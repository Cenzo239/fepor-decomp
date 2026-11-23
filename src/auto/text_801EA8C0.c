// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"
#include "common.h"

extern u16 gTabMenuHeaderRect;
extern u16 lbl_80368304;
extern u16 lbl_8036831C;
extern u16 gTabMenuTabRect;
extern u16 lbl_80368314;
extern u16 lbl_80368324;
extern u16 lbl_8036832C;
extern u16 lbl_80368334;
extern u16 lbl_8036833C;
extern u16 lbl_80368344;
extern u16 lbl_8036834C;
extern u16 lbl_80368354;
extern u8 lbl_80332020[];
void fn_801EAA2C(void *, int);
void fn_8022C260(void *, void (*)(void *, int), void (*)(void *, int), u32, u32);

void fn_801EA8C0(void) {
 void fn_8022C260(void *,void *,void *,u32,u32,u32,void *,void *);
 u32 z=0;
 u32 w0=0xd8,h0=0x30;
 u32 ph=(u32)&gTabMenuHeaderRect;
 u32 p1=(u32)&lbl_80368304; u32 w1=0x220,h1=0x1a;
 u32 p2=(u32)&gTabMenuTabRect; u32 w2=0x64,h2=0x22;
 u32 p3=(u32)&lbl_80368314; u32 w3=0x60,h3=0x20;
 u32 p4=(u32)&lbl_8036831C; u32 w4=0x220,h4=0x20;
 u32 p5=(u32)&lbl_80368324; u32 w5=2,h5=8;
 u32 p6=(u32)&lbl_8036832C;
 u32 p7=(u32)&lbl_80368334;
 u32 p8=(u32)&lbl_8036833C; u32 w8=0x38,h8=0x18;
 u32 p9=(u32)&lbl_80368344; u32 w9=0x10;
 u32 p10=(u32)&lbl_8036834C; u32 w10=8;
 u32 p11=(u32)&lbl_80368354; u32 w11=0x10;
 ((s16*)ph)[2]=w0; ((s16*)ph)[1]=z; ((s16*)ph)[3]=h0; gTabMenuHeaderRect=z;
 lbl_80368304=z; ((s16*)p1)[1]=z; ((s16*)p1)[2]=w1; ((s16*)p1)[3]=h1;
 gTabMenuTabRect=z; ((s16*)p2)[1]=z; ((s16*)p2)[2]=w2; ((s16*)p2)[3]=h2;
 lbl_80368314=z; ((s16*)p3)[1]=z; ((s16*)p3)[2]=w3; ((s16*)p3)[3]=h3;
 lbl_8036831C=z; ((s16*)p4)[1]=z; ((s16*)p4)[2]=w4; ((s16*)p4)[3]=h4;
 lbl_80368324=z; ((s16*)p5)[1]=z; ((s16*)p5)[2]=w5; ((s16*)p5)[3]=h5;
 lbl_8036832C=z; ((s16*)p6)[1]=z; ((s16*)p6)[2]=w5; ((s16*)p6)[3]=h5;
 lbl_80368334=z; ((s16*)p7)[1]=z; ((s16*)p7)[2]=w5; ((s16*)p7)[3]=h5;
 lbl_8036833C=z; ((s16*)p8)[1]=z; ((s16*)p8)[2]=w8; ((s16*)p8)[3]=h8;
 lbl_80368344=z; ((s16*)p9)[1]=z; ((s16*)p9)[2]=w9; ((s16*)p9)[3]=h5;
 lbl_8036834C=z; ((s16*)p10)[1]=z; ((s16*)p10)[2]=w10; ((s16*)p10)[3]=h5;
 lbl_80368354=z; ((s16*)p11)[1]=z; ((s16*)p11)[2]=w11; ((s16*)p11)[3]=h5;
 fn_8022C260(&lbl_80332020,&fn_801EAA2C,0,0x18,0x18,0x18,&lbl_80368354,&lbl_8036834C);
}
