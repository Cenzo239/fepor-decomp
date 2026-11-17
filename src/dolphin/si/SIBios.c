/* Functions from 0x8022CD68 to 0x80267A7C, found by decomp-toolkit. */
#include "common.h"

typedef union SIComCSR {
    u32 value;
    struct {
        u8 tcint:1, tcintmsk:1, rest0:6;
        u8 rest1:1, outlen:7;
        u8 rest2:1, inlen:7;
        u8 rest3:5, channel:2, start:1;
    } bits;
} SIComCSR;

extern u16 lbl_80366F28;
extern char lbl_80282AE8[];
extern char lbl_80282B20[];
extern u8 gSoundData[];
extern f64 lbl_8036C368;
extern u16 Ecb_8033E188[192];u16 *D_80256B30;
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

extern s32 fn_802314D8(s32, s32, s32);

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern f64 lbl_8036C148;

volatile u32 __SIRegs[64] : 0xCC006400;

/* Version string at +0, transfer state at +0x44 (Si_8029EFAC) */
typedef struct SIControl {
    char version[0x44];
    s32 chan;
    u32 unk48;
    u32 inputBytes;
    void *input;
    void *callback;
} SIControl;
extern SIControl lbl_8029EF68;

typedef struct SIPacket {
    s32 chan;
    void *output;
    u32 outputBytes;
    void *input;
    u32 inputBytes;
    void *callback;
    s64 fire;
} SIPacket;

typedef struct SIAlarm {
    u8 pad[0x28];
} SIAlarm;

static SIPacket Packet_8033E248[4];
static SIAlarm lbl_8033E2C8[4];
static s64 TypeTime[4];
static s64 XferTime[4];
static void *TypeCallback[4][4];
static u32 PollingHandler[4];
static BOOL InputBufferValid[4];
static u32 InputBuffer[4][2];
static volatile u32 InputBufferVcount[4];

static s32 SI_CopyS32(s32 x) {
    s32 y;
    y = x;
    return y;
}
static u32 cmdTypeAndStatus[4];

s32 fn_8023ABD4(void) {
    extern s32 Si_8029EFAC[];
    if (Si_8029EFAC[0] != -1) {
        return 1;
    }
    return 0;
}

s32 fn_8023ABF4(s32 arg0) {
    extern SIPacket Packet_8033E248[4];
    extern s32 Si_8029EFAC[];
    s32 var_r5 = 1;
    if ((Packet_8033E248[arg0].chan == -1) && (Si_8029EFAC[0] != arg0)) {
        var_r5 = 0;
    }
    return var_r5;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
u32 fn_8023AC30(void) {
    s64 __OSGetSystemTime(void);
    extern u32 Type_8029EFC0[4];
    extern s64 lbl_8033E388[4];
    u8 *siRegs;
    u32 *comcsr;
    SIControl *si;
    u32 sr;
    u32 *dst;
    u32 i;
    u32 nWords;
    u32 nBytes;
    u32 data;
    u32 err;
    u32 chan;
    s64 time;
    u32 *pInputBytes;
    u32 *src;
    u32 ctr;
    s32 left;
    u32 pad;

    siRegs = (u8 *)0xCC006400;
    comcsr = (u32 *)(siRegs + 0x34);
    sr = *(u32 *)0xCC006438;
    *(u32 *)(siRegs + 0x34) = (*(u32 *)0xCC006434 | 0x80000000) & ~1;
    si = &lbl_8029EF68;
    err = sr;
    pad = 0;
    if (si->chan != -1) {
        time = __OSGetSystemTime();
        pInputBytes = &si->inputBytes;
        i = 0;
        lbl_8033E388[si->chan] = time;
        dst = (u32 *)si->input;
        nWords = *pInputBytes >> 2;
        if (nWords > 0) {
            if (nWords > 8) {
                left = (s32)(nWords - 8);
                ctr = (u32)(left + 7) >> 3;
                if (left > 0) {
                    do {
                        i += 8;
                        dst[0] = *(u32 *)(siRegs + 0x80);
                        dst[1] = *(u32 *)(siRegs + 0x84);
                        dst[2] = *(u32 *)(siRegs + 0x88);
                        dst[3] = *(u32 *)(siRegs + 0x8C);
                        dst[4] = *(u32 *)(siRegs + 0x90);
                        dst[5] = *(u32 *)(siRegs + 0x94);
                        dst[6] = *(u32 *)(siRegs + 0x98);
                        data = *(u32 *)(siRegs + 0x9C);
                        siRegs += 0x20;
                        dst[7] = data;
                        dst += 8;
                    } while (--ctr);
                }
            }
            src = (u32 *)((u8 *)0xCC006400 + (i << 2));
            left = (s32)(nWords - i);
            if (i < nWords) {
                do {
                    data = *(u32 *)((u8 *)src + 0x80);
                    src += 1;
                    i += 1;
                    *dst = data;
                    dst += 1;
                } while (--left);
            }
        }
        nBytes = *pInputBytes & 3;
        if (nBytes != 0) {
            data = *(u32 *)((u8 *)0xCC006400 + (i << 2) + 0x80);
            i = 0;
            if (nBytes > 0) {
                if (nBytes > 8) {
                    left = (s32)(nBytes - 8);
                    ctr = (u32)(left + 7) >> 3;
                    if (left > 0) {
                        do {
                            ((u8 *)dst)[0] = (u8)(data >> ((3 - i) << 3));
                            ((u8 *)dst)[1] = (u8)(data >> ((3 - (i + 1)) << 3));
                            ((u8 *)dst)[2] = (u8)(data >> ((3 - (i + 2)) << 3));
                            ((u8 *)dst)[3] = (u8)(data >> (-i << 3));
                            ((u8 *)dst)[4] = (u8)(data >> ((3 - (i + 4)) << 3));
                            ((u8 *)dst)[5] = (u8)(data >> ((3 - (i + 5)) << 3));
                            ((u8 *)dst)[6] = (u8)(data >> ((3 - (i + 6)) << 3));
                            ((u8 *)dst)[7] = (u8)(data >> ((3 - (i + 7)) << 3));
                            dst = (u32 *)((u8 *)dst + 8);
                            i += 8;
                        } while (--ctr);
                    }
                }
                left = (s32)(nBytes - i);
                if (i < nBytes) {
                    do {
                        *(u8 *)dst = (u8)(data >> ((3 - i) << 3));
                        dst = (u32 *)((u8 *)dst + 1);
                        i += 1;
                    } while (--left);
                }
            }
        }
        if (*comcsr & 0x20000000) {
            chan = (u32)si->chan;
            err = (sr >> ((3 - chan) << 3)) & 0xF;
            if (err & 8) {
                if (!(Type_8029EFC0[chan] & 0x80)) {
                    Type_8029EFC0[chan] = 8;
                }
            }
            if (err == 0) {
                err = 4;
            }
        } else {
            time = __OSGetSystemTime();
            TypeTime[si->chan] = time;
            err = 0;
        }
        si->chan = -1;
    }
    (void)pad;
    return err;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void SIInterruptHandler(s32 interrupt, s32 context) {
    s64 __OSGetSystemTime(void);
    void OSCancelAlarm(void *);
    u32 fn_8023AC30(void);
    BOOL fn_8023B57C(s32, void *, u32, void *, u32, void *);
    s32 fn_8023B99C(s32);
    s32 SITransfer(s32, void *, u32, void *, u32, void *, s64);
    u32 fn_802117D8(void);
    extern void GetTypeCallback(s32, u32);
    extern u32 lbl_80368818;
    extern SIPacket Packet_8033E248[4];
    volatile u32 pad[2];
    SIPacket *pktBase;
    SIControl *si;
    s32 i;
    s32 j;
    SIPacket *packet;
    u32 sr;
    s32 chan;
    u32 xfer;
    void (*cb)(s32, u32, s32);
    u32 *typep;
    s32 ok;
    u32 vc;
    u32 rdst;
    volatile u32 *vcp;
    u32 *pollp;
    u32 poll;
    u32 bit;
    volatile u32 *vp;
    void (**rdstCb)(s32, s32);
    void (*handler)(s32, s32);
    u32 bus;
    u32 delay;
    u8 *alarm;
    u32 hi;
    u32 sh;
    void (*gtc)(s32, u32);
    u32 half;
    u32 *r3base;
    u32 *r4sic;
    u32 r5;

    pktBase = Packet_8033E248;
    si = &lbl_8029EF68;
    sr = *(volatile u32 *)0xCC006434;
    if ((u32)((sr & 0xC0000000) + 0x40000000) == 0) {
        chan = si->chan;
        xfer = fn_8023AC30();
        cb = (void (*)(s32, u32, s32))si->callback;
        i = 0;
        si->callback = (void *)i;
        j = chan;
        for (;;) {
            j = j + 1;
            j = j % 4;
            packet = (SIPacket *)((u8 *)pktBase + (j << 5));
            if (packet->chan != -1) {
                if (!(__OSGetSystemTime() < packet->fire)) {
                    if (fn_8023B57C(packet->chan, packet->output, packet->outputBytes,
                                    packet->input, packet->inputBytes, packet->callback)) {
                        alarm = (u8 *)pktBase + j * 0x28;
                        OSCancelAlarm(alarm + 0x80);
                        packet->chan = -1;
                    }
                    break;
                }
            }
            i += 1;
            if (i >= 4) {
                break;
            }
        }
        if (cb != 0) {
            (*cb)(chan, xfer, context);
        }
        r3base = (u32 *)0xCC000000;
        r4sic = r3base + (0x6400 / 4);
        r5 = r3base[0x6438 / 4];
        r5 &= (u32)((s32)0x0F000000 >> (chan * 8));
        r4sic[0x38 / 4] = r5;
        typep = (u32 *)((u8 *)si + (chan * 4));
        typep = (u32 *)((u8 *)typep + 0x58);
        if (*typep == 0x80) {
            ok = 1;
            if (((s32 *)pktBase)[chan * 8] == -1 && si->chan != chan) {
                ok = 0;
            }
            if (ok == 0) {
                bus = *(u32 *)0x800000F8;
                gtc = GetTypeCallback;
                bus >>= 2;
                delay = __mulhwu(0x431BDE83, bus);
                delay = delay >> 15;
                delay = delay * 0x41;
                delay = delay >> 3;
                SITransfer(chan, &lbl_80368818, 1, typep, 3, gtc, delay);
            }
        }
    }
    if ((u32)((sr & 0x18000000) + 0xE8000000) == 0) {
        vc = fn_802117D8();
        poll = *(u32 *)((u8 *)si + 0x48);
        vcp = (volatile u32 *)((u8 *)pktBase + 0x1E0);
        pollp = &si->unk48;
        vp = vcp;
        vc = vc + 1;
        rdst = (poll >> 16) & 0x3FF;
        i = 0;
        do {
            if (fn_8023B99C(i) != 0) {
                *vp = vc;
            }
            i += 1;
            vp += 1;
        } while (i < 4);
        poll = *pollp;
        half = rdst >> 1;
        hi = 0x80000000;
        sh = 0x18;
        bit = hi >> sh;
        if (poll & bit) {
            if (*vcp == 0) {
                goto out;
            }
            if (half + *vcp >= vc) {
                goto bit1;
            }
            goto out;
        }
    bit1:
        vp = vcp + 1;
        sh = 0x19;
        bit = hi >> sh;
        if (poll & bit) {
            if (*vp == 0) {
                goto out;
            }
            if (half + *vp >= vc) {
                goto bit2;
            }
            goto out;
        }
    bit2:
        vp = vp + 1;
        sh = 0x1A;
        bit = hi >> sh;
        if (poll & bit) {
            if (*vp == 0) {
                goto out;
            }
            if (half + *vp >= vc) {
                goto bit3;
            }
            goto out;
        }
    bit3:
        vp = vp + 1;
        sh = 0x1B;
        bit = hi >> sh;
        if (poll & bit) {
            if (*vp == 0) {
                goto out;
            }
            if (half + *vp >= vc) {
                goto bit4;
            }
            goto out;
        }
    bit4:
        i = 0;
        *vcp = i;
        rdstCb = (void (**)(s32, s32))((u8 *)pktBase + 0x1A0);
        *(u32 *)((u8 *)pktBase + 0x1E4) = i;
        *(u32 *)((u8 *)pktBase + 0x1E8) = i;
        *(u32 *)((u8 *)pktBase + 0x1EC) = i;
        do {
            handler = *rdstCb;
            if (handler != 0) {
                (*handler)(interrupt, context);
            }
            i += 1;
            rdstCb += 1;
        } while (i < 4);
    }
out:
    ;
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

BOOL SIEnablePollingInterrupt(BOOL enable) {
    BOOL enabled;
    BOOL rc;
    u32 reg;
    int i;

    enabled = OSDisableInterrupts();
    reg = __SIRegs[13];
    rc = (reg & 0x08000000) ? TRUE : FALSE;
    if (enable) {
        reg |= 0x08000000;
        for (i = 0; i < 4; i++) {
            InputBufferVcount[i] = 0;
        }
    } else {
        reg &= ~0x08000000;
    }
    reg &= ~(0x80000000 | 0x00000001);
    __SIRegs[13] = reg;
    OSRestoreInterrupts(enabled);
    return rc;
}

BOOL SIRegisterPollingHandler(void *handler) {
    /* Register an SI polling handler; enables RDST interrupt if a free slot is found. */
    BOOL enabled;
    int i;

    enabled = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        if ((void *)PollingHandler[i] == handler) {
            OSRestoreInterrupts(enabled);
            return TRUE;
        }
    }
    for (i = 0; i < 4; i++) {
        if (PollingHandler[i] == 0) {
            PollingHandler[i] = (u32)handler;
            SIEnablePollingInterrupt(TRUE);
            OSRestoreInterrupts(enabled);
            return TRUE;
        }
    }
    OSRestoreInterrupts(enabled);
    return FALSE;
}

s32 fn_8023B3D4(void *handler) {
 BOOL enabled;
 int i, j;
 enabled=OSDisableInterrupts();
 for(i=0;i<4;i++) {
 if((void *)PollingHandler[i]==handler) {
 PollingHandler[i]=0;
 for(j=0;j<4;j++) { if(PollingHandler[j]!=0) break; }
 if(j==4) SIEnablePollingInterrupt(0);
 OSRestoreInterrupts(enabled);
 return 1;
 }
 }
 OSRestoreInterrupts(enabled);
 return 0;
}

void SIInit(void) {
    void OSRegisterVersion(s32);
    void SISetSamplingRate(u32);
    void __OSSetInterruptHandler(s32, void *);
    void __OSUnmaskInterrupts(s32);
    u32 SIGetType(s32);
    extern s32 __SIVersion;
    extern s32 Si_8029EFAC[];
    extern void SIInterruptHandler(void);
    volatile u32 *reg;
    OSRegisterVersion(__SIVersion);
    Packet_8033E248[3].chan = -1;
    Packet_8033E248[2].chan = -1;
    Packet_8033E248[1].chan = -1;
    Packet_8033E248[0].chan = -1;
    Si_8029EFAC[1] = 0;
    SISetSamplingRate(0);
    do {
        reg = __SIRegs;
    } while (*(reg += 13) & 1);
    *reg = 0x80000000;
    __OSSetInterruptHandler(0x14, SIInterruptHandler);
    __OSUnmaskInterrupts(0x800);
    SIGetType(0);
    SIGetType(1);
    SIGetType(2);
    SIGetType(3);
}

BOOL fn_8023B57C(s32 chan, void *output, u32 outputBytes, void *input, u32 inputBytes, void *callback) {
    BOOL enabled;
    u32 i;
    u32 rlen;
    SIComCSR comcsr;
    u32 sr;
    SIControl *si;
    si = &lbl_8029EF68;
    enabled = OSDisableInterrupts();
    if (si->chan != -1) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }
    sr = ((volatile u32 *)0xCC000000)[0x6438 / 4];
    sr &= (u32)((s32)0x0F000000 >> (chan << 3));
    ((volatile u32 *)0xCC000000)[0x6438 / 4] = sr;
    rlen = (outputBytes + 3) / 4;
    si->chan = chan;
    si->callback = callback;
    si->inputBytes = inputBytes;
    si->input = input;
    for (i = 0; rlen > i; ++i) {
        __SIRegs[32 + i] = ((u32 *)output)[i];
    }
    comcsr.value = __SIRegs[13];
    comcsr.bits.tcint = 1;
    comcsr.bits.tcintmsk = callback ? 1 : 0;
    comcsr.bits.outlen = (u8)(outputBytes == 128 ? 0 : outputBytes);
    comcsr.bits.inlen = (u8)(inputBytes == 128 ? 0 : inputBytes);
    comcsr.bits.channel = chan;
    comcsr.bits.start = 1;
    __SIRegs[13] = comcsr.value;
    OSRestoreInterrupts(enabled);
    return TRUE;
}

u32 fn_8023B788(s32 chan) {
    extern u32 Type_8029EFC0[4];
    BOOL enabled;
    u32 status;

    enabled = OSDisableInterrupts();
    status = __SIRegs[14];
    status >>= (3 - chan) * 8;
    if (status & 8) {
        if (!(Type_8029EFC0[chan] & 0x80)) {
            Type_8029EFC0[chan] = 8;
        }
    }
    OSRestoreInterrupts(enabled);
    return status;
}

void fn_8023B804(s32 chan, u32 value) {
    __SIRegs[chan * 3] = value;
}

void fn_8023B818(void) {
    __SIRegs[14] = 0x80000000;
}

#pragma dont_inline on
u32 SISetXY(s32 chan, s32 xy) {
    BOOL OSDisableInterrupts(void);
    BOOL OSRestoreInterrupts(BOOL);
    extern u32 Si_8029EFAC[];
    BOOL enabled;
    u32 *p;
    u32 cmd;

    cmd = chan << 16;
    cmd |= xy << 8;
    enabled = OSDisableInterrupts();
    p = &Si_8029EFAC[1];
    *p &= 0xFC0000FF;
    *p |= cmd;
    cmd = *p;
    __SIRegs[12] = cmd;
    OSRestoreInterrupts(enabled);
    return cmd;
}
#pragma dont_inline reset

u32 fn_8023B894(u32 type) {
 extern u32 Si_8029EFAC[];
 BOOL enabled; u32 *p; u32 mask;
 if (type == 0) return Si_8029EFAC[1];
 enabled=OSDisableInterrupts();
 p=&Si_8029EFAC[1];
 type >>= 24;
 mask=(type >> 4)&15;
 *p &= ~mask;
 type &= mask | 0x03FFFFF0;
 type &= 0xFC0000FF;
 *p |= type;
 type=*p;
 __SIRegs[14]=0x80000000;
 __SIRegs[12]=type;
 OSRestoreInterrupts(enabled);
 return type;
}

u32 fn_8023B930(u32 type) {
    extern u32 Si_8029EFAC[];
    BOOL enabled;
    u32 *p;

    if (type == 0) {
        return Si_8029EFAC[1];
    }
    enabled = OSDisableInterrupts();
    p = &Si_8029EFAC[1];
    type = __rlwinm(type, 8, 24, 27);
    type = *p & ~type;
    __SIRegs[12] = type;
    *p = type;
    OSRestoreInterrupts(enabled);
    return type;
}

s32 fn_8023B99C(s32 chan)
{
  struct SIState
  {
    u8 pad[0x1B0];
    u32 ready[4];
    u32 response[4][2];
  };
  struct SIState *packet = (struct SIState *) Packet_8033E248;
  volatile u32 *si;
  u32 offset;
  if (fn_8023B788(chan) & 0x20)
  {
    ;
    offset = chan << 3;
    packet->response[chan][0] = (&__SIRegs[chan * 3])[1];
    packet->response[chan][1] = (&__SIRegs[chan * 3])[2];
    packet->ready[chan] = 1;
    return 1;
  }
  return 0;
}

#pragma dont_inline on
s32 fn_8023BA70(s32 chan, u32 *out)
{
  struct SIState
  {
    u8 pad[0x1B0];
    u32 ready[4];
    u32 response[4][2];
  };
  struct SIState *packet = (struct SIState *)Packet_8033E248;
  u32 interrupts;
  s32 result;

  interrupts = OSDisableInterrupts();
  if (fn_8023B788(chan) & 0x20) {
    packet->response[chan][0] = (&__SIRegs[chan * 3])[1];
    packet->response[chan][1] = (&__SIRegs[chan * 3])[2];
    packet->ready[chan] = 1;
  }
  result = packet->ready[chan];
  packet->ready[chan] = 0;
  if (result != 0) {
    out[0] = packet->response[chan][0];
    out[1] = packet->response[chan][1];
  }
  OSRestoreInterrupts(interrupts);
  return result;
}
#pragma dont_inline reset
void fn_8023BB34(void *alarm, void *context) {
    extern SIAlarm lbl_8033E2C8[4];
    extern SIPacket Packet_8033E248[4];
    s32 fn_8023B57C(s32, void *, u32, void *, u32, void *);
    s32 chan;
    SIPacket *packet;

    chan = (SIAlarm *)alarm - lbl_8033E2C8;
    packet = &Packet_8033E248[chan];
    if (packet->chan != -1) {
        if (fn_8023B57C(packet->chan, packet->output, packet->outputBytes, packet->input, packet->inputBytes, packet->callback)) {
            packet->chan = -1;
        }
    }
}

s32 SITransfer(s32 chan, void *output, u32 outputBytes, void *input, u32 inputBytes, void *callback, s64 delay) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s64 __OSGetSystemTime(void);
    void OSSetAlarm(void *, s64, void (*)(void *, void *));
    extern s32 Si_8029EFAC[];
    s32 enabled;
    s64 fire;
    s64 now;
    SIPacket *packet;
    u8 *base;
    u8 *alarm;
    base = (u8 *)Packet_8033E248;
    packet = &Packet_8033E248[chan];
    enabled = OSDisableInterrupts();
    if (packet->chan != -1 || Si_8029EFAC[0] == chan) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    now = __OSGetSystemTime();
    if (delay == 0) fire = now;
    else {
        fire = delay + XferTime[chan];
    }
    if (now < fire) {
        delay = fire - now;
        alarm = base + chan * 0x28;
        OSSetAlarm(alarm + 0x80, delay, fn_8023BB34);
    } else if (fn_8023B57C(chan, output, outputBytes, input, inputBytes, callback)) {
        OSRestoreInterrupts(enabled);
        return 1;
    }
    packet->chan = chan;
    packet->output = output;
    packet->outputBytes = outputBytes;
    packet->input = input;
    packet->inputBytes = inputBytes;
    packet->callback = callback;
    packet->fire = fire;
    OSRestoreInterrupts(enabled);
    return 1;
}

#pragma global_optimizer off
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma optimization_level 1
void GetTypeCallback(s32 chan, u32 type) {
    s32 SITransfer(s32, void *, u32, void *, u32, void *, s64);
    s64 __OSGetSystemTime(void);
    void fn_80209C10(s32, u16);
    s32 fn_80209B8C(s32);
    extern u32 Type_8029EFC0[4];
    extern u32 lbl_80368820;
    extern SIPacket Packet_8033E248[4];
    s64 pad;
    s32 clear;
    s32 i;
    u32 typeVal;
    void **cbs;
    void (*cb)(s32, u32);
    u32 *typep;
    s32 chan4;
    u32 typeArg;
    u32 cmd;
    s32 needFix;
    u32 poll;
    u32 chanBit;
    u32 t;
    u32 *cmdBase;
    u8 *packet;
    u8 *timep;
    s64 time;
    s64 *padp;

    padp = &pad;
    packet = (u8 *)Packet_8033E248;
    typeArg = type;
    chan4 = chan * 4;
    typep = (u32 *)((u8 *)Type_8029EFC0 + chan4);
    *typep &= ~0x80;
    *typep |= typeArg;
    time = __OSGetSystemTime();
    timep = packet + (chan << 3);
    *(s64 *)(timep + 0x120) = time;
    chanBit = 0x80000000U >> chan;
    poll = lbl_80368820;
    t = *typep;
    lbl_80368820 = poll & ~chanBit;
    needFix = (s32)(poll & chanBit);
    if ((typeArg & 0xF) || ((t & 0x18000000) != 0x08000000) || !(t & 0x80000000) || (t & 0x04000000)) {
        fn_80209C10(chan, 0);
        typeVal = *typep;
        cbs = (void **)(packet + (chan << 4));
        i = 0;
        clear = SI_CopyS32(i);
        cbs = (void **)((u8 *)cbs + 0x160);
        do {
            cb = (void (*)(s32, u32))*cbs;
            if (cb != 0) {
                *cbs = (void *)clear;
                (*cb)(chan, typeVal);
            }
            i += 1;
            cbs += 1;
        } while (i < 4);
        return;
    }
    cmd = ((u32)fn_80209B8C(chan) << 8) & 0xFFFF00;
    if (needFix != 0 && (cmd & 0x100000)) {
        cmdBase = (u32 *)(packet + chan4);
        *(u32 *)((u8 *)cmdBase + 0x1F0) = (cmd & 0xCFFF00) | 0x4E100000;
        *typep = 0x80;
        SITransfer(chan, (u8 *)cmdBase + 0x1F0, 3, typep, 3, GetTypeCallback, 0);
        return;
    }
    if (t & 0x100000) {
        if ((cmd & 0xCFFF00) != (t & 0xCFFF00)) {
            if (!(cmd & 0x100000)) {
                cmd = (t & 0xCFFF00) | 0x100000;
                fn_80209C10(chan, (u16)(cmd >> 8));
            }
            cmdBase = (u32 *)(packet + chan4);
            *(u32 *)((u8 *)cmdBase + 0x1F0) = cmd | 0x4E000000;
            *typep = 0x80;
            SITransfer(chan, (u8 *)cmdBase + 0x1F0, 3, typep, 3, GetTypeCallback, 0);
            return;
        }
    } else if (t & 0x40000000) {
        t &= 0xCFFF00;
        t |= 0x100000;
        fn_80209C10(chan, (u16)(t >> 8));
        cmdBase = (u32 *)(packet + chan4);
        *(u32 *)((u8 *)cmdBase + 0x1F0) = t | 0x4E000000;
        *typep = 0x80;
        SITransfer(chan, (u8 *)cmdBase + 0x1F0, 3, typep, 3, GetTypeCallback, 0);
        return;
    } else {
        fn_80209C10(chan, 0);
    }
    typeVal = *typep;
    cbs = (void **)(packet + (chan << 4));
    i = 0;
    clear = SI_CopyS32(i);
    cbs = (void **)((u8 *)cbs + 0x160);
    do {
        cb = (void (*)(s32, u32))*cbs;
        if (cb != 0) {
            *cbs = (void *)clear;
            (*cb)(chan, typeVal);
        }
        i += 1;
        cbs += 1;
    } while (i < 4);
    (void)padp;
}
#pragma optimization_level reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma global_optimizer reset

u32 SIGetType(s32 chan) {
s64 __OSGetSystemTime(void);
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
extern u32 Type_8029EFC0[4];
extern s32 Si_8029EFAC[];
extern s64 TypeTime_8033E368[4];
static u32 cmdTypeAndStatus;
s32 enabled;
u32 type;
s64 elapsed;
enabled=OSDisableInterrupts();
type=Type_8029EFC0[chan];
elapsed=__OSGetSystemTime()-TypeTime_8033E368[chan];
if(Si_8029EFAC[1] & (0x80>>chan)) {
if(type!=8) {
TypeTime_8033E368[chan]=__OSGetSystemTime();
OSRestoreInterrupts(enabled); return type;
}
{Type_8029EFC0[chan]=0x80; type=0x80;}
} else {
if(elapsed <= (s64)(50*((*(volatile u32*)0x800000F8/4)/1000)) && type!=8) {
OSRestoreInterrupts(enabled); return type;
}
if(elapsed <= (s64)(75*((*(volatile u32*)0x800000F8/4)/1000))) Type_8029EFC0[chan]=0x80;
else {Type_8029EFC0[chan]=0x80; type=0x80;}
}
TypeTime_8033E368[chan]=__OSGetSystemTime();
SITransfer(chan,&cmdTypeAndStatus,1,&Type_8029EFC0[chan],3,GetTypeCallback,(s64)((65*((*(volatile u32*)0x800000F8/4)/125000))/8));
OSRestoreInterrupts(enabled); return type;
}

extern u16 lbl_802822F0[200];
extern s32 SIEnablePolling(s32 param_1);
extern s32 SIDisablePolling(s32 param_1);
u32 fn_8023C188(s32 chan, void (*callback)(s32, u32)) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    u32 SIGetType(s32);
    extern void (*lbl_8033E3A8[4][4])(s32, u32);
    extern u32 Type_8029EFC0[4];
    s32 enabled;
    u32 type;
    s32 i;
    void (**callbacks)(s32, u32);
    enabled = OSDisableInterrupts();
    type = SIGetType(chan);
    if (Type_8029EFC0[chan] & 0x80) {
        callbacks = lbl_8033E3A8[chan];
        for (i = 0; i < 4; i++) {
            if (callbacks[i] == callback) break;
            if (callbacks[i] == 0) {
                callbacks[i] = callback;
                break;
            }
        }
    } else {
        callback(chan, type);
    }
    OSRestoreInterrupts(enabled);
    return type;
}

u32 fn_8023C2C4(u32 type) {
    u32 error = type & 0xFF;
    u32 device = type & 0xFFFFFF00;
    if (type & 8) return 8;
    if (error & 0x47) return 0x40;
    if (error != 0) return 0x80;
    if ((device & 0x18000000) == 0) {
        switch ((s32)(device & 0xFFFF0000)) {
        case 0x10000: case 0x20000: case 0x40000: case 0x02000000: case 0x05000000:
            return device & 0xFFFF0000;
        default: return 0x40;
        }
    }
    if ((device & 0x18000000) != 0x08000000) return 0x40;
    {
        switch ((s32)(device & 0xFFFF0000)) {
        case 0x08000000: case 0x09000000: return device & 0xFFFF0000;
        }
        if ((device & 0xFFE00000) == 0x08200000) return 0x08200000;
        if ((device & 0x80000000) && !(device & 0x04000000)) {
            if ((device & 0x8B100000) == 0x8B100000) return 0x8B100000;
            if (!(device & 0x02000000)) return 0x88000000;
        }
        if ((device & 0x09000000) == 0x09000000) return 0x09000000;
        return 0x40;
    }
}

u32 fn_8023C410(s32 chan) {
    u32 SIGetType(s32);
    u32 fn_8023C2C4(u32);
    return fn_8023C2C4(SIGetType(chan));
}

#pragma optimization_level 4
void SISetSamplingRate(u32 rate) {
    extern u8 XYNTSC_8029F080[48];
    extern u32 SamplingRate_80368828;
    s32 VIGetTvFormat(void);
    void OSReport(const char *, ...);
    u32 SISetXY(s32, s32);
    u8 *base;
    u8 *table;
    BOOL enabled;
    u32 scale;

    base = &XYNTSC_8029F080[0];
    if (rate > 11) {
        rate = 11;
    }
    enabled = OSDisableInterrupts();
    SamplingRate_80368828 = rate;
    switch (VIGetTvFormat()) {
    case 0:
    case 2:
    case 5:
        table = base;
        break;
    case 1:
        table = base + 0x30;
        break;
    default:
        OSReport((char *)(base + 0x60));
        rate = 0;
        table = base;
        break;
    }
    if (*(volatile u16 *)0xCC00206C & 1) {
        scale = 2;
    } else {
        scale = 1;
    }
    SISetXY((s32)(scale * *(u16 *)(table + rate * 4)), (s32)table[rate * 4 + 2]);
    OSRestoreInterrupts(enabled);
}
void fn_8023C518(void) {
    void SISetSamplingRate(u32);
    extern u32 SamplingRate_80368828;
    SISetSamplingRate(SamplingRate_80368828);
}
