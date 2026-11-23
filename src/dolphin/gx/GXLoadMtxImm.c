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
    volatile u16 *base;
    volatile u16 *regH;
    volatile u16 *regL;
    u32 ctrH0;
    u32 ctrH1;
    u32 ctrL;

    base = __peReg;
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
