/* Functions from 0x8007C5E4 to 0x8009F0BC, found by decomp-toolkit. */
#include "common.h"
#include "global.h"

typedef struct BorderColor { u32 rgba; } BorderColor;
extern s32 Game_GetFrameCount(void);
extern s32 Abs(s32);
static inline f32 BorderStep(f32 end, f32 start, s32 *count) {
    *count = Abs(15);
    return (end - start) / (f32)*count;
}
static inline BorderColor GetColor_8008F4BC(u8 *s, s32 idx) {
    return (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F];
}
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

void fn_8008F49C(void) {
    void fn_8008F4BC(void);
    fn_8008F4BC();
}

#pragma use_lmw_stmw on
void fn_8008F4BC(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    s32 Abs(s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetCornerColors(BorderColor *, BorderColor *, BorderColor *, BorderColor *);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    void Prim2D_SetColorPacked(BorderColor *);
    extern const f32 lbl_80369754;
    extern const f32 gZeroF;
    extern const f64 lbl_80369770;
    extern const f32 lbl_80369778;
    extern const f32 lbl_8036977C;

    BorderColor d3_1, d2_1, d1_1, d0_1, c3_1, c2_1, c1_1, c0_1;
    BorderColor d3_2, d2_2, d1_2, d0_2, c3_2, c2_2, c1_2, c0_2;
    BorderColor d3_3, d2_3, d1_3, d0_3, c3_3, c2_3, c1_3, c0_3;
    BorderColor d3_4, d2_4, d1_4, d0_4, c3_4, c2_4, c1_4, c0_4;
    BorderColor e0, e1, e2, e3;
    u8 *s;
    f32 t, ty, x0, y0, x1, y1, cur, step1, nstep1;
    s32 idx, n, i, count;
    s32 a, b;

    s = (u8 *)arg0;
    Prim2D_Begin();
    Prim2D_SetTransform(gZeroF, gZeroF, lbl_80369778, lbl_80369754);
    Prim2D_SetTex(0, 0);
    Prim2D_PrepareTex();

    a = *(s32 *)(s + 0x34);
    b = *(s32 *)(s + 0x38);
    x0 = (f32)a;
    y0 = (f32)b;
    x1 = (f32)(a + *(s32 *)(s + 0x3C));
    y1 = (f32)(b + *(s32 *)(s + 0x40));
    t = lbl_8036977C + x0;

    cur = t;
    idx = 1;
    count = Abs(0xF);
    step1 = (x1 - cur) / (f32)count;
    nstep1 = -step1;
    for (i = 0; i < count; i++) {
        Prim2D_AddPrim(3);
        if (step1 >= gZeroF) {
            Prim2D_SetRect(cur, y0, step1, lbl_8036977C);
            { BorderColor color = (*(BorderColor **)(s + 0x30))[((n = idx + 1) - Game_GetFrameCount()) & 0x1F]; c3_1 = color; }
            { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; c2_1 = color; }
            { BorderColor color = (*(BorderColor **)(s + 0x30))[(n - Game_GetFrameCount()) & 0x1F]; c1_1 = color; }
            { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; c0_1 = color; }
            Prim2D_SetCornerColors(&c0_1, &c1_1, &c2_1, &c3_1);
        } else {
            Prim2D_SetRect(cur + step1, y0, nstep1, lbl_8036977C);
            { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; d3_1 = color; }
            { BorderColor color = (*(BorderColor **)(s + 0x30))[((n = idx + 1) - Game_GetFrameCount()) & 0x1F]; d2_1 = color; }
            { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; d1_1 = color; }
            { BorderColor color = (*(BorderColor **)(s + 0x30))[(n - Game_GetFrameCount()) & 0x1F]; d0_1 = color; }
            Prim2D_SetCornerColors(&d0_1, &d1_1, &d2_1, &d3_1);
        }
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        cur += step1;
        idx += 1;
    }

    {
        f32 step, nstep;
        idx = 0x11;
        ty = lbl_8036977C + y0;
        cur = ty;
        count = Abs(0xF);
        step = (y1 - cur) / (f32)count;
        nstep = -step;
        for (i = 0; i < count; i++) {
            Prim2D_AddPrim(3);
            if (step >= gZeroF) {
                Prim2D_SetRect(x1, cur, lbl_8036977C, step);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((n = idx + 1) - Game_GetFrameCount()) & 0x1F]; c3_2 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(n - Game_GetFrameCount()) & 0x1F]; c2_2 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; c1_2 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; c0_2 = color; }
                Prim2D_SetCornerColors(&c0_2, &c1_2, &c2_2, &c3_2);
            } else {
                Prim2D_SetRect(x1, cur + step, lbl_8036977C, nstep);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; d3_2 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; d2_2 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((n = idx + 1) - Game_GetFrameCount()) & 0x1F]; d1_2 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(n - Game_GetFrameCount()) & 0x1F]; d0_2 = color; }
                Prim2D_SetCornerColors(&d0_2, &d1_2, &d2_2, &d3_2);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            cur += step;
            idx += 1;
        }
    }

    {
        f32 nstep, step;
        cur = x1;
        idx = 1;
        count = Abs(0xF);
        step = (t - x1) / (f32)count;
        nstep = -step;
        for (i = 0; i < count; i++) {
            Prim2D_AddPrim(3);
            if (step >= gZeroF) {
                Prim2D_SetRect(cur, y1, step, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((n = idx + 1) - Game_GetFrameCount()) & 0x1F]; c3_3 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; c2_3 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(n - Game_GetFrameCount()) & 0x1F]; c1_3 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; c0_3 = color; }
                Prim2D_SetCornerColors(&c0_3, &c1_3, &c2_3, &c3_3);
            } else {
                Prim2D_SetRect(cur + step, y1, nstep, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; d3_3 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((n = idx + 1) - Game_GetFrameCount()) & 0x1F]; d2_3 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; d1_3 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(n - Game_GetFrameCount()) & 0x1F]; d0_3 = color; }
                Prim2D_SetCornerColors(&d0_3, &d1_3, &d2_3, &d3_3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            cur += step;
            idx += 1;
        }
    }

    {
        f32 nstep, step;
        cur = y1;
        idx = 0x11;
        count = Abs(0xF);
        step = (ty - y1) / (f32)count;
        nstep = -step;
        for (i = 0; i < count; i++) {
            Prim2D_AddPrim(3);
            if (step >= gZeroF) {
                Prim2D_SetRect(x0, cur, lbl_8036977C, step);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((n = idx + 1) - Game_GetFrameCount()) & 0x1F]; c3_4 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(n - Game_GetFrameCount()) & 0x1F]; c2_4 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; c1_4 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; c0_4 = color; }
                Prim2D_SetCornerColors(&c0_4, &c1_4, &c2_4, &c3_4);
            } else {
                Prim2D_SetRect(x0, cur + step, lbl_8036977C, nstep);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; d3_4 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(idx - Game_GetFrameCount()) & 0x1F]; d2_4 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((n = idx + 1) - Game_GetFrameCount()) & 0x1F]; d1_4 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[(n - Game_GetFrameCount()) & 0x1F]; d0_4 = color; }
                Prim2D_SetCornerColors(&d0_4, &d1_4, &d2_4, &d3_4);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            cur += step;
            idx += 1;
        }
    }

    {
        f32 oy, ox;
        Prim2D_AddPrim(1);
        ox = lbl_80369754 + x0;
        oy = lbl_80369754 + y0;
        Prim2D_SetRect(ox, oy, lbl_8036977C, lbl_8036977C);
        e0 = GetColor_8008F4BC(s, 0);
        Prim2D_SetColorPacked(&e0);
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRect(x1 - lbl_80369754, oy, lbl_8036977C, lbl_8036977C);
        e1 = GetColor_8008F4BC(s, 0x10);
        Prim2D_SetColorPacked(&e1);
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRect(x1 - lbl_80369754, y1 - lbl_80369754, lbl_8036977C, lbl_8036977C);
        e2 = GetColor_8008F4BC(s, 0);
        Prim2D_SetColorPacked(&e2);
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRect(ox, y1 - lbl_80369754, lbl_8036977C, lbl_8036977C);
        e3 = GetColor_8008F4BC(s, 0x10);
        Prim2D_SetColorPacked(&e3);
        Prim2D_EndPrim();
    }
}
