#include "common.h"
#pragma cplusplus on
struct UiAnimatedSprite {
    virtual void m08(); virtual void m0C(); virtual void m10();
    virtual s32 getTexId();
    virtual s16 getUvW(); virtual s16 getUvH();
    virtual s16 getW(); virtual s16 getH();
    virtual void m28(); virtual void m2C();
    virtual void draw(s32, s32, f32, f32, f32);
    u32 unk4;
    s32 direction;
    u8 visible, moving;
    s16 x, y, z, frame, movement;
};
struct LensFlareView {
    u8 pad[0x40];
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void setPosition(f32, f32, f32);
    virtual void setPoint(s32 *);
    virtual void setScreen(s32, s32);
    virtual void v10();
    virtual void setColor(u8, u8, u8, u8);
};
struct LensFlareOwner {
    u8 pad[0x10];
    virtual void v0(); virtual void v1();
    virtual LensFlareView *find(char *, char *);
};
struct CursorRenderView {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void update(void *);
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13();
    virtual void drawRow(s32, s16, s16, s16, u8);
};
struct ItemCursorView {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual s32 getRowOffset();
};
struct UnitPanelView {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10();
    virtual void setUnit(u32);
};
#pragma cplusplus reset
#pragma opt_common_subs off
static inline void init_761F8_base(void *p,s16 x,s16 y,s16 w,s16 h,s16 style) {
 extern u16 lbl_8028FDB0[],lbl_80292230[];
 extern f32 gF32_1;
 f32 zero;
 M2C_FIELD(p,void * *,0)=lbl_8028FDB0; M2C_FIELD(p,s32 *,4)=0; M2C_FIELD(p,void * *,0)=lbl_80292230; M2C_FIELD(p,s16 *,8)=-1;M2C_FIELD(p,s16 *,10)=x;
M2C_FIELD(p,s16 *,12)=y;
M2C_FIELD(p,s16 *,14)=x+w;
M2C_FIELD(p,s16 *,16)=y+h;
M2C_FIELD(p,s16 *,18)=0;
M2C_FIELD(p,s16 *,20)=0;
M2C_FIELD(p,s16 *,22)=w;
M2C_FIELD(p,s16 *,24)=h;
M2C_FIELD(p,s16 *,26)=0;
M2C_FIELD(p,s16 *,28)=0;M2C_FIELD(p,u8 *,30)=0xFF;
M2C_FIELD(p,u8 *,31)=0xFF;
M2C_FIELD(p,u8 *,32)=0xFF;
M2C_FIELD(p,u8 *,33)=0xFF;M2C_FIELD(p,s16 *,0x22)=style; M2C_FIELD(p,s16 *,0x24)=0;
 zero=gF32_1; M2C_FIELD(p,f32 *,0x28)=zero; M2C_FIELD(p,f32 *,0x2C)=zero; M2C_FIELD(p,f32 *,0x30)=zero;
 M2C_FIELD(p,s32 *,0x34)=0; M2C_FIELD(p,s32 *,0x38)=0;
 
}
#pragma opt_common_subs on
extern u32 gUiContext[];
extern u16 gUiMsgStrings[];
void fn_8006D8E8(void *);
extern u16 gUiListPanelProc[];

typedef struct Unk8016F694_Inner {
    u8 pad0[0x4C];
    s16 field4C;
} Unk8016F694_Inner;

typedef struct Unk8016F694_Outer {
    u8 pad0[0x44];
    void *ptr44;
    u8 pad1[0x4C - 0x44 - 4];
    Unk8016F694_Inner *inner;
} Unk8016F694_Outer;
extern u8 gBattleState[];
  extern void *lbl_803680E8;
  extern f32 lbl_8036AC2C;
extern f32 lbl_8036AC30;
extern f32 lbl_8036AC34;
extern f32 lbl_8036AC40;
extern f32 lbl_8036AC48;
extern f32 lbl_8036AC5C;
extern f32 lbl_8036AC60;
extern f32 lbl_8036AC64;
extern f32 lbl_8036AC68;
extern f32 lbl_8036AC6C;
extern f32 lbl_8036AC70;
extern f32 lbl_8036AC74;
extern f32 lbl_8036AC78;
extern f32 lbl_8036AB94;
extern u16 gUiListPanelProc[];
extern u16 E_FloatAnim_script[10];
extern f32 lbl_8036ABB0;
extern f32 lbl_8036ABBC;
extern f32 lbl_8036ABA0;
extern f32 lbl_8036A9C0;

extern u8 gUnits[];

static inline u8 IsSlotFilled(void *obj, s16 slot) {
    u32 *Unit_GetItemSlot(s32, s32);
    s32 idx = slot;
    u32 *item = Unit_GetItemSlot(M2C_FIELD(obj, s32 *, 0x58), idx);

    if (M2C_FIELD(obj, s32 *, 0x5C) == 1 && *item == 0) {
        if (slot == 0 || slot == 4 || *Unit_GetItemSlot(M2C_FIELD(obj, s32 *, 0x58), idx - 1) != 0) {
            return 1;
        }
    }
    return *item != 0;
}

static inline u8 IsSlotAvailable(void *obj, s16 slot) {
    if (slot >= 0 && slot <= 3 && !(M2C_FIELD(obj, s32 *, 0x60) & 1)) {
        return 0;
    }
    if (slot >= 4 && slot <= 7 && !(M2C_FIELD(obj, s32 *, 0x60) & 2)) {
        return 0;
    }
    return IsSlotFilled(obj, slot);
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma opt_peephole off

#pragma opt_peephole reset
#pragma global_optimizer reset
#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma cplusplus on

#pragma cplusplus reset
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma global_optimizer on

/* First empty item slot in the range selected by inv+0x60&3 (1:0-3, 2:4-7, 3:0-7), or -1. */

#pragma scheduling reset
/* Find the next filled inventory slot at or below startSlot, or -1 if none. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma global_optimizer off
/* Construct a BattleTerrain: base strings, load map path, parse param.dbx room/foot fields. */

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset

#pragma cplusplus on
#pragma global_optimizer off
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma global_optimizer reset
#pragma cplusplus reset
extern u16 lbl_8028DED0[];

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma dont_inline on

#pragma dont_inline reset

#pragma use_lmw_stmw reset

#pragma opt_common_subs off

#pragma opt_common_subs reset

#pragma cplusplus on
  extern "C" void *fn_8016915C(void *, s16, s16, s16, s16);
  extern "C" u8 gUiPanelVtbl[];

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
/* Draw a centered menu-slot label and its selection frame. */

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

extern u8 lbl_80294514[16];

extern u8 E_Jyokyo_script[16];

extern void fn_8005376C(void);
extern void FileCache_ReleaseSlot(void *);
extern void fn_800C4588(void);

#pragma global_optimizer off
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma global_optimizer reset

/* One-shot E_Jyokyo teardown: clear map disp, refresh face, free nodes/cache, unlink process. */

#pragma global_optimizer off
#pragma opt_strength_reduction off
#pragma opt_common_subs off

#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
#pragma global_optimizer reset

#pragma use_lmw_stmw off

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset
#pragma global_optimizer on
/* Draw the fullscreen map overlay: dim backdrop, then map and unit markers. */

#pragma use_lmw_stmw off
#pragma global_optimizer off

#pragma global_optimizer on

#pragma cplusplus on
/* Release a list panel's seven child refs and destroy the panel base. */

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

/* Pop a nested UI menu: rebuild the parent list, retreat a step, restore MU blend and portrait, then clear this process. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on
/* Tick map-cursor unit-info: follow the hovered unit and handle A/B/X popup input. */

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma use_lmw_stmw on
#pragma cplusplus on
/* Handle unit-list pad input: help text, unit-info popup, confirm/cancel, and back. */

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus reset
#pragma opt_common_subs on

/* Slide the unit list back on, reset the inventory panel, slide detail widget 0x107 off, dismiss 0x106, and raise the inventory. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus off

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

/* Bring the unit inventory forward for taking the selected list item, limiting slots by item flags. */

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma cplusplus on
/* Handle A/B/X/Y while choosing a trade partner from the unit list. */

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma dont_inline on
#pragma global_optimizer off
#pragma cplusplus on

#pragma cplusplus reset
#pragma global_optimizer reset
#pragma dont_inline reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma opt_common_subs on
#pragma global_optimizer on

#pragma cplusplus on
extern "C" void Ui_DrawListWindowFrame(s32, s32, s32, s16, s32, s32);
extern "C" void Ui_DrawLine(s32, s32, s16, s32, s32, void *);
extern "C" s32 Prim2D_SetAlphaByte(u8);
/* Draw a list panel's window chrome and a faint horizontal separator above the footer. */

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

extern u16 gUiMsgStrings[257];

/* If entry type is 2, show a lock-message popup at parent+entry pos; else set UI command 0x87. */

#pragma use_lmw_stmw on
#pragma cplusplus on
/* Draw a centered UI slot label, with optional leading icon. */

#pragma cplusplus reset

/* If the menu entry is locked, show a popup; otherwise set UI command 0x86. */

/* If the menu entry is locked, show a popup; otherwise set UI command 0x85 and advance the list panel. */

/* If the menu entry is locked, show a popup; otherwise open the list panel. */

/* If the list option is disabled (state 2), show a help popup for the selected submenu index; otherwise set UI command 0x83 and advance the list panel. */

#pragma opt_strength_reduction off

/* If the menu entry is locked, show a popup; otherwise set UI command 0x82. */

#pragma opt_strength_reduction reset

#pragma opt_peephole off

#pragma opt_peephole reset
/* If entry type is 2, show a lock-message popup at parent+entry pos; else set UI command 0x81. */

/* If the menu entry is locked, show a popup; otherwise set UI command 0x80. */

#pragma cplusplus on

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on
/* Space each child gfx ent evenly across parent width (v18); y = 0. */

#pragma cplusplus reset
extern "C" M2C_UNK Prim2D_SetTransform(f32, f32, f32, f32);
extern "C" M2C_UNK Prim2D_SetColorByte(u8);
extern "C" M2C_UNK Prim2D_SetAlphaByte(u8);

#pragma cplusplus on

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset
/* Move a horizontal UI row cursor with left/right, refresh unit-info text, and focus/unfocus slots. */

#pragma cplusplus reset

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

static inline void Stream_InitBase(void *self) {
    extern u8 gStreamBaseVtbl[];
    *(void **)((u8 *)self + 0x10) = gStreamBaseVtbl;
    *(s32 *)((u8 *)self + 4) = 0;
    *(s32 *)self = 0;
    *(s32 *)((u8 *)self + 8) = 0;
    *(u8 *)((u8 *)self + 0xC) = 0;
}
#pragma cplusplus on

#pragma cplusplus off

#pragma cplusplus on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer on
#pragma cplusplus reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

s32 Status_SumBonus(void *);
#pragma cplusplus on
extern "C" void Ui_DrawJobPersonalPanel(s16, s16, s16, s16, s32, s32, s32, f32);

#pragma cplusplus reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma scheduling off

#pragma scheduling on
#pragma cplusplus off

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer off

#pragma global_optimizer on

#pragma dont_inline on
#pragma global_optimizer off
#pragma optimization_level 3
#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset
#pragma optimization_level reset
#pragma global_optimizer reset
#pragma dont_inline reset

#pragma scheduling on

#pragma scheduling reset

/* Gold cost for qty after base calc, status 0x4B markup (*10/7), and 0xB half-price. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
/* Draw a UI sprite quad with frame UVs, color, and optional UV rotation. */

#pragma cplusplus reset

#pragma opt_strength_reduction off
/* Start a process that lerps target's float at +4 by amount (duration from amount). */

#pragma opt_strength_reduction reset

/* Advance FloatAnim: tick, lerp target's float at +4, play rise SE on odd frames, clear when duration elapses. */

#pragma global_optimizer off

#pragma global_optimizer on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw off
#pragma peephole off
#pragma cplusplus on

#pragma cplusplus reset
#pragma peephole reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus reset
/* Create the unit-info title (id 0x80) and caption (id -0x1000) widgets and attach them to parent. */

#pragma opt_common_subs off

#pragma cplusplus on

#pragma use_lmw_stmw on

#pragma cplusplus reset

#pragma cplusplus on
extern "C" s32 Unit_GetSupportRankTotal(s32, s16);
extern "C" void fn_80157700(s32, s16, u8, s32);
extern "C" void fn_80157930(s32, s32, s16, s16, s32, s32);

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma cplusplus reset

#pragma scheduling on
#pragma peephole on

void fn_80181C40(s32 *arg0, void *arg1) {
    s32 *fn_8013F748(void *, s32 *, s16 *);
    s32 spC;
    s16 sp8;
    s16 spA;
    void *self;
    s16 index;
    s16 step;
    s16 x;
    s16 y;

    self = arg1;
    index = *(s16 *)((u8 *)arg1 + 0x4E);
    step = *(s16 *)((u8 *)arg1 + 0x54);
    x = *(s16 *)((u8 *)self + 0x56);
    y = *(s16 *)((u8 *)self + 0x58);
    sp8 = x;
    spA = (s16)(step * index + y);
    (void)spA;
    *arg0 = *fn_8013F748(self, &spC, &sp8);
}
#pragma scheduling reset
#pragma peephole reset
typedef struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
} ListNode;

typedef struct List {
    u32 unk0;
    ListNode node;
} List;

typedef struct ListOwner {
    void *vtbl;
    u8 pad4[0x58];
    List list;
} ListOwner;
