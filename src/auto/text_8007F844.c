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

extern f64 lbl_80369440;
extern f64 lbl_80369470;

extern void* fn_800980D4(s32 arg0);
extern void fn_8017E394(void* arg0, void* arg1, void* arg2, s32 arg3);

extern u8 lbl_80289EB8[16];

extern f32 lbl_803697E0;
extern f32 lbl_803697E4;

#pragma use_lmw_stmw on
void fn_8007F844(s32 arg0, f32 fx, f32 fy, f32 fz) {
    typedef struct { f32 v[9]; } Arr9;
    typedef union { u32 w; u8 b[4]; } ColorWord;
    void Prim2D_SetCornerColors(s32 *, s32 *, s32 *, s32 *);
    void Prim2D_EmitQuad(void);
    void fn_80007628(f32, f32, f32, f32);
    void fn_80007648(f32, f32, f32, f32);
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
    u16 **fn_8006EDD8(s32, s32);
    void *Ui_GetColor(s32);
    f64 fn_802380D0(f32);
    f64 sin(f32);
    extern Arr9 lbl_8026C824;
    extern Arr9 lbl_8026C848;
    extern u8 gUiStrings[];
    extern f32 lbl_803674C4;
    extern s8 lbl_803674C8;
    extern f32 lbl_803674CC;
    extern s8 lbl_803674D0;
    extern s32 gUiAtlas;
    extern u32 lbl_80369410;
    extern u32 lbl_80369414;
    extern f32 lbl_80369418;
    extern f32 lbl_80369430;
    extern f32 lbl_80369438;
    extern f64 lbl_80369440;
    extern f64 lbl_80369470;
    extern f32 lbl_803694CC;
    extern f32 lbl_803694E4;
    extern f32 lbl_80369514;
    extern f32 lbl_8036951C;
    extern f32 lbl_80369520;
    extern f32 lbl_80369524;
    extern f32 lbl_80369528;
    extern f32 lbl_8036952C;
    extern f32 lbl_80369530;
    extern f32 lbl_80369534;
    extern f32 lbl_80369538;
    extern f32 lbl_8036953C;
    extern f32 lbl_80369540;
    extern f32 lbl_80369544;
    extern f32 lbl_80369548;
    extern f32 lbl_8036954C;
    extern f32 lbl_80369550;
    Arr9 arrA;
    Arr9 arrB;
    u32 sp24;
    u32 sp20;
    ColorWord cw;
    s32 sp1C, sp18, sp14, sp10, sp8;
    u32 col;
    s32 iz;
    f32 frac;
    f32 f21, f20;
    f32 sh, sw, h, w;
    f32 baseX, baseY;
    f32 ang0, ang1;
    f32 s0, c0, s1, c1;
    f32 *pA, *pB;
    u16 *tex;
    s32 id;
    s32 i;
    s32 j;
    f32 t;
    f32 k28, k29, k31, k17, k18;
    f32 yOff, yOff2;
    u8 *bp;
    f32 cr, cg, cb;
    f64 magic_u;
    f64 magic_s;

    magic_u = lbl_80369440;
    magic_s = lbl_80369470;
    (void)magic_u;
    (void)magic_s;

    iz = (s32)fz;
    frac = fz - (f32)iz;
    tex = *fn_8006EDD8(gUiAtlas, 0x1B);
    sh = (f32)tex[0] * lbl_80369430;
    sw = (f32)tex[1] * lbl_80369430;
    col = *(u32 *)Ui_GetColor(1);
    id = gUiAtlas;
    tex = *fn_8006EDD8(id, 0x1B);
    w = (f32)tex[1];
    h = (f32)tex[0];
    Prim2D_Begin();
    Prim2D_BindTexture(id, 0x1B, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_80369418);
    Prim2D_SetQuadMin(fx, fy, lbl_80369418, lbl_80369418);
    Prim2D_SetQuadMax(fx + sw, fy + sh, w, h);
    Prim2D_SetColor(((u8 *)&col)[0], ((u8 *)&col)[1], ((u8 *)&col)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369520);
    Prim2D_PrepareTex();
    yOff = lbl_80369528 + fy;
    yOff2 = lbl_80369528 + fy;
    fn_8001003C((s32)(lbl_80369524 + fx), (s32)yOff, 2, 0, 0, gUiStrings + 0x240, iz, lbl_80369430, lbl_80369418);
    fn_8001003C((s32)(lbl_8036952C + fx), (s32)yOff2, 0xC, 0, 0, gUiStrings + 0x244, arg0, lbl_80369430, lbl_80369418);

    arrA = lbl_8026C824;
    arrB = lbl_8026C848;
    if (lbl_803674C8 == 0) {
        lbl_803674C8 = 1;
        lbl_803674C4 = lbl_80369418;
    }
    if (lbl_803674D0 == 0) {
        lbl_803674D0 = 1;
        lbl_803674CC = lbl_80369530;
    }
    t = lbl_803674C4 + lbl_803674CC;
    lbl_803674C4 = t;
    if (t >= lbl_80369430) {
        lbl_803674C4 = lbl_80369430;
        lbl_803674CC = lbl_80369534;
    }
    if (lbl_803674C4 <= lbl_80369514) {
        lbl_803674C4 = lbl_80369514;
        lbl_803674CC = lbl_80369530;
    }
    if (arg0 != 0) {
        baseX = lbl_80369538 + fx;
        baseY = lbl_8036953C + fy;
        k28 = lbl_80369544;
        k29 = lbl_8036951C;
        k31 = lbl_80369540;
        k17 = lbl_803694CC;
        k18 = lbl_8036954C;
        pA = arrA.v;
        pB = arrB.v;
        for (i = 0; i < 10; i++) {
            Prim2D_Begin();
            if (i == 0) {
                Prim2D_SetTex(0, 0x12);
            } else {
                Prim2D_SetTex(0, 0x22);
            }
            Prim2D_PrepareTex();
            Prim2D_Begin();
            Prim2D_AddZ(lbl_80369520);
            Prim2D_PrepareTex();
            f21 = lbl_803674C4 * pA[0] + baseX;
            f20 = lbl_803674C4 * pB[0] + baseY;
            for (j = 0; j < iz + 1; j++) {
                if (j >= arg0) {
                    break;
                }
                ang0 = k31 - k28 * (k29 * ((f32)j / (f32)arg0));
                if (j == iz) {
                    ang1 = k31 - k28 * (k29 * (((f32)j + frac) / (f32)arg0));
                } else {
                    ang1 = k31 - k28 * (k29 * ((f32)(j + 1) / (f32)arg0));
                }
                s0 = (f32)sin(ang0);
                c0 = (f32)fn_802380D0(ang0);
                s1 = (f32)sin(ang1);
                c1 = (f32)fn_802380D0(ang1);
                if (i == 0) {
                    sp24 = lbl_80369410;
                    bp = (u8 *)&sp24;
                    cw.b[0] = bp[0];
                    cw.b[1] = bp[1];
                    cw.b[2] = bp[2];
                    cw.b[3] = bp[3];
                } else {
                    sp20 = lbl_80369414;
                    bp = (u8 *)&sp20;
                    cr = lbl_803694E4 * lbl_803674C4;
                    cg = lbl_80369438 * lbl_803674C4;
                    cb = lbl_80369548 * lbl_803674C4;
                    bp[0] = (u8)(s32)cr;
                    bp[1] = (u8)((s32)cg + 0xA);
                    bp[2] = (u8)((s32)cb + 0xA);
                    cw.b[0] = bp[0];
                    cw.b[1] = bp[1];
                    cw.b[2] = bp[2];
                    cw.b[3] = bp[3];
                }
                Prim2D_AddPrim(3);
                Prim2D_SetQuadMin(c0 * k17 + f21, f20 - s0 * k17, lbl_80369418, lbl_80369418);
                fn_80007648(c0 * k18 + f21, f20 - s0 * k18, lbl_80369418, lbl_80369418);
                fn_80007628(c1 * k17 + f21, f20 - s1 * k17, lbl_80369418, lbl_80369418);
                Prim2D_SetQuadMax(c1 * k18 + f21, f20 - s1 * k18, lbl_80369418, lbl_80369418);
                sp8 = cw.w;
                sp10 = sp8;
                sp14 = sp8;
                sp18 = sp8;
                sp1C = sp8;
                Prim2D_SetCornerColors(&sp1C, &sp18, &sp14, &sp10);
                Prim2D_EndPrim();
            }
            pA++;
            pB++;
        }
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369550);
    Prim2D_PrepareTex();
}

#pragma push
#pragma optimization_level 2
#pragma opt_common_subs off
#pragma use_lmw_stmw on
#pragma opt_peephole off
void fn_8007FF58(void *arg0) {
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
    void Ui_DrawIcon(void *, s32, s32, s32);
    s32 Status_SumBonus(void *);
    void *fn_8010586C(void *);
    void fn_8007F844(u8, f32, f32, f32);
    extern u8 gUiStrings[];
    extern u8 gItemIconDrawer[];
    extern s32 gUiAtlas;
    extern const f32 lbl_80369418;
    extern const f32 lbl_8036942C;
    extern const f32 lbl_80369430;
    extern const f32 lbl_80369434;
    extern const f32 lbl_80369438;
    extern const f32 lbl_8036943C;
    extern const f32 lbl_80369448;
    extern f64 lbl_80369440;
    extern f64 lbl_80369470;
    extern const f32 lbl_803694D0;
    extern const f32 lbl_803694E4;
    extern const f32 lbl_80369518;
    extern const f32 lbl_8036951C;
    extern const f32 lbl_80369528;
    extern const f32 lbl_80369554;
    extern const f32 lbl_80369558;
    extern const f32 lbl_8036955C;
    extern const f32 lbl_80369560;
    extern const f32 lbl_80369564;
    extern const f32 lbl_80369568;
    extern const f32 lbl_8036956C;
    extern const f32 lbl_80369570;
    extern const f32 lbl_80369574;
    extern const f32 lbl_80369578;
    extern const f32 lbl_8036957C;

    Color color2;
    Color color;
    void *obj58;
    f32 w, h, sw, sh, by, bx, tx, fy, fx, ty;
    f32 sw2, sh2, w2, h2;
    u16 *tex;
    u16 *dim;
    void *str;
    s32 id;
    s32 i, off;
    void *slot;
    void *item;
    void *unit;
    s32 a, b;
    s32 ypos;
    f32 baseX, baseY, labelX;
    s32 iconX;
    f32 x;
    f32 y;

    y = *(f32 *)((u8 *)arg0 + 0x18);
    x = lbl_80369554 + *(f32 *)((u8 *)arg0 + 0x14);
    obj58 = *(void **)((u8 *)arg0 + 0x58);

    fn_800875B4(0xB3, 0, x, y, lbl_80369558, lbl_8036955C);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036942C);
    Prim2D_PrepareTex();
    str = Msg_Expand(gUiStrings + 0x249);
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    bx = lbl_8036943C + x;
    by = lbl_80369438 + y;
    Prim2D_SetRect(bx, by, lbl_80369560, lbl_80369434);
    Prim2D_EmitQuad();
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_EndPrim();
    tex = *fn_8006EDD8(gUiAtlas, 0x1D);
    sh = (f32)tex[0] * lbl_80369430;
    sw = (f32)tex[1] * lbl_80369430;
    color = *Ui_GetColor(1);
    id = gUiAtlas;
    dim = *fn_8006EDD8(id, 0x1D);
    w = (f32)dim[1];
    h = (f32)dim[0];
    Prim2D_Begin();
    Prim2D_BindTexture(id, 0x1D, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_80369418);
    tx = bx + lbl_80369560;
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

    tex = *fn_8006EDD8(gUiAtlas, 0x20);
    sh2 = (f32)tex[0] * lbl_80369430;
    sw2 = (f32)tex[1] * lbl_80369430;
    color2 = *Ui_GetColor(0);
    id = gUiAtlas;
    dim = *fn_8006EDD8(id, 0x20);
    w2 = (f32)dim[1];
    h2 = (f32)dim[0];
    Prim2D_Begin();
    Prim2D_BindTexture(id, 0x20, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_80369418);
    fx = lbl_80369564 + x;
    fy = lbl_80369568 + y;
    Prim2D_SetQuadMin(fx, fy, lbl_80369418, lbl_80369418);
    Prim2D_SetQuadMax(fx + sw2, fy + sh2, w2, h2);
    Prim2D_SetColor(color2.r, color2.g, color2.b, 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036942C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    unit = *(void **)((u8 *)obj58 + 0x18C);
    a = Status_SumBonus((u8 *)obj58 + 0x1BC);
    b = Status_SumBonus((u8 *)unit + 0x1C);
    fn_8007F844(*(u8 *)((u8 *)unit + 0x40), lbl_803694D0 + x, lbl_8036956C + y, (f32)(a - b));

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    fn_8001003C((s32)(lbl_80369438 + x), (s32)(ty = lbl_80369518 + y), 6, 1, 0, Msg_Expand(gUiStrings + 0x254), lbl_80369430, lbl_80369418);

    ypos = (s32)ty;
    slot = arg0;
    off = 0;
    i = 0;
    do {
        item = *(void **)((u8 *)slot + 0x38);
        if (item != 0) {
            fx = (x + lbl_80369570) + (f32)off;
            Ui_DrawIcon(gItemIconDrawer, (s32)(fx - lbl_803694E4), ypos, *(u8 *)((u8 *)item + 0x19));
            Prim2D_Begin();
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            fn_8001003C((s32)(lbl_80369528 + fx), (s32)ty, 1, 1, 0, fn_8010586C(item), lbl_80369430, lbl_80369418);
        }
        i++;
        off += 0x77;
        slot = (u8 *)slot + 4;
    } while (i < 2);

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    fn_8001003C((s32)(lbl_80369448 + x), (s32)(lbl_80369574 + y), 6, 1, 0, Msg_Expand(gUiStrings + 0x25B), lbl_80369430, lbl_80369418);

    baseX = lbl_8036957C + x;
    baseY = lbl_80369578 + y;
    labelX = lbl_80369528 + baseX;
    iconX = (s32)(baseX - lbl_803694E4);
    slot = (u8 *)arg0 + 8;
    i = 2;
    do {
        item = *(void **)((u8 *)slot + 0x38);
        if (item != 0) {
            fy = baseY + (f32)((i - 2) << 5);
            Ui_DrawIcon(gItemIconDrawer, iconX, (s32)fy, *(u8 *)((u8 *)item + 0x19));
            Prim2D_Begin();
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            fn_8001003C((s32)labelX, (s32)fy, 1, 1, 0, fn_8010586C(item), lbl_80369430, lbl_80369418);
        }
        i++;
        slot = (u8 *)slot + 4;
    } while (i < 7);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036951C);
    Prim2D_PrepareTex();
}
#pragma pop
void fn_80080698(void *arg0) {
    typedef struct { u8 r, g, b, a; } Color;
    void fn_800875B4(s32, s32, f32, f32, f32, f32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
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
    u8 Status_Test(void *, s32);
    void *Res_GetByName(void *);
    s32 Unit_GetWpnExp(void *, u8);
    void *WpnRank_GetLetter(s32);
    s32 Str_Cmp(void *, void *);
    s32 fn_8005A310(u8 *, u8, s32);
    void *fn_8001E5D0(u8, u8);
    void Ui_DrawIcon(u8 *, s32, s32, u8);
    s32 Text_MeasureWidth(u8 *, s32, f32);
    s8 fn_8003C114(void *);
    extern f32 lbl_80369580, lbl_80369584, lbl_80369588, lbl_8036958C;
    extern f32 lbl_80369590, lbl_80369594, lbl_80369598;
    extern f32 lbl_803694A4, lbl_80369548;
    extern f32 lbl_8036942C, lbl_8036943C, lbl_80369438, lbl_803694D4, lbl_80369434;
    extern f32 lbl_80369430, lbl_80369418, lbl_80369488, lbl_8036951C, lbl_80369524;
    extern s32 gUiAtlas;
    extern u8 gUiStrings[];
    extern u8 gUiIconDrawer[];
    extern s32 lbl_8026C804[], lbl_8026C814[];

    Color color3;
    Color color;
    Color color2;
    s32 arrB[4];
    s32 arrA[4];
    u8 *unit2;
    u8 *unit;
    f32 tx, sh, sw, h, w, wx, wy;
    f32 by, bx, x, y;
    u16 *tex;
    void *str;
    s32 id;
    s32 i;
    void *letter, *text;
    s32 icon;

    y = lbl_80369580 + *(f32 *)((u8 *)arg0 + 0x18);
    unit = *(u8 **)((u8 *)*(void **)((u8 *)arg0 + 0x58) + 0x18C);
    x = *(f32 *)((u8 *)arg0 + 0x14);
    unit2 = unit;
    fn_800875B4(0xB3, 0, x, y, lbl_80369584, lbl_80369588);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036942C);
    Prim2D_PrepareTex();

    if (*(u16 *)(unit + 0x3A) & 0x20) {
        u8 *strings;
        str = Msg_Expand(gUiStrings + 0x26B);
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
        sh = (f32)tex[0] * lbl_80369430;
        sw = (f32)tex[1] * lbl_80369430;
        color = *Ui_GetColor(1);
        id = gUiAtlas;
        tex = *fn_8006EDD8(id, 0x1D);
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

        strings = gUiStrings;
        for (i = 0; i < 8; i++) {
            arrA[0] = lbl_8026C804[0];
            arrA[1] = lbl_8026C804[1];
            arrA[2] = lbl_8026C804[2];
            arrA[3] = lbl_8026C804[3];
            arrB[0] = lbl_8026C814[0];
            arrB[1] = lbl_8026C814[1];
            arrB[2] = lbl_8026C814[2];
            arrB[3] = lbl_8026C814[3];
            letter = WpnRank_GetLetter(Unit_GetWpnExp(*(void **)((u8 *)arg0 + 0x58), i));
            if (Str_Cmp(letter, strings + 0x15) != 0) {
                wx = x + *(f32 *)&arrA[i];
                wy = y + *(f32 *)&arrB[i];
                if (i == 7 && Status_Test((u8 *)*(void **)((u8 *)arg0 + 0x58) + 0x1BC, 0x23)) {
                    icon = 0x53;
                    text = Msg_Expand(gUiStrings + 0x262);
                } else {
                    icon = (u8)fn_8005A310(gUiIconDrawer, i, 0);
                    text = fn_8001E5D0(i, 0);
                }
                Ui_DrawIcon(gUiIconDrawer, (s32)wx, (s32)(lbl_8036951C + wy), (u8)icon);
                Prim2D_Begin();
                Prim2D_SetTex(0, 0x13);
                Prim2D_PrepareTex();
                Text_MeasureWidth(text, -1, lbl_80369430);
                fn_8001003C((s32)(lbl_80369524 + wx), (s32)wy, 1, 1, 0, letter, lbl_80369430, lbl_80369418);
            }
        }
    } else {
        f32 by2, bx2;
        if (!Status_Test((u8 *)*(void **)((u8 *)arg0 + 0x58) + 0x1BC, 9)) {
            void *res = *(void **)(unit + 0xC);
            unit2 = res != 0 ? (u8 *)Res_GetByName(res) : 0;
        }
        str = Msg_Expand(gUiStrings + 0x274);
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x12);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        bx2 = lbl_8036943C + x;
        by2 = lbl_80369438 + y;
        Prim2D_SetRect(bx2, by2, lbl_80369488, lbl_80369434);
        Prim2D_EmitQuad();
        Prim2D_SetColor(0, 0, 0, 0xFF);
        Prim2D_EndPrim();
        tex = *fn_8006EDD8(gUiAtlas, 0x1D);
        sh = (f32)tex[0] * lbl_80369430;
        sw = (f32)tex[1] * lbl_80369430;
        color2 = *Ui_GetColor(1);
        id = gUiAtlas;
        tex = *fn_8006EDD8(id, 0x1D);
        w = (f32)tex[1];
        h = (f32)tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(id, 0x1D, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetPrimParam(lbl_80369418);
        tx = bx2 + lbl_80369488;
        Prim2D_SetQuadMin(tx, by2, lbl_80369418, lbl_80369418);
        Prim2D_SetQuadMax(tx + sw, by2 + sh, w, h);
        Prim2D_SetColor(color2.r, color2.g, color2.b, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036942C);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        fn_8001003C((s32)(lbl_80369438 + bx2), (s32)(by2 - lbl_8036943C), 9, 0, 0, str, lbl_80369430, lbl_80369418);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369430);
        Prim2D_PrepareTex();
        {
            u16 f2 = *(u16 *)(unit2 + 0x3A);
            s32 texId;
            if (f2 & 0x100) {
                texId = 0x24;
            } else if (f2 & 0x40) {
                texId = 0x25;
            } else if (f2 & 0x80) {
                texId = 0x26;
            }
            tex = *fn_8006EDD8(gUiAtlas, (u16)texId);
            sh = (f32)tex[0] * lbl_80369430;
            sw = (f32)tex[1] * lbl_80369430;
            color3 = *Ui_GetColor(1);
            id = gUiAtlas;
            tex = *fn_8006EDD8(id, (u16)texId);
            w = (f32)tex[1];
            h = (f32)tex[0];
            Prim2D_Begin();
            Prim2D_BindTexture(id, (u16)texId, 0x11);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetPrimParam(lbl_80369418);
            wx = lbl_80369438 + x;
            wy = lbl_8036958C + y;
            Prim2D_SetQuadMin(wx, wy, lbl_80369418, lbl_80369418);
            Prim2D_SetQuadMax(wx + sw, wy + sh, w, h);
            Prim2D_SetColor(color3.r, color3.g, color3.b, 0xFF);
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
        }
        {
            s8 val = fn_8003C114(*(void **)((u8 *)arg0 + 0x58));
            f32 gx = lbl_80369590 + wx;
            f32 gy = lbl_803694A4 + wy;
            f32 ratio = (f32)val / lbl_80369548;
            s32 atlas = gUiAtlas;
            u16 *t27;
            u16 tw, th;
            Prim2D_Begin();
            Prim2D_AddZ(lbl_8036942C);
            Prim2D_PrepareTex();
            Prim2D_Begin();
            Prim2D_BindTexture(atlas, 0x27, 0x11);
            Prim2D_PrepareTex();
            t27 = *fn_8006EDD8(gUiAtlas, 0x27);
            tw = t27[1];
            th = t27[0];
            Prim2D_AddPrim(1);
            Prim2D_SetQuadMin(gx, gy, lbl_80369418, lbl_80369418);
            Prim2D_SetQuadMax(gx + (f32)tw * ratio, gy + (f32)th, (f32)tw * ratio, (f32)th);
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            Prim2D_Begin();
            Prim2D_AddZ(lbl_80369430);
            Prim2D_PrepareTex();
            Prim2D_Begin();
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            val = fn_8003C114(*(void **)((u8 *)arg0 + 0x58));
            fn_8001003C((s32)(lbl_80369594 + x), (s32)by2, 1, 1, 0, gUiStrings + 0x240, lbl_80369430, lbl_80369418, (s32)val);
            fn_8001003C((s32)(lbl_80369598 + x), (s32)by2, 4, 1, 0, gUiStrings + 0x244, lbl_80369430, lbl_80369418, 0x14);
        }
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369430);
    Prim2D_PrepareTex();
}

#pragma push
#pragma optimization_level 3
#pragma opt_common_subs off
void fn_800810BC(void *arg0) {
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
    extern u8 gUiStrings[];
    extern s32 gUiAtlas;
    extern f32 lbl_80369418;
    extern f32 lbl_8036942C;
    extern f32 lbl_80369430;
    extern f32 lbl_80369434;
    extern f32 lbl_80369438;
    extern f32 lbl_8036943C;
    extern f64 lbl_80369440;
    extern f64 lbl_80369470;
    extern f32 lbl_803694E4;
    extern f32 lbl_80369458;
    extern f32 lbl_8036953C;
    extern f32 lbl_80369560;
    extern f32 lbl_8036959C;
    extern f32 lbl_803695A0;

    Color color;
    f32 by;
    f32 bx;
    void *unit;
    f32 h, w, sw, sh, tx;
    f32 y;
    f32 x;
    u16 *tex;
    void *str;
    s32 id;
    s32 count;

    count = 0;
    y = *(f32 *)((u8 *)arg0 + 0x18);
    x = lbl_803695A0 + *(f32 *)((u8 *)arg0 + 0x14);
    unit = *(void **)(*(u8 **)((u8 *)arg0 + 0x58) + 0x18C);

    fn_800875B4(0xB3, 0, x, y, lbl_8036953C, lbl_80369458);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036942C);
    Prim2D_PrepareTex();
    str = Msg_Expand(gUiStrings + 0x27F);
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    bx = lbl_803694E4 + x;
    by = lbl_80369438 + y;
    Prim2D_SetRect(bx, by, lbl_80369560, lbl_80369434);
    Prim2D_EmitQuad();
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_EndPrim();
    tex = *fn_8006EDD8(gUiAtlas, 0x1D);
    sh = (f32)tex[0] * lbl_80369430;
    sw = (f32)tex[1] * lbl_80369430;
    color = *Ui_GetColor(1);
    id = gUiAtlas;
    tex = *fn_8006EDD8(id, 0x1D);
    w = (f32)tex[1];
    h = (f32)tex[0];
    Prim2D_Begin();
    Prim2D_BindTexture(id, 0x1D, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_80369418);
    tx = bx + lbl_80369560;
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

    if (*(u16 *)((u8 *)unit + 0x3A) & 0x20) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)((lbl_8036959C + y) + lbl_80369418), 1, 1, 0, Msg_Expand(gUiStrings + 0x289), lbl_80369430, lbl_80369418);
        count = 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x10) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count * 32)), 1, 1, 0, Msg_Expand(gUiStrings + 0x292), lbl_80369430, lbl_80369418);
        count += 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x4) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count * 32)), 1, 1, 0, Msg_Expand(gUiStrings + 0x29B), lbl_80369430, lbl_80369418);
        count += 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x8) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count * 32)), 1, 1, 0, Msg_Expand(gUiStrings + 0x2A4), lbl_80369430, lbl_80369418);
        count += 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x40) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count * 32)), 1, 1, 0, Msg_Expand(gUiStrings + 0x2AD), lbl_80369430, lbl_80369418);
        count += 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x100) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count * 32)), 1, 1, 0, Msg_Expand(gUiStrings + 0x2B8), lbl_80369430, lbl_80369418);
        count += 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x2) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count * 32)), 1, 1, 0, Msg_Expand(gUiStrings + 0x2C2), lbl_80369430, lbl_80369418);
        count += 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x80) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count * 32)), 1, 1, 0, Msg_Expand(gUiStrings + 0x2CB), lbl_80369430, lbl_80369418);
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369430);
    Prim2D_PrepareTex();
}
#pragma pop
void fn_80081830(void *arg0)
{
  u8 *new_var;
  char new_var3;
  f32 new_var4;
  s32 new_var2;
  typedef struct 
  {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
  } Color;
  void fn_800875B4(s32, s32, void *, f32, f32, f32, f32);
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
  s32 Unit_GetCon(void *);
  void sprintf(void *, void *, s8, ...);
  s16 Text_MeasureWidth(void *, s32, f32);
  u32 fn_800A883C(void *, s32);
  s32 fn_800A886C(s8 *);
  void Ui_DrawIcon(void *, s32, s32, s32);
  extern u8 gUiStrings[];
  extern u8 gItemIconDrawer[];
  extern s32 gUiAtlas;
  extern f32 lbl_80369418;
  extern f32 lbl_8036942C;
  extern f32 lbl_80369430;
  extern f32 lbl_80369434;
  extern f32 lbl_80369438;
  extern f32 lbl_8036943C;
  extern f64 lbl_80369440;
  extern f32 lbl_803694BC;
  extern f32 lbl_803694E4;
  extern f32 lbl_8036953C;
  extern f32 lbl_80369458;
  extern f32 lbl_80369560;
  extern f32 lbl_80369574;
  extern f32 lbl_8036959C;
  extern f32 lbl_803695A4;
  extern f32 lbl_803695A8;
  f32 by;
  f32 bx;
  f32 y = *((f32 *) (((s8 *) arg0) + 0x18));
  f32 x = lbl_80369430 + (*((f32 *) (((s8 *) arg0) + 0x14)));
  void *obj58 = *((void **) (((s8 *) arg0) + 0x58));
  void *unit = *((void **) (((s8 *) obj58) + 0x18C));
  Color color;
  f32 h;
  f32 w;
  f32 sw;
  f32 sh;
  f32 tx;
  u16 *tex;
  void *str;
  s32 id;
  s32 xpos;
  s16 width;
  s8 spC;
  s8 sp8;
  char buf[8];
  fn_800875B4(0xB3, 0, obj58, x, y, lbl_8036953C, lbl_80369458);
  Prim2D_Begin();
  Prim2D_AddZ(lbl_8036942C);
  Prim2D_PrepareTex();
  str = Msg_Expand(gUiStrings + 0x2D4);
  Prim2D_Begin();
  Prim2D_SetTex(0, 0x12);
  Prim2D_PrepareTex();
  Prim2D_AddPrim(1);
  bx = lbl_803694E4 + x;
  new_var3 = 0;
  by = lbl_80369438 + y;
  Prim2D_SetRect(bx, by, lbl_80369560, lbl_80369434);
  Prim2D_EmitQuad();
  Prim2D_SetColor(0, new_var3, new_var3, 0xFF);
  Prim2D_EndPrim();
  tex = *fn_8006EDD8(gUiAtlas, 0x1D);
  sh = ((f32) tex[new_var3]) * lbl_80369430;
  sw = ((f32) tex[1]) * lbl_80369430;
  color = *Ui_GetColor(1);
  id = gUiAtlas;
  tex = *fn_8006EDD8(id, 0x1D);
  w = (f32) tex[1];
  new_var4 = (f32) tex[new_var3];
  h = new_var4;
  Prim2D_Begin();
  Prim2D_BindTexture(id, 0x1D, 0x11);
  Prim2D_PrepareTex();
  Prim2D_AddPrim(1);
  Prim2D_SetPrimParam(lbl_80369418);
  tx = bx + lbl_80369560;
  Prim2D_SetQuadMin(tx, by, lbl_80369418, lbl_80369418);
  Prim2D_SetQuadMax(tx + sw, by + sh, w, h);
  Prim2D_SetColor(color.r, color.g, color.b, 0xFF);
  Prim2D_EmitQuad();
  Prim2D_EndPrim();
  Prim2D_Begin();
  Prim2D_AddZ(lbl_8036942C);
  new_var = gItemIconDrawer;
  Prim2D_PrepareTex();
  Prim2D_Begin();
  Prim2D_SetTex(new_var3, 0x13);
  Prim2D_PrepareTex();
  fn_8001003C((s32) (lbl_80369438 + bx), (s32) (by - lbl_8036943C), 9, new_var3, new_var3, str, lbl_80369430, lbl_80369418);
  Prim2D_Begin();
  Prim2D_AddZ(lbl_80369430);
  Prim2D_PrepareTex();
  Prim2D_Begin();
  Prim2D_SetTex(new_var3, 0x13);
  Prim2D_PrepareTex();
  sprintf(buf, gUiStrings + 0x215, Unit_GetCon(*((void **) (((s8 *) arg0) + 0x58))));
  width = Text_MeasureWidth(buf, -1, lbl_80369430);
  fn_8001003C((s32) ((lbl_803695A4 + x) - ((f32) (width / 2))), (s32) (lbl_8036959C + y), 1, 1, new_var3, buf, lbl_80369430, lbl_80369418);
  spC = (s8) (fn_800A883C(unit, new_var3) >> 24);
  new_var2 = fn_800A886C(&spC);
  xpos = (s32) (lbl_803694BC + x);
  Ui_DrawIcon(new_var, xpos, (s32) (lbl_80369574 + y), new_var2);
  sp8 = (s8) (fn_800A883C(unit, 1) >> 24);
  Ui_DrawIcon(new_var, xpos, (s32) (lbl_803695A8 + y), fn_800A886C(&sp8));
  Prim2D_Begin();
  Prim2D_AddZ(lbl_80369430);
  Prim2D_PrepareTex();
}
