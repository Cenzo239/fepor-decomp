/* Functions from 0x80006264 to 0x80011968, found by decomp-toolkit. */
#include "common.h"
#include "process.h"

typedef struct {
    void *unk0;
    void *unk4;
    s32 unk8;
} Struct_8000B090;

extern s32 lbl_802AEE20[5]; // array of 5 pointers
extern f64 lbl_80368C28;    // global float constant
extern u16 jumptable_80283AE8[];

#pragma optimization_level 2

#pragma optimization_level reset

#pragma opt_unroll off

#pragma global_optimizer reset

#pragma global_optimizer on
#pragma opt_strength_reduction on

#pragma optimization_level 4
#pragma scheduling on

#pragma scheduling reset
#pragma optimization_level reset

s64 fn_80006798(void) {
    extern u32 lbl_80367120;
    extern u32 lbl_80367124;
    extern u32 lbl_80367128;
    extern u32 lbl_8036712C;
    s64 prev;
    s64 cur;

    cur = lbl_8036712C;
    prev = lbl_80367124;
    cur |= (s64)lbl_80367128 << 32;
    prev |= (s64)lbl_80367120 << 32;
    return cur - prev;
}

s32 Game_GetFrameCount(void) {
    extern s32 gFrameCount;
    return gFrameCount;
}

#pragma push
#pragma optimization_level 3
#pragma opt_common_subs off
f32 Math_Ease(s32 mode, f32 start, f32 end, f32 time, f32 duration)
{
  extern f32 lbl_80368B68;
  extern f32 lbl_80368B6C;
  extern f32 lbl_80368B70;
  extern f32 lbl_80368B74;
  extern f32 lbl_80368B78;
  extern f32 lbl_80368B7C;
  extern f32 lbl_80368B80;
  extern f32 lbl_80368B84;
  f64 fn_802380D0(f64);
  f64 sin(f64);
  f32 f4;
  f32 f3;
  f32 f2;
  float new_var;
  f32 f1;
  f32 f0;
  f32 new_var2;
  if (lbl_80368B68 == duration)
  {
    return end;
  }
  switch (mode)
  {
    case 0:
      f0 = end - start;
      f0 = time * f0;
      f0 = f0 / duration;
      return start + f0;
      if (!f1)
    {
    }

    case 1:
      f1 = time * time;
      f2 = end - start;
      f0 = duration * duration;
      f2 = f1 * f2;
      f0 = f2 / f0;
      return start + f0;

    case 2:
      f2 = time * time;
      f0 = duration * duration;
      f1 = end - start;
      f2 = time * f2;
      f0 = duration * f0;
      f1 = f2 * f1;
      f0 = f1 / f0;
      return start + f0;

    case 3:
      f2 = time * time;
      f0 = duration * duration;
      f1 = end - start;
      f2 = time * f2;
      f0 = duration * f0;
      f2 = time * f2;
      f0 = duration * f0;
      f1 = f2 * f1;
      f0 = f1 / f0;
      return start + f0;

    case 4:
      f2 = (f32) fn_802380D0(lbl_80368B6C * (lbl_80368B70 * (time / duration)));
      f1 = end - start;
      f3 = duration - time;
      f0 = duration * duration;
      f1 = f1 * f2;
      f1 = f3 * f1;
      f1 = f3 * f1;
      f0 = f1 / f0;
      return end - f0;

    case 5:
      f2 = (f32) fn_802380D0(lbl_80368B6C * (lbl_80368B70 * (time * time / duration)) / lbl_80368B74);
      f1 = end - start;
      f3 = duration - time;
      f0 = duration * duration;
      f1 = f1 * f2;
      f1 = f3 * f1;
      f1 = f3 * f1;
      f0 = f1 / f0;
      return end - f0;

    case 6:
      f1 = duration - time;
      f3 = end - start;
      f0 = duration * duration;
      f1 = f1 * f1;
      f2 = start + f3;
      f1 = f1 * f3;
      f0 = f1 / f0;
      return f2 - f0;

    case 7:
      f4 = duration - time;
      f3 = end - start;
      f0 = duration * duration;
      f1 = f4 * f4;
      f2 = start + f3;
      f0 = duration * f0;
      f1 = f4 * f1;
      f1 = f1 * f3;
      ;
      return f2 - (f1 / f0);

    case 8:
      f4 = duration - time;
      f0 = duration * duration;
      f3 = end - start;
      f1 = f4 * f4;
      f0 = duration * f0;
      f2 = start + f3;
      f1 = f4 * f1;
      f0 = duration * f0;
      f1 = f4 * f1;
      f1 = f1 * f3;
      ;
      return f2 - (f1 / f0);

    case 9:
      f2 = (f32) fn_802380D0(lbl_80368B6C * (lbl_80368B70 * (time * time / duration)) / lbl_80368B78);
      f3 = duration - time;
      f1 = duration * duration;
      f2 = f3 * f2;
      f2 = f3 * f2;
      f1 = f2 / f1;
      if (f1 < lbl_80368B68) {
        f1 = -f1;
      }
      return end - (f1 * (end - start));

    case 10:
      f0 = lbl_80368B70 * time;
      f1 = f0 / duration;
      f3 = (f32) fn_802380D0(f1);
      f1 = lbl_80368B7C - f3;
      f2 = end - start;
      f0 = lbl_80368B80;
      f1 = f2 * f1;
      return start + (f1 * f0);

    case 11:
      f0 = lbl_80368B84 * time;
      f1 = f0 / duration;
      f1 = (f32) sin(f1);
      f0 = end - start;
      return start + (f0 * f1);

    case 12:
      f0 = lbl_80368B84 * time;
      f1 = f0 / duration;
      f2 = (f32) fn_802380D0(f1);
      f0 = lbl_80368B7C - f2;
      f1 = end - start;
      return start + (f1 * f0);

  }

  return lbl_80368B68;
}
#pragma pop
