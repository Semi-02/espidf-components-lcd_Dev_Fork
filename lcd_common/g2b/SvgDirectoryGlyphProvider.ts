import fs from "node:fs";
import path from "node:path";
import { GlyphProviderResult, IGlyphProvider, BitmapFormat, concat, FONT_UNITS_PER_PIXEL } from './utils';
import { GlyphDesc } from './utils';
import * as Canvas from "canvas";
import { imageData2bitmap, toHexArray } from "./glyph_extractor";


export class SvgDirectoryGlyphProvider extends GlyphProviderResult implements IGlyphProvider {
	constructor(private directory: string, private beginCodepoint: number, public lineHeight = 32, private canvasWidth = 32, private scaleToFit = false) { super(); }
	public glyphsDesc: Array<GlyphDesc> = [];
	async Provide(): Promise<GlyphProviderResult> {
		var codePoint = this.beginCodepoint;
		var files = fs.readdirSync(this.directory);
		for (var index = 0; index < files.length; index++) {
			var file = files[index];
			var debug = index == 1;
			var fileWithoutExt = path.parse(file).name;
			var canvas = Canvas.createCanvas(this.canvasWidth, this.lineHeight);
			var ctx: any = canvas.getContext("2d");
			var image = await Canvas.loadImage(path.join(this.directory, file));
			if (this.scaleToFit) {
				ctx.drawImage(image, 0, 0, this.canvasWidth, this.lineHeight);
			} else {
				ctx.drawImage(image, (this.canvasWidth - image.naturalWidth) / 2, (this.lineHeight - image.height) / 2);
			}
			if (debug) {
				fs.writeFileSync(fileWithoutExt + ".png", canvas.toBuffer());
			}

			var linesOfEightPixels = Math.ceil(this.lineHeight / 8);
			var pixelVects = new Array<Uint8Array>(linesOfEightPixels);

			for (var line = 0; line < linesOfEightPixels; line++) {
				var pixelVect: Uint8Array = new Uint8Array(this.canvasWidth);
				pixelVects[line] = pixelVect;
				for (let x = 0; x < this.canvasWidth; x++) {
					var pixels = ctx.getImageData(x, line * 8, 1, (line + 1) * 8);
					pixelVect[x] = (imageData2bitmap(pixels));
				}
			}


			var offsetX = 0;
			while (offsetX < this.canvasWidth && 0 == pixelVects.reduce<number>((sum, pv) => sum + pv[offsetX], 0)) { //So lange kein einziger !0 ist, also alle gleich null sind, erhöhe offset
				offsetX++;
			}
			var w = 0;
			if (offsetX == this.canvasWidth) {
				//we discovered a SPACE character without any visible elementt
				offsetX = 0;
			} else {
				while (0 < pixelVects.reduce<number>((sum, pv) => sum + pv[offsetX + w], 0)) { //So lange mindestens einer !0 ist, erhöhe die Breite
					w++;
				}
			}

			var pixelVectsSliced: Array<Uint8Array> = [];
			pixelVects.forEach((v) => {
				pixelVectsSliced.push(v.slice(offsetX, offsetX + w));
			});

			if (debug) {
				console.log(``);
				console.log(`file=${file} nat_width:${image.naturalWidth} net_height=${image.naturalHeight} offsetX=${offsetX}, w=${w}, first=${toHexArray(pixelVectsSliced[0])}, second=${pixelVectsSliced[1]}`);
			}
			this.glyphsDesc.push(new GlyphDesc(codePoint, fileWithoutExt, this.canvasWidth*FONT_UNITS_PER_PIXEL, w, linesOfEightPixels * 8, offsetX, 0, 0, 0, BitmapFormat.ONE_BPP_EIGHT_IN_A_COLUMN, concat(pixelVectsSliced)));

			codePoint++;

		}
		return this;
	}
}
