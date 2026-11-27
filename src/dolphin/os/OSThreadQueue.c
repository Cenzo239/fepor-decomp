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

void __OSReschedule(void) {
    extern s32 RunQueueHint_8036851C;
    if (RunQueueHint_8036851C != 0) {
        SelectThread_8020A2C4(0);
    }
}

void OS_YieldThread(void) {
    BOOL OSDisableInterrupts(void);
    BOOL OSRestoreInterrupts(BOOL level);
    BOOL enabled;

    enabled = OSDisableInterrupts();
    SelectThread_8020A2C4(1);
    OSRestoreInterrupts(enabled);
}

s32 fn_8020A558(void *arg0, void *entry, void *arg, void *stack, u32 size, s32 priority, u16 attr) {
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
void fn_8020A740(void*);
void fn_80205B7C(void*,void*,void*);
extern u32 __OSErrorTable[];
extern u32 lbl_80366F38;
u32 pad[2];
u8 *thread = arg0;
u32 *sp;
s32 enabled;
u32 i;
u8 **p;
u8 *tail;
void *callThread;
if (priority < 0 || priority > 31) return 0;
*(u16 *)(thread + 0x2C8) = 1;
*(u16 *)(thread + 0x2CA) = attr & 1;
sp = (u32 *)((u32)stack & ~7);
*(s32 *)(thread + 0x2D4) = priority;
callThread = thread;
*(s32 *)(thread + 0x2D0) = priority;
*(s32 *)(thread + 0x2CC) = 1;
*(s32 *)(thread + 0x2D8) = -1;
*(u32 *)(thread + 0x2F0) = 0;
*(u32 *)(thread + 0x2EC) = 0;
*(u32 *)(thread + 0x2E8) = 0;
*(u32 *)(thread + 0x2F8) = 0;
*(u32 *)(thread + 0x2F4) = 0;
sp[-2] = 0;
sp[-1] = 0;
fn_80205B7C(callThread, entry, sp - 2);
*(void **)(thread + 0x84) = fn_8020A740;
*(void **)(thread + 0xC) = arg;
*(void **)(thread + 0x304) = stack;
*(u8 **)(thread + 0x308) = (u8 *)stack - size;
**(u32 **)(thread + 0x308) = 0xDEADBABE;
*(u32 *)(thread + 0x30C) = 0;
*(u32 *)(thread + 0x310) = 0;
*(u32 *)(thread + 0x314) = 0;
enabled = OSDisableInterrupts();
if (__OSErrorTable[16]) {
*(u32 *)(thread + 0x19C) |= 0x900;
*(u16 *)(thread + 0x1A2) |= 1;
*(u32 *)(thread + 0x194) = (lbl_80366F38 & 0xF8) | 4;
for (i = 0; i < 32; i++) {
*(u64 *)(thread + 0x90 + i * 8) = ~(u64)0;
*(u64 *)(thread + 0x1C8 + i * 8) = ~(u64)0;
}
}
p = (u8 **)0x800000DC;
tail = *++p;
if (!tail) {
*(u8 **)0x800000DC = thread;
} else {
*(u8 **)(tail + 0x2FC) = thread;
}
*(u8 **)(thread + 0x300) = tail;
*(u32 *)(thread + 0x2FC) = 0;
*p = thread;
OSRestoreInterrupts(enabled);
return 1;
(void)pad;
}

#pragma opt_lifetimes off
void fn_8020A740(void *arg0) {
s32 OSDisableInterrupts(void); void OSRestoreInterrupts(s32);
void fn_802086A0(void*); void fn_8020AEC4(void*); void SelectThread_8020A2C4(s32);
u8 *thread; s32 enabled; u8 *prev; u8 *next;
enabled=OSDisableInterrupts(); thread=*(u8**)0x800000e4;
OSClearContext((OSContext*)thread);
if (*(u16*)(thread+0x2ca)&1) {
prev=*(u8**)(thread+0x300); next=*(u8**)(thread+0x2fc);
if(next==0) *(u8**)0x800000e0=prev; else *(u8**)(next+0x300)=prev;
if(prev==0) *(u8**)0x800000dc=next; else *(u8**)(prev+0x2fc)=next;
*(u16*)(thread+0x2c8)=0;
} else { *(u16*)(thread+0x2c8)=8; *(void**)(thread+0x2d8)=arg0; }
fn_802086A0(thread); fn_8020AEC4(thread+0x2e8);
RunQueueHint_8036851C=1;
__OSReschedule();
OSRestoreInterrupts(enabled);
}
#pragma opt_lifetimes reset
void fn_8020A824(void *arg0) {
typedef struct Thread Thread;
typedef struct Queue {Thread *head,*tail;} Queue;
struct Thread {u8 pad[0x2C8]; u16 state,attr; s32 suspend,priority,basePriority; void *value; Queue *queue; Thread *next,*prev; Queue join; void *mutex; u8 pad2[8]; Thread *activeNext,*activePrev;};
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
void OSClearContext(void*);
void fn_8020A060(void*);
s32 fn_8020A0C8(void*);
void *fn_8020A104(void*,s32);
void fn_802086A0(void*);
void fn_8020AEC4(void*);
void SelectThread_8020A2C4(s32);
extern s32 RunQueueHint_8036851C;
s32 enabled;
Thread *thread=arg0;
Thread *owner,*next,*prev;
s32 priority;
enabled=OSDisableInterrupts();
switch(thread->state) {
case 1: if(thread->suspend<=0) fn_8020A060(thread); break;
case 2: RunQueueHint_8036851C=1; break;
case 4:
next=thread->next; prev=thread->prev;
if(!next) thread->queue->tail=prev; else next->prev=prev;
if(!prev) thread->queue->head=next; else prev->next=next;
thread->queue=0;
if(thread->suspend<=0 && thread->mutex) {
owner=*(Thread**)((u8*)thread->mutex+8);
do {
if(owner->suspend>0) break;
priority=fn_8020A0C8(owner);
if(owner->priority==priority) break;
owner=fn_8020A104(owner,priority);
} while(owner);
}
break;
default: OSRestoreInterrupts(enabled); return;
}
OSClearContext(thread);
if(thread->attr&1) {
next=thread->activeNext; prev=thread->activePrev;
if(!next) *(Thread**)0x800000E0=prev; else next->activePrev=prev;
if(!prev) *(Thread**)0x800000DC=next; else prev->activeNext=next;
thread->state=0;
} else thread->state=8;
fn_802086A0(thread);
fn_8020AEC4(&thread->join);
if(RunQueueHint_8036851C) SelectThread_8020A2C4(0);
OSRestoreInterrupts(enabled);
}

#pragma use_lmw_stmw on
s32 fn_8020A9E0(void *arg0)
{
    typedef struct OSThread OSThread;
    typedef struct OSThreadQueue {
        OSThread *head;
        OSThread *tail;
    } OSThreadQueue;
    typedef struct OSMutexLink {
        OSThread *head;
        u8 pad[0xC];
        struct OSMutexLink *next;
    } OSMutexLink;
    struct OSThread {
        u8 pad[0x2C8];
        u16 state;
        u16 pad2C8;
        s32 suspend;
        s32 priority;
        s32 basePriority;
        u8 pad2D8[4];
        OSThreadQueue *queue;
        OSThread *next;
        OSThread *prev;
        u8 pad2E8[8];
        void *mutex;
        OSMutexLink *mutexQueue;
    };

    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void SelectThread_8020A2C4(s32);
    s32 fn_8020A0C8(OSThread *);
    OSThread *fn_8020A104(OSThread *);
    extern s32 RunQueueBits_80368518;
    extern s32 RunQueueHint_8036851C;

    OSThread *thread;
    s32 enabled;
    s32 prevSuspend;
    s32 prio;
    OSMutexLink *link;
    OSThread *t;
    OSThread *next;
    OSThread *prev;
    OSThread *cur;
    s32 eff;
    s32 pad1;
    s32 pad2;

    thread = (OSThread *)arg0;

    enabled = OSDisableInterrupts();
    prevSuspend = thread->suspend;
    thread->suspend = prevSuspend - 1;
    pad1 = prevSuspend;
    pad2 = enabled;

    if (thread->suspend < 0) {
        thread->suspend = 0;
    } else if (thread->suspend == 0) {
        switch (thread->state) {
        case 1:
            prio = thread->basePriority;
            link = thread->mutexQueue;
            while (link != NULL) {
                t = link->head;
                if (t != NULL) {
                    if (prio > t->priority) {
                        prio = t->priority;
                    }
                }
                link = link->next;
            }
            thread->priority = prio;
            thread->queue = &((OSThreadQueue *)RunQueue_80339478)[thread->priority];
            prev = thread->queue->tail;
            if (prev == NULL) {
                thread->queue->head = thread;
            } else {
                prev->next = thread;
            }
            thread->prev = prev;
            thread->next = NULL;
            thread->queue->tail = thread;
            RunQueueBits_80368518 |= 1 << (31 - thread->priority);
            RunQueueHint_8036851C = 1;
            break;

        case 4:
            next = thread->next;
            prev = thread->prev;
            if (next == NULL) {
                thread->queue->tail = prev;
            } else {
                next->prev = prev;
            }
            if (prev == NULL) {
                thread->queue->head = next;
            } else {
                prev->next = next;
            }

            prio = thread->basePriority;
            link = thread->mutexQueue;
            while (link != NULL) {
                t = link->head;
                if (t != NULL) {
                    if (prio > t->priority) {
                        prio = t->priority;
                    }
                }
                link = link->next;
            }
            thread->priority = prio;

            cur = thread->queue->head;
            while (cur != NULL && cur->priority <= thread->priority) {
                cur = cur->next;
            }
            if (cur == NULL) {
                prev = thread->queue->tail;
                if (prev == NULL) {
                    thread->queue->head = thread;
                } else {
                    prev->next = thread;
                }
                thread->prev = prev;
                thread->next = NULL;
                thread->queue->tail = thread;
            } else {
                thread->next = cur;
                prev = cur->prev;
                cur->prev = thread;
                thread->prev = prev;
                if (prev == NULL) {
                    thread->queue->head = thread;
                } else {
                    prev->next = thread;
                }
            }

            if (thread->mutex != NULL) {
                thread = *(OSThread **)((u8 *)thread->mutex + 8);
                for (;;) {
                    if (thread->suspend > 0) {
                        break;
                    }
                    eff = fn_8020A0C8(thread);
                    if (thread->priority == eff) {
                        break;
                    }
                    thread = fn_8020A104(thread);
                    if (thread == NULL) {
                        break;
                    }
                }
            }
            break;
        }

        if (RunQueueHint_8036851C != 0) {
            SelectThread_8020A2C4(0);
        }
    }

    OSRestoreInterrupts(enabled);
    return prevSuspend;
}

s32 fn_8020AC68(void *arg0) {
    typedef struct Thread Thread;
    typedef struct Queue { Thread *head, *tail; } Queue;
    struct Thread {
        u8 pad[0x2C8];
        u16 state, attr;
        s32 suspend, priority, basePriority;
        void *value;
        Queue *queue;
        Thread *next, *prev;
        u8 pad2[8];
        void *mutex;
    };
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void SelectThread_8020A2C4(s32);
    void fn_8020A060(void *);
    s32 fn_8020A0C8(void *);
    void *fn_8020A104(void *, s32);
    Thread *thread = arg0;
    s32 enabled;
    s32 previous;
    Thread *next, *prev, *tail;
    Queue *queue;
    void *mutex;
    s32 priority;
    enabled = OSDisableInterrupts();
    previous = thread->suspend++;
    if (previous == 0) {
        switch (thread->state) {
        case 3: break;
        case 2:
            RunQueueHint_8036851C = 1;
            thread->state = 1;
            break;
        case 1:
            fn_8020A060(thread);
            break;
        case 4:
            next = thread->next;
            prev = thread->prev;
            if (next == 0) thread->queue->tail = prev;
            else next->prev = prev;
            if (prev == 0) thread->queue->head = next;
            else prev->next = next;
            thread->priority = 32;
            tail = thread->queue->tail;
            if (tail == 0) thread->queue->head = thread;
            else tail->next = thread;
            thread->prev = tail;
            thread->next = 0;
            thread->queue->tail = thread;
            mutex = thread->mutex;
            if (mutex != 0) {
                thread = M2C_FIELD(mutex, void **, 8);
                do {
                    if (thread->suspend > 0) break;
                    priority = fn_8020A0C8(thread);
                    if (thread->priority == priority) break;
                    thread = fn_8020A104(thread, priority);
                } while (thread != 0);
            }
            break;
        }
        if (RunQueueHint_8036851C != 0) SelectThread_8020A2C4(0);
    }
    OSRestoreInterrupts(enabled);
    return previous;
}

void OSSleepThread(void *arg0) {
s32 OSDisableInterrupts(void); void OSRestoreInterrupts(s32);
s32 enabled; u8 *thread; u8 *cur; u8 *prev; u8 **queue=(u8**)arg0;
enabled=OSDisableInterrupts(); thread=*(u8**)0x800000e4;
*(u16*)(thread+0x2c8)=4; *(void**)(thread+0x2dc)=arg0;
cur=queue[0];
while(cur && *(s32*)(cur+0x2d0)<=*(s32*)(thread+0x2d0)) cur=*(u8**)(cur+0x2e0);
if(cur==0) {
prev=queue[1]; if(prev==0) queue[0]=thread; else *(u8**)(prev+0x2e0)=thread;
*(u8**)(thread+0x2e4)=prev; *(u8**)(thread+0x2e0)=0; queue[1]=thread;
} else {
*(u8**)(thread+0x2e0)=cur; prev=*(u8**)(cur+0x2e4); *(u8**)(cur+0x2e4)=thread;
*(u8**)(thread+0x2e4)=prev; if(prev==0) queue[0]=thread; else *(u8**)(prev+0x2e0)=thread;
}
RunQueueHint_8036851C=1; __OSReschedule(); OSRestoreInterrupts(enabled);
}

void fn_8020AEC4(void *arg0) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void SelectThread_8020A2C4(s32);
    extern void *RunQueue_80339478[];
    extern s32 RunQueueBits_80368518;
    extern s32 RunQueueHint_8036851C;

    typedef struct OSThread OSThread;
    typedef struct OSThreadQueue {
        OSThread *head;
        OSThread *tail;
    } OSThreadQueue;
    struct OSThread {
        u8 pad[0x2C8];
        u16 state;
        u16 pad2CA;
        s32 suspend;
        s32 priority;
        s32 basePriority;
        u8 pad2D8[4];
        OSThreadQueue *queue;
        OSThread *next;
        OSThread *prev;
    };

    OSThreadQueue *wakeQueue;
    s32 enabled;
    OSThread *thread;
    OSThread *next;
    OSThread *prev;

    enabled = OSDisableInterrupts();
    wakeQueue = (OSThreadQueue *)arg0;
    while ((thread = wakeQueue->head) != NULL) {
        next = thread->next;
        if (next == NULL) {
            wakeQueue->tail = NULL;
        } else {
            next->prev = NULL;
        }
        wakeQueue->head = next;
        thread->state = 1;
        if (thread->suspend <= 0) {
            thread->queue = &((OSThreadQueue *)RunQueue_80339478)[thread->priority];
            prev = thread->queue->tail;
            if (prev == NULL) {
                thread->queue->head = thread;
            } else {
                prev->next = thread;
            }
            thread->prev = prev;
            thread->next = NULL;
            thread->queue->tail = thread;
            *(volatile s32 *)&RunQueueBits_80368518 =
                RunQueueBits_80368518 | (1 << (31 - thread->priority));
            *(volatile s32 *)&RunQueueHint_8036851C = 1;
        }
    }
    if (RunQueueHint_8036851C != 0) {
        SelectThread_8020A2C4(0);
    }
    OSRestoreInterrupts(enabled);
}
