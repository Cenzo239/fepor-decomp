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

void cb(s32 arg0, void *arg1) {
    extern u8 *bb2_803685F4;
    extern void *idTmp_803685F8;
    extern s32 lbl_803685F0;
    void DVDReset(void);
    if (arg0 > 0) {
        switch (lbl_803685F0) {
        case 0:
            lbl_803685F0=1;
            fn_8020EBEC(arg1,(u32)bb2_803685F4,32,0x420,(u32)cb);
            break;
        case 1:
            lbl_803685F0=2;
            fn_8020EBEC(arg1,*(u32 *)(bb2_803685F4+0x10),(*(u32 *)(bb2_803685F4+8)+31)&~31,*(u32 *)(bb2_803685F4+4),(u32)cb);
            break;
        }
    } else {
        if (arg0 == -1) return;
        if (arg0 == -4) {
            lbl_803685F0=0;
            DVDReset();
            DVDReadDiskID(arg1,idTmp_803685F8,(void *)cb);
        }
    }
}

void __fstLoad(void) {
void *OSGetArenaHi(void);
void OSSetArenaHi(void *);
void DVDReset(void);
void OSReport(char *, ...);
void *memcpy(void *, const void *, u32);
extern u8 *bb2_803685F4;
extern void *idTmp_803685F8;
static u8 block[48];
u8 idBuffer[64];
u8 *id;
u8 *boot;
OSGetArenaHi();
idTmp_803685F8 = (void *)(((u32)idBuffer + 31) & ~31);
bb2_803685F4 = (u8 *)(((u32)bb2Buf_80339FF8 + 31) & ~31);
DVDReset();
DVDReadDiskID(block,idTmp_803685F8,(void *)cb);
while (DVDGetDriveStatus() != 0) {}
id=(u8 *)0x80000000;
boot=(u8 *)0x80000000;
*(u32 *)(boot+0x38)=*(u32 *)(bb2_803685F4+0x10);
*(u32 *)(boot+0x3C)=*(u32 *)(bb2_803685F4+0xC);
memcpy(id,idTmp_803685F8,32);
OSReport("\n");
OSReport("  Game Name ... %c%c%c%c\n",(s8)id[0],(s8)id[1],(s8)id[2],(s8)id[3]);
OSReport("  Company ..... %c%c\n",(s8)id[4],(s8)id[5]);
OSReport("  Disk # ...... %d\n",id[6]);
OSReport("  Game ver .... %d\n",id[7]);
OSReport("  Streaming ... %s\n",boot[8] == 0 ? "OFF" : "ON");
OSReport("\n");
OSSetArenaHi(*(void **)(bb2_803685F4+0x10));
}

#pragma use_lmw_stmw on
static inline u32 fn_8020FD50_cntlzd(u64 bit) {
    u32 hi = (u32)(bit >> 32);
    u32 lo = (u32)(bit & 0xFFFFFFFF);
    u32 value = __cntlzw(hi);
    if (value < 32) {
        return value;
    }
    return 32 + __cntlzw(lo);
}
