import * as Canvas from 'canvas';
import opentype, { Glyph } from 'opentype.js';
import { BitmapFormat, Range, concat, GlyphProviderResult, IGlyphProvider, FONT_UNITS_PER_PIXEL } from './utils';
import { GlyphProcessingInfo } from './utils';
import { UNICODE_PRIVATE_USE_AREA } from './utils';
import { GlyphDesc } from './utils';
import { codepoint2glyphindex } from './opentype_extensions';
import { imageData2bitmap } from './glyph_extractor';
import fs from "node:fs"

export class TtfGlyphProvider extends GlyphProviderResult implements IGlyphProvider {
	public glyphsDesc: Array<GlyphDesc> = [];

	Provide(): Promise<GlyphProviderResult> {
		var glyphIndexes: Array<GlyphProcessingInfo> = [];
		var emMultiplicator= this.fontSize*FONT_UNITS_PER_PIXEL/this.font.unitsPerEm;
		var relocatedCodepoint = UNICODE_PRIVATE_USE_AREA;
		this.codepointRanges.forEach(r => {
			for (let codePoint = r.startIncl; codePoint < r.endExcl; codePoint++) {
				var debug=false;
				if(codePoint==88){
					debug=true;
				}
				var glyphIndexTtf = codepoint2glyphindex(this.font, codePoint);
				if (!glyphIndexTtf) continue;
				var g: Glyph = this.font.glyphs.get(glyphIndexTtf);
				var canvas = Canvas.createCanvas(this.lineHeight*2, this.lineHeight);
				var ctx: any = canvas.getContext("2d");
				g.draw(ctx, 0, this.lineHeight-this.baselineFromBottom, this.fontSize, <any>{ hinting: true });
				if (debug) {
					fs.writeFileSync("./glyph" + codePoint + ".png", canvas.toBuffer());
				}
				var linesOfEightPixels=Math.ceil(this.lineHeight/8)
				var pixelVects:Array<Uint8Array>=[];
				
				for(var line=0;line<linesOfEightPixels;line++){
					var pixelVect: Uint8Array = new Uint8Array(this.lineHeight*2);
					pixelVects.push(pixelVect);
					for (let x = 0; x < this.lineHeight*2; x++) {
						var pixels = ctx.getImageData(x, line*8, 1, (line+1)*8);
						pixelVect[x] = (imageData2bitmap(pixels));
					}
				}
				var offsetX = 0;
				while (offsetX<this.lineHeight*2 && 0==pixelVects.reduce<number>((sum,pv)=>sum+pv[offsetX],0)) {//So lange kein einziger !0 ist, also alle gleich null sind, erhöhe offset
					offsetX++;
				}
				var w = 0
				if(offsetX==this.lineHeight*2){
					//we discovered a SPACE character without any visible elementt
					offsetX=0;
				}else{
					while (0<pixelVects.reduce<number>((sum,pv)=>sum+pv[offsetX+w],0)) {//So lange mindestens einer !0 ist, erhöhe die Breite
						w++;
					}
				}
				
				var pixelVectsSliced:Array<Uint8Array>=[];
				pixelVects.forEach((v)=>{
					pixelVectsSliced.push(v.slice(offsetX, offsetX + w))
				});
				if (this.relocateToUnicodePrivateUseArea) {
					//constructor(public readonly codepointDest:number, public readonly name:string, public adv_w = 0, public box_w = 0, public box_h = 16, public ofs_x = 0, public ofs_y = 0, public kerningClassLeft=0, public kerningClassRight=0, public readonly bitmapFormat:BitmapFormat, public readonly bitmap:Uint8Array) { }
					this.glyphsDesc.push(new GlyphDesc(relocatedCodepoint, g.name??"Glyph_"+relocatedCodepoint, Math.floor(g.advanceWidth*emMultiplicator), w, this.lineHeight, offsetX, 0, 0, 0, BitmapFormat.ONE_BPP_EIGHT_IN_A_COLUMN, concat(pixelVectsSliced)));
					relocatedCodepoint++;
				} else {
					this.glyphsDesc.push(new GlyphDesc(codePoint, g.name??"Glyph_"+codePoint, Math.floor(g.advanceWidth*emMultiplicator), w, this.lineHeight, offsetX, 0, 0, 0, BitmapFormat.ONE_BPP_EIGHT_IN_A_COLUMN, concat(pixelVectsSliced)));
				}

			}
		});
		return new Promise((resolve, reject) => { resolve(this); });
	}

	constructor(private font: opentype.Font, private codepointRanges: Range[], public lineHeight=24, private fontSize=16, private baselineFromBottom=0, private relocateToUnicodePrivateUseArea=false) { super() }

}
