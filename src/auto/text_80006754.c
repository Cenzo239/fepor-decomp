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

#pragma opt_common_subs off
void fn_80006754(void) {
    extern u32 gFrameCount;
    extern u64 lbl_80367120;
    extern u64 lbl_80367128;
    extern u64 OSGetTime(void);
    u64 time;

    gFrameCount = gFrameCount + 1;
    lbl_80367120 = lbl_80367128;
    time = OSGetTime();
    lbl_80367128 = time;
}
#pragma opt_common_subs reset
