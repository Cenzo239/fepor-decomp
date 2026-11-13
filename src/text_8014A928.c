/* Functions from 0x8014A370 to 0x8014E350, found by decomp-toolkit. */
#include "common.h"

extern s32 lbl_80367B00;
extern s32 lbl_80367B04;
extern u8 lbl_80367B0E;
extern u8 lbl_80367B44;

typedef struct { u8 a; u8 b; } Entry;
typedef struct { u8 pad[0x544]; s8 count; Entry entries[256]; } Obj;
extern u8 lbl_80367B08;
extern u8 lbl_80367B09;
extern u8 lbl_80367B0A;
extern u8 lbl_80367B0B;
extern u16 lbl_80292F60[];
extern f32 lbl_8036A7D0;
extern f32 lbl_8036A7D4;
extern f32 lbl_8036A7D8;
extern f32 lbl_8036A7DC;
extern f32 lbl_8036A7E0;
extern f64 lbl_8036A7E8;
extern u8 lbl_80367B0C;
extern u8 lbl_80367B0D;

void fn_800C426C(s32);
s32 fn_800C42AC(s32);
void *fn_8003FCCC(void *);
void fn_80024398(void *, s32, s32);
#pragma opt_strength_reduction off

extern s32 lbl_80367B00;
extern u8 lbl_80367B0D;

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

extern u16 *g_AccessoryArray;

void fn_8017A430(void *, s32, void *);
void fn_8017A5EC(void *, u8);
void fn_8017A574(void *, s32);
void fn_8017A5C4(void *, u16);
void fn_8017A4CC(void *, s32, s32);
void fn_80105A30(void *, void *);
void fn_80014F94(void *, void *);
void fn_80199B88(void *, void *);
void fn_800BDAF8(void *, void *);
void fn_8017A480(void *, s32, void *);
void fn_8017A3E0(void *, s32, u8);
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
extern u16 lbl_80367B68;

void strcpy(s32, u32);

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#include "common.h"
extern f32 lbl_8036A7F0;
extern M2C_UNK gBattleMap;
extern s32 lbl_80367B00;
extern s32 lbl_80367B04;
extern u8 lbl_80367B0D;

void Ui_PlaySeCue(s32, s32); /* extern */
#include "global.h"

extern void* fn_80019F04();
#include "common.h"
extern u8 gUnitLists[];
extern u8 gUnits[];
#include "common.h"
#include "ef.h"
#include "global.h"

extern u8 gBattleState[];
extern u8 lbl_80277060[];
extern u8 lbl_8032BB58[];
#include "global.h"
extern u8 gBattleState[];

s32 fn_8014A928(s32 unused0, s32 unused1, void *arg2) {
    if ((s8)lbl_80367B08 == 0) {
        lbl_80367B09 = lbl_80367B0D;
        lbl_80367B0B = *(u8 *)((u8 *)arg2 + 0x3A);
    } else {
        lbl_80367B0A = lbl_80367B0D;
        lbl_80367B0C = *(u8 *)((u8 *)arg2 + 0x3A);
    }
    return 9;
}

s32 fn_8014A960(void) {
    return 0;
}

s32 fn_8014A968(s32 unused, void *arg1) {
    s32 a = (s8)lbl_80367B0D;
    s32 b = *(u8 *)((u8 *)arg1 + 0x3A);
    return ((s32 *)lbl_80367B00)[a * 0x18 + b];
}

s32 fn_8014A98C(s32 arg0, s32 arg1, void *arg2)
{
    u8 *Hash_Lookup(s32);
    s8 fn_80146BE4(s32);
    void Ui_PlaySeCue(s32, s32);

    s32 index;
    s32 entry;

    index = *(u8 *)((u8 *)arg2 + 0x3A) + (s8)lbl_80367B0D * 0x18;

    if (index >= lbl_80367B04) {
        return 0;
    }

    entry = ((s32 *)lbl_80367B00)[index];

    if (!(Hash_Lookup(entry)[5] & 4) || (fn_80146BE4(entry) < 0)) {
        Ui_PlaySeCue(entry, 0x64);
    }

    return 0;
}

#pragma cplusplus on
extern "C" s32 fn_8014AA18(void *arg0, void *arg1, void *arg2) {
    void *Hash_Lookup(s32);
    void fn_80024398(void *, void *, s32);
    extern s32 lbl_80367B10;
    extern void *lbl_80367B14;
    extern u8 lbl_80367B34;
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9(void *, void *) = 0;
    };
    s32 index;
    s32 entry;

    index = *(u8 *)((u8 *)arg2 + 0x3A) + (s8)lbl_80367B0D * 0x18;
    lbl_80367B10 = index;
    if (index >= lbl_80367B04) {
        return 0;
    }
    entry = ((s32 *)lbl_80367B00)[index];
    lbl_80367B14 = Hash_Lookup(entry);
    ((Obj *)arg0)->v9(arg1, arg2);
    fn_80024398(&lbl_80367B34, arg1, 0);
    return 0;
}
#pragma cplusplus reset
s32 fn_8014AC68(void) {
    extern void *gPadInput;
    extern u8 lbl_80367B0D;
    extern u8 lbl_80367B0E;
    s32 e;
    void *p = gPadInput;

    if (*(u32 *)((u8 *)p + 0x10) & 0x1000001) {
        e = (s8)lbl_80367B0E;
        {
            s32 em1 = e;
            em1 -= 1;
            lbl_80367B0D = ((s8)lbl_80367B0D + em1) % e;
        }
    }
    if (*(u32 *)((u8 *)p + 0x10) & 0x2000002) {
        lbl_80367B0D = ((s8)lbl_80367B0D + 1) % (s8)lbl_80367B0E;
    }
    return 0;
}

s32 fn_8014ACE8(s32 unused0, s32 unused1, s32 arg2) {
    if ((s8)lbl_80367B08 == 0) {
        if ((arg2 & 0xFF) == (s8)lbl_80367B0B) {
            return 1;
        }
    } else if ((arg2 & 0xFF) == (s8)lbl_80367B0C) {
        return 1;
    }
    return 0;
}

char *fn_8014AD34(void) {
    void sprintf(void *, void *, ...);
    extern char lbl_803306E8[];
    extern u8 lbl_80276F00[];
    extern u8 lbl_80367B0D;
    extern u8 lbl_80367B0E;
    s32 page;
    s32 total;
    void *fmt;

    page = (s8)lbl_80367B0D + 1;
    total = (s8)lbl_80367B0E;
    fmt = lbl_80276F00 + 0xF0;
    sprintf(lbl_803306E8, fmt, page, total);
    return lbl_803306E8;
}

s32 fn_8014AD88(void) {
    return 0;
}

s32 fn_8014AD90(void) {
    return 0x200;
}

s32 fn_8014AD98(void) {
    return 0;
}

s32 fn_8014ADA0(void) {
    return 0xFFFF;
}

void *fn_8014ADAC(void) {
    extern char lbl_80276F00[];
    return &lbl_80276F00[0x104];
}

u16 fn_8014ADBC(void) {
    extern void *lbl_80367B14;
    return M2C_FIELD(lbl_80367B14, u16 *, 0x12);
}

void fn_8014ADC8(s32 arg0, s16 arg1) {
    extern void *lbl_80367B14;
    M2C_FIELD(lbl_80367B14, s16 *, 0x12) = arg1;
}

s32 fn_8014ADD4(void) {
    extern void *lbl_80367B14;
    if (M2C_FIELD(lbl_80367B14, u8 *, 5) & 4) {
        return 3;
    }
    return 1;
}

s32 fn_8014ADF0(void) {
    u8 *Hash_Lookup(s32);
    s8 fn_80146BE4(s32);
    void Ui_PlaySeCue(s32, s32);
    extern s32 *lbl_80367B14;

    s32 temp_r31 = *lbl_80367B14;
    if (!(Hash_Lookup(temp_r31)[5] & 4) || (fn_80146BE4(temp_r31) < 0)) {
        Ui_PlaySeCue(temp_r31, 0x64);
    }
    return 0;
}

void SoundMenu_DrawDistanceItem(void *arg0, void *arg1, void *arg2) {
#pragma cplusplus on
    struct Model {
        u8 pad[4];
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
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
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
        virtual f32 v25() = 0;
    };
    struct Drawer {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void *v4(void *) = 0;
    };
    struct Obj {
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
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual void v18() = 0;
        virtual void v19() = 0;
        virtual s32 v20() = 0;
    };
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
    void sprintf(void *, void *, ...);
    extern f32 lbl_8036A7BC;
    extern f32 lbl_8036A7C0;
    extern f32 lbl_8036A7C4;
    extern u8 lbl_80276F00[];
    char sp8[8];

    Prim2D_Begin();
    Prim2D_SetTransform((f32)*(s16 *)((u8 *)arg1 + 0x30), (f32)*(s16 *)((u8 *)arg1 + 0x32),
                (*(Model **)((u8 *)arg1 + 0x3C))->v25() - lbl_8036A7C0, lbl_8036A7BC);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)*(s16 *)((u8 *)arg2 + 0x30), (f32)*(s16 *)((u8 *)arg2 + 0x32));
    Prim2D_SetText((*(Drawer **)((u8 *)arg2 + 0x34))->v4(arg2));
    Prim2D_SetScale(lbl_8036A7C4);
    if (*(u8 *)((u8 *)arg2 + 0x38) != 0) {
        Prim2D_SetTint(0xFF, 0xFF, 0, 0xFF);
    }
    if (*(u8 *)((u8 *)arg2 + 0x39) == 2) {
        Prim2D_SetTint(0, 0, 0, 0xFF);
    }
    Prim2D_EndPrim();
    sprintf(sp8, lbl_80276F00 + 0x10D, ((Obj *)arg0)->v20());
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)(*(s16 *)((u8 *)arg2 + 0x30) + 0x60), (f32)*(s16 *)((u8 *)arg2 + 0x32));
    Prim2D_SetText(sp8);
    Prim2D_SetScale(lbl_8036A7C4);
    if (*(u8 *)((u8 *)arg2 + 0x38) != 0) {
        Prim2D_SetTint(0xFF, 0xFF, 0, 0xFF);
    }
    if (*(u8 *)((u8 *)arg2 + 0x39) == 2) {
        Prim2D_SetTint(0, 0, 0, 0xFF);
    }
    Prim2D_EndPrim();
#pragma cplusplus off
}

s32 fn_8014B20C(void) {
    return 0x7F;
}

s32 fn_8014B214(void) {
    return 0;
}

s32 fn_8014B21C(void) {
    return 3;
}

s32 fn_8014B224(void) {
    return 0x200;
}

s32 fn_8014B22C(void) {
    return -0x2000;
}

s32 fn_8014B234(void) {
    return 0x1FFF;
}

void *fn_8014B23C(void) {
    extern u16 lbl_80276F00[];
    return (u8 *)lbl_80276F00 + 0x113;
}

s16 fn_8014B24C(void) {
    extern s16 *lbl_80367B14;
    return lbl_80367B14[8];
}

void fn_8014B258(u16 arg0, u16 arg1) {
    extern u8 *lbl_80367B14;

    *(u16 *)(lbl_80367B14 + 0x10) = arg1;
}

s32 fn_8014B264(void) {
    return 0xFF;
}

void *fn_8014B26C(void) {
    extern char lbl_80276F00[];
    return &lbl_80276F00[0x119];
}

u8 fn_8014B27C(void) {
    extern u8 *lbl_80367B14;

    return lbl_80367B14[0xF];
}

void fn_8014B288(u8 arg0, u8 arg1) {
    extern u8 *lbl_80367B14;
    lbl_80367B14[0xF] = arg1;
}

void *fn_8014B294(void) {
    extern u8 lbl_80276F00[];
    return &lbl_80276F00[0x11F];
}

u8 fn_8014B2A4(void) {
    // Returns byte at offset 0xC in the data pointed to by lbl_80367B14
    extern void *lbl_80367B14;
    return *(u8 *)((char *) lbl_80367B14 + 0xC);
}

void fn_8014B2B0(u8 arg0, u8 arg1) {
    extern u8 *lbl_80367B14;
    lbl_80367B14[0xC] = arg1;
}

void *fn_8014B2BC(void) {
    extern u16 lbl_80276F00[];
    return (u8 *)lbl_80276F00 + 0x126;
}

u8 fn_8014B2CC(void) {
    extern u8 *lbl_80367B14;
    return lbl_80367B14[0x7];
}

void fn_8014B2D8(u8 arg0, u8 arg1) {
    extern u8 *lbl_80367B14;

    lbl_80367B14[0x7] = arg1;
}

s32 fn_8014B2E4(void) {
    return 0;
}

void *fn_8014B2EC(void) {
    extern u16 lbl_80276F00[];
    return (u8 *)lbl_80276F00 + 0x12a;
}

u8 fn_8014B2FC(void) {
    extern u8 *lbl_80367B14;

    return lbl_80367B14[0x6];
}

void fn_8014B308(u8 arg0, u8 arg1) {
    extern u8 *lbl_80367B14;

    lbl_80367B14[0x6] = arg1;
}

s32 fn_8014B314(void) {
    return 1;
}

s32 fn_8014B31C(void) {
    extern s32 *lbl_80367B14;
    return *lbl_80367B14;
}

s32 fn_8014B328(void) {
    u8 *Hash_Lookup(s32);
    s8 fn_80146BE4(s32);
    void Ui_PlaySeCue(s32, s32);
    extern s32 *lbl_80367B14;

    s32 temp_r31 = *lbl_80367B14;
    if (!(Hash_Lookup(temp_r31)[5] & 4) || (fn_80146BE4(temp_r31) < 0)) {
        Ui_PlaySeCue(temp_r31, 0x64);
    }
    return 0;
}

void fn_8014BB58(s32 arg0, s32 arg1, s32 *arg2, s32 arg3) {
    M2C_UNK Prim2D_SetText(s32);
    M2C_UNK Prim2D_SetColorPacked(s32 *);
    M2C_UNK Prim2D_SetPos(f32, f32);
    M2C_UNK Prim2D_EndPrim();
    M2C_UNK Prim2D_AddPrim(M2C_UNK);
    M2C_UNK Prim2D_SetTex(M2C_UNK, M2C_UNK);
    M2C_UNK Prim2D_PrepareTex();
    M2C_UNK Prim2D_Begin();
    s32 sp8;

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x23);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(0xA);
    Prim2D_SetPos((f32) arg0, (f32) arg1);
    sp8 = *arg2;
    Prim2D_SetColorPacked(&sp8);
    Prim2D_SetText(arg3);
    Prim2D_EndPrim();
}

