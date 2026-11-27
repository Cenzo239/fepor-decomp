/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"
#include <dolphin/os.h>
#include "global.h"

/* Minimal DVDCommandBlock layout used by the DVD state machine. */
typedef struct DVDReadyCommand {
    u8 pad[8];
    s32 command; /* +0x08 */
    s32 state;   /* +0x0C */
    u8 pad10[0x18];
    void (*callback)(s32, void *); /* +0x28 */
} DVDReadyCommand;
extern u16 Scb_80339420[];
extern volatile u32 __DIRegs[16];

static inline void dvdClearDiStatus(void) {
    u32 *base = (u32 *)0xCC000000;
    u32 tmp = base[0x1801];
    u32 *di = base + 0x1800;
    di[1] = tmp;
}

typedef struct {
    u8 unk0;
    u8 pad1;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u16 unk20;
} VITiming;
extern s32 PauseFlag_803685A4;
extern s32 PausingFlag_803685A8;
extern s32 FatalErrorFlag_803685B0;
extern void* executing_80368598;
extern u8 DummyCommandBlock_80339F80[48];
extern u32 lbl_803685B8;
extern void (*lbl_803685BC)(void*, void*);
extern void stateReady(void);
s32 fn_8020F0B8(DVDReadyCommand *block, void (*callback)(s32, void *));
extern void __DVDClearWaitingQueue(void);
extern u8 bb2Buf_80339FF8[];
extern s32 __DVDPopWaitingQueue(void);;
extern s32 gSaveDataBase;;
extern s32 fn_80013E50(s32);
extern s32 fn_80013E60(s32, s32);
extern s32 fn_80013E74(void*, s32);
extern s32 lbl_80366F60;
  extern char lbl_8029CFE8[];


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
extern u16* lbl_80368648;
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
void fn_8020DAE0(u32 arg0);
extern void fn_8020C1A4(u8, u32, void *);

extern u8 lbl_80289EB8[16];

typedef struct OSResetFunctionInfo OSResetFunctionInfo;
struct OSResetFunctionInfo {
    BOOL (*func)(BOOL final);
    u32 priority;
    OSResetFunctionInfo *next;
    OSResetFunctionInfo *prev;
};

typedef struct OSResetFunctionQueue {
    OSResetFunctionInfo *head;
    OSResetFunctionInfo *tail;
} OSResetFunctionQueue;

extern OSResetFunctionQueue ResetFunctionQueue_803684E8;

typedef struct OSContext {
    u8 data[0x2C8];
} OSContext;

void OSRegisterResetFunction(OSResetFunctionInfo *info);
BOOL __OSCallResetFunctions(BOOL final);
void __OSReboot(u32 resetCode, u32 bootDol);
void OSClearContext(OSContext *context);
void OSSetCurrentContext(OSContext *context);
void fn_80206E1C(u32 bootDol, u32 resetCode, char **argv);
s32 __OSSyncSram(void);

extern void DecrementerExceptionCallback(void);

extern u32 __SPR_392;

extern u16 InterruptHandlerTable_803684C8[];

extern s32 StopAtNextInt_80368530;
extern u16 lbl_80368550;

extern u32 lbl_80368514;
extern u32 lbl_80368510;
extern s32 lbl_803684FC;
extern s32 lbl_80368500;
extern void (*lbl_803684F8)();

extern void* __OSSystemCallVectorStart;
extern void* __OSSystemCallVectorEnd;

typedef struct FSTEntry {
    u32 isDirAndStringOff;
    u32 parentOrPosition;
    u32 nextEntryOrLength;
} FSTEntry;

extern FSTEntry *FstStart_8036857C;
extern char *FstStringStart_80368580;
extern s32 currentDirectory;

#define entryIsDir(i) (((FstStart_8036857C[i].isDirAndStringOff & 0xFF000000) == 0) ? FALSE : TRUE)
#define stringOff(i) (FstStart_8036857C[i].isDirAndStringOff & ~0xFF000000)
#define parentDir(i) (FstStart_8036857C[i].parentOrPosition)

static inline BOOL DVDComparePathComponent(char *path, char *name) {
    s32 fn_80230CE0(s32);
    while (*name) {
        s32 first = fn_80230CE0(*name++);
        if (first != fn_80230CE0(*path++)) return FALSE;
    }
    if (*path == '/' || *path == 0) return TRUE;
    return FALSE;
}

static u32 myStrncpy(char *dest, char *src, u32 maxlen) {
    u32 i = maxlen;

    while ((i > 0) && (*src != 0)) {
        *dest++ = *src++;
        i--;
    }

    return maxlen - i;
}

extern u16 Scb_803394;

u32 __OSGetResetSWState(void);

extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);

/* Recursively write "/parent/.../name" for an FST entry into path; returns length used. */

/* Build an absolute path for the current DVD directory into path. */

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma dont_inline on

#pragma dont_inline reset

#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer off
#pragma opt_common_subs off

#pragma opt_common_subs reset
#pragma global_optimizer reset

#pragma global_optimizer on

#pragma optimization_level 3

#pragma optimization_level reset

#pragma optimization_level reset

#pragma opt_common_subs off
/* Pop the next DVD command and enter its busy/resume path (Dolphin DVD state machine). */

#pragma opt_common_subs reset
#pragma global_optimizer off
#pragma peephole off

#pragma peephole reset
#pragma global_optimizer on

#pragma global_optimizer off
#pragma peephole off

#pragma peephole reset
#pragma global_optimizer reset

#pragma peephole off
#pragma global_optimizer off

#pragma opt_common_subs off

#pragma opt_common_subs reset

#pragma global_optimizer on
#pragma peephole on

#pragma use_lmw_stmw on
static inline s32 fn_8020FD50_cntlzd(u64 bit) {
    u32 hi = (u32)(bit >> 32);
    u32 lo = (u32)(bit & 0xFFFFFFFF);
    s32 value = __cntlzw(hi);
    if (value < 32) {
        return value;
    }
    return 32 + __cntlzw(lo);
}

void fn_8020FD50(s32 unused, OSContext *arg1) {
    void fn_80211B30(s32, s32);
    u32 fn_802116D4(void);
    void fn_8023C518(void);
    void fn_8020AEC4(s32 *);
    extern u8 lbl_8033A068[];
    extern u32 lbl_80368604;
    extern u32 lbl_80368608;
    extern s32 lbl_8036860C;

    OSContext ctx;
    s16 sp16;
    s16 sp14;
    volatile u16 *r5;
    volatile u16 *rp;
    u16 val0;
    u16 val1;
    s32 regMask;
    s32 didFlush;
    s32 bit;
    u8 *regsBase;
    OSContext *ctxArg;
    u8 *timing;

    ctxArg = arg1;
    timing = lbl_8033A068;
    regMask = 0;
    r5 = (volatile u16 *)0xCC002000;
    val0 = *(r5 += 0x18);
    if (val0 & 0x8000) {
        *r5 = (u16)(val0 & ~0x8000);
        regMask |= 1;
    }
    rp = (volatile u16 *)0xCC000000;
    val1 = *(rp += 0x101A);
    if (val1 & 0x8000) {
        *rp = (u16)(val1 & ~0x8000);
        regMask |= 2;
    }
    rp = (volatile u16 *)0xCC000000;
    val1 = *(rp += 0x101C);
    if (val1 & 0x8000) {
        *rp = (u16)(val1 & ~0x8000);
        regMask |= 4;
    }
    rp = (volatile u16 *)0xCC000000;
    val1 = *(rp += 0x101E);
    if (val1 & 0x8000) {
        *rp = (u16)(val1 & ~0x8000);
        regMask |= 8;
    }
    if ((regMask & 4) || (regMask & 8)) {
        OSClearContext(&ctx);
        OSSetCurrentContext(&ctx);
        if (lbl_8036861C != NULL) {
            fn_80211B30((s32)&sp16, (s32)&sp14);
            ((void (*)(s16, s16))lbl_8036861C)(sp16, sp14);
        }
        OSClearContext(&ctx);
        OSSetCurrentContext(ctxArg);
        return;
    }
    lbl_80368604 += 1;
    OSClearContext(&ctx);
    OSSetCurrentContext(&ctx);
    if ((u32)lbl_80368614 != 0) {
        ((void (*)(u32))lbl_80368614)(lbl_80368604);
    }
    if (lbl_80368608 != 0) {
        if ((u32)lbl_80368638 != 1 || fn_802116D4() != 0) {
            regsBase = (u8 *)0xCC002000;
            while (*(u64 *)&lbl_80368640 != 0) {
                bit = fn_8020FD50_cntlzd(*(u64 *)&lbl_80368640);
                *(volatile u16 *)(regsBase + (bit << 1)) = *(u16 *)((u8 *)(timing + (bit << 1)) + 0x78);
                *(u64 *)&lbl_80368640 &= ~((u64)1 << (63 - bit));
            }
            lbl_80368638 = (void *)0;
            didFlush = 1;
            lbl_80368648 = (u16 *)*(u32 *)(timing + 0x144);
            lbl_8036864C = *(void **)(timing + 0x118);
            lbl_80368654 = lbl_80368650;
        } else {
            didFlush = 0;
        }
        if (didFlush != 0) {
            lbl_80368608 = 0;
            fn_8023C518();
        }
    }
    if (lbl_80368618 != NULL) {
        OSClearContext(&ctx);
        ((void (*)(u32))lbl_80368618)(lbl_80368604);
    }
    fn_8020AEC4(&lbl_8036860C);
    OSClearContext(&ctx);
    OSSetCurrentContext(ctxArg);
}
#pragma use_lmw_stmw reset

s32 fn_8020FFC4(s32 arg0) {
    extern s32 lbl_80368614;
    s32 temp_r31;

    temp_r31 = lbl_80368614;
    OSDisableInterrupts();
    lbl_80368614 = arg0;
    OSRestoreInterrupts();
    return temp_r31;
}

void* fn_80210008(void* arg0) {
    void* temp_r31;

    temp_r31 = lbl_80368618;
    OSDisableInterrupts();
    lbl_80368618 = arg0;
    OSRestoreInterrupts();
    return temp_r31;
}

VITiming *fn_8021004C(u32 arg0) {
extern u8 lbl_8029D2C8[];
extern VITiming *lbl_8036865C;
u8 *data = lbl_8029D2C8;
switch(arg0) {
case 0: return (VITiming *)(data+0x44);
case 1: return (VITiming *)(data+0x6A);
case 4: return (VITiming *)(data+0x90);
case 5: return (VITiming *)(data+0xB6);
case 20: return (VITiming *)(data+0x44);
case 21: return (VITiming *)(data+0x6A);
case 8: return (VITiming *)(data+0xDC);
case 9: return (VITiming *)(data+0x102);
case 2: return (VITiming *)(data+0x128);
case 3: return (VITiming *)(data+0x14E);
case 16: return (VITiming *)(data+0x90);
case 17: return (VITiming *)(data+0xB6);
case 24: return (VITiming *)(data+0x174);
case 25: return (VITiming *)(data+0x19A);
case 30: return lbl_8036865C;
default: return 0;
}
}

VITiming *fn_8021004C(u32 arg0);

void fn_802100F4(u32 arg0) {
    VITiming *fn_8021004C(u32);
    volatile u16 *regs;
    VITiming *tm;
    u32 tv;
    u32 mode;
    u32 val;
    volatile u32 grit;
    u32 pad0;
    u32 pad1;
    u32 pad2;
    u8 lo;
    u8 hi;
    u16 tmp;
    u16 tmp2;

    mode = arg0 >> 2;
    tv = arg0 & 3;
    *(u32 *)0x800000CC = mode;
    tm = fn_8021004C(arg0);
    regs = (volatile u16 *)0xCC002000;
    *++regs = 2;
    grit = 0;
    if (grit < 1000) {
        while (grit < 1000) {
            grit += 8;
        }
    }
    *regs = 0;
    tmp = tm->unk1A;
    *(volatile u16 *)0xCC002006 = tmp;
    hi = tm->unk1D;
    lo = tm->unk1E;
    *(volatile u16 *)0xCC002004 = lo | (hi << 8);
    hi = tm->unk1F;
    lo = tm->unk1C;
    *(volatile u16 *)0xCC00200A = lo | (hi << 7);
    tmp = tm->unk20;
    *(volatile u16 *)0xCC002008 = (tmp & 0x7FFF) << 1;
    tmp = tm->unk2;
    lo = tm->unk0;
    tmp = (tmp * 2) - 2;
    *(volatile u16 *)0xCC002000 = lo;
    *(volatile u16 *)0xCC00200E = tm->unk4 + tmp;
    *(volatile u16 *)0xCC00200C = tm->unk8 + 2;
    tmp = tm->unk2;
    tmp = (tmp * 2) - 2;
    *(volatile u16 *)0xCC002012 = tm->unk6 + tmp;
    *(volatile u16 *)0xCC002010 = tm->unkA + 2;
    *(volatile u16 *)0xCC002016 = tm->unkC | (tm->unk10 << 5);
    *(volatile u16 *)0xCC002014 = tm->unkE | (tm->unk14 << 5);
    *(volatile u16 *)0xCC00201A = tm->unkD | (tm->unk12 << 5);
    *(volatile u16 *)0xCC002018 = tm->unkF | (tm->unk16 << 5);
    *(volatile u16 *)0xCC002048 = 0x2828;
    *(volatile u16 *)0xCC002036 = 1;
    *(volatile u16 *)0xCC002034 = 0x1001;
    tmp = tm->unk18;
    tmp2 = tm->unk1A;
    *(volatile u16 *)0xCC002032 = tmp2 + 1;
    *(volatile u16 *)0xCC002030 = ((s16)tmp / 2 + 1) | 0x1000;
    if ((s32)mode < 4) {
        if ((s32)mode >= 1) {
            val = mode;
        } else {
            val = 0;
        }
    } else {
        val = 0;
    }
    if (tv <= 1) {
        *regs = (u16)((((tv & 1) << 2) | 1) | (val << 8));
        *(volatile u16 *)0xCC00206C = 0;
    } else {
        *regs = (u16)((val << 8) | 5);
        *(volatile u16 *)0xCC00206C = 1;
    }
}

#pragma optimization_level 3
extern volatile u16 __VIRegs[59] : 0xCC002000;
void VIInit(void){
extern u8 lbl_8029D2C8[],lbl_8033A068[];extern s32 lbl_80368600,lbl_80368604,lbl_80368608;extern const char *lbl_80366F90;
extern s16 lbl_80368626;extern u32 CurrTvMode_8036864C;extern u8 lbl_8036860C[8];
void OSRegisterVersion(const char*);void *__OSLockSram(void);void __OSUnlockSram(s32);
void OSInitThreadQueue(void*);void __OSSetInterruptHandler(s32,void(*)(void));void __OSUnmaskInterrupts(u32);void fn_8020FD50(void);
u8 *data=lbl_8029D2C8,*v=lbl_8033A068;
u16 *tim;u32 *modep,*progp;u16 control;u32 tv,boot;s32 maxx,x;s32 divisor,parity,y,limit,high,low,tmp;
u16 *pF2,*pF6;s16 offV;u16 acv;
if(!lbl_80368600){
OSRegisterVersion(lbl_80366F90);lbl_80368600=1;lbl_80368620=(void*)1;
if(!(__VIRegs[1]&1))fn_802100F4(0);
lbl_80368604=0;lbl_80368634=0;lbl_80368630=0;lbl_80368644=0;lbl_80368640=0;lbl_80368628=0;lbl_80368638=0;lbl_80368608=0;
__VIRegs[39]=*(u16*)(data+0x1c0)|((*(u16*)(data+0x1c2)<<10)&0xfc00);
__VIRegs[38]=((s32)*(u16*)(data+0x1c2)>>6)|(*(u16*)(data+0x1c4)<<4);
__VIRegs[41]=*(u16*)(data+0x1c6)|((*(u16*)(data+0x1c8)<<10)&0xfc00);
__VIRegs[40]=((s32)*(u16*)(data+0x1c8)>>6)|(*(u16*)(data+0x1ca)<<4);
__VIRegs[43]=*(u16*)(data+0x1cc)|((*(u16*)(data+0x1ce)<<10)&0xfc00);
__VIRegs[42]=((s32)*(u16*)(data+0x1ce)>>6)|(*(u16*)(data+0x1d0)<<4);
__VIRegs[45]=*(u16*)(data+0x1d2)|(*(u16*)(data+0x1d4)<<8);
__VIRegs[44]=*(u16*)(data+0x1d6)|(*(u16*)(data+0x1d8)<<8);
__VIRegs[47]=*(u16*)(data+0x1da)|(*(u16*)(data+0x1dc)<<8);
__VIRegs[46]=*(u16*)(data+0x1de)|(*(u16*)(data+0x1e0)<<8);
__VIRegs[49]=*(u16*)(data+0x1e2)|(*(u16*)(data+0x1e4)<<8);
__VIRegs[48]=*(u16*)(data+0x1e6)|(*(u16*)(data+0x1e8)<<8);
__VIRegs[51]=*(u16*)(data+0x1ea)|(*(u16*)(data+0x1ec)<<8);
__VIRegs[50]=*(u16*)(data+0x1ee)|(*(u16*)(data+0x1f0)<<8);
__VIRegs[0x70/2]=640;
*(s16*)&lbl_80368624=(s8)((u8*)__OSLockSram())[0x10];lbl_80368626=0;__OSUnlockSram(0);
control=__VIRegs[1];boot=*(u32*)0x800000cc;progp=(u32*)(v+0x114);*progp=(control>>2)&1;modep=(u32*)(v+0x118);*modep=(control>>8)&3;
if(boot==1&&*modep==0)*modep=5;
tv=*modep;if(tv==3)tv=0;
*(VITiming**)(v+0x144)=fn_8021004C(tv*4+*progp);
*(u16*)(v+0x2)=control;lbl_80368648=*(u16**)(v+0x144);CurrTvMode_8036864C=*modep;
pF2=(u16*)(v+0xf2);pF6=(u16*)(v+0xf6);
*(u16*)(v+0xf4)=640;tim=lbl_80368648;*pF6=(*++tim*2)&0xfffe;
*(u16*)(v+0xf0)=(720-*(u16*)(v+0xf4))/2;*pF2=0;
acv=*tim;
maxx=720-*(u16*)(v+0xf4);x=*(s16*)(v+0xf0)+*(s16*)&lbl_80368624;
*(u16*)(v+0xf8)=(x>maxx)?maxx:((x<0)?0:x);
divisor=(*(s32*)(v+0x110)==0)?2:1;
parity=*pF2&1;offV=lbl_80368626;
y=(s16)*pF2+offV;*(u16*)(v+0xfa)=(y>parity)?y:parity;
limit=(s16)acv*2-parity;
tmp=(s16)*pF2+((s16)*pF6+offV);high=(tmp-limit>0)?(tmp-limit):0;
tmp=(s16)*pF2+offV;low=(tmp-parity<0)?(tmp-parity):0;
*(u16*)(v+0xfc)=*pF6+low-high;
tmp=(s16)*pF2+offV;low=(tmp-parity<0)?(tmp-parity):0;
*(u16*)(v+0xfe)=*(u16*)(v+0x108)-low/divisor;
tmp=(s16)*pF2+((s16)*pF6+offV);high=(tmp-limit>0)?(tmp-limit):0;
tmp=(s16)*pF2+offV;low=(tmp-parity<0)?(tmp-parity):0;
*(u16*)(v+0x100)=*(u16*)(v+0x10c)+low/divisor-high/divisor;
*(u16*)(v+0x102)=640;*(u16*)(v+0x104)=(*tim*2)&0xfffe;
*(u16*)(v+0x106)=0;*(u16*)(v+0x108)=0;*(u16*)(v+0x10a)=640;*(u16*)(v+0x10c)=(*tim*2)&0xfffe;
*(u32*)(v+0x110)=0;v[0x11c]=40;v[0x11d]=40;v[0x11e]=40;v[0x12c]=0;*(u32*)(v+0x130)=1;*(u32*)(v+0x134)=0;
OSInitThreadQueue(lbl_8036860C);
__VIRegs[0x30/2]=__VIRegs[0x30/2]&0x7fff;__VIRegs[0x34/2]=__VIRegs[0x34/2]&0x7fff;
lbl_80368614=0;lbl_80368618=0;__OSSetInterruptHandler(24,fn_8020FD50);__OSUnmaskInterrupts(0x80);
}
}
#pragma peephole on
void VIWaitForRetrace(void) {
extern u32 lbl_80368604;
extern u8 lbl_8036860C;
BOOL OSDisableInterrupts(void);
void OSRestoreInterrupts(BOOL);
void OSSleepThread(void *);
BOOL enabled;
u32 previous;
enabled=OSDisableInterrupts();
previous=lbl_80368604;
do { OSSleepThread(&lbl_8036860C); } while(previous==lbl_80368604);
OSRestoreInterrupts(enabled);
}

#pragma push
#pragma opt_lifetimes off
void fn_802107FC(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4)
{
  extern u8 lbl_8033A068[];
  u8 *a = (u8 *) arg0;
  u8 *base = lbl_8033A068;
  u32 *p1 = (u32 *) arg1;
  u32 *p2 = (u32 *) arg2;
  u32 *p3 = (u32 *) arg3;
  u32 *p4 = (u32 *) arg4;
  s32 shift = (*((u8 *) (a + 0x2C))) << 5;
  u32 mult = *((u16 *) (a + 0xE));
  u16 ext = *((u16 *) (a + 0x16));
  s32 v20 = *((s32 *) (a + 0x20));
  u32 v30 = *((u32 *) (a + 0x30));
  s32 v0A = *((u16 *) (a + 0xA));
  u32 prod = shift * mult;
  u32 term = (ext * 2) & 0xFFFFFFE0;
  u8 *new_var2;
  u32 sum = term + prod;
  u32 var;
  u32 tmp;
  u8 *new_var;
  *p1 = v30 + sum;
  if (v20 == 0)
  {
    var = *p1;
  }
  else
  {
    var = (*p1) + shift;
  }
  *p2 = var;
  if ((v0A % 2) == 1)
  {
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
  }
  *p1 &= 0x3FFFFFFF;
  *p2 &= 0x3FFFFFFF;
  if ((*((s32 *) (a + 0x44))) != 0)
  {
    s32 shift2 = (*((u8 *) (a + 0x2C))) << 5;
    u32 prod2 = shift2 * (*((u16 *) (a + 0xE)));
    u32 term2 = term = ((*((u16 *) (a + 0x16))) * 2) & 0xFFFFFFE0;
    s32 v20b = *((s32 *) (a + 0x20));
    s32 v0Ab = *((u16 *) (a + 0xA));
    u32 val2 = (*((u32 *) (a + 0x48))) + (term2 + prod2);
    *p3 = val2;
    if (v20b == 0)
    {
      var = *p3;
    }
    else
    {
      var = (*p3) + shift2;
    }
    *p4 = var;
    if ((v0Ab % 2) == 1)
    {
      tmp = *p3;
      *p3 = *p4;
      *p4 = tmp;
    }
    *p3 &= 0x3FFFFFFF;
    *p4 &= 0x3FFFFFFF;
  }
  if (((((*p1) < 0x01000000U) && ((*p2) < 0x01000000U)) && ((*p3) < 0x01000000U)) && ((*p4) < 0x01000000U))
  {
    var = ((*((s32 *) (a + 0x44))) != 0) * 0;
  }
  else
  {
    var = 1;
  }
  if (var != 0)
  {
    *p1 >>= 5;
    *p2 >>= 5;
    *p3 >>= 5;
    *p4 >>= 5;
  }
  *((u16 *) (base + 0x1E)) = (u16) (*p1);
  *((volatile u32 *) (&lbl_80368634)) = *((volatile u32 *) (&lbl_80368634));
  lbl_80368630 = (void *) (((u32) lbl_80368630) | 0x10000);
  *((u16 *) (base + 0x1C)) = (u16) ((var << 0xC) | (((*p1) >> 0x10) | ((*((u8 *) (a + 0x3C))) << 8)));
  *((volatile u32 *) (&lbl_80368634)) = *((volatile u32 *) (&lbl_80368634));
  lbl_80368630 = (void *) (((u32) lbl_80368630) | 0x20000);
  *((u16 *) (base + 0x26)) = (u16) (*p2);
  new_var = base + 0x20;
  *((volatile u32 *) (&lbl_80368634)) = *((volatile u32 *) (&lbl_80368634));
  lbl_80368630 = (void *) (((u32) lbl_80368630) | 0x1000);
  *((u16 *) (base + 0x24)) = (u16) ((*p2) >> 0x10);
  new_var2 = base + 0x2A;
  *((volatile u32 *) (&lbl_80368634)) = *((volatile u32 *) (&lbl_80368634));
  lbl_80368630 = (void *) (((u32) lbl_80368630) | 0x2000);
  if ((*((s32 *) (a + 0x44))) != 0)
  {
    *((u16 *) (base + 0x22)) = (u16) (*p3);
    *((volatile u32 *) (&lbl_80368634)) = *((volatile u32 *) (&lbl_80368634));
    lbl_80368630 = (void *) (((u32) lbl_80368630) | 0x4000);
    *((u16 *) new_var) = (u16) ((*p3) >> 0x10);
    *((volatile u32 *) (&lbl_80368634)) = *((volatile u32 *) (&lbl_80368634));
    lbl_80368630 = (void *) (((u32) lbl_80368630) | 0x8000);
    *((u16 *) new_var2) = (u16) (*p4);
    *((volatile u32 *) (&lbl_80368634)) = *((volatile u32 *) (&lbl_80368634));
    lbl_80368630 = (void *) (((u32) lbl_80368630) | 0x400);
    *((u16 *) (base + 0x28)) = (u16) ((*p4) >> 0x10);
    *((volatile u32 *) (&lbl_80368634)) = *((volatile u32 *) (&lbl_80368634));
    lbl_80368630 = (void *) (((u32) lbl_80368630) | 0x800);
  }
}
#pragma push
#pragma opt_lifetimes off
void fn_80210AD0(u16 dispPosY, u16 dispSizeY, u8 equ, u16 acv, u16 trimOdd, u16 trimEven, u16 psbOdd, u16 psbEven, s32 black) {
    extern u16 lbl_8033A068[];
    u16 *regs = lbl_8033A068;
    u16 actualPrbOdd;
    u16 actualPrbEven;
    u16 actualPsbOdd;
    u16 actualPsbEven;
    u16 div1;
    u16 div2;
    u16 half;

    if (regs[54] & 1) {
        div1 = 1;
        div2 = 2;
    } else {
        div1 = 2;
        div2 = 1;
    }

    if ((dispPosY % 2) == 0) {
        actualPrbOdd = (u16)(trimOdd + div2 * dispPosY);
        actualPsbOdd = (u16)(psbOdd + div2 * ((div1 * acv - dispSizeY) - dispPosY));
        actualPrbEven = (u16)(trimEven + div2 * dispPosY);
        actualPsbEven = (u16)(psbEven + div2 * ((div1 * acv - dispSizeY) - dispPosY));
    } else {
        actualPrbOdd = (u16)(trimEven + div2 * dispPosY);
        actualPsbOdd = (u16)(psbEven + div2 * ((div1 * acv - dispSizeY) - dispPosY));
        actualPrbEven = (u16)(trimOdd + div2 * dispPosY);
        actualPsbEven = (u16)(psbOdd + div2 * ((div1 * acv - dispSizeY) - dispPosY));
    }

    half = (u16)(dispSizeY / div1);
    if (black) {
        actualPrbOdd += 2 * half - 2;
        actualPrbEven += 2 * half - 2;
        half = 0;
        actualPsbOdd += 2;
        actualPsbEven += 2;
    }

    regs[0] = (u16)(equ | ((half << 4) & 0xFFFF0));
    *(u64 *)&lbl_80368630 |= 0x8000000000000000ULL;
    regs[7] = actualPrbOdd;
    *(u64 *)&lbl_80368630 |= 0x0100000000000000ULL;
    regs[6] = actualPsbOdd;
    *(u64 *)&lbl_80368630 |= 0x0200000000000000ULL;
    regs[9] = actualPrbEven;
    *(u64 *)&lbl_80368630 |= 0x0040000000000000ULL;
    regs[8] = actualPsbEven;
    *(u64 *)&lbl_80368630 |= 0x0080000000000000ULL;
}
#pragma pop
void VIConfigure(void *arg0) {
    BOOL OSDisableInterrupts(void);
    void OSRestoreInterrupts(BOOL);
    void OSReport(char *, ...);
    void OSPanic(char *, s32, char *, ...);
    VITiming *fn_8021004C(u32);
    void fn_802107FC(void *, void *, void *, void *, void *);
    void fn_80210AD0(u16, u16, u8, u16, u16, u16, u16, u16, u32);
    extern u8 lbl_8029D2C8[];
    extern u8 lbl_8033A068[];
    extern u32 lbl_80368658;
    extern u32 lbl_80368660;
    extern s16 lbl_80368626;

    BOOL irq;
    u8 *data;
    u16 *p106;
    s32 tv;
    u16 *p10A;
    u32 mode;
    u16 *p108;
    u8 *self;
    u16 *pFA;
    u16 *pFC;
    s32 *p134;
    u32 *p118;
    u16 *pF6;
    u16 *pF2;
    u16 *pF4;
    s32 *p110;
    u16 *p10C;
    u16 *p102;
    u32 *progp;
    u8 *v;
    VITiming *tm;
    u32 tmp;
    s32 maxx, x;
    s32 divisor, parity, y, limit, high, low, tmpi;
    u16 val, r2, r6c;
    u32 r0;

    self = (u8 *)arg0;
    data = lbl_8029D2C8;
    v = lbl_8033A068;
    irq = OSDisableInterrupts();
    progp = (u32 *)(v + 0x114);
    tmp = *(u32 *)self & 3;
    if (*progp != tmp) {
        lbl_80368628 = (void *)1;
        *progp = tmp;
    }
    tv = *(s32 *)0x800000CC;
    mode = *(u32 *)self >> 2;
    if (mode == 4 && lbl_80368660 == 0) {
        lbl_80368660 = 1;
        OSReport((char *)(data + 0x270));
        OSReport((char *)(data + 0x29c));
        OSReport((char *)(data + 0x2c8));
        OSReport((char *)(data + 0x2f4));
        OSReport((char *)(data + 0x320));
        OSReport((char *)(data + 0x34c));
        OSReport((char *)(data + 0x270));
    }
    switch (tv) {
    case 0:
    case 2:
    case 6:
    case 7:
        if (mode != 0 && mode != 2 && (u32)(mode - 6) > 1) {
            goto err;
        }
        break;
    case 1:
    case 5:
        if (mode != 1 && mode != 5) {
            goto err;
        }
        break;
    default:
    err:
        OSPanic("vi.c", 0x7bb, (char *)(data + 0x378), tv, mode);
        break;
    }
    if (mode == 0 || mode == 2) {
        *(u32 *)(v + 0x118) = (u32)tv;
    } else {
        *(u32 *)(v + 0x118) = mode;
    }
    *(u16 *)(v + 0xf0) = *(u16 *)(self + 0xa);
    if (*progp == 1) {
        val = (u16)(*(u16 *)(self + 0xc) << 1);
    } else {
        val = *(u16 *)(self + 0xc);
    }
    *(u16 *)(v + 0xf2) = val;
    pF2 = (u16 *)(v + 0xf2);
    pF4 = (u16 *)(v + 0xf4);
    p102 = (u16 *)(v + 0x102);
    p110 = (s32 *)(v + 0x110);
    p10A = (u16 *)(v + 0x10a);
    p10C = (u16 *)(v + 0x10c);
    p106 = (u16 *)(v + 0x106);
    p108 = (u16 *)(v + 0x108);
    *pF4 = *(u16 *)(self + 0xe);
    *p102 = *(u16 *)(self + 4);
    *(u16 *)(v + 0x104) = *(u16 *)(self + 8);
    *p110 = *(s32 *)(self + 0x14);
    *p10A = *p102;
    *p10C = *(u16 *)(v + 0x104);
    *p106 = 0;
    *p108 = 0;
    if (*progp == 2) {
        val = *p10C;
    } else if (*progp == 3) {
        val = *p10C;
    } else if (*p110 == 0) {
        val = (u16)(*p10C << 1);
    } else {
        val = *p10C;
    }
    pF6 = (u16 *)(v + 0xf6);
    *pF6 = val;
    p134 = (s32 *)(v + 0x134);
    *p134 = (*progp == 3) ? 1 : 0;
    p118 = (u32 *)(v + 0x118);
    tm = fn_8021004C((*p118 << 2) + *progp);
    *(VITiming **)(v + 0x144) = tm;
    maxx = 0x2d0 - *pF4;
    x = *(s16 *)(v + 0xf0) + *(s16 *)&lbl_80368624;
    if (x > maxx) {
        x = maxx;
    } else if (x < 0) {
        x = 0;
    }
    *(u16 *)(v + 0xf8) = x;
    divisor = (*p110 == 0) ? 2 : 1;
    parity = *pF2 & 1;
    y = (s16)*pF2 + lbl_80368626;
    if (y <= parity) {
        y = parity;
    }
    pFA = (u16 *)(v + 0xfa);
    *pFA = y;
    limit = ((s16)tm->unk2 << 1) - parity;
    tmpi = (s16)*pF2 + ((s16)*pF6 + lbl_80368626);
    high = (tmpi - limit > 0) ? (tmpi - limit) : 0;
    tmpi = (s16)*pF2 + lbl_80368626;
    low = (tmpi - parity < 0) ? (tmpi - parity) : 0;
    pFC = (u16 *)(v + 0xfc);
    *pFC = (u16)(*pF6 + low - high);
    tmpi = (s16)*pF2 + lbl_80368626;
    low = (tmpi - parity < 0) ? (tmpi - parity) : 0;
    *(u16 *)(v + 0xfe) = (u16)(*p108 - low / divisor);
    tmpi = (s16)*pF2 + ((s16)*pF6 + lbl_80368626);
    high = (tmpi - limit > 0) ? (tmpi - limit) : 0;
    tmpi = (s16)*pF2 + lbl_80368626;
    low = (tmpi - parity < 0) ? (tmpi - parity) : 0;
    *(u16 *)(v + 0x100) = (u16)(*p10C + low / divisor - high / divisor);
    if (lbl_80368620 == 0) {
        *p118 = 3;
    }
    {
        u16 t18 = tm->unk18;
        u16 half = (u16)((s32)t18 / 2);
        if ((u16)(t18 % 2) != 0) {
            val = tm->unk1A;
        } else {
            val = 0;
        }
        *(u16 *)(v + 0x32) = (u16)(val + 1);
        *(u64 *)&lbl_80368630 |= 0x4000000000ULL;
        *(u16 *)(v + 0x30) = (u16)((half + 1) | 0x1000);
        *(u64 *)&lbl_80368630 |= 0x8000000000ULL;
    }
    r2 = *(u16 *)(v + 2);
    r6c = *(u16 *)(v + 0x6c);
    if (*progp == 2 || *progp == 3) {
        r2 = (u16)((r2 & ~4) | 4);
        r6c = (u16)((r6c & ~1) | 1);
    } else {
        r2 = (u16)((r2 & ~4) | ((*progp << 2) & 4));
        r6c = (u16)(r6c & ~1);
    }
    r2 = (u16)((r2 & ~8) | (*p134 << 3));
    if (*p118 == 1 || (*p118 - 2) <= 1) {
        r0 = (r2 & 0xFCFF) | (*p118 << 8);
    } else {
        r0 = r2 & 0xFCFF;
    }
    *(u16 *)(v + 2) = (u16)r0;
    *(u16 *)(v + 0x6c) = r6c;
    *(u64 *)&lbl_80368630 |= 0x4000000000000000ULL;
    *(u64 *)&lbl_80368630 |= 0x200ULL;
    if (*p134 != 0) {
        val = (u16)(*p10A << 1);
    } else {
        val = *p10A;
    }
    if (val < *pF4) {
        *(u16 *)(v + 0x4a) = (u16)(((*pF4 + ((val << 8) - 1)) / *pF4) | 0x1000);
        *(u64 *)&lbl_80368630 |= 0x04000000ULL;
        *(u16 *)(v + 0x70) = val;
        *(u64 *)&lbl_80368630 |= 0x80ULL;
    } else {
        *(u16 *)(v + 0x4a) = 0x100;
        *(u64 *)&lbl_80368630 |= 0x04000000ULL;
    }
    *(u16 *)(v + 6) = tm->unk1A;
    *(u64 *)&lbl_80368630 |= 0x1000000000000000ULL;
    *(u16 *)(v + 4) = (u16)(tm->unk1E | (tm->unk1D << 8));
    *(u64 *)&lbl_80368630 |= 0x2000000000000000ULL;
    r0 = (tm->unk1F + *(u16 *)(v + 0xf8)) - 0x28;
    *(u16 *)(v + 0xa) = (u16)(tm->unk1C | ((r0 << 7) & 0xFF80));
    *(u64 *)&lbl_80368630 |= 0x0400000000000000ULL;
    *(u16 *)(v + 8) = (u16)((r0 >> 9) | (((tm->unk20 + *(u16 *)(v + 0xf8) + 0x28) - (0x2d0 - *pF4)) << 1));
    *(u64 *)&lbl_80368630 |= 0x0800000000000000ULL;
    *(u16 *)(v + 0x16) = (u16)(tm->unkC | (tm->unk10 << 5));
    *(u64 *)&lbl_80368630 |= 0x0010000000000000ULL;
    *(u16 *)(v + 0x14) = (u16)(tm->unkE | (tm->unk14 << 5));
    *(u64 *)&lbl_80368630 |= 0x0020000000000000ULL;
    *(u16 *)(v + 0x1a) = (u16)(tm->unkD | (tm->unk12 << 5));
    *(u64 *)&lbl_80368630 |= 0x0004000000000000ULL;
    *(u16 *)(v + 0x18) = (u16)(tm->unkF | (tm->unk16 << 5));
    *(u64 *)&lbl_80368630 |= 0x0008000000000000ULL;
    v[0x11c] = (u8)((*p102 + 0xf) / 16);
    if (*p110 == 0) {
        v[0x11d] = v[0x11c];
    } else {
        v[0x11d] = (u8)(v[0x11c] << 1);
    }
    v[0x12c] = (u8)(*p106 % 16);
    v[0x11e] = (u8)((v[0x12c] + (*p10A + 0xf)) / 16);
    *(u16 *)(v + 0x48) = (u16)(v[0x11d] | (v[0x11e] << 8));
    *(u64 *)&lbl_80368630 |= 0x08000000ULL;
    if (lbl_80368658 != 0) {
        fn_802107FC(v + 0xf0, v + 0x124, v + 0x128, v + 0x13c, v + 0x140);
    }
    fn_80210AD0(*pFA, *pFC, tm->unk0, tm->unk2, tm->unk4, tm->unk6, tm->unk8, tm->unkA, *(u32 *)(v + 0x130));
    OSRestoreInterrupts(irq);
}

static inline void VIFlushMode(u32 *shadow, u32 *changed) {
    *shadow |= *changed;
    *changed = 0;
}

static inline s32 cntlzd(u64 bit) {
    u32 hi = (u32)(bit >> 32);
    u32 lo = (u32)(bit & 0xFFFFFFFF);
    s32 value = __cntlzw(hi);
    if (value < 32) {
        return value;
    }
    return __cntlzw(lo) + 32;
}

#pragma push
#pragma optimization_level 3
#pragma global_optimizer off
#pragma opt_common_subs off
void VIFlush(void) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    extern u8 lbl_8033A068[];
    extern s32 lbl_80368608;
    struct {
        u16 regs[60];
        u16 shdwRegs[60];
        u8 pad[0x30];
        void *unk120;
    } *vi = (void *)lbl_8033A068;
    s32 enabled;
    s32 regIndex;
    u16 *p;

    enabled = OSDisableInterrupts();
    *(u32 *)&lbl_80368638 |= *(u32 *)&lbl_80368628;
    *(u32 *)&lbl_80368628 = 0;
    *(u32 *)&lbl_80368644 |= *(u32 *)&lbl_80368634;
    *(u32 *)&lbl_80368640 |= *(u32 *)&lbl_80368630;

    while (*(u64 *)&lbl_80368630 != 0) {
        regIndex = cntlzd(*(u64 *)&lbl_80368630);
        p = &vi->regs[regIndex];
        p[60] = vi->regs[regIndex];
        *(u64 *)&lbl_80368630 &= ~((u64)1 << (63 - regIndex));
    }

    lbl_80368608 = 1;
    lbl_80368650 = vi->unk120;
    OSRestoreInterrupts(enabled);
}
#pragma pop
void VISetNextFrameBuffer(void *frameBuffer)
{
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    void fn_802107FC(void *, void *, void *, void *, void *);
    extern u8 lbl_8033A068[];
    extern u32 lbl_80368658;
    u32 enabled;
    u8 *base = lbl_8033A068;
    enabled = OSDisableInterrupts();
    *(void **)(base + 0x120) = frameBuffer;
    lbl_80368658 = 1;
    fn_802107FC(base + 0xF0, base + 0x124, base + 0x128, base + 0x13C, base + 0x140);
    OSRestoreInterrupts(enabled);
}

void fn_80211614(s32 arg0)
{
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    void fn_80210AD0(u16, u16, u8, u16, u16, u16, u16, u16, s32);
    extern u8 lbl_8033A068[];
    u32 enabled;
    u8 *base = lbl_8033A068;
    u8 *timing;
    enabled = OSDisableInterrupts();
    *(s32 *)(base + 0x130) = arg0;
    timing = *(u8 **)(base + 0x144);
    fn_80210AD0(*(u16 *)(base + 0xFA), *(u16 *)(base + 0xF6),
        timing[0], *(u16 *)(timing + 2), *(u16 *)(timing + 4),
        *(u16 *)(timing + 6), *(u16 *)(timing + 8), *(u16 *)(timing + 10),
        *(s32 *)(base + 0x130));
    OSRestoreInterrupts(enabled);
}

#pragma use_lmw_stmw reset

#pragma peephole on
s32 fn_80211690(void) {
    extern s32 lbl_80368604;
    return lbl_80368604;
}

void fn_80211698(s32 *arg0, u32 *arg1) {
    u32 new_var3;
    volatile u16 *base;
    volatile u16 *bump = (volatile u16 *)0xCC002000;
    u32 previous;
    u32 vertical;
    u32 horizontal;
    u32 new_var;
    u32 new_var2;

    if (vertical) {}
    vertical = (*(bump += 0x16)) & 0x7FF;
    base = (volatile u16 *)0xCC002000;
    do {
        new_var3 = base[0x17];
        previous = vertical;
        horizontal = new_var3;
        vertical = (*bump) & 0x7FF;
        horizontal &= 0x7FF;
    } while (previous != vertical);
    new_var = horizontal;
    new_var2 = vertical;
    *arg0 = new_var;
    *arg1 = new_var2;
}

s32 fn_802116D4(void) {
volatile u16 *base;
u32 second;
u32 first;
volatile u16 *bump;
u32 third;
VITiming *info;
bump=(volatile u16 *)0xCC002000;
second=(*(bump += 0x16))&0x7ff;
base=(volatile u16 *)0xCC002000;
do { first=second; third=base[0x17]&0x7ff; second=(*bump)&0x7ff; } while(first!=second);
info=(VITiming *)lbl_80368648;
if (((second-1)*2+(third-1)/info->unk1A)<info->unk18) return 1;
return 0;
}

s32 fn_8021173C(void) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    extern u8 lbl_8033A158[];
    s32 field;
    s32 enabled;
    u32 vertical;
    s32 horizontal;
    void (*getPosition)(s32 *, u32 *) = fn_80211698;
    enabled = OSDisableInterrupts();
    getPosition(&horizontal, &vertical);
    {
        u32 halfLine = (vertical - 1) * 2 + (u32)(horizontal - 1) / lbl_80368648[13];
        field = halfLine < lbl_80368648[12] ? 1 : 0;
    }
    OSRestoreInterrupts(enabled);
    return field ^ 1 ^ (*(u16 *)(lbl_8033A158 + 0xA) & 1);
}

u32 fn_802117D8(void) {
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    u32 pad[4];
    volatile u16 *base;
    u32 vertical;
    u32 previous;
    volatile u16 *bump;
    u32 horizontal;
    u16 *timing;
    u32 irq;
    u32 line;

    timing = lbl_80368648;
    irq = OSDisableInterrupts();
    bump = (volatile u16 *)0xCC002000;
    vertical = (*(bump += 0x16)) & 0x7FF;
    base = (volatile u16 *)0xCC002000;
    do {
        previous = vertical;
        horizontal = base[0x17] & 0x7FF;
        vertical = (*bump) & 0x7FF;
    } while (previous != vertical);
    line = ((vertical - 1) << 1) + (horizontal - 1) / lbl_80368648[13];
    OSRestoreInterrupts(irq);
    if (line >= timing[12]) {
        line -= timing[12];
    }
    return line >> 1;
}

u32 VIGetTvFormat(void) {
extern u32 CurrTvMode_8036864C;
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
u32 format;
s32 enabled;
enabled=OSDisableInterrupts();
switch(CurrTvMode_8036864C) {
case 0: case 3: case 6: case 7: format=0; break;
case 1: case 4: format=1; break;
case 2: case 5: format=CurrTvMode_8036864C; break;
}
OSRestoreInterrupts(enabled);
return format;
}

s32 fn_802118D8(void) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s32 enabled;
    s32 temp_r31;

    enabled = OSDisableInterrupts();
    temp_r31 = *(u16 *)0xCC00206E & 3;
    OSRestoreInterrupts(enabled);
    return temp_r31 & 1;
}

void fn_80211914(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern u16 *lbl_80368648;
    extern u8 lbl_8033A158[];
    VITiming *tm;
    u32 mode;
    u32 hc;

    tm = (VITiming *)lbl_80368648;
    hc = ((arg1 - 1) * 2) + ((u32)(arg0 - 1) / tm->unk1A);
    mode = *(u32 *)(lbl_8033A158 + 0x24);

    if (mode == 0U) {
        if (hc < tm->unk18) {
            if (hc < (u32)(tm->unk4 + tm->unk0 * 3)) {
                *(s16 *)arg3 = -1;
            } else if (hc >= (u32)(tm->unk18 - tm->unk8)) {
                *(s16 *)arg3 = -1;
            } else {
                *(s16 *)arg3 = ((hc - tm->unk0 * 3) - tm->unk4) & ~1;
            }
        } else {
            hc -= tm->unk18;
            if (hc < (u32)(tm->unk6 + tm->unk0 * 3)) {
                *(s16 *)arg3 = -1;
            } else if (hc >= (u32)(tm->unk18 - tm->unkA)) {
                *(s16 *)arg3 = -1;
            } else {
                *(s16 *)arg3 = (((hc - tm->unk0 * 3) - tm->unk6) & ~1) + 1;
            }
        }
    } else if (mode == 1U) {
        if (hc >= tm->unk18) {
            hc -= tm->unk18;
        }
        if (hc < (u32)(tm->unk4 + tm->unk0 * 3)) {
            *(s16 *)arg3 = -1;
        } else if (hc >= (u32)(tm->unk18 - tm->unk8)) {
            *(s16 *)arg3 = -1;
        } else {
            *(s16 *)arg3 = ((hc - tm->unk0 * 3) - tm->unk4) & ~1;
        }
    } else if (mode == 2U) {
        if (hc < tm->unk18) {
            if (hc < (u32)(tm->unk4 + tm->unk0 * 3)) {
                *(s16 *)arg3 = -1;
            } else if (hc >= (u32)(tm->unk18 - tm->unk8)) {
                *(s16 *)arg3 = -1;
            } else {
                *(s16 *)arg3 = (hc - tm->unk0 * 3) - tm->unk4;
            }
        } else {
            hc -= tm->unk18;
            if (hc < (u32)(tm->unk6 + tm->unk0 * 3)) {
                *(s16 *)arg3 = -1;
            } else if (hc >= (u32)(tm->unk18 - tm->unkA)) {
                *(s16 *)arg3 = -1;
            } else {
                *(s16 *)arg3 = ((hc - tm->unk0 * 3) - tm->unk6) & ~1;
            }
        }
    }
    *(s16 *)arg2 = arg0 - 1;
}

void fn_80211B30(s32 arg0, s32 arg1) {
    void fn_80211914(s32, s32, s32, s32);
    u32 new_var3;
    volatile u16 *base;
    u32 vertical;
    volatile u16 *bump = (volatile u16 *)0xCC002000;
    u32 previous;
    u32 horizontal;
    u32 new_var;
    u32 new_var2;

    if (vertical) {}
    vertical = (*(bump += 0x16)) & 0x7FF;
    base = (volatile u16 *)0xCC002000;
    do {
        new_var3 = base[0x17];
        previous = vertical;
        horizontal = new_var3;
        vertical = (*bump) & 0x7FF;
        horizontal &= 0x7FF;
    } while (previous != vertical);
    new_var = horizontal;
    new_var2 = vertical;
    fn_80211914(new_var, new_var2, arg0, arg1);
}

void fn_80211B90(s8 *arg0, s8 *arg1, s8 arg2, s8 arg3, s8 arg4) {
    s32 sa;
    s32 a;
    s32 b;
    s32 sb;
    s32 t9;
    s32 t7;
    s32 t;

    sa = *arg0;
    b = *arg1;
    a = sa;
    if (sa >= 0) {
        sa = 1;
    } else {
        sa = -1;
        a = -a;
    }
    if (b >= 0) {
        sb = 1;
    } else {
        sb = -1;
        b = -b;
    }
    if (a <= arg4) {
        a = 0;
    } else {
        a = a - arg4;
    }
    if (b <= arg4) {
        b = 0;
    } else {
        b = b - arg4;
    }
    if (a == 0 && b == 0) {
        *arg1 = 0;
        *arg0 = 0;
        return;
    }
    t9 = arg3 * b;
    t7 = arg3 * a;
    if (t9 <= t7) {
        t = arg3 * arg2;
        t7 = t7 + b * (arg2 - arg3);
        if (t < t7) {
            a = (s8)((a * t) / t7);
            b = (s8)((b * t) / t7);
        }
    } else {
        t = arg3 * arg2;
        t7 = t9 + a * (arg2 - arg3);
        if (t < t7) {
            a = (s8)((a * t) / t7);
            b = (s8)((b * t) / t7);
        }
    }
    *arg0 = sa * a;
    *arg1 = sb * b;
}

void fn_80211CC0(void *arg0) {
    void fn_80211B90(s8 *, s8 *, s8, s8, s8);
    extern u8 lbl_80282268[];

    u8 *config;
    u8 *maximum;
    s32 i;
    u8 *input;
    u8 hi;
    u8 value;
    u8 lo;

    i = 0;
    input = (u8 *)arg0;
    config = lbl_80282268;
    maximum = config + 1;

    while (i < 4) {
        if ((s8)input[0xA] == 0) {
            fn_80211B90(
                (s8 *)(input + 2),
                (s8 *)(input + 3),
                (s8)config[3],
                (s8)config[4],
                (s8)config[2]
            );

            fn_80211B90(
                (s8 *)(input + 4),
                (s8 *)(input + 5),
                (s8)config[6],
                (s8)config[7],
                (s8)config[5]
            );

            if ((hi = maximum[0], value = input[6], lo = config[0], value <= lo)) {
                input[6] = 0;
            } else {
                if (hi < value) {
                    input[6] = hi;
                }
                input[6] = input[6] - config[0];
            }

            if ((hi = maximum[0], value = input[7], lo = config[0], value <= lo)) {
                input[7] = 0;
            } else {
                if (hi < value) {
                    input[7] = hi;
                }
                input[7] = input[7] - config[0];
            }
        }
        i += 1;
        input += 0xC;
    }
}

extern u16 Scb_80339420[4];
extern u16 lbl_80282268[8];
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
extern u16 lbl_8029D210[];
