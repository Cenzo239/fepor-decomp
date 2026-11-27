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

#pragma use_lmw_stmw on

#pragma use_lmw_stmw off
#pragma global_optimizer off
#pragma opt_strength_reduction off

#pragma opt_common_subs off
void UnitInfo_DrawCombatStats(void *arg0, s32 arg1) {
    void fn_8008BA80(void *, s32, s32, s32);
    void fn_8007D044(f32, f32, f32, f32, s32, u8);
    void fn_8008CD64(f32);
    void fn_8008CD34(void);
    s8 Unit_GetMaxHp(void *);
    s8 fn_8003A778(void *);
    void *Msg_Expand(char *);
    void fn_8001003C(s16, s32, s32, s32, s32, f32, f32, char *, ...);
    s32 fn_8010418C(void *, s32);
    s32 fn_8010424C(void *);
    void Ui_DrawIcon(void *, s32, s32, s32);

    extern f32 gZeroF;
    extern f32 lbl_80369780;
    extern f32 lbl_80369784;
    extern f32 lbl_8036978C;
    extern f32 lbl_80369768;
    extern char gBattleHelpStrings[];
    extern u8 gUiIconDrawer[];

    s32 combatArg;
    u8 *self;
    s32 maxHp;
    s32 hp;
    void *text;
    u8 *por;

    combatArg = arg1;
    self = (u8 *)arg0;
    fn_8008BA80(self, 0, 0, 0);
    por = *(u8 **)(self + 0x190);
    fn_8007D044(gZeroF, lbl_80369780, lbl_80369784, lbl_8036978C, 0xB3, por[8]);
    fn_8008CD64(lbl_80369768);
    fn_8008CD34();

    hp = self[0x1A8];
    maxHp = Unit_GetMaxHp(self);
    text = Msg_Expand(gBattleHelpStrings + 0x111);
    fn_8001003C(0x10, 0x2C, 1, 1, 0, 1.0f, 0.0f, gBattleHelpStrings + 0xFA, text, (s8)hp, (s8)maxHp);

    maxHp = fn_8003A778(self);
    text = Msg_Expand(gBattleHelpStrings + 0x143);
    fn_8001003C(0x10, 0x48, 1, 1, 0, 1.0f, 0.0f, gBattleHelpStrings + 0x117, text, (s8)maxHp);

    text = Msg_Expand(gBattleHelpStrings + 0x14B);
    fn_8001003C(0x86, 0x48, 1, 1, 0, 1.0f, 0.0f, gBattleHelpStrings + 0x117, text, combatArg);

    text = Msg_Expand(gBattleHelpStrings + 0x135);
    fn_8001003C(0x10, 0x64, 1, 1, 0, 1.0f, 0.0f, gBattleHelpStrings + 0x12D, text);

    maxHp = 0;
    hp = 0x48;
    while (maxHp < fn_8010424C(self + 0x1A4)) {
        Ui_DrawIcon(gUiIconDrawer, hp, 0x66, fn_8010418C(self + 0x1A4, maxHp));
        hp += 0x1A;
        maxHp++;
    }
}
#pragma use_lmw_stmw on
#pragma opt_common_subs off
void fn_80090688(void *arg0, s32 arg1, s32 arg2) {
    void fn_8008BA80(void *, s32, s32, s32);
    void fn_8007D044(f32, f32, f32, f32, s32, u8);
    void fn_8008CD64(f32);
    void fn_8008CD34(void);
    s8 Unit_GetMaxHp(void *);
    void *Msg_Expand(char *);
    void fn_8001003C(s16, s32, s32, s32, s32, char *, ...);
    s32 fn_800398B0(void *, s32);
    void *fn_80017570(s32);

    extern f32 gZeroF;
    extern f32 lbl_80369780;
    extern f32 lbl_80369784;
    extern f32 lbl_80369790;
    extern f32 lbl_80369768;
    extern f32 lbl_80369754;
    extern char gBattleHelpStrings[];

    u8 *por;
    s32 hp;
    s32 maxHp;
    s32 value1;
    s32 value2;
    void *text;

    fn_8008BA80(arg0, 0, 0, 0);
    por = *(u8 **)((u8 *)arg0 + 0x190);
    fn_8007D044(gZeroF, lbl_80369780, lbl_80369784, lbl_80369790, 0xB3, por[8]);
    fn_8008CD64(lbl_80369768);
    fn_8008CD34();

    hp = ((u8 *)arg0)[0x1A8];
    maxHp = Unit_GetMaxHp(arg0);
    text = Msg_Expand(gBattleHelpStrings + 0x111);
    fn_8001003C(0x10, 0x2C, 1, 1, 0, gBattleHelpStrings + 0xFA, text, (s8)hp, (s8)maxHp, lbl_80369754, gZeroF);

    value1 = (s8)fn_800398B0(arg0, (u8)arg1);
    value2 = (s8)fn_800398B0(arg0, (u8)arg1);
    text = fn_80017570(arg1);
    fn_8001003C(0x10, 0x48, 1, 1, 0, gBattleHelpStrings + 0x152, text, value2, lbl_80369754, gZeroF, arg2 + value1);
}
#pragma opt_common_subs on
#pragma use_lmw_stmw off
void UnitInfo_DrawInventoryPanel(void *arg0) {
    void fn_8008BA80(void *, s32, s32, u8);
    void fn_8008BBF8(s32, s32, s32, s32, u8, s32);
    void fn_8008CD64(f32);
    void UnitRef_Draw(s32, s32, s32, s32);
    s32 Unit_GetHeldItemSlot(void *, s32);
    s32 fn_8001C0C8(void);
    extern f32 lbl_80369768;

    s32 offset;
    s32 temp;
    s32 i;
    s32 id;

    fn_8008BA80(arg0, 0, 0, 1);
    fn_8008BBF8(0, 0x20, 0x108, 0x88, *(u8 *)(*(u8 **)((u8 *)arg0 + 0x190) + 8), 0x9A);
    offset = 0x2C;
    fn_8008CD64(lbl_80369768);
    i = 0;
    do {
        temp = Unit_GetHeldItemSlot(arg0, i);
        id = fn_8001C0C8();
        UnitRef_Draw(temp, id, 0x1C, offset);
        i += 1;
        offset += 0x1C;
    } while (i < 4);
}

#pragma use_lmw_stmw on
void UnitInfo_DrawItemStats(void *arg0, s32 arg1) {
    void fn_8008BA80(void *, s32, s32, u8);
    void fn_8008BBF8(s32, s32, s32, s32, u8, s32);
    void fn_8008CD64(f32);
    s32 Unit_CanReceiveItem(s32, void *);
    void *Unit_GetItemSlot(void *, s32);
    s32 Unit_GetHeldItemSlot(void *, s32);
    void UnitRef_Draw(s32, s32, s32, s32);
    u8 flags[8];
    s32 i;
    s32 y;
    u8 *write;
    s32 receiver;
    s32 j;
    u8 *p;
    u8 *base;
    u8 *unit;

    receiver = arg1;
    fn_8008BA80(arg0, 0, 0, 1);
    fn_8008BBF8(0, 0x20, 0x108, 0x110, *(u8 *)(*(u8 **)((u8 *)arg0 + 0x190) + 8), 0x9A);
    base = flags;
    j = 0;
    write = base;
    do {
        void *item = Unit_GetItemSlot(arg0, j);
        if (*(u32 *)item) {
            *write = Unit_CanReceiveItem(receiver, item);
        }
        j++;
        write++;
    } while (j < 8);
    fn_8008CD64(0.0f);
    p = base;
    y = 0x2C;
    i = 0;
    do {
        UnitRef_Draw(Unit_GetHeldItemSlot(arg0, i), *p, 0x1C, y);
        i++;
        y += 0x1C;
        p++;
    } while (i < 4);
    unit = arg0;
    i = 0;
    y += 0x18;
    do {
        UnitRef_Draw((s32)(unit + 0x1EC), base[4], 0x1C, y);
        i++;
        y += 0x1C;
        unit += 8;
        base++;
    } while (i < 4);
}
#pragma use_lmw_stmw reset
void UnitInfo_DrawBagPanel(void *arg0) {
    void fn_8008BA80(void *, s32, s32, u8);
    void fn_8008BBF8(s32, s32, s32, s32, u8, s32);
    void fn_8008CD64(f32);
    void UnitRef_Draw(s32, s32, s32, s32);
    s32 Unit_GetHeldItemSlot(void *, s32);
    void *Unit_GetItemSlot(void *, s32);
    u8 fn_80093DA8(void *);
    extern f32 lbl_80369768;

    u8 buf[8];
    s32 j;
    long var_r30;
    s32 i;
    u8 *base;
    register void *unit;

    unit = arg0;
    fn_8008BA80(unit, 0, 0, 1);
    fn_8008BBF8(0, 0x20, 0x108, 0x110, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8), 0x9A);

    base = buf;
    i = 0;
    var_r30 = (s32)base;
    do {
        if (*(u32 *)Unit_GetItemSlot(unit, i) != 0) {
            *(u8 *)var_r30 = fn_80093DA8(unit);
        }
        i += 1;
        ++var_r30;
    } while (i < 8);

    fn_8008CD64(lbl_80369768);

    i = (s32)base;
    var_r30 = 0x2C;
    j = 0;
    do {
        UnitRef_Draw(Unit_GetHeldItemSlot(unit, j), *(u8 *)i, 0x1C, var_r30);
        j += 1;
        var_r30 += 0x1C;
        i += 1;
    } while (j < 4);

    j = 0;
    i = (s32)unit;
    var_r30 += 0x18;
    do {
        UnitRef_Draw(i + 0x1EC, base[4], 0x1C, var_r30);
        j += 1;
        base += 1;
        i += 8;
        var_r30 += 0x1C;
    } while (j < 4);
}

#pragma use_lmw_stmw on
void UnitInfo_DrawHealStats(void *arg0, s32 arg1) {
    void fn_8008BA80(void *, s32, s32, s32);
    void fn_8007D044(s32, u8, f32, f32, f32, f32);
    void fn_8008CD64(f32);
    void fn_8008CD34(void);
    s8 Unit_GetMaxHp(void *);
    void *Msg_Expand(char *);
    void fn_8001003C(s16, s32, s32, s32, s32, char *, ...);
    s32 fn_8010418C(void *, s32);
    s32 fn_8010424C(void *);
    void Ui_DrawIcon(void *, s32, s32, s32);

    extern f32 gZeroF;
    extern f32 lbl_80369780;
    extern f32 lbl_80369784;
    extern f32 lbl_80369790;
    extern f32 lbl_80369768;
    extern f32 lbl_80369754;
    extern char gBattleHelpStrings[];
    extern u8 gUiIconDrawer[];

    s32 healAmount;
    s32 healedHp;
    s32 maxHp;
    void *text;
    s32 maxHp2;
    u8 *self;
    s32 hp;
    void *text2;
    void *drawer;
    s32 i;
    s32 x;
    u8 *p;

    healAmount = arg1;
    self = (u8 *)arg0;

    fn_8008BA80(self, 0, 0, 0);

    p = *(u8 **)(self + 0x190);
    fn_8007D044(
        0xB3,
        p[8],
        gZeroF,
        lbl_80369780,
        lbl_80369784,
        lbl_80369790
    );

    fn_8008CD64(lbl_80369768);
    fn_8008CD34();

    healedHp = healAmount + (s8)self[0x1A8];

    if (healedHp > (s8)Unit_GetMaxHp(self)) {
        healedHp = (s8)Unit_GetMaxHp(self);
    }

    hp = self[0x1A8];
    maxHp = (s8)Unit_GetMaxHp(self);

    text = Msg_Expand(gBattleHelpStrings + 0x111);

    maxHp2 = (s8)Unit_GetMaxHp(self);
    text2 = Msg_Expand(gBattleHelpStrings + 0x111);

    fn_8001003C(
        0x10,
        0x2C,
        1,
        1,
        0,
        gBattleHelpStrings + 0x168,
        text2,
        (s8)hp,
        lbl_80369754,
        gZeroF,
        maxHp2,
        text,
        healedHp,
        maxHp
    );

    text2 = Msg_Expand(gBattleHelpStrings + 0x135);

    fn_8001003C(
        0x10,
        0x48,
        1,
        1,
        0,
        gBattleHelpStrings + 0x12D,
        text2,
        lbl_80369754,
        gZeroF
    );

    i = 0;
    drawer = gUiIconDrawer;
    x = 0x48;

    while (i < fn_8010424C(self + 0x1A4)) {
        Ui_DrawIcon(
            drawer,
            x,
            0x4A,
            fn_8010418C(self + 0x1A4, i)
        );
        x += 0x1A;
        i++;
    }
}
#pragma opt_common_subs on
#pragma opt_strength_reduction on
void UnitInfo_DrawStatus(void *arg0)
{
  void fn_8008BA80(void *, s32, s32, s32);
  void fn_8007D044(f32, f32, f32, f32, s32, u8);
  int new_var;
  void fn_8008CD64(f32);
  void fn_8008CD34(void);
  s8 Unit_GetMaxHp(void *);
  s8 fn_8003A1E0(void *);
  char *new_var4;
  void *Msg_Expand(char *);
  void fn_8001003C(s16, s32, s32, s32, s32, char *, ...);
  s32 fn_8010418C(void *, s32);
  s32 fn_8010424C(void *);
  char *new_var3;
  void Ui_DrawIcon(void *, s32, s32, s32);
  extern f32 gZeroF;
  f32 new_var2;
  extern f32 lbl_80369780;
  extern f32 lbl_80369784;
  extern f32 lbl_80369790;
  extern f32 lbl_80369768;
  extern f32 lbl_80369754;
  extern char gBattleHelpStrings[];
  extern u8 gUiIconDrawer[];
  u8 *self;
  u8 *por;
  s32 maxHp;
  s32 hp;
  volatile long new_var5;
  s32 i;
  void *drawer;
  void *text;
  s32 x;
  self = (u8 *) arg0;
  fn_8008BA80(self, 0, 0, 0);
  por = *((u8 **) (0x190 + self));
  fn_8007D044(gZeroF, lbl_80369780, lbl_80369784, lbl_80369790, 0xB3, por[8]);
  new_var = 0x126;
  fn_8008CD64(lbl_80369768);
  fn_8008CD34();
  hp = self[0x1A8];
  maxHp = Unit_GetMaxHp(self);
  text = Msg_Expand((0, gBattleHelpStrings + 0x111));
  fn_8001003C(0x10, 0x2C, 1, 1, 0, gBattleHelpStrings + 0xFA, text, (s8) hp, new_var5 = (s8) maxHp, lbl_80369754, gZeroF);
  maxHp = fn_8003A1E0(self);
  text = Msg_Expand(gBattleHelpStrings + new_var);
  new_var3 = gBattleHelpStrings + 0x117;
  fn_8001003C(0x86, 0x2C, 1, 1, 0, new_var3, text, (s8) maxHp, lbl_80369754, gZeroF);
  text = Msg_Expand(gBattleHelpStrings + 0x135);
  new_var4 = gBattleHelpStrings + 0x12D;
  new_var2 = lbl_80369754;
  fn_8001003C(0x10, 0x48, 1, 1, 0, new_var4, text, new_var2, gZeroF);
  i = 0;
  x = 0x48;
  while (i < fn_8010424C(self + 0x1A4))
  {
    Ui_DrawIcon(gUiIconDrawer, x, 0x4A, fn_8010418C(self + 0x1A4, i));
    x += 0x1A;
    i++;
  }

}
#pragma opt_common_subs reset
#pragma opt_strength_reduction off
/* Draw a fixed-size unit-info panel fill tinted by allegiance, plus white translucent edge strips. */
void UnitInfo_DrawPanel(s32 x, s32 y, s32 allegiance)
{
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SetColor(u8, u8, u8, u8);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    extern s32 gUnitInfoPanelColorPlayer;
    extern s32 gUnitInfoPanelColorOther;
    extern s32 gUnitInfoPanelColorPartner;
    extern f32 gZeroF;
    extern f32 gUnitInfoPanelW;
    extern f32 gUnitInfoPanelH;
    extern f32 gUnitInfoPanelOuterW;
    extern f32 gUnitInfoPanelOuterH;
    u8 rgbaBytes[4];
    s32 colorPlayer;
    s32 colorOther;
    s32 colorPartner;
    s32 colorPacked;

    switch (allegiance) {
    case 0:
        colorPlayer = gUnitInfoPanelColorPlayer;
        rgbaBytes[0] = *(u8 *)&colorPlayer;
        rgbaBytes[1] = *(u8 *)((u8 *)&colorPlayer + 1);
        rgbaBytes[2] = *(u8 *)((u8 *)&colorPlayer + 2);
        rgbaBytes[3] = *(u8 *)((u8 *)&colorPlayer + 3);
        break;
    case 2:
        colorOther = gUnitInfoPanelColorOther;
        rgbaBytes[0] = *(u8 *)&colorOther;
        rgbaBytes[1] = *(u8 *)((u8 *)&colorOther + 1);
        rgbaBytes[2] = *(u8 *)((u8 *)&colorOther + 2);
        rgbaBytes[3] = *(u8 *)((u8 *)&colorOther + 3);
        break;
    case 3:
        colorPartner = gUnitInfoPanelColorPartner;
        rgbaBytes[0] = *(u8 *)&colorPartner;
        rgbaBytes[1] = *(u8 *)((u8 *)&colorPartner + 1);
        rgbaBytes[2] = *(u8 *)((u8 *)&colorPartner + 2);
        rgbaBytes[3] = *(u8 *)((u8 *)&colorPartner + 3);
        break;
    }
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)x, (f32)y, gUnitInfoPanelW, gUnitInfoPanelH);
    colorPacked = *(s32 *)rgbaBytes;
    Prim2D_SetColorPacked(&colorPacked);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetRect((f32)(x - 3), (f32)y, gUnitInfoPanelOuterW, gZeroF);
    Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0x4D);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetRect((f32)(x - 3), (f32)(y + 0x62), gUnitInfoPanelOuterW, gZeroF);
    Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0x4D);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetRect((f32)x, (f32)(y - 3), gZeroF, gUnitInfoPanelOuterH);
    Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0x4D);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetRect((f32)(x + 0xD0), (f32)(y - 3), gZeroF, gUnitInfoPanelOuterH);
    Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0x4D);
    Prim2D_EndPrim();
}

#pragma dont_inline on
#pragma global_optimizer off
void Ui_OpenWeaponKindHelp(u8 arg0, s32 parent, s8 kind2, s8 kind3, s8 kind4) {
    s32 fn_8005A310(void *, u8, u8);
    s32 sprintf(char *, const char *, ...);
    char *strcat(char *, const char *);
    void fn_8000D864(s32, char *);
    s32 Msg_Expand(void *);
    void Ui_OpenHelpPopup(s32, void *, s32, s32);

    extern u8 gUiIconDrawer[];
    extern u8 gBattleHelpStrings[];

    char text[0x40];
    char part1[0x10];
    char part2[0x10];
    char part3[0x10];
    char part4[0x10];
    u16 kind;

    text[0] = 0;

    kind = (u16)fn_8005A310(gUiIconDrawer, (u8)arg0, 0);
    sprintf(part1, (char *)gBattleHelpStrings + 0x19B, kind - 1);
    strcat(text, part1);

    if (kind2 >= 0) {
        kind = (u16)fn_8005A310(gUiIconDrawer, (u8)kind2, 0);
        sprintf(part2, (char *)gBattleHelpStrings + 0x19B, kind - 1);
        strcat(text, part2);
    }

    if (kind3 >= 0) {
        kind = (u16)fn_8005A310(gUiIconDrawer, (u8)kind3, 0);
        sprintf(part3, (char *)gBattleHelpStrings + 0x19B, kind - 1);
        strcat(text, part3);
    }

    if (kind4 >= 0) {
        kind = (u16)fn_8005A310(gUiIconDrawer, (u8)kind4, 0);
        sprintf(part4, (char *)gBattleHelpStrings + 0x19B, kind - 1);
        strcat(text, part4);
    }

    fn_8000D864(0, text);

    Ui_OpenHelpPopup(
        Msg_Expand(gBattleHelpStrings + 0x1A2),
        gBattleHelpStrings + 0x1AC,
        parent,
        1
    );
}
#pragma global_optimizer reset
#pragma dont_inline reset
/* Open a help popup naming which stat on a bonus entry is non-zero. */
void StatBonus_ShowHelp(void *bonus, s32 parent) {
    s32 Msg_Expand(void *);
    void Ui_OpenHelpPopup(s32, void *, s32, s8);
    extern u8 gBattleHelpStrings[];
    void *msg;

    if ((s8)*(u8 *)((u8 *)bonus + 0x1F) != 0) {
        msg = gBattleHelpStrings + 0x1BD;
    } else if ((s8)*(u8 *)((u8 *)bonus + 0x20) != 0) {
        msg = gBattleHelpStrings + 0x1C4;
    } else if ((s8)*(u8 *)((u8 *)bonus + 0x21) != 0) {
        msg = gBattleHelpStrings + 0x1CC;
    } else if ((s8)*(u8 *)((u8 *)bonus + 0x22) != 0) {
        msg = gBattleHelpStrings + 0x1D5;
    } else if ((s8)*(u8 *)((u8 *)bonus + 0x23) != 0) {
        msg = gBattleHelpStrings + 0x1DE;
    } else if ((s8)*(u8 *)((u8 *)bonus + 0x24) != 0) {
        msg = gBattleHelpStrings + 0x1E8;
    } else if ((s8)*(u8 *)((u8 *)bonus + 0x25) != 0) {
        msg = gBattleHelpStrings + 0x1F1;
    } else if ((s8)*(u8 *)((u8 *)bonus + 0x26) != 0) {
        msg = gBattleHelpStrings + 0x1F9;
    } else if ((s8)*(u8 *)((u8 *)bonus + 0x28) != 0) {
        msg = gBattleHelpStrings + 0x202;
    } else if ((s8)*(u8 *)((u8 *)bonus + 0x27) != 0) {
        msg = gBattleHelpStrings + 0x20C;
    } else {
        msg = bonus;
    }
    Ui_OpenHelpPopup(Msg_Expand(msg), gBattleHelpStrings + 0x1AC, parent, 1);
}

#pragma scheduling on
void fn_800913D4(void **arg0, s32 arg1, s32 arg2) {
    void fn_8000D864(s32, char *);
    s32 fn_8000D910(char *, s32);
    s32 fn_8001D070(void **, s32);
    s32 UnitRef_GetName(void **);
    s32 Status_Test(s32, s32);
    void Ui_OpenHelpPopup(s32, s32, s32, s32);
    s32 fn_80231E74(char *, s32, char *, ...);
    extern u8 gBattleHelpStrings[];

    char sp8[0x80];
    s32 temp;
    u8 kind;
    void *p;

    p = *arg0;
    if (p != 0) {
        kind = *(u8 *)((char *)p + 0x15);
    } else {
        kind = 0;
    }
    fn_80231E74(sp8, 0x80, (char *)gBattleHelpStrings + 0x214, (temp = UnitRef_GetName(arg0), fn_8001D070(arg0, 0)), temp, kind + 0x60);
    fn_8000D864(0, sp8);
    Ui_OpenHelpPopup(fn_8000D910((char *)gBattleHelpStrings + 0x21F, Status_Test(arg2 + 0x1BC, 1)), 0, arg1, 0);
}
#pragma scheduling reset
void fn_8009149C(s32 arg0, s32 arg1) {
    extern u8 gBattleHelpStrings[];
    s32 fn_80231E74(char *, s32, char *, ...);
    void fn_8000D864(s32, char *);
    s32 Msg_Expand(void *);
    void Ui_OpenHelpPopup(s32, void *, s32, s32);
    char sp8[0x80];

    fn_80231E74(sp8, 0x80, (char *)gBattleHelpStrings + 0x228, arg0);
    fn_8000D864(0, sp8);
    Ui_OpenHelpPopup(Msg_Expand((char *)gBattleHelpStrings + 0x22B), gBattleHelpStrings + 0x1AC, arg1, 0);
}

#pragma use_lmw_stmw on
#pragma opt_common_subs off
void fn_80091518(void **arg0, s32 arg1, s32 arg2) {
    void fn_8000D864(s32, char *);
    s32 fn_8000D910(char *, s32, void *);
    s32 fn_8001D070(void **, s32);
    s32 UnitRef_GetName(void **);
    s32 Status_Test(s32, s32);
    void Ui_OpenHelpPopup(s32, void *, s32, s32);
    s32 fn_80231E74(char *, s32, char *, ...);
    extern u8 gBattleHelpStrings[];

    s32 temp;
    u8 kind;
    char sp8[0x80];

    if (*arg0 != 0) {
        kind = *(u8 *)((char *)*arg0 + 0x15);
    } else {
        kind = 0;
    }
    temp = UnitRef_GetName(arg0);
    fn_80231E74(sp8, 0x80, (char *)gBattleHelpStrings + 0x214, fn_8001D070(arg0, 0), temp, kind + 0x60);
    fn_8000D864(0, sp8);
    Ui_OpenHelpPopup(fn_8000D910((char *)gBattleHelpStrings + 0x25A, Status_Test(arg2 + 0x1BC, 1), gBattleHelpStrings), gBattleHelpStrings + 0x23E, arg1, 0);
}
#pragma opt_common_subs reset
#pragma use_lmw_stmw reset
void fn_800915E8(void **arg0, s32 arg1, s32 arg2) {
#pragma scheduling off
    void fn_8000D864(s32, char *);
    s32 fn_8000D910(char *, s32, void *);
    s32 fn_8001D070(void **, s32);
    s32 UnitRef_GetName(void **);
    s32 Status_Test(s32, s32);
    void Ui_OpenHelpPopup(s32, void *, s32, s32);
    s32 fn_80231E74(char *, s32, char *, ...);
    extern u8 gBattleHelpStrings[];
    char sp8[0x80];
    s32 temp;
    u8 kind;
    void *p;
#pragma scheduling reset
    p = *arg0;
    if (p != 0) {
        kind = *(u8 *)((char *)p + 0x15);
    } else {
        kind = 0;
    }
    temp = UnitRef_GetName(arg0);
    fn_80231E74(sp8, 0x80, (char *)gBattleHelpStrings + 0x214, fn_8001D070(arg0, 0), temp, kind + 0x60);
    fn_8000D864(0, sp8);
    Ui_OpenHelpPopup(fn_8000D910((char *)gBattleHelpStrings + 0x265, Status_Test(arg2 + 0x1BC, 1), gBattleHelpStrings), gBattleHelpStrings + 0x1AC, arg1, 0);
}
#pragma opt_allocation off
void fn_800916B8(void **arg0, s32 arg1, s32 arg2) {
    extern u8 gBattleHelpStrings[];
    s32 fn_80231E74(char *, s32, char *, ...);
    void fn_8000D864(s32, char *);
    s32 fn_8000D910(char *, s32, void *);
    s32 fn_8001D070(void **, s32);
    s32 UnitRef_GetName(void **);
    s32 Status_Test(s32, s32);
    void Ui_OpenHelpPopup(s32, void *, s32, s32);
    char sp8[0x80];
    void *entry;
    s32 result;
    u8 type;

    entry = *arg0;
    if (entry != 0) {
        type = *((u8 *)entry + 0x15);
    } else {
        type = 0;
    }
    result = UnitRef_GetName(arg0);
    fn_80231E74(sp8, 0x80, (char *)gBattleHelpStrings + 0x214, fn_8001D070(arg0, 0), result, type + 0x60);
    fn_8000D864(0, sp8);
    Ui_OpenHelpPopup(fn_8000D910((char *)gBattleHelpStrings + 0x270, Status_Test(arg2 + 0x1BC, 1), gBattleHelpStrings), gBattleHelpStrings + 0x23E, arg1, 0);
}
#pragma opt_allocation reset
void fn_80091788(void **arg0, s32 arg1, s32 arg2) {
    void fn_8000D864(s32, char *);
    s32 fn_8000D910(char *, s32, void *);
    s32 fn_8001D070(void **, s32);
    s32 UnitRef_GetName(void **);
    s32 Status_Test(s32, s32);
    void Ui_OpenHelpPopup(s32, void *, s32, s32);
    s32 fn_80231E74(char *, s32, char *, ...);
    extern u8 gBattleHelpStrings[];

    char sp8[0x80];
    s32 result;
    u8 type;
    s32 a2 = arg2;
    s32 a1 = arg1;
    void **unit = arg0;
    void *entry;

    entry = *unit;
    if (entry != 0) {
        type = *(u8 *)((char *)entry + 0x15);
    } else {
        type = 0;
    }
    result = UnitRef_GetName(unit);
    fn_80231E74(sp8, 0x80, (char *)gBattleHelpStrings + 0x214, fn_8001D070(unit, 0), result, type + 0x60);
    fn_8000D864(0, sp8);
    Ui_OpenHelpPopup(fn_8000D910((char *)gBattleHelpStrings + 0x27B, Status_Test(a2 + 0x1BC, 1), gBattleHelpStrings), gBattleHelpStrings + 0x1AC, a1, 0);
}
