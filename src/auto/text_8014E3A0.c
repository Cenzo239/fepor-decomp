/* Functions from 0x8014E3A0 to 0x801620BC, found by decomp-toolkit. */
#include "common.h"


static inline void *MsgDebug_FilterText(void *text, u8 *dst)
{
    void *Msg_Expand(void *);
    extern u8 lbl_80330C80[];
    u8 *src = (u8 *)Msg_Expand(text);
    u8 ch;
    u8 *lim = lbl_80330C80 + 0x46;
    while ((s8)(ch = *src) != 0) {
        if ((s8)ch != 10 && ch >= 0x80) {
            dst[0] = *src;
            dst[1] = *++src;
            dst += 2;
            if (dst >= lim) break;
        }
        src++;
    }
    *dst = 0;
    return lbl_80330C80;
}


extern u32 *gPrim2D;
typedef struct { u8 r, g, b, a; } Color;
typedef struct { s32 c0, c1, c2, c3; } Color4;
typedef struct { s32 c3, c2, c1, c0; } Color4rev;

s32 fn_8014E3A0(void) {
    return 0;
}

s32 fn_8014E3A8(void) {
    return 0x260;
}

void *fn_8014E3B0(void) {
    extern u16 lbl_80277238[];
    return (u8 *)lbl_80277238 + 0xA2;
}

s32 fn_8014E3C0(void) {
    return 9;
}

void *fn_8014E3C8(void) {
    void sprintf(void *, void *, ...);
    extern u8 lbl_80330CC8[];
    extern u8 lbl_80277238[];
    extern s32 gMsgDebugPage;
    extern s32 gMsgDebugPageCount;

    sprintf(lbl_80330CC8, lbl_80277238 + 0xD0, gMsgDebugPage + 1, gMsgDebugPageCount);
    return lbl_80330CC8;
}

s32 fn_8014E414(void) {
    return 0;
}

extern s32 gMsgDebugPage;
extern u32 gMsgDebugCount;
extern u8 lbl_80277238[];
extern u32 gMsgDebugPtrs;
void *fn_8014E41C(s32 arg0, void *arg1) {
    extern s32 gMsgDebugPage;
    extern u32 gMsgDebugCount;
    extern u8 lbl_80277238[];
    extern u32 gMsgDebugPtrs;
    s32 idx;
    s32 limit;

    idx = *(u8 *)((char *)arg1 + 0x3A) + gMsgDebugPage * 0x18;
    limit = gMsgDebugCount;
    if (idx >= limit) {
        return lbl_80277238 + 0x85;
    }
    return *(void **)(gMsgDebugPtrs + idx * 4);
}

s32 fn_8014E458(void) {
    extern void *gPadInput;
    extern s32 gMsgDebugPage;
    extern s32 gMsgDebugPageCount;
    if (M2C_FIELD(gPadInput, s32 *, 0x10) & 0x01000001) {
        gMsgDebugPage = (gMsgDebugPage + gMsgDebugPageCount - 1) % gMsgDebugPageCount;
    }
    if (M2C_FIELD(gPadInput, s32 *, 0x10) & 0x02000002) {
        gMsgDebugPage = (gMsgDebugPage + 1) % gMsgDebugPageCount;
    }
    return 0;
}

s32 fn_8014E4C8(void *arg0, void *arg1, void *arg2) {
    extern s32 gMsgDebugPage;
    extern u32 gMsgDebugCount;
    extern s32 lbl_80367B84;
    extern u32 gMsgDebugPtrs;
    char *Msg_Expand(void *);
    s32 index;
    char *str;
    u8 flag;

    index = gMsgDebugPage * 0x18;
    index += *(u8 *)((u8 *)arg2 + 0x3A);
    lbl_80367B84 = index;
    if (index >= (s32)gMsgDebugCount) {
        return 0x10;
    }
    if (*(void **)(gMsgDebugPtrs + index * 4) == NULL) {
        flag = 0;
    } else {
        str = Msg_Expand(*(void **)(gMsgDebugPtrs + index * 4));
        if (str[0] != '$') {
            flag = 0;
        } else if (str[1] != 'R') {
            flag = 0;
        } else {
            flag = 1;
        }
    }
    if (flag == 0) {
        return 0x10;
    }
    return 5;
}

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma global_optimizer off
extern "C" void fn_8014E568(void *unused, void *arg1, void *arg2) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetText(void *);
    void Prim2D_SetScale(f32);
    void Prim2D_SetTint(s32, s32, s32, s32);
    void Prim2D_EndPrim(void);
    void *Msg_Expand(void *);
    extern s32 gMsgDebugPage;
    extern u32 gMsgDebugCount;
    extern u8 *gMsgDebugKinds;
    extern u32 gMsgDebugPtrs;
    extern f32 lbl_8036A800;
    extern f32 lbl_8036A804;
    extern f32 lbl_8036A808;
    extern u8 lbl_80277238[];
    extern u8 lbl_80330C80[];
    struct Obj {
        u8 pad[4];
        virtual f32 v0() = 0; virtual f32 v1() = 0; virtual f32 v2() = 0; virtual f32 v3() = 0;
        virtual f32 v4() = 0; virtual f32 v5() = 0; virtual f32 v6() = 0; virtual f32 v7() = 0;
        virtual f32 v8() = 0; virtual f32 v9() = 0; virtual f32 v10() = 0; virtual f32 v11() = 0;
        virtual f32 v12() = 0; virtual f32 v13() = 0; virtual f32 v14() = 0; virtual f32 v15() = 0;
        virtual f32 v16() = 0; virtual f32 v17() = 0; virtual f32 v18() = 0; virtual f32 v19() = 0;
        virtual f32 v20() = 0; virtual f32 v21() = 0; virtual f32 v22() = 0; virtual f32 v23() = 0;
        virtual f32 v24() = 0; virtual f32 v25() = 0;
    };
    s32 idx;
    s32 r, g, b;
    char *dst;
    u8 *src;
    void *str;
    s32 mul;

    (void)unused;
    mul = gMsgDebugPage * 0x18;
    idx = mul + *(u8 *)((u8 *)arg2 + 0x3A);
    if (idx >= (s32)gMsgDebugCount) {
        return;
    }
    Prim2D_Begin();
    {
        Obj *obj = *(Obj **)((u8 *)arg1 + 0x3C);
        Prim2D_SetTransform((f32)*(s16 *)((u8 *)arg1 + 0x30), (f32)*(s16 *)((u8 *)arg1 + 0x32),
                    obj->v25() - lbl_8036A800, lbl_8036A804);
    }
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    switch (gMsgDebugKinds[idx]) {
    case 0:
        r = 0; g = 0; b = 0;
        break;
    case 1:
        r = 0xFF; g = 0xFF; b = 0xFF;
        break;
    case 2:
        r = 0xFF; g = 0; b = 0xFF;
        break;
    case 4:
        r = 0xFF; g = 0; b = 0;
        break;
    }
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)*(s16 *)((u8 *)arg2 + 0x30), (f32)*(s16 *)((u8 *)arg2 + 0x32));
    idx <<= 2;
    str = *(void **)(gMsgDebugPtrs + idx);
    Prim2D_SetText(str);
    Prim2D_SetScale(lbl_8036A808);
    Prim2D_SetTint(r, g, b, 0xFF);
    Prim2D_EndPrim();
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)(*(s16 *)((u8 *)arg2 + 0x30) + 0xB0), (f32)*(s16 *)((u8 *)arg2 + 0x32));
    str = *(void **)(gMsgDebugPtrs + idx);
    if ((u32)str == 0) {
        str = lbl_80277238 + 0x85;
    } else {
        str = MsgDebug_FilterText(str, lbl_80330C80);
    }
    Prim2D_SetText(str);
    Prim2D_SetScale(lbl_8036A808);
    Prim2D_SetTint(r, g, b, 0xFF);
    Prim2D_EndPrim();
}
#pragma global_optimizer reset
#pragma cplusplus off
#pragma use_lmw_stmw on

void fn_8014E7F8(void *arg0) {
    M2C_UNK fn_8014E864();
    if ((u32) M2C_FIELD(arg0, u32 *, 0x54) != 0U) {
        fn_8014E864();
    }
}

void fn_8014E824(void *arg0)
{
    void fn_80067708(s32, u32, void *, void *);
    void fn_8014E864(void);

    u8 *ptr;

    ptr = (u8 *)arg0;

    if (*(u32 *)(ptr + 0x54) != 0) {
        fn_80067708(
            2,
            ptr[0x87],
            (void *)fn_8014E864,
            arg0
        );
    }
}

#pragma use_lmw_stmw on
extern f32 lbl_8036A818;
extern f32 lbl_8036A81C;
extern f32 lbl_8036A820;
extern f64 lbl_8036A828;
extern f64 lbl_8036A830;
extern u8 lbl_80277320[];
#pragma use_lmw_stmw on
void fn_8014E864(void *arg0) {
    void *fn_80060638(void *);
    void *fn_80060664(void *);
    void *fn_8006060C(void *);
    void GMaterial_ApplyRenderState(void *, s32);
    void fn_8006C6F8(void *, s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetZMode(s32, s32, s32);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void QUATMtx(void *, void *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXCopy(void *, void *);
    void Game_Assert(void *, s32, void *);
    void *Camera_GetViewMtx(void);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void fn_801502EC(void *, void *, void *, void *);
    void fn_8014EFB8(void *, void *, void *, void *, void *);
    void GXClearVtxDesc(void);
    void GXSetVtxDesc(s32, s32);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void GXSetNumTevStages(s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void fn_8022100C(s32);
    void fn_80220F44(s32, s32);
    void GXBegin(s32, s32, s32);

    u8 bufF8[0x30];
    u8 bufC8[0x30];
    u8 buf98[0x30];
    u8 buf68[0x30];
    u8 buf38[0x30];
    u8 buf8[0x30];
    void *unk31;
    void *obj54;
    void *mesh;
    u8 *entry;
    void *unk22;
    u8 *mtx;
    s32 i;
    s32 off;
    void *vtx;
    void *base;
    s32 mode;
    f32 scale;
    s32 w;
    s32 vi;
    u8 *vp;

    unk31 = fn_80060638(arg0);
    fn_80060664(arg0);
    obj54 = *(void **)((u8 *)arg0 + 0x54);
    mesh = *(void **)((u8 *)obj54 + 0x34);
    entry = (u8 *)mesh + 8;
    unk22 = fn_8006060C(arg0);
    GMaterial_ApplyRenderState(arg0, 2);
    mtx = (u8 *)arg0 + 0x10;
    i = 0;
    off = 0;

    for (;;) {
        if (i >= (s32)*(u16 *)((u8 *)mesh + 6)) {
            break;
        }
        if ((*(u32 *)arg0 & 0x00400000) != 0) {
            if ((*(u16 *)(entry + 6) & 0x0800) != 0) {
                vtx = *(void **)(*(u8 **)((u8 *)obj54 + 0x38) + off);
                base = (u8 *)*(void **)((u8 *)unk31 + 0x34) + (*(s16 *)(entry + 0xA) << 5);
                GXSetCullMode(1);
                GXSetBlendMode(0, 0, 0, 1, 0, 0, 2);
                GXSetBlendMode(2, 0, 1, 1, 0, 0, 2);
                fn_802245D8(1, 4, 5, 0);
                if (*(u16 *)(entry + 6) & 0x1000) {
                    fn_802245D8(1, 4, 1, 0);
                }
                if (*(u16 *)(entry + 6) & 0x2000) {
                    fn_802245D8(3, 0, 0, 0);
                }
                if (*(u16 *)(entry + 6) & 0x4000) {
                    GXSetZMode(0, 3, 0);
                }
                if (*(u16 *)(entry + 6) & 0x8000) {
                    GXSetBlendMode(0, 1, 0, 1, 1, 0, 2);
                }

                switch (*(u32 *)((u8 *)arg0 + 0xC)) {
                case 1:
                    PSMTXRotRad(buf68, 0x58, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x1C));
                    PSMTXRotRad(buf98, 0x59, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x20));
                    PSMTXRotRad(bufC8, 0x5A, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x24));
                    goto perm_join;
                case 2:
                    PSMTXRotRad(buf68, 0x59, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x20));
                    PSMTXRotRad(buf98, 0x5A, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x24));
                    PSMTXRotRad(bufC8, 0x58, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x1C));
                    goto perm_join;
                case 3:
                    PSMTXRotRad(buf68, 0x5A, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x24));
                    PSMTXRotRad(buf98, 0x58, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x1C));
                    PSMTXRotRad(bufC8, 0x59, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x20));
                    goto perm_join;
                case 4:
                    PSMTXRotRad(buf68, 0x58, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x1C));
                    PSMTXRotRad(buf98, 0x5A, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x24));
                    PSMTXRotRad(bufC8, 0x59, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x20));
                    goto perm_join;
                case 5:
                    PSMTXRotRad(buf68, 0x59, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x20));
                    PSMTXRotRad(buf98, 0x58, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x1C));
                    PSMTXRotRad(bufC8, 0x5A, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x24));
                    goto perm_join;
                case 6:
                    PSMTXRotRad(buf68, 0x5A, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x24));
                    PSMTXRotRad(buf98, 0x59, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x20));
                    PSMTXRotRad(bufC8, 0x58, lbl_8036A818 * *(f32 *)((u8 *)arg0 + 0x1C));
                    goto perm_join;
                case 8:
                    PSMTXScale(buf8, *(f32 *)((u8 *)arg0 + 0x28), *(f32 *)((u8 *)arg0 + 0x2C), *(f32 *)((u8 *)arg0 + 0x30));
                    PSMTXTrans(buf38, *(f32 *)((u8 *)arg0 + 0x10), *(f32 *)((u8 *)arg0 + 0x14), *(f32 *)((u8 *)arg0 + 0x18));
                    QUATMtx(mtx, buf68);
                    PSMTXConcat(buf68, buf8, bufF8);
                    PSMTXConcat(buf68, bufF8, bufF8);
                    PSMTXConcat(buf38, bufF8, bufF8);
                    goto after_mtx;
                case 7:
                    PSMTXCopy(mtx, bufF8);
                    goto after_mtx;
                case 0:
                default:
                    Game_Assert(lbl_80277320, 0xB8, lbl_80277320 + 8);
                perm_join:
                    PSMTXScale(buf8, *(f32 *)((u8 *)arg0 + 0x28), *(f32 *)((u8 *)arg0 + 0x2C), *(f32 *)((u8 *)arg0 + 0x30));
                    PSMTXTrans(buf38, *(f32 *)((u8 *)arg0 + 0x10), *(f32 *)((u8 *)arg0 + 0x14), *(f32 *)((u8 *)arg0 + 0x18));
                    PSMTXConcat(buf68, buf8, bufF8);
                    PSMTXConcat(buf98, bufF8, bufF8);
                    PSMTXConcat(bufC8, bufF8, bufF8);
                    PSMTXConcat(buf38, bufF8, bufF8);
                after_mtx:
                    PSMTXConcat(Camera_GetViewMtx(), bufF8, bufF8);
                    GXLoadPosMtxImm(bufF8, 0);
                    GXSetCurrentMtx(0);

                    mode = *(u16 *)(entry + 6) & 7;
                    switch (mode) {
                    case 1:
                        fn_801502EC(entry, vtx, base, unk22);
                        break;
                    case 2:
                        base = vtx;
                        GXClearVtxDesc();
                        GXSetVtxDesc(9, 1);
                        GXSetVtxDesc(11, 1);
                        GXSetVtxAttrFmt(0, 9, 1, 4, 0);
                        GXSetVtxAttrFmt(0, 11, 1, 5, 0);
                        GXSetNumChans(0);
                        GXSetNumTevStages(1);
                        GXSetTevOrder(0, 0xFF, 0xFF, 4);
                        GXSetNumTexGens(0, 4);
                        fn_8022100C(0);
                        w = (s32)(lbl_8036A81C * (f32)*(s16 *)(entry + 0x10));
                        scale = lbl_8036A81C * (f32)*(s16 *)(entry + 0x14);
                        if (w > 0x28) {
                            w = 0x28;
                        }
                        fn_80220F44((s32)(lbl_8036A820 * (f32)w), 0);
                        for (vi = 0; vi < (s32)*(u16 *)(entry + 0x1E); vi++) {
                            vp = (u8 *)base;
                            base = (u8 *)base + 0x2C;
                            if (vp[0x28] != 0) {
                                GXBegin(0xA8, 0, 2);
                                *(volatile f32 *)0xCC008000 = *(f32 *)(vp + 0);
                                *(volatile f32 *)0xCC008000 = *(f32 *)(vp + 4);
                                *(volatile f32 *)0xCC008000 = *(f32 *)(vp + 8);
                                *(volatile u8 *)0xCC008000 = vp[0x29];
                                *(volatile u8 *)0xCC008000 = vp[0x2A];
                                *(volatile u8 *)0xCC008000 = vp[0x2B];
                                *(volatile u8 *)0xCC008000 = vp[0x28];
                                *(volatile f32 *)0xCC008000 = *(f32 *)(vp + 0) - *(f32 *)(vp + 0xC) * *(f32 *)(vp + 0x1C);
                                *(volatile f32 *)0xCC008000 = *(f32 *)(vp + 4) - *(f32 *)(vp + 0x10) * *(f32 *)(vp + 0x1C);
                                *(volatile f32 *)0xCC008000 = *(f32 *)(vp + 8) - *(f32 *)(vp + 0x14) * *(f32 *)(vp + 0x1C);
                                *(volatile u8 *)0xCC008000 = vp[0x29];
                                *(volatile u8 *)0xCC008000 = vp[0x2A];
                                *(volatile u8 *)0xCC008000 = vp[0x2B];
                                *(volatile u8 *)0xCC008000 = (u8)(s32)((f32)vp[0x28] * scale);
                            }
                        }
                        break;
                    case 3:
                    case 4:
                        fn_8014EFB8(arg0, entry, vtx, base, unk22);
                        break;
                    }
                }
            }
        }
        off += 4;
        i++;
        entry += 0x34;
    }

    GXSetZMode(1, 3, 0);
    fn_802245D8(1, 4, 5, 7);
    fn_8006C6F8(arg0, 2);
}
volatile unsigned long long fn_8014EFB8(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4)
{
  void *fn_80060664(void *);
  void fn_8022100C(s32);
  void GXClearVtxDesc(void);
  long new_var3;
  void GXSetVtxDesc(s32, s32);
  void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
  void Ui_LoadAtlasTex(void *, void *, u16);
  void fn_80222C50(void *, s32);
  void GXSetNumChans(s32);
  void GXSetNumTevStages(s32);
  void GXSetTevOrder(s32, s32, s32, s32);
  void GXSetNumTexGens(s32);
  void fn_802201A8(s32, s32, s32, s32, s32, s32);
  void PSMTXRotRad(f32 *, s32, f32);
  void PSMTXScale(f32 *, f32, f32, f32);
  f32 new_var5;
  void PSMTXTrans(f32 *, f32, f32, f32);
  void QUATMtx(void *, f32 *);
  void PSMTXCopy(f32 *, f32 *);
  void PSMTXConcat(f32 *, f32 *, f32 *);
  void PSMTXIdentity(f32 *);
  void *Camera_GetViewMtx(void);
  u8 *new_var9;
  void *Camera_Get(void);
  f32 *new_var2;
  void fn_802020F0(void *, f32 *);
  void fn_8006C100(f32 *, f32 *);
  u8 *new_var6;
  void fn_802029C4(f32 *, f32 *, f32 *);
  void fn_802031A8(void *, void *, f32 *);
  f64 fn_80237E90(f32);
  void GXLoadPosMtxImm(f32 *, u32);
  void GXSetCurrentMtx(u32);
  void fn_80224E50(f32 *, s32, s32);
  void GXBegin(s32, s32, s32);
  f32 fn_80064164(void *, s16, f32);
  f32 fn_8006469C(void *, s16, f32);
  f32 fn_80064400(void *, s16, f32);
  f32 fn_80063EC8(void *, s16, f32);
  f32 fn_80063C2C(void *, s16, f32);
  void Game_Assert(void *, s32, void *);
  extern f32 lbl_8036A818;
  extern f32 lbl_8036A838;
  s16 new_var7;
  extern f32 lbl_8036A83C;
  extern f32 lbl_8036A840;
  extern f32 lbl_8036A844;
  extern f32 lbl_8036A848;
  extern f32 lbl_8036A84C;
  extern u8 lbl_80277320[];
  extern s16 lbl_802939F0[];
  u8 *transform = (u8 *) arg0;
  u8 *renderFlags = (u8 *) arg1;
  u8 *sprite = (u8 *) arg2;
  u8 *renderData = (u8 *) arg3;
  u8 *geometry;
  u8 *effect;
  void *effects;
  u8 frame[0x568];
  void *camera;
  int new_var8;
  volatile f32 *fifoFloat = (volatile f32 *) 0xCC008000;
  volatile u8 *fifoByte = (volatile u8 *) 0xCC008000;
  s32 mode;
  s32 rendered;
  s32 batch;
  char slot;
  u8 *new_var4;
  s32 i;
  s32 j;
  u8 *batchStart;
  u8 hasEffects;
  f32 v0;
  f32 v1;
  f32 v2;
  f32 v3;
  f32 v4;
  f32 angle;
  f32 factor;
  f32 x0;
  f32 y0;
  f32 x1;
  f32 y1;
  u8 *new_var;
  f32 z;
  f32 halfWidth;
  f32 halfHeight;
  if ((*((u32 *) (renderData + 0x14))) == 0)
  {
    return;
  }
  geometry = (u8 *) fn_80060664(transform);
  effect = *((u8 **) (renderData + 0x14));
  fn_8022100C(0);
  new_var8 = 1;
  GXClearVtxDesc();
  GXSetVtxDesc(9, 1);
  GXSetVtxDesc(11, 1);
  GXSetVtxDesc(13, 1);
  GXSetVtxAttrFmt(0, 9, new_var8, 4, 0);
  GXSetVtxAttrFmt(0, 11, new_var8, 5, 0);
  GXSetVtxAttrFmt(0, 13, new_var8, 4, 0);
  Ui_LoadAtlasTex(arg4, frame + 0x24, *((u16 *) (effect + 4)));
  new_var4 = frame;
  fn_80222C50(new_var4 + 0x24, 0);
  GXSetNumChans(1);
  GXSetNumTevStages(new_var8);
  GXSetTevOrder(0, 0, 0, 4);
  new_var7 = *((s16 *) (renderFlags + 0xa));
  GXSetNumTexGens(0);
  hasEffects = 0;
  if ((geometry != 0) && ((*((u8 **) geometry)) != 0))
  {
    effects = *((void **) geometry);
    if ((((((*((void **) (((u8 *) effects) + 0x14))) != 0) || ((*((void **) (((u8 *) effects) + 0x0c))) != 0)) || ((*((void **) (((u8 *) effects) + 0x10))) != 0)) || ((*((void **) (((u8 *) effects) + 0x18))) != 0)) || ((*((void **) (((u8 *) effects) + 0x1c))) != 0))
    {
      hasEffects = new_var8;
    }
  }
  if ((!hasEffects) && (((*((u16 *) effect)) & 1) != 0))
  {
    fn_802201A8(0, new_var8, 4, 0x3c, 0, 0x7d);
  }
  else
  {
    hasEffects = new_var8;
    fn_802201A8(0, 1, 4, 0x1e, 0, 0x7d);
  }
  switch (*((u32 *) (transform + 0x0c)))
  {
    case 0:
      PSMTXRotRad((f32 *) (frame + 0x3a4), 'X', lbl_8036A818 * (*((f32 *) (transform + 0x1c))));
      PSMTXRotRad((f32 *) (frame + 0x3d4), 'Y', lbl_8036A818 * (*((f32 *) (transform + 0x20))));
      PSMTXRotRad((f32 *) (new_var4 + 0x404), 'Z', lbl_8036A818 * (*((f32 *) (transform + 0x24))));
      break;

    case 1:
      PSMTXRotRad((f32 *) (new_var4 + 0x3a4), 'Y', lbl_8036A818 * (*((f32 *) (transform + 0x20))));
      PSMTXRotRad((f32 *) (frame + 0x3d4), 'Z', lbl_8036A818 * (*((f32 *) (transform + 0x24))));
      PSMTXRotRad((f32 *) (new_var4 + 0x404), 'X', lbl_8036A818 * (*((f32 *) (transform + 0x1c))));
      break;

    case 2:
      PSMTXRotRad((f32 *) (new_var4 + 0x3a4), 'Z', lbl_8036A818 * (*((f32 *) (transform + 0x24))));
      PSMTXRotRad((f32 *) (new_var4 + 0x3d4), 'X', lbl_8036A818 * (*((f32 *) (transform + 0x1c))));
      PSMTXRotRad((f32 *) (new_var4 + 0x404), 'Y', lbl_8036A818 * (*((f32 *) (transform + 0x20))));
      break;

    case 3:
      PSMTXRotRad((f32 *) (frame + 0x3a4), 'X', lbl_8036A818 * (*((f32 *) (transform + 0x1c))));
      PSMTXRotRad((f32 *) (frame + 0x3d4), 'Z', lbl_8036A818 * (*((f32 *) (transform + 0x24))));
      PSMTXRotRad((f32 *) (frame + 0x404), 'Y', lbl_8036A818 * (*((f32 *) (transform + 0x20))));
      break;
      new_var = new_var;

    case 4:
      PSMTXRotRad((f32 *) (frame + 0x3a4), 'Y', lbl_8036A818 * (*((f32 *) (transform + 0x20))));
      PSMTXRotRad((f32 *) (new_var4 + 0x3d4), 'X', lbl_8036A818 * (*((f32 *) (transform + 0x1c))));
      PSMTXRotRad((f32 *) (new_var4 + 0x404), 'Z', lbl_8036A818 * (*((f32 *) (transform + 0x24))));
      break;

    case 5:
      PSMTXRotRad((f32 *) (new_var4 + 0x3a4), 'Z', lbl_8036A818 * (*((f32 *) (transform + 0x24))));
      PSMTXRotRad((f32 *) (new_var4 + 0x3d4), 'Y', lbl_8036A818 * (*((f32 *) (transform + 0x20))));
      PSMTXRotRad((f32 *) (new_var4 + 0x404), 'X', lbl_8036A818 * (*((f32 *) (transform + 0x1c))));
      break;

    case 6:
      PSMTXScale((f32 *) (frame + 0x344), *((f32 *) (transform + 0x28)), *((f32 *) (transform + 0x2c)), *((f32 *) (transform + 0x30)));
      PSMTXTrans((f32 *) (frame + 0x374), *((f32 *) (transform + 0x10)), *((f32 *) (transform + 0x14)), *((f32 *) (transform + 0x18)));
      QUATMtx(transform + 0x10, (f32 *) (new_var4 + 0x3a4));
      PSMTXConcat((f32 *) (frame + 0x3a4), (f32 *) (frame + 0x344), (f32 *) (new_var4 + 0x4f4));
      PSMTXConcat((f32 *) (frame + 0x3a4), (f32 *) (new_var4 + 0x4f4), (f32 *) (frame + 0x4f4));
      PSMTXConcat((f32 *) (new_var4 + 0x374), (f32 *) (new_var4 + 0x4f4), (f32 *) (new_var4 + 0x4f4));
      goto finishedTransform;

    case 7:
      PSMTXCopy((f32 *) (transform + 0x10), (f32 *) (frame + 0x4f4));
      goto finishedTransform;

    case 8:

    default:
      Game_Assert(lbl_80277320, 0xb8, lbl_80277320 + 8);
      break;
      if (!x0)
    {
    }

  }

  PSMTXScale((f32 *) (frame + 0x344), *((f32 *) (transform + 0x28)), *((f32 *) (transform + 0x2c)), *((f32 *) (transform + 0x30)));
  PSMTXTrans((f32 *) (new_var4 + 0x374), *((f32 *) (transform + 0x10)), *((f32 *) (transform + 0x14)), *((f32 *) (transform + 0x18)));
  PSMTXConcat((f32 *) (frame + 0x3a4), (f32 *) (new_var4 + 0x344), (f32 *) (frame + 0x4f4));
  PSMTXConcat((f32 *) (frame + 0x3d4), (f32 *) (new_var4 + 0x4f4), (f32 *) (new_var4 + 0x4f4));
  PSMTXConcat((f32 *) (new_var4 + 0x404), (f32 *) (new_var4 + 0x4f4), (f32 *) (new_var4 + 0x4f4));
  PSMTXConcat((f32 *) (new_var4 + 0x374), (f32 *) (new_var4 + 0x4f4), (f32 *) (new_var4 + 0x4f4));
  new_var6 = frame + 0x4c4;
  finishedTransform:
  fn_802020F0(Camera_GetViewMtx(), (f32 *) new_var6);

  fn_8006C100((f32 *) (new_var4 + 0x4f4), (f32 *) (new_var4 + 0x464));
  PSMTXConcat((f32 *) (frame + 0x4c4), (f32 *) (frame + 0x464), (f32 *) (frame + 0x4c4));
  mode = (*((u16 *) (renderFlags + 6))) & 0x600;
  if (mode == 0x600)
  {
    PSMTXTrans((f32 *) (new_var4 + 0x494), ((f32 *) (new_var4 + 0x4f4))[3], ((f32 *) (frame + 0x4f4))[7], ((f32 *) (frame + 0x4f4))[11]);
    PSMTXConcat((f32 *) (frame + 0x494), (f32 *) (new_var4 + 0x4c4), (f32 *) (new_var4 + 0x524));
    PSMTXConcat((f32 *) Camera_GetViewMtx(), (f32 *) (frame + 0x524), (f32 *) (new_var4 + 0x524));
    GXLoadPosMtxImm((f32 *) (frame + 0x524), 0);
    for (i = 0; i < (*((u16 *) (renderFlags + 0x1e))); ++i, sprite += 0x2c)
    {
      new_var5 = *((f32 *) (sprite + 0x18));
      if ((sprite[0x28] == 0) || (new_var5 == lbl_8036A838))
      {
        continue;
      }
      if (hasEffects)
      {
        v0 = *((f32 *) (effect + 0x18));
        v1 = *((f32 *) (effect + 8));
        v2 = *((f32 *) (effect + 0xc));
        v3 = *((f32 *) (effect + 0x10));
        v4 = *((f32 *) (effect + 0x14));
        effects = *((void **) geometry);
        if (effects != 0)
        {
          factor = ((f32) (*((s32 *) (geometry + 0x18)))) * (*((f32 *) (sprite + 0x18)));
          if ((*((u32 *) (((u8 *) effects) + 0x14))) != 0)
          {
            v0 = fn_80064164(geometry, *((s16 *) (renderFlags + 0xa)), factor);
          }
          if ((*((u32 *) (((u8 *) effects) + 0xc))) != 0)
          {
            v1 = fn_8006469C(geometry, *((s16 *) (renderFlags + 0xa)), factor);
          }
          if ((*((u32 *) (((u8 *) effects) + 0x10))) != 0)
          {
            v2 = fn_80064400(geometry, *((s16 *) (renderFlags + 0xa)), factor);
          }
          if ((*((u32 *) (((u8 *) effects) + 0x18))) != 0)
          {
            v3 = fn_80063EC8(geometry, *((s16 *) (renderFlags + 0xa)), factor);
          }
          if ((*((u32 *) (((u8 *) effects) + 0x1c))) != 0)
          {
            v4 = fn_80063C2C(geometry, *((s16 *) (renderFlags + 0xa)), factor);
          }
        }
        new_var = frame;
        PSMTXIdentity((f32 *) (new_var + 0x314));
        if (v0 != lbl_8036A838)
        {
          PSMTXTrans((f32 *) (new_var + 0x2e4), lbl_8036A83C, lbl_8036A83C, lbl_8036A838);
          PSMTXRotRad((f32 *) (new_var + 0x2b4), 'z', lbl_8036A818 * (-v0));
          PSMTXConcat((f32 *) (new_var + 0x2b4), (f32 *) ((0, new_var + 0x2e4)), (f32 *) (new_var + 0x2b4));
          PSMTXTrans((f32 *) (new_var + 0x2e4), lbl_8036A840, lbl_8036A840, lbl_8036A838);
          PSMTXConcat((f32 *) (new_var + 0x2e4), (f32 *) (new_var + 0x2b4), (f32 *) (new_var + 0x314));
        }
        if ((v3 != lbl_8036A844) || (v4 != lbl_8036A844))
        {
          PSMTXTrans((f32 *) (new_var + 0x2e4), lbl_8036A838, lbl_8036A848, lbl_8036A838);
          PSMTXScale((f32 *) (new_var + 0x284), v3, v4, lbl_8036A844);
          PSMTXConcat((f32 *) (new_var + 0x284), (f32 *) (new_var + 0x2e4), (f32 *) (new_var + 0x284));
          PSMTXTrans((f32 *) (new_var + 0x2e4), lbl_8036A838, lbl_8036A844, lbl_8036A838);
          PSMTXConcat((f32 *) (new_var + 0x2e4), (f32 *) (new_var + 0x284), (f32 *) (new_var + 0x284));
          PSMTXConcat((f32 *) (new_var + 0x284), (f32 *) (new_var + 0x314), (f32 *) (new_var + 0x314));
        }
        if ((v1 != lbl_8036A838) || (v2 != lbl_8036A838))
        {
          PSMTXTrans((f32 *) (new_var + 0x2e4), v1, -v2, lbl_8036A838);
          PSMTXConcat((f32 *) (new_var + 0x2e4), (f32 *) (new_var + 0x314), (f32 *) (new_var + 0x314));
        }
        fn_80224E50((f32 *) (new_var + 0x314), 0x1e, new_var8);
      }
      halfWidth = (*((f32 *) (sprite + 0x1c))) * lbl_8036A840;
      halfHeight = (*((f32 *) (sprite + 0x20))) * lbl_8036A840;
      {
        f32 x = *((f32 *) (sprite + 0));
        f32 y = *((f32 *) (sprite + 4));
        z = *((f32 *) (sprite + 8));
        GXBegin(0x80, 0, 4);
        x0 = x - halfWidth;
        x1 = x + halfWidth;
        y0 = y - halfHeight;
        y1 = y + halfHeight;
      }
      *fifoFloat = x0;
      *fifoFloat = y0;
      *fifoFloat = z;
      {
        u8 a = sprite[0x28];
        u8 b = sprite[0x2b];
        u8 g = sprite[0x2a];
        u8 r = sprite[0x29];
        *fifoByte = r;
        *fifoByte = g;
        *fifoByte = b;
        *fifoByte = a;
      }
      *fifoFloat = (*fifoFloat = lbl_8036A838);
      *fifoFloat = x1;
      if ((!factor) && (!factor))
      {
      }
      *fifoFloat = y0;
      *fifoFloat = z;
      {
        u8 a = sprite[0x28 & 0xFFFFu];
        u8 b = sprite[0x2b];
        u8 g = sprite[0x2a];
        u8 r = sprite[0x29];
        *fifoByte = r;
        *fifoByte = g;
        *fifoByte = b;
        *fifoByte = a;
      }
      *fifoFloat = lbl_8036A844;
      *fifoFloat = lbl_8036A838;
      *fifoFloat = x1;
      *fifoFloat = y1;
      *fifoFloat = z;
      {
        u8 a;
        u8 b = sprite[0x2b];
        u8 g = sprite[0x2a];
        u8 r = sprite[0x29];
        *fifoByte = r;
        *fifoByte = g;
        *fifoByte = b;
        if (transform)
        {
        }
        *fifoByte = a;
      }
      *fifoFloat = (*fifoFloat = lbl_8036A844);
      *fifoFloat = x0;
      *fifoFloat = y1;
      *fifoFloat = z;
      {
        u8 a = sprite[0x28];
        u8 b = sprite[0x2b];
        u8 g = sprite[0x2a];
        u8 r = sprite[0x29];
        *fifoByte = r;
        *fifoByte = g;
        a = sprite[0x28];
        *fifoByte = b;
        *fifoByte = a;
      }
      *fifoFloat = lbl_8036A838;
      *fifoFloat = lbl_8036A844;
    }

  }
  else
    if (mode == 0x400)
  {
    camera = Camera_Get();
    fn_802031A8(((u8 *) camera) + 0xe0, ((u8 *) camera) + 0xd4, (f32 *) (new_var + 0x18));
    new_var9 = sprite;
    fn_802020F0((f32 *) (new_var + 0x4f4), (f32 *) (new_var + 0x524));
    fn_802029C4((f32 *) (new_var + 0x524), (f32 *) (new_var + 0x18), (f32 *) (new_var + 0x18));
    angle = lbl_8036A838;
    if ((*((f32 *) (new_var + 0x18))) != lbl_8036A838)
    {
      new_var2 = (f32 *) (new_var + 0x20);
      angle = (f32) fn_80237E90((*new_var2) / (*((f32 *) (new_var + 0x18))));
      if ((*((f32 *) (new_var + 0x18))) < lbl_8036A838)
      {
        angle = lbl_8036A84C - angle;
      }
      else
      {
        angle = (-angle) - lbl_8036A84C;
      }
    }
    PSMTXRotRad((f32 *) (new_var + 0x434), 'Y', angle);
    rendered = 0;
    while (rendered < (*((u16 *) (renderFlags + 0x1e))))
    {
      batchStart = new_var9;
      batch = 0;
      j = rendered;
      while ((j <= ((*((u16 *) (renderFlags + 0x1e))) - 1)) && (batch < 10))
      {
        if ((sprite[0x28] != 0) && ((*((f32 *) (sprite + 0x18))) != lbl_8036A838))
        {
          *((f32 *) (new_var + 0xc)) = *((f32 *) (sprite + 0));
          *((f32 *) (new_var + 0x10)) = *((f32 *) (sprite + 4));
          *((f32 *) (new_var + 0x14)) = *((f32 *) (sprite + 8));
          fn_802029C4((f32 *) (new_var + 0x434), (f32 *) (new_var + 0xc), (f32 *) (new_var + 0xc));
          PSMTXTrans((f32 *) (new_var + 0x254), *((f32 *) (new_var + 0xc)), *((f32 *) (new_var + 0x10)), *((f32 *) (new_var + 0x14)));
          PSMTXConcat((f32 *) (new_var + 0x4f4), (f32 *) (new_var + 0x254), (f32 *) (new_var + 0x224));
          PSMTXTrans((f32 *) (new_var + 0x254), *((f32 *) (new_var + 0x230)), *((f32 *) (new_var + 0x240)), *((f32 *) (new_var + 0x250)));
          PSMTXConcat((f32 *) (new_var + 0x254), (f32 *) (new_var + 0x4c4), (f32 *) (new_var + 0x224));
          PSMTXConcat((f32 *) Camera_GetViewMtx(), (f32 *) (new_var + 0x224), (f32 *) (new_var + 0x224));
          if ((*((f32 *) (sprite + 0x24))) != lbl_8036A838)
          {
            PSMTXRotRad((f32 *) (new_var + 0x254), 'z', lbl_8036A818 * (*((f32 *) (sprite + 0x24))));
            PSMTXConcat((f32 *) (new_var + 0x224), (f32 *) (new_var + 0x254), (f32 *) (new_var + 0x224));
          }
          GXLoadPosMtxImm((f32 *) (new_var + 0x224), lbl_802939F0[batch]);
          ++batch;
        }
        ++j;
        sprite += 0x2c;
      }

      sprite = batchStart;
      slot = 0;
      while (rendered < j)
      {
        if ((batchStart[0x28] != 0) && ((*((f32 *) (batchStart + 0x18))) != lbl_8036A838))
        {
          if (hasEffects)
          {
            v0 = *((f32 *) (effect + 0x18));
            v1 = *((f32 *) (effect + 8));
            v2 = *((f32 *) (effect + 0xc));
            v3 = *((f32 *) (effect + 0x10));
            v4 = *((f32 *) (effect + 0x14));
            effects = *((void **) geometry);
            if (effects != 0)
            {
              factor = ((f32) (*((s32 *) (geometry + 0x18)))) * (*((f32 *) (sprite + 0x18)));
              if ((*((u32 *) (((u8 *) effects) + 0x14))) != 0)
              {
                v0 = fn_80064164(geometry, *((s16 *) (renderFlags + 0xa)), factor);
              }
              if ((*((u32 *) (((u8 *) effects) + 0xc))) != 0)
              {
                v1 = fn_8006469C(geometry, *((s16 *) (renderFlags + 0xa)), factor);
              }
              if ((*((u32 *) (((u8 *) effects) + 0x10))) != 0)
              {
                v2 = fn_80064400(geometry, *((s16 *) (renderFlags + 0xa)), factor);
              }
              if ((*((u32 *) (((u8 *) effects) + 0x18))) != 0)
              {
                v3 = fn_80063EC8(geometry, *((s16 *) (renderFlags + 0xa)), factor);
              }
              if ((*((u32 *) (((u8 *) effects) + 0x1c))) != 0)
              {
                v4 = fn_80063C2C(geometry, *((s16 *) (renderFlags + 0xa)), factor);
              }
            }
            PSMTXIdentity((f32 *) (new_var + 0x1f4));
            if (v0 != lbl_8036A838)
            {
              PSMTXTrans((f32 *) (new_var + 0x1c4), lbl_8036A83C, lbl_8036A83C, lbl_8036A838);
              PSMTXRotRad((f32 *) (new_var + 0x194), 'z', lbl_8036A818 * (-v0));
              PSMTXConcat((f32 *) (new_var + 0x194), (f32 *) (new_var + 0x1c4), (f32 *) (new_var + 0x194));
              PSMTXTrans((f32 *) (new_var + 0x1c4), lbl_8036A840, lbl_8036A840, lbl_8036A838);
              PSMTXConcat((f32 *) (new_var + 0x1c4), (f32 *) (new_var + 0x194), (f32 *) (new_var + 0x1f4));
            }
            if ((v3 != lbl_8036A844) || (v4 != lbl_8036A844))
            {
              PSMTXTrans((f32 *) (new_var + 0x1c4), lbl_8036A838, lbl_8036A848, lbl_8036A838);
              PSMTXScale((f32 *) (new_var + 0x164), v3, v4, lbl_8036A844);
              PSMTXConcat((f32 *) (new_var + 0x164), (f32 *) (new_var + 0x1c4), (f32 *) (new_var + 0x164));
              PSMTXTrans((f32 *) (new_var + 0x1c4), lbl_8036A838, lbl_8036A844, lbl_8036A838);
              PSMTXConcat((f32 *) (new_var + 0x1c4), (f32 *) (new_var + 0x164), (f32 *) (new_var + 0x164));
              PSMTXConcat((f32 *) (new_var + 0x164), (f32 *) (new_var + 0x1f4), (f32 *) (new_var + 0x1f4));
            }
            if ((v1 != lbl_8036A838) || (v2 != lbl_8036A838))
            {
              PSMTXTrans((f32 *) (new_var + 0x1c4), v1, -v2, lbl_8036A838);
              PSMTXConcat((f32 *) (new_var + 0x1c4), (f32 *) (new_var + 0x1f4), (f32 *) (new_var + 0x1f4));
            }
            fn_80224E50((f32 *) (new_var + 0x1f4), 0x1e, new_var8);
          }
          GXSetCurrentMtx(lbl_802939F0[slot]);
          ++slot;
          halfWidth = (*((f32 *) (sprite + 0x1c))) * lbl_8036A840;
          halfHeight = (*((f32 *) (sprite + 0x20))) * lbl_8036A840;
          GXBegin(0x80, 0, 4);
          x0 = lbl_8036A838 - halfWidth;
          x1 = lbl_8036A838 + halfWidth;
          y0 = lbl_8036A838 - halfHeight;
          y1 = lbl_8036A838 + halfHeight;
          z = lbl_8036A838;
          *fifoFloat = x0;
          *fifoFloat = y0;
          *fifoFloat = z;
          {
            u8 a = batchStart[0x28];
            u8 b = sprite[0x2b];
            u8 g = sprite[0x2a];
            u8 r = sprite[0x29];
            *fifoByte = r;
            *fifoByte = g;
            *fifoByte = b;
            *fifoByte = a;
          }
          *fifoFloat = (*fifoFloat = lbl_8036A838);
          *fifoFloat = x1;
          *fifoFloat = y0;
          *fifoFloat = z;
          {
            u8 a = sprite[0x28];
            u8 b = sprite[0x2b];
            u8 g = sprite[0x2a];
            u8 r = sprite[0x29];
            *fifoByte = r;
            *fifoByte = g;
            *fifoByte = b;
            *fifoByte = a;
          }
          *fifoFloat = lbl_8036A844;
          *fifoFloat = lbl_8036A838;
          *fifoFloat = x1;
          *fifoFloat = y1;
          *fifoFloat = z;
          {
            u8 a = batchStart[0x28];
            u8 b = batchStart[0x2b];
            u8 g = batchStart[0x2a];
            u8 r = batchStart[0x29];
            *fifoByte = r;
            *fifoByte = g;
            *fifoByte = b;
            *fifoByte = a;
          }
          *fifoFloat = lbl_8036A844;
          *fifoFloat = lbl_8036A844;
          *fifoFloat = x0;
          *fifoFloat = y1;
          *fifoFloat = z;
          {
            u8 a = batchStart[0x28];
            u8 b = batchStart[0x2b];
            u8 g = batchStart[0x2a];
            u8 r = batchStart[0x29];
            *fifoByte = r;
            *fifoByte = g;
            *fifoByte = b;
            *fifoByte = a;
          }
          *fifoFloat = lbl_8036A838;
          *fifoFloat = lbl_8036A844;
        }
        ++rendered;
        sprite += 0x2c;
      }

    }

  }
  else
  {
    rendered = 0;
    while (rendered < (*((u16 *) (renderFlags + 0x1e))))
    {
      batchStart = sprite;
      batch = 0;
      j = rendered;
      while ((j < (*((u16 *) (renderFlags + 0x1e)))) && (batch < 10))
      {
        if ((sprite[0x28] != 0) && ((*((f32 *) (sprite + 0x18))) != lbl_8036A838))
        {
          PSMTXTrans((f32 *) (new_var + 0x134), *((f32 *) (sprite + 0)), *((f32 *) (sprite + ((0, 4)))), *((f32 *) (sprite + 8)));
          PSMTXConcat((f32 *) (new_var + 0x4f4), (f32 *) (new_var + 0x134), (f32 *) (new_var + 0x104));
          PSMTXTrans((f32 *) (new_var + 0x134), *((f32 *) (new_var + 0x110)), *((f32 *) (new_var + 0x120)), *((f32 *) (new_var + 0x130)));
          PSMTXConcat((f32 *) (new_var + 0x134), (f32 *) (new_var + 0x4c4), (f32 *) (new_var + 0x104));
          PSMTXConcat((f32 *) Camera_GetViewMtx(), (f32 *) (new_var + 0x104), (f32 *) (new_var + 0x104));
          if ((*((f32 *) (sprite + 0x24))) != lbl_8036A838)
          {
            PSMTXRotRad((f32 *) (new_var + 0x134), 'z', lbl_8036A818 * (*((f32 *) (sprite + 0x24))));
            PSMTXConcat((f32 *) (new_var + 0x104), (f32 *) (new_var + 0x134), (f32 *) (new_var + 0x104));
          }
          GXLoadPosMtxImm((f32 *) (new_var + 0x104), lbl_802939F0[batch]);
          ++batch;
        }
        ++j;
        sprite += 0x2c;
      }

      sprite = batchStart;
      slot = 0;
      while (rendered < j)
      {
        if ((sprite[0x28] != 0) && ((*((f32 *) (sprite + 0x18))) != lbl_8036A838))
        {
          GXSetCurrentMtx(lbl_802939F0[slot]);
          ++slot;
          if (hasEffects)
          {
            v0 = *((f32 *) (effect + 0x18));
            v1 = *((f32 *) (effect + 8));
            v2 = *((f32 *) (effect + 0xc));
            v3 = *((f32 *) (effect + 0x10));
            v4 = *((f32 *) (effect + 0x14));
            effects = *((void **) geometry);
            if (effects != 0)
            {
              factor = ((f32) (*((s32 *) (geometry + 0x18)))) * (*((f32 *) (sprite + 0x18)));
              if ((*((u32 *) (((u8 *) effects) + 0x14))) != 0)
              {
                v0 = fn_80064164(geometry, new_var7, factor);
              }
              if ((*((u32 *) (((u8 *) effects) + 0xc))) != 0)
              {
                v1 = fn_8006469C(geometry, *((s16 *) (renderFlags + 0xa)), factor);
              }
              if ((*((u32 *) (((u8 *) effects) + 0x10))) != 0)
              {
                v2 = fn_80064400(geometry, *((s16 *) (renderFlags + 0xa)), factor);
              }
              if ((*((u32 *) (((u8 *) effects) - -0x18))) != 0)
              {
                v3 = fn_80063EC8(geometry, *((s16 *) (renderFlags + 0xa)), factor);
              }
              if ((*((u32 *) (((u8 *) effects) + 0x1c))) != 0)
              {
                v4 = fn_80063C2C(geometry, *((s16 *) (renderFlags + 0xa)), factor);
              }
            }
            PSMTXIdentity((f32 *) (new_var + 0xd4));
            if (v0 != lbl_8036A838)
            {
              PSMTXTrans((f32 *) (new_var + 0xa4), lbl_8036A83C, lbl_8036A83C, lbl_8036A838);
              PSMTXRotRad((f32 *) (new_var + 0x74), 'z', lbl_8036A818 * (-v0));
              PSMTXConcat((f32 *) (new_var + 0x74), (f32 *) (new_var + 0xa4), (f32 *) (new_var + 0x74));
              PSMTXTrans((f32 *) (new_var + 0xa4), lbl_8036A840, lbl_8036A840, lbl_8036A838);
              PSMTXConcat((f32 *) (new_var + 0xa4), (f32 *) (new_var + 0x74), (f32 *) (new_var + 0xd4));
            }
            if ((v3 != lbl_8036A844) || (v4 != lbl_8036A844))
            {
              PSMTXTrans((f32 *) (new_var + 0xa4), lbl_8036A838, lbl_8036A848, lbl_8036A838);
              PSMTXScale((f32 *) (new_var + 0x44), v3, v4, lbl_8036A844);
              PSMTXConcat((f32 *) (new_var + 0x44), (f32 *) (new_var + 0xa4), (f32 *) (new_var + 0x44));
              PSMTXTrans((f32 *) (new_var + 0xa4), lbl_8036A838, lbl_8036A844, lbl_8036A838);
              PSMTXConcat((f32 *) (new_var + 0xa4), (f32 *) (new_var + 0x44), (f32 *) (new_var + 0x44));
              PSMTXConcat((f32 *) (new_var + 0x44), (f32 *) (new_var + 0xd4), (f32 *) (new_var + 0xd4));
            }
            if ((v1 != lbl_8036A838) || (v2 != lbl_8036A838))
            {
              PSMTXTrans((f32 *) (new_var + 0xa4), v1, -v2, lbl_8036A838);
              PSMTXConcat((f32 *) (new_var + 0xa4), (f32 *) (new_var + 0xd4), (f32 *) (new_var + 0xd4));
            }
            fn_80224E50((f32 *) (new_var + 0xd4), 0x1e, 1);
          }
          halfWidth = (*((f32 *) (sprite + 0x1c))) * lbl_8036A840;
          halfHeight = *((f32 *) (sprite + 0x20));
          halfHeight = halfHeight * lbl_8036A840;
          GXBegin(0x80, 0, 4);
          x0 = lbl_8036A838 - halfWidth;
          x1 = lbl_8036A838 + halfWidth;
          y0 = lbl_8036A838 - halfHeight;
          y1 = lbl_8036A838 + halfHeight;
          z = lbl_8036A838;
          *fifoFloat = x0;
          *fifoFloat = y0;
          *fifoFloat = z;
          new_var3 = sprite[0x2a];
          {
            u8 a = sprite[0x28];
            u8 b = sprite[0x2b];
            u8 g = new_var3;
            u8 r = sprite[0x29];
            *fifoByte = r;
            *fifoByte = g;
            *fifoByte = b;
            *fifoByte = a;
          }
          *fifoFloat = lbl_8036A838;
          *fifoFloat = lbl_8036A838;
          *fifoFloat = x1;
          *fifoFloat = y0;
          *fifoFloat = z;
          {
            u8 a = sprite[0x28];
            u8 b = sprite[0x2b];
            u8 g = sprite[0x2a];
            u8 r = sprite[0x29];
            *fifoByte = r;
            *fifoByte = g;
            *fifoByte = b;
            *fifoByte = a;
          }
          *fifoFloat = lbl_8036A844;
          *fifoFloat = lbl_8036A838;
          *fifoFloat = x1;
          *fifoFloat = y1;
          *fifoFloat = z;
          {
            u8 a = sprite[0x28];
            u8 b = sprite[0x2b];
            u8 g = sprite[0x2a];
            u8 r = sprite[0x29];
            *fifoByte = r;
            *fifoByte = g;
            *fifoByte = b;
            *fifoByte = a;
          }
          *fifoFloat = (*fifoFloat = lbl_8036A844);
          *fifoFloat = x0;
          *fifoFloat = y1;
          *fifoFloat = z;
          {
            u8 a = sprite[0x28];
            u8 b = sprite[0x2b];
            u8 g = sprite[0x2a];
            u8 r = sprite[0x29];
            *fifoByte = r;
            *fifoByte = g;
            *fifoByte = b;
            *fifoByte = a;
          }
          *fifoFloat = lbl_8036A838;
          *fifoFloat = lbl_8036A844;
        }
        ++rendered;
        sprite += 0x2c;
      }

    }

  }
}

#pragma push
#pragma optimization_level 4
#pragma opt_lifetimes off
#pragma opt_propagation on
#pragma global_optimizer off
void fn_801502EC(void *arg0, void *arg1, void *arg2, void *arg3) {
    void fn_8022100C(s32);
    void GXClearVtxDesc(void);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetVtxDesc(s32, s32);
    void Ui_LoadAtlasTex(void *, void *, u16);
    void fn_80222C50(void *, s32);
    void GXSetNumChans(s32);
    void GXSetNumTevStages(s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void fn_80220FC4(s32, s32, s32);
    void GXBegin(s32, s32, s32);
    void fn_80220F84(s32, s32);
    extern f32 lbl_8036A820;
    extern f32 lbl_8036A838;
    u8 sp8[0x20];
    s32 ctr;
    void *var_r30;
    void *var_r29;
    void *var_r28;
    s32 ctr2;
    f32 f0, f1, f2, f3;
    volatile u8 *fifo;
    u8 r0b, r3b, r4b, r5b;

    var_r30 = arg0;
    var_r29 = arg2;
    var_r28 = arg3;
    fn_8022100C(0);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
    if (*(u8 *)((u8 *)var_r29 + 6) != 0) {
        GXSetVtxDesc(0xD, 1);
        GXSetVtxAttrFmt(0, 0xD, 1, 4, 0);
        Ui_LoadAtlasTex(var_r28, sp8, *(u16 *)(*(u8 **)((u8 *)var_r29 + 0x14) + 4));
        fn_80222C50(sp8, 0);
        GXSetNumChans(1);
        GXSetNumTevStages(1);
        fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
        GXSetTevOrder(0, 0, 0, 4);
        GXSetNumTexGens(0, 0);
        fn_80220FC4(0, 0, 1);
        ctr = 0;
        goto check1;
        do {
            r0b = *(u8 *)((u8 *)arg1 + 0x28);
            var_r28 = arg1;
            arg1 = (u8 *)arg1 + 0x2C;
            if (r0b) {
                fn_80220F84((s32)(lbl_8036A820 * *(f32 *)((u8 *)var_r28 + 0x1C)), 5);
                GXBegin(0xB8, 0, 1);
                fifo = (volatile u8 *)0xCC008000;
                f3 = *(f32 *)((u8 *)var_r28 + 8);
                f2 = *(f32 *)((u8 *)var_r28 + 4);
                f1 = *(f32 *)((u8 *)var_r28 + 0);
                f0 = lbl_8036A838;
                *(volatile f32 *)fifo = f1;
                *(volatile f32 *)fifo = f2;
                *(volatile f32 *)fifo = f3;
                r5b = *(u8 *)((u8 *)var_r28 + 0x28);
                r4b = *(u8 *)((u8 *)var_r28 + 0x2B);
                r3b = *(u8 *)((u8 *)var_r28 + 0x2A);
                r0b = *(u8 *)((u8 *)var_r28 + 0x29);
                *fifo = r0b;
                *fifo = r3b;
                *fifo = r4b;
                *fifo = r5b;
                *(volatile f32 *)fifo = f0;
                *(volatile f32 *)fifo = f0;
            }
            ctr++;
        check1:
            ;
        } while (ctr < (s32)*(u16 *)((u8 *)var_r30 + 0x1E));
    } else {
        GXSetNumChans(0);
        GXSetNumTevStages(1);
        GXSetTevOrder(0, 0xFF, 0xFF, 4);
        GXSetNumTexGens(0, 4);
        ctr2 = 0;
        goto check2;
        do {
            r0b = *(u8 *)((u8 *)arg1 + 0x28);
            var_r29 = arg1;
            arg1 = (u8 *)arg1 + 0x2C;
            if (r0b) {
                fn_80220F84((s32)(lbl_8036A820 * *(f32 *)((u8 *)var_r29 + 0x1C)), 5);
                GXBegin(0xB8, 0, 1);
                fifo = (volatile u8 *)0xCC008000;
                f2 = *(f32 *)((u8 *)var_r29 + 8);
                f1 = *(f32 *)((u8 *)var_r29 + 4);
                f0 = *(f32 *)((u8 *)var_r29 + 0);
                *(volatile f32 *)fifo = f0;
                *(volatile f32 *)fifo = f1;
                *(volatile f32 *)fifo = f2;
                r5b = *(u8 *)((u8 *)var_r29 + 0x28);
                r4b = *(u8 *)((u8 *)var_r29 + 0x2B);
                r3b = *(u8 *)((u8 *)var_r29 + 0x2A);
                r0b = *(u8 *)((u8 *)var_r29 + 0x29);
                *fifo = r0b;
                *fifo = r3b;
                *fifo = r4b;
                *fifo = r5b;
            }
            ctr2 += 1;
        check2:
            ;
        } while (ctr2 < (s32)*(u16 *)((u8 *)var_r30 + 0x1E));
    }
}
#pragma pop
#pragma global_optimizer on
void fn_801505A8(void *arg0,void *arg1) {
typedef struct {u32 x,y,z;} Triple;
typedef struct {Triple position; Triple rotation; f32 a,b,c,d; u8 e,f,g,h;} Entry;
Entry *b;
Entry *a;
s32 innerOffset, outerOffset;
u8 *src=*(u8 **)((u8 *)arg0+0x54);
u8 *dst=*(u8 **)((u8 *)arg1+0x54);
u8 *header;
u8 *group;
s32 i,j;
if(src==0 || dst==0) return;
header=*(u8 **)(src+0x34);
group=header+8;
for(i=0,outerOffset=0;i<*(u16 *)(header+6);outerOffset+=4,i++,group+=0x34) {
for(j=0,innerOffset=0;j<*(u16 *)(group+0x1e);j++,innerOffset+=0x2c) {
a=(Entry *)((u8 *)*(Entry **)(outerOffset+*(u32 *)(src+0x38))+innerOffset);
b=(Entry *)((u8 *)*(Entry **)(outerOffset+*(u32 *)(dst+0x38))+innerOffset);
b->position=a->position;
b->rotation=a->rotation;
b->a=a->a; b->b=a->b; b->c=a->c; b->d=a->d;
b->e=a->e; b->f=a->f; b->g=a->g; b->h=a->h;
}
}
}

s32 fn_801506AC(void *arg0)
{
  u32 fn_80060638(void *);
  f32 new_var;
  u32 fn_80060664(void *);
  f32 fn_80060468(void *);
  u8 GMaterial_EvalAlphaAnim(void **, s32, void *, f32);
  u8 GMaterial_EvalColorAnim(void *, s32, void *, f32);
  s32 fn_80064F24(void *, s32);
  void Game_Assert(const char *, s32, const char *);
  extern u8 lbl_80277320[];
  extern f32 lbl_8036A81C;
  float new_var3;
  extern f32 lbl_8036A838;
  extern f32 lbl_8036A844;
  extern f32 lbl_8036A848;
  u8 *self;
  u8 *work;
  u8 *model;
  u8 *header;
  u8 *group;
  u8 *track;
  u8 *channel;
  s16 new_var2;
  u8 *output;
  u8 *outputBase;
  u8 *values;
  u8 *curve;
  u8 *key;
  u8 *colorSource;
  u8 color[4];
  s32 groupIndex;
  s32 entryIndex;
  s32 trackIndex;
  s32 groupOffset;
  s32 outputOffset;
  s32 trackOffset;
  s32 vertexOffset;
  s32 channelType;
  s32 selection;
  s32 position;
  s32 keyIndex;
  s32 component;
  unsigned char count;
  s32 value;
  s32 alpha;
  s16 frame;
  s16 frameStart;
  s16 frameEnd;
  f32 time;
  f32 scale;
  f32 factor;
  f32 delta;
  f32 weight;
  f32 start;
  f32 end;
  f32 result;
  f32 first;
  f32 second;
  self = (u8 *) arg0;
  work = *((u8 **) (self + 0x54));
  model = (u8 *) fn_80060638(self);
  outputBase = (u8 *) fn_80060664(self);
  if (work == 0)
  {
    return 0;
  }
  *((f32 *) (work + 0x30)) = (time = fn_80060468(self));
  delta = time - (*((f32 *) (work + 0x30)));
  new_var2 = (s16) ((s32) time);
  frame = new_var2;
  if (delta < lbl_8036A838)
  {
    outputBase = (u8 *) fn_80060664(self);
    if (outputBase == 0)
    {
      return 0;
    }
    work = *((u8 **) (self + 0x54));
    if (0, work == 0)
    {
      return 0;
    }
    *((f32 *) (work + 0x30)) = (f32) (*((s32 *) (outputBase + 0x14)));
    header = *((u8 **) (work + 0x34));
    group = header + 8;
    groupOffset = 0;
    for (groupIndex = 0; groupIndex < (*((u16 *) (header + 6))); groupIndex++, group += 0x34, groupOffset += 4)
    {
      trackOffset = 0;
      outputOffset = 0;
      for (entryIndex = 0; entryIndex < (*((u16 *) (group + 0x1E))); entryIndex++, trackOffset += 0xC, outputOffset += 0x2C)
      {
        track = (*((u8 **) (group + 0x20))) + trackOffset;
        output = *((u8 **) ((*((u8 **) (work + 0x38))) + groupOffset));
        output += outputOffset;
        scale = lbl_8036A81C;
        *((f32 *) (output + 0x00)) = ((f32) (*((s16 *) (track + 6)))) * scale;
        *((f32 *) (output + 0x04)) = ((f32) (*((s16 *) (track + 8)))) * scale;
        *((f32 *) (output + 0x08)) = ((f32) (*((s16 *) (track + 10)))) * scale;
        *((f32 *) (output + 0x0C)) = lbl_8036A838;
        *((f32 *) (output + 0x10)) = lbl_8036A838;
        *((f32 *) (output + 0x14)) = lbl_8036A838;
        *((f32 *) (output + 0x18)) = lbl_8036A848;
        *((f32 *) (output + 0x1C)) = lbl_8036A844;
        *((f32 *) (output + 0x20)) = lbl_8036A844;
        output[0x28] = 0;
      }

    }

    return 0;
  }
  header = *((u8 **) (work + 0x34));
  group = header + 8;
  groupOffset = 0;
  for (groupIndex = 0; ((0, groupIndex)) < (*((u16 *) (header + 6))); groupIndex++, groupOffset += 4, group += 0x34)
  {
    colorSource = (u8 *) model;
    colorSource = *((u8 **) (colorSource + 0x34));
    output = colorSource + (((s32) (*((s16 *) (group + 0xA)))) * 0x20);
    color[0] = output[8];
    color[1] = output[9];
    color[2] = output[10];
    color[3] = output[11];
    GMaterial_EvalAlphaAnim((void **) outputBase, *((s16 *) (group + 0xA)), color, time);
    GMaterial_EvalColorAnim(outputBase, *((s16 *) (group + 0xA)), color, time);
    for (component = 0; component < 3; component++)
    {
      if (self[8 + component] < 0x80)
      {
        color[component] = (color[component] * self[8 + component]) >> 7;
      }
    }

    alpha = color[3] * self[0xB];
    color[3] = alpha / 128;
    channelType = (*((u16 *) (group + 6))) & 7;
    switch (channelType)
    {
      case 1:
        selection = *((s16 *) (group + 0xE));
        factor = lbl_8036A81C * selection;
        break;

      case 2:
        selection = *((s16 *) (group + 0x12));
        factor = lbl_8036A81C * selection;
        break;

      case 3:
        selection = *((s16 *) (group + 0x16));
        factor = lbl_8036A81C * selection;
        break;

      default:
        factor = lbl_8036A844;
        break;

    }

    switch (channelType)
    {
      case 1:
        selection = *((s16 *) (group + 0xE));
        weight = lbl_8036A81C * selection;
        break;

      case 2:
        selection = *((s16 *) (group + 0x12));
        weight = lbl_8036A81C * selection;
        break;

      case 3:
        new_var = lbl_8036A81C;
        selection = *((s16 *) (group + 0x18));
        entryIndex += 0;
        weight = new_var * selection;
        break;

      default:
        weight = lbl_8036A844;
        break;

    }

    scale = new_var * ((f32) (*((s16 *) (group + 0x1A))));
    track = *((u8 **) (group + 0x24));
    trackOffset = 0;
    outputOffset = 0;
    for (entryIndex = 0; entryIndex < (*((u16 *) (group + 0x1E))); entryIndex++, trackOffset += 8, outputOffset += 0x2C)
    {
      u8 *record;
      if ((*record) != entryIndex)
      {
        record = track + trackOffset;
        Game_Assert((const char *) (lbl_80277320 + 0x27), 0x145, (const char *) (lbl_80277320 + 0x35));
      }
      output = *((u8 **) (work + 0x38));
      output = *((u8 **) (output + groupOffset));
      output += outputOffset;
      values = *((u8 **) (group + 0x20));
      new_var2++;
      new_var2--;
      values += entryIndex * 0xC;
      frameStart = *((s16 *) (values + 2));
      frameEnd = *((s16 *) (values + 4));
      if ((time < ((f32) frameStart)) || (time > ((f32) frameEnd)))
      {
        *((f32 *) (output + 0x18)) = lbl_8036A838;
        output[0x28] = 0;
        *((f32 *) (output + 0)) = (f32) (*((s16 *) (values + 6)));
        *((f32 *) (output + 4)) = (f32) (*((s16 *) (8 + values)));
        *((f32 *) (output + 8)) = (f32) (*((s16 *) (values + 10)));
        continue;
      }
      first = (f32) frameStart;
      second = (f32) frameEnd;
      result = (time - first) / (second - first);
      *((f32 *) (output + 0x18)) = result;
      new_var3 = (lbl_8036A844 - result) * ((f32) color[3]);
      *((f32 *) (output + 0x1C)) = factor;
      *((f32 *) (output + 0x20)) = weight;
      output[0x28] = (u8) ((s32) new_var3);
      output[0x29] = color[0];
      output[0x2A] = color[1];
      output[0x2B] = color[2];
      *((f32 *) (output + 0x0C)) = lbl_8036A838;
      *((f32 *) (output + 0x10)) = lbl_8036A838;
      *((f32 *) (output + 0x14)) = lbl_8036A838;
      *((f32 *) (output + 0x24)) = scale;
      curve = *((u8 **) (group + 0x28));
      curve += (*((u16 *) (record + 4))) * 0xC;
      for (trackIndex = 0; trackIndex < (*((u16 *) (record + 6))); trackIndex++, curve += 0xC)
      {
        u8 *keys;
        channelType = *((u16 *) (curve + 0));
        key = *((u8 **) (group + 0x2C));
        key += (*((u32 *) (curve + 8))) * 4;
        keys = key;
        count = *((u16 *) (curve + 6));
        if (count == 0)
        {
          continue;
        }
        start = (f32) (*((s16 *) (keys + 2)));
        end = (f32) (*((s16 *) ((keys + ((count - 1) * 4)) + 2)));
        if (!(frame >= ((s16) end)))
        {
          if (frame < ((s16) start))
          {
            result = (f32) (*((s16 *) (keys + 0)));
          }
          else
          {
            keyIndex = fn_80064F24(keys, frame);
            position = keyIndex * 4;
            key = keys + position;
            first = (f32) (*((s16 *) (key + 2)));
            if (result)
            {
            }
            second = (f32) (*((s16 *) (key + 6)));
            value = frame;
            result = (f32) ((long) (*(key + 0)));
            if (second != first)
            {
            }
          }
        }
        else
        {
          result = (f32) (*((s16 *) ((keys + ((count - 1) * 4)) + 0)));
        }
        switch (channelType)
        {
          case 0:
            *((f32 *) (output + 0x0C)) = result;
            break;
            result += (((f32) (*((s16 *) (key + 4)))) - result) * ((value - first) / (second - first));

          case 1:
            *((f32 *) (output + 0x10)) = result;
            break;

          case 2:
            *((f32 *) (output + 0x14)) = result;
            break;

          case 3:
            *((f32 *) (output + 0x1C)) = result;
            *((f32 *) (0x20 + output)) = result;
            break;

          case 4:
            *((f32 *) (output + 0x1C)) = result;
            break;

          case 5:
            *((f32 *) (output + 0x20)) = result;
            break;

          case 6:
            output[0x28] = (u8) ((s32) (result * color[3]));
            break;

          case 7:
            output[0x29] = (u8) ((s32) (result * color[0]));
            break;

          case 8:
            output[0x2A] = (u8) ((s32) (result * color[1]));
            break;

          case 9:
            output[0x2B] = (u8) ((s32) (result * color[2]));
            break;

          case 10:
            *((f32 *) (output + 0x24)) = result;
            break;

        }

      }

      *((f32 *) (output + 0)) += (*((f32 *) (output + 0x0C))) * delta;
      *((f32 *) (output + 4)) += (*((f32 *) (output + 0x10))) * delta;
      *((f32 *) (output + 0x24)) = scale;
      *((f32 *) (output + 8)) += (*((f32 *) (output + 0x14))) * delta;
    }

  }

  return 0;
}

#pragma use_lmw_stmw on
void fn_80150F38(void *arg0) {
    void fn_800C4588(void *);
    long i;
    register int off;
    void *self;
    void *work;
    u32 z1;
    register void *z0;
    void *meta;

    self = arg0;
    work = *(void **)((u8 *)arg0 + 0x54);
    if (work != NULL) {
        meta = *(void **)((u8 *)work + 0x34);
        if (*(void **)((u8 *)work + 0x38) != NULL) {
            off = 0;
            i = 0;
            z0 = (void *)off;
            z1 = (u32)off;
            while (i < (s32)*(u16 *)((u8 *)meta + 6)) {
                fn_800C4588(*(void **)((u8 *)*(void **)((u8 *)work + 0x38) + off));
                i += 1;
                *(void **)((u8 *)*(void **)((u8 *)work + 0x38) + off) = z0;
                *(void **)((u8 *)*(void **)((u8 *)work + 0x38) + off) = (void *)z1;
                off += 4;
            }
            fn_800C4588(*(void **)((u8 *)work + 0x38));
            *(void **)((u8 *)work + 0x38) = 0;
            *(void **)((u8 *)work + 0x38) = 0;
        }
        fn_800C4588(*(void **)((u8 *)self + 0x54));
        *(void **)((u8 *)self + 0x54) = 0;
        *(void **)((u8 *)self + 0x54) = 0;
        *(void **)((u8 *)self + 0x54) = 0;
    }
}
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_strength_reduction off
void fn_80150FEC(void *arg0) {
    void *fn_80060664(void *);
    void *fn_800C4638(s32, u8 *, s32);
    void PSMTXIdentity(void *);
    extern f64 lbl_8036A828;
    extern u8 lbl_80277320[];
    extern f32 lbl_8036A81C;
    extern f32 lbl_8036A838;
    extern f32 lbl_8036A848;
    extern f32 lbl_8036A844;

    register void *base;
    void *inner;
    void *zero;
    s32 i;
    u8 *entry;
    register void *obj;
    s32 off;
    u8 *tag;
    f32 f838;
    void *block;
    u8 *src;
    unsigned long off2;
    s32 j;
    s32 off3;
    f32 f844;
    u8 *out;
    f32 scale;
    void *hdr;
    f32 f848;
    u16 count;

    base = fn_80060664(arg0);
    if (base == NULL) return;
    inner = *(void **)base;
    if (inner == NULL) return;
    hdr = *(void **)((u8 *)inner + 0x20);
    if (hdr == NULL) return;
    if (*(u32 *)hdr != 0x12345678U) return;
    if ((*(u16 *)((u8 *)hdr + 4) & 1) == 0) {
        entry = (u8 *)hdr + 8;
        for (i = 0; i < (s32)*(u16 *)((u8 *)hdr + 6); i++, entry += 0x34) {
            if (*(void **)entry != NULL) *(void **)entry = (u8 *)*(void **)entry + (u32)base;
            if (*(void **)(entry + 0x20) != NULL) *(void **)(entry + 0x20) = (u8 *)*(void **)(entry + 0x20) + (u32)base;
            if (*(void **)(entry + 0x24) != NULL) *(void **)(entry + 0x24) = (u8 *)*(void **)(entry + 0x24) + (u32)base;
            if (*(void **)(entry + 0x28) != NULL) *(void **)(entry + 0x28) = (u8 *)*(void **)(entry + 0x28) + (u32)base;
            if (*(void **)(entry + 0x2C) != NULL) *(void **)(entry + 0x2C) = (u8 *)*(void **)(entry + 0x2C) + (u32)base;
        }
        *(u16 *)((u8 *)hdr + 4) = *(u16 *)((u8 *)hdr + 4) | 1;
    }
    if ((u16)*(u16 *)((u8 *)hdr + 6) == 0) return;
    *(void **)((u8 *)arg0 + 0x54) = fn_800C4638(0x40, lbl_80277320 + 0x5E, 0);
    entry = (u8 *)hdr + 8;
    obj = *(void **)((u8 *)arg0 + 0x54);
    *(void **)((u8 *)obj + 0x38) = fn_800C4638((s32)*(u16 *)((u8 *)hdr + 6) * 4, lbl_80277320 + 0x5E, 0);
    off = 0;
    zero = (void *)off;
    tag = lbl_80277320;
    for (i = 0; i < (s32)*(u16 *)((u8 *)hdr + 6); i++, entry += 0x34) {
        count = *(u16 *)(entry + 0x1E);
        if (!count) *(void **)((u8 *)*(void **)((u8 *)obj + 0x38) + off) = zero;
        else *(void **)((u8 *)*(void **)((u8 *)obj + 0x38) + off) = fn_800C4638((s32)count * 0x2C, tag + 0x5E, 0);
        off += 4;
    }
    *(void **)((u8 *)obj + 0x34) = hdr;
    PSMTXIdentity(obj);
    base = fn_80060664(arg0);
    if (base == NULL) return;
    block = *(void **)((u8 *)arg0 + 0x54);
    if (block == NULL) return;
    i = 0;
    off = i;
    scale = lbl_8036A81C;
    f838 = lbl_8036A838;
    f848 = lbl_8036A848;
    f844 = lbl_8036A844;
    *(f32 *)((u8 *)block + 0x30) = (f32)*(s32 *)((u8 *)base + 0x14);
    hdr = *(void **)((u8 *)block + 0x34);
    entry = (u8 *)hdr + 8;
    while (i < (s32)*(u16 *)((u8 *)hdr + 6)) {
        j = 0;
        off2 = j;
        off3 = j;
        while (j < (s32)*(u16 *)(entry + 0x1E)) {
            src = (u8 *)*(void **)(entry + 0x20) + off3;
            out = (u8 *)(*(void **)((u8 *)*(void **)((u8 *)block + 0x38) + off)) + off2;
            off3 += 0xC;
            j += 1;
            off2 += 0x2C;
            *(f32 *)(out + 0) = scale * (f32)*(s16 *)(src + 6);
            *(f32 *)(out + 4) = scale * (f32)*(s16 *)(src + 8);
            *(f32 *)(out + 8) = scale * (f32)*(s16 *)(src + 0xA);
            *(f32 *)(out + 0xC) = f838;
            *(f32 *)(out + 0x10) = f838;
            *(f32 *)(out + 0x14) = f838;
            *(f32 *)(out + 0x18) = f848;
            *(f32 *)(out + 0x1C) = f844;
            *(f32 *)(out + 0x20) = f844;
            out[0x28] = 0;
        }
        off += 4;
        ++i;
        entry += 0x34;
    }
}
#pragma pop
s32 fn_801512D8(void) {
    M2C_UNK fn_800D758C(s32);
    extern s32 lbl_80367BA0;
    fn_800D758C(lbl_80367BA0);
    return 0;
}

int fn_80151300(void) {
    extern u8 *lbl_80367BA0;
    extern void fn_800DC3B0(void *);
    extern void fn_800DA608(void);

    fn_800DC3B0(*(void **)(lbl_80367BA0 + 0x424));
    fn_800DA608();

    return 0;
}

#pragma cplusplus on
extern "C" void fn_80151330(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void fn_800D7254(void);
    struct Obj {
        u8 pad[0x40];
        virtual void v0(s32, s32, s32) = 0;
        virtual void v1(s32, s32, s32) = 0;
        virtual void v2(s32, s32, s32) = 0;
        virtual void v3(s32, s32, s32) = 0;
        virtual void v4(s32, s32, s32) = 0;
        virtual void v5(s32, s32, s32) = 0;
        virtual void v6(s32, s32, s32) = 0;
        virtual void v7(s32, s32, s32) = 0;
        virtual void v8(s32, s32, s32) = 0;
        virtual void v9(s32, s32, s32) = 0;
        virtual void v10(s32, s32, s32) = 0;
        virtual void v11(s32, s32, s32) = 0;
        virtual void v12(s32, s32, s32) = 0;
        virtual void v13(s32, s32, s32) = 0;
        virtual void v14(s32, s32, s32) = 0;
        virtual void v15(s32, s32, s32) = 0;
        virtual void v16(s32, s32, s32) = 0;
        virtual void v17(s32, s32, s32) = 0;
        virtual void v18(s32, s32, s32) = 0;
        virtual void v19(s32, s32, s32) = 0;
        virtual void v20(s32, s32, s32) = 0;
    };
    fn_800D7254();
    (*(Obj **)((u8 *)arg0 + 0x424))->v20(arg1, arg2, arg3);
}
#pragma cplusplus reset

void fn_801513A0(void *arg0) {
    M2C_UNK String_Destroy(M2C_UNK *, M2C_UNK);
    M2C_UNK String_Copy(M2C_UNK *);
    M2C_UNK fn_800DC518(s32, M2C_UNK *, M2C_UNK);
    M2C_UNK sp8;

    String_Copy(&sp8);
    fn_800DC518(M2C_FIELD(arg0, s32 *, 0x424), &sp8, 0);
    String_Destroy(&sp8, -1);
}

extern u16 lbl_80367BA0;
void *fn_801513EC(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct { u32 size; u32 cap; char *data; } String;
    void String_Init(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void fn_800D764C(void *, s32, s32, s32, void *, void *);
    void String_Destroy(void *, s32);
    void *fn_800D75FC(void *, void *);
    void fn_800E3F54(void *);
    extern char lbl_80277380[];
    extern u8 lbl_80293A78[];
    extern void fn_80151300(void);
    extern void fn_801512D8(void);
    String pathBase;
    String dbxPath;
    String winName;
    String ctrl0;
    String okBtn;
    String cancelBtn;
    void *sp18;
    void *sp14;
    void *sp10;
    void *spC;
    void *sp8;
    void *temp;
    void *self;

    self = arg0;
    String_Init(&pathBase, lbl_80277380, &sp18);
    String_ConcatCStr(&dbxPath, &pathBase, lbl_80277380 + 7);
    String_Init(&winName, lbl_80277380 + 0x15, &sp14);
    fn_800D764C(self, arg1, arg2, arg3, &dbxPath, &winName);
    String_Destroy(&winName, -1);
    String_Destroy(&dbxPath, -1);
    String_Destroy(&pathBase, -1);
    *(void **)((u8 *)self + 0xC) = lbl_80293A78;
    String_Init(&ctrl0, lbl_80277380 + 0x1F, &sp10);
    *(void **)((u8 *)self + 0x424) = fn_800D75FC(self, &ctrl0);
    String_Destroy(&ctrl0, -1);
    String_Init(&okBtn, lbl_80277380 + 0x2A, &spC);
    temp = fn_800D75FC(self, &okBtn);
    *(void **)((u8 *)self + 0x428) = temp;
    *(void **)((u8 *)self + 0x418) = temp;
    String_Destroy(&okBtn, -1);
    String_Init(&cancelBtn, lbl_80277380 + 0x30, &sp8);
    temp = fn_800D75FC(self, &cancelBtn);
    *(void **)((u8 *)self + 0x42C) = temp;
    *(void **)((u8 *)self + 0x41C) = temp;
    String_Destroy(&cancelBtn, -1);
    temp = *(void **)((u8 *)self + 0x428);
    *(void **)((u8 *)temp + 0xA4) = (void *)fn_80151300;
    temp = *(void **)((u8 *)self + 0x42C);
    *(void **)((u8 *)temp + 0xA4) = (void *)fn_801512D8;
    *(void **)((u8 *)self + 0x14) = *(void **)((u8 *)self + 0x428);
    *(void **)((u8 *)self + 0x414) = *(void **)((u8 *)self + 0x428);
    fn_800E3F54(*(void **)((u8 *)self + 0x414));
    return self;
}

void fn_801515AC(void) {
    extern s32 lbl_80367BA8;
    lbl_80367BA8 = 0;
}

#pragma cplusplus on
extern "C" s32 fn_801515B8(void *arg0) {
    struct Obj {
        u8 pad[0x10];
        virtual void v0(void **) = 0;
        virtual void v1(void **) = 0;
        virtual void v2(void **) = 0;
        virtual void v3(void **) = 0;
        virtual void v4(void **) = 0;
        virtual void v5(void **) = 0;
        virtual void v6(void **) = 0;
        virtual void v7(void **) = 0;
        virtual void v8(void **) = 0;
    };
    void **temp_r4;
    Obj *obj;

    temp_r4 = *(void ***)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x4c);
    obj = (Obj *)*temp_r4;
    obj->v8(temp_r4);
    return 0;
}
#pragma cplusplus reset
s32 fn_801515F4(void *arg0) {
    M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), void **, 0x4C), s8 *, 0xC4) = 1;
    return 0;
}

s32 fn_8015160C(void *arg0) {
    typedef struct { f32 x, y, z; } Vec3;
    s32 Pad_IsButton(void *, s32);
    s32 fn_8005F84C(void *, s32, s32);
    void Effect_SetPos(void *, f32, f32, f32);
    Vec3 copy;
    Vec3 vec;
    void *pad;
    void *obj;
    void *inner;
    void **vtable;
    f32 z;
    f32 y;
    f32 x;
    s32 result;
    f32 fr;
    f32 d;
    f32 pv;

    inner = *(void **)((u8 *)arg0 + 0x30);
    vec.z = 0.0f;
    obj = *(void **)((u8 *)inner + 0x4C);
    vec.y = 0.0f;
    vtable = *(void ***)((u8 *)obj + 0x40);
    pad = *(void **)((u8 *)inner + 0x5C);
    vec.x = 0.0f;
    ((void (*)(void *))vtable[8])(obj);

    if (pad != NULL) {
        if ((u8)Pad_IsButton(pad, 0x11) != 0) {
            x = *(f32 *)((u8 *)obj + 0x48);
            y = *(f32 *)((u8 *)obj + 0x4C);
            z = *(f32 *)((u8 *)obj + 0x50);
            *(f32 *)((u8 *)obj + 0x48) = *(f32 *)((u8 *)obj + 0xB4);
            *(f32 *)((u8 *)obj + 0x4C) = 0.0f;
            *(f32 *)((u8 *)obj + 0x50) = *(f32 *)((u8 *)obj + 0xBC);
            vec.x = x;
            *(f32 *)((u8 *)obj + 0xB4) = x;
            *(f32 *)((u8 *)obj + 0xB8) = y;
            vec.y = y;
            vec.z = z;
            *(f32 *)((u8 *)obj + 0xBC) = z;
        }
    }

    if (pad != NULL) {
        if ((u8)Pad_IsButton(pad, 0x12) != 0) {
            result = fn_8005F84C(pad, (s32)*(f32 *)((u8 *)pad + 0x58), 0x13);
            if (result > 0) {
                fr = result;
                pv = *(f32 *)((u8 *)pad + 0x58);
                d = fr - pv;
                vec.x = *(f32 *)((u8 *)obj + 0xB4);
                vec.y = 0.0f;
                vec.z = *(f32 *)((u8 *)obj + 0xBC);
                copy = vec;
                vtable = *(void ***)((u8 *)obj + 0x40);
                ((void (*)(void *, Vec3 *, s32))vtable[0x11])(obj, &copy, (s32)d);
            }
        }
    }

    Effect_SetPos(arg0,
        *(f32 *)((u8 *)obj + 0x48),
        *(f32 *)((u8 *)obj + 0x4C),
        *(f32 *)((u8 *)obj + 0x50));
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x18) = *(f32 *)((u8 *)obj + 0x6C);
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x20) = *(f32 *)((u8 *)obj + 0x54);
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x24) = *(f32 *)((u8 *)obj + 0x58);
    return 0;
}

u8 fn_801517C0(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0xC4);
}

void fn_801517C8(void *arg0) {
    void fn_800535B0();
    void *x = *(void **)((u8 *)arg0 + 0xB0);
    if (x != NULL) {
        fn_800535B0(x);
    }
}

void fn_801517F4(void *arg0) {
    extern f32 lbl_8036A860;
    void fn_802031E8(f32 *, f32 *);
    f64 fn_80203270(f32 *, f32 *);
    f64 fn_80238788(f64);
    f32 vec1[3];
    f32 vec2[3];
    f32 *p;
    f32 dx;

    p = vec1;
    dx = *(f32 *)((u8 *)arg0 + 0xB4) - *(f32 *)((u8 *)arg0 + 0x48);
    p[1] = 0.0f;
    p[2] = 0.0f;
    p[0] = dx;
    vec2[0] = dx;
    vec2[1] = *(f32 *)((u8 *)arg0 + 0xB8) - *(f32 *)((u8 *)arg0 + 0x4C);
    vec2[2] = *(f32 *)((u8 *)arg0 + 0xBC) - *(f32 *)((u8 *)arg0 + 0x50);
    fn_802031E8(p, p);
    fn_802031E8(vec2, vec2);
    *(f32 *)((u8 *)arg0 + 0x54) = lbl_8036A860 * (f32)fn_80238788(fn_80203270(vec1, vec2));
}

void fn_80151894(void *arg0) {
    void *temp_r3;
    void *temp_r3_2;

    temp_r3 = M2C_FIELD(arg0, void **, 0xB0);
    if (temp_r3 != NULL) {
        temp_r3_2 = M2C_FIELD(temp_r3, void **, 0x30);
        M2C_FIELD(temp_r3_2, s32 *, 8) = (s32) (M2C_FIELD(temp_r3_2, s32 *, 8) | 2);
    }
}

void fn_801518B4(void *arg0, void *arg1) {
    M2C_FIELD(arg0, f32 *, 0xB4) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0, f32 *, 0xB8) = (f32) M2C_FIELD(arg1, f32 *, 4);
    M2C_FIELD(arg0, f32 *, 0xBC) = (f32) M2C_FIELD(arg1, f32 *, 8);
}

s32 fn_801518D0(void *arg0, s32 arg1) {
    void *fn_800536FC(u16);
    s32 Pad_IsButton(void *, s32);

    *(void **)((u8 *)arg0 + 0xB0) = fn_800536FC((u16)*(u32 *)((u8 *)arg0 + 0xAC));
    if (*(void **)((u8 *)arg0 + 0xB0) != NULL) {
        if (*(void **)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x30) + 0x5C) != NULL) {
            return Pad_IsButton(*(void **)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x30) + 0x5C), arg1);
        }
        return 0;
    }
    return 0;
}

s32 fn_80151948(void *arg0, s32 arg1) {
    void *fn_800536FC(u16);
    s32 fn_8005F894(void *, s32);

    *(void **)((u8 *)arg0 + 0xB0) = fn_800536FC((u16)*(u32 *)((u8 *)arg0 + 0xAC));
    if (*(void **)((u8 *)arg0 + 0xB0) != NULL) {
        if (*(void **)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x30) + 0x5C) != NULL) {
            return fn_8005F894(*(void **)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x30) + 0x5C), arg1);
        }
        return -1;
    }
    return -1;
}

s32 fn_801519C0(void *arg0) {
    void *p = M2C_FIELD(arg0, void **, 0xB0);
    s32 result = 0;

    p = M2C_FIELD(p, void **, 0x30);
    p = M2C_FIELD(p, void **, 0x5C);
    if (p != NULL) {
        p = M2C_FIELD(p, void **, 0x44);
        if (p != NULL) {
            result = M2C_FIELD(p, s32 *, 0x18);
        }
    }
    return result;
}

void Camera_ApplyPadControls(void *arg0) {
    /* Apply pad buttons 9-B / 1E-21 to the camera object using gGame axis rates. */
    void *fn_800536FC(u16);
    s32 Pad_IsButton(void *, s32);
    void UiObj_SetCamerasTransitionDecay(void *, f32);
    void UiObj_SetCamerasTransition(void *, s32, s32, f32);
    extern void *gGame;
    void *camera;
    s32 pressed;
    void *pad;

    camera = *(void **)arg0;
    *(void **)((u8 *)arg0 + 0xB0) = fn_800536FC((u16)*(u32 *)((u8 *)arg0 + 0xAC));
    pad = *(void **)((u8 *)arg0 + 0xB0);
    if (pad != NULL) {
        pad = *(void **)((u8 *)*(void **)((u8 *)pad + 0x30) + 0x5C);
        if (pad != NULL) {
            pressed = Pad_IsButton(pad, 9);
        } else {
            pressed = 0;
        }
    } else {
        pressed = 0;
    }
    if ((u8)pressed != 0) {
        UiObj_SetCamerasTransition(camera, 0, 0x3C, *(f32 *)((u8 *)gGame + 0x98));
    }
    *(void **)((u8 *)arg0 + 0xB0) = fn_800536FC((u16)*(u32 *)((u8 *)arg0 + 0xAC));
    pad = *(void **)((u8 *)arg0 + 0xB0);
    if (pad != NULL) {
        pad = *(void **)((u8 *)*(void **)((u8 *)pad + 0x30) + 0x5C);
        if (pad != NULL) {
            pressed = Pad_IsButton(pad, 0xA);
        } else {
            pressed = 0;
        }
    } else {
        pressed = 0;
    }
    if ((u8)pressed != 0) {
        UiObj_SetCamerasTransition(camera, 0, 0x3C, *(f32 *)((u8 *)gGame + 0x9C));
    }
    *(void **)((u8 *)arg0 + 0xB0) = fn_800536FC((u16)*(u32 *)((u8 *)arg0 + 0xAC));
    pad = *(void **)((u8 *)arg0 + 0xB0);
    if (pad != NULL) {
        pad = *(void **)((u8 *)*(void **)((u8 *)pad + 0x30) + 0x5C);
        if (pad != NULL) {
            pressed = Pad_IsButton(pad, 0xB);
        } else {
            pressed = 0;
        }
    } else {
        pressed = 0;
    }
    if ((u8)pressed != 0) {
        UiObj_SetCamerasTransition(camera, 0, 0x3C, *(f32 *)((u8 *)gGame + 0xA0));
    }
    *(void **)((u8 *)arg0 + 0xB0) = fn_800536FC((u16)*(u32 *)((u8 *)arg0 + 0xAC));
    pad = *(void **)((u8 *)arg0 + 0xB0);
    if (pad != NULL) {
        pad = *(void **)((u8 *)*(void **)((u8 *)pad + 0x30) + 0x5C);
        if (pad != NULL) {
            pressed = Pad_IsButton(pad, 0x1E);
        } else {
            pressed = 0;
        }
    } else {
        pressed = 0;
    }
    if ((u8)pressed != 0) {
        UiObj_SetCamerasTransition(camera, 0, -1, *(f32 *)((u8 *)gGame + 0x98));
    }
    *(void **)((u8 *)arg0 + 0xB0) = fn_800536FC((u16)*(u32 *)((u8 *)arg0 + 0xAC));
    pad = *(void **)((u8 *)arg0 + 0xB0);
    if (pad != NULL) {
        pad = *(void **)((u8 *)*(void **)((u8 *)pad + 0x30) + 0x5C);
        if (pad != NULL) {
            pressed = Pad_IsButton(pad, 0x1F);
        } else {
            pressed = 0;
        }
    } else {
        pressed = 0;
    }
    if ((u8)pressed != 0) {
        UiObj_SetCamerasTransition(camera, 0, -1, *(f32 *)((u8 *)gGame + 0x9C));
    }
    *(void **)((u8 *)arg0 + 0xB0) = fn_800536FC((u16)*(u32 *)((u8 *)arg0 + 0xAC));
    pad = *(void **)((u8 *)arg0 + 0xB0);
    if (pad != NULL) {
        pad = *(void **)((u8 *)*(void **)((u8 *)pad + 0x30) + 0x5C);
        if (pad != NULL) {
            pressed = Pad_IsButton(pad, 0x20);
        } else {
            pressed = 0;
        }
    } else {
        pressed = 0;
    }
    if ((u8)pressed != 0) {
        UiObj_SetCamerasTransition(camera, 0, -1, *(f32 *)((u8 *)gGame + 0xA0));
    }
    *(void **)((u8 *)arg0 + 0xB0) = fn_800536FC((u16)*(u32 *)((u8 *)arg0 + 0xAC));
    pad = *(void **)((u8 *)arg0 + 0xB0);
    if (pad != NULL) {
        pad = *(void **)((u8 *)*(void **)((u8 *)pad + 0x30) + 0x5C);
        if (pad != NULL) {
            pressed = Pad_IsButton(pad, 0x21);
        } else {
            pressed = 0;
        }
    } else {
        pressed = 0;
    }
    if ((u8)pressed != 0) {
        UiObj_SetCamerasTransitionDecay(camera, *(f32 *)((u8 *)gGame + 0x98));
    }
    *(s32 *)((u8 *)arg0 + 0xC0) = *(s32 *)((u8 *)arg0 + 0xC0) + 1;
}

extern u16 lbl_8028DED0[];
void *fn_80151CE0(void *arg0, s16 arg1) {
    void fn_800DF724(void *, s32);
    void Heap_Free(void *);
    extern u8 lbl_80293A88[];

    if (arg0 != NULL) {
        M2C_FIELD(arg0, void **, 0x40) = lbl_80293A88;
        if (arg0 != NULL) {
            M2C_FIELD(arg0, void **, 0x40) = lbl_8028DED0;
            fn_800DF724(arg0, 0);
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma readonly_strings on
#pragma pool_strings on
typedef struct Vec {
    f32 x, y, z;
} Vec;
extern "C" M2C_UNK String_Init(M2C_UNK *, const char *, M2C_UNK *);
extern "C" M2C_UNK String_Destroy(M2C_UNK *, M2C_UNK);
extern "C" void fn_800DBE34(void *, s32, M2C_UNK *, s32, M2C_UNK *);
extern "C" char *String_CStr(void *);
extern "C" void *Effect_Create(char *, s32);
extern "C" void fn_80053658(void *, s32, void *);
extern "C" s32 fn_8015160C(void *);
extern "C" s32 fn_801515F4(void *);
extern "C" s32 fn_801515B8(void *);
extern "C" void *fn_80151D50(void *arg0, s32 arg1, s32 arg2, void *arg3, f32 *arg4, f32 *arg5) {
    extern u8 lbl_80293A88[];
    extern s32 lbl_80367BA8;
    struct Effect {
        u8 pad0[0x40];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void SetPos(f32, f32, f32) = 0;
        virtual void v8() = 0;
        virtual void SetRot(f32, f32, f32) = 0;
    };
    M2C_UNK name[3];
    M2C_UNK kind[3];
    M2C_UNK alloc1;
    M2C_UNK alloc2;
    void *task;
    s32 id;

    String_Init(name, "Effect", &alloc1);
    String_Init(kind, "effect", &alloc2);
    fn_800DBE34(arg0, arg1, name, arg2, kind);
    String_Destroy(kind, -1);
    String_Destroy(name, -1);
    M2C_FIELD(arg0, void **, 0x40) = lbl_80293A88;
    M2C_FIELD(arg0, f32 *, 0xBC) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0xB8) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0xB4) = 0.0f;
    M2C_FIELD(arg0, u8 *, 0xC4) = 0;
    task = Effect_Create(String_CStr(arg3), 4);
    if (task != NULL) {
        id = ++lbl_80367BA8;
        M2C_FIELD(arg0, s32 *, 0xAC) = id;
        M2C_FIELD(M2C_FIELD(task, void **, 0x30), void **, 0x40) = (void *)fn_8015160C;
        M2C_FIELD(M2C_FIELD(task, void **, 0x30), void **, 0x3C) = (void *)fn_801515F4;
        M2C_FIELD(M2C_FIELD(task, void **, 0x30), void **, 0x44) = (void *)fn_801515B8;
        fn_80053658(task, 0, arg0);
        M2C_FIELD(M2C_FIELD(task, void **, 0x30), s16 *, 0) = M2C_FIELD(arg0, s32 *, 0xAC);
    } else {
        M2C_FIELD(arg0, s32 *, 0xAC) = -1;
    }
    M2C_FIELD(arg0, void **, 0xB0) = task;
    M2C_FIELD(arg0, s32 *, 0xC0) = 0;
    ((Effect *)arg0)->SetPos(((Vec *)arg4)->x, ((Vec *)arg4)->y, ((Vec *)arg4)->z);
    ((Effect *)arg0)->SetRot(arg5[0], arg5[1], arg5[2]);
    return arg0;
}

#pragma cplusplus off
void fn_80151EDC(s16 x, s16 y, s32 texFlags) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    extern u8 gUiTexScratch[64];
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_803680A0;
    s16 h;
    s16 w;

    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, 0xAB);
    h = (s16)(lbl_803680A0.f6 - lbl_803680A0.f2);
    w = (s16)(lbl_803680A0.f4 - lbl_803680A0.f0);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(texFlags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_803680A0.f0, (f32)lbl_803680A0.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
}
#pragma cplusplus off
void fn_80152010(s16 arg0, s16 arg1, s16 arg2, u8 arg3, s32 arg4)
{
    void Ui_LoadAtlasTex(void *, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_EndPrim(void);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(void *);
    extern u8 gUiTexScratch[];
    extern void *gUiTexAtlas;
    extern s16 lbl_80368088[4], lbl_80368090[4], lbl_80368098[4];
    u8 color[4];
    u32 c2, c1, c0;
    s16 right, x2, x1, h2, h1, w1, left, w0, h0;
    s16 w2;
    s32 raw;
    s16 width;

    color[0] = 255;
    color[1] = 255;
    color[2] = 255;
    color[3] = arg3;
    width = arg2;
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0xa8);
    w0 = lbl_80368088[2] - lbl_80368088[0];
    h0 = lbl_80368088[3] - lbl_80368088[1];
    if (w0 && h0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg4 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(arg0, arg1, lbl_80368088[0], lbl_80368088[1], w0, h0);
        c1 = *(u32 *)color;
        Prim2D_SetColorPacked(&c1);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0xa9);
    left = lbl_80368088[2] - lbl_80368088[0];
    right = lbl_80368098[2] - lbl_80368098[0];
    w1 = width - left - right;
    h1 = lbl_80368090[3] - lbl_80368090[1];
    x1 = arg0 + left;
    if (w1 && h1) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg4 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect(x1, arg1, w1, h1);
        Prim2D_SetUvRect(lbl_80368090[0], lbl_80368090[1], (s16)(lbl_80368090[2] - lbl_80368090[0]), (s16)(lbl_80368090[3] - lbl_80368090[1]));
        c2 = *(u32 *)color;
        Prim2D_SetColorPacked(&c2);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0xaa);
    raw = lbl_80368098[2] - lbl_80368098[0];
    x2 = arg0 + (width - (s16)raw);
    w2 = raw;
    h2 = lbl_80368098[3] - lbl_80368098[1];
    if ((s16)w2 && h2) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg4 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(x2, arg1, lbl_80368098[0], lbl_80368098[1], (s16)w2, h2);
        c0 = *(u32 *)color;
        Prim2D_SetColorPacked(&c0);
        Prim2D_EndPrim();
    }
}
void fn_80152414(s16 arg0, s16 arg1, s32 arg2) {
void Ui_LoadAtlasTex(s32,void *,s32);
void Prim2D_SetTex(void *,u16);
void Prim2D_Begin(void);
void Prim2D_PrepareTex(void);
void Prim2D_AddPrim(s32);
void Prim2D_SetRectUv(f32,f32,f32,f32,f32,f32);
void Prim2D_EndPrim(void);
extern s32 gUiTexAtlas;
extern u8 gUiTexScratch[];
extern struct {s16 x,y,right,bottom;} lbl_80368078;
s16 h;
s16 w;
Ui_LoadAtlasTex(gUiTexAtlas,gUiTexScratch,0xa6);
h=(s16)(lbl_80368078.bottom-lbl_80368078.y);
w=(s16)(lbl_80368078.right-lbl_80368078.x);
if(w!=0 && h!=0) {
Prim2D_Begin();
Prim2D_SetTex(gUiTexScratch,(u16)(arg2|1));
Prim2D_PrepareTex();
Prim2D_AddPrim(1);
Prim2D_SetRectUv((f32)arg0,(f32)arg1,(f32)lbl_80368078.x,(f32)lbl_80368078.y,(f32)w,(f32)h);
Prim2D_EndPrim();
}
}

void fn_80152548(s16 arg0, s16 arg1, s32 arg2) {
void Ui_LoadAtlasTex(s32,void *,s32);
void Prim2D_SetTex(void *,u16);
void Prim2D_Begin(void);
void Prim2D_PrepareTex(void);
void Prim2D_AddPrim(s32);
void Prim2D_SetRectUv(f32,f32,f32,f32,f32,f32);
void Prim2D_EndPrim(void);
extern s32 gUiTexAtlas;
extern u8 gUiTexScratch[];
extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80368070;
s16 h;
s16 w;
Ui_LoadAtlasTex(gUiTexAtlas,(void *)&gUiTexScratch,0xa5);
h=(s16)(lbl_80368070.f6-lbl_80368070.f2);
w=(s16)(lbl_80368070.f4-lbl_80368070.f0);
if(w!=0 && h!=0) {
Prim2D_Begin();
Prim2D_SetTex((void *)&gUiTexScratch,(u16)(arg2|1));
Prim2D_PrepareTex();
Prim2D_AddPrim(1);
Prim2D_SetRectUv((f32)arg0,(f32)arg1,(f32)lbl_80368070.f0,(f32)lbl_80368070.f2,(f32)w,(f32)h);
Prim2D_EndPrim();
}
}

void fn_8015267C(s16 arg0, s16 arg1, s32 arg2) {
void Ui_LoadAtlasTex(s32,void *,s32);
void Prim2D_SetTex(void *,u16);
void Prim2D_Begin(void);
void Prim2D_PrepareTex(void);
void Prim2D_AddPrim(s32);
void Prim2D_SetRectUv(f32,f32,f32,f32,f32,f32);
void Prim2D_EndPrim(void);
extern s32 gUiTexAtlas;
extern u8 gUiTexScratch[];
extern struct {s16 x,y,right,bottom;} lbl_80368068;
s16 h;
s16 w;
Ui_LoadAtlasTex(gUiTexAtlas,gUiTexScratch,0xa4);
h=(s16)(lbl_80368068.bottom-lbl_80368068.y);
w=(s16)(lbl_80368068.right-lbl_80368068.x);
if(w!=0 && h!=0) {
Prim2D_Begin();
Prim2D_SetTex(gUiTexScratch,(u16)(arg2|1));
Prim2D_PrepareTex();
Prim2D_AddPrim(1);
Prim2D_SetRectUv((f32)arg0,(f32)arg1,(f32)lbl_80368068.x,(f32)lbl_80368068.y,(f32)w,(f32)h);
Prim2D_EndPrim();
}
}

extern void Ui_LoadAtlasTex(s32*, s32);
void fn_801527B0(s16 arg0, s16 arg1, s32 arg2) {
void Ui_LoadAtlasTex(s32,void *,s32);
void Prim2D_SetTex(void *,u16);
void Prim2D_Begin(void);
void Prim2D_PrepareTex(void);
void Prim2D_AddPrim(s32);
void Prim2D_SetRectUv(f32,f32,f32,f32,f32,f32);
void Prim2D_EndPrim(void);
extern s32 gUiTexAtlas;
extern u8 gUiTexScratch[];
extern struct {s16 x,y,right,bottom;} lbl_80368060;
s16 h;
s16 w;
Ui_LoadAtlasTex(gUiTexAtlas,gUiTexScratch,0xa3);
h=(s16)(lbl_80368060.bottom-lbl_80368060.y);
w=(s16)(lbl_80368060.right-lbl_80368060.x);
if(w!=0 && h!=0) {
Prim2D_Begin();
Prim2D_SetTex(gUiTexScratch,(u16)(arg2|1));
Prim2D_PrepareTex();
Prim2D_AddPrim(1);
Prim2D_SetRectUv((f32)arg0,(f32)arg1,(f32)lbl_80368060.x,(f32)lbl_80368060.y,(f32)w,(f32)h);
Prim2D_EndPrim();
}
}

void fn_801528E4(s16 arg0, s16 arg1, s32 arg2) {
void Ui_LoadAtlasTex(s32,void *,s32);
void Prim2D_SetTex(void *,u16);
void Prim2D_Begin(void);
void Prim2D_PrepareTex(void);
void Prim2D_AddPrim(s32);
void Prim2D_SetRectUv(f32,f32,f32,f32,f32,f32);
void Prim2D_EndPrim(void);
extern s32 gUiTexAtlas;
extern u8 gUiTexScratch[];
extern struct {s16 x,y,right,bottom;} lbl_80368058;
s16 h;
s16 w;
Ui_LoadAtlasTex(gUiTexAtlas,gUiTexScratch,0xa2);
h=(s16)(lbl_80368058.bottom-lbl_80368058.y);
w=(s16)(lbl_80368058.right-lbl_80368058.x);
if(w!=0 && h!=0) {
Prim2D_Begin();
Prim2D_SetTex(gUiTexScratch,(u16)(arg2|1));
Prim2D_PrepareTex();
Prim2D_AddPrim(1);
Prim2D_SetRectUv((f32)arg0,(f32)arg1,(f32)lbl_80368058.x,(f32)lbl_80368058.y,(f32)w,(f32)h);
Prim2D_EndPrim();
}
}

extern s32 gUiTexAtlas;
extern u8 gUiTexScratch[64];
extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367BE8;
void fn_80152A18(s16 arg0, s16 arg1, s32 arg2) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    s16 h;
    s16 w;

    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, 0x76);
    h = (s16)(lbl_80367BE8.f6 - lbl_80367BE8.f2);
    w = (s16)(lbl_80367BE8.f4 - lbl_80367BE8.f0);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg2 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)arg1, (f32)lbl_80367BE8.f0, (f32)lbl_80367BE8.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
}

void fn_80152B4C(s16 arg0, s16 arg1, s32 arg2, s32 arg3) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    extern u8 gUiTexScratch[64];
    extern struct { s16 x, y, right, bottom; } lbl_80368048;
    s16 h;
    s16 w;
    s16 *rect;
    s32 flags;
    s32 i;
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0xA0);
    flags = arg3 | 1;
    i = 0;
    rect = (s16 *)&lbl_80368048;
    for (; i < arg2; i++) {
        h = (s16)(rect[3] - rect[1]);
        w = (s16)(rect[2] - lbl_80368048.x);
        if (w != 0 && h != 0) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)flags);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)arg0, (f32)arg1, (f32)lbl_80368048.x, (f32)rect[1], (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
        arg0 += (s16)(rect[2] - lbl_80368048.x);
    }
}

void fn_80152CAC(s16 arg0, s16 arg1, s32 arg2) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80368030;
    s16 h;
    s16 w;

    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, 0x67);
    h = (s16)(lbl_80368030.f6 - lbl_80368030.f2);
    w = (s16)(lbl_80368030.f4 - lbl_80368030.f0);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg2 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)arg1, (f32)lbl_80368030.f0, (f32)lbl_80368030.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
}

void fn_80152DE0(s16 x, s16 y, u8 row, u8 col, u16 texFlags) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    extern s32 lbl_802774D0[4][2];
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80368038;
    s16 h;
    s16 w;
    s32 atlas;
    void *scratch;

    atlas = gUiTexAtlas;
    scratch = (void *)&gUiTexScratch;
    Ui_LoadAtlasTex(atlas, scratch, lbl_802774D0[row][col]);
    h = (s16)(lbl_80368038.f6 - lbl_80368038.f2);
    w = (s16)(lbl_80368038.f4 - lbl_80368038.f0);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(texFlags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80368038.f0, (f32)lbl_80368038.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
}

#pragma use_lmw_stmw on
void fn_80152F28(s16 arg0, s16 arg1, u8 arg2, s32 arg3) {
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddZ(f32);
    extern s32 lbl_803680CC;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_803680B0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_803680B8;
    extern f32 lbl_8036A878;
    f32 sp8;
    s16 *var_r29b;
    s32 temp_r28;
    s16 *var_r29;
    s16 temp_r30;
    s16 temp_r31;

    temp_r28 = Prim2D_PushZ(&sp8);
    Ui_LoadAtlasTex(lbl_803680CC, (void *)&gUiTexScratch, 1);
    var_r29 = (s16 *)&lbl_803680B0;
    temp_r31 = (s16)(var_r29[3] - var_r29[1]);
    temp_r30 = (s16)(var_r29[2] - lbl_803680B0.f0);
    if (temp_r30 != 0 && temp_r31 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg3 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)arg1, (f32)lbl_803680B0.f0, (f32)var_r29[1], (f32)temp_r30, (f32)temp_r31);
        Prim2D_EndPrim();
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A878);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(lbl_803680CC, (void *)&gUiTexScratch, arg2);
    var_r29b = (s16 *)&lbl_803680B8;
    temp_r30 = (s16)(var_r29b[3] - var_r29b[1]);
    temp_r31 = (s16)(var_r29b[2] - var_r29b[0]);
    if (temp_r31 != 0 && temp_r30 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg3 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(arg0 + 8), (f32)(s16)(arg1 + 8), (f32)lbl_803680B8.f0, (f32)var_r29b[1], (f32)temp_r31, (f32)temp_r30);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(temp_r28, sp8);
}
#pragma use_lmw_stmw reset
void fn_80153190(s16 arg0, s16 arg1, u8 arg2, s32 arg3) {
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddZ(f32);
    extern s32 lbl_803680CC;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_803680A8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_803680B8;
    extern f32 lbl_8036A878;
    f32 sp8;
    s32 temp_r28;
    s16 *var_r29;
    s16 temp_r30;
    s16 temp_r31;

    temp_r28 = Prim2D_PushZ(&sp8);
    Ui_LoadAtlasTex(lbl_803680CC, (void *)&gUiTexScratch, 0);
    {
        s16 t2, t6, t0, t4;
        var_r29 = (s16 *)&lbl_803680A8;
        t2 = var_r29[1];
        t6 = var_r29[3];
        t0 = var_r29[0];
        t4 = var_r29[2];
        temp_r31 = (s16)(t6 - t2);
        temp_r30 = (s16)(t4 - t0);
        if (temp_r30 != 0 && temp_r31 != 0) {
            Prim2D_Begin();
            Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg3 | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)arg0, (f32)arg1, (f32)lbl_803680A8.f0, (f32)var_r29[1], (f32)temp_r30, (f32)temp_r31);
            Prim2D_EndPrim();
        }
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A878);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(lbl_803680CC, (void *)&gUiTexScratch, arg2);
    var_r29 = (s16 *)&lbl_803680B8;
    temp_r30 = (s16)(var_r29[3] - var_r29[1]);
    temp_r31 = (s16)(var_r29[2] - var_r29[0]);
    if (temp_r31 != 0 && temp_r30 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg3 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(arg0 + 0x10), (f32)(s16)(arg1 + 8), (f32)lbl_803680B8.f0, (f32)var_r29[1], (f32)temp_r31, (f32)temp_r30);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(temp_r28, sp8);
}
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
void Ui_DrawSlotFrame(s16 arg0, s16 arg1, u8 arg2, s32 arg3) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80368018;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80368020;
    extern u8 gUiTexScratch[64];
    s16 var_r26;
    s16 var_r27;
    s32 var_r28;
    s16 temp_r30;
    s16 temp_r31;

    var_r26 = arg0;
    var_r27 = arg1;
    var_r28 = arg3;
    if (arg2 != 0) {
        s16 *var_r29;
        Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, 0x4B);
        var_r29 = (s16 *)&lbl_80368018;
        temp_r31 = (s16)(var_r29[3] - var_r29[1]);
        temp_r30 = (s16)(var_r29[2] - lbl_80368018.f0);
        if (temp_r30 != 0) {
            if (temp_r31 != 0) {
                Prim2D_Begin();
                Prim2D_SetTex((void *)&gUiTexScratch, (u16)(var_r28 | 1));
                Prim2D_PrepareTex();
                Prim2D_AddPrim(1);
                Prim2D_SetRectUv((f32)var_r26, (f32)var_r27, (f32)lbl_80368018.f0, (f32)var_r29[1], (f32)temp_r30, (f32)temp_r31);
                Prim2D_EndPrim();
            }
        }
    } else {
        s16 *var_r29;
        Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, 0x4C);
        var_r29 = (s16 *)&lbl_80368020;
        temp_r30 = (s16)(var_r29[3] - var_r29[1]);
        temp_r31 = (s16)(var_r29[2] - var_r29[0]);
        if (temp_r31 != 0) {
            if (temp_r30 != 0) {
                Prim2D_Begin();
                Prim2D_SetTex((void *)&gUiTexScratch, (u16)(var_r28 | 1));
                Prim2D_PrepareTex();
                Prim2D_AddPrim(1);
                Prim2D_SetRectUv((f32)var_r26, (f32)var_r27, (f32)lbl_80368020.f0, (f32)var_r29[1], (f32)temp_r31, (f32)temp_r30);
                Prim2D_EndPrim();
            }
        }
    }
}
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
/* Draw UI atlas tile 0x4A as an L-corner: horizontal arm, then vertical with UVs swapped. */
void Ui_DrawAtlasLCorner(s16 x, s16 y, s32 texFlags) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SwapUvU(void);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    extern u8 gUiTexScratch[64];
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } gUiAtlasRect4A;
    s16 drawX;
    s16 drawY;
    s32 flags;
    s16 *rect;
    s16 w;
    s16 h;
    s32 raw;

    drawX = x;
    drawY = y;
    flags = texFlags;
    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, 0x4A);
    rect = (s16 *)&gUiAtlasRect4A;
    h = (s16)(rect[3] - rect[1]);
    w = (s16)(rect[2] - gUiAtlasRect4A.f0);
    if (w != 0) {
        if (h != 0) {
            Prim2D_Begin();
            Prim2D_SetTex((void *)&gUiTexScratch, (u16)(flags | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)drawX, (f32)drawY, (f32)gUiAtlasRect4A.f0, (f32)rect[1], (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
    }
    raw = rect[2] - gUiAtlasRect4A.f0;
    drawX = (s16)(drawX + (s16)raw);
    w = (s16)(rect[3] - rect[1]);
    h = (s16)raw;
    if (h != 0) {
        if (w != 0) {
            Prim2D_Begin();
            Prim2D_SetTex((void *)&gUiTexScratch, (u16)(flags | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)drawX, (f32)drawY, (f32)gUiAtlasRect4A.f0, (f32)rect[1], (f32)h, (f32)w);
            Prim2D_SwapUvU();
            Prim2D_EndPrim();
        }
    }
}

#pragma use_lmw_stmw on
void fn_8015385C(s8 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, u16 arg7) {
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddZ(f32);
    extern u8 lbl_80277488[];
    extern u8 gUiTexScratch[64];
    extern s32 gUiTexAtlas;
    extern struct { s16 f0, f2, f4, f6; } lbl_80367FC0, lbl_80367FC8, lbl_80367FD0, lbl_80367FA8, lbl_80367FB0, lbl_80367FB8;
    extern f64 lbl_8036A868;
    extern f32 lbl_8036A878;
    s32 *tbl;
    s32 saved;
    f32 sp8;
    s16 w, h, y2;
    s16 mid_h, mid_w;
    (void)arg3;

    saved = Prim2D_PushZ(&sp8);
    tbl = (s32 *)(lbl_80277488 + (s8)arg0 * 0x18);
    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, *tbl++);
    w = (s16)(lbl_80367FC0.f4 - lbl_80367FC0.f0);
    h = (s16)(lbl_80367FC0.f6 - lbl_80367FC0.f2);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg7 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg1, (f32)arg2, (f32)lbl_80367FC0.f0, (f32)lbl_80367FC0.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, *tbl++);
    {
        s16 h0 = (s16)(lbl_80367FC0.f6 - lbl_80367FC0.f2);
        s16 h1 = (s16)(lbl_80367FD0.f6 - lbl_80367FD0.f2);
        mid_w = (s16)(lbl_80367FC8.f4 - lbl_80367FC8.f0);
        mid_h = (s16)(arg4 - (h0 + h1));
        y2 = (s16)(arg2 + h0);
        if (mid_w != 0 && mid_h != 0) {
            Prim2D_Begin();
            Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg7 | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect((f32)arg1, (f32)y2, (f32)mid_w, (f32)mid_h);
            Prim2D_SetUvRect((f32)lbl_80367FC8.f0, (f32)lbl_80367FC8.f2, (f32)(s16)(lbl_80367FC8.f4 - lbl_80367FC8.f0), (f32)(s16)(lbl_80367FC8.f6 - lbl_80367FC8.f2));
            Prim2D_EndPrim();
        }
    }
    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, *tbl++);
    {
        s16 hb = (s16)(lbl_80367FD0.f6 - lbl_80367FD0.f2);
        w = (s16)(lbl_80367FD0.f4 - lbl_80367FD0.f0);
        y2 = (s16)(arg2 + (arg4 - hb));
        if (w != 0 && hb != 0) {
            Prim2D_Begin();
            Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg7 | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)arg1, (f32)y2, (f32)lbl_80367FD0.f0, (f32)lbl_80367FD0.f2, (f32)w, (f32)hb);
            Prim2D_EndPrim();
        }
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A878);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, *tbl++);
    w = (s16)(lbl_80367FA8.f4 - lbl_80367FA8.f0);
    h = (s16)(lbl_80367FA8.f6 - lbl_80367FA8.f2);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg7 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg1, (f32)(s16)(arg2 + arg5), (f32)lbl_80367FA8.f0, (f32)lbl_80367FA8.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, *tbl++);
    {
        s16 h0 = (s16)(lbl_80367FA8.f6 - lbl_80367FA8.f2);
        s16 h1 = (s16)(lbl_80367FB8.f6 - lbl_80367FB8.f2);
        mid_w = (s16)(lbl_80367FB0.f4 - lbl_80367FB0.f0);
        mid_h = (s16)(arg6 - (h0 + h1));
        y2 = (s16)(arg2 + (arg5 + h0));
        if (mid_w != 0 && mid_h != 0) {
            Prim2D_Begin();
            Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg7 | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect((f32)arg1, (f32)y2, (f32)mid_w, (f32)mid_h);
            Prim2D_SetUvRect((f32)lbl_80367FB0.f0, (f32)lbl_80367FB0.f2, (f32)(s16)(lbl_80367FB0.f4 - lbl_80367FB0.f0), (f32)(s16)(lbl_80367FB0.f6 - lbl_80367FB0.f2));
            Prim2D_EndPrim();
        }
    }
    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, *tbl);
    {
        s16 hb = (s16)(lbl_80367FB8.f6 - lbl_80367FB8.f2);
        w = (s16)(lbl_80367FB8.f4 - lbl_80367FB8.f0);
        y2 = (s16)(arg2 + ((arg5 + arg6) - hb));
        if (w != 0 && hb != 0) {
            Prim2D_Begin();
            Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg7 | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)arg1, (f32)y2, (f32)lbl_80367FB8.f0, (f32)lbl_80367FB8.f2, (f32)w, (f32)hb);
            Prim2D_EndPrim();
        }
    }
    Prim2D_PopZ(saved, sp8);
}
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset

void fn_80154004(s16 arg0, s16 arg1, s32 arg2) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367F58;
    s16 h;
    s16 w;

    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, 0x31);
    h = (s16)(lbl_80367F58.f6 - lbl_80367F58.f2);
    w = (s16)(lbl_80367F58.f4 - lbl_80367F58.f0);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg2 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)arg1, (f32)lbl_80367F58.f0, (f32)lbl_80367F58.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
}

#pragma use_lmw_stmw on
void fn_80154138(s16 arg0, s16 arg1, s32 arg2) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SwapUvU(void);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367F90;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367F80;
    extern u8 gUiTexScratch[64];
    extern f64 lbl_8036A868;
    s16 x;
    s16 y;
    s32 flags;
    s16 *rect;
    s16 temp_r30;
    s16 temp_r31;

    x = arg0;
    y = arg1;
    flags = arg2;
    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, 0x33);
    {
        s16 t2, t6, t0, t4;
        rect = (s16 *)&lbl_80367F90;
        t2 = rect[1];
        t6 = rect[3];
        t0 = lbl_80367F90.f0;
        t4 = rect[2];
        temp_r31 = (s16)(t6 - t2);
        temp_r30 = (s16)(t4 - t0);
        if (temp_r30 != 0 && temp_r31 != 0) {
            Prim2D_Begin();
            Prim2D_SetTex((void *)&gUiTexScratch, (u16)(flags | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80367F90.f0, (f32)rect[1], (f32)temp_r30, (f32)temp_r31);
            Prim2D_EndPrim();
        }
    }
    {
        s16 *p80 = (s16 *)&lbl_80367F80;
        s16 raw = (s16)(p80[2] - lbl_80367F80.f0);
        x = (s16)(x + raw);
        temp_r31 = (s16)(rect[2] - lbl_80367F90.f0);
        temp_r30 = (s16)(rect[3] - rect[1]);
        if (temp_r31 != 0 && temp_r30 != 0) {
            Prim2D_Begin();
            Prim2D_SetTex((void *)&gUiTexScratch, (u16)(flags | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80367F90.f0, (f32)rect[1], (f32)temp_r31, (f32)temp_r30);
            Prim2D_SwapUvU();
            Prim2D_EndPrim();
        }
    }
}
#pragma use_lmw_stmw reset
void fn_80154370(s16 arg0, s16 arg1) {
#pragma use_lmw_stmw on
#pragma global_optimizer off
    void Ui_DrawWindowFrame(void);
    s32 Prim2D_PushZ(f32 *);
    s32 Msg_Expand(void *);
    s32 Text_MeasureWidth(s32, s32, f32);
    s32 fn_80010770(s32, s32, f32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_EndPrim(void);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Text_Draw(s16, s16, s32, s32, s16, ...);
    void Prim2D_PopZ(s32, f32);
    extern u8 lbl_802774F0[];
    extern f32 lbl_8036A874;
    extern f32 lbl_8036A87C;
    extern f32 lbl_8036A878;
    extern f64 lbl_8036A868;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C40;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CE8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C50;
    extern u8 gUiTexScratch[64];
    extern s32 gUiTexAtlas;

    f32 sp10;
    u8 spC[4];
    s32 sp8;
    s32 temp_r30;
    s32 temp_r31;
    s16 temp_r20;
    s16 *temp_r25;
    s16 *temp_r26;
    s16 temp_r27;
    s16 temp_r28;
    s16 temp_r29;
    s32 temp_r22;
    s32 temp_r21;

    Ui_DrawWindowFrame();
    temp_r22 = Prim2D_PushZ(&sp10);
    temp_r21 = Msg_Expand(lbl_802774F0 + 0x1DA);
    temp_r30 = Text_MeasureWidth(temp_r21, -1, lbl_8036A874);
    temp_r31 = fn_80010770(temp_r21, -1, lbl_8036A874);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A87C);
    Prim2D_PrepareTex();

    {
        s16 *rC40 = (s16 *)&lbl_80367C40;
        s16 t4;
        s16 t5;
        s16 t7;
        s16 t8;

        temp_r26 = (s16 *)&lbl_80367CE8;
        spC[0] = 0;
        temp_r25 = (s16 *)&lbl_80367C50;
        t4 = (s16)(temp_r26[2] - lbl_80367CE8.f0);
        t5 = (s16)(arg0 + ((s16)(rC40[2] - lbl_80367C40.f0) + 1));
        t8 = (s16)(temp_r26[3] - temp_r26[1]);
        t7 = (s16)(arg1 + ((s16)(temp_r25[3] - temp_r25[1]) + 8));
        spC[0] = 0;
        temp_r27 = (s16)(t5 + (s16)(temp_r30 + t4));
        spC[1] = 0;
        temp_r20 = (s16)(t7 + t8);
        spC[2] = 0;
        temp_r28 = (s16)(temp_r27 - t4);
        spC[3] = 0xFF;
        temp_r30 = t5;
        temp_r29 = t7;
        temp_r20 = (s16)(t7 + t8);
    }

    Prim2D_Begin();
    Prim2D_SetTex(NULL, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)(s16)temp_r30, (f32)temp_r29, (f32)(s16)(temp_r28 - (s16)temp_r30), (f32)(s16)(temp_r20 - temp_r29));
    sp8 = *(s32 *)spC;
    Prim2D_SetColorPacked(&sp8);
    Prim2D_EndPrim();
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0xA);

    {
        s16 t5 = (s16)(lbl_80367CE8.f4 - lbl_80367CE8.f0);
        s16 t0 = (s16)(temp_r26[3] - temp_r26[1]);
        temp_r30 = (s16)(temp_r27 - t5);
        temp_r27 = t5;
        temp_r28 = t0;
        if (temp_r27 != 0) {
            if (temp_r28 != 0) {
                Prim2D_Begin();
                Prim2D_SetTex(gUiTexScratch, 0x11);
                Prim2D_PrepareTex();
                Prim2D_AddPrim(1);
                Prim2D_SetRectUv((f32)(s16)temp_r30, (f32)temp_r29, (f32)lbl_80367CE8.f0, (f32)temp_r26[1], (f32)temp_r27, (f32)temp_r28);
                Prim2D_EndPrim();
            }
        }
    }

    temp_r20 = (s16)(((s16)(temp_r26[3] - temp_r26[1]) - temp_r31) >> 1);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A878);
    Prim2D_PrepareTex();
    Text_Draw(
        (s16)(arg0 + (s16)(temp_r26[2] - lbl_80367CE8.f0)),
        (s16)(arg1 + ((s16)(temp_r25[3] - temp_r25[1]) + 8 + temp_r20)),
        9, temp_r21, lbl_80367CE8.f0);
    Prim2D_PopZ(temp_r22, sp10);
}
#pragma global_optimizer reset
void fn_801546B0(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367F30;
    s16 h;
    s16 w;

    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, 0x16);
    h = (s16)(lbl_80367F30.f6 - lbl_80367F30.f2);
    w = (s16)(lbl_80367F30.f4 - lbl_80367F30.f0);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg4 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)arg1, (f32)lbl_80367F30.f0, (f32)lbl_80367F30.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
}

#pragma use_lmw_stmw on
/* Draw Job/Personal panel: window frame, icon, MD_JOB/MD_PSN labels, and exp gauge. */
void Ui_DrawJobPersonalPanel(s16 x, s16 y, s32 width, s32 height, s32 gaugeMax, s32 alpha, s32 flags, f32 gaugeVal) {
    void Ui_DrawWindowFrame(s16, s16, s32, s32, s32, s32);
    s32 Prim2D_PushZ(f32 *);
    void Ui_LoadAtlasTex(s32, void *, s32);
    u8 *Ui_GetColor(s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_EndPrim(void);
    s32 Msg_Expand(void *);
    void fn_8001003C(s16, s16, s32, s32, s32, s32, ...);
    void Ui_DrawExpGauge(s32, f32, f32, f32);
    void Prim2D_PopZ(s32, f32);
    extern s32 gUiTexAtlas;
    extern u8 gUiTexScratch[64];
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } gUiJobPersonalIconUv;
    extern f64 lbl_8036A868;
    extern f32 lbl_8036A874;
    extern f32 lbl_8036A880;
    extern u8 lbl_802774F0[];

    f32 savedZ;
    u8 colorBytes[4];
    s32 packedColor;
    s16 posY;
    s16 posX;
    s16 h;
    s16 w;
    s16 *rect;
    s32 saved;
    u8 *color;
    s32 str;

    Ui_DrawWindowFrame(x, y, width, height, alpha, flags);
    saved = Prim2D_PushZ(&savedZ);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0xC);
    color = Ui_GetColor(0);
    rect = (s16 *)&gUiJobPersonalIconUv;
    colorBytes[0] = color[0];
    w = (s16)(rect[2] - rect[0]);
    colorBytes[1] = color[1];
    colorBytes[2] = color[2];
    colorBytes[3] = color[3];
    h = (s16)(rect[3] - rect[1]);
    if (w != 0) {
        if (h != 0) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)(flags | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)(s16)(x + 0x90), (f32)(s16)(y + 0x2D),
                        (f32)gUiJobPersonalIconUv.f0, (f32)rect[1], (f32)w, (f32)h);
            packedColor = *(s32 *)colorBytes;
            Prim2D_SetColorPacked(&packedColor);
            Prim2D_EndPrim();
        }
    }
    Prim2D_Begin();
    Prim2D_SetTex(NULL, 0x13);
    Prim2D_PrepareTex();
    posX = (s16)x;
    posY = (s16)y;
    str = Msg_Expand(lbl_802774F0 + 0x1E8);
    fn_8001003C((s16)(posX + 0xA), (s16)(posY + 0xE), 6, 1, 0, str, lbl_8036A874, lbl_8036A880);
    str = Msg_Expand(lbl_802774F0 + 0x1EF);
    fn_8001003C((s16)(posX + 0x8C), (s16)(posY + 0x2F), 6, 1, 0, str, lbl_8036A874, lbl_8036A880);
    Ui_DrawExpGauge(gaugeMax, (f32)(posX + 8), (f32)(posY + 0x2E), gaugeVal);
    Prim2D_PopZ(saved, savedZ);
}

void fn_80154A74(s16 x, s32 y, s16 boxW, s32 a, s32 b, s32 flags) {
    void fn_8015C674(void);
    s32 Prim2D_PushZ(f32 *);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32,f32,f32,f32,f32,f32);
    void Prim2D_EndPrim(void);
    void Prim2D_PopZ(s32,f32);
    extern s32 gUiTexAtlas;
    extern u8 gUiTexScratch[64];
    extern struct { s16 f0,f2,f4,f6; } gUiPanelDecorUvB;
    f32 savedZ;
    s16 *uv;
    s16 drawY;
    s16 h;
    s16 w;
    s32 saved;
    s16 drawX;
    fn_8015C674();
    saved = Prim2D_PushZ(&savedZ);
    Ui_LoadAtlasTex(gUiTexAtlas,gUiTexScratch,0x80);
    uv = (s16 *)&gUiPanelDecorUvB;
    drawY = y + 0x30;
    drawX = (x + (boxW - (s16)(uv[2]-gUiPanelDecorUvB.f0))) >> 1;
    w = uv[2]-gUiPanelDecorUvB.f0;
    h = uv[3]-uv[1];
    if(w) { if(h) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch,(u16)(flags|1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(drawX,drawY,gUiPanelDecorUvB.f0,uv[1],w,h);
        Prim2D_EndPrim();
    }}
    Prim2D_PopZ(saved,savedZ);
}

#pragma use_lmw_stmw reset

void fn_80154BE4(void) {
    M2C_UNK fn_8015C674();
    fn_8015C674();
}

#pragma use_lmw_stmw on
/* Draw panel decor sprites 0x81 and 0x80, centered in the given box. */
void Ui_DrawPanelDecor(s16 x, s16 y, s16 boxW, s16 boxH, s32 unused, s32 flags) {
    void fn_8015D240(void);
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_PopZ(s32, f32);
    extern s32 gUiTexAtlas;
    extern u8 gUiTexScratch[64];
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } gUiPanelDecorUvA;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } gUiPanelDecorUvB;
    extern f64 lbl_8036A868;
    extern f32 lbl_8036A878;
    extern f32 lbl_8036A884;
    f32 savedZ;
    s16 *uv;
    s16 w;
    s32 bw;
    s16 h;
    s32 bx;
    s32 saved;
    s16 drawX;
    s16 drawY;

    fn_8015D240();
    saved = Prim2D_PushZ(&savedZ);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A878);
    Prim2D_PrepareTex();
    uv = (s16 *)&gUiPanelDecorUvA;
    bw = boxW;
    bx = x;
    drawX = (s16)(bx + ((bw >> 2) - ((s16)(uv[2] - gUiPanelDecorUvA.f0) >> 1)));
    drawY = (s16)((f32)y + (lbl_8036A884 * (f32)boxH - (f32)((s16)(uv[3] - uv[1]) >> 1)));
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x81);
    h = (s16)(uv[3] - uv[1]);
    w = (s16)(uv[2] - gUiPanelDecorUvA.f0);
    if (w) {
        if (h) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)(flags | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)drawX, (f32)drawY, (f32)gUiPanelDecorUvA.f0, (f32)uv[1], (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x80);
    uv = (s16 *)&gUiPanelDecorUvB;
    drawX = (s16)((bx + (bw - (s16)(uv[2] - gUiPanelDecorUvB.f0))) >> 1);
    w = (s16)(uv[2] - gUiPanelDecorUvB.f0);
    h = (s16)(uv[3] - uv[1]);
    if (w) {
        if (h) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)(flags | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)drawX, (f32)(s16)(y + 0x28), (f32)gUiPanelDecorUvB.f0, (f32)uv[1], (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
    }
    Prim2D_PopZ(saved, savedZ);
}

#pragma optimization_level 3
void fn_80154F1C(s32 x, s32 y, s32 align, s32 value, s32 flags) {
    char *fn_80238ABC(s32, char *, s32);
    u32 strlen(char *);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    extern u8 gUiTexScratch[64];
    extern struct { s16 x, y, right, bottom; } lbl_80367F98;
    extern s32 lbl_80367F9C;
    char buf[16];
    s16 rect[4];
    s16 *base;
    char *p;
    s16 w;
    s16 h;
    s32 len;
    s16 totalW;
    s32 dig;

    fn_80238ABC(value, buf, 0xA);
    len = strlen(buf);
    base = (s16 *)&lbl_80367F98;
    totalW = (s16)(len * (s16)(base[2] - lbl_80367F98.x));
    switch (align) {
    case 0:
        break;
    case 1:
        x = (s16)(x - (totalW >> 1));
        break;
    case 2:
        x = x - totalW;
        break;
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x21);
    p = buf;
    flags |= 1;
    while ((s8)*p != 0) {
        *(s32 *)&rect[0] = *(s32 *)&lbl_80367F98;
        *(s32 *)&rect[2] = lbl_80367F9C;
        dig = ((s8)*p) - 0x30;
        w = (s16)(rect[2] - rect[0] + 1);
        h = (s16)(rect[3] - rect[1]);
        w = (s16)(dig * w);
        rect[0] = (s16)(rect[0] + w);
        rect[2] = (s16)(rect[2] + w);
        w = (s16)(rect[2] - rect[0]);
        if (w != 0 && h != 0) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)flags);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)(s16)x, (f32)(s16)y, (f32)rect[0], (f32)rect[1], (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
        p++;
        x += (s16)(base[2] - lbl_80367F98.x);
    }
}
#pragma optimization_level reset

void fn_8015512C(s16 arg0,s16 arg1,u8 arg2,s32 arg3) {
void Ui_LoadAtlasTex(s32,void *,s32);
void Prim2D_Begin(void); void Prim2D_SetTex(void *,u16);
void Prim2D_PrepareTex(void); void Prim2D_AddPrim(s32);
void Prim2D_SetRectUv(f32,f32,f32,f32,f32,f32);
void Prim2D_SwapUvU(void); void Prim2D_SwapUvV(void);
void Prim2D_RotateUvCcw(void); void Prim2D_RotateUvCw(void); void Prim2D_EndPrim(void);
extern s32 gUiTexAtlas;
extern u8 gUiTexScratch[64];
extern struct {s16 x,y,right,bottom;} lbl_80367FA0;
s16 x=arg0,y=arg1;
u8 flip=arg2;
s32 flags=arg3;
s16 h,w;
s16 *rect;
s32 uv;
Ui_LoadAtlasTex(gUiTexAtlas,gUiTexScratch,0x22);
rect=(s16 *)&lbl_80367FA0;
h=(s16)(rect[3]-rect[1]);
w=(s16)(rect[2]-lbl_80367FA0.x);
if(w!=0 && h!=0) {
Prim2D_Begin(); Prim2D_SetTex(gUiTexScratch,(u16)(flags|1)); Prim2D_PrepareTex(); Prim2D_AddPrim(1);
Prim2D_SetRectUv((f32)x,(f32)y,(f32)lbl_80367FA0.x,(f32)rect[1],(f32)w,(f32)h);
uv=2;if(flip)uv=0;if(uv&1)Prim2D_SwapUvU();
uv=2;if(flip)uv=0;if(uv&2)Prim2D_SwapUvV();
uv=2;if(flip)uv=0;if(uv&0x100)Prim2D_RotateUvCcw();
uv=2;if(flip)uv=0;if(uv&0x200)Prim2D_RotateUvCw();
Prim2D_EndPrim();
}
}

void fn_801552D4(s16 arg0,s16 arg1,u8 arg2,s32 arg3) {
void Ui_LoadAtlasTex(s32,void *,s32);
void Prim2D_Begin(void); void Prim2D_SetTex(void *,u16);
void Prim2D_PrepareTex(void); void Prim2D_AddPrim(s32);
void Prim2D_SetRectUv(f32,f32,f32,f32,f32,f32);
void Prim2D_SwapUvU(void); void Prim2D_SwapUvV(void);
void Prim2D_RotateUvCcw(void); void Prim2D_RotateUvCw(void); void Prim2D_EndPrim(void);
extern s32 gUiTexAtlas;
extern u8 gUiTexScratch[64];
extern struct {s16 x,y,right,bottom;} lbl_80367FA0;
s16 x=arg0,y=arg1;
u8 flip=arg2;
s32 flags=arg3;
s16 h,w;
s16 *rect;
s32 uv;
Ui_LoadAtlasTex(gUiTexAtlas,gUiTexScratch,0x22);
rect=(s16 *)&lbl_80367FA0;
h=(s16)(rect[3]-rect[1]);
w=(s16)(rect[2]-lbl_80367FA0.x);
if(w!=0 && h!=0) {
Prim2D_Begin(); Prim2D_SetTex(gUiTexScratch,(u16)(flags|1)); Prim2D_PrepareTex(); Prim2D_AddPrim(1);
Prim2D_SetRectUv((f32)x,(f32)y,(f32)lbl_80367FA0.x,(f32)rect[1],(f32)w,(f32)h);
uv=2;if(flip)uv=0;if(uv&1)Prim2D_SwapUvU();
uv=2;if(flip)uv=0;if(uv&2)Prim2D_SwapUvV();
uv=2;if(flip)uv=0;if(uv&0x100)Prim2D_RotateUvCcw();
uv=2;if(flip)uv=0;if(uv&0x200)Prim2D_RotateUvCw();
Prim2D_EndPrim();
}
}

#pragma use_lmw_stmw on
void fn_8015547C(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(void *);
    void Prim2D_AddZ(f32);
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CD8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CB0;
    extern s16 lbl_80367CE0[4];
    extern s16 lbl_80367CA8[4];
    extern s16 lbl_80367CC8[4];
    extern s16 lbl_80367CD0[4];
    extern s16 lbl_80367CB8[4];
    extern s16 lbl_80367CC0[4];
    extern s16 lbl_80368040[4];
    extern f32 lbl_8036A888;
    f32 sp14;
    s32 handle;
    s16 sp5C;
    u8 color[4];
    u8 alpha;
    s16 x, y, x2, y2;
    s16 t14, t18, t19, t20;
    s16 w, h, px, py;
    s32 packed;
    s16 *p38;
    s16 *p58;

    x = arg0;
    y = arg1;
    x2 = (s16)(x + arg2);
    y2 = (s16)(y + arg3);
    alpha = arg4;
    p58 = (s16 *)&lbl_80367CD8;
    p38 = (s16 *)&lbl_80367CB0;

    {
        s16 h38 = (s16)(p38[3] - p38[1]);
        s16 w38 = (s16)(p38[2] - lbl_80367CB0.f0);
        t18 = (s16)(y2 - (s16)(p58[3] - p58[1]));
        t19 = (s16)(x2 - (s16)(p58[2] - lbl_80367CD8.f0));
        t20 = (s16)(y + h38);
        t14 = (s16)(x + w38);
        sp5C = t20;
    }

    handle = Prim2D_PushZ(&sp14);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x36);

    w = (s16)(p38[2] - lbl_80367CB0.f0);
    h = (s16)(p38[3] - p38[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80367CB0.f0, (f32)p38[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x3C);
    w = (s16)(lbl_80367CE0[2] - lbl_80367CE0[0]);
    h = (s16)(lbl_80367CE0[3] - lbl_80367CE0[1]);
    px = (s16)(x2 - w);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367CE0[0], (f32)lbl_80367CE0[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x35);
    w = (s16)(lbl_80367CA8[2] - lbl_80367CA8[0]);
    h = (s16)(lbl_80367CA8[3] - lbl_80367CA8[1]);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)py, (f32)lbl_80367CA8[0], (f32)lbl_80367CA8[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x3B);
    h = (s16)(p58[3] - p58[1]);
    w = (s16)(p58[2] - lbl_80367CD8.f0);
    px = (s16)(x2 - w);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367CD8.f0, (f32)p58[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x39);
    t19 = (s16)(t19 - t14);
    h = (s16)(lbl_80367CC8[3] - lbl_80367CC8[1]);
    px = (s16)(x + (s16)(p38[2] - lbl_80367CB0.f0));
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367CC8[0], (f32)lbl_80367CC8[1], (f32)t19, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x3A);
    h = (s16)(lbl_80367CD0[3] - lbl_80367CD0[1]);
    px = (s16)(x + (s16)(lbl_80367CA8[2] - lbl_80367CA8[0]));
    py = (s16)(y2 - h);
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367CD0[0], (f32)lbl_80367CD0[1], (f32)t19, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x37);
    t18 = (s16)(t18 - sp5C);
    w = (s16)(lbl_80367CB8[2] - lbl_80367CB8[0]);
    py = (s16)(y + (s16)(p38[3] - p38[1]));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)py, (f32)lbl_80367CB8[0], (f32)lbl_80367CB8[1], (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x38);
    w = (s16)(lbl_80367CC0[2] - lbl_80367CC0[0]);
    py = (s16)(y + (s16)(lbl_80367CE0[3] - lbl_80367CE0[1]));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x2 - w), (f32)py, (f32)lbl_80367CC0[0], (f32)lbl_80367CC0[1], (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    py = (s16)(arg1 + 2);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x74);
    w = (s16)(x2 - x);
    h = (s16)((s16)(y2 - 2) - py);
    color[0] = 0xFF;
    color[1] = 0xFF;
    color[2] = 0xFF;
    color[3] = alpha;
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)arg0, (f32)py, (f32)w, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80368040[0], (f32)lbl_80368040[1],
                    (f32)(s16)(lbl_80368040[2] - lbl_80368040[0]),
                    (f32)(s16)(lbl_80368040[3] - lbl_80368040[1]));
        packed = *(s32 *)color;
        Prim2D_SetColorPacked(&packed);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(handle, sp14);
}

#pragma use_lmw_stmw on
void fn_80155F20(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(void *);
    void Prim2D_AddZ(f32);
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CD8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CB0;
    extern s16 lbl_80367CE0[4];
    extern s16 lbl_80367CA8[4];
    extern s16 lbl_80367CC8[4];
    extern s16 lbl_80367CD0[4];
    extern s16 lbl_80367CB8[4];
    extern s16 lbl_80367CC0[4];
    extern s16 lbl_80368040[4];
    extern f32 lbl_8036A888;
    f32 sp14;
    s32 handle;
    s16 sp5C;
    u8 color[4];
    u8 alpha;
    s16 x, y, x2, y2;
    s16 t14, t18, t19, t20;
    s16 w, h, px, py;
    s32 packed;
    s16 *p38;
    s16 *p58;

    x = arg0;
    y = arg1;
    x2 = (s16)(x + arg2);
    y2 = (s16)(y + arg3);
    alpha = arg4;
    p58 = (s16 *)&lbl_80367CD8;
    p38 = (s16 *)&lbl_80367CB0;

    {
        s16 h38 = (s16)(p38[3] - p38[1]);
        s16 w38 = (s16)(p38[2] - lbl_80367CB0.f0);
        t18 = (s16)(y2 - (s16)(p58[3] - p58[1]));
        t19 = (s16)(x2 - (s16)(p58[2] - lbl_80367CD8.f0));
        t20 = (s16)(y + h38);
        t14 = (s16)(x + w38);
        sp5C = t20;
    }

    handle = Prim2D_PushZ(&sp14);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x36);

    w = (s16)(p38[2] - lbl_80367CB0.f0);
    h = (s16)(p38[3] - p38[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80367CB0.f0, (f32)p38[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x3C);
    w = (s16)(lbl_80367CE0[2] - lbl_80367CE0[0]);
    h = (s16)(lbl_80367CE0[3] - lbl_80367CE0[1]);
    px = (s16)(x2 - w);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367CE0[0], (f32)lbl_80367CE0[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x35);
    w = (s16)(lbl_80367CA8[2] - lbl_80367CA8[0]);
    h = (s16)(lbl_80367CA8[3] - lbl_80367CA8[1]);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)py, (f32)lbl_80367CA8[0], (f32)lbl_80367CA8[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x3B);
    h = (s16)(p58[3] - p58[1]);
    w = (s16)(p58[2] - lbl_80367CD8.f0);
    px = (s16)(x2 - w);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367CD8.f0, (f32)p58[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x39);
    t19 = (s16)(t19 - t14);
    h = (s16)(lbl_80367CC8[3] - lbl_80367CC8[1]);
    px = (s16)(x + (s16)(p38[2] - lbl_80367CB0.f0));
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367CC8[0], (f32)lbl_80367CC8[1], (f32)t19, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x3A);
    h = (s16)(lbl_80367CD0[3] - lbl_80367CD0[1]);
    px = (s16)(x + (s16)(lbl_80367CA8[2] - lbl_80367CA8[0]));
    py = (s16)(y2 - h);
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367CD0[0], (f32)lbl_80367CD0[1], (f32)t19, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x37);
    t18 = (s16)(t18 - sp5C);
    w = (s16)(lbl_80367CB8[2] - lbl_80367CB8[0]);
    py = (s16)(y + (s16)(p38[3] - p38[1]));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)py, (f32)lbl_80367CB8[0], (f32)lbl_80367CB8[1], (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x38);
    w = (s16)(lbl_80367CC0[2] - lbl_80367CC0[0]);
    py = (s16)(y + (s16)(lbl_80367CE0[3] - lbl_80367CE0[1]));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x2 - w), (f32)py, (f32)lbl_80367CC0[0], (f32)lbl_80367CC0[1], (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    py = (s16)(arg1 + 2);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x74);
    w = (s16)(x2 - x);
    h = (s16)((s16)(y2 - 2) - py);
    color[0] = 0xFF;
    color[1] = 0xFF;
    color[2] = 0xFF;
    color[3] = alpha;
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)arg0, (f32)py, (f32)w, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80368040[0], (f32)lbl_80368040[1],
                    (f32)(s16)(lbl_80368040[2] - lbl_80368040[0]),
                    (f32)(s16)(lbl_80368040[3] - lbl_80368040[1]));
        packed = *(s32 *)color;
        Prim2D_SetColorPacked(&packed);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(handle, sp14);
}
void fn_801569C4(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void fn_80007358(f32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    typedef struct { s16 f0; s16 f2; s16 f4; s16 f6; } Rect;
    extern Rect lbl_80367C68;
    extern Rect lbl_80367C70;
    extern Rect lbl_80367C78;
    extern Rect lbl_80367C80;
    extern Rect lbl_80367C88;
    extern Rect lbl_80367C90;
    extern Rect lbl_80367C98;
    extern Rect lbl_80367CA0;
    extern Rect lbl_80367FE0;
    extern Rect lbl_80367FE8;
    extern u8 gUiTexScratch[64];
    extern s32 gUiTexAtlas;
    extern f32 lbl_8036A880;
    extern f32 lbl_8036A888;
    f32 sp14;
    u8 sp10[4];
    s32 spC;
    u8 sp8;
    s32 saved;
    Rect *p98;
    Rect *p70;
    Rect *pA0;
    Rect *p68;
    Rect *p88;
    Rect *p90;
    s16 a0;
    s16 a1;
    s16 x1;
    s16 y1;
    s16 w;
    s16 h;
    s16 t14;
    s16 t19;
    s16 t20;
    s16 dw;
    s16 dh;
    s16 xfill;
    s16 xR;
    s32 fl;

    p98 = &lbl_80367C98;
    a0 = arg0;
    a1 = arg1;
    p70 = &lbl_80367C70;
    x1 = (s16)(a0 + arg2);
    y1 = (s16)(a1 + arg3);
    sp8 = arg4;
    fl = arg5;
    {
        s16 h70 = (s16)(p70->f6 - p70->f2);
        s16 w70 = (s16)(p70->f4 - lbl_80367C70.f0);
        dh = (s16)(y1 - (s16)(p98->f6 - p98->f2));
        t19 = (s16)(x1 - (s16)(p98->f4 - lbl_80367C98.f0));
        t20 = (s16)(a1 + h70);
        t14 = (s16)(a0 + w70);
    }
    saved = Prim2D_PushZ(&sp14);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x2A);
    w = (s16)(p70->f4 - lbl_80367C70.f0);
    h = (s16)(p70->f6 - p70->f2);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)a0, (f32)a1, (f32)lbl_80367C70.f0, (f32)p70->f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x30);
    pA0 = &lbl_80367CA0;
    w = (s16)(pA0->f4 - lbl_80367CA0.f0);
    h = (s16)(pA0->f6 - pA0->f2);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x1 - w), (f32)a1, (f32)lbl_80367CA0.f0, (f32)pA0->f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x29);
    p68 = &lbl_80367C68;
    w = (s16)(p68->f4 - lbl_80367C68.f0);
    h = (s16)(p68->f6 - p68->f2);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)a0, (f32)(s16)(y1 - h), (f32)lbl_80367C68.f0, (f32)p68->f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x2F);
    w = (s16)(p98->f4 - lbl_80367C98.f0);
    h = (s16)(p98->f6 - p98->f2);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x1 - w), (f32)(s16)(y1 - h), (f32)lbl_80367C98.f0, (f32)p98->f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x2D);
    p88 = &lbl_80367C88;
    dw = (s16)(t19 - t14);
    h = (s16)(p88->f6 - p88->f2);
    t14 = (s16)(a0 + (s16)(p70->f4 - lbl_80367C70.f0));
    if (dw != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)t14, (f32)a1, (f32)lbl_80367C88.f0, (f32)p88->f2, (f32)dw, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x2E);
    p90 = &lbl_80367C90;
    h = (s16)(p90->f6 - p90->f2);
    t14 = (s16)(a0 + (s16)(p68->f4 - lbl_80367C68.f0));
    if (dw != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)t14, (f32)(s16)(y1 - h), (f32)lbl_80367C90.f0, (f32)p90->f2, (f32)dw, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x2B);
    dh = (s16)(t20 - dh);
    w = (s16)(lbl_80367C78.f4 - lbl_80367C78.f0);
    t14 = (s16)(a1 + (s16)(p70->f6 - p70->f2));
    if (w != 0 && dh != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(a0 + 1), (f32)t14, (f32)lbl_80367C78.f0, (f32)lbl_80367C78.f2, (f32)w, (f32)dh);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x2C);
    w = (s16)(lbl_80367C80.f4 - lbl_80367C80.f0);
    t14 = (s16)(a1 + (s16)(pA0->f6 - pA0->f2));
    if (w != 0 && dh != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)((x1 - w) - 1), (f32)t14, (f32)lbl_80367C80.f0, (f32)lbl_80367C80.f2, (f32)w, (f32)dh);
        Prim2D_EndPrim();
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    xR = (s16)(x1 - 1);
    xfill = (s16)(a0 + 1);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x45);
    w = (s16)(lbl_80367FE0.f4 - lbl_80367FE0.f0);
    h = (s16)(y1 - a1);
    sp10[0] = 0xFF;
    sp10[1] = 0xFF;
    sp10[2] = 0xFF;
    sp10[3] = sp8;
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)xfill, (f32)a1, (f32)w, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80367FE0.f0, (f32)lbl_80367FE0.f2,
                    (f32)(s16)(lbl_80367FE0.f4 - lbl_80367FE0.f0),
                    (f32)(s16)(lbl_80367FE0.f6 - lbl_80367FE0.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        spC = *(s32 *)sp10;
        Prim2D_SetColorPacked(&spC);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x46);
    w = (s16)(lbl_80367FE8.f4 - lbl_80367FE8.f0);
    sp10[0] = 0xFF;
    sp10[1] = 0xFF;
    sp10[2] = 0xFF;
    sp10[3] = sp8;
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)(s16)(xR - w), (f32)a1, (f32)w, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80367FE8.f0, (f32)lbl_80367FE8.f2,
                    (f32)(s16)(lbl_80367FE8.f4 - lbl_80367FE8.f0),
                    (f32)(s16)(lbl_80367FE8.f6 - lbl_80367FE8.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        spC = *(s32 *)sp10;
        Prim2D_SetColorPacked(&spC);
        Prim2D_EndPrim();
    }
    w = (s16)(lbl_80367FE0.f4 - lbl_80367FE0.f0);
    if ((s16)(xR - xfill) > (s32)(w * 2)) {
        s16 xl = (s16)(xfill + w);
        s16 wr = (s16)(lbl_80367FE8.f4 - lbl_80367FE8.f0);
        s16 xr = (s16)(xR - wr);
        sp10[0] = 0x38;
        sp10[1] = 0x1F;
        sp10[2] = 0x16;
        sp10[3] = sp8;
        Prim2D_Begin();
        Prim2D_SetTex(NULL, (u16)(fl | 2));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)xl, (f32)a1, (f32)(s16)(xr - xl), (f32)h);
        spC = *(s32 *)sp10;
        Prim2D_SetColorPacked(&spC);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(saved, sp14);
}

void fn_80157700(s16 x, s16 y, s32 a2, s32 flags) {
    void fn_80006B18(s32, s32, s32, s32, u8);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    s32 Msg_Expand(void *);
    void Text_Draw(s16, s16, s32, s32, ...);
    s32 Text_MeasureHeight(s32, f32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Ui_DrawRouteTexCw(s32, s32, s32);
    s32 *Ui_GetColor(s32);
    extern s32 gUiTexAtlas;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80368008;
    extern f32 lbl_8036A874;
    extern f32 lbl_8036A878;
    extern u8 gUiTexScratch[64];
    extern u8 lbl_802774F0[];
    int new_var2;
    f32 spC;
    long new_var3;
    s32 sp8;
    s32 str;
    s16 h;
    s16 w;
    s16 *rect;
    s32 saved;
    int new_var;
    long new_var4;

    saved = Prim2D_PushZ(&spC);
    Ui_LoadAtlasTex(gUiTexAtlas, (void *)gUiTexScratch, 0x49);
    rect = (s16 *)&lbl_80368008;
    h = (s16)(rect[3] - rect[1]);
    w = (s16)(rect[2] - lbl_80368008.f0);
    if (w != 0) {
        new_var2 = h != 0;
        if (new_var2) {
            Prim2D_Begin();
            Prim2D_SetTex((void *)gUiTexScratch, (u16)(flags | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80368008.f0, (f32)rect[1], (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A878);
    Prim2D_PrepareTex();
    flags = x;
    y = y;
    Ui_DrawRouteTexCw(0x18 + flags, y - 3, 0);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A878);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(NULL, 0x13);
    Prim2D_PrepareTex();
    new_var = rect[3] - rect[1];
    new_var4 = (s16)new_var;
    x = new_var4;
    x = (s16)((x - Text_MeasureHeight(-1, lbl_8036A874)) >> 1);
    str = Msg_Expand(lbl_802774F0 + 0x1f6);
    Text_Draw((s16)(flags + 0x40), (s16)(y + x), 0xF, str);
    Prim2D_AddPrim(6);
    sp8 = *Ui_GetColor(2);
    Prim2D_SetColorPacked(&sp8);
    fn_80006B18(0xC0 + flags, new_var3 = (y + x), 0, 0, (u8)a2);
    Prim2D_EndPrim();
    Prim2D_PopZ(saved, spC);
}

#pragma use_lmw_stmw on
void fn_80157930(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_SwapUvV(void);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(void *);
    void Prim2D_AddZ(f32);
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    void fn_80007358(f32, f32);
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C58;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C38;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C60;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C30;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C50;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C40;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C48;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80368050;
    extern u8 gUiTexScratch[64];
    extern s32 gUiTexAtlas;
    extern f32 lbl_8036A880;
    extern f32 lbl_8036A888;
    f32 sp14;
    s32 handle;
    u8 color[4];
    s16 x, y, x2, y2;
    s16 t14, t18, t19, t20;
    s16 w, h, px, py;
    s32 packed;
    s16 *p38;
    s16 *p58;

    x = arg0;
    y = arg1;
    x2 = (s16)(x + arg2);
    y2 = (s16)(y + arg3);
    p58 = (s16 *)&lbl_80367C58;
    p38 = (s16 *)&lbl_80367C38;

    {
        s16 h38 = (s16)(p38[3] - p38[1]);
        s16 w38 = (s16)(p38[2] - lbl_80367C38.f0);
        t18 = (s16)(y2 - (s16)(p58[3] - p58[1]));
        t19 = (s16)(x2 - (s16)(p58[2] - lbl_80367C58.f0));
        t20 = (s16)(y + h38);
        t14 = (s16)(x + w38);
    }

    handle = Prim2D_PushZ(&sp14);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 4);

    w = (s16)(p38[2] - lbl_80367C38.f0);
    h = (s16)(p38[3] - p38[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80367C38.f0, (f32)p38[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 9);
    w = (s16)(lbl_80367C60.f4 - lbl_80367C60.f0);
    h = (s16)(lbl_80367C60.f6 - lbl_80367C60.f2);
    px = (s16)(x2 - w);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367C60.f0, (f32)lbl_80367C60.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 3);
    w = (s16)(lbl_80367C30.f4 - lbl_80367C30.f0);
    h = (s16)(lbl_80367C30.f6 - lbl_80367C30.f2);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)py, (f32)lbl_80367C30.f0, (f32)lbl_80367C30.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 8);
    h = (s16)(p58[3] - p58[1]);
    w = (s16)(p58[2] - lbl_80367C58.f0);
    px = (s16)(x2 - w);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367C58.f0, (f32)p58[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 7);
    t19 = (s16)(t19 - t14);
    h = (s16)(lbl_80367C50.f6 - lbl_80367C50.f2);
    px = (s16)(x + (s16)(p38[2] - lbl_80367C38.f0));
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367C50.f0, (f32)lbl_80367C50.f2, (f32)t19, (f32)h);
        Prim2D_EndPrim();
    }

    h = (s16)(lbl_80367C50.f6 - lbl_80367C50.f2);
    px = (s16)(x + (s16)(lbl_80367C30.f4 - lbl_80367C30.f0));
    py = (s16)(y2 - h);
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367C50.f0, (f32)lbl_80367C50.f2, (f32)t19, (f32)h);
        Prim2D_SwapUvV();
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 5);
    t18 = (s16)(t18 - t20);
    w = (s16)(lbl_80367C40.f4 - lbl_80367C40.f0);
    py = (s16)(y + (s16)(p38[3] - p38[1]));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x + 1), (f32)py, (f32)lbl_80367C40.f0, (f32)lbl_80367C40.f2, (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 6);
    w = (s16)(lbl_80367C48.f4 - lbl_80367C48.f0);
    py = (s16)(y + (s16)(lbl_80367C60.f6 - lbl_80367C60.f2));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)((x2 - w) - 1), (f32)py, (f32)lbl_80367C48.f0, (f32)lbl_80367C48.f2, (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    px = (s16)(x + 1);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x66);
    h = (s16)(y2 - y);
    w = (s16)(lbl_80368050.f4 - lbl_80368050.f0);
    color[0] = 0xFF;
    color[1] = 0xFF;
    color[2] = 0xFF;
    color[3] = arg4;
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)px, (f32)y, (f32)w, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80368050.f0, (f32)lbl_80368050.f2,
                    (f32)(s16)(lbl_80368050.f4 - lbl_80368050.f0),
                    (f32)(s16)(lbl_80368050.f6 - lbl_80368050.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        packed = *(s32 *)color;
        Prim2D_SetColorPacked(&packed);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(handle, sp14);
}
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
void fn_801583D0(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    s32 fn_80009E44(f32 *);
    void fn_80009E64(s32, f32);
    void fn_80009C0C(f32);
    void fn_8000A174(void *, u16);
    void fn_8000A248(void);
    void fn_8000A258(void);
    void fn_80007668(s32 *);
    void fn_8000770C(f32, f32, f32, f32, f32, f32);
    void fn_800077D8(f32, f32, f32, f32);
    void fn_80007884(void);
    void fn_80007898(s32);
    void fn_8006ECCC(s32, void *, s32);
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DB8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DC0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DC8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DD0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DD8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DE0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DE8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DF0;
    extern u8 lbl_80330D18[64];
    extern s32 lbl_803680C8;
    extern f32 lbl_8036A888;

    f32 sp14;
    u8 sp10[4];
    s32 spC;
    u8 sp8;
    s32 saved;
    s16 x1;
    s16 y1;
    s16 w;
    s16 h;
    s16 t14;
    s16 t19;
    s16 t20;
    s16 dw;
    s16 dh;
    s16 xfill;

    sp8 = arg4;
    x1 = (s16)(arg0 + arg2);
    y1 = (s16)(arg1 + arg3);
    w = (s16)(lbl_80367DE8.f4 - lbl_80367DE8.f0);
    h = (s16)(lbl_80367DE8.f6 - lbl_80367DE8.f2);
    t19 = (s16)(x1 - w);
    dh = (s16)(y1 - h);
    t14 = (s16)(arg0 + (s16)(lbl_80367DC0.f4 - lbl_80367DC0.f0));
    t20 = (s16)(arg1 + (s16)(lbl_80367DC0.f6 - lbl_80367DC0.f2));
    saved = fn_80009E44(&sp14);
    fn_8006ECCC(lbl_803680C8, lbl_80330D18, 0x57);
    w = (s16)(lbl_80367DC0.f4 - lbl_80367DC0.f0);
    h = (s16)(lbl_80367DC0.f6 - lbl_80367DC0.f2);
    if (w != 0 && h != 0) {
        fn_8000A258();
        fn_8000A174(lbl_80330D18, (u16)(arg5 | 1));
        fn_8000A248();
        fn_80007898(1);
        fn_8000770C((f32)arg0, (f32)arg1, (f32)lbl_80367DC0.f0, (f32)lbl_80367DC0.f2, (f32)w, (f32)h);
        fn_80007884();
    }
    fn_8006ECCC(lbl_803680C8, lbl_80330D18, 0x5D);
    w = (s16)(lbl_80367DF0.f4 - lbl_80367DF0.f0);
    h = (s16)(lbl_80367DF0.f6 - lbl_80367DF0.f2);
    if (w != 0 && h != 0) {
        fn_8000A258();
        fn_8000A174(lbl_80330D18, (u16)(arg5 | 1));
        fn_8000A248();
        fn_80007898(1);
        fn_8000770C((f32)(s16)(x1 - w), (f32)arg1, (f32)lbl_80367DF0.f0, (f32)lbl_80367DF0.f2, (f32)w, (f32)h);
        fn_80007884();
    }
    fn_8006ECCC(lbl_803680C8, lbl_80330D18, 0x56);
    w = (s16)(lbl_80367DB8.f4 - lbl_80367DB8.f0);
    h = (s16)(lbl_80367DB8.f6 - lbl_80367DB8.f2);
    if (w != 0 && h != 0) {
        fn_8000A258();
        fn_8000A174(lbl_80330D18, (u16)(arg5 | 1));
        fn_8000A248();
        fn_80007898(1);
        fn_8000770C((f32)arg0, (f32)(s16)(y1 - h), (f32)lbl_80367DB8.f0, (f32)lbl_80367DB8.f2, (f32)w, (f32)h);
        fn_80007884();
    }
    fn_8006ECCC(lbl_803680C8, lbl_80330D18, 0x5C);
    w = (s16)(lbl_80367DE8.f4 - lbl_80367DE8.f0);
    h = (s16)(lbl_80367DE8.f6 - lbl_80367DE8.f2);
    if (w != 0 && h != 0) {
        fn_8000A258();
        fn_8000A174(lbl_80330D18, (u16)(arg5 | 1));
        fn_8000A248();
        fn_80007898(1);
        fn_8000770C((f32)(s16)(x1 - w), (f32)(s16)(y1 - h), (f32)lbl_80367DE8.f0, (f32)lbl_80367DE8.f2, (f32)w, (f32)h);
        fn_80007884();
    }
    fn_8006ECCC(lbl_803680C8, lbl_80330D18, 0x5A);
    dw = (s16)(t19 - t14);
    h = (s16)(lbl_80367DD8.f6 - lbl_80367DD8.f2);
    t14 = (s16)(arg0 + (s16)(lbl_80367DC0.f4 - lbl_80367DC0.f0));
    if (dw != 0 && h != 0) {
        fn_8000A258();
        fn_8000A174(lbl_80330D18, (u16)(arg5 | 1));
        fn_8000A248();
        fn_80007898(1);
        fn_8000770C((f32)t14, (f32)arg1, (f32)lbl_80367DD8.f0, (f32)lbl_80367DD8.f2, (f32)dw, (f32)h);
        fn_80007884();
    }
    fn_8006ECCC(lbl_803680C8, lbl_80330D18, 0x5B);
    h = (s16)(lbl_80367DE0.f6 - lbl_80367DE0.f2);
    t14 = (s16)(arg0 + (s16)(lbl_80367DB8.f4 - lbl_80367DB8.f0));
    if (dw != 0 && h != 0) {
        fn_8000A258();
        fn_8000A174(lbl_80330D18, (u16)(arg5 | 1));
        fn_8000A248();
        fn_80007898(1);
        fn_8000770C((f32)t14, (f32)(s16)(y1 - h), (f32)lbl_80367DE0.f0, (f32)lbl_80367DE0.f2, (f32)dw, (f32)h);
        fn_80007884();
    }
    fn_8006ECCC(lbl_803680C8, lbl_80330D18, 0x58);
    dh = (s16)(dh - t20);
    w = (s16)(lbl_80367DC8.f4 - lbl_80367DC8.f0);
    t14 = (s16)(arg1 + (s16)(lbl_80367DC0.f6 - lbl_80367DC0.f2));
    if (w != 0 && dh != 0) {
        fn_8000A258();
        fn_8000A174(lbl_80330D18, (u16)(arg5 | 1));
        fn_8000A248();
        fn_80007898(1);
        fn_8000770C((f32)(s16)(arg0 + 1), (f32)t14, (f32)lbl_80367DC8.f0, (f32)lbl_80367DC8.f2, (f32)w, (f32)dh);
        fn_80007884();
    }
    fn_8006ECCC(lbl_803680C8, lbl_80330D18, 0x59);
    w = (s16)(lbl_80367DD0.f4 - lbl_80367DD0.f0);
    t14 = (s16)(arg1 + (s16)(lbl_80367DF0.f6 - lbl_80367DF0.f2));
    if (w != 0 && dh != 0) {
        fn_8000A258();
        fn_8000A174(lbl_80330D18, (u16)(arg5 | 1));
        fn_8000A248();
        fn_80007898(1);
        fn_8000770C((f32)(s16)((x1 - w) - 1), (f32)t14, (f32)lbl_80367DD0.f0, (f32)lbl_80367DD0.f2, (f32)w, (f32)dh);
        fn_80007884();
    }
    fn_8000A258();
    fn_80009C0C(lbl_8036A888);
    fn_8000A248();
    xfill = (s16)(arg0 + 1);
    sp10[0] = 0x24;
    sp10[1] = 0x16;
    sp10[2] = 3;
    sp10[3] = sp8;
    fn_8000A258();
    fn_8000A174(NULL, (u16)(arg5 | 2));
    fn_8000A248();
    fn_80007898(1);
    fn_800077D8((f32)xfill, (f32)arg1, (f32)(s16)((s16)(x1 - 1) - xfill), (f32)(s16)(y1 - arg1));
    spC = *(s32 *)sp10;
    fn_80007668(&spC);
    fn_80007884();
    fn_80009E64(saved, sp14);
}

#pragma use_lmw_stmw on
void fn_80158DD8(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_SwapUvU(void);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void fn_80007358(f32, f32);
    void Prim2D_SetColorPacked(void *);
    void Prim2D_AddZ(f32);
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E28;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E00;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E30;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DF8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E18;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E20;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E08;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E10;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80368028;
    extern u8 gUiTexScratch[64];
    extern s32 gUiTexAtlas;
    extern f32 lbl_8036A888;
    extern f32 lbl_8036A880;
    f32 sp14;
    s32 handle;
    u8 color[4];
    s16 x, y, x2, y2;
    s16 t14, t18, t19, t20;
    s16 w, h, px, py;
    s32 packed;
    s16 *p38;
    s16 *p58;

    p58 = (s16 *)&lbl_80367E28;
    x = arg0;
    p38 = (s16 *)&lbl_80367E00;
    y = arg1;
    x2 = (s16)(x + arg2);
    y2 = (s16)(y + arg3);

    {
        s16 h38 = (s16)(p38[3] - p38[1]);
        s16 w38 = (s16)(p38[2] - lbl_80367E00.f0);
        t18 = (s16)(y2 - (s16)(p58[3] - p58[1]));
        t19 = (s16)(x2 - (s16)(p58[2] - lbl_80367E28.f0));
        t20 = (s16)(y + h38);
        t14 = (s16)(x + w38);
    }

    handle = Prim2D_PushZ(&sp14);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x5F);

    w = (s16)(p38[2] - lbl_80367E00.f0);
    h = (s16)(p38[3] - p38[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80367E00.f0, (f32)p38[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x65);
    w = (s16)(lbl_80367E30.f4 - lbl_80367E30.f0);
    h = (s16)(lbl_80367E30.f6 - lbl_80367E30.f2);
    px = (s16)(x2 - w);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367E30.f0, (f32)lbl_80367E30.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x5E);
    w = (s16)(lbl_80367DF8.f4 - lbl_80367DF8.f0);
    h = (s16)(lbl_80367DF8.f6 - lbl_80367DF8.f2);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)py, (f32)lbl_80367DF8.f0, (f32)lbl_80367DF8.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x64);
    h = (s16)(p58[3] - p58[1]);
    w = (s16)(p58[2] - lbl_80367E28.f0);
    px = (s16)(x2 - w);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367E28.f0, (f32)p58[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x62);
    t19 = (s16)(t19 - t14);
    h = (s16)(lbl_80367E18.f6 - lbl_80367E18.f2);
    px = (s16)(x + (s16)(p38[2] - lbl_80367E00.f0));
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)(s16)(arg1 + 4), (f32)lbl_80367E18.f0, (f32)lbl_80367E18.f2, (f32)t19, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x63);
    h = (s16)(lbl_80367E20.f6 - lbl_80367E20.f2);
    px = (s16)(x + (s16)(lbl_80367DF8.f4 - lbl_80367DF8.f0));
    py = (s16)((y2 - h) - 4);
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367E20.f0, (f32)lbl_80367E20.f2, (f32)t19, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x60);
    t18 = (s16)(t18 - t20);
    w = (s16)(lbl_80367E08.f4 - lbl_80367E08.f0);
    py = (s16)(y + (s16)(p38[3] - p38[1]));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)py, (f32)lbl_80367E08.f0, (f32)lbl_80367E08.f2, (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x61);
    w = (s16)(lbl_80367E10.f4 - lbl_80367E10.f0);
    py = (s16)(y + (s16)(lbl_80367E30.f6 - lbl_80367E30.f2));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x2 - w), (f32)py, (f32)lbl_80367E10.f0, (f32)lbl_80367E10.f2, (f32)w, (f32)t18);
        Prim2D_SwapUvU();
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    py = (s16)(arg1 + 4);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x66);
    w = (s16)(lbl_80368028.f4 - lbl_80368028.f0);
    h = (s16)((s16)(y2 - 4) - py);
    color[0] = 0xFF;
    color[1] = 0xFF;
    color[2] = 0xFF;
    color[3] = arg4;
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)arg0, (f32)py, (f32)w, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80368028.f0, (f32)lbl_80368028.f2,
                    (f32)(s16)(lbl_80368028.f4 - lbl_80368028.f0),
                    (f32)(s16)(lbl_80368028.f6 - lbl_80368028.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        packed = *(s32 *)color;
        Prim2D_SetColorPacked(&packed);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(handle, sp14);
}
void fn_80159898(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s8 arg4, s32 arg5) {
    void Prim2D_SetCornerColors(s32 *, s32 *, s32 *, s32 *, s32, s32, s32);
    void Prim2D_EmitQuad(void);
    void Prim2D_SwapUvU(void);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void *Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(void *, f32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Ui_LoadAtlasTex(s32, void *, s32);
    extern s32 gUiTexAtlas;
    extern u8 lbl_80330CE8[0x40];
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DF8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E00;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E08;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E10;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E18;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E20;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E28;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E30;
    extern f32 lbl_8036A888;
    s32 col[8];
    f32 zsave;
    s16 sp60, sp62, sp64;
    s16 *pRM;
    s16 *pLM;
    s16 *pBM;
    s16 *pTM;
    s16 *pBL;
    s16 *pTR;
    u8 *base;
    s16 *pTL;
    s16 *pBR;
    s16 w, h;
    s16 midW, midH;
    s16 xa, ya;
    s16 x2, y2;
    s16 sx, sy;
    s8 alpha;
    s32 flags;
    void *saved;
    s32 c0, c1, c2, c3;
    s16 edgeBot;

    pBR = (s16 *)&lbl_80367E28;
    sx = arg0;
    pTL = (s16 *)&lbl_80367E00;
    {
        s32 t1 = sx + arg2;
        sy = arg1;
        {
            s32 t2 = sy + arg3;
            alpha = arg4;
            x2 = (s16)t1;
            flags = arg5;
            y2 = (s16)t2;
        }
    }
    base = lbl_80330CE8;

    w = (s16)(pBR[2] - lbl_80367E28.f0);
    h = (s16)(pBR[3] - pBR[1]);
    sp60 = (s16)(x2 - w);
    edgeBot = (s16)(y2 - h);
    sp62 = (s16)(sy + (s16)(pTL[3] - pTL[1]));
    sp64 = (s16)(sx + (s16)(pTL[2] - lbl_80367E00.f0));
    saved = Prim2D_PushZ(&zsave);

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x5F);
    w = (s16)(pTL[2] - lbl_80367E00.f0);
    h = (s16)(pTL[3] - pTL[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)sx, (f32)sy, (f32)lbl_80367E00.f0, (f32)pTL[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x65);
    pTR = (s16 *)&lbl_80367E30;
    w = (s16)(pTR[2] - lbl_80367E30.f0);
    h = (s16)(pTR[3] - pTR[1]);
    xa = (s16)(x2 - w);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)sy, (f32)lbl_80367E30.f0, (f32)pTR[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x5E);
    pBL = (s16 *)&lbl_80367DF8;
    w = (s16)(pBL[2] - lbl_80367DF8.f0);
    h = (s16)(pBL[3] - pBL[1]);
    ya = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)sx, (f32)ya, (f32)lbl_80367DF8.f0, (f32)pBL[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x64);
    w = (s16)(pBR[2] - lbl_80367E28.f0);
    h = (s16)(pBR[3] - pBR[1]);
    xa = (s16)(x2 - w);
    ya = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)ya, (f32)lbl_80367E28.f0, (f32)pBR[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x62);
    midW = (s16)(sp60 - sp64);
    pTM = (s16 *)&lbl_80367E18;
    h = (s16)(pTM[3] - pTM[1]);
    xa = (s16)(sx + (s16)(pTL[2] - lbl_80367E00.f0));
    if (midW != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)(s16)(sy + 4), (f32)lbl_80367E18.f0, (f32)pTM[1], (f32)midW, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x63);
    pBM = (s16 *)&lbl_80367E20;
    h = (s16)(pBM[3] - pBM[1]);
    xa = (s16)(sx + (s16)(pBL[2] - lbl_80367DF8.f0));
    ya = (s16)((s16)(y2 - h) - 4);
    if (midW != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)ya, (f32)lbl_80367E20.f0, (f32)pBM[1], (f32)midW, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x60);
    midH = (s16)(edgeBot - sp62);
    pLM = (s16 *)&lbl_80367E08;
    w = (s16)(pLM[2] - lbl_80367E08.f0);
    ya = (s16)(sy + (s16)(pTL[3] - pTL[1]));
    if (w != 0 && midH != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)sx, (f32)ya, (f32)lbl_80367E08.f0, (f32)pLM[1], (f32)w, (f32)midH);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x61);
    pRM = (s16 *)&lbl_80367E10;
    w = (s16)(pRM[2] - lbl_80367E10.f0);
    ya = (s16)(sy + (s16)(pTR[3] - pTR[1]));
    xa = (s16)(x2 - w);
    if (w != 0 && midH != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)ya, (f32)lbl_80367E10.f0, (f32)pRM[1], (f32)w, (f32)midH);
        Prim2D_SwapUvU();
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    {
        u8 *p20 = base + 0x20;
        u8 *p10 = base + 0x10;
        s16 yBot = (s16)(y2 - 4);
        s16 yTop = (s16)(sy + 4);
        p20[3] = alpha;
        p10[3] = alpha;
        p20[7] = alpha;
        p10[7] = alpha;
        p20[0xB] = alpha;
        p10[0xB] = alpha;
        p20[0xF] = alpha;
        p10[0xF] = alpha;
        Prim2D_Begin();
        Prim2D_SetTex(NULL, (u16)(flags | 2));
        Prim2D_PrepareTex();
        c0 = ((s32 *)(base + 0x20))[0];
        c1 = ((s32 *)(base + 0x20))[1];
        c2 = ((s32 *)(base + 0x20))[2];
        c3 = ((s32 *)(base + 0x20))[3];
        col[0] = c0; col[1] = c1; col[2] = c2; col[3] = c3;
        Prim2D_AddPrim(3);
        Prim2D_SetRect((f32)sx, (f32)yTop, (f32)(s16)(x2 - sx), (f32)(s16)(yBot - yTop));
        Prim2D_EmitQuad();
        col[7] = col[3]; col[6] = col[2]; col[5] = col[1]; col[4] = col[0];
        Prim2D_SetCornerColors(&col[4], &col[5], &col[6], &col[7], col[1], col[2], col[3]);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(saved, zsave);
}
#pragma use_lmw_stmw reset
void fn_8015A2D8(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_SwapUvV(void);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(void *);
    void Prim2D_AddZ(f32);
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DA8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367D80;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DB0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367D78;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367D98;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DA0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367D88;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367D90;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80368000;
    extern u8 gUiTexScratch[64];
    extern s32 gUiTexAtlas;
    extern f32 lbl_8036A888;
    f32 sp14;
    s32 handle;
    u8 color[4];
    s16 x, y, x2, y2;
    s16 t14, t18, t19, t20;
    s16 w, h, px, py;
    s32 packed;
    s16 *p38;
    s16 *p58;

    p58 = (s16 *)&lbl_80367DA8;
    x = arg0;
    p38 = (s16 *)&lbl_80367D80;
    y = arg1;
    x2 = (s16)(x + arg2);
    y2 = (s16)(y + arg3);

    {
        s16 h38 = (s16)(p38[3] - p38[1]);
        s16 w38 = (s16)(p38[2] - lbl_80367D80.f0);
        t18 = (s16)(y2 - (s16)(p58[3] - p58[1]));
        t19 = (s16)(x2 - (s16)(p58[2] - lbl_80367DA8.f0));
        t20 = (s16)(y + h38);
        t14 = (s16)(x + w38);
    }

    handle = Prim2D_PushZ(&sp14);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x4E);

    w = (s16)(p38[2] - lbl_80367D80.f0);
    h = (s16)(p38[3] - p38[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80367D80.f0, (f32)p38[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x54);
    w = (s16)(lbl_80367DB0.f4 - lbl_80367DB0.f0);
    h = (s16)(lbl_80367DB0.f6 - lbl_80367DB0.f2);
    px = (s16)(x2 - w);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367DB0.f0, (f32)lbl_80367DB0.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x4D);
    w = (s16)(lbl_80367D78.f4 - lbl_80367D78.f0);
    h = (s16)(lbl_80367D78.f6 - lbl_80367D78.f2);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)py, (f32)lbl_80367D78.f0, (f32)lbl_80367D78.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x53);
    h = (s16)(p58[3] - p58[1]);
    w = (s16)(p58[2] - lbl_80367DA8.f0);
    px = (s16)(x2 - w);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367DA8.f0, (f32)p58[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x51);
    t19 = (s16)(t19 - t14);
    h = (s16)(lbl_80367D98.f6 - lbl_80367D98.f2);
    px = (s16)(x + (s16)(p38[2] - lbl_80367D80.f0));
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367D98.f0, (f32)lbl_80367D98.f2, (f32)t19, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x52);
    h = (s16)(lbl_80367DA0.f6 - lbl_80367DA0.f2);
    px = (s16)(x + (s16)(lbl_80367D78.f4 - lbl_80367D78.f0));
    py = (s16)(y2 - h);
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367DA0.f0, (f32)lbl_80367DA0.f2, (f32)t19, (f32)h);
        Prim2D_SwapUvV();
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x4F);
    t18 = (s16)(t18 - t20);
    w = (s16)(lbl_80367D88.f4 - lbl_80367D88.f0);
    py = (s16)(y + (s16)(p38[3] - p38[1]));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x + 1), (f32)py, (f32)lbl_80367D88.f0, (f32)lbl_80367D88.f2, (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x50);
    w = (s16)(lbl_80367D90.f4 - lbl_80367D90.f0);
    py = (s16)(y + (s16)(lbl_80367DB0.f6 - lbl_80367DB0.f2));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)((x2 - w) - 1), (f32)py, (f32)lbl_80367D90.f0, (f32)lbl_80367D90.f2, (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    px = (s16)(x + 1);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x74);
    h = (s16)(y2 - y);
    w = (s16)((s16)(x2 - 1) - px);
    color[0] = 0xFF;
    color[1] = 0xFF;
    color[2] = 0xFF;
    color[3] = arg4;
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)px, (f32)y, (f32)w, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80368000.f0, (f32)lbl_80368000.f2,
                    (f32)(s16)(lbl_80368000.f4 - lbl_80368000.f0),
                    (f32)(s16)(lbl_80368000.f6 - lbl_80368000.f2));
        packed = *(s32 *)color;
        Prim2D_SetColorPacked(&packed);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(handle, sp14);
}

#pragma use_lmw_stmw on
void Ui_DrawListWindowFrame(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_AddZ(f32);
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DA8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367D80;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DB0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367D78;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367D98;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367DA0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367D88;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367D90;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80368000;
    extern u8 gUiTexScratch[64];
    extern s32 gUiTexAtlas;
    extern f32 lbl_8036A888;
    extern f64 lbl_8036A868;
    f32 sp14;
    u8 sp10[4];
    s32 spC;
    u8 sp8;
    s32 handle;
    s16 x, y, x2, y2;
    s16 t14, t18, t19, t20;
    s16 w, h, px, py;
    s16 *p38;
    s16 *p58;
    s16 *pDB0;
    f64 magic;

    magic = lbl_8036A868;
    (void)magic;
    sp8 = arg4;
    sp10[3] = arg4;
    x = arg0;
    y = arg1;
    x2 = (s16)(x + arg2);
    y2 = (s16)(y + arg3);
    p58 = (s16 *)&lbl_80367DA8;
    p38 = (s16 *)&lbl_80367D80;

    {
        s16 h38 = (s16)(p38[3] - p38[1]);
        s16 w38 = (s16)(p38[2] - lbl_80367D80.f0);
        t18 = (s16)(y2 - (s16)(p58[3] - p58[1]));
        t19 = (s16)(x2 - (s16)(p58[2] - lbl_80367DA8.f0));
        t20 = (s16)(y + h38);
        t14 = (s16)(x + w38);
    }

    handle = Prim2D_PushZ(&sp14);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x4E);

    h = (s16)(p38[3] - p38[1]);
    w = (s16)(p38[2] - lbl_80367D80.f0);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80367D80.f0, (f32)p38[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x54);
    pDB0 = (s16 *)&lbl_80367DB0;
    w = (s16)(pDB0[2] - lbl_80367DB0.f0);
    px = (s16)(x2 - w);
    h = (s16)(pDB0[3] - pDB0[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367DB0.f0, (f32)pDB0[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x4D);
    h = (s16)(lbl_80367D78.f6 - lbl_80367D78.f2);
    w = (s16)(lbl_80367D78.f4 - lbl_80367D78.f0);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)py, (f32)lbl_80367D78.f0, (f32)lbl_80367D78.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x53);
    h = (s16)(p58[3] - p58[1]);
    w = (s16)(p58[2] - lbl_80367DA8.f0);
    px = (s16)(x2 - w);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367DA8.f0, (f32)p58[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x51);
    t19 = (s16)(t19 - t14);
    h = (s16)(lbl_80367D98.f6 - lbl_80367D98.f2);
    px = (s16)(x + (s16)(p38[2] - lbl_80367D80.f0));
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367D98.f0, (f32)lbl_80367D98.f2, (f32)t19, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x52);
    h = (s16)(lbl_80367DA0.f6 - lbl_80367DA0.f2);
    px = (s16)(x + (s16)(lbl_80367D78.f4 - lbl_80367D78.f0));
    py = (s16)(y2 - h);
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367DA0.f0, (f32)lbl_80367DA0.f2, (f32)t19, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x4F);
    t18 = (s16)(t18 - t20);
    w = (s16)(lbl_80367D88.f4 - lbl_80367D88.f0);
    py = (s16)(y + (s16)(p38[3] - p38[1]));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x + 1), (f32)py, (f32)lbl_80367D88.f0, (f32)lbl_80367D88.f2, (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x50);
    w = (s16)(lbl_80367D90.f4 - lbl_80367D90.f0);
    py = (s16)(y + (s16)(pDB0[3] - pDB0[1]));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)((x2 - w) - 1), (f32)py, (f32)lbl_80367D90.f0, (f32)lbl_80367D90.f2, (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    px = (s16)(x + 1);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x55);
    h = (s16)(y2 - y);
    w = (s16)((s16)(x2 - 1) - px);
    sp10[0] = 0xFF;
    sp10[1] = 0xFF;
    sp10[2] = 0xFF;
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)px, (f32)y, (f32)w, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80368000.f0, (f32)lbl_80368000.f2,
                    (f32)(s16)(lbl_80368000.f4 - lbl_80368000.f0),
                    (f32)(s16)(lbl_80368000.f6 - lbl_80368000.f2));
        spC = *(s32 *)sp10;
        Prim2D_SetColorPacked(&spC);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(handle, sp14);
}

void fn_8015B820(s16 arg0, s16 arg1, s32 arg2) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367BD8;
    s16 h;
    s16 w;

    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, 0x76);
    h = (s16)(lbl_80367BD8.f6 - lbl_80367BD8.f2);
    w = (s16)(lbl_80367BD8.f4 - lbl_80367BD8.f0);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg2 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)arg1, (f32)lbl_80367BD8.f0, (f32)lbl_80367BD8.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
}

/* Draws UI atlas tile 0x75 (gUiAtlasRect75) at (x, y) if its UV size is non-zero. */
void Ui_DrawAtlasRect75(s16 x, s16 y, s32 texFlags) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } gUiAtlasRect75;
    s16 h;
    s16 w;

    Ui_LoadAtlasTex(gUiTexAtlas, (void *)&gUiTexScratch, 0x75);
    h = (s16)(gUiAtlasRect75.f6 - gUiAtlasRect75.f2);
    w = (s16)(gUiAtlasRect75.f4 - gUiAtlasRect75.f0);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(texFlags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)gUiAtlasRect75.f0, (f32)gUiAtlasRect75.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
}

void fn_8015BA88(void) {
    M2C_UNK Ui_DrawWindowFrame();
    Ui_DrawWindowFrame();
}

#pragma use_lmw_stmw on
void fn_8015BAA8(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddZ(f32);
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    void fn_80007358(f32, f32);
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367EF8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367ED0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367F00;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367EC8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367EE8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367EF0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367ED8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367EE0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367F08;
    extern u8 gUiTexScratch[64];
    extern s32 gUiTexAtlas;
    extern f32 lbl_8036A880;
    extern f32 lbl_8036A888;
    s32 saved;
    f32 sp8;
    s16 x, y, x2, y2;
    s16 t14, t19, t20, t21;
    s16 w, h, dw, dh;
    s16 *p58;
    s16 *p38;

    x = arg0;
    y = arg1;
    x2 = (s16)(x + arg2);
    y2 = (s16)(y + arg3);
    p58 = (s16 *)&lbl_80367EF8;
    p38 = (s16 *)&lbl_80367ED0;

    {
        s16 h38 = (s16)(p38[3] - p38[1]);
        s16 w38 = (s16)(p38[2] - lbl_80367ED0.f0);
        t21 = (s16)(y2 - (s16)(p58[3] - p58[1]));
        t19 = (s16)(x2 - (s16)(p58[2] - lbl_80367EF8.f0));
        dh = (s16)(y + h38);
        t20 = (s16)(x + w38);
    }

    saved = Prim2D_PushZ(&sp8);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x98);

    w = (s16)(p38[2] - lbl_80367ED0.f0);
    h = (s16)(p38[3] - p38[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80367ED0.f0, (f32)p38[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x9E);
    w = (s16)(lbl_80367F00.f4 - lbl_80367F00.f0);
    h = (s16)(lbl_80367F00.f6 - lbl_80367F00.f2);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x2 - w), (f32)y, (f32)lbl_80367F00.f0, (f32)lbl_80367F00.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x97);
    w = (s16)(lbl_80367EC8.f4 - lbl_80367EC8.f0);
    h = (s16)(lbl_80367EC8.f6 - lbl_80367EC8.f2);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)(s16)(y2 - h), (f32)lbl_80367EC8.f0, (f32)lbl_80367EC8.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x9D);
    h = (s16)(p58[3] - p58[1]);
    w = (s16)(p58[2] - lbl_80367EF8.f0);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x2 - w), (f32)(s16)(y2 - h), (f32)lbl_80367EF8.f0, (f32)p58[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x9B);
    dw = (s16)(t19 - t20);
    h = (s16)(lbl_80367EE8.f6 - lbl_80367EE8.f2);
    t14 = (s16)(x + (s16)(p38[2] - lbl_80367ED0.f0));
    if (dw != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)t14, (f32)(s16)(y + 1), (f32)dw, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80367EE8.f0, (f32)lbl_80367EE8.f2,
                    (f32)(s16)(lbl_80367EE8.f4 - lbl_80367EE8.f0),
                    (f32)(s16)(lbl_80367EE8.f6 - lbl_80367EE8.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x9C);
    h = (s16)(lbl_80367EF0.f6 - lbl_80367EF0.f2);
    t14 = (s16)(x + (s16)(lbl_80367EC8.f4 - lbl_80367EC8.f0));
    if (dw != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)t14, (f32)(s16)(y2 - h), (f32)dw, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80367EF0.f0, (f32)lbl_80367EF0.f2,
                    (f32)(s16)(lbl_80367EF0.f4 - lbl_80367EF0.f0),
                    (f32)(s16)(lbl_80367EF0.f6 - lbl_80367EF0.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x99);
    t14 = (s16)(y + (s16)(p38[3] - p38[1]));
    dh = (s16)(dh - t21);
    w = (s16)(lbl_80367ED8.f4 - lbl_80367ED8.f0);
    if (w != 0 && dh != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)(s16)(x + 2), (f32)t14, (f32)w, (f32)dh);
        Prim2D_SetUvRect((f32)lbl_80367ED8.f0, (f32)lbl_80367ED8.f2,
                    (f32)(s16)(lbl_80367ED8.f4 - lbl_80367ED8.f0),
                    (f32)(s16)(lbl_80367ED8.f6 - lbl_80367ED8.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x9A);
    w = (s16)(lbl_80367EE0.f4 - lbl_80367EE0.f0);
    t14 = (s16)(y + (s16)(lbl_80367F00.f6 - lbl_80367F00.f2));
    if (w != 0 && dh != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)(s16)(x2 - w), (f32)t14, (f32)w, (f32)dh);
        Prim2D_SetUvRect((f32)lbl_80367EE0.f0, (f32)lbl_80367EE0.f2,
                    (f32)(s16)(lbl_80367EE0.f4 - lbl_80367EE0.f0),
                    (f32)(s16)(lbl_80367EE0.f6 - lbl_80367EE0.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x9F);
    if (dw != 0 && dh != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)t20, (f32)t21, (f32)dw, (f32)dh);
        Prim2D_SetUvRect((f32)lbl_80367F08.f0, (f32)lbl_80367F08.f2,
                    (f32)(s16)(lbl_80367F08.f4 - lbl_80367F08.f0),
                    (f32)(s16)(lbl_80367F08.f6 - lbl_80367F08.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(saved, sp8);
}

#pragma use_lmw_stmw on
void fn_8015C674(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddZ(f32);
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    void fn_80007358(f32, f32);
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367EB0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E88;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367EB8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E80;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367EA0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367EA8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E90;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367E98;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367EC0;
    extern u8 gUiTexScratch[64];
    extern s32 gUiTexAtlas;
    extern f32 lbl_8036A880;
    extern f32 lbl_8036A888;
    s32 saved;
    f32 sp8;
    s16 x, y, x2, y2;
    s16 t14, t19, t20, t21;
    s16 w, h, dw, dh;
    s16 *p58;
    s16 *p38;

    x = arg0;
    y = arg1;
    x2 = (s16)(x + arg2);
    y2 = (s16)(y + arg3);
    p58 = (s16 *)&lbl_80367EB0;
    p38 = (s16 *)&lbl_80367E88;

    {
        s16 h38 = (s16)(p38[3] - p38[1]);
        s16 w38 = (s16)(p38[2] - lbl_80367E88.f0);
        t21 = (s16)(y2 - (s16)(p58[3] - p58[1]));
        t19 = (s16)(x2 - (s16)(p58[2] - lbl_80367EB0.f0));
        dh = (s16)(y + h38);
        t20 = (s16)(x + w38);
    }

    saved = Prim2D_PushZ(&sp8);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x8F);

    w = (s16)(p38[2] - lbl_80367E88.f0);
    h = (s16)(p38[3] - p38[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80367E88.f0, (f32)p38[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x95);
    w = (s16)(lbl_80367EB8.f4 - lbl_80367EB8.f0);
    h = (s16)(lbl_80367EB8.f6 - lbl_80367EB8.f2);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x2 - w), (f32)y, (f32)lbl_80367EB8.f0, (f32)lbl_80367EB8.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x8E);
    w = (s16)(lbl_80367E80.f4 - lbl_80367E80.f0);
    h = (s16)(lbl_80367E80.f6 - lbl_80367E80.f2);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)(s16)(y2 - h), (f32)lbl_80367E80.f0, (f32)lbl_80367E80.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x94);
    h = (s16)(p58[3] - p58[1]);
    w = (s16)(p58[2] - lbl_80367EB0.f0);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x2 - w), (f32)(s16)(y2 - h), (f32)lbl_80367EB0.f0, (f32)p58[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x92);
    dw = (s16)(t19 - t20);
    h = (s16)(lbl_80367EA0.f6 - lbl_80367EA0.f2);
    t14 = (s16)(x + (s16)(p38[2] - lbl_80367E88.f0));
    if (dw != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)t14, (f32)(s16)(y + 1), (f32)dw, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80367EA0.f0, (f32)lbl_80367EA0.f2,
                    (f32)(s16)(lbl_80367EA0.f4 - lbl_80367EA0.f0),
                    (f32)(s16)(lbl_80367EA0.f6 - lbl_80367EA0.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x93);
    h = (s16)(lbl_80367EA8.f6 - lbl_80367EA8.f2);
    t14 = (s16)(x + (s16)(lbl_80367E80.f4 - lbl_80367E80.f0));
    if (dw != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)t14, (f32)(s16)(y2 - h), (f32)dw, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80367EA8.f0, (f32)lbl_80367EA8.f2,
                    (f32)(s16)(lbl_80367EA8.f4 - lbl_80367EA8.f0),
                    (f32)(s16)(lbl_80367EA8.f6 - lbl_80367EA8.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x90);
    t14 = (s16)(y + (s16)(p38[3] - p38[1]));
    dh = (s16)(dh - t21);
    w = (s16)(lbl_80367E90.f4 - lbl_80367E90.f0);
    if (w != 0 && dh != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)(s16)(x + 2), (f32)t14, (f32)w, (f32)dh);
        Prim2D_SetUvRect((f32)lbl_80367E90.f0, (f32)lbl_80367E90.f2,
                    (f32)(s16)(lbl_80367E90.f4 - lbl_80367E90.f0),
                    (f32)(s16)(lbl_80367E90.f6 - lbl_80367E90.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x91);
    w = (s16)(lbl_80367E98.f4 - lbl_80367E98.f0);
    t14 = (s16)(y + (s16)(lbl_80367EB8.f6 - lbl_80367EB8.f2));
    if (w != 0 && dh != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)(s16)(x2 - w), (f32)t14, (f32)w, (f32)dh);
        Prim2D_SetUvRect((f32)lbl_80367E98.f0, (f32)lbl_80367E98.f2,
                    (f32)(s16)(lbl_80367E98.f4 - lbl_80367E98.f0),
                    (f32)(s16)(lbl_80367E98.f6 - lbl_80367E98.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        Prim2D_EndPrim();
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x96);
    if (dw != 0 && dh != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect((f32)t20, (f32)t21, (f32)dw, (f32)dh);
        Prim2D_SetUvRect((f32)lbl_80367EC0.f0, (f32)lbl_80367EC0.f2,
                    (f32)(s16)(lbl_80367EC0.f4 - lbl_80367EC0.f0),
                    (f32)(s16)(lbl_80367EC0.f6 - lbl_80367EC0.f2));
        fn_80007358(lbl_8036A880, lbl_8036A880);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(saved, sp8);
}

#pragma use_lmw_stmw on
void fn_8015D240(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void fn_80007358(f32, f32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    typedef struct { s16 f0; s16 f2; s16 f4; s16 f6; } Rect;
    extern Rect lbl_80367E38;
    extern Rect lbl_80367E40;
    extern Rect lbl_80367E48;
    extern Rect lbl_80367E50;
    extern Rect lbl_80367E58;
    extern Rect lbl_80367E60;
    extern Rect lbl_80367E68;
    extern Rect lbl_80367E70;
    extern Rect lbl_80367E78;
    extern u8 gUiTexScratch[64];
    extern s32 gUiTexAtlas;
    extern f32 lbl_8036A880;
    extern f32 lbl_8036A888;
    f32 sp8;
    s16 sp54;
    s32 *psaved;
    s32 saved;
    Rect *p68;
    Rect *p40;
    Rect *p70;
    Rect *p38;
    Rect *p58;
    Rect *p60;
    Rect *p48;
    Rect *p50r;
    s16 a0;
    s16 a1;
    s16 x1;
    s16 y1;
    s16 w;
    s16 h;
    s16 t14;
    s16 t19;
    s16 t20;
    s16 t21;
    s16 dw;
    s16 dh;
    s32 fl;

    (void)arg4;
    p68 = &lbl_80367E68;
    a0 = arg0;
    a1 = arg1;
    p40 = &lbl_80367E40;
    x1 = (s16)(a0 + arg2);
    y1 = (s16)(a1 + arg3);
    fl = arg5;
    h = (s16)(p68->f6 - p68->f2);
    w = (s16)(p68->f4 - lbl_80367E68.f0);
    t19 = (s16)(x1 - w);
    dh = (s16)(y1 - h);
    t21 = (s16)(a1 + (s16)(p40->f6 - p40->f2));
    t20 = (s16)(a0 + (s16)(p40->f4 - lbl_80367E40.f0));
    sp54 = dh;
    psaved = &saved;
    *psaved = Prim2D_PushZ(&sp8);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x78);
    w = (s16)(p40->f4 - lbl_80367E40.f0);
    h = (s16)(p40->f6 - p40->f2);
    if (w) {
        if (h) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)a0, (f32)a1, (f32)lbl_80367E40.f0, (f32)p40->f2, (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x7E);
    p70 = &lbl_80367E70;
    w = (s16)(p70->f4 - lbl_80367E70.f0);
    h = (s16)(p70->f6 - p70->f2);
    if (w) {
        if (h) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)(s16)(x1 - w), (f32)a1, (f32)lbl_80367E70.f0, (f32)p70->f2, (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x77);
    p38 = &lbl_80367E38;
    w = (s16)(p38->f4 - lbl_80367E38.f0);
    h = (s16)(p38->f6 - p38->f2);
    if (w) {
        if (h) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)a0, (f32)(s16)(y1 - h), (f32)lbl_80367E38.f0, (f32)p38->f2, (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x7D);
    w = (s16)(p68->f4 - lbl_80367E68.f0);
    h = (s16)(p68->f6 - p68->f2);
    if (w) {
        if (h) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32)(s16)(x1 - w), (f32)(s16)(y1 - h), (f32)lbl_80367E68.f0, (f32)p68->f2, (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x7B);
    p58 = &lbl_80367E58;
    dw = (s16)(t19 - t20);
    h = (s16)(p58->f6 - p58->f2);
    t14 = (s16)(a0 + (s16)(p40->f4 - lbl_80367E40.f0));
    if (dw) {
        if (h) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(9);
            Prim2D_SetRect((f32)t14, (f32)a1, (f32)dw, (f32)h);
            Prim2D_SetUvRect((f32)lbl_80367E58.f0, (f32)p58->f2,
                        (f32)(s16)(p58->f4 - lbl_80367E58.f0),
                        (f32)(s16)(p58->f6 - p58->f2));
            fn_80007358(lbl_8036A880, lbl_8036A880);
            Prim2D_EndPrim();
        }
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x7C);
    p60 = &lbl_80367E60;
    h = (s16)(p60->f6 - p60->f2);
    t14 = (s16)(a0 + (s16)(p38->f4 - lbl_80367E38.f0));
    if (dw) {
        if (h) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(9);
            Prim2D_SetRect((f32)t14, (f32)(s16)(y1 - h), (f32)dw, (f32)h);
            Prim2D_SetUvRect((f32)lbl_80367E60.f0, (f32)p60->f2,
                        (f32)(s16)(p60->f4 - lbl_80367E60.f0),
                        (f32)(s16)(p60->f6 - p60->f2));
            fn_80007358(lbl_8036A880, lbl_8036A880);
            Prim2D_EndPrim();
        }
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x79);
    p48 = &lbl_80367E48;
    dh = (s16)(sp54 - t21);
    w = (s16)(p48->f4 - lbl_80367E48.f0);
    t14 = (s16)(a1 + (s16)(p40->f6 - p40->f2));
    if (w) {
        if (dh) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(9);
            Prim2D_SetRect((f32)a0, (f32)t14, (f32)w, (f32)dh);
            Prim2D_SetUvRect((f32)lbl_80367E48.f0, (f32)p48->f2,
                        (f32)(s16)(p48->f4 - lbl_80367E48.f0),
                        (f32)(s16)(p48->f6 - p48->f2));
            fn_80007358(lbl_8036A880, lbl_8036A880);
            Prim2D_EndPrim();
        }
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x7A);
    p50r = &lbl_80367E50;
    w = (s16)(p50r->f4 - lbl_80367E50.f0);
    t14 = (s16)(a1 + (s16)(p70->f6 - p70->f2));
    if (w) {
        if (dh) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(9);
            Prim2D_SetRect((f32)(s16)(x1 - w), (f32)t14, (f32)w, (f32)dh);
            Prim2D_SetUvRect((f32)lbl_80367E50.f0, (f32)p50r->f2,
                        (f32)(s16)(p50r->f4 - lbl_80367E50.f0),
                        (f32)(s16)(p50r->f6 - p50r->f2));
            fn_80007358(lbl_8036A880, lbl_8036A880);
            Prim2D_EndPrim();
        }
    }
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x7F);
    if (dw) {
        if (dh) {
            Prim2D_Begin();
            Prim2D_SetTex(gUiTexScratch, (u16)(fl | 1));
            Prim2D_PrepareTex();
            Prim2D_AddPrim(9);
            Prim2D_SetRect((f32)t20, (f32)t21, (f32)dw, (f32)dh);
            Prim2D_SetUvRect((f32)lbl_80367E78.f0, (f32)lbl_80367E78.f2,
                        (f32)(s16)(lbl_80367E78.f4 - lbl_80367E78.f0),
                        (f32)(s16)(lbl_80367E78.f6 - lbl_80367E78.f2));
            fn_80007358(lbl_8036A880, lbl_8036A880);
            Prim2D_EndPrim();
        }
    }
    Prim2D_PopZ(*psaved, sp8);
}
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
void fn_8015DE0C(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s8 arg4, s32 arg5) {
    void Prim2D_SetCornerColors(s32 *, s32 *, s32 *, s32 *, s32, s32, s32);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void *Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(void *, f32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Ui_LoadAtlasTex(s32, void *, s32);
    extern s32 gUiTexAtlas;
    extern u8 lbl_80330CE8[0x40];
    extern s16 lbl_80367D38;
    extern s16 lbl_80367D40;
    extern s16 lbl_80367D48;
    extern s16 lbl_80367D50;
    extern s16 lbl_80367D58;
    extern s16 lbl_80367D60;
    extern s16 lbl_80367D68;
    extern s16 lbl_80367D70;
    extern f32 lbl_8036A888;
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    f32 sp28;
    s16 sp60;
    s16 sp62;
    s16 sp64;
    s16 sp66;
    s16 *p68;
    s16 *p40;
    s16 *p70;
    s16 *p38;
    s16 *p58;
    s16 *p60r;
    s16 *p48;
    u8 *base;
    s16 x;
    s16 y;
    s16 x2;
    s16 y2;
    s16 w;
    s16 h;
    s16 w2;
    s16 h2;
    s16 t;
    s16 midW;
    s16 midH;
    s16 xa;
    s16 ya;
    s16 xb;
    s16 yb;
    s16 xc;
    s16 xd;
    s8 alpha;
    s32 flags;
    void *saved;
    s32 c0, c1, c2, c3;

    alpha = arg4;
    flags = arg5;
    x = arg0;
    y = arg1;
    p68 = &lbl_80367D68;
    p40 = &lbl_80367D40;
    x2 = (s16)(x + arg2);
    y2 = (s16)(y + arg3);
    base = lbl_80330CE8;

    w = (s16)(p68[2] - p68[0]);
    h = (s16)(p68[3] - p68[1]);
    w2 = (s16)(p40[2] - p40[0]);
    h2 = (s16)(p40[3] - p40[1]);
    sp60 = (s16)(y2 - h);
    sp62 = (s16)(x2 - w);
    sp64 = (s16)(y + h2);
    sp66 = (s16)(x + w2);
    saved = Prim2D_PushZ(&sp28);

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x3E);
    w = (s16)(p40[2] - p40[0]);
    h = (s16)(p40[3] - p40[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)p40[0], (f32)p40[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x44);
    p70 = &lbl_80367D70;
    w = (s16)(p70[2] - p70[0]);
    h = (s16)(p70[3] - p70[1]);
    xa = (s16)(x2 - w);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)y, (f32)p70[0], (f32)p70[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x3D);
    p38 = &lbl_80367D38;
    w = (s16)(p38[2] - p38[0]);
    h = (s16)(p38[3] - p38[1]);
    ya = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)ya, (f32)p38[0], (f32)p38[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x43);
    w = (s16)(p68[2] - p68[0]);
    h = (s16)(p68[3] - p68[1]);
    xb = (s16)(x2 - w);
    yb = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xb, (f32)yb, (f32)p68[0], (f32)p68[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x41);
    midW = (s16)(sp62 - sp66);
    p58 = &lbl_80367D58;
    h = (s16)(p58[3] - p58[1]);
    xc = (s16)(x + (s16)(p40[2] - p40[0]));
    if (midW != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xc, (f32)y, (f32)p58[0], (f32)p58[1], (f32)midW, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x42);
    p60r = &lbl_80367D60;
    h = (s16)(p60r[3] - p60r[1]);
    xd = (s16)(x + (s16)(p38[2] - p38[0]));
    ya = (s16)(y2 - h);
    if (midW != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xd, (f32)ya, (f32)p60r[0], (f32)p60r[1], (f32)midW, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x3F);
    midH = (s16)(sp60 - sp64);
    p48 = &lbl_80367D48;
    w = (s16)(p48[2] - p48[0]);
    ya = (s16)(y + (s16)(p40[3] - p40[1]));
    if (w != 0 && midH != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)ya, (f32)p48[0], (f32)p48[1], (f32)w, (f32)midH);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x40);
    w = (s16)(*(s16 *)((char *)&lbl_80367D50 + 4) - *(s16 *)((char *)&lbl_80367D50 + 0));
    ya = (s16)(y + (s16)(p70[3] - p70[1]));
    xa = (s16)(x2 - w);
    if (w != 0 && midH != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)ya, (f32)*(s16 *)((char *)&lbl_80367D50 + 0), (f32)*(s16 *)((char *)&lbl_80367D50 + 2), (f32)w, (f32)midH);
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    {
        u8 *p20 = base + 0x20;
        u8 *p10 = base + 0x10;
        s16 xRight = (s16)(x2 - 1);
        s16 xLeft = (s16)(x + 1);
        p20[3] = alpha;
        p10[3] = alpha;
        p20[7] = alpha;
        p10[7] = alpha;
        p20[0xB] = alpha;
        p10[0xB] = alpha;
        p20[0xF] = alpha;
        p10[0xF] = alpha;
        Prim2D_Begin();
        Prim2D_SetTex(NULL, (u16)(flags | 2));
        Prim2D_PrepareTex();
        c0 = ((s32 *)(base + 0x20))[0];
        c1 = ((s32 *)(base + 0x20))[1];
        c2 = ((s32 *)(base + 0x20))[2];
        c3 = ((s32 *)(base + 0x20))[3];
        sp8 = c0;
        spC = c1;
        sp10 = c2;
        sp14 = c3;
        Prim2D_AddPrim(3);
        Prim2D_SetRect((f32)xLeft, (f32)y, (f32)(s16)(xRight - xLeft), (f32)(s16)(y2 - y));
        Prim2D_EmitQuad();
        sp24 = sp14;
        sp20 = sp10;
        sp1C = spC;
        sp18 = sp8;
        Prim2D_SetCornerColors(&sp18, &sp1C, &sp20, &sp24, spC, sp10, sp14);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(saved, sp28);
}

#pragma use_lmw_stmw on
void fn_8015E848(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5) {
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CA8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CB0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CB8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CC0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CC8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CD0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CD8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CE0;
    extern u8 gUiTexScratch[64];
    extern s32 gUiTexAtlas;
    extern f32 lbl_8036A888;
    f32 sp10;
    u8 spC[4];
    s32 sp8;
    s16 sp4E;
    s16 sp4C;
    s16 *p68;
    s16 *p38;
    s16 *p40;
    s16 x;
    s16 y;
    s16 y2;
    s16 x2;
    s16 w;
    s16 h;
    s16 w2;
    s16 h2;
    s16 xa;
    s16 xb;
    s16 midW;
    s16 midH;
    s16 ya;
    s16 yb;
    s32 flags;
    s32 saved;
    s16 *p70;
    s16 *p58;
    s16 *p60r;
    s16 *p48;
    s16 *p50;

    p68 = (s16 *)&lbl_80367CD8;
    p40 = (s16 *)&lbl_80367CB0;
    x = arg0;
    y = arg1;
    x2 = (s16)(x + arg2);
    y2 = (s16)(y + arg3);
    flags = arg5;

    h = (s16)(p68[3] - p68[1]);
    w = (s16)(p68[2] - lbl_80367CD8.f0);
    h2 = (s16)(p40[3] - p40[1]);
    w2 = (s16)(p40[2] - lbl_80367CB0.f0);
    sp4C = (s16)(y2 - h);
    xa = (s16)(x2 - w);
    sp4E = (s16)(y + h2);
    xb = (s16)(x + w2);
    saved = Prim2D_PushZ(&sp10);

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x36);
    w = (s16)(p40[2] - lbl_80367CB0.f0);
    h = (s16)(p40[3] - p40[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80367CB0.f0, (f32)p40[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x3C);
    p70 = (s16 *)&lbl_80367CE0;
    w = (s16)(p70[2] - lbl_80367CE0.f0);
    h = (s16)(p70[3] - p70[1]);
    ya = (s16)(x2 - w);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)ya, (f32)y, (f32)lbl_80367CE0.f0, (f32)p70[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x35);
    p38 = (s16 *)&lbl_80367CA8;
    w = (s16)(p38[2] - lbl_80367CA8.f0);
    h = (s16)(p38[3] - p38[1]);
    yb = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)yb, (f32)lbl_80367CA8.f0, (f32)p38[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x3B);
    h = (s16)(p68[3] - p68[1]);
    w = (s16)(p68[2] - lbl_80367CD8.f0);
    ya = (s16)(y2 - h);
    yb = (s16)(x2 - w);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)yb, (f32)ya, (f32)lbl_80367CD8.f0, (f32)p68[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x39);
    p58 = (s16 *)&lbl_80367CC8;
    midW = (s16)(xa - xb);
    w2 = (s16)(p40[2] - lbl_80367CB0.f0);
    h = (s16)(p58[3] - p58[1]);
    xb = (s16)(x + w2);
    if (midW != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xb, (f32)y, (f32)lbl_80367CC8.f0, (f32)p58[1], (f32)midW, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x3A);
    p60r = (s16 *)&lbl_80367CD0;
    h = (s16)(p60r[3] - p60r[1]);
    w2 = (s16)(p38[2] - lbl_80367CA8.f0);
    xb = (s16)(x + w2);
    yb = (s16)(y2 - h);
    if (midW != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xb, (f32)yb, (f32)lbl_80367CD0.f0, (f32)p60r[1], (f32)midW, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x37);
    midH = (s16)(sp4C - sp4E);
    p48 = (s16 *)&lbl_80367CB8;
    w = (s16)(p48[2] - lbl_80367CB8.f0);
    h2 = (s16)(p40[3] - p40[1]);
    yb = (s16)(y + h2);
    if (w != 0 && midH != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)yb, (f32)lbl_80367CB8.f0, (f32)p48[1], (f32)w, (f32)midH);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0x38);
    p50 = (s16 *)&lbl_80367CC0;
    w = (s16)(p50[2] - lbl_80367CC0.f0);
    xa = (s16)(x2 - w);
    h2 = (s16)(p70[3] - p70[1]);
    yb = (s16)(y + h2);
    if (w != 0 && midH != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)yb, (f32)lbl_80367CC0.f0, (f32)p50[1], (f32)w, (f32)midH);
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    spC[0] = arg4[0];
    spC[1] = arg4[1];
    spC[2] = arg4[2];
    spC[3] = arg4[3];
    Prim2D_Begin();
    Prim2D_SetTex(NULL, (u16)(flags | 2));
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)x, (f32)y, (f32)(s16)(x2 - x), (f32)(s16)(y2 - y));
    sp8 = *(s32 *)spC;
    Prim2D_SetColorPacked(&sp8);
    Prim2D_EndPrim();
    Prim2D_PopZ(saved, sp10);
}

#pragma use_lmw_stmw on
void fn_8015F24C(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s8 arg4, s32 arg5) {
    void Prim2D_SetCornerColors(s32 *, s32 *, s32 *, s32 *, s32, s32, s32);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void *Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(void *, f32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Ui_LoadAtlasTex(s32, void *, s32);
    extern s32 gUiTexAtlas;
    extern u8 lbl_80330CE8[0x40];
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CA8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CB0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CB8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CC0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CC8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CD0;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CD8;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367CE0;
    extern f32 lbl_8036A888;
    s32 col[8];
    f32 zsave;
    s16 sp60, sp62, sp64, sp66;
    s16 *pRM;
    s16 *pLM;
    s16 *pBM;
    s16 *pTM;
    s16 *pBL;
    s16 *pTR;
    u8 *base;
    s16 *pTL;
    s16 *pBR;
    s16 w, h;
    s16 midW, midH;
    s16 xa, ya;
    s16 x2, y2;
    s16 sx, sy;
    s8 alpha;
    s32 flags;
    void *saved;
    s32 c0, c1, c2, c3;

    pBR = (s16 *)&lbl_80367CD8;
    sx = arg0;
    pTL = (s16 *)&lbl_80367CB0;
    {
        s32 t1 = sx + arg2;
        sy = arg1;
        {
            s32 t2 = sy + arg3;
            alpha = arg4;
            y2 = (s16)t2;
            x2 = (s16)t1;
            flags = arg5;
        }
    }
    base = lbl_80330CE8;

    w = (s16)(pBR[2] - lbl_80367CD8.f0);
    h = (s16)(pBR[3] - pBR[1]);
    sp60 = (s16)(y2 - h);
    sp62 = (s16)(x2 - w);
    sp64 = (s16)(sy + (s16)(pTL[3] - pTL[1]));
    sp66 = (s16)(sx + (s16)(pTL[2] - lbl_80367CB0.f0));
    saved = Prim2D_PushZ(&zsave);

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x36);
    w = (s16)(pTL[2] - lbl_80367CB0.f0);
    h = (s16)(pTL[3] - pTL[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)sx, (f32)sy, (f32)lbl_80367CB0.f0, (f32)pTL[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x3C);
    pTR = (s16 *)&lbl_80367CE0;
    w = (s16)(pTR[2] - lbl_80367CE0.f0);
    h = (s16)(pTR[3] - pTR[1]);
    xa = (s16)(x2 - w);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)sy, (f32)lbl_80367CE0.f0, (f32)pTR[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x35);
    pBL = (s16 *)&lbl_80367CA8;
    w = (s16)(pBL[2] - lbl_80367CA8.f0);
    h = (s16)(pBL[3] - pBL[1]);
    ya = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)sx, (f32)ya, (f32)lbl_80367CA8.f0, (f32)pBL[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x3B);
    w = (s16)(pBR[2] - lbl_80367CD8.f0);
    h = (s16)(pBR[3] - pBR[1]);
    xa = (s16)(x2 - w);
    ya = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)ya, (f32)lbl_80367CD8.f0, (f32)pBR[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x39);
    midW = (s16)(sp62 - sp66);
    pTM = (s16 *)&lbl_80367CC8;
    h = (s16)(pTM[3] - pTM[1]);
    xa = (s16)(sx + (s16)(pTL[2] - lbl_80367CB0.f0));
    if (midW != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)sy, (f32)lbl_80367CC8.f0, (f32)pTM[1], (f32)midW, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x3A);
    pBM = (s16 *)&lbl_80367CD0;
    h = (s16)(pBM[3] - pBM[1]);
    xa = (s16)(sx + (s16)(pBL[2] - lbl_80367CA8.f0));
    ya = (s16)(y2 - h);
    if (midW != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)ya, (f32)lbl_80367CD0.f0, (f32)pBM[1], (f32)midW, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x37);
    midH = (s16)(sp60 - sp64);
    pLM = (s16 *)&lbl_80367CB8;
    w = (s16)(pLM[2] - lbl_80367CB8.f0);
    ya = (s16)(sy + (s16)(pTL[3] - pTL[1]));
    if (w != 0 && midH != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)sx, (f32)ya, (f32)lbl_80367CB8.f0, (f32)pLM[1], (f32)w, (f32)midH);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0x38);
    pRM = (s16 *)&lbl_80367CC0;
    w = (s16)(pRM[2] - lbl_80367CC0.f0);
    ya = (s16)(sy + (s16)(pTR[3] - pTR[1]));
    xa = (s16)(x2 - w);
    if (w != 0 && midH != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)xa, (f32)ya, (f32)lbl_80367CC0.f0, (f32)pRM[1], (f32)w, (f32)midH);
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    {
        u8 *p20 = base + 0x20;
        u8 *p10 = base + 0x10;
        s16 xRight = (s16)(x2 - 1);
        s16 xLeft = (s16)(sx + 1);
        p20[3] = alpha;
        p10[3] = alpha;
        p20[7] = alpha;
        p10[7] = alpha;
        p20[0xB] = alpha;
        p10[0xB] = alpha;
        p20[0xF] = alpha;
        p10[0xF] = alpha;
        Prim2D_Begin();
        Prim2D_SetTex(NULL, (u16)(flags | 2));
        Prim2D_PrepareTex();
        c0 = ((s32 *)(base + 0x20))[0];
        c1 = ((s32 *)(base + 0x20))[1];
        c2 = ((s32 *)(base + 0x20))[2];
        c3 = ((s32 *)(base + 0x20))[3];
        col[0] = c0; col[1] = c1; col[2] = c2; col[3] = c3;
        Prim2D_AddPrim(3);
        Prim2D_SetRect((f32)xLeft, (f32)sy, (f32)(s16)(xRight - xLeft), (f32)(s16)(y2 - sy));
        Prim2D_EmitQuad();
        col[7] = col[3]; col[6] = col[2]; col[5] = col[1]; col[4] = col[0];
        Prim2D_SetCornerColors(&col[4], &col[5], &col[6], &col[7], col[1], col[2], col[3]);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(saved, zsave);
}
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
void Ui_DrawWindowFrame(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_SwapUvV(void);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(void *);
    void Prim2D_AddZ(f32);
    s32 Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(s32, f32);
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C58;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C38;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C60;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C30;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C50;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C40;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80367C48;
    extern struct { s16 f0; s16 f2; s16 f4; s16 f6; } lbl_80368080;
    extern u8 gUiTexScratch[64];
    extern s32 gUiTexAtlas;
    extern f32 lbl_8036A888;
    f32 sp14;
    s32 handle;
    u8 color[4];
    s16 x, y, x2, y2;
    s16 t14, t18, t19, t20;
    s16 w, h, px, py;
    s32 packed;
    s16 *p38;
    s16 *p58;

    x = arg0;
    y = arg1;
    x2 = (s16)(x + arg2);
    y2 = (s16)(y + arg3);
    p58 = (s16 *)&lbl_80367C58;
    p38 = (s16 *)&lbl_80367C38;

    h = (s16)(p58[3] - p58[1]);
    w = (s16)(p58[2] - lbl_80367C58.f0);
    {
        s16 h38 = (s16)(p38[3] - p38[1]);
        s16 w38 = (s16)(p38[2] - lbl_80367C38.f0);
        t18 = (s16)(y2 - h);
        t19 = (s16)(x2 - w);
        t20 = (s16)(y + h38);
        t14 = (s16)(x + w38);
    }

    handle = Prim2D_PushZ(&sp14);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 4);

    w = (s16)(p38[2] - lbl_80367C38.f0);
    h = (s16)(p38[3] - p38[1]);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)lbl_80367C38.f0, (f32)p38[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 9);
    w = (s16)(lbl_80367C60.f4 - lbl_80367C60.f0);
    h = (s16)(lbl_80367C60.f6 - lbl_80367C60.f2);
    px = (s16)(x2 - w);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367C60.f0, (f32)lbl_80367C60.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 3);
    w = (s16)(lbl_80367C30.f4 - lbl_80367C30.f0);
    h = (s16)(lbl_80367C30.f6 - lbl_80367C30.f2);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)py, (f32)lbl_80367C30.f0, (f32)lbl_80367C30.f2, (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 8);
    h = (s16)(p58[3] - p58[1]);
    w = (s16)(p58[2] - lbl_80367C58.f0);
    px = (s16)(x2 - w);
    py = (s16)(y2 - h);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367C58.f0, (f32)p58[1], (f32)w, (f32)h);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 7);
    t19 = (s16)(t19 - t14);
    h = (s16)(lbl_80367C50.f6 - lbl_80367C50.f2);
    px = (s16)(x + (s16)(p38[2] - lbl_80367C38.f0));
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)arg1, (f32)lbl_80367C50.f0, (f32)lbl_80367C50.f2, (f32)t19, (f32)h);
        Prim2D_EndPrim();
    }

    h = (s16)(lbl_80367C50.f6 - lbl_80367C50.f2);
    px = (s16)(x + (s16)(lbl_80367C30.f4 - lbl_80367C30.f0));
    py = (s16)(y2 - h);
    if (t19 != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)px, (f32)py, (f32)lbl_80367C50.f0, (f32)lbl_80367C50.f2, (f32)t19, (f32)h);
        Prim2D_SwapUvV();
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 5);
    t18 = (s16)(t18 - t20);
    w = (s16)(lbl_80367C40.f4 - lbl_80367C40.f0);
    py = (s16)(y + (s16)(p38[3] - p38[1]));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(x + 1), (f32)py, (f32)lbl_80367C40.f0, (f32)lbl_80367C40.f2, (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 6);
    w = (s16)(lbl_80367C48.f4 - lbl_80367C48.f0);
    py = (s16)(y + (s16)(lbl_80367C60.f6 - lbl_80367C60.f2));
    if (w != 0 && t18 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)((x2 - w) - 1), (f32)py, (f32)lbl_80367C48.f0, (f32)lbl_80367C48.f2, (f32)w, (f32)t18);
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    px = (s16)(x + 1);
    Ui_LoadAtlasTex(gUiTexAtlas, gUiTexScratch, 0xA7);
    h = (s16)(y2 - y);
    w = (s16)((s16)(x2 - 1) - px);
    color[0] = 0xFF;
    color[1] = 0xFF;
    color[2] = 0xFF;
    color[3] = arg4;
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg5 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)px, (f32)y, (f32)w, (f32)h);
        Prim2D_SetUvRect((f32)lbl_80368080.f0, (f32)lbl_80368080.f2,
                    (f32)(s16)(lbl_80368080.f4 - lbl_80368080.f0),
                    (f32)(s16)(lbl_80368080.f6 - lbl_80368080.f2));
        packed = *(s32 *)color;
        Prim2D_SetColorPacked(&packed);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(handle, sp14);
}
void fn_8016070C(s16 arg0, s16 arg1, s16 arg2, s32 arg3, s8 arg4, s32 arg5) {
    void Prim2D_SetCornerColors(s32 *, s32 *, s32 *, s32 *);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetPosCorners(f32, f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void *Prim2D_PushZ(f32 *);
    void Prim2D_PopZ(void *, f32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void fn_80161778(s16, s16, s16, s32);
    extern u8 lbl_80330CE8[0x40];
    extern s32 gUiTexAtlas;
    extern s16 lbl_80367BC0;
    extern s16 lbl_80367C10;
    extern s16 lbl_80367C20;
    extern s16 lbl_80367C28;
    extern u32 lbl_803680C0;
    extern f64 lbl_8036A868;
    extern f32 lbl_8036A870;
    extern f32 lbl_8036A888;
    extern f32 lbl_8036A88C;

    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
    f32 sp38;
    s16 box[4];
    s16 rect[4];
    s16 *bc0;
    s16 *c10;
    s16 *c20;
    s16 *c28;
    u32 *colors;
    u8 *base;
    u8 *p20;
    u8 *p10;
    void *saved;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    s16 t;
    s16 yA;
    s16 yB;
    s16 yC;
    s16 xL;
    s16 xR;
    s16 w28;
    s16 h28;
    s16 midX;
    s16 midY;
    u16 flags2;
    s8 alpha;
    s32 flags;
    f32 f30;
    f32 f31;
    f32 fx, fy, fw, fh;

    base = lbl_80330CE8;
    x = arg0;
    y = arg1;
    w = arg2;
    flags = arg5;
    alpha = arg4;
    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 0);
    saved = Prim2D_PushZ(&sp38);
    bc0 = &lbl_80367BC0;
    rect[0] = x;
    h = (s16)(bc0[3] - bc0[1]);
    rect[1] = y;
    rect[2] = (s16)(x + w);
    rect[3] = (s16)(y + arg3);
    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        fx = (f32)x;
        fy = (f32)y;
        fw = (f32)w;
        fh = (f32)h;
        Prim2D_SetRect(fx, fy, fw, fh);
        Prim2D_SetUvRect((f32)bc0[0], (f32)bc0[1],
                    (f32)(s16)(bc0[2] - bc0[0]), (f32)(s16)(bc0[3] - bc0[1]));
        Prim2D_EndPrim();
    }
    c10 = &lbl_80367C10;
    fn_80161778(x, (s16)(rect[3] - (s16)(c10[3] - c10[1])), w, flags);
    h = (s16)(bc0[3] - bc0[1]);
    yB = rect[1];
    t = (s16)(rect[3] - yB);
    yA = (s16)(yB + h);
    xL = rect[0];
    yC = (s16)((s16)(t - (s16)(h + (s16)(c10[3] - c10[1]))) + 4);
    yC = (s16)(yA + yC);
    xR = (s16)(xL + 1);
    Prim2D_Begin();
    flags2 = (u16)(flags | 2);
    Prim2D_SetTex(0, flags2);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    f30 = lbl_8036A870 + (f32)yA;
    f31 = lbl_8036A870 + (f32)yC;
    Prim2D_SetPosCorners(lbl_8036A870 + (f32)xL, f30, lbl_8036A870 + (f32)xL, f31, lbl_8036A870);
    colors = &lbl_803680C0;
    sp14 = colors[0];
    Prim2D_SetColorPacked(&sp14);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTex(0, flags2);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_8036A870 + (f32)xR, f30, lbl_8036A870 + (f32)xR, f31, lbl_8036A870);
    sp10 = colors[1];
    Prim2D_SetColorPacked(&sp10);
    Prim2D_EndPrim();
    c20 = &lbl_80367C20;
    xR = (s16)(rect[2] - 2);
    h = (s16)(bc0[3] - bc0[1]);
    t = (s16)(rect[3] - rect[1]);
    xL = (s16)(xR + 1);
    yC = (s16)(t - (s16)(h + (s16)(c20[3] - c20[1])));
    yA = (s16)(rect[1] + (s16)(h - 4));
    yC = (s16)(yA + (s16)(yC + 4));
    Prim2D_Begin();
    Prim2D_SetTex(0, flags2);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    f31 = lbl_8036A870 + (f32)yA;
    f30 = lbl_8036A870 + (f32)yC;
    Prim2D_SetPosCorners(lbl_8036A870 + (f32)xR, f31, lbl_8036A870 + (f32)xR, f30, lbl_8036A870);
    spC = colors[0];
    Prim2D_SetColorPacked(&spC);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTex(0, flags2);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_8036A870 + (f32)xL, f31, lbl_8036A870 + (f32)xL, f30, lbl_8036A870);
    sp8 = colors[1];
    Prim2D_SetColorPacked(&sp8);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A888);
    Prim2D_PrepareTex();
    p20 = base + 0x20;
    p10 = base + 0x10;
    *(s32 *)&box[0] = *(s32 *)&rect[0];
    *(s32 *)&box[2] = *(s32 *)&rect[2];
    h = (s16)(bc0[3] - bc0[1]);
    t = (s16)(c10[3] - c10[1]);
    box[1] = (s16)(box[1] + (h >> 1));
    box[3] = (s16)(box[3] - (t >> 1));
    p20[3] = alpha;
    p10[3] = alpha;
    p20[7] = alpha;
    p10[7] = alpha;
    p20[0xB] = alpha;
    p10[0xB] = alpha;
    p20[0xF] = alpha;
    p10[0xF] = alpha;
    Prim2D_Begin();
    Prim2D_SetTex(0, flags2);
    Prim2D_PrepareTex();
    sp18 = ((s32 *)p20)[0];
    sp1C = ((s32 *)p20)[1];
    sp20 = ((s32 *)p20)[2];
    sp24 = ((s32 *)p20)[3];
    Prim2D_AddPrim(3);
    Prim2D_SetRect((f32)box[0], (f32)box[1],
                (f32)(s16)(box[2] - box[0]), (f32)(s16)(box[3] - box[1]));
    Prim2D_EmitQuad();
    sp34 = sp24;
    sp30 = sp20;
    sp2C = sp1C;
    sp28 = sp18;
    Prim2D_SetCornerColors(&sp28, &sp2C, &sp30, &sp34);
    Prim2D_EndPrim();
    Ui_LoadAtlasTex(gUiTexAtlas, base + 0x30, 1);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A88C);
    Prim2D_PrepareTex();
    c28 = &lbl_80367C28;
    yA = (s16)(rect[1] + (s16)(bc0[3] - bc0[1]));
    yB = (s16)(rect[3] - (s16)(c10[3] - c10[1]));
    h28 = (s16)(c28[3] - c28[1]);
    w28 = (s16)(c28[2] - c28[0]);
    box[1] = rect[1];
    box[3] = rect[3];
    box[0] = rect[0];
    box[2] = rect[2];
    box[1] = yA;
    box[3] = yB;
    midY = (s16)(yA + (((s16)(yB - yA) >> 1) - (h28 >> 1)));
    midX = (s16)(rect[0] + (((s16)(rect[2] - rect[0]) - w28) >> 1));
    if (w28 != 0 && h28 != 0) {
        Prim2D_Begin();
        Prim2D_SetTex(base + 0x30, (u16)(flags | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)midX, (f32)midY,
                    (f32)c28[0], (f32)c28[1], (f32)w28, (f32)h28);
        Prim2D_EndPrim();
    }
    Prim2D_PopZ(saved, sp38);
}

#pragma optimization_level 3
void fn_80160F00(s16 x, s16 y, u8 flag, s32 texFlags) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    extern s32 gUiTexAtlas;
    typedef struct UiRect { s16 f0; s16 f2; s16 f4; s16 f6; } UiRect;
    extern UiRect lbl_80367F20;
    extern UiRect lbl_80367F28;
    s16 xl;
    s16 yl;
    s32 tf;
    s16 h;
    s16 w;
    s32 texId;
    u32 scratch;

    xl = x;
    yl = y;
    tf = texFlags;
    scratch = (u32)&gUiTexScratch;

    texId = 0x15;
    if (flag != 0) {
        texId = 0x14;
    }
    Ui_LoadAtlasTex(gUiTexAtlas, (void *)scratch, texId);

    h = (s16)((flag != 0 ? &lbl_80367F20 : &lbl_80367F28)->f6 -
             (flag != 0 ? &lbl_80367F20 : &lbl_80367F28)->f2);
    w = (s16)((flag != 0 ? &lbl_80367F20 : &lbl_80367F28)->f4 -
             (flag != 0 ? &lbl_80367F20 : &lbl_80367F28)->f0);

    if (w != 0 && h != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)&gUiTexScratch, (u16)(tf | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(
            (f32)xl,
            (f32)yl,
            (f32)(flag != 0 ? &lbl_80367F20 : &lbl_80367F28)->f0,
            (f32)(flag != 0 ? &lbl_80367F20 : &lbl_80367F28)->f2,
            (f32)w,
            (f32)h);
        Prim2D_EndPrim();
    }
}
#pragma push
#pragma use_lmw_stmw on
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_801610A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32,f32,f32,f32);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetCornerColors(s32 *,s32 *,s32 *,s32 *);
    void Prim2D_EndPrim(void);
    void Prim2D_SetColorPacked(s32 *);
    extern s8 lbl_803680D6;
    extern s8 lbl_803680D7;
    extern u8 lbl_80330D58[];
    extern u8 lbl_803680D8[8];
    extern f64 lbl_8036A868;

    s32 right, bottom, bottom2;
    s32 x, y, w, h, flags;
    s16 h3;
    Color4rev initial;
    Color4 corner;
    Color4 colors;
    s32 finalColor;
    u8 zero;
    Color4 *palette;

    x = (s16)arg0;
    y = (s16)arg1;
    w = (s16)arg2;
    h = (s16)arg3;
    flags = arg4;
    bottom2 = (s16)(y + h);
    h3 = h / 3;
    bottom = (s16)(y + h3);
    right = (s16)(x + w);
    if (lbl_803680D6 == 0) {
        palette = (Color4 *)lbl_80330D58;
        zero = 0;
        ((Color *)&initial.c0)->r = zero; ((Color *)&initial.c0)->g = zero; ((Color *)&initial.c0)->b = zero; ((Color *)&initial.c0)->a = zero;
        ((Color *)&initial.c1)->r = zero; ((Color *)&initial.c1)->g = zero; ((Color *)&initial.c1)->b = zero; ((Color *)&initial.c1)->a = zero;
        ((Color *)&initial.c2)->r = zero; ((Color *)&initial.c2)->g = zero; ((Color *)&initial.c2)->b = zero; ((Color *)&initial.c2)->a = 0xFF;
        ((Color *)&initial.c3)->r = zero; ((Color *)&initial.c3)->g = zero; ((Color *)&initial.c3)->b = zero; ((Color *)&initial.c3)->a = 0xFF;
        palette->c0 = initial.c0;
        palette->c1 = initial.c1;
        palette->c2 = initial.c2;
        palette->c3 = initial.c3;
        lbl_803680D6 = 1;
    }

    if (lbl_803680D7 == 0) {
        lbl_803680D8[0] = 0;
        lbl_803680D8[1] = 0;
        lbl_803680D8[2] = 0;
        lbl_803680D8[3] = 0xFF;
        lbl_803680D7 = 1;
    }

    Prim2D_Begin();
    flags |= 2;
    Prim2D_SetTex(0, (u16)flags);
    Prim2D_PrepareTex();

    colors = *(Color4 *)lbl_80330D58;
    Prim2D_AddPrim(3);

    Prim2D_SetRect((f32)(s16)arg0, (f32)(s16)arg1, (f32)(s16)(right - x), (f32)(s16)(bottom - y));
    Prim2D_EmitQuad();

    corner.c3 = colors.c3;
    corner.c2 = colors.c2;
    corner.c1 = colors.c1;
    corner.c0 = colors.c0;
    Prim2D_SetCornerColors((s32 *)&corner.c0,
                (s32 *)&corner.c1,
                (s32 *)&corner.c2,
                (s32 *)&corner.c3);

    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTex(0, (u16)flags);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)(s16)arg0, (f32)bottom, (f32)(s16)(right - x), (f32)(s16)(bottom2 - bottom));
    finalColor = *(s32 *)lbl_803680D8;
    Prim2D_SetColorPacked(&finalColor);
    Prim2D_EndPrim();
}
#pragma pop
void fn_80161364(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void Prim2D_Begin(void);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetCornerColors(void *, void *, void *, void *);
    void Prim2D_EndPrim(void);
    void Prim2D_SetColorPacked(void *);
    extern u8 lbl_803680D4;
    extern u8 lbl_803680D5;
    extern u32 lbl_80330D38[];
    extern u32 lbl_80330D48[];
    extern f64 lbl_8036A868;
    u32 colors[4];
    u32 rev[4];
    u32 tip;
    register s16 x0;
    s16 y0;
    s16 x1;
    s16 yA;
    s16 yB;
    s16 yC;
    s16 third;
    s32 flags;

    flags = arg4;
    x0 = (s16)arg0;
    y0 = (s16)arg1;
    third = (s16)arg3 / 3;
    x1 = (s16)(x0 + (s16)arg2);
    yA = (s16)(y0 + third);
    yB = (s16)(y0 + third * 2);
    yC = (s16)(y0 + third * 3);

    if ((s8)lbl_803680D4 == 0) {
        u8 *p;
        p = (u8 *)colors;
        p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0;
        p[4] = 0; p[5] = 0; p[6] = 0; p[7] = 0;
        p[8] = 0; p[9] = 0; p[10] = 0; p[11] = 0xFF;
        p[12] = 0; p[13] = 0; p[14] = 0; p[15] = 0xFF;
        lbl_80330D38[0] = colors[0];
        lbl_80330D38[1] = colors[1];
        lbl_80330D38[3] = colors[3];
        lbl_80330D38[2] = colors[2];
        lbl_803680D4 = 1;
    }
    if ((s8)lbl_803680D5 == 0) {
        u8 *p;
        p = (u8 *)colors;
        p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0xFF;
        p[4] = 0; p[5] = 0; p[6] = 0; p[7] = 0xFF;
        p[8] = 0; p[9] = 0; p[10] = 0; p[11] = 0;
        p[12] = 0; p[13] = 0; p[14] = 0; p[15] = 0;
        lbl_80330D48[0] = colors[0];
        lbl_80330D48[1] = colors[1];
        lbl_80330D48[2] = colors[2];
        lbl_80330D48[3] = colors[3];
        lbl_803680D5 = 1;
    }

    Prim2D_Begin();
    flags |= 2;
    Prim2D_SetTex(0, (u16)flags);
    Prim2D_PrepareTex();
    colors[0] = lbl_80330D38[0];
    colors[1] = lbl_80330D38[1];
    colors[2] = lbl_80330D38[2];
    colors[3] = lbl_80330D38[3];
    Prim2D_AddPrim(3);
    Prim2D_SetRect((f32)(s16)arg0, (f32)(s16)arg1, (f32)(s16)(x1 - x0), (f32)(s16)(yA - y0));
    Prim2D_EmitQuad();
    rev[3] = colors[3]; rev[2] = colors[2]; rev[1] = colors[1]; rev[0] = colors[0];
    Prim2D_SetCornerColors(&rev[0], &rev[1], &rev[2], &rev[3]);
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_SetTex(0, (u16)flags);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)(s16)arg0, (f32)yA, (f32)(s16)(x1 - x0), (f32)(s16)(yB - yA));
    tip = lbl_80330D48[0];
    Prim2D_SetColorPacked(&tip);
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_SetTex(0, (u16)flags);
    Prim2D_PrepareTex();
    colors[0] = lbl_80330D48[0];
    colors[1] = lbl_80330D48[1];
    colors[2] = lbl_80330D48[2];
    colors[3] = lbl_80330D48[3];
    Prim2D_AddPrim(3);
    Prim2D_SetRect((f32)(s16)arg0, (f32)yB, (f32)(s16)(x1 - x0), (f32)(s16)(yC - yB));
    Prim2D_EmitQuad();
    rev[3] = colors[3]; rev[2] = colors[2]; rev[1] = colors[1]; rev[0] = colors[0];
    Prim2D_SetCornerColors(&rev[0], &rev[1], &rev[2], &rev[3]);
    Prim2D_EndPrim();
}
void fn_80161778(s16 arg0, s16 arg1, s32 arg2, s32 arg3) {
    M2C_UNK Prim2D_SetColorPacked(s32 *);
    M2C_UNK Prim2D_SetPosCorners(f32, f32, f32, f32, f32);
    M2C_UNK Prim2D_Begin(void);
    M2C_UNK Prim2D_SetTex(void *, u16);
    M2C_UNK Prim2D_PrepareTex(void);
    M2C_UNK Prim2D_AddPrim(s32);
    M2C_UNK Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    M2C_UNK Prim2D_EndPrim(void);
    M2C_UNK fn_80161B98(s16, s16, s16, s16, s32, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK lbl_80330CE8;
    extern M2C_UNK lbl_80367C10;
    extern M2C_UNK lbl_80367C18;
    extern M2C_UNK lbl_80367C20;
    extern u8 gUiTexScratch[64];
    extern f64 lbl_8036A868;
    extern f32 lbl_8036A870;
    s16 temp_r7;
    s16 temp_r0;
    s16 temp_r3;
    s16 temp_r24;
    s16 temp_r27;
    s16 temp_r0_2;
    s16 temp_r0_3;
    u8 spF;
    u8 spE;
    u8 spD;
    u8 spC;
    s32 sp8;
    f32 temp_f2;

    temp_r7 = M2C_FIELD(&lbl_80367C10, s16 *, 4) - M2C_FIELD(&lbl_80367C10, s16 *, 0);
    temp_r0 = M2C_FIELD(&lbl_80367C10, s16 *, 6) - M2C_FIELD(&lbl_80367C10, s16 *, 2);
    temp_r27 = arg2 - (temp_r7 + (s16)(M2C_FIELD(&lbl_80367C20, s16 *, 4) - M2C_FIELD(&lbl_80367C20, s16 *, 0)));
    if ((temp_r7 != 0) && (temp_r0 != 0)) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg3 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)arg0, (f32)arg1, (f32)M2C_FIELD(&lbl_80367C10, s16 *, 0), (f32)M2C_FIELD(&lbl_80367C10, s16 *, 2), (f32)temp_r7, (f32)temp_r0);
        Prim2D_EndPrim();
    }
    spC = 0xFF;
    temp_r3 = M2C_FIELD(&lbl_80367C10, s16 *, 4) - M2C_FIELD(&lbl_80367C10, s16 *, 0);
    spD = 0xFF;
    temp_r24 = arg0 + temp_r3;
    spE = 0xFF;
    spF = 0xFF;
    Prim2D_Begin();
    Prim2D_SetTex(NULL, (u16)(arg3 | 2));
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    temp_f2 = lbl_8036A870 + (f32)arg1;
    Prim2D_SetPosCorners(lbl_8036A870 + (f32)temp_r24, temp_f2, lbl_8036A870 + (f32)(s16)(temp_r24 + temp_r27), temp_f2, lbl_8036A870);
    sp8 = (s32)spC;
    Prim2D_SetColorPacked(&sp8);
    Prim2D_EndPrim();
    fn_80161B98(temp_r24, arg1, temp_r27, (s16)(M2C_FIELD(&lbl_80367C18, s16 *, 6) - M2C_FIELD(&lbl_80367C18, s16 *, 2)), arg3, &lbl_80367C18, &lbl_80330CE8, 0);
    temp_r0_2 = M2C_FIELD(&lbl_80367C20, s16 *, 4) - M2C_FIELD(&lbl_80367C20, s16 *, 0);
    temp_r0_3 = M2C_FIELD(&lbl_80367C20, s16 *, 6) - M2C_FIELD(&lbl_80367C20, s16 *, 2);
    if ((temp_r0_2 != 0) && (temp_r0_3 != 0)) {
        Prim2D_Begin();
        Prim2D_SetTex(gUiTexScratch, (u16)(arg3 | 1));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)(s16)(temp_r24 + temp_r27), (f32)arg1, (f32)M2C_FIELD(&lbl_80367C20, s16 *, 0), (f32)M2C_FIELD(&lbl_80367C20, s16 *, 2), (f32)temp_r0_2, (f32)temp_r0_3);
        Prim2D_EndPrim();
    }
}

#pragma use_lmw_stmw on
void Ui_DrawLine(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 *arg5) {
    void Prim2D_Begin(void);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPosCorners(f32, f32, f32, f32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_EndPrim(void);
    extern f64 lbl_8036A868;
    extern f32 lbl_8036A870;
    s32 packedColor;

    Prim2D_Begin();
    Prim2D_SetTex(0, (u16)(arg4 | 2));
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_8036A870 + (f32)arg0, lbl_8036A870 + (f32)arg1, lbl_8036A870 + (f32)arg2, lbl_8036A870 + (f32)arg3, 0.5f);
    packedColor = *arg5;
    Prim2D_SetColorPacked(&packedColor);
    Prim2D_EndPrim();
}
#pragma use_lmw_stmw reset
static inline void Store4Desc80161B98(s32 c0, s32 c1, s32 c2, s32 c3,
                                     void *d0, void *d1, void *d2, void *d3) {
    *(s32 *)d0 = c0;
    *(s32 *)d1 = c1;
    *(s32 *)d2 = c2;
    *(s32 *)d3 = c3;
}

void fn_80161B98(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s16 *arg5, s32 *arg6, s32 arg7) {
    void Prim2D_Begin(void);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32);
    void Prim2D_SwapUvU(void);
    void Prim2D_SwapUvV(void);
    void Prim2D_EmitQuad(void);
    void Prim2D_RotateUvCcw(void);
    void Prim2D_RotateUvCw(void);
    void Prim2D_SetCornerColors(Color *, Color *, Color *, Color *);
    void Prim2D_EndPrim(void);
    Color sp2C;
    extern u8 gUiTexScratch[64];
    extern f64 lbl_8036A868;
    Color sp28;
    Color sp24;
    Color sp20;
    Color sp1C;
    Color sp18;
    Color sp14;
    Color sp10;
    Color tmp;
    Color tmp2;
    s32 c3;
    unsigned c2;
    int c1;
    unsigned long c0;
    s16 t1;
    register s16 t0;
    s16 w;
    s16 h;

    w = arg2;
    h = arg3;
    if (w == 0 || h == 0) {
        return;
    }
    Prim2D_Begin();
    Prim2D_SetTex((void *)&gUiTexScratch, (u16)(arg4 | 1));
    Prim2D_PrepareTex();
    c0 = arg6[0];
    c1 = arg6[1];
    c2 = arg6[2];
    c3 = arg6[3];
    *(s32 *)&sp2C = c0;
    *(s32 *)&sp24 = c2;
    *(s32 *)&sp20 = c3;
    *(s32 *)&sp28 = c1;
    Prim2D_AddPrim(3);
    Prim2D_SetRect((f32)arg0, (f32)arg1, (f32)w, (f32)h);
    t1 = arg5[1];
    t0 = arg5[0];
    Prim2D_SetUvRect((f32)t0, (f32)t1, (f32)(s16)(arg5[2] - t0), (f32)(s16)(arg5[3] - t1));
    if (arg7 & 1) {
        Prim2D_SwapUvU();
        *(s32 *)&tmp = *(s32 *)&sp2C;
        if (&sp2C != &sp28) {
            sp2C.r = sp28.r;
            sp2C.g = sp28.g;
            sp2C.b = sp28.b;
            sp2C.a = sp28.a;
        }
        if (&sp28 != &tmp) {
            sp28.r = tmp.r;
            sp28.g = tmp.g;
            sp28.b = tmp.b;
            sp28.a = tmp.a;
        }
    }
    if (arg7 & 2) {
        Prim2D_SwapUvV();
        *(s32 *)&tmp2 = *(s32 *)&sp24;
        if (&sp24 != &sp20) {
            sp24.r = sp20.r;
            sp24.g = sp20.g;
            sp24.b = sp20.b;
            sp24.a = sp20.a;
        }
        if (&sp20 != &tmp2) {
            sp20.r = tmp2.r;
            sp20.g = tmp2.g;
            sp20.b = tmp2.b;
            sp20.a = tmp2.a;
        }
    }
    Prim2D_EmitQuad();
    if (arg7 & 0x100) {
        Prim2D_RotateUvCcw();
    }
    if (arg7 & 0x200) {
        Prim2D_RotateUvCw();
    }
    *(s32 *)&sp10 = *(s32 *)&sp20;
    *(s32 *)&sp14 = *(s32 *)&sp24;
    *(s32 *)&sp18 = *(s32 *)&sp28;
    *(s32 *)&sp1C = *(s32 *)&sp2C;
    Prim2D_SetCornerColors(&sp1C, &sp18, &sp14, &sp10);
    Prim2D_EndPrim();
}
/* Draw a colored screen rect sized from uvRect, with optional UV flip/rotate. */
void Ui_DrawRect(s16 x, s16 y, s32 texFlags, s16 *uvRect, s32 *color, s32 uvFlags) {
    void Prim2D_RotateUvCw(void);
    void Prim2D_RotateUvCcw(void);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SwapUvV(void);
    void Prim2D_SwapUvU(void);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    extern f64 lbl_8036A868;
    s32 packedColor;

    Prim2D_Begin();
    Prim2D_SetTex(0, (u16)(texFlags | 2));
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)x, (f32)y, (f32)(s16)(uvRect[2] - uvRect[0]), (f32)(s16)(uvRect[3] - uvRect[1]));
    if (uvFlags & 1) {
        Prim2D_SwapUvU();
    }
    if (uvFlags & 2) {
        Prim2D_SwapUvV();
    }
    if (uvFlags & 0x100) {
        Prim2D_RotateUvCcw();
    }
    if (uvFlags & 0x200) {
        Prim2D_RotateUvCw();
    }
    packedColor = *color;
    Prim2D_SetColorPacked(&packedColor);
    Prim2D_EndPrim();
}

void fn_80161F7C(void) {
    M2C_UNK FileCache_ReleaseSlot(M2C_UNK *);
    extern M2C_UNK gUiTexAtlas;
    extern M2C_UNK lbl_803680CC;
    extern s32 lbl_803680D0;
    s32 temp_r0;

    temp_r0 = lbl_803680D0 - 1;
    lbl_803680D0 = temp_r0;
    if (temp_r0 == 0) {
        FileCache_ReleaseSlot(&gUiTexAtlas);
        FileCache_ReleaseSlot(&lbl_803680CC);
    }
}

s32 FileCache_IsReady(char *name);
u8 fn_80161FB8(void) {
    extern u32 lbl_80293AD8[];
    s32 var_r31;
    var_r31 = 0;
    if (((u8)FileCache_IsReady((char *)lbl_80293AD8[2]) != 0) && ((u8)FileCache_IsReady((char *)lbl_80293AD8[3]) != 0)) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}

void fn_80162018(void) {
    extern u32 lbl_80293AD8[];
    fn_8005C8B4(lbl_80293AD8[2]);
    fn_8005C8B4(lbl_80293AD8[3]);
}

void fn_80162054(void) {
    void fn_8006EEFC(void *, void *);
    extern M2C_UNK gUiTexAtlas;
    extern M2C_UNK lbl_803680CC;
    extern s32 lbl_803680D0;
    extern u32 lbl_80293AD8[];

    if (lbl_803680D0++ == 0) {
        fn_8006EEFC(&gUiTexAtlas, (void *)lbl_80293AD8[2]);
        fn_8006EEFC(&lbl_803680CC, (void *)lbl_80293AD8[3]);
    }
}

s32 fn_801620AC(void) {
    extern char lbl_80293B10[];
    return *(s32*)((u8*)lbl_80293B10 + 4);
}
extern f64 lbl_8036A868;
extern f32 lbl_8036A870;
#include "common.h"
extern u16 lbl_80367E28[];
extern u16 lbl_80367E00[];
extern u16 lbl_80367E30[];
extern u16 lbl_80367DF8[];
extern u16 lbl_80367E18[];
extern u16 lbl_80367E20[];
extern u16 lbl_80367E08[];
extern u16 lbl_80367E10[];
extern s32 gUiTexAtlas;
extern f64 lbl_8036A868;
extern f64 lbl_8036A888;
