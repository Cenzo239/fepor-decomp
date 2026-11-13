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
extern s32 lbl_803693C4;
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

void Ui_DrawTerrainInfoDecor(s32 tex, s32 mode, f32 x, f32 y) {
    void Prim2D_EmitQuad(void);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_BindTexture(s32, s32, s32);
    extern f32 lbl_803697E4;
    extern f32 lbl_803697F8;
    extern f32 lbl_803697FC;
    extern f32 lbl_80369808;
    extern f32 lbl_8036980C;
    extern f32 lbl_8036981C;
    extern f32 lbl_80369830;
    extern f32 lbl_80369844;
    extern f32 lbl_80369860;
    extern f32 lbl_80369868;
    extern f32 lbl_8036987C;
    extern f32 lbl_80369880;
    extern f32 lbl_80369884;
    extern f32 lbl_80369888;
    extern f32 lbl_8036988C;

    // Draw terrain-info popup frame pieces for mode 0/1/2 (tex slots 8/9/A).
    switch (mode) {
    case 0:
        Prim2D_Begin();
        Prim2D_SetTransform(x, y, lbl_80369808, lbl_8036980C);
        Prim2D_BindTexture(tex, 8, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_8036987C, lbl_803697FC, lbl_803697E4, lbl_803697E4, lbl_80369860, lbl_8036981C);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_80369880, lbl_803697FC, lbl_80369830, lbl_803697E4, lbl_80369884, lbl_8036981C);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_80369888, lbl_803697FC, lbl_80369868, lbl_803697E4, lbl_803697FC, lbl_8036981C);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        break;
    case 1:
        Prim2D_Begin();
        Prim2D_SetTransform(x, y, lbl_80369808, lbl_8036980C);
        Prim2D_BindTexture(tex, 9, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_803697F8, lbl_803697FC, 0.0f, 0.0f, lbl_803697F8, lbl_8036981C);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        break;
    case 2:
        Prim2D_Begin();
        Prim2D_SetTransform(x, y, lbl_80369808, lbl_8036980C);
        Prim2D_BindTexture(tex, 0xA, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_80369844, lbl_803697FC, 0.0f, 0.0f, lbl_8036988C, lbl_803697FC);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        break;
    }
}

void fn_8009B738(void* arg0, void* arg1) {
    if (arg1 != NULL && arg0 != NULL) {
        u32* src = (u32*)arg1;
        u32* dst = (u32*)arg0;
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        dst[4] = src[4];
        dst[5] = src[5];
        dst[6] = src[6];
    }
}

void fn_8009B900(s32 arg0, s32 arg1) {
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void fn_8014BB58(s32, s32, void *, char *);
    extern f32 lbl_803698FC;
    extern f32 lbl_80369900;
    extern s32 lbl_803698B8;
    extern s32 lbl_803698BC;
    extern s32 lbl_803698C0;
    extern s32 lbl_803698C4;
    extern s32 lbl_803698C8;
    extern s32 lbl_803698CC;
    extern u8 gDebugHudStrs[];

    s32 c0, c1, c2, c3, c4, c5;

    Prim2D_Begin();
    Prim2D_SetTransform((f32)arg0, (f32)arg1, lbl_803698FC, lbl_80369900);
    Prim2D_PrepareTex();

    c0 = lbl_803698B8;
    fn_8014BB58(0x13A, 0x20, &c0, (char *)gDebugHudStrs + 0x2F);
    c1 = lbl_803698BC;
    fn_8014BB58(0x13A, 0x38, &c1, (char *)gDebugHudStrs + 0x32);
    c2 = lbl_803698C0;
    fn_8014BB58(0x13A, 0x78, &c2, (char *)gDebugHudStrs + 0x37);
    c3 = lbl_803698C4;
    fn_8014BB58(0x10A, 0x20, &c3, (char *)gDebugHudStrs + 0x3B);
    c4 = lbl_803698C8;
    fn_8014BB58(0x10A, 0x90, &c4, (char *)gDebugHudStrs + 0x3F);
    c5 = lbl_803698CC;
    fn_8014BB58(0x10A, 0x40, &c5, (char *)gDebugHudStrs + 0x43);
}

/* Draw the debug guide rectangle and optional T/E markers from gUiInputFlags. */
void Debug_DrawGuideFrame(void) {
    void Prim2D_SetText(u8 *);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Prim2D_EndPrim(void);
    extern u8 gDebugHudStrs[];
    extern s32 gUiInputFlags;
    extern f32 lbl_803698FC;
    extern f32 lbl_80369900;
    extern f32 lbl_8036992C;
    extern f32 lbl_80369930;
    extern f32 lbl_80369934;
    extern f32 lbl_80369938;
    extern f32 lbl_8036993C;
    extern f32 lbl_80369940;
    extern f32 lbl_80369944;
    extern f32 lbl_80369948;
    extern f32 lbl_8036994C;
    extern f32 lbl_80369950;
    extern f32 lbl_80369954;
    extern f32 lbl_80369958;
    extern f32 lbl_8036995C;
    extern f32 lbl_80369960;
    extern f32 lbl_80369964;
    extern f32 lbl_80369968;

    Prim2D_Begin();
    Prim2D_SetTransform(lbl_803698FC, lbl_803698FC, lbl_803698FC, lbl_80369900);
    Prim2D_SetTex(0, 0);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_80369930, lbl_80369934, lbl_80369938, lbl_80369934);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_80369938, lbl_80369934, lbl_80369938, lbl_8036993C);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_80369938, lbl_8036993C, lbl_80369930, lbl_8036993C);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_80369930, lbl_80369934, lbl_80369930, lbl_8036993C);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_80369940, lbl_80369944, lbl_80369948, lbl_80369944);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_8036992C, lbl_8036994C, lbl_8036992C, lbl_80369950);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_80369954, lbl_80369944, lbl_80369958, lbl_80369944);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_8036995C, lbl_80369960, lbl_8036995C, lbl_80369964);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTex(0, 3);
    Prim2D_PrepareTex();
    if (gUiInputFlags & 2) {
        Prim2D_AddPrim(7);
        Prim2D_SetPos(lbl_80369930, lbl_80369934);
        Prim2D_SetText(gDebugHudStrs + 0x47);
        Prim2D_EndPrim();
    }
    if (gUiInputFlags & 1) {
        Prim2D_AddPrim(7);
        Prim2D_SetPos(lbl_80369968, lbl_80369934);
        Prim2D_SetText(gDebugHudStrs + 0x49);
        Prim2D_EndPrim();
    }
}

#pragma use_lmw_stmw on
void fn_8009D95C(s32 arg0, s32 arg1) {
    void Prim2D_SetText(void *);
    void fn_800072B0(u32 *, u32 *, u32 *, u32 *);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void sprintf(void *, void *, s32, ...);
    extern u32 lbl_80312100[];
    extern u32 lbl_80369890, lbl_80369894, lbl_80369898, lbl_8036989C;
    extern u32 lbl_803698A0, lbl_803698A4, lbl_803698A8, lbl_803698AC;
    extern u32 lbl_803698B0, lbl_803698B4;
    extern f32 lbl_803698F8, lbl_803698FC, lbl_80369900;
    extern f32 lbl_8036996C, lbl_803699D0, lbl_803699D4, lbl_803699D8;
    extern f32 lbl_803699DC, lbl_803699E0, lbl_803699E4;
    extern f32 lbl_80369930, lbl_80369968, lbl_80369970;
    extern u8 gDebugHudStrs[];
    s32 x;
    s32 y;
    u32 *tbl;
    f32 f31;
    f32 f30;
    f32 f29;
    u32 c0, c1;
    u32 a, b, c, d;
    u32 bus, rate, ticks;
    char buf[0x80];
    s32 i;

    x = arg0;
    y = arg1;
    Prim2D_Begin();
    Prim2D_SetTransform((f32)x, (f32)(y + 0x28), lbl_803698FC, lbl_80369900);
    Prim2D_SetTex(0, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_803698FC, lbl_8036996C, lbl_803699D0, lbl_8036996C);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_803698FC, lbl_803698FC, lbl_803698FC, lbl_803699D4);
    Prim2D_EndPrim();

    tbl = lbl_80312100;
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 1000u;
    ticks = tbl[2] << 3;
    c0 = lbl_80369894;
    c1 = lbl_80369890;
    f31 = lbl_803699D0 * ((f32)(ticks / rate) / lbl_803699D8);
    Prim2D_AddPrim(3);
    Prim2D_SetRect(lbl_803698FC, lbl_803698FC, f31, lbl_8036996C);
    Prim2D_EmitQuad();
    a = c1; b = c1; c = c0; d = c0;
    fn_800072B0(&a, &b, &c, &d);
    Prim2D_EndPrim();

    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 1000u;
    ticks = tbl[3] << 3;
    f30 = lbl_803698FC + f31;
    c0 = lbl_8036989C;
    c1 = lbl_80369898;
    f31 = lbl_803699D0 * ((f32)(ticks / rate) / lbl_803699D8);
    Prim2D_AddPrim(3);
    Prim2D_SetRect(f30, lbl_803698FC, f31, lbl_8036996C);
    Prim2D_EmitQuad();
    a = c1; b = c1; c = c0; d = c0;
    fn_800072B0(&a, &b, &c, &d);
    Prim2D_EndPrim();

    f30 = f30 + f31;
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 1000u;
    ticks = tbl[4] << 3;
    c0 = lbl_803698A4;
    c1 = lbl_803698A0;
    f31 = lbl_803699D0 * ((f32)(ticks / rate) / lbl_803699D8);
    Prim2D_AddPrim(3);
    Prim2D_SetRect(f30, lbl_803698FC, f31, lbl_8036996C);
    Prim2D_EmitQuad();
    a = c1; b = c1; c = c0; d = c0;
    fn_800072B0(&a, &b, &c, &d);
    Prim2D_EndPrim();

    f29 = f30 + f31;
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 1000u;
    ticks = tbl[7] << 3;
    c0 = lbl_803698AC;
    c1 = lbl_803698A8;
    f31 = lbl_803699D0 * ((f32)(ticks / rate) / lbl_803699D8);
    Prim2D_AddPrim(3);
    Prim2D_SetRect(f29, lbl_803698FC, f31, lbl_8036996C);
    Prim2D_EmitQuad();
    a = c1; b = c1; c = c0; d = c0;
    fn_800072B0(&a, &b, &c, &d);
    Prim2D_EndPrim();

    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 1000u;
    ticks = tbl[1] << 3;
    c0 = lbl_803698B4;
    c1 = lbl_803698B0;
    f30 = lbl_803699D0 * ((f32)(ticks / rate) / lbl_803699D8);
    Prim2D_AddPrim(3);
    Prim2D_SetRect(f29 + f31, lbl_803698FC, f30, lbl_8036996C);
    Prim2D_EmitQuad();
    a = c1; b = c1; c = c0; d = c0;
    fn_800072B0(&a, &b, &c, &d);
    Prim2D_EndPrim();

    Prim2D_AddPrim(1);
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 1000u;
    ticks = tbl[6] << 3;
    Prim2D_SetRect(lbl_803698FC, lbl_8036996C,
                lbl_803699D0 * ((f32)(ticks / rate) / lbl_803699D8),
                lbl_803699DC);
    Prim2D_SetColor(0xFF, 0xA0, 0xFF, 0xFF);
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_SetTransform((f32)x, (f32)y, lbl_803698FC, lbl_80369900);
    Prim2D_SetTex(0, 0x23);
    Prim2D_PrepareTex();

    Prim2D_AddPrim(0xA);
    Prim2D_SetPos(lbl_803698FC, lbl_803698FC);
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 1000u;
    ticks = tbl[2] << 3;
    {
        u32 qq = ticks / rate;
        sprintf(buf, gDebugHudStrs + 0x199,
                    (s32)(lbl_803698F8 * ((f32)qq / lbl_803699D8)));
    }
    Prim2D_SetColor(0x80, 0xC8, 0xFF, 0xFF);
    Prim2D_SetText(buf);
    Prim2D_EndPrim();

    Prim2D_AddPrim(0xA);
    Prim2D_SetPos(lbl_803698FC, lbl_8036996C);
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 1000u;
    ticks = tbl[3] << 3;
    {
        u32 qq = ticks / rate;
        sprintf(buf, gDebugHudStrs + 0x1AF,
                    (s32)(lbl_803698F8 * ((f32)qq / lbl_803699D8)));
    }
    Prim2D_SetColor(0xA0, 0xFF, 0xA0, 0xFF);
    Prim2D_SetText(buf);
    Prim2D_EndPrim();

    if ((f32)tbl[7] > lbl_803699E0) {
        Prim2D_AddPrim(0xA);
        Prim2D_SetPos(lbl_803698FC, lbl_803699E4);
        bus = *(u32 *)0x800000F8 >> 2;
        rate = bus / 1000u;
        ticks = tbl[7] << 3;
        {
            u32 qq = ticks / rate;
            sprintf(buf, gDebugHudStrs + 0x1C5,
                        (s32)(lbl_803698F8 * ((f32)qq / lbl_803699D8)));
        }
        Prim2D_SetColor(0xFF, 0xA0, 0xA0, 0xFF);
        Prim2D_SetText(buf);
        Prim2D_EndPrim();
    }

    Prim2D_AddPrim(0xA);
    Prim2D_SetPos(lbl_803698FC, lbl_80369930);
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 1000u;
    ticks = tbl[1] << 3;
    {
        u32 qq = ticks / rate;
        sprintf(buf, gDebugHudStrs + 0x1DB,
                    (s32)(lbl_803698F8 * ((f32)qq / lbl_803699D8)));
    }
    Prim2D_SetColor(0xFF, 0xFF, 0x80, 0xFF);
    Prim2D_SetText(buf);
    Prim2D_EndPrim();

    Prim2D_AddPrim(0xA);
    Prim2D_SetPos(lbl_803698FC, lbl_80369970);
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 1000u;
    ticks = tbl[5] << 3;
    {
        u32 qq = ticks / rate;
        sprintf(buf, gDebugHudStrs + 0x1F1,
                    (s32)(lbl_803698F8 * ((f32)qq / lbl_803699D8)));
    }
    Prim2D_SetText(buf);
    Prim2D_EndPrim();

    Prim2D_AddPrim(0xA);
    Prim2D_SetPos(lbl_803698FC, lbl_80369968);
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 1000u;
    ticks = tbl[6] << 3;
    {
        u32 qq = ticks / rate;
        sprintf(buf, gDebugHudStrs + 0x207,
                    (s32)(lbl_803698F8 * ((f32)qq / lbl_803699D8)));
    }
    Prim2D_SetColor(0xFF, 0xB4, 0xFF, 0xFF);
    Prim2D_SetText(buf);
    Prim2D_EndPrim();

    for (i = 0; i < 8; i++) {
        if (*(u32 *)((u8 *)tbl + 0x24 + i * 4) != 0) {
            Prim2D_Begin();
            Prim2D_SetTransform((f32)x, (f32)y, lbl_803698FC, lbl_80369900);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(0xA);
            Prim2D_SetPos(lbl_803698FC, (f32)(-0xC - i * 8));
            sprintf(buf, gDebugHudStrs + 0x21D, i);
            Prim2D_SetText(buf);
            Prim2D_EndPrim();
        }
    }
    for (i = 0; i < 4; i++) {
        if (*(u32 *)((u8 *)tbl + 0x64 + i * 4) != 0) {
            Prim2D_Begin();
            Prim2D_SetTransform((f32)x, (f32)y, lbl_803698FC, lbl_80369900);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(0xA);
            Prim2D_SetPos(lbl_803698FC, (f32)(-0xC - i * 8));
            sprintf(buf, gDebugHudStrs + 0x234, i,
                        *(u32 *)((u8 *)tbl + 0x64 + i * 4));
            Prim2D_SetText(buf);
            Prim2D_EndPrim();
        }
    }
}
#pragma use_lmw_stmw reset
void fn_8009E574(void) {
    extern u8 lbl_80312100[];
    lbl_80312100[0xc4] = 1;
}

void fn_8009E588(void) {
    s32 fn_8006EB9C(void);
    void fn_8021F1B8(s32, void *, void *);
    s32 spC;
    s32 sp8;

    fn_8021F1B8(fn_8006EB9C(), &sp8, &spC);
}

void fn_8009E5B4(void) {
    s32 fn_8006EB9C(void *);
    void fn_8021F1B8(s32, void *, void *);
    extern u8 lbl_80312100[];
    s32 sp8;

    lbl_80312100[0xC4] = 0;
    fn_8021F1B8(fn_8006EB9C(lbl_80312100), &sp8, lbl_80312100 + 0xB4);
}

void fn_8009E5F8(void) {
    extern u8 lbl_80312100[];
    *(s32 *)(lbl_80312100 + 0x24) = 0;
    *(s32 *)(lbl_80312100 + 0x28) = 0;
    *(s32 *)(lbl_80312100 + 0x2C) = 0;
    *(s32 *)(lbl_80312100 + 0x30) = 0;
    *(s32 *)(lbl_80312100 + 0x34) = 0;
    *(s32 *)(lbl_80312100 + 0x38) = 0;
    *(s32 *)(lbl_80312100 + 0x3C) = 0;
    *(s32 *)(lbl_80312100 + 0x40) = 0;
    *(s32 *)(lbl_80312100 + 0x64) = 0;
    *(s32 *)(lbl_80312100 + 0x68) = 0;
    *(s32 *)(lbl_80312100 + 0x6C) = 0;
    *(s32 *)(lbl_80312100 + 0x70) = 0;
}

void fn_8009E638(void) {
    extern u8 lbl_80312100[];
    *(s32 *)(lbl_80312100 + 0x1c) = 0;
}

void fn_8009E64C(void) {
    u32 OSGetTick(void);
    extern u8 lbl_80312100[];
    u8 *p = lbl_80312100;

    *(u32 *)(p + 0x1c) = OSGetTick() - *(u32 *)(p + 0x1c);
}

void fn_8009E688(void) {
    extern u16 lbl_80312100[];
    *(u32 *)((u8 *)lbl_80312100 + 0x1c) = OSGetTick();
}

void fn_8009E6B4(void) {
    u32 OSGetTick(void);
    extern u8 lbl_80312100[];
    u8 *p = lbl_80312100;

    *(u32 *)(p + 0x10) = OSGetTick() - *(u32 *)(p + 0x10);
}

void fn_8009E6F0(void) {
    extern u16 lbl_80312100[];
    *(u32 *)((u8 *)lbl_80312100 + 0x10) = OSGetTick();
}

void fn_8009E71C(void) {
    u32 OSGetTick(void);
    void fn_800070C8(void *, void *, void *, void *);
    extern u8 lbl_80312100[];
    u8 *p = lbl_80312100;

    *(u32 *)(p + 0xC) = OSGetTick() - *(u32 *)(p + 0xC);
    fn_800070C8(p + 0xB8, p + 0xBC, p + 0xBE, p + 0xC0);
}

void fn_8009E774(void) {
    extern u16 lbl_80312100[];
    *(u32 *)((u8 *)lbl_80312100 + 0xc) = OSGetTick();
}

void fn_8009E7A0(void) {
    u32 OSGetTick(void);
    extern u8 lbl_80312100[];
    u8 *p = lbl_80312100;

    *(u32 *)(p + 8) = OSGetTick() - *(u32 *)(p + 8);
}

void fn_8009E7DC(void) {
    extern u16 lbl_80312100[];
    *(u32 *)((u8 *)lbl_80312100 + 0x8) = OSGetTick();
}

void fn_8009E808(void) {
    u32 OSGetTick(void);
    extern u8 lbl_80312100[];
    u8 *p = lbl_80312100;

    *(u32 *)(p + 4) = OSGetTick() - *(u32 *)(p + 4);
}

void fn_8009E844(void) {
    extern u16 lbl_80312100[];
    *(u32 *)((u8 *)lbl_80312100 + 0x4) = OSGetTick();
}

void fn_8009E9A0(void) {
    s32 OSGetTick();
    extern s32 lbl_80312100[];
    lbl_80312100[5] = OSGetTick() - lbl_80312100[0];
}

void fn_8009E9D0(void) {
    s32 OSGetTick(void);
    s32 fn_80225BF4(s32);
    s32 fn_8006EB9C(void);
    void fn_8021F1B8(s32, void *, void *);
    extern u8 lbl_80312100[];
    extern u8 lbl_803121C8[];
    s32 sp8;
    s32 tick;

    tick = OSGetTick();
    *(s32 *)lbl_80312100 = tick;
    fn_80225BF4(tick);
    fn_8021F1B8(fn_8006EB9C(), &sp8, lbl_803121C8 + 0x9C);
}

