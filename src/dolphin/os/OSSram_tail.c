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

s32 __OSSyncSram(void) {
    return M2C_FIELD(&Scb_80339420, s32 *, 0x4C);
}

s32 fn_802098F8(void) {
    u16 *scb;
    
    scb = Scb_80339420;
    OSDisableInterrupts();
    if (scb[0x48 / 2] != 0) {
        OSRestoreInterrupts();
        return 0;
    } else {
        scb[0x44 / 2] = 0; // OSDisableInterrupts() returns void, so we can't cast it
        scb[0x48 / 2] = 1;
    }
    
    return (scb[0x13 / 2] >> 7) & 1;
}

void fn_80209968(u32 arg0) {
    extern u16 Scb_80339420[];

    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    s32 fn_8020931C(s32, s32);

    volatile u8 *scb;
    volatile u32 *lock;
    u32 interrupts;
    u32 mode;
    u32 flags;

    scb = (volatile u8 *)Scb_80339420;
    mode = (arg0 & 1) << 7;

    interrupts = OSDisableInterrupts();

    lock = (volatile u32 *)(scb + 0x48);

    if (*lock != 0) {
        OSRestoreInterrupts(interrupts);
        return;
    }

    *(volatile u32 *)(scb + 0x44) = interrupts;
    *lock = 1;

    flags = scb[0x13];

    if ((flags & 0x80) == mode) {
        fn_8020931C(0, 0);
    } else {
        scb[0x13] = flags & ~0x80;

        flags = scb[0x13];
        scb[0x13] = flags | mode;

        fn_8020931C(1, 0);
    }
}

u8 fn_80209A0C(void) {
 u32 OSDisableInterrupts(void);
 void OSRestoreInterrupts(u32);
 void fn_8020931C(s32, s32);
 u8 *scb;
 s32 *locked;
 u32 interrupts;
 u8 value;
 scb = (u8 *)Scb_80339420;
 interrupts = OSDisableInterrupts();
 locked = (s32 *)(scb += 0x48);
 if (*locked != 0) { OSRestoreInterrupts(interrupts); scb = NULL; }
 else { *(u32 *)(scb - 4) = interrupts; *locked = 1; }
 value = scb[-0x36];
 fn_8020931C(0,0);
 return value;
}

