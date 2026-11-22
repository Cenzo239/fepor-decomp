// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

void fn_80127D80(void) {
extern void * lbl_8028459C[], *lbl_80285FF4[], *lbl_802860E4[], *lbl_802862E4[], *lbl_802863BC[], *lbl_80286610[], *lbl_80286664[], *lbl_802905E8[], *lbl_80290824[], *lbl_802908A4[], *lbl_802908F8[], *lbl_8029094C[], *lbl_802909A0[], *lbl_8032FE48[], *gUiMenuDrawVtbl[];
extern void *lbl_80367A70[2],*lbl_80367A78[2],*lbl_80367A80[2];
void **obj=lbl_8032FE48;
void *p0=lbl_8028459C,*p1=lbl_80286610,*p2=lbl_802862E4,*p3=lbl_80285FF4,*p4=lbl_802909A0;
void *p5=lbl_8029094C,*p6=lbl_802908F8,*p7=lbl_802908A4;
lbl_80367A70[0]=p0;
lbl_80367A78[0]=p0; lbl_80367A80[0]=p0;
lbl_80367A70[0]=p1;
lbl_80367A78[0]=p1;
obj[1]=gUiMenuDrawVtbl;
lbl_80367A80[0]=p1;
lbl_80367A70[0]=p2;
lbl_80367A78[0]=p2; lbl_80367A80[0]=p2;
obj[1]=lbl_80286664;
lbl_80367A70[0]=p3;
lbl_80367A78[0]=p3; lbl_80367A80[0]=p3;
obj[1]=lbl_802863BC;
lbl_80367A70[0]=p4;
lbl_80367A78[0]=p4; lbl_80367A80[0]=p4;
obj[1]=lbl_802860E4;
lbl_80367A70[0]=p5;lbl_80367A78[0]=p6;lbl_80367A80[0]=p7;
obj[0]=lbl_802905E8;
*(s16 *)((u8 *)obj+14)=0;
*(s16 *)((u8 *)obj+16)=0x46;
obj[1]=lbl_80290824;
}
