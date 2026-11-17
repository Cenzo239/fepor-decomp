/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"
#include <dolphin/os.h>
extern s32 gSaveDataBase;
extern s32 fn_80013E50(s32);
extern s32 fn_80013E60(s32, s32);
extern s32 fn_80013E74(void*, s32);

// From Dolphin SDK's vec.c, handwritten PSVECCrossProduct function
static void PSVECCrossProduct(f32 *a, f32 *b, f32 *out) {
    f32 temp[4];
    temp[0] = a[1] * b[2] - a[2] * b[1];
    temp[1] = a[2] * b[0] - a[0] * b[2];
    temp[2] = a[0] * b[1] - a[1] * b[0];
    temp[3] = 0.0f;
    out[0] = temp[0];
    out[1] = temp[1];
    out[2] = temp[2];
    out[3] = temp[3];
}


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
#include "common.h"
#include <dolphin/os.h>
extern s32 gSaveDataBase;
extern s32 fn_80015A14(void);
#include "common.h"
#include <dolphin/os.h>
extern s32 gFallingParticleVelY;
extern s32 gFallingParticleVelXCenter;
extern s32 gFallingParticleVelYCenter;
extern s32 gFallingParticleVelXRange;
extern s32 gFallingParticleVelYRange;
extern u8 gFallingParticleAlphaMin;
extern u8 gFallingParticleAlphaMax;
extern f32 gFloatZero;
extern f32 gFloatOne;

#pragma peephole off
void PSMTXRotRad(void *m, s32 axis, f32 rad) {
    f32 sinf(f32);
    f32 cosf(f32);
    void fn_80202370(void *, s32, f32, f32);
    f32 s;
    f32 c;

    s = sinf(rad);
    c = cosf(rad);
    fn_80202370(m, axis, s, c);
}
#pragma peephole on
f32 fn_80202370(s32 arg1, f64 farg0, f64 farg1) {
    extern f32 lbl_8036BC38;
    u32 temp_r0;

    temp_r0 = arg1 | 0x20;
    M2C_ERROR(/* unknown instruction: ps_neg $f2, $f5 */);
    switch (temp_r0) {                              /* irregular */
    case 0x78:
        M2C_ERROR(/* unknown instruction: ps_merge00 $f3, $f5, $f4 */);
        return M2C_ERROR(/* unknown instruction: ps_merge00 $f1, $f4, $f2 */);
    case 0x79:
        M2C_ERROR(/* unknown instruction: ps_merge00 $f3, $f4, $f0 */);
        M2C_ERROR(/* unknown instruction: ps_merge00 $f2, $f2, $f0 */);
        M2C_ERROR(/* unknown instruction: ps_merge00 $f0, $f5, $f0 */);
        return M2C_ERROR(/* unknown instruction: ps_merge00 $f1, $f0, $f1 */);
    case 0x7A:
        M2C_ERROR(/* unknown instruction: ps_merge00 $f3, $f5, $f4 */);
        M2C_ERROR(/* unknown instruction: ps_merge00 $f2, $f4, $f2 */);
        return M2C_ERROR(/* unknown instruction: ps_merge00 $f1, $f1, $f0 */);
    default:
        return lbl_8036BC38;
    }
}

void fn_80202420(f32 *m, f32 *axis, f32 s, f32 c) {
    extern f32 lbl_8036BC40;
    extern f32 lbl_8036BC44;
    f32 x, y, z, xx, yy, zz, xy, xz, yz, len, inv;
    f32 t, cs;

    x = axis[0];
    y = axis[1];
    z = axis[2];
    len = x * x + y * y + z * z;
    inv = 1.0f / (f32)__frsqrte(len);
    (void)lbl_8036BC40;
    (void)lbl_8036BC44;
    x *= inv;
    y *= inv;
    z *= inv;
    t = 1.0f - c;
    xx = t * x * x;
    yy = t * y * y;
    zz = t * z * z;
    xy = t * x * y;
    xz = t * x * z;
    yz = t * y * z;
    cs = c;
    m[0] = xx + cs;
    m[1] = xy - z * s;
    m[2] = xz + y * s;
    m[3] = xy + z * s;
    m[4] = yy + cs;
    m[5] = yz - x * s;
    m[6] = xz - y * s;
    m[7] = yz + x * s;
    m[8] = zz + cs;
}

#pragma peephole off
void fn_802024D0(s32 arg0, s32 arg1, f32 rad) {
    f32 sinf(f32);
    f32 cosf(f32);
    void fn_80202420(s32, s32, f32, f32);
    f32 s;
    f32 c;
    s = sinf(rad);
    c = cosf(rad);
    fn_80202420(arg0, arg1, s, c);
}
#pragma peephole reset
