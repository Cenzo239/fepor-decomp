// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

#pragma global_optimizer off
void fn_80127D80(void) {
extern void * lbl_8028459C[], *lbl_80285FF4[], *lbl_802860E4[], *lbl_802862E4[], *lbl_802863BC[], *lbl_80286610[], *lbl_80286664[], *lbl_802905E8[], *lbl_80290824[], *lbl_802908A4[], *lbl_802908F8[], *lbl_8029094C[], *lbl_802909A0[], *lbl_8032FE48[], *gUiMenuDrawVtbl[];
extern void *lbl_80367A70[2],*lbl_80367A78[2],*lbl_80367A80[2];
typedef struct { void *f0; void *f1; u8 pad[6]; s16 a; s16 b; } Obj;
void *p0=lbl_8028459C,*p1=lbl_80286610,*p2=lbl_802862E4,*p3=lbl_80285FF4,*p4=lbl_802909A0,*p5=lbl_8029094C;
Obj *obj=(Obj *)lbl_8032FE48;
lbl_80367A70[0]=p0;
lbl_80367A78[0]=p0; lbl_80367A80[0]=p0;
lbl_80367A70[0]=p1;
obj->f1=gUiMenuDrawVtbl;
lbl_80367A78[0]=p1; lbl_80367A80[0]=p1;
lbl_80367A70[0]=p2;
lbl_80367A78[0]=p2; lbl_80367A80[0]=p2;
obj->f1=lbl_80286664;
lbl_80367A70[0]=p3;
lbl_80367A78[0]=p3; lbl_80367A80[0]=p3;
obj->f1=lbl_802863BC;
lbl_80367A70[0]=p4;
lbl_80367A78[0]=p4; lbl_80367A80[0]=p4;
obj->f1=lbl_802860E4;
lbl_80367A70[0]=p5;lbl_80367A78[0]=lbl_802908F8;lbl_80367A80[0]=lbl_802908A4;
obj->f0=lbl_802905E8;
obj->a=0;
obj->b=0x46;
obj->f1=lbl_80290824;
}
#pragma global_optimizer on
