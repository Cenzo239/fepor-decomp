/* string pool for double2hex / printf float specials */
const char stringBase0_80282C60[] =
    "\0-INF\0-inf\0INF\0inf\0-NAN\0-nan\0NAN\0nan";
#define double2hex_strpool stringBase0_80282C60

/* Functions from 0x8022CD68 to 0x80267A7C, found by decomp-toolkit. */
#include "common.h"
typedef struct RuntimeDecimal { u8 sign; s16 exponent; u8 length; u8 digits[36]; } RuntimeDecimal;

extern f64 lbl_8036BE20;
extern f64 lbl_8036BE28;
extern f64 lbl_8036BE30;
extern f64 lbl_8036BE38;
extern f64 lbl_8036BE40;
extern f64 lbl_8036BE48;
extern f64 lbl_8036BE50;
extern f64 lbl_8036BE58;
extern f64 lbl_8036BE60;
extern f64 lbl_8036BE68;
extern f64 lbl_8036BE70;
extern f64 lbl_8036BE78;
extern f64 lbl_8036BE80;
extern f64 lbl_8036BE88;
extern f64 lbl_8036BE90;
extern f64 lbl_8036BE98;
extern f64 lbl_8036BEA0;

extern f64 fn_80238A9C(f64, f64);

extern s32 lbl_80366F28;
extern char lbl_80282AE8[];
extern char lbl_80282B20[];
extern void *__stdio_exit;
extern void __close_all(void);
extern u8 gSoundData[];
extern f64 lbl_8036C368;
extern u16 Ecb_8033E188[192];u16 *D_80256B30;
extern s32 UART_Initialized;
extern f32 lbl_8036C374;
extern s32 gSynthTimeHi;
extern s32 gSynthTimeLo;
extern s32 gSynthSchedList;
extern s32 gSynthIdleList;
extern u32* lbl_80368A38;
extern void (*lbl_80368B34)(s16);
extern f32 lbl_8034C324[];
extern s32 D_80368AD0;
extern s32 lbl_80368B0C;
extern void (*__atexit_funcs[])(void);
extern s32 __atexit_curr_func;
extern void (*__console_exit)(void);
extern s32 __aborting;
extern void (*_dtors[])(void);
extern void _ExitProcess(void);
extern s16 lbl_802A1E90[];
extern u8 lbl_80368AAE;
extern u8 lbl_80368AAD;
extern u16 lbl_8035BF18[];
extern u32 lbl_8035C918[];

typedef struct __InStrCtrl {
    char *NextChar;
    s32 NullCharDetected;
} __InStrCtrl;

u32 fn_8026367C(void);
u16 Sound_GetChanParam(u8 arg0, u8 arg1, u8 arg2);
s32 __cvt_fp2unsigned(f32 arg0);
void Sound_SetVoiceEnvelope(u8 arg0, void *arg1, s32 arg2);
void fn_8026146C(s32 *);
void fn_8025FFC8(void *arg0, u8 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5);
s32 Sound_LookupVid(void);
extern void func_80013934(s32 arg0);
extern s32 gSynthVoices;
extern u16 lbl_803548B8;
extern u16 lbl_80368A08;
extern u16 lbl_8035A510[];
extern u16 lbl_8035D118[256];
extern u16 gSoundChanParamsDefault[4288];
extern f32 lbl_802831BC[];
extern f64 lbl_8036C348;
extern u16 lbl_803670C0;
extern u32 lbl_803670C8;
extern u32 lbl_800000F8;

#include "musyx/select_source.h"

typedef struct Voice {
    u8 pad0[0x110];
    u64 flags;
    u8 pad118[0x5C];
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    s32 unk188;
    u32 unk18C;
    u32 unk190;
} Voice;

typedef struct VidList {
    struct VidList *next; /* 0x0 */
    struct VidList *prev; /* 0x4 */
    u32 vid;              /* 0x8 */
    u32 root;             /* 0xC */
} VidList;

extern u32 vidGenerator;

static u32 GetNewVid(void) {
    u32 vid;

    do {
        vid = vidGenerator++;
    } while (vid == 0xFFFFFFFF);
    return vid;
}

typedef struct GroupData {
    u8 pad0[4];
    u16 id;     /* 0x04 */
    u16 type;   /* 0x06 */
    u8 pad8[0x1C - 0x8];
    u32 unk1C;  /* 0x1C */
    u32 unk20;  /* 0x20 */
    u32 unk24;  /* 0x24 */
} GroupData;

typedef struct GroupEntry {
    GroupData *data; /* 0x0 */
    u32 unk4;        /* 0x4 */
    u32 base;        /* 0x8 */
} GroupEntry;

typedef struct GroupNode {
    struct GroupNode *next; /* 0x0 */
    u32 unk4;               /* 0x4 */
    s16 count;              /* 0x8 */
    GroupEntry entries[1];  /* 0xC */
} GroupNode;

typedef struct GroupItem {
    u16 id;
    u8 pad2[0x52];
} GroupItem;

typedef struct SynthVoice {
    struct SynthVoice *next; /* 0x000 */
    struct SynthVoice *prev; /* 0x004 */
    u8 state;                /* 0x008 */
    u8 id;                   /* 0x009 */
    u16 unkA;                /* 0x00A */
    u32 vid;                 /* 0x00C */
    u8 pad10[0xF4 - 0x10];
    u32 unkF4;               /* 0x0F4 */
    struct VidList *unkF8;   /* 0x0F8 */
    struct VidList *unkFC;   /* 0x0FC */
    u8 pad100[0x11C - 0x100];
    s32 unk11C;              /* 0x11C */
    s32 unk120;              /* 0x120 */
    u8 pad124[0xEF0 - 0x124];
    s32 unkEF0;              /* 0xEF0 */
    s32 unkEF4;              /* 0xEF4 */
    u16 unkEF8;              /* 0xEF8 */
    u8 unkEFA;               /* 0xEFA */
    u8 padEFB[0x1508 - 0xEFB];
    struct {
        u8 pad0[0x32];
        u16 unk32;
        u8 pad34[4];
    } unk1508[16];           /* 0x1508 */
} SynthVoice;

typedef struct {
    char gpr;
    char fpr;
    char reserved[2];
    char *input_arg_area;
    char *reg_save_area;
} __va_list;
typedef __va_list va_list[1];

typedef struct {
    char *buffer;
    s32 length;
    s32 position;
} __OutStr;

s32 __pformatter(s32 (*)(void *, const char *, u32), void *, const char *, va_list);
s32 fn_80232220(void *, const char *, u32);

// The structure being used in functions in this file - assumed based on offset 0xF4
typedef struct {
    u8 unkF4;  // This is likely the member accessed in function with 0xF4 offset 
} SStructType;

void fn_8022CDD0(void *);
#pragma global_optimizer off
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma global_optimizer reset

f64 fn_802380A8(f64, f64);

#pragma use_lmw_stmw on

extern s32 D_8022EF64;

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

/* Write any pending FILE buffer bytes via write_proc, then reset buffer pointers. */

extern s32 fn_802314D8(s32, s32, s32);

#pragma optimization_level 3

#pragma optimization_level reset

#pragma use_lmw_stmw on
/* Format args into dest with fmt; null-terminate and return written length. */

#pragma use_lmw_stmw reset

#pragma push
#pragma optimization_level 4
#pragma opt_propagation off

#pragma pop
typedef struct decimal_80233174 {
    char sign;
    char unk1;
    s16 exp;
    struct {
        u8 length;
        u8 text[36];
        u8 unk41;
    } sig;
} decimal_80233174;

#pragma optimization_level 3

#pragma optimization_level reset

#pragma optimization_level reset

/* MSL raise: run the handler for sig (1..6), honoring SIG_IGN/SIG_DFL. */

f64 fn_8022D5E0(void *);

#pragma use_lmw_stmw on
extern u8 lbl_8029E8A8[];
extern u8 lbl_8029EAA8[];
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

/* MSL console write: on non-TDEV, init/write EXI UART then always hand off to GDEV path. */

/* IEEE754 double remainder: return x - n*y for integer n, same sign as x. */

#pragma push
#pragma optimization_level 4

double fn_802360C4(double x, double y)
{

    extern double fn_80238A9C(double);
    extern double fn_80238378(double, int);
    extern int errno;
    extern float lbl_80367068[];

    static const double bp[2] = {
        1.0, 1.5
    };
    static const double dp_h[2] = {
        0.0, 5.84962487220764160156e-01
    };
    static const double dp_l[2] = {
        0.0, 1.35003920212974897128e-08
    };

    const double zero = 0.0;
    const double one = 1.0;
    const double two = 2.0;
    const double two53 = 9007199254740992.0;
    const double huge = 1.0e300;
    const double tiny = 1.0e-300;

    const double L1 = 5.99999999999994648725e-01;
    const double L2 = 4.28571428578550184252e-01;
    const double L3 = 3.33333329818377432918e-01;
    const double L4 = 2.72728123808534006489e-01;
    const double L5 = 2.30660745775561754067e-01;
    const double L6 = 2.06975017800338417784e-01;

    const double P1 = 1.66666666666666019037e-01;
    const double P2 = -2.77777777770155933842e-03;
    const double P3 = 6.61375632143793436117e-05;
    const double P4 = -1.65339022054652515390e-06;
    const double P5 = 4.13813679705723846039e-08;

    const double lg2 = 6.93147180559945286227e-01;
    const double lg2_h = 6.93147182464599609375e-01;
    const double lg2_l = -1.90465429995776804525e-09;
    const double ovt = 8.0085662595372944372e-17;

    const double cp = 9.61796693925975554329e-01;
    const double cp_h = 9.61796700954437255859e-01;
    const double cp_l = -7.02846165095275826516e-09;

    const double ivln2 = 1.44269504088896338700e+00;
    const double ivln2_h = 1.44269502162933349609e+00;
    const double ivln2_l = 1.92596299112661746887e-08;

    double z, ax, z_h, z_l, p_h, p_l;
    double y1, t1, t2, r, s, t, u, v, w;
    double ss, s2, s_h, s_l, t_h, t_l;

    int i, j, k, yisint, n;
    int sign;
    int hx, hy, ix, iy;
    unsigned int lx, ly;

    hy = ((int *)&y)[0];
    ly = ((unsigned int *)&y)[1];
    hx = ((int *)&x)[0];
    lx = ((unsigned int *)&x)[1];

    ix = hx & 0x7fffffff;
    iy = hy & 0x7fffffff;

    if ((iy | ly) == 0)
        return one;

    if (ix > 0x7ff00000 ||
        (ix == 0x7ff00000 && lx != 0) ||
        iy > 0x7ff00000 ||
        (iy == 0x7ff00000 && ly != 0))
        return x + y;

    yisint = 0;

    if (hx < 0) {
        if (iy >= 0x43400000) {
            yisint = 2;
        } else if (iy >= 0x3ff00000) {
            k = (iy >> 20) - 0x3ff;

            if (k > 20) {
                j = ly >> (52 - k);
                if ((unsigned int)(j << (52 - k)) == ly)
                    yisint = 2 - (j & 1);
            } else if (ly == 0) {
                j = iy >> (20 - k);
                if ((j << (20 - k)) == iy)
                    yisint = 2 - (j & 1);
            }
        }
    }

    if (ly == 0) {
        if (iy == 0x7ff00000) {
            if (((ix - 0x3ff00000) | lx) == 0)
                return y - y;
            else if (ix >= 0x3ff00000)
                return hy >= 0 ? y : zero;
            else
                return hy < 0 ? -y : zero;
        }

        if (iy == 0x3ff00000) {
            if (hy < 0)
                return one / x;
            return x;
        }

        if (hy == 0x40000000)
            return x * x;

        if (hy == 0x3fe00000 && hx >= 0)
            return fn_80238A9C(x);
    }

    ax = __fabs(x);

    if (lx == 0) {
        if (ix == 0x7ff00000 ||
            ix == 0 ||
            ix == 0x3ff00000) {
            z = ax;

            if (hy < 0)
                z = one / z;

            if (hx < 0) {
                if (((ix - 0x3ff00000) | yisint) == 0) {
                    z = (z - z) / (z - z);
                } else if (yisint == 1) {
                    z = -z;
                }
            }
            return z;
        }
    }

    sign = (hx >> 31) + 1;

    if ((sign | yisint) == 0) {
        errno = 33;
        return lbl_80367068[0];
    }


    if (iy > 0x41e00000) {
        if (iy > 0x43f00000) {
            if (ix <= 0x3fefffff)
                return hy < 0 ? huge * huge : tiny * tiny;

            if (ix >= 0x3ff00000)
                return hy > 0 ? huge * huge : tiny * tiny;
        }

        if (ix < 0x3fefffff)
            return hy < 0 ? huge * huge : tiny * tiny;

        if (ix > 0x3ff00000)
            return hy > 0 ? huge * huge : tiny * tiny;

        t = x - one;
        w = (t * t) *
            (0.5 - t * (0.3333333333333333333333 - t * 0.25));

        u = ivln2_h * t;
        v = t * ivln2_l - w * ivln2;

        t1 = u + v;
        ((unsigned int *)&t1)[1] = 0;

        t2 = v - (t1 - u);
    } else {
        n = 0;

        if (ix < 0x00100000) {
            ax *= two53;
            n -= 53;
            ix = ((int *)&ax)[0];
        }

        n += (ix >> 20) - 0x3ff;
        j = ix & 0x000fffff;
        ix = j | 0x3ff00000;

        if (j <= 0x3988E) {
            k = 0;
        } else if (j < 0xBB67A) {
            k = 1;
        } else {
            k = 0;
            n++;
            ix -= 0x00100000;
        }

        ((unsigned int *)&ax)[0] = ix;

        u = ax - bp[k];
        v = one / (ax + bp[k]);
        ss = u * v;

        s_h = ss;
        ((unsigned int *)&s_h)[1] = 0;

        t_h = zero;
        ((unsigned int *)&t_h)[0] = ((ix >> 1) | 0x20000000) +
                    0x00080000 + (k << 18);

        t_l = ax - (t_h - bp[k]);
        s_l = v * ((u - s_h * t_h) - s_h * t_l);

        s2 = ss * ss;

        r = s2 * s2 *
            (L1 + s2 *
            (L2 + s2 *
            (L3 + s2 *
            (L4 + s2 *
            (L5 + s2 * L6)))));

        r += s_l * (s_h + ss);

        s2 = s_h * s_h;
        t_h = 3.0 + s2 + r;

        ((unsigned int *)&t_h)[1] = 0;

        t_l = r - ((t_h - 3.0) - s2);

        u = s_h * t_h;
        v = s_l * t_h + t_l * ss;

        p_h = u + v;
        ((unsigned int *)&p_h)[1] = 0;

        p_l = v - (p_h - u);

        z_h = cp_h * p_h;
        z_l = cp_l * p_h + p_l * cp + dp_l[k];

        t = (double)n;
        t1 = ((z_h + z_l) + dp_h[k]) + t;

        ((unsigned int *)&t1)[1] = 0;

        t2 = z_l - (((t1 - t) - dp_h[k]) - z_h);
    }

    s = one;

    if ((sign | (yisint - 1)) == 0)
        s = -one;

    y1 = y;
    ((unsigned int *)&y1)[1] = 0;

    p_l = (y - y1) * t1 + y * t2;
    p_h = y1 * t1;

    z = p_l + p_h;
    j = ((int *)&z)[0];
    i = ((int *)&z)[1];

    if (j >= 0x40900000) {
        if (((j - 0x40900000) | i) != 0)
            return s * huge * huge;

        if (p_l + ovt > z - p_h)
            return s * huge * huge;
    } else if ((j & 0x7fffffff) >= 0x4090cc00) {
        if (((unsigned int)j - 0xc090cc00U) | (unsigned int)i)
            return s * tiny * tiny;

        if (p_l <= z - p_h)
            return s * tiny * tiny;
    }

    i = j & 0x7fffffff;
    k = (i >> 20) - 0x3ff;
    n = 0;

    if (i > 0x3fe00000) {
        n = j + (0x00100000 >> (k + 1));
        k = ((n & 0x7fffffff) >> 20) - 0x3ff;

        t = zero;
        ((unsigned int *)&t)[0] = n & ~(0x000fffff >> k);

        n = ((n & 0x000fffff) | 0x00100000) >> (20 - k);

        if (j < 0)
            n = -n;

        p_h -= t;
    }

    t = p_l + p_h;
    ((unsigned int *)&t)[1] = 0;

    u = t * lg2_h;
    v = (p_l - (t - p_h)) * lg2 + t * lg2_l;

    z = u + v;
    w = v - (z - u);

    t = z * z;

    t1 = z - t *
        (P1 + t *
        (P2 + t *
        (P3 + t *
        (P4 + t * P5))));

    r = (z * t1) / (t1 - two) - (w + z * w);
    z = one - (r - z);

    j = ((int *)&z)[0];
    j += n << 20;

    if ((j >> 20) <= 0) {
        z = fn_80238378(z, n);
    } else {
        ((int *)&z)[0] += n << 20;
    }

    return s * z;
}
#pragma pop
