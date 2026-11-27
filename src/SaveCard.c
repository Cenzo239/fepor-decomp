/* Functions from 0x801B3258 to 0x801E4380, found by decomp-toolkit. */
#include "common.h"
static inline void *SaveMenu_GetHeader(void *base) {
    void *fn_801E09B4(void *);
    u8 *slot = fn_801E09B4(base);
    if (slot != NULL && slot[0x60] == 3) return slot;
    return NULL;
}
static inline void *SaveMenu_GetUnit(void *base, void *id) {
    void *fn_801E2324(void *, void *);
    u8 *slot = fn_801E2324(base, id);
    if (slot != NULL && slot[0x60] == 2) return slot;
    return NULL;
}
const f64 lbl_8036B670 = 4503816931318784.0;
static inline u8 *Battle_FindActiveSideUnit(void) {
    extern u8 gBattle[];
    u8 *unit;
    u8 type;
    unit = *(u8 **)(gBattle + 0x280);
    if (unit) {
        type = (*(u8 **)(unit + 0x190))[8];
        if (type == 0 || type == 5) return unit;
    }
    unit = *(u8 **)(gBattle + 0x560);
    if (unit) {
        type = (*(u8 **)(unit + 0x190))[8];
        if (type == 0 || type == 5) return unit;
    }
    return 0;
}
static inline u8 *MenuResource_ClearIn(s32 clear, u8 *base) {
    void FileCache_ReleaseSlot(void *);
    u8 *p;
    s32 i = 0;
    for (p = base; i < 40; i++, p += 12) {
        if (*(u32 *)(p + 8)) FileCache_ReleaseSlot(p + 8);
        *(u32 *)(p + 8) = clear;
    }
    return base;
}

static inline void MenuResource_ClearSlots(u8 *base, s32 clear) {
    void FileCache_ReleaseSlot(void *);
    u8 *p;
    s32 i = 0;
    for (p = base; i < 40; i++, p += 12) {
        if (*(u32 *)(p + 8)) FileCache_ReleaseSlot(p + 8);
        *(u32 *)(p + 8) = clear;
    }
}
static inline void MenuResource_ClearTable(u8 **base) {
    void FileCache_ReleaseSlot(void *);
    u8 *p;
    s32 clear;
    s32 i = 0;
    clear = i;
    for (p = *base; i < 40; i++, p += 12) {
        if (*(u32 *)(p + 8)) FileCache_ReleaseSlot(p + 8);
        *(u32 *)(p + 8) = clear;
    }
}
static inline u8 *MenuResource_FindIn(u8 *p, s32 id) {
s32 i;
for(i=0;i<40;p+=12,i++) { if(id==*(s32*)p) return p; }
return 0;
}
static inline u8 *MenuResource_Find(s32 id) {
extern u8 lbl_80299A78[];
u8 *p=lbl_80299A78;
s32 i;
for(i=0;i<40;i++,p+=12) { if(id==*(s32*)p) return p; }
return 0;
}
#pragma cplusplus on
struct MenuD28 {
virtual s32 v0()=0;
virtual s32 v1()=0;
virtual s32 v2()=0;
virtual s32 v3()=0;
virtual s32 v4()=0;
virtual s32 v5()=0;
virtual s32 v6()=0;
virtual s32 v7()=0;
virtual s32 v8()=0;
virtual s32 v9()=0;
virtual s32 v10()=0;
};
struct UnitHireItem {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
virtual void v15();
virtual void v16();
virtual void v17();
virtual void set2(s32);
virtual void v19();
virtual void set3(s32);
};
struct UnitHireMenuBase { u32 unknown; };
struct UnitHireMenu : UnitHireMenuBase {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
virtual UnitHireItem *get(s32);
};
static inline void InitPanelBase480x256(u8 *w, s16 x, s16 y, s16 id, f32 one) {
    extern u8 lbl_8028FDB0[], lbl_80292230[];
    s16 right = (s16)(x + 0x1E0);
    s16 bottom = (s16)(y + 0x100);
    *(void **)w = lbl_8028FDB0;
    *(s32 *)(w + 4) = 0;
    *(void **)w = lbl_80292230;
    *(s16 *)(w + 8) = -1;
    *(s16 *)(w + 0xA) = x;
    *(s16 *)(w + 0xC) = y;
    *(s16 *)(w + 0xE) = right;
    *(s16 *)(w + 0x10) = bottom;
    *(s16 *)(w + 0x12) = 0;
    *(s16 *)(w + 0x14) = 0;
    *(s16 *)(w + 0x16) = 0x1E0;
    *(s16 *)(w + 0x18) = 0x100;
    *(s16 *)(w + 0x1A) = 0;
    *(s16 *)(w + 0x1C) = 0;
    w[0x1E] = 255; w[0x1F] = 255; w[0x20] = 255; w[0x21] = 255;
    *(s16 *)(w + 0x22) = id;
    *(s16 *)(w + 0x24) = 0;
    *(f32 *)(w + 0x28) = one;
    *(f32 *)(w + 0x2C) = one;
    *(f32 *)(w + 0x30) = one;
    *(s32 *)(w + 0x34) = 0;
    *(s32 *)(w + 0x38) = 0;
}
static inline void InitUnitHireWidget(u8 *w) {
    extern u8 lbl_8028FDB0[], lbl_80292230[], lbl_8029186C[];
        *(void **)(w+0) = lbl_8028FDB0;
        *(s32 *)(w+4) = 0;
        *(void **)(w+0) = lbl_80292230;
        *(s16 *)(w+8) = -1;
        *(s16 *)(w+0xA) = 0x260;
        *(s16 *)(w+0xC) = 0x7C;
        *(s16 *)(w+0xE) = 0x368;
        *(s16 *)(w+0x10) = 0x16E;
        *(s16 *)(w+0x12) = 0;
        *(s16 *)(w+0x14) = 0;
        *(s16 *)(w+0x16) = 0x108;
        *(s16 *)(w+0x18) = 0xF2;
        *(s16 *)(w+0x1A) = 0;
        *(s16 *)(w+0x1C) = 0;
        w[0x1E] = 255; w[0x1F] = 255; w[0x20] = 255; w[0x21] = 255;
        *(s16 *)(w+0x22) = 0x1E0;
        *(s16 *)(w+0x24) = 0;
        *(f32 *)(w+0x28) = 1.0f;
        *(f32 *)(w+0x2C) = 1.0f;
        *(f32 *)(w+0x30) = 1.0f;
        *(s32 *)(w+0x34) = 0;
        *(s32 *)(w+0x38) = 0;
        *(void **)(w+0) = lbl_8029186C;
        *(s32 *)(w+0x3C) = 0;
        *(s16 *)(w+0x40) = 20;
        *(s16 *)(w+0x42) = 8;
}
struct UnitHireWidgetFields {
    void *vtable; s32 refcount;
    s16 id, x, y, right, bottom, offX, offY, width, height, scrollX, scrollY;
    u8 color[4]; s16 style, mode; f32 scale[3]; u32 flags, unk38;
    void *entry; s16 unk40, unk42;
};
struct UnitHireWidget {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void init();
};
#pragma cplusplus reset




typedef struct SaveMenuFileEntry {
 s16 flags;
 u8 pad02[8];
 s16 x, y;
 u8 pad0E[0x3E];
} SaveMenuFileEntry;
typedef struct SaveMenuFileEntries {
 u8 pad00[0x1B4];
 SaveMenuFileEntry files[5];
} SaveMenuFileEntries;
typedef struct ParseValue801CB41C { f32 v[8]; } ParseValue801CB41C;
typedef struct String801CB41C { u32 a, b, c; } String801CB41C;

typedef struct Self801CAF94 {
    s32 unk0;
    u8 pad4[0x50];
    s32 unk54;
    u8 pad58[0x14];
    void *unk6C;
    u8 pad70[4];
    s32 unk74;
    s8 unk78;
    s8 unk79;
} Self801CAF94;

void *Process_Create(void *, s32);
void *fn_801BEB9C(void *arg0, s16 *arg1, s16 *arg2, s16 arg3);

typedef struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    void *val;
} ListNode;

typedef struct ListIter {
    ListNode *node;
} ListIter;

typedef struct MonitorWin {
    u8 pad0[0x30];
    u32 field30;
} MonitorWin;
typedef MonitorWin Arg801C838C;

typedef struct List {
    s32 size;
} List;

typedef struct UIListObj {
    u8 unk00[0x4E];
    s16 field4E;
    u8 unk50[4];
    s16 field54;
    u8 unk56[0x16];
    u32 count;
    u8 unk70[4];
    void *field74;
} UIListObj;


static inline s32 MsgBoxAddPad(s32 h, s32 pad) {
    return h + pad;
}

void fn_801E00EC(void *arg0, void *arg1);
extern u8 gFxChannels[];
extern u16 gScriptObjSlots[];
extern f32 lbl_8036B4A8;
extern f32 lbl_8027D528[3];
extern f32 lbl_8027D534[3];

typedef struct {
    u8 pad[0xC];
    u32 flags;
} Fn801C797CEnt;

struct Unit {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u16 unk22;
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u16 unk2A;
    u16 unk2C;
    u16 unk2E;
    u16 unk30;
    u16 unk32;
    u16 unk34;
    u16 unk36;
    u16 unk38;
    u16 unk3A;
    u16 unk3C;
    u16 unk3E;
    u16 unk40;
    u16 unk42;
    u16 unk44;
    u16 unk46;
    u16 unk48;
    u16 unk4A;
    u16 unk4C;
    u16 unk4E;
    u16 unk50;
    u16 unk52;
    u16 unk54;
    u16 unk56;
    u16 unk58;
    u16 unk5A;
    u16 unk5C;
    u16 unk5E;
    u16 unk60;
    u16 unk62;
    u16 unk64;
    u16 unk66;
};

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4C;
    u32 unk50;
    u32 unk54;
    u32 unk58;
    u32 unk5C;
    u32 unk60;
    u32 unk62;
} struct0;


/* Message box: up to 7 text lines, opened/closed through state (0x64/0x6E open, 0xC8/0xD2 close). */
typedef struct MsgBox {
    /* 0x000 */ s16 flags;
    /* 0x002 */ s16 state;
    /* 0x004 */ s16 type;
    /* 0x006 */ u8 unk6[4];
    /* 0x00A */ s16 width;
    /* 0x00C */ s16 height;
    /* 0x00E */ u8 unkE[0x10];
    /* 0x01E */ s16 timer;
    /* 0x020 */ char lines[7][0x41];
    /* 0x1E7 */ s8 numLines;
    /* 0x1E8 */ u8 unk1E8[2];
} MsgBox;

static inline s32 MsgBoxPadHeight(s32 h, s32 pad) {
    return h + pad;
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

#pragma opt_common_subs off

#pragma opt_common_subs reset

/* Advance the EXP bar fill: lerp displayed EXP, play a tick SE on odd frames, clear when finished. */

#pragma global_optimizer off
#pragma opt_common_subs off

#pragma opt_common_subs reset
#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset
#pragma global_optimizer off

#pragma global_optimizer reset

#pragma use_lmw_stmw on

/* Return 1 if every player/faction-5 unit has escaped (stateFlags 0x4000); else 0. */

#pragma use_lmw_stmw reset

/* Count enemy units whose job JID is Priest, Bishop, or Saint. */

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma opt_common_subs off

extern f32 lbl_8036B228;

#pragma opt_common_subs reset
#pragma opt_loop_invariants off

#pragma opt_loop_invariants reset

/* Apply chapter achievement gold to funds; open bonus tally UI when unlocked. */

#pragma global_optimizer off

#pragma use_lmw_stmw on

#pragma global_optimizer off

#pragma global_optimizer on

/* Focus the unit-manage list on gBattleState's unit, sync portrait/skill widgets, then Process_Goto. */

/* Focus the unit-manage list on gBattleState+0xAC's unit and sync portrait/skill widgets. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on
/* Handle unit select-list input: A picks the unit, X opens info, B hides/backs out. */

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on
#pragma opt_common_subs off

#pragma opt_common_subs reset
#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus reset

/* Layout the unit-manage panel: attach list, slide inventory into place, init help cursor, set caption. */

/* Handle unit-manage list input: sync inventory widgets on selection change; A confirms unit, Y/X open side panels, B backs out. */

#pragma cplusplus on

#pragma cplusplus on

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on
#pragma use_lmw_stmw on
/* Allocate the unit-panel caption and position child widgets, or exit if the panel is not ready. */

#pragma cplusplus off
#pragma use_lmw_stmw reset

#pragma cplusplus reset

#pragma optimization_level 3

#pragma optimization_level reset

#pragma cplusplus on

#pragma cplusplus reset

/* Build the unit-hire panel: caption widget plus list child bound to gUiContext. */

#pragma cplusplus on
/* Handle unit-hire panel input: A buys if affordable, X/Y open side panels, B backs out. */

#pragma cplusplus reset

#pragma cplusplus on
/* Attach cached unit-panel children, size them for the open layout, and set the caption text. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on
/* Destroy a unit panel: release ten refcounted children, run base dtor, optionally free. */

#pragma cplusplus reset

#pragma cplusplus reset

/* Validate skill assign on the unit panel; store error -1/-2/-3 at +4, return 2 on fail or 0. */

/* Menu item for skill assign: draw error popup from item+4, or enter state 0x82. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma opt_common_subs off
#pragma dont_inline on
#pragma global_optimizer off
#pragma use_lmw_stmw on

#pragma global_optimizer reset
#pragma dont_inline reset
#pragma opt_common_subs reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma optimization_level 3

#pragma optimization_level reset

#pragma cplusplus on

#pragma cplusplus off

#pragma cplusplus off

#pragma cplusplus on
extern "C" void fn_80142060(void *);
extern "C" int fn_801C18E4(void *);
extern "C" void fn_801D2C30(void *);

#pragma cplusplus reset

void Heap_Free(void *);
void *fn_801D2E40(void *, s16);

#pragma global_optimizer off

#pragma global_optimizer off

#pragma global_optimizer on

#pragma cplusplus on

#pragma cplusplus reset

#pragma opt_common_subs off

#pragma use_lmw_stmw on

#pragma opt_common_subs on

extern u8 lbl_8029824C[];

#pragma optimization_level 3

#pragma optimization_level reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma global_optimizer off

#pragma global_optimizer on

#pragma optimization_level 3

#pragma optimization_level reset

/* Copy LightFade source channels onto display lights, release extras, restore fog color. */

#pragma use_lmw_stmw on
/* Fade GX light and fog colors toward the linked unit's target colors over time. */

#pragma use_lmw_stmw reset

extern u32 lbl_8036C510;

extern u8 LightFade_script[];

#pragma use_lmw_stmw on

#pragma cplusplus on

#pragma cplusplus reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma global_optimizer off
/* Reload CameraWin anim list for a category and set the camChara side mode. */

#pragma global_optimizer reset
#pragma optimization_level reset
#pragma use_lmw_stmw reset

#pragma cplusplus off
/* Construct the ztool CameraWin window and wire its child controls. */

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma opt_strength_reduction off
#pragma cplusplus on

#pragma cplusplus reset
#pragma opt_strength_reduction reset
#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma opt_common_subs off

#pragma cplusplus reset

#pragma use_lmw_stmw on

#pragma opt_common_subs on
#pragma cplusplus off

#pragma cplusplus on

#pragma global_optimizer off
#pragma peephole off

#pragma peephole on
#pragma global_optimizer reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma global_optimizer off
#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus reset
#pragma use_lmw_stmw reset
#pragma global_optimizer reset

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma optimization_level 1

#pragma optimization_level reset
#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma cplusplus reset

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off

#pragma pop
#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

static inline u8 **GetTbl(s32 k) {
    extern u8 *lbl_802984C0[]; u8 **r = 0; switch (k) { case 0: r = lbl_802984C0; break; } return r; }
static inline s32 Width(s32 k) {
    s32 n = 0;
    u8 **p = GetTbl(k);
    while ((s32)**p != 10) { p++; n++; }
    return n;
}

#pragma push
#pragma global_optimizer on
#pragma use_lmw_stmw off
#pragma opt_common_subs on
#pragma peephole on

#pragma pop

#pragma push
#pragma global_optimizer on
#pragma use_lmw_stmw off
#pragma opt_common_subs on
#pragma peephole on

#pragma pop
#pragma push
#pragma optimization_level 4
#pragma global_optimizer on
static inline u8 Menu_InputBlocked(void) {
    extern u32 gUiInputFlags;
    u8 blocked = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) blocked = 1;
    return blocked;
}
static inline s32 Menu_CountEntries(void *self) {
    u32 *p = (u32 *)((u8 *)self + 0x3c);
    s32 i;
    for (i=0; *p; i++,p++) {}
    return i;
}

#pragma pop
#pragma push
#pragma cplusplus on
#pragma optimization_level 2
#pragma global_optimizer off
#pragma use_lmw_stmw on

#pragma pop
#pragma cplusplus off
extern struct efUnit* gEfUnitArray;
#pragma cplusplus on
extern "C" void fn_801583D0(s16, s16, s32, s32, u8, s32);
extern "C" void Prim2D_Begin(void);
extern "C" void Prim2D_AddZ(f32);
extern "C" void Prim2D_PrepareTex(void);
extern "C" s32 Text_MeasureHeight(s32, f32);
extern "C" s32 fn_8001059C(void *, s32, f32);
extern "C" void Ui_DrawIcon(void *, s32, s32, s32);
extern "C" void Prim2D_SetTex(s32, s32);
extern "C" void Prim2D_AddPrim(s32);
extern "C" void Prim2D_SetPos(f32, f32);
extern "C" void Prim2D_SetTextScale(u8, f32);
extern "C" void Prim2D_SetText(void *);
extern "C" void Prim2D_EndPrim(void);
#pragma cplusplus on

#pragma cplusplus off

#pragma opt_unroll off

#pragma opt_unroll reset

#pragma global_optimizer off

#pragma global_optimizer on

typedef struct { u8 pad[0xa]; s16 xa, xc, xe, x10, x12, x14, x16, x18; u8 pad2[0x78 - 0x1a]; s32 x78; } O_801CDFC8;
static inline s16 W(O_801CDFC8 *o) { return o->xe - o->xa; }
static inline s16 H(O_801CDFC8 *o) { return o->x10 - o->xc; }
static inline void Set(O_801CDFC8 *o, s16 a, s16 b, s16 c, s16 d) { o->x12 = a; o->x14 = b; o->x16 = c; o->x18 = d; }
static inline void Move(O_801CDFC8 *o, s16 x, s16 y) { o->xe = x + W(o); o->xa = x; o->x10 = y + H(o); o->xc = y; }

#pragma cplusplus on
extern "C" void String_Destroy(void *, s32);
extern "C" void Ui_DtorPanelBase(void *, s32);
#pragma opt_propagation off
#pragma cplusplus on

#pragma cplusplus off
#pragma opt_propagation on

#pragma cplusplus on
#pragma opt_common_subs off

#pragma opt_common_subs on
#pragma cplusplus off

#pragma push
#pragma cplusplus on
#pragma optimization_level 2

#pragma pop

#pragma cplusplus on

#pragma cplusplus reset

void Prim2D_Begin(void);
void Prim2D_AddZ(f32);
void Prim2D_PrepareTex(void);
void Ui_DrawLine(s16, s16, s16, s16, s32, u8 *);
extern f32 lbl_8036B510;
static inline void DrawHLine(s32 x1, s16 y, s32 x2, s32 z, u8 *c) { Ui_DrawLine(x1, y, x2, y, z, c); }
static inline void DrawVLine(s16 x, s32 y1, s32 y2, s32 z, u8 *c) { Ui_DrawLine(x, y1, x, y2, z, c); }
static inline void DrawCursorBox(u8 *obj, s32 x, s32 y) {
    s32 x2 = (s16)(x + 0x5C);
    s32 y2 = (s16)(y + 0x1D);
    u8 color[4];
    color[0] = 0x9C;
    color[1] = 0x2F;
    color[2] = 0x12;
    color[3] = 0xFF;
    DrawHLine(x, y - 1, x2, *(s32 *)(obj + 0x34), color);
    DrawHLine(x, y2, x2, *(s32 *)(obj + 0x34), color);
    DrawVLine(x - 1, y, y2, *(s32 *)(obj + 0x34), color);
    DrawVLine(x2, y, y2, *(s32 *)(obj + 0x34), color);
    DrawHLine(x, y, x2, *(s32 *)(obj + 0x34), color);
    DrawHLine(x, y2 - 1, x2, *(s32 *)(obj + 0x34), color);
    DrawVLine(x, y, y2, *(s32 *)(obj + 0x34), color);
    DrawVLine(x2 - 1, y, y2, *(s32 *)(obj + 0x34), color);
}
#pragma cplusplus on

#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma global_optimizer off

#pragma optimization_level reset
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma global_optimizer off
#pragma cplusplus on

#pragma cplusplus reset
#pragma global_optimizer reset

#pragma cplusplus reset

#pragma cplusplus reset

#pragma scheduling on

#pragma scheduling reset

#pragma opt_common_subs off

#pragma opt_common_subs on

#pragma optimization_level 4

#pragma optimization_level reset

#pragma global_optimizer off

#pragma global_optimizer on
typedef struct { u8 x28; void *x2c; } Slot;
typedef struct { u8 pad[8]; s32 x8; u8 pad2[0x1c]; Slot s[7]; } Obj_801CFA44;
static inline void Clr(Obj_801CFA44 *o, s32 v) {
    void Process_Unlink(void *);
    s32 i;
    o->x8 = v;
    for (i = 0; i < 7; i++, o = (Obj_801CFA44 *)((u8 *)o + 8)) {
        o->s[0].x28 = v;
        if (o->s[0].x2c) { Process_Unlink(o->s[0].x2c); o->s[0].x2c = (void *)v; }
    }
}

extern void *gPrim2D;

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer off

#pragma global_optimizer on

#pragma opt_strength_reduction on
#pragma global_optimizer on

#pragma opt_strength_reduction off

#pragma opt_strength_reduction on

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_strength_reduction off

#pragma pop

#pragma push
#pragma optimization_level 4
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma use_lmw_stmw on

#pragma pop

#pragma cplusplus on

#pragma cplusplus on

#pragma push
#pragma cplusplus on
#pragma optimization_level 4
#pragma opt_propagation off

#pragma pop
#pragma push
#pragma cplusplus on
#pragma optimization_level 4
#pragma opt_propagation off
#pragma global_optimizer off
#pragma use_lmw_stmw on

#pragma pop
#pragma cplusplus off

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma global_optimizer off

#pragma optimization_level reset
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma cplusplus off

#pragma push
#pragma optimization_level 3
#pragma opt_propagation off
#pragma cplusplus on
struct ListPoint {
    s16 x, y;

    ListPoint(s16 x, s16 y) : x(x), y(y) {}
};

struct ListRowLayout {
    u8 pad0[0x4E];
    s16 row;
    u8 pad50[4];
    s16 firstRow;
    s16 rowHeight;
    u8 pad58[8];
    ListPoint origin;

    s16 index() const { return row - firstRow; }
    s32 offset() const { return rowHeight * index(); }
};

static inline s16 ListRowY(const ListPoint &origin, s32 offset)
{
    offset += origin.y;
    return offset;
}

#pragma cplusplus reset
#pragma pop

#pragma push
#pragma optimization_level 3
#pragma cplusplus on

#pragma pop
#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma push
#pragma opt_lifetimes off

#pragma pop
#pragma cplusplus off
typedef struct { u8 pad[0xa]; s16 xa, xc, xe, x10, x12, x14, x16, x18; u8 pad2[0x5e - 0x1a]; s16 x5e, x60, x62; u8 pad3[0x86 - 0x64]; s16 x86, x88, x8a; } O_801D3A4C;
static inline s16 W_801D3A4C(O_801D3A4C *o) { return o->xe - o->xa; }
static inline s16 H_801D3A4C(O_801D3A4C *o) { return o->x10 - o->xc; }
static inline void Set_801D3A4C(O_801D3A4C *o, s16 a, s16 b, s16 c, s16 d) { o->x12 = a; o->x14 = b; o->x16 = c; o->x18 = d; }
static inline s16 W2(O_801D3A4C *o) { return o->x16 - o->x12; }
static inline s16 H2(O_801D3A4C *o) { return o->x18 - o->x14; }
static inline void Set3(s16 *p, s16 a, s16 b, s16 c) { p[0] = a; p[1] = b; p[2] = c; }

typedef struct { u8 pad[8]; void *x8; } E_801D3BD0;
typedef struct { u8 pad[8]; void *x8; void *xc; u8 pad2[0x4a]; u8 x5a; } W_801D3BD0;
static inline void Clr_801D3BD0(void *v) {
    extern u8 lbl_80299A78[];
    void FileCache_ReleaseSlot(void *);
    s32 i;
    for (i = 0; i < 0x28; i++) {
        if (((E_801D3BD0 *)lbl_80299A78)[i].x8) FileCache_ReleaseSlot(&((E_801D3BD0 *)lbl_80299A78)[i].x8);
        ((E_801D3BD0 *)lbl_80299A78)[i].x8 = v;
    }
}

#pragma opt_common_subs off

#pragma push
#pragma optimization_level 4

#pragma pop

#pragma push
#pragma optimization_level 4

#pragma pop

#pragma use_lmw_stmw on
#pragma opt_common_subs off
/* Clear a file-menu entry and build its label from gFileMenuMsgKeys[type] via Msg_Expand. */

#pragma opt_common_subs reset

#pragma push
#pragma optimization_level 3
#pragma opt_common_subs off

#pragma pop

#pragma push
#pragma opt_lifetimes off

#pragma pop

#pragma push
#pragma opt_lifetimes off
#pragma inline_depth(8)
#pragma inline_max_size(256)

#pragma pop
static inline u8 *A_801DBFF8(u8 *p) { if (p != 0 && p[0x60] == 2) return p; return 0; }

static inline void *fn_801DC10C_inline(void *arg0)
{
    extern u8 gSaveDataBase;
    extern void *fn_801E2324(void *, void *);
    u8 *result;

    result = (u8 *)fn_801E2324(&gSaveDataBase, arg0);
    if (result != 0 && result[0x60] == 2) {
        return result;
    }
    return 0;
}

#pragma global_optimizer off

#pragma global_optimizer on
/* Handle A/B confirm/cancel and left/right option select for a yes-no dialog. */

#pragma optimization_level 2

#pragma optimization_level reset

#pragma push
#pragma optimization_level 3
#pragma opt_common_subs off
#pragma opt_loop_invariants off

#pragma pop
/* Advance MsgBox open/close fade (timer 0..5) and relayout. */

extern void *lbl_801D3B14;
#pragma opt_propagation off

#pragma opt_propagation reset

#pragma scheduling on

#pragma push
#pragma optimization_level 4
#pragma global_optimizer off
#pragma opt_lifetimes off

#pragma pop

#pragma push
#pragma optimization_level 4
#pragma global_optimizer on
#pragma opt_loop_invariants off
#pragma opt_common_subs off

#pragma pop
static inline void Init_801DE274(void *arg) {
    s32 sprintf(char *, char *, ...);
    s32 FileCache_GetFlags(char *);
    void fn_8006EEFC(void *, void *);
    extern char gUiSeCues[];
    char buf[0x40];
    char *cues;
    s32 i;
    u8 *p = (u8 *)arg;

    cues = gUiSeCues;
    i = 0;
    do {
        sprintf(buf, cues + 0x661, *(s32 *)(p + 4));
        if (FileCache_GetFlags(buf) & 0x2000) {
            fn_8006EEFC(p + 8, buf);
        }
        i += 1;
        p += 0xC;
    } while (i < 0x28);
}

#pragma opt_loop_invariants reset

#pragma use_lmw_stmw reset

#pragma optimization_level 3

#pragma cplusplus on
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off

#pragma pop
#pragma cplusplus off
#pragma cplusplus on

#pragma cplusplus on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus reset

#pragma cplusplus reset

extern u8 lbl_80299F4C[];

extern u64 OSGetTime();
extern u16 fn_802072A0(u32, s32, s32, s32);
extern u8 fn_80209A0C();
extern s32 fn_80211690(s32, s32);
extern void fn_8021D614(u32, s32*, u32);

void fn_801DF960(void *arg0)
{
    extern void *gSaveDataBase;
    void Process_Goto(void *, s32);

    u8 *data;
    s32 i;
    u32 offset;
    u32 size;
    u32 limit;
    u32 mask;
    u8 valid;
    u8 found;
    u8 *base;
    u32 offset2;
    u8 *slot;

    base = (u8 *)gSaveDataBase;
    i = 0;
    offset = 0x2000;
    for (; i < 6; i++) {
        data = base + offset;
        if (*(u32 *)(data + 0x70) != 0x53595346U) {
            valid = 0;
        } else if (*(u32 *)(data + 0x74) != 0x20050201U) {
            valid = 0;
        } else {
            valid = 1;
        }
        if (valid != 0) {
            size = *(u32 *)(data + 0x48);
            limit = 0x100000;
            mask = size > limit ? 0 : size;
            if (mask <= limit) {
                found = 1;
                goto check;
            }
        }
        offset += 0x4000;
    }

    offset2 = 0x1A000;
    for (i = 0; i < 2; i++) {
        slot = base + offset2;
        if (*(u32 *)(slot + 0x70) != 0x53595346U) {
            valid = 0;
        } else if (*(u32 *)(slot + 0x74) != 0x20050201U) {
            valid = 0;
        } else {
            valid = 1;
        }
        if (valid != 0) {
            size = *(u32 *)(slot + 0x48);
            limit = 0x100000;
            mask = size > limit ? 0 : size;
            if (mask <= limit) {
                found = 1;
                goto check;
            }
        }
        offset2 += 0x6000;
    }

    found = 0;
check:
    if (found != 0) return;
    Process_Goto(arg0, 2);
}

void fn_801DFB4C(void *arg0) {
    extern void *gSaveDataBase;
    extern u8 gSaveStrings[];

    void DebugPrint(const char *, ...);
    void fn_800C4588(void *);
    void *fn_800C4604(s32, s32, void *, s32);
    void fn_800EA540(void *, void *);

    void *ptr;
    void *arg;

    arg = arg0;

    if (gSaveDataBase != (int)NULL) {
        DebugPrint(
            (char *)(gSaveStrings + 0x122)
        );

        fn_800C4588(gSaveDataBase);
        gSaveDataBase = NULL;
    }

    DebugPrint(
        (char *)(gSaveStrings + 0x137)
    );

    ptr = fn_800C4604(
        0,
        -0x26000,
        gSaveStrings + 0x14E,
        0
    );

    gSaveDataBase = ptr;

    fn_800EA540(ptr, arg);
}

#pragma use_lmw_stmw on
#pragma optimization_level 2
/* Clear first corrupt chapter/suspend save slot (bad CRC) and request a card rewrite; return 1 if cleared. */
s32 Save_ClearCorruptSlots(s32 proc) {
    extern void *gSaveDataBase;
    extern u8 gSaveStrings[];
    u8 Card_CheckError(void);
    void *fn_800C4638(s32, void *, s32);
    void fn_800C4588(void *);
    void Crc32_InitTable(void);
    u32 Crc32_Calc(void *, void *, s32);
    void Card_RequestWrite(void *, s32, s32, s32, s32);
    void *memset(void *, s32, s32);

    void *crcTable;
    u32 checksum;
    s32 self;
    s32 i;
    u8 *slot;
    s32 offset;
    u8 headerOk;
    u8 checksumOk;

    self = proc;
    if (Card_CheckError() != 0) {
        return 0;
    }

    i = 0;
    offset = 0x2000;
    do {
        slot = (u8 *)gSaveDataBase + offset;
        if (*(u32 *)(slot + 0x40) != SAVE_SLOT_MAGIC) {
            headerOk = 0;
        } else if (*(u32 *)(slot + 0x44) != SAVE_VER_20050201) {
            headerOk = 0;
        } else {
            headerOk = 1;
        }
        if (headerOk != 0) {
            if (*(u32 *)(slot + 0x50) == SAVE_CHECKSUM_UNINIT) {
                checksumOk = 1;
            } else if (*(u8 *)(slot + 0x60) == 1) {
                checksumOk = 1;
            } else {
                crcTable = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
                Crc32_InitTable();
                checksum = Crc32_Calc(crcTable, slot + SAVE_SLOT_PAYLOAD_OFF, *(s32 *)(slot + 0x4C) - SAVE_SLOT_PAYLOAD_OFF);
                fn_800C4588(crcTable);
                if (*(u32 *)(slot + 0x50) != checksum) {
                    checksumOk = 0;
                } else {
                    checksumOk = 1;
                }
            }
            if (checksumOk == 0) {
                memset(slot, 0, SAVE_SLOT_BLOCK_SIZE);
                Card_RequestWrite(slot, SAVE_SLOT_BLOCK_SIZE, (s32)(slot - (u8 *)gSaveDataBase), -1, self);
                return 1;
            }
        }
        i += 1;
        offset += 0x4000;
    } while (i < 6);

    i = 0;
    offset = 0x1A000;
    do {
        slot = (u8 *)gSaveDataBase + offset;
        if (*(u32 *)(slot + 0x40) != SAVE_SLOT_MAGIC) {
            headerOk = 0;
        } else if (*(u32 *)(slot + 0x44) != SAVE_VER_20050201) {
            headerOk = 0;
        } else {
            headerOk = 1;
        }
        if (headerOk != 0) {
            if (*(u32 *)(slot + 0x50) == SAVE_CHECKSUM_UNINIT) {
                checksumOk = 1;
            } else if (*(u8 *)(slot + 0x60) == 1) {
                checksumOk = 1;
            } else {
                crcTable = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
                Crc32_InitTable();
                checksum = Crc32_Calc(crcTable, slot + SAVE_SLOT_PAYLOAD_OFF, *(s32 *)(slot + 0x4C) - SAVE_SLOT_PAYLOAD_OFF);
                fn_800C4588(crcTable);
                if (*(u32 *)(slot + 0x50) != checksum) {
                    checksumOk = 0;
                } else {
                    checksumOk = 1;
                }
            }
            if (checksumOk == 0) {
                memset(slot, 0, SAVE_SLOT_BLOCK_SIZE);
                Card_RequestWrite(slot, SAVE_SLOT_BLOCK_SIZE, (s32)(slot - (u8 *)gSaveDataBase), -1, self);
                return 1;
            }
        }
        i += 1;
        offset += 0x6000;
    } while (i < 2);

    return 0;
}
  #pragma optimization_level reset
  
  static inline u32 save_slot_size(u8 *slot) {
    u32 size = *(u32 *)(slot + 0x48);
    if (size > 0x100000U) {
        return 0;
    }
    return size;
}

static inline u32 save_slot_size_lim(u8 *slot, u32 limit) {
    u32 size = *(u32 *)(slot + 0x48);
    return (size <= limit) ? size : 0;
}
  
#pragma push
void fn_801DFE60(u8 **arg0, s32 arg1) {
    void fn_800062CC(void *, void *, s32);
    void fn_801E3CA8(void *);
    void Card_RequestWrite(void *, s32, s32, s32, s32);
    extern void *gSaveDataBase;

    s32 i;
    u32 minSize;
    u8 *slot;
    s32 off;
    u32 size;
    u8 *best;
    s32 self;
    u8 hdrOk;
    u8 *found;
    u8 *src;
    s32 diff;

    minSize = (u32)-1;
    best = NULL;
    self = arg1;
    i = 0;
    off = 0x2000;

    for (; i < 6; i++) {
        slot = *arg0 + off;
        if (*(u32 *)(slot + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(slot + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
            size = *(u32 *)(slot + 0x48);
            if (minSize > (size > 0x100000U ? 0 : size)) {
                best = slot;
                minSize = size > 0x100000U ? 0 : size;
            }
        }
        off += 0x4000;
    }

    i = 0;
    off = 0x2000;
    for (; i < 6; i++) {
        found = *arg0 + off;
        if (*(u32 *)(found + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(found + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk != 0) {
            goto found_slot;
        }
        off += 0x4000;
    }

    found = NULL;

found_slot:
    src = found;
    if (src == NULL) {
        src = *arg0 + 0x2000;
        if (src == best) {
            src = *arg0 + 0x6000;
        }
    }

    fn_800062CC(best, src, *(s32 *)(src + 0x4C));
    fn_801E3CA8(best);
    diff = (s32)best - (s32)gSaveDataBase;
    Card_RequestWrite(best, *(s32 *)(best + 0x4C), diff, diff, self);
}
#pragma pop
  extern u8 lbl_80299F1C[];
void fn_801E00EC(void *arg0, void *arg1) { void Process_CreateChild(void *); extern u8 lbl_80299F1C[]; (void)arg0; (void)arg1; Process_CreateChild(lbl_80299F1C); }

void fn_801E0114(s32 arg0) {
    u8 Card_CheckError(void);
    void fn_801E0154(void *, s32);
    extern u32 gSaveDataBase;

    if (Card_CheckError() != 0) {
        return;
    }

    fn_801E0154(&gSaveDataBase, arg0);
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
static inline u8 *Save_FindWritableHeaderIn(u8 **arg0) {
    void fn_800062CC(void *, void *, s32);
    void fn_801E3CA8(void *);
    void Card_RequestWrite(void *, s32, s32, s32, s32);
    void *fn_800C4638(s32, void *, s32);
    void fn_800C4588(void *);
    void Crc32_InitTable(void);
    u32 Crc32_Calc(void *, void *, s32);
    extern void *gSaveDataBase;
    extern u8 gSaveStrings[];

u8 *base,*dst; s32 i,off; u8 hdrOk,chkOk; void *buf; u32 sum;

        for (i = 0, off = 0x20000 - 0x6000; i < 2; i++) {
    dst = *arg0 + off;
    if (*(u32 *)(dst + 0x40) != 0x4645384AU) {
        hdrOk = 0;
    } else if (*(u32 *)(dst + 0x44) != 0x20050201U) {
        hdrOk = 0;
    } else {
        hdrOk = 1;
    }
    if (hdrOk == 0) {
        goto got;
    }
    if (*(u32 *)(dst + 0x50) == 0x12345678U) {
        chkOk = 1;
    } else if (*(u8 *)(dst + 0x60) == 1) {
        chkOk = 1;
    } else {
        buf = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
        Crc32_InitTable();
        sum = Crc32_Calc(buf, dst + 0x70, *(s32 *)(dst + 0x4C) - 0x70);
        fn_800C4588(buf);
        if (*(u32 *)(dst + 0x50) != sum) {
            chkOk = 0;
        } else {
            chkOk = 1;
        }
    }
    if (chkOk == 0) {
        goto got;
    }
    off += 0x6000;
    }
    base = *arg0;
    dst = base + 0x1A000;
    if (save_slot_size(dst) < save_slot_size(base + 0x20000)) goto got;
    dst = base + 0x20000;
got:
    return dst;
}
static inline u8 *Save_FindLinkedSlot(u8 *base, s32 id)
{
s32 off;
u8 *slot;
s32 i;
u8 valid;
i=0; off=0x2000;
for(;i<6;i++) {
slot=base+off;
if(*(u32 *)(slot+0x40)!=0x4645384AU) valid=0;
else if(*(u32 *)(slot+0x44)!=0x20050201U) valid=0;
else valid=1;
if(valid && id==slot[0x62]) return slot;
off+=0x4000;
}
return 0;
}
static inline u8 *Save_FindSlotById(s32 id, u8 *base)
{
    u8 *slot;
    s32 off;
    s32 i;
    u8 valid;
    i=0; off=0x2000;
    for(;i<6;i++) {
        slot=base+off;
        if(*(u32 *)(slot+0x40)!=0x4645384AU) valid=0;
        else if(*(u32 *)(slot+0x44)!=0x20050201U) valid=0;
        else valid=1;
        if(valid && id==slot[0x62]) return slot;
        off+=0x4000;
    }
    return 0;
}
static inline u8 *Save_FindLinkedHeader(u8 **save)
{
u8 *base;
s32 off;
u8 *slot;
s32 i;
u8 valid;
i=0; off=0x1a000;
for(;i<2;i++) {
base=*save;
slot=base+off;
if(*(u32 *)(slot+0x40)!=0x4645384AU) valid=0;
else if(*(u32 *)(slot+0x44)!=0x20050201U) valid=0;
else valid=1;
if(valid && Save_FindLinkedSlot(base,slot[0x63])) return slot;
off+=0x6000;
}
return 0;
}
#pragma push
#pragma optimization_level 4
#pragma opt_loop_invariants off
void fn_801E0154(u8 **arg0, s32 arg1) {
    void fn_800062CC(void *, void *, s32);
    void fn_801E3CA8(void *);
    void Card_RequestWrite(void *, s32, s32, s32, s32);
    void *fn_800C4638(s32, void *, s32);
    void fn_800C4588(void *);
    void Crc32_InitTable(void);
    u32 Crc32_Calc(void *, void *, s32);
    extern void *gSaveDataBase;
    extern u8 gSaveStrings[];

    s32 i;
    u8 *src;
    s32 off;
    u8 *dst;
    s32 self;
    u8 **save;
    u32 sum;
    void *buf;
    u8 *base;
    u8 hdrOk;
    u8 chkOk;

    self = arg1;
    save = arg0;
    src = Save_FindLinkedHeader(save);
    i = 0;
    off = 0x20000 - 0x6000;
    for (; i < 2; i++, off += 0x6000) {
        dst = *save + off;
        if (*(u32 *)(dst + 0x40) != 0x4645384AU) hdrOk = 0;
        else if (*(u32 *)(dst + 0x44) != 0x20050201U) hdrOk = 0;
        else hdrOk = 1;
        if (hdrOk == 0) {
            goto got_dst;
        }
        if (*(u32 *)(dst + 0x50) == 0x12345678U) {
            chkOk = 1;
        } else if (dst[0x60] == 1) {
            chkOk = 1;
        } else {
            buf = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
            Crc32_InitTable();
            sum = Crc32_Calc(buf, dst + 0x70, *(s32 *)(dst + 0x4C) - 0x70);
            fn_800C4588(buf);
            if (*(u32 *)(dst + 0x50) != sum) {
                chkOk = 0;
            } else {
                chkOk = 1;
            }
        }
        if (chkOk != 0) {
            continue;
        }
        goto got_dst;
    }
    base = *save;
    dst = base + 0x1A000;
    if (save_slot_size(dst) < save_slot_size(base + 0x20000)) goto got_dst;
    dst = base + 0x20000;
got_dst:
    fn_800062CC(dst, src, *(s32 *)(src + 0x4C));
    fn_801E3CA8(dst);
    dst[0x60] = 1;
    Card_RequestWrite(dst, 0x2000, (s32)dst - (s32)gSaveDataBase, -1, self);
}
#pragma push
#pragma optimization_level 3
#pragma opt_common_subs off
void fn_801E047C(u8 **arg0, s32 arg1)
{
  void fn_80006298(void *, s32, s32);
  void fn_800167E4(void *);
  void fn_80016A3C(void *);
  void fn_80048C5C(void *);
  void fn_800C2980(void *, void *);
  void fn_800C33C0(void *, void *);
  void fn_800C4588(void *);
  void *fn_800C4638(s32, void *, s32);
  int new_var;
  void fn_800E9B80(void *, s32, s32, s32, s32);
  u32 fn_800EC0A4(void *, void *, s32);
  void fn_800EC1F8(void);
  void fn_8010FBA8(void *, void *);
  void fn_8014C39C(void *, void *);
  void fn_8017A38C(void *, void *);
  void fn_801E3CA8(void *);
  extern u8 gSaveStrings[];
  extern u8 gStreamBaseVtbl[];
  extern u8 gMemStreamVtbl[];
  extern u8 gConvoy[];
  extern u8 gIconSlots[];
  extern u8 gMapObjEventList[];
  extern u8 gBattleState[];
  extern u8 gSystemSave[];
  extern void *gSaveDataBase;
  s32 i;
  s32 off;
  u8 *slot;
  u8 hdrOk;
  u8 chkOk;
  void *buf;
  u8 *base;
  u32 sum;
  u8 *picked;
  struct 
  {
    void *start;
    void *cur;
    u32 size;
    u8 owned;
    u8 pad[3];
    void *vtbl;
  } w;
  u8 *p;
  i = 0;
  off = 0x1A000;
  do
  {
    slot = (*arg0) + off;
    if (((u32) ((*((u32 *) (slot + 0x40))) + 0xB9BB0000)) != 0x384AU)
    {
      hdrOk = 0;
    }
    else
      if (((u32) ((*((u32 *) (slot + 0x44))) + 0xDFFB0000)) != 0x201U)
    {
      hdrOk = 0;
    }
    else
    {
      hdrOk = 1;
    }
    if (hdrOk == 0)
    {
      goto do_init;
    }
    if ((*((u32 *) (slot + 0x50))) == 0x12345678U)
    {
      chkOk = 1;
    }
    else
      if (slot[0x60] == 1)
    {
      chkOk = 1;
    }
    else
    {
      buf = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
      fn_800EC1F8();
      sum = fn_800EC0A4(buf, slot + 0x70, (*((s32 *) (slot + 0x4C))) - 0x70);
      fn_800C4588(buf);
      if ((*((u32 *) (slot + 0x50))) != sum)
      {
        chkOk = 0;
      }
      else
      {
        chkOk = 1;
      }
    }
    if (chkOk == 0)
    {
      goto do_init;
    }
    goto incr;
    incr:
    i += 1;
    off += 0x6000;
  }
  while (i < 2);
  base = *arg0;
  slot = base + 0x1A000;
  if (save_slot_size(base + 0x1A000) >= save_slot_size(base + 0x20000))
  {
    goto pick;
  }
  goto do_init;
  pick:
  slot = base + 0x20000;
  do_init:
  fn_80006298(slot, 0, 0x6000);

  *((s32 *) (slot + 0x4C)) = 0x6000;
  *((u32 *) (slot + 0x40)) = 0x4645384AU;
  *((u32 *) (slot + 0x44)) = 0x20050201U;
  *((u32 *) (slot + 0x48)) = 0;
  *((u32 *) (slot + 0x5C)) = 0;
  *((u32 *) (slot + 0x58)) = 0;
  p = slot + 0xB8;
  slot[0x60] = 3;
  slot[0x61] = 0;
  slot[0x62] = 0;
  slot[0x63] = 0;
  new_var = 0x64;
  slot[new_var] = 0;
  slot[0x65] = 0;
  slot[0x66] = 0;
  slot[0x63] = gSystemSave[0x47];
  *((u64 *) (slot + 0x58)) = *((u64 *) (gBattleState + 0x58));
  slot[0x61] = gBattleState[0x51C];
  slot[new_var] = gBattleState[0x10];
  slot[0x65] = 8;
  slot[0x66] = gBattleState[0xA6];
  w.vtbl = gStreamBaseVtbl;
  w.cur = NULL;
  w.start = NULL;
  w.size = 0;
  new_var = 0x4C;
  w.owned = 0;
  w.vtbl = gMemStreamVtbl;
  w.owned = 0;
  w.start = p;
  w.cur = p;
  w.size = 0x100000;
  fn_8017A38C(&w, gSaveStrings + 0x14F);
  fn_8014C39C(gBattleState, &w);
  fn_8017A38C(&w, gSaveStrings + 0x154);
  fn_80048C5C(&w);
  fn_8017A38C(&w, gSaveStrings + 0x159);
  if (gBattleState[0x55] != 0)
  {
    fn_800167E4(&w);
  }
  else
  {
    fn_80016A3C(&w);
  }
  fn_8017A38C(&w, gSaveStrings + 0x15E);
  fn_800C33C0(gConvoy, &w);
  fn_8017A38C(&w, gSaveStrings + 0x163);
  fn_800C2980(gIconSlots, &w);
  fn_8017A38C(&w, gSaveStrings + 0x168);
  fn_8010FBA8(gMapObjEventList, &w);
  w.vtbl = gMemStreamVtbl;
  w.vtbl = gStreamBaseVtbl;
  if (w.owned != 0)
  {
    fn_800C4588(w.start);
    w.start = NULL;
    w.owned = 0;
  }
  fn_801E3CA8(slot);
  arg0[1] = slot;
  picked = slot;
  fn_800E9B80(picked, *((s32 *) (picked + new_var)), ((s32) picked) - ((s32) gSaveDataBase), ((s32) picked) - ((s32) gSaveDataBase), arg1);
}
#pragma pop

#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

static inline u8 *Save_FindLinkedSlotIn(u8 **save, s32 id) {
    s32 off; u8 *slot; s32 i; u8 valid;
    i=0; off=0x2000;
    for (;i<6;i++) {
        slot=*save+off;
        if (*(u32 *)(slot+0x40)!=0x4645384AU) valid=0;
        else if (*(u32 *)(slot+0x44)!=0x20050201U) valid=0;
        else valid=1;
        if (valid && id==slot[0x62]) return slot;
        off+=0x4000;
    }
    return 0;
}
static inline u8 *Save_FindUnusedSlotIn(u8 **save) {
    u8 *best; s32 off; u8 *slot; u32 minSize; s32 i; u8 valid;
    best=0; i=0; minSize=-1; off=0x2000;
    for (;i<6;i++) {
        slot=*save+off;
        if (*(u32 *)(slot+0x40)!=0x4645384AU) valid=0;
        else if (*(u32 *)(slot+0x44)!=0x20050201U) valid=0;
        else valid=1;
        if (!valid && minSize>save_slot_size(slot)) {
            best=slot; minSize=save_slot_size(slot);
        }
        off+=0x4000;
    }
    return best;
}

#pragma global_optimizer off
void fn_801E080C(void *arg0) {
extern u8 gSystemSave[];
u8 **save=(u8 **)arg0;
save[1]=Save_FindLinkedHeader(save);
gSystemSave[0x47]=save[1][0x63];
}
#pragma push
#pragma optimization_level 4
#pragma global_optimizer off
#pragma cplusplus off
void *fn_801E09B4(u8 **save) {
u8 *slot;
s32 off;
u8 *base;
s32 i;
u8 valid;
i=0; off=0x1a000;
for(;i<2;i++) {
base=*save;
slot=base+off;
if(*(u32 *)(slot+0x40)!=0x4645384AU) valid=0;
else if(*(u32 *)(slot+0x44)!=0x20050201U) valid=0;
else valid=1;
if(valid && Save_FindLinkedSlot(base,slot[0x63])) return slot;
off+=0x6000;
}
return 0;
}
#pragma pop
void fn_801E0B48(s32 unused, s32 arg1, s32 arg2, s32 arg3) {
    void *Process_CreateChild(void *, s32);
    extern u8 lbl_80299ED8[];
    void *obj;

    obj = Process_CreateChild(lbl_80299ED8, arg3);
    *(s32 *)((u8 *)obj + 0x60) = arg1;
    *(s32 *)((u8 *)obj + 0x64) = arg2;
}

void fn_801E0B94(void *arg0) {
    s32 fn_80211690();
    u16 fn_802072A0();
    u64 time;
    s8 lang;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x54);
    u32 add;
    memset(p, 0, 0x2000);
    *(u32 *)(p+0x70)=0x53595346;
    *(u32 *)(p+0x74)=0x20050201;
    time=0;
    fn_8021D614(0,(s32 *)&time,0x20050201);
    time += OSGetTime();
    add=fn_80211690()*123;
    time += add;
    *(u64 *)(p+0x78)=time;
    *(u16 *)(p+0x80)=0;
    p[0xB0]=0; p[0xB1]=0; p[0xB2]=0x40; p[0xB3]=0;
    if (fn_802072A0()==1) lang=0;
    else switch((s32)fn_80209A0C()) {
    case 0: lang=1; break; case 1: lang=2; break; case 2: lang=3; break;
    case 3: lang=4; break; case 4: lang=5; break; case 5: lang=1; break;
    }
    p[0xB4]=lang; p[0xB7]=0;
    memset(p+0x82,0,0x1E); memset(p+0xB5,0,2);
    *(u32 *)(p+0xAC)=0; *(u32 *)(p+0xA8)=0; *(u32 *)(p+0xA4)=0; *(u32 *)(p+0xA0)=0;
    *(u32 *)(p+0x40)=0; *(u32 *)(p+0x48)=1;
}

void fn_801E0D30(void *arg0) {
    u8 Card_CheckError(void);
    void fn_801E0D78(void *, void *, s32, s32);
    extern u16 gSaveDataBase;

    if (Card_CheckError() != 0) {
        return;
    }

    fn_801E0D78(&gSaveDataBase, arg0, *(s32 *) ((u8 *) arg0 + 0x60), *(s32 *) ((u8 *) arg0 + 0x64));
}

#pragma push
#pragma optimization_level 4
void fn_801E0D78(u8 **arg0, void *arg1, s32 arg2, s32 arg3) {
    void fn_800062CC(void *, void *, s32);
    void fn_801E3CA8(void *);
    void Card_RequestWrite(void *, s32, s32, s32, void *);
    extern void *gSaveDataBase;
    s32 val;
    void *self;
    u8 *found;
    u8 *best;
    s32 diff;
    val=arg3;
    self=arg1;
    found=Save_FindLinkedSlotIn(arg0,arg2);
    best=Save_FindUnusedSlotIn(arg0);
    fn_800062CC(best,found,*(s32 *)(found+0x4C));
    best[0x62]=(u8)val;
    fn_801E3CA8(best);
    diff=(s32)best-(s32)gSaveDataBase;
    Card_RequestWrite(best,*(s32 *)(best+0x4C),diff,diff,self);
    *(void **)((u8 *)self+0x54)=best;
}
#pragma push
#pragma optimization_level 4
void fn_801E1018(u8 **arg0, s32 arg1, void *arg2) {
    void *Process_CreateChild(void *, void *);
    extern u8 lbl_80299E9C[];
    void *proc;

    Save_FindLinkedSlotIn(arg0, arg1);
    proc = Process_CreateChild(lbl_80299E9C, arg2);
    *((s32 *)(((u8 *)proc) + 0x60)) = arg1;
}
#pragma pop
void fn_801E1168(void *arg0) {
    u8 Card_CheckError(void);
    void fn_801E11AC(void *, void *, s32);
    extern u16 gSaveDataBase[4];

    if (Card_CheckError() != 0) {
        return;
    }

    fn_801E11AC(gSaveDataBase, arg0, *(s32 *) ((u8 *) arg0 + 0x60));
}

#pragma opt_strength_reduction off
