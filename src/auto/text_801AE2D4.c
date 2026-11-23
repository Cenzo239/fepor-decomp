// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

#pragma use_lmw_stmw on
void fn_801AE2D4(void) {
    extern u32 lbl_80331C38[10];
    u32 *dst;
    struct { u8 r, g, b, a; } c0, c1, c2, c3, c4, c5, c6, c7, c8;

    dst = lbl_80331C38;

    c0.r = 0x80;
    c0.g = 0x80;
    c0.b = 0x80;
    c0.a = 0xFF;
    dst[0] = *(u32 *)&c0;

    c1.r = 0x60;
    c1.g = 0x60;
    c1.b = 0x60;
    c1.a = 0xFF;
    dst[1] = *(u32 *)&c1;

    c2.r = 0xAA;
    c2.g = 0xAA;
    c2.b = 0xAA;
    c2.a = 0xFF;
    dst[2] = *(u32 *)&c2;

    c3.r = 0xB4;
    c3.g = 0x96;
    c3.b = 0x5A;
    c3.a = 0xFF;
    dst[3] = *(u32 *)&c3;

    c4.r = 0x6E;
    c4.g = 0xA0;
    c4.b = 0x5A;
    c4.a = 0xFF;
    dst[4] = *(u32 *)&c4;

    c5.r = 0x6E;
    c5.g = 0x8C;
    c5.b = 0xB4;
    c5.a = 0xFF;
    dst[5] = *(u32 *)&c5;

    c6.r = 0x96;
    c6.g = 0x5A;
    c6.b = 0xA0;
    c6.a = 0xFF;
    dst[6] = *(u32 *)&c6;

    c7.r = 0xAA;
    c7.g = 0x5A;
    c7.b = 0x50;
    c7.a = 0xFF;
    dst[7] = *(u32 *)&c7;

    c8.r = 0xD2;
    c8.g = 0x6E;
    c8.b = 0x96;
    c8.a = 0xFF;
    dst[8] = *(u32 *)&c8;
}
#pragma use_lmw_stmw reset
