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

#pragma global_optimizer off
s32 fn_80006AC0(u8 *arg0) {
 u32 result; u32 high; u32 mid; u32 low;
 if(arg0[0]!=0x10) return 0;
 mid=arg0[2]; high=arg0[3]; low=arg0[1];
 result=low+((mid<<8)&0xff00);
 return result+((high<<16)&0xff0000);
}
