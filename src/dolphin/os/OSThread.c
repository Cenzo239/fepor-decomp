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
typedef struct OSThread OSThread;
typedef struct OSThreadQueue { OSThread *head, *tail; } OSThreadQueue;
struct OSThread {
    u8 context[0x1A2];
    u16 contextState;
    u8 pad1A4[0x124];
    u16 state;
    u16 attr;
    s32 suspend;
    s32 priority;
    s32 base;
    void *value;
    OSThreadQueue *queue;
    OSThread *next, *prev;
};
#pragma opt_common_subs on
static inline void PopThread(OSThreadQueue *queue, OSThread **out) {
    OSThread *thread = queue->head;
    OSThread *next = thread->next;
    *out = thread;
    if (next == NULL) queue->tail = NULL;
    else next->prev = NULL;
    queue->head = next;
}
#pragma opt_common_subs reset
extern void* RunQueue_80339478[];
extern volatile u32 RunQueueBits_80368518;
extern volatile s32 RunQueueHint_8036851C;



#pragma opt_common_subs off
#pragma peephole on
void *SelectThread_8020A2C4(s32 arg0) {
    OSContext *fn_802059EC(void);
    u32 fn_802059F8(void *);
    void OSSetCurrentContext(void *);
    void OSClearContext(void *);
    void OSLoadContext(void *);
    void OSEnableInterrupts(void);
    void OSDisableInterrupts(void);
    extern s32 Reschedule_80368520;
    extern volatile u32 RunQueueBits_80368518;
    extern volatile s32 RunQueueHint_8036851C;
    extern void *RunQueue_80339478[];
    extern void (*SwitchThreadCallback_80366F50)(void *, void *);
    void **queue;
    OSThread *thread;
    OSThread *next;
    OSThread *tail;
    OSThread *pred;
    s32 prio;
    OSThreadQueue *q;
        OSContext *cur; OSContext *context;

    queue = RunQueue_80339478;
    if (Reschedule_80368520 > 0) {
        return NULL;
    }
    cur = fn_802059EC();
    thread = *(OSThread **)0x800000E4;
    context = (OSContext *)thread;
    if (cur != (OSContext *)thread) {
        return NULL;
    }
    if (thread != NULL) {
        if (thread->state == 2) {
            if (arg0 == 0) {
                s32 bits = __cntlzw((u32)RunQueueBits_80368518);
                if (thread->priority <= bits) {
                    return NULL;
                }
            }
            thread->state = 1;
            thread->queue = (OSThreadQueue *)((u8 *)queue + (thread->priority * 8));
            q = thread->queue;
            tail = q->tail;
            if (tail == NULL) {
                q->head = thread;
            } else {
                tail->next = thread;
            }
            thread->prev = tail;
            thread->next = NULL;
            thread->queue->tail = thread;
            {
                s32 one = 1;
                RunQueueBits_80368518 |= one << (0x1F - thread->priority);
                RunQueueHint_8036851C = one;
            }
        }
        if ((thread->contextState & 2) == 0) {
            if (fn_802059F8(context) != 0) {
                return NULL;
            }
        }
    }
    if ((u32)RunQueueBits_80368518 == 0) {
        SwitchThreadCallback_80366F50(*(void **)0x800000E4, NULL);
        *(void **)0x800000E4 = NULL;
        OSSetCurrentContext((u8 *)queue + 0x730);
        do {
            OSEnableInterrupts();
            while ((u32)RunQueueBits_80368518 == 0) {
            }
            OSDisableInterrupts();
        } while ((u32)RunQueueBits_80368518 == 0);
        OSClearContext((u8 *)queue + 0x730);
    }
    RunQueueHint_8036851C = 0;
    prio = __cntlzw((u32)RunQueueBits_80368518);
    q = (OSThreadQueue *)((u8 *)queue + (prio * 8));
    PopThread(q, &next);
    if (q->head == NULL) {
        s32 one = 1;
        RunQueueBits_80368518 &= ~(one << (0x1F - prio));
    }
    next->queue = NULL;
    next->state = 2;
    SwitchThreadCallback_80366F50(*(void **)0x800000E4, next);
    *(void **)0x800000E4 = next;
    OSSetCurrentContext(next);
    OSLoadContext(next);
    return next;
}
#pragma opt_common_subs reset
#pragma peephole reset
