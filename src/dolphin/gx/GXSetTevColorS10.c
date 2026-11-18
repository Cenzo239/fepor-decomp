/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
#include "structs.h"

typedef struct GXColor { u8 r, g, b, a; } GXColor;

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

// GXTexObj structure (from headers or similar functions)
typedef struct {
    u32 dummy[4];
} GXTexObj;

#pragma fp_contract off

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

extern u16 * const __GXData;

extern u16 * const __GXData;

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

extern u16 * const __GXData;
extern u16 * const __GXData;
extern u16 * const __GXData;
extern u16 * const __GXData;
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
#include "structs.h"

extern u16 * const __GXData;
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
#include "structs.h"

extern u16 * const __GXData;
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
#include "structs.h"

extern u16* lbl_80368790;
extern u16* __peReg;
extern u16 * const __GXData;

#pragma optimization_level 2

#pragma optimization_level reset
void fn_80222644(void *, void *, u16, u16, s32, s32, s32, u8);

/* Pack LOD / filter / anisotropy fields into a GXTexObj. */

#pragma optimization_level 3

#pragma optimization_level reset

#pragma global_optimizer off
#pragma opt_strength_reduction off

#pragma opt_strength_reduction on
#pragma global_optimizer on

#pragma optimization_level 3

#pragma optimization_level reset

#pragma optimization_level 3

#pragma optimization_level reset

#pragma scheduling off

#pragma scheduling reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma scheduling off

void fn_80223C14(s32 id, u32 *color)
{
  u16 *gx;
  u8 cmd;
  u32 idx;
  u32 b;
  u32 reg;
  u32 a;
  a = color[0];
  idx = id << 1;
  cmd = 0x61;
  gx = (u16 *) (idx + 0xE0);
  reg = ((u32) gx) << 24;
  b = color[1];
  gx = __GXData;
  reg = __rlwimi(reg, a, 16, 21, 31);
  GXWGFifo.u8 = cmd;
  reg = __rlwimi(reg, b, 12, 9, 19);
  GXWGFifo.u32 = reg;
  idx += 0xE1;
  idx <<= 24;
  idx = __rlwimi(idx, b, 16, 21, 31);
  GXWGFifo.u8 = cmd;
  idx = __rlwimi(idx, a, 12, 9, 19);
  GXWGFifo.u32 = idx;
  GXWGFifo.u8 = cmd;
  GXWGFifo.u32 = idx;
  GXWGFifo.u8 = cmd;
  GXWGFifo.u32 = idx;
  gx[1] = 0;
}
#pragma scheduling on
#pragma optimization_level 2
#pragma opt_propagation off
void fn_80223C78(s32 id, u32 *color) {
    u32 idx = id << 1;
    u32 c = *color;
    u32 a = idx + 0xe0;
    u32 lo;
    u32 hi;
    u32 eight;
    u8 cmd;
    u16 zero;

    a <<= 24;
    a = __rlwimi(a, c, 8, 24, 31);
    lo = a;
    cmd = 0x61;
    GXWGFifo.u8 = cmd;
    hi = idx + 0xe1;
    hi <<= 24;
    hi = __rlwimi(hi, c, 24, 24, 31);
    eight = 8;
    lo = __rlwimi(lo, c, 12, 12, 19);
    lo = __rlwimi(lo, eight, 20, 8, 11);
    GXWGFifo.u32 = lo;
    hi = __rlwimi(hi, c, 28, 12, 19);
    hi = __rlwimi(hi, eight, 20, 8, 11);
    GXWGFifo.u8 = cmd;
    zero = 0;
    GXWGFifo.u32 = hi;
    __GXData[1] = zero;
}
#pragma opt_propagation reset
#pragma optimization_level reset
void fn_80223CDC(s32 arg0, s32 arg1) {
    u8 cmd;
    u16 *gx;
    u32 *reg;

    gx = __GXData;
    reg = (u32 *)((u8 *)gx + (arg0 >> 1) * 4 + 0x1B0);
    if (arg0 & 1) {
        *reg = __rlwimi(*reg, arg1, 14, 13, 17);
    } else {
        *reg = __rlwimi(*reg, arg1, 4, 23, 27);
    }
    cmd = 0x61;
    GXWGFifo.u8 = cmd;
    GXWGFifo.u32 = *reg;
    __GXData[1] = 0;
}

void fn_80223D38(s32 arg0, s32 arg1) {
    u8 cmd;
    u16 *gx;
    u32 *reg;

    gx = __GXData;
    reg = (u32 *)((u8 *)gx + (arg0 >> 1) * 4 + 0x1B0);
    if (arg0 & 1) {
        *reg = __rlwimi(*reg, arg1, 19, 8, 12);
    } else {
        *reg = __rlwimi(*reg, arg1, 9, 18, 22);
    }
    cmd = 0x61;
    GXWGFifo.u8 = cmd;
    GXWGFifo.u32 = *reg;
    __GXData[1] = 0;
}

void GXSetTevSwapMode(s32 arg0, s32 arg1, s32 arg2) {
    u8 *gx = (u8 *)__GXData;
    u32 *reg = (u32 *)(gx + arg0 * 4 + 0x170);
    *reg = __rlwimi(*reg, arg1, 0, 30, 31);
    *reg = __rlwimi(*reg, arg2, 2, 28, 29);
    *(volatile u8 *)0xCC008000 = 0x61;
    *(volatile u32 *)0xCC008000 = *reg;
    *(u16 *)(gx + 2) = 0;
}

void GXSetTevSwapModeTable(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *gx;
    s32 idx2;
    u32 *reg;
    u32 *reg2;
    u8 cmd;

    idx2 = arg0 << 1;
    gx = (u8 *)__GXData;
    reg = (u32 *)(gx + idx2 * 4 + 0x1B0);
    *reg = __rlwimi(*reg, arg1, 0, 30, 31);
    reg2 = (u32 *)(gx + (idx2 + 1) * 4 + 0x1B0);
    *reg = __rlwimi(*reg, arg2, 2, 28, 29);
    cmd = 0x61;
    GXWGFifo.u8 = cmd;
    GXWGFifo.u32 = *reg;
    *reg2 = __rlwimi(*reg2, arg3, 0, 30, 31);
    *reg2 = __rlwimi(*reg2, arg4, 2, 28, 29);
    GXWGFifo.u8 = cmd;
    GXWGFifo.u32 = *reg2;
    *(u16 *)(gx + 2) = 0;
}

void fn_80223E5C(s32 arg0,u8 arg1,s32 arg2,s32 arg3,u8 arg4) {

u32 v=__rlwimi(0xF3000000,(u32)arg1,0,24,31);
v=__rlwimi(v,(u32)arg4,8,16,23);
v=__rlwimi(v,arg0,16,13,15);
v=__rlwimi(v,arg3,19,10,12);
v=__rlwimi(v,arg2,22,8,9);
GXWGFifo.u8=0x61;
GXWGFifo.u32=v;
__GXData[1]=0;
}

void fn_80223EA0(s32 arg0, s32 arg1, s32 arg2) {
    u32 value = 0;
    u32 format;
    u32 mode = 0;
    u16 *gx;
    u8 cmd;
    value = __rlwimi(value, arg2, 0, 8, 31);
    value = __rlwimi(value, 0xF4, 24, 0, 7);
    switch (arg1) {
    case 17: format=0; break;
    case 19: format=1; break;
    case 22: format=2; break;
    default: format=2; break;
    }
    cmd=0x61;
    gx=__GXData;
    GXWGFifo.u8=cmd;
    mode=__rlwimi(__rlwimi(mode,format,0,30,31),arg0,2,28,29);
    GXWGFifo.u32=value;
    mode = (mode & 0x00FFFFFF) | 0xF5000000;
    GXWGFifo.u8=cmd;
    GXWGFifo.u32=mode;
    gx[1]=0;
}

void GXSetTevOrder(s32 stage, s32 coord, s32 map, s32 color) {
    extern u32 lbl_8029E330[];
    u8 *gx;
    u32 *used;
    u32 raw;
    u32 tex;
    u32 *reg;
    u32 channel;
    s32 enable;
    reg = (u32 *)((u8 *)__GXData + 0x100 + (stage / 2) * 4);
    ((u32 *)((u8 *)__GXData + 0x554))[stage] = map;
    raw = map & ~0x100;
    tex = raw >= 8 ? 0 : raw;
    if (coord >= 8) {
        used=(u32 *)__GXData;
        *(used += 0x598/4) &= ~(1 << stage);
        coord=0;
    } else {
        used=(u32 *)__GXData;
        *(used += 0x598/4) |= 1 << stage;
    }
    if (stage & 1) {
        *reg=__rlwimi(*reg,tex,12,17,19);
        *reg=__rlwimi(*reg,coord,15,14,16);
        channel=(color==255) ? 7 : lbl_8029E330[color];
        *reg=__rlwimi(*reg,channel,19,10,12);
        enable=map!=255 && !(map & 0x100);
        *reg=__rlwimi(*reg,enable,18,13,13);
    } else {
        *reg=__rlwimi(*reg,tex,0,29,31);
        *reg=__rlwimi(*reg,coord,3,26,28);
        channel=(color==255) ? 7 : lbl_8029E330[color];
        *reg=__rlwimi(*reg,channel,7,22,24);
        enable=map!=255 && !(map & 0x100);
        *reg=__rlwimi(*reg,enable,6,25,25);
    }
    GXWGFifo.u8=0x61;
    GXWGFifo.u32=*reg;
    gx=(u8 *)__GXData;
    *(u16 *)(gx+2)=0;
    *(u32 *)(gx+0x5AC) |= 1;
}

void GXSetNumTevStages(u8 arg0) {
    u32 *gxData = (u32 *)__GXData;
    gxData[0x204 / 4] = __rlwimi(gxData[0x204 / 4], (u32)arg0 - 1, 10, 18, 21);
    gxData[0x5AC / 4] |= 4;
}
