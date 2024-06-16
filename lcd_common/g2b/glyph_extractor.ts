
import { IGlyphProvider, IGlyphProviderWithKerning, BitmapFormat, formatedTimestamp } from './utils';
import { CharacterMap0Tiny } from './utils';
import { GlyphDesc } from './utils';



export class FontCC{

	public glyphs:Array<GlyphDesc>=[];
	public characterMaps:Array<CharacterMap0Tiny>=[];
	public fontUnitsPerPixel:number=2048;
	public leftrightKerningClass2kerningValue:Array<number>=[];
	public leftKerningClassCnt:number=0;
	public rightKerningClassCnt:number=0;
	public lineHeight:number=0;

	private constructor(){}


	private buildAndAddCmaps(glyphsDesc:Array<GlyphDesc>, targetGlyphIndex:number){
		//Finde nun zusammenhängende codepoint-Bereiche und erstelle für jeden zusammenhängenden BEreich eine cmap
		var i=0;
		
		var len=0;
		var cmap = new CharacterMap0Tiny(glyphsDesc[i].codepointDest, targetGlyphIndex);
		i++;
		targetGlyphIndex++;
		len++;
		while(i<glyphsDesc.length){
			if(glyphsDesc[i].codepointDest==glyphsDesc[i-1].codepointDest+1){ //wenn der nächste codepoint gleich dem vorherigen+1 ist
				len++;
			}else{
				cmap.len=len;
				this.characterMaps.push(cmap);
				cmap=new CharacterMap0Tiny(glyphsDesc[i].codepointDest, targetGlyphIndex);
				len=1;
			}
			i++;
			targetGlyphIndex++;
		}
		cmap.len=len;
		this.characterMaps.push(cmap);
	}

	private async build(mainProvider:IGlyphProviderWithKerning, otherProviders:Array<IGlyphProvider>){
		this.glyphs.push(new GlyphDesc(0,"DummyGlyph", 0,0,0,0,0, 0,0,BitmapFormat.UNDEFINED, new Uint8Array()));
		if(mainProvider){
			var res = await mainProvider.Provide();
			this.buildAndAddCmaps(res.glyphsDesc, this.glyphs.length);
			this.glyphs.push(...res.glyphsDesc)
			this.leftrightKerningClass2kerningValue=res.leftrightKerningClass2kerningValue;
			this.leftKerningClassCnt=res.leftKerningClassCnt;
			this.rightKerningClassCnt=res.rightKerningClassCnt;
			this.lineHeight=resx.lineHeight;
			for(var pIndex=0; pIndex<otherProviders.length;pIndex++){//start at 0!!!
				var resx = await otherProviders[pIndex].Provide();
				this.buildAndAddCmaps(resx.glyphsDesc, this.glyphs.length);
				this.glyphs.push(...resx.glyphsDesc)
			}
		}else{
			var resx = await otherProviders[0].Provide();
			this.buildAndAddCmaps(resx.glyphsDesc, this.glyphs.length);
			this.glyphs.push(...resx.glyphsDesc)
			this.lineHeight=resx.lineHeight;
			for(var pIndex=1; pIndex<otherProviders.length;pIndex++){//start at 1!!!
				var resx = await otherProviders[pIndex].Provide();
				this.buildAndAddCmaps(resx.glyphsDesc, this.glyphs.length);
				this.glyphs.push(...resx.glyphsDesc)
			}
		}
		return this;
	}

	




	public toFontCCFile(namespace:string):string{
		var ret=`//created with glyph_extractor.ts ${formatedTimestamp()}\n#include <cstdint>\n#include <initializer_list>\n#include \"lcd_font.hh\"\nusing namespace lcd_common;\nnamespace ${namespace}{\n`;
		var bitmap="";
		var glyphDescStr="";
		var bitmapIndex=0;
		for(var gi=0;gi<this.glyphs.length;gi++){
			var g = this.glyphs[gi];
			bitmap += `/* ${g.name} codepoint=${g.codepointDest},  glyphindex=${gi}, width=${g.box_w}*/ ${g.box_w>0?toHexArray(g.bitmap)+",":""}\n`;
			glyphDescStr+=g.toCppConstructorString(bitmapIndex, gi);
			bitmapIndex+=g.bitmap.byteLength;
		}

		var cmaps="";
		this.characterMaps.forEach(v=>{
			cmaps+=`\t${v.toCppConstructorString()},\n`
		});
	
		//console.log(`offsetX=${offsetX}, w=${w}, top8vec=${toHexArray(top8vec)}, bot8vec=${toHexArray(bot8vec)}`)
		
		ret+=`constexpr std::initializer_list<uint8_t> glyph_bitmap={\n${bitmap}\n};\n\n`
		ret+=`constexpr std::initializer_list<GlyphDesc> glyph_desc={\n${glyphDescStr}\n};\n\n`
		ret+=`constexpr std::initializer_list<CharacterMap0Tiny> cmaps={\n${cmaps}\n};\n\n`
		ret+=`constexpr std::initializer_list<int16_t> kern_class_values = {${this.leftrightKerningClass2kerningValue}};\n\n`
		ret+=`constexpr const FontDesc font = FontDesc(\n\t${this.leftKerningClassCnt}, \n\t${this.rightKerningClassCnt},\n\t&kern_class_values,\n\t${this.characterMaps.length},\n\t&cmaps,\n\t&glyph_desc,\n\t&glyph_bitmap,\n\t${this.lineHeight},\n\t0);\n`
		ret+="}"
		return ret;
	}

	public toSymbolDefHeader():string{
		
		var header=`//created with glyph_extractor.ts ${formatedTimestamp()}\n#pragma once\n`;
		
		this.glyphs.filter(v=>v.codepointDest>255).forEach((gl_in, index) => {
			//header+=`   constexpr const char* G_${e.name.replaceAll("-", "_").toLocaleUpperCase()} = "${encodeCodePoint(e.unicode[0])}"; // ${e.unicode[0]}\n`;
			header+=`   #define G_${gl_in.name.replaceAll("-", "_").toLocaleUpperCase()} "${encodeCodePoint(gl_in.codepointDest)}" //codepoint ${gl_in.codepointDest} glyphindex ${index}\n`;
		});
		return header;
	}

	public static async Build(mainProvider:IGlyphProviderWithKerning, ...otherProviders:Array<IGlyphProvider>):Promise<FontCC>{
		var res = new FontCC();
		return await res.build(mainProvider, otherProviders);

	}
}

var stringFromCharCode = (charcode: number) => {
	return "\\x" + charcode.toString(16);
}

function checkScalarValue(codePoint: number) {
	if (codePoint >= 0xD800 && codePoint <= 0xDFFF) {
		throw Error(
			'Lone surrogate U+' + codePoint.toString(16).toUpperCase() +
			' is not a scalar value'
		);
	}
}

export function imageData2bitmap(image:ImageData, step:number=1){
	var arr=image.data;
	var val=0;
	for(let i=(8*step)-1;i>=0;i-=step){
		val=val<<1;
		var r=arr[4*i+0];
		var g=arr[4*i+1];
		var b=arr[4*i+2];
		var a=arr[4*i+3];
		var lum = 0.299*(r) + 0.587*(g) + 0.114*(b);
		if(a>64){
			val |=1;
		}
		
	}
	return val;
}


export function toHexArray(byteArray:Iterable<number>, shift=0):string {
	return Array.from(byteArray, (byte)=> {
		byte=byte>>shift
		if(byte>=16) return ('0x' + (byte & 0xFF).toString(16));
	  	else return '0x0'+((byte & 0xFF).toString(16));
	}).join(",")
}

function createByte(codePoint: number, shift: number) {
	return stringFromCharCode(((codePoint >> shift) & 0x3F) | 0x80);
}

function encodeCodePoint(codePoint: number): string {
	if ((codePoint & 0xFFFFFF80) == 0) { // 1-byte sequence
		return stringFromCharCode(codePoint);
	}
	var symbol = '';
	if ((codePoint & 0xFFFFF800) == 0) { // 2-byte sequence
		symbol = stringFromCharCode(((codePoint >> 6) & 0x1F) | 0xC0);
	}
	else if ((codePoint & 0xFFFF0000) == 0) { // 3-byte sequence
		checkScalarValue(codePoint);
		symbol = stringFromCharCode(((codePoint >> 12) & 0x0F) | 0xE0);
		symbol += createByte(codePoint, 6);
	}
	else if ((codePoint & 0xFFE00000) == 0) { // 4-byte sequence
		symbol = stringFromCharCode(((codePoint >> 18) & 0x07) | 0xF0);
		symbol += createByte(codePoint, 12);
		symbol += createByte(codePoint, 6);
	}
	symbol += stringFromCharCode((codePoint & 0x3F) | 0x80);
	return symbol;
}



