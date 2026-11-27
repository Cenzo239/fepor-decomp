/* Functions from 0x801B3258 to 0x801E4380, found by decomp-toolkit. */
#include "common.h"
static inline u8 *Battle_FindEligibleUnit(void) {
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

typedef struct StatDisplayTable { u8 pad[0x28]; s16 x[10]; s16 y[10]; u8 order[12]; } StatDisplayTable;
static inline s16 StatDisplay_CoordAt(s16 *coords, s32 index) { return coords[index]; }
static inline u8 StatDisplay_OrderAt(u8 *order, s32 index) { return order[index]; }
static inline s32 Ui_ScrollDirection(s16 value) {
    if (value < 0) return -1;
    return value > 0;
}
static inline u8 Ui_TickMarker(void *pos) {
    s16 *life = (s16 *)((u8 *)pos + 0x10);
    void fn_80067708(s32, s32, void (*)(void), s32);
    void fn_801C65E0(void);
    --*life;
    if (*life <= 0) return 0;
    fn_80067708(2, 1, fn_801C65E0, (s32)pos);
    return 1;
}
#pragma cplusplus on
extern "C" void *Heap_Alloc(s32);
#pragma cplusplus off
static inline s32 AchieveList_GoldAt(void *arg0,s32 i) { return *(s32*)((u8*)arg0+0x200+i*4); }
static inline s32 AchieveList_SumGoldNested(void *arg0,s32 start) {
s32 sum=start, i;
for(i=start;i<*(s32*)((u8*)arg0+0x224);i++) sum+=AchieveList_GoldAt(arg0,i);
return *(s32*)((u8*)arg0+0x228)+sum;
}

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
static inline void InitUnitHireWidgetRect(u8 *w, s16 x, s16 y, s16 width, s16 height) {
extern u8 lbl_8028FDB0[],lbl_80292230[],lbl_8029186C[];
        *(void **)(w+0) = lbl_8028FDB0;
        *(s32 *)(w+4) = 0;
        *(void **)(w+0) = lbl_80292230;
        *(s16 *)(w+8) = -1;
        *(s16 *)(w+0xA) = x;
        *(s16 *)(w+0xC) = y;
        *(s16 *)(w+0xE) = x+width;
        *(s16 *)(w+0x10) = y+height;
        *(s16 *)(w+0x12) = 0;
        *(s16 *)(w+0x14) = 0;
        *(s16 *)(w+0x16) = width;
        *(s16 *)(w+0x18) = height;
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

#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on

#pragma pop

#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
#pragma opt_common_subs off
#pragma opt_loop_invariants off

#pragma pop
#pragma opt_common_subs off

#pragma opt_common_subs reset

#pragma opt_common_subs off

#pragma opt_common_subs reset

/* Advance the EXP bar fill: lerp displayed EXP, play a tick SE on odd frames, clear when finished. */

#pragma global_optimizer off
#pragma opt_common_subs off

#pragma opt_common_subs reset
#pragma global_optimizer reset

#pragma push
#pragma optimization_level 4
#pragma global_optimizer off

#pragma pop
#pragma global_optimizer reset
#pragma global_optimizer off

#pragma global_optimizer reset

#pragma use_lmw_stmw on

/* Return 1 if every player/faction-5 unit has escaped (stateFlags 0x4000); else 0. */

#pragma use_lmw_stmw reset

/* Count enemy units whose job JID is Priest, Bishop, or Saint. */

static inline s32 AchieveList_SumGoldFrom(void *arg0, s32 start) {
    s32 sum = start;
    s32 i;
    for (i = start; i < *(s32 *)((u8 *)arg0 + 0x224); ++i)
        sum += *(s32 *)((u8 *)arg0 + 0x200 + i * 4);
    return *(s32 *)((u8 *)arg0 + 0x228) + sum;
}

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_strength_reduction off

#pragma pop
#pragma global_optimizer off

#pragma global_optimizer reset

extern f32 lbl_8036B228;
#pragma use_lmw_stmw on

#pragma use_lmw_stmw off

#pragma opt_common_subs reset
#pragma opt_loop_invariants off

#pragma use_lmw_stmw on

#pragma use_lmw_stmw off

/* Apply chapter achievement gold to funds; open bonus tally UI when unlocked. */

#pragma global_optimizer off

#pragma use_lmw_stmw on
#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
#pragma global_optimizer off
static inline void Ui_DrawSummaryRows(void *self) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddZ(f32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    void Prim2D_SetTex(s32, s32);
    void *Msg_Expand(void *);
    s32 Text_MeasureWidth(void *, s32, f32);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    void **fn_8006EDD8(void *, s32);
    s32 *Ui_GetColor(s32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void *fn_801B77F0(void *, s32);
    extern const f32 lbl_8036B278, lbl_8036B27C, lbl_8036B280, lbl_8036B284, lbl_8036B288;
    extern const f32 lbl_8036B28C, lbl_8036B290, lbl_8036B294, lbl_8036B298, lbl_8036B29C;
    extern const f32 lbl_8036B2A0, lbl_8036B2A4, lbl_8036B2A8, lbl_8036B2AC, lbl_8036B2B0;
    extern const f32 lbl_8036B2B4, lbl_8036B2B8;
    extern u8 lbl_8027C5E8[];

    f32 baseY;
    s32 i;
    s32 y;
    void *p;
    i = 0;
    baseY = lbl_8036B2AC;
    y = i;
    p = self;
    while (i < *(s32 *)((u8 *)*(void **)((u8 *)self + 0xC) + 0x224)) {
        f32 fy = baseY + (f32)y;
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        fn_8001003C(0x68, (s32)fy, 1, 1, 0, fn_801B77F0(*(void **)((u8 *)self + 0xC), i),
                    lbl_8036B280, lbl_8036B278);
        fn_8001003C(0x19E, (s32)fy, 6, 1, 0, lbl_8027C5E8 + 0x79,
                    lbl_8036B280, lbl_8036B278, *(void **)((u8 *)p + 0x10));
        y += 0x20;
        p = (u8 *)p + 4;
        i += 1;
    }
}

#pragma use_lmw_stmw on
#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma opt_lifetimes off

#pragma pop
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

#pragma push
#pragma optimization_level 4
#pragma opt_lifetimes off
#pragma cplusplus on

#pragma pop
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

#pragma push
#pragma optimization_level 4
#pragma opt_strength_reduction off

#pragma pop

#pragma opt_propagation on

#pragma cplusplus on
#pragma use_lmw_stmw on
/* Allocate the unit-panel caption and position child widgets, or exit if the panel is not ready. */

#pragma cplusplus off
#pragma use_lmw_stmw reset

#pragma cplusplus reset

#pragma optimization_level 3

#pragma cplusplus on

#pragma cplusplus reset

#pragma push
#pragma cplusplus on
#pragma opt_common_subs off

#pragma pop
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
#pragma global_optimizer on

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

#pragma push
#pragma global_optimizer reset

#pragma pop

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma optimization_level 3
static inline void SetHelpText_801C0F54(s32 self, void *msg) {
    u32 Ui_FindChild(s32, s32, s32);
    void Ui_SetWidgetText(u32, void *);
    u32 result = Ui_FindChild(self, -0x1000, 0);
    if (result != 0) {
        Ui_SetWidgetText(result, msg);
    }
}

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
#pragma opt_propagation off

#pragma opt_propagation reset

#pragma global_optimizer off

#pragma global_optimizer off

#pragma global_optimizer on

#pragma push
#pragma optimization_level reset

#pragma pop

#pragma cplusplus on

#pragma cplusplus reset

#pragma opt_common_subs off

#pragma global_optimizer off

#pragma global_optimizer on

extern u8 lbl_8029824C[];

#pragma optimization_level 3

#pragma optimization_level reset

#pragma push
#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma opt_propagation off
#pragma opt_loop_invariants off

#pragma pop

#pragma cplusplus on

#pragma cplusplus off
#pragma push
#pragma optimization_level 3

#pragma pop
#pragma push
#pragma optimization_level 4

#pragma pop

#pragma push
#pragma opt_common_subs off

#pragma pop

#pragma optimization_level 3

/* Copy LightFade source channels onto display lights, release extras, restore fog color. */

#pragma use_lmw_stmw on
/* Fade GX light and fog colors toward the linked unit's target colors over time. */

#pragma use_lmw_stmw reset

extern u32 lbl_8036C510;

extern u8 LightFade_script[];

#pragma opt_common_subs off
#pragma push
static inline void fn_801C77D0_free(void *arg0, s32 zero) {
    void Heap_Free(void *);
    extern u8 LightFade_script[];
    void Process_UnlinkByKey(void *);
    void GActor_UnlinkNodeLink(void);
    void fn_8005376C(void);
    void fn_800C4588(void *);
    void fn_8005FA14(void *, s32);
    void Heap_Free(void *);
    void **walk;
    void **ptr;
    s32 i;
    s32 base;

    base = (s32)LightFade_script;
    Process_UnlinkByKey((void *)(base + 0x54));
    Process_UnlinkByKey((void *)(base + 0x7c));
    GActor_UnlinkNodeLink();
    Process_UnlinkByKey((void *)(base + 0x24));
    fn_8005376C();
    ptr = *(void ***)((u8 *)arg0 + 0x30);
    if (ptr != NULL) {
        fn_800C4588(*ptr);
        walk = ptr;
        *ptr = (void *)zero;
        i = 0;
        *ptr = (void *)zero;
        do {
            if (walk[1] != NULL) {
                fn_8005FA14(walk[1], 0);
                walk[1] = (void *)zero;
            }
            i += 1;
            walk = (void **)((u8 *)walk + 0x14);
        } while (i < 0x20);
        Heap_Free(ptr);
    }
    *(void **)((u8 *)arg0 + 0x30) = 0;
}

#pragma pop
#pragma opt_common_subs on

#pragma use_lmw_stmw on

#pragma push
#pragma optimization_level 4

#pragma pop

#pragma cplusplus on

#pragma cplusplus reset

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off

#pragma pop

#pragma push
#pragma optimization_level 3
#pragma opt_common_subs off
#pragma opt_strength_reduction off

void fn_801C9170(void *arg0) {
    void Process_ClearFunc(void *);
    void Ui_PlaySeCue(void *, s32);
    void fn_801E3560(void *, u8, u8, u8);
    extern char lbl_8027D740[];
    extern u8 gBattleState[];
    extern u8 gSystemSave[];
    extern u8 lbl_80366E9C;
    extern void *gPadInput;
    extern s8 lbl_803682B0;
    extern s8 lbl_803682B1;
    void *self;
    u8 b2;
    u8 b1;
    u8 b0;
    s32 held;
    s32 trig;
    s32 buttons;
    void *obj;

    self = arg0;
    UiMenu_LoadPadState(&b0, &held, &buttons, &trig);

    if ((s8)b0 > -0x14 && (buttons & 0x01000001)) {
        lbl_803682B0 = b0 - 1;
        *(u8 *)((u8 *)self + 0x34) = 1;
        obj = *(void **)((u8 *)self + 0x40);
        *(s16 *)((u8 *)obj + 0x16) = 1;
        *(u8 *)((u8 *)obj + 0xD) = 0;
        Ui_PlaySeCue(lbl_8027D740 + 0xE0, 0x64);
    } else if ((s8)b0 < 0x14 && (buttons & 0x02000002)) {
        lbl_803682B0 += 1;
        *(u8 *)((u8 *)self + 0x34) = 1;
        obj = *(void **)((u8 *)self + 0x44);
        *(s16 *)((u8 *)obj + 0x16) = 1;
        *(u8 *)((u8 *)obj + 0xD) = 0;
        Ui_PlaySeCue(lbl_8027D740 + 0xE0, 0x64);
    }

    b1 = lbl_803682B1;
    if ((s8)b1 > -0xF && (buttons & 0x08000008)) {
        lbl_803682B1 = b1 - 1;
        *(u8 *)((u8 *)self + 0x34) = 1;
        obj = *(void **)((u8 *)self + 0x38);
        *(s16 *)((u8 *)obj + 0x16) = 1;
        *(u8 *)((u8 *)obj + 0xD) = 0;
        Ui_PlaySeCue(lbl_8027D740 + 0xF5, 0x64);
    } else if ((s8)b1 < 0xF && (buttons & 0x04000004)) {
        lbl_803682B1 += 1;
        *(u8 *)((u8 *)self + 0x34) = 1;
        obj = *(void **)((u8 *)self + 0x3C);
        *(s16 *)((u8 *)obj + 0x16) = 1;
        *(u8 *)((u8 *)obj + 0xD) = 0;
        Ui_PlaySeCue(lbl_8027D740 + 0xF5, 0x64);
    }

    b2 = lbl_80366E9C;
    if ((s8)b2 > 0xE && (buttons & 0x40000000)) {
        lbl_80366E9C = b2 - 1;
        *(u8 *)((u8 *)self + 0x34) = 1;
        obj = *(void **)((u8 *)self + 0x4C);
        *(s16 *)((u8 *)obj + 0x16) = 1;
        *(u8 *)((u8 *)obj + 0xD) = 0;
        Ui_PlaySeCue(lbl_8027D740 + 0x10A, 0x64);
    } else if ((s8)b2 < 0x72 && (buttons & 0x80000000)) {
        lbl_80366E9C += 1;
        *(u8 *)((u8 *)self + 0x34) = 1;
        obj = *(void **)((u8 *)self + 0x48);
        *(s16 *)((u8 *)obj + 0x16) = 1;
        *(u8 *)((u8 *)obj + 0xD) = 0;
        Ui_PlaySeCue(lbl_8027D740 + 0x10A, 0x64);
    }

    if (trig & 0x100) {
        fn_801E3560(gSystemSave, lbl_803682B0, lbl_803682B1, lbl_80366E9C);
        b0 = lbl_80366E9C;
        b1 = lbl_803682B1;
        b2 = lbl_803682B0;
        gBattleState[0xA1] = b0;
        gBattleState[0xA3] = b1;
        gBattleState[0xA2] = b2;
        Ui_PlaySeCue(lbl_8027D740 + 0x121, 0x64);
        Process_ClearFunc(self);
    } else if (trig & 0x200) {
        b2 = gBattleState[0xA2];
        b1 = gBattleState[0xA3];
        b0 = gBattleState[0xA1];
        lbl_803682B0 = b2;
        lbl_803682B1 = b1;
        lbl_80366E9C = b0;
        *(u8 *)((u8 *)self + 0x34) = 1;
        Ui_PlaySeCue(lbl_8027D740 + 0x131, 0x64);
        Process_ClearFunc(self);
    }
}
#pragma pop
