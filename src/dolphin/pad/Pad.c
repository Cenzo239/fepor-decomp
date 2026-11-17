/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
extern u16 Scb_80339420[];
extern s32 PauseFlag_803685A4;
extern s32 PausingFlag_803685A8;
extern void* executing_80368598;
extern u32 lbl_803685B8;
extern void (*lbl_803685BC)(void*, void*);
extern void stateReady(void);
extern void fn_8020F0B8(void *arg0);
extern void __DVDClearWaitingQueue(void);
extern s32 __DVDPopWaitingQueue(void);;
extern s32 gSaveDataBase;;
extern s32 fn_80013E50(s32);
extern s32 fn_80013E60(s32, s32);
extern s32 fn_80013E74(void*, s32);
extern s32 lbl_80366F60;
extern s32 lbl_8029CFE8;

typedef struct PADStatus {
    u16 button;
    s8 stickX;
    s8 stickY;
    s8 substickX;
    s8 substickY;
    u8 triggerLeft;
    u8 triggerRight;
    u8 analogA;
    u8 analogB;
    s8 err;
} PADStatus;


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

volatile u16 OS_DSPRegs[64] : 0xCC005000;

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

extern s32* FstStart_8036857C;
extern s32 currentDirectory;

extern u16 Scb_803394;

u32 __OSGetResetSWState(void);

extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);

extern u16 Scb_80339420[4];
extern u16 lbl_80282268[8];
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
extern u16 lbl_8029D210[];

static void PADDisable(s32 chan) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void fn_80209C10(s32 chan, u16 id);
    u32 fn_8023B930(u32 poll);
    extern u32 EnabledBits;
    extern u32 WaitingBits;
    extern u32 CheckingBits;
    extern u32 lbl_80368680;
    extern u32 __PADFixBits;
    s32 enabled;
    u32 chanBit;

    enabled = OSDisableInterrupts();
    chanBit = 0x80000000 >> chan;
    fn_8023B930(chanBit);
    EnabledBits &= ~chanBit;
    WaitingBits &= ~chanBit;
    CheckingBits &= ~chanBit;
    lbl_80368680 &= ~chanBit;
    __PADFixBits &= ~chanBit;
    fn_80209C10(chan, 0);
    OSRestoreInterrupts(enabled);
}

void fn_80211F78(s32 arg0, s32 arg1) {
    extern s32 lbl_80366FA4;
    extern s32 lbl_80366FAC;
    extern s32 lbl_8036866C;
    extern s32 lbl_80368670;
    extern char lbl_8033A1C0[];
    extern void fn_802121E0(void);
    void fn_80211DD4(s32);
    void fn_8023BA70(s32, void *);
    void fn_8023B804(s32, s32);
    void fn_8023B894(s32);
    void fn_8023C188(s32, void *);
    void *memset(void *, int, unsigned int);
    s32 r31;
    char buf[24];

    if (!(arg1 & 0xF)) {
        fn_80211DD4(lbl_80366FA4);
        r31 = lbl_80366FA4;
        lbl_8036866C |= 0x80000000U >> r31;
        fn_8023BA70(r31, buf);
        fn_8023B804(r31, lbl_80366FAC | 0x400000);
        fn_8023B894(lbl_8036866C);
    }
    lbl_80366FA4 = __cntlzw(lbl_80368670);
    if (lbl_80366FA4 != 0x20) {
        lbl_80368670 &= ~(0x80000000U >> lbl_80366FA4);
        memset(lbl_8033A1C0 + (lbl_80366FA4 * 0xC), 0, 0xC);
        fn_8023C188(lbl_80366FA4, fn_802121E0);
    }
}

void PADOriginCallback(s32 chan, u32 error) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void fn_80209C10(s32 chan, u16 id);
    u32 fn_8023B930(u32 poll);
    void fn_80211DD4(s32);
    extern u32 EnabledBits;
    extern u32 WaitingBits;
    extern u32 CheckingBits;
    extern u32 lbl_80368680;
    extern u32 __PADFixBits;
    u32 e;
    u32 chanBit;
    s32 c;
    u32 bitConst;

    e = error;
    c = chan;
    bitConst = 0x80000000;
    chanBit = bitConst >> chan;
    if (!(EnabledBits & chanBit)) {
        return;
    }
    if (!(e & 0xF)) {
        fn_80211DD4(c);
    }
    if (e & 8) {
        e = OSDisableInterrupts();
        fn_8023B930(chanBit);
        EnabledBits &= ~chanBit;
        WaitingBits &= ~chanBit;
        CheckingBits &= ~chanBit;
        lbl_80368680 &= ~chanBit;
        __PADFixBits &= ~chanBit;
        fn_80209C10(c, 0);
        OSRestoreInterrupts(e);
    }
}

void fn_80212108(s32 chan, u32 type) {
    void fn_8023B804(s32, u32);
    void fn_8023B894(u32);
    void fn_8023BA70(s32, u32 *);
    void fn_8023C188(s32, void (*)(s32, u32));
    void memset(void *, int, u32);
    extern void fn_802121E0(s32, u32);
    extern u8 lbl_8033A1C0[];
    extern s32 lbl_80366FA4;
    extern u32 lbl_80366FAC;
    extern u32 lbl_8036866C;
    extern u32 lbl_80368670;
    extern u32 lbl_80368678;
    u32 sr[2];
    u32 pad[2];
    u32 chanBit;
    u32 bit;
    u32 bitConst;

    (void)pad;
    if (!(type & 0xF)) {
        bitConst = 0x80000000U;
        chanBit = lbl_80366FA4;
        lbl_8036866C |= bitConst >> chanBit;
        fn_8023BA70(chanBit, sr);
        fn_8023B804(chanBit, lbl_80366FAC | 0x400000);
        fn_8023B894(lbl_8036866C);
        lbl_80368678 |= bitConst >> lbl_80366FA4;
    }
    bit = lbl_80368670;
    lbl_80366FA4 = __cntlzw(bit);
    if (lbl_80366FA4 != 0x20) {
        lbl_80368670 = bit & ~(0x80000000U >> lbl_80366FA4);
        memset(&lbl_8033A1C0[lbl_80366FA4 * 12], 0, 12);
        fn_8023C188(lbl_80366FA4, fn_802121E0);
    }
}

/* On SI type/status: GetOrigin if a standard PAD, else disable the channel. */
void PADTypeAndStatusCallback(s32 chan, u32 type) {
    s32 SITransfer(s32 chan, void *output, u32 outputBytes, void *input, u32 inputBytes, void *callback, s64 delay);
    void PADOriginCallback(s32 chan, u32 error);
    extern u8 Origin[];
    extern u32 cmdGetOrigin;
    extern u32 EnabledBits;
    extern u32 WaitingBits;
    extern u32 CheckingBits;
    u32 error;
    u32 chanBit;

    chanBit = 0x80000000 >> chan;
    if (!(EnabledBits & chanBit)) {
        return;
    }

    error = type & 0xFF;
    type &= ~0xFF;

    WaitingBits &= ~chanBit;
    CheckingBits &= ~chanBit;

    if (!(error & 0xF) && (type & 0x80000000) && (type & 0x00100000) && (type & 0x40000000) &&
        !(type & 0x04000000) && !(type & 0x00080000) && !(type & 0x00040000)) {
        SITransfer(chan, &cmdGetOrigin, 1, &Origin[chan * 0xC], 10, PADOriginCallback, 0);
    } else {
        PADDisable(chan);
    }
}

s32 fn_8021264C(u32 mask) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void fn_8023B930(u32);
    void fn_8023C188(s32, void (*)(void));
    void fn_802121E0(void);
    void *memset(void *, s32, u32);
    extern u8 Origin[];
    extern u32 lbl_80368680, WaitingBits, CheckingBits, lbl_80368670, lbl_80366FB0, EnabledBits, __PADFixBits, lbl_80368674;
    extern s32 lbl_80366FA4;
    s32 interrupts;
    u32 disable;
    interrupts=OSDisableInterrupts();
    mask |= lbl_80368680;
    mask &= ~(WaitingBits | CheckingBits);
    lbl_80368670 |= mask;
    lbl_80368680=0;
    disable=lbl_80368670 & EnabledBits;
    EnabledBits &= ~mask;
    __PADFixBits &= ~mask;
    if (lbl_80366FB0==4) lbl_80368674 |= mask;
    fn_8023B930(disable);
    if (lbl_80366FA4==32) {
        lbl_80366FA4=__cntlzw(lbl_80368670);
        if (lbl_80366FA4!=32) {
            lbl_80368670 &= ~(0x80000000U >> lbl_80366FA4);
            memset(Origin+lbl_80366FA4*12,0,12);
            fn_8023C188(lbl_80366FA4,fn_802121E0);
        }
    }
    OSRestoreInterrupts(interrupts);
    return 1;
}

s32 fn_8021275C(u32 mask) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void fn_8023B930(u32);
    void fn_8023C188(s32, void (*)(void));
    void fn_802121E0(void);
    void *memset(void *, s32, u32);
    extern u8 Origin[];
    extern u32 lbl_80368680, WaitingBits, CheckingBits, lbl_80368670, lbl_80366FB0, EnabledBits, __PADFixBits, lbl_80368674;
    extern s32 lbl_80366FA4;
    u32 flags;
    u32 disable;
    s32 interrupts;
    interrupts=OSDisableInterrupts();
    mask |= lbl_80368680;
    mask &= ~(WaitingBits | CheckingBits);
    flags = *(u8 *)0x800030E3;
    lbl_80368670 |= mask;
    lbl_80368680=0;
    disable=lbl_80368670 & EnabledBits;
    EnabledBits &= ~mask;
    __PADFixBits &= ~mask;
    if (!(flags & 0x40)) lbl_80368674 |= mask;
    fn_8023B930(disable);
    if (lbl_80366FA4==32) {
        lbl_80366FA4=__cntlzw(lbl_80368670);
        if (lbl_80366FA4!=32) {
            lbl_80368670 &= ~(0x80000000U >> lbl_80366FA4);
            memset(Origin+lbl_80366FA4*12,0,12);
            fn_8023C188(lbl_80366FA4,fn_802121E0);
        }
    }
    OSRestoreInterrupts(interrupts);
    return 1;
}

s32 fn_80212870(void) {
extern s32 lbl_80368668;
extern char *lbl_80366FA0;
extern u32 __PADSpec, lbl_80368820, lbl_80368674;
extern u32 PADType[];
extern OSResetFunctionInfo lbl_8029D6F8;
void OSRegisterVersion(const char *);
void PADSetSpec(u32);
s64 OSGetTime(void);
void fn_8023C518(void);
s32 fn_8021264C(u32);
s64 time;
u64 sum;
u32 *types = PADType;
if (lbl_80368668) return 1;
OSRegisterVersion(lbl_80366FA0);
if (__PADSpec) PADSetSpec(__PADSpec);
lbl_80368668 = 1;
if (lbl_80368820) {
time = OSGetTime();
sum = (time & 0xffff) + ((time >> 16) & 0xffff) + ((time >> 32) & 0xffff) + ((time >> 48) & 0xffff);
lbl_80368674 = 0xf0000000;
*(u16 *)0x800030e0 = sum & 0x3fff;
}
types[16] = ((*(u16 *)0x800030e0 & 0x3fff) << 8) | 0x4d000000;
types[17] = ((*(u16 *)0x800030e0 & 0x3fff) << 8) | 0x4d400000;
types[18] = ((*(u16 *)0x800030e0 & 0x3fff) << 8) | 0x4d800000;
types[19] = ((*(u16 *)0x800030e0 & 0x3fff) << 8) | 0x4dc00000;
fn_8023C518();
OSRegisterResetFunction(&lbl_8029D6F8);
return fn_8021264C(0xf0000000);
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
u32 fn_802129C0(PADStatus *status)
{
  s32 OSDisableInterrupts(void);
  void OSRestoreInterrupts(s32);
  s32 fn_8021264C(u32);
  s32 fn_8023ABF4(s32);
  u32 fn_8023B788(s32);
  u32 SIGetType(s32);
  s32 fn_8023BA70(s32, void *);
  void fn_8023C188(s32, void *);
  void PADOriginCallback(s32 chan, u32 error);
  void PADTypeAndStatusCallback(s32, u32);
  s32 SITransfer(s32, void *, u32, void *, u32, void *, s64);
  void *memset(void *, s32, u32);
  extern u8 Origin[];
  extern s32 lbl_80366FA4;
  extern u16 cmdGetOrigin;
  extern u32 EnabledBits;
  extern u32 lbl_80368670;
  extern u32 WaitingBits;
  extern u32 CheckingBits;
  extern u32 lbl_80368680;
  extern void (*lbl_80366FB4)(s32, PADStatus *, u32 *);
  u64 response;
  u8 *origin;
  s32 enabled;
  s32 chan;
  u32 result;
  u32 bit;
  u32 offset;
  enabled = OSDisableInterrupts();
  chan = (result = 0);
  offset = chan * 12;
  origin = Origin + offset;
  do
  {
    bit = 0x80000000U >> chan;
    if (lbl_80368680 & bit)
    {
      fn_8021264C(0);
      status->err = -2;
      memset(status, 0, 10);
    }
    else if ((lbl_80368670 & bit) || (lbl_80366FA4 == chan))
    {
      status->err = -2;
      memset(status, 0, 10);
    }
    else if (!(EnabledBits & bit))
    {
      status->err = -1;
      memset(status, 0, 10);
    }
    else if (fn_8023ABF4(chan))
    {
      status->err = -3;
      memset(status, 0, 10);
    }
    else if (fn_8023B788(chan) & 8)
    {
      fn_8023BA70(chan, (u32 *) (&response));
      if (WaitingBits & bit)
      {
        status->err = 0;
        memset(status, 0, 10);
        if (!(CheckingBits & bit))
        {
          CheckingBits |= bit;
          fn_8023C188(chan, PADTypeAndStatusCallback);
        }
      }
      else
      {
        PADDisable(chan);
        status->err = -1;
        memset(status, 0, 10);
      }
    }
    else
    {
      if (!(SIGetType(chan) & 0x20000000))
      {
        result |= bit;
      }
      if (!fn_8023BA70(chan, (u32 *) (&response)))
      {
        status->err = -3;
        memset(status, 0, 10);
      }
      else if (((u32 *) (&response))[0] & 0x80000000)
      {
        status->err = -3;
        memset(status, 0, 10);
      }
      else
      {
        lbl_80366FB4(chan, status, (u32 *) (&response));
        if (status->button & 0x2000)
        {
          status->err = -3;
          memset(status, 0, 10);
          SITransfer(chan, &cmdGetOrigin, 1, origin, 10, PADOriginCallback, 0);
        }
        else
        {
          status->err = 0;
          status->button &= ~0x80;
        }
      }
    }
    chan++;
    origin += 12;
    status++;
  }
  while (chan < 4);
  OSRestoreInterrupts(enabled);
  return result;
}
#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset
void fn_80212CC0(s32 arg0, u32 arg1) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s32 SIGetType(s32);
    void fn_8023B804(s32, u32);
    void fn_8023B818(void);
    extern s32 EnabledBits;
    extern u32 lbl_80366FB0;
    extern u32 PADSpec;
    s32 enabled;
    u32 var_r30;
    s32 pad;

    var_r30 = arg1;
    enabled = OSDisableInterrupts();
    if ((EnabledBits & (0x80000000U >> arg0)) && (SIGetType(arg0) & 0x20000000) == 0) {
        if (lbl_80366FB0 < 2U && var_r30 == 2) {
            var_r30 = 0;
        }
        if (*(u8 *)0x800030E3 & 0x20) {
            var_r30 = 0;
        }
        fn_8023B804(arg0, PADSpec | 0x400000 | (var_r30 & 3));
        fn_8023B818();
    }
    OSRestoreInterrupts(enabled);
}

void PADSetSpec(s32 arg0)
{
    extern s32 __PADSpec;
    extern s32 lbl_80366FB0;
    extern void (*lbl_80366FB4)(s32, PADStatus *, u32 *);
    void SPEC0_MakeStatus(s32, PADStatus *, u32 *);
    void SPEC1_MakeStatus(s32, PADStatus *, u32 *);
    void PADMakeStatus(s32, PADStatus *, u32 *);

    __PADSpec = 0;
    switch (arg0) {
    case 0:
        lbl_80366FB4 = SPEC0_MakeStatus;
        break;
    case 1:
        lbl_80366FB4 = SPEC1_MakeStatus;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        lbl_80366FB4 = PADMakeStatus;
        break;
    }
    lbl_80366FB0 = arg0;
}

/* Decode raw PAD transfer words into a PADStatus using the SPEC0 bit layout. */
void SPEC0_MakeStatus(s32 chan, PADStatus *status, u32 *data) {
    status->button = 0;
    status->button |= ((data[0] >> 16) & 0x0008) ? 0x0100 : 0;
    status->button |= ((data[0] >> 16) & 0x0020) ? 0x0200 : 0;
    status->button |= ((data[0] >> 16) & 0x0100) ? 0x0400 : 0;
    status->button |= ((data[0] >> 16) & 0x0001) ? 0x0800 : 0;
    status->button |= ((data[0] >> 16) & 0x0010) ? 0x1000 : 0;

    status->stickX = (s8)(data[1] >> 16);
    status->stickY = (s8)(data[1] >> 24);
    status->substickX = (s8)(data[1]);
    status->substickY = (s8)(data[1] >> 8);

    status->triggerLeft = (u8)(data[0] >> 8) & 0xFF;
    status->triggerRight = (u8)data[0] & 0xFF;

    status->analogA = 0;
    status->analogB = 0;

    if (170 <= status->triggerLeft) {
        status->button |= 0x0040;
    }
    if (170 <= status->triggerRight) {
        status->button |= 0x0020;
    }

    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
}

/* Decode raw PAD transfer words into a PADStatus using the SPEC1 bit layout. */
void SPEC1_MakeStatus(s32 chan, PADStatus *status, u32 *data) {
    status->button = 0;
    status->button |= ((data[0] >> 16) & 0x0080) ? 0x0100 : 0;
    status->button |= ((data[0] >> 16) & 0x0100) ? 0x0200 : 0;
    status->button |= ((data[0] >> 16) & 0x0020) ? 0x0400 : 0;
    status->button |= ((data[0] >> 16) & 0x0010) ? 0x0800 : 0;
    status->button |= ((data[0] >> 16) & 0x0200) ? 0x1000 : 0;

    status->stickX = (s8)(data[1] >> 16);
    status->stickY = (s8)(data[1] >> 24);
    status->substickX = (s8)(data[1]);
    status->substickY = (s8)(data[1] >> 8);

    status->triggerLeft = (u8)(data[0] >> 8) & 0xFF;
    status->triggerRight = (u8)data[0] & 0xFF;

    status->analogA = 0;
    status->analogB = 0;

    if (170 <= status->triggerLeft) {
        status->button |= 0x0040;
    }
    if (170 <= status->triggerRight) {
        status->button |= 0x0020;
    }

    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
}

static void ClampS8(s8* p, s8 o) {
    s8 s = *p;
    s8 m;
    if (0 < o) {
        m = (s8)(o - 128);
        if (s < m) {
            s = m;
        }
    } else if (o < 0) {
        m = (s8)(o + 127);
        if (m < s) {
            s = m;
        }
    }
    s -= o;
    *p = s;
}

static void ClampU8(u8* p, u8 o) {
    u8 s = *p;
    if (s < o) {
        s = o;
    }
    s -= o;
    *p = s;
}

/* Decode raw PAD transfer words into a calibrated PADStatus for one channel. */
void PADMakeStatus(s32 chan, PADStatus* status, u32* data) {
    extern u32 PADSpec;
    extern u32 PADType[];
    extern u32 __PADFixBits;
    extern u8 Origin[];
    u8* origin;

    status->button = (u16)((data[0] >> 16) & 0x3fff);
    status->stickX = (s8)(data[0] >> 8);
    status->stickY = (s8)(data[0] >> 0);

    switch (PADSpec & 0x700) {
    case 0x000:
    case 0x500:
    case 0x600:
    case 0x700:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)((data[1] >> 8) & 0xf0);
        status->triggerRight = (u8)((data[1] >> 4) & 0xf0);
        status->analogA = (u8)(data[1] & 0xf0);
        status->analogB = (u8)((data[1] << 4) & 0xf0);
        break;
    case 0x100:
        status->substickX = (s8)(s32)((data[1] >> 24) & 0xf0);
        status->substickY = (s8)(s32)((data[1] >> 20) & 0xf0);
        status->triggerLeft = (u8)(data[1] >> 16);
        status->triggerRight = (u8)(data[1] >> 8);
        status->analogA = (u8)(data[1] & 0xf0);
        status->analogB = (u8)((data[1] << 4) & 0xf0);
        break;
    case 0x200:
        status->substickX = (s8)(s32)((data[1] >> 24) & 0xf0);
        status->substickY = (s8)(s32)((data[1] >> 20) & 0xf0);
        status->triggerLeft = (u8)((data[1] >> 16) & 0xf0);
        status->triggerRight = (u8)((data[1] >> 12) & 0xf0);
        status->analogA = (u8)(data[1] >> 8);
        status->analogB = (u8)(data[1] >> 0);
        break;
    case 0x300:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)(data[1] >> 8);
        status->triggerRight = (u8)(data[1] >> 0);
        status->analogA = 0;
        status->analogB = 0;
        break;
    case 0x400:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = 0;
        status->triggerRight = 0;
        status->analogA = (u8)(data[1] >> 8);
        status->analogB = (u8)(data[1] >> 0);
        break;
    }

    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;

    if (((PADType[chan] & 0xffff0000) == 0x09000000) &&
        ((status->button & 0x0080) ^ 0x0080)) {
        __PADFixBits |= 0x80000000U >> chan;
        status->stickX = 0;
        status->stickY = 0;
        status->substickX = 0;
        status->substickY = 0;
        return;
    }

    __PADFixBits &= ~(0x80000000U >> chan);
    origin = &Origin[chan * 12];

    ClampS8(&status->stickX, (s8)origin[2]);
    ClampS8(&status->stickY, (s8)origin[3]);
    ClampS8(&status->substickX, (s8)origin[4]);
    ClampS8(&status->substickY, (s8)origin[5]);
    ClampU8(&status->triggerLeft, origin[6]);
    ClampU8(&status->triggerRight, origin[7]);
}

#pragma optimization_level 3
s32 fn_80213530(s32 arg0)
{
  s32 fn_8021275C(M2C_UNK);
  int new_var;
  M2C_UNK fn_8021364C(M2C_UNK);
  s32 fn_8023ABD4();
  extern s32 lbl_80366FA4;
  extern u32 lbl_80368670;
  int new_var2;
  extern u32 lbl_80368688;
  extern s32 lbl_8036868C;
  s32 var_r31;
  s32 var_r3;
  if (((u32) lbl_80368688) != 0U)
  {
    fn_8021364C(0);
  }
  if (arg0 == 0)
  {
    var_r31 = 0;
    var_r3 = var_r31;
    new_var2 = ((u32) lbl_80368670) == 0U;
    if (new_var2 && (((s32) lbl_80366FA4) == 0x20))
    {
      var_r3 = 1;
    }
    new_var = 1;
    if ((var_r3 != 0) && (fn_8023ABD4() == 0))
    {
      var_r31 = new_var;
    }
    if ((((s32) lbl_8036868C) == 0) && (var_r31 != 0))
    {
      lbl_8036868C = fn_8021275C(0xF0000000);
      return (int) 0;
    }
    return var_r31;
  }
  lbl_8036868C = 0;
  return 1;
}
#pragma optimization_level reset
void fn_802135EC(s32 arg0, OSContext *context)
{
    extern void (*lbl_80368688)(void);
    void OSClearContext(void *);
    void OSSetCurrentContext(void *);

    OSContext tempContext;

    if (lbl_80368688 != 0) {
        OSClearContext(&tempContext);
        OSSetCurrentContext(&tempContext);

        lbl_80368688();

        OSClearContext(&tempContext);
        OSSetCurrentContext(context);
    }
}

u32 fn_8021364C(u32 arg0) {
    void SIRegisterPollingHandler(void (*)(void));
    void fn_8023B3D4(void (*)(void));
    void fn_802135EC(void);
    extern u32 lbl_80368688;
    u32 prev;

    prev = lbl_80368688;
    lbl_80368688 = arg0;
    if (arg0 != 0) {
        SIRegisterPollingHandler(fn_802135EC);
    } else {
        fn_8023B3D4(fn_802135EC);
    }
    return prev;
}

s32 __PADDisableRecalibration(s32 disable) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s32 enabled;
    s32 interrupted;

    interrupted = OSDisableInterrupts();
    if ((*(u8 *)0x800030E3) & 0x40) {
        enabled = 1;
    } else {
        enabled = 0;
    }
    *(u8 *)0x800030E3 &= ~0x40;
    if (disable != 0) {
        *(u8 *)0x800030E3 |= 0x40;
    }
    OSRestoreInterrupts(interrupted);
    return enabled;
}

extern s32 lbl_8036869C;
s32 fn_8021371C(s32 arg0) {
    extern s32 lbl_8036869C;
    s32 temp_r31;

    temp_r31 = lbl_8036869C;
    OSDisableInterrupts();
    lbl_8036869C = arg0;
    OSRestoreInterrupts();
    return temp_r31;
}

void fn_80213760(u32 arg0, u32 arg1) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    extern volatile u16 __PADRegs[];
    s32 enabled;
    u8 *base;
    u16 t;

    enabled = OSDisableInterrupts();
    base = (u8 *)0xCC000000;
    t = *(u16 *)(base + 0x5030);
    OS_DSPRegs[0x18] = (t & ~0x3FFu) | (arg0 >> 16);
    t = __PADRegs[0x19];
    t = (u16)__rlwinm(t, 0, 27, 15);
    __PADRegs[0x19] = t | (u16)arg0;
    t = *(volatile u16 *)0xCC005036;
    *(volatile u16 *)0xCC005036 = (t & ~0x7FFFu) | (u16)(arg1 >> 5);
    OSRestoreInterrupts(enabled);
}

volatile u16 __PADRegs[32] : 0xCC005000;
void fn_802137E8(void) {
    __PADRegs[0x1B] |= 0x8000;
}

s32 fn_80213800(void) {
    extern volatile u16 __PADRegs[];
    u32 a = __PADRegs[0x18];
    return ((a & 0x3FF) << 16) | (__PADRegs[0x19] & 0xFFE0);
}

s32 fn_8021381C(void) {
    return (*(u16 *)0xCC005036 << 5) & 0xFFFE0;
}

void fn_8021382C(u32 arg0) {
u32 fn_80213904(void);
u32 fn_80213ADC(void);
u32 fn_80213B34(void);
u32 fn_80213B08(void);
void fn_80213B18(u32);
void fn_80213AEC(u32);
void fn_80213E30(void);
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
s32 interrupts;
u32 right, left;
if (arg0 != fn_80213904()) {
if (fn_80213ADC() == 0 && arg0 == 1) {
right=fn_80213B34();
left=fn_80213B08();
fn_80213B18(0);
fn_80213AEC(0);
interrupts=OSDisableInterrupts();
fn_80213E30();
*(volatile u32*)0xCC006C00=(*(volatile u32*)0xCC006C00 & ~0x20) | 0x20;
*(volatile u32*)0xCC006C00=(*(volatile u32*)0xCC006C00 & ~1) | 1;
OSRestoreInterrupts(interrupts);
fn_80213AEC(right);
fn_80213B18(left);
} else {
*(volatile u32*)0xCC006C00=(*(volatile u32*)0xCC006C00 & ~1) | arg0;
}
}
}

s32 fn_80213904(void) {
    return *(s32 *)0xCC006C00 & 1;
}

void fn_80213914(u32 arg0) {
    u32 fn_802139F4(void);
    u32 fn_80213B08(void);
    u32 fn_80213B34(void);
    u32 fn_80213ADC(void);
    void fn_80213AEC(u32);
    void fn_80213B18(u32);
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    void fn_80213E30(void);

    volatile u32 *reg;
    u32 old0;
    u32 old1;
    u32 old2;
    s32 old3;
    u32 interrupts;
    u32 value;

    if (arg0 != fn_802139F4()) {
        reg = (volatile u32 *)0xCC006C00;

        value = *reg;
        *reg = value & ~0x40;

        if (arg0 == 0) {
            old0 = fn_80213B08();
            old1 = fn_80213B34();
            old2 = *reg & 1;
            old3 = fn_80213ADC();

            fn_80213AEC(0);
            fn_80213B18(0);

            interrupts = OSDisableInterrupts();

            fn_80213E30();

            value = *reg;
            value &= ~0x20;
            value |= 0x20;
            *reg = value;

            *reg = (*reg & ~2) | ((u32)old3 << 1);

            value = *reg;
            value &= ~1;
            value |= old2;
            *reg = value;

            value = *reg;
            value |= 0x40;
            *reg = value;

            OSRestoreInterrupts(interrupts);

            fn_80213AEC(old0);
            fn_80213B18(old1);
        }
    }
}

s32 fn_802139F4(void) {
    return (((u32) *(u32 *)0xCC006C00 >> 6U) & 1) ^ 1;
}

void fn_80213A08(u32 arg0) {
u32 fn_80213ADC(void);
u32 fn_80213B08(void);
u32 fn_80213B34(void);
void fn_80213B18(u32);
void fn_80213AEC(u32);
void fn_80213E30(void);
void fn_8021382C(u32);
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
volatile u32 *reg;
s32 interrupts;
u32 play;
u32 left;
u32 right;
u32 rate;
u32 value;
if (arg0 != fn_80213ADC()) {
reg=(volatile u32 *)0xCC006C00;
play=*reg & 1;
left=fn_80213B08();
right=fn_80213B34();
fn_80213B18(0);
fn_80213AEC(0);
value=*reg;
rate=(u32)value & 0x40;
value=*reg;
*reg=(unsigned short)value & ~0x40;
interrupts=OSDisableInterrupts();
fn_80213E30();
*reg |= rate;
value=*reg;
value &= ~0x20;
value |= 0x20;
*reg=value;
value=*reg;
value &= ~2;
*reg=value | (arg0<<1);
OSRestoreInterrupts(interrupts);
fn_8021382C(play);
fn_80213AEC(left);
fn_80213B18(right);
}
}

s32 fn_80213ADC(void) {
    return ((u32) *(u32 *)0xCC006C00 >> 1U) & 1;
}

#pragma peephole off
void fn_80213AEC(s32 arg0) {
    extern volatile u32 OS_AIRegs[8];
    u32 *regs = (u32 *)OS_AIRegs;
    u32 value = regs[1];
    value = __rlwimi(value & 0xFFFFFF00, (u32)arg0, 0, 24, 31);
    regs[1] = value;
}
#pragma peephole on
u8 fn_80213B08(void) {
    return (u8) *(s32 *)0xCC006C04;
}

void fn_80213B18(s32 arg0) {
    extern volatile u32 OS_AIRegs[8];
    u32 *regs = (u32 *)OS_AIRegs;
    u32 value = regs[1];
    value = __rlwimi(value & 0xFFFF00FF, (u32)arg0, 8, 16, 23);
    regs[1] = value;
}

u8 fn_80213B34(void) {
    return (u8) ((u32) *(u32 *)0xCC006C04 >> 8U);
}

void fn_80213B44(s32 arg0) {
void OSRegisterVersion(const char *);
void __OSSetInterruptHandler(s32, void *);
void __OSUnmaskInterrupts(u32);
void fn_80213CB0(void);
void fn_80213D2C(void);
extern char *lbl_80366FC0;
extern s32 lbl_803686A8, lbl_80368698, lbl_8036869C, lbl_803686A0;
extern u64 lbl_803686B0, lbl_803686B8, lbl_803686C0, lbl_803686C8, lbl_803686D0;
extern volatile u32 OS_AIRegs[8];
u32 rate;
u32 *regs = (u32 *)OS_AIRegs;
if(lbl_803686A8 == 1) return;
OSRegisterVersion(lbl_80366FC0);
rate = (*(u32 *)0x800000f8 / 4) / 125000;
lbl_803686B0 = rate * 31524 / 8000;
lbl_803686B8 = rate * 42024 / 8000;
lbl_803686C0 = rate * 42000 / 8000;
lbl_803686C8 = rate * 63000 / 8000;
lbl_803686D0 = rate * 3000 / 8000;
regs[0] = (regs[0] & ~0x20) | 0x20;
regs[1] = __rlwimi(regs[1] & 0xffff00ff, 0, 8, 16, 23);
regs[1] = __rlwimi(regs[1] & 0xffffff00, 0, 0, 24, 31);
regs[3] = 0;
fn_80213A08(1);
fn_80213914(0);
lbl_80368698=0;
lbl_8036869C=0;
lbl_803686A0=arg0;
__OSSetInterruptHandler(5,fn_80213D2C);
__OSUnmaskInterrupts(0x04000000);
__OSSetInterruptHandler(8,fn_80213CB0);
__OSUnmaskInterrupts(0x00800000);
lbl_803686A8=1;
}

void fn_80213CB0(s32 arg0, OSContext *context)
{
    extern void (*lbl_80368698)(u32);
    OSContext tempContext;
    *(u32 *)0xCC006C00 |= 8;
    OSClearContext(&tempContext);
    OSSetCurrentContext(&tempContext);
    if (lbl_80368698 != 0) {
        u32 *regs = (u32 *)0xCC006C00;
        lbl_80368698(regs[2]);
    }
    OSClearContext(&tempContext);
    OSSetCurrentContext(context);
}

void fn_80213D2C(s32 arg0, OSContext *context) {
    void OSClearContext(void *);
    void OSSetCurrentContext(void *);
    void fn_80213DD8(void);
    extern volatile u16 __PADRegs[];
    extern s32 lbl_8036869C;
    extern s32 lbl_803686A0;
    extern s32 lbl_803686AC;
    typedef struct { u8 pad[0xA]; u16 val; } PadReg;
    volatile PadReg *p;
    u16 v;
    OSContext tempContext;

    p = (volatile PadReg *)__PADRegs;
    v = p->val;
    p->val = (u16)((v & -0xA1) | 8);

    OSClearContext(&tempContext);
    OSSetCurrentContext(&tempContext);

    if ((u32)lbl_8036869C != 0 && lbl_803686AC == 0) {
        lbl_803686AC = 1;
        if ((u32)lbl_803686A0 != 0) {
            fn_80213DD8();
        } else {
            ((void (*)(void))lbl_8036869C)();
        }
        lbl_803686AC = 0;
    }

    OSClearContext(&tempContext);
    OSSetCurrentContext(context);
}

void fn_80213DD8(void) {
    void (*funcPtr)(void) = lbl_803685E8;
    if (funcPtr != NULL) {
        funcPtr();
    }
}

extern s32 lbl_803686D8;
s32 fn_80214014(s32 arg0) {
    extern s32 lbl_803686D8;
    s32 temp_r31;

    temp_r31 = lbl_803686D8;
    OSDisableInterrupts();
    lbl_803686D8 = arg0;
    OSRestoreInterrupts();
    return temp_r31;
}

s32 fn_80214058(void) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s32 enabled;
    s32 temp_r31;

    enabled = OSDisableInterrupts();
    temp_r31 = *(u16 *)0xCC00500A & 0x200;
    OSRestoreInterrupts(enabled);
    return temp_r31;
}

void fn_80214094(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s32 enabled;
    u32 ha;
    u32 t;

    enabled = OSDisableInterrupts();
    ha = 0xCC000000U;
    t = *(u16 *)(ha + 0x5020);
    *(u16 *)(ha + 0x5020) = (t & ~0x3FFu) | (arg1 >> 16);
    t = *(u16 *)(ha + 0x5022);
    *(u16 *)(ha + 0x5022) = __rlwinm(t, 0, 27, 15) | (arg1 & 0xFFFF);
    t = *(u16 *)(ha + 0x5024);
    *(u16 *)(ha + 0x5024) = (t & ~0x3FFu) | (arg2 >> 16);
    t = *(u16 *)(ha + 0x5026);
    *(u16 *)(ha + 0x5026) = __rlwinm(t, 0, 27, 15) | (arg2 & 0xFFFF);
    t = *(u16 *)(ha + 0x5028);
    t = __rlwinm(t, 0, 17, 15);
    t = __rlwimi(t, arg0, 15, 0, 16);
    *(u16 *)(ha + 0x5028) = t;
    t = *(u16 *)(ha + 0x5028);
    *(u16 *)(ha + 0x5028) = (t & ~0x3FFu) | (arg3 >> 16);
    t = *(u16 *)(ha + 0x502A);
    *(u16 *)(ha + 0x502A) = __rlwinm(t, 0, 27, 15) | (arg3 & 0xFFFF);
    OSRestoreInterrupts(enabled);
}

#pragma peephole off
s32 fn_80214184(s32 arg0) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    extern s32 lbl_803686E8;
    extern s32 lbl_803686EC;
    extern s32 lbl_803686F0;
    unsigned long old;
    s32 enabled;

    enabled = OSDisableInterrupts();
    old = lbl_803686E8;
    lbl_803686E8 = old + arg0;
    *(s32 *)lbl_803686F0 = arg0;
    lbl_803686F0 = lbl_803686F0 + 4;
    lbl_803686EC = lbl_803686EC - 1;
    OSRestoreInterrupts(enabled);
    return old;
}

#pragma peephole off
s32 fn_802141EC(void *arg0, s32 arg1) {
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
void OSRegisterVersion(const char *);
void fn_802142C0(s32, OSContext *);
void fn_80214368(void);
extern char *lbl_80366FC8;
extern s32 lbl_803686F4;
extern s32 lbl_803686E8;
extern s32 lbl_803686EC;
extern s32 lbl_803686F0;
typedef struct { u8 pad[0x1a]; u16 val; } PadInitReg;
s32 enabled;
volatile PadInitReg *regs;
u32 value;
if (lbl_803686F4 == 1) return 0x4000;
OSRegisterVersion(lbl_80366FC8);
enabled=OSDisableInterrupts();
lbl_803686D8=0;
__OSSetInterruptHandler(6,fn_802142C0);
__OSUnmaskInterrupts(0x02000000);
lbl_803686EC=arg1;
lbl_803686E8=0x4000;
lbl_803686F0=(s32)arg0;
regs=(volatile PadInitReg *)__PADRegs;
value=regs->val;
value &= ~0xff;
value = __rlwimi(value, *(volatile u16 *)0xCC00501A,0,24,31);
regs->val = value;
fn_80214368();
lbl_803686F4=1;
OSRestoreInterrupts(enabled);
return lbl_803686E8;
}
#pragma peephole on
s32 fn_802142B0(void) {
    return 0x4000;
}

s32 fn_802142B8(void) {
    extern s32 lbl_803686DC;
    return lbl_803686DC;
}

void fn_802142C0(s32 arg0, OSContext *context)
{
    void OSClearContext(void *);
    void OSSetCurrentContext(void *);
    extern volatile u16 __PADRegs[];
    typedef struct { u8 pad[0xA]; u16 val; } PadReg;
    volatile PadReg *p;
    u16 v;
    OSContext tempContext;

    p = (volatile PadReg *)__PADRegs;
    v = p->val;
    p->val = (u16)((v & -0x89) | 0x20);

    OSClearContext(&tempContext);
    OSSetCurrentContext(&tempContext);

    if ((u32)lbl_803686D8 != 0) {
        ((void (*)(void))lbl_803686D8)();
    }

    OSClearContext(&tempContext);
    OSSetCurrentContext(context);
}

void fn_80214338(void) {
    extern volatile u16 __PADRegs[];
    typedef struct { u8 pad[0xA]; u16 val; } PadReg;
    volatile PadReg *p;
    u16 v;
    p = (volatile PadReg *)__PADRegs;
    v = p->val;
    p->val = (u16)((v & -0x89) | 0x20);
}

s32 fn_80214358(void) {
    return *(u16 *)0xCC00500A & 0x20;
}

extern u32 lbl_803686E0;
extern u32 lbl_803686E4;
void DCFlushRange(void *, u32);
void DCInvalidateRange(void *, u32);
void *memset(void *, int, u32);
void PPCSync(void);
void fn_80214368(void) {
    volatile u16 *regs;
    u32 *bufA;
    u32 *bufB;
    u32 fill0;
    u32 fill1;
    u32 *slots[6];
    u32 saved[6];
    u32 tmp;
    u32 i;
    u8 stack[0x2C0] __attribute__((aligned(32)));
    typedef struct { u8 pad[0xA]; u16 val; } PadReg;
    volatile PadReg *p;
    u16 v;

    regs = __PADRegs;
    if ((regs[0x0B] & 1) == 0) {
        return;
    }

    fill0 = 0xDEADBEF;
    fill1 = 0xBAD0BAD0;
    bufA = (u32 *)((u32)stack + 0x1E0);
    bufB = (u32 *)((u32)stack + 0x1A0);
    for (i = 0; i < 8; i++) {
        bufA[i] = fill0;
        bufB[i] = fill1;
    }

    lbl_803686E0 = 0x100;
    regs[9] = (u16)((regs[9] & ~0x3F) | 0x23);

    slots[0] = (u32 *)((u32)stack + 0x20);
    slots[1] = (u32 *)((u32)stack + 0x60);
    slots[2] = (u32 *)((u32)stack + 0xA0);
    slots[3] = (u32 *)((u32)stack + 0xC0);
    slots[4] = (u32 *)((u32)stack + 0xE0);
    slots[5] = (u32 *)((u32)stack + 0x160);

    DCFlushRange(bufA, 0x20);
    DCFlushRange(bufB, 0x20);
    lbl_803686E4 = 0;
    DCInvalidateRange(slots[4], 0x20);

    regs[0x10] = (u16)((regs[0x10] & 0xFC00) | ((u32)slots[4] >> 16));
    regs[0x11] = (u16)((regs[0x11] & 0x001F) | (u16)(u32)slots[4]);
    regs[0x12] = (u16)((regs[0x12] & 0xFC00) | 0x10);
    regs[0x13] = (u16)((regs[0x13] & 0x001F) | 0);
    regs[0x14] = regs[0x14] | 0x8000;
    regs[0x14] = (u16)(regs[0x14] & 0x03FF);
    regs[0x15] = (u16)((regs[0x15] & 0x001F) | 0x20);

    p = (volatile PadReg *)regs;
    if ((p->val & 0x400) == 0) {
        v = p->val;
        p->val = (u16)((v & ~0x77) | 0x20);
        PPCSync();
    } else {
        memset(slots[5], 0, 0x20);
        DCFlushRange(slots[5], 0x20);
    }
}

void fn_80215B5C(void) {
extern u32 *lbl_80368700, *lbl_8036870C;
extern u32 lbl_80368714, lbl_80368718;
void fn_80214094(u32,u32,u32,u32);
if (!lbl_8036870C && lbl_80368700) {
lbl_8036870C=lbl_80368700;
lbl_80368700=(u32*)lbl_80368700[0];
}
if (lbl_8036870C) {
if (lbl_8036870C[6] <= lbl_80368718) {
if (lbl_8036870C[2]==0)
fn_80214094(lbl_8036870C[2],lbl_8036870C[4],lbl_8036870C[5],lbl_8036870C[6]);
else
fn_80214094(lbl_8036870C[2],lbl_8036870C[5],lbl_8036870C[4],lbl_8036870C[6]);
lbl_80368714=lbl_8036870C[7];
} else {
if (lbl_8036870C[2]==0)
fn_80214094(lbl_8036870C[2],lbl_8036870C[4],lbl_8036870C[5],lbl_80368718);
else
fn_80214094(lbl_8036870C[2],lbl_8036870C[5],lbl_8036870C[4],lbl_80368718);
}
lbl_8036870C[6]-=lbl_80368718;
lbl_8036870C[4]+=lbl_80368718;
lbl_8036870C[5]+=lbl_80368718;
}
}

void fn_80215C5C(void) {

}

void fn_80215C60(void) {
extern void (*lbl_80368710)(void *);
extern void (*lbl_80368714)(void *);
extern void *lbl_80368708;
extern void *lbl_8036870C;
extern u32 *lbl_803686F8;
void fn_80214094(u32,u32,u32,u32);
void fn_80215B5C(void);
u32 *request;
if (lbl_80368710) {
lbl_80368710(lbl_80368708);
lbl_80368708=0;
lbl_80368710=0;
} else if (lbl_80368714) {
lbl_80368714(lbl_8036870C);
lbl_8036870C=0;
lbl_80368714=0;
}
request=lbl_803686F8;
if (request) {
if (request[2]==0) fn_80214094(request[2],request[4],request[5],request[6]);
else fn_80214094(request[2],request[5],request[4],request[6]);
request=lbl_803686F8;
lbl_80368710=(void (*)(void *))request[7];
lbl_80368708=request;
lbl_803686F8=(u32 *)request[0];
}
if (!lbl_80368708) fn_80215B5C();
}

#pragma dont_inline on
void fn_80215D2C(void) {
    extern s32 lbl_8036871C;
    extern s32 lbl_80366FD0;
    extern s32 lbl_80368700;
    extern s32 lbl_803686F8;
    extern s32 lbl_80368718;
    extern s32 lbl_80368708;
    extern s32 lbl_8036870C;
    extern s32 lbl_80368710;
    extern s32 lbl_80368714;
    s32 fn_80214014(s32);
    void fn_80215C60(void);

    if (lbl_8036871C == 1) {
        return;
    }
    OSRegisterVersion(lbl_80366FD0);
    lbl_80368700 = 0;
    lbl_803686F8 = 0;
    lbl_80368718 = 0x1000;
    fn_80214014((s32)fn_80215C60);
    lbl_80368708 = 0;
    lbl_8036870C = 0;
    lbl_80368710 = 0;
    lbl_80368714 = 0;
    lbl_8036871C = 1;
}
#pragma dont_inline reset
void ARQPostRequest(u32 *request, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, s32 arg6, void *arg7) {
extern u32 *lbl_80368700,*lbl_80368704,*lbl_803686F8,*lbl_803686FC,*lbl_80368708,*lbl_8036870C;
extern u32 lbl_80368710;
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
void fn_80214094(u32,u32,u32,u32);
s32 enabled;
u32 *next;
request[0]=0;
request[1]=arg1;
request[2]=arg2;
request[4]=arg4;
request[5]=(u32)arg5;
request[6]=arg6;
if(arg7) request[7]=(u32)arg7;
else request[7]=(u32)fn_80215C5C;
enabled=OSDisableInterrupts();
switch(arg3) {
case 0:
if(lbl_80368700) lbl_80368704[0]=(u32)request;
else lbl_80368700=request;
lbl_80368704=request;
break;
case 1:
if(lbl_803686F8) lbl_803686FC[0]=(u32)request;
else lbl_803686F8=request;
lbl_803686FC=request;
break;
}
if(!lbl_80368708 && !lbl_8036870C) {
next=lbl_803686F8;
if(next) {
if(next[2]==0) fn_80214094(next[2],next[4],next[5],next[6]);
else fn_80214094(next[2],next[5],next[4],next[6]);
next=lbl_803686F8;
lbl_80368710=next[7];
lbl_80368708=next;
lbl_803686F8=(u32*)next[0];
}
if(!lbl_80368708) fn_80215B5C();
}
OSRestoreInterrupts(enabled);
}

void fn_80215EF8(void) {
    extern s32 lbl_803686F8;
    extern s32 lbl_803686FC;
    extern s32 lbl_80368700;
    extern s32 lbl_80368704;
    OSDisableInterrupts();
    lbl_803686F8 = 0;
    lbl_803686FC = 0;
    lbl_80368700 = 0;
    lbl_80368704 = 0;
    OSRestoreInterrupts();
}

s32 fn_80215F30(void) {
    extern s32 lbl_80368718;
    return lbl_80368718;
}

s32 fn_80215F38(void) {
    extern s32 lbl_8036871C;
    return lbl_8036871C;
}

s32 fn_80215F40(void) {
    return ((u16) *(u16 *)0xCC005000 >> 0xFU) & 1;
}

s32 fn_80215F50(void) {
    return ((u16) *(u16 *)0xCC005004 >> 0xFU) & 1;
}

s32 fn_80215F60(void) {
    return (__PADRegs[2] << 16) | __PADRegs[3];
}

#pragma global_optimizer off
void fn_80215F78(u32 arg0)
{
    extern volatile u16 __PADRegs[];

    __PADRegs[0] = (u16)(arg0 >> 16);
    __PADRegs[1] = (u16)arg0;
}

#pragma global_optimizer off
void fn_80215F8C(void) {
void fn_802160C0(char *, ...);
void fn_80216110(s32, OSContext *);
void OSRegisterVersion(const char *);
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
extern char lbl_8029D7E0[];
extern char *lbl_80366FD8;
extern s32 lbl_80368720;
extern void *lbl_80368730;
extern void *lbl_8036873C;
extern void *lbl_80368734;
extern void *lbl_80368738;
typedef struct { u8 pad[0xa]; u16 val; } PadReg;
s32 enabled;
volatile PadReg *p;
u16 v;
fn_802160C0(lbl_8029D7E0+0x48,lbl_8029D7E0+0x68,lbl_8029D7E0+0x74);
if (lbl_80368720 != 1) {
OSRegisterVersion(lbl_80366FD8);
enabled=OSDisableInterrupts();
__OSSetInterruptHandler(7,fn_80216110);
__OSUnmaskInterrupts(0x01000000);
p=(volatile PadReg *)__PADRegs;
p->val=(p->val & ~0xa8)|0x800;
v=p->val;
p->val=v & ~0xac;
lbl_80368730=0;
lbl_8036873C=0;
lbl_80368734=0;
lbl_80368738=0;
lbl_80368720=1;
OSRestoreInterrupts(enabled);
}
}
#pragma global_optimizer on
void *fn_80216050(void *arg0) {
extern void *lbl_80368738;
void fn_80216860(void *); void fn_802166D4(void *); void OSRestoreInterrupts(s32); s32 OSDisableInterrupts(void);
s32 enabled=OSDisableInterrupts();
fn_80216860(arg0);
*(s32 *)arg0=0;
*((s32 *)arg0+2)=1;
OSRestoreInterrupts(enabled);
if(arg0==lbl_80368738) fn_802166D4(arg0);
return arg0;
}

void fn_802160C0(u8 level, char *fmt, ...) {
}

void fn_80216110(s32 arg0, OSContext *ctx) {
    void OSClearContext(void *);
    void OSSetCurrentContext(void *);
    u32 fn_80215F40(void);
    u32 fn_80215F50(void);
    s32 fn_80215F60(void);
    void fn_80215F78(s32);
    void fn_80216534(void *, void *);
    void fn_80216900(void *);
    extern s32 lbl_80368728;
    extern void *lbl_8036872C;
    extern void *lbl_80368734;
    extern void *lbl_80368738;
    extern void *lbl_8036873C;
    extern volatile u16 __PADRegs[];

    typedef struct { u8 pad[0xA]; u16 val; } PadReg;
    struct Node {
        s32 state;
        s32 unk04;
        s32 unk08;
        u8 pad[0x1C];
        void (*cb28)(void);
        void (*cb2C)(void);
        void (*cb30)(void *);
        void (*cb34)(void *);
        struct Node *next;
        struct Node *prev;
    };

    u8 temp[sizeof(OSContext) + 8];
    volatile PadReg *p;
    u16 v;
    s32 type;
    struct Node *node;

    p = (volatile PadReg *)__PADRegs;
    v = p->val;
    p->val = (u16)((v & ~0x28) | 0x80);
    OSClearContext(temp);
    OSSetCurrentContext(temp);

    do {
    } while (fn_80215F50() == 0);

    type = fn_80215F60();
    node = (struct Node *)lbl_8036873C;
    if ((node->unk08 & 2) && ((u32)(type + 0x232F0000) == 2)) {
        type = 0xDCD10003;
    }
    switch (type) {
    case 0xDCD10000:
        node->state = 1;
        if (((struct Node *)lbl_8036873C)->cb28 != NULL) {
            ((struct Node *)lbl_8036873C)->cb28();
        }
        break;
    case 0xDCD10001:
        node->state = 1;
        if (((struct Node *)lbl_8036873C)->cb2C != NULL) {
            ((struct Node *)lbl_8036873C)->cb2C();
        }
        break;
    case 0xDCD10002:
        if (lbl_80368728 != 0) {
            if (lbl_8036873C == lbl_8036872C) {
                fn_80215F78(0xCDD10003);
                do {
                } while (fn_80215F40() != 0);
                lbl_8036872C = NULL;
                lbl_80368728 = 0;
                if (((struct Node *)lbl_8036873C)->cb2C != NULL) {
                    ((struct Node *)lbl_8036873C)->cb2C();
                }
            } else {
                fn_80215F78(0xCDD10001);
                do {
                } while (fn_80215F40() != 0);
                fn_80216534(lbl_8036873C, lbl_8036872C);
                *(s32 *)lbl_8036873C = 2;
                lbl_80368728 = 0;
                lbl_8036873C = lbl_8036872C;
                lbl_8036872C = 0;
            }
        } else if (((struct Node *)lbl_8036873C)->next == NULL) {
            if (lbl_8036873C == lbl_80368738) {
                fn_80215F78(0xCDD10003);
                do {
                } while (fn_80215F40() != 0);
                if (((struct Node *)lbl_8036873C)->cb2C != NULL) {
                    ((struct Node *)lbl_8036873C)->cb2C();
                }
            } else {
                fn_80215F78(0xCDD10001);
                do {
                } while (fn_80215F40() != 0);
                fn_80216534(lbl_8036873C, lbl_80368738);
                ((struct Node *)lbl_8036873C)->state = 2;
                lbl_8036873C = lbl_80368738;
            }
        } else {
            fn_80215F78(0xCDD10001);
            do {
            } while (fn_80215F40() != 0);
            fn_80216534(lbl_8036873C, ((struct Node *)lbl_8036873C)->next);
            ((struct Node *)lbl_8036873C)->state = 2;
            lbl_8036873C = ((struct Node *)lbl_8036873C)->next;
        }
        break;
    case 0xDCD10003:
        if (lbl_80368728 != 0) {
            if (((struct Node *)lbl_8036873C)->cb30 != NULL) {
                ((struct Node *)lbl_8036873C)->cb30(lbl_8036873C);
            }
            fn_80215F78(0xCDD10001);
            do {
            } while (fn_80215F40() != 0);
            fn_80216534(NULL, lbl_8036872C);
            fn_80216900(lbl_8036873C);
            lbl_80368728 = 0;
            lbl_8036873C = lbl_8036872C;
            lbl_8036872C = 0;
        } else if (((struct Node *)lbl_8036873C)->next == NULL) {
            if (lbl_8036873C == lbl_80368738) {
                if (((struct Node *)lbl_8036873C)->cb30 != NULL) {
                    ((struct Node *)lbl_8036873C)->cb30(lbl_8036873C);
                }
                fn_80215F78(0xCDD10002);
                do {
                } while (fn_80215F40() != 0);
                ((struct Node *)lbl_8036873C)->state = 3;
                fn_80216900(lbl_8036873C);
            } else {
                if (((struct Node *)lbl_8036873C)->cb30 != NULL) {
                    ((struct Node *)lbl_8036873C)->cb30(lbl_8036873C);
                }
                fn_80215F78(0xCDD10001);
                do {
                } while (fn_80215F40() != 0);
                ((struct Node *)lbl_8036873C)->state = 3;
                fn_80216534(NULL, lbl_80368738);
                lbl_8036873C = lbl_80368738;
                fn_80216900(lbl_80368734);
            }
        } else {
            if (((struct Node *)lbl_8036873C)->cb30 != NULL) {
                ((struct Node *)lbl_8036873C)->cb30(lbl_8036873C);
            }
            fn_80215F78(0xCDD10001);
            do {
            } while (fn_80215F40() != 0);
            ((struct Node *)lbl_8036873C)->state = 3;
            fn_80216534(NULL, ((struct Node *)lbl_8036873C)->next);
            lbl_8036873C = ((struct Node *)lbl_8036873C)->next;
            fn_80216900(((struct Node *)lbl_8036873C)->prev);
        }
        break;
    case 0xDCD10004:
        if (((struct Node *)lbl_8036873C)->cb34 != NULL) {
            ((struct Node *)lbl_8036873C)->cb34(lbl_8036873C);
        }
        break;
    }
    OSClearContext(temp);
    OSSetCurrentContext(ctx);
}

void fn_80216534(void *arg0, void *arg1) {
    M2C_UNK fn_80215F78(s32);
    if (arg0 != NULL) {
        fn_80215F78(M2C_FIELD(arg0, s32 *, 0x18));
        do {

        } while (fn_80215F40() != 0U);
        fn_80215F78(M2C_FIELD(arg0, s32 *, 0x1C));
        do {

        } while (fn_80215F40() != 0U);
        fn_80215F78(M2C_FIELD(arg0, s32 *, 0x20));
        do {

        } while (fn_80215F40() != 0U);
    } else {
        fn_80215F78(0);
        do {

        } while (fn_80215F40() != 0U);
        fn_80215F78(0);
        do {

        } while (fn_80215F40() != 0U);
        fn_80215F78(0);
        do {

        } while (fn_80215F40() != 0U);
    }
    fn_80215F78(M2C_FIELD(arg1, s32 *, 0xC));
    do {

    } while (fn_80215F40() != 0U);
    fn_80215F78(M2C_FIELD(arg1, s32 *, 0x10));
    do {

    } while (fn_80215F40() != 0U);
    fn_80215F78(M2C_FIELD(arg1, s32 *, 0x14));
    do {

    } while (fn_80215F40() != 0U);
    if ((u32) M2C_FIELD(arg1, u32 *, 0) == 0U) {
        fn_80215F78((s32) M2C_FIELD(arg1, u16 *, 0x24));
        do {

        } while (fn_80215F40() != 0U);
        fn_80215F78(0);
        do {

        } while (fn_80215F40() != 0U);
        fn_80215F78(0);
        do {

        } while (fn_80215F40() != 0U);
        fn_80215F78(0);
        do {

        } while (fn_80215F40() != 0U);
        return;
    }
    fn_80215F78((s32) M2C_FIELD(arg1, u16 *, 0x26));
    do {

    } while (fn_80215F40() != 0U);
    fn_80215F78(M2C_FIELD(arg1, s32 *, 0x18));
    do {

    } while (fn_80215F40() != 0U);
    fn_80215F78(M2C_FIELD(arg1, s32 *, 0x1C));
    do {

    } while (fn_80215F40() != 0U);
    fn_80215F78(M2C_FIELD(arg1, s32 *, 0x20));
    do {

    } while (fn_80215F40() != 0U);
}

void fn_802166D4(void *arg0) {
    s32 fn_80215F50();
    void fn_80215F60();
    void fn_80215F78(void *);
    s32 fn_80215F40();
    void fn_802160C0(void *, void *);
    extern u16 lbl_8029D860[160];

    // First loop with fn_80215F50
    do {
        if (fn_80215F50() == 0) {
            break;
        }
    } while (1);
    
    fn_80215F60();
    
    // Process various fields through calls to fn_80215F78 with hard-coded values 
    fn_80215F78((void *)0x80F3A001);
    
    do {
        if (fn_80215F40() == 0) {
            break;
        }
    } while (1);
    
    fn_80215F78(M2C_FIELD(arg0, void **, 0xC));
    
    do {
        if (fn_80215F40() == 0) {
            break;
        }
    } while (1);
    
    fn_80215F78((void *)0x80F3C002);
    
    do {
        if (fn_80215F40() == 0) {
            break;
        }
    } while (1);
    
    fn_80215F78((void *)((u16)M2C_FIELD(arg0, s32 *, 0x14)));
    
    do {
        if (fn_80215F40() == 0) {
            break;
        }
    } while (1);
    
    fn_80215F78((void *)0x80F3A002);
    
    do {
        if (fn_80215F40() == 0) {
            break;
        }
    } while (1);
    
    fn_80215F78(M2C_FIELD(arg0, void **, 0x10));
    
    do {
        if (fn_80215F40() == 0) {
            break;
        }
    } while (1);
    
    fn_80215F78((void *)0x80F3B002);
    
    do {
        if (fn_80215F40() == 0) {
            break;
        }
    } while (1);
    
    fn_80215F78(NULL);
    
    do {
        if (fn_80215F40() == 0) {
            break;
        }
    } while (1);
    
    fn_80215F78((void *)0x80F3D001);
    
    do {
        if (fn_80215F40() == 0) {
            break;
        }
    } while (1);
    
    fn_80215F78((void *)M2C_FIELD(arg0, u16 *, 0x24));
    
    do {
        if (fn_80215F40() == 0) {
            break;
        }
    } while (1);
    
    // Final calls to fn_802160C0
    fn_802160C0(&lbl_8029D860, arg0);
    fn_802160C0(&lbl_8029D860 + 0x20, M2C_FIELD(arg0, void **, 0xC));
    fn_802160C0(&lbl_8029D860 + 0x50, (void *)M2C_FIELD(arg0, s32 *, 0x14));
    fn_802160C0(&lbl_8029D860 + 0x80, M2C_FIELD(arg0, void **, 0x10));
    fn_802160C0(&lbl_8029D860 + 0xB0, M2C_FIELD(arg0, void **, 0x1C));
    fn_802160C0(&lbl_8029D860 + 0xE0, (void *)M2C_FIELD(arg0, u16 *, 0x24));
}

void fn_80216860(void *arg0) {
    extern void *lbl_80368734;
    extern void *lbl_80368738;
    extern void *lbl_8036873C;
    struct Node {
        s32 state;
        s32 unk04;
        s32 unk08;
        u8 pad[0x2C];
        struct Node *next;
        struct Node *prev;
    } *node = (struct Node *)arg0;
    struct Node *cur;
    struct Node *tmp;

    if (lbl_80368738 == NULL) {
        lbl_8036873C = node;
        lbl_80368734 = node;
        lbl_80368738 = node;
        node->prev = NULL;
        node->next = NULL;
        return;
    }

    cur = (struct Node *)lbl_80368738;
    while (cur != NULL) {
        if ((u32)node->unk04 < (u32)cur->unk04) {
            node->prev = cur->prev;
            cur->prev = node;
            node->next = cur;
            tmp = node->prev;
            if (tmp == NULL) {
                lbl_80368738 = node;
            } else {
                tmp->next = node;
            }
            break;
        }
        cur = cur->next;
    }
    if (cur != NULL) {
        return;
    }
    ((struct Node *)lbl_80368734)->next = node;
    node->next = NULL;
    node->prev = (struct Node *)lbl_80368734;
    lbl_80368734 = node;
}

void fn_80216900(void *arg0) {
    extern void *lbl_80368738;
    extern void *lbl_80368734;
    extern void *lbl_8036873C;
    struct Node {
        s32 state;
        s32 unk04;
        s32 unk08;
        u8 pad[0x2C];
        struct Node *next;
        struct Node *prev;
    } *node = (struct Node *)arg0;
    struct Node *tmp;

    node->unk08 = 0;
    node->state = 3;
    if ((struct Node *)lbl_80368738 == node) {
        if (node->next != NULL) {
            lbl_80368738 = node->next;
            node->next->prev = NULL;
            return;
        }
        lbl_8036873C = NULL;
        lbl_80368734 = NULL;
        lbl_80368738 = NULL;
        return;
    }
    if ((struct Node *)lbl_80368734 == node) {
        lbl_80368734 = node->prev;
        node->prev->next = NULL;
        lbl_8036873C = lbl_80368738;
        return;
    }
    lbl_8036873C = node->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;
}
#include "common.h"
#include <dolphin/os.h>
