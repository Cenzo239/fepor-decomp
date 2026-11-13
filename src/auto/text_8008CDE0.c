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
extern s32 lbl_803693C4;
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

void fn_8008CDE0(void *arg0, s32 arg1) {
    s32 fn_80060638(void);
    void fn_800688D4(s32, void *, void *, s32);
    extern u16 gUnitRefStrs[];
    extern void fn_8008CE28(void);
    void *base;

    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 0x90) = arg1;
        base = gUnitRefStrs;
        fn_800688D4(fn_80060638(), (u8 *)base + 0x1D, fn_8008CE28, 0x4000);
    }
}

void fn_8008CFB4(void **arg0, s32 arg1, s32 arg2) {
    void Ui_DrawIcon(void *, s32, s32, s32);
    extern u8 gUiIconDrawer[];
    void *p;

    p = *arg0;
    if (p != NULL) {
        Ui_DrawIcon(gUiIconDrawer, arg1, arg2, (u8)(p != NULL ? *((u8 *)p + 0x15) : 0) + 0x61);
    }
}

