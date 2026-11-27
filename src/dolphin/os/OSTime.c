/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
extern u16 Scb_80339420[];
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
extern void (*lbl_803684F8)();

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

typedef struct OSCalendarTime {
    s32 sec;
    s32 min;
    s32 hour;
    s32 mday;
    s32 mon;
    s32 year;
    s32 wday;
    s32 yday;
    s32 msec;
    s32 usec;
} OSCalendarTime;

#pragma peephole off
#pragma use_lmw_stmw on
void fn_8020B294(u64 ticks, OSCalendarTime *td) {
    s64 __mod2i(s64, s64);
    s64 __div2i(s64, s64);
    void fn_8020B0F8(s32, void *);
    s32 days;
    s32 secs;
    s32 hours;
    s64 tmp;
    s64 d;
    u32 daySec;
    u32 usecDiv;

    d = __mod2i((s64)ticks, (s64)(*(u32 *)0x800000F8 >> 2));
    if (d < 0) {
        d += (s64)(*(u32 *)0x800000F8 >> 2);
    }
    usecDiv = __mulhwu(0x431BDE83, *(u32 *)0x800000F8 >> 2) >> 15;
    tmp = __div2i(d * 8, (s64)usecDiv);
    td->usec = (s32)__mod2i(tmp, 1000);
    tmp = __div2i(d, (s64)(__mulhwu(0x10624DD3, *(u32 *)0x800000F8 >> 2) >> 6));
    td->msec = (s32)__mod2i(tmp, 1000);
    ticks -= (u64)d;
    daySec = 0x15180;
    tmp = __div2i((s64)ticks, (s64)(*(u32 *)0x800000F8 >> 2));
    days = (s32)(__div2i(tmp, (s64)daySec) + 0xB2575);
    secs = (s32)__mod2i(__div2i((s64)ticks, (s64)(*(u32 *)0x800000F8 >> 2)), (s64)daySec);
    if (secs < 0) {
        days -= 1;
        secs += 0x15180;
    }
    fn_8020B0F8(days, td);
    hours = secs / 60;
    td->hour = hours / 60;
    td->min = hours % 60;
    td->sec = secs % 60;
}
#pragma use_lmw_stmw reset
#pragma peephole reset
void __init_cpp(void);

void __init_user(void) {
    __init_cpp();
}

#pragma peephole off
void __init_cpp(void)
{
    extern void (*_ctors[])(void);
    void (**ctor)(void);

    for (ctor = _ctors; *ctor; ctor++) {
        (*ctor)();
    }
}
#pragma peephole on
void _ExitProcess(void) {
    M2C_UNK PPCHalt();
    PPCHalt();
}
