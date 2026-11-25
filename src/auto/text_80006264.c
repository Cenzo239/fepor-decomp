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

asm s32 fn_80006264(u32 *a, u32 *b, u32 n) {
    nofralloc
    subi r3, r3, 4
    srwi r5, r5, 2
    subi r4, r4, 4
    mtctr r5
@loop:
    lwzu r11, 4(r3)
    lwzu r12, 4(r4)
    cmplw r11, r12
    bne @diff
    bdnz @loop
    li r3, 0
    blr
@diff:
    li r3, 1
    blr
}
asm void fn_80006298(u32 *dst, u32 val, u32 n) {
    nofralloc
    srwi r5, r5, 2
    subi r3, r3, 4
    mtctr r5
@loop:
    stwu r4, 4(r3)
    bdnz @loop
    blr
}
#pragma opt_unroll off
asm void fn_800062B0(u32 *dst, u32 val, u32 n) {
    nofralloc
    srwi r5, r5, 3
    subi r3, r3, 4
    mtctr r5
@loop:
    stwu r4, 4(r3)
    stwu r4, 4(r3)
    bdnz @loop
    blr
}
asm void fn_800062CC(u32 *dst, u32 *src, u32 n) {
    nofralloc
    subi r3, r3, 4
    srwi r5, r5, 2
    subi r4, r4, 4
    mtctr r5
@loop:
    lwzu r11, 4(r4)
    stwu r11, 4(r3)
    bdnz @loop
    blr
}
#pragma global_optimizer reset
asm void fn_800062EC(u32 *dst, u32 *src, u32 n) {
    nofralloc
    subi r3, r3, 4
    srwi r5, r5, 3
    subi r4, r4, 4
    mtctr r5
@loop:
    lwzu r11, 4(r4)
    stwu r11, 4(r3)
    lwzu r12, 4(r4)
    stwu r12, 4(r3)
    bdnz @loop
    blr
}
#pragma global_optimizer on
#pragma opt_strength_reduction on
