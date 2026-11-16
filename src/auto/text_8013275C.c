// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

void fn_8013275C(void) {
    extern u8 gUiMenuDrawVtbl[128];
    extern u8 lbl_802916E0[80];
    extern u8 lbl_80291694[76];
    extern u8 lbl_80291648[76];
    extern u8 lbl_802915FC[76];
    extern u8 lbl_802915B0[76];
    extern u8 lbl_80291564[76];
    extern u8 lbl_80291518[76];
    extern u8 lbl_80291428[32];
    extern u8 lbl_80291448[84];
    extern u8 lbl_8029149C[124];
    extern void *lbl_80367AA8;
    extern void *lbl_80367AAC;
    extern void *lbl_80367AB0;
    extern void *lbl_80367AB4;
    extern void *lbl_80367AB8;
    extern void *lbl_80367ABC;
    extern void *lbl_80367AC0;
    extern void *lbl_80367AC4[2];
    extern void *lbl_80367ACC;
    void **p = lbl_80367AC4;
    void *v0;
    void *v1;
    void *v2;
    void *v3;
    void *v4;
    void *v5;
    void *v6;
    void *v7;
    void *v8;
    p[1] = gUiMenuDrawVtbl;
    v0 = lbl_802916E0;
    v1 = lbl_80291694;
    v2 = lbl_80291648;
    v3 = lbl_802915FC;
    v4 = lbl_802915B0;
    v5 = lbl_80291564;
    v6 = lbl_80291518;
    v7 = lbl_80291428;
    v8 = lbl_80291448;
    lbl_80367AA8 = v0;
    lbl_80367AAC = v1;
    lbl_80367AB0 = v2;
    lbl_80367AB4 = v3;
    lbl_80367AB8 = v4;
    lbl_80367ABC = v5;
    lbl_80367AC0 = v6;
    lbl_80367AC4[0] = v7;
    p[1] = lbl_8029149C;
    lbl_80367ACC = v8;
}
