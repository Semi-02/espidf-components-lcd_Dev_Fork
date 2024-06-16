import fs from "node:fs";
import * as Canvas from "canvas";
import {Range} from "./utils"
import { Font, Glyph } from "opentype.js";
import { imageData2bitmap } from "./glyph_extractor";
import { codepoint2glyphindex } from "./opentype_extensions";
import { GlyphProviderWithKerningResult, IGlyphProviderWithKerning, GlyphDesc, GlyphProcessingInfo, UNICODE_PRIVATE_USE_AREA, BitmapFormat, concat } from "./utils";

export class TtfGlyphProviderWithKerning extends GlyphProviderWithKerningResult implements IGlyphProviderWithKerning {
	
	public glyphsDesc: Array<GlyphDesc> = [];

	public fontUnitsPerPixel: number = 0;
	public leftKerningClassCnt: number = 0;
	public rightKerningClassCnt: number = 0;
	public leftrightKerningClass2kerningValue: Array<number> = [];

	private buildClassBasedKernings(font: Font, glyphProcessingInfo: Array<GlyphProcessingInfo>) {

		const gposKerning = (<any>font).position.defaultKerningTables;
		const subtable = gposKerning[0].subtables[1];
		var classes2kerning: Array<number> = [];
		for (let leftClass = 0; leftClass < subtable.class1Count; leftClass++) {
			for (let rightClass = 0; rightClass < subtable.class2Count; rightClass++) {
				const pair = subtable.classRecords[leftClass][rightClass];
				classes2kerning.push(pair.value1 && pair.value1.xAdvance || 0);
			}
		}

		//subtable.classRecords.forEach((i)=>{classes2kerning.push(i.value1 && i.value1.xAdvance || 0)})
		this.leftrightKerningClass2kerningValue = classes2kerning;
		this.leftKerningClassCnt = subtable.class1Count;
		this.rightKerningClassCnt = subtable.class2Count;
	}
	//@Obsolete
	private buildGlyphDescriptionAndAddToBitmap(info: GlyphProcessingInfo): GlyphDesc|null {
		var debug = false;
		if (info.codepointSource == 72) {
			debug = true;
		}
		var g = info.font.glyphs.get(info.glyphIndexSource);
		var canvas = Canvas.createCanvas(16, 16);
		var ctx: any = canvas.getContext("2d");
		g.draw(ctx, 0, 16, 16, <any>{ hinting: true });

		var offsetX = 0;
		var top8vec: Uint8Array = new Uint8Array(16);
		var bot8vec: Uint8Array = new Uint8Array(16);
		if (debug) {
			fs.writeFileSync("./glyph" + info.codepointSource + ".png", canvas.toBuffer());
		}
		for (let x = 0; x < 16; x++) {
			var top8 = ctx.getImageData(x, 0, 1, 8);
			top8vec[x] = (imageData2bitmap(top8));
			var bottom8 = ctx.getImageData(x, 8, 1, 8);
			bot8vec[x] = (imageData2bitmap(bottom8));
		}
		var offsetX = 0;
		while (top8vec[offsetX] == 0 && bot8vec[offsetX] == 0) {
			offsetX++;
		}
		var w = 16 - offsetX;
		while (w > 0 && top8vec[offsetX + w] == 0 && bot8vec[offsetX + w] == 0) {
			w--;
		}
		top8vec = top8vec.slice(offsetX, offsetX + w);
		bot8vec = bot8vec.slice(offsetX, offsetX + w);

		return null;
	}

	Provide(): Promise<GlyphProviderWithKerningResult> {
		var glyphIndexes: Array<GlyphProcessingInfo> = [];
		const gposKerning = (<any>this.font).position.defaultKerningTables;
		const subtable = gposKerning[0].subtables[1];

		var relocatedCodepoint = UNICODE_PRIVATE_USE_AREA;
		this.codepointRanges.forEach(r => {
			for (let codePoint = r.startIncl; codePoint < r.endExcl; codePoint++) {
				var glyphIndexTtf = codepoint2glyphindex(this.font, codePoint);
				if (!glyphIndexTtf) continue;
				var g: Glyph = this.font.glyphs.get(glyphIndexTtf);
				var leftClass=(<any>this.font).position.getGlyphClass(subtable.classDef1, glyphIndexTtf)
				var rightClass=((<any>this.font).position.getGlyphClass(subtable.classDef2, glyphIndexTtf));
				var canvas = Canvas.createCanvas(16, 16);
				var ctx: any = canvas.getContext("2d");
				g.draw(ctx, 0, 16, 16, <any>{ hinting: true });

				var offsetX = 0;
				var top8vec: Uint8Array = new Uint8Array(16);
				var bot8vec: Uint8Array = new Uint8Array(16);

				for (let x = 0; x < 16; x++) {
					var top8 = ctx.getImageData(x, 0, 1, 8);
					top8vec[x] = (imageData2bitmap(top8));
					var bottom8 = ctx.getImageData(x, 8, 1, 8);
					bot8vec[x] = (imageData2bitmap(bottom8));
				}
				var offsetX = 0;
				while (top8vec[offsetX] == 0 && bot8vec[offsetX] == 0) {
					offsetX++;
				}
				var w = 16 - offsetX;
				while (w > 0 && top8vec[offsetX + w] == 0 && bot8vec[offsetX + w] == 0) {
					w--;
				}
				top8vec = top8vec.slice(offsetX, offsetX + w);
				bot8vec = bot8vec.slice(offsetX, offsetX + w);
				if (this.relocateToUnicodePrivateUseArea) {
					this.glyphsDesc.push(new GlyphDesc(relocatedCodepoint, g.name??"Glyph_"+relocatedCodepoint, g.advanceWidth, w, 16, offsetX, 0, leftClass, rightClass, BitmapFormat.ONE_BPP_EIGHT_IN_A_COLUMN, concat(top8vec, bot8vec)));
					relocatedCodepoint++;
				} else {
					this.glyphsDesc.push(new GlyphDesc(codePoint, g.name??"Glyph_"+relocatedCodepoint, g.advanceWidth, w, 16, offsetX, 0, leftClass, rightClass, BitmapFormat.ONE_BPP_EIGHT_IN_A_COLUMN, concat(top8vec, bot8vec)));
				}

			}
		});
		return new Promise((resolve, reject)=>{resolve(this);});
	}

	constructor(private font: opentype.Font, private codepointRanges: Range[], private relocateToUnicodePrivateUseArea: boolean) {super() }

}