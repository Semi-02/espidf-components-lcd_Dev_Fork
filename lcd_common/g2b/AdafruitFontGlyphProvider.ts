import { GlyphProviderResult, IGlyphProvider, BitmapFormat, ToUint8Array } from './utils';
import { GlyphDesc } from './utils';
import { GFXfont } from "./adafruit_fonts/GfXfont"



export class AdafruitFontGlyphProvider extends GlyphProviderResult implements IGlyphProvider {
	public glyphsDesc: Array<GlyphDesc> = [];
	constructor(private fileRelativeToThisSourceFile: string, private unitsPerPixel:number) { super(); }

	async Provide(): Promise<GlyphProviderResult> {
		const fontModule = await import(this.fileRelativeToThisSourceFile);
		var gfxFont = <GFXfont>fontModule.default;
		for (var codepoint = gfxFont.firstCodepoint; codepoint <= gfxFont.lastCodepoint; codepoint++) {
			var glyphDescSrc = gfxFont.glyphs[codepoint-gfxFont.firstCodepoint];
			var bitmapSize = Math.ceil((glyphDescSrc.width*glyphDescSrc.height)/8);
			var bitmap=gfxFont.bitmap.slice(glyphDescSrc.bitmapOffset,glyphDescSrc.bitmapOffset+bitmapSize);
			var glyphDescDest = new GlyphDesc(
				codepoint, 
				String.fromCodePoint(codepoint), 
				glyphDescSrc.xAdvance*this.unitsPerPixel, 
				glyphDescSrc.width, 
				glyphDescSrc.height,
				glyphDescSrc.xOffset,
				glyphDescSrc.yOffset,
				0, 0, BitmapFormat.ONE_BPP_ROW_BY_ROW, ToUint8Array(bitmap));
			this.glyphsDesc.push(glyphDescDest);
		}
		this.lineHeight=gfxFont.newlineDistance;
		return this;
	}
}
