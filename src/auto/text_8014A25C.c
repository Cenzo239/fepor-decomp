// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

extern u8 gUiMenuDrawVtbl[128];
extern u8 lbl_80292808[];
extern u8 lbl_80292914[];
extern u8 lbl_80292990[];
extern u8 lbl_802929DC[];
extern u8 lbl_80292A28[];
extern u8 lbl_80292A74[];
extern u8 lbl_80292AC0[];
extern u8 lbl_80292B0C[];
extern u8 lbl_80292B88[];
extern u8 lbl_80292BD4[];
extern u8 lbl_80292C6C[];
extern u8 lbl_80292CCC[];
extern u8 lbl_80292D2C[];
extern u8 lbl_80292D8C[];
extern u8 lbl_80292DEC[];
extern u8 lbl_80292E4C[];
extern u8 lbl_80292F0C[];
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
#pragma global_optimizer off
void fn_8014A25C(void) {
void *pF0C; void *pE4C; void *pDEC; void *pD8C; void *pD2C; void *pCCC; void *pC6C;
void *pBD4; void *pB88; void *pB0C; void *pAC0; void *pA74; void *pA28; void *p9DC; void *p990; void *p914;
void *vtbl; void *base; void *base0; void *base20; void *base88;
void **a; void **b; void **c;
base = lbl_80292808;
a = lbl_80367B44; b = lbl_80367B60;
pF0C = lbl_80292F0C; pBD4 = lbl_80292BD4; pB88 = lbl_80292B88; pB0C = lbl_80292B0C;
pAC0 = lbl_80292AC0; pA74 = lbl_80292A74; pA28 = lbl_80292A28; p9DC = lbl_802929DC; p990 = lbl_80292990;
pE4C = lbl_80292E4C; pDEC = lbl_80292DEC; pD8C = lbl_80292D8C; pD2C = lbl_80292D2C; pCCC = lbl_80292CCC; pC6C = lbl_80292C6C;
vtbl = gUiMenuDrawVtbl; a[1] = vtbl;
base0 = (u8 *)base + 0; base20 = (u8 *)base + 0x20; base88 = (u8 *)base + 0x88;
c = lbl_80367B34;
b[1] = vtbl;
p914 = lbl_80292914;
lbl_80367B18 = pF0C; lbl_80367B1C = pE4C; lbl_80367B20 = pDEC; lbl_80367B24 = pD8C;
lbl_80367B28 = pD2C; lbl_80367B2C = pCCC; lbl_80367B30 = pC6C;
c[1] = vtbl; c[0] = base0;
lbl_80367B3C = pBD4; lbl_80367B40 = pB88;
a[0] = base20; a[1] = pB0C;
lbl_80367B4C = pAC0; lbl_80367B50 = pA74; lbl_80367B54 = pA28; lbl_80367B58 = p9DC; lbl_80367B5C = p990;
b[0] = base88; b[1] = p914;
}
#pragma global_optimizer on
__declspec(section ".ctors") static void (*const lbl_80267AF4)(void) = fn_8014A25C;

