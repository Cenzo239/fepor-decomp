/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"

#include <dolphin/os.h>
#include "global.h"
#include "ef.h"



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

/* Lock/select the memory card EXI channel and arm the command timeout alarm. */

#pragma optimization_level 3

#pragma optimization_level reset

extern u16 __CARDBlock[];

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma optimization_level 3

#pragma optimization_level 4

#pragma optimization_level 3

#pragma optimization_level reset

s32 fn_802198C0(u16 *arg0, s32 arg1, u16 *arg2, u16 *arg3);
s32 fn_80205110(void *, s32);
void fn_80219734(s32, s32);
#pragma optimization_level 3

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma global_optimizer reset
#pragma opt_strength_reduction off
#pragma opt_common_subs reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma opt_strength_reduction on

#pragma opt_strength_reduction off

#pragma global_optimizer off

#pragma global_optimizer on

#pragma dont_inline on

#pragma use_lmw_stmw on

#pragma dont_inline reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

s64 OSGetTime(void);
s32 __CARDGetDirBlock(void *arg0);
s32 __CARDGetFatBlock(void *arg0);
s32 __CARDUpdateDir(s32 arg0, s32 arg1);
s32 __CARDPutControlBlock(void *arg0, s32 arg1);
int __CARDEraseSector(s32 chan, u32 addr, void *callback);
void __CARDEraseCallback(s32 chan, s32 result);
#pragma dont_inline on
/* Continue a CARD file write: on success update dir time or erase/write next FAT block. */

#pragma dont_inline reset

#pragma optimization_level 3

#pragma optimization_level reset

#pragma inline_depth(0)

#pragma inline_depth(8)

#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

s32 fn_8021D614(s32 chan, u32 *serial)
{
    s32 fn_80217B18(s32, s32 *);
    s32 __CARDPutControlBlock(void *, s32);
    s32 card;
    s32 result;
    u32 check1;
    u32 check0;
    u32 *face;
    int q;

    if (chan < 0 || chan >= 2) {
        return -0x80;
    }
    result = fn_80217B18(chan, &card);
    if (result < 0) {
        return result;
    }
    check1 = 0;
    check0 = 0;
    face = *(u32 **)(card + 0x80);
    check1 ^= face[1];
    q = (int)face + 8;
    check0 ^= face[0];
    check0 ^= face[2];
    check1 ^= ((u32 *)q)[1];
    q = (int)face + 16;
    check0 ^= face[4];
    check1 ^= ((u32 *)q)[1];
    q = (int)face + 24;
    check0 ^= face[6];
    check1 ^= ((u32 *)q)[1];
    serial[1] = check1;
    serial[0] = check0;
    return __CARDPutControlBlock((void *)card, 0);
}

#pragma dont_inline on
