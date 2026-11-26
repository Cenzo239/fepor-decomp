/* string pool for double2hex / printf float specials */
const char stringBase0_80282C60[] =
    "\0-INF\0-inf\0INF\0inf\0-NAN\0-nan\0NAN\0nan";
#define double2hex_strpool stringBase0_80282C60

/* Functions from 0x8022CD68 to 0x80267A7C, found by decomp-toolkit. */
#include "common.h"
typedef struct RuntimeDecimal { u8 sign; s16 exponent; u8 length; u8 digits[36]; } RuntimeDecimal;

static inline s32 count_trailing_zero(f64 x) {
    u32 *l = (u32 *)&x;
    u32 lo = l[1];
    u32 hi;
    s32 n;
    if (lo != 0) {
        s32 m = 16;
        u32 xbits = 0xFFFFU;
        s32 j = 32;
        s32 k = m;
        n = 0;
        while (j != 0) {
            if ((lo & xbits) == 0) {
                n += k;
                lo >>= k;
                j -= k;
            } else if (xbits == 1) {
                break;
            }
            if (m > 1) {
                m /= 2;
            }
            if (xbits > 1) {
                xbits >>= m;
                k -= m;
            }
        }
        return n;
    } else {
        s32 m = 16;
        u32 xbits = 0xFFFFU;
        s32 j = 32;
        s32 k = m;
        hi = l[0] | 0x100000;
        n = 0;
        while (j != 0) {
            if ((hi & xbits) == 0) {
                n += k;
                hi >>= k;
                j -= k;
            } else if (xbits == 1) {
                break;
            }
            if (m > 1) {
                m /= 2;
            }
            if (xbits > 1) {
                xbits >>= m;
                k -= m;
            }
        }
        return n + 32;
    }
}

extern f32 lbl_80367068;
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

#pragma opt_common_subs off
void fn_8022E804(void *dst, f64 x) {
    u64 fn_8022CC2C(f64);
    void fn_8022F1C0(void *, s32);
    void fn_80230944(void *, void *, void *);
    f64 fn_802382EC(s32 *, f64);
    f64 fn_80238378(s32, f64);
    void fn_8023853C(f64 *);
    extern const f64 lbl_8036BDC8;
    u8 dig[0x2C];
    u8 sp38[0x2C];
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    s8 sign;
    f64 f31;
    s32 hx;
    s32 clas;
    s32 clas2;
    u32 xbits;
    s32 k;
    s32 m;
    s32 j;
    s32 n;
    u32 lo;
    u32 hi;
    u64 uq;
    u8 t;
    u8 *q;
    u8 *p;
    s32 expadj;
    s8 ch;

    sp8 = x;
    sign = (s8)((*(u32 *)&sp8) >> 31);
    if (lbl_8036BDC8 == x) {
        *(s8 *)dst = sign;
        *(s16 *)((u8 *)dst + 2) = 0;
        ((u8 *)dst)[4] = 1;
        ((u8 *)dst)[5] = 0;
        return;
    }
    sp28 = x;
    hx = *(s32 *)&sp28;
    switch (hx & 0x7FF00000) {
    case 0x7FF00000:
        if ((hx & 0xFFFFF) || *((s32 *)&sp28 + 1) != 0) {
            clas = 1;
        } else {
            clas = 2;
        }
        break;
    case 0:
        if ((hx & 0xFFFFF) || *((s32 *)&sp28 + 1) != 0) {
            clas = 5;
        } else {
            clas = 3;
        }
        break;
    default:
        clas = 4;
        break;
    }
    if (clas <= 2) {
        *(s8 *)dst = sign;
        *(s16 *)((u8 *)dst + 2) = 0;
        ((u8 *)dst)[4] = 1;
        sp20 = sp8;
        hx = *(s32 *)&sp20;
        switch (hx & 0x7FF00000) {
        case 0x7FF00000:
            if ((hx & 0xFFFFF) || *((s32 *)&sp20 + 1) != 0) {
                clas2 = 1;
            } else {
                clas2 = 2;
            }
            break;
        case 0:
            if ((hx & 0xFFFFF) || *((s32 *)&sp20 + 1) != 0) {
                clas2 = 5;
            } else {
                clas2 = 3;
            }
            break;
        default:
            clas2 = 4;
            break;
        }
        ch = 0x49;
        if (clas2 == 1) {
            ch = 0x4E;
        }
        ((u8 *)dst)[5] = ch;
        return;
    }
    if ((s8)sign != 0) {
        sp8 = -x;
    }
    f31 = fn_802382EC((s32 *)&sp10, sp8);
    sp18 = f31;
    lo = *((u32 *)&sp18 + 1);
    if (lo != 0) {
        m = 0x10;
        xbits = 0xFFFFU;
        n = 0;
        k = m;
        j = 0x20;
        while (j != 0) {
            if ((lo & xbits) == 0) {
                n += k;
                lo >>= k;
                j -= k;
            } else if (xbits == 1) {
                break;
            }
            if (m > 1) {
                m /= 2;
            }
            if (xbits > 1) {
                xbits >>= m;
                k -= m;
            }
        }
    } else {
        k = 0x10;
        xbits = 0xFFFFU;
        n = 0;
        m = k;
        hi = (*(u32 *)&sp18) | 0x100000;
        j = 0x20;
        while (j != 0) {
            if ((hi & xbits) == 0) {
                n += k;
                hi >>= k;
                j -= k;
            } else if (xbits == 1) {
                break;
            }
            if (m > 1) {
                m /= 2;
            }
            if (xbits > 1) {
                xbits >>= m;
                k -= m;
            }
        }
        n += 0x20;
    }
    expadj = 0x35 - n;
    fn_8022F1C0(sp38, *(s32 *)&sp10 - expadj);
    fn_80238378(expadj, f31);
    fn_8023853C(&sp30);
    uq = fn_8022CC2C(sp30);
    dig[0] = 0;
    if (uq == 0) {
        *(s16 *)(dig + 2) = 0;
        dig[4] = 1;
        dig[5] = 0;
    } else {
        dig[4] = 0;
        while (uq != 0) {
            dig[5 + dig[4]++] = (u8)(uq % 10);
            uq /= 10;
        }
        p = dig + 5;
        q = dig + dig[4] + 5;
        while (p < q) {
            t = *p;
            *p = *q;
            p++;
            *q = t;
            q--;
        }
        *(s16 *)(dig + 2) = dig[4] - 1;
    }
    fn_80230944(dst, dig, sp38);
    *(s8 *)dst = sign;
}
#pragma opt_common_subs on
