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
    if (size > 0x100000U) {
        return 0;
    }
    return size;
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

void fn_801E11AC(void *arg0, s32 arg1, s32 arg2) {
    void fn_800062CC(void *, s32);
    void fn_801E3CA8(void *);
    void Card_RequestWrite(void *, s32, s32, s32, s32);
    extern void *gSaveDataBase;

    s32 i;
    s32 off;
    s32 val;
    s32 self;
    s32 ctr;
    u8 *found;
    u8 hdrOk;
    u8 *best;
    u32 minSize;
    u8 *slot;
    u32 clamped;

    i = 0;
    off = 0x2000;
    val = arg2;
    self = arg1;

    for (ctr = 2; ctr != 0; ctr--) {
        found = (u8 *)gSaveDataBase + off;
        if (*(u32 *)(found + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(found + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
        } else if (val != *(u8 *)(found + 0x62)) {
        } else {
            goto found_slot;
        }
        off += 0x4000;
        found = (u8 *)gSaveDataBase + off;
        if (*(u32 *)(found + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(found + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
        } else if (val != *(u8 *)(found + 0x62)) {
        } else {
            goto found_slot;
        }
        off += 0x4000;
        found = (u8 *)gSaveDataBase + off;
        if (*(u32 *)(found + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(found + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
        } else if (val != *(u8 *)(found + 0x62)) {
        } else {
            goto found_slot;
        }
        off += 0x4000;
        i += 2;
    }
    found = NULL;

found_slot:
    best = NULL;
    i = (s32)best;
    minSize = (u32)-1;
    off = 0x2000;
    for (ctr = 3; ctr != 0; ctr--) {
        slot = (u8 *)gSaveDataBase + off;
        if (*(u32 *)(slot + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(slot + 0x44) != 0x20050201U) {
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
        slot = (u8 *)gSaveDataBase + off;
        if (*(u32 *)(slot + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(slot + 0x44) != 0x20050201U) {
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

    fn_800062CC(best, *(s32 *)(found + 0x4C));
    *(u8 *)(best + 0x62) = (u8)val;
    fn_801E3CA8(best);
    *(u8 *)(best + 0x60) = 1;
    Card_RequestWrite(best, 0x2000, (s32)best - (s32)gSaveDataBase, -1, self);
}
