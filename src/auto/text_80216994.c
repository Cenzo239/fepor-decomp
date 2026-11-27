/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"



#include <dolphin/os.h>
#include "global.h"
#include "ef.h"
static inline u32 Card_ReverseScramble(u32 count, u32 value) {
    u32 i;
    for (i = 0; i < count; ++i) {
        u32 bits = ~((value >> 23) ^ ((value >> 15) ^ (value ^ (value >> 7))));
        value = (value >> 1) | ((bits << 30) & 0x40000000);
    }
    return value | (~((value >> 23) ^ ((value >> 15) ^ (value ^ (value >> 7)))) << 31);
}
static inline u32 Card_AdvanceScramble(u32 count, u32 value) {
 u32 i;
 for(i=0;i<count;++i) {
  u32 bits=~((value<<23)^((value<<15)^(value^(value<<7))));
  value=(value<<1)|((bits>>30)&2);
 }
 return value | (~((value<<23)^((value<<15)^(value^(value<<7))))>>31);
}



typedef struct CardDirEntry {
    u8 unk0[4];
    u8 unk4[2];
    u8 pad6[1];
    u8 unk7;
    u8 unk8[0x20];
    s32 unk28;
    s32 unk2C;
    u16 unk30;
    u16 unk32;
    u8 unk34;
    u8 unk35;
    u8 pad36[6];
    s32 unk3C;
} CardDirEntry;
extern s32 gSaveDataBase;
extern s32 fn_80013E50(s32);
extern s32 fn_80013E60(s32, s32);
extern s32 fn_80013E74(void*, s32);

extern u8 lbl_8033A420[];
extern u8 lbl_80366FF2;
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
extern void* lbl_80368648;
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

typedef struct CardCtrl {
    u8 unk0[0xC];
    u32 sectorSize;
    u8 unk10[0xAC];
    u16 fileNo;
    u8 unkBE[2];
    void *apiFd;
    u8 unkC4[0xC];
    void *apiCb;
    u8 unkD4[0x38];
    void *diskID;
} CardCtrl;

void fn_80216994(void) {

}

void fn_80216998(s32 chan, s32 result) {
    void fn_8020AEC4(void *);
    extern u8 __CARDBlock[];
    fn_8020AEC4(__CARDBlock + chan * 0x110 + 0x8c);
}

void fn_802169CC(s32 chan) {
    extern u16 __CARDBlock[];
    void fn_80239298(s32, void *);
    void OSCancelAlarm(void *);
    u8 *card;
    void (*callback)(s32,s32);
    card = (u8 *)__CARDBlock + chan * 0x110;
    if (*(s32 *)card != 0) {
        *(s32 *)card = 0;
        fn_80239298(chan, 0);
        OSCancelAlarm(card + 0xE0);
        callback = *(void (**)(s32,s32))(card + 0xCC);
        if (callback) {
            *(void **)(card + 0xCC) = 0;
            callback(chan, -3);
        }
        if (*(s32 *)(card + 4) != -1) *(s32 *)(card + 4) = -3;
        callback = *(void (**)(s32,s32))(card + 0xC4);
        if (callback && *(s32 *)(card + 0x24) >= 7) {
            *(void **)(card + 0xC4) = 0;
            callback(chan, -3);
        }
    }
}

void fn_80216AA4(s32 chan) {
    extern u16 __CARDBlock[];
    void OSCancelAlarm(void *);
    s32 EXILock(s32,s32,void*);
    void EXIUnlock(s32);
    s32 fn_80216DA8(s32,s32*);
    s32 fn_80216F88(s32);
    s32 __CARDRetry(s32);
    u8 status;
    void (*callback)(s32,s32);
    u8 *card;
    s32 result;
    s32 error;
    card=(u8*)__CARDBlock+chan*0x110;
    OSCancelAlarm(card+0xe0);
    if(*(s32*)card) {
        if(!EXILock(chan,0,0)) {
            result=-128;
            goto done;
        }
        result=fn_80216DA8(chan,(s32*)&status);
        if(result>=0) {
            result=fn_80216F88(chan);
            if(result>=0) {
                error=(status&0x18)?-5:0;
                result=error;
                if(result==-5) {
                    if(--*(s32*)(card+0xa8)>0) {
                        result=__CARDRetry(chan);
                        if(result>=0) return;
                        goto done;
                    }
                }
            }
        }
        EXIUnlock(chan);
done:
        callback=*(void(**)(s32,s32))(card+0xcc);
        if(callback) {
            *(void**)(card+0xcc)=0;
            callback(chan,result);
        }
    }
}

void __CARDTxHandler(s32 chan) {
    s32 EXIDeselect(s32);
    s32 EXIUnlock(s32);
    s32 fn_80239488(s32);
    extern u16 __CARDBlock[];
    s32 failed;
    s32 success;
    u8 *card;
    void (*callback)(s32,s32);
    card = (u8 *)__CARDBlock + chan * 0x110;
    failed = !EXIDeselect(chan);
    EXIUnlock(chan);
    callback = *(void (**)(s32,s32))(card+0xC8);
    if (callback) {
        *(void (**)(s32,s32))(card+0xC8) = 0;
        success = !failed && fn_80239488(chan);
        callback(chan, success ? 0 : -3);
    }
}

void __CARDLockCallback(s32 chan) {
    s32 fn_80239488(s32);
    extern u16 __CARDBlock[];
    u8 *card;
    void (*callback)(s32,s32);
    s32 result;
    card = (u8 *)__CARDBlock + chan * 0x110;
    callback = *(void (**)(s32,s32))(card+0xDC);
    if (callback != 0) {
        *(void (**)(s32,s32))(card+0xDC) = 0;
        if (fn_80239488(chan) != 0) result = 1;
        else result = -3;
        callback(chan,result);
    }
}

s32 fn_80216CE8(s32 arg0, s32 arg1) {
    s32 EXIDeselect(s32);
    s32 EXIImm(s32, s32 *, s32, s32, s32);
    s32 EXISelect(s32, s32, s32);
    s32 EXISync(s32);
    s32 sp10;
    s32 temp_r31;
    if (EXISelect(arg0, 0, 4) == 0) {
        return -3;
    }
    sp10 = (arg1 != 0) ? 0x81010000 : 0x81000000;
    temp_r31 = !EXIImm(arg0, &sp10, 2, 1, 0);
    temp_r31 |= !EXISync(arg0);
    temp_r31 |= !EXIDeselect(arg0);
    if (temp_r31 != 0) {
        return -3;
    }
    return 0;
}

s32 fn_80216DA8(s32 arg0, s32 *arg1) {
    s32 EXISelect(s32, s32, s32);
    s32 EXIImm(s32, s32 *, s32, s32, s32);
    s32 EXISync(s32);
    s32 EXIDeselect(s32);
    s32 sp10;
    u32 acc;

    if (EXISelect(arg0, 0, 4) == 0) {
        return -3;
    }
    sp10 = 0x83000000;
    acc = !EXIImm(arg0, &sp10, 2, 1, 0);
    acc |= !EXISync(arg0);
    acc |= !EXIImm(arg0, arg1, 1, 0, 0);
    acc |= !EXISync(arg0);
    acc |= !EXIDeselect(arg0);
    if (acc != 0) {
        return -3;
    }
    return 0;
}

s32 fn_80216E98(s32 arg0, s32 *arg1) {
    s32 EXIDeselect(s32);
    s32 EXIImm(s32, s32 *, s32, s32, s32);
    s32 EXISelect(s32, s32, s32);
    s32 EXISync(s32);
    s32 command;
    s32 error;
    if (EXISelect(arg0, 0, 4) == 0) return -3;
    command = 0x85000000;
    error = !EXIImm(arg0, &command, 2, 1, 0);
    error |= !EXISync(arg0);
    error |= !EXIImm(arg0, arg1, 2, 0, 0);
    error |= !EXISync(arg0);
    error |= !EXIDeselect(arg0);
    if (error != 0) return -3;
    return 0;
}

s32 fn_80216F88(s32 arg0) {
    s32 EXIDeselect(s32);
    s32 EXIImm(s32, s32 *, s32, s32, s32);
    s32 EXISelect(s32, s32, s32);
    s32 EXISync(s32);
    s32 spC;
    s32 temp_r31;

    if (EXISelect(arg0, 0, 4) == 0) {
        return -3;
    }
    spC = 0x89000000;
    temp_r31 = !EXIImm(arg0, &spC, 1, 1, 0);
    temp_r31 |= !EXISync(arg0);
    temp_r31 |= !EXIDeselect(arg0);
    if (temp_r31 != 0) {
        return -3;
    }
    return 0;
}

void __CARDTimeoutHandler(void *alarm, void *context) {
    extern u16 __CARDBlock[];
    void fn_80239298(s32, void *);

    s32 chan;
    u8 *card;
    u8 *base;
    void (*callback)(s32, s32);

    (void)context;

    base = (u8 *)__CARDBlock;
    chan = 0;
    card = base;
    if (alarm != base + 0xE0) {
        card = (base += 0x110);
        chan = 1;
        if (alarm != (u8 *)__CARDBlock + 0x1F0) {
            chan = 2;
        }
    }

    if (*(s32 *)card != 0) {
        fn_80239298(chan, NULL);
        callback = *(void (**)(s32, s32))(card + 0xCC);
        if (callback) {
            *(void (**)(s32, s32))(card + 0xCC) = 0;
            (*callback)(chan, -5);
        }
    }
}

s32 __CARDRetry(s32 chan) {
    /* Select the card, send the pending cmd (and read addr), then EXIDma or finish. */
    extern u16 __CARDBlock[];
    s32 EXISelect(s32, s32, s32);
    s32 EXIUnlock(s32);
    s32 EXIDeselect(s32);
    s32 EXIDma(s32, s32, s32, s32, void *);
    void OSCancelAlarm(void *);
    void OSSetAlarm(void *, s64, void *);
    s32 EXIImmEx(s32, void *, s32, s32);
    void __CARDTimeoutHandler();
    void __CARDTxHandler();
    u8 *card;
    s32 dmaSize;

    card = (u8 *)__CARDBlock + chan * 0x110;
    if (EXISelect(chan, 0, 4) == 0) {
        EXIUnlock(chan);
        return -3;
    }
    OSCancelAlarm(card + 0xE0);
    switch (card[0x94]) {
    case 0xF2:
        OSSetAlarm(card + 0xE0, (*(u32 *)0x800000F8 / 4) / 1000 * 100, __CARDTimeoutHandler);
        break;
    case 0xF3:
        break;
    case 0xF4:
        if (*(u16 *)(card + 0xA) > 0x80) {
            OSSetAlarm(card + 0xE0, (s64)2 * (*(u32 *)0x800000F8 / 4) * (*(u16 *)(card + 0x10) / 64), __CARDTimeoutHandler);
            break;
        }
    case 0xF1:
        OSSetAlarm(card + 0xE0, (s64)2 * (*(u32 *)0x800000F8 / 4) * (*(s32 *)(card + 0xC) / 0x2000), __CARDTimeoutHandler);
        break;
    }
    if (EXIImmEx(chan, card + 0x94, *(s32 *)(card + 0xA0), 1) == 0) {
        EXIDeselect(chan);
        EXIUnlock(chan);
        return -3;
    }
    if (card[0x94] == 0x52) {
        if (EXIImmEx(chan, *(u8 **)(card + 0x80) + 0x200, *(s32 *)(card + 0x14), 1) == 0) {
            EXIDeselect(chan);
            EXIUnlock(chan);
            return -3;
        }
    }
    if ((*(u32 *)(card + 0xA4) + 0x10000) == 0xFFFF) {
        EXIDeselect(chan);
        EXIUnlock(chan);
        return 0;
    }
    if (card[0x94] == 0x52) {
        dmaSize = 0x200;
    } else {
        dmaSize = *(u16 *)(card + 0xA);
    }
    if (EXIDma(chan, *(s32 *)(card + 0xB4), dmaSize, *(s32 *)(card + 0xA4), __CARDTxHandler) == 0) {
        EXIDeselect(chan);
        EXIUnlock(chan);
        return -3;
    }
    return 0;
}

void __CARDUnlockedHandler(s32 chan, s32 result) {
    /* On EXI unlock: retry the pending CARD cmd, or fire tx/exi callbacks on failure. */
    extern u16 __CARDBlock[];
    s32 EXILock(s32, s32, void *);
    s32 __CARDRetry(s32);
    void __CARDLockCallback();
    u8 *card;
    void (*callback)(s32);

    card = (u8 *)__CARDBlock + chan * 0x110;
    if (result >= 0) {
        *(void **)(card + 0xDC) = __CARDUnlockedHandler;
        if (EXILock(chan, 0, __CARDLockCallback) == 0) {
            result = 0;
        } else {
            *(void **)(card + 0xDC) = NULL;
            result = __CARDRetry(chan);
        }
    }
    if (result < 0) {
        switch ((s32) card[0x94]) {
        case 0x52:
            callback = *(void (**)(s32))(card + 0xC8);
            if (callback != NULL) {
                *(void **)(card + 0xC8) = NULL;
                callback(chan);
            }
            break;
        case 0xF1:
        case 0xF2:
        case 0xF4:
            callback = *(void (**)(s32))(card + 0xCC);
            if (callback != NULL) {
                *(void **)(card + 0xCC) = NULL;
                callback(chan);
            }
            break;
        case 0xF3:
            break;
        }
    }
}

/* Lock/select the memory card EXI channel and arm the command timeout alarm. */
s32 __CARDStart(s32 chan, void *txCallback, void *exiCallback) {
    extern u16 __CARDBlock[];
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s32 EXILock(s32, s32, void *);
    s32 EXISelect(s32, s32, s32);
    s32 EXIUnlock(s32);
    void OSCancelAlarm(void *);
    void OSSetAlarm(void *, s64, void *);
    void __CARDUnlockedHandler();
    void __CARDLockCallback();
    void __CARDTimeoutHandler();
    s32 enabled;
    u8 *card;
    s32 result;

    enabled = OSDisableInterrupts();
    card = (u8 *)__CARDBlock + chan * 0x110;
    if (*(s32 *)card == 0) {
        result = -3;
    } else {
        if (txCallback) {
            *(void **)(card + 0xC8) = txCallback;
        }
        if (exiCallback) {
            *(void **)(card + 0xCC) = exiCallback;
        }
        *(void **)(card + 0xDC) = __CARDUnlockedHandler;
        if (!EXILock(chan, 0, __CARDLockCallback)) {
            result = -1;
        } else {
            *(void **)(card + 0xDC) = 0;
            if (!EXISelect(chan, 0, 4)) {
                EXIUnlock(chan);
                result = -3;
            } else {
                OSCancelAlarm(card + 0xE0);
                switch (card[0x94]) {
                case 0xF2:
                    OSSetAlarm(card + 0xE0, (*(u32 *)0x800000F8 / 4) / 1000 * 100, __CARDTimeoutHandler);
                    break;
                case 0xF3:
                    break;
                case 0xF4:
                    if (*(u16 *)(card + 0xA) > 0x80) {
                        OSSetAlarm(card + 0xE0, (s64)2 * (*(u32 *)0x800000F8 / 4) * (*(u16 *)(card + 0x10) / 64), __CARDTimeoutHandler);
                        break;
                    }
                case 0xF1:
                    OSSetAlarm(card + 0xE0, (s64)2 * (*(u32 *)0x800000F8 / 4) * (*(s32 *)(card + 0xC) / 0x2000), __CARDTimeoutHandler);
                    break;
                }
                result = 0;
            }
        }
    }
    OSRestoreInterrupts(enabled);
    return result;
}

s32 __CARDReadPage(s32 chan, void *callback) {
    /* Issue a memory-card page-read (cmd 0x52) and DMA 0x200 bytes into the card buffer. */
    extern u16 __CARDBlock[];
    extern s32 EXIDma(s32, s32, s32, s32, void *);
    extern void EXIDeselect(s32);
    extern void EXIUnlock(s32);
    s32 EXIImmEx(s32, void *, s32, s32);
    void __CARDTxHandler(s32 arg0);
    u8 *card;
    s32 result;

    card = (u8 *)__CARDBlock + chan * 0x110;
    card[0x94] = 0x52;
    card[0x95] = (u8)((*(u32 *)(card + 0xB0) >> 17) & 0x7F);
    card[0x96] = (u8)(*(u32 *)(card + 0xB0) >> 9);
    card[0x97] = (u8)((*(u32 *)(card + 0xB0) >> 7) & 3);
    card[0x98] = (u8)(*(u32 *)(card + 0xB0) & 0x7F);
    *(s32 *)(card + 0xA0) = 5;
    *(s32 *)(card + 0xA4) = 0;
    *(s32 *)(card + 0xA8) = 0;

    result = __CARDStart(chan, callback, 0);
    if (result == -1) {
        result = 0;
    } else if (result >= 0) {
        if (!EXIImmEx(chan, card + 0x94, *(s32 *)(card + 0xA0), 1) ||
            !EXIImmEx(chan, *(u8 **)(card + 0x80) + 0x200, *(s32 *)(card + 0x14), 1) ||
            !EXIDma(chan, *(s32 *)(card + 0xB4), 0x200, *(s32 *)(card + 0xA4), __CARDTxHandler)) {
            *(void **)(card + 0xC8) = 0;
            EXIDeselect(chan);
            EXIUnlock(chan);
            result = -3;
        } else {
            result = 0;
        }
    }
    return result;
}

s32 fn_802177E0(s32 chan, void *callback) {
    extern u16 __CARDBlock[];
    extern s32 EXIDma(s32, s32, s32, s32, void *);
    extern void EXIDeselect(s32);
    extern void EXIUnlock(s32);
    s32 EXIImmEx(s32, void *, s32, s32);
    void __CARDTxHandler(s32);
    u8 *card;
    s32 result;
    card = (u8 *)__CARDBlock + chan * 0x110;
    card[0x94] = 0xF2;
    if (*(u16 *)(card + 0xA) > 0x80)
        card[0x95] = ((*(u32 *)(card + 0xB0) >> 17) & 0x7F) | 0x80;
    else
        card[0x95] = (*(u32 *)(card + 0xB0) >> 17) & 0x7F;
    result = (*(u32 *)(card + 0xB0) >> 9) & 0xFF;
    card[0x96] = result;
    card[0x97] = (*(u32 *)(card + 0xB0) >> 7) & 3;
    card[0x98] = *(u32 *)(card + 0xB0) & 0x7F;
    *(s32 *)(card + 0xA0) = 5;
    *(s32 *)(card + 0xA4) = 1;
    *(s32 *)(card + 0xA8) = 3;
    result = __CARDStart(chan, 0, callback);
    if (result == -1) result = 0;
    else if (result >= 0) {
        if (!EXIImmEx(chan, card + 0x94, *(s32 *)(card + 0xA0), 1) ||
            !EXIDma(chan, *(s32 *)(card + 0xB4), *(u16 *)(card + 0xA), *(s32 *)(card + 0xA4), __CARDTxHandler)) {
            *(void **)(card + 0xCC) = 0;
            EXIDeselect(chan);
            EXIUnlock(chan);
            result = -3;
        } else result = 0;
    }
    return result;
}

int __CARDEraseSector(s32 chan, u32 addr, void *callback) {
    extern u16 __CARDBlock[];
    s32 EXIImmEx(s32,void*,s32,s32);
    void EXIDeselect(s32);
    void EXIUnlock(s32);
    u8 *card;
    s32 result;
    u32 low;
    card=(u8*)__CARDBlock+chan*0x110;
    if(*(u16*)(card+0xa)>0x80) {
        if(callback) ((void(*)(s32,s32))callback)(chan,0);
        return 0;
    }
    card[0x94]=0xf1;
    low=(addr>>9)&0xff;
    card[0x95]=(addr>>17)&0x7f;
    card[0x96]=low;
    *(s32*)(card+0xa0)=3;
    *(s32*)(card+0xa4)=-1;
    *(s32*)(card+0xa8)=3;
    result=__CARDStart(chan,0,callback);
    if(result==-1) result=0;
    else if(result>=0) {
        if(!EXIImmEx(chan,card+0x94,*(s32*)(card+0xa0),1)) {
            *(void**)(card+0xcc)=0;
            result=-3;
        } else result=0;
        EXIDeselect(chan);
        EXIUnlock(chan);
    }
    return result;
}

#pragma optimization_level 3
void PADInit(void) {
    extern u16 __CARDBlock[];
    extern u16 lbl_80368740;
    extern char *lbl_80366FE0;
    extern u8 lbl_8029D9E8[];

    u16 fn_802072A0(void);
    void OSRegisterVersion(char *);
    void fn_80215F8C(void);
    void OSInitAlarm(void);
    void OSInitThreadQueue(void *);
    void OSCreateAlarm(void *);
    void fn_80217AE0(void *);
    void OSRegisterResetFunction(void *);

    u8 *card;
    s32 i;
    s32 result;

    card = (u8 *)__CARDBlock;

    if (*(u32 *)(card + 0x10C) != 0) {
        if (*(u32 *)(card + 0x21C) != 0) {
            return;
        }
    }

    lbl_80368740 = fn_802072A0();
    OSRegisterVersion(lbl_80366FE0);
    fn_80215F8C();
    OSInitAlarm();

    i = 0;
    result = -3;

    do {
        *(s32 *)(card + 4) = result;
        OSInitThreadQueue(card + 0x8C);
        OSCreateAlarm(card + 0xE0);

        i++;
        card += 0x110;
    } while (i < 2);

    fn_80217AE0((void *)0x80000000);
    OSRegisterResetFunction(lbl_8029D9E8);
}
#pragma optimization_level reset
u16 fn_80217AD8(void) {
    extern u16 lbl_80368740;
    return lbl_80368740;
}

void fn_80217AE0(void *arg0) {
    extern u8 __CARDBlock[];
    u8 *base = __CARDBlock;
    void *r0;

    if (arg0 != (void *)0) {
        r0 = arg0;
    } else {
        r0 = (void *)(base + 0x220);
    }
    *(void **)(base + 0x10C) = r0;
    arg0 = (arg0 != (void *)0) ? arg0 : (void *)(base + 0x220);
    *(void **)(base + 0x21C) = arg0;
}

s32 fn_80217B18(s32 arg0, s32 *arg1) {
    void OSDisableInterrupts(void);
    void OSRestoreInterrupts(void);
    extern u8 __CARDBlock[];
    s32 result;
    u8 *ptr;

    ptr = __CARDBlock + arg0 * 0x110;
    if (arg0 < 0 || arg0 >= 2 || *(u32 *)(ptr + 0x10C) == 0) {
        return -0x80;
    }
    OSDisableInterrupts();
    if (*(s32 *)ptr == 0) {
        result = -3;
    } else if (*(s32 *)(ptr + 4) == -1) {
        result = -1;
    } else {
        *(s32 *)(ptr + 4) = -1;
        result = 0;
        *(s32 *)(ptr + 0xD0) = 0;
        *arg1 = (s32)ptr;
    }
    OSRestoreInterrupts();
    return result;
}

s32 __CARDPutControlBlock(void *arg0, s32 arg1) {
    M2C_UNK OSRestoreInterrupts();
    M2C_UNK OSDisableInterrupts();
    OSDisableInterrupts();
    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        M2C_FIELD(arg0, s32 *, 4) = arg1;
    } else if (M2C_FIELD(arg0, s32 *, 4) == -1) {
        M2C_FIELD((u32)arg0, s32 *, 4) = arg1;
    }
    OSRestoreInterrupts();
    return arg1;
}

extern u16 __CARDBlock[];
s32 CARDGetResultCode(s32 arg0) {
    extern u16 __CARDBlock[];
    if (arg0 < 0 || arg0 >= 2) {
        return -0x80;
    }
    return *(s32 *)((u8 *)__CARDBlock + arg0 * 0x110 + 4);
}

#pragma global_optimizer off
s32 fn_80217C64(s32 chan) {
    u32 OSDisableInterrupts(void);
    void OSSleepThread(void *);
    void OSRestoreInterrupts(u32);
    u8 *card;
    s32 result;
    s32 status;
    unsigned enabled;

    card = (u8 *)__CARDBlock + chan * 0x110;
    enabled = OSDisableInterrupts();
    goto check;
sleep:
    OSSleepThread(card + 0x8C);
check:
    if ((int)chan < 0 || chan >= 2) {
        status = -0x80;
    } else {
        status = *(s32 *)(card + 4);
    }
    result = status;
    if (result == -1) {
        goto sleep;
    }
    OSRestoreInterrupts(enabled);
    return result;
}
#pragma global_optimizer reset
s32 fn_80217CFC(s32 arg0) {
    s32 fn_8021B20C(M2C_UNK);
    if ((arg0 == 0) && ((fn_8021B20C(0) == -1) || (fn_8021B20C(1) == -1))) {
        return 0;
    }
    return 1;
}

s32 fn_80217D4C(void) {
    extern u16 lbl_80368742;
    if (lbl_80368742 != 0) {
        return 1;
    }
    return 0;
}

s32 fn_80217D68(u32 arg0) {
u32 sign=arg0>>31;
u32 result, i, left, right;
left=0; right=1; result=0;
for(i=0;i<32;i++){
if(i>15){if(i==31) result|=sign; else {result|=(arg0&(1U<<i))>>right;right+=2;}}
else {result|=(arg0&(1U<<i))<<((31-i)-left);left++;}
}
return result;
}

s32 fn_80217ED4(s32 chan, u32 addr, void *buffer, s32 length, s32 mode) {
extern u16 __CARDBlock[];
s32 EXISelect(s32,s32,s32);
s32 EXIImmEx(s32,void*,s32,s32);
s32 EXIDeselect(s32);
u8 command[5];
u8 *card;
s32 error;
card=(u8*)__CARDBlock+chan*0x110;
if (!EXISelect(chan,0,4)) return -3;
addr &= ~0xFFF;
memset(command,0,5);
command[0]=0x52;
if(mode==0) {
command[1]=(addr>>29)&3;
command[2]=addr>>21;
command[3]=(addr>>19)&3;
command[4]=(addr>>12)&0x7F;
} else {
command[1]=addr>>24;
command[2]=addr>>16;
}
error=!EXIImmEx(chan,command,5,1);
error|=!EXIImmEx(chan,*(u8**)(card+0x80)+0x200,*(s32*)(card+0x14),1);
error|=!EXIImmEx(chan,buffer,length,0);
error|=!EXIDeselect(chan);
if(error) return -3;
return 0;
}

s32 fn_80218018(void) {
    extern volatile u32 lbl_80366FE8;
    u32 temp_r0;
    u32 var_r30;
    u32 var_r29;
    s32 var_r3;
    u32 stack_pad0;
    u32 stack_pad1;
    u32 stack_pad2;
    u32 stack_pad3;

    var_r30 = 1;
    var_r29 = 0;
    lbl_80366FE8 = OSGetTick();
    lbl_80366FE8 = (lbl_80366FE8 * 0x41C64E6D) + 0x3039;
    var_r3 = (((u32) lbl_80366FE8 >> 0x10U) & 0x1F) + 1;
    while ((var_r3 < 4) && (var_r29 < 0xAU)) {
        temp_r0 = OSGetTick() << var_r30;
        var_r30 += 1;
        if (var_r30 > 0x10U) {
            var_r30 = 1;
        }
        lbl_80366FE8 = temp_r0;
        var_r29 += 1;
        lbl_80366FE8 = (lbl_80366FE8 * 0x41C64E6D) + 0x3039;
        var_r3 = (((u32) lbl_80366FE8 >> 0x10U) & 0x1F) + 1;
    }
    if (var_r3 < 4) {
        var_r3 = 4;
    }
    return var_r3;
}

#pragma push
#pragma optimization_level 4
#pragma opt_loop_invariants off
s32 fn_802180DC(s32 chan, void *out) {
    u32 OSGetTick(void);
    void DCFlushRange(void *, u32);
    void DCInvalidateRange(void *, u32);
    s32 fn_80217D68(u32);
    s32 fn_80217ED4(s32, u32, void *, s32, s32);
    s32 fn_80218018(void);
    void fn_80216050(void *, void *, s32);
    extern void fn_80218C34;
    extern void fn_80218CA4;
    extern u16 lbl_8033A200[];
    extern u8 lbl_8029DA00[];
    extern u32 lbl_80366FE8;

    u8 *card;
    u8 *work;
    void *buf;
    u32 aligned;
    void *aligned2;
    u32 seed;
    u32 scramble;
    s32 tick;
    s32 n;
    u32 i;
    u32 rem;
    u32 ctr;
    u32 t;
    s32 left;
    u32 spA4[5];
    u32 w0, w1, w2, w3, w4;

    card = (u8 *)lbl_8033A200 + chan * 0x110;
    work = card + 0x30;
    buf = *(void **)(card + 0x80);
    aligned = ((u32)buf + 0x2F) & ~0x1Fu;
    aligned2 = (void *)(aligned + 0x20);

    lbl_80366FE8 = OSGetTick();
    lbl_80366FE8 = lbl_80366FE8 * 0x41C64E6D + 0x3039;
    seed = 0x7FEC8000u;
    seed |= (lbl_80366FE8 >> 16) & 0x7FFF;
    seed &= 0xFFFFF000u;

    tick = fn_80218018();
    if (fn_80217ED4(chan, seed, spA4, tick, 0) < 0) {
        return -3;
    }

    scramble = seed;
    for (i = 0; i < (u32)((tick << 3) + 1); ++i) {
        t = ~((scramble >> 23) ^ ((scramble >> 15) ^ (scramble ^ (scramble >> 7))));
        scramble = (scramble >> 1) | ((t << 30) & 0x40000000);
    }

    t = ~((scramble >> 23) ^ ((scramble >> 15) ^ (scramble ^ (scramble >> 7))));
    scramble |= t << 31;
    *(u32 *)(card + 0x2C) = scramble;
    *(u32 *)(card + 0x2C) = fn_80217D68(*(u32 *)(card + 0x2C));

    tick = fn_80218018();
    if (fn_80217ED4(chan, 0, spA4, tick + 0x14, 1) < 0) {
        return -3;
    }

    scramble = *(u32 *)(card + 0x2C);
    w0 = spA4[0] ^ scramble;
    scramble = Card_AdvanceScramble(32, scramble);
    *(u32 *)(card + 0x2C) = scramble;

    scramble = *(u32 *)(card + 0x2C);
    w1 = spA4[1] ^ scramble;
    scramble = Card_AdvanceScramble(32, scramble);
    *(u32 *)(card + 0x2C) = scramble;

    scramble = *(u32 *)(card + 0x2C);
    w2 = spA4[2] ^ scramble;
    scramble = Card_AdvanceScramble(32, scramble);
    *(u32 *)(card + 0x2C) = scramble;

    scramble = *(u32 *)(card + 0x2C);
    w3 = spA4[3] ^ scramble;
    scramble = Card_AdvanceScramble(32, scramble);
    *(u32 *)(card + 0x2C) = scramble;

    scramble = *(u32 *)(card + 0x2C);
    w4 = spA4[4] ^ scramble;
    scramble = Card_AdvanceScramble(tick << 3, scramble);
    *(u32 *)(card + 0x2C) = scramble;

    /* final 0x21-step and DMA setup */
    scramble = *(u32 *)(card + 0x2C);
    scramble = Card_AdvanceScramble(33, scramble);
    *(u32 *)(card + 0x2C) = scramble;

    *(u32 *)aligned = w3;
    *(u32 *)(aligned + 4) = w4;
    *(u32 *)buf = aligned;
    *(u32 *)((u8 *)buf + 4) = 8;
    *(u32 *)((u8 *)buf + 0xC) = (u32)aligned2;
    *(u32 *)((u8 *)buf + 8) = 0;
    DCFlushRange((void *)aligned, 8);
    DCInvalidateRange((void *)aligned2, 4);
    DCFlushRange(buf, 0x10);

    *(u32 *)(work + 4) = 0xFF;
    *(void **)(work + 0xC) = (void *)((u32)lbl_8029DA00 + 0x80000000);
    *(u32 *)(work + 0x10) = 0x160;
    *(u32 *)(work + 0x14) = 0;
    *(u16 *)(work + 0x24) = 0x10;
    *(void **)(work + 0x28) = &fn_80218C34;
    *(u32 *)(work + 0x2C) = 0;
    *(void **)(work + 0x30) = &fn_80218CA4;
    *(u32 *)(work + 0x34) = 0;
    fn_80216050(work, &fn_80218C34, 0x10);

    *(u32 *)out = w0;
    *((u32 *)out + 1) = w1;
    *((u32 *)out + 2) = w2;
    return 0;
}
#pragma pop
void fn_80218C34(void *arg0)
{
    extern void fn_80215F78(u32);
    extern u32 fn_80215F40(void);

    u8 *card;
    u32 previous;
    s32 chan;

    chan = 0;
    card = (u8 *)__CARDBlock;
    if (card + 0x30 != (u8 *)arg0) {
        card += 0x110;
        chan = 1;
        if ((u8 *)__CARDBlock + 0x140 != (u8 *)arg0) {
            chan = 2;
        }
    }

    previous = *(u32 *)(card + 0x80);

    fn_80215F78(0xFF000000);
    while (fn_80215F40() != 0) {
    }
    fn_80215F78(previous);
    while (fn_80215F40() != 0) {
    }

    (void)chan;
}

#pragma push
#pragma optimization_level 3
void fn_80218CA4(void *arg0)
{
  s32 EXIUnlock(s32);
  s32 fn_80216DA8(s32, u8 *);
  s32 fn_80217ED4(s32, u32, void *, s32, s32);
  s32 fn_80218018(void);
  void fn_8021AE98(s32, s32);
  s32 fn_80239488(s32);
  extern u16 __CARDBlock[];
  u8 cmd[0x40];
  u8 status;
  u32 address;
  u32 scramble;
  u32 i;
  u32 n;
  u32 rem;
  u32 ctr;
  u32 t;
  s32 left;
  u8 *work;
  s32 new_var;
  s32 tick;
  s32 chan;
  u32 cid;
  u8 *card;
  s32 result;
  chan = 0;
  card = (u8 *) __CARDBlock;
  if ((((u8 *) __CARDBlock) + 0x30) != ((u8 *) arg0))
  {
    card = ((u8 *) __CARDBlock) + 0x110;
    chan = 1;
    if ((((u8 *) __CARDBlock) + 0x140) != ((u8 *) arg0))
    {
      chan = 2;
    }
  }
  work = (u8 *) (((*((u32 *) (card + 0x80))) + 0x2F) & (~0x1Fu));
  cid = *((u32 *) (work + 0x20));
  tick = (0, fn_80218018());
  address = (cid ^ (*((u32 *) (card + 0x2C)))) & 0xFFFF0000u;
  new_var = tick;
  if (fn_80217ED4(chan, address, cmd, new_var, 1) < 0)
  {
    EXIUnlock(chan);
    fn_8021AE98(chan, -3);
    return;
  }
  tick += *((s32 *) (card + 0x14));
  n = ((tick + 4) * 8) + 1;
  scramble = Card_AdvanceScramble(n, *((u32 *) (card + 0x2C)));
  *((u32 *) (card + 0x2C)) = scramble;
  tick = fn_80218018();
  address = ((cid << 16) ^ (*((u32 *) (card + 0x2C)))) & 0xFFFF0000u;
  if (fn_80217ED4(chan, address, cmd, tick, 1) < 0)
  {
    EXIUnlock(chan);
    fn_8021AE98(chan, -3);
    return;
  }
  result = fn_80216DA8(chan, &status);
  if (fn_80239488(chan) == 0)
  {
    EXIUnlock(chan);
    fn_8021AE98(chan, -3);
    return;
  }
  if ((result == 0) && (!(status & 0x40)))
  {
    EXIUnlock(chan);
    result = -5;
  }
  fn_8021AE98(chan, result);
}
#pragma pop
void fn_80218FC8(s32 chan, s32 result) {
    extern u16 __CARDBlock[];
    s32 __CARDPutControlBlock(void *,s32);
    u8 *card;
    void (*callback)(s32,s32);
    card = (u8 *)__CARDBlock + chan * 0x110;
    if (result >= 0) {
        *(u32 *)(card+0xB8) += 0x200;
        *(u32 *)(card+0xB0) += 0x200;
        *(u32 *)(card+0xB4) += 0x200;
        if (--*(s32 *)(card+0xAC) > 0) {
            result = __CARDReadPage(chan, fn_80218FC8);
            if (result >= 0) return;
        }
    }
    if (*(u32 *)(card+0xD0) == 0) __CARDPutControlBlock(card,result);
    callback = *(void (**)(s32,s32))(card+0xD4);
    if (callback) {
        *(void **)(card+0xD4) = 0;
        callback(chan,result);
    }
}

s32 fn_802190A4(s32 chan, u32 addr, u32 length, void *dst, void *callback) {
    extern u16 __CARDBlock[];
    void fn_80218FC8();
    u8 *card;

    card = (u8 *)__CARDBlock + chan * 0x110;
    if (*(s32 *)card == 0) {
        return -3;
    }
    *(void **)(card + 0xD4) = callback;
    *(u32 *)(card + 0xAC) = length / 0x200;
    *(u32 *)(card + 0xB0) = addr;
    *(void **)(card + 0xB4) = dst;
    return __CARDReadPage(chan, fn_80218FC8);
}

void fn_80219108(s32 chan, s32 result) {
    extern u16 __CARDBlock[];
    s32 __CARDPutControlBlock(void *,s32);
    s32 fn_802177E0(s32, void (*)(s32, s32));
    u8 *card;
    void (*callback)(s32,s32);
    card = (u8 *)__CARDBlock + chan * 0x110;
    if (result >= 0) {
        *(u32 *)(card+0xB8) += *(u16 *)(card + 0xA);
        *(u32 *)(card+0xB0) += *(u16 *)(card + 0xA);
        *(u32 *)(card+0xB4) += *(u16 *)(card + 0xA);
        if (--*(s32 *)(card+0xAC) > 0) {
            result = fn_802177E0(chan, fn_80219108);
            if (result >= 0) return;
        }
    }
    if (*(u32 *)(card+0xD0) == 0) __CARDPutControlBlock(card,result);
    callback = *(void (**)(s32,s32))(card+0xD4);
    if (callback) {
        *(void **)(card+0xD4) = 0;
        callback(chan,result);
    }
}

s32 fn_802191F0(s32 chan, u32 addr, s32 length, void *dst, void *callback) {
    extern u16 __CARDBlock[];
    void fn_80219108();
    s32 fn_802177E0(s32, void *);
    u8 *card;
    s32 sector;

    card = (u8 *)__CARDBlock + chan * 0x110;
    if (*(s32 *)card == 0) {
        return -3;
    }
    *(void **)(card + 0xD4) = callback;
    sector = *(u16 *)(card + 0xA);
    *(u32 *)(card + 0xAC) = length / sector;
    *(u32 *)(card + 0xB0) = addr;
    *(void **)(card + 0xB4) = dst;
    return fn_802177E0(chan, fn_80219108);
}

s32 __CARDGetFatBlock(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x88);
}

void __CARDUpdateFatCallback(s32 chan, s32 result) {
    /* On successful FAT write, flip currentFat between workArea+0x6000/0x8000 and run the async callback. */
    extern u16 __CARDBlock[];
    void *memcpy(void *, const void *, u32);
    s32 __CARDPutControlBlock(void *, s32);
    u8 *card;
    u8 *workArea;
    u8 *fat0;
    u8 *fat1;
    void (*callback)(s32, s32);

    card = (u8 *)__CARDBlock + chan * 0x110;
    if (result >= 0) {
        workArea = *(u8 **)(card + 0x80);
        fat0 = workArea + 0x6000;
        fat1 = workArea + 0x8000;
        if (*(u8 **)(card + 0x88) == fat0) {
            *(u8 **)(card + 0x88) = fat1;
            memcpy(fat1, fat0, 0x2000);
        } else {
            *(u8 **)(card + 0x88) = fat0;
            memcpy(fat0, fat1, 0x2000);
        }
    }
    if (*(u32 *)(card + 0xD0) == 0) {
        __CARDPutControlBlock(card, result);
    }
    callback = *(void (**)(s32, s32))(card + 0xD8);
    if (callback != NULL) {
        *(void **)(card + 0xD8) = NULL;
        callback(chan, result);
    }
}

#pragma optimization_level 3
void fn_80219334(s32 chan, s32 result) {
    extern u16 __CARDBlock[];
    s32 fn_802191F0(s32, u32, s32, void *, void (*)(s32, s32));
    s32 __CARDPutControlBlock(void *, s32);
    void __CARDUpdateFatCallback(s32, s32);
    u8 pad[8];
    void (*callback)(s32, s32);
    u8 *fat;
    u8 *dst;
    u8 *card;

    (void)pad;
    card = (u8 *)__CARDBlock + chan * 0x110;
    if (result < 0) {
        goto fail;
    }
    fat = *(u8 **)(card + 0x88);
    dst = fat;
    result = fn_802191F0(chan, *(u32 *)(card + 0xC) * ((u32)(fat - *(u8 **)(card + 0x80)) >> 13), 0x2000, dst, __CARDUpdateFatCallback);
    if (result >= 0) {
        return;
    }
fail:
    if (*(u32 *)(card + 0xD0) == 0) {
        __CARDPutControlBlock(card, result);
    }
    callback = *(void (**)(s32, s32))(card + 0xD8);
    if (callback != NULL) {
        *(void **)(card + 0xD8) = NULL;
        callback(chan, result);
    }
}
#pragma push
#pragma optimization_level 3
s32 fn_802193FC(s32 arg0, u32 arg1, void *arg2) {
    s32 fn_802195B0(s32, void *, void *);
    u8 *entry;
    u16 *data;
    u16 current, first, previous, attempts;
    if (*(s32 *)(entry = (u8 *)__CARDBlock + arg0 * 0x110) == 0)
        return -3;
    if ((data = *(u16 **)(entry + 0x88))[3] < arg1)
        return -9;
    data[3] -= arg1;
    current = data[4];
    first = 0xFFFF;
    attempts = 0;
    while (arg1 != 0) {
        u16 limit = *(u16 *)(entry + 0x10);
        if (limit - 5 < ++attempts)
            return -6;
        current++;
        if (current < 5 || current >= limit)
            current = 5;
        if (data[current] == 0) {
            if (first == 0xFFFF)
                first = current;
            else
                data[previous] = current;
            data[current] = 0xFFFF;
            previous = current;
            arg1--;
        }
    }
    data[4] = current;
    *(u16 *)(entry + 0xBE) = first;
    return fn_802195B0(arg0, data, arg2);
}
#pragma push
#pragma optimization_level 2
s32 fn_80219514(s32 chan, u16 block, void *callback) {
    s32 fn_802195B0(s32, void *, void *);
    u8 *card;
    u16 *fat;
    card = (u8 *)__CARDBlock + chan * 0x110;
    if (*(s32 *)card == 0) return -3;
    fat = *(u16 **)(card + 0x88);
    while (block != 0xFFFF) {
        u16 next;
        if (block < 5 || block >= *(u16 *)(card+0x10)) return -6;
        next = fat[block];
        fat[block] = 0;
        block = next;
        fat[3]++;
    }
    return fn_802195B0(chan,fat,callback);
}
#pragma pop
s32 fn_802195B0(s32 arg0, u16 *fat, void *arg2) {
    void fn_802198C0(void *, u32, void *, void *);
    void fn_80205110(void *, u32);
    s32 __CARDEraseSector(s32, u32, void *);
    void fn_80219334(void);
    extern u16 __CARDBlock[];
    u8 *card;

    card = (u8 *)__CARDBlock + arg0 * 0x110;
    ++fat[2];
    fn_802198C0(fat + 2, 0x1FFC, fat, fat + 1);
    fn_80205110(fat, 0x2000);
    *(void **)(card + 0xD8) = arg2;
    return __CARDEraseSector(arg0, (((u32)fat - *(u32 *)(card + 0x80)) / 0x2000) * *(u32 *)(card + 0xC), fn_80219334);
}

s32 __CARDGetDirBlock(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x84);
}

void fn_80219664(s32 chan, s32 result) {
    extern u16 __CARDBlock[];
    void *memcpy(void *, const void *, u32);
    s32 __CARDPutControlBlock(void *, s32);
    u8 *card;
    u8 *workArea;
    u8 *dir0;
    u8 *dir1;
    void (*callback)(s32, s32);
    card = (u8 *)__CARDBlock + chan * 0x110;
    if (result >= 0) {
        workArea = *(u8 **)(card + 0x80);
        dir0 = workArea + 0x2000;
        dir1 = workArea + 0x4000;
        if (*(u8 **)(card + 0x84) == dir0) {
            *(u8 **)(card + 0x84) = dir1;
            memcpy(dir1, dir0, 0x2000);
        } else {
            *(u8 **)(card + 0x84) = dir0;
            memcpy(dir0, dir1, 0x2000);
        }
    }
    if (*(u32 *)(card + 0xD0) == 0) __CARDPutControlBlock(card, result);
    callback = *(void (**)(s32, s32))(card + 0xD8);
    if (callback != NULL) {
        *(void **)(card + 0xD8) = NULL;
        callback(chan, result);
    }
}

void fn_80219734(s32 chan, s32 result) {
    extern u16 __CARDBlock[];
    s32 fn_802191F0(s32, u32, s32, void *, void (*)(s32, s32));
    s32 __CARDPutControlBlock(void *, s32);
    void fn_80219664(s32, s32);
    u8 pad[8];
    void (*callback)(s32, s32);
    u8 *dir;
    u8 *dst;
    u8 *card;

    (void)pad;
    card = (u8 *)__CARDBlock + chan * 0x110;
    if (result < 0) {
        goto fail;
    }
    dir = *(u8 **)(card + 0x84);
    dst = dir;
    result = fn_802191F0(chan, *(u32 *)(card + 0xC) * ((u32)(dir - *(u8 **)(card + 0x80)) >> 13), 0x2000, dst, fn_80219664);
    if (result >= 0) {
        return;
    }
fail:
    if (*(u32 *)(card + 0xD0) == 0) {
        __CARDPutControlBlock(card, result);
    }
    callback = *(void (**)(s32, s32))(card + 0xD8);
    if (callback != NULL) {
        *(void **)(card + 0xD8) = NULL;
        callback(chan, result);
    }
}

s32 fn_802198C0(u16 *arg0, s32 arg1, u16 *arg2, u16 *arg3);
s32 fn_80205110(void *, s32);
void fn_80219734(s32, s32);
#pragma optimization_level 3
s32 __CARDUpdateDir(s32 arg0, s32 arg1) {
    u8 *card;
    u8 *dir;
    void *temp_r6;
    u32 pad[2];

    card = (u8 *)__CARDBlock + arg0 * 0x110;
    if (*(s32 *)card == 0) {
        return -3;
    }
    dir = *(u8 **)(card + 0x84);
    temp_r6 = dir + 0x1FC0;
    *(u16 *)(dir + 0x1FFA) = (u16)(*(s16 *)(dir + 0x1FFA) + 1);
    fn_802198C0((u16 *)dir, 0x1FFC, (u16 *)((u8 *)temp_r6 + 0x3C), (u16 *)((u8 *)temp_r6 + 0x3E));
    fn_80205110(dir, 0x2000);
    *(s32 *)(card + 0xD8) = arg1;
    return __CARDEraseSector(arg0, *(s32 *)(card + 0x0C) * ((u32)(dir - *(u8 **)(card + 0x80)) >> 13), (void *)fn_80219734);
}
s32 fn_802198C0(u16 *arg0, s32 arg1, u16 *arg2, u16 *arg3) {
    s32 n;

    *arg3 = 0;
    n = arg1 / 2;
    *arg2 = 0;
    for (; n > 0; n--) {
        *arg2 += *arg0;
        *arg3 += ~*arg0;
        arg0++;
    }
    if (*arg2 == 0xFFFF) {
        *arg2 = 0;
    }
    if (*arg3 == 0xFFFF) {
        *arg3 = 0;
    }
    return (s32)arg0;
}

#pragma use_lmw_stmw on
s32 fn_80219A70(void *arg0)
{
    extern u16 __CARDBlock[];
    u8 *__OSLockSramEx(void);
    void __OSUnlockSramEx(s32);
    u16 fn_80217AD8(void);
    s32 length, n;
    u16 *p;
    u16 v;
    u32 sum, inv;
    u8 *sram;
    s64 random;
    u8 *header;
    s32 i;
    u8 *serial;

    header = *(u8 **)((u8 *)arg0 + 0x80);
    if (*(u16 *)(header + 0x20) != 0 || *(u16 *)(header + 0x22) != *(u16 *)((u8 *)arg0 + 8)) {
        return -6;
    }
    length = 0x1fc;
    length /= 2;
    p = (u16 *)header;
    sum = inv = 0;
    for (n = length; n > 0; n--) {
        v = *p++;
        sum += v;
        inv += ~v;
    }
    if ((u16)sum == 0xffff) {
        sum = 0;
    }
    if ((u16)inv == 0xffff) {
        inv = 0;
    }
    if (*(u16 *)(header + 0x1fc) != (u16)sum || *(u16 *)(header + 0x1fe) != (u16)inv) {
        return -6;
    }
    random = *(s64 *)(header + 12);
    sram = __OSLockSramEx();
    for (i = 0; i < 12; i++) {
        random = (random * 1103515245 + 12345) >> 16;
        if (header[i] != (u8)(sram[(((u8 *)arg0 - (u8 *)__CARDBlock) / 0x110) * 12 + i] + random)) {
            __OSUnlockSramEx(0);
            return -6;
        }
        random = ((random * 1103515245 + 12345) >> 16) & 0x7fff;
    }
    __OSUnlockSramEx(0);
    if (*(u16 *)(header + 0x24) != fn_80217AD8()) {
        return -13;
    }
    return 0;
}
#pragma use_lmw_stmw reset
static inline void CARD_CheckSumInline(void *ptr, s32 length, u16 *checksum, u16 *checksumInv) {
    u16 *p;
    length /= 2;
    *checksum = *checksumInv = 0;
    for (p = (u16 *)ptr; length > 0; length--, p++) {
        *checksum += *p;
        *checksumInv += ~*p;
    }
    if (*checksum == 0xFFFF) {
        *checksum = 0;
    }
    if (*checksumInv == 0xFFFF) {
        *checksumInv = 0;
    }
}
#pragma push
#pragma opt_lifetimes off
s32 fn_80219CF4(s32 card, s32 *alternative)
{
  void *memcpy(void *, const void *, u32);
  u8 *block[2];
  u8 *check[2];
  s32 cBlock;
  s32 cCheck;
  s32 i;
  u16 sum;
  u8 *new_var2;
  u8 **new_var;
  u16 inv;
  cBlock = 0;
  cCheck = 0;
  for (i = 0; i < 2; i++)
  {
    new_var2 = (u8 *) card;
    if (((!card) && (!card)) && (!card))
    {
    }
    block[i] = (*((u8 **) (new_var2 + 0x80))) + ((i + 1) << 13);
    check[i] = block[i] + 0x1FC0;
    CARD_CheckSumInline(block[i], 0x1FFC, &sum, &inv);
    if ((sum != (*((u16 *) (check[i] + 0x3C)))) || (inv != (*((u16 *) (check[i] + 0x3E)))))
    {
      *((u8 **) (new_var2 + 0x84)) = 0;
      cCheck = i;
      cBlock++;
    }
  }

  if (cBlock == 0)
  {
    if ((*((u8 **) (((u8 *) card) + 0x84))) == 0)
    {
      if (((*((s16 *) (check[0] + 0x3A))) - (*((s16 *) (check[1] + 0x3A)))) < 0)
      {
        cCheck = 0;
      }
      else
      {
        cCheck = 1;
      }
      *((u8 **) (new_var2 + 0x84)) = block[cCheck];
      memcpy(block[cCheck], block[cCheck ^ 1], 0x2000);
    }
    else
    {
      cCheck = ((*((u8 **) (((u8 *) card) + 0x84))) == (new_var = block)[0]) ? (0) : (1);
    }
  }
  if (alternative != 0)
  {
    *alternative = cCheck;
  }
  return cBlock;
}
#pragma optimization_level 4
#pragma global_optimizer off
s32 fn_80219F34(s32 card,s32 *alternative) {
void *memcpy(void*,const void*,u32);
u8 *block[2];
s32 i;
u8 **bp;
s32 *alt;
s32 cBlock,cCheck;
u8 *b;

i=0;cBlock=0;cCheck=0;alt=alternative;bp=block;
do{
s32 n;
u16 *p;
u16 temp;
u32 sum,inv;
b=*(u8**)((u8*)card+0x80)+((i+3)<<13);
*bp=b;
n=0x1ffc;n/=2;
p=(u16*)(b+4);sum=inv=0;
for(;n>0;n--){temp=*p++;sum+=temp;inv+=~temp;}
if((u16)sum==0xffff)sum=0;
if((u16)inv==0xffff)inv=0;
if(*(u16*)b!=(u16)sum || *(u16*)(b+2)!=(u16)inv){
*(u8**)((u8*)card+0x88)=0;cCheck=i;cBlock++;
}else{
u16 free,j;
u32 total=*(u16*)((u8*)card+0x10);
p=(u16*)(b+10);free=0;j=5;
while(j<total){if(*p==0)free++;p++;j++;}
if(free!=*(u16*)(b+6)){*(u8**)((u8*)card+0x88)=0;cCheck=i;cBlock++;}
}
i++;bp++;
}while(i<2);
if(cBlock==0){
if(*(u8**)((u8*)card+0x88)==0){
if(*(s16*)(block[0]+4)-*(s16*)(block[1]+4)<0)cCheck=0;else cCheck=1;
{u8 **chosen=&block[cCheck];
*(u8**)((u8*)card+0x88)=*chosen;
memcpy(*chosen,block[cCheck^1],0x2000);}
}else {s32 chosen;if(*(u8**)((u8*)card+0x88)==block[0])chosen=0;else chosen=1;cCheck=chosen;}
}
if(alt)*alt=cCheck;
return cBlock;
}
#pragma global_optimizer on
s32 fn_8021A1B8(s32 arg0) {
    s32 temp_r31;
    s32 temp_r0;
    s32 temp_r3;

    temp_r3 = fn_80219A70((void *)arg0);
    if (temp_r3 < 0) {
        return temp_r3;
    }
    temp_r31 = fn_80219CF4(arg0, 0);
    temp_r0 = temp_r31 + fn_80219F34(arg0, 0);
    switch (temp_r0) {
    case 0:
        return 0;
    case 1:
        return -6;
    default:
        return -6;
    }
}

#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
s32 fn_8021A244(s32 chan, s32 *outSize, void (*callback)(s32, s32))
{
    void *memcpy(void *, const void *, u32);
    void *memset(void *, s32, u32);
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s32 fn_80217B18(s32, void **);
    s32 __CARDPutControlBlock(void *, s32);
    s32 fn_80219A70(void *);
    s32 fn_80219CF4(void *, s32 *);
    s32 fn_80219F34(void *, s32 *);
    s32 __CARDUpdateDir(s32, s32);
    s32 fn_802195B0(s32, void *, void *);

    void *card;
    u8 *blockDir[2];
    u8 *blockFat[2];
    s32 altFat;
    s32 altDir;
    s32 cBlock;
    s32 flagFat = 0;
    s32 flagDir = 0;
    s32 flagDirty = 0;
    s32 ret;
    u8 *base;
    u16 *scratch;
    u8 *dir;
    s32 i;
    u16 block;
    u16 len;
    u16 next;
    u16 *fat;
    u16 *sp;
    u16 freeCount;
    u16 idx;
    u16 limit;
    u16 cnt;
    s32 irq;
    u16 temp;
    u16 *src;
    u16 *p1;

    if (outSize != 0) {
        *outSize = 0;
    }
    ret = fn_80217B18(chan, &card);
    if (ret < 0) {
        return ret;
    }
    ret = fn_80219A70(card);
    if (ret < 0) {
        return __CARDPutControlBlock(card, ret);
    }
    cBlock = fn_80219CF4(card, &altDir);
    cBlock += fn_80219F34(card, &altFat);
    if (cBlock > 1) {
        return __CARDPutControlBlock(card, -6);
    }
    base = *(u8 **)((u8 *)card + 0x80);
    blockDir[0] = base + 0x2000;
    blockFat[0] = base + 0x6000;
    blockDir[1] = base + 0x4000;
    blockFat[1] = base + 0x8000;
    switch (cBlock) {
      case 1:
        if (*(void **)((u8 *)card + 0x84) == 0) {
            *(u8 **)((u8 *)card + 0x84) = blockDir[altDir];
            memcpy(blockDir[altDir], blockDir[altDir ^ 1], 0x2000);
            flagDir = 1;
        } else {
            *(u8 **)((u8 *)card + 0x88) = blockFat[altFat];
            memcpy(blockFat[altFat], blockFat[altFat ^ 1], 0x2000);
            flagFat = 1;
        }
    }
    scratch = (u16 *)blockFat[altFat ^ 1];
    memset(scratch, 0, 0x2000);
    for (i = 0; i < 0x7F; i++) {
        dir = *(u8 **)((u8 *)card + 0x84) + (i * 0x40);
        if (*dir != 0xFF) {
            block = *(u16 *)(dir + 0x36);
            len = 0;
            while ((u32)block != 0xFFFF && (u32)len < *(u16 *)(dir + 0x38)) {
                if ((u32)block < 5 || (u32)block >= *(u16 *)((u8 *)card + 0x10)) {
                    return __CARDPutControlBlock(card, -6);
                }
                cnt = scratch[block] + 1;
                scratch[block] = cnt;
                if ((u32)cnt > 1) {
                    return __CARDPutControlBlock(card, -6);
                }
                block = (*(u16 **)((u8 *)card + 0x88))[block];
                len++;
            }
            if ((u32)len != *(u16 *)(dir + 0x38) || (u32)block != 0xFFFF) {
                return __CARDPutControlBlock(card, -6);
            }
        }
    }
    sp = scratch + 5;
    freeCount = 0;
    for (idx = 5, i = 0xA; (u32)idx < *(u16 *)((u8 *)card + 0x10); idx++, i += 2, sp++) {
        next = *(u16 *)(*(u8 **)((u8 *)card + 0x88) + i);
        if (*sp == 0) {
            if (next != 0) {
                *(u16 *)(*(u8 **)((u8 *)card + 0x88) + i) = 0;
                flagDirty = 1;
            }
            freeCount++;
        } else if (((u32)next < 5 || (u32)next >= *(u16 *)((u8 *)card + 0x10)) && (u32)next != 0xFFFF) {
            return __CARDPutControlBlock(card, -6);
        }
    }
    fat = *(u16 **)((u8 *)card + 0x88);
    if (freeCount != fat[3]) {
        fat[3] = freeCount;
        flagDirty = 1;
    }
    if (flagDirty != 0) {
        fat = *(u16 **)((u8 *)card + 0x88);
        p1 = fat + 1;
        *fat = 0;
        *p1 = 0;
        src = fat + 2;
        i = 0x1FFC / 2;
        if (i > 0) {
            s32 n = (u32)i >> 3;
            if (n != 0) {
                do {
                    *fat += src[0]; temp = src[0]; *p1 += (u16)~temp;
                    *fat += src[1]; temp = src[1]; *p1 += (u16)~temp;
                    *fat += src[2]; temp = src[2]; *p1 += (u16)~temp;
                    *fat += src[3]; temp = src[3]; *p1 += (u16)~temp;
                    *fat += src[4]; temp = src[4]; *p1 += (u16)~temp;
                    *fat += src[5]; temp = src[5]; *p1 += (u16)~temp;
                    *fat += src[6]; temp = src[6]; *p1 += (u16)~temp;
                    *fat += src[7]; temp = src[7]; src += 8; *p1 += (u16)~temp;
                } while (--n);
            }
            i &= 7;
            if (i != 0) {
                do {
                    *fat += *src; temp = *src; src++; *p1 += (u16)~temp;
                } while (--i);
            }
        }
        if (*fat == 0xFFFF) {
            *fat = 0;
        }
        if (*p1 == 0xFFFF) {
            *p1 = 0;
        }
    }
    memcpy(blockFat[altFat ^ 1], blockFat[altFat], 0x2000);
    if (flagDir != 0) {
        if (outSize != 0) {
            *outSize = 0x2000;
        }
        return __CARDUpdateDir(chan, (s32)callback);
    }
    if ((flagFat | flagDirty) != 0) {
        if (outSize != 0) {
            *outSize = 0x2000;
        }
        return fn_802195B0(chan, *(void **)((u8 *)card + 0x88), callback);
    }
    __CARDPutControlBlock(card, 0);
    if (callback != 0) {
        irq = OSDisableInterrupts();
        callback(chan, 0);
        OSRestoreInterrupts(irq);
    }
    return 0;
}
#pragma pop
void fn_8021A7D4(void *arg0, s32 arg1) {
    void fn_8021A244(void *, void *, s32);
    s32 sp10;

    fn_8021A244(arg0, &sp10, arg1);
}

s32 fn_8021A7FC(u32 id) {
    extern u32 lbl_8029DB60[];
    extern u16 lbl_80366FF0;
    s32 sectorSize;
    s32 memSize;

    if (id & 0xFFFF0000) {
        if ((u32)(id + 0x80000000) != 4 || lbl_80366FF0 == 0xFFFF) {
            return 0;
        }
    }
    if (id & 3) {
        return 0;
    }
    memSize = id & 0xFC;
    switch (memSize) {
    case 4:
    case 8:
    case 0x10:
    case 0x20:
    case 0x40:
    case 0x80:
        break;
    default:
        return 0;
    }
    sectorSize = *(s32 *)((u8 *)lbl_8029DB60 + ((id >> 9) & 0x1C));
    if (sectorSize == 0) {
        return 0;
    }
    if (((memSize << 17) & 0x1FFE0000) / (u32)sectorSize < 8) {
        return 0;
    }
    return 1;
}

#pragma use_lmw_stmw on
s32 CARDProbeEx(s32 chan, s32 *memSize, s32 *sectorSize) {
    extern u16 __CARDBlock[];
    extern u32 lbl_8029DB60[];
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s32 EXIGetID(s32, s32, u32 *);
    s32 fn_8021A7FC(u32);
    s32 fn_80239508(s32);
    s32 fn_8023A114(s32);
    u8 *card;
    s32 enabled;
    s32 probe;
    s32 result;
    u32 id;

    if (chan < 0 || chan >= 2) {
        return -0x80;
    }
    if (*(u8 *)0x800030E3 & 0x80) {
        return -3;
    }
    card = (u8 *)__CARDBlock + chan * 0x110;
    enabled = OSDisableInterrupts();
    probe = fn_80239508(chan);
    if (probe == -1) {
        result = -3;
    } else if (probe == 0) {
        result = -1;
    } else if (*(s32 *)card != 0) {
        if (*(s32 *)(card + 0x24) < 1) {
            result = -1;
        } else {
            if (memSize != NULL) {
                *memSize = *(u16 *)(card + 8);
            }
            if (sectorSize != NULL) {
                *sectorSize = *(s32 *)(card + 0xC);
            }
            result = 0;
        }
    } else if (fn_8023A114(chan) & 8) {
        result = -2;
    } else if (EXIGetID(chan, 0, &id) == 0) {
        result = -1;
    } else if (fn_8021A7FC(id) != 0) {
        if (memSize != NULL) {
            *memSize = (s32)(id & 0xFC);
        }
        if (sectorSize != NULL) {
            *sectorSize = *(s32 *)((u8 *)lbl_8029DB60 + ((id >> 9) & 0x1C));
        }
        result = 0;
    } else {
        result = -2;
    }
    OSRestoreInterrupts(enabled);
    return result;
}

#pragma push
#pragma optimization_level 4
s32 fn_8021AA44(s32 chan) {
    s32 EXIGetID(s32, s32, u32 *);
    s32 EXIUnlock(s32);
    s32 fn_8021A7FC(u32);
    s32 fn_80216E98(s32, void *);
    s32 fn_80217D4C(void);
    s32 fn_80216F88(s32);
    s32 fn_80216DA8(s32, u8 *);
    s32 fn_80239488(s32);
    s32 fn_802180DC(s32, void *);
    void *__OSLockSramEx(void);
    void __OSUnlockSramEx(s32);
    s32 fn_80216CE8(s32, s32);
    void fn_80239298(s32, void *);
    void fn_80216AA4(void);
    void fn_8021AE98(s32, s32);
    s32 fn_802190A4(s32, u32, u32, void *, void *);
    void __CARDPutControlBlock(void *, s32);
    void fn_8021B170(s32, s32);
    extern u16 __CARDBlock[];
    extern s32 lbl_8029DB60[], lbl_8029DB80[];
    extern u16 lbl_80366FF0;

    typedef struct {
        u8 flashID[2][12];
        u8 pad18[0xE];
        u8 flashIDCheckSum[2];
    } SramEx;

    typedef struct {
        u8 pad0[0x8];
        u16 size;
        u16 pageSize;
        s32 sectorSize;
        u16 cBlock;
        u16 vendorID;
        s32 latency;
        u8 flashID[12];
        s32 mountStep;
        u8 pad28[0x58];
        void *workArea;
        u8 pad84[0x84];
        u32 id;
    } CardCtrl;

    CardCtrl *card;
    u32 id;
    u8 status;
    s32 result;
    SramEx *sram;
    int i;
    u8 checkSum;
    s32 step;
    u16 code;

    card = (CardCtrl *)((u8 *)__CARDBlock + chan * 0x110);
    if (card->mountStep == 0) {
        if (!EXIGetID(chan, 0, &id)) {
            result = -3;
        } else if (fn_8021A7FC(id)) {
            result = 0;
        } else {
            result = -2;
        }
        if (result < 0) {
            goto fail;
        }
        card->id = id;
        card->size = id & 0xFC;
        card->sectorSize = *(s32 *)((u8 *)lbl_8029DB60 + ((id >> 9) & 0x1C));
        card->cBlock = ((s32)(card->size << 20) / 8) / card->sectorSize;
        card->latency = *(s32 *)((u8 *)lbl_8029DB80 + ((id >> 6) & 0x1C));
        result = fn_80216E98(chan, &card->vendorID);
        if (result < 0) {
            goto fail;
        }
        if (fn_80217D4C() && (card->vendorID >> 8) == 0xEC) {
            card->pageSize = 512;
        } else {
            card->pageSize = 128;
        }
        result = fn_80216F88(chan);
        if (result < 0) {
            goto fail;
        }
        result = fn_80216DA8(chan, &status);
        if (result < 0) {
            goto fail;
        }
        if (!fn_80239488(chan)) {
            result = -3;
            goto fail;
        }
        if (!(status & 0x40)) {
            result = fn_802180DC(chan, card->flashID);
            if (result < 0) {
                goto fail;
            }
            sram = (SramEx *)__OSLockSramEx();
            checkSum = 0;
            for (i = 0; i < 12; ++i) {
                sram->flashID[chan][i] = card->flashID[i];
                checkSum += card->flashID[i];
            }
            sram->flashIDCheckSum[chan] = ~checkSum;
            __OSUnlockSramEx(1);
            return result;
        }
        card->mountStep = 1;
        sram = (SramEx *)__OSLockSramEx();
        checkSum = 0;
        for (i = 0; i < 12; ++i) {
            checkSum += sram->flashID[chan][i];
        }
        __OSUnlockSramEx(0);
        if (sram->flashIDCheckSum[chan] != (u8)~checkSum) {
            result = -5;
            goto fail;
        }
    }
    if (card->mountStep == 1) {
        if (card->id == 0x80000004) {
            sram = (SramEx *)__OSLockSramEx();
            code = *(u16 *)sram->flashID[chan];
            __OSUnlockSramEx(0);
            if (lbl_80366FF0 == 0xFFFF || code != lbl_80366FF0) {
                result = -2;
                goto fail;
            }
        }
        card->mountStep = 2;
        result = fn_80216CE8(chan, 1);
        if (result < 0) {
            goto fail;
        }
        fn_80239298(chan, fn_80216AA4);
        EXIUnlock(chan);
        DCInvalidateRange(card->workArea, 0xA000);
    }
    step = card->mountStep - 2;
    result = fn_802190A4(chan, card->sectorSize * step, 0x2000, (u8 *)card->workArea + (step << 13), fn_8021AE98);
    if (result < 0) {
        __CARDPutControlBlock(card, result);
    }
    return result;
fail:
    EXIUnlock(chan);
    fn_8021B170(chan, result);
    return result;
}
#pragma pop
void fn_8021AE98(s32 chan, s32 result) {
    extern u16 __CARDBlock[];
    s32 EXILock(s32,s32,void*);
    s32 fn_8021A1B8(void*);
    s32 fn_8021AA44(s32);
    void fn_8021B170(s32,s32);
    s32 __CARDPutControlBlock(void *, s32);
    u8 *card;
    void (*callback)(s32,s32);
    card=(u8*)__CARDBlock+chan*0x110;
    switch(result) {
    case 0:
        if(++*(s32*)(card+0x24)<7) {
            result=fn_8021AA44(chan);
            if(result>=0) return;
        } else {
            result=fn_8021A1B8(card);
        }
        break;
    case 1:
        *(void(**)(s32,s32))(card+0xdc)=fn_8021AE98;
        if(!EXILock(chan,0,__CARDLockCallback)) return;
        *(void**)(card+0xdc)=0;
        result=fn_8021AA44(chan);
        if(result>=0) return;
        break;
    case -3:
    case -5:
        fn_8021B170(chan,result);
        break;
    }
    callback=*(void(**)(s32,s32))(card+0xd0);
    *(void**)(card+0xd0)=0;
    __CARDPutControlBlock(card,result);
    callback(chan,result);
}

s32 fn_8021AFD0(s32 chan, void *work, void *detach, void *callback) {
extern u16 __CARDBlock[];
s32 fn_8023A114(s32);
s32 fn_802395BC(s32,void *);
void fn_80239298(s32,void *);
void OSCancelAlarm(void *);
s32 EXILock(s32,s32,void *);
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
u8 *card;
s32 enabled;
if(chan<0||chan>=2) return -128;
if(*(u8 *)0x800030E3&0x80) return -3;
card=(u8 *)__CARDBlock+chan*0x110;
enabled=OSDisableInterrupts();
if(*(s32 *)(card+4)==-1) {OSRestoreInterrupts(enabled);return -1;}
if(*(s32 *)card==0&&(fn_8023A114(chan)&8)) {OSRestoreInterrupts(enabled);return -2;}
*(s32 *)(card+4)=-1;
*(void **)(card+0x80)=work;
*(void **)(card+0xC4)=detach;
*(void **)(card+0xD0)=callback ? callback : (void *)fn_80216994;
*(s32 *)(card+0xCC)=0;
if(*(s32 *)card==0&&!fn_802395BC(chan,fn_802169CC)){
*(s32 *)(card+4)=-3;
OSRestoreInterrupts(enabled);return -3;
}
*(s32 *)(card+0x24)=0;
*(s32 *)card=1;
fn_80239298(chan,0);
OSCancelAlarm(card+0xE0);
*(s32 *)(card+0x84)=0;
*(s32 *)(card+0x88)=0;
OSRestoreInterrupts(enabled);
*(void (**)(s32,s32))(card+0xDC)=fn_8021AE98;
if(!EXILock(chan,0,__CARDLockCallback)) return 0;
*(s32 *)(card+0xDC)=0;
return fn_8021AA44(chan);
}

#pragma opt_strength_reduction off

void fn_8021B170(s32 chan, s32 result) {
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    u32 enabled;
    u8 *card;
    card = (u8 *)__CARDBlock + chan * 0x110;
    enabled = OSDisableInterrupts();
    if (*(s32 *)card != 0) {
        fn_80239298(chan,0);
        fn_802396C8(chan);
        OSCancelAlarm(card+0xE0);
        *(s32 *)card = 0;
        *(s32 *)(card+4) = result;
        *(s32 *)(card+0x24) = 0;
    }
    OSRestoreInterrupts(enabled);
}

#pragma global_optimizer off
s32 fn_8021B20C(s32 chan) {
    s32 fn_80217B18(s32, void **);
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    void fn_80239298(s32, s32);
    void fn_802396C8(s32);
    void OSCancelAlarm(void *);

    void *handle;
    s32 result;
    u32 enabled;
    u8 *card;

    result = fn_80217B18(chan, &handle);
    if (result < 0) {
        return result;
    }

    card = (u8 *)__CARDBlock + chan * 0x110;
    enabled = OSDisableInterrupts();
    if (*(s32 *)card != 0) {
        fn_80239298(chan, 0);
        fn_802396C8(chan);
        OSCancelAlarm(card + 0xE0);
        *(s32 *)card = 0;
        *(s32 *)(card + 4) = -3;
        *(s32 *)(card + 0x24) = 0;
    }
    OSRestoreInterrupts(enabled);
    return 0;
}
#pragma global_optimizer on

#pragma dont_inline on
void fn_8021B2B8(s32 chan, s32 result) {
    extern u16 __CARDBlock[];
    s32 __CARDEraseSector(s32, s32, void *);
    s32 fn_802191F0(s32, s32, s32, s32, void *);
    void *memcpy(void *, const void *, u32);
    s32 __CARDPutControlBlock(void *, s32);
    u8 *card;
    void (*callback)(s32, s32);
    s32 step;
    s32 i;

    card = (u8 *)__CARDBlock + chan * 0x110;
    if (result >= 0) {
        *(s32 *)(card + 0x28) = *(s32 *)(card + 0x28) + 1;
        step = *(s32 *)(card + 0x28);
        if (step < 5) {
            result = __CARDEraseSector(chan, *(s32 *)(card + 0xC) * step, fn_8021B2B8);
            if (result >= 0) {
                return;
            }
        } else if (step < 10) {
            i = step - 5;
            result = fn_802191F0(chan, *(s32 *)(card + 0xC) * i, 0x2000,
                                (s32)(*(u8 **)(card + 0x80) + (i << 13)), fn_8021B2B8);
            if (result >= 0) {
                return;
            }
        } else {
            *(u8 **)(card + 0x84) = *(u8 **)(card + 0x80) + 0x2000;
            memcpy(*(void **)(card + 0x84), *(u8 **)(card + 0x80) + 0x4000, 0x2000);
            *(u8 **)(card + 0x88) = *(u8 **)(card + 0x80) + 0x6000;
            memcpy(*(void **)(card + 0x88), *(u8 **)(card + 0x80) + 0x8000, 0x2000);
        }
    }
    callback = *(void (**)(s32, s32))(card + 0xD0);
    *(void **)(card + 0xD0) = 0;
    __CARDPutControlBlock(card, result);
    callback(chan, result);
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_strength_reduction on
s32 fn_8021B3FC(s32 chan, s16 arg1, void *callback)
{
    s32 fn_80217B18(s32, void **);
    void *memset(void *, s32, u32);
    void *__OSLockSram(void);
    void __OSUnlockSram(s32);
    u8 *__OSLockSramEx(void);
    void __OSUnlockSramEx(s32);
    s64 OSGetTime(void);
    void fn_802198C0(void *, u32, void *, void *);
    void fn_80205110(void *, u32);
    s32 __CARDEraseSector(s32, s32, void *, void *);
    void __CARDPutControlBlock(void *, s32);
    extern void fn_80216994(void);
    extern void fn_8021B2B8(void);

    void *card;
    u8 *work;
    u16 dsp;
    void *sram;
    s64 time;
    s64 seed;
    u8 *flash;
    u8 *p;
    s16 i;
    s16 limit;
    u8 *block;
    void *cb;
    s32 result;

    result = fn_80217B18(chan, &card);
    if (result < 0) {
        return result;
    }

    work = *(u8 **)((u8 *)card + 0x80);
    memset(work, 0xFF, 0x2000);
    dsp = *(u16 *)0xCC00206E;
    *(s16 *)(work + 0x24) = arg1;

    sram = __OSLockSram();
    *(u32 *)(work + 0x14) = *(u32 *)((u8 *)sram + 0xC);
    *(u32 *)(work + 0x18) = *(u8 *)((u8 *)sram + 0x12);
    __OSUnlockSram(0);

    time = OSGetTime();
    seed = time;
    flash = __OSLockSramEx() + chan * 0xC;
    p = flash;
    i = 0;
    limit = 4;

    while (i < limit) {
        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        work[i] = (u8)(seed + *p);
        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        seed &= 0x7FFF;

        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        work[(s16)(i + 1)] = (u8)(seed + flash[(s16)(i + 1)]);
        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        seed &= 0x7FFF;

        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        work[(s16)(i + 2)] = (u8)(seed + flash[(s16)(i + 2)]);
        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        seed &= 0x7FFF;

        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        work[(s16)(i + 3)] = (u8)(seed + flash[(s16)(i + 3)]);
        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        seed &= 0x7FFF;

        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        work[(s16)(i + 4)] = (u8)(seed + flash[(s16)(i + 4)]);
        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        seed &= 0x7FFF;

        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        work[(s16)(i + 5)] = (u8)(seed + flash[(s16)(i + 5)]);
        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        seed &= 0x7FFF;

        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        work[(s16)(i + 6)] = (u8)(seed + flash[(s16)(i + 6)]);
        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        seed &= 0x7FFF;

        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        work[(s16)(i + 7)] = (u8)(seed + flash[(s16)(i + 7)]);
        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        seed &= 0x7FFF;

        p += 8;
        i += 8;
    }

    p = flash + i;
    while (i < 0xC) {
        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        work[i] = (u8)(seed + *p);
        seed = (seed * 0x41C64E6D + 0x3039) >> 16;
        seed &= 0x7FFF;
        p += 1;
        i += 1;
    }

    __OSUnlockSramEx(0);
    *(u32 *)(work + 0x1C) = dsp;
    i = 0;
    *(s64 *)(work + 0xC) = time;
    *(s16 *)(work + 0x20) = 0;
    *(u16 *)(work + 0x22) = *(u16 *)((u8 *)card + 8);
    fn_802198C0(work, 0x1FC, work + 0x1FC, work + 0x1FE);

    while (i < 2) {
        block = *(u8 **)((u8 *)card + 0x80) + ((i + 1) << 13);
        memset(block, 0xFF, 0x2000);
        *(s16 *)(block + 0x1FFA) = i;
        p = block + 0x1FC0;
        fn_802198C0(block, 0x1FFC, p + 0x3C, p + 0x3E);
        i += 1;
    }

    i = 0;
    while (i < 2) {
        block = *(u8 **)((u8 *)card + 0x80) + ((i + 3) << 13);
        memset(block, 0, 0x2000);
        *(s16 *)(block + 4) = i;
        *(s16 *)(block + 6) = *(u16 *)((u8 *)card + 0x10) - 5;
        *(s16 *)(block + 8) = 4;
        fn_802198C0(block + 4, 0x1FFC, block, block + 2);
        i += 1;
    }

    if (callback != 0) {
        cb = callback;
    } else {
        cb = (void *)fn_80216994;
    }
    *(void **)((u8 *)card + 0xD0) = cb;
    fn_80205110(*(void **)((u8 *)card + 0x80), 0xA000);
    *(u32 *)((u8 *)card + 0x28) = 0;
    result = __CARDEraseSector(chan, *(s32 *)((u8 *)card + 0xC) * *(s32 *)((u8 *)card + 0x28), (void *)fn_8021B2B8, card);
    if (result < 0) {
        __CARDPutControlBlock(card, result);
    }
    return result;
}
#pragma pop
void fn_8021BA54(s32 arg0, s32 arg1) {
    s32 fn_8021B3FC(s32, u16, s32);
    fn_8021B3FC(arg0, fn_80217AD8(), arg1);
}
#pragma dont_inline reset
s32 fn_8021BA9C(void *arg0, char *name) {
    char *p;
    s8 a;
    s8 b;
    s32 n;

    p = (char *)arg0 + 8;
    n = 0x20;
    while (--n >= 0) {
        a = *p++;
        b = *name++;
        if (a != b) {
            return 0;
        }
        if (b == 0) {
            return 1;
        }
    }
    if ((s8)*name == 0) {
        return 1;
    }
    return 0;
}

s32 fn_8021BB04(void *arg0, u8 *arg1) {
    s32 fn_80231944(void *, void *, u32);
    extern u8 lbl_8033A420[];
    u8 *p = M2C_FIELD(arg0, u8 **, 0x10C);

    if (*arg1 == 0xFF) {
        return -4;
    }
    if (p == lbl_8033A420 || (fn_80231944(arg1, p, 4) == 0 && fn_80231944(arg1 + 4, p + 4, 2) == 0)) {
        return 0;
    }
    return -10;
}

s32 fn_8021BB98(void *arg0, void *arg1)
{
    s32 fn_80231944(const void *, const void *, u32);
    extern u8 lbl_8033A420[];
    extern u8 lbl_80366FF2;
    s32 result;
    u8 *reference;
    u8 flags;
    u8 *data;

    data = arg1;
    reference = *(u8 **)((u8 *)arg0 + 0x10C);

    if (data[0] == 0xFF) {
        result = -4;
        goto done;
    }
    if (reference == lbl_8033A420 ||
        (fn_80231944(data, reference, 4) == 0 &&
         fn_80231944(data + 4, reference + 4, 2) == 0)) {
        result = 0;
        goto done;
    }
    result = -10;
done:
    if (result == -10) {
        flags = (u8)(data[0x34] & lbl_80366FF2);
        if (flags & 0x20) {
            if (fn_80231944(data, lbl_8033A420, 4) == 0 &&
                fn_80231944(data + 4, lbl_8033A420 + 4, 2) == 0) {
                return 0;
            }
        }
        if (flags & 0x40) {
            if (fn_80231944(data, lbl_8033A420, 4) == 0 &&
                fn_80231944(data + 4, reference + 4, 2) == 0) {
                return 0;
            }
        }
    }
    return result;
}

#pragma use_lmw_stmw on
s32 fn_8021BCCC(void *arg0, void *arg1)
{
    s32 fn_8021BB04(void *);
    s32 fn_80231944(const void *, const void *, u32);
    extern u8 lbl_80366FF2;
    extern u8 lbl_8033A420[];
    u8 flags;
    s32 result;
    u8 *saved;
    u8 *data;

    data = (u8 *)arg1;
    saved = *(u8 **)((u8 *)arg0 + 0x10C);
    result = fn_8021BB04(arg0);
    if (result == -10) {
        flags = (u8)(data[0x34] & lbl_80366FF2);
        if (flags & 0x20) {
            if (fn_80231944(data, lbl_8033A420, 4) == 0) {
                if (fn_80231944(data + 4, lbl_8033A420 + 4, 2) == 0) {
                    result = 0;
                    goto after;
                }
            }
        }
        if (flags & 0x40) {
            if (fn_80231944(data, lbl_8033A420, 4) == 0) {
                if (fn_80231944(data + 4, saved + 4, 2) == 0) {
                    result = 0;
                }
            }
        }
    }
after:
    if (result == -10) {
        if (data[0x34] & 4) {
            return 0;
        }
    }
    return result;
}
static inline BOOL fn_8021BDC0_CompareFileName(u8 *ent, const char *fileName)
{
    char *entName;
    char c1;
    char c2;
    int n;

    entName = (char *)ent + 8;
    n = 0x20;
    while (0 <= --n) {
        if ((c1 = *entName++) != (c2 = *fileName++)) {
            return FALSE;
        } else if (c2 == '\0') {
            return TRUE;
        }
    }
    if (*fileName == '\0') {
        return TRUE;
    }
    return FALSE;
}

static inline s32 fn_8021BDC0_Access(void *card, u8 *ent)
{
    s32 fn_80231944(const void *, const void *, u32);
    extern u8 lbl_8033A420[];
    u8 *diskID = *(u8 **)((u8 *)card + 0x10C);

    if (ent[0] == 0xFF) {
        return -4;
    }
    if (diskID == lbl_8033A420 || (fn_80231944(ent, diskID, 4) == 0 && fn_80231944(ent + 4, diskID + 4, 2) == 0)) {
        return 0;
    }
    return -10;
}

#pragma push
#pragma opt_loop_invariants off
s32 fn_8021BDC0(void *card, char *filename, s32 *outIndex)
{
    u8 *__CARDGetDirBlock(void *);
    u8 *dir;
    u8 *ent;
    s32 fileNo;
    s32 result;

    if (*(s32 *)card == 0) {
        return -3;
    }
    ent = __CARDGetDirBlock(card);
    for (fileNo = 0; fileNo < 0x7F; fileNo++, ent += 0x40) {
        result = fn_8021BDC0_Access(card, ent);
        if (result < 0) {
            continue;
        }
        if (fn_8021BDC0_CompareFileName(ent, filename)) {
            *outIndex = fileNo;
            return 0;
        }
    }
    return -4;
}
#pragma pop

static inline s32 fn_8021BF10_GetFileNo(void *card, void *fileName, s32 *pfileNo)
{
    void *__CARDGetDirBlock(void *);
    s32 fn_8021BB04(void *, void *);
    s32 fn_8021BA9C(void *, void *);
    u8 *ent;
    s32 fileNo;
    s32 result;

    if (*(s32 *)card == 0) return -3;
    ent = (u8 *)__CARDGetDirBlock(card);
    for (fileNo = 0; fileNo < 0x7f; fileNo++, ent += 0x40) {
        result = fn_8021BB04(card, ent);
        if (result < 0) continue;
        if (fn_8021BA9C(ent, fileName)) {
            *pfileNo = fileNo;
            return 0;
        }
    }
    return -4;
}

s32 fn_8021BF10(void *arg0, void *arg1, void *arg2)
{
    s32 fn_80217B18(void *, void **);
    void *__CARDGetDirBlock(void *);
    s32 __CARDPutControlBlock(void *, s32);
    void *card;
    u8 *dir;
    u8 *ent;
    s32 result;
    s32 fileNo;

    *(s32 *)arg2 = -1;
    result = fn_80217B18(arg0, &card);
    if (result < 0) return result;
    result = fn_8021BF10_GetFileNo(card, arg1, &fileNo);
    if (0 <= result) {
        dir = (u8 *)__CARDGetDirBlock(card);
        ent = dir + (fileNo << 6);
        if (!(5 <= *(u16 *)(ent + 0x36) && *(u16 *)(ent + 0x36) < *(u16 *)((u8 *)card + 0x10))) {
            result = -6;
        } else {
            *(void **)arg2 = arg0;
            *(s32 *)((u8 *)arg2 + 4) = fileNo;
            *(s32 *)((u8 *)arg2 + 8) = 0;
            *(u16 *)((u8 *)arg2 + 0x10) = *(u16 *)(ent + 0x36);
        }
    }
    return __CARDPutControlBlock(card, result);
}

s32 fn_8021C02C(s32 *arg0) {
    s32 fn_80217B18(s32, s32 *);
    s32 __CARDPutControlBlock(void *, s32);
    s32 spC;
    s32 result;

    result = fn_80217B18(*arg0, &spC);
    if (result < 0) {
        return result;
    }
    *arg0 = -1;
    return __CARDPutControlBlock((void *)spC, 0);
}

s32 fn_8021C080(void) {
    return 0;
}

void fn_8021C088(s32 chan, s32 result)
{
    extern u16 __CARDBlock[];

    s32 __CARDGetDirBlock(void *);
    s32 __CARDUpdateDir(s32, s32);
    s32 __CARDPutControlBlock(void *, s32);
    s64 OSGetTime(void);
    void *memcpy(void *, const void *, u32);

    u8 *card;
    u8 *entry;
    void (*callback)(s32, s32);
    u32 ticks;
    s64 time;

    card = (u8 *)__CARDBlock + chan * 0x110;
    callback = *(void (**)(s32, s32))(card + 0xD0);
    *(u32 *)(card + 0xD0) = 0;

    if (result >= 0) {
        entry = (u8 *)__CARDGetDirBlock(card);
        entry += *(u16 *)(card + 0xBC) << 6;

        memcpy(entry, *(u8 **)(card + 0x10C), 4);
        memcpy(entry + 4, *(u8 **)(card + 0x10C) + 4, 2);

        entry[0x34] = 4;
        entry[0x35] = 0;
        *(u16 *)(entry + 0x36) = *(u16 *)(card + 0xBE);

        entry[7] = 0;
        *(s32 *)(entry + 0x2C) = -1;
        *(u16 *)(entry + 0x30) = 0;
        *(u16 *)(entry + 0x32) = 0;
        *(s32 *)(entry + 0x3C) = -1;

        *(u16 *)(entry + 0x32) =
            (*(u16 *)(entry + 0x32) & ~3) | 1;

        *(u32 *)(*(u8 **)(card + 0xC0) + 8) = 0;

        *(u16 *)(*(u8 **)(card + 0xC0) + 0x10) =
            *(u16 *)(entry + 0x36);

        ticks = *(u32 *)0x800000F8 >> 2;
        time = OSGetTime();

        *(u32 *)(entry + 0x28) = (u32)(time / ticks);

        result = __CARDUpdateDir(chan, (s32)callback);
        if (result >= 0) goto done;
    }

    __CARDPutControlBlock(card, result);
    if (callback != 0) {
        callback(chan, result);
    }
done:;
}

#pragma use_lmw_stmw on
s32 CARDCreateAsync(s32 chan, char *name, u32 size, void *fileInfo, void *callback) {
    s32 fn_80217B18(s32, CardCtrl **);
    s32 __CARDPutControlBlock(CardCtrl *, s32);
    void *__CARDGetFatBlock(CardCtrl *);
    s32 fn_802193FC(s32, u32, void *);
    u8 *__CARDGetDirBlock(CardCtrl *);
    s32 fn_8021BA9C(u8 *, char *);
    s32 fn_80231944(u8 *, void *, s32);
    void Str_CopyPad(u8 *, char *, s32);
    u32 strlen(char *);
    extern void fn_80216994(void);
    extern void fn_8021C088(void);

    CardCtrl *card;
    u8 *dir;
    u8 *ent;
    u16 freeIdx;
    u16 i;
    s32 result;
    void *cb;
    u8 *slot;
    void *stat;

    if (strlen(name) > 0x20) {
        return -0xC;
    }
    result = fn_80217B18(chan, &card);
    if (result < 0) {
        return result;
    }
    if (size == 0 || (size % card->sectorSize) != 0) {
        return -0x80;
    }
    freeIdx = 0xFFFF;
    dir = __CARDGetDirBlock(card);
    ent = dir;
    for (i = 0; i < 0x7F; ent += 0x40, i += 1) {
        if (*ent == 0xFF) {
            if (freeIdx == 0xFFFF) {
                freeIdx = i;
            }
        } else if (fn_80231944(ent, card->diskID, 4) == 0
            && fn_80231944(ent + 4, (u8 *)card->diskID + 4, 2) == 0
            && fn_8021BA9C(ent, name) != 0) {
            return __CARDPutControlBlock(card, -7);
        }
    }
    if (freeIdx == 0xFFFF) {
        return __CARDPutControlBlock(card, -8);
    }
    stat = __CARDGetFatBlock(card);
    if ((u32)(card->sectorSize * *(u16 *)((u8 *)stat + 6)) < size) {
        return __CARDPutControlBlock(card, -9);
    }
    if (callback != NULL) {
        cb = callback;
    } else {
        cb = fn_80216994;
    }
    card->apiCb = cb;
    slot = dir + (freeIdx << 6);
    card->fileNo = freeIdx;
    *(u16 *)(slot + 0x38) = (u16)(size / card->sectorSize);
    Str_CopyPad(slot + 8, name, 0x20);
    card->apiFd = fileInfo;
    *(s32 *)fileInfo = chan;
    *(u32 *)((u8 *)fileInfo + 4) = freeIdx;
    result = fn_802193FC(chan, size / card->sectorSize, fn_8021C088);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }
    return result;
}

s32 fn_8021C3D8(s32 chan, char *name, u32 size, void *fileInfo) {
 s32 fn_80217C64(s32);
 void fn_80216998(s32,s32);
 s32 result = CARDCreateAsync(chan,name,size,fileInfo,fn_80216998);
 if (result < 0) return result;
 return fn_80217C64(chan);
}

s32 fn_8021C420(void *arg0,s32 length,s32 offset,void **out) {
s32 fn_80217B18(s32,void **);
s32 __CARDPutControlBlock(void *,s32);
u8 *__CARDGetDirBlock(void *);
u16 *__CARDGetFatBlock(void *);
u8 *card;
u8 *file=arg0;
u8 *entry;
u16 *fat;
s32 result;
u8 *dirBlock;
result=fn_80217B18(*(s32 *)file,(void **)&card);
if(result<0) return result;
if(*(u16 *)(file+0x10)<5 || *(u16 *)(file+0x10)>=*(u16 *)(card+0x10) ||
(s32)(*(u16 *)(card+0x10)**(s32 *)(card+0xC))<=*(s32 *)(file+8))
return __CARDPutControlBlock(card,-128);
dirBlock=__CARDGetDirBlock(card);
entry=dirBlock+(*(s32 *)(file+4)<<6);
if(*(u16 *)(entry+0x38)**(s32 *)(card+0xC)<=offset||*(u16 *)(entry+0x38)**(s32 *)(card+0xC)<offset+length) return __CARDPutControlBlock(card,-11);
*(void **)(card+0xC0)=file;
*(s32 *)(file+0xC)=length;
if(offset<*(s32 *)(file+8)){
*(s32 *)(file+8)=0;
*(u16 *)(file+0x10)=*(u16 *)(entry+0x36);
if(*(u16 *)(file+0x10)<5 || *(u16 *)(file+0x10)>=*(u16 *)(card+0x10))
return __CARDPutControlBlock(card,-6);
}
fat=__CARDGetFatBlock(card);
while((u32)*(s32 *)(file+8)<(u32)(offset&~(*(s32 *)(card+0xC)-1))){
*(s32 *)(file+8)+=*(s32 *)(card+0xC);
*(u16 *)(file+0x10)=fat[*(u16 *)(file+0x10)];
if(*(u16 *)(file+0x10)<5 || *(u16 *)(file+0x10)>=*(u16 *)(card+0x10))
return __CARDPutControlBlock(card,-6);
}
*(s32 *)(file+8)=offset;
*out=card;
return 0;
}

void fn_8021C5D8(s32 chan, s32 result) {
    extern u16 __CARDBlock[];
    s32 fn_802190A4(s32, u32, u32, void *, void *);
    void *__CARDGetFatBlock(void *);
    s32 __CARDPutControlBlock(void *, s32);

    u8 *card;
    void (*callback)(s32, s32);
    u16 *fat;
    u8 *file;
    s32 length;
    s32 n;

    card = (u8 *)__CARDBlock + chan * 0x110;
    if (result < 0) {
        goto error;
    }

    file = *(u8 **)(card + 0xC0);
    if (*(s32 *)(file + 0xC) < 0) {
        result = -14;
        goto error;
    }

    n = *(s32 *)(card + 0xC) - 1;
    n = ~n;
    length = ((*(s32 *)(file + 8) + *(s32 *)(card + 0xC)) & n) - *(s32 *)(file + 8);
    *(s32 *)(file + 0xC) -= length;
    if (*(s32 *)(file + 0xC) <= 0) {
        goto error;
    }

    fat = (u16 *)__CARDGetFatBlock(card);
    *(s32 *)(file + 8) += length;
    *(u16 *)(file + 0x10) = fat[*(u16 *)(file + 0x10)];
    if (*(u16 *)(file + 0x10) < 5 || *(u16 *)(file + 0x10) >= *(u16 *)(card + 0x10)) {
        result = -6;
        goto error;
    }

    result = fn_802190A4(
        chan,
        *(s32 *)(card + 0xC) * (u32)*(u16 *)(file + 0x10),
        (*(s32 *)(file + 0xC) < *(s32 *)(card + 0xC)) ? *(s32 *)(file + 0xC) : *(s32 *)(card + 0xC),
        *(void **)(card + 0xB4),
        (void *)fn_8021C5D8
    );

    if (result < 0) {
    error:
        callback = *(void (**)(s32, s32))(card + 0xD0);
        *(void (**)(s32, s32))(card + 0xD0) = 0;
        __CARDPutControlBlock(card, result);
        callback(chan, result);
    }
}

s32 fn_8021C708(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4)
{
    s32 fn_8021C420(void *, u32, u32, void **);
    s32 fn_802190A4(s32, u32, u32, void *, void *);
    s32 __CARDPutControlBlock(void *, s32);
    s32 __CARDGetDirBlock(void *);
    s32 fn_8021BCCC(void *, void *);
    void DCInvalidateRange(void *, u32);
    void fn_80216994(void);
    void fn_8021C5D8(s32, s32);

    void *card;
    u8 *entry;
    u32 start;
    s32 result;
    void *callback;

    if (((u32)arg3 & 0x1FF) != 0 || ((u32)arg2 & 0x1FF) != 0) {
        return -0x80;
    }

    result = fn_8021C420(arg0, arg2, arg3, &card);
    if (result < 0) return result;

    entry = (u8 *)__CARDGetDirBlock(card);
    entry += arg0[1] << 6;

    result = fn_8021BCCC(card, entry);
    if (result < 0) return __CARDPutControlBlock(card, result);

    DCInvalidateRange((void *)arg1, arg2);

    if (arg4 != 0) {
        callback = arg4;
    } else {
        callback = (void *)fn_80216994;
    }
    *(void **)((u8 *)card + 0xD0) = callback;

    start = *(u32 *)((u8 *)arg0 + 8) & (*(u32 *)((u8 *)card + 0xC) - 1);
    arg2 = (arg2 < (s32)(*(u32 *)((u8 *)card + 0xC) - start)) ? arg2 : (s32)(*(u32 *)((u8 *)card + 0xC) - start);
    result = fn_802190A4(
        arg0[0],
        *(u32 *)((u8 *)card + 0xC) * *(u16 *)((u8 *)arg0 + 0x10) + start,
        arg2,
        (void *)arg1,
        (void *)fn_8021C5D8
    );

    if (result < 0) __CARDPutControlBlock(card, result);
    return result;
}

s32 fn_8021C84C(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 fn_80217C64(s32);
    s32 fn_8021C708(s32 *, s32, s32, s32, void *);
    void fn_80216998(s32, s32);
    s32 result;

    result = fn_8021C708(arg0, arg1, arg2, arg3, fn_80216998);
    if (result < 0) {
        return result;
    }
    return fn_80217C64(*arg0);
}

s64 OSGetTime(void);
s32 __CARDGetDirBlock(void *arg0);
s32 __CARDGetFatBlock(void *arg0);
s32 __CARDUpdateDir(s32 arg0, s32 arg1);
s32 __CARDPutControlBlock(void *arg0, s32 arg1);
int __CARDEraseSector(s32 chan, u32 addr, void *callback);
void __CARDEraseCallback(s32 chan, s32 result);
#pragma dont_inline on
/* Continue a CARD file write: on success update dir time or erase/write next FAT block. */
void __CARDWriteCallback(s32 chan, s32 result) {
    u8 *card;
    void (*callback)(s32, s32);
    u16 *fat;
    u8 *ent;
    u8 *fileInfo;

    card = (u8 *)__CARDBlock + chan * 0x110;
    if (result < 0) {
        goto error;
    }

    fileInfo = *(u8 **)(card + 0xC0);
    if (*(s32 *)(fileInfo + 0xC) < 0) {
        result = CARD_RESULT_ENCODING;
        goto error;
    }

    *(s32 *)(fileInfo + 0xC) -= *(s32 *)(card + 0xC);
    if (*(s32 *)(fileInfo + 0xC) <= 0) {
        ent = (u8 *)__CARDGetDirBlock(card) + (*(s32 *)(fileInfo + 0x4) << 6);
        *(u32 *)(ent + 0x28) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 / 4));
        callback = *(void (**)(s32, s32))(card + 0xD0);
        *(void (**)(s32, s32))(card + 0xD0) = 0;
        result = __CARDUpdateDir(chan, (s32)callback);
    } else {
        fat = (u16 *)__CARDGetFatBlock(card);
        *(s32 *)(fileInfo + 0x8) += *(s32 *)(card + 0xC);
        *(u16 *)(fileInfo + 0x10) = fat[*(u16 *)(fileInfo + 0x10)];
        if (*(u16 *)(fileInfo + 0x10) < 5 || *(u16 *)(fileInfo + 0x10) >= *(u16 *)(card + 0x10)) {
            result = CARD_RESULT_BROKEN;
            goto error;
        }
        result = __CARDEraseSector(chan, *(s32 *)(card + 0xC) * (u32)*(u16 *)(fileInfo + 0x10), __CARDEraseCallback);
    }

    if (result < 0) {
    error:
        callback = *(void (**)(s32, s32))(card + 0xD0);
        *(void (**)(s32, s32))(card + 0xD0) = 0;
        __CARDPutControlBlock(card, result);
        callback(chan, result);
    }
}

void __CARDEraseCallback(s32 chan, s32 result) {
    u8 *card;
    void (*callback)(s32, s32);
    u8 *fileInfo;

    card = (u8 *)__CARDBlock + chan * 0x110;
    if (result < 0) {
        goto error;
    }

    fileInfo = *(u8 **)(card + 0xC0);
    result = fn_802191F0(chan, *(s32 *)(card + 0xC) * (u32)*(u16 *)(fileInfo + 0x10), *(s32 *)(card + 0xC), *(void **)(card + 0xB4), __CARDWriteCallback);
    if (result < 0) {
    error:
        callback = *(void (**)(s32, s32))(card + 0xD0);
        *(void (**)(s32, s32))(card + 0xD0) = 0;
        __CARDPutControlBlock(card, result);
        callback(chan, result);
    }
}

s32 fn_8021CAB4(void *arg0, void *arg1, u32 arg2, u32 arg3, void *arg4)
{
    s32 fn_8021C420(void *, u32, u32, void **);
    s32 __CARDPutControlBlock(void *, s32);
    void *__CARDGetDirBlock(void);
    s32 fn_8021BB98(void *, void *);
    void fn_80205110(void *, u32);
    s32 __CARDEraseSector(void *, u32, void *);

    extern void fn_80216994(void);
    extern void __CARDEraseCallback(void);

    void *state;
    u32 alignment;
    u32 size;
    s32 result;
    u8 *buffer;
    void *callback;

    result = fn_8021C420(arg0, arg2, arg3, &state);

    if (result < 0) {
        return result;
    }

    alignment = *(u32 *)((u8 *)state + 0xC) - 1;

    if ((arg3 & alignment) != 0 ||
        (arg2 & alignment) != 0) {
        return __CARDPutControlBlock(state, -0x80);
    }

    buffer = (u8 *)__CARDGetDirBlock();
    buffer += (*(u32 *)((u8 *)arg0 + 4) << 6);

    result = fn_8021BB98(state, buffer);

    if (result < 0) {
        return __CARDPutControlBlock(state, result);
    }

    fn_80205110(arg1, arg2);

    if (arg4 != 0) {
        callback = arg4;
    } else {
        callback = (void *)fn_80216994;
    }

    *(void **)((u8 *)state + 0xD0) = callback;
    *(void **)((u8 *)state + 0xB4) = arg1;

    size = *(u32 *)((u8 *)state + 0xC);
    size *= *(u16 *)((u8 *)arg0 + 0x10);

    result = __CARDEraseSector(*(void **)arg0, size, __CARDEraseCallback);

    if (result < 0) {
        __CARDPutControlBlock(state, result);
    }

    return result;
}

#pragma dont_inline reset
s32 fn_8021CBC8(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 fn_80217C64(s32);
    s32 fn_8021CAB4(s32 *, s32, s32, s32, void *);
    void fn_80216998(s32, s32);
    s32 result;

    result = fn_8021CAB4(arg0, arg1, arg2, arg3, fn_80216998);
    if (result < 0) {
        return result;
    }
    return fn_80217C64(*arg0);
}

#pragma optimization_level 3
void fn_8021CC10(s32 chan, s32 result) {
    extern u16 __CARDBlock[];
    s32 fn_80219514(s32, u16, void *);
    s32 __CARDPutControlBlock(void *, s32);

    u8 *card;
    void (*callback)(s32, s32);

    card = (u8 *)__CARDBlock + chan * 0x110;
    callback = *(void (**)(s32, s32))(card + 0xD0);
    *(void **)(card + 0xD0) = NULL;
    if ((result < 0) || (result = fn_80219514(chan, *(u16 *)(card + 0xBE), callback), result < 0)) {
        __CARDPutControlBlock(card, result);
        if (callback != NULL) {
            (*callback)(chan, result);
        }
    }
}
#pragma optimization_level reset
s32 fn_8021CCB4(s32 chan, char *name, void *callback) {
    s32 fn_80217B18(s32, s32 *);
    s32 fn_8021BDC0(void *, char *, s32 *);
    s32 fn_8021C080(void *, s32);
    s32 __CARDPutControlBlock(void *, s32);
    u8 *__CARDGetDirBlock(void *);
    s32 __CARDUpdateDir(s32, s32);
    void fn_80216994(void);
    void fn_8021CC10(void);
    s32 card;
    s32 index;
    s32 result;
    u8 *entry;
    result = fn_80217B18(chan, &card);
    if (result < 0) return result;
    result = fn_8021BDC0((void *)card, name, &index);
    if (result < 0) return __CARDPutControlBlock((void *)card, result);
    if (fn_8021C080((void *)card, index) != 0) return __CARDPutControlBlock((void *)card, -1);
    entry = __CARDGetDirBlock((void *)card) + (index << 6);
    *(u16 *)(card + 0xbe) = *(u16 *)(entry + 0x36);
    memset(entry, 255, 64);
    *(void **)(card + 0xd0) = callback ? callback : (void *)fn_80216994;
    result = __CARDUpdateDir(chan, (s32)fn_8021CC10);
    if (result < 0) __CARDPutControlBlock((void *)card, result);
    return result;
}

s32 fn_8021CDC4(s32 arg0,s32 arg1) {
s32 fn_8021CCB4(s32,s32,void*);
s32 fn_80217C64(s32);
void fn_80216998(s32,s32);
s32 result=fn_8021CCB4(arg0,arg1,fn_80216998);
if(result<0) return result;
return fn_80217C64(arg0);
}

void fn_8021CE0C(void *arg0,void *arg1){
u8 *entry=arg0;
struct Stat { u8 pad[0x44]; s32 icons[8]; };
u8 *stat=arg1;
u32 offset;
s32 palette;
s32 i;
offset=*(u32 *)(entry+0x2C);
if(offset==0xFFFFFFFF){
stat[0x2E]=0;
offset=0;
*(u16 *)(stat+0x34)=0;
*(u16 *)(stat+0x36)=0;
}
palette=0;
switch(entry[7]&3){
case 1:
*(s32 *)(stat+0x3C)=offset;
*(s32 *)(stat+0x40)=offset+0xC00;
offset+=0xE00;
break;
case 2:
*(s32 *)(stat+0x3C)=offset;
*(s32 *)(stat+0x40)=-1;
offset+=0x1800;
break;
default:
*(s32 *)(stat+0x3C)=-1;
*(s32 *)(stat+0x40)=-1;
}
for(i=0;i<8;i++){
switch((*(u16 *)(entry+0x30)>>(2*i))&3){
case 1:
((struct Stat *)stat)->icons[i]=offset;
palette=1;
offset+=0x400;
break;
case 2:
((struct Stat *)stat)->icons[i]=offset;
offset+=0x800;
break;
default:
((struct Stat *)stat)->icons[i]=-1;
}
}
if(palette){*(s32 *)(stat+0x64)=offset;offset+=0x200;}
else *(s32 *)(stat+0x64)=-1;
*(s32 *)(stat+0x68)=offset;
}

s32 fn_8021D004(s32 arg0, s32 arg1, s32 arg2) {
    s32 fn_80217B18(s32, s32 *);
    s32 fn_8021BCCC(void *, void *);
    void fn_8021CE0C(void *, void *);
    s32 __CARDPutControlBlock(void *, s32);
    u8 *__CARDGetDirBlock(void *);
    s32 card;
    s32 result;
    u8 *entry;
    u8 *stat=(u8*)arg2;
    if(arg1<0 || arg1>=127) return -128;
    result=fn_80217B18(arg0,&card);
    if(result<0) return result;
    entry=(u8*)__CARDGetDirBlock((void*)card)+(arg1<<6);
    result=fn_8021BCCC((void*)card,entry);
    if(result>=0) {
        memcpy(stat+0x28,entry,4);
        memcpy(stat+0x2c,entry+4,2);
        *(u32*)(stat+0x20)=*(u16*)(entry+0x38)* *(u32*)(card+0xc);
        memcpy(stat,entry+8,32);
        *(u32*)(stat+0x24)=*(u32*)(entry+0x28);
        stat[0x2e]=entry[7];
        *(u32*)(stat+0x30)=*(u32*)(entry+0x2c);
        *(u16*)(stat+0x34)=*(u16*)(entry+0x30);
        *(u16*)(stat+0x36)=*(u16*)(entry+0x32);
        *(u32*)(stat+0x38)=*(u32*)(entry+0x3c);
        fn_8021CE0C(entry,stat);
    }
    return __CARDPutControlBlock((void*)card,result);
}

s32 fn_8021D118(s32 chan, s32 fileNo, void *stat, s32 callback) {
#pragma dont_inline on
#pragma use_lmw_stmw off

    s32 card;
    s32 result;
    u32 address;
    u32 ticksPerSecond;
    u8 *status = (u8 *)stat;
    CardDirEntry *entry;
    u8 *__CARDGetDirBlock(void *);
    s32 __CARDPutControlBlock(void *, s32);
    s32 __CARDUpdateDir(s32, s32);

    if (fileNo < 0 || fileNo >= 0x7F) {
        goto invalid;
    }

    address = *(u32 *)(status + 0x30);
    if (address + 0x10000U != 0xFFFFU && address >= 0x200U) {
        goto invalid;
    }

    address = *(u32 *)(status + 0x38);
    if (address + 0x10000U == 0xFFFFU || (address & 0x1FFFU) <= 0x1FC0U) {
        goto valid;
    }

invalid:
    return -0x80;

valid:
    result = fn_80217B18(chan, &card);
    if (result < 0) {
        return result;
    }

    entry = (CardDirEntry *)((u8 *)__CARDGetDirBlock((void *)card) + (fileNo << 6));
    result = fn_8021BB98((void *)card, entry);
    if (result < 0) {
        return __CARDPutControlBlock((void *)card, result);
    }

    entry->unk7 = status[0x2E];
    entry->unk2C = *(s32 *)(status + 0x30);
    entry->unk30 = *(u16 *)(status + 0x34);
    entry->unk32 = *(u16 *)(status + 0x36);
    entry->unk3C = *(s32 *)(status + 0x38);
    fn_8021CE0C(entry, stat);

    if ((u32)entry->unk2C + 0x10000U == 0xFFFFU) {
        entry->unk32 = (entry->unk32 & ~3U) | 1U;
    }

    ticksPerSecond = *(u32 *)0x800000F8 >> 2;
    entry->unk28 = (s32)(OSGetTime() / ticksPerSecond);

    result = __CARDUpdateDir(chan, callback);
    if (result < 0) {
        __CARDPutControlBlock((void *)card, result);
    }
    return result;

#pragma use_lmw_stmw reset
#pragma dont_inline reset
}

s32 fn_8021D28C(s32 chan, s32 fileNo, void *stat) {
 s32 fn_80217C64(s32);
 void fn_80216998(s32,s32);
 s32 result = fn_8021D118(chan,fileNo,stat,(s32)fn_80216998);
 if(result < 0) return result;
 return fn_80217C64(chan);
}

#pragma inline_depth(0)
s32 fn_8021D2D4(s32 chan, s32 index, void *dst) {
    s32 fn_80217B18(s32, s32 *);
    s32 __CARDPutControlBlock(void *, s32);
    s32 __CARDGetDirBlock(void *);
    s32 fn_8021BCCC(void *, u8 *);
    void *memcpy(void *, const void *, u32);
    s32 card;
    s32 result;
    u8 *entry;

    if (index < 0 || index >= 0x7F) {
        return -0x80;
    }
    result = fn_80217B18(chan, &card);
    if (result < 0) {
        return result;
    }
    entry = (u8 *)__CARDGetDirBlock((void *)card) + (index << 6);
    result = fn_8021BCCC((void *)card, entry);
    if (result >= 0) {
        memcpy(dst, entry, 0x40);
    }
    return __CARDPutControlBlock((void *)card, result);
}
#pragma inline_depth(8)
s32 fn_8021D378(s32 arg0, s32 arg1, CardDirEntry *arg2, s32 arg3) {
    s32 fn_80217B18(s32, s32 *);
    s32 __CARDPutControlBlock(void *, s32);
    u8 *__CARDGetDirBlock(s32);
    s32 __CARDUpdateDir(s32, s32);
    s32 fn_8021BB98(s32, CardDirEntry *);
    s32 fn_80231944(void *, void *, u32);
    void *memcpy(void *, const void *, u32);
    void *memset(void *, int, u32);
    s32 i;
    s32 sp18;
    s32 ret;
    u8 *base;
    CardDirEntry *slot;
    u8 *fileName;

    if (arg1 < 0 || arg1 >= 0x7F || arg2->unk8[0] == 0xFF || arg2->unk8[0] == 0) {
        return -0x80;
    }
    ret = fn_80217B18(arg0, &sp18);
    if (ret < 0) {
        return ret;
    }
    base = __CARDGetDirBlock(sp18);
    slot = (CardDirEntry *)(base + (arg1 << 6));
    ret = fn_8021BB98(sp18, slot);
    if (ret < 0) {
        return __CARDPutControlBlock((void *)sp18, ret);
    }
    for (fileName = arg2->unk8; fileName < arg2->unk8 + 0x20; fileName++) {
        if (*fileName == 0) {
            while (++fileName < (u8 *)&arg2->unk28) {
                *fileName = 0;
            }
            break;
        }
    }
    if (arg2->unk34 & 0x20) {
        memset(arg2->unk0, 0, 4);
        memset(arg2->unk4, 0, 2);
    }
    if (arg2->unk34 & 0x40) {
        memset(arg2->unk0, 0, 4);
    }
    if (fn_80231944(slot->unk8, arg2->unk8, 0x20) != 0 ||
        fn_80231944(slot->unk0, arg2->unk0, 4) != 0 ||
        fn_80231944(slot->unk4, arg2->unk4, 2) != 0) {
        for (i = 0; i < 0x7F; i++, base += 0x40) {
            if (i != arg1 && base[0] != 0xFF) {
                if (fn_80231944(base, arg2->unk0, 4) == 0 &&
                    fn_80231944(base + 4, arg2->unk4, 2) == 0 &&
                    fn_80231944(base + 8, arg2->unk8, 0x20) == 0) {
                    return __CARDPutControlBlock((void *)sp18, -7);
                }
            }
        }
        memcpy(slot->unk8, arg2->unk8, 0x20);
        memcpy(slot->unk0, arg2->unk0, 4);
        memcpy(slot->unk4, arg2->unk4, 2);
    }
    slot->unk28 = arg2->unk28;
    slot->unk7 = arg2->unk7;
    slot->unk2C = arg2->unk2C;
    slot->unk30 = arg2->unk30;
    slot->unk32 = arg2->unk32;
    slot->unk3C = arg2->unk3C;
    slot->unk34 = arg2->unk34;
    slot->unk35 = arg2->unk35;
    ret = __CARDUpdateDir(arg0, arg3);
    if (ret < 0) {
        __CARDPutControlBlock((void *)sp18, ret);
    }
    return ret;
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset
