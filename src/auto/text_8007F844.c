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

void fn_8007F844(s32 arg0, f32 fx, f32 fy, f32 fz) {
    typedef struct { u8 r, g, b, a; } Color;
    typedef struct { f32 v[9]; } Arr9;
    void fn_800072B0(s32 *, s32 *, s32 *, s32 *);
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
    Color *Ui_GetColor(s32);
    f64 fn_802380D0(f32);
    f64 fn_80238638(f32);
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
    Color col;
    u32 sp24;
    u32 sp20;
    u8 sp28, sp29, sp2A, sp2B;
    s32 sp8, sp10, sp14, sp18, sp1C;
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
    s32 i, j;
    f32 t;
    f32 k28, k29, k31, k17, k18;
    f32 yOff;
    u8 *bp;

    iz = (s32)fz;
    frac = fz - (f32)iz;
    tex = *fn_8006EDD8(gUiAtlas, 0x1B);
    sh = (f32)tex[0] * lbl_80369430;
    sw = (f32)tex[1] * lbl_80369430;
    col = *Ui_GetColor(1);
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
    Prim2D_SetColor(col.r, col.g, col.b, 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369520);
    Prim2D_PrepareTex();
    yOff = lbl_80369528 + fy;
    fn_8001003C((s32)(lbl_80369524 + fx), (s32)yOff, 2, 0, 0, gUiStrings + 0x240, iz, lbl_80369430, lbl_80369418);
    fn_8001003C((s32)(lbl_8036952C + fx), (s32)yOff, 0xC, 0, 0, gUiStrings + 0x244, arg0, lbl_80369430, lbl_80369418);

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
                s0 = (f32)fn_80238638(ang0);
                c0 = (f32)fn_802380D0(ang0);
                s1 = (f32)fn_80238638(ang1);
                c1 = (f32)fn_802380D0(ang1);
                if (i == 0) {
                    sp24 = lbl_80369410;
                    bp = (u8 *)&sp24;
                    sp28 = bp[0];
                    sp29 = bp[1];
                    sp2A = bp[2];
                    sp2B = bp[3];
                } else {
                    sp20 = lbl_80369414;
                    bp = (u8 *)&sp20;
                    bp[1] = (u8)((s32)(lbl_80369438 * lbl_803674C4) + 0xA);
                    bp[0] = (u8)(s32)(lbl_803694E4 * lbl_803674C4);
                    bp[2] = (u8)((s32)(lbl_80369548 * lbl_803674C4) + 0xA);
                    sp28 = bp[0];
                    sp29 = bp[1];
                    sp2A = bp[2];
                    sp2B = bp[3];
                }
                Prim2D_AddPrim(3);
                Prim2D_SetQuadMin(c0 * k17 + f21, f20 - s0 * k17, lbl_80369418, lbl_80369418);
                fn_80007648(c0 * k18 + f21, f20 - s0 * k18, lbl_80369418, lbl_80369418);
                fn_80007628(c1 * k17 + f21, f20 - s1 * k17, lbl_80369418, lbl_80369418);
                Prim2D_SetQuadMax(c1 * k18 + f21, f20 - s1 * k18, lbl_80369418, lbl_80369418);
                sp8 = *(s32 *)&sp28;
                sp10 = sp8;
                sp14 = sp8;
                sp18 = sp8;
                sp1C = sp8;
                fn_800072B0(&sp1C, &sp18, &sp14, &sp10);
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

#pragma use_lmw_stmw on
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
    s32 fn_80105A5C(void *);
    void *fn_8010586C(void *);
    void fn_8007F844(u8, f32, f32, f32);
    extern u8 gUiStrings[];
    extern u8 lbl_802F0350[];
    extern s32 gUiAtlas;
    extern f32 lbl_80369418;
    extern f32 lbl_8036942C;
    extern f32 lbl_80369430;
    extern f32 lbl_80369434;
    extern f32 lbl_80369438;
    extern f32 lbl_8036943C;
    extern f32 lbl_80369448;
    extern f64 lbl_80369440;
    extern f64 lbl_80369470;
    extern f32 lbl_803694D0;
    extern f32 lbl_803694E4;
    extern f32 lbl_80369518;
    extern f32 lbl_8036951C;
    extern f32 lbl_80369528;
    extern f32 lbl_80369554;
    extern f32 lbl_80369558;
    extern f32 lbl_8036955C;
    extern f32 lbl_80369560;
    extern f32 lbl_80369564;
    extern f32 lbl_80369568;
    extern f32 lbl_8036956C;
    extern f32 lbl_80369570;
    extern f32 lbl_80369574;
    extern f32 lbl_80369578;
    extern f32 lbl_8036957C;

    Color color;
    Color color2;
    f32 y;
    f32 x;
    void *obj58;
    f32 h, w, sw, sh, bx, by, tx, fx, fy, ty;
    u16 *tex;
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

    tex = *fn_8006EDD8(gUiAtlas, 0x20);
    sh = (f32)tex[0] * lbl_80369430;
    sw = (f32)tex[1] * lbl_80369430;
    color2 = *Ui_GetColor(0);
    id = gUiAtlas;
    tex = *fn_8006EDD8(id, 0x20);
    w = (f32)tex[1];
    h = (f32)tex[0];
    Prim2D_Begin();
    Prim2D_BindTexture(id, 0x20, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_80369418);
    fx = lbl_80369564 + x;
    fy = lbl_80369568 + y;
    Prim2D_SetQuadMin(fx, fy, lbl_80369418, lbl_80369418);
    Prim2D_SetQuadMax(fx + sw, fy + sh, w, h);
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
    a = fn_80105A5C((u8 *)obj58 + 0x1BC);
    b = fn_80105A5C((u8 *)unit + 0x1C);
    fn_8007F844(*(u8 *)((u8 *)unit + 0x40), lbl_803694D0 + x, lbl_8036956C + y, (f32)(a - b));

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    ty = lbl_80369518 + y;
    fn_8001003C((s32)(lbl_80369438 + x), (s32)ty, 6, 1, 0, Msg_Expand(gUiStrings + 0x254), lbl_80369430, lbl_80369418);

    ypos = (s32)ty;
    slot = arg0;
    off = 0;
    for (i = 0; i < 2; i++) {
        item = *(void **)((u8 *)slot + 0x38);
        if (item != 0) {
            fx = (x + lbl_80369570) + (f32)off;
            Ui_DrawIcon(lbl_802F0350, (s32)(fx - lbl_803694E4), ypos, *(u8 *)((u8 *)item + 0x19));
            Prim2D_Begin();
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            fn_8001003C((s32)(lbl_80369528 + fx), ypos, 1, 1, 0, fn_8010586C(item), lbl_80369430, lbl_80369418);
        }
        off += 0x77;
        slot = (u8 *)slot + 4;
    }

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    fn_8001003C((s32)(lbl_80369448 + x), (s32)(lbl_80369574 + y), 6, 1, 0, Msg_Expand(gUiStrings + 0x25B), lbl_80369430, lbl_80369418);

    baseX = lbl_8036957C + x;
    baseY = lbl_80369578 + y;
    labelX = lbl_80369528 + baseX;
    iconX = (s32)(baseX - lbl_803694E4);
    slot = (u8 *)arg0 + 8;
    for (i = 2; i < 7; i++) {
        item = *(void **)((u8 *)slot + 0x38);
        if (item != 0) {
            fy = baseY + (f32)((i - 2) << 5);
            Ui_DrawIcon(lbl_802F0350, iconX, (s32)fy, *(u8 *)((u8 *)item + 0x19));
            Prim2D_Begin();
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            fn_8001003C((s32)labelX, (s32)fy, 1, 1, 0, fn_8010586C(item), lbl_80369430, lbl_80369418);
        }
        slot = (u8 *)slot + 4;
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036951C);
    Prim2D_PrepareTex();
}

void fn_80080698(void *arg0) {
    void fn_800875B4(s32, s32, void *, f32, f32, f32, f32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void *Msg_Expand(void *);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void Prim2D_EndPrim(void);
    void **fn_8006EDD8(void *, s32);
    s32 *Ui_GetColor(s32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, f32, f32);
    u8 Status_Test(void *, s32);
    void *Res_GetByName(void *);
    extern f32 lbl_80369580;
    extern f32 lbl_80369584;
    extern f32 lbl_80369588;
    extern f32 lbl_8036942C;
    extern f32 lbl_8036943C;
    extern f32 lbl_80369438;
    extern f32 lbl_803694D4;
    extern f32 lbl_80369434;
    extern f32 lbl_80369430;
    extern f32 lbl_80369418;
    extern f32 lbl_80369488;
    extern f64 lbl_80369440;
    extern void *gUiAtlas;
    extern u8 gUiStrings[];

    void *self = arg0;
    void *unit;
    void *entry;
    f32 x, y;
    f32 x2, y2;
    u16 flags;

    unit = *(void **)(*(u8 **)((u8 *)self + 0x58) + 0x18C);
    y = lbl_80369580 + *(f32 *)((u8 *)self + 0x18);
    x = *(f32 *)((u8 *)self + 0x14);
    fn_800875B4(0xB3, 0, *(void **)((u8 *)self + 0x58), x, y, lbl_80369584, lbl_80369588);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036942C);
    Prim2D_PrepareTex();

    flags = *(u16 *)((u8 *)unit + 0x3A);
    if (flags & 0x20) {
        entry = Msg_Expand(gUiStrings + 0x26B);
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x12);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        x2 = lbl_8036943C + x;
        y2 = lbl_80369438 + y;
        Prim2D_SetRect(x2, y2, lbl_803694D4, lbl_80369434);
        Prim2D_EmitQuad();
        Prim2D_SetColor(0, 0, 0, 0xFF);
        Prim2D_EndPrim();
        (void)entry;
        (void)gUiAtlas;
        (void)lbl_80369430;
        (void)lbl_80369418;
        (void)lbl_80369440;
        (void)fn_8006EDD8;
        (void)Ui_GetColor;
        (void)Prim2D_BindTexture;
        (void)Prim2D_SetPrimParam;
        (void)Prim2D_SetQuadMin;
        (void)Prim2D_SetQuadMax;
        (void)fn_8001003C;
        (void)Status_Test;
        (void)Res_GetByName;
        (void)lbl_80369488;
    } else {
        (void)Status_Test(*(u8 **)((u8 *)self + 0x58) + 0x1BC, 9);
    }
}

#pragma global_optimizer off
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
    f32 y;
    f32 x;
    void *unit;
    f32 h, w, sw, sh, tx, bx, by;
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
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count << 5)), 1, 1, 0, Msg_Expand(gUiStrings + 0x292), lbl_80369430, lbl_80369418);
        count += 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x4) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count << 5)), 1, 1, 0, Msg_Expand(gUiStrings + 0x29B), lbl_80369430, lbl_80369418);
        count += 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x8) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count << 5)), 1, 1, 0, Msg_Expand(gUiStrings + 0x2A4), lbl_80369430, lbl_80369418);
        count += 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x40) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count << 5)), 1, 1, 0, Msg_Expand(gUiStrings + 0x2AD), lbl_80369430, lbl_80369418);
        count += 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x100) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count << 5)), 1, 1, 0, Msg_Expand(gUiStrings + 0x2B8), lbl_80369430, lbl_80369418);
        count += 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x2) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count << 5)), 1, 1, 0, Msg_Expand(gUiStrings + 0x2C2), lbl_80369430, lbl_80369418);
        count += 1;
    }
    if (*(u16 *)((u8 *)unit + 0x3A) & 0x80) {
        fn_8001003C((s32)(lbl_80369438 + x), (s32)(lbl_8036959C + y + (f32)(count << 5)), 1, 1, 0, Msg_Expand(gUiStrings + 0x2CB), lbl_80369430, lbl_80369418);
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369430);
    Prim2D_PrepareTex();
}
#pragma global_optimizer on
void fn_80081830(void *arg0) {
    typedef struct { u8 r, g, b, a; } Color;
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
    s8 Unit_GetCon(void *);
    void sprintf(void *, void *, s8, ...);
    s16 Text_MeasureWidth(void *, s32, f32);
    u32 fn_800A883C(void *, s32);
    s32 fn_800A886C(s8 *);
    void Ui_DrawIcon(void *, s32, s32, s32);
    extern u8 gUiStrings[];
    extern u8 lbl_802F0350[];
    extern s32 gUiAtlas;
    extern f32 lbl_80369418;
    extern f32 lbl_8036942C;
    extern f32 lbl_80369430;
    extern f32 lbl_80369434;
    extern f32 lbl_80369438;
    extern f32 lbl_8036943C;
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
    f32 y = M2C_FIELD(arg0, f32 *, 0x18);
    f32 x = lbl_80369430 + M2C_FIELD(arg0, f32 *, 0x14);
    void *obj58 = M2C_FIELD(arg0, void **, 0x58);
    void *unit = M2C_FIELD(obj58, void **, 0x18C);
    Color color;
    f32 h, w, sw, sh, tx;
    u16 *tex;
    void *str;
    s32 id, xpos;
    s16 width;
    s8 spC, sp8;
    char buf[64];

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
    sprintf(buf, gUiStrings + 0x215, Unit_GetCon(M2C_FIELD(arg0, void **, 0x58)));
    width = Text_MeasureWidth(buf, -1, lbl_80369430);
    fn_8001003C((s32)((lbl_803695A4 + x) - (f32)(width / 2)), (s32)(lbl_8036959C + y), 1, 1, 0, buf, lbl_80369430, lbl_80369418);
    spC = (s8)(fn_800A883C(unit, 0) >> 24);
    xpos = (s32)(lbl_803694BC + x);
    Ui_DrawIcon(lbl_802F0350, xpos, (s32)(lbl_80369574 + y), fn_800A886C(&spC));
    sp8 = (s8)(fn_800A883C(unit, 1) >> 24);
    Ui_DrawIcon(lbl_802F0350, xpos, (s32)(lbl_803695A8 + y), fn_800A886C(&sp8));
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369430);
    Prim2D_PrepareTex();
}
