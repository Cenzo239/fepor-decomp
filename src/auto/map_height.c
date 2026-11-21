/* Functions from 0x8001EEEC to 0x80028864, found by decomp-toolkit. */
#include "common.h"
#pragma cplusplus on
struct MenuSelection24768 { u8 pad[0x40]; u8 index; };
struct MenuController24768 { u32 pad;
virtual void v0() = 0;
virtual void v1() = 0;
virtual void v2() = 0;
virtual void v3() = 0;
virtual void v4() = 0;
virtual void v5() = 0;
virtual void v6() = 0;
virtual void v7() = 0;
virtual void v8() = 0;
virtual void v9() = 0;
virtual void v10() = 0;
virtual void v11(void *) = 0;
virtual void v12(void *) = 0;
virtual void v13(void *) = 0;
virtual u8 v14(void *) = 0;
virtual void v15() = 0;
virtual void v16() = 0;
virtual void v17() = 0;
virtual void v18() = 0;
virtual void v19() = 0;
virtual void v20() = 0;
virtual void v21() = 0;
virtual void v22() = 0;
virtual void v23() = 0;
virtual void v24() = 0;
virtual void v25() = 0;
virtual void v26() = 0;
virtual void * v27() = 0;
virtual void * v28() = 0;
};
struct MenuItem24768 {
virtual void v0() = 0;
virtual void v1() = 0;
virtual void * v2() = 0;
virtual void v3() = 0;
virtual void v4() = 0;
virtual void v5() = 0;
virtual void v6() = 0;
virtual void v7() = 0;
virtual void v8() = 0;
virtual void v9() = 0;
virtual void v10() = 0;
virtual void v11() = 0;
virtual void v12() = 0;
virtual void v13() = 0;
virtual void v14() = 0;
virtual void v15(void *,void *) = 0;
virtual void * v16(void *) = 0;
};
#pragma cplusplus off

typedef struct {
    s32 field_0x0;
    s32 field_0x4;
    s32 field_0x8;
    s32 field_0xC;
    s32 field_0x10;
    s32 field_0x14;
    s32 field_0x18;
    s32 field_0x1C;
    s32 field_0x20;
    s32 field_0x24;
    s32 field_0x28;
    s32 field_0x2C;
    s32 field_0x30;
    s32 field_0x34;
    s32 field_0x38;
} Actor;

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma fp_contract off
#pragma global_optimizer off

#pragma fp_contract off
#pragma global_optimizer off

const f64 lbl_80368D80 = 4503601774854144.0;

#pragma fp_contract off
#pragma global_optimizer off
f32 fn_8001F53C(void *arg0, s8 arg1, s8 arg2, s32 arg3)
{
  float new_var2;
  extern f32 lbl_80368D78;
  extern f32 lbl_80368D7C;
  void *self;
  u8 *row;
  f32 t1;
  float new_var;
  s16 *cell;
  f32 t0;
  f32 t2;
  f32 scale;
  f32 t3;
  f32 s0;
  f32 s1;
  s32 idx;
  s8 x;
  s8 y;
  self = arg0;
  x = arg1;
  y = arg2;
  switch (arg3)
  {
    case 8:
      row = ((u8 *) self) + 0x10000;
      idx = (x + (y << 6)) << 3;
      cell = (s16 *) (row + idx);
      scale = *((f32 *) (((u8 *) arg0) + 0x1C2D4));
      t0 = (f32) (*((s16 *) (((u8 *) cell) + 0x42D4)));
      t1 = (f32) (*((s16 *) (((u8 *) cell) + 0x42D6)));
      t2 = (f32) (*((s16 *) (((u8 *) cell) + 0x42D8)));
      t3 = (f32) (*((s16 *) (((u8 *) cell) + 0x42DA)));
      t0 = t0 * scale;
      t1 = t1 * scale;
      s0 = (t0 + t1) * lbl_80368D78;
      t2 = t2 * scale;
      t3 = t3 * scale;
      new_var = t2 + t3;
      s1 = new_var * lbl_80368D78;
      return s0 - s1;

    case 4:
      row = ((u8 *) self) + 0x10000;
      idx = (x + (y << 6)) << 3;
      cell = (s16 *) (row + idx);
      scale = *((f32 *) (((u8 *) arg0) + 0x1C2D4));
      t0 = (f32) (*((s16 *) (((u8 *) cell) + 0x42D8)));
      t1 = (f32) (*((s16 *) (((u8 *) cell) + 0x42DA)));
      t2 = (f32) (*((s16 *) (((u8 *) cell) + 0x42D4)));
      t3 = (f32) (*((s16 *) (((u8 *) cell) + 0x42D6)));
      t0 = t0 * scale;
      t1 = t1 * scale;
      s0 = (t0 + t1) * lbl_80368D78;
      t2 = t2 * scale;
      t3 = t3 * scale;
      s1 = (t2 + t3) * lbl_80368D78;
      return s0 - s1;

    case 1:
      row = ((u8 *) self) + 0x10000;
      idx = (x + (y << 6)) << 3;
      cell = (s16 *) (row + idx);
      scale = *((f32 *) (((u8 *) arg0) + 0x1C2D4));
      t0 = (f32) (*((s16 *) (((u8 *) cell) + 0x42D4)));
      t1 = (f32) (*((s16 *) (((u8 *) cell) + 0x42D8)));
      t2 = (f32) (*((s16 *) (((u8 *) cell) + 0x42D6)));
      t3 = (f32) (*((s16 *) (((u8 *) cell) + 0x42DA)));
      t0 = t0 * scale;
      t1 = t1 * scale;
      s0 = (t0 + t1) * lbl_80368D78;
      t2 = t2 * scale;
      t3 = t3 * scale;
      new_var2 = t2 + t3;
      s1 = new_var2 * lbl_80368D78;
      return s0 - s1;

    case 2:
      row = ((u8 *) self) + 0x10000;
      idx = (x + (y << 6)) << 3;
      cell = (s16 *) (row + idx);
      scale = *((f32 *) (((u8 *) arg0) + 0x1C2D4));
      t0 = (f32) (*((s16 *) (((u8 *) cell) + 0x42D6)));
      t1 = (f32) (*((s16 *) (((u8 *) cell) + 0x42DA)));
      t2 = (f32) (*((s16 *) (((u8 *) cell) + 0x42D4)));
      t3 = (f32) (*((s16 *) (((u8 *) cell) + 0x42D8)));
      t0 = t0 * scale;
      t1 = t1 * scale;
      s0 = (t0 + t1) * lbl_80368D78;
      t2 = t2 * scale;
      t3 = t3 * scale;
      s1 = (t2 + t3) * lbl_80368D78;
      return s0 - s1;

    default:
      return lbl_80368D7C;

  }

}
