/* Functions from 0x801A7D78 to 0x801AE2D4, found by decomp-toolkit. */
#include "common.h"

extern u16 lbl_80367218;
u32 Battle_Destroy(u32 battle, s16 doFree) {
    void *Item_Destroy(s32, s32);
    void Heap_Free(u32);
    void BattleUnit_Reset(u32);
    void Array_Destroy(s32, void *(*)(s32, s32), s32, s32);

    // Destroy the three combatant slots in a battle object; free if doFree > 0.
    if (battle != 0U) {
        if ((battle + 0x5C0) != 0) {
            BattleUnit_Reset(battle + 0x5C0);
            Item_Destroy(battle + 0x84C, -1);
            Item_Destroy(battle + 0x844, -1);
            if (((battle + 0x5C0) != 0) && ((battle + 0x5C0) != 0) && ((battle + 0x5C0) != 0) && ((battle + 0x5C0) != 0) && ((battle + 0x5C0) != 0) && ((battle + 0x5C0) != 0) && ((battle + 0x5C0) != 0)) {
                Array_Destroy(battle + 0x7AC, Item_Destroy, 8, 4);
                Array_Destroy(battle + 0x78C, Item_Destroy, 8, 4);
            }
        }
        if ((battle + 0x2E0) != 0) {
            BattleUnit_Reset(battle + 0x2E0);
            Item_Destroy(battle + 0x56C, -1);
            Item_Destroy(battle + 0x564, -1);
            if (((battle + 0x2E0) != 0) && ((battle + 0x2E0) != 0) && ((battle + 0x2E0) != 0) && ((battle + 0x2E0) != 0) && ((battle + 0x2E0) != 0) && ((battle + 0x2E0) != 0) && ((battle + 0x2E0) != 0)) {
                Array_Destroy(battle + 0x4CC, Item_Destroy, 8, 4);
                Array_Destroy(battle + 0x4AC, Item_Destroy, 8, 4);
            }
        }
        if (battle != 0U) {
            BattleUnit_Reset(battle);
            Item_Destroy(battle + 0x28C, -1);
            Item_Destroy(battle + 0x284, -1);
            if ((battle != 0U) && (battle != 0U) && (battle != 0U) && (battle != 0U) && (battle != 0U) && (battle != 0U) && (battle != 0U)) {
                Array_Destroy(battle + 0x1EC, Item_Destroy, 8, 4);
                Array_Destroy(battle + 0x1CC, Item_Destroy, 8, 4);
            }
        }
        if (doFree > 0) {
            Heap_Free(battle);
        }
    }
    return battle;
}

void *fn_801A7F5C(void *arg0) {
    fn_801A7FA4(arg0);
    fn_801A7FA4((char *)arg0 + 0x2E0);
    fn_801A7FA4((char *)arg0 + 0x5C0);
    *(s32 *)((char *)arg0 + 0xCAC) = 0;
    return arg0;
}

int fn_801A7FA4(void *arg0)
{
    void fn_80016F78(void *);
    void Item_Init(void *);
    void BattleUnit_Reset(void *);

    u8 *ptr;

    ptr = (u8 *)arg0;

    fn_80016F78(arg0);

    Item_Init(ptr + 0x284);
    Item_Init(ptr + 0x28C);

    *(u16 *)(ptr + 0x2AE) = 0;

    BattleUnit_Reset(arg0);

    return (int)arg0;
}

u16 *BattleUnit_GetWeaponSlot(void *arg0) {
    s8 temp = ((s8 *)arg0)[0x2C8 / sizeof(s8)];
    if (temp <= 0) {
        return &lbl_80367218;
    }
    return (u16 *)((u8 *)arg0 + 0x284);
}

void fn_801A8010(void *arg0) {
    u64 *Item_GetFlagsPtr(void *);
    u8 fn_8001DDE8(s32);
    extern u16 lbl_80367218;
    void *base;
    s8 flag;

    flag = *(s8 *)((u8 *)arg0 + 0x2C8);
    if (flag > 0) {
        if (flag <= 0) {
            base = &lbl_80367218;
        } else {
            base = (u8 *)arg0 + 0x284;
        }
        if ((*Item_GetFlagsPtr(base) & 0x10000000000ULL) == 0) {
            if (*(u8 *)((u8 *)arg0 + 0x295) == 0x52) {
                if (*(s8 *)((u8 *)arg0 + 0x2C8) <= 0) {
                    base = &lbl_80367218;
                } else {
                    base = (u8 *)arg0 + 0x284;
                }
                if (fn_8001DDE8(*(s32 *)base) == 0) {
                    return;
                }
            }
            flag = *(s8 *)((u8 *)arg0 + 0x2C8);
            *(u8 *)((u8 *)arg0 + 0x2C8) = (u8)(flag - 1);
            if (*(s8 *)((u8 *)arg0 + 0x2C8) == 0) {
                *(u8 *)((u8 *)arg0 + 0x2C7) = 1;
            }
        }
    }
}

#pragma use_lmw_stmw on
void fn_801A80D8(void *unit, s32 *hit, s32 *avoid, s32 *crit) {
    void Allegiance_FillMask(s32, void *);
    u8 Unit_GetDistance(void *, void *);
    u8 Status_Test(void *, s32);
    u8 Allegiance_Compare(void *, void *);
    void *Unit_FindDisposLeader(void *);
    extern u8 gUnits[];
    u8 mask[8];
    u8 distance;
    u8 *other;
    void *self;
    s32 *pHit;
    s32 *pAvoid;
    s32 *pCrit;
    s32 i;

    self = unit;
    pHit = hit;
    pAvoid = avoid;
    pCrit = crit;
    *hit = 0;
    *avoid = 0;
    *crit = 0;
    Allegiance_FillMask(3, mask);
    other = 0;
    for (i = 1; i <= 0x9F; i++) {
        if ((u8)i) {
            other = gUnits + ((u8)i - 1) * 0x280;
        } else {
            other = 0;
        }
        if (*(u32 *)(other + 0x188) == 0) {
            continue;
        }
        if (mask[(*(u8 **)(other + 0x190))[8]] == 0) {
            continue;
        }
        distance = Unit_GetDistance(self, other);
        if (distance > 3 || distance < 1) {
            continue;
        }
        if (Status_Test(other + 0x1BC, 0x3B) == 0) {
            continue;
        }
        if (Allegiance_Compare(*(void **)((u8 *)self + 0x190), *(void **)(other + 0x190)) != 1) {
            continue;
        }
        *pHit -= 5;
        *pCrit -= 5;
    }
    switch ((*(u8 **)((u8 *)self + 0x190))[8]) {
    case 0:
    case 5:
    case 6:
        break;
    default:
        other = (u8 *)Unit_FindDisposLeader(self);
        if (other != NULL && Status_Test(other + 0x1BC, 0x3A) != 0) {
            distance = Unit_GetDistance(self, other);
            if (distance >= 1 && distance <= 3) {
                *pHit += 5;
                *pAvoid += 5;
            }
        }
        break;
    }
}
void fn_801A80D8(void *arg0, s32 *arg1, s32 *arg2, s32 *arg3);

#pragma push
#pragma optimization_level 4
#pragma opt_lifetimes off
void fn_801A8268(void *arg0) {
    s32 DebugPrint(const char *, ...);
    s32 Msg_ResolveName(void *);
    s32 fn_800A8978(void *);
    s32 Unit_GetMaxHp(void *);
    u8 fn_800386B0(void *);
    s32 fn_8003A778(void *);
    s32 fn_8003AA40(void *);
    s32 fn_8003ACF8(void *);
    s32 fn_8003AEB0(void *);
    s32 fn_8003AF28(void *);
    s32 Unit_GetMagAtk(void *);
    s32 Unit_GetCarryWtLimit(void *);
    s32 UnitRef_GetName(void *);
    s32 Unit_FormatAttrFlags(void *);
    extern u8 gBattleDebugMsgs[];
    extern u16 lbl_80367218;
    s8 g, f, e, d, c, b, a;
    s8 t;
    u8 b25;
    u8 b26;
    s32 tmp;
    s8 v1a8, v19a;
    void *p;
    s32 flag;
    s32 secondFlag;
    void *base, *obj;
    s32 ret;
    void *slot;

    p = *(void **)((u8 *)arg0 + 0x188);
    DebugPrint((const char *)(gBattleDebugMsgs + 0x1D),
                Msg_ResolveName(p), *(void **)p);
    p = *(void **)((u8 *)arg0 + 0x18C);
    DebugPrint((const char *)(gBattleDebugMsgs + 0x29),
                fn_800A8978(p), *(void **)p);

    v1a8 = *(s8 *)((u8 *)arg0 + 0x1A8);
    v19a = *(s8 *)((u8 *)arg0 + 0x19A);
    t = Unit_GetMaxHp(arg0);
    DebugPrint((const char *)(gBattleDebugMsgs + 0x35),
                v19a, fn_800386B0(arg0), v1a8, t);

    DebugPrint((const char *)(gBattleDebugMsgs + 0x49),
                *(s8 *)((u8 *)arg0 + 0x19E), *(s8 *)((u8 *)arg0 + 0x19F));

    a = fn_8003A778(arg0);
    b = fn_8003AA40(arg0);
    c = fn_8003ACF8(arg0);
    d = fn_8003AEB0(arg0);
    e = fn_8003AF28(arg0);
    f = Unit_GetMagAtk(arg0);
    g = Unit_GetCarryWtLimit(arg0);
    DebugPrint((const char *)(gBattleDebugMsgs + 0x57),
                g, f, e, d, c, b, a);

    DebugPrint((const char *)(gBattleDebugMsgs + 0x82),
                *(s16 *)((u8 *)arg0 + 0x298), *(s16 *)((u8 *)arg0 + 0x29A),
                *(s16 *)((u8 *)arg0 + 0x29C), *(s16 *)((u8 *)arg0 + 0x29E));
    DebugPrint((const char *)(gBattleDebugMsgs + 0xA3),
                *(s16 *)((u8 *)arg0 + 0x2A0), *(s16 *)((u8 *)arg0 + 0x2A4),
                *(s16 *)((u8 *)arg0 + 0x2A6));
    DebugPrint((const char *)(gBattleDebugMsgs + 0xC0),
                *(s16 *)((u8 *)arg0 + 0x2A2), *(s16 *)((u8 *)arg0 + 0x2A8));

    flag = *((u8 *)arg0 + 0x2C8);
    if ((s8)flag <= 0) {
        base = &lbl_80367218;
    } else {
        base = (u8 *)arg0 + 0x284;
    }
    b25 = *((u8 *)base + 4);
    if ((s8)flag <= 0) {
        base = &lbl_80367218;
    } else {
        base = (u8 *)arg0 + 0x284;
    }
    base = *(void **)base;
    if (base != 0) {
        tmp = *((u8 *)base + 0x18);
    } else {
        tmp = 0;
    }
    b26 = (u8)tmp;
    if ((s8)flag <= 0) {
        base = &lbl_80367218;
    } else {
        base = (u8 *)arg0 + 0x284;
    }
    DebugPrint((const char *)(gBattleDebugMsgs + 0xD9),
                UnitRef_GetName(base), b25, b26, *(s8 *)((u8 *)arg0 + 0x294));

    DebugPrint((const char *)(gBattleDebugMsgs + 0xEC),
                *(s16 *)((u8 *)arg0 + 0x2C2), *(s16 *)((u8 *)arg0 + 0x2C4));

    secondFlag = *((u8 *)arg0 + 0x2C8);
    slot = (u8 *)arg0 + 0x28C;
    if ((s8)secondFlag <= 0) {
        base = &lbl_80367218;
    } else {
        base = (u8 *)arg0 + 0x284;
    }
    b25 = *((u8 *)base + 4);
    if ((s8)secondFlag <= 0) {
        base = &lbl_80367218;
    } else {
        base = (u8 *)arg0 + 0x284;
    }
    obj = *(void **)base;
    if (obj != 0) {
        tmp = *((u8 *)obj + 0x18);
    } else {
        tmp = 0;
    }
    b26 = (u8)tmp;
    DebugPrint((const char *)(gBattleDebugMsgs + 0x100),
                UnitRef_GetName(slot), b25, b26, *(s8 *)((u8 *)arg0 + 0x294));

    DebugPrint((const char *)(gBattleDebugMsgs + 0x114),
                Unit_FormatAttrFlags((u8 *)arg0 + 0x2AE));
    DebugPrint((const char *)(gBattleDebugMsgs + 0x121),
                Unit_FormatAttrFlags((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0x3A));
    DebugPrint((const char *)(gBattleDebugMsgs + 0x12E));
}
#pragma pop
void fn_801A859C(void *arg0) {
    s8 temp;
    temp = Unit_GetMaxHp();
    M2C_FIELD(arg0, s8 *, 0x2B7) = temp;
    M2C_FIELD(arg0, u8 *, 0x2B8) = (u8) M2C_FIELD(arg0, u8 *, 0x1A8);
    M2C_FIELD(arg0, s16 *, 0x2BA) = (s16) M2C_FIELD(arg0, s16 *, 0x298);
    M2C_FIELD(arg0, s16 *, 0x2BC) = (s16) M2C_FIELD(arg0, s16 *, 0x29A);
    M2C_FIELD(arg0, s16 *, 0x2BE) = (s16) M2C_FIELD(arg0, s16 *, 0x2A2);
    M2C_FIELD(arg0, s16 *, 0x2C0) = (s16) M2C_FIELD(arg0, s16 *, 0x2A8);
}

void fn_801A85F4(s32 arg0) {
    M2C_UNK Status_Set(s32, M2C_UNK);
    Status_Set(arg0 + 0x1BC, 0x4C);
    Status_Set(arg0 + 0x1BC, 0x31);
    Status_Set(arg0 + 0x1BC, 0x30);
    Status_Set(arg0 + 0x1BC, 0x5A);
    Status_Set(arg0 + 0x1BC, 0x2F);
    Status_Set(arg0 + 0x1BC, 0x38);
    Status_Set(arg0 + 0x1BC, 0x35);
    Status_Set(arg0 + 0x1BC, 0x39);
    Status_Set(arg0 + 0x1BC, 0x33);
}

/* Clear map-event status bits on a unit if any are set; return whether any were. */
s32 Unit_ClearEventStatuses(s32 unit) {
    u8 Status_Test(s32, M2C_UNK);
    if ((Status_Test(unit + 0x1BC, 0x29) == 0) && (Status_Test(unit + 0x1BC, 0x41) == 0) && (Status_Test(unit + 0x1BC, 0x4C) == 0) && (Status_Test(unit + 0x1BC, 0x31) == 0) && (Status_Test(unit + 0x1BC, 0x2F) == 0) && (Status_Test(unit + 0x1BC, 0x30) == 0) && (Status_Test(unit + 0x1BC, 0x32) == 0) && (Status_Test(unit + 0x1BC, 0x3F) == 0) && (Status_Test(unit + 0x1BC, 0x10) == 0) && (Status_Test(unit + 0x1BC, 0x35) == 0) && (Status_Test(unit + 0x1BC, 0x2B) == 0) && (Status_Test(unit + 0x1BC, 0x2C) == 0) && (Status_Test(unit + 0x1BC, 0x2E) == 0) && (Status_Test(unit + 0x1BC, 0x33) == 0) && (Status_Test(unit + 0x1BC, 0x38) == 0) && (Status_Test(unit + 0x1BC, 0x34) == 0) && (Status_Test(unit + 0x1BC, 0x39) == 0) && (Status_Test(unit + 0x1BC, 0x36) == 0) && (Status_Test(unit + 0x1BC, 0x42) == 0) && (Status_Test(unit + 0x1BC, 0x5A) == 0) && (Status_Test(unit + 0x1BC, 0x2D) == 0)) {
        return 0;
    }
    Status_Set(unit + 0x1BC, 0x29);
    Status_Set(unit + 0x1BC, 0x41);
    Status_Set(unit + 0x1BC, 0x4C);
    Status_Set(unit + 0x1BC, 0x31);
    Status_Set(unit + 0x1BC, 0x2F);
    Status_Set(unit + 0x1BC, 0x30);
    Status_Set(unit + 0x1BC, 0x32);
    Status_Set(unit + 0x1BC, 0x3F);
    Status_Set(unit + 0x1BC, 0x10);
    Status_Set(unit + 0x1BC, 0x35);
    Status_Set(unit + 0x1BC, 0x2B);
    Status_Set(unit + 0x1BC, 0x2C);
    Status_Set(unit + 0x1BC, 0x2E);
    Status_Set(unit + 0x1BC, 0x33);
    Status_Set(unit + 0x1BC, 0x38);
    Status_Set(unit + 0x1BC, 0x34);
    Status_Set(unit + 0x1BC, 0x39);
    Status_Set(unit + 0x1BC, 0x36);
    Status_Set(unit + 0x1BC, 0x42);
    Status_Set(unit + 0x1BC, 0x5A);
    Status_Set(unit + 0x1BC, 0x2D);
    return 1;
}

/* For a non-item/non-kind-9 weapon slot: add wpn exp, OR rank-up into +0x2C6, debug-print the new exp. */
void BattleUnit_GainWpnExp(void *unit, void *slotArg) {
    s32 Unit_AddWpnExp(void *);
    u8 Unit_GetWpnExp(void *, u8);
    s32 DebugPrint(const char *, ...);
    extern u8 gBattleDebugMsgs[];
    void *slot;
    void *item;
    u8 kind;

    slot = slotArg;
    if ((slotArg = *(void **)slotArg) == NULL) {
        return;
    }
    kind = (slotArg != NULL) ? *(u8 *)((u8 *)slotArg + 0x12) : 0xC;
    if (kind == 8) {
        return;
    }
    kind = (slotArg != NULL) ? *(u8 *)((u8 *)slotArg + 0x12) : 0xC;
    if (kind == 9) {
        return;
    }
    *(u8 *)((u8 *)unit + 0x2C6) |= Unit_AddWpnExp(unit);
    DebugPrint((const char *)(gBattleDebugMsgs + 0x16A),
                Unit_GetWpnExp(unit, ((item = *(void **)slot) != NULL) ? *(u8 *)((u8 *)item + 0x12) : 0xC));
}

extern u8 gBattleHitTbl[104];
extern u16 gBattle[1634];
u8 Rand_TrueHit(s16);
u8 Rand_Chance(s16);
/* Decide this strike's outcome: 0x50 hit, 0x51 crit, 0x52 miss (forced flags, triangle crit, then 2RN hit / 1RN crit). */
s32 Battle_RollHitResult(void *unit) {
    u8 Rand_TrueHit(s16);
    u8 Rand_Chance(s16);
    extern u8 gBattleHitTbl[104];
    extern u16 gBattle[1634];
    u8 flags;
    u8 *hitTbl;

    hitTbl = gBattleHitTbl;
    flags = hitTbl[hitTbl[0x60]];

    if (flags & 1) {
        return 0x50;
    }
    if (flags & 2) {
        return 0x51;
    }
    if (flags & 4) {
        return 0x52;
    }

    if (*(u8 *)((u8 *)unit + 0x2CA) != 0) {
        *(u8 *)((u8 *)unit + 0x2CA) = 0;
        *(u32 *)((u8 *)gBattle + 0xCAC) |= 0x1000;
        return 0x51;
    }

    if (Rand_TrueHit(*(s16 *)((u8 *)unit + 0x2A2)) == 0) {
        return 0x52;
    }

    return (Rand_Chance(*(s16 *)((u8 *)unit + 0x2A8)) != 0) + 0x50;
}

void fn_801A8AF4(void *arg0) {
    s16 *temp1;
    s16 *temp2;
    
    temp1 = (s16*)((u8*)arg0 + 0x2A2);
    if (*temp1 > 0x64) {
        *temp1 = 0x64;
    }
    if (*temp1 < 0) {
        *temp1 = 0;
    }
    
    temp2 = (s16*)((u8*)arg0 + 0x2A8);
    if (*temp2 > 0x64) {
        *temp2 = 0x64;
    }
    if (*temp2 < 0) {
        *temp2 = 0;
    }
}

void fn_801A8B48(void *arg0, void *arg1) {
    u8 Status_Test(void *, s32);
    void *Item_GetFlagsPtr(void *);
    void *fn_80037C20(void *);
    void *slot;
    if (Status_Test((void *)((u32)arg0+0x1BC),0x35)) *(s16 *)((u8 *)arg0+0x2A2)*=2;
    if (Status_Test((u8 *)arg0+0x1BC,0x3F)) {
        *(s16 *)((u8 *)arg0+0x2A2)/=2;
        *(s16 *)((u8 *)arg0+0x2A8)*=2;
    }
    if (*(u8 *)((u8 *)arg1+0x1A5)&7) *(s16 *)((u8 *)arg0+0x2A2)=100;
    if (*(u32 *)((u8 *)arg1+0x28C) && (*(u64 *)Item_GetFlagsPtr((void *)((u32)arg1+0x28C))&0x4000ULL))
        *(s16 *)((u8 *)arg0+0x2A8)=0;
    slot=fn_80037C20(arg0);
    if (slot && *(u32 *)slot && (*(u64 *)Item_GetFlagsPtr(slot)&0x4000ULL))
        *(s16 *)((u8 *)arg0+0x2A8)=0;
    if (Status_Test((u8 *)arg1+0x1BC,0x5F) && !(*(u64 *)Item_GetFlagsPtr((u8 *)arg0+0x28C)&0x2000000000ULL))
        *(s16 *)((u8 *)arg0+0x298)=0;
}

/* Sum affinity bonuses from same-unk190 support partners within 3 tiles into info, then halve. */
void Unit_FillAffinityBonuses(void *unit, void *info) {
    void Unit_AddAffinityBonuses(void *, s32, void *);
    void Unit_FindSupportPartnerIndex(void *, s32);
    s32 Unit_GetSupportRank(void *, s32);
    void *Unit_GetSupportPartner(void *, s32);
    u8 Unit_CountSupportPartners(void *);
    u8 Unit_GetDistance(void *, void *);
    void AffinityBonuses_Halve(void *);
    s32 i;
    void *partner;
    s32 rank;

    i = 0;
    *(u8 *)((u8 *)info + 9) = 0;
    *(u8 *)((u8 *)info + 8) = 0;
    *(u8 *)((u8 *)info + 7) = 0;
    *(u8 *)((u8 *)info + 6) = 0;
    *(u8 *)((u8 *)info + 5) = 0;
    *(u8 *)((u8 *)info + 4) = 0;

    for (; i < (s32)Unit_CountSupportPartners(unit); i++) {
        partner = Unit_GetSupportPartner(unit, i);
        if (partner == NULL) {
            continue;
        }
        if (*(u32 *)((u8 *)unit + 0x190) != *(u32 *)((u8 *)partner + 0x190)) {
            continue;
        }
        if ((u8)Unit_GetDistance(unit, partner) > 3) {
            continue;
        }
        Unit_FindSupportPartnerIndex(partner, *(s32 *)((u8 *)unit + 0x188));
        rank = Unit_GetSupportRank(unit, i);
        Unit_AddAffinityBonuses(unit, rank, info);
        Unit_AddAffinityBonuses(partner, rank, info);
    }
    AffinityBonuses_Halve(info);
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801A8DA4(void *unit) {
    struct {
        u32 unk00;
        s8 bonuses[6];
    } info;

    Unit_FillAffinityBonuses(unit, &info);
    *(s16 *)((u8 *)unit + 0x298) += info.bonuses[0];
    *(s16 *)((u8 *)unit + 0x29A) += info.bonuses[1];
    *(s16 *)((u8 *)unit + 0x29E) += info.bonuses[2];
    *(s16 *)((u8 *)unit + 0x2A0) += info.bonuses[3];
    *(s16 *)((u8 *)unit + 0x2A4) += info.bonuses[4];
    *(s16 *)((u8 *)unit + 0x2A6) += info.bonuses[5];
}
#pragma pop
void fn_801A8F14(void *arg0, void *arg1) {
    u8 fn_801B8550(s32);
    if (fn_801B8550(M2C_FIELD(arg1, s32 *, 0x280)) != 0) {
        M2C_FIELD(arg0, s16 *, 0x2A4) = 0;
    }
    M2C_FIELD(arg0, s16 *, 0x2A2) = (s16) (M2C_FIELD(arg0, s16 *, 0x29E) - M2C_FIELD(arg1, s16 *, 0x2A0));
    M2C_FIELD(arg0, s16 *, 0x2A8) = (s16) (M2C_FIELD(arg0, s16 *, 0x2A4) - M2C_FIELD(arg1, s16 *, 0x2A6));
}

void fn_801A8F80(void *arg0, void *arg1) {
    void *Item_GetFlagsPtr(void *);
    u8 Item_GetWt(void *);
    u8 fn_8001D3FC(void *);
    u8 fn_8001D47C(void *);
    u8 fn_8001D500(void *);
    u8 fn_8001DDC4(u8);
    typedef struct { u8 b0, b1, b2, b3, b4; } Ret378CC;
    Ret378CC fn_800378CC(void *);
    s8 fn_8003AA40(void *);
    void fn_80037904(void *, s32);
    s8 fn_8003A778(void *);
    s8 fn_8003ACF8(void *);
    s8 fn_8003AEB0(void *);
    s8 fn_8003AF28(void *);
    s8 Unit_GetMagAtk(void *);
    s8 Unit_GetCarryWtLimit(void *);
    u8 fn_80092DC4(void *, void *);
    void fn_801A80D8(void *, s32 *, s32 *, s32 *);
    u8 Status_Test(void *, s32);
    s8 fn_801B8674(void *);
    s8 fn_801F19A0(void);
    extern u16 lbl_80367218;

    void *self;
    void *other;
    u8 flag;
    s16 t2c2;
    void *obj;
    u32 kind;
    u8 hit;
    void *base;
    unsigned long tmp;
    s32 diff;
    Ret378CC ret;
    s32 sp10;
    s32 spC;
    s32 sp8;
    u64 *bits;
    s8 t;

    self = arg0;
    other = arg1;
    hit = 0;

    if (other != NULL && *(u32 *)((u8 *)other + 0x188) != 0 &&
        (u8)fn_80092DC4(other, (u8 *)self + 0x2AE) != 0) {
        *(u8 *)((u8 *)self + 0x296) = 1;
    }

    if (other != NULL && *(u32 *)((u8 *)other + 0x188) != 0) {
        if ((s8)*(u8 *)((u8 *)other + 0x2C8) <= 0) {
            base = &lbl_80367218;
        } else {
            base = (u8 *)other + 0x284;
        }
        obj = *(void **)base;
        if (obj != NULL) {
            kind = *(u8 *)((u8 *)obj + 0x13);
        } else {
            kind = 0xC;
        }
        if ((u8)fn_8001DDC4((u8)kind) != 0) {
            hit = 1;
        }
    }

    flag = *(u8 *)((u8 *)self + 0x2C8);
    if ((s8)flag <= 0) {
        base = &lbl_80367218;
    } else {
        base = (u8 *)self + 0x284;
    }
    if (*(void **)base != NULL) {
        t2c2 = *(s16 *)((u8 *)self + 0x2C2);
        if ((s8)flag <= 0) {
            base = &lbl_80367218;
        } else {
            base = (u8 *)self + 0x284;
        }
        *(s16 *)((u8 *)self + 0x298) = (s16)((u8)fn_8001D500(base) + t2c2);
        if (*(u8 *)((u8 *)self + 0x296) != 0) {
            *(s16 *)((u8 *)self + 0x298) = (s16)(*(s16 *)((u8 *)self + 0x298) * 2);
        }
        if ((s8)*(u8 *)((u8 *)self + 0x2C8) <= 0) {
            base = &lbl_80367218;
        } else {
            base = (u8 *)self + 0x284;
        }
        bits = (u64 *)Item_GetFlagsPtr(base);
        if ((*bits & 0x1000ULL) == 0) {
            if ((s8)*(u8 *)((u8 *)self + 0x2C8) <= 0) {
                base = &lbl_80367218;
            } else {
                base = (u8 *)self + 0x284;
            }
            obj = *(void **)base;
            if (obj != NULL) {
                kind = *(u8 *)((u8 *)obj + 0x13);
            } else {
                kind = 0xC;
            }
            if ((u8)fn_8001DDC4((u8)kind) != 0) {
                *(s16 *)((u8 *)self + 0x298) =
                    (s16)(*(s16 *)((u8 *)self + 0x298) + Unit_GetMagAtk(self));
            } else {
                *(s16 *)((u8 *)self + 0x298) =
                    (s16)(*(s16 *)((u8 *)self + 0x298) + Unit_GetCarryWtLimit(self));
            }
        }
    } else {
        *(s16 *)((u8 *)self + 0x298) = 0;
    }

    if (hit == 0) {
        *(s16 *)((u8 *)self + 0x29A) =
            (s16)((s8)*(u8 *)((u8 *)self + 0x2B4) + fn_8003AA40(self));
    } else {
        *(s16 *)((u8 *)self + 0x29A) =
            (s16)((s8)*(u8 *)((u8 *)self + 0x2B5) + fn_8003A778(self));
    }

    tmp = (u8)Item_GetWt((u8 *)self + 0x28C);
    diff = tmp - Unit_GetCarryWtLimit(self);
    if (diff < 0) {
        diff = 0;
    }
    *(s16 *)((u8 *)self + 0x29C) = (s16)(fn_8003AEB0(self) - diff);
    if (*(s16 *)((u8 *)self + 0x29C) < 0) {
        *(s16 *)((u8 *)self + 0x29C) = 0;
    }

    fn_80037904(self, -1);
    ret = fn_800378CC(self);

    if ((s8)*(u8 *)((u8 *)self + 0x2C8) <= 0) {
        base = &lbl_80367218;
    } else {
        base = (u8 *)self + 0x284;
    }
    tmp = fn_8003AF28(self) * 2;
    *(s16 *)((u8 *)self + 0x29E) = (s16)((u8)fn_8001D47C(base) + tmp);

    t = fn_8003ACF8(self);
    *(s16 *)((u8 *)self + 0x29E) =
        (s16)(t + (*(s16 *)((u8 *)self + 0x2C4) + *(s16 *)((u8 *)self + 0x29E)));
    *(s16 *)((u8 *)self + 0x29E) =
        (s16)(*(s16 *)((u8 *)self + 0x29E) + (s8)ret.b2);

    *(s16 *)((u8 *)self + 0x2A0) =
        (s16)(fn_8003ACF8(self) +
              ((*(s16 *)((u8 *)self + 0x29C) * 2) + (s8)*(u8 *)((u8 *)self + 0x2B6)));
    *(s16 *)((u8 *)self + 0x2A0) =
        (s16)(*(s16 *)((u8 *)self + 0x2A0) + (s8)ret.b3);

    if (((*(u16 *)((u8 *)self + 0x1A4) >> 7) & 7) != 0) {
        *(s16 *)((u8 *)self + 0x2A0) = 0;
    }

    if ((s8)*(u8 *)((u8 *)self + 0x2C8) <= 0) {
        base = &lbl_80367218;
    } else {
        base = (u8 *)self + 0x284;
    }
    tmp = (u8)fn_8001D3FC(base);
    t = fn_8003AF28(self);
    *(s16 *)((u8 *)self + 0x2A4) =
        (s16)(((((u32)t >> 31) + t) >> 1) + tmp);
    *(s16 *)((u8 *)self + 0x2A4) =
        (s16)(*(s16 *)((u8 *)self + 0x2A4) + (s8)ret.b4);

    *(s16 *)((u8 *)self + 0x2A4) =
        (s16)(*(s16 *)((u8 *)self + 0x2A4) +
              fn_801B8674(*(void **)((u8 *)self + 0x280)));

    if ((u8)Status_Test((u8 *)self + 0x1BC, 0x61) != 0) {
        *(s16 *)((u8 *)self + 0x2A4) =
            (s16)(*(s16 *)((u8 *)self + 0x2A4) + fn_801F19A0());
    }

    if ((s8)*(u8 *)((u8 *)self + 0x2C8) <= 0) {
        base = &lbl_80367218;
    } else {
        base = (u8 *)self + 0x284;
    }
    bits = (u64 *)Item_GetFlagsPtr(base);
    if ((*bits & 0x2000ULL) != 0) {
        *(s16 *)((u8 *)self + 0x2A4) = 0;
    }

    *(s16 *)((u8 *)self + 0x2A6) = (s16)fn_8003ACF8(self);

    if ((u8)Status_Test((u8 *)self + 0x1BC, 0x41) == 0) {
        if ((u8)Status_Test((u8 *)self + 0x1BC, 0x52) != 0) {
            *(s16 *)((u8 *)self + 0x2A0) =
                (s16)(*(s16 *)((u8 *)self + 0x2A0) + 0x14);
        }
        if ((u8)Status_Test((u8 *)self + 0x1BC, 0x51) != 0) {
            *(s16 *)((u8 *)self + 0x29E) =
                (s16)(*(s16 *)((u8 *)self + 0x29E) + 0x14);
        }
        fn_801A80D8(self, &sp10, &spC, &sp8);
        *(s16 *)((u8 *)self + 0x29E) =
            (s16)(*(s16 *)((u8 *)self + 0x29E) + sp10);
        *(s16 *)((u8 *)self + 0x2A0) =
            (s16)(*(s16 *)((u8 *)self + 0x2A0) + spC);
        *(s16 *)((u8 *)self + 0x2A4) =
            (s16)(*(s16 *)((u8 *)self + 0x2A4) + sp8);
        if (*(s16 *)((u8 *)self + 0x29E) < 0) {
            *(s16 *)((u8 *)self + 0x29E) = 0;
        }
        if (*(s16 *)((u8 *)self + 0x2A0) < 0) {
            *(s16 *)((u8 *)self + 0x2A0) = 0;
        }
        if (*(s16 *)((u8 *)self + 0x2A4) < 0) {
            *(s16 *)((u8 *)self + 0x2A4) = 0;
        }
    }
}

void fn_801A949C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x2B4) = 0;
    M2C_FIELD(arg0, s8 *, 0x2B5) = 0;
    M2C_FIELD(arg0, s8 *, 0x2B6) = 0;
}

#pragma use_lmw_stmw off
void fn_801A94B0(void *arg0)
{
  void *Terrain_GetEntry(u8);
  u8 Status_Test(void *, s32);
  void *fn_8005B73C(void *);
  void *Msg_ResolveName(void *);
  s32 DebugPrint(const char *, ...);
  extern u8 gBattleMap[];
  extern u8 gBattleDebugMsgs[];
  void *tname;
  void *name;
  *((void **) (((u8 *) arg0) + 0x2B0)) = Terrain_GetEntry(gBattleMap[(((s8) (*(((u8 *) arg0) + 0x19E))) + (((s8) (*(((u8 *) arg0) + 0x19F))) << 6)) + 0x100D]);
  if ((*((void **) (((u8 *) arg0) + 0x2B0))) == NULL)
  {
    DebugPrint((const char *) (gBattleDebugMsgs + 0x175));
    return;
  }
  if (Status_Test(((u8 *) arg0) + 0x1BC, 4) != 0)
  {
    *(((u8 *) arg0) + 0x2B4) = (*((u8 **) (((s8 *) (*((void **) (((s8 *) arg0) + 0x2B0)))) + 8)))[4];
    *(((u8 *) arg0) + 0x2B5) = (*((u8 **) (((s8 *) (*((void **) (((s8 *) arg0) + 0x2B0)))) + 8)))[5];
    *(((u8 *) arg0) + 0x2B6) = (*((u8 **) (((s8 *) (*((void **) (((s8 *) arg0) + 0x2B0)))) + 8)))[3];
  }
  else
  {
    *(((u8 *) arg0) + 0x2B4) = (*((u8 **) (((s8 *) (*((void **) (((s8 *) arg0) + 0x2B0)))) + 8)))[1];
    *(((u8 *) arg0) + 0x2B5) = (*((u8 **) (((s8 *) (*((void **) (((s8 *) arg0) + 0x2B0)))) + 8)))[2];
    *(((u8 *) arg0) + 0x2B6) = (*((u8 **) (((s8 *) (*((void **) (((s8 *) arg0) + 0x2B0)))) + 8)))[0];
  }
  name = *((void **) (((u8 *) arg0) + 0x188));
  ;
  DebugPrint((const char *) (gBattleDebugMsgs + 0x18D), Msg_ResolveName(name), fn_8005B73C(*((void **) (((u8 *) arg0) + 0x2B0))), *((s8 *) (((u8 *) arg0) + 0x2B4)), *((s8 *) (((u8 *) arg0) + 0x2B5)), *((s8 *) (((u8 *) arg0) + 0x2B6)));
}
#pragma opt_common_subs off
void fn_801A9600(void *arg0, void *arg1) {
    void Item_Copy(void *, void *);
    u8 Unit_CanEquipItem(void *, void *);
    void Item_Clear(void *);
    void *fn_80037C20(void *);
    extern u16 lbl_80367218;
    s8 flag;
    void *p;
    void *q;
    void *r;

    *(s8 *)((u8 *)arg0 + 0x294) = -1;
    Item_Copy((u8 *)arg0 + 0x284, arg1);
    Item_Copy((u8 *)arg0 + 0x28C, arg1);
    *(u8 *)((u8 *)arg0 + 0x2C8) = *(u8 *)((u8 *)arg1 + 4);
    *(u16 *)((u8 *)arg0 + 0x2AE) = 0;
    flag = *(s8 *)((u8 *)arg0 + 0x2C8);
    if (*(void **)(flag <= 0 ? (void *)&lbl_80367218 : (void *)((u8 *)arg0 + 0x284)) != NULL) {
        void *sel = flag <= 0 ? (void *)&lbl_80367218 : (void *)((u8 *)arg0 + 0x284);
        void *item = *(void * volatile *)sel;
        if (Unit_CanEquipItem(arg0, item) == 0) {
            Item_Clear((u8 *)arg0 + 0x284);
        }
    }
    p = *(void **)((u8 *)arg0 + 0x28C);
    if (p != NULL) {
        *(u16 *)((u8 *)arg0 + 0x2AE) |= *(u16 *)((u8 *)p + 0xC);
    }
    q = fn_80037C20(arg0);
    if (q != NULL) {
        r = *(void **)q;
        if (r != NULL) {
            *(u16 *)((u8 *)arg0 + 0x2AE) |= *(u16 *)((u8 *)r + 0xC);
        }
    }
}
void fn_801A96FC(void *arg0, u8 arg1) {
    void Item_Clear(void *);
    void Item_Copy(void *, void *);
    void *Unit_GetItemSlot(void *, s32);
    u8 Unit_CanEquipItem(void *, void *);
    void **fn_80037C20(void *);
    extern u16 lbl_80367218;
    s8 flag;
    void *item;
    void **held;
    u8 *self = arg0;
    self[0x294] = arg1;
    if ((s8)self[0x294] < 0) {
        Item_Clear(self + 0x284);
        Item_Clear(self + 0x28C);
        return;
    }
    Item_Copy(self + 0x284, Unit_GetItemSlot(self, (s8)self[0x294]));
    Item_Copy(self + 0x28C, Unit_GetItemSlot(self, *(s8 *)(self + 0x294)));
    self[0x2C8] = self[0x288];
    flag = *(s8 *)(self + 0x2C8);
    if (*(void **)(flag <= 0 ? (void *)&lbl_80367218 : (void *)(self + 0x284)) != NULL) {
        void *sel = flag <= 0 ? (void *)&lbl_80367218 : (void *)(self + 0x284);
        void *it = *(void * volatile *)sel;
        if (Unit_CanEquipItem(self, it) == 0) {
            Item_Clear(self + 0x284);
        }
    }
    item = *(void **)(self + 0x28C);
    if (item != NULL) {
        *(u16 *)(self + 0x2AE) |= *(u16 *)((u8 *)item + 0xC);
    }
    held = fn_80037C20(self);
    if (held != NULL) {
        void *r = *held;
        if (r != NULL) {
            *(u16 *)(self + 0x2AE) |= *(u16 *)((u8 *)r + 0xC);
        }
    }
}

void fn_801A981C(void *unit, s32 range, s8 slot) {
    void Item_Clear(void *);
    void Item_Copy(void *, void *);
    void *Unit_GetHeldItemSlot(void *, s32);
    s8 Unit_GetActiveItemSlot(void *);
    u8 Item_GetMaxRange(void *);
    u8 Unit_CanEquipItem(void *, void *);
    void **fn_80037C20(void *);
    extern u16 lbl_80367218;
    u8 *self;
    s8 uses;
    void *base;
    void *item;
    u8 minR;
    u8 maxR;
    void **held;

    self = unit;
    if (slot < 0) {
        self[0x294] = Unit_GetActiveItemSlot(self);
    } else {
        self[0x294] = slot;
    }
    uses = *(s8 *)(self + 0x294);
    if (uses < 0) {
        Item_Clear(self + 0x284);
        Item_Clear(self + 0x28C);
        return;
    }
    Item_Copy(self + 0x284, Unit_GetHeldItemSlot(self, uses));
    uses = *(s8 *)(self + 0x294);
    Item_Copy(self + 0x28C, Unit_GetHeldItemSlot(self, uses));
    self[0x2C8] = self[0x288];
    if (range != 0) {
        uses = *(s8 *)(self + 0x2C8);
        if (uses <= 0) {
            base = &lbl_80367218;
        } else {
            base = self + 0x284;
        }
        item = *(void **)base;
        if (item != NULL) {
            minR = ((u8 *)item)[0x1D];
        } else {
            minR = 0;
        }
        if ((s32)minR <= range) {
            if (uses <= 0) {
                base = &lbl_80367218;
            } else {
                base = self + 0x284;
            }
            if (*(void **)base != NULL) {
                maxR = (u8)Item_GetMaxRange(*(void **)base);
            } else {
                maxR = 0;
            }
            if ((s32)maxR >= range) {
                goto after_clear;
            }
        }
        Item_Clear(self + 0x284);
    after_clear:
        ;
    }
    uses = *(s8 *)(self + 0x2C8);
    if (*(void **)(uses <= 0 ? (void *)&lbl_80367218 : (void *)(self + 0x284)) != NULL) {
        void *sel = uses <= 0 ? (void *)&lbl_80367218 : (void *)(self + 0x284);
        void *it = *(void * volatile *)sel;
        if (Unit_CanEquipItem(self, it) == 0) {
            Item_Clear(self + 0x284);
        }
    }
    item = *(void **)(self + 0x28C);
    if (item != NULL) {
        *(u16 *)(self + 0x2AE) |= *(u16 *)((u8 *)item + 0xC);
    }
    held = fn_80037C20(self);
    if (held != NULL) {
        item = *held;
        if (item != NULL) {
            *(u16 *)(self + 0x2AE) |= *(u16 *)((u8 *)item + 0xC);
        }
    }
}

#pragma opt_common_subs reset
void fn_801A99E8(void *arg0, void *arg1) {
    void *Item_GetFlagsPtr(void *);
    void Item_Clear(void *);
    void *slot;
    if (*(s8 *)((u8 *)arg1+0x2C8)<=0) slot=&lbl_80367218;
    else slot=(u8 *)arg1+0x284;
    if (*(u64 *)Item_GetFlagsPtr(slot)&0x400ULL) Item_Clear((u8 *)arg0+0x284);
    if (*(s8 *)((u8 *)arg0+0x2C8)<=0) slot=&lbl_80367218;
    else slot=(u8 *)arg0+0x284;
    if (*(u64 *)Item_GetFlagsPtr(slot)&0x400ULL) {
        if (*(s8 *)((u8 *)arg1+0x2C8)<=0) slot=&lbl_80367218;
        else slot=(u8 *)arg1+0x284;
        if (!(*(u64 *)Item_GetFlagsPtr(slot)&0x400ULL)) Item_Clear((u8 *)arg0+0x284);
    }
}

#pragma opt_common_subs off
void BattleUnit_Apply(void *arg0) {
    /* Write this battle unit's HP, flags, and weapon changes back onto its linked unit. */
    struct BattleUnit {
        u8 pad0[0x1A4];
        u16 unk1A4;
        u16 unk1A6;
        s8 hp;
        u8 pad1A9[0x1BC - 0x1A9];
        u8 status[0x20C - 0x1BC];
        u8 unk20C[8];
        u8 pad214[0x280 - 0x214];
        void *unit;
        u8 item[8];
        u8 itemSrc[8];
        s8 itemSlot;
        u8 pad295[0x2C8 - 0x295];
        s8 itemUses;
    } *bu = arg0;
    u8 Status_Test(void *, s32);
    void Unit_SetHeldItem(void *, u8, void *);
    void *unit;

    Unit_SetHp(bu->unit, bu->hp);
    unit = bu->unit;
    M2C_FIELD(unit, u16 *, 0x1A4) = bu->unk1A4;
    M2C_FIELD(unit, u16 *, 0x1A6) = bu->unk1A6;
    if (bu->hp == 0 && Status_Test(bu->status, 0x5C) == 0) {
        M2C_FIELD(bu->unit, u32 *, 0x1A0) |= 0x01000000;
    }
    if (bu->itemSlot >= 0) {
        Item_Copy(bu->item, bu->itemSrc);
        Item_SetUses(bu->item, (u8)bu->itemUses);
        Unit_SetHeldItem(bu->unit, bu->itemSlot, bu->item);
        Unit_CompactItems(bu->unit);
        unit = bu->unit;
        M2C_FIELD(unit, u8 *, 0x20C) = bu->unk20C[0];
        M2C_FIELD(unit, u8 *, 0x20D) = bu->unk20C[1];
        M2C_FIELD(unit, u8 *, 0x20E) = bu->unk20C[2];
        M2C_FIELD(unit, u8 *, 0x20F) = bu->unk20C[3];
        M2C_FIELD(unit, u8 *, 0x210) = bu->unk20C[4];
        M2C_FIELD(unit, u8 *, 0x211) = bu->unk20C[5];
        M2C_FIELD(unit, u8 *, 0x212) = bu->unk20C[6];
        M2C_FIELD(unit, u8 *, 0x213) = bu->unk20C[7];
        if (bu->itemUses <= 0) {
            fn_800951D0(bu->unit, -1);
        }
    }
}
#pragma opt_common_subs reset
void fn_801A9C0C(void *arg0) {
    M2C_UNK fn_80050E14(u16, void *);
    M2C_UNK fn_800A89C0(void *);
    M2C_UNK fn_800A8A2C(void *);
    extern u8 gUnitLists[];
    extern u8 lbl_80331B70[];
    extern u8 lbl_80331BD4[];
    extern s8 lbl_80368218;
    extern s8 lbl_80368219;
    u16 temp_r3;

    if (lbl_80368218 == 0) {
        fn_800A8A2C(lbl_80331B70);
        lbl_80368218 = 1;
    }
    if (lbl_80368219 == 0) {
        fn_800A89C0(lbl_80331BD4);
        lbl_80368219 = 1;
    }
    temp_r3 = *(u16 *)(lbl_80331BD4 + 0x3A);
    *(s8 *)(lbl_80331BD4 + 0x4C) = 0x64;
    *(u16 *)(lbl_80331BD4 + 0x3A) = temp_r3 | 0x1000;
    fn_80050E14(temp_r3, lbl_80331BD4);
    *(void **)((u8 *)arg0 + 0x188) = lbl_80331B70;
    *(void **)((u8 *)arg0 + 0x18C) = lbl_80331BD4;
    *(void **)((u8 *)arg0 + 0x190) = gUnitLists;
}

void fn_801A9CB8(void *arg0, s32 arg1) {
    M2C_UNK Unit_Copy();
    Unit_Copy();
    M2C_FIELD(arg0, s32 *, 0x280) = arg1;
}

/* Copy a battle unit: base Unit_Copy, then battle items and combat fields. */
void *BattleUnit_Copy(void *dst, void *src) {
    if (src != dst) {
        Unit_Copy(); /* r3=dst, r4=src still from entry */
        *(u32 *)(((char *)dst) + 0x280) = *(u32 *)(((char *)src) + 0x280);
        Item_Copy(((char *)dst) + 0x284, ((char *)src) + 0x284);
        Item_Copy(((char *)dst) + 0x28C, ((char *)src) + 0x28C);
        *(u8 *)(((char *)dst) + 0x294) = *(u8 *)(((char *)src) + 0x294);
        *(u8 *)(((char *)dst) + 0x295) = *(u8 *)(((char *)src) + 0x295);
        *(u8 *)(((char *)dst) + 0x296) = *(u8 *)(((char *)src) + 0x296);
        *(s16 *)(((char *)dst) + 0x298) = *(s16 *)(((char *)src) + 0x298);
        *(s16 *)(((char *)dst) + 0x29A) = *(s16 *)(((char *)src) + 0x29A);
        *(s16 *)(((char *)dst) + 0x29C) = *(s16 *)(((char *)src) + 0x29C);
        *(s16 *)(((char *)dst) + 0x29E) = *(s16 *)(((char *)src) + 0x29E);
        *(s16 *)(((char *)dst) + 0x2A0) = *(s16 *)(((char *)src) + 0x2A0);
        *(s16 *)(((char *)dst) + 0x2A2) = *(s16 *)(((char *)src) + 0x2A2);
        *(s16 *)(((char *)dst) + 0x2A4) = *(s16 *)(((char *)src) + 0x2A4);
        *(s16 *)(((char *)dst) + 0x2A6) = *(s16 *)(((char *)src) + 0x2A6);
        *(s16 *)(((char *)dst) + 0x2A8) = *(s16 *)(((char *)src) + 0x2A8);
        *(s16 *)(((char *)dst) + 0x2AA) = *(s16 *)(((char *)src) + 0x2AA);
        *(s16 *)(((char *)dst) + 0x2AC) = *(s16 *)(((char *)src) + 0x2AC);
        *(u16 *)(((char *)dst) + 0x2AE) = *(u16 *)(((char *)src) + 0x2AE);
        *(u32 *)(((char *)dst) + 0x2B0) = *(u32 *)(((char *)src) + 0x2B0);
        *(u8 *)(((char *)dst) + 0x2B4) = *(u8 *)(((char *)src) + 0x2B4);
        *(u8 *)(((char *)dst) + 0x2B5) = *(u8 *)(((char *)src) + 0x2B5);
        *(u8 *)(((char *)dst) + 0x2B6) = *(u8 *)(((char *)src) + 0x2B6);
        *(u8 *)(((char *)dst) + 0x2B7) = *(u8 *)(((char *)src) + 0x2B7);
        *(u8 *)(((char *)dst) + 0x2B8) = *(u8 *)(((char *)src) + 0x2B8);
        *(s16 *)(((char *)dst) + 0x2BA) = *(s16 *)(((char *)src) + 0x2BA);
        *(s16 *)(((char *)dst) + 0x2BC) = *(s16 *)(((char *)src) + 0x2BC);
        *(s16 *)(((char *)dst) + 0x2BE) = *(s16 *)(((char *)src) + 0x2BE);
        *(s16 *)(((char *)dst) + 0x2C0) = *(s16 *)(((char *)src) + 0x2C0);
        *(s16 *)(((char *)dst) + 0x2C2) = *(s16 *)(((char *)src) + 0x2C2);
        *(s16 *)(((char *)dst) + 0x2C4) = *(s16 *)(((char *)src) + 0x2C4);
        *(u8 *)(((char *)dst) + 0x2C6) = *(u8 *)(((char *)src) + 0x2C6);
        *(u8 *)(((char *)dst) + 0x2C7) = *(u8 *)(((char *)src) + 0x2C7);
        *(u8 *)(((char *)dst) + 0x2C8) = *(u8 *)(((char *)src) + 0x2C8);
        *(u8 *)(((char *)dst) + 0x2C9) = *(u8 *)(((char *)src) + 0x2C9);
        *(u8 *)(((char *)dst) + 0x2CA) = *(u8 *)(((char *)src) + 0x2CA);
        *(u8 *)(((char *)dst) + 0x2CB) = *(u8 *)(((char *)src) + 0x2CB);
        *(u8 *)(((char *)dst) + 0x2CC) = *(u8 *)(((char *)src) + 0x2CC);
        *(s16 *)(((char *)dst) + 0x2CE) = *(s16 *)(((char *)src) + 0x2CE);
        *(u8 *)(((char *)dst) + 0x2D6) = *(u8 *)(((char *)src) + 0x2D6);
        *(u8 *)(((char *)dst) + 0x2D7) = *(u8 *)(((char *)src) + 0x2D7);
        *(u8 *)(((char *)dst) + 0x2D8) = *(u8 *)(((char *)src) + 0x2D8);
        *(u8 *)(((char *)dst) + 0x2D9) = *(u8 *)(((char *)src) + 0x2D9);
        *(u8 *)(((char *)dst) + 0x2DA) = *(u8 *)(((char *)src) + 0x2DA);
        *(u8 *)(((char *)dst) + 0x2DB) = *(u8 *)(((char *)src) + 0x2DB);
        *(u8 *)(((char *)dst) + 0x2DC) = *(u8 *)(((char *)src) + 0x2DC);
        *(u8 *)(((char *)dst) + 0x2DD) = *(u8 *)(((char *)src) + 0x2DD);
        *(u8 *)(((char *)dst) + 0x2DE) = *(u8 *)(((char *)src) + 0x2DE);
    }
    return dst;
}

void BattleUnit_Reset(void *bu) {
    /* Clear the unit base, then zero battle-only fields (items, combat stats, flags). */
    void Unit_Clear(void *, s32);
    void Item_Clear(void *);

    Unit_Clear(bu, 0);
    *(u32*)(((char*)bu) + 0x280) = 0;
    Item_Clear(((char*)bu) + 0x284);
    Item_Clear(((char*)bu) + 0x28C);
    *(s8*)(((char*)bu) + 0x294) = -1;
    *(u8*)(((char*)bu) + 0x295) = 0;
    *(u8*)(((char*)bu) + 0x296) = 0;
    *(s16*)(((char*)bu) + 0x298) = 0;
    *(s16*)(((char*)bu) + 0x29A) = 0;
    *(s16*)(((char*)bu) + 0x29C) = 0;
    *(s16*)(((char*)bu) + 0x29E) = 0;
    *(s16*)(((char*)bu) + 0x2A0) = 0;
    *(s16*)(((char*)bu) + 0x2A2) = 0;
    *(s16*)(((char*)bu) + 0x2A4) = 0;
    *(s16*)(((char*)bu) + 0x2A6) = 0;
    *(s16*)(((char*)bu) + 0x2A8) = 0;
    *(s16*)(((char*)bu) + 0x2AA) = 0;
    *(s16*)(((char*)bu) + 0x2AC) = 0;
    *(u16*)(((char*)bu) + 0x2AE) = 0;
    *(u32*)(((char*)bu) + 0x2B0) = 0;
    *(u8*)(((char*)bu) + 0x2B4) = 0;
    *(u8*)(((char*)bu) + 0x2B5) = 0;
    *(u8*)(((char*)bu) + 0x2B6) = 0;
    *(s16*)(((char*)bu) + 0x2C2) = 0;
    *(s16*)(((char*)bu) + 0x2C4) = 0;
    *(u8*)(((char*)bu) + 0x2C6) = 0;
    *(u8*)(((char*)bu) + 0x2C7) = 0;
    *(u8*)(((char*)bu) + 0x2C8) = 0;
    *(u8*)(((char*)bu) + 0x2C9) = 0;
    *(u8*)(((char*)bu) + 0x2CA) = 0;
    *(u8*)(((char*)bu) + 0x2CB) = 0;
    *(u8*)(((char*)bu) + 0x2CC) = 0;
    *(s16*)(((char*)bu) + 0x2CE) = 0;
    *(u32*)(((char*)bu) + 0x2D0) = 0;
    *(u8*)(((char*)bu) + 0x2D4) = 0;
    *(u8*)(((char*)bu) + 0x2D5) = 0;
    *(u8*)(((char*)bu) + 0x2D6) = 0;
    *(u8*)(((char*)bu) + 0x2DE) = 0;
    *(u8*)(((char*)bu) + 0x2DD) = 0;
    *(u8*)(((char*)bu) + 0x2DC) = 0;
    *(u8*)(((char*)bu) + 0x2DB) = 0;
    *(u8*)(((char*)bu) + 0x2DA) = 0;
    *(u8*)(((char*)bu) + 0x2D9) = 0;
    *(u8*)(((char*)bu) + 0x2D8) = 0;
    *(u8*)(((char*)bu) + 0x2D7) = 0;
    *(u8*)(((char*)bu) + 0x2B7) = 0xFF;
    *(u8*)(((char*)bu) + 0x2B8) = 0xFF;
    *(s16*)(((char*)bu) + 0x2BA) = -1;
    *(s16*)(((char*)bu) + 0x2BC) = -1;
    *(s16*)(((char*)bu) + 0x2BE) = -1;
    *(s16*)(((char*)bu) + 0x2C0) = -1;
}

s32 fn_801A9FC8(void) {
    return 0;
}

s32 fn_801A9FD0(void) {
    return 0;
}

#pragma optimization_level 1
s32 fn_801A9FD8(s32 arg0)
{
    s32 z;

    z = 0;
    arg0 = *(s32 *)((u8 *)arg0 + 0x1A0);
    arg0 = (arg0 >> 12) & 1;
    arg0 = -arg0;
    return z & ~arg0;
}
#pragma optimization_level reset
s32 fn_801A9FF0(void) {
    return 0;
}

s32 fn_801A9FF8(void) {
    return 0;
}

void fn_801AA000(s32 unused, void *arg1) {
    extern u8 lbl_8027B808[];
    void fn_800F3860(void *, void *, s32);

    fn_800F3860(arg1, lbl_8027B808 + 0x1D, 0x1D);
}

s32 fn_801AA034(void) {
    return 0;
}

void fn_801AA03C(s32 unused, s32 arg1) {
    void Ai_TryAttackAction(s32, s32);
    Ai_TryAttackAction(arg1, 0x15);
}

#pragma optimization_level 2
u8 fn_801AA064(void *arg0, void *arg1, void *arg2) {
    u8 Status_Test(void *, s32);
    extern s32 lbl_80297278[];
    extern u8 gAiState[];
    s32 *entry;
    void (*handler)(void *, void *);
    u8 key;

    key = *(u8 *)((u8 *)arg1 + 0x18);
    if (Status_Test((u8 *)arg0 + 0x1BC, key) != 0) {
        entry = lbl_80297278;
        goto check;
        do {
            if ((s32)key == entry[0]) {
                if (handler == NULL) {
                    goto next;
                } else {
                    goto found;
                }
            }
        next:
            entry += 2;
        check:
            handler = (void (*)(void *, void *))entry[1];
        } while (handler != NULL);
    }
    entry = NULL;
found:
    if (entry == NULL) {
        return 0;
    }
    ((void (*)(void *, void *))entry[1])(arg0, arg2);
    return gAiState[0x21C];
}
#pragma optimization_level reset
extern u8 lbl_802973C8[16];
void fn_801AA120(s32 arg0) {
    void Process_CreateChild(void *, s32);
    extern u8 lbl_802973C8[16];
    Process_CreateChild(lbl_802973C8, arg0);
}

void fn_801AA14C(void *arg0) {
    M2C_UNK fn_800A7EC4();
    M2C_FIELD(arg0, u8 *, 0x30) = (u8) (M2C_FIELD(arg0, u8 *, 0x30) & 0xFE);
    fn_800A7EC4();
}

void fn_801AA178(void *arg0)
{
    void GfxEnt_UnlinkByName(void *);
    extern u8 lbl_8027B838[];

    *(u8 *)((u8 *)arg0 + 0x30) |= 1;
    GfxEnt_UnlinkByName(lbl_8027B838 + 0x2bd);
}

void fn_801AA1B0(void *arg0) {
    M2C_UNK fn_80057A10(s32, M2C_UNK);
    M2C_UNK fn_801AB004(void *);
    M2C_UNK Process_Unlink(s32);
    M2C_UNK FileCache_ReleaseSlot(void *);
    struct Obj {
        u8 pad[0x50];
        u32 field50;
    };
    struct Obj *obj = arg0;

    if (*(u8 *)((u8 *)arg0 + 0x69) == 0) {
        fn_80057A10(*(s32 *)((u8 *)arg0 + 0x54), 1);
        fn_80057A10(*(s32 *)((u8 *)arg0 + 0x58), 1);
        fn_801AB004(arg0);
        Process_Unlink(*(s32 *)((u8 *)arg0 + 0x6C));
        if (obj->field50 != 0) {
            FileCache_ReleaseSlot(&obj->field50);
        }
        *(u8 *)((u8 *)arg0 + 0x69) = 1;
    }
}

void fn_801AA228(void *arg0)
{
    extern u8 *gPadInput;
    extern u8 gOptionsTable[];
    extern u8 lbl_8027B838[];
    extern f32 lbl_8036AF98;
    extern f32 lbl_8036AF9C;
    extern u8 lbl_80367AE8;
    extern u8 lbl_80367AEA;
    void Ui_PlaySeCue(void *, s32);
    void Process_Goto(void *, s32);
    void fn_80057E6C(void *);
    void fn_80145E9C(s32);
    void fn_80209854(s32);
    void fn_80025624(void *, s32);
    u8 *p = (u8 *)arg0;
    u8 before = p[0x3C];
    u32 held = *(u32 *)(gPadInput + 4);
    u32 previous = *(u32 *)(gPadInput + 8);
    u32 repeat = *(u32 *)(gPadInput + 12);
    u32 edge = held & (previous ^ held);
    s32 i;
    u8 *entry;
    s32 top;
    u8 value;
    s32 next;
    u16 flags;

    if (edge & 0x200) {
        Ui_PlaySeCue(lbl_8027B838 + 0x2C8, 100);
        Process_Goto(arg0, 3);
        return;
    }
    if (repeat & 0x08000008) {
        i = before;
        entry = gOptionsTable + i * 12;
        while (i > 0) {
            entry -= 12;
            --i;
            if (*entry != 0) break;
        }
        if (i >= 0) p[0x3C] = (u8)i;
        top = p[0x36];
        if ((s32)p[0x3C] - top <= 0 && top != 0) {
            p[0x36] = (u8)(top - 1);
            *(f32 *)(p + 0x38) = lbl_8036AF98;
            fn_80057E6C(*(void **)(p + 0x54));
        }
        p[0x3D] = 4;
        *(s16 *)(p + 0x48) = *(s16 *)(p + 0x44);
        *(s16 *)(p + 0x4A) = *(s16 *)(p + 0x46);
        *(s16 *)(p + 0x4C) = 20;
        *(s16 *)(p + 0x4E) = (s16)((p[0x3C] - p[0x36]) * 32 + 127);
    }
    if (repeat & 0x04000004) {
        i = p[0x3C];
        entry = gOptionsTable + i * 12;
        while (i < 22) {
            entry += 12;
            ++i;
            if (*entry != 0) break;
        }
        if (i < 22) p[0x3C] = (u8)i;
        top = p[0x36];
        if ((s32)p[0x3C] - top >= 7 && top < p[0x31] - 8) {
            p[0x36] = (u8)(top + 1);
            *(f32 *)(p + 0x38) = lbl_8036AF9C;
            fn_80057E6C(*(void **)(p + 0x58));
        }
        p[0x3D] = 4;
        *(s16 *)(p + 0x48) = *(s16 *)(p + 0x44);
        *(s16 *)(p + 0x4A) = *(s16 *)(p + 0x46);
        *(s16 *)(p + 0x4C) = 20;
        *(s16 *)(p + 0x4E) = (s16)((p[0x3C] - p[0x36]) * 32 + 127);
    }
    if (p[0x3C] != before)
        Ui_PlaySeCue(lbl_8027B838 + 0x2D8, 100);

    switch (p[0x3C]) {
    case 0:
        if ((edge & 0x100) && p[0x5E] == 2) {
            Process_Goto(arg0, 1);
            Ui_PlaySeCue(lbl_8027B838 + 0x2F4, 100);
            break;
        }
        value = p[0x5E];
        if (repeat & 0x01000001) {
            next = (s32)p[0x5E] - 1;
            next &= ~(next >> 31);
            p[0x5E] = (u8)next;
        }
        if (repeat & 0x02000002) {
            next = (s32)p[0x5E] + 1;
            if (next > 2) next = 2;
            p[0x5E] = (u8)next;
        }
        if (p[0x5E] != value) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 1:
        flags = *(u16 *)(p + 0x5C);
        if (repeat & 0x01000001)
            *(u16 *)(p + 0x5C) = flags | 0x4000;
        if (repeat & 0x02000002)
            *(u16 *)(p + 0x5C) &= (u16)~0x4000;
        if (*(u16 *)(p + 0x5C) != flags) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 2:
        value = p[0x5F];
        if (repeat & 0x01000001) {
            next = (s32)p[0x5F] - 1;
            next &= ~(next >> 31);
            p[0x5F] = (u8)next;
        }
        if (repeat & 0x02000002) {
            next = (s32)p[0x5F] + 1;
            if (next > 1) next = 1;
            p[0x5F] = (u8)next;
        }
        if (p[0x5F] != value) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 3:
        value = p[0x60];
        if (repeat & 0x01000001) {
            next = (s32)p[0x60] - 1;
            next &= ~(next >> 31);
            p[0x60] = (u8)next;
        }
        if (repeat & 0x02000002) {
            next = (s32)p[0x60] + 1;
            if (next > 3) next = 3;
            p[0x60] = (u8)next;
        }
        if (p[0x60] != value) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 4:
        if (edge & 0x400) p[0x61] = 20;
        if (held & 0x01000001) {
            next = (s32)p[0x61] - 1;
            next &= ~(next >> 31);
            p[0x61] = (u8)next;
        }
        if (held & 0x02000002) {
            next = (s32)p[0x61] + 1;
            if (next > 100) next = 100;
            p[0x61] = (u8)next;
        }
        break;
    case 5:
        flags = *(u16 *)(p + 0x5C);
        if (repeat & 0x01000001)
            *(u16 *)(p + 0x5C) = flags | 0x1;
        if (repeat & 0x02000002)
            *(u16 *)(p + 0x5C) &= (u16)~0x1;
        if (*(u16 *)(p + 0x5C) != flags) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 6:
        flags = *(u16 *)(p + 0x5C);
        if (repeat & 0x01000001)
            *(u16 *)(p + 0x5C) = flags | 0x2;
        if (repeat & 0x02000002)
            *(u16 *)(p + 0x5C) &= (u16)~0x2;
        if (*(u16 *)(p + 0x5C) != flags) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 7:
        value = p[0x62];
        if (repeat & 0x01000001) {
            next = (s32)p[0x62] - 1;
            next &= ~(next >> 31);
            p[0x62] = (u8)next;
        }
        if (repeat & 0x02000002) {
            next = (s32)p[0x62] + 1;
            if (next > 2) next = 2;
            p[0x62] = (u8)next;
        }
        if (p[0x62] != value) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 8:
        value = p[0x63];
        if (repeat & 0x01000001) {
            next = (s32)p[0x63] - 1;
            next &= ~(next >> 31);
            p[0x63] = (u8)next;
        }
        if (repeat & 0x02000002) {
            next = (s32)p[0x63] + 1;
            if (next > 2) next = 2;
            p[0x63] = (u8)next;
        }
        if (p[0x63] != value) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 9:
        flags = *(u16 *)(p + 0x5C);
        if (repeat & 0x01000001)
            *(u16 *)(p + 0x5C) = flags | 0x20;
        if (repeat & 0x02000002)
            *(u16 *)(p + 0x5C) &= (u16)~0x20;
        if (*(u16 *)(p + 0x5C) != flags) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 10:
        flags = *(u16 *)(p + 0x5C);
        if (repeat & 0x01000001)
            *(u16 *)(p + 0x5C) = flags | 0x40;
        if (repeat & 0x02000002)
            *(u16 *)(p + 0x5C) &= (u16)~0x40;
        if (*(u16 *)(p + 0x5C) != flags) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 11:
        flags = *(u16 *)(p + 0x5C);
        if (repeat & 0x01000001)
            *(u16 *)(p + 0x5C) = flags | 0x80;
        if (repeat & 0x02000002)
            *(u16 *)(p + 0x5C) &= (u16)~0x80;
        if (*(u16 *)(p + 0x5C) != flags) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 12:
        if (edge & 0x100) {
            Process_Goto(arg0, 2);
            Ui_PlaySeCue(lbl_8027B838 + 0x2F4, 100);
        }
        break;
    case 13:
        flags = *(u16 *)(p + 0x5C);
        if (repeat & 0x01000001)
            *(u16 *)(p + 0x5C) = flags | 0x100;
        if (repeat & 0x02000002)
            *(u16 *)(p + 0x5C) &= (u16)~0x100;
        if (*(u16 *)(p + 0x5C) != flags) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 14:
        flags = *(u16 *)(p + 0x5C);
        if (repeat & 0x01000001)
            *(u16 *)(p + 0x5C) = flags | 0x200;
        if (repeat & 0x02000002)
            *(u16 *)(p + 0x5C) &= (u16)~0x200;
        if (*(u16 *)(p + 0x5C) != flags) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 15:
        flags = *(u16 *)(p + 0x5C);
        if (repeat & 0x01000001)
            *(u16 *)(p + 0x5C) = flags | 0x400;
        if (repeat & 0x02000002)
            *(u16 *)(p + 0x5C) &= (u16)~0x400;
        if (*(u16 *)(p + 0x5C) != flags) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 16:
        flags = *(u16 *)(p + 0x5C);
        if (repeat & 0x01000001)
            *(u16 *)(p + 0x5C) = flags | 0x2000;
        if (repeat & 0x02000002)
            *(u16 *)(p + 0x5C) &= (u16)~0x2000;
        if (*(u16 *)(p + 0x5C) != flags) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    case 17:
        value = p[0x66];
        if (repeat & 0x01000001) {
            next = (s32)p[0x66] - 1;
            next &= ~(next >> 31);
            p[0x66] = (u8)next;
            fn_80145E9C(p[0x66]);
        }
        if (repeat & 0x02000002) {
            next = (s32)p[0x66] + 1;
            if (next > 2) next = 2;
            p[0x66] = (u8)next;
            fn_80145E9C(p[0x66]);
        }
        if (p[0x66] != value) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
            if (p[0x66] == 0) fn_80209854(0);
            else if (p[0x66] < 3) fn_80209854(1);
        }
        break;
    case 18:
        value = p[0x67];
        if (held & 0x01000001) {
            next = (s32)p[0x67] - 1;
            next &= ~(next >> 31);
            p[0x67] = (u8)next;
            lbl_80367AE8 = p[0x67];
        }
        if (held & 0x02000002) {
            next = (s32)p[0x67] + 1;
            if (next > 100) next = 100;
            p[0x67] = (u8)next;
            lbl_80367AE8 = p[0x67];
        }
        if ((edge & 0x400) && p[0x67] != value) {
            p[0x68] = p[0x67];
            lbl_80367AEA = p[0x68];
        }
        break;
    case 19:
        value = p[0x68];
        if (held & 0x01000001) {
            next = (s32)p[0x68] - 1;
            next &= ~(next >> 31);
            p[0x68] = (u8)next;
            lbl_80367AEA = p[0x68];
        }
        if (held & 0x02000002) {
            next = (s32)p[0x68] + 1;
            if (next > 100) next = 100;
            p[0x68] = (u8)next;
            lbl_80367AEA = p[0x68];
        }
        if ((edge & 0x400) && p[0x68] != value) {
            p[0x67] = p[0x68];
            lbl_80367AE8 = p[0x67];
        }
        break;
    case 20:
        flags = *(u16 *)(p + 0x5C);
        if (repeat & 0x01000001)
            *(u16 *)(p + 0x5C) = flags | 0x800;
        if (repeat & 0x02000002)
            *(u16 *)(p + 0x5C) &= (u16)~0x800;
        if (*(u16 *)(p + 0x5C) != flags) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
            if (*(u16 *)(p + 0x5C) & 0x800)
                fn_80025624(gPadInput, 8);
        }
        break;
    case 21:
        flags = *(u16 *)(p + 0x5C);
        if (repeat & 0x01000001)
            *(u16 *)(p + 0x5C) = flags | 0x1000;
        if (repeat & 0x02000002)
            *(u16 *)(p + 0x5C) &= (u16)~0x1000;
        if (*(u16 *)(p + 0x5C) != flags) {
            Ui_PlaySeCue(lbl_8027B838 + 0x304, 100);
        }
        break;
    }
}

#pragma peephole off
void fn_801AAD74(void *arg0)
{
    void fn_801AA228(void *);
    switch (*(s16 *)((char *)arg0 + 0x32)) {
    case 0:
        fn_801AA228(arg0);
        break;
    default:
        break;
    }
}
#pragma peephole reset

#pragma optimization_level 4
#pragma opt_common_subs off
void fn_801AADA4(void *arg0) {
    s32 Process_AttachFunc(void *, void *);
    u16 FileCache_GetFlags(char *);
    void fn_8006EEFC(void *, void *);
    void Process_ClearFunc(void *);
    void fn_801ADA50(void *);
    extern u8 lbl_8027B838[];
    if (FileCache_GetFlags((char *)lbl_8027B838 + 0x320) & 0x2000) {
        fn_8006EEFC((char *)arg0 + 0x50, (char *)lbl_8027B838 + 0x320);
        *(s32 *)((char *)arg0 + 0x6C) = Process_AttachFunc(fn_801ADA50, arg0);
        Process_ClearFunc(arg0);
    }
}

void fn_801AAE14(void *arg0) {
    void *Heap_Alloc(s32);
    void *fn_80057A64(void *, s32);
    void fn_80057E98(void *, s32, s32);
    void fn_80057E5C(void *, s32);
    void fn_80057E54(void *, s32);
    void fn_80057E90(void *, f32);
    void fn_8005C8B4(void *);
    u8 SystemSave_TestFlag0(void *);
    void Options_LoadFromBattleState(void *);
    extern u8 gOptionsTable[];
    extern u8 gSystemSave[];
    extern char lbl_8027B838[];
    u8 *self;
    void *obj;
    s32 i;
    s32 n;
    s32 a;
    s32 b;

    n = 0x15;
    a = 0x14;
    b = 0x7F;
    self = (u8 *)arg0;
    self[0x30] = 0;
    *(s16 *)(self + 0x32) = 0;
    *(s16 *)(self + 0x34) = 0;
    self[0x3D] = 0;
    self[0x36] = 0;
    *(f32 *)(self + 0x38) = 0.0f;
    self[0x3C] = 0;
    self[0x3D] = 0;
    *(f32 *)(self + 0x40) = 0.0f;
    *(s16 *)(self + 0x44) = a;
    *(s16 *)(self + 0x46) = b;
    for (i = 0; i < n + 1; i++) {
        gOptionsTable[i * 0xC] = 1;
    }
    if (SystemSave_TestFlag0(gSystemSave) == 0) {
        self[0x31] = n;
        gOptionsTable[0xFC] = 0;
    } else {
        self[0x31] = 0x16;
    }
    Options_LoadFromBattleState(self);
    obj = Heap_Alloc(0x58);
    if (obj != 0) {
        obj = fn_80057A64(obj, 8);
    }
    *(void **)(self + 0x54) = obj;
    fn_80057E98(*(void **)(self + 0x54), 0x22A, 0x7E);
    fn_80057E5C(*(void **)(self + 0x54), 0);
    fn_80057E54(*(void **)(self + 0x54), 1);
    fn_80057E90(*(void **)(self + 0x54), 130.0f);
    obj = Heap_Alloc(0x58);
    if (obj != 0) {
        obj = fn_80057A64(obj, 4);
    }
    *(void **)(self + 0x58) = obj;
    fn_80057E98(*(void **)(self + 0x58), 0x22A, 0x176);
    fn_80057E5C(*(void **)(self + 0x58), 0);
    fn_80057E54(*(void **)(self + 0x58), 1);
    fn_80057E90(*(void **)(self + 0x58), 130.0f);
    fn_8005C8B4(lbl_8027B838 + 0x320);
    self[0x69] = 0;
    *(s32 *)(self + 0x50) = 0;
}

void fn_801AB004(void *arg0) {
    extern u8 gBattleState[];

    typedef struct {
        u8 c67 : 2;
        u8 c5 : 1;
        u8 c34 : 2;
        u8 c2 : 1;
        u8 c1 : 1;
        u8 c0 : 1;
        u8 d67 : 2;
        u8 d5 : 1;
        u8 d4 : 1;
        u8 d23 : 2;
        u8 d1 : 1;
        u8 d0 : 1;
        u8 e7 : 1;
        u8 e6 : 1;
        u8 e5 : 1;
        u8 e4 : 1;
        u8 e23 : 2;
        u8 e1 : 1;
        u8 e0 : 1;
        u8 padF6 : 2;
        u8 f5 : 1;
        u8 f4 : 1;
        u8 padF0 : 4;
    } Bits;

    u8 *bs = gBattleState;
    Bits *b = (Bits *)&bs[0x9C];
    u8 *p = (u8 *)arg0;

    b->c67 = p[0x5E];
    if (*(u16 *)&p[0x5C] & 0x4000) {
        b->f4 = 0;
    } else {
        b->f4 = 1;
    }
    b->c5 = p[0x5F];
    b->c34 = p[0x60];
    bs[0xA0] = p[0x61];
    if (*(u16 *)&p[0x5C] & 0x1) {
        b->c2 = 0;
    } else {
        b->c2 = 1;
    }
    if (*(u16 *)&p[0x5C] & 0x2) {
        b->c1 = 0;
    } else {
        b->c1 = 1;
    }
    if (*(u16 *)&p[0x5C] & 0x4) {
        b->c0 = 0;
    } else {
        b->c0 = 1;
    }
    b->d67 = p[0x62];
    if (*(u16 *)&p[0x5C] & 0x8) {
        b->d5 = 0;
    } else {
        b->d5 = 1;
    }
    if (*(u16 *)&p[0x5C] & 0x10) {
        b->d4 = 0;
    } else {
        b->d4 = 1;
    }
    b->d23 = p[0x63];
    if (*(u16 *)&p[0x5C] & 0x20) {
        b->d1 = 0;
    } else {
        b->d1 = 1;
    }
    if (*(u16 *)&p[0x5C] & 0x40) {
        b->d0 = 0;
    } else {
        b->d0 = 1;
    }
    if (*(u16 *)&p[0x5C] & 0x80) {
        b->e7 = 0;
    } else {
        b->e7 = 1;
    }
    if (*(u16 *)&p[0x5C] & 0x100) {
        b->e6 = 0;
    } else {
        b->e6 = 1;
    }
    if (*(u16 *)&p[0x5C] & 0x200) {
        b->e5 = 0;
    } else {
        b->e5 = 1;
    }
    if (*(u16 *)&p[0x5C] & 0x400) {
        b->e4 = 0;
    } else {
        b->e4 = 1;
    }
    if (*(u16 *)&p[0x5C] & 0x2000) {
        b->f5 = 0;
    } else {
        b->f5 = 1;
    }
    b->e23 = p[0x66];
    bs[0xA4] = p[0x67];
    bs[0xA5] = p[0x68];
    if (*(u16 *)&p[0x5C] & 0x800) {
        b->e1 = 0;
    } else {
        b->e1 = 1;
    }
    if (*(u16 *)&p[0x5C] & 0x1000) {
        b->e0 = 0;
        return;
    }
    b->e0 = 1;
}

void Options_LoadFromBattleState(u8 *opt) {
    extern u8 gBattleState[];
    u8 *cfg = gBattleState;
    struct {
        u8 hi : 6;
        u8 mid : 1;
        u8 lo : 1;
    } *bf;

    // Load packed options from gBattleState into the Options UI object.
    *(u16 *)(opt + 0x5C) = 0;
    opt[0x5E] = (u8)((cfg[0x9C] >> 6) & 3);
    if (!((cfg[0x9F] >> 4) & 1)) {
        *(u16 *)(opt + 0x5C) |= 0x4000;
    }
    opt[0x5F] = (u8)((cfg[0x9C] >> 5) & 1);
    opt[0x60] = (u8)((cfg[0x9C] >> 3) & 3);
    opt[0x61] = cfg[0xA0];
    if (!((cfg[0x9C] >> 2) & 1)) {
        *(u16 *)(opt + 0x5C) |= 1;
    }
    if (!((cfg[0x9C] >> 1) & 1)) {
        *(u16 *)(opt + 0x5C) |= 2;
    }
    if (!(cfg[0x9C] & 1)) {
        *(u16 *)(opt + 0x5C) |= 4;
    }
    opt[0x62] = (u8)((cfg[0x9D] >> 6) & 3);
    if (!((cfg[0x9D] >> 5) & 1)) {
        *(u16 *)(opt + 0x5C) |= 8;
    }
    if (!((cfg[0x9D] >> 4) & 1)) {
        *(u16 *)(opt + 0x5C) |= 0x10;
    }
    opt[0x63] = (u8)((cfg[0x9D] >> 2) & 3);
    if (!((cfg[0x9D] >> 1) & 1)) {
        *(u16 *)(opt + 0x5C) |= 0x20;
    }
    if (!(cfg[0x9D] & 1)) {
        *(u16 *)(opt + 0x5C) |= 0x40;
    }
    if (!((cfg[0x9E] >> 7) & 1)) {
        *(u16 *)(opt + 0x5C) |= 0x80;
    }
    if (!((cfg[0x9E] >> 6) & 1)) {
        *(u16 *)(opt + 0x5C) |= 0x100;
    }
    if (!((cfg[0x9E] >> 5) & 1)) {
        *(u16 *)(opt + 0x5C) |= 0x200;
    }
    if (!((cfg[0x9E] >> 4) & 1)) {
        *(u16 *)(opt + 0x5C) |= 0x400;
    }
    if (!((cfg[0x9F] >> 5) & 1)) {
        *(u16 *)(opt + 0x5C) |= 0x2000;
    }
    opt[0x66] = (u8)((cfg[0x9E] >> 2) & 3);
    opt[0x67] = cfg[0xA4];
    opt[0x68] = cfg[0xA5];
    if (!((cfg[0x9E] >> 1) & 1)) {
        *(u16 *)(opt + 0x5C) |= 0x800;
    }
    if (!(cfg[0x9E] & 1)) {
        *(u16 *)(opt + 0x5C) |= 0x1000;
    }
    bf = (void *)&cfg[0x9E];
    bf->mid = 0;
}

void Options_DrawScrollbar(void *arg0) {
    /* Draw the options-list scrollbar thumb as three textured quads. */
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    u16 **fn_8006EDD8(void *, s32);
    void *Ui_GetColor(s32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    extern f64 lbl_8036AFE0;
    extern f64 lbl_8036AFC0;
    extern f32 lbl_8036AFC8;
    extern f32 lbl_8036AF9C;
    extern f32 lbl_8036AFA0;
    extern f32 lbl_8036AFCC;
    extern f32 lbl_8036AFD4;
    extern f32 lbl_8036AFD0;
    extern f32 lbl_8036AFD8;
    typedef struct {
        u8 pad[0x31];
        u8 count;
        u8 pad32[0x36 - 0x32];
        u8 scrollIndex;
        u8 pad37;
        f32 scrollPos;
        u8 pad3C[0x50 - 0x3C];
        void *texBank;
    } Obj;
    s32 y;
    Obj *self;
    f32 h;
    f32 w;
    u16 *tex;
    u32 col1;
    u32 col0;
    u32 col2;

    self = (Obj *)arg0;
    y = (s32)(lbl_8036AFC8 * (((f32)self->scrollIndex - self->scrollPos) / (f32)(self->count - 8)));
    tex = *fn_8006EDD8(self->texBank, 5);
    h = (f32)tex[0] * lbl_8036AF9C;
    w = (f32)tex[1] * lbl_8036AF9C;
    col0 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->texBank, 5, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036AFCC, (f32)(y + 0x88), lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036AFCC + w, (f32)(y + 0x88) + h, lbl_8036AFA0 + w, lbl_8036AFA0 + h);
    Prim2D_SetColor(((u8 *)&col0)[0], ((u8 *)&col0)[1], ((u8 *)&col0)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    col1 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->texBank, 6, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036AFCC, (f32)(y + 0x8C), lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036AFD0, (f32)(y + 0x8C) + lbl_8036AFD4, lbl_8036AFD8, lbl_8036AFD4);
    Prim2D_SetColor(((u8 *)&col1)[0], ((u8 *)&col1)[1], ((u8 *)&col1)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    tex = *fn_8006EDD8(self->texBank, 7);
    h = (f32)tex[0] * lbl_8036AF9C;
    w = (f32)tex[1] * lbl_8036AF9C;
    col2 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->texBank, 7, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036AFCC, (f32)(y + 0xCA), lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036AFCC + w, (f32)(y + 0xCA) + h, lbl_8036AFA0 + w, lbl_8036AFA0 + h);
    Prim2D_SetColor(((u8 *)&col2)[0], ((u8 *)&col2)[1], ((u8 *)&col2)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
}

void fn_801AB8A8(void *self, s32 option, f32 x, f32 y, f32 unused) {
void Prim2D_Begin(void); void Prim2D_SetTex(s32,s32); void Prim2D_PrepareTex(void);
void *Msg_Expand(void *); void fn_8001003C(s32,s32,s32,s32,s32,...);
extern u8 gOptionsTable[],lbl_8027B838[];
extern f32 lbl_8036AFE8,lbl_8036AFEC,lbl_8036AF9C,lbl_8036AFA0,lbl_8036AFF0,lbl_8036AFF4,lbl_8036AFF8,lbl_8036AFFC,lbl_8036B000;
void Prim2D_AddZ(f32); u16 **fn_8006EDD8(void *,s32); void *Ui_GetColor(s32);
void Prim2D_BindTexture(void *,s32,s32); void Prim2D_AddPrim(s32);
void Prim2D_SetQuadMin(f32,f32,f32,f32); void Prim2D_SetQuadMax(f32,f32,f32,f32);
void Prim2D_SetColor(u8,u8,u8,s32); void Prim2D_EmitQuad(void); void Prim2D_EndPrim(void);
extern f32 lbl_8036AF98,lbl_8036AFD8,lbl_8036B004,lbl_8036B008,lbl_8036B00C,lbl_8036B010,lbl_8036B014,lbl_8036B018,lbl_8036B01C,lbl_8036B020,lbl_8036B024;
u32 col1,col3,col5,col0,col2,col4;
u16 *tex;
f32 w,h,xx,yy;
f32 left=lbl_8036AFE8+x;
u8 color;
void *text;
Prim2D_Begin(); Prim2D_SetTex(0,0x13); Prim2D_PrepareTex();
text=Msg_Expand(*(void **)(gOptionsTable+option*12+4));
fn_8001003C((s32)(lbl_8036AFEC+x),(s32)y,1,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
switch(option) {
case 0:
color=1; if(M2C_FIELD(self,u8 *,0x5e)==0x0) color=20;
text=Msg_Expand(lbl_8027B838+0x368);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if(M2C_FIELD(self,u8 *,0x5e)==0x1) color=20;
text=Msg_Expand(lbl_8027B838+0x370);
fn_8001003C((s32)(left+lbl_8036AFF0),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if(M2C_FIELD(self,u8 *,0x5e)==0x2) color=20;
text=Msg_Expand(lbl_8027B838+0x379);
fn_8001003C((s32)(left+lbl_8036AFF4),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 1:
color=1; if((M2C_FIELD(self,u16 *,0x5c)&16384)!=0) color=20;
text=Msg_Expand(lbl_8027B838+0x384);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if((M2C_FIELD(self,u16 *,0x5c)&16384)==0) color=20;
text=Msg_Expand(lbl_8027B838+0x392);
fn_8001003C((s32)(left+lbl_8036AFF4),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 2:
color=1; if(M2C_FIELD(self,u8 *,0x5f)==0x0) color=20;
text=Msg_Expand(lbl_8027B838+0x39f);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if(M2C_FIELD(self,u8 *,0x5f)==0x1) color=20;
text=Msg_Expand(lbl_8027B838+0x3ab);
fn_8001003C((s32)(left+lbl_8036AFF4),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 3:
color=1; if(M2C_FIELD(self,u8 *,0x60)==0x0) color=20;
text=Msg_Expand(lbl_8027B838+0x3b5);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if(M2C_FIELD(self,u8 *,0x60)==0x1) color=20;
text=Msg_Expand(lbl_8027B838+0x39f);
fn_8001003C((s32)(left+lbl_8036AFF8),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if(M2C_FIELD(self,u8 *,0x60)==0x2) color=20;
text=Msg_Expand(lbl_8027B838+0x3ab);
fn_8001003C((s32)(left+lbl_8036AFFC),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if(M2C_FIELD(self,u8 *,0x60)==0x3) color=20;
text=Msg_Expand(lbl_8027B838+0x3bf);
fn_8001003C((s32)(left+lbl_8036B000),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 4:
tex=*fn_8006EDD8(M2C_FIELD(self,void **,0x50),2);
h=(f32)tex[0]*lbl_8036AF9C; w=(f32)tex[1]*lbl_8036AF9C;
col0=*(u32 *)Ui_GetColor(1);
Prim2D_Begin(); Prim2D_BindTexture(M2C_FIELD(self,void **,0x50),2,0x11);
Prim2D_PrepareTex(); Prim2D_AddPrim(1);
yy=lbl_8036B004+y;
Prim2D_SetQuadMin(left,yy,lbl_8036AFA0,lbl_8036AFA0);
Prim2D_SetQuadMax(left+w,yy+h,lbl_8036AFA0+w,lbl_8036AFA0+h);
Prim2D_SetColor(((u8 *)&col0)[0],((u8 *)&col0)[1],((u8 *)&col0)[2],255);
Prim2D_EmitQuad(); Prim2D_EndPrim();
Prim2D_Begin(); Prim2D_AddZ(lbl_8036AF98); Prim2D_PrepareTex();
w=(f32)((M2C_FIELD(self,u8 *,97)*208)/100);
col1=*(u32 *)Ui_GetColor(1);
Prim2D_Begin(); Prim2D_BindTexture(M2C_FIELD(self,void **,0x50),3,0x11);
Prim2D_PrepareTex(); Prim2D_AddPrim(1);
xx=lbl_8036B008+left; yy=lbl_8036B00C+y;
Prim2D_SetQuadMin(xx,yy,lbl_8036AFA0,lbl_8036AFA0);
Prim2D_SetQuadMax(xx+w,yy+lbl_8036AFD8,lbl_8036AFA0+w,lbl_8036AFD8);
Prim2D_SetColor(((u8 *)&col1)[0],((u8 *)&col1)[1],((u8 *)&col1)[2],255);
Prim2D_EmitQuad(); Prim2D_EndPrim();
Prim2D_Begin(); Prim2D_AddZ(lbl_8036AF9C); Prim2D_PrepareTex();
break;
case 5:
color=1; if((M2C_FIELD(self,u16 *,0x5c)&1)!=0) color=20;
text=Msg_Expand(lbl_8027B838+0x368);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if((M2C_FIELD(self,u16 *,0x5c)&1)==0) color=20;
text=Msg_Expand(lbl_8027B838+0x370);
fn_8001003C((s32)(left+lbl_8036B010),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 6:
color=1; if((M2C_FIELD(self,u16 *,0x5c)&2)!=0) color=20;
text=Msg_Expand(lbl_8027B838+0x368);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if((M2C_FIELD(self,u16 *,0x5c)&2)==0) color=20;
text=Msg_Expand(lbl_8027B838+0x370);
fn_8001003C((s32)(left+lbl_8036B010),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 7:
color=1; if(M2C_FIELD(self,u8 *,0x62)==0x0) color=20;
text=Msg_Expand(lbl_8027B838+0x3cd);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if(M2C_FIELD(self,u8 *,0x62)==0x1) color=20;
text=Msg_Expand(lbl_8027B838+0x3d9);
fn_8001003C((s32)(left+lbl_8036B014),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if(M2C_FIELD(self,u8 *,0x62)==0x2) color=20;
text=Msg_Expand(lbl_8027B838+0x370);
fn_8001003C((s32)(left+lbl_8036B018),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 8:
color=1; if(M2C_FIELD(self,u8 *,0x63)==0x0) color=20;
text=Msg_Expand(lbl_8027B838+0x3e5);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if(M2C_FIELD(self,u8 *,0x63)==0x1) color=20;
text=Msg_Expand(lbl_8027B838+0x3f1);
fn_8001003C((s32)(left+lbl_8036B014),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if(M2C_FIELD(self,u8 *,0x63)==0x2) color=20;
text=Msg_Expand(lbl_8027B838+0x370);
fn_8001003C((s32)(left+lbl_8036B018),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 9:
color=1; if((M2C_FIELD(self,u16 *,0x5c)&32)!=0) color=20;
text=Msg_Expand(lbl_8027B838+0x368);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if((M2C_FIELD(self,u16 *,0x5c)&32)==0) color=20;
text=Msg_Expand(lbl_8027B838+0x370);
fn_8001003C((s32)(left+lbl_8036B010),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 10:
color=1; if((M2C_FIELD(self,u16 *,0x5c)&64)!=0) color=20;
text=Msg_Expand(lbl_8027B838+0x3fe);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if((M2C_FIELD(self,u16 *,0x5c)&64)==0) color=20;
text=Msg_Expand(lbl_8027B838+0x40c);
fn_8001003C((s32)(left+lbl_8036B01C),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 11:
color=1; if((M2C_FIELD(self,u16 *,0x5c)&128)!=0) color=20;
text=Msg_Expand(lbl_8027B838+0x3fe);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if((M2C_FIELD(self,u16 *,0x5c)&128)==0) color=20;
text=Msg_Expand(lbl_8027B838+0x40c);
fn_8001003C((s32)(left+lbl_8036B01C),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 12:
text=Msg_Expand(lbl_8027B838+0x419);
fn_8001003C((s32)(left),(s32)y,1,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 13:
color=1; if((M2C_FIELD(self,u16 *,0x5c)&256)!=0) color=20;
text=Msg_Expand(lbl_8027B838+0x368);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if((M2C_FIELD(self,u16 *,0x5c)&256)==0) color=20;
text=Msg_Expand(lbl_8027B838+0x370);
fn_8001003C((s32)(left+lbl_8036B010),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 14:
color=1; if((M2C_FIELD(self,u16 *,0x5c)&512)!=0) color=20;
text=Msg_Expand(lbl_8027B838+0x368);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if((M2C_FIELD(self,u16 *,0x5c)&512)==0) color=20;
text=Msg_Expand(lbl_8027B838+0x370);
fn_8001003C((s32)(left+lbl_8036B010),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 15:
color=1; if((M2C_FIELD(self,u16 *,0x5c)&1024)!=0) color=20;
text=Msg_Expand(lbl_8027B838+0x368);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if((M2C_FIELD(self,u16 *,0x5c)&1024)==0) color=20;
text=Msg_Expand(lbl_8027B838+0x370);
fn_8001003C((s32)(left+lbl_8036B010),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 16:
color=1; if((M2C_FIELD(self,u16 *,0x5c)&8192)!=0) color=20;
text=Msg_Expand(lbl_8027B838+0x368);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if((M2C_FIELD(self,u16 *,0x5c)&8192)==0) color=20;
text=Msg_Expand(lbl_8027B838+0x370);
fn_8001003C((s32)(left+lbl_8036B010),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 17:
color=1; if(M2C_FIELD(self,u8 *,0x66)==0x0) color=20;
text=Msg_Expand(lbl_8027B838+0x427);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if(M2C_FIELD(self,u8 *,0x66)==0x1) color=20;
text=Msg_Expand(lbl_8027B838+0x431);
fn_8001003C((s32)(left+lbl_8036B020),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if(M2C_FIELD(self,u8 *,0x66)==0x2) color=20;
text=Msg_Expand(lbl_8027B838+0x43d);
fn_8001003C((s32)(left+lbl_8036B024),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 18:
tex=*fn_8006EDD8(M2C_FIELD(self,void **,0x50),2);
h=(f32)tex[0]*lbl_8036AF9C; w=(f32)tex[1]*lbl_8036AF9C;
col2=*(u32 *)Ui_GetColor(1);
Prim2D_Begin(); Prim2D_BindTexture(M2C_FIELD(self,void **,0x50),2,0x11);
Prim2D_PrepareTex(); Prim2D_AddPrim(1);
yy=lbl_8036B004+y;
Prim2D_SetQuadMin(left,yy,lbl_8036AFA0,lbl_8036AFA0);
Prim2D_SetQuadMax(left+w,yy+h,lbl_8036AFA0+w,lbl_8036AFA0+h);
Prim2D_SetColor(((u8 *)&col2)[0],((u8 *)&col2)[1],((u8 *)&col2)[2],255);
Prim2D_EmitQuad(); Prim2D_EndPrim();
Prim2D_Begin(); Prim2D_AddZ(lbl_8036AF98); Prim2D_PrepareTex();
w=(f32)((M2C_FIELD(self,u8 *,103)*208)/100);
col3=*(u32 *)Ui_GetColor(1);
Prim2D_Begin(); Prim2D_BindTexture(M2C_FIELD(self,void **,0x50),3,0x11);
Prim2D_PrepareTex(); Prim2D_AddPrim(1);
xx=lbl_8036B008+left; yy=lbl_8036B00C+y;
Prim2D_SetQuadMin(xx,yy,lbl_8036AFA0,lbl_8036AFA0);
Prim2D_SetQuadMax(xx+w,yy+lbl_8036AFD8,lbl_8036AFA0+w,lbl_8036AFD8);
Prim2D_SetColor(((u8 *)&col3)[0],((u8 *)&col3)[1],((u8 *)&col3)[2],255);
Prim2D_EmitQuad(); Prim2D_EndPrim();
Prim2D_Begin(); Prim2D_AddZ(lbl_8036AF9C); Prim2D_PrepareTex();
break;
case 19:
tex=*fn_8006EDD8(M2C_FIELD(self,void **,0x50),2);
h=(f32)tex[0]*lbl_8036AF9C; w=(f32)tex[1]*lbl_8036AF9C;
col4=*(u32 *)Ui_GetColor(1);
Prim2D_Begin(); Prim2D_BindTexture(M2C_FIELD(self,void **,0x50),2,0x11);
Prim2D_PrepareTex(); Prim2D_AddPrim(1);
yy=lbl_8036B004+y;
Prim2D_SetQuadMin(left,yy,lbl_8036AFA0,lbl_8036AFA0);
Prim2D_SetQuadMax(left+w,yy+h,lbl_8036AFA0+w,lbl_8036AFA0+h);
Prim2D_SetColor(((u8 *)&col4)[0],((u8 *)&col4)[1],((u8 *)&col4)[2],255);
Prim2D_EmitQuad(); Prim2D_EndPrim();
Prim2D_Begin(); Prim2D_AddZ(lbl_8036AF98); Prim2D_PrepareTex();
w=(f32)((M2C_FIELD(self,u8 *,104)*208)/100);
col5=*(u32 *)Ui_GetColor(1);
Prim2D_Begin(); Prim2D_BindTexture(M2C_FIELD(self,void **,0x50),3,0x11);
Prim2D_PrepareTex(); Prim2D_AddPrim(1);
xx=lbl_8036B008+left; yy=lbl_8036B00C+y;
Prim2D_SetQuadMin(xx,yy,lbl_8036AFA0,lbl_8036AFA0);
Prim2D_SetQuadMax(xx+w,yy+lbl_8036AFD8,lbl_8036AFA0+w,lbl_8036AFD8);
Prim2D_SetColor(((u8 *)&col5)[0],((u8 *)&col5)[1],((u8 *)&col5)[2],255);
Prim2D_EmitQuad(); Prim2D_EndPrim();
Prim2D_Begin(); Prim2D_AddZ(lbl_8036AF9C); Prim2D_PrepareTex();
break;
case 20:
color=1; if((M2C_FIELD(self,u16 *,0x5c)&2048)!=0) color=20;
text=Msg_Expand(lbl_8027B838+0x368);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if((M2C_FIELD(self,u16 *,0x5c)&2048)==0) color=20;
text=Msg_Expand(lbl_8027B838+0x370);
fn_8001003C((s32)(left+lbl_8036B010),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
case 21:
color=1; if((M2C_FIELD(self,u16 *,0x5c)&4096)!=0) color=20;
text=Msg_Expand(lbl_8027B838+0x368);
fn_8001003C((s32)(left),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
color=1; if((M2C_FIELD(self,u16 *,0x5c)&4096)==0) color=20;
text=Msg_Expand(lbl_8027B838+0x370);
fn_8001003C((s32)(left+lbl_8036B010),(s32)y,color,0,0,text,lbl_8036AF9C,lbl_8036AFA0);
break;
}
}

#pragma push
#pragma opt_lifetimes off
void fn_801ACF4C(void *arg0) {
    extern u8 lbl_80368220;
    extern u16 lbl_80368224[4];
    extern f32 lbl_8036AFA0;
    extern f32 lbl_8036B028;
    extern u8 gOptionsTable[];
    extern f32 lbl_8036B030;
    extern f32 lbl_8036B01C;
    extern f32 lbl_8036B02C;
    extern void fn_801ADD58;
    void Prim2D_Begin(void);
    void Prim2D_SetCallback(void *, void *);
    void Prim2D_PrepareTex(void);
    void Prim2D_ClearCallbacks(void);
    void fn_801AB8A8(void *self, s32 option, f32 x, f32 y);

    s32 temp_r4;
    s32 var_r30;
    f32 var_f1;
    f32 var_f2;
    u16 a;
    u16 b;
    u16 c;
    u16 d;

    if ((s8)lbl_80368220 == 0) {
        lbl_80368220 = 1;
    }
    a = 0x30;
    b = 0x80;
    c = 0x208;
    d = 0xFE;
    var_f1 = lbl_8036AFA0;
    lbl_80368224[0] = a;
    lbl_80368224[1] = b;
    lbl_80368224[2] = c;
    lbl_80368224[3] = d;
    var_f2 = *(f32 *)((char *)arg0 + 0x38);
    if (var_f2 > var_f1) {
        *(f32 *)((char *)arg0 + 0x38) = var_f2 - lbl_8036B028;
        if (*(f32 *)((char *)arg0 + 0x38) < var_f1) {
            *(f32 *)((char *)arg0 + 0x38) = var_f1;
        }
    }
    var_f2 = *(f32 *)((char *)arg0 + 0x38);
    var_f1 = lbl_8036AFA0;
    if (var_f2 < var_f1) {
        *(f32 *)((char *)arg0 + 0x38) = var_f2 + lbl_8036B028;
        if (*(f32 *)((char *)arg0 + 0x38) > var_f1) {
            *(f32 *)((char *)arg0 + 0x38) = var_f1;
        }
    }
    Prim2D_Begin();
    Prim2D_SetCallback(&fn_801ADD58, lbl_80368224);
    Prim2D_PrepareTex();
    var_r30 = 0;
    do {
        temp_r4 = var_r30 - 1;
        temp_r4 = *(u8 *)((char *)arg0 + 0x36) + temp_r4;
        if ((temp_r4 >= 0) && (temp_r4 < *(u8 *)((char *)arg0 + 0x31)) && (*(u8 *)(gOptionsTable + (temp_r4 * 0xC)) == 1)) {
            fn_801AB8A8(arg0, temp_r4, lbl_8036B02C, (lbl_8036B030 * (f32)var_r30 + lbl_8036B01C) + lbl_8036B030 * *(f32 *)((char *)arg0 + 0x38));
        }
        var_r30 += 1;
    } while (var_r30 < 0xA);
    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
}
#pragma pop
void fn_801AD0B0(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    u16 **fn_8006EDD8(void *, s32);
    void *Ui_GetColor(s32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    void fn_801ACF4C(void *);
    void Options_DrawScrollbar(void *);
    extern f32 lbl_8036AF98, lbl_8036AF9C, lbl_8036AFA0, lbl_8036B004;
    extern f32 lbl_8036B030, lbl_8036B034, lbl_8036B038, lbl_8036B03C;
    extern f32 lbl_8036B040, lbl_8036B044, lbl_8036B048, lbl_8036B04C;
    extern f32 lbl_8036B050, lbl_8036B054, lbl_8036B058, lbl_8036B05C;
    extern f32 lbl_8036B060, lbl_8036B064, lbl_8036B068, lbl_8036B06C;
    extern f32 lbl_8036B070, lbl_8036B074, lbl_8036B078, lbl_8036B07C, lbl_8036B080;

    typedef struct { u8 pad[0x50]; void *unk50; } Obj;
    u32 col2;
    u32 col5;
    u32 col7;
    u32 col8;
    u32 col0;
    u32 col1;
    u32 col3;
    u32 col4;
    u32 col6;
    Obj *self;
    u16 *tex;
    f32 width8;
    f32 height8;
    f32 heightA;
    f32 widthA;
    f32 heightD;
    f32 widthD;
    f32 heightF;
    f32 widthF;
    f32 width;
    f32 height;
    f32 f30;
    f32 f31;

    self = (Obj *)arg0;
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036AF98);
    Prim2D_PrepareTex();
    tex = *fn_8006EDD8(self->unk50, 4);
    f30 = (f32)tex[0] * lbl_8036AF9C;
    f31 = (f32)tex[1] * lbl_8036AF9C;
    col0 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->unk50, 4, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B030, lbl_8036B034, lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036B030 + f31, lbl_8036B034 + f30, lbl_8036AFA0 + f31, lbl_8036AFA0 + f30);
    Prim2D_SetColor(((u8 *)&col0)[0], ((u8 *)&col0)[1], ((u8 *)&col0)[2], 0xDF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036AF98);
    Prim2D_PrepareTex();
    tex = *fn_8006EDD8(self->unk50, 8);
    width8 = (f32)tex[0] * lbl_8036AF9C;
    height8 = (f32)tex[1] * lbl_8036AF9C;
    col1 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->unk50, 8, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B030, lbl_8036B038, lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036B030 + height8, lbl_8036B038 + width8, lbl_8036AFA0 + height8, lbl_8036AFA0 + width8);
    Prim2D_SetColor(((u8 *)&col1)[0], ((u8 *)&col1)[1], ((u8 *)&col1)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    col2 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->unk50, 9, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B03C, lbl_8036B034, lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036B040, lbl_8036B044, lbl_8036B048, lbl_8036B004);
    Prim2D_SetColor(((u8 *)&col2)[0], ((u8 *)&col2)[1], ((u8 *)&col2)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    tex = *fn_8006EDD8(self->unk50, 0xA);
    widthA = (f32)tex[0] * lbl_8036AF9C;
    heightA = (f32)tex[1] * lbl_8036AF9C;
    col3 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->unk50, 0xA, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B040, lbl_8036B034, lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036B040 + heightA, lbl_8036B034 + widthA, lbl_8036AFA0 + heightA, lbl_8036AFA0 + widthA);
    Prim2D_SetColor(((u8 *)&col3)[0], ((u8 *)&col3)[1], ((u8 *)&col3)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    tex = *fn_8006EDD8(self->unk50, 0xD);
    widthD = (f32)tex[0] * lbl_8036AF9C;
    heightD = (f32)tex[1] * lbl_8036AF9C;
    col4 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->unk50, 0xD, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B04C, lbl_8036B050, lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036B04C + heightD, lbl_8036B050 + widthD, lbl_8036AFA0 + heightD, lbl_8036AFA0 + widthD);
    Prim2D_SetColor(((u8 *)&col4)[0], ((u8 *)&col4)[1], ((u8 *)&col4)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    col5 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->unk50, 0xE, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B054, lbl_8036B058, lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036B05C, lbl_8036B060, lbl_8036B064, lbl_8036B004);
    Prim2D_SetColor(((u8 *)&col5)[0], ((u8 *)&col5)[1], ((u8 *)&col5)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    tex = *fn_8006EDD8(self->unk50, 0xF);
    widthF = (f32)tex[0] * lbl_8036AF9C;
    heightF = (f32)tex[1] * lbl_8036AF9C;
    col6 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->unk50, 0xF, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B05C, lbl_8036B050, lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036B05C + heightF, lbl_8036B050 + widthF, lbl_8036AFA0 + heightF, lbl_8036AFA0 + widthF);
    Prim2D_SetColor(((u8 *)&col6)[0], ((u8 *)&col6)[1], ((u8 *)&col6)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    col7 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->unk50, 0xB, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B030, lbl_8036B068, lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036B06C, lbl_8036B070, lbl_8036B004, lbl_8036B074);
    Prim2D_SetColor(((u8 *)&col7)[0], ((u8 *)&col7)[1], ((u8 *)&col7)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    col8 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->unk50, 0xC, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B078, lbl_8036B068, lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036B07C, lbl_8036B070, lbl_8036B004, lbl_8036B074);
    Prim2D_SetColor(((u8 *)&col8)[0], ((u8 *)&col8)[1], ((u8 *)&col8)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    fn_801ACF4C(self);
    Options_DrawScrollbar(self);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B080);
    Prim2D_PrepareTex();
}

void Options_DrawHeader(void *arg0) {
    /* Draw options header decoration and the selected entry title. */
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    u16 **fn_8006EDD8(void *, s32);
    void *Ui_GetColor(s32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    void Prim2D_SetTex(s32, s32);
    void *Msg_Expand(void *);
    void fn_8001003C(s32, s32, s32, s32, s32, ...);
    extern f32 lbl_8036B084;
    extern f64 lbl_8036AFE0;
    extern f32 lbl_8036AF9C;
    extern f32 lbl_8036AFA0;
    extern f32 lbl_8036B088;
    extern f32 lbl_8036AFEC;
    extern f32 lbl_8036B080;
    extern f32 lbl_8036AF98;
    extern f32 lbl_8036B08C;
    extern f32 lbl_8036B090;
    typedef struct {
        u8 pad[0x3C];
        u8 selected;
        u8 pad3D[0x50 - 0x3D];
        void *texBank;
    } Obj;
    typedef struct {
        u8 pad[8];
        void *ptr;
    } Row;
    extern Row gOptionsTable[];
    Obj *self;
    f32 h;
    f32 w;
    u16 *tex;
    u32 col0;
    u32 col1;
    u32 col2;
    f32 t;
    void *str;

    self = (Obj *)arg0;
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B084);
    Prim2D_PrepareTex();
    tex = *fn_8006EDD8(self->texBank, 0);
    h = (f32)tex[0] * lbl_8036AF9C;
    w = (f32)tex[1] * lbl_8036AF9C;
    col0 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->texBank, 0, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B088, lbl_8036AFEC, lbl_8036AFA0, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036B088 + w, lbl_8036AFEC + h, lbl_8036AFA0 + w, lbl_8036AFA0 + h);
    Prim2D_SetColor(((u8 *)&col0)[0], ((u8 *)&col0)[1], ((u8 *)&col0)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B080);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036AF98);
    Prim2D_PrepareTex();
    tex = *fn_8006EDD8(self->texBank, 1);
    h = (f32)tex[0] * lbl_8036AF9C;
    w = (f32)tex[1] * lbl_8036AF9C;
    col1 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->texBank, 1, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036AFA0, lbl_8036B08C, lbl_8036AFA0, lbl_8036AFA0);
    t = lbl_8036AFA0 + w;
    Prim2D_SetQuadMax(t, lbl_8036B08C + h, t, lbl_8036AFA0 + h);
    Prim2D_SetColor(((u8 *)&col1)[0], ((u8 *)&col1)[1], ((u8 *)&col1)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    tex = *fn_8006EDD8(self->texBank, 1);
    h = (f32)tex[0] * lbl_8036AF9C;
    w = (f32)tex[1] * lbl_8036AF9C;
    col2 = *(u32 *)Ui_GetColor(1);
    Prim2D_Begin();
    Prim2D_BindTexture(self->texBank, 1, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B090, lbl_8036B08C, lbl_8036AFA0 + w, lbl_8036AFA0);
    Prim2D_SetQuadMax(lbl_8036B090 + w, lbl_8036B08C + h, lbl_8036AFA0, lbl_8036AFA0 + h);
    Prim2D_SetColor(((u8 *)&col2)[0], ((u8 *)&col2)[1], ((u8 *)&col2)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036AF98);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    str = Msg_Expand(gOptionsTable[self->selected].ptr);
    fn_8001003C(0x64, 0x3D, 2, 0, 0, str, lbl_8036AF9C, lbl_8036AFA0);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B080);
    Prim2D_PrepareTex();
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
void fn_801ADA50(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    void Options_DrawHeader(void *);
    void fn_801AD0B0(void *);
    void *Msg_Expand(void *);
    void strcpy(void *, void *);
    void strcat(void *, void *);
    void Ui_DrawCaptionBar(void *, s32);
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Prim2D_AddZ(f32);
    void Ui_DrawRouteIconEx(s32, s32, s32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    void fn_80057E64(void *, s32);
    void fn_80057AE0(void *);
    extern const f32 lbl_8036B094;
    extern const f32 lbl_8036B098;
    extern const f32 lbl_8036AFA0;
    extern const f32 lbl_8036AFFC;
    extern const f32 lbl_8036AF9C;
    extern u8 lbl_8027B838[];
    extern f64 lbl_8036AFC0;
    extern const f32 lbl_8036AFA8;
    extern const f32 lbl_8036AFAC;
    extern const f32 lbl_8036AFB0;
    extern const f32 lbl_8036AFB4;
    extern const f32 lbl_8036AFB8;
    typedef struct {
        u8 pad30[0x30];
        u8 unk30;
        u8 unk31;
        u8 pad32[0x36 - 0x32];
        u8 unk36;
        u8 pad37[0x3D - 0x37];
        u8 unk3D;
        u8 pad3E[0x40 - 0x3E];
        f32 unk40;
        s16 unk44;
        s16 unk46;
        s16 unk48;
        s16 unk4A;
        s16 unk4C;
        s16 unk4E;
        u8 pad50[0x54 - 0x50];
        void *unk54;
        void *unk58;
    } Obj;
    Obj *self;
    s32 t;
    char sp8[0x80];
    f32 f1;
    f32 a;
    f32 b;
    f32 lim;
    s16 x0, x1;

    self = (Obj *)arg0;
    if (!(self->unk30 & 1)) {
        self->unk40 += lbl_8036B094;
        if (self->unk40 >= lbl_8036B098) self->unk40 -= lbl_8036B098;
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_SetTransform(lbl_8036AFA0, lbl_8036AFA0, lbl_8036AFFC, lbl_8036AF9C);
        Prim2D_PrepareTex();
        Options_DrawHeader(self);
        fn_801AD0B0(self);
        strcpy(sp8, Msg_Expand(lbl_8027B838 + 0x336));
        strcat(sp8, lbl_8027B838 + 0x346);
        strcat(sp8, Msg_Expand(lbl_8027B838 + 0x349));
        strcat(sp8, lbl_8027B838 + 0x346);
        strcat(sp8, Msg_Expand(lbl_8027B838 + 0x35C));
        Ui_DrawCaptionBar(sp8, 0);
        if (self->unk3D != 0) {
            self->unk3D -= 1;
            x0 = self->unk48;
            x1 = self->unk4C;
            t = 4 - self->unk3D;
            self->unk44 = (s16)Math_Ease(4, (f32)x0, (f32)x1, (f32)t, lbl_8036AFA8);
            x0 = self->unk4A;
            x1 = self->unk4E;
            self->unk46 = (s16)Math_Ease(4, (f32)x0, (f32)x1, (f32)t, lbl_8036AFA8);
        }
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036AFAC);
        Prim2D_PrepareTex();
        Ui_DrawRouteIconEx(self->unk44 + 0x1C, self->unk46 + 3, 1);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036AFB0);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036AFB4);
        Prim2D_PrepareTex();
        fn_8008AB7C(self->unk44 + 0x91, self->unk46 + 0xD, 0xE6, 0x18, 0x19, 0x4B, 1);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036AFB8);
        Prim2D_PrepareTex();
        if (self->unk36 == 0) {
            fn_80057E64(self->unk54, 0);
        } else {
            fn_80057E64(self->unk54, 1);
        }
        if (self->unk36 == (self->unk31 - 8)) {
            fn_80057E64(self->unk58, 0);
        } else {
            fn_80057E64(self->unk58, 1);
        }
        fn_80057AE0(self->unk54);
        fn_80057AE0(self->unk58);
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}
#pragma pop
void fn_801ADD58(s32 unused, s16 *p) {
    extern void GXSetScissor(s16, s16, s16, s16);
    GXSetScissor(p[0], p[1], p[2], p[3]);
}

#pragma cplusplus on
extern "C" void fn_801ADD8C(void *arg0) {
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

/* Move options focus among the main 8-slot row and the two bottom panes; play UI SE on change. */
extern "C" void Options_HandleFocusInput(void *opt) {
    extern u8 Options_SeCues[];
    extern void *gPadInput;
    void Ui_PlaySeCue(void *, s32);
    extern s32 gUiInputFlags;
    u8 blocked;
    s16 cursor;
    s32 held;
    s32 buttons;
    s16 next_focus;
    s32 pressed;
    s16 focus;

    blocked = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        blocked = 1;
    }
    if (blocked == 0) {
        focus = *(s16 *)((char *)opt + 0x3E);
        buttons = *(s32 *)((char *)gPadInput + 4);
        held = *(s32 *)((char *)gPadInput + 0xC);
        cursor = *(s16 *)((char *)opt + 0x40);
        pressed = buttons & (*(s32 *)((char *)gPadInput + 8) ^ buttons);
        switch (focus) {
        case 0:
            if (pressed & 0x04000004) {
                next_focus = 2;
                if (cursor < 4) {
                    next_focus = 1;
                }
                *(s16 *)((char *)opt + 0x3E) = next_focus;
            } else if (held & 0x01000001) {
                if ((cursor == 0) && (held == pressed)) {
                    *(s16 *)((char *)opt + 0x40) = 7;
                } else if (0 < cursor) {
                    *(s16 *)((char *)opt + 0x40) = *(s16 *)((char *)opt + 0x40) - 1;
                }
            } else if (held & 0x02000002) {
                if ((cursor == 7) && (held == pressed)) {
                    *(s16 *)((char *)opt + 0x40) = 0;
                } else if (cursor < 7) {
                    *(s16 *)((char *)opt + 0x40) = *(s16 *)((char *)opt + 0x40) + 1;
                }
            }
            break;
        case 1:
            if (pressed & 0x02000002) {
                *(s16 *)((char *)opt + 0x3E) = 2;
            } else if (pressed & 0x08000008) {
                *(s16 *)((char *)opt + 0x3E) = 0;
                if (*(s16 *)((char *)opt + 0x40) < 0) {
                    *(s16 *)((char *)opt + 0x40) = 0;
                }
            }
            break;
        case 2:
            if (pressed & 0x01000001) {
                *(s16 *)((char *)opt + 0x3E) = 1;
            } else if (pressed & 0x08000008) {
                *(s16 *)((char *)opt + 0x3E) = 0;
                if (*(s16 *)((char *)opt + 0x40) < 0) {
                    *(s16 *)((char *)opt + 0x40) = 0;
                }
            }
            break;
        }
        if (focus != *(s16 *)((char *)opt + 0x3E)) {
            Ui_PlaySeCue((u8 *)Options_SeCues + 0x39, 0x64);
        }
        if (cursor != *(s16 *)((char *)opt + 0x40)) {
            Ui_PlaySeCue((u8 *)Options_SeCues + 0x55, 0x64);
        }
    }
}

#pragma peephole off
void fn_801ADFCC(void *arg0, void *arg1) {
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Ui_DrawRouteIconEx(s32, s32, s32);
    void Prim2D_SetAlphaByte(s32);
    extern f32 lbl_8036B0A0;
#pragma cplusplus on
    struct Obj { virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void update(void *)=0; };
    s32 active;
    s16 x;
    s16 y;
    u8 *self = (u8 *)arg0;
    u8 *ctx = (u8 *)arg1;
    ((Obj *)arg0)->update(arg1);
    switch (*(s16 *)(self + 0x3E)) {
    case 0: x = *(s16 *)(self + 0x40) * 26 + 27; y = 16; break;
    case 1: x = 36; y = 64; break;
    case 2: x = 144; y = 64; break;
    }
    {
        s16 t42 = *(s16 *)(self + 0x42);
        if ((s16)t42 < 0 || *(s16 *)(self + 0x44) < 0) {
            *(s16 *)(self + 0x42) = x;
            *(s16 *)(self + 0x44) = y;
        } else {
            *(s16 *)(self + 0x42) = (s16)((s32)(t42 + x + 1) >> 1);
            *(s16 *)(self + 0x44) = (s16)((s32)(*(s16 *)(self + 0x44) + y + 1) >> 1);
        }
    }
    if (self[0x3C]) {
        u8 ready;
        active = 0;
        ready = active;
        if (ctx[0x2D] == 0) {
            if (ctx[0x2E] == 0) {
                ready = 1;
            }
        }
        if (ready) {
            void *selected;
            if (*(u32 *)(ctx + 0x34)) selected = *(void **)(*(u8 **)(ctx + 0x38) + 8);
            else selected = 0;
            if (selected == self) active = 1;
        }
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B0A0);
        Prim2D_PrepareTex();
        Ui_DrawRouteIconEx(*(s16 *)(self + 0x42), *(s16 *)(self + 0x44), active);
    }
    Prim2D_Begin();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
#pragma cplusplus reset
}
#pragma peephole reset
extern "C" void fn_801AE154(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
    };
    void fn_80152548(s32, s32, s32);
    void fn_801527B0(s32, s32, s32);
    void fn_8015267C(s32, s32, s32);

    ((Obj *)arg0)->v3();
    fn_80152548(0x16, 0x10, 0x10);
    fn_801527B0(0x1C, 0x40, 0x10);
    fn_8015267C(0x88, 0x40, 0x10);
}
#pragma cplusplus reset
void fn_801AE1B0(void *arg0, void *arg1) {
    s32 *fn_8013F748(void *, void *, s16 *);
    void *spC;
    s16 sp8[2];
    s16 a;
    s16 b;
    s16 sel;

    sel = *(s16 *)((u8 *)arg1 + 0x3E);
    switch (sel) {
    case 0:
        a = (s16)(*(s16 *)((u8 *)arg1 + 0x40) * 0x1A + 0x28);
        b = 0x18;
        break;
    case 1:
        a = 0x24;
        b = 0x50;
        break;
    case 2:
        a = 0x90;
        b = 0x50;
        break;
    }
    sp8[0] = a;
    sp8[1] = b;
    *(s32 *)arg0 = *fn_8013F748(arg1, &spC, sp8);
}

s32 fn_801AE24C(void *arg0) {
    extern s32 lbl_80297590[];
    return lbl_80297590[M2C_FIELD(arg0, s16 *, 0x3E)];
}

void *fn_801AE264(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_8029759C[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_8029759C;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_801AE2D0(void) {

}
#include "common.h"
extern u16 lbl_80367218;
