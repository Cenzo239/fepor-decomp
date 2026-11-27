/* Functions from 0x8007C5E4 to 0x8009F0BC, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
typedef struct {
    f32 x, y;
    u8 unk8[4];
    s8 next;
    u8 type;
    u8 unkE[6];
} Menu888Entry;
extern void* lbl_803674E8;
extern f64 lbl_80369688;
extern const f32 lbl_803696C8;
typedef struct { u16 a, b, c; } Fn89980Struct;
typedef struct { f32 a, b; } FloatPair892E8;

extern s32 gSaveDataBase;
extern u8 lbl_8026CC58[];
extern u8 lbl_80289998[];
extern const f32 gScreenOrigin;
extern f32 lbl_803696A8;
extern f32 lbl_803696AC;
extern f64 lbl_803696C0;

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

/* Draw the unit info panel: child widgets, gradient bar, and status text. */

#pragma use_lmw_stmw on

#pragma optimization_level 3
#pragma opt_strength_reduction off

#pragma optimization_level reset

#pragma scheduling on

#pragma scheduling reset

void fn_8000BFEC(void (*arg0)(void *));
void fn_80089490(void *);

#pragma optimization_level 2

#pragma optimization_level reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma global_optimizer reset
#pragma peephole off

#pragma peephole on

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
void fn_80089A28(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
    void GXSetVtxDesc(s32, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void GXBegin(s32, s32, s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetZMode(s32, s32, s32);
    void GXSetProjection(void *, s32);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    extern s32 gUiInputFlags;
    extern f32 gScreenHeight;
    extern f32 gScreenWidth;
    extern f32 gOrthoFar;
    extern f32 gFadeQuadZ;
    extern f32 gViewportFar;
    extern const f32 lbl_803696B4;
    extern f32 lbl_803696CC;
    extern f32 lbl_803696D0;
    extern const f32 lbl_803696D4;

    u8 sp8[0x40];
    s32 xv[4];
    f32 f31;
    f32 f30;
    f32 start;
    s32 mode;
    s32 zero;
    s32 height;
    s32 a0;
    s32 a1;
    u16 state;

    if (gUiInputFlags & 1) {
        state = *(u16 *)((u8 *)arg0 + 0x32);
        switch (state) {
        case 0:
        case 2:
            return;
        case 1:
            *(u16 *)((u8 *)arg0 + 0x32) = 2;
            return;
        case 3:
            *(u16 *)((u8 *)arg0 + 0x32) = 0;
            return;
        }
    }

    state = *(u16 *)((u8 *)arg0 + 0x32);
    switch (state) {
    case 0:
        return;
    case 1:
        *(u16 *)((u8 *)arg0 + 0x34) = *(u16 *)((u8 *)arg0 + 0x34) + 1;
        start = lbl_803696B4;
        f31 = Math_Ease(0, start, lbl_803696CC,
                          (f32)*(u16 *)((u8 *)arg0 + 0x34),
                          (f32)*(u16 *)((u8 *)arg0 + 0x36));
        mode = 0;
        if (*(u16 *)((u8 *)arg0 + 0x34) >= *(u16 *)((u8 *)arg0 + 0x36)) {
            *(u16 *)((u8 *)arg0 + 0x32) = 2;
        }
        break;
    case 2:
        f31 = lbl_803696CC;
        mode = 0;
        break;
    case 3:
        *(u16 *)((u8 *)arg0 + 0x34) = *(u16 *)((u8 *)arg0 + 0x34) + 1;
        start = gScreenOrigin;
        f31 = Math_Ease(0, start, lbl_803696D0,
                          (f32)*(u16 *)((u8 *)arg0 + 0x34),
                          (f32)*(u16 *)((u8 *)arg0 + 0x36));
        mode = 1;
        if (*(u16 *)((u8 *)arg0 + 0x34) >= *(u16 *)((u8 *)arg0 + 0x36)) {
            *(u16 *)((u8 *)arg0 + 0x32) = 0;
        }
        break;
    }

    C_MTXOrtho(sp8, gScreenOrigin, gScreenHeight, gScreenOrigin, gScreenWidth, gScreenOrigin, gOrthoFar);
    GXSetProjection(sp8, 1);
    PSMTXTrans(sp8, gScreenOrigin, gScreenOrigin, gFadeQuadZ);
    GXLoadPosMtxImm(sp8, 0);
    GXSetCurrentMtx(0);
    GXSetViewport(gScreenOrigin, gScreenOrigin, gScreenWidth, gScreenHeight, gScreenOrigin, gViewportFar);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxAttrFmt(0, 9, 1, 3, 0);
    GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
    GXSetNumChans(0);
    GXSetNumTexGens(0, 4);
    GXSetTevOrder(0, 0xFF, 0xFF, 4);
    GXSetNumTevStages(1);
    GXSetCullMode(1);
    GXSetBlendMode(4, 0, 1, 1, 0, 0, 2);
    fn_802245D8(1, 4, 5, 0);
    GXSetZMode(1, 3, 0);

    if (mode == 0) {
        a0 = 0;
        a1 = 0xFF;
        f30 = lbl_803696D4 + f31;
    } else if (mode == 1) {
        f30 = f31;
        a0 = 0xFF;
        a1 = 0;
        f31 = lbl_803696B4 + f31;
    } else {
        return;
    }

    zero = 0;
    height = 0x1C0;

    GXBegin(0x98, 0, 4);
    *(volatile s16 *)0xCC008000 = (s16)f31;
    *(volatile s16 *)0xCC008000 = (s16)zero;
    *(volatile s16 *)0xCC008000 = (s16)zero;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = (u8)a0;
    *(volatile s16 *)0xCC008000 = (s16)(lbl_803696D4 + f31);
    *(volatile s16 *)0xCC008000 = (s16)zero;
    *(volatile s16 *)0xCC008000 = (s16)zero;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = (u8)a1;
    *(volatile s16 *)0xCC008000 = (s16)f31;
    *(volatile s16 *)0xCC008000 = (s16)height;
    *(volatile s16 *)0xCC008000 = (s16)zero;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = (u8)a0;
    *(volatile s16 *)0xCC008000 = (s16)(lbl_803696D4 + f31);
    *(volatile s16 *)0xCC008000 = (s16)height;
    *(volatile s16 *)0xCC008000 = (s16)zero;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = (u8)a1;

    GXBegin(0x98, 0, 4);
    *(volatile s16 *)0xCC008000 = (s16)f30;
    *(volatile s16 *)0xCC008000 = (s16)zero;
    *(volatile s16 *)0xCC008000 = (s16)zero;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0xFF;
    *(volatile s16 *)0xCC008000 = (s16)(lbl_803696B4 + f30);
    *(volatile s16 *)0xCC008000 = (s16)zero;
    *(volatile s16 *)0xCC008000 = (s16)zero;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0xFF;
    *(volatile s16 *)0xCC008000 = (s16)f30;
    *(volatile s16 *)0xCC008000 = (s16)height;
    *(volatile s16 *)0xCC008000 = (s16)zero;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0xFF;
    *(volatile s16 *)0xCC008000 = (s16)(lbl_803696B4 + f30);
    *(volatile s16 *)0xCC008000 = (s16)height;
    *(volatile s16 *)0xCC008000 = (s16)zero;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0;
    *(volatile u8 *)0xCC008000 = 0xFF;
}
#pragma pop
s32 fn_80089ED8(void) {
    extern void *lbl_803674E8;
    u16 temp_r0;

    temp_r0 = M2C_FIELD(lbl_803674E8, u16 *, 0x32);
    if ((temp_r0 == 1) || (temp_r0 == 2)) {
        return 1;
    }
    return 0;
}

void fn_80089F00(u8 arg0,u8 arg1,u8 arg2,s32 arg3,s32 arg4) {
extern const f32 lbl_803696C8; extern void *lbl_803674E8; extern u32 lbl_8036C470;
u8 *ptr; f32 div; union { u32 w; u8 b[4]; } color;
div=lbl_803696C8; ptr=(u8*)lbl_803674E8;
*(u16*)(ptr+0x32)=1;
color.w=lbl_8036C470;
color.b[0]=arg0; color.b[1]=arg1; color.b[2]=arg2;
ptr[0x34]=color.b[0]; ptr[0x35]=color.b[1]; ptr[0x36]=color.b[2]; ptr[0x37]=color.b[3];
*(u16*)(ptr+0x38)=0; *(u16*)(ptr+0x3C)=0;
*(u16*)(ptr+0x3A)=(s32)((f32)arg3/div);
*(u16*)(ptr+0x3E)=(s32)((f32)arg4/div);
}

/* Ease fullscreen fade alpha and draw a colored ortho quad when alpha is non-zero. */
void Ui_DrawColorFade(void *fade) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
    void GXSetVtxDesc(s32, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void GXBegin(s32, s32, s32);
    void GXSetChanMatColor(s32, s32 *);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetZMode(s32, s32, s32);
    void GXSetProjection(void *, s32);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    extern s32 gUiInputFlags;
    extern f32 gScreenHeight;
    extern f32 gScreenWidth;
    extern f32 gOrthoFar;
    extern f32 gFadeQuadZ;
    extern f32 gViewportFar;
    u8 mtx[0x44];
    s32 matColor;
    f32 easeFrom;
    f32 easeTo;
    u16 state;

    if (gUiInputFlags & 1) {
        *(u8 *)((u8 *)fade + 0x37) = 0;
        *(u16 *)((u8 *)fade + 0x32) = 0;
        return;
    }
    state = *(u16 *)((u8 *)fade + 0x32);
    switch (state) {
    case 0:
        *(u8 *)((u8 *)fade + 0x37) = 0;
        break;
    case 1:
        *(u16 *)((u8 *)fade + 0x38) = *(u16 *)((u8 *)fade + 0x38) + 1;
        easeFrom = 0.0f;
        easeTo = 255.0f;
        *(u8 *)((u8 *)fade + 0x37) =
            (u8)(s32)Math_Ease(0, easeFrom, easeTo,
                                 (f32)*(u16 *)((u8 *)fade + 0x38),
                                 (f32)*(u16 *)((u8 *)fade + 0x3A));
        if (*(u16 *)((u8 *)fade + 0x38) >= *(u16 *)((u8 *)fade + 0x3A)) {
            *(u16 *)((u8 *)fade + 0x32) = 2;
        }
        break;
    case 2:
        *(u16 *)((u8 *)fade + 0x3C) = *(u16 *)((u8 *)fade + 0x3C) + 1;
        easeFrom = 255.0f;
        easeTo = 0.0f;
        *(u8 *)((u8 *)fade + 0x37) =
            (u8)(s32)Math_Ease(0, easeFrom, easeTo,
                                 (f32)*(u16 *)((u8 *)fade + 0x3C),
                                 (f32)*(u16 *)((u8 *)fade + 0x3E));
        if (*(u16 *)((u8 *)fade + 0x3C) >= *(u16 *)((u8 *)fade + 0x3E)) {
            *(u16 *)((u8 *)fade + 0x32) = 0;
        }
        break;
    }
    if (*(u8 *)((u8 *)fade + 0x37) != 0) {
        C_MTXOrtho(mtx, gScreenOrigin, gScreenHeight, gScreenOrigin, gScreenWidth, gScreenOrigin, gOrthoFar);
        GXSetProjection(mtx, 1);
        PSMTXTrans(mtx, gScreenOrigin, gScreenOrigin, gFadeQuadZ);
        GXLoadPosMtxImm(mtx, 0);
        GXSetCurrentMtx(0);
        GXSetViewport(gScreenOrigin, gScreenOrigin, gScreenWidth, gScreenHeight, gScreenOrigin, gViewportFar);
        GXClearVtxDesc();
        GXSetVtxDesc(9, 1);
        GXSetVtxAttrFmt(0, 9, 1, 3, 0);
        GXSetNumChans(0);
        GXSetNumTexGens(0, 4);
        GXSetTevOrder(0, 0xFF, 0xFF, 4);
        GXSetNumTevStages(1);
        GXSetCullMode(1);
        GXSetBlendMode(4, 0, 0, 0, 0, 0, 2);
        matColor = *(s32 *)((u8 *)fade + 0x34);
        GXSetChanMatColor(4, &matColor);
        fn_802245D8(1, 4, 5, 0);
        GXSetZMode(1, 3, 0);
        GXBegin(0x98, 0, 4);
        *(volatile s16 *)0xCC008000 = 0;
        *(volatile s16 *)0xCC008000 = 0;
        *(volatile s16 *)0xCC008000 = 0;
        *(volatile s16 *)0xCC008000 = 0x260;
        *(volatile s16 *)0xCC008000 = 0;
        *(volatile s16 *)0xCC008000 = 0;
        *(volatile s16 *)0xCC008000 = 0;
        *(volatile s16 *)0xCC008000 = 0x1C0;
        *(volatile s16 *)0xCC008000 = 0;
        *(volatile s16 *)0xCC008000 = 0x260;
        *(volatile s16 *)0xCC008000 = 0x1C0;
        *(volatile s16 *)0xCC008000 = 0;
    }
}

void fn_8008A290(s32 arg0, s32 arg1) {
    extern s32 gUiInputFlags;
    void fn_8008A32C(void *, s32, s32);
    extern u16 *lbl_803674E0;
    int var_r6;
    s32 var_r5;

    var_r6 = arg0;
    var_r5 = arg1;
    if (gUiInputFlags & 1) {
        switch ((u8)var_r6) {
        case 2:
            var_r6 = 0;
            break;
        case 3:
            var_r6 = 1;
            break;
        case 5:
            var_r6 = 0;
            break;
        case 6:
            var_r6 = 4;
            break;
        case 7:
            var_r6 = 0;
            break;
        }
        var_r5 = 0;
    }
    fn_8008A32C(lbl_803674E0, var_r6, var_r5);
}

void fn_8008A32C(void *arg0, s32 arg1, s32 arg2)
{
    s32 GXGetTexBufferSize(s32, s32, s32, s32, s32);
    void *fn_800C45B8(s32, void *, s32);
    void DCInvalidateRange(void *, s32);
    void fn_80222644(void *, void *, s32, s32, s32, s32, s32, s32);
    void GXInitTexObjLOD(void *, s32, s32, s32, s32, s32, f32, f32, f32);
    void *Process_Create(void *, s32);

    extern const f32 lbl_803696B0;
    extern const f32 lbl_803696C8;
    extern const f32 gScreenOrigin;

    u8 *obj;
    void *proc;
    s32 size;

    obj = (u8 *)arg0;

    if ((*(u16 *)(obj + 0x32) & 1) == 0) {
        obj[0x30] = arg1;

        *(u16 *)(obj + 0x32) = 1;
        *(u16 *)(obj + 0x34) = 0;

        *(s16 *)(obj + 0x36) =
            (s32)((f32)arg2 / lbl_803696C8);

        *(u32 *)(obj + 0x48) = 0;

        switch (obj[0x30]) {
        case 0:
            *(u16 *)(obj + 0x32) = 2;
            *(f32 *)(obj + 0x3C) = gScreenOrigin;
            *(u32 *)(obj + 0x40) = 0;
            break;

        case 1:
            *(u16 *)(obj + 0x32) = 6;
            *(f32 *)(obj + 0x3C) = lbl_803696B0;
            *(u32 *)(obj + 0x40) = 0xFF;
            break;

        case 2:
            *(f32 *)(obj + 0x38) = lbl_803696B0;
            *(f32 *)(obj + 0x3C) = gScreenOrigin;
            *(u32 *)(obj + 0x40) = 0xFF;
            break;

        case 3:
            *(u16 *)(obj + 0x32) |= 4;
            *(f32 *)(obj + 0x38) = gScreenOrigin;
            *(f32 *)(obj + 0x3C) = lbl_803696B0;
            *(u32 *)(obj + 0x40) = 0xFF;
            break;

        case 4:
            *(u16 *)(obj + 0x32) = 0xA;
            *(f32 *)(obj + 0x3C) = lbl_803696B0;
            *(u32 *)(obj + 0x40) = -1;
            break;

        case 5:
            *(f32 *)(obj + 0x38) = lbl_803696B0;
            *(f32 *)(obj + 0x3C) = gScreenOrigin;
            *(u32 *)(obj + 0x40) = -1;
            break;

        case 6:
            *(u16 *)(obj + 0x32) |= 8;
            *(f32 *)(obj + 0x38) = gScreenOrigin;
            *(f32 *)(obj + 0x3C) = lbl_803696B0;
            *(u32 *)(obj + 0x40) = -1;
            break;

        case 7:
            *(f32 *)(obj + 0x38) = lbl_803696B0;
            *(f32 *)(obj + 0x3C) = gScreenOrigin;
            *(u32 *)(obj + 0x40) = -1;

            size = GXGetTexBufferSize(
                0x260,
                0x1C0,
                4,
                0,
                0
            );

            *(void **)(obj + 0x48) =
                fn_800C45B8(
                    -size,
                    lbl_8026CC58 + 0x2A,
                    0
                );

            DCInvalidateRange(
                *(void **)(obj + 0x48),
                size
            );

            fn_80222644(
                obj + 0x4C,
                *(void **)(obj + 0x48),
                0x260,
                0x1C0,
                4,
                0,
                0,
                0
            );

            GXInitTexObjLOD(
                obj + 0x4C,
                0,
                0,
                0,
                0,
                0,
                gScreenOrigin,
                gScreenOrigin,
                gScreenOrigin
            );

            proc = Process_Create(
                lbl_80289998,
                6
            );

            *(void **)((u8 *)proc + 0x54) = obj;
            break;
        }
    }
}

u16 fn_8008A56C(void) {
    return lbl_803674E0[0x19];
}

s32 fn_8008A578(void) {
    s32 result;
    u16 temp_r4;

    result = 0;
    temp_r4 = lbl_803674E0[0x19];
    if (temp_r4 & 2) {
        if (temp_r4 & 4) {
            result = 1;
        }
    }
    return result;
}

u32 fn_8008A59C(void) {
    extern u16 *lbl_803674E0;

    return lbl_803674E0[0x19] & 1;
}

#pragma push
#pragma optimization_level 4
void fn_8008A5AC(void *arg0) {
    void fn_800C4588(void *);
    void PSMTXTrans(void *, f32, f32, f32);
    void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
    void GXSetVtxDesc(s32, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void GXBegin(s32, s32, s32);
    void GXSetChanMatColor(s32, s32 *);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void fn_80222C50(void *, s32);
    void GXSetNumTexGens(s32, s32);
    void GXSetTevColorIn(s32, s32, s32, s32, s32);
    void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
    void GXSetTevColorOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevAlphaOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetZMode(s32, s32, s32);
    void GXSetProjection(void *, s32);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    extern s32 gUiInputFlags;
    extern f32 gScreenHeight;
    extern f32 gScreenWidth;
    extern f32 gOrthoFar;
    extern f32 gFadeQuadZ;
    extern f32 gViewportFar;
    extern const f32 lbl_803696BC;
    u8 spC[0x44];
    s32 sp8;
    f32 temp_f5;
    f32 bc;
    u16 t;
    u32 u34;
    u32 u36;
    void *p;

    if (*(u16 *)((u8 *)arg0 + 0x34) >= *(u16 *)((u8 *)arg0 + 0x36) || (gUiInputFlags & 1)) {
        bc = lbl_803696BC;
        t = *(u16 *)((u8 *)arg0 + 0x32);
        t &= 0xFFFE;
        *(u16 *)((u8 *)arg0 + 0x32) = t;
        t = *(u16 *)((u8 *)arg0 + 0x32);
        t |= 2;
        *(u16 *)((u8 *)arg0 + 0x32) = t;
        *(u8 *)((u8 *)arg0 + 0x43) = (u8)(s32)(bc * *(f32 *)((u8 *)arg0 + 0x3C));
        p = *(void **)((u8 *)arg0 + 0x48);
        if (p != NULL) {
            fn_800C4588(p);
            *(void **)((u8 *)arg0 + 0x48) = NULL;
        }
    }
    if (*(u16 *)((u8 *)arg0 + 0x32) & 1) {
        *(u16 *)((u8 *)arg0 + 0x34) = *(u16 *)((u8 *)arg0 + 0x34) + 1;
        u34 = *(u16 *)((u8 *)arg0 + 0x34);
        u36 = *(u16 *)((u8 *)arg0 + 0x36);
        temp_f5 = *(f32 *)((u8 *)arg0 + 0x38);
        *(u8 *)((u8 *)arg0 + 0x43) = (u8)(s32)(lbl_803696BC * ((((f32)u34 / (f32)u36) * (*(f32 *)((u8 *)arg0 + 0x3C) - temp_f5)) + temp_f5));
    }
    if (*(u8 *)((u8 *)arg0 + 0x43) != 0) {
        C_MTXOrtho(spC, gScreenOrigin, gScreenHeight, gScreenOrigin, gScreenWidth, gScreenOrigin, gOrthoFar);
        GXSetProjection(spC, 1);
        PSMTXTrans(spC, gScreenOrigin, gScreenOrigin, gFadeQuadZ);
        GXLoadPosMtxImm(spC, 0);
        GXSetCurrentMtx(0);
        GXSetViewport(gScreenOrigin, gScreenOrigin, gScreenWidth, gScreenHeight, gScreenOrigin, gViewportFar);
        GXClearVtxDesc();
        GXSetVtxDesc(9, 1);
        GXSetVtxAttrFmt(0, 9, 1, 3, 0);
        if (*(u8 *)((u8 *)arg0 + 0x30) == 7) {
            GXSetVtxDesc(0xD, 1);
            GXSetVtxAttrFmt(0, 0xD, 1, 3, 0);
            GXSetTevColorIn(0, 0xF, 0xA, 8, 0xF);
            GXSetTevColorOp(0, 0, 0, 0, 1, 0);
            GXSetTevAlphaIn(0, 7, 7, 7, 5);
            GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
            GXSetTevOrder(0, 0, 0, 4);
            fn_80222C50((u8 *)arg0 + 0x4C, 0);
            GXSetNumChans(1);
            fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
        } else {
            GXSetNumTexGens(0, 4);
            GXSetTevOrder(0, 0xFF, 0xFF, 4);
            GXSetNumChans(0);
        }
        GXSetNumTevStages(1);
        GXSetCullMode(1);
        GXSetBlendMode(4, 0, 0, 0, 0, 0, 2);
        sp8 = *(s32 *)((u8 *)arg0 + 0x40);
        GXSetChanMatColor(4, &sp8);
        fn_802245D8(1, 4, 5, 0);
        GXSetZMode(1, 3, 0);
        if (*(u8 *)((u8 *)arg0 + 0x30) != 7) {
            GXBegin(0x98, 0, 4);
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0x260;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0x1C0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0x260;
            *(volatile s16 *)0xCC008000 = 0x1C0;
            *(volatile s16 *)0xCC008000 = 0;
        } else {
            GXBegin(0x98, 0, 4);
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0x260;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 1;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0x1C0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 1;
            *(volatile s16 *)0xCC008000 = 0x260;
            *(volatile s16 *)0xCC008000 = 0x1C0;
            *(volatile s16 *)0xCC008000 = 0;
            *(volatile s16 *)0xCC008000 = 1;
            *(volatile s16 *)0xCC008000 = 1;
        }
    }
}
#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
void fn_8008A998(s32 x, s32 y, s32 width) {
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetUvCorners(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiRouteAtlas;
    extern f32 lbl_803696D8;
    extern f32 lbl_803696DC;
    extern f32 lbl_803696E0;
    extern f64 lbl_803696E8;
    extern f64 lbl_803696F0;
    struct {
        u8 buf[0x20];
        u16 w;
        u16 h;
    } sp;
    s32 mid;
    s32 right;

    Ui_LoadAtlasTex(gUiRouteAtlas, sp.buf, 0x15);
    sp.w = GXGetTexObjWidth(sp.buf);
    sp.h = GXGetTexObjHeight(sp.buf);
    mid = width - sp.w;
    Prim2D_Begin();
    Prim2D_SetTex(sp.buf, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)x, (f32)y, lbl_803696D8, lbl_803696DC);
    Prim2D_SetUvCorners(lbl_803696E0, lbl_803696E0, lbl_803696D8, lbl_803696DC);
    Prim2D_EndPrim();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)(x + 0x41), (f32)y, (f32)mid, lbl_803696DC);
    Prim2D_SetUvCorners(lbl_803696D8, lbl_803696E0, lbl_803696D8, lbl_803696DC);
    Prim2D_EndPrim();
    Prim2D_AddPrim(1);
    right = mid + 0x41;
    Prim2D_SetRect((f32)(x + right), (f32)y, (f32)(sp.w - 0x41), lbl_803696DC);
    Prim2D_SetUvCorners(lbl_803696D8, lbl_803696E0, (f32)sp.w, lbl_803696DC);
    Prim2D_EndPrim();
}
#pragma pop
#pragma global_optimizer off
void fn_8008AB7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s64 OSGetTime(void);
    f64 sin(f32);
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_EmitQuad(void);
    s32 *Ui_GetColor(u8);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SetAlpha(s32);
    void Prim2D_EndPrim(void);
    extern s32 gUiAtlas;
    extern f32 lbl_803696E0;
    extern f32 lbl_803696F8;
    extern f32 lbl_803696FC;
    extern f32 lbl_80369700;
    extern f32 lbl_80369704;

    s32 col0, col1, col2;
    struct { u8 buf[0x20]; u16 w; u16 h; } sp;
    s32 handle, half, bottom, width, tw, th, alpha, cidx, y, x;
    f32 phase, s;

    width = arg2; x = arg0; y = arg1; cidx = arg3;
    handle = gUiAtlas;
    if (width <= 0x50) width = 0x50;
    phase = (f32)((OSGetTime() / ((*(u32 *)0x800000F8 >> 2) / 1000)) % 1500) / lbl_803696F8;
    if ((u8)arg6 == 0) alpha = arg4;
    else {
        s = (f32)sin(lbl_803696FC * phase);
        alpha = (s32)(lbl_80369700 * (((f32)(u8)arg5 - (f32)(u8)arg4) * (lbl_80369704 + s)) + (f32)(u8)arg4);
    }
    Ui_LoadAtlasTex(handle, sp.buf, 0x43);
    sp.w = GXGetTexObjWidth(sp.buf); sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin(); Prim2D_SetTex(sp.buf, 0x11); Prim2D_PrepareTex();
    tw = sp.w; th = sp.h; Prim2D_AddPrim(1);
    half = width / 2; width = x - half;
    Prim2D_SetQuadMin((f32)width, (f32)(y - 0xA), lbl_803696E0, lbl_803696E0);
    width = tw + width; bottom = y + th; bottom -= 0xA;
    Prim2D_SetQuadMax((f32)width, (f32)bottom, (f32)tw, (f32)th);
    Prim2D_EmitQuad(); col0 = *Ui_GetColor((u8)cidx); Prim2D_SetColorPacked(&col0); Prim2D_SetAlpha(alpha); Prim2D_EndPrim();
    Prim2D_AddPrim(1); x += half; half = x - tw;
    Prim2D_SetQuadMin((f32)half, (f32)(y - 0xA), (f32)tw, lbl_803696E0);
    Prim2D_SetQuadMax((f32)x, (f32)bottom, lbl_803696E0, (f32)th);
    Prim2D_EmitQuad(); col1 = *Ui_GetColor((u8)cidx); Prim2D_SetColorPacked(&col1); Prim2D_SetAlpha(alpha); Prim2D_EndPrim();
    Ui_LoadAtlasTex(handle, sp.buf, 0x44);
    sp.w = GXGetTexObjWidth(sp.buf); sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin(); Prim2D_SetTex(sp.buf, 0x11); Prim2D_PrepareTex(); Prim2D_AddPrim(1);
    Prim2D_SetQuadMin((f32)width, (f32)(y - 0xA), lbl_803696E0, lbl_803696E0);
    Prim2D_SetQuadMax((f32)half, (f32)bottom, (f32)(u32)sp.w, (f32)(u32)sp.h);
    Prim2D_EmitQuad(); col2 = *Ui_GetColor((u8)cidx); Prim2D_SetColorPacked(&col2); Prim2D_SetAlpha(alpha); Prim2D_EndPrim();
}
u16 Ui_DrawMsgPanelAlt(s32 x, s32 y) {
    /* Draw UI atlas tile 0x38 as a 2D rect at (x, y); return its width. */
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiAtlas;
    extern f32 lbl_80369704;
    extern f64 lbl_803696E8;
    extern f64 lbl_803696F0;
    extern f32 lbl_80369708;
    struct {
        u8 buf[0x20];
        u16 w;
        u16 h;
    } sp;

    Ui_LoadAtlasTex(gUiAtlas, sp.buf, 0x38);
    sp.w = GXGetTexObjWidth(sp.buf);
    sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369704);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(sp.buf, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)x, (f32)y, (f32)sp.w, (f32)sp.h);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369708);
    Prim2D_PrepareTex();
    return sp.w;
}

u16 fn_8008B09C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    extern s32 gUiAtlas;
    extern f32 lbl_80369704;
    extern f32 lbl_80369708;
    struct { u8 buf[0x20]; u16 w; u16 h; } sp;
    Ui_LoadAtlasTex(gUiAtlas, sp.buf, 0x37);
    sp.w = GXGetTexObjWidth(sp.buf);
    sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369704);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(sp.buf, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)arg0, (f32)arg1, (f32)arg2, (f32)arg3);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369708);
    Prim2D_PrepareTex();
    return sp.w;
}

u16 Ui_DrawMsgPanelBg(s32 x, s32 y) {
    /* Draw UI atlas tile 0x37 (message panel background) as a 2D rect at (x, y); return its width. */
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiAtlas;
    extern f32 lbl_80369704;
    extern f64 lbl_803696E8;
    extern f64 lbl_803696F0;
    extern f32 lbl_80369708;
    struct {
        u8 buf[0x20];
        u16 w;
        u16 h;
    } sp;

    Ui_LoadAtlasTex(gUiAtlas, sp.buf, 0x37);
    sp.w = GXGetTexObjWidth(sp.buf);
    sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369704);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(sp.buf, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)x, (f32)y, (f32)sp.w, (f32)sp.h);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369708);
    Prim2D_PrepareTex();
    return sp.w;
}

#pragma global_optimizer off
void fn_8008B2B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void Prim2D_Begin(void);
    void Prim2D_EndPrim(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_SetColorByte(u8);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetText(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    extern s32 gUiAtlas;
    extern f32 lbl_803696E0;
    extern f64 lbl_803696E8;
    extern f64 lbl_803696F0;
    extern f32 lbl_80369704;
    extern f32 lbl_80369708;
    struct { u8 buf[0x20]; u16 w; u16 h; } sp;

    Ui_LoadAtlasTex(gUiAtlas, sp.buf, 0x2A);
    sp.w = GXGetTexObjWidth(sp.buf);
    sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_803696E0, lbl_803696E0, (f32)(0x14 - arg3), lbl_80369704);
    Prim2D_SetTex(NULL, 0x13);
    Prim2D_SetColorByte((u8)arg2);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(6);
    Prim2D_SetPos((f32)(arg0 + 0x18), (f32)(arg1 - 1));
    Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
    Prim2D_SetText(arg4);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369704);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(sp.buf, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)(arg0 - 8), (f32)arg1, (f32)sp.w, (f32)sp.h);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369708);
    Prim2D_PrepareTex();
}
#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
#pragma global_optimizer on
#pragma opt_common_subs off
void fn_8008B464(void *self, s32 x, s32 y) {
    void *fn_8003A114(void *);
    void *Face_Create(void *, s32);
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void *Prim2D_PushZ(s32);
    s32 __cvt_fp2unsigned(f32, f32, f32);
    void Prim2D_SetCallback(void (*)(s32, s32), s32);
    void Prim2D_AddZ(f32);
    void fn_8007B4D8(s32, s32, s32, void *);
    void Prim2D_ClearCallbacks(void);
    void *Msg_ResolveName(void *);
    void *fn_800A8978(void *);
    s32 Text_MeasureWidth(void *, s32, f32);
    void fn_8001003C(s16, s16, s32, s32, s32, void *, ...);
    void *Msg_Expand(void *);
    u8 fn_800386B0(void *);
    s8 Unit_GetMaxHp(void *);
    void fn_8007AD6C(void *);
    void fn_8008BA50(s32, s32);
    extern s32 gUiAtlas;
    extern u8 lbl_8026CC88[];
    extern f64 lbl_803696E8;
    extern f64 lbl_803696F0;
    extern f32 lbl_803696E0;
    extern f32 lbl_80369700;
    extern f32 lbl_80369704;
    extern f32 lbl_80369708;
    extern f32 lbl_8036970C;
    extern f32 lbl_80369710;
    extern f32 lbl_80369714;
    extern f32 lbl_80369718;
    extern f32 lbl_8036971C;
    extern f32 lbl_80369720;

    struct { u8 buf[0x20]; u16 w, h; } sp;
    f32 tmp;
    f32 width;
    s32 cb;
    void *tex;
    s32 handle;
    void *name;
    void *cls;


    tex = Face_Create(fn_8003A114(self), 0);
    handle = gUiAtlas;
    cls = *(void **)((u8 *)self + 0x18C);
    name = *(void **)((u8 *)self + 0x188);

    Ui_LoadAtlasTex(handle, sp.buf, 0x16);
    sp.w = GXGetTexObjWidth(sp.buf);
    sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin();
    Prim2D_SetTex(sp.buf, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)x, (f32)y, (f32)sp.w, (f32)sp.h);
    Prim2D_EndPrim();

    tmp = *(f32 *)((u8 *)Prim2D_PushZ(0) + 0xC);
    cb = (u32)(lbl_8036970C + (tmp + (f32)x));
    Prim2D_Begin();
    Prim2D_SetCallback(fn_8008BA50, cb);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369710);
    Prim2D_PrepareTex();

    if (tex) {
        fn_8007B4D8(x + 0xC0, y + 0x5D, 0xFF, tex);
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369714);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369708);
    Prim2D_PrepareTex();

    Ui_LoadAtlasTex(handle, sp.buf, 0x1F);
    sp.w = GXGetTexObjWidth(sp.buf);
    sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin();
    Prim2D_SetTex(sp.buf, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)(x - 5), (f32)(y - 0xB), (f32)sp.w, (f32)sp.h);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTex(NULL, 0x13);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369710);
    Prim2D_PrepareTex();

    {
        void *str = Msg_ResolveName(name);
        width = (f32)Text_MeasureWidth(str, -1, lbl_80369704);
        str = Msg_ResolveName(name);
        fn_8001003C((s16)(lbl_80369718 + (f32)x - lbl_80369700 * width),
                    (s16)(y - 0xB), 1, 0, 0, str, lbl_80369704, lbl_803696E0);
    }
    {
        void *str = fn_800A8978(cls);
        width = (f32)Text_MeasureWidth(str, -1, lbl_80369704);
        str = fn_800A8978(cls);
        fn_8001003C((s16)(lbl_8036971C + (f32)x - lbl_80369700 * width),
                    (s16)(y + 0xF), 2, 0, 0, str, lbl_80369704, lbl_803696E0);
    }

    fn_8001003C((s16)(x + 0x12), (s16)(y + 0x23), 8, 0, 0,
                Msg_Expand(lbl_8026CC88 + 0x3B), lbl_80369704, lbl_803696E0);
    fn_8001003C((s16)(x + 0x28), (s16)(y + 0x23), 2, 0, 0,
                lbl_8026CC88 + 0x41, (s32)((u8 *)self)[0x19A], lbl_80369704, lbl_803696E0);
    fn_8001003C((s16)(x + 0x4C), (s16)(y + 0x23), 8, 0, 0,
                Msg_Expand(lbl_8026CC88 + 0x45), lbl_80369704, lbl_803696E0);

    if (fn_800386B0(self) == 0xFF) {
        fn_8001003C((s16)(x + 0x62), (s16)(y + 0x23), 2, 0, 0,
                    lbl_8026CC88 + 0x4B, lbl_80369704, lbl_803696E0);
    } else {
        fn_8001003C((s16)(x + 0x62), (s16)(y + 0x23), 2, 0, 0,
                    lbl_8026CC88 + 0x41, (u8)fn_800386B0(self), lbl_80369704, lbl_803696E0);
    }

    fn_8001003C((s16)(x + 0x10), (s16)(y + 0x3A), 8, 0, 0,
                Msg_Expand(lbl_8026CC88 + 0x50), lbl_80369704, lbl_803696E0);
    fn_8001003C((s16)(x + 0x3A), (s16)(y + 0x3A), 2, 0, 0,
                lbl_8026CC88 + 0x41, (s32)((u8 *)self)[0x1A8], lbl_80369704, lbl_803696E0);
    fn_8001003C((s16)(x + 0x54), (s16)(y + 0x3A), 0xC, 0, 0,
                lbl_8026CC88 + 0x56, Unit_GetMaxHp(self), lbl_80369704, lbl_803696E0);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369720);
    Prim2D_PrepareTex();
    if (tex) {
        fn_8007AD6C(tex);
    }
}
#pragma pop
void fn_8008BA50(s32 unused, s32 arg1) {
    void GXSetScissor(s32, s32, s32, s32);
    GXSetScissor(arg1 - 0x40, 0, 0x87, 0x1E0);
}

#pragma push
#pragma optimization_level 3
#pragma opt_propagation off
void fn_8008BA80(void *arg0, s32 arg1, s32 arg2, u8 arg3) {
    void Prim2D_SetRect(f32, f32, f32, f32);
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void *Msg_ResolveName(void *);
    s32 Text_MeasureWidth(void *, s32, f32);
    void Text_Draw(s16, s16, s32, void *, ...);
    extern s32 gUiAtlas;
    extern f32 lbl_80369704;
    extern f32 lbl_80369708;
    struct { u8 buf[0x20]; u16 w; u16 h; } sp;
    void *text;
    u8 *texture = sp.buf;
    s32 atlas = gUiAtlas;
    u16 tile = 0x18;
    if (arg3) tile = 0x17;
    Ui_LoadAtlasTex(atlas, texture, tile);
    sp.w = GXGetTexObjWidth(sp.buf);
    sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin();
    Prim2D_SetTex(sp.buf, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)arg1, (f32)arg2, (f32)sp.w, (f32)sp.h);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369708);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    text = Msg_ResolveName(*(void **)((u8 *)arg0 + 0x188));
    Text_Draw((s16)((sp.w - Text_MeasureWidth(text, -1, lbl_80369704))/2), (s16)(arg2+2), 2, text);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369704);
    Prim2D_PrepareTex();
}
#pragma pop
void fn_8008BBF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    M2C_UNK fn_8007D004(s32, u8, f32, f32, f32, f32);
    s32 var_r5;
    u8 var_r7;

    var_r5 = arg2;
    var_r7 = arg4;
    if (var_r7 == 5) {
        var_r7 = 0;
    }
    if (var_r5 == 0) {
        var_r5 = 0x108;
    }
    fn_8007D004(arg5, var_r7, (f32) arg0, (f32) arg1, (f32) var_r5, (f32) arg3);
}

void Ui_DrawRouteTexCw(s32 x, s32 y, u8 flipV) {
    /* Draw route.tpl atlas tile 0x14 at (x, y), rotated 90° CW; optionally flip V. */
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SwapUvV(void);
    void Prim2D_EmitQuad(void);
    void Prim2D_RotateUvCw(void);
    void Prim2D_EndPrim(void);
    extern s32 gUiRouteAtlas;
    extern f64 lbl_803696E8;
    extern f64 lbl_803696F0;
    struct { u8 buf[0x20]; u16 w; u16 h; } sp;
    Ui_LoadAtlasTex(gUiRouteAtlas, sp.buf, 0x14);
    sp.w = GXGetTexObjWidth(sp.buf);
    sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin();
    Prim2D_SetTex(sp.buf, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(2);
    Prim2D_SetRect((f32)x, (f32)y, (f32)sp.h, (f32)sp.w);
    if (flipV != 0) Prim2D_SwapUvV();
    Prim2D_EmitQuad();
    Prim2D_RotateUvCw();
    Prim2D_EndPrim();
}

void Ui_DrawRouteTex(s32 x, s32 y, u8 noFlipV) {
    /* Draw route.tpl atlas tile 0x14 at (x, y); swap V when noFlipV is 0. */
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SwapUvV(void);
    void Prim2D_EndPrim(void);
    extern s32 gUiRouteAtlas;
    extern f64 lbl_803696E8;
    extern f64 lbl_803696F0;
    struct {
        u8 buf[0x20];
        u16 w;
        u16 h;
    } sp;

    Ui_LoadAtlasTex(gUiRouteAtlas, sp.buf, 0x14);
    sp.w = GXGetTexObjWidth(sp.buf);
    sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin();
    Prim2D_SetTex(sp.buf, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)x, (f32)y, (f32)sp.w, (f32)sp.h);
    if (noFlipV == 0) {
        Prim2D_SwapUvV();
    }
    Prim2D_EndPrim();
}

/* Draw route.tpl atlas tile 0x13 centered near (x, y). */
void Ui_DrawRouteIcon(s32 x, s32 y) {
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiRouteAtlas;
    extern f64 lbl_803696E8;
    extern f64 lbl_803696F0;
    struct {
        u8 buf[0x20];
        u16 w;
        u16 h;
    } sp;

    Ui_LoadAtlasTex(gUiRouteAtlas, sp.buf, 0x13);
    sp.w = GXGetTexObjWidth(sp.buf);
    sp.h = GXGetTexObjHeight(sp.buf);
    Prim2D_Begin();
    Prim2D_SetTex(sp.buf, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)(x - 0x20), (f32)(y + 0xC), (f32)sp.w, (f32)sp.h);
    Prim2D_EndPrim();
}

void Ui_DrawRouteIconEx(s32 arg0, s32 arg1, u8 arg2) {
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    u32 OSGetTick(void);
    f64 fn_802380D0(f32);
    extern s32 gUiRouteAtlas;
    extern f32 lbl_80369700;
    extern f32 lbl_80369704;
    extern f32 lbl_8036972C;
    struct {
        u8 buf[0x20];
        u16 x;
        u16 y;
    } sp2;
    struct {
        u8 buf[0x20];
        u16 x;
        u16 y;
    } sp;
    f32 temp_f31;
    u32 ms;
    u32 rem;
    s32 t1;
    s32 t2;
    f32 phase;
    f32 ratio;
    f32 sin_res;

    if (arg2 == 0) {
        Ui_LoadAtlasTex(gUiRouteAtlas, sp.buf, 0x13);
        sp.x = GXGetTexObjWidth(sp.buf);
        sp.y = GXGetTexObjHeight(sp.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp.buf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)(arg0 - 0x20), (f32)(arg1 + 0xC), (f32)sp.x, (f32)sp.y);
        Prim2D_EndPrim();
        return;
    }
    ms = OSGetTick() / ((*(u32 *)0x800000F8 >> 2) / 1000);
    rem = ms % 500;
    phase = (f32)rem;
    ratio = phase / 500.0f;
    sin_res = (f32)fn_802380D0(6.2831855f * ratio);
    temp_f31 = lbl_8036972C * (lbl_80369704 + sin_res);
    Ui_LoadAtlasTex(gUiRouteAtlas, sp2.buf, 0x13);
    sp2.x = GXGetTexObjWidth(sp2.buf);
    sp2.y = GXGetTexObjHeight(sp2.buf);
    Prim2D_Begin();
    Prim2D_SetTex(sp2.buf, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    t1 = (s32)((f32)(arg0 - 0x20) - temp_f31);
    t2 = (s32)(temp_f31 * lbl_80369700 + (f32)arg1) + 0xC;
    Prim2D_SetRect((f32)t1, (f32)t2, (f32)sp2.x, (f32)sp2.y);
    Prim2D_EndPrim();
}

#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
void fn_8008C1D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetAlpha(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_SwapUvU(void);
    void Prim2D_EndPrim(void);
    extern s32 gUiAtlas;
    extern f32 lbl_80369704;
    extern f32 lbl_80369708;
    struct { u8 buf[0x20]; u16 w; u16 h; } sp74, sp50, sp2C, sp8;
    s32 wide;
    s32 wide2;
    s32 wm1;

    if (arg4 == 3) {
        Ui_LoadAtlasTex(gUiAtlas, sp74.buf, 0x36);
        sp74.w = GXGetTexObjWidth(sp74.buf);
        sp74.h = GXGetTexObjHeight(sp74.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp74.buf, 0x10);
        Prim2D_PrepareTex();
        wide = sp74.w;
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)(arg0 + 4), (f32)(arg1 + 8), (f32)(s32)wide, (f32)(arg3 - 0x10));
        Prim2D_SetAlpha(0xD1);
        Prim2D_EndPrim();
        goto block_6;
    } else if (arg4 == 0) {
        Ui_LoadAtlasTex(gUiAtlas, sp50.buf, 0x2E);
        sp50.w = GXGetTexObjWidth(sp50.buf);
        sp50.h = GXGetTexObjHeight(sp50.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp50.buf, 0x10);
        Prim2D_PrepareTex();
        wide = sp50.w;
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)(arg0 + 4), (f32)(arg1 + 0xE), (f32)(s32)wide, (f32)(arg3 - 0x1C));
        Prim2D_SetAlpha(0xB3);
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369708);
        Prim2D_PrepareTex();
        Ui_LoadAtlasTex(gUiAtlas, sp50.buf, 0x2B);
        sp50.w = GXGetTexObjWidth(sp50.buf);
        sp50.h = GXGetTexObjHeight(sp50.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp50.buf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)arg0, (f32)arg1, (f32)sp50.w, (f32)sp50.h);
        Prim2D_EndPrim();
        Ui_LoadAtlasTex(gUiAtlas, sp50.buf, 0x2C);
        sp50.w = GXGetTexObjWidth(sp50.buf);
        sp50.h = GXGetTexObjHeight(sp50.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp50.buf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)arg0, (f32)((arg1 + arg3) - sp50.h), (f32)sp50.w, (f32)sp50.h);
        Prim2D_EndPrim();
        Ui_LoadAtlasTex(gUiAtlas, sp50.buf, 0x2D);
        sp50.w = GXGetTexObjWidth(sp50.buf);
        sp50.h = GXGetTexObjHeight(sp50.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp50.buf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)arg0, (f32)(arg1 + 0x18), (f32)sp50.w, (f32)(arg3 - 0x30));
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)(arg0 + wide), (f32)(arg1 + 0x18), (f32)sp50.w, (f32)(arg3 - 0x30));
        Prim2D_SwapUvU();
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369704);
        Prim2D_PrepareTex();
    } else if (arg4 == 1) {
        Ui_LoadAtlasTex(gUiAtlas, sp2C.buf, 0x36);
        sp2C.w = GXGetTexObjWidth(sp2C.buf);
        sp2C.h = GXGetTexObjHeight(sp2C.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp2C.buf, 0x10);
        Prim2D_PrepareTex();
        wide = sp2C.w;
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)(arg0 + 4), (f32)(arg1 + 8), (f32)(s32)wide, (f32)(arg3 - 0x10));
        Prim2D_SetAlpha(0xB3);
        Prim2D_EndPrim();
block_6:
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369708);
        Prim2D_PrepareTex();
        Ui_LoadAtlasTex(gUiAtlas, sp2C.buf, 0x33);
        sp2C.w = GXGetTexObjWidth(sp2C.buf);
        sp2C.h = GXGetTexObjHeight(sp2C.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp2C.buf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)arg0, (f32)arg1, (f32)sp2C.w, (f32)sp2C.h);
        Prim2D_EndPrim();
        Ui_LoadAtlasTex(gUiAtlas, sp2C.buf, 0x34);
        sp2C.w = GXGetTexObjWidth(sp2C.buf);
        sp2C.h = GXGetTexObjHeight(sp2C.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp2C.buf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)arg0, (f32)((arg1 + arg3) - sp2C.h), (f32)sp2C.w, (f32)sp2C.h);
        Prim2D_EndPrim();
        Ui_LoadAtlasTex(gUiAtlas, sp2C.buf, 0x35);
        sp2C.w = GXGetTexObjWidth(sp2C.buf);
        sp2C.h = GXGetTexObjHeight(sp2C.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp2C.buf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)(arg0 + 1), (f32)(arg1 + 0x10), (f32)sp2C.w, (f32)(arg3 - 0x20));
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        wm1 = (s32)wide - 1;
        Prim2D_SetRect((f32)(arg0 + wm1), (f32)(arg1 + 0x10), (f32)sp2C.w, (f32)(arg3 - 0x20));
        Prim2D_SwapUvU();
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369704);
        Prim2D_PrepareTex();
    } else if (arg4 == 2) {
        Ui_LoadAtlasTex(gUiAtlas, sp8.buf, 0x32);
        sp8.w = GXGetTexObjWidth(sp8.buf);
        sp8.h = GXGetTexObjHeight(sp8.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp8.buf, 0x10);
        Prim2D_PrepareTex();
        wide2 = sp8.w + 0x20;
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)(arg0 + 4), (f32)(arg1 + 0xE), (f32)wide2, (f32)(arg3 - 0x1C));
        Prim2D_SetAlpha(0xB3);
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369708);
        Prim2D_PrepareTex();
        Ui_LoadAtlasTex(gUiAtlas, sp8.buf, 0x2F);
        sp8.w = GXGetTexObjWidth(sp8.buf);
        sp8.h = GXGetTexObjHeight(sp8.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp8.buf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)arg0, (f32)arg1, (f32)sp8.w, (f32)sp8.h);
        Prim2D_EndPrim();
        Ui_LoadAtlasTex(gUiAtlas, sp8.buf, 0x30);
        sp8.w = GXGetTexObjWidth(sp8.buf);
        sp8.h = GXGetTexObjHeight(sp8.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp8.buf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)arg0, (f32)((arg1 + arg3) - sp8.h), (f32)sp8.w, (f32)sp8.h);
        Prim2D_EndPrim();
        Ui_LoadAtlasTex(gUiAtlas, sp8.buf, 0x31);
        sp8.w = GXGetTexObjWidth(sp8.buf);
        sp8.h = GXGetTexObjHeight(sp8.buf);
        Prim2D_Begin();
        Prim2D_SetTex(sp8.buf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)arg0, (f32)(arg1 + 0x18), (f32)sp8.w, (f32)(arg3 - 0x30));
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)(arg0 + wide2), (f32)(arg1 + 0x18), (f32)sp8.w, (f32)(arg3 - 0x30));
        Prim2D_SwapUvU();
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369704);
        Prim2D_PrepareTex();
    }
}
#pragma pop
void fn_8008CD34(void) {
    M2C_UNK Prim2D_SetTex(M2C_UNK, M2C_UNK);
    M2C_UNK Prim2D_PrepareTex();
    M2C_UNK Prim2D_Begin();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
}

void fn_8008CD64(f32 farg0) {
    M2C_UNK Prim2D_AddZ(f32);
    Prim2D_Begin();
    Prim2D_AddZ(farg0);
    Prim2D_PrepareTex();
}

#pragma scheduling reset
#include "common.h"
#include "unit.h"

extern s32 gUiAtlas;
extern f32 lbl_80369704;
extern f32 lbl_80369708;
extern f64 lbl_803696E8;
extern f64 lbl_803696F0;
extern f32 lbl_803696E0;
extern f32 lbl_803696F8;
extern f32 lbl_803696FC;
extern f32 lbl_80369700;
extern u16 lbl_802899C0[256];
