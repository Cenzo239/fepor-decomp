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

/* Draw a menu text item, then overlay the cursor unit's weapon exp and rank letter. */

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset


#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern s32 lbl_8036773C;

extern s32 lbl_80367550;

extern s32 lbl_8036757C;

extern s32 lbl_803676D4;

extern s32 lbl_803676F8;

#pragma global_optimizer off

#pragma opt_lifetimes off

#pragma opt_lifetimes on
#pragma global_optimizer reset
extern u8 lbl_80366E25;

extern u8 lbl_80367708;
#pragma global_optimizer off

#pragma global_optimizer reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer off

s32 fn_800A0348(s32 a, s32 b, void *item) {
    extern u8 lbl_80367705;
    enum { MENU_TOGGLE_ON = 0, MENU_TOGGLE_OFF = 2 };

    lbl_80367705 ^= 1;
    *((u8 *)item + 0x39) = lbl_80367705 ? MENU_TOGGLE_ON : MENU_TOGGLE_OFF;
    return 0;
}
#pragma global_optimizer on
u32 fn_800A0370(void) {
    extern u8 lbl_80367705;
    u32 var_r3;

    var_r3 = 2;
    if (lbl_80367705 != 0) {
        var_r3 = 0;
    }
    return (u8)var_r3;
}

void *fn_800A038C(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x3f6;
}

s32 fn_800A039C(s32 a, s32 b, void *item) {
    extern u8 lbl_80367704;
    enum { MENU_TOGGLE_ON = 0, MENU_TOGGLE_OFF = 2 };

    lbl_80367704 ^= 1;
    *((u8 *)item + 0x39) = lbl_80367704 ? MENU_TOGGLE_ON : MENU_TOGGLE_OFF;
    return 0;
}

u32 fn_800A03C4(void) {
    extern u8 lbl_80367704;
    u32 var_r3;

    var_r3 = 2;
    if (lbl_80367704 != 0) {
        var_r3 = 0;
    }
    return (u8)var_r3;
}

void *fn_800A03E0(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x403;
}

s32 fn_800A03F0(s32 a, s32 b, void *item) {
    extern u8 lbl_80367703;
    enum { MENU_TOGGLE_ON = 0, MENU_TOGGLE_OFF = 2 };

    lbl_80367703 ^= 1;
    *((u8 *)item + 0x39) = lbl_80367703 ? MENU_TOGGLE_ON : MENU_TOGGLE_OFF;
    return 0;
}

u32 fn_800A0418(void) {
    extern u8 lbl_80367703;
    u32 var_r3;

    var_r3 = 2;
    if (lbl_80367703 != 0) {
        var_r3 = 0;
    }
    return (u8)var_r3;
}

void *fn_800A0434(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x415;
}

s32 fn_800A0444(s32 a, s32 b, void *item) {
    extern u8 lbl_80367702;
    enum { MENU_TOGGLE_ON = 0, MENU_TOGGLE_OFF = 2 };

    lbl_80367702 ^= 1;
    *((u8 *)item + 0x39) = lbl_80367702 ? MENU_TOGGLE_ON : MENU_TOGGLE_OFF;
    return 0;
}

u32 fn_800A046C(void) {
    extern u8 lbl_80367702;
    u32 var_r3;

    var_r3 = 2;
    if (lbl_80367702 != 0) {
        var_r3 = 0;
    }
    return (u8)var_r3;
}

void *fn_800A0488(void) {
    extern u8 gMenuCmdStrings[];
    return (char *)&gMenuCmdStrings + 0x424;
}

s32 fn_800A0498(s32 a, s32 b, void *item) {
    extern u8 lbl_80367706;
    enum { MENU_TOGGLE_ON = 0, MENU_TOGGLE_OFF = 2 };

    lbl_80367706 ^= 1;
    *((u8 *)item + 0x39) = lbl_80367706 ? MENU_TOGGLE_ON : MENU_TOGGLE_OFF;
    return 0;
}

u32 fn_800A04C0(void) {
    extern u8 lbl_80367706;
    u32 var_r3;

    var_r3 = 2;
    if (lbl_80367706 != 0) {
        var_r3 = 0;
    }
    return (u8)var_r3;
}

void *fn_800A04DC(void) {
    extern u16 gMenuCmdStrings[];
    return (char *)&gMenuCmdStrings + 0x42B;
}

s32 fn_800A04EC(s32 a, s32 b, void *item) {
    extern u8 lbl_80367701;
    enum { MENU_TOGGLE_ON = 0, MENU_TOGGLE_OFF = 2 };

    lbl_80367701 ^= 1;
    *((u8 *)item + 0x39) = lbl_80367701 ? MENU_TOGGLE_ON : MENU_TOGGLE_OFF;
    return 0;
}

u32 fn_800A0514(void) {
    extern u8 lbl_80367701;
    u32 var_r3;

    var_r3 = 2;
    if (lbl_80367701 != 0) {
        var_r3 = 0;
    }
    return (u8)var_r3;
}

void *fn_800A0530(void) {
    extern u16 gMenuCmdStrings[];
    return (char *)&gMenuCmdStrings + 0x437;
}

s32 fn_800A0540(s32 a, s32 b, void *item) {
    extern u8 lbl_80367700;
    enum { MENU_TOGGLE_ON = 0, MENU_TOGGLE_OFF = 2 };

    lbl_80367700 ^= 1;
    *((u8 *)item + 0x39) = lbl_80367700 ? MENU_TOGGLE_ON : MENU_TOGGLE_OFF;
    return 0;
}

u32 fn_800A0568(void) {
    extern u8 lbl_80367700;
    u32 var_r3;

    var_r3 = 2;
    if (lbl_80367700 != 0) {
        var_r3 = 0;
    }
    return (u8)var_r3;
}

void *fn_800A0584(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x444;
}

s32 fn_800A0594(void) {
    M2C_UNK fn_800C418C();
    fn_800C418C();
    return 5;
}

void *fn_800A05B8(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x454;
}

s32 fn_800A05C8(void) {
    M2C_UNK fn_8005BCAC();
    fn_8005BCAC();
    return 5;
}

void *fn_800A05EC(void) {
    extern u16 gMenuCmdStrings[];
    return (char *)gMenuCmdStrings + 0x460;
}

s32 fn_800A05FC(void) {
    void fn_800056A0(s32);
    s32 DebugPrint(const char *, ...);
    extern u16 gMenuCmdStrings[];

    fn_800056A0(0);
    DebugPrint((const char *)((u8 *)gMenuCmdStrings + 0x46F));
    return 5;
}

void *fn_800A0638(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x48c;
}

s32 fn_800A0648(void) {
    void fn_800056A0(s32);
    s32 DebugPrint(const char *, ...);
    void fn_8000D048(void);
    extern u16 gMenuCmdStrings[];

    fn_800056A0(0);
    DebugPrint((const char *)((u8 *)gMenuCmdStrings + 0x496));
    fn_8000D048();
    DebugPrint((const char *)((u8 *)gMenuCmdStrings + 0x4AD));
    return 5;
}

void *fn_800A069C(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x4b0;
}

s32 fn_800A06AC(void) {
    M2C_UNK fn_800056A0(M2C_UNK);
    M2C_UNK fn_801EC7B4();
    fn_800056A0(0);
    fn_801EC7B4();
    return 5;
}

void *fn_800A06D8(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x4bb;
}

s32 fn_800A06E8(void) {
    void fn_800056A0(s32);
    s32 DebugPrint(const char *, ...);
    void fn_8005BCD0(void);
    extern u16 gMenuCmdStrings[];

    fn_800056A0(0);
    DebugPrint((const char *)((u8 *)gMenuCmdStrings + 0x4C6));
    fn_8005BCD0();
    DebugPrint((const char *)((u8 *)gMenuCmdStrings + 0x4AD));
    return 5;
}

void *fn_800A073C(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x4dc;
}

s32 fn_800A074C(void) {
    M2C_UNK fn_800C4384();
    fn_800056A0(0);
    fn_800C4384();
    return 5;
}

void *fn_800A0778(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x4E9;
}

s32 fn_800A0788(void) {
    M2C_UNK fn_801B84C0();
    fn_800056A0(0);
    fn_801B84C0();
    return 6;
}

void *fn_800A07B4(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x4EE;
}

s32 fn_800A07C4(void) {
    extern u16 gBattleState[1400];
    fn_8014DD10((u8 *)gBattleState + 0x3c4);
    return 6;
}

void *fn_800A07F4(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x4F2;
}

s32 fn_800A0804(void) {
    M2C_UNK fn_80016538();
    fn_80016538();
    return 0;
}

void *MenuCmd_GetCursorMapObjLabel(void) {
    /* Label for the map object under the battle cursor: hidden, visible, or neither. */
    s32 Map_Get(void *);
    s32 Map_FindObjAt(s32, s32, s32, s32, s32);
    u8 MapObj_IsVisible(s32);
    u8 MapObj_IsHidden(void);
    extern u8 gBattleState[];
    extern u16 gMenuCmdStrings[];
    f32 cy;
    f32 cx;
    s32 obj;
    s32 map;

    cy = *(f32 *)(gBattleState + 0x538);
    cx = *(f32 *)(gBattleState + 0x534);
    map = Map_Get(gBattleState);
    obj = Map_FindObjAt(map, (s32)cx, (s32)cy, 0x800, 0x10);
    if (obj != 0) {
        if (MapObj_IsHidden() != 0) {
            return (u8 *)gMenuCmdStrings + 0x4FC;
        }
    }
    if ((u32)obj != 0) {
        if (MapObj_IsVisible(obj) != 0) {
            return (u8 *)gMenuCmdStrings + 0x509;
        }
    }
    return (u8 *)gMenuCmdStrings + 0x516;
}

s32 fn_800A08FC(void) {
    s32 Map_Get(void *);
    s32 Map_FindObjAt(s32, s32, s32, s32, s32);
    u8 MapObj_IsVisible(s32);
    u8 MapObj_IsHidden(void);
    extern u8 gBattleState[];
    f32 f31;
    f32 f30;
    s32 r31;
    s32 tmp;

    f31 = *(f32 *)(gBattleState + 0x538);
    f30 = *(f32 *)(gBattleState + 0x534);
    tmp = Map_Get(gBattleState);
    r31 = Map_FindObjAt(tmp, (s32)f30, (s32)f31, 0x800, 0x10);
    if (r31 != 0) {
        if (MapObj_IsHidden() != 0) {
            return 0;
        }
    }
    if ((u32)r31 != 0) {
        if (MapObj_IsVisible(r31) != 0) {
            return 0;
        }
    }
    return 2;
}

/* Toggle show/hide of the map object under the battle cursor, then refresh the map. */
s32 MenuCmd_ToggleCursorMapObj(s32 unused0, s32 unused1, void *item) {
    s32 Map_Get();
    s32 Map_FindObjAt(s32, s32, s32, s32, s32);
    void fn_800498A4(s32, s32, s32);
    u8 MapObj_IsVisible(s32);
    u8 MapObj_IsHidden(void);
    void fn_80044450(s32, s32);
    extern u8 gBattleState[];
    f32 cy;
    f32 cx;
    s32 obj;
    s32 map;

    (void)unused0;
    (void)unused1;
    if (*(u8 *)((u8 *)item + 0x39) != 0) {
        return 0;
    }
    cy = *(f32 *)(gBattleState + 0x538);
    cx = *(f32 *)(gBattleState + 0x534);
    map = Map_Get(gBattleState);
    obj = Map_FindObjAt(map, (s32)cx, (s32)cy, 0x800, 0x10);
    if (obj != 0) {
        if (MapObj_IsHidden() != 0) {
            fn_800498A4(obj, 0, 1);
            goto after;
        }
    }
    if ((u32)obj != 0) {
        if (MapObj_IsVisible(obj) != 0) {
            fn_800498A4(obj, 0, 0);
        }
    }
 after:
    fn_80044450(Map_Get(), 1);
    return 0;
}

void *fn_800A0AA8(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x527;
}

s32 fn_800A0AB8(void) {
    extern u8 gMenuCmdStrings[];
    BMapMain_Goto(1);
    GfxEnt_UnlinkByName(gMenuCmdStrings + 0x531);
    return 6;
}

void *fn_800A0AF0(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x53C;
}

s32 fn_800A0B00(void) {
    void fn_800056A0(s32);
    void fn_8010FBD8(void *);
    extern u8 gMapObjEventList[];
    fn_800056A0(0);
    fn_8010FBD8(gMapObjEventList);
    return 6;
}

void *fn_800A0B34(void) {
    extern u8 gMenuCmdStrings[];
    return (u16*)(gMenuCmdStrings + 0x54A);
}

extern s32 lbl_803676A4;
s32 fn_800A0B44(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_803676A4, arg1, 0);
    return 0;
}

char *fn_800A0B70(void) {
    s32 fn_800C3E54(void *);
    void sprintf(void *, void *, ...);
    extern u8 gConvoy[];
    extern char lbl_80312378[];
    extern u8 gMenuCmdStrings[];

    sprintf(lbl_80312378, gMenuCmdStrings + 0x558, fn_800C3E54(gConvoy));
    return lbl_80312378;
}

u8 fn_800A0BC0(void) {
    s32 fn_800C3E54(void *);
    extern u8 gConvoy[];
    s32 result;
    s32 ret;

    result = fn_800C3E54(gConvoy);
    ret = 2;
    if (result != 0) {
        ret = 0;
    }
    return (u8)ret;
}

s32 fn_800A0BFC(s32 arg0, s32 arg1, void *arg2) {
    void fn_800056A0(s32);
    s32 fn_800C3468(void *);
    extern u8 gConvoy[];

    if (*(u8 *)((char *)arg2 + 0x39) != 0) {
        return 0;
    }
    fn_800C3468(gConvoy);
    fn_800056A0(0);
    return 0;
}

/* Format the name of the map object under the battle cursor; disable item if none. */
void *MenuCmd_FormatCursorMapObjName(void *unused, void *item) {
    s32 Map_Get(void *);
    void *Map_FindObjAtXY(s32, s32, s32);
    void sprintf(void *, void *, ...);
    extern u8 gBattleState[];
    extern u8 gMenuCmdStrings[];
    extern u8 sMenuMapObjNameBuf[];
    s32 cursorY;
    s32 cursorX;
    s32 map;
    void *obj;

    cursorY = (s32)*(f32 *)(gBattleState + 0x528);
    cursorX = (s32)*(f32 *)(gBattleState + 0x524);
    map = Map_Get(gBattleState);
    obj = Map_FindObjAtXY(map, (s8)cursorX, (s8)cursorY);
    *(u8 *)((u8 *)item + 0x39) = 2;
    if (obj == NULL) {
        return gMenuCmdStrings + 0x563;
    }
    sprintf(sMenuMapObjNameBuf, gMenuCmdStrings + 0x575, **(s32 **)((u8 *)obj + 0x10));
    *(u8 *)((u8 *)item + 0x39) = 0;
    return sMenuMapObjNameBuf;
}

extern s32 lbl_80367670;
extern void *Ui_CreateMenu(void *, s32, s32);
s32 fn_800A0D08(s32 arg0, s32 arg1, void *arg2) {
    if (*(u8 *)((char *)arg2 + 0x39) != 0) {
        return 0;
    }
    Ui_CreateMenu(&lbl_80367670, arg1, 0);
    return 0;
}

char *fn_800A0D48(void)
{
    extern u8 gMenuCmdStrings[];
    extern char lbl_80312338[];

    extern void *Map_GetCursorUnit(void);
    extern s32 Msg_ResolveName(void *);
    extern s32 sprintf(char *, const char *, ...);

    u8 *unit;
    s32 value;

    unit = (u8 *)Map_GetCursorUnit();

    if (unit == 0) {
        return (char *)gMenuCmdStrings + 0x582;
    }

    value = Msg_ResolveName(*(void **)(unit + 0x188));

    sprintf(
        lbl_80312338,
        (const char *)gMenuCmdStrings + 0x590,
        value
    );

    return lbl_80312338;
}

u8 fn_800A0DB0(void) {
    u32 Map_GetCursorUnit(void);
    u32 result;
    u32 r0;
    result = Map_GetCursorUnit();
    r0 = 2;
    if (result != 0) {
        r0 = 0;
    }
    return (u8)r0;
}

extern s32 lbl_80367660;
s32 fn_800A0DE4(s32 arg0, s32 arg1, void *arg2) {
    if (*(u8 *)((char *)arg2 + 0x39) != 0) {
        return 0;
    }
    Ui_CreateMenu(&lbl_80367660, arg1, 0);
    return 0;
}

char *fn_800A0E24(void) {
    s32 SystemSave_CountPackedSlots(void *);
    void sprintf(void *, void *, ...);
    extern u8 gSystemSave[];
    extern char gItemMenuTextBuf[];
    extern u8 gMenuCmdStrings[];

    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x599, (u8)SystemSave_CountPackedSlots(gSystemSave));
    return gItemMenuTextBuf;
}

#pragma push
#pragma opt_loop_invariants off
s32 fn_800A0E74(void) {
#pragma optimization_level 3
    u8 SystemSave_CountPackedSlots(void *);
    extern void *gPadInput;
    extern u8 gSystemSave[];
    s32 dir;
    s32 i;
    s32 limit;
    s32 zero = 0;
    int new_var;
    s32 ctr;
    u8 count;

    dir = 0;
    if (*(u32 *)((u8 *)gPadInput + 0xC) & 0x01000001U) {
        dir = -1;
        if ((u8)SystemSave_CountPackedSlots(gSystemSave) == 1) {
            return 0;
        }
    }
    if (*(u32 *)((u8 *)gPadInput + 0xC) & 0x02000002U) {
        dir = 1;
        if ((u8)SystemSave_CountPackedSlots(gSystemSave) == 0x1F) {
            return 0;
        }
    }
    if (dir == 0) {
        return 0;
    }
    count = (u8)SystemSave_CountPackedSlots(gSystemSave);
    limit = count + dir;
    for (i = 0; i < 30; i++) {
        new_var = limit - 1;
        if (i < new_var) {
            gSystemSave[i + 0x12] = i + 1;
        } else {
            gSystemSave[i + 0x12] = zero;
        }
    }
    return 0;
}
#pragma pop
char *fn_800A101C(void) {
    void sprintf(void *, void *, ...);
    extern u8 gBattleState[];
    extern char gItemMenuTextBuf[];
    extern u8 gMenuCmdStrings[];
    char *buf;
    u8 *base;
    u8 flag;
    void *arg2;
    void *var_r5;

    buf = gItemMenuTextBuf;
    base = gMenuCmdStrings;
    flag = gBattleState[0x9F];
    arg2 = base + 0x5AE;
    var_r5 = base + 0x5C3;
    if ((flag >> 7) & 1) {
        var_r5 = base + 0x5BA;
    }
    sprintf(buf, arg2, var_r5);
    return gItemMenuTextBuf;
}
#pragma optimization_level reset
s32 fn_800A1078(void) {
    extern void *gPadInput;
    extern u8 gBattleState[];
    s32 temp_r5;
    struct {
        u8 flag : 1;
        u8 rest : 7;
    } *b;

    temp_r5 = *(s32 *)((u8 *)gPadInput + 4);
    if (temp_r5 & (*(s32 *)((u8 *)gPadInput + 8) ^ temp_r5) & 0x03000003) {
        b = (void *)&gBattleState[0x9F];
        b->flag ^= 1;
    }
    return 0;
}

char *fn_800A10C0(void) {
    void sprintf(void *, void *, ...);
    extern u8 gBattleState[];
    extern char gItemMenuTextBuf[];
    extern u8 gMenuCmdStrings[];
    void *var_r5;

    switch (gBattleState[0xA6]) {
    case 0:
        var_r5 = gMenuCmdStrings + 0x5CA;
        break;
    case 1:
        var_r5 = gMenuCmdStrings + 0x5D1;
        break;
    case 2:
        var_r5 = gMenuCmdStrings + 0x5D6;
        break;
    case 3:
        var_r5 = gMenuCmdStrings + 0x5DD;
        break;
    default:
        var_r5 = NULL;
        break;
    }
    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x5E2, var_r5);
    return gItemMenuTextBuf;
}

s32 fn_800A1178(void)
{
  extern u8 *gPadInput;
  extern u16 gBattleState[];
  u8 *obj;
  u8 *table;
  u32 previous;
  u32 current;
  u32 changed;
  u8 count;
  obj = gPadInput;
  table = (u8 *) gBattleState;
  previous = *((u32 *) (obj + 4));
  current = *((u32 *) (obj + 8));
  count = table[0xA6];
  changed = previous & (current ^ previous);
  if (changed & 0x01000001)
  {
    count = (u8) (count - 1);
  }
  if (changed & 0x02000002)
  {
    changed = 1;
    count = (u8) (count + changed);
  }
  table[0xA6] = ((s32) count) % 4;
  return 0;
}

char *fn_800A11F0(void) {
    void sprintf(void *, void *, ...);
    extern u8 gBattleState[];
    extern char gItemMenuTextBuf[];
    extern u8 gMenuCmdStrings[];

    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x5EC, gBattleState[0x10], gBattleState + 0x504);
    return gItemMenuTextBuf;
}

char *fn_800A1240(void) {
    s32 Battle_GetTotalAssets(void *);
    void sprintf(void *, void *, ...);
    extern u8 gBattleState[];
    extern char gItemMenuTextBuf[];
    extern u8 gMenuCmdStrings[];

    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x5FA, Battle_GetTotalAssets(gBattleState));
    return gItemMenuTextBuf;
}

char *fn_800A1290(void) {
    void sprintf(void *, void *, ...);
    extern u8 gBattleState[];
    extern char gItemMenuTextBuf[];
    extern u8 gMenuCmdStrings[];

    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x606, *(s32 *)(gBattleState + 0x18));
    return gItemMenuTextBuf;
}

s32 fn_800A12DC(void)
{
    extern u8 *gPadInput;
    extern u16 gBattleState[];

    extern void fn_8014D268(void *, s32);

    u8 *obj;
    u8 *table;
    u32 flags;
    s32 value;

    obj = gPadInput;
    flags = *(u32 *)(obj + 0x10);

    if (flags & 0x01000001) {
        table = (u8 *)gBattleState;
        value = *(s32 *)(table + 0x18);

        fn_8014D268(table, value - 0x64);
    }

    obj = gPadInput;
    flags = *(u32 *)(obj + 0x10);

    if (flags & 0x02000002) {
        table = (u8 *)gBattleState;
        value = *(s32 *)(table + 0x18);

        fn_8014D268(table, value + 0x64);
    }

    return 0;
}

char *fn_800A1354(void) {
    void sprintf(void *, void *, ...);
    extern u8 gBattleState[];
    extern char gItemMenuTextBuf[];
    extern u8 gMenuCmdStrings[];

    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x612, *(s32 *)(gBattleState + 0x1C));
    return gItemMenuTextBuf;
}

s32 fn_800A13A0(void) {
    extern void *gPadInput;
    extern u8 gBattleState[];
    void *obj = gPadInput;

    if (*(s32 *)((u8 *)obj + 0x10) & 0x01000001) {
        *(s32 *)(gBattleState + 0x1C) -= 0x64;
    }
    if (*(s32 *)((u8 *)obj + 0x10) & 0x02000002) {
        *(s32 *)(gBattleState + 0x1C) += 0x64;
    }
    return 0;
}

char *fn_800A13FC(void) {
    void sprintf(void *, void *, ...);
    extern u8 gBattleState[];
    extern char gItemMenuTextBuf[];
    extern u8 gMenuCmdStrings[];

    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x61E, *(s16 *)(gBattleState + 0x12));
    return gItemMenuTextBuf;
}

s32 fn_800A1448(void) {
    extern void *gPadInput;
    extern u8 gBattleState[];
    void *obj = gPadInput;

    if (*(s32 *)((u8 *)obj + 0x10) & 0x01000001) {
        *(s16 *)(gBattleState + 0x12) -= 1;
    }
    if (*(s32 *)((u8 *)obj + 0x10) & 0x02000002) {
        *(s16 *)(gBattleState + 0x12) += 1;
    }
    return 0;
}

#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" void fn_800A14A4(void *unused, void *parent, void *item) {
#pragma cplusplus on
#pragma use_lmw_stmw on
    struct Model {
        u8 pad[4];
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
        virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
        virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0;
        virtual void v15() = 0; virtual void v16() = 0; virtual void v17() = 0;
        virtual void v18() = 0; virtual void v19() = 0; virtual void v20() = 0;
        virtual void v21() = 0; virtual void v22() = 0; virtual void v23() = 0;
        virtual void v24() = 0; virtual f32 v25() = 0;
    };
    void sprintf(u8 *, void *, ...);
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetText(void *);
    void Prim2D_SetScale(f32);
    void Prim2D_EndPrim(void);
    extern u8 gBattleState[];
    extern u8 gMenuCmdStrings[];
    extern u8 gItemMenuTextBuf[];
    extern u8 lbl_8026D7C8[];
    extern f32 lbl_803699F8;
    extern f32 lbl_803699FC;
    extern f32 gItemMenuTextScale;
    struct {
        u32 vals[5];
        u8 last;
        u32 names[3];
    } buf;
    s32 index;
    u8 *tbl;
    s32 off;
    u8 *p0;
    u8 *p1;
    u8 *p2;

    (void)unused;
    tbl = lbl_8026D7C8;
    index = *((u8 *)item + 0x3A);
    buf.names[0] = *(u32 *)(tbl + 0xF8);
    buf.names[1] = *(u32 *)(tbl + 0xFC);
    buf.names[2] = *(u32 *)(tbl + 0x100);
    buf.vals[0] = *(u32 *)(tbl + 0x10);
    buf.vals[1] = *(u32 *)(tbl + 0x14);
    buf.vals[2] = *(u32 *)(tbl + 0x18);
    buf.vals[3] = *(u32 *)(tbl + 0x104);
    buf.vals[4] = *(u32 *)(tbl + 0x108);
    buf.last = tbl[0x10C];
    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x629, buf.names[index], buf.vals[*(u8 *)(gBattleState + index + 0x15)]);
    Prim2D_Begin();
    Prim2D_SetTransform((f32)*(s16 *)((u8 *)parent + 0x30), (f32)*(s16 *)((u8 *)parent + 0x32),
        (*(Model **)((u8 *)parent + 0x3C))->v25() - lbl_803699F8, lbl_803699FC);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)*(s16 *)((u8 *)item + 0x30), (f32)*(s16 *)((u8 *)item + 0x32));
    off = index * 3;
    p0 = (u8 *)buf.vals + 12;
    p1 = (u8 *)buf.vals + 13;
    p2 = (u8 *)buf.vals + 14;
    Prim2D_SetColor(p0[off], p1[off], p2[off], 0xFF);
    Prim2D_SetText(gItemMenuTextBuf);
    Prim2D_SetScale(gItemMenuTextScale);
    Prim2D_EndPrim();
#pragma cplusplus reset
}
#pragma cplusplus reset
#pragma use_lmw_stmw reset
s32 fn_800A1658(s32 arg0,s32 arg1,void *arg2) {
extern u8 *lbl_80367240; extern u8 lbl_80330708[]; void fn_8014D244(u8 *,u8,u8);
u32 previous,current,changed; s32 idx; u8 val; u8 initial;
previous=*(u32*)(lbl_80367240+4); current=*(u32*)(lbl_80367240+8);
idx=*((u8*)arg2+0x3A)+1; initial=lbl_80330708[idx+0x14];
changed=previous & (current ^ previous); val=initial;
if(changed&0x01000001) val=(u8)(initial+2);
if(changed&0x02000002) val=(u8)((u8)val+1);
val=(u8)((s32)val%3); fn_8014D244(lbl_80330708,(u8)idx,val); return 0;
}

s32 fn_800A1710(void) {
    return 0;
}

void *fn_800A1718(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x62F;
}

s32 fn_800A1728(void) {
    extern f32 gBattleState[];
    s32 Map_Get(void *);
    s32 Map_FindObjAtXY(s32, s32, s32);
    s32 fn_80049D84(s32);
    s32 temp_r31;
    s32 temp_r30;
    u8 temp_r4;

    temp_r31 = (s32) gBattleState[0x14A];
    temp_r30 = (s32) gBattleState[0x149];
    temp_r4 = (u8) fn_80049D84(Map_FindObjAtXY(Map_Get(gBattleState), (s8) temp_r30, (s8) temp_r31));
    return (temp_r4 != 0) ? 0 : 2;
}

s32 fn_800A17A8(void) {
    s32 Map_Get(void *);
    s32 Map_FindObjAtXY(s32, s32, s32);
    s32 fn_80049D08(void);
    extern f32 gBattleState[];
    s8 temp_r31;
    s8 temp_r30;

    temp_r31 = (s8)gBattleState[0x14A];
    temp_r30 = (s8)gBattleState[0x149];
    Map_FindObjAtXY(Map_Get(gBattleState), temp_r30, temp_r31);
    fn_80049D08();
    return 0;
}

void *fn_800A1814(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x640;
}

#pragma dont_inline on
s32 fn_800A1824(void) {
    extern f32 gBattleState[];
    s32 Map_Get(void *);
    s32 Map_FindObjAtXY(s32, s32, s32);
    s32 fn_80049D84(s32);
    s32 temp_r31;
    s32 temp_r30;
    u8 temp_r4;

    temp_r31 = (s32) gBattleState[0x14A];
    temp_r30 = (s32) gBattleState[0x149];
    temp_r4 = (u8) fn_80049D84(Map_FindObjAtXY(Map_Get(gBattleState), (s8) temp_r30, (s8) temp_r31));
    return (temp_r4 != 0) ? 0 : 2;
}

s32 fn_800A18A4(void) {
    s32 Map_Get(void *);
    s32 Map_FindObjAtXY(s32, s32, s32);
    s32 fn_80049D30(void);
    extern f32 gBattleState[];
    s8 temp_r31;
    s8 temp_r30;

    temp_r31 = (s8)gBattleState[0x14A];
    temp_r30 = (s8)gBattleState[0x149];
    Map_FindObjAtXY(Map_Get(gBattleState), temp_r30, temp_r31);
    fn_80049D30();
    return 0;
}

void *fn_800A1910(void) {
    extern u16 gMenuCmdStrings[];
    return (u16*)((char*)gMenuCmdStrings + 0x651);
}

s32 fn_800A1920(s32 unused, s32 arg1) {
    void *Map_GetCursorUnit(void);
    u8 Status_Test(void *, s32);
    void Unit_ResetHeldFromClass(void *);
    void *fn_800241C8(s32);
    void Ui_OpenHelpPopup(void *, s32, s32, s32);
    extern u8 gMenuCmdStrings[];
    void *temp_r31;
    void *temp_r3;

    temp_r31 = Map_GetCursorUnit();
    if (temp_r31 == NULL) {
        return 0x10;
    }
    if (Status_Test((u8 *)temp_r31 + 0x1BC, 8) == 0) {
        return 0x10;
    }
    Unit_ResetHeldFromClass(temp_r31);
    temp_r3 = fn_800241C8(arg1);
    Ui_OpenHelpPopup(gMenuCmdStrings + 0x660, 0, *(s32 *)((u8 *)temp_r3 + 0x18), 0);
    return 6;
}

void *fn_800A19B0(void) {
    extern u16 gMenuCmdStrings[];
    return (u16*)((char*)gMenuCmdStrings + 0x667);
}

/* Kill the unit under the cursor: zero HP, then death cleanup or death anim. */
s32 Ui_KillCursorUnit(void) {
    void *Process_FindByName(void *);
    void Process_Goto(void *, s32);
    void fn_800A6A3C(void);
    void *Map_GetCursorUnit(void);
    void UiCtx_BeginMoveSelect(void *, void *);
    void UiCtx_EndMoveSelect(void *, s32);
    void Unit_SetHp(void *, s32);
    void Unit_OnZeroHp(void *);
    void Map_RefreshUnitMap(void *);
    void Battle_SetupUnit(void *, void *, s32);
    void Battle_QueueDeathAnim(void *);
    void fn_8019B704(void *, s32);
    extern u8 gMenuCmdStrings[];
    extern u8 gUiContext[];
    extern u8 gBattleMap[];
    extern u8 gBattle[];
    void *proc;
    void *unit;
    u8 *person;

    proc = Process_FindByName(gMenuCmdStrings + 0x531);
    if (proc == NULL) {
        return 0x10;
    }
    Process_Goto(proc, 9);
    fn_800A6A3C();
    unit = Map_GetCursorUnit();
    UiCtx_BeginMoveSelect(gUiContext, unit);
    UiCtx_EndMoveSelect(gUiContext, 1);
    Unit_SetHp(unit, 0);
    person = *(u8 **)((u8 *)unit + 0x190);
    if (person[8] != 0) {
        Unit_OnZeroHp(unit);
        Map_RefreshUnitMap(gBattleMap);
        return 6;
    }
    Unit_OnZeroHp(unit);
    Battle_SetupUnit(gBattle, unit, -1);
    Battle_QueueDeathAnim(gBattle);
    fn_8019B704(proc, 0);
    return 6;
}

void *fn_800A1AB0(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x66f;
}

void *fn_800A1AC0(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x673;
}

extern s32 lbl_80367628;
s32 fn_800A1AD0(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_80367628, arg1, 0);
    return 0;
}

void *fn_800A1AFC(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x679;
}

extern s32 lbl_80367618;
s32 fn_800A1B0C(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_80367618, arg1, 0);
    return 0;
}

void *fn_800A1B38(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x684;
}

extern s32 lbl_8036760C;
s32 fn_800A1B48(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_8036760C, arg1, 0);
    return 0;
}

void *fn_800A1B74(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x688;
}

extern s32 lbl_803675FC;
s32 fn_800A1B84(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_803675FC, arg1, 0);
    return 0;
}

void *fn_800A1BB0(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x68C;
}

extern s32 lbl_803675EC;
s32 fn_800A1BC0(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_803675EC, arg1, 0);
    return 0;
}

void *fn_800A1BEC(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x693;
}

extern s32 lbl_803675D8;
s32 fn_800A1BFC(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_803675D8, arg1, 0);
    return 0;
}

void *fn_800A1C28(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x6A0;
}

extern s32 lbl_803675D0;
s32 fn_800A1C38(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_803675D0, arg1, 0);
    return 0;
}

void *fn_800A1C64(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x6AB;
}

s32 fn_800A1C74(s32 arg0, s32 arg1, void *arg2) {
    extern u64 lbl_80367588;
    if (*(u8 *)((char *)arg2 + 0x39) != 0) {
        return 0x10;
    }
    Ui_CreateMenu(&lbl_80367588, arg1, 0);
    return 0;
}

#pragma opt_strength_reduction off
s32 fn_800A1CB4(void) { void *Map_GetCursorUnit(void); void *p = Map_GetCursorUnit(); p = *(void **)((u8 *)p + 0x188); return *(s32 *)((u8 *)p + 0x50) == 0 ? 2 : 0; }
#pragma opt_strength_reduction on
void *fn_800A1CF0(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x6b8;
}

s32 fn_800A1D00(void) {
    M2C_UNK Unit_SetStatBonusesToCap();
    M2C_UNK Map_GetCursorUnit();
    Map_GetCursorUnit();
    Unit_SetStatBonusesToCap();
    return 6;
}

/* Draw the selected item's name and current/max uses for a unit item-menu row. */
void ItemMenu_DrawItemText(s32 ctrl, s32 parent, void *item) {
    void *Map_GetCursorUnit(void);
    s32 Unit_GetItemSlot(s32, s32);
    s32 UnitRef_GetName(void);
    void sprintf(void *, void *, ...);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetText(void *);
    void Prim2D_SetScale(f32);
    void Prim2D_EndPrim(void);
    extern u8 gMenuCmdStrings[];
    extern u8 gItemMenuTextBuf[];
    extern f32 gItemMenuTextZ;
    extern f32 gItemMenuTextScale;
    void *row;
    void **slot;

    row = item;
    slot = (void **)Unit_GetItemSlot((s32)Map_GetCursorUnit(), *(u8 *)((u8 *)row + 0x3A));
    if (slot == NULL || *slot == NULL) {
        return;
    }
    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x6C7, UnitRef_GetName());
    Prim2D_Begin();
    Prim2D_AddZ(gItemMenuTextZ);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)*(s16 *)((u8 *)row + 0x30), (f32)*(s16 *)((u8 *)row + 0x32));
    Prim2D_SetText(gItemMenuTextBuf);
    Prim2D_SetScale(gItemMenuTextScale);
    Prim2D_EndPrim();
    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x6CA, *(u8 *)((u8 *)slot + 4),
        (u8)((*slot != NULL) ? *(u8 *)((u8 *)*slot + 0x18) : 0));
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)(*(s16 *)((u8 *)row + 0x30) + 0x78), (f32)*(s16 *)((u8 *)row + 0x32));
    Prim2D_SetText(gItemMenuTextBuf);
    Prim2D_SetScale(gItemMenuTextScale);
    Prim2D_EndPrim();
}

s32 fn_800A1EB4(s32 unused, s32 unused2, void *row) {
    void *Map_GetCursorUnit(void);
    void *Unit_GetItemSlot(void *, s32);
    void Item_SetUses(void *, u8);
    void *Item_Get(s32);
    void Item_Clear(void *);
    void UnitRef_Set(void *, void *);
    extern u8 *gPadInput;
    extern s32 lbl_803671E0;
    u32 held;
    void *slot;
    void *item;
    s32 max;
    s32 uses;
    s16 iid;
    s16 next;

    held = *(u32 *)(gPadInput + 0x10);
    if (!(held & 0x03000003)) {
        return 0;
    }
    slot = Unit_GetItemSlot(Map_GetCursorUnit(), *(u8 *)((u8 *)row + 0x3A));
    if (slot == NULL || (item = *(void **)slot, item == NULL)) {
        return 0;
    }
    if (*(u32 *)(gPadInput + 4) & 0x400) {
        max = (u8)((item != NULL) ? *(u8 *)((u8 *)item + 0x18) : 0);
        uses = *(u8 *)((u8 *)slot + 4);
        if (held & 0x01000001) {
            uses -= 1;
        }
        if (held & 0x02000002) {
            uses += 1;
        }
        if (uses > max) {
            uses = max;
        }
        if (uses < 1) {
            uses = 1;
        }
        Item_SetUses(slot, uses);
        return 0;
    }
    iid = (s16)*(u16 *)((u8 *)item + 0xE);
    if (held & 0x01000001) {
        for (;;) {
            if ((s16)iid == 1) {
                break;
            }
            iid -= 1;
            if (*(u8 *)((u8 *)Item_Get(iid) + 0x12) != 9) {
                break;
            }
        }
    }
    if (held & 0x02000002) {
        do {
            next = 1;
            if ((s16)iid < lbl_803671E0 - 1) {
                next = (s16)(iid + 1);
            }
            iid = next;
        } while (*(u8 *)((u8 *)Item_Get(next) + 0x12) == 9);
    }
    Item_Clear(slot);
    if ((s16)iid > lbl_803671E0) {
        iid = (s16)lbl_803671E0;
    }
    if ((s16)iid < 1) {
        iid = 1;
    }
    UnitRef_Set(slot, Item_Get(iid));
    return 0;
}

extern u16 lbl_8026D878[];
void *fn_800A207C(s32 unused, void *arg1) {
    typedef struct { void *e[18]; } Tbl;
    extern u16 lbl_8026D878[];
    Tbl t;

    t = *(Tbl *)lbl_8026D878;
    return t.e[*(u8 *)((u8 *)arg1 + 0x3a)];
}

s32 fn_800A20C4(s32 unused, s32 unused2, u8 *row) {
void *Map_GetCursorUnit(void);
u8 fn_8003D13C(void);
u8 fn_800386B0(void *);
s8 fn_8003C114(void *);
s8 fn_800386E0(void *);
s8 fn_8003A1E0(void *);
void fn_8003712C(void *);
extern u8 *gPadInput;
u8 *unit;
s32 value;
u32 flags;
unit=Map_GetCursorUnit(); value=0;
if(row[0x3a]==1 && !fn_8003D13C())return 0;
switch(row[0x3a]) {
case 0: value=*(s8 *)(unit+410); break;
case 1: value=fn_800386B0(unit); break;
case 2: value=*(s8 *)(unit+427); break;
case 3: value=*(s8 *)(unit+424); break;
case 4: value=*(s8 *)(unit+428); break;
case 5: value=*(s8 *)(unit+429); break;
case 6: value=*(s8 *)(unit+430); break;
case 7: value=*(s8 *)(unit+431); break;
case 8: value=*(s8 *)(unit+432); break;
case 9: value=*(s8 *)(unit+433); break;
case 10: value=*(s8 *)(unit+434); break;
case 11: value=*(s8 *)(unit+425); break;
case 12: value=*(s8 *)(unit+426); break;
case 13:value=fn_8003C114(unit);break;
case 14:value=fn_800386E0(unit);break;
case 15:value=*(u16 *)(unit+0x228);break;
case 17:value=fn_8003A1E0(unit);break;
}
flags=*(u32 *)(gPadInput+0x10);
if(flags&0x01000001)value--;
if(flags&0x02000002)value++;
switch(row[0x3a]) {
case 0: if(value>20)value=20; if(value<1)value=1; unit[410]=value;break;
case 1: if(value>99)value=99; if(value<0)value=0; unit[411]=value;break;
case 2:  if(value<1)value=1; unit[427]=value;break;
case 3:  if(value<1)value=1; unit[424]=value;break;
case 4:  if(value<0)value=0; unit[428]=value;break;
case 5:  if(value<0)value=0; unit[429]=value;break;
case 6:  if(value<0)value=0; unit[430]=value;break;
case 7:  if(value<0)value=0; unit[431]=value;break;
case 8:  if(value<0)value=0; unit[432]=value;break;
case 9:  if(value<0)value=0; unit[433]=value;break;
case 10:  if(value<0)value=0; unit[434]=value;break;
case 11:  if(value<0)value=0; unit[425]=value;break;
case 12:  if(value<0)value=0; unit[426]=value;break;
case 13:if(value<0)value=0;if(value>20)value=20;unit[0x19c]=value;break;
case 14:if(value<0)value=0;if(value>100)value=100;unit[0x19d]=value;break;
case 15:*(u16 *)(unit+0x228)=value;break;
case 17:if(value>99)value=99;if(value<0)value=0;
(*(u8 **)(unit+0x188))[0x1c]=value-(*(u8 **)(unit+0x18c))[0x3d];break;
}
fn_8003712C(unit);return 0;
}

#pragma peephole on
void fn_800A2410(s32 arg0, s32 arg1, void *arg2)
{
    void *Map_GetCursorUnit(void);
    u8 fn_800386B0(void *);
    s8 Unit_GetHp(void *);
    s8 Unit_GetStr(void *);
    s8 Unit_GetMag(void *);
    s8 Unit_GetSkl(void *);
    s8 Unit_GetSpd(void *);
    s8 Unit_GetLck(void *);
    s8 Unit_GetDef(void *);
    s8 Unit_GetRes(void *);
    s8 Unit_GetCon(void *);
    s8 Unit_GetMov(void *);
    s8 fn_8003C114(void *);
    s8 fn_800386E0(void *);
    f32 fn_80037904(void *, s32);
    s8 fn_8003A1E0(void *);

    void sprintf(u8 *, void *, ...);
    void Ui_DrawMenuTextItem(s32, s32, void *);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetText(void *);
    void Prim2D_SetScale(f32);
    void Prim2D_SetTint(s32, s32, s32, s32);
    void Prim2D_EndPrim(void);

    extern u8 gMenuCmdStrings[];
    extern f32 lbl_80369A00;
    extern f32 gItemMenuTextScale;

    u8 buffer[8];
    u8 *item;
    u8 *unit;
    s32 value;
    f32 result;

    item = (u8 *)arg2;
    unit = (u8 *)Map_GetCursorUnit();

    value = 0;

    switch (item[0x3A]) {
    case 0:
        value = *(s8 *)(unit + 0x19A);
        break;

    case 1:
        value = fn_800386B0(unit);
        break;

    case 2:
        value = Unit_GetHp(unit);
        break;

    case 3:
        value = *(s8 *)(unit + 0x1A8);
        break;

    case 4:
        value = Unit_GetStr(unit);
        break;

    case 5:
        value = Unit_GetMag(unit);
        break;

    case 6:
        value = Unit_GetSkl(unit);
        break;

    case 7:
        value = Unit_GetSpd(unit);
        break;

    case 8:
        value = Unit_GetLck(unit);
        break;

    case 9:
        value = Unit_GetDef(unit);
        break;

    case 10:
        value = Unit_GetRes(unit);
        break;

    case 11:
        value = Unit_GetCon(unit);
        break;

    case 12:
        value = Unit_GetMov(unit);
        break;

    case 13:
        value = fn_8003C114(unit);
        break;

    case 14:
        value = fn_800386E0(unit);
        break;

    case 15:
        value = *(u16 *)(unit + 0x228);
        break;

    case 16:
        result = fn_80037904(unit, -1);
        value = (s32)(lbl_80369A00 * result);
        break;

    case 17:
        value = fn_8003A1E0(unit);
        break;
    }

    sprintf(
        buffer,
        gMenuCmdStrings + 0x6D2,
        value
    );

    Ui_DrawMenuTextItem(arg0, arg1, item);

    Prim2D_AddPrim(5);

    Prim2D_SetPos(
        (f32)(*(s16 *)(item + 0x30) + 0x50),
        (f32)*(s16 *)(item + 0x32)
    );

    Prim2D_SetText(buffer);
    Prim2D_SetScale(gItemMenuTextScale);

    if (item[0x38] != 0) {
        Prim2D_SetTint(0xFF, 0xFF, 0, 0xFF);
    }

    if (item[0x39] == 2) {
        Prim2D_SetTint(0, 0, 0, 0xFF);
    }

    Prim2D_EndPrim();
}

#pragma global_optimizer reset
#pragma optimization_level 3
s32 fn_800A2624(void *arg0) {
    M2C_FIELD(arg0, u16 *, 4) = (u16) M2C_FIELD(M2C_FIELD(Map_GetCursorUnit(), void **, 0x18C), u16 *, 0x38);
    return 0;
}
#pragma optimization_level reset
char *fn_800A2660(void *arg0) {
    void *Job_Get(s16);
    s32 fn_800A8978(void);
    void sprintf(void *, void *, ...);
    extern u8 gMenuCmdStrings[];
    extern char gItemMenuTextBuf[];
    void *temp_r31;
    s32 temp_r6;

    temp_r31 = Job_Get(*(s16 *)((u8 *)arg0 + 4));
    temp_r6 = fn_800A8978();
    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x6D6, *(s16 *)((u8 *)arg0 + 4), temp_r6, *(s32 *)temp_r31);
    return gItemMenuTextBuf;
}

s32 fn_800A26D0(void *arg0)
{
    extern u8 *gPadInput;
    extern s32 lbl_803671D8;

    u8 *obj;
    s32 limit;
    s32 value;

    obj = gPadInput;
    limit = lbl_803671D8;

    if (*(u32 *)(obj + 0x10) & 0x01000001) {
        value = *(s16 *)((u8 *)arg0 + 4);

        if (value == 1) {
            *(s16 *)((u8 *)arg0 + 4) = limit;
        } else {
            *(s16 *)((u8 *)arg0 + 4) = value - 1;
        }
    }

    obj = gPadInput;

    if (*(u32 *)(obj + 0x10) & 0x02000002) {
        value = *(s16 *)((u8 *)arg0 + 4);

        if (value == limit) {
            *(s16 *)((u8 *)arg0 + 4) = 1;
        } else {
            *(s16 *)((u8 *)arg0 + 4) = value + 1;
        }
    }

    return 0;
}

s32 fn_800A2748(void *arg0) {
    s32 Job_Get(s16);
    s32 fn_8003C6BC(s32, s32, s32);

    s32 temp_r31 = Map_GetCursorUnit();
    s16 temp_r5 = M2C_FIELD(arg0, s16 *, 4);
    s32 temp_r3 = Job_Get(temp_r5);
    fn_8003C6BC(temp_r31, 0, temp_r3);
    return 0;
}

#pragma optimization_level 3
s32 fn_800A279C(void *arg0) {
    M2C_FIELD(arg0, u16 *, 4) = (u16) M2C_FIELD(M2C_FIELD(fn_800AA794(), void **, 0x188), u16 *, 0x18);
    return 0;
}
#pragma optimization_level reset
char *fn_800A27D8(void *arg0) {
    void *Person_Get(s16);
    s32 Msg_ResolveName(void);
    void sprintf(void *, void *, ...);
    extern u8 gMenuCmdStrings[];
    extern char gItemMenuTextBuf[];
    void *temp_r31;
    s32 temp_r6;

    temp_r31 = Person_Get(*(s16 *)((u8 *)arg0 + 4));
    temp_r6 = Msg_ResolveName();
    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x6D6, *(s16 *)((u8 *)arg0 + 4), temp_r6, *(s32 *)temp_r31);
    return gItemMenuTextBuf;
}

s32 fn_800A2848(void *arg0)
{
    extern u8 *gPadInput;
    extern s32 lbl_803671D0;

    u8 *obj;
    s32 limit;
    s32 value;

    obj = gPadInput;
    limit = lbl_803671D0;

    if (*(u32 *)(obj + 0x10) & 0x01000001) {
        value = *(s16 *)((u8 *)arg0 + 4);

        if (value == 1) {
            *(s16 *)((u8 *)arg0 + 4) = limit;
        } else {
            *(s16 *)((u8 *)arg0 + 4) = value - 1;
        }
    }

    obj = gPadInput;

    if (*(u32 *)(obj + 0x10) & 0x02000002) {
        value = *(s16 *)((u8 *)arg0 + 4);

        if (value == limit) {
            *(s16 *)((u8 *)arg0 + 4) = 1;
        } else {
            *(s16 *)((u8 *)arg0 + 4) = value + 1;
        }
    }

    return 0;
}

s32 fn_800A28C0(void *arg0) {
    s32 Person_Get(s16);
    M2C_UNK fn_8003C6BC(s32, s32, M2C_UNK);

    s32 temp_r31 = Map_GetCursorUnit();
    s32 arg1 = Person_Get(M2C_FIELD(arg0, s16 *, 4));
    fn_8003C6BC(temp_r31, arg1, 0);
    return 0;
}

char *fn_800A2914(void) {
    void *Res_GetEntry(u8);
    s32 fn_8010586C(void);
    void sprintf(void *, void *, ...);
    extern u8 lbl_80366E08;
    extern u8 gMenuCmdStrings[];
    extern char gItemMenuTextBuf[];
    u8 temp_r31;
    s32 temp_r6;

    temp_r31 = *((u8 *)Res_GetEntry(lbl_80366E08) + 0x18);
    temp_r6 = fn_8010586C();
    sprintf(gItemMenuTextBuf, gMenuCmdStrings + 0x2C7, temp_r31, temp_r6);
    return gItemMenuTextBuf;
}

s32 fn_800A2974(void) {
    extern void *gPadInput;
    extern u8 lbl_80366E08;

    if (*(u32*)((u8*)gPadInput + 0xC) & 0x1000001) {
        if (lbl_80366E08 == 0)
            lbl_80366E08 = 0x61;
        else
            lbl_80366E08 -= 1;
    }
    if (*(u32*)((u8*)gPadInput + 0xC) & 0x2000002) {
        if (lbl_80366E08 == 0x61)
            lbl_80366E08 = 0;
        else
            lbl_80366E08 += 1;
    }
    return 0;
}

s32 fn_800A29E8(void) {
    M2C_UNK Res_GetEntry(u8);
    u8 Status_Test(s32, u8);
    M2C_UNK Status_Clear(s32, u8);
    extern u8 lbl_80366E08;
    s32 temp_r31;

    temp_r31 = Map_GetCursorUnit();
    Res_GetEntry(lbl_80366E08);
    if (Status_Test(temp_r31 + 0x1BC, lbl_80366E08) == 0) {
        Status_Clear(temp_r31 + 0x1BC, lbl_80366E08);
    }
    return 5;
}

void *fn_800A2A40(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x6e4;
}

s32 fn_800A2A50(void) {
    return 0x10;
}

void fn_800A2A58(void *arg0, void *arg1) {
    M2C_UNK fn_801043FC(u8);
    fn_801043FC(*(u8 *)((char *)arg1 + 0x3A));
}

#pragma use_lmw_stmw on
s32 fn_800A2A7C(s32 arg0, s32 arg1, void *arg2) {
    void *Map_GetCursorUnit(void);
    s32 Unit_GetSkillRank(void *, u8);
    void Unit_SetSkillRank(void *, u8, s32);
    extern void *gPadInput;
    struct RankLimits { s32 rank[16]; };
    extern const struct RankLimits lbl_8026D838;
    u8 *unit;
    u32 skill;
    s32 rank;
    u32 flags;
    unit = Map_GetCursorUnit();
    skill = *(u8 *)((u8 *)arg2 + 0x3a);
    rank = Unit_GetSkillRank(unit + 0x1a4, skill);
    flags = *(u32 *)((u8 *)gPadInput + 0xc);
    if ((flags & 0x01000001) && rank != 0)
        rank--;
    if (flags & 0x02000002) {
        struct RankLimits limits = lbl_8026D838;
        rank++;
        if (rank > limits.rank[skill])
            rank = limits.rank[skill];
    }
    Unit_SetSkillRank(unit + 0x1a4, skill, rank);
    return 0;
}
/* Draw a menu text item, then overlay the cursor unit's skill rank. */
void Ui_DrawSkillRankMenuItem(s32 unused, s32 parent, void *item) {
    void *Map_GetCursorUnit(void);
    void Prim2D_SetText(void *);
    void Prim2D_SetScale(f32);
    void Prim2D_SetTint(s32, s32, s32, s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Ui_DrawMenuTextItem(s32, s32, void *);
    s32 Unit_GetSkillRank(void *, u8);
    void sprintf(u8 *, void *, ...);
    extern u8 gMenuCmdStrings[];
    extern f32 gItemMenuTextScale;
    u8 buf[8];

    sprintf(buf, gMenuCmdStrings + 0x6E5, Unit_GetSkillRank((u8 *)Map_GetCursorUnit() + 0x1A4, *(u8 *)((u8 *)item + 0x3A)));
    Ui_DrawMenuTextItem(unused, parent, item);
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)(*(s16 *)((u8 *)item + 0x30) + 0x64), (f32)*(s16 *)((u8 *)item + 0x32));
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

f32 fn_800A2CC0(void) {
    extern f32 lbl_80369A08;
    return lbl_80369A08;
}

s32 fn_800A2CC8(void) {
    return 0x140;
}

s32 fn_800A2CD0(void *a, void *b, s32 arg) {
 void *Map_GetCursorUnit(void);
 u8 Unit_CountSupportPartners(void *);
 u32 fn_80037004(void *, u8);
 s32 Unit_GetSupportPartner(void *, u8);
 void *obj; void *p; u8 value;
 obj=Map_GetCursorUnit();
 p=*(void **)((u8 *)obj+0x188);
 if(*(u32 *)((u8 *)p+0x50)==0) return 3;
 value=(u8)arg;
 if((s32)(u8)Unit_CountSupportPartners(obj)<=(s32)value) return 3;
 if(fn_80037004(obj,value)==0) return 3;
 return Unit_GetSupportPartner(obj,value)==0?2:0;
}

#pragma push
#pragma opt_common_subs off
void fn_800A2D78(s32 arg0, s32 arg1, void *arg2) {
    void *Map_GetCursorUnit(void);
    M2C_UNK Prim2D_Begin(void);
    M2C_UNK Prim2D_AddZ(f32);
    M2C_UNK Prim2D_SetTex(M2C_UNK, M2C_UNK);
    M2C_UNK Prim2D_PrepareTex(void);
    s32 fn_80037004(void *, s32);
    u8 Unit_CountSupportPartners(void *);
    s32 Msg_ResolveName(s32);
    M2C_UNK sprintf(u8 *, void *, ...);
    M2C_UNK Prim2D_AddPrim(M2C_UNK);
    M2C_UNK Prim2D_SetPos(f32, f32);
    M2C_UNK Prim2D_SetText(void *);
    M2C_UNK Prim2D_SetTint(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Prim2D_SetScale(f32);
    M2C_UNK Prim2D_EndPrim(void);
    s32 Unit_GetSupportRank(void *, s32);
    u8 fn_80036FC4(void *, s32);
    u8 fn_80036B20(void *, s32);
    M2C_UNK strcat(void *, void *);
    extern u8 gMenuCmdStrings[];
    extern s32 lbl_8026D7C8[];
    extern f32 gItemMenuTextZ;
    extern f32 gItemMenuTextScale;
    struct UnitEntry *row2;
    struct UnitEntry *row;
    void *obj;
    u32 idx;
    s32 temp;
    s32 vals[4];
    u8 sp18[0x20];

    obj = Map_GetCursorUnit();
    if (M2C_FIELD(M2C_FIELD(obj, void **, 0x188), void **, 0x50) != NULL) {
        idx = M2C_FIELD(arg2, u8 *, 0x3A);
        if ((u8) Unit_CountSupportPartners(obj) > (s32) idx) {
            Prim2D_Begin();
            Prim2D_AddZ(gItemMenuTextZ);
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            sprintf(sp18, gMenuCmdStrings + 0x6C7, Msg_ResolveName(fn_80037004(obj, idx)));
            Prim2D_AddPrim(5);
            Prim2D_SetPos((f32) M2C_FIELD(arg2, s16 *, 0x30), (f32) M2C_FIELD(arg2, s16 *, 0x32));
            Prim2D_SetText(sp18);
            if (M2C_FIELD(arg2, u8 *, 0x39) != 0) {
                Prim2D_SetTint(0, 0, 0, 0xFF);
            }
            Prim2D_SetScale(gItemMenuTextScale);
            Prim2D_EndPrim();
            row2 = (struct UnitEntry *) ((u8 *) M2C_FIELD(M2C_FIELD(obj, void **, 0x188), void **, 0x50) + idx * 8 + 8);
            row = (struct UnitEntry *) ((u8 *) M2C_FIELD(M2C_FIELD(obj, void **, 0x188), void **, 0x50) + idx * 8 + 8);
            temp = Unit_GetSupportRank(obj, idx);
            vals[0] = lbl_8026D7C8[0];
            vals[1] = lbl_8026D7C8[1];
            vals[2] = lbl_8026D7C8[2];
            vals[3] = lbl_8026D7C8[3];
            sprintf(sp18, gMenuCmdStrings + 0x704, vals[(u8) temp], (u8) fn_80036FC4(obj, idx), row->unk4, row->unk5, row2->unk6);
            if (fn_80036B20(obj, idx)) {
                strcat(sp18, gMenuCmdStrings + 0x719);
            }
            Prim2D_AddPrim(5);
            Prim2D_SetPos((f32) (M2C_FIELD(arg2, s16 *, 0x30) + 0x5A), (f32) M2C_FIELD(arg2, s16 *, 0x32));
            Prim2D_SetText(sp18);
            if (M2C_FIELD(arg2, u8 *, 0x39) != 0) {
                Prim2D_SetTint(0, 0, 0, 0xFF);
            }
            Prim2D_SetScale(gItemMenuTextScale);
            Prim2D_EndPrim();
        }
    }
}
#pragma pop
s32 fn_800A2FC4(s32 arg0, s32 arg1, void *arg2) {
    void *Map_GetCursorUnit(void);
    void *Unit_GetSupportPartner(void *, u8);
    s32 Unit_FindSupportPartnerIndex(void *, void *);
    u8 fn_80036FC4(void *, u8);
    extern void *gPadInput;
    s32 index;
    u8 *unit;
    u8 *partner;
    u8 other;
    u32 slot;
    s32 value;
    u32 flags;
    u8 *table;
    s32 offset;
    s32 row;

    if (*(u8 *)((u8 *)arg2 + 0x39)) {
        return 0;
    }
    unit = Map_GetCursorUnit();
    slot = *(u8 *)((u8 *)arg2 + 0x3A);
    partner = Unit_GetSupportPartner(unit, slot);
    index = (u8)Unit_FindSupportPartnerIndex(unit, *(void **)(partner + 0x188));
    other = Unit_FindSupportPartnerIndex(partner, *(void **)(unit + 0x188));
    value = fn_80036FC4(unit, index);
    flags = *(u32 *)((u8 *)gPadInput + 0x10);
    if (flags & 0x01000001) {
        value--;
    }
    if (flags & 0x02000002) {
        value++;
    }
    if (value < 0) {
        value = 0;
    }
    offset = slot * 8;
    row = offset + 8;
    table = *(u8 **)(*(u8 **)(unit + 0x188) + 0x50);
    row = (s32)table + row;
    if (value > (u8)(*(u8 *)(row + 6) + 1)) {
        value = (u8)(table[offset + 0xE] + 1);
    }
    *(unit + index + 0x214) = value;
    *(partner + other + 0x214) = value;
    return 0;
}
#pragma opt_common_subs reset
s32 fn_800A30D8(void) {
    return 0;
}

f32 fn_800A30E0(void) {
    extern f32 lbl_80369A0C;
    return lbl_80369A0C;
}

void *fn_800A30E8(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x71c;
}

extern void *fn_800241C8(s32);
extern void fn_8014DE70(s32);
s32 fn_800A30F8(s32 arg0, s32 arg1) {
    void *fn_800241C8(s32);
    M2C_UNK fn_8014DE70(s32);
    fn_8014DE70(M2C_FIELD(fn_800241C8(arg1), s32 *, 0x18));
    return 6;
}

void *fn_800A3128(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x725;
}

s32 fn_800A3138(s32 unused, s32 arg1) {
    void Process_Unlink(void);
    void *fn_800241C8(s32);
    void fn_800C28A0(s32);
    s32 temp_r31;

    temp_r31 = M2C_FIELD(fn_800241C8(arg1), s32 *, 0x18);
    fn_800241C8(arg1);
    Process_Unlink();
    fn_800C28A0(temp_r31);
    return 5;
}

void *fn_800A318C(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x736;
}

s32 fn_800A319C(void) {
    M2C_UNK fn_800C221C();
    fn_800C221C();
    return 5;
}

void *fn_800A31C0(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x74b;
}

s32 fn_800A31D0(s32 arg0, s32 arg1) {
    extern s8 lbl_80367558;
    extern s8 lbl_80367559;
    extern M2C_UNK lbl_80367564;
    lbl_80367558 = 0;
    lbl_80367559 = 5;
    Ui_CreateMenu(&lbl_80367564, arg1, 0);
    return 0;
}

s32 fn_800A320C(void) {
    extern void *gPadInput;
    extern u8 lbl_80367558;
    extern u8 lbl_80367559;
    if (((s8) lbl_80367558 > 0) && (M2C_FIELD(gPadInput, s32 *, 0xC) & 0x01000001)) {
        lbl_80367558 -= 1;
    }
    if (((s8) lbl_80367558 < (s8) lbl_80367559) && (M2C_FIELD(gPadInput, s32 *, 0xC) & 0x02000002)) {
        lbl_80367558 += 1;
    }
    return 0;
}

#pragma global_optimizer off
s32 fn_800A3278(void *a, void *b, void *arg) {
    extern u8 gBattleState[];
    extern u8 lbl_80367558;
    void fn_800BDB54(void *, s32);
    void fn_800BDB78(void *, s32);
    u8 fn_800BDB9C(void *, s32);
    s32 index;
    u8 *base;
    s32 row;
    u8 col;

    base = (u8 *)((u32)gBattleState + 0xb4);
    row = (s8)lbl_80367558;
    col = *((u8 *)arg + 0x3a);
    index = (row << 4) + col - 1;

    if (*(u32 *)(base + (index << 2)) == 0) {
        return 0;
    }
    if (fn_800BDB9C(base, index)) fn_800BDB54(base, index);
    else fn_800BDB78(base, index);
    return 0;
}
#pragma global_optimizer on
void fn_800A3314(s32 arg0,s32 arg1,void *item) {
void sprintf(void *,void *,...);
void Prim2D_Begin(void);
void Prim2D_AddZ(f32);
void Prim2D_SetTex(s32,s32);
void Prim2D_PrepareTex(void);
void Prim2D_AddPrim(s32);
void Prim2D_SetPos(f32,f32);
void Prim2D_SetText(void *);
void Prim2D_SetScale(f32);
void Prim2D_EndPrim(void);
u8 fn_800BDB9C(void *,s32);
extern u8 gBattleState[],gMenuCmdStrings[];
extern u8 lbl_80367558;
extern f32 gItemMenuTextZ,gItemMenuTextScale;
u8 buf[32];
s32 index=(((s8)lbl_80367558)<<4)+*(u8 *)((u8 *)item+0x3a)-1;
u8 *base=gBattleState+0xb4;
s32 offset=index*4;
if(*(u32 *)(base+offset)) {
Prim2D_Begin();
Prim2D_AddZ(gItemMenuTextZ);
Prim2D_SetTex(0,19);
Prim2D_PrepareTex();
sprintf(buf,gMenuCmdStrings+0x6c7,*(u32 *)(base+offset));
Prim2D_AddPrim(5);
Prim2D_SetPos((f32)*(s16 *)((u8 *)item+0x30),(f32)*(s16 *)((u8 *)item+0x32));
Prim2D_SetText(buf);
Prim2D_SetScale(gItemMenuTextScale);
Prim2D_EndPrim();
if(fn_800BDB9C(base,index)) {
Prim2D_AddPrim(5);
Prim2D_SetPos((f32)(*(s16 *)((u8 *)item+0x30)-16),(f32)*(s16 *)((u8 *)item+0x32));
Prim2D_SetText(gMenuCmdStrings+0x756);
Prim2D_SetScale(gItemMenuTextScale);
Prim2D_EndPrim();
}
}
}

char *fn_800A3490(void) {
    void sprintf(void *, void *, ...);
    extern char lbl_80312328[];
    extern u8 gMenuCmdStrings[];
    extern u8 lbl_80367558;
    extern u8 lbl_80367559;

    sprintf(lbl_80312328, gMenuCmdStrings + 0x759, (s8)lbl_80367558 + 1, (s8)lbl_80367559 + 1);
    return lbl_80312328;
}

s32 fn_800A34E8(void) {
    extern void *gPadInput;
    extern u8 lbl_80367558;
    extern u8 lbl_80367559;
    if (((s8) lbl_80367558 > 0) && (M2C_FIELD(gPadInput, s32 *, 0xC) & 0x01000001)) {
        lbl_80367558 -= 1;
    }
    if (((s8) lbl_80367558 < (s8) lbl_80367559) && (M2C_FIELD(gPadInput, s32 *, 0xC) & 0x02000002)) {
        lbl_80367558 += 1;
    }
    return 0;
}

f32 fn_800A3554(void) {
    extern f32 lbl_80369A10;
    return lbl_80369A10;
}

void *fn_800A355C(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x769;
}

extern s32 lbl_80367528;
s32 fn_800A356C(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_80367528, arg1, 0);
    return 0;
}

u16 *fn_800A3598(void) {
    extern u16 gMenuCmdStrings[];
    return (u16 *)((u8 *)gMenuCmdStrings + 0x76f);
}

s32 fn_800A35A8(s32 unused, s32 arg1) {
    void *fn_800241C8(s32);
    void fn_80108C80(void *, s32, void *);
    extern u8 gMenuCmdStrings[];

    fn_80108C80(gMenuCmdStrings + 0x774, *(s32 *)((u8 *)fn_800241C8(arg1) + 0x18), gMenuCmdStrings);
    return 6;
}

void *fn_800A35E4(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x781;
}

s32 fn_800A35F4(s32 arg0, s32 arg1) {
    void *fn_800241C8(s32);
    M2C_UNK fn_801C7F60(s32);
    fn_801C7F60(M2C_FIELD(fn_800241C8(arg1), s32 *, 0x18));
    return 6;
}

void *fn_800A3624(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x78f;
}

s32 fn_800A3634(void) {
    M2C_UNK fn_800C0C54();
    fn_800C0C54();
    return 0;
}

void *fn_800A3658(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x796;
}

s32 fn_800A3668(s32 arg0, s32 arg1) {
    void *fn_800241C8(s32);
    M2C_UNK fn_8012B488(s32);
    fn_8012B488(M2C_FIELD(fn_800241C8(arg1), s32 *, 0x18));
    return 6;
}

void *fn_800A3698(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x7A8;
}

s32 fn_800A36A8(s32 arg0, s32 arg1) {
    void *fn_800241C8(s32);
    M2C_UNK fn_80127170(s32);
    fn_80127170(M2C_FIELD(fn_800241C8(arg1), s32 *, 0x18));
    return 6;
}

void *fn_800A36D8(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x7B3;
}

s32 fn_800A36E8(s32 unused, s32 arg1) {
    void *fn_800241C8(s32);
    void fn_80108C80(void *, s32, void *);
    extern u8 gMenuCmdStrings[];

    fn_80108C80(gMenuCmdStrings + 0x7BF, *(s32 *)((u8 *)fn_800241C8(arg1) + 0x18), gMenuCmdStrings);
    return 6;
}

void *fn_800A3724(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x7CD;
}

s32 fn_800A3734(s32 unused, s32 arg1) {
    void *fn_800241C8(s32);
    void fn_80108C80(void *, s32, void *);
    extern u8 gMenuCmdStrings[];

    fn_80108C80(gMenuCmdStrings + 0x7D3, *(s32 *)((u8 *)fn_800241C8(arg1) + 0x18), gMenuCmdStrings);
    return 6;
}

#pragma global_optimizer off
void fn_800A3770(void) {
    void fn_8005B918(u8 *);
    s32 fn_8005B8CC(void);
    s32 fn_8005B8AC(s32);
    s32 fn_8005C0AC(s32, u8 *);
    extern u8 gMenuCmdStrings[];
    extern s32 lbl_80312290[];
    extern s32 lbl_80367520;
    s32 item;
    s32 count;
    s32 i;

    fn_8005B918(gMenuCmdStrings + 0x7E0);
    count = fn_8005B8CC();
    lbl_80367520 = 0;
    for (i = 0; i < count; i++) {
        item = fn_8005B8AC(i);
        if ((u8)fn_8005C0AC(item, gMenuCmdStrings + 0x7E6) != 0) {
            lbl_80312290[lbl_80367520++] = item;
        }
    }
}
#pragma global_optimizer on
void fn_800A3808(void) {
    M2C_UNK fn_8005B8E8();
    fn_8005B8E8();
}

f32 fn_800A3828(void) {
    extern f32 lbl_80369A08;
    return lbl_80369A08;
}

void *fn_800A3830(void *arg0, void *arg1)
{
    extern s32 lbl_80367520;
    extern u8 gMenuCmdStrings[];
    extern u32 lbl_80312290[];

    s32 index;

    index = *(u8 *)((u8 *)arg1 + 0x3A);

    if (index > lbl_80367520) {
        return gMenuCmdStrings + 0x6E4;
    }

    return (void *)lbl_80312290[index];
}

s32 fn_800A3864(s32 unused, s32 arg1, void *arg2) {
    void Process_CreateChild(void *, s32); void *fn_800241C8(s32); void fn_800A5D1C(void *, s32, s32); void fn_80146B00(void); void fn_801480D8(s32); void sprintf(void *, void *, s32, ...);
    extern s32 lbl_80367520; extern u8 lbl_80289F98[], lbl_80312290[], gMenuCmdStrings[];
    u8 temp[0x40]; u8 index=*(u8 *)((u8 *)arg2+0x3a);
    if(index>=lbl_80367520) return 0x10;
    Process_CreateChild(lbl_80289F98,*(s32 *)((u8 *)fn_800241C8(arg1)+0x18));
    sprintf(temp,gMenuCmdStrings+0x7eb,*(s32 *)(lbl_80312290+index*4),gMenuCmdStrings);
    fn_800A5D1C(temp,0,1); fn_80146B00(); fn_801480D8(0xfa); return 6;
}

void *fn_800A3904(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x7F4;
}

s32 fn_800A3914(void) {
    return 0;
}

void *fn_800A391C(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x807;
}

s32 fn_800A392C(void) {
    return 0;
}

void *fn_800A3934(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x8;
}

s32 fn_800A3944(void) {
    return 0;
}

void *fn_800A394C(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x81A;
}

s32 fn_800A395C(void) {
    return 0;
}

void fn_800A3964(void *arg0) {
    extern u8 lbl_8028459C[];
    extern u8 lbl_8028A478[];
    *(void **)arg0 = lbl_8028459C;
    *(void **)arg0 = lbl_8028A478;
}

void fn_800A3980(void *arg0) {
    extern u8 lbl_8028459C[];
    extern u8 lbl_8028A42C[];
    *(void **)arg0 = lbl_8028459C;
    *(void **)arg0 = lbl_8028A42C;
}
extern u16 gMenuCmdStrings;
extern u16 gMenuCmdStrings;
extern u16 gMenuCmdStrings;
extern u16 gMenuCmdStrings;
extern u16 gMenuCmdStrings;
extern u16 gMenuCmdStrings;
extern u16 gMenuCmdStrings;
extern u8 gConvoy[];
#include "global.h"
extern u32* gPadInput;
extern u8 gBattleState[];
extern u16 gMenuCmdStrings;
extern u16 gMenuCmdStrings;
#include "global.h"

extern u16 gMenuCmdStrings;
extern u16 gItemMenuTextBuf;
extern u8 gBattleState[1400];
#include "global.h"

extern u8 gConvoy[];
extern u16 lbl_80367100;
extern s32 fn_800C3468(u16*);
