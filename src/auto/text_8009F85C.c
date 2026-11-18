/* Functions from 0x8009F85C to 0x800A399C, found by decomp-toolkit. */
#include "common.h"

static inline u8 *MenuCmd_FindStatus(s32 slot) {
    void *Map_GetCursorUnit(void);
    void *fn_80105C5C(void *, u8);
    u8 *unit = Map_GetCursorUnit();
    s32 count = 0;
    s32 i = count;
    for (; i < 0x62; i++) {
        u8 *status = fn_80105C5C(unit + 0x1BC, (u8)i);
        if (status != 0) {
            if (count == slot) return status;
            count++;
        }
    }
    return 0;
}

extern s32 lbl_80367788;
extern u8 lbl_80367704;
void *fn_8009F85C(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x277;
}

void *fn_8009F86C(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x27E;
}

s32 fn_8009F87C(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_80367788, arg1, 0);
    return 0;
}

void fn_8009F8A8(void *unused, void *arg1) {
    M2C_UNK WpnType_GetName(u8, M2C_UNK);
    WpnType_GetName(M2C_FIELD(arg1, u8 *, 0x3A), 0);
}

s32 fn_8009F8D0(s32 arg0, s32 arg1, void *arg2) {
    void *Map_GetCursorUnit(void);
    u8 Unit_GetWpnExp(void *, u8);
    extern void *gPadInput;
    u8 *base;
    u8 index;
    s32 value;
    s32 step;
    void *obj;
    u32 flags;

    base = Map_GetCursorUnit();
    index = *(u8 *)((u8 *)arg2 + 0x3A);
    value = Unit_GetWpnExp(base, index);
    step = 1;
    obj = gPadInput;
    if (*(u32 *)((u8 *)obj + 4) & 0x400) {
        step = 8;
    }
    flags = *(u32 *)((u8 *)obj + 0x10);
    if (flags & 0x01000001) {
        value -= step;
    }
    if (flags & 0x02000002) {
        value += step;
    }
    if (value < 0) {
        value = 0;
    }
    if (value > 0xFB) {
        value = 0xFB;
    }
    *(base + index + 0x20C) = value;
    return 0;
}

/* Draw a menu text item, then overlay the cursor unit's weapon exp and rank letter. */
void Ui_DrawWpnRankMenuItem(s32 unused, s32 parent, void *item) {
    void *Map_GetCursorUnit(void);
    void Prim2D_SetText(void *);
    void Prim2D_SetScale(f32);
    void Prim2D_SetTint(s32, s32, s32, s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    s32 WpnRank_GetLetter(u8);
    void Ui_DrawMenuTextItem(s32, s32, void *);
    s32 Unit_GetWpnExp(void *, u8);
    void sprintf(u8 *, void *, ...);
    extern u8 gMenuCmdStrings[];
    extern f32 gItemMenuTextScale;
    u8 buf[8];
    u8 exp;
    s32 letter;

    exp = Unit_GetWpnExp(Map_GetCursorUnit(), *(u8 *)((u8 *)item + 0x3A));
    letter = WpnRank_GetLetter(exp);
    sprintf(buf, gMenuCmdStrings + 0x2A8, exp, letter);
    Ui_DrawMenuTextItem(unused, parent, item);
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)(*(s16 *)((u8 *)item + 0x30) + 0x40), (f32)*(s16 *)((u8 *)item + 0x32));
    Prim2D_SetText(buf);
    Prim2D_SetScale(gItemMenuTextScale);
    if (*(u8 *)((u8 *)item + 0x38) != 0) {
        Prim2D_SetTint(0xFF, 0xFF, 0, 0xFF);
    }
    if (*(u8 *)((u8 *)item + 0x39) == 2) {
        Prim2D_SetTint(0, 0, 0, 0xFF);
    }
    Prim2D_EndPrim();
}

void *fn_8009FAAC(void) {
    extern u16 gMenuCmdStrings[];
    return (char *)gMenuCmdStrings + 0x2C4;
}

#pragma use_lmw_stmw on
s32 fn_8009FABC(s32 arg0, s32 arg1, void *arg2) {
    void *Map_GetCursorUnit(void);
    void Status_Set(void *, u8);
    u8 *dst;
    u8 *entry;
    dst=Map_GetCursorUnit();
    entry=MenuCmd_FindStatus(*((u8 *)arg2+0x3A));
    if(entry) Status_Set(dst+0x1BC,entry[0x18]);
    return 0;
}
#pragma use_lmw_stmw on
s32 fn_8009FB4C(s32 arg0, s32 arg1, void *arg2) {
    void *Map_GetCursorUnit(void);
    void Ui_CreateMenu(void *, s32, s32);
    extern u8 lbl_803675E4;
    u8 *entry;
    Map_GetCursorUnit();
    entry=MenuCmd_FindStatus(*((u8 *)arg2+0x3A));
    if(entry==0) Ui_CreateMenu(&lbl_803675E4,arg1,0);
    return 0;
}
#pragma use_lmw_stmw reset


#pragma use_lmw_stmw on
void fn_8009FBE0(s32 unused, s32 parent, void *item) {
    void *Map_GetCursorUnit(void);
    void *fn_80105C5C(void *, u8);
    void *fn_8010586C(void *);
    void Prim2D_SetText(void *);
    void Prim2D_SetScale(f32);
    void Prim2D_SetTint(s32, s32, s32, s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Ui_DrawMenuTextItem(s32, s32, void *);
    void sprintf(u8 *, void *, ...);
    extern u8 gMenuCmdStrings[];
    extern f32 gItemMenuTextScale;
    u8 buf[32];
    s32 i;
    s32 count;
    s32 slot;
    u8 *unit;
    u8 *status;
    void *name;

    slot = *(u8 *)((u8 *)item + 0x3A);
    status = MenuCmd_FindStatus(slot);
    if (status != 0) {
        count = status[0x18];
        name = fn_8010586C(status);
        sprintf(buf, gMenuCmdStrings + 0x2C7, count, name);
    } else {
        sprintf(buf, gMenuCmdStrings + 0x2CF);
    }
    Ui_DrawMenuTextItem(unused, parent, item);
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)(*(s16 *)((u8 *)item + 0x30) + 0x38), (f32)*(s16 *)((u8 *)item + 0x32));
    Prim2D_SetText(buf);
    Prim2D_SetScale(gItemMenuTextScale);
    if (*(u8 *)((u8 *)item + 0x38) != 0) {
        Prim2D_SetTint(0xFF, 0xFF, 0, 0xFF);
    }
    if (*(u8 *)((u8 *)item + 0x39) == 2) {
        Prim2D_SetTint(0, 0, 0, 0xFF);
    }
    Prim2D_EndPrim();
}
#pragma use_lmw_stmw reset
void *fn_8009FD50(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x2d5;
}

s32 fn_8009FD60(void) {
    M2C_UNK fn_800EBD78(M2C_UNK, M2C_UNK);
    fn_800EBD78(0, 0);
    return 0;
}

void *fn_8009FD8C(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x2ed;
}

s32 fn_8009FD9C(void) {
    void Process_CreateChild(void *);
    extern u8 lbl_8028A384[];
    Process_CreateChild(lbl_8028A384);
    return 0;
}

void *fn_8009FDC8(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x2f8;
}

s32 fn_8009FDD8(void) {
    void Process_CreateChild(void *);
    extern u8 lbl_8028A350[];
    Process_CreateChild(lbl_8028A350);
    return 0;
}

void *fn_8009FE04(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x307;
}

s32 fn_8009FE14(void) {
    void Process_CreateChild(void *);
    extern u8 lbl_8028A31C[];
    Process_CreateChild(lbl_8028A31C);
    return 0;
}

void *fn_8009FE40(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x314;
}

s32 fn_8009FE50(void) {
    void Process_CreateChild(void *);
    extern u8 lbl_8028A2E8[];
    Process_CreateChild(lbl_8028A2E8);
    return 0;
}

void *fn_8009FE7C(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x325;
}

s32 fn_8009FE8C(void) {
    void Process_CreateChild(void *);
    extern u8 lbl_8028A2D0[];
    Process_CreateChild(lbl_8028A2D0);
    return 0;
}

void *fn_8009FEB8(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x33a;
}

s32 fn_8009FEC8(void) {
    M2C_UNK Card_PrintResult();
    M2C_UNK fn_801E25EC(M2C_UNK *);
    extern M2C_UNK gSaveDataBase;
    fn_801E25EC(&gSaveDataBase);
    Card_PrintResult();
    return 0;
}

void *fn_8009FEF4(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x34b;
}

s32 fn_8009FF04(void) {
    void Process_CreateChild(void *);
    extern u8 lbl_8028A2B0[];
    Process_CreateChild(lbl_8028A2B0);
    return 0;
}

void *fn_8009FF30(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x354;
}

s32 fn_8009FF40(void) {
    void Process_CreateChild(void *);
    extern u8 lbl_8028A298[];
    Process_CreateChild(lbl_8028A298);
    return 0;
}

void *fn_8009FF6C(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x365;
}

s32 fn_8009FF7C(void) {
    M2C_UNK fn_800EBF58();
    fn_800EBF58();
    return 0;
}

void *fn_8009FFA0(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x36a;
}

s32 fn_8009FFB0(s32 arg0, s32 arg1) {
    void *fn_800241C8(s32);
    M2C_UNK fn_8014A030(s32);
    fn_8014A030(M2C_FIELD(fn_800241C8(arg1), s32 *, 0x18));
    return 6;
}

void *fn_8009FFE0(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x370;
}

extern s32 lbl_8036773C;
s32 fn_8009FFF0(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_8036773C, arg1, 0);
    return 0;
}

void *fn_800A001C(void) {
    extern u16 gMenuCmdStrings[];
    return (char *)gMenuCmdStrings + 0x37A;
}

extern s32 lbl_80367550;
s32 fn_800A002C(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_80367550, arg1, 0);
    return 0;
}

void *fn_800A0058(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x386;
}

extern s32 lbl_8036757C;
s32 fn_800A0068(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_8036757C, arg1, 0);
    return 0;
}

void *fn_800A0094(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x38E;
}

extern s32 lbl_803676D4;
s32 fn_800A00A4(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_803676D4, arg1, 0);
    return 0;
}

void *fn_800A00D0(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x395;
}

extern s32 lbl_803676F8;
s32 fn_800A00E0(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_803676F8, arg1, 0);
    return 0;
}

void *fn_800A010C(void) {
    extern u8 gMenuCmdStrings[];
    return (char *)gMenuCmdStrings + 0x39E;
}

#pragma global_optimizer off

#pragma opt_lifetimes off
