/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
extern u16 Scb_80339420[];
typedef struct OSSram {
    u16 checkSum;
    u16 checkSumInv;
    u32 ead0;
    u32 ead1;
    u32 counterBias;
    s8 displayOffsetH;
    u8 ntd;
    u8 language;
    u8 flags;
} OSSram;
extern s32 gSaveDataBase;;
extern s32 fn_80013E50(s32);
extern s32 fn_80013E60(s32, s32);
extern s32 fn_80013E74(void*, s32);
extern s32 lbl_80366F60;
extern s32 lbl_8029CFE8;


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
extern void *fn_8020DAE0;
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
extern s32 lbl_80368508;
extern u32 lbl_8036850C;
extern s64 __OSStartTime;
extern void (*lbl_803684F8)();

#pragma peephole off

#pragma peephole reset

extern void* __OSSystemCallVectorStart;
extern void* __OSSystemCallVectorEnd;

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern s32* FstStart_8036857C;
extern s32 currentDirectory;

extern u16 Scb_803394;

u32 __OSGetResetSWState(void);

extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void* RunQueue_80339478[];
extern s32 RunQueueBits_80368518;
extern s32 RunQueueHint_8036851C;

void fn_80208FB0(s32 chan, void *ctx) {
    s32 fn_80209010(void *, s32, s32);
    u8 *scb;
    s32 *p40;
    s32 off;
    s32 sync;

    scb = (u8 *)Scb_80339420;
    p40 = (s32 *)(scb + 0x40);
    off = *p40;
    sync = fn_80209010(scb + off, off, 0x40 - off);
    *(s32 *)(scb + 0x4C) = sync;
    if (*(s32 *)(scb + 0x4C) != 0) {
        *p40 = 0x40;
    }
}

s32 fn_80209010(s32 arg0, s32 arg1, s32 arg2) {
s32 EXILock(s32,s32,void (*)(void));
s32 EXISelect(s32,s32,s32);
s32 EXIUnlock(s32);
s32 EXIImm(s32,void *,s32,s32,s32);
s32 EXISync(s32);
s32 EXIImmEx(s32,s32,s32,s32);
s32 EXIDeselect(s32);
void fn_80208FB0(void);
s32 command;
s32 error;
if(!EXILock(0,1,fn_80208FB0)) return 0;
if(!EXISelect(0,1,3)){ EXIUnlock(0); return 0; }
arg1 <<= 6;
command=(arg1+0x100)|0xA0000000;
error=!EXIImm(0,&command,4,1,0);
error|=!EXISync(0);
error|=!EXIImmEx(0,arg0,arg2,1);
error|=!EXIDeselect(0);
EXIUnlock(0);
return !error;
}

void __OSInitSram(void) {
s32 EXILock(s32,s32,void *);
s32 EXISelect(s32,s32,s32);
s32 EXIUnlock(s32);
s32 EXIImm(s32,void *,s32,s32,s32);
s32 EXISync(s32);
s32 EXIDma(s32,void *,s32,s32,s32);
s32 EXIDeselect(s32);
u16 OSGetGbsMode(void);
void OSSetGbsMode(u16);
s32 command;
u8 *scb;
s32 result=0;
scb=(u8 *)Scb_80339420;
*(s32 *)(scb+0x44)=0;
*(s32 *)(scb+0x48)=0;
DCInvalidateRange(scb,0x40);
if(!EXILock(0,1,0)) { result=0; }
else if(!EXISelect(0,1,3)) { EXIUnlock(0); }
else {
command=0x20000100;
result=!EXIImm(0,&command,4,1,0);
result|=!EXISync(0);
result|=!EXIDma(0,scb,0x40,0,0);
result|=!EXISync(0);
result|=!EXIDeselect(0);
EXIUnlock(0);
result=!result;
}
*(s32 *)(scb+0x4C)=result;
*(s32 *)(scb+0x40)=0x40;
OSSetGbsMode(OSGetGbsMode());
}

void *__OSLockSram(void) {
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);

    u8 *scb;
    s32 *locked;
    u32 interrupts;

    scb = (u8 *)Scb_80339420;
    interrupts = OSDisableInterrupts();
    locked = (s32 *)(scb + 0x48);
    if (*locked != 0) {
        OSRestoreInterrupts(interrupts);
        scb = NULL;
    } else {
        *(u32 *)(scb + 0x44) = interrupts;
        *locked = 1;
    }
    return scb;
}

void *__OSLockSramEx(void) {
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);

    u8 *scb;
    s32 *locked;
    u32 interrupts;

    scb = (u8 *)Scb_80339420;
    interrupts = OSDisableInterrupts();
    locked = (s32 *)(scb + 0x48);
    if (*locked != 0) {
        OSRestoreInterrupts(interrupts);
        return NULL;
    }
    *(u32 *)(scb + 0x44) = interrupts;
    *locked = 1;
    return scb + 0x14;
}

#pragma opt_common_subs off
#pragma opt_propagation off
s32 fn_8020931C(s32 commit, s32 offset) {
    void OSRestoreInterrupts(s32);
    u8 *scb = (u8 *)Scb_80339420;
    u32 *dirty;
    u16 *p;
    if (commit) {
        if ((u32)offset == 0) {
            if ((scb[0x13] & 3U) > 2U) scb[0x13] &= ~3;
            ((OSSram *)scb)->checkSum = ((OSSram *)scb)->checkSumInv = 0;
            for (p=(u16 *)(scb+0xc); p<(u16 *)(scb+0x14); p++) {
                ((OSSram *)scb)->checkSum += *p;
                ((OSSram *)scb)->checkSumInv = ((OSSram *)scb)->checkSumInv + ~*p;
            }
        }
        dirty=(u32 *)(scb+0x40);
        if((u32)offset < *dirty) *dirty=offset;
        if(*dirty <= 0x14) {
            u16 mode;
            u8 *ex;
            ex=scb+0x14;
            mode=*(u16 *)(ex+0x28);
            if ((mode&0x7c00U)==0x5000 || (mode&0xc0U)==0xc0)
                *(u16 *)(ex+0x28)=0;
        }
        *(s32 *)(scb+0x4c)=fn_80209010((s32)(scb+*dirty),*dirty,0x40-*dirty);
        if(*(s32 *)(scb+0x4c)) *dirty=0x40;
    }
    *(s32 *)(scb+0x48)=0;
    OSRestoreInterrupts(*(s32 *)(scb+0x44));
    return *(s32 *)(scb+0x4c);
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
s32 fn_8020931C(s32 commit, s32 offset);

