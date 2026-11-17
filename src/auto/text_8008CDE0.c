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

#pragma use_lmw_stmw on
s32 fn_8008CE28(void *arg0, s32 arg1) {
    s32 GMaterial_GetCurrent(void);
    s32 GMaterial_GetNode(void);
    s32 GMaterial_AllocTevStage(void);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void GMaterial_SetCullMode(s32, s32);
    void fn_800690D4(s32, s32, void *);
    void fn_80069354(s32, s32, s32, s32, s32);
    void GMaterial_SetupColor(s32, s32, s32, void *);
    u8 *fn_8001BC18(s32);
    u32 OSGetTick(void);
    f32 fn_80059EB8(s32, s32, f32, f32);
    extern u32 lbl_80369730;
    extern f32 lbl_80369734;
    extern f32 lbl_80369738;

    s32 mat;
    s32 node;
    s32 owner;
    s32 tev;
    u8 *src;
    u8 color[4];
    u32 saved;
    s32 pulse;

    mat = GMaterial_GetCurrent();
    node = GMaterial_GetNode();
    owner = *(s32 *)((u8 *)mat + 0x90);

    if (*(u8 *)((u8 *)arg0 + 6) != 0) {
        fn_80069354(mat, 0, node, *(s32 *)((u8 *)arg0 + 0x14), arg1);
    } else {
        tev = GMaterial_AllocTevStage();
        GXSetTevOrder(tev, 0xFF, 0xFF, 4);
        GXSetNumTexGens(tev, 4);
    }

    GMaterial_SetCullMode(mat, node);
    fn_800690D4(mat, node, arg0);

    *(u32 *)color = lbl_80369730;
    if ((u32)owner != 0) {
        src = fn_8001BC18(owner);
        color[0] = src[0];
        color[1] = src[1];
        color[2] = src[2];
        color[3] = src[3];
    } else {
        pulse = (s32)fn_80059EB8(0x3E8, OSGetTick() / ((*(u32 *)0x800000F8 >> 2) / 1000), lbl_80369734, lbl_80369738);
        color[1] = 0x80;
        color[2] = 0x80;
        color[0] = pulse;
    }

    saved = *(u32 *)((u8 *)mat + 8);
    *(u8 *)((u8 *)mat + 8) = color[0];
    *(u8 *)((u8 *)mat + 9) = color[1];
    *(u8 *)((u8 *)mat + 0xA) = color[2];
    GMaterial_SetupColor(mat, 0, node, arg0);
    *(u8 *)((u8 *)mat + 8) = ((u8 *)&saved)[0];
    *(u8 *)((u8 *)mat + 9) = ((u8 *)&saved)[1];
    *(u8 *)((u8 *)mat + 0xA) = ((u8 *)&saved)[2];
    *(u8 *)((u8 *)mat + 0xB) = ((u8 *)&saved)[3];
    return 1;
}
#pragma use_lmw_stmw reset

void fn_8008CFB4(void **arg0, s32 arg1, s32 arg2) {
    void Ui_DrawIcon(void *, s32, s32, s32);
    extern u8 gUiIconDrawer[];
    void *p;

    p = *arg0;
    if (p != NULL) {
        Ui_DrawIcon(gUiIconDrawer, arg1, arg2, (u8)(p != NULL ? *((u8 *)p + 0x15) : 0) + 0x61);
    }
}

