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

typedef struct Vec4 {
    f32 v[4];
} Vec4;

extern Vec4 lbl_8026CD50;

#pragma scheduling reset

#pragma use_lmw_stmw on
/* Draw an item/unit-ref row: scaled price (dimmed if unaffordable), name, uses, and icon. */
void UnitRef_DrawScaled(void *ref, u8 enabled, s32 x, s32 y, f32 priceScale) {
    void Ui_DrawIcon(void *, s32, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Text_Draw(s16, s16, u8, void *, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    void *Item_GetFlagsPtr(void *);
    u32 UnitRef_GetValue(void *);
    s32 UnitRef_GetName(void *);
    void sprintf(void *, void *, s32, ...);
    extern u16 gUnitRefStrs[];
    extern u8 gUiIconDrawer[];
    extern f32 lbl_8036973C;
    extern f64 lbl_80369740;
    char priceBuf[0x10];
    s16 priceWidth;
    u8 nameColor;
    u32 usesColor;
    s32 var_color;
    u8 var_r4;
    u8 var_r0;
    void *temp_r3;
    s32 gold;
    u8 canAfford;
    struct { unsigned b:8; } enabledBit;
    u64 flags;
    s32 price;

    if (*(void **)ref != NULL) {
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        price = (s32)(priceScale * (f32)(u16)UnitRef_GetValue(ref));
        sprintf(priceBuf, (u8 *)gUnitRefStrs + 0x2F, price);
        priceWidth = Text_MeasureWidth(priceBuf, -1, lbl_8036973C);
        canAfford = enabled != 0;
        gold = *(s32 *)(gBattleState + 0x18);
        price = (s32)(priceScale * (f32)(u16)UnitRef_GetValue(ref));
        if (gold < price) {
            canAfford = 0;
        }
        Text_Draw((s16)(x + (0x10E - priceWidth)), (s16)y, canAfford, priceBuf);
        {
            s32 cond = enabled;
            enabledBit.b = cond != 0;
            var_color = 0;
            if (cond != 0) {
                var_color = 4;
            }
        }
        usesColor = (u8)var_color;
        nameColor = enabledBit.b;
        if (enabledBit.b == 1 && (*(u8 *)((u8 *)ref + 5) & 0x3F)) {
            nameColor = 4;
        }
        if ((*(u8 *)((u8 *)ref + 5) >> 6) & 1) {
            nameColor = 3;
        }
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        Text_Draw((s16)(x + 0x18), (s16)y, nameColor, (u8 *)gUnitRefStrs + 0x21, UnitRef_GetName(ref));
        flags = *(u64 *)Item_GetFlagsPtr(ref);
        if ((flags & ((0x100ULL << 32) | 0x10)) == 0) {
            Text_Draw((s16)(x + 0xA2), (s16)y, enabledBit.b, (u8 *)gUnitRefStrs + 0x34, *(u8 *)((u8 *)ref + 4));
            Text_Draw((s16)(x + 0xBC), (s16)y, usesColor, (u8 *)gUnitRefStrs + 0x3A, (u8)(*(void **)ref != NULL ? *((u8 *)*(void **)ref + 0x18) : 0));
        }
        Ui_DrawIcon(gUiIconDrawer, x, y, (u8)(*(void **)ref != NULL ? *((u8 *)*(void **)ref + 0x15) : 0) + 0x61);
    }
}
/* Draw a unit inventory slot: badge, name, uses/max, and item icon. */
void UnitRef_Draw(void *ref, u8 selected, s32 x, s32 y) {
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Text_Draw(s16, s16, u8, void *, ...);
    void *Item_GetFlagsPtr(void *);
    s32 UnitRef_GetName(void *);
    void Ui_DrawIcon(void *, s32, s32, s32);
    extern u16 gUnitRefStrs[];
    extern u8 gUiIconDrawer[];
    struct { unsigned b : 8; } selBit;
    u8 nameColor;
    u32 usesColor;
    s32 baseColor;
    u64 flags;

    if (*(void **)ref != NULL) {
        if ((*(u8 *)((u8 *)ref + 5) >> 7) & 1) {
            Ui_DrawIcon(gUiIconDrawer, x + 9, y + 9, 1);
        }
        {
            s32 cond = selected;
            selBit.b = cond != 0;
            baseColor = 0;
            if (cond != 0) {
                baseColor = 4;
            }
        }
        usesColor = (u8)baseColor;
        nameColor = selBit.b;
        if (selBit.b == 1 && (*(u8 *)((u8 *)ref + 5) & 0x3F)) {
            nameColor = 4;
        }
        if ((*(u8 *)((u8 *)ref + 5) >> 6) & 1) {
            nameColor = 3;
        }
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        Text_Draw((s16)(x + 0x18), (s16)y, nameColor, (u8 *)gUnitRefStrs + 0x21, UnitRef_GetName(ref));
        flags = *(u64 *)Item_GetFlagsPtr(ref);
        if ((flags & ((0x100ULL << 32) | 0x10)) == 0) {
            Text_Draw((s16)(x + 0xA2), (s16)y, selBit.b, (u8 *)gUnitRefStrs + 0x34, *(u8 *)((u8 *)ref + 4));
            Text_Draw((s16)(x + 0xBC), (s16)y, usesColor, (u8 *)gUnitRefStrs + 0x3A, (u8)(*(void **)ref != NULL ? *((u8 *)*(void **)ref + 0x18) : 0));
        }
        Ui_DrawIcon(gUiIconDrawer, x, y, (u8)(*(void **)ref != NULL ? *((u8 *)*(void **)ref + 0x15) : 0) + 0x61);
    }
}
void MsgTip_Create(void *arg0) {
    M2C_UNK Process_Create(void *, s32);
    M2C_UNK Msg_Expand(void *);
    M2C_UNK fn_8023440C(void *, s32, s32);
    s32 Text_MeasureWidth(void *, s32, f32);
    M2C_UNK Process_Unlink(void *);
    extern u8 lbl_80289AB8[];
    extern f32 lbl_80369754;
    extern u8 gMsgTipSlots[4];
    extern f32 lbl_80369758;
    u8 *temp_r31;
    Vec4 sp8;

    temp_r31 = (u8 *)Process_Create(lbl_80289AB8, 3);
    fn_8023440C(temp_r31 + 0x3E, Msg_Expand(arg0), 0x30);
    *(s16 *)(temp_r31 + 0x38) = Text_MeasureWidth(temp_r31 + 0x3E, -1, lbl_80369754) + 0x60;
    sp8 = lbl_8026CD50;
    M2C_FIELD(temp_r31, s8 *, 0x3D) = 0;
    while (M2C_FIELD(temp_r31, s8 *, 0x3D) < 4) {
        s32 index = M2C_FIELD(temp_r31, s8 *, 0x3D);
        if (gMsgTipSlots[index] == 0) {
            gMsgTipSlots[index] = 1;
            break;
        }
        M2C_FIELD(temp_r31, s8 *, 0x3D)++;
    }
    if (M2C_FIELD(temp_r31, s8 *, 0x3D) == 4) {
        Process_Unlink(temp_r31);
    } else {
        *(f32 *)(temp_r31 + 0x30) = lbl_80369758;
        *(f32 *)(temp_r31 + 0x34) = sp8.v[M2C_FIELD(temp_r31, s8 *, 0x3D)];
    }
}

void fn_8008D7EC(void *arg0) {
    M2C_UNK Process_ClearFunc(void *);
    M2C_FIELD(arg0, u8 *, 0x3A) = (u8) (M2C_FIELD(arg0, u8 *, 0x3A) + M2C_FIELD(arg0, u8 *, 0x3C));
    if ((s8) M2C_FIELD(arg0, u8 *, 0x3A) == (s8) M2C_FIELD(arg0, u8 *, 0x3B)) {
        Process_ClearFunc(arg0);
    }
}
