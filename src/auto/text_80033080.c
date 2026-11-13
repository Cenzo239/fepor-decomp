// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"
#include "common.h"
extern u8 lbl_80285050[];
extern u8 lbl_802EFCB8[];
extern u8 lbl_80285424[];
extern u8 lbl_80285458[];
extern u8 lbl_80367278;
void Item_Destroy(void);

#pragma global_optimizer off
#pragma opt_strength_reduction off
void fn_80033080(void) {
    void *fn_8001C76C(void *);
    void __register_global_object(void *, void (*)(void), void *);
    u8 *base;
    void **slot0;
    void **slot1;
    void *vt;

    base = lbl_802EFCB8;
    slot0 = (void **)(base + 4);
    slot1 = (void **)(base + 0x10);
    vt = lbl_80285050;
    *slot1 = vt;
    *slot0 = vt;
    vt = lbl_80285458;
    *slot1 = vt;
    *slot0 = vt;
    *slot1 = lbl_80285424;
    __register_global_object(fn_8001C76C(&lbl_80367278), Item_Destroy, base + 0xdc);
}
#pragma opt_strength_reduction reset
#pragma global_optimizer reset
