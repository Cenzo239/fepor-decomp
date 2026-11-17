// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

#pragma optimization_level 3
void fn_80149F38(void) {
    extern u8 gFxChannels[];
    void fn_8014A008(void);
    void fn_80149FE0(void);
    void fn_80149FB8(void);
    void fn_8022C260(void *, void *, s32, s32, s32);
    u32 base = (u32)gFxChannels;
    fn_8022C260((void *)(base + 0), (void *)fn_8014A008, 0, 0x30, 4);
    fn_8022C260((void *)(base + 0xC0), (void *)fn_80149FE0, 0, 0x30, 0xA);
    fn_8022C260((void *)(base + 0x2A0), (void *)fn_80149FB8, 0, 0x30, 0x1C);
}
#pragma optimization_level reset
