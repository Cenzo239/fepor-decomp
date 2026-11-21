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

s32 fn_802096B0(void *arg0, s32 arg1, s32 arg2) {
s32 EXILock(s32,s32,void *);
s32 EXISelect(s32,s32,s32);
s32 EXIUnlock(s32);
s32 EXIImm(s32,void *,s32,s32,s32);
s32 EXISync(s32);
s32 EXIDma(s32,void *,s32,s32,s32);
s32 EXIDeselect(s32);
s32 command;
s32 error;
DCInvalidateRange(arg0,arg1);
if(!EXILock(0,1,0)) return 0;
if(!EXISelect(0,1,3)){EXIUnlock(0);return 0;}
command=arg2<<6;
error=!EXIImm(0,&command,4,1,0);
error|=!EXISync(0);
error|=!EXIDma(0,arg0,arg1,0,0);
error|=!EXISync(0);
error|=!EXIDeselect(0);
EXIUnlock(0);
return !error;
}

#pragma opt_lifetimes off
s32 fn_802097D4(void) {
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    void fn_8020931C(s32, s32);

    u8 *scb;
    s32 *locked;
    u32 interrupts;
    u8 pad[16];

    scb = (u8 *)Scb_80339420;
    interrupts = OSDisableInterrupts();
    locked = (s32 *)(scb + 0x48);
    if (*locked) {
        OSRestoreInterrupts(interrupts);
        scb = 0;
    } else {
        *(u32 *)(scb + 0x44) = interrupts;
        *locked = 1;
    }
    if ((scb[0x13] & 4) != 0) {
        scb = (u8 *)1;
    } else {
        scb = (u8 *)0;
    }
    fn_8020931C(0, 0);
    return (s32)scb;
}
  
void fn_80209854(u32 arg0) {
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
    mode = (arg0 & 1) << 2;

    interrupts = OSDisableInterrupts();
    locked = (volatile s32 *)(scb + 0x48);

    if (*locked != 0) {
        OSRestoreInterrupts(interrupts);
        scb = NULL;
    } else {
        *(u32 *)(scb + 0x44) = interrupts;
        *locked = 1;
    }

    flags = scb[0x13];
    if (mode == (flags & 4)) {
        fn_8020931C(0, 0);
    } else {
        scb[0x13] = flags & ~4;
        flags = scb[0x13];
        scb[0x13] = flags | mode;
        fn_8020931C(1, 0);
    }
}
#pragma optimization_level reset

#pragma scheduling off

#pragma scheduling reset
