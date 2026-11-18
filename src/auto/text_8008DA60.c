/* Functions from 0x8007C5E4 to 0x8009F0BC, found by decomp-toolkit. */
#include "common.h"
#include "global.h"

typedef struct BorderColor { u32 rgba; } BorderColor;
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

#pragma optimization_level 3
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
    BorderColor d3_1, d2_1, d1_1, d0_1, c3_1, c2_1, c1_1, c0_1;
    BorderColor d3_2, d2_2, d1_2, d0_2, c3_2, c2_2, c1_2, c0_2;
    BorderColor d3_3, d2_3, d1_3, d0_3, c3_3, c2_3, c1_3, c0_3;
    BorderColor d3_4, d2_4, d1_4, d0_4, c3_4, c2_4, c1_4, c0_4;
    BorderColor d3_5, d2_5, d1_5, d0_5, c3_5, c2_5, c1_5, c0_5;
    BorderColor d3_6, d2_6, d1_6, d0_6, c3_6, c2_6, c1_6, c0_6;
    BorderColor d3_7, d2_7, d1_7, d0_7, c3_7, c2_7, c1_7, c0_7;
    BorderColor d3_8, d2_8, d1_8, d0_8, c3_8, c2_8, c1_8, c0_8;
    BorderColor d3_9, d2_9, d1_9, d0_9, c3_9, c2_9, c1_9, c0_9;
    BorderColor d3_10, d2_10, d1_10, d0_10, c3_10, c2_10, c1_10, c0_10;
    BorderColor d3_11, d2_11, d1_11, d0_11, c3_11, c2_11, c1_11, c0_11;
    BorderColor d3_12, d2_12, d1_12, d0_12, c3_12, c2_12, c1_12, c0_12;
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
        s32 firstIndex, firstCount;
        f32 firstEnd, firstY, firstX, firstStep, firstNegative;
        firstIndex=0;
        firstY=(f32)(*(s32 *)(s + 0x38));
        firstEnd=(f32)(*(s32 *)(s + 0x34)+*(s32 *)(s + 0x3C));
        firstX=(f32)(*(s32 *)(s + 0x34));
        n=Abs(5);
        firstStep=(firstEnd-firstX)/(f32)n;
        firstNegative=-firstStep;
        zero=gZeroF;
        for (firstCount = 0; firstCount < n; firstCount++) {
            Prim2D_AddPrim(3);
            if (firstStep >= zero) {
                Prim2D_SetRect(firstX, firstY, firstStep, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=firstIndex+1) - Game_GetFrameCount()) & 31]; c3_1 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((firstIndex) - Game_GetFrameCount()) & 31]; c2_1 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; c1_1 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((firstIndex) - Game_GetFrameCount()) & 31]; c0_1 = color; }
                Prim2D_SetCornerColors(&c0_1, &c1_1, &c2_1, &c3_1);
            } else {
                Prim2D_SetRect(firstX + firstStep, firstY, firstNegative, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((firstIndex) - Game_GetFrameCount()) & 31]; d3_1 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=firstIndex+1) - Game_GetFrameCount()) & 31]; d2_1 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((firstIndex) - Game_GetFrameCount()) & 31]; d1_1 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; d0_1 = color; }
                Prim2D_SetCornerColors(&d0_1, &d1_1, &d2_1, &d3_1);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            firstX += firstStep;
            firstIndex++;
        }
    }
    {
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
                Prim2D_SetRect(b, a, lbl_8036977C, step);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; c3_2 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; c2_2 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c1_2 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c0_2 = color; }
                Prim2D_SetCornerColors(&c0_2, &c1_2, &c2_2, &c3_2);
            } else {
                Prim2D_SetRect(b, a + step, lbl_8036977C, nstep);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d3_2 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d2_2 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; d1_2 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; d0_2 = color; }
                Prim2D_SetCornerColors(&d0_2, &d1_2, &d2_2, &d3_2);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
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
                Prim2D_SetRect(a, b, step, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; c3_3 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c2_3 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; c1_3 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c0_3 = color; }
                Prim2D_SetCornerColors(&c0_3, &c1_3, &c2_3, &c3_3);
            } else {
                Prim2D_SetRect(a + step, b, nstep, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d3_3 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; d2_3 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d1_3 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; d0_3 = color; }
                Prim2D_SetCornerColors(&d0_3, &d1_3, &d2_3, &d3_3);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
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
                Prim2D_SetRect(b, a, lbl_8036977C, step);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; c3_4 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; c2_4 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c1_4 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c0_4 = color; }
                Prim2D_SetCornerColors(&c0_4, &c1_4, &c2_4, &c3_4);
            } else {
                Prim2D_SetRect(b, a + step, lbl_8036977C, nstep);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d3_4 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d2_4 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; d1_4 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; d0_4 = color; }
                Prim2D_SetCornerColors(&d0_4, &d1_4, &d2_4, &d3_4);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
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
                Prim2D_SetRect(a, b, step, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; c3_5 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c2_5 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; c1_5 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c0_5 = color; }
                Prim2D_SetCornerColors(&c0_5, &c1_5, &c2_5, &c3_5);
            } else {
                Prim2D_SetRect(a + step, b, nstep, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d3_5 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; d2_5 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d1_5 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; d0_5 = color; }
                Prim2D_SetCornerColors(&d0_5, &d1_5, &d2_5, &d3_5);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
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
                Prim2D_SetRect(b, a, lbl_8036977C, step);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; c3_6 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; c2_6 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c1_6 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c0_6 = color; }
                Prim2D_SetCornerColors(&c0_6, &c1_6, &c2_6, &c3_6);
            } else {
                Prim2D_SetRect(b, a + step, lbl_8036977C, nstep);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d3_6 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d2_6 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; d1_6 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; d0_6 = color; }
                Prim2D_SetCornerColors(&d0_6, &d1_6, &d2_6, &d3_6);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    } else {
    {
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
                Prim2D_SetRect(a, b, step, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; c3_7 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c2_7 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; c1_7 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c0_7 = color; }
                Prim2D_SetCornerColors(&c0_7, &c1_7, &c2_7, &c3_7);
            } else {
                Prim2D_SetRect(a + step, b, nstep, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d3_7 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; d2_7 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d1_7 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; d0_7 = color; }
                Prim2D_SetCornerColors(&d0_7, &d1_7, &d2_7, &d3_7);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
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
                Prim2D_SetRect(b, a, lbl_8036977C, step);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; c3_8 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; c2_8 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c1_8 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c0_8 = color; }
                Prim2D_SetCornerColors(&c0_8, &c1_8, &c2_8, &c3_8);
            } else {
                Prim2D_SetRect(b, a + step, lbl_8036977C, nstep);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d3_8 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d2_8 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; d1_8 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; d0_8 = color; }
                Prim2D_SetCornerColors(&d0_8, &d1_8, &d2_8, &d3_8);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
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
                Prim2D_SetRect(a, b, step, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; c3_9 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c2_9 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; c1_9 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c0_9 = color; }
                Prim2D_SetCornerColors(&c0_9, &c1_9, &c2_9, &c3_9);
            } else {
                Prim2D_SetRect(a + step, b, nstep, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d3_9 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; d2_9 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d1_9 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; d0_9 = color; }
                Prim2D_SetCornerColors(&d0_9, &d1_9, &d2_9, &d3_9);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
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
                Prim2D_SetRect(b, a, lbl_8036977C, step);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; c3_10 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; c2_10 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c1_10 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c0_10 = color; }
                Prim2D_SetCornerColors(&c0_10, &c1_10, &c2_10, &c3_10);
            } else {
                Prim2D_SetRect(b, a + step, lbl_8036977C, nstep);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d3_10 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d2_10 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; d1_10 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; d0_10 = color; }
                Prim2D_SetCornerColors(&d0_10, &d1_10, &d2_10, &d3_10);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
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
                Prim2D_SetRect(a, b, step, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; c3_11 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c2_11 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; c1_11 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c0_11 = color; }
                Prim2D_SetCornerColors(&c0_11, &c1_11, &c2_11, &c3_11);
            } else {
                Prim2D_SetRect(a + step, b, nstep, lbl_8036977C);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d3_11 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; d2_11 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d1_11 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; d0_11 = color; }
                Prim2D_SetCornerColors(&d0_11, &d1_11, &d2_11, &d3_11);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    {
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
                Prim2D_SetRect(b, a, lbl_8036977C, step);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; c3_12 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; c2_12 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c1_12 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; c0_12 = color; }
                Prim2D_SetCornerColors(&c0_12, &c1_12, &c2_12, &c3_12);
            } else {
                Prim2D_SetRect(b, a + step, lbl_8036977C, nstep);
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d3_12 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((idx) - Game_GetFrameCount()) & 31]; d2_12 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next=idx+1) - Game_GetFrameCount()) & 31]; d1_12 = color; }
                { BorderColor color = (*(BorderColor **)(s + 0x30))[((next) - Game_GetFrameCount()) & 31]; d0_12 = color; }
                Prim2D_SetCornerColors(&d0_12, &d1_12, &d2_12, &d3_12);
            }
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            a += step;
            idx++;
        }
    }
    }
}
#pragma optimization_level reset
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

