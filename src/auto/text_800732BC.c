// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

extern u8 gUiMenuDrawVtbl[128];
extern u8 lbl_80286590[128];
extern u8 lbl_80286664[128];
extern u8 lbl_80286F40[128];
extern u8 lbl_80286F58[128];
extern u8 lbl_80286F70[128];
extern u8 lbl_80286FC4[84];
extern u8 lbl_80287018[84];
extern u8 lbl_8028706C[84];
extern u8 lbl_802870C0[84];
extern u8 lbl_80287114[84];
extern u8 lbl_80287168[84];
extern u8 lbl_802871BC[84];
extern u8 lbl_80366DF0;
extern void *lbl_80367360;
extern void *lbl_80367364;
extern void *lbl_80367368;
extern void *lbl_8036736C;
extern void *lbl_80367370;
extern void *lbl_80367374;
extern void *lbl_80367378;
extern void *lbl_8036737C[2];
extern void *lbl_80367384;
extern void *lbl_80367388[2];
extern void *lbl_80367390[2];

#pragma no_register_save_helpers on
#pragma use_lmw_stmw on
void fn_800732BC(void) {
    void **a;
    void **b;
    void **c;

    a = lbl_8036737C;
    b = lbl_80367388;
    c = lbl_80367390;

    a[1] = gUiMenuDrawVtbl;
    b[1] = gUiMenuDrawVtbl;
    c[1] = gUiMenuDrawVtbl;

    a[1] = lbl_80286664;
    b[1] = lbl_80286664;

    lbl_80367360 = lbl_802871BC;
    lbl_80367364 = lbl_80287168;
    lbl_80367368 = lbl_80287114;
    lbl_8036736C = lbl_802870C0;
    lbl_80367370 = lbl_8028706C;
    lbl_80367374 = lbl_80287018;
    lbl_80367378 = lbl_80286FC4;

    lbl_8036737C[0] = lbl_80286F40;
    a[1] = lbl_80286590;

    lbl_80367384 = lbl_80286F70;

    lbl_80367388[0] = &lbl_80366DF0;
    b[1] = lbl_80286590;

    lbl_80367390[0] = lbl_80286F58;
    c[1] = lbl_80286664;
}
#pragma use_lmw_stmw reset
#pragma no_register_save_helpers reset
