/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
#include "structs.h"

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

u32 GXGetTexBufferSize(u16 width, u16 height, u32 fmt, u8 mipmap, u8 maxlod)
{
    s32 shiftW, shiftH;
    u32 size, tile, i;
    s32 tilesW, tilesH;
    switch(fmt) {
    case 0: case 8: case 14: case 0x20: case 0x30: shiftW=3; shiftH=3; break;
    case 1: case 2: case 9: case 0x11: case 0x22: case 0x25: case 0x26: case 0x27: case 0x28: case 0x39: case 0x3A: shiftW=3; shiftH=2; break;
    case 3: case 4: case 5: case 6: case 10: case 0x13: case 0x16: case 0x23: case 0x29: case 0x2A: case 0x3C: shiftW=2; shiftH=2; break;
    default: shiftH=0; shiftW=0; break;
    }
    if(fmt==6 || fmt==0x16) tile=64; else tile=32;
    if(mipmap==1) {
        size=0;
        for(i=0;i<maxlod;i++) {
            tilesW=(width+(1<<shiftW)-1)>>shiftW;
            tilesH=(height+(1<<shiftH)-1)>>shiftH;
            size+=tile*(tilesW*tilesH);
            if(width==1 && height==1) break;
            width=width>1?width>>1:1;
            height=height>1?height>>1:1;
        }
    } else {
        tilesW=(width+(1<<shiftW)-1)>>shiftW;
        tilesH=(height+(1<<shiftH)-1)>>shiftH;
        size=tile*(tilesW*tilesH);
    }
    return size;
}

#pragma optimization_level 2
#pragma push
#pragma optimization_level 4
typedef enum _GXTexFmt {
    GX_TF_I4 = 0x0,
    GX_TF_I8 = 0x1,
    GX_TF_IA4 = 0x2,
    GX_TF_IA8 = 0x3,
    GX_TF_RGB565 = 0x4,
    GX_TF_RGB5A3 = 0x5,
    GX_TF_RGBA8 = 0x6,
    GX_TF_CMPR = 0xE,
    GX_CTF_R4 = 0x0 | 0x20,
    GX_CTF_RA4 = 0x2 | 0x20,
    GX_CTF_RA8 = 0x3 | 0x20,
    GX_CTF_YUVA8 = 0x6 | 0x20,
    GX_CTF_A8 = 0x7 | 0x20,
    GX_CTF_R8 = 0x8 | 0x20,
    GX_CTF_G8 = 0x9 | 0x20,
    GX_CTF_B8 = 0xA | 0x20,
    GX_CTF_RG8 = 0xB | 0x20,
    GX_CTF_GB8 = 0xC | 0x20,
    GX_TF_Z8 = 0x1 | 0x10,
    GX_TF_Z16 = 0x3 | 0x10,
    GX_TF_Z24X8 = 0x6 | 0x10,
    GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    GX_TF_A8 = GX_CTF_A8,
} GXTexFmt;
static void __GXGetTexTileShift(GXTexFmt fmt, u32 *rowTileS, u32 *colTileS) {
    switch (fmt) {
    case GX_TF_I4:
    case 0x8:
    case GX_TF_CMPR:
    case GX_CTF_R4:
    case GX_CTF_Z4:
        *rowTileS = 3;
        *colTileS = 3;
        break;
    case GX_TF_I8:
    case GX_TF_IA4:
    case 0x9:
    case GX_TF_Z8:
    case GX_CTF_RA4:
    case GX_TF_A8:
    case GX_CTF_R8:
    case GX_CTF_G8:
    case GX_CTF_B8:
    case GX_CTF_Z8M:
    case GX_CTF_Z8L:
        *rowTileS = 3;
        *colTileS = 2;
        break;
    case GX_TF_IA8:
    case GX_TF_RGB565:
    case GX_TF_RGB5A3:
    case GX_TF_RGBA8:
    case 0xA:
    case GX_TF_Z16:
    case GX_TF_Z24X8:
    case GX_CTF_RA8:
    case GX_CTF_RG8:
    case GX_CTF_GB8:
    case GX_CTF_Z16L:
        *rowTileS = 2;
        *colTileS = 2;
        break;
    default:
        *rowTileS = *colTileS = 0;
        break;
    }
}
void fn_8022257C(s32 fmt_, u16 wd, u16 ht, u32 * rowTiles, u32 * colTiles, u32 * cmpTiles) {
    GXTexFmt fmt = (GXTexFmt)fmt_;
    u32 texRowShift;
    u32 texColShift;
    __GXGetTexTileShift(fmt, &texRowShift, &texColShift);
    if (wd == 0) {
        wd = 1;
    }
    if (ht == 0) {
        ht = 1;
    }
    *rowTiles = (wd + (1 << texRowShift) - 1) >> texRowShift;
    *colTiles = (ht + (1 << texColShift) - 1) >> texColShift;
    *cmpTiles = (fmt == GX_TF_RGBA8 || fmt == GX_TF_Z24X8) ? 2 : 1;
}
#pragma pop

#pragma push
#pragma optimization_level 4
#pragma opt_lifetimes off
void fn_80222644(void *obj, void *image, u16 width, u16 height, s32 format, s32 wrapS, s32 wrapT, u8 mipmap)
{
  u32 *p = obj;
  u16 shiftW;
  u16 shiftH;
  u32 lod;
  int new_var2;
  int new_var;
  memset(obj, 0, 32);
  p[0] = __rlwimi(p[0], wrapS, 0, 30, 31);
  p[0] = __rlwimi(p[0], wrapT, 2, 28, 29);
  p[0] = __rlwimi(p[0], 1, 4, 27, 27);
  if (mipmap)
  {
    ((u8 *) obj)[31] |= 1;
    if (((u32) (format - 8)) <= 2)
    {
      p[0] = __rlwimi(p[0], 5, 5, 24, 26);
    }
    else
    {
      p[0] = __rlwimi(p[0], 6, 5, 24, 26);
    }
    if (width > height)
    {
      lod = ((0, 31)) - __cntlzw(width);
    }
    else
    {
      lod = 31 - __cntlzw(height);
    }
    p[1] = __rlwimi(p[1], (s32) (16.0f * lod), 8, 16, 23);
  }
  else
  {
    p[0] = __rlwimi(p[0], 4, 5, 24, 26);
  }
  p[5] = format;
  new_var2 = height - 1;
  p[2] = __rlwimi(p[2], width - 1, 0, 22, 31);
  p[2] = __rlwimi(p[2], new_var2, 10, 12, 21);
  new_var = 28;
  p[2] = __rlwimi(p[2], format, 20, 8, 11);
  p[3] = __rlwimi(p[3], (u32) image, 27, 11, 31);
  switch (format & 15)
  {
    case 0:

    case 8:
      ((u8 *) obj)[30] = 1;
      shiftW = 3;
      shiftH = 3;
      break;

    case 1:

    case 2:

    case 9:
      ((u8 *) obj)[30] = 2;
      shiftW = 3;
      shiftH = 2;
      break;

    case 3:

    case 4:

    case 5:

    case 10:
      p = obj;
      ((u8 *) p)[30] = 2;
      shiftW = 2;
      shiftH = 2;
      break;

    case 6:
      ((u8 *) p)[30] = 3;
      shiftW = 2;
      shiftH = 2;
      break;

    case 14:
      ((u8 *) p)[30] = 0;
      shiftW = 3;
      shiftH = 3;
      break;

    default:
      ((u8 *) p)[30] = 2;
      shiftW = 2;
      shiftH = 2;
      break;

  }

  *((u16 *) (((u8 *) p) + new_var)) = ((((width + (1 << shiftW)) - 1) >> shiftW) * (((height + (1 << shiftH)) - 1) >> shiftH)) & 0x7fff;
  ((u8 *) p)[31] |= 2;
}
#pragma pop
void fn_80222644(void *, void *, u16, u16, s32, s32, s32, u8);
void GXInitTexObjCI(void *obj, void *image_ptr, u16 width, u16 height,
                 s32 format, s32 wrap_s, s32 wrap_t, u8 mipmap, u32 tlut_name)
{
    fn_80222644(obj, image_ptr, width, height, format, wrap_s, wrap_t, mipmap);
    *(u8 *)((char *)obj + 0x1F) = (u8)(*(u8 *)((char *)obj + 0x1F) & ~2);
    *(u32 *)((char *)obj + 0x18) = tlut_name;
}

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

