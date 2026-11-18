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

#pragma optimization_level 3

s32 fn_80006AC0(u8 *arg0) {
    u32 t;
    u32 b1;

    if (arg0[0] != 0x10) {
        return 0;
    }
    t = arg0[2];
    b1 = arg0[3];
    t = ((t << 8) & 0xFF00) + arg0[1];
    return t + ((b1 << 16) & 0xFF0000);
}
#pragma optimization_level reset
