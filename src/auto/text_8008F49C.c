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
extern s32 lbl_803693C0;
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

void fn_8008F49C(void) {
    void fn_8008F4BC(void);
    fn_8008F4BC();
}

void fn_8008F4BC(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    s32 fn_80230BCC(s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    s32 fn_800067B4(void);
    void fn_800072B0(s32 *, s32 *, s32 *, s32 *);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    void Prim2D_SetColorPacked(s32 *, s32);
    extern f32 lbl_80369754;
    extern f32 gZeroF;
    extern f64 lbl_80369770;
    extern f32 lbl_80369778;
    extern f32 lbl_8036977C;

    s32 c0, c1, c2, c3;
    s32 *pal;
    f32 x0, y0, x1, y1;
    f32 cur, step, nstep, zero;
    f32 t;
    s32 i, n, idx, count;
    s32 a, b;

    Prim2D_Begin();
    Prim2D_SetTransform(gZeroF, gZeroF, lbl_80369778, lbl_80369754);
    Prim2D_SetTex(0, 0);
    Prim2D_PrepareTex();

    a = *(s32 *)((u8 *)arg0 + 0x34);
    b = *(s32 *)((u8 *)arg0 + 0x38);
    x0 = (f32)a;
    y0 = (f32)b;
    x1 = (f32)(a + *(s32 *)((u8 *)arg0 + 0x3C));
    y1 = (f32)(b + *(s32 *)((u8 *)arg0 + 0x40));
    t = lbl_8036977C + x0;
    cur = t;
    idx = 1;
    count = fn_80230BCC(0xF);
    zero = gZeroF;
    step = (x1 - cur) / (f32)count;
    nstep = -step;
    for (i = 0; i < count; i++) {
        Prim2D_AddPrim(3);
        pal = *(s32 **)((u8 *)arg0 + 0x30);
        if (step >= zero) {
            Prim2D_SetRect(cur, y0, step, lbl_8036977C);
            n = idx + 1;
            c3 = pal[(n - fn_800067B4()) & 0x1F];
            c2 = pal[(idx - fn_800067B4()) & 0x1F];
            c1 = pal[(n - fn_800067B4()) & 0x1F];
            c0 = pal[(idx - fn_800067B4()) & 0x1F];
            fn_800072B0(&c0, &c1, &c2, &c3);
        } else {
            Prim2D_SetRect(cur + step, y0, nstep, lbl_8036977C);
            c3 = pal[(idx - fn_800067B4()) & 0x1F];
            n = idx + 1;
            c2 = pal[(n - fn_800067B4()) & 0x1F];
            c1 = pal[(idx - fn_800067B4()) & 0x1F];
            c0 = pal[(n - fn_800067B4()) & 0x1F];
            fn_800072B0(&c0, &c1, &c2, &c3);
        }
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        cur += step;
        idx += 1;
    }

    idx = 0x11;
    cur = lbl_8036977C + y0;
    count = fn_80230BCC(0xF);
    zero = gZeroF;
    step = (y1 - cur) / (f32)count;
    nstep = -step;
    for (i = 0; i < count; i++) {
        Prim2D_AddPrim(3);
        pal = *(s32 **)((u8 *)arg0 + 0x30);
        if (step >= zero) {
            Prim2D_SetRect(x1, cur, lbl_8036977C, step);
            n = idx + 1;
            c3 = pal[(n - fn_800067B4()) & 0x1F];
            c2 = pal[(n - fn_800067B4()) & 0x1F];
            c1 = pal[(idx - fn_800067B4()) & 0x1F];
            c0 = pal[(idx - fn_800067B4()) & 0x1F];
            fn_800072B0(&c0, &c1, &c2, &c3);
        } else {
            Prim2D_SetRect(x1, cur + step, lbl_8036977C, nstep);
            c3 = pal[(idx - fn_800067B4()) & 0x1F];
            c2 = pal[(idx - fn_800067B4()) & 0x1F];
            n = idx + 1;
            c1 = pal[(n - fn_800067B4()) & 0x1F];
            c0 = pal[(n - fn_800067B4()) & 0x1F];
            fn_800072B0(&c0, &c1, &c2, &c3);
        }
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        cur += step;
        idx += 1;
    }

    cur = x1;
    idx = 1;
    count = fn_80230BCC(0xF);
    zero = gZeroF;
    step = (t - x1) / (f32)count;
    nstep = -step;
    for (i = 0; i < count; i++) {
        Prim2D_AddPrim(3);
        pal = *(s32 **)((u8 *)arg0 + 0x30);
        if (step >= zero) {
            Prim2D_SetRect(cur, y1, step, lbl_8036977C);
            n = idx + 1;
            c3 = pal[(n - fn_800067B4()) & 0x1F];
            c2 = pal[(idx - fn_800067B4()) & 0x1F];
            c1 = pal[(n - fn_800067B4()) & 0x1F];
            c0 = pal[(idx - fn_800067B4()) & 0x1F];
            fn_800072B0(&c0, &c1, &c2, &c3);
        } else {
            Prim2D_SetRect(cur + step, y1, nstep, lbl_8036977C);
            c3 = pal[(idx - fn_800067B4()) & 0x1F];
            n = idx + 1;
            c2 = pal[(n - fn_800067B4()) & 0x1F];
            c1 = pal[(idx - fn_800067B4()) & 0x1F];
            c0 = pal[(n - fn_800067B4()) & 0x1F];
            fn_800072B0(&c0, &c1, &c2, &c3);
        }
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        cur += step;
        idx += 1;
    }

    cur = y1;
    idx = 0x11;
    count = fn_80230BCC(0xF);
    zero = gZeroF;
    step = ((lbl_8036977C + y0) - y1) / (f32)count;
    nstep = -step;
    for (i = 0; i < count; i++) {
        Prim2D_AddPrim(3);
        pal = *(s32 **)((u8 *)arg0 + 0x30);
        if (step >= zero) {
            Prim2D_SetRect(x0, cur, lbl_8036977C, step);
            n = idx + 1;
            c3 = pal[(n - fn_800067B4()) & 0x1F];
            c2 = pal[(n - fn_800067B4()) & 0x1F];
            c1 = pal[(idx - fn_800067B4()) & 0x1F];
            c0 = pal[(idx - fn_800067B4()) & 0x1F];
            fn_800072B0(&c0, &c1, &c2, &c3);
        } else {
            Prim2D_SetRect(x0, cur + step, lbl_8036977C, nstep);
            c3 = pal[(idx - fn_800067B4()) & 0x1F];
            c2 = pal[(idx - fn_800067B4()) & 0x1F];
            n = idx + 1;
            c1 = pal[(n - fn_800067B4()) & 0x1F];
            c0 = pal[(n - fn_800067B4()) & 0x1F];
            fn_800072B0(&c0, &c1, &c2, &c3);
        }
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        cur += step;
        idx += 1;
    }

    {
        f32 ox = lbl_80369754 + x0;
        f32 oy = lbl_80369754 + y0;
        Prim2D_AddPrim(1);
        Prim2D_SetRect(ox, oy, lbl_8036977C, lbl_8036977C);
        pal = *(s32 **)((u8 *)arg0 + 0x30);
        c0 = pal[(0 - fn_800067B4()) & 0x1F];
        Prim2D_SetColorPacked(&c0, (s32)pal);
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRect(x1 - lbl_80369754, oy, lbl_8036977C, lbl_8036977C);
        pal = *(s32 **)((u8 *)arg0 + 0x30);
        c0 = pal[(0x10 - fn_800067B4()) & 0x1F];
        Prim2D_SetColorPacked(&c0, (s32)pal);
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRect(x1 - lbl_80369754, y1 - lbl_80369754, lbl_8036977C, lbl_8036977C);
        pal = *(s32 **)((u8 *)arg0 + 0x30);
        c0 = pal[(0 - fn_800067B4()) & 0x1F];
        Prim2D_SetColorPacked(&c0, (s32)pal);
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRect(ox, y1 - lbl_80369754, lbl_8036977C, lbl_8036977C);
        pal = *(s32 **)((u8 *)arg0 + 0x30);
        c0 = pal[(0x10 - fn_800067B4()) & 0x1F];
        Prim2D_SetColorPacked(&c0, (s32)pal);
        Prim2D_EndPrim();
    }
}

