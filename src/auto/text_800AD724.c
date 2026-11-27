/* Functions from 0x800AD24C to 0x800C3F18, found by decomp-toolkit. */
#include "common.h"

typedef struct {
    u8 flag : 1;
    u8 unk : 7;
} ItemFlagBits;

typedef struct {
    u8 unk0[8];
    u8 param;
    u8 pad9[3];
    u32 handle;
    u8 pad10[4];
} SoundChan_800B1BFC;

extern f64 lbl_80369CF8;

static inline u32 LoadSoundBankB(void *path) {
    s32 fn_800B4A84(void *, s32, s32);
    s32 fn_800B49C8(void *);
    s32 fn_800B4A14(void *, s32, s32, s32);
    void fn_800B49D0(void *);
    s32 fn_800C4638(s32, void *, s32);
    void fn_800C4588(s32);
    extern u8 Sound_str[];
    s32 handle;
    s32 size;
    u32 buffer;
    u32 value;
    handle = fn_800B4A84(path, 2, 0);
    if (handle == 0) return 0;
    value = fn_800B49C8((void *)handle);
    if (value == 0) return 0;
    size = (value + 31) & ~31;
    buffer = fn_800C4638(size, Sound_str + 0x2E, 0);
    if (buffer == 0) return 0;
    if (fn_800B4A14((void *)handle, buffer, size, 0) <= 0) {
        fn_800C4588(buffer);
        return 0;
    }
    fn_800B49D0((void *)handle);
    return buffer;
}

static inline u32 SoundReadSizeB(u32 offset, u32 limit) {
    u32 size = 0x8000;
    u32 step = 0x10000;
    u32 n;
    if (offset + 0x8000 > limit) size = limit - offset;
    else {
        for (n=2;n<6;n++) {
            if (offset + step > limit) {
                size -= (0x8000 - (limit - (offset + ((n-1)<<15)))) / n;
                size += 0x20 - (size & 31);
                break;
            }
            step += 0x8000;
        }
    }
    return size;
}

typedef struct StreamB { u8 pad[0x2C]; s32 buffers[2]; u8 pad34[0x14]; u32 size; u16 index; } StreamB;
typedef struct {
    u8 pad[0x30];
    void *entries[0xC];
    u8 kinds[0xC];
    s16 count;
    s16 cursor;
} EventBlessProc;
extern s32 fn_80010710(u8* arg0);
  extern s32 gUnitRef;
  extern s32 E_EventCaller_script[];
  extern s32 lbl_80319A68[];
  void Battle_ClearPhaseBannerChild(void *);
  void Battle_DrawPhaseBanner(void *);

#pragma optimization_level 2
/* Collect same-allegiance units with Live/Rest statuses into an E_Bless process; return 0 if none. */

/* Advance the E_Bless queue: begin move-select for the next unit, or finish at label 0x63. */

extern u8 lbl_8028D064[16];

#pragma optimization_level reset

/* Apply prior battle, bump win/battle stats if needed, then setup and calc vs current target. */

void Battle_SetupVsCurrentTarget(void *proc) {
    void Battle_Apply(void *);
    void *TargetList_GetCurrent(void *);
    void *UnitRef_GetUnit(void);
    void Battle_SetupPair(void *, void *, void *);
    void Battle_CalcHits(void *);
    extern u8 gBattle[];
    extern u8 gTargetList[];
    void *faction;
    void *unit;
    void *target;
    u8 hits;

    Battle_Apply(gBattle);
    if ((s8)gBattle[0x1A8] == 0) {
        faction = *(void **)(gBattle + 0x190);
        if (*(u8 *)((u8 *)faction + 8) == 1) {
            unit = *(void **)((u8 *)proc + 0x30);
            *(u16 *)((u8 *)unit + 0x22A) = *(u16 *)((u8 *)unit + 0x22A) + 1;
            unit = *(void **)((u8 *)proc + 0x30);
            *(u16 *)((u8 *)unit + 0x22C) = *(u16 *)((u8 *)unit + 0x22C) + 1;
        }
    }
    TargetList_GetCurrent(gTargetList);
    target = UnitRef_GetUnit();
    unit = *(void **)((u8 *)proc + 0x30);
    Battle_SetupPair(gBattle, unit, target);
    if (*(u8 *)((u8 *)proc + 0x3B) != 0) {
        gBattle[0x2D6] = 1;
    }
    Battle_CalcHits(gBattle);
    hits = gBattle[0x2C9];
    if (*(u8 *)((u8 *)proc + 0x3A) < hits) {
        *(u8 *)((u8 *)proc + 0x3A) = hits;
    }
}

/* Setup gBattle for healing the current target from proc HP, then open MapSelect. */
void Battle_SetupHealTarget(void *proc) {
    void *TargetList_GetCurrent(void *);
    void *UnitRef_GetUnit(void);
    void fn_801A7218(void *, void *, s32);
    void Battle_QueueDeathAnim(void *);
    s8 Unit_GetMaxHp(void *);
    void Battle_ApplyHpDelta(void *, s8);
    void fn_8019B704(void *, s32);
    extern u8 gTargetList[];
    extern u8 gBattle[];
    void *entry;
    void *battle;
    s32 heal;
    s32 negHeal;
    void *target;
    u8 div;

    entry = TargetList_GetCurrent(gTargetList);
    target = UnitRef_GetUnit();
    fn_801A7218(gBattle, target, -1);
    Battle_QueueDeathAnim(gBattle);
    div = *((u8 *)entry + 3);
    battle = gBattle;
    heal = *(s16 *)((u8 *)proc + 0x34) - *(s16 *)((u8 *)battle + 0x29A);
    heal /= div;
    if (heal > Unit_GetMaxHp(battle)) {
        heal = Unit_GetMaxHp(battle);
    }
    if (heal < 1) {
        heal = 1;
    }
    negHeal = -heal;
    *((u8 *)proc + 0x3B) = (u32)(negHeal | heal) >> 31;
    Battle_ApplyHpDelta(gBattle, (s8)negHeal);
    fn_8019B704(proc, 0);
}

void fn_800AD92C(s32 arg0) {
    void Process_Goto(s32, s32);
    void *TargetList_GetCurrent(void *);
    void *UnitRef_GetUnit(void);
    void BattleState_SetCamPos(void *, f32, f32);
    extern u8 gTargetList[];
    extern u8 gBattleState[];
    void *temp_r3;

    if (TargetList_GetCurrent(gTargetList) == NULL) {
        Process_Goto(arg0, 0x63);
        return;
    }
    temp_r3 = UnitRef_GetUnit();
    BattleState_SetCamPos(gBattleState, (f32)*(s8 *)((u8 *)temp_r3 + 0x19E), (f32)*(s8 *)((u8 *)temp_r3 + 0x19F));
}

void fn_800AD9C8(u8 *self) {
void fn_80029858(u8, u8);
void fn_80199CC0(void *);
extern u8 gUiContext[];
extern u8 gBattle[];
void *p;
fn_80029858(gUiContext[0xF], gUiContext[0x10]);
*(void **)(self + 0x30) = *(void **)(gBattle + 0x280);
*(s16 *)(self + 0x34) = *(s16 *)(gBattle + 0x298);
*(s16 *)(self + 0x36) = *(s16 *)(gBattle + 0x29E);
*(s16 *)(self + 0x38) = *(s16 *)(gBattle + 0x2A4);
self[0x3A] = 0;
p = *(void **)(self + 0x30);
++*(u16 *)((u8 *)p + 0x228);
fn_80199CC0(self);
}

s32 fn_800ADA4C(s32 arg0) {
    void fn_8002F728(void *);
    void Allegiance_FillMask(s32, void *);
    u8 fn_80104628(void *, s32);
    void Unit_DecSkillRanks(void *, s32);
    void fn_8002F6E8(void *, u8, u8, u8, s32);
    void *Process_CreateChild(void *, s32);
    extern u8 gTargetList[];
    extern u8 gUnits[];
    extern u8 lbl_8028D028[];

    u8 allegMask;
    s32 i;
    u8 *unit;

    fn_8002F728(gTargetList);
    Allegiance_FillMask(0, &allegMask);
    i = 1;
    do {
        if ((u8)i != 0) {
            unit = gUnits + (((u8)i - 1) * 0x280);
        } else {
            unit = NULL;
        }
        if (*(u32 *)(unit + 0x188) != 0
            && *((u8 *)&allegMask + *((u8 *)*(void **)(unit + 0x190) + 8)) != 0) {
            if (fn_80104628(unit + 0x1A4, 0) == 0
                || (*(u32 *)(unit + 0x1A0) & 0x010000DC) != 0) {
                Unit_DecSkillRanks(unit + 0x1A4, 0);
            } else {
                fn_8002F6E8(
                    gTargetList,
                    unit[0x19E],
                    unit[0x19F],
                    unit[0x198],
                    0
                );
            }
        }
        i += 1;
    } while (i <= 0x9F);
    if (*(s32 *)gTargetList == 0) {
        return 0;
    }
    Process_CreateChild(lbl_8028D028, arg0);
    return 1;
}

s32 fn_800ADB74(s32 arg0) {
    void fn_8002F728(void *);
    void Allegiance_FillMask(s32, void *);
    u8 fn_80104628(void *, s32);
    void Unit_DecSkillRanks(void *, s32);
    void fn_8002F6E8(void *, u8, u8, u8, s32);
    void *Process_CreateChild(void *, s32);
    extern u8 gTargetList[];
    extern u8 gUnits[];
    extern u8 lbl_8028D028[];

    u8 allegMask;
    s32 i;
    u8 *unit;

    fn_8002F728(gTargetList);
    Allegiance_FillMask(0, &allegMask);
    i = 1;
    do {
        if ((u8)i != 0) {
            unit = gUnits + (((u8)i - 1) * 0x280);
        } else {
            unit = NULL;
        }
        if (*(u32 *)(unit + 0x188) != 0
            && *((u8 *)&allegMask + *((u8 *)*(void **)(unit + 0x190) + 8)) != 0) {
            if (fn_80104628(unit + 0x1A4, 1) == 0
                || (*(u32 *)(unit + 0x1A0) & 0x010000DC) != 0) {
                Unit_DecSkillRanks(unit + 0x1A4, 1);
            } else {
                fn_8002F6E8(
                    gTargetList,
                    unit[0x19E],
                    unit[0x19F],
                    unit[0x198],
                    1
                );
            }
        }
        i += 1;
    } while (i <= 0x9F);
    if (*(s32 *)gTargetList == 0) {
        return 0;
    }
    Process_CreateChild(lbl_8028D028, arg0);
    return 1;
}

void fn_800ADD04(void);
void fn_800ADC9C(s32 arg0) {
    extern u8 gTargetList[];
    extern u8 gBattle[];
    void *TargetList_GetCurrent(void *);
    u8 *UnitRef_GetUnit(void);
    M2C_UNK fn_8019B6B4(s32, void (*)(void));
    M2C_UNK Battle_QueueDeathAnim(void *);
    M2C_UNK Battle_SetupUnit(void *, u8 *, s32);
    u8 *p;

    TargetList_GetCurrent(gTargetList);
    p = UnitRef_GetUnit();
    Battle_SetupUnit(gBattle, p, -1);
    Battle_QueueDeathAnim(gBattle);
    fn_8019B6B4(arg0, fn_800ADD04);
}

void fn_800ADD04(void) {
    extern u8 gTargetList[];
    void *TargetList_GetCurrent(void *);
    u8 *UnitRef_GetUnit(void);
    M2C_UNK Unit_DecSkillRanks(void *, u8);
    void *p;

    p = TargetList_GetCurrent(gTargetList);
    Unit_DecSkillRanks(UnitRef_GetUnit() + 0x1A4, M2C_FIELD(p, u8 *, 3));
}

extern u8 gTargetList[];
extern void fn_8002F61C(void *);
extern void *TargetList_GetCurrent(void *);
extern u8 *UnitRef_GetUnit(void);
extern void Unit_OnZeroHp(void);
void fn_800ADD48(void) {
    TargetList_GetCurrent(gTargetList);
    UnitRef_GetUnit();
    Unit_OnZeroHp();
    fn_8002F61C(gTargetList);
}

void fn_800ADD84(void) {
    M2C_UNK fn_80033418(void *);
    M2C_UNK Battle_Apply(void *);
    extern u8 gBattle[];

    Battle_Apply(gBattle);
    fn_80033418(gBattle + 0x8A0);
}

/* Init gBattle from the current target entry's unit, apply optional HP delta, and open MapSelect. */
void Battle_SetupTargetSelect(s32 parent) {
    void *TargetList_GetCurrent(void *);
    u8 *UnitRef_GetUnit(void);
    void fn_8019B79C(s32, s32);
    void fn_8019B83C(s32, s32);
    void fn_8019B8A0(s32, s32);
    void Battle_QueueDeathAnim(void *);
    void Battle_ApplyHpDelta(void *, s8);
    void Battle_SetupUnit(void *, u8 *, s32);
    extern u8 gTargetList[];
    extern u8 gBattle[];
    void *entry;
    u8 *unit;
    s8 hpDelta;

    entry = TargetList_GetCurrent(gTargetList);
    unit = UnitRef_GetUnit();
    Battle_SetupUnit(gBattle, unit, -1);
    Battle_QueueDeathAnim(gBattle);
    hpDelta = *(s8 *)((u8 *)entry + 1);
    if (hpDelta != 0) {
        Battle_ApplyHpDelta(gBattle, hpDelta);
    }
    if (!(*(s32 *)((u8 *)unit + 0x1A0) & 0x010000DC)) {
        switch (*(s8 *)((u8 *)entry + 0)) {
        case 0:
            fn_8019B8A0(parent, 0);
            break;
        case 1:
            fn_8019B83C(parent, 0);
            break;
        case 2:
            fn_8019B79C(parent, 0);
            break;
        }
    }
}

#pragma push
#pragma opt_lifetimes off
#pragma use_lmw_stmw on
s32 fn_800ADEB0(s32 arg0) {
    void fn_8002F728(void *);
    void Allegiance_FillMask(s32, void *);
    void fn_8002F6E8(void *, u8, s8, u8, s32);
    s8 Unit_GetMaxHp(void *);
    u8 Status_Test(void *, s32);
    void *Terrain_GetEntry(u8);
    s32 Rand_Range(s32);
    void *Process_CreateChild(void *, s32);
    extern u8 gTargetList[], gUnits[], gBattleMap[], lbl_8028CFA0[];
    u8 mask[4];
    u8 *unit;
    s32 i;
    u8 *terrain;
    u8 hp;
    u8 statusHp;
    s8 damage;
    fn_8002F728(gTargetList);
    Allegiance_FillMask(0, mask);
    i = 1;
    do {
        unit = (u8)i ? gUnits + ((u8)i - 1) * 0x280 : NULL;
        if (*(u32 *)(unit + 0x188) && mask[((u8 *)*(void **)(unit + 0x190))[8]] && !(*(u32 *)(unit + 0x1A0) & 4)) {
            terrain = Terrain_GetEntry(M2C_FIELD(gBattleMap + (s8)unit[0x19E] + ((s8)unit[0x19F] << 6), u8 *, 0x100D));
            if (((u8 *)*(void **)(terrain+8))[6] != 0) {
                hp = unit[0x1A8];
                if ((s8)hp != Unit_GetMaxHp(unit))
                    fn_8002F6E8(gTargetList, 0, (s8)(((u8 *)*(void **)(terrain+8))[6] * Unit_GetMaxHp(unit) / 100), unit[0x198], 0);
            }
            if (Status_Test(unit+0x1BC, 12)) {
                statusHp = unit[0x1A8];
                if ((s8)statusHp != Unit_GetMaxHp(unit))
                    fn_8002F6E8(gTargetList, 1, (s8)(Unit_GetMaxHp(unit) / 10), unit[0x198], 0);
            }
            if ((unit[0x1A4] >> 5) & 7) {
                damage = Rand_Range(3) + 1;
                fn_8002F6E8(gTargetList, 2, -damage, unit[0x198], 0);
            }
        }
        i++;
    } while (i <= 0x9F);
    if (*(s32 *)gTargetList == 0) return 0;
    Process_CreateChild(lbl_8028CFA0, arg0);
    return 1;
}
#pragma pop
#pragma use_lmw_stmw reset
s32 fn_800AE0D4(s32 arg0) {
    void fn_8002F728(void *);
    void Allegiance_FillMask(s32, void *);
    u8 Map_IsInViewBounds(void *, u8, u8);
    u8 Unit_TickTransformGaugeFast(void *);
    void fn_8002F6E8(void *, u8, u8, u8, s32);
    void *Process_CreateChild(void *, s32);
    extern u8 gTargetList[];
    extern u8 gUnits[];
    extern u8 gBattleMap[];
    extern u8 lbl_8028CF68[];

    u8 allegMask;
    s32 i;
    u8 *unit;

    fn_8002F728(gTargetList);
    Allegiance_FillMask(0, &allegMask);
    i = 1;
    do {
        if ((u8)i != 0) {
            unit = gUnits + (((u8)i - 1) * 0x280);
        } else {
            unit = NULL;
        }
        if (*(u32 *)(unit + 0x188) != 0
            && *((u8 *)&allegMask + *((u8 *)*(void **)(unit + 0x190) + 8)) != 0
            && !(*(u32 *)(unit + 0x1A0) & 4)
            && Map_IsInViewBounds(gBattleMap, unit[0x19E], unit[0x19F]) != 0
            && Unit_TickTransformGaugeFast(unit) != 0) {
            fn_8002F6E8(
                gTargetList,
                unit[0x19E],
                unit[0x19F],
                unit[0x198],
                0
            );
        }
        i += 1;
    } while (i <= 0x9F);
    if (*(s32 *)gTargetList != 0) {
        Process_CreateChild(lbl_8028CF68, arg0);
        return 1;
    }
    return 0;
}

extern void Unit_ApplyTransform(void);
void fn_800AE1FC(void) {
    TargetList_GetCurrent(&gTargetList);
    UnitRef_GetUnit();
    Unit_ApplyTransform();
    fn_8002F61C(&gTargetList);
}

void fn_800AE238(s32 arg0) {
    void *TargetList_GetCurrent(void *);
    void *UnitRef_GetUnit(void);
    void fn_80183BE4(void *, s32);
    extern u8 gTargetList[];

    TargetList_GetCurrent(gTargetList);
    fn_80183BE4(UnitRef_GetUnit(), arg0);
}

void fn_800AE278(s32 arg0) {
    void Process_Goto(s32, s32);
    void *TargetList_GetCurrent(void *);
    void *UnitRef_GetUnit(void);
    void BattleState_SetCamPos(void *, f32, f32);
    extern u8 gTargetList[];
    extern u8 gBattleState[];
    void *temp_r3;

    if (TargetList_GetCurrent(gTargetList) == NULL) {
        Process_Goto(arg0, 0x63);
        return;
    }
    temp_r3 = UnitRef_GetUnit();
    if ((*(u32 *)((u8 *)temp_r3 + 0x1A0) & 0x010000DC) == 0) {
        BattleState_SetCamPos(gBattleState, (f32)*(s8 *)((u8 *)temp_r3 + 0x19E), (f32)*(s8 *)((u8 *)temp_r3 + 0x19F));
    }
}

s32 fn_800AE328(s32 arg0) {
 void fn_8003DDF8(void *, s8 *, s8 *);
 void Unit_SeparateRescue(void *, u8, u8);
 void fn_80183C6C(void *, s32, s32, s32, s32, s32);
 void *Battle_GetActiveCombatant(void *);
 extern u8 gBattle[];
 s8 x; s8 y; void *unit; void *obj; void *p;
 obj=Battle_GetActiveCombatant(gBattle);
 if(obj==NULL) return 0;
 if(!(*(s32 *)((u8 *)obj+0x1A0)&2)) return 0;
 unit=*(void **)((u8 *)obj+0x280);
 fn_8003DDF8(unit,&x,&y);
 p=*(void **)((u8 *)unit+0x194);
 fn_80183C6C(p,*(s8 *)((u8 *)p+0x19E),*(s8 *)((u8 *)p+0x19F),x,y,arg0);
 Unit_SeparateRescue(unit,(u8)x,(u8)y);
 return 1;
}

void fn_800AE3DC(s32 arg0) {
    void Process_CreateChild(void *, s32);
    extern u8 gBattleState[];
    extern u8 gUnitLists[];
    extern u8 lbl_8028D138[];
    u8 *entry;

    entry = *(u8 **)(gUnitLists + gBattleState[0x11] * 0xC);
    while (entry != 0) {
        u32 flags = *(u32 *)(entry + 0x1A0);
        entry = *(u8 **)(entry + 0x184);
        if (!(flags & 4))
            goto do_call;
    }
    return;
do_call:
    Process_CreateChild(lbl_8028D138, arg0);
}
