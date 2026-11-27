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
extern const f32 lbl_8036A7D0;
extern const f32 lbl_8036A7D4;
extern const f32 lbl_8036A7D8;
extern const f32 lbl_8036A7DC;
extern const f32 lbl_8036A7E0;
extern f64 lbl_8036A7E8;
extern u8 lbl_80367B0C;
extern u8 lbl_80367B0D;

void Heap_FreeRaw(s32);
s32 Heap_AllocRaw(s32);
void *Archive_Load(void *);
void Ui_CreateMenu(void *, s32, s32);
#pragma opt_strength_reduction off

extern s32 lbl_80367B00;
extern u8 lbl_80367B0D;

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

extern u16 *g_AccessoryArray;

void Stream_Write(void *, s32, void *);
void Stream_WriteU8(void *, u8);
void Stream_WriteS32(void *, s32);
void Stream_WriteU16(void *, u16);
void Stream_WriteS64(void *, s32, s32);
void fn_80105A30(void *, void *);
void fn_80014F94(void *, void *);
void fn_80199B88(void *, void *);
void fn_800BDAF8(void *, void *);
void Stream_WriteStr(void *, s32, void *);
void Stream_WritePad(void *, s32, u8);
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
extern u8 gMapObjEventList[];
#include "global.h"
extern u8 gBattleState[];

#pragma cplusplus on

#pragma cplusplus reset

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
 extern u8 gSoundMenuStrings[];
 extern u8 lbl_80367B0D;
 extern u8 lbl_80367B0E;
 s32 total = *(s8 *)&lbl_80367B0E;
 s32 page = *(s8 *)&lbl_80367B0D;
 sprintf(lbl_803306E8, gSoundMenuStrings + 0xF0, page + 1, total);
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
    extern char gSoundMenuStrings[];
    return &gSoundMenuStrings[0x104];
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

/* Draw the sound-menu Distance row: item label plus signed %+6d value. */
void SoundMenu_DrawDistanceItem(void *ctrl, void *parent, void *item) {
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
    extern f32 gOneF;
    extern f32 gMenuItemZBias;
    extern f32 gMenuTextScale;
    extern u8 gSoundMenuStrings[];
    char buf[8];

    Prim2D_Begin();
    Prim2D_SetTransform((f32)*(s16 *)((u8 *)parent + 0x30), (f32)*(s16 *)((u8 *)parent + 0x32),
                (*(Model **)((u8 *)parent + 0x3C))->v25() - gMenuItemZBias, gOneF);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)*(s16 *)((u8 *)item + 0x30), (f32)*(s16 *)((u8 *)item + 0x32));
    Prim2D_SetText((*(Drawer **)((u8 *)item + 0x34))->v4(item));
    Prim2D_SetScale(gMenuTextScale);
    if (*(u8 *)((u8 *)item + 0x38) != 0) {
        Prim2D_SetTint(0xFF, 0xFF, 0, 0xFF);
    }
    if (*(u8 *)((u8 *)item + 0x39) == 2) {
        Prim2D_SetTint(0, 0, 0, 0xFF);
    }
    Prim2D_EndPrim();
    sprintf(buf, gSoundMenuStrings + 0x10D, ((Obj *)ctrl)->v20());
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)(*(s16 *)((u8 *)item + 0x30) + 0x60), (f32)*(s16 *)((u8 *)item + 0x32));
    Prim2D_SetText(buf);
    Prim2D_SetScale(gMenuTextScale);
    if (*(u8 *)((u8 *)item + 0x38) != 0) {
        Prim2D_SetTint(0xFF, 0xFF, 0, 0xFF);
    }
    if (*(u8 *)((u8 *)item + 0x39) == 2) {
        Prim2D_SetTint(0, 0, 0, 0xFF);
    }
    Prim2D_EndPrim();
#pragma cplusplus off
}

#pragma cplusplus on
extern "C" s32 fn_8014B078(void *arg0) {
    s8 fn_80146BE4(s32);
    extern void *gPadInput;
    extern u8 *lbl_80367B14;
    extern u8 gSeCueSlots[];
    struct Ctrl {
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
        virtual s32 v17() = 0;
        virtual s32 v18() = 0;
        virtual s32 v19() = 0;
        virtual s32 v20() = 0;
        virtual void v21(s32) = 0;
    };
    struct SeCue {
        u8 pad[8];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6(u8) = 0;
        virtual void v7() = 0;
        virtual void v8(u8) = 0;
    };
    s32 val;
    s8 slot;
    SeCue *cue;

    val = ((Ctrl *)arg0)->v20();
    if (*(u32 *)((u8 *)gPadInput + 0x10) & 0x01000001) {
        val -= ((Ctrl *)arg0)->v17();
    }
    if (*(u32 *)((u8 *)gPadInput + 0x10) & 0x02000002) {
        val += ((Ctrl *)arg0)->v17();
    }
    if (val < ((Ctrl *)arg0)->v18()) {
        val = ((Ctrl *)arg0)->v18();
    }
    if (val > ((Ctrl *)arg0)->v19()) {
        val = ((Ctrl *)arg0)->v19();
    }
    ((Ctrl *)arg0)->v21(val);
    if (lbl_80367B14[5] & 4) {
        slot = fn_80146BE4(*(s32 *)lbl_80367B14);
        if (slot >= 0) {
            cue = (SeCue *)(gSeCueSlots + (u8)slot * 0x30);
            cue->v8(lbl_80367B14[6]);
            cue->v6(lbl_80367B14[7]);
        }
    }
    return 0;
}
#pragma cplusplus reset

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
    extern u16 gSoundMenuStrings[];
    return (u8 *)gSoundMenuStrings + 0x113;
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
    extern char gSoundMenuStrings[];
    return &gSoundMenuStrings[0x119];
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
    extern u8 gSoundMenuStrings[];
    return &gSoundMenuStrings[0x11F];
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
    extern u16 gSoundMenuStrings[];
    return (u8 *)gSoundMenuStrings + 0x126;
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
    extern u16 gSoundMenuStrings[];
    return (u8 *)gSoundMenuStrings + 0x12a;
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

#pragma push
#pragma optimization_level 3
#pragma global_optimizer off
#pragma opt_common_subs off
#pragma use_lmw_stmw off
void fn_8014B388(u8 *color, u8 *str, f32 x, f32 y, f32 z) {
    void fn_80222644(void *, void *, s32, s32, s32, s32, s32, s32);
    void GXInitTexObjLOD(void *, s32, s32, s32, s32, s32, f32, f32, f32);
    void fn_80222C50(void *, s32);
    void PSMTXScale(void *, f32, f32, f32);
    void fn_80224E50(void *, s32, s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void GXSetNumTexGens(s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXBegin(s32, s32, s32);
    extern u16 lbl_80292F60[];
    extern const f32 lbl_8036A7D0;
    extern const f32 lbl_8036A7D4;
    extern const f32 lbl_8036A7D8;
    extern const f32 lbl_8036A7DC;
    extern const f32 lbl_8036A7E0;
    extern f64 lbl_8036A7E8;
    u8 texObj[0x20];
    f32 mtx[3][4];
    f32 step;
    f32 y2;
    f32 y3;
    f32 y4;
    f32 y1;
    s32 col;
    s32 row;
    u8 ch_u;
    u8 a;
    u8 r;
    u8 g;
    u8 b;
    f32 one;

    fn_80222644(texObj, lbl_80292F60, 0x80, 0x20, 0, 0, 0, 0);
    GXInitTexObjLOD(texObj, 0, 0, 0, 0, 0, lbl_8036A7D0, lbl_8036A7D0, lbl_8036A7D0);
    fn_80222C50(texObj, 0);
    PSMTXScale(mtx, lbl_8036A7D4, lbl_8036A7D8, lbl_8036A7DC);
    fn_80224E50(mtx, 0x1E, 1);
    fn_802201A8(0, 1, 4, 0x1E, 0, 0x7D);
    GXSetNumChans(1);
    GXSetNumTexGens(0, 0);
    GXSetTevOrder(0, 0, 0, 4);
    one = lbl_8036A7DC;
    step = lbl_8036A7E0;
    y3 = y - one;
    y1 = one + y;
    y2 = step + y;
    y3 = step + y3;
    y4 = step + y1;
    goto check;
loop:
    if ((s8)ch_u > 0x20 && (s8)ch_u < 0x80) {
        s32 idx = (s8)ch_u - 0x20;
        col = idx & 0xF;
        row = idx / 16;
        row *= 8;
        if (row >= 0x20) {
            row -= 0x10;
        }
        fn_802245D8(1, 4, 5, 0);
        GXBegin(0x80, 0, 0x14);
        a = color[3];
        {
            f32 x0 = x - lbl_8036A7DC;
            *(volatile f32 *)0xCC008000 = x0;
            *(volatile f32 *)0xCC008000 = y;
            *(volatile f32 *)0xCC008000 = z;
            *(volatile u8 *)0xCC008000 = 0;
            *(volatile u8 *)0xCC008000 = 0;
            *(volatile u8 *)0xCC008000 = 0;
            *(volatile u8 *)0xCC008000 = a;
            *(volatile f32 *)0xCC008000 = (f32)(col << 3);
            *(volatile f32 *)0xCC008000 = (f32)row;
            {
                f32 x1 = lbl_8036A7E0 + x0;
                *(volatile f32 *)0xCC008000 = x1;
                *(volatile f32 *)0xCC008000 = y;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)((col << 3) + 8);
                *(volatile f32 *)0xCC008000 = (f32)row;
                *(volatile f32 *)0xCC008000 = x1;
                *(volatile f32 *)0xCC008000 = y2;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)((col << 3) + 8);
                *(volatile f32 *)0xCC008000 = (f32)(row + 8);
                *(volatile f32 *)0xCC008000 = x0;
                *(volatile f32 *)0xCC008000 = y2;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)(col << 3);
                *(volatile f32 *)0xCC008000 = (f32)(row + 8);
            }
            {
                f32 x2 = lbl_8036A7DC + x;
                f32 x3 = lbl_8036A7E0 + x2;
                *(volatile f32 *)0xCC008000 = x2;
                *(volatile f32 *)0xCC008000 = y;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)(col << 3);
                *(volatile f32 *)0xCC008000 = (f32)row;
                *(volatile f32 *)0xCC008000 = x3;
                *(volatile f32 *)0xCC008000 = y;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)((col << 3) + 8);
                *(volatile f32 *)0xCC008000 = (f32)row;
                *(volatile f32 *)0xCC008000 = x3;
                *(volatile f32 *)0xCC008000 = y2;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)((col << 3) + 8);
                *(volatile f32 *)0xCC008000 = (f32)(row + 8);
                *(volatile f32 *)0xCC008000 = x2;
                *(volatile f32 *)0xCC008000 = y2;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)(col << 3);
                *(volatile f32 *)0xCC008000 = (f32)(row + 8);
            }
            {
                f32 yLo = y - lbl_8036A7DC;
                f32 xr = lbl_8036A7E0 + x;
                *(volatile f32 *)0xCC008000 = x;
                *(volatile f32 *)0xCC008000 = yLo;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)(col << 3);
                *(volatile f32 *)0xCC008000 = (f32)row;
                *(volatile f32 *)0xCC008000 = xr;
                *(volatile f32 *)0xCC008000 = yLo;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)((col << 3) + 8);
                *(volatile f32 *)0xCC008000 = (f32)row;
                *(volatile f32 *)0xCC008000 = xr;
                *(volatile f32 *)0xCC008000 = y3;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)((col << 3) + 8);
                *(volatile f32 *)0xCC008000 = (f32)(row + 8);
                *(volatile f32 *)0xCC008000 = x;
                *(volatile f32 *)0xCC008000 = y3;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)(col << 3);
                *(volatile f32 *)0xCC008000 = (f32)(row + 8);
                *(volatile f32 *)0xCC008000 = x;
                *(volatile f32 *)0xCC008000 = y1;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)(col << 3);
                *(volatile f32 *)0xCC008000 = (f32)row;
                *(volatile f32 *)0xCC008000 = xr;
                *(volatile f32 *)0xCC008000 = y1;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)((col << 3) + 8);
                *(volatile f32 *)0xCC008000 = (f32)row;
                *(volatile f32 *)0xCC008000 = xr;
                *(volatile f32 *)0xCC008000 = y4;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)((col << 3) + 8);
                *(volatile f32 *)0xCC008000 = (f32)(row + 8);
                *(volatile f32 *)0xCC008000 = x;
                *(volatile f32 *)0xCC008000 = y4;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = 0;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)(col << 3);
                *(volatile f32 *)0xCC008000 = (f32)(row + 8);
                r = color[0];
                g = color[1];
                b = color[2];
                *(volatile f32 *)0xCC008000 = x;
                *(volatile f32 *)0xCC008000 = y;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = r;
                *(volatile u8 *)0xCC008000 = g;
                *(volatile u8 *)0xCC008000 = b;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)(col << 3);
                *(volatile f32 *)0xCC008000 = (f32)row;
                *(volatile f32 *)0xCC008000 = xr;
                *(volatile f32 *)0xCC008000 = y;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = r;
                *(volatile u8 *)0xCC008000 = g;
                *(volatile u8 *)0xCC008000 = b;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)((col << 3) + 8);
                *(volatile f32 *)0xCC008000 = (f32)row;
                *(volatile f32 *)0xCC008000 = xr;
                *(volatile f32 *)0xCC008000 = y2;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = r;
                *(volatile u8 *)0xCC008000 = g;
                *(volatile u8 *)0xCC008000 = b;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)((col << 3) + 8);
                *(volatile f32 *)0xCC008000 = (f32)(row + 8);
                *(volatile f32 *)0xCC008000 = x;
                *(volatile f32 *)0xCC008000 = y2;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = r;
                *(volatile u8 *)0xCC008000 = g;
                *(volatile u8 *)0xCC008000 = b;
                *(volatile u8 *)0xCC008000 = a;
                *(volatile f32 *)0xCC008000 = (f32)(col << 3);
                *(volatile f32 *)0xCC008000 = (f32)(row + 8);
            }
        }
    }
    x += step;
    str++;
check:
    ch_u = *str;
    if ((s8)ch_u != 0) {
        goto loop;
    }
}
#pragma pop
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

