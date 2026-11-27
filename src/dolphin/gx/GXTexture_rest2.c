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

#pragma peephole on

#pragma peephole on

#pragma peephole on

#pragma peephole reset

#pragma opt_propagation on

void fn_80224860(u8 arg0, u8 arg1)
{
  extern u16 *__GXData;
  u16 *gx;
  u32 value;
  u8 cmd;
  gx = __GXData;
  value = *((u32 *) (((u8 *) gx) + 0x7c));
  value = __rlwimi(value, arg1, 22, 9, 9);
  *((u32 *) (((u8 *) __GXData) + 0x7c)) = value;
  cmd = 0x61;
  GXWGFifo.u8 = cmd;
  GXWGFifo.u32 = *((u32 *) (((u8 *) gx) + 0x7c));
  __GXFlushTextureState();
  GXWGFifo.u8 = cmd;
  GXWGFifo.u32 = ((u32) arg0) | 0x68000000;
  __GXFlushTextureState();
}

#pragma global_optimizer off
#pragma push
#pragma peephole off
void fn_802248D8(u32 base, u32 size) {
    extern u8 lbl_8033AA70[];
    extern void *lbl_803687A8;
    void *fn_8021F4CC(void);
    void fn_80220D6C(void);
    void fn_8021F06C(void *);
    void GXSetCPUFifo(void *);
    void fn_80220554(void);
    void *memcpy(void *, const void *, u32);
    u8 *save;
    void *fifo;
    save = lbl_8033AA70;
    fifo = fn_8021F4CC();
    if (*(u32 *)((u8 *)__GXData + 0x5AC) != 0)
        fn_80220D6C();
    if (((u8 *)__GXData)[0x5A9] != 0)
        memcpy(save + 0x24, __GXData, 0x5B0);
    *(u32 *)(save + 0) = base;
    *(u32 *)(save + 4) = ((u32)base + size) - 4;
    *(u32 *)(save + 8) = size;
    *(u32 *)(save + 0x1C) = 0;
    *(u32 *)(save + 0x14) = base;
    *(u32 *)(save + 0x18) = base;
    ((u8 *)__GXData)[0x5A8] = 1;
    fn_8021F06C(fifo);
    lbl_803687A8 = fifo;
    GXSetCPUFifo(save);
    fn_80220554();
}
#pragma pop
#pragma push
#pragma optimization_level 3
s32 fn_802249A4(void) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    typedef struct { u8 bytes[0x5B0]; } SaveBuf;
    extern SaveBuf lbl_8033AA70;
    extern u32 *__piReg;
    extern void *lbl_803687A8;
    void fn_802204F8(void);
    void fn_8021F0A0(void *);
    void GXSetCPUFifo(void *);
    void *memcpy(void *, const void *, u32);
    SaveBuf *save = &lbl_8033AA70;
    u32 flag;
    s32 interrupts;
    u32 old;
    fn_802204F8();
    flag = (__piReg[5] >> 26) & 1;
    fn_8021F0A0(save);
    GXSetCPUFifo(lbl_803687A8);
    if (((u8 *)__GXData)[0x5A9] != 0) {
        interrupts = OSDisableInterrupts();
        old = *(u32 *)((u8 *)__GXData + 8);
        memcpy(__GXData, save->bytes + 0x24, 0x5B0);
        *(u32 *)((u8 *)__GXData + 8) = old;
        OSRestoreInterrupts(interrupts);
    }
    ((u8 *)__GXData)[0x5A8] = 0;
    if (flag == 0)
        return *(s32 *)(save->bytes + 0x1C);
    return 0;
}
#pragma pop
void fn_80224A68(s32 arg0, s32 arg1) {
    void fn_80220D6C(void);
    void fn_80220EBC(void);

    if (*(u32 *)((u8 *)__GXData + 0x5ac) != 0) {
        fn_80220D6C();
    }
    if (*(u32 *)__GXData == 0) {
        fn_80220EBC();
    }
    *(volatile u8 *)0xCC008000 = 0x40;
    *(volatile s32 *)0xCC008000 = arg0;
    *(volatile s32 *)0xCC008000 = arg1;
}

/* Transform a point by the model-view matrix and project it to screen space (perspective or ortho). */
void GXProject(f32 x, f32 y, f32 z, f32 mtx[3][4], f32 *pm, f32 *vp, f32 *sx, f32 *sy, f32 *sz) {
    f32 peye_x;
    f32 peye_y;
    f32 peye_z;
    f32 xc;
    f32 yc;
    f32 zc;
    f32 wc;

    peye_x = mtx[0][3] + ((mtx[0][2] * z) + ((mtx[0][0] * x) + (mtx[0][1] * y)));
    peye_y = mtx[1][3] + ((mtx[1][2] * z) + ((mtx[1][0] * x) + (mtx[1][1] * y)));
    peye_z = mtx[2][3] + ((mtx[2][2] * z) + ((mtx[2][0] * x) + (mtx[2][1] * y)));
    if (pm[0] == 0.0f) {
        xc = (peye_x * pm[1]) + (peye_z * pm[2]);
        yc = (peye_y * pm[3]) + (peye_z * pm[4]);
        zc = pm[6] + (peye_z * pm[5]);
        wc = 1.0f / -peye_z;
    } else {
        xc = pm[2] + (peye_x * pm[1]);
        yc = pm[4] + (peye_y * pm[3]);
        zc = pm[6] + (peye_z * pm[5]);
        wc = 1.0f;
    }
    *sx = (vp[2] / 2.0f) + (vp[0] + (wc * (xc * vp[2] / 2.0f)));
    *sy = (vp[3] / 2.0f) + (vp[1] + (wc * (-yc * vp[3] / 2.0f)));
    *sz = vp[5] + (wc * (zc * (vp[5] - vp[4])));
}

#pragma ppc_intrinsics on
#pragma optimization_level 3
