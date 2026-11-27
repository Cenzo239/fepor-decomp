/* string pool for double2hex / printf float specials */
extern const char stringBase0_80282C60[];
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
extern u16 Ecb_8033E188[192];extern u16 *D_80256B30;
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

#pragma use_lmw_stmw on
#pragma optimization_level 3

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

extern f64 __floor_huge;
extern f64 __floor_zero;

extern const f64 lbl_8036C148;
#pragma global_optimizer off

#pragma global_optimizer on
extern f64 lbl_8036C150;
extern f64 lbl_8036C158;
extern f64 lbl_8036C160;
extern f64 lbl_8036C168;
extern f64 lbl_8036C170;

#pragma global_optimizer off
/* fdlibm __kernel_cos: cosine on a reduced argument (x, y) with |x| ~<= pi/4. */

#pragma global_optimizer reset

  extern f64 lbl_8036C180;
  extern f64 lbl_80282ED8[];
  extern f64 lbl_8036C0D0;
  extern f64 lbl_8036C0D8;
  extern f64 lbl_8036C0E0;
  extern f64 lbl_8036C0E8;
  extern f64 lbl_8036C0F0;
  extern f64 lbl_8036C0F8;
  extern f64 lbl_8036C100;
extern f64 lbl_80282F40[];
extern f64 lbl_8036C108;
extern f64 lbl_8036C110;
extern f64 lbl_8036C118;
extern f64 lbl_8036C120;
extern f64 lbl_8036C128;

extern u16 Ecb_8033E188[];

extern u16 Ecb_8033E188[192];

f64 fn_802387E8(f64 x) {
    extern s32 errno;
    extern f64 lbl_8036C188;
    extern f32 lbl_80367068[];
    u32 r;
    u32 t2;
    u32 t1;
    u32 s1;
    u32 q1;
    u32 s0;
    s32 q0;
    u32 t;
    s32 m;
    s32 ix0;
    u32 ix1;
    f64 z;
    s32 rem;

    ix0 = ((s32 *)&x)[0];
    ix1 = ((u32 *)&x)[1];

    if ((u32)((ix0 & 0x7FF00000) + 0x80100000) == 0U) {
        errno = 0x21;
        return x * x + x;
    }
    if (ix0 <= 0) {
        if ((ix1 | (ix0 & 0x7FFFFFFF)) == 0) {
            return x;
        }
        if (ix0 < 0) {
            errno = 0x21;
            return *(f32 *)(void *)&lbl_80367068;
        }
    }

    m = ix0 >> 20;
    if (m == 0) {
        s32 i;
        u32 a;
        s32 b;
        goto denorm_check;
    denorm_shift:
        t = ix1 >> 11;
        ix1 <<= 21;
        ix0 |= (s32)t;
        m -= 0x15;
    denorm_check:
        if (ix0 == 0) {
            goto denorm_shift;
        }
        i = 0;
        goto denorm_bit_check;
    denorm_bit_shift:
        ix0 <<= 1;
        i += 1;
    denorm_bit_check:
        if ((ix0 & 0x100000) == 0) {
            goto denorm_bit_shift;
        }
        b = i - 1;
        m -= b;
        a = 32 - i;
        t = ix1 >> a;
        ix1 <<= i;
        ix0 |= (s32)t;
    }

    t = (u32)(m - 0x3FF);
    rem = (ix0 & 0xFFFFF) | 0x100000;
    if (t & 1) {
        t = ix1 >> 31;
        ix1 += ix1;
        t = t + rem;
        rem = rem + t;
    }
    t = ix1 >> 31;
    ix1 += ix1;
    t = t + rem;
    rem = rem + t;
    s1 = 0;
    s0 = 0;
    q1 = 0;
    q0 = 0;
    r = 0x200000;
    goto loop1_check;
 loop1:
    t = s0 + r;
    if ((s32)t <= (s32)rem) {
        s0 = t + r;
        rem = rem - t;
        q0 = q0 + r;
    }
    t = ix1 >> 31;
    ix1 += ix1;
    t = t + rem;
    rem = rem + t;
    r >>= 1;
 loop1_check:
    if (r != 0) {
        goto loop1;
    }

    r = 0x80000000;
    goto loop2_check;
 loop2:
    t2 = s0;
    t1 = s1 + r;
    if ((s32)s0 < (s32)rem) {
        goto loop2_take;
    }
    if ((s32)s0 != (s32)rem) {
        goto loop2_skip;
    }
    if (t1 > ix1) {
        goto loop2_skip;
    }
 loop2_take:
    s1 = t1 + r;
    if ((u32)((t1 & 0x80000000) + 0x80000000) == 0U && (s1 & 0x80000000) == 0) {
        s0 = s0 + 1;
    }
    rem = rem - t2;
    if (ix1 < t1) {
        rem = rem - 1;
    }
    ix1 = ix1 - t1;
    q1 = q1 + r;
 loop2_skip:
    t = ix1 >> 31;
    ix1 += ix1;
    t = t + rem;
    rem = rem + t;
    r >>= 1;
 loop2_check:
    if (r != 0) {
        goto loop2;
    }

    if ((rem | ix1) != 0) {
        z = lbl_8036C188;
        z = lbl_8036C188;
        if ((u32)(q1 + 0x10000) == 0xFFFFU) {
            q1 = 0;
            q0 = q0 + 1;
        } else {
            q1 = q1 + (q1 & 1);
        }
    }

    {
        s32 q0_odd = (s32)(q0 & 1);
        s32 hi = (s32)(q0 >> 1);
        u32 lo = q1 >> 1;
        hi += 0x3FE00000;
        if (q0_odd == 1) {
            lo |= 0x80000000;
        }
        ((u32 *)&z)[1] = lo;
        hi += ((m - 0x3FF) >> 1) << 20;
        ((s32 *)&z)[0] = hi;
    }
    return z;
}

f32 fn_80238A0C(void) {
    f64 fn_80238710();
    return (f32) fn_80238710();
}

f32 sinf(void) {
    f64 sin();
    return (f32) sin();
}

f32 cosf(void) {
    f64 fn_802380D0();
    return (f32) fn_802380D0();
}

f32 acosf(void) {
    f64 fn_80238788();
    return (f32) fn_80238788();
}

f64 fn_80238A9C(f64, f64) {
    M2C_UNK fn_802387E8();
    fn_802387E8();
}

void fn_80238ABC(void) {
    M2C_UNK fn_8023108C();
    fn_8023108C();
}

u8 *fn_80238ADC(u8 *arg0) { extern u16 lbl_8029E9A8[256]; u8 *table=(u8*)lbl_8029E9A8; s32 tmp; s32 c; u8 *p=arg0; goto check; do { tmp=(s8)c; if (tmp == -1) tmp=-1; else tmp=table[(u8)tmp]; *p++=(u8)tmp; check: c=*p; } while ((s8)c != 0); return arg0; }

s32 Hu_IsStub(void) {
    return 0;
}
