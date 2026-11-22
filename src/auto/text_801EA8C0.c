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
extern u8 lbl_80332020[576];
extern void fn_801EAA2C(void);

void fn_801EA8C0(void) {
 void fn_8022C260(void *,void *,void *,u32,u32);
*(u16 *)((u8 *)&gTabMenuHeaderRect+4)=216;
*(u16 *)((u8 *)&gTabMenuHeaderRect+2)=0;
*(u16 *)((u8 *)&gTabMenuHeaderRect+6)=48;
*(u16 *)((u8 *)&gTabMenuHeaderRect+0)=0;
*(u16 *)((u8 *)&lbl_80368304+0)=0;
*(u16 *)((u8 *)&lbl_80368304+2)=0;
*(u16 *)((u8 *)&lbl_80368304+4)=544;
*(u16 *)((u8 *)&lbl_80368304+6)=26;
*(u16 *)((u8 *)&gTabMenuTabRect+0)=0;
*(u16 *)((u8 *)&gTabMenuTabRect+2)=0;
*(u16 *)((u8 *)&gTabMenuTabRect+4)=100;
*(u16 *)((u8 *)&gTabMenuTabRect+6)=34;
*(u16 *)((u8 *)&lbl_80368314+0)=0;
*(u16 *)((u8 *)&lbl_80368314+2)=0;
*(u16 *)((u8 *)&lbl_80368314+4)=96;
*(u16 *)((u8 *)&lbl_80368314+6)=32;
*(u16 *)((u8 *)&lbl_8036831C+0)=0;
*(u16 *)((u8 *)&lbl_8036831C+2)=0;
*(u16 *)((u8 *)&lbl_8036831C+4)=544;
*(u16 *)((u8 *)&lbl_8036831C+6)=32;
*(u16 *)((u8 *)&lbl_80368324+0)=0;
*(u16 *)((u8 *)&lbl_80368324+2)=0;
*(u16 *)((u8 *)&lbl_80368324+4)=2;
*(u16 *)((u8 *)&lbl_80368324+6)=8;
*(u16 *)((u8 *)&lbl_8036832C+0)=0;
*(u16 *)((u8 *)&lbl_8036832C+2)=0;
*(u16 *)((u8 *)&lbl_8036832C+4)=2;
*(u16 *)((u8 *)&lbl_8036832C+6)=8;
*(u16 *)((u8 *)&lbl_80368334+0)=0;
*(u16 *)((u8 *)&lbl_80368334+2)=0;
*(u16 *)((u8 *)&lbl_80368334+4)=2;
*(u16 *)((u8 *)&lbl_80368334+6)=8;
*(u16 *)((u8 *)&lbl_8036833C+0)=0;
*(u16 *)((u8 *)&lbl_8036833C+2)=0;
*(u16 *)((u8 *)&lbl_8036833C+4)=56;
*(u16 *)((u8 *)&lbl_8036833C+6)=24;
*(u16 *)((u8 *)&lbl_80368344+0)=0;
*(u16 *)((u8 *)&lbl_80368344+2)=0;
*(u16 *)((u8 *)&lbl_80368344+4)=16;
*(u16 *)((u8 *)&lbl_80368344+6)=8;
*(u16 *)((u8 *)&lbl_8036834C+0)=0;
*(u16 *)((u8 *)&lbl_8036834C+2)=0;
*(u16 *)((u8 *)&lbl_8036834C+4)=8;
*(u16 *)((u8 *)&lbl_8036834C+6)=8;
*(u16 *)((u8 *)&lbl_80368354+0)=0;
*(u16 *)((u8 *)&lbl_80368354+2)=0;
*(u16 *)((u8 *)&lbl_80368354+4)=16;
*(u16 *)((u8 *)&lbl_80368354+6)=8;
fn_8022C260(&lbl_80332020,&fn_801EAA2C,0,24,24);
}
