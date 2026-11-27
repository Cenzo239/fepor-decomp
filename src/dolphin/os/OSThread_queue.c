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

s32 fn_8020931C(s32 commit, s32 offset);

void fn_8020A060(void *arg0) {
    extern s32 RunQueueBits_80368518;
    void *temp_r4;
    void *temp_r5;
    void *temp_r6;

    temp_r5 = M2C_FIELD(arg0, void **, 0x2DC);
    temp_r4 = M2C_FIELD(arg0, void **, 0x2E0);
    temp_r6 = M2C_FIELD(arg0, void **, 0x2E4);
    if (temp_r4 == NULL) {
        M2C_FIELD(temp_r5, void **, 4) = temp_r6;
    } else {
        M2C_FIELD(temp_r4, void **, 0x2E4) = temp_r6;
    }
    if (temp_r6 == NULL) {
        M2C_FIELD(temp_r5, void **, 0) = temp_r4;
    } else {
        M2C_FIELD(temp_r6, void **, 0x2E0) = temp_r4;
    }
    if ((void *) M2C_FIELD(temp_r5, void **, 0) == NULL) {
        RunQueueBits_80368518 &= ~(1 << (0x1F - M2C_FIELD(arg0, s32 *, 0x2D0)));
    }
    M2C_FIELD(arg0, void **, 0x2DC) = NULL;
}

s32 fn_8020A0C8(void *arg0)
{
  s32 value;
  void *thread;
  s32 priority = *((s32 *) (((s8 *) arg0) + 0x2D4));
  void *node = *((void **) (((s8 *) arg0) + 0x2F4));
  while (node != NULL)
  {
    thread = *((void **) node);
    if (NULL != thread)
    {
      value = *((s32 *) (((s8 *) thread) + 0x2D0));
      if (value < priority)
      {
        priority = value;
      }
    }
    node = *((void **) (((s8 *) node) + 0x10));
  }

  return priority;
}

#pragma optimization_level 3
void *fn_8020A104(void *thread,s32 priority) {
void fn_8020A060();
void *next,*prev,*tail,*node,*queue;
switch((s32)M2C_FIELD(thread,u16*,0x2c8)){
case 1:
fn_8020A060(thread);
M2C_FIELD(thread,s32*,0x2d0)=priority;
M2C_FIELD(thread,void**,0x2dc)=(u8*)RunQueue_80339478+M2C_FIELD(thread,s32*,0x2d0)*8;
queue=M2C_FIELD(thread,void**,0x2dc);
tail=M2C_FIELD(queue,void**,4);
if(!tail)M2C_FIELD(queue,void**,0)=thread;else M2C_FIELD(tail,void**,0x2e0)=thread;
M2C_FIELD(thread,void**,0x2e4)=tail;
M2C_FIELD(thread,void**,0x2e0)=0;
M2C_FIELD(M2C_FIELD(thread,void**,0x2dc),void**,4)=thread;
RunQueueBits_80368518|=1<<(31-M2C_FIELD(thread,s32*,0x2d0));
RunQueueHint_8036851C=1;
break;
case 4:
next=M2C_FIELD(thread,void**,0x2e0);prev=M2C_FIELD(thread,void**,0x2e4);
if(!next)M2C_FIELD(M2C_FIELD(thread,void**,0x2dc),void**,4)=prev;else M2C_FIELD(next,void**,0x2e4)=prev;
if(!prev)M2C_FIELD(M2C_FIELD(thread,void**,0x2dc),void**,0)=next;else M2C_FIELD(prev,void**,0x2e0)=next;
M2C_FIELD(thread,s32*,0x2d0)=priority;
queue=M2C_FIELD(thread,void**,0x2dc);
for(node=M2C_FIELD(queue,void**,0);node && M2C_FIELD(node,s32*,0x2d0)<=M2C_FIELD(thread,s32*,0x2d0);node=M2C_FIELD(node,void**,0x2e0)){}
if(!node){
tail=M2C_FIELD(queue,void**,4);
if(!tail)M2C_FIELD(queue,void**,0)=thread;else M2C_FIELD(tail,void**,0x2e0)=thread;
M2C_FIELD(thread,void**,0x2e4)=tail;M2C_FIELD(thread,void**,0x2e0)=0;
M2C_FIELD(M2C_FIELD(thread,void**,0x2dc),void**,4)=thread;
}else{
M2C_FIELD(thread,void**,0x2e0)=node;
prev=M2C_FIELD(node,void**,0x2e4);
M2C_FIELD(node,void**,0x2e4)=thread;
M2C_FIELD(thread,void**,0x2e4)=prev;
if(!prev)M2C_FIELD(M2C_FIELD(thread,void**,0x2dc),void**,0)=thread;else M2C_FIELD(prev,void**,0x2e0)=thread;
}
node=M2C_FIELD(thread,void**,0x2f0);
if(node)return M2C_FIELD(node,void**,8);
break;
case 2:RunQueueHint_8036851C=1;M2C_FIELD(thread,s32*,0x2d0)=priority;break;
case 3:default:break;
}
return 0;
}
