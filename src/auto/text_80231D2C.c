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

#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
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
    s32 whole;
    s32 frac;
    s32 exp;
    s32 n;
    s32 signch;
    s32 prec;
    u8 conv;

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

    conv=fmt->conv;
    out = buffer - 1;
    dec.exponent = dec.length + dec.exponent - 1;
    buffer[-1] = 0;

    switch (conv) {
    case 0x67:
    case 0x47:
        if ((s32)dec.length > fmt->precision) {
            fn_80233174(&dec, fmt->precision);
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
        goto done;
    }

do_exp:
    if ((s32)dec.length > fmt->precision + 1) {
        fn_80233174(&dec, fmt->precision + 1);
    }
    exp = (s32)dec.exponent;
    signch = 0x2B;
    if (exp < 0) {
        exp = -exp;
        signch = 0x2D;
    }
    n = 0;
    while (exp != 0 || n < 2) {
        n += 1;
        i = exp % 10;
        exp /= 10;
        *--out = (char)(i + 0x30);
    }
    out[-1] = signch;
    out[-2] = fmt->conv;
    out -= 2;
    if (fmt->precision + (s32)(buffer - out) > 0x1FD) {
        return NULL;
    }
    if ((s32)dec.length < fmt->precision + 1) {
        n = (fmt->precision + 2) - dec.length;
        while (--n != 0) {
            *--out = 0x30;
        }
    }
    i = dec.length;
    p = digs + i;
    while (--i != 0) {
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
    goto done;

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
done:
    return out;
}
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

#pragma push
#pragma optimization_level 3
#pragma opt_propagation off
char *double2hex(char *buffer, void *format, f64 value)
{
  void fn_8022E660(void *, void *);
  void strcpy(char *, const char *);
  char *long2str_802338EC(s32, char *, void *);
  volatile int pad3;
  typedef struct
  {
    u8 unk0;
    u8 sign_style;
    u8 unk2;
    u8 alternate;
    u8 unk4;
    u8 conv;
    u8 pad6[6];
    s32 precision;
  } PrintFormat;
  typedef struct
  {
    s8 kind;
    s8 pad;
    s16 width;
    s32 pad2;
  } DecCtrl;
  u8 sp40[0x38];
  char sp30[16];
  char sp20[16];
  f64 sp18;
  DecCtrl sp10;
  PrintFormat *fmt = (PrintFormat *) format;
  char *out;
  char *p;
  s32 exp;
  u8 b;
  u8 *cp;
  s32 i;
  s16 raw_exp;
  s8 nibble;
  s32 ch;
  sp18 = value;
  if (fmt->precision > 0x1FD)
  {
    return NULL;
  }
  sp10.kind = 0;
  sp10.width = 0x20;
  fn_8022E660(&sp10, sp40);
  if (sp40[5] == 'I')
  {
    if ((*((s16 *) (&sp18))) & 0x8000)
    {
      out = buffer - 5;
      if (fmt->conv == 'A')
      {
        strcpy(out, double2hex_strpool + 1);
      }
      else
      {
        strcpy(out, double2hex_strpool + 6);
      }
    }
    else
    {
      out = buffer - 4;
      if (fmt->conv == 'A')
      {
        strcpy(out, double2hex_strpool + 0xB);
      }
      else
      {
        strcpy(out, double2hex_strpool + 0xF);
      }
    }
    return out;
  }
  if (sp40[5] == 'N')
  {
    if ((*((u8 *) (&value))) & 0x80)
    {
      out = buffer - 5;
      if (fmt->conv == 'A')
      {
        strcpy(out, double2hex_strpool + 0x13);
      }
      else
      {
        strcpy(out, double2hex_strpool + 0x18);
      }
    }
    else
    {
      out = buffer - 4;
      if (fmt->conv == 'A')
      {
        strcpy(out, double2hex_strpool + 0x1D);
      }
      else
      {
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
  *((s32 *) (sp30 + 8)) = 0;
  raw_exp = (*((s16 *) (&sp18)) & 0x7FF0) >> 4;
  *((s32 *) (sp30 + 12)) = 1;
  *((s32 *) (sp20 + 0)) = *((s32 *) (sp30 + 0));
  *((s32 *) (sp20 + 4)) = *((s32 *) (sp30 + 4));
  *((s32 *) (sp20 + 8)) = 0;
  *((s32 *) (sp20 + 12)) = 1;
  exp = raw_exp - 0x3FF;
  p = long2str_802338EC(exp, buffer, sp20);
  if (fmt->conv == 'a')
  {
    p[-1] = 'p';
    out = p - 1;
  }
  else
  {
    p[-1] = 'P';
    out = p - 1;
  }
  cp = (u8 *) &value;
  for (i = fmt->precision; i >= 1; i--)
  {
    b = cp[i / 2 + 1];
    nibble = (i % 2 != 0) ? (s8) (b & 0xF) : (s8) ((b >> 4) & 0xF);
    if (nibble < 0xA)
    {
      ch = nibble + '0';
    }
    else
      if (fmt->conv == 'a')
    {
      ch = nibble + 0x57;
    }
    else
    {
      ch = nibble + 0x37;
    }
    *(--out) = ch;
  }

  if ((fmt->precision != 0) || (fmt->alternate != 0))
  {
    *(--out) = '.';
  }
  out[-1] = '1';
  if (fmt->conv == 'a')
  {
    out[-2] = 'x';
    out -= 2;
  }
  else
  {
    out[-2] = 'X';
    out -= 2;
  }
  *(--out) = '0';
  if ((*((s16 *) (&sp18))) & 0x8000)
  {
    *(--out) = '-';
  }
  else
    if (fmt->sign_style == 1)
  {
    *(--out) = '+';
  }
  else
    if (fmt->sign_style == 2)
  {
    *(--out) = ' ';
  }
  return out;
}
#pragma pop
#pragma optimization_level 3
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
  int new_var;
  extern u8 lbl_8036BE0C;
  extern f64 lbl_8036BE10;
  void *new_var2;
  extern f64 lbl_8036BE18;
  f64 fn_8022D5E0(void *);
  typedef union 
  {
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
    const u32 *srcWords = (const u32 *) lbl_80282C88;
    u32 *dstWords = (u32 *) buf;
    u32 w0 = srcWords[0];
    u32 w8 = srcWords[8];
    u32 w1;
    u32 w2 = srcWords[2];
    u32 w3 = srcWords[3];
    u32 w4 = srcWords[4];
    u32 w5 = srcWords[5];
    u32 w6 = srcWords[6];
    u32 w7 = srcWords[7];
    u32 w9 = srcWords[9];
    u16 last = *((const u16 *) (lbl_80282C88 + 0x28));
    dstWords[0] = w0;
    dstWords[1] = srcWords[1];
    dstWords[3] = w3;
    dstWords[4] = w4;
    dstWords[2] = w2;
    dstWords[5] = w5;
    dstWords[6] = w6;
    dstWords[7] = w7;
    dstWords[8] = w8;
    dstWords[9] = w9;
    *((u16 *) (buf + 0x28)) = last;
  }
  decimal = *lbl_8029EBA8[0];
  *arg4 = 0;
  ch = arg1(arg2, 0, 0);
  goto parse_check;
  parse_next:
  switch (state)
  {
    case 1:
      if (lbl_8029E8A8[(u8) ch] & 6)
    {
      ch = arg1(arg2, 0, 0);
      skipped++;
    }
    else
    {
      cls = (ch == (-1)) ? (-1) : ((s32) lbl_8029EAA8[(u8) ch]);
      switch (cls)
      {
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
      do
    {
      break;
    }
    while (0);

    case 0x4000:
      p = &infbuf[1];
      n = 1;
      *((s32 *) infbuf) = *((s32 *) lbl_80282CB4);
      *((s32 *) (infbuf + 4)) = *((s32 *) (lbl_80282CB4 + 4));
      infbuf[8] = lbl_80282CB4[8];
      goto inf_check;
      inf_advance:
    p++;

      n++;
      pos++;
      ch = arg1(arg2, 0, 0);
      inf_check:
    if (n < 8)
    {
      cls = (ch == (-1)) ? (-1) : ((s32) lbl_8029EAA8[(u8) ch]);
      if (((s8) (*p)) == cls)
      {
        goto inf_advance;
      }
    }

      if ((n == 3) || (n == 8))
    {
      f = (neg) ? (-lbl_8036706C[0]) : (lbl_8036706C[0]);
      value.d = f;
      *arg3 = (skipped + n) + sp5C;
      return value.d;
    }
      state = 0x1000;
      break;

    case 0x2000:
      p = &nanbuf[1];
      n = 1;
      *((s32 *) nanbuf) = lbl_8036BE08;
      nanbuf[4] = lbl_8036BE0C;
      i = 0;
      goto nan_check;
      nan_advance:
    p++;

      new_var = 0xC0;
      n++;
      pos++;
      ch = arg1(arg2, 0, 0);
      nan_check:
    if (n < 4)
    {
      cls = (ch == (-1)) ? (-1) : ((s32) lbl_8029EAA8[(u8) ch]);
      if (((s8) (*p)) == cls)
      {
        goto nan_advance;
      }
    }

      if ((n == 3) || (n == 4))
    {
      if (n == 4)
      {
        while ((i < 0x20) && ((lbl_8029E8A8[(u8) ch] & 0x10) || (lbl_8029E8A8[(u8) ch] & new_var)))
        {
          i++;
          pos++;
          ch = arg1(arg2, 0, 0);
        }

        if (ch != 0x29)
        {
          state = 0x1000;
          break;
        }
        i++;
      }
      f = (neg) ? (-lbl_80367068[0]) : (lbl_80367068[0]);
      value.d = f;
      *arg3 = ((skipped + n) + i) + sp5C;
      return value.d;
    }
      state = 0x1000;
      break;
      new_var2 = arg2;

    case 2:
      if (ch == ((s32) decimal))
    {
      state = 0x10;
      pos++;
      ch = arg1(new_var2, 0, 0);
    }
    else
      if (!(lbl_8029E8A8[(u8) ch] & 0x10))
    {
      state = 0x1000;
    }
    else
      if (ch == 0x30)
    {
      pos++;
      ch = arg1(new_var2, 0, 0);
      cls = (ch == (-1)) ? (-1) : ((s32) lbl_8029EAA8[(u8) ch]);
      if (cls == 0x58)
      {
        hexphase = 1;
        state = 0x8000;
      }
      else
      {
        state = 4;
      }
    }
    else
    {
      state = 8;
    }
      break;

    case 4:
      if (ch == 0x30)
    {
      pos++;
      ch = arg1(new_var2, 0, 0);
    }
    else
    {
      state = 8;
    }
      break;

    case 8:
      if (!(lbl_8029E8A8[(u8) ((unsigned long) ch)] & 0x10))
    {
      if (ch == ((s32) decimal))
      {
        state = 0x20;
        pos++;
        ch = arg1(new_var2, 0, 0);
      }
      else
      {
        state = 0x40;
      }
    }
    else
    {
      if (buf[4] < 0x14)
      {
        u8 length = buf[4];
        buf[4] = length + 1;
        buf[5 + length] = (u8) ch;
      }
      else
      {
        trail++;
      }
      pos++;
      ch = arg1(new_var2, 0, 0);
    }
      break;

    case 0x10:
      if (!(lbl_8029E8A8[(u8) ch] & 0x10))
    {
      state = 0x1000;
    }
    else
    {
      state = 0x20;
    }
      break;

    case 0x20:
      if (!(lbl_8029E8A8[(u8) ch] & 0x10))
    {
      state = 0x40;
    }
    else
    {
      if (buf[4] < 0x14)
      {
        if ((ch != 0x30) || (buf[4] != 0))
        {
          u8 length = buf[4];
          buf[4] = length + 1;
          buf[5 + length] = (u8) ch;
        }
        trail--;
      }
      pos++;
      ch = arg1(new_var2, 0, 0);
    }
      break;

    case 0x40:
      cls = (ch == (-1)) ? (-1) : ((s32) lbl_8029EAA8[(u8) ch]);
      if (cls == 0x45)
    {
      state = 0x80;
      pos++;
      ch = arg1(new_var2, 0, 0);
    }
    else
    {
      state = 0x800;
    }
      break;

    case 0x80:
      if (ch == 0x2B)
    {
      pos++;
      ch = arg1(new_var2, 0, 0);
    }
    else
      if (ch == 0x2D)
    {
      pos++;
      ch = arg1(new_var2, 0, 0);
      sp60 = 1;
    }
      state = 0x100;
      break;

    case 0x100:
      if (!(lbl_8029E8A8[(u8) ch] & 0x10))
    {
      state = 0x1000;
    }
    else
      if (ch == 0x30)
    {
      state = 0x200;
      pos++;
      ch = arg1(new_var2, 0, 0);
    }
    else
    {
      state = 0x400;
    }
      break;

    case 0x200:
      if (ch == 0x30)
    {
      pos++;
      ch = arg1(new_var2, 0, 0);
    }
    else
    {
      state = 0x400;
    }
      break;

    case 0x400:
      if (!(lbl_8029E8A8[(u8) ch] & 0x10))
    {
      state = 0x800;
    }
    else
    {
      expv = (ch + (expv * 10)) - 0x30;
      if (expv > 0x7FFF)
      {
        *arg4 = 1;
      }
      pos++;
      ch = arg1(new_var2, 0, 0);
    }
      break;

    case 0x8000:
      switch (hexphase)
    {
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
        ch = arg1(new_var2, 0, 0);
        break;

      case 2:
        if (ch == 0x30)
      {
        pos++;
        ch = arg1(new_var2, 0, 0);
      }
      else
      {
        hexphase = 4;
      }
        break;

      case 4:
        if (!(lbl_8029E8A8[(u8) ch] & 0x20))
      {
        if (ch == ((s32) decimal))
        {
          hexphase = 8;
          pos++;
          ch = arg1(new_var2, 0, 0);
        }
        else
        {
          hexphase = 0x10;
        }
      }
      else
      {
        if (hexCount < 0x11)
        {
          s32 digit;
          s32 index = hexCount / 2;
          u8 old = value.b[index];
          cls = (ch == (-1)) ? (-1) : ((s32) lbl_8029EAA8[(u8) ch]);
          digit = (cls >= 0x41) ? (cls - 0x37) : (cls - 0x30);
          if (hexCount % 2)
          {
            value.b[index] = (u8) (old | digit);
          }
          else
          {
            value.b[index] = (u8) (old | (((u8) digit) << 4));
          }
          hexCount++;
          wholeHexDigits++;
        }
        pos++;
        ch = arg1(new_var2, 0, 0);
      }
        break;

      case 8:
        if (!(lbl_8029E8A8[(u8) ch] & 0x20))
      {
        hexphase = 0x10;
      }
      else
      {
        if (hexCount < 0x11)
        {
          s32 digit;
          s32 index = hexCount / 2;
          u8 old = value.b[index];
          cls = (ch == (-1)) ? (-1) : ((s32) lbl_8029EAA8[(u8) ch]);
          digit = (cls >= 0x41) ? (cls - 0x37) : (cls - 0x30);
          if (hexCount % 2)
          {
            value.b[index] = (u8) (old | digit);
          }
          else
          {
            value.b[index] = (u8) (old | (digit << 4));
          }
          hexCount++;
        }
        pos++;
        ch = arg1(new_var2, 0, 0);
      }
        break;

      case 0x10:
        cls = (ch == (-1)) ? (-1) : ((s32) lbl_8029EAA8[(u8) ch]);
        if (cls == 0x50)
      {
        hexphase = 0x20;
        hexSuffix++;
        pos++;
        ch = arg1(new_var2, 0, 0);
      }
      else
      {
        state = 0x800;
      }
        break;

      case 0x20:
        hexSuffix++;
        if (ch == 0x2D)
      {
        sp58 = 1;
      }
      else
        if (ch != 0x2B)
      {
        arg1(new_var2, ch, 1);
        hexSuffix--;
      }
        hexphase = 0x40;
        pos++;
        ch = arg1(new_var2, 0, 0);
        break;

      case 0x40:
        if (!(lbl_8029E8A8[(u8) ch] & 0x10))
      {
        state = 0x1000;
      }
      else
        if (ch == 0x30)
      {
        hexphase = 0x80;
        hexSuffix++;
        pos++;
        ch = arg1(new_var2, 0, 0);
      }
      else
      {
        hexphase = 0x100;
      }
        break;

      case 0x80:
        if (!(lbl_8029E8A8[(u8) ch] & 0x10))
      {
        state = 0x800;
      }
      else
        if (ch == 0x30)
      {
        hexSuffix++;
        pos++;
        ch = arg1(new_var2, 0, 0);
      }
      else
      {
        hexphase = 0x100;
      }
        break;

      case 0x100:
        if (!(lbl_8029E8A8[(u8) ch] & 0x10))
      {
        state = 0x800;
      }
      else
      {
        hexexp = (s16) (((hexexp * 10) + ch) - 0x30);
        if (expv > 0x7FFF)
        {
          *arg4 = 1;
        }
        hexSuffix++;
        pos++;
        ch = arg1(new_var2, 0, 0);
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
  if (((pos <= arg0) && (ch != (-1))) && (!(state & 0x1800)))
  {
    goto parse_next;
  }

  mask = state & 0xE2C;
  if (mask == 0)
  {
    *arg3 = 0;
  }
  else
  {
    *arg3 = (pos + skipped) - 1;
  }
  arg1(new_var2, ch, 1);
  if (hexphase == 0)
  {
    if (sp60)
    {
      expv = -expv;
    }
    {
      s32 nd = buf[4];
      u8 *q = (buf + 5) + nd;
      for (;;)
      {
        if ((nd--) == 0)
        {
          break;
        }
        if ((*(--q)) != 0x30)
        {
          break;
        }
        trail++;
        state = 0x40;
      }

      buf[4] = (u8) (nd + 1);
    }
    if (buf[4] == 0)
    {
      s32 nd = buf[4];
      buf[4] = (u8) (nd + 1);
      buf[5 + nd] = 0x30;
    }
    expv += trail;
    if ((expv < (-0x8000)) || (expv > 0x7FFF))
    {
      *arg4 = 1;
    }
    if ((*arg4) != 0)
    {
      if (sp60)
      {
        return lbl_8036BE10;
      }
      if (neg)
      {
        return -lbl_80367080[0];
      }
      return lbl_80367080[0];
    }
    *((s16 *) (buf + 2)) = (s16) expv;
    value.d = fn_8022D5E0(buf);
    if ((lbl_8036BE10 != value.d) && (value.d < lbl_80367088[0]))
    {
      *arg4 = 1;
    }
    else
      if (value.d > lbl_80367090[0])
    {
      *arg4 = 1;
      value.d = lbl_80367080[0];
    }
    if (neg && (mask != 0))
    {
      value.d = -value.d;
    }
    return value.d;
  }
  if (value.d != lbl_8036BE18)
  {
    if (sp58)
    {
      hexexp = (s16) (-hexexp);
    }
    hexexp++;
    value.bits >>= 1;
    {
      s16 head = value.sh[0];
      if ((head & 0xF0) == 0x10)
      {
        head &= 0xF;
        hexexp = (s16) (hexexp + ((wholeHexDigits - 1) * 4));
        value.h[0] = (u16) (head | (((u32) (hexexp + 0x3FF)) << 4));
        *arg3 = (((skipped + sp5C) + hexCount) + 1) + hexSuffix;
        if ((lbl_8036BE10 != value.d) && (value.d < lbl_80367088[0]))
        {
          *arg4 = 1;
          value.d = lbl_8036BE10;
        }
        else
          if (value.d > lbl_80367090[0])
        {
          *arg4 = 1;
          value.d = lbl_80367080[0];
        }
      }
    }
    if (neg)
    {
      value.sh[0] |= (s16) 0x8000;
    }
  }
  else
  {
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

f64 fn_80235B4C(f64 x)
{
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
  f64 y;
  f64 z;
  f64 h;
  f64 df;
  f64 p;
  f64 q;
  f64 r;
  f64 s;
  f64 w;
  f64 c;
  f64 sp8;
  s32 hx;
  s32 ix;
  sp8 = x;
  hx = *((s32 *) (&sp8));
  ix = hx & 0x7FFFFFFF;
  if (ix >= 0x3FF00000)
  {
    if (((ix - 0x3FF00000) | (*((s32 *) (((s8 *) (&sp8)) + 4)))) == 0)
    {
      if (hx > 0)
      {
        return lbl_8036BE20;
      }
      return lbl_8036BE28;
    }
    return lbl_80367068[0];
  }
  if (ix < 0x3FE00000)
  {
    if (ix <= 0x3C600000)
    {
      return lbl_8036BE30;
    }
    y = x * x;
    p = (((((((((lbl_8036BE68 * y) + lbl_8036BE60) * y) + lbl_8036BE58) * y) + lbl_8036BE50) * y) + lbl_8036BE48) * y) + lbl_8036BE40;
    q = (((((((lbl_8036BE90 * y) + lbl_8036BE88) * y) + lbl_8036BE80) * y) + lbl_8036BE78) * y) + lbl_8036BE70;
    r = (y * p) / q;
    s = lbl_8036BE38 - (x * r);
    return lbl_8036BE30 - (x - s);
  }
  if (hx < 0)
  {
    z = lbl_8036BE98 * (lbl_8036BE70 + x);
    h = fn_80238A9C(z);
    p = (((((((((lbl_8036BE68 * z) + lbl_8036BE60) * z) + lbl_8036BE58) * z) + lbl_8036BE50) * z) + lbl_8036BE48) * z) + lbl_8036BE40;
    q = (((((((lbl_8036BE90 * z) + lbl_8036BE88) * z) + lbl_8036BE80) * z) + lbl_8036BE78) * z) + lbl_8036BE70;
    r = (z * p) / q;
    w = (r * h) - lbl_8036BE38;
    return lbl_8036BE28 - (lbl_8036BEA0 * (h + w));
  }
  z = lbl_8036BE98 * (lbl_8036BE70 - x);
  h = fn_80238A9C(z);
  df = h;
  *((s32 *) (((s8 *) (&df)) + 4)) = 0;
  c = (z - (df * df)) / (h + df);
  p = z * (((((((((lbl_8036BE68 * z) + lbl_8036BE60) * z) + lbl_8036BE58) * z) + lbl_8036BE50) * z) + lbl_8036BE48) * z + lbl_8036BE40);
  q = (((((((lbl_8036BE90 * z) + lbl_8036BE88) * z) + lbl_8036BE80) * z) + lbl_8036BE78) * z) + lbl_8036BE70;
  r = p / q;
  w = (r * h) + c;
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

#pragma push
#pragma optimization_level 4
