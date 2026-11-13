/* Functions from 0x800A9488 to 0x800AD1F4, found by decomp-toolkit. */
#include "common.h"
#pragma cplusplus on
extern "C" void fn_8001C76C(void *);
extern "C" void Item_Destroy(void *, s32);
struct ItemABA {
    u32 unk0, unk4;
    ItemABA() { fn_8001C76C(this); }
    ~ItemABA() { Item_Destroy(this, -1); }
};
#pragma cplusplus reset

#pragma use_lmw_stmw on

typedef struct {
    u8 flag : 1;
    u8 unk : 7;
} Entry9Bits;

static inline void *fn_800AA794_helper(void) {
    extern u8 gUnits[101760];
    extern u8 gBattleMap[151280];
    extern u8 gBattleState[1400];
    s8 sx = *(float *)&gBattleState[0x524];
    s8 sy = *(float *)&gBattleState[0x528];
    u8 id = gBattleMap[sx + (sy << 6) + 0xD];
    if (id != 0) {
        return &gUnits[(id - 1) * 0x280];
    }
    return NULL;
}

void *fn_800A9488(void) {
    extern u8 gOptionsStr[];
    return (void *)((u32)gOptionsStr + 0xCC);
}

s32 fn_800A9498(void) {
    return 0x100;
}

s32 fn_800A94A0(void) {
    return 0x48;
}

s32 fn_800A94A8(void) {
    return 0x18;
}

s32 fn_800A94B0(void) {
    return 0x140;
}

s32 fn_800A94B8(void) {
    return 0;
}

void *fn_800A9638(void) {
    extern u8 gOptionsStr[];
    return (void *)((u32)gOptionsStr + 0x110);
}

s32 fn_800A9648(void) {
    M2C_UNK fn_80006220(M2C_UNK);
    fn_80006220(5);
    return 5;
}

void *fn_800A9670(void) {
    extern u8 gOptionsStr[];
    return (void *)((u32)gOptionsStr + 0x110);
}

s32 fn_800A9680(void) {
    fn_80006220(5);
    return 5;
}

void *fn_800A96A8(void) {
    extern u8 gOptionsStr[];
    return (void *)((u32)gOptionsStr + 0x13F);
}

s32 fn_800A96B8(void) {
    return 0x40;
}

s32 fn_800A96C0(void) {
    return 0x110;
}

s32 fn_800A96C8(void) {
    return 0x140;
}

s32 fn_800A96D0(void) {
    return 0;
}

s32 Options_CycleDifficulty(void) {
    extern u8 gBattleState[];
    u8 x;

    x = gBattleState[0xA6] + 1;
    gBattleState[0xA6] = x;
    gBattleState[0xA6] = x % 4;
    return 0;
}

s32 fn_800A9710(void) {
    extern u8 gSystemSave[];
    gSystemSave[0x44] = 2;
    return 0;
}

#pragma cplusplus on
extern "C" M2C_UNK Prim2D_SetCornerColors(s32 *, s32 *, s32 *, s32 *, s32, s32, s32);
extern "C" M2C_UNK Prim2D_EmitQuad();
extern "C" M2C_UNK Prim2D_SetRect(f32, f32, f32, f32);
extern "C" M2C_UNK Prim2D_EndPrim();
extern "C" M2C_UNK Prim2D_AddPrim(M2C_UNK);
extern "C" M2C_UNK Prim2D_SetColorByte(M2C_UNK);
extern "C" M2C_UNK Prim2D_SetTransform(f32, f32, f32, f32);
extern "C" M2C_UNK Prim2D_SetTex(M2C_UNK, M2C_UNK);
extern "C" M2C_UNK Prim2D_PrepareTex();
extern "C" M2C_UNK Prim2D_Begin();
extern "C" void Text_Draw(s32, s32, s32, void *, ...);
extern "C" void Options_DrawDifficulty(M2C_UNK arg0, void *arg1) {
    /* Draw the options difficulty widget: panel quad, mode name from A6, and language. */
    struct Model {
        u8 pad[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual void v18() = 0;
        virtual void v19() = 0;
        virtual void v20() = 0;
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual f32 v25() = 0;
    };
    extern u8 gOptionsStr[];
    extern u8 gLanguageNamePtrs[];
    extern u8 gBattleState[];
    extern s32 lbl_80369B98;
    extern s32 lbl_80369B9C;
    extern s32 lbl_80369BA0;
    extern s32 lbl_80369BA4;
    extern f32 lbl_80369BA8;
    extern f32 gOptionsIdentityScale;
    extern f64 lbl_80369C00;
    extern f32 lbl_80369C1C;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    u8 lit;
    void *modeName;

    Prim2D_Begin();
    Prim2D_SetTransform((f32) M2C_FIELD(arg1, s16 *, 0x30), (f32) M2C_FIELD(arg1, s16 *, 0x32), M2C_FIELD(arg1, Model **, 0x3C)->v25(), gOptionsIdentityScale);
    Prim2D_SetTex(0, 0x12);
    lit = 0;
    if (((u8) M2C_FIELD(arg1, u8 *, 0x2D) == 0) && ((u8) M2C_FIELD(arg1, u8 *, 0x2E) == 0)) {
        lit = 1;
    }
    if (lit == 0) {
        Prim2D_SetColorByte(0x80);
    }
    Prim2D_PrepareTex();
    Prim2D_AddPrim(3);
    Prim2D_SetRect(lbl_80369BA8, lbl_80369C1C, (f32) M2C_FIELD(arg1, s16 *, 0x34), (f32) (M2C_FIELD(arg1, s16 *, 0x36) + 0x10));
    Prim2D_EmitQuad();
    sp8 = lbl_80369BA4;
    spC = lbl_80369BA0;
    sp10 = lbl_80369B9C;
    sp14 = lbl_80369B98;
    Prim2D_SetCornerColors(&sp14, &sp10, &spC, &sp8, lbl_80369B9C, lbl_80369BA0, lbl_80369BA4);
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    switch (gBattleState[0xA6]) {
    case 0:
        modeName = gOptionsStr + 0x150;
        break;
    case 1:
        modeName = gOptionsStr + 0x157;
        break;
    case 2:
        modeName = gOptionsStr + 0x15C;
        break;
    case 3:
        modeName = gOptionsStr + 0x163;
        break;
    default:
        modeName = NULL;
        break;
    }
    Text_Draw(0x160, 0, 1, gOptionsStr + 0x168, modeName);
    Text_Draw(0x148, 0x18, 1, gOptionsStr + 0x177, *(void **)(gLanguageNamePtrs + 4));
}
#pragma cplusplus reset

void *fn_800A9AFC(void) {
    extern char gOptionsStr[];
    return &gOptionsStr[0x19B];
}

s32 fn_800A9B0C(void) {
    M2C_UNK fn_800EB884();
    fn_800EB884();
    fn_80006220(3);
    return 5;
}

#pragma cplusplus on
extern "C" void Options_DrawTextItem(void *unused, void *parent, void *item) {
    /* Draw options-menu item text in black via Prim2D under the parent transform. */
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetText(void);
    void Prim2D_SetScale(f32);
    void Prim2D_EndPrim(void);
    struct Model {
        u8 pad[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual void v18() = 0;
        virtual void v19() = 0;
        virtual void v20() = 0;
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual f32 v25() = 0;
    };
    struct Drawer {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4(void *) = 0;
    };
    extern f32 gOptionsIdentityScale;
    extern f32 gOptionsZBias;
    extern f32 gOptionsTextScale;

    (void)unused;
    Prim2D_Begin();
    Prim2D_SetTransform((f32) M2C_FIELD(parent, s16 *, 0x30), (f32) M2C_FIELD(parent, s16 *, 0x32),
        M2C_FIELD(parent, Model **, 0x3C)->v25() - gOptionsZBias, gOptionsIdentityScale);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32) M2C_FIELD(item, s16 *, 0x30), (f32) M2C_FIELD(item, s16 *, 0x32));
    Prim2D_SetColor(0, 0, 0, 0xFF);
    M2C_FIELD(item, Drawer **, 0x34)->v4(item);
    Prim2D_SetText();
    Prim2D_SetScale(gOptionsTextScale);
    Prim2D_EndPrim();
}
#pragma cplusplus reset

void *fn_800A9C5C(void) {
    extern u16 gOptionsStr[];
    return (u8 *)gOptionsStr + 0x1b1;
}

s32 fn_800A9C6C(s32 unused, void *arg1) {
    void fn_801FFD7C(s32);
    fn_801FFD7C(*(s32 *)((char *)arg1 + 0x18));
    fn_80006220(3);
    return 5;
}

void *fn_800A9C9C(void) {
    extern u16 gOptionsStr[];
    return (u8 *)gOptionsStr + 0x1be;
}

s32 fn_800A9CAC(void) {
    M2C_UNK fn_800EBACC(M2C_UNK, M2C_UNK);
    fn_800EBACC(0, 0);
    fn_80006220(3);
    return 5;
}

void *fn_800A9CE0(void) {
    extern u16 gOptionsStr[];
    return (u8 *)gOptionsStr + 0x1d2;
}

s32 fn_800A9CF0(void) {
    M2C_UNK fn_800EBD78(M2C_UNK, M2C_UNK);
    fn_800EBD78(0, 0);
    fn_80006220(3);
    return 5;
}

void *fn_800A9D24(void) {
    extern u16 gOptionsStr[];
    return (u8 *)gOptionsStr + 0x1e6;
}

s32 fn_800A9D34(void) {
    extern void *gPadInput;
    extern u8 lbl_80367701;
    extern s8 lbl_80367702;
    fn_80006220(4);
    if ((u32) (M2C_FIELD(gPadInput, s32 *, 4) & 0x60) == 0x60) {
        lbl_80367701 ^= 1;
    }
    if (M2C_FIELD(gPadInput, s32 *, 4) & 0x10) {
        lbl_80367702 = 1;
    }
    return 5;
}

void *fn_800A9D90(void) {
    extern u16 gOptionsStr[];
    return (u8 *)gOptionsStr + 0x1f7;
}

s32 fn_800A9DA0(void) {
    fn_80006220(2);
    return 5;
}

void *fn_800A9DC8(void) {
    extern u16 gOptionsStr[];
    return &gOptionsStr[0x105];
}

s32 fn_800A9DD8(void) {
    fn_80006220(5);
    return 5;
}

void *fn_800A9E00(void) {
    extern u8 gOptionsStr[];
    return (void *)((u32)gOptionsStr + 0xCC);
}

s32 fn_800A9E10(void *arg0) {
    u32 fn_80019ED0(s32);
    extern void *gPadInput;
    u32 flags;
    s32 delta;

    flags = *(u32 *)((u8 *)gPadInput + 0x10);
    if (flags & 0x01000001) {
        delta = -1;
    }
    if (flags & 0x02000002) {
        delta = 1;
    }
    if (fn_80019ED0((s8)((u8 *)arg0)[4] + delta) == 0) {
        return 0;
    }
    ((u8 *)arg0)[4] = ((u8 *)arg0)[4] + delta;
    return 0;
}

s32 fn_800AA078(void *arg0) {
    s32 fn_8000CEE4(s32);
    void fn_80016DE0(void);
    void *fn_80019ED0(s32);
    void Battle_SetPhase(void *, u8);
    void fn_8014D698(void *, u8, s32, s32, s32);
    extern u8 gBattleState[];
    extern u64 gSystemSave[];
    u8 *s;
    u8 saved;
    void *unit;

    s = gBattleState;
    saved = s[0xA6];
    fn_80016DE0();
    fn_8014D698(gBattleState, (u8)(fn_8000CEE4(0x1E) + 1), 0, 0, 1);
    s[0xA6] = saved;
    unit = fn_80019ED0((s32)*(s8 *)((u8 *)arg0 + 4));
    {
        u8 *p;
        p = gBattleState;
        Battle_SetPhase(p, *(u8 *)((u8 *)unit + 0x3C));
    }
    gSystemSave[1] = 0x0123456789ABCDEFULL;
    fn_80006220(0xA);
    return 5;
}

void fn_800AA134(void) {
    M2C_UNK Process_UnlinkByKey(void *);
    extern u8 lbl_8028CDF0[];
    Process_UnlinkByKey(lbl_8028CDF0);
}

void fn_800AA15C(void) {
    extern u8 lbl_8028CDF0[];
    void Process_Create(void *, s32);
    Process_Create(lbl_8028CDF0, 4);
}

u32 *Process_Find(u32 arg0);
s32 fn_800AA188(void) {
    void *Process_Find(void *);
    extern u8 lbl_8028CDF0[];
    void *p;

    p = Process_Find(lbl_8028CDF0);
    if (p != NULL) {
        return *(s32 *)((u8 *)p + 0x60) == 0;
    }
    return 0;
}

void fn_800AA1CC(void)
{
    void *Process_Find(void *);
    extern u8 lbl_8028CDF0[];
    void *p;
    u32 v;

    p = Process_Find(lbl_8028CDF0);
    if (p != NULL) {
        v = *(u32 *)((u8 *)p + 0x60);
        *(u32 *)((u8 *)p + 0x60) = v + 1;
    }
}

void fn_800AA208(void)
{
    void *Process_Find(void *);
    extern u8 lbl_8028CDF0[];
    void *p;
    u32 v;

    p = Process_Find(lbl_8028CDF0);
    if (p != NULL) {
        v = *(u32 *)((u8 *)p + 0x60);
        *(u32 *)((u8 *)p + 0x60) = v - 1;
    }
}

void fn_800AA244(void) {
    M2C_UNK fn_800F0774();
    M2C_UNK fn_800F2E70();
    fn_800F2E70();
    fn_800F0774();
}

s32 fn_800AA268(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x60) != 0;
}

void fn_800AA27C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
}


s32 fn_800AA288(s32 arg0) {
    s32 fn_8003F224(s32, s32);
    s32 fn_8003F47C(void);
    void Map_Get(void);
    s32 fn_800431E4(void);
    u8 fn_80105E88(s32, s32);
    s32 count;
    s32 list;
    s32 i;
    s32 item;

    Map_Get();
    list = fn_800431E4();
    count = fn_8003F47C();
    for (i = 0; i < count; i++) {
        item = fn_8003F224(list, i);
        if (fn_80105E88(item, arg0)) {
            return item;
        }
    }
    return 0;
}
s32 fn_800AA304(s8 arg0, s8 arg1) {
    extern struct {
        u8 pad0[0xD];
        u8 unitMap[0x6100];
        u8 pad1;
        s16 costMap[0x4040];
        s8 fogMap[64];
    } gBattleMap;
    extern u8 gUnits[];
    extern void *gUiContext[];
    s16 val;
    u8 id;
    void *unit;

    val = gBattleMap.costMap[arg0 + arg1 * 64];
    if (val < 0) {
        return 0;
    }
    if (val == 0) {
        return 1;
    }
    if (gBattleMap.fogMap[arg0 + arg1 * 64] != 0) {
        return 0;
    }
    id = gBattleMap.unitMap[arg0 + arg1 * 64];
    if (id != 0) {
        unit = gUnits + (id - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit != NULL && unit != gUiContext[0]) {
        return 0;
    }
    return 1;
}

void Map_UpdateCursorMoveLimit(void) {
    /* When the unit under the cursor changes, hide or rebuild the move-limit overlay. */
    void Map_HideMoveLimitView(void);
    void Map_ShowMoveLimitView(void);
    void Map_SetupUnitMoveLimit(void *);

    extern u8 gUnits[101760];
    extern u8 gBattleMap[151280];
    extern u8 gBattleState[1400];
    extern void *gPadInput;
    extern void *gCursorHoverUnit;
    extern s8 gCursorHoverUnitInited;

    void *unit;
    u8 id;
    s8 sx;
    s8 sy;
    struct {
        struct {
            u8 pad[2];
            s8 stickX;
            s8 stickY;
        } *stick;
        u32 buttons;
    } *pad;

    if (gCursorHoverUnitInited == 0) {
        gCursorHoverUnit = NULL;
        gCursorHoverUnitInited = 1;
    }

    sx = *(float *)&gBattleState[0x524];
    sy = *(float *)&gBattleState[0x528];
    id = gBattleMap[sx + (sy << 6) + 0xD];
    unit = (id != 0) ? &gUnits[(id - 1) * 0x280] : NULL;

    if (gCursorHoverUnit != unit) {
        pad = gPadInput;
        if ((pad->buttons & 0xF) != 0 || pad->stick->stickX != 0 || pad->stick->stickY != 0) {
            if (unit == NULL) {
                Map_HideMoveLimitView();
                gCursorHoverUnit = NULL;
            }
        } else if ((u32)(((gBattleState[0x9F] >> 6) & 1)) != 1U) {
            gCursorHoverUnit = unit;
            if (unit == NULL || *(u8 *)(*(u32 *)((char *)unit + 0x190) + 8) == 0) {
                Map_HideMoveLimitView();
            } else {
                Map_SetupUnitMoveLimit(unit);
                Map_ShowMoveLimitView();
            }
        }
    }
}

/* Build and show the selected unit's move-range overlay (refresh or first setup). */
void MapUi_ShowUnitRanges(void *unit) {
    void UiCtx_RefreshRangeSelect(void *);
    void fn_80022DAC(void *, s32, s32);
    void fn_80022FD8(void *, s32);
    void fn_800227F8(void *, s32);
    void fn_80022748(void *, s32);
    void Map_FloodMoveRange(void *, u8, u8, u8, s32, s32);
    void Msg_Expand(void *);
    void fn_80091A1C(void);
    void UiCtx_BeginMoveSelect(void *, void *);
    void Map_SetupUnitMoveLimit(void *);
    void Map_ShowMoveLimitView(void);
    extern u8 gUiContext[];
    extern u8 gBattleMap[];
    extern u8 gMapMoveMsgStrs[];
    u8 mov;

    if ((s8)gUiContext[0x12] != 0) {
        UiCtx_RefreshRangeSelect(gUiContext);
        mov = gUiContext[0x11];
        fn_80022DAC(gBattleMap, 8, 0);
        fn_80022FD8(gBattleMap, 5);
        fn_800227F8(gBattleMap, *(s32 *)((u8 *)unit + 0x18C));
        fn_80022748(gBattleMap, *(s32 *)((u8 *)unit + 0x190));
        Map_FloodMoveRange(gBattleMap, ((u8 *)unit)[0x19E], ((u8 *)unit)[0x19F], mov, 0, 0);
        Msg_Expand(gMapMoveMsgStrs + 0xCE);
        fn_80091A1C();
    } else {
        UiCtx_BeginMoveSelect(gUiContext, unit);
        Map_SetupUnitMoveLimit(unit);
        Msg_Expand(gMapMoveMsgStrs + 0xD9);
        fn_80091A1C();
    }
    Map_ShowMoveLimitView();
}

void *fn_800AA5F0(void *arg0) {
    extern void *gUnitLists;
    u32 var_r0;
    void *var_r3;
    void *var_r4;
    void *var_r5;

    var_r4 = *(void **)gUnitLists;
    if (var_r4 == NULL) {
        return NULL;
    }

    if (arg0 != NULL) {
        u8 *temp_r0 = *(u8 **)((char *)arg0 + 0x190);
        temp_r0 = *(u8 **)((char *)temp_r0 + 8);
        if ((temp_r0 != NULL) && (*temp_r0 != 0)) {
            arg0 = NULL;
        }
    }

    if (arg0 == NULL) {
    loop_40:
        var_r3 = var_r4;
        do {
            s32 *temp_r0 = *(s32 **)((char *)var_r4 + 0x1A0);
            if (*temp_r0 & 5) {
                var_r0 = 0;
            } else {
                u16 *temp_r1 = *(u16 **)((char *)var_r4 + 0x1A4);
                if (((*temp_r1 >> 7) & 7) == 0) {
                    u8 *temp_r2 = *(u8 **)((char *)var_r4 + 0x1A5);
                    if ((*temp_r2 & 7) != 0) {
                        var_r0 = 0;
                    } else {
                        var_r0 = 1;
                    }
                } else {
                    var_r0 = 0;
                }
            }

            if (var_r0 != 0) {
                return var_r4;
            }
            var_r4 = *(void **)((char *)var_r4 + 0x184);
        } while (var_r4 != NULL);
        return NULL;
    } else {
        var_r5 = *(void **)((char *)arg0 + 0x184);
        if (var_r5 == NULL) {
            var_r5 = var_r4;
        }
    loop_15:
        var_r3 = var_r5;
        do {
            s32 *temp_r0 = *(s32 **)((char *)var_r3 + 0x1A0);
            if (*temp_r0 & 5) {
                var_r0 = 0;
            } else {
                u16 *temp_r1 = *(u16 **)((char *)var_r3 + 0x1A4);
                if (((*temp_r1 >> 7) & 7) == 0) {
                    u8 *temp_r2 = *(u8 **)((char *)var_r3 + 0x1A5);
                    if ((*temp_r2 & 7) != 0) {
                        var_r0 = 0;
                    } else {
                        var_r0 = 1;
                    }
                } else {
                    var_r0 = 0;
                }
            }

            if (var_r0 == 0) {
                var_r3 = *(void **)((char *)var_r3 + 0x184);
                goto loop_15;
            }
            return var_r3;
        } while (0); /* Never reached */
    }
}

s32 fn_800AA76C(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 var_r5;

    var_r5 = arg2;
    temp_r0 = arg0 + var_r5;
    if (temp_r0 > arg1) {
        return arg1 - arg0;
    }
    if (temp_r0 < 0) {
        var_r5 = -arg0;
    }
    return var_r5;
}

void *Map_GetCursorUnit(void) {
    extern u8 gBattleState[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    s8 sx;
    s8 sy;
    u8 id;

    sx = (s8)*(f32 *)(gBattleState + 0x524);
    sy = (s8)*(f32 *)(gBattleState + 0x528);
    id = gBattleMap[sx + (sy << 6) + 0xD];
    if (id != 0) {
        return &gUnits[(id - 1) * 0x280];
    }
    return NULL;
}

void fn_800AA80C(void *arg0) {
    u8 Status_Test(void *, s32);
    void fn_80022DAC(void *, s32, s32);
    void fn_80022FD8(void *, s32);
    void fn_8002011C(void *, u8, u8, s32, s32);
    extern u8 gBattleMap[];

    if (Status_Test((u8 *)arg0 + 0x1BC, 0x43) != 0) {
        fn_80022DAC(gBattleMap, 5, -1);
        fn_80022DAC(gBattleMap, 8, 0);
        fn_80022FD8(gBattleMap, 6);
        fn_8002011C(gBattleMap, ((u8 *)arg0)[0x19E], ((u8 *)arg0)[0x19F], 1, 2);
    }
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
void fn_800AA89C(void *arg0) {
    u8 fn_8001DDBC(void *);
    void fn_8002011C(u8 *, s8, s8, u8, u8);
    void **Unit_GetHeldItemSlot(void *, s32);
    u8 fn_8009339C(void *);
    u8 Status_Test(void *, s32);
    extern u8 gBattleMap[151280];

    u8 saved;
    void *self;
    s32 slot;
    s8 bestMax;
    s8 bestMin;
    u8 *map;
    u8 *unitSlot;
    u32 pp;
    void *item;
    u32 atk;
    s8 y;
    s8 x;
    s32 yOff;
    u8 *rowBase;
    u8 *cell;
    s32 idx2;

    self = arg0;
    bestMin = 0x64;
    map = gBattleMap;
    bestMax = 0;
    unitSlot = map + 0xD;
    slot = 0;
    saved = unitSlot[(s8)*(u8 *)((u8 *)self + 0x19E) + ((s8)*(u8 *)((u8 *)self + 0x19F) << 6)];
    unitSlot[(s8)*(u8 *)((u8 *)self + 0x19E) + ((s8)*(u8 *)((u8 *)self + 0x19F) << 6)] = 0;

    goto slot_cmp;
slot_loop:
    pp = (u32)Unit_GetHeldItemSlot(self, slot);
    item = *(void **)pp;
    if (item == NULL) {
        goto slots_done;
    }
    if (fn_8009339C(self) == 0) {
        goto slot_next;
    }
    item = *(void **)pp;
    if (item != NULL) {
        pp = ((u8 *)item)[0x1D];
    } else {
        pp = 0;
    }
    if (item != NULL) {
        atk = fn_8001DDBC(item);
    } else {
        atk = 0;
    }
    atk = (u8)atk;
    if (bestMin > (s32)pp || (s32)atk > bestMax) {
        if ((s32)pp < bestMin) {
            bestMin = (s8)pp;
        }
        if (bestMax < (s32)atk) {
            bestMax = (s8)atk;
        }
        y = 0;
        yOff = 0;
        rowBase = gBattleMap;
        goto y_cmp;
y_loop:
        cell = rowBase;
        idx2 = yOff << 1;
        x = 0;
        goto x_cmp;
x_loop:
        if (*(s16 *)(map + idx2 + 0x610E) >= 0
            && (s8)cell[0xE18E] == 0
            && cell[0xD] == 0) {
            fn_8002011C(gBattleMap, x, y, (u8)pp, (u8)atk);
        }
        idx2 += 2;
        cell += 1;
        x += 1;
x_cmp:
        if ((s32)x < *(s32 *)map) {
            goto x_loop;
        }
        yOff += 0x40;
        rowBase += 0x40;
        y += 1;
y_cmp:
        if ((s32)y < *(s32 *)(map + 4)) {
            goto y_loop;
        }
    }
slot_next:
    slot += 1;
slot_cmp:
    if (slot < 4) {
        goto slot_loop;
    }
slots_done:
    if (Status_Test((u8 *)self + 0x1BC, 0x43) != 0) {
        u8 *map2 = gBattleMap;
        y = 0;
        yOff = 0;
        rowBase = map2;
        goto y2_cmp;
y2_loop:
        cell = rowBase;
        idx2 = yOff << 1;
        x = 0;
        goto x2_cmp;
x2_loop:
        if (*(s16 *)(map2 + idx2 + 0x610E) >= 0
            && (s8)cell[0xE18E] == 0
            && cell[0xD] == 0) {
            fn_8002011C(gBattleMap, x, y, 1, 2);
        }
        idx2 += 2;
        cell += 1;
        x += 1;
x2_cmp:
        if ((s32)x < *(s32 *)map2) {
            goto x2_loop;
        }
        yOff += 0x40;
        rowBase += 0x40;
        y += 1;
y2_cmp:
        if ((s32)y < *(s32 *)(map + 4)) {
            goto y2_loop;
        }
    }

    unitSlot[(s8)*(u8 *)((u8 *)self + 0x19E) + ((s8)*(u8 *)((u8 *)self + 0x19F) << 6)] = saved;
}
#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

void fn_800AAB3C(void *arg0) {
    u8 fn_8001DDBC(void);
    void fn_8002011C(void *, u8, u8, u8);
    void fn_80022DAC(void *, s32, s32);
    void fn_80022FD8(void *, s32);
    void **Unit_GetHeldItemSlot(void *, s32);
    u8 fn_8009339C(void *);
    extern u16 gBattleMap;

    s32 var_r27;
    s8 var_r28;
    s8 var_r29;
    u8 var_r0;
    u8 var_r0_2;
    void **temp_r3;
    void *temp_r3_2;
    u8 temp_r31;

    fn_80022DAC(&gBattleMap, 5, -1);
    fn_80022DAC(&gBattleMap, 8, 0);
    fn_80022FD8(&gBattleMap, 6);
    var_r29 = 0x64;
    var_r28 = 0;
    var_r27 = 0;
loop_1:
    temp_r3 = Unit_GetHeldItemSlot(arg0, var_r27);
    if ((void *) *temp_r3 != NULL) {
        if (fn_8009339C(arg0) != 0) {
            temp_r3_2 = *temp_r3;
            if (temp_r3_2 != NULL) {
                var_r0 = M2C_FIELD(temp_r3_2, u8 *, 0x1D);
            } else {
                var_r0 = 0;
            }
            if (temp_r3_2 != NULL) {
                var_r0_2 = fn_8001DDBC();
            } else {
                var_r0_2 = 0;
            }
            if ((var_r29 > (s32) var_r0) || ((s32) var_r0_2 > var_r28)) {
                if ((s32) var_r0 < var_r29) {
                    var_r29 = (s8) var_r0;
                }
                if (var_r28 < (s32) var_r0_2) {
                    var_r28 = (s8) var_r0_2;
                }
                fn_8002011C(&gBattleMap, M2C_FIELD(arg0, u8 *, 0x19E), M2C_FIELD(arg0, u8 *, 0x19F), var_r0);
            }
        }
        var_r27 += 1;
        if (var_r27 < 4) {
            goto loop_1;
        }
    }
}

void fn_800AAC64(void *arg0) {
    extern u8 gBattleMap[];
    
    fn_80022FD8(gBattleMap, 5);
    fn_800227F8(gBattleMap, *(s32*)((char*)arg0 + 0x18C));
    fn_80022748(gBattleMap, 0);
    Map_FloodMoveRange(gBattleMap, *(u8*)((char*)arg0 + 0x19E), *(u8*)((char*)arg0 + 0x19F), 0x3E8, 0, 0);
}

void fn_800AAE78(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    void *Process_CreateChild(void *, void *);
    void *Unit_GetItemSlot(void *, s32);
    void Item_Copy(void *, void *);
    void fn_80091CD8(void *);
    void fn_8018DBD8(void);
    void fn_800256A0(void *, s32);
    void Process_Goto(void *, s32);
    extern u8 lbl_8028CEF8[];
    extern void *gUiContext[];
    extern u8 lbl_80312ACC[];
    extern u8 gBattleState[];
    extern void *gPadInput;
    typedef struct {
        u8 pad[0x28];
        s16 unk28;
        u8 pad2A[0x30 - 0x2A];
        void *unk30;
        void *unk34;
        s16 unk38;
        s16 unk3A;
        u8 unk3C;
        u8 unk3D;
        u8 unk3E;
        u8 unk3F;
        u8 pad40;
        u8 unk41;
        u8 unk42;
        u8 unk43;
        u8 unk44;
        u8 unk45;
    } Obj;
    s32 col;
    s32 row;
    u8 *entry;
    u8 *rowPtr;
    u8 *base;
    Obj *self;

    {
        void *ret;
        void **ef;
        void *w1;
        void *w0;
        ret = Process_CreateChild(lbl_8028CEF8, arg0);
        ef = gUiContext;
        row = 0;
        w1 = ef[1];
        base = lbl_80312ACC;
        w0 = ef[0];
        self = ret;
        self->unk30 = w0;
        rowPtr = base;
        self->unk34 = w1;
        self->unk3A = -1;
        self->unk38 = -1;
        self->unk43 = 0;
        self->unk41 = 0;
    }
    do {
        col = 0;
        entry = rowPtr;
        do {
            *(s16 *)entry = 0x1E;
            *(s16 *)(entry + 2) = (s16)(((col & 3) * 0x1C) + 0x71);
            if (row != 0) {
                *(s16 *)entry = (s16)(*(s16 *)entry + 0x118);
            }
            if (col >= 4) {
                *(s16 *)(entry + 2) = (s16)(*(s16 *)(entry + 2) + 0x88);
            }
            if (row != 0) {
                Item_Copy(entry + 4, Unit_GetItemSlot(self->unk34, col));
            } else {
                Item_Copy(entry + 4, Unit_GetItemSlot(self->unk30, col));
            }
            col += 1;
            entry += 0x10;
        } while (col < 8);
        row += 1;
        rowPtr += 0x80;
    } while (row < 2);
    self->unk44 = 0;
    fn_80091CD8(self->unk30);
    fn_80091CD8(self->unk34);
    rowPtr = base;
    for (row = 0; row < 2; row++, rowPtr += 0x80) {
        for (entry = rowPtr, col = 0; col < 8; entry += 0x10, col++) {
            if (col < 4 && self->unk44 != 0) {
                entry[0xC] = 0;
            } else {
                entry[0xC] = (*(s32 *)(entry + 4) != 0);
            }
        }
    }
    col = 0;
    entry = base;
    self->unk3C = 0;
    while (1) {
        if (col >= 8) {
            col = -1;
            break;
        }
        if (entry[0xC] != 0) {
            break;
        }
        entry += 0x10;
        col += 1;
    }
    self->unk3D = col;
    if ((s8)self->unk3D < 0) {
        col = 0;
        self->unk3C = 1;
        while (1) {
            if (col >= 8) {
                col = -1;
                break;
            }
            if (base[0x8C] != 0) {
                break;
            }
            base += 0x10;
            col += 1;
        }
        self->unk3D = col;
    }
    self->unk3E = 0;
    self->unk3F = 0;
    fn_8018DBD8();
    gBattleState[0x51D] = 0xF;
    self->unk42 = 1;
    self->unk45 = arg1;
    if (arg2 >= 0) {
        self->unk42 = 0;
        self->unk41 = 0;
        for (row = 0; row < 2; row++, base += 0x80) {
            for (entry = base, col = 0; col < 8; entry += 0x10, col++) {
                if (col < 4 && self->unk44 != 0) entry[0xC] = 0;
                else entry[0xC] = (*(s32 *)(entry + 4) != 0);
            }
        }
        self->unk3C = arg2;
        self->unk3D = arg3;
        Process_Goto(self, 1);
    }
}

#pragma use_lmw_stmw on
void fn_800AB2A4(void *arg0) {
    void *Process_CreateChild(void *, void *);
    void *Unit_GetItemSlot(void *, s32);
    void Item_Copy(void *, void *);
    void fn_80091CD8(void *);
    void fn_8018DBD8(void);
    void fn_800256A0(void *, s32);
    void Process_Goto(void *, s32);
    extern u8 lbl_8028CE90[];
    extern void *gUiContext[];
    extern u8 lbl_80312ACC[];
    extern u8 gBattleState[];
    extern void *gPadInput;
    typedef struct {
        u8 pad[0x28];
        s16 unk28;
        u8 pad2A[0x30 - 0x2A];
        void *unk30;
        void *unk34;
        s16 unk38;
        s16 unk3A;
        u8 unk3C;
        u8 unk3D;
        u8 unk3E;
        u8 unk3F;
        u8 pad40;
        u8 unk41;
        u8 unk42;
        u8 unk43;
        u8 unk44;
        u8 unk45;
    } Obj;
    s32 row;
    u8 *rowPtr;
    u8 *base;
    Obj *self;
    s32 col;
    u8 *entry;

    {
        void *ret;
        void **ef;
        void *w1;
        void *w0;
        ret = Process_CreateChild(lbl_8028CE90, arg0);
        ef = gUiContext;
        row = 0;
        w1 = ef[1];
        rowPtr = lbl_80312ACC;
        w0 = ef[0];
        self = ret;
        self->unk30 = w0;
        base = rowPtr;
        self->unk34 = w1;
        self->unk3A = -1;
        self->unk38 = -1;
        self->unk43 = row;
        self->unk41 = row;
    }
    do {
        col = 0;
        entry = rowPtr;
        do {
            *(s16 *)entry = 0x1E;
            *(s16 *)(entry + 2) = (s16)(((col & 3) * 0x1C) + 0x71);
            if (row != 0) {
                *(s16 *)entry = (s16)(*(s16 *)entry + 0x118);
            }
            if (col >= 4) {
                *(s16 *)(entry + 2) = (s16)(*(s16 *)(entry + 2) + 0x88);
            }
            if (row != 0) {
                Item_Copy(entry + 4, Unit_GetItemSlot(self->unk34, col));
            } else {
                Item_Copy(entry + 4, Unit_GetItemSlot(self->unk30, col));
            }
            col += 1;
            entry += 0x10;
        } while (col < 8);
        row += 1;
        rowPtr += 0x80;
    } while (row < 2);
    self->unk44 = 0;
    fn_80091CD8(self->unk30);
    fn_80091CD8(self->unk34);
    rowPtr = base;
    for (row = 0; row < 2; row++, rowPtr += 0x80) {
        for (entry = rowPtr, col = 0; col < 8; entry += 0x10, col++) {
            if (col < 4 && self->unk44 != 0) {
                entry[0xC] = 0;
            } else {
                entry[0xC] = (*(s32 *)(entry + 4) != 0);
            }
        }
    }
    col = 0;
    entry = base;
    self->unk3C = 0;
    while (1) {
        if (col >= 8) {
            col = -1;
            break;
        }
        if (entry[0xC] != 0) {
            break;
        }
        entry += 0x10;
        col += 1;
    }
    self->unk3D = col;
    if ((s8)self->unk3D < 0) {
        col = 0;
        self->unk3C = 1;
        while (1) {
            if (col >= 8) {
                col = -1;
                break;
            }
            if (base[0x8C] != 0) {
                break;
            }
            base += 0x10;
            col += 1;
        }
        self->unk3D = col;
    }
    self->unk3E = 0;
    self->unk3F = 0;
    fn_8018DBD8();
    gBattleState[0x51D] = 0xF;
    self->unk42 = 1;
    self->unk28 = 4;
    self->unk45 = 0x9A;
    if (*((u8 *)gUiContext + 8) == 0x28) {
        fn_800256A0(gPadInput, 0x100);
        self->unk3C = 0;
        self->unk3D = *((u8 *)gUiContext + 0xA);
        Process_Goto(self, 3);
    }
}
void fn_800AB73C(void) {
    M2C_UNK fn_800AB75C();
    fn_800AB75C();
}

void fn_800AB75C(void *arg0) {
    void fn_8001C76C(void *);
    void *Item_Copy(void *, void *);
    void *Item_Destroy(void *, s32);
    void fn_800ABA3C(void *);
    extern u8 lbl_80312ACC[];

    u8 sp8[8];
    u8 *var_r3;
    s32 j;
    u8 temp_x;
    void *self;
    s32 i;
    s8 y;
    u8 *var_r7;
    u8 *var_r8;

    self = arg0;
    *(u8 *)((u8 *)self + 0x43) = 1;
    ((Entry9Bits *)(lbl_80312ACC + ((s8)*(u8 *)((u8 *)self + 0x3C) << 7)
                                  + ((s8)*(u8 *)((u8 *)self + 0x3D) << 4) + 9))->flag = 0;
    ((Entry9Bits *)(lbl_80312ACC + ((s8)*(u8 *)((u8 *)self + 0x3E) << 7)
                                  + ((s8)*(u8 *)((u8 *)self + 0x3F) << 4) + 9))->flag = 0;
    fn_8001C76C(sp8);
    Item_Copy(sp8, lbl_80312ACC + ((s8)*(u8 *)((u8 *)self + 0x3C) << 7)
                                 + ((s8)*(u8 *)((u8 *)self + 0x3D) << 4) + 4);
    Item_Copy(lbl_80312ACC + ((s8)*(u8 *)((u8 *)self + 0x3C) << 7)
                           + ((s8)*(u8 *)((u8 *)self + 0x3D) << 4) + 4,
                lbl_80312ACC + ((s8)*(u8 *)((u8 *)self + 0x3E) << 7)
                             + ((s8)*(u8 *)((u8 *)self + 0x3F) << 4) + 4);
    Item_Copy(lbl_80312ACC + ((s8)*(u8 *)((u8 *)self + 0x3E) << 7)
                           + ((s8)*(u8 *)((u8 *)self + 0x3F) << 4) + 4, sp8);
    fn_800ABA3C(self);
    var_r8 = (u8 *)(u32)lbl_80312ACC;
    for (i = 0; i < 2; i++, var_r8 += 0x80) {
        for (var_r7 = var_r8, j = 0; j < 8; var_r7 += 0x10, j++) {
            if (j < 4 && *(u8 *)((u8 *)self + 0x44) != 0) {
                *(u8 *)(var_r7 + 0xC) = 0;
            } else {
                *(u8 *)(var_r7 + 0xC) = (*(s32 *)(var_r7 + 4) != 0);
            }
        }
    }
    temp_x = *(u8 *)((u8 *)self + 0x3E);
    y = *(u8 *)((u8 *)self + 0x3F);
    var_r3 = lbl_80312ACC + ((s8)*(u8 *)((u8 *)self + 0x3E) << 7) + (y << 4);
    if (y >= 0) {
        while (1) {
            if (*(u8 *)(var_r3 + 0xC) != 0) {
                break;
            }
            var_r3 -= 0x10;
            y -= 1;
        }
    }
    if (y - (s8)*(u8 *)((u8 *)self + 0x40) >= 0) {
        *(u8 *)((u8 *)self + 0x3C) = temp_x;
        *(u8 *)((u8 *)self + 0x3D) = (u8)y;
    }
    Item_Destroy(sp8, -1);
}

#pragma cplusplus on
#pragma opt_strength_reduction off
extern "C" void *Item_Copy(void *, void *);
extern "C" void Item_Clear(void *);
#pragma cplusplus off
void fn_800ABA3C(void) {
    void fn_8001C76C(void *);
    void Item_Clear(void *);
    void Item_Destroy(void *, s32);
    extern u8 lbl_80312ACC[];
    u8 *base;
    {
        u8 a[4][8];
        s32 off, n;
        u8 *p;
        u8 *q;
        u8 *dst;
        s32 i;
        u8 *check;
        fn_8001C76C(a[0]); fn_8001C76C(a[1]); fn_8001C76C(a[2]); fn_8001C76C(a[3]);

        q = a[0];
        for(i=0,p=q;i<4;i++,p+=8) Item_Clear(p);
        base=lbl_80312ACC;
        i=0; n=i; off=i; dst=base+0;
        for(i=0,p=dst,check=base;i<4;i++,p+=16,check+=16) {
            if (*(u32 *)(check+4)!=0) {
                u8 *out = (u8 *)a+off;
                n++; off+=8;
                Item_Copy(out,p+4);
            }
            Item_Clear(p+4);
        }
        for(i=0;i<n;q+=8,dst+=16,i++) Item_Copy(dst+4,q);
        Item_Destroy(a[3],-1); Item_Destroy(a[2],-1); Item_Destroy(a[1],-1); Item_Destroy(a[0],-1);

    }
    {
        u8 a[4][8];
        s32 off, n;
        u8 *p;
        u8 *q;
        u8 *dst;
        s32 i;
        u8 *check;
        fn_8001C76C(a[0]); fn_8001C76C(a[1]); fn_8001C76C(a[2]); fn_8001C76C(a[3]);

        q = a[0];
        for(i=0,p=q;i<4;i++,p+=8) Item_Clear(p);
        base=lbl_80312ACC;
        i=0; n=i; off=i; dst=base+64;
        for(i=0,p=dst,check=base;i<4;i++,p+=16,check+=16) {
            if (*(u32 *)(check+68)!=0) {
                u8 *out = (u8 *)a+off;
                n++; off+=8;
                Item_Copy(out,p+4);
            }
            Item_Clear(p+4);
        }
        for(i=0;i<n;q+=8,dst+=16,i++) Item_Copy(dst+4,q);
        Item_Destroy(a[3],-1); Item_Destroy(a[2],-1); Item_Destroy(a[1],-1); Item_Destroy(a[0],-1);

    }
    {
        u8 a[4][8];
        s32 off, n;
        u8 *p;
        u8 *q;
        u8 *dst;
        s32 i;
        u8 *check;
        fn_8001C76C(a[0]); fn_8001C76C(a[1]); fn_8001C76C(a[2]); fn_8001C76C(a[3]);

        q = a[0];
        for(i=0,p=q;i<4;i++,p+=8) Item_Clear(p);
        base=lbl_80312ACC;
        i=0; n=i; off=i; dst=base+128;
        for(i=0,p=dst,check=base;i<4;i++,p+=16,check+=16) {
            if (*(u32 *)(check+132)!=0) {
                u8 *out = (u8 *)a+off;
                n++; off+=8;
                Item_Copy(out,p+4);
            }
            Item_Clear(p+4);
        }
        for(i=0;i<n;q+=8,dst+=16,i++) Item_Copy(dst+4,q);
        Item_Destroy(a[3],-1); Item_Destroy(a[2],-1); Item_Destroy(a[1],-1); Item_Destroy(a[0],-1);

    }
    {
        u8 a[4][8];
        s32 off, n;
        u8 *p;
        u8 *q;
        u8 *dst;
        s32 i;
        u8 *check;
        fn_8001C76C(a[0]); fn_8001C76C(a[1]); fn_8001C76C(a[2]); fn_8001C76C(a[3]);

        q = a[0];
        for(i=0,p=q;i<4;i++,p+=8) Item_Clear(p);
        base=lbl_80312ACC;
        i=0; n=i; off=i; dst=base+192;
        for(i=0,p=dst,check=base;i<4;i++,p+=16,check+=16) {
            if (*(u32 *)(check+196)!=0) {
                u8 *out = (u8 *)a+off;
                n++; off+=8;
                Item_Copy(out,p+4);
            }
            Item_Clear(p+4);
        }
        for(i=0;i<n;q+=8,dst+=16,i++) Item_Copy(dst+4,q);
        Item_Destroy(a[3],-1); Item_Destroy(a[2],-1); Item_Destroy(a[1],-1); Item_Destroy(a[0],-1);

    }
}
void fn_800ABE74(void *arg0) {
    void fn_800AC0C0(void);
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    s32 Msg_Expand(void *);
    u64 *Item_GetFlagsPtr(void *);
    void Ui_PlaySeCue(void *, s32);
    void fn_80166AE8(s16, s32, s32, void *, void *);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_HideUnitInfoPopup(void *);
    void Ui_OpenUnitInfoPopup(void *, void *, void *, f32, f32);
    extern void *gPadInput;
    extern u8 gUnitInfoPopup[];
    extern u8 lbl_80312ACC[];
    extern u8 lbl_8026E858[];
    extern u32 gUnitInfoPopupFlag;
    u32 var_r31;
    void *var_r30;
    s32 var_r29;
    register s32 str;
    register u8 *entry;
    u32 a;

    var_r30 = arg0;
    fn_800AC0C0();
    a = ((u32 *)gPadInput)[1];
    var_r31 = a & (((u32 *)gPadInput)[2] ^ a);
    if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
        if (var_r31 & 0xA00) {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
        }
    } else if (var_r31 & 0x100) {
        register var_r31 = 0;
        entry = lbl_80312ACC + (((s8)*(u8 *)((u8 *)var_r30 + 0x3C)) << 7)
                              + (((s8)*(u8 *)((u8 *)var_r30 + 0x3D)) << 4);
        if (*(u32 *)(entry + 4) != 0) {
            if (*Item_GetFlagsPtr(entry + 4) & 0x200) {
                var_r31 = 1;
            }
        }
        if ((u8)var_r31 != 0) {
            var_r31 = ((s8)*(u8 *)((u8 *)var_r30 + 0x3D)) << 4;
            var_r29 = ((s8)*(u8 *)((u8 *)var_r30 + 0x3C)) << 7;
            str = Msg_Expand(lbl_8026E858 + 0xE7);
            entry = lbl_80312ACC + var_r29;
            fn_80166AE8(*(s16 *)((u8 *)entry + var_r31),
                        *(s16 *)((u8 *)entry + var_r31 + 2) + 0x28,
                        str, var_r30, entry);
        } else {
            Process_ClearFunc(var_r30);
            Ui_PlaySeCue(lbl_8026E858 + 0xEF, 0x64);
        }
    } else if (var_r31 & 0x200) {
        *(u8 *)((u8 *)var_r30 + 0x3C) = *(u8 *)((u8 *)var_r30 + 0x3E);
        *(u8 *)((u8 *)var_r30 + 0x3D) = *(u8 *)((u8 *)var_r30 + 0x3F);
        Process_Goto(var_r30, 0);
        Ui_PlaySeCue(lbl_8026E858 + 0xFF, 0x64);
    } else if (var_r31 & 0x800) {
        entry = lbl_80312ACC + (((s8)*(u8 *)((u8 *)var_r30 + 0x3C)) << 7)
                              + (((s8)*(u8 *)((u8 *)var_r30 + 0x3D)) << 4);
        if (*(u32 *)(entry + 4) != 0) {
            Ui_OpenUnitInfoPopup(gUnitInfoPopup, var_r30, entry + 4,
                        (f32)*(s16 *)entry,
                        (f32)(*(s16 *)(entry + 2) + 0x28));
            *(u32 *)gUnitInfoPopup |= gUnitInfoPopupFlag;
        }
    }
}

void fn_800AC0C0(void *arg0) {
    void Ui_PlaySeCue(void *, s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoPopup(void *, void *, f32, f32);
    void Ui_HideUnitInfoPopup(void *);
    extern void *gPadInput;
    extern u8 lbl_80312ACC[];
    extern u8 lbl_8026E858[];
    extern u8 gUnitInfoPopup[];

    u8 var_r7;
    u32 temp_r0;
    u32 temp_r6;
    u32 temp_r3;
    s32 var_r6;
    u8 *var_r5;
    register s32 temp_r8;
    s32 temp_r5;
    s32 temp_r4;
    s32 var_r7_2;
    u8 *var_r5_2;
    u8 *var_r4;
    u8 *temp_r7;
    void *self = arg0;

    var_r7 = 0;
    temp_r0 = ((u32 *)gPadInput)[3];
    temp_r6 = ((u32 *)gPadInput)[1];
    temp_r3 = temp_r6 & (((u32 *)gPadInput)[2] ^ temp_r6);
    if ((temp_r0 & 0x01000001) && ((s32)*(u8 *)((u8 *)self + 0x3C) == 1)) {
        var_r6 = *(s8 *)((u8 *)self + 0x3D);
        var_r5 = lbl_80312ACC + (var_r6 * 0x10);
        while (1) {
            if (var_r6 < 0) {
                break;
            }
            if (var_r5[0xC] != 0) {
                break;
            }
            var_r5 -= 0x10;
            var_r6 -= 1;
        }
        if (var_r6 < 0) {
            return;
        }
        var_r7 = 1;
        *(u8 *)((u8 *)self + 0x3C) = 0;
        *(u8 *)((u8 *)self + 0x3D) = (u8)var_r6;
    }
    if ((temp_r0 & 0x02000002) && (*(s8 *)((u8 *)self + 0x3C) == 0)) {
        var_r6 = *(s8 *)((u8 *)self + 0x3D);
        var_r5 = lbl_80312ACC + (var_r6 * 0x10);
        while (1) {
            if (var_r6 < 0) {
                break;
            }
            if (var_r5[0x8C] != 0) {
                break;
            }
            var_r5 -= 0x10;
            var_r6 -= 1;
        }
        if (var_r6 < 0) {
            return;
        }
        var_r7 = 0;
        *(u8 *)((u8 *)self + 0x3C) = 1;
        *(u8 *)((u8 *)self + 0x3D) = (u8)var_r6;
    }
    if (temp_r0 & 0x08000008) {
        temp_r5 = *(s8 *)((u8 *)self + 0x3D);
        temp_r8 = *(s8 *)((u8 *)self + 0x3C);
        var_r6 = temp_r5 - 1;
        temp_r5 = temp_r8 * 0x80;
        var_r5 = lbl_80312ACC + temp_r5 + var_r6 * 0x10;
        while (1) {
            if (var_r6 < 0) {
                break;
            }
            if (var_r5[0xC] != 0) {
                break;
            }
            var_r5 -= 0x10;
            var_r6 -= 1;
        }
        temp_r5 = *(s8 *)((u8 *)self + 0x40);
        temp_r4 = var_r6 - temp_r5;
        if (temp_r4 < 0 || temp_r4 > 3) {
            if (!(temp_r3 & 0x08000008)) {
                return;
            }
            var_r7_2 = temp_r5 + 3;
            temp_r5 = temp_r8 * 0x80;
            var_r5_2 = lbl_80312ACC + temp_r5 + var_r7_2 * 0x10;
            while (1) {
                if (var_r7_2 < 0) {
                    break;
                }
                if (var_r5_2[0xC] != 0) {
                    break;
                }
                var_r5_2 -= 0x10;
                var_r7_2 -= 1;
            }
            var_r6 = var_r7_2;
        }
        *(u8 *)((u8 *)self + 0x3D) = (u8)var_r6;
        var_r7 = 1;
    }
    if (temp_r0 & 0x04000004) {
        temp_r5 = *(s8 *)((u8 *)self + 0x3D);
        temp_r8 = *(s8 *)((u8 *)self + 0x3C);
        var_r7_2 = temp_r5 + 1;
        temp_r5 = temp_r8 * 0x80;
        var_r4 = lbl_80312ACC + temp_r5 + var_r7_2 * 0x10;
        while (1) {
            if (var_r7_2 >= 8) {
                var_r7_2 = -1;
                break;
            }
            if (var_r4[0xC] != 0) {
                break;
            }
            var_r4 += 0x10;
            var_r7_2 += 1;
        }
        temp_r5 = *(s8 *)((u8 *)self + 0x40);
        temp_r4 = var_r7_2 - temp_r5;
        if (temp_r4 < 0 || temp_r4 > 3) {
            if (!(temp_r3 & 0x04000004)) {
                return;
            }
            var_r7_2 = temp_r5;
        }
        *(u8 *)((u8 *)self + 0x3D) = (u8)var_r7_2;
        var_r7 = 1;
    }
    if (var_r7 != 0) {
        Ui_PlaySeCue(lbl_8026E858 + 0x10F, 0x64);
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            temp_r7 = lbl_80312ACC + (*(s8 *)((u8 *)self + 0x3C) << 7)
                                  + (*(s8 *)((u8 *)self + 0x3D) << 4);
            if (*(u32 *)(temp_r7 + 4) != 0) {
                Ui_ShowUnitInfoPopup(gUnitInfoPopup, temp_r7 + 4,
                            (f32)*(s16 *)temp_r7,
                            (f32)(*(s16 *)(temp_r7 + 2) + 0x28));
            } else {
                Ui_HideUnitInfoPopup(gUnitInfoPopup);
            }
        }
    }
}

void fn_800AC400(void) {
    M2C_UNK func_8000BF00(void*);
    extern u16 lbl_8028CDF0[];
    func_8000BF00(lbl_8028CDF0);
}

void fn_800AC5DC(void *arg0) {
    void fn_800AC810(void);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_HideUnitInfoPopup(void *);
    u64 *Item_GetFlagsPtr(void *);
    s32 Msg_Expand(void *);
    void fn_80166AE8(s16, s32, s32, void *, void *);
    void Process_Goto(void *, s32);
    void Ui_PlaySeCue(void *, s32);
    void Ui_OpenUnitInfoPopup(void *, void *, void *, f32, f32);

    extern void *gPadInput;
    extern u8 gUnitInfoPopup[];
    extern u8 lbl_80312ACC[];
    extern u8 lbl_8026E858[];
    extern u32 gUnitInfoPopupFlag;

    void *self;
    u32 pressed;

    self = arg0;
    fn_800AC810();
    pressed = ((u32 *)gPadInput)[1] & (((u32 *)gPadInput)[2] ^ ((u32 *)gPadInput)[1]);
    if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
        if (pressed & 0xA00) {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
        }
    } else if (pressed & 0x100) {
        pressed = 0;
        {
            u8 *entry = lbl_80312ACC + ((s8)*(u8 *)((char *)self + 0x3C) << 7)
                                      + ((s8)*(u8 *)((char *)self + 0x3D) << 4);
            if (*(u32 *)(entry + 4) != 0) {
                if (*Item_GetFlagsPtr(entry + 4) & 0x200) {
                    pressed = 1;
                }
            }
        }
        if ((u8)pressed != 0) {
            s32 off_c;
            s32 str;
            u8 *entry;
            pressed = (s8)*(u8 *)((char *)self + 0x3D) << 4;
            off_c = (s8)*(u8 *)((char *)self + 0x3C) << 7;
            str = Msg_Expand(lbl_8026E858 + 0xE7);
            entry = lbl_80312ACC + off_c;
            fn_80166AE8(*(s16 *)(entry + pressed),
                        *(s16 *)(entry + pressed + 2) + 0x28,
                        str, self, entry);
        } else {
            Process_Goto(self, 1);
            Ui_PlaySeCue(lbl_8026E858 + 0xEF, 0x64);
        }
    } else if (pressed & 0x200) {
        Process_Goto(self, 2);
        Ui_PlaySeCue(lbl_8026E858 + 0xFF, 0x64);
    } else if (pressed & 0x800) {
        u8 *entry = lbl_80312ACC + ((s8)*(u8 *)((char *)self + 0x3C) << 7)
                                  + ((s8)*(u8 *)((char *)self + 0x3D) << 4);
        s16 x = *(s16 *)entry;
        Ui_OpenUnitInfoPopup(gUnitInfoPopup, self, entry + 4, (f32)x,
                    (f32)(*(s16 *)(entry + 2) + 0x28));
    }
    *(u32 *)gUnitInfoPopup |= gUnitInfoPopupFlag;
}

void fn_800AC810(void *arg0) {
    void Ui_PlaySeCue(void *, s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoPopup(void *, void *, f32, f32);
    extern void *gPadInput;
    extern u8 lbl_80312ACC[];
    extern u8 lbl_8026E858[];
    extern u8 gUnitInfoPopup[];
    extern f64 lbl_80369C28;
    s32 var_r8;
    s32 flags;
    s32 buttons;
    s32 pressed;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    s32 tmp;
    u8 *entry;
    s16 x;
    s16 y;

    var_r8 = 0;
    flags = *(s32 *)((u8 *)gPadInput + 0xC);
    buttons = *(s32 *)((u8 *)gPadInput + 4);
    pressed = buttons & (*(s32 *)((u8 *)gPadInput + 8) ^ buttons);
    if (flags & 0x01000001) {
        tmp = *(u8 *)((u8 *)arg0 + 0x3C);
        if (tmp == 1) {
            var_r7 = *(s8 *)((u8 *)arg0 + 0x3D);
            var_r6 = var_r7;
            var_r5 = (s32)(lbl_80312ACC + var_r7 * 0x10);
        loop1:
            if (var_r6 >= 0 && *(u8 *)(var_r5 + 0xC) == 0) {
                var_r5 -= 0x10;
                var_r6 -= 1;
                goto loop1;
            }
            var_r5 = var_r6;
            if (var_r5 < 0) {
                var_r5 = (s32)(lbl_80312ACC + var_r7 * 0x10);
            loop1b:
                if (var_r7 >= 8) {
                    var_r7 = -1;
                } else if (*(u8 *)(var_r5 + 0xC) == 0) {
                    var_r5 += 0x10;
                    var_r7 += 1;
                    goto loop1b;
                }
                var_r5 = var_r7;
            }
            if (var_r5 < 0) {
                return;
            }
            var_r8 = 1;
            *(u8 *)((u8 *)arg0 + 0x3C) = 0;
            *(u8 *)((u8 *)arg0 + 0x3D) = var_r5;
        }
    }
    if (flags & 0x02000002) {
        tmp = *(s8 *)((u8 *)arg0 + 0x3C);
        if (tmp == 0) {
            var_r6 = *(s8 *)((u8 *)arg0 + 0x3D);
            var_r7 = var_r6;
            var_r5 = (s32)(lbl_80312ACC + var_r6 * 0x10);
        loop2:
            if (var_r7 >= 0 && *(u8 *)(var_r5 + 0x8C) == 0) {
                var_r5 -= 0x10;
                var_r7 -= 1;
                goto loop2;
            }
            if (var_r7 < 0) {
                var_r5 = (s32)(lbl_80312ACC + var_r6 * 0x10);
            loop2b:
                if (var_r6 >= 8) {
                    var_r6 = -1;
                } else if (*(u8 *)(var_r5 + 0x8C) == 0) {
                    var_r5 += 0x10;
                    var_r6 += 1;
                    goto loop2b;
                }
                var_r7 = var_r6;
            }
            if (var_r7 < 0) {
                return;
            }
            var_r8 = 1;
            *(u8 *)((u8 *)arg0 + 0x3C) = 1;
            *(u8 *)((u8 *)arg0 + 0x3D) = var_r7;
        }
    }
    if (flags & 0x08000008) {
        var_r6 = *(s8 *)((u8 *)arg0 + 0x3C);
        var_r7 = *(s8 *)((u8 *)arg0 + 0x3D) - 1;
        var_r5 = (s32)(lbl_80312ACC + (var_r6 << 7) + (var_r7 * 0x10));
    loop3:
        if (var_r7 >= 0 && *(u8 *)(var_r5 + 0xC) == 0) {
            var_r5 -= 0x10;
            var_r7 -= 1;
            goto loop3;
        }
        if (var_r7 < 0) {
            if (!(pressed & 0x08000008)) {
                return;
            }
            var_r7 = 7;
            var_r5 = (s32)(lbl_80312ACC + (var_r6 << 7) + 0x70);
        loop3b:
            if (var_r7 >= 0 && *(u8 *)(var_r5 + 0xC) == 0) {
                var_r5 -= 0x10;
                var_r7 -= 1;
                goto loop3b;
            }
        }
        *(u8 *)((u8 *)arg0 + 0x3D) = var_r7;
        var_r8 = 1;
    }
    if (flags & 0x04000004) {
        var_r6 = *(s8 *)((u8 *)arg0 + 0x3C);
        tmp = *(s8 *)((u8 *)arg0 + 0x3D) + 1;
        var_r5 = (s32)(lbl_80312ACC + (var_r6 << 7) + (tmp * 0x10));
    loop4:
        if (tmp >= 8) {
            tmp = -1;
        } else if (*(u8 *)(var_r5 + 0xC) == 0) {
            var_r5 += 0x10;
            tmp += 1;
            goto loop4;
        }
        if (tmp < 0) {
            if (!(pressed & 0x04000004)) {
                return;
            }
            tmp = 0;
            var_r5 = (s32)(lbl_80312ACC + (var_r6 << 7));
        loop4b:
            if (tmp >= 8) {
                tmp = -1;
            } else if (*(u8 *)(var_r5 + 0xC) == 0) {
                var_r5 += 0x10;
                tmp += 1;
                goto loop4b;
            }
        }
        *(u8 *)((u8 *)arg0 + 0x3D) = tmp;
        var_r8 = 1;
    }
    if ((u8)var_r8 != 0) {
        Ui_PlaySeCue(lbl_8026E858 + 0x10F, 0x64);
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            entry = lbl_80312ACC + ((*(s8 *)((u8 *)arg0 + 0x3C)) << 7)
                + (*(s8 *)((u8 *)arg0 + 0x3D) * 0x10);
            x = *(s16 *)entry;
            y = *(s16 *)(entry + 2);
            Ui_ShowUnitInfoPopup(gUnitInfoPopup, entry + 4, (f32)x, (f32)(y + 0x28));
        }
    }
}

void fn_800ACCF8(void) {
    M2C_UNK fn_800ACD18();
    fn_800ACD18();
}

#pragma use_lmw_stmw on
void fn_800ACD18(void *arg0)
{
    void Math_Ease(s32, f32, f32, f32, f32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    void fn_8008B464(s32, s32, s32);
    void fn_8008BBF8(s32, s32, s32, s32, s32, u8);
    void fn_8008BE84(s16, s16);
    void fn_8008BF68(s16, s16, s32);
    void UnitRef_Draw(void *, s32, s32, s16);
    s32 fn_80093DA8(s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    extern u8 lbl_80312ACC[];
    extern u8 gUnitInfoPopup[];
    extern f64 lbl_80369C28;
    extern f32 lbl_80369C30;
    extern f32 lbl_80369C34;
    extern f32 lbl_80369C38;
    extern f32 lbl_80369C3C;
    extern f32 lbl_80369C40;
    extern f32 lbl_80369C44;
    extern f32 lbl_80369C48;
    extern f32 lbl_80369C4C;
    extern f32 lbl_80369C50;
    extern f32 lbl_80369C54;
    extern f32 lbl_80369C58;
    extern s32 lbl_8036C480;
    extern s32 lbl_8036C484;

    s32 pair1[2];
    s32 pair2[2];
    s32 *pp;
    f32 saved;
    f32 f31;
    s32 t;
    s32 sum;
    s32 tmp;
    s32 x;
    s32 col;
    u8 *row;
    s16 v38;
    s16 y28;
    s16 x27;
    s32 v27;
    u8 *ent;
    s32 i;
    u8 *ent4;
    u8 b0;
    u8 b1;

    t = *(s16 *)((u8 *)arg0 + 0x28) + 1;
    switch (*(u8 *)((u8 *)arg0 + 0x42)) {
    case 0:
        f31 = lbl_80369C30;
        break;
    case 1:
        f31 = lbl_80369C34 * (f32)(5 - t);
        break;
    case 2:
        f31 = lbl_80369C34 * (f32)t;
        break;
    default:
        f31 = lbl_80369C38;
        break;
    }

    Math_Ease(5, lbl_80369C38, lbl_80369C30, f31, lbl_80369C30);
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_80369C3C, lbl_80369C40, lbl_80369C44, lbl_80369C30);
    f31 *= lbl_80369C48;
    saved = f31;
    Prim2D_SetColorByte((s32)f31);
    Prim2D_PrepareTex();

    pp = pair1;
    v27 = *(s32 *)((u8 *)arg0 + 0x34);
    pp[0] = lbl_8036C480;
    pp[1] = lbl_8036C484;
    pp[0] = *(s32 *)((u8 *)arg0 + 0x30);
    pp[1] = v27;
    fn_8008B464(v27, 0, 0);
    fn_8008BBF8(0, 0x64, 0x108, 0x110, 0, *(u8 *)((u8 *)arg0 + 0x45));
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369C4C);
    Prim2D_PrepareTex();

    i = 0;
    ent = lbl_80312ACC + 0x80;
    do {
        ent4 = ent + 4;
        x = *(s32 *)(ent + 4);
        if (((u32)(-x | x) >> 31) != 0) {
            UnitRef_Draw(ent4, fn_80093DA8(v27), *(s16 *)ent - 0x118, *(s16 *)(ent + 2));
        }
        i += 1;
        ent += 0x10;
    } while (i < 8);

    Prim2D_Begin();
    Prim2D_SetTransform(lbl_80369C50, lbl_80369C40, lbl_80369C44, lbl_80369C30);
    f31 = saved;
    Prim2D_SetColorByte((s32)f31);
    Prim2D_PrepareTex();

    pp = pair2;
    pp[0] = lbl_8036C480;
    pp[1] = lbl_8036C484;
    pp[0] = *(s32 *)((u8 *)arg0 + 0x30);
    pp[1] = *(s32 *)((u8 *)arg0 + 0x34);
    fn_8008B464(pair2[0], 0, 0);
    fn_8008BBF8(0, 0x64, 0x108, 0x110, 0, *(u8 *)((u8 *)arg0 + 0x45));
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369C4C);
    Prim2D_PrepareTex();

    i = 0;
    ent = lbl_80312ACC;
    do {
        ent4 = ent + 4;
        x = *(s32 *)(ent + 4);
        if (((u32)(-x | x) >> 31) != 0) {
            UnitRef_Draw(ent4, fn_80093DA8(pair2[0]), *(s16 *)ent, *(s16 *)(ent + 2));
        }
        i += 1;
        ent += 0x10;
    } while (i < 8);

    Prim2D_Begin();
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();

    if (*(u8 *)((u8 *)arg0 + 0x42) == 0) {
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369C4C);
        Prim2D_PrepareTex();

        v38 = *(s16 *)((u8 *)arg0 + 0x38);
        if (v38 < 0) {
            b0 = *(u8 *)((u8 *)arg0 + 0x3C);
            b1 = *(u8 *)((u8 *)arg0 + 0x3D);
            row = lbl_80312ACC + ((s8)b0 << 7);
            col = (s8)b1 << 4;
            *(s16 *)((u8 *)arg0 + 0x38) = *(s16 *)(row + col);
            b0 = *(u8 *)((u8 *)arg0 + 0x3C);
            b1 = *(u8 *)((u8 *)arg0 + 0x3D);
            row = lbl_80312ACC + ((s8)b0 << 7);
            col = (s8)b1 << 4;
            *(s16 *)((u8 *)arg0 + 0x3A) = *(s16 *)(row + col + 2);
        } else {
            b0 = *(u8 *)((u8 *)arg0 + 0x3C);
            b1 = *(u8 *)((u8 *)arg0 + 0x3D);
            row = lbl_80312ACC + ((s8)b0 << 7);
            col = (s8)b1 << 4;
            sum = v38 + *(s16 *)(row + col);
            sum = ((u32)sum >> 31) + sum;
            *(s16 *)((u8 *)arg0 + 0x38) = sum >> 1;
            b0 = *(u8 *)((u8 *)arg0 + 0x3C);
            b1 = *(u8 *)((u8 *)arg0 + 0x3D);
            row = lbl_80312ACC + ((s8)b0 << 7);
            col = (s8)b1 << 4;
            sum = *(s16 *)((u8 *)arg0 + 0x3A) + *(s16 *)(row + col + 2);
            sum = ((u32)sum >> 31) + sum;
            *(s16 *)((u8 *)arg0 + 0x3A) = sum >> 1;
        }

        b0 = *(u8 *)((u8 *)arg0 + 0x3E);
        b1 = *(u8 *)((u8 *)arg0 + 0x3F);
        row = lbl_80312ACC + ((s8)b0 << 7);
        col = (s8)b1 << 4;
        tmp = (s32)(row + col);
        x27 = *(s16 *)(row + col);
        y28 = *(s16 *)(tmp + 2);

        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369C54);
        Prim2D_PrepareTex();
        fn_8008BF68(*(s16 *)((u8 *)arg0 + 0x38), *(s16 *)((u8 *)arg0 + 0x3A), Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369C58);
        Prim2D_PrepareTex();

        if (*(u8 *)((u8 *)arg0 + 0x41) == 1) {
            fn_8008BE84(x27, y28);
            Prim2D_Begin();
            Prim2D_AddZ(lbl_80369C30);
            Prim2D_PrepareTex();
            fn_8008AB7C(x27 + 0x74, y28 + 0xD, 0xED, 0x18, 0x19, 0x4B, 0);
            Prim2D_Begin();
            Prim2D_AddZ(lbl_80369C4C);
            Prim2D_PrepareTex();
        }

        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369C30);
        Prim2D_PrepareTex();
        b0 = *(u8 *)((u8 *)arg0 + 0x3C);
        b1 = *(u8 *)((u8 *)arg0 + 0x3D);
        row = lbl_80312ACC + ((s8)b0 << 7);
        col = (s8)b1 << 4;
        fn_8008AB7C(*(s16 *)(row + col) + 0x74, *(s16 *)((u8 *)arg0 + 0x3A) + 0xD, 0xED, 0x18, 0x19, 0x4B, 1);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369C4C);
        Prim2D_PrepareTex();
    }
}
#include "common.h"

#pragma use_lmw_stmw on

extern u8 lbl_80312ACC[];
