/* string pool for double2hex / printf float specials */
const char stringBase0_80282C60[] =
    "\0-INF\0-inf\0INF\0inf\0-NAN\0-nan\0NAN\0nan";
#define double2hex_strpool stringBase0_80282C60

/* Functions from 0x8022CD68 to 0x80267A7C, found by decomp-toolkit. */
#include "common.h"
typedef struct RuntimeDecimal { u8 sign; s16 exponent; u8 length; u8 digits[36]; } RuntimeDecimal;

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

extern s32 D_8022EF64;

#pragma global_optimizer off

void fn_80230944(u8 *dest, u8 *a, u8 *b) {
    u8 sp8[0x54];
    u8 *out;
    u8 *end;
    s32 dig_b;
    s32 dig_a;
    s32 pos;
    s32 q;
    u32 acc;
    s32 i, j, n, n8;
    u8 *pa, *pb;
    u32 prod;
    u8 t0, t1;
    s32 c;
    u8 *p, *base;
    u8 d;

    dig_b = b[4];
    dig_a = a[4];
    pos = dig_a + (dig_b - 1);
    acc = 0;
    q = pos + 1;
    out = sp8 + q;
    dest[0] = 0;
    end = out;

    for (;;) {
        j = dig_b - 1;
        i = (pos - j) - 1;
        if (i < 0) {
            i = 0;
            j = pos - 1;
        }
        n = j + 1;
        {
            s32 lim = dig_a - i;
            pa = a + i + 5;
            pb = b + j + 5;
            if (n > lim) {
                n = lim;
            }
        }
        if (n > 0) {
            n8 = (u32)n >> 3;
            if (n8 != 0) {
                do {
                    t0 = pa[0]; t1 = pb[0]; prod = t0 * t1; acc += prod;
                    t0 = pa[1]; t1 = pb[-1]; prod = t0 * t1; acc += prod;
                    t0 = pa[2]; t1 = pb[-2]; prod = t0 * t1; acc += prod;
                    t0 = pa[3]; t1 = pb[-3]; prod = t0 * t1; acc += prod;
                    t0 = pa[4]; t1 = pb[-4]; prod = t0 * t1; acc += prod;
                    t0 = pa[5]; t1 = pb[-5]; prod = t0 * t1; acc += prod;
                    t0 = pa[6]; t1 = pb[-6]; prod = t0 * t1; acc += prod;
                    t0 = pa[7]; t1 = pb[-7];
                    pa += 8; pb -= 8;
                    prod = t0 * t1; acc += prod;
                } while (--n8);
            }
            n &= 7;
            if (n != 0) {
                do {
                    t0 = *pa; pa++;
                    t1 = *pb; pb--;
                    acc += t0 * t1;
                } while (--n);
            }
        }
        {
            u32 magic = acc * 0xCCCCCCCDU;
            pos--;
            d = (u8)(acc - ((magic >> 3) * 10));
            acc = magic >> 3;
            *--out = d;
        }
        if (pos <= 0) break;
    }

    *(s16 *)(dest + 2) = *(s16 *)(a + 2) + *(s16 *)(b + 2);
    if (acc != 0) {
        *--out = (u8)acc;
        (*(s16 *)(dest + 2))++;
    }

    for (c = 0; c < 0x24 && out < end; c++, out++) {
        dest[c + 5] = *out;
    }
    dest[4] = (u8)c;

    if (out < end) {
        d = *out;
        if (d >= 5) {
            if (d != 5) {
                goto round_up;
            }
            p = out + 1;
            n = (s32)(end - p);
            if (p < end) {
                do {
                    if (*p != 0) {
                        goto round_up;
                    }
                    p++;
                } while (--n);
            }
            if ((out[-1] & 1) == 0) {
                goto done;
            }
        round_up:
            base = dest + 5;
            p = base + dest[4] - 1;
            for (;;) {
                if (*p < 9) {
                    (*p)++;
                    break;
                }
                if (p == base) {
                    *p = 1;
                    (*(s16 *)(dest + 2))++;
                    break;
                }
                *p = 0;
                p--;
            }
        }
    }
done:
    ;
}
#pragma global_optimizer reset
