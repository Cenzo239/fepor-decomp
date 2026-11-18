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

#pragma optimization_level reset

#pragma opt_unroll off

#pragma global_optimizer reset

#pragma global_optimizer on
#pragma opt_strength_reduction on

#pragma optimization_level 4
#pragma scheduling on

#pragma scheduling reset
#pragma optimization_level reset

s64 fn_80006798(void) {
    extern u32 lbl_80367120;
    extern u32 lbl_80367124;
    extern u32 lbl_80367128;
    extern u32 lbl_8036712C;
    s64 prev;
    s64 cur;

    cur = lbl_8036712C;
    prev = lbl_80367124;
    cur |= (s64)lbl_80367128 << 32;
    prev |= (s64)lbl_80367120 << 32;
    return cur - prev;
}

s32 Game_GetFrameCount(void) {
    extern s32 gFrameCount;
    return gFrameCount;
}

void Math_Ease(s32 arg0, void *arg1) {
    s32 temp_r3;
    s32 i;
    s32 r4;

    if (arg0 < 2) {
        for (i = 0; i < 0x40; i++) {
            *(u8 *)((char *)arg1 + i) = 0;
        }
        
        temp_r3 = *(s32 *)arg1;
        if (temp_r3 == 0) {
            *(u32 *)((char *)arg1 + 0x8) = 0;
        }
        else {
            r4 = *(s32 *)((char *)arg1 + 0x4);
            *(u32 *)arg1 = temp_r3 + 1;
            *(u32 *)((char *)arg1 + 0x8) = r4;
            *(u32*)((char*)arg1 + 0xC) = *(u32*)((char*)arg1 + 0x10);
        }
    }
}

#pragma optimization_level 3
