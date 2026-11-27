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
        s32 second = fn_80230CE0(*path++);
        if (second != first) return FALSE;
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

void __DVDFSInit(void) {
extern void *BootInfo_80368578;
extern u32 MaxEntryNum_80368584;
FSTEntry *fst;
BootInfo_80368578=(void*)0x80000000;
FstStart_8036857C=*(FSTEntry**)0x80000038;
fst=FstStart_8036857C;
if(fst) {
MaxEntryNum_80368584=fst->nextEntryOrLength;
FstStringStart_80368580=(char*)(fst+MaxEntryNum_80368584);
}
}

#pragma push
#pragma optimization_level 3
u32 fn_8020C3E0(char *path) {
    extern u32 __DVDLongFileNameFlag;
    extern char lbl_8029CEE8[];
    extern s32 lbl_80366F60;
    void OSPanic(void *, s32, char *, ...);

    s32 more;
    u32 parent;
    char *end;
    u32 length;
    u32 entry;
    char *original;
    char *extension;
    s32 invalid;
    s32 dotted;
    char *name;
    s32 equal;

    original = path;
    entry = (u32)currentDirectory;

    for (;;) {
        if (*path == 0) {
            return entry;
        }
        if (*path == '/') {
            entry = 0;
            path++;
            continue;
        }
        if (*path == '.') {
            if (path[1] == '.') {
                if (path[2] == '/') {
                    entry = parentDir(entry);
                    path += 3;
                    continue;
                }
                if (path[2] == 0) {
                    return parentDir(entry);
                }
            } else {
                if (path[1] == '/') {
                    path += 2;
                    continue;
                }
                if (path[1] == 0) {
                    return entry;
                }
            }
        }
        if (!__DVDLongFileNameFlag) {
            end = path;
            dotted = 0;
            invalid = 0;
            while (*end && *end != '/') {
                if (*end == '.') {
                    if (end - path > 8 || dotted == 1) {
                        invalid = 1;
                        break;
                    }
                    extension = end + 1;
                    dotted = 1;
                } else if (*end == ' ') {
                    invalid = 1;
                }
                end++;
            }
            if (dotted == 1 && end - extension > 3) {
                invalid = 1;
            }
            if (invalid) {
                OSPanic(&lbl_80366F60, 0x183, lbl_8029CEE8, original);
            }
        } else {
            for (end = path; *end && *end != '/'; end++) {
            }
        }
        more = (*end == 0) ? 0 : 1;
        parent = entry;
        length = end - path;
        for (entry++; entry < FstStart_8036857C[parent].nextEntryOrLength;
             entry = entryIsDir(entry) ? FstStart_8036857C[entry].nextEntryOrLength : entry + 1) {
            if (entryIsDir(entry) || more != 1) {
                name = FstStringStart_80368580 + stringOff(entry);
                equal = DVDComparePathComponent(path, name);
                if (equal == 1) {
                    goto found;
                }
            }
        }
        return -1;
    found:
        if (!more) {
            return entry;
        }
        path += length;
        path++;
    }
}
#pragma pop
s32 fn_8020C6D4(char *path, void *info) {
BOOL DVDGetCurrentDir(char *, u32);
void OSReport(char *, ...);
extern char lbl_8029CFB0[];
char currentPath[0x80];
s32 entry = fn_8020C3E0(path);
if (entry < 0) {
DVDGetCurrentDir(currentPath, 0x80);
OSReport(lbl_8029CFB0, path, currentPath);
return 0;
}
if (entryIsDir(entry)) return 0;
*(u32 *)((u8 *)info+0x30)=FstStart_8036857C[entry].parentOrPosition;
*(u32 *)((u8 *)info+0x34)=FstStart_8036857C[entry].nextEntryOrLength;
*(u32 *)((u8 *)info+0x38)=0;
*(u32 *)((u8 *)info+0xC)=0;
return 1;
}

s32 fn_8020C79C(void) {
    M2C_UNK fn_8020F334();
    fn_8020F334();
    return 1;
}

/* Recursively write "/parent/.../name" for an FST entry into path; returns length used. */
u32 entryToPath(u32 entry, char *path, u32 maxlen) {
    char *name;
    u32 loc;

    if (entry == 0) {
        return 0;
    }

    name = FstStringStart_80368580 + stringOff(entry);

    loc = entryToPath(parentDir(entry), path, maxlen);

    if (loc == maxlen) {
        return loc;
    }

    *(path + loc++) = '/';

    loc += myStrncpy(path + loc, name, maxlen - loc);

    return loc;
}

BOOL DVDConvertEntrynumToPath(s32 entrynum, char *path, u32 maxlen) {
    /* Build an absolute DVD path for entrynum; append '/' for directories. FALSE if truncated. */
    u32 loc;

    loc = entryToPath((u32)entrynum, path, maxlen);

    if (loc == maxlen) {
        path[maxlen - 1] = '\0';
        return FALSE;
    }

    if (entryIsDir(entrynum)) {
        if (loc == maxlen - 1) {
            path[loc] = '\0';
            return FALSE;
        }
        path[loc++] = '/';
    }

    path[loc] = '\0';
    return TRUE;
}

/* Build an absolute path for the current DVD directory into path. */
BOOL DVDGetCurrentDir(char *path, u32 maxlen) {
    return DVDConvertEntrynumToPath((s32)currentDirectory, path, maxlen);
}

#pragma use_lmw_stmw on
s32 fn_8020CB38(void *arg0, s32 arg1, s32 arg2, s32 arg3, void (*arg4)(s32, void *), s32 arg5) {
  void OSPanic(void *, s32, char *, ...);
  s32 DVDReadAbsAsyncPrio(void *, s32, s32, s32, void (*)(s32, void *), s32);
  void fn_8020CBF8(s32, void *);
  extern s32 lbl_80366F60;
  s32 temp_r4;

  if ((arg3 < 0) || ((u32)arg3 > *(u32 *)((u8 *)arg0 + 0x34))) {
    OSPanic(&lbl_80366F60, 0x2EE, lbl_8029CFE8);
  }
  temp_r4 = arg3 + arg2;
  if ((temp_r4 < 0) || ((u32)temp_r4 >= *(u32 *)((u8 *)arg0 + 0x34) + 0x20)) {
    OSPanic(&lbl_80366F60, 0x2F4, lbl_8029CFE8);
  }
  *(void (**)(s32, void *))((u8 *)arg0 + 0x38) = arg4;
  DVDReadAbsAsyncPrio(arg0, arg1, arg2, *(s32 *)((u8 *)arg0 + 0x30) + arg3, fn_8020CBF8, arg5);
  return 1;
}
#pragma use_lmw_stmw reset
void fn_8020CBF8(s32 result, void *arg1) { if (*(void (**)(s32, void *))((char *)arg1+0x38) != NULL) (*(void (**)(s32, void *))((char *)arg1+0x38))(result,arg1); }

s32 fn_8020CC28(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void OSPanic(void *, s32, char *, ...);
    void fn_8020CD40(void);
    s32 DVDReadAbsAsyncPrio(void *, s32, s32, s32, void (*)(void), s32);
    void OSSleepThread(void *);
    extern void *__DVDThreadQueue;
    extern char lbl_8029D01C[];
    s32 state;
    s32 interrupts;
    s32 end;
    void *block;
    s32 result;
    if (arg3 < 0 || (u32)arg3 > *(u32 *)((u8 *)arg0 + 0x34))
        OSPanic(&lbl_80366F60, 0x334, lbl_8029D01C);
    end = arg3 + arg2;
    if (end < 0 || (u32)end >= *(u32 *)((u8 *)arg0 + 0x34) + 0x20)
        OSPanic(&lbl_80366F60, 0x33A, lbl_8029D01C);
    block = arg0;
    result = DVDReadAbsAsyncPrio(block, arg1, arg2, *(u32 *)((u8 *)arg0+0x30)+arg3, fn_8020CD40, arg4);
    if (result == 0)
        return -1;
    interrupts = OSDisableInterrupts();
    for (;;) {
        state = ((DVDReadyCommand *)arg0)->state;
        if (state == 0) { result = *(s32 *)((u8 *)arg0+0x20); break; }
        if (state == -1) { result = -1; break; }
        if (state == 10) { result = -3; break; }
        OSSleepThread(&__DVDThreadQueue);
    }
    OSRestoreInterrupts(interrupts);
    return result;
}

void fn_8020CD40(void) {
    extern void* __DVDThreadQueue;
    fn_8020AEC4(&__DVDThreadQueue);
}

s32 fn_8020CD64(char *path, void *dir) {
    BOOL DVDConvertEntrynumToPath(s32, char *, u32);
    void OSReport(char *, ...);
    extern char lbl_8029D04C[];
    char currentPath[0x80];
    s32 entry = fn_8020C3E0(path);
    if (entry < 0) {
        DVDConvertEntrynumToPath(currentDirectory, currentPath, 0x80);
        OSReport(lbl_8029D04C, path, currentPath);
        return 0;
    }
    if (!entryIsDir(entry)) return 0;
    *(s32 *)dir = entry;
    *(s32 *)((u8 *)dir + 4) = entry + 1;
    *(u32 *)((u8 *)dir + 8) = FstStart_8036857C[entry].nextEntryOrLength;
    return 1;
}

s32 fn_8020CE24(void *arg0, void *arg1) {
    u8 *dir;
    u8 *entry;
    u32 loc;
    u32 next;

    dir = (u8 *)arg0;
    entry = (u8 *)arg1;

    loc = *(u32 *)(dir + 4);

    if (loc <= *(u32 *)dir || *(u32 *)(dir + 8) <= loc) {
        return 0;
    }

    *(u32 *)entry = loc;
    *(u32 *)(entry + 4) = entryIsDir(loc);
    *(char **)(entry + 8) =
        FstStringStart_80368580 + stringOff(loc);

    if (entryIsDir(loc)) {
        next = FstStart_8036857C[loc].nextEntryOrLength;
    } else {
        next = loc + 1;
    }
    *(u32 *)(dir + 4) = next;

    return 1;
}

s32 fn_8020CEC8(void) {
    return 1;
}

void fn_8020CED0(void) {

}

#pragma dont_inline on
extern volatile u32 __DIRegs_abs[16] : 0xCC006000;
void DVDInit(void) {
 extern s32 DVDInitialized_803685DC;
 extern const char *__DVDVersion;
 extern u32 MotorState_803685D8;
 extern u8 *bootInfo_803685A0;
 extern s32 FirstTimeInBootrom_803685D4;
 extern void *__DVDThreadQueue;
 extern void __DVDInitWA(void);
 extern void __DVDInterruptHandler(s16, OSContext *);
 extern void __fstLoad(void);
 void OSReport(const char*,...);
 if(DVDInitialized_803685DC==0) {
 OSRegisterVersion(__DVDVersion); DVDInitialized_803685DC=1;
 __DVDFSInit(); __DVDClearWaitingQueue(); __DVDInitWA();
 MotorState_803685D8=0; bootInfo_803685A0=(u8*)0x80000000; IDShouldBe_8036859C=bootInfo_803685A0;
 __OSSetInterruptHandler(0x15,__DVDInterruptHandler); __OSUnmaskInterrupts(0x400); OSInitThreadQueue((void*)&__DVDThreadQueue);
 __DIRegs_abs[0] = 0x2a;
 __DIRegs_abs[1] = 0;
 if(*(u32*)(bootInfo_803685A0+0x20)==0xE5207C22) { OSReport("load fst\n"); __fstLoad(); }
 else if(*(u32*)(bootInfo_803685A0+0x20)!=0x0D15EA5E) FirstTimeInBootrom_803685D4=1;
 }
}
#pragma dont_inline reset
void fn_8020CFAC(void) {
    extern void (*lbl_803685E0)(void *);
    extern u8 *bootInfo_803685A0;
    extern u8 BB2_80339F40[];
    extern s32 lbl_80366F74;
    extern char lbl_8029D0DC[];

    void OSPanic(void *, s32, char *, ...);
    s32 fn_8020BAD0(void *, u32, u32, void (*)(u32));
    void fn_8020D040(u32);

    lbl_803685E0 = (void (*)(void *))fn_8020CFAC;

    if (*(u32 *)(bootInfo_803685A0 + 0x3C) < *(u32 *)(BB2_80339F40 + 8)) {
        OSPanic(&lbl_80366F74, 0x295, lbl_8029D0DC);
    }

    fn_8020BAD0(
        *(void **)(bootInfo_803685A0 + 0x38),
        (*(u32 *)(BB2_80339F40 + 8) + 0x1F) & ~0x1F,
        *(u32 *)(BB2_80339F40 + 4),
        fn_8020D040
    );
}
#pragma global_optimizer reset
void fn_8020D040(u32 arg0) {
    void __DVDFSInit(void);
    void fn_8020D16C(void);
    void fn_8020D1A0(void);
    void stateReady(void);
    extern s32 lbl_803685CC;
    extern void *executing_80368598;
    extern u8 DummyCommandBlock_80339F80[];
    DVDReadyCommand *block;
    s32 zero;

    if (arg0 == 0x10) {
        fn_8020D16C();
        return;
    }
    if (arg0 & 1) {
        zero = 0;
        lbl_803685CC = zero;
        __DVDFSInit();
        block = (DVDReadyCommand *)executing_80368598;
        executing_80368598 = DummyCommandBlock_80339F80;
        block->state = zero;
        if (block->callback != NULL) {
            (*block->callback)(0, block);
        }
        stateReady();
        return;
    }
    fn_8020D1A0();
}

#pragma global_optimizer off
void cbForStateError(u32 arg0) {
    void fn_8020D16C(void);
    void fn_8020FAE0(void);
    void stateReady(void);

    DVDReadyCommand *block;
    void (*callback)(void *, void *);
    s32 one;

    ((DVDReadyCommand *)executing_80368598)->state = -1;

    if (arg0 == 0x10) {
        fn_8020D16C();
        return;
    }

    fn_8020FAE0();

    one = 1;
    block = (DVDReadyCommand *)executing_80368598;
    executing_80368598 = DummyCommandBlock_80339F80;
    FatalErrorFlag_803685B0 = one;

    if (block->callback != 0) {
        (*block->callback)(-1, block);
    }

    if (lbl_803685B8 != 0) {
        callback = lbl_803685BC;
        lbl_803685B8 = 0;

        if (callback != 0) {
            (*callback)(0, block);
        }
    }

    stateReady();
}
#pragma global_optimizer on
void fn_8020D16C(void) {
    M2C_UNK DVDReset();
    M2C_UNK __DVDStoreErrorCode(M2C_UNK);
    M2C_UNK cbForStateError(M2C_UNK);
    __DVDStoreErrorCode(0x01234568);
    DVDReset();
    cbForStateError(0);
}

void fn_8020D1A0(void) {
    void fn_8020BF58(void (*)(void));
    extern void fn_8020D27C(void);

    fn_8020BF58(fn_8020D27C);
}

s32 fn_8020D1C8(u32 arg0) {
    /* CategorizeError */
    extern void *executing_80368598;
    extern u32 lbl_803685C8;
    extern s32 lbl_803685CC;
    u32 temp_r4;

    if ((u32) (arg0 + 0xFFFE0000) == 0x400U) {
        lbl_803685C8 = arg0;
        return 1;
    }
    temp_r4 = arg0 & 0xFFFFFF;
    if (((u32) (temp_r4 + 0xFFFA0000) == 0x2800U) || ((u32) (temp_r4 + 0xFFFE0000) == 0x3A00U) || ((u32) (temp_r4 + 0xFFF50000) == 0x5A01U)) {
        return 0;
    }
    lbl_803685CC += 1;
    if ((s32) lbl_803685CC == 2) {
        if (temp_r4 == (u32) lbl_803685C8) {
            lbl_803685C8 = temp_r4;
            return 1;
        }
        lbl_803685C8 = temp_r4;
        return 2;
    }
    lbl_803685C8 = temp_r4;
    if (((u32) (temp_r4 + 0xFFFD0000) == 0x1100U) || (M2C_FIELD(executing_80368598, u32 *, 8) == 5U)) {
        return 2;
    }
    return 3;
}

void fn_8020D27C(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void DVDLowStopMotor(void (*)(u32));
    u32 fn_8020D1C8(u32);
    void stateReady(void);
    void fn_8020D5BC(void);
    void fn_8020BD68(u32, void *, void *);
    void fn_8020DD7C(void);
    void fn_8020DC14(void);
    extern void *executing_80368598;
    extern u32 lbl_803685B8;
    extern s32 ResumeFromHere_803685C0;
    extern u8 DummyCommandBlock_80339F80[];
    extern void (*lbl_803685BC)(void *, void *);
    extern void (*lbl_803685E0)(void *);
    extern void fn_8020D4E0(u32);

    typedef struct DVDReadyCommand {
        u8 pad[8];
        s32 command;
        s32 state;
        u8 pad10[0x18];
        void (*callback)(s32, void *);
    } DVDReadyCommand;

    DVDReadyCommand *temp_r30;
    u32 temp_r29;
    u32 temp_r28;
    u32 temp_r31;
    s32 var_r4;
    s32 var_r0;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }
    if (arg0 & 2) {
        __DVDStoreErrorCode(0x01234567);
        DVDLowStopMotor(cbForStateError);
        return;
    }
    temp_r29 = *(u32 *)0xCC006020;
    temp_r28 = temp_r29 & 0xFF000000;
    temp_r31 = fn_8020D1C8(temp_r29);
    if (temp_r31 == 1) {
        __DVDStoreErrorCode(temp_r29);
        DVDLowStopMotor(cbForStateError);
        return;
    }
    if ((u32)(temp_r31 - 2) <= 1) {
        var_r4 = 0;
    } else if (temp_r28 == 0x01000000) {
        var_r4 = 4;
    } else if (temp_r28 == 0x02000000) {
        var_r4 = 6;
    } else if (temp_r28 == 0x03000000) {
        var_r4 = 3;
    } else {
        var_r4 = 5;
    }
    if (lbl_803685B8 != 0) {
        ResumeFromHere_803685C0 = var_r4;
        lbl_803685B8 = 0;
        temp_r30 = executing_80368598;
        executing_80368598 = DummyCommandBlock_80339F80;
        temp_r30->state = 0xA;
        if (temp_r30->callback != NULL) {
            temp_r30->callback(-3, temp_r30);
        }
        if (lbl_803685BC != NULL) {
            lbl_803685BC((void *)0, temp_r30);
        }
        stateReady();
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 == 0) {
        if (temp_r31 == 2) {
            __DVDStoreErrorCode(temp_r29);
            fn_8020D5BC();
            return;
        }
        if (temp_r31 == 3) {
            if ((temp_r29 & 0xFFFFFF) == 0x031100) {
                fn_8020BD68(*(u32 *)((u8 *)executing_80368598 + 0x10), (void *)fn_8020D4E0, executing_80368598);
                return;
            }
            lbl_803685E0(executing_80368598);
            return;
        }
        if (temp_r28 == 0x01000000) {
            ((DVDReadyCommand *)executing_80368598)->state = 5;
            fn_8020DD7C();
            return;
        }
        if (temp_r28 == 0x02000000) {
            ((DVDReadyCommand *)executing_80368598)->state = 3;
            fn_8020DC14();
            return;
        }
        if (temp_r28 == 0x03000000) {
            ((DVDReadyCommand *)executing_80368598)->state = 4;
            fn_8020DD7C();
            return;
        }
        __DVDStoreErrorCode(0x01234567);
        DVDLowStopMotor(cbForStateError);
    }
}

void fn_8020D4E0(u32 arg0) {
    /* cbForUnrecoveredError */
    void DVDReset(void);
    void __DVDStoreErrorCode(u32);
    void cbForStateError(u32);
    void fn_8020BF58(void *);
    void fn_8020D5BC(void);
    void fn_8020D53C(void);

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }
    if (arg0 & 1) {
        fn_8020D5BC();
        return;
    }
    fn_8020BF58(fn_8020D53C);
}

void fn_8020D53C(u32 arg0) {
    /* cbForUnrecoveredErrorRetry */
    void DVDReset(void);
    void __DVDStoreErrorCode(u32);
    void DVDLowStopMotor(void (*)(u32));
    void cbForStateError(u32);

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (arg0 & 2) {
        __DVDStoreErrorCode(0x01234567);
        DVDLowStopMotor(cbForStateError);
        return;
    }

    __DVDStoreErrorCode(__DIRegs[8]);
    DVDLowStopMotor(cbForStateError);
}

void fn_8020D5BC(void) {
    /* stateGoToRetry */
    void DVDLowStopMotor(void (*)(void));
    extern void fn_8020D5E4(void);

    DVDLowStopMotor(fn_8020D5E4);
}

#pragma push
#pragma global_optimizer on
void fn_8020D5E4(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void DVDLowStopMotor(void (*)(u32));
    void fn_8020DD7C(void);

    extern s32 lbl_803685CC;
    extern volatile u32 CurrCommand_803685B4;
    extern s32 ResetRequired_803685D0;
    extern u32 lbl_803685B8;
    extern void *executing_80368598;
    extern u8 DummyCommandBlock_80339F80[];
    extern s32 ResumeFromHere_803685C0;
    extern void (*lbl_803685BC)(void *, void *);

    DVDReadyCommand *finished;
    s32 flag;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if ((arg0 & 2) != 0) {
        __DVDStoreErrorCode(0x01234567);
        DVDLowStopMotor(cbForStateError);
        return;
    }

    *(volatile s32 *)&lbl_803685CC = 0;

    if (CurrCommand_803685B4 == 4 || CurrCommand_803685B4 == 5 ||
        CurrCommand_803685B4 == 13 || CurrCommand_803685B4 == 15) {
        ResetRequired_803685D0 = 1;
    }

    if (lbl_803685B8 != 0) {
        *(volatile s32 *)&ResumeFromHere_803685C0 = 2;
        finished = (DVDReadyCommand *)executing_80368598;
        *(void * volatile *)&executing_80368598 = DummyCommandBlock_80339F80;
        lbl_803685B8 = 0;
        finished->state = 10;

        if (finished->callback != 0) {
            (*finished->callback)(-3, finished);
        }

        if (lbl_803685BC != 0) {
            (*lbl_803685BC)((void *)0, finished);
        }

        stateReady();
        flag = 1;
    } else {
        flag = 0;
    }

    if (flag == 0) {
        ((DVDReadyCommand *)executing_80368598)->state = 11;
        fn_8020DD7C();
    }
}
#pragma push
#pragma optimization_level 2
void fn_8020D724(void) {
    /* stateCheckID */
    extern u16 BB2_80339F40[];
    extern volatile s32 CurrCommand_803685B4;
    extern void *executing_80368598;
    extern void *IDShouldBe_8036859C;
    extern void (*lbl_803685E0)(void *);

    s32 fn_8020F9E8(u8 *, u8 *);
    s32 fn_80231944(const void *, const void *, u32);
    void fn_8020D838();
    void fn_8020D804();
    void fn_8020D90C(u32);
    void DVDLowStopMotor(void (*)(u32));
    void DCInvalidateRange(void *, u32);

    u8 *base = (u8 *)BB2_80339F40;
    switch (CurrCommand_803685B4) {
    case 3:
        if (fn_8020F9E8(
                (base + 0x20),
                *(u8 **)((u8 *)executing_80368598 + 0x24))) {

            memcpy(IDShouldBe_8036859C, (base + 0x20), 0x20);

            ((DVDReadyCommand *)executing_80368598)->state = 1;

            DCInvalidateRange(base, 0x20);

            lbl_803685E0 = (void (*)(void *))fn_8020D838;
            fn_8020D838(executing_80368598);
        } else {
            DVDLowStopMotor(fn_8020D90C);
        }
        break;
    default:
        if (fn_80231944((base + 0x20), IDShouldBe_8036859C, 0x20) != 0) {
            DVDLowStopMotor(fn_8020D90C);
        } else {
            lbl_803685E0 = (void (*)(void *))fn_8020D804;
            fn_8020D804(executing_80368598);
        }
    }
}
#pragma pop
void fn_8020D804(void) {
      /* DVD Disc ID Check */
      void fn_8020C1A4(u8, s32, void *);
      void fn_8020DAE0(u32);
    extern void *IDShouldBe_8036859C;

    fn_8020C1A4(
        ((u8 *)IDShouldBe_8036859C)[8],
        0xA,
        fn_8020DAE0
    );
}

void fn_8020D838(void) {
    /* DVD Disc ID Check */
    void fn_8020C1A4(u8, s32, void *);
    void fn_8020D86C(u32 arg0);
    extern void *IDShouldBe_8036859C;

    fn_8020C1A4(M2C_FIELD(IDShouldBe_8036859C, u8 *, 8), 0xA, fn_8020D86C);
}

void fn_8020D86C(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void fn_8020BF58(void *);
    void fn_8020D8D4();

    extern s32 lbl_803685CC;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (arg0 & 1) {
        lbl_803685CC = 0;
        fn_8020D8D4(executing_80368598);
        return;
    }

    fn_8020BF58((void *)fn_8020D27C);
}

void fn_8020D8D4(void) {
    extern u16 BB2_80339F40[16];
    void fn_8020DA08(u32);
    void fn_8020BAD0(u16 *, s32, s32, void (*)(u32));

    fn_8020BAD0(BB2_80339F40, 0x20, 0x420, fn_8020DA08);
}

#pragma optimization_level 3
void fn_8020D90C(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void DVDLowStopMotor(void (*)(u32));
    void fn_8020DD7C(void);

    extern s32 lbl_803685CC;
    extern u32 lbl_803685B8;
    extern s32 ResumeFromHere_803685C0;
    extern void *executing_80368598;
    extern u8 DummyCommandBlock_80339F80[];
    extern void (*lbl_803685BC)(void *, void *);

    s32 flag;
    DVDReadyCommand *block;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (arg0 & 2) {
        __DVDStoreErrorCode(0x01234567);
        DVDLowStopMotor(cbForStateError);
        return;
    }

    flag = 0;
    lbl_803685CC = flag;
    if (lbl_803685B8 != 0) {
        block = (DVDReadyCommand *)executing_80368598;
        ResumeFromHere_803685C0 = 1;
        lbl_803685B8 = flag;
        executing_80368598 = DummyCommandBlock_80339F80;
        block->state = 0xA;
        if (block->callback != NULL) {
            block->callback(-3, block);
        }
        if (lbl_803685BC != NULL) {
            lbl_803685BC((void *)0, block);
        }
        stateReady();
        flag = 1;
    }
    if (flag == 0) {
        ((DVDReadyCommand *)executing_80368598)->state = 6;
        fn_8020DD7C();
    }
}
#pragma optimization_level reset
void fn_8020DA08(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void fn_8020BF58(void *);
    s32 fn_8020BAD0(void *, u32, u32, void (*)(u32));
    void fn_8020D040(u32);
    void OSPanic(void *, s32, char *, ...);
    extern void (*lbl_803685E0)(void *);
    extern u8 *bootInfo_803685A0;
    extern u8 BB2_80339F40[];
    extern s32 lbl_80366F74;
    extern char lbl_8029D0DC[];
    extern s32 lbl_803685CC;
    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
    } else if (arg0 & 1) {
        lbl_803685CC = 0;
        lbl_803685E0 = (void (*)(void *))fn_8020CFAC;
        if (*(u32 *)(bootInfo_803685A0 + 0x3C) < *(u32 *)(BB2_80339F40 + 8))
            OSPanic(&lbl_80366F74, 0x295, lbl_8029D0DC);
        fn_8020BAD0(
            *(void **)(bootInfo_803685A0 + 0x38),
            (*(u32 *)(BB2_80339F40 + 8) + 0x1F) & ~0x1F,
            *(u32 *)(BB2_80339F40 + 4),
            fn_8020D040
        );
    } else {
        fn_8020BF58((void *)fn_8020D27C);
    }
}
#pragma optimization_level reset
void fn_8020DAE0(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void fn_8020BF58(void *);
    void stateBusy_8020E178(void *);
    void fn_8020D27C(void);

    extern s32 lbl_803685CC;
    extern s32 ResumeFromHere_803685C0;

    DVDReadyCommand *block;
    s32 cleaned;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (arg0 & 1) {
        cleaned = 0;
        lbl_803685CC = 0;
        if (lbl_803685B8 != 0) {
            ResumeFromHere_803685C0 = 0;
            block = (DVDReadyCommand *)executing_80368598;
            lbl_803685B8 = 0;
            executing_80368598 = DummyCommandBlock_80339F80;
            block->state = 10;
            if (block->callback != 0) {
                block->callback(-3, block);
            }
            if (lbl_803685BC != 0) {
                lbl_803685BC((void *)0, block);
            }
            stateReady();
            cleaned = 1;
        }
        if (cleaned == 0) {
            ((DVDReadyCommand *)executing_80368598)->state = 1;
            stateBusy_8020E178(executing_80368598);
        }
    } else {
        fn_8020BF58((void *)fn_8020D27C);
    }
}

void AlarmHandler(void *alarm, void *context) {
    void DVDReset(void);
    void DCInvalidateRange(void *, u32);
    void fn_8020DCE8(void *);
    extern u8 lbl_80339F60[];
    extern void *executing_80368598;
    extern void (*lbl_803685E0)(void *);

    DVDReset();
    DCInvalidateRange(lbl_80339F60, 0x20);
    lbl_803685E0 = fn_8020DCE8;
    fn_8020DCE8(executing_80368598);
}

void fn_8020DC14(void) {
    extern u16 BB2_80339F40[];
    extern volatile s32 CurrCommand_803685B4;
    extern u32 MotorState_803685D8;
    void DVDReset(void);
    void OSCreateAlarm(void *);
    void OSSetAlarm(void *, u64, void (*)(void *, void *));
    void AlarmHandler(void *, void *);
    void __DVDClearWaitingQueue(void);

    u8 *bb2;
    DVDReadyCommand *block;

    bb2 = (u8 *)BB2_80339F40;

    switch (CurrCommand_803685B4) {
    case 4:
    case 5:
    case 13:
    case 15:
        __DVDClearWaitingQueue();
        block = (DVDReadyCommand *)executing_80368598;
        executing_80368598 = bb2 + 0x40;
        if (block->callback != 0) {
            block->callback(-4, block);
        }
        stateReady();
        break;
    default:
        MotorState_803685D8 = 0;
        DVDReset();
        OSCreateAlarm(bb2 + 0x70);
        OSSetAlarm(bb2 + 0x70, (u64)(((*(u32 *)0x800000f8 / 4) / 1000) * 1150), AlarmHandler);
        break;
    }
}

void fn_8020DCE8(void *block) {
    void fn_8020BE28(void *, void *);
    void fn_8020DD18(void);
    extern u8 lbl_80339F60[];

    fn_8020BE28(lbl_80339F60, fn_8020DD18);
}

void fn_8020DD18(u32 arg0)
{
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void fn_8020BF58(void *);
    void fn_8020D724(void);
    void fn_8020D27C(void);
    extern s32 lbl_803685CC;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (arg0 & 1) {
        lbl_803685CC = 0;
        fn_8020D724();
        return;
    }

    fn_8020BF58((void *)fn_8020D27C);
}

void fn_8020DD7C(void) {
    void DVDLowWaitCoverClose(void (*)(void));
    extern void cbForStateMotorStopped(void);
    DVDLowWaitCoverClose(cbForStateMotorStopped);
}

void cbForStateMotorStopped(void) {
    extern u16 BB2_80339F40[];
    extern volatile s32 CurrCommand_803685B4;
    extern u32 MotorState_803685D8;
    void DVDReset(void);
    void OSCreateAlarm(void *);
    void OSSetAlarm(void *, u64, void (*)(void *, void *));
    void AlarmHandler(void *, void *);
    void __DVDClearWaitingQueue(void);
    u8 *bb2;
    DVDReadyCommand *block;
    u32 pad[2];
    bb2 = (u8 *)BB2_80339F40;
    *(u32 *)0xCC006004=0;
    ((DVDReadyCommand *)executing_80368598)->state=3;
    switch (CurrCommand_803685B4) {
    case 4:
    case 5:
    case 13:
    case 15:
        __DVDClearWaitingQueue();
        block = (DVDReadyCommand *)executing_80368598;
        executing_80368598 = bb2 + 0x40;
        if (block->callback != 0) {
            block->callback(-4, block);
        }
        stateReady();
        break;
    default:
        MotorState_803685D8 = 0;
        DVDReset();
        OSCreateAlarm(bb2 + 0x70);
        OSSetAlarm(bb2 + 0x70, (u64)(((*(u32 *)0x800000f8 / 4) / 1000) * 1150), AlarmHandler);
        break;
    }
}

#pragma opt_common_subs off
/* Pop the next DVD command and enter its busy/resume path (Dolphin DVD state machine). */
void stateReady(void) {
    extern u16 BB2_80339F40[];
    extern volatile s32 CurrCommand_803685B4;
    extern s32 CancelLastError_803685C4;
    extern volatile u32 ResumeFromHere_803685C0;
    extern u32 MotorState_803685D8;
    s32 __DVDCheckWaitingQueue(void);
    void stateBusy_8020E178(void *);
    void DVDLowWaitCoverClose(void (*)(void));
    void cbForStateMotorStopped(void);
    void DVDReset(void);
    void OSCreateAlarm(void *);
    void OSSetAlarm(void *, u64, void (*)(void *, void *));
    void __DVDStoreErrorCode(s32);
    void DVDLowStopMotor(void (*)(u32));
    void cbForStateError(u32);
    u8 *bb2 = (u8 *)BB2_80339F40;
    void *block;
    void (*callback)(s32, void *);

    if (!__DVDCheckWaitingQueue()) {
        executing_80368598 = 0;
        return;
    }
    if (PauseFlag_803685A4) {
        PausingFlag_803685A8 = 1;
        executing_80368598 = 0;
        return;
    }
    executing_80368598 = (void *)__DVDPopWaitingQueue();
    if (FatalErrorFlag_803685B0) {
        ((DVDReadyCommand *)executing_80368598)->state = -1;
        block = executing_80368598;
        executing_80368598 = bb2 + 0x40;
        callback = *(void (**)(s32, void *))((u8 *)block + 0x28);
        if (callback)
            callback(-1, block);
        stateReady();
        return;
    }
    block = executing_80368598;
    CurrCommand_803685B4 = ((DVDReadyCommand *)block)->command;
    if (ResumeFromHere_803685C0 != 0U) {
        switch ((s32)ResumeFromHere_803685C0) {
        case 2:
            ((DVDReadyCommand *)executing_80368598)->state = 11;
            DVDLowWaitCoverClose(cbForStateMotorStopped);
            break;
        case 3:
            ((DVDReadyCommand *)executing_80368598)->state = 4;
            DVDLowWaitCoverClose(cbForStateMotorStopped);
            break;
        case 4:
            ((DVDReadyCommand *)executing_80368598)->state = 5;
            DVDLowWaitCoverClose(cbForStateMotorStopped);
            break;
        case 1:
        case 6:
        case 7:
            ((DVDReadyCommand *)block)->state = 3;
            switch (CurrCommand_803685B4) {
            case 4:
            case 5:
            case 13:
            case 15:
                __DVDClearWaitingQueue();
                block = executing_80368598;
                executing_80368598 = bb2 + 0x40;
                callback = *(void (**)(s32, void *))((u8 *)block + 0x28);
                if (callback)
                    callback(-4, block);
                stateReady();
                break;
            default:
                MotorState_803685D8 = 0;
                DVDReset();
                OSCreateAlarm(bb2 + 0x70);
                OSSetAlarm(bb2 + 0x70, (u64)(((*(u32 *)0x800000f8 / 4) / 1000) * 1150), AlarmHandler);
                break;
            }
            break;
        case 5:
            __DVDStoreErrorCode(CancelLastError_803685C4);
            DVDLowStopMotor(cbForStateError);
            break;
        }
        ResumeFromHere_803685C0 = 0;
        return;
    }
    if (MotorState_803685D8 == 0) {
        ((DVDReadyCommand *)executing_80368598)->state = 1;
        stateBusy_8020E178(executing_80368598);
        return;
    }
    switch (CurrCommand_803685B4) {
    case 4:
    case 5:
    case 13:
    case 15:
        __DVDClearWaitingQueue();
        block = executing_80368598;
        executing_80368598 = bb2 + 0x40;
        callback = *(void (**)(s32, void *))((u8 *)block + 0x28);
        if (callback)
            callback(-4, block);
        stateReady();
        break;
    default:
        MotorState_803685D8 = 0;
        DVDReset();
        OSCreateAlarm(bb2 + 0x70);
        OSSetAlarm(bb2 + 0x70, (u64)(((*(u32 *)0x800000f8 / 4) / 1000) * 1150), AlarmHandler);
        break;
    }
}
#pragma opt_common_subs reset
#pragma global_optimizer off
#pragma peephole off
void stateBusy_8020E178(void *arg0) {
    extern void (*lbl_803685E0)(void *);
    extern void *executing_80368598;
    extern u8 DummyCommandBlock_80339F80[];
    extern s32 lbl_803685AC;
    extern void (*lbl_80366F70)(void *, void *);
    void fn_8020BE28(void *, void *);
    void fn_8020BAD0(void *, void *, void *, void *);
    void fn_8020BD68(void *, void *);
    void DVDLowStopMotor(void *);
    void fn_8020C118(void *, void *);
    void fn_8020C080(void *, void *, void *, void *);
    void fn_8020C1A4(void *, void *, void *);
    void fn_8020BFE4(void *, void *);
    void stateReady(void);
    void fn_8020E4B8(void);
    u8 *b;
    void *old;
    void (*cb)(void *, void *);
    u32 remaining;
    u32 len;

    lbl_803685E0 = stateBusy_8020E178;
    b = (u8 *)arg0;

    switch (*(u32 *)(b + 0x8)) {
    case 5:
        dvdClearDiStatus();
        *(u32 *)(b + 0x1c) = 0x20;
        fn_8020BE28(*(void **)(b + 0x18), (void *)fn_8020E4B8);
        break;
    case 1:
    case 4:
        if (*(u32 *)(b + 0x14) == 0) {
            old = executing_80368598;
            executing_80368598 = DummyCommandBlock_80339F80;
            *(u32 *)((u8 *)old + 0xc) = 0;
            cb = *(void **)((u8 *)old + 0x28);
            if (cb) {
                cb(NULL, old);
            }
            stateReady();
        } else {
            dvdClearDiStatus();
            remaining = *(u32 *)(b + 0x14) - *(u32 *)(b + 0x20);
            if (remaining > 0x80000) {
                len = 0x80000;
            } else {
                len = remaining;
            }
            *(u32 *)(b + 0x1c) = len;
            fn_8020BAD0((void *)(*(u32 *)(b + 0x18) + *(u32 *)(b + 0x20)),
                        *(void **)(b + 0x1c),
                        (void *)(*(u32 *)(b + 0x10) + *(u32 *)(b + 0x20)),
                        (void *)fn_8020E4B8);
        }
        break;
    case 2:
        dvdClearDiStatus();
        fn_8020BD68(*(void **)(b + 0x10), (void *)fn_8020E4B8);
        break;
    case 3:
        DVDLowStopMotor((void *)fn_8020E4B8);
        break;
    case 15:
        DVDLowStopMotor((void *)fn_8020E4B8);
        break;
    case 6:
        dvdClearDiStatus();
        if (lbl_803685AC != 0) {
            *(u32 *)((u8 *)executing_80368598 + 0x1c) = 0;
            fn_8020C118(NULL, (void *)fn_8020E4B8);
        } else {
            *(u32 *)((u8 *)executing_80368598 + 0x1c) = 1;
            fn_8020C080(NULL, (void *)(u32)*(u32 *)(b + 0x14), (void *)(u32)*(u32 *)(b + 0x10), (void *)fn_8020E4B8);
        }
        break;
    case 7:
        dvdClearDiStatus();
        fn_8020C080((void *)0x10000, NULL, NULL, (void *)fn_8020E4B8);
        break;
    case 8:
        dvdClearDiStatus();
        lbl_803685AC = 1;
        fn_8020C080(NULL, NULL, NULL, (void *)fn_8020E4B8);
        break;
    case 9:
        dvdClearDiStatus();
        fn_8020C118(NULL, (void *)fn_8020E4B8);
        break;
    case 10:
        dvdClearDiStatus();
        fn_8020C118((void *)0x10000, (void *)fn_8020E4B8);
        break;
    case 11:
        dvdClearDiStatus();
        fn_8020C118((void *)0x20000, (void *)fn_8020E4B8);
        break;
    case 12:
        dvdClearDiStatus();
        fn_8020C118((void *)0x30000, (void *)fn_8020E4B8);
        break;
    case 13:
        dvdClearDiStatus();
        fn_8020C1A4(*(void **)(b + 0x10), *(void **)(b + 0x14), (void *)fn_8020E4B8);
        break;
    case 14:
        dvdClearDiStatus();
        *(u32 *)(b + 0x1c) = 0x20;
        fn_8020BFE4(*(void **)(b + 0x18), (void *)fn_8020E4B8);
        break;
    case 16:
        dvdClearDiStatus();
        DVDLowStopMotor((void *)fn_8020E4B8);
        break;
    case 0:
    default:
        lbl_80366F70(arg0, (void *)fn_8020E4B8);
        break;
    }
}
#pragma peephole reset
#pragma global_optimizer on

#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
void fn_8020E4B8(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void DVDLowStopMotor(void (*)(u32));
    void DVDLowWaitCoverClose(void (*)(void));
    void cbForStateMotorStopped(void);
    void stateReady(void);
    void stateBusy_8020E178(void *);
    void fn_8020BF58(void *);
    void fn_8020C080(u32, u32, u32, void (*)(u32));
    void fn_8020D27C(u32);
    extern u16 BB2_80339F40[];
    extern volatile u32 CurrCommand_803685B4;
    extern volatile s32 lbl_803685CC;
    extern s32 ResetRequired_803685D0;
    extern u32 lbl_803685B8;
    extern void *executing_80368598;
    extern s32 ResumeFromHere_803685C0;
    extern void (*lbl_803685BC)(void *, void *);
    extern u32 lbl_80366F7C;
    extern s32 MotorState_803685D8;
    extern u32 lbl_8029D154[];
    extern s32 lbl_803685AC;

    typedef struct DVDReadyCommand {
        u8 pad[8];
        s32 command;
        s32 state;
        u32 unk10;
        u32 unk14;
        u32 unk18;
        u32 unk1C;
        u32 unk20;
        u8 pad24[4];
        void (*callback)(s32, void *);
    } DVDReadyCommand;

    DVDReadyCommand *block;
    u8 *base;
    u32 cmd;
    s32 flag;
    u32 *tbl;
    u32 val;

    base = (u8 *)BB2_80339F40;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (CurrCommand_803685B4 == 3 || CurrCommand_803685B4 == 0xF) {
        if (arg0 & 2) {
            __DVDStoreErrorCode(0x01234567);
            DVDLowStopMotor(cbForStateError);
            return;
        }
        lbl_803685CC = 0;
        if (CurrCommand_803685B4 == 0xF) {
            ResetRequired_803685D0 = 1;
        }
        if (lbl_803685B8 != 0) {
            ResumeFromHere_803685C0 = 7;
            block = (DVDReadyCommand *)executing_80368598;
            lbl_803685B8 = 0;
            *(s32 *)((u8 *)block + 0xC) = 0xA;
            executing_80368598 = base + 0x40;
            if (block->callback != NULL) {
                block->callback(-3, block);
            }
            if (lbl_803685BC != NULL) {
                lbl_803685BC((void *)0, block);
            }
            stateReady();
            flag = 1;
        } else {
            flag = 0;
        }
        if (flag == 0) {
            ((DVDReadyCommand *)executing_80368598)->state = 7;
            DVDLowWaitCoverClose(cbForStateMotorStopped);
        }
        return;
    }

    cmd = CurrCommand_803685B4;
    if (cmd == 1 || (cmd - 4) <= 1 || cmd == 0xE) {
        flag = 1;
    } else if (cmd == lbl_80366F7C) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag != 0) {
        block = (DVDReadyCommand *)executing_80368598;
        block->unk20 = block->unk20 + (block->unk1C - __DIRegs[6]);
    }

    if (arg0 & 8) {
        block = (DVDReadyCommand *)executing_80368598;
        lbl_803685B8 = 0;
        executing_80368598 = base + 0x40;
        *(s32 *)((u8 *)block + 0xC) = 0xA;
        if (block->callback != NULL) {
            block->callback(-3, block);
        }
        if (lbl_803685BC != NULL) {
            lbl_803685BC((void *)0, block);
        }
        stateReady();
        return;
    }

    if (arg0 & 1) {
        lbl_803685CC = 0;
        if (CurrCommand_803685B4 == 0x10) {
            block = (DVDReadyCommand *)executing_80368598;
            MotorState_803685D8 = 1;
            executing_80368598 = base + 0x40;
            block->state = 0;
            if (block->callback != NULL) {
                block->callback(0, block);
            }
            stateReady();
            return;
        }
        if (lbl_803685B8 != 0) {
            ResumeFromHere_803685C0 = 0;
            block = (DVDReadyCommand *)executing_80368598;
            lbl_803685B8 = 0;
            *(s32 *)((u8 *)block + 0xC) = 0xA;
            executing_80368598 = base + 0x40;
            if (block->callback != NULL) {
                block->callback(-3, block);
            }
            if (lbl_803685BC != NULL) {
                lbl_803685BC((void *)0, block);
            }
            stateReady();
            flag = 1;
        } else {
            flag = 0;
        }
        if (flag != 0) {
            return;
        }
        cmd = CurrCommand_803685B4;
        if (cmd == 1 || (cmd - 4) <= 1 || cmd == 0xE) {
            flag = 1;
        } else if (cmd == lbl_80366F7C) {
            flag = 1;
        } else {
            flag = 0;
        }
        if (flag != 0) {
            DVDReadyCommand *active = (DVDReadyCommand *)executing_80368598;
            if (active->unk20 != active->unk14) {
                stateBusy_8020E178(active);
                return;
            }
            executing_80368598 = base + 0x40;
            active->state = 0;
            block = active;
            if (block->callback != NULL) {
                block->callback((s32)block->unk20, block);
            }
            stateReady();
            return;
        }
        cmd = CurrCommand_803685B4;
        if ((cmd - 9) <= 3) {
            flag = 1;
        } else {
            tbl = lbl_8029D154;
            if (cmd == *tbl) {
                flag = 1;
            } else {
                tbl++;
                if (cmd == *tbl) {
                    flag = 1;
                } else if (cmd == tbl[1]) {
                    flag = 1;
                } else {
                    flag = 0;
                }
            }
        }
        if (flag != 0) {
            if (CurrCommand_803685B4 == 0xB || CurrCommand_803685B4 == 0xA) {
                val = *(volatile u32 *)(0xCC006000 + 0x20) << 2;
            } else {
                val = __DIRegs[8];
            }
            block = (DVDReadyCommand *)executing_80368598;
            executing_80368598 = base + 0x40;
            block->state = 0;
            if (block->callback != NULL) {
                block->callback((s32)val, block);
            }
            stateReady();
            return;
        }
        if (CurrCommand_803685B4 == 6) {
            u32 *phase;
            block = (DVDReadyCommand *)executing_80368598;
            phase = &block->unk1C;
            if (*phase == 0) {
                if (*(volatile u32 *)(0xCC006000 + 0x20) & 1) {
                    executing_80368598 = base + 0x40;
                    block->state = 9;
                    if (block->callback != NULL) {
                        block->callback(-2, block);
                    }
                    stateReady();
                    return;
                }
                lbl_803685AC = 0;
                *phase = 1;
                fn_8020C080(0, ((DVDReadyCommand *)executing_80368598)->unk14,
                            ((DVDReadyCommand *)executing_80368598)->unk10, fn_8020E4B8);
                return;
            }
            executing_80368598 = base + 0x40;
            block->state = 0;
            if (block->callback != NULL) {
                block->callback(0, block);
            }
            stateReady();
            return;
        }
        block = (DVDReadyCommand *)executing_80368598;
        executing_80368598 = base + 0x40;
        block->state = 0;
        if (block->callback != NULL) {
            block->callback(0, block);
        }
        stateReady();
        return;
    }

    if (CurrCommand_803685B4 == 0xE) {
        __DVDStoreErrorCode(0x01234567);
        DVDLowStopMotor(cbForStateError);
        return;
    }

    if (CurrCommand_803685B4 == 1 || CurrCommand_803685B4 == 4 || CurrCommand_803685B4 == 5 ||
        CurrCommand_803685B4 == 0xE) {
        block = (DVDReadyCommand *)executing_80368598;
        if (block->unk20 == block->unk14) {
            if (lbl_803685B8 != 0) {
                ResumeFromHere_803685C0 = 0;
                lbl_803685B8 = 0;
                executing_80368598 = base + 0x40;
                *(s32 *)((u8 *)block + 0xC) = 0xA;
                if (block->callback != NULL) {
                    block->callback(-3, block);
                }
                if (lbl_803685BC != NULL) {
                    lbl_803685BC((void *)0, block);
                }
                stateReady();
                flag = 1;
            } else {
                flag = 0;
            }
            if (flag == 0) {
                block = (DVDReadyCommand *)executing_80368598;
                executing_80368598 = base + 0x40;
                block->state = 0;
                if (block->callback != NULL) {
                    block->callback((s32)block->unk20, block);
                }
                stateReady();
            }
            return;
        }
    }
    fn_8020BF58(fn_8020D27C);
}
#pragma pop
s32 DVDReadAbsAsyncPrio(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s32 arg5)
{
    void DCInvalidateRange(void *, u32);
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    s32 __DVDPushWaitingQueue(s32, void *);
    void stateReady(void);

    extern s32 autoInvalidation_80366F6C;
    extern void *executing_80368598;
    extern s32 PauseFlag_803685A4;

    u8 *block;
    u32 addr;
    u32 length;
    u32 command;
    s32 result;
    u32 interrupts;

    block = (u8 *)arg0;
    addr=arg1;
    length=arg2;

    *(u32 *)(block + 0x08) = 1;
    *(u32 *)(block + 0x18) = addr;
    *(u32 *)(block + 0x14) = length;
    *(u32 *)(block + 0x10) = arg3;
    *(u32 *)(block + 0x20) = 0;
    *(u32 *)(block + 0x28) = arg4;

    if (autoInvalidation_80366F6C) {
        command = *(u32 *)(block + 0x08);

        if (command == 1 ||
            (u32)(command - 4) <= 1 ||
            command == 14) {
            DCInvalidateRange(
                *(void **)(block + 0x18),
                *(u32 *)(block + 0x14)
            );
        }
    }

    interrupts = OSDisableInterrupts();

    *(u32 *)(block + 0x0C) = 2;

    result = __DVDPushWaitingQueue(arg5, arg0);

    if (executing_80368598 == 0 &&
        PauseFlag_803685A4 == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);

    return result;
}

s32 fn_8020EBEC(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    void DCInvalidateRange(void *, u32);
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    s32 __DVDPushWaitingQueue(s32, void *);
    void stateReady(void);

    extern s32 autoInvalidation_80366F6C;
    extern void *executing_80368598;
    extern s32 PauseFlag_803685A4;

    s32 result;
    u32 interrupts;
    u32 command;
    u32 addr;
    u32 length;
    register u8 *block;

    block = (u8 *)arg0;
    addr = arg1;
    length = arg2;

    *(u32 *)(block + 0x08) = 4;
    *(u32 *)(block + 0x18) = addr;
    *(u32 *)(block + 0x14) = length;
    *(u32 *)(block + 0x10) = arg3;
    *(u32 *)(block + 0x20) = 0;
    *(u32 *)(block + 0x28) = arg4;

    if (autoInvalidation_80366F6C) {
        command = *(u32 *)(block + 0x08);

        if (command == 1 ||
            (u32)(command - 4) <= 1 ||
            command == 14) {
            DCInvalidateRange(
                *(void **)(block + 0x18),
                *(u32 *)(block + 0x14)
            );
        }
    }

    interrupts = OSDisableInterrupts();

    *(u32 *)(block + 0x0C) = 2;

    result = __DVDPushWaitingQueue(2, block);

    if (executing_80368598 == 0 &&
        PauseFlag_803685A4 == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);

    return result;
}

s32 DVDReadDiskID(u8 *block, void *arg1, void *callback) {
    void DCInvalidateRange(void *, u32);
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    s32 __DVDPushWaitingQueue(s32, void *);
    extern s32 autoInvalidation_80366F6C;
    s32 result;
    u8 pad[8];
    *(u32 *)(block + 8) = 5;
    *(void **)(block + 0x18) = arg1;
    *(u32 *)(block + 0x14) = 0x20;
    *(u32 *)(block + 0x10) = 0;
    *(u32 *)(block + 0x20) = 0;
    *(void **)(block + 0x28) = callback;
    {
        u32 enabled;
        u32 command;
        if (autoInvalidation_80366F6C != 0) {
            command = *(u32 *)(block + 8);
            if (command == 1 || command - 4 <= 1 || command == 14)
                DCInvalidateRange(*(void **)(block + 0x18), *(u32 *)(block + 0x14));
        }
        enabled = OSDisableInterrupts();
        *(u32 *)(block + 0xC) = 2;
        result = __DVDPushWaitingQueue(2, block);
        if (executing_80368598 == 0 && PauseFlag_803685A4 == 0)
            stateReady();
        OSRestoreInterrupts(enabled);
    }
    return result;
}

s32 fn_8020ED90(u8 *block, u32 callback) {
  void DCInvalidateRange(void *, u32);
  u32 OSDisableInterrupts(void);
  void OSRestoreInterrupts(u32);
  s32 __DVDPushWaitingQueue(s32, void *);
  void stateReady(void);
  extern s32 autoInvalidation_80366F6C;
  extern void *executing_80368598;
  extern s32 PauseFlag_803685A4;
  s32 result;
  u32 interrupts;
  u32 command;
  u32 pad[2];

  (void)pad;
  *(u32 *)(block + 8) = 7;
  *(u32 *)(block + 0x28) = callback;
  if (autoInvalidation_80366F6C != 0) {
    command = *(u32 *)(block + 8);
    if (command == 1 || command - 4 <= 1 || command == 14)
      DCInvalidateRange(*(void **)(block + 0x18), *(u32 *)(block + 0x14));
  }
  interrupts = OSDisableInterrupts();
  *(u32 *)(block + 0xC) = 2;
  result = __DVDPushWaitingQueue(1, block);
  if (executing_80368598 == 0 && PauseFlag_803685A4 == 0)
    stateReady();
  OSRestoreInterrupts(interrupts);
  return result;
}

s32 DVDInquiryAsync(u8 *block, s32 arg1, s32 arg2) {
    void DCInvalidateRange(void *, u32);
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    s32 __DVDPushWaitingQueue(s32, void *);
    extern s32 autoInvalidation_80366F6C;
    s32 result;
    u8 pad[8];
    *(u32 *)(block + 8) = 14;
    *(s32 *)(block + 0x18) = arg1;
    *(u32 *)(block + 0x14) = 32;
    *(u32 *)(block + 0x20) = 0;
    *(s32 *)(block + 0x28) = arg2;
    {
        u32 enabled;
        u32 command;
        if (autoInvalidation_80366F6C != 0) {
            command = *(u32 *)(block + 8);
            if (command == 1 || command - 4 <= 1 || command == 14)
                DCInvalidateRange(*(void **)(block + 0x18), *(u32 *)(block + 0x14));
        }
        enabled = OSDisableInterrupts();
        *(u32 *)(block + 0xC) = 2;
        result = __DVDPushWaitingQueue(2, block);
        if (executing_80368598 == 0 && PauseFlag_803685A4 == 0)
            stateReady();
        OSRestoreInterrupts(enabled);
    }
    return result;
}

#pragma global_optimizer off
#pragma peephole off
void DVDReset(void) {
    extern s32 ResetRequired_803685D0;
    extern s32 ResumeFromHere_803685C0;
    u32 *base;
    u32 *di;
    u32 tmp;
    DVDLowReset();
    base = (u32 *)0xCC000000;
    base[0x1800] = 0x2A;
    di = base + 0x1800;
    tmp = base[0x1801];
    di[1] = tmp;
    ResetRequired_803685D0 = 0;
    ResumeFromHere_803685C0 = 0;
}
#pragma peephole reset
#pragma global_optimizer reset

s32 DVDGetCommandBlockStatus(void *arg0) {
    s32 temp_r0;
    s32 var_r31;

    OSDisableInterrupts();
    temp_r0 = *(s32 *)((char *)arg0 + 0xC);
    if (temp_r0 == 3) {
        var_r31 = 1;
    } else {
        var_r31 = temp_r0;
    }
    OSRestoreInterrupts();
    return var_r31;
}

s32 DVDGetDriveStatus(void) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s32 enabled;
    s32 ret;
    s32 level[2];
    void *exec;

    enabled = OSDisableInterrupts();
    if (FatalErrorFlag_803685B0 != 0) {
        ret = -1;
    } else if (PausingFlag_803685A8 != 0) {
        ret = 8;
    } else {
        exec = executing_80368598;
        if (exec == NULL) {
            ret = 0;
        } else if (exec == DummyCommandBlock_80339F80) {
            ret = 0;
        } else {
            level[0] = OSDisableInterrupts();
            ret = *(s32 *)((u8 *)exec + 0xC);
            if (ret == 3) {
                ret = 1;
            }
            OSRestoreInterrupts(level[0]);
        }
    }
    OSRestoreInterrupts(enabled);
    return ret;
}

s32 fn_8020F058(s32 arg0) {
    extern s32 autoInvalidation_80366F6C;
    s32 temp_r0;

    temp_r0 = autoInvalidation_80366F6C;
    autoInvalidation_80366F6C = arg0;
    return temp_r0;
}

#pragma peephole off
#pragma global_optimizer off
void fn_8020F068(void) {
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    u32 enabled;
    enabled = OSDisableInterrupts();
    *(volatile s32 *)&PauseFlag_803685A4 = 0;
    if (*(volatile s32 *)&PausingFlag_803685A8 != 0) {
        *(volatile s32 *)&PausingFlag_803685A8 = 0;
        stateReady();
    }
    OSRestoreInterrupts(enabled);
}

#pragma opt_common_subs off
s32 fn_8020F0B8(DVDReadyCommand *block, void (*callback)(s32, void *)) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    BOOL fn_8020C2FC(void);
    void *fn_8020C310(void);
    s32 fn_8020F7F0(void *);
    void cbForStateMotorStopped(void);
    extern s32 ResumeFromHere_803685C0;
    void (*cb)(s32, void *);
    s32 enabled;
    u8 pad[8];

    enabled = OSDisableInterrupts();
    cb = callback;

    switch (block->state) {
    case -1:
    case 0:
    case 10:
        if (cb != 0) {
            cb(0, block);
        }
        break;
    case 1:
        if (lbl_803685B8 != 0) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        lbl_803685BC = (void (*)(void *, void *))cb;
        lbl_803685B8 = 1;
        if ((u32)block->command == 4U) {
            goto state2;
        }
        if ((u32)block->command == 1U) {
            fn_8020C2FC();
        }
        break;
    case 2:
    state2:
        fn_8020F7F0(block);
        block->state = 10;
        cb = block->callback;
        if (cb != 0) {
            cb(-3, block);
        }
        cb = callback;
    case 3:
        if (cb != 0) {
            cb(0, block);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 11:
        switch (block->command) {
        case 4:
        case 5:
        case 13:
        case 15:
            if (cb != 0) {
                cb(0, block);
            }
            break;
        default:
            if (lbl_803685B8 != 0) {
                OSRestoreInterrupts(enabled);
                return 0;
            }
            lbl_803685BC = (void (*)(void *, void *))cb;
            lbl_803685B8 = 1;
            break;
        }
        break;
    case 8:
    case 9:
        if (fn_8020C310() != (void *)cbForStateMotorStopped) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        if (block->state == 4) {
            ResumeFromHere_803685C0 = 3;
        }
        if (block->state == 5) {
            ResumeFromHere_803685C0 = 4;
        }
        if (block->state == 6) {
            ResumeFromHere_803685C0 = 1;
        }
        if (block->state == 11) {
            ResumeFromHere_803685C0 = 2;
        }
        if (block->state == 7) {
            ResumeFromHere_803685C0 = 7;
        }
        executing_80368598 = DummyCommandBlock_80339F80;
        block->state = 10;
        cb = block->callback;
        if (cb != 0) {
            cb(-3, block);
        }
        cb = callback;
        if (cb != 0) {
            cb(0, block);
        }
        stateReady();
        break;
    }

    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma opt_common_subs reset
s32 fn_8020F334(void *arg0) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void OSSleepThread(void *);
    s32 fn_8020F0B8(void *, void *);
    extern M2C_UNK __DVDThreadQueue;
    extern M2C_UNK fn_8020F3E0;
    s32 interrupts;
    s32 state;
    u32 command;

    if (fn_8020F0B8(arg0, &fn_8020F3E0) == 0) {
        return -1;
    }
    interrupts = OSDisableInterrupts();
    while (1) {
        state = ((DVDReadyCommand *)arg0)->state;
        if ((u32)(state + 1) <= 1U) break;
        if (state == 10) break;
        if (state == 3) {
            command = (u32)((DVDReadyCommand *)arg0)->command;
            if ((u32)(command - 4) <= 1U) break;
            if (command == 13) break;
            if (command == 15) break;
        }
        OSSleepThread(&__DVDThreadQueue);
    }
    OSRestoreInterrupts(interrupts);
    return 0;
}

#pragma global_optimizer on
#pragma peephole on
void fn_8020F3E0(void) {
    extern void* __DVDThreadQueue;
    fn_8020AEC4(&__DVDThreadQueue);
}

s32 fn_8020F404(void) {
    return 0x80000000;
}

s32 DVDKeepAlive(void)
{
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    extern s32 FatalErrorFlag_803685B0;
    extern s32 PausingFlag_803685A8;
    extern void *executing_80368598;
    extern u32 ResumeFromHere_803685C0;
    extern u8 DummyCommandBlock_80339F80[];
    extern volatile u32 __DIRegs[16];
    s32 enabled;
    s32 state;
    void *exec;
    u32 diStatus;
    s32 result;

    enabled = OSDisableInterrupts();

    if (FatalErrorFlag_803685B0 != 0) {
        state = -1;
    } else if (PausingFlag_803685A8 != 0) {
        state = 8;
    } else {
        exec = executing_80368598;
        if (exec == 0) {
            state = 0;
        } else if (exec == (void *)DummyCommandBlock_80339F80) {
            state = 0;
        } else {
            state = *(s32 *)((u8 *)exec + 0xC);
        }
    }

    switch (state) {
    case 1:
    case 2:
    case 9:
    case 10:
        result = 1;
        break;
    case -1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 11:
        result = 0;
        break;
    case 0:
    case 8:
        diStatus = ((u32 *)__DIRegs)[1];
        if ((((diStatus >> 2) & 1) != 0) || ((diStatus & 1) != 0)) {
            result = 0;
        } else if (ResumeFromHere_803685C0 != 0) {
            result = 0;
        } else {
            result = 1;
        }
        break;
    }

    OSRestoreInterrupts(enabled);
    return result;
}

void fn_8020F504(void (*arg0)(void *, void *)) {
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    void fn_8020F0B8(void *, void (*)(void *, void *));
    u32 inner, resume, outer, pause;
    void *block;
    outer = OSDisableInterrupts();
    __DVDClearWaitingQueue();
    if (lbl_803685B8 != 0) {
        lbl_803685BC = arg0;
    } else {
        if (executing_80368598 != 0)
            ((DVDReadyCommand *)executing_80368598)->callback = 0;
        inner = OSDisableInterrupts();
        pause = OSDisableInterrupts();
        PauseFlag_803685A4 = 1;
        if (executing_80368598 == 0)
            PausingFlag_803685A8 = 1;
        OSRestoreInterrupts(pause);
        while ((block = (void *)__DVDPopWaitingQueue()) != 0)
            fn_8020F0B8(block, 0);
        if (executing_80368598 != 0)
            fn_8020F0B8(executing_80368598, arg0);
        else if (arg0 != 0)
            arg0(0, 0);
        resume = OSDisableInterrupts();
        *(volatile s32 *)&PauseFlag_803685A4 = 0;
        if (*(volatile s32 *)&PausingFlag_803685A8 != 0) {
            *(volatile s32 *)&PausingFlag_803685A8 = 0;
            stateReady();
        }
        OSRestoreInterrupts(resume);
        OSRestoreInterrupts(inner);
    }
    OSRestoreInterrupts(outer);
}

int fn_8020F620(void *arg0) {
    extern u8 lbl_80339FB0[];

    if (arg0 == lbl_80339FB0) {
        return 1;
    }

    return fn_8020C370(arg0);
}

void __DVDClearWaitingQueue(void) {
    struct DVDQueue {
        struct DVDQueue *next;
        struct DVDQueue *prev;
    };
    extern struct DVDQueue WaitingQueue_80339FD8[4];
    struct DVDQueue *ptr;
    u32 i;

    for (i = 0; i < 4; i++) {
        ptr = &WaitingQueue_80339FD8[i];
        ptr->next = ptr;
        ptr->prev = ptr;
    }
}

int __DVDPushWaitingQueue(s32 priority, void *block) {
    struct DVDQueue {
        struct DVDQueue *next;
        struct DVDQueue *prev;
    };
    extern struct DVDQueue WaitingQueue_80339FD8[4];
    extern u32 OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(u32);
    struct DVDQueue *queue;
    struct DVDQueue *entry;
    u32 interrupts;

    entry = (struct DVDQueue *)block;
    interrupts = OSDisableInterrupts();
    queue = &WaitingQueue_80339FD8[priority];
    queue->prev->next = entry;
    entry->prev = queue->prev;
    entry->next = queue;
    queue->prev = entry;
    OSRestoreInterrupts(interrupts);
    return 1;
}

s32 __DVDPopWaitingQueue(void)
{
    struct DVDQueue {
        struct DVDQueue *next;
        struct DVDQueue *prev;
    };
    extern struct DVDQueue WaitingQueue_80339FD8[4];
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    struct DVDQueue *entry;
    s32 i;
    u32 interrupts;

    interrupts = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        if (WaitingQueue_80339FD8[i].next != &WaitingQueue_80339FD8[i]) {
            OSRestoreInterrupts(interrupts);
            interrupts = OSDisableInterrupts();
            entry = WaitingQueue_80339FD8[i].next;
            WaitingQueue_80339FD8[i].next = entry->next;
            entry->next->prev = &WaitingQueue_80339FD8[i];
            OSRestoreInterrupts(interrupts);
            entry->next = 0;
            entry->prev = 0;
            return (s32)entry;
        }
    }
    OSRestoreInterrupts(interrupts);
    return 0;
}

s32 __DVDCheckWaitingQueue(void) {
    struct DVDQueue {
        struct DVDQueue *next;
        struct DVDQueue *prev;
    };
    extern struct DVDQueue WaitingQueue_80339FD8[4];
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);

    u32 enabled;
    struct DVDQueue *q;
    s32 i;

    enabled = OSDisableInterrupts();

    for (i = 0; i < 4; i++) {
        q = &WaitingQueue_80339FD8[i];
        if (q->next != q) {
            OSRestoreInterrupts(enabled);
            return 1;
        }
    }

    OSRestoreInterrupts(enabled);
    return 0;
}

s32 fn_8020F7F0(void *arg0) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void **prev;
    void *next;
    s32 enabled;

    enabled = OSDisableInterrupts();
    prev = *(void ***)((char *)arg0 + 4);
    next = *(void **)arg0;
    if (prev == NULL || next == NULL) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    *prev = next;
    *(void **)((char *)next + 4) = prev;
    OSRestoreInterrupts(enabled);
    return 1;
}

u8 ErrorCode2Num(s32 error)
{
    extern u16 lbl_8029D210[];

    u32 *table;
    u32 i;

    table = (u32 *)lbl_8029D210;

    for (i = 0; i < 18; i++) {
        if ((u32)error == table[i]) {
            return (u8)i;
        }
    }

    if ((u32)error >= 0x100000 && (u32)error <= 0x100008) {
        return 0x11;
    }

    return 0x1D;
}

void __DVDStoreErrorCode(u32 arg0) {
    u8 ErrorCode2Num(s32);
    void *__OSLockSramEx(void);
    void __OSUnlockSramEx(s32);
    u8 var_r31;
    u32 temp_r0;
    u32 var_r31_2;
    u8 temp_r3;

    temp_r0 = arg0 + 0xFEDD0000;
    if (temp_r0 == 0x4567U) {
        var_r31 = 0xFFU;
    } else if (temp_r0 == 0x4568U) {
        var_r31 = 0xFEU;
    } else {
        var_r31_2 = arg0 >> 0x18U;
        temp_r3 = ErrorCode2Num(arg0 & 0xFFFFFF);
        if (var_r31_2 >= 6U) {
            var_r31_2 = 6;
        }
        var_r31 = temp_r3 + (var_r31_2 * 0x1E);
    }
    M2C_FIELD(__OSLockSramEx(), u8 *, 0x24) = var_r31;
    __OSUnlockSramEx(1);
}

s32 fn_8020F9E8(u8 *arg0, u8 *arg1)
{
    s32 Str_NCmp(u8 *, u8 *, u32);
    u8 *b;
    u8 *a;

    b = arg1;
    a = arg0;

    if ((s8)a[0] != 0 && (s8)b[0] != 0) {
        if (Str_NCmp(a, b, 4) != 0) {
            return 0;
        }
    }

    if (!((s8)a[4] != 0 && (s8)b[4] != 0 && Str_NCmp(a + 4, b + 4, 2) == 0)) {
        return 0;
    }

    if (a[6] != 0xFF && b[6] != 0xFF) {
        if (a[6] != b[6]) {
            return 0;
        }
    }

    if (a[7] != 0xFF && b[7] != 0xFF) {
        if (a[7] != b[7]) {
            return 0;
        }
    }

    return 1;
}

void fn_8020FAE0(void) {
    if (lbl_803685E8 != NULL) {
        lbl_803685E8();
    }
}
