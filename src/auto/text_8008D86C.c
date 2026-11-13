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

void fn_8008D86C(u8 *arg0) {
    extern u8 gMsgTipSlots;
    *(&gMsgTipSlots + (s8)arg0[0x3d]) = 0;
}

s32 fn_8008D988(void) {
    extern u16 gBattleHelpStrings[];
    fn_8000BD98((u8 *)gBattleHelpStrings + 0xE3);
    return 0;
}

#pragma use_lmw_stmw on
s32 fn_8008D9B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    extern u8 lbl_80289A8C[];
    void *obj;

    if (Process_Find(lbl_80289A8C) != NULL) {
        obj = Process_Find(lbl_80289A8C);
    } else {
        obj = Process_Create(lbl_80289A8C, 3);
    }
    *(s32 *)((u8 *)obj + 0x34) = arg0;
    *(s32 *)((u8 *)obj + 0x38) = arg1;
    *(s32 *)((u8 *)obj + 0x3C) = arg2;
    *(s32 *)((u8 *)obj + 0x40) = arg3;
    *(s32 *)((u8 *)obj + 0x44) = arg4;
    *(s32 *)((u8 *)obj + 0x48) = arg5;
    *(u8 *)((u8 *)obj + 0x4C) = arg6 != 0;
    return 0;
}
#pragma use_lmw_stmw reset

