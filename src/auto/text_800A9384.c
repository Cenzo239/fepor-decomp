// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"
#include "common.h"

extern u8 lbl_8028CD0C[76];
extern u8 gUiMenuDrawVtbl[128];
extern void *lbl_80312AB0[4];
extern u8 lbl_8028459C[76];
extern u8 lbl_80286664[128];
extern u8 lbl_8028CDA4[76];
extern u8 lbl_8028CCC0[76];
extern u8 lbl_8028CC74[76];
extern u8 lbl_8028CC28[76];
extern u8 lbl_8028CBDC[76];
extern u8 lbl_8028CB90[76];
extern u8 lbl_8028CB44[76];
extern u8 lbl_8028C850[76];
extern u8 lbl_8028CA74[76];
extern u8 lbl_8028CA20[76];
extern u8 lbl_8028CAC8[76];
extern u8 lbl_8028C9A0[76];
extern u8 lbl_8028CD58[76];
extern u8 lbl_802863BC[76];

extern void *lbl_803677C8;
extern void *lbl_803677D0;
extern void *lbl_803677D4;
extern void *lbl_803677D8;
extern void *lbl_803677DC;
extern void *lbl_803677E0;
extern void *lbl_803677E4;
extern void *lbl_803677E8;
extern void *lbl_803677EC[2];
extern void *lbl_803677F4;
extern void *lbl_803677F8;
extern u8 lbl_80366E30;
#pragma use_lmw_stmw on
#pragma push
#pragma opt_common_subs off
void fn_800A9384(void) {
    void *cd0c;
    void *vtbl;
    void **a;
    void *d8459c;
    void *d86664;
    void *cda4;
    void **c;
    void *ccc0;
    void *cc74;
    void *cc28;
    void *cbdc;
    void *cb90;
    void *cb44;
    void *c850;
    void *ca74;
    void *ca20;
    void *pad31;
    void *c863bc;
    void *cac8;
    void *cd58;
    void *c9a0;

    cd0c = lbl_8028CD0C;
    vtbl = gUiMenuDrawVtbl;
    a = lbl_80312AB0;
    d8459c = lbl_8028459C;
    d86664 = lbl_80286664;
    cda4 = lbl_8028CDA4;
    c = (void **)&lbl_803677EC;
    ccc0 = lbl_8028CCC0;
    cc74 = lbl_8028CC74;
    cc28 = lbl_8028CC28;
    cbdc = lbl_8028CBDC;
    cb90 = lbl_8028CB90;
    cb44 = lbl_8028CB44;
    c850 = lbl_8028C850;
    ca74 = lbl_8028CA74;
    ca20 = lbl_8028CA20;
    pad31 = &lbl_80366E30;
    c863bc = lbl_802863BC;
    cac8 = lbl_8028CAC8;
    cd58 = lbl_8028CD58;
    c9a0 = lbl_8028C9A0;

    a[1] = vtbl;
    lbl_803677C8 = d8459c;
    a[1] = d86664;
    lbl_803677C8 = cda4;
    c[1] = vtbl;
    a[1] = c863bc;
    lbl_803677C8 = cd58;
    lbl_803677D0 = cd0c;
    lbl_803677D4 = ccc0;
    lbl_803677D8 = cc74;
    lbl_803677DC = cc28;
    lbl_803677E0 = cbdc;
    lbl_803677E4 = cb90;
    lbl_803677E8 = cb44;
    c[0] = c850;
    c[1] = cac8;
    lbl_803677F4 = ca74;
    lbl_803677F8 = ca20;
    a[0] = pad31;
    a[1] = c9a0;
}
#pragma pop
#pragma use_lmw_stmw reset
