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

void fn_80006314(void) {
    void OSInitThreadQueue(void *);
    s32 fn_80209FD4(void);
    void fn_8020A558(void *, void (*)(void), s32, void *, s32, s32, s32);
    void fn_8020A9E0(void *);
    void fn_80006388(void);
    extern u8 lbl_802A53C0[];
    extern u8 lbl_802A56D8[];
    extern s8 lbl_80367130;
    extern s8 lbl_80367131;
    extern s32 lbl_80367134;
    extern u8 lbl_80367138;

    lbl_80367131 = 0;
    lbl_80367130 = 0;
    OSInitThreadQueue(&lbl_80367138);
    lbl_80367134 = fn_80209FD4();
    fn_8020A558(lbl_802A53C0, fn_80006388, 0, lbl_802A56D8 + 0x1000, 0x1000, 0x10, 1);
    fn_8020A9E0(lbl_802A53C0);
}
