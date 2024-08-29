//created with glyph_extractor.ts 2024-08-24 14:33:28
#include <cstdint>
#include <initializer_list>
#include "lcd_font.hh"
using namespace lcd_common;
namespace sans12pt1bpp{
constexpr std::initializer_list<uint8_t> glyph_bitmap={
/* DummyGlyph codepoint=0,  glyphindex=0, width=0*/ 
/*   codepoint=32,  glyphindex=1, width=0*/ 
/* ! codepoint=33,  glyphindex=2, width=2*/ 0xff,0xff,0xff,0xf0,0xf0,
/* " codepoint=34,  glyphindex=3, width=6*/ 0xcf,0x3c,0xf3,0x8a,0x20,
/* # codepoint=35,  glyphindex=4, width=13*/ 0x06,0x30,0x31,0x03,0x18,0x18,0xc7,0xff,0xbf,0xfc,0x31,0x03,0x18,0x18,0xc7,0xff,0xbf,0xfc,0x31,0x01,0x18,0x18,0xc0,0xc6,0x06,0x30,
/* $ codepoint=36,  glyphindex=5, width=11*/ 0x04,0x03,0xe1,0xff,0x72,0x6c,0x47,0x88,0xf1,0x07,0x20,0x7e,0x03,0xf0,0x17,0x02,0x3c,0x47,0x88,0xf1,0x1b,0x26,0x7f,0xc3,0xe0,0x10,0x02,0x00,
/* % codepoint=37,  glyphindex=6, width=20*/ 0x00,0x06,0x03,0xc0,0x40,0x7e,0x0c,0x0e,0x70,0x80,0xc3,0x18,0x0c,0x31,0x00,0xe7,0x30,0x07,0xe6,0x00,0x3c,0x40,0x00,0x0c,0x7c,0x00,0x8f,0xe0,0x19,0xc7,0x01,0x18,0x30,0x31,0x83,0x02,0x1c,0x70,0x40,0xfe,0x04,0x07,0xc0,
/* & codepoint=38,  glyphindex=7, width=14*/ 0x0f,0x00,0x7e,0x03,0x9c,0x0c,0x30,0x30,0xc0,0xe7,0x01,0xf8,0x03,0x80,0x3e,0x01,0xcc,0x6e,0x19,0xb0,0x7c,0xc0,0xf3,0x03,0xce,0x1f,0x9f,0xe6,0x1e,0x1c,
/* ' codepoint=39,  glyphindex=8, width=2*/ 0xff,0xa0,
/* ( codepoint=40,  glyphindex=9, width=5*/ 0x08,0x8c,0x66,0x31,0x98,0xc6,0x31,0x8c,0x63,0x08,0x63,0x08,0x61,0x0c,0x20,
/* ) codepoint=41,  glyphindex=10, width=5*/ 0x82,0x18,0xc3,0x18,0xc3,0x18,0xc6,0x31,0x8c,0x62,0x31,0x88,0xc4,0x62,0x00,
/* * codepoint=42,  glyphindex=11, width=7*/ 0x10,0x23,0x5b,0xe3,0x8d,0x91,0x00,
/* + codepoint=43,  glyphindex=12, width=10*/ 0x0c,0x03,0x00,0xc0,0x30,0xff,0xff,0xf0,0xc0,0x30,0x0c,0x03,0x00,0xc0,
/* , codepoint=44,  glyphindex=13, width=2*/ 0xf5,0x60,
/* - codepoint=45,  glyphindex=14, width=6*/ 0xff,0xf0,
/* . codepoint=46,  glyphindex=15, width=2*/ 0xf0,
/* / codepoint=47,  glyphindex=16, width=7*/ 0x02,0x0c,0x10,0x20,0xc1,0x02,0x0c,0x10,0x20,0xc1,0x02,0x0c,0x10,0x20,0xc1,0x00,
/* 0 codepoint=48,  glyphindex=17, width=11*/ 0x1f,0x07,0xf1,0xc7,0x30,0x6e,0x0f,0x80,0xf0,0x1e,0x03,0xc0,0x78,0x0f,0x01,0xe0,0x3c,0x0e,0xc1,0x9c,0x71,0xfc,0x1f,0x00,
/* 1 codepoint=49,  glyphindex=18, width=5*/ 0x08,0xcf,0xff,0x8c,0x63,0x18,0xc6,0x31,0x8c,0x63,0x18,
/* 2 codepoint=50,  glyphindex=19, width=11*/ 0x1f,0x0f,0xf9,0x87,0x60,0x7c,0x06,0x00,0xc0,0x18,0x07,0x01,0xc0,0xf0,0x78,0x1c,0x06,0x00,0x80,0x30,0x07,0xff,0xff,0xe0,
/* 3 codepoint=51,  glyphindex=20, width=11*/ 0x3f,0x0f,0xf3,0x87,0x60,0x6c,0x0c,0x01,0x80,0x70,0x7c,0x0f,0x80,0x18,0x01,0x80,0x3c,0x07,0x80,0xd8,0x73,0xfc,0x1f,0x00,
/* 4 codepoint=52,  glyphindex=21, width=11*/ 0x01,0x80,0x70,0x0e,0x03,0xc0,0xd8,0x1b,0x06,0x61,0x8c,0x21,0x8c,0x33,0x06,0x7f,0xff,0xfe,0x03,0x00,0x60,0x0c,0x01,0x80,
/* 5 codepoint=53,  glyphindex=22, width=11*/ 0x3f,0xcf,0xf9,0x80,0x30,0x06,0x00,0xde,0x1f,0xe7,0x0e,0x00,0xe0,0x0c,0x01,0x80,0x30,0x07,0x81,0xf8,0x73,0xfc,0x1f,0x00,
/* 6 codepoint=54,  glyphindex=23, width=11*/ 0x0f,0x07,0xf9,0xc3,0x30,0x74,0x01,0x80,0x33,0xc7,0xfe,0xf0,0xdc,0x1f,0x01,0xe0,0x3c,0x06,0xc1,0xdc,0x71,0xfc,0x1f,0x00,
/* 7 codepoint=55,  glyphindex=24, width=11*/ 0xff,0xff,0xfc,0x01,0x00,0x60,0x18,0x02,0x00,0xc0,0x30,0x06,0x01,0x80,0x30,0x04,0x01,0x80,0x30,0x06,0x01,0x80,0x30,0x00,
/* 8 codepoint=56,  glyphindex=25, width=11*/ 0x1f,0x07,0xf1,0xc7,0x30,0x66,0x0c,0xc1,0x8c,0x61,0xfc,0x3f,0x8e,0x3b,0x01,0xe0,0x3c,0x07,0x80,0xd8,0x31,0xfc,0x1f,0x00,
/* 9 codepoint=57,  glyphindex=26, width=11*/ 0x1f,0x07,0xf1,0xc7,0x70,0x6c,0x07,0x80,0xf0,0x1e,0x07,0x61,0xef,0xfc,0x79,0x80,0x30,0x05,0x81,0x98,0x73,0xfc,0x1e,0x00,
/* : codepoint=58,  glyphindex=27, width=2*/ 0xf0,0x00,0x03,0xc0,
/* ; codepoint=59,  glyphindex=28, width=2*/ 0xf0,0x00,0x0f,0x56,
/* < codepoint=60,  glyphindex=29, width=12*/ 0x00,0x00,0x07,0x01,0xe0,0xf8,0x3c,0x0f,0x00,0xe0,0x07,0xc0,0x0f,0x00,0x3c,0x00,0xf0,0x01,
/* = codepoint=61,  glyphindex=30, width=12*/ 0xff,0xff,0xff,0x00,0x00,0x00,0xff,0xff,0xff,
/* > codepoint=62,  glyphindex=31, width=12*/ 0x00,0x0e,0x00,0x78,0x01,0xf0,0x07,0xc0,0x0f,0x00,0x70,0x1e,0x0f,0x03,0xc0,0xf0,0x08,0x00,
/* ? codepoint=63,  glyphindex=32, width=10*/ 0x1f,0x1f,0xee,0x1b,0x03,0xc0,0xc0,0x30,0x0c,0x06,0x03,0x81,0xc0,0xe0,0x30,0x0c,0x03,0x00,0x00,0x00,0x0c,0x03,0x00,
/* @ codepoint=64,  glyphindex=33, width=22*/ 0x00,0xfe,0x00,0x0f,0xfe,0x00,0xf0,0x3e,0x07,0x00,0x3c,0x38,0x00,0x30,0xc1,0xe0,0x66,0x0f,0xd9,0xd8,0x61,0xc3,0xc3,0x07,0x0f,0x1c,0x1c,0x3c,0x60,0x60,0xf1,0x81,0x83,0xc6,0x06,0x1b,0x18,0x38,0xee,0x71,0xe7,0x18,0xfd,0xf8,0x71,0xe7,0xc0,0xe0,0x00,0x01,0xe0,0x00,0x01,0xff,0xc0,0x01,0xfc,0x00,
/* A codepoint=65,  glyphindex=34, width=16*/ 0x03,0xc0,0x03,0xc0,0x03,0xc0,0x07,0xe0,0x06,0x60,0x06,0x60,0x0e,0x70,0x0c,0x30,0x0c,0x30,0x1c,0x38,0x18,0x18,0x1f,0xf8,0x3f,0xfc,0x30,0x1c,0x30,0x0c,0x70,0x0e,0x60,0x06,0x60,0x06,
/* B codepoint=66,  glyphindex=35, width=13*/ 0xff,0xc7,0xff,0x30,0x19,0x80,0x6c,0x03,0x60,0x1b,0x00,0xd8,0x0c,0xff,0xc7,0xff,0x30,0x0d,0x80,0x3c,0x01,0xe0,0x0f,0x00,0x78,0x06,0xff,0xf7,0xfe,0x00,
/* C codepoint=67,  glyphindex=36, width=15*/ 0x07,0xe0,0x3f,0xf0,0xe0,0x73,0x80,0x66,0x00,0x6c,0x00,0x30,0x00,0x60,0x00,0xc0,0x01,0x80,0x03,0x00,0x06,0x00,0x06,0x00,0x6c,0x00,0xdc,0x03,0x1e,0x0e,0x1f,0xf8,0x0f,0xc0,
/* D codepoint=68,  glyphindex=37, width=14*/ 0xff,0x83,0xff,0x8c,0x07,0x30,0x0e,0xc0,0x1b,0x00,0x7c,0x00,0xf0,0x03,0xc0,0x0f,0x00,0x3c,0x00,0xf0,0x03,0xc0,0x1f,0x00,0x6c,0x03,0xb0,0x1c,0xff,0xe3,0xff,0x00,
/* E codepoint=69,  glyphindex=38, width=12*/ 0xff,0xff,0xff,0xc0,0x0c,0x00,0xc0,0x0c,0x00,0xc0,0x0c,0x00,0xff,0xef,0xfe,0xc0,0x0c,0x00,0xc0,0x0c,0x00,0xc0,0x0c,0x00,0xff,0xff,0xff,
/* F codepoint=70,  glyphindex=39, width=11*/ 0xff,0xff,0xff,0x00,0x60,0x0c,0x01,0x80,0x30,0x06,0x00,0xff,0xdf,0xfb,0x00,0x60,0x0c,0x01,0x80,0x30,0x06,0x00,0xc0,0x18,0x00,
/* G codepoint=71,  glyphindex=40, width=16*/ 0x07,0xf0,0x1f,0xfc,0x3c,0x1e,0x70,0x06,0x60,0x03,0xe0,0x00,0xc0,0x00,0xc0,0x00,0xc0,0x7f,0xc0,0x7f,0xc0,0x03,0xc0,0x03,0x60,0x03,0x60,0x07,0x30,0x0f,0x3c,0x1f,0x1f,0xfb,0x07,0xe1,
/* H codepoint=72,  glyphindex=41, width=13*/ 0xc0,0x1e,0x00,0xf0,0x07,0x80,0x3c,0x01,0xe0,0x0f,0x00,0x78,0x03,0xff,0xff,0xff,0xf0,0x07,0x80,0x3c,0x01,0xe0,0x0f,0x00,0x78,0x03,0xc0,0x1e,0x00,0xc0,
/* I codepoint=73,  glyphindex=42, width=2*/ 0xff,0xff,0xff,0xff,0xf0,
/* J codepoint=74,  glyphindex=43, width=9*/ 0x01,0x80,0xc0,0x60,0x30,0x18,0x0c,0x06,0x03,0x01,0x80,0xc0,0x60,0x3c,0x1e,0x0f,0x07,0xc7,0x7f,0x1f,0x00,
/* K codepoint=75,  glyphindex=44, width=14*/ 0xc0,0x3b,0x01,0xcc,0x0e,0x30,0x70,0xc3,0x83,0x1c,0x0c,0xe0,0x33,0x80,0xde,0x03,0xdc,0x0e,0x38,0x30,0x60,0xc1,0xc3,0x03,0x8c,0x06,0x30,0x1c,0xc0,0x3b,0x00,0x60,
/* L codepoint=76,  glyphindex=45, width=10*/ 0xc0,0x30,0x0c,0x03,0x00,0xc0,0x30,0x0c,0x03,0x00,0xc0,0x30,0x0c,0x03,0x00,0xc0,0x30,0x0c,0x03,0x00,0xff,0xff,0xf0,
/* M codepoint=77,  glyphindex=46, width=16*/ 0xe0,0x07,0xe0,0x07,0xf0,0x0f,0xf0,0x0f,0xd0,0x0f,0xd8,0x1b,0xd8,0x1b,0xd8,0x1b,0xcc,0x33,0xcc,0x33,0xcc,0x33,0xc6,0x63,0xc6,0x63,0xc6,0x63,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc1,0x83,
/* N codepoint=78,  glyphindex=47, width=13*/ 0xe0,0x1f,0x00,0xfc,0x07,0xe0,0x3d,0x81,0xee,0x0f,0x30,0x79,0xc3,0xc6,0x1e,0x18,0xf0,0xe7,0x83,0x3c,0x1d,0xe0,0x6f,0x01,0xf8,0x0f,0xc0,0x3e,0x01,0xc0,
/* O codepoint=79,  glyphindex=48, width=17*/ 0x03,0xe0,0x0f,0xfc,0x0f,0x07,0x86,0x00,0xc6,0x00,0x33,0x00,0x1b,0x00,0x07,0x80,0x03,0xc0,0x01,0xe0,0x00,0xf0,0x00,0x78,0x00,0x36,0x00,0x33,0x00,0x18,0xc0,0x18,0x78,0x3c,0x1f,0xfc,0x03,0xf8,0x00,
/* P codepoint=80,  glyphindex=49, width=12*/ 0xff,0x8f,0xfe,0xc0,0x6c,0x03,0xc0,0x3c,0x03,0xc0,0x3c,0x07,0xff,0xef,0xfc,0xc0,0x0c,0x00,0xc0,0x0c,0x00,0xc0,0x0c,0x00,0xc0,0x0c,0x00,
/* Q codepoint=81,  glyphindex=50, width=17*/ 0x03,0xe0,0x0f,0xfc,0x0f,0x07,0x86,0x00,0xc6,0x00,0x33,0x00,0x1b,0x00,0x07,0x80,0x03,0xc0,0x01,0xe0,0x00,0xf0,0x00,0x78,0x00,0x36,0x00,0x33,0x01,0x98,0xc0,0xfc,0x78,0x3c,0x1f,0xff,0x03,0xf9,0x80,0x00,0x40,
/* R codepoint=82,  glyphindex=51, width=14*/ 0xff,0xc3,0xff,0xcc,0x03,0xb0,0x06,0xc0,0x1b,0x00,0x6c,0x01,0xb0,0x0c,0xff,0xe3,0xff,0xcc,0x03,0xb0,0x06,0xc0,0x1b,0x00,0x6c,0x01,0xb0,0x06,0xc0,0x1b,0x00,0x70,
/* S codepoint=83,  glyphindex=52, width=14*/ 0x0f,0xe0,0x7f,0xc3,0x83,0x9c,0x07,0x60,0x0d,0x80,0x06,0x00,0x1e,0x00,0x3f,0x80,0x3f,0xc0,0x0f,0x80,0x07,0xc0,0x0f,0x00,0x3e,0x00,0xde,0x0e,0x3f,0xf0,0x3f,0x80,
/* T codepoint=84,  glyphindex=53, width=12*/ 0xff,0xff,0xff,0x06,0x00,0x60,0x06,0x00,0x60,0x06,0x00,0x60,0x06,0x00,0x60,0x06,0x00,0x60,0x06,0x00,0x60,0x06,0x00,0x60,0x06,0x00,0x60,
/* U codepoint=85,  glyphindex=54, width=13*/ 0xc0,0x1e,0x00,0xf0,0x07,0x80,0x3c,0x01,0xe0,0x0f,0x00,0x78,0x03,0xc0,0x1e,0x00,0xf0,0x07,0x80,0x3c,0x01,0xe0,0x0f,0x80,0xee,0x0e,0x3f,0xe0,0x7c,0x00,
/* V codepoint=86,  glyphindex=55, width=15*/ 0x60,0x06,0xc0,0x1d,0xc0,0x31,0x80,0x63,0x01,0xc7,0x03,0x06,0x06,0x0c,0x1c,0x1c,0x30,0x18,0x60,0x31,0xc0,0x73,0x00,0x66,0x00,0xdc,0x01,0xf0,0x01,0xe0,0x03,0xc0,0x07,0x00,
/* W codepoint=87,  glyphindex=56, width=22*/ 0xe0,0x30,0x1d,0x80,0xe0,0x76,0x07,0x81,0xd8,0x1e,0x06,0x70,0x7c,0x18,0xc1,0xb0,0xe3,0x0c,0xc3,0x8c,0x33,0x0c,0x38,0xc6,0x30,0x67,0x18,0xc1,0x98,0x67,0x06,0x61,0xd8,0x1d,0x83,0x60,0x3c,0x0d,0x80,0xf0,0x3e,0x03,0xc0,0x70,0x0f,0x01,0xc0,0x18,0x07,0x00,
/* X codepoint=88,  glyphindex=57, width=15*/ 0x70,0x0e,0x60,0x38,0xe0,0x60,0xe1,0xc0,0xc3,0x01,0xcc,0x01,0xf8,0x01,0xe0,0x03,0x80,0x07,0x80,0x1f,0x00,0x33,0x00,0xe7,0x03,0x86,0x06,0x0e,0x1c,0x0e,0x70,0x0c,0xc0,0x1c,
/* Y codepoint=89,  glyphindex=58, width=16*/ 0x60,0x06,0x70,0x0e,0x30,0x1c,0x38,0x18,0x1c,0x38,0x0c,0x30,0x0e,0x70,0x06,0x60,0x03,0xc0,0x03,0xc0,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
/* Z codepoint=90,  glyphindex=59, width=13*/ 0xff,0xff,0xff,0xc0,0x0e,0x00,0xe0,0x0e,0x00,0x60,0x07,0x00,0x70,0x07,0x00,0x30,0x03,0x80,0x38,0x03,0x80,0x18,0x01,0xc0,0x1c,0x00,0xff,0xff,0xff,0xc0,
/* [ codepoint=91,  glyphindex=60, width=4*/ 0xff,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcf,0xf0,
/* \ codepoint=92,  glyphindex=61, width=7*/ 0x81,0x81,0x02,0x06,0x04,0x08,0x18,0x10,0x20,0x60,0x40,0x81,0x81,0x02,0x06,0x04,
/* ] codepoint=93,  glyphindex=62, width=4*/ 0xff,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x3f,0xf0,
/* ^ codepoint=94,  glyphindex=63, width=9*/ 0x0c,0x0e,0x05,0x86,0xc3,0x21,0x19,0x8c,0x83,0xc1,0x80,
/* _ codepoint=95,  glyphindex=64, width=15*/ 0xff,0xfe,
/* ` codepoint=96,  glyphindex=65, width=5*/ 0xe3,0x8c,0x30,
/* a codepoint=97,  glyphindex=66, width=12*/ 0x3f,0x07,0xf8,0xe1,0xcc,0x0c,0x00,0xc0,0x1c,0x3f,0xcf,0x8c,0xc0,0xcc,0x0c,0xe3,0xc7,0xef,0x3c,0x70,
/* b codepoint=98,  glyphindex=67, width=12*/ 0xc0,0x0c,0x00,0xc0,0x0c,0x00,0xc0,0x0c,0xf8,0xdf,0xcf,0x0e,0xe0,0x7c,0x03,0xc0,0x3c,0x03,0xc0,0x3c,0x03,0xe0,0x6f,0x0e,0xdf,0xcc,0xf8,
/* c codepoint=99,  glyphindex=68, width=10*/ 0x1f,0x0f,0xe7,0x1b,0x83,0xc0,0x30,0x0c,0x03,0x00,0xc0,0x38,0x37,0x1c,0xfe,0x1f,0x00,
/* d codepoint=100,  glyphindex=69, width=11*/ 0x00,0x60,0x0c,0x01,0x80,0x30,0x06,0x3c,0xcf,0xfb,0x8f,0xe0,0xf8,0x0f,0x01,0xe0,0x3c,0x07,0x80,0xf8,0x3b,0x8f,0x3f,0x63,0xcc,
/* e codepoint=101,  glyphindex=70, width=11*/ 0x1f,0x07,0xf1,0xc7,0x70,0x3c,0x07,0xff,0xff,0xfe,0x00,0xc0,0x1c,0x0d,0xc3,0x1f,0xe1,0xf0,
/* f codepoint=102,  glyphindex=71, width=5*/ 0x3b,0xd8,0xc6,0x7f,0xec,0x63,0x18,0xc6,0x31,0x8c,0x63,0x00,
/* g codepoint=103,  glyphindex=72, width=11*/ 0x1e,0x67,0xfd,0xc7,0xf0,0x7c,0x07,0x80,0xf0,0x1e,0x03,0xc0,0x7c,0x1d,0xc7,0x9f,0xb1,0xe6,0x00,0xc0,0x3e,0x0e,0x7f,0xc7,0xe0,
/* h codepoint=104,  glyphindex=73, width=10*/ 0xc0,0x30,0x0c,0x03,0x00,0xc0,0x33,0xcd,0xfb,0xc7,0xe0,0xf0,0x3c,0x0f,0x03,0xc0,0xf0,0x3c,0x0f,0x03,0xc0,0xf0,0x30,
/* i codepoint=105,  glyphindex=74, width=2*/ 0xf0,0x3f,0xff,0xff,0xf0,
/* j codepoint=106,  glyphindex=75, width=4*/ 0x33,0x00,0x03,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x3f,0xe0,
/* k codepoint=107,  glyphindex=76, width=11*/ 0xc0,0x18,0x03,0x00,0x60,0x0c,0x01,0x83,0x30,0xc6,0x30,0xcc,0x1b,0x83,0xf0,0x77,0x0c,0x61,0x8e,0x30,0xe6,0x0c,0xc1,0xd8,0x18,
/* l codepoint=108,  glyphindex=77, width=2*/ 0xff,0xff,0xff,0xff,0xf0,
/* m codepoint=109,  glyphindex=78, width=17*/ 0xcf,0x1f,0x6f,0xdf,0xfc,0x78,0xfc,0x18,0x3c,0x0c,0x1e,0x06,0x0f,0x03,0x07,0x81,0x83,0xc0,0xc1,0xe0,0x60,0xf0,0x30,0x78,0x18,0x3c,0x0c,0x18,
/* n codepoint=110,  glyphindex=79, width=10*/ 0xcf,0x37,0xef,0x1f,0x83,0xc0,0xf0,0x3c,0x0f,0x03,0xc0,0xf0,0x3c,0x0f,0x03,0xc0,0xc0,
/* o codepoint=111,  glyphindex=80, width=11*/ 0x1f,0x07,0xf1,0xc7,0x70,0x7c,0x07,0x80,0xf0,0x1e,0x03,0xc0,0x7c,0x1d,0xc7,0x1f,0xc1,0xf0,
/* p codepoint=112,  glyphindex=81, width=12*/ 0xcf,0x8d,0xfc,0xf0,0xee,0x06,0xc0,0x3c,0x03,0xc0,0x3c,0x03,0xc0,0x3e,0x07,0xf0,0xef,0xfc,0xcf,0x8c,0x00,0xc0,0x0c,0x00,0xc0,0x00,
/* q codepoint=113,  glyphindex=82, width=11*/ 0x1e,0x67,0xfd,0xc7,0xf0,0x7c,0x07,0x80,0xf0,0x1e,0x03,0xc0,0x7c,0x1d,0xc7,0x9f,0xf1,0xe6,0x00,0xc0,0x18,0x03,0x00,0x60,
/* r codepoint=114,  glyphindex=83, width=6*/ 0xcf,0x7f,0x38,0xc3,0x0c,0x30,0xc3,0x0c,0x30,0xc0,
/* s codepoint=115,  glyphindex=84, width=10*/ 0x3e,0x1f,0xee,0x1b,0x00,0xc0,0x3c,0x07,0xf0,0x3e,0x01,0xf0,0x3e,0x1d,0xfe,0x3e,0x00,
/* t codepoint=116,  glyphindex=85, width=5*/ 0x63,0x19,0xff,0xb1,0x8c,0x63,0x18,0xc6,0x31,0xe7,
/* u codepoint=117,  glyphindex=86, width=10*/ 0xc0,0xf0,0x3c,0x0f,0x03,0xc0,0xf0,0x3c,0x0f,0x03,0xc0,0xf0,0x7e,0x3d,0xfb,0x3c,0xc0,
/* v codepoint=118,  glyphindex=87, width=12*/ 0xe0,0x66,0x06,0x60,0x67,0x0c,0x30,0xc3,0x0c,0x39,0x81,0x98,0x19,0x81,0xf0,0x0f,0x00,0xe0,0x0e,0x00,
/* w codepoint=119,  glyphindex=88, width=17*/ 0xc1,0xc1,0xb0,0xe1,0xd8,0x70,0xcc,0x2c,0x66,0x36,0x31,0x9b,0x18,0xcd,0x98,0x64,0x6c,0x16,0x36,0x0f,0x1a,0x07,0x8f,0x03,0x83,0x80,0xc1,0xc0,
/* x codepoint=120,  glyphindex=89, width=11*/ 0x60,0xee,0x18,0xc6,0x0c,0xc1,0xf0,0x1c,0x01,0x80,0x78,0x1b,0x03,0x30,0xc7,0x30,0x66,0x06,
/* y codepoint=121,  glyphindex=90, width=11*/ 0xe0,0x6c,0x0d,0x83,0x38,0x63,0x0c,0x63,0x0e,0x60,0xcc,0x1b,0x03,0x60,0x3c,0x07,0x00,0xe0,0x18,0x03,0x00,0xe0,0x78,0x0e,0x00,
/* z codepoint=122,  glyphindex=91, width=10*/ 0xff,0xff,0xf0,0x18,0x0c,0x07,0x03,0x81,0xc0,0x60,0x30,0x18,0x0e,0x03,0xff,0xff,0xc0,
/* { codepoint=123,  glyphindex=92, width=5*/ 0x19,0xcc,0x63,0x18,0xc6,0x31,0x99,0x86,0x18,0xc6,0x31,0x8c,0x63,0x1c,0x60,
/* | codepoint=124,  glyphindex=93, width=2*/ 0xff,0xff,0xff,0xff,0xff,0xfc,
/* } codepoint=125,  glyphindex=94, width=5*/ 0xc7,0x18,0xc6,0x31,0x8c,0x63,0x0c,0x33,0x31,0x8c,0x63,0x18,0xc6,0x73,0x00,
/* ~ codepoint=126,  glyphindex=95, width=10*/ 0x70,0x3e,0x09,0xe4,0x1f,0x03,0x80,

};

constexpr std::initializer_list<GlyphDesc> glyph_desc={
	GlyphDesc(0, 0, 0, 0, 0, 0, 0, 0, lcd_common::BitmapFormat::UNDEFINED),// DummyGlyph glyphindex=0 codepoint=0
	GlyphDesc(0, 768, 0, 0, 0, 1, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),//   glyphindex=1 codepoint=32
	GlyphDesc(0, 1024, 2, 18, 3, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// ! glyphindex=2 codepoint=33
	GlyphDesc(5, 1024, 6, 6, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// " glyphindex=3 codepoint=34
	GlyphDesc(10, 1664, 13, 16, 0, -15, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// # glyphindex=4 codepoint=35
	GlyphDesc(36, 1664, 11, 20, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// $ glyphindex=5 codepoint=36
	GlyphDesc(64, 2688, 20, 17, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// % glyphindex=6 codepoint=37
	GlyphDesc(107, 2048, 14, 17, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// & glyphindex=7 codepoint=38
	GlyphDesc(137, 640, 2, 6, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// ' glyphindex=8 codepoint=39
	GlyphDesc(139, 1024, 5, 23, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// ( glyphindex=9 codepoint=40
	GlyphDesc(154, 1024, 5, 23, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// ) glyphindex=10 codepoint=41
	GlyphDesc(169, 1152, 7, 7, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// * glyphindex=11 codepoint=42
	GlyphDesc(176, 1792, 10, 11, 2, -10, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// + glyphindex=12 codepoint=43
	GlyphDesc(190, 896, 2, 6, 2, -1, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// , glyphindex=13 codepoint=44
	GlyphDesc(192, 1024, 6, 2, 1, -7, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// - glyphindex=14 codepoint=45
	GlyphDesc(194, 768, 2, 2, 2, -1, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// . glyphindex=15 codepoint=46
	GlyphDesc(195, 896, 7, 18, 0, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// / glyphindex=16 codepoint=47
	GlyphDesc(211, 1664, 11, 17, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// 0 glyphindex=17 codepoint=48
	GlyphDesc(235, 1664, 5, 17, 3, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// 1 glyphindex=18 codepoint=49
	GlyphDesc(246, 1664, 11, 17, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// 2 glyphindex=19 codepoint=50
	GlyphDesc(270, 1664, 11, 17, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// 3 glyphindex=20 codepoint=51
	GlyphDesc(294, 1664, 11, 17, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// 4 glyphindex=21 codepoint=52
	GlyphDesc(318, 1664, 11, 17, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// 5 glyphindex=22 codepoint=53
	GlyphDesc(342, 1664, 11, 17, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// 6 glyphindex=23 codepoint=54
	GlyphDesc(366, 1664, 11, 17, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// 7 glyphindex=24 codepoint=55
	GlyphDesc(390, 1664, 11, 17, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// 8 glyphindex=25 codepoint=56
	GlyphDesc(414, 1664, 11, 17, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// 9 glyphindex=26 codepoint=57
	GlyphDesc(438, 768, 2, 13, 2, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// : glyphindex=27 codepoint=58
	GlyphDesc(442, 768, 2, 16, 2, -11, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// ; glyphindex=28 codepoint=59
	GlyphDesc(446, 1792, 12, 12, 1, -11, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// < glyphindex=29 codepoint=60
	GlyphDesc(464, 1792, 12, 6, 1, -8, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// = glyphindex=30 codepoint=61
	GlyphDesc(473, 1792, 12, 12, 1, -11, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// > glyphindex=31 codepoint=62
	GlyphDesc(491, 1664, 10, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// ? glyphindex=32 codepoint=63
	GlyphDesc(514, 3072, 22, 21, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// @ glyphindex=33 codepoint=64
	GlyphDesc(572, 2048, 16, 18, 0, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// A glyphindex=34 codepoint=65
	GlyphDesc(608, 2048, 13, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// B glyphindex=35 codepoint=66
	GlyphDesc(638, 2176, 15, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// C glyphindex=36 codepoint=67
	GlyphDesc(672, 2176, 14, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// D glyphindex=37 codepoint=68
	GlyphDesc(704, 1920, 12, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// E glyphindex=38 codepoint=69
	GlyphDesc(731, 1792, 11, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// F glyphindex=39 codepoint=70
	GlyphDesc(756, 2304, 16, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// G glyphindex=40 codepoint=71
	GlyphDesc(792, 2176, 13, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// H glyphindex=41 codepoint=72
	GlyphDesc(822, 896, 2, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// I glyphindex=42 codepoint=73
	GlyphDesc(827, 1664, 9, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// J glyphindex=43 codepoint=74
	GlyphDesc(848, 2048, 14, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// K glyphindex=44 codepoint=75
	GlyphDesc(880, 1792, 10, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// L glyphindex=45 codepoint=76
	GlyphDesc(903, 2560, 16, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// M glyphindex=46 codepoint=77
	GlyphDesc(939, 2304, 13, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// N glyphindex=47 codepoint=78
	GlyphDesc(969, 2432, 17, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// O glyphindex=48 codepoint=79
	GlyphDesc(1008, 2048, 12, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// P glyphindex=49 codepoint=80
	GlyphDesc(1035, 2432, 17, 19, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// Q glyphindex=50 codepoint=81
	GlyphDesc(1076, 2176, 14, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// R glyphindex=51 codepoint=82
	GlyphDesc(1108, 2048, 14, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// S glyphindex=52 codepoint=83
	GlyphDesc(1140, 1920, 12, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// T glyphindex=53 codepoint=84
	GlyphDesc(1167, 2176, 13, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// U glyphindex=54 codepoint=85
	GlyphDesc(1197, 1920, 15, 18, 0, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// V glyphindex=55 codepoint=86
	GlyphDesc(1231, 2816, 22, 18, 0, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// W glyphindex=56 codepoint=87
	GlyphDesc(1281, 2048, 15, 18, 0, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// X glyphindex=57 codepoint=88
	GlyphDesc(1315, 2048, 16, 18, 0, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// Y glyphindex=58 codepoint=89
	GlyphDesc(1351, 1920, 13, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// Z glyphindex=59 codepoint=90
	GlyphDesc(1381, 896, 4, 23, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// [ glyphindex=60 codepoint=91
	GlyphDesc(1393, 896, 7, 18, 0, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// \ glyphindex=61 codepoint=92
	GlyphDesc(1409, 896, 4, 23, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// ] glyphindex=62 codepoint=93
	GlyphDesc(1421, 1408, 9, 9, 1, -16, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// ^ glyphindex=63 codepoint=94
	GlyphDesc(1432, 1664, 15, 1, -1, 4, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// _ glyphindex=64 codepoint=95
	GlyphDesc(1434, 768, 5, 4, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// ` glyphindex=65 codepoint=96
	GlyphDesc(1437, 1664, 12, 13, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// a glyphindex=66 codepoint=97
	GlyphDesc(1457, 1664, 12, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// b glyphindex=67 codepoint=98
	GlyphDesc(1484, 1536, 10, 13, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// c glyphindex=68 codepoint=99
	GlyphDesc(1501, 1664, 11, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// d glyphindex=69 codepoint=100
	GlyphDesc(1526, 1664, 11, 13, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// e glyphindex=70 codepoint=101
	GlyphDesc(1544, 896, 5, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// f glyphindex=71 codepoint=102
	GlyphDesc(1556, 1664, 11, 18, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// g glyphindex=72 codepoint=103
	GlyphDesc(1581, 1664, 10, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// h glyphindex=73 codepoint=104
	GlyphDesc(1604, 640, 2, 18, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// i glyphindex=74 codepoint=105
	GlyphDesc(1609, 768, 4, 23, 0, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// j glyphindex=75 codepoint=106
	GlyphDesc(1621, 1536, 11, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// k glyphindex=76 codepoint=107
	GlyphDesc(1646, 640, 2, 18, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// l glyphindex=77 codepoint=108
	GlyphDesc(1651, 2432, 17, 13, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// m glyphindex=78 codepoint=109
	GlyphDesc(1679, 1664, 10, 13, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// n glyphindex=79 codepoint=110
	GlyphDesc(1696, 1664, 11, 13, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// o glyphindex=80 codepoint=111
	GlyphDesc(1714, 1664, 12, 17, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// p glyphindex=81 codepoint=112
	GlyphDesc(1740, 1664, 11, 17, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// q glyphindex=82 codepoint=113
	GlyphDesc(1764, 1024, 6, 13, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// r glyphindex=83 codepoint=114
	GlyphDesc(1774, 1536, 10, 13, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// s glyphindex=84 codepoint=115
	GlyphDesc(1791, 896, 5, 16, 1, -15, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// t glyphindex=85 codepoint=116
	GlyphDesc(1801, 1664, 10, 13, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// u glyphindex=86 codepoint=117
	GlyphDesc(1818, 1536, 12, 13, 0, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// v glyphindex=87 codepoint=118
	GlyphDesc(1838, 2176, 17, 13, 0, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// w glyphindex=88 codepoint=119
	GlyphDesc(1866, 1408, 11, 13, 0, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// x glyphindex=89 codepoint=120
	GlyphDesc(1884, 1408, 11, 18, 0, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// y glyphindex=90 codepoint=121
	GlyphDesc(1909, 1536, 10, 13, 1, -12, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// z glyphindex=91 codepoint=122
	GlyphDesc(1926, 1024, 5, 23, 1, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// { glyphindex=92 codepoint=123
	GlyphDesc(1941, 768, 2, 23, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// | glyphindex=93 codepoint=124
	GlyphDesc(1947, 1024, 5, 23, 2, -17, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// } glyphindex=94 codepoint=125
	GlyphDesc(1962, 1536, 10, 5, 1, -10, 0, 0, lcd_common::BitmapFormat::ONE_BPP_ROW_BY_ROW),// ~ glyphindex=95 codepoint=126

};

constexpr std::initializer_list<CharacterMap0Tiny> cmaps={
	CharacterMap0Tiny(32, 1, 95),

};

constexpr std::initializer_list<int16_t> kern_class_values = {};

constexpr const FontDesc font = FontDesc(
	0, 
	0,
	&kern_class_values,
	1,
	&cmaps,
	&glyph_desc,
	&glyph_bitmap,
	29,
	0);
}