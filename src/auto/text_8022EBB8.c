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

void fn_8022EBB8(RuntimeDecimal *out,RuntimeDecimal *left,RuntimeDecimal *right){
s32 offset,n,len,index,round;u8 *base,*p,*rbase,*tail,*q,*borrow,*end;u8 removed;
{u32 *dst=(u32*)out,*src=(u32*)left;u32 a,b;u16 h;
a=src[0];b=src[1];dst[0]=a;
a=src[2];dst[1]=b;
b=src[3];dst[2]=a;
a=src[4];dst[3]=b;
b=src[5];dst[4]=a;
a=src[6];dst[5]=b;
b=src[7];dst[6]=a;
a=src[8];dst[7]=b;
b=src[9];dst[8]=a;
h=*(u16*)(src+10);
dst[9]=b;
*(u16*)(dst+10)=h;}
if(!right->digits[0])return;
n=out->length;if(n<right->length)n=right->length;
offset=out->exponent-right->exponent;n+=offset;if(n>36)n=36;
while(out->length<n){out->digits[out->length++]=0;}
base=out->digits;p=base+n;len=right->length+offset;if(len<n)p=base+len;
rbase=right->digits;q=rbase+(p-base-offset);tail=q;
while(p>base&&q>rbase){
--p;--q;
if(*p<*q){
borrow=p-1;while(*borrow==0)--borrow;
for(;borrow!=p;borrow++){--*borrow;borrow[1]+=10;}
}
*p-=*q;
}
index=tail-rbase;
if(index<right->length){
round=0;
if(*tail<5)round=1;
else if(*tail==5){
q=tail+1;end=right->digits+right->length;
for(;q<end;q++){if(*q)goto trim;}
p=base+index+offset-1;
if(*p&1)round=1;
}
if(round){
if(*p<1){borrow=p-1;while(*borrow==0)--borrow;for(;borrow!=p;borrow++){--*borrow;borrow[1]+=10;}}
--*p;
}
}
trim:
p=base;while(*p==0)++p;
if(p>base){removed=p-base;out->exponent-=removed;end=base+out->length;
for(;p<end;p++,base++)*base=*p;
out->length-=removed;
}
base=out->digits;p=base+out->length;
while(p>base){if(*--p)break;}
out->length=p-base+1;
}

extern s32 D_8022EF64;
s32 fn_8022F0B4(RuntimeDecimal *a, RuntimeDecimal *b) {
    s32 blen,alen,i,n;
    if(a->digits[0]==0) return b->digits[0]==0;
    if(b->digits[0]==0) return a->digits[0]==0;
    if(a->exponent==b->exponent) {
        alen=a->length;
        blen=b->length;
        n=alen;
        if(alen>blen) n=blen;
        for(i=0;i<n;i++) {
            if(a->digits[i]!=b->digits[i]) return 0;
        }
        if(n==alen) {
            for(;i<blen;i++) if(b->digits[i]!=0) return 0;
        } else {
            for(;i<alen;i++) if(a->digits[i]!=0) return 0;
        }
        return 1;
    }
    return 0;
}

void fn_8022F1C0(RuntimeDecimal *d,s32 code) { extern char lbl_80282B78[]; void fn_80230944(void *,void *,void *); RuntimeDecimal half, temp; s32 i; char *s; u8 *p; switch(code){
case -64: d->exponent=-20; i=d->sign=0; s=lbl_80282B78+37; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round0; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round0: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -53: d->exponent=-16; i=d->sign=0; s=lbl_80282B78+83; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round1; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round1: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -32: d->exponent=-10; i=d->sign=0; s=lbl_80282B78+122; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round2; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round2: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -16: d->exponent=-5; i=d->sign=0; s=lbl_80282B78+146; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round3; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round3: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -8: d->exponent=-3; i=d->sign=0; s=lbl_80282B78+159; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round4; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round4: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -7: d->exponent=-3; i=d->sign=0; s=lbl_80282B78+166; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round5; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round5: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -6: d->exponent=-2; i=d->sign=0; s=lbl_80282B78+172; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round6; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round6: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -5: d->exponent=-2; i=d->sign=0; s=lbl_80282B78+178; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round7; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round7: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -4: d->exponent=-2; i=d->sign=0; s=lbl_80282B78+183; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round8; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round8: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -3: d->exponent=-1; i=d->sign=0; s=lbl_80282B78+187; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round9; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round9: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -2: d->exponent=-1; i=d->sign=0; s=lbl_80282B78+191; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round10; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round10: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -1: d->exponent=-1; i=d->sign=0; s=lbl_80282B78+194; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round11; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round11: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 0: d->exponent=0; i=d->sign=0; s=lbl_80282B78+196; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round12; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round12: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 1: d->exponent=0; i=d->sign=0; s=lbl_80282B78+198; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round13; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round13: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 2: d->exponent=0; i=d->sign=0; s=lbl_80282B78+200; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round14; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round14: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 3: d->exponent=0; i=d->sign=0; s=lbl_80282B78+202; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round15; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round15: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 4: d->exponent=1; i=d->sign=0; s=lbl_80282B78+204; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round16; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round16: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 5: d->exponent=1; i=d->sign=0; s=lbl_80282B78+207; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round17; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round17: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 6: d->exponent=1; i=d->sign=0; s=lbl_80282B78+210; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round18; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round18: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 7: d->exponent=2; i=d->sign=0; s=lbl_80282B78+213; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round19; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round19: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 8: d->exponent=2; i=d->sign=0; s=lbl_80282B78+217; for(;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round20; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round20: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;default: fn_8022F1C0(&half,code/2); fn_80230944(d,&half,&half); if(code&1){temp=*d; if(code>0){half.exponent=0;half.sign=0;s=lbl_80282B78+198;for(i=0;i<36 && *s;i++) (&half)->digits[i]=*s++-'0';
(&half)->length=i;
if(!*s) goto multiply;
if(*s<5) goto multiply;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round21; ++t; } if(!((&half)->digits[i-1]&1)) goto multiply; }
round21: {u8 *base=(&half)->digits; p=base+((&half)->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++(&half)->exponent;break;} *p=0; }}
}else{half.sign=0;half.exponent=-1;s=lbl_80282B78+194;for(i=0;i<36 && *s;i++) (&half)->digits[i]=*s++-'0';
(&half)->length=i;
if(!*s) goto multiply;
if(*s<5) goto multiply;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round22; ++t; } if(!((&half)->digits[i-1]&1)) goto multiply; }
round22: {u8 *base=(&half)->digits; p=base+((&half)->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++(&half)->exponent;break;} *p=0; }}
} multiply: fn_80230944(d,&temp,&half);}break;} done:; }

#pragma global_optimizer off
