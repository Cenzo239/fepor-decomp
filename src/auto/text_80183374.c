// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

void fn_80183374(void) {
    extern u8 lbl_802845E8[128];
    extern u8 lbl_80286664[128];
    extern u8 lbl_802959A8[88];
    extern u8 lbl_80295950[88];
    extern u8 lbl_802958F8[88];
    extern u8 lbl_802958A0[88];
    extern u8 lbl_80295848[88];
    extern u8 lbl_80295770[24];
    extern u8 lbl_802957C8[128];
    extern void *lbl_803681F4;
    extern void *lbl_803681F8;
    extern void *lbl_803681FC;
    extern void *lbl_80368200;
    extern void *lbl_80368204;
    extern void *lbl_80368208[2];
    void **dst = lbl_80368208;
    void *p86664;
    void *p9A8;
    void *p950;
    void *p8F8;
    void *p8A0;
    void *p848;
    void *p770;
    void *p7C8;

    dst[1] = lbl_802845E8;
    p86664 = lbl_80286664;
    p9A8 = lbl_802959A8;
    p950 = lbl_80295950;
    p8F8 = lbl_802958F8;
    p8A0 = lbl_802958A0;
    p848 = lbl_80295848;
    p770 = lbl_80295770;
    dst[1] = p86664;
    p7C8 = lbl_802957C8;
    lbl_803681F4 = p9A8;
    lbl_803681F8 = p950;
    lbl_803681FC = p8F8;
    lbl_80368200 = p8A0;
    lbl_80368204 = p848;
    dst[0] = p770;
    dst[1] = p7C8;
}

__declspec(section ".ctors") static void (*const lbl_80267B00)(void) = fn_80183374;

