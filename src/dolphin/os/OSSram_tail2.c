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
extern s32 lbl_80368508;
extern u32 lbl_8036850C;
extern s64 __OSStartTime;
extern void (*lbl_803684F8)();

#pragma peephole off

#pragma peephole reset

extern u8 __OSSystemCallVectorStart[];
extern u8 __OSSystemCallVectorEnd[];

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

s32 fn_8020931C(s32 commit, s32 offset);

void fn_80209AE8(u32 arg0) {
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    s32 fn_8020931C(s32, s32);
    extern u16 Scb_80339420[];

    u8 *scb;
    volatile s32 *locked;
    u32 interrupts;
    u32 mode;
    u8 flags;
    u8 pad[8];

    scb = (u8 *)Scb_80339420;
    mode = (arg0 & 1) << 6;

    interrupts = OSDisableInterrupts();
    locked = (volatile s32 *)(scb + 0x48);

    if (*locked != 0) {
        OSRestoreInterrupts(interrupts);
        scb = NULL;
    } else {
        *(u32 *)(scb + 0x44) = interrupts;
        *locked = 1;
    }

    flags = scb[0x11];
    if (mode == (flags & 0x40)) {
        fn_8020931C(0, 0);
    } else {
        scb[0x11] = flags & ~0x40;
        flags = scb[0x11];
        scb[0x11] = flags | mode;
        fn_8020931C(1, 0);
    }
}

s32 fn_80209B8C(s32 arg0) {
    extern u16 Scb_80339420[];
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    s32 fn_8020931C(s32, s32);

    u8 *scb;
    s32 *locked;
    u32 irq;
    u16 result;
    u8 *row;
    u8 pad[8];

    scb = (u8 *)Scb_80339420;
    irq = OSDisableInterrupts();
    locked = (s32 *)(scb + 0x48);
    if (*locked) {
        OSRestoreInterrupts(irq);
        return 0;
    }
    *(u32 *)(scb + 0x44) = irq;
    row = scb + 0x14;
    *locked = 1;
    row += arg0 << 1;
    result = *(u16 *)(row + 0x1c);
    fn_8020931C(0, 0x14);
    return result;
}

void fn_80209C10(s32 arg0, u32 arg1) {
u32 OSDisableInterrupts(void); void OSRestoreInterrupts(u32);
u8 *scb=(u8*)Scb_80339420; u32 irq; s32 *locked; u16 *entry;
irq=OSDisableInterrupts(); locked=(s32*)scb;
if(*(locked+=18)) { OSRestoreInterrupts(irq); scb=0; }
else { *(u32*)(scb+0x44)=irq; *locked=1; scb+=0x14; }
entry=(u16*)(scb+(arg0<<1)); ;
if(*(entry+=14) != (u16)arg1) { *entry=arg1; fn_8020931C(1,0x14); }
else fn_8020931C(0,0x14);
}

u16 OSGetGbsMode(void) {
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    s32 fn_8020931C(s32, s32);

    u8 *scb;
    s32 *locked;
    u32 irq;
    u16 result;
    u8 pad[8];

    scb = (u8 *)Scb_80339420;
    irq = OSDisableInterrupts();
    locked = (s32 *)(scb + 0x48);
    if (*locked) {
        OSRestoreInterrupts(irq);
        scb = 0;
    } else {
        *(u32 *)(scb + 0x44) = irq;
        *locked = 1;
        scb += 0x14;
    }
    result = *(u16 *)(scb + 0x28);
    fn_8020931C(0, 0x14);
    return result;
}

void fn_80209DE4(void) { }

#pragma scheduling off
void __OSInitSystemCall(void) {
    void memcpy(void *, const void *, u32);
    void DCFlushRangeNoSync(void *, u32);
    void ICInvalidateRange(void *, u32);
    extern u8 __OSSystemCallVectorStart[];
    extern u8 __OSSystemCallVectorEnd[];
    void *addr;
    u8 *start;
    u8 *end;

    addr = (void *)0x80000C00;
    start = __OSSystemCallVectorStart;
    end = __OSSystemCallVectorEnd;
    memcpy(addr, start, end - start);
    DCFlushRangeNoSync(addr, 0x100);
    __sync();
    ICInvalidateRange(addr, 0x100);
}
#pragma scheduling reset
void fn_80209E68(void) {

}

void __OSThreadInit(void) {
extern u8 _stack_addr[], _stack_end[];
extern void (*SwitchThreadCallback_80366F50)(void *,void *);
extern s32 Reschedule_80368520;
void OSClearStack(s32);
void OSInitThreadQueue(void *);
u8 *base;
u8 *tail;
u8 **active;
register s32 i;
u8 *thread;
base=(u8*)RunQueue_80339478; thread=base+0x418;
*(u16*)(base+0x6e0)=2; *(u16*)(base+0x6e2)=1;
*(s32*)(base+0x6ec)=16; *(s32*)(base+0x6e8)=16;
*(s32*)(base+0x6e4)=0; *(s32*)(base+0x6f0)=-1;
*(s32*)(base+0x708)=0;
OSInitThreadQueue(thread+0x2e8);
*(s32*)(base+0x710)=0; *(s32*)(base+0x70c)=0;
*(void**)0x800000d8=thread;
OSClearContext((OSContext*)thread); OSSetCurrentContext((OSContext*)thread);
*(void**)(base+0x71c)=_stack_addr; *(void**)(base+0x720)=_stack_end;
**(u32**)(base+0x720)=0xdeadbabe;
SwitchThreadCallback_80366F50(*(void**)0x800000e4,thread);
*(void**)0x800000e4=thread;
OSClearStack(0);
RunQueueBits_80368518=0; RunQueueHint_8036851C=0;
i=0;
do {OSInitThreadQueue((u8*)RunQueue_80339478+i*8); i++;}while(i<=31);
OSInitThreadQueue((void*)0x800000dc);
active=(u8**)0x800000dc;
tail=*++active;
if(!tail) *(void**)0x800000dc=thread;
else *(void**)(tail+0x2fc)=thread;
*(void**)(thread+0x300)=tail;
*(void**)(thread+0x2fc)=0;
*active=thread;
OSClearContext((OSContext*)(base+0x730));
Reschedule_80368520=0;
}

void OSInitThreadQueue(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
}

s32 fn_80209FD4(void) {
    return *(s32 *)0x800000E4;
}
