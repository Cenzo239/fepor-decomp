/* Functions from 0x8022CD68 to 0x80267A7C, found by decomp-toolkit. */
#include "common.h"

extern s32 lbl_80366F28;
extern char lbl_80282AE8[];
extern char lbl_80282B20[];
extern u8 gSoundData[];
extern f64 lbl_8036C368;
typedef struct EXIControl {
    void (*exiCallback)(s32 chan, void *context);
    void (*tcCallback)(s32 chan, void *context);
    void (*extCallback)(s32 chan, void *context);
    volatile u32 state;
    int immLen;
    u8 *immBuf;
    u32 dev;
    u32 id;
    s32 idTime;
    int items;
    struct {
        u32 dev;
        void (*callback)(s32 chan, void *context);
    } queue[3];
} EXIControl;

extern EXIControl Ecb_8033E188[3];
s32 EXIGetID(s32 chan, u32 dev, u32 *id);
u16 *D_80256B30;
extern s32 UART_Initialized;
extern f32 lbl_8036C374;
extern s32 gSynthTimeHi;
extern s32 gSynthTimeLo;
extern s32 gSynthSchedList;
extern s32 gSynthIdleList;
extern u32* lbl_80368A38;
extern void (*lbl_80368B34)(s16);
extern f32 lbl_8034C324[];
extern s32 D_80368AD0;
extern s32 lbl_80368B0C;
extern void (*__atexit_funcs[])(void);
extern s32 __atexit_curr_func;
extern void (*__console_exit)(void);
extern s32 __aborting;
extern void (*__stdio_exit)(void);
extern void (**_dtors)(void);
extern void _ExitProcess(void);
extern s16 lbl_802A1E90[];
extern u8 lbl_80368AAE;
extern u8 lbl_80368AAD;
extern u16 lbl_8035BF18[];
extern u32 lbl_8035C918[];

typedef struct __InStrCtrl {
    char *NextChar;
    s32 NullCharDetected;
} __InStrCtrl;

u32 fn_8026367C(void);
u16 Sound_GetChanParam(u8 arg0, u8 arg1, u8 arg2);
s32 __cvt_fp2unsigned(f32 arg0);
void Sound_SetVoiceEnvelope(u8 arg0, void *arg1, s32 arg2);
void fn_8026146C(s32 *);
void fn_8025FFC8(void *arg0, u8 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5);
s32 Sound_LookupVid(void);
extern void func_80013934(s32 arg0);
extern s32 gSynthVoices;
extern u16 lbl_803548B8;
extern u16 lbl_80368A08;
extern u16 lbl_8035A510[];
extern u16 lbl_8035D118[256];
extern u16 gSoundChanParamsDefault[4288];
extern f32 lbl_802831BC[];
extern f64 lbl_8036C348;
extern u16 lbl_803670C0;
extern u32 lbl_803670C8;
extern u32 lbl_800000F8;

#include "musyx/select_source.h"

typedef struct Voice {
    u8 pad0[0x110];
    u64 flags;
    u8 pad118[0x5C];
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    s32 unk188;
    u32 unk18C;
    u32 unk190;
} Voice;

typedef struct VidList {
    struct VidList *next; /* 0x0 */
    struct VidList *prev; /* 0x4 */
    u32 vid;              /* 0x8 */
    u32 root;             /* 0xC */
} VidList;

extern u32 vidGenerator;

static u32 GetNewVid(void) {
    u32 vid;

    do {
        vid = vidGenerator++;
    } while (vid == 0xFFFFFFFF);
    return vid;
}

typedef struct GroupData {
    u8 pad0[4];
    u16 id;     /* 0x04 */
    u16 type;   /* 0x06 */
    u8 pad8[0x1C - 0x8];
    u32 unk1C;  /* 0x1C */
    u32 unk20;  /* 0x20 */
    u32 unk24;  /* 0x24 */
} GroupData;

typedef struct GroupEntry {
    GroupData *data; /* 0x0 */
    u32 unk4;        /* 0x4 */
    u32 base;        /* 0x8 */
} GroupEntry;

typedef struct GroupNode {
    struct GroupNode *next; /* 0x0 */
    u32 unk4;               /* 0x4 */
    s16 count;              /* 0x8 */
    GroupEntry entries[1];  /* 0xC */
} GroupNode;

typedef struct GroupItem {
    u16 id;
    u8 pad2[0x52];
} GroupItem;

typedef struct SynthVoice {
    struct SynthVoice *next; /* 0x000 */
    struct SynthVoice *prev; /* 0x004 */
    u8 state;                /* 0x008 */
    u8 id;                   /* 0x009 */
    u16 unkA;                /* 0x00A */
    u32 vid;                 /* 0x00C */
    u8 pad10[0xF4 - 0x10];
    u32 unkF4;               /* 0x0F4 */
    struct VidList *unkF8;   /* 0x0F8 */
    struct VidList *unkFC;   /* 0x0FC */
    u8 pad100[0x11C - 0x100];
    s32 unk11C;              /* 0x11C */
    s32 unk120;              /* 0x120 */
    u8 pad124[0xEF0 - 0x124];
    s32 unkEF0;              /* 0xEF0 */
    s32 unkEF4;              /* 0xEF4 */
    u16 unkEF8;              /* 0xEF8 */
    u8 unkEFA;               /* 0xEFA */
    u8 padEFB[0x1508 - 0xEFB];
    struct {
        u8 pad0[0x32];
        u16 unk32;
        u8 pad34[4];
    } unk1508[16];           /* 0x1508 */
} SynthVoice;

typedef struct {
    char gpr;
    char fpr;
    char reserved[2];
    char *input_arg_area;
    char *reg_save_area;
} __va_list;
typedef __va_list va_list[1];

typedef struct {
    char *buffer;
    s32 length;
    s32 position;
} __OutStr;

s32 __pformatter(s32 (*)(void *, const char *, u32), void *, const char *, va_list);
s32 fn_80232220(void *, const char *, u32);

// The structure being used in functions in this file - assumed based on offset 0xF4
typedef struct {
    u8 unkF4;  // This is likely the member accessed in function with 0xF4 offset 
} SStructType;

extern s32 D_8022EF64;

volatile u32 __EXIRegs[16] : 0xCC006800;
s32 __EXIProbeStartTime[2] : 0x800030C0;

typedef struct OSContext {
    u32 gpr[32];
    u32 cr;
    u32 lr;
    u32 ctr;
    u32 xer;
    f64 fpr[32];
    u32 fpscr_pad;
    u32 fpscr;
    u32 srr0;
    u32 srr1;
    u16 mode;
    u16 state;
    u32 gqr[8];
    u32 psf_pad;
    f64 psf[32];
} OSContext;

extern s32 fn_802314D8(s32, s32, s32);

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

static void CompleteTransfer(s32 chan)
{
    EXIControl *exi = &Ecb_8033E188[chan];
    u8 *buf;
    u32 data;
    s32 i;
    s32 len;

    if (exi->state & 3) {
        if (exi->state & 2) {
            if ((len = exi->immLen) != 0) {
                buf = exi->immBuf;
                data = __EXIRegs[(chan * 5) + 4];
                for (i = 0; i < len; i++) {
                    *buf++ = (u8)(data >> (8 * (3 - i)));
                }
            }
        }
        exi->state &= ~3;
    }
}

extern f64 __floor_huge;
extern f64 __floor_zero;

extern f64 lbl_8036C148;

#pragma scheduling off
/* Mask or unmask the EXI interrupt for chan based on callback/lock state. */
void SetExiInterruptMask(s32 chan, EXIControl *exi) {
    void __OSMaskInterrupts(u32);
    void __OSUnmaskInterrupts(u32);
    u32 __OSGetInterruptHandler(u32);
    u32 *ecb2 = (u32 *)((u8 *)Ecb_8033E188 + 0x80);
    switch (chan) {
    case 0:
        if (((u32)M2C_FIELD(exi, u32 *, 0) == 0U && *ecb2 == 0U) || (M2C_FIELD(exi, s32 *, 0xC) & 0x10)) {
            __OSMaskInterrupts(0x410000);
            return;
        }
        __OSUnmaskInterrupts(0x410000);
        return;
    case 1:
        if (((u32)M2C_FIELD(exi, u32 *, 0) == 0U) || (M2C_FIELD(exi, s32 *, 0xC) & 0x10)) {
            __OSMaskInterrupts(0x80000);
            return;
        }
        __OSUnmaskInterrupts(0x80000);
        return;
    case 2:
        if ((__OSGetInterruptHandler(0x19) == 0U) || (M2C_FIELD(exi, s32 *, 0xC) & 0x10)) {
            __OSMaskInterrupts(0x40);
            return;
        }
        __OSUnmaskInterrupts(0x40);
        return;
    }
}

#pragma scheduling off
#pragma use_lmw_stmw on
BOOL EXIImm(s32 chan, void *buf, s32 len, u32 type, void (*callback)(s32, void *))
{
    BOOL enabled;
    EXIControl *exi = &Ecb_8033E188[chan];

    enabled = OSDisableInterrupts();
    if ((exi->state & 3) || !(exi->state & 4)) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    exi->tcCallback = callback;
    if (exi->tcCallback) {
        EXIClearInterrupts(chan, FALSE, TRUE, FALSE);
        __OSUnmaskInterrupts(0x200000U >> (chan * 3));
    }

    exi->state |= 2;

    if (type != 0) {
        u32 data;
        int i;
        data = 0;
        for (i = 0; i < len; i++) {
            data |= ((u8 *)buf)[i] << ((3 - i) * 8);
        }
        __EXIRegs[chan * 5 + 4] = data;
    }

    exi->immBuf = buf;
    exi->immLen = (type != 1) ? len : 0;

    __EXIRegs[chan * 5 + 3] = ((type << 2) | 1) | ((len - 1) << 4);

    OSRestoreInterrupts(enabled);
    return TRUE;
}
s32 EXIImmEx(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 EXIImm(s32, s32, s32, s32, s32);
    s32 EXISync(s32);
    s32 n;
    s32 type;
    s32 len;
    s32 buf;
    s32 chan;

    chan = arg0;
    buf = arg1;
    len = arg2;
    type = arg3;

    while (len) {
        n = (len < 4) ? len : 4;
        if (!EXIImm(chan, buf, n, type, 0)) {
            return 0;
        }
        if (!EXISync(chan)) {
            return 0;
        }
        buf += n;
        len -= n;
    }
    return 1;
}

BOOL EXIDma(s32 chan, void *buf, s32 len, u32 type, void (*callback)(s32, void *)) {
    BOOL enabled;
    EXIControl *exi;

    exi = &Ecb_8033E188[chan];
    enabled = OSDisableInterrupts();
    if ((exi->state & 3) || !(exi->state & 4)) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    exi->tcCallback = callback;
    if (exi->tcCallback) {
        EXIClearInterrupts(chan, FALSE, TRUE, FALSE);
        __OSUnmaskInterrupts(0x200000U >> (chan * 3));
    }

    exi->state |= 1;

    __EXIRegs[chan * 5 + 1] = (u32)buf & 0x03FFFFE0;
    __EXIRegs[chan * 5 + 2] = len;
    __EXIRegs[chan * 5 + 3] = (type << 2) | 3;

    OSRestoreInterrupts(enabled);
    return TRUE;
}

u32 fn_80204410(void);
u32 OSGetConsoleType(void);
#pragma scheduling off
#pragma use_lmw_stmw on
BOOL EXISync(s32 chan) {
    EXIControl *exi;
    BOOL ret;
    BOOL enabled;

    exi = &Ecb_8033E188[chan];
    ret = 0;

    while (exi->state & 4) {
        if ((__EXIRegs[chan * 5 + 3] & 1) == 0) {
            enabled = OSDisableInterrupts();
            if (exi->state & 4) {
                CompleteTransfer(chan);
                if (fn_80204410() != 0xFF ||
                    (OSGetConsoleType() & 0xF0000000) == 0x20000000 ||
                    exi->immLen != 4 ||
                    (__EXIRegs[chan * 5] & 0x70) != 0 ||
                    (__EXIRegs[chan * 5 + 4] != 0x01010000 &&
                     __EXIRegs[chan * 5 + 4] != 0x05070000 &&
                     __EXIRegs[chan * 5 + 4] != 0x04220001) ||
                    *(u16 *)0x800030E6 == 0x8200) {
                    ret = 1;
                }
            }
            OSRestoreInterrupts(enabled);
            break;
        }
    }
    return ret;
}
BOOL EXIClearInterrupts(s32 chan, BOOL exi, BOOL tc, BOOL ext) {
    u32 cpr;
    u32 prev;

    prev = cpr = __EXIRegs[chan * 5];
    cpr &= 0x7F5;
    if (exi) {
        cpr |= 2;
    }
    if (tc) {
        cpr |= 8;
    }
    if (ext) {
        cpr |= 0x800;
    }
    __EXIRegs[chan * 5] = cpr;
    return prev;
}

#pragma scheduling off
#pragma use_lmw_stmw on
s32 fn_80239298(s32 chan, void *callback)
{
    EXIControl *exi;
    void *old;
    BOOL enabled;

    exi = &Ecb_8033E188[chan];
    enabled = OSDisableInterrupts();
    old = (void *)exi->exiCallback;
    exi->exiCallback = (void (*)(s32, void *))callback;
    if (chan != 2) {
        SetExiInterruptMask(chan, exi);
    } else {
        SetExiInterruptMask(0, Ecb_8033E188);
    }
    OSRestoreInterrupts(enabled);
    return (s32)old;
}
BOOL OSDisableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL level);
s64 OSGetTime(void);
#pragma scheduling off
/* Return whether an EXI device is stably present on chan (chan 2 always true). */
BOOL __EXIProbe(s32 chan) {
    EXIControl *exi = &Ecb_8033E188[chan];
    BOOL enabled;
    BOOL rc;
    u32 cpr;
    s32 t;

    if (chan == 2) {
        return TRUE;
    }

    rc = TRUE;
    enabled = OSDisableInterrupts();
    cpr = __EXIRegs[chan * 5];
    if (!(exi->state & 8)) {
        if (cpr & 0x800) {
            EXIClearInterrupts(chan, FALSE, FALSE, TRUE);
            exi->idTime = 0;
            __EXIProbeStartTime[chan] = 0;
        }

        if (cpr & 0x1000) {
            t = (s32)(OSGetTime() / ((*(u32 *)0x800000F8 / 4) / 1000) / 100) + 1;
            if (__EXIProbeStartTime[chan] == 0) {
                __EXIProbeStartTime[chan] = t;
            }
            if (t - __EXIProbeStartTime[chan] < 3) {
                rc = FALSE;
            }
        } else {
            exi->idTime = 0;
            __EXIProbeStartTime[chan] = 0;
            rc = FALSE;
        }
    } else if (!(cpr & 0x1000) || (cpr & 0x800)) {
        exi->idTime = 0;
        __EXIProbeStartTime[chan] = 0;
        rc = FALSE;
    }
    OSRestoreInterrupts(enabled);

    return rc;
}

s32 fn_80239488(s32 chan) {
    EXIControl *exi;
    s32 err;
    u32 id;

    exi = &Ecb_8033E188[chan];
    err = __EXIProbe(chan);
    if (err != 0 && exi->idTime == 0) {
        if (EXIGetID(chan, 0, &id) != 0) {
            return 1;
        }
        return 0;
    }
    return err;
}

#pragma scheduling reset
s32 fn_80239508(s32 chan) {
    EXIControl *exi;
    s32 err;
    u32 id;
    exi = &Ecb_8033E188[chan];
    err = __EXIProbe(chan);
    if (err != 0 && exi->idTime == 0) {
        if (EXIGetID(chan, 0, &id) != 0) err = 1;
        else err = 0;
    }
    if (err != 0) return 1;
    if (__EXIProbeStartTime[chan] != 0) return 0;
    return -1;
}

static inline s32 EXIAttachInternal(s32 chan, void *callback)
{
    EXIControl *exi = &Ecb_8033E188[chan];
    s32 enabled = OSDisableInterrupts();
    u32 mask;
    s32 result;
    if ((exi->state & 8) || !__EXIProbe(chan)) {
        OSRestoreInterrupts(enabled);
        result = 0;
    } else {
        EXIClearInterrupts(chan, 1, 0, 0);
        exi->extCallback = callback;
        mask = 0x100000U >> (chan * 3);
        __OSUnmaskInterrupts(mask);
        exi->state |= 8;
        OSRestoreInterrupts(enabled);
        result = 1;
    }
    return result;
}

#pragma inline_depth(1)
s32 fn_802395BC(s32 chan, void *callback)
{
 EXIControl *exi;
 s32 enabled;
 s32 result;
 exi=&Ecb_8033E188[chan];
 fn_80239488(chan);
 enabled=OSDisableInterrupts();
 if(exi->idTime==0) {OSRestoreInterrupts(enabled);return 0;}
 result=EXIAttachInternal(chan,callback);
 OSRestoreInterrupts(enabled);
 return result;
}
#pragma inline_depth(8)
s32 fn_802396C8(s32 chan) {
    EXIControl *exi;
    s32 enabled;
    exi = &Ecb_8033E188[chan];
    enabled = OSDisableInterrupts();
    if (!(exi->state & 8)) {
        OSRestoreInterrupts(enabled);
        return 1;
    }
    if ((exi->state & 0x10) && exi->dev == 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state &= ~8;
    __OSMaskInterrupts(0x500000U >> (chan * 3));
    OSRestoreInterrupts(enabled);
    return 1;
}

s32 EXISelect(s32 chan, u32 dev, u32 freq)
{
    EXIControl *exi;
    s32 enabled;
    u32 csr;

    exi = &Ecb_8033E188[chan];
    enabled = OSDisableInterrupts();

    if (exi->state & 4) goto fail;
    if (chan == 2) goto select;

    if (dev == 0 && !(exi->state & 8)) {
        if (!__EXIProbe(chan)) goto fail;
    }
    if (!(exi->state & 0x10)) goto fail;
    if (exi->dev == dev) goto select;

fail:
    OSRestoreInterrupts(enabled);
    return 0;

select:
    exi->state |= 4;

    csr = __EXIRegs[chan * 5];
    csr &= 0x405;
    csr |= ((1U << dev) << 7) | (freq << 4);
    __EXIRegs[chan * 5] = csr;

    if (exi->state & 8) {
        switch (chan) {
        case 0: __OSMaskInterrupts(0x00100000); break;
        case 1: __OSMaskInterrupts(0x00020000); break;
        }
    }

    OSRestoreInterrupts(enabled);
    return 1;
}

s32 EXIDeselect(s32 channel) {
 u32 csr;
 s32 enabled;
 EXIControl *exi;
 s32 chan = channel;
 exi = &Ecb_8033E188[chan];
 enabled = OSDisableInterrupts();
 if (!(exi->state & 4)) { OSRestoreInterrupts(enabled); return 0; }
 exi->state &= ~4;
 csr = __EXIRegs[chan * 5];
 __EXIRegs[chan * 5] = csr & 0x405;
 if (exi->state & 8) {
 switch (chan) { case 0: __OSUnmaskInterrupts(0x100000); break; case 1: __OSUnmaskInterrupts(0x20000); break; }
 }
 OSRestoreInterrupts(enabled);
 if (chan != 2 && (csr & 0x80)) { if (__EXIProbe(chan)) return 1; else return 0; }
 return 1;
}

#pragma scheduling off
void EXIIntrruptHandler(s16 interrupt, OSContext *context)
{
    void OSClearContext(void *);
    void OSSetCurrentContext(void *);

    s32 chan;
    EXIControl *exi;
    void (*callback)(s32, void *);
    OSContext exceptionContext;
    u8 filler[8];

    chan = (interrupt - 9) / 3;
    exi = &Ecb_8033E188[chan];
    __EXIRegs[chan * 5] = (__EXIRegs[chan * 5] & 0x7F5) | 2;
    callback = exi->exiCallback;
    if (callback) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        callback(chan, context);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}
void OSClearContext(void *);
void OSSetCurrentContext(void *);
#pragma scheduling off
/* EXI transfer-complete IRQ: finish DMA/imm transfer and invoke the channel's tcCallback. */
void TCIntrruptHandler(s16 interrupt, OSContext *context)
{
    s32 chan;
    EXIControl *exi;
    void (*callback)(s32, void *);
    OSContext exceptionContext;
    u8 filler[8];

    (void)filler;
    chan = (interrupt - 10) / 3;
    exi = &Ecb_8033E188[chan];
    __OSMaskInterrupts(0x80000000U >> interrupt);
    __EXIRegs[chan * 5] = (__EXIRegs[chan * 5] & 0x7F5) | 8;
    callback = exi->tcCallback;
    if (callback) {
        exi->tcCallback = 0;
        CompleteTransfer(chan);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        callback(chan, context);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}

/* EXI external (device insert/remove) IRQ: mask channel IRQs, clear state bit 0x8, invoke extCallback. */
void EXTIntrruptHandler(s16 interrupt, OSContext *context)
{
    s32 chan;
    EXIControl *exi;
    void (*callback)(s32, void *);
    OSContext exceptionContext;

    chan = (interrupt - 11) / 3;
    __OSMaskInterrupts(0x500000U >> (chan * 3));
    exi = &Ecb_8033E188[chan];
    callback = exi->extCallback;
    exi->state &= ~0x8;
    if (callback) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        exi->extCallback = 0;
        callback(chan, context);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}

void EXIInit(void) {
extern u32 IDSerialPort1_80368800;
extern s32 __OSInIPL;
extern const char *__EXIVersion;
void OSRegisterVersion(const char *);
void __OSSetInterruptHandler(s32, void (*)(s16, OSContext *));
void __OSEnableBarnacle(s32, s32);
u32 id;
while ((__EXIRegs[3] & 1) == 1 || (__EXIRegs[8] & 1) == 1 || (__EXIRegs[13] & 1) == 1) {
}
__OSMaskInterrupts(0x7F8000);
__EXIRegs[0] = 0;
__EXIRegs[5] = 0;
__EXIRegs[10] = 0;
__EXIRegs[0] = 0x2000;
__OSSetInterruptHandler(9, EXIIntrruptHandler);
__OSSetInterruptHandler(10, TCIntrruptHandler);
__OSSetInterruptHandler(11, EXTIntrruptHandler);
__OSSetInterruptHandler(12, EXIIntrruptHandler);
__OSSetInterruptHandler(13, TCIntrruptHandler);
__OSSetInterruptHandler(14, EXTIntrruptHandler);
__OSSetInterruptHandler(15, EXIIntrruptHandler);
__OSSetInterruptHandler(16, TCIntrruptHandler);
EXIGetID(0, 2, &IDSerialPort1_80368800);
if (__OSInIPL) {
__EXIProbeStartTime[1] = 0;
__EXIProbeStartTime[0] = 0;
Ecb_8033E188[1].idTime = 0;
Ecb_8033E188[0].idTime = 0;
__EXIProbe(0);
__EXIProbe(1);
} else if (EXIGetID(0, 0, &id) && id == 0x07010000) {
__OSEnableBarnacle(1, 0);
} else if (EXIGetID(1, 0, &id) && id == 0x07010000) {
__OSEnableBarnacle(0, 2);
}
OSRegisterVersion(__EXIVersion);
}

#pragma scheduling reset
s32 EXILock(s32 chan, u32 dev, void (*callback)(s32, void *)) {
    EXIControl *exi;
    s32 enabled;
    s32 i;

    exi = &Ecb_8033E188[chan];
    enabled = OSDisableInterrupts();
    if (exi->state & 0x10) {
        if (callback) {
            for (i = 0; i < exi->items; i++) {
                if (exi->queue[i].dev == dev) {
                    OSRestoreInterrupts(enabled);
                    return 0;
                }
            }
            exi->queue[exi->items].callback = callback;
            exi->queue[exi->items].dev = dev;
            exi->items++;
        }
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state |= 0x10;
    exi->dev = dev;
    SetExiInterruptMask(chan, exi);
    OSRestoreInterrupts(enabled);
    return 1;
}

s32 EXIUnlock(s32 chan) {
    EXIControl *exi;
    s32 enabled;
    void (*callback)(s32, void *);
    exi = &Ecb_8033E188[chan];
    enabled = OSDisableInterrupts();
    if (!(exi->state & 0x10)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state &= ~0x10;
    SetExiInterruptMask(chan, exi);
    if (exi->items > 0) {
        callback = exi->queue[0].callback;
        if (--exi->items > 0) {
            memmove(&exi->queue[0], &exi->queue[1], exi->items * sizeof(exi->queue[0]));
        }
        callback(chan, 0);
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

s32 fn_8023A114(s32 chan) {
    s32 off = chan << 6;
    return *(s32 *)((u8 *)Ecb_8033E188 + off + 0xC);
}

void UnlockedHandler(s32 chan, void *context) {
    u32 id;

    (void)context;
    EXIGetID(chan, 0, &id);
}


#pragma push
#pragma optimization_level 3
#pragma scheduling off
#pragma use_lmw_stmw on
#pragma inline_depth(1)
#pragma peephole on
s32 EXIGetID(s32 chan, u32 dev, u32 *id) {
    EXIControl *exi;
    s32 err;
    s32 startTime;
    s32 enabled3;
    s32 enabled;
    u32 cmd;
    s32 ok;
    void (*handler)(s32,void *);
    extern u32 IDSerialPort1_80368800;
    BOOL EXIClearInterrupts(s32, BOOL, BOOL, BOOL);
    s32 EXILock(s32,u32,void (*)(s32,void *));
    BOOL EXISelect(s32, u32, u32);
    BOOL EXIImm(s32, void *, s32, u32, void (*)(s32, void *));
    BOOL EXISync(s32);
    BOOL EXIDeselect(s32);
    void SetExiInterruptMask(s32, void *);
    void __OSUnmaskInterrupts(u32);
    void __OSMaskInterrupts(u32);
    void *memmove(void *, const void *, u32);

    exi = &Ecb_8033E188[chan];
    if (chan == 0 && dev == 2 && IDSerialPort1_80368800 != 0) {
        *id = IDSerialPort1_80368800;
        return 1;
    }
    if (chan < 2 && dev == 0) {
        if (!__EXIProbe(chan)) {
            return 0;
        }
        if (exi->idTime == __EXIProbeStartTime[chan]) {
            *id = exi->id;
            return exi->idTime;
        }
        if (!EXIAttachInternal(chan, 0)) {
            return 0;
        }
        startTime = __EXIProbeStartTime[chan];
    }
    enabled = OSDisableInterrupts();
    ok = 0;
    if (chan < 2 && dev == 0) {
        ok = 1;
    }
    if (ok != 0) {
        handler = UnlockedHandler;
    } else {
        handler = 0;
    }
    err = !EXILock(chan, dev, handler);
    if (!err) {
        err = !EXISelect(chan, dev, 0);
        if (!err) {
            cmd = 0;
            err |= !EXIImm(chan, &cmd, 2, 1, NULL);
            err |= !EXISync(chan);
            err |= !EXIImm(chan, id, 4, 0, NULL);
            err |= !EXISync(chan);
            err |= !EXIDeselect(chan);
        }
        EXIUnlock(chan);
    }
    OSRestoreInterrupts(enabled);
    if (chan < 2 && dev == 0) {
        fn_802396C8(chan);
        enabled3 = OSDisableInterrupts();
        err |= startTime != __EXIProbeStartTime[chan];
        if (!err) {
            exi->id = *id;
            exi->idTime = startTime;
        }
        OSRestoreInterrupts(enabled3);
        if (err) {
            return 0;
        }
        return exi->idTime;
    }
    if (err) {
        return 0;
    }
    return 1;
}
#pragma pop
#pragma use_lmw_stmw reset
#pragma scheduling reset

s32 fn_8023A504(s32 chan, u32 dev, u32 *type) {
 u32 id;
 s32 result;
 s32 value;
 result = EXIGetID(chan, dev, &id);
 if (result == 0) return result;
 value = id & 0xFFFFFF00;
 switch (value) {
 case 0x04020100: case 0x04020200: case 0x04020300: case 0x04060000:
 *type = value; return result;
 }
 switch ((s32)(id & 0xFFFF0000)) {
 case 0:
 if (!(id & 0x3803)) {
 switch ((s32)(id & 0xFC)) {
 case 4: case 8: case 0x10: case 0x20: case 0x40: case 0x80:
 *type = id & 0xFC; return result;
 }
 }
 break;
 case 0x05070000: *type = 0x05070000; return result;
 }
 *type = id;
 return result;
}

#pragma inline_depth(0)
#pragma scheduling on
s32 fn_8023A61C(s32 chan, u32 dev, u32 *id) {
    u32 cmd;
    s32 err;

    if (chan != 2 && dev == 0 && fn_802395BC(chan, 0) == 0) {
        return 0;
    }
    err = !EXILock(chan, dev, 0);
    if (err != 0) {
        goto after_unlock;
    }
    err = !EXISelect(chan, dev, 0);
    if (err != 0) {
        goto do_unlock;
    }
    cmd = 0x20011300;
    err = !EXIImm(chan, &cmd, 4, 1, 0);
    err |= !EXISync(chan);
    err |= !EXIImm(chan, id, 4, 0, 0);
    err |= !EXISync(chan);
    err |= !EXIDeselect(chan);
do_unlock:
    EXIUnlock(chan);
after_unlock:
    if (chan != 2 && dev == 0) {
        fn_802396C8(chan);
    }
    if (err != 0) {
        return 0;
    }
    if ((u32)(*id + 0x10000) == 0xFFFF) {
        goto fail;
    }
    return 1;
fail:
    return 0;
}
void __OSEnableBarnacle(s32 chan, s32 dev)
{
  s32 fn_8023A61C(s32, s32, s32 *);
  extern u32 lbl_80368808;
  extern u32 lbl_8036880C;
  extern u32 lbl_80368814;
  extern u32 lbl_80368810;
  s32 id;
  s32 d;
  s32 c;
  d = dev;
  if (!EXIGetID(chan, d, (u32 *) (&id)))
  {
    return;
  }
  switch (id)
  {
    case (s32) 0x80000004:

    case (s32) 0x80000008:

    case (s32) 0x80000010:

    case (s32) 0x80000020:

    case -1:

    case 4:

    case 8:

    case 16:

    case 32:

    case 0x01010000:

    case 0x01020000:

    case 0x02020000:

    case 0x03010000:

    case 0x04020100:

    case 0x04020200:

    case 0x04020300:

    case 0x04040404:

    case 0x04060000:

    case 0x04120000:

    case 0x04130000:

    case 0x04220000:
      break;

    default:
      c = chan;
      if (fn_8023A61C(c, d, &id))
    {
      lbl_80368808 = c;
      lbl_8036880C = d;
      lbl_80368814 = 0xA5FF005A;
      lbl_80368810 = 0xA5FF005A;
    }
      break;

  }

}

#pragma global_optimizer off
s32 InitializeUART(void) {
    u32 OSGetConsoleType(void);
    extern u32 lbl_80368808;
    extern u32 lbl_8036880C;
    extern u32 lbl_80368810;
    extern u32 lbl_80368814;
    u32 magic;
    s32 result;

    if ((u32)(lbl_80368814 + 0x5A010000) == 0x5AU) {
        return 0;
    }
    if ((OSGetConsoleType() & 0x10000000) == 0) {
        lbl_80368810 = 0;
        return 2;
    }
    magic = 0xA5FF005A;
    result = 0;
    lbl_80368810 = magic;
    {
        u32 one = 1;
        lbl_80368808 = result;
        lbl_8036880C = one;
    }
    return result;
}

#pragma optimization_level 3
#pragma global_optimizer off
s32 WriteUARTN(void *buf, u32 len) {
    BOOL EXILock(s32, u32, void *);
    BOOL EXISelect(s32, u32, u32);
    BOOL EXIImm(s32, void *, s32, u32, void *);
    BOOL EXISync(s32);
    BOOL EXIDeselect(s32);
    void EXIUnlock(s32);
    extern u32 lbl_80368808;
    extern u32 lbl_8036880C;
    extern u32 lbl_80368810;
    u32 length;
    u8 *ptr;
    u32 probe;
    s32 chunk;
    s32 avail;
    s32 error;
    char *p;
    u32 cmd;
    u32 q;

    ptr = (u8 *)buf;
    length = len;

    if ((u32)(lbl_80368810 + 0x5A010000) != 0x5AU) {
        return 2;
    }
    if (EXILock(lbl_80368808, lbl_8036880C, 0) == 0) {
        return 0;
    }

    for (p = (char *)ptr; (u32)(p - (char *)ptr) < length; p++) {
        if (*p == '\n') {
            *p = '\r';
        }
    }

    cmd = 0xA0010000;
    error = 0;
    probe = 0x20010000;

    while (length != 0) {
        s32 space;
        if (EXISelect(lbl_80368808, lbl_8036880C, 3) == 0) {
            space = -1;
        } else {
            q = probe;
            EXIImm(lbl_80368808, &q, 4, 1, 0);
            EXISync(lbl_80368808);
            EXIImm(lbl_80368808, &q, 1, 0, 0);
            EXISync(lbl_80368808);
            EXIDeselect(lbl_80368808);
            space = 0x10 - (s32)(q >> 24);
        }
        avail = space;
        if (space < 0) {
            error = 3;
            break;
        }
        if (space < 0xC && (u32)space < length) {
            continue;
        }

        if (EXISelect(lbl_80368808, lbl_8036880C, 3) == 0) {
            error = 3;
            break;
        }
        EXIImm(lbl_80368808, &cmd, 4, 1, 0);
        EXISync(lbl_80368808);

        while (avail != 0 && length != 0) {
            s32 n;
            if (avail < 4 && (u32)avail < length) {
                break;
            }
            if (length < 4U) {
                chunk = (s32)length;
            } else {
                chunk = 4;
            }
            n = chunk;
            EXIImm(lbl_80368808, ptr, n, 1, 0);
            {
                s32 c = (s32)lbl_80368808;
                ptr += chunk;
                length -= chunk;
                avail -= chunk;
                EXISync(c);
            }
        }
        EXIDeselect(lbl_80368808);
    }

    EXIUnlock(lbl_80368808);
    return error;
}
#pragma global_optimizer on
#pragma optimization_level reset

#pragma global_optimizer on
