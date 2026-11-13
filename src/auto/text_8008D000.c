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

extern void* lbl_80367488;
extern s32 lbl_803693C0;
extern s32 lbl_803693C4;
extern f64 lbl_803693C8;
extern f32 lbl_803693D4;
extern f32 lbl_803693D8;
extern f32 lbl_803693E4;

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
/* Draw a unit-ref inventory row with sell price (half value, or dashes if unpriced). */
void UnitRef_DrawSell(void *ref, u8 enabled, s32 x, s32 y) {
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Text_Draw(s16, s16, u8, void *, ...);
    s16 Text_MeasureWidth(void *, s32, f32);
    void *Item_GetFlagsPtr(void *);
    u32 UnitRef_GetValue(void *);
    s32 UnitRef_GetName(void *);
    void Ui_DrawIcon(void *, s32, s32, s32);
    void sprintf(void *, void *, s32, ...);
    void strcpy(void *, void *);
    extern u16 gUnitRefStrs[];
    extern u8 gUiIconDrawer[];
    extern f32 lbl_8036973C;
    char priceBuf[0x10];
    u8 nameColor;
    u8 var_r4;
    u8 var_r0;
    void *flagsPtr;
    u64 flags;
    s16 priceWidth;
    s32 var_color;
    u32 usesColor;
    u8 temp_r30;
    struct { unsigned b:8; } enabledBit;
    s32 ext;

    if (*(void **)ref != NULL) {
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        flagsPtr = Item_GetFlagsPtr(ref);
        flags = *(u64 *)flagsPtr;
        if (flags & (0x200ULL << 32)) {
            strcpy(priceBuf, (u8 *)gUnitRefStrs + 0x26);
        } else {
            sprintf(priceBuf, (u8 *)gUnitRefStrs + 0x2F, (s32)((UnitRef_GetValue(ref) >> 1) & 0x7FFF));
        }
        priceWidth = Text_MeasureWidth(priceBuf, -1, lbl_8036973C);
        Text_Draw((s16)(x + (0x10E - priceWidth)), (s16)y, enabled != 0, priceBuf);
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
