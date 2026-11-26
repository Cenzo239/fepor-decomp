/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
#include "structs.h"

// GXTexObj structure (from headers or similar functions)
typedef struct {
    u32 dummy[4];
} GXTexObj;

#pragma fp_contract off

typedef struct { f32 x, y; } F32Pair;

static inline f32 gx_sqrtf(f32 x) {
    volatile f32 y;
    if (x > 0.0f) {
        f64 guess = __frsqrte((f64)x);
        guess = 0.5 * guess * (3.0 - (f64)x * (guess * guess));
        guess = 0.5 * guess * (3.0 - (f64)x * (guess * guess));
        guess = 0.5 * guess * (3.0 - (f64)x * (guess * guess));
        y = (f32)((f64)x * guess);
        return y;
    }
    return x;
}

extern u16 lbl_80368784;
extern s32 gSaveDataBase;
extern s32 fn_80013E50(s32);
extern s32 fn_80013E60(s32, s32);
extern s32 fn_80013E74(void*, s32);


extern s32 lbl_80368614;
extern void (*lbl_803685E8)(void);
extern void* lbl_80368618;
extern void* lbl_8036861C;
extern void* lbl_80368620;
extern void* lbl_80368624;
extern void* lbl_80368628;
extern void* lbl_8036862C;
extern void* lbl_80368630;
extern void* lbl_80368634;
extern void* lbl_80368638;
extern void* lbl_8036863C;
extern void* lbl_80368640;
extern void* lbl_80368644;
extern void* lbl_80368648;
extern void* lbl_8036864C;
extern void* lbl_80368650;
extern void* lbl_80368654;

u8 ErrorCode2Num(s32);

extern u8 lbl_802820B8[];
extern u32 lbl_80368448;

typedef struct GXRenderModeObj {
    u32 viTVmode;
    u16 fbWidth;
    u16 efbHeight;
    u16 xfbHeight;
    u16 viXOrigin;
    u16 viYOrigin;
    u16 viWidth;
    u16 viHeight;
    s32 xFBmode;
    u8 field_rendering;
    u8 aa;
    u8 sample_pattern[12][2];
    u8 vfilter[7];
} GXRenderModeObj;

static u32 sFaceResAddrs[8];
static u32 sFaceResIds[8];
static s16 lbl_80339328[8];
static s16 lbl_80339338[8];

extern s32 lbl_803679F0;

extern u16 lbl_8029B634[10];

#pragma opt_common_subs off

#pragma opt_common_subs reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern u16 lbl_8029B7FC[10];

#pragma opt_common_subs off

#pragma opt_common_subs reset

extern u16 lbl_8029B7A4[10];

#pragma opt_common_subs off

#pragma opt_common_subs reset

extern void *IDShouldBe_8036859C;
extern void *fn_8020DAE0;
extern void fn_8020C1A4(u8, u32, void *);

extern u8 lbl_80289EB8[16];

extern u16 *__peReg;

extern u16* __peReg;

extern u32 lbl_80368738;
extern u32 __GXCurrentCPUFifo;

extern s32 jumptable_8029E0B8[];

extern u16* __GXData;

extern u16 *__GXData;

extern f32 lbl_8036BDC0;

static inline u32 __GXReadPECounterU32(u32 lo, u32 hi) {
    u32 ctrH0;
    u32 ctrH1;
    u32 ctrL;

    ctrH0 = *((volatile u16 *)__peReg + hi);
    do {
        ctrH1 = ctrH0;
        ctrL = *((volatile u16 *)__peReg + lo);
        ctrH0 = *((volatile u16 *)__peReg + hi);
    } while (ctrH0 != ctrH1);
    return (ctrH0 << 16) | ctrL;
}

extern u16* __cpReg;

static inline u32 __GXReadCPCounterU32(u32 lo, u32 hi) {
    u32 ctrH0;
    u32 ctrH1;
    u32 ctrL;

    volatile u16 *regH = (volatile u16 *)__cpReg + hi;
    volatile u16 *regL = (volatile u16 *)__cpReg + lo;

    ctrH0 = *regH;
    do {
        ctrH1 = ctrH0;
        ctrL = *regL;
        ctrH0 = *regH;
    } while (ctrH0 != ctrH1);
    return (ctrH0 << 16) | ctrL;
}

extern u16 *__GXData;
extern u16 *__GXData;
extern u16 *__GXData;
extern u16 *__GXData;
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
#include "structs.h"

extern u16 *__GXData;
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
#include "structs.h"

extern u16 *__GXData;
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
#include "structs.h"

extern u16* lbl_80368790;
extern u16* __peReg;
extern u16 *__GXData;

void fn_80222644(void *, void *, u16, u16, s32, s32, s32, u8);

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

void fn_80224304(s16 *table, u16 width, f32 *projmtx)
{
    f32 xi, scale, epsilon, nearz, f;
    f32 x;
    u32 i;
    volatile f32 sp14;

    if (0.0 == projmtx[0x3C / 4]) {
        nearz = projmtx[0x2C / 4] / (projmtx[0x28 / 4] - 1.0f);
        epsilon = nearz / projmtx[0];
    } else {
        epsilon = 1.0f / projmtx[0];
        nearz = 1.73205f * epsilon;
    }

    xi = nearz * nearz;
    scale = 2.0f / (f32)width;

    for (i = 0; i < 10; i++) {
        x = (f32)((i + 1) * 32);
        x = x * scale;
        x = x * epsilon;
        f = x * x;
        f = 1.0f + f / xi;
        if (f > 0.0f) {
            f64 guess = __frsqrte((f64)f);
            guess = 0.5 * guess * (3.0 - (f64)f * (guess * guess));
            guess = 0.5 * guess * (3.0 - (f64)f * (guess * guess));
            guess = 0.5 * guess * (3.0 - (f64)f * (guess * guess));
            sp14 = (f32)((f64)f * guess);
            f = sp14;
        }
        table[i] = (u32)(256.0f * f) & 0xFFF;
    }
}

void fn_802244B4(u8 arg0, u16 arg1, u16 *arg2) {
u32 i, value;
u16 *gx;
if(arg0) {
for(i=0;i<10;i+=2) {
value=0;
value=__rlwimi(value,arg2[i],0,20,31);
value=__rlwimi(value,arg2[i+1],12,8,19);
value=__rlwimi(value,(i>>1)+0xE9,24,0,7);
*(u8 *)0xCC008000=0x61;
*(u32 *)0xCC008000=value;
}
}
value=0;
value=__rlwimi(value,arg1+0x156,0,22,31);
value=__rlwimi(value,arg0,10,21,21);
gx=__GXData;
*(u8 *)0xCC008000=0x61;
value=__rlwimi(value,0xE8,24,0,7);
*(u32 *)0xCC008000=value;
gx[1]=0;
}

void fn_802245D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 *ptr = (u32 *)__GXData;
    u32 value = ptr[0x1D0 / 4];
    value = __rlwimi(value, (arg0 == 3), 11, 20, 20);
    value = __rlwimi(value, arg0, 0, 31, 31);
    value = __rlwimi(value, (arg0 == 2), 1, 30, 30);
    value = __rlwimi(value, arg3, 12, 16, 19);
    value = __rlwimi(value, arg1, 8, 21, 23);
    value = __rlwimi(value, arg2, 5, 24, 26);
    *(volatile u8 *)0xCC008000 = 0x61;
    *(volatile u32 *)0xCC008000 = value;
    ptr[0x1D0 / 4] = value;
    *(u16 *)((u8 *)ptr + 2) = 0;
}

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    s8 s8;
    s16 s16;
    s32 s32;
    f32 f32;
} PPCWGPipe;

volatile PPCWGPipe GXWGFifo : 0xCC008000;

#pragma peephole on
void fn_8022462C(u8 arg0) {
    u32 *ptr;
    u32 value;
    ptr = (u32 *)__GXData;
    value = ptr[0x1D0 / 4];
    value = __rlwimi(value, (u32)arg0, 3, 28, 28);
    *(u8 *)0xCC008000 = 0x61;
    *(u32 *)0xCC008000 = value;
    ptr[0x1D0 / 4] = value;
    *(u16 *)((u8 *)ptr + 2) = 0;
}
#pragma peephole on
void fn_80224658(u8 arg0) {
    u32 *ptr;
    u32 value;
    ptr = (u32 *)__GXData;
    value = ptr[0x1D0 / 4];
    value = __rlwimi(value, arg0, 4, 27, 27);
    *(u8 *)0xCC008000 = 0x61;
    *(u32 *)0xCC008000 = value;
    ptr[0x1D0 / 4] = value;
    *(u16 *)((u8 *)ptr + 2) = 0;
}
#pragma peephole on
void GXSetZMode(u8 arg0, s32 arg1, u8 arg2)
{
  u32 *ptr;
  u32 value;
  ptr = (u32 *) __GXData;
  value = ptr[0x1D8 / 4];
  value = __rlwimi(value, (u32) arg0, 0, 31, 31);
  *((u8 *) 0xCC008000) = 0x61;
  value = __rlwimi(value, arg1, 1, 28, 30);
  if (((!value) && (!value)) && (!value))
  {
  }
  value = __rlwimi(value, (u32) arg2, 4, 27, 27);
  *((u32 *) 0xCC008000) = value;
  ptr[0x1D8 / 4] = value;
  *((u16 *) (((u8 *) ptr) + 2)) = 0;
}

void fn_802246B8(u8 arg0) {
u32 *ptr = (u32*)__GXData;
ptr[0x1DC/4] = __rlwimi(ptr[0x1DC/4], (u32)arg0,6,25,25);
*(volatile u8*)0xCC008000 = 0x61;
*(volatile u32*)0xCC008000 = ptr[0x1DC/4];
*(u16*)((u8*)ptr+2) = 0;
}

void fn_802246EC(u32 arg0, u32 arg1)
{
  extern u32 lbl_8029E358[];
  u32 *ptr;
  u32 *entry;
  u32 *new_var2;
  u32 *gx;
  int new_var;
  u32 old;
  int new_var3[2];
  ptr = (u32 *) __GXData;
  entry = &lbl_8029E358[arg0];
  new_var3[0] = ptr[0x1DC / 4];
  old = new_var3[0];
  new_var3[0] = __rlwimi(new_var3[0], entry[0], 0, 29, 31);
  ptr[0x1DC / 4] = new_var3[0];
  new_var = 4;
  new_var3[0] = ptr[0x1DC / new_var];
  new_var3[0] = __rlwimi(new_var3[0], arg1, 3, 26, 28);
  ptr[0x1DC / new_var] = new_var3[0];
  new_var3[0] = ptr[0x1DC / new_var];
  if (old != new_var3[0])
  {
    *((volatile u8 *) 0xCC008000) = 0x61;
    *((volatile u32 *) 0xCC008000) = new_var3[0];
    if (((s32) arg0) == 2)
    {
      new_var3[1] = 1;
    }
    else
    {
      new_var3[1] = 0;
    }
    gx = (u32 *) __GXData;
    new_var3[0] = gx[0x204 / new_var];
    new_var3[0] = __rlwimi(new_var3[0], new_var3[1], 9, 22, 22);
    gx[0x204 / new_var] = new_var3[0];
    gx[0x5AC / new_var] |= new_var;
  }
  if (entry[0] == new_var)
  {
    ptr = (new_var2 = (u32 *) __GXData);
    new_var3[0] = ptr[0x1D4 / new_var];
    new_var3[0] = __rlwimi(new_var3[0], arg0 - new_var, 9, 21, 22);
    ptr[0x1D4 / new_var] = new_var3[0];
    new_var3[0] = ptr[0x1D4 / 4];
    new_var3[0] = __rlwimi(new_var3[0], 0x42, 24, 0, 7);
    ptr[0x1D4 / new_var] = new_var3[0];
    *((volatile u8 *) 0xCC008000) = 0x61;
    *((volatile u32 *) 0xCC008000) = ptr[0x1D4 / 4];
  }
  *((u16 *) (((u8 *) __GXData) + 2)) = 0;
}

#pragma peephole on
void fn_802247C0(u8 arg0) {
u32 *ptr; u32 value;
ptr=(u32 *)__GXData;
value=ptr[0x1d0/4];
value=__rlwimi(value,arg0,2,29,29);
*(u8 *)0xCC008000=0x61;
*(u32 *)0xCC008000=value;
ptr[0x1d0/4]=value;
*(u16 *)((u8 *)ptr+2)=0;
}
#pragma peephole reset
void fn_802247EC(u8 arg0, u8 arg1) {
    u32 *ptr;
    u32 value;
    ptr = (u32 *)__GXData;
    value = ptr[0x1D4 / 4];
    value = __rlwimi(value, (u32)arg1, 0, 24, 31);
    *(u8 *)0xCC008000 = 0x61;
    value = __rlwimi(value, (u32)arg0, 8, 23, 23);
    *(u32 *)0xCC008000 = value;
    ptr[0x1D4 / 4] = value;
    *(u16 *)((u8 *)ptr + 2) = 0;
}

#pragma opt_propagation on
