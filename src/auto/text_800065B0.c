/* Functions from 0x80006264 to 0x80011968, found by decomp-toolkit. */
#include "common.h"
#include "process.h"

typedef struct {
    void *unk0;
    void *unk4;
    s32 unk8;
} Struct_8000B090;

extern s32 lbl_802AEE20[5]; // array of 5 pointers
extern f64 lbl_80368C28;    // global float constant
extern u16 jumptable_80283AE8[];

#pragma optimization_level 2
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma optimization_level reset

#pragma opt_unroll off

#pragma global_optimizer reset

#pragma global_optimizer on
#pragma opt_strength_reduction on

void fn_800065B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void fn_8020AEC4(u8 *);
    extern u8 lbl_80367131;
    extern u8 lbl_802A51C0[];
    extern u8 lbl_80367138[8];
    u8 *entry;
    u8 idx;

    idx = lbl_80367131;
    *(s32 *)(lbl_802A51C0 + (s8)idx * 0x10) = arg0;
    entry = lbl_802A51C0 + (s8)idx * 0x10;
    *(s32 *)(entry + 4) = arg1;
    *(s32 *)(entry + 8) = arg2;
    *(s32 *)(entry + 0xC) = arg3;
    lbl_80367131 = (idx + 1) & 0x1F;
    fn_8020AEC4(lbl_80367138);
}

void fn_80006608(s16 *arg0) {
    s16 x;
    s32 dy;
    s16 dx;

    x = arg0[0];
    dy = arg0[1];
    dx = -x;
    dy = -dy;
    arg0[0] = x + dx;
    arg0[1] = arg0[1] + (s16)dy;
    arg0[2] = arg0[2] + dx;
    arg0[3] = arg0[3] + (s16)dy;
}

s32 fn_80006650(s16 *arg0, s16 *arg1) {
    if (arg0[2] < arg1[0]) {
        return 0;
    }
    if (arg1[2] < arg0[0]) {
        return 0;
    }
    if (arg0[3] < arg1[1]) {
        return 0;
    }
    return arg1[3] >= arg0[1];
}

#pragma push
#pragma optimization_level 3
void fn_800066B4(s32 hi, u32 lo, s32 *hours, s32 *mins, s32 *secs) {
    unsigned long long __div2i(s32, u32, s32, u32);
    s32 *h, *s, *m;
    u32 total;

    h = hours;
    s = secs;
    m = mins;
    total = (u32)__div2i(hi, lo, 0, *(u32 *)0x800000F8 >> 2);
    *s = total % 60;
    *m = (total / 60) % 60;
    *h = total / 3600;
}
#pragma pop
