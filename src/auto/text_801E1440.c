/* Functions from 0x801B3258 to 0x801E4380, found by decomp-toolkit. */
#include "common.h"
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

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma opt_propagation on
#pragma global_optimizer on

#pragma global_optimizer reset
#pragma opt_propagation reset

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma global_optimizer off

#pragma optimization_level reset
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma cplusplus off
extern struct efUnit* gEfUnitArray;

#pragma opt_unroll off

#pragma opt_unroll reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma cplusplus on
#pragma opt_common_subs off

#pragma opt_common_subs on
#pragma cplusplus off

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on

#pragma global_optimizer off
#pragma cplusplus on

#pragma cplusplus reset
#pragma global_optimizer reset

#pragma cplusplus reset

#pragma cplusplus reset

#pragma opt_common_subs off

#pragma opt_common_subs on

#pragma global_optimizer off

#pragma global_optimizer on

extern void *gPrim2D;
#pragma global_optimizer off

#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer off

#pragma global_optimizer on

#pragma opt_strength_reduction on
#pragma global_optimizer on

#pragma opt_strength_reduction off

#pragma opt_strength_reduction on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus on

#pragma global_optimizer off
#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma cplusplus reset
#pragma use_lmw_stmw reset
#pragma global_optimizer reset

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

#pragma optimization_level 3

#pragma optimization_level reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma opt_common_subs off
#pragma dont_inline on
#pragma global_optimizer on

#pragma global_optimizer reset
#pragma dont_inline reset
#pragma opt_common_subs reset
#pragma cplusplus reset

#pragma opt_common_subs off

#pragma opt_common_subs reset

#pragma optimization_level 3

#pragma optimization_level reset

#pragma use_lmw_stmw on
#pragma opt_common_subs off
/* Clear a file-menu entry and build its label from gFileMenuMsgKeys[type] via Msg_Expand. */

#pragma opt_common_subs reset

#pragma global_optimizer off

#pragma global_optimizer on
/* Handle A/B confirm/cancel and left/right option select for a yes-no dialog. */

/* Advance MsgBox open/close fade (timer 0..5) and relayout. */

extern void *lbl_801D3B14;
#pragma opt_propagation off

#pragma opt_propagation reset

#pragma scheduling on

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma cplusplus on
#pragma global_optimizer off
#pragma opt_loop_invariants off

#pragma opt_loop_invariants reset
#pragma global_optimizer reset
#pragma cplusplus reset

#pragma opt_loop_invariants reset

#pragma use_lmw_stmw reset

#pragma optimization_level 3

#pragma optimization_level reset

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

#pragma use_lmw_stmw on
#pragma optimization_level 2
/* Clear first corrupt chapter/suspend save slot (bad CRC) and request a card rewrite; return 1 if cleared. */

  #pragma optimization_level reset
  
  static inline u32 save_slot_size(u8 *slot) {
      u32 size = *(u32 *)(slot + 0x48);
      return size & ~-(size > 0x100000U);
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

static inline u32 save_slot_size_lim(u8 *slot, u32 limit) {
    u32 size = *(u32 *)(slot + 0x48);
    return (size <= limit) ? size : 0;
}
  
#pragma opt_strength_reduction off

  extern u8 lbl_80299F1C[];

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

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
#pragma global_optimizer off

#pragma cplusplus on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus reset

#pragma opt_strength_reduction off

#pragma global_optimizer off
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma global_optimizer on

#pragma opt_strength_reduction off

void fn_801E1440(s32 arg0, s32 arg1, s32 arg2) {
    void fn_8014D698(void *, s32, u8, u8, s32);
    extern u8 gBattleState[];
    extern s32 gSystemSave[];

    s32 temp_r2 = arg2;
    u8 temp_r3 = arg1;
    
    fn_8014D698(gBattleState, 0, temp_r3, temp_r2, 1);
    gSystemSave[0] = -1;
    gSystemSave[1] = -1;
    ((u8 *) gSystemSave)[0x44] = 1;
}

void fn_801E1498(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    extern u8 lbl_80299E60[];
    extern void *Process_CreateChild(void *, s32);

    u8 *entry;

    entry = (u8 *)Process_CreateChild(lbl_80299E60, arg4);

    *(s32 *)(entry + 0x60) = arg1;
    *(s32 *)(entry + 0x64) = arg2;
    *(s32 *)(entry + 0x68) = arg3;
}

void fn_801E1540(u8 **arg0, void *arg1, s32 arg2, u8 arg3, u8 arg4);

void fn_801E14F4(void *arg0) {
    u8 Card_CheckError(void);
    void fn_801E1540(void *, void *, s32, s32, s32);
    extern u16 gSaveDataBase;

    if (Card_CheckError() != 0) {
        return;
    }

    fn_801E1540(&gSaveDataBase, arg0, *(s32 *)((u8 *)arg0 + 0x60), *(s32 *)((u8 *)arg0 + 0x64), *(s32 *)((u8 *)arg0 + 0x68));
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
void fn_801E1540(u8 **arg0, void *arg1, s32 arg2, u8 arg3, u8 arg4) {
    void fn_80006298(void *, s32, s32);
    void fn_800167E4(void *);
    void Unit_WriteAll(void *);
    void fn_80048C5C(void *);
    void Icon_WriteSlots(void *, void *);
    void fn_800C33C0(void *, void *);
    void fn_800C4588(void *);
    void Card_RequestWrite(void *, s32, s32, s32, void *);
    void fn_8010FBA8(void *, void *);
    void BattleState_Write(void *, void *);
    void fn_8014D698(void *, u8, u8, u8, u8);
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

    u8 *best;
    u8 hist[0x28];
    struct {
        void *start;
        void *cur;
        u32 size;
        u8 owned;
        u8 pad[3];
        void *vtbl;
    } w;
    u32 minSize;
    s32 off;
    s32 i;
    void *other;
    s32 ctr;
    u8 *slot;
    u8 hdrOk;
    u32 clamped;
    u8 *rec;
    s32 n;
    u8 *found;
    u8 b;
    u8 freeId;
    u8 *hp;
    u8 idx;
    u8 *p;
    s32 diff;
    u8 *base;

    other = arg1;
    best = NULL;
    i = 0;
    gSystemSave[0x47] = (u8)arg2;
    minSize = (u32)-1;
    off = 0x2000;

    for (ctr = 3; ctr != 0; ctr--) {
        base = *arg0;
        slot = base + off;
        if ((u32)(*(u32 *)(slot + 0x40) + 0xB9BB0000) != 0x384AU) {
            hdrOk = 0;
        } else if ((u32)(*(u32 *)(slot + 0x44) + 0xDFFB0000) != 0x201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
            clamped = save_slot_size(slot);
            if (minSize > clamped) {
                best = slot;
                minSize = save_slot_size(slot);
            }
        }
        off += 0x4000;
        base = *arg0;
        slot = base + off;
        if ((u32)(*(u32 *)(slot + 0x40) + 0xB9BB0000) != 0x384AU) {
            hdrOk = 0;
        } else if ((u32)(*(u32 *)(slot + 0x44) + 0xDFFB0000) != 0x201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
            clamped = save_slot_size(slot);
            if (minSize > clamped) {
                best = slot;
                minSize = save_slot_size(slot);
            }
        }
        off += 0x4000;
        i += 1;
    }

    fn_80006298(best, 0, 0x4000);
    *(s32 *)(best + 0x4C) = 0x4000;
    *(u32 *)(best + 0x40) = 0x4645384AU;
    *(u32 *)(best + 0x44) = 0x20050201U;
    rec = gSystemSave;
    *(u32 *)(best + 0x48) = 0;
    *(u32 *)(best + 0x5C) = 0;
    *(u32 *)(best + 0x58) = 0;
    best[0x60] = 2;
    best[0x61] = 0;
    best[0x62] = (u8)arg2;
    best[0x63] = 0;
    best[0x64] = 0;
    best[0x65] = 0;
    best[0x66] = 0;
    *(u32 *)(best + 0x5C) = 0;
    *(u32 *)(best + 0x58) = 0;

    hist[0x00] = 0; hist[0x01] = 0; hist[0x02] = 0; hist[0x03] = 0;
    hist[0x04] = 0; hist[0x05] = 0; hist[0x06] = 0; hist[0x07] = 0;
    hist[0x08] = 0; hist[0x09] = 0; hist[0x0A] = 0; hist[0x0B] = 0;
    hist[0x0C] = 0; hist[0x0D] = 0; hist[0x0E] = 0; hist[0x0F] = 0;
    hist[0x10] = 0; hist[0x11] = 0; hist[0x12] = 0; hist[0x13] = 0;
    hist[0x14] = 0; hist[0x15] = 0; hist[0x16] = 0; hist[0x17] = 0;
    hist[0x18] = 0; hist[0x19] = 0; hist[0x1A] = 0; hist[0x1B] = 0;
    hist[0x1C] = 0; hist[0x1D] = 0; hist[0x1E] = 0; hist[0x1F] = 0;
    hist[0x20] = 0; hist[0x21] = 0; hist[0x22] = 0; hist[0x23] = 0;
    hist[0x24] = 0; hist[0x25] = 0; hist[0x26] = 0; hist[0x27] = 0;

    for (ctr = 5; ctr != 0; ctr--) {
        b = rec[0x12];
        if (b == 0) {
            break;
        }
        hist[b] += 1;
        b = rec[0x13];
        rec += 1;
        if (b == 0) {
            break;
        }
        hist[b] += 1;
        b = rec[0x13];
        rec += 1;
        if (b == 0) {
            break;
        }
        hist[b] += 1;
        b = rec[0x13];
        rec += 1;
        if (b == 0) {
            break;
        }
        hist[b] += 1;
        b = rec[0x13];
        rec += 1;
        if (b == 0) {
            break;
        }
        hist[b] += 1;
        b = rec[0x13];
        rec += 1;
        if (b == 0) {
            break;
        }
        rec += 1;
        hist[b] += 1;
    }

    i = 0;
    do {
        off = 0x2000;
        for (ctr = 2; ctr != 0; ctr--) {
            found = (u8 *)gSaveDataBase + off;
            if ((u32)(*(u32 *)(found + 0x40) + 0xB9BB0000) != 0x384AU) {
                hdrOk = 0;
            } else if ((u32)(*(u32 *)(found + 0x44) + 0xDFFB0000) != 0x201U) {
                hdrOk = 0;
            } else {
                hdrOk = 1;
            }
            if (hdrOk == 0) {
            } else if (i != (s32)found[0x62]) {
            } else {
                goto found_id;
            }
            off += 0x4000;
            found = (u8 *)gSaveDataBase + off;
            if ((u32)(*(u32 *)(found + 0x40) + 0xB9BB0000) != 0x384AU) {
                hdrOk = 0;
            } else if ((u32)(*(u32 *)(found + 0x44) + 0xDFFB0000) != 0x201U) {
                hdrOk = 0;
            } else {
                hdrOk = 1;
            }
            if (hdrOk == 0) {
            } else if (i != (s32)found[0x62]) {
            } else {
                goto found_id;
            }
            off += 0x4000;
            found = (u8 *)gSaveDataBase + off;
            if ((u32)(*(u32 *)(found + 0x40) + 0xB9BB0000) != 0x384AU) {
                hdrOk = 0;
            } else if ((u32)(*(u32 *)(found + 0x44) + 0xDFFB0000) != 0x201U) {
                hdrOk = 0;
            } else {
                hdrOk = 1;
            }
            if (hdrOk == 0) {
            } else if (i != (s32)found[0x62]) {
            } else {
                goto found_id;
            }
            off += 0x4000;
        }
        found = NULL;
    found_id:
        if (found != NULL) {
            b = found[0x61];
            if (b < 0x28U) {
                hist[b] += 1;
            }
        }
        i += 1;
    } while (i < 5);

    hp = &hist[1];
    idx = 1;
    for (ctr = 0xD; ctr != 0; ctr--) {
        if ((s8)hp[0] == 0) {
            freeId = idx;
            goto got_free;
        }
        idx += 1;
        if ((s8)hp[1] == 0) {
            freeId = idx;
            goto got_free;
        }
        idx += 1;
        if ((s8)hp[2] == 0) {
            freeId = idx;
            goto got_free;
        }
        hp += 3;
        idx += 1;
    }
    freeId = 0;
 got_free:
    best[0x61] = freeId;
    n = 0;
    best[0x64] = 1;
    best[0x65] = 3;
    best[0x66] = arg3;

    rec = gSystemSave;
    for (ctr = 3; ctr != 0; ctr--) {
        if (rec[0x12] == 0) {
            break;
        }
        b = rec[0x13];
        n += 1;
        rec += 1;
        if (b == 0) {
            break;
        }
        b = rec[0x13];
        n += 1;
        rec += 1;
        if (b == 0) {
            break;
        }
        b = rec[0x13];
        n += 1;
        rec += 1;
        if (b == 0) {
            break;
        }
        b = rec[0x13];
        n += 1;
        rec += 1;
        if (b == 0) {
            break;
        }
        b = rec[0x13];
        n += 1;
        rec += 1;
        if (b == 0) {
            break;
        }
        b = rec[0x13];
        n += 1;
        rec += 1;
        if (b == 0) {
            break;
        }
        b = rec[0x13];
        n += 1;
        rec += 1;
        if (b == 0) {
            break;
        }
        b = rec[0x13];
        n += 1;
        rec += 1;
        if (b == 0) {
            break;
        }
        n += 1;
        rec += 1;
    }

    fn_8014D698(gBattleState, best[0x61], best[0x66], arg4, (u8)(n + 1));

    p = best + 0xB8;
    w.owned = 0;
    w.vtbl = gStreamBaseVtbl;
    w.cur = NULL;
    w.start = NULL;
    w.size = 0;
    w.vtbl = gMemStreamVtbl;
    w.owned = 0;
    w.start = p;
    w.cur = p;
    w.size = 0x100000;
    fn_8017A38C(&w, gSaveStrings + 0x14F);
    BattleState_Write(gBattleState, &w);
    fn_8017A38C(&w, gSaveStrings + 0x154);
    fn_80048C5C(&w);
    fn_8017A38C(&w, gSaveStrings + 0x159);
    if (gBattleState[0x55] != 0) {
        fn_800167E4(&w);
    } else {
        Unit_WriteAll(&w);
    }
    fn_8017A38C(&w, gSaveStrings + 0x15E);
    fn_800C33C0(gConvoy, &w);
    fn_8017A38C(&w, gSaveStrings + 0x163);
    Icon_WriteSlots(gIconSlots, &w);
    fn_8017A38C(&w, gSaveStrings + 0x168);
    fn_8010FBA8(gMapObjEventList, &w);
    w.vtbl = gMemStreamVtbl;
    w.vtbl = gStreamBaseVtbl;
    if (w.owned != 0) {
        fn_800C4588(w.start);
        w.start = NULL;
        w.owned = 0;
    }
    fn_801E3CA8(best);
    arg0[1] = best;
    diff = (s32)best - (s32)gSaveDataBase;
    Card_RequestWrite(best, *(s32 *)(best + 0x4C), diff, diff, other);
}

#pragma push
#pragma optimization_level 4
void fn_801E1CB4(u8 **arg0, void *arg1) {
    void fn_80006298(void *, s32, s32);
    void fn_800167E4(void *);
    void Unit_WriteAll(void *);
    void fn_80048C5C(void *);
    void Icon_WriteSlots(void *, void *);
    void fn_800C33C0(void *, void *);
    void fn_800C4588(void *);
    void fn_8010FBA8(void *, void *);
    void BattleState_Write(void *, void *);
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

    u32 minSize;
    s32 off;
    u8 *best;
    s32 i;
    void *other;
    s32 ctr;
    u8 *base;
    u8 *slot;
    u8 hdrOk;
    u32 clamped;
    u8 saved47;
    struct {
        void *start;
        void *cur;
        u32 size;
        u8 owned;
        u8 pad[3];
        void *vtbl;
    } w;
    u8 *p;
    u8 *battle;

    other = arg1;
    saved47 = gSystemSave[0x47];
    best = Save_FindUnusedSlotIn(arg0);

    fn_80006298(best, 0, 0x4000);
    battle = gBattleState;
    *(s32 *)(best + 0x4C) = 0x4000;
    *(u32 *)(best + 0x40) = 0x4645384AU;
    *(u32 *)(best + 0x44) = 0x20050201U;
    *(u32 *)(best + 0x48) = 0;
    *(u32 *)(best + 0x5C) = 0;
    *(u32 *)(best + 0x58) = 0;
    best[0x60] = 2;
    best[0x61] = 0;
    best[0x62] = saved47;
    best[0x63] = 0;
    best[0x64] = 0;
    best[0x65] = 0;
    best[0x66] = 0;
    *(u64 *)(best + 0x58) = *(u64 *)(battle + 0x58);
    best[0x61] = battle[0x51C];
    best[0x64] = battle[0x10];
    best[0x65] = battle[0x54];
    best[0x66] = battle[0xA6];

    p = best + 0xB8;
    w.vtbl = gStreamBaseVtbl;
    w.cur = NULL;
    w.start = NULL;
    w.size = 0;
    w.owned = 0;
    w.vtbl = gMemStreamVtbl;
    w.owned = 0;
    w.start = p;
    w.cur = p;
    w.size = 0x100000;
    fn_8017A38C(&w, gSaveStrings + 0x14F);
    BattleState_Write(gBattleState, &w);
    fn_8017A38C(&w, gSaveStrings + 0x154);
    fn_80048C5C(&w);
    fn_8017A38C(&w, gSaveStrings + 0x159);
    if (gBattleState[0x55] != 0) {
        fn_800167E4(&w);
    } else {
        Unit_WriteAll(&w);
    }
    fn_8017A38C(&w, gSaveStrings + 0x15E);
    fn_800C33C0(gConvoy, &w);
    fn_8017A38C(&w, gSaveStrings + 0x163);
    Icon_WriteSlots(gIconSlots, &w);
    fn_8017A38C(&w, gSaveStrings + 0x168);
    fn_8010FBA8(gMapObjEventList, &w);
    w.vtbl = gMemStreamVtbl;
    w.vtbl = gStreamBaseVtbl;
    if (w.owned != 0) {
        fn_800C4588(w.start);
        w.start = NULL;
        w.owned = 0;
    }
    fn_801E3CA8(best);
    arg0[1] = best;
    *(u8 **)((u8 *)other + 0x54) = best;
}
#pragma pop
void fn_801E2014(s32 unused, u8 arg1, s32 arg2) {
    extern u8 gSystemSave[];
    extern u8 lbl_80299E10[];
    void Process_CreateChild(void *, s32);

    gSystemSave[0x47] = arg1;
    Process_CreateChild(lbl_80299E10, arg2);
}

void fn_801E204C(void *arg0) {
    extern u8 gBattleState[];
    u8 *temp_r5;

    if (gBattleState[0x54] == 4 && gBattleState[0x10] != 0x20) {
        temp_r5 = *(u8 **)((u8 *)arg0 + 0x54);
        temp_r5[0x64] = gBattleState[0x51E];
        temp_r5[0x65] = 9;
    }
}

void fn_801E2084(s32 arg0) {
    u8 Card_CheckError(void);
    void fn_801E1CB4(void *, s32);
    extern u16 gSaveDataBase;

    if (Card_CheckError() != 0) {
        return;
    }

    fn_801E1CB4(&gSaveDataBase, arg0);
}

/* Free any prior save buffer, alloc a new one, then init it or start E_OpenSeq. */
void SaveData_StartOpenSeq(void *parent) {
    extern void *gSaveDataBase;
    extern u8 gSaveStrings[];
    extern s32 gUiInputFlags;
    extern u8 gProc_E_OpenSeq[];

    void DebugPrint(const char *, ...);
    void fn_800C4588(void *);
    void *fn_800C4604(s32, s32, void *, s32);
    void SaveData_Init(void **);
    void *Process_CreateChild(void *, void *);

    void *buf;
    void *child;
    void *arg;

    arg = parent;

    if (gSaveDataBase != (int)NULL) {
        DebugPrint((char *)(gSaveStrings + 0x122));
        fn_800C4588(gSaveDataBase);
        gSaveDataBase = NULL;
    }

    DebugPrint((char *)(gSaveStrings + 0x16D));
    buf = fn_800C4604(0, -0x26000, gSaveStrings + 0x14E, 0);
    gSaveDataBase = buf;

    if (gUiInputFlags & 0x10) {
        SaveData_Init(&gSaveDataBase);
    } else {
        child = Process_CreateChild(gProc_E_OpenSeq, arg);
        *(void **)((u8 *)child + 0x54) = gSaveDataBase;
        *(s32 *)((u8 *)child + 0x60) = 1;
    }
}

void fn_801E218C(void) {
    u8 Card_CheckError(void);
    if (Card_CheckError() != 0) {
        return;
    }
}

void fn_801E21B0(void *arg0) {
    void Card_RequestWrite(void *, s32, s32, s32, void *);
    extern s32 gSaveDataBase;
    void *temp_r6;
    s32 temp_r5;

    temp_r6 = *(void **)((u8 *)arg0 + 0x54);
    temp_r5 = (s32)temp_r6 - gSaveDataBase;
    Card_RequestWrite(temp_r6, *(s32 *)((u8 *)temp_r6 + 0x4C), temp_r5, temp_r5, arg0);
}

extern u8 gSystemSave[72];
void fn_801E21EC(void **arg0,s32 arg1) {
#pragma cplusplus on
struct Save {
u8 *base;
void *find(s32 id) {
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
if(valid && id==*(u8 *)(slot+0x62)) return slot;
off+=0x4000;
}
return NULL;
}
};
arg0[1]=((Save *)arg0)->find(arg1);
gSystemSave[0x47]=arg1;
#pragma cplusplus reset
}

void *fn_801E2324(void **arg0,s32 arg1) {
u8 *slot;
s32 off,i;
u8 valid;
i=0;
off=0x2000;
for(;i<6;i++) {
slot=(u8 *)*arg0+off;
if(*(u32 *)(slot+0x40)!=0x4645384AU) valid=0;
else if(*(u32 *)(slot+0x44)!=0x20050201U) valid=0;
else valid=1;
if(valid && arg1==*(u8 *)(slot+0x62)) return slot;
off+=0x4000;
}
return NULL;
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
u8 *fn_801E2458(u8 **arg0)
{
  s32 off = 0x2000;
  u32 minSize = -1;
  u8 *new_var;
  u8 *best = NULL;
  s32 i = 0;
  u8 *slot;
  u8 *new_var2;
  int new_var3;
  u8 valid;
  for (; i < 6; i++)
  {
    new_var2 = (*arg0) + off;
    new_var = new_var2;
    ;
    if ((*((u32 *) (new_var + 0x40))) != 0x4645384AU)
    {
      valid = 0;
    }
    else
      if ((*((u32 *) (new_var + 0x44))) != 0x20050201U)
    {
      valid = 0;
    }
    else
    {
      ;
    }
    new_var3 = !1;
    if (new_var3 && (minSize > save_slot_size(new_var)))
    {
      best = slot;
      minSize = save_slot_size(slot);
    }
    off += 0x4000;
  }

  return best;
}
#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset
s32 Save_GetLargeSlot(s32 *arg0, s32 arg1) {
    return ((arg1 * 0x6000) + 0x20000 + *arg0) - 0x6000;
}

s32 Save_GetSmallSlot(s32 *arg0, s32 arg1) {
    s32 x = *arg0;
    x = (arg1 << 14) + x;
    return x + 0x2000;
}

void SaveData_Release(u32 *arg0) {
    extern u16 gSaveStrings[];
    void DebugPrint(char *, ...);

    if (*arg0 != 0U) {
        DebugPrint((char *)((u8 *)gSaveStrings + 0x122));
        fn_800C4588(*arg0);
        *arg0 = 0U;
    }
}

void fn_801E25EC(void) {
    extern u8 gSaveStrings[];
    void DebugPrint(char *, ...);
    DebugPrint((char *)(gSaveStrings + 0x181));
    fn_800E9A94();
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
void fn_801E2620(void **arg0, u8 arg1) {
    u8 fn_800EB520(void *);
    void fn_800EB760(s32);
    void *fn_800C4638(s32, void *, s32);
    void fn_800C4588(void *);
    void Crc32_InitTable(void);
    u32 Crc32_Calc(void *, void *, s32);
    void fn_8021D614(u32, s32 *, u32);
    u64 OSGetTime(void);
    s32 fn_80211690(s32, s32);
    u16 fn_802072A0(u32, s32, s32, s32);
    u8 fn_80209A0C(void);
    void *memset(void *, s32, u32);
    extern u8 gSaveStrings[];
    extern u8 gSystemSave[72];

    u8 counts[5];
    s8 best_idx[5];
    u32 best_val[5];
    u8 hist[6];
    u8 *slots[2];
    s32 spC;
    s32 sp8;
    s32 i;
    s32 off;
    u8 *blk;
    u8 *sys;
    u8 ok;
    u8 ok2;
    void *buf;
    u32 hash;
    u8 *dst;
    u8 *src;
    s32 j;
    u32 capped;
    u8 *best;
    u32 bestc;
    u8 *less;
    u8 *more;
    s8 lang;
    u32 x0, x1;
    u64 temp_ret;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    s32 temp_r4_2;
    u8 temp_r3;
    u8 idx;

    if (fn_800EB520(*arg0) == 0) {
        fn_800EB760(-4);
        return;
    }

    counts[0] = 0;
    i = 0;
    off = 0x2000;
    best_idx[0] = -1;
    best_val[0] = 0;
    counts[1] = 0;
    best_idx[1] = -1;
    best_val[1] = 0;
    counts[2] = 0;
    best_idx[2] = -1;
    best_val[2] = 0;
    counts[3] = 0;
    best_idx[3] = -1;
    best_val[3] = 0;
    counts[4] = 0;
    best_idx[4] = -1;
    best_val[4] = 0;

    do {
        blk = (u8 *)*(void * volatile *)arg0 + off;
        if (*(u32 *)(blk + 0x40) != 0x4645384AU) {
            ok = 0;
        } else if (*(u32 *)(blk + 0x44) != 0x20050201U) {
            ok = 0;
        } else {
            ok = 1;
        }
        if (ok != 0) {
            if (*(u32 *)(blk + 0x50) == 0x12345678U) {
                ok2 = 1;
            } else if (blk[0x60] == 1) {
                ok2 = 1;
            } else {
                buf = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
                Crc32_InitTable();
                hash = Crc32_Calc(buf, blk + 0x70, *(s32 *)(blk + 0x4C) - 0x70);
                fn_800C4588(buf);
                if (*(u32 *)(blk + 0x50) != hash) {
                    ok2 = 0;
                } else {
                    ok2 = 1;
                }
            }
            if (ok2 == 0) {
                *(u32 *)(blk + 0x40) = 0;
                fn_800EB760(-0x42);
            } else {
                goto accumulate;
            }
        } else {
        accumulate:
            idx = blk[0x62];
            capped = save_slot_size(blk);
            counts[idx] = (u8)(counts[idx] + 1);
            if (best_val[idx] < capped) {
                best_idx[idx] = (s8)i;
                best_val[idx] = save_slot_size(blk);
            }
        }
        i += 1;
        off += 0x4000;
    } while (i < 6);

    hist[0] = 0;
    hist[1] = 0;
    hist[2] = 0;
    hist[3] = 0;
    hist[4] = 0;
    hist[5] = 0;
    if ((s8)best_idx[0] >= 0) {
        hist[(s8)best_idx[0]] = (u8)(hist[(s8)best_idx[0]] + 1);
    }
    if ((s8)best_idx[1] >= 0) {
        hist[(s8)best_idx[1]] = (u8)(hist[(s8)best_idx[1]] + 1);
    }
    if ((s8)best_idx[2] >= 0) {
        hist[(s8)best_idx[2]] = (u8)(hist[(s8)best_idx[2]] + 1);
    }
    if ((s8)best_idx[3] >= 0) {
        hist[(s8)best_idx[3]] = (u8)(hist[(s8)best_idx[3]] + 1);
    }
    if ((s8)best_idx[4] >= 0) {
        hist[(s8)best_idx[4]] = (u8)(hist[(s8)best_idx[4]] + 1);
    }

    {
        u8 *hp = hist;
        off = 0x2000;
        for (j = 2; j != 0; j--) {
            blk = (u8 *)*(void * volatile *)arg0 + off;
            if (hp[0] == 0) {
                *(u32 *)(blk + 0x40) = 0;
            } else if (blk[0x60] == 1) {
                *(u32 *)(blk + 0x40) = 0;
            }
            off += 0x4000;
            blk = (u8 *)*(void * volatile *)arg0 + off;
            if (hp[1] == 0) {
                *(u32 *)(blk + 0x40) = 0;
            } else if (blk[0x60] == 1) {
                *(u32 *)(blk + 0x40) = 0;
            }
            off += 0x4000;
            blk = (u8 *)*(void * volatile *)arg0 + off;
            if (hp[2] == 0) {
                *(u32 *)(blk + 0x40) = 0;
            } else if (blk[0x60] == 1) {
                *(u32 *)(blk + 0x40) = 0;
            }
            off += 0x4000;
            hp += 3;
        }
    }

    {
        u8 **sp = slots;
        off = 0x1A000;
        i = 0;
        do {
            *sp = (u8 *)*(void * volatile *)arg0 + off;
            blk = *sp;
            if (*(u32 *)(blk + 0x40) != 0x4645384AU) {
                ok = 0;
            } else if (*(u32 *)(blk + 0x44) != 0x20050201U) {
                ok = 0;
            } else {
                ok = 1;
            }
            if (ok != 0) {
                if (*(u32 *)(blk + 0x50) == 0x12345678U) {
                    ok2 = 1;
                } else if (blk[0x60] == 1) {
                    ok2 = 1;
                } else {
                    buf = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
                    Crc32_InitTable();
                    hash = Crc32_Calc(buf, blk + 0x70, *(s32 *)(blk + 0x4C) - 0x70);
                    fn_800C4588(buf);
                    if (*(u32 *)(blk + 0x50) != hash) {
                        ok2 = 0;
                    } else {
                        ok2 = 1;
                    }
                }
                if (ok2 == 0) {
                    *(u32 *)(slots[i] + 0x40) = 0;
                    fn_800EB760(-0x42);
                    goto after_pair;
                }
            }
            i += 1;
            sp += 1;
            off += 0x6000;
        } while (i < 2);
    }

    {
        u32 ca = save_slot_size(slots[0]);
        u32 cb = save_slot_size(slots[1]);
        if (ca < cb) {
            less = slots[0];
            more = slots[1];
        } else {
            less = slots[1];
            more = slots[0];
        }
        *(u32 *)(less + 0x40) = 0;
        if (more[0x60] == 1) {
            *(u32 *)(more + 0x40) = 0;
        }
    }

after_pair:
    bestc = 0;
    best = NULL;
    off = 0x2000;
    for (j = 3; j != 0; j--) {
        sys = (u8 *)*(void * volatile *)arg0 + off;
        if (*(u32 *)(sys + 0x70) != 0x53595346U) {
            ok = 0;
        } else if (*(u32 *)(sys + 0x74) != 0x20050201U) {
            ok = 0;
        } else {
            ok = 1;
        }
        if (ok != 0) {
            capped = save_slot_size(sys);
            if (bestc < capped) {
                best = sys;
                bestc = save_slot_size(sys);
            }
        }
        off += 0x4000;
        sys = (u8 *)*(void * volatile *)arg0 + off;
        if (*(u32 *)(sys + 0x70) != 0x53595346U) {
            ok = 0;
        } else if (*(u32 *)(sys + 0x74) != 0x20050201U) {
            ok = 0;
        } else {
            ok = 1;
        }
        if (ok != 0) {
            capped = save_slot_size(sys);
            if (bestc < capped) {
                best = sys;
                bestc = save_slot_size(sys);
            }
        }
        off += 0x4000;
    }
    sys = (u8 *)*(void * volatile *)arg0 + 0x1A000;
    if (*(u32 *)(sys + 0x70) != 0x53595346U) {
        ok = 0;
    } else if (*(u32 *)(sys + 0x74) != 0x20050201U) {
        ok = 0;
    } else {
        ok = 1;
    }
    if (ok != 0) {
        capped = save_slot_size(sys);
        if (bestc < capped) {
            best = sys;
            bestc = save_slot_size(sys);
        }
    }
    sys = (u8 *)*(void * volatile *)arg0 + 0x20000;
    if (*(u32 *)(sys + 0x70) != 0x53595346U) {
        ok = 0;
    } else if (*(u32 *)(sys + 0x74) != 0x20050201U) {
        ok = 0;
    } else {
        ok = 1;
    }
    if (ok != 0) {
        capped = save_slot_size(sys);
        if (bestc < capped) {
            best = sys;
        }
    }

    if (arg1 != 0) {
        if (best == NULL) {
            fn_800EB760(-0x40);
            return;
        }
        x0 = *(u32 *)(best + 0x78);
        x1 = *(u32 *)(best + 0x7C);
        if (((*(u32 *)(gSystemSave + 8) ^ x0) | (*(u32 *)(gSystemSave + 0xC) ^ x1)) == 0) {
            return;
        }
        if (((*(u32 *)(gSystemSave + 8) ^ 0x01234567U) | (*(u32 *)(gSystemSave + 0xC) ^ 0x89ABCDEFU)) == 0) {
            return;
        }
        fn_800EB760(-0x40);
        return;
    }

    if (best != NULL) {
        src = best + 0x70;
        dst = gSystemSave;
        *(u32 *)(dst + 0) = *(u32 *)(src + 0);
        *(u32 *)(dst + 4) = *(u32 *)(src + 4);
        *(u32 *)(dst + 0xC) = *(u32 *)(src + 0xC);
        *(u32 *)(dst + 8) = *(u32 *)(src + 8);
        *(u16 *)(dst + 0x10) = *(u16 *)(src + 0x10);
        dst[0x40] = src[0x40];
        dst[0x41] = src[0x41];
        dst[0x42] = src[0x42];
        dst[0x43] = src[0x43];
        dst[0x44] = src[0x44];
        dst[0x47] = src[0x47];
        dst = gSystemSave;
        j = 0;
        for (i = 5; i != 0; i--) {
            u8 *p = src + 0x12 + j;
            j += 6;
            dst[0x12] = p[0];
            dst[0x13] = p[1];
            dst[0x14] = p[2];
            dst[0x15] = p[3];
            dst[0x16] = p[4];
            dst[0x17] = p[5];
            dst += 6;
        }
        dst = gSystemSave;
        *(u32 *)(dst + 0x3C) = 0;
        *(u32 *)(dst + 0x38) = 0;
        *(u32 *)(dst + 0x34) = 0;
        *(u32 *)(dst + 0x30) = 0;
        *(u32 *)(dst + 0x30) = *(u32 *)(src + 0x30);
        *(u32 *)(dst + 0x34) = *(u32 *)(src + 0x34);
        *(u32 *)(dst + 0x38) = *(u32 *)(src + 0x38);
        *(u32 *)(dst + 0x3C) = *(u32 *)(src + 0x3C);
        return;
    }

    *(u32 *)(gSystemSave + 0) = 0x53595346U;
    *(u32 *)(gSystemSave + 4) = 0x20050201U;
    spC = 0;
    sp8 = 0;
    fn_8021D614(0, &sp8, 0x20050201U);
    temp_ret = OSGetTime();
    temp_r5 = spC;
    temp_r4 = temp_r5 + (u32)temp_ret;
    spC = temp_r4;
    sp8 = sp8 + (s32)temp_ret;
    temp_r6 = fn_80211690(temp_r4, temp_r5) * 0x7B;
    temp_r5_2 = spC + temp_r6;
    temp_r4_2 = sp8;
    spC = temp_r5_2;
    sp8 = temp_r4_2;
    *(u32 *)(gSystemSave + 0xC) = temp_r5_2;
    *(u32 *)(gSystemSave + 8) = temp_r4_2;
    *(u16 *)(gSystemSave + 0x10) = 0;
    gSystemSave[0x40] = 0;
    gSystemSave[0x41] = 0;
    gSystemSave[0x42] = 0x40;
    gSystemSave[0x43] = 0;
    if (fn_802072A0(0, temp_r4_2, temp_r5_2, temp_r6) == 1) {
        lang = 0;
    } else {
        temp_r3 = fn_80209A0C();
        switch ((s32)temp_r3) {
        case 0:
            lang = 1;
            break;
        case 1:
            lang = 2;
            break;
        case 2:
            lang = 3;
            break;
        case 3:
            lang = 4;
            break;
        case 4:
            lang = 5;
            break;
        case 5:
            lang = 1;
            break;
        }
    }
    gSystemSave[0x44] = (u8)lang;
    gSystemSave[0x47] = 0;
    memset(gSystemSave + 0x12, 0, 0x1E);
    memset(gSystemSave + 0x45, 0, 2);
    *(u32 *)(gSystemSave + 0x3C) = 0;
    *(u32 *)(gSystemSave + 0x38) = 0;
    *(u32 *)(gSystemSave + 0x34) = 0;
    *(u32 *)(gSystemSave + 0x30) = 0;
    fn_800EB760(-0x42);
}
#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

void fn_801E2F9C(s32 *arg0, s32 arg1) {
    extern u8 gSaveStrings[];
    void DebugPrint(char *, ...);
    s32 fn_800C4604(s32, s32, void *, s32);
    void fn_800EA540(s32, s32);

    DebugPrint((char *)(gSaveStrings + 0x137));
    *arg0 = fn_800C4604(0, 0xFFFDA000, gSaveStrings + 0x14E, 0);
    fn_800EA540(*arg0, arg1);
}

void SaveData_Init(void **arg0) {
    void *memset(void *, int, unsigned long);
    void fn_800EB760(s32);
    u8 *buf;
    u32 bus;
    u32 magic;
    u32 ver;

    memset(*arg0, 0, SAVE_CARD_FILE_SIZE);
    buf = *arg0;

    magic = SAVE_SLOT_MAGIC;
    ver = SAVE_VER_20050201;

    *(u32 *)(buf + 0x2040) = magic;
    *(u32 *)(buf + 0x2044) = ver;
    *(u32 *)(buf + 0x2048) = 1;
    buf[0x2060] = 2;
    buf[0x2062] = 0;
    buf[0x2064] = 3;
    buf[0x2065] = 4;
    buf[0x2066] = 0;

    bus = *(u32 *)0x800000F8 >> 2;
    *(u32 *)(buf + 0x205C) = bus * 0xE10;
    *(u32 *)(buf + 0x2058) = (u32)(((u64)bus * 0xE10ULL) >> 32);

    buf = *arg0;
    *(u32 *)(buf + 0x6040) = magic;
    *(u32 *)(buf + 0x6044) = ver;
    *(u32 *)(buf + 0x6048) = 2;
    buf[0x6060] = 2;
    buf[0x6062] = 1;
    buf[0x6064] = 4;
    buf[0x6065] = 4;
    buf[0x6066] = 0;

    buf = *arg0;
    *(u32 *)(buf + 0xA040) = magic;
    *(u32 *)(buf + 0xA044) = ver;
    *(u32 *)(buf + 0xA048) = 3;
    buf[0xA060] = 2;
    buf[0xA062] = 2;
    buf[0xA064] = 5;
    buf[0xA065] = 4;
    buf[0xA066] = 0;

    fn_800EB760(0);
}

void fn_801E3118(s32 *arg0, s32 arg1, u8 arg2) {
    void DebugPrint(char *, ...);
    s32 fn_800C4604(s32, s32, void *, s32);
    void SaveData_Init(s32 *);
    void *Process_CreateChild(void *, s32);
    extern u8 gSaveStrings[];
    extern u8 gProc_E_OpenSeq[];
    extern s32 gUiInputFlags;
    void *p;

    DebugPrint((char *)(gSaveStrings + 0x16D));
    *arg0 = fn_800C4604(0, 0xFFFDA000, gSaveStrings + 0x14E, 0);
    if (gUiInputFlags & 0x10) {
        SaveData_Init(arg0);
    } else {
        p = Process_CreateChild(gProc_E_OpenSeq, arg1);
        *(s32 *)((u8 *)p + 0x54) = *arg0;
        *(u32 *)((u8 *)p + 0x60) = arg2;
    }
}

void fn_801E31C8(void *arg0)
{
    void fn_801E2620(void *, s32);
    u8 Card_CheckError(void);
    extern u8 gSaveDataBase;
    u32 value;

    if ((u8)Card_CheckError() != 0) {
        return;
    }

    value = *(u32 *)((u8 *)arg0 + 0x60);
    fn_801E2620(&gSaveDataBase, value != 0);
}

void fn_801E3214(void *arg0) {
    M2C_UNK fn_800EA540(s32, void *);
    fn_800EA540(M2C_FIELD(arg0, s32 *, 0x54), arg0);
}

void fn_801E323C(void *arg0, void *arg1)
{
    extern u8 gSaveStrings[];
    extern u8 lbl_80299DC8[];
    void DebugPrint(char *, ...);
    void *Process_CreateChild(void *, void *);
    void *obj;

    DebugPrint((char *)(gSaveStrings + 0x197));
    obj = Process_CreateChild(lbl_80299DC8, arg1);
    *(s32 *)((u8 *)obj + 0x54) = *(s32 *)arg0;
}

void fn_801E329C(void *arg0) {
    M2C_UNK fn_800EA7CC(s32, void *);
    fn_800EA7CC(M2C_FIELD(arg0, s32 *, 0x54), arg0);
}

void fn_801E32C4(s32 unused, s32 arg1) {
    extern u8 gSaveStrings[];
    void DebugPrint(char *, ...);
    void fn_800E9AE4(s32);

    DebugPrint((char *)(gSaveStrings + 0x1AD));
    fn_800E9AE4(arg1);
}

#pragma global_optimizer off
#pragma opt_strength_reduction off
u8 SystemSave_CountPackedSlots(u8 *save)
{
    /* Count leading non-zero bytes in save+0x12 (3 rows × 10); return count+1. */
    s32 count = 0;
    s32 off = 0;
    s32 i;
    s32 idx;

    for (i = 0; i < 3; i++) {
        idx = off + 0x12;
        if (save[idx] == 0)
            goto end;
        count += 1;
        idx = off + 0x13;
        if (save[idx] == 0)
            goto end;
        count += 1;
        idx = off + 0x14;
        if (save[idx] == 0)
            goto end;
        count += 1;
        idx = off + 0x15;
        if (save[idx] == 0)
            goto end;
        count += 1;
        idx = off + 0x16;
        if (save[idx] == 0)
            goto end;
        count += 1;
        idx = off + 0x17;
        if (save[idx] == 0)
            goto end;
        count += 1;
        idx = off + 0x18;
        if (save[idx] == 0)
            goto end;
        count += 1;
        idx = off + 0x19;
        if (save[idx] == 0)
            goto end;
        count += 1;
        idx = off + 0x1a;
        if (save[idx] == 0)
            goto end;
        count += 1;
        idx = off + 0x1b;
        if (save[idx] == 0)
            goto end;
        count += 1;
        off += 0xa;
    }
end:
    return (u8)(count + 1);
}
#pragma opt_strength_reduction on
#pragma global_optimizer on
s32 SystemSave_TestFlag0(void *arg0) {
    return M2C_FIELD(arg0, u16 *, 0x10) & 1;
}

#pragma opt_unroll 1
#pragma opt_strength_reduction off
void fn_801E3400(u8 *arg0, u8 arg1)
{
    extern u8 gBattleState[];
    s32 i;
    u8 v;

    switch (gBattleState[0xa6]) {
    case 1:
        *(u16 *)(arg0 + 0x10) |= 4;
    case 0:
        *(u16 *)(arg0 + 0x10) |= 2;
    case 3:
        *(u16 *)(arg0 + 0x10) |= 1;
        break;
    case 2:
        break;
    }

    for (i = 0; i < 30; i++) {
        v = arg0[i + 0x12];
        if (v == arg1) return;
        if (v == 0) {
            arg0[i + 0x12] = arg1;
            return;
        }
    }
}
#pragma opt_strength_reduction reset
#pragma opt_unroll reset
void fn_801E3560(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    M2C_FIELD(arg0, s8 *, 0x40) = arg1;
    M2C_FIELD(arg0, s8 *, 0x41) = arg2;
    M2C_FIELD(arg0, s8 *, 0x42) = arg3;
}

s32 fn_801E3570(s32 arg0, void *arg1) {
    u8 Status_Test(s32, u8);
    u16 temp_r0;

    temp_r0 = M2C_FIELD(arg1, u16 *, 0x18);
    if (temp_r0 >= 0x80U) {
        return 0;
    }
    return Status_Test(arg0 + 0x30, (u8) temp_r0) != 0;
}

void fn_801E35BC(s32 arg0, s32 arg1) {
    M2C_UNK Status_Clear(s32, u8);
    if (arg1 < 0x80) {
        Status_Clear(arg0 + 0x30, (u8) arg1);
    }
}

void fn_801E35EC(s32 arg0, void *arg1) {
    s32 Status_Clear(s32, u8);
    u16 temp_r0 = *(u16 *)((u8 *)arg1 + 0x18);
    if (temp_r0 < 0x80U) {
        s32 a = arg0 + 0x30;
        u8 b = (u8)temp_r0;
        Status_Clear(a, b);
    }
}

s32 fn_801E3620(void *arg0) {
    if ((u32) (M2C_FIELD(arg0, s32 *, 0) + 0xACA70000) != 0x5346U) {
        return 0;
    }
    return M2C_FIELD(arg0, s32 *, 4) == 0x20050201;
}

void fn_801E3654(void *unused, void *data) {
    struct { void *start; void *cur; u32 size; u8 owned; void *vtbl; } w;
    extern u8 gBattleState[], gSaveStrings[], gConvoy[], gIconSlots[], gMapObjEventList[];
    extern u16 lbl_802842B8[], gStreamBaseVtbl[];
    void fn_8017A7D4(void *, void *);
    void fn_8017A6C4(void *, void *);
    void fn_8014C1B8(void *, void *);
    void fn_80048A90(void *);
    void fn_80016628(void *);
    void fn_800C3364(void *, void *);
    void fn_800C2930(void *, void *);
    void fn_8010FB7C(void *, void *);
    void fn_800C4588(void *);
    void UnitPair_Read(void *, void *);
    extern u8 gUiContext[];
    fn_8017A7D4(&w, data);
    fn_8017A6C4(&w, gSaveStrings + 0x14F);
    fn_8014C1B8(gBattleState, &w);
    fn_8017A6C4(&w, gSaveStrings + 0x154);
    fn_80048A90(&w);
    fn_8017A6C4(&w, gSaveStrings + 0x159);
    fn_80016628(&w);
    fn_8017A6C4(&w, gSaveStrings + 0x15E);
    fn_800C3364(gConvoy, &w);
    fn_8017A6C4(&w, gSaveStrings + 0x163);
    fn_800C2930(gIconSlots, &w);
    fn_8017A6C4(&w, gSaveStrings + 0x168);
    fn_8010FB7C(gMapObjEventList, &w);
    fn_8017A6C4(&w, gSaveStrings + 0x1C2);
    UnitPair_Read(gUiContext, &w);
    w.vtbl = lbl_802842B8;
    w.vtbl = gStreamBaseVtbl;
    if (w.owned) {
        fn_800C4588(w.start);
        w.start = 0;
        w.owned = 0;
    }
}

void fn_801E379C(u8 *arg0) {
    struct { void *start; void *cur; u32 size; u8 owned; void *vtbl; } w;
    extern u8 gBattleState[], gSaveStrings[], gConvoy[], gIconSlots[], gMapObjEventList[];
    extern u16 lbl_802842B8[], gStreamBaseVtbl[];
    void fn_8017A7D4(void *, void *);
    void fn_8017A6C4(void *, void *);
    void fn_8014C1B8(void *, void *);
    void fn_80048A90(void *);
    void fn_80016628(void *);
    void fn_800C3364(void *, void *);
    void fn_800C2930(void *, void *);
    void fn_8010FB7C(void *, void *);
    void fn_800C4588(void *);
    fn_8017A7D4(&w, arg0 + 0xB8);
    gBattleState[0x51C] = arg0[0x61];
    fn_8017A6C4(&w, gSaveStrings + 0x14F);
    fn_8014C1B8(gBattleState, &w);
    fn_8017A6C4(&w, gSaveStrings + 0x154);
    fn_80048A90(&w);
    fn_8017A6C4(&w, gSaveStrings + 0x159);
    fn_80016628(&w);
    fn_8017A6C4(&w, gSaveStrings + 0x15E);
    fn_800C3364(gConvoy, &w);
    fn_8017A6C4(&w, gSaveStrings + 0x163);
    fn_800C2930(gIconSlots, &w);
    fn_8017A6C4(&w, gSaveStrings + 0x168);
    fn_8010FB7C(gMapObjEventList, &w);
    w.vtbl = lbl_802842B8;
    w.vtbl = gStreamBaseVtbl;
    if (w.owned) {
        fn_800C4588(w.start);
        w.start = 0;
        w.owned = 0;
    }
}

#pragma push
#pragma opt_propagation off
typedef struct MemStream_801E38E0 {
    void *start;
    void *cur;
    u32 size;
    u8 owned;
    void *vtbl;
} MemStream_801E38E0;

static inline void MemStream_Init_801E38E0(MemStream_801E38E0 *w, void *data) {
    extern u16 gStreamBaseVtbl[];
    extern u8 gMemStreamVtbl[];
    w->vtbl = gStreamBaseVtbl;
    w->cur = 0;
    w->start = 0;
    w->size = 0;
    w->owned = 0;
    w->vtbl = gMemStreamVtbl;
    w->owned = 0;
    w->start = data;
    w->cur = data;
    w->size = 0x100000;
}

void fn_801E38E0(void *unused, void *data) {
    MemStream_801E38E0 w;
    extern u8 gBattleState[], gSaveStrings[], gConvoy[], gIconSlots[], gMapObjEventList[], gUiContext[], gMemStreamVtbl[];
    extern u16 gStreamBaseVtbl[];
    void fn_8017A38C(void *, void *);
    void BattleState_Write(void *, void *);
    void fn_80048C5C(void *);
    void Unit_WriteAll(void *);
    void fn_800C33C0(void *, void *);
    void Icon_WriteSlots(void *, void *);
    void fn_8010FBA8(void *, void *);
    void UnitPair_Write(void *, void *);
    void fn_800C4588(void *);

    MemStream_Init_801E38E0(&w, data);
    fn_8017A38C(&w, gSaveStrings + 0x14F);
    BattleState_Write(gBattleState, &w);
    fn_8017A38C(&w, gSaveStrings + 0x154);
    fn_80048C5C(&w);
    fn_8017A38C(&w, gSaveStrings + 0x159);
    Unit_WriteAll(&w);
    fn_8017A38C(&w, gSaveStrings + 0x15E);
    fn_800C33C0(gConvoy, &w);
    fn_8017A38C(&w, gSaveStrings + 0x163);
    Icon_WriteSlots(gIconSlots, &w);
    fn_8017A38C(&w, gSaveStrings + 0x168);
    fn_8010FBA8(gMapObjEventList, &w);
    fn_8017A38C(&w, gSaveStrings + 0x1C2);
    UnitPair_Write(gUiContext, &w);
    w.vtbl = gMemStreamVtbl;
    w.vtbl = gStreamBaseVtbl;
    if (w.owned) {
        fn_800C4588(w.start);
        w.start = 0;
        w.owned = 0;
    }
}
#pragma pop
void fn_801E3A60(void *arg0, u32 *hours, u32 *mins, u32 *secs) {
#pragma use_lmw_stmw on
    unsigned long long __div2i(s32, s32, s32, s32);
    u32 total;
    s32 *m;
    s32 *h;
    s32 *s;

    m = (s32 *)mins;
    h = (s32 *)hours;
    s = (s32 *)secs;
    total = (u32)__div2i(*(s32 *)((u8 *)arg0 + 0x58), *(s32 *)((u8 *)arg0 + 0x5C), 0, *(u32 *)0x800000F8 >> 2);
    *s = (s32)(total % 60);
    *m = (s32)((total / 60) % 60);
    *h = (s32)(total / 3600);
}
#pragma opt_strength_reduction off
#pragma global_optimizer off
void fn_801E3B08(u8 *dst) {
void *Msg_Expand(void*); void fn_8020B294(s64,void*); void fn_80231E74(void*,s32,void*,...);
s32 strlen(void*); void *memcpy(void*,void*,s32);
extern u8 gSaveStrings[];
u8 formatted[0x28];
s32 cal[10];
u8 suffix[0x20];
u8 space; u8 *p; s32 ctr; s32 i; void *name;
i=0; space=0x20;
for(ctr=2;ctr!=0;ctr--) {
p=dst+i; i+=8;
p[0]=space;p[1]=space;p[2]=space;p[3]=space;p[4]=space;p[5]=space;p[6]=space;p[7]=space;
p=dst+i; i+=8;
p[0]=space;p[1]=space;p[2]=space;p[3]=space;p[4]=space;p[5]=space;p[6]=space;p[7]=space;
p=dst+i; i+=8;
p[0]=space;p[1]=space;p[2]=space;p[3]=space;p[4]=space;p[5]=space;p[6]=space;p[7]=space;
p=dst+i; i+=8;
p[0]=space;p[1]=space;p[2]=space;p[3]=space;p[4]=space;p[5]=space;p[6]=space;p[7]=space;
}
name=Msg_Expand(gSaveStrings+0x1c7);
fn_8020B294(OSGetTime(),cal);
cal[4]++;
suffix[0]=0;
fn_80231E74(formatted,0x20,gSaveStrings+0x1d0,cal[4],cal[3],cal[5]%100,cal[2],cal[1],suffix);
memcpy(dst,name,strlen(name));
memcpy(dst+0x20,formatted,strlen(formatted));
}
#pragma global_optimizer reset
#pragma opt_strength_reduction reset
void fn_801E3CA8(void *arg0) {
    void *Msg_Expand(void *);
    void DebugPrint(void *, s32, ...);
    void *fn_800C4638(s32, void *, s32);
    void fn_800C4588(void *);
    void Crc32_InitTable(void);
    s32 Crc32_Calc(void *, void *, s32);
    s64 OSGetTime(void);
    void fn_8020B294(s64, void *);
    void fn_80231E74(void *, s32, void *, ...);
    s32 strlen(void *);
    void *memcpy(void *, void *, s32);
    extern void *gSaveDataBase;
    extern u8 gSaveStrings[];
    u8 sp58[0x28];
    struct {
        s32 sec, min, hour, mday, mon, year;
        s32 wday, yday, msec, usec;
    } cal;
    u8 sp10;
    s32 i;
    s32 j;
    s32 off;
    s32 ctr;
    u32 best;
    u32 clamped;
    u32 w8;
    u32 wC;
    u8 *base;
    u8 *src;
    void *buf;
    u8 *dst;
    u8 *tmpl;
    void *name;

    j = 0;
    tmpl = gSystemSave;
    src = tmpl;
    *(u32 *)((u8 *)arg0 + 0x70) = *(u32 *)(tmpl + 0);
    *(u32 *)((u8 *)arg0 + 0x74) = *(u32 *)(tmpl + 4);
    w8 = *(u32 *)(tmpl + 8);
    wC = *(u32 *)(tmpl + 0xC);
    *(u32 *)((u8 *)arg0 + 0x7C) = wC;
    *(u32 *)((u8 *)arg0 + 0x78) = w8;
    *(u16 *)((u8 *)arg0 + 0x80) = *(u16 *)(tmpl + 0x10);
    ((u8 *)arg0)[0xB0] = tmpl[0x40];
    ((u8 *)arg0)[0xB1] = tmpl[0x41];
    ((u8 *)arg0)[0xB2] = tmpl[0x42];
    ((u8 *)arg0)[0xB3] = tmpl[0x43];
    ((u8 *)arg0)[0xB4] = tmpl[0x44];
    ((u8 *)arg0)[0xB7] = tmpl[0x47];
    dst = (u8 *)arg0 + 0x70;
    for (ctr = 5; ctr != 0; ctr--) {
        u8 *p = dst + j + 0x12;
        u8 *s = src + 0x12;
        j += 6;
        p[0] = s[0];
        p[1] = s[1];
        p[2] = s[2];
        p[3] = s[3];
        p[4] = s[4];
        p[5] = s[5];
        src += 6;
    }
    *(u32 *)(dst + 0x3C) = 0;
    *(u32 *)(dst + 0x38) = 0;
    *(u32 *)(dst + 0x34) = 0;
    *(u32 *)(dst + 0x30) = 0;
    src = gSystemSave;
    *(u32 *)(dst + 0x30) |= *(u32 *)(src + 0x30);
    *(u32 *)(dst + 0x34) |= *(u32 *)(src + 0x34);
    *(u32 *)(dst + 0x38) |= *(u32 *)(src + 0x38);
    *(u32 *)(dst + 0x3C) |= *(u32 *)(src + 0x3C);
    best = 0;
    off = 0x2000;
    base = (u8 *)gSaveDataBase;
    for (ctr = 2; ctr != 0; ctr--) {
        clamped = save_slot_size(base + off);
        if (best < clamped) {
            best = save_slot_size(base + off);
        }
        off += 0x4000;
        clamped = save_slot_size(base + off);
        if (best < clamped) {
            best = save_slot_size(base + off);
        }
        off += 0x4000;
        clamped = save_slot_size(base + off);
        if (best < clamped) {
            best = save_slot_size(base + off);
        }
        off += 0x4000;
    }
    clamped = save_slot_size(base + 0x1A000);
    if (best < clamped) {
        best = save_slot_size(base + 0x1A000);
    }
    clamped = save_slot_size(base + 0x20000);
    if (best < clamped) {
        best = save_slot_size(base + 0x20000);
    }
    *(u32 *)((u8 *)arg0 + 0x48) = best + 1;
    j = 0;
    for (ctr = 2; ctr != 0; ctr--) {
        u8 *p = (u8 *)arg0 + j;
        j += 8;
        p[0] = 0x20; p[1] = 0x20; p[2] = 0x20; p[3] = 0x20;
        p[4] = 0x20; p[5] = 0x20; p[6] = 0x20; p[7] = 0x20;
        p = (u8 *)arg0 + j;
        j += 8;
        p[0] = 0x20; p[1] = 0x20; p[2] = 0x20; p[3] = 0x20;
        p[4] = 0x20; p[5] = 0x20; p[6] = 0x20; p[7] = 0x20;
        p = (u8 *)arg0 + j;
        j += 8;
        p[0] = 0x20; p[1] = 0x20; p[2] = 0x20; p[3] = 0x20;
        p[4] = 0x20; p[5] = 0x20; p[6] = 0x20; p[7] = 0x20;
        p = (u8 *)arg0 + j;
        j += 8;
        p[0] = 0x20; p[1] = 0x20; p[2] = 0x20; p[3] = 0x20;
        p[4] = 0x20; p[5] = 0x20; p[6] = 0x20; p[7] = 0x20;
    }
    name = Msg_Expand(gSaveStrings + 0x1C7);
    i = 0;
    for (ctr = 3; ctr != 0; ctr--) {
        if (tmpl[0x12] == 0) break;
        if (tmpl[0x13] == 0) break;
        tmpl += 1;
        if (tmpl[0x13] == 0) break;
        tmpl += 1;
        if (tmpl[0x13] == 0) break;
        tmpl += 1;
        if (tmpl[0x13] == 0) break;
        tmpl += 1;
        if (tmpl[0x13] == 0) break;
        tmpl += 1;
        if (tmpl[0x13] == 0) break;
        tmpl += 1;
        if (tmpl[0x13] == 0) break;
        tmpl += 1;
        if (tmpl[0x13] == 0) break;
        tmpl += 1;
        if (tmpl[0x13] == 0) break;
        tmpl += 1;
        tmpl += 1;
        i += 9;
    }
    fn_8020B294(OSGetTime(), &cal);
    sp10 = 0;
    cal.mon += 1;
    fn_80231E74(sp58, 0x20, gSaveStrings + 0x1D0, cal.mon, cal.mday, cal.year % 100, cal.hour, cal.min, &sp10);
    memcpy(arg0, name, strlen(name));
    memcpy((u8 *)arg0 + 0x20, sp58, strlen(sp58));
    buf = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
    Crc32_InitTable();
    *(u32 *)((u8 *)arg0 + 0x50) = Crc32_Calc(buf, dst, *(s32 *)((u8 *)arg0 + 0x4C) - 0x70);
    fn_800C4588(buf);
    DebugPrint(gSaveStrings + 0x1E9, *(s32 *)((u8 *)arg0 + 0x50));
}
u32 fn_801E417C(void *arg0) {
    u32 size;

    size = *(u32 *)((u8 *)arg0 + 0x48);
    return size & ~-(size > 0x100000U);
}

s32 Save_BumpVersionChecksum(void *slot) {
    void *fn_800C4638(s32, void *, s32);
    void Crc32_InitTable(void);
    u32 Crc32_Calc(void *, void *, s32);
    void fn_800C4588(void *);
    void DebugPrint(char *, ...);
    extern u8 gSaveStrings[];
    void *crcTable;
    u8 *payload;
    u32 ver;

    if ((u32)(*(u32 *)((u8 *)slot + 0x40) + 0xB9BB0000) != 0x384AU) {
        return 0;
    }
    ver = SAVE_VER_20050201;
    payload = (u8 *)slot + SAVE_SLOT_PAYLOAD_OFF;
    *(u32 *)((u8 *)slot + 0x44) = ver;
    if (payload) {
        if ((u32)(*(u32 *)payload + 0xB9BB0000) == 0x384AU) {
            *(u32 *)(payload + 4) = ver;
        }
    }
    crcTable = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
    Crc32_InitTable();
    *(u32 *)((u8 *)slot + 0x50) = Crc32_Calc(crcTable, payload, *(s32 *)((u8 *)slot + 0x4C) - SAVE_SLOT_PAYLOAD_OFF);
    fn_800C4588(crcTable);
    DebugPrint((char *)(gSaveStrings + 0x1E9), *(u32 *)((u8 *)slot + 0x50));
    return 1;
}

#pragma optimization_level 3
s32 Save_IsValid(void *slot) {
    void *fn_800C4638(s32, void *, s32);
    void Crc32_InitTable(void);
    u32 Crc32_Calc(void *, void *, s32);
    void fn_800C4588(void *);
    extern u8 gSaveStrings[];
    void *crcTable;
    u32 sum;
    u8 ok;
    u32 value;

    if (*(u32 *)((u8 *)slot + 0x40) != 0x4645384AU) {
        return 0;
    }
    if (*(u32 *)((u8 *)slot + 0x50) == 0x12345678U) {
        ok = 1;
    } else if (*(u8 *)((u8 *)slot + 0x60) == 1) {
        ok = 1;
    } else {
        crcTable = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
        Crc32_InitTable();
        sum = Crc32_Calc(crcTable, (u8 *)slot + 0x70, *(s32 *)((u8 *)slot + 0x4C) - 0x70);
        fn_800C4588(crcTable);
        if (*(u32 *)((u8 *)slot + 0x50) != sum) {
            ok = 0;
        } else {
            ok = 1;
        }
    }
    value = (u8)ok;
    return ((-value) | value) >> 31;
}
#pragma optimization_level reset
s32 fn_801E434C(void *arg0) {
    if ((u32) (M2C_FIELD(arg0, s32 *, 0x40) + 0xB9BB0000) != 0x384AU) {
        return 0;
    }
    return M2C_FIELD(arg0, s32 *, 0x44) == 0x20050201;
}
extern u8 lbl_80299E10[];
extern u8 gSystemSave[];
#include "global.h"
extern u16 gStreamBaseVtbl[5];
extern u16 lbl_802842B8[6];
extern s16 *gUiUnitPanelStrings;

extern void *gCameraWin;
extern u8 lbl_802986A8[];
extern u16 gWinCondCmdNames[];
extern u16 gUnitLists[];
#include "global.h"

extern s32 gUiInputFlags;
extern f32 lbl_8036B330;
extern f32 lbl_8036B338;
extern f32 lbl_8036B358;
#include "global.h"
#include "m2c.h"

extern u8 gUiSeCues[];
extern f32 lbl_8036B630;
extern f32 lbl_8036B650;
extern f32 lbl_8036B664;
extern f32 lbl_8036B668;
extern f32 lbl_8036B698;
extern f32 lbl_8036B69C;
#include "common.h"
#include "structs.h"

