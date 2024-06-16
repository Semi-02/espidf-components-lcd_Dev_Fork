import { GlyphProviderResult, IGlyphProvider, BitmapFormat, ToUint8Array } from './utils';
import { GlyphDesc } from './utils';




export class GlcdFontProvider extends GlyphProviderResult implements IGlyphProvider {
	public glyphsDesc: Array<GlyphDesc> = [];
	constructor(private fileRelativeToThisSourceFile: string) { super(); }

	async Provide(): Promise<GlyphProviderResult> {
		const fontModule = await import(this.fileRelativeToThisSourceFile);
		var data = <number[]>fontModule.default;
		var sizeInBytes = data[1] << 8 + data[0];
		var glyphWidth = data[2];
		var glyphHeight = data[3];
		var codePointFirstGlyph = data[4];
		var codepointsCnt = data[5];
		var bitmapIndex = 6 + codepointsCnt;;
		for (var i = 0; i < codepointsCnt; i++) {
			var width = data[6 + i];
			var top8vec = data.slice(bitmapIndex, bitmapIndex + width);
			var bot8vec = data.slice(bitmapIndex + width, bitmapIndex + 2 * width);
			bot8vec.forEach((v, i, a) => { a[i] >>= 2; });

			var glyphDesc = new GlyphDesc(codePointFirstGlyph + i, String.fromCodePoint(codePointFirstGlyph + i), width + 2, width, 16, 0, 0, 0, 0, BitmapFormat.ONE_BPP_EIGHT_IN_A_COLUMN, ToUint8Array(top8vec, bot8vec));
			this.glyphsDesc.push(glyphDesc);
			bitmapIndex += (2 * width);
		}
		return this;
	}
}
