/* Functions from 0x80006264 to 0x80011968, found by decomp-toolkit. */
#include "common.h"
#pragma cplusplus on
struct TextWidthFontInterface {
    virtual s32 v0() = 0;
    virtual s32 v1() = 0;
    virtual s32 v2() = 0;
    virtual s32 v3() = 0;
    virtual s32 v4() = 0;
    virtual s32 v5() = 0;
    virtual s32 v6() = 0;
    virtual s32 v7() = 0;
    virtual s32 v8() = 0;
    virtual s32 v9() = 0;
    virtual s32 v10() = 0;
    virtual s32 v11() = 0;
    virtual s32 v12() = 0;
    virtual s32 v13() = 0;
};
#pragma cplusplus reset

typedef struct {
    void *unk0;
    void *unk4;
    s32 unk8;
} Struct_8000B090;

extern s32 lbl_802AEE20[5]; // array of 5 pointers
static inline s32 Text_FindFontIndex(u32 *p, u32 result) {
    s32 i;
    for(i=0;i<5;i++,p++) {
        if(*p==result) return i;
    }
    return -1;
}
extern f64 lbl_80368C28;    // global float constant
extern u16 jumptable_80283AE8[];

extern f64 lbl_80368C28;

extern u16 gPrim2D;

extern void *(*lbl_80366DA0)(s32);
extern f32 gFloat1, lbl_80368BB8, lbl_80368B98;
extern u32 gProcessOpcodeTables[9];

extern void *fn_8000A738(void *, s32);
extern void fn_8000B5F0(void *);
extern void fn_8000B70C(void *);

typedef struct HashKey {
    u32 h1;
    u32 h2;
} HashKey;

extern struct UnkStruct_802AEE80 gUnk_802AEE80;

extern s32 gUnknown_0x80369C84;
extern s32 gUnknown_0x80369C88;

#pragma push
#pragma use_lmw_stmw on
#pragma peephole on

#pragma pop

int fn_8000E7FC(int a0, int a1, int a2, int a3, int a4, int a5, float f0, float f1, float f2, float f3, float f4);

#pragma push
#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma pop

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset

extern f32 lbl_80368BDC;
extern f32 lbl_80368BE0;
extern f64 lbl_80368C20;

s32 fn_80010770(u8 *str, s32 idx, f32 scale) {
#pragma push
#pragma use_lmw_stmw on
    extern f32 lbl_80368BDC;
    extern f32 lbl_80368BE0;
    u32 *tbl;
    u32 found;
    s32 i;
    s32 result;
    f32 fmax;
    u8 *p;
    s32 c;
    s32 code;
    f32 ftmp;
    s32 rnd;

    p = str;
    if (idx == -1) {
        idx = 0;
    }
    found = (u32)fn_8010494C((void *)lbl_802AEE20[idx]);
    tbl = (u32 *)lbl_802AEE20;
    {
        u32 *q = tbl;
        s32 j;
        for (j = 0; j < 5; j++, q++) {
            if (*q == found) {
                i = j;
                goto font_found;
            }
        }
        i = -1;
    font_found:
        ;
    }

    fmax = lbl_80368BDC;
    result = 0;

    while ((s8)*p != 0) {
        c = *p;
        p++;
        if ((s8)c == '#') {
            c = (s8)*p;
            p++;
            code = c - 0x23;
            if ((((u32)code) + 1) <= (0x56U + 1)) {
                switch (code) {
                case 30:
                case 31:
                case 32:
                case 36:
                case 38:
                case 47:
                case 53:
                case 85:
                    p += 2;
                    break;
                case 45:
                    p += 3;
                    break;
                case 35: {
                    s16 shift;
                    s16 digi;
                    u8 n;
                    s32 val;
                    u8 *digits;
                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 2) {
                        c = (s8)*p++;
                        if (c >= '0' && c <= '9') {
                            digits[n] = (u8)(c - '0');
                        } else if (c >= 'a' && c <= 'f') {
                            digits[n] = (u8)(c - 0x57);
                        } else if (c >= 'A' && c <= 'F') {
                            digits[n] = (u8)(c - 0x37);
                        }
                        n += 1;
                    }
                    val = 0;
                    digi = (s16)(val + 1);
                    shift = (s16)val;
                    while (digi >= 0) {
                        val += digits[digi] << shift;
                        digi -= 1;
                        shift += 4;
                    }
                    if (val == -1) {
                        val = 0;
                    }
                    found = (u32)fn_8010494C((void *)lbl_802AEE20[val]);
                    Text_FindFontIndex(tbl, found);
                    break;
                }
                case 48:
                case 54: {
                    s16 shift;
                    s16 digi;
                    u8 n;
                    s32 val;
                    u8 *digits;
                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 2) {
                        c = (s8)*p++;
                        if (c >= '0' && c <= '9') {
                            digits[n] = (u8)(c - '0');
                        } else if (c >= 'a' && c <= 'f') {
                            digits[n] = (u8)(c - 0x57);
                        } else if (c >= 'A' && c <= 'F') {
                            digits[n] = (u8)(c - 0x37);
                        }
                        n += 1;
                    }
                    val = 0;
                    digi = (s16)(val + 1);
                    shift = (s16)val;
                    while (digi >= 0) {
                        val += digits[digi] << shift;
                        digi -= 1;
                        shift += 4;
                    }
                    ftmp = (f32)(u32)val * lbl_80368BE0;
                    if (ftmp > fmax) {
                        fmax = ftmp;
                    }
                    break;
                }
                default:
                    break;
                }
            }
        } else {
            rnd = fn_80104E40();
            ftmp = fmax * (f32)rnd * scale;
            rnd = (s32)ftmp;
            if (result < rnd) {
                result = rnd;
            }
        }
    }

    if (i == -1) {
        i = 0;
    }
    found = (u32)fn_8010494C((void *)lbl_802AEE20[i]);
    Text_FindFontIndex(tbl, found);
    return result;
#pragma pop
}

#pragma cplusplus on
extern "C" s32 Text_MeasureWidth(u8 *str, s32 idx, f32 scale)
{
  extern f32 lbl_80368BE8;
  extern f32 lbl_80368BDC;
  extern f32 lbl_80368BE0;
  extern void *lbl_80367168;
  extern u8 *fn_80105124(u8 *, s32 *);
  u32 *tbl;
  u32 found;
  s32 index;
  f32 result;
  f32 fmax;
  u8 *p;
  s32 c;
  s32 width;
  f32 advance;
  u8 flag;
  void *obj;
  u32 raw;
  p = str;
  if (idx == (-1)) { idx = 0; }
  found = (u32) fn_8010494C(lbl_802AEE20[idx]);
  tbl = (u32 *) lbl_802AEE20;
  {
    u32 *q = tbl;
    s32 j;
    for (j = 0; j < 5; j++, q++)
    {
      if ((*q) == found) { index = j; goto font_found; }
    }
    index = -1;
    font_found: ;
  }
  result = lbl_80368BE8;
  fmax = lbl_80368BDC;
  while (((s8) (raw = *p)) != 0)
  {
    flag = 0;
    if (((s8) raw) == '#')
    {
      c = (s8) p[1];
      p += 2;
      switch (c)
      {
        case 'A': case 'B': case 'C': case 'G':
        case 'I': case 'R': case 'X': case 'x':
          p += 2;
          goto next;
        case 'S': case 'Y':
        {
          s16 shift; s16 digi; u8 n; s32 val; u8 *digits; s32 z;
          digits = (u8 *) __alloca(8);
          n = 0;
          while (n < 2)
          {
            c = (s8) (*(p++));
            if ((c >= '0') && (c <= '9')) { digits[n] = (u8) (c - '0'); }
            else if ((c >= 'a') && (c <= 'f')) { digits[n] = (u8) (c - 0x57); }
            else if ((c >= 'A') && (c <= 'F')) { digits[n] = (u8) (c - 0x37); }
            n += 1;
          }
          z = 0; val = z; digi = 1; shift = z;
          while (digi >= 0)
          {
            val += digits[digi] << shift;
            digi -= 1;
            shift += 4;
          }
          fmax = ((f32) ((u32) val)) * lbl_80368BE0;
          goto next;
        }
        case 'y':
          fmax = lbl_80368BDC;
          goto next;
        default:
          p -= 1;
          break;
        case 'P':
          flag = 1;
          p += 3;
          break;
        case 'F':
        {
          s16 shift; s16 digi; u8 n; s32 val; u8 *digits; s32 z;
          digits = (u8 *) __alloca(8);
          n = 0;
          while (n < 2)
          {
            c = (s8) (*(p++));
            if ((c >= '0') && (c <= '9')) { digits[n] = (u8) (c - '0'); }
            else if ((c >= 'a') && (c <= 'f')) { digits[n] = (u8) (c - 0x57); }
            else if ((c >= 'A') && (c <= 'F')) { digits[n] = (u8) (c - 0x37); }
            n += 1;
          }
          z = 0; val = z; digi = 1; shift = z;
          while (digi >= 0)
          {
            val += digits[digi] << shift;
            digi -= 1;
            shift += 4;
          }
          if (val == (-1)) { val = 0; }
          found = (u32) fn_8010494C(lbl_802AEE20[val]);
          Text_FindFontIndex(tbl, found);
          goto next;
        }
      }
    }
    if (((u8) flag) == 0)
    {
      p = fn_80105124(p, &width);
      advance = scale * (((f32) width) * fmax);
    }
    else
    {
      obj = lbl_80367168;
      advance = (f32) ((TextWidthFontInterface *) obj)->v13();
    }
    result += advance;
    next: ;
  }
  if (index == (-1)) { index = 0; }
  found = (u32) fn_8010494C(lbl_802AEE20[index]);
  Text_FindFontIndex(tbl, found);
      return (s32) result;
  }
  #pragma peephole reset
  #pragma cplusplus reset
