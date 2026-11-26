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

#pragma pop

f64 fn_802380A8(f64 farg0, f64 farg1) {
    f64 y;
    f64 x;
    x = farg0;
    y = farg1;
    *(u32*)&x = (*(u32*)&x & 0x7FFFFFFF) | (*(u32*)&y & 0x80000000);
    return x;
}

f64 fn_802380D0(f64 x) {
 f64 __kernel_cos(f64, f64);
 f64 fn_80237BDC(f64, f64, s32);
 s32 fn_802368F4(f64 *, f64);
 f64 y[2];
 s32 ix=(*(s32 *)&x)&0x7fffffff;
 if(ix<=0x3fe921fb) return __kernel_cos(x,0.0);
 if(ix>=0x7ff00000) return x-x;
 switch(fn_802368F4(y,x)&3) {
 case 0: return __kernel_cos(y[0],y[1]);
 case 1: return -fn_80237BDC(y[0],y[1],1);
 case 2: return -__kernel_cos(y[0],y[1]);
 default: return fn_80237BDC(y[0],y[1],1);
 }
}

extern f64 __floor_huge;
extern f64 __floor_zero;
f64 floor(f64 x) {
    /* Round double toward -infinity (fdlibm/MSL floor). */
    s32 i0;
    u32 i1;
    s32 j0;
    u32 i;
    u32 j;

    i0 = ((s32 *)&x)[0];
    i1 = ((u32 *)&x)[1];
    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20) {
        if (j0 < 0) {
            if (__floor_huge + x > __floor_zero) {
                if (i0 >= 0) {
                    i1 = 0;
                    i0 = 0;
                } else if (((i0 & 0x7fffffff) | i1) != 0) {
                    i0 = 0xbff00000;
                    i1 = 0;
                }
            }
        } else {
            i = 0x000fffff >> j0;
            if (((i0 & i) | i1) == 0) {
                return x;
            }
            if (__floor_huge + x > __floor_zero) {
                if (i0 < 0) {
                    i0 += 0x00100000 >> j0;
                }
                i0 &= ~i;
                i1 = 0;
            }
        }
    } else if (j0 > 51) {
        if (j0 == 0x400) {
            return x + x;
        }
        return x;
    } else {
        i = 0xffffffffU >> (j0 - 20);
        if ((i1 & i) == 0) {
            return x;
        }
        if (__floor_huge + x > __floor_zero) {
            if (i0 < 0) {
                if (j0 == 20) {
                    i0 += 1;
                } else {
                    j = i1 + (1 << (52 - j0));
                    if (j < i1) {
                        i0 += 1;
                    }
                    i1 = j;
                }
            }
            i1 &= ~i;
        }
    }
    ((s32 *)&x)[0] = i0;
    ((u32 *)&x)[1] = i1;
    return x;
}

extern const f64 lbl_8036C148;
#pragma global_optimizer off
f64 fn_802382EC(s32 *arg0, f64 farg0) {
    s32 high, magnitude;
    u32 low;
    f64 scale;
    high = *(s32 *)&farg0;
    low = ((u32 *)&farg0)[1];
    *arg0 = 0;
    magnitude = high & 0x7fffffff;
    if (magnitude >= 0x7ff00000 || (magnitude | low) == 0)
        return farg0;
    if (magnitude < 0x100000) {
        scale = lbl_8036C148;
        *arg0 = -54;
        farg0 = farg0 * scale;
        high = *(s32 *)&farg0;
        magnitude = high & 0x7fffffff;
    }
    *arg0 += (magnitude >> 20) - 0x3fe;
    *(s32 *)&farg0 = (high & 0x800fffff) | 0x3fe00000;
    return farg0;
}
#pragma global_optimizer on
extern f64 lbl_8036C150;
extern f64 lbl_8036C158;
extern f64 lbl_8036C160;
extern f64 lbl_8036C168;
extern f64 lbl_8036C170;
f64 fn_80238378(s32 n, f64 x) {
    f64 fn_802380A8();
    f64 classified = x;
    f64 value = x;
    s32 high = ((s32 *)&classified)[0];
    s32 kind;
    s32 exponent;
    u32 low;
    switch (high & 0x7FF00000) {
    case 0x7FF00000:
        if ((high & 0xFFFFF) || ((s32 *)&classified)[1] != 0) kind=1; else kind=2;
        break;
    case 0:
        if ((high & 0xFFFFF) || ((s32 *)&classified)[1] != 0) kind=5; else kind=3;
        break;
    default: kind=4;
    }
    if (kind <= 2 || lbl_8036C150 == x) return x;
    high=((s32 *)&value)[0];
    low=((u32 *)&value)[1];
    exponent=(high >> 20)&0x7FF;
    if (exponent==0) {
        if ((low | (high & 0x7FFFFFFF)) == 0) return x;
        value *= lbl_8036C158;
        high=((s32 *)&value)[0];
        exponent=((high>>20)&0x7FF)-54;
        if (n < -50000) return lbl_8036C160*value;
    }
    if (exponent==0x7FF) return value+value;
    exponent += n;
    if (exponent>0x7FE) return lbl_8036C168*fn_802380A8(lbl_8036C168,value);
    if (exponent>0) {
        ((s32 *)&value)[0]=(high&0x800FFFFF)|(exponent<<20);
        return value;
    }
    if (exponent<=-54) {
        if (n>50000) return lbl_8036C168*fn_802380A8(lbl_8036C168,value);
        return lbl_8036C160*fn_802380A8(lbl_8036C160,value);
    }
    exponent += 54;
    ((s32 *)&value)[0]=(high&0x800FFFFF)|(exponent<<20);
    return lbl_8036C170*value;
}

f64 fn_8023853C(f64 *iptr, f64 x) {
 f64 temp=x;
 u32 hi=((u32 *)&temp)[0];
 u32 lo=((u32 *)&temp)[1];
 s32 exponent=((hi>>20)&0x7ff)-0x3ff;
 s32 mask;
 u32 lowmask;
 if(exponent<20) {
 if(exponent<0) {((u32 *)iptr)[0]=hi&0x80000000; ((u32 *)iptr)[1]=0; return x;}
 mask=0xfffff>>exponent;
 if((lo|(hi&mask))==0) {((u32 *)&temp)[0]=hi&0x80000000; ((u32 *)&temp)[1]=0; *iptr=x; return temp;}
 ((u32 *)iptr)[0]=hi&~mask; ((u32 *)iptr)[1]=0; return x-*iptr;
 }
 if(exponent>51) {((u32 *)&temp)[0]=hi&0x80000000; ((u32 *)&temp)[1]=0; *iptr=x; return temp;}
 lowmask=0xffffffffU>>(exponent-20);
 if((lo&lowmask)==0) {((u32 *)&temp)[0]=hi&0x80000000; ((u32 *)&temp)[1]=0; *iptr=x; return temp;}
 ((u32 *)iptr)[0]=hi; ((u32 *)iptr)[1]=lo&~lowmask; return x-*iptr;
}

#pragma global_optimizer off
/* fdlibm __kernel_cos: cosine on a reduced argument (x, y) with |x| ~<= pi/4. */
f64 __kernel_cos(f64 x, f64 y) {
    extern f64 __kcos_one;
    extern f64 __kcos_C1;
    extern f64 __kcos_C2;
    extern f64 __kcos_C3;
    extern f64 __kcos_C4;
    extern f64 __kcos_C5;
    extern f64 __kcos_C6;
    extern f64 __kcos_half;
    extern f64 __kcos_qx;
    f64 qx;
    f64 xLocal;
    f64 z;
    f64 r;
    s32 ix;

    xLocal = x;
    ix = ((s32 *)&xLocal)[0] & 0x7FFFFFFF;
    if (ix < 0x3E400000) {
        if ((s32)x == 0) {
            return __kcos_one;
        }
    }
    z = xLocal * xLocal;
    r = z * (((((__kcos_C6 * z + __kcos_C5) * z + __kcos_C4) * z + __kcos_C3) * z + __kcos_C2) * z + __kcos_C1);
    if (ix < 0x3FD33333) {
        return __kcos_one - ((__kcos_half * z) - ((z * r) - (xLocal * y)));
    }
    if (ix > 0x3FE90000) {
        qx = __kcos_qx;
    } else {
        ((s32 *)&qx)[0] = ix - 0x00200000;
        ((s32 *)&qx)[1] = 0;
    }
    return (__kcos_one - qx) - (((__kcos_half * z) - qx) - ((z * r) - (xLocal * y)));
}

#pragma push
#pragma optimization_level 4
s32 fn_80236D88(const f64 *x, f64 *y, s32 e0, s32 nx, s32 prec, const s32 *ipio2)
{
    extern s32 lbl_80282E88[];
    extern f64 lbl_80282E98[];
    
    
    
    
    
    
    
    f64 fn_80238378(f64, s32);
    f64 floor(f64);
    s32 jz, jx, jv, jp, jk, carry, n, iq[20], i, j, k, m, q0, ih;
    f64 z, fw, f[20], fq[20], q[20];
    register f64 zero, eight, eighth, two24, twon24;

    jk = lbl_80282E88[prec];
    jp = jk;
    jx = nx - 1;
    jv = (e0 - 3) / 24;
    if (jv < 0) {
        jv = 0;
    }
    q0 = e0 - 24 * (jv + 1);

    j = jv - jx;
    m = jx + jk;
    for(i=0;i<=m;i++,j++) f[i] = j<0 ? 0.0 : (f64)ipio2[j];

    for (i = 0; i <= jk; i++) {
        fw = 0.0;
        for (j = 0; j <= jx; j++) {
            fw += x[j] * f[jx + i - j];
        }
        q[i] = fw;
    }

    twon24 = 5.9604644775390625e-8;
    two24 = 16777216.0;
    eighth = 0.125;
    eight = 8.0;
    zero = 0.0;

    jz = jk;
recompute:
    z = q[jz];
    for (i = 0, j = jz; j > 0; i++, j--) {
        s32 integral = (s32)(twon24 * z);
        fw = (f64)integral;
        iq[i] = (s32)(z - two24 * fw);
        z = q[j - 1] + fw;
    }

    z = fn_80238378(z, q0);
    z -= eight * floor(eighth * z);
    n = (s32)z;
    z -= (f64)n;
    ih = 0;
    if (q0 > 0) {
        i = iq[jz - 1] >> (24 - q0);
        n += i;
        iq[jz - 1] -= i << (24 - q0);
        ih = iq[jz - 1] >> (23 - q0);
    } else if (q0 == 0) {
        ih = iq[jz - 1] >> 23;
    } else if (z >= 0.5) {
        ih = 2;
    }

    if (ih > 0) {
        n++;
        carry = 0;
        for (i = 0; i < jz; i++) {
            j = iq[i];
            if (carry == 0) {
                if (j != 0) {
                    carry = 1;
                    iq[i] = 0x1000000 - j;
                }
            } else {
                iq[i] = 0xFFFFFF - j;
            }
        }
        if (q0 > 0) {
            switch (q0) {
            case 1:
                iq[jz - 1] &= 0x7FFFFF;
                break;
            case 2:
                iq[jz - 1] &= 0x3FFFFF;
                break;
            }
        }
        if (ih == 2) {
            z = 1.0 - z;
            if (carry != 0) {
                z -= fn_80238378(1.0, q0);
            }
        }
    }

    if (zero == z) {
        j = 0;
        for (i = jz - 1; i >= jk; i--) {
            j |= iq[i];
        }
        if (j == 0) {
            for (k = 1; iq[jk - k] == 0; k++) {
            }
            for (i = jz + 1; i <= jz + k; i++) {
                f[jx+i] = (f64)ipio2[jv+i];
                fw = 0.0;
                for(j=0;j<=jx;j++) fw += x[j] * f[jx+i-j];
                q[i] = fw;
            }
            jz += k;
            goto recompute;
        }
    }

    if (0.0 == z) {
        jz--;
        q0 -= 24;
        while (iq[jz] == 0) {
            jz--;
            q0 -= 24;
        }
    } else {
        z = fn_80238378(z, -q0);
        if (z >= 16777216.0) {
            s32 integral = (s32)(5.9604644775390625e-8 * z);
            fw = (f64)integral;
            iq[jz] = (s32)(z - 16777216.0 * fw);
            jz++;
            q0 += 24;
            iq[jz] = (s32)fw;
        } else {
            iq[jz] = (s32)z;
        }
    }

    fw = fn_80238378(1.0, q0);
    for (i = jz; i >= 0; i--) {
        q[i] = fw * (f64)iq[i];
        fw *= 5.9604644775390625e-8;
    }
    for (i = jz; i >= 0; i--) {
        fw = 0.0;
        for (k = 0; k <= jp && k <= jz-i; k++) {
            fw += lbl_80282E98[k] * q[i+k];
        }
        fq[jz - i] = fw;
    }

    switch (prec) {
    case 0:
        fw = 0.0;
        for (i=jz;i>=0;i--) fw += fq[i];
        y[0] = ih == 0 ? fw : -fw;
        break;
    case 1:
    case 2:
        fw = 0.0;
        for (i=jz;i>=0;i--) fw += fq[i];
        y[0] = ih == 0 ? fw : -fw;
        fw = fq[0] - fw;
        for (i=1;i<=jz;i++) fw += fq[i];
        y[1] = ih == 0 ? fw : -fw;
        break;
    case 3:
        for(i=jz;i>0;i--) {
            fw=fq[i-1]+fq[i];
            fq[i] += fq[i-1]-fw;
            fq[i-1]=fw;
        }
        for(i=jz;i>1;i--) {
            fw=fq[i-1]+fq[i];
            fq[i] += fq[i-1]-fw;
            fq[i-1]=fw;
        }
        fw = 0.0;
        for(i=jz;i>=2;i--) fw += fq[i];
        if (ih == 0) {
            y[0] = fq[0];
            y[1] = fq[1];
            y[2] = fw;
        } else {
            y[0] = -fq[0];
            y[1] = -fq[1];
            y[2] = -fw;
        }
        break;
    }
    return n & 7;
}
#pragma pop
f64 fn_80237BDC(f64 x, f64 y, s32 iy) {
    extern f64 lbl_8036C098;
    extern f64 lbl_8036C0A0;
    extern f64 lbl_8036C0A8;
    extern f64 lbl_8036C0B0;
    extern f64 lbl_8036C0B8;
    extern f64 lbl_8036C0C0;
    extern f64 lbl_8036C0C8;
    f64 xLocal;
    f64 z;
    f64 r;
    f64 v;
    s32 ix;

    xLocal = x;
    ix = ((s32 *)&xLocal)[0] & 0x7FFFFFFF;
    if (ix < 0x3E400000) {
        if ((s32)x == 0) {
            return x;
        }
    }
    z = xLocal * xLocal;
    v = z * xLocal;
    r = ((((lbl_8036C0B8 * z + lbl_8036C0B0) * z + lbl_8036C0A8) * z + lbl_8036C0A0) * z + lbl_8036C098);
    if (iy == 0) {
        return xLocal + (v * (lbl_8036C0C0 + z * r));
    }
    return xLocal - ((z * (lbl_8036C0C8 * y - v * r) - y) - lbl_8036C0C0 * v);
}

#pragma global_optimizer reset
f64 sin(f64 x) {
 f64 __kernel_cos(f64, f64);
 f64 fn_80237BDC(f64, f64, s32);
 s32 fn_802368F4(f64 *, f64);
 f64 y[2];
 s32 ix=(*(s32 *)&x)&0x7fffffff;
 if(ix<=0x3fe921fb) return fn_80237BDC(x,0.0,0);
 if(ix>=0x7ff00000) return x-x;
 switch(fn_802368F4(y,x)&3) {
 case 0: return fn_80237BDC(y[0],y[1],1);
 case 1: return __kernel_cos(y[0],y[1]);
 case 2: return -fn_80237BDC(y[0],y[1],1);
 default: return -__kernel_cos(y[0],y[1]);
 }
}

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

f64 fn_80237C7C(s32 arg0, f64 farg0, f64 farg1) {
    extern f64 lbl_8036C0D0;
    extern f64 lbl_8036C0D8;
    extern f64 lbl_8036C0E0;
    extern f64 lbl_8036C0E8;
    extern f64 lbl_8036C0F0;
    extern f64 lbl_8036C0F8;
    extern f64 lbl_8036C100;
    extern f64 lbl_80282ED8[];
    f64 st[3];
    f64 z;
    f64 w;
    f64 r;
    f64 v;
    f64 s;
    f64 a;
    f64 y;
    f64 *T;
    s32 ix;
    s32 hx;
    s32 sf;

    y = farg1;
    st[0] = farg0;
    hx = ((s32 *)&st[0])[0];
    ix = hx & 0x7FFFFFFF;
    if (ix < 0x3E300000 && (s32)farg0 == 0) {
        if (((arg0 + 1) | (ix | ((s32 *)&st[0])[1])) == 0) {
            farg0 = __fabs(farg0);
            return lbl_8036C0D0 / farg0;
        }
        if (arg0 == 1) {
            return farg0;
        }
        return lbl_8036C0D8 / farg0;
    }
    if (ix >= 0x3FE59428) {
        if (hx < 0) {
            y = -y;
            st[0] = -st[0];
        }
        z = lbl_8036C0E0 - st[0];
        a = lbl_8036C0E8 - y;
        y = lbl_8036C0F0;
        st[2] = z;
        st[0] = z + a;
    }
    T = lbl_80282ED8;
    z = st[0] * st[0];
    w = z * z;
    r = T[1] + w * (T[3] + w * (T[5] + w * (T[7] + w * (T[9] + w * T[11]))));
    v = z * (T[2] + w * (T[4] + w * (T[6] + w * (T[8] + w * (T[10] + w * T[12])))));
    s = z * st[0];
    st[2] = z;
    r = y + z * (s * (r + v) + y);
    r += T[0] * s;
    w = st[0] + r;
    if (ix >= 0x3FE59428) {
        sf = 1 - ((s32)((u32)hx >> 30) & 2);
        v = (f64)arg0;
        a = (f64)sf;
        (void)lbl_8036C100;
        s = w * w;
        z = w + v;
        s = s / z - r;
        return a * (v - lbl_8036C0F8 * (st[0] - s));
    }
    if (arg0 == 1) {
        return w;
    }
    st[2] = w;
    ((s32 *)&st[2])[1] = 0;
    v = r - (st[2] - st[0]);
    a = lbl_8036C0D8 / w;
    st[1] = a;
    ((s32 *)&st[1])[1] = 0;
    s = lbl_8036C0D0 + st[1] * st[2];
    return st[1] + a * (s + st[1] * v);
}

f64 fn_80237E90(f64 farg0) {
    static const f64 atanhi[4] = {
        4.63647609000806093515e-01,
        7.85398163397448278999e-01,
        9.82793723247329054082e-01,
        1.57079632679489655800e+00,
    };
    static const f64 atanlo[4] = {
        2.26987774529616870924e-17,
        3.06161699786838301793e-17,
        1.39033110312309984516e-17,
        6.12323399573676603587e-17,
    };
    static const f64 aT[11] = {
        3.33333333333329318027e-01,
       -1.99999999998764832476e-01,
        1.42857142725034663711e-01,
       -1.11111104054623557880e-01,
        9.09088713343650656196e-02,
       -7.69187620504482999495e-02,
        6.66107313738753120669e-02,
       -5.83357013379057348645e-02,
        4.97687799461593236017e-02,
       -3.65315727442169155270e-02,
        1.62858201153657823623e-02,
    };
    f64 w;
    f64 z;
    f64 s1;
    f64 s2;
    f64 a;
    s32 ix;
    s32 hx;
    s32 id;

    hx = ((s32 *)&farg0)[0];
    ix = hx & 0x7FFFFFFF;
    if (ix >= 0x44100000) {
        if (ix > 0x7FF00000 || (ix == 0x7FF00000 && ((s32 *)&farg0)[1] != 0)) {
            return farg0 + farg0;
        }
        if (hx > 0) {
            return atanhi[3] + atanlo[3];
        }
        return -atanhi[3] - atanlo[3];
    }
    if (ix < 0x3FDC0000) {
        if (ix < 0x3E200000 && (lbl_8036C108 + farg0) > lbl_8036C110) {
            return farg0;
        }
        id = -1;
    } else {
        a = __fabs(farg0);
        farg0 = a;
        if (ix < 0x3FF30000) {
            if (ix < 0x3FE60000) {
                id = 0;
                farg0 = ((lbl_8036C118 * a) - lbl_8036C110) / (lbl_8036C118 + a);
            } else {
                id = 1;
                farg0 = (a - lbl_8036C110) / (lbl_8036C110 + a);
            }
        } else if (ix < 0x40038000) {
            id = 2;
            farg0 = (a - lbl_8036C120) / ((lbl_8036C120 * a) + lbl_8036C110);
        } else {
            id = 3;
            farg0 = lbl_8036C128 / a;
        }
    }
    z = farg0 * farg0;
    w = z * z;
    s1 = z * (aT[0] + w * (aT[2] + w * (aT[4] + w * (aT[6] + w * (aT[8] + w * aT[10])))));
    s2 = w * (aT[1] + w * (aT[3] + w * (aT[5] + w * (aT[7] + w * aT[9]))));
    if (id < 0) {
        return farg0 - farg0 * (s1 + s2);
    }
    z = atanhi[id] - ((farg0 * (s1 + s2) - atanlo[id]) - farg0);
    if (hx < 0) {
        z = -z;
    }
    return z;
}

  f64 fn_80238710(f64 farg0) {
      f64 sp10[2];
      f64 sp8;
      s32 temp_r3;

      sp8 = farg0;
      temp_r3 = *(s32 *)&sp8 & 0x7FFFFFFF;
      if (temp_r3 <= 0x3FE921FB) {
          return fn_80237C7C(1, farg0, lbl_8036C180);
      }
      if (temp_r3 >= 0x7FF00000) {
          return farg0 - farg0;
      }
      return fn_80237C7C(1 - ((fn_802368F4(sp10, farg0) * 2) & 2), sp10[0], sp10[1]);
  }

void fn_80238788(void) {
    M2C_UNK fn_80235B4C();
    fn_80235B4C();
}

void fn_802387A8(void) {
    M2C_UNK __ieee754_fmod();
    __ieee754_fmod();
}

void fmod(void) {
    M2C_UNK fn_802360C4();
    fn_802360C4();
}

extern u16 Ecb_8033E188[];

extern u16 Ecb_8033E188[192];
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
int fn_802368F4(f64 *y, f64 x) {
    int fn_80236D88();
    extern const f64 lbl_8036BFB8;
    extern const f64 lbl_8036BFC0;
    extern const f64 lbl_8036BFC8;
    extern const f64 lbl_8036BFD0;
    extern const f64 lbl_8036BFD8;
    extern const f64 lbl_8036BFE0;
    extern const f64 lbl_8036BFE8;
    extern const f64 lbl_8036BFF0;
    extern const f64 lbl_8036BFF8;
    extern const f64 lbl_8036C000;
    extern const f64 lbl_8036C008;
    extern s32 lbl_80282E08[];
    extern s32 lbl_80282D00[];
    f64 t, w, r, fn, z;
    f64 pio2_1, pio2_2;
    f64 tx[3];
    int e0, i, j, nx, n, ix, hx;

    hx = *(int *)&x;
    ix = hx & 0x7fffffff;
    if (ix <= 0x3fe921fb) {
        y[0] = x;
        y[1] = lbl_8036BFB8;
        return 0;
    }
    if (ix < 0x4002d97c) {
        if (hx > 0) {
            z = x - lbl_8036BFC0;
            if ((unsigned)(ix - 0x3ff90000) != 0x21fbU) {
                                y[0] = z - lbl_8036BFC8;
                y[1] = (z - y[0]) - lbl_8036BFC8;
            } else {
                pio2_2 = lbl_8036BFD0;
                                z -= pio2_2;
                y[0] = z - lbl_8036BFD8;
                y[1] = (z - y[0]) - lbl_8036BFD8;
            }
            return 1;
        } else {
            z = lbl_8036BFC0 + x;
            if ((unsigned)(ix - 0x3ff90000) != 0x21fbU) {
                                y[0] = lbl_8036BFC8 + z;
                y[1] = lbl_8036BFC8 + (z - y[0]);
            } else {
                pio2_2 = lbl_8036BFD0;
                                z += pio2_2;
                y[0] = lbl_8036BFD8 + z;
                y[1] = lbl_8036BFD8 + (z - y[0]);
            }
            return -1;
        }
    }
    if (ix <= 0x413921fb) {
        t = __fabs(x);
        n = (int)(lbl_8036BFE8 * t + lbl_8036BFE0);
        fn = (f64)n;
        pio2_1 = lbl_8036BFC0;
                r = t - pio2_1 * fn;
        w = lbl_8036BFC8 * fn;
        if (n < 32 && ix != lbl_80282E08[n - 1]) {
            y[0] = r - w;
        } else {
            j = ix >> 20;
            y[0] = r - w;
            i = j - (((*(int *)&y[0]) >> 20) & 0x7ff);
            if (i > 16) {
                t = r;
                w = lbl_8036BFD0 * fn;
                r = t - w;
                w = lbl_8036BFD8 * fn - ((t - r) - w);
                y[0] = r - w;
                i = j - (((*(int *)&y[0]) >> 20) & 0x7ff);
                if (i > 49) {
                    t = r;
                    w = lbl_8036BFF0 * fn;
                    r = t - w;
                    w = lbl_8036BFF8 * fn - ((t - r) - w);
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (hx < 0) {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        }
        return n;
    }
    if (ix >= 0x7ff00000) {
        y[0] = y[1] = x - x;
        return 0;
    }
    e0 = (ix >> 20) - 1046;
    *(1 + (unsigned *)&z) = *(1 + (unsigned *)&x);
    *(int *)&z = ix - (e0 << 20);
    for (i = 0; i < 2; i++) {
        t = (double)((int)(z));
        tx[i] = t;
        z = (z - tx[i]) * lbl_8036C000;
    }
    tx[2] = z;
    nx = 3;
    while (tx[nx - 1] == lbl_8036BFB8)
        nx--;
    n = fn_80236D88(tx, y, e0, nx, 2, lbl_80282D00);
    if (hx < 0) {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}
#pragma pop
