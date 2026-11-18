// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

u8 lbl_80311CA8[0x10];
u8 lbl_80311CB8[0x28];
u8 lbl_80311CE0[0xA8];

#pragma push
#pragma use_lmw_stmw on
#pragma optimization_level 2
void fn_80072408(void)
{
    void fn_8022C260(void *, void (*)(void), void *, s32, u32);
    void fn_800725C8(void);

    extern u8 lbl_8028680C[];
    extern u8 gUiMenuDrawVtbl[];
    extern u8 lbl_8028459C[];
    extern u8 lbl_8026BB84[];
    extern u8 lbl_802867B8[];
    extern u8 lbl_802866E4[];
    extern u8 lbl_80285FE8[];
    extern u8 lbl_80286764[];
    extern void *lbl_80367350[2];
    extern void *lbl_80367358[2];

    typedef struct {
        void *f0;
        void *f4;
    } Pair;

    void *vtbl;
    void *p8680C;
    void *p8459C;
    Pair *base;
    void *rodata;
    void *p867B8;
    u8 *data;
    Pair *p38;
    void *data0;
    Pair *p10;
    Pair *p24;
    Pair *p0;
    void *p866E4;
    void *p86764;
    void *p67C;
    void *p628;
    void *p3D4;
    void *p2FC;
    void *p1FC;
    void **sbss50;
    void *p27C;
    void *p17C;
    void *s_ed;
    void *s_f5;
    void **sbss58;
    Pair *p6C;
    Pair *p94;
    Pair *p80;
    void *pFC;
    void *p7C;

    vtbl = gUiMenuDrawVtbl;
    p8680C = lbl_8028680C;
    p8459C = lbl_8028459C;
    base = (Pair *)lbl_80311CA8;
    rodata = lbl_8026BB84;
    p867B8 = lbl_802867B8;
    data = lbl_80285FE8;
    p38 = (Pair *)lbl_80311CE0;
    data0 = data;
    p10 = (Pair *)lbl_80311CB8;
    p24 = (Pair *)((u8 *)lbl_80311CA8 + 0x24);
    p0 = base;
    p866E4 = lbl_802866E4;
    p86764 = lbl_80286764;
    p67C = data + 0x67C;
    p628 = data + 0x628;
    p3D4 = data + 0x3D4;
    p2FC = data + 0x2FC;
    p1FC = data + 0x1FC;
    sbss50 = lbl_80367350;
    p27C = data + 0x27C;
    p17C = data + 0x17C;

    p38->f4 = vtbl;
    p10->f4 = vtbl;
    lbl_80367350[0] = p8459C;
    lbl_80367358[0] = p8459C;
    s_ed = (u8 *)rodata + 0xED;
    s_f5 = (u8 *)rodata + 0xF5;
    p24->f4 = vtbl;
    p0->f4 = vtbl;

    p38->f4 = p67C;
    lbl_80367350[0] = p628;
    lbl_80367358[0] = p628;
    sbss58 = lbl_80367358;
    p10->f4 = p67C;
    p24->f4 = p67C;

    p38->f4 = p3D4;
    lbl_80367350[0] = p2FC;
    lbl_80367358[0] = p2FC;
    p0->f4 = p67C;
    p10->f4 = p3D4;
    p24->f4 = p3D4;

    p38->f4 = p866E4;
    lbl_80367350[0] = p8680C;
    lbl_80367358[0] = p8680C;
    p0->f4 = p3D4;
    p10->f4 = p866E4;
    p24->f4 = p866E4;

    p38->f4 = p1FC;
    sbss50[1] = s_ed;
    lbl_80367350[0] = p867B8;
    sbss58[1] = s_f5;
    lbl_80367358[0] = p86764;

    *(void **)((u8 *)base + 0x00) = data0;
    p0->f4 = p866E4;
    *(void **)((u8 *)base + 0x10) = data0;
    p10->f4 = p27C;
    *(void **)((u8 *)base + 0x24) = data0;
    p24->f4 = p1FC;
    *(void **)((u8 *)base + 0x38) = data0;
    p38->f4 = p17C;

    fn_8022C260((u8 *)base + 0x4C, fn_800725C8, 0, 8, 4);

    p6C = (Pair *)((u8 *)base + 0x6C);
    p94 = (Pair *)((u8 *)base + 0x94);
    vtbl = gUiMenuDrawVtbl;
    p80 = (Pair *)((u8 *)base + 0x80);

    p94->f4 = vtbl;
    p80->f4 = vtbl;

    pFC = data + 0xFC;
    p7C = data + 0x7C;

    p94->f4 = p67C;
    p80->f4 = p67C;
    p94->f4 = p3D4;
    p80->f4 = p3D4;
    p94->f4 = pFC;
    *(void **)((u8 *)base + 0x80) = p6C;
    p80->f4 = pFC;

    *(s16 *)((u8 *)p80 + 0xE) = 0;
    *(s16 *)((u8 *)p80 + 0x10) = 0x46;
    *(void **)((u8 *)base + 0x94) = p6C;
    *(s16 *)((u8 *)p94 + 0xE) = 0;
    *(s16 *)((u8 *)p94 + 0x10) = 0x46;
    p94->f4 = p7C;
}
#pragma pop
