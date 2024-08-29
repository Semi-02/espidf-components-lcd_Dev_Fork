export class GFXglyph {
    constructor(
        public bitmapOffset: number, ///u16< Pointer into GFXfont->bitmap
        public width: number,         ///u8< Bitmap dimensions in pixels
        public height: number,        ///u8< Bitmap dimensions in pixels
        public xAdvance: number,      ///u8< Distance to advance cursor (x axis)
        public xOffset: number,        ///i8< X dist from cursor pos to UL corner
        public yOffset: number) { }        ///i8< Y dist from cursor pos to UL corner
}

export class GFXfont {
    constructor(public bitmap: number[], public glyphs: GFXglyph[], public firstCodepoint: number, public lastCodepoint: number, public newlineDistance: number) { }
}