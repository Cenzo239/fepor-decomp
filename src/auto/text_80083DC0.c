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
extern f32 lbl_8036A154;

extern f32 lbl_80369768;
extern u16 lbl_80289A60[];

extern u8 lbl_80289B00[16];

extern void* fn_800980D4(s32 arg0);
extern void fn_8017E394(void* arg0, void* arg1, void* arg2, s32 arg3);

extern u8 lbl_80289EB8[16];

extern f32 lbl_803697E0;
extern f32 lbl_803697E4;

void fn_80083DC0(void *arg0) {
    M2C_UNK fn_800832C0(s32, f32, f32);
    fn_800832C0(M2C_FIELD(arg0, s32 *, 0x58), (f32) (s32) M2C_FIELD(arg0, f32 *, 0x14), (f32) (s32) M2C_FIELD(arg0, f32 *, 0x18));
}

void fn_80083E34(s32 arg0) {
    void fn_80081CF4(s32);
    void fn_80083278(s32);
    void fn_80083DC0(s32);
    fn_80083DC0(arg0);
    fn_80083278(arg0);
    fn_80081CF4(arg0);
}

void fn_80083E70(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    void fn_80083E34(s32);
    void fn_80081CB0(s32);
    void fn_8007F7F8(s32);
    extern f32 lbl_80369418;
    extern f32 lbl_803695E0;
    extern f32 lbl_80369430;
    s8 temp;

    Prim2D_Begin();
    Prim2D_SetColorByte(*(u8 *)((u8 *)arg0 + 0xa));
    Prim2D_SetTransform(lbl_80369418, lbl_80369418, lbl_803695E0, lbl_80369430);
    Prim2D_PrepareTex();
    temp = *(s8 *)((u8 *)arg0 + 9);
    switch (temp) {
    case 0:
        fn_80083E34((s32)arg0);
        break;
    case 1:
        fn_80081CB0((s32)arg0);
        break;
    case 2:
        fn_8007F7F8((s32)arg0);
        break;
    }
}

#pragma use_lmw_stmw on
void fn_80083F08(void *arg0) {
    typedef struct { u8 r, g, b, a; } Color;
    void fn_80007340(void *, void *);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(s32);
    void fn_80009B98(void);
    void fn_80009BC0(void (*)(s32, s16 *), s16 *);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void *Msg_Expand(void *);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    f32 fn_80037904(void *, s32);
    u8 fn_800386B0(void *);
    s8 fn_8003A1E0(void *);
    s8 fn_8003A398(void *);
    s8 fn_8003B2D0(void *);
    void fn_8004BD1C(void *, f32 *, f32);
    void fn_8004DDB8(s32);
    void Ui_DrawIcon(void *, s32, s32);
    void fn_8005F780(void *, s32);
    void Model_SetAlpha(void *, u8);
    void fn_80060060(void *);
    void fn_800609DC(void *);
    u16 **fn_8006EDD8(s32, s32);
    void fn_8007B4D8(s32, s32, s32, void *);
    void fn_800852BC(void);
    void fn_8008532C(s32, s16 *);
    void *fn_800A8978(u32);
    void *fn_800A8A88(s32);
    s32 fn_801660A8(void *);
    Color *Ui_GetColor(s32);
    void PSMTXCopy(f32 *, void *);
    void PSMTXConcat(f32 *, f32 *, f32 *);
    void PSMTXRotRad(f32 *, s32, f32);
    void PSMTXTrans(f32 *, f32, f32, f32);
    void PSMTXScale(f32 *, f32, f32, f32);
    void fn_802029C4(f32 *, f32 *, f32 *);
    extern u8 gUiStrings[];
    extern u8 lbl_802F0308[];
    extern s8 lbl_803674B8;
    extern s16 lbl_803674BC[4];
    extern s32 lbl_803674F4;
    extern f32 lbl_80369418;
    extern f32 lbl_80369428;
    extern f32 lbl_8036942C;
    extern f32 lbl_80369430;
    extern f32 lbl_80369438;
    extern f32 lbl_8036943C;
    extern f64 lbl_80369440;
    extern f64 lbl_80369470;
    extern f32 lbl_80369480;
    extern f32 lbl_80369498;
    extern f32 lbl_8036949C;
    extern f32 lbl_803694B4;
    extern f32 lbl_803694CC;
    extern f32 lbl_803694EC;
    extern f32 lbl_80369514;
    extern f32 lbl_80369518;
    extern f32 lbl_80369524;
    extern f32 lbl_8036959C;
    extern f32 lbl_803695A4;
    extern f32 lbl_803695E0;
    extern f32 lbl_803695E4;
    extern f32 lbl_803695E8;
    extern f32 lbl_803695EC;
    extern f32 lbl_803695F0;
    extern f32 lbl_803695F4;
    extern f32 lbl_803695F8;
    extern f32 lbl_803695FC;
    extern f32 lbl_80369600;
    extern f32 lbl_80369604;
    extern f32 lbl_80369608;
    extern f32 lbl_8036960C;
    extern f32 lbl_80369610;
    extern f32 lbl_80369614;
    extern f32 lbl_80369618;
    extern f32 lbl_8036961C;
    extern f32 lbl_80369620;
    extern f32 lbl_80369624;
    extern f32 lbl_80369628;
    extern f32 lbl_8036962C;
    extern f32 lbl_80369630;
    extern f32 lbl_80369634;
    extern f32 lbl_80369638;
    extern f32 lbl_8036963C;
    extern f32 lbl_80369640;
    extern f32 lbl_80369644;
    extern f32 lbl_80369648;
    extern f32 lbl_8036964C;
    extern f32 lbl_80369650;
    extern f32 lbl_80369654;
    extern f32 lbl_80369658;
    extern f32 lbl_8036965C;
    extern f32 lbl_80369660;
    extern f32 lbl_80369664;

    f32 sp120[12];
    f32 spF0[12];
    f32 spC0[12];
    f32 sp90[12];
    f32 sp60[12];
    f32 sp30[12];
    f32 sp24;
    f32 sp28;
    Color col0, col1, col2, col3, col4, col5;
    void *unit;
    s32 nameId;
    u32 classId;
    f32 bx, by;
    f32 sh, sw, th, tw;
    f32 x, y, t, yRow, x0, w;
    f32 f23v, f24v, f25v, f29v, f30v, f31v;
    void *str;
    void *child;
    u16 *tex;
    s32 id;
    s32 i;
    s32 xOff;
    void *walk;

    (void)lbl_80369440;
    (void)lbl_80369470;

    unit = *(void **)((u8 *)arg0 + 0x58);
    bx = *(f32 *)((u8 *)arg0 + 0xC);
    nameId = *(s32 *)((u8 *)unit + 0x188);
    classId = *(u32 *)((u8 *)unit + 0x18C);
    by = *(f32 *)((u8 *)arg0 + 0x10);

    if ((s8)lbl_803674B8 == 0) {
        lbl_803674B8 = 1;
        Prim2D_Begin();
        Prim2D_SetColorByte(*(u8 *)((u8 *)arg0 + 8));
        Prim2D_SetTransform(lbl_80369418, lbl_80369418, lbl_803695E0, lbl_80369430);
        Prim2D_PrepareTex();

        tex = *fn_8006EDD8(lbl_803674F4, 0x1C);
        sh = (f32)tex[0] * lbl_80369430;
        sw = (f32)tex[1] * lbl_80369430;
        col0 = *Ui_GetColor(1);
        id = lbl_803674F4;
        tex = *fn_8006EDD8(id, 0x1C);
        tw = (f32)tex[1];
        th = (f32)tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(id, 0x1C, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetPrimParam(lbl_80369418);
        x = lbl_803695E4 + bx;
        Prim2D_SetQuadMin(x, by - lbl_803695E8, lbl_80369418, lbl_80369418);
        Prim2D_SetQuadMax(x + sw, (by - lbl_803695E8) + sh, tw, th);
        Prim2D_SetColor(col0.r, col0.g, col0.b, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036942C);
        Prim2D_PrepareTex();
    }

    tex = *fn_8006EDD8(lbl_803674F4, 0x15);
    sh = (f32)tex[0] * lbl_80369430;
    sw = (f32)tex[1] * lbl_80369430;
    col1 = *Ui_GetColor(1);
    id = lbl_803674F4;
    tex = *fn_8006EDD8(id, 0x15);
    tw = (f32)tex[1];
    th = (f32)tex[0];
    Prim2D_Begin();
    Prim2D_BindTexture(id, 0x15, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_80369418);
    Prim2D_SetQuadMin(bx, by, lbl_80369418, lbl_80369418);
    Prim2D_SetQuadMax(bx + sw, by + sh, tw, th);
    Prim2D_SetColor(col1.r, col1.g, col1.b, 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    fn_8001003C((s32)(lbl_803695EC + bx), (s32)(by - lbl_803695E8), 1, 0, 1, gUiStrings + 0x215, (s8)*(u8 *)((u8 *)arg0 + 9) + 1, lbl_80369430, lbl_80369418);
    f30v = lbl_803695F0 + bx;
    fn_8001003C((s32)f30v, (s32)(by - lbl_803695E8), 6, 0, 1, gUiStrings + 0x360, lbl_80369430, lbl_80369418);
    fn_8001003C((s32)(lbl_803695F4 + bx), (s32)(by - lbl_803695E8), 6, 0, 1, gUiStrings + 0x362, lbl_80369430, lbl_80369418);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036942C);
    Prim2D_PrepareTex();

    tex = *fn_8006EDD8(lbl_803674F4, 0x1E);
    sh = (f32)tex[0] * lbl_80369430;
    sw = (f32)tex[1] * lbl_80369430;
    col2 = *Ui_GetColor(1);
    id = lbl_803674F4;
    tex = *fn_8006EDD8(id, 0x1E);
    tw = (f32)tex[1];
    th = (f32)tex[0];
    Prim2D_Begin();
    Prim2D_BindTexture(id, 0x1E, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_80369418);
    f24v = lbl_80369524 + bx;
    Prim2D_SetQuadMin(f24v, by - lbl_8036949C, lbl_80369418, lbl_80369418);
    Prim2D_SetQuadMax(f24v + sw, (by - lbl_8036949C) + sh, tw, th);
    Prim2D_SetColor(col2.r, col2.g, col2.b, 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    t = fn_80037904(unit, fn_801660A8(gBattleState + 0x3C0));
    if (t >= lbl_803695F8) {
        tex = *fn_8006EDD8(lbl_803674F4, 0x22);
        sh = (f32)tex[0] * lbl_80369430;
        sw = (f32)tex[1] * lbl_80369430;
        col3 = *Ui_GetColor(0xA);
        id = lbl_803674F4;
        tex = *fn_8006EDD8(id, 0x22);
        tw = (f32)tex[1];
        th = (f32)tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(id, 0x22, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetPrimParam(lbl_80369418);
        x = lbl_803695FC + bx;
        y = lbl_803694CC + by;
        Prim2D_SetQuadMin(x, y, lbl_80369418, th);
        Prim2D_SetQuadMax(x + sw, y + sh, tw, lbl_80369418);
        Prim2D_SetColor(col3.r, col3.g, col3.b, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
    } else if (t <= lbl_80369600) {
        tex = *fn_8006EDD8(lbl_803674F4, 0x22);
        sh = (f32)tex[0] * lbl_80369430;
        sw = (f32)tex[1] * lbl_80369430;
        col3 = *Ui_GetColor(0xB);
        id = lbl_803674F4;
        tex = *fn_8006EDD8(id, 0x22);
        tw = (f32)tex[1];
        th = (f32)tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(id, 0x22, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetPrimParam(lbl_80369418);
        f23v = lbl_803695FC + bx;
        f24v = lbl_803694CC + by;
        Prim2D_SetQuadMin(f23v, f24v, lbl_80369418, lbl_80369418);
        Prim2D_SetQuadMax(f23v + sw, f24v + sh, tw, th);
        Prim2D_SetColor(col3.r, col3.g, col3.b, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
    } else if (t >= lbl_80369604) {
        tex = *fn_8006EDD8(lbl_803674F4, 0x23);
        sh = (f32)tex[0] * lbl_80369430;
        sw = (f32)tex[1] * lbl_80369430;
        col4 = *Ui_GetColor(0xA);
        id = lbl_803674F4;
        tex = *fn_8006EDD8(id, 0x23);
        tw = (f32)tex[1];
        th = (f32)tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(id, 0x23, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetPrimParam(lbl_80369418);
        f24v = lbl_80369608 + bx;
        f23v = lbl_80369480 + by;
        Prim2D_SetQuadMin(f24v, f23v, lbl_80369418, th);
        Prim2D_SetQuadMax(f24v + sw, f23v + sh, tw, lbl_80369418);
        Prim2D_SetColor(col4.r, col4.g, col4.b, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
    } else if (t <= lbl_8036960C) {
        tex = *fn_8006EDD8(lbl_803674F4, 0x23);
        sh = (f32)tex[0] * lbl_80369430;
        sw = (f32)tex[1] * lbl_80369430;
        col5 = *Ui_GetColor(0xB);
        id = lbl_803674F4;
        tex = *fn_8006EDD8(id, 0x23);
        tw = (f32)tex[1];
        th = (f32)tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(id, 0x23, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetPrimParam(lbl_80369418);
        f24v = lbl_80369608 + bx;
        f23v = lbl_80369480 + by;
        Prim2D_SetQuadMin(f24v, f23v, lbl_80369418, lbl_80369418);
        Prim2D_SetQuadMax(f24v + sw, f23v + sh, tw, th);
        Prim2D_SetColor(col5.r, col5.g, col5.b, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
    }

    if (*(u32 *)((u8 *)arg0 + 0x5C) != 0) {
        lbl_803674BC[1] = 0;
        lbl_803674BC[2] = 0x8C;
        lbl_803674BC[3] = 0x1E0;
        lbl_803674BC[0] = (s16)(lbl_80369610 + bx);
        Prim2D_Begin();
        fn_80009BC0(fn_8008532C, lbl_803674BC);
        Prim2D_PrepareTex();
        fn_8007B4D8((s32)(lbl_80369614 + bx), (s32)(lbl_80369618 + by), 0xFF, *(void **)((u8 *)arg0 + 0x5C));
        Prim2D_Begin();
        fn_80009B98();
        Prim2D_PrepareTex();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036942C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    fn_800A8A88(nameId);
    w = (f32)Text_MeasureWidth(fn_800A8A88(nameId), -1, lbl_80369430);
    fn_8001003C((s32)((lbl_8036961C + bx) - (lbl_80369514 * w)), (s32)(by - lbl_8036949C), 1, 0, 0, fn_800A8A88(nameId), lbl_80369430, lbl_80369418);

    if (classId != 0) {
        fn_8001003C((s32)(lbl_803695FC + bx), (s32)(lbl_803694B4 + by), 2, 0, 0, fn_800A8978(classId), lbl_80369430, lbl_80369418);
    }

    f23v = lbl_8036959C + by;
    fn_8001003C((s32)(lbl_80369620 + bx), (s32)f23v, 8, 0, 0, Msg_Expand(gUiStrings + 0x364), lbl_80369430, lbl_80369418);
    fn_8001003C((s32)(lbl_80369624 + bx), (s32)f23v, 2, 0, 0, gUiStrings + 0x240, (s8)*(u8 *)((u8 *)unit + 0x19A), lbl_80369430, lbl_80369418);
    fn_8001003C((s32)(lbl_80369628 + bx), (s32)f23v, 8, 0, 0, Msg_Expand(gUiStrings + 0x36A), lbl_80369430, lbl_80369418);
    if (fn_800386B0(unit) == 0xFF) {
        fn_8001003C((s32)(lbl_8036962C + bx), (s32)f23v, 2, 0, 0, gUiStrings + 0x2DF, lbl_80369430, lbl_80369418);
    } else {
        fn_8001003C((s32)(lbl_80369630 + bx), (s32)f23v, 2, 0, 0, gUiStrings + 0x240, (s8)fn_800386B0(unit), lbl_80369430, lbl_80369418);
    }

    f31v = lbl_80369634 + by;
    fn_8001003C((s32)(lbl_803695FC + bx), (s32)f31v, 8, 0, 0, Msg_Expand(gUiStrings + 0x370), lbl_80369430, lbl_80369418);
    fn_8001003C((s32)(lbl_80369638 + bx), (s32)f31v, 2, 0, 0, gUiStrings + 0x240, (s8)*(u8 *)((u8 *)unit + 0x1A8), lbl_80369430, lbl_80369418);
    fn_8001003C((s32)(lbl_80369498 + bx), (s32)f31v, 0xC, 0, 0, gUiStrings + 0x244, fn_8003B2D0(unit), lbl_80369430, lbl_80369418);

    f29v = lbl_8036963C + bx;
    f23v = lbl_80369438 + by;
    fn_8001003C((s32)f29v, (s32)f23v, 8, 0, 0, Msg_Expand(gUiStrings + 0x376), lbl_80369430, lbl_80369418);
    fn_8001003C((s32)(lbl_80369640 + bx), (s32)f23v, 2, 0, 0, gUiStrings + 0x240, fn_8003A398(unit), lbl_80369430, lbl_80369418);
    fn_8001003C((s32)(lbl_80369644 + bx), (s32)f23v, 8, 0, 0, Msg_Expand(gUiStrings + 0x37D), lbl_80369430, lbl_80369418);
    fn_8001003C((s32)f30v, (s32)f23v, 2, 0, 0, gUiStrings + 0x240, fn_8003A1E0(unit), lbl_80369430, lbl_80369418);

    f23v = lbl_80369648 + by;
    fn_8001003C((s32)f29v, (s32)f23v, 8, 0, 0, Msg_Expand(gUiStrings + 0x384), lbl_80369430, lbl_80369418);
    child = *(void **)((u8 *)unit + 0x194);
    if (child != NULL) {
        fn_800A8A88(*(s32 *)((u8 *)child + 0x188));
        w = (f32)Text_MeasureWidth(fn_800A8A88(*(s32 *)((u8 *)child + 0x188)), -1, lbl_80369430);
        fn_8001003C((s32)((lbl_80369428 + bx) - (lbl_80369514 * w)), (s32)f23v, 2, 0, 0, fn_800A8A88(*(s32 *)((u8 *)child + 0x188)), lbl_80369430, lbl_80369418);
    }

    fn_8001003C((s32)f29v, (s32)f31v, 8, 0, 0, Msg_Expand(gUiStrings + 0x38C), lbl_80369430, lbl_80369418);

    f23v = lbl_8036964C + bx;
    f25v = lbl_803694EC + f23v;
    walk = arg0;
    xOff = 0;
    i = 0;
    do {
        if (*(s16 *)((u8 *)walk + 0x24) == -1) {
            break;
        }
        Ui_DrawIcon(lbl_802F0308, (s32)(f23v + (f32)xOff), (s32)f31v);
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036942C);
        Prim2D_PrepareTex();
        fn_8001003C((s32)(f25v + (f32)xOff), (s32)f31v, 3, 0, 1, gUiStrings + 0x215, (s16)*(s16 *)((u8 *)walk + 0x2E), lbl_80369430, lbl_80369418);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369430);
        Prim2D_PrepareTex();
        i += 1;
        xOff += 0x1A;
        walk = (u8 *)walk + 2;
    } while (i < 5);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369650);
    Prim2D_PrepareTex();
    fn_8004BD1C(unit, &sp24, lbl_8036943C);
    PSMTXRotRad(sp120, 0x7A, lbl_80369654 * *(f32 *)((u8 *)arg0 + 0x64));
    fn_802029C4(sp120, &sp24, &sp24);
    PSMTXScale(spF0, lbl_8036943C, lbl_8036943C, lbl_8036943C);
    PSMTXRotRad(sp90, 0x78, lbl_80369658);
    PSMTXRotRad(sp60, 0x79, lbl_80369654 * (lbl_80369518 + *(f32 *)((u8 *)arg0 + 0x64)));
    PSMTXRotRad(sp30, 0x78, lbl_8036965C);
    f24v = sp24;
    f23v = sp28;
    PSMTXTrans(spC0, lbl_803695A4 + bx + f24v, lbl_80369660 + by + f23v, lbl_80369664);
    PSMTXConcat(sp90, spF0, sp120);
    PSMTXConcat(sp60, sp120, sp120);
    PSMTXConcat(sp30, sp120, sp120);
    PSMTXConcat(spC0, sp120, sp120);
    PSMTXCopy(sp120, (u8 *)*(void **)((u8 *)arg0 + 0x60) + 0x10);
    Model_SetAlpha(*(void **)((u8 *)arg0 + 0x60), *(u8 *)((u8 *)arg0 + 8));
    fn_8005F780(*(void **)((u8 *)arg0 + 0x60), 0xFF);
    fn_80060060(*(void **)((u8 *)arg0 + 0x60));
    fn_800609DC(*(void **)((u8 *)arg0 + 0x60));
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_80369418, lbl_80369418, lbl_80369664, lbl_80369430);
    Prim2D_SetTex(0, 0x410);
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(0xB);
    fn_80007340(fn_800852BC, *(void **)((u8 *)arg0 + 0x60));
    Prim2D_EndPrim();
    fn_8004DDB8(0x32);
}
#pragma use_lmw_stmw reset
