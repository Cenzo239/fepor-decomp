/* Functions from 0x8007C5E4 to 0x8009F0BC, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
extern void* lbl_803674E8;
extern f32 lbl_803696C8;

extern s32 gSaveDataBase;
extern void *lbl_8026CC58;
extern void *lbl_80289998;
extern f32 gScreenOrigin;
extern f32 lbl_803696A8;
extern f32 lbl_803696AC;

extern void* gActiveFace;
extern s32 gFaceDbgMouthStartStr;
extern s32 gFaceDbgMouthEndStr;
extern f64 lbl_803693C8;
extern f32 lbl_803693D4;
extern f32 lbl_803693D8;
extern f32 gFaceDbgTextScale;

extern u8 gBattleState[1400];

extern u16 *lbl_803674E0;

#pragma inline

extern f32 lbl_8036A118;
extern f32 lbl_8036A120;
extern f32 lbl_8036A130;
extern f32 gTextScale2;

extern f32 lbl_80369768;
extern u16 lbl_80289A60[];

extern u8 lbl_80289B00[16];

extern void* fn_800980D4(s32 arg0);
extern void fn_8017E394(void* arg0, void* arg1, void* arg2, s32 arg3);

extern u8 lbl_80289EB8[16];

extern f32 lbl_803697E0;
extern f32 lbl_803697E4;

#pragma scheduling reset

s32 fn_800958C4(s32 arg0) {
    s32 Event_GetCmdFlagRes(s32);
    if (arg0 & 0x80) {
        return Event_GetCmdFlagRes(0x80);
    }
    if (arg0 & 0x20) {
        return Event_GetCmdFlagRes(0x20);
    }
    if (arg0 & 8) {
        return Event_GetCmdFlagRes(8);
    }
    if (arg0 & 0x10) {
        return Event_GetCmdFlagRes(0x10);
    }
    return 0;
}

void *fn_80095934(s32 *arg0, s32 arg1, s32 arg2) {
extern void **lbl_80367500;
extern u8 gBattle[];
extern char gEventCmdStrings[];
void *Item_GetFlagsPtr(void *);
void *fn_80055204(s32, s32);
void *item;
u8 *unit;
s32 kind;
void *result;

unit = *lbl_80367500;
if (!unit)
    item = 0;
else {
    item = unit + 0x28C;
    if (!*(u32 *)item)
        item = 0;
}
if (item) {
    if (*(u64 *)Item_GetFlagsPtr(item) & 2ULL) {
        kind = 1;
        goto done;
    }
    if (*(u64 *)Item_GetFlagsPtr(item) & 0x800000000ULL) {
        kind = 2;
        goto done;
    }
    if (*(u64 *)Item_GetFlagsPtr(item) & 0x8000000000ULL) {
        kind = 1;
        goto done;
    }
    if (*(s32 *)(gBattle + 0xCA8) > 1) {
        if (*(u64 *)Item_GetFlagsPtr(item) & 0x40ULL) {
            kind = 1;
            goto done;
        }
        if (*(u64 *)Item_GetFlagsPtr(item) & 0x4000000000ULL) {
            kind = 3;
            goto done;
        }
    }
}
kind = 0;
done:
if (kind == 1)
    return 0;
if (arg1 == 0x52)
    return 0;
if (arg2 & 0x01000000)
    return gEventCmdStrings + 0xDB;
if (arg2 & 0x20000)
    return gEventCmdStrings + 0xED;
if (arg2 & 2)
    return gEventCmdStrings + 0xFA;
if (arg0 != 0) {
    result = fn_80055204(*arg0, 1);
    if (result != 0)
        return result;
}
if (arg2 & 0x40)
    return gEventCmdStrings + 0x105;
if (arg1 == 0x51)
    return gEventCmdStrings + 0x114;
result = 0;
if (arg1 == 0x50)
    result = gEventCmdStrings + 0xFA;
return result;
}

