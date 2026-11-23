// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

extern u8 gUiMenuDrawVtbl[128];
extern u8 lbl_80292808[160];
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
#pragma global_optimizer off
void fn_8014A25C(void)
{
  typedef struct Pair {
    u8 *lo;
    u8 *hi;
  } Pair;
  Pair *r34;
  Pair *r60;
  Pair *r44;
  u8 *p914;
  u8 *p990;
  u8 *p9DC;
  u8 *pA28;
  u8 *pA74;
  u8 *pAC0;
  u8 *pB0C;
  u8 *pB88;
  u8 *pBD4;
  u8 *pC6C;
  u8 *pCCC;
  u8 *pD2C;
  u8 *pD8C;
  u8 *pDEC;
  u8 *pE4C;
  u8 *pF0C;
  u8 *base88;
  u8 *base20;
  u8 *base0;
  u8 *base;
  u8 *new_var;

  base = lbl_80292808;
  r44 = (Pair *)lbl_80367B44;
  r60 = (Pair *)lbl_80367B60;
  pF0C = lbl_80292F0C;
  pBD4 = lbl_80292BD4;
  pB88 = lbl_80292B88;
  pB0C = lbl_80292B0C;
  pAC0 = lbl_80292AC0;
  new_var = lbl_80292990;
  pA74 = lbl_80292A74;
  pA28 = lbl_80292A28;
  p9DC = lbl_802929DC;
  p990 = lbl_80292990;
  pE4C = lbl_80292E4C;
  pDEC = lbl_80292DEC;
  pD8C = lbl_80292D8C;
  pDEC = lbl_80292D2C;
  pD2C = pDEC;
  pCCC = lbl_80292CCC;
  pC6C = lbl_80292C6C;
  base0 = base + 0;
  base20 = base + 0x20;
  r44->hi = gUiMenuDrawVtbl;
  base88 = base + 0x88;
  pAC0 = lbl_80292AC0;
  pA74 = lbl_80292A74;
  pA28 = lbl_80292A28;
  p9DC = lbl_802929DC;
  p990 = new_var;
  r34 = (Pair *)lbl_80367B34;
  pB0C = lbl_80292B0C;
  lbl_80367B28 = pD2C;
  ((Pair *)lbl_80367B60)->hi = gUiMenuDrawVtbl;
  p914 = lbl_80292914;
  lbl_80367B18 = pF0C;
  lbl_80367B1C = pE4C;
  lbl_80367B20 = pDEC;
  lbl_80367B24 = pD8C;
  lbl_80367B2C = pCCC;
  lbl_80367B30 = pC6C;
  r34->hi = gUiMenuDrawVtbl;
  ((Pair *)lbl_80367B34)->lo = base0;
  lbl_80367B3C = pBD4;
  lbl_80367B40 = pB88;
  ((Pair *)lbl_80367B44)->lo = base20;
  r44->hi = pB0C;
  lbl_80367B4C = pAC0;
  lbl_80367B50 = pA74;
  lbl_80367B54 = pA28;
  lbl_80367B58 = p9DC;
  lbl_80367B5C = p990;
  ((Pair *)lbl_80367B60)->lo = base88;
  r60->hi = p914;
}
__declspec(section ".ctors") static void (*const lbl_80267AF4)(void) = fn_8014A25C;

