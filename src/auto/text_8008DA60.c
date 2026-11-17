/* Functions from 0x8007C5E4 to 0x8009F0BC, found by decomp-toolkit. */
#include "common.h"
#include "global.h"

typedef struct BorderColor { u32 rgba; } BorderColor;
static inline BorderColor Border_GetColor(void *self, s32 index) {
    s32 Game_GetFrameCount(void);
    return (*(BorderColor **)((u8 *)self + 0x30))[(index - Game_GetFrameCount()) & 31];
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

void fn_8008DA60(void) {
    void fn_8008DA80(void);
    fn_8008DA80();
}

#pragma use_lmw_stmw on
void fn_8008DA80(void *self) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetCornerColors(BorderColor *, BorderColor *, BorderColor *, BorderColor *);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    void Prim2D_End(void);
    s32 Abs(s32);
    s32 Game_GetFrameCount(void);
    extern f32 gZeroF, lbl_80369778, lbl_80369754, lbl_8036977C;
    extern f64 lbl_80369770;
    u8 *s;
    s32 i, n, idx, next;
    f32 nstep, c, step, a, b, zero;

    s = (u8 *)self;
    Prim2D_Begin();
    Prim2D_SetTransform(gZeroF, gZeroF, lbl_80369778, lbl_80369754);
    Prim2D_SetTex(0, 0);
    Prim2D_PrepareTex();

    if (s[0x4C] != 0) {
    {
        BorderColor d3,d2,d1,d0,c3,c2,c1,c0;
        idx=0;
        b=(f32)(*(s32 *)(s + 0x38));
        c=(f32)(*(s32 *)(s + 0x34)+*(s32 *)(s + 0x3C));
        a=(f32)(*(s32 *)(s + 0x34));
        n=Abs(5);
        step=(c-a)/(f32)n;
        nstep=-step;
        zero=gZeroF;
        for (i = 0; i < n; i++) {
            Prim2D_AddPrim(3);
            if (step >= zero) {
                next=idx+1;
                Prim2D_SetRect(a, b, step, lbl_8036977C);
                c3 = Border_GetColor(s, next);
                c2 = Border_GetColor(s, idx);
                c1 = Border_GetColor(s, next);
                c0 = Border_GetColor(s, idx);
                Prim2D_SetCornerColors(&c0, &c1, &c2, &c3);
            } else {
                next=idx+1;
                Prim2D_SetRect(a + step, b, nstep, lbl_8036977C);
                d3 = Border_GetColor(s, idx);
                d2 = Border_GetColor(s, next);
                d1 = Border_GetColor(s, idx);
                d0 = Border_GetColor(s, next);
                Prim2D_SetCornerColors(&d0, &d1, &d2, &d3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
        BorderColor d3,d2,d1,d0,c3,c2,c1,c0;
        idx=5;
        b=(f32)(*(s32 *)(s + 0x34)+*(s32 *)(s + 0x3C));
        c=(f32)(*(s32 *)(s + 0x38)+*(s32 *)(s + 0x44));
        a=(f32)(*(s32 *)(s + 0x38));
        n=Abs(11);
        step=(c-a)/(f32)n;
        nstep=-step;
        zero=gZeroF;
        for (i = 0; i < n; i++) {
            Prim2D_AddPrim(3);
            if (step >= zero) {
                next=idx+1;
                Prim2D_SetRect(b, a, lbl_8036977C, step);
                c3 = Border_GetColor(s, next);
                c2 = Border_GetColor(s, next);
                c1 = Border_GetColor(s, idx);
                c0 = Border_GetColor(s, idx);
                Prim2D_SetCornerColors(&c0, &c1, &c2, &c3);
            } else {
                next=idx+1;
                Prim2D_SetRect(b, a + step, lbl_8036977C, nstep);
                d3 = Border_GetColor(s, idx);
                d2 = Border_GetColor(s, idx);
                d1 = Border_GetColor(s, next);
                d0 = Border_GetColor(s, next);
                Prim2D_SetCornerColors(&d0, &d1, &d2, &d3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
        BorderColor d3,d2,d1,d0,c3,c2,c1,c0;
        idx=16;
        b=(f32)(*(s32 *)(s + 0x38)+*(s32 *)(s + 0x44));
        c=(f32)(*(s32 *)(s + 0x40)+(*(s32 *)(s + 0x34)+*(s32 *)(s + 0x3C)));
        a=(f32)(*(s32 *)(s + 0x34)+*(s32 *)(s + 0x3C));
        n=Abs(11);
        step=(c-a)/(f32)n;
        nstep=-step;
        zero=gZeroF;
        for (i = 0; i < n; i++) {
            Prim2D_AddPrim(3);
            if (step >= zero) {
                next=idx+1;
                Prim2D_SetRect(a, b, step, lbl_8036977C);
                c3 = Border_GetColor(s, next);
                c2 = Border_GetColor(s, idx);
                c1 = Border_GetColor(s, next);
                c0 = Border_GetColor(s, idx);
                Prim2D_SetCornerColors(&c0, &c1, &c2, &c3);
            } else {
                next=idx+1;
                Prim2D_SetRect(a + step, b, nstep, lbl_8036977C);
                d3 = Border_GetColor(s, idx);
                d2 = Border_GetColor(s, next);
                d1 = Border_GetColor(s, idx);
                d0 = Border_GetColor(s, next);
                Prim2D_SetCornerColors(&d0, &d1, &d2, &d3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
        BorderColor d3,d2,d1,d0,c3,c2,c1,c0;
        idx=27;
        b=(f32)(*(s32 *)(s + 0x34)+(*(s32 *)(s + 0x3C)+*(s32 *)(s + 0x40)));
        c=(f32)(*(s32 *)(s + 0x48)+(*(s32 *)(s + 0x38)+*(s32 *)(s + 0x44)));
        a=(f32)(*(s32 *)(s + 0x38)+*(s32 *)(s + 0x44));
        n=Abs(5);
        step=(c-a)/(f32)n;
        nstep=-step;
        zero=gZeroF;
        for (i = 0; i < n; i++) {
            Prim2D_AddPrim(3);
            if (step >= zero) {
                next=idx+1;
                Prim2D_SetRect(b, a, lbl_8036977C, step);
                c3 = Border_GetColor(s, next);
                c2 = Border_GetColor(s, next);
                c1 = Border_GetColor(s, idx);
                c0 = Border_GetColor(s, idx);
                Prim2D_SetCornerColors(&c0, &c1, &c2, &c3);
            } else {
                next=idx+1;
                Prim2D_SetRect(b, a + step, lbl_8036977C, nstep);
                d3 = Border_GetColor(s, idx);
                d2 = Border_GetColor(s, idx);
                d1 = Border_GetColor(s, next);
                d0 = Border_GetColor(s, next);
                Prim2D_SetCornerColors(&d0, &d1, &d2, &d3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
        BorderColor d3,d2,d1,d0,c3,c2,c1,c0;
        idx=0;
        b=(f32)(*(s32 *)(s + 0x38)+(*(s32 *)(s + 0x44)+*(s32 *)(s + 0x48)));
        c=(f32)(*(s32 *)(s + 0x34));
        a=(f32)(*(s32 *)(s + 0x34)+(*(s32 *)(s + 0x3C)+*(s32 *)(s + 0x40)));
        n=Abs(16);
        step=(c-a)/(f32)n;
        nstep=-step;
        zero=gZeroF;
        for (i = 0; i < n; i++) {
            Prim2D_AddPrim(3);
            if (step >= zero) {
                next=idx+1;
                Prim2D_SetRect(a, b, step, lbl_8036977C);
                c3 = Border_GetColor(s, next);
                c2 = Border_GetColor(s, idx);
                c1 = Border_GetColor(s, next);
                c0 = Border_GetColor(s, idx);
                Prim2D_SetCornerColors(&c0, &c1, &c2, &c3);
            } else {
                next=idx+1;
                Prim2D_SetRect(a + step, b, nstep, lbl_8036977C);
                d3 = Border_GetColor(s, idx);
                d2 = Border_GetColor(s, next);
                d1 = Border_GetColor(s, idx);
                d0 = Border_GetColor(s, next);
                Prim2D_SetCornerColors(&d0, &d1, &d2, &d3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
        BorderColor d3,d2,d1,d0,c3,c2,c1,c0;
        idx=16;
        b=(f32)(*(s32 *)(s + 0x34));
        c=(f32)(*(s32 *)(s + 0x38));
        a=(f32)(*(s32 *)(s + 0x38)+(*(s32 *)(s + 0x44)+*(s32 *)(s + 0x48)));
        n=Abs(16);
        step=(c-a)/(f32)n;
        nstep=-step;
        zero=gZeroF;
        for (i = 0; i < n; i++) {
            Prim2D_AddPrim(3);
            if (step >= zero) {
                next=idx+1;
                Prim2D_SetRect(b, a, lbl_8036977C, step);
                c3 = Border_GetColor(s, next);
                c2 = Border_GetColor(s, next);
                c1 = Border_GetColor(s, idx);
                c0 = Border_GetColor(s, idx);
                Prim2D_SetCornerColors(&c0, &c1, &c2, &c3);
            } else {
                next=idx+1;
                Prim2D_SetRect(b, a + step, lbl_8036977C, nstep);
                d3 = Border_GetColor(s, idx);
                d2 = Border_GetColor(s, idx);
                d1 = Border_GetColor(s, next);
                d0 = Border_GetColor(s, next);
                Prim2D_SetCornerColors(&d0, &d1, &d2, &d3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    } else {
    {
        BorderColor d3,d2,d1,d0,c3,c2,c1,c0;
        idx=0;
        b=(f32)(*(s32 *)(s + 0x38));
        c=(f32)(*(s32 *)(s + 0x34)+(*(s32 *)(s + 0x3C)+*(s32 *)(s + 0x40)));
        a=(f32)(*(s32 *)(s + 0x34));
        n=Abs(16);
        step=(c-a)/(f32)n;
        nstep=-step;
        zero=gZeroF;
        for (i = 0; i < n; i++) {
            Prim2D_AddPrim(3);
            if (step >= zero) {
                next=idx+1;
                Prim2D_SetRect(a, b, step, lbl_8036977C);
                c3 = Border_GetColor(s, next);
                c2 = Border_GetColor(s, idx);
                c1 = Border_GetColor(s, next);
                c0 = Border_GetColor(s, idx);
                Prim2D_SetCornerColors(&c0, &c1, &c2, &c3);
            } else {
                next=idx+1;
                Prim2D_SetRect(a + step, b, nstep, lbl_8036977C);
                d3 = Border_GetColor(s, idx);
                d2 = Border_GetColor(s, next);
                d1 = Border_GetColor(s, idx);
                d0 = Border_GetColor(s, next);
                Prim2D_SetCornerColors(&d0, &d1, &d2, &d3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
        BorderColor d3,d2,d1,d0,c3,c2,c1,c0;
        idx=16;
        b=(f32)(*(s32 *)(s + 0x34)+(*(s32 *)(s + 0x3C)+*(s32 *)(s + 0x40)));
        c=(f32)(*(s32 *)(s + 0x38)+(*(s32 *)(s + 0x44)+*(s32 *)(s + 0x48)));
        a=(f32)(*(s32 *)(s + 0x38));
        n=Abs(16);
        step=(c-a)/(f32)n;
        nstep=-step;
        zero=gZeroF;
        for (i = 0; i < n; i++) {
            Prim2D_AddPrim(3);
            if (step >= zero) {
                next=idx+1;
                Prim2D_SetRect(b, a, lbl_8036977C, step);
                c3 = Border_GetColor(s, next);
                c2 = Border_GetColor(s, next);
                c1 = Border_GetColor(s, idx);
                c0 = Border_GetColor(s, idx);
                Prim2D_SetCornerColors(&c0, &c1, &c2, &c3);
            } else {
                next=idx+1;
                Prim2D_SetRect(b, a + step, lbl_8036977C, nstep);
                d3 = Border_GetColor(s, idx);
                d2 = Border_GetColor(s, idx);
                d1 = Border_GetColor(s, next);
                d0 = Border_GetColor(s, next);
                Prim2D_SetCornerColors(&d0, &d1, &d2, &d3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
        BorderColor d3,d2,d1,d0,c3,c2,c1,c0;
        idx=0;
        b=(f32)(*(s32 *)(s + 0x38)+(*(s32 *)(s + 0x44)+*(s32 *)(s + 0x48)));
        c=(f32)(*(s32 *)(s + 0x34)+*(s32 *)(s + 0x3C));
        a=(f32)(*(s32 *)(s + 0x40)+(*(s32 *)(s + 0x34)+*(s32 *)(s + 0x3C)));
        n=Abs(5);
        step=(c-a)/(f32)n;
        nstep=-step;
        zero=gZeroF;
        for (i = 0; i < n; i++) {
            Prim2D_AddPrim(3);
            if (step >= zero) {
                next=idx+1;
                Prim2D_SetRect(a, b, step, lbl_8036977C);
                c3 = Border_GetColor(s, next);
                c2 = Border_GetColor(s, idx);
                c1 = Border_GetColor(s, next);
                c0 = Border_GetColor(s, idx);
                Prim2D_SetCornerColors(&c0, &c1, &c2, &c3);
            } else {
                next=idx+1;
                Prim2D_SetRect(a + step, b, nstep, lbl_8036977C);
                d3 = Border_GetColor(s, idx);
                d2 = Border_GetColor(s, next);
                d1 = Border_GetColor(s, idx);
                d0 = Border_GetColor(s, next);
                Prim2D_SetCornerColors(&d0, &d1, &d2, &d3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
        BorderColor d3,d2,d1,d0,c3,c2,c1,c0;
        idx=5;
        b=(f32)(*(s32 *)(s + 0x34)+*(s32 *)(s + 0x3C));
        c=(f32)(*(s32 *)(s + 0x38)+*(s32 *)(s + 0x44));
        a=(f32)(*(s32 *)(s + 0x48)+(*(s32 *)(s + 0x38)+*(s32 *)(s + 0x44)));
        n=Abs(11);
        step=(c-a)/(f32)n;
        nstep=-step;
        zero=gZeroF;
        for (i = 0; i < n; i++) {
            Prim2D_AddPrim(3);
            if (step >= zero) {
                next=idx+1;
                Prim2D_SetRect(b, a, lbl_8036977C, step);
                c3 = Border_GetColor(s, next);
                c2 = Border_GetColor(s, next);
                c1 = Border_GetColor(s, idx);
                c0 = Border_GetColor(s, idx);
                Prim2D_SetCornerColors(&c0, &c1, &c2, &c3);
            } else {
                next=idx+1;
                Prim2D_SetRect(b, a + step, lbl_8036977C, nstep);
                d3 = Border_GetColor(s, idx);
                d2 = Border_GetColor(s, idx);
                d1 = Border_GetColor(s, next);
                d0 = Border_GetColor(s, next);
                Prim2D_SetCornerColors(&d0, &d1, &d2, &d3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
        BorderColor d3,d2,d1,d0,c3,c2,c1,c0;
        idx=16;
        b=(f32)(*(s32 *)(s + 0x38)+*(s32 *)(s + 0x44));
        c=(f32)(*(s32 *)(s + 0x34));
        a=(f32)(*(s32 *)(s + 0x34)+*(s32 *)(s + 0x3C));
        n=Abs(11);
        step=(c-a)/(f32)n;
        nstep=-step;
        zero=gZeroF;
        for (i = 0; i < n; i++) {
            Prim2D_AddPrim(3);
            if (step >= zero) {
                next=idx+1;
                Prim2D_SetRect(a, b, step, lbl_8036977C);
                c3 = Border_GetColor(s, next);
                c2 = Border_GetColor(s, idx);
                c1 = Border_GetColor(s, next);
                c0 = Border_GetColor(s, idx);
                Prim2D_SetCornerColors(&c0, &c1, &c2, &c3);
            } else {
                next=idx+1;
                Prim2D_SetRect(a + step, b, nstep, lbl_8036977C);
                d3 = Border_GetColor(s, idx);
                d2 = Border_GetColor(s, next);
                d1 = Border_GetColor(s, idx);
                d0 = Border_GetColor(s, next);
                Prim2D_SetCornerColors(&d0, &d1, &d2, &d3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
        BorderColor d3,d2,d1,d0,c3,c2,c1,c0;
        idx=27;
        b=(f32)(*(s32 *)(s + 0x34));
        c=(f32)(*(s32 *)(s + 0x38));
        a=(f32)(*(s32 *)(s + 0x38)+*(s32 *)(s + 0x44));
        n=Abs(5);
        step=(c-a)/(f32)n;
        nstep=-step;
        zero=gZeroF;
        for (i = 0; i < n; i++) {
            Prim2D_AddPrim(3);
            if (step >= zero) {
                next=idx+1;
                Prim2D_SetRect(b, a, lbl_8036977C, step);
                c3 = Border_GetColor(s, next);
                c2 = Border_GetColor(s, next);
                c1 = Border_GetColor(s, idx);
                c0 = Border_GetColor(s, idx);
                Prim2D_SetCornerColors(&c0, &c1, &c2, &c3);
            } else {
                next=idx+1;
                Prim2D_SetRect(b, a + step, lbl_8036977C, nstep);
                d3 = Border_GetColor(s, idx);
                d2 = Border_GetColor(s, idx);
                d1 = Border_GetColor(s, next);
                d0 = Border_GetColor(s, next);
                Prim2D_SetCornerColors(&d0, &d1, &d2, &d3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    }
}
#pragma use_lmw_stmw reset
s32 fn_8008F400(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    void *var_r4;

    if (Process_Find(lbl_80289A60) != NULL) {
        var_r4 = Process_Find(lbl_80289A60);
    } else {
        var_r4 = Process_Create(lbl_80289A60, 3);
    }
    *(s32 *)((u8 *)var_r4 + 0x34) = arg0;
    *(s32 *)((u8 *)var_r4 + 0x38) = arg1;
    *(s32 *)((u8 *)var_r4 + 0x3C) = arg2;
    *(s32 *)((u8 *)var_r4 + 0x40) = arg3;
    return 0;
}

