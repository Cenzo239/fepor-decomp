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
    volatile u16 *base;
    volatile u16 *regH;
    volatile u16 *regL;
    u32 ctrH0;
    u32 ctrH1;
    u32 ctrL;

    base = __cpReg;
    regH = base + hi;
    ctrH0 = *((volatile u16 *)base + hi);
    regL = base + lo;
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

#pragma peephole off

#pragma peephole off

#pragma peephole on

#pragma peephole off

#pragma peephole on

/* Transform a point by the model-view matrix and project it to screen space (perspective or ortho). */

#pragma ppc_intrinsics on

#pragma peephole off

#pragma peephole on

f32 GXLoadPosMtxImm(s32 arg1) {
    *(s8 *)0xCC008000 = 0x10;
    *(s8 *)0xCC008000 = (s32) ((arg1 * 4) | 0xB0000);
    return M2C_ERROR(/* psq_l unimplemented */);
}

void fn_80224DCC(f32 mtx[3][4], s32 id)
{
    f64 row0;
    f64 row1;
    f64 row2;
    f32 c0;
    f32 c1;
    f32 c2;
    u32 reg;

    reg = (u32)(id * 3) + 0x400;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = reg | 0x80000;
    row0 = *(f64 *)&mtx[0][0];
    c0 = mtx[0][2];
    row1 = *(f64 *)&mtx[1][0];
    c1 = mtx[1][2];
    row2 = *(f64 *)&mtx[2][0];
    c2 = mtx[2][2];
    *(volatile f64 *)&GXWGFifo = row0;
    GXWGFifo.f32 = c0;
    *(volatile f64 *)&GXWGFifo = row1;
    GXWGFifo.f32 = c1;
    *(volatile f64 *)&GXWGFifo = row2;
    GXWGFifo.f32 = c2;
}

void GXSetCurrentMtx(u32 arg0) {
 void fn_80225180(s32);
 M2C_FIELD(__GXData, u32 *, 0x80) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x80), arg0, 0, 26, 31);
 fn_80225180(0);
}

#pragma optimization_level 3
void fn_80224E50(f32 *mtx, u32 id, s32 type) {
    u32 addr;
    u32 size;
    register u32 shift;
    f64 a, b, c, d, e, f;
    register volatile u32 *fifo;
    volatile f64 *dst;

    if (id >= 0x40U) {
        addr = ((id - 0x40) * 4) + 0x500;
    } else {
        addr = id * 4;
    }
    if (type == 1) {
        size = 8;
    } else {
        size = 0xC;
    }
    shift = (size - 1) << 16;

    fifo = (volatile u32 *)0xCC010000;
    *(volatile u8 *)((u8 *)fifo - 0x8000) = 0x10;
    *(volatile u32 *)((u8 *)fifo - 0x8000) = addr | shift;
    fifo = (volatile u32 *)((u8 *)fifo - 0x8000);
    dst = (volatile f64 *)fifo;

    if (type == 0) {
        a = ((f64 *)mtx)[0]; b = ((f64 *)mtx)[1]; c = ((f64 *)mtx)[2];
        d = ((f64 *)mtx)[3]; e = ((f64 *)mtx)[4]; f = ((f64 *)mtx)[5];
        *dst = a; *dst = b; *dst = c; *dst = d; *dst = e; *dst = f;
    } else {
        a = ((f64 *)mtx)[0]; b = ((f64 *)mtx)[1]; c = ((f64 *)mtx)[2]; d = ((f64 *)mtx)[3];
        *dst = a; *dst = b; *dst = c; *dst = d;
    }
}
#pragma optimization_level reset
void fn_80224F04(u16 *unused) {
    extern f32 lbl_8036BDC0;
    extern f32 lbl_8036BDC4;
    u8 *gx;
    f32 scale;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 f;
    f32 e;
    f32 g;
    f32 h;
    f32 negA;
    f32 mul_b;
    f32 mul_neg;
    f32 mul_ef;
    f32 mul_gf;
    f32 bias;

    gx = (u8 *)__GXData;
    scale = lbl_8036BDC0;
    a = *(f32 *)(gx + 0x500);
    b = *(f32 *)(gx + 0x4FC);
    negA = -a;
    c = *(f32 *)(gx + 0x4F4);
    mul_b = b * scale;
    d = *(f32 *)(gx + 0x4F8);
    a = a * scale;
    f = *(f32 *)(gx + 0x510);
    e = *(f32 *)(gx + 0x508);
    mul_neg = negA * scale;
    g = *(f32 *)(gx + 0x504);
    h = *(f32 *)(gx + 0x50C);
    mul_ef = e * f;
    mul_gf = g * f;
    bias = lbl_8036BDC4;
    *(u8 *)0xCC008000 = 0x10;
    c = c + mul_b;
    *(u32 *)0xCC008000 = 0x0005101A;
    d = d + a;
    *(f32 *)0xCC008000 = mul_b;
    mul_gf = mul_ef - mul_gf;
    c = bias + c;
    *(f32 *)0xCC008000 = mul_neg;
    d = bias + d;
    *(f32 *)0xCC008000 = mul_gf;
    h = mul_ef + h;
    *(f32 *)0xCC008000 = c;
    *(f32 *)0xCC008000 = d;
    *(f32 *)0xCC008000 = h;
}

void fn_80224F94(u32 arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) { u16 *gx; if(arg0==0) farg1-=lbl_8036BDC0; gx=__GXData; *(f32*)((char*)gx+0x4F4)=farg0; *(f32*)((char*)gx+0x4F8)=farg1; *(f32*)((char*)gx+0x4FC)=farg2; *(f32*)((char*)gx+0x500)=farg3; *(f32*)((char*)gx+0x504)=farg4; *(f32*)((char*)gx+0x508)=farg5; fn_80224F04(gx); __GXData[1]=1; }

void GXSetViewport(f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) { u16 *gx=__GXData; *(f32*)((char*)gx+0x4F4)=farg0; *(f32*)((char*)gx+0x4F8)=farg1; *(f32*)((char*)gx+0x4FC)=farg2; *(f32*)((char*)gx+0x500)=farg3; *(f32*)((char*)gx+0x504)=farg4; *(f32*)((char*)gx+0x508)=farg5; fn_80224F04(gx); __GXData[1]=1; }

void fn_80225034(u32 arg0, u32 *dst) {
    double *source = (double *)((u8 *)__GXData + 0x4f4);
    double *out = (double *)arg0;
    double a = source[0], b = source[1], c = source[2];
    out[0] = a;
    out[1] = b;
    out[2] = c;
}

#pragma optimization_level 2
void GXSetScissor(s32 left, s32 top, s32 wd, s32 ht)
{
  u8 *gx;
  s32 x0;
  s32 y0;
  u32 x1;
  u32 y1;
  u32 adjustedHeight;
  gx = (u8 *) __GXData;
  y0 = top + 0x156;
  adjustedHeight = ((u32) ht) - 1;
  *((u32 *) (gx + 0xF8)) = __rlwimi(*((u32 *) (gx + 0xF8)), y0, 0, 21, 31);
  x0 = left + 0x156;
  x1 = ((u32) wd) - 1;
  y1 = ((u32) y0) + adjustedHeight;
  *((u32 *) (gx + 0xF8)) = __rlwimi(*((u32 *) (gx + 0xF8)), x0, 12, 9, 19);
  x1 = ((u32) x0) + x1;
  adjustedHeight = y1;
  *((u32 *) (gx + 0xFC)) = __rlwimi(*((u32 *) (gx + 0xFC)), adjustedHeight, 0, 21, 31);
  *((u32 *) (gx + 0xFC)) = __rlwimi(*((u32 *) (gx + 0xFC)), x1, 12, 9, 19);
  GXWGFifo.u8 = 0x61;
  GXWGFifo.u32 = *((u32 *) (gx + 0xF8));
  GXWGFifo.u8 = 0x61;
  GXWGFifo.u32 = *((u32 *) (gx + 0xFC));
  *((u16 *) (gx + 2)) = 0;
}
#pragma scheduling off
void fn_802250D0(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
  u32 temp_r8;
  u32 temp_r7;
  u32 temp_r9;
  u32 width;
  u32 bottom;
  temp_r8 = *((u32 *) (((char *) __GXData) + 0xfc));
  temp_r7 = *((u32 *) (((char *) __GXData) + 0xf8));
  temp_r9 = (temp_r7 >> 12) & 0x7ff;
  *arg0 = temp_r9 - 0x156;
  temp_r7 &= 0x7ff;
  *arg1 = temp_r7 - 0x156;
  width = (((temp_r8 >> 12) & 0x7ff) - temp_r9) + 1;
  bottom = temp_r8 & 0x7ff;
  *arg2 = width;
  *arg3 = (bottom - temp_r7) + 1;
}
#pragma scheduling reset

#pragma peephole off
void fn_80225118(s32 x, s32 y)
{
  u32 value;
  s32 yoff;
  s32 xoff;

  xoff = x + 0x156;
  yoff = y + 0x156;
  value = __rlwimi(__rlwimi(0, (u32)xoff, 31, 22, 31) + 0, (u32)yoff, 9, 12, 21);
  GXWGFifo.u8 = 0x61;
  value = __rlwimi(value, 0x59, 24, 0, 7);
  GXWGFifo.u32 = value;
  __GXData[1] = 0;
}
void fn_80225158(u32 arg0)
{
  u8 cmd = 0x10;
  u16 *gx;
  GXWGFifo.u8 = cmd;
  GXWGFifo.u32 = 0x1005;
  GXWGFifo.u32 = arg0;
  __GXData[1] = 1;
}

void fn_80225180(s32 arg0)
{
  int new_var2;
  u32 value;
  int new_var;
  u16 *gx;
  new_var = 0;
  new_var2 = 5;
  if (arg0 < new_var2)
  {
    gx = __GXData;
    GXWGFifo.u8 = 8;
    GXWGFifo.u8 = 0x30;
    value = (GXWGFifo.u32 = *((u32 *) (((u8 *) gx) + 0x80)));
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = 0x1018;
    GXWGFifo.u32 = value;
  }
  else
  {
    gx = __GXData;
    GXWGFifo.u8 = 8;
    arg0 += new_var;
    GXWGFifo.u8 = 0x40;
    value = (GXWGFifo.u32 = *((u32 *) (((u8 *) gx) + 0x84)));
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = 0x1019;
    GXWGFifo.u32 = value;
  }
  __GXData[1] = 1;
}

#pragma opt_common_subs off
#pragma peephole off
void fn_80225204(u32 perf0, u32 perf1)
{
    u16 *gx;
    u32 val;
    s32 old;

    old = M2C_FIELD(__GXData, s32 *, 0x59C);
    if (old == 34) {
        goto clear_perf0_cp;
    } else if (old >= 34) {
        goto perf0_done;
    } else if (old < 11) {
        if (old >= 0) {
            goto clear_perf0_cp;
        }
        goto perf0_done;
    } else if (old >= 27) {
        goto clear_perf0_2400;
    } else {
        goto clear_perf0_2300;
    }

clear_perf0_cp:
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = 0x1006;
    GXWGFifo.u32 = 0;
    goto perf0_done;

clear_perf0_2300:
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = 0x23000000;
    goto perf0_done;

clear_perf0_2400:
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = 0x24000000;

perf0_done:
    gx = __GXData;
    old = M2C_FIELD(gx, s32 *, 0x5A0);
    if (old == 21) {
        goto clear_perf1_bp;
    } else if (old >= 21) {
        goto perf1_done;
    } else if (old < 9) {
        if (old >= 0) {
            goto clear_perf1_bp;
        }
        goto perf1_done;
    } else if (old >= 17) {
        goto perf1_done;
    } else {
        goto clear_perf1_pe;
    }

clear_perf1_bp:
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = 0x67000000;
    goto perf1_done;

clear_perf1_pe:
    val = M2C_FIELD(gx, u32 *, 0x5A4);
    val = __rlwimi(val, 0, 4, 24, 27);
    M2C_FIELD(gx, u32 *, 0x5A4) = val;
    GXWGFifo.u8 = 8;
    GXWGFifo.u8 = 0x20;
    GXWGFifo.u32 = M2C_FIELD(gx, u32 *, 0x5A4);

perf1_done:
    __cpReg[3] = 0;

    gx = __GXData;
    M2C_FIELD(gx, u32 *, 0x59C) = perf0;
    switch (M2C_FIELD(gx, u32 *, 0x59C)) {
    case 0:
        GXWGFifo.u8 = 0x10; GXWGFifo.u32 = 0x1006; GXWGFifo.u32 = 0x273; break;
    case 1:
        GXWGFifo.u8 = 0x10; GXWGFifo.u32 = 0x1006; GXWGFifo.u32 = 0x14A; break;
    case 2:
        GXWGFifo.u8 = 0x10; GXWGFifo.u32 = 0x1006; GXWGFifo.u32 = 0x16B; break;
    case 3:
        GXWGFifo.u8 = 0x10; GXWGFifo.u32 = 0x1006; GXWGFifo.u32 = 0x84; break;
    case 4:
        GXWGFifo.u8 = 0x10; GXWGFifo.u32 = 0x1006; GXWGFifo.u32 = 0xC6; break;
    case 5:
        GXWGFifo.u8 = 0x10; GXWGFifo.u32 = 0x1006; GXWGFifo.u32 = 0x210; break;
    case 6:
        GXWGFifo.u8 = 0x10; GXWGFifo.u32 = 0x1006; GXWGFifo.u32 = 0x252; break;
    case 7:
        GXWGFifo.u8 = 0x10; GXWGFifo.u32 = 0x1006; GXWGFifo.u32 = 0x231; break;
    case 8:
        GXWGFifo.u8 = 0x10; GXWGFifo.u32 = 0x1006; GXWGFifo.u32 = 0x1AD; break;
    case 9:
        GXWGFifo.u8 = 0x10; GXWGFifo.u32 = 0x1006; GXWGFifo.u32 = 0x1CE; break;
    case 10:
        GXWGFifo.u8 = 0x10; GXWGFifo.u32 = 0x1006; GXWGFifo.u32 = 0x21; break;
    case 11:
        GXWGFifo.u8 = 0x10; GXWGFifo.u32 = 0x1006; GXWGFifo.u32 = 0x153; break;
    case 12:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x5181; break;
    case 13:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x7181; break;
    case 14:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x6181; break;
    case 15:
        val = 0x2300 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val + 0x1E7F; break;
    case 16:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x53C1; break;
    case 17:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x5381; break;
    case 18:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x5341; break;
    case 19:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x5301; break;
    case 20:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x52C1; break;
    case 21:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x5281; break;
    case 22:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x5241; break;
    case 23:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x5201; break;
    case 24:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x51C1; break;
    case 25:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x5D81; break;
    case 26:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x5981; break;
    case 27:
        val = 0x2301 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x5581; break;
    case 28:
        val = 0x2403 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x3F3A; break;
    case 29:
        val = 0x2403 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x3E95; break;
    case 30:
        val = 0x2403 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x3F19; break;
    case 31:
        val = 0x2403 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x3EF8; break;
    case 32:
        val = 0x2403 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x3ED7; break;
    case 33:
        val = 0x2403 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x3EB6; break;
    case 34:
        val = 0x2403 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val - 0x3E53; break;
    case 35:
        break;
    }

    gx = __GXData;
    M2C_FIELD(gx, u32 *, 0x5A0) = perf1;
    switch (M2C_FIELD(gx, u32 *, 0x5A0)) {
    case 0:
        val = 0x6700 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val + 0x42; break;
    case 1:
        val = 0x6700 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val + 0x84; break;
    case 2:
        val = 0x6700 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val + 0x63; break;
    case 3:
        val = 0x6700 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val + 0x129; break;
    case 8:
        val = 0x6700 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val + 0x252; break;
    case 21:
        val = 0x6700 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val + 0x21; break;
    case 4:
        val = 0x6700 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val + 0x14B; break;
    case 5:
        val = 0x6700 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val + 0x18D; break;
    case 6:
        val = 0x6700 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val + 0x1CF; break;
    case 7:
        val = 0x6700 << 16; GXWGFifo.u8 = 0x61; GXWGFifo.u32 = val + 0x211; break;
    case 9:
        val = M2C_FIELD(gx, u32 *, 0x5A4);
        val = __rlwimi(val, 2, 4, 24, 27);
        M2C_FIELD(gx, u32 *, 0x5A4) = val;
        GXWGFifo.u8 = 8; GXWGFifo.u8 = 0x20;
        GXWGFifo.u32 = M2C_FIELD(gx, u32 *, 0x5A4);
        break;
    case 10:
        val = M2C_FIELD(gx, u32 *, 0x5A4);
        val = __rlwimi(val, 3, 4, 24, 27);
        M2C_FIELD(gx, u32 *, 0x5A4) = val;
        GXWGFifo.u8 = 8; GXWGFifo.u8 = 0x20;
        GXWGFifo.u32 = M2C_FIELD(gx, u32 *, 0x5A4);
        break;
    case 11:
        val = M2C_FIELD(gx, u32 *, 0x5A4);
        val = __rlwimi(val, 4, 4, 24, 27);
        M2C_FIELD(gx, u32 *, 0x5A4) = val;
        GXWGFifo.u8 = 8; GXWGFifo.u8 = 0x20;
        GXWGFifo.u32 = M2C_FIELD(gx, u32 *, 0x5A4);
        break;
    case 12:
        val = M2C_FIELD(gx, u32 *, 0x5A4);
        val = __rlwimi(val, 5, 4, 24, 27);
        M2C_FIELD(gx, u32 *, 0x5A4) = val;
        GXWGFifo.u8 = 8; GXWGFifo.u8 = 0x20;
        GXWGFifo.u32 = M2C_FIELD(gx, u32 *, 0x5A4);
        break;
    case 13:
        val = M2C_FIELD(gx, u32 *, 0x5A4);
        val = __rlwimi(val, 6, 4, 24, 27);
        M2C_FIELD(gx, u32 *, 0x5A4) = val;
        GXWGFifo.u8 = 8; GXWGFifo.u8 = 0x20;
        GXWGFifo.u32 = M2C_FIELD(gx, u32 *, 0x5A4);
        break;
    case 14:
        val = M2C_FIELD(gx, u32 *, 0x5A4);
        val = __rlwimi(val, 7, 4, 24, 27);
        M2C_FIELD(gx, u32 *, 0x5A4) = val;
        GXWGFifo.u8 = 8; GXWGFifo.u8 = 0x20;
        GXWGFifo.u32 = M2C_FIELD(gx, u32 *, 0x5A4);
        break;
    case 15:
        val = M2C_FIELD(gx, u32 *, 0x5A4);
        val = __rlwimi(val, 9, 4, 24, 27);
        M2C_FIELD(gx, u32 *, 0x5A4) = val;
        GXWGFifo.u8 = 8; GXWGFifo.u8 = 0x20;
        GXWGFifo.u32 = M2C_FIELD(gx, u32 *, 0x5A4);
        break;
    case 16:
        val = M2C_FIELD(gx, u32 *, 0x5A4);
        val = __rlwimi(val, 8, 4, 24, 27);
        M2C_FIELD(gx, u32 *, 0x5A4) = val;
        GXWGFifo.u8 = 8; GXWGFifo.u8 = 0x20;
        GXWGFifo.u32 = M2C_FIELD(gx, u32 *, 0x5A4);
        break;
    case 17:
        __cpReg[3] = 2; break;
    case 18:
        __cpReg[3] = 3; break;
    case 19:
        __cpReg[3] = 4; break;
    case 20:
        __cpReg[3] = 5; break;
    case 22:
        break;
    }

    __GXData[1] = 0;
}
#pragma global_optimizer off
#pragma scheduling off
#pragma peephole on
void fn_80225A4C(u32 *cnt0, u32 *cnt1) {
    u32 ctr0;
    u32 ctr1;
    u32 ctr2;
    u32 ctr3;
    u32 ctrH0;
    u32 ctrH1;
    u32 ctrL;
    volatile u16 *base;

    base = __cpReg;

{
 volatile u16 *regL;
 volatile u16 *regH;
    regH = base + 0x21;
    ctr0 = base[0x21];
    regL = base + 0x20;
    do {
        ctrH1 = ctr0;
        ctrL = *regL;
        ctr0 = *regH;
    } while (ctr0 != ctrH1);
    ctr0 = (ctr0 << 16) | ctrL;
}

{
 volatile u16 *regL;
 volatile u16 *regH;
    regH = base + 0x23;
    ctr1 = base[0x23];
    regL = base + 0x22;
    do {
        ctrH1 = ctr1;
        ctrL = *regL;
        ctr1 = *regH;
    } while (ctr1 != ctrH1);
    ctr1 = (ctr1 << 16) | ctrL;
}

{
 volatile u16 *regL;
 volatile u16 *regH;
    regH = base + 0x25;
    ctr2 = base[0x25];
    regL = base + 0x24;
    do {
        ctrH1 = ctr2;
        ctrL = *regL;
        ctr2 = *regH;
    } while (ctr2 != ctrH1);
    ctr2 = (ctr2 << 16) | ctrL;
}

{
 volatile u16 *regL;
 volatile u16 *regH;
    regH = base + 0x27;
    ctr3 = base[0x27];
    regL = base + 0x26;
    do {
        ctrH1 = ctr3;
        ctrL = *regL;
        ctr3 = *regH;
    } while (ctr3 != ctrH1);
    ctr3 = (ctr3 << 16) | ctrL;
}

    switch (M2C_FIELD(__GXData, s32 *, 0x59C)) {
    case 10:
        *cnt0 = ctr1 * 1000 / ctr0;
        break;
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
    case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
    case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30:
    case 31: case 32: case 33: case 34:
        *cnt0 = ctr0;
        break;
    case 35:
        *cnt0 = 0;
        break;
    default:
        *cnt0 = 0;
        break;
    }

    switch (M2C_FIELD(__GXData, s32 *, 0x5A0)) {
    case 0:
        *cnt1 = ctr3 * 4;
        break;
    case 4:
        *cnt1 = ctr2 + ctr3 * 2;
        break;
    case 5:
        *cnt1 = ctr2 * 3 + ctr3 * 4;
        break;
    case 6:
        *cnt1 = ctr2 * 5 + ctr3 * 6;
        break;
    case 7:
        *cnt1 = ctr2 * 7 + ctr3 * 8;
        break;
    case 1: case 2: case 3:
    case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
    case 21:
        *cnt1 = ctr3;
        break;
    case 17: case 18: case 19: case 20:
        *cnt1 = ctr2;
        break;
    case 22:
        *cnt1 = 0;
        break;
    default:
        *cnt1 = 0;
        break;
    }
}
#pragma scheduling reset
#pragma global_optimizer reset
void fn_80225BF4(void) {
    extern u16 *__cpReg;
    M2C_FIELD(__cpReg, s16 *, 4) = 4;
}

void fn_80225C04(u32 *top_pixels_in, u32 *top_pixels_out, u32 *bot_pixels_in, u32 *bot_pixels_out, u32 *clear_pixels_in, u32 *copy_clks) {
    *top_pixels_in = __GXReadPECounterU32(0xC, 0xD) * 4;
    *top_pixels_out = __GXReadPECounterU32(0xE, 0xF) * 4;
    *bot_pixels_in = __GXReadPECounterU32(0x10, 0x11) * 4;
    *bot_pixels_out = __GXReadPECounterU32(0x12, 0x13) * 4;
    *clear_pixels_in = __GXReadPECounterU32(0x14, 0x15) * 4;
    *copy_clks = __GXReadPECounterU32(0x16, 0x17);
}

void fn_80225D3C(void)
{
  extern u16 *__GXData;
  u8 cmd = 0x61;
  u16 *gx;
  u32 a = 0x57000000;
  GXWGFifo.u8 = cmd;
  GXWGFifo.u32 = a;
  GXWGFifo.u8 = cmd;
  GXWGFifo.u32 = a + 0xAAA;
  __GXData[1] = 0;
}

void fn_80225D6C(u32 *arg0, u32 *arg1, u32 *arg2, u32 *arg3) {
    *arg2 = __GXReadCPCounterU32(32, 33);
    *arg3 = __GXReadCPCounterU32(34, 35);
    *arg0 = __GXReadCPCounterU32(36, 37);
    *arg1 = __GXReadCPCounterU32(38, 39);
}
