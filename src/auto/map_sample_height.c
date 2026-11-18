/* Functions from 0x8001EEEC to 0x80028864, found by decomp-toolkit. */
#include "common.h"
#pragma cplusplus on
struct MenuSelection24768 { u8 pad[0x40]; u8 index; };
struct MenuController24768 { u32 pad;
virtual void v0() = 0;
virtual void v1() = 0;
virtual void v2() = 0;
virtual void v3() = 0;
virtual void v4() = 0;
virtual void v5() = 0;
virtual void v6() = 0;
virtual void v7() = 0;
virtual void v8() = 0;
virtual void v9() = 0;
virtual void v10() = 0;
virtual void v11(void *) = 0;
virtual void v12(void *) = 0;
virtual void v13(void *) = 0;
virtual u8 v14(void *) = 0;
virtual void v15() = 0;
virtual void v16() = 0;
virtual void v17() = 0;
virtual void v18() = 0;
virtual void v19() = 0;
virtual void v20() = 0;
virtual void v21() = 0;
virtual void v22() = 0;
virtual void v23() = 0;
virtual void v24() = 0;
virtual void v25() = 0;
virtual void v26() = 0;
virtual void * v27() = 0;
virtual void * v28() = 0;
};
struct MenuItem24768 {
virtual void v0() = 0;
virtual void v1() = 0;
virtual void * v2() = 0;
virtual void v3() = 0;
virtual void v4() = 0;
virtual void v5() = 0;
virtual void v6() = 0;
virtual void v7() = 0;
virtual void v8() = 0;
virtual void v9() = 0;
virtual void v10() = 0;
virtual void v11() = 0;
virtual void v12() = 0;
virtual void v13() = 0;
virtual void v14() = 0;
virtual void v15(void *,void *) = 0;
virtual void * v16(void *) = 0;
};
#pragma cplusplus off

typedef struct {
    s32 field_0x0;
    s32 field_0x4;
    s32 field_0x8;
    s32 field_0xC;
    s32 field_0x10;
    s32 field_0x14;
    s32 field_0x18;
    s32 field_0x1C;
    s32 field_0x20;
    s32 field_0x24;
    s32 field_0x28;
    s32 field_0x2C;
    s32 field_0x30;
    s32 field_0x34;
    s32 field_0x38;
} Actor;

#pragma fp_contract on
#pragma scheduling on

f32 Map_SampleHeight(void *arg0, f32 x, f32 y) {
    void fn_80203290(f32 *, f32 *, f32 *);
    extern u8 lbl_80268CE8[];
    extern f32 lbl_80368D88;
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    u8 *tbl;
    s32 ix_i;
    u32 iy_i;
    s32 six;
    s32 siy;
    f32 scale;
    f32 h;
    f32 t;


    tbl = lbl_80268CE8;
    ix_i = (s32)x;
    iy_i = (s32)y;
    six = (s8)ix_i;
    siy = (s8)iy_i;
    if (((y + (x - (f32)six)) - (f32)siy) > lbl_80368D88) {
        u32 w54, w4c, w50, w60, w58, w5c;
        s16 ha, hb, hc;
        f32 f0, f1, nz;
        u8 *cell;
        u8 *base2;
        base2 = (u8 *)arg0 + 0x20000;
        cell = base2 + ((six + (siy << 6)) * 8);
        w54 = *(u32 *)(tbl + 0x54);
        w4c = *(u32 *)(tbl + 0x4C);
        ha = *(s16 *)(cell - 0x3D22);
        hb = *(s16 *)(cell - 0x3D24);
        scale = *(f32 *)(base2 - 0x3D2C);
        w50 = *(u32 *)(tbl + 0x50);
        w60 = *(u32 *)(tbl + 0x60);
        h = (f32)ha * scale;
        w58 = *(u32 *)(tbl + 0x58);
        w5c = *(u32 *)(tbl + 0x5C);
        t = (f32)hb * scale;
        *(u32 *)&sp34 = w54;
        *(u32 *)&sp5C[0] = w4c;
        *(u32 *)&sp5C[1] = w50;
        *(u32 *)&sp28 = w60;
        sp34 = t - h;
        *(u32 *)&sp2C = w4c;
        *(u32 *)&sp5C[2] = *(u32 *)&sp34;
        *(u32 *)&sp30 = w50;
        hc = *(s16 *)(cell - 0x3D26);
        *(u32 *)&sp20 = w58;
        *(u32 *)&sp24 = w5c;
        *(u32 *)&sp50[0] = w58;
        *(u32 *)&sp50[1] = w5c;
        t = (f32)hc * scale;
        sp28 = t - h;
        *(u32 *)&sp50[2] = *(u32 *)&sp28;
        fn_80203290(sp5C, sp50, sp5C);
        f0 = sp5C[1] * y + sp5C[0] * x;
        nz = sp5C[2];
        f1 = sp5C[1] * (f32)(siy + 1) + sp5C[0] * (f32)(six + 1);
        f1 = -(f1 + nz * h);
        return -(f1 + f0) / nz;
    }
    {
        u32 w6c, w64, w68, w78, w70, w74;
        s16 ha, hb, hc;
        f32 f0, f1, nz;
        u8 *cell;
        u8 *base2;
        base2 = (u8 *)arg0 + 0x20000;
        cell = base2 + ((six + (siy << 6)) * 8);
        w6c = *(u32 *)(tbl + 0x6C);
        w64 = *(u32 *)(tbl + 0x64);
        ha = *(s16 *)(cell - 0x3D28);
        hb = *(s16 *)(cell - 0x3D26);
        scale = *(f32 *)(base2 - 0x3D2C);
        w68 = *(u32 *)(tbl + 0x68);
        w78 = *(u32 *)(tbl + 0x78);
        h = (f32)ha * scale;
        w70 = *(u32 *)(tbl + 0x70);
        w74 = *(u32 *)(tbl + 0x74);
        t = (f32)hb * scale;
        *(u32 *)&sp1C = w6c;
        *(u32 *)&sp44[0] = w64;
        *(u32 *)&sp44[1] = w68;
        *(u32 *)&sp10 = w78;
        sp1C = t - h;
        *(u32 *)&sp14 = w64;
        *(u32 *)&sp44[2] = *(u32 *)&sp1C;
        *(u32 *)&sp18 = w68;
        hc = *(s16 *)(cell - 0x3D24);
        *(u32 *)&sp8 = w70;
        *(u32 *)&spC = w74;
        *(u32 *)&sp38[0] = w70;
        *(u32 *)&sp38[1] = w74;
        t = (f32)hc * scale;
        sp10 = t - h;
        *(u32 *)&sp38[2] = *(u32 *)&sp10;
        fn_80203290(sp44, sp38, sp44);
        f0 = sp44[1] * y + sp44[0] * x;
        nz = sp44[2];
        f1 = sp44[1] * (f32)(s8)iy_i + sp44[0] * (f32)(s8)ix_i;
        f1 = -(f1 + nz * h);
        return -(f1 + f0) / nz;
    }
}

typedef struct {
    s32 width;
    s32 height;
    u8 pad8[5];
    u8 unitMap[0x6100];
    u8 pad1;
    s16 costMap[0x4040];
    s8 fogMap[64];
} Map_802CA518;
extern Map_802CA518 gBattleMap;
