/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
#include "structs.h"

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

extern u16* const __GXData;

extern f32 lbl_8036BDC0;

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

extern u16* lbl_80368790;

/* Shrink a render mode's framebuffer/VI rects to leave an overscan border. */

#pragma use_lmw_stmw on
extern f64 lbl_8036BCD8;
extern f32 lbl_8036BCD0;
s32 __cvt_fp2unsigned(f32);
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

void fn_80221A2C(s32 arg0) {
    M2C_FIELD(__GXData, u32 *, 0x1EC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1EC), arg0, 7, 23, 24);
}

void GXCopyDisp(void *dest, u8 clear) {
    u32 reg;
    u32 tempPeCtrl;
    u32 phyAddr;
    u8 changePeCtrl;

    if (clear) {
        reg = M2C_FIELD(__GXData, u32 *, 0x1D8);
        reg = __rlwimi(reg, 1, 0, 31, 31);
        reg = __rlwimi(reg, 7, 1, 28, 30);
        GXWGFifo.u8 = 0x61;
        GXWGFifo.u32 = reg;

        reg = M2C_FIELD(__GXData, u32 *, 0x1D0);
        reg = __rlwimi(reg, 0, 0, 31, 31);
        reg = __rlwimi(reg, 0, 1, 30, 30);
        GXWGFifo.u8 = 0x61;
        GXWGFifo.u32 = reg;
    }

    changePeCtrl = 0;
    if (clear || (M2C_FIELD(__GXData, u32 *, 0x1DC) & 7) == 3) {
        if (((M2C_FIELD(__GXData, u32 *, 0x1DC) >> 6) & 1) == 1) {
            tempPeCtrl = M2C_FIELD(__GXData, u32 *, 0x1DC);
            GXWGFifo.u8 = 0x61;
            tempPeCtrl = __rlwimi(tempPeCtrl, 0, 6, 25, 25);
            GXWGFifo.u32 = tempPeCtrl;
            changePeCtrl = 1;
        }
    }

    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1E0);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1E4);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1E8);

    phyAddr = (u32)dest & 0x3FFFFFFF;
    reg = 0;
    reg = __rlwimi(reg, phyAddr >> 5, 0, 11, 31);
    reg = __rlwimi(reg, 0x4B, 24, 0, 7);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = reg;

    M2C_FIELD(__GXData, u32 *, 0x1EC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1EC), clear, 11, 20, 20);
    M2C_FIELD(__GXData, u32 *, 0x1EC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1EC), 1, 14, 17, 17);
    M2C_FIELD(__GXData, u32 *, 0x1EC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1EC), 0x52, 24, 0, 7);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1EC);

    if (clear) {
        GXWGFifo.u8 = 0x61;
        GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1D8);
        GXWGFifo.u8 = 0x61;
        GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1D0);
    }
    if (changePeCtrl) {
 GXWGFifo.u8 = 0x61;
 GXWGFifo.u32 = M2C_FIELD(__GXData,u32 *,0x1DC);
 }
 M2C_FIELD(__GXData,u16 *,2) = 0;
}

/* Copy the EFB into dest as a texture; optionally clear the EFB afterward. */
void GXCopyTex(void *dest, u8 clear) {
    u32 reg;
    u32 tempPeCtrl;
    u32 phyAddr;
    u8 changePeCtrl;

    if (clear) {
        reg = M2C_FIELD(__GXData, u32 *, 0x1D8);
        reg = __rlwimi(reg, 1, 0, 31, 31);
        reg = __rlwimi(reg, 7, 1, 28, 30);
        GXWGFifo.u8 = 0x61;
        GXWGFifo.u32 = reg;

        reg = M2C_FIELD(__GXData, u32 *, 0x1D0);
        reg = __rlwimi(reg, 0, 0, 31, 31);
        reg = __rlwimi(reg, 0, 1, 30, 30);
        GXWGFifo.u8 = 0x61;
        GXWGFifo.u32 = reg;
    }

    changePeCtrl = 0;
    tempPeCtrl = M2C_FIELD(__GXData, u32 *, 0x1DC);
    if (M2C_FIELD(__GXData, u8 *, 0x200) && (tempPeCtrl & 7) != 3) {
        changePeCtrl = 1;
        tempPeCtrl = __rlwimi(tempPeCtrl, 3, 0, 29, 31);
    }
    if ((clear || (tempPeCtrl & 7) == 3) && ((tempPeCtrl >> 6) & 1) == 1) {
        changePeCtrl = 1;
        tempPeCtrl = __rlwimi(tempPeCtrl, 0, 6, 25, 25);
    }
    if (changePeCtrl) {
        GXWGFifo.u8 = 0x61;
        GXWGFifo.u32 = tempPeCtrl;
    }

    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1F0);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1F4);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1F8);

    phyAddr = (u32)dest & 0x3FFFFFFF;
    reg = 0;
    reg = __rlwimi(reg, phyAddr >> 5, 0, 11, 31);
    reg = __rlwimi(reg, 0x4B, 24, 0, 7);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = reg;

    M2C_FIELD(__GXData, u32 *, 0x1FC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1FC), clear, 11, 20, 20);
    M2C_FIELD(__GXData, u32 *, 0x1FC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1FC), 0, 14, 17, 17);
    M2C_FIELD(__GXData, u32 *, 0x1FC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1FC), 0x52, 24, 0, 7);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1FC);

    if (clear) {
        GXWGFifo.u8 = 0x61;
        GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1D8);
        GXWGFifo.u8 = 0x61;
        GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1D0);
    }
    if (changePeCtrl) {
        GXWGFifo.u8 = 0x61;
        GXWGFifo.u32 = M2C_FIELD(__GXData, u32 *, 0x1DC);
    }
    M2C_FIELD(__GXData, u16 *, 0x2) = 0;
}

void fn_80221D34(void)
{
  u8 cmd = 0x61;
  u16 *gx = __GXData;
  u32 a = 0x55000000;
  u32 b;
  GXWGFifo.u8 = cmd;
  GXWGFifo.u32 = a + 0x3FF;
  b = 0x56000000;
  GXWGFifo.u8 = cmd;
  GXWGFifo.u32 = b + 0x3FF;
  __GXData[1] = 0;
}

void fn_80221D6C(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    M2C_FIELD(arg0, f32 *, 0x10) = farg0;
    M2C_FIELD(arg0, f32 *, 0x14) = farg1;
    M2C_FIELD(arg0, f32 *, 0x18) = farg2;
    M2C_FIELD(arg0, f32 *, 0x1C) = farg3;
    M2C_FIELD(arg0, f32 *, 0x20) = farg4;
    M2C_FIELD(arg0, f32 *, 0x24) = farg5;
}

void fn_80221D88(f32 *obj, f32 angle, u32 mode) {
    f32 cosf(f32);
    f32 a, b, c, t, x;
    if (angle <= 0.0f || angle > 90.0f)
        mode = 0;
    x = cosf(3.1415927f * angle / 180.0f);
    switch (mode) {
    case 1:
        a = (-1000.0f) * x;
        b = 1000.0f;
        c = 0.0f;
        break;
    case 2:
        t = 1.0f / (1.0f - x);
        b = t;
        a = -x * t;
        c = 0.0f;
        break;
    case 3:
        t = 1.0f / (1.0f - x);
        c = t;
        b = -x * t;
        a = 0.0f;
        break;
    case 4:
        t = 1.0f / ((1.0f - x) * (1.0f - x));
        a = t * (x * (x - 2.0f));
        b = 2.0f * t;
        c = -t;
        break;
    case 5:
        t = 1.0f / ((1.0f - x) * (1.0f - x));
        c = (-4.0f) * t;
        a = c * x;
        b = (4.0f * (1.0f + x)) * t;
        break;
    case 6:
        t = 1.0f / ((1.0f - x) * (1.0f - x));
        a = t * ((x * 2.0f) * x);
        b = (x * 4.0f) * t;
        c = t * (-2.0f);
        a = 1.0f - a;
        break;
    case 0:
    default:
        a = 1.0f;
        b = 0.0f;
        c = b;
        break;
    }
    obj[4] = a;
    obj[5] = b;
    obj[6] = c;
}

void fn_80221F18(void *arg0, s32 arg1, f32 farg0, f32 farg1) {
 f32 a,b,c;
 if(farg0<0.0f) arg1=0;
 if(farg1<=0.0f || farg1>=1.0f) arg1=0;
 switch(arg1) {
 case 1: a=1.0f; b=(1.0f-farg1)/(farg1*farg0); c=0.0f; break;
 case 2: a=1.0f; b=(0.5f*(1.0f-farg1))/(farg1*farg0); c=(0.5f*(1.0f-farg1))/(farg0*(farg1*farg0)); break;
 case 3: a=1.0f; b=0.0f; c=(1.0f-farg1)/(farg0*(farg1*farg0)); break;
 case 0: default: a=1.0f; b=0.0f; c=0.0f; break;
 }
 *(f32*)((u8*)arg0+0x1c)=a;
 *(f32*)((u8*)arg0+0x20)=b;
 *(f32*)((u8*)arg0+0x24)=c;
}

void fn_80221FE8(void *arg0, f32 farg0, f32 farg1, f32 farg2) {
    M2C_FIELD(arg0, f32 *, 0x28) = farg0;
    M2C_FIELD(arg0, f32 *, 0x2C) = farg1;
    M2C_FIELD(arg0, f32 *, 0x30) = farg2;
}

void fn_80221FF8(void *arg0, f32 farg0, f32 farg1, f32 farg2) {
    extern f32 lbl_8036BCE0;
    extern f32 lbl_8036BCF8;
    extern f32 lbl_8036BD20;
    extern f64 lbl_8036BD10;
    extern f64 lbl_8036BD18;
    typedef struct { u8 pad[0x28]; f32 a[3]; f32 b[3]; } Vec;
    Vec *v = (Vec *)arg0;
    f32 x, y, z, xx, yy, zz, mag, scale, root;
    volatile f32 sp18;
    f64 r, t;
    f32 px, py, pz;

    x = -farg0;
    y = -farg1;
    z = lbl_8036BCF8 - farg2;
    xx = x * x;
    yy = y * y;
    zz = z * z;
    mag = xx + yy;
    mag = mag + zz;
    scale = mag;
    if (lbl_8036BCE0 != mag) {
        if (scale > lbl_8036BCE0) {
            r = __frsqrte(scale);
            t = r * r;
            r = lbl_8036BD10 * r;
            t = (f64)scale * t;
            t = lbl_8036BD18 - t;
            r = r * t;
            t = r * r;
            r = lbl_8036BD10 * r;
            t = (f64)scale * t;
            t = lbl_8036BD18 - t;
            r = r * t;
            t = r * r;
            r = lbl_8036BD10 * r;
            t = (f64)scale * t;
            t = lbl_8036BD18 - t;
            r = r * t;
            sp18 = (f32)((f64)scale * r);
            root = sp18;
        } else {
            root = scale;
        }
        scale = lbl_8036BCF8 / root;
    }
    v->b[0] = x * scale;
    v->b[1] = y * scale;
    v->b[2] = z * scale;
    px = lbl_8036BD20 * farg0;
    py = lbl_8036BD20 * farg1;
    pz = lbl_8036BD20 * farg2;
    v->a[0] = px;
    v->a[1] = py;
    v->a[2] = pz;
}

void fn_802220DC(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) *arg1;
}

void fn_802220E8(void *arg0, u32 arg1) {
 volatile u8 *fifo=(volatile u8 *)0xCC008000;
 u8 *src=arg0;
 u32 command=(((31-__cntlzw(arg1))&7)<<4)+0x600;
 u32 value;
 f64 f0,f1,f2,f3,f4,f5;
 *fifo=0x10;
 *(volatile u32*)fifo=command|0xF0000;
 value=*(u32*)(src+12);
 f5=*(f64*)(src+16); f4=*(f64*)(src+24); f3=*(f64*)(src+32); f2=*(f64*)(src+40); f1=*(f64*)(src+48); f0=*(f64*)(src+56);
 *(volatile u32*)fifo=0; *(volatile u32*)fifo=0; *(volatile u32*)fifo=0; *(volatile u32*)fifo=value;
 *(volatile f64*)fifo=f5; *(volatile f64*)fifo=f4; *(volatile f64*)fifo=f3; *(volatile f64*)fifo=f2; *(volatile f64*)fifo=f1; *(volatile f64*)fifo=f0;
 *(u16*)((u8*)__GXData+2)=1;
}

#pragma optimization_level 3
void fn_80222164(s32 arg0, void *arg1) {
    u32 value;
    s32 index;
    struct GXChanData { u16 unused; u16 dirty; u8 pad[0xA4]; u32 color[2]; } *gx;
    switch (arg0) {
    case 0: index = 0; value = *(u32 *)((u8 *)__GXData + 0xA8); value = __rlwimi(value, *(u32 *)arg1, 0, 0, 23); break;
    case 1: index = 1; value = *(u32 *)((u8 *)__GXData + 0xAC); value = __rlwimi(value, *(u32 *)arg1, 0, 0, 23); break;
    case 2: index = 0; value = *(u32 *)((u8 *)__GXData + 0xA8); value = __rlwimi(value, ((u8 *)arg1)[3], 0, 24, 31); break;
    case 3: index = 1; value = *(u32 *)((u8 *)__GXData + 0xAC); value = __rlwimi(value, ((u8 *)arg1)[3], 0, 24, 31); break;
    case 4: value = *(u32 *)arg1; index = 0; break;
    case 5: value = *(u32 *)arg1; index = 1; break;
    default: return;
    }
    GXWGFifo.u8 = 0x10;
    gx = (void *)__GXData;
    GXWGFifo.u32 = (index + 0x100A) & 0xFFFFFFFFFFFFFFFF;
    GXWGFifo.u32 = value;
    gx->dirty = 1;
    gx->color[index] = value;
}
#pragma optimization_level 3
void GXSetChanMatColor(s32 arg0, void *arg1)
{
  s32 index;
  u32 value;
  struct GXChanData
  {
    u16 unused;
    u16 dirty;
    u8 pad[0xAC];
    u32 color[2];
  } *gx;
  switch (arg0)
  {
    case 0:
      index = 0;
      value = *((u32 *) (((u8 *) __GXData) + 0xB0));
      value = __rlwimi(value, *((u32 *) arg1), 0, 0, 23);
      break;

    case 1:
      index = 1;
      value = *((u32 *) (((u8 *) __GXData) + 0xB4));
      value = __rlwimi(value, *((u32 *) arg1), 0, 0, 23);
      break;

    case 2:
      index = 0;
      value = *((u32 *) (((u8 *) __GXData) + 0xB0));
      value = __rlwimi(value, ((u8 *) arg1)[3], 0, 24, 31);
      break;

    case 3:
      index = 1;
      value = *((u32 *) (((u8 *) __GXData) + 0xB4));
      value = __rlwimi(value, ((u8 *) arg1)[3], 0, 24, 31);
      break;

    case 4:
      value = *((u32 *) arg1);
      index = 0;
      break;

    case 5:
      value = *((u32 *) arg1);
      index = 1;
      break;

    default:
      return;

  }

  GXWGFifo.u8 = 0x10;
  gx = (void *) __GXData;
  GXWGFifo.u32 = (index + 0x100C) & 0xFFFFFFFFFFFFFFFF;
  GXWGFifo.u32 = value;
  gx->dirty = 1;
  gx->color[index] = value;
}
#pragma optimization_level reset
void GXSetCullMode(u32 arg0) {
u32 *gxData = (u32*)__GXData;
u32 count = (u8)arg0;
gxData[0x204/4] = __rlwimi(gxData[0x204/4],count,4,25,27);
*(volatile u8*)0xCC008000 = 0x10;
*(volatile u32*)0xCC008000 = 0x1009;
*(volatile u32*)0xCC008000 = count;
gxData[0x5AC/4] |= 4;
}

void GXSetBlendMode(s32 arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
#pragma scheduling on
 u32 value=0;
 u32 channel=arg0&3;
 value=__rlwimi(value,arg1,1,30,30);
 value=__rlwimi(value,arg3,0,31,31);
 value=__rlwimi(value,arg2,6,25,25);
 if(arg6==0) arg5=0;
 value=__rlwimi(value,arg5,7,23,24);
 value=__rlwimi(value,arg6!=2,9,22,22);
 value=__rlwimi(value,arg6!=0,10,21,21);
 value=__rlwimi(value,arg4,2,26,29);
 value=__rlwimi(value,arg4,7,17,20);
 GXWGFifo.u8=0x10;
 GXWGFifo.u32=channel+0x100E;
 GXWGFifo.u32=value;
 if(arg0==4) {
 GXWGFifo.u8=0x10; GXWGFifo.u32=0x1010; GXWGFifo.u32=value;
 } else if(arg0==5) {
 GXWGFifo.u8=0x10; GXWGFifo.u32=0x1011; GXWGFifo.u32=value;
 }
 __GXData[1]=1;
}

#pragma scheduling reset
