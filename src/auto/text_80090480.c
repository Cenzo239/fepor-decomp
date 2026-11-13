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

#pragma use_lmw_stmw on

#pragma use_lmw_stmw off
#pragma global_optimizer off
#pragma opt_strength_reduction off

void fn_80090480(s32 arg0, s32 arg1, void* arg2, s32 arg3) {
    s32 sp14;
    s32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;
    
    s32 var_r3 = arg0;
    s32 var_r4 = arg1;
    void* var_r5 = arg2;
    s32 var_r6 = arg3;

    if (arg0 < 0) {
        var_r3 = -var_r3;
    }
    
    if (arg1 < 0) {
        var_r4 = -var_r4;
    }
    
    sp14 = arg1;
    sp18 = arg0; 
    
    sp1C = lbl_8036A118 * var_r3;
    sp20 = lbl_8036A120 * var_r4;
    sp24 = lbl_8036A130 * var_r3;
    sp28 = gTextScale2 * var_r4;
    
    if (arg3 == 0) {
        sp30 = sp1C + sp20 + sp24 + sp28;
        sp34 = sp1C - sp20 - sp24 - sp28;
    } else {
        sp30 = sp1C + sp20 + sp24 - sp28;
        sp34 = sp1C - sp20 - sp24 + sp28;
    }
    
    *(f32*)var_r5 = sp30;
    *((f32*)var_r5 + 1) = sp34;
}

void fn_800907B8(void *arg0) {
    void fn_8008BA80(void *, s32, s32, u8);
    void fn_8008BBF8(s32, s32, s32, s32, u8, s32);
    void fn_8008CD64(f32);
    void UnitRef_Draw(s32, s32, s32, s32);
    s32 Unit_GetHeldItemSlot(void *, s32);
    s32 fn_8001C0C8(void);
    extern f32 lbl_80369768;

    s32 offset;
    s32 temp;
    s32 i;
    s32 id;

    fn_8008BA80(arg0, 0, 0, 1);
    fn_8008BBF8(0, 0x20, 0x108, 0x88, *(u8 *)(*(u8 **)((u8 *)arg0 + 0x190) + 8), 0x9A);
    offset = 0x2C;
    fn_8008CD64(lbl_80369768);
    i = 0;
    do {
        temp = Unit_GetHeldItemSlot(arg0, i);
        id = fn_8001C0C8();
        UnitRef_Draw(temp, id, 0x1C, offset);
        i += 1;
        offset += 0x1C;
    } while (i < 4);
}

void fn_80090874(void *arg0, s32 arg1) {
    s32 var_r29;
    u8 *var_r28;
    void *var_r27;
    u8 *var_r30;
    s32 var_r31;
    
    fn_8008BA80(0, 0, 1);
    fn_8008BBF8(0, 0x20, 0x108, 0x110, *(u8*)((u8*)arg0 + 0x190 + 0x8), 0x9A);
    
    var_r28 = (u8*)arg0 + 0x194;
    var_r29 = 0;
    var_r30 = (u8*)arg0 + 0x1F0;
    do {
        if (*(u32*)Unit_GetItemSlot(arg0, var_r29) != 0) {
            *(u8*)var_r30 = fn_8003DAC4(arg1);
        }
        var_r29 += 1;
        var_r30 += 1;
    } while (var_r29 < 8);
    
    fn_8008CD64(lbl_80369768);
    
    var_r27 = arg0;
    var_r31 = 0;
    do {
        Unit_GetHeldItemSlot(var_r27, var_r31);
        UnitRef_Draw(*(u8*)var_r28, 0x1C, 0x2C, var_r31);
        var_r31 += 1;
        var_r28 += 1;
    } while (var_r31 < 4);
    
    var_r27 = arg0;
    var_r31 = 0;
    do {
        UnitRef_Draw(*(u8*)((u8*)var_r27 + 0x1EC), *(u8*)((u8*)var_r27 + 0x4), 0x1C, var_r31);
        var_r31 += 1;
        var_r27 = (void*)((u8*)var_r27 + 0x8);
    } while (var_r31 < 4);
}

void fn_80090990(void *arg0) {
    u8 sp8;
    s32 var_r29;
    u8 *var_r28;
    void *var_r27;
    u8 *var_r30;
    s32 var_r31;

    fn_8008BA80(0, 0, 1);
    fn_8008BBF8(0, 0x20, 0x108, 0x110, ((u8*)arg0 + 0x190)[8], 0x9A);
    
    var_r28 = &sp8;
    var_r29 = 0;
    var_r30 = var_r28;
    
    do {
        if (*(u32*)Unit_GetItemSlot(arg0, var_r29) != 0) {
            *var_r30 = fn_80093DA8(arg0);
        }
        var_r29 += 1;
        var_r30 += 1;
    } while (var_r29 < 8);
    
    fn_8008CD64(lbl_80369768);
    
    var_r27 = arg0;
    var_r31 = 0;
    
    do {
        Unit_GetHeldItemSlot(var_r27, var_r31);
        UnitRef_Draw(*var_r28, 0x1C, 0x2C + (var_r31 * 0x1C));
        var_r31 += 1;
        var_r28 += 1;
    } while (var_r31 < 4);
    
    var_r27 = arg0;
    var_r31 = 0;
    
    do {
        UnitRef_Draw(((u8*)var_r27 + 0x1EC)[0], ((u8*)arg0 + 4)[0], 0x1C, 0x94 + (var_r31 * 0x1C));
        var_r31 += 1;
        var_r27 = (u8*)var_r27 + 8;
        var_r28 += 1;
    } while (var_r31 < 4);
}

/* Draw a fixed-size unit-info panel fill tinted by allegiance, plus white translucent edge strips. */
void UnitInfo_DrawPanel(s32 x, s32 y, s32 allegiance)
{
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SetColor(u8, u8, u8, u8);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    extern s32 gUnitInfoPanelColorPlayer;
    extern s32 gUnitInfoPanelColorOther;
    extern s32 gUnitInfoPanelColorPartner;
    extern f32 gZeroF;
    extern f32 gUnitInfoPanelW;
    extern f32 gUnitInfoPanelH;
    extern f32 gUnitInfoPanelOuterW;
    extern f32 gUnitInfoPanelOuterH;
    u8 rgbaBytes[4];
    s32 colorPlayer;
    s32 colorOther;
    s32 colorPartner;
    s32 colorPacked;

    switch (allegiance) {
    case 0:
        colorPlayer = gUnitInfoPanelColorPlayer;
        rgbaBytes[0] = *(u8 *)&colorPlayer;
        rgbaBytes[1] = *(u8 *)((u8 *)&colorPlayer + 1);
        rgbaBytes[2] = *(u8 *)((u8 *)&colorPlayer + 2);
        rgbaBytes[3] = *(u8 *)((u8 *)&colorPlayer + 3);
        break;
    case 2:
        colorOther = gUnitInfoPanelColorOther;
        rgbaBytes[0] = *(u8 *)&colorOther;
        rgbaBytes[1] = *(u8 *)((u8 *)&colorOther + 1);
        rgbaBytes[2] = *(u8 *)((u8 *)&colorOther + 2);
        rgbaBytes[3] = *(u8 *)((u8 *)&colorOther + 3);
        break;
    case 3:
        colorPartner = gUnitInfoPanelColorPartner;
        rgbaBytes[0] = *(u8 *)&colorPartner;
        rgbaBytes[1] = *(u8 *)((u8 *)&colorPartner + 1);
        rgbaBytes[2] = *(u8 *)((u8 *)&colorPartner + 2);
        rgbaBytes[3] = *(u8 *)((u8 *)&colorPartner + 3);
        break;
    }
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)x, (f32)y, gUnitInfoPanelW, gUnitInfoPanelH);
    colorPacked = *(s32 *)rgbaBytes;
    Prim2D_SetColorPacked(&colorPacked);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetRect((f32)(x - 3), (f32)y, gUnitInfoPanelOuterW, gZeroF);
    Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0x4D);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetRect((f32)(x - 3), (f32)(y + 0x62), gUnitInfoPanelOuterW, gZeroF);
    Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0x4D);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetRect((f32)x, (f32)(y - 3), gZeroF, gUnitInfoPanelOuterH);
    Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0x4D);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetRect((f32)(x + 0xD0), (f32)(y - 3), gZeroF, gUnitInfoPanelOuterH);
    Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0x4D);
    Prim2D_EndPrim();
}

void StatBonus_ShowHelp(void *arg0, s32 arg1) {
    s32 Msg_Expand(void *);
    void Ui_OpenHelpPopup(s32, void *, s32, s8);
    extern u8 gBattleHelpStrings[];
    void *msg;

    if ((s8)*(u8 *)((u8 *)arg0 + 0x1F) != 0) {
        msg = gBattleHelpStrings + 0x1BD;
    } else if ((s8)*(u8 *)((u8 *)arg0 + 0x20) != 0) {
        msg = gBattleHelpStrings + 0x1C4;
    } else if ((s8)*(u8 *)((u8 *)arg0 + 0x21) != 0) {
        msg = gBattleHelpStrings + 0x1CC;
    } else if ((s8)*(u8 *)((u8 *)arg0 + 0x22) != 0) {
        msg = gBattleHelpStrings + 0x1D5;
    } else if ((s8)*(u8 *)((u8 *)arg0 + 0x23) != 0) {
        msg = gBattleHelpStrings + 0x1DE;
    } else if ((s8)*(u8 *)((u8 *)arg0 + 0x24) != 0) {
        msg = gBattleHelpStrings + 0x1E8;
    } else if ((s8)*(u8 *)((u8 *)arg0 + 0x25) != 0) {
        msg = gBattleHelpStrings + 0x1F1;
    } else if ((s8)*(u8 *)((u8 *)arg0 + 0x26) != 0) {
        msg = gBattleHelpStrings + 0x1F9;
    } else if ((s8)*(u8 *)((u8 *)arg0 + 0x28) != 0) {
        msg = gBattleHelpStrings + 0x202;
    } else if ((s8)*(u8 *)((u8 *)arg0 + 0x27) != 0) {
        msg = gBattleHelpStrings + 0x20C;
    } else {
        msg = arg0;
    }
    Ui_OpenHelpPopup(Msg_Expand(msg), gBattleHelpStrings + 0x1AC, arg1, 1);
}

void fn_800913D4(void **arg0, s32 arg1, s32 arg2) {
    void fn_8000D864(s32, char *);
    s32 fn_8000D910(char *, s32);
    s32 fn_8001D070(void **, s32);
    s32 UnitRef_GetName(void **);
    s32 Status_Test(s32, s32);
    void Ui_OpenHelpPopup(s32, s32, s32, s32);
    s32 fn_80231E74(char *, s32, char *, ...);
    extern u8 gBattleHelpStrings[];

    char sp8[0x80];
    s32 temp;
    u8 kind;
    void *p;

    p = *arg0;
    if (p != 0) {
        kind = *(u8 *)((char *)p + 0x15);
    } else {
        kind = 0;
    }
    fn_80231E74(sp8, 0x80, (char *)gBattleHelpStrings + 0x214, (temp = UnitRef_GetName(arg0), fn_8001D070(arg0, 0)), temp, kind + 0x60);
    fn_8000D864(0, sp8);
    Ui_OpenHelpPopup(fn_8000D910((char *)gBattleHelpStrings + 0x21F, Status_Test(arg2 + 0x1BC, 1)), 0, arg1, 0);
}

void fn_8009149C(s32 arg0, s32 arg1) {
    extern u8 gBattleHelpStrings[];
    s32 fn_80231E74(char *, s32, char *, ...);
    void fn_8000D864(s32, char *);
    s32 Msg_Expand(void *);
    void Ui_OpenHelpPopup(s32, void *, s32, s32);
    char sp8[0x80];

    fn_80231E74(sp8, 0x80, (char *)gBattleHelpStrings + 0x228, arg0);
    fn_8000D864(0, sp8);
    Ui_OpenHelpPopup(Msg_Expand((char *)gBattleHelpStrings + 0x22B), gBattleHelpStrings + 0x1AC, arg1, 0);
}

void fn_80091518(void **arg0, s32 arg1, s32 arg2) {
    void fn_8000D864(s32, char *);
    s32 fn_8000D910(char *, s32, void *);
    s32 fn_8001D070(void **, s32);
    s32 UnitRef_GetName(void **);
    s32 Status_Test(s32, s32);
    void Ui_OpenHelpPopup(s32, void *, s32, s32);
    s32 fn_80231E74(char *, s32, char *, ...);
    extern u8 gBattleHelpStrings[];

    char sp8[0x80];
    s32 temp;
    u8 kind;
    void *p;
    void **self;
    s32 dst;
    s32 src;

    self = arg0;
    src = arg1;
    dst = arg2;
    temp = 0;
    p = *self;
    if (p != 0) {
        kind = *(u8 *)((char *)p + 0x15);
    } else {
        kind = 0;
    }
    temp = UnitRef_GetName(self);
    fn_80231E74(sp8, 0x80, (char *)gBattleHelpStrings + 0x214, fn_8001D070(self, 0), temp, kind + 0x60);
    fn_8000D864(0, sp8);
    Ui_OpenHelpPopup(fn_8000D910((char *)gBattleHelpStrings + 0x25A, Status_Test(dst + 0x1BC, 1), gBattleHelpStrings), gBattleHelpStrings + 0x23E, src, 0);
}

void fn_800915E8(void **arg0, s32 arg1, s32 arg2) {
    void fn_8000D864(s32, char *);
    s32 fn_8000D910(char *, s32, void *);
    s32 fn_8001D070(void **, s32);
    s32 UnitRef_GetName(void **);
    s32 Status_Test(s32, s32);
    void Ui_OpenHelpPopup(s32, void *, s32, s32);
    s32 fn_80231E74(char *, s32, char *, ...);
    extern u8 gBattleHelpStrings[];

    char sp8[0x80];
    s32 temp;
    u8 kind;
    void *p;

    p = *arg0;
    if (p != 0) {
        kind = *(u8 *)((char *)p + 0x15);
    } else {
        kind = 0;
    }
    temp = UnitRef_GetName(arg0);
    fn_80231E74(sp8, 0x80, (char *)gBattleHelpStrings + 0x214, fn_8001D070(arg0, 0), temp, kind + 0x60);
    fn_8000D864(0, sp8);
    Ui_OpenHelpPopup(fn_8000D910((char *)gBattleHelpStrings + 0x265, Status_Test(arg2 + 0x1BC, 1), gBattleHelpStrings), gBattleHelpStrings + 0x1AC, arg1, 0);
}

#pragma optimization_level 2
void fn_800916B8(void **arg0, s32 arg1, s32 arg2) {
    extern u8 gBattleHelpStrings[];
    s32 fn_80231E74(char *, s32, char *, ...);
    void fn_8000D864(s32, char *);
    s32 fn_8000D910(u8 *, s32);
    s32 fn_8001D070(void **, s32);
    s32 UnitRef_GetName(void **);
    s32 Status_Test(s32, s32);
    void Ui_OpenHelpPopup(s32, void *, s32, s32);
    char sp8[0x80];
    void *entry;
    s32 result;
    u8 type;

    entry = *arg0;
    if (entry != 0) {
        type = *((u8 *)entry + 0x15);
    } else {
        type = 0;
    }
    result = UnitRef_GetName(arg0);
    fn_80231E74(sp8, 0x80, (char *)gBattleHelpStrings + 0x214, fn_8001D070(arg0, 0), result, type + 0x60);
    fn_8000D864(0, sp8);
    Ui_OpenHelpPopup(fn_8000D910(gBattleHelpStrings + 0x270, Status_Test(arg2 + 0x1BC, 1)), gBattleHelpStrings + 0x23E, arg1, 0);
}
#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_80091788(void **arg0, s32 arg1, s32 arg2) {
    extern u8 gBattleHelpStrings[];
    s32 fn_80231E74(char *, s32, char *, ...);
    void fn_8000D864(s32, char *);
    s32 fn_8000D910(u8 *, s32);
    s32 fn_8001D070(void **, s32);
    s32 UnitRef_GetName(void **);
    s32 Status_Test(s32, s32);
    void Ui_OpenHelpPopup(s32, void *, s32, s32);
    char sp8[0x80];
    void *entry;
    s32 result;
    u8 type;

    entry = *arg0;
    if (entry != 0) {
        type = *((u8 *)entry + 0x15);
    } else {
        type = 0;
    }
    result = UnitRef_GetName(arg0);
    fn_80231E74(sp8, 0x80, (char *)gBattleHelpStrings + 0x214, fn_8001D070(arg0, 0), result, type + 0x60);
    fn_8000D864(0, sp8);
    Ui_OpenHelpPopup(fn_8000D910(gBattleHelpStrings + 0x27B, Status_Test(arg2 + 0x1BC, 1)), gBattleHelpStrings + 0x1AC, arg1, 0);
}
#pragma global_optimizer on
#pragma use_lmw_stmw off
