/* Functions from 0x80103748 to 0x80105504, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
#include "unit.h"

extern u32 gProcesses[];
extern f64 lbl_8036A100;
extern f32 lbl_8036A0F8;
extern u16 lbl_80366E80;

void Status_Clear(void *, u8);

s32 fn_80103748(void) {
    return 0x21;
}

void *fn_80103750(void) {
    extern u16 lbl_802734D0[29];
    return &lbl_802734D0[0x56/2];
}

s32 fn_80103760(void *arg0, s32 arg1) {
    void fn_80016358(void *);
    void Ui_CreateMenu(void *, s32, s32);
    extern u8 lbl_803679B4[8];

    fn_80016358(arg0);
    Ui_CreateMenu(lbl_803679B4, arg1, 0);
    return 4;
}

void *fn_801037A0(void) {
    extern u16 lbl_802734D0[];
    return (u8 *)lbl_802734D0 + 0xa3;
}

s32 fn_801037B0(void) {
    void Status_Clear(void *, u8);
    extern u8 gBattleState[];
    void *p;
    s32 i;

    p = gBattleState + 0x74;
    i = 0;
    do {
        Status_Clear(p, (u8)i);
        i += 1;
    } while (i < 0x40);
    return 6;
}

void *fn_80103808(void) {
    extern u16 lbl_802734D0[];
    return &lbl_802734D0[0xB8 / 2];
}

s32 fn_80103818(void) {
    return 0;
}

/* Init unit-action menu configs if needed, then open the menu on the map UI process. */
s32 Ui_OpenUnitActionMenu(void) {
    s32 Process_FindByName(void *);
    void Process_Goto(s32, s32);
    void Ui_CreateMenu(void *, s32, s32);
    void fn_800A8400(void);
    extern u8 lbl_802734D0[];
    extern u8 gUiMenuDrawVtbl[];
    extern u8 lbl_8028EAD8[];
    extern u8 lbl_8028ED04[];
    extern u8 lbl_8028ED80[];
    extern u8 lbl_8028EDD4[];
    extern u8 lbl_8028EE28[];
    extern u8 lbl_80367964;
    extern void *lbl_80367968;
    extern u8 lbl_8036796C;
    extern void *lbl_80367970;
    extern u8 lbl_80367974;
    extern void *lbl_80367978;
    extern u8 lbl_8036797C;
    extern void *gUiUnitActionMenu[2];
    s32 proc;
    u8 *entry;

    proc = Process_FindByName((u8 *)lbl_802734D0 + 0xC4);
    fn_800A8400();
    Process_Goto(proc, 0);
    if ((s8)lbl_80367964 == 0) {
        entry = lbl_8028EE28;
        lbl_80367968 = entry;
        lbl_80367964 = 1;
    }
    if ((s8)lbl_8036796C == 0) {
        entry = lbl_8028EDD4;
        lbl_80367970 = entry;
        lbl_8036796C = 1;
    }
    if ((s8)lbl_80367974 == 0) {
        entry = lbl_8028ED80;
        lbl_80367978 = entry;
        lbl_80367974 = 1;
    }
    if ((s8)lbl_8036797C == 0) {
        gUiUnitActionMenu[1] = gUiMenuDrawVtbl;
        gUiUnitActionMenu[0] = lbl_8028EAD8;
        gUiUnitActionMenu[1] = lbl_8028ED04;
        lbl_8036797C = 1;
    }
    Ui_CreateMenu(gUiUnitActionMenu, proc, 0);
    return 6;
}

s32 fn_80103918(void) {
    return 0x20;
}

s32 fn_80103920(void) {
    return 0x108;
}

s32 fn_80103928(void) {
    return 0x20;
}

s32 fn_80103930(void) {
    return 0xAC;
}

s32 fn_80103938(void) {
    return 0xA0;
}

void *fn_80103940(void) {
    extern char lbl_802734D0[];
    return &lbl_802734D0[0xCF];
}

s32 fn_80103950(void) {
    return 0;
}

void *fn_80103958(void) {
    extern u16 lbl_802734D0[];
    return &lbl_802734D0[0xF4 / 2];
}

s32 fn_80103968(void) {
    return 0;
}

void *fn_80103970(void) {
    extern char lbl_802734D0[];
    return &lbl_802734D0[0x119];
}

s32 fn_80103980(void) {
    return 0;
}

void *fn_80103988(void) {
    extern u16 lbl_802734D0[];
    return (u8 *)lbl_802734D0 + 0x138;
}

s32 fn_80103998(void) {
    return 0;
}

#pragma optimization_level 3
s32 fn_801039A0(void *, void *, void *arg2) {
    s32 Process_FindByName(void *);
    void Process_Goto(s32, s32);
    void fn_800A8400(void);
    void fn_80168E90(s32);
    extern u8 lbl_802734D0[];
    extern u8 gBattleMap[];
    extern u8 gUiContext[];
    extern u8 gBattleState[];
    s32 proc;
    u8 *map;
    u8 *ui;
    u8 *str;
    f32 f1;
    f32 f0;
    s8 a;
    s8 b;

    if (*(u8 *)((u8 *)arg2 + 0x39) == 2) {
        return 0x10;
    }
    map = gBattleMap;
    ui = gUiContext;
    f1 = *(f32 *)(gBattleState + 0x534);
    str = lbl_802734D0;
    f0 = *(f32 *)(gBattleState + 0x538);
    a = (s8)(s32)f1;
    b = (s8)(s32)f0;
    map = map + a + (b << 6);
    ui[0x14] = map[0xD];
    proc = Process_FindByName(str + 0xC4);
    fn_800A8400();
    Process_Goto(proc, 0);
    fn_80168E90(proc);
    return 6;
}
#pragma optimization_level reset
void *fn_80103A5C(void) {
    extern u16 lbl_802734D0[];
    return (u8 *)lbl_802734D0 + 0x142;
}

s32 fn_80103A6C(void) {
    return 0;
}

s32 fn_80103A74(void) {
    s32 Process_FindByName(void *);
    M2C_UNK Process_Goto(s32, M2C_UNK);
    M2C_UNK fn_800A8400();
    M2C_UNK String_CStr(M2C_UNK *);
    M2C_UNK fn_800C992C(M2C_UNK *, void *, s32);
    M2C_UNK String_Destroy(M2C_UNK *, M2C_UNK);
    M2C_UNK String_Init(M2C_UNK *, void *, M2C_UNK *);
    M2C_UNK BMapAuxiliary_Create(M2C_UNK, s32);
    s32 strlen(void *);
    extern u8 lbl_802734D0[];
    extern u8 gBattleState[];

    s32 temp_r31;
    M2C_UNK spC;
    M2C_UNK sp8;

    temp_r31 = Process_FindByName((char *) &lbl_802734D0 + 0xC4);
    String_Init(&spC, gBattleState + 0x504, &sp8);
    fn_800C992C(&spC, &lbl_802734D0[0x157], strlen((u8 *)lbl_802734D0 + 0x157));
    fn_800A8400();
    Process_Goto(temp_r31, 0);
    BMapAuxiliary_Create(String_CStr(&spC), temp_r31);
    String_Destroy(&spC, -1);
    return 6;
}

void *fn_80103B20(void) {
    extern u16 lbl_802734D0[];
    return (u8 *)lbl_802734D0 + 0x161;
}

s32 fn_80103B30(void) {
    return 0;
}

s32 fn_80103B38(void) {
    s32 Process_FindByName(void *);
    void fn_800A8400(void);
    void Process_Goto(s32, s32);
    void fn_8011AC78(s32);
    extern char lbl_802734D0[];

    s32 temp_r31 = Process_FindByName(lbl_802734D0 + 0xC4);
    fn_800A8400();
    Process_Goto(temp_r31, 0);
    fn_8011AC78(temp_r31);
    return 6;
}

void *fn_80103B8C(void) {
    extern u16 lbl_802734D0[];
    return (char *) &lbl_802734D0 + 0x167;
}

s32 fn_80103B9C(void) {
    return 0;
}

s32 fn_80103BA4(void) {
    s32 Process_FindByName(void *);
    void Process_Goto(s32, s32);
    void Process_CreateChild(void *, s32);
    void fn_800A8400(void);
    extern char lbl_802734D0[];
    extern struct { u8 pad[0x100]; } lbl_8028EB50;
    s32 temp_r31;

    temp_r31 = Process_FindByName(lbl_802734D0 + 0xC4);
    if (temp_r31 != 0) {
        fn_800A8400();
        Process_Goto(temp_r31, 0);
    }
    Process_CreateChild(&lbl_8028EB50, temp_r31);
    return 6;
}

void *fn_80103C04(void) {
    extern u16 lbl_802734D0[];
    return (u8 *)lbl_802734D0 + 0x17b;
}

s32 fn_80103C14(void) {
    return 0;
}

s32 fn_80103C1C(void) {
    s32 Process_FindByName(void *);
    void Process_Goto(s32, s32);
    void Process_CreateChild(void *, s32);
    void fn_800A8400(void);
    extern char lbl_802734D0[];
    extern struct { u8 pad[0x100]; } lbl_8028EB10;
    s32 temp_r31;

    temp_r31 = Process_FindByName(lbl_802734D0 + 0xC4);
    if (temp_r31 != 0) {
        fn_800A8400();
        Process_Goto(temp_r31, 0);
    }
    Process_CreateChild(&lbl_8028EB10, temp_r31);
    return 6;
}

void *fn_80103C7C(void) {
    extern u16 lbl_802734D0[];
    return (u8 *)lbl_802734D0 + 0x18c;
}

s32 fn_80103C8C(void) {
    return 0;
}

s32 fn_80103C94(void) {
    s32 Process_FindByName(void *);
    void Process_Goto(s32, s32);
    void Process_CreateChild(void *, s32);
    void fn_800A8400(void);
    extern char lbl_802734D0[];
    extern struct { u8 pad[0x100]; } lbl_8028EAE8;
    s32 temp_r31;

    temp_r31 = Process_FindByName(lbl_802734D0 + 0xC4);
    if (temp_r31 != 0) {
        fn_800A8400();
        Process_Goto(temp_r31, 0);
    }
    Process_CreateChild(&lbl_8028EAE8, temp_r31);
    return 6;
}

void *fn_80103CF4(void) {
    extern u8 lbl_802734D0[];
    return &lbl_802734D0[0x191];
}

s32 fn_80103D04(void) {
    return 0;
}

s32 fn_80103D0C(void) {
    s32 Process_FindByName(void *);
    void fn_800A8400(void);
    void Process_Goto(s32, s32);
    void fn_80132B00(s32, s32);
    extern char lbl_802734D0[];

    s32 temp_r31 = Process_FindByName(lbl_802734D0 + 0xC4);
    fn_800A8400();
    Process_Goto(temp_r31, 0);
    fn_80132B00(temp_r31, 1);
    return 6;
}

void *fn_80103D64(void) {
    extern u16 lbl_802734D0[];
    return (u8 *)lbl_802734D0 + 0x1a4;
}

s32 fn_80103D74(void) {
    return 0;
}

s32 fn_80103D7C(void) {
void fn_800C3AB0(void *, void *);
s32 Convoy_FindEmpty(void *);
extern char lbl_802734D0[];
extern u8 gConvoy[0x640];
struct { u8 *obj; char *str; } s;
s.obj = gConvoy;
s.str = lbl_802734D0;
while (Convoy_FindEmpty(s.obj) >= 0) {
fn_800C3AB0(s.obj, s.str + 0x1B1);
}
return 6;
}

#pragma global_optimizer on
#pragma opt_propagation on
char *fn_80103DDC(void *arg0, void *arg1) {
    void sprintf(char *, char *, ...);
    extern char lbl_8032BB18[];
    extern char lbl_802734D0[];
    s32 a;
    char *fmt;
    u8 *base;

    a = *(s32 *)((char *)arg0 + 4);
    arg0 = *(void **)((char *)arg1 + 0x18);
    fmt = lbl_802734D0;
    base = (u8 *)*(s32 *)((char *)arg0 + 0x3c);
    sprintf(lbl_8032BB18, fmt + 0x1bf, a, (base + a)[0x14]);
    return lbl_8032BB18;
}
#pragma opt_propagation reset
#pragma global_optimizer reset
s32 fn_80103E30(void) {
    return 0;
}

void *fn_80103E38(void) {
    extern u16 lbl_802734D0[];
    return (u8 *)lbl_802734D0 + 0x1cc;
}

s32 fn_80103E48(void) {
    return 0;
}

#pragma global_optimizer off
char *fn_80103E50(s32 arg0, void *arg1) {
    void sprintf(void *, void *, ...);
    extern char lbl_8032BAF8[];
    extern u8 lbl_802734D0[];
    extern const f32 lbl_8036A0D8;
    f32 value;
    u8 *strings;
    f32 scale;
    scale = lbl_8036A0D8;
    strings = lbl_802734D0;
    value = *(f32 *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg1 + 0x18) + 0x3C) + 0xc);
    sprintf(lbl_8032BAF8, strings + 0x1dc, scale * value);
    return lbl_8032BAF8;
}
#pragma global_optimizer reset
s32 Options_AdjustRatioPad(s32 unused, void *menu) {
    extern void *gPadInput;
    u16 fill;
    void *state;

    /* Left/right pad nudges the option fill count and refreshes fill/scale ratio. */
    state = M2C_FIELD(menu, void **, 0x3C);
    fill = M2C_FIELD(state, u16 *, 0x10);
    if ((fill != 0) && ((u16) M2C_FIELD(state, u16 *, 0x12) < 0xFCU) && (M2C_FIELD(gPadInput, s32 *, 0xC) & 0x01000001)) {
        M2C_FIELD(state, u16 *, 0x10) = (u16) (fill - 1);
        M2C_FIELD(state, u16 *, 0x12) = (u16) (M2C_FIELD(state, u16 *, 0x12) + 1);
        M2C_FIELD(state, f32 *, 0xC) = (f32) ((f32) M2C_FIELD(state, u16 *, 0x10) / M2C_FIELD(state, f32 *, 8));
        M2C_FIELD(state, s8 *, 0x1B) = 1;
    } else if ((fill < 0xC0U) && ((u16) M2C_FIELD(state, u16 *, 0x12) != 0) && (M2C_FIELD(gPadInput, s32 *, 0xC) & 0x02000002)) {
        M2C_FIELD(state, u16 *, 0x10) += 1;
        M2C_FIELD(state, u16 *, 0x12) -= 1;
        M2C_FIELD(state, f32 *, 0xC) = (f32) ((f32) M2C_FIELD(state, u16 *, 0x10) / M2C_FIELD(state, f32 *, 8));
        M2C_FIELD(state, s8 *, 0x1B) = 1;
    }
    return 0;
}

#pragma global_optimizer off
char *fn_80103FA4(s32 arg0, void *arg1) {
s32 sprintf(void *, void *, ...);
extern char lbl_8032BAD8[];
extern u8 lbl_802734D0[];
extern const f32 lbl_8036A0E8;
u8 *strings = lbl_802734D0;
f32 value = *(f32 *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg1 + 0x18) + 0x3C) + 8);
sprintf(lbl_8032BAD8, strings + 0x1EB, value * lbl_8036A0E8);
return lbl_8032BAD8;
}
#pragma global_optimizer reset

s32 Options_AdjustValuePad(s32 unused, void *menu) {
    /* Left/right pad nudges the option float value by ±1 and refreshes derived integer fields. */
    extern void *gPadInput;
    extern f32 lbl_8036A0F0;
    void *state;

    state = M2C_FIELD(menu, void **, 0x3C);
    if ((M2C_FIELD(state, f32 *, 8) > 0.0f) && (M2C_FIELD(gPadInput, s32 *, 0xC) & 0x01000001)) {
        M2C_FIELD(state, f32 *, 8) -= lbl_8036A0F0;
        M2C_FIELD(state, s16 *, 0x10) = (s16) (M2C_FIELD(state, f32 *, 8) * M2C_FIELD(state, f32 *, 0xC));
        M2C_FIELD(state, s16 *, 0x12) = (s16) (M2C_FIELD(state, f32 *, 8) - (f32) M2C_FIELD(state, u16 *, 0x10));
        M2C_FIELD(state, s8 *, 0x1B) = 1;
    } else if ((M2C_FIELD(state, u16 *, 0x10) < 0xC0U) && (M2C_FIELD(state, u16 *, 0x12) < 0x100U) && (M2C_FIELD(gPadInput, s32 *, 0xC) & 0x02000002)) {
        M2C_FIELD(state, f32 *, 8) += lbl_8036A0F0;
        M2C_FIELD(state, s16 *, 0x10) = (s16) (M2C_FIELD(state, f32 *, 8) * M2C_FIELD(state, f32 *, 0xC));
        M2C_FIELD(state, s16 *, 0x12) = (s16) (M2C_FIELD(state, f32 *, 8) - (f32) M2C_FIELD(state, u16 *, 0x10));
        M2C_FIELD(state, s8 *, 0x1B) = 1;
    }
    return 0;
}

void fn_80104134(s32 arg0, s32 arg1) {
    M2C_UNK Stream_Read(s32, M2C_UNK, s32);
    Stream_Read(arg1, 4, arg0);
}

void fn_80104160(s32 arg0, s32 arg1) {
    M2C_UNK Stream_Write(s32, M2C_UNK, s32);
    Stream_Write(arg1, 4, arg0);
}

s32 fn_8010418C(void *arg0, s32 arg1) {
    s32 count;
    u8 *p;

    p = (u8 *)arg0;
    count = 0;
    if ((p[0] >> 5) & 7) {
        count = 1;
    }
    if (arg1 + 1 == count) {
        return 0x1B;
    }

    if ((*(u16 *)p >> 7) & 7) {
        count += 1;
    }
    if (arg1 + 1 == count) {
        return 0x1C;
    }

    if ((p[1] >> 4) & 7) {
        count += 1;
    }
    if (arg1 + 1 == count) {
        return 0x1D;
    }

    p = (u8 *)arg0;
    if ((p[0] >> 2) & 7) {
        count += 1;
    }
    if (arg1 + 1 == count) {
        return 0x1E;
    }

    p = (u8 *)arg0;
    if (p[1] & 7) {
        count += 1;
    }
    if (arg1 + 1 == count) {
        return 0x1F;
    }

    return 0;
}

s32 fn_8010424C(void *arg0) {
    s32 count;
    u8 *p;

    p = (u8 *)arg0;
    count = 0;
    if ((p[0] >> 5) & 7) {
        count = 1;
    }
    if ((*(u16 *)p >> 7) & 7) {
        count += 1;
    }
    if ((p[1] >> 4) & 7) {
        count += 1;
    }
    p = (u8 *)arg0;
    if ((p[0] >> 2) & 7) {
        count += 1;
    }
    p = (u8 *)arg0;
    if (p[1] & 7) {
        count += 1;
    }
    return count;
}

void Unit_SetSkillRank(void *arg0, u32 arg1, s32 arg2) {
    struct { u8 hi:3; u8 lo:5; } *p;
    struct { u16 hi:6; u16 mid:3; u16 lo:7; } *h;
    struct { u8 hi:1; u8 mid:3; u8 lo:4; } *q;
    struct { u8 a:3; u8 b:3; u8 c:2; } *r;
    struct { u8 hi:5; u8 lo:3; } *s;
    struct { u8 hi:3; u8 lo:5; } *t;
    struct { u8 a:3; u8 b:3; u8 c:2; } *u;

    switch (arg1) {
    case 0:
        p = arg0;
        p->hi = arg2;
        break;
    case 2:
        h = arg0;
        h->mid = arg2;
        break;
    case 3:
        q = (void *)((u8 *)arg0 + 1);
        q->mid = arg2;
        break;
    case 4:
        r = arg0;
        r->b = arg2;
        break;
    case 5:
        s = (void *)((u8 *)arg0 + 1);
        s->lo = arg2;
        break;
    case 14:
        t = (void *)((u8 *)arg0 + 2);
        t->hi = arg2;
        break;
    case 15:
        u = (void *)((u8 *)arg0 + 2);
        u->b = arg2;
        break;
    }
}

/* Return the packed weapon-rank nibble for kind (0-15); 0 if unused, -1 if out of range. */
s32 Unit_GetSkillRank(void *ranks, u32 kind) {
    struct { u8 hi:3; u8 lo:5; } *p;
    struct { u16 hi:6; u16 mid:3; u16 lo:7; } *h;
    struct { u8 hi:1; u8 mid:3; u8 lo:4; } *q;
    struct { u8 a:3; u8 b:3; u8 c:2; } *r;
    struct { u8 hi:5; u8 lo:3; } *s;
    struct { u8 hi:3; u8 lo:5; } *t;
    struct { u8 a:3; u8 b:3; u8 c:2; } *u;

    switch (kind) {
    case 0:
        p = ranks;
        return p->hi;
    case 1:
        return 0;
    case 2:
        h = ranks;
        return h->mid;
    case 3:
        q = (void *)((u8 *)ranks + 1);
        return q->mid;
    case 4:
        r = ranks;
        return r->b;
    case 5:
        s = (void *)((u8 *)ranks + 1);
        return s->lo;
    case 6:
        return 0;
    case 7:
        return 0;
    case 8:
        return 0;
    case 9:
        return 0;
    case 10:
        return 0;
    case 11:
        return 0;
    case 12:
        return 0;
    case 13:
        return 0;
    case 14:
        t = (void *)((u8 *)ranks + 2);
        return t->hi;
    case 15:
        u = (void *)((u8 *)ranks + 2);
        return u->b;
    }
    return -1;
}

extern u32 lbl_8028F210[];
s32 fn_801043FC(s32 arg0) {
    return lbl_8028F210[arg0];
}

void fn_80104410(void *arg0) {
    struct { u8 hi:3; u8 lo:5; } *p;
    struct { u16 hi:6; u16 mid:3; u16 lo:7; } *h;
    struct { u8 hi:1; u8 mid:3; u8 lo:4; } *q;
    struct { u8 a:3; u8 b:3; u8 c:2; } *r;
    struct { u8 hi:5; u8 lo:3; } *s;
    struct { u8 hi:3; u8 lo:5; } *t;
    struct { u8 a:3; u8 b:3; u8 c:2; } *u;

    p = arg0;
    p->hi = 0;
    h = arg0;
    h->mid = 0;
    q = (void *)((u8 *)arg0 + 1);
    q->mid = 0;
    r = arg0;
    r->b = 0;
    s = (void *)((u8 *)arg0 + 1);
    s->lo = 0;
    t = (void *)((u8 *)arg0 + 2);
    t->hi = 0;
    u = (void *)((u8 *)arg0 + 2);
    u->b = 0;
}

void fn_8010446C(u8 *arg0) {
    struct {
        u8 hi : 3;
        u8 lo : 5;
    } *p = (void *)arg0;
    p->hi = 0;
}

void fn_80104480(void *arg0) {
    struct { u8 hi:3; u8 lo:5; } *p;
    struct { u16 hi:6; u16 mid:3; u16 lo:7; } *h;
    struct { u8 hi:1; u8 mid:3; u8 lo:4; } *q;
    struct { u8 a:3; u8 b:3; u8 c:2; } *r;
    struct { u8 hi:5; u8 lo:3; } *s;

    p = arg0;
    p->hi = 0;
    h = arg0;
    h->mid = 0;
    q = (void *)((u8 *)arg0 + 1);
    q->mid = 0;
    r = arg0;
    r->b = 0;
    s = (void *)((u8 *)arg0 + 1);
    s->lo = 0;
}

u32 fn_801044C4(void *arg0) {
    s32 temp_r4;

    temp_r4 = ((u8) M2C_FIELD(arg0, u8 *, 2) >> 5U) & 7;
    return (u32) ((7 - temp_r4) | (temp_r4 - 7)) >> 0x1FU;
}

u32 fn_801044E0(void *arg0) {
    s32 temp_r4;

    temp_r4 = ((u8) M2C_FIELD(arg0, u8 *, 2) >> 2U) & 7;
    return (u32) ((4 - temp_r4) | (temp_r4 - 4)) >> 0x1FU;
}

s32 fn_801044FC(u8 *arg0) {
    u8 b0;
    u8 b1;

    b0 = arg0[0];
    if ((b0 >> 5) & 7) {
        return 1;
    }
    if ((*(u16 *)arg0 >> 7) & 7) {
        return 1;
    }
    b1 = arg0[1];
    if ((b1 >> 4) & 7) {
        return 1;
    }
    if ((b0 >> 2) & 7) {
        return 1;
    }
    return (b1 & 7) != 0;
}

/* Decrement packed skill-rank counters: mode 1 ticks all combat ranks, mode 0 ticks rank slot 5 only. */
void Unit_DecSkillRanks(void *ranks, u8 mode) {
    typedef struct {
        u8 hi:5;
        u8 cnt:3;
    } Lo3;
    u8 *p;
    u8 b;
    u16 h;
    s32 v;

    p = (u8 *)ranks;
    switch ((s32)mode) {
    case 1:
        b = p[0];
        v = (b >> 5U) & 7;
        if (v != 0) {
            p[0] = (u8)((b & ~0xE0) | (((v - 1) << 5) & 0xE0));
        }
        h = *(u16 *)p;
        v = (h >> 7U) & 7;
        if (v != 0) {
            *(u16 *)p = (u16)((h & ~0x380) | (((v - 1) << 7) & 0x380));
        }
        p = (u8 *)ranks;
        b = p[1];
        v = (b >> 4U) & 7;
        if (v != 0) {
            p[1] = (u8)((b & ~0x70) | (((v - 1) << 4) & 0x70));
        }
        p = (u8 *)ranks;
        b = p[0];
        v = (b >> 2U) & 7;
        if (v != 0) {
            p[0] = (u8)((b & ~0x1C) | (((v - 1) << 2) & 0x1C));
        }
        p = (u8 *)ranks;
        b = p[2];
        v = (b >> 5U) & 7;
        if (v != 0) {
            p[2] = (u8)((b & ~0xE0) | (((v - 1) << 5) & 0xE0));
        }
        p = (u8 *)ranks;
        b = p[2];
        v = (b >> 2U) & 7;
        if (v != 0) {
            p[2] = (u8)((b & ~0x1C) | (((v - 1) << 2) & 0x1C));
        }
        return;
    case 0:
        p = (u8 *)ranks;
        b = p[1];
        v = b & 7;
        if (v != 0) {
            ((Lo3 *)&p[1])->cnt = v - 1;
        }
        break;
    }
}

s32 fn_80104628(void *ranks, u8 mode) {
    typedef struct {
        u8 hi : 5;
        u8 cnt : 3;
    } Lo3;
    struct {
        u8 hi : 3;
        u8 lo : 5;
    } *p0;
    struct {
        u16 hi : 6;
        u16 mid : 3;
        u16 lo : 7;
    } *h;
    struct {
        u8 hi : 1;
        u8 mid : 3;
        u8 lo : 4;
    } *q;
    struct {
        u8 a : 3;
        u8 b : 3;
        u8 c : 2;
    } *r;
    struct {
        u8 hi : 5;
        u8 lo : 3;
    } *s;
    u8 *p;
    u8 b;
    u16 hw;
    s32 v;
    s32 n;
    u32 copy;

    n = 0;
    p0 = ranks;
    if (p0->hi != 0) {
        n = 1;
    }
    h = ranks;
    if (h->mid != 0) {
        n += 1;
    }
    q = (void *)((u8 *)ranks + 1);
    if (q->mid != 0) {
        n += 1;
    }
    r = ranks;
    if (r->b != 0) {
        n += 1;
    }
    s = (void *)((u8 *)ranks + 1);
    if (s->lo != 0) {
        n += 1;
    }
    if (n == 0) {
        return 0;
    }

    copy = *(u32 *)ranks;
    p = (u8 *)&copy;
    switch ((s32)mode) {
    case 1:
        b = p[0];
        v = (b >> 5U) & 7;
        if (v != 0) {
            p[0] = (u8)((b & ~0xE0) | (((v - 1) << 5) & 0xE0));
        }
        hw = *(u16 *)p;
        v = (hw >> 7U) & 7;
        if (v != 0) {
            *(u16 *)p = (u16)((hw & ~0x380) | (((v - 1) << 7) & 0x380));
        }
        b = p[1];
        v = (b >> 4U) & 7;
        if (v != 0) {
            p[1] = (u8)((b & ~0x70) | (((v - 1) << 4) & 0x70));
        }
        b = p[0];
        v = (b >> 2U) & 7;
        if (v != 0) {
            p[0] = (u8)((b & ~0x1C) | (((v - 1) << 2) & 0x1C));
        }
        b = p[2];
        v = (b >> 5U) & 7;
        if (v != 0) {
            p[2] = (u8)((b & ~0xE0) | (((v - 1) << 5) & 0xE0));
        }
        b = p[2];
        v = (b >> 2U) & 7;
        if (v != 0) {
            p[2] = (u8)((b & ~0x1C) | (((v - 1) << 2) & 0x1C));
        }
        break;
    case 0:
        b = p[1];
        v = b & 7;
        if (v != 0) {
            ((Lo3 *)&p[1])->cnt = v - 1;
        }
        break;
    }

    n = 0;
    p0 = (void *)&copy;
    if (p0->hi != 0) {
        n = 1;
    }
    h = (void *)&copy;
    if (h->mid != 0) {
        n += 1;
    }
    q = (void *)((u8 *)&copy + 1);
    if (q->mid != 0) {
        n += 1;
    }
    r = (void *)&copy;
    if (r->b != 0) {
        n += 1;
    }
    s = (void *)((u8 *)&copy + 1);
    if (s->lo != 0) {
        n += 1;
    }
    if (n == 0) {
        return 1;
    }
    return 0;
}

s32 fn_801047D0(void) {
    extern void *lbl_803679C0;
    return *(s32 *)((char *)lbl_803679C0 + 0x4);
}

#pragma cplusplus on
extern "C" s32 fn_801053E4(s32,s32,u16 *,void *);
extern "C" s32 fn_80105474(s32,s32,void *,void *);
extern "C" u32 fn_80104930(u16 *,u16);
extern "C" void *fn_801047DC(u8 *arg0) {
    u16 sp8;
    u8 is_double;
    u16 code;
    void **ctx;
    void *base;
    void *end;
    void *start;
    void *entry;
    extern void *lbl_803679C0;
    if (((arg0[0]>=0x81U && arg0[0]<=0x9FU)||(arg0[0]>=0xE0U && arg0[0]<=0xFCU)) &&
       ((arg0[1]>=0x40U && arg0[1]<=0x7EU)||(arg0[1]>=0x80U && arg0[1]<=0xFCU))) is_double=1;
    else is_double=0;
    if(is_double) {
        code=arg0[1];
        code=((s32)*(s8 *)arg0 << 8 & 0xFF00) | code;
    } else code=*(s8 *)arg0 & 0xFF;
    sp8=code;
    ctx=(void **)lbl_803679C0;
    if(*(u16 *)ctx[3]!=code) {
        base=ctx[1];
        start=(u8 *)base+*(u16 *)((u8 *)base+0x22);
        end=(u8 *)start+((s32)ctx[2]<<4);
        ctx[3]=(void *)fn_801053E4((s32)start,(s32)end,&sp8,(void *)fn_80104930);
        entry=ctx[3];
        if(end==entry || *(u16 *)entry!=sp8) {
            ctx[3]=(void *)fn_80105474((s32)start,(s32)end,&lbl_80366E80,(void *)fn_80104930);
            entry=ctx[3];
            if(end==entry || *(u16 *)entry!=0x8199U) ctx[3]=start;
        }
    }
    return ctx[3];
}
#pragma cplusplus off
u32 fn_80104930(u16 *arg0, u16 arg1) {
    return *arg0 < arg1;
}

s32 fn_80104944(void) {
    extern s32 lbl_803679C0;
    return lbl_803679C0;
}

extern void* lbl_803679C0;
extern u8 lbl_8032BB44[20];
void* fn_8010494C(void* arg0) {
    void* temp_r0 = lbl_803679C0;
    
    if (arg0 != NULL) {
        lbl_803679C0 = arg0;
    } else {
        lbl_803679C0 = &lbl_8032BB44;
    }
    
    return temp_r0;
}

u8 *fn_80104970(u8 *arg0)
{
    u8 flag;
    u8 c = arg0[0];
    if (((c >= 0x81 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) &&
        ((arg0[1] >= 0x40 && arg0[1] <= 0x7E) || (arg0[1] >= 0x80 && arg0[1] <= 0xFC))) {
        flag = 1;
    } else {
        flag = 0;
    }
    return arg0 + (flag ? 2 : 1);
}

#pragma opt_strength_reduction off
#pragma use_lmw_stmw on
void *fn_801049E0(u8 *arg0, void **arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5)
{
    u16 sp8;
    void **ctx = lbl_803679C0;
    u8 is_double;
    u8 *next;
    u16 code;
    void *base;
    void *end;
    void *start;
    void *entry;
    f32 width;
    s32 fn_801053E4(s32, s32, u16 *, void *);
    s32 fn_80105474(s32, s32, void *, void *);

    if (((arg0[0] >= 0x81U && arg0[0] <= 0x9FU) || (arg0[0] >= 0xE0U && arg0[0] <= 0xFCU))
        && ((arg0[1] >= 0x40U && arg0[1] <= 0x7EU) || (arg0[1] >= 0x80U && arg0[1] <= 0xFCU))) {
        is_double = 1;
    } else {
        is_double = 0;
    }

    if (is_double != 0) {
        u16 trail = *(u8 *)(arg0 + 1);
        s8 lead = *(s8 *)((u8 *)arg0 + 0);
        next = arg0 + 2;
        code = (u16)(((lead << 8) & 0xFF00) | trail);
    } else {
        code = *(u8 *)arg0;
        next = arg0 + 1;
    }
    sp8 = code;

    if (*(u16 *)ctx[3] != code) {
        base = ctx[1];
        start = (u8 *)base + *(u16 *)((u8 *)base + 0x22);
        end = (u8 *)start + ((s32)ctx[2] << 4);
        ctx[3] = (void *)fn_801053E4((s32)start, (s32)end, &sp8, fn_80104930);
        entry = ctx[3];
        if (end == entry || *(u16 *)entry != sp8) {
            ctx[3] = (void *)fn_80105474((s32)start, (s32)end, &lbl_80366E80, fn_80104930);
            entry = ctx[3];
            if (end == entry || *(u16 *)entry != 0x8199U) {
                ctx[3] = start;
            }
        }
    }

    {
        u8 *temp_r5;
        u8 *temp_r6;
        u32 tmp;

        temp_r5 = ctx[3];
        *arg4 = (s8)temp_r5[0xC];
        temp_r6 = ctx[1];
        tmp = *(u32 *)(temp_r6 + 0x24) + *(u16 *)(temp_r5 + 2) * *(u32 *)(temp_r6 + 0x14);
        *arg1 = (void *)((u32)temp_r6 + tmp);
        *arg2 = *(u16 *)(temp_r5 + 4);
        *arg3 = *(u16 *)(temp_r5 + 6);
    }

    if (*(u16 *)((void **)lbl_803679C0)[3] & 0xFF00) {
        width = (f32)*arg4;
    } else {
        width = lbl_8036A0F8 * (f32)(s32)*(u16 *)((u8 *)((void **)lbl_803679C0)[1] + 0xC);
    }
    *arg5 = (s32)width;
    return next;
}
#pragma opt_strength_reduction reset

#pragma push
#pragma use_lmw_stmw on
#pragma scheduling off
void *fn_80104BF4(u8 *arg0, void **arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    u16 sp8;
    u8 is_double;
    u16 code;
    void **ctx;
    u8 *next;
    void *base;
    void *end;
    void *start;
    u8 *entry;
    s32 fn_801053E4(s32, s32, u16 *, void *);
    s32 fn_80105474(s32, s32, void *, void *);
    u32 fn_80104930(u16 *, u16);
    extern void *lbl_803679C0;

    ctx = lbl_803679C0;
    if (((arg0[0] >= 0x81U && arg0[0] <= 0x9FU) || (arg0[0] >= 0xE0U && arg0[0] <= 0xFCU)) &&
        ((arg0[1] >= 0x40U && arg0[1] <= 0x7EU) || (arg0[1] >= 0x80U && arg0[1] <= 0xFCU))) {
        is_double = 1;
    } else {
        is_double = 0;
    }
    if (is_double) {
        code = arg0[1];
        next = arg0 + 2;
        code = ((s32)*(s8 *)arg0 << 8 & 0xFF00) | code;
    } else {
        code = *(s8 *)arg0 & 0xFF;
        next = arg0 + 1;
    }
    sp8 = code;
    if (*(u16 *)ctx[3] != code) {
        base = ctx[1];
        start = (u8 *)base + *(u16 *)((u8 *)base + 0x22);
        end = (u8 *)start + ((s32)ctx[2] << 4);
        ctx[3] = (void *)fn_801053E4((s32)start, (s32)end, &sp8, fn_80104930);
        entry = ctx[3];
        if (end == entry || *(u16 *)entry != sp8) {
            ctx[3] = (void *)fn_80105474((s32)start, (s32)end, &lbl_80366E80, fn_80104930);
            entry = ctx[3];
            if (end == entry || *(u16 *)entry != 0x8199U) {
                ctx[3] = start;
            }
        }
    }
    entry = ctx[3];
    *arg4 = *(s8 *)(entry + 12);
    {
        u32 *b = ctx[1];
        *arg1 = (void *)((u8 *)b + b[9] + *(u16 *)(entry + 2) * b[5]);
    }
    *arg2 = *(u16 *)(entry + 4);
    *arg3 = *(u16 *)(entry + 6);
    return next;
}
#pragma pop
s32 fn_80104D90(void)
{
  void *FileCache_Load(void *);
  extern u8 lbl_80273788[];
  extern u8 lbl_8032BB44[20];
  extern void *lbl_803679C0;
  u8 *file;
  u8 **new_var;
  u8 *new_var2;
  u8 *ctx;
  u16 sum;
  u16 off;
  u32 n;
  u16 *p;
  file = FileCache_Load(lbl_80273788);
  ctx = lbl_8032BB44;
  *((u8 **) (lbl_8032BB44 + 4)) = file;
  sum = (*((u16 *) (file + 0x8))) + (*((u16 *) (file + 0xA)));
  *((u16 *) (file + 0x12)) = sum;
  *((u16 *) (file + 0x10)) = sum;
  off = (unsigned int) (*((u16 *) (file + 0x22)));
  n = (*((u32 *) (ctx + 8)) = ((*((u32 *) (file + 0x24))) - off) >> 4);
  p = (u16 *) (((*((u8 **) (ctx + 4))) + off) + ((n - 1) * 0x10));
  while ((*p) == 0)
  {
    p = (u16 *) (((u8 *) p) - 0x10);
    *((u32 *) (ctx + 8)) -= 1;
  }

  new_var = &(*((u8 **) (ctx + 4)));
  file++;
  file--;
  off = *((u16 *) (file + 0x22));
  new_var2 = *new_var;
  lbl_803679C0 = lbl_8032BB44;
  *((u8 **) (lbl_8032BB44 + 0xC)) = new_var2 + off;
  return 1;
}

u32 fn_80104E40(void) {
    extern void *lbl_803679C0;
    u8 *ptr;

    ptr = *(u8 **)((u8 *)lbl_803679C0 + 0x4);

    return *(u16 *)(ptr + 0x8) + *(u16 *)(ptr + 0xA);
}

extern void *lbl_803679C0;
u16 fn_80104E58(void) {
    extern void *lbl_803679C0;
    return *(u16 *)((u8 *)(*(void **)((u8 *)lbl_803679C0 + 4)) + 0xC);
}

extern u16 lbl_80366E80;
#pragma push
#pragma optimization_level 3
s32 fn_80104E68(u8 *arg0) {
    u16 sp8;
    u8 is_double;
    u16 code;
    void **ctx;
    void *base;
    void *end;
    void *start;
    void *entry;
    s32 fn_801053E4(s32, s32, u16 *, void *);
    s32 fn_80105474(s32, s32, void *, void *);
    u32 fn_80104930(u16 *, u16);
    extern void *lbl_803679C0;
    u8 c0 = arg0[0];
    ctx = lbl_803679C0;
    if (((c0 >= 0x81U && c0 <= 0x9FU) || (c0 >= 0xE0U && c0 <= 0xFCU)) &&
        ((arg0[1] >= 0x40U && arg0[1] <= 0x7EU) || (arg0[1] >= 0x80U && arg0[1] <= 0xFCU)))
        is_double = 1;
    else
        is_double = 0;
    if (is_double) {
        u32 low = arg0[1];
        arg0 = (u8 *)(s32)*(s8 *)arg0;
        code = __rlwimi(low, (u32)arg0, 8, 16, 23);
    } else
        code = *(s8 *)arg0 & 0xFF;
    sp8 = code;
    if (*(u16 *)ctx[3] != code) {
        base = ctx[1];
        start = (u8 *)base + *(u16 *)((u8 *)base + 0x22);
        end = (u8 *)start + ((s32)ctx[2] << 4);
        ctx[3] = (void *)fn_801053E4((s32)start, (s32)end, &sp8, fn_80104930);
        entry = ctx[3];
        if (end == entry || *(u16 *)entry != sp8) {
            ctx[3] = (void *)fn_80105474((s32)start, (s32)end, &lbl_80366E80, fn_80104930);
            entry = ctx[3];
            if (end == entry || *(u16 *)entry != 0x8199U) ctx[3] = start;
        }
    }
    return *(s8 *)((u8 *)ctx[3] + 12);
}
#pragma push
#pragma use_lmw_stmw on
#pragma opt_common_subs off
#pragma opt_lifetimes off
s32 fn_80104FC4(u8 **arg0) {
    extern void *lbl_803679C0;
    extern u16 lbl_80366E80;
    u32 fn_80104930(u16 *, u16);
    s32 fn_801053E4(s32, s32, u16 *, u32 (*)(u16 *, u16));
    s32 fn_80105474(s32, s32, u16 *, u32 (*)(u16 *, u16));
    u8 *str;
    u8 *ctx;
    u8 *file;
    u8 *end;
    u8 *base;
    u8 *found;
    u8 *next;
    u16 code;
    u16 tmp;
    u8 isDouble;
    u8 c0;
    u8 c1;
    s32 result;

    str = *arg0;
    ctx = lbl_803679C0;
    c0 = *str;
    if ((c0 >= 0x81 && c0 <= 0x9F) || (c0 >= 0xE0 && c0 <= 0xFC)) {
        c1 = str[1];
        if ((c1 >= 0x40 && c1 <= 0x7E) || (c1 >= 0x80 && c1 <= 0xFC)) {
            isDouble = 1;
            goto after_sjis;
        }
    }
    isDouble = 0;
after_sjis:

    if (isDouble != 0) {
        u8 lo = str[1];
        next = str + 2;
        tmp = (u16)(lo | (((s8)str[0] << 8) & 0xFF00));
    } else {
        tmp = *str;
        next = str + 1;
    }
    code = tmp;

    found = *(u8 **)((u8 *)ctx + 0xC);
    if (*(u16 *)found != tmp) {
        file = *(u8 **)((u8 *)ctx + 4);
        base = file + *(u16 *)(file + 0x22);
        end = base + (*(u32 *)((u8 *)ctx + 8) << 4);
        *(u8 **)((u8 *)ctx + 0xC) = (u8 *)fn_801053E4((s32)base, (s32)end, &code, fn_80104930);
        found = *(u8 **)((u8 *)ctx + 0xC);
        if (end != found) {
            if (*(u16 *)found == code) {
                goto done;
            }
        }
        *(u8 **)((u8 *)ctx + 0xC) = (u8 *)fn_80105474((s32)base, (s32)end, &lbl_80366E80, fn_80104930);
        found = *(u8 **)((u8 *)ctx + 0xC);
        if (end != found) {
            if (*(u16 *)found == 0x8199) {
                goto done;
            }
        }
        *(u8 **)((u8 *)ctx + 0xC) = base;
    }
done:
    result = *(s8 *)(*(u8 **)((u8 *)ctx + 0xC) + 0xC);
    *arg0 = next;
    return result;
}
#pragma pop
