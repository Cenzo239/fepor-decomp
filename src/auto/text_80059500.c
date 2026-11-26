/* Functions from 0x80055C74 to 0x8005A29C, found by decomp-toolkit. */
#include "common.h"

void *Process_CreateChild(void *, s32, void *);             /* extern */
s32 strcpy(void *, s32);                       /* extern */
extern u16 lbl_80285BD0[16];
extern const f64 lbl_80369160;    /* 0.5 double constant, .sdata2 */

static inline f64 HalfD(f32 a, f32 b) { return (f64)(a - b) * lbl_80369160; }

#pragma optimization_level reset

/* Free up/down scroll arrows; if create, alloc new ones (kinds 8 and 4). */

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern u8 Proc_GActorNodeLink[16];

/* Create a process that links two named nodes on a GActor; assert if either is missing. */

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma scheduling on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma optimization_level reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma optimization_level 3

f32 Math_Hermite(f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4)
{
  extern f32 lbl_80369104;
  extern const f32 lbl_8036912C;
  extern f32 lbl_8036915C;
  f32 t_m1;
  f32 one;
  f32 h01;
  f32 h00;
  f32 two_t;
  one = lbl_8036912C;
  two_t = lbl_80369104 * farg4;
  t_m1 = farg4 - one;
  h01 = ((lbl_8036915C - two_t) * (farg4 * farg4));
  h00 = ((one + two_t) * (t_m1 * t_m1));
  return (f32) ((((f64) ((t_m1 * farg4) * farg4)) * (((f64) (farg3 - farg1)) * 0.5)) + ((((f64) (((one - farg4) * (one - farg4)) * farg4)) * (((f64) (farg2 - farg0)) * 0.5)) + ((f64) ((h00 * farg1) + (h01 * farg2)))));
}
#pragma optimization_level reset
