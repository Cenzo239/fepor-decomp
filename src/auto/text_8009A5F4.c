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

#pragma scheduling reset

void fn_8009A5F4(void) {
    void Process_UnlinkByKey(void *);
    extern u8 lbl_80289EB8[16];
    Process_UnlinkByKey(lbl_80289EB8);
}

void fn_8009A61C(s32 arg0) {
    void Process_Create(void *, s32);
    extern u8 lbl_80289EB8[16];
    Process_Create(lbl_80289EB8, arg0);
}

#pragma scheduling off
#pragma global_optimizer off
void fn_8009A648(void *arg0) {
    extern f32 lbl_803697E0;
    s32 z;
    f32 f;

    z = 0;
    f = lbl_803697E0;
    ((u8 *)arg0)[0x3E] = (u8)z;
    *(f32 *)((u8 *)arg0 + 0x30) = f;
    ((u8 *)arg0)[0x3D] = (u8)z;
}
#pragma scheduling off
#pragma global_optimizer off
void fn_8009A660(u8 *arg0) {
    extern f32 lbl_803697E4;
    u8 t;
    f32 f;

    t = arg0[0x40];
    f = lbl_803697E4;
    arg0[0x3E] = t;
    *(f32 *)(arg0 + 0x30) = f;
    arg0[0x3D] = arg0[0x3F];
}
#pragma global_optimizer reset
#pragma scheduling on
void fn_8009A67C(void *arg0) {
    f32 Math_Lerp(u8, u8, f32, f32, f32, f32);
    f32 Math_EaseOutPow(M2C_UNK, u8, f32, f32, f32, f32);
    extern f32 lbl_803697E4;
    extern f32 lbl_803697E8;
    u8 temp_r3;
    u8 temp_r3_2;
    u8 temp_r4;
    u8 temp_r5;

    temp_r3 = M2C_FIELD(arg0, u8 *, 0x3E);
    if (temp_r3 != 0) {
        M2C_FIELD(arg0, u8 *, 0x3E) = (u8) (temp_r3 - 1);
    }
    temp_r5 = M2C_FIELD(arg0, u8 *, 0x3F);
    temp_r3_2 = M2C_FIELD(arg0, u8 *, 0x40);
    M2C_FIELD(arg0, s8 *, 0x3D) = (s8) Math_Lerp(temp_r3_2, temp_r5, lbl_803697E4, (f32) temp_r5, (f32) temp_r3_2, (f32) M2C_FIELD(arg0, u8 *, 0x3E));
    temp_r4 = M2C_FIELD(arg0, u8 *, 0x40);
    M2C_FIELD(arg0, f32 *, 0x30) = Math_EaseOutPow(2, temp_r4, lbl_803697E8, lbl_803697E4, (f32) temp_r4, (f32) M2C_FIELD(arg0, u8 *, 0x3E));
    if ((u8) M2C_FIELD(arg0, u8 *, 0x3E) == 0) {
        Process_ClearFunc(arg0);
    }
}

void fn_8009A76C(void *arg0) {
    f32 Math_Lerp(u8, u8, f32, f32, f32, f32);
    f32 Math_EaseOutPow(M2C_UNK, u8, f32, f32, f32, f32);
    extern f32 lbl_803697E4;
    extern f32 lbl_803697E8;
    u8 temp_r3;
    u8 temp_r3_2;
    u8 temp_r4;
    u8 temp_r5;

    temp_r3 = M2C_FIELD(arg0, u8 *, 0x3E);
    if (temp_r3 < (u8) M2C_FIELD(arg0, u8 *, 0x40)) {
        M2C_FIELD(arg0, u8 *, 0x3E) = (u8) (temp_r3 + 1);
    }
    temp_r5 = M2C_FIELD(arg0, u8 *, 0x3F);
    temp_r3_2 = M2C_FIELD(arg0, u8 *, 0x40);
    M2C_FIELD(arg0, s8 *, 0x3D) = (s8) Math_Lerp(temp_r3_2, temp_r5, lbl_803697E4, (f32) temp_r5, (f32) temp_r3_2, (f32) M2C_FIELD(arg0, u8 *, 0x3E));
    temp_r4 = M2C_FIELD(arg0, u8 *, 0x40);
    M2C_FIELD(arg0, f32 *, 0x30) = Math_EaseOutPow(2, temp_r4, lbl_803697E8, lbl_803697E4, (f32) temp_r4, (f32) M2C_FIELD(arg0, u8 *, 0x3E));
    if ((u8) M2C_FIELD(arg0, u8 *, 0x3E) == (u8) M2C_FIELD(arg0, u8 *, 0x40)) {
        Process_ClearFunc(arg0);
    }
}

void fn_8009A864(void *arg0) {
    void fn_8006D8E8(u32);
    u32 v = *(u32 *)((char *)arg0 + 0x38);
    if (v != 0) {
        fn_8006D8E8(v);
    }
}

void fn_8009A890(void *arg0) {
    M2C_UNK fn_80055C8C(void *, void *, void *);
    M2C_UNK Process_AttachFunc(void *, void *);
    void fn_8009A934(void *);
    void fn_8009A970(void *);
    extern u8 lbl_8026D404[];

    M2C_FIELD(arg0, f32 *, 0x30) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x34) = 0.0f;
    M2C_FIELD(arg0, u8 *, 0x3D) = 0;
    M2C_FIELD(arg0, u8 *, 0x3F) = 0xC0;
    M2C_FIELD(arg0, u8 *, 0x40) = 0xA;
    M2C_FIELD(arg0, u8 *, 0x3E) = 0;
    M2C_FIELD(arg0, u8 *, 0x3C) = 0;
    M2C_FIELD(arg0, s16 *, 0x42) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, s16 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s16 *, 0x46) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s16 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    fn_80055C8C(lbl_8026D404 + 0xD8, fn_8009A934, arg0);
    Process_AttachFunc(fn_8009A970, arg0);
}

void fn_8009A934(void *arg0) {
    s32 fn_8006D948(void *);
    extern u8 lbl_8026D404[];
    *(s32 *)((char *)arg0 + 0x38) = fn_8006D948(lbl_8026D404 + 0xD8);
}

#pragma use_lmw_stmw on
void fn_8009A970(void *arg0) {
void Prim2D_EmitQuad(void);
void Prim2D_SetRectUv(f32,f32,f32,f32,f32,f32);
void Prim2D_EndPrim(void);
void Prim2D_AddPrim(s32);
void fn_80009B28(void);
void Prim2D_SetColorByte(u8);
void Prim2D_SetTransform(f32,f32,f32,f32);
void Prim2D_BindTexture(u32,s32,s32);
void Prim2D_PrepareTex(void);
void Prim2D_Begin(void);
s32 fn_8009ADC0(u32,s32,f32,f32);
void fn_8009B028(void *,u32,s32,f32,f32);
extern f32 lbl_803697E4;
extern f32 lbl_803697F8;
extern f32 lbl_803697FC;
extern f32 lbl_80369800;
extern f32 lbl_80369804;
extern f32 lbl_80369808;
extern f32 lbl_8036980C;
extern f32 lbl_80369810;
extern f32 lbl_80369814;
extern f32 lbl_80369818;
extern f32 lbl_8036981C;
extern f32 lbl_80369820;
extern f32 lbl_80369824;
extern f32 lbl_80369828;
extern f32 lbl_8036982C;
extern f32 lbl_80369830;
extern f32 lbl_80369834;
extern f32 lbl_80369838;
extern f32 lbl_8036983C;
extern f32 lbl_80369840;
extern f32 lbl_80369844;


    f32 temp_f29;
    f32 temp_f2;
    f32 temp_f31;
    f32 temp_f30;
    s32 var_r26;
    s32 temp_r0;
    s32 temp_r25;
    u32 temp_r25_2;
    u32 temp_r26;
    s32 var_r24;
    s32 var_r27;
    s32 var_r31;
    u8 temp_r5;

    temp_r5 = *(u8 *)((u8 *)arg0 + 0x3D);
    if ((temp_r5 != 0) && ((u32) *(u32 *)((u8 *)arg0 + 0x38) != 0U) && ((u32) (((u8) gBattleState[0x9C] >> 2U) & 1) != 1)) {
        temp_r0 = (temp_r5 * 2) & 0x1FE;
        var_r31 = temp_r0;
        if (temp_r0 > 0xFF) {
            var_r31 = 0xFF;
        }
        fn_8009B028(arg0, *(u32 *)((u8 *)arg0 + 0x38), var_r31, lbl_803697F8 + *(f32 *)((u8 *)arg0 + 0x30), lbl_803697F8 + *(f32 *)((u8 *)arg0 + 0x34));
        temp_r25 = (s32) (fn_8009ADC0(*(u32 *)((u8 *)arg0 + 0x38), var_r31, lbl_803697FC + *(f32 *)((u8 *)arg0 + 0x30), lbl_80369800 + *(f32 *)((u8 *)arg0 + 0x34)) + 7) / 8;
        temp_f31 = *(f32 *)((u8 *)arg0 + 0x30);
        temp_f29 = lbl_80369804 + *(f32 *)((u8 *)arg0 + 0x34);
        temp_r26 = *(u32 *)((u8 *)arg0 + 0x38);
        Prim2D_Begin();
        Prim2D_SetTransform(temp_f31, temp_f29, lbl_80369808, lbl_8036980C);
        Prim2D_BindTexture(temp_r26, 2, 0x11);
        Prim2D_SetColorByte((u8) var_r31);
        Prim2D_PrepareTex();
        for (var_r27 = 0, var_r24 = 0; var_r27 < temp_r25 - 1; ++var_r27, var_r24 += 8) {
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv((f32) var_r24, lbl_803697E4, lbl_803697E4, lbl_803697E4, lbl_80369810, lbl_80369810);
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
        }
        Prim2D_Begin();
        Prim2D_SetTransform(temp_f31, temp_f29, lbl_80369808, lbl_8036980C);
        Prim2D_BindTexture(temp_r26, 1, 0x11);
        Prim2D_SetColorByte((u8) var_r31);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32) ((temp_r25 - 1) * 8), lbl_80369814, lbl_803697E4, lbl_803697E4, lbl_80369818, lbl_8036981C);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        fn_80009B28();
        if (*(s16 *)(gBattleState + 0x12) != 0) {
            temp_f29 = *(f32 *)((u8 *)arg0 + 0x30);
            temp_f31 = lbl_80369820 + *(f32 *)((u8 *)arg0 + 0x34);
            temp_r26 = *(u32 *)((u8 *)arg0 + 0x38);
            Prim2D_Begin();
            Prim2D_SetTransform(temp_f29, temp_f31, lbl_80369808, lbl_8036980C);
            Prim2D_BindTexture(temp_r26, 2, 0x11);
            Prim2D_SetColorByte((u8) var_r31);
            Prim2D_PrepareTex();
            temp_r25 = 0;
            var_r24 = 0;
            do {
                Prim2D_AddPrim(1);
                Prim2D_SetRectUv((f32) var_r24, lbl_803697E4, lbl_803697E4, lbl_803697E4, lbl_80369810, lbl_80369810);
                Prim2D_EmitQuad();
                Prim2D_EndPrim();
                temp_r25 += 1;
                var_r24 += 8;
            } while (temp_r25 < 0xD);
            Prim2D_Begin();
            Prim2D_SetTransform(temp_f29, temp_f31, lbl_80369808, lbl_8036980C);
            Prim2D_BindTexture(temp_r26, 1, 0x11);
            Prim2D_SetColorByte((u8) var_r31);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv(lbl_80369824, lbl_80369814, lbl_803697E4, lbl_803697E4, lbl_80369818, lbl_8036981C);
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            fn_80009B28();
            temp_f2 = *(f32 *)((u8 *)arg0 + 0x34);
            temp_f30 = lbl_80369828 + temp_f2;
            var_r26 = *(s16 *)(gBattleState + 0x12);
            temp_f29 = lbl_803697FC + *(f32 *)((u8 *)arg0 + 0x30);
            temp_r25_2 = *(u32 *)((u8 *)arg0 + 0x38);
            Prim2D_Begin();
            Prim2D_SetTransform(temp_f29, temp_f30, lbl_80369808, lbl_8036980C);
            Prim2D_BindTexture(temp_r25_2, 3, 0x11);
            Prim2D_SetColorByte((u8) var_r31);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv(lbl_803697E4, lbl_8036982C, lbl_8036980C, lbl_80369830, lbl_80369834, lbl_80369838);
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            temp_f29 = lbl_8036983C;
            temp_f31 = lbl_80369844;
            while (var_r26 != 0) {
                Prim2D_AddPrim(1);
                Prim2D_SetRectUv(temp_f29, lbl_803697E4, (f32)((var_r26 % 10) * 0x13), lbl_803697E4, lbl_80369840, lbl_803697FC);
                Prim2D_EmitQuad();
                Prim2D_EndPrim();
                temp_f29 -= temp_f31;
                var_r26 /= 10;
            }
            fn_80009B28();
        }
        fn_80009B28();
    }
}
s32 fn_8009ADC0(s32 arg0, s32 arg1, f32 farg0, f32 farg1) {
    void Prim2D_EmitQuad(void);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void fn_80009B28(void);
    void Prim2D_SetColorByte(u8);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void fn_8005926C(s32, s32, s32, s32, s32, s32, s32, s32);
    void fn_8014C880(void *, s32, u8 *, u8 *);
    extern u8 lbl_8026D3F8[];
    extern f32 lbl_803697E4;
    extern f32 lbl_803697FC;
    extern f32 lbl_80369808;
    extern f32 lbl_8036980C;
    extern f32 lbl_8036982C;
    extern f32 lbl_80369830;
    extern f32 lbl_80369834;
    extern f32 lbl_80369844;
    extern f32 lbl_80369850;
    extern f32 lbl_80369854;
    extern f32 lbl_80369858;
    extern f32 lbl_8036985C;
    extern f32 lbl_80369860;
    static s32 width = 0x46;
    u8 buf[12];
    u8 sp9;
    u8 sp8;
    s32 saved;
    s32 var_r30;
    s32 temp_r29;

    saved = arg0;
    temp_r29 = arg1;
    sp9 = 0;
    sp8 = 0;
    fn_8014C880(gBattleState, 0, &sp9, &sp8);
    Prim2D_Begin();
    Prim2D_SetTransform(farg0, farg1, lbl_80369808, lbl_8036980C);
    Prim2D_BindTexture(saved, 3, 0x11);
    Prim2D_SetColorByte(temp_r29);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv(lbl_803697E4, lbl_80369850, lbl_80369854, lbl_80369830, lbl_80369834, lbl_80369844);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    *(s32 *)&buf[0] = *(s32 *)&lbl_8026D3F8[0];
    var_r30 = 0x30;
    *(s32 *)&buf[4] = *(s32 *)&lbl_8026D3F8[4];
    buf[8] = lbl_8026D3F8[8];
    temp_r29 = buf[(s8)sp9];
    if ((s8)sp8 != 0) {
        Prim2D_Begin();
        Prim2D_BindTexture(saved, 6, 0x11);
        Prim2D_PrepareTex();
        fn_8005926C(0x38, 0xB, 0, 0, 0x10, 0x18, 0xC, (s8)sp8);
        Prim2D_Begin();
        Prim2D_BindTexture(saved, 7, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)width, lbl_8036982C, lbl_803697E4, lbl_803697E4, lbl_80369858, lbl_803697FC);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        var_r30 = 0x82;
    }
    Prim2D_Begin();
    Prim2D_BindTexture(saved, 5, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv((f32)(var_r30 - 8), lbl_8036985C, lbl_803697E4, (f32)((s8)sp9 * 0x19), (f32)temp_r29, lbl_80369860);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    var_r30 += temp_r29;
    fn_80009B28();
    return var_r30;
}

void fn_8009B028(void *arg0, u32 arg1, s32 arg2, f32 farg0, f32 farg1) {
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void fn_80009B28(void);
    void Prim2D_SetColorByte(u8);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(u32, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void *Msg_Expand(void *);
    void Text_Draw(s16, s32, s32, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    void *Terrain_GetEntry(s32);
    void *Item_GetByIid(void *);
    void fn_8005926C(s32, s32, s32, s32, s32, s32, s32, s32);
    void *fn_8005B73C(void *);
    void Ui_DrawTerrainInfoDecor(u32, s32, f32, f32);
    void *fn_8010F9BC(void *, s8, s8, s32);
    void *fn_8010FF24(void *, s8, s8, s32);
    extern u8 lbl_8026D404[];
    extern u8 gBattleMap[];
    extern u8 lbl_8032BB58[];
    extern f32 lbl_803697E4;
    extern f32 lbl_80369808;
    extern f32 lbl_8036980C;
    extern f32 lbl_80369864;
    extern f32 lbl_80369868;
    extern f32 lbl_8036986C;
    extern f32 lbl_80369870;
    extern f32 lbl_80369874;
    extern f32 lbl_80369878;

    void *unit;
    void *str;
    u32 tex;
    void *self;
    s32 x;
    s32 y;
    s32 kind;
    void *obj;
    void *walk;
    s32 i;
    u8 *p;
    s32 w;
    u8 alpha;

    self = arg0;
    tex = arg1;
    str = NULL;
    Prim2D_Begin();
    Prim2D_SetColorByte((u8)arg2);
    Prim2D_PrepareTex();

    y = (s8)(s32)*(f32 *)(gBattleState + 0x528);
    x = (s8)(s32)*(f32 *)(gBattleState + 0x524);
    kind = *(u8 *)(gBattleMap + x + (y << 6) + 0x100D);
    if (kind < 0) {
        goto after_cases;
    }
    unit = Terrain_GetEntry(kind);
    if (kind != 0x21) {
        if (kind < 0x21) {
            if (kind != 0x1C) {
                if (kind < 0x1C) {
                    if (kind == 9) {
                        goto case_common;
                    }
                    goto block_22;
                }
                goto block_22;
            }
            goto case_common;
        }
        if (kind >= 0x2D) {
            goto block_22;
        }
        if (kind >= 0x2B) {
            goto case_2b;
        }
        goto block_22;
    }

case_common:
    str = fn_8005B73C(unit);
    obj = fn_8010FF24(lbl_8032BB58, (s8)x, (s8)y, 4);
    if (obj != NULL && *(u8 *)((u8 *)obj + 4) != 0) {
        Ui_DrawTerrainInfoDecor(tex, 2, farg0, farg1);
        Prim2D_Begin();
        Prim2D_SetTransform(farg0, farg1, lbl_80369808, lbl_8036980C);
        Prim2D_BindTexture(tex, 4, 0x11);
        Prim2D_PrepareTex();
        fn_8005926C(0x68, 0x1B, 0, 0, 0xB, 0x1A, 9, *(u8 *)((u8 *)obj + 4));
        goto after_cases;
    }
    goto block_22;

case_2b:
    obj = fn_8010F9BC(lbl_8032BB58, (s8)x, (s8)y, 7);
    Ui_DrawTerrainInfoDecor(tex, 1, farg0, farg1);
    if (obj != NULL) {
        alpha = *(u8 *)((u8 *)obj + 5);
        Prim2D_Begin();
        Prim2D_SetTransform(farg0, farg1, lbl_80369808, lbl_8036980C);
        Prim2D_BindTexture(tex, 4, 0x11);
        Prim2D_PrepareTex();
        fn_8005926C(0x48, 0x1B, 0, 0, 0xB, 0x1A, 9, alpha);
        if (*(u16 *)((u8 *)self + 0x42) == 0) {
            *(u16 *)((u8 *)self + 0x42) = *(u16 *)((u8 *)Item_GetByIid(lbl_8026D404 + 0xEE) + 0xE);
            *(u16 *)((u8 *)self + 0x44) = *(u16 *)((u8 *)Item_GetByIid(lbl_8026D404 + 0xFB) + 0xE);
            *(u16 *)((u8 *)self + 0x46) = *(u16 *)((u8 *)Item_GetByIid(lbl_8026D404 + 0x108) + 0xE);
            *(u16 *)((u8 *)self + 0x48) = *(u16 *)((u8 *)Item_GetByIid(lbl_8026D404 + 0x117) + 0xE);
            *(void **)((u8 *)self + 0x4C) = Msg_Expand(lbl_8026D404 + 0x122);
            *(void **)((u8 *)self + 0x50) = Msg_Expand(lbl_8026D404 + 0x12E);
            *(void **)((u8 *)self + 0x54) = Msg_Expand(lbl_8026D404 + 0x13A);
            *(void **)((u8 *)self + 0x58) = Msg_Expand(lbl_8026D404 + 0x146);
        }
        walk = self;
        for (i = 0; i < 4; i++) {
            if (*(u16 *)((u8 *)walk + 0x42) == *(u8 *)((u8 *)obj + 4)) {
                walk = (u8 *)self + (i << 2);
                str = ((void **)walk)[0x13];
                break;
            }
            walk = (u8 *)walk + 2;
        }
    } else {
        str = lbl_8026D404 + 0x150;
    }
    goto after_cases;

block_22:
    p = *(u8 **)((u8 *)unit + 8);
    kind = (s8)p[0];
    y = (s8)p[1];
    x = (s8)p[2];
    Ui_DrawTerrainInfoDecor(tex, 0, farg0, farg1);
    Prim2D_Begin();
    Prim2D_SetTransform(farg0, farg1, lbl_80369808, lbl_8036980C);
    Prim2D_BindTexture(tex, 4, 0x11);
    Prim2D_PrepareTex();
    fn_8005926C(0x28, 0x1A, 0, 0, 0xB, 0x1A, 9, kind);
    fn_8005926C(0x50, 0x1A, 0, 0, 0xB, 0x1A, 9, y);
    fn_8005926C(0x80, 0x1A, 0, 0, 0xB, 0x1A, 9, x);
    str = fn_8005B73C(unit);

after_cases:
    if (str != NULL) {
        Prim2D_Begin();
        Prim2D_SetTransform(farg0, farg1, lbl_80369808, lbl_8036980C);
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        w = 0x90 - Text_MeasureWidth(str, -1, lbl_8036980C);
        w = ((s32)((u32)w >> 31) + w) >> 1;
        Text_Draw((s16)w, -1, 1, str);
    }

    Prim2D_Begin();
    Prim2D_SetTransform(farg0, farg1, lbl_80369808, lbl_8036980C);
    Prim2D_BindTexture(tex, 0, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv(lbl_803697E4, lbl_803697E4, lbl_803697E4, lbl_803697E4, lbl_80369864, lbl_80369868);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(2);
    Prim2D_SetQuadMin(lbl_8036986C, lbl_80369870, lbl_803697E4, lbl_803697E4);
    Prim2D_SetQuadMax(lbl_80369874, lbl_80369878, lbl_803697E4, lbl_803697E4);
    Prim2D_SetColor(0, 0, 0x2C, 0x66);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    fn_80009B28();
}

