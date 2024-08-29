/*
var buffer = fs.readFileSync('Roboto-Regular.ttf').buffer;
const main_font= opentype.parse(buffer);
buffer = fs.readFileSync('fa-solid-900.ttf').buffer;
const symbol_font= opentype.parse(buffer);
var fontCc= FontCC.Build(main_font, [new Range(32,256)], symbol_font, [new Range(0xe005, 0xE059)]);
var target="roboto_fontawesome_16px1bpp"
*/

import opentype from "opentype.js";
import { FontCC, } from "./glyph_extractor";
import { SvgDirectoryGlyphProvider } from "./SvgDirectoryGlyphProvider";
import { UNICODE_PRIVATE_USE_AREA, Range } from "./utils";
import fs from "node:fs"
import { TtfGlyphProvider } from "./TtfGlyphProvider";
import { AdafruitFontGlyphProvider } from "./AdafruitFontGlyphProvider";

/*
var arial = new TtfGlyphProvider(opentype.parse(fs.readFileSync("./g2b/ttf_fonts/Arial.ttf").buffer), [new Range(32,256)], 32, 24, 10, false)
//var glcd = new GlcdFontProvider("./glcd_fonts/font_30_glcd.ts");
var svg = new SvgDirectoryGlyphProvider("./node_modules/pixelarticons/svg", UNICODE_PRIVATE_USE_AREA, 32, 32, false);
FontCC.Build(null, arial, svg ).then(fontCc=>{
	var target="arial_and_symbols_24px1bpp"
	fs.writeFileSync(target+".cc", fontCc.toFontCCFile(target));
	fs.writeFileSync("symbols.hh", fontCc.toSymbolDefHeader());
})
*/
const UNITS_PER_PIXEL=128 //keep in sync with lcd_font.hh
var sans12 = new AdafruitFontGlyphProvider("./adafruit_fonts/FreeSans12pt7b.ts", UNITS_PER_PIXEL);
FontCC.Build(null, sans12).then(fontCc=>{
	var target="sans12pt1bpp"
	fs.writeFileSync("./include/fonts/"+target+".hh", fontCc.toFontCCFile(target));
	fs.writeFileSync("symbols.hh", fontCc.toSymbolDefHeader());
});