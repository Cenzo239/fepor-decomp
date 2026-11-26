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

void __stdio_atexit(void) {
    __stdio_exit = __close_all;
}

#pragma use_lmw_stmw on
/* Format args into dest with fmt; null-terminate and return written length. */
s32 sprintf(char *dest, const char *fmt, ...) {
    va_list args;
    __OutStr out;
    s32 n;

    __builtin_va_info(&args);
    out.buffer = dest;
    out.length = -1;
    out.position = 0;
    n = __pformatter(fn_80232220, &out, fmt, args);
    if (dest != NULL) {
        u32 idx = (u32)-2;
        if ((u32)n < (u32)-1) {
            idx = (u32)n;
        }
        dest[idx] = 0;
    }
    return n;
}

s32 fn_80231E74(char *dest, s32 dest_len, const char *fmt, ...) {
 va_list args;
 __OutStr out;
 s32 n;
 __builtin_va_info(&args);
 out.buffer=dest; out.length=dest_len; out.position=0;
 n=__pformatter(fn_80232220,&out,fmt,args);
 if(dest != NULL) { u32 idx=(u32)dest_len-1; if((u32)n<(u32)dest_len) idx=(u32)n; dest[idx]=0; }
 return n;
}

#pragma use_lmw_stmw reset
s32 vsprintf(char *s, const char *fmt, va_list args) {
    __OutStr out;
    s32 n;
    u32 idx;

    out.buffer = s;
    out.length = -1;
    out.position = 0;
    n = __pformatter(fn_80232220, &out, fmt, args);
    if (s != NULL) {
        idx = (u32)-2;
        if ((u32)n < (u32)-1) {
            idx = (u32)n;
        }
        s[idx] = 0;
    }
    return n;
}

s32 vprintf(const char *format, void *args) {
    extern u8 __files[];
    s32 fwide(void *, s32);
    void __begin_critical_region(s32);
    void __end_critical_region(s32);
    s32 __FileWrite(void *, const char *, u32);
    s32 __pformatter(s32 (*)(void *, const char *, u32), void *, const char *, void *);

    void *stream;
    s32 result;

    stream = __files + 0x50;

    if (fwide(stream, -1) >= 0) {
        return -1;
    }

    __begin_critical_region(2);
    result = __pformatter(__FileWrite, stream, format, args);
    __end_critical_region(2);
    return result;
}

s32 fprintf(void *stream, const char *format, ...) {
    s32 fwide(void *, s32);
    void __begin_critical_region(s32);
    void __end_critical_region(s32);
    s32 __FileWrite(void *, const char *, u32);
    s32 result;
    va_list args;

    if (fwide(stream, -1) >= 0) {
        return -1;
    }
    __begin_critical_region(2);
    __builtin_va_info(&args);
    result = __pformatter(__FileWrite, stream, format, args);
    __end_critical_region(2);
    return result;
}

s32 fn_80232138(const char *format, ...) {
 extern u8 __files[];
 s32 fwide(void *, s32);
 void __begin_critical_region(s32);
 void __end_critical_region(s32);
 s32 __FileWrite(void *, const char *, u32);
 s32 result;
 va_list args;
 void *stream=__files+0x50;
 if(fwide(stream,-1)>=0) return -1;
 __begin_critical_region(2);
 __builtin_va_info(&args);
 result=__pformatter(__FileWrite,stream,format,args);
 __end_critical_region(2);
 return result;
}

s32 __StringWrite(void *arg0, const void *arg1, s32 arg2) {
    void *memcpy(void *, const void *, s32);
    void *self;
    s32 pos;
    s32 end;
    s32 n;

    self = arg0;
    pos = *(s32 *)((u8 *)arg0 + 8);
    end = *(s32 *)((u8 *)self + 4);
    n = end - pos;
    if ((u32)(pos + arg2) <= (u32)end) {
        n = arg2;
    }
    memcpy(*(char **)self + pos, arg1, n);
    *(s32 *)((u8 *)self + 8) = *(s32 *)((u8 *)self + 8) + n;
    return 1;
}

s32 __FileWrite(void *file, const char *buf, u32 n) {
    u32 fwrite(const void *, u32, u32, void *);
    u32 written;

    written = fwrite(buf, 1, n, file);
    if (n == written) {
        return (s32)file;
    }
    return 0;
}

s32 __pformatter(s32 (*write)(void *, const char *, u32), void *context, const char *format, va_list args) {
    typedef struct {
        u8 just, sign, prec_set, alt, size, conv;
        u16 pad;
        s32 width, precision;
    } Format;
    void *__va_arg(void *,s32);
    char *parse_format_80233B44(const char *,void *,void *);
    char *longlong2str_802335D8(s64,char *,Format);
    char *long2str_802338EC(s32,char *,Format);
    char *float2str(char *,Format,f64);
    char *double2hex(char *,Format,f64);
    s32 wcstombs(char *,const void *,u32);
    s32 strlen(const char *);
    char *strchr(const char *,s32);
    void *memchr(const void *,s32,u32);
    char buffer[512];
    Format f;
    char pad=' ';
    char blank;
    const char *cursor=format;
    const char *percent;
    char *text;
    s32 total=0;
    s32 number;
    s64 wide;
    s32 length, count;
    f64 real;
    void *ptr;
    while(*cursor) {
        percent=strchr(cursor,'%');
        if(!percent) {
            length=strlen(cursor);
            total+=length;
            if(length && ((u32)write(context,cursor,length)==0U)) return -1;
            break;
        }
        length=percent-cursor;
        total+=length;
        if(length && ((u32)write(context,cursor,length)==0U)) return -1;
        cursor=parse_format_80233B44(percent,args,&f);
        switch(f.conv) {
        case 'd': case 'i':
            if(f.size==3) number=*(s32 *)__va_arg(args,1);
            else if(f.size==4) wide=*(s64 *)__va_arg(args,2);
            else number=*(s32 *)__va_arg(args,1);
            if(f.size==2) number=(s16)number;
            if(f.size==1) number=(s8)number;
            if(f.size==4) {
                text=longlong2str_802335D8(wide,buffer+512,f);
                if(!text) goto invalid;
            } else {
                text=long2str_802338EC(number,buffer+512,f);
                if(!text) goto invalid;
            }
            length=buffer+511-text;
            break;
        case 'o': case 'u': case 'x': case 'X':
            if(f.size==3) number=*(u32 *)__va_arg(args,1);
            else if(f.size==4) wide=*(u64 *)__va_arg(args,2);
            else number=*(u32 *)__va_arg(args,1);
            if(f.size==2) number=(u16)number;
            if(f.size==1) number=(u8)number;
            if(f.size==4) {
                text=longlong2str_802335D8(wide,buffer+512,f);
                if(!text) goto invalid;
            } else {
                text=long2str_802338EC(number,buffer+512,f);
                if(!text) goto invalid;
            }
            length=buffer+511-text;
            break;
        case 'f': case 'F': case 'e': case 'E': case 'g': case 'G':
            if(f.size==5) real=*(long double *)__va_arg(args,3);
            else real=*(double *)__va_arg(args,3);
            text=float2str(buffer+512,f,real);
            if(!text) goto invalid;
            length=buffer+511-text;
            break;
        case 'a': case 'A':
            if(f.size==5) real=*(long double *)__va_arg(args,3);
            else real=*(double *)__va_arg(args,3);
            text=double2hex(buffer+512,f,real);
            if(!text) goto invalid;
            length=buffer+511-text;
            break;
        case 's':
            if(f.size==6) {
                const void *str=*(void **)__va_arg(args,1);
                if(!str) str=L"";
                if(wcstombs(buffer,str,512)<0) goto invalid;
                text=buffer;
            } else text=*(char **)__va_arg(args,1);
            if(!text) text=(char *)double2hex_strpool;
            if(f.alt) {
                length=(u8)*text++;
                if(f.prec_set && length>f.precision) length=f.precision;
            } else if(f.prec_set) {
                length=f.precision;
                ptr=memchr(text,0,length);
                if(ptr) length=(char *)ptr-text;
            } else length=strlen(text);
            break;
        case 'n':
            ptr=*(void **)__va_arg(args,1);
            switch(f.size) {
            case 0: *(s32 *)ptr=total; break;
            case 2: *(s16 *)ptr=total; break;
            case 3: *(s32 *)ptr=total; break;
            case 4: *(s64 *)ptr=total; break;
            }
            continue;
        case 'c':
            text=buffer;
            buffer[0]=*(s32 *)__va_arg(args,1);
            length=1;
            break;
        case '%':
            text=buffer;
            buffer[0]='%';
            length=1;
            break;
        case 0xFF: case 'h': case 't':
        default:
invalid:
            length=strlen(percent);
            total+=length;
            if(length && ((u32)write(context,percent,length)==0U)) return -1;
            return total;
        }
        count=length;
        if(f.just) {
            pad=f.just==2?'0':' ';
            if((*text=='+' || *text=='-' || *text==' ') && pad=='0') {
                if(((u32)write(context,text,1)==0U)) return -1;
                text++;
                length--;
            }
            while(count<f.width) {
                if(((u32)write(context,&pad,1)==0U)) return -1;
                count++;
            }
        }
        if(length && ((u32)write(context,text,length)==0U)) return -1;
        if(!f.just) {
            while(count<f.width) {
                blank=' ';
                if(((u32)write(context,&blank,1)==0U)) return -1;
                count++;
            }
        }
        total+=count;
    }
    return total;
}

char *float2str(char *buffer, void *format, f64 value)
{
    void fn_8022E660(void *, void *);
    void fn_80233174(void *, s32);
    void strcpy(char *, const char *);
    extern u8 lbl_8029E8A8[];
    extern f64 lbl_8036BE00;

    typedef struct {
        u8 unk0;
        u8 sign_style;
        u8 unk2;
        u8 alternate;
        u8 unk4;
        u8 conv;
        u8 pad6[6];
        s32 precision;
    } PrintFormat;

    typedef struct {
        s8 kind;
        s8 pad;
        s16 width;
    } DecCtrl;

    DecCtrl ctrl;
    RuntimeDecimal dec;
    PrintFormat *fmt = (PrintFormat *)format;
    char *out;
    s8 *digs;
    s8 *p;
    s32 i;
    s32 n;
    s32 frac;
    s32 whole;
    s32 exp;
    s8 signch;
    s32 prec;

    prec = fmt->precision;
    if (prec > 0x1FD) {
        return NULL;
    }

    ctrl.kind = 0;
    ctrl.width = 0x20;
    fn_8022E660(&ctrl, &dec);

    digs = (s8 *)dec.digits;
    p = digs + dec.length;
    while (dec.length > 1 && *--p == 0x30) {
        dec.length -= 1;
        dec.exponent += 1;
    }

    switch ((s32)dec.digits[0]) {
    case 0x30:
        dec.exponent = 0;
        break;
    case 0x49:
        if (value < lbl_8036BE00) {
            out = buffer - 5;
            if (lbl_8029E8A8[fmt->conv] & 0x80) {
                strcpy(out, double2hex_strpool + 1);
            } else {
                strcpy(out, double2hex_strpool + 6);
            }
        } else {
            out = buffer - 4;
            if (lbl_8029E8A8[fmt->conv] & 0x80) {
                strcpy(out, double2hex_strpool + 0xB);
            } else {
                strcpy(out, double2hex_strpool + 0xF);
            }
        }
        return out;
    case 0x4E:
        if ((s8)dec.sign != 0) {
            out = buffer - 5;
            if (lbl_8029E8A8[fmt->conv] & 0x80) {
                strcpy(out, double2hex_strpool + 0x13);
            } else {
                strcpy(out, double2hex_strpool + 0x18);
            }
        } else {
            out = buffer - 4;
            if (lbl_8029E8A8[fmt->conv] & 0x80) {
                strcpy(out, double2hex_strpool + 0x1D);
            } else {
                strcpy(out, double2hex_strpool + 0x21);
            }
        }
        return out;
    }

    out = buffer - 1;
    dec.exponent = dec.length + dec.exponent - 1;
    buffer[-1] = 0;

    switch (fmt->conv) {
    case 0x67:
    case 0x47:
        if ((s32)dec.length > fmt->precision) {
            fn_80233174(&dec, 0);
        }
        if (dec.exponent < -4 || dec.exponent >= fmt->precision) {
            if (fmt->alternate != 0) {
                fmt->precision = fmt->precision - 1;
            } else {
                fmt->precision = dec.length - 1;
            }
            if (fmt->conv == 0x67) {
                fmt->conv = 0x65;
            } else {
                fmt->conv = 0x45;
            }
            goto do_exp;
        }
        if (fmt->alternate != 0) {
            fmt->precision = fmt->precision - (dec.exponent + 1);
        } else {
            n = dec.length - (dec.exponent + 1);
            fmt->precision = n;
            if (n < 0) {
                fmt->precision = 0;
            }
        }
    case 0x66:
    case 0x46:
        goto do_f;
    case 0x65:
    case 0x45:
        goto do_exp;
    default:
        return out;
    }

do_exp:
    if ((s32)dec.length > fmt->precision + 1) {
        fn_80233174(&dec, 0);
    }
    exp = dec.exponent;
    signch = 0x2B;
    if (exp < 0) {
        exp = -exp;
        signch = 0x2D;
    }
    n = 0;
    do {
        n += 1;
        i = exp % 10;
        exp /= 10;
        *--out = (char)(i + 0x30);
    } while (exp != 0 || n < 2);
    out[-1] = signch;
    out[-2] = fmt->conv;
    out -= 2;
    if (fmt->precision + (s32)(buffer - out) > 0x1FD) {
        return NULL;
    }
    if ((s32)dec.length < fmt->precision + 1) {
        n = (fmt->precision + 2) - dec.length;
        do {
            *--out = 0x30;
            n -= 1;
        } while (n != 0);
    }
    i = dec.length;
    p = digs + i;
    while (i != 0) {
        i -= 1;
        if (i == 0) {
            break;
        }
        *--out = *--p;
    }
    if (fmt->precision != 0 || fmt->alternate != 0) {
        *--out = 0x2E;
    }
    *--out = dec.digits[0];
    if ((s8)dec.sign != 0) {
        *--out = 0x2D;
    } else if (fmt->sign_style == 1) {
        *--out = 0x2B;
    } else if (fmt->sign_style == 2) {
        *--out = 0x20;
    }
    return out;

do_f:
    frac = (dec.length - dec.exponent) - 1;
    if (frac < 0) {
        frac = 0;
    }
    if (frac > fmt->precision) {
        fn_80233174(&dec, dec.length - (frac - fmt->precision));
        frac = (dec.length - dec.exponent) - 1;
        if (frac < 0) {
            frac = 0;
        }
    }
    whole = dec.exponent + 1;
    if (whole < 0) {
        whole = 0;
    }
    if (whole + frac > 0x1FD) {
        return NULL;
    }
    n = fmt->precision - frac;
    p = digs + dec.length;
    while (n > 0) {
        *--out = 0x30;
        n -= 1;
    }
    i = 0;
    while (i < frac && i < (s32)dec.length) {
        *--out = *--p;
        i += 1;
    }
    while (i < frac) {
        *--out = 0x30;
        i += 1;
    }
    if (fmt->precision != 0 || fmt->alternate != 0) {
        *--out = 0x2E;
    }
    if (whole != 0) {
        i = 0;
        while (i < whole - (s32)dec.length) {
            *--out = 0x30;
            i += 1;
        }
        while (i < whole) {
            *--out = *--p;
            i += 1;
        }
    } else {
        *--out = 0x30;
    }
    if ((s8)dec.sign != 0) {
        *--out = 0x2D;
    } else if (fmt->sign_style == 1) {
        *--out = 0x2B;
    } else if (fmt->sign_style == 2) {
        *--out = 0x20;
    }
    return out;
}

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
static void fn_80233174(void *dec_, s32 new_length_) {
    decimal_80233174 *dec = (decimal_80233174 *)dec_;
    int new_length = (int)new_length_;
    extern f64 exp(f64);
    char c;
    char *p;
    int carry;
    if (new_length < 0) {
    return_zero:
        dec->exp = 0;
        dec->sig.length = 1;
        *dec->sig.text = '0';
        return;
    }
    if (new_length >= dec->sig.length) {
        return;
    }
    p = (char *)dec->sig.text + new_length + 1;
    c = *--p - '0';
    if (c == 5) {
        char *q = &((char *)dec->sig.text)[dec->sig.length];
        while (--q > p && *q == '0')
            ;
        carry = (q == p) ? p[-1] & 1 : 1;
    } else {
        carry = (c > 5);
    }
    while (new_length != 0) {
        c = *--p - '0' + carry;
        if ((carry = (c > 9)) != 0 || c == 0) {
            --new_length;
        } else {
            *p = c + '0';
            break;
        }
    }
    if (carry != 0) {
        dec->exp += 1;
        dec->sig.length = 1;
        *dec->sig.text = '1';
        return;
    } else if (new_length == 0) {
        goto return_zero;
    }
    dec->sig.length = new_length;
}

char *double2hex(char *buffer, void *format, f64 value) {
    void fn_8022E660(void *, void *);
    void strcpy(char *, const char *);
    char *long2str_802338EC(s32, char *, void *);

    typedef struct {
        u8 unk0;
        u8 sign_style;
        u8 unk2;
        u8 alternate;
        u8 unk4;
        u8 conv;
        u8 pad6[6];
        s32 precision;
    } PrintFormat;

    typedef struct {
        s8 kind;
        s8 pad;
        s16 width;
        s32 pad2;
    } DecCtrl;

    PrintFormat *fmt = (PrintFormat *)format;
    s32 prec = fmt->precision;
    u8 sp40[0x38];
    char sp30[16];
    char sp20[16];
    f64 sp18;
    DecCtrl sp10;
    f64 sp8;
    s32 i;
    char *out;
    char *p;
    s32 exp;
    s16 raw_exp;
    u32 sb;
    u8 b;
    s8 nibble;
    s32 ch;

    sp8 = value;
    sp18 = value;
    if (prec > 0x1FD) {
        return NULL;
    }

    sp10.kind = 0;
    sp10.width = 0x20;
    fn_8022E660(&sp10, sp40);

    if (sp40[5] == 'I') {
        if (*(s16 *)&sp18 & 0x8000) {
            out = buffer - 5;
            if (fmt->conv == 'A') {
                strcpy(out, double2hex_strpool + 1);
            } else {
                strcpy(out, double2hex_strpool + 6);
            }
        } else {
            out = buffer - 4;
            if (fmt->conv == 'A') {
                strcpy(out, double2hex_strpool + 0xB);
            } else {
                strcpy(out, double2hex_strpool + 0xF);
            }
        }
        return out;
    }

    if (sp40[5] == 'N') {
        if (*(u8 *)&sp8 & 0x80) {
            out = buffer - 5;
            if (fmt->conv == 'A') {
                strcpy(out, double2hex_strpool + 0x13);
            } else {
                strcpy(out, double2hex_strpool + 0x18);
            }
        } else {
            out = buffer - 4;
            if (fmt->conv == 'A') {
                strcpy(out, double2hex_strpool + 0x1D);
            } else {
                strcpy(out, double2hex_strpool + 0x21);
            }
        }
        return out;
    }

    sp30[0] = 1;
    sp30[1] = 1;
    sp30[2] = 0;
    sp30[3] = 0;
    sp30[4] = 0;
    sp30[5] = 0x64;
    *(s32 *)(sp30 + 8) = 0;
    *(s32 *)(sp30 + 12) = 1;
    *(s32 *)(sp20 + 0) = *(s32 *)(sp30 + 0);
    *(s32 *)(sp20 + 4) = *(s32 *)(sp30 + 4);
    *(s32 *)(sp20 + 8) = 0;
    *(s32 *)(sp20 + 12) = 1;

    raw_exp = (*(s16 *)&sp18 >> 4) & 0x7FF;
    exp = raw_exp - 0x3FF;
    p = long2str_802338EC(exp, buffer, sp20);

    if (fmt->conv == 'a') {
        p[-1] = 'p';
        out = p - 1;
    } else {
        p[-1] = 'P';
        out = p - 1;
    }

    for (i = fmt->precision; i >= 1; i--) {
        sb = (u32)i >> 31;
        b = ((u8 *)&sp8)[((s32)(sb + i) >> 1) + 1];
        if ((((i & 1) ^ (s32)sb) - (s32)sb) != 0) {
            nibble = (s8)(b & 0xF);
        } else {
            nibble = (s8)((b >> 4) & 0xF);
        }
        if (nibble < 0xA) {
            ch = nibble + '0';
        } else if (fmt->conv == 'a') {
            ch = nibble + 0x57;
        } else {
            ch = nibble + 0x37;
        }
        *--out = ch;
    }

    if (fmt->precision != 0 || fmt->alternate != 0) {
        *--out = '.';
    }

    out[-1] = '1';
    if (fmt->conv == 'a') {
        out[-2] = 'x';
        out -= 2;
    } else {
        out[-2] = 'X';
        out -= 2;
    }
    *--out = '0';

    if (*(s16 *)&sp18 & 0x8000) {
        *--out = '-';
    } else if (fmt->sign_style == 1) {
        *--out = '+';
    } else if (fmt->sign_style == 2) {
        *--out = ' ';
    }
    return out;
}

char *longlong2str_802335D8(s64 value, char *buffer, void *format)
{
    typedef struct {
        u8 just;
        u8 sign;
        u8 prec_set;
        u8 alt;
        u8 size;
        u8 conv;
        u16 pad;
        s32 width;
        s32 precision;
    } Format;
    u64 __div2u(u32, u32, u32, u32);
    u64 __mod2u(u32, u32, u32, u32);

    u64 val;
    u64 base;
    char *out;
    s32 count;
    s32 negative;
    Format *f;
    char *buf;
    s32 digit;

    val = value;
    f = (Format *)format;
    buf = buffer;
    out = buf;
    negative = 0;
    count = 0;
    *--out = 0;

    if (value == 0 && f->precision == 0 && !(f->alt && f->conv == 'o')) {
        return out;
    }

    switch (f->conv) {
    case 'd':
    case 'i':
        base = 10;
        if (value < 0) {
            val = -val;
            negative = 1;
        }
        break;
    case 'o':
        base = 8;
        f->sign = 0;
        break;
    case 'u':
        base = 10;
        f->sign = 0;
        break;
    case 'x':
    case 'X':
        base = 16;
        f->sign = 0;
        break;
    }

    do {
        digit = (u32)__mod2u((u32)((u64)val >> 32), (u32)(u64)val,
                             (u32)(base >> 32), (u32)base);
        val = __div2u((u32)((u64)val >> 32), (u32)(u64)val,
                           (u32)(base >> 32), (u32)base);
        if (digit < 10) {
            digit += '0';
        } else if (f->conv == 'x') {
            digit += 'a' - 10;
        } else {
            digit += 'A' - 10;
        }
        *--out = (char)digit;
        count++;
    } while (val != 0);

    if (base == 8 && f->alt && *out != '0') {
        *--out = '0';
        count++;
    }

    if (f->just == 2) {
        f->precision = f->width;
        if (negative || f->sign) {
            f->precision--;
        }
        if (base == 16 && f->alt) {
            f->precision -= 2;
        }
    }

    {
        s32 precision = f->precision;
        if (precision + (buf - out) > 509) {
            return 0;
        }

        while (count < precision) {
            *--out = '0';
            count++;
        }
    }

    if (base == 16 && f->alt) {
        *--out = f->conv;
        *--out = '0';
    }

    if (negative) {
        *--out = '-';
    } else if (f->sign == 1) {
        *--out = '+';
    } else if (f->sign == 2) {
        *--out = ' ';
    }

    return out;
}
#pragma optimization_level 3
char *long2str_802338EC(s32 value,char *buffer,void *format) {
    typedef struct {
        u8 just, sign, prec_set, alt, size, conv;
        u16 pad;
        s32 width, precision;
    } Format;
    Format *f=(Format *)format;
    u32 base;
    char *out=buffer;
    s32 count;
    s32 negative;
    s32 precision;
    s32 digit;
    u8 conv;
    negative=0;
    count=0;
    *--out=0;
    if(value==0 && f->precision==0 && !(f->alt && f->conv=='o')) return out;
    switch(f->conv) {
    case 'd': case 'i':
        base=10;
        if(value<0) { value=-value; negative=1; }
        break;
    case 'o': base=8; f->sign=0; break;
    case 'u': base=10; f->sign=0; break;
    case 'x': case 'X': base=16; f->sign=0; break;
    }
    conv=f->conv;
    do {
        digit=(u32)value%base;
        value=(u32)value/base;
        if(digit<10) digit+='0';
        else if(conv=='x') digit+='a'-10;
        else digit+='A'-10;
        *--out=digit;
        count++;
    } while((u32)value!=0);
    if(base==8 && f->alt && *out!='0') { *--out='0'; count++; }
    if(f->just==2) {
        f->precision=f->width;
        if(negative || f->sign) f->precision--;
        if(base==16 && f->alt) f->precision-=2;
    }
    precision=f->precision;
    if(precision+(buffer-out)>509) return 0;
    while(count<precision) { *--out='0'; count++; }
    if(base==16 && f->alt) {
        *--out=f->conv;
        *--out='0';
    }
    if(negative) *--out='-';
    else if(f->sign==1) *--out='+';
    else if(f->sign==2) *--out=' ';
    return out;
}
#pragma optimization_level reset
char *parse_format_80233B44(char *format, void *ap, void *out)
{
    void *__va_arg(void *, s32);
    extern u8 lbl_8029E8A8[];

    struct {
        u8 just;
        u8 sign;
        u8 prec_set;
        u8 alt;
        u8 size;
        u8 conv;
        u16 pad;
        s32 width;
        s32 precision;
    } f;
    char *p;
    s32 c;
    s32 cont;
    s32 *vp;
    s32 v;

    c = (s8)format[1];
    p = format + 1;

    f.sign = 0;
    f.just = 1;
    f.prec_set = 0;
    f.alt = 0;
    f.size = 0;
    f.width = 0;
    f.precision = 0;

    if (c == '%') {
        f.conv = (u8)c;
        *(u32 *)out = *(u32 *)&f.just;
        *(u32 *)((u8 *)out + 4) = *(u32 *)&f.size;
        *(s32 *)((u8 *)out + 8) = 0;
        *(s32 *)((u8 *)out + 12) = 0;
        return p + 1;
    }

    for (;;) {
        cont = 1;
        switch (c) {
        case '-':
            f.just = 0;
            break;
        case '+':
            f.sign = 1;
            break;
        case ' ':
            if (f.sign != 1) {
                f.sign = 2;
            }
            break;
        case '#':
            f.alt = 1;
            break;
        case '0':
            if (f.just != 0) {
                f.just = 2;
            }
            break;
        default:
            cont = 0;
            break;
        }
        if (cont == 0) {
            break;
        }
        c = (s8)*++p;
    }

    if (c == '*') {
        vp = __va_arg(ap, 1);
        v = *vp;
        f.width = v;
        if (v < 0) {
            f.just = 0;
            f.width = -v;
        }
        c = (s8)*++p;
    } else {
        while (lbl_8029E8A8[(u8)c] & 0x10) {
            f.width = f.width * 10 + (c - '0');
            c = (s8)*++p;
        }
    }

    if (f.width > 0x1FD) {
        f.conv = 0xFF;
        *(u32 *)out = *(u32 *)&f.just;
        *(u32 *)((u8 *)out + 4) = *(u32 *)&f.size;
        *(s32 *)((u8 *)out + 8) = f.width;
        *(s32 *)((u8 *)out + 12) = f.precision;
        return p + 1;
    }

    if (c == '.') {
        f.prec_set = 1;
        c = (s8)*++p;
        if (c == '*') {
            vp = __va_arg(ap, 1);
            v = *vp;
            f.precision = v;
            if (v < 0) {
                f.prec_set = 0;
            }
            c = (s8)*++p;
        } else {
            while (lbl_8029E8A8[(u8)c] & 0x10) {
                f.precision = f.precision * 10 + (c - '0');
                c = (s8)*++p;
            }
        }
    }

    cont = 1;
    switch (c) {
    case 'h':
        f.size = 2;
        if ((s8)p[1] == 'h') {
            f.size = 1;
            c = (s8)p[1];
            p += 1;
        }
    break;
    case 'l':
        f.size = 3;
        if ((s8)p[1] == 'l') {
            f.size = 4;
            c = (s8)p[1];
            p += 1;
        }
    break;
    case 'L':
        f.size = 5;
        break;
    default:
        cont = 0;
        break;
    }
    if (cont != 0) {
        c = (s8)*++p;
    }

    f.conv = (u8)c;
    switch (c) {
    case 'd':
    case 'i':
    case 'o':
    case 'u':
    case 'x':
    case 'X':
        if (f.size == 5) {
            f.conv = 0xFF;
        } else if (f.prec_set == 0) {
            f.precision = 1;
        } else if (f.just == 2) {
            f.just = 1;
        }
        break;
    case 'f':
    case 'F':
    case 'e':
    case 'E':
        if (f.size == 2 || f.size == 4) {
            f.conv = 0xFF;
        } else if (f.prec_set == 0) {
            f.precision = 6;
        }
        break;
    case 'a':
    case 'A':
        if (f.prec_set == 0) {
            f.precision = 0xD;
        }
        if (f.size == 2 || f.size == 4 || f.size == 1) {
            f.conv = 0xFF;
        }
        break;
    case 'g':
    case 'G':
        if (f.precision == 0) f.precision = 1;
        if (f.size == 2 || f.size == 4 || f.size == 1) f.conv = 0xFF;
        else if (f.prec_set == 0) f.precision = 6;
        break;
    case 'p':
        f.conv = 'x';
        f.alt = 1;
        f.size = 3;
        f.precision = 8;
        break;
    case 'n':
        if (f.size == 3) {
            f.size = 6;
        } else if (f.prec_set != 0 || f.size != 0) {
            f.conv = 0xFF;
        }
        break;
    case 's':
        if (f.size == 3) {
            f.size = 6;
        } else if (f.size != 0) {
            f.conv = 0xFF;
        }
        break;
    case 'c':
        if (f.size == 5) {
            f.conv = 0xFF;
        }
        break;
    default:
        f.conv = 0xFF;
        break;
    }

    *(u32 *)out = *(u32 *)&f.just;
    *(u32 *)((u8 *)out + 4) = *(u32 *)&f.size;
    *(s32 *)((u8 *)out + 8) = f.width;
    *(s32 *)((u8 *)out + 12) = f.precision;
    return p + 1;
}
#pragma optimization_level reset
s32 __StringRead(void *isc, s32 ch, s32 act)
{
    char ret;
    __InStrCtrl *Iscp = (__InStrCtrl *)isc;

    switch (act) {
    case 0:
        ret = *Iscp->NextChar;
        if (ret == '\0') {
            Iscp->NullCharDetected = 1;
            return -1;
        }
        Iscp->NextChar++;
        return (u8)ret;
    case 1:
        if (Iscp->NullCharDetected == 0) {
            Iscp->NextChar--;
        } else {
            Iscp->NullCharDetected = 0;
        }
        return ch;
    case 2:
        return Iscp->NullCharDetected;
    default:
        return 0;
    }
}

/* MSL raise: run the handler for sig (1..6), honoring SIG_IGN/SIG_DFL. */
s32 signal_raise(s32 sig) {
    extern void (*__signal_funcs[])(s32);
    extern s32 __begin_critical_region(s32);
    extern s32 __end_critical_region(s32);
    extern void exit(s32);
    void (*handler)(s32);

    if ((sig < 1) || (sig > 6)) {
        return -1;
    }
    __begin_critical_region(4);
    handler = __signal_funcs[sig - 1];
    if (handler != (void (*)(s32))1) {
        __signal_funcs[sig - 1] = 0;
    }
    __end_critical_region(4);
    if ((handler == (void (*)(s32))1) || ((handler == 0) && (sig == 1))) {
        return 0;
    }
    if (handler == 0) {
        exit(0);
    }
    handler(sig);
    return 0;
}

u8 *fn_80234198(u8 *str, u8 *pat) {
u8 *p; u8 c; u8 d; u8 e; u8 *q; u8 *r;
p=str-1;
if(!pat) return str;
c=*pat;
if(!c) return str;
goto outer;
match_check:
if(d!=c) goto outer;
q=p-1; r=pat-1;
do {
d=*++q; e=*++r;
if(d!=e) break;
} while(d!=0);
if(e!=0) goto outer;
return p;
outer:
d=*++p;
if(d!=0) goto match_check;
return 0;
}

void *fn_80234200(s32 arg0, u8 arg1) { u8 *p=(u8*)arg0-1; u32 needle=arg1; u8 *last=NULL; u32 c; while((c=*++p)!=0) { if(c==needle) last=p; } if(last!=NULL) return last; if(needle!=0) return NULL; return p; }

void *strchr(void *arg0, u8 arg1) {
    u8 *p = (u8 *)arg0 - 1;
    u32 needle = arg1;
    u32 c;
    while ((c = *++p) != 0) {
        if (c == needle) return p;
    }
    if (needle == 0) return p;
    return NULL;
}

s32 Str_NCmp(u8 *arg0, u8 *arg1, u32 arg2) {
    register u8 *s1 = arg0 - 1;
    register u8 *s2 = arg1 - 1;
    register u32 c1;
    register u32 c2;
    register u32 n = arg2 + 1;

    while (--n != 0) {
        c1 = *++s1;
        c2 = *++s2;
        if (c1 != c2) {
            return c1 - c2;
        }
        if (c1 == 0) {
            break;
        }
    }
    return 0;
}

s32 Str_Cmp(u8 *s1, u8 *s2) {
    // Word-at-a-time strcmp: align, then compare 4 bytes until a zero byte or mismatch.
    register u8 *left = s1;
    register u8 *right = s2;
    u32 align;
    u32 mask;
    register u32 l1;
    register u32 r1;
    register s32 x;

    l1 = *left;
    x = l1 - *right;
    if (x != 0) {
        return x;
    }
    if ((align = (u32)left & 3) != ((u32)right & 3)) {
        goto bytecopy;
    }
    if (align != 0) {
        if (l1 == 0) {
            return 0;
        }
        for (align = 3 - align; align != 0; align--) {
            l1 = *(++left);
            r1 = *(++right);
            x = l1 - r1;
            if (x != 0) {
                return x;
            }
            if (l1 == 0) {
                return 0;
            }
        }
        left++;
        right++;
    }
    l1 = *(u32 *)left;
    mask = 0x80808080;
    r1 = *(u32 *)right;
    if ((l1 - 0x01010101) & mask) {
        goto adjust;
    }
    while (l1 == r1) {
        left += 4;
        right += 4;
        l1 = *(u32 *)left;
        r1 = *(u32 *)right;
        if ((l1 - 0x01010101) & mask) {
            goto adjust;
        }
    }
    if (l1 > r1) {
        return 1;
    }
    return -1;

adjust:
    l1 = *left;
    x = l1 - *right;
    if (x != 0) {
        return x;
    }
bytecopy:
    if (l1 == 0) {
        return 0;
    }
    do {
        l1 = *(++left);
        x = l1 - *(++right);
        if (x != 0) {
            return x;
        }
    } while (l1 != 0);
    return 0;
}

u8 *strcat(u8 *dest, u8 *src)
{
    u8 *s;
    u8 *d;

    s = src - 1;
    d = dest - 1;
    while (*++d != 0) {
    }
    d--;
    while ((*++d = *++s) != 0) {
    }
    return dest;
}

char *Str_CopyPad(char *dest, const char *src, s32 count) { const unsigned char *s=(const unsigned char*)src-1; unsigned char *d=(unsigned char*)dest-1; count++; while (--count != 0) { unsigned char value=*++s; *++d=value; if (value==0) { while (--count != 0) *++d=0; return dest; } } return dest; }

char *strcpy(char *dst, const char *src) {
    register u8 *d = (u8 *)dst;
    register u8 *s = (u8 *)src;
    u32 align;
    u32 mask;
    register u32 w;
    register u32 c;
    if (((u32)d & 3) != (align = (u32)s & 3)) goto bytecopy;
    if (align != 0) {
        c = *d = *s;
        if (c == 0) return dst;
        for (align = 3 - align; align != 0; align--) {
            c = *++s;
            *++d = c;
            if (c == 0) return dst;
        }
        d++;
        s++;
    }
    w = *(u32 *)s;
    mask = 0x80808080;
    if (((w - 0x01010101) & mask) == 0) {
        d -= 4;
        do {
            *(u32 *)(d += 4) = w;
            w = *(u32 *)(s += 4);
        } while (((w - 0x01010101) & mask) == 0);
        d += 4;
    }
bytecopy:
    c = *d = *s;
    if (c == 0) return dst;
    do {
        c = *++s;
        *++d = c;
    } while (c != 0);
    return dst;
}

s32 strlen(const char *str) {
    const u8 *s = (const u8 *)str - 1;
    s32 length = -1;
    u32 c;
    do {
        c = *++s;
        ++length;
    } while (c != 0);
    return length;
}

f64 fn_80234524(char *arg0) {
f64 fn_802345B0(s32,s32 (*)(),void *,s32 *,s32 *);
extern s32 __StringRead();
extern f64 lbl_80367070[], lbl_80367078[];
extern f64 lbl_8036BE10;
extern s32 errno;
f64 value, magnitude;
__InStrCtrl isc;
s32 overflow, count;
isc.NextChar=arg0;
isc.NullCharDetected=0;
value=fn_802345B0(0x7fffffff,__StringRead,&isc,&count,&overflow);
magnitude=__fabs(value);
if (overflow || (lbl_8036BE10 != value && (magnitude < lbl_80367070[0] || magnitude > lbl_80367078[0]))) errno=0x22;
return value;
}

f64 fn_8022D5E0(void *);
f64 fn_802345B0(s32 arg0, s32 (*arg1)(void *, s32, s32), void *arg2, s32 *arg3, s32 *arg4)
{
    extern u8 lbl_80282C88[];
    extern u8 *lbl_8029EBA8[];
    extern u8 lbl_8029E8A8[];
    extern u8 lbl_8029EAA8[];
    extern u8 lbl_80282CB4[];
    extern f32 lbl_8036706C[];
    extern f32 lbl_80367068[];
    extern f64 lbl_80367080[];
    extern f64 lbl_80367088[];
    extern f64 lbl_80367090[];
    extern s32 lbl_8036BE08;
    extern u8 lbl_8036BE0C;
    extern f64 lbl_8036BE10;
    extern f64 lbl_8036BE18;
    f64 fn_8022D5E0(void *);

    typedef union {
        f64 d;
        u32 w[2];
        u16 h[4];
        s16 sh[4];
        u8 b[8];
        unsigned long long bits;
    } DoubleBits;

    s32 sp60 = 0;
    s32 sp5C = 0;
    s32 sp58 = 0;
    u8 buf[0x2C];
    DoubleBits value;
    u8 infbuf[12];
    u8 nanbuf[8];
    s32 state = 1;
    s32 hexphase = 0;
    s32 skipped = 0;
    s32 expv = 0;
    s32 trail = 0;
    s32 neg = 0;
    s32 pos = 1;
    s32 ch;
    s32 cls;
    s32 n;
    s32 i;
    s32 mask;
    s32 hexCount = 2;
    s32 wholeHexDigits = 0;
    s32 hexSuffix = 0;
    s16 hexexp = 0;
    u8 decimal;
    u8 *p;
    f32 f;

    {
        const u32 *srcWords = (const u32 *)lbl_80282C88;
        u32 *dstWords = (u32 *)buf;
        u32 w0 = srcWords[0];
        u32 w1 = srcWords[1];
        u32 w2 = srcWords[2];
        u32 w3 = srcWords[3];
        u32 w4 = srcWords[4];
        u32 w5 = srcWords[5];
        u32 w6 = srcWords[6];
        u32 w7 = srcWords[7];
        u32 w8 = srcWords[8];
        u32 w9 = srcWords[9];
        u16 last = *(const u16 *)(lbl_80282C88 + 0x28);

        dstWords[0] = w0;
        dstWords[1] = w1;
        dstWords[3] = w3;
        dstWords[4] = w4;
        dstWords[2] = w2;
        dstWords[5] = w5;
        dstWords[6] = w6;
        dstWords[7] = w7;
        dstWords[8] = w8;
        dstWords[9] = w9;
        *(u16 *)(buf + 0x28) = last;
    }
    decimal = *lbl_8029EBA8[0];
    *arg4 = 0;
    ch = arg1(arg2, 0, 0);

    goto parse_check;
parse_next:
    switch (state) {
        case 1:
            if (lbl_8029E8A8[(u8)ch] & 6) {
                ch = arg1(arg2, 0, 0);
                skipped++;
            } else {
                cls = (ch == -1) ? -1 : (s32)lbl_8029EAA8[(u8)ch];
                switch (cls) {
                case 0x2D:
                    neg = 1;
                    pos++;
                    ch = arg1(arg2, 0, 0);
                    sp5C = 1;
                    break;
                case 0x2B:
                    pos++;
                    ch = arg1(arg2, 0, 0);
                    sp5C = 1;
                    break;
                case 0x49:
                    pos++;
                    state = 0x4000;
                    ch = arg1(arg2, 0, 0);
                    break;
                case 0x4E:
                    pos++;
                    state = 0x2000;
                    ch = arg1(arg2, 0, 0);
                    break;
                default:
                    state = 2;
                    break;
                }
            }
            break;

        case 0x4000:
            p = &infbuf[1];
            n = 1;
            *(s32 *)infbuf = *(s32 *)lbl_80282CB4;
            *(s32 *)(infbuf + 4) = *(s32 *)(lbl_80282CB4 + 4);
            infbuf[8] = lbl_80282CB4[8];
            goto inf_check;
inf_advance:
            p++;
            n++;
            pos++;
            ch = arg1(arg2, 0, 0);
inf_check:
            if (n < 8) {
                cls = (ch == -1) ? -1 : (s32)lbl_8029EAA8[(u8)ch];
                if ((s8)*p == cls)
                    goto inf_advance;
            }
            if (n == 3 || n == 8) {
                f = neg ? -lbl_8036706C[0] : lbl_8036706C[0];
                value.d = f;
                *arg3 = skipped + n + sp5C;
                return value.d;
            }
            state = 0x1000;
            break;

        case 0x2000:
            p = &nanbuf[1];
            n = 1;
            *(s32 *)nanbuf = lbl_8036BE08;
            nanbuf[4] = lbl_8036BE0C;
            i = 0;
            goto nan_check;
nan_advance:
            p++;
            n++;
            pos++;
            ch = arg1(arg2, 0, 0);
nan_check:
            if (n < 4) {
                cls = (ch == -1) ? -1 : (s32)lbl_8029EAA8[(u8)ch];
                if ((s8)*p == cls)
                    goto nan_advance;
            }
            if (n == 3 || n == 4) {
                if (n == 4) {
                    while (i < 0x20 &&
                           ((lbl_8029E8A8[(u8)ch] & 0x10) ||
                            (lbl_8029E8A8[(u8)ch] & 0xC0))) {
                        i++;
                        pos++;
                        ch = arg1(arg2, 0, 0);
                    }
                    if (ch != 0x29) {
                        state = 0x1000;
                        break;
                    }
                    i++;
                }
                f = neg ? -lbl_80367068[0] : lbl_80367068[0];
                value.d = f;
                *arg3 = skipped + n + i + sp5C;
                return value.d;
            }
            state = 0x1000;
            break;

        case 2:
            if (ch == (s32)decimal) {
                state = 0x10;
                pos++;
                ch = arg1(arg2, 0, 0);
            } else if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                state = 0x1000;
            } else if (ch == 0x30) {
                pos++;
                ch = arg1(arg2, 0, 0);
                cls = (ch == -1) ? -1 : (s32)lbl_8029EAA8[(u8)ch];
                if (cls == 0x58) {
                    hexphase = 1;
                    state = 0x8000;
                } else {
                    state = 4;
                }
            } else {
                state = 8;
            }
            break;

        case 4:
            if (ch == 0x30) {
                pos++;
                ch = arg1(arg2, 0, 0);
            } else {
                state = 8;
            }
            break;

        case 8:
            if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                if (ch == (s32)decimal) {
                    state = 0x20;
                    pos++;
                    ch = arg1(arg2, 0, 0);
                } else {
                    state = 0x40;
                }
            } else {
                if (buf[4] < 0x14) {
                    u8 length = buf[4];
                    buf[4] = length + 1;
                    buf[5 + length] = (u8)ch;
                } else {
                    trail++;
                }
                pos++;
                ch = arg1(arg2, 0, 0);
            }
            break;

        case 0x10:
            if (!(lbl_8029E8A8[(u8)ch] & 0x10))
                state = 0x1000;
            else
                state = 0x20;
            break;

        case 0x20:
            if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                state = 0x40;
            } else {
                if (buf[4] < 0x14) {
                    if (ch != 0x30 || buf[4] != 0) {
                        u8 length = buf[4];
                        buf[4] = length + 1;
                        buf[5 + length] = (u8)ch;
                    }
                    trail--;
                }
                pos++;
                ch = arg1(arg2, 0, 0);
            }
            break;

        case 0x40:
            cls = (ch == -1) ? -1 : (s32)lbl_8029EAA8[(u8)ch];
            if (cls == 0x45) {
                state = 0x80;
                pos++;
                ch = arg1(arg2, 0, 0);
            } else {
                state = 0x800;
            }
            break;

        case 0x80:
            if (ch == 0x2B) {
                pos++;
                ch = arg1(arg2, 0, 0);
            } else if (ch == 0x2D) {
                pos++;
                ch = arg1(arg2, 0, 0);
                sp60 = 1;
            }
            state = 0x100;
            break;

        case 0x100:
            if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                state = 0x1000;
            } else if (ch == 0x30) {
                state = 0x200;
                pos++;
                ch = arg1(arg2, 0, 0);
            } else {
                state = 0x400;
            }
            break;

        case 0x200:
            if (ch == 0x30) {
                pos++;
                ch = arg1(arg2, 0, 0);
            } else {
                state = 0x400;
            }
            break;

        case 0x400:
            if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                state = 0x800;
            } else {
                expv = (ch + expv * 10) - 0x30;
                if (expv > 0x7FFF)
                    *arg4 = 1;
                pos++;
                ch = arg1(arg2, 0, 0);
            }
            break;

        case 0x8000:
            switch (hexphase) {
            case 1:
                value.b[0] = 0;
                value.b[1] = 0;
                value.b[2] = 0;
                value.b[3] = 0;
                value.b[4] = 0;
                value.b[5] = 0;
                value.b[6] = 0;
                value.b[7] = 0;
                hexCount = 2;
                hexphase = 2;
                pos++;
                ch = arg1(arg2, 0, 0);
                break;

            case 2:
                if (ch == 0x30) {
                    pos++;
                    ch = arg1(arg2, 0, 0);
                } else {
                    hexphase = 4;
                }
                break;

            case 4:
                if (!(lbl_8029E8A8[(u8)ch] & 0x20)) {
                    if (ch == (s32)decimal) {
                        hexphase = 8;
                        pos++;
                        ch = arg1(arg2, 0, 0);
                    } else {
                        hexphase = 0x10;
                    }
                } else {
                    if (hexCount < 0x11) {
                        s32 digit;
                        s32 index = hexCount / 2;
                        u8 old = value.b[index];
                        cls = (ch == -1) ? -1 : (s32)lbl_8029EAA8[(u8)ch];
                        digit = cls >= 0x41 ? cls - 0x37 : cls - 0x30;
                        if (hexCount % 2)
                            value.b[index] = (u8)(old | digit);
                        else
                            value.b[index] = (u8)(old | ((u8)digit << 4));
                        hexCount++;
                        wholeHexDigits++;
                    }
                    pos++;
                    ch = arg1(arg2, 0, 0);
                }
                break;

            case 8:
                if (!(lbl_8029E8A8[(u8)ch] & 0x20)) {
                    hexphase = 0x10;
                } else {
                    if (hexCount < 0x11) {
                        s32 digit;
                        s32 index = hexCount / 2;
                        u8 old = value.b[index];
                        cls = (ch == -1) ? -1 : (s32)lbl_8029EAA8[(u8)ch];
                        digit = cls >= 0x41 ? cls - 0x37 : cls - 0x30;
                        if (hexCount % 2)
                            value.b[index] = (u8)(old | digit);
                        else
                            value.b[index] = (u8)(old | ((u8)digit << 4));
                        hexCount++;
                    }
                    pos++;
                    ch = arg1(arg2, 0, 0);
                }
                break;

            case 0x10:
                cls = (ch == -1) ? -1 : (s32)lbl_8029EAA8[(u8)ch];
                if (cls == 0x50) {
                    hexphase = 0x20;
                    hexSuffix++;
                    pos++;
                    ch = arg1(arg2, 0, 0);
                } else {
                    state = 0x800;
                }
                break;

            case 0x20:
                hexSuffix++;
                if (ch == 0x2D) {
                    sp58 = 1;
                } else if (ch != 0x2B) {
                    arg1(arg2, ch, 1);
                    hexSuffix--;
                }
                hexphase = 0x40;
                pos++;
                ch = arg1(arg2, 0, 0);
                break;

            case 0x40:
                if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                    state = 0x1000;
                } else if (ch == 0x30) {
                    hexphase = 0x80;
                    hexSuffix++;
                    pos++;
                    ch = arg1(arg2, 0, 0);
                } else {
                    hexphase = 0x100;
                }
                break;

            case 0x80:
                if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                    state = 0x800;
                } else if (ch == 0x30) {
                    hexSuffix++;
                    pos++;
                    ch = arg1(arg2, 0, 0);
                } else {
                    hexphase = 0x100;
                }
                break;

            case 0x100:
                if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                    state = 0x800;
                } else {
                    hexexp = (s16)((hexexp * 10 + ch) - 0x30);
                    if (expv > 0x7FFF)
                        *arg4 = 1;
                    hexSuffix++;
                    pos++;
                    ch = arg1(arg2, 0, 0);
                }
                break;

            default:
                break;
            }
            break;

        default:
            state = 0x1000;
            break;
    }
parse_check:
    if (pos <= arg0 && ch != -1 && !(state & 0x1800))
        goto parse_next;

    mask = state & 0xE2C;
    if (mask == 0)
        *arg3 = 0;
    else
        *arg3 = (pos + skipped) - 1;

    arg1(arg2, ch, 1);

    if (hexphase == 0) {
        if (sp60)
            expv = -expv;
        {
            s32 nd = buf[4];
            u8 *q = buf + 5 + nd;
            for (;;) {
                if (nd-- == 0)
                    break;
                if (*--q != 0x30)
                    break;
                trail++;
            }
            buf[4] = (u8)(nd + 1);
        }
        if (buf[4] == 0) {
            s32 nd = buf[4];
            buf[4] = (u8)(nd + 1);
            buf[5 + nd] = 0x30;
        }
        expv += trail;
        if (expv < -0x8000 || expv > 0x7FFF)
            *arg4 = 1;

        if (*arg4 != 0) {
            if (sp60)
                return lbl_8036BE10;
            if (neg)
                return -lbl_80367080[0];
            return lbl_80367080[0];
        }

        *(s16 *)(buf + 2) = (s16)expv;
        value.d = fn_8022D5E0(buf);
        if (lbl_8036BE10 != value.d && value.d < lbl_80367088[0]) {
            *arg4 = 1;
        } else if (value.d > lbl_80367090[0]) {
            *arg4 = 1;
            value.d = lbl_80367080[0];
        }
        if (neg && mask != 0)
            value.d = -value.d;
        return value.d;
    }

    if (value.d != lbl_8036BE18) {
        if (sp58)
            hexexp = (s16)-hexexp;
        hexexp++;
        value.bits >>= 1;
        {
            s16 head = value.sh[0];
            if ((head & 0xF0) == 0x10) {
                head &= 0xF;
                hexexp = (s16)(hexexp + (wholeHexDigits - 1) * 4);
                value.h[0] = (u16)(head | ((u32)(hexexp + 0x3FF) << 4));
                *arg3 = skipped + sp5C + hexCount + 1 + hexSuffix;
                if (lbl_8036BE10 != value.d && value.d < lbl_80367088[0]) {
                    *arg4 = 1;
                    value.d = lbl_8036BE10;
                } else if (value.d > lbl_80367090[0]) {
                    *arg4 = 1;
                    value.d = lbl_80367080[0];
                }
            }
        }
        if (neg)
            value.sh[0] |= (s16)0x8000;
    } else {
        value.d = lbl_8036BE10;
    }
    return value.d;
}

s32 atoi(char *str) {
    extern s32 errno;
    extern s32 __StringRead();
    extern u32 __strtoul(s32, s32, s32 (*)(), void *, s32 *, s32 *, s32 *);
    u32 value;
    s32 overflow;
    s32 negative;
    s32 count;
    __InStrCtrl isc;

    // Parse a decimal C string to s32; clamp to INT_MIN/INT_MAX and set errno=ERANGE on overflow.
    isc.NextChar = str;
    isc.NullCharDetected = 0;
    value = __strtoul(10, 0x7FFFFFFF, __StringRead, &isc, &count, &negative, &overflow);
    if (overflow || (!negative && value > 0x7FFFFFFF) || (negative && value > 0x80000000)) {
        value = negative ? 0x80000000 : 0x7FFFFFFF;
        errno = 0x22;
    } else if (negative) {
        value = -value;
    }
    return value;
}

#pragma use_lmw_stmw on
extern u8 lbl_8029E8A8[];
extern u8 lbl_8029EAA8[];
#pragma opt_strength_reduction off
u32 __strtoul(s32 base, s32 max_width, s32 (*ReadProc)(void *, s32, s32), void *ReadProcArg,
                s32 *chars_scanned, s32 *negative, s32 *overflow) {
    s32 state;
    s32 count;
    s32 (*rp)(void *, s32, s32);
    s32 b;
    void *rpa;
    u32 value;
    u32 limit;
    s32 *ovfp;
    s32 spaces;
    s32 mw;
    s32 *negp;
    s32 *csp;
    s32 c;
    u8 cls;

    b = base;
    mw = max_width;
    rp = ReadProc;
    rpa = ReadProcArg;
    csp = chars_scanned;
    negp = negative;
    ovfp = overflow;

    *ovfp = 0;
    *negp = 0;
    state = 1;
    count = 0;
    spaces = 0;
    value = 0;
    limit = 0;

    if (b < 0 || b == 1 || b > 36 || mw < 1) {
        state = 0x40;
    } else {
        c = (count++, (*rp)(rpa, 0, 0));
    }
    if (b != 0) limit = 0xFFFFFFFFu / (u32)b;
    while (count <= mw && c != -1 && !(state & 0x60)) {
    switch (state) {
    case 1:
        if ((lbl_8029E8A8[c & 0xFF] & 6) != 0) {
            c = (*rp)(rpa, 0, 0);
            spaces++;
            break;
        }
        if (c == '+') {
            count++;
            c = (*rp)(rpa, 0, 0);
        } else if (c == '-') {
            count++;
            c = (*rp)(rpa, 0, 0);
            *negp = 1;
        }
        state = 2;
        break;
    case 2:
        if (b == 0 || b == 16) {
            if (c == '0') {
                state = 4;
                count++;
                c = (*rp)(rpa, 0, 0);
                break;
            }
        }
        state = 8;
        break;
    case 4:
        if (c == 'X' || c == 'x') {
            b = 16;
            state = 8;
            count++;
            c = (*rp)(rpa, 0, 0);
            break;
        }
        if (b == 0) {
            b = 8;
        }
        state = 0x10;
        break;
    case 8:
        if (b == 0) {
            b = 10;
        }
        if (limit == 0) {
            limit = 0xFFFFFFFFu / (u32)b;
        }
        /* fall through */
    case 0x10:
        cls = lbl_8029E8A8[c & 0xFF];
        if (cls & 0x10) {
            c -= '0';
            if (c >= b) {
                state = (state == 0x10) ? 0x20 : 0x40;
                c += '0';
                break;
            }
        } else {
            if (!(cls & 0xC0) || ((c == -1 ? -1 : (s32)lbl_8029EAA8[c & 0xFF]) - 0x37) >= b) {
                if (state == 0x10) state = 0x20;
                else state = 0x40;
                break;
            }
            c = (c == -1 ? -1 : (s32)lbl_8029EAA8[c & 0xFF]) - 0x37;
        }
        if (value > limit) {
            *ovfp = 1;
        }
        value *= b;
        if ((u32)c > 0xFFFFFFFFu - value) {
            *ovfp = 1;
        }
        value += c;
        state = 0x10;
        count++;
        c = (*rp)(rpa, 0, 0);
        break;
    default:
        break;
    }

    }

    if ((state & 0x34) == 0) {
        value = 0;
        *csp = 0;
    } else {
        count += spaces;
        *csp = count - 1;
    }
    (*rp)(rpa, c, 1);
    return value;
}
#pragma opt_strength_reduction reset
s32 fwide(void *arg0, s32 arg1) {
u8 *stream=arg0;
s32 orientation;
u8 flags;
if (!stream || !((*(u16*)(stream+4)>>6)&7)) return 0;
flags=stream[5];
orientation=(flags>>4)&3;
switch (orientation) {
case 0:
if (arg1>0) stream[5]=__rlwimi(flags,2,4,26,27);
else if (arg1<0) stream[5]=__rlwimi(flags,1,4,26,27);
return arg1;
case 2: return 1;
case 1: return -1;
}
return (s32)arg0;
}

/* MSL console write: on non-TDEV, init/write EXI UART then always hand off to GDEV path. */
s32 __write_console(s32 handle, s32 buffer, s32 *count, s32 ref) {
    s32 OSGetConsoleType(void);
    M2C_UNK fn_8022B530(s32, s32, s32 *, s32);
    s32 InitializeUART(M2C_UNK);
    s32 WriteUARTN(s32, s32);
    extern s32 UART_Initialized;
    s32 err;

    if (!(OSGetConsoleType() & 0x20000000)) {
        err = 0;
        if ((s32) UART_Initialized == 0) {
            err = InitializeUART(0xE100);
            if (err == 0) {
                UART_Initialized = 1;
            }
        }
        if (err != 0) {
            return 1;
        }
        if (WriteUARTN(buffer, *count) != 0) {
            *count = 0;
            return 1;
        }
        goto block_8;
    }
block_8:
    fn_8022B530(handle, buffer, count, ref);
    return 0;
}

f64 fn_80235B4C(f64 x) {
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
    extern f32 lbl_80367068[];
    extern f64 fn_80238A9C(f64);
    f64 y, z, h, p, q, r, s, w, c, df, sp8;
    s32 hx, ix;

    sp8 = x;
    hx = *(s32 *)&sp8;
    ix = hx & 0x7FFFFFFF;
    if (ix >= 0x3FF00000) {
        if (((ix - 0x3FF00000) | *(s32 *)((s8 *)&sp8 + 4)) == 0) {
            if (hx > 0)
                return lbl_8036BE20;
            return lbl_8036BE28;
        }
        return lbl_80367068[0];
    }
    if (ix < 0x3FE00000) {
        if (ix <= 0x3C600000)
            return lbl_8036BE30;
        y = x * x;
        p = ((((lbl_8036BE68 * y + lbl_8036BE60) * y + lbl_8036BE58) * y + lbl_8036BE50) * y + lbl_8036BE48) * y + lbl_8036BE40;
        q = (((lbl_8036BE90 * y + lbl_8036BE88) * y + lbl_8036BE80) * y + lbl_8036BE78) * y + lbl_8036BE70;
        r = (y * p) / q;
        s = lbl_8036BE38 - (x * r);
        return lbl_8036BE30 - (x - s);
    }
    if (hx < 0) {
        z = lbl_8036BE98 * (lbl_8036BE70 + x);
        h = fn_80238A9C(z);
        p = ((((lbl_8036BE68 * z + lbl_8036BE60) * z + lbl_8036BE58) * z + lbl_8036BE50) * z + lbl_8036BE48) * z + lbl_8036BE40;
        q = (((lbl_8036BE90 * z + lbl_8036BE88) * z + lbl_8036BE80) * z + lbl_8036BE78) * z + lbl_8036BE70;
        r = (z * p) / q;
        w = (r * h) - lbl_8036BE38;
        return lbl_8036BE28 - (lbl_8036BEA0 * (h + w));
    }
    z = lbl_8036BE98 * (lbl_8036BE70 - x);
    h = fn_80238A9C(z);
    df = h;
    p = lbl_8036BE68 * z + lbl_8036BE60;
    *(s32 *)((s8 *)&df + 4) = 0;
    p = (z * p + lbl_8036BE58) * z + lbl_8036BE50;
    c = z - df * df;
    q = lbl_8036BE90 * z + lbl_8036BE88;
    p = (z * p + lbl_8036BE48) * z + lbl_8036BE40;
    q = ((z * q + lbl_8036BE80) * z + lbl_8036BE78) * z + lbl_8036BE70;
    s = c / (h + df);
    r = (z * p) / q;
    w = r * h + s;
    return lbl_8036BEA0 * (df + w);
}

/* IEEE754 double remainder: return x - n*y for integer n, same sign as x. */
f64 __ieee754_fmod(f64 x, f64 y) {
    extern f64 fmod_Zero[];
    int n, hx, hy, hz, ix, iy, sx, i;
    unsigned lx, ly, lz;

    hy = *(int *)&y;
    hx = *(int *)&x;
    ly = *(1 + (unsigned *)&y);
    sx = hx & 0x80000000;
    hx ^= sx;
    hy &= 0x7fffffff;
    lx = *(1 + (unsigned *)&x);

    if ((hy | ly) == 0 || (hx >= 0x7ff00000) ||
        ((hy | ((ly | -ly) >> 31)) > 0x7ff00000))
        return (x * y) / (x * y);
    if (hx <= hy) {
        if ((hx < hy) || (lx < ly))
            return x;
        if (lx == ly)
            return fmod_Zero[(unsigned)sx >> 31];
    }

    if (hx < 0x00100000) {
        if (hx == 0) {
            for (ix = -1043, i = lx; i > 0; i <<= 1)
                ix -= 1;
        } else {
            for (ix = -1022, i = (hx << 11); i > 0; i <<= 1)
                ix -= 1;
        }
    } else
        ix = (hx >> 20) - 1023;

    if (hy < 0x00100000) {
        if (hy == 0) {
            for (iy = -1043, i = ly; i > 0; i <<= 1)
                iy -= 1;
        } else {
            for (iy = -1022, i = (hy << 11); i > 0; i <<= 1)
                iy -= 1;
        }
    } else
        iy = (hy >> 20) - 1023;

    if (ix >= -1022)
        hx = 0x00100000 | (0x000fffff & hx);
    else {
        n = -1022 - ix;
        if (n <= 31) {
            hx = (hx << n) | (lx >> (32 - n));
            lx <<= n;
        } else {
            hx = lx << (n - 32);
            lx = 0;
        }
    }
    if (iy >= -1022)
        hy = 0x00100000 | (0x000fffff & hy);
    else {
        n = -1022 - iy;
        if (n <= 31) {
            hy = (hy << n) | (ly >> (32 - n));
            ly <<= n;
        } else {
            hy = ly << (n - 32);
            ly = 0;
        }
    }

    n = ix - iy;
    while (n--) {
        hz = hx - hy;
        lz = lx - ly;
        if (lx < ly)
            hz -= 1;
        if (hz < 0) {
            hx = hx + hx + (lx >> 31);
            lx = lx + lx;
        } else {
            if ((hz | lz) == 0)
                return fmod_Zero[(unsigned)sx >> 31];
            hx = hz + hz + (lz >> 31);
            lx = lz + lz;
        }
    }
    hz = hx - hy;
    lz = lx - ly;
    if (lx < ly)
        hz -= 1;
    if (hz >= 0) {
        hx = hz;
        lx = lz;
    }

    if ((hx | lx) == 0)
        return fmod_Zero[(unsigned)sx >> 31];
    while (hx < 0x00100000) {
        hx = hx + hx + (lx >> 31);
        lx = lx + lx;
        iy -= 1;
    }
    if (iy >= -1022) {
        hx = ((hx - 0x00100000) | ((iy + 1023) << 20));
        *(int *)&x = hx | sx;
        *(1 + (unsigned *)&x) = lx;
    } else {
        n = -1022 - iy;
        if (n <= 20) {
            lx = (lx >> n) | ((unsigned)hx << (32 - n));
            hx >>= n;
        } else if (n <= 31) {
            lx = ((unsigned)hx << (32 - n)) | (lx >> n);
            hx = sx;
        } else {
            lx = hx >> (n - 32);
            hx = sx;
        }
        *(int *)&x = hx | sx;
        *(1 + (unsigned *)&x) = lx;
    }
    return x;
}

double fn_802360C4(double x, double y)
{
    typedef union {
        double d;
        struct {
            unsigned int hi;
            unsigned int lo;
        } w;
    } DoubleBits;

    extern double fn_80238A9C(double);
    extern double fn_80238378(double, int);
    extern int errno;

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
    int hx, hy, ix, iy;
    unsigned int lx, ly;
    DoubleBits bits;

    bits.d = y;
    hy = (int)bits.w.hi;
    ly = bits.w.lo;

    bits.d = x;
    hx = (int)bits.w.hi;
    lx = bits.w.lo;

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

    bits.d = x;
    bits.w.hi &= 0x7fffffff;
    ax = bits.d;

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

    n = (hx >> 31) + 1;

    if ((n | yisint) == 0) {
        errno = 33;
        return (x - x) / (x - x);
    }

    s = one;

    if ((n | (yisint - 1)) == 0)
        s = -one;

    if (iy > 0x41e00000) {
        if (iy > 0x43f00000) {
            if (ix <= 0x3fefffff)
                return hy < 0 ? huge * huge : tiny * tiny;

            if (ix >= 0x3ff00000)
                return hy > 0 ? huge * huge : tiny * tiny;
        }

        if (ix < 0x3fefffff)
            return hy < 0 ? s * huge * huge : s * tiny * tiny;

        if (ix > 0x3ff00000)
            return hy > 0 ? s * huge * huge : s * tiny * tiny;

        t = ax - one;
        w = (t * t) *
            (0.5 - t * (0.3333333333333333333333 - t * 0.25));

        u = ivln2_h * t;
        v = t * ivln2_l - w * ivln2;

        t1 = u + v;
        bits.d = t1;
        bits.w.lo = 0;
        t1 = bits.d;

        t2 = v - (t1 - u);
    } else {
        n = 0;

        if (ix < 0x00100000) {
            ax *= two53;
            n -= 53;
            bits.d = ax;
            ix = bits.w.hi;
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

        bits.d = ax;
        bits.w.hi = ix;
        ax = bits.d;

        u = ax - bp[k];
        v = one / (ax + bp[k]);
        ss = u * v;

        s_h = ss;
        bits.d = s_h;
        bits.w.lo = 0;
        s_h = bits.d;

        t_h = zero;
        bits.d = t_h;
        bits.w.hi = ((ix >> 1) | 0x20000000) +
                    0x00080000 + (k << 18);
        t_h = bits.d;

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

        bits.d = t_h;
        bits.w.lo = 0;
        t_h = bits.d;

        t_l = r - ((t_h - 3.0) - s2);

        u = s_h * t_h;
        v = s_l * t_h + t_l * ss;

        p_h = u + v;
        bits.d = p_h;
        bits.w.lo = 0;
        p_h = bits.d;

        p_l = v - (p_h - u);

        z_h = cp_h * p_h;
        z_l = cp_l * p_h + p_l * cp + dp_l[k];

        t = (double)n;
        t1 = ((z_h + z_l) + dp_h[k]) + t;

        bits.d = t1;
        bits.w.lo = 0;
        t1 = bits.d;

        t2 = z_l - (((t1 - t) - dp_h[k]) - z_h);
    }

    y1 = y;
    bits.d = y1;
    bits.w.lo = 0;
    y1 = bits.d;

    p_l = (y - y1) * t1 + y * t2;
    p_h = y1 * t1;

    z = p_l + p_h;
    bits.d = z;
    j = (int)bits.w.hi;
    i = (int)bits.w.lo;

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
        bits.d = t;
        bits.w.hi = n & ~(0x000fffff >> k);
        t = bits.d;

        n = ((n & 0x000fffff) | 0x00100000) >> (20 - k);

        if (j < 0)
            n = -n;

        p_h -= t;
    }

    t = p_l + p_h;
    bits.d = t;
    bits.w.lo = 0;
    t = bits.d;

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

    bits.d = z;
    j = (int)bits.w.hi;
    j += n << 20;

    if ((j >> 20) <= 0) {
        z = fn_80238378(z, n);
    } else {
        bits.w.hi += n << 20;
        z = bits.d;
    }

    return s * z;
}

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

s32 fn_80236D88(const f64 *x, f64 *y, s32 e0, s32 nx, s32 prec, const s32 *ipio2)
{
    extern s32 lbl_80282E88[];
    extern f64 lbl_80282E98[];
    extern f64 lbl_8036C058;
    extern f64 lbl_8036C060;
    extern f64 lbl_8036C068;
    extern f64 lbl_8036C070;
    extern f64 lbl_8036C078;
    extern f64 lbl_8036C080;
    extern f64 lbl_8036C088;
    f64 fn_80238378(f64, s32);
    f64 floor(f64);
    s32 jz, jx, jv, jp, jk, carry, n, iq[20], i, j, k, m, q0, ih;
    f64 z, fw, f[20], fq[20], q[20];
    register f64 twon24, two24, eighth, eight, zero;

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
    {
        const s32 *from = ipio2 + j;
        f64 *to = f;
        for (i = 0; i <= m; i++, j++, from++, to++) {
            if (j < 0) {
                *to = lbl_8036C058;
            } else {
                *to = (f64)(*from);
            }
        }
    }

    for (i = 0; i <= jk; i++) {
        const f64 *px = x;
        const f64 *pf = f + jx + i;
        fw = lbl_8036C058;
        for (j = 0; j <= jx; j++) {
            fw += (*px++) * (*pf--);
        }
        q[i] = fw;
    }

    twon24 = lbl_8036C060;
    two24 = lbl_8036C068;
    eighth = lbl_8036C078;
    eight = lbl_8036C070;
    zero = lbl_8036C058;

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
    z -= eight * floor(z * eighth);
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
    } else if (z >= lbl_8036C080) {
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
            z = lbl_8036C088 - z;
            if (carry != 0) {
                z -= fn_80238378(lbl_8036C088, q0);
            }
        }
    }

    if (z == zero) {
        j = 0;
        for (i = jz - 1; i >= jk; i--) {
            j |= iq[i];
        }
        if (j == 0) {
            for (k = 1; iq[jk - k] == 0; k++) {
            }
            for (i = jz + 1; i <= jz + k; i++) {
                const f64 *px = x;
                const f64 *pf;
                s32 value = ipio2[jv + i];
                f[jx + i] = (f64)value;
                fw = zero;
                pf = f + jx + i;
                for (j = 0; j <= jx; j++) {
                    fw += (*px++) * (*pf--);
                }
                q[i] = fw;
            }
            jz += k;
            goto recompute;
        }
    }

    if (z == zero) {
        jz--;
        q0 -= 24;
        while (iq[jz] == 0) {
            jz--;
            q0 -= 24;
        }
    } else {
        z = fn_80238378(z, -q0);
        if (z >= two24) {
            s32 integral = (s32)(twon24 * z);
            fw = (f64)integral;
            iq[jz] = (s32)(z - two24 * fw);
            jz++;
            q0 += 24;
            iq[jz] = (s32)fw;
        } else {
            iq[jz] = (s32)z;
        }
    }

    fw = fn_80238378(lbl_8036C088, q0);
    for (i = jz; i >= 0; i--) {
        q[i] = fw * (f64)iq[i];
        fw *= twon24;
    }
    for (i = jz; i >= 0; i--) {
        const f64 *pi = lbl_80282E98;
        fw = zero;
        for (k = 0; k <= jp && k <= jz - i; k++) {
            fw += (*pi++) * q[i + k];
        }
        fq[jz - i] = fw;
    }

    switch (prec) {
    case 0:
        fw = zero;
        {
            const f64 *p = &fq[jz];
            for (i = jz; i >= 0; i--) {
                fw += *p--;
            }
        }
        y[0] = ih == 0 ? fw : -fw;
        break;
    case 1:
    case 2:
        fw = zero;
        {
            const f64 *p = &fq[jz];
            for (i = jz; i >= 0; i--) {
                fw += *p--;
            }
        }
        y[0] = ih == 0 ? fw : -fw;
        fw = fq[0] - fw;
        {
            const f64 *p = &fq[1];
            for (i = 1; i <= jz; i++) {
                fw += *p++;
            }
        }
        y[1] = ih == 0 ? fw : -fw;
        break;
    case 3:
        {
            f64 *p = &fq[jz];
            for (i = jz; i > 0; i--, p--) {
                fw = p[-1] + p[0];
                p[0] += p[-1] - fw;
                p[-1] = fw;
            }
        }
        {
            f64 *p = &fq[jz];
            for (i = jz; i > 1; i--, p--) {
                fw = p[-1] + p[0];
                p[0] += p[-1] - fw;
                p[-1] = fw;
            }
        }
        fw = zero;
        {
            const f64 *p = &fq[jz];
            for (i = jz; i >= 2; i--) {
                fw += *p--;
            }
        }
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
int fn_802368F4(f64 *y, f64 x) {
    int fn_80236D88();
    extern f64 lbl_8036BFB8;
    extern f64 lbl_8036BFC0;
    extern f64 lbl_8036BFC8;
    extern f64 lbl_8036BFD0;
    extern f64 lbl_8036BFD8;
    extern f64 lbl_8036BFE0;
    extern f64 lbl_8036BFE8;
    extern f64 lbl_8036BFF0;
    extern f64 lbl_8036BFF8;
    extern f64 lbl_8036C000;
    extern f64 lbl_8036C008;
    extern s32 lbl_80282E08[];
    extern s32 lbl_80282D00[];
    f64 w, t, r, fn, z;
    f64 pio2_1, pio2_1t, pio2_2, pio2_2t;
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
                pio2_1t = lbl_8036BFC8;
                y[0] = z - pio2_1t;
                y[1] = (z - y[0]) - pio2_1t;
            } else {
                pio2_2 = lbl_8036BFD0;
                pio2_2t = lbl_8036BFD8;
                z -= pio2_2;
                y[0] = z - pio2_2t;
                y[1] = (z - y[0]) - pio2_2t;
            }
            return 1;
        } else {
            z = lbl_8036BFC0 + x;
            if ((unsigned)(ix - 0x3ff90000) != 0x21fbU) {
                pio2_1t = lbl_8036BFC8;
                y[0] = pio2_1t + z;
                y[1] = pio2_1t + (z - y[0]);
            } else {
                pio2_2 = lbl_8036BFD0;
                pio2_2t = lbl_8036BFD8;
                z += pio2_2;
                y[0] = pio2_2t + z;
                y[1] = pio2_2t + (z - y[0]);
            }
            return -1;
        }
    }
    if (ix <= 0x413921fb) {
        t = __fabs(x);
        n = (int)(lbl_8036BFE8 * t + lbl_8036BFE0);
        {
            int hi = 0x43300000;
            int lo = n ^ 0x80000000;
            *(int *)&fn = hi;
            *((int *)&fn + 1) = lo;
            fn = fn - lbl_8036C008;
        }
        pio2_1 = lbl_8036BFC0;
        pio2_1t = lbl_8036BFC8;
        r = t - pio2_1 * fn;
        w = pio2_1t * fn;
        if (n < 32 && ix != lbl_80282E08[n - 1]) {
            y[0] = r - w;
        } else {
            j = ix >> 20;
            y[0] = r - w;
            i = j - (((*(int *)&y[0]) >> 20) & 0x7ff);
            if (i > 16) {
                t = r;
                w = fn * lbl_8036BFD0;
                r = t - w;
                w = fn * lbl_8036BFD8 - ((t - r) - w);
                y[0] = r - w;
                i = j - (((*(int *)&y[0]) >> 20) & 0x7ff);
                if (i > 49) {
                    t = r;
                    w = fn * lbl_8036BFF0;
                    r = t - w;
                    w = fn * lbl_8036BFF8 - ((t - r) - w);
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
        y[0] = x - x;
        y[1] = x - x;
        return 0;
    }
    e0 = (ix >> 20) - 1046;
    *(int *)&z = ix - (e0 << 20);
    *(1 + (unsigned *)&z) = *(1 + (unsigned *)&x);
    for (i = 0; i < 2; i++) {
        tx[i] = (double)((int)(z));
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
