/* Functions from 0x800A9488 to 0x800AD1F4, found by decomp-toolkit. */
#include "common.h"
#pragma cplusplus on
extern "C" void Item_Init(void *);
extern "C" void Item_Destroy(void *, s32);
struct ItemABA {
    u32 unk0, unk4;
    ItemABA() { Item_Init(this); }
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

#pragma cplusplus on
extern "C" void fn_800A94C0(void *arg0) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetText(void *);
    s32 Text_MeasureWidth(void *, s32, f32);
    struct Obj {
        u8 pad[4];
        virtual void *v0() = 0;
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
        virtual void v25() = 0;
        virtual void v26() = 0;
        virtual void v27() = 0;
        virtual void v28() = 0;
        virtual void v29() = 0;
    };
    extern s32 gUiRouteAtlas;
    extern f32 lbl_80369BA8;
    extern f32 lbl_80369C14;
    extern f32 gOptionsIdentityScale;
    extern f32 lbl_80369C18;
    struct {
        u8 buf[0x20];
        u16 w;
        u16 h;
    } sp;
    f32 x;
    Obj *self = (Obj *)arg0;

    self->v29();
    Ui_LoadAtlasTex(gUiRouteAtlas, sp.buf, 0x15);
    sp.w = GXGetTexObjWidth(sp.buf);
    sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin();
    Prim2D_SetTex(sp.buf, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect(lbl_80369BA8, lbl_80369BA8, (f32)sp.w, (f32)sp.h);
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369C14);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    x = (f32)(0xB3 - (Text_MeasureWidth(self->v0(), -1, gOptionsIdentityScale) / 2));
    Prim2D_AddPrim(6);
    Prim2D_SetPos(x, lbl_80369C18);
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_SetText(self->v0());
    Prim2D_EndPrim();
}
#pragma cplusplus reset

void *fn_800A9638(void) {
    extern u8 gOptionsStr[];
    return (void *)((u32)gOptionsStr + 0x110);
}

s32 fn_800A9648(void) {
    M2C_UNK Game_SetState(M2C_UNK);
    Game_SetState(5);
    return 5;
}

void *fn_800A9670(void) {
    extern u8 gOptionsStr[];
    return (void *)((u32)gOptionsStr + 0x110);
}

s32 fn_800A9680(void) {
    Game_SetState(5);
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

extern "C" void fn_800A9950(void *unused, void *node) {
void *GfxEnt_Get(u8);
void Prim2D_Begin(void);
void Prim2D_SetTransform(f32,f32,f32,f32);
void Prim2D_SetTex(s32,s32);
void Prim2D_PrepareTex(void);
void Prim2D_AddPrim(s32);
void Prim2D_SetRect(f32,f32,f32,f32);
void Prim2D_EmitQuad(void);
void Prim2D_SetCornerColors(s32*,s32*,s32*,s32*);
void Prim2D_EndPrim(void);
extern f32 gOptionsIdentityScale,lbl_80369BA8;
extern s32 lbl_80369B94,lbl_80369B90,lbl_80369B8C,lbl_80369B88;
#pragma cplusplus on
struct Model {u8 pad[4];
virtual void v0()=0;
virtual void v1()=0;
virtual void v2()=0;
virtual void v3()=0;
virtual void v4()=0;
virtual void v5()=0;
virtual void v6()=0;
virtual void v7()=0;
virtual void v8()=0;
virtual void v9()=0;
virtual void v10()=0;
virtual void v11()=0;
virtual void v12()=0;
virtual void v13()=0;
virtual void v14()=0;
virtual void v15()=0;
virtual void v16()=0;
virtual s16 v17()=0;
virtual void v18()=0;
virtual void v19()=0;
virtual s16 v20()=0;
virtual void v21()=0;
virtual void v22()=0;
virtual void v23()=0;
virtual void v24()=0;
virtual f32 v25()=0;
};
struct Entry { u8 pad[0x40]; u8 id; };
s32 tl,tr,bl,br;
u8 *base;
s8 off;
base = (u8 *)node;
off = *(s8 *)(base + 0x62);
base += off;
u8 *ent = (u8 *)GfxEnt_Get(((Entry *)base)->id);
s16 y = *(s16 *)(ent + 0x32) + (*(Model **)((u8 *)node + 0x3C))->v17();
s16 old = *(s16 *)((u8 *)node + 0x3A);
if (old < 0) *(s16 *)((u8 *)node + 0x3A) = y;
else *(s16 *)((u8 *)node + 0x3A) = (old + y) / 2;
Prim2D_Begin();
Prim2D_SetTransform((f32)*(s16 *)((u8 *)node + 0x30), (f32)*(s16 *)((u8 *)node + 0x32), (*(Model **)((u8 *)node + 0x3C))->v25() - gOptionsIdentityScale, gOptionsIdentityScale);
Prim2D_SetTex(0, 0x12);
Prim2D_PrepareTex();
Prim2D_AddPrim(3);
Prim2D_SetRect(lbl_80369BA8, (f32)*(s16 *)((u8 *)node + 0x3A), (f32)*(s16 *)((u8 *)node + 0x34), (f32)(*(Model **)((u8 *)node + 0x3C))->v20());
Prim2D_EmitQuad();
br = lbl_80369B94; bl = lbl_80369B90; tr = lbl_80369B8C; tl = lbl_80369B88;
Prim2D_SetCornerColors(&tl, &tr, &bl, &br);
Prim2D_EndPrim();
#pragma cplusplus reset
}

#pragma cplusplus reset

void *fn_800A9AFC(void) {
    extern char gOptionsStr[];
    return &gOptionsStr[0x19B];
}

s32 fn_800A9B0C(void) {
    M2C_UNK fn_800EB884();
    fn_800EB884();
    Game_SetState(3);
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
    Game_SetState(3);
    return 5;
}

void *fn_800A9C9C(void) {
    extern u16 gOptionsStr[];
    return (u8 *)gOptionsStr + 0x1be;
}

s32 fn_800A9CAC(void) {
    M2C_UNK fn_800EBACC(M2C_UNK, M2C_UNK);
    fn_800EBACC(0, 0);
    Game_SetState(3);
    return 5;
}

void *fn_800A9CE0(void) {
    extern u16 gOptionsStr[];
    return (u8 *)gOptionsStr + 0x1d2;
}

s32 fn_800A9CF0(void) {
    M2C_UNK fn_800EBD78(M2C_UNK, M2C_UNK);
    fn_800EBD78(0, 0);
    Game_SetState(3);
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
    Game_SetState(4);
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
    Game_SetState(2);
    return 5;
}

void *fn_800A9DC8(void) {
    extern u16 gOptionsStr[];
    return &gOptionsStr[0x105];
}

s32 fn_800A9DD8(void) {
    Game_SetState(5);
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

void fn_800A9EA0(void *arg0, void *parent, void *item) {
void Prim2D_Begin(void);
void Prim2D_SetTransform(f32,f32,f32,f32);
void Prim2D_SetTex(s32,s32);
void Prim2D_PrepareTex(void);
void Prim2D_AddPrim(s32);
void Prim2D_SetPos(f32,f32);
void Prim2D_SetColor(s32,s32,s32,s32);
void Prim2D_SetText(void *);
void Prim2D_SetScale(f32);
void Prim2D_EndPrim(void);
void *fn_80019ED0(s32);
s32 fn_801662F0(void);
s32 sprintf(char *,const char*,...);
extern u8 gOptionsStr[];
extern f32 gOptionsIdentityScale,gOptionsZBias,gOptionsTextScale;
#pragma cplusplus on
struct Model {u8 pad[4];
virtual void v0()=0;
virtual void v1()=0;
virtual void v2()=0;
virtual void v3()=0;
virtual void v4()=0;
virtual void v5()=0;
virtual void v6()=0;
virtual void v7()=0;
virtual void v8()=0;
virtual void v9()=0;
virtual void v10()=0;
virtual void v11()=0;
virtual void v12()=0;
virtual void v13()=0;
virtual void v14()=0;
virtual void v15()=0;
virtual void v16()=0;
virtual void v17()=0;
virtual void v18()=0;
virtual void v19()=0;
virtual void v20()=0;
virtual void v21()=0;
virtual void v22()=0;
virtual void v23()=0;
virtual void v24()=0;
virtual f32 v25()=0;
};
struct Drawer {
virtual void v0()=0;
virtual void v1()=0;
virtual void v2()=0;
virtual void v3()=0;
virtual void *v4(void*)=0;
};
char text[64];
s32 number;
u8 value;
u8 *info;
Prim2D_Begin();
Prim2D_SetTransform((f32)*(s16*)((u8*)parent+0x30),(f32)*(s16*)((u8*)parent+0x32),(*(Model**)((u8*)parent+0x3C))->v25()-gOptionsZBias,gOptionsIdentityScale);
Prim2D_SetTex(0,0x13);
Prim2D_PrepareTex();
Prim2D_AddPrim(5);
Prim2D_SetPos((f32)*(s16*)((u8*)item+0x30),(f32)*(s16*)((u8*)item+0x32));
Prim2D_SetColor(0,0,0,255);
Prim2D_SetText((*(Drawer**)((u8*)item+0x34))->v4(item));
Prim2D_SetScale(gOptionsTextScale);
Prim2D_EndPrim();
info=(u8*)fn_80019ED0(*(s8*)((u8*)arg0+4));
number=*(s32*)(info+4);
value=info[0x3C];
sprintf(text,(char*)gOptionsStr+0x213,value,number,fn_801662F0());
Prim2D_AddPrim(5);
Prim2D_SetPos((f32)*(s16*)((u8*)item+0x30),(f32)*(s16*)((u8*)item+0x32));
Prim2D_SetColor(0,0,0,255);
Prim2D_SetText(text);
Prim2D_SetScale(gOptionsTextScale);
Prim2D_EndPrim();
#pragma cplusplus reset
}

s32 fn_800AA078(void *arg0) {
    s32 fn_8000CEE4(M2C_UNK);
    void fn_80016DE0(void);
    void *fn_80019ED0(s32);
    void fn_8014D2B0(void *, u8);
    void fn_8014D698(void *, u8, M2C_UNK, M2C_UNK, M2C_UNK);
    void fn_80006220(s32);
    struct BS { u8 pad[0x3C]; u8 phase; };
    extern struct BS gBattleState;
    extern u64 lbl_80331FB8[];
    u8 *s = (u8 *)&gBattleState;
    u8 saved;

    saved = s[0xA6];
    fn_80016DE0();
    fn_8014D698(&gBattleState, (u8)(fn_8000CEE4(0x1E) + 1), 0, 0, 1);
    s[0xA6] = saved;
    fn_8014D2B0(&gBattleState, ((struct BS *)fn_80019ED0(M2C_FIELD(arg0, s8 *, 4)))->phase);
    lbl_80331FB8[1] = 0x0123456789ABCDEFULL;
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
    void Map_FillLayer(void *, s32, s32);
    void Map_SelectRangeBuffer(void *, s32);
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
        Map_FillLayer(gBattleMap, 8, 0);
        Map_SelectRangeBuffer(gBattleMap, 5);
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

void *fn_800AA5F0(void *unit)
{
  u8 ok;
  extern u32 gUnitLists[];
  void *head;
  void *stop;
  void *next;
  void *faction;
  head = (void *) gUnitLists[0];
  if (head == NULL)
  {
    return NULL;
  }
  if (unit != NULL)
  {
    faction = *((void **) (((u8 *) unit) + 0x190));
    if ((*((u8 *) (((u8 *) faction) + 8))) != 0)
    {
      unit = NULL;
    }
  }
  if (unit == NULL)
  {
    goto check_null;
  }
  next = *((void **) (((u8 *) unit) + 0x184));
  stop = next;
  if (next == NULL)
  {
    stop = head;
  }
  unit = stop;
  goto check_unit;
  do
  {
    if ((*((u32 *) (((u8 *) unit) + 0x1A0))) & 5)
    {
      ok = 0;
    }
    else
      if (((*((u16 *) (((u8 *) unit) + 0x1A4))) >> 7) & 7)
    {
      ok = 0;
    }
    else
      if ((*((u8 *) (((u8 *) unit) + 0x1A5))) & 7)
    {
      ok = 0;
    }
    else
    {
      ok = 1;
    }
    if (ok)
    {
      return unit;
    }
    unit = *((void **) (((u8 *) unit) + 0x184));
    check_unit:
    ;

    ;
  }
  while (unit != NULL);
  goto check_wrap;
  do
  {
    if ((*((u32 *) (((u8 *) head) + 0x1A0))) & 5)
    {
      ok = 0;
    }
    else
      if (((*((u16 *) (((u8 *) head) + 0x1A4))) >> 7) & 7)
    {
      ok = 0;
    }
    else
      if ((*((u8 *) (((u8 *) head) + 0x1A5))) & 7)
    {
      ok = 0;
    }
    else
    {
      ok = 1;
    }
    if (ok)
    {
      return head;
    }
    head = *((void **) (((u8 *) head) + 0x184));
    check_wrap:
    ;

    ;
  }
  while (head != stop);
  goto ret_null;
  do
  {
    if ((*((u32 *) (((u8 *) head) + 0x1A0))) & 5)
    {
      ok = 0;
    }
    else
      if (((*((u16 *) (((u8 *) head) + 0x1A4))) >> 7) & 7)
    {
      ok = 0;
    }
    else
      if ((*((u8 *) (((u8 *) head) + 0x1A5))) & 7)
    {
      ok = 0;
    }
    else
    {
      ok = 1;
    }
    if (ok)
    {
      return head;
    }
    head = *((void **) (((u8 *) head) + 0x184));
    check_null:
    ;

    ;
  }
  while (head != NULL);
  ret_null:
  return NULL;

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
    void Map_FillLayer(void *, s32, s32);
    void Map_SelectRangeBuffer(void *, s32);
    void Map_FillAttackRange(void *, u8, u8, s32, s32);
    extern u8 gBattleMap[];

    if (Status_Test((u8 *)arg0 + 0x1BC, 0x43) != 0) {
        Map_FillLayer(gBattleMap, 5, -1);
        Map_FillLayer(gBattleMap, 8, 0);
        Map_SelectRangeBuffer(gBattleMap, 6);
        Map_FillAttackRange(gBattleMap, ((u8 *)arg0)[0x19E], ((u8 *)arg0)[0x19F], 1, 2);
    }
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
void fn_800AA89C(void *arg0) {
    u8 Item_GetMaxRange(void *);
    void Map_FillAttackRange(u8 *, s8, s8, u8, u8);
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
    u8 *item;
    u32 atk;
    u8 minRange;
    s8 y;
    s8 x;
    s32 yOff;
    u8 *rowBase;
    u8 *cell;
    s32 cellOff;

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
    if (*(void **)pp == NULL) {
        goto slots_done;
    }
    if (fn_8009339C(self) == 0) {
        goto slot_next;
    }
    item = *(u8 **)pp;
    if (item != NULL) {
        minRange = item[0x1D];
    } else {
        minRange = 0;
    }
    pp = minRange;
    if (item != NULL) {
        atk = Item_GetMaxRange(item);
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
        cellOff = yOff;
        x = 0;
        goto x_cmp;
x_loop:
        if (*(s16 *)((map + (cellOff << 1)) + 0x610E) >= 0
            && (s8)cell[0xE18E] == 0
            && cell[0xD] == 0) {
            Map_FillAttackRange(gBattleMap, x, y, (u8)pp, (u8)atk);
        }
        cell += 1;
        cellOff += 1;
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
        cellOff = yOff;
        x = 0;
        goto x2_cmp;
x2_loop:
        if (*(s16 *)((map2 + (cellOff << 1)) + 0x610E) >= 0
            && (s8)cell[0xE18E] == 0
            && cell[0xD] == 0) {
            Map_FillAttackRange(gBattleMap, x, y, 1, 2);
        }
        cell += 1;
        cellOff += 1;
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
u8 Item_GetMaxRange(void *);
void Map_FillAttackRange(void *, u8, u8, u8, u8);
void Map_FillLayer(void *, s32, s32);
void Map_SelectRangeBuffer(void *, s32);
void **Unit_GetHeldItemSlot(void *, s32);
u8 fn_8009339C(void *,void *);
extern u8 gBattleMap[];
s8 bestMin;
s8 bestMax;
s32 slot;
u32 min,max;
void **held;
void *item;
void *self;
self=arg0;
Map_FillLayer(gBattleMap,5,-1);
Map_FillLayer(gBattleMap,8,0);
Map_SelectRangeBuffer(gBattleMap,6);
bestMin=100;
bestMax=0;
for(slot=0;slot<4;++slot) {
held=Unit_GetHeldItemSlot(self,slot);
item=*held;
if(item==NULL) break;
if(fn_8009339C(self,item)!=0) {
item=*held;
min=(u8)(item ? ((u8*)item)[0x1D]:0);
max=(u8)(item ? Item_GetMaxRange(item):0);
if(bestMin>(s32)min || (s32)max>bestMax) {
if((s32)min<bestMin) bestMin=(s8)min;
if(bestMax<(s32)max) bestMax=(s8)max;
Map_FillAttackRange(gBattleMap,((u8*)self)[0x19E],((u8*)self)[0x19F],min,max);
}
}
}
}

void fn_800AAC64(void *arg0) {
    extern u8 gBattleMap[];
    
    Map_SelectRangeBuffer(gBattleMap, 5);
    fn_800227F8(gBattleMap, *(s32*)((char*)arg0 + 0x18C));
    fn_80022748(gBattleMap, 0);
    Map_FloodMoveRange(gBattleMap, *(u8*)((char*)arg0 + 0x19E), *(u8*)((char*)arg0 + 0x19F), 0x3E8, 0, 0);
}

#pragma opt_strength_reduction off
void Map_SetupUnitMoveLimit(void *unit)
{
    void fn_800227F8(void *, s32);
    void Map_SelectRangeBuffer(void *, s32);
    void fn_80022748(void *, s32);
    void Map_FloodMoveRange(void *, u8, u8, s32, s32, s32);
    s8 Unit_GetMov(void *);
    void Map_FillLayer(void *, s32, s32);
    void *Item_Get(s32);
    u8 Status_Test(void *, s32);
    s32 Item_GetMaxRange(void *);
    void Map_FillAttackRange(void *, s32, s32, s32, s32);
    void Map_ClipRangeByFacing(void *, s32, s32, s32);
    s32 fn_8010FF88(void *);
    void fn_800AA89C(void *);
    extern u8 gBattleMap[];
    extern u8 gMapObjEventList[];

    u8 *list;
    void *self;
    u8 *entry;
    register long i;
    u8 minRange;
    u8 y;
    u8 x;
    void *item;

    self = unit;
    Map_SelectRangeBuffer(gBattleMap, 5);
    fn_800227F8(gBattleMap, *(s32 *)((u8 *)self + 0x18C));
    fn_80022748(gBattleMap, *(s32 *)((u8 *)self + 0x190));
    list = (u8 *)(u32)((u8 *)self)[0x19F];
    entry = (u8 *)(u32)((u8 *)self)[0x19E];
    Map_FloodMoveRange(gBattleMap, (u32)entry, (u32)list, Unit_GetMov(self), 0, 0);
    Map_SelectRangeBuffer(gBattleMap, 6);
    Map_FillLayer(gBattleMap, 8, 0);

    if ((u8)Status_Test((u8 *)self + 0x1BC, 0x4F) != 0) {
        entry = gMapObjEventList;
        i = 0;
        list = entry;
        for (; i < fn_8010FF88(list); entry += 8, i++) {
            if (entry[2] == 7) {
                if (*(s16 *)(gBattleMap + 0x610E +
                    (((s8)entry[0] + ((s8)entry[1] << 6)) << 1)) >= 0 &&
                    entry[5] != 0) {
                    item = Item_Get(entry[4]);
                    minRange = ((u8 *)item)[0x1D];
                    y = entry[1];
                    x = entry[0];
                    Map_FillAttackRange(gBattleMap, x, y, minRange,
                                        Item_GetMaxRange(item));
                    Map_ClipRangeByFacing(gBattleMap, entry[0], entry[1],
                                          entry[3]);
                }
            }
        }
    }

    fn_800AA89C(self);
    Map_SelectRangeBuffer(gBattleMap, 5);
}
#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
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
    long col;
    s32 row;
    u8 *entry;
    register u8 *rowPtr;
    u8 *base;
    u8 *scan;
    Obj *self;

    {
        Obj *ret;
        void **ef;
        void *w1;
        void *w0;
        ret = Process_CreateChild(lbl_8028CEF8, arg0);
        ef = gUiContext;
        col = 0;
        row = 0;
        w1 = ef[1];
        base = lbl_80312ACC;
        entry = base;
        w0 = ef[0];
        self = ret;
        ret->unk30 = w0;
        rowPtr = base;
        ret->unk34 = w1;
        ret->unk3A = -1;
        ret->unk38 = -1;
        ret->unk43 = row;
        ret->unk41 = row;
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
        scan = base;
        while (1) {
            if (col >= 8) {
                col = -1;
                break;
            }
            if (scan[0x8C] != 0) {
                break;
            }
            scan += 0x10;
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
#pragma pop
#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
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
    s32 r;
    u8 *rp;
    u8 *b;
    Obj *s;
    s32 c;
    u8 *e;

    {
        void *ret;
        void **ef;
        void *w1;
        void *w0;
        ret = Process_CreateChild(lbl_8028CE90, arg0);
        ef = gUiContext;
        r = 0;
        w1 = ef[1];
        rp = lbl_80312ACC;
        w0 = ef[0];
        s = ret;
        s->unk30 = w0;
        b = rp;
        s->unk34 = w1;
        s->unk3A = -1;
        s->unk38 = -1;
        s->unk43 = r;
        s->unk41 = r;
    }
    do {
        c = 0;
        e = rp;
        do {
            *(s16 *)e = 0x1E;
            *(s16 *)(e + 2) = (s16)(((c & 3) * 0x1C) + 0x71);
            if (r != 0) {
                *(s16 *)e = (s16)(*(s16 *)e + 0x118);
            }
            if (c >= 4) {
                *(s16 *)(e + 2) = (s16)(*(s16 *)(e + 2) + 0x88);
            }
            if (r != 0) {
                Item_Copy(e + 4, Unit_GetItemSlot(s->unk34, c));
            } else {
                Item_Copy(e + 4, Unit_GetItemSlot(s->unk30, c));
            }
            c += 1;
            e += 0x10;
        } while (c < 8);
        r += 1;
        rp += 0x80;
    } while (r < 2);
    s->unk44 = 0;
    fn_80091CD8(s->unk30);
    fn_80091CD8(s->unk34);
    rp = b;
    for (r = 0; r < 2; r++, rp += 0x80) {
        for (e = rp, c = 0; c < 8; e += 0x10, c++) {
            if (c < 4 && s->unk44 != 0) {
                e[0xC] = 0;
            } else {
                e[0xC] = (*(s32 *)(e + 4) != 0);
            }
        }
    }
    c = 0;
    e = b;
    s->unk3C = 0;
    while (1) {
        if (c >= 8) {
            c = -1;
            break;
        }
        if (e[0xC] != 0) {
            break;
        }
        e += 0x10;
        c += 1;
    }
    s->unk3D = c;
    if ((s8)s->unk3D < 0) {
        c = 0;
        s->unk3C = 1;
        while (1) {
            if (c >= 8) {
                c = -1;
                break;
            }
            if (b[0x8C] != 0) {
                break;
            }
            b += 0x10;
            c += 1;
        }
        s->unk3D = c;
    }
    s->unk3E = 0;
    s->unk3F = 0;
    fn_8018DBD8();
    gBattleState[0x51D] = 0xF;
    s->unk42 = 1;
    s->unk28 = 4;
    s->unk45 = 0x9A;
    if (*((u8 *)gUiContext + 8) == 0x28) {
        fn_800256A0(gPadInput, 0x100);
        s->unk3C = 0;
        s->unk3D = *((u8 *)gUiContext + 0xA);
        Process_Goto(s, 3);
    }
}
#pragma pop
void fn_800AB5DC(void *arg0) {
void fn_800931E4(void*,u8,void*);
void fn_800931B0(void*,u8,void*);
s8 Unit_GetActiveItemSlot(void*);
void fn_800951D0(void*,s32);
void fn_80037CCC(void*);
void Item_Clear(void*);
extern u8 gUiContext[];
extern u8 gMapUiResult;
extern u8 lbl_80312ACC[];
s32 col;
u8 *entry;
s32 rowIndex;
u8 *other;
s32 slot;
u8 *base;
u8 *self;
u8 zero;
self=arg0;
if(self[0x43]==0) {
gUiContext[8]=0x23;
gMapUiResult=9;
} else {
base=lbl_80312ACC;
for(slot=0,entry=base;slot<4;++slot,entry+=0x10) {
fn_800931E4(*(void**)(self+0x30),(u8)slot,entry+4);
other=base+((slot+4)*0x10);
fn_800931B0(*(void**)(self+0x30),(u8)slot,other+4);
fn_800931E4(*(void**)(self+0x34),(u8)slot,entry+0x84);
fn_800931B0(*(void**)(self+0x34),(u8)slot,other+0x84);
}
if(Unit_GetActiveItemSlot(*(void**)(self+0x30))<0) fn_800951D0(*(void**)(self+0x30),-1);
fn_80037CCC(*(void**)(self+0x30));
if(Unit_GetActiveItemSlot(*(void**)(self+0x34))<0) fn_800951D0(*(void**)(self+0x34),-1);
fn_80037CCC(*(void**)(self+0x34));
gMapUiResult=5;
}
self[0x42]=2;
base=lbl_80312ACC;
rowIndex=0;
*(u16*)(self+0x28)=4;
zero=0;
for(;rowIndex<2;++rowIndex,base+=0x80) {
for(col=0,entry=base;col<8;++col,entry+=0x10) {
Item_Clear(entry+4);
entry[0xC]=zero;
}
}
}

void fn_800AB73C(void) {
    M2C_UNK fn_800AB75C();
    fn_800AB75C();
}

void fn_800AB75C(void *arg0) {
    void fn_8001C76C(void *);
    void *fn_8001C4FC(void *, void *);
    void *fn_8001C5F8(void *, s32);
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
    fn_8001C4FC(sp8, lbl_80312ACC + ((s8)*(u8 *)((u8 *)self + 0x3C) << 7)
                                 + ((s8)*(u8 *)((u8 *)self + 0x3D) << 4) + 4);
    fn_8001C4FC(lbl_80312ACC + ((s8)*(u8 *)((u8 *)self + 0x3C) << 7)
                           + ((s8)*(u8 *)((u8 *)self + 0x3D) << 4) + 4,
                lbl_80312ACC + ((s8)*(u8 *)((u8 *)self + 0x3E) << 7)
                             + ((s8)*(u8 *)((u8 *)self + 0x3F) << 4) + 4);
    fn_8001C4FC(lbl_80312ACC + ((s8)*(u8 *)((u8 *)self + 0x3E) << 7)
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
    fn_8001C5F8(sp8, -1);
}

#pragma cplusplus on
#pragma opt_strength_reduction off
extern "C" void *Item_Copy(void *, void *);
extern "C" void Item_Clear(void *);
#pragma cplusplus off
void fn_800ABA3C(void) {
    void Item_Init(void *);
    void Item_Clear(void *);
    void Item_Copy(void *, void *);
    void Item_Destroy(void *, s32);
    typedef struct {
        u32 unk0;
        u32 unk4;
    } Item;
    extern u8 lbl_80312ACC[];
    u8 *base;
    s32 i, n;
    Item *q;
    Item *qa;
    u8 *p;
    u8 *dst;
    u8 *check;
    {
        Item a[4];
        Item_Init(&a[0]); Item_Init(&a[1]); Item_Init(&a[2]); Item_Init(&a[3]);

        q = a;
        for (i = 0, qa = q; i < 4; i++, qa++) Item_Clear(qa);
        base = lbl_80312ACC;
        for (i = 0, n = 0, p = base; i < 4; i++, p += 16) {
            if (*(u32 *)(p + 4) != 0) {
                Item_Copy(&a[n++], p + 4);
            }
            Item_Clear(p + 4);
        }
        for (i = 0, p = base; i < n; q++, p += 16, i++) Item_Copy(p + 4, q);
        Item_Destroy(&a[3], -1); Item_Destroy(&a[2], -1); Item_Destroy(&a[1], -1); Item_Destroy(&a[0], -1);
    }
    {
        Item a[4];
        Item_Init(&a[0]); Item_Init(&a[1]); Item_Init(&a[2]); Item_Init(&a[3]);

        q = a;
        for (i = 0, qa = q; i < 4; i++, qa++) Item_Clear(qa);
        dst = lbl_80312ACC + 64;
        for (i = 0, n = 0, p = dst, check = base; i < 4; i++, p += 16, check += 16) {
            if (*(u32 *)(check + 68) != 0) {
                Item_Copy(&a[n++], p + 4);
            }
            Item_Clear(p + 4);
        }
        for (i = 0; i < n; q++, dst += 16, i++) Item_Copy(dst + 4, q);
        Item_Destroy(&a[3], -1); Item_Destroy(&a[2], -1); Item_Destroy(&a[1], -1); Item_Destroy(&a[0], -1);
    }
    {
        Item a[4];
        Item_Init(&a[0]); Item_Init(&a[1]); Item_Init(&a[2]); Item_Init(&a[3]);

        q = a;
        for (i = 0, qa = q; i < 4; i++, qa++) Item_Clear(qa);
        dst = lbl_80312ACC + 128;
        for (i = 0, n = 0, p = dst, check = base; i < 4; i++, p += 16, check += 16) {
            if (*(u32 *)(check + 132) != 0) {
                Item_Copy(&a[n++], p + 4);
            }
            Item_Clear(p + 4);
        }
        for (i = 0; i < n; q++, dst += 16, i++) Item_Copy(dst + 4, q);
        Item_Destroy(&a[3], -1); Item_Destroy(&a[2], -1); Item_Destroy(&a[1], -1); Item_Destroy(&a[0], -1);
    }
    {
        Item a[4];
        Item_Init(&a[0]); Item_Init(&a[1]); Item_Init(&a[2]); Item_Init(&a[3]);

        q = a;
        for (i = 0, qa = q; i < 4; i++, qa++) Item_Clear(qa);
        dst = lbl_80312ACC + 192;
        for (i = 0, n = 0, p = dst, check = base; i < 4; i++, p += 16, check += 16) {
            if (*(u32 *)(check + 196) != 0) {
                Item_Copy(&a[n++], p + 4);
            }
            Item_Clear(p + 4);
        }
        for (i = 0; i < n; q++, dst += 16, i++) Item_Copy(dst + 4, q);
        Item_Destroy(&a[3], -1); Item_Destroy(&a[2], -1); Item_Destroy(&a[1], -1); Item_Destroy(&a[0], -1);
    }
}
void fn_800ABE74(void *arg0) {
    void fn_800AC0C0(void);
    void fn_8000C070(void *, s32);
    void fn_8000C188(void *);
    s32 fn_8000E0E4(void *);
    u64 *fn_8001CB64(void *);
    void fn_801475FC(void *, s32);
    void fn_80166AE8(s16, s32, s32, void *, void *);
    u8 fn_80166D8C(void *);
    void fn_801673D0(void *);
    void fn_8016746C(void *, void *, void *, f32, f32);
    extern void *lbl_80367240;
    extern u8 lbl_80330D68[];
    extern u8 lbl_80312ACC[];
    extern u8 lbl_8026E858[];
    extern u32 lbl_80368DC4;
    u32 var_r31;
    void *var_r30;
    s32 var_r29;
    register s32 str;
    register u8 *entry;
    u32 a;

    var_r30 = arg0;
    fn_800AC0C0();
    a = ((u32 *)lbl_80367240)[1];
    var_r31 = a & (((u32 *)lbl_80367240)[2] ^ a);
    if (fn_80166D8C(lbl_80330D68) != 0) {
        if (var_r31 & 0xA00) {
            fn_801673D0(lbl_80330D68);
        }
    } else if (var_r31 & 0x100) {
        register var_r31 = 0;
        entry = lbl_80312ACC + (((s8)*(u8 *)((u8 *)var_r30 + 0x3C)) << 7)
                              + (((s8)*(u8 *)((u8 *)var_r30 + 0x3D)) << 4);
        if (*(u32 *)(entry + 4) != 0) {
            if (*fn_8001CB64(entry + 4) & 0x200) {
                var_r31 = 1;
            }
        }
        if ((u8)var_r31 != 0) {
            var_r31 = ((s8)*(u8 *)((u8 *)var_r30 + 0x3D)) << 4;
            var_r29 = ((s8)*(u8 *)((u8 *)var_r30 + 0x3C)) << 7;
            str = fn_8000E0E4(lbl_8026E858 + 0xE7);
            entry = lbl_80312ACC + var_r29;
            fn_80166AE8(*(s16 *)((u8 *)entry + var_r31),
                        *(s16 *)((u8 *)entry + var_r31 + 2) + 0x28,
                        str, var_r30, entry);
        } else {
            fn_8000C188(var_r30);
            fn_801475FC(lbl_8026E858 + 0xEF, 0x64);
        }
    } else if (var_r31 & 0x200) {
        *(u8 *)((u8 *)var_r30 + 0x3C) = *(u8 *)((u8 *)var_r30 + 0x3E);
        *(u8 *)((u8 *)var_r30 + 0x3D) = *(u8 *)((u8 *)var_r30 + 0x3F);
        fn_8000C070(var_r30, 0);
        fn_801475FC(lbl_8026E858 + 0xFF, 0x64);
    } else if (var_r31 & 0x800) {
        entry = lbl_80312ACC + (((s8)*(u8 *)((u8 *)var_r30 + 0x3C)) << 7)
                              + (((s8)*(u8 *)((u8 *)var_r30 + 0x3D)) << 4);
        if (*(u32 *)(entry + 4) != 0) {
            fn_8016746C(lbl_80330D68, var_r30, entry + 4,
                        (f32)*(s16 *)entry,
                        (f32)(*(s16 *)(entry + 2) + 0x28));
            *(u32 *)lbl_80330D68 |= lbl_80368DC4;
        }
    }
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_propagation off
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
    s32 var_r7_2;
    s32 temp_r5;
    s32 temp_r4;
    s32 temp_r8;
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
        temp_r5 = temp_r8 << 7;
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
            temp_r5 = temp_r8 << 7;
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
        temp_r5 = *(u8 *)((u8 *)self + 0x3D);
        temp_r8 = *(s8 *)((u8 *)self + 0x3C);
        temp_r4 = (s8)temp_r5;
        var_r7_2 = temp_r4 + 1;
        temp_r5 = temp_r8 << 7;
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
#pragma push
#pragma optimization_level 3
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_lifetimes off
void fn_800AC400(u8 *arg0) {
    extern u8 lbl_80312ACC[];
    s32 zero;
    s32 j;
    s32 i;
    u8 *entry;
    u8 *scan;
    u8 *row;
    s32 col;
    s32 row_off;

    zero = 0;
    arg0[0x42] = zero;
    row = lbl_80312ACC;
    i = zero;
    arg0[0x41] = 1;
    do {
        entry = row;
        for (j = 0; j < 8; entry += 0x10, ++j) {
            if ((j < 4) && (arg0[0x44] != 0)) {
                entry[0xC] = zero;
            } else {
                entry[0xC] = ((*(u32 *)(entry + 4)) != 0);
            }
        }
        ++i;
        row += 0x80;
    } while(i < 2);

    arg0[0x3e] = arg0[0x3c];
    arg0[0x3f] = arg0[0x3d];
    arg0[0x3c] ^= 1;
    arg0[0x40] = arg0[0x3d] & 4;
    row_off = ((s8)arg0[0x3c]) << 7;
    col = (s8)arg0[0x40];
    scan = lbl_80312ACC + row_off;
    entry = scan + (col << 4);
    if (entry[0x3c] != 0) {
        return;
    }
    i = col + 3;
    scan += i << 4;
    for (;;) {
        if (i < 0) {
            break;
        }
        if (scan[0xc] != 0) {
            break;
        }
        scan -= 0x10;
        --i;
    }
    j = i + 1;
    if ((j - col) < 0) {
        j = col;
    }
    *(lbl_80312ACC + (row_off + (j << 4)) + 0xc) = 1;
    arg0[0x3d] = j;
}
#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
void fn_800AC5DC(void *arg0) {
    void fn_800AC810(void);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_HideUnitInfoPopup(void *);
    u64 *Item_GetFlagsPtr(void *);
    s32 Msg_Expand(void *);
    void fn_80166AE8(s16, s32, s32, void *);
    void Process_Goto(void *, s32);
    void Ui_PlaySeCue(void *, s32);
    void Ui_OpenUnitInfoPopup(void *, void *, void *, f32, f32);

    extern void *gPadInput;
    extern u8 gUnitInfoPopup[];
    extern u8 lbl_80312ACC[];
    extern u8 lbl_8026E858[];
    extern u32 gUnitInfoPopupFlag;

    s32 off_c;
    s32 temp;
    u32 *pad;
    u32 cur;

    fn_800AC810();
    pad = (u32 *)gPadInput;
    cur = pad[1];
    temp = cur & (pad[2] ^ cur);
    if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
        if (temp & 0xA00) {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
        }
    } else if (temp & 0x100) {
        temp = 0;
        {
            u8 *entry = lbl_80312ACC + ((s8)*(u8 *)((char *)arg0 + 0x3C) << 7)
                                      + ((s8)*(u8 *)((char *)arg0 + 0x3D) << 4);
            if (*(u32 *)(entry + 4) != 0) {
                if (*Item_GetFlagsPtr(entry + 4) & 0x200) {
                    temp = 1;
                }
            }
        }
        if ((u8)temp != 0) {
            temp = (s8)*(u8 *)((char *)arg0 + 0x3D) << 4;
            off_c = (s8)*(u8 *)((char *)arg0 + 0x3C) << 7;
            {
                s32 str = Msg_Expand(lbl_8026E858 + 0xE7);
                u8 *row = lbl_80312ACC + off_c;
                u8 *entry = row + temp;
                fn_80166AE8(*(s16 *)(row + temp),
                            *(s16 *)(entry + 2) + 0x28,
                            str, arg0);
            }
        } else {
            Process_Goto(arg0, 1);
            Ui_PlaySeCue(lbl_8026E858 + 0xEF, 0x64);
        }
    } else if (temp & 0x200) {
        Process_Goto(arg0, 2);
        Ui_PlaySeCue(lbl_8026E858 + 0xFF, 0x64);
    } else if (temp & 0x800) {
        u8 *entry = lbl_80312ACC + ((s8)*(u8 *)((char *)arg0 + 0x3C) << 7)
                                  + ((s8)*(u8 *)((char *)arg0 + 0x3D) << 4);
        Ui_OpenUnitInfoPopup(gUnitInfoPopup, arg0, entry + 4, (f32)*(s16 *)entry,
                    (f32)(*(s16 *)(entry + 2) + 0x28));
        *(u32 *)gUnitInfoPopup |= gUnitInfoPopupFlag;
    }
}
#pragma pop
void fn_800AC810(void *arg0)
{
  void Ui_PlaySeCue(void *, s32);
  u8 Ui_IsUnitInfoPopupOpen(void *);
  void Ui_ShowUnitInfoPopup(void *, void *, f32, f32);
  extern void *gPadInput;
  extern u8 lbl_80312ACC[];
  extern u8 lbl_8026E858[];
  extern u8 gUnitInfoPopup[];
  extern f64 lbl_80369C28;
  s32 flags;
  s32 buttons;
  s32 pressed;
  s32 var_r5;
  s32 var_r6;
  s32 var_r7;
  s32 tmp;
  u8 *entry;
  s32 var_r8;
  s16 x;
  s16 y;
  var_r8 = 0;
  flags = *((s32 *) (((u8 *) gPadInput) + 0xC));
  buttons = *((s32 *) (((u8 *) gPadInput) + 4));
  pressed = buttons & ((*((s32 *) (((u8 *) gPadInput) + 8))) ^ buttons);
  if (flags & 0x01000001)
  {
    tmp = *((u8 *) (((u8 *) arg0) + 0x3C));
    if (tmp == 1)
    {
      var_r7 = (var_r6 = *((s8 *) (((u8 *) arg0) + 0x3D)));
      var_r5 = (s32) (lbl_80312ACC + (var_r6 * 0x10));
      loop1:
      if ((var_r6 >= 0) && ((*((u8 *) (var_r5 + 0xC))) == 0))
      {
        var_r5 -= 0x10;
        var_r6 -= 1;
        goto loop1;
      }

      var_r5 = var_r6;
      if (var_r5 < 0)
      {
        var_r5 = (s32) (lbl_80312ACC + (var_r7 * 0x10));
        loop1b:
        if (var_r7 >= 8)
        {
          var_r7 = -1;
        }
        else
          if ((*((u8 *) (var_r5 + 0xC))) == 0)
        {
          var_r5 += 0x10;
          var_r7 += 1;
          goto loop1b;
        }

        var_r5 = var_r7;
      }
      if (var_r5 < 0)
      {
        return;
      }
      var_r8 = 1;
      *((u8 *) (((u8 *) arg0) + 0x3C)) = 0;
      *((u8 *) (((u8 *) arg0) + 0x3D)) = var_r5;
    }
  }
  if (flags & 0x02000002)
  {
    tmp = *((s8 *) (((u8 *) arg0) + 0x3C));
    if (tmp == 0)
    {
      var_r6 = *((s8 *) (((u8 *) arg0) + 0x3D));
      var_r7 = var_r6;
      var_r5 = (s32) (lbl_80312ACC + (var_r6 * 0x10));
      loop2:
      if ((var_r7 >= 0) && ((*((u8 *) (var_r5 + 0x8C))) == 0))
      {
        var_r5 -= 0x10;
        var_r7 -= 1;
        goto loop2;
      }

      if (var_r7 < 0)
      {
        var_r5 = (s32) (lbl_80312ACC + (var_r6 * 0x10));
        loop2b:
        if (var_r6 >= 8)
        {
          var_r6 = -1;
        }
        else
          if ((*((u8 *) (var_r5 + 0x8C))) == 0)
        {
          var_r5 += 0x10;
          var_r6 += 1;
          goto loop2b;
        }

        var_r7 = var_r6;
      }
      if (var_r7 < 0)
      {
        return;
      }
      var_r8 = 1;
      *((u8 *) (((u8 *) arg0) + 0x3C)) = 1;
      *((u8 *) (((u8 *) arg0) + 0x3D)) = var_r7;
    }
  }
  if (flags & 0x08000008)
  {
    buttons = (*((s8 *) (((u8 *) arg0) + 0x3D))) - 1;
    var_r6 = *((s8 *) (((u8 *) arg0) + 0x3C));
    var_r7 = buttons;
    var_r5 = (s32) ((lbl_80312ACC + (var_r6 << 7)) + (var_r7 * 0x10));
    loop3:
    if ((var_r7 >= 0) && ((*((u8 *) (var_r5 + 0xC))) == 0))
    {
      var_r5 -= 0x10;
      var_r7 -= 1;
      goto loop3;
    }

    if (var_r7 < 0)
    {
      if (!(pressed & 0x08000008))
      {
        return;
      }
      var_r7 = 7;
      var_r5 = (s32) ((lbl_80312ACC + (var_r6 << 7)) + 0x70);
      loop3b:
      if ((var_r7 >= 0) && ((*((u8 *) (var_r5 + 0xC))) == 0))
      {
        var_r5 -= 0x10;
        var_r7 -= 1;
        goto loop3b;
      }

    }
    *((u8 *) (((u8 *) arg0) + 0x3D)) = var_r7;
    var_r8 = 1;
  }
  if (flags & 0x04000004)
  {
    tmp = (*((s8 *) (((u8 *) arg0) + 0x3D))) + 1;
    var_r6 = *((s8 *) (((u8 *) arg0) + 0x3C));
    var_r5 = (s32) ((lbl_80312ACC + (var_r6 << 7)) + (tmp * 0x10));
    loop4:
    if (tmp >= 8)
    {
      tmp = -1;
    }
    else
      if ((*((u8 *) (var_r5 + 0xC))) == 0)
    {
      var_r5 += 0x10;
      tmp += 1;
      goto loop4;
    }

    if (tmp < 0)
    {
      if (!(pressed & 0x04000004))
      {
        return;
      }
      tmp = 0;
      var_r5 = (s32) (lbl_80312ACC + (var_r6 << 7));
      loop4b:
      if (tmp >= 8)
      {
        tmp = -1;
      }
      else
        if ((*((u8 *) (var_r5 + 0xC))) == 0)
      {
        var_r5 += 0x10;
        tmp += 1;
        goto loop4b;
      }

    }
    *((u8 *) (((u8 *) arg0) + 0x3D)) = tmp;
    var_r8 = 1;
  }
  if (((u8) var_r8) != 0)
  {
    Ui_PlaySeCue(lbl_8026E858 + 0x10F, 0x64);
    if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0)
    {
      entry = (lbl_80312ACC + ((*((s8 *) (((u8 *) arg0) + 0x3C))) << 7)) + ((*((s8 *) (((u8 *) arg0) + 0x3D))) * 0x10);
      x = *((s16 *) entry);
      y = *((s16 *) (entry + 2));
      Ui_ShowUnitInfoPopup(gUnitInfoPopup, entry + 4, (f32) x, (f32) (y + 0x28));
    }
  }
}
#pragma pop
#pragma optimization_level reset
void fn_800ACBD8(void *arg0) {
extern u8 lbl_80312ACC[];
s32 j;
s32 i;
u8 *entry;
u8 *row;
((u8*)arg0)[0x42]=0;
row=lbl_80312ACC;
((u8*)arg0)[0x41]=0;
for(i=0;i<2;++i,row+=0x80) {
entry=row;
for(j=0;j<8;entry+=0x10,++j) {
if(j<4 && ((u8*)arg0)[0x44]!=0) entry[0xC]=0;
else entry[0xC]=(*(u32*)(entry+4)!=0);
}
}
}
#pragma optimization_level reset
void fn_800ACCF8(void) {
    M2C_UNK fn_800ACD18();
    fn_800ACD18();
}

#pragma use_lmw_stmw on
void fn_800ACD18(void *arg0)
{
    void Math_Ease(s32, f32, f32, f32, f32);
    void Prim2D_SetColorByte(u8);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    void fn_8008B464(s32, s32, s32);
    void fn_8008BBF8(s32, s32, s32, s32, s32, u8);
    void Ui_DrawRouteIcon(s16, s16);
    void Ui_DrawRouteIconEx(s16, s16, s32);
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
    u8 *ent;
    s32 i;
    u8 *ent4;
    s32 v27;
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
    f31 = lbl_80369C48 * f31;
    Prim2D_SetColorByte((u8)f31);
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
    Prim2D_SetColorByte((u8)f31);
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
        Ui_DrawRouteIconEx(*(s16 *)((u8 *)arg0 + 0x38), *(s16 *)((u8 *)arg0 + 0x3A), Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369C58);
        Prim2D_PrepareTex();

        if (*(u8 *)((u8 *)arg0 + 0x41) == 1) {
            Ui_DrawRouteIcon(x27, y28);
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
