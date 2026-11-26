/* Functions from 0x800330F8 to 0x80055C70, found by decomp-toolkit. */
#include "common.h"
extern f64 lbl_80368F90;
static inline void Map_WriteColorVertex(f32 x, f32 y, f32 z, const u8 *color) {
u8 r=color[0],g=color[1],b=color[2],a=color[3];
*(volatile f32 *)0xCC008000=x;
*(volatile f32 *)0xCC008000=y;
*(volatile f32 *)0xCC008000=z;
*(volatile u8 *)0xCC008000=r;
*(volatile u8 *)0xCC008000=g;
*(volatile u8 *)0xCC008000=b;
*(volatile u8 *)0xCC008000=a;
}
typedef struct { void *ptr; u8 pad[4]; } Elem8_8003A1E0;
static inline s32 get_4F128_id(void *arg0) {
 void *Unit_GetActiveItemPtr(void *);
 s32 fn_8004ABD4(void *,s32);
 s32 value=M2C_FIELD(arg0,s8 *,0x16C);
 if(value>=0)return value;
 return fn_8004ABD4(Unit_GetActiveItemPtr(arg0),0);
}
static inline void *get_4F128_resource(void *arg0,s32 value) {
  void fn_800056A0(s32);
 void DebugPrint(void *, ...);
 void *Res_GetByName(void *);
 void *Unit_GetActiveItemPtr(void *);
 s32 fn_8004ABD4(void *,s32);
 u8 fn_8004AF74(void *,u8);
 void *fn_8004B078(void *,s32);
 void *fn_8004B158(void *);
 s32 fn_8004B1A0(s32);
 u16 FileCache_Probe(void *);
 void fn_8005C870(void *,u16);
 u8 Status_Test(void *,s32);
 void sprintf(void *,void *,...);
 extern u8 lbl_8026AB18[];
 extern void *lbl_80366DC8;

 char buf[0x20];
 void *base;
 s32 idx;
 void *name;
 void *resolved;
 
 base=M2C_FIELD(arg0,void * *,0x18C);
 if(M2C_FIELD(arg0,u8 *,3)&4) base=M2C_FIELD(base,void * *,0xC)?Res_GetByName(M2C_FIELD(base,void * *,0xC)):0;
 idx=0;
 if(Status_Test((u8 *)arg0+0x1BC,8)) {
 if(Status_Test((u8 *)base+0x1C,9)) idx=1;
 } else if(Status_Test((u8 *)base+0x1C,2)) idx=1;
 name=M2C_FIELD(arg0,void * *,0x188);
 name=(u8 *)name+idx*4;
 name=M2C_FIELD(name,void * *,0x5C);
 if(!name) name=M2C_FIELD(base,void * *,0x18);
 if(!name) {fn_800056A0(0);name=lbl_8026AB18+0x52;}
 
 if(!name||!*(s8 *)name) return Res_GetByName(lbl_8026AB18+0x53);
 sprintf(buf,lbl_8026AB18+0x5F,name,fn_8004B1A0(value));
 resolved=Res_GetByName(buf);
 if(!resolved) {fn_800056A0(0);return Res_GetByName(lbl_8026AB18+0x53);}
 sprintf(buf,lbl_8026AB18+0x64,fn_8004B158(resolved));
 if(FileCache_Probe(buf)==0x8000U) {
 DebugPrint(lbl_8026AB18+0x67,buf);
 return Res_GetByName(lbl_8026AB18+0x53);
 }
 return resolved;

}


void fn_8004FE98(s32 arg0, s8 arg1);

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 pad0[0x168];
    s8 unk16C;
    u8 pad1[0xF];
    void *unk17C;
    u8 pad2[8];
    void *unk188;
    void *unk18C;
} Unit;

typedef struct {
    u8 pad0[0xC];
    u32 unkC;
    u8 pad1[8];
    void *unk18;
} Unk18CObj;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
    s32 unk30;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    f32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk41;
    s32 unk42;
    s32 unk43;
} UnitStruct;


extern s8 *lbl_80366DC0;

typedef struct {
    u8 pad[0x18];
    s8 c0;
    s8 c1;
    s8 c2;
    s8 c3;
    s8 c4;
    s8 c5;
    s8 c6;
} NameCmpObj;

typedef struct {
    s8 c0;
    s8 c1;
    s8 c2;
    s8 c3;
    s8 c4;
    s8 c5;
    s8 c6;
} NameCmpRef;

extern void* lbl_803672A8;
extern f64 lbl_80368EF8;
extern f64 lbl_80368F08;
extern f32 lbl_80368FC0;
extern f32 lbl_80368FC4;
extern f32 lbl_8036901C;
extern f64 lbl_80368FE0;
extern f64 lbl_80368E80;
extern f32 gUnitInfoDrawScale;
extern f32 gUnitInfoDrawDepth;

#pragma cplusplus on
extern "C" void Prim2D_SetColorByte(u8);
extern "C" void Prim2D_SetTransform(f32, f32, f32, f32);
extern "C" void Prim2D_PrepareTex(void);
extern "C" void Prim2D_Begin(void);
extern "C" s32 UnitRef_GetUnit(u32);
extern "C" void UnitInfo_DrawStatus(s32);

#pragma cplusplus reset

/* Set brave-weapon flag (bit 3) on count*2 hit-table entries from the current cursor. */

#pragma global_optimizer off
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma global_optimizer reset

#pragma opt_strength_reduction reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
/* Promote the foe copy, then queue battle anims for each stat gain vs the base unit. */

#pragma use_lmw_stmw reset

/* Roll level-up growths from rates, clamp to class caps, and queue non-zero gains. */

/* Add rounded growth deltas into the unit's eight growth-progress bytes (clamp 0..255). */

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma opt_strength_reduction off
#pragma global_optimizer off

#pragma opt_strength_reduction reset
#pragma global_optimizer reset

#pragma opt_strength_reduction off

#pragma global_optimizer off
#pragma scheduling off

#pragma scheduling reset

#pragma global_optimizer on

#pragma peephole off

#pragma peephole on

/* Return the first deployed unit with the same faction and disposId as unit, and state flags 0x100 set / 8 clear. */

extern f32 lbl_80368EA8;
extern f32 lbl_80368EAC;
extern f32 lbl_80368EB0;
extern f32 lbl_80368EB4;
extern f64 lbl_80368EB8;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
} UnkRet800378CC;

M2C_UNK fn_80165E90(s32 *, s32);

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma scheduling off

#pragma scheduling reset

#pragma optimization_level 2

#pragma optimization_level reset

#pragma cplusplus off

#pragma dont_inline off
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma dont_inline reset
extern u8 lbl_8026A3A8[176];
void *fn_800A88E0(u32);

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma opt_strength_reduction reset

#pragma global_optimizer off

#pragma global_optimizer on

void *Unit_GetActiveItemPtr(void *);
void *fn_80037C20(void *);

#pragma opt_peephole off

#pragma opt_peephole off

#pragma opt_peephole reset

#pragma opt_peephole off

#pragma opt_peephole reset

#pragma opt_peephole reset

#pragma opt_peephole reset

#pragma optimization_level 3

#pragma optimization_level reset

void fn_8003B69C(s32 arg0) {
    M2C_UNK fn_800173B4(s32, s32);
    fn_800173B4(arg0 + 0x236, arg0);
}

void fn_8003B6C4(void* arg0, s32 arg1) {
    *(s32*)((char*)arg0 + 0x190) = arg1;
    fn_800173B4((char*)arg0 + 0x236, arg0);
}

void Unit_Clear(u8 *unit, s32 slotId) {
    /* Zero unit battle/runtime fields and inventory; set slot id when slotId >= 0. */
    void fn_80104410(void *);
    void Item_Clear(void *);
    u8 *slot;
    s32 i;

    *(u32 *)(unit + 0x180) = 0;
    *(u32 *)(unit + 0x184) = 0;
    *(u32 *)(unit + 0x188) = 0;
    *(u32 *)(unit + 0x18C) = 0;
    *(u32 *)(unit + 0x190) = 0;
    *(u32 *)(unit + 0x194) = 0;
    unit[0x19A] = 0;
    unit[0x19B] = 0;
    unit[0x19C] = 0;
    unit[0x19D] = 0;
    unit[0x19E] = 0;
    unit[0x19F] = 0;
    *(u32 *)(unit + 0x1A0) = 0;

    fn_80104410(unit + 0x1A4);

    slot = unit;
    unit[0x1A8] = 0;
    i = 0;

    unit[0x1B2] = 0;
    unit[0x1B1] = 0;
    unit[0x1B0] = 0;
    unit[0x1AF] = 0;
    unit[0x1AE] = 0;
    unit[0x1AD] = 0;
    unit[0x1AC] = 0;
    unit[0x1AB] = 0;
    unit[0x1BB] = 0;
    unit[0x1BA] = 0;
    unit[0x1B9] = 0;
    unit[0x1B8] = 0;
    unit[0x1B7] = 0;
    unit[0x1B6] = 0;
    unit[0x1B5] = 0;
    unit[0x1B4] = 0;
    *(u32 *)(unit + 0x1C8) = 0;
    *(u32 *)(unit + 0x1C4) = 0;
    *(u32 *)(unit + 0x1C0) = 0;
    *(u32 *)(unit + 0x1BC) = 0;

    do {
        Item_Clear(slot + 0x1CC);
        Item_Clear(slot + 0x1EC);
        i += 1;
        slot += 8;
    } while (i < 4);

    unit[0x20C] = 0;
    unit[0x20D] = 0;
    unit[0x20E] = 0;
    unit[0x20F] = 0;
    unit[0x210] = 0;
    unit[0x211] = 0;
    unit[0x212] = 0;
    unit[0x213] = 0;
    *(u16 *)(unit + 0x228) = 0;
    *(u16 *)(unit + 0x22A) = 0;
    *(u16 *)(unit + 0x22C) = 0;
    *(u16 *)(unit + 0x22E) = 0;
    *(u16 *)(unit + 0x230) = 0;
    *(u16 *)(unit + 0x232) = 0;
    unit[0x234] = 0;
    unit[0x235] = 0;

    if (slotId >= 0) {
        unit[0x198] = slotId;
    }
}

#pragma use_lmw_stmw on
void fn_8003B844(void *arg0, s32 arg1)
{
    void *Person_GetByPid(void *);
    s32 j;
    u8 *walk;
    void *outer;
    s32 i;
    void *pid;

    for (outer = arg0, i = 0; i < arg1; i++) {
        for (j = 0, walk = (u8 *)outer; j < *(s32 *)((u8 *)outer + 4); walk += 8, j++) {
            pid = *(void **)(walk + 8);
            if (pid != NULL) {
                *(void **)(walk + 8) = Person_GetByPid(pid);
            }
        }
        *(void **)((u8 *)Person_GetByPid(*(void **)outer) + 0x50) = outer;
        outer = (u8 *)outer + (*(s32 *)((u8 *)outer + 4) << 3) + 8;
    }
}
#pragma use_lmw_stmw reset
void AffinityBonuses_Halve(void *arg0) {
    M2C_FIELD(arg0, u8 *, 4) = (u8) ((s8) M2C_FIELD(arg0, u8 *, 4) >> 1);
    M2C_FIELD(arg0, u8 *, 5) = (u8) ((s8) M2C_FIELD(arg0, u8 *, 5) >> 1);
    M2C_FIELD(arg0, u8 *, 6) = (u8) ((s8) M2C_FIELD(arg0, u8 *, 6) >> 1);
    M2C_FIELD(arg0, u8 *, 7) = (u8) ((s8) M2C_FIELD(arg0, u8 *, 7) >> 1);
    M2C_FIELD(arg0, u8 *, 8) = (u8) ((s8) M2C_FIELD(arg0, u8 *, 8) >> 1);
    M2C_FIELD(arg0, u8 *, 9) = (u8) ((s8) M2C_FIELD(arg0, u8 *, 9) >> 1);
}

s32 fn_8003B938(u8 arg0) {
    switch (arg0) {
    case 0:
        return 0;
    case 1:
        return 0x7;
    case 2:
        return 0x9;
    case 3:
        return 0x8;
    case 4:
        return 0x4;
    case 5:
        return 0x6;
    case 6:
        return 0x5;
    case 7:
        return 0x2;
    case 8:
        return 0x3;
    default:
        return 0;
    }
}

extern s32 gGameState;
void *fn_8003B9AC(u32 arg0) {
    void *Msg_Expand(void *);
    extern u16 gAffinityStr[];
    u8 *s;

    switch ((u8)arg0) {
    case 0:
        s = (u8 *)gAffinityStr + 0x8;
        break;
    case 1:
        s = (u8 *)gAffinityStr + 0xF;
        break;
    case 2:
        s = (u8 *)gAffinityStr + 0x16;
        break;
    case 3:
        s = (u8 *)gAffinityStr + 0x1D;
        break;
    case 4:
        s = (u8 *)gAffinityStr + 0x25;
        break;
    case 5:
        s = (u8 *)gAffinityStr + 0x2B;
        break;
    case 6:
        s = (u8 *)gAffinityStr + 0x33;
        break;
    case 7:
        s = (u8 *)gAffinityStr + 0x3A;
        break;
    case 8:
    default:
        s = (u8 *)gAffinityStr + 0x43;
        return s;
    }
    return Msg_Expand(s);
}

extern u16 gAffinityStr[];
s32 Affinity_FromName(void *name) {
    /* Map affinity name (fire..telius) to id 1-8; 0 if unknown or NULL. */
    s32 Str_Cmp(void *, void *);
    extern u16 gAffinityStr[];
    s32 cmp;

    if (name == NULL) {
        return 0;
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x44) == 0) {
        return 1; /* fire */
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x49) == 0) {
        return 2; /* thunder */
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x51) == 0) {
        return 3; /* wind */
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x56) == 0) {
        return 4; /* water */
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x5C) == 0) {
        return 5; /* dark */
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x61) == 0) {
        return 6; /* light */
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x67) == 0) {
        return 7; /* heaven */
    }
    cmp = Str_Cmp(name, (u8 *)gAffinityStr + 0x6E);
    if (cmp != 0) {
        return 0;
    }
    return 8; /* telius */
}

void fn_8003BBD4(void *arg0, s32 arg1)
{
    u8 Status_Test(void *, s32);
    u8 fn_80091D74(void *);
    void *Res_GetByName(void *);
    void fn_80091CD8(void *);

    struct UnitTransform {
        u8 pad[0x18C];
        void *res;
        u8 pad190[12];
        u8 gauge;
        u8 pad19D[3];
        u32 flags;
        u8 pad1A4[24];
        u32 status[4];
    };

    struct UnitTransform *unit;
    void *res;

    unit = (struct UnitTransform *)arg0;

    if (Status_Test(unit->status, 8) == 0) {
        return;
    }

    if (Status_Test(unit->status, 10) != 0) {
        return;
    }

    if (fn_80091D74(unit) != 0) {
        return;
    }

    if ((u8)arg1 != 0) {
        if (Status_Test(unit->status, 9) != 0) {
            return;
        }
    } else {
        if (Status_Test(unit->status, 9) == 0) {
            return;
        }
    }

    res = unit->res;

    unit->status[0] &= ~*(u32 *)((u8 *)res + 0x1C);
    unit->status[1] &= ~*(u32 *)((u8 *)res + 0x20);
    unit->status[2] &= ~*(u32 *)((u8 *)res + 0x24);
    unit->status[3] &= ~*(u32 *)((u8 *)res + 0x28);

    res = *(void **)((u8 *)unit->res + 0xC);
    unit->res = res ? Res_GetByName(res) : 0;
    res = unit->res;

    unit->status[0] |= *(u32 *)((u8 *)res + 0x1C);
    unit->status[1] |= *(u32 *)((u8 *)res + 0x20);
    unit->status[2] |= *(u32 *)((u8 *)res + 0x24);
    unit->status[3] |= *(u32 *)((u8 *)res + 0x28);

    unit->flags &= ~(1U << 13);

    if (Status_Test(unit->status, 9) != 0) {
        unit->gauge = 0x14;
    } else {
        unit->gauge = 0;
    }

    fn_80091CD8(unit);
}

/* If the unit has status flag 8, clear held items and equip the class default weapon. */
void Unit_ResetHeldFromClass(void *unit) {
    u8 Status_Test(void *, s32);
    void *Unit_GetHeldItemSlot(void *, s32);
    void Item_Clear(void *);
    void *Res_GetByName(void *);
    void fn_80094A54(void *, void *);
    struct Bit7 {
        u8 flag : 1;
        u8 rest : 7;
    };

    s32 i;
    u32 iid;
    void *cls;
    void *parent;
    void *slot;

    if ((u8)Status_Test((u8 *)unit + 0x1BC, 8) != 0) {
        for (i = 0; i < 4; i++) {
            Item_Clear(Unit_GetHeldItemSlot(unit, i));
        }

        cls = *(void **)((u8 *)unit + 0x18C);
        iid = 0;
        if (*(u32 *)((u8 *)cls + 0x14) != 0) {
            iid = *(u32 *)((u8 *)cls + 0x14);
        }
        if (iid == 0) {
            parent = *(void **)((u8 *)cls + 0xC);
            if (parent != 0) {
                parent = Res_GetByName(parent);
            } else {
                parent = 0;
            }
            if (*(u32 *)((u8 *)parent + 0x14) != 0) {
                parent = *(void **)((u8 *)*(void **)((u8 *)unit + 0x18C) + 0xC);
                if (parent != 0) {
                    parent = Res_GetByName(parent);
                } else {
                    parent = 0;
                }
                iid = *(u32 *)((u8 *)parent + 0x14);
            }
        }
        if (iid != 0) {
            fn_80094A54(unit, (void *)iid);
            slot = Unit_GetHeldItemSlot(unit, 0);
            ((struct Bit7 *)((u8 *)slot + 5))->flag = 1;
        }
    }
}

void Unit_ApplyTransform(void *arg0) {
 void *Res_GetByName(void *);
 u8 Status_Test(void *, s32);
 void fn_80091CD8(void *);
 struct UnitTransform { u8 pad[0x18C]; void *res; u8 pad190[12]; u8 gauge; u8 pad19D[3]; u32 flags; u8 pad1A4[24]; u32 status[4]; };
 struct UnitTransform *unit=arg0;
 void *res=unit->res;
 unit->status[0]&=~M2C_FIELD(res,u32 *,0x1C);
 unit->status[1]&=~M2C_FIELD(res,u32 *,0x20);
 unit->status[2]&=~M2C_FIELD(res,u32 *,0x24);
 unit->status[3]&=~M2C_FIELD(res,u32 *,0x28);
 res=M2C_FIELD(unit->res,void **,0xC);
 unit->res=res?Res_GetByName(res):0;
 res=unit->res;
 unit->status[0]|=M2C_FIELD(res,u32 *,0x1C);
 unit->status[1]|=M2C_FIELD(res,u32 *,0x20);
 unit->status[2]|=M2C_FIELD(res,u32 *,0x24);
 unit->status[3]|=M2C_FIELD(res,u32 *,0x28);
 unit->flags&=~(1U<<13);
 if(Status_Test(unit->status,9)) unit->gauge=20;
 else unit->gauge=0;
 fn_80091CD8(unit);
}

#pragma global_optimizer off
/* Tick laguz transform gauge by +4 (or -3 if transformed); return 1 if it hit 0 or 0x14. */
s32 Unit_TickTransformGaugeFast(void *unit) {
    u8 Status_Test(void *, s32);
    u8 fn_80091D74(void *);
    s32 adj;
    u8 gauge;
    u8 transformed;

    if (Status_Test((u8 *)unit + 0x1BC, 8) == 0) {
        return 0;
    }
    if (Status_Test((u8 *)unit + 0x1BC, 0xA) != 0) {
        return 0;
    }
    if (fn_80091D74(unit) != 0) {
        return 0;
    }
    transformed = Status_Test((u8 *)unit + 0x1BC, 9);
    adj = 4;
    if (transformed != 0) {
        adj = -3;
    }
    *((u8 *)unit + 0x19C) = (u8)(*((u8 *)unit + 0x19C) + adj);
    gauge = *((u8 *)unit + 0x19C);
    if ((s8)gauge <= 0) {
        *((u8 *)unit + 0x19C) = 0;
        return 1;
    }
    if ((s8)gauge >= 0x14) {
        *((u8 *)unit + 0x19C) = 0x14;
        return 1;
    }
    return 0;
}
/* Tick laguz transform gauge by +2 (or -1 if transformed); return 1 if it hit 0 or 0x14. */
s32 Unit_TickTransformGaugeSlow(void *unit) {
    u8 Status_Test(void *, s32);
    u8 fn_80091D74(void *);
    s32 delta;
    u8 gauge;
    u8 transformed;

    if (Status_Test((u8 *)unit + 0x1BC, 8) == 0) {
        return 0;
    }
    if (Status_Test((u8 *)unit + 0x1BC, 0xA) != 0) {
        return 0;
    }
    if (fn_80091D74(unit) != 0) {
        return 0;
    }
    transformed = Status_Test((u8 *)unit + 0x1BC, 9);
    delta = 2;
    if (transformed != 0) {
        delta = -1;
    }
    *((u8 *)unit + 0x19C) = (u8)(*((u8 *)unit + 0x19C) + delta);
    gauge = *((u8 *)unit + 0x19C);
    if ((s8)gauge <= 0) {
        *((u8 *)unit + 0x19C) = 0;
        return 1;
    }
    if ((s8)gauge >= 0x14) {
        *((u8 *)unit + 0x19C) = 0x14;
        return 1;
    }
    return 0;
}
#pragma global_optimizer reset

u8 fn_8003C114(u8 *arg0) {
    u8 Status_Test(u8 *, s32);

    if ((u8)Status_Test(arg0 + 0x1BC, 0xA) != 0) {
        return 0x14;
    }
    return arg0[0x19C];
}

void fn_8003C15C(void *arg0) {
    u8 Status_Test(s32, M2C_UNK);
    M2C_UNK fn_80091CD8(void *);

    if (Status_Test((s32)((char *)arg0 + 0x1BC), 9) != 0) {
        *(u8 *)((char *)arg0 + 0x19C) = 0x14;
    } else {
        *(u8 *)((char *)arg0 + 0x19C) = 0;
    }
    fn_80091CD8(arg0);
}

void fn_8003C1B4(s32 arg0) {
    u8 Status_Test(s32, s32);

    if (Status_Test(arg0 + 0x1BC, 8) != 0) {
        if (Status_Test(arg0 + 0x1BC, 9) != 0) {
            *(u8 *)(arg0 + 0x19C) = 0x14;
        } else {
            *(u8 *)(arg0 + 0x19C) = *(u8 *)(*(s32 *)(arg0 + 0x188) + 0x56);
        }
    }
}

void fn_8003C21C(void *arg0, void *arg1)
{
    extern u8 lbl_8026A4D0[];

    void *Hash_Lookup(void *);
    void *Res_GetByName(void *);
    u8 Stream_ReadU8(void *);
    u16 Stream_ReadU16(void *);
    u32 fn_8017A950(void *);

    u8 *unit;
    void *stream;
    void **table;
    u8 *resource;
    u32 index;

    unit = (u8 *)arg0;
    stream = arg1;

    *(u32 *)(unit + 0x238) = 0;
    *(u32 *)(unit + 0x23C) = 0;
    *(u32 *)(unit + 0x240) = 0;
    *(u32 *)(unit + 0x244) = 0;
    unit[0x248] = 0;
    *(u32 *)(unit + 0x24C) = 0;
    unit[0x250] = 0;
    unit[0x251] = 0;
    *(u32 *)(unit + 0x254) = 0;
    *(u16 *)(unit + 0x258) = 0;
    *(u16 *)(unit + 0x25A) = 0;
    *(u32 *)(unit + 0x25C) = 0;
    unit[0x260] = 0x10;

    table = (void **)Hash_Lookup(lbl_8026A4D0 + 8);
    index = Stream_ReadU8(stream);
    resource = (u8 *)Res_GetByName(table[(u8)index]);

    if (resource != 0) {
        *(u32 *)(unit + 0x238) = *(u32 *)(resource + 0x14);
        unit[0x250] = 0;
    }

    table = (void **)Hash_Lookup(lbl_8026A4D0 + 0x17);
    index = Stream_ReadU8(stream);
    resource = (u8 *)Res_GetByName(table[(u8)index]);

    if (resource != 0) {
        *(u32 *)(unit + 0x23C) = *(u32 *)(resource + 0x14);
        unit[0x251] = 0;
    }

    table = (void **)Hash_Lookup(lbl_8026A4D0 + 0x26);
    index = Stream_ReadU8(stream);
    resource = (u8 *)Res_GetByName(table[(u8)index]);

    if (resource != 0) {
        *(u32 *)(unit + 0x240) = *(u32 *)resource;
    }

    table = (void **)Hash_Lookup(lbl_8026A4D0 + 0x36);
    index = Stream_ReadU8(stream);
    resource = (u8 *)Res_GetByName(table[(u8)index]);

    if (resource != 0) {
        *(u32 *)(unit + 0x244) = *(u32 *)resource;
    }

    unit[0x250] = Stream_ReadU8(stream);
    unit[0x251] = Stream_ReadU8(stream);
    *(u32 *)(unit + 0x254) = fn_8017A950(stream);
    *(u16 *)(unit + 0x258) = Stream_ReadU16(stream);
    *(u16 *)(unit + 0x25A) = Stream_ReadU16(stream);
    unit[0x248] = Stream_ReadU8(stream);
}

/* Write unit aux fields (hash refs at +0x238.., counters, ids) to stream. */
void Unit_WriteExtra(void *unit, s32 stream) {
    void *Hash_Lookup(void *);
    void Stream_WriteU8(s32, u8);
    void Stream_WriteS32(s32, s32);
    void Stream_WriteU16(s32, u16);
    void *entry;

    entry = Hash_Lookup(*(void **)((u8 *)unit + 0x238));
    Stream_WriteU8(stream, (u8)*(u32 *)((u8 *)entry + 0x20));
    entry = Hash_Lookup(*(void **)((u8 *)unit + 0x23C));
    Stream_WriteU8(stream, (u8)*(u32 *)((u8 *)entry + 0x20));
    entry = Hash_Lookup(*(void **)((u8 *)unit + 0x240));
    Stream_WriteU8(stream, *((u8 *)entry + 4));
    entry = Hash_Lookup(*(void **)((u8 *)unit + 0x244));
    Stream_WriteU8(stream, *((u8 *)entry + 4));
    Stream_WriteU8(stream, *((u8 *)unit + 0x250));
    Stream_WriteU8(stream, *((u8 *)unit + 0x251));
    Stream_WriteS32(stream, *(s32 *)((u8 *)unit + 0x254));
    Stream_WriteU16(stream, *(u16 *)((u8 *)unit + 0x258));
    Stream_WriteU16(stream, *(u16 *)((u8 *)unit + 0x25A));
    Stream_WriteU8(stream, *((u8 *)unit + 0x248));
}

void fn_8003C4B0(void *arg0, void *arg1)
{
  void *Res_GetByName(void *);
  void *resource;
  void *name1;
  void **new_var;
  void *name2;
  u8 *self;
  u8 *source;
  self = (u8 *) arg0;
  source = (u8 *) arg1;
  name2 = *((void **) (source + 0x40));
  name1 = *((void **) (source + 0x3C));
  resource = Res_GetByName(*((void **) (source + 0x38)));
  if (resource != NULL)
  {
    *((void **) (self + 0x238)) = *((void **) (((u8 *) resource) + 0x14));
    self[0x250] = 0;
  }
  resource = Res_GetByName(name1);
  if (resource != NULL)
  {
    new_var = (void **) (self + 0x23C);
    *new_var = *((void **) (((u8 *) resource) + 0x14));
    self[0x251] = 0;
  }
  resource = Res_GetByName(name2);
  if (resource != NULL)
  {
    *((void **) (self + 0x240)) = *((void **) resource);
  }
  resource = Res_GetByName(*((void **) (source + 0x44)));
  if (resource != NULL)
  {
    *((void **) (self + 0x244)) = *((void **) resource);
  }
}

void fn_8003C56C(void *arg0, s32 arg1) {
    s32 *Res_GetByName(s32);
    s32 *temp_r3;

    temp_r3 = Res_GetByName(arg1);
    if (temp_r3 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x244) = (s32) *temp_r3;
    }
}

void fn_8003C5AC(void *arg0, s32 arg1) {
    s32 *Res_GetByName(s32);
    s32 *temp_r3;

    temp_r3 = Res_GetByName(arg1);
    if (temp_r3 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x240) = (s32)*temp_r3;
    }
}

void *Res_GetByName(s32);
void fn_8003C5EC(void *arg0, s32 arg1) {
    void *temp_r3;

    temp_r3 = Res_GetByName(arg1);
    if (temp_r3 != NULL) {
        *(s32*)((char*)arg0 + 0x23C) = *(s32*)((char*)temp_r3 + 0x14);
        *(u8*)((char*)arg0 + 0x251) = 0;
    }
}

void fn_8003C634(void *arg0, s32 arg1) {
    void *temp_r3;

    temp_r3 = Res_GetByName(arg1);
    if (temp_r3 != NULL) {
        *(s32*)((char*)arg0 + 0x238) = *(s32*)((char*)temp_r3 + 0x14);
        *(u8*)((char*)arg0 + 0x250) = 0;
    }
}

void fn_8003C67C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x238) = 0;
    M2C_FIELD(arg0, s32 *, 0x23C) = 0;
    M2C_FIELD(arg0, s32 *, 0x240) = 0;
    M2C_FIELD(arg0, s32 *, 0x244) = 0;
    M2C_FIELD(arg0, s8 *, 0x248) = 0;
    M2C_FIELD(arg0, s32 *, 0x24C) = 0;
    M2C_FIELD(arg0, s8 *, 0x250) = 0;
    M2C_FIELD(arg0, s8 *, 0x251) = 0;
    M2C_FIELD(arg0, s32 *, 0x254) = 0;
    M2C_FIELD(arg0, s16 *, 0x258) = 0;
    M2C_FIELD(arg0, s16 *, 0x25A) = 0;
    M2C_FIELD(arg0, s32 *, 0x25C) = 0;
    M2C_FIELD(arg0, s8 *, 0x260) = 0x10;
}

void fn_8003C6BC(void *arg0, void *arg1, void *arg2) {
    void *Job_GetByJid(void *);
    void *Res_GetByName(void *);
    u8 Status_Test(void *, s32);
    void *fn_800951D0(void *, s32);
    void fn_8004E9D8(void *, s32);
    void fn_80050C90(void *);

    u8 *job;
    u8 *unit;
    void *resource;
    void *person;

    unit = (u8 *)arg0;
    person = arg1;
    job = (u8 *)arg2;

    if (person != NULL) {
        *(void **)(unit + 0x188) = person;

        job = (u8 *)Job_GetByJid(*(void **)((u8 *)person + 0x10));

        if (*(void **)(job + 0xC) != NULL) {
            resource = Res_GetByName(*(void **)(job + 0xC));
        } else {
            resource = NULL;
        }

        if (resource == NULL) {
            goto finish;
        }

        if (Status_Test(*(u8 **)(unit + 0x18C) + 0x1C, 2) != 0) {
            if (Status_Test(job + 0x1C, 2) != 0) goto finish;
            if (*(void **)(job + 0xC) != NULL) {
                resource = Res_GetByName(*(void **)(job + 0xC));
            } else {
                resource = NULL;
            }
            job = (u8 *)resource;
            goto finish;
        }

        if (Status_Test(job + 0x1C, 2) != 0) {
            if (*(void **)(job + 0xC) != NULL) {
                resource = Res_GetByName(*(void **)(job + 0xC));
            } else {
                resource = NULL;
            }
            job = (u8 *)resource;
        }
    }

finish:
    if (job != NULL) {
        *(void **)(unit + 0x18C) = job;
    }
    fn_800951D0(unit, -1);
    fn_8004E9D8(unit, 0);
    fn_80050C90(unit);
}

s32 Unit_HasHitBlockStatus(s32 arg0) {
    u8 Status_Test(s32, M2C_UNK);
    if (Status_Test(arg0 + 0x1BC, 6) != 0) {
        return 1;
    }
    return Status_Test(arg0 + 0x1BC, 7) != 0;
}

#pragma global_optimizer off
/* Read a unit record from stream into unit; return 0 if person id is 0 (empty). */
s32 Unit_Read(void *unit, void *stream) {
    u16 Stream_ReadU16(void *);
    u8 Stream_ReadU8(void *);
    s32 Person_Get(u16);
    s32 Job_Get(u16);
    void fn_8003B6C4(void *, s32);
    void Stream_Read(void *, s32, void *);
    void fn_80104134(void *, void *);
    void fn_80105A04(void *, void *);
    s32 Unit_GetItemSlot(s32, s32);
    void Item_Read(void *, void *);
    void fn_8001D018(void *, void *);
    void fn_80017414(void *, void *);
    void fn_8003C21C(void *, void *);
    void fn_8004BC48(void *, void *);
    void fn_8003B69C(s32);
    extern u8 gUnitLists[];
    extern u8 gUnits[];
    void *src;
    void *dst;
    u32 pid;
    s32 person;
    s32 job;
    u8 id;
    void *p;

    src = stream;
    dst = unit;
    pid = Stream_ReadU16(src);
    if ((u16)pid == 0) {
        return 0;
    }
    person = Person_Get((u16)pid);
    job = Job_Get((u16)Stream_ReadU16(src));
    *(s32 *)((u8 *)dst + 0x188) = person;
    *(s32 *)((u8 *)dst + 0x18C) = job;
    id = Stream_ReadU8(src);
    fn_8003B6C4(dst, (s32)(gUnitLists + id * 0xC));
    id = Stream_ReadU8(src);
    if (id != 0) {
        p = gUnits + (id - 1) * 0x280;
    } else {
        p = NULL;
    }
    *(void **)((u8 *)dst + 0x180) = p;
    id = Stream_ReadU8(src);
    if (id != 0) {
        p = gUnits + (id - 1) * 0x280;
    } else {
        p = NULL;
    }
    *(void **)((u8 *)dst + 0x184) = p;
    id = Stream_ReadU8(src);
    if (id != 0) {
        p = gUnits + (id - 1) * 0x280;
    } else {
        p = NULL;
    }
    *(void **)((u8 *)dst + 0x194) = p;
    *((u8 *)dst + 0x199) = Stream_ReadU8(src);
    *((u8 *)dst + 0x19A) = Stream_ReadU8(src);
    *((u8 *)dst + 0x19B) = Stream_ReadU8(src);
    *((u8 *)dst + 0x19C) = Stream_ReadU8(src);
    *((u8 *)dst + 0x19D) = Stream_ReadU8(src);
    *((u8 *)dst + 0x19E) = Stream_ReadU8(src);
    *((u8 *)dst + 0x19F) = Stream_ReadU8(src);
    Stream_Read(src, 4, (u8 *)dst + 0x1A0);
    fn_80104134((u8 *)dst + 0x1A4, src);
    *((u8 *)dst + 0x1A8) = Stream_ReadU8(src);
    *((u8 *)dst + 0x1A9) = Stream_ReadU8(src);
    *((u8 *)dst + 0x1AA) = Stream_ReadU8(src);
    Stream_Read(src, 8, (u8 *)dst + 0x1AB);
    Stream_Read(src, 8, (u8 *)dst + 0x1B4);
    fn_80105A04((u8 *)dst + 0x1BC, src);
    for (person = 0; person < 8; person++) {
        Item_Read((void *)Unit_GetItemSlot((s32)dst, person), src);
    }
    fn_8001D018((u8 *)dst + 0x20C, src);
    fn_80017414((u8 *)dst + 0x228, src);
    Stream_Read(src, 0xA, (u8 *)dst + 0x214);
    fn_8003C21C(dst, src);
    fn_8004BC48(dst, src);
    *(s32 *)((u8 *)src + 4) = *(s32 *)((u8 *)src + 4) + 2;
    fn_8003B69C((s32)dst);
    return 1;
}
#pragma use_lmw_stmw on
void Unit_Write(void *arg0, s32 arg1) {
    void Stream_WriteU16(s32, u16);
    void Stream_WriteU8(s32, u8);
    void Stream_Write(s32, s32, void *);
    void fn_80104160(void *, s32);
    void fn_80105A30(void *, s32);
    s32 Unit_GetItemSlot(s32, s32);
    void fn_8001C21C(void *, s32);
    void fn_8001D044(void *, s32);
    void fn_800174A8(void *, s32);
    void Unit_WriteExtra(void *, s32);
    void fn_8004BCCC(void *, s32);
    s32 out;
    void *self;
    u32 tmp;
    void *p;
    u8 b;

    out = arg1;
    self = arg0;
    p = *(void **)((u8 *)self + 0x188);
    if (!p) {
        Stream_WriteU16(out, 0);
        return;
    }
    Stream_WriteU16(out, *(u16 *)((u8 *)p + 0x18));
    Stream_WriteU16(out, *(u16 *)((u8 *)*(void **)((u8 *)self + 0x18C) + 0x38));
    Stream_WriteU8(out, *((u8 *)*(void **)((u8 *)self + 0x190) + 8));
    p = *(void **)((u8 *)self + 0x180);
    if (p) {
        tmp = *((u8 *)p + 0x198);
    } else {
        tmp = 0;
    }
    Stream_WriteU8(out, (u8)tmp);
    p = *(void **)((u8 *)self + 0x184);
    if (p) {
        tmp = *((u8 *)p + 0x198);
    } else {
        tmp = 0;
    }
    Stream_WriteU8(out, (u8)tmp);
    p = *(void **)((u8 *)self + 0x194);
    if (p) {
        b = *((u8 *)p + 0x198);
    } else {
        b = 0;
    }
    Stream_WriteU8(out, b);
    Stream_WriteU8(out, *((u8 *)self + 0x199));
    Stream_WriteU8(out, *((u8 *)self + 0x19A));
    Stream_WriteU8(out, *((u8 *)self + 0x19B));
    Stream_WriteU8(out, *((u8 *)self + 0x19C));
    Stream_WriteU8(out, *((u8 *)self + 0x19D));
    Stream_WriteU8(out, *((u8 *)self + 0x19E));
    Stream_WriteU8(out, *((u8 *)self + 0x19F));
    Stream_Write(out, 4, (u8 *)self + 0x1A0);
    fn_80104160((u8 *)self + 0x1A4, out);
    Stream_WriteU8(out, *((u8 *)self + 0x1A8));
    Stream_WriteU8(out, *((u8 *)self + 0x1A9));
    Stream_WriteU8(out, *((u8 *)self + 0x1AA));
    Stream_Write(out, 8, (u8 *)self + 0x1AB);
    Stream_Write(out, 8, (u8 *)self + 0x1B4);
    fn_80105A30((u8 *)self + 0x1BC, out);
    {
        s32 i;
        for (i = 0; i < 8; i++) {
            fn_8001C21C((void *)Unit_GetItemSlot((s32)self, i), out);
        }
    }
    fn_8001D044((u8 *)self + 0x20C, out);
    fn_800174A8((u8 *)self + 0x228, out);
    Stream_Write(out, 0xA, (u8 *)self + 0x214);
    Unit_WriteExtra(self, out);
    fn_8004BCCC(self, out);
    Stream_WriteU16(out, 0);
}
void fn_8003CCB0(void *arg0, u8 *arg1, u8 *arg2) {
    extern u8 gBattleMap[], lbl_8026A520[];
    void Map_SelectRangeBuffer(void *, s32);
    void fn_80022748(void *, s32);
    void fn_800227F8(void *, void *);
    void *Job_GetByJid(void *);
    void Map_FloodMoveRange(void *, u8, u8, s32, s32, s32);
    u8 Map_IsAiTerrainBlocked(s8, s8);
    s16 fn_8002134C(u8 *, s8, s8);
    u8 *outY, *outX;
    void *unit;
    u8 *map;
    u8 saved;
    s32 rowOff;
    u8 *row;
    u8 *mapHi;
    u8 *layer;
    u8 *tile;
    s32 byteOff;
    u16 best;
    s32 y, x;
    s32 initIdx;
    s32 endIdx;

    outY = arg2;
    outX = arg1;
    unit = arg0;
    map = gBattleMap;
    layer = map + 13;
    initIdx = (s8)M2C_FIELD(unit, u8 *, 0x19E) + ((s8)M2C_FIELD(unit, u8 *, 0x19F) << 6);
    saved = layer[initIdx];
    layer[initIdx] = 0;
    Map_SelectRangeBuffer(map, 5);
    fn_80022748(gBattleMap, 0);
    fn_800227F8(gBattleMap, Job_GetByJid(lbl_8026A520 + 0x50));
    Map_FloodMoveRange(gBattleMap, *outX, *outY, 64, 0, 0);
    fn_800227F8(gBattleMap, M2C_FIELD(unit, void **, 0x18C));
    map = gBattleMap;
    best = 9999;
    mapHi = map + 0x10000;
    for (y = ((s8 *)map)[9]; y <= ((s8 *)map)[11] - 1; y++) {
        rowOff = (s8)y << 6;
        x = ((s8 *)map)[8];
        row = map + rowOff;
        for (; x <= ((s8 *)map)[10] - 1; x++) {
            byteOff = ((s8)x + rowOff) << 1;
            if (*(s16 *)(*(u8 **)(mapHi + 0x4190) + byteOff) >= 0) {
                tile = row + (s8)x;
                if ((s8)tile[0xE18E] == 0 && !Map_IsAiTerrainBlocked((s8)x, (s8)y) && tile[13] == 0 &&
                    fn_8002134C(gBattleMap, (s8)x, (s8)y) <= 30000) {
                    if (best > (u16)*(s16 *)(*(u8 **)(mapHi + 0x4190) + byteOff)) {
                        best = *(s16 *)(*(u8 **)(mapHi + 0x4190) + byteOff);
                        *outX = x;
                        *outY = y;
                    }
                }
            }
        }
    }
    endIdx = (s8)M2C_FIELD(unit, u8 *, 0x19E) + ((s8)M2C_FIELD(unit, u8 *, 0x19F) << 6);
    layer[endIdx] = saved;
}

#pragma push
void fn_8003CE88(void *unit, s32 range) {
#pragma use_lmw_stmw on
#pragma global_optimizer on
extern u8 gBattleMap[];
void Map_SelectRangeBuffer(void *,s32);
void Map_FillLayer(void *,s32,s32);
void fn_800227F8(void *,void *);
s16 fn_8002134C(u8 *,s8,s8);
s32 negativeDy, dy;
u8 *row;
s32 sy, sx;
s32 x, y;
x = *((u8 *)unit + 0x19E);
y = *((u8 *)unit + 0x19F);
Map_SelectRangeBuffer(gBattleMap, 5);
Map_FillLayer(gBattleMap, 5, -1);
fn_800227F8(gBattleMap, *(void **)((u8 *)unit + 0x18C));
sy = (s8)y;
sx = (s8)x;
for (y = *(s8 *)(gBattleMap+9); y <= (s8)gBattleMap[11] - 1; y++) {
    dy = sy - y;
    negativeDy = -dy;
    row = gBattleMap + ((s8)y << 6);
    x = *(s8 *)(gBattleMap+8);
    for (; x <= (s8)gBattleMap[10] - 1; x++) {
        s32 dx, absoluteY;

        if (dy < 0) absoluteY = negativeDy;
        else absoluteY = dy;
        if (sx - x < 0) dx = -(sx - x);
        else dx = sx - x;
        if (dx + absoluteY <= range) {
            if (row[(s8)x + 0xD] == 0 && (s8)row[(s8)x + 0xE18E] == 0 && row[(s8)x + 0x200D] != 0 &&
                fn_8002134C(gBattleMap, (s8)x, (s8)y) <= 30000) {
                (*(s16 **)(gBattleMap + 0x14190))[(s8)x + ((s8)y << 6)] = 0;
            }
        }
    }
}
}
#pragma pop
u8 Unit_CalcHitRate(void *arg0, void *arg1) {
    s32 Unit_GetMagAtk(void *);
    s32 fn_8003A778(void *);
    s32 fn_8003AF28(void *);
    u8 Unit_GetDistance(void *, void *);
    s32 t;
    s32 u;
    s32 scaled;
    s32 v;

    t = (s8)Unit_GetMagAtk(arg0);
    scaled = (t - (s8)fn_8003A778(arg1)) * 5;
    u = (s8)fn_8003AF28(arg0);
    v = (scaled + u + 0x1E) - ((u8)Unit_GetDistance(arg0, arg1) << 1);
    if (v > 0x64) {
        v = 0x64;
    }
    if (v < 0) {
        v = 0;
    }
    return (u8)v;
}

u8 fn_8003D094(s32 arg0, u8 arg1) {
    s32 v;
    u8 Status_Test(s32, s32);

    if (arg1 == 0) {
        return 0;
    }
    v = arg1;
    if ((u8)Status_Test(arg0 + 0x1BC, 0xB) != 0) {
        v <<= 1;
    }
    if ((u8)Status_Test(arg0 + 0x1BC, 0x4B) != 0) {
        v = (v * 7) / 10;
        if (v < 1) {
            v = 1;
        }
    }
    if (v > 0x64) {
        v = 0x64;
    }
    return (u8)v;
}

u8 fn_8003D13C(u8 *unit)
{
    extern u8 gBattleState[];

    u8 fn_800386B0(void *);
    u8 Status_Test(void *, s32);
    void *Res_GetByName(void *);

    u8 *classData;
    s32 limit;
    s32 result;
    s32 level;
    u8 value;
    u8 ok;
    void *res;

    if ((gBattleState[0x9F] >> 3) & 1) {
        return 0;
    }

    classData = *(u8 **)(unit + 0x190);

    if (classData[8] != 0 && classData[8] != 5) {
        return 0;
    }

    if ((s8)unit[0x1A8] == 0) {
        return 0;
    }

    value = fn_800386B0(unit);

    if (value == 0xFF) {
        return 0;
    }

    limit = 0x76C;

    if (Status_Test(unit + 0x1BC, 2) != 0) {
        ok = 0;
    } else if (Status_Test(unit + 0x1BC, 8) != 0) {
        ok = 0;
    } else if (Status_Test(unit + 0x1BC, 0x4D) != 0) {
        ok = 0;
    } else {
        res = *(void **)(*(u8 **)(unit + 0x18C) + 0xC);
        if (res) {
            res = Res_GetByName(res);
        } else {
            res = 0;
        }

        if (!res) {
            ok = 0;
        } else {
            level = (s8)unit[0x19A];
            if (level < 10) {
                ok = 0;
            } else {
                ok = 1;
            }
        }
    }

    if (ok) {
        limit = 0x7D0;
    }

    value = fn_800386B0(unit);
    result = limit - (value + ((s8)unit[0x19A] - 1) * 100);

    if (result > 100) {
        result = 100;
    }

    if (result < 0) {
        result = 0;
    }

    return (u8)result;
}

#pragma opt_strength_reduction off
#pragma optimization_level 3
void Unit_Promote(void *arg0) {
    void *Res_GetByName(void *);
    void Unit_SetHp(void *, s8);
    void fn_8003868C(void *, s32);
    u8 Status_Test(void *, s32);
    s32 Unit_GetMaxHp(void *);
    void Status_Set(void *, s32);
    typedef struct {
        u8 pad0[0xC];
        void *unkC;
        u8 pad10[0xC];
        u32 unk1C;
        u32 unk20;
        u32 unk24;
        u32 unk28;
        u8 unk2C[8];
    } Item;
    typedef struct {
        u8 pad0[0x18C];
        Item *unk18C;
        u8 pad190[0xA];
        u8 unk19A;
        u8 pad19B[5];
        u32 unk1A0;
        u8 pad1A4[0x10];
        u8 unk1B4;
        u8 unk1B5;
        u8 unk1B6;
        u8 unk1B7;
        u8 unk1B8;
        u8 unk1B9;
        u8 unk1BA;
        u8 unk1BB;
        u32 unk1BC;
        u32 unk1C0;
        u32 unk1C4;
        u32 unk1C8;
        u8 pad1CC[0x40];
        u8 unk20C[8];
    } Unit;
    Unit *self;
    Item *item;
    void *child;
    void *flags;
    s32 code;
    s32 i;
    s32 ctr;
    u8 t;
    u32 tmp;
    u8 *dp;
    Item *ip;

    self = (Unit *)arg0;
    item = self->unk18C;
    self->unk1BC &= ~item->unk1C;
    self->unk1C0 &= ~item->unk20;
    self->unk1C4 &= ~item->unk24;
    self->unk1C8 &= ~item->unk28;
    child = self->unk18C->unkC;
    if (child != NULL) {
        child = Res_GetByName(child);
    } else {
        child = NULL;
    }
    self->unk18C = child;
    flags = &self->unk1BC;
    code = 0x44;
    item = self->unk18C;
    self->unk1BC |= item->unk1C;
    self->unk1C0 |= item->unk20;
    self->unk1C4 |= item->unk24;
    self->unk1C8 |= item->unk28;
    if (Status_Test(flags, code) == 0) {
        Status_Set(&self->unk1BC, 0x45);
    }
    i = 0;
    for (ctr = 2; ctr != 0; ctr--) {
        item = self->unk18C;
        ip = (Item *)((u8 *)item + (u8)i);
        dp = (u8 *)self + (u8)i;
        t = ip->unk2C[0];
        if (dp[0x20C] < t) {
            dp[0x20C] = t;
        }
        i = (s32)i + 1;
        item = self->unk18C;
        ip = (Item *)((u8 *)item + (u8)i);
        dp = (u8 *)self + (u8)i;
        t = ip->unk2C[0];
        if (dp[0x20C] < t) {
            dp[0x20C] = t;
        }
        i = i + 1;
        item = self->unk18C;
        ip = (Item *)((u8 *)item + (u8)i);
        dp = (u8 *)self + (u8)i;
        t = ip->unk2C[0];
        if (dp[0x20C] < t) {
            dp[0x20C] = t;
        }
        i = i + 1;
        item = self->unk18C;
        ip = (Item *)((u8 *)item + (u8)i);
        dp = (u8 *)self + (u8)i;
        t = ip->unk2C[0];
        if (dp[0x20C] < t) {
            dp[0x20C] = t;
        }
        i = i + 1;
    }
    self->unk19A = 1;
    fn_8003868C(self, 0);
    tmp = self->unk1B4;
    self->unk1B4 = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    tmp = self->unk1B5;
    self->unk1B5 = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    tmp = self->unk1B6;
    self->unk1B6 = (u8)((s32)(((u32)tmp >> 31) + (int)tmp) >> 1);
    tmp = self->unk1B7;
    self->unk1B7 = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    tmp = self->unk1B8;
    self->unk1B8 = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    tmp = self->unk1B9;
    self->unk1B9 = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    tmp = self->unk1BA;
    self->unk1BA = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    tmp = self->unk1BB;
    self->unk1BB = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    self->unk1A0 &= 0xFFFBFFFF;
    Unit_SetHp(self, (s8)Unit_GetMaxHp(self));
}
#pragma optimization_level reset
#pragma opt_strength_reduction reset
s32 Unit_CanPromote(s32 unit) {
    /* True if unit can promote: no blocking statuses, promo class exists, level >= 10. */
    u8 Status_Test(s32, s32);
    void *Res_GetByName(void *);
    void *promoName;
    void *promoClass;

    if (Status_Test(unit + 0x1BC, 2) != 0) {
        return 0;
    }
    if (Status_Test(unit + 0x1BC, 8) != 0) {
        return 0;
    }
    if (Status_Test(unit + 0x1BC, 0x4D) != 0) {
        return 0;
    }
    promoName = *(void **)((u8 *)*(void **)(unit + 0x18C) + 0xC);
    if (promoName != NULL) {
        promoClass = Res_GetByName(promoName);
    } else {
        promoClass = NULL;
    }
    if (promoClass == NULL) {
        return 0;
    }
    return (s8)*(u8 *)(unit + 0x19A) >= 0xA;
}

#pragma opt_strength_reduction reset
void Unit_SetDisposId(void *arg0, u8 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, u8 *, 0x199) = arg1;
    }
}

void Unit_MoveToList(void *unit, s32 listId) {
    void fn_800156A0(void *, void *);
    void fn_80015718(void *, void *);
    void fn_800946F0(void *);
    extern u8 gUnitLists[];

    switch (listId) {
    case 0:
    case 2:
    case 3:
        fn_800946F0(unit);
    }
    fn_800156A0(*(void **)((u8 *)unit + 0x190), unit);
    fn_80015718(gUnitLists + listId * 0xC, unit);
}

void Unit_MoveToListHead(void *unit, s32 listId) {
    void fn_800156A0(void *, void *);
    void fn_800157DC(void *, void *);
    void fn_800946F0(void *);
    extern u8 gUnitLists[];

    switch (listId) {
    case 0:
    case 2:
    case 3:
        fn_800946F0(unit);
    }
    fn_800156A0(*(void **)((u8 *)unit + 0x190), unit);
    fn_800157DC(gUnitLists + listId * 0xC, unit);
}

#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
void fn_8003D70C(s32 arg0) {
    extern u8 lbl_80330708[];
    void *fn_8014D8FC(void *);
    s32 fn_801661CC(void *);
    void *fn_8000D354(void *);
    u8 fn_80105BC0(s32, s32);
    s8 fn_801F1A2C(void);
    s32 fn_8000CEE4(s32);

    void *partner;
    s16 s7;
    s16 s6;
    s16 s5;
    s16 s4;
    s16 s3;
    s16 s2;
    s16 s1;
    s16 s0;
    s32 bonus;
    s32 level;
    u8 *cls;
    s32 factor;

    level = fn_801661CC(fn_8014D8FC(lbl_80330708));
    if (*(u8 *)(*(u8 **)(arg0 + 0x190) + 8) != 1) {
        level = 0;
    }
    level += (s8)*(u8 *)(arg0 + 0x19A);
    if (level > 0x14) {
        level = 0x14;
    }
    if (level < 1) {
        level = 1;
    }
    *(u8 *)(arg0 + 0x19A) = level;

    cls = *(u8 **)(arg0 + 0x18C);
    s0 = level * cls[0x54];
    s1 = level * cls[0x55];
    s2 = level * cls[0x56];
    s3 = level * cls[0x57];
    s4 = level * cls[0x58];
    s5 = level * cls[0x59];
    s6 = level * cls[0x5A];
    s7 = level * cls[0x5B];
    if (*(void **)(cls + 0xC) != NULL) {
        partner = fn_8000D354(*(void **)(cls + 0xC));
    } else {
        partner = NULL;
    }

    if (partner != NULL) {
        if (fn_80105BC0(arg0 + 0x1BC, 2) != 0) {
            if (fn_80105BC0(arg0 + 0x1BC, 8) == 0) {
                if (fn_80105BC0((s32)partner + 0x1C, 2) == 0) {
                    bonus = (s8)fn_801F1A2C();
                    bonus += fn_801661CC(fn_8014D8FC(lbl_80330708));
                    s0 += bonus * ((u8 *)partner)[0x54];
                    s1 += bonus * ((u8 *)partner)[0x55];
                    s2 += bonus * ((u8 *)partner)[0x56];
                    s3 += bonus * ((u8 *)partner)[0x57];
                    s4 += bonus * ((u8 *)partner)[0x58];
                    s5 += bonus * ((u8 *)partner)[0x59];
                    s6 += bonus * ((u8 *)partner)[0x5A];
                    s7 += bonus * ((u8 *)partner)[0x5B];
                }
            }
        }
    }

    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1AB) = *(u8 *)(arg0 + 0x1AB) + (s0 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1AC) = *(u8 *)(arg0 + 0x1AC) + (s1 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1AD) = *(u8 *)(arg0 + 0x1AD) + (s2 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1AE) = *(u8 *)(arg0 + 0x1AE) + (s3 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1AF) = *(u8 *)(arg0 + 0x1AF) + (s4 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1B0) = *(u8 *)(arg0 + 0x1B0) + (s5 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1B1) = *(u8 *)(arg0 + 0x1B1) + (s6 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1B2) = *(u8 *)(arg0 + 0x1B2) + (s7 * factor) / 10000;
}
#pragma pop
s32 Unit_CanReceiveItem(s32 unit, void *item) {
    /* True if item is free, under CON wt limit, and unit has an empty item/held slot. */
    u64 *Item_GetFlagsPtr(void *);
    u8 Item_GetWt(void *);
    s32 Unit_GetCarryWtLimit(void);
    s32 Unit_FindEmptyItemSlot(s32);
    s32 Unit_FindEmptyHeldSlot(s32);
    s8 lim;
    u8 code;

    if (((*(u8 *)((u8 *)item + 5) >> 7) & 1) != 0) {
        code = 2;
    } else {
        lim = (s8)Unit_GetCarryWtLimit();
        if ((s32)Item_GetWt(item) >= (s32)lim) {
            code = 1;
        } else {
            if ((*Item_GetFlagsPtr(item) & 5ULL) != 0) {
                if (Unit_FindEmptyHeldSlot(unit) < 0) {
                    code = 3;
                    goto end;
                }
            } else if (Unit_FindEmptyItemSlot(unit) < 0) {
                code = 3;
                goto end;
            }
            code = 0;
        }
    }
end:
    return code == 0;
}

s32 Unit_CheckReceiveItem(s32 unit, void *item) {
    /* Status for giving item to unit: 0 ok, 1 over weight, 2 locked, 3 no free slot. */
    u64 *Item_GetFlagsPtr(void *);
    u8 Item_GetWt(void *);
    s32 Unit_GetCarryWtLimit(void);
    s32 Unit_FindEmptyItemSlot(s32);
    s32 Unit_FindEmptyHeldSlot(s32);
    s8 lim;

    if (((*(u8 *)((u8 *)item + 5) >> 7) & 1) != 0) {
        return 2;
    }
    lim = (s8)Unit_GetCarryWtLimit();
    if ((s32)Item_GetWt(item) >= (s32)lim) {
        return 1;
    }
    if ((*Item_GetFlagsPtr(item) & 5ULL) != 0) {
        if (Unit_FindEmptyHeldSlot(unit) < 0) {
            return 3;
        }
    } else {
        if (Unit_FindEmptyItemSlot(unit) < 0) {
            return 3;
        }
    }
    return 0;
}

s32 fn_8003DC80(s32 arg0, s32 arg1) {
    s8 fn_8003AEB0(s32);
    s32 temp_r31;
    s32 temp_r4;

    temp_r31 = (s8)fn_8003AEB0(arg1);
    temp_r4 = (s8)fn_8003AEB0(arg0);
    return temp_r31 < temp_r4;
}

void fn_8003DCDC(u8 *arg0, u8 *arg1, s32 arg2, s8 *arg3, s8 *arg4) {
    s32 b19e;
    s32 a19e;
    s32 a19f;
    s32 b19f;
    s32 d0;
    s32 d1;
    int new_var;

    b19e = *(s8 *)(arg1 + 0x19E);
    a19e = arg0[0x19E];
    a19f = arg0[0x19F];
    d0 = (s8)(b19e - a19e);
    b19f = arg1[0x19F];
    d1 = (s8)(b19f - a19f);
    new_var = arg2 * d0;
    *arg3 = (s8)(new_var + b19e);
    d1 = d1 * arg2;
    *arg4 = (s8)(d1 + arg1[0x19F]);
}

s32 fn_8003DD20(s32 arg0, s32 arg1) {
    s8 fn_8003A1E0(s32);
    s32 temp_r31;
    s32 temp_r4;

    temp_r31 = (s8)fn_8003A1E0(arg1);
    temp_r4 = (s8)fn_8003A1E0(arg0);
    return temp_r31 <= (temp_r4 + 2);
}

s32 fn_8003DD7C(s32 arg0, s32 arg1) {
    s8 fn_8003A1E0(s32);
    u8 Status_Test(s32, s32);
    s32 temp_r31;
    s32 temp_r4;

    if (Status_Test(arg1 + 0x1BC, 3) != 0) {
        return 0;
    }
    temp_r31 = fn_8003A1E0(arg1);
    temp_r4 = fn_8003A1E0(arg0);
    return (temp_r31 <= (temp_r4 - 2));
}

#pragma use_lmw_stmw on
void fn_8003DDF8(void *arg0, s8 *arg1, s8 *arg2) {
    extern u8 gBattleMap[];
    void Map_SelectRangeBuffer(void *, s32);
    void fn_800227F8(void *, void *);
    void fn_80022748(void *, s32);
    void Map_FloodMoveRange(void *, u8, u8, s32, s32, s32);
    s16 fn_8002134C(u8 *, s8, s8);

    s32 x;
    s32 y;
    u16 bestCost;
    u8 *layer;
    u8 *mapHi;
    u8 *row;
    u8 *map;
    s32 rowOff;
    void *unit;
    s8 *outX;
    s8 *outY;
    s16 cost;

    unit = arg0;
    outX = arg1;
    outY = arg2;

    layer = gBattleMap + 0xD;
    map = *(u8 **)((u8 *)unit + 0x194);
    layer[((s8)*((u8 *)unit + 0x19E)) + (((s8)*((u8 *)unit + 0x19F)) << 6)] = 0;
    Map_SelectRangeBuffer(gBattleMap, 5);
    fn_800227F8(gBattleMap, *(void **)((u8 *)unit + 0x18C));
    fn_80022748(gBattleMap, 0);
    Map_FloodMoveRange(gBattleMap, *((u8 *)unit + 0x19E), *((u8 *)unit + 0x19F), 0x3E8, 0, 0);
    fn_800227F8(gBattleMap, *(void **)(map + 0x18C));
    fn_80022748(gBattleMap, *(s32 *)(map + 0x190));

    *outX = -1;
    map = gBattleMap;
    bestCost = 0x7FFF;
    *outY = -1;
    mapHi = map + 0x10000;

    for (y = (s8)map[9]; y <= (s8)map[0xB] - 1; y++) {
        rowOff = (s8)y << 6;
        row = map + rowOff;
        for (x = (s8)map[8]; x <= (s8)map[0xA] - 1; x++) {
            if ((s16)fn_8002134C(map, (s8)x, (s8)y) <= 0x7530) {
                if (row[(s8)x + 0xD] == 0 && row[(s8)x + 0x100D] != 0x37) {
                    cost = (*(s16 **)(mapHi + 0x4190))[(s8)x + rowOff];
                    if (bestCost > (u16)cost) {
                        *outX = (s8)x;
                        bestCost = (u16)cost;
                        *outY = (s8)y;
                    }
                }
            }
        }
    }

    layer[((s8)*((u8 *)unit + 0x19E)) + (((s8)*((u8 *)unit + 0x19F)) << 6)] = *((u8 *)unit + 0x198);
}
void fn_8003DFB8(void *arg0) {
    void fn_800156A0(void *, void *);
    void fn_80015718(void *, void *);
    void fn_800157DC(void *, void *);
    void Unit_SetMapPos(void *, s32, s32);
    void Unit_Clear(void *, s32);
    void Unit_MoveToListHead(void *, s32);
    void Unit_SeparateRescue(void *, s32, s32);
    void *fn_8003F1AC(s32);
    u8 fn_8003F1C0(void *);
    void *fn_8003F1C8(void *);
    u32 fn_8003F1D0(s32 *, s32);
    void fn_8003F1DC(s32 *, s32);
    void fn_8003F1EC(void *, s32);
    void fn_8003F1F4(s32 *, s32);
    void *fn_8003F204(void *);
    s32 fn_8003F20C(void *);
    s32 fn_8003F214(void *);
    s32 *fn_8003F21C(void *);
    void fn_8004EA60(void *, s32);
    extern u8 gUnitLists[];

    void *self = arg0;
    void *partner = *(void **)((u8 *)self + 0x194);
    s32 flags;
    void *other;
    s32 a, b;
    void *p;
    void *next;

    if (partner == NULL) {
        goto finish;
    }

    flags = *(s32 *)((u8 *)self + 0x1A0);
    if (flags & 2) {
        a = ((u8 *)self)[0x19F];
        b = ((u8 *)self)[0x19E];
        *(s32 *)((u8 *)self + 0x1A0) = flags & ~2;
        *(s32 *)((u8 *)partner + 0x1A0) = *(s32 *)((u8 *)partner + 0x1A0) & ~4;
        *(void **)((u8 *)self + 0x194) = NULL;
        *(void **)((u8 *)partner + 0x194) = NULL;
        Unit_SetMapPos(partner, b, a);
        *(s32 *)((u8 *)partner + 0x1A0) |= 1;

        if (*(void **)((u8 *)partner + 0x194) != NULL) {
            if (*fn_8003F21C(partner) & 2) {
                other = *(void **)((u8 *)partner + 0x194);
                a = fn_8003F214(partner);
                b = fn_8003F20C(partner);
                p = fn_8003F204(partner);
                fn_8003F1F4(fn_8003F21C(partner), 2);
                fn_8003F1F4(fn_8003F21C(p), 4);
                fn_8003F1EC(partner, 0);
                fn_8003F1EC(p, 0);
                Unit_SetMapPos(p, b, a);
                fn_8003F1DC(fn_8003F21C(p), 1);
                if (fn_8003F204(other) != NULL) {
                    if (fn_8003F1D0(fn_8003F21C(other), 2) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(other, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    } else if (fn_8003F1D0(fn_8003F21C(other), 4) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(next, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    }
                }
                fn_8004EA60(other, 1);
                if (fn_8003F1C0(fn_8003F1C8(other)) == 0) {
                    Unit_MoveToListHead(other, 5);
                    fn_8003F1DC(fn_8003F21C(other), 0x4000);
                } else {
                    fn_800156A0(fn_8003F1C8(other), other);
                    Unit_Clear(other, -1);
                    fn_80015718(fn_8003F1AC(4), other);
                }
            } else if (*fn_8003F21C(partner) & 4) {
                other = *(void **)((u8 *)partner + 0x194);
                a = fn_8003F214(partner);
                b = fn_8003F20C(partner);
                p = fn_8003F204(other);
                fn_8003F1F4(fn_8003F21C(other), 2);
                fn_8003F1F4(fn_8003F21C(p), 4);
                fn_8003F1EC(other, 0);
                fn_8003F1EC(p, 0);
                Unit_SetMapPos(p, b, a);
                fn_8003F1DC(fn_8003F21C(p), 1);
                if (fn_8003F204(other) != NULL) {
                    if (fn_8003F1D0(fn_8003F21C(other), 2) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(other, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    } else if (fn_8003F1D0(fn_8003F21C(other), 4) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(next, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    }
                }
                fn_8004EA60(other, 1);
                if (fn_8003F1C0(fn_8003F1C8(other)) == 0) {
                    Unit_MoveToListHead(other, 5);
                    fn_8003F1DC(fn_8003F21C(other), 0x4000);
                } else {
                    fn_800156A0(fn_8003F1C8(other), other);
                    Unit_Clear(other, -1);
                    fn_80015718(fn_8003F1AC(4), other);
                }
            }
        }

        fn_8004EA60(partner, 1);
        if (*(u8 *)(*(u8 **)((u8 *)partner + 0x190) + 8) == 0) {
            fn_800156A0(fn_8003F1C8(partner), partner);
            fn_800157DC(fn_8003F1AC(5), partner);
            *fn_8003F21C(partner) |= 0x4000;
        } else {
            fn_800156A0(*(void **)((u8 *)partner + 0x190), partner);
            Unit_Clear(partner, -1);
            fn_80015718(gUnitLists + 0x30, partner);
        }
    } else if (flags & 4) {
        other = *(void **)((u8 *)partner + 0x194);
        *(s32 *)((u8 *)partner + 0x1A0) = *(s32 *)((u8 *)partner + 0x1A0) & ~2;
        a = ((u8 *)self)[0x19F];
        b = ((u8 *)self)[0x19E];
        *(s32 *)((u8 *)other + 0x1A0) = *(s32 *)((u8 *)other + 0x1A0) & ~4;
        *(void **)((u8 *)partner + 0x194) = NULL;
        *(void **)((u8 *)other + 0x194) = NULL;
        Unit_SetMapPos(other, b, a);
        *(s32 *)((u8 *)other + 0x1A0) |= 1;

        if (*(void **)((u8 *)partner + 0x194) != NULL) {
            if (*fn_8003F21C(partner) & 2) {
                other = *(void **)((u8 *)partner + 0x194);
                a = fn_8003F214(partner);
                b = fn_8003F20C(partner);
                p = fn_8003F204(partner);
                fn_8003F1F4(fn_8003F21C(partner), 2);
                fn_8003F1F4(fn_8003F21C(p), 4);
                fn_8003F1EC(partner, 0);
                fn_8003F1EC(p, 0);
                Unit_SetMapPos(p, b, a);
                fn_8003F1DC(fn_8003F21C(p), 1);
                if (fn_8003F204(other) != NULL) {
                    if (fn_8003F1D0(fn_8003F21C(other), 2) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(other, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    } else if (fn_8003F1D0(fn_8003F21C(other), 4) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(next, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    }
                }
                fn_8004EA60(other, 1);
                if (fn_8003F1C0(fn_8003F1C8(other)) == 0) {
                    Unit_MoveToListHead(other, 5);
                    fn_8003F1DC(fn_8003F21C(other), 0x4000);
                } else {
                    fn_800156A0(fn_8003F1C8(other), other);
                    Unit_Clear(other, -1);
                    fn_80015718(fn_8003F1AC(4), other);
                }
            } else if (*fn_8003F21C(partner) & 4) {
                other = *(void **)((u8 *)partner + 0x194);
                a = fn_8003F214(partner);
                b = fn_8003F20C(partner);
                p = fn_8003F204(other);
                fn_8003F1F4(fn_8003F21C(other), 2);
                fn_8003F1F4(fn_8003F21C(p), 4);
                fn_8003F1EC(other, 0);
                fn_8003F1EC(p, 0);
                Unit_SetMapPos(p, b, a);
                fn_8003F1DC(fn_8003F21C(p), 1);
                if (fn_8003F204(other) != NULL) {
                    if (fn_8003F1D0(fn_8003F21C(other), 2) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(other, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    } else if (fn_8003F1D0(fn_8003F21C(other), 4) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(next, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    }
                }
                fn_8004EA60(other, 1);
                if (fn_8003F1C0(fn_8003F1C8(other)) == 0) {
                    Unit_MoveToListHead(other, 5);
                    fn_8003F1DC(fn_8003F21C(other), 0x4000);
                } else {
                    fn_800156A0(fn_8003F1C8(other), other);
                    Unit_Clear(other, -1);
                    fn_80015718(fn_8003F1AC(4), other);
                }
            }
        }

        fn_8004EA60(partner, 1);
        if (*(u8 *)(*(u8 **)((u8 *)partner + 0x190) + 8) == 0) {
            fn_800156A0(fn_8003F1C8(partner), partner);
            fn_800157DC(fn_8003F1AC(5), partner);
            *fn_8003F21C(partner) |= 0x4000;
        } else {
            fn_800156A0(*(void **)((u8 *)partner + 0x190), partner);
            Unit_Clear(partner, -1);
            fn_80015718(gUnitLists + 0x30, partner);
        }
    }

finish:
    fn_8004EA60(self, 1);
    if (*(u8 *)(*(u8 **)((u8 *)self + 0x190) + 8) == 0) {
        fn_800156A0(fn_8003F1C8(self), self);
        fn_800157DC(fn_8003F1AC(5), self);
        *(s32 *)((u8 *)self + 0x1A0) |= 0x4000;
    } else {
        fn_800156A0(*(void **)((u8 *)self + 0x190), self);
        Unit_Clear(self, -1);
        fn_80015718(gUnitLists + 0x30, self);
    }
}
#pragma use_lmw_stmw reset

#pragma global_optimizer off
void Unit_OnZeroHp(void *unit) {
    u8 Status_Test(void *, s32);
    void Unit_SetHp(void *, s8);
    void fn_8004EA60(void *, s32);
    void fn_800156A0(void *, void *);
    void fn_800157DC(void *, void *);
    void fn_80015718(void *, void *);
    void fn_8003670C(void *);
    s32 Unit_GetMaxHp(void *);
    void Unit_Clear(void *, s32);
    extern u8 gUnitLists[];
    extern u8 gBattleState[];
    u32 flags;
    u8 *bs;

    if ((s8)((u8 *)unit)[0x1A8] != 0) {
        return;
    }
    if ((u8)Status_Test((u8 *)unit + 0x1BC, 0x5C) != 0) {
        Unit_SetHp(unit, 1);
        *(u32 *)((u8 *)unit + 0x1A0) &= ~0x800U;
        return;
    }
    *(u32 *)((u8 *)unit + 0x1A0) |= 8;
    fn_8004EA60(unit, 1);
    if (*(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8) == 0) {
        fn_800156A0(*(void **)((u8 *)unit + 0x190), unit);
        fn_800157DC(gUnitLists + 0x48, unit);
        flags = *(u32 *)((u8 *)unit + 0x1A0);
        bs = gBattleState;
        flags = flags | 0x8000U;
        *(u32 *)((u8 *)unit + 0x1A0) = flags;
        ((u8 *)unit)[0x234] = bs[0x10];
        fn_8003670C(unit);
        return;
    }
    if ((u8)Status_Test((u8 *)unit + 0x1BC, 0x59) != 0) {
        fn_800156A0(*(void **)((u8 *)unit + 0x190), unit);
        fn_800157DC(gUnitLists + 0x54, unit);
        Unit_SetHp(unit, (s8)Unit_GetMaxHp(unit));
        return;
    }
    fn_800156A0(*(void **)((u8 *)unit + 0x190), unit);
    Unit_Clear(unit, -1);
    fn_80015718(gUnitLists + 0x30, unit);
}
#pragma global_optimizer on
void Unit_SeparateRescue(void *arg0, s32 arg1, s32 arg2) {
    void Unit_SetMapPos(void *, s32, s32);
    s32 flags;
    void *partner;

    flags = *(s32 *)((u8 *)arg0 + 0x1A0);
    partner = *(void **)((u8 *)arg0 + 0x194);
    *(s32 *)((u8 *)arg0 + 0x1A0) = flags & ~2;
    *(s32 *)((u8 *)partner + 0x1A0) = *(s32 *)((u8 *)partner + 0x1A0) & ~4;
    *(void **)((u8 *)arg0 + 0x194) = NULL;
    *(void **)((u8 *)partner + 0x194) = NULL;
    Unit_SetMapPos(partner, arg1, arg2);
    *(s32 *)((u8 *)partner + 0x1A0) |= 1;
}

void Unit_Rescue(void *arg0, void *arg1) {
    u8 y = *(volatile u8 *)((u8 *)arg0 + 0x19F);
    u8 x = *(u8 *)((u8 *)arg0 + 0x19E);
    Unit_SetMapPos(arg1, x, y);
    *(s32*)((u8*)arg0 + 0x1A0) |= 2;
    *(s32*)((u8*)arg1 + 0x1A0) |= 4;
    *(void**)((u8*)arg0 + 0x194) = arg1;
    *(void**)((u8*)arg1 + 0x194) = arg0;
}

#pragma use_lmw_stmw on
void Unit_InitFromDispos(void *arg0, void *arg1) {
    void *Res_GetByName(void *);
    void fn_80104410(void *);
    void Unit_SetMapPos(void *, u8, u8);
    void Status_OrByName(void *, void *);
    s32 Str_Cmp(void *, void *);
    u8 Status_Test(void *, s32);
    void *fn_80028854(void);
    void fn_8003C1B4(void *);
    void fn_8003D70C(void *);
    void fn_8001753C(void *);
    void fn_8003708C(void *, u8 *);
    void fn_80094A54(void *);
    void fn_800946F0(void *);
    void *Unit_GetItemSlot(void *, s32);
    u8 fn_80094768(void *);
    void Unit_ResetHeldFromClass(void *);
    void Unit_ApplyStatusWpnExp(void *);
    u8 Unit_GetWpnExp(void *, u8);
    void *Unit_GetHeldItemSlot(void *, s32);
    u8 fn_80093DA8(void *);
    void fn_800056A0(s32);
    void fn_80036834(void *);
    void fn_800951D0(void *, s32);
    void fn_80095070(void *, s32);
    s32 Unit_GetMaxHp(void *);
    void Unit_SetHp(void *, s8);
    u8 fn_80091D74(void *);
    void Unit_ApplyTransform(void *);
    void fn_8004FE58(void *);
    void fn_8003C67C(void *);
    void fn_8003C4B0(void *, void *);
    void fn_801E35EC(void *, void *);
    extern u8 gBattleState[];
    extern u8 gSystemSave[];

    struct Self {
        u8 pad[0x188];
        void *unk188;
        void *unk18C;
        u8 pad190[4];
        s32 unk194;
        u8 pad198;
        u8 unk199;
        u8 unk19A;
        u8 unk19B;
        u8 unk19C;
        u8 pad19D[3];
        s32 unk1A0;
        u8 pad1A4[5];
        u8 unk1A9;
        u8 unk1AA;
        u8 pad1AB[9];
        u8 unk1B4;
        u8 unk1B5;
        u8 unk1B6;
        u8 unk1B7;
        u8 unk1B8;
        u8 unk1B9;
        u8 unk1BA;
        u8 unk1BB;
        u32 unk1BC;
        u32 unk1C0;
        u32 unk1C4;
        u32 unk1C8;
        u8 pad1CC[0x40];
        u8 unk20C[8];
        u8 pad214[0x14];
        s16 unk228;
        s16 unk22A;
        s16 unk22C;
        s16 unk22E;
        s16 unk230;
        s16 unk232;
        u8 unk234;
        u8 unk235;
        u8 pad236[0x12];
        u8 unk248;
        u8 pad249[0xB];
        u32 unk254;
    };
    struct Src {
        void *unk0;
        void *unk4;
        u8 unk8;
        u8 pad9;
        u8 unkA;
        u8 unkB;
        u8 unkC;
        u8 padD[3];
        void *unk10[8];
        u8 flags[8];
        u8 pad38[0x10];
        void *unk48[5];
        u8 unk5C[8];
        u8 unk64;
        u8 pad65;
        u8 unk66;
        u8 unk67;
    };
    struct ItemFlag { u8 pad : 1; u8 flag : 1; u8 rest : 6; };

    u8 sp8[8];
    struct Src *src = arg1;
    struct Self *self = arg0;
    s32 i;
    struct Src *walk;
    u8 t;
    void *item;
    void *p;
    u8 a, b;
    u8 j;
    void *c;

    self->unk188 = Res_GetByName(src->unk0);
    self->unk19B = 0;
    self->unk1A9 = 0;
    self->unk1AA = 0;
    self->unk1A0 = 0;
    fn_80104410((u8 *)self + 0x1A4);
    self->unk194 = 0;
    self->unk1C8 = 0;
    self->unk1C4 = 0;
    self->unk1C0 = 0;
    self->unk1BC = 0;
    self->unk228 = 0;
    self->unk22A = 0;
    self->unk22C = 0;
    self->unk22E = 0;
    self->unk230 = 0;
    self->unk232 = 0;
    self->unk234 = 0;
    self->unk235 = 0;
    if (src->unk4 == 0) {
        self->unk18C = Res_GetByName(*(void **)((u8 *)self->unk188 + 0x10));
    } else {
        self->unk18C = Res_GetByName(src->unk4);
    }
    Unit_SetMapPos(self, src->unkB, src->unkC);
    c = self->unk188;
    self->unk1BC |= *(u32 *)((u8 *)c + 0x40);
    self->unk1C0 |= *(u32 *)((u8 *)c + 0x44);
    self->unk1C4 |= *(u32 *)((u8 *)c + 0x48);
    self->unk1C8 |= *(u32 *)((u8 *)c + 0x4C);
    c = self->unk18C;
    self->unk1BC |= *(u32 *)((u8 *)c + 0x1C);
    self->unk1C0 |= *(u32 *)((u8 *)c + 0x20);
    self->unk1C4 |= *(u32 *)((u8 *)c + 0x24);
    self->unk1C8 |= *(u32 *)((u8 *)c + 0x28);
    walk = src;
    for (i = 0; i < 5; i++) {
        if (walk->unk48[0] != 0) {
            Status_OrByName(&self->unk1BC, walk->unk48[0]);
        }
        walk = (struct Src *)((u8 *)walk + 4);
    }
    if (Str_Cmp(src->unk4, *(void **)((u8 *)self->unk188 + 0x10)) != 0 ||
        src->unkA > (s8)*(u8 *)((u8 *)self->unk188 + 0x1A)) {
        self->unk19A = src->unkA;
    } else {
        self->unk19A = *(u8 *)((u8 *)self->unk188 + 0x1A);
    }
    if (Status_Test(&self->unk1BC, 0x4E) != 0) {
        if (fn_80028854() != 0) {
            fn_80028854();
        }
        if (Status_Test(&self->unk1BC, 2) != 0) {
            self->unk19A = 1;
        } else {
            self->unk19A = 0xA;
        }
    }
    fn_8003C1B4(self);
    t = src->unk64;
    if (t != 0 && t < 0x14) {
        self->unk19C = t;
    }
    if (src->unk8 & 1) {
        fn_8003D70C(self);
        fn_8001753C(&self->unk228);
    }
    sp8[0] = src->unk5C[0];
    sp8[1] = src->unk5C[1];
    sp8[2] = src->unk5C[2];
    sp8[3] = src->unk5C[3];
    sp8[4] = src->unk5C[4];
    sp8[5] = src->unk5C[5];
    sp8[6] = src->unk5C[6];
    sp8[7] = src->unk5C[7];
    fn_8003708C(self, sp8);
    walk = src;
    self->unk1B4 = *((u8 *)self->unk188 + 0x2D);
    self->unk1B5 = *((u8 *)self->unk188 + 0x2E);
    self->unk1B6 = *((u8 *)self->unk188 + 0x2F);
    self->unk1B7 = *((u8 *)self->unk188 + 0x30);
    self->unk1B8 = *((u8 *)self->unk188 + 0x31);
    self->unk1B9 = *((u8 *)self->unk188 + 0x32);
    self->unk1BA = *((u8 *)self->unk188 + 0x33);
    self->unk1BB = *((u8 *)self->unk188 + 0x34);
    for (i = 0; i < 8; i++) {
        if (walk->unk10[0] != 0) {
            t = src->flags[i];
            if ((t & 2) == 0 || gBattleState[0x57] != 1) {
                fn_80094A54(self);
                t = src->flags[i];
                if (t & 1) {
                    if (t & 2) {
                        fn_800946F0(self);
                        p = Unit_GetItemSlot(self, i);
                        ((struct ItemFlag *)((u8 *)p + 5))->flag = 1;
                    } else if (fn_80094768(self) == 0) {
                        p = Unit_GetItemSlot(self, i);
                        ((struct ItemFlag *)((u8 *)p + 5))->flag = 1;
                    }
                }
            }
        }
        walk = (struct Src *)((u8 *)walk + 4);
    }
    Unit_ResetHeldFromClass(self);
    self->unk20C[0] = *((u8 *)self->unk18C + 0x2C);
    self->unk20C[1] = *((u8 *)self->unk18C + 0x2D);
    self->unk20C[2] = *((u8 *)self->unk18C + 0x2E);
    self->unk20C[3] = *((u8 *)self->unk18C + 0x2F);
    self->unk20C[4] = *((u8 *)self->unk18C + 0x30);
    self->unk20C[5] = *((u8 *)self->unk18C + 0x31);
    self->unk20C[6] = *((u8 *)self->unk18C + 0x32);
    self->unk20C[7] = *((u8 *)self->unk18C + 0x33);
    Unit_ApplyStatusWpnExp(self);
    for (j = 0; j < 8; j++) {
        if (Unit_GetWpnExp(self, j) != 0) {
            t = *((u8 *)self->unk188 + 0x35 + j);
            if (t != 0) {
                self->unk20C[j] = t;
            }
        }
    }
    if (src->unk8 & 1) {
        for (i = 0; i < 4; i++) {
            item = Unit_GetHeldItemSlot(self, i);
            if (item != 0 && *(s32 *)item != 0 && fn_80093DA8(self) == 0) {
                p = *(void **)item;
                a = p ? *(u8 *)((u8 *)p + 0x12) : 0xC;
                if (a < 8) {
                    p = *(void **)item;
                    a = p ? *(u8 *)((u8 *)p + 0x12) : 0xC;
                    if (Unit_GetWpnExp(self, a) == 0) {
                        if (((*(u8 *)((u8 *)item + 5) >> 6) & 1) == 0) {
                            fn_800056A0(0);
                        }
                    } else {
                        p = *(void **)item;
                        b = p ? *(u8 *)((u8 *)p + 0x16) : 0;
                        p = *(void **)item;
                        a = p ? *(u8 *)((u8 *)p + 0x12) : 0xC;
                        if ((u8)Unit_GetWpnExp(self, a) < b) {
                            p = *(void **)item;
                            b = p ? *(u8 *)((u8 *)p + 0x16) : 0;
                            p = *(void **)item;
                            a = p ? *(u8 *)((u8 *)p + 0x12) : 0xC;
                            self->unk20C[a] = b;
                        }
                    }
                }
            }
        }
    }
    fn_80036834(self);
    fn_800951D0(self, -1);
    fn_80095070(self, -1);
    Unit_SetHp(self, (s8)Unit_GetMaxHp(self));
    if (fn_80091D74(self) != 0 && Status_Test(&self->unk1BC, 9) == 0) {
        Unit_ApplyTransform(self);
    }
    fn_8004FE58(self);
    t = src->unk67;
    if (t != 0) {
        self->unk199 = t;
    }
    if (src->unk8 & 4) {
        self->unk1A0 |= 0x100;
    }
    fn_8003C67C(self);
    fn_8003C4B0(self, src);
    self->unk248 = src->unk66;
    if (src->unk8 & 2) {
        self->unk254 |= 0x02000000;
    }
    if (src->unk8 & 0x10) {
        self->unk254 |= 0x10000000;
    }
    if (src->unk8 & 0x20) {
        self->unk254 |= 0x20000000;
    }
    if (src->unk8 & 0x40) {
        self->unk254 |= 0x20000;
    }
    fn_801E35EC(gSystemSave, self->unk188);
    self->unk1A0 |= 0x80000;
}
#pragma use_lmw_stmw reset

void *fn_8003F1AC(s32 arg0) {
    extern u8 gUnitLists[];
    return gUnitLists + arg0 * 0xC;
}

u8 fn_8003F1C0(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 8);
}

s32 fn_8003F1C8(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x190);
}

s32 fn_8003F1D0(s32 *arg0, s32 arg1) {
    return *arg0 & arg1;
}

void fn_8003F1DC(s32 *arg0, s32 arg1) {
    *arg0 |= arg1;
}

void fn_8003F1EC(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x194) = arg1;
}

void fn_8003F1F4(s32 *arg0, s32 arg1) {
    *arg0 &= ~arg1;
}

s32 fn_8003F204(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x194);
}

u8 fn_8003F20C(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x19E);
}

u8 fn_8003F214(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x19F);
}

s32 fn_8003F21C(s32 arg0) {
    return arg0 + 0x1A0;
}

void *fn_8003F224(void *arg0, s32 arg1) {
    extern s8 *lbl_80366DC0;
    s8 *ref;
    void *ptr;
    u8 ok;
    u32 k;
    u32 *entry;
    u32 *base;
    u32 *var_r7;
    void *result;
    u32 count;

    ptr = arg0;
    ref = lbl_80366DC0;

    for (k = 0; k < 7; k++) {
        if ((s8)((u8 *)ptr)[0x18 + k] != ref[k]) {
            ok = 0;
            goto done1;
        }
    }
    ok = 1;
done1:

    switch (ok) {
    case 0:
        ptr = (u8 *)ptr - 0x20;

        for (k = 0; k < 7; k++) {
            if ((s8)((u8 *)ptr)[0x18 + k] != ref[k]) {
                ok = 0;
                goto done2;
            }
        }
        ok = 1;
done2:

        switch (ok) {
        case 0:
            ptr = 0;
        }
    }

    {
        u32 unk4;
        u32 idx8;
        u32 unkC;
        u32 unk10;
        u32 t;

        unk4 = *(u32 *)((u8 *)ptr + 4);
        idx8 = (u32)arg1 << 3;
        unkC = *(u32 *)((u8 *)ptr + 0xC);
        unk4 &= ~3u;
        var_r7 = (u32 *)((u8 *)ptr + unk4);
        count = *(u32 *)((u8 *)ptr + 8);
        unk10 = *(u32 *)((u8 *)ptr + 0x10);
        t = count << 2;
        unkC <<= 3;
        var_r7 = (u32 *)((u8 *)var_r7 + 0x20);
        base = (u32 *)((u8 *)var_r7 + t);
        t = unk10 << 3;
        entry = (u32 *)((u8 *)base + idx8);
        result = (u8 *)base + unkC + t + entry[1];
    }

    {
        u32 i;
        for (i = 0; i < count; i++) {
            if (entry[0] == *var_r7) {
                return result;
            }
            var_r7++;
        }
    }
    return result;
}

s32 fn_8003F47C(void *arg0) {
    extern s8 *lbl_80366DC0;
    s8 *ref;
    void *ptr;
    u8 ok;
    u32 k;

    ptr = arg0;
    ref = lbl_80366DC0;

    for (k = 0; k < 7; k++) {
        if ((s8)((u8 *)ptr)[0x18 + k] != ref[k]) {
            ok = 0;
            goto done1;
        }
    }
    ok = 1;
done1:

    switch (ok) {
    case 0:
        ptr = (u8 *)ptr - 0x20;

        for (k = 0; k < 7; k++) {
            if ((s8)((u8 *)ptr)[0x18 + k] != ref[k]) {
                ok = 0;
                goto done2;
            }
        }
        ok = 1;
done2:

        switch (ok) {
        case 0:
            ptr = 0;
        }
    }

    return *(s32 *)((u8 *)ptr + 0xC);
}

void fn_8005C7E8(void *);
void fn_8003F670(void *arg0) {
    void fn_8005C7E8(void *);
    extern s8 *lbl_80366DC0;
    s8 *ref;
    void *ptr;
    u8 ok;
    u32 k;

    ptr = arg0;
    ref = lbl_80366DC0;

    for (k = 0; k < 7; k++) {
        if ((s8)((u8 *)ptr)[0x18 + k] != ref[k]) {
            ok = 0;
            goto done1;
        }
    }
    ok = 1;
done1:

    switch (ok) {
    case 0:
        ptr = (u8 *)ptr - 0x20;

        for (k = 0; k < 7; k++) {
            if ((s8)((u8 *)ptr)[0x18 + k] != ref[k]) {
                ok = 0;
                goto done2;
            }
        }
        ok = 1;
done2:

        switch (ok) {
        case 0:
            ptr = 0;
        }
    }

    fn_8005C7E8(ptr);
}
