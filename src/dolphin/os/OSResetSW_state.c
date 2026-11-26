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

extern s64 lbl_80368510;
extern s32 lbl_803684FC;
extern s32 lbl_80368500;
extern s64 lbl_80368508;
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

u8 __OSResetTimer : 0x800030E3;
u32 __OSBusClock : 0x800000F8;

#define OS_TIMER_CLOCK (__OSBusClock / 4)

s32 fn_80208D18(void) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s64 __OSGetSystemTime(void);
    s32 enabled = OSDisableInterrupts();
    s32 state;
    u32 reg;
    s64 now;

    now = __OSGetSystemTime();

    reg = *(volatile u32 *)0xCC003000;
    if (!(reg & 0x00010000)) {
        if (!lbl_803684FC) {
            lbl_803684FC = 1;
            state = lbl_80368508 ? 1 : 0;
            lbl_80368510 = now;
        } else {
            state = lbl_80368508 || (100 * (OS_TIMER_CLOCK / 125000) / 8 < now - lbl_80368510) ? 1 : 0;
        }
    } else if (lbl_803684FC) {
        lbl_803684FC = 0;
        state = lbl_80368500;
        if (state) {
            lbl_80368508 = now;
        } else {
            lbl_80368508 = 0;
        }
    } else if (lbl_80368508 && (now - lbl_80368508 < (40 * (OS_TIMER_CLOCK / 1000)))) {
        state = 1;
    } else {
        state = 0;
        lbl_80368508 = 0;
    }

    lbl_80368500 = state;

    if (__OSResetTimer & 0x1F) {
        s64 fire = (__OSResetTimer & 0x1F) * 60;
        fire = __OSStartTime + (fire * OS_TIMER_CLOCK);
        if (fire < now) {
            now -= fire;
            now = (now / OS_TIMER_CLOCK) / 2;
            if ((now & 1) == 0) {
                state = 1;
            } else {
                state = 0;
            }
        }
    }

    OSRestoreInterrupts(enabled);
    return state;
}
