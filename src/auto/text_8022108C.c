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
void GXAdjustForOverscan(const GXRenderModeObj *rmin, GXRenderModeObj *rmout, u16 hor, u16 ver) {
    u16 hor2 = (u16)(hor * 2);
    u16 ver2 = (u16)(ver * 2);
    u32 verf;
    u32 mode;

    if (rmin != rmout) {
        *rmout = *rmin;
    }

    mode = rmin->viTVmode & 3;
    rmout->fbWidth = (u16)(rmin->fbWidth - hor2);
    verf = (ver2 * rmin->efbHeight) / (u32)rmin->xfbHeight;
    rmout->efbHeight = (u16)(rmin->efbHeight - verf);
    if (rmin->xFBmode == 0 && mode == 0) {
        rmout->xfbHeight = (u16)(rmin->xfbHeight - ver2 / 2);
    } else {
        rmout->xfbHeight = (u16)(rmin->xfbHeight - ver2);
    }

    rmout->viWidth = (u16)(rmin->viWidth - hor2);
    if (mode == 1) {
        rmout->viHeight = (u16)(rmin->viHeight - ver2 * 2);
    } else {
        rmout->viHeight = (u16)(rmin->viHeight - ver2);
    }

    rmout->viXOrigin = (u16)(rmin->viXOrigin + hor);
    rmout->viYOrigin = (u16)(rmin->viYOrigin + ver);
}

void fn_802211D0(u16 arg0, u16 arg1, u16 arg2, u16 arg3)
{
  u8 *gx;
  u32 w;
  u32 zero;
  u32 new_var[2];
  u32 c49;
  gx = (u8 *) __GXData;
  zero = 0;
  w = arg2;
  *((u32 *) (gx + 0x1E0)) = zero;
  new_var[1] = arg3;
  new_var[0] = *((u32 *) (gx + 0x1E0));
  new_var[0] = __rlwimi(new_var[0], arg0, 0, 22, 31);
  *((u32 *) (gx + 0x1E0)) = new_var[0];
  c49 = 0x49;
  w -= 1;
  new_var[0] = *((u32 *) (gx + 0x1E0));
  new_var[0] = __rlwimi(new_var[0], arg1, 10, 12, 21);
  new_var[1] -= 1;
  *((u32 *) (gx + 0x1E0)) = new_var[0];
  new_var[0] = *((u32 *) (gx + 0x1E0));
  new_var[0] = __rlwimi(new_var[0], c49, 24, 0, 7);
  *((u32 *) (gx + 0x1E0)) = new_var[0];
  *((u32 *) (gx + 0x1E4)) = zero;
  new_var[0] = *((u32 *) (gx + 0x1E4));
  new_var[0] = __rlwimi(new_var[0], w, 0, 22, 31);
  *((u32 *) (gx + 0x1E4)) = new_var[0];
  new_var[0] = *((u32 *) (gx + 0x1E4));
  new_var[0] = __rlwimi(new_var[0], new_var[1], 10, 12, 21);
  *((u32 *) (gx + 0x1E4)) = new_var[0];
  new_var[0] = *((u32 *) (gx + 0x1E4));
  new_var[0] = __rlwimi(new_var[0], 0x4A, 24, 0, 7);
  *((u32 *) (gx + 0x1E4)) = new_var[0];
}

void fn_8022124C(u16 arg0, u16 arg1, u16 arg2, u16 arg3)
{
  u8 *gx;
  u32 w;
  u32 zero;
  u32 c49;
  u32 h;
  u32 reg;
  gx = (u8 *) __GXData;
  zero = 0;
  w = arg2;
  *((u32 *) (gx + 0x1F0)) = zero;
  h = arg3;
  reg = *((u32 *) (gx + 0x1F0));
  reg = __rlwimi(reg, arg0, 0, 22, 31);
  *((u32 *) (gx + 0x1F0)) = reg;
  c49 = 0x49;
  w -= 1;
  reg = *((u32 *) (gx + 0x1F0));
  reg = __rlwimi(reg, arg1, 10, 12, 21);
  h -= 1;
  *((u32 *) (gx + 0x1F0)) = reg;
  reg = *((u32 *) (gx + 0x1F0));
  reg = __rlwimi(reg, c49, 24, 0, 7);
  *((u32 *) (gx + 0x1F0)) = reg;
  *((u32 *) (gx + 0x1F4)) = zero;
  reg = *((u32 *) (gx + 0x1F4));
  reg = __rlwimi(reg, w, 0, 22, 31);
  *((u32 *) (gx + 0x1F4)) = reg;
  reg = *((u32 *) (gx + 0x1F4));
  reg = __rlwimi(reg, h, 10, 12, 21);
  *((u32 *) (gx + 0x1F4)) = reg;
  reg = *((u32 *) (gx + 0x1F4));
  reg = __rlwimi(reg, 0x4A, 24, 0, 7);
  *((u32 *) (gx + 0x1F4)) = reg;
}

void fn_802212C8(s32 arg0) {
 M2C_FIELD(__GXData, u32 *, 0x1E8) = 0;
 M2C_FIELD(__GXData, u32 *, 0x1E8) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1E8), (s32)((arg0 & 0x7FFF) << 1) >> 5, 0, 22, 31);
 M2C_FIELD(__GXData, u32 *, 0x1E8) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1E8), 0x4D, 24, 0, 7);
}

void fn_802212FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
 u32 x, y, z;
 u32 format = arg2 & 15;
 M2C_FIELD(__GXData, u8 *, 0x200) = 0;
 if (arg2 == 0x13) format = 11;
 switch(arg2) {
 case 0: case 1: case 2: case 3: case 0x26:
 M2C_FIELD(__GXData, u32 *, 0x1FC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1FC),3,15,15,16); break;
 default: M2C_FIELD(__GXData, u32 *, 0x1FC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1FC),2,15,15,16); break;
 }
 M2C_FIELD(__GXData,u8 *,0x200) = (arg2 & 0x10) == 0x10;
 M2C_FIELD(__GXData, u32 *, 0x1FC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1FC),format,0,28,28);
 format &= 7;
 fn_8022257C(arg2,arg0,arg1,&x,&y,&z);
 M2C_FIELD(__GXData, u32 *, 0x1F8) = 0;
 M2C_FIELD(__GXData, u32 *, 0x1F8) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1F8),x*z,0,22,31);
 M2C_FIELD(__GXData, u32 *, 0x1F8) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1F8),0x4D,24,0,7);
 M2C_FIELD(__GXData, u32 *, 0x1FC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1FC),arg3,9,22,22);
 M2C_FIELD(__GXData, u32 *, 0x1FC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1FC),format,4,25,27);
}

void fn_8022142C(u32 arg0) {
    M2C_FIELD(__GXData, u32 *, 0x1EC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1EC), arg0, 12, 18, 19);
    M2C_FIELD(__GXData, u32 *, 0x1FC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1FC), 0, 12, 18, 19);
}

void fn_80221450(u32 arg0) {
    u8 flag0 = ((arg0 & 1) == 1);
    u8 flag1 = ((arg0 & 2) == 2);
    M2C_FIELD(__GXData, u32 *, 0x1EC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1EC), flag0, 0, 31, 31);
    M2C_FIELD(__GXData, u32 *, 0x1EC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1EC), flag1, 1, 30, 30);
    M2C_FIELD(__GXData, u32 *, 0x1FC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1FC), flag0, 0, 31, 31);
    M2C_FIELD(__GXData, u32 *, 0x1FC) = __rlwimi(M2C_FIELD(__GXData, u32 *, 0x1FC), flag1, 1, 30, 30);
}

#pragma use_lmw_stmw on
extern f64 lbl_8036BCD8;
extern f32 lbl_8036BCD0;
s32 __cvt_fp2unsigned(f32);
#pragma use_lmw_stmw on
f32 fn_802214A8(u16 efbHeight, u16 xfbHeight) {
    f64 bias;
    f32 f256;
    f32 best;
    f32 ratio;
    u32 efb;
    u32 fixed;
    u32 xfbOrig;
    u32 yScale;
    u32 save0;
    u32 efbOrig;
    u32 save1;
    u32 denom;
    u32 lines;
    u32 cmp;
    f32 tmp;
    f32 inv;

    yScale = xfbHeight;
    efb = efbHeight;
    save0 = efbHeight;
    save1 = xfbHeight;
    tmp = (f32)yScale / (f32)efb;
    inv = lbl_8036BCD0 / tmp;
    ratio = tmp;
    denom = (u32)__cvt_fp2unsigned(inv) & 0x1FF;
    fixed = (efb - 1) << 8;
    lines = (fixed / denom) + 1;
    if (denom > 0x80U && denom < 0x100U) {
        while ((denom & 1) == 0) {
            denom >>= 1;
        }
        if ((efb % denom) == 0) {
            lines += 1;
        }
    }
    if (lines > 0x400U) {
        lines = 0x400U;
    }
    cmp = lines;

    bias = lbl_8036BCD8;
    f256 = lbl_8036BCD0;
    xfbOrig = (u16)save1;
    efbOrig = (u16)save0;

    while (cmp > xfbOrig) {
        yScale -= 1;
        tmp = (f32)yScale / (f32)efbOrig;
        inv = f256 / tmp;
        ratio = tmp;
        denom = (u32)__cvt_fp2unsigned(inv) & 0x1FF;
        lines = (fixed / denom) + 1;
        if (denom > 0x80U && denom < 0x100U) {
            while ((denom & 1) == 0) {
                denom >>= 1;
            }
            if ((efb % denom) == 0) {
                lines += 1;
            }
        }
        if (lines > 0x400U) {
            lines = 0x400U;
        }
        cmp = lines;
    }

    best = ratio;
    bias = lbl_8036BCD8;
    f256 = lbl_8036BCD0;
    efbOrig = (u16)save0;

    while (cmp < xfbOrig) {
        yScale += 1;
        best = ratio;
        tmp = (f32)yScale / (f32)efbOrig;
        inv = f256 / tmp;
        ratio = tmp;
        denom = (u32)__cvt_fp2unsigned(inv) & 0x1FF;
        lines = (fixed / denom) + 1;
        if (denom > 0x80U && denom < 0x100U) {
            while ((denom & 1) == 0) {
                denom >>= 1;
            }
            if ((efb % denom) == 0) {
                lines += 1;
            }
        }
        if (lines > 0x400U) {
            lines = 0x400U;
        }
        cmp = lines;
    }
    return best;
}
#pragma use_lmw_stmw reset

u32 fn_802216E0(f32 scale)
{
    u32 yscale;
    u32 enabled;
    u32 reg;
    u32 height;
    u32 result;
    u32 y;

    yscale = (u32)__cvt_fp2unsigned(lbl_8036BCD0 / scale) & 511;
    enabled = 0x100 - yscale;
    GXWGFifo.u8 = 0x61;
    enabled = (enabled - 1) < enabled;
    reg = __rlwimi(0, yscale, 0, 23, 31);
    reg = __rlwimi(reg, 0x4E, 24, 0, 7);
    GXWGFifo.u32 = reg;
    __GXData[1] = 0;
    y = yscale;
    *(u32 *)((u8 *)__GXData + 0x1EC) = __rlwimi(*(u32 *)((u8 *)__GXData + 0x1EC), enabled, 10, 21, 21);
    height = ((*(u32 *)((u8 *)__GXData + 0x1E4) >> 10) & 1023) + 1;
    result = ((height - 1) << 8) / yscale + 1;
    if (yscale > 128 && yscale < 256) {
        while (!(y & 1))
            y >>= 1;
        if (height % y == 0)
            result++;
    }
    if (result > 1024)
        result = 1024;
    return result;
}

void GXSetCopyClear(u8 *clear, u32 z) {
    u32 val;

    val = 0;
    val = __rlwimi(val, clear[0], 0, 24, 31);
    val = __rlwimi(val, clear[3], 8, 16, 23);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = __rlwimi(val, 0x4F, 24, 0, 7);

    val = 0;
    val = __rlwimi(val, clear[2], 0, 24, 31);
    val = __rlwimi(val, clear[1], 8, 16, 23);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = __rlwimi(val, 0x50, 24, 0, 7);

    val = 0;
    val = __rlwimi(val, z, 0, 8, 31);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = __rlwimi(val, 0x51, 24, 0, 7);

    __GXData[1] = 0;
}

#pragma use_lmw_stmw on
void fn_80221824(u8 aa, const u8 *sp, u8 vf, const u8 *vfilt) {
    u32 reg2;
    u32 reg1;
    u32 reg3;
    u32 reg4;
    u32 reg53;
    u32 reg54;
    u32 t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
    u32 t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23;

    if (aa) {
        t6 = sp[6];
        reg2 = 0;
        t0 = sp[0];
        reg1 = 0;
        reg2 = __rlwimi(reg2, t6, 0, 28, 31);
        t12 = sp[12];
        reg1 = __rlwimi(reg1, t0, 0, 28, 31);
        reg3 = 0;
        t18 = sp[18];
        reg3 = __rlwimi(reg3, t12, 0, 28, 31);
        reg4 = 0;
        t1 = sp[1];
        reg4 = __rlwimi(reg4, t18, 0, 28, 31);
        t19 = sp[19];
        t13 = sp[13];
        reg1 = __rlwimi(reg1, t1, 4, 24, 27);
        t2 = sp[2];
        reg4 = __rlwimi(reg4, t19, 4, 24, 27);
        t7 = sp[7];
        t20 = sp[20];
        reg3 = __rlwimi(reg3, t13, 4, 24, 27);
        t14 = sp[14];
        reg1 = __rlwimi(reg1, t2, 8, 20, 23);
        t3 = sp[3];
        reg3 = __rlwimi(reg3, t14, 8, 20, 23);
        t4 = sp[4];
        reg1 = __rlwimi(reg1, t3, 12, 16, 19);
        t5 = sp[5];
        reg1 = __rlwimi(reg1, t4, 16, 12, 15);
        t8 = sp[8];
        reg2 = __rlwimi(reg2, t7, 4, 24, 27);
        t15 = sp[15];
        reg1 = __rlwimi(reg1, t5, 20, 8, 11);
        t9 = sp[9];
        t10 = sp[10];
        reg4 = __rlwimi(reg4, t20, 8, 20, 23);
        reg1 = __rlwimi(reg1, 1, 24, 0, 7);
        t21 = sp[21];
        reg2 = __rlwimi(reg2, t8, 8, 20, 23);
        t11 = sp[11];
        reg2 = __rlwimi(reg2, t9, 12, 16, 19);
        t16 = sp[16];
        reg2 = __rlwimi(reg2, t10, 16, 12, 15);
        reg3 = __rlwimi(reg3, t15, 12, 16, 19);
        t17 = sp[17];
        t22 = sp[22];
        reg3 = __rlwimi(reg3, t16, 16, 12, 15);
        reg4 = __rlwimi(reg4, t21, 12, 16, 19);
        reg4 = __rlwimi(reg4, t22, 16, 12, 15);
        t23 = sp[23];
        reg2 = __rlwimi(reg2, t11, 20, 8, 11);
        reg2 = __rlwimi(reg2, 2, 24, 0, 7);
        reg3 = __rlwimi(reg3, t17, 20, 8, 11);
        reg3 = __rlwimi(reg3, 3, 24, 0, 7);
        reg4 = __rlwimi(reg4, t23, 20, 8, 11);
        reg4 = __rlwimi(reg4, 4, 24, 0, 7);
    } else {
        reg1 = 0x01666666;
        reg2 = 0x02666666;
        reg3 = 0x03666666;
        reg4 = 0x04666666;
    }

    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = reg1;
    reg53 = __rlwimi(0, 0x53, 24, 0, 7);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = reg2;
    reg54 = __rlwimi(0, 0x54, 24, 0, 7);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = reg3;
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = reg4;

    if (vf) {
        reg53 = __rlwimi(reg53, vfilt[0], 0, 26, 31);
        reg54 = __rlwimi(reg54, vfilt[4], 0, 26, 31);
        reg53 = __rlwimi(reg53, vfilt[1], 6, 20, 25);
        reg53 = __rlwimi(reg53, vfilt[2], 12, 14, 19);
        reg54 = __rlwimi(reg54, vfilt[5], 6, 20, 25);
        reg53 = __rlwimi(reg53, vfilt[3], 18, 8, 13);
        reg54 = __rlwimi(reg54, vfilt[6], 12, 14, 19);
    } else {
        reg53 = __rlwimi(reg53, 0, 0, 26, 31);
        reg53 = __rlwimi(reg53, 0, 6, 20, 25);
        reg54 = __rlwimi(reg54, 0x15, 0, 26, 31);
        reg53 = __rlwimi(reg53, 0x15, 12, 14, 19);
        reg54 = __rlwimi(reg54, 0, 6, 20, 25);
        reg54 = __rlwimi(reg54, 0, 12, 14, 19);
        reg53 = __rlwimi(reg53, 0x16, 18, 8, 13);
    }

    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = reg53;
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = reg54;
    __GXData[1] = 0;
}
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
f32 a,b,c,t,x;
if(angle<=0.0f || angle>90.0f) mode=0;
x=cosf(3.1415927f*angle/180.0f);
switch(mode) {
case 1:a=(-1000.0f)*x;b=1000.0f;c=0.0f;break;
case 2:t=1.0f/(1.0f-x);b=t;a=-x*t;c=0.0f;break;
case 3:t=1.0f/(1.0f-x);c=t;b=-x*t;a=0.0f;break;
case 4:t=1.0f/((1.0f-x)*(1.0f-x));a=t*(x*(x-2.0f));b=2.0f*t;c=-t;break;
case 5:t=1.0f/((1.0f-x)*(1.0f-x));c=(-4.0f)*t;a=c*x;b=(4.0f*(1.0f+x))*t;break;
case 6:t=1.0f/((1.0f-x)*(1.0f-x));a=t*((2.0f*x)*x);b=(4.0f*x)*t;c=(-2.0f)*t;a=1.0f-a;break;
case 0:default:a=1.0f;c=0.0f;b=c;break;
}
obj[4]=a;obj[5]=b;obj[6]=c;
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
