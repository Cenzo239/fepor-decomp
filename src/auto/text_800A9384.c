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
    void **a = (void**)&lbl_80312AB0;
    void **c;

    a[1] = gUiMenuDrawVtbl;
    lbl_803677C8 = lbl_8028459C;
    a[1] = lbl_80286664;
    lbl_803677C8 = lbl_8028CDA4;
    c = (void**)&lbl_803677EC;
    c[1] = gUiMenuDrawVtbl;
    a[1] = lbl_802863BC;
    lbl_803677C8 = lbl_8028CD58;
    lbl_803677D0 = lbl_8028CD0C;
    lbl_803677D4 = lbl_8028CCC0;
    lbl_803677D8 = lbl_8028CC74;
    lbl_803677DC = lbl_8028CC28;
    lbl_803677E0 = lbl_8028CBDC;
    lbl_803677E4 = lbl_8028CB90;
    lbl_803677E8 = lbl_8028CB44;
    c[0] = lbl_8028C850;
    c[1] = lbl_8028CAC8;
    lbl_803677F4 = lbl_8028CA74;
    lbl_803677F8 = lbl_8028CA20;
    a[0] = &lbl_80366E30;
    a[1] = lbl_8028C9A0;
}
#pragma use_lmw_stmw reset
