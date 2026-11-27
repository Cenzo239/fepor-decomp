// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

extern u8 gUiMenuDrawVtbl[128];
extern u8 lbl_80292914[124];
extern u8 lbl_80292990[76];
extern u8 lbl_802929DC[76];
extern u8 lbl_80292A28[76];
extern u8 lbl_80292A74[76];
extern u8 lbl_80292AC0[76];
extern u8 lbl_80292B0C[124];
extern u8 lbl_80292B88[76];
extern u8 lbl_80292BD4[152];
extern u8 lbl_80292C6C[96];
extern u8 lbl_80292CCC[96];
extern u8 lbl_80292D2C[96];
extern u8 lbl_80292D8C[96];
extern u8 lbl_80292DEC[96];
extern u8 lbl_80292E4C[192];
extern u8 lbl_80292F0C[84];
extern void *lbl_80367B18;
extern void *lbl_80367B1C;
extern void *lbl_80367B20;
extern void *lbl_80367B24;
extern void *lbl_80367B28;
extern void *lbl_80367B2C;
extern void *lbl_80367B30;
extern void *lbl_80367B34[2];
extern void *lbl_80367B3C;
extern void *lbl_80367B40;
extern void *lbl_80367B44[2];
extern void *lbl_80367B4C;
extern void *lbl_80367B50;
extern void *lbl_80367B54;
extern void *lbl_80367B58;
extern void *lbl_80367B5C;
extern void *lbl_80367B60[2];

#pragma use_lmw_stmw on
void **lbl_80292808[] = {
    &lbl_80367B18, &lbl_80367B1C, &lbl_80367B20, &lbl_80367B24,
    &lbl_80367B28, &lbl_80367B2C, &lbl_80367B30, NULL,
};

static void **secondItems[] = {
    &lbl_80367B40, &lbl_80367B40, &lbl_80367B40, &lbl_80367B40,
    &lbl_80367B40, &lbl_80367B40, &lbl_80367B40, &lbl_80367B40,
    &lbl_80367B40, &lbl_80367B40, &lbl_80367B40, &lbl_80367B40,
    &lbl_80367B40, &lbl_80367B40, &lbl_80367B40, &lbl_80367B40,
    &lbl_80367B40, &lbl_80367B40, &lbl_80367B40, &lbl_80367B40,
    &lbl_80367B40, &lbl_80367B40, &lbl_80367B40, &lbl_80367B40,
    &lbl_80367B3C, NULL,
};

static void **thirdItems[] = {
    &lbl_80367B4C, &lbl_80367B50, &lbl_80367B54, &lbl_80367B58,
    &lbl_80367B5C, NULL,
};

void fn_8014A25C(void)
{
    lbl_80367B18 = lbl_80292F0C;
    lbl_80367B1C = lbl_80292E4C;
    lbl_80367B20 = lbl_80292DEC;
    lbl_80367B24 = lbl_80292D8C;
    lbl_80367B28 = lbl_80292D2C;
    lbl_80367B2C = lbl_80292CCC;
    lbl_80367B30 = lbl_80292C6C;

    lbl_80367B34[1] = gUiMenuDrawVtbl;
    lbl_80367B34[0] = lbl_80292808;
    lbl_80367B3C = lbl_80292BD4;
    lbl_80367B40 = lbl_80292B88;

    lbl_80367B44[1] = gUiMenuDrawVtbl;
    lbl_80367B44[0] = secondItems;
    lbl_80367B44[1] = lbl_80292B0C;
    lbl_80367B4C = lbl_80292AC0;
    lbl_80367B50 = lbl_80292A74;
    lbl_80367B54 = lbl_80292A28;
    lbl_80367B58 = lbl_802929DC;
    lbl_80367B5C = lbl_80292990;

    lbl_80367B60[1] = gUiMenuDrawVtbl;
    lbl_80367B60[0] = thirdItems;
    lbl_80367B60[1] = lbl_80292914;
}
__declspec(section ".ctors") static void (*const lbl_80267AF4)(void) = fn_8014A25C;

