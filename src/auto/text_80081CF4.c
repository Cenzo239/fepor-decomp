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

#pragma use_lmw_stmw on
void fn_80081CF4(void *arg0) {
extern f32 lbl_8036948C, lbl_80369494, lbl_8036955C, lbl_8036942C, lbl_80369528, lbl_803695AC, lbl_803695B0, lbl_80369430;
extern f64 lbl_80369470;
extern void *Unit_GetItemSlot(void *, s32);
extern s32 fn_80093DA8(void *);
extern void fn_80086020(s32, s32, f32, f32, f32, f32);
extern void UnitRef_Draw(void *, s32, s32, s32);
s32 off;
s32 x;
void *unit;
void *slot;
s32 i;
f32 row0;
f32 row1;
f32 y;
f32 xpos;
u32 item;

y = *(f32 *)((u8 *)arg0 + 0x18);
xpos = lbl_8036948C + *(f32 *)((u8 *)arg0 + 0x14);
unit = *(void **)((u8 *)arg0 + 0x58);
fn_80086020(0xb3, 0, xpos, y, lbl_80369494, lbl_8036955C);
Prim2D_Begin();
Prim2D_AddZ(lbl_8036942C);
Prim2D_PrepareTex();
x = (s32)(lbl_80369528 + xpos);
row0 = lbl_803695AC + y;
row1 = lbl_803695B0 + y;
i = 0;
off = 0;
do {
    item = *(u32 *)(slot = Unit_GetItemSlot(unit, i));
    if (item != 0) {
        if (i < 4) {
            y = row0 + (f32)off;
        } else {
            y = row1 + (f32)((i - 4) * 28);
        }
        UnitRef_Draw(slot, fn_80093DA8(unit), x, (s32)y);
    }
    i++;
    off += 28;
} while (i < 8);
Prim2D_Begin();
Prim2D_AddZ(lbl_80369430);
Prim2D_PrepareTex();
}

void fn_80081E68(s32 arg0, u16 *arg1, f32 farg0, f32 farg1) {
    extern char gUiStrings[];
    extern f32 lbl_80369578;
    void Prim2D_Begin(void);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    const char *Msg_Expand(const char *);
    void fn_8001003C(s32, s32, s32, s32, s32, f32, f32, const char *, ...);
    f32 x;
    s32 count;

    count = 0;
    x = 50.0f + farg0;
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    if (*arg1 & 0x20) {
        fn_8001003C((s32)(x + count * 90.0f), (s32)farg1, 2, 0, 0, 1.0f, 0.0f, Msg_Expand(gUiStrings + 0x289));
        count++;
    }
    if (*arg1 & 0x10) {
        fn_8001003C((s32)(x + count * lbl_80369578), (s32)farg1, 2, 0, 0, 1.0f, 0.0f, Msg_Expand(gUiStrings + 0x292));
        count++;
    }
    if (*arg1 & 4) {
        fn_8001003C((s32)(x + count * lbl_80369578), (s32)farg1, 2, 0, 0, 1.0f, 0.0f, Msg_Expand(gUiStrings + 0x29B));
        count++;
    }
    if (*arg1 & 8) {
        fn_8001003C((s32)(x + count * lbl_80369578), (s32)farg1, 2, 0, 0, 1.0f, 0.0f, Msg_Expand(gUiStrings + 0x2A4));
        count++;
    }
    if (*arg1 & 0x40) {
        fn_8001003C((s32)(x + count * lbl_80369578), (s32)farg1, 2, 0, 0, 1.0f, 0.0f, Msg_Expand(gUiStrings + 0x2AD));
        count++;
    }
    if (*arg1 & 0x100) {
        fn_8001003C((s32)(x + count * lbl_80369578), (s32)farg1, 2, 0, 0, 1.0f, 0.0f, Msg_Expand(gUiStrings + 0x2B8));
        count++;
    }
    if (*arg1 & 2) {
        fn_8001003C((s32)(x + count * lbl_80369578), (s32)farg1, 2, 0, 0, 1.0f, 0.0f, Msg_Expand(gUiStrings + 0x2C2));
        count++;
    }
    if (*arg1 & 0x80) {
        fn_8001003C((s32)(x + count * lbl_80369578), (s32)farg1, 2, 0, 0, 1.0f, 0.0f, Msg_Expand(gUiStrings + 0x2CB));
    }
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
static inline u8 UiBattle_MaxRange(void *battle) {
    s32 Item_GetMaxRange(void *);
    void *item = *(void **)((u8 *)battle + 0x28C);
    return item ? (u8)Item_GetMaxRange(item) : 0;
}
static inline u8 UiBattle_MinRange(void *battle) {
    void *item = *(void **)((u8 *)battle + 0x28C);
    return item ? *((u8 *)item + 0x1D) : 0;
}
void fn_80082298(void *arg0, s32 arg1, f32 farg0, f32 farg1) {
    typedef struct { u8 r, g, b, a; } Color;
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    s32 Item_GetMaxRange(void *);
    u32 Unit_GetActiveItemPtr(void *);
    u16 **fn_8006EDD8(s32, s32);
    void fn_80081E68(void *, void *, f32, f32);
    Color *Ui_GetColor(s32);
    s32 Str_Cmp(void *, void *);
    extern u8 gUiStrings[];
    extern s32 gUiAtlas;
    extern f32 lbl_80369418;
    extern f32 lbl_8036942C;
    extern f32 lbl_80369430;
    extern f32 lbl_80369434;
    extern f32 lbl_8036944C;
    extern f32 lbl_8036951C;
    extern f32 lbl_80369524;
    extern f32 lbl_80369528;
    extern f32 lbl_80369594;
    extern f32 lbl_8036959C;
    extern f32 lbl_803695A8;
    extern f32 lbl_803695B4;
    extern f32 lbl_803695B8;
    extern f32 lbl_803695BC;
    extern f32 lbl_803695C0;
    extern f32 lbl_803695C4;
    extern f64 lbl_80369440;

    s16 a, b;
    f32 h, y, x;
    Color color;
    f32 w;
    f32 sw;
    f32 sh;
    u16 *tex;
    s32 id;
    f64 magic_u;

    x = farg0;
    y = farg1;
    tex = *fn_8006EDD8(gUiAtlas, 0x19);
    magic_u = lbl_80369440;
    (void)magic_u;
    sh = (f32)(u32)tex[0] * lbl_80369430;
    sw = (f32)(u32)tex[1] * lbl_80369430;
    color = *Ui_GetColor(1);
    tex = *fn_8006EDD8((id = gUiAtlas), 0x19);
    w = (f32)(u32)tex[1];
    h = (f32)(u32)tex[0];
    Prim2D_Begin();
    Prim2D_BindTexture(id, 0x19, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_80369418);
    Prim2D_SetQuadMin(x, y, lbl_80369418, lbl_80369418);
    Prim2D_SetQuadMax(x + sw, y + sh, w, h);
    Prim2D_SetColor(color.r, color.g, color.b, 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036942C);
    Prim2D_PrepareTex();

{
    s16 val;
    val = *(s16 *)((u8 *)arg0 + 0x298);
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    if (((u8)arg1 == 1) && (Unit_GetActiveItemPtr(arg0) == 0)) {
        fn_8001003C((s32)(lbl_80369524 + (lbl_803695C0 + x)), (s32)(lbl_803695C0 + y), 2, 0, 0, gUiStrings + 0x2DF, lbl_80369430, lbl_80369418);
    } else if (Str_Cmp(gUiStrings + 0x2EF, gUiStrings + 0x2E4) == 0) {
        if (val == 0) {
            fn_8001003C((s32)(lbl_8036944C + (lbl_803695C0 + x)), (s32)(lbl_803695C0 + y), 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, val);
        } else {
            f32 ay, ax, bx;
            ax = lbl_803695C0 + x;
            ay = lbl_803695C0 + y;
            fn_8001003C((s32)(lbl_80369528 + ax), (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, val);
            bx = lbl_803695B8 + ax;
            fn_8001003C((s32)bx, (s32)(ay - lbl_8036951C), 2, 0, 0, gUiStrings + 0x15, lbl_80369430, lbl_80369418);
            fn_8001003C((s32)bx, (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, 0);
        }
    } else {
        fn_8001003C((s32)(lbl_8036959C + (lbl_803695C0 + x)), (s32)(lbl_803695C0 + y), 2, 0, 0, gUiStrings + 0x2EB, lbl_80369430, lbl_80369418, val);
    }

}
{
    s16 val;
    val = *(s16 *)((u8 *)arg0 + 0x29E);
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    if (((u8)arg1 == 1) && (Unit_GetActiveItemPtr(arg0) == 0)) {
        fn_8001003C((s32)(lbl_80369524 + (lbl_803695A8 + x)), (s32)(lbl_803695C0 + y), 2, 0, 0, gUiStrings + 0x2DF, lbl_80369430, lbl_80369418);
    } else if (Str_Cmp(gUiStrings + 0x2F6, gUiStrings + 0x2E4) == 0) {
        if (val == 0) {
            fn_8001003C((s32)(lbl_8036944C + (lbl_803695A8 + x)), (s32)(lbl_803695C0 + y), 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, val);
        } else {
            f32 ay, ax, bx;
            ax = lbl_803695A8 + x;
            ay = lbl_803695C0 + y;
            fn_8001003C((s32)(lbl_80369528 + ax), (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, val);
            bx = lbl_803695B8 + ax;
            fn_8001003C((s32)bx, (s32)(ay - lbl_8036951C), 2, 0, 0, gUiStrings + 0x15, lbl_80369430, lbl_80369418);
            fn_8001003C((s32)bx, (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, 0);
        }
    } else {
        fn_8001003C((s32)(lbl_8036959C + (lbl_803695A8 + x)), (s32)(lbl_803695C0 + y), 2, 0, 0, gUiStrings + 0x2EB, lbl_80369430, lbl_80369418, val);
    }

}
{
    s16 val;
    val = *(s16 *)((u8 *)arg0 + 0x2A0);
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    if (Str_Cmp(gUiStrings + 0x2FD, gUiStrings + 0x2E4) == 0) {
        if (val == 0) {
            fn_8001003C((s32)(lbl_8036944C + (lbl_80369594 + x)), (s32)(lbl_803695C0 + y), 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, val);
        } else {
            f32 ay, ax, bx;
            ax = lbl_80369594 + x;
            ay = lbl_803695C0 + y;
            fn_8001003C((s32)(lbl_80369528 + ax), (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, val);
            bx = lbl_803695B8 + ax;
            fn_8001003C((s32)bx, (s32)(ay - lbl_8036951C), 2, 0, 0, gUiStrings + 0x15, lbl_80369430, lbl_80369418);
            fn_8001003C((s32)bx, (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, 0);
        }
    } else {
        fn_8001003C((s32)(lbl_8036959C + (lbl_80369594 + x)), (s32)(lbl_803695C0 + y), 2, 0, 0, gUiStrings + 0x2EB, lbl_80369430, lbl_80369418, val);
    }

}
{
    s16 val;
    val = *(s16 *)((u8 *)arg0 + 0x2A4);
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    if (((u8)arg1 == 1) && (Unit_GetActiveItemPtr(arg0) == 0)) {
        fn_8001003C((s32)(lbl_80369524 + (lbl_803695C0 + x)), (s32)(lbl_803695B4 + y), 2, 0, 0, gUiStrings + 0x2DF, lbl_80369430, lbl_80369418);
    } else if (Str_Cmp(gUiStrings + 0x304, gUiStrings + 0x2E4) == 0) {
        if (val == 0) {
            fn_8001003C((s32)(lbl_8036944C + (lbl_803695C0 + x)), (s32)(lbl_803695B4 + y), 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, val);
        } else {
            f32 ay, ax, bx;
            ax = lbl_803695C0 + x;
            ay = lbl_803695B4 + y;
            fn_8001003C((s32)(lbl_80369528 + ax), (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, val);
            bx = lbl_803695B8 + ax;
            fn_8001003C((s32)bx, (s32)(ay - lbl_8036951C), 2, 0, 0, gUiStrings + 0x15, lbl_80369430, lbl_80369418);
            fn_8001003C((s32)bx, (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, 0);
        }
    } else {
        fn_8001003C((s32)(lbl_8036959C + (lbl_803695C0 + x)), (s32)(lbl_803695B4 + y), 2, 0, 0, gUiStrings + 0x2EB, lbl_80369430, lbl_80369418, val);
    }

}
{
    s16 val;
    val = *(s16 *)((u8 *)arg0 + 0x2A6);
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    if (Str_Cmp(gUiStrings + 0x30C, gUiStrings + 0x2E4) == 0) {
        if (val == 0) {
            fn_8001003C((s32)(lbl_8036944C + (lbl_803695A8 + x)), (s32)(lbl_803695B4 + y), 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, val);
        } else {
            f32 ay, ax, bx;
            ax = lbl_803695A8 + x;
            ay = lbl_803695B4 + y;
            fn_8001003C((s32)(lbl_80369528 + ax), (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, val);
            bx = lbl_803695B8 + ax;
            fn_8001003C((s32)bx, (s32)(ay - lbl_8036951C), 2, 0, 0, gUiStrings + 0x15, lbl_80369430, lbl_80369418);
            fn_8001003C((s32)bx, (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, 0);
        }
    } else {
        fn_8001003C((s32)(lbl_8036959C + (lbl_803695A8 + x)), (s32)(lbl_803695B4 + y), 2, 0, 0, gUiStrings + 0x2EB, lbl_80369430, lbl_80369418, val);
    }

}
    if (*(void **)((u8 *)arg0 + 0x28C) != 0) {
        a = (u8)Item_GetMaxRange(*(void **)((u8 *)arg0 + 0x28C));
    } else {
        a = 0;
    }
    if (*(void **)((u8 *)arg0 + 0x28C) != 0) {
        b = *((u8 *)*(void **)((u8 *)arg0 + 0x28C) + 0x1D);
    } else {
        b = 0;
    }
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    if (((u8)arg1 == 1) && (Unit_GetActiveItemPtr(arg0) == 0)) {
        fn_8001003C((s32)(lbl_80369524 + (lbl_80369594 + x)), (s32)(lbl_803695B4 + y), 2, 0, 0, gUiStrings + 0x2DF, lbl_80369430, lbl_80369418);
    } else if (Str_Cmp(gUiStrings + 0x2E4, gUiStrings + 0x2E4) == 0) {
        if (b == a) {
            fn_8001003C((s32)(lbl_8036944C + (lbl_80369594 + x)), (s32)(lbl_803695B4 + y), 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, b);
        } else {
            f32 ay, ax, bx;
            ax = lbl_80369594 + x;
            ay = lbl_803695B4 + y;
            fn_8001003C((s32)(lbl_80369528 + ax), (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, b);
            bx = lbl_803695B8 + ax;
            fn_8001003C((s32)bx, (s32)(ay - lbl_8036951C), 2, 0, 0, gUiStrings + 0x15, lbl_80369430, lbl_80369418);
            if (a >= 0xA) {
                fn_8001003C((s32)(lbl_803695BC + ax), (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, a);
            } else {
                fn_8001003C((s32)bx, (s32)ay, 2, 0, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, a);
            }
        }
    } else {
        fn_8001003C((s32)(lbl_8036959C + (lbl_80369594 + x)), (s32)(lbl_803695B4 + y), 2, 0, 0, gUiStrings + 0x2EB, lbl_80369430, lbl_80369418, b);
    }

    fn_80081E68(gUiStrings + 0x314, (u8 *)arg0 + 0x2AE, lbl_80369434 + x, lbl_803695C4 + y);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369430);
    Prim2D_PrepareTex();
}
#pragma pop
void fn_80083278(void *arg0) {
extern u8 gBattle[];
extern const f32 lbl_80369430, lbl_803695C8;
f64 x=lbl_80369430;
f32 y=lbl_803695C8;
x=(f32)x+*(f32*)((u8*)arg0+0x14);
y+=*(f32*)((u8*)arg0+0x18);
fn_80082298(gBattle,1,x,y);
}
  
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma use_lmw_stmw off
#pragma opt_loop_invariants off
void fn_800832C0(void *arg0, f32 farg0, f32 farg1) {
    typedef struct { u8 r, g, b, a; } Color;
    void fn_800875B4(s32, s32, f32, f32, f32, f32);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddZ(f32);
    void *Msg_Expand(void *);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_EndPrim(void);
    u16 **fn_8006EDD8(s32, s32);
    Color *Ui_GetColor(s32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    void fn_80087F50(s32, f32, f32);
    s8 Unit_GetCarryWtLimit(void *);
    s8 Unit_GetStr(void *);
    s8 Unit_GetMagAtk(void *);
    s8 Unit_GetMag(void *);
    s8 fn_8003AF28(void *);
    s8 Unit_GetSkl(void *);
    s8 fn_8003AEB0(void *);
    s8 Unit_GetSpd(void *);
    s8 fn_8003ACF8(void *);
    s8 Unit_GetLck(void *);
    s8 fn_8003AA40(void *);
    s8 Unit_GetDef(void *);
    s8 fn_8003A778(void *);
    s8 Unit_GetRes(void *);
    extern u8 gUiStrings[];
    extern s32 gUiAtlas;
    extern f32 lbl_80369418;
    extern f32 lbl_8036942C;
    extern f32 lbl_80369430;
    extern f32 lbl_80369434;
    extern f32 lbl_80369438;
    extern f32 lbl_8036943C;
    extern f32 lbl_8036944C;
    extern f32 lbl_803694A4;
    extern f32 lbl_803694C4;
    extern f32 lbl_803694D4;
    extern f32 lbl_803694E4;
    extern f32 lbl_8036951C;
    extern f32 lbl_80369574;
    extern f32 lbl_80369578;
    extern f32 lbl_8036958C;
    extern f32 lbl_803695CC;
    extern f32 lbl_803695D0;
    extern f32 lbl_803695D4;
    extern f32 lbl_803695D8;
    extern f32 lbl_803695DC;
    extern f64 lbl_80369440;
    f32 h;
    f32 x;
    Color color;
    f32 y;
    f32 w;
    f32 sw;
    f32 sh;
    f32 tx;
    f32 by;
    f32 bx;
    u16 *tex;
    s32 id;
    void *str;
    u8 col;
    s32 lim;
    s8 cur;
    s8 mx;
    f64 magic_u;

    x = farg0;
    y = farg1;
    fn_800875B4(0xB3, 0, x, y, lbl_803694C4, lbl_803695D4);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036942C);
    Prim2D_PrepareTex();
    str = Msg_Expand(gUiStrings + 0x31B);
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    bx = lbl_8036943C + x;
    by = lbl_80369438 + y;
    Prim2D_SetRect(bx, by, lbl_803694D4, lbl_80369434);
    Prim2D_EmitQuad();
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_EndPrim();
    tex = *fn_8006EDD8(gUiAtlas, 0x1D);
    magic_u = lbl_80369440;
    (void)magic_u;
    sh = (f32)tex[0] * lbl_80369430;
    sw = (f32)tex[1] * lbl_80369430;
    color = *Ui_GetColor(1);
    tex = *fn_8006EDD8((id = gUiAtlas), 0x1D);
    w = (f32)tex[1];
    h = (f32)tex[0];
    Prim2D_Begin();
    Prim2D_BindTexture(id, 0x1D, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_80369418);
    tx = bx + lbl_803694D4;
    Prim2D_SetQuadMin(tx, by, lbl_80369418, lbl_80369418);
    Prim2D_SetQuadMax(tx + sw, by + sh, w, h);
    Prim2D_SetColor(color.r, color.g, color.b, 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036942C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    fn_8001003C((s32)(lbl_80369438 + bx), (s32)(by - lbl_8036943C), 9, 0, 0, str, lbl_80369430, lbl_80369418);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369430);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    {
        f32 sy, sx, y2, vx, barx, bary, y3, sx2, sy2, vx2, barx2, bary2, bary3;

        lim = *(s8 *)(*(u8 **)((u8 *)arg0 + 0x18C) + 0x4D);
        mx = Unit_GetCarryWtLimit(arg0);
        cur = Unit_GetStr(arg0);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_803695CC);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        str = Msg_Expand(gUiStrings + 0x329);
        sx = lbl_803695D8 + x;
        sy = lbl_8036944C + y;
        fn_8001003C((s32)sx, (s32)sy, 6, 1, 0, str, lbl_80369430, lbl_80369418);
        col = 1;
        if (cur >= lim) {
            col = 0x22;
        }
        lim = cur;
        vx = lbl_8036958C + sx;
        fn_8001003C((s32)vx, (s32)sy, col, 1, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, lim);
        barx = lbl_803695D0 + sx;
        bary = lbl_803694E4 + sy;
        fn_80087F50(mx - lim, barx, bary);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036951C);
        Prim2D_PrepareTex();

        lim = *(s8 *)(*(u8 **)((u8 *)arg0 + 0x18C) + 0x4E);
        mx = Unit_GetMagAtk(arg0);
        cur = Unit_GetMag(arg0);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_803695CC);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        str = Msg_Expand(gUiStrings + 0x330);
        y2 = lbl_80369574 + y;
        fn_8001003C((s32)sx, (s32)y2, 6, 1, 0, str, lbl_80369430, lbl_80369418);
        col = 1;
        if (cur >= lim) {
            col = 0x22;
        }
        lim = cur;
        fn_8001003C((s32)vx, (s32)y2, col, 1, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, lim);
        bary2 = lbl_803694E4 + y2;
        fn_80087F50(mx - lim, barx, bary2);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036951C);
        Prim2D_PrepareTex();

        lim = *(s8 *)(*(u8 **)((u8 *)arg0 + 0x18C) + 0x4F);
        mx = fn_8003AF28(arg0);
        cur = Unit_GetSkl(arg0);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_803695CC);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        str = Msg_Expand(gUiStrings + 0x338);
        y3 = lbl_80369578 + y;
        fn_8001003C((s32)sx, (s32)y3, 6, 1, 0, str, lbl_80369430, lbl_80369418);
        col = 1;
        if (cur >= lim) {
            col = 0x22;
        }
        lim = cur;
        fn_8001003C((s32)vx, (s32)y3, col, 1, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, lim);
        bary3 = lbl_803694E4 + y3;
        fn_80087F50(mx - lim, barx, bary3);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036951C);
        Prim2D_PrepareTex();

        lim = *(s8 *)(*(u8 **)((u8 *)arg0 + 0x18C) + 0x50);
        mx = fn_8003AEB0(arg0);
        cur = Unit_GetSpd(arg0);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_803695CC);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        str = Msg_Expand(gUiStrings + 0x340);
        sx2 = lbl_803695DC + x;
        sy2 = lbl_803694A4 + y;
        fn_8001003C((s32)sx2, (s32)sy2, 6, 1, 0, str, lbl_80369430, lbl_80369418);
        col = 1;
        if (cur >= lim) {
            col = 0x22;
        }
        lim = cur;
        vx2 = lbl_8036958C + sx2;
        fn_8001003C((s32)vx2, (s32)sy2, col, 1, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, lim);
        barx2 = lbl_803695D0 + sx2;
        fn_80087F50(mx - lim, barx2, lbl_803694E4 + sy2);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036951C);
        Prim2D_PrepareTex();

        mx = fn_8003ACF8(arg0);
        cur = Unit_GetLck(arg0);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_803695CC);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        str = Msg_Expand(gUiStrings + 0x349);
        fn_8001003C((s32)sx2, (s32)sy, 6, 1, 0, str, lbl_80369430, lbl_80369418);
        col = 1;
        if (cur >= 0x28) {
            col = 0x22;
        }
        lim = cur;
        fn_8001003C((s32)vx2, (s32)sy, col, 1, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, lim);
        fn_80087F50(mx - lim, barx2, bary);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036951C);
        Prim2D_PrepareTex();

        lim = *(s8 *)(*(u8 **)((u8 *)arg0 + 0x18C) + 0x52);
        mx = fn_8003AA40(arg0);
        cur = Unit_GetDef(arg0);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_803695CC);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        str = Msg_Expand(gUiStrings + 0x351);
        fn_8001003C((s32)sx2, (s32)y2, 6, 1, 0, str, lbl_80369430, lbl_80369418);
        col = 1;
        if (cur >= lim) {
            col = 0x22;
        }
        lim = cur;
        fn_8001003C((s32)vx2, (s32)y2, col, 1, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, lim);
        fn_80087F50(mx - lim, barx2, bary2);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036951C);
        Prim2D_PrepareTex();

        lim = *(s8 *)(*(u8 **)((u8 *)arg0 + 0x18C) + 0x53);
        mx = fn_8003A778(arg0);
        cur = Unit_GetRes(arg0);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_803695CC);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        str = Msg_Expand(gUiStrings + 0x358);
        fn_8001003C((s32)sx2, (s32)y3, 6, 1, 0, str, lbl_80369430, lbl_80369418);
        col = 1;
        if (cur >= lim) {
            col = 0x22;
        }
        lim = cur;
        fn_8001003C((s32)vx2, (s32)y3, col, 1, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, lim);
        fn_80087F50(mx - lim, barx2, bary3);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036951C);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369430);
        Prim2D_PrepareTex();
    }
}
#pragma pop
