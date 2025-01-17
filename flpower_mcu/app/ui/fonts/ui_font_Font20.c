/*******************************************************************************
 * Size: 20 px
 * Bpp: 4
 * Opts: --bpp 4 --size 20 --font D:\OSProject\flPower\software\gui\assets\Arial.ttf -o D:\OSProject\flPower\software\gui\assets\ui_font_Font20.c --format lvgl --symbols 0123456789.AVSETONC --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONT20
#define UI_FONT_FONT20 1
#endif

#if UI_FONT_FONT20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002E "." */
    0x1, 0x13, 0xfd, 0x3f, 0xd0,

    /* U+0030 "0" */
    0x0, 0x7, 0xdf, 0xd7, 0x0, 0x0, 0xa, 0xfc,
    0x8c, 0xfa, 0x0, 0x4, 0xfa, 0x0, 0xa, 0xf4,
    0x0, 0xbf, 0x20, 0x0, 0x1f, 0xa0, 0xe, 0xe0,
    0x0, 0x0, 0xde, 0x1, 0xfb, 0x0, 0x0, 0xb,
    0xf1, 0x2f, 0xa0, 0x0, 0x0, 0xaf, 0x22, 0xfa,
    0x0, 0x0, 0xa, 0xf2, 0x2f, 0xa0, 0x0, 0x0,
    0xaf, 0x11, 0xfb, 0x0, 0x0, 0xb, 0xf0, 0xe,
    0xd0, 0x0, 0x0, 0xde, 0x0, 0xaf, 0x10, 0x0,
    0x1f, 0xa0, 0x4, 0xfa, 0x0, 0xa, 0xf4, 0x0,
    0xb, 0xfc, 0x8c, 0xfa, 0x0, 0x0, 0x8, 0xdf,
    0xd7, 0x0, 0x0,

    /* U+0031 "1" */
    0x0, 0x1, 0xe7, 0x0, 0xc, 0xf7, 0x1, 0xcf,
    0xf7, 0x6e, 0xfb, 0xf7, 0xdd, 0x45, 0xf7, 0x40,
    0x5, 0xf7, 0x0, 0x5, 0xf7, 0x0, 0x5, 0xf7,
    0x0, 0x5, 0xf7, 0x0, 0x5, 0xf7, 0x0, 0x5,
    0xf7, 0x0, 0x5, 0xf7, 0x0, 0x5, 0xf7, 0x0,
    0x5, 0xf7, 0x0, 0x5, 0xf7,

    /* U+0032 "2" */
    0x0, 0x19, 0xef, 0xea, 0x20, 0x0, 0x1e, 0xfb,
    0x8b, 0xfe, 0x20, 0x9, 0xf7, 0x0, 0x5, 0xfb,
    0x0, 0xee, 0x0, 0x0, 0xd, 0xf0, 0x6, 0x60,
    0x0, 0x0, 0xdf, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0xd0, 0x0, 0x0, 0x0, 0xb, 0xf6, 0x0, 0x0,
    0x0, 0x9, 0xfb, 0x0, 0x0, 0x0, 0x9, 0xfc,
    0x0, 0x0, 0x0, 0xb, 0xfb, 0x0, 0x0, 0x0,
    0x1c, 0xfa, 0x0, 0x0, 0x0, 0xc, 0xf8, 0x0,
    0x0, 0x0, 0x8, 0xf9, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xcc, 0xcc, 0xcc, 0xc0, 0x5f, 0xff, 0xff,
    0xff, 0xff, 0x10,

    /* U+0033 "3" */
    0x0, 0x19, 0xdf, 0xd7, 0x0, 0x0, 0x1d, 0xfa,
    0x8c, 0xfb, 0x0, 0x9, 0xf6, 0x0, 0xa, 0xf4,
    0x0, 0xad, 0x0, 0x0, 0x5f, 0x70, 0x0, 0x0,
    0x0, 0x8, 0xf5, 0x0, 0x0, 0x0, 0x38, 0xfc,
    0x0, 0x0, 0x0, 0x9f, 0xfe, 0x20, 0x0, 0x0,
    0x4, 0x57, 0xff, 0x40, 0x0, 0x0, 0x0, 0x3,
    0xfd, 0x0, 0x0, 0x0, 0x0, 0xc, 0xf1, 0x6,
    0x50, 0x0, 0x0, 0xbf, 0x30, 0xfe, 0x0, 0x0,
    0xe, 0xf0, 0xa, 0xf7, 0x0, 0x8, 0xfa, 0x0,
    0x1e, 0xfb, 0x9c, 0xfd, 0x10, 0x0, 0x19, 0xef,
    0xd8, 0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x8f, 0x30, 0x0, 0x0, 0x0,
    0x3f, 0xf3, 0x0, 0x0, 0x0, 0xd, 0xff, 0x30,
    0x0, 0x0, 0x8, 0xfb, 0xf3, 0x0, 0x0, 0x2,
    0xf8, 0x8f, 0x30, 0x0, 0x0, 0xcd, 0x8, 0xf3,
    0x0, 0x0, 0x7f, 0x30, 0x8f, 0x30, 0x0, 0x2f,
    0x90, 0x8, 0xf3, 0x0, 0xc, 0xe0, 0x0, 0x8f,
    0x30, 0x6, 0xf4, 0x0, 0x8, 0xf3, 0x0, 0xcf,
    0xff, 0xff, 0xff, 0xff, 0x28, 0xaa, 0xaa, 0xad,
    0xfb, 0xa1, 0x0, 0x0, 0x0, 0x8f, 0x30, 0x0,
    0x0, 0x0, 0x8, 0xf3, 0x0, 0x0, 0x0, 0x0,
    0x8f, 0x30, 0x0,

    /* U+0035 "5" */
    0x0, 0x8f, 0xff, 0xff, 0xfa, 0x0, 0xb, 0xfb,
    0xbb, 0xbb, 0x70, 0x0, 0xec, 0x0, 0x0, 0x0,
    0x0, 0x1f, 0x90, 0x0, 0x0, 0x0, 0x4, 0xf6,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0x7b, 0xee, 0xa2,
    0x0, 0xa, 0xff, 0xca, 0xdf, 0xf3, 0x0, 0xbf,
    0x40, 0x0, 0x7f, 0xd0, 0x0, 0x0, 0x0, 0x0,
    0xdf, 0x20, 0x0, 0x0, 0x0, 0x9, 0xf4, 0x2,
    0x20, 0x0, 0x0, 0xaf, 0x41, 0xfe, 0x0, 0x0,
    0xd, 0xf1, 0xb, 0xf6, 0x0, 0x7, 0xfa, 0x0,
    0x2e, 0xfb, 0x8c, 0xfd, 0x10, 0x0, 0x2a, 0xef,
    0xd8, 0x0, 0x0,

    /* U+0036 "6" */
    0x0, 0x5, 0xcf, 0xea, 0x20, 0x0, 0x8, 0xfd,
    0x8a, 0xff, 0x20, 0x3, 0xfc, 0x0, 0x4, 0xfa,
    0x0, 0xaf, 0x20, 0x0, 0x9, 0x80, 0xe, 0xc0,
    0x0, 0x0, 0x0, 0x1, 0xf9, 0x2b, 0xff, 0xa2,
    0x0, 0x3f, 0xbf, 0xea, 0xcf, 0xe2, 0x3, 0xff,
    0xa0, 0x0, 0x7f, 0xb0, 0x3f, 0xf1, 0x0, 0x0,
    0xdf, 0x2, 0xfd, 0x0, 0x0, 0xa, 0xf2, 0xf,
    0xd0, 0x0, 0x0, 0xaf, 0x20, 0xcf, 0x10, 0x0,
    0xd, 0xf0, 0x5, 0xfa, 0x0, 0x6, 0xf9, 0x0,
    0xa, 0xfd, 0x8b, 0xfd, 0x10, 0x0, 0x6, 0xdf,
    0xe9, 0x10, 0x0,

    /* U+0037 "7" */
    0xf, 0xff, 0xff, 0xff, 0xff, 0x30, 0xcc, 0xcc,
    0xcc, 0xcf, 0xf1, 0x0, 0x0, 0x0, 0x9, 0xf6,
    0x0, 0x0, 0x0, 0x4, 0xfb, 0x0, 0x0, 0x0,
    0x0, 0xdf, 0x20, 0x0, 0x0, 0x0, 0x6f, 0x80,
    0x0, 0x0, 0x0, 0xe, 0xf1, 0x0, 0x0, 0x0,
    0x5, 0xf9, 0x0, 0x0, 0x0, 0x0, 0xbf, 0x30,
    0x0, 0x0, 0x0, 0xf, 0xd0, 0x0, 0x0, 0x0,
    0x5, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x9f, 0x40,
    0x0, 0x0, 0x0, 0xc, 0xf1, 0x0, 0x0, 0x0,
    0x0, 0xee, 0x0, 0x0, 0x0, 0x0, 0xf, 0xc0,
    0x0, 0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x8, 0xef, 0xe9, 0x10, 0x0, 0xc, 0xfc,
    0x8b, 0xfd, 0x0, 0x5, 0xf9, 0x0, 0x9, 0xf6,
    0x0, 0x9f, 0x30, 0x0, 0x3f, 0xa0, 0x8, 0xf6,
    0x0, 0x5, 0xf8, 0x0, 0x2f, 0xe6, 0x25, 0xee,
    0x10, 0x0, 0x3d, 0xff, 0xfe, 0x20, 0x0, 0x1b,
    0xf8, 0x68, 0xfe, 0x20, 0xa, 0xf4, 0x0, 0x3,
    0xfc, 0x0, 0xfc, 0x0, 0x0, 0xb, 0xf1, 0x2f,
    0xa0, 0x0, 0x0, 0x9f, 0x31, 0xfd, 0x0, 0x0,
    0xc, 0xf1, 0xb, 0xf6, 0x0, 0x5, 0xfc, 0x0,
    0x2e, 0xfb, 0x8b, 0xfe, 0x20, 0x0, 0x19, 0xef,
    0xe9, 0x10, 0x0,

    /* U+0039 "9" */
    0x0, 0x19, 0xef, 0xc6, 0x0, 0x0, 0x1e, 0xfc,
    0x9c, 0xfa, 0x0, 0xa, 0xf8, 0x0, 0x8, 0xf5,
    0x0, 0xfe, 0x0, 0x0, 0xe, 0xc0, 0x2f, 0xb0,
    0x0, 0x0, 0xcf, 0x2, 0xfb, 0x0, 0x0, 0xc,
    0xf2, 0xe, 0xf1, 0x0, 0x2, 0xff, 0x30, 0x8f,
    0xc3, 0x3, 0xdf, 0xf3, 0x0, 0xaf, 0xff, 0xfb,
    0x8f, 0x30, 0x0, 0x48, 0x84, 0x9, 0xf1, 0x0,
    0x0, 0x0, 0x0, 0xde, 0x0, 0xac, 0x0, 0x0,
    0x2f, 0xa0, 0x8, 0xf4, 0x0, 0xc, 0xf2, 0x0,
    0x1e, 0xf9, 0x8d, 0xf7, 0x0, 0x0, 0x2a, 0xef,
    0xc5, 0x0, 0x0,

    /* U+0041 "A" */
    0x0, 0x0, 0x0, 0xbf, 0xb0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xff, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xf7, 0xf7, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xde, 0xf, 0xd0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xa0, 0xaf, 0x40, 0x0, 0x0, 0x0, 0x8,
    0xf5, 0x4, 0xfa, 0x0, 0x0, 0x0, 0x0, 0xef,
    0x0, 0xe, 0xf1, 0x0, 0x0, 0x0, 0x4f, 0xa0,
    0x0, 0x9f, 0x70, 0x0, 0x0, 0xa, 0xf4, 0x0,
    0x3, 0xfd, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff,
    0xff, 0xf3, 0x0, 0x0, 0x6f, 0xc9, 0x99, 0x99,
    0xbf, 0x90, 0x0, 0xc, 0xf3, 0x0, 0x0, 0x1,
    0xff, 0x0, 0x1, 0xfd, 0x0, 0x0, 0x0, 0xb,
    0xf6, 0x0, 0x7f, 0x80, 0x0, 0x0, 0x0, 0x5f,
    0xc0, 0xd, 0xf2, 0x0, 0x0, 0x0, 0x0, 0xff,
    0x20,

    /* U+0043 "C" */
    0x0, 0x3, 0x9d, 0xff, 0xc6, 0x0, 0x0, 0x8,
    0xff, 0xdb, 0xcf, 0xfb, 0x0, 0x8, 0xfd, 0x30,
    0x0, 0x1c, 0xf9, 0x2, 0xfe, 0x10, 0x0, 0x0,
    0x1f, 0xf1, 0x8f, 0x70, 0x0, 0x0, 0x0, 0x67,
    0x1c, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0xef,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xef, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xc, 0xf3, 0x0, 0x0, 0x0, 0x1,
    0x20, 0x7f, 0x70, 0x0, 0x0, 0x0, 0x8f, 0x72,
    0xfe, 0x10, 0x0, 0x0, 0x1e, 0xf2, 0x8, 0xfd,
    0x30, 0x0, 0x2c, 0xfa, 0x0, 0xa, 0xff, 0xdb,
    0xdf, 0xfb, 0x0, 0x0, 0x4, 0xbd, 0xff, 0xc6,
    0x0, 0x0,

    /* U+0045 "E" */
    0x6f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x6f, 0xdc,
    0xcc, 0xcc, 0xcc, 0xb0, 0x6f, 0x70, 0x0, 0x0,
    0x0, 0x0, 0x6f, 0x70, 0x0, 0x0, 0x0, 0x0,
    0x6f, 0x70, 0x0, 0x0, 0x0, 0x0, 0x6f, 0x70,
    0x0, 0x0, 0x0, 0x0, 0x6f, 0xdc, 0xcc, 0xcc,
    0xcc, 0x40, 0x6f, 0xff, 0xff, 0xff, 0xff, 0x60,
    0x6f, 0x70, 0x0, 0x0, 0x0, 0x0, 0x6f, 0x70,
    0x0, 0x0, 0x0, 0x0, 0x6f, 0x70, 0x0, 0x0,
    0x0, 0x0, 0x6f, 0x70, 0x0, 0x0, 0x0, 0x0,
    0x6f, 0x70, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xdc,
    0xcc, 0xcc, 0xcc, 0xc3, 0x6f, 0xff, 0xff, 0xff,
    0xff, 0xf4,

    /* U+004E "N" */
    0x7f, 0xc0, 0x0, 0x0, 0x0, 0xfc, 0x7f, 0xf6,
    0x0, 0x0, 0x0, 0xfc, 0x7f, 0xff, 0x10, 0x0,
    0x0, 0xfc, 0x7f, 0xcf, 0xb0, 0x0, 0x0, 0xfc,
    0x7f, 0x5d, 0xf5, 0x0, 0x0, 0xfc, 0x7f, 0x53,
    0xfe, 0x10, 0x0, 0xfc, 0x7f, 0x50, 0x9f, 0x90,
    0x0, 0xfc, 0x7f, 0x50, 0xe, 0xf4, 0x0, 0xfc,
    0x7f, 0x50, 0x4, 0xfd, 0x0, 0xfc, 0x7f, 0x50,
    0x0, 0xaf, 0x80, 0xfc, 0x7f, 0x50, 0x0, 0x1e,
    0xf3, 0xfc, 0x7f, 0x50, 0x0, 0x6, 0xfc, 0xfc,
    0x7f, 0x50, 0x0, 0x0, 0xbf, 0xfc, 0x7f, 0x50,
    0x0, 0x0, 0x2f, 0xfc, 0x7f, 0x50, 0x0, 0x0,
    0x7, 0xfc,

    /* U+004F "O" */
    0x0, 0x0, 0x29, 0xdf, 0xec, 0x60, 0x0, 0x0,
    0x0, 0x7f, 0xfe, 0xbc, 0xff, 0xd2, 0x0, 0x0,
    0x7f, 0xe4, 0x0, 0x1, 0x8f, 0xe1, 0x0, 0x2f,
    0xe1, 0x0, 0x0, 0x0, 0x8f, 0xb0, 0x8, 0xf7,
    0x0, 0x0, 0x0, 0x0, 0xef, 0x10, 0xcf, 0x20,
    0x0, 0x0, 0x0, 0x9, 0xf6, 0xf, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x6f, 0x80, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x5, 0xfa, 0xf, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x5f, 0x80, 0xcf, 0x20, 0x0, 0x0,
    0x0, 0x8, 0xf6, 0x8, 0xf7, 0x0, 0x0, 0x0,
    0x0, 0xdf, 0x20, 0x1f, 0xe2, 0x0, 0x0, 0x0,
    0x7f, 0xb0, 0x0, 0x6f, 0xe4, 0x0, 0x0, 0x8f,
    0xf2, 0x0, 0x0, 0x6f, 0xfd, 0xbb, 0xff, 0xd3,
    0x0, 0x0, 0x0, 0x29, 0xdf, 0xec, 0x60, 0x0,
    0x0,

    /* U+0053 "S" */
    0x0, 0x4, 0xbe, 0xfe, 0xb5, 0x0, 0x0, 0x8,
    0xff, 0xdc, 0xdf, 0xfa, 0x0, 0x3, 0xfd, 0x20,
    0x0, 0x2d, 0xf5, 0x0, 0x7f, 0x50, 0x0, 0x0,
    0x3f, 0xb0, 0x7, 0xf6, 0x0, 0x0, 0x0, 0x75,
    0x0, 0x2f, 0xf7, 0x10, 0x0, 0x0, 0x0, 0x0,
    0x6f, 0xff, 0xd9, 0x50, 0x0, 0x0, 0x0, 0x28,
    0xdf, 0xff, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x15,
    0xaf, 0xf9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2e,
    0xf1, 0xf, 0xc0, 0x0, 0x0, 0x0, 0x9f, 0x40,
    0xdf, 0x30, 0x0, 0x0, 0xb, 0xf2, 0x6, 0xfe,
    0x50, 0x0, 0x7, 0xfc, 0x0, 0x9, 0xff, 0xec,
    0xcf, 0xfe, 0x20, 0x0, 0x4, 0xad, 0xff, 0xd8,
    0x10, 0x0,

    /* U+0054 "T" */
    0x8f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x6c, 0xcc,
    0xcf, 0xfc, 0xcc, 0xc9, 0x0, 0x0, 0xd, 0xf1,
    0x0, 0x0, 0x0, 0x0, 0xd, 0xf1, 0x0, 0x0,
    0x0, 0x0, 0xd, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0xd, 0xf1, 0x0, 0x0, 0x0, 0x0, 0xd, 0xf1,
    0x0, 0x0, 0x0, 0x0, 0xd, 0xf1, 0x0, 0x0,
    0x0, 0x0, 0xd, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0xd, 0xf1, 0x0, 0x0, 0x0, 0x0, 0xd, 0xf1,
    0x0, 0x0, 0x0, 0x0, 0xd, 0xf1, 0x0, 0x0,
    0x0, 0x0, 0xd, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0xd, 0xf1, 0x0, 0x0, 0x0, 0x0, 0xd, 0xf1,
    0x0, 0x0,

    /* U+0056 "V" */
    0xbf, 0x40, 0x0, 0x0, 0x0, 0xe, 0xf0, 0x5f,
    0xa0, 0x0, 0x0, 0x0, 0x4f, 0xa0, 0xf, 0xf0,
    0x0, 0x0, 0x0, 0xaf, 0x40, 0x9, 0xf5, 0x0,
    0x0, 0x0, 0xfd, 0x0, 0x3, 0xfa, 0x0, 0x0,
    0x5, 0xf8, 0x0, 0x0, 0xdf, 0x0, 0x0, 0xb,
    0xf2, 0x0, 0x0, 0x8f, 0x50, 0x0, 0x1f, 0xc0,
    0x0, 0x0, 0x2f, 0xb0, 0x0, 0x6f, 0x60, 0x0,
    0x0, 0xc, 0xf1, 0x0, 0xcf, 0x0, 0x0, 0x0,
    0x6, 0xf6, 0x1, 0xfa, 0x0, 0x0, 0x0, 0x0,
    0xfb, 0x7, 0xf4, 0x0, 0x0, 0x0, 0x0, 0xaf,
    0x1c, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x4f, 0x7f,
    0x80, 0x0, 0x0, 0x0, 0x0, 0xe, 0xff, 0x20,
    0x0, 0x0, 0x0, 0x0, 0x8, 0xfc, 0x0, 0x0,
    0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 89, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 178, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 178, .box_w = 6, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 178, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 216, .adv_w = 178, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 299, .adv_w = 178, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 382, .adv_w = 178, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 465, .adv_w = 178, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 548, .adv_w = 178, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 631, .adv_w = 178, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 178, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 797, .adv_w = 213, .box_w = 15, .box_h = 15, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 910, .adv_w = 231, .box_w = 13, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1008, .adv_w = 213, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1098, .adv_w = 231, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1188, .adv_w = 249, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1301, .adv_w = 213, .box_w = 13, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1399, .adv_w = 195, .box_w = 12, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1489, .adv_w = 213, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
    0x9, 0xa, 0xb, 0x13, 0x15, 0x17, 0x20, 0x21,
    0x25, 0x26, 0x28
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 46, .range_length = 41, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 19, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    3, 3,
    12, 18,
    12, 19,
    18, 1,
    18, 12,
    18, 16,
    19, 1,
    19, 12
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -24, -24, -24, -35, -24, -6, -29, -24
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 8,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_Font20 = {
#else
lv_font_t ui_font_Font20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_FONT20*/

