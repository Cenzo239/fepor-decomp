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

void fn_80006754(void)
{
    extern u32 lbl_80367120;
    extern u32 lbl_80367124;
    extern u32 lbl_80367128;
    extern u32 lbl_8036712C;
    extern u32 gFrameCount;
    extern u64 OSGetTime(void);

    u32 high = lbl_80367128;
    u32 low = lbl_8036712C;
    u32 count = gFrameCount;
    u64 time;

    gFrameCount = count + 1;
    lbl_80367124 = low;
    lbl_80367120 = high;

    time = OSGetTime();
    lbl_8036712C = (u32)time;
    lbl_80367128 = (u32)(time >> 32);
}
#pragma scheduling reset
#pragma optimization_level reset
