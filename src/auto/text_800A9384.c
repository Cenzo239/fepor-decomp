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
void fn_800A9384(void) {
    void *v_cb44;
    void *v_cb90;
    void *v_cbdc;
    void *v_cda4;
    void *pad26;
    void *pad27;
    void *pad28;
    void *pad29;
    void *vtbl;
    void **a;
    void *pad31;
    void **c;

    vtbl = gUiMenuDrawVtbl;
    a = lbl_80312AB0;
    c = (void **)&lbl_803677EC;
    v_cda4 = lbl_8028CDA4;
    v_cbdc = lbl_8028CBDC;
    v_cb90 = lbl_8028CB90;
    v_cb44 = lbl_8028CB44;
    pad26 = lbl_8028C850;
    pad27 = lbl_8028CAC8;
    pad28 = lbl_8028CA74;
    pad29 = lbl_8028CA20;
    pad31 = &lbl_80366E30;

    a[1] = vtbl;
    lbl_803677C8 = lbl_8028459C;
    a[1] = lbl_80286664;
    lbl_803677C8 = v_cda4;
    c[1] = vtbl;
    a[1] = lbl_802863BC;
    lbl_803677C8 = lbl_8028CD58;
    lbl_803677D0 = lbl_8028CD0C;
    lbl_803677D4 = lbl_8028CCC0;
    lbl_803677D8 = lbl_8028CC74;
    lbl_803677DC = lbl_8028CC28;
    lbl_803677E0 = v_cbdc;
    lbl_803677E4 = v_cb90;
    lbl_803677E8 = v_cb44;
    c[0] = pad26;
    c[1] = pad27;
    lbl_803677F4 = pad28;
    lbl_803677F8 = pad29;
    a[0] = pad31;
    a[1] = lbl_8028C9A0;
}
#pragma use_lmw_stmw reset
