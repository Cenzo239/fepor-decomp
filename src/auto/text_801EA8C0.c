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
extern u16* lbl_80332020;
extern u16* fn_801EAA2C;

void fn_801EA8C0(void) {
 void fn_8022C260(void *,void *,void *,u32,u32,u32,void *,void *);
 s32 z=0;
 s32 w0=0xd8,h0=0x30;
 s16 *ph=(s16 *)&gTabMenuHeaderRect;
 s16 *p1=(s16 *)&lbl_80368304; s32 w1=0x220,h1=0x1a;
 s16 *p2=(s16 *)&gTabMenuTabRect; s32 w2=0x64,h2=0x22;
 s16 *p3=(s16 *)&lbl_80368314; s32 w3=0x60,h3=0x20;
 s16 *p4=(s16 *)&lbl_8036831C; s32 w4=0x220,h4=0x20;
 s16 *p5=(s16 *)&lbl_80368324; s32 w5=2,h5=8;
 s16 *p6=(s16 *)&lbl_8036832C;
 s16 *p7=(s16 *)&lbl_80368334;
 s16 *p8=(s16 *)&lbl_8036833C; s32 w8=0x38,h8=0x18;
 s16 *p9=(s16 *)&lbl_80368344; s32 w9=0x10;
 s16 *p10=(s16 *)&lbl_8036834C; s32 w10=8;
 s16 *p11=(s16 *)&lbl_80368354; s32 w11=0x10;
 ph[2]=w0; ph[1]=z; ph[3]=h0; gTabMenuHeaderRect=z;
 lbl_80368304=z; p1[1]=z; p1[2]=w1; p1[3]=h1;
 gTabMenuTabRect=z; p2[1]=z; p2[2]=w2; p2[3]=h2;
 lbl_80368314=z; p3[1]=z; p3[2]=w3; p3[3]=h3;
 lbl_8036831C=z; p4[1]=z; p4[2]=w4; p4[3]=h4;
 lbl_80368324=z; p5[1]=z; p5[2]=w5; p5[3]=h5;
 lbl_8036832C=z; p6[1]=z; p6[2]=w5; p6[3]=h5;
 lbl_80368334=z; p7[1]=z; p7[2]=w5; p7[3]=h5;
 lbl_8036833C=z; p8[1]=z; p8[2]=w8; p8[3]=h8;
 lbl_80368344=z; p9[1]=z; p9[2]=w9; p9[3]=h5;
 lbl_8036834C=z; p10[1]=z; p10[2]=w10; p10[3]=h5;
 lbl_80368354=z; p11[1]=z; p11[2]=w11; p11[3]=h5;
 fn_8022C260(&lbl_80332020,&fn_801EAA2C,0,0x18,0x18,0x18,&lbl_80368354,&lbl_8036834C);
}
