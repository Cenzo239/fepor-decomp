/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"

typedef struct { f32 x, y; } FPair;
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

typedef f32 Mtx[3][4];
void PSMTXTrans(register Mtx m, register f32 xT, register f32 yT, register f32 zT) {
    register f32 c0 = 0.0f;
    register f32 c1 = 1.0f;
    asm {
stfs xT, 12(m)
stfs yT, 28(m)
psq_st c0, 4(m), 0, 0
psq_st c0, 32(m), 0, 0
stfs c0, 16(m)
stfs c1, 20(m)
stfs c0, 24(m)
stfs c1, 40(m)
stfs zT, 44(m)
stfs c1, 0(m)
    }
}

f32 fn_80202574(f64 farg0, f64 farg1, f64 farg2) {
    M2C_ERROR(/* unknown instruction: ps_sum1 $f5, $f1, $f5, $f5 */);
    M2C_ERROR(/* unknown instruction: ps_sum1 $f7, $f2, $f7, $f7 */);
    M2C_ERROR(/* unknown instruction: ps_sum1 $f8, $f3, $f8, $f8 */);
    return (f32) farg0;
}

void PSMTXScale(register Mtx m, register f32 xS, register f32 yS, register f32 zS) {
    register f32 c0 = 0.0f;
    asm {
stfs xS, 0(m)
psq_st c0, 4(m), 0, 0
psq_st c0, 12(m), 0, 0
stfs yS, 20(m)
psq_st c0, 24(m), 0, 0
psq_st c0, 32(m), 0, 0
stfs zS, 40(m)
stfs c0, 44(m)
    }
}

void fn_802025E8(f32 *src, f32 *dst, f32 x, f32 y, f32 z) {
    dst[0] = src[0] * x;
    dst[1] = src[1] * x;
    dst[2] = src[2] * y;
    dst[3] = src[3] * y;
    dst[4] = src[4] * z;
    dst[5] = src[5] * z;
}

void fn_80202640(void) {
    M2C_ERROR(/* unknown instruction: ps_mul $f6, $f4, $f4 */);
    M2C_ERROR(/* unknown instruction: ps_merge10 $f9, $f4, $f4 */);
    M2C_ERROR(/* unknown instruction: ps_madd $f8, $f5, $f5, $f6 */);
    M2C_ERROR(/* unknown instruction: ps_mul $f7, $f5, $f5 */);
    M2C_ERROR(/* unknown instruction: ps_sum0 $f3, $f8, $f8, $f8 */);
    M2C_ERROR(/* unknown instruction: ps_muls1 $f10, $f9, $f5 */);
    M2C_ERROR(/* unknown instruction: ps_sum1 $f8, $f7, $f8, $f6 */);
    M2C_ERROR(/* unknown instruction: ps_nmsub $f3, $f3, $f11, $f2 */);
    M2C_ERROR(/* unknown instruction: ps_muls1 $f7, $f5, $f5 */);
    M2C_ERROR(/* unknown instruction: ps_mul $f3, $f11, $f3 */);
    M2C_ERROR(/* unknown instruction: ps_sum0 $f6, $f6, $f6, $f6 */);
    M2C_ERROR(/* unknown instruction: ps_madd $f11, $f4, $f9, $f7 */);
    M2C_ERROR(/* unknown instruction: ps_msub $f7, $f4, $f9, $f7 */);
    M2C_ERROR(/* unknown instruction: ps_nmsub $f6, $f6, $f3, $f1 */);
    M2C_ERROR(/* unknown instruction: ps_nmsub $f8, $f8, $f3, $f1 */);
    M2C_ERROR(/* unknown instruction: ps_mul $f11, $f11, $f3 */);
    M2C_ERROR(/* unknown instruction: ps_mul $f7, $f7, $f3 */);
    M2C_ERROR(/* unknown instruction: ps_madds0 $f9, $f4, $f5, $f10 */);
    M2C_ERROR(/* unknown instruction: ps_merge00 $f5, $f11, $f8 */);
    M2C_ERROR(/* unknown instruction: ps_nmsub $f10, $f10, $f2, $f9 */);
    M2C_ERROR(/* unknown instruction: ps_merge10 $f4, $f8, $f7 */);
    M2C_ERROR(/* unknown instruction: ps_mul $f9, $f9, $f3 */);
    M2C_ERROR(/* unknown instruction: ps_mul $f10, $f10, $f3 */);
    M2C_ERROR(/* unknown instruction: ps_merge10 $f7, $f10, $f0 */);
    M2C_ERROR(/* unknown instruction: ps_merge01 $f11, $f10, $f9 */);
}

#pragma push
#pragma peephole off
void fn_802026E4(f32 *out, f32 *eye, f32 *up, f32 *target) {
    void fn_802031E8(f32 *, f32 *);
    void fn_80203290(f32 *, f32 *, f32 *);
    f32 back[3], right[3], vertical[3];
    back[0] = eye[0] - target[0];
    back[1] = eye[1] - target[1];
    back[2] = eye[2] - target[2];
    fn_802031E8(back, back);
    fn_80203290(up, back, right);
    fn_802031E8(right, right);
    fn_80203290(back, right, vertical);
    out[0] = right[0];
    out[1] = right[1];
    out[2] = right[2];
    out[3] = -((f32)(eye[2] * right[2]) + ((f32)(eye[0] * right[0]) + (f32)(eye[1] * right[1])));
    out[4] = vertical[0];
    out[5] = vertical[1];
    out[6] = vertical[2];
    out[7] = -((f32)(eye[2] * vertical[2]) + ((f32)(eye[0] * vertical[0]) + (f32)(eye[1] * vertical[1])));
    out[8] = back[0];
    out[9] = back[1];
    out[10] = back[2];
    out[11] = -((f32)(eye[2] * back[2]) + ((f32)(eye[0] * back[0]) + (f32)(eye[1] * back[1])));
}
#pragma pop
void fn_80202870(f32 *m, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    f32 fn_80238A0C(f32);
    extern f32 lbl_8036BC38, lbl_8036BC3C, lbl_8036BC40, lbl_8036BC4C, lbl_8036BC50;
    f32 t;
    f32 z;
    f32 scale;

    scale = lbl_8036BC40 * lbl_8036BC50;
    farg0 = scale * farg0;
    t = farg1;
    t = lbl_8036BC38 / fn_80238A0C(farg0);
    m[0] = farg2 * (t / farg1);
    z = lbl_8036BC3C;
    m[1] = z;
    m[2] = -farg4;
    m[3] = z;
    m[4] = z;
    m[5] = t * farg3;
    m[6] = -farg5;
    m[7] = z;
    m[8] = z;
    m[9] = z;
    m[10] = lbl_8036BC4C;
    m[11] = z;
}
#pragma scheduling on
void C_MTXLightOrtho(f32 *m, f32 t, f32 b, f32 l, f32 r, f32 sx, f32 sy, f32 tx, f32 ty)
{
  extern const f32 lbl_8036BC38;
  extern const f32 lbl_8036BC48;
  extern const f32 lbl_8036BC3C;
  f32 tmp;
  f32 tmp2;
  f32 tmp3;

  tmp = lbl_8036BC38 / (r - l);
  tmp3 = lbl_8036BC48 * tmp;
  m[0] = tmp3 * sx;
  m[1] = lbl_8036BC3C;
  m[2] = lbl_8036BC3C;
  tmp2 = sx * (tmp * -(r + l));
  m[3] = tx + tmp2;
  tmp = lbl_8036BC38 / (t - b);
  m[4] = lbl_8036BC3C;
  tmp3 = lbl_8036BC48 * tmp;
  m[5] = tmp3 * sy;
  m[6] = lbl_8036BC3C;
  tmp2 = sy * (tmp * -(t + b));
  m[7] = ty + tmp2;
  m[8] = lbl_8036BC3C;
  m[9] = lbl_8036BC3C;
  m[10] = lbl_8036BC3C;
  m[11] = lbl_8036BC38;
}
#pragma scheduling off
f32 fn_802029C4(void) {
    M2C_ERROR(/* unknown instruction: ps_mul $f4, $f2, $f0 */);
    M2C_ERROR(/* unknown instruction: ps_madd $f5, $f3, $f1, $f4 */);
    M2C_ERROR(/* unknown instruction: ps_sum0 $f6, $f5, $f6, $f5 */);
    M2C_ERROR(/* unknown instruction: ps_mul $f10, $f8, $f0 */);
    M2C_ERROR(/* unknown instruction: ps_madd $f11, $f9, $f1, $f10 */);
    M2C_ERROR(/* unknown instruction: ps_sum0 $f12, $f11, $f12, $f11 */);
    M2C_ERROR(/* unknown instruction: ps_mul $f4, $f2, $f0 */);
    M2C_ERROR(/* unknown instruction: ps_madd $f5, $f3, $f1, $f4 */);
    M2C_ERROR(/* unknown instruction: ps_sum0 $f6, $f5, $f6, $f5 */);
    return M2C_ERROR(/* psq_l unimplemented */);
}

void fn_80202A18(const f32 m[3][4], const f32 *v, f32 *out) {
    f32 x=v[0], y=v[1], z=v[2];
    f32 a=m[0][0]*x+m[0][1]*y;
    f32 b=m[1][0]*x+m[1][1]*y;
    f32 c=m[2][0]*x+m[2][1]*y;
    out[0]=m[0][2]*z+a;
    out[1]=m[1][2]*z+b;
    out[2]=m[2][2]*z+c;
}

#pragma scheduling on
void fn_80202A6C(f32 *m, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
 f32 fn_80238A0C(f32);
 extern f32 lbl_8036BC58, lbl_8036BC60, lbl_8036BC64, lbl_8036BC68, lbl_8036BC6C;
 f32 t, r, one, z;
 farg0=lbl_8036BC68*farg0; farg0=lbl_8036BC6C*farg0; t=fn_80238A0C(farg0);
 one=lbl_8036BC58; t=one/t;
 m[0]=t/farg1; r=one/(farg3-farg2); z=lbl_8036BC60;
 m[1]=z; m[2]=z; m[3]=z; m[4]=z; m[5]=t; m[6]=z; m[7]=z; m[8]=z; m[9]=z;
 m[10]=-farg2*r; m[11]=r*-(farg3*farg2); m[12]=z; m[13]=z; m[14]=lbl_8036BC64; m[15]=z;
}
#pragma scheduling reset
#pragma push
#pragma optimization_level 3
void C_MTXOrtho(f32 *m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
  extern f32 lbl_8036BC58;
  extern f32 lbl_8036BC5C;
  extern f32 lbl_8036BC60;
  extern f32 lbl_8036BC64;
  f32 one = lbl_8036BC58;
  f32 two = lbl_8036BC5C;
  f32 rw = one / (r - l);
  f32 rh = one / (t - b);
  f32 rd;
  f32 zero;
  m[0] = rw * two;
  zero = lbl_8036BC60;
  m[1] = zero;
  m[2] = zero;
  m[3] = rw * (-(r + l));
  m[4] = zero;
  m[5] = rh * two;
  m[6] = zero;
  m[7] = rh * (-(t + b));
  rd = one / (f - n);
  m[8] = zero;
  m[9] = zero;
  m[10] = lbl_8036BC64 * rd;
  m[11] = (-f) * rd;
  m[12] = zero;
  m[13] = zero;
  m[14] = zero;
  m[15] = one;
}
#pragma pop

#pragma push
typedef f32 Mtx44[4][4];
asm void fn_80202BD4(const register Mtx44 src, register Mtx44 dst) {
nofralloc
psq_l f1, 0x0(src), 0, 0
psq_st f1, 0x0(dst), 0, 0
psq_l f1, 0x8(src), 0, 0
psq_st f1, 0x8(dst), 0, 0
psq_l f1, 0x10(src), 0, 0
psq_st f1, 0x10(dst), 0, 0
psq_l f1, 0x18(src), 0, 0
psq_st f1, 0x18(dst), 0, 0
psq_l f1, 0x20(src), 0, 0
psq_st f1, 0x20(dst), 0, 0
psq_l f1, 0x28(src), 0, 0
psq_st f1, 0x28(dst), 0, 0
psq_l f1, 0x30(src), 0, 0
psq_st f1, 0x30(dst), 0, 0
psq_l f1, 0x38(src), 0, 0
psq_st f1, 0x38(dst), 0, 0
blr
}
#pragma pop

#pragma push
asm void fn_80202C18(const register Mtx44 a, const register Mtx44 b, register Mtx44 ab) {
nofralloc
psq_l f0, 0x0(a), 0, 0
psq_l f2, 0x0(b), 0, 0
ps_muls0 f6, f2, f0
psq_l f3, 0x10(b), 0, 0
psq_l f4, 0x20(b), 0, 0
ps_madds1 f6, f3, f0, f6
psq_l f1, 0x8(a), 0, 0
psq_l f5, 0x30(b), 0, 0
ps_madds0 f6, f4, f1, f6
psq_l f0, 0x10(a), 0, 0
ps_madds1 f6, f5, f1, f6
psq_l f1, 0x18(a), 0, 0
ps_muls0 f8, f2, f0
ps_madds1 f8, f3, f0, f8
psq_l f0, 0x20(a), 0, 0
ps_madds0 f8, f4, f1, f8
ps_madds1 f8, f5, f1, f8
psq_l f1, 0x28(a), 0, 0
ps_muls0 f10, f2, f0
ps_madds1 f10, f3, f0, f10
psq_l f0, 0x30(a), 0, 0
ps_madds0 f10, f4, f1, f10
ps_madds1 f10, f5, f1, f10
psq_l f1, 0x38(a), 0, 0
ps_muls0 f12, f2, f0
psq_l f2, 0x8(b), 0, 0
ps_madds1 f12, f3, f0, f12
psq_l f0, 0x0(a), 0, 0
ps_madds0 f12, f4, f1, f12
psq_l f3, 0x18(b), 0, 0
ps_madds1 f12, f5, f1, f12
psq_l f1, 0x8(a), 0, 0
ps_muls0 f7, f2, f0
psq_l f4, 0x28(b), 0, 0
ps_madds1 f7, f3, f0, f7
psq_l f5, 0x38(b), 0, 0
ps_madds0 f7, f4, f1, f7
psq_l f0, 0x10(a), 0, 0
ps_madds1 f7, f5, f1, f7
psq_l f1, 0x18(a), 0, 0
ps_muls0 f9, f2, f0
psq_st f6, 0x0(ab), 0, 0
ps_madds1 f9, f3, f0, f9
psq_l f0, 0x20(a), 0, 0
ps_madds0 f9, f4, f1, f9
psq_st f8, 0x10(ab), 0, 0
ps_madds1 f9, f5, f1, f9
psq_l f1, 0x28(a), 0, 0
ps_muls0 f11, f2, f0
psq_st f10, 0x20(ab), 0, 0
ps_madds1 f11, f3, f0, f11
psq_l f0, 0x30(a), 0, 0
ps_madds0 f11, f4, f1, f11
psq_st f12, 0x30(ab), 0, 0
ps_madds1 f11, f5, f1, f11
psq_l f1, 0x38(a), 0, 0
ps_muls0 f13, f2, f0
psq_st f7, 0x8(ab), 0, 0
ps_madds1 f13, f3, f0, f13
psq_st f9, 0x18(ab), 0, 0
ps_madds0 f13, f4, f1, f13
psq_st f11, 0x28(ab), 0, 0
ps_madds1 f13, f5, f1, f13
psq_st f13, 0x38(ab), 0, 0
blr
}
#pragma pop

#pragma ppc_intrinsics on
s32 fn_80202D1C(f32 *src, f32 *inv) {
    void fn_80202BD4(f32 *, f32 *);
    extern f32 lbl_8036BC58;
    extern f32 lbl_8036BC60;
    f32 sp10[16];
    f32 one;
    f32 zero;
    f64 zpair;
    f32 f1;
    f32 f4;
    f32 f0;
    f32 t;
    s32 i;
    s32 j;
    s32 pivot;
    s32 off;
    s32 col;
    s32 r5;
    s32 r6;
    s32 r0;
    s32 ctr;

    fn_80202BD4(src, sp10);
    one = lbl_8036BC58;
    zero = lbl_8036BC60;
    ((f32 *)&zpair)[0] = zero;
    ((f32 *)&zpair)[1] = zero;
    inv[0] = one;
    *(f64 *)&inv[1] = zpair;
    *(f64 *)&inv[3] = zpair;
    inv[5] = one;
    *(f64 *)&inv[6] = zpair;
    *(f64 *)&inv[8] = zpair;
    inv[10] = one;
    *(f64 *)&inv[11] = zpair;
    *(f64 *)&inv[13] = zpair;
    inv[15] = one;

    i = 0;
    off = 0;
    col = 0;
    do {
        f1 = zero;
        pivot = i;
        j = i;
        r5 = j << 4;
        ctr = 4 - j;
        if (j < 4) {
            do {
                r0 = r5 + col;
                f0 = __fabsf(*(f32 *)((s8 *)sp10 + r0));
                if (f0 > f1) {
                    f1 = f0;
                    pivot = j;
                }
                j += 1;
                r5 += 0x10;
            } while (--ctr);
        }
        if (zero == f1)
            return 0;
        if (pivot != i) {
            r5 = pivot << 4;
            t = *(f32 *)((s8 *)sp10 + off);
            *(f32 *)((s8 *)sp10 + off) = *(f32 *)((s8 *)sp10 + r5);
            *(f32 *)((s8 *)sp10 + r5) = t;
            t = *(f32 *)((s8 *)inv + off);
            *(f32 *)((s8 *)inv + off) = *(f32 *)((s8 *)inv + r5);
            *(f32 *)((s8 *)inv + r5) = t;
            r6 = off + 4; r0 = r5 + 4;
            t = *(f32 *)((s8 *)sp10 + r6);
            *(f32 *)((s8 *)sp10 + r6) = *(f32 *)((s8 *)sp10 + r0);
            *(f32 *)((s8 *)sp10 + r0) = t;
            t = *(f32 *)((s8 *)inv + r6);
            *(f32 *)((s8 *)inv + r6) = *(f32 *)((s8 *)inv + r0);
            *(f32 *)((s8 *)inv + r0) = t;
            r6 = off + 8; r0 = r5 + 8;
            t = *(f32 *)((s8 *)sp10 + r6);
            *(f32 *)((s8 *)sp10 + r6) = *(f32 *)((s8 *)sp10 + r0);
            *(f32 *)((s8 *)sp10 + r0) = t;
            t = *(f32 *)((s8 *)inv + r6);
            *(f32 *)((s8 *)inv + r6) = *(f32 *)((s8 *)inv + r0);
            *(f32 *)((s8 *)inv + r0) = t;
            r6 = off + 0xC; r0 = r5 + 0xC;
            t = *(f32 *)((s8 *)sp10 + r6);
            *(f32 *)((s8 *)sp10 + r6) = *(f32 *)((s8 *)sp10 + r0);
            *(f32 *)((s8 *)sp10 + r0) = t;
            t = *(f32 *)((s8 *)inv + r6);
            *(f32 *)((s8 *)inv + r6) = *(f32 *)((s8 *)inv + r0);
            *(f32 *)((s8 *)inv + r0) = t;
        }
        f4 = one / *(f32 *)((s8 *)sp10 + (off + col));
        f0 = *(f32 *)((s8 *)sp10 + off) * f4; *(f32 *)((s8 *)sp10 + off) = f0;
        f0 = *(f32 *)((s8 *)inv + off) * f4; *(f32 *)((s8 *)inv + off) = f0;
        r0 = off + 4;
        f0 = *(f32 *)((s8 *)sp10 + r0) * f4; *(f32 *)((s8 *)sp10 + r0) = f0;
        f0 = *(f32 *)((s8 *)inv + r0) * f4; *(f32 *)((s8 *)inv + r0) = f0;
        r0 = off + 8;
        f0 = *(f32 *)((s8 *)sp10 + r0) * f4; *(f32 *)((s8 *)sp10 + r0) = f0;
        f0 = *(f32 *)((s8 *)inv + r0) * f4; *(f32 *)((s8 *)inv + r0) = f0;
        r0 = off + 0xC;
        f0 = *(f32 *)((s8 *)sp10 + r0) * f4; *(f32 *)((s8 *)sp10 + r0) = f0;
        f0 = *(f32 *)((s8 *)inv + r0) * f4; *(f32 *)((s8 *)inv + r0) = f0;
        j = 0; r5 = 0; ctr = 2;
        do {
            if (j != i) {
                f4 = *(f32 *)((s8 *)sp10 + (r5 + col));
                f0 = f4 * *(f32 *)((s8 *)sp10 + off); t = *(f32 *)((s8 *)sp10 + r5) - f0; *(f32 *)((s8 *)sp10 + r5) = t;
                f0 = f4 * *(f32 *)((s8 *)inv + off); t = *(f32 *)((s8 *)inv + r5) - f0; *(f32 *)((s8 *)inv + r5) = t;
                r0 = off + 4; r6 = r5 + 4;
                f0 = f4 * *(f32 *)((s8 *)sp10 + r0); t = *(f32 *)((s8 *)sp10 + r6) - f0; *(f32 *)((s8 *)sp10 + r6) = t;
                f0 = f4 * *(f32 *)((s8 *)inv + r0); t = *(f32 *)((s8 *)inv + r6) - f0; *(f32 *)((s8 *)inv + r6) = t;
                r0 = off + 8; r6 = r5 + 8;
                f0 = f4 * *(f32 *)((s8 *)sp10 + r0); t = *(f32 *)((s8 *)sp10 + r6) - f0; *(f32 *)((s8 *)sp10 + r6) = t;
                f0 = f4 * *(f32 *)((s8 *)inv + r0); t = *(f32 *)((s8 *)inv + r6) - f0; *(f32 *)((s8 *)inv + r6) = t;
                r0 = off + 0xC; r6 = r5 + 0xC;
                f0 = f4 * *(f32 *)((s8 *)sp10 + r0); t = *(f32 *)((s8 *)sp10 + r6) - f0; *(f32 *)((s8 *)sp10 + r6) = t;
                f0 = f4 * *(f32 *)((s8 *)inv + r0); t = *(f32 *)((s8 *)inv + r6) - f0; *(f32 *)((s8 *)inv + r6) = t;
            }
            j += 1; r5 += 0x10;
            if (j != i) {
                f4 = *(f32 *)((s8 *)sp10 + (r5 + col));
                f0 = f4 * *(f32 *)((s8 *)sp10 + off); t = *(f32 *)((s8 *)sp10 + r5) - f0; *(f32 *)((s8 *)sp10 + r5) = t;
                f0 = f4 * *(f32 *)((s8 *)inv + off); t = *(f32 *)((s8 *)inv + r5) - f0; *(f32 *)((s8 *)inv + r5) = t;
                r0 = off + 4; r6 = r5 + 4;
                f0 = f4 * *(f32 *)((s8 *)sp10 + r0); t = *(f32 *)((s8 *)sp10 + r6) - f0; *(f32 *)((s8 *)sp10 + r6) = t;
                f0 = f4 * *(f32 *)((s8 *)inv + r0); t = *(f32 *)((s8 *)inv + r6) - f0; *(f32 *)((s8 *)inv + r6) = t;
                r0 = off + 8; r6 = r5 + 8;
                f0 = f4 * *(f32 *)((s8 *)sp10 + r0); t = *(f32 *)((s8 *)sp10 + r6) - f0; *(f32 *)((s8 *)sp10 + r6) = t;
                f0 = f4 * *(f32 *)((s8 *)inv + r0); t = *(f32 *)((s8 *)inv + r6) - f0; *(f32 *)((s8 *)inv + r6) = t;
                r0 = off + 0xC; r6 = r5 + 0xC;
                f0 = f4 * *(f32 *)((s8 *)sp10 + r0); t = *(f32 *)((s8 *)sp10 + r6) - f0; *(f32 *)((s8 *)sp10 + r6) = t;
                f0 = f4 * *(f32 *)((s8 *)inv + r0); t = *(f32 *)((s8 *)inv + r6) - f0; *(f32 *)((s8 *)inv + r6) = t;
            }
            j += 1; r5 += 0x10;
        } while (--ctr);
        i += 1; off += 0x10; col += 4;
    } while (i < 4);
    return 1;
}

void fn_8020310C(f32 *m, f32 *v, f32 *out) {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    x = v[0];
    y = v[1];
    z = v[2];
    w = x * m[12] + y * m[13] + z * m[14];
    w = z / w;
    out[0] = (x * m[0] + y * m[1]) * w;
    out[1] = (x * m[4] + y * m[5]) * w;
    out[2] = (x * m[8] + y * m[9]) * w;
}

void fn_80203184(void) {
    M2C_ERROR(/* unknown instruction: ps_add $f6, $f2, $f4 */);
    M2C_ERROR(/* unknown instruction: ps_add $f7, $f3, $f5 */);
}

void fn_802031A8(float *arg0, float *arg1, float *arg2) {
    arg2[0] = arg0[0] - arg1[0];
    arg2[1] = arg0[1] - arg1[1];
}

void fn_802031CC(void *arg0, void *arg1) {
    f64* a = (f64*)arg0;
    f64* b = (f64*)arg1;
    f64 c;
    c = a[0] * 0.5; 
    b[0] = c;
    c = a[1] * 0.5;
    b[1] = c;
}

void fn_802031E8(f32 *src, f32 *dst) {
extern f32 lbl_8036BC70, lbl_8036BC74;
f32 x=src[0], y=src[1], z=src[2];
f32 mag=x*x+y*y+z*z;
f32 est=__frsqrte(mag);
f32 scale=(est*lbl_8036BC70)*(lbl_8036BC74-est*est*mag);
dst[0]=x*scale; dst[1]=y*scale; dst[2]=z*scale;
}

f32 Vec_Length(void *arg0) {
    extern f32 lbl_8036BC70;
    extern f32 lbl_8036BC74;
    f32 temp_f0;
    f32 var_f1;

    M2C_ERROR(/* unknown instruction: ps_mul $f0, $f0, $f0 */);
    M2C_ERROR(/* unknown instruction: ps_madd $f1, $f1, $f1, $f0 */);
    var_f1 = M2C_ERROR(/* unknown instruction: ps_sum0 $f1, $f1, $f0, $f0 */);
    if (var_f1 != (lbl_8036BC70 - lbl_8036BC70)) {
        temp_f0 = __frsqrte(var_f1);
        var_f1 *= -((temp_f0 * temp_f0 * var_f1) - lbl_8036BC74) * (temp_f0 * lbl_8036BC70);
    }
    return var_f1;
}

f32 fn_80203270(const f32 *a, const f32 *b) { return a[0]*b[0] + (a[1]*b[1] + a[2]*b[2]); }

void fn_80203290(const f32 *a, const f32 *b, f32 *out) {
f32 x=a[1]*b[2]-a[2]*b[1];
f32 y=a[2]*b[0]-a[0]*b[2];
f32 z=a[0]*b[1]-a[1]*b[0];
out[0]=x; out[1]=y; out[2]=z;
}

f32 PSVECDistance(void) {
    extern f32 lbl_8036BC70;
    extern f32 lbl_8036BC74;
    f32 temp_f0;
    f32 var_f1;

    M2C_ERROR(/* unknown instruction: ps_sub $f2, $f0, $f1 */);
    M2C_ERROR(/* unknown instruction: ps_mul $f2, $f2, $f2 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f1 */);
    M2C_ERROR(/* unknown instruction: ps_madd $f1, $f0, $f0, $f2 */);
    var_f1 = M2C_ERROR(/* unknown instruction: ps_sum0 $f1, $f1, $f2, $f2 */);
    if ((lbl_8036BC70 - lbl_8036BC70) != var_f1) {
        temp_f0 = __frsqrte(var_f1);
        var_f1 *= -((temp_f0 * temp_f0 * var_f1) - lbl_8036BC74) * (temp_f0 * lbl_8036BC70);
    }
    return var_f1;
}
