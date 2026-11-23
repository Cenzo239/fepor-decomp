// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

#pragma opt_strength_reduction off
void fn_80149F38(void) {
    extern u8 gFxChannels[];
    void fn_8014A008(void *, int);
    void fn_80149FE0(void *, int);
    void fn_80149FB8(void *, int);
    void fn_8022C260(void *, void (*)(void *, int), int, u32, u32);
    struct { u8 at0; } *p;
    p = (void *)gFxChannels;
    fn_8022C260(&p->at0, fn_8014A008, 0, 0x30, 4);
    fn_8022C260((u8 *)p + 0xC0, fn_80149FE0, 0, 0x30, 0xA);
    fn_8022C260((u8 *)p + 0x2A0, fn_80149FB8, 0, 0x30, 0x1C);
}
#pragma opt_strength_reduction on
