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

#pragma pop

s32 fn_801C9704(void) {
    extern s32 gGameRenderModeProg;
    return gGameRenderModeProg;
}

s32 fn_801C970C(void) {
    extern s32 gGameRenderMode;
    return gGameRenderMode;
}

void fn_801C9714(void) {
    extern s32 gGameFlags;
    gGameFlags &= 0xFFFFFFFE;
}

void fn_801C9724(void) {
    extern s32 gGameFlags;
    gGameFlags |= 1;
}

s32 CameraWin_OnCancel(void) {
    s32 String_Compare(void *, u32, u32, char *, u32);
    void String_Assign(void *, void *, u32, u32);
    void fn_800C992C(void *, const char *, u32);
    void fn_800C99A0(void *, void *, u32, u32);
    void String_Destroy(void *, s16);
    void String_ConcatCStr(void *, void *, char *);
    void fn_800DF6DC(void *, s32);
    s32 fn_8011C984(s32, s32);
    s32 fn_8011C9E4(s32);
    void fn_801CA814(s32, void *);
    void fn_801CB25C(void *, s32);
    u32 strlen(const char *);
    extern char CameraWin_str[];
    extern void *gGame;
    extern void *gCameraWin;
    struct Str {
        u32 size;
        u32 cap;
        char *data;
    };
    // Build {gGame}xcam/[dir/]name.dbx from the anime box and write it out.
    struct Str path;
    struct Str dirName;
    struct Str dirTmp;
    struct Str dirSlash;
    struct Str baseName;
    void *win;
    u32 len;

    path.cap = 0;
    win = gCameraWin;
    dirName.cap = 0;
    path.size = 0;
    path.data = 0;
    path.cap = 0;
    dirName.size = 0;
    dirName.data = 0;
    dirName.cap = 0;

    win = (void *)fn_8011C984(*(s32 *)((u8 *)win + 0x430), fn_8011C9E4(*(s32 *)((u8 *)win + 0x430)));

    fn_801CB25C(&dirTmp, (s32)win);
    String_Assign(&dirName, &dirTmp, 0, -1);
    String_Destroy(&dirTmp, -1);
    String_Assign(&path, gGame, 0, -1);

    len = strlen(&CameraWin_str[8]);
    fn_800C992C(&path, (char *)CameraWin_str + 8, len);

    len = strlen((char *)CameraWin_str + 0xE);
    if (String_Compare(&dirName, 0, dirName.size, &CameraWin_str[0xE], len) != 0) {
        String_ConcatCStr(&dirSlash, &dirName, (char *)CameraWin_str + 0xF);
        fn_800C99A0(&path, &dirSlash, 0, -1);
        String_Destroy(&dirSlash, -1);
    }

    fn_800DF6DC(&baseName, (s32)win);
    fn_800C99A0(&path, &baseName, 0, -1);
    String_Destroy(&baseName, -1);

    len = strlen(&CameraWin_str[0x11]);
    fn_800C992C(&path, (char *)CameraWin_str + 0x11, len);

    fn_801CA814((s32)win, &path);
    String_Destroy(&dirName, -1);
    String_Destroy(&path, -1);
    return 0;
}

s32 fn_801C98EC(void) {
    s32 fn_8011C984(s32, s32);
    s32 fn_8011C9E4(s32);
    void fn_801CAF94(s32, s32, s32, s32, s32);
    extern void *gCameraWin;
    void *temp_r31;

    temp_r31 = gCameraWin;
    fn_801CAF94(
        fn_8011C984(M2C_FIELD(temp_r31, s32 *, 0x430), fn_8011C9E4(M2C_FIELD(temp_r31, s32 *, 0x430))),
        0, 0, 0, 1);
    return 0;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
s32 CameraWin_CaptureKeyframe(void) {
    /* Snapshot current camera eye/look-at/FOV and slot id into the selected CameraWin keyframe. */
    void *fn_800DC3B0(void *);
    s32 fn_8011C9E4(s32);
    s32 fn_8011C984(s32, s32);
    void *CameraAnim_GetKeyframe(void *, s32);
    void *CameraAnim_GetCamera(void *);
    void Camera_GetEyePos(f32 *, void *);
    void Camera_GetLookAt(f32 *, void *);
    f32 Camera_GetFov(void *);
    extern void *gCameraWin;

    f32 eyeZ;
    f32 eyeY;
    f32 eyeX;
    f32 lookZ;
    f32 lookY;
    f32 lookX;
    void *keyframe;
    void *cam;
    s32 index;
    f32 eye[3];
    f32 lookAt[3];
    f32 fov;
    u32 slot;

    index = (s32)fn_800DC3B0(*(void **)((u8 *)gCameraWin + 0x438));
    cam = gCameraWin;
    cam = (void *)fn_8011C984(*(s32 *)((u8 *)cam + 0x430), fn_8011C9E4(*(s32 *)((u8 *)cam + 0x430)));
    keyframe = CameraAnim_GetKeyframe(cam, index);
    Camera_GetEyePos(eye, cam = CameraAnim_GetCamera(cam));
    eyeX = eye[0];
    eyeY = eye[1];
    eyeZ = eye[2];
    Camera_GetLookAt(lookAt, cam);
    lookX = lookAt[0];
    lookY = lookAt[1];
    lookZ = lookAt[2];
    fov = Camera_GetFov(cam);
    slot = *(u32 *)((u8 *)*(void **)((u8 *)gCameraWin + 0x42C) + (index << 2));
    *(f32 *)((u8 *)keyframe + 0x00) = eyeX;
    *(f32 *)((u8 *)keyframe + 0x04) = eyeY;
    *(f32 *)((u8 *)keyframe + 0x08) = eyeZ;
    *(f32 *)((u8 *)keyframe + 0x0C) = lookX;
    *(f32 *)((u8 *)keyframe + 0x10) = lookY;
    *(f32 *)((u8 *)keyframe + 0x14) = lookZ;
    *(f32 *)((u8 *)keyframe + 0x18) = fov;
    *(u32 *)((u8 *)keyframe + 0x1C) = slot;
    return 0;
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
s32 fn_801C9A88(void) {
    return 0;
}

s32 fn_801C9A90(void) {
    s32 fn_800DC3B0(s32);
    s32 fn_8011C984(s32, s32);
    s32 fn_8011C9E4(s32);
    void CameraWin_LoadList(void *, s32);
    void fn_801CACE4(void *, s32);
    extern void *gCameraWin;
    s32 temp_r30;
    void *temp_r31;

    temp_r30 = fn_800DC3B0(M2C_FIELD(gCameraWin, s32 *, 0x438));
    temp_r31 = gCameraWin;
    fn_801CACE4((void *)fn_8011C984(M2C_FIELD(temp_r31, s32 *, 0x430), fn_8011C9E4(M2C_FIELD(temp_r31, s32 *, 0x430))), temp_r30);
    CameraWin_LoadList(gCameraWin, fn_8011C9E4(M2C_FIELD(gCameraWin, s32 *, 0x430)));
    return 0;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
s32 fn_801C9B08(void) {
    void *fn_800DC3B0(void *);
    s32 fn_8011C9E4(s32);
    s32 fn_8011C984(s32, s32);
    void *CameraAnim_GetCamera(void *);
    void Camera_GetEyePos(f32 *, void *);
    void Camera_GetLookAt(f32 *, void *);
    f32 Camera_GetFov(void *);
    void fn_801CAD38(s32, s32, void *);
    void CameraWin_LoadList(void *, s32);
    extern void *gCameraWin;

    f32 eyeZ;
    f32 eyeY;
    f32 eyeX;
    f32 lookZ;
    f32 lookY;
    f32 lookX;
    void *handle;
    void *cam;
    s32 index;
    f32 eye[3];
    f32 lookAt[3];
    f32 fov;
    struct {
        f32 eyeX, eyeY, eyeZ;
        f32 lookX, lookY, lookZ;
        f32 fov;
        u32 unk;
    } data;

    index = (s32)fn_800DC3B0(*(void **)((u8 *)gCameraWin + 0x438));
    handle = gCameraWin;
    handle = (void *)fn_8011C984(*(s32 *)((u8 *)handle + 0x430), fn_8011C9E4(*(s32 *)((u8 *)handle + 0x430)));
    Camera_GetEyePos(eye, cam = CameraAnim_GetCamera(handle));
    eyeX = eye[0];
    eyeY = eye[1];
    eyeZ = eye[2];
    Camera_GetLookAt(lookAt, cam);
    lookX = lookAt[0];
    lookY = lookAt[1];
    lookZ = lookAt[2];
    fov = Camera_GetFov(cam);
    data.eyeX = eyeX;
    data.eyeY = eyeY;
    data.eyeZ = eyeZ;
    data.lookX = lookX;
    data.lookY = lookY;
    data.lookZ = lookZ;
    data.fov = fov;
    data.unk = 0x14;
    fn_801CAD38((s32)handle, index, &data);
    CameraWin_LoadList(gCameraWin, fn_8011C9E4(*(s32 *)((u8 *)gCameraWin + 0x430)));
    return 0;
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

s32 fn_801C9C5C(void) {
    s32 fn_800DC3B0(s32);
    s32 fn_8011C984(s32, s32);
    s32 fn_8011C9E4(s32);
    void fn_801CADBC(s32, s32);
    extern void *gCameraWin;
    void *temp_r31;
    s32 temp_r31_2;
    s32 temp_r0;

    temp_r31 = gCameraWin;
    temp_r31_2 = fn_8011C984(M2C_FIELD(temp_r31, s32 *, 0x430), fn_8011C9E4(M2C_FIELD(temp_r31, s32 *, 0x430)));
    temp_r0 = fn_800DC3B0(M2C_FIELD(gCameraWin, s32 *, 0x438));
    fn_801CADBC(temp_r31_2, temp_r0);
    return 0;
}

s32 fn_801C9CBC(void) {
    extern void *gCameraWin;
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void fn_801C9D94(void *, void *);
    void fn_801CAF58(void *, void *);
    s32 fn_8011C984(s32, s32);
    s32 fn_8011C9E4(s32);

    struct Str {
        u32 size;
        u32 cap;
        char *data;
    };
    struct Str sp14;
    struct Str sp8;
    void *obj;
    s32 handle;

    sp14.cap = 0;
    obj = gCameraWin;
    sp14.size = 0;
    sp14.data = 0;
    sp14.cap = 0;

    handle = fn_8011C984(*(s32 *)((u8 *)obj + 0x430),
                         fn_8011C9E4(*(s32 *)((u8 *)obj + 0x430)));

    fn_801C9D94(&sp8, gCameraWin);
    String_Assign(&sp14, &sp8, 0, -1);
    String_Destroy(&sp8, -1);
    fn_801CAF58((void *)handle, &sp14);
    String_Destroy(&sp14, -1);

    return 0;
}

s32 fn_801C9D58(void) {
    s32 fn_8011C9E4(s32);
    void CameraWin_LoadList(void *, s32);
    extern void *gCameraWin;

    s32 temp_r3 = fn_8011C9E4(*(s32 *)((char *)gCameraWin + 0x430));
    CameraWin_LoadList(gCameraWin, temp_r3);
    return 0;
}

void fn_801C9D94(void *dst, void *win) {
    void *__register_global_object(void *, void (*)(void), void *);
    void *String_Init(void *, char *, void *);
    void String_Destroy(void);
    void String_Copy(void *, void *);
    s32 fn_8011C9E4(void *);
    extern char CameraWin_str[];
    extern u8 lbl_80331C88[];
    extern s8 lbl_803682BC;

    typedef struct Str { u32 size; u32 cap; char *data; } Str;
    void *sp18;
    void *sp14;
    void *sp10;
    void *spC;
    void *sp8;
    u8 *base = lbl_80331C88;

    if ((s8)lbl_803682BC == 0) {
        __register_global_object(String_Init(&((Str *)(base + 0x3C))[0], CameraWin_str + 0x21, &sp18),
                                 String_Destroy, &base[0]);
        __register_global_object(String_Init(&((Str *)(base + 0x3C))[1], CameraWin_str + 0x2C, &sp14),
                                 String_Destroy, &base[0xC]);
        __register_global_object(String_Init(&((Str *)(base + 0x3C))[2], CameraWin_str + 0x37, &sp10),
                                 String_Destroy, &base[0x18]);
        __register_global_object(String_Init(&((Str *)(base + 0x3C))[3], CameraWin_str + 0x42, &spC),
                                 String_Destroy, &base[0x24]);
        __register_global_object(String_Init(&((Str *)(base + 0x3C))[4], CameraWin_str + 0x4D, &sp8),
                                 String_Destroy, &base[0x30]);
        lbl_803682BC = 1;
    }
    String_Copy(dst, &((Str *)(base + 0x3C))[fn_8011C9E4(*(void **)((u8 *)win + 0x434))]);
}

#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma global_optimizer off
/* Reload CameraWin anim list for a category and set the camChara side mode. */
void CameraWin_LoadList(void *arg0, s32 arg1) {
    s32 String_Compare(void *, s32, u32, char *, u32);
    void String_AssignCStr(void *, char *, u32);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_Copy(void *, void *);
    void fn_800C9BC4(void *, void *, s32, void *);
    void fn_800DC454(void *);
    void fn_800DC518(void *, void *, void *);
    void fn_800DF6DC(void *, s32);
    s32 fn_8011C984(s32, s32);
    void fn_8011C9A8(s32, s32);
    void fn_801CADBC(s32, s32);
    void *CameraAnim_GetKeyframe(s32, s32);
    s32 fn_801CAF50(void);
    s32 CameraAnim_GetCamera(s32);
    void sprintf(char *, char *, ...);
    u32 strlen(const char *);
    extern char CameraWin_str[];

    struct Str {
        u32 size;
        u32 cap;
        char *data;
    };
    struct Entry {
        u8 pad[0x1C];
        s32 nameId;
    };
    char label[0x30];
    struct Str tempStr;
    struct Str pathStr;
    struct Str listStr;
    struct Str pathTmp;
    void *self;
    s32 handle;
    s32 count;
    struct Entry *entry;
    u32 len;
    char *base;

    self = arg0;
    tempStr.cap = 0;
    pathStr.cap = 0;
    tempStr.size = 0;
    tempStr.data = 0;
    tempStr.cap = 0;
    pathStr.size = 0;
    pathStr.data = 0;
    pathStr.cap = 0;

    fn_800DC454(*(void **)((u8 *)self + 0x438));
    *(s32 *)((u8 *)self + 0x428) = 0;
    handle = fn_8011C984(*(s32 *)((u8 *)self + 0x430), arg1);
    count = fn_801CAF50();
    base = CameraWin_str;
    for (arg1 = 0; arg1 < count; arg1++) {
        entry = (struct Entry *)CameraAnim_GetKeyframe(handle, arg1);
        sprintf(label, base + 0x16, arg1, entry->nameId);
        String_AssignCStr(&tempStr, label, strlen(label));
        String_Copy(&listStr, &tempStr);
        fn_800DC518(*(void **)((u8 *)self + 0x438), &listStr, entry);
        String_Destroy(&listStr, -1);
        fn_800C9BC4((u8 *)self + 0x424,
                    (void *)(*(s32 *)((u8 *)self + 0x42C) + (*(s32 *)((u8 *)self + 0x428) * 4)),
                    1, &entry->nameId);
    }

    fn_800DF6DC(&pathTmp, CameraAnim_GetCamera(handle));
    String_Assign(&pathStr, &pathTmp, 0, -1);
    String_Destroy(&pathTmp, -1);

    len = strlen((char *)((u8 *)CameraWin_str + 0x21));
    if (String_Compare(&pathStr, 0, pathStr.size, (char *)((u32)CameraWin_str + 0x21), len) == 0) {
        fn_8011C9A8(*(s32 *)((u8 *)self + 0x434), 0);
    } else {
        len = strlen((char *)((u8 *)CameraWin_str + 0x2C));
        if (String_Compare(&pathStr, 0, pathStr.size, (char *)((u32)CameraWin_str + 0x2C), len) == 0) {
            fn_8011C9A8(*(s32 *)((u8 *)self + 0x434), 1);
        } else {
            len = strlen((char *)((u8 *)CameraWin_str + 0x37));
            if (String_Compare(&pathStr, 0, pathStr.size, (char *)((u32)CameraWin_str + 0x37), len) == 0) {
                fn_8011C9A8(*(s32 *)((u8 *)self + 0x434), 2);
            } else {
                len = strlen((char *)((u8 *)CameraWin_str + 0x42));
                if (String_Compare(&pathStr, 0, pathStr.size, (char *)((u32)CameraWin_str + 0x42), len) == 0) {
                    fn_8011C9A8(*(s32 *)((u8 *)self + 0x434), 3);
                } else {
                    len = strlen((char *)((u8 *)CameraWin_str + 0x4D));
                    if (String_Compare(&pathStr, 0, pathStr.size, (char *)((u32)CameraWin_str + 0x4D), len) == 0) {
                        fn_8011C9A8(*(s32 *)((u8 *)self + 0x434), 4);
                    }
                }
            }
        }
    }

    fn_801CADBC(handle, 0);
    String_Destroy(&pathStr, -1);
    String_Destroy(&tempStr, -1);
}
#pragma global_optimizer reset
#pragma optimization_level reset
#pragma use_lmw_stmw reset

void fn_801CA1B8(s32 arg0) {
    void CameraWin_LoadList(s32, s32);
    CameraWin_LoadList(arg0, 0);
}

void fn_801CA1DC(void *arg0, s32 arg1) {
    M2C_UNK String_Destroy(M2C_UNK *, M2C_UNK);
    M2C_UNK fn_8011CAAC(s32, M2C_UNK *, s32);
    M2C_UNK fn_801CB280(M2C_UNK *);
    M2C_UNK sp8;

    fn_801CB280(&sp8);
    fn_8011CAAC(M2C_FIELD(arg0, s32 *, 0x430), &sp8, arg1);
    String_Destroy(&sp8, -1);
}

void fn_801CA234(void *arg0, s32 arg1, u32 arg2, u32 arg3)
{
  void fn_800D7254(void *, s32, u32, u32);
  s32 fn_800DC3B0(void *);
  void fn_800DC408(void *, s32, void *);
  void String_AssignCStr(void *, const char *, u32);
  void String_Destroy(void *, s32);
  s32 sprintf(char *, const char *, ...);
  u32 strlen(const char *);
  extern char CameraWin_str[];
  struct String
  {
    u32 size;
    u32 cap;
    char *data;
  };
  char buf_dec[0x30];
  char buf_inc[0x24];
  struct String str_dec;
  struct String str_inc;
  s32 value;
  s32 index;
  void *self;
  self = arg0;
  if (((*((u8 *) (((u8 *) self) + 0x420))) != 0) || ((arg2 & 0x1000) != 0))
  {
    fn_800D7254(self, arg1, arg2, arg3);
  }
  if ((*((s32 *) self)) == 0)
  {
    if ((*((s32 *) (((u8 *) self) + 4))) == 3)
    {
      index = fn_800DC3B0(*((void **) (((u8 *) self) + 0x438)));
      value = (*((s32 **) (((u8 *) self) + 0x42C)))[index];
      if (arg3 & 1)
      {
        value--;
        if (value < 0)
        {
          value = 0;
        }
        str_dec.cap = 0;
        str_dec.size = 0;
        str_dec.data = 0;
        str_dec.cap = 0;
        (*((s32 **) (((u8 *) self) + 0x42C)))[index] = value;
        sprintf(buf_dec, CameraWin_str + 0x16, index, value);
        String_AssignCStr(&str_dec, buf_dec, strlen(buf_dec));
        fn_800DC408(*((void **) (((u8 *) self) + 0x438)), index, &str_dec);
        String_Destroy(&str_dec, -1);
      }
      else
        if (arg3 & 2)
      {
        value++;
        if (value > 0x3E7)
        {
          value = 0x3E7;
        }
        str_inc.cap = 0;
        str_inc.size = 0;
        str_inc.data = 0;
        str_inc.cap = 0;
        (*((s32 **) (((u8 *) self) + 0x42C)))[index] = value;
        sprintf(buf_inc, CameraWin_str + 0x16, (unsigned char) index, value);
        String_AssignCStr(&str_inc, buf_inc, strlen(buf_inc));
        fn_800DC408(*((void **) (((u8 *) self) + 0x438)), index, &str_inc);
        String_Destroy(&str_inc, -1);
      }
    }
  }
}

#pragma cplusplus off
/* Construct the ztool CameraWin window and wire its child controls. */
void *CameraWin_Create(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void fn_801C9B08(void);
    void String_Init(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void String_Destroy(void *, s16);
    void fn_800D764C(void *, s32, s32, s32, void *, void *);
    void *fn_800D75FC(void *, void *);
    void fn_800E3F54(void *);
    extern char CameraWin_str[];
    extern u8 CameraWin_vtable[];
    u32 pathBase[3];
    u32 dbxPath[3];
    u32 winName[3];
    u32 camAnimeBox[3];
    u32 cameraBox[3];
    u32 animeList[3];
    u32 addBtn[3];
    u32 deleteBtn[3];
    u32 clearBtn[3];
    u32 setBtn[3];
    u32 okBtn[3];
    u32 cancelBtn[3];
    void *sp30;
    void *sp2C;
    void *sp28;
    void *sp24;
    void *sp20;
    void *sp1C;
    void *sp18;
    void *sp14;
    void *sp10;
    void *spC;
    void *sp8;
    u8 *self;
    void *ok;
    self = (u8 *)arg0;
    String_Init(pathBase, CameraWin_str + 0x52, &sp30);
    String_ConcatCStr(dbxPath, pathBase, CameraWin_str + 0x59);
    String_Init(winName, CameraWin_str + 0x67, &sp2C);
    fn_800D764C(self, arg1, arg2, arg3, dbxPath, winName);
    String_Destroy(winName, -1);
    String_Destroy(dbxPath, -1);
    String_Destroy(pathBase, -1);
    *(void **)(self + 0xC) = CameraWin_vtable;
    *(u32 *)(self + 0x424) = 0;
    *(u32 *)(self + 0x428) = 0;
    *(u32 *)(self + 0x42C) = 0;
    String_Init(camAnimeBox, CameraWin_str + 0x71, &sp28);
    *(void **)(self + 0x430) = fn_800D75FC(self, camAnimeBox);
    String_Destroy(camAnimeBox, -1);
    String_Init(cameraBox, CameraWin_str + 0x7d, &sp24);
    *(void **)(self + 0x434) = fn_800D75FC(self, cameraBox);
    String_Destroy(cameraBox, -1);
    String_Init(animeList, CameraWin_str + 0x87, &sp20);
    *(void **)(self + 0x438) = fn_800D75FC(self, animeList);
    String_Destroy(animeList, -1);
    String_Init(addBtn, CameraWin_str + 0x91, &sp1C);
    *(void **)(self + 0x43c) = fn_800D75FC(self, addBtn);
    String_Destroy(addBtn, -1);
    String_Init(deleteBtn, CameraWin_str + 0x98, &sp18);
    *(void **)(self + 0x440) = fn_800D75FC(self, deleteBtn);
    String_Destroy(deleteBtn, -1);
    String_Init(clearBtn, CameraWin_str + 0xa2, &sp14);
    *(void **)(self + 0x444) = fn_800D75FC(self, clearBtn);
    String_Destroy(clearBtn, -1);
    String_Init(setBtn, CameraWin_str + 0xab, &sp10);
    *(void **)(self + 0x448) = fn_800D75FC(self, setBtn);
    String_Destroy(setBtn, -1);
    String_Init(okBtn, CameraWin_str + 0xb2, &spC);
    ok = fn_800D75FC(self, okBtn);
    *(void **)(self + 0x44C) = ok;
    *(void **)(self + 0x418) = ok;
    String_Destroy(okBtn, -1);
    String_Init(cancelBtn, CameraWin_str + 0xb8, &sp8);
    *(void **)(self + 0x450) = fn_800D75FC(self, cancelBtn);
    String_Destroy(cancelBtn, -1);
    *(void **)(*(u8 **)(self + 0x430) + 0xFC) = (void *)fn_801C9D58;
    *(void **)(*(u8 **)(self + 0x434) + 0xFC) = (void *)fn_801C9CBC;
    *(void **)(*(u8 **)(self + 0x438) + 0x118) = (void *)fn_801C9C5C;
    *(void **)(*(u8 **)(self + 0x43c) + 0xA4) = (void *)fn_801C9B08;
    *(void **)(*(u8 **)(self + 0x440) + 0xA4) = (void *)fn_801C9A90;
    *(void **)(*(u8 **)(self + 0x444) + 0xA4) = (void *)fn_801C9A88;
    *(void **)(*(u8 **)(self + 0x448) + 0xA4) = (void *)CameraWin_CaptureKeyframe;
    *(void **)(*(u8 **)(self + 0x44c) + 0xA4) = (void *)fn_801C98EC;
    *(void **)(*(u8 **)(self + 0x450) + 0xA4) = (void *)CameraWin_OnCancel;
    *(void **)(self + 0x14) = *(void **)(self + 0x430);
    *(void **)(self + 0x54) = *(void **)(self + 0x434);
    *(void **)(self + 0x94) = *(void **)(self + 0x43c);
    *(void **)(self + 0x98) = *(void **)(self + 0x440);
    *(void **)(self + 0x9c) = *(void **)(self + 0x444);
    *(void **)(self + 0xd4) = *(void **)(self + 0x438);
    *(void **)(self + 0x114) = *(void **)(self + 0x448);
    *(void **)(self + 0x154) = *(void **)(self + 0x44c);
    *(void **)(self + 0x158) = *(void **)(self + 0x450);
    *(void **)(self + 0x414) = *(void **)(self + 0x430);
    fn_800E3F54(*(void **)(self + 0x414));
    return self;
}

void *fn_801CA77C(void *p, s16 n) {
    extern u8 lbl_80298428[];
    void String_Destroy(void *, s32);
    void fn_801CBFD0(void *, s32);
    void fn_800DF724(void *, s32);
    void Heap_Free(void *);
    struct T {
        u8 pad[0x48];
        u8 sub;
    } *t;

    if (p != NULL) {
        t = (struct T *)p;
        *(u8 **)((u8 *)p + 0x40) = lbl_80298428;
        String_Destroy((u8 *)p + 0x60, -1);
        String_Destroy((u8 *)p + 0x54, -1);
        if (&t->sub != NULL) {
            if (&t->sub != NULL) {
                fn_801CBFD0(&t->sub, 0);
            }
        }
        fn_800DF724(p, 0);
        if (n > 0) {
            Heap_Free(p);
        }
    }
    return p;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma opt_strength_reduction off
#pragma cplusplus on
extern "C" void fn_801CA814(void *arg0, void *arg1) {
    u32 strlen(const char *);
    void fn_800C96F8(void *, char *, u32);
    void fn_800CBF24(void *, char *, void *);
    void fn_800CB90C(void *, void *, char *);
    void fn_800C99A0(void *, void *, s32, s32);
    void fn_800C9A60(void *, s16);
    void fn_800C992C(void *, char *, u32);
    char *fn_800C93EC(void *);
    void fn_80231D94(char *, char *, ...);
    void fn_800DF6DC(void *, void *);
    void *fn_800C42D8(s32);
    void *fn_800C4638(s32, char *, s32);
    void fn_8017A430(void *, s32, char *);
    void fn_8017A310(void *, char *);
    extern char lbl_8027DAB0[];
    extern u8 lbl_802842A4[];
    extern u8 lbl_80284C98[];
    struct Str { u32 size; u32 cap; char *data; };
    struct WObj {
        u8 pad[0x10];
        virtual void v0();
        virtual void v1();
        virtual void close(s32);
    };
    struct Str sp2C;
    struct Str sp20;
    struct Str sp14;
    struct Str sp8;
    char sp38[0x40];
    register s32 i;
    char *base;
    u32 len;
    f32 *ent;
    register s32 off;

    sp2C.cap = 0;
    sp2C.size = 0;
    sp2C.data = 0;
    sp2C.cap = 0;
    {
        u32 n = strlen(lbl_8027DAB0);
        fn_800C96F8(&sp2C, lbl_8027DAB0, n);
    }
    fn_800CBF24(&sp20, (char *)lbl_8027DAB0 + 4, (void *)((u8 *)arg0 + 0x54));
    fn_800CB90C(&sp14, &sp20, (char *)((u8 *)lbl_8027DAB0 + 0x1C));
    fn_800C99A0(&sp2C, &sp14, 0, -1);
    fn_800C9A60(&sp14, -1);
    fn_800C9A60(&sp20, -1);
    len = strlen(lbl_8027DAB0);
    fn_800C992C(&sp2C, lbl_8027DAB0, len);
    len = strlen(&lbl_8027DAB0[0x1C]);
    fn_800C992C(&sp2C, (char *)lbl_8027DAB0 + 0x1C, len);
    len = strlen(&lbl_8027DAB0[0x1F]);
    fn_800C992C(&sp2C, (char *)lbl_8027DAB0 + 0x1F, len);
    len = strlen(&lbl_8027DAB0[0x23]);
    fn_800C992C(&sp2C, (char *)lbl_8027DAB0 + 0x23, len);
    fn_80231D94(sp38, (char *)lbl_8027DAB0 + 0x38, fn_800C93EC((u8 *)arg0 + 0x10));
    fn_800C992C(&sp2C, sp38, strlen(sp38));
    fn_80231D94(sp38, (char *)lbl_8027DAB0 + 0x43, fn_800C93EC((u8 *)arg0 + 0x60));
    fn_800C992C(&sp2C, sp38, strlen(sp38));
    fn_80231D94(sp38, (char *)lbl_8027DAB0 + 0x50, fn_800C93EC((void *)((s8 *)arg0 + 0x54)));
    fn_800C992C(&sp2C, sp38, strlen(sp38));
    fn_800DF6DC(&sp8, *(void **)((u8 *)arg0 + 0x6C));
    fn_80231D94(sp38, (char *)lbl_8027DAB0 + 0x5E, fn_800C93EC(&sp8));
    fn_800C9A60(&sp8, -1);
    fn_800C992C(&sp2C, sp38, strlen(sp38));
    fn_80231D94(sp38, (char *)lbl_8027DAB0 + 0x6B, *(s32 *)((u8 *)arg0 + 0x70));
    fn_800C992C(&sp2C, sp38, strlen(sp38));
    base = lbl_8027DAB0;
    off = 0;
    i = 0;
    while (i < *(s32 *)((u8 *)arg0 + 0x70)) {
        ent = (f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + off);
        fn_80231D94(sp38, base + 0x76, *(ent), *(ent + 1), *(ent + 2));
        fn_800C992C(&sp2C, sp38, strlen(sp38));
        fn_80231D94(sp38, base + 0x8F, *(ent + 3), *(ent + 4), *(ent + 5));
        fn_800C992C(&sp2C, sp38, strlen(sp38));
        fn_80231D94(sp38, base + 0xA8, *(ent + 6));
        fn_800C992C(&sp2C, sp38, strlen(sp38));
        fn_80231D94(sp38, base + 0xB5, *(s32 *)(ent + 7));
        fn_800C992C(&sp2C, sp38, strlen(sp38));
        off = off + 0x20;
        i = i + 1;
    }
    len = strlen(&lbl_8027DAB0[0xC0]);
    fn_800C992C(&sp2C, (char *)lbl_8027DAB0 + 0xC0, len);
    len = strlen(&lbl_8027DAB0[0x1C]);
    fn_800C992C(&sp2C, (char *)lbl_8027DAB0 + 0x1C, len);
    len = strlen(&lbl_8027DAB0[0xC4]);
    fn_800C992C(&sp2C, (char *)lbl_8027DAB0 + 0xC4, len);
    if ((arg0 = fn_800C42D8(0x14)) != 0) {
        void *copy = (void *)((u32)arg0 + i - i);
        *(void **)((u8 *)arg0 + 0x10) = lbl_802842A4;
        *(u32 *)((u8 *)arg0 + 4) = 0;
        *(u32 *)arg0 = 0;
        *(u32 *)((u8 *)arg0 + 8) = 0;
        *(u8 *)((u8 *)arg0 + 0xC) = 0;
        *(void **)((u8 *)arg0 + (short)0x10) = lbl_80284C98;
        *(void **)copy = fn_800C4638((short)0x8000, (char *)lbl_8027DAB0 + 0xC8, 0);
        *(void **)((u8 *)copy + 4) = *(void **)copy;
        *(u32 *)((u8 *)copy + 8) = 0x8000;
        *(u8 *)((u8 *)copy + 0xC) = 1;
    }
    {
        char *s = fn_800C93EC(&sp2C);
        fn_8017A430(arg0, sp2C.size, s);
    }
    fn_8017A310(arg0, fn_800C93EC(arg1));
    if (arg0) {
        ((WObj *)arg0)->close(1);
    }
    fn_800C9A60(&sp2C, -1);
}
#pragma cplusplus reset
#pragma opt_strength_reduction reset
#pragma global_optimizer reset
void fn_801CACE4(void *arg0, s32 arg1) {
    if (arg1 < *(s32*)((char*)arg0 + 0x70)) {
        s32 temp_r5 = *(s32*)((char*)arg0 + 0x50);
        fn_801CB7F0((char*)arg0 + 0x48, (void *)(temp_r5 + (arg1 << 5)));
        *(s32*)((char*)arg0 + 0x70) = *(s32*)((char*)arg0 + 0x70) - 1;
    }
}

void fn_801CAD38(void *p,s32 n,s32 v){void fn_801CB934(void*,void*,s32,s32);s32 x=n+1; if(x<*(s32*)((u8*)p+0x70))fn_801CB934((u8*)p+0x48,(u8*)(*(u32*)((u8*)p+0x50)+(x<<5)),1,v);else fn_801CB934((u8*)p+0x48,(u8*)(*(u32*)((u8*)p+0x50)+(*(s32*)((u8*)p+0x4c)<<5)),1,v);(*(s32*)((u8*)p+0x70))++;}

#pragma global_optimizer off
void fn_801CADBC(void *arg0, s32 arg1) {
    u8 Camera_IsEnabled(void *);
    void fn_800DF6DC(void *, void *);
    void fn_800E7B80(s32, void *);
    void String_Destroy(void *, s32);
    void *fn_800E8BB4(void *);
    void fn_800E8BBC(void *, s32);
    void fn_800E8FAC(void *, s32);
    void fn_800E8BF8(void *, f32 *, f32 *, s32, f32);
    struct Str { u32 size; u32 cap; char *data; };
    struct Fl { f32 sp2C; f32 sp30; f32 sp34; f32 sp38; f32 sp3C; f32 sp40; };
    struct Fl fl;
    struct Str sp20;
    f32 sp14[3];
    f32 sp8[3];
    f32 *entry;
    s32 unk0;
    void *child;
    f32 last;

    fl.sp40 = 0.0f;
    unk0 = *(s32 *)arg0;
    fl.sp3C = 0.0f;
    fl.sp38 = 0.0f;
    fl.sp34 = 0.0f;
    fl.sp30 = 0.0f;
    fl.sp2C = 0.0f;
    if (arg1 < *(s32 *)((u8 *)arg0 + 0x70)) {
        entry = (f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + (arg1 << 5));
    } else {
        entry = NULL;
    }
    if (entry != 0 && (u32)*(void **)((u8 *)arg0 + 0x6C) != 0) {
        if (Camera_IsEnabled(*(void **)((u8 *)arg0 + 0x6C)) == 0) {
            fn_800DF6DC(&sp20, *(void **)((u8 *)arg0 + 0x6C));
            fn_800E7B80(unk0, &sp20);
            String_Destroy(&sp20, -1);
        }
        child = fn_800E8BB4(*(void **)((u8 *)arg0 + 0x6C));
        if (child != 0 && (u32)*(void **)((u8 *)child + 0x6C) != 0) {
            *(s32 *)((u8 *)child + 0x74) = -1;
            fn_800E8BBC(*(void **)((u8 *)child + 0x6C), 0);
        }
        fn_800E8FAC(*(void **)((u8 *)arg0 + 0x6C), 0);
        fl.sp38 = entry[0];
        fl.sp3C = entry[1];
        fl.sp40 = entry[2];
        fl.sp2C = entry[3];
        fl.sp30 = entry[4];
        fl.sp34 = entry[5];
        last = entry[6];
        *(u32 *)&sp8[0] = *(u32 *)&fl.sp2C;
        *(u32 *)&sp8[1] = *(u32 *)&fl.sp30;
        *(u32 *)&sp8[2] = *(u32 *)&fl.sp34;
        *(u32 *)&sp14[0] = *(u32 *)&fl.sp38;
        *(u32 *)&sp14[1] = *(u32 *)&fl.sp3C;
        *(u32 *)&sp14[2] = *(u32 *)&fl.sp40;
        fn_800E8BF8(*(void **)((u8 *)arg0 + 0x6C), sp14, sp8, 0, last);
    }
}
#pragma global_optimizer on
s32 CameraAnim_GetKeyframe(void *arg0, s32 arg1) {
    if (arg1 < (s32) M2C_FIELD(arg0, s32 *, 0x70)) {
        return M2C_FIELD(arg0, s32 *, 0x50) + (arg1 << 5);
    }
    return 0;
}

s32 fn_801CAF50(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x70);
}

void fn_801CAF58(void *arg0) {
    s32 fn_800E7F60(s32);
    M2C_FIELD(arg0, s32 *, 0x6C) = fn_800E7F60(M2C_FIELD(arg0, s32 *, 0));
}

s32 CameraAnim_GetCamera(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x6C);
}

#pragma cplusplus on
extern "C" void fn_801CAF94(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 Camera_IsEnabled(void *);
    void fn_800DF6DC(void *, s32);
    void fn_800E7B80(s32, void *);
    void String_Destroy(void *, s32);
    void *fn_800E8BB4(void *);
    void fn_800E8BBC(void *, void *);
    void fn_800E8FAC(void *, s32);
    s32 fn_800E8F00(void *);
    void String_Substr(void *, void *, s32, s32);
    void String_ConcatCStr(void *, void *, char *);
    void String_Assign(void *, void *, s32, s32);
    s32 String_Compare(void *, s32, u32, char *, u32);
    void String_AssignCStr(void *, char *, u32);
    void fn_800C99A0(void *, void *, s32, s32);
    void *String_CStr(void *);
    void fn_800E574C(void *, void *, f32, s32, s32, s32, s32);
    u32 strlen(const char *);
    extern char lbl_8027DAB0[];
    extern f32 lbl_8036B4AC;

    struct Str { u32 size; u32 cap; char *data; };
    struct Obj { u8 pad[0x40]; virtual void m08(s32) = 0; };
    struct Self {
        s32 unk0;
        u8 pad4[0x50];
        s32 unk54;
        u8 pad58[0x14];
        void *unk6C;
        u8 pad70[4];
        s32 unk74;
        s8 unk78;
        s8 unk79;
    };

    struct Str sp44;
    struct Str sp38;
    struct Str sp2C;
    struct Str sp20;
    struct Str sp14;
    struct Str sp8;
    Self *self;
    s32 a1;
    s32 unk0;
    void *child;
    u32 len;

    self = (Self *)arg0;
    a1 = arg1;
    unk0 = self->unk0;
    if (self->unk6C != NULL) {
        if (Camera_IsEnabled(self->unk6C) == 0) {
            fn_800DF6DC(&sp2C, (s32)self->unk6C);
            fn_800E7B80(unk0, &sp2C);
            String_Destroy(&sp2C, -1);
        }
        child = fn_800E8BB4(self->unk6C);
        if (child != NULL && *(u32 *)((u8 *)child + 0x6C) != 0) {
            *(s32 *)((u8 *)child + 0x74) = -1;
            fn_800E8BBC(*(void **)((u8 *)child + 0x6C), NULL);
        }
        fn_800E8FAC(self->unk6C, a1);
        fn_800E8BBC(self->unk6C, self);
        if ((u8)arg4 != 0) {
            sp44.cap = 0;
            sp38.cap = 0;
            sp44.size = 0;
            sp44.data = 0;
            sp44.cap = 0;
            sp38.size = 0;
            sp38.data = 0;
            sp38.cap = 0;
            arg4 = fn_800E8F00(self->unk6C);
            if (arg4 != 0) {
                unk0 = self->unk54;
                String_Substr(&sp20, &self->unk54, unk0 - 2, 2);
                String_ConcatCStr(&sp14, &sp20, lbl_8027DAB0 + 0xC9);
                String_Assign(&sp44, &sp14, 0, -1);
                String_Destroy(&sp14, -1);
                String_Destroy(&sp20, -1);
                len = strlen((char *)lbl_8027DAB0 + 0xCB);
                if (String_Compare(&sp44, 0, sp44.size, &lbl_8027DAB0[0xCB], len) == 0) {
                    len = strlen((char *)lbl_8027DAB0 + 0xCF);
                    String_AssignCStr(&sp44, &lbl_8027DAB0[0xCF], len);
                }
                String_Substr(&sp8, &self->unk54, 5, unk0 - 8);
                String_Assign(&sp38, &sp8, 0, -1);
                String_Destroy(&sp8, -1);
                len = strlen((char *)lbl_8027DAB0 + 0xD3);
                if (String_Compare(&sp38, 0, sp38.size, &lbl_8027DAB0[0xD3], len) == 0) {
                    len = strlen((char *)lbl_8027DAB0 + 0xD8);
                    String_AssignCStr(&sp38, &lbl_8027DAB0[0xD8], len);
                }
                fn_800C99A0(&sp44, &sp38, 0, -1);
                fn_800E574C((void *)arg4, String_CStr(&sp44), lbl_8036B4AC, 0, 1, 0, 0xA);
            }
            String_Destroy(&sp38, -1);
            String_Destroy(&sp44, -1);
        }
        self->unk74 = 0;
        self->unk78 = arg2;
        self->unk79 = arg3;
        ((Obj *)self)->m08(1);
    }
}
#pragma cplusplus reset

void fn_801CB25C(s32 arg0, s32 arg1) {
    String_Copy(arg0, arg1 + 0x60);
}

void fn_801CB280(s32 arg0, s32 arg1) {
    String_Copy(arg0, arg1 + 0x54);
}

void fn_801CB2A4(void *arg0) {
    u8 Camera_IsEnabled(void *);
    u8 fn_800E8BC4(void *);
    void fn_800E8BF8(void *, f32 *, f32 *, s32, f32);
    extern f32 lbl_8036B4B4;
    extern f32 lbl_8036B4B0;
    extern f32 lbl_8036B4B8;

    struct CamEntry {
        f32 ex, ey, ez;
        f32 lx, ly, lz;
        f32 fov;
        u32 slot;
    };
    struct Vec3 { f32 x, y, z; };

    struct Vec3 hi;
    struct Vec3 lo;
    struct Vec3 eyeArg;
    struct Vec3 lookArg;
    void *self;
    struct CamEntry *entry;
    f32 t6;
    u32 slot;

    self = arg0;
    hi.z = 0.0f;
    hi.y = 0.0f;
    hi.x = 0.0f;
    lo.z = 0.0f;
    lo.y = 0.0f;
    lo.x = 0.0f;

    if (*(void **)((u8 *)self + 0x6C) == NULL) {
        return;
    }
    if (*(s32 *)((u8 *)self + 0x74) < 0) {
        return;
    }
    if (Camera_IsEnabled(*(void **)((u8 *)self + 0x6C)) == 0) {
        *(s32 *)((u8 *)self + 0x74) = -1;
        return;
    }
    if (*(s32 *)((u8 *)self + 0x74) != 0) {
        if (fn_800E8BC4(*(void **)((u8 *)self + 0x6C)) != 0) {
            return;
        }
    }

    entry = (struct CamEntry *)(*(u8 **)((u8 *)self + 0x50) + (*(s32 *)((u8 *)self + 0x74) << 5));
    hi.x = entry->ex;
    hi.y = entry->ey;
    hi.z = entry->ez;
    lo.x = entry->lx;
    lo.y = entry->ly;
    lo.z = entry->lz;
    t6 = entry->fov;
    slot = entry->slot;

    if (*(u8 *)((u8 *)self + 0x78) != 0) {
        lo.y = lbl_8036B4B0 - (lo.y - lbl_8036B4B4);
    }
    if (*(u8 *)((u8 *)self + 0x79) != 0) {
        hi.x = hi.x * lbl_8036B4B8;
    }

    lookArg = lo;
    eyeArg = hi;
    fn_800E8BF8(*(void **)((u8 *)self + 0x6C), (f32 *)&eyeArg, (f32 *)&lookArg, (s32)slot, t6);

    *(s32 *)((u8 *)self + 0x74) = *(s32 *)((u8 *)self + 0x74) + 1;
    if (*(s32 *)((u8 *)self + 0x74) >= *(s32 *)((u8 *)self + 0x70)) {
        *(s32 *)((u8 *)self + 0x74) = -1;
    }
}

#pragma push
#pragma cplusplus off
#pragma optimization_level 2
#pragma opt_common_subs off
void *fn_801CB41C(u8 *self, void *arg1, void *arg2) {
void fn_800DF7A0(void *);
void String_Init(void *,void *,void *); void Xml_GetNamedValue(void *,void *,void *);
u32 strlen(void *); void String_AssignCStr(void *,void *,u32); void String_Destroy(void *,s32);
s32 String_Compare(void *,s32,u32,void *,u32); u8 *fn_80117CC0(void *,s32);
void String_Substr(void *,void *,s32,s32); void String_Assign(void *,void *,s32,s32);
void *fn_800E7F60(void *,void *); void Xml_AdvanceChild(void *); void Xml_GetChildValue(void *,void *);
void fn_801CB934(void *,void *,s32,s32);
extern u8 lbl_80298428[],lbl_8027DAB0[];
ParseValue801CB41C p180,p160,p140,p120,p100,pe0,pc0,pa0;
ParseValue801CB41C tmp;
f32 record[8];
String801CB41C str,s48,s3c,s30,s24,s18;
u32 a14,a10,ac,a8;
void *saved;
s32 i;
u32 len;
u8 *s60;

fn_800DF7A0(self);
saved=arg1;
*(void **)(self+0x40)=lbl_80298428;
*(u32 *)(self+0x48)=0; *(u32 *)(self+0x4c)=0; *(u32 *)(self+0x50)=0;
*(u32 *)(self+0x54)=0; *(u32 *)(self+0x58)=0; *(u32 *)(self+0x5c)=0; *(u32 *)(self+0x58)=0;
*(u32 *)(self+0x60)=0; *(u32 *)(self+0x64)=0; *(u32 *)(self+0x68)=0; *(u32 *)(self+0x64)=0;
str.b=0;str.a=0;str.c=0;str.b=0;
String_Init(&s48,lbl_8027DAB0+0xdd,&a14);
Xml_GetNamedValue(&p180,arg2,&s48);arg1=&p180;
String_AssignCStr(self+0x54,arg1,strlen(arg1));String_Destroy(&s48,-1);
String_Init(&s3c,lbl_8027DAB0+0xe5,&a10);
Xml_GetNamedValue(&p160,arg2,&s3c);arg1=&p160;
String_AssignCStr(self+0x60,arg1,strlen(arg1));String_Destroy(&s3c,-1);
len=strlen(lbl_8027DAB0+0xc8);
s60=self+0x60;
if(String_Compare(s60,0,*(u32 *)s60,lbl_8027DAB0+0xc8,len)==0 && (s32)*fn_80117CC0(self+0x54,4)=='_'){
String_Substr(&s30,self+0x54,0,4);String_Assign(self+0x60,&s30,0,-1);String_Destroy(&s30,-1);
}
String_Init(&s24,lbl_8027DAB0+0xec,&ac);
Xml_GetNamedValue(&p140,arg2,&s24);arg1=&p140;
String_AssignCStr(&str,arg1,strlen(arg1));String_Destroy(&s24,-1);
*(void **)(self+0x6c)=fn_800E7F60(saved,&str);
String_Init(&s18,lbl_8027DAB0+0xf3,&a8);
Xml_GetNamedValue(&p120,arg2,&s18);
*(u32 *)(self+0x70)=*(u32 *)&p120;String_Destroy(&s18,-1);
Xml_AdvanceChild(arg2);
for(i=0;i<*(s32 *)(self+0x70);i++){
Xml_GetChildValue(&pa0,arg2);tmp=pa0;
record[0]=tmp.v[0];record[1]=tmp.v[1];record[2]=tmp.v[2];Xml_AdvanceChild(arg2);
Xml_GetChildValue(&pc0,arg2);tmp=pc0;
record[3]=tmp.v[0];record[4]=tmp.v[1];record[5]=tmp.v[2];Xml_AdvanceChild(arg2);
Xml_GetChildValue(&pe0,arg2);record[6]=pe0.v[0];Xml_AdvanceChild(arg2);
Xml_GetChildValue(&p100,arg2);((u32 *)record)[7]=*(u32 *)&p100;Xml_AdvanceChild(arg2);
fn_801CB934(self+0x48,*(u8 **)(self+0x50)+(*(u32 *)(self+0x4c)<<5),1,(s32)record);
}
*(s32 *)(self+0x74)=-1;self[0x78]=0;self[0x79]=0;String_Destroy(&str,-1);
return self;
}
#pragma pop
int fn_801CB7F0(void *arg0, void *arg1, void *unused) {
    u8 *src;
    u8 *dst;
    u8 *end;
    (void)unused;
    end = *(u8 **)((u8 *)arg0 + 8) + (*(s32 *)((u8 *)arg0 + 4) << 5);
    if ((((s32)(end - (u8 *)arg1) / 32) - 1) != 0) {
        src = (u8 *)arg1 + 0x20;
        dst = (u8 *)arg1;
        while (src < end) {
            ((f32 *)dst)[0] = ((f32 *)src)[0];
            ((f32 *)dst)[1] = ((f32 *)src)[1];
            ((f32 *)dst)[2] = ((f32 *)src)[2];
            ((f32 *)dst)[3] = ((f32 *)src)[3];
            ((f32 *)dst)[4] = ((f32 *)src)[4];
            ((f32 *)dst)[5] = ((f32 *)src)[5];
            ((f32 *)dst)[6] = ((f32 *)src)[6];
            ((u32 *)dst)[7] = ((u32 *)src)[7];
            src += 0x20;
            dst += 0x20;
        }
    }
    *(s32 *)((u8 *)arg0 + 4) = *(s32 *)((u8 *)arg0 + 4) - 1;
    return (int)arg1;
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_unroll_loops off
void fn_801CB934(void *arg0, void *arg1, s32 arg2, s32 arg3)
{
    struct Vector32 {
        u32 capacity;
        u32 size;
        u8 *data;
    };
    struct Raw32 {
        u32 w0, w1, w2, w3, w4, w5, w6, w7;
    };
    struct Float32 {
        f32 f0, f1, f2, f3, f4, f5, f6;
        u32 last;
    };

    void fprintf(void *, void *, ...);
    void abort(void);
    void *Heap_Alloc(s32);
    void Heap_Free(void *);
    void fn_801CC030(void *);
    extern u8 __files[];
    extern u8 lbl_8027DAB0[];

    struct Vector32 *vec;
    u8 *fill;
    u32 count;
    u8 *position;
    u8 *end;
    u8 *src;
    u8 *dst;
    u32 required;
    u32 i;

    vec = (struct Vector32 *)arg0;
    position = (u8 *)arg1;
    fill = (u8 *)arg3;
    count = (u32)arg2;

    if (count == 0) {
        return;
    }

    if (count > 0x07FFFFFFU || vec->size > 0x07FFFFFFU - count) {
        fprintf(__files + 0xA0, lbl_8027DAB0 + 0x1A7);
        abort();
    }

    required = vec->size + count;
    if (required <= vec->capacity) {
        u8 *fillPtr = fill;
        s32 after;
        u32 remaining;

        end = vec->data + (vec->size << 5);
        after = (s32)(end - position) / 0x20;

        if (count > (u32)after) {
            u32 extra;
            extra = count - after;
            dst = end;
            for (; count > (u32)after;) {
                if (dst != 0) {
                    *(struct Raw32 *)dst = *(struct Raw32 *)fill;
                }
                vec->size++;
                dst += 0x20;
                count--;
            }

            src = position;
            {
                for (; src < end;) {
                    if (dst != 0) {
                        *(struct Raw32 *)dst = *(struct Raw32 *)src;
                    }
                    vec->size++;
                    src += 0x20;
                    dst += 0x20;
                }
            }
        } else {
            u8 *shiftFrom;
            u8 *shiftTo;

            src = end - (count << 5);
            dst = end;
            for (; src < end;) {
                if (dst != 0) {
                    *(struct Raw32 *)dst = *(struct Raw32 *)src;
                }
                vec->size++;
                src += 0x20;
                dst += 0x20;
            }

            remaining = (u32)after - count;
            shiftFrom = position + (remaining << 5);
            shiftTo = end;

            if ((u32)(end - (remaining << 5)) <= (u32)fill &&
                (u32)fill < (u32)end) {
                fillPtr += count << 5;
            }

            {
                for (; shiftFrom > position;) {
                    shiftFrom -= 0x20;
                    shiftTo -= 0x20;
                    ((struct Float32 *)shiftTo)->f0 = ((struct Float32 *)shiftFrom)->f0;
                    ((struct Float32 *)shiftTo)->f1 = ((struct Float32 *)shiftFrom)->f1;
                    ((struct Float32 *)shiftTo)->f2 = ((struct Float32 *)shiftFrom)->f2;
                    ((struct Float32 *)shiftTo)->f3 = ((struct Float32 *)shiftFrom)->f3;
                    ((struct Float32 *)shiftTo)->f4 = ((struct Float32 *)shiftFrom)->f4;
                    ((struct Float32 *)shiftTo)->f5 = ((struct Float32 *)shiftFrom)->f5;
                    ((struct Float32 *)shiftTo)->f6 = ((struct Float32 *)shiftFrom)->f6;
                    ((struct Float32 *)shiftTo)->last = ((struct Float32 *)shiftFrom)->last;
                }
            }
        }

        dst = position;
        for (i = 0; i < count; i++) {
            ((struct Float32 *)dst)->f0 = ((struct Float32 *)fillPtr)->f0;
            ((struct Float32 *)dst)->f1 = ((struct Float32 *)fillPtr)->f1;
            ((struct Float32 *)dst)->f2 = ((struct Float32 *)fillPtr)->f2;
            ((struct Float32 *)dst)->f3 = ((struct Float32 *)fillPtr)->f3;
            ((struct Float32 *)dst)->f4 = ((struct Float32 *)fillPtr)->f4;
            ((struct Float32 *)dst)->f5 = ((struct Float32 *)fillPtr)->f5;
            ((struct Float32 *)dst)->f6 = ((struct Float32 *)fillPtr)->f6;
            ((struct Float32 *)dst)->last = ((struct Float32 *)fillPtr)->last;
            dst += 0x20;
        }
    } else {
        struct Vector32 tmp;
        u32 newCapacity;
        u8 *allocated;

        tmp.capacity = 0;
        tmp.size = 0;
        tmp.data = 0;

        newCapacity = vec->capacity;
        if (newCapacity == 0) {
            newCapacity = 1;
        }
        while (required > newCapacity) {
            if (newCapacity < 0x03FFFFFFU) {
                newCapacity <<= 1;
            } else {
                newCapacity = 0x07FFFFFFU;
            }
        }

        allocated = Heap_Alloc(newCapacity << 5);
        if (allocated == 0) {
            fprintf(__files + 0xA0, lbl_8027DAB0 + 0x1C4);
            abort();
        }
        tmp.data = allocated;
        tmp.capacity = newCapacity;

        src = vec->data;
        end = src + (vec->size << 5);
        dst = tmp.data;
        {
            for (; src < position;) {
                if (dst != 0) {
                    *(struct Raw32 *)dst = *(struct Raw32 *)src;
                }
                tmp.size++;
                dst += 0x20;
                src += 0x20;
            }
        }

        for (i = 0; i < count; i++) {
            if (dst != 0) {
                *(struct Raw32 *)dst = *(struct Raw32 *)fill;
            }
            tmp.size++;
            dst += 0x20;
        }

        {
            for (; src < end;) {
                if (dst != 0) {
                    *(struct Raw32 *)dst = *(struct Raw32 *)src;
                }
                tmp.size++;
                dst += 0x20;
                src += 0x20;
            }
        }

        if (&tmp != vec) {
            u32 oldCapacity;
            u32 oldSize;
            u8 *oldData;

            oldCapacity = tmp.capacity;
            tmp.capacity = vec->capacity;
            vec->capacity = oldCapacity;
            oldData = tmp.data;
            tmp.data = vec->data;
            vec->data = oldData;
            oldSize = tmp.size;
            tmp.size = vec->size;
            vec->size = oldSize;
        }

        fn_801CC030(&tmp);
        if (tmp.data != 0) {
            Heap_Free(tmp.data);
        }
    }
}
#pragma pop

void *fn_801CBFD0(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    void fn_801CC030(void *);

    if (arg0 != NULL) {
        fn_801CC030(arg0);
        if (M2C_FIELD(arg0, void **, 8) != NULL) {
            Heap_Free(M2C_FIELD(arg0, void **, 8));
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_801CC030(u32 *arg0) {
    u8 *start = (u8 *)arg0[2];
    u8 *end = start + (arg0[1] << 5);
    while (end > start) {
        end -= 0x20;
    }
    arg0[1] = 0;
}

#pragma cplusplus on
extern "C" void fn_801CC068(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
    };
    ((Obj *)arg0)->v6();
}

#pragma global_optimizer off
#pragma peephole off
extern "C" void fn_801CC094(void *arg0) {
    u8 *fn_801CD480(void *, s16, s16);
    void fn_801475FC(void *, s32);
    extern u32 lbl_80367110;
    extern void *lbl_80367240;
    extern f64 lbl_8036B4C0;
    extern u8 lbl_8027DD30[];

    struct Obj {
        virtual void v0() {}
        virtual void v1() {}
        virtual void v2() {}
        virtual void v3() {}
        virtual void v4() {}
        virtual void v5() {}
        virtual void v6() {}
        virtual void v7() {}
        virtual void v8() {}
        virtual void v9() {}
        virtual s16 v10() { return 0; }
        virtual void v11() {}
        virtual s16 v12() { return 0; }
        virtual s16 v13() { return 0; }
        virtual s16 v14() { return 0; }
        u8 *GetCell(s16 x, s16 y) {
            u8 *fn_801CD480(void *, s16, s16);
            return fn_801CD480(*(void **)((u8 *)this + 0x3C), x, y);
        }
    };

    Obj *self;
    u32 held;
    u32 pressed;
    s16 saveX;
    s16 saveY;
    s16 saveTop;

    self = (Obj *)arg0;
    {
        u8 skip = 0;
        if ((lbl_80367110 & 0x10) != 0 && (lbl_80367110 & 0x20) == 0) {
            skip = 1;
        }
        if (skip != 0) {
            return;
        }
    }

    {
        u32 *pad = (u32 *)lbl_80367240;
        u32 buttons = pad[1];
        u32 prev = pad[2];

        saveX = *(s16 *)((u8 *)self + 0x48);
        held = pad[3];
        saveY = *(s16 *)((u8 *)self + 0x4A);
        saveTop = *(s16 *)((u8 *)self + 0x46);
        pressed = buttons & (prev ^ buttons);
    }

    if ((held & 0x01000001) != 0) {
        if (--(*(s16 *)((u8 *)self + 0x48)) < 0) {
            *(s16 *)((u8 *)self + 0x48) = (pressed == held)
                ? (self->v13() - 1)
                : ++(*(s16 *)((u8 *)self + 0x48));
        }
        {
            s8 done = 0;
            s8 dir = -1;
            while (done == 0) {
                s8 ch = (s8)*self->GetCell(*(s16 *)((u8 *)self + 0x48), *(s16 *)((u8 *)self + 0x4A));
                switch (ch) {
                case 0xA:
                    if (pressed == held) {
                        *(s16 *)((u8 *)self + 0x48) = (s16)(self->v13() - dir - 1);
                    } else {
                        dir *= -1;
                    }
                    break;
                case 9:
                    break;
                default:
                    done = 1;
                    break;
                }
                *(s16 *)((u8 *)self + 0x48) += (done == 0) ? dir : 0;
            }
        }
    } else if ((held & 0x02000002) != 0) {
        if (++(*(s16 *)((u8 *)self + 0x48)) >= self->v13()) {
            *(s16 *)((u8 *)self + 0x48) = (pressed == held)
                ? 0
                : --(*(s16 *)((u8 *)self + 0x48));
        }
        {
            s8 done = 0;
            s8 dir = 1;
            while (done == 0) {
                s8 ch = (s8)*self->GetCell(*(s16 *)((u8 *)self + 0x48), *(s16 *)((u8 *)self + 0x4A));
                switch (ch) {
                case 0xA:
                    if (pressed == held) {
                        *(s16 *)((u8 *)self + 0x48) = (s16)(-dir);
                    } else {
                        dir *= -1;
                    }
                    break;
                case 9:
                    break;
                default:
                    done = 1;
                    break;
                }
                *(s16 *)((u8 *)self + 0x48) += (done == 0) ? dir : 0;
            }
        }
    }

    if ((held & 0x08000008) != 0) {
        if (*(s16 *)((u8 *)self + 0x4A) == 0) {
            if (held == pressed) {
                *(s16 *)((u8 *)self + 0x4A) = self->v14() - 1;
                *(s16 *)((u8 *)self + 0x46) =
                    (self->v12() < self->v14()) ? (self->v14() - self->v12()) : 0;
            }
        } else {
            *(s16 *)((u8 *)self + 0x4A) -= 1;
            if (*(s16 *)((u8 *)self + 0x4A) > 0) {
                if (*(s16 *)((u8 *)self + 0x4A) - *(s16 *)((u8 *)self + 0x46) == 0) {
                    *(s16 *)((u8 *)self + 0x46) -= 1;
                    *(f32 *)((u8 *)self + 0x58) = (f32)(-self->v10());
                }
            }
        }
    } else if ((held & 0x04000004) != 0) {
        if (*(s16 *)((u8 *)self + 0x4A) == self->v14() - 1) {
            if (held == pressed) {
                *(s16 *)((u8 *)self + 0x46) = 0;
                *(s16 *)((u8 *)self + 0x4A) = 0;
            }
        } else {
            *(s16 *)((u8 *)self + 0x4A) += 1;
            if (*(s16 *)((u8 *)self + 0x4A) < self->v14() - 1) {
                if (*(s16 *)((u8 *)self + 0x4A) - *(s16 *)((u8 *)self + 0x46) == self->v12() - 1) {
                    *(s16 *)((u8 *)self + 0x46) += 1;
                    *(f32 *)((u8 *)self + 0x58) = (f32)self->v10();
                }
            }
        }
    }

    {
        s8 done = 0;
        s8 dir = -1;
        while (done == 0) {
            s8 ch = (s8)*self->GetCell(*(s16 *)((u8 *)self + 0x48), *(s16 *)((u8 *)self + 0x4A));
            switch (ch) {
            case 0xA:
                dir *= -1;
                break;
            case 9:
                break;
            default:
                done = 1;
                break;
            }
            *(s16 *)((u8 *)self + 0x48) += (done == 0) ? dir : 0;
        }
    }

    if (saveX != *(s16 *)((u8 *)self + 0x48) || saveY != *(s16 *)((u8 *)self + 0x4A) ||
        saveTop != *(s16 *)((u8 *)self + 0x46)) {
        fn_801475FC(lbl_8027DD30 + 8, 0x64);
    }
}
#pragma peephole on
#pragma global_optimizer reset

#pragma push
#pragma optimization_level 4
#pragma opt_lifetimes off
#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void fn_801CC5C4(void *arg0, void *arg1) {
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Ui_DrawLine(s16, s16, s16, s16, s32, u8 *);
    extern f32 lbl_8036B4C8;

    struct Obj {
        virtual void v0() {}
        virtual void v1() {}
        virtual void v2() {}
        virtual void v3() {}
        virtual void v4() {}
        virtual void v5() {}
        virtual void v6() {}
        virtual void v7() {}
        virtual void v8() {}
        virtual s16 v9() { return 0; }
        virtual s16 v10() { return 0; }
        virtual s16 v11() { return 0; }
        virtual void v12() {}
        virtual void v13() {}
    };

    u8 color[4];
    s16 w;
    s16 h;
    s32 x0;
    void *arg;
    void *self;
    s16 y0;

    self = arg0;
    arg = arg1;
    ((Obj *)self)->v3();
    x0 = *(s16 *)((u8 *)self + 0x48);
    y0 = (s16)(*(s16 *)((u8 *)self + 0x4A) - ((Obj *)self)->v11());
    w = ((Obj *)self)->v9();
    h = ((Obj *)self)->v10();
    {
        s16 t3;
        s16 old4c;
        s16 t5;

        t3 = (s16)(x0 * w);
        old4c = *(s16 *)((u8 *)self + 0x4C);
        t5 = (s16)(y0 * h);
        if (old4c == -1 && *(s16 *)((u8 *)self + 0x4E) == -1) {
            *(s16 *)((u8 *)self + 0x4C) = t3;
            *(s16 *)((u8 *)self + 0x4E) = t5;
        } else {
            *(s16 *)((u8 *)self + 0x4C) = (old4c + t3 + 1) >> 1;
            *(s16 *)((u8 *)self + 0x4E) = (*(s16 *)((u8 *)self + 0x4E) + t5 + 1) >> 1;
        }
    }
    x0 = *(s16 *)((u8 *)self + 0x4C);
    {
        s16 py;
        void *ptr;
        bool eq;
        s32 x1;
        s32 y1;
        s16 x2;
        s16 y2;
        u8 alpha;

        py = *(s16 *)((u8 *)self + 0x4E);
        if (*(u32 *)((u8 *)arg + 0x34) != 0) {
            ptr = (*(void ***)((u8 *)arg + 0x38))[2];
        } else {
            ptr = 0;
        }
        eq = (ptr == self);
        if (eq) {
            Prim2D_Begin();
            Prim2D_AddZ(lbl_8036B4C8);
            Prim2D_PrepareTex();
            color[0] = 0x9C;
            x1 = (s16)(x0 + ((w - 0x30) >> 1));
            y1 = (s16)(py + ((h - 0x30) >> 1));
            color[1] = 0x2F;
            x2 = (s16)(x1 + 0x30);
            alpha = 0x80;
            y2 = (s16)(y1 + 0x30);
            color[2] = 0x12;
            if (eq) {
                alpha = 0xFF;
            }
            color[3] = alpha;
            Ui_DrawLine((s16)x1, (s16)(y1 - 1), (s16)x2, (s16)(y1 - 1), *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)x1, (s16)y2, (s16)x2, (s16)y2, *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)(x1 - 1), (s16)y1, (s16)(x1 - 1), (s16)y2, *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)x2, (s16)y1, (s16)x2, (s16)y2, *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)x1, (s16)y1, (s16)x2, (s16)y1, *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)x1, (s16)(y2 - 1), (s16)x2, (s16)(y2 - 1), *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)x1, (s16)y1, (s16)x1, (s16)y2, *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)(x2 - 1), (s16)y1, (s16)(x2 - 1), (s16)y2, *(s32 *)((u8 *)self + 0x34), color);
        }
    }
}
#pragma pop
#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma scheduling on
#pragma push
#pragma cplusplus on
#pragma optimization_level 4
#pragma use_lmw_stmw on
#pragma global_optimizer off
extern "C" void fn_801CC844(void *arg0, void *arg1) {
    struct Obj {
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5(void *) = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual s16 v11() = 0;
        virtual s16 v12() = 0;
        virtual s16 v13() = 0;
        virtual s16 v14() = 0;
        virtual s16 v15() = 0;
        virtual s16 v16() = 0;
        virtual void v17() = 0;
        virtual void v18() = 0;
        virtual void v19() = 0;
        u8 pad4[0xE];
        s16 a12, a14, a16, a18;
        u8 pad1A[0x34 - 0x1A];
        u32 unk34;
        u8 pad38[0x3C - 0x38];
        void *unk3C;
        u8 pad40[0x48 - 0x40];
        s16 unk48, unk4A;
        u8 pad4C[4];
        s16 rect[4];
        f32 unk58;
        u8 pad5C[0x68 - 0x5C];
        u8 unk68;
        u8 pad69[0x90 - 0x69];
        u8 unk90;
    };
    struct Sub {
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11(s32) = 0;
    };
    void fn_8013F748(void *, s16 *, s16 *);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_ScissorFromRect(void *);
    void Prim2D_SetCallback(void (*)(void *), s16 *);
    void Prim2D_SetTex(s32, u16);
    s32 Text_MeasureHeight(s32, f32);
    s32 fn_8001059C(u8 *, s32, f32);
    s32 Text_MeasureWidth(u8 *, s32, f32);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    u8 *fn_801CD480(void *, s16, s16);
    extern const f32 lbl_8036B4CC;
    extern const f32 lbl_8036B4D0;
    extern const f32 lbl_8036B4D4;
    extern const f32 lbl_8036B4D8;
    extern const f32 lbl_8036B4DC;
    extern f32 lbl_80367098[];

    void *arg;
    s16 *rect;
    s16 half;
    s32 scroll;
    s16 sign;
    s16 row;
    s32 endrow;
    s16 col;
    s16 ybase;
    bool same;
    u8 sel;
    f32 scale;
    f32 dx;
    f32 dy;
    u8 *cell;
    s16 x;
    void *ptr;
    s32 rowIndex;
    s16 scrollShort;
    Obj *self;

    self = (Obj *)arg0;
    arg = arg1;
    self->v19();
    self->v5(arg);
    rect = self->rect;
    {
        s16 h = (s16)(self->a18 - self->a14);
        s16 w = (s16)(self->a16 - self->a12);
        rect[0] = 0;
        rect[1] = 0;
        rect[2] = w;
        rect[3] = h;
    }
    fn_8013F748(self, rect, rect);
    rect = self->rect + 2;
    fn_8013F748(self, rect, rect);
    Prim2D_Begin();
    Prim2D_SetCallback(Prim2D_ScissorFromRect, self->rect);
    Prim2D_SetTex(0, (u16)(self->unk34 | 3));
    Prim2D_PrepareTex();

    half = (s16)((self->v12() - Text_MeasureHeight(-1, lbl_8036B4CC)) >> 1);
    scroll = (s32)self->unk58;
    {
        
        f32 fval = self->unk58;
        if (fval < lbl_8036B4D0) {
            f32 value = (f32)self->v12() * lbl_8036B4D4 + self->unk58;
            self->unk58 = value;
            if (value >= -lbl_80367098[0]) {
                self->unk58 = lbl_8036B4D0;
            }
        } else if (fval > lbl_8036B4D0) {
            f32 value = self->unk58 - (f32)self->v12() * lbl_8036B4D4;
            self->unk58 = value;
            if (value <= lbl_80367098[0]) {
                self->unk58 = lbl_8036B4D0;
            }
        }
    }

    sign = Ui_ScrollDirection((s16)scroll);

    if (*(u32 *)((u8 *)arg + 0x34) != 0) {
        ptr = (*(void ***)((u8 *)arg + 0x38))[2];
    } else {
        ptr = 0;
    }
    same = (ptr == self);
    row = (s16)((-sign & ~sign) >> 31);
    if (sign < 0) {
        s32 count = self->v14();
        endrow = count + 1;
    } else {
        s32 count = self->v14();
        endrow = count;
    }

    endrow = (s16)endrow;
    scrollShort = (s16)scroll;
    for (; row < endrow; row++) {
        if ((rowIndex = (s16)row) + self->v13() >= 0) {
            if (self->v16() >= rowIndex + self->v13()) {
                ybase = (s16)(half + (row * self->v12() + scrollShort));
                for (col = 0; col < self->v15(); col++) {
                    sel = 0;
                    if (same != 0 && col == self->unk48 &&
                        self->unk4A == rowIndex + self->v13()) {
                        sel = 1;
                    }
                    if (sel != 0) {
                        scale = lbl_8036B4D8;
                    } else {
                        scale = lbl_8036B4CC;
                    }
                    void *cells = self->unk3C;
                    cell = fn_801CD480(cells, col, (s16)(row + self->v13()));
                    if ((s32)*cell != 9) {
                        s16 center = (s16)((self->v11() - fn_8001059C(cell, -1, lbl_8036B4CC)) >> 1);
                        x = (s16)(center + col * self->v11());
                        dx = lbl_8036B4D0;
                        dy = dx;
                        if (sel != 0) {
                            dx = lbl_8036B4DC *
                                 (f32)(Text_MeasureWidth(cell, -1, lbl_8036B4CC) -
                                       Text_MeasureWidth(cell, -1, scale));
                            dy = lbl_8036B4DC *
                                 (f32)(Text_MeasureHeight(-1, lbl_8036B4CC) -
                                       Text_MeasureHeight(-1, scale));
                        }
                        fn_8001003C((s32)((f32)x + dx), (s32)((f32)ybase + dy), 1, 0, 0,
                                    cell, scale, lbl_8036B4D0);
                    }
                }
            }
        }
    }

    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
    self->unk68 = (u8)(self->v13() > 0);
    {
        s32 diff = self->v16() - self->v14();
        self->unk90 = (u8)(self->v13() < diff);
    }
    ((Sub *)((u8 *)self + 0x5C))->v11(0x10);
    ((Sub *)((u8 *)self + 0x84))->v11(0x10);
}
#pragma pop
#pragma cplusplus off

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_801CCE7C(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
    };
    ((Obj *)arg0)->v2();
}
#pragma cplusplus reset

#pragma optimization_level 1

