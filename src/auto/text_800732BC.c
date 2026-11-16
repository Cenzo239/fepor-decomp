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

#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_800732BC(void) {
void *pBC; void *p68; void **a; void **b; void **c; void *vtbl; void *base; void *entry; void *e114; void *eC0; void *e6C; void *e18; void *eC4;
pBC=lbl_802871BC; p68=lbl_80287168;
a=lbl_8036737C; b=lbl_80367388; c=lbl_80367390;
e114=lbl_80287114; eC0=lbl_802870C0; e6C=lbl_8028706C; e18=lbl_80287018; eC4=lbl_80286FC4; entry=lbl_80286F40;
vtbl=gUiMenuDrawVtbl; a[1]=vtbl; b[1]=vtbl; c[1]=vtbl;
base=lbl_80286664; a[1]=base; b[1]=base;
lbl_80367360=pBC; lbl_80367364=p68; lbl_80367368=e114;
lbl_8036736C=eC0; lbl_80367370=e6C; lbl_80367374=e18; lbl_80367378=eC4;
lbl_8036737C[0]=entry; a[1]=lbl_80286590;
lbl_80367384=lbl_80286F70; lbl_80367388[0]=&lbl_80366DF0; b[1]=lbl_80286590;
lbl_80367390[0]=lbl_80286F58; c[1]=base;
}
#pragma global_optimizer on
__declspec(section ".ctors") static void (*const lbl_80267AB0)(void) = fn_800732BC;
