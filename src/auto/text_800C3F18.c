// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

#pragma global_optimizer off
void fn_800C3F18(void) {
    void fn_8022C260(void *, void *, void *, s32, s32);
    void __register_global_object(void *, void (*)(void), void *);
    void *Item_Init(void *);
    void *Item_Destroy(void *, s16);
    void fn_800C412C(void);
    void fn_800C40F4(u8 *);
    extern u8 lbl_803200A0[];
    void *init;
    void *dtor;
    u8 *base;
    u8 *p;
    s32 i;

    /* assign destroy before init to control argument register order */
    dtor = Item_Destroy;
    init = Item_Init;
    base = lbl_803200A0;
    fn_8022C260(base + 0xC, init, dtor, 8, 0xC8);
    __register_global_object(base + 0xC, fn_800C412C, base + 0);
    fn_8022C260(base + 0x64C, fn_800C40F4, NULL, 0x18, 0x30);

    p = base + 0x64C;
    for (i = 6; i != 0; i--) {
        p[0] = 0;
        p[1] = 0;
        p[0x13] = 0;
        p[0x12] = 0;
        p[0x11] = 0;
        p[0x10] = 0;
        p[0x16] = 0x80;
        p[0x15] = 0x80;
        p[0x14] = 0x80;
        p[0x17] = 0xFF;
        p[0x18] = 0;
        p[0x19] = 0;
        p[0x2B] = 0;
        p[0x2A] = 0;
        p[0x29] = 0;
        p[0x28] = 0;
        p[0x2E] = 0x80;
        p[0x2D] = 0x80;
        p[0x2C] = 0x80;
        p[0x2F] = 0xFF;
        p[0x30] = 0;
        p[0x31] = 0;
        p[0x43] = 0;
        p[0x42] = 0;
        p[0x41] = 0;
        p[0x40] = 0;
        p[0x46] = 0x80;
        p[0x45] = 0x80;
        p[0x44] = 0x80;
        p[0x47] = 0xFF;
        p[0x48] = 0;
        p[0x49] = 0;
        p[0x5B] = 0;
        p[0x5A] = 0;
        p[0x59] = 0;
        p[0x58] = 0;
        p[0x5E] = 0x80;
        p[0x5D] = 0x80;
        p[0x5C] = 0x80;
        p[0x5F] = 0xFF;
        p[0x60] = 0;
        p[0x61] = 0;
        p[0x73] = 0;
        p[0x72] = 0;
        p[0x71] = 0;
        p[0x70] = 0;
        p[0x76] = 0x80;
        p[0x75] = 0x80;
        p[0x74] = 0x80;
        p[0x77] = 0xFF;
        p[0x78] = 0;
        p[0x79] = 0;
        p[0x8B] = 0;
        p[0x8A] = 0;
        p[0x89] = 0;
        p[0x88] = 0;
        p[0x8E] = 0x80;
        p[0x8D] = 0x80;
        p[0x8C] = 0x80;
        p[0x8F] = 0xFF;
        p[0x90] = 0;
        p[0x91] = 0;
        p[0xA3] = 0;
        p[0xA2] = 0;
        p[0xA1] = 0;
        p[0xA0] = 0;
        p[0xA6] = 0x80;
        p[0xA5] = 0x80;
        p[0xA4] = 0x80;
        p[0xA7] = 0xFF;
        p[0xA8] = 0;
        p[0xA9] = 0;
        p[0xBB] = 0;
        p[0xBA] = 0;
        p[0xB9] = 0;
        p[0xB8] = 0;
        p[0xBE] = 0x80;
        p[0xBD] = 0x80;
        p[0xBC] = 0x80;
        p[0xBF] = 0xFF;
        p += 0xC0;
    }
}
#pragma global_optimizer reset
