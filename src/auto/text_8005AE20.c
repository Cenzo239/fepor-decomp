/* Functions from 0x8005AE20 to 0x80072408, found by decomp-toolkit. */
#include "common.h"
#include "global.h"

typedef struct MaterialColor { u8 r, g, b, a; } MaterialColor;

typedef struct {
    s32 at0[16];
    s32 at40[8];
    s32 at60[8];
    s32 at80[16];
} StagePool;

// Structure definition for the argument passed to fn_80063A14
typedef struct {
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkC;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    s32 unk34;
} SomeStruct;

struct UnkStruct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

extern u16 gBattleState[1400];
extern f32 lbl_803692E0;
extern f32 lbl_80369300;
extern f32 lbl_8036930C;
extern f64 lbl_803692C0;
extern f32 lbl_803692B8;
extern u16 lbl_80285D18[];
extern char lbl_8026B590[];
extern f32 lbl_803691E0;
extern f32 lbl_803691E4;
extern f32 lbl_803691E8;
extern u8 lbl_8026B658[];

static inline u8 *FindEntryByName(char *name) {
    extern u8 gFileCache[];
    s32 Str_Cmp();
    u8 *e;
    char *start;
    u32 hash;
    s32 i;

    if (*name == '/') {
        name++;
    }
    start = name;
    hash = 0;
    while (*name != 0) {
        if (*name >= 'A' && *name <= 'Z') {
            *name += 0x20;
        }
        hash = *name++ + hash * 37;
    }
    for (i = 0, e = gFileCache; i < 0x400; i++, e += 0x7C) {
        if (hash == *(u32 *)(e + 0x2C) && Str_Cmp(start, e) == 0) {
            return gFileCache + i * 0x7C;
        }
    }
    return NULL;
}

static inline u32 FindUnk48(void *arg0) {
    while (arg0 != NULL) {
        u32 temp = M2C_FIELD(arg0, u32 *, 0x48);
        if (temp != 0U) {
            return temp;
        }
        arg0 = M2C_FIELD(arg0, void **, 4);
    }
    return 0U;
}

static inline u32 CalcUnk48Size(u32 found) {
    s16 t = M2C_FIELD(M2C_FIELD(found, void **, 0x48), s16 *, 0xA);
    return (((t * 12) + 31) & ~31) / 2 * 2;
}

static inline u32 AddUnk48Size(u32 base, void *node) {
    void *current = node;

    while (current != NULL) {
        u32 temp = M2C_FIELD(current, u32 *, 0x48);
        if (temp != 0U) {
            return base + CalcUnk48Size(temp);
        }
        current = M2C_FIELD(current, void **, 4);
    }
    return base + CalcUnk48Size(0);
}

void *fn_8005AE20(void) {
    extern u8 lbl_8026AE88[];

    return lbl_8026AE88 + 9;
}

s32 fn_8005AE30(void) {
    return 1;
}

s32 fn_8005AE38(void) {
    return 0x400;
}

s32 fn_8005AE40(void) {
    return 0x60;
}

s32 fn_8005AE48(void) {
    return 0x20;
}

s32 fn_8005AE50(void) {
    return 2;
}

s32 fn_8005AE58(void) {
    return 0x20;
}

s32 fn_8005AE60(void) {
    return 0x20;
}

void *fn_8005AE68(void) {
    extern u8 lbl_8026AE88[];

    return lbl_8026AE88 + 9;
}

void Game_PollSoftReset(void) {
    /* Hold Start+X+B for 30 frames or release the reset switch to soft-reset. */
    void OSResetSystem(s32, s32, s32);
    u8 fn_80014E70(void);
    void fn_800B46D8(void);
    s32 fn_80208D18(void);
    void VIWaitForRetrace(void);
    void VIFlush(void);
    void fn_80211614(s32);
    void fn_8022097C(void);
    extern s32 gUiInputFlags;
    extern void *gPadInput;
    extern s32 gSoftResetHoldCount;
    extern s8 gSoftResetHoldInited;
    extern u8 gResetSwitchWasHeld;
    extern s8 gResetSwitchTrackInited;
    extern u8 gSoftResetRequested;
    extern s8 gSoftResetReqInited;
    extern u32 gGameFlags;
    s32 holdCount;
    s32 resetCode;
    u16 buttons;

    if (gSoftResetHoldInited == 0) {
        gSoftResetHoldCount = 0;
        gSoftResetHoldInited = 1;
    }
    if (gResetSwitchTrackInited == 0) {
        gResetSwitchWasHeld = 0;
        gResetSwitchTrackInited = 1;
    }
    if (gSoftResetReqInited == 0) {
        gSoftResetRequested = 0;
        gSoftResetReqInited = 1;
    }
    buttons = **(u16 **)gPadInput;
    holdCount = (buttons == 0x1600) ? (gSoftResetHoldCount + 1) : 0;
    gSoftResetHoldCount = holdCount;
    if (holdCount >= 0x1E) {
        gSoftResetRequested = 1;
    }
    if (gResetSwitchWasHeld != 0 && fn_80208D18() == 0) {
        gSoftResetRequested = 1;
    }
    gResetSwitchWasHeld = fn_80208D18() != 0;
    if (!(gUiInputFlags & 0x100) && gSoftResetRequested != 0) {
        fn_80211614(1);
        VIFlush();
        VIWaitForRetrace();
        VIWaitForRetrace();
        fn_8022097C();
        VIWaitForRetrace();
        VIWaitForRetrace();
        VIWaitForRetrace();
        resetCode = 0;
        if (gGameFlags & 0x90000) {
            if (!(gGameFlags & 0x10)) {
                resetCode |= 2;
            }
            if (gGameFlags & 0x40) {
                resetCode |= 1;
            }
        } else if (gGameFlags & 0x60000) {
            if (!(gGameFlags & 0x10)) {
                resetCode |= 0x20;
            }
            if (gGameFlags & 0x100) {
                resetCode |= 0x10;
            }
        }
        if (fn_80014E70() != 0) {
            resetCode |= 0x100;
            fn_800B46D8();
        }
        OSResetSystem(0, resetCode, 0);
        while (1) {}
    }
}

#pragma push
#pragma use_lmw_stmw on
#pragma opt_loop_invariants off
void fn_8005B010(void *file, s32 line, s32 kind, char *format, ...) {
    typedef struct { char gpr, fpr, reserved[2]; char *input_arg_area; char *reg_save_area; } VaInfo;
    s32 fn_8005B42C(u32 *, u32);
    s32 fn_8005B448(s32, s32, s32 *, u8 (*)(s32,s32));
    void DebugPrint(const char *, ...);
    void *fn_80205B50(void);
    s32 vsprintf(char *, const char *, void *);
    void fn_800056AC(void);
    void fn_80005720(u16, s32);
    void fn_800059B0(void);
    void fn_80025970(void);
    void *fn_8002595C(s32);
    u32 fn_80211690(void);
    void fn_80211614(s32);
    void GXCopyDisp(void *, s32);
    void VISetNextFrameBuffer(void *);
    void VIFlush(void);
    void VIWaitForRetrace(void);
    void fn_8022097C(void);
    s32 fn_80208D18(void);
    u8 fn_80014E70(void);
    void fn_800B46D8(void);
    void OSResetSystem(s32, s32, s32);
    extern char lbl_8026AEA8[];
    extern u32 lbl_802F0398[];
    extern u32 lbl_803672D8;
    extern void *DemoCurrentBuffer, *DemoFrameBuffer1, *DemoFrameBuffer2;
    extern s8 gSoftResetHoldInited, gResetSwitchTrackInited, gSoftResetReqInited;
    extern u8 gResetSwitchWasHeld, gSoftResetRequested;
    extern s32 gSoftResetHoldCount, gUiInputFlags;
    extern void *gPadInput;
    extern u32 gGameFlags;
    s32 address;
    VaInfo args[1];
    char buffer[512];
    u16 buttons;
    void *frame;
    u32 count;
    u32 *table;
    u32 end, begin;
    void *entry;
    u32 tick;
    s32 holdCount;
    s32 resetCode;
    DebugPrint(lbl_8026AEA8 + 0x212);
    DebugPrint(lbl_8026AEA8 + 0x231);
    count = 0;
    frame = fn_80205B50();
    table = lbl_802F0398;
    while (frame && frame != (void *)-1 && count++ < 16) {
        address = M2C_FIELD(frame, s32 *, 4);
        if (!lbl_803672D8) entry = NULL;
        else {
            begin = table[1];
            end = begin + lbl_802F0398[0] * 8;
            entry = (void *)fn_8005B448(begin, end, &address, (u8 (*)(s32,s32))fn_8005B42C);
            if ((u32)entry == begin || (u32)entry == end) entry = NULL;
            else entry = (u8 *)entry - 8;
        }
        if (!entry) DebugPrint(lbl_8026AEA8 + 0x247, frame, M2C_FIELD(frame, u32 *, 4));
        else DebugPrint(lbl_8026AEA8 + 0x257, frame, M2C_FIELD(frame, u32 *, 4), M2C_FIELD(entry, u32 *, 4), M2C_FIELD(frame, u32 *, 4) - M2C_FIELD(entry, u32 *, 0));
        frame = M2C_FIELD(frame, void **, 0);
    }
    __builtin_va_info(&args);
    vsprintf(buffer, format, args);
    DebugPrint(lbl_8026AEA8 + 0x26e);
    DebugPrint(lbl_8026AEA8 + 0x29b, buffer);
    DebugPrint(lbl_8026AEA8 + 0x2a1, file, line, kind);
    fn_800056AC();
    do {
        tick = fn_80211690();
        fn_80025970();
        buttons = M2C_FIELD(fn_8002595C(0), u32 *, 4);
        buttons |= M2C_FIELD(fn_8002595C(1), u32 *, 4);
        buttons |= M2C_FIELD(fn_8002595C(2), u32 *, 4);
        buttons |= M2C_FIELD(fn_8002595C(3), u32 *, 4);
        fn_80005720(buttons & ~0x10, 0);
        fn_800059B0();
        GXCopyDisp(DemoCurrentBuffer, 1);
        VISetNextFrameBuffer(DemoCurrentBuffer);
        fn_80211614(0);
        VIFlush();
        while (tick == fn_80211690()) {}
        DemoCurrentBuffer = DemoCurrentBuffer == DemoFrameBuffer1 ? DemoFrameBuffer2 : DemoFrameBuffer1;
        if (!gSoftResetHoldInited) { gSoftResetHoldCount=0; gSoftResetHoldInited=1; }
        if (!gResetSwitchTrackInited) { gResetSwitchWasHeld=0; gResetSwitchTrackInited=1; }
        if (!gSoftResetReqInited) { gSoftResetRequested=0; gSoftResetReqInited=1; }
        buttons = **(u16 **)gPadInput;
        holdCount = (buttons == 0x1600) ? gSoftResetHoldCount + 1 : 0;
        gSoftResetHoldCount = holdCount;
        if (holdCount >= 30) gSoftResetRequested=1;
        if (gResetSwitchWasHeld && !fn_80208D18()) gSoftResetRequested=1;
        gResetSwitchWasHeld = fn_80208D18() != 0;
    } while ((gUiInputFlags & 0x100) || !gSoftResetRequested);
    fn_80211614(1); VIFlush(); VIWaitForRetrace(); VIWaitForRetrace();
    fn_8022097C(); VIWaitForRetrace(); VIWaitForRetrace(); VIWaitForRetrace();
    resetCode=0;
    if (gGameFlags & 0x90000) {
        if (!(gGameFlags & 0x10)) resetCode |= 2;
        if (gGameFlags & 0x40) resetCode |= 1;
    } else if (gGameFlags & 0x60000) {
        if (!(gGameFlags & 0x10)) resetCode |= 0x20;
        if (gGameFlags & 0x100) resetCode |= 0x10;
    }
    if (fn_80014E70()) { resetCode |= 0x100; fn_800B46D8(); }
    OSResetSystem(0, resetCode, 0);
    for (;;) {}
}
#pragma pop
s32 fn_8005B42C(u32 *arg0, u32 arg1) {
    return (u32) *arg0 <= arg1;
}

#pragma use_lmw_stmw on
s32 fn_8005B448(s32 arg0, s32 arg1, s32 *arg2, u8 (*arg3)(s32, s32)) {
    s32 count;
    s32 mid_ptr;
    s32 mid;

    count = (arg1 - arg0) / 8;
    while (count > 0) {
        mid = count / 2;
        mid_ptr = arg0 + (mid * 8);
        if (arg3(mid_ptr, *arg2) != 0) {
            arg0 = mid_ptr + 8;
            count -= mid + 1;
        } else {
            count = mid;
        }
    }
    return arg0;
}
#pragma use_lmw_stmw off

#pragma global_optimizer off
s32 fn_8005B4D8(s32 arg0) {
    s32 Hash_Lookup(void *);
    void *Res_GetByName(void *);
    s32 Bin_ReadU32(s32 *);
    void Bin_ReadU8(s32 *);
    extern u8 lbl_8026B308[];
    s32 sp8;
    s32 i;

    if (Res_GetByName(lbl_8026B308 + 8) != 0) {
        sp8 = Hash_Lookup(lbl_8026B308 + 8);
        Bin_ReadU8(&sp8);
        Bin_ReadU8(&sp8);
        Bin_ReadU8(&sp8);
        Bin_ReadU8(&sp8);
        for (i = 0; i < arg0; i++) {
            Bin_ReadU32(&sp8);
        }
        return Bin_ReadU32(&sp8);
    }
    return 0;
}

static inline u32 HashString(u8 *s) {
    u32 hash;
    u8 b;
    hash = 0;
    while ((b = *s, (s8)b != 0)) {
        hash += b;
        s++;
        hash <<= 4;
    }
    return hash;
}

static inline u32 ColFromHash(u32 hash) {
    extern u32 lbl_802F03A8[0x4D];
    u32 *p;
    s32 i;
    s32 ctr;
    p = lbl_802F03A8;
    i = 0;
    for (ctr = 0x4D; ctr != 0; ctr--) {
        if (hash == *p) {
            switch (i) {
            case 9:
            case 0x21:
                return 0x1C;
            default:
                return (u8)i;
            }
        }
        p++;
        i++;
    }
    return 0;
}

#pragma use_lmw_stmw on
u32 fn_8005B580(void *arg0, u8 *name, u8 flag) {
    s32 Hash_Lookup(void *);
    u16 fn_8001B91C(s32 *);
    u32 Bin_ReadU32(s32 *);
    s32 Str_Cmp(void *, void *);
    extern u8 lbl_8026B308[];
    s32 sp[3];
    u32 h;
    u32 var_r0;
    s32 off;
    u8 col;
    s32 idx;
    u16 stride;
    u16 count;
    s32 j;
    u32 result;

    h = HashString(*(u8 **)arg0);
    var_r0 = ColFromHash(h);
    col = (u8)var_r0;
    idx = -1;
    sp[2] = Hash_Lookup(lbl_8026B308 + 0x16);
    stride = (u16)fn_8001B91C(&sp[2]);
    count = (u16)fn_8001B91C(&sp[2]);
    if (name == 0 || (s8)*name == 0) {
        idx = 0;
    } else {
        j = 0;
        off = 0;
        while (j < (s32)count) {
            sp[1] = sp[2] + (off * 4);
            if (Str_Cmp((void *)Bin_ReadU32(&sp[1]), name) == 0) {
                idx = j;
                break;
            }
            off = stride + off;
            j++;
            off++;
        }
    }
    if (idx < 0) {
        if (flag != 0) {
            return 0;
        }
        idx = 0;
    }
    off = (stride + 1) * idx;
    off += 1;
    sp[0] = sp[2] + ((col + off) * 4);
    result = Bin_ReadU32(&sp[0]);
    if (result == 0) {
        if (flag != 0) {
            return 0;
        }
        sp[0] = sp[2] + (off * 4);
        result = Bin_ReadU32(&sp[0]);
    }
    return result;
}
void fn_8005B73C(void *arg0) {
    M2C_UNK Msg_Expand(s32);
    Msg_Expand(M2C_FIELD(arg0, s32 *, 4));
}

#pragma optimization_level 4
