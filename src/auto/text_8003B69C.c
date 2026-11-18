/* Functions from 0x800330F8 to 0x80055C70, found by decomp-toolkit. */
#include "common.h"
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

void fn_8003B844(void *arg0,s32 arg1) {
 void *outer=arg0;
 s32 i=0;
 void *entry;
 s32 j;
 while(i<arg1) {
  entry=outer; j=0;
  while(j<M2C_FIELD(outer,s32*,4)) {
   if (M2C_FIELD(entry,void**,8)!=0) M2C_FIELD(entry,void**,8)=(void*)Person_GetByPid(M2C_FIELD(entry,void**,8));
   entry=(u8*)entry+8; j++;
  }
  M2C_FIELD(Person_GetByPid(M2C_FIELD(outer,void**,0)),void**,0x50)=outer;
  i++;
  outer=(u8*)outer+(M2C_FIELD(outer,s32*,4)*8)+8;
 }
}

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

    if (res != 0) {
        unit->res = Res_GetByName(res);
    } else {
        unit->res = 0;
    }

    res = unit->res;

    unit->status[0] |= *(u32 *)((u8 *)res + 0x1C);
    unit->status[1] |= *(u32 *)((u8 *)res + 0x20);
    unit->status[2] |= *(u32 *)((u8 *)res + 0x24);
    unit->status[3] |= *(u32 *)((u8 *)res + 0x28);

    unit->flags &= ~0x2000;

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
 unit->flags&=~0x2000;
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

    u8 *unit;
    u8 *job;
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

        if (Status_Test(
                *(u8 **)(unit + 0x18C) + 0x1C,
                2
            ) != 0) {
            if (Status_Test(job + 0x1C, 2) == 0) {
                if (*(void **)(job + 0xC) != NULL) {
                    job = (u8 *)Res_GetByName(*(void **)(job + 0xC));
                } else {
                    job = NULL;
                }
            }
        } else {
            if (Status_Test(job + 0x1C, 2) != 0) {
                if (*(void **)(job + 0xC) != NULL) {
                    job = (u8 *)Res_GetByName(*(void **)(job + 0xC));
                } else {
                    job = NULL;
                }
            }
        }
    }

finish:
    if (job != NULL) {
        *(void **)(unit + 0x18C) = job;

        fn_800951D0(unit, -1);
        fn_8004E9D8(unit, 0);
        fn_80050C90(unit);
    }
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
#pragma global_optimizer reset
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
    s32 i;
    u32 tmp;
    void *p;

    p = *(void **)((u8 *)arg0 + 0x188);
    if (p == NULL) {
        Stream_WriteU16(arg1, 0);
        return;
    }
    Stream_WriteU16(arg1, *(u16 *)((u8 *)p + 0x18));
    Stream_WriteU16(arg1, *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0x38));
    Stream_WriteU8(arg1, *((u8 *)*(void **)((u8 *)arg0 + 0x190) + 8));
    p = *(void **)((u8 *)arg0 + 0x180);
    if (p != NULL) {
        tmp = *((u8 *)p + 0x198);
    } else {
        tmp = 0;
    }
    Stream_WriteU8(arg1, (u8)tmp);
    p = *(void **)((u8 *)arg0 + 0x184);
    if (p != NULL) {
        tmp = *((u8 *)p + 0x198);
    } else {
        tmp = 0;
    }
    Stream_WriteU8(arg1, (u8)tmp);
    p = *(void **)((u8 *)arg0 + 0x194);
    if (p != NULL) {
        tmp = *((u8 *)p + 0x198);
    } else {
        tmp = 0;
    }
    Stream_WriteU8(arg1, (u8)tmp);
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x199));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x19A));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x19B));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x19C));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x19D));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x19E));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x19F));
    Stream_Write(arg1, 4, (u8 *)arg0 + 0x1A0);
    fn_80104160((u8 *)arg0 + 0x1A4, arg1);
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x1A8));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x1A9));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x1AA));
    Stream_Write(arg1, 8, (u8 *)arg0 + 0x1AB);
    Stream_Write(arg1, 8, (u8 *)arg0 + 0x1B4);
    fn_80105A30((u8 *)arg0 + 0x1BC, arg1);
    for (i = 0; i < 8; i++) {
        fn_8001C21C((void *)Unit_GetItemSlot((s32)arg0, i), arg1);
    }
    fn_8001D044((u8 *)arg0 + 0x20C, arg1);
    fn_800174A8((u8 *)arg0 + 0x228, arg1);
    Stream_Write(arg1, 0xA, (u8 *)arg0 + 0x214);
    Unit_WriteExtra(arg0, arg1);
    fn_8004BCCC(arg0, arg1);
    Stream_WriteU16(arg1, 0);
}

void fn_8003CCB0(void *arg0,u8 *arg1,u8 *arg2) {
 extern u8 gBattleMap[],lbl_8026A520[];
 void Map_SelectRangeBuffer(void *,s32); void fn_80022748(void *,s32); void fn_800227F8(void *,void *);
 void *Job_GetByJid(void *); void Map_FloodMoveRange(void *,u8,u8,s32,s32,s32);
 u8 Map_IsAiTerrainBlocked(s8,s8); s16 fn_8002134C(u8 *,s8,s8);
 u8 *outY,*outX; void *unit; u8 *map; u8 saved; u8 *layer,*mapHi,*row,*tile;
 s32 rowOff,index; u16 best; register s32 y,x;
 outY=arg2; outX=arg1; unit=arg0;
 map=gBattleMap; layer=map+13;
 index=(s8)M2C_FIELD(unit,u8 *,0x19E)+((s8)M2C_FIELD(unit,u8 *,0x19F)<<6);
 saved=layer[index]; layer[index]=0;
 Map_SelectRangeBuffer(map,5);
 fn_80022748(gBattleMap,0);
 fn_800227F8(gBattleMap,Job_GetByJid(lbl_8026A520+0x50));
 Map_FloodMoveRange(gBattleMap,*outX,*outY,64,0,0);
 fn_800227F8(gBattleMap,M2C_FIELD(unit,void **,0x18C));
 map=gBattleMap; best=9999; mapHi=map+0x10000;
 for(y=(s8)map[9];y<=(s8)map[11]-1;y++) {
 rowOff=(s8)y<<6; row=map+rowOff;
 for(x=(s8)map[8];x<=(s8)map[10]-1;x++) {
 index=(s8)x+rowOff;
 if((*(s16 **)(mapHi+0x4190))[index]>=0) {
 tile=row+(s8)x;
 if((s8)tile[0xE18E]==0 && !Map_IsAiTerrainBlocked((s8)x,(s8)y) && tile[13]==0 &&
 fn_8002134C(gBattleMap,(s8)x,(s8)y)<=30000) {
 s16 cost=(*(s16 **)(mapHi+0x4190))[index];
 if(best>(u16)cost) { *outX=x; best=(u16)cost; *outY=y; }
 }
 }
 }
 }
 layer[(s8)M2C_FIELD(unit,u8 *,0x19E)+((s8)M2C_FIELD(unit,u8 *,0x19F)<<6)]=saved;
}

void fn_8003CE88(void *unit, s32 range) {
#pragma use_lmw_stmw on
extern u8 gBattleMap[];
void Map_SelectRangeBuffer(void *,s32);
void Map_FillLayer(void *,s32,s32);
void fn_800227F8(void *,void *);
s16 fn_8002134C(u8 *,s8,s8);
s32 negativeDy,dy;
u8 *row;
s32 sy,sx;
s32 y,x;
u8 ux,uy;
ux=*((u8 *)unit+0x19E); uy=*((u8 *)unit+0x19F);
Map_SelectRangeBuffer(gBattleMap,5);
Map_FillLayer(gBattleMap,5,-1);
fn_800227F8(gBattleMap,*(void **)((u8 *)unit+0x18C));
sy=(s8)uy; sx=(s8)ux;
y=gBattleMap[9];
for(y=(s8)y; y <= (s8)gBattleMap[11]-1; y++) {
x=gBattleMap[8];
for(x=(s8)x; x <= (s8)gBattleMap[10]-1; x++) {
s32 dx,absoluteY;
dy=sy-y; negativeDy=-dy;
row=gBattleMap+((s8)y<<6);
if(dy<0) absoluteY=negativeDy; else absoluteY=dy;
if(sx-x<0) dx=-(sx-x); else dx=sx-x;
if (dx+absoluteY<=range) {

if(row[(s8)x+0xD]==0 && (s8)row[(s8)x+0xE18E]==0 && row[(s8)x+0x200D]!=0 &&
fn_8002134C(gBattleMap,(s8)x,(s8)y)<=30000) {
(*(s16 **)(gBattleMap+0x14190))[(s8)x+((s8)y<<6)]=0;
}
}
}
}
}

u8 Unit_CalcHitRate(void *arg0, void *arg1) {
    s32 Unit_GetMagAtk(void *);
    s32 fn_8003A778(void *);
    s32 fn_8003AF28(void *);
    u8 Unit_GetDistance(void *, void *);
    s32 u;
    s32 t;
    u8 d;

    t = (s8)Unit_GetMagAtk(arg0);
    t = (t - (s8)fn_8003A778(arg1)) * 5;
    u = (s8)fn_8003AF28(arg0);
    d = Unit_GetDistance(arg0, arg1);
    t = (t + u + 0x1E) - ((u8)d << 1);
    if (t > 0x64) {
        t = 0x64;
    }
    if (t < 0) {
        t = 0;
    }
    return (u8)t;
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

u8 fn_8003D13C(void *arg0)
{
    extern u8 gBattleState[];

    u8 fn_800386B0(void *);
    u8 Status_Test(void *, s32);
    void *Res_GetByName(void *);

    u8 *unit;
    u8 *classData;
    s32 limit;
    s32 result;
    s32 level;
    u8 value;
    void *res;

    unit = (u8 *)arg0;

    if (gBattleState[0x9F] & 8) {
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
        result = 0;
    } else if (Status_Test(unit + 0x1BC, 8) != 0) {
        result = 0;
    } else if (Status_Test(unit + 0x1BC, 0x4D) != 0) {
        result = 0;
    } else {
        res = *(void **)(*(u8 **)(unit + 0x18C) + 0xC);

        if (res != 0) {
            res = Res_GetByName(res);
        }

        if (res == 0) {
            result = 0;
        } else {
            level = (s8)unit[0x19A];

            if (level < 10) {
                result = 0;
            } else {
                result = 1;
            }
        }
    }

    if (result != 0) {
        limit = 0x7D0;
    }

    value = fn_800386B0(unit);
    level = (s8)unit[0x19A];

    result = limit - ((level - 1) * 100 + value);

    if (result > 100) {
        result = 100;
    }

    if (result < 0) {
        result = 0;
    }

    return (u8)result;
}

#pragma opt_strength_reduction off
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
        fn_800156A0(*(void **)((u8 *)unit + 0x190), unit);
        fn_80015718(gUnitLists + listId * 0xC, unit);
        return;
    }
}

void Unit_MoveToListHead(void *arg0, s32 arg1)
{
    extern u8 gUnitLists[];

    extern void fn_800946F0(void *);
    extern void fn_800156A0(void *, void *);
    extern void fn_800157DC(void *, void *);

    u8 *obj;
    s32 index;

    obj = (u8 *)arg0;
    index = arg1;

    if (index != 1) {
        if (index < 1) {
            if (index >= 0) {
                fn_800946F0(obj);
            }
        } else {
            if (index < 4) {
                fn_800946F0(obj);
            }
        }
    }

    fn_800156A0(*(void **)(obj + 0x190), obj);

    fn_800157DC(
        gUnitLists + index * 0xC,
        obj
    );
}

#pragma use_lmw_stmw on
void fn_8003D70C(s32 arg0) {
    extern u8 gBattleState[];
    void *fn_8014D8FC(void *);
    s32 fn_801661CC(void *);
    void *Res_GetByName(void *);
    u8 Status_Test(s32, s32);
    s8 fn_801F1A2C(void);
    s32 Rand_Range(s32);

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

    level = fn_801661CC(fn_8014D8FC(gBattleState));
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
    s0 = (s16)(level * cls[0x54]);
    s1 = (s16)(level * cls[0x55]);
    s2 = (s16)(level * cls[0x56]);
    s3 = (s16)(level * cls[0x57]);
    s4 = (s16)(level * cls[0x58]);
    s5 = (s16)(level * cls[0x59]);
    s6 = (s16)(level * cls[0x5A]);
    s7 = (s16)(level * cls[0x5B]);
    {
        void *name = *(void **)(cls + 0xC);
        if (name != NULL) {
            partner = Res_GetByName(name);
        } else {
            partner = NULL;
        }
    }

    if (partner != NULL && Status_Test(arg0 + 0x1BC, 2) != 0 && Status_Test(arg0 + 0x1BC, 8) == 0 && Status_Test((s32)partner + 0x1C, 2) == 0) {
        u8 *p = (u8 *)partner;
        bonus = (s8)fn_801F1A2C();
        bonus += fn_801661CC(fn_8014D8FC(gBattleState));
        s0 = (s16)(s0 + bonus * p[0x54]);
        s1 = (s16)(s1 + bonus * p[0x55]);
        s2 = (s16)(s2 + bonus * p[0x56]);
        s3 = (s16)(s3 + bonus * p[0x57]);
        s4 = (s16)(s4 + bonus * p[0x58]);
        s5 = (s16)(s5 + bonus * p[0x59]);
        s6 = (s16)(s6 + bonus * p[0x5A]);
        s7 = (s16)(s7 + bonus * p[0x5B]);
    }

    factor = 0x64 - (0xA - Rand_Range(0x14));
    *(u8 *)(arg0 + 0x1AB) = *(u8 *)(arg0 + 0x1AB) + (s0 * factor) / 10000;
    factor = 0x64 - (0xA - Rand_Range(0x14));
    *(u8 *)(arg0 + 0x1AC) = *(u8 *)(arg0 + 0x1AC) + (s1 * factor) / 10000;
    factor = 0x64 - (0xA - Rand_Range(0x14));
    *(u8 *)(arg0 + 0x1AD) = *(u8 *)(arg0 + 0x1AD) + (s2 * factor) / 10000;
    factor = 0x64 - (0xA - Rand_Range(0x14));
    *(u8 *)(arg0 + 0x1AE) = *(u8 *)(arg0 + 0x1AE) + (s3 * factor) / 10000;
    factor = 0x64 - (0xA - Rand_Range(0x14));
    *(u8 *)(arg0 + 0x1AF) = *(u8 *)(arg0 + 0x1AF) + (s4 * factor) / 10000;
    factor = 0x64 - (0xA - Rand_Range(0x14));
    *(u8 *)(arg0 + 0x1B0) = *(u8 *)(arg0 + 0x1B0) + (s5 * factor) / 10000;
    factor = 0x64 - (0xA - Rand_Range(0x14));
    *(u8 *)(arg0 + 0x1B1) = *(u8 *)(arg0 + 0x1B1) + (s6 * factor) / 10000;
    factor = 0x64 - (0xA - Rand_Range(0x14));
    *(u8 *)(arg0 + 0x1B2) = *(u8 *)(arg0 + 0x1B2) + (s7 * factor) / 10000;
}

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

#pragma dont_inline on
void fn_8003DDF8(void *arg0, s8 *arg1, s8 *arg2) {
    extern u8 gBattleMap[];
    void Map_SelectRangeBuffer(void *, s32);
    void fn_800227F8(void *, void *);
    void fn_80022748(void *, s32);
    void Map_FloodMoveRange(void *, u8, u8, s32, s32, s32);
    s16 fn_8002134C(u8 *, s8, s8);
    s8 *outY;
    s8 *outX;
    void *unit;
    void *other;
    u8 *layer;
    u8 *map;
    u8 *row;
    u8 *mapHi;
    s32 x, y;
    s32 rowOff;
    s16 cost;
    u16 bestCost;

    outY = arg2;
    outX = arg1;
    unit = arg0;
    map = gBattleMap;
    layer = map + 0xD;
    other = *(void **)((u8 *)unit + 0x194);
    layer[((s8)*((u8 *)unit + 0x19E)) + (((s8)*((u8 *)unit + 0x19F)) << 6)] = 0;
    Map_SelectRangeBuffer(map, 5);
    fn_800227F8(gBattleMap, *(void **)((u8 *)unit + 0x18C));
    fn_80022748(gBattleMap, 0);
    Map_FloodMoveRange(gBattleMap, *((u8 *)unit + 0x19E), *((u8 *)unit + 0x19F), 0x3E8, 0, 0);
    fn_800227F8(gBattleMap, *(void **)((u8 *)other + 0x18C));
    fn_80022748(gBattleMap, *(s32 *)((u8 *)other + 0x190));
    *outX = -1;
    map = gBattleMap;
    bestCost = 0x7FFF;
    *outY = -1;
    mapHi = map + 0x10000;
    y = (s8)map[9];
    while (y <= (s8)map[0xB] - 1) {
        rowOff = (s8)y << 6;
        x = (s8)map[8];
        row = map + rowOff;
        while (x <= (s8)map[0xA] - 1) {
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
            x = x + 1;
        }
        y = y + 1;
    }
    layer[((s8)*((u8 *)unit + 0x19E)) + (((s8)*((u8 *)unit + 0x19F)) << 6)] = *((u8 *)unit + 0x198);
}
#pragma dont_inline reset
void fn_8003DFB8(void *arg0) {
    void fn_800156A0(void *);
    void fn_80015718(void *, void *);
    void fn_800157DC(void *, void *);
    void Unit_SetMapPos(void *, u8, u8);
    void Unit_Clear(void *, s32);
    void Unit_MoveToListHead(void *, s32);
    void Unit_SeparateRescue(void *, s32, s32);
    void *fn_8003F1AC(s32);
    u8 fn_8003F1C0(void *);
    void *fn_8003F1C8(void *);
    s32 fn_8003F1D0(s32 *, s32);
    void fn_8003F1DC(s32 *, s32);
    void fn_8003F1EC(void *, s32);
    void fn_8003F1F4(s32 *, s32);
    void *fn_8003F204(void *);
    u8 fn_8003F20C(void *);
    u8 fn_8003F214(void *);
    s32 *fn_8003F21C(void *);
    void fn_8004EA60(void *, s32);
    extern u8 gUnitLists[];

    void *self = arg0;
    void *partner = *(void **)((u8 *)self + 0x194);
    s32 flags;
    void *other;
    void *next;
    u8 a, b;
    void *p;

    if (partner == NULL) {
        goto finish;
    }

    flags = *(s32 *)((u8 *)self + 0x1A0);
    if (flags & 2) {
        a = ((u8 *)self)[0x19F];
        *(s32 *)((u8 *)self + 0x1A0) = flags & ~2;
        b = ((u8 *)self)[0x19E];
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
                    fn_8003F1C8(other);
                    fn_800156A0(other);
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
                    fn_8003F1C8(other);
                    fn_800156A0(other);
                    Unit_Clear(other, -1);
                    fn_80015718(fn_8003F1AC(4), other);
                }
            }
        }

        fn_8004EA60(partner, 1);
        if (*(u8 *)(*(u8 **)((u8 *)partner + 0x190) + 8) == 0) {
            fn_8003F1C8(partner);
            fn_800156A0(partner);
            fn_800157DC(fn_8003F1AC(5), partner);
            *fn_8003F21C(partner) |= 0x4000;
        } else {
            fn_800156A0(partner);
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
                    fn_8003F1C8(other);
                    fn_800156A0(other);
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
                    fn_8003F1C8(other);
                    fn_800156A0(other);
                    Unit_Clear(other, -1);
                    fn_80015718(fn_8003F1AC(4), other);
                }
            }
        }

        fn_8004EA60(partner, 1);
        if (*(u8 *)(*(u8 **)((u8 *)partner + 0x190) + 8) == 0) {
            fn_8003F1C8(partner);
            fn_800156A0(partner);
            fn_800157DC(fn_8003F1AC(5), partner);
            *fn_8003F21C(partner) |= 0x4000;
        } else {
            fn_800156A0(partner);
            Unit_Clear(partner, -1);
            fn_80015718(gUnitLists + 0x30, partner);
        }
    }

finish:
    fn_8004EA60(self, 1);
    if (*(u8 *)(*(u8 **)((u8 *)self + 0x190) + 8) == 0) {
        fn_800156A0(self);
        fn_800157DC(fn_8003F1AC(5), self);
        *(s32 *)((u8 *)self + 0x1A0) |= 0x4000;
    } else {
        fn_800156A0(self);
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
        *(u32 *)((u8 *)unit + 0x1A0) |= 0x8000;
        ((u8 *)unit)[0x234] = gBattleState[0x10];
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
    Unit_SetMapPos(arg1, *(u8*)((u8*)arg0 + 0x19F), *(u8*)((u8*)arg0 + 0x19E));
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
    s8 Unit_GetMaxHp(void *);
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
        u8 pad30[8];
        void *unk48[5];
        u8 unk5C[8];
        u8 unk64;
        u8 pad65;
        u8 unk66;
        u8 unk67;
    };
    struct Cls {
        u8 pad[0x10];
        void *unk10;
        u8 pad14[6];
        u8 unk1A;
        u8 pad1B[0x25];
        u8 unk40[0x10];
        u8 unk2D_dummy;
    };

    u8 sp8[8];
    struct Self *self;
    struct Src *src;
    struct Src *walk;
    s32 i;
    u8 t;
    void *item;
    void *p;
    u8 a, b;
    u8 j;
    void *c;

    self = (struct Self *)arg0;
    src = (struct Src *)arg1;
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
    c = self->unk188;
    if (Str_Cmp(src->unk4, *(void **)((u8 *)c + 0x10)) != 0 ||
        src->unkA > (s8)*(u8 *)((u8 *)c + 0x1A)) {
        self->unk19A = src->unkA;
    } else {
        self->unk19A = *(u8 *)((u8 *)c + 0x1A);
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
            t = *((u8 *)src + i + 0x30);
            if ((t & 2) == 0 || gBattleState[0x57] != 1) {
                fn_80094A54(self);
                t = *((u8 *)src + i + 0x30);
                if (t & 1) {
                    if (t & 2) {
                        fn_800946F0(self);
                        p = Unit_GetItemSlot(self, i);
                        *(u8 *)((u8 *)p + 5) |= 0x40;
                    } else if (fn_80094768(self) == 0) {
                        p = Unit_GetItemSlot(self, i);
                        *(u8 *)((u8 *)p + 5) |= 0x40;
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
            if (item != 0 && *(void **)item != 0 && fn_80093DA8(self) == 0) {
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
    Unit_SetHp(self, Unit_GetMaxHp(self));
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
    u8 ok;
    void *ptr;
    s8 *ref;
    s8 c;
    u32 *var_r7;
    u32 *base;
    u32 *entry;
    void *result;
    u32 count;
    u32 unk4;
    u32 unkC;
    u32 unk10;
    u32 idx8;
    u32 t;
    u32 ctr;

    ref = lbl_80366DC0;
    ptr = arg0;
    c = ((u8 *)ptr)[0x18];
    if ((s8)c != ref[0]) {
        ok = 0;
    } else {
        c = ((u8 *)ptr)[0x19];
        if ((s8)c != ref[1]) {
            ok = 0;
        } else {
            c = ((u8 *)ptr)[0x1A];
            if ((s8)c != ref[2]) {
                ok = 0;
            } else {
                c = ((u8 *)ptr)[0x1B];
                if ((s8)c != ref[3]) {
                    ok = 0;
                } else {
                    c = ((u8 *)ptr)[0x1C];
                    if ((s8)c != ref[4]) {
                        ok = 0;
                    } else {
                        c = ((u8 *)ptr)[0x1D];
                        if ((s8)c != ref[5]) {
                            ok = 0;
                        } else {
                            c = ((u8 *)ptr)[0x1E];
                            if ((s8)c != ref[6]) {
                                ok = 0;
                            } else {
                                ok = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (ok == 0) {
        ptr = (u8 *)ptr - 0x20;
        c = ((u8 *)ptr)[0x18];
        if ((s8)c != ref[0]) {
            ok = 0;
        } else {
            c = ((u8 *)ptr)[0x19];
            if ((s8)c != ref[1]) {
                ok = 0;
            } else {
                c = ((u8 *)ptr)[0x1A];
                if ((s8)c != ref[2]) {
                    ok = 0;
                } else {
                    c = ((u8 *)ptr)[0x1B];
                    if ((s8)c != ref[3]) {
                        ok = 0;
                    } else {
                        c = ((u8 *)ptr)[0x1C];
                        if ((s8)c != ref[4]) {
                            ok = 0;
                        } else {
                            c = ((u8 *)ptr)[0x1D];
                            if ((s8)c != ref[5]) {
                                ok = 0;
                            } else {
                                c = ((u8 *)ptr)[0x1E];
                                if ((s8)c != ref[6]) {
                                    ok = 0;
                                } else {
                                    ok = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (ok == 0) {
            ptr = 0;
        }
    } else {
        goto calc;
    }
calc:
    unk4 = *(u32 *)((u8 *)ptr + 4);
    idx8 = arg1 * 8;
    unkC = *(u32 *)((u8 *)ptr + 0xC);
    unk4 &= ~3u;
    count = *(u32 *)((u8 *)ptr + 8);
    var_r7 = (u32 *)((u8 *)ptr + unk4);
    unk10 = *(u32 *)((u8 *)ptr + 0x10);
    t = count * 4;
    unkC = unkC * 8;
    var_r7 = (u32 *)((u8 *)var_r7 + 0x20);
    base = (u32 *)((u8 *)var_r7 + t);
    t = unk10 * 8;
    entry = (u32 *)((u8 *)base + idx8);
    result = (u8 *)base + unkC + t + entry[1];

    for (ctr = count; ctr != 0; ctr--) {
        if (entry[0] == *var_r7) {
            return result;
        }
        var_r7++;
    }
    return result;
}

s32 fn_8003F47C(void *arg0)
{
    s8 *ref;
    void *ptr;
    u8 ok;

    ptr = arg0;
    ref = lbl_80366DC0;

    if ((s8)((u8 *)ptr)[0x18] != ref[0]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x19] != ref[1]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1A] != ref[2]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1B] != ref[3]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1C] != ref[4]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1D] != ref[5]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1E] != ref[6]) {
        ok = 0;
    } else {
        ok = 1;
    }

    if (ok) {
    } else {
        ptr = (u8 *)ptr - 0x20;

        if ((s8)((u8 *)ptr)[0x18] != ref[0]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x19] != ref[1]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1A] != ref[2]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1B] != ref[3]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1C] != ref[4]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1D] != ref[5]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1E] != ref[6]) {
            ok = 0;
        } else {
            ok = 1;
        }

        if (ok) {
        } else {
            ptr = 0;
        }
    }

    return *(s32 *)((u8 *)ptr + 0xC);
}

void fn_8005C7E8(void *);
void fn_8003F670(void *arg0) {
    s8 *ref;
    void *ptr;
    u8 ok;

    ptr = arg0;
    ref = lbl_80366DC0;
    if ((s8)((u8 *)ptr)[0x18] != ref[0]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x19] != ref[1]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1A] != ref[2]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1B] != ref[3]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1C] != ref[4]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1D] != ref[5]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1E] != ref[6]) {
        ok = 0;
    } else {
        ok = 1;
    }
    if (ok) {
    } else {
        ptr = (u8 *)ptr - 0x20;
        if ((s8)((u8 *)ptr)[0x18] != ref[0]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x19] != ref[1]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1A] != ref[2]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1B] != ref[3]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1C] != ref[4]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1D] != ref[5]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1E] != ref[6]) {
            ok = 0;
        } else {
            ok = 1;
        }
        if (ok) {
        } else {
            ptr = 0;
        }
    }
    fn_8005C7E8(ptr);
}

void *Archive_LoadFlags(s32 arg0, u32 arg1) {
    void *fn_8005C82C(s32, u16);
    void FileCache_MarkRelocated(s32);
    void fn_8000D3EC(void *, void *);
    extern s8 *lbl_80366DC0;

    u8 *base20;
    u32 *p30;
    u8 *p29;
    u32 *p28;
    void *obj;
    s32 self;
    u32 j;
    s8 *ref1;
    s8 *ref2;
    u8 ok;
    u8 c;
    u32 i;
    u32 *walk;
    u32 *scan;
    u32 count;
    void *result;
    u32 t;
    u32 old;
    void *da;
    void *db;

    self = arg0;
    obj = fn_8005C82C(arg0, (u16)(arg1 | 1));
    ref1 = lbl_80366DC0;
    base20 = (u8 *)obj + 0x20;
    t = *(u32 *)((u8 *)obj + 4);
    c = ((u8 *)obj)[0x18];
    t &= ~3u;
    p30 = (u32 *)(base20 + t);
    p28 = (u32 *)((u8 *)p30 + (*(u32 *)((u8 *)obj + 8) << 2));
    p29 = (u8 *)p28 + (*(u32 *)((u8 *)obj + 0xC) << 3) + (*(u32 *)((u8 *)obj + 0x10) << 3);

    if (*(s8 *)((u8 *)obj + 0x18) != *(s8 *)((u8 *)ref1 + 0)) {
        ok = 0;
    } else if (*(s8 *)((u8 *)obj + 0x19) != *(s8 *)((u8 *)ref1 + 1)) {
        ok = 0;
    } else if (*(s8 *)((u8 *)obj + 0x1A) != *(s8 *)((u8 *)ref1 + 2)) {
        ok = 0;
    } else if (*(s8 *)((u8 *)obj + 0x1B) != *(s8 *)((u8 *)ref1 + 3)) {
        ok = 0;
    } else if (*(s8 *)((u8 *)obj + 0x1C) != *(s8 *)((u8 *)ref1 + 4)) {
        ok = 0;
    } else if (*(s8 *)((u8 *)obj + 0x1D) != *(s8 *)((u8 *)ref1 + 5)) {
        ok = 0;
    } else if (*(s8 *)((u8 *)obj + 0x1E) != *(s8 *)((u8 *)ref1 + 6)) {
        ok = 0;
    } else {
        ok = 1;
    }

    if (ok == 0) {
        walk = p30;
        i = 0;
        ((u8 *)obj)[0x18] = ref1[0];
        ((u8 *)obj)[0x19] = lbl_80366DC0[1];
        ((u8 *)obj)[0x1A] = lbl_80366DC0[2];
        ((u8 *)obj)[0x1B] = lbl_80366DC0[3];
        ((u8 *)obj)[0x1C] = lbl_80366DC0[4];
        ((u8 *)obj)[0x1D] = lbl_80366DC0[5];
        ((u8 *)obj)[0x1E] = lbl_80366DC0[6];
        while (i < *(u32 *)((u8 *)obj + 8)) {
            t = *walk;
            walk += 1;
            i += 1;
            t &= ~3u;
            old = *(u32 *)(base20 + t);
            *(u32 *)(base20 + t) = old + (u32)base20;
        }
    }

    if (*(s8 *)((u8 *)obj + 0x1F) == 0) {
        j = 0;
        ((u8 *)obj)[0x1F] = 1;
        while (j < *(u32 *)((u8 *)obj + 0xC)) {
            t = *p28;
            scan = p30;
            da = (u8 *)p29 + p28[1];
            t &= ~3u;
            count = *(u32 *)((u8 *)obj + 8);
            db = (u8 *)base20 + t;
            for (; count != 0; count--) {
                if (*p28 == *scan) {
                    break;
                }
                scan += 1;
            }
            fn_8000D3EC(da, db);
            p28 += 2;
            j += 1;
        }
    }

    FileCache_MarkRelocated(self);
    result = obj;
    ref2 = lbl_80366DC0;
    if (*(s8 *)((u8 *)obj + 0x18) != *(s8 *)((u8 *)ref2 + 0)) {
        ok = 0;
    } else if (*(s8 *)((u8 *)obj + 0x19) != *(s8 *)((u8 *)ref2 + 1)) {
        ok = 0;
    } else if (*(s8 *)((u8 *)obj + 0x1A) != *(s8 *)((u8 *)ref2 + 2)) {
        ok = 0;
    } else if (*(s8 *)((u8 *)obj + 0x1B) != *(s8 *)((u8 *)ref2 + 3)) {
        ok = 0;
    } else if (*(s8 *)((u8 *)obj + 0x1C) != *(s8 *)((u8 *)ref2 + 4)) {
        ok = 0;
    } else if (*(s8 *)((u8 *)obj + 0x1D) != *(s8 *)((u8 *)ref2 + 5)) {
        ok = 0;
    } else if (*(s8 *)((u8 *)obj + 0x1E) != *(s8 *)((u8 *)ref2 + 6)) {
        ok = 0;
    } else {
        ok = 1;
    }

    if (ok) {
    } else {
        result = (u8 *)obj - 0x20;
        if (*(s8 *)((u8 *)result + 0x18) != *(s8 *)((u8 *)ref2 + 0)) {
            ok = 0;
        } else if (*(s8 *)((u8 *)result + 0x19) != *(s8 *)((u8 *)ref2 + 1)) {
            ok = 0;
        } else if (*(s8 *)((u8 *)result + 0x1A) != *(s8 *)((u8 *)ref2 + 2)) {
            ok = 0;
        } else if (*(s8 *)((u8 *)result + 0x1B) != *(s8 *)((u8 *)ref2 + 3)) {
            ok = 0;
        } else if (*(s8 *)((u8 *)result + 0x1C) != *(s8 *)((u8 *)ref2 + 4)) {
            ok = 0;
        } else if (*(s8 *)((u8 *)result + 0x1D) != *(s8 *)((u8 *)ref2 + 5)) {
            ok = 0;
        } else if (*(s8 *)((u8 *)result + 0x1E) != *(s8 *)((u8 *)ref2 + 6)) {
            ok = 0;
        } else {
            ok = 1;
        }
        if (ok) {
        } else {
            result = 0;
        }
    }
    return (u8 *)result + 0x20;
}

void Archive_Load(s32 arg0) {
    void Archive_LoadFlags(s32, s32);
    Archive_LoadFlags(arg0, 0);
}

void *fn_8003FCF0(void *arg0) {
 u8 equal,c; s8 *ref; u8 *p=arg0;
ref=lbl_80366DC0;
 if((s8)p[24]!=(s8)ref[0]) equal=0;
else if((s8)p[25]!=(s8)ref[1]) equal=0;
else if((s8)p[26]!=(s8)ref[2]) equal=0;
else if((s8)p[27]!=(s8)ref[3]) equal=0;
else if((s8)p[28]!=(s8)ref[4]) equal=0;
else if((s8)p[29]!=(s8)ref[5]) equal=0;
else if((s8)p[30]!=(s8)ref[6]) equal=0;
else equal=1;
if(equal) {} else {
 p-=0x20;
 if((s8)p[24]!=(s8)ref[0]) equal=0;
else if((s8)p[25]!=(s8)ref[1]) equal=0;
else if((s8)p[26]!=(s8)ref[2]) equal=0;
else if((s8)p[27]!=(s8)ref[3]) equal=0;
else if((s8)p[28]!=(s8)ref[4]) equal=0;
else if((s8)p[29]!=(s8)ref[5]) equal=0;
else if((s8)p[30]!=(s8)ref[6]) equal=0;
else equal=1;
if(equal) {} else {
 p=0;
}
}
return p;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8003FED8(u8 *arg0) {
    void Hash_Remove(void *);
    u32 j;
    u8 *obj;
    u32 *p30;
    u8 *p29;
    u32 *p28;
    u32 t4;
    u32 t8;
    u32 masked;
    u32 tC;
    u32 t10;

    obj = arg0;
    j = 0;
    t4 = *(u32 *)(arg0 + 4);
    t8 = *(u32 *)(arg0 + 8);
    masked = t4 & ~3u;
    tC = *(u32 *)(arg0 + 0xC);
    t10 = *(u32 *)(obj + 0x10);
    p30 = (u32 *)(obj + masked);
    t8 <<= 2;
    tC <<= 3;
    t10 <<= 3;
    p30 = (u32 *)((u8 *)p30 + 0x20);
    p28 = (u32 *)((u8 *)p30 + t8);
    p29 = (u8 *)((u8 *)p28 + tC + t10);
    while (j < *(u32 *)(obj + 0xC)) {
        u32 *scan = p30;
        u32 count = *(u32 *)(obj + 8);
        void *da = p29 + p28[1];
        u32 i;
        for (i = 0; i < count; i++) {
            if (*p28 == *scan) {
                break;
            }
            scan++;
        }
        Hash_Remove(da);
        p28 += 2;
        j++;
    }
    obj[0x1F] = 0;
}
#pragma global_optimizer on
#pragma use_lmw_stmw reset

void fn_8003FF90(void *arg0, u32 arg1) {
    void *Process_Create(void *, s32);
    void fn_80040028(void *, void *);
    extern u8 lbl_802857A0[];

    if (arg1 == 0) {
        arg1 = 3;
    }
    fn_80040028(Process_Create(lbl_802857A0, arg1), arg0);
}

void fn_8003FFD8(void) {
    M2C_UNK fn_8003FFF8();
    fn_8003FFF8();
}

void fn_8003FFF8(void) {
    extern void *gMap;
    extern void fn_80044450(void *, int);

    if (gMap != 0) {
        fn_80044450(gMap, 0);
    }
}

void fn_80040028(void *arg0, void *arg1)
{
    extern u8 *gMap;
    void fn_80044450(void *, s32);

    u8 *map;
    u8 *entry;
    u8 *obj;
    u8 *list[64];
    u32 flags;
    u32 i;
    s32 count;
    s32 j;
    s32 num;
    u8 valid;

    map = gMap;

    if (map != 0) {
        count = 0;
        j = 0;

        for (i = 0; i < *(s16 *)(map + 6); i++) {
            entry = *(u8 **)(map + 0x14);
            obj = entry + i * 0xB4;

            flags = *(u32 *)(*(u8 **)(obj + 0x10) + 0xBC);

            valid = 0;

            if ((flags & 0x10) == 0) {
                if ((flags & 0x800) != 0) {
                    valid = 1;
                } else if ((flags & 0x1000) != 0) {
                    valid = 1;
                }
            }

            if (valid != 0) {
                valid = 0;

                if ((flags & 0x10) == 0) {
                    if ((flags & 0x100000) == 0) {
                        valid = 1;
                    }
                }

                if (valid != 0) {
                    if ((u8)(u32)arg1 == 0) {
                        if ((flags & 0x1000) != 0) {
                            valid = 0;
                        }
                    }

                    if (valid != 0) {
                        if ((obj[2] & 3) == 0) {
                            list[count] = obj;
                            count++;
                            obj[2] |= 2;
                        }
                    }
                }
            }
        }

        fn_80044450(map, 0);

        if (count > 0) {
            for (j = 0; j < count; j++) {
                list[j][2] &= ~2;
            }
        }
    }
}

void fn_8004022C(void) {
    void Map_PrepareEntryRange(void *, s32, s32);
    void fn_80060060(void *);
    void fn_800609DC(void *);
    void fn_8006785C(s32, void *, void *);
    void fn_8006CAD4(void *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void fn_800449C8(void);
    void fn_80048518(void);
    extern void *gMap;
    extern s32 gGameFlags;
    extern u8 sMapUpdateInited;
    extern s32 sMapUpdateCounter;
    extern f64 lbl_80368EF8;
    extern f32 lbl_80368EE4;
    extern f32 lbl_80368EE8;
    extern f32 lbl_80368EEC;
    extern f32 lbl_80368EF0;
    extern f32 lbl_80368EF4;
    u8 sp98[0x30];
    u8 sp68[0x30];
    u8 sp38[0x30];
    u8 sp8[0x30];
    u32 mask;
    u8 *ent;
    s32 i;
    u8 *sub;
    u8 *obj;
    u8 *p0;
    u8 flags;
    f32 f29v, f28v, f31v, f30v;
    f32 t30;
    s16 t6;
    s32 a, b;
    f32 scale;
    f32 temp_f0;

    obj = gMap;
    if (obj != 0 && (gGameFlags & 2) == 0) {
        if ((*(u32 *)(obj + 0x64) & 0x80000000) == 0 && (*(u32 *)(obj + 0x64) & 0x40000000) != 0) {
            ent = *(u8 **)(obj + 0x14);
            i = 0;
            goto loop_test;
        loop_body:
            sub = ent + 0x14;
            flags = ent[2];
            mask = *(u32 *)(*(u8 **)(ent + 0x10) + 0xBC);
            if ((mask & 1) == 1 && (flags & 1) == 0) {
                if ((mask & 0x400) != 0) {
                    fn_80060060(sub);
                }
                if ((flags & 0x80) == 0) {
                    if ((mask & 0x80) != 0) {
                        f28v = (f32)(s8)ent[0] + lbl_80368EE4;
                        f29v = -(*(f32 *)(ent + 0xC) + *(f32 *)(*(u8 **)((u8 *)gMap + 0x30) + 0x48));
                        t30 = (f32)(s8)ent[1];
                        f31v = *(f32 *)(ent + 8) + lbl_80368EE4;
                        f30v = t30 + lbl_80368EE4;
                        if (*(u8 *)(obj + 0x68) == 1) {
                            a = *(s16 *)obj;
                            b = *(s16 *)(obj + 2);
                            a = a / 2;
                            f28v -= (f32)a;
                            f30v -= (f32)(b / 2);
                        }
                        PSMTXTrans(sp98, lbl_80368EE8, lbl_80368EE4, lbl_80368EE8);
                        PSMTXRotRad(sp68, 0x59, lbl_80368EEC * f31v);
                        PSMTXConcat(sp68, sp98, sp68);
                        PSMTXTrans(sp98, lbl_80368EF0, lbl_80368EE4, lbl_80368EF0);
                        PSMTXConcat(sp98, sp68, sp8);
                        scale = *(f32 *)(obj + 0x6C);
                        PSMTXScale(sp38, scale, scale, scale);
                        PSMTXConcat(sp38, sp8, sp8);
                        temp_f0 = *(f32 *)(obj + 0x6C);
                        PSMTXTrans(sp98, lbl_80368EF4 * (f28v * temp_f0), lbl_80368EF4 * (f29v * temp_f0), lbl_80368EF4 * (f30v * temp_f0));
                        PSMTXConcat(sp98, sp8, sp8);
                        PSMTXConcat(obj + 0x70, sp8, ent + 0x24);
                    }
                    if ((mask & 0x10000) != 0) {
                        fn_8006785C(2, fn_80048518, ent);
                    }
                    fn_800609DC(sub);
                    fn_8006CAD4(sub);
                }
            }
            i += 1;
            ent += 0xB4;
        loop_test:
            if (i < *(s16 *)(obj + 6)) {
                goto loop_body;
            }
        }
    }
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
/* Per-frame map update: alternate half-range prepare, rebuild entry matrices, queue deferred work. */
void Map_Update(void) {
    void Map_PrepareEntryRange(void *, s32, s32);
    void fn_80060060(void *);
    void fn_800609DC(void *);
    void fn_8006785C(s32, void *, void *);
    void fn_8006CAD4(void *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void fn_800449C8(void);
    void fn_80048518(void);
    extern void *gMap;
    extern s32 gGameFlags;
    extern u8 sMapUpdateInited;
    extern s32 sMapUpdateCounter;
    extern f64 lbl_80368EF8;
    extern f32 lbl_80368EE4;
    extern f32 lbl_80368EE8;
    extern f32 lbl_80368EEC;
    extern f32 lbl_80368EF0;
    extern f32 lbl_80368EF4;
    u8 sp98[0x30];
    u8 sp68[0x30];
    u8 sp38[0x30];
    u8 sp8[0x30];
    u32 mask;
    u8 *ent;
    s32 i;
    u8 *sub;
    u8 *obj;
    u8 *p0;
    u8 flags;
    f32 f31v, f30v, f29v, f28v;
    f32 t30;
    s16 t6;
    s32 a, b;
    f32 scale;
    f32 temp_f0;

    p0 = gMap;
    if (p0 != 0 && (gGameFlags & 2) == 0) {
        if (*(u32 *)(p0 + 0xC) != 0) {
            if ((s8)sMapUpdateInited == 0) {
                a = 0;
                sMapUpdateCounter = a;
                sMapUpdateInited = 1;
            }
            if ((sMapUpdateCounter & 1) != 0) {
                t6 = *(s16 *)(p0 + 6);
                a = 0;
                b = (s32)(((u32)t6 >> 31) + t6) >> 1;
            } else {
                b = *(s16 *)(p0 + 6);
                a = (s32)(((u32)b >> 31) + b) >> 1;
            }
            sMapUpdateCounter = sMapUpdateCounter + 1;
            Map_PrepareEntryRange(p0, a, b);
        }
        obj = gMap;
        if ((*(u32 *)(obj + 0x64) & 0x80000000) == 0 && (*(u32 *)(obj + 0x64) & 0x40000000) != 0) {
            ent = *(u8 **)(obj + 0x14);
            i = 0;
            goto loop_test;
        loop_body:
            sub = ent + 0x14;
            flags = ent[2];
            mask = *(u32 *)(*(u8 **)(ent + 0x10) + 0xBC);
            if ((mask & 1) == 0 && (flags & 1) == 0) {
                if ((mask & 0x400) != 0) {
                    fn_80060060(sub);
                }
                if ((flags & 0x80) == 0) {
                    if ((mask & 0x80) != 0) {
                        f28v = (f32)(s8)ent[0] + lbl_80368EE4;
                        f29v = -(*(f32 *)(ent + 0xC) + *(f32 *)(*(u8 **)((u8 *)gMap + 0x30) + 0x48));
                        t30 = (f32)(s8)ent[1];
                        f31v = *(f32 *)(ent + 8) + lbl_80368EE4;
                        f30v = t30 + lbl_80368EE4;
                        if (*(u8 *)(obj + 0x68) == 1) {
                            a = *(s16 *)obj;
                            p0 = (u8 *)*(s16 *)(obj + 2);
                            a = (s32)(((u32)a >> 31) + a) >> 1;
                            f28v -= (f32)a;
                            f30v -= (f32)((s32)(((u32)(s32)p0 >> 31) + (s32)p0) >> 1);
                        }
                        PSMTXTrans(sp98, lbl_80368EE8, lbl_80368EE4, lbl_80368EE8);
                        PSMTXRotRad(sp68, 0x59, lbl_80368EEC * f31v);
                        PSMTXConcat(sp68, sp98, sp68);
                        PSMTXTrans(sp98, lbl_80368EF0, lbl_80368EE4, lbl_80368EF0);
                        PSMTXConcat(sp98, sp68, sp8);
                        scale = *(f32 *)(obj + 0x6C);
                        PSMTXScale(sp38, scale, scale, scale);
                        PSMTXConcat(sp38, sp8, sp8);
                        temp_f0 = *(f32 *)(obj + 0x6C);
                        PSMTXTrans(sp98, lbl_80368EF4 * (f28v * temp_f0), lbl_80368EF4 * (f29v * temp_f0), lbl_80368EF4 * (f30v * temp_f0));
                        PSMTXConcat(sp98, sp8, sp8);
                        PSMTXConcat(obj + 0x70, sp8, ent + 0x24);
                    }
                    if ((mask & 0x10000) != 0) {
                        fn_8006785C(2, fn_80048518, ent);
                    }
                    fn_800609DC(sub);
                    fn_8006CAD4(sub);
                }
            }
            i += 1;
            ent += 0xB4;
        loop_test:
            if (i < *(s16 *)(obj + 6)) {
                goto loop_body;
            }
        }
        if (*(u32 *)((u8 *)gMap + 0xC) != 0 && (*(u32 *)((u8 *)gMap + 0x64) & 0x80000000) == 0) {
            fn_8006785C(2, fn_800449C8, gMap);
        }
    }
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

s32 fn_80040824(void) {
    extern void *gMap;
    if (gMap == NULL) {
        return 0;
    }
    return (M2C_FIELD(gMap, u32 *, 0x64) >> 30) & 1;
}

s32 Map_Get(void) {
    extern u16 *gMap;
    return (s32)gMap;
}

void fn_8004084C(s32 arg0) {
    extern u16 *gMap;
    gMap = (u16 *)arg0;
}

void fn_80040854(void *arg0)
{
    void fn_80041254(void *);
    extern void *gMap;

    void *ptr;

    if ((ptr = arg0) == 0) {
        ptr = gMap;
    }

    if (ptr != 0) {
        fn_80041254(ptr);

        if (ptr == gMap) {
            gMap = 0;
        }
    }
}

void fn_800408A8(void* arg0, void* arg1, s32 arg2) {
    if (arg2 == 0) {
        return;
    }
    
    // Initialize to zero first
    M2C_FIELD(arg0, u8*, 0x196) = 0;
    M2C_FIELD(arg0, u8*, 0x197) = 0;
    M2C_FIELD(arg0, u8*, 0x1A0) = 0;
    M2C_FIELD(arg0, u8*, 0x1A4) = 0;
    M2C_FIELD(arg0, u8*, 0x1A8) = 0;
    M2C_FIELD(arg0, u8*, 0x1A9) = 0;
    M2C_FIELD(arg0, u8*, 0x1B0) = 0;
    M2C_FIELD(arg0, u8*, 0x1B7) = 0;
    M2C_FIELD(arg0, u8*, 0x1B8) = 0;
    M2C_FIELD(arg0, u8*, 0x1B9) = 0;
    M2C_FIELD(arg0, u8*, 0x1BA) = 0;

    if (arg2 & 1) {
        M2C_FIELD(arg0, u8*, 0x196) = 1;
    }
    
    if (arg2 & 2) {
        M2C_FIELD(arg0, u8*, 0x197) = 2;
    }

    if (arg2 & 4) {
        M2C_FIELD(arg0, u8*, 0x1A0) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
    }
    
    if (arg2 & 8) {
        M2C_FIELD(arg0, u8*, 0x1A4) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
    }

    if (arg2 & 0x10) {
        *(u8*)arg1; // Read into temp value, then advance
        arg1 = (u8*)arg1 + 1; 
        M2C_FIELD(arg0, u8*, 0x1A8) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
        M2C_FIELD(arg0, u8*, 0x1A9) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
    }

    if (arg2 & 0x20) {
        M2C_FIELD(arg0, u8*, 0x1B0) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
    }

    if (arg2 & 0x40) {
        M2C_FIELD(arg0, u8*, 0x1B7) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
        M2C_FIELD(arg0, u8*, 0x1B8) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
    }
   
    if (arg2 & 0x80) {
        *(u8*)arg1; // Read first byte
        arg1 = (u8*)arg1 + 1; 
        M2C_FIELD(arg0, u8*, 0x1B9) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
        M2C_FIELD(arg0, u8*, 0x1BA) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
    }
}

u8 fn_80040B1C(void *arg0, s32 arg1, s32 arg2) {
    u8 temp_r6;

    temp_r6 = M2C_FIELD(arg0, u8 *, 0x61);
    if (arg1 < (s32) temp_r6) {
        return 1U;
    }
    if (arg2 < (s32) temp_r6) {
        return 1U;
    }
    if (arg1 >= (s32) (M2C_FIELD(arg0, s16 *, 0) - temp_r6)) {
        return 1U;
    }
    return (u8) ((M2C_FIELD(arg0, s16 *, 2) - temp_r6) <= arg2);
}

void fn_80040B78(void *arg0, u32 arg1) {
extern u8 lbl_80366E90;
extern f32 lbl_80368EE4, lbl_80368F00;
s32 fn_80145F58(u32,void **);
void fn_801478D0(s32);
s8 Fx_AllocSlot(s32,u8,s32,f32,f32,f32);
s8 fn_80147B24(s32,u8,s32,f32,f32,f32);
void *list[10];
s32 count;
void **p;
s32 i;
f32 scale, x,y,z;
void *item;
scale=(f32)lbl_80366E90;
if(arg1==0) {
fn_801478D0(250);
((s8*)arg0)[0xAC]=-1; ((s8*)arg0)[0xAD]=-1; ((s8*)arg0)[0xAE]=-1; ((s8*)arg0)[0xAF]=-1;
((s8*)arg0)[0xB0]=-1; ((s8*)arg0)[0xB1]=-1; ((s8*)arg0)[0xB2]=-1; ((s8*)arg0)[0xB3]=-1;
} else {
count=fn_80145F58(arg1,list);
p=list;
for(i=0;i<count;p++,i++) {
z=y=x=lbl_80368EE4;
item=*p;
switch((s32)((u8*)arg0)[0x68]){
case 0: x=lbl_80368F00+(f32)(s8)((u8*)item)[9]; y=lbl_80368F00+(f32)(s8)((u8*)item)[10]; x*=scale; y*=scale; z=(f32)(s8)((u8*)item)[11]*scale; break;
case 1: x=(f32)(s8)((u8*)item)[9]*scale; y=(f32)(s8)((u8*)item)[11]*scale; z=(f32)(s8)((u8*)item)[10]*scale; break;
}
switch((s32)((u8*)item)[8]){
case 0: ((s8*)arg0)[(u16)(i+0xAC)]=Fx_AllocSlot(*(s32*)((u8*)item+4),((u8*)item)[12],1,x,y,z);break;
case 1: ((s8*)arg0)[(u16)(i+0xAC)]=fn_80147B24(*(s32*)((u8*)item+4),((u8*)item)[12],1,x,y,z);break;
}
}
}
}

void fn_80040DA4(void *arg0) {
void fn_8012391C(void *); void fn_800C1BDC(void); void fn_800C1984(void); void fn_8014716C(s32);
void fn_80067460(s32); void fn_80066F64(void); void *Light_GetChannel(s32);
void Light_CopyChannel(void *,void *); void fn_8006720C(void *);
void fn_800675C8(s32); void *Fog_GetColor(void); void fn_80067480(void);
extern u8 gMapBlendMode,lbl_80367294,lbl_80367295,lbl_8036729C,lbl_80367298,lbl_8036728C,lbl_8036728D,lbl_8036728E,lbl_80367290;
extern f32 lbl_80368EF4;
u8 mode,enabled;
u8 *light; u8 *fog;
fn_8012391C(M2C_FIELD(arg0,void **,0x30));
switch(M2C_FIELD(arg0,u8 *,0x68)) {
case 0:
fn_800C1BDC(); fn_800C1984();
enabled=1; mode=gMapBlendMode-1;
if (((u32)((enabled|~mode)-((u32)(1-mode)>>1))>>31)==0) enabled=0;
if(enabled) fn_8014716C(1); else fn_8014716C(0);
break;
}
fn_80067460(0); fn_80066F64();
light=Light_GetChannel(0);
*(f32 *)(light+0x24)=(f32)(s8)lbl_80367294;
*(f32 *)(light+0x28)=(f32)(s8)lbl_80367295;
light[0]=(&lbl_8036729C)[0];light[1]=(&lbl_8036729C)[1];light[2]=(&lbl_8036729C)[2];
light[4]=(&lbl_80367298)[0];light[5]=(&lbl_80367298)[1];light[6]=(&lbl_80367298)[2];
light=Light_GetChannel(2); Light_CopyChannel(Light_GetChannel(0),light);
fn_8006720C((u8 *)arg0+0x70);
fn_800675C8(0); fog=Fog_GetColor(); fn_80067480();
fog[0]=lbl_8036728C;
*(f32 *)(fog+4)=5.0f*((f32)(s8)lbl_8036728D * M2C_FIELD(arg0,f32 *,0x6C));
*(f32 *)(fog+8)=5.0f*((f32)(s8)lbl_8036728E * M2C_FIELD(arg0,f32 *,0x6C));
fog[1]=(&lbl_80367290)[0];fog[2]=(&lbl_80367290)[1];fog[3]=(&lbl_80367290)[2];
}

/* Decode map header flags at +0x64 into gMapBlendMode and gBattleSkyIndex. */
void Map_DecodeHeaderFlags(void *map) {
    extern u8 gBattleState[];
    extern s8 gMapBlendMode;
    extern s8 gBattleSkyIndex;

    s32 blendBits;
    s32 skyBits;
    s8 blend;

    blendBits = *(s32 *)((char *)map + 0x64) & 0xC0000;
    switch (blendBits) {
    case 0x80000:
        blend = 1;
        if (*(u8 *)((char *)gBattleState + 0xA6) != 1) {
            blend = 0;
        }
        gMapBlendMode = blend;
        break;
    case 0xC0000:
        blend = 2;
        if (*(u8 *)((char *)gBattleState + 0xA6) != 1) {
            blend = 0;
        }
        gMapBlendMode = blend;
        break;
    case 0x40000:
        blend = 3;
        if (*(u8 *)((char *)gBattleState + 0xA6) != 1) {
            blend = 0;
        }
        gMapBlendMode = blend;
        break;
    default:
        blend = 0;
        if (*(u8 *)((char *)gBattleState + 0xA6) != 1) {
            blend = 0;
        }
        gMapBlendMode = blend;
        break;
    }
    skyBits = *(s32 *)((char *)map + 0x64) & 0x01F00000;
    switch (skyBits) {
    case 0x0:
        gBattleSkyIndex = 0;
        return;
    case 0x100000:
        gBattleSkyIndex = 1;
        return;
    case 0x200000:
        gBattleSkyIndex = 2;
        return;
    case 0x300000:
        gBattleSkyIndex = 3;
        return;
    case 0x400000:
        gBattleSkyIndex = 4;
        return;
    case 0x500000:
        gBattleSkyIndex = 5;
        return;
    case 0x600000:
        gBattleSkyIndex = 6;
        return;
    case 0x700000:
        gBattleSkyIndex = 7;
        return;
    case 0x800000:
        gBattleSkyIndex = 8;
        return;
    case 0x900000:
        gBattleSkyIndex = 9;
        return;
    case 0xA00000:
        gBattleSkyIndex = 0xA;
        return;
    case 0xB00000:
        gBattleSkyIndex = 0xB;
        return;
    case 0xC00000:
        gBattleSkyIndex = 0xC;
        return;
    case 0xD00000:
        gBattleSkyIndex = 0xD;
        return;
    case 0xE00000:
        gBattleSkyIndex = 0xE;
        return;
    case 0xF00000:
        gBattleSkyIndex = 0xF;
        return;
    case 0x1000000:
        gBattleSkyIndex = 0x10;
        return;
    case 0x1100000:
        gBattleSkyIndex = 0x11;
        return;
    default:
        gBattleSkyIndex = 0;
        return;
    }
}

#pragma optimization_level 3
void fn_80041254(void *arg0) {
    void Process_UnlinkByKey(void *);
    void Process_Unlink(void *);
    void fn_8006D8E8(void *);
    void fn_8005C7C8(void *);
    void fn_80040B78(void *, s32);
    void fn_800C4588(void *);
    void fn_800C0F94(void);
    void fn_8003F670(void *);
    void fn_8014716C(s32);
    void fn_800616A0(void *);
    void Heap_FreeRaw(void *);
    void fn_8005C7E8(void *);
    void fn_8005BCAC(void);
    void fn_8006805C(f32, f32);
    extern u8 lbl_802856C8[];
    extern u8 lbl_8026A660[];
    extern u8 lbl_80367AF6;
    extern u8 lbl_80367288;
    extern u8 gBattleSkyIndex;
    extern u8 gMapBlendMode;
    extern u8 lbl_8036728B;
    extern u8 lbl_8036728C;
    extern u8 lbl_8036728D;
    extern u8 lbl_8036728E;
    extern u8 lbl_80367294;
    extern u8 lbl_80367295;
    extern u8 lbl_80367298[4];
    extern u8 lbl_8036729C[4];
    extern u8 lbl_80367290[4];
    extern u32 lbl_80368ED0;
    extern u32 lbl_80368ED4;
    extern u32 lbl_80368ED8;
    extern f32 lbl_80368F10;
    extern f32 lbl_80368F14;

    union Colors { u8 bytes[12]; u32 words[3]; }; union Colors colors;
    void *self;
    u8 *keys;
    s32 off;
    s32 i;
    u8 c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11;

    self = arg0;
    keys = lbl_802856C8 + 0x70;
    if (M2C_FIELD(self, u32 *, 0x64) & 0x40000000) {
        M2C_FIELD(self, u32 *, 0x64) &= ~0x40000000;
        Process_UnlinkByKey(keys);
        Process_UnlinkByKey(keys - 0x50);
        Process_UnlinkByKey(keys - 0x70);
        Process_Unlink(M2C_FIELD(self, void **, 0x30));
        M2C_FIELD(self, void **, 0x30) = 0;
        Process_Unlink(M2C_FIELD(self, void **, 0x2C));
        M2C_FIELD(self, void **, 0x2C) = 0;
        fn_8006D8E8(M2C_FIELD(self, void **, 0x38));
        fn_8005C7C8(lbl_8026A660 + 0x112);
        fn_80040B78(self, 0);
        switch (M2C_FIELD(self, u8 *, 0x68)) { case 0:
            if (M2C_FIELD(self, void **, 0xA4) != 0) {
                fn_800C4588(M2C_FIELD(self, void **, 0xA4));
                M2C_FIELD(self, void **, 0xA4) = 0;
                M2C_FIELD(self, void **, 0xA4) = 0;
            }
            fn_800C0F94();
            if (M2C_FIELD(self, void **, 0x1C) != 0) {
                fn_8003F670(M2C_FIELD(self, void **, 0x1C));
                M2C_FIELD(self, void **, 0x1C) = 0;
            }
            if (M2C_FIELD(self, void **, 0x20) != 0) {
                fn_8003F670(M2C_FIELD(self, void **, 0x20));
                M2C_FIELD(self, void **, 0x20) = 0;
            }
            if (M2C_FIELD(self, void **, 0x24) != 0) {
                fn_8003F670(M2C_FIELD(self, void **, 0x24));
                M2C_FIELD(self, void **, 0x24) = 0;
            }
            if (M2C_FIELD(self, void **, 0x28) != 0) {
                fn_8003F670(M2C_FIELD(self, void **, 0x28));
                M2C_FIELD(self, void **, 0x28) = 0;
            }
            if (M2C_FIELD(self, void **, 0x18) != 0) {
                fn_8003F670(M2C_FIELD(self, void **, 0x18));
                M2C_FIELD(self, void **, 0x18) = 0;
            }
            fn_8014716C(0);
            lbl_80367AF6 = 0;
        break; }
        for (i = 0, off = 0; i < M2C_FIELD(self, s16 *, 6); off += 0xB4, i++) {
            fn_800616A0((u8 *)M2C_FIELD(self, void **, 0x14) + off + 0x14);
        }
        {
            s32 offset; s32 index;
            for(index=0,offset=0;index<M2C_FIELD(self,s16 *,4);offset+=0xC0,index++)
                fn_800616A0((u8 *)M2C_FIELD(self,void **,0x10)+offset+4);
        }
        Heap_FreeRaw(M2C_FIELD(self, void **, 0x10));
        M2C_FIELD(self, void **, 0x10) = 0;
        Heap_FreeRaw(M2C_FIELD(self, void **, 0x14));
        M2C_FIELD(self, void **, 0x14) = 0;
        fn_8003F670(M2C_FIELD(self, void **, 0xC));
        M2C_FIELD(self, void **, 0xC) = 0;
        fn_8005C7E8(M2C_FIELD(self, void **, 8));
        M2C_FIELD(self, void **, 8) = 0;
        M2C_FIELD(self, s16 *, 6) = 0;
        M2C_FIELD(self, s16 *, 4) = 0;
        colors.words[0]=lbl_80368ED0;
        colors.words[1]=lbl_80368ED4;
        colors.words[2]=lbl_80368ED8;
        c0 = colors.bytes[0];
        c1 = colors.bytes[1];
        c2 = colors.bytes[2];
        c3 = colors.bytes[3];
        c4 = colors.bytes[4];
        c5 = colors.bytes[5];
        c6 = colors.bytes[6];
        c7 = colors.bytes[7];
        c8 = colors.bytes[8];
        c9 = colors.bytes[9];
        c10 = colors.bytes[10];
        c11 = colors.bytes[11];
        lbl_80367288 = 1;
        gBattleSkyIndex = 0;
        gMapBlendMode = 3;
        lbl_8036728C = 0;
        lbl_8036728D = 0;
        lbl_8036728E = 0;
        lbl_80367294 = 0;
        lbl_80367295 = 0;
        lbl_80367298[0] = c0;
        lbl_80367298[1] = c1;
        lbl_80367298[2] = c2;
        lbl_80367298[3] = c3;
        lbl_8036729C[0] = c4;
        lbl_8036729C[1] = c5;
        lbl_8036729C[2] = c6;
        lbl_8036729C[3] = c7;
        lbl_80367290[0] = c8;
        lbl_80367290[1] = c9;
        lbl_80367290[2] = c10;
        lbl_80367290[3] = c11;
        lbl_8036728B = 0;
        fn_8005BCAC();
        fn_8006805C(lbl_80368F10, lbl_80368F14);
    }
}
#pragma optimization_level reset
void Map_LoadTerrain(void *arg0, char *arg1)
{
    s64 OSGetTime(void);
    s32 strlen(char *);
    void strcpy(void *, char *);
    void strcat(void *, void *);
    s32 FileCache_Load(void *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXCopy(void *, void *);
    void PSMTXIdentity(void *);
    u16 FileCache_Probe(void *);
    u32 Res_GetByName(void *);
    void *Hash_Lookup(void *);
    f32 fn_8001B84C(void *);
    s32 fn_8001B8E0(void *);
    void *Bin_ReadU32(void *);
    void *Heap_AllocRaw(s32);
    void fn_80061824(void *);
    s32 fn_80065EE8(void *);
    s32 fn_8006CE14(void *);
    u8 FileCache_Exists(void *);
    s32 fn_8006D948(void *);
    void fn_8005F5B4(void *, void *);
    void GActor_Finalize(void *);
    void fn_80045D50(void *, void *);
    void fn_80044450(void *, s32);
    void fn_800C1E24(void);
    void fn_8006805C(f32, f32);
    s32 fn_800EE490(void);
    s32 fn_80123BA8(void);
    void fn_8012391C(s32);
    void fn_800C1BDC(void);
    void fn_800C1984(void);
    void fn_8014716C(s32);
    void fn_80067460(s32);
    void fn_80066F64(void);
    void *Light_GetChannel(s32);
    void Light_CopyChannel(void *);
    void fn_8006720C(void *);
    void fn_800675C8(s32);
    void *Fog_GetColor(void);
    void fn_80067480(void);
    void fn_80040B78(void *, void *, void *, s8, f32, f32);
    void *fn_80145EBC(void);
    extern u8 lbl_802EFE20[];
    extern u8 lbl_8026A660[];
    extern f32 lbl_80368F18;
    extern f32 lbl_80368F1C;
    extern f32 lbl_80368F10;
    extern f32 lbl_80368F14;
    extern f32 lbl_80368F20;
    extern f32 lbl_80368F24;
    extern f32 lbl_80368F28;
    extern f32 lbl_80368EF4;
    extern u8 gBattleMap[];
    extern u8 lbl_8036729C;
    extern u8 lbl_80367298;
    extern u8 lbl_80367294;
    extern u8 lbl_80367295;
    extern u8 lbl_80367290;
    extern u8 lbl_8036728C;
    extern u8 lbl_8036728D;
    extern u8 lbl_8036728E;
    extern s8 lbl_80366E90;
    extern u8 lbl_80367AF6;
    extern u8 gMapBlendMode;

    s64 t0;
    u8 sp18[0x30];
    void *cursor;
    char *p;
    char *dst;
    char c;
    s32 mode;
    f32 scale;
    s32 i;
    void *entry;
    void *sub;
    void *name;
    void *tmp;
    u8 *bytes;
    s32 b;
    void *light;
    void *fog;
    s32 (*fccc)(void *) = (s32 (*)(void *))Archive_Load;
    void *(*f87c)(void *, s32) = (void *(*)(void *, s32))Archive_LoadFlags;

    fn_80041254(arg0);
    dst = (char *)arg0 + 0x3C;
    p = arg1 + strlen(arg1) - 1;
    while (p != arg1) {
        c = p[-1];
        p--;
        if ((s8)c == '/' || (s8)c == '\\') {
            p++;
            break;
        }
    }
    for (;;) {
        c = *p;
        if ((s8)c == 0) break;
        if ((s8)c == '/' || (s8)c == '\\') break;
        *dst++ = *p++;
    }
    *dst = 0;

    t0 = OSGetTime();
    mode = ((u8 *)arg0)[0x68];
    if (mode == 0) {
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x161);
        M2C_FIELD(arg0, s32 *, 8) = FileCache_Load(lbl_802EFE20);
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x169);
        M2C_FIELD(arg0, s32 *, 0xC) = fccc(lbl_802EFE20);
        PSMTXRotRad(sp18, 0x58, lbl_80368F18);
        M2C_FIELD(arg0, f32 *, 0x6C) = lbl_80368F1C;
        PSMTXCopy(sp18, (u8 *)arg0 + 0x70);

        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x122);
        if (FileCache_Probe(lbl_802EFE20) != 0x8000) {
            M2C_FIELD(arg0, void **, 0x18) = f87c(lbl_802EFE20, 8);
        }
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x12D);
        if (FileCache_Probe(lbl_802EFE20) != 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x1C) = fccc(lbl_802EFE20);
        }
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x13A);
        if (FileCache_Probe(lbl_802EFE20) != 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x20) = fccc(lbl_802EFE20);
        }
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x147);
        if (FileCache_Probe(lbl_802EFE20) != 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x24) = fccc(lbl_802EFE20);
        }
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x154);
        if (FileCache_Probe(lbl_802EFE20) != 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x28) = fccc(lbl_802EFE20);
        }

        scale = lbl_80368F10;
        if (Res_GetByName(lbl_8026A660 + 0x171) != 0) {
            cursor = Hash_Lookup(lbl_8026A660 + 0x171);
            M2C_FIELD(arg0, s16 *, 0) = *(s16 *)cursor;
            cursor = (u8 *)cursor + 2;
            M2C_FIELD(arg0, s16 *, 2) = *(s16 *)cursor;
            cursor = (u8 *)cursor + 2;
            M2C_FIELD(arg0, s16 *, 4) = *(s16 *)cursor;
            cursor = (u8 *)cursor + 2;
            M2C_FIELD(arg0, s16 *, 6) = *(s16 *)cursor;
            cursor = (u8 *)cursor + 2;
            scale = lbl_80368F10 / fn_8001B84C(&cursor);
        }
        *(f32 *)(gBattleMap + 0x1C2D4) = scale;

        if (Res_GetByName(lbl_8026A660 + 0x17D) != 0) {
            bytes = (u8 *)Hash_Lookup(lbl_8026A660 + 0x17D);
            ((u8 *)arg0)[0x5C] = bytes[0];
            ((u8 *)arg0)[0x5D] = bytes[1];
            ((u8 *)arg0)[0x5E] = bytes[2];
            ((u8 *)arg0)[0x5F] = bytes[3];
            ((u8 *)arg0)[0x60] = bytes[4];
            ((u8 *)arg0)[0x61] = bytes[5];
            ((u8 *)arg0)[0x62] = bytes[6];
            ((u8 *)arg0)[0x63] = bytes[7];
            M2C_FIELD(arg0, s32 *, 0x64) = *(s32 *)(bytes + 8);
        } else {
            ((u8 *)arg0)[0x5C] = 0x18;
            ((u8 *)arg0)[0x5D] = 0x18;
            ((u8 *)arg0)[0x5E] = 0x20;
            ((u8 *)arg0)[0x5F] = 0x20;
            ((u8 *)arg0)[0x60] = 0x40;
            ((u8 *)arg0)[0x61] = 0;
            M2C_FIELD(arg0, s32 *, 0x64) = 0;
        }
        Map_DecodeHeaderFlags(arg0);
        cursor = Hash_Lookup(lbl_8026A660 + 0x186);
        M2C_FIELD(arg0, void **, 0x10) = Heap_AllocRaw(M2C_FIELD(arg0, s16 *, 4) * 0xC0);
        entry = M2C_FIELD(arg0, void **, 0x10);
        for (i = 0; i < M2C_FIELD(arg0, s16 *, 4); i++, entry = (u8 *)entry + 0xC0) {
            M2C_FIELD(entry, f32 *, 0xA4) = fn_8001B84C(&cursor);
            M2C_FIELD(entry, f32 *, 0xA8) = fn_8001B84C(&cursor);
            M2C_FIELD(entry, f32 *, 0xAC) = fn_8001B84C(&cursor);
            M2C_FIELD(entry, f32 *, 0xB0) = fn_8001B84C(&cursor);
            M2C_FIELD(entry, f32 *, 0xB4) = fn_8001B84C(&cursor);
            M2C_FIELD(entry, f32 *, 0xB8) = fn_8001B84C(&cursor);
            M2C_FIELD(entry, s32 *, 0xBC) = fn_8001B8E0(&cursor);
            name = Bin_ReadU32(&cursor);
            M2C_FIELD(entry, void **, 0) = name;
            sub = (u8 *)entry + 4;
            fn_80061824(sub);
            strcpy(lbl_802EFE20, arg1);
            strcat(lbl_802EFE20, name);
            strcat(lbl_802EFE20, lbl_8026A660 + 0x193);
            M2C_FIELD(sub, s32 *, 0x40) = fn_80065EE8(lbl_802EFE20);
            strcpy(lbl_802EFE20, arg1);
            strcat(lbl_802EFE20, name);
            strcat(lbl_802EFE20, lbl_8026A660 + 0x196);
            M2C_FIELD(sub, s32 *, 0x48) = fn_8006CE14(lbl_802EFE20);
            strcpy(lbl_802EFE20, arg1);
            strcat(lbl_802EFE20, lbl_8026A660 + 0x19A);
            strcat(lbl_802EFE20, lbl_8026A660 + 0x1A2);
            if (FileCache_Exists(lbl_802EFE20) != 0) {
                strcpy(lbl_802EFE20, arg1);
                strcat(lbl_802EFE20, lbl_8026A660 + 0x19A);
                strcat(lbl_802EFE20, lbl_8026A660 + 0x1A2);
                M2C_FIELD(sub, s32 *, 0x4C) = fn_8006D948(lbl_802EFE20);
            }
            if (M2C_FIELD(entry, s32 *, 0xBC) & 0x200) {
                strcpy(lbl_802EFE20, arg1);
                strcat(lbl_802EFE20, name);
                strcat(lbl_802EFE20, lbl_8026A660 + 0x1A7);
                fn_8005F5B4(sub, lbl_802EFE20);
            }
            GActor_Finalize(sub);
        }
        fn_80045D50(arg0, lbl_8026A660 + 0x1AB);
        fn_80044450(arg0, 1);
        fn_800C1E24();

        if (Res_GetByName(lbl_8026A660 + 0x1B8) != 0) {
            bytes = (u8 *)Hash_Lookup(lbl_8026A660 + 0x1B8);
            if ((s8)bytes[0] != 0) {
                lbl_80367294 = bytes[1];
                lbl_80367295 = bytes[2];
                (&lbl_8036729C)[0] = bytes[3];
                (&lbl_8036729C)[1] = bytes[4];
                (&lbl_8036729C)[2] = bytes[5];
                (&lbl_80367298)[0] = bytes[6];
                (&lbl_80367298)[1] = bytes[7];
                (&lbl_80367298)[2] = bytes[8];
            }
        } else {
            lbl_80367294 = (u8)-0x1E;
            lbl_80367295 = (u8)-0x1E;
            (&lbl_8036729C)[0] = 0x80;
            (&lbl_8036729C)[1] = 0x80;
            (&lbl_8036729C)[2] = 0x80;
            (&lbl_80367298)[0] = 0xFF;
            (&lbl_80367298)[1] = 0xFF;
            (&lbl_80367298)[2] = 0xFF;
        }
        if (Res_GetByName(lbl_8026A660 + 0x1C1) != 0) {
            bytes = (u8 *)Hash_Lookup(lbl_8026A660 + 0x1C1);
            b = (s8)bytes[0] != 0;
            lbl_8036728C = (u8)(((s8)bytes[1] + 1) & ((s32)(-b | b) >> 31));
            lbl_8036728D = bytes[2];
            lbl_8036728E = bytes[3];
            (&lbl_80367290)[0] = bytes[4];
            (&lbl_80367290)[1] = bytes[5];
            (&lbl_80367290)[2] = bytes[6];
        } else {
            lbl_8036728C = 0;
        }
        if (Res_GetByName(lbl_8026A660 + 0x1C8) != 0) {
            bytes = (u8 *)Hash_Lookup(lbl_8026A660 + 0x1C8);
            ((u8 *)arg0)[0xA3] = bytes[0];
            ((u8 *)arg0)[0xA0] = bytes[1];
            ((u8 *)arg0)[0xA1] = bytes[2];
            ((u8 *)arg0)[0xA2] = bytes[3];
        } else {
            ((u8 *)arg0)[0xA3] = 0x20;
            ((u8 *)arg0)[0xA0] = 0xFF;
            ((u8 *)arg0)[0xA1] = 0xFF;
            ((u8 *)arg0)[0xA2] = 0xFF;
        }
        tmp = fn_80145EBC();
        if (tmp != NULL) {
            lbl_80367AF6 = ((u8 *)tmp)[4];
        } else {
            lbl_80367AF6 = 0;
        }
        lbl_80366E90 = 1;
        fn_8006805C(lbl_80368F10, lbl_80368F14);
    } else if (mode == 1) {
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x1D0);
        M2C_FIELD(arg0, s32 *, 8) = FileCache_Load(lbl_802EFE20);
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x169);
        M2C_FIELD(arg0, s32 *, 0xC) = fccc(lbl_802EFE20);
        PSMTXIdentity(sp18);
        M2C_FIELD(arg0, f32 *, 0x6C) = lbl_80368F20;
        PSMTXCopy(sp18, (u8 *)arg0 + 0x70);
        lbl_80366E90 = 0xF;
        fn_8006805C(lbl_80368F24, lbl_80368F28);
    }

    FileCache_Load(lbl_8026A660 + 0x112);
    M2C_FIELD(arg0, s32 *, 0x38) = fn_8006D948(lbl_8026A660 + 0x21C);
    M2C_FIELD(arg0, s32 *, 0x2C) = fn_800EE490();
    M2C_FIELD(arg0, s32 *, 0x30) = fn_80123BA8();
    M2C_FIELD(arg0, s32 *, 0x64) |= 0x40000000;
    fn_8012391C(M2C_FIELD(arg0, s32 *, 0x30));
    if (M2C_FIELD(arg0, s32 *, 0x68) == 0) {
        fn_800C1BDC();
        fn_800C1984();
        if ((u8)(gMapBlendMode - 1) >= 1) {
            fn_8014716C(1);
        } else {
            fn_8014716C(0);
        }
    }
    fn_80067460(0);
    fn_80066F64();
    light = Light_GetChannel(0);
    M2C_FIELD(light, f32 *, 0x24) = (f32)(s8)lbl_80367294;
    M2C_FIELD(light, f32 *, 0x28) = (f32)(s8)lbl_80367295;
    ((u8 *)light)[0] = (&lbl_8036729C)[0];
    ((u8 *)light)[1] = (&lbl_8036729C)[1];
    ((u8 *)light)[2] = (&lbl_8036729C)[2];
    ((u8 *)light)[4] = (&lbl_80367298)[0];
    ((u8 *)light)[5] = (&lbl_80367298)[1];
    ((u8 *)light)[6] = (&lbl_80367298)[2];
    tmp = Light_GetChannel(2);
    Light_GetChannel(0);
    Light_CopyChannel(tmp);
    fn_8006720C((u8 *)arg0 + 0x70);
    fn_800675C8(0);
    fog = Fog_GetColor();
    fn_80067480();
    ((u8 *)fog)[0] = lbl_8036728C;
    M2C_FIELD(fog, f32 *, 4) = lbl_80368EF4 * ((f32)(s8)lbl_8036728D * M2C_FIELD(arg0, f32 *, 0x6C));
    M2C_FIELD(fog, f32 *, 8) = lbl_80368EF4 * ((f32)(s8)lbl_8036728E * M2C_FIELD(arg0, f32 *, 0x6C));
    ((u8 *)fog)[1] = (&lbl_80367290)[0];
    ((u8 *)fog)[2] = (&lbl_80367290)[1];
    ((u8 *)fog)[3] = (&lbl_80367290)[2];
    fn_80040B78(arg0, (u8 *)arg0 + 0x3C, &lbl_80367290, (s8)lbl_8036728D, (f32)(s8)lbl_8036728E, lbl_80368EF4);
    (void)t0;
    (void)OSGetTime();
}

#pragma use_lmw_stmw on
void fn_80042558(void *arg0) {
    void fn_8005FEE8(void *, f32);
    void MapObj_FadeOut(void *, s32);
    s32 Map_CollectLinkedObjs(void *, void *);
    void MapObj_Hide(void *, s32);
    extern u8 gMapObjEventList[];
    extern f32 lbl_80368F2C;
    u32 list[19];
    u8 *start = gMapObjEventList;
    u8 *rec;
    s32 foundCount = 0;
    s8 x;
    s8 y;
    s32 i;
    s32 k;
    u8 *ent;
    u8 *found;
    u32 flags;
    s32 count;

    rec = start;
    while (rec[2] != 0) {
        x = (s8) rec[0];
        y = (s8) rec[1];
        switch (rec[2] - 0x21) {
            case 0:
                found = NULL;
                count = M2C_FIELD(arg0, s16 *, 6);
                for (i = count - 1; i >= 0; i--) {
                    ent = M2C_FIELD(arg0, u8 **, 0x14) + i * 0xB4;
                    flags = M2C_FIELD(M2C_FIELD(ent, u8 **, 0x10), u32 *, 0xBC);
                    if (flags & 0x410) {
                        continue;
                    }
                    if ((flags & 0xA00) != 0xA00) {
                        continue;
                    }
                    if (x < (s8) M2C_FIELD(ent, u8 *, 4)) {
                        continue;
                    }
                    if (x > (s8) M2C_FIELD(ent, u8 *, 6)) {
                        continue;
                    }
                    if (y < (s8) M2C_FIELD(ent, u8 *, 5)) {
                        continue;
                    }
                    if (y > (s8) M2C_FIELD(ent, u8 *, 7)) {
                        continue;
                    }
                    found = ent;
                    break;
                }
                if (found == NULL) {
                    break;
                }
                fn_8005FEE8(found + 0x14, lbl_80368F2C);
                break;
            case 1:
                found = NULL;
                count = M2C_FIELD(arg0, s16 *, 6);
                for (i = count - 1; i >= 0; i--) {
                    ent = M2C_FIELD(arg0, u8 **, 0x14) + i * 0xB4;
                    flags = M2C_FIELD(M2C_FIELD(ent, u8 **, 0x10), u32 *, 0xBC);
                    if ((flags & 0x1000) == 0) {
                        continue;
                    }
                    if (x < (s8) M2C_FIELD(ent, u8 *, 4)) {
                        continue;
                    }
                    if (x > (s8) M2C_FIELD(ent, u8 *, 6)) {
                        continue;
                    }
                    if (y < (s8) M2C_FIELD(ent, u8 *, 5)) {
                        continue;
                    }
                    if (y > (s8) M2C_FIELD(ent, u8 *, 7)) {
                        continue;
                    }
                    found = ent;
                    break;
                }
                if (found == NULL) {
                    break;
                }
                MapObj_FadeOut(found, 0);
                break;
            case 2:
                found = NULL;
                count = M2C_FIELD(arg0, s16 *, 6);
                for (i = count - 1; i >= 0; i--) {
                    ent = M2C_FIELD(arg0, u8 **, 0x14) + i * 0xB4;
                    flags = M2C_FIELD(M2C_FIELD(ent, u8 **, 0x10), u32 *, 0xBC);
                    if ((flags & 0x800) == 0) {
                        continue;
                    }
                    if (x < (s8) M2C_FIELD(ent, u8 *, 4)) {
                        continue;
                    }
                    if (x > (s8) M2C_FIELD(ent, u8 *, 6)) {
                        continue;
                    }
                    if (y < (s8) M2C_FIELD(ent, u8 *, 5)) {
                        continue;
                    }
                    if (y > (s8) M2C_FIELD(ent, u8 *, 7)) {
                        continue;
                    }
                    found = ent;
                    break;
                }
                if (found == NULL) {
                    break;
                }
                Map_CollectLinkedObjs(arg0, list);
                break;
            case 3:
                found = NULL;
                count = M2C_FIELD(arg0, s16 *, 6);
                for (i = count - 1; i >= 0; i--) {
                    ent = M2C_FIELD(arg0, u8 **, 0x14) + i * 0xB4;
                    flags = M2C_FIELD(M2C_FIELD(ent, u8 **, 0x10), u32 *, 0xBC);
                    if (flags & 0x410) {
                        continue;
                    }
                    if ((flags & 0x800) == 0) {
                        continue;
                    }
                    if (x < (s8) M2C_FIELD(ent, u8 *, 4)) {
                        continue;
                    }
                    if (x > (s8) M2C_FIELD(ent, u8 *, 6)) {
                        continue;
                    }
                    if (y < (s8) M2C_FIELD(ent, u8 *, 5)) {
                        continue;
                    }
                    if (y > (s8) M2C_FIELD(ent, u8 *, 7)) {
                        continue;
                    }
                    found = ent;
                    break;
                }
                if (found == NULL) {
                    break;
                }
                count = Map_CollectLinkedObjs(arg0, list);
                for (k = 0; k < count; k++) {
                    MapObj_Hide((void *) list[k], 0);
                }
                break;
            case 4:
                break;
            case 5:
                found = NULL;
                count = M2C_FIELD(arg0, s16 *, 6);
                for (i = count - 1; i >= 0; i--) {
                    ent = M2C_FIELD(arg0, u8 **, 0x14) + i * 0xB4;
                    flags = M2C_FIELD(M2C_FIELD(ent, u8 **, 0x10), u32 *, 0xBC);
                    if (flags & 0x410) {
                        continue;
                    }
                    if ((flags & 0x200) == 0) {
                        continue;
                    }
                    if (x < (s8) M2C_FIELD(ent, u8 *, 4)) {
                        continue;
                    }
                    if (x > (s8) M2C_FIELD(ent, u8 *, 6)) {
                        continue;
                    }
                    if (y < (s8) M2C_FIELD(ent, u8 *, 5)) {
                        continue;
                    }
                    if (y > (s8) M2C_FIELD(ent, u8 *, 7)) {
                        continue;
                    }
                    found = ent;
                    break;
                }
                if (found == NULL) {
                    break;
                }
                fn_8005FEE8(found + 0x14, lbl_80368F2C);
                break;
            case 6:
                found = NULL;
                count = M2C_FIELD(arg0, s16 *, 6);
                for (i = count - 1; i >= 0; i--) {
                    ent = M2C_FIELD(arg0, u8 **, 0x14) + i * 0xB4;
                    flags = M2C_FIELD(M2C_FIELD(ent, u8 **, 0x10), u32 *, 0xBC);
                    if (flags & 0x410) {
                        continue;
                    }
                    if ((flags & 0xA00) != 0xA00) {
                        continue;
                    }
                    if (x < (s8) M2C_FIELD(ent, u8 *, 4)) {
                        continue;
                    }
                    if (x > (s8) M2C_FIELD(ent, u8 *, 6)) {
                        continue;
                    }
                    if (y < (s8) M2C_FIELD(ent, u8 *, 5)) {
                        continue;
                    }
                    if (y > (s8) M2C_FIELD(ent, u8 *, 7)) {
                        continue;
                    }
                    found = ent;
                    break;
                }
                if (found == NULL) {
                    break;
                }
                M2C_FIELD(found, u8 *, 2) |= 1;
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                break;
        }
        rec += 3;
    }
}
#pragma use_lmw_stmw reset

s32 fn_800431E4(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x1C);
}

extern f32 lbl_80368EE4;
void fn_800431EC(s32 unused, s32 arg1) {
    extern void *lbl_803672A8;
    extern f32 lbl_80368EE4;
    void *ptr = lbl_803672A8;

    fn_80222644(arg1, M2C_FIELD(ptr, s32 *, 0x1C), (s32)M2C_FIELD(ptr, f32 *, 0x10), (s32)M2C_FIELD(ptr, f32 *, 0x14), 4, 0, 0, 0);
    GXInitTexObjLOD(arg1, 0, 0, 0, 0, 0, lbl_80368EE4, lbl_80368EE4, lbl_80368EE4);
}

void Map_ClearDispCache(void) {
    void Process_UnlinkByKey(void *);
    void fn_800C4588(void *);
    void Heap_Free(void *);
    extern void *lbl_803672A8;
    extern u8 lbl_80285778[];

    if (lbl_803672A8 != NULL) {
        Process_UnlinkByKey(lbl_80285778);
        fn_800C4588(*(void **)((u8 *)lbl_803672A8 + 0x1C));
        *(void **)((u8 *)lbl_803672A8 + 0x1C) = NULL;
        Heap_Free(lbl_803672A8);
        lbl_803672A8 = NULL;
    }
}

#pragma global_optimizer off
void fn_800432D8(void *arg0) {
    void fn_80067708(s32, s32, void *, void *);
    void fn_80060060(void *);
    void fn_800609DC(void *);
    void fn_8006785C(s32, void *, void *);
    void fn_8006CAD4(void *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void fn_80043E88(void);
    void fn_80043DEC(void);
    void fn_800449C8(void);
    void fn_80048518(void);
    extern void *gMap;
    extern f64 lbl_80368EF8;
    extern f32 lbl_80368EE4;
    extern f32 lbl_80368EE8;
    extern f32 lbl_80368EEC;
    extern f32 lbl_80368EF0;
    extern f32 lbl_80368EF4;

    u8 sp158[0x30];
    u8 sp128[0x30];
    u8 spF8[0x30];
    u8 spC8[0x30];
    u8 sp98[0x30];
    u8 sp68[0x30];
    u8 sp38[0x30];
    u8 sp8[0x30];
    u32 mask;
    u8 *ent;
    s32 i;
    u8 *sub;
    void *self;
    u8 flags;
    f32 f31v, f30v, f29v, f28v;
    f32 t30;
    s32 a, b;
    f32 scale;
    f32 temp_f0;
    s16 h;

    self = arg0;
    fn_80067708(0, 1, fn_80043E88, self);
    if (*(u32 *)((u8 *)self + 0xC) != 0) {
        s32 n;
        u8 *e;
        e = *(u8 **)((u8 *)self + 0x14);
        n = 0;
        goto clear_test;
    clear_body:
        {
            u8 f;
            f = e[2];
            n += 1;
            e[2] = f & 0x7F;
            e += 0xB4;
        }
    clear_test:
        if (n < *(s16 *)((u8 *)self + 6)) {
            goto clear_body;
        }
    }
    if ((*(u32 *)((u8 *)self + 0x64) & 0x80000000) == 0 && (*(u32 *)((u8 *)self + 0x64) & 0x40000000) != 0) {
        ent = *(u8 **)((u8 *)self + 0x14);
        i = 0;
        goto loop1_test;
    loop1_body:
        sub = ent + 0x14;
        flags = ent[2];
        mask = *(u32 *)(*(u8 **)(ent + 0x10) + 0xBC);
        if ((mask & 1) == 0 && (flags & 1) == 0) {
            if ((mask & 0x400) != 0) {
                fn_80060060(sub);
            }
            if ((flags & 0x80) == 0) {
                if ((mask & 0x80) != 0) {
                    f28v = (f32)(s8)ent[0] + lbl_80368EE4;
                    f29v = -(*(f32 *)(ent + 0xC) + *(f32 *)(*(u8 **)((u8 *)gMap + 0x30) + 0x48));
                    t30 = (f32)(s8)ent[1];
                    f31v = *(f32 *)(ent + 8) + lbl_80368EE4;
                    f30v = t30 + lbl_80368EE4;
                    if (*(u8 *)((u8 *)self + 0x68) == 1) {
                        a = *(s16 *)self;
                        h = *(s16 *)((u8 *)self + 2);
                        a = ((u32)a >> 31) + a;
                        a >>= 1;
                        f28v -= (f32)a;
                        f30v -= (f32)((s32)(((u32)h >> 31) + h) >> 1);
                    }
                    PSMTXTrans(sp158, lbl_80368EE8, lbl_80368EE4, lbl_80368EE8);
                    PSMTXRotRad(sp128, 0x59, lbl_80368EEC * f31v);
                    PSMTXConcat(sp128, sp158, sp128);
                    PSMTXTrans(sp158, lbl_80368EF0, lbl_80368EE4, lbl_80368EF0);
                    PSMTXConcat(sp158, sp128, spC8);
                    scale = *(f32 *)((u8 *)self + 0x6C);
                    PSMTXScale(spF8, scale, scale, scale);
                    PSMTXConcat(spF8, spC8, spC8);
                    temp_f0 = *(f32 *)((u8 *)self + 0x6C);
                    PSMTXTrans(sp158, lbl_80368EF4 * (f28v * temp_f0), lbl_80368EF4 * (f29v * temp_f0), lbl_80368EF4 * (f30v * temp_f0));
                    PSMTXConcat(sp158, spC8, spC8);
                    PSMTXConcat((u8 *)self + 0x70, spC8, ent + 0x24);
                }
                if ((mask & 0x10000) != 0) {
                    fn_8006785C(2, fn_80048518, ent);
                }
                fn_800609DC(sub);
                fn_8006CAD4(sub);
            }
        }
        i += 1;
        ent += 0xB4;
    loop1_test:
        if (i < *(s16 *)((u8 *)self + 6)) {
            goto loop1_body;
        }
    }
    if (*(u32 *)((u8 *)self + 0xC) != 0 && (*(u32 *)((u8 *)self + 0x64) & 0x80000000) == 0) {
        fn_8006785C(2, fn_800449C8, self);
    }
    if ((*(u32 *)((u8 *)self + 0x64) & 0x80000000) == 0 && (*(u32 *)((u8 *)self + 0x64) & 0x40000000) != 0) {
        u32 m;
        s32 n;
        ent = *(u8 **)((u8 *)self + 0x14);
        n = 0;
        goto loop2_test;
    loop2_body:
        sub = ent + 0x14;
        flags = ent[2];
        m = *(u32 *)(*(u8 **)(ent + 0x10) + 0xBC);
        if ((u32)(m & 1) == 1 && (flags & 1) == 0) {
            if ((m & 0x400) != 0) {
                fn_80060060(sub);
            }
            if ((flags & 0x80) == 0) {
                if ((m & 0x80) != 0) {
                    f31v = (f32)(s8)ent[0] + lbl_80368EE4;
                    f30v = -(*(f32 *)(ent + 0xC) + *(f32 *)(*(u8 **)((u8 *)gMap + 0x30) + 0x48));
                    t30 = (f32)(s8)ent[1];
                    f28v = *(f32 *)(ent + 8) + lbl_80368EE4;
                    f29v = t30 + lbl_80368EE4;
                    if (*(u8 *)((u8 *)self + 0x68) == 1) {
                        a = *(s16 *)self;
                        h = *(s16 *)((u8 *)self + 2);
                        a = ((u32)a >> 31) + a;
                        a >>= 1;
                        f31v -= (f32)a;
                        f29v -= (f32)((s32)(((u32)h >> 31) + h) >> 1);
                    }
                    PSMTXTrans(sp98, lbl_80368EE8, lbl_80368EE4, lbl_80368EE8);
                    PSMTXRotRad(sp68, 0x59, lbl_80368EEC * f28v);
                    PSMTXConcat(sp68, sp98, sp68);
                    PSMTXTrans(sp98, lbl_80368EF0, lbl_80368EE4, lbl_80368EF0);
                    PSMTXConcat(sp98, sp68, sp8);
                    scale = *(f32 *)((u8 *)self + 0x6C);
                    PSMTXScale(sp38, scale, scale, scale);
                    PSMTXConcat(sp38, sp8, sp8);
                    temp_f0 = *(f32 *)((u8 *)self + 0x6C);
                    PSMTXTrans(sp98, lbl_80368EF4 * (f31v * temp_f0), lbl_80368EF4 * (f30v * temp_f0), lbl_80368EF4 * (f29v * temp_f0));
                    PSMTXConcat(sp98, sp8, sp8);
                    PSMTXConcat((u8 *)self + 0x70, sp8, ent + 0x24);
                }
                if ((m & 0x10000) != 0) {
                    fn_8006785C(2, fn_80048518, ent);
                }
                fn_800609DC(sub);
                fn_8006CAD4(sub);
            }
        }
        n += 1;
        ent += 0xB4;
    loop2_test:
        if (n < *(s16 *)((u8 *)self + 6)) {
            goto loop2_body;
        }
    }
    fn_80067708(2, 3, fn_80043DEC, self);
}

void fn_80043838(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6)
{
    extern void *lbl_803672A8;
    extern u8 lbl_8026A660[];
    extern u8 lbl_80285778[];
    extern f32 lbl_80368F30;

    void *Heap_Alloc(s32);
    u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
    void *fn_800C45B8(s32, void *, s32);
    void DCInvalidateRange(void *, u32);
    void fn_800432D8(void *);
    void *Process_CreateChild(void *, void *);

    u8 *work;
    void *buffer;
    u32 size;
    f32 width;
    f32 height;
    f32 scale;
    f32 limit;

    work = (u8 *)Heap_Alloc(0x20);
    lbl_803672A8 = work;

    *(f32 *)(work + 0x00) = arg2;
    *(f32 *)(work + 0x04) = arg3;
    *(f32 *)(work + 0x10) = arg5;
    *(f32 *)(work + 0x14) = arg6;

    scale = arg4 * arg6 / arg5;

    if (scale < arg4) {
        scale = arg4;
    }

    if (scale > lbl_80368F30) {
        scale = lbl_80368F30;
    }

    work = (u8 *)lbl_803672A8;
    *(f32 *)(work + 0x08) = scale;
    *(f32 *)(work + 0x0C) = scale;

    if (arg5 > arg6) {
        *(f32 *)(work + 0x08) =
            *(f32 *)(work + 0x08) * (arg5 / arg6);
    } else {
        *(f32 *)(work + 0x0C) =
            *(f32 *)(work + 0x0C) * (arg6 / arg5);
    }

    width = arg5;
    height = arg6;

    size = GXGetTexBufferSize(
        (s32)width,
        (s32)height,
        4,
        0,
        0
    );

    buffer = fn_800C45B8(
        -(s32)size,
        lbl_8026A660 + 0x245,
        0
    );

    work = (u8 *)lbl_803672A8;
    *(void **)(work + 0x1C) = buffer;

    work = (u8 *)lbl_803672A8;
    DCInvalidateRange(*(void **)(work + 0x1C), size);

    if (arg1 == 0) {
        fn_800432D8(arg0);
    } else {
        Process_CreateChild(lbl_80285778, arg1);
    }
}

void fn_80043A00(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK fn_80043838(s32, f32, f32, f32, f32, f32, f32);
    extern f32 lbl_80368F00;
    s16 temp_r11;
    s16 temp_r12;
    s32 temp_r8;

    temp_r12 = M2C_FIELD(arg0, s16 *, 0);
    temp_r11 = M2C_FIELD(arg0, s16 *, 2);
    temp_r8 = M2C_FIELD(arg0, u8 *, 0x61) * 2;
    fn_80043838(arg3, (f32) temp_r12 * lbl_80368F00, (f32) temp_r11 * lbl_80368F00, (f32) (temp_r12 - temp_r8), (f32) (temp_r11 - temp_r8), (f32) arg1, (f32) arg2);
}

void fn_80043AC8(void *arg0) {
    M2C_UNK fn_80068550(s32);
    M2C_UNK fn_800C4588(void *);
    extern s32 gGameFlags;
    void *temp_r31;

    fn_80068550(M2C_FIELD(arg0, s32 *, 0x54));
    temp_r31 = M2C_FIELD(arg0, void **, 0x58);
    fn_800C4588(M2C_FIELD(temp_r31, void **, 0x114));
    M2C_FIELD(temp_r31, void **, 0x114) = NULL;
    fn_800C4588(temp_r31);
    gGameFlags &= 0xFFFFFFF7;
}

void fn_80043B20(void) {
    extern void *gMap;
    extern void fn_800432D8(void *);

    fn_800432D8(gMap);
}

void fn_80043B44(void *arg0) {
void *Camera_Get(void);
void *fn_800C45B8(s32,void *,s32);
void fn_80068550(void);
void fn_800680AC(s32,s32,s32,s32);
void fn_80068070(f32,f32,f32,f32);
void fn_8006805C(f32,f32);
void fn_80202A6C(void *,f32,f32,f32,f32);
void fn_800680D0(void *,s32);
void fn_80067FE8(void *,void *,void *);
void fn_80066124(void *);
extern u8 gMapTileEdgeVecs[],lbl_8026A660[];
extern u32 gGameFlags;
extern f32 lbl_80368EE4,lbl_80368F34,lbl_80368F38,lbl_80368F10,lbl_80368F3C,lbl_80368F40,lbl_80368F44,lbl_80368F48;
f32 matrix[16]; f32 a[3]; f32 b[3]; f32 c[3];
u8 *cam; u8 *table=gMapTileEdgeVecs;
M2C_FIELD(arg0,void **,0x54)=Camera_Get();
cam=fn_800C45B8(-400,lbl_8026A660+0x245,0);
fn_80068550(); *(u16 *)cam=2;
fn_800680AC(0,0,608,448);
fn_80068070(lbl_80368EE4,lbl_80368EE4,lbl_80368F34,lbl_80368F38);
fn_8006805C(lbl_80368F10,lbl_80368F3C);
fn_80202A6C(matrix,lbl_80368F40,*(f32 *)(cam+12)/ *(f32 *)(cam+16),*(f32 *)(cam+0x180),*(f32 *)(cam+0x184));
fn_800680D0(matrix,1);
*(u32 *)&a[0]=*(u32 *)(table+172);
*(u32 *)&a[1]=*(u32 *)(table+176);
*(u32 *)&a[2]=*(u32 *)(table+180);
*(f32 *)(cam+212)=a[0];
*(f32 *)(cam+216)=a[1];
*(f32 *)(cam+220)=a[2];
*(u32 *)&b[0]=*(u32 *)(table+184);
*(u32 *)&b[1]=*(u32 *)(table+188);
*(u32 *)&b[2]=*(u32 *)(table+192);
*(f32 *)(cam+224)=b[0];
*(f32 *)(cam+228)=b[1];
*(f32 *)(cam+232)=b[2];
*(u32 *)&c[0]=*(u32 *)(table+196);
*(u32 *)&c[1]=*(u32 *)(table+200);
*(u32 *)&c[2]=*(u32 *)(table+204);
*(f32 *)(cam+236)=c[0];
*(f32 *)(cam+240)=c[1];
*(f32 *)(cam+244)=c[2];
*(f32 *)(cam+0xF8)=80.0f;
*(f32 *)(cam+0xFC)=0.0f;
*(f32 *)(cam+0x100)=0.0f;
*(f32 *)(cam+0x104)=0.0f;
*(f32 *)(cam+0x18C)=30.0f;
*(f32 *)(cam+0x188)=1.3333333333333333f;
fn_80067FE8(cam+0xD4,cam+0xEC,cam+0xE0);
*(void **)(cam+0x114)=fn_800C45B8(-0x4000,lbl_8026A660+0x245,0);
*(u16 *)(cam+0x11A)=0x400;
fn_80066124(cam);
M2C_FIELD(arg0,void **,0x58)=cam;
gGameFlags|=8;
}

s32 fn_80043D18(s32 unused, s32 x, s32 y, f32 *out) {
    extern void *lbl_803672A8;
    extern f64 lbl_80368EF8;
    extern f32 lbl_80368F00;
    extern f32 lbl_80368EE4;
    f32 *p;
    f32 hi;
    f32 p2;
    f32 scale;
    f32 half;
    f32 p0;
    f32 fx;
    f32 fy;
    f32 t;
    f32 p3;
    f32 p1;
    f32 zero;
    f32 a;
    f32 b;

    p = lbl_803672A8;
    hi = p[4];
    p2 = p[2];
    scale = hi / p2;
    half = lbl_80368F00;
    p0 = p[0];
    fx = (f32)x;
    t = p0 - p2 * half;
    p3 = p[3];
    fy = (f32)y;
    a = (half + fx) - t;
    p1 = p[1];
    zero = lbl_80368EE4;
    t = p1 - p3 * half;
    b = (half + fy) - t;
    out[0] = scale * a;
    out[1] = scale * b;
    out[2] = zero;
    if (out[0] < zero || out[1] < zero || out[0] > hi || out[1] > hi) {
        return 0;
    }
    return 1;
}

f32 fn_80043DD8(void) {
    extern void *lbl_803672A8;
    return M2C_FIELD(lbl_803672A8, f32 *, 0x10) / M2C_FIELD(lbl_803672A8, f32 *, 8);
}

void fn_80043DEC(void) {
    M2C_UNK fn_802209FC();
    M2C_UNK fn_8022124C(s32, s32, u16, u16);
    M2C_UNK fn_802212FC(u16, u16, s32, s32);
    M2C_UNK GXCopyTex(s32, s32);
    M2C_UNK fn_80222EB4();
    M2C_UNK fn_80067984(s32);
    M2C_UNK fn_80067058();
    extern void *lbl_803672A8;
    s32 temp_r31;
    s32 temp_r30;

    temp_r31 = (s32)*(f32 *)((char *)lbl_803672A8 + 0x10);
    temp_r30 = (s32)*(f32 *)((char *)lbl_803672A8 + 0x14);
    fn_8022124C(0, 0, (u16)temp_r31, (u16)temp_r30);
    fn_802212FC((u16)temp_r31, (u16)temp_r30, 4, 0);
    GXCopyTex(*(s32 *)((char *)lbl_803672A8 + 0x1C), 1);
    fn_802209FC();
    fn_80222EB4();
    fn_80067984(0);
    fn_80067058();
}

void fn_80043E88(void) {
 void *Camera_Get(void);
 void fn_80068070(f32,f32,f32,f32);
 void fn_800680AC(s32,s32,s32,s32);
 void fn_80067C48(s32,f32,f32);
 void fn_80067058(void);
 f32 x,y,w,h,a,b;
 f32 *p=lbl_803672A8;
 x=p[0]; y=p[1]; w=p[4]; h=p[5]; a=p[2]; b=p[3];
 p=Camera_Get();
 p[0x38]=x; p[0x39]=y;
 p[0x3A]=0.0f; p[0x3B]=0.0f;
 p[0x3C]=-1.0f; p[0x3D]=0.0f;
 p[0x35]=x; p[0x36]=y; p[0x37]=-30.0f;
 fn_80068070(0.0f,0.0f,w,h);
 fn_800680AC(0,0,(s32)w,(s32)h);
 fn_80067C48(0,a,b);
 fn_80067058();
}

#pragma global_optimizer off
/* Build a terrain-aligned 3x4 basis matrix from map tile corner heights at (x, y). */
void Map_BuildSlopeMatrix(void *cam, f32 *mtx, f32 x, f32 y) {
    f32 Map_GetTileCornerHeight(void *, s32, s32, s32);
    void fn_80203290(f32 *, f32 *, f32 *);
    void fn_802031E8(f32 *, f32 *);
    extern u8 gBattleMap[];
    extern u8 gMapTileEdgeVecs[];
    extern f32 lbl_80368F10;
    extern f32 lbl_80368F00;
    extern f32 lbl_80368EE4;
    f32 xAxis[3];
    f32 binormal[3];
    f32 normal[3];
    f32 unit[3];
    f32 nTri0[3];
    f32 nTri1[3];
    f32 edge0b[3];
    f32 edge0a[3];
    f32 edge0bTmp[3];
    f32 edge0aTmp[3];
    f32 edge1b[3];
    f32 edge1a[3];
    f32 edge1bTmp[3];
    f32 edge1aTmp[3];
    u8 *tbl;
    s32 ix;
    s32 iy;
    f32 base;
    f32 t;
    f32 tmp;
    f32 zero;
    f32 one;

    tbl = gMapTileEdgeVecs;
    ix = (s32)x;
    iy = (s32)y;
    base = Map_GetTileCornerHeight(gBattleMap, ix, iy, 0);

    *(u32 *)&edge0a[0] = *(u32 *)(tbl + 0x94);
    *(u32 *)&edge0a[1] = *(u32 *)(tbl + 0x98);
    *(u32 *)&edge0a[2] = *(u32 *)(tbl + 0x9C);
    tmp = Map_GetTileCornerHeight(gBattleMap, ix, iy, 1) - base;
    {
        u32 t2;
        u32 tz;
        u32 t1;
        u32 t0;
        t0 = *(u32 *)&edge0a[0];
        t1 = *(u32 *)&edge0a[1];
        t2 = *(u32 *)(tbl + 0xA0);
        edge0a[2] = tmp;
        *(u32 *)&edge0aTmp[0] = t0;
        *(u32 *)&edge0aTmp[1] = t1;
        tz = *(u32 *)&edge0a[2];
        *(u32 *)&edge0aTmp[2] = tz;
        *(u32 *)&edge0b[0] = t2;
        *(u32 *)&edge0b[1] = *(u32 *)(tbl + 0xA4);
        *(u32 *)&edge0b[2] = *(u32 *)(tbl + 0xA8);
    }
    tmp = Map_GetTileCornerHeight(gBattleMap, ix, iy, 2) - base;
    *(u32 *)&edge0bTmp[0] = *(u32 *)&edge0b[0];
    *(u32 *)&edge0bTmp[1] = *(u32 *)&edge0b[1];
    edge0b[2] = tmp;
    *(u32 *)&edge0bTmp[2] = *(u32 *)&edge0b[2];
    fn_80203290(edge0aTmp, edge0bTmp, nTri0);

    base = Map_GetTileCornerHeight(gBattleMap, ix, iy, 3);

    *(u32 *)&edge1a[0] = *(u32 *)(tbl + 0x7C);
    *(u32 *)&edge1a[1] = *(u32 *)(tbl + 0x80);
    *(u32 *)&edge1a[2] = *(u32 *)(tbl + 0x84);
    tmp = Map_GetTileCornerHeight(gBattleMap, ix, iy, 2) - base;
    {
        u32 t2;
        u32 tz;
        u32 t1;
        u32 t0;
        t0 = *(u32 *)&edge1a[0];
        t1 = *(u32 *)&edge1a[1];
        t2 = *(u32 *)(tbl + 0x88);
        edge1a[2] = tmp;
        *(u32 *)&edge1aTmp[0] = t0;
        *(u32 *)&edge1aTmp[1] = t1;
        tz = *(u32 *)&edge1a[2];
        *(u32 *)&edge1aTmp[2] = tz;
        *(u32 *)&edge1b[0] = t2;
        *(u32 *)&edge1b[1] = *(u32 *)(tbl + 0x8C);
        *(u32 *)&edge1b[2] = *(u32 *)(tbl + 0x90);
    }
    tmp = Map_GetTileCornerHeight(gBattleMap, ix, iy, 1) - base;
    *(u32 *)&edge1bTmp[0] = *(u32 *)&edge1b[0];
    *(u32 *)&edge1bTmp[1] = *(u32 *)&edge1b[1];
    edge1b[2] = tmp;
    *(u32 *)&edge1bTmp[2] = *(u32 *)&edge1b[2];
    fn_80203290(edge1aTmp, edge1bTmp, nTri1);

    t = (y + (x - (f32)(s8)ix)) - (f32)(s8)iy;
    if (lbl_80368F10 == t) {
        normal[0] = lbl_80368F00 * (nTri0[0] + nTri1[0]);
        normal[1] = lbl_80368F00 * (nTri0[1] + nTri1[1]);
        normal[2] = lbl_80368F00 * (nTri0[2] + nTri1[2]);
    } else if (t > lbl_80368F10) {
        normal[0] = nTri1[0];
        normal[1] = nTri1[1];
        normal[2] = nTri1[2];
    } else {
        normal[0] = nTri0[0];
        normal[1] = nTri0[1];
        normal[2] = nTri0[2];
    }

    zero = lbl_80368EE4;
    one = lbl_80368F10;
    xAxis[1] = zero;
    xAxis[0] = one;
    xAxis[2] = zero;
    fn_80203290(normal, xAxis, binormal);
    fn_80203290(binormal, normal, xAxis);

    fn_802031E8(xAxis, unit);
    mtx[0] = unit[0];
    mtx[4] = unit[1];
    mtx[8] = unit[2];

    fn_802031E8(binormal, unit);
    mtx[1] = unit[0];
    mtx[5] = unit[1];
    mtx[9] = unit[2];

    fn_802031E8(normal, unit);
    {
        f32 z;
        t = unit[0];
        z = lbl_80368EE4;
        mtx[2] = t;
        t = unit[1];
        mtx[6] = t;
        t = unit[2];
        mtx[10] = t;
        mtx[11] = z;
        mtx[7] = z;
        mtx[3] = z;
    }
}

u8 fn_8004434C(void *arg0, s32 x, s32 y) {
    u8 *map;
    u8 *entry;
    u32 flags;
    u32 type;
    s32 count;

    map = (u8 *)arg0;

    if ((*(u32 *)(map + 0x64) & 0x10000000U) == 0) {
        return 0;
    }

    count = *(s16 *)(map + 6);
    entry = *(u8 **)(map + 0x14);

    while (count > 0) {
        flags = *(u32 *)(*(u8 **)(entry + 0x10) + 0xBC);

        if ((flags & 0x10) == 0 &&
            (flags & 0x1800) != 0) {

            if ((flags & 0x100000) == 0 &&
                (entry[2] & 3) == 0) {

                if (x >= (s8)entry[4] &&
                    x <= (s8)entry[6] &&
                    y >= (s8)entry[5] &&
                    y <= (s8)entry[7]) {
                    return 1;
                }
            }
        }

        entry += 0xB4;
        count--;
    }

    return 0;
}

#pragma global_optimizer off
void fn_80044450(void *arg0, s32 arg1) {
void *Hash_Lookup(void *);
u32 Res_GetByName(void *);
void fn_80015DEC(void);
void fn_80023A4C(void *);
void fn_80023B80(void *);
void fn_80045604(void *);
u8 fn_8005B7A4(void *);
extern u8 lbl_8026A660[];
extern u8 gBattleMap[];

    void *tblA;
    u16 *idxA;
    void *tblB;
    u16 *idxB;
    u8 *ca;
    s32 rowSl;
    u8 *rowPtr;
    u8 *tileA;
    u8 *tileB;
    s32 t;
    s32 c;
    s32 off;
    u8 ok;
    s16 v;
    u8 *p;
    s32 q;
    s32 sh;
    s32 q1;
    u16 ia;
    u16 ib;
    void *node;
    s32 i;
    u32 flags;
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 lim;
    s32 yy;
    s32 xx;
    u16 *src;
    u8 *tile;
    s32 row;
    s32 col;

    tblA = Hash_Lookup(lbl_8026A660 + 0x289);
    idxA = Hash_Lookup(lbl_8026A660 + 0x295);
    tblB = tblA;
    idxB = idxA;
    if (Res_GetByName(lbl_8026A660 + 0x2A0) != 0) {
        tblB = Hash_Lookup(lbl_8026A660 + 0x2A0);
        idxB = Hash_Lookup(lbl_8026A660 + 0x2B0);
    }
    ca = gBattleMap;
    for (row = 0; row < *(s16 *)((u8 *)arg0 + 2); row++) {
        rowSl = (s8)row << 6;
        rowPtr = ca + rowSl;
        for (col = 0; col < *(s16 *)((u8 *)arg0 + 0); ) {
            ia = *idxA;
            idxA += 1;
            ib = *idxB;
            idxB += 1;
            tileA = (u8 *)tblA + ia * 0xC;
            tileB = (u8 *)tblB + ib * 0xC;
            ok = fn_8005B7A4(*(void **)(tileA + 8));
            c = (s8)col;
            col += 1;
            off = c + 0x100D;
            rowPtr[off] = ok;
            t = c + rowSl;
            sh = t << 3;
            q = t << 2;
            v = *(s16 *)tileA;
            q1 = q + 1;
            p = ca + sh;
            *(s16 *)(p + 0x142D4) = v;
            v = *(s16 *)tileB;
            *(s16 *)(p + 0x1C2D8) = v;
            p = ca + (q1 << 1);
            v = *(s16 *)(tileA + 2);
            q1 = q + 2;
            *(s16 *)(p + 0x142D4) = v;
            v = *(s16 *)(tileB + 2);
            *(s16 *)(p + 0x1C2D8) = v;
            p = ca + (q1 << 1);
            v = *(s16 *)(tileA + 4);
            q1 = q + 3;
            *(s16 *)(p + 0x142D4) = v;
            v = *(s16 *)(tileB + 4);
            *(s16 *)(p + 0x1C2D8) = v;
            p = ca + (q1 << 1);
            v = *(s16 *)(tileA + 6);
            *(s16 *)(p + 0x142D4) = v;
            v = *(s16 *)(tileB + 6);
            *(s16 *)(p + 0x1C2D8) = v;
        }
    }
    if (*(u32 *)((u8 *)arg0 + 0x64) & 0x10000000) {
        node = *(void **)((u8 *)arg0 + 0x14);
        for (i = 0; i < *(s16 *)((u8 *)arg0 + 6); i++, node = (u8 *)node + 0xB4) {
            flags = *(u32 *)(*(u8 **)((u8 *)node + 0x10) + 0xBC);
            if (flags & 0x10) {
                ok = 0;
            } else if (flags & 0x800) {
                ok = 1;
            } else if (flags & 0x1000) {
                ok = 1;
            } else {
                ok = 0;
            }
            if ((u8)ok == 0) {
                continue;
            }
            ok = (u8)((*(u8 *)((u8 *)node + 2) & 3) == 0);
            if (ok == 0) {
                continue;
            }
            x0 = *(s8 *)((u8 *)node + 4);
            y0 = *(s8 *)((u8 *)node + 5);
            x1 = *(s8 *)((u8 *)node + 6);
            y1 = *(s8 *)((u8 *)node + 7);
            if (x0 < 0) {
                x0 = 0;
            }
            if (y0 < 0) {
                y0 = 0;
            }
            lim = *(s16 *)((u8 *)arg0 + 0) - 1;
            if (x1 >= lim) {
                x1 = lim;
            }
            lim = *(s16 *)((u8 *)arg0 + 2) - 1;
            if (y1 >= lim) {
                y1 = lim;
            }
            if (flags & 2) {
                if (Res_GetByName(lbl_8026A660 + 0x26A) == 0) {
                    continue;
                }
                tblA = Hash_Lookup(lbl_8026A660 + 0x26A);
                idxA = Hash_Lookup(lbl_8026A660 + 0x27A);
                ca = gBattleMap;
                for (yy = y0; yy <= y1; yy++) {
                    rowSl = (s8)yy << 6;
                    rowPtr = ca + rowSl;
                    xx = x0;
                    src = idxA + (x0 + yy * *(s16 *)((u8 *)arg0 + 0));
                    for (; xx <= x1; ) {
                        ia = *src;
                        src += 1;
                        tile = (u8 *)tblA + ia * 0xC;
                        ok = fn_8005B7A4(*(void **)(tile + 8));
                        c = (s8)xx;
                        xx += 1;
                        off = c + 0x100D;
                        rowPtr[off] = ok;
                        t = c + rowSl;
                        q = t << 2;
                        sh = t << 3;
                        v = *(s16 *)tile;
                        q1 = q + 1;
                        p = ca + sh;
                        *(s16 *)(p + 0x142D4) = v;
                        *(s16 *)(p + 0x1C2D8) = v;
                        p = ca + (q1 << 1);
                        v = *(s16 *)(tile + 2);
                        q1 = q + 2;
                        *(s16 *)(p + 0x142D4) = v;
                        *(s16 *)(p + 0x1C2D8) = v;
                        p = ca + (q1 << 1);
                        v = *(s16 *)(tile + 4);
                        q1 = q + 3;
                        *(s16 *)(p + 0x142D4) = v;
                        *(s16 *)(p + 0x1C2D8) = v;
                        p = ca + (q1 << 1);
                        v = *(s16 *)(tile + 6);
                        *(s16 *)(p + 0x142D4) = v;
                        *(s16 *)(p + 0x1C2D8) = v;
                    }
                }
            } else {
                if (Res_GetByName(lbl_8026A660 + 0x26A) == 0) {
                    continue;
                }
                tblA = Hash_Lookup(lbl_8026A660 + 0x26A);
                idxA = Hash_Lookup(lbl_8026A660 + 0x27A);
                ca = gBattleMap;
                for (yy = y0; yy <= y1; yy++) {
                    rowSl = (s8)yy << 6;
                    rowPtr = ca + rowSl;
                    xx = x0;
                    src = idxA + (x0 + yy * *(s16 *)((u8 *)arg0 + 0));
                    for (; xx <= x1; ) {
                        ia = *src;
                        src += 1;
                        tile = (u8 *)tblA + ia * 0xC;
                        ok = fn_8005B7A4(*(void **)(tile + 8));
                        c = (s8)xx;
                        xx += 1;
                        off = c + 0x100D;
                        rowPtr[off] = ok;
                        t = c + rowSl;
                        sh = t << 3;
                        p = ca + sh;
                        *(s16 *)(p + 0x142D4) = *(s16 *)tile;
                        q = t << 2;
                        q1 = q + 1;
                        p = ca + (q1 << 1);
                        *(s16 *)(p + 0x142D4) = *(s16 *)(tile + 2);
                        q1 = q + 2;
                        p = ca + (q1 << 1);
                        *(s16 *)(p + 0x142D4) = *(s16 *)(tile + 4);
                        q1 = q + 3;
                        p = ca + (q1 << 1);
                        *(s16 *)(p + 0x142D4) = *(s16 *)(tile + 6);
                    }
                }
            }
        }
    }
    fn_80023B80(gBattleMap);
    fn_80045604(arg0);
    fn_80023A4C(gBattleMap);
    if ((u8)arg1 != 0) {
        fn_80015DEC();
        *(u32 *)((u8 *)arg0 + 0x64) |= 1;
    }
}
#pragma global_optimizer on

void Map_ReloadTileFlags(void *arg0, u8 arg1) {
    void fn_80023A4C(void *);
    void fn_80023B80(void *);
    void fn_80045604(void *);
    extern u8 gBattleMap[];

    fn_80023B80(gBattleMap);
    fn_80045604(arg0);
    if (arg1 != 0) {
        fn_80023A4C(gBattleMap);
    }
}

void fn_800449C8(void *arg0) {
void fn_80044BE4(void *);
void fn_80069C7C(void);
s32 GMaterial_AllocTevStage(void);
void PSMTXTrans(void *,f32,f32,f32);
void *Camera_GetViewMtx(void);
void PSMTXConcat(void *,void *,void *);
void GXLoadPosMtxImm(void *,s32);
void GXSetCurrentMtx(s32);
void fn_80202238(void *,void *);
void fn_80224DCC(void *,s32);
void fn_80220F44(s32,s32);
void GXSetCullMode(s32);
void GXSetChanMatColor(s32,void *);
void fn_80222164(s32,void *);
void GXSetBlendMode(s32,s32,s32,s32,s32,s32,s32);
void GXSetTevOrder(s32,s32,s32,s32);
void GXSetNumTexGens(s32,s32);
void GXClearVtxDesc(void);
void GXSetVtxDesc(s32,s32);
void GXSetVtxAttrFmt(s32,s32,s32,s32,s32);
void fn_802245D8(s32,s32,s32,s32);
void fn_802246B8(s32);
void fn_80223E5C(s32,s32,s32,s32,s32);
void GXSetZMode(s32,s32,s32);
void fn_800C15A8(void);
s32 fn_80069E74(void);
void GXSetNumTevStages(s32);
s32 fn_80069DB4(void);
void GXSetNumChans(s32);
void fn_80224A68(s32,s32);
void fn_80066D00(s32);
extern u8 gBattleState[],gMapBlendMode;
extern f32 lbl_80368EE4,lbl_80368F54;
extern u32 lbl_80368EE0;
f32 matrix[3][4];
u32 color,mat,amb;
s32 stage;
u8 enabled;
u8 mode;
if(M2C_FIELD(arg0,u32 *,0x64)&1){
M2C_FIELD(arg0,u32 *,0x64)&=~1;
fn_80044BE4(arg0);
}
color=M2C_FIELD(arg0,u32 *,0xa0);
((u8 *)&color)[3]=gBattleState[0xa0]*255/100;
fn_80069C7C();
stage=GMaterial_AllocTevStage();
PSMTXTrans(matrix,lbl_80368EE4,lbl_80368EE4,lbl_80368F54);
PSMTXConcat(Camera_GetViewMtx(),matrix,matrix);
GXLoadPosMtxImm(matrix,0);
GXSetCurrentMtx(0);
fn_80202238(matrix,matrix);
fn_80224DCC(matrix,0);
fn_80220F44(6,0);
GXSetCullMode(1);
mat=color;
GXSetChanMatColor(4,&mat);
amb=lbl_80368EE0;
fn_80222164(4,&amb);
GXSetBlendMode(4,0,0,0,0,0,2);
GXSetTevOrder(stage,255,255,4);
GXSetNumTexGens(stage,4);
GXClearVtxDesc();
GXSetVtxDesc(9,1);
GXSetVtxAttrFmt(0,9,1,4,0);
fn_802245D8(1,4,5,0);
fn_802246B8(1);
fn_80223E5C(0,0,1,7,0);
GXSetZMode(1,3,0);
mode=gMapBlendMode-1;
enabled=1;
if(!(mode<=1U)) enabled=0;
if(enabled) fn_800C15A8();
GXSetNumTevStages(fn_80069E74());
GXSetNumChans(fn_80069DB4());
fn_80224A68(M2C_FIELD(arg0,s32 *,0xa4),M2C_FIELD(arg0,s32 *,0xa8));
fn_80066D00(-1);
}

void fn_80044BE4(void *arg0) {
    f32 Map_GetTileCornerHeight(void *, s32, s32, s32);
    void *fn_800C45B8(s32, void *, s32);
    void fn_800C4588(void *);
    void *fn_800C4638(s32, void *, s32);
    void DCInvalidateRange(void *, u32);
    void DCFlushRange(void *, u32);
    void *fn_802248D8(void *, u32);
    s32 fn_802249A4(void *);
    void GXBegin(s32, s32, s32);
    void DebugPrint(void *, s32);
    void *memcpy(void *, void *, s32);
    extern u8 lbl_8026A660[];
    extern u8 gBattleMap[];
    extern f32 lbl_80368F58;
    volatile f32 *wgpipe;
    void *buf;
    void *disp;
    u8 *row;
    u8 *cell;
    u8 *above;
    u8 *base;
    s32 margin;
    s32 y;
    s32 x;
    s32 tile;
    f32 dx;
    f32 dy;
    f32 a;
    s32 size;
    void *out;
    s32 do_edge;

    margin = M2C_FIELD(arg0, u8 *, 0x61);
    buf = fn_800C45B8(-0x4000, lbl_8026A660 + 0x245, 0);
    base = (u8 *)buf + (margin << 7);
    row = base;
    y = margin;
    while (y < M2C_FIELD(arg0, s16 *, 2) - margin) {
        x = margin;
        cell = row + margin;
        above = (u8 *)buf + (((y - 1) << 7) + margin);
        while (x < M2C_FIELD(arg0, s16 *, 0) - margin) {
            *cell = 0;
            tile = gBattleMap[((s8)y << 6) + ((s8)x + 0x100D)];
            do_edge = 0;
            if (tile == 0xB) {
            } else if (tile >= 0xB) {
                if (tile >= 0x49) {
                    do_edge = 1;
                } else if (tile < 0x45) {
                    do_edge = 1;
                }
            } else if (tile == 4) {
            } else if (tile >= 4) {
                do_edge = 1;
            } else if (tile == 0) {
            } else {
                do_edge = 1;
            }
            if (do_edge) {
                *cell = 6;
                if (x == margin) {
                    *cell |= 1;
                } else if (cell[-1] == 0) {
                    *cell |= 1;
                } else {
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)y, 1);
                    dx = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0) - a;
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)y, 3);
                    dy = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 2) - a;
                    if (dy * dy + dx * dx >= lbl_80368F58) {
                        *cell |= 1;
                    }
                }
                if (y == margin) {
                    *cell |= 8;
                } else if (*above == 0) {
                    *cell |= 8;
                } else {
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)(y - 1), 2);
                    dx = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0) - a;
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)(y - 1), 3);
                    dy = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 1) - a;
                    if (dy * dy + dx * dx >= lbl_80368F58) {
                        *cell |= 8;
                    }
                }
            }
            cell += 1;
            above += 1;
            x += 1;
        }
        row += 0x80;
        y += 1;
    }

    disp = fn_800C45B8(0xFFFC0000, lbl_8026A660 + 0x245, 0);
    DCInvalidateRange(disp, 0x40000);
    fn_802248D8(disp, 0x40000);
    wgpipe = (volatile f32 *)0xCC008000;
    row = base;
    y = margin;
    while (y < M2C_FIELD(arg0, s16 *, 2) - margin) {
        x = margin;
        cell = row + margin;
        while (x < M2C_FIELD(arg0, s16 *, 0) - margin) {
            tile = *cell;
            if (tile != 0) {
                if (tile == 0xE) {
                    goto case_e;
                } else if (tile >= 0xE) {
                    if (tile >= 0x10) {
                    } else {
                        goto case_f;
                    }
                } else if (tile == 7) {
                    goto case_7;
                } else if (tile >= 7) {
                } else if (tile >= 6) {
                    GXBegin(0xB0, 0, 3);
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 1);
                    wgpipe[0] = (f32)(x + 1);
                    wgpipe[0] = (f32)y;
                    wgpipe[0] = a;
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 3);
                    wgpipe[0] = (f32)(x + 1);
                    wgpipe[0] = (f32)(y + 1);
                    wgpipe[0] = a;
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 2);
                    wgpipe[0] = (f32)x;
                    wgpipe[0] = (f32)(y + 1);
                    wgpipe[0] = a;
                }
                goto next2;
            case_7:
                GXBegin(0xB0, 0, 4);
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 1);
                wgpipe[0] = (f32)(x + 1);
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 3);
                wgpipe[0] = (f32)(x + 1);
                wgpipe[0] = (f32)(y + 1);
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 2);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)(y + 1);
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
                goto next2;
            case_e:
                GXBegin(0xB0, 0, 4);
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 1);
                wgpipe[0] = (f32)(x + 1);
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 3);
                wgpipe[0] = (f32)(x + 1);
                wgpipe[0] = (f32)(y + 1);
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 2);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)(y + 1);
                wgpipe[0] = a;
                goto next2;
            case_f:
                GXBegin(0xB0, 0, 5);
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 1);
                wgpipe[0] = (f32)(x + 1);
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 3);
                wgpipe[0] = (f32)(x + 1);
                wgpipe[0] = (f32)(y + 1);
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 2);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)(y + 1);
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
            }
        next2:
            cell += 1;
            x += 1;
        }
        row += 0x80;
        y += 1;
    }

    out = M2C_FIELD(arg0, void **, 0xA4);
    size = fn_802249A4(disp);
    if (out != 0) {
        fn_800C4588(out);
        M2C_FIELD(arg0, void **, 0xA4) = 0;
    }
    M2C_FIELD(arg0, void **, 0xA4) = fn_800C4638(size, lbl_8026A660 + 0x245, 0);
    M2C_FIELD(arg0, s32 *, 0xA8) = size;
    DCFlushRange(M2C_FIELD(arg0, void **, 0xA4), size);
    memcpy(M2C_FIELD(arg0, void **, 0xA4), disp, size);
    DCFlushRange(M2C_FIELD(arg0, void **, 0xA4), size);
    fn_800C4588(disp);
    fn_800C4588(buf);
    DebugPrint(lbl_8026A660 + 0x2BF, M2C_FIELD(arg0, s32 *, 0xA8));
}

void fn_80045604(s32 unused) {
    void *Hash_Lookup(void *);
    u32 Res_GetByName(void *);
    extern u8 lbl_8026A660[];
    extern u8 gBattleMap[];

    typedef struct { u8 pad[0x408E]; u16 flags; } FlagTile;

    s16 *data;
    s16 count;
    s32 n;
    u8 *p;
    s32 i;
    s32 x;
    s32 y;
    u8 v;
    FlagTile *fp;
    u32 pairs;
    u8 *base;

    if (Res_GetByName(lbl_8026A660 + 0x2D3) != 0) {
        data = Hash_Lookup(lbl_8026A660 + 0x2D3);
        count = *data;
        p = (u8 *)data + 2;
        i = 0;
        n = count;
        if (n > 0) {
            for (i = 0; i < n; i++) {
                x = (s8)p[0];
                y = (s8)p[1];
                v = p[2];
                p += 3;
                ((FlagTile *)(gBattleMap + ((x + (y << 6)) * 2)))->flags = v;
            }
        }
    }

    if (Res_GetByName(lbl_8026A660 + 0x2DB) != 0) {
        data = Hash_Lookup(lbl_8026A660 + 0x2DB);
        count = *data;
        p = (u8 *)data + 2;
        base = gBattleMap;
        n = count;
        if (n > 0) {
            pairs = (u32)n >> 1;
            if (pairs != 0) {
                do {
                    x = (s8)p[0];
                    y = (s8)p[1];
                    v = p[2];
                    fp = (FlagTile *)(base + ((x + (y << 6)) * 2));
                    fp->flags = (fp->flags & ~0x0F00) | (v << 8);
                    x = (s8)p[3];
                    y = (s8)p[4];
                    v = p[5];
                    p += 6;
                    fp = (FlagTile *)(base + ((x + (y << 6)) * 2));
                    fp->flags = (fp->flags & ~0x0F00) | (v << 8);
                    pairs -= 1;
                } while (pairs != 0);
                n &= 1;
            }
            if (n != 0) {
                do {
                    x = (s8)p[0];
                    y = (s8)p[1];
                    v = p[2];
                    p += 3;
                    fp = (FlagTile *)(base + ((x + (y << 6)) * 2));
                    fp->flags = (fp->flags & ~0x0F00) | (v << 8);
                    n -= 1;
                } while (n != 0);
            }
        }
    }

    if (Res_GetByName(lbl_8026A660 + 0x2E5) != 0) {
        data = Hash_Lookup(lbl_8026A660 + 0x2E5);
        count = *data;
        p = (u8 *)data + 2;
        i = 0;
        n = count;
        if (n > 0) {
            for (i = 0; i < n; i++) {
                x = (s8)p[0];
                y = (s8)p[1];
                v = p[2];
                p += 3;
                ((FlagTile *)(gBattleMap + ((x + (y << 6)) * 2)))->flags =
                    (u16)(v + (((~v) << 4) & 0xF0));
            }
        }
    }
}

void fn_80045B9C(void *arg0) {
    M2C_UNK fn_80067480();
    M2C_UNK fn_800675C8(M2C_UNK);
    void *Fog_GetColor();
    extern u8 lbl_8036728C;
    extern u8 lbl_8036728D;
    extern u8 lbl_8036728E;
    extern M2C_UNK lbl_80367290;
    extern f32 lbl_80368EF4;
    void *temp_r31;

    fn_800675C8(0);
    temp_r31 = Fog_GetColor();
    fn_80067480();
    M2C_FIELD(temp_r31, u8 *, 0) = (u8) lbl_8036728C;
    M2C_FIELD(temp_r31, f32 *, 4) = (f32) (5.0f * ((f32) (s8) lbl_8036728D * M2C_FIELD(arg0, f32 *, 0x6C)));
    M2C_FIELD(temp_r31, f32 *, 8) = (f32) (5.0f * ((f32) (s8) lbl_8036728E * M2C_FIELD(arg0, f32 *, 0x6C)));
    M2C_FIELD(temp_r31, u8 *, 1) = (u8) M2C_FIELD(&lbl_80367290, u8 *, 0);
    M2C_FIELD(temp_r31, u8 *, 2) = (u8) M2C_FIELD(&lbl_80367290, u8 *, 1);
    M2C_FIELD(temp_r31, u8 *, 3) = (u8) M2C_FIELD(&lbl_80367290, u8 *, 2);
}

void fn_80045C68(void *arg0)
{
    void fn_80067460(s32);
    void fn_80066F64(void);
    void *Light_GetChannel(s32);
    void Light_CopyChannel(void *, void *);
    void fn_8006720C(void *);
    extern u8 lbl_80367294;
    extern u8 lbl_80367295;
    extern u8 lbl_8036729C;
    extern u8 lbl_80367298;
    void *light;
    void *self;

    self = arg0;
    fn_80067460(0);
    fn_80066F64();
    light = Light_GetChannel(0);
    *(f32 *)((u8 *)light + 0x24) = (f32)(s8)lbl_80367294;
    *(f32 *)((u8 *)light + 0x28) = (f32)(s8)lbl_80367295;
    ((u8 *)light)[0] = (&lbl_8036729C)[0];
    ((u8 *)light)[1] = (&lbl_8036729C)[1];
    ((u8 *)light)[2] = (&lbl_8036729C)[2];
    ((u8 *)light)[4] = (&lbl_80367298)[0];
    ((u8 *)light)[5] = (&lbl_80367298)[1];
    ((u8 *)light)[6] = (&lbl_80367298)[2];
    light = Light_GetChannel(2);
    Light_CopyChannel(Light_GetChannel(0), light);
    fn_8006720C((u8 *)self + 0x70);
}

#pragma global_optimizer off
void fn_80045D50(void *arg0, void *arg1) {
    void *Hash_Lookup(void *);
    f32 fn_8001B84C(u8 **);
    void fn_8004781C(void *);
    void fn_8005FEE8(void *, f32);
    void *fn_80060638(void *);
    void *fn_80060664(void *);
    void GActor_Finalize(void *);
    void fn_80061824(void *);
    u8 fn_80068CFC(void *, void *);
    void *Heap_AllocRaw(s32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    extern u8 lbl_8026A660[];
    extern f64 lbl_80368EF8;
    extern f32 lbl_80368EE4;
    extern f32 lbl_80368EE8;
    extern f32 lbl_80368EEC;
    extern f32 lbl_80368EF0;
    extern f32 lbl_80368EF4;

    u8 sp9C[0x30];
    u8 sp6C[0x30];
    u8 sp3C[0x30];
    u8 spC[0x30];
    u8 *sp8;
    f32 f30v;
    f32 f29v;
    f32 f28v;
    f32 f27v, f26v, f25v, f24v;
    u8 *sub;
    s32 r29v;
    s32 i;
    u8 *ent;
    s32 r26v;
    void *self;
    u8 *base;
    u8 *other;
    u8 *p;
    u8 *t6;
    u8 *t5;
    u8 *t4;
    s32 a, h;
    s32 count;
    s32 m;
    s32 ctr;
    s32 idx;
    s32 tmp;
    void *ref;
    f32 scale;
    f32 temp_f0;

    self = arg0;
    sp8 = Hash_Lookup(arg1);
    *(void **)((u8 *)self + 0x14) = Heap_AllocRaw(*(s16 *)((u8 *)self + 6) * 0xB4);
    i = 0;
    ent = *(u8 **)((u8 *)self + 0x14);
    f28v = lbl_80368EE4;
    f29v = lbl_80368EEC;
    f30v = lbl_80368EF4;
    goto loop1_test;
loop1_body:
    sub = ent + 0x14;
    fn_80061824(sub);
    p = sp8;
    sp8 = p + 1;
    ent[0] = *p;
    p = sp8;
    sp8 = p + 1;
    ent[1] = *p;
    t6 = sp8;
    t5 = t6 + 1;
    sp8 = t5;
    t4 = t5 + 1;
    tmp = (s32)(t4 + 1);
    r26v = (u8)t6[0];
    sp8 = t4;
    r29v = (u8)t6[1];
    sp8 = (u8 *)tmp;
    ent[4] = t6[2];
    p = sp8;
    sp8 = p + 1;
    ent[5] = *p;
    p = sp8;
    sp8 = p + 1;
    ent[6] = *p;
    p = sp8;
    sp8 = p + 1;
    ent[7] = *p;
    *(f32 *)(ent + 0xC) = fn_8001B84C(&sp8);
    r29v *= 0xC0;
    *(void **)(ent + 0x10) = (u8 *)*(void **)((u8 *)self + 0x10) + r29v;
    *(f32 *)(ent + 8) = (f32)(0x168 - ((s32)(r26v * 0x168) >> 8));
    ent[2] = 0;
    f25v = -(*(f32 *)(ent + 0xC) + f28v);
    f27v = *(f32 *)(ent + 8) + f28v;
    f24v = (f32)(s8)ent[0] + f28v;
    f26v = (f32)(s8)ent[1] + f28v;
    if (*(u8 *)((u8 *)self + 0x68) == 1) {
        a = *(s16 *)self;
        h = *(s16 *)((u8 *)self + 2);
        a = ((u32)a >> 31) + a;
        a >>= 1;
        f24v -= (f32)a;
        f26v -= (f32)((s32)(((u32)h >> 31) + h) >> 1);
    }
    PSMTXTrans(sp9C, lbl_80368EE8, lbl_80368EE4, lbl_80368EE8);
    PSMTXRotRad(sp6C, 0x59, f29v * f27v);
    PSMTXConcat(sp6C, sp9C, sp6C);
    PSMTXTrans(sp9C, lbl_80368EF0, lbl_80368EE4, lbl_80368EF0);
    PSMTXConcat(sp9C, sp6C, spC);
    scale = *(f32 *)((u8 *)self + 0x6C);
    PSMTXScale(sp3C, scale, scale, scale);
    PSMTXConcat(sp3C, spC, spC);
    temp_f0 = *(f32 *)((u8 *)self + 0x6C);
    PSMTXTrans(sp9C, f30v * (f24v * temp_f0), f30v * (f25v * temp_f0), f30v * (f26v * temp_f0));
    PSMTXConcat(sp9C, spC, spC);
    PSMTXConcat((u8 *)self + 0x70, spC, ent + 0x24);
    tmp = r29v + 4;
    *(void **)(sub + 4) = (u8 *)*(void **)((u8 *)self + 0x10) + tmp;
    GActor_Finalize(sub);
    r26v = *(s32 *)(*(u8 **)(ent + 0x10) + 0xBC);
    if (*(u8 *)((u8 *)self + 0x68) == 1) {
        if (fn_80068CFC(fn_80060638(sub), lbl_8026A660 + 0x2F0) != 0) {
            sub[0x87] = 0;
        } else {
            sub[0x87] = 3;
        }
    } else {
        if (r26v & 0x2000) {
            *(u32 *)sub |= 0x200000;
        }
        if (r26v & 0x2020) {
            sub[0x87] = 2;
        } else {
            sub[0x87] = 1;
        }
    }
    if (r26v & 0x800) {
        sub[0x87] = 2;
    }
    if (r26v & 0x40) {
        *(u32 *)sub |= 0x40000 | 0x400;
    }
    if (r26v & 0x40000) {
        *(u32 *)sub |= 0x400;
    }
    if (r26v & 0x20000) {
        ent[2] |= 1;
    }
    if (((s32)((s8)ent[6] - (s8)ent[4]) >= 2) || ((s32)((s8)ent[7] - (s8)ent[5]) >= 2)) {
        u8 *t = *(u8 **)(ent + 0x10);
        *(u32 *)(t + 0xBC) |= 8;
    }
    i += 1;
    ent += 0xB4;
loop1_test:
    if (i < *(s16 *)((u8 *)self + 6)) {
        goto loop1_body;
    }

    r29v = 0;
    r26v = 0;
    sub = (u8 *)r29v;
    i = 0;
    goto loop2_test;
loop2_body:
    base = *(u8 **)((u8 *)self + 0x14);
    ent = base + (s32)sub;
    if (*(u32 *)(*(u8 **)(ent + 0x10) + 0xBC) & 0x400) {
        if (r26v == 0) {
            m = r29v + 1;
            ctr = count - m;
            idx = m * 0xB4;
            if (m < count) {
                for (; ctr != 0; ctr--) {
                    other = base + idx;
                    if (*(void **)(ent + 0x10) != *(void **)(other + 0x10)
                        || (s8)ent[0] != (s8)other[0]
                        || (s8)ent[1] != (s8)other[1]) {
                        break;
                    }
                    r26v += 1;
                    idx += 0xB4;
                    m += 1;
                }
            }
            i = 0;
        }
        if (r26v > 0) {
            u8 *s2 = ent + 0x14;
            ref = fn_80060664(s2);
            tmp = r26v + 1;
            fn_8005FEE8(s2, (f32)((s32)(i * *(s32 *)((u8 *)ref + 0x18)) / tmp));
            i += 1;
            if (i > r26v) {
                r26v = 0;
            }
        }
    }
    sub += 0xB4;
    r29v += 1;
loop2_test:
    count = *(s16 *)((u8 *)self + 6);
    if (r29v < count) {
        goto loop2_body;
    }

    if (!(*(u32 *)((u8 *)self + 0x64) & 0x20000000)) {
        fn_8004781C(self);
        *(u32 *)((u8 *)self + 0x64) |= 0x20000000;
    }
}
#pragma global_optimizer on

void fn_800462FC(void *arg0, void *arg1, void *arg2) {
    void *fn_80060638(void *);
    void fn_80068558(void *, void *, void *);
    u8 *ptr;
    s32 i;

    i = 0;
    ptr = *(u8 **)((u8 *)arg0 + 0x10);
    while (i < *(s16 *)((u8 *)arg0 + 4)) {
        fn_80068558(fn_80060638(ptr + 4), arg1, arg2);
        i += 1;
        ptr += 0xC0;
    }
}

void *fn_80046360(void *arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, s32 arg5) {
    void *fn_80060638(void *);
    u8 fn_800688D4(void *, s32, s32, s32);
    void *result;
    u8 *ptr;
    s32 i;
    u32 flags;
    void *node;

    result = NULL;
    i = 0;
    ptr = *(u8 **)((u8 *)arg0 + 0x10);
    while (i < *(s16 *)((u8 *)arg0 + 4)) {
        flags = *(u32 *)(ptr + 0xBC);
        node = ptr + 4;
        if (!(flags & arg4) && arg3 == (arg3 & flags)) {
            if (fn_800688D4(fn_80060638(node), arg1, arg2, arg5) != 0) {
                result = ptr;
            }
        }
        i += 1;
        ptr += 0xC0;
    }
    return result;
}

void Map_CollectLinkedObjs(void *arg0, void *arg1, void *arg2) {
    M2C_UNK fn_80046424(void *, void *, void *, M2C_UNK);
    fn_80046424(arg0, arg1, arg2, 0);
}

s32 fn_80046424(void *arg0, void *arg1, void **arg2, s32 arg3) {
    void *Map_FindObjAt(void *, s32, s32, u32, s32);
    void *fn_80049E1C(void *);
    void **p;
    s32 n;
    s32 i;
    s32 mid;
    s32 edge;
    u32 mask;
    u32 flags;
    void *found;
    u8 *entry;
    u8 *base;
    u32 nmask;
    u8 ok;
    s32 count;

    if (arg1 == NULL) {
        return arg3;
    }
    p = arg2;
    n = arg3;
    if (n > 0) {
        do {
            if (*p == arg1) {
                return arg3;
            }
            p++;
        } while (--n != 0);
    }
    arg2[arg3] = arg1;
    mask = *(u32 *)((u8 *)*(void **)((u8 *)arg1 + 0x10) + 0xBC) | 0x200000;
    count = arg3 + 1;

    /* left */
    mid = ((s8)*(u8 *)((u8 *)arg1 + 5) + (s8)*(u8 *)((u8 *)arg1 + 7)) / 2;
    edge = (s8)*(u8 *)((u8 *)arg1 + 4) - 1;
    found = NULL;
    for (i = *(s16 *)((u8 *)arg0 + 6) - 1; i >= 0; i--) {
        base = *(u8 **)((u8 *)arg0 + 0x14);
        entry = base + i * 0xB4;
        flags = *(u32 *)((u8 *)*(void **)(entry + 0x10) + 0xBC);
        if (!(flags & 0x10)) {
            if (mask == 0 || mask == (mask & flags)) {
                if (edge >= (s8)*(u8 *)(entry + 4) && edge <= (s8)*(u8 *)(entry + 6) &&
                    mid >= (s8)*(u8 *)(entry + 5) && mid <= (s8)*(u8 *)(entry + 7)) {
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok != 0) {
                    found = base + i * 0xB4;
                    break;
                }
            }
        }
    }
    if (found != NULL) {
        p = arg2;
        n = count;
        if (n > 0) {
            do {
                if (*p == found) {
                    goto right;
                }
                p++;
            } while (--n != 0);
        }
        arg2[count] = found;
        n = count + 1;
        nmask = *(u32 *)((u8 *)fn_80049E1C(found) + 0xBC) | 0x200000;
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 4) - 1, mid, nmask, 0x10), arg2, n);
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 6) + 1, mid, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 5) - 1, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 7) + 1, nmask, 0x10), arg2, count);
    }
right:
    mid = ((s8)*(u8 *)((u8 *)arg1 + 5) + (s8)*(u8 *)((u8 *)arg1 + 7)) / 2;
    edge = (s8)*(u8 *)((u8 *)arg1 + 6) + 1;
    found = NULL;
    for (i = *(s16 *)((u8 *)arg0 + 6) - 1; i >= 0; i--) {
        base = *(u8 **)((u8 *)arg0 + 0x14);
        entry = base + i * 0xB4;
        flags = *(u32 *)((u8 *)*(void **)(entry + 0x10) + 0xBC);
        if (!(flags & 0x10)) {
            if (mask == 0 || mask == (mask & flags)) {
                if (edge >= (s8)*(u8 *)(entry + 4) && edge <= (s8)*(u8 *)(entry + 6) &&
                    mid >= (s8)*(u8 *)(entry + 5) && mid <= (s8)*(u8 *)(entry + 7)) {
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok != 0) {
                    found = base + i * 0xB4;
                    break;
                }
            }
        }
    }
    if (found != NULL) {
        p = arg2;
        n = count;
        if (n > 0) {
            do {
                if (*p == found) {
                    goto up;
                }
                p++;
            } while (--n != 0);
        }
        arg2[count] = found;
        n = count + 1;
        nmask = *(u32 *)((u8 *)fn_80049E1C(found) + 0xBC) | 0x200000;
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 4) - 1, mid, nmask, 0x10), arg2, n);
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 6) + 1, mid, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 5) - 1, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 7) + 1, nmask, 0x10), arg2, count);
    }
up:
    mid = ((s8)*(u8 *)((u8 *)arg1 + 4) + (s8)*(u8 *)((u8 *)arg1 + 6)) / 2;
    edge = (s8)*(u8 *)((u8 *)arg1 + 5) - 1;
    found = NULL;
    for (i = *(s16 *)((u8 *)arg0 + 6) - 1; i >= 0; i--) {
        base = *(u8 **)((u8 *)arg0 + 0x14);
        entry = base + i * 0xB4;
        flags = *(u32 *)((u8 *)*(void **)(entry + 0x10) + 0xBC);
        if (!(flags & 0x10)) {
            if (mask == 0 || mask == (mask & flags)) {
                if (mid >= (s8)*(u8 *)(entry + 4) && mid <= (s8)*(u8 *)(entry + 6) &&
                    edge >= (s8)*(u8 *)(entry + 5) && edge <= (s8)*(u8 *)(entry + 7)) {
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok != 0) {
                    found = base + i * 0xB4;
                    break;
                }
            }
        }
    }
    if (found != NULL) {
        p = arg2;
        n = count;
        if (n > 0) {
            do {
                if (*p == found) {
                    goto down;
                }
                p++;
            } while (--n != 0);
        }
        arg2[count] = found;
        n = count + 1;
        nmask = *(u32 *)((u8 *)fn_80049E1C(found) + 0xBC) | 0x200000;
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 4) - 1, mid, nmask, 0x10), arg2, n);
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 6) + 1, mid, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 5) - 1, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 7) + 1, nmask, 0x10), arg2, count);
    }
down:
    mid = ((s8)*(u8 *)((u8 *)arg1 + 4) + (s8)*(u8 *)((u8 *)arg1 + 6)) / 2;
    edge = (s8)*(u8 *)((u8 *)arg1 + 7) + 1;
    found = NULL;
    for (i = *(s16 *)((u8 *)arg0 + 6) - 1; i >= 0; i--) {
        base = *(u8 **)((u8 *)arg0 + 0x14);
        entry = base + i * 0xB4;
        flags = *(u32 *)((u8 *)*(void **)(entry + 0x10) + 0xBC);
        if (!(flags & 0x10)) {
            if (mask == 0 || mask == (mask & flags)) {
                if (mid >= (s8)*(u8 *)(entry + 4) && mid <= (s8)*(u8 *)(entry + 6) &&
                    edge >= (s8)*(u8 *)(entry + 5) && edge <= (s8)*(u8 *)(entry + 7)) {
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok != 0) {
                    found = base + i * 0xB4;
                    break;
                }
            }
        }
    }
    if (found != NULL) {
        p = arg2;
        n = count;
        if (n > 0) {
            do {
                if (*p == found) {
                    goto done;
                }
                p++;
            } while (--n != 0);
        }
        arg2[count] = found;
        n = count + 1;
        nmask = *(u32 *)((u8 *)fn_80049E1C(found) + 0xBC) | 0x200000;
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 4) - 1, mid, nmask, 0x10), arg2, n);
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 6) + 1, mid, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 5) - 1, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 7) + 1, nmask, 0x10), arg2, count);
    }
done:
    return count;
}

void *fn_80046EB8(void *arg0,void *arg1) { u8 *base; s32 i; if(arg1==0)return 0; for(i=*(s16*)((u8*)arg0+6)-1;i>=0;i--) {base=*(u8**)((u8*)arg0+0x14); if(arg1==*(void**)(base+i*0xB4+0x10))return base+i*0xB4;} return 0; }

s32 Map_FindObjNear(void *arg0, s32 arg1) {
    void **temp_r7;
    s32 var_r9;
    void *temp_r5;
    s32 *temp_r3;

    temp_r7 = (void **)((char *)arg0 + 0x188);
    if (*(void **)temp_r7 == NULL) {
        return 0;
    }
    temp_r5 = (char *)temp_r7 + 0x50;
    if (*(void **)temp_r5 == NULL) {
        return 0;
    }

    temp_r3 = (s32 *)((char *)arg0 + 0x210);
    var_r9 = *(s32 *)((char *)temp_r5 + arg1 * 8);
    if (var_r9 >= 0) {
        if ((u32)(var_r9 - *(s32 *)temp_r3) > 0U) {
            return 0;
        }
    } else {
        s32 temp = *(s32 *)((char *)arg0 + arg1 * 8 + 0x24C);
        if (temp >= 0) {
            if ((u32)(temp - *(s32 *)temp_r3) > 0U) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

s32 Map_FindObjAtXY(void *arg0, s32 arg1, s32 arg2)
{
  s32 i;
  s32 offset;
  u8 *entry;
  s32 base;
  s32 count;
  u8 ok;
  count = *((s16 *) (((u8 *) arg0) + 0x6));
  for (i = count - 1, offset = i * 0xB4; i >= 0; offset -= 0xB4, i--)
  {
    base = *((s32 *) (((u8 *) arg0) + 0x14));
    entry = ((u8 *) base) + offset;
    {
      s32 flags = *((s32 *) (((u8 *) (*((s32 *) (entry + 0x10)))) + 0xBC));
      if (!(flags & 0x90))
      {
        if ((((arg1 >= (*((s8 *) (entry + 0x4)))) && (arg1 <= (*((s8 *) (entry + 0x6))))) && (arg2 >= (*((s8 *) (entry + 0x5))))) && (arg2 <= (*((s8 *) (entry + 0x7)))))
        {
          ok = 1;
        }
        else
        {
          ok = 0;
        }
        if (ok != 0)
        {
          return base + (i * 0xB4);
        }
      }
    }
  }

  return 0;
}

s32 Map_FindObjAt(void *arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4) {
    u8 *entry;
    s32 base;
    s32 i;
    s32 count;
    u8 ok;

    count = *(s16 *)((u8 *)arg0 + 0x6);
    for (i = count - 1; i >= 0; i--) {
        base = *(s32 *)((u8 *)arg0 + 0x14);
        entry = (u8 *)base + i * 0xB4;
        {
            s32 flags = *(s32 *)((u8 *)*(s32 *)(entry + 0x10) + 0xBC);
            if (!(flags & arg4)) {
                if (arg3 == 0 || arg3 == (u32)(arg3 & flags)) {
                    if (arg1 >= *(s8 *)(entry + 0x4) && arg1 <= *(s8 *)(entry + 0x6) &&
                        arg2 >= *(s8 *)(entry + 0x5) && arg2 <= *(s8 *)(entry + 0x7)) {
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                    if (ok != 0) {
                        return base + i * 0xB4;
                    }
                }
            }
        }
    }
    return 0;
}

#pragma global_optimizer off
/* Update map-entry world matrices; alternate half-ranges each frame, then transform visible entries. */
void Map_UpdateTransforms(void *arg0) {
void Map_PrepareEntryRange(void *, s32, s32);
void fn_80060060(void *);
void fn_800609DC(void *);
void fn_8006785C(s32, void *, void *);
void fn_8006CAD4(void *);
void PSMTXConcat(void *, void *, void *);
void PSMTXRotRad(void *, s32, f32);
void PSMTXTrans(void *, f32, f32, f32);
void PSMTXScale(void *, f32, f32, f32);
void fn_80048518(void);
extern void *gMap;
extern u8 sMapUpdateInited;
extern s32 sMapUpdateCounter;
extern f64 lbl_80368EF8;
extern f32 lbl_80368EE4;
extern f32 lbl_80368EE8;
extern f32 lbl_80368EEC;
extern f32 lbl_80368EF0;
extern f32 lbl_80368EF4;
    u8 sp158[0x30];
    u8 sp128[0x30];
    u8 spF8[0x30];
    u8 spC8[0x30];
    u8 sp98[0x30];
    u8 sp68[0x30];
    u8 sp38[0x30];
    u8 sp8[0x30];
    u32 mask;
    u8 *ent;
    s32 i;
    u8 *sub;
    void *self;
    u8 flags;
    f32 f31v, f30v, f29v, f28v;
    f32 t30;
    s16 t6;
    s32 a, b;
    f32 scale;
    f32 temp_f0;
    s16 h;

    self = arg0;
    if (*(u32 *)((u8 *)self + 0x64) & 0x40000000) {
        if (*(u32 *)((u8 *)self + 0xC) != 0) {
            if ((s8)sMapUpdateInited == 0) {
                sMapUpdateCounter = 0;
                sMapUpdateInited = 1;
            }
            if ((sMapUpdateCounter & 1) != 0) {
                t6 = *(s16 *)((u8 *)self + 6);
                a = 0;
                b = (s32)(((u32)t6 >> 31) + t6) >> 1;
            } else {
                b = *(s16 *)((u8 *)self + 6);
                a = (s32)(((u32)b >> 31) + b) >> 1;
            }
            sMapUpdateCounter = sMapUpdateCounter + 1;
            Map_PrepareEntryRange(self, a, b);
        }
        if ((*(u32 *)((u8 *)self + 0x64) & 0x80000000) == 0 && (*(u32 *)((u8 *)self + 0x64) & 0x40000000) != 0) {
            ent = *(u8 **)((u8 *)self + 0x14);
            i = 0;
            goto loop1_test;
        loop1_body:
            sub = ent + 0x14;
            flags = ent[2];
            mask = *(u32 *)(*(u8 **)(ent + 0x10) + 0xBC);
            if ((mask & 1) == 0 && (flags & 1) == 0) {
                if ((mask & 0x400) != 0) {
                    fn_80060060(sub);
                }
                if ((flags & 0x80) == 0) {
                    if ((mask & 0x80) != 0) {
                        f28v = (f32)(s8)ent[0] + lbl_80368EE4;
                        f29v = -(*(f32 *)(ent + 0xC) + *(f32 *)(*(u8 **)((u8 *)gMap + 0x30) + 0x48));
                        t30 = (f32)(s8)ent[1];
                        f31v = *(f32 *)(ent + 8) + lbl_80368EE4;
                        f30v = t30 + lbl_80368EE4;
                        if (*(u8 *)((u8 *)self + 0x68) == 1) {
                            a = *(s16 *)self;
                            h = *(s16 *)((u8 *)self + 2);
                            a = ((u32)a >> 31) + a;
                            a >>= 1;
                            f28v -= (f32)a;
                            f30v -= (f32)((s32)(((u32)h >> 31) + h) >> 1);
                        }
                        PSMTXTrans(sp158, lbl_80368EE8, lbl_80368EE4, lbl_80368EE8);
                        PSMTXRotRad(sp128, 0x59, lbl_80368EEC * f31v);
                        PSMTXConcat(sp128, sp158, sp128);
                        PSMTXTrans(sp158, lbl_80368EF0, lbl_80368EE4, lbl_80368EF0);
                        PSMTXConcat(sp158, sp128, spC8);
                        scale = *(f32 *)((u8 *)self + 0x6C);
                        PSMTXScale(spF8, scale, scale, scale);
                        PSMTXConcat(spF8, spC8, spC8);
                        temp_f0 = *(f32 *)((u8 *)self + 0x6C);
                        PSMTXTrans(sp158, lbl_80368EF4 * (f28v * temp_f0), lbl_80368EF4 * (f29v * temp_f0), lbl_80368EF4 * (f30v * temp_f0));
                        PSMTXConcat(sp158, spC8, spC8);
                        PSMTXConcat((u8 *)self + 0x70, spC8, ent + 0x24);
                    }
                    if ((mask & 0x10000) != 0) {
                        fn_8006785C(2, fn_80048518, ent);
                    }
                    fn_800609DC(sub);
                    fn_8006CAD4(sub);
                }
            }
            i += 1;
            ent += 0xB4;
        loop1_test:
            if (i < *(s16 *)((u8 *)self + 6)) {
                goto loop1_body;
            }
        }
        if ((*(u32 *)((u8 *)self + 0x64) & 0x80000000) == 0 && (*(u32 *)((u8 *)self + 0x64) & 0x40000000) != 0) {
            u32 m;
            s32 n;
            ent = *(u8 **)((u8 *)self + 0x14);
            n = 0;
            goto loop2_test;
        loop2_body:
            sub = ent + 0x14;
            flags = ent[2];
            m = *(u32 *)(*(u8 **)(ent + 0x10) + 0xBC);
            if ((u32)(m & 1) == 1 && (flags & 1) == 0) {
                if ((m & 0x400) != 0) {
                    fn_80060060(sub);
                }
                if ((flags & 0x80) == 0) {
                    if ((m & 0x80) != 0) {
                        f31v = (f32)(s8)ent[0] + lbl_80368EE4;
                        f30v = -(*(f32 *)(ent + 0xC) + *(f32 *)(*(u8 **)((u8 *)gMap + 0x30) + 0x48));
                        t30 = (f32)(s8)ent[1];
                        f28v = *(f32 *)(ent + 8) + lbl_80368EE4;
                        f29v = t30 + lbl_80368EE4;
                        if (*(u8 *)((u8 *)self + 0x68) == 1) {
                            a = *(s16 *)self;
                            h = *(s16 *)((u8 *)self + 2);
                            a = ((u32)a >> 31) + a;
                            a >>= 1;
                            f31v -= (f32)a;
                            f29v -= (f32)((s32)(((u32)h >> 31) + h) >> 1);
                        }
                        PSMTXTrans(sp98, lbl_80368EE8, lbl_80368EE4, lbl_80368EE8);
                        PSMTXRotRad(sp68, 0x59, lbl_80368EEC * f28v);
                        PSMTXConcat(sp68, sp98, sp68);
                        PSMTXTrans(sp98, lbl_80368EF0, lbl_80368EE4, lbl_80368EF0);
                        PSMTXConcat(sp98, sp68, sp8);
                        scale = *(f32 *)((u8 *)self + 0x6C);
                        PSMTXScale(sp38, scale, scale, scale);
                        PSMTXConcat(sp38, sp8, sp8);
                        temp_f0 = *(f32 *)((u8 *)self + 0x6C);
                        PSMTXTrans(sp98, lbl_80368EF4 * (f31v * temp_f0), lbl_80368EF4 * (f30v * temp_f0), lbl_80368EF4 * (f29v * temp_f0));
                        PSMTXConcat(sp98, sp8, sp8);
                        PSMTXConcat((u8 *)self + 0x70, sp8, ent + 0x24);
                    }
                    if ((m & 0x10000) != 0) {
                        fn_8006785C(2, fn_80048518, ent);
                    }
                    fn_800609DC(sub);
                    fn_8006CAD4(sub);
                }
            }
            n += 1;
            ent += 0xB4;
        loop2_test:
            if (n < *(s16 *)((u8 *)self + 6)) {
                goto loop2_body;
            }
        }
    }
}
#pragma global_optimizer on
u8 fn_80047AF8(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x61);
}

#pragma use_lmw_stmw on
#pragma opt_loop_invariants off
#pragma opt_peephole off
void Map_PrepareEntryRange(void *arg0, s32 arg1, s32 arg2) {
    void fn_80060638(void *);
    void fn_8006049C(void *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void QUATMtx(void *, void *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXCopy(void *, void *);
    void Game_Assert(void *, s32, void *);
    void *fn_80067FD0(void);
    void fn_80202C18(void *, void *, void *);
    void fn_8020310C(void *, void *, void *);
    extern u8 lbl_8026A660[];
    extern f32 lbl_80368EE4;
    extern f32 lbl_80368EEC;
    extern f32 lbl_80368F10;
    extern f32 lbl_80368F2C;
    extern f32 lbl_80368F5C;
    extern f32 lbl_80368F60;
    extern f32 lbl_80368F64;
    extern f32 lbl_80368F68;
    struct Work {
        f32 quat[4];
        f32 corners[8][3];
    } wk;
    u8 bufF8[0x30];
    u8 bufC8[0x30];
    u8 buf98[0x30];
    u8 buf68[0x30];
    u8 buf38[0x30];
    u8 buf8[0x30];
    s32 i;
    u8 *entry = M2C_FIELD(arg0, u8 **, 0x14) + arg1 * 0xB4;
    u8 *sub;
    f32 *c7 = &wk.corners[7][0];
    f32 *c6 = &wk.corners[6][0];
    f32 *c5 = &wk.corners[5][0];
    f32 *c4 = &wk.corners[4][0];
    f32 *c3 = &wk.corners[3][0];
    f32 *c2 = &wk.corners[2][0];
    f32 *c1 = &wk.corners[1][0];
    u8 *e;
    u32 mask = 0x1040;
    f32 minX;
    f32 minY;
    f32 maxX;
    f32 maxY;
    f32 x;
    f32 y;
    f32 *p;
    s32 j;
    u8 hit;

    for (i = arg1; i < arg2; i++, entry += 0xB4) {
        e = entry + 0x14;
        fn_80060638(e);
        sub = M2C_FIELD(entry, u8 **, 0x10);
        M2C_FIELD(entry, u8 *, 2) &= 0x7F;
        if (M2C_FIELD(sub, u32 *, 0xBC) & mask) {
            continue;
        }
        fn_8006049C(e);
        switch (M2C_FIELD(e, u32 *, 0xC)) {
            case 0:
                break;
            case 1:
                PSMTXRotRad(buf68, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                PSMTXRotRad(buf98, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                PSMTXRotRad(bufC8, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                break;
            case 2:
                PSMTXRotRad(buf68, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                PSMTXRotRad(buf98, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                PSMTXRotRad(bufC8, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                break;
            case 3:
                PSMTXRotRad(buf68, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                PSMTXRotRad(buf98, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                PSMTXRotRad(bufC8, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                break;
            case 4:
                PSMTXRotRad(buf68, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                PSMTXRotRad(buf98, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                PSMTXRotRad(bufC8, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                break;
            case 5:
                PSMTXRotRad(buf68, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                PSMTXRotRad(buf98, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                PSMTXRotRad(bufC8, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                break;
            case 6:
                PSMTXRotRad(buf68, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                PSMTXRotRad(buf98, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                PSMTXRotRad(bufC8, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                break;
            case 7:
                PSMTXCopy(e + 0x10, bufF8);
                goto checks;
            case 8:
                PSMTXScale(buf8, M2C_FIELD(e, f32 *, 0x28), M2C_FIELD(e, f32 *, 0x2C), M2C_FIELD(e, f32 *, 0x30));
                PSMTXTrans(buf38, M2C_FIELD(e, f32 *, 0x10), M2C_FIELD(e, f32 *, 0x14), M2C_FIELD(e, f32 *, 0x18));
                QUATMtx(e + 0x10, buf68);
                PSMTXConcat(buf68, buf8, bufF8);
                PSMTXConcat(buf68, bufF8, bufF8);
                PSMTXConcat(buf38, bufF8, bufF8);
                goto checks;
            default:
                goto checks;
        }
        Game_Assert(lbl_8026A660 + 0x2F7, 0xB8, lbl_8026A660 + 0x2FF);
        PSMTXScale(buf8, M2C_FIELD(e, f32 *, 0x28), M2C_FIELD(e, f32 *, 0x2C), M2C_FIELD(e, f32 *, 0x30));
        PSMTXTrans(buf38, M2C_FIELD(e, f32 *, 0x10), M2C_FIELD(e, f32 *, 0x14), M2C_FIELD(e, f32 *, 0x18));
        PSMTXConcat(buf68, buf8, bufF8);
        PSMTXConcat(buf98, bufF8, bufF8);
        PSMTXConcat(bufC8, bufF8, bufF8);
        PSMTXConcat(buf38, bufF8, bufF8);
        wk.quat[0] = lbl_80368EE4;
        wk.quat[1] = lbl_80368EE4;
        wk.quat[2] = lbl_80368EE4;
        wk.quat[3] = lbl_80368F10;
        fn_80202C18(fn_80067FD0(), bufF8, bufF8);
checks:
        wk.corners[0][0] = M2C_FIELD(sub, f32 *, 0xA4);
        wk.corners[0][1] = M2C_FIELD(sub, f32 *, 0xA8);
        wk.corners[0][2] = M2C_FIELD(sub, f32 *, 0xAC);
        fn_8020310C(bufF8, &wk.corners[0][0], &wk.corners[0][0]);
        hit = !(wk.corners[0][0] * wk.corners[0][0] < lbl_80368F5C && wk.corners[0][1] * wk.corners[0][1] < lbl_80368F60 &&
                wk.corners[0][2] > lbl_80368F2C && wk.corners[0][2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c1[0] = M2C_FIELD(sub, f32 *, 0xB0);
        c1[1] = M2C_FIELD(sub, f32 *, 0xA8);
        c1[2] = M2C_FIELD(sub, f32 *, 0xAC);
        fn_8020310C(bufF8, c1, c1);
        hit = !(c1[0] * c1[0] < lbl_80368F5C && c1[1] * c1[1] < lbl_80368F60 &&
                c1[2] > lbl_80368F2C && c1[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c2[0] = M2C_FIELD(sub, f32 *, 0xB0);
        c2[1] = M2C_FIELD(sub, f32 *, 0xB4);
        c2[2] = M2C_FIELD(sub, f32 *, 0xAC);
        fn_8020310C(bufF8, c2, c2);
        hit = !(c2[0] * c2[0] < lbl_80368F5C && c2[1] * c2[1] < lbl_80368F60 &&
                c2[2] > lbl_80368F2C && c2[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c3[0] = M2C_FIELD(sub, f32 *, 0xA4);
        c3[1] = M2C_FIELD(sub, f32 *, 0xB4);
        c3[2] = M2C_FIELD(sub, f32 *, 0xAC);
        fn_8020310C(bufF8, c3, c3);
        hit = !(c3[0] * c3[0] < lbl_80368F5C && c3[1] * c3[1] < lbl_80368F60 &&
                c3[2] > lbl_80368F2C && c3[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c4[0] = M2C_FIELD(sub, f32 *, 0xA4);
        c4[1] = M2C_FIELD(sub, f32 *, 0xA8);
        c4[2] = M2C_FIELD(sub, f32 *, 0xB8);
        fn_8020310C(bufF8, c4, c4);
        hit = !(c4[0] * c4[0] < lbl_80368F5C && c4[1] * c4[1] < lbl_80368F60 &&
                c4[2] > lbl_80368F2C && c4[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c5[0] = M2C_FIELD(sub, f32 *, 0xB0);
        c5[1] = M2C_FIELD(sub, f32 *, 0xA8);
        c5[2] = M2C_FIELD(sub, f32 *, 0xB8);
        fn_8020310C(bufF8, c5, c5);
        hit = !(c5[0] * c5[0] < lbl_80368F5C && c5[1] * c5[1] < lbl_80368F60 &&
                c5[2] > lbl_80368F2C && c5[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c6[0] = M2C_FIELD(sub, f32 *, 0xB0);
        c6[1] = M2C_FIELD(sub, f32 *, 0xB4);
        c6[2] = M2C_FIELD(sub, f32 *, 0xB8);
        fn_8020310C(bufF8, c6, c6);
        hit = !(c6[0] * c6[0] < lbl_80368F5C && c6[1] * c6[1] < lbl_80368F60 &&
                c6[2] > lbl_80368F2C && c6[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c7[0] = M2C_FIELD(sub, f32 *, 0xA4);
        c7[1] = M2C_FIELD(sub, f32 *, 0xB4);
        c7[2] = M2C_FIELD(sub, f32 *, 0xB8);
        fn_8020310C(bufF8, c7, c7);
        hit = !(c7[0] * c7[0] < lbl_80368F5C && c7[1] * c7[1] < lbl_80368F60 &&
                c7[2] > lbl_80368F2C && c7[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        if (!(M2C_FIELD(sub, u32 *, 0xBC) & 8)) {
            continue;
        }
        minX = lbl_80368F64;
        minY = minX;
        maxX = lbl_80368F68;
        maxY = maxX;
        p = &wk.corners[0][0];
        for (j = 0; j < 4; j++, p += 2) {
            x = p[0];
            y = p[1];
            if (p[2] > lbl_80368EE4) {
                x *= lbl_80368F2C;
                y *= lbl_80368F2C;
            }
            if (minX > x) {
                minX = x;
            }
            if (minY > y) {
                minY = y;
            }
            if (maxX < x) {
                maxX = x;
            }
            if (maxY < y) {
                maxY = y;
            }
            x = p[3];
            y = p[4];
            if (p[5] > lbl_80368EE4) {
                x *= lbl_80368F2C;
                y *= lbl_80368F2C;
            }
            if (minX > x) {
                minX = x;
            }
            if (minY > y) {
                minY = y;
            }
            if (maxX < x) {
                maxX = x;
            }
            if (maxY < y) {
                maxY = y;
            }
        }
        if (minX >= lbl_80368F2C) {
            goto res2;
        }
        if (maxX <= lbl_80368F10) {
            goto res2;
        }
        if (minY >= lbl_80368F2C) {
            goto res2;
        }
        if (maxY > lbl_80368F10) {
            continue;
        }
        if (minX * minX < lbl_80368F10 && minY * minY < lbl_80368F10) {
            continue;
        }
        if (maxX * maxX < lbl_80368F10 && minY * minY < lbl_80368F10) {
            continue;
        }
        if (maxX * maxX < lbl_80368F10 && maxY * maxY < lbl_80368F10) {
            continue;
        }
        if (minX * minX < lbl_80368F10 && maxY * maxY < lbl_80368F10) {
            continue;
        }
res2:
        if (minX < lbl_80368F2C && maxX > lbl_80368F10 && minY * minY < lbl_80368F10 && maxY * maxY < lbl_80368F10) {
            continue;
        }
        if (minY >= lbl_80368F2C) {
            continue;
        }
        if (maxY <= lbl_80368F10) {
            continue;
        }
        if (minX * minX < lbl_80368F10) {
            continue;
        }
        if (maxX * maxX < lbl_80368F10) {
            continue;
        }
        M2C_FIELD(entry, u8 *, 2) |= 0x80;
    }
}

#pragma use_lmw_stmw on
void fn_80048478(void *arg0, void *arg1, u32 arg2, u32 arg3) {
    void fn_80069F2C(void *, void *);
    s32 i;
    u8 *entry;
    u32 flags;
    u8 bits;

    if (*(u32 *)((u8 *)arg0 + 0x64) & 0x40000000) {
        entry = *(u8 **)((u8 *)arg0 + 0x14);
        i = 0;
        while (i < *(s16 *)((u8 *)arg0 + 6)) {
            flags = *(u32 *)(*(u8 **)(entry + 0x10) + 0xBC);
            bits = entry[2];
            if (!(flags & arg3) && (arg2 == 0 || (flags & arg2)) && !(bits & 1) && !(bits & 0x80)) {
                fn_80069F2C(arg1, entry + 0x14);
            }
            i += 1;
            entry += 0xB4;
        }
    }
}

void fn_80048518(void *arg0) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    void fn_80222C50(void *, s32);
    void fn_8022100C(s32);
    void GXClearVtxDesc(void);
    void GXSetVtxDesc(s32, s32);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void PSMTXTrans(void *, f32, f32, f32);
    void *Camera_GetViewMtx(void);
    void PSMTXConcat(void *, void *, void *);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void GXSetZMode(s32, s32, s32);
    void fn_802245D8(s32, s32, s32, s32);
    void fn_80223E5C(s32, s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void QUATMtx(void *, void *);
    void PSMTXCopy(void *, void *);
    void Game_Assert(void *, s32, void *);
    void fn_802029C4(void *, void *, void *);
    void fn_80051328(s32, void *, f32, f32, f32, f32, f32);
    void fn_80224E50(void *, s32, s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80051538(void *, s32, f32, f32);
    void fn_80066D00(s32);
    extern void *gMap;
    extern f32 lbl_80368EE4, lbl_80368F50, lbl_80368EEC, lbl_80368F00;
    extern u32 lbl_80368EDC;
    extern u8 lbl_8026A660[];
    extern u32 lbl_8026A600[3];
    f32 fx;
    f32 fy;
    u8 *self;
    f32 view[3][4];
    f32 tmp[3][4];
    f32 out[3][4];
    f32 rz[3][4];
    f32 ry[3][4];
    f32 rx[3][4];
    f32 trans[3][4];
    f32 scale[3][4];
    u8 tex[0x20];
    u32 pt[3];
    u32 color_tmp;
    u32 color;
    u8 alpha;

    self = arg0;
    Ui_LoadAtlasTex(*(s32 *)((u8 *)gMap + 0x38), tex, 0);
    fn_80222C50(tex, 0);
    fn_8022100C(2);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xb, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xb, 1, 5, 0);
    GXSetCullMode(1);
    GXSetBlendMode(4, 0, 1, 1, 0, 0, 2);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetNumChans(1);
    PSMTXTrans(tmp, lbl_80368EE4, lbl_80368EE4, lbl_80368F50);
    PSMTXConcat(Camera_GetViewMtx(), tmp, view);
    GXLoadPosMtxImm(view, 0);
    GXSetCurrentMtx(0);
    GXSetZMode(1, 3, 0);
    fn_802245D8(1, 4, 5, 7);
    fn_80223E5C(7, 0, 1, 7, 0);
    GXSetNumTexGens(0, 0);

    switch (*(u32 *)(self + 0x20)) {
    case 1:
        PSMTXRotRad(rx, 0x58, lbl_80368EEC * *(f32 *)(self + 0x30));
        PSMTXRotRad(ry, 0x59, lbl_80368EEC * *(f32 *)(self + 0x34));
        PSMTXRotRad(rz, 0x5A, lbl_80368EEC * *(f32 *)(self + 0x38));
        break;
    case 2:
        PSMTXRotRad(rx, 0x59, lbl_80368EEC * *(f32 *)(self + 0x34));
        PSMTXRotRad(ry, 0x5A, lbl_80368EEC * *(f32 *)(self + 0x38));
        PSMTXRotRad(rz, 0x58, lbl_80368EEC * *(f32 *)(self + 0x30));
        break;
    case 3:
        PSMTXRotRad(rx, 0x5A, lbl_80368EEC * *(f32 *)(self + 0x38));
        PSMTXRotRad(ry, 0x58, lbl_80368EEC * *(f32 *)(self + 0x30));
        PSMTXRotRad(rz, 0x59, lbl_80368EEC * *(f32 *)(self + 0x34));
        break;
    case 4:
        PSMTXRotRad(rx, 0x58, lbl_80368EEC * *(f32 *)(self + 0x30));
        PSMTXRotRad(ry, 0x5A, lbl_80368EEC * *(f32 *)(self + 0x38));
        PSMTXRotRad(rz, 0x59, lbl_80368EEC * *(f32 *)(self + 0x34));
        break;
    case 5:
        PSMTXRotRad(rx, 0x59, lbl_80368EEC * *(f32 *)(self + 0x34));
        PSMTXRotRad(ry, 0x58, lbl_80368EEC * *(f32 *)(self + 0x30));
        PSMTXRotRad(rz, 0x5A, lbl_80368EEC * *(f32 *)(self + 0x38));
        break;
    case 6:
        PSMTXRotRad(rx, 0x5A, lbl_80368EEC * *(f32 *)(self + 0x38));
        PSMTXRotRad(ry, 0x59, lbl_80368EEC * *(f32 *)(self + 0x34));
        PSMTXRotRad(rz, 0x58, lbl_80368EEC * *(f32 *)(self + 0x30));
        break;
    case 8:
        PSMTXScale(scale, *(f32 *)(self + 0x3C), *(f32 *)(self + 0x40), *(f32 *)(self + 0x44));
        PSMTXTrans(trans, *(f32 *)(self + 0x24), *(f32 *)(self + 0x28), *(f32 *)(self + 0x2C));
        QUATMtx(self + 0x24, rx);
        PSMTXConcat(rx, scale, out);
        PSMTXConcat(rx, out, out);
        PSMTXConcat(trans, out, out);
        goto draw;
    case 7:
        PSMTXCopy(self + 0x24, out);
        goto draw;
    default:
        Game_Assert(lbl_8026A660 + 0x2F7, 0xB8, lbl_8026A660 + 0x2FF);
        break;
    }
    PSMTXScale(scale, *(f32 *)(self + 0x3C), *(f32 *)(self + 0x40), *(f32 *)(self + 0x44));
    PSMTXTrans(trans, *(f32 *)(self + 0x24), *(f32 *)(self + 0x28), *(f32 *)(self + 0x2C));
    PSMTXConcat(rx, scale, out);
    PSMTXConcat(ry, out, out);
    PSMTXConcat(rz, out, out);
    PSMTXConcat(trans, out, out);
draw:
    pt[0] = lbl_8026A600[0];
    pt[1] = lbl_8026A600[1];
    pt[2] = lbl_8026A600[2];
    fn_802029C4(out, pt, pt);
    fx = *(f32 *)&pt[0];
    fy = *(f32 *)&pt[1];
    alpha = self[0x1F];
    fn_80051328(0, view, fx, fy, lbl_80368F00, lbl_80368F00, lbl_80368EE4);
    fn_80224E50(view, 0x1E, 0);
    fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
    color_tmp = lbl_80368EDC;
    *((u8 *)&color_tmp + 3) = alpha;
    color = color_tmp;
    fn_80051538(&color, 1, fx, fy);
    fn_80066D00(-1);
}

#pragma use_lmw_stmw reset

#pragma opt_peephole reset
#pragma opt_loop_invariants reset
#pragma use_lmw_stmw reset
void fn_80048A3C(s8 arg0, s8 arg1, s8 arg2, u8 *arg3) {
    extern s8 lbl_8036728C;
    extern s8 lbl_8036728D;
    extern s8 lbl_8036728E;
    extern u8 lbl_80367290[];
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u8 *p;

    a = arg3[0];
    b = arg3[1];
    c = arg3[2];
    d = arg3[3];
    p = lbl_80367290;
    lbl_8036728C = arg0;
    lbl_8036728D = arg1;
    lbl_8036728E = arg2;
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
}

void fn_80048A70(s8 arg0) {
    extern u8 gBattleState[];
    extern s8 gMapBlendMode;
    s8 var_r3;

    var_r3 = arg0;
    if ((u8) gBattleState[0xA6] != 1) {
        var_r3 = 0;
    }
    gMapBlendMode = var_r3;
}

void fn_80048A90(void *arg0)
{
    extern u8 lbl_80367288;
    extern u8 gMapBlendMode;
    extern u8 gBattleSkyIndex;
    extern u8 lbl_8036728C;
    extern u8 lbl_8036728D;
    extern u8 lbl_8036728E;
    extern u8 lbl_80367290[];
    extern u8 lbl_80367294;
    extern u8 lbl_80367295;
    extern u8 lbl_80367298[];
    extern u8 lbl_8036729C[];
    extern f32 lbl_80368F6C;

    u8 Stream_ReadU8(void *);
    u16 Stream_ReadU16(void *);
    void *Camera_GetActive(void);
    void fn_80019384(void *, u32);

    void *stream;
    u8 *camera;
    u8 value;
    s16 x;
    s16 y;
    s32 i;

    stream = arg0;

    lbl_80367288 = Stream_ReadU8(stream);
    gMapBlendMode = Stream_ReadU8(stream);
    gBattleSkyIndex = Stream_ReadU8(stream);
    lbl_8036728C = Stream_ReadU8(stream);
    lbl_8036728D = Stream_ReadU8(stream);
    lbl_8036728E = Stream_ReadU8(stream);

    lbl_80367290[0] = Stream_ReadU8(stream);
    lbl_80367290[1] = Stream_ReadU8(stream);
    lbl_80367290[2] = Stream_ReadU8(stream);

    lbl_80367294 = Stream_ReadU8(stream);
    lbl_80367295 = Stream_ReadU8(stream);

    lbl_80367298[0] = Stream_ReadU8(stream);
    lbl_80367298[1] = Stream_ReadU8(stream);
    lbl_80367298[2] = Stream_ReadU8(stream);

    lbl_8036729C[0] = Stream_ReadU8(stream);
    lbl_8036729C[1] = Stream_ReadU8(stream);
    lbl_8036729C[2] = Stream_ReadU8(stream);

    value = Stream_ReadU8(stream);
    x = (s16)Stream_ReadU16(stream);
    y = (s16)Stream_ReadU16(stream);

    camera = (u8 *)Camera_GetActive();

    if (camera != 0 && lbl_80367288 == 1) {
        fn_80019384(camera, value);

        *(f32 *)(camera + 4) =
            (f32)x * lbl_80368F6C;

        *(f32 *)(camera + 8) =
            (f32)y * lbl_80368F6C;
    }

    for (i = 0x16; i < 0x20; i++) {
        Stream_ReadU8(stream);
    }

    lbl_80367298[3] = 0xFF;
    lbl_8036729C[3] = 0xFF;
    lbl_80367290[3] = 0xFF;
    lbl_80367288 = 1;
}

void fn_80048C5C(s32 stream) {
void Stream_WriteU8(s32,u8); void Stream_WriteU16(s32,u16);
void *Camera_GetActive(void);
extern u8 lbl_80367288,gMapBlendMode,gBattleSkyIndex,lbl_8036728C,lbl_8036728D,lbl_8036728E,lbl_80367290,lbl_80367294,lbl_80367295,lbl_80367298,lbl_8036729C;
extern f32 lbl_80368F30;
u8 mode; s32 x; s32 y;
u8 *camera;
s32 i;
Stream_WriteU8(stream,lbl_80367288);
Stream_WriteU8(stream,gMapBlendMode);
Stream_WriteU8(stream,gBattleSkyIndex);
Stream_WriteU8(stream,lbl_8036728C);
Stream_WriteU8(stream,lbl_8036728D);
Stream_WriteU8(stream,lbl_8036728E);
Stream_WriteU8(stream,lbl_80367290);
Stream_WriteU8(stream,(&lbl_80367290)[1]);
Stream_WriteU8(stream,(&lbl_80367290)[2]);
Stream_WriteU8(stream,lbl_80367294);
Stream_WriteU8(stream,lbl_80367295);
Stream_WriteU8(stream,lbl_80367298);
Stream_WriteU8(stream,(&lbl_80367298)[1]);
Stream_WriteU8(stream,(&lbl_80367298)[2]);
Stream_WriteU8(stream,lbl_8036729C);
Stream_WriteU8(stream,(&lbl_8036729C)[1]);
Stream_WriteU8(stream,(&lbl_8036729C)[2]);
mode=0; x=0; y=0;
camera=Camera_GetActive();
if(camera) {
x=(s32)(lbl_80368F30 * *(f32 *)(camera+4));
y=(s32)(lbl_80368F30 * *(f32 *)(camera+8));
mode=(u8)*(u32 *)(camera+0x20);
}
Stream_WriteU8(stream,mode);
Stream_WriteU16(stream,x); Stream_WriteU16(stream,y);
for(i=22;i<32;i++) Stream_WriteU8(stream,0);
}

void fn_80048E08(s32 arg0, u32 arg1, void *arg2, s32 arg3) {
    void *fn_8000CAA0(void *);
    void *fn_8000CAF0(void *, s32);
    void fn_8005F7E0(s32, u8, u8, u8);
    void fn_8005F7B0(s32, u8);
    extern u8 lbl_80285738[];
    s32 sp8;
    u8 b;
    void *var_r3;
    u8 a;
    s32 temp_r31;

    if (arg3 == 0) {
        temp_r31 = arg0 + 0x14;
        sp8 = *(s32 *)arg2;
        fn_8005F7E0(temp_r31, ((u8 *)&sp8)[0], ((u8 *)&sp8)[1], ((u8 *)&sp8)[2]);
        fn_8005F7B0(temp_r31, ((u8 *)&sp8)[3]);
        return;
    }
    if (arg1 != 0U) {
        var_r3 = fn_8000CAA0(lbl_80285738);
    } else {
        var_r3 = fn_8000CAF0(lbl_80285738, 3);
    }
    b = ((u8 *)arg2)[1];
    a = ((u8 *)arg2)[0];
    ((u8 *)var_r3)[0x40] = a;
    a = ((u8 *)arg2)[2];
    ((u8 *)var_r3)[0x41] = b;
    b = ((u8 *)arg2)[3];
    ((u8 *)var_r3)[0x42] = a;
    ((u8 *)var_r3)[0x43] = b;
    *(s32 *)((u8 *)var_r3 + 0x38) = arg3;
    *(s32 *)((u8 *)var_r3 + 0x30) = arg0;
}

#pragma global_optimizer off
void fn_80048ECC(void *arg0) {
    f32 fn_80059EB8(s32, s32, f32, f32);
    f32 Math_Lerp(f32, f32, f32, f32);
    void Model_SetColor(void *, u8, u8, u8);
    void Model_SetAlpha(void *, u8);
    void Process_ClearFunc(void *);
    extern f32 lbl_80368EE4;
    extern f32 lbl_80368F70;
    u8 spC[4];
    s32 sp8;
    s32 t;
    void *model;

    *(s32 *)((u8 *)arg0 + 0x34) = *(s32 *)((u8 *)arg0 + 0x34) + 1;
    t = (s32)fn_80059EB8(*(s32 *)((u8 *)arg0 + 0x38), *(s32 *)((u8 *)arg0 + 0x34), lbl_80368EE4, lbl_80368F70);
    ((u8 *)spC)[0] = (s32)Math_Lerp((f32)t, (f32)*(u8 *)((u8 *)arg0 + 0x3c), lbl_80368F70, (f32)*(u8 *)((u8 *)arg0 + 0x40));
    ((u8 *)spC)[1] = (s32)Math_Lerp((f32)t, (f32)*(u8 *)((u8 *)arg0 + 0x3d), lbl_80368F70, (f32)*(u8 *)((u8 *)arg0 + 0x41));
    ((u8 *)spC)[2] = (s32)Math_Lerp((f32)t, (f32)*(u8 *)((u8 *)arg0 + 0x3e), lbl_80368F70, (f32)*(u8 *)((u8 *)arg0 + 0x42));
    ((u8 *)spC)[3] = (s32)Math_Lerp((f32)t, (f32)*(u8 *)((u8 *)arg0 + 0x3f), lbl_80368F70, (f32)*(u8 *)((u8 *)arg0 + 0x43));
    sp8 = *(s32 *)spC;
    model = (u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x14;
    Model_SetColor(model, ((u8 *)&sp8)[0], ((u8 *)&sp8)[1], ((u8 *)&sp8)[2]);
    Model_SetAlpha(model, ((u8 *)&sp8)[3]);
    if (*(s32 *)((u8 *)arg0 + 0x38) == *(s32 *)((u8 *)arg0 + 0x34)) {
        Process_ClearFunc(arg0);
    }
}
void fn_800490F0(void *arg0) {
    M2C_UNK Model_SetAlpha(s32, u8);
    M2C_UNK Model_SetColor(s32, u8, u8, u8);
    u8 sp[4];
    s32 temp_r31;

    *(u32 *)sp = *(u32 *)((u8 *)arg0 + 0x3C);
    temp_r31 = *(s32 *)((u8 *)arg0 + 0x30) + 0x14;
    Model_SetColor(temp_r31, sp[0], sp[1], sp[2]);
    Model_SetAlpha(temp_r31, sp[3]);
}

void fn_80049144(void *arg0) {
    void *temp_r5;

    temp_r5 = M2C_FIELD(arg0, void **, 0x30);
    M2C_FIELD(arg0, u8 *, 0x3C) = (u8) M2C_FIELD(temp_r5, u8 *, 0x1C);
    M2C_FIELD(arg0, u8 *, 0x3D) = (u8) M2C_FIELD(temp_r5, u8 *, 0x1D);
    M2C_FIELD(arg0, u8 *, 0x3E) = (u8) M2C_FIELD(temp_r5, u8 *, 0x1E);
    M2C_FIELD(arg0, u8 *, 0x3F) = (u8) M2C_FIELD(temp_r5, u8 *, 0x1F);
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
}

void fn_80049174(void *arg0, void *arg1, void *arg2, void *arg3) {
    void Model_SetColor(void *, u8, u8, u8);
    void Model_SetAlpha(void *, u8);
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, s32);
    extern u8 lbl_80285710[];

    u8 *self;
    u8 *color;
    u8 *process;
    u32 rgba;
    u8 *model;

    self = (u8 *)arg0;
    color = (u8 *)arg2;

    if (arg3 == NULL) {
        rgba = *(u32 *)color;
        model = self + 0x14;

        Model_SetColor(
            model,
            ((u8 *)&rgba)[0],
            ((u8 *)&rgba)[1],
            ((u8 *)&rgba)[2]
        );

        Model_SetAlpha(model, ((u8 *)&rgba)[3]);
        return;
    }

    if (arg1 != NULL) {
        process = Process_CreateChild(lbl_80285710, arg1);
    } else {
        process = Process_Create(lbl_80285710, 3);
    }

    process[0x40] = color[0];
    process[0x41] = color[1];
    process[0x42] = color[2];
    process[0x43] = color[3];

    *(void **)(process + 0x38) = arg3;
    *(void **)(process + 0x30) = arg0;
}

void fn_80049238(void *arg0) {
f32 Math_Lerp(f32,f32,f32,f32);
void Model_SetColor(void *,u8,u8,u8);
void Model_SetAlpha(void *,u8);
void Process_ClearFunc(void *);
struct Color { u8 r,g,b,a; } color,copy;
struct Proc { u8 pad[0x30]; u8 *model; s32 frame,duration; u8 start[4],end[4]; };
struct Proc *proc=(struct Proc*)arg0;
void *model;
++proc->frame;
color.r=(s32)Math_Lerp((f32)proc->start[0],(f32)proc->end[0],(f32)proc->duration,(f32)proc->frame);
color.g=(s32)Math_Lerp((f32)proc->start[1],(f32)proc->end[1],(f32)proc->duration,(f32)proc->frame);
color.b=(s32)Math_Lerp((f32)proc->start[2],(f32)proc->end[2],(f32)proc->duration,(f32)proc->frame);
color.a=(s32)Math_Lerp((f32)proc->start[3],(f32)proc->end[3],(f32)proc->duration,(f32)proc->frame);
model=proc->model+0x14;
copy=color;
Model_SetColor(model,copy.r,copy.g,copy.b);
Model_SetAlpha(model,copy.a);
if(proc->duration==proc->frame) Process_ClearFunc(arg0);
}

void fn_8004949C(void *arg0) {
    void Model_SetAlpha(s32, u8);
    void Model_SetColor(s32, u8, u8, u8);
    s32 sp8;
    s32 temp_r31;

    sp8 = *(s32 *)((u8 *)arg0 + 0x40);
    temp_r31 = *(s32 *)((u8 *)arg0 + 0x30) + 0x14;
    Model_SetColor(temp_r31, ((u8 *)&sp8)[0], ((u8 *)&sp8)[1], ((u8 *)&sp8)[2]);
    Model_SetAlpha(temp_r31, ((u8 *)&sp8)[3]);
}

void fn_800494F0(void *arg0) {
    void *temp_r5;

    temp_r5 = M2C_FIELD(arg0, void **, 0x30);
    M2C_FIELD(arg0, u8 *, 0x3C) = (u8) M2C_FIELD(temp_r5, u8 *, 0x1C);
    M2C_FIELD(arg0, u8 *, 0x3D) = (u8) M2C_FIELD(temp_r5, u8 *, 0x1D);
    M2C_FIELD(arg0, u8 *, 0x3E) = (u8) M2C_FIELD(temp_r5, u8 *, 0x1E);
    M2C_FIELD(arg0, u8 *, 0x3F) = (u8) M2C_FIELD(temp_r5, u8 *, 0x1F);
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
}

void fn_80049520(s32 arg0, u32 arg1, s32 arg2, f32 farg0) {
    void *Process_CreateChild(void *);
    void *Process_Create(void *, s32);
    extern u8 lbl_802856E8[];
    void *var_r3;

    if (arg1 != 0U) {
        var_r3 = Process_CreateChild(lbl_802856E8);
    } else {
        var_r3 = Process_Create(lbl_802856E8, 3);
    }
    *(f32 *)((char *)var_r3 + 0x38) = farg0;
    *(s32 *)((char *)var_r3 + 0x3C) = arg2;
    *(s32 *)((char *)var_r3 + 0x30) = arg0;
}

s32 fn_80049594(s32 arg0, s32 arg1, s32 arg2)
{
    if (arg0 < 0 || arg1 < 0 || arg2 < 0) {
        return -1;
    }

    if ((u32)(arg0 + 0x40) > 0xFFFF || (u32)(arg1 + 0x40) > 0xFFFF || (u32)(arg2 + 0x40) > 0xFFFF) {
        return -1;
    }

    return 0;
}

void fn_8004982C(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x48);
}

void fn_8004983C(void *arg0) {
    extern f32 lbl_80368F74;
    extern f32 lbl_80368F78;
    struct Obj {
        u8 pad[0x30];
        f32 *ptr;
        u8 pad2[4];
        f32 unk38;
        u8 pad3[4];
        s32 flag;
        f32 a;
        f32 b;
    };
    struct Obj *obj = (struct Obj *)arg0;
    f32 diff;

    obj->flag = 0;
    obj->a = obj->ptr[2];
    obj->b = obj->unk38;
    diff = (f32)__fabs((f64)(obj->a - obj->b));
    if (diff > lbl_80368F74) {
        if (obj->a < obj->b) {
            obj->a = obj->a + lbl_80368F78;
            return;
        }
        if (obj->a > obj->b) {
            obj->b = obj->b + lbl_80368F78;
        }
    }
}

void fn_800498A4(void *arg0, void *arg1, u8 arg2)
{
    extern u8 lbl_802856C8[];
    extern f32 lbl_80368EE4;
    extern f32 lbl_80368F10;
    extern f32 lbl_80368F2C;
    extern f32 lbl_80368F00;

    void fn_8005FEE8(void *, f32);
    void *Process_CreateEx(void *);

    u8 *obj;
    u8 *node;
    u8 *process;
    s32 mode;
    u32 flags;
    u8 enabled;
    s32 x;
    s32 y;

    obj = (u8 *)arg0;
    flags = *(u32 *)(*(u8 **)(obj + 0x10) + 0xBC);

    if (flags & 0x400) {
        if (flags & 0x200) {
            enabled = 1;
        } else {
            enabled = 0;
        }
    } else {
        enabled = 0;
    }

    if (enabled != 0) {
        mode = (u8)arg2;
        node = obj + 0x14;

        switch (mode) {
        case 3:
            fn_8005FEE8(node, lbl_80368EE4);
            *(f32 *)(node + 0x5C) = lbl_80368F10;
            break;

        case 4:
            fn_8005FEE8(node, lbl_80368F2C);
            *(f32 *)(node + 0x5C) = lbl_80368F10;
            break;
        }
    } else {
        mode = (u8)arg2;
        node = obj + 0x14;

        process = (u8 *)Process_CreateEx(lbl_802856C8);

        *(void **)(process + 0x34) = node;
        *(void **)(process + 0x30) = obj;
        *(s32 *)(process + 0x44) = mode;
        process[0x48] = 0;

        x = (s8)obj[4] + (s8)obj[6];
        y = (s8)obj[5] + (s8)obj[7];

        *(f32 *)(process + 0x38) = (f32)x * lbl_80368F00;
        *(f32 *)(process + 0x3C) = (f32)y * lbl_80368F00;
        *(f32 *)(process + 0x40) = *(f32 *)(obj + 0xC);

        switch (mode) {
        case 0:
            fn_8005FEE8(node, lbl_80368EE4);
            *(f32 *)(node + 0x5C) = lbl_80368F10;
            break;

        case 1:
            fn_8005FEE8(node, lbl_80368F2C);
            *(f32 *)(node + 0x5C) = lbl_80368F2C;
            break;
        }
    }
}

void fn_80049A3C(void *arg0)
{
    void fn_8005FEE8(void *, f32);
    extern f32 lbl_80368EE4;
    extern f32 lbl_80368F2C;
    f32 zero;

    if (*(u8 *)((u8 *)arg0 + 0x48) == 0) {
        zero = lbl_80368EE4;
        if (*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x5c) > zero) {
            fn_8005FEE8((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x14, lbl_80368F2C);
        } else {
            fn_8005FEE8((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x14, zero);
        }
    }
}

void fn_80049A98(void *arg0) {
    void fn_8004AE28(void *, f32, f32, f32);
    u8 Pad_IsButton(void *, s32);
    void fn_80060060(void *);
    void Process_ClearFunc(void *);
    void *p;

    p = *(void **)((u8 *)arg0 + 0x34);
    fn_80060060(p);
    p = *(void **)((u8 *)arg0 + 0x34);
    if (*(u32 *)p & 0x10) {
        Process_ClearFunc(arg0);
        return;
    }
    if (Pad_IsButton(p, 8) != 0) {
        *(u8 *)((u8 *)arg0 + 0x48) = 1;
        Process_ClearFunc(arg0);
        return;
    }
    fn_8004AE28(*(void **)((u8 *)arg0 + 0x34),
                *(f32 *)((u8 *)arg0 + 0x38),
                *(f32 *)((u8 *)arg0 + 0x3C),
                *(f32 *)((u8 *)arg0 + 0x40));
}

#pragma global_optimizer off
void MapObj_FadeIn(void *arg0,u8 arg1) { void fn_8005FEE8(void *,f32); void fn_80044450(void *,s32); void fn_80016180(void); extern u32 gMap; u8 *ptr=arg0; ptr[2]&=~2; fn_8005FEE8(ptr+0x14,0.0f); if(arg1) {fn_80044450((void*)gMap,1); fn_80016180();} }
#pragma global_optimizer reset
void MapObj_FadeOut(void *arg0, u8 arg1) {
    void fn_8005FEE8(void *, f32);
    void fn_80044450(s32, s32);
    void fn_80016180(void);
    extern f32 lbl_80368F2C;
    extern u16 *gMap;
    u8 temp;

    temp = *(u8 *)((u8 *)arg0 + 2);
    temp |= 2;
    *(u8 *)((u8 *)arg0 + 2) = temp;

    fn_8005FEE8((u8 *)arg0 + 0x14, -1.0f);

    if (arg1 != 0) {
        fn_80044450((s32)gMap, 1);
        fn_80016180();
    }
}

extern u16* gMap;
void MapObj_Show(void *arg0, u8 arg1) {
    void Model_SetAlpha(void *, s32, void *);
    void fn_80044450(s32, s32);
    void fn_80016180(void);
    extern u16 *gMap;
    u8 temp;

    temp = *(u8 *)((u8 *)arg0 + 2);
    temp &= 0xFC;
    *(u8 *)((u8 *)arg0 + 2) = temp;

    Model_SetAlpha((u8 *)arg0 + 0x14, 0xFF, arg0);

    if (arg1 != 0) {
        fn_80044450((s32)gMap, 1);
        fn_80016180();
    }
}

void MapObj_Hide(void *arg0, u8 arg1)
{
    void Model_SetAlpha(void *, s32, void *);
    void fn_80044450(s32, s32);
    void fn_80016180(void);
    extern u16 *gMap;
    u8 temp;

    temp = *(u8 *)((u8 *)arg0 + 2);
    temp |= 3;
    *(u8 *)((u8 *)arg0 + 2) = temp;

    Model_SetAlpha((u8 *)arg0 + 0x14, 0, arg0);

    if (arg1 != 0) {
        fn_80044450((s32)gMap, 1);
        fn_80016180();
    }
}

void fn_80049C8C(void *arg0, u8 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, u8 *, 2) = (u8) (M2C_FIELD(arg0, u8 *, 2) & 0xFE);
        return;
    }
    M2C_FIELD(arg0, u8 *, 2) = (u8) (M2C_FIELD(arg0, u8 *, 2) | 1);
}

void fn_80049CB4(s32 arg0, void *arg1) {
    M2C_UNK Model_SetAlpha(s32, u8);
    M2C_UNK Model_SetColor(s32, u8, u8, u8);
    s32 temp_r31;

    temp_r31 = arg0 + 0x14;
    Model_SetColor(temp_r31, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1), M2C_FIELD(arg1, u8 *, 2));
    Model_SetAlpha(temp_r31, M2C_FIELD(arg1, u8 *, 3));
}

void fn_80049D08(s32 arg0) {
    void fn_8005FEE8(s32, f32);
    fn_8005FEE8(arg0 + 0x14, -1.0f);
}
void fn_80049D30(s32 arg0) {
    void fn_8005FEE8(s32, f32);
    fn_8005FEE8(arg0 + 0x14, 0.0f);
}

s32 MapObj_IsVisible(void *arg0) {
    return (M2C_FIELD(arg0, u8 *, 2) & 3) == 0;
}

s32 MapObj_IsHidden(void *arg0) {
    return (M2C_FIELD(arg0, u8 *, 2) & 3) != 0;
}

#pragma global_optimizer off
s32 fn_80049D84(s32 arg0) {
    arg0 = *(s32 *)(arg0 + 0x10);
    arg0 = *(s32 *)(arg0 + 0xBC);
    if (arg0 & 0x400) {
        return 0;
    }
    return (arg0 >> 9) & 1;
}
#pragma global_optimizer reset
void *fn_80049DA4(s32 arg0, s32 arg1, u32 arg2) {
    void strcpy(void *, s32);
    void strcat(void *, s32);
    extern u8 lbl_802EFE20[64];

    strcpy(lbl_802EFE20, arg0);
    strcat(lbl_802EFE20, arg1);
    if (arg2 != 0) {
        strcat(lbl_802EFE20, arg2);
    }
    return lbl_802EFE20;
}

s32 fn_80049E1C(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x10);
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void Map_DrawRangeTiles(void) {
    /* Draw GX quads for map tiles flagged as movement/range overlays. */
    u8 fn_800AA188(void);
    void GXClearVtxDesc(void);
    void GXSetVtxDesc(s32, s32);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetChanMatColor(s32, void *);
    void GXSetNumTevStages(s32);
    void GXSetNumTexGens(s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void PSMTXTrans(void *, f32, f32, f32);
    void *Camera_GetViewMtx(void);
    void PSMTXConcat(void *, void *, void *);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetTevSwapMode(s32, s32, s32);
    void GXSetTevSwapModeTable(s32, s32, s32, s32, s32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void fn_80222C50(void *, s32);
    void GXBegin(s32, s32, s32);
    f32 Map_GetTileCornerHeight(void *, s8, s8, s32);
    void fn_80066D00(s32);
    extern s32 gUiInputFlags;
    extern u32 lbl_80368F80;
    extern f32 gMapColorDrawZero;
    extern f32 gMapColorDrawZBias;
    extern f32 lbl_80368F8C;
    extern f64 lbl_80368F90;
    extern s32 gUiRouteAtlas;
    extern u8 gBattleMap[];
    u32 matColor;
    f32 mtx[12];
    u8 texBuf[16][32];
    s32 pos;
    s32 yOff;
    s8 y;
    s8 x;
    s32 texId;
    u8 *p;
    s32 i;
    u16 tile;
    f32 fx;
    f32 fy;
    f32 fx1;
    f32 fy1;
    f32 z;
    s32 texIdx;

    if (fn_800AA188() != 0 && !(gUiInputFlags & 0x1000)) {
        GXClearVtxDesc();
        GXSetVtxDesc(9, 1);
        GXSetVtxDesc(0xD, 1);
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);
        GXSetVtxAttrFmt(0, 0xD, 1, 0, 0);
        GXSetCullMode(1);
        GXSetBlendMode(4, 0, 0, 0, 0, 0, 2);
        matColor = lbl_80368F80;
        GXSetChanMatColor(4, &matColor);
        GXSetNumTevStages(1);
        GXSetNumTexGens(0, 0);
        GXSetTevOrder(0, 0, 0, 4);
        GXSetNumChans(1);
        fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
        PSMTXTrans(mtx, gMapColorDrawZero, gMapColorDrawZero, gMapColorDrawZBias);
        PSMTXConcat(Camera_GetViewMtx(), mtx, mtx);
        GXLoadPosMtxImm(mtx, 0);
        GXSetCurrentMtx(0);
        fn_802245D8(1, 4, 5, 0);
        GXSetTevSwapMode(0, 0, 3);
        GXSetTevSwapModeTable(3, 0, 1, 2, 0);
        texId = gUiRouteAtlas;
        p = &texBuf[0][0];
        i = 0;
        do {
            Ui_LoadAtlasTex(texId, p, i + 1);
            i += 1;
            p += 0x20;
        } while (i < 0x10);
        y = *(s32 *)(gBattleMap + 4) - 1;
        yOff = y << 6;
        goto y_test;
        do {
            x = *(s32 *)gBattleMap - 1;
            pos = x + yOff;
            goto x_test;
            do {
                tile = *(u16 *)(gBattleMap + 0x1218E + (pos << 1));
                if (tile & 0x2000) {
                    texIdx = (tile >> 4) & 15;
                    fn_80222C50(texBuf[texIdx], 0);
                    fx = (f32)x;
                    fy = (f32)y;
                    fx1 = lbl_80368F8C + fx;
                    fy1 = lbl_80368F8C + fy;
                    GXBegin(0x98, 0, 4);
                    z = Map_GetTileCornerHeight(gBattleMap, x, y, 0);
                    *(f32 *)0xCC008000 = fx;
                    *(f32 *)0xCC008000 = fy;
                    *(f32 *)0xCC008000 = z;
                    *(u8 *)0xCC008000 = 0;
                    *(u8 *)0xCC008000 = 0;
                    z = Map_GetTileCornerHeight(gBattleMap, x, y, 1);
                    *(f32 *)0xCC008000 = fx1;
                    *(f32 *)0xCC008000 = fy;
                    *(f32 *)0xCC008000 = z;
                    *(u8 *)0xCC008000 = 1;
                    *(u8 *)0xCC008000 = 0;
                    z = Map_GetTileCornerHeight(gBattleMap, x, y, 2);
                    *(f32 *)0xCC008000 = fx;
                    *(f32 *)0xCC008000 = fy1;
                    *(f32 *)0xCC008000 = z;
                    *(u8 *)0xCC008000 = 0;
                    *(u8 *)0xCC008000 = 1;
                    z = Map_GetTileCornerHeight(gBattleMap, x, y, 3);
                    *(f32 *)0xCC008000 = fx1;
                    *(f32 *)0xCC008000 = fy1;
                    *(f32 *)0xCC008000 = z;
                    *(u8 *)0xCC008000 = 1;
                    *(u8 *)0xCC008000 = 1;
                }
                pos -= 1;
                x -= 1;
            x_test:
                ;
            } while (x >= 0);
            yOff -= 0x40;
            y -= 1;
        y_test:
            ;
        } while (y >= 0);
        GXSetTevSwapMode(0, 0, 0);
        GXSetTevSwapModeTable(3, 0, 1, 2, 3);
        fn_80066D00(-1);
    }
}
#pragma global_optimizer reset

void Map_HideMoveLimitView(void) {
    extern u8 gMoveLimitViewProc[];
    extern u32 gUiInputFlags;
    void Process_UnlinkByKey(void *);
    Process_UnlinkByKey(gMoveLimitViewProc);
    gUiInputFlags &= ~0x400u;
}

void Map_ShowMoveLimitView(void) {
    void *Process_Create(void *, s32);
    extern u8 gMoveLimitViewProc[];
    extern u32 gUiInputFlags;
    void *p;

    p = Process_Create(gMoveLimitViewProc, 4);
    *(s32 *)((u8 *)p + 0x30) = 0;
    gUiInputFlags |= 0x400;
}

void fn_8004A264(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void fn_8006785C(s32, void *, void *);
    void fn_8004A2EC(void *);
    extern f32 gMapColorDrawZero;
    extern f32 lbl_80368F8C;
    extern f32 lbl_80368F98;
    s32 temp_r0;

    *(s32 *)((u8 *)arg0 + 0x30) = *(s32 *)((u8 *)arg0 + 0x30) + 1;
    temp_r0 = *(s32 *)((u8 *)arg0 + 0x30);
    if (temp_r0 <= 8) {
        *(f32 *)((u8 *)arg0 + 0x34) = Math_Ease(6, gMapColorDrawZero, lbl_80368F8C, (f32)temp_r0, lbl_80368F98);
    }
    fn_8006785C(2, fn_8004A2EC, arg0);
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8004A2EC(void *arg0) {
u8 fn_800AA188(void);
void GXClearVtxDesc(void);
void GXSetVtxDesc(s32, s32);
void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
void GXSetCullMode(s32);
void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
void GXSetNumTevStages(s32);
void GXSetNumTexGens(s32, s32);
void GXSetTevOrder(s32, s32, s32, s32);
void GXSetNumChans(s32);
void fn_802201A8(s32, s32, s32, s32, s32, s32);
void fn_8022100C(s32);
void PSMTXTrans(void *, f32, f32, f32);
void *Camera_GetViewMtx(void);
void PSMTXConcat(void *, void *, void *);
void GXLoadPosMtxImm(void *, s32);
void GXSetCurrentMtx(s32);
void fn_802245D8(s32, s32, s32, s32);
void GXBegin(s32, s32, s32);
f32 Map_GetTileCornerHeight(void *, s8, s8, s32);
void fn_80066D00(s32);
extern f32 gMapColorDrawZero;
extern f32 gMapColorDrawZBias;
extern f32 lbl_80368F8C;
extern f64 lbl_80368F90;
extern u8 gBattleMap[];
extern u8 lbl_80285828[];
    f32 sp8[12];
    u8 *ca;
    u8 *row;
    s32 yOff;
    s32 y1;
    s32 idx;
    u8 *cell;
    u8 *pal;
    void *self;
    s8 x;
    s8 y;
    f32 k8c;
    f64 k90;
    f32 f31v;
    f32 margin;
    f32 f25v, f26v, f27v, f28v;
    f32 z;
    s32 th;

    self = arg0;
    if (fn_800AA188() != 0) {
        GXClearVtxDesc();
        GXSetVtxDesc(9, 1);
        GXSetVtxDesc(0xB, 1);
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);
        GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
        GXSetCullMode(1);
        GXSetBlendMode(4, 0, 0, 1, 0, 0, 2);
        GXSetNumTevStages(1);
        GXSetNumTexGens(0, 4);
        GXSetTevOrder(0, 0xFF, 0xFF, 4);
        GXSetNumChans(0);
        fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
        fn_8022100C(0);
        PSMTXTrans(sp8, gMapColorDrawZero, gMapColorDrawZero, gMapColorDrawZBias);
        PSMTXConcat(Camera_GetViewMtx(), sp8, sp8);
        GXLoadPosMtxImm(sp8, 0);
        GXSetCurrentMtx(0);
        fn_802245D8(1, 4, 1, 0);
        ca = gBattleMap;
        k8c = lbl_80368F8C;
        pal = lbl_80285828;
        k90 = lbl_80368F90;
        y = *(s32 *)(ca + 4) - 1;
        yOff = y << 6;
        row = ca + yOff;
        goto y_test;
        do {
            y1 = (s8)y + 1;
            x = *(s32 *)ca - 1;
            idx = x + yOff;
            cell = row + x;
            f31v = k8c + (f32)(s8)y;
            goto x_test;
            do {
                if ((s8)*(cell + 0xE18E) == 0) {
                    th = *(s16 *)(gBattleMap + (idx << 1) + 0x610E);
                    if (th >= 0) {
                        margin = *(f32 *)((u8 *)self + 0x34);
                        f26v = f31v - margin;
                        f25v = (f32)x;
                        f27v = f25v + margin;
                        f28v = (f32)y1;
                        GXBegin(0x98, 0, 4);
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 0);
                        *(f32 *)0xCC008000 = f25v;
                        *(f32 *)0xCC008000 = f26v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x10];
                        *(u8 *)0xCC008000 = pal[0x11];
                        *(u8 *)0xCC008000 = pal[0x12];
                        *(u8 *)0xCC008000 = pal[0x13];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 1);
                        *(f32 *)0xCC008000 = f27v;
                        *(f32 *)0xCC008000 = f26v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x14];
                        *(u8 *)0xCC008000 = pal[0x15];
                        *(u8 *)0xCC008000 = pal[0x16];
                        *(u8 *)0xCC008000 = pal[0x17];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 2);
                        *(f32 *)0xCC008000 = f25v;
                        *(f32 *)0xCC008000 = f28v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x18];
                        *(u8 *)0xCC008000 = pal[0x19];
                        *(u8 *)0xCC008000 = pal[0x1A];
                        *(u8 *)0xCC008000 = pal[0x1B];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 3);
                        *(f32 *)0xCC008000 = f27v;
                        *(f32 *)0xCC008000 = f28v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x1C];
                        *(u8 *)0xCC008000 = pal[0x1D];
                        *(u8 *)0xCC008000 = pal[0x1E];
                        *(u8 *)0xCC008000 = pal[0x1F];
                    } else if (*(u16 *)(gBattleMap + (idx << 1) + 0xC18E) != 0) {
                        margin = *(f32 *)((u8 *)self + 0x34);
                        f27v = f31v - margin;
                        f28v = (f32)x;
                        f26v = f28v + margin;
                        f25v = (f32)y1;
                        GXBegin(0x98, 0, 4);
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 0);
                        *(f32 *)0xCC008000 = f28v;
                        *(f32 *)0xCC008000 = f27v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x20];
                        *(u8 *)0xCC008000 = pal[0x21];
                        *(u8 *)0xCC008000 = pal[0x22];
                        *(u8 *)0xCC008000 = pal[0x23];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 1);
                        *(f32 *)0xCC008000 = f26v;
                        *(f32 *)0xCC008000 = f27v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x24];
                        *(u8 *)0xCC008000 = pal[0x25];
                        *(u8 *)0xCC008000 = pal[0x26];
                        *(u8 *)0xCC008000 = pal[0x27];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 2);
                        *(f32 *)0xCC008000 = f28v;
                        *(f32 *)0xCC008000 = f25v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x28];
                        *(u8 *)0xCC008000 = pal[0x29];
                        *(u8 *)0xCC008000 = pal[0x2A];
                        *(u8 *)0xCC008000 = pal[0x2B];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 3);
                        *(f32 *)0xCC008000 = f26v;
                        *(f32 *)0xCC008000 = f25v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x2C];
                        *(u8 *)0xCC008000 = pal[0x2D];
                        *(u8 *)0xCC008000 = pal[0x2E];
                        *(u8 *)0xCC008000 = pal[0x2F];
                    }
                }
                cell -= 1;
                idx -= 1;
                x -= 1;
            x_test:
                ;
            } while ((s8)x >= 0);
            row -= 0x40;
            yOff -= 0x40;
            y -= 1;
        y_test:
            ;
        } while ((s8)y >= 0);
        fn_80066D00(-1);
    }
}
#pragma global_optimizer on

#pragma global_optimizer off
void fn_8004A864(s32 x,s32 y,u8 *color) {
void GXBegin(s32,s32,s32);
f32 fn_800233D0(void *,s8,s8,s32);
extern u8 gBattleMap[];
GXBegin(0x98,0,4);
Map_WriteColorVertex((f32)(x),(f32)(y),fn_800233D0(gBattleMap,(s8)x,(s8)y,0),color);
Map_WriteColorVertex((f32)(x+1),(f32)(y),fn_800233D0(gBattleMap,(s8)x,(s8)y,1),color);
Map_WriteColorVertex((f32)(x),(f32)(y+1),fn_800233D0(gBattleMap,(s8)x,(s8)y,2),color);
Map_WriteColorVertex((f32)(x+1),(f32)(y+1),fn_800233D0(gBattleMap,(s8)x,(s8)y,3),color);
}
#pragma global_optimizer on
/* Set up GX for untextured POS+CLR0 map color overlays and load the camera view with a small Z bias. */
void Map_SetupColorGx(void) {
    void *Camera_GetViewMtx(void);
    void PSMTXConcat(void *, f32 *, f32 *);
    void PSMTXTrans(f32 *, f32, f32, f32);
    void GXSetVtxDesc(s32, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void fn_8022100C(s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXLoadPosMtxImm(f32 *, s32);
    void GXSetCurrentMtx(s32);
    extern f32 gMapColorDrawZero;
    extern f32 gMapColorDrawZBias;
    f32 mtx[14];

    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(0, GX_VA_POS, 1, 4, 0);
    GXSetVtxAttrFmt(0, GX_VA_CLR0, 1, 5, 0);
    GXSetCullMode(1);
    GXSetBlendMode(4, 0, 0, 1, 0, 0, 2);
    GXSetNumTevStages(1);
    GXSetNumTexGens(0, 4);
    GXSetTevOrder(0, GX_VA_NULL, GX_VA_NULL, 4);
    GXSetNumChans(0);
    fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
    fn_8022100C(0);
    PSMTXTrans(mtx, gMapColorDrawZero, gMapColorDrawZero, gMapColorDrawZBias);
    PSMTXConcat(Camera_GetViewMtx(), mtx, mtx);
    GXLoadPosMtxImm(mtx, 0);
    GXSetCurrentMtx(0);
    fn_802245D8(1, 4, 1, 0);
}

s32 fn_8004ABD4(void **arg0, u8 arg1) {
    void *Item_GetFlagsPtr(void **);
    u8 Item_GetMaxRange();
    u8 var_r0;
    u8 var_r0_2;
    u8 var_r0_3;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;

    if (arg0 != NULL) {
        if (arg1 == 0) {
            if ((void *) *arg0 != NULL) {
                var_r0 = Item_GetMaxRange();
            } else {
                var_r0 = 0;
            }
            if ((var_r0 > 1U) && (temp_r3 = Item_GetFlagsPtr(arg0), (((((M2C_FIELD(temp_r3, s32 *, 4) & 0x40) ^ 0) | ((M2C_FIELD(temp_r3, s32 *, 0) & 0) ^ 0)) == 0) != 0))) {
                temp_r3_2 = *arg0;
                if (temp_r3_2 != NULL) {
                    var_r0_2 = M2C_FIELD(temp_r3_2, u8 *, 0x12);
                } else {
                    var_r0_2 = 0xC;
                }
                switch ((s32) var_r0_2) {           /* switch 1; irregular */
                case 2:                             /* switch 1 */
                    return 3;
                case 1:                             /* switch 1 */
                    return 5;
                }
            } else {
                goto block_16;
            }
        } else {
block_16:
            temp_r3_3 = *arg0;
            if (temp_r3_3 != NULL) {
                var_r0_3 = M2C_FIELD(temp_r3_3, u8 *, 0x12);
            } else {
                var_r0_3 = 0xC;
            }
            switch ((s32) var_r0_3) {               /* switch 2; irregular */
            case 1:                                 /* switch 2 */
                return 4;
            case 3:                                 /* switch 2 */
                return 6;
            case 8:                                 /* switch 2 */
                return 0;
            case 2:                                 /* switch 2 */
                return 2;
            case 0:                                 /* switch 2 */
                return 1;
            }
        }
    } else {
        return 0;
    }
}

void fn_8004AD20(void *arg0, f32 *arg1) {
    s32 fn_80146B10(s32);
    void DebugPrint(void *, ...);
    void SeCue_PlayAt(void *, s32, f32, f32, f32);
    void Ui_PlaySeCue(void *, s32);

    extern u16 lbl_8026A9B0[40];
    extern f32 lbl_80368FA0;

    u16 *entry;
    s32 cue;
    s32 i;
    f32 x;
    f32 y;
    f32 z;

    z = arg1[2];
    y = arg1[1];
    x = arg1[0];

    entry = (u16 *)arg0;
    i = 0;

    while (i < 4) {
        u16 id = *(u16 *)((u8 *)entry + 0x7C);

        if (id == 0xFFFF) {
            cue = 0;
        } else if (id < 0x3E8) {
            cue = 0;
        } else {
            cue = fn_80146B10(id);
        }

        if (cue != 0) {
            DebugPrint(
                (u8 *)lbl_8026A9B0 + 0x8A,
                cue
            );

            if (z > lbl_80368FA0) {
                SeCue_PlayAt((void *)cue, 0x64, x, y, z);
            } else {
                Ui_PlaySeCue((void *)cue, 0x64);
            }
        }

        i++;
        entry++;
    }
}

void fn_8004AE28(void *arg0, f32 x, f32 y, f32 z) {
#pragma global_optimizer off
 void *fn_80146B10(s32);
 void DebugPrint(void *, ...);
 void SeCue_PlayAt(void *, s32, f32, f32, f32);
 void Ui_PlaySeCue(void *, s32);
 extern u16 lbl_8026A9B0[40];
 extern f32 lbl_80368FA0;
 u16 *entry;
 void *cue;
 s32 i;
 entry=(u16 *)arg0;
 i=0;
 while(i<4) {
 u16 id=*(u16 *)((u8 *)entry+0x7C);
 if(id==0xFFFF) cue=0;
 else if(id<0x3E8) cue=0;
 else cue=fn_80146B10(id);
 if(cue) {
 DebugPrint((u8 *)lbl_8026A9B0+0x8A,cue);
 if(z>lbl_80368FA0) SeCue_PlayAt(cue,0x64,x,y,z);
 else Ui_PlaySeCue(cue,0x64);
 }
 i++; entry++;
 }
#pragma global_optimizer on
}

s32 fn_8004AF30(u16 arg0) {
 s32 fn_80146B10(u32);
 if(arg0 == 0xFFFF) return 0;
 if(arg0 < 0x3E8) return 0;
 return fn_80146B10(arg0);
}

#pragma peephole on
s32 fn_8004AF74(u8 *arg0, s32 arg1) {
    s32 v = (arg0 + arg1)[0xc];
    if (v / 64 == 0 && (v % 64) < 0x20) {
        return 1;
    }
    return 0;
}
s32 fn_8004AFB4(void *arg0, s32 arg1) {
    return (M2C_FIELD(arg0, s32 *, 0x10) & (1 << arg1)) != 0;
}

char *fn_8004AFD4(void *arg0, s32 arg1) {
void fn_800056A0(s32); void sprintf(void *, void *, ...);
extern u8 lbl_8026A9B0[]; extern s32 lbl_80285880[]; extern s32 lbl_802858C4[]; extern u8 lbl_802EFFC8[];
if ((*(s32 *)((u8 *)arg0+0x10) & (1 << arg1)) == 0) {arg1=6; fn_800056A0(0);}
sprintf(lbl_802EFFC8,lbl_8026A9B0+0x9C,lbl_8026A9B0+0xA8,*(s32 *)((u8 *)arg0+4),lbl_80285880[arg1],lbl_802858C4[*(u8 *)((u8 *)arg0+8)]);
return (char *)lbl_802EFFC8;
}

typedef struct StringValueByte { u8 pad0[0xC]; u8 value; } StringValueByte;
char *fn_8004B078(void *arg0, s32 arg1) {
    void sprintf(void *, void *, ...);
    extern u8 lbl_8026A9B0[];
    extern u8 lbl_802EFFC8[];
    u8 *p = (u8 *)arg0;

    sprintf(lbl_802EFFC8, lbl_8026A9B0 + 0xAD, lbl_8026A9B0 + 0xA8,
            *(void **)(p + 4),
            (p + arg1)[0xC]);
    return (char *)lbl_802EFFC8;
}
void *fn_8004B0C8(void *arg0) {
    void sprintf(void *, void *, ...);
    extern u8 lbl_8026A9B0[];
    extern u8 lbl_802EFFC8[];

    sprintf(lbl_802EFFC8, lbl_8026A9B0 + 0xBC, lbl_8026A9B0 + 0xA8, *(s32 *)((u8 *)arg0 + 4));
    return lbl_802EFFC8;
}

extern u16 lbl_8026A9B0[40];
extern u16 lbl_802EFFC8[16];
void *fn_8004B110(void *arg0) {
    void sprintf(void *, void *, ...);

    sprintf(lbl_802EFFC8, (u8 *)lbl_8026A9B0 + 0xCB, (u8 *)lbl_8026A9B0 + 0xA8, *(s32 *)((u8 *)arg0 + 4));
    return lbl_802EFFC8;
}

void *fn_8004B158(void *arg0) {
    void sprintf(void *, void *, ...);

    sprintf(lbl_802EFFC8, (u8 *)lbl_8026A9B0 + 0xD7, (u8 *)lbl_8026A9B0 + 0xA8, *(s32 *)((u8 *)arg0 + 4));
    return lbl_802EFFC8;
}

s32 fn_8004B1A0(s32 arg0) {
    extern s32 lbl_802858C4[];
    return lbl_802858C4[arg0];
}

void fn_8004B1B4(u8 *arg0) {
    u8 Status_Test(u8 *, s32);
    void fn_8004FE98(u8 *, s32);

    if ((u8)Status_Test(arg0 + 0x1BC, 0x5C) != 0) {
        fn_8004FE98(arg0, 0xB);
        arg0[3] |= 0x10;
    } else {
        arg0[3] |= 0x20;
    }
}

void fn_8004B218(void) {
void Allegiance_FillMask(s32, void *);
s32 fn_8010424C(void *);
void PSMTXRotRad(void *, s32, f32);
void PSMTXScale(void *, f32, f32, f32);
void PSMTXTrans(void *, f32, f32, f32);
void PSMTXConcat(void *, void *, void *);
void Model_SetAlpha(void *, u8);
void fn_80060060(void *);
void fn_800609DC(void *);
void fn_8006CAD4(void *);
extern u8 gUnits[], lbl_802EFFE8[];
extern f32 lbl_80368FB8, lbl_80368FBC, lbl_80368FC0;
f32 rot[3][4], scale[3][4], trans[3][4];
u8 mask[8];
s32 id;
u8 *unit;
u8 *model;
Allegiance_FillMask(3,mask);
for(id=1;id<=159;id++) {
u8 valid;
s32 count;
unit=(u8)id ? gUnits+((u8)id-1)*0x280 : 0;
if(!M2C_FIELD(unit,void **,0x188)) continue;
if(!mask[M2C_FIELD(M2C_FIELD(unit,void **,0x190),u8 *,8)]) continue;
if(M2C_FIELD(unit,u32 *,0x1A0)&0x010000FC) valid=0;
else if((u8)(unit[3]&0x22)!=2) valid=0;
else if(!unit[0x27]) valid=0;
else valid=1;
if(!valid) continue;
model=unit+0xBC;
count=fn_8010424C(unit+0x1A4);
if(count>5)count=5;
if(count>0) {
M2C_FIELD(model,void **,4)=lbl_802EFFE8+(count-1)*0xA0;
PSMTXRotRad(rot,0x58,lbl_80368FB8);
PSMTXScale(scale,lbl_80368FBC,lbl_80368FBC,lbl_80368FBC);
PSMTXTrans(trans,M2C_FIELD(unit,f32 *,4)+M2C_FIELD(unit,f32 *,0x10),M2C_FIELD(unit,f32 *,8)+M2C_FIELD(unit,f32 *,0x14),(M2C_FIELD(unit,f32 *,0xC)+M2C_FIELD(unit,f32 *,0x18))-lbl_80368FC0);
PSMTXConcat(rot,scale,scale);
PSMTXConcat(trans,scale,model+0x10);
Model_SetAlpha(model,unit[0x27]);
fn_80060060(model);
fn_800609DC(model);
fn_8006CAD4(model);
}
}
}

extern s32 gGMaterialCurrent;
#pragma use_lmw_stmw on
s32 GMaterial_SetupAtlasTev(void *obj, s32 atlas) {
    s32 GMaterial_GetCurrent(void);
    s32 GMaterial_GetNode(void);
    s32 GMaterial_AllocTevStage(void);
    s32 GMaterial_AllocTexMap(void);
    s32 GMaterial_AllocTexCoord(void);
    void Ui_LoadAtlasTex(s32, void *, u16);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80222C50(void *, s32);
    void GXSetTevSwapModeTable(s32, s32, s32, s32, s32);
    void GXSetTevSwapMode(s32, s32, s32);
    void GXSetTevColorIn(s32, s32, s32, s32, s32);
    void GXSetTevColorOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
    void GXSetTevAlphaOp(s32, s32, s32, s32, s32, s32);
    void GMaterial_SetCullMode(s32, s32);
    void fn_800690D4(s32, s32, void *);
    void GMaterial_SetupColor(s32, s32, s32, void *);
    // Set up one TEV stage from an atlas tex (or color-only), then apply material color.
    u8 texBuf[0x20];
    s32 mat;
    s32 node;
    s32 owner;
    s32 tevStage;
    s32 texMap;
    s32 texCoord;

    mat = GMaterial_GetCurrent();
    node = GMaterial_GetNode();
    owner = *(s32 *)((u8 *)mat + 0x90);
    tevStage = GMaterial_AllocTevStage();
    if ((*(s32 *)mat & 0x2000) != 0) {
        GXSetTevOrder(tevStage, 0xFF, 0xFF, 4);
        GXSetNumTexGens(tevStage, 4);
    } else {
        Ui_LoadAtlasTex(atlas, texBuf, *(u16 *)((u8 *)(*(void **)((u8 *)obj + 0x14)) + 4));
        texMap = GMaterial_AllocTexMap();
        texCoord = GMaterial_AllocTexCoord();
        fn_802201A8(texCoord, 1, 4, 0x3C, 0, 0x7D);
        fn_80222C50(texBuf, texMap);
        GXSetTevOrder(tevStage, texCoord, texMap, 4);
        GXSetNumTexGens(tevStage, 0);
    }
    if ((*(s32 *)((u8 *)owner + 0x1A0) & 1) != 0) {
        GXSetTevSwapModeTable(1, 1, 1, 1, 3);
        GXSetTevSwapMode(tevStage, 0, 1);
        GXSetTevColorIn(tevStage, 0xF, 8, 0xA, 0xA);
        GXSetTevColorOp(tevStage, 0, 2, 3, 1, 0);
        GXSetTevAlphaIn(tevStage, 7, 4, 5, 7);
        GXSetTevAlphaOp(tevStage, 0, 0, 0, 1, 0);
    }
    GMaterial_SetCullMode(mat, node);
    fn_800690D4(mat, node, obj);
    GMaterial_SetupColor(mat, 0, node, obj);
    return 1;
}

#pragma use_lmw_stmw on
void fn_8004B588(u8 *arg0)
{
    f32 Math_Lerp(f32, f32, f32, f32);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void fn_80222C50(void *, s32);
    void PSMTXRotRad(void *, s32, f32);
    void fn_802026E4(void *, void *, void *, void *);
    void C_MTXLightOrtho(void *, f32, f32, f32, f32, f32, f32, f32, f32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXTrans(void *, f32, f32, f32);
    void fn_80224E50(void *, s32, s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80051564(void *, s32, f32, f32);
    extern u8 lbl_8026AA98[];
    extern s32 gUnitShadowMat;
    extern u32 lbl_80368FB4;
    extern f32 lbl_80368FBC;
    extern f32 lbl_80368FC4;
    extern f32 lbl_80368FC8;
    extern f32 lbl_80368FCC;
    extern f32 lbl_80368FD0;
    extern f32 lbl_80368FD4;
    extern f32 lbl_80368FD8;
    extern f32 lbl_80368FDC;
    extern f64 lbl_80368FE0;
    extern f64 lbl_80368FE8;
    u8 sp12C[0x30];
    u8 spFC[0x30];
    u8 spCC[0x30];
    u8 sp9C[0x30];
    u8 sp6C[0x30];
    u8 sp4C[0x50];
    u32 sp48;
    f32 sp44;
    f32 sp40;
    u32 sp3C;
    f32 sp38;
    f32 sp34;
    u32 sp30;
    u32 sp2C;
    u32 sp28;
    u32 sp24;
    f32 sp20;
    f32 sp1C;
    u32 sp18;
    f32 sp14;
    f32 sp10;
    u32 spC;
    u32 sp8;
    f32 scale;
    s32 alpha;
    u8 *tbl;

    tbl = lbl_8026AA98;
    scale = lbl_80368FC4;
    alpha = 0xFF;
    switch (arg0[0]) {
    case 0:
        alpha = 0xC0;
        if (arg0[1] > 0x78U) {
            alpha = (s32)Math_Lerp(lbl_80368FC8, lbl_80368FCC, lbl_80368FD0, (f32)(s32)(arg0[1] - 0x78));
        }
        Ui_LoadAtlasTex(gUnitShadowMat, sp4C, 3);
        break;
    case 1:
        alpha = (s32)Math_EaseOutPow(2, lbl_80368FD4, lbl_80368FCC, lbl_80368FD0, (f32)arg0[1]);
        scale = Math_EaseOutPow(2, lbl_80368FBC, lbl_80368FC4, lbl_80368FD0, (f32)arg0[1]);
        Ui_LoadAtlasTex(gUnitShadowMat, sp4C, 4);
        break;
    }
    fn_80222C50(sp4C, 0);
    {
        f32 angle = (f32)*(s16 *)(arg0 + 2);
        f32 y = *(f32 *)(arg0 + 8);
        f32 x = *(f32 *)(arg0 + 4);
        sp38 = *(f32 *)(tbl + 0x20);
        sp44 = *(f32 *)(tbl + 0x2C);
        sp40 = *(f32 *)(tbl + 0x28);
        sp34 = *(f32 *)(tbl + 0x1C);
        sp34 = x;
        sp38 = y;
        sp44 = y;
        spC = lbl_80368FB4;
        sp40 = x;
        ((u8 *)&spC)[3] = (u8)alpha;
        sp3C = *(u32 *)(tbl + 0x24);
        sp10 = sp34;
        sp14 = sp38;
        sp18 = *(u32 *)(tbl + 0x24);
        sp48 = *(u32 *)(tbl + 0x30);
        sp1C = sp40;
        sp20 = sp44;
        sp24 = *(u32 *)(tbl + 0x30);
        sp28 = *(u32 *)(tbl + 0x34);
        sp2C = *(u32 *)(tbl + 0x38);
        sp30 = *(u32 *)(tbl + 0x3C);
        if (lbl_80368FCC != angle) {
            PSMTXRotRad(spCC, 0x5A, lbl_80368FD8 * angle);
            fn_802026E4(sp9C, &sp1C, &sp28, &sp10);
            C_MTXLightOrtho(sp6C, -scale, scale, -scale, scale, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
            PSMTXConcat(sp6C, sp9C, sp12C);
            PSMTXTrans(spFC, lbl_80368FDC, lbl_80368FDC, lbl_80368FCC);
            PSMTXConcat(spCC, spFC, spCC);
            PSMTXTrans(spFC, lbl_80368FC4, lbl_80368FC4, lbl_80368FCC);
            PSMTXConcat(spFC, spCC, spCC);
            PSMTXConcat(spCC, sp12C, sp12C);
        } else {
            fn_802026E4(sp9C, &sp1C, &sp28, &sp10);
            C_MTXLightOrtho(sp6C, -scale, scale, -scale, scale, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
            PSMTXConcat(sp6C, sp9C, sp12C);
        }
    }
    fn_80224E50(sp12C, 0x1E, 0);
    fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
    sp8 = spC;
    fn_80051564(&sp8, 0, *(f32 *)(arg0 + 4), *(f32 *)(arg0 + 8));
}

void fn_8004B8F8(int arg0, int arg1, float arg2, float arg3)
{
  extern u8 *lbl_803672CC;
  u8 *new_var[2];
  u8 *pool;
  pool = lbl_803672CC;
  new_var[0] = *((u8 **) (*((u8 **) (pool + 8))));
  if (new_var[0] == 0)
  {
    new_var[0] = 0;
  }
  else
  {
    new_var[1] = *((u8 **) (pool + 0x10));
    *((u8 **) (new_var[0] + 4)) = new_var[1];
    *((u32 *) (new_var[0] + 0)) = 0;
    new_var[1] = *((u8 **) (pool + 0x10));
    if (new_var[1] != 0)
    {
      *((u8 **) (new_var[1] + 0)) = new_var[0];
    }
    if ((*((u8 **) (pool + 0xC))) == 0)
    {
      *((u8 **) (pool + 0xC)) = new_var[0];
    }
    *((u8 **) (pool + 0x10)) = new_var[0];
    *((u8 **) (pool + 8)) += 4;
    ++(*((u32 *) (pool + 0x14)));
  }
  if (new_var[0] == 0)
  {
    return;
  }
  *((float *) (new_var[0] + 0xC)) = arg2;
  *((float *) (new_var[0] + 0x10)) = arg3;
  *((u16 *) (new_var[0] + 0xA)) = arg0;
  *((u8 *) (new_var[0] + 9)) = 0;
  *((u8 *) (new_var[0] + 8)) = arg1;
}

void fn_8004B984(void) {
 void fn_80067708(s32,s32,void *,s32);
 s32 fn_8004BAC4(s32,s32,s32,s32);
 extern void *lbl_803672CC;
 struct Node {struct Node *next,*prev; u8 kind,timer;};
 struct Pool {u8 pad[8]; struct Node **free; struct Node *head,*tail; s32 count;};
 struct Pool *pool;
 struct Node *node;
 struct Node *link;
 u8 keep;
 if(lbl_803672CC) {
 node=0;
 goto next;
 do {
 node->timer++;
 switch(node->kind) {
 case 0: if(node->timer==180) {keep=0;break;} goto alive;
 case 1: if(node->timer==60) {keep=0;break;} goto alive;
 default: alive: keep=1;break;
 }
 if(!keep) {
 pool=lbl_803672CC;
 if(node) {
 link=node->next;
 if(link) link->prev=node->prev;
 link=node->prev;
 if(link) link->next=node->next;
 if(node==pool->head) pool->head=node->next;
 if(node==pool->tail) pool->tail=node->prev;
 pool->free--;
 pool->count--;
 *pool->free=node;
 }
 }
 next:
 pool=lbl_803672CC;
 node = node == 0 ? pool->head : node->next;
 } while(node);
 fn_80067708(2,2,fn_8004BAC4,0);
 }
}

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset
void fn_8004BAC4(void) {
void *Camera_GetViewMtx(void);
void PSMTXConcat(void *,void *,void *);
void PSMTXTrans(void *,f32,f32,f32);
void GXClearVtxDesc(void);
void GXSetVtxDesc(s32,s32);
void GXSetVtxAttrFmt(s32,s32,s32,s32,s32);
void GXSetCullMode(s32);
void GXSetBlendMode(s32,s32,s32,s32,s32,s32,s32);
void GXSetNumTevStages(s32);
void GXSetTevOrder(s32,s32,s32,s32);
void GXSetNumChans(s32);
void GXLoadPosMtxImm(void *,s32);
void GXSetCurrentMtx(s32);
void GXSetZMode(s32,s32,s32);
void fn_8022100C(s32);
void fn_802245D8(s32,s32,s32,s32);
void fn_80223E5C(s32,s32,s32,s32,s32);
void GXSetNumTexGens(s32,s32);
extern void *lbl_803672CC;
extern f32 lbl_80368FCC, gUnitShadowZ;
u8 out[0x30];
u8 trans[0x30];
u8 *node;
if (M2C_FIELD(lbl_803672CC,s32 *,0x14)) {
fn_8022100C(2);
GXClearVtxDesc();
GXSetVtxDesc(9,1); GXSetVtxDesc(11,1);
GXSetVtxAttrFmt(0,9,1,4,0); GXSetVtxAttrFmt(0,11,1,5,0);
GXSetCullMode(1); GXSetBlendMode(4,0,1,1,0,0,2);
GXSetNumTevStages(1); GXSetTevOrder(0,0,0,4); GXSetNumChans(1);
PSMTXTrans(trans,lbl_80368FCC,lbl_80368FCC,gUnitShadowZ);
PSMTXConcat(Camera_GetViewMtx(),trans,out);
GXLoadPosMtxImm(out,0); GXSetCurrentMtx(0);
GXSetZMode(1,3,0); fn_802245D8(1,4,5,7); fn_80223E5C(7,0,1,7,0); GXSetNumTexGens(0,0);
node=0;
goto next;
do {
fn_8004B588(node+8);
next: {
void *pool=lbl_803672CC;
if (node==0) node=M2C_FIELD(pool,u8 **,0xC);
else node=*(u8 **)node;
} } while (node);
}
}

void fn_8004BC48(void *arg0, s32 arg1) {
    s16 fn_8017A9B0(s32);
    M2C_UNK fn_8017A9DC(s32);
    extern f32 lbl_80368FCC;
    M2C_FIELD(arg0, s8 *, 3) = 0;
    M2C_FIELD(arg0, s16 *, 0x15C) = 0;
    M2C_FIELD(arg0, s16 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 0x16E) = -1;
    M2C_FIELD(arg0, s8 *, 0x16D) = -1;
    M2C_FIELD(arg0, s8 *, 0x16C) = -1;
    M2C_FIELD(arg0, f32 *, 0x170) = (f32) lbl_80368FCC;
    M2C_FIELD(arg0, f32 *, 0x174) = (f32) lbl_80368FCC;
    M2C_FIELD(arg0, f32 *, 0x178) = (f32) lbl_80368FCC;
    M2C_FIELD(arg0, s32 *, 0x17C) = 0;
    M2C_FIELD(arg0, s16 *, 0x15C) = fn_8017A9B0(arg1);
    fn_8017A9DC(arg1);
    fn_8017A9DC(arg1);
}

void fn_8004BCCC(void *arg0, s32 arg1) {
    M2C_UNK Stream_WriteU16(s32, u16);
    M2C_UNK Stream_WriteU8(s32, M2C_UNK);
    Stream_WriteU16(arg1, (u16) M2C_FIELD(arg0, s16 *, 0x15C));
    Stream_WriteU8(arg1, 0);
    Stream_WriteU8(arg1, 0);
}

#pragma global_optimizer off
void fn_8004BD1C(void *arg0, f32 *out, f32 scale) {
extern f32 lbl_80368FCC; extern f32 lbl_80368FF4;
f32 a,b,k,t,x,y; u8 *p;
a=lbl_80368FCC; p=*(u8 **)((u8 *)arg0+0x17c); b=a;
if(p){ a=(f32)(s8)p[0xa]; b=(f32)(s8)p[0xb]; }
x=a*scale; k=lbl_80368FF4; y=b*scale; t=lbl_80368FCC;
x=x*k; t=t*scale; y=y*k; out[0]=x; t=t*k; out[1]=y; out[2]=t;
}
#pragma global_optimizer on
f32 fn_8004BDA8(void *arg0, f32 farg0, f32 farg1) {
    f32 Math_Angle2D(f32, f32, f32, f32);
    extern f32 lbl_80368FF8;
    if ((farg0 == M2C_FIELD(arg0, f32 *, 4)) && (farg1 == M2C_FIELD(arg0, f32 *, 8))) {
        return (f32)M2C_FIELD(arg0, s16 *, 0x15C) / lbl_80368FF8;
    }
    return Math_Angle2D(M2C_FIELD(arg0, f32 *, 4), M2C_FIELD(arg0, f32 *, 8), farg0, farg1);
}

f32 Unit_GetAngleTo(void *arg0, void *arg1) {
    f32 Math_Angle2D(f32, f32, f32, f32);
    extern f32 lbl_80368FF8;
    f32 y1;
    f32 y0;
    f32 x1;

    y1 = *(f32 *)((char *)arg1 + 4);
    y0 = *(f32 *)((char *)arg0 + 4);
    x1 = *(f32 *)((char *)arg1 + 8);
    if (y1 == y0 && x1 == *(f32 *)((char *)arg0 + 8)) {
        return (f32)*(s16 *)((char *)arg0 + 0x15C) / lbl_80368FF8;
    }
    return Math_Angle2D(y0, *(f32 *)((char *)arg0 + 8), y1, x1);
}

void Unit_FocusCamera(void *arg0, u8 arg1) {
    void fn_8001885C(void);
    void BattleState_SetCamPos(void *, f32, f32);
    extern u8 gBattleState[];

    if (!(M2C_FIELD(arg0, s32 *, 0x1A0) & 0x18)) {
        BattleState_SetCamPos(gBattleState, (f32)(s32)M2C_FIELD(arg0, f32 *, 4), (f32)(s32)M2C_FIELD(arg0, f32 *, 8));
        if (arg1 != 0) {
            fn_8001885C();
        }
    }
}

void fn_8004BF24(void *arg0)
{
    void *fn_80060664(void *);
    void fn_8005FEE8(void *, f32);
    extern f32 lbl_80368FFC;
    void *p;
    void *result;

    if ((*(u8 *)((u8 *)arg0 + 3) & 2) != 0) {
        p = (u8 *)arg0 + 0x1C;
        result = fn_80060664(p);
        if (result != 0 && *(s32 *)((u8 *)result + 0x10) == 0) {
            fn_8005FEE8(p, lbl_80368FFC);
        }
    }
}

s32 Mu_IsAnimDone(void *arg0) {
    void *fn_80060664(void *);
    void *ret;
    u8 *sub;

    if ((*(u8 *)((u8 *)arg0 + 3) & 2) == 0) {
        return 1;
    }
    if ((*(u32 *)((u8 *)arg0 + 0x1A0) & 0x010000DC) != 0) {
        return 1;
    }
    sub = (u8 *)arg0 + 0x1C;
    ret = fn_80060664(sub);
    if (ret == NULL) {
        return 1;
    }
    if (*(s32 *)((u8 *)ret + 0x10) != 0) {
        return 1;
    }
    return (*(u32 *)sub >> 4) & 1;
}

u8 fn_8004C00C(void *arg0) {
 extern f32 lbl_80368FC4;
 { f32 x=(s8)M2C_FIELD(arg0,u8 *,0x19E);
 if(lbl_80368FC4+x != M2C_FIELD(arg0,f32 *,4)+M2C_FIELD(arg0,f32 *,0x10)) return 1; }
 { f32 y=(s8)M2C_FIELD(arg0,u8 *,0x19F);
 return (u8)(lbl_80368FC4+y != M2C_FIELD(arg0,f32 *,8)+M2C_FIELD(arg0,f32 *,0x14)); }
}

void fn_8004C0A0(void *arg0) {
    void *Map_Get(void);
    u8 fn_80040B1C(void *, s32, s32);

    fn_80040B1C(Map_Get(), (s32)*(f32 *)((u8 *)arg0 + 4), (s32)*(f32 *)((u8 *)arg0 + 8));
}

#pragma peephole off
s32 fn_8004C0F0(void *arg0) {
    return (*(u8 *)((char *)arg0 + 3) & 2) != 0;
}
#pragma peephole on
void fn_8004C108(void)
{
    extern u8 lbl_803672BC;
    extern void fn_8004C148(void);
    extern void fn_80067708(s32, s32, void (*)(void), s32);

    if (lbl_803672BC != 0) {
        fn_80067708(2, 1, fn_8004C148, 0);
    }
}

void fn_8004C148(void) {
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8004C444(void *arg0) {
    s32 Game_GetFrameCount(void);
    f32 fn_80059EB8(s32, s32, f32, f32);
    void PSMTXRotRad(void *, s32, f32);
    void fn_802026E4(void *, void *, void *, void *);
    void C_MTXLightOrtho(void *, f32, f32, f32, f32, f32, f32, f32, f32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXTrans(void *, f32, f32, f32);
    void fn_80224E50(void *, s32, s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80051564(void *, s32, f32, f32);
    extern u8 lbl_8026AA98[];
    extern f64 lbl_80368FE8;
    extern f32 lbl_80368FD4;
    extern f32 lbl_80369000;
    extern f32 lbl_80368FCC;
    extern f32 lbl_80368FD8;
    extern f32 lbl_80368FC4;
    extern f32 lbl_80368FDC;

    u8 sp11C[0x30];
    u8 spEC[0x30];
    u8 spBC[0x30];
    u8 sp8C[0x30];
    u8 sp5C[0x30];
    u8 sp4C[0x30];
    u32 sp48;
    f32 sp44;
    f32 sp40;
    u32 sp3C;
    f32 sp38;
    f32 sp34;
    u32 sp30;
    u32 sp2C;
    u32 sp28;
    u32 sp24;
    f32 sp20;
    f32 sp1C;
    u32 sp18;
    f32 sp14;
    f32 sp10;
    u32 spC;
    u32 sp8;
    f32 x, y, angle, f1;
    s32 alpha;
    u8 *tbl;
    u32 t24, t30, t1c, t20, t28, t2c, t34, t38, t3c;

    tbl = lbl_8026AA98;
    angle = (f32)*(u16 *)arg0;
    x = *(f32 *)((u8 *)arg0 + 4);
    y = *(f32 *)((u8 *)arg0 + 8);
    f1 = fn_80059EB8(0x80, Game_GetFrameCount(), lbl_80368FD4, lbl_80369000);

    t24 = *(u32 *)(tbl + 0x24);
    t30 = *(u32 *)(tbl + 0x30);
    t1c = *(u32 *)(tbl + 0x1C);
    t20 = *(u32 *)(tbl + 0x20);
    t28 = *(u32 *)(tbl + 0x28);
    t2c = *(u32 *)(tbl + 0x2C);
    alpha = (s32)(((f32)((u8 *)arg0)[0x27] * f1) / lbl_80369000);
    *(u32 *)&sp34 = t1c;
    *(u32 *)&sp38 = t20;
    *(u32 *)&sp40 = t28;
    *(u32 *)&sp44 = t2c;
    t34 = *(u32 *)(tbl + 0x34);
    t38 = *(u32 *)(tbl + 0x38);
    t3c = *(u32 *)(tbl + 0x3C);
    sp34 = x;
    sp38 = y;
    sp40 = x;
    sp44 = y;
    sp3C = t24;
    sp10 = sp34;
    sp14 = sp38;
    sp18 = t24;
    sp48 = t30;
    sp1C = sp40;
    sp20 = sp44;
    sp24 = t30;
    sp28 = t34;
    sp2C = t38;
    sp30 = t3c;

    if (angle != lbl_80368FCC) {
        PSMTXRotRad(spBC, 0x5A, lbl_80368FD8 * angle);
        fn_802026E4(sp8C, &sp1C, &sp28, &sp10);
        C_MTXLightOrtho(sp5C, -lbl_80368FC4, lbl_80368FC4, -lbl_80368FC4, lbl_80368FC4,
                    lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
        PSMTXConcat(sp5C, sp8C, sp11C);
        PSMTXTrans(spEC, lbl_80368FDC, lbl_80368FDC, lbl_80368FCC);
        PSMTXConcat(spBC, spEC, spBC);
        PSMTXTrans(spEC, lbl_80368FC4, lbl_80368FC4, lbl_80368FCC);
        PSMTXConcat(spEC, spBC, spBC);
        PSMTXConcat(spBC, sp11C, sp11C);
    } else {
        fn_802026E4(sp8C, &sp1C, &sp28, &sp10);
        C_MTXLightOrtho(sp5C, -lbl_80368FC4, lbl_80368FC4, -lbl_80368FC4, lbl_80368FC4,
                    lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
        PSMTXConcat(sp5C, sp8C, sp11C);
    }

    fn_80224E50(sp11C, 0x1E, 0);
    fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);

    {
        u32 *c = (u32 *)sp4C;
        c[0] = *(u32 *)(tbl + 0x70);
        c[1] = *(u32 *)(tbl + 0x74);
        c[2] = *(u32 *)(tbl + 0x78);
        c[3] = *(u32 *)(tbl + 0x7C);
        ((u8 *)&c[0])[3] = (u8)alpha;
        ((u8 *)&c[1])[3] = (u8)alpha;
        ((u8 *)&c[2])[3] = (u8)alpha;
        ((u8 *)&c[3])[3] = (u8)alpha;
        switch (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x190) + 8)) {
        case 0:
            ((u8 *)&spC)[0] = ((u8 *)&c[0])[0];
            ((u8 *)&spC)[1] = ((u8 *)&c[0])[1];
            ((u8 *)&spC)[2] = ((u8 *)&c[0])[2];
            ((u8 *)&spC)[3] = (u8)alpha;
            break;
        case 1:
            ((u8 *)&spC)[0] = ((u8 *)&c[1])[0];
            ((u8 *)&spC)[1] = ((u8 *)&c[1])[1];
            ((u8 *)&spC)[2] = ((u8 *)&c[1])[2];
            ((u8 *)&spC)[3] = (u8)alpha;
            break;
        case 2:
            ((u8 *)&spC)[0] = ((u8 *)&c[2])[0];
            ((u8 *)&spC)[1] = ((u8 *)&c[2])[1];
            ((u8 *)&spC)[2] = ((u8 *)&c[2])[2];
            ((u8 *)&spC)[3] = (u8)alpha;
            break;
        case 3:
            ((u8 *)&spC)[0] = ((u8 *)&c[3])[0];
            ((u8 *)&spC)[1] = ((u8 *)&c[3])[1];
            ((u8 *)&spC)[2] = ((u8 *)&c[3])[2];
            ((u8 *)&spC)[3] = (u8)alpha;
            break;
        }
    }

    if (*(u32 *)((u8 *)arg0 + 0x1A0) & 1) {
        ((u8 *)&spC)[0] >>= 1;
        ((u8 *)&spC)[1] >>= 1;
        ((u8 *)&spC)[2] >>= 1;
    }

    sp8 = spC;
    fn_80051564(&sp8, 0, x, y);
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

/* Set up GX and draw a ground shadow for each visible unit. */
void Unit_DrawShadows(void) {
    void Allegiance_FillMask(s32, void *);
    void Unit_DrawShadow(void *, s32);
    void fn_80066D00(s32);
    void *Light_GetChannel(s32);
    void *Camera_GetViewMtx(void);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXTrans(void *, f32, f32, f32);
    void GXSetVtxDesc(s32, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void fn_8022100C(s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void fn_80222C50(void *, s32);
    void GXSetNumTexGens(s32, s32);
    void fn_80223E5C(s32, s32, s32, s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetZMode(s32, s32, s32);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    extern u8 gUnits[];
    extern s32 gUnitShadowMat;
    extern f32 lbl_80368FCC;
    extern f32 gUnitShadowZ;
    u8 mtxOut[0x30];
    u8 mtxTrans[0x30];
    u8 matBuf[0x20];
    u8 allegMask[8];
    u8 *light;
    s32 light0;
    s32 light4;
    s32 alpha;
    s32 unitId;
    void *unit;
    s32 canDraw;

    Ui_LoadAtlasTex(gUnitShadowMat, matBuf, 0);
    fn_80222C50(matBuf, 0);
    fn_8022100C(2);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
    GXSetCullMode(1);
    GXSetBlendMode(4, 0, 1, 1, 0, 0, 2);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetNumChans(1);
    PSMTXTrans(mtxTrans, lbl_80368FCC, lbl_80368FCC, gUnitShadowZ);
    PSMTXConcat(Camera_GetViewMtx(), mtxTrans, mtxOut);
    GXLoadPosMtxImm(mtxOut, 0);
    GXSetCurrentMtx(0);
    GXSetZMode(1, 3, 0);
    fn_802245D8(1, 4, 5, 7);
    fn_80223E5C(7, 0, 1, 7, 0);
    GXSetNumTexGens(0, 0);
    light = (u8 *)Light_GetChannel(0);
    light0 = light[0];
    light4 = light[4];
    alpha = (((light[6] + (light4 + light[5])) / 3) * (0xFF - ((light[2] + (light0 + light[1])) / 3))) / 255;
    alpha *= 2;
    if (alpha < 0) {
        alpha = 0;
    }
    if (alpha > 0xFF) {
        alpha = 0xFF;
    }
    Allegiance_FillMask(3, allegMask);
    unitId = 1;
    do {
        if ((u8)unitId != 0) {
            unit = gUnits + ((u8)unitId - 1) * 0x280;
        } else {
            unit = NULL;
        }
        if (*(u32 *)((u8 *)unit + 0x188) != 0 &&
            allegMask[*(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)] != 0) {
            if (*(s32 *)((u8 *)unit + 0x1A0) & 0x010000FC) {
                canDraw = 0;
            } else if ((u8)(*(u8 *)((u8 *)unit + 3) & 0x22) != 2) {
                canDraw = 0;
            } else if (*(u8 *)((u8 *)unit + 0x27) == 0) {
                canDraw = 0;
            } else {
                canDraw = 1;
            }
            if ((u8)canDraw != 0) {
                Unit_DrawShadow(unit, alpha);
            }
        }
        unitId += 1;
    } while (unitId <= 0x9F);
    fn_80066D00(-1);
}

#pragma use_lmw_stmw on
void Unit_DrawShadow(u8 *arg0, s32 arg1) {
    f32 Map_SampleHeight(void *);
    void fn_80051564(void *, s32, f32, f32);
    u32 fn_80055D94(s32);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_80060F70(void *, s32, f32 *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void fn_802026E4(void *, void *, void *, void *);
    void C_MTXLightOrtho(void *, f32, f32, f32, f32, f32, f32, f32, f32);
    void fn_802029C4(void *, void *, void *);
    void fn_802031E8(void *, void *);
    f32 fn_80203270(void *, void *);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80224E50(void *, s32, s32);
    f64 fn_80238788(f32);
    extern u8 lbl_8026AA98[];
    extern void *gBattleMap;
    extern u32 lbl_80368FA8;
    extern u32 lbl_80368FAC;
    extern f32 lbl_80368FBC;
    extern f32 lbl_80368FC0;
    extern f32 lbl_80368FC4;
    extern f32 lbl_80368FCC;
    extern f32 lbl_80368FD8;
    extern f32 lbl_80368FDC;
    extern f32 lbl_80368FFC;
    extern f32 lbl_80369004;
    extern f32 lbl_80369008;
    extern f32 lbl_8036900C;
    extern f32 lbl_80369010;
    extern f32 lbl_80369014;
    extern f32 lbl_80369018;
    u8 sp340[0x30];
    u8 sp310[0x30];
    u8 sp2E0[0x30];
    u8 sp2B0[0x30];
    u8 sp280[0x30];
    u8 sp250[0x30];
    u8 sp220[0x30];
    u8 sp1F0[0x30];
    u8 sp1C0[0x30];
    u8 sp190[0x30];
    u8 sp160[0x30];
    f32 sp154;
    f32 sp158;
    f32 sp15C;
    f32 sp148;
    f32 sp14C;
    f32 sp150;
    f32 sp124;
    f32 sp128;
    f32 sp12C;
    u8 scratch[0x120];
    u32 sp18;
    u32 sp14;
    u32 sp10;
    u32 spC;
    u32 sp8;
    f32 f30, f29, f28, f27, f26, f25, f31, f24;
    f32 dx, dy, t;
    s8 r29, r27;
    u8 r30;
    u8 *r28;
    u8 *tbl;
    f32 lim;

    f30 = *(f32 *)(arg0 + 4);
    f29 = *(f32 *)(arg0 + 8);
    r28 = arg0 + 0x1C;
    f28 = lbl_80369004 * ((f32)*(s16 *)(arg0 + 0x15E) / lbl_80369008);
    f25 = *(f32 *)(arg0 + 0xC);
    r29 = (s8)arg0[0x168];
    r27 = (s8)arg0[0x169];
    f27 = lbl_80369004 * ((f32)*(s16 *)(arg0 + 0x162) / lbl_80369008);
    r30 = (u8)((arg1 * arg0[0x27]) / 255);
    tbl = lbl_8026AA98;
    (void)gBattleMap;
    lim = -(f25 - Map_SampleHeight(gBattleMap));
    if (lim > lbl_8036900C) lim = lbl_8036900C;
    f31 = Math_Lerp(lbl_80368FC0, lbl_80368FBC, lbl_8036900C, lim);
    if (r29 >= 0 && r27 >= 0) {
        fn_80060F70(r28, r29, &sp148);
        fn_80060F70(r28, r27, &sp154);
        f30 = (sp148 + sp154) * lbl_80368FC4;
        f29 = (sp14C + sp158) * lbl_80368FC4;
        f26 = f30 - sp148;
        f25 = f29 - sp14C;
        if (lbl_80368FCC != f26 || lbl_80368FCC != f25) {
            *(f32 *)(scratch + 0) = (f32)(s32)(lbl_80369008 * f26);
            *(f32 *)(scratch + 4) = (f32)(s32)(lbl_80369008 * f25);
            *(u32 *)(scratch + 0x10) = *(u32 *)(tbl + 0x4C);
            *(u32 *)(scratch + 0x14) = *(u32 *)(tbl + 0x50);
            *(u32 *)(scratch + 0x18) = *(u32 *)(tbl + 0x54);
            *(f32 *)(scratch + 0x20) = *(f32 *)(scratch + 0);
            *(f32 *)(scratch + 0x24) = *(f32 *)(scratch + 4);
            *(u32 *)(scratch + 0x28) = *(u32 *)(tbl + 0x60);
            fn_802031E8(scratch + 0x20, scratch + 0x20);
            t = fn_80203270(scratch + 0x10, scratch + 0x20);
            if (t > lbl_80368FC0) t = lbl_80368FC0;
            if (t < lbl_80368FFC) t = lbl_80368FFC;
            f24 = (f32)fn_80238788(t);
            if (f25 < lbl_80368FCC) f24 *= lbl_80368FFC;
            PSMTXRotRad(sp340, 0x7A, -f24);
            *(f32 *)(scratch + 0x20) = f26;
            *(f32 *)(scratch + 0x24) = f25;
            *(u32 *)(scratch + 0x28) = *(u32 *)(tbl + 0x6C);
            fn_802029C4(sp340, scratch + 0x20, scratch + 0x20);
            f26 = lbl_80369010 + *(f32 *)(scratch + 0x20);
            f25 = lbl_80369010 + *(f32 *)(scratch + 0x24);
            dx = lbl_80369014 * f24;
        } else {
            dx = lbl_80368FCC;
        }
        if (f26 < f28) f26 = f28;
        if (f25 < f27) f25 = f27;
        {
            f32 x1 = f30, y1 = f29;
            *(f32 *)(scratch + 0x30) = x1;
            *(f32 *)(scratch + 0x34) = y1;
            *(u32 *)(scratch + 0x38) = *(u32 *)(tbl + 0x24);
            *(f32 *)(scratch + 0x3C) = x1;
            *(f32 *)(scratch + 0x40) = y1;
            *(u32 *)(scratch + 0x44) = *(u32 *)(tbl + 0x30);
            *(u32 *)(scratch + 0x48) = *(u32 *)(tbl + 0x34);
            *(u32 *)(scratch + 0x4C) = *(u32 *)(tbl + 0x38);
            *(u32 *)(scratch + 0x50) = *(u32 *)(tbl + 0x3C);
            if (lbl_80368FCC != dx) {
                PSMTXRotRad(sp2E0, 0x5A, lbl_80368FD8 * dx);
                fn_802029C4(sp2E0, scratch + 0x48, scratch + 0x48);
                fn_802026E4(sp2B0, scratch + 0x3C, scratch + 0x48, scratch + 0x30);
                C_MTXLightOrtho(sp280, -(f25 * f31), f25 * f31, -(f26 * f31), f26 * f31, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
                PSMTXConcat(sp280, sp2B0, sp340);
                PSMTXTrans(sp310, lbl_80368FDC, lbl_80368FDC, lbl_80368FCC);
                PSMTXConcat(sp2E0, sp310, sp2E0);
                PSMTXTrans(sp310, lbl_80368FC4, lbl_80368FC4, lbl_80368FCC);
                PSMTXConcat(sp310, sp2E0, sp2E0);
                PSMTXConcat(sp2E0, sp340, sp340);
            } else {
                fn_802026E4(sp2B0, scratch + 0x3C, scratch + 0x48, scratch + 0x30);
                C_MTXLightOrtho(sp280, -(f25 * f31), f25 * f31, -(f26 * f31), f26 * f31, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
                PSMTXConcat(sp280, sp2B0, sp340);
            }
        }
        if (fn_80055D94(0x100) != 0) {
            sp18 = lbl_80368FA8;
            ((u8 *)&sp18)[3] = r30;
            fn_802026E4(sp250, scratch + 0x60, scratch + 0x6C, scratch + 0x54);
            C_MTXLightOrtho(sp220, lbl_80369018, lbl_80369010, lbl_80369018, lbl_80369010, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
            PSMTXConcat(sp220, sp250, sp340);
            fn_80224E50(sp340, 0x1E, 0);
            fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
            sp10 = sp18;
            fn_80051564(&sp10, 1, f30, f29);
            fn_802026E4(sp1F0, scratch + 0x80, scratch + 0x8C, scratch + 0x74);
            C_MTXLightOrtho(sp1C0, lbl_80369018, lbl_80369010, lbl_80369018, lbl_80369010, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
            PSMTXConcat(sp1C0, sp1F0, sp340);
            fn_80224E50(sp340, 0x1E, 0);
            fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
            spC = sp18;
            fn_80051564(&spC, 1, f30, f29);
            return;
        }
    } else {
        fn_80060F70(r28, 1, &sp124);
        fn_802026E4(sp190, scratch + 0xA0, scratch + 0xAC, scratch + 0x94);
        C_MTXLightOrtho(sp160, -(f28 * f31), f28 * f31, -(f27 * f31), f27 * f31, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
        PSMTXConcat(sp160, sp190, sp340);
    }
    fn_80224E50(sp340, 0x1E, 0);
    fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
    sp14 = lbl_80368FAC;
    ((u8 *)&sp14)[3] = r30;
    sp8 = sp14;
    fn_80051564(&sp8, 1, f30, f29);
}

void fn_8004D370(void) {
    void fn_80067708(s32, s32, void (*)(void), s32);
    void Unit_DrawShadows(void);
    fn_80067708(2, 1, Unit_DrawShadows, 0);
}

void fn_8004D3A4(u8 *p) {
 void fn_8006CAD4(void *);
 void Prim2D_Begin(void);
 void Prim2D_SetTransform(f32,f32,f32,f32);
 void Prim2D_SetColorByte(u8);
 void Prim2D_PrepareTex(void);
 void Ui_DrawIcon(void *,s32,s32,s32);
 void Prim2D_ResetState(void);
 u32 Game_GetFrameCount(void);
 void fn_8005F780(void *,s32);
 extern u8 gUiIconDrawer[];
 u8 valid, alpha;
 s32 x,y;
 if (*(u32 *)(p+0x1A0)&0x010000FC) valid=0;
 else if((u8)(p[3]&0x22)!=2) valid=0;
 else if(p[0x27]==0) valid=0;
 else valid=1;
 if(valid) {
 fn_8006CAD4(p+0x1C);
 if(*(u32 *)(p+0x1A0)&2) {
 alpha=p[0x27];
 Prim2D_Begin();
 Prim2D_SetTransform((f32)(s32)(0.5f+*(f32 *)(p+0x170)),(f32)(s32)(0.5f+*(f32 *)(p+0x174)),990.0f,1.0f);
 Prim2D_SetColorByte(alpha);
 Prim2D_PrepareTex();
 Ui_DrawIcon(gUiIconDrawer,0,-20,79);
 Prim2D_ResetState();
 }
 if((*(u32 *)(p+0x1A0)&0x800) && (Game_GetFrameCount()&31)<20) {
 Prim2D_Begin();
 Prim2D_SetTransform((f32)(s32)(0.5f+*(f32 *)(p+0x170)),(f32)(s32)(0.5f+*(f32 *)(p+0x174)),990.0f,1.0f);
 Prim2D_PrepareTex();
 Ui_DrawIcon(gUiIconDrawer,-12,-24,56);
 }
 y=(s32)*(f32 *)(p+8)*7;
 x=(s32)*(f32 *)(p+4);
 fn_8005F780(p+0x1C,(((x+y)%49+10)*4)&0xFC);
 }
}

void fn_8004D5D4(s32 arg0) {
    extern s32 lbl_803672B8;
    extern f32 lbl_80368FCC;

    fn_80222644(arg0, lbl_803672B8, 0xA0, 0x78, 0, 0, 0, 0);
    GXInitTexObjLOD(arg0, 1, 1, 0, 0, 0, lbl_80368FCC, lbl_80368FCC, lbl_80368FCC);
}

void fn_8004D644(void) {
    void *Map_Get(void);
    extern void fn_8004D688(void);
    extern void fn_80067708(s32, s32, void (*)(void), s32);
    void *p;

    p = Map_Get();
    if (*(u32 *)((u8 *)p + 0x64) & 0x10) {
        fn_80067708(3, 1, fn_8004D688, 0);
    }
}

void fn_8004DAFC(void *arg0, f32 radius) {
typedef struct { f32 x,y,z; } Position;
extern f32 lbl_80368FCC, lbl_8036902C, lbl_80369030, lbl_80368FC0;
void fn_80068070(f32,f32,f32,f32);
void fn_80067984(s32);
Position pos = *(Position *)((u8 *)arg0+0x170);
f32 one,zero,right,top,left,bottom;
u8 color;
fn_80068070(0.0f,0.0f,lbl_8036902C,lbl_80369030);
fn_800680AC(0,0,160,120);
Camera_ApplyOrtho(0);
color=*((u8 *)arg0+0x27);
GXBegin(0x98,0,4);
right=pos.x; bottom=pos.y;
left=right-radius; top=bottom-radius; right+=radius; bottom+=radius;
zero=0.0f; one=1.0f;
*(volatile f32 *)0xCC008000=left; *(volatile f32 *)0xCC008000=top; *(volatile f32 *)0xCC008000=zero;
*(volatile u8 *)0xCC008000=color; *(volatile u8 *)0xCC008000=color; *(volatile u8 *)0xCC008000=color; *(volatile u8 *)0xCC008000=255;
*(volatile f32 *)0xCC008000=zero; *(volatile f32 *)0xCC008000=zero;
*(volatile f32 *)0xCC008000=right; *(volatile f32 *)0xCC008000=top; *(volatile f32 *)0xCC008000=zero;
*(volatile u8 *)0xCC008000=color; *(volatile u8 *)0xCC008000=color; *(volatile u8 *)0xCC008000=color; *(volatile u8 *)0xCC008000=255;
*(volatile f32 *)0xCC008000=one; *(volatile f32 *)0xCC008000=zero;
*(volatile f32 *)0xCC008000=left; *(volatile f32 *)0xCC008000=bottom; *(volatile f32 *)0xCC008000=zero;
*(volatile u8 *)0xCC008000=color; *(volatile u8 *)0xCC008000=color; *(volatile u8 *)0xCC008000=color; *(volatile u8 *)0xCC008000=255;
*(volatile f32 *)0xCC008000=zero; *(volatile f32 *)0xCC008000=one;
*(volatile f32 *)0xCC008000=right; *(volatile f32 *)0xCC008000=bottom; *(volatile f32 *)0xCC008000=zero;
*(volatile u8 *)0xCC008000=color; *(volatile u8 *)0xCC008000=color; *(volatile u8 *)0xCC008000=color; *(volatile u8 *)0xCC008000=255;
*(volatile f32 *)0xCC008000=one; *(volatile f32 *)0xCC008000=one;
fn_80067984(0);
}

void fn_8004DC54(s8 arg0) {
    extern u8 lbl_803672BC;
    lbl_803672BC = arg0;
}

void fn_8004DC5C(void *arg0) {
    void fn_80067708(void *, s32, void *, s32);
    extern void fn_8004DC8C(void);
    fn_80067708(arg0, 1, fn_8004DC8C, 0);
}

void fn_8004DC8C(void) {
 u32 fn_80055D94(s32);
 void fn_800680AC(u16,u16,u16,u16);
 void Camera_ApplyOrtho(s32);
 void fn_800599D0(s32,s32,s32,s32,s32);
 void fn_8005956C(f32,s32,s32,s32,s32,u8,void *,s32);
 void fn_80067984(s32);
 extern s32 lbl_803672B4;
 extern u8 lbl_803672BD;
 struct Color {u8 r,g,b,a;};
 extern struct Color lbl_803672C0;
 extern s16 lbl_803672C4,lbl_803672C6,lbl_803672C8,lbl_803672CA;
 extern f32 lbl_80368FCC;
 struct Color *p;
 s16 left;
 if(fn_80055D94(0x80)==0) {
 left=lbl_803672C4;
 p=&lbl_803672C0;
 p->r=0x30; p->g=0x30; p->b=0x60; p->a=0x60;
 lbl_803672BD=1;
 if(left<0) lbl_803672C4=0;
 if(lbl_803672C6<0) lbl_803672C6=0;
 if(lbl_803672C8>0x260) lbl_803672C8=0x260;
 if(lbl_803672CA>0x1C0) lbl_803672CA=0x1C0;
 if(lbl_803672C4>=lbl_803672C8 || lbl_803672C6>=lbl_803672CA) return;
 {
 fn_800680AC((u16)lbl_803672C4,(u16)lbl_803672C6,(u16)(lbl_803672C8-lbl_803672C4),(u16)(lbl_803672CA-lbl_803672C6));
 Camera_ApplyOrtho(0);
 fn_800599D0(0,0,0x260,0x1C0,lbl_803672B4);
 fn_8005956C(lbl_80368FCC,0,0,0x260,0x1C0,lbl_803672BD,&lbl_803672C0,lbl_803672B4);
 fn_80067984(0);
 }
 }
}

void fn_8004DDB8(s32 arg0) {
    void fn_80007340(void (*)(void), s32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_ResetState(void);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    u32 fn_80055D94(s32);
    void fn_8004DEAC(void);
    extern u8 lbl_803672BD;
    extern u8 lbl_803672C0;
    extern f32 lbl_80368FC0;
    extern f32 lbl_80368FCC;
    u8 c;
    u8 *p;
    u8 flag;

    if (fn_80055D94(0x80) == 0) {
        c = 0x60;
        p = &lbl_803672C0;
        flag = 1;
        p[0] = c;
        p[1] = c;
        p[2] = c;
        p[3] = c;
        lbl_803672BD = flag;
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_80368FCC, lbl_80368FCC, (f32)arg0, lbl_80368FC0);
        Prim2D_SetTex(0, 0x410);
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(0xB);
        fn_80007340(fn_8004DEAC, 0);
        Prim2D_EndPrim();
        Prim2D_ResetState();
    }
}

void fn_8004DE78(void) {
    M2C_UNK fn_80059C2C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    fn_80059C2C(0, 0, 0x260, 0x1C0, 0);
}

void fn_8004DEAC(void) {
    M2C_UNK fn_8005956C(f32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u8, M2C_UNK *, s32);
    M2C_UNK fn_800599D0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern s32 lbl_803672B4;
    extern u8 lbl_803672BD;
    extern M2C_UNK lbl_803672C0;
    extern f32 lbl_80368FCC;
    fn_800599D0(0, 0, 0x260, 0x1C0, lbl_803672B4);
    fn_8005956C(lbl_80368FCC, 0, 0, 0x260, 0x1C0, lbl_803672BD, &lbl_803672C0, lbl_803672B4);
}

void fn_8004DF04(void) {
    extern s16 lbl_803672C4;
    extern s16 lbl_803672C6;
    extern s16 lbl_803672C8;
    extern s16 lbl_803672CA;
    lbl_803672C4 = 0x3E8;
    lbl_803672C6 = 0x3E8;
    lbl_803672C8 = -0x3E8;
    lbl_803672CA = -0x3E8;
}

void fn_8004DF20(void *arg0) {
    u8 temp_r4;

    temp_r4 = ((u8*)arg0)[3];
    if ((temp_r4 & 2) && !(temp_r4 & 8)) {
        fn_80060060((char*)arg0 + 0x1C);
    }
}

/* Per-frame unit visual: update the model if drawable, and idle-spin mapAngle on the active phase. */
void Unit_UpdateVisual(void *unit)
{
    void fn_800609DC(void *);
    extern u8 gBattleState[];
    u8 flags;
    void *model;
    u8 canDraw;
    s32 angle;

    flags = *((u8 *)unit + 3);
    model = (u8 *)unit + 0x1c;
    if (!(flags & 8)) {
        if (*(u32 *)((u8 *)unit + 0x1a0) & 0x010000FC) {
            canDraw = 0;
        } else if ((u8)(flags & 0x22) != 2) {
            canDraw = 0;
        } else if (*((u8 *)unit + 0x27) == 0) {
            canDraw = 0;
        } else {
            canDraw = 1;
        }
        if (canDraw) {
            fn_800609DC(model);
        }
        if (!(*(u32 *)((u8 *)unit + 0x1a0) & 1)) {
            if (*(*(u8 **)((u8 *)unit + 0x190) + 8) == gBattleState[0x11]) {
                angle = *(u16 *)unit + 1;
                *(u16 *)unit = angle % 360;
            }
        }
    }
}

extern double lbl_80368FE0;
extern float lbl_80368FF8;
extern float lbl_80368FD8;
void fn_8004E040(void *obj) {
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXConcat(void *, void *, void *);
    f32 mtxTrans[3][4];
    f32 mtxRotX[3][4];
    f32 mtxRotY[3][4];
    f32 mtxScale[3][4];

    PSMTXRotRad(mtxRotY, 0x59, 0.017453292f * ((f32)*(s16 *)((u8 *)obj + 0x15C) / 50.0f));
    PSMTXRotRad(mtxRotX, 0x58, 4.712389f);
    PSMTXScale(mtxScale,
        (f32)*(s16 *)((u8 *)obj + 0x15E) / 1000.0f,
        (f32)*(s16 *)((u8 *)obj + 0x160) / 1000.0f,
        (f32)*(s16 *)((u8 *)obj + 0x162) / 1000.0f);
    PSMTXTrans(mtxTrans,
        *(f32 *)((u8 *)obj + 0x4) + *(f32 *)((u8 *)obj + 0x10),
        *(f32 *)((u8 *)obj + 0x8) + *(f32 *)((u8 *)obj + 0x14),
        *(f32 *)((u8 *)obj + 0xC) + *(f32 *)((u8 *)obj + 0x18));
    PSMTXConcat(mtxRotY, mtxScale, mtxScale);
    PSMTXConcat(mtxRotX, mtxScale, mtxScale);
    PSMTXConcat(mtxTrans, mtxScale, (u8 *)obj + 0x2C);
}

#pragma global_optimizer off
void fn_8004E178(void *arg0) {
void *Camera_GetActive(void);
f32 Math_Lerp(f32,f32,f32,f32);
u8 Status_Test(void *,s32);
void PSMTXRotRad(void *,s32,f32);
void PSMTXScale(void *,f32,f32,f32);
void PSMTXTrans(void *,f32,f32,f32);
void PSMTXConcat(void *,void *,void *);
void PSMTXCopy(void *,void *);
void QUATMtx(void *,void *);
void Game_Assert(void *,s32,void *);
void fn_8005A1E8(s32,f32 *,f32 *);
extern f32 lbl_80368FCC,lbl_80369038,lbl_8036903C,lbl_80369028,lbl_80368FF8,lbl_80369040,lbl_80369024,lbl_80369044,lbl_80369048,lbl_80368FD8,lbl_80368FC4;
extern u8 lbl_8026AB18[];
extern s16 lbl_803672C4,lbl_803672C6,lbl_803672C8,lbl_803672CA;
f32 out[12], rz[12], ry[12], rx[12], trans[12], scale[12];
f32 left,right,top,bottom,margin;
f32 depth, px;
void *cam;
s32 x,y;
u8 *p=arg0;
if (!(*(u32 *)(p+0x1A0)&0x10000DC) && (p[3]&2) && p[0x27]) {
left=lbl_80368FCC; right=lbl_80369038; bottom=lbl_8036903C; top=left;
cam=Camera_GetActive();
if(cam) {
margin=Math_Lerp(lbl_80368FF8,lbl_80369040,lbl_80369024,*(f32 *)((u8 *)cam+0x18)-lbl_80369028);
if(margin<lbl_80369040) margin=lbl_80369040;
if(margin>lbl_80368FF8) margin=lbl_80368FF8;
if(Status_Test(p+0x1BC,7)) margin*=lbl_80369044;
left-=margin; right+=margin; top-=margin; bottom+=lbl_80369048*margin;
}
switch(*(u32 *)(p+0x28)) {
case 1:
PSMTXRotRad(rx,88,lbl_80368FD8 * *(f32 *)(p+56));
PSMTXRotRad(ry,89,lbl_80368FD8 * *(f32 *)(p+60));
PSMTXRotRad(rz,90,lbl_80368FD8 * *(f32 *)(p+64));
break;
case 2:
PSMTXRotRad(rx,89,lbl_80368FD8 * *(f32 *)(p+60));
PSMTXRotRad(ry,90,lbl_80368FD8 * *(f32 *)(p+64));
PSMTXRotRad(rz,88,lbl_80368FD8 * *(f32 *)(p+56));
break;
case 3:
PSMTXRotRad(rx,90,lbl_80368FD8 * *(f32 *)(p+64));
PSMTXRotRad(ry,88,lbl_80368FD8 * *(f32 *)(p+56));
PSMTXRotRad(rz,89,lbl_80368FD8 * *(f32 *)(p+60));
break;
case 4:
PSMTXRotRad(rx,88,lbl_80368FD8 * *(f32 *)(p+56));
PSMTXRotRad(ry,90,lbl_80368FD8 * *(f32 *)(p+64));
PSMTXRotRad(rz,89,lbl_80368FD8 * *(f32 *)(p+60));
break;
case 5:
PSMTXRotRad(rx,89,lbl_80368FD8 * *(f32 *)(p+60));
PSMTXRotRad(ry,88,lbl_80368FD8 * *(f32 *)(p+56));
PSMTXRotRad(rz,90,lbl_80368FD8 * *(f32 *)(p+64));
break;
case 6:
PSMTXRotRad(rx,90,lbl_80368FD8 * *(f32 *)(p+64));
PSMTXRotRad(ry,89,lbl_80368FD8 * *(f32 *)(p+60));
PSMTXRotRad(rz,88,lbl_80368FD8 * *(f32 *)(p+56));
break;
case 8:
PSMTXScale(scale,*(f32 *)(p+0x44),*(f32 *)(p+0x48),*(f32 *)(p+0x4C));
PSMTXTrans(trans,*(f32 *)(p+0x2C),*(f32 *)(p+0x30),*(f32 *)(p+0x34));
QUATMtx(p+0x2C,rx);
PSMTXConcat(rx,scale,out); PSMTXConcat(rx,out,out); PSMTXConcat(trans,out,out);
goto done;
case 7: PSMTXCopy(p+0x2C,out); goto done;
default: Game_Assert(lbl_8026AB18+0x2B,0xB8,lbl_8026AB18+0x33); break;
}
PSMTXScale(scale,*(f32 *)(p+0x44),*(f32 *)(p+0x48),*(f32 *)(p+0x4C));
PSMTXTrans(trans,*(f32 *)(p+0x2C),*(f32 *)(p+0x30),*(f32 *)(p+0x34));
PSMTXConcat(rx,scale,out); PSMTXConcat(ry,out,out); PSMTXConcat(rz,out,out); PSMTXConcat(trans,out,out);
done:
px=out[3]; depth=lbl_80368FC4;
*(f32 *)(p+0x170)=px; *(f32 *)(p+0x174)=out[7]; *(f32 *)(p+0x178)=out[11]-depth;
fn_8005A1E8(0,(f32 *)(p+0x170),(f32 *)(p+0x170));
if(*(f32 *)(p+0x170)>left && *(f32 *)(p+0x170)<right && *(f32 *)(p+0x174)>top && *(f32 *)(p+0x174)<bottom) {
*(u32 *)(p+0x1A0)&=~0x20;
y=*(f32 *)(p+0x174); x=*(f32 *)(p+0x170);
if(lbl_803672C4>x-64)lbl_803672C4=x-64;
if(lbl_803672C6>y-64)lbl_803672C6=y-64;
if(lbl_803672C8<x+64)lbl_803672C8=x+64;
if(lbl_803672CA<y+64)lbl_803672CA=y+64;
} else *(u32 *)(p+0x1A0)|=0x20;
}}

void fn_8004E670(void *dst, void *arg0, u8 update) {
void PSMTXRotRad(void *,s32,f32);
void PSMTXScale(void *,f32,f32,f32);
void PSMTXTrans(void *,f32,f32,f32);
void PSMTXConcat(void *,void *,void *);
void PSMTXCopy(void *,void *);
void QUATMtx(void *,void *);
void Game_Assert(void *,s32,void *);
void fn_8005A1E8(s32,f32 *,f32 *);
extern f32 lbl_80368FCC,lbl_80369038,lbl_8036903C,lbl_80369028,lbl_80368FF8,lbl_80369040,lbl_80369024,lbl_80369044,lbl_80369048,lbl_80368FD8,lbl_80368FC4;
extern u8 lbl_8026AB18[];
f32 out[12], rz[12], ry[12], rx[12], trans[12], scale[12];
f32 depth,px;
u8 *p=arg0;
if(update) {
switch(*(u32 *)(p+0x28)) {
case 1:
PSMTXRotRad(rx,88,lbl_80368FD8 * *(f32 *)(p+56));
PSMTXRotRad(ry,89,lbl_80368FD8 * *(f32 *)(p+60));
PSMTXRotRad(rz,90,lbl_80368FD8 * *(f32 *)(p+64));
break;
case 2:
PSMTXRotRad(rx,89,lbl_80368FD8 * *(f32 *)(p+60));
PSMTXRotRad(ry,90,lbl_80368FD8 * *(f32 *)(p+64));
PSMTXRotRad(rz,88,lbl_80368FD8 * *(f32 *)(p+56));
break;
case 3:
PSMTXRotRad(rx,90,lbl_80368FD8 * *(f32 *)(p+64));
PSMTXRotRad(ry,88,lbl_80368FD8 * *(f32 *)(p+56));
PSMTXRotRad(rz,89,lbl_80368FD8 * *(f32 *)(p+60));
break;
case 4:
PSMTXRotRad(rx,88,lbl_80368FD8 * *(f32 *)(p+56));
PSMTXRotRad(ry,90,lbl_80368FD8 * *(f32 *)(p+64));
PSMTXRotRad(rz,89,lbl_80368FD8 * *(f32 *)(p+60));
break;
case 5:
PSMTXRotRad(rx,89,lbl_80368FD8 * *(f32 *)(p+60));
PSMTXRotRad(ry,88,lbl_80368FD8 * *(f32 *)(p+56));
PSMTXRotRad(rz,90,lbl_80368FD8 * *(f32 *)(p+64));
break;
case 6:
PSMTXRotRad(rx,90,lbl_80368FD8 * *(f32 *)(p+64));
PSMTXRotRad(ry,89,lbl_80368FD8 * *(f32 *)(p+60));
PSMTXRotRad(rz,88,lbl_80368FD8 * *(f32 *)(p+56));
break;
case 8:
PSMTXScale(scale,*(f32 *)(p+0x44),*(f32 *)(p+0x48),*(f32 *)(p+0x4C));
PSMTXTrans(trans,*(f32 *)(p+0x2C),*(f32 *)(p+0x30),*(f32 *)(p+0x34));
QUATMtx(p+0x2C,rx);
PSMTXConcat(rx,scale,out); PSMTXConcat(rx,out,out); PSMTXConcat(trans,out,out);
goto done;
case 7: PSMTXCopy(p+0x2C,out); goto done;
default: Game_Assert(lbl_8026AB18+0x2B,0xB8,lbl_8026AB18+0x33); break;
}
PSMTXScale(scale,*(f32 *)(p+0x44),*(f32 *)(p+0x48),*(f32 *)(p+0x4C));
PSMTXTrans(trans,*(f32 *)(p+0x2C),*(f32 *)(p+0x30),*(f32 *)(p+0x34));
PSMTXConcat(rx,scale,out); PSMTXConcat(ry,out,out); PSMTXConcat(rz,out,out); PSMTXConcat(trans,out,out);
done:
px=out[3];
*(f32 *)(p+0x170)=px; *(f32 *)(p+0x174)=out[7]; *(f32 *)(p+0x178)=out[11]-0.5f;
fn_8005A1E8(0,(f32 *)(p+0x170),(f32 *)(p+0x170));
}
{ u32 y; u32 x; x=*(u32 *)(p+0x170); y=*(u32 *)(p+0x174); ((u32 *)dst)[0]=x; ((u32 *)dst)[1]=y; ((u32 *)dst)[2]=*(u32 *)(p+0x178); }
}

#pragma global_optimizer reset
void fn_8004E9D8(void *arg0, s32 arg1) {
    void fn_800616A0(void *);
    void fn_80184F20(void *);
    void fn_8005C7E8(u32);
    void fn_8004EB14(void *, s32);
    u8 temp;
    u32 p;

    fn_800616A0((u8 *)arg0 + 0xBC);
    temp = *((u8 *)arg0 + 3);
    if ((temp & 2) != 0) {
        *((u8 *)arg0 + 3) = (u8)(temp & ~2);
        fn_80184F20(arg0);
        fn_800616A0((u8 *)arg0 + 0x1C);
        p = *(u32 *)((u8 *)arg0 + 0x164);
        if (p != 0) {
            fn_8005C7E8(p);
        }
        *(u32 *)((u8 *)arg0 + 0x164) = 0;
        *(u32 *)((u8 *)arg0 + 0x17C) = 0;
    }
    fn_8004EB14(arg0, arg1);
}

void fn_8004EA60(void *arg0, s32 arg1) {
void fn_800616A0(void *); void fn_80184F20(void *); void fn_8005C7E8(u32);
extern f32 lbl_80368FCC;
u8 temp; u32 p;
fn_800616A0((u8 *)arg0+0xBC);
temp=*((u8 *)arg0+3);
if(temp & 2) {
*((u8 *)arg0+3)=(u8)(temp & ~2);
fn_80184F20(arg0); fn_800616A0((u8 *)arg0+0x1C);
p=*(u32 *)((u8 *)arg0+0x164);
if(p) fn_8005C7E8(p);
*(u32 *)((u8 *)arg0+0x164)=0;
*(u32 *)((u8 *)arg0+0x17C)=0;
if((u8)arg1) {
f32 zero;
*((u8 *)arg0+3)=0;
zero=lbl_80368FCC;
*(s16 *)((u8 *)arg0+0x15C)=0;
*(s16 *)arg0=0;
*(s16 *)((u8 *)arg0+0x16E)=-1;
*((s8 *)arg0+0x16D)=-1;
*((s8 *)arg0+0x16C)=-1;
*(f32 *)((u8 *)arg0+0x170)=zero;
*(f32 *)((u8 *)arg0+0x174)=zero;
*(f32 *)((u8 *)arg0+0x178)=zero;
*(u32 *)((u8 *)arg0+0x17C)=0;
}
}
}

#pragma use_lmw_stmw on
void fn_8004EB14(void *arg0, u32 arg1) {
#pragma opt_common_subs off
    void fn_800056A0(s32);
    void DebugPrint(void *, ...);
    void *Res_GetByName(void *);
    void *Unit_GetActiveItemPtr(void *);
    s32 fn_8004ABD4(void *, s32);
    void *fn_8004B078(void *, s32);
    s32 fn_8004B0C8(void *);
    s32 fn_8004B110(void *);
    void *fn_8004B158(void *);
    s32 fn_8004B1A0(s32);
    void fn_8004FE98(void *, s32);
    u16 FileCache_Probe(void *);
    void *fn_8005C82C(void *, u16);
    void fn_8005F434(void *, void *, u16);
    void GActor_LoadG(void *, s32);
    void GActor_LoadGs(void *, s32);
    void Model_SetAlpha(void *, s32);
    void fn_8005FEE8(void *, f32);
    void fn_80060638(void *);
    void *fn_80060664(void *);
    s32 GActor_FindNode(void *, void *);
    void GActor_Finalize(void *);
    void fn_80061824(void *);
    void fn_800688D4(void *, s32, void *, s32);
    u8 Status_Test(void *, s32);
    void sprintf(void *, void *, ...);
    void GMaterial_SetupAtlasTev(void);
    extern u8 lbl_8026AB18[];
    extern void *lbl_80366DC8;
    extern f32 lbl_80368FCC;
    extern f32 lbl_80368FFC;
    extern u8 lbl_802EFFE8[];

    s32 sp[2];
    void *res;
    void *sub;
    void *sub2;
    void *tmp;
    u8 flags;
    u8 t;
    s32 id;

    flags = M2C_FIELD(arg0, u8 *, 3);
    if (!(flags & 2)) {
        M2C_FIELD(arg0, u8 *, 3) = flags & 0xFE;
        M2C_FIELD(arg0, u8 *, 3) |= 2;
        id = get_4F128_id(arg0);
        res = get_4F128_resource(arg0, id);
        sub = (u8 *)arg0 + 0x1C;
        M2C_FIELD(arg0, void **, 0x17C) = res;
        fn_80061824(sub);
        M2C_FIELD(sub, u8 *, 0x87) = 1;
        arg1 = (u16)arg1 | 8;
        M2C_FIELD(arg0, void **, 0x164) = fn_8005C82C(fn_8004B158(res), (u16)arg1);
        GActor_LoadG(sub, fn_8004B0C8(res));
        GActor_LoadGs(sub, fn_8004B110(res));
        id = get_4F128_id(arg0);
        res = get_4F128_resource(arg0, id);
        switch (M2C_FIELD(M2C_FIELD(arg0, void **, 0x190), u8 *, 8)) {
        case 0: res = fn_8004B078(res, 0); break;
        case 1: res = fn_8004B078(res, 1); break;
        case 2: res = fn_8004B078(res, 2); break;
        case 3: res = fn_8004B078(res, 3); break;
        default: res = fn_8004B078(res, 0); break;
        }
        if (!res || FileCache_Probe(res) == 0x8000U) {
            res = lbl_80366DC8;
        }
        fn_8005F434(sub, res, (u16)arg1);
        GActor_Finalize(sub);
        if (M2C_FIELD(sub, u32 *, 0x64) != 0) {
            fn_800056A0(0);
        }
        if (M2C_FIELD(arg0, u8 *, 3) & 0x10) {
            fn_8004FE98(arg0, 0xB);
            if (M2C_FIELD(arg0, u8 *, 3) & 2) {
                sub2 = (u8 *)arg0 + 0x1C;
                tmp = fn_80060664(sub2);
                if (tmp != NULL && M2C_FIELD(tmp, s32 *, 0x10) == 0) {
                    fn_8005FEE8(sub2, lbl_80368FFC);
                }
            }
            t = M2C_FIELD(arg0, u8 *, 3);
            M2C_FIELD(arg0, u8 *, 3) = t & 0xEF;
        } else {
            fn_8004FE98(arg0, 0);
        }
        {
            u32 bits = M2C_FIELD(sub, u32 *, 0);
            M2C_FIELD(sub, u32 *, 0) = (bits | 0x61100000) | 0x8000;
        }
        M2C_FIELD(arg0, f32 *, 0x10) = lbl_80368FCC;
        M2C_FIELD(arg0, f32 *, 0x14) = lbl_80368FCC;
        M2C_FIELD(arg0, f32 *, 0x18) = lbl_80368FCC;
        M2C_FIELD(arg0, s16 *, 0x15E) = 0x3C;
        M2C_FIELD(arg0, s16 *, 0x160) = 0x3C;
        M2C_FIELD(arg0, s16 *, 0x162) = 0x3C;
        sp[0] = GActor_FindNode(sub, lbl_8026AB18 + 0x8F);
        sp[1] = GActor_FindNode(sub, lbl_8026AB18 + 0x92);
        sub2 = (u8 *)arg0 + 0x1C;
        M2C_FIELD(arg0, u8 *, 0x168) = sp[0];
        M2C_FIELD(arg0, u8 *, 0x169) = sp[1];
        fn_80060638(sub2);
        fn_800688D4(sub2, 0, GMaterial_SetupAtlasTev, 0x4000);
        M2C_FIELD(sub2, void **, 0x90) = arg0;
        Model_SetAlpha(sub2, 0);
        sub2 = (u8 *)arg0 + 0xBC;
        fn_80061824(sub2);
        M2C_FIELD(sub2, void **, 4) = lbl_802EFFE8;
        GActor_Finalize(sub2);
        M2C_FIELD(sub2, u32 *, 0) |= 0x100;
        M2C_FIELD(sub2, void **, 4) = NULL;
    }
}
#pragma use_lmw_stmw reset

s32 Unit_IsDisplayReady(void *arg0) {
#pragma opt_common_subs off
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

 u8 FileCache_IsReady(void *);
 void *res;
 s32 id;
 void *obj=arg0;
 u8 flags=M2C_FIELD(arg0,u8 *,3);
 if(flags&2) return 1;
 if(!(flags&1)) return 1;
 id=get_4F128_id(arg0);
 res=get_4F128_resource(obj,id);
 if(!FileCache_IsReady(fn_8004B158(res))) return 0;
 if(!fn_8004AF74(res,M2C_FIELD(M2C_FIELD(arg0,void **,0x190),u8 *,8))) {
 res=get_4F128_resource(arg0,get_4F128_id(arg0));
 switch(M2C_FIELD(M2C_FIELD(arg0,void **,0x190),u8 *,8)) {
 case 0: res=fn_8004B078(res,0);break;
case 1: res=fn_8004B078(res,1);break;
case 2: res=fn_8004B078(res,2);break;
case 3: res=fn_8004B078(res,3);break;
default: res=fn_8004B078(res,0);break;
 }
 if(!res||FileCache_Probe(res)==0x8000U) res=lbl_80366DC8;
 if(res!=lbl_80366DC8&&!FileCache_IsReady(res))return 0;
 }
 return 1;
}

static inline s32 get_4F5EC_id(void *arg0) {
 void *Unit_GetActiveItemPtr(void *);
 s32 fn_8004ABD4(void *,s32);
 s32 value=M2C_FIELD(arg0,s8 *,0x16C);
 if(value>=0) return value;
 return fn_8004ABD4(Unit_GetActiveItemPtr(arg0),0);
}
static inline void *get_4F5EC_resource(void *arg0) {
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
 s32 value;
 void *resolved;
 value=get_4F5EC_id(arg0);
 base=M2C_FIELD(arg0,void **,0x18C);
 if(M2C_FIELD(arg0,u8 *,3)&4) base=M2C_FIELD(base,void **,0xC)?Res_GetByName(M2C_FIELD(base,void **,0xC)):0;
 idx=0;
 if(Status_Test((u8 *)arg0+0x1BC,8)) {
 if(Status_Test((u8 *)base+0x1C,9)) idx=1;
 } else if(Status_Test((u8 *)base+0x1C,2)) idx=1;
 name=M2C_FIELD(arg0,void **,0x188);
 name=(u8 *)name+idx*4;
 name=M2C_FIELD(name,void **,0x5C);
 if(!name) name=M2C_FIELD(base,void **,0x18);
 if(!name) {fn_800056A0(0);name=lbl_8026AB18+0x52;}
 if(!name||!*(s8 *)name) return Res_GetByName(lbl_8026AB18+0x53);
 sprintf(buf,lbl_8026AB18+0x5F,name,fn_8004B1A0(value));
 resolved=Res_GetByName(buf);
 if(!resolved) {
 fn_800056A0(0);return Res_GetByName(lbl_8026AB18+0x53);
 }
 sprintf(buf,lbl_8026AB18+0x64,fn_8004B158(resolved));
 if(FileCache_Probe(buf)==0x8000U) {
 DebugPrint(lbl_8026AB18+0x67,buf);
 return Res_GetByName(lbl_8026AB18+0x53);
 }
 return resolved;
}
void fn_8004F5EC(void *arg0,u32 arg1) {
#pragma opt_common_subs off
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

 void *res;
 void *name;
 u8 flags=M2C_FIELD(arg0,u8 *,3);
 if(!(flags&3)||(flags&4)) {
 res=get_4F5EC_resource(arg0);
 name=fn_8004B158(res);
 arg1=(u16)arg1|8;
 fn_8005C870(name,arg1);
 if(!fn_8004AF74(res,M2C_FIELD(M2C_FIELD(arg0,void **,0x190),u8 *,8))) {
 res=get_4F5EC_resource(arg0);
 switch(M2C_FIELD(M2C_FIELD(arg0,void **,0x190),u8 *,8)) {
 case 0: res=fn_8004B078(res,0);break;
case 1: res=fn_8004B078(res,1);break;
case 2: res=fn_8004B078(res,2);break;
case 3: res=fn_8004B078(res,3);break;
default: res=fn_8004B078(res,0);break;
 }
 if(!res||FileCache_Probe(res)==0x8000U) res=lbl_80366DC8;
 if(res!=lbl_80366DC8) fn_8005C870(res,arg1);
 }
 M2C_FIELD(arg0,u8 *,3)|=1;
 }
}

u8 fn_8004FA88(void *arg0, s32 arg1) {
char *fn_8004AFD4(void *,s32);
u8 FileCache_IsReady(void *);
s32 value=get_4F128_id(arg0);
void *res=get_4F128_resource(arg0,value);
return FileCache_IsReady(fn_8004AFD4(res,arg1));
}

u8 fn_8004FC70(void *arg0, s32 arg1) {
char *fn_8004AFD4(void *,s32);
u8 fn_8005C8B4(void *);
s32 value=get_4F128_id(arg0);
void *res=get_4F128_resource(arg0,value);
return fn_8005C8B4(fn_8004AFD4(res,arg1));
}

void fn_8004FE58(void *arg0) {
    extern f32 lbl_80368FCC;
    f32 f;
    *(u8 *)((u8 *)arg0 + 3) = 0;
    f = lbl_80368FCC;
    *(s16 *)((u8 *)arg0 + 0x15C) = 0;
    *(s16 *)arg0 = 0;
    *(s16 *)((u8 *)arg0 + 0x16E) = -1;
    *(s8 *)((u8 *)arg0 + 0x16D) = -1;
    *(s8 *)((u8 *)arg0 + 0x16C) = -1;
    *(f32 *)((u8 *)arg0 + 0x170) = f;
    *(f32 *)((u8 *)arg0 + 0x174) = f;
    *(f32 *)((u8 *)arg0 + 0x178) = f;
    *(s32 *)((u8 *)arg0 + 0x17C) = 0;
}

void fn_8004FE90(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 2) = arg1;
}

#pragma use_lmw_stmw on
void fn_8004FE98(s32 arg0, s8 arg1) {
    extern u8 lbl_8026AB18[];
    Unit *unit = (Unit *)arg0;
    Unk18CObj *var_r27;
    Unk18CObj *var_r26;
    s32 var_r30;
    s32 var_r27_2;
    s8 var_r28;
    s8 var_r3_3;
    void *var_r30_2;
    void *var_r27_3;
    void *var_r3_2;
    void *var_r3_5;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;
    void *temp_r30;
    u8 sp28[0x20];
    u8 sp8[0x20];

    if (unit->unk3 & 2) {
        var_r28 = unit->unk16C;
        if (var_r28 < 0) {
            var_r28 = (s8)fn_8004ABD4((void **)Unit_GetActiveItemPtr((void *)arg0), 0);
        }
        var_r27 = unit->unk18C;
        if (unit->unk3 & 4) {
            void *tmp;
            tmp = var_r27->unkC ? Res_GetByName((s32)var_r27) : NULL;
            var_r27 = tmp;
        }
        var_r30 = 0;
        if (Status_Test((u8 *)arg0 + 0x1BC, 8)) {
            if (Status_Test((u8 *)var_r27 + 0x1C, 9)) {
                var_r30 = 1;
            }
        } else if (Status_Test((u8 *)var_r27 + 0x1C, 2)) {
            var_r30 = 1;
        }
        var_r30_2 = *(void **)((u8 *)unit->unk188 + var_r30 * 4 + 0x5C);
        if (var_r30_2 == NULL) {
            var_r30_2 = var_r27->unk18;
        }
        if (var_r30_2 == NULL) {
            fn_800056A0(0);
            var_r30_2 = (u8 *)(lbl_8026AB18 + 0x52);
        }
        if (var_r30_2 == NULL || *(s8 *)var_r30_2 == 0) {
            var_r3_2 = Res_GetByName((s32)(lbl_8026AB18 + 0x53));
        } else {
            sprintf(sp28, (char *)(lbl_8026AB18 + 0x5F), var_r30_2, fn_8004B1A0(var_r28));
            temp_r3 = Res_GetByName((s32)(void *)sp28);
            if (temp_r3 == NULL) {
                fn_800056A0(0);
                var_r3_2 = Res_GetByName((s32)(lbl_8026AB18 + 0x53));
            } else {
                sprintf(sp28, (char *)(lbl_8026AB18 + 0x64), fn_8004B158((void *)arg0));
                if ((u16)FileCache_Probe(sp28) == 0x8000U) {
                    DebugPrint((char *)(lbl_8026AB18 + 0x67), sp28);
                    var_r3_2 = Res_GetByName((s32)(lbl_8026AB18 + 0x53));
                } else {
                    var_r3_2 = temp_r3;
                }
            }
        }
        unit->unk17C = var_r3_2;
        temp_r30 = (u8 *)arg0 + 0x1C;
        var_r3_3 = unit->unk16C;
        if (var_r3_3 < 0) {
            var_r3_3 = (s8)fn_8004ABD4((void **)Unit_GetActiveItemPtr((void *)arg0), 0);
        }
        var_r26 = unit->unk18C;
        if (unit->unk3 & 4) {
            void *tmp;
            tmp = var_r26->unkC ? Res_GetByName((s32)var_r26) : NULL;
            var_r26 = tmp;
        }
        var_r27_2 = 0;
        if (Status_Test((u8 *)arg0 + 0x1BC, 8)) {
            if (Status_Test((u8 *)var_r26 + 0x1C, 9)) {
                var_r27_2 = 1;
            }
        } else if (Status_Test((u8 *)var_r26 + 0x1C, 2)) {
            var_r27_2 = 1;
        }
        var_r27_3 = *(void **)((u8 *)unit->unk188 + var_r27_2 * 4 + 0x5C);
        if (var_r27_3 == NULL) {
            var_r27_3 = var_r26->unk18;
        }
        if (var_r27_3 == NULL) {
            fn_800056A0(0);
            var_r27_3 = (u8 *)(lbl_8026AB18 + 0x52);
        }
        if (var_r27_3 == NULL || *(s8 *)var_r27_3 == 0) {
            var_r3_5 = Res_GetByName((s32)(lbl_8026AB18 + 0x53));
        } else {
            sprintf(sp8, (char *)(lbl_8026AB18 + 0x5F), var_r27_3, fn_8004B1A0(var_r3_3));
            temp_r3_2 = Res_GetByName((s32)(void *)sp8);
            if (temp_r3_2 == NULL) {
                fn_800056A0(0);
                var_r3_5 = Res_GetByName((s32)(lbl_8026AB18 + 0x53));
            } else {
                sprintf(sp8, (char *)(lbl_8026AB18 + 0x64), fn_8004B158((void *)arg0));
                if ((u16)FileCache_Probe(sp8) == 0x8000U) {
                    DebugPrint((char *)(lbl_8026AB18 + 0x67), sp8);
                    var_r3_5 = Res_GetByName((s32)(lbl_8026AB18 + 0x53));
                } else {
                    var_r3_5 = temp_r3_2;
                }
            }
        }
        temp_r3_3 = (void *)0xDEADBEEF;
        if (temp_r3_3 != 0) {
            fn_8005FA14(temp_r30, 1);
            fn_8005F5B4(temp_r30, temp_r3_3);
            unit->unk2 = arg1;
        }
    }
}

#pragma opt_common_subs off
void fn_80050268(void *arg0) {
void *fn_8004B078(void *,s32);
u16 FileCache_Probe(void *);
void fn_8005F434(void *,void *,s32);
extern void *lbl_80366DC8;
void *result; void *dest;
if(M2C_FIELD(arg0,u8 *,3)&2) {
dest=(u8 *)arg0+0x1C;
result=get_4F128_resource(arg0,get_4F128_id(arg0));
switch(M2C_FIELD(M2C_FIELD(arg0,void **,0x190),u8 *,8)) {
case 0: result=fn_8004B078(result,0); break;
case 1: result=fn_8004B078(result,1); break;
case 2: result=fn_8004B078(result,2); break;
case 3: result=fn_8004B078(result,3); break;
default: result=fn_8004B078(result,0); break;
}
if(!result || FileCache_Probe(result)==0x8000) result=lbl_80366DC8;
fn_8005F434(dest,result,8);
}
}
#pragma optimization_level 2
void fn_800504FC(void *arg0, s32 arg1)
{
    void *Unit_GetActiveItemPtr(void *);
    s32 fn_8004ABD4(void *, s32);
    u8 Status_Test(void *, s32);
    void *Res_GetByName(void *);
    void fn_800056A0(s32);
    s32 fn_8004B1A0(s32);
    s32 fn_8004B158(void);
    u16 FileCache_Probe(void *);
    void fn_8004AFB4(s32, s32);
    s32 sprintf(char *, const char *, ...);
    void DebugPrint(const char *, ...);

    extern u8 lbl_8026AB18[];

    Unit *unit;
    s32 index;
    u8 *classData;
    u8 *res;
    u8 *name;
    s32 item;
    char buffer[0x20];

    unit = (Unit *)arg0;

    item = unit->unk16C;

    if (item >= 0) {
    } else {
        item = fn_8004ABD4(
            Unit_GetActiveItemPtr(unit), 0
        );
    }

    classData = (u8 *)unit->unk18C;

    if (unit->unk3 & 4) {
        res = *(u8 **)(classData + 0xC);

        if (res != 0) {
            classData = (u8 *)Res_GetByName(res);
        } else {
            classData = 0;
        }
    }

    index = 0;

    if (Status_Test((u8 *)unit + 0x1BC, 8) != 0) {
        if (Status_Test(classData + 0x1C, 9) != 0) {
            index = 1;
        }
    } else {
        if (Status_Test(classData + 0x1C, 2) != 0) {
            index = 1;
        }
    }

    res = *(u8 **)(
        (u8 *)unit->unk188 + 0x5C + index * 4
    );

    name = res;

    if (name == 0) {
        name = *(u8 **)(classData + 0x18);

        if (name == 0) {
            fn_800056A0(0);
            name = lbl_8026AB18 + 0x52;
        }
    }

    if (name != 0) {
        if ((s8)name[0] == 0) {
            Res_GetByName(lbl_8026AB18 + 0x53);
        } else {
            sprintf(
                buffer,
                (char *)lbl_8026AB18 + 0x5F,
                name,
                fn_8004B1A0(item)
            );

            if ((res = (u8 *)Res_GetByName(buffer)) == 0) {
                fn_800056A0(0);
                Res_GetByName(lbl_8026AB18 + 0x53);
            } else {
                sprintf(
                    buffer,
                    (char *)lbl_8026AB18 + 0x64,
                    fn_8004B158()
                );

                if (FileCache_Probe(buffer) == 0x8000) {
                    DebugPrint(
                        (char *)lbl_8026AB18 + 0x67,
                        buffer
                    );

                    Res_GetByName(lbl_8026AB18 + 0x53);
                }
            }
        }
    }

    fn_8004AFB4(item, arg1);
}
#pragma optimization_level reset
void fn_800506E0(void *arg0, s32 arg1)
{
    void *Unit_GetActiveItemPtr(void *);
    s32 fn_8004ABD4(void *, s32);
    u8 Status_Test(void *, s32);
    void *Res_GetByName(void *);
    void fn_800056A0(s32);
    s32 fn_8004B1A0(s32);
    s32 fn_8004B158(void);
    u16 FileCache_Probe(void *);
    void fn_8004AFD4(s32, s32);
    s32 sprintf(char *, const char *, ...);
    void DebugPrint(const char *, ...);

    extern u8 lbl_8026AB18[];

    u8 *unit;
    u8 *classData;
    u8 *res;
    u8 *name;
    s32 item;
    s32 index;
    char buffer[0x20];

    unit = (u8 *)arg0;

    item = (s8)unit[0x16C];

    if (item < 0) {
        item = fn_8004ABD4(
            Unit_GetActiveItemPtr(unit), 0
        );
    }

    classData = *(u8 **)(unit + 0x18C);

    if (unit[3] & 4) {
        res = *(u8 **)(classData + 0xC);

        if (res != 0) {
            classData = (u8 *)Res_GetByName(res);
        } else {
            classData = 0;
        }
    }

    index = 0;

    if (Status_Test(unit + 0x1BC, 8) != 0) {
        if (Status_Test(classData + 0x1C, 9) == 0) {
            index = 1;
        }
    } else {
        if (Status_Test(classData + 0x1C, 2) != 0) {
            index = 1;
        }
    }

    res = *(u8 **)(
        *(u8 **)(unit + 0x188) + 0x5C + index * 4
    );

    name = res;

    if (name == 0) {
        name = *(u8 **)(classData + 0x18);

        if (name == 0) {
            fn_800056A0(0);
            name = lbl_8026AB18 + 0x52;
        }
    }

    if (name != 0) {
        if ((s8)name[0] == 0) {
            Res_GetByName(lbl_8026AB18 + 0x53);
        } else {
            sprintf(
                buffer,
                (char *)lbl_8026AB18 + 0x5F,
                name,
                fn_8004B1A0(item)
            );

            res = (u8 *)Res_GetByName(buffer);

            if (res == 0) {
                fn_800056A0(0);
                Res_GetByName(lbl_8026AB18 + 0x53);
            } else {
                sprintf(
                    buffer,
                    (char *)lbl_8026AB18 + 0x64,
                    fn_8004B158()
                );

                if (FileCache_Probe(buffer) == 0x8000) {
                    DebugPrint(
                        (char *)lbl_8026AB18 + 0x67,
                        buffer
                    );

                    Res_GetByName(lbl_8026AB18 + 0x53);
                }
            }
        }
    }

    fn_8004AFD4(item, arg1);
}

void *fn_800508C4(void *arg0) {
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
 register s32 value;
 void *resolved;
 value=get_4F128_id(arg0);
 base=M2C_FIELD(arg0,void **,0x18C);
 if(M2C_FIELD(arg0,u8 *,3)&4) base=M2C_FIELD(base,void **,0xC)?Res_GetByName(M2C_FIELD(base,void **,0xC)):0;
 idx=0;
 if(Status_Test((u8 *)arg0+0x1BC,8)) {
 if(Status_Test((u8 *)base+0x1C,9)) idx=1;
 } else if(Status_Test((u8 *)base+0x1C,2)) idx=1;
 name=M2C_FIELD(arg0,void **,0x188);
 name=(u8 *)name+idx*4;
 name=M2C_FIELD(name,void **,0x5C);
 if(!name) name=M2C_FIELD(base,void **,0x18);
 if(!name) {fn_800056A0(0);name=lbl_8026AB18+0x52;}
 if(!name||!*(s8 *)name) return Res_GetByName(lbl_8026AB18+0x53);
 sprintf(buf,lbl_8026AB18+0x5F,name,fn_8004B1A0(value));
 resolved=Res_GetByName(buf);
 if(!resolved) {
 fn_800056A0(0);return Res_GetByName(lbl_8026AB18+0x53);
 }
 sprintf(buf,lbl_8026AB18+0x64,fn_8004B158(resolved));
 if(FileCache_Probe(buf)==0x8000U) {
 DebugPrint(lbl_8026AB18+0x67,buf);
 return Res_GetByName(lbl_8026AB18+0x53);
 }
 return resolved;
}

#pragma global_optimizer off
void *Unit_GetMapModelName(void *unit) {
    void fn_800056A0(s32);
    void *Res_GetByName(void *);
    u8 Status_Test(void *, s32);
    extern u8 lbl_8026AB18[];
    void *name;
    void *klass;
    s32 slot;
    void *r;
    u32 tmp;

    /* Pick mounted or base class map-model name; fall back to a default string. */
    r = *(void **)((u8 *)unit + 0x18C);
    klass = r;
    if (*(u8 *)((u8 *)unit + 3) & 4) {
        r = *(void **)((u8 *)r + 0xC);
        if (r != 0) {
            r = Res_GetByName(r);
        } else {
            r = 0;
        }
        klass = r;
    }
    slot = 0;
    if (Status_Test((u8 *)unit + 0x1BC, 8) != 0) {
        if (Status_Test((u8 *)klass + 0x1C, 9) != 0) {
            slot = 1;
        }
    } else if (Status_Test((u8 *)klass + 0x1C, 2) != 0) {
        slot = 1;
    }
    name = *(void **)((u8 *)unit + 0x188);
    name = (void *)((u8 *)name + (slot * 4));
    tmp = *(u32 *)((u8 *)name + 0x5C);
    name = (void *)tmp;
    if (tmp == 0) {
        name = *(void **)((u8 *)klass + 0x18);
    }
    if (name == 0) {
        fn_800056A0(0);
        name = lbl_8026AB18 + 0x52;
    }
    return name;
}
#pragma global_optimizer on
void fn_80050BA8(s32 arg0) {
    M2C_UNK fn_8005F788(s32);
    fn_8005F788(arg0 + 0x1C);
}

void Unit_SetModelAlpha(s32 arg0, u8 arg1) {
    Model_SetAlpha(arg0 + 0x1C, arg1);
}

void fn_80050BF4(void *arg0, s32 arg1)
{
    void Model_SetColor(void *, u8, u8, u8);
    void Model_SetAlpha(void *, u8);
    extern s32 gMuFlashPalette[];
    s32 sp8;
    void *r31;

    r31 = (u8 *)arg0 + 0x1c;
    sp8 = gMuFlashPalette[arg1];
    Model_SetColor(r31, ((u8 *)&sp8)[0], ((u8 *)&sp8)[1], ((u8 *)&sp8)[2]);
    Model_SetAlpha(r31, ((u8 *)&sp8)[3]);
}

void Unit_SetWorldXY(void *arg0, f32 farg0, f32 farg1) {
    f32 Map_SampleHeightRaw(void *);
    extern u8 gBattleMap[];

    *(f32 *)((u8 *)arg0 + 4) = farg0;
    *(f32 *)((u8 *)arg0 + 8) = farg1;
    *(f32 *)((u8 *)arg0 + 0xC) = Map_SampleHeightRaw(gBattleMap);
}

void fn_80050C90(void *arg0)
{
    u8 fn_80040824(void *);
    f32 Map_SampleHeightRaw(void *, f32, f32);
    void Model_SetAlpha(void *, s32);
    void *Map_Get(void);
    u8 fn_8004434C(void *, s32, s32);

    extern u8 gBattleMap[];
    extern u8 gMapBlendMode;
    extern f32 lbl_80368FC4;
    extern f64 lbl_80368FE0;

    u8 *unit;
    s32 x;
    s32 y;
    u32 flags;
    u8 mode;
    u8 enabled;
    u32 value;

    unit = (u8 *)arg0;

    if (fn_80040824(unit) != 0) {
        x = (s8)unit[0x19E];
        y = (s8)unit[0x19F];

        *(f32 *)(unit + 4) = lbl_80368FC4 + (f32)x;
        *(f32 *)(unit + 8) = lbl_80368FC4 + (f32)y;

        *(f32 *)(unit + 0xC) = Map_SampleHeightRaw(
            gBattleMap,
            *(f32 *)(unit + 4),
            *(f32 *)(unit + 8)
        );

        flags = *(u32 *)(unit + 0x1A0);
        *(u32 *)(unit + 0x1A0) = flags & ~0x240;

        Model_SetAlpha(unit + 0x1C, 0xFF);

        enabled = 1;
        mode = gMapBlendMode - 1;

        if (((u32)((1 | ~mode) -
            ((u32)(1 - mode) >> 1)) >> 31) == 0) {
            enabled = 0;
        }

        if (enabled != 0) {
            if ((*(u8 **)(unit + 0x190))[8] == 1) {
                if (gBattleMap[x + y * 0x40 + 0x200D] == 0) {
                    *(u32 *)(unit + 0x1A0) |= 0x40;
                    Model_SetAlpha(unit + 0x1C, 0);
                }
            }
        }

        if (fn_8004434C(Map_Get(), x, y) != 0) {
            *(u32 *)(unit + 0x1A0) |= 0x80;
            return;
        }

        value = *(u32 *)(unit + 0x1A0);
        *(u32 *)(unit + 0x1A0) = value & ~0x80;
    } else {
        Model_SetAlpha(unit + 0x1C, 0xFF);
    }
}

#pragma peephole off
void fn_80050E14(void) {
 extern u8 *lbl_803672CC;
 s32 i, offset, tableOffset, n;
 u8 *obj, *table, *base;
 obj=lbl_803672CC;
 if (!obj) return;
 *(s32 *)(obj+0x14)=0;
 i=*(s32 *)(obj+0x14);
 offset=i;
 tableOffset=i;
 while(i<(n=*(s32 *)(obj+0x18))) {
 base=*(u8 **)obj;
 i++;
 table=*(u8 **)(obj+4);
 *(u32 *)(table+tableOffset)=(u32)base+offset;
 offset+=20;
 tableOffset+=4;
 }
 table=*(u8 **)(obj+4);
 *(u32 *)(table+n*4)=0;
 *(void **)(obj+8)=*(void **)(obj+4);
 *(s32 *)(obj+12)=0;
 *(s32 *)(obj+16)=0;
}
#pragma peephole on
void fn_80050E80(void)
{
    void fn_800162B8(void);
    void fn_800616A0(void *);
    void fn_800C4588(void *);
    void Heap_FreeRaw(void *);
    void Heap_Free(void *);
    void fn_8006D8E8(void *);
    extern u8 lbl_802EFFE8[];
    extern void *lbl_803672B8;
    extern void *lbl_803672B4;
    extern void *lbl_803672CC;
    extern void *gUnitShadowMat;
    void *p;
    s32 i;
    void *a;
    void *b;

    fn_800162B8();
    i = 0;
    p = lbl_802EFFE8;
    do {
        fn_800616A0(p);
        i += 1;
        p = (u8 *)p + 0xA0;
    } while (i < 5);

    a = lbl_803672B8;
    if (a != 0) {
        fn_800C4588(a);
    }
    b = lbl_803672B4;
    lbl_803672B8 = 0;
    if (b != 0) {
        fn_800C4588(b);
    }
    p = lbl_803672CC;
    lbl_803672B4 = 0;
    if (p != 0 && p != 0) {
        a = *(void **)p;
        if (a != 0) {
            if (a != 0) {
                Heap_FreeRaw((u8 *)a - 0x10);
            }
            *(void **)p = 0;
        }
        a = *(void **)((u8 *)p + 4);
        if (a != 0) {
            Heap_FreeRaw(a);
            *(void **)((u8 *)p + 4) = 0;
        }
        Heap_Free(p);
    }
    b = gUnitShadowMat;
    lbl_803672CC = 0;
    fn_8006D8E8(b);
}

#pragma global_optimizer off
void Map_InitGfx(void) {
    void *fn_8006D948(void *);
    void *Heap_Alloc(s32);
    void *Heap_AllocRaw(s32);
    void *fn_8022C414(void *, void (*)(void *, s32), void *, s32, s32);
    void DCFlushRange(void *, u32);
    void *GXGetTexBufferSize(s32, s32, s32, s32, s32);
    void *fn_800C45B8(void *, void *, s32);
    void fn_80067708(s32, s32, void (*)(void), s32);
    void fn_80061824(void *);
    void sprintf(char *, char *, ...);
    void GActor_LoadGs(void *, char *);
    void GActor_LoadG(void *, char *);
    void fn_8005F5B4(void *, char *);
    void GActor_LoadTpl(void *, char *);
    void GActor_Finalize(void *);
    void Allegiance_FillMask(s32, void *);
    void fn_80052B44(void *);
    void fn_8004DE78(void);
    extern u8 lbl_8026AB18[];
    extern void *gUnitShadowMat;
    extern void *lbl_803672CC;
    extern void *lbl_803672B4;
    extern void *lbl_803672B8;
    extern u8 lbl_802EFFE8[];
    extern u8 gUnits[];
    extern f32 lbl_80368FCC;
    extern u8 lbl_803672BC;

    char sp10[0x20];
    u8 sp8[8];
    s32 a;
    s32 b;
    s32 c;

    gUnitShadowMat = fn_8006D948(lbl_8026AB18 + 0x95);
    a = (s32)Heap_Alloc(0x1C);
    if (a) {
        *(s32 *)(a + 0) = 0;
        *(s32 *)(a + 4) = 0;
        *(s32 *)(a + 8) = 0;
        *(s32 *)(a + 0x14) = 0;
        *(s32 *)(a + 0xC) = 0;
        *(s32 *)(a + 0x10) = 0;
    }
    lbl_803672CC = (void *)a;
    *(s32 *)(a + 0x18) = 0x40;
    c = *(s32 *)(a + 0x18);
    b = c * 0x14;
    *(s32 *)(a + 0) = (s32)fn_8022C414(Heap_AllocRaw(b + 0x10),
                    (void (*)(void *, s32))fn_80052B44, NULL, 0x14, c);
    *(s32 *)(a + 4) = (s32)Heap_AllocRaw((*(s32 *)(a + 0x18) + 1) * 4);
    DCFlushRange((void *)*(s32 *)(a + 0), (u32)b);
    DCFlushRange((void *)*(s32 *)(a + 4),
                 (u32)((*(s32 *)(a + 0x18) + 1) * 4));

    {
        s32 i = 0;
        s32 off;
        s32 idx;
        *(s32 *)(a + 0x14) = i;
        off = i;
        idx = i;
        while (i < *(s32 *)(a + 0x18)) {
            i += 1;
            *(s32 *)(*(s32 *)(a + 4) + idx) = *(s32 *)(a + 0) + off;
            off += 0x14;
            idx += 4;
        }
        *(s32 *)(*(s32 *)(a + 4) + (*(s32 *)(a + 0x18) << 2)) = 0;
        *(s32 *)(a + 8) = *(s32 *)(a + 4);
        *(s32 *)(a + 0xC) = 0;
        *(s32 *)(a + 0x10) = 0;
    }

    lbl_803672B4 = fn_800C45B8(GXGetTexBufferSize(0x260, 0x1C0, 0x27, 0, 0),
                               lbl_8026AB18 + 0x52, 0);
    lbl_803672B8 = fn_800C45B8(GXGetTexBufferSize(0xA0, 0x78, 0, 0, 0),
                               lbl_8026AB18 + 0x52, 0);
    fn_80067708(3, 1, fn_8004DE78, 0);

    c = (s32)lbl_802EFFE8;
    b = 0;
    a = (s32)lbl_8026AB18;
    do {
        fn_80061824((void *)c);
        if (b + 1 < 0) {
            sprintf(sp10, (char *)(lbl_8026AB18 + 0xA5),
                        (char *)(lbl_8026AB18 + 0xB0),
                        (char *)(lbl_8026AB18 + 0xB6));
        } else {
            sprintf(sp10, (char *)(lbl_8026AB18 + 0xBA),
                        (char *)(lbl_8026AB18 + 0xB0), b + 1,
                        (char *)(lbl_8026AB18 + 0xB6));
        }
        GActor_LoadGs((void *)c, sp10);
        if (b + 1 < 0) {
            sprintf(sp10, (char *)(lbl_8026AB18 + 0xA5),
                        (char *)(lbl_8026AB18 + 0xB0),
                        (char *)(lbl_8026AB18 + 0xC7));
        } else {
            sprintf(sp10, (char *)(lbl_8026AB18 + 0xBA),
                        (char *)(lbl_8026AB18 + 0xB0), b + 1,
                        (char *)(lbl_8026AB18 + 0xC7));
        }
        GActor_LoadG((void *)c, sp10);
        if (b + 1 < 0) {
            sprintf(sp10, (char *)(lbl_8026AB18 + 0xA5),
                        (char *)(lbl_8026AB18 + 0xB0),
                        (char *)(lbl_8026AB18 + 0xCA));
        } else {
            sprintf(sp10, (char *)(lbl_8026AB18 + 0xBA),
                        (char *)(lbl_8026AB18 + 0xB0), b + 1,
                        (char *)(lbl_8026AB18 + 0xCA));
        }
        fn_8005F5B4((void *)c, sp10);
        sprintf(sp10, (char *)(a + 0xA5), (char *)(a + 0xB0),
                    (char *)(a + 0xCE));
        GActor_LoadTpl((void *)c, sp10);
        GActor_Finalize((void *)c);
        b += 1;
        c += 0xA0;
    } while (b < 5);

    Allegiance_FillMask(5, sp8);
    {
        u8 id = 1;
        s32 ctr = 0x9F;
        void *unit;
        do {
            if ((u8)id != 0) {
                unit = gUnits + ((u8)id - 1) * 0x280;
            } else {
                unit = NULL;
            }
            if (*(u32 *)((u8 *)unit + 0x188) != 0 &&
                sp8[*(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)] != 0) {
                s32 z = 0;
                s32 m = -1;
                ((u8 *)unit)[3] = z;
                *(s16 *)((u8 *)unit + 0x15C) = z;
                *(s16 *)((u8 *)unit + 0) = z;
                *(s16 *)((u8 *)unit + 0x16E) = m;
                ((u8 *)unit)[0x16D] = m;
                ((u8 *)unit)[0x16C] = m;
                *(f32 *)((u8 *)unit + 0x170) = lbl_80368FCC;
                *(f32 *)((u8 *)unit + 0x174) = lbl_80368FCC;
                *(f32 *)((u8 *)unit + 0x178) = lbl_80368FCC;
                *(s32 *)((u8 *)unit + 0x17C) = z;
            }
            id += 1;
        } while (--ctr);
    }

    lbl_803672BC = 1;
}
#pragma global_optimizer reset

void fn_80051328(u8 arg0, M2C_UNK *arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    M2C_UNK PSMTXConcat(M2C_UNK *, M2C_UNK *, M2C_UNK *);
    M2C_UNK PSMTXRotRad(M2C_UNK *, M2C_UNK, f32);
    M2C_UNK PSMTXTrans(M2C_UNK *, f32, f32, f32);
    M2C_UNK fn_802026E4(M2C_UNK *, f32 *, s32 *, f32 *);
    M2C_UNK C_MTXLightOrtho(M2C_UNK *, f32, f32, f32, f32, f32, f32, f32, f32);
    M2C_UNK fn_802029C4(M2C_UNK *, s32 *, s32 *);
    extern M2C_UNK lbl_8026AA98;
    extern f32 lbl_80368FC4;
    extern f32 lbl_80368FCC;
    extern f32 lbl_80368FD8;
    extern f32 lbl_80368FDC;
    M2C_UNK spD4;
    M2C_UNK spA4;
    M2C_UNK sp74;
    M2C_UNK sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    s32 sp34;
    f32 sp30;
    f32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;

    sp2C = M2C_FIELD(&lbl_8026AA98, f32 *, 0x1C);
    sp30 = M2C_FIELD(&lbl_8026AA98, f32 *, 0x20);
    sp38 = M2C_FIELD(&lbl_8026AA98, f32 *, 0x28);
    sp3C = M2C_FIELD(&lbl_8026AA98, f32 *, 0x2C);
    sp2C = farg0;
    sp30 = farg1;
    sp38 = farg0;
    sp3C = farg1;
    sp34 = M2C_FIELD(&lbl_8026AA98, s32 *, 0x24);
    sp8 = sp2C;
    spC = sp30;
    sp10 = M2C_FIELD(&lbl_8026AA98, s32 *, 0x24);
    sp40 = M2C_FIELD(&lbl_8026AA98, s32 *, 0x30);
    sp14 = sp38;
    sp18 = sp3C;
    sp1C = M2C_FIELD(&lbl_8026AA98, s32 *, 0x30);
    sp20 = M2C_FIELD(&lbl_8026AA98, s32 *, 0x34);
    sp24 = M2C_FIELD(&lbl_8026AA98, s32 *, 0x38);
    sp28 = M2C_FIELD(&lbl_8026AA98, s32 *, 0x3C);
    if (lbl_80368FCC != farg4) {
        PSMTXRotRad(&spA4, 0x5A, lbl_80368FD8 * farg4);
        if (arg0 == 0) {
            fn_802029C4(&spA4, &sp20, &sp20);
        }
        fn_802026E4(&sp74, &sp14, &sp20, &sp8);
        C_MTXLightOrtho(&sp44, -farg2, farg2, -farg3, farg3, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
        PSMTXConcat(&sp44, &sp74, arg1);
        PSMTXTrans(&spD4, lbl_80368FDC, lbl_80368FDC, lbl_80368FCC);
        PSMTXConcat(&spA4, &spD4, &spA4);
        PSMTXTrans(&spD4, lbl_80368FC4, lbl_80368FC4, lbl_80368FCC);
        PSMTXConcat(&spD4, &spA4, &spA4);
        PSMTXConcat(&spA4, arg1, arg1);
        return;
    }
    fn_802026E4(&sp74, &sp14, &sp20, &sp8);
    C_MTXLightOrtho(&sp44, -farg2, farg2, -farg3, farg3, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
    PSMTXConcat(&sp44, &sp74, arg1);
}

void fn_80051538(s32 *arg0) {
    M2C_UNK fn_80051564(s32 *);
    s32 sp8;

    sp8 = *arg0;
    fn_80051564(&sp8);
}

void fn_80051564(u32 *arg0, u8 arg1, f32 fx, f32 fy) {
    void GXBegin(s32, s32, s32);
    f32 Map_GetTileCornerHeight(void *, s8, s8, s32);
    extern s32 gBattleMap[];
    extern f32 lbl_8036904C;
    extern f32 lbl_80369050;
    volatile f32 *wgpipe = (volatile f32 *)0xCC008000;
    u32 color;
    s32 x;
    s32 y;
    f32 z;
    u8 r, g, b, a;

    color = *arg0;
    x = (s32)fx;
    y = (s32)fy;
    if (x < 0 || y < 0 || x >= gBattleMap[0] || y >= gBattleMap[1]) {
        return;
    }
    if (arg1 != 0 && *(((u8 *)gBattleMap) + x + (y << 6) + 0x100D) == 0x1A) {
        return;
    }
    GXBegin(0x98, 0, 4);
    z = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0);
    r = ((u8 *)&color)[0];
    g = ((u8 *)&color)[1];
    b = ((u8 *)&color)[2];
    a = ((u8 *)&color)[3];
    wgpipe[0] = (f32)x;
    wgpipe[0] = (f32)y;
    wgpipe[0] = z;
    *(volatile u8 *)wgpipe = r;
    *(volatile u8 *)wgpipe = g;
    *(volatile u8 *)wgpipe = b;
    *(volatile u8 *)wgpipe = a;
    (void)lbl_8036904C;
    (void)lbl_80369050;
}

s32 Mu_GetFlashColor(s32 arg0) {
    extern s32 gMuFlashPalette[];
    return gMuFlashPalette[arg0];
}

void fn_80052B44(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
}

void *fn_80052B54(void *name, u32 priority) {
    extern u8 lbl_80285A00[];
    extern u32 lbl_80369080;
    extern const f32 lbl_80369084;
    extern const f32 lbl_80369088;
    extern const f32 lbl_8036908C;
    void *Process_Create(void *, s32);
    void *Heap_Alloc(s32);
    void *Res_GetByName(void *);
    void *nameSave;
    void *init;
    void *proc;
    u32 color;
    f32 zero;

    nameSave = name;
    if (priority == 0) {
        priority = 4;
    }
    proc = Process_Create(lbl_80285A00, priority);
    *(void **)((u8 *)proc + 0x30) = Heap_Alloc(0x60);
    init = *(void **)((u8 *)proc + 0x30);
    zero = lbl_80369084;
    *(f32 *)((u8 *)init + 0xC) = zero;
    *(f32 *)((u8 *)init + 0x10) = zero;
    *(f32 *)((u8 *)init + 0x14) = zero;
    *(u16 *)((u8 *)init + 0) = 0;
    *(s8 *)((u8 *)init + 3) = -1;
    *(s8 *)((u8 *)init + 4) = -1;
    *(u32 *)((u8 *)init + 0x30) = 0;
    *(u32 *)((u8 *)init + 0x34) = 0;
    *(u32 *)((u8 *)init + 0x3C) = 0;
    *(u32 *)((u8 *)init + 0x40) = 0;
    *(u32 *)((u8 *)init + 0x44) = 0;
    *(u32 *)((u8 *)init + 8) = 0;
    *(u32 *)((u8 *)init + 0x5C) = 0;
    *(u32 *)((u8 *)init + 0x48) = 0;
    color = lbl_80369080;
    ((u8 *)init)[0x38] = ((u8 *)&color)[0];
    ((u8 *)init)[0x39] = ((u8 *)&color)[1];
    ((u8 *)init)[0x3A] = ((u8 *)&color)[2];
    ((u8 *)init)[0x3B] = ((u8 *)&color)[3];
    *(void **)((u8 *)init + 0x2C) = Res_GetByName(nameSave);
    *(f32 *)((u8 *)init + 0x20) = lbl_80369084;
    *(f32 *)((u8 *)init + 0x24) = lbl_80369084;
    *(f32 *)((u8 *)init + 0x28) = lbl_80369084;
    *(f32 *)((u8 *)init + 0x1C) = lbl_80369088;
    *(f32 *)((u8 *)init + 0x18) = lbl_8036908C;
    ((u8 *)init)[5] = 3;
    *(u32 *)((u8 *)init + 0x4C) = 0;
    *(u32 *)((u8 *)init + 0x50) = 0;
    *(u32 *)((u8 *)init + 0x54) = 0;
    *(u32 *)((u8 *)init + 0x58) = 0;
    init = *(void **)((u8 *)proc + 0x30);
    *(u32 *)((u8 *)init + 8) |= 0x08000000;
    init = *(void **)((u8 *)proc + 0x30);
    if (((*((u8 *)(*(void **)((u8 *)init + 0x2C)) + 4)) & 0xC) == 4U) {
        *(u32 *)((u8 *)init + 8) |= 0x20000000;
    }
    return proc;
}

void fn_80052CA8(void *arg0) {
 f32 Map_SampleHeightRaw(void *,f32,f32);
 s32 fn_8005F84C(void *,s32,s32);
 void *Process_Create(void *,void *);
 extern u8 gBattleMap[],lbl_802859E0[];
 extern f32 lbl_80369098,lbl_8036909C,lbl_80369084;
 typedef struct {f32 x,y,z;} V;
 V dest,to,from,current;
 u8 *object=*(u8 **)((u8 *)arg0+0x30);
 u8 *unit;
 u8 *anim;
 u8 x,y;
 f32 duration;
 u8 *proc;
 if(*(void **)(object+0x34)==0 || *(void **)(object+0x30)==0) return;
 *(u32 *)(object+8)^=0x20000000;
 object=*(u8 **)((u8 *)arg0+0x30);
 if(*(u32 *)(object+8)&0x20000000) {
 unit=*(u8 **)(object+0x34);
 if(unit==0) unit=*(u8 **)(object+0x30);
 } else unit=*(u8 **)(object+0x30);
 x=unit[0x19e]; y=unit[0x19f];
 dest.x=lbl_80369098+(f32)(s8)x;
 dest.y=lbl_80369098+(f32)(s8)y;
 dest.z=lbl_8036909C+Map_SampleHeightRaw(gBattleMap,(f32)(s8)x,(f32)(s8)y);
 anim=*(u8 **)(*(u8 **)((u8 *)arg0+0x30)+0x5c);
 if(anim) {
 duration=(f32)fn_8005F84C(anim,(s32)*(f32 *)(anim+0x58),0x13);
 if(!(duration<lbl_80369084)) {
 object=*(u8 **)((u8 *)arg0+0x30);
 current.x=*(f32 *)(object+0xc);current.y=*(f32 *)(object+0x10);current.z=*(f32 *)(object+0x14);
 duration-=*(f32 *)(anim+0x58);
 to=dest;from=current;
 if(!(duration<lbl_80369084)) {
 proc=Process_Create(lbl_802859E0,arg0);
 *(f32 *)(proc+0x34)=from.x;*(f32 *)(proc+0x38)=from.y;*(f32 *)(proc+0x3c)=from.z;
 *(f32 *)(proc+0x40)=to.x;*(f32 *)(proc+0x44)=to.y;*(f32 *)(proc+0x48)=to.z;
 *(void **)(proc+0x30)=arg0;*(f32 *)(proc+0x4c)=duration;
 }
 }
 }
}

void MapObj_LerpPosProc(u8 *proc) {
    /* Advance map-object position lerp by one frame; clear when duration is reached. */
    f32 Math_Lerp(f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern f32 lbl_8036908C;
    f32 x;
    f32 y;
    f32 z;
    u8 *owner;

    *(f32 *)(proc + 0x50) = *(f32 *)(proc + 0x50) + lbl_8036908C;
    x = Math_Lerp(*(f32 *)(proc + 0x34), *(f32 *)(proc + 0x40), *(f32 *)(proc + 0x4C), *(f32 *)(proc + 0x50));
    y = Math_Lerp(*(f32 *)(proc + 0x38), *(f32 *)(proc + 0x44), *(f32 *)(proc + 0x4C), *(f32 *)(proc + 0x50));
    z = Math_Lerp(*(f32 *)(proc + 0x3C), *(f32 *)(proc + 0x48), *(f32 *)(proc + 0x4C), *(f32 *)(proc + 0x50));
    owner = *(u8 **)(proc + 0x30);
    *(f32 *)(*(u8 **)(owner + 0x30) + 0xC) = x;
    *(f32 *)(*(u8 **)(owner + 0x30) + 0x10) = y;
    *(f32 *)(*(u8 **)(owner + 0x30) + 0x14) = z;
    if (*(f32 *)(proc + 0x50) >= *(f32 *)(proc + 0x4C)) {
        Process_ClearFunc(proc);
    }
}

void fn_80052F90(void *arg0) {
    extern f32 lbl_80369084;
    M2C_FIELD(arg0, f32 *, 0x50) = (f32) lbl_80369084;
}

s32 fn_80052F9C(void *arg0) {
    return M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), void **, 0x2C), u8 *, 4) & 3;
}

void fn_80052FB0(void *arg0, f32 *arg1, f32 *arg2) {
    f32 fn_80059440(f32, f32, f32, f32);
    extern f32 lbl_8036909C;
    void *temp_r3;
    f32 *var_r4;
    f32 x;
    f32 y;
    f32 z;

    if (arg1 != NULL && arg2 != NULL) {
        *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x24) =
            fn_80059440(arg1[0], arg1[1], arg2[0], arg2[1]);
    }

    temp_r3 = *(void **)((u8 *)arg0 + 0x30);
    if ((*(u32 *)((u8 *)temp_r3 + 8) & 0x20000000) && arg1 != NULL) {
        var_r4 = arg1;
    } else {
        var_r4 = arg2;
    }

    if (var_r4 != NULL) {
        z = var_r4[2];
        y = var_r4[1];
        x = var_r4[0];
        *(f32 *)((u8 *)temp_r3 + 0xC) = x;
        z = lbl_8036909C + z;
        *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x10) = y;
        *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x14) = z;
    }
}

void fn_8005306C(void *arg0) {
    f32 Map_SampleHeightRaw(M2C_UNK *, f32, f32, f32);
    f32 Math_Angle2D(f32, f32, f32, f32);
    extern M2C_UNK gBattleMap;
    extern f32 lbl_80369098;
    extern f32 lbl_8036909C;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 *var_r30;
    f32 *var_r31;
    f32 *var_r3;
    f32 temp_f3;
    f32 temp_f3_2;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r0_3;
    u8 temp_r0_4;
    void *temp_r29;
    void *temp_r3;
    void *temp_r4;
    void *temp_r5;

    var_r31 = NULL;
    var_r30 = NULL;
    temp_r3 = M2C_FIELD(arg0, void **, 0x30);
    temp_r5 = M2C_FIELD(temp_r3, void **, 0x34);
    temp_r29 = M2C_FIELD(temp_r3, void **, 0x30);
    if (temp_r5 != NULL) {
        temp_r0 = M2C_FIELD(temp_r5, u8 *, 0x19E);
        sp14 = lbl_80369098 + (f32) (s8) temp_r0;
        temp_r0_2 = M2C_FIELD(temp_r5, u8 *, 0x19F);
        temp_f3 = lbl_80369098 + (f32) (s8) temp_r0_2;
        sp18 = temp_f3;
        sp1C = Map_SampleHeightRaw(&gBattleMap, (f32) (s8) temp_r0, (f32) (s8) temp_r0_2, temp_f3);
        var_r31 = &sp14;
    }
    if (temp_r29 != NULL) {
        temp_r0_3 = M2C_FIELD(temp_r29, u8 *, 0x19E);
        sp8 = lbl_80369098 + (f32) (s8) temp_r0_3;
        temp_r0_4 = M2C_FIELD(temp_r29, u8 *, 0x19F);
        temp_f3_2 = lbl_80369098 + (f32) (s8) temp_r0_4;
        spC = temp_f3_2;
        sp10 = Map_SampleHeightRaw(&gBattleMap, (f32) (s8) temp_r0_3, (f32) (s8) temp_r0_4, temp_f3_2);
        var_r30 = &sp8;
    }
    if ((var_r31 != NULL) && (var_r30 != NULL)) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x24) = Math_Angle2D(M2C_FIELD(var_r31, f32 *, 0), M2C_FIELD(var_r31, f32 *, 4), M2C_FIELD(var_r30, f32 *, 0), M2C_FIELD(var_r30, f32 *, 4));
    }
    temp_r4 = M2C_FIELD(arg0, void **, 0x30);
    if ((M2C_FIELD(temp_r4, s32 *, 8) & 0x20000000) && (var_r31 != NULL)) {
        var_r3 = var_r31;
    } else {
        var_r3 = var_r30;
    }
    if (var_r3 != NULL) {
        M2C_FIELD(temp_r4, f32 *, 0xC) = (f32) M2C_FIELD(var_r3, f32 *, 0);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x10) = (f32) M2C_FIELD(var_r3, f32 *, 4);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x14) = (f32) (lbl_8036909C + M2C_FIELD(var_r3, f32 *, 8));
    }
}

#pragma use_lmw_stmw on
static inline void *MapObj_GetOwner(void *base) {
    void *obj;
    if (*(u32 *)((u8 *)base + 8) & 0x20000000) {
        obj = *(void **)((u8 *)base + 0x34);
        if (obj != NULL) return obj;
    }
    return *(void **)((u8 *)base + 0x30);
}
void MapObj_UpdateMatrix(void *arg0)
{
    /* Build map-object world matrix: billboard, fixed, or free rot (+slope). */
    void *Map_Get(void);
    void Map_BuildSlopeMatrix(void *, void *, f32, f32);
    void fn_8004E670(f32 *, void *, s32);
    void fn_8005A1E8(s32, f32 *, f32 *);
    void PSMTXIdentity(void *);
    void PSMTXCopy(void *, void *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    extern f32 lbl_803690A0;
    extern f32 lbl_803690A4;
    extern f64 lbl_80369090;
    extern f32 lbl_803690A8;
    extern f32 lbl_803690AC;
    extern f32 lbl_803690B0;
    extern f64 lbl_803690B8;
    typedef struct { f32 x, y, z; } Vec;
    u8 sp14C[0x30];
    u8 sp11C[0x30];
    u8 spEC[0x30];
    u8 spBC[0x30];
    u8 sp8C[0x30];
    u8 sp5C[0x30];
    u8 sp2C[0x30];
    Vec pos;
    Vec tmp;
    Vec src;
    f32 scale;
    void *node;
    void *cam;
    void *obj;
    void *base;
    u32 flags;
    u8 mode;

    base = *(void **)((u8 *)arg0 + 0x30);
    src.x = *(f32 *)((u8 *)base + 0xC);
    scale = *(f32 *)((u8 *)base + 0x18);
    src.y = *(f32 *)((u8 *)base + 0x10);
    src.z = *(f32 *)((u8 *)base + 0x14);
    pos = src;
    node = *(void **)((u8 *)base + 0x5C);
    flags = *(u32 *)((u8 *)base + 0x8);
    obj = MapObj_GetOwner(base);
    if (obj == NULL) {
        cam = NULL;
    } else {
        cam = *(void **)((u8 *)obj + 0x280);
    }
    PSMTXIdentity(sp11C);
    PSMTXRotRad(spBC, 0x58, lbl_803690A0);
    base = *(void **)((u8 *)arg0 + 0x30);
    if (*(u32 *)((u8 *)base + 0x8) & 8) {
        scale *= lbl_803690A4;
        *(f32 *)((u8 *)base + 0x1C) = (f32)(s16)pos.z;
    } else {
        switch (*(u8 *)(*(u8 **)((u8 *)base + 0x2C) + 4) & 3) {
        case 1:
            scale *= lbl_803690A4;
            if (cam != NULL) {
                fn_8004E670(&tmp.x, cam, 1);
                pos.x = tmp.x;
                pos.y = tmp.y;
                pos.z = tmp.z;
            } else {
                fn_8005A1E8(0, &pos.x, &pos.x);
            }
            pos.z = (f32)(s32)*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x1C);
            break;
        case 2:
            pos.x = lbl_803690A8;
            scale *= lbl_803690A4;
            pos.y = lbl_803690AC;
            pos.z = (f32)(s32)*(f32 *)((u8 *)base + 0x1C);
            break;
        default:
            PSMTXRotRad(sp8C, 0x58, lbl_803690B0 * *(f32 *)((u8 *)base + 0x20));
            base = *(void **)((u8 *)arg0 + 0x30);
            PSMTXRotRad(sp5C, 0x59, lbl_803690B0 * *(f32 *)((u8 *)base + 0x24));
            base = *(void **)((u8 *)arg0 + 0x30);
            PSMTXRotRad(sp2C, 0x5A, lbl_803690B0 * *(f32 *)((u8 *)base + 0x28));
            PSMTXConcat(sp5C, sp8C, sp11C);
            PSMTXConcat(sp2C, sp11C, sp11C);
            cam = Map_Get();
            if (cam != NULL) {
                PSMTXCopy((u8 *)cam + 0x70, spBC);
                mode = *(u8 *)((u8 *)cam + 0x68);
                switch (mode) {
                case 0:
                    scale = (f32)((f64)scale * lbl_803690B8);
                    if (*(u32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x8) & 0x40) {
                        Map_BuildSlopeMatrix(cam, sp8C, pos.x, pos.y);
                        PSMTXConcat(sp8C, spBC, spBC);
                    }
                    break;
                case 1:
                    break;
                }
            }
            break;
        }
    }
    PSMTXScale(sp14C, scale, scale, scale);
    PSMTXTrans(spEC, pos.x, pos.y, pos.z);
    PSMTXConcat(sp14C, sp11C, sp14C);
    PSMTXConcat(spBC, sp14C, sp14C);
    PSMTXConcat(spEC, sp14C, (u8 *)node + 0x10);
}
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
void fn_800535B0(void *arg0) {
    void DebugPrint(void *, ...);
    void *fn_8004AF30(u16);
    s32 fn_8005F8E4(void *, u16 *);
    s8 fn_80146BE4(void *);
    void SeCue_FadeOut(s8, s32);
    extern u8 GActor_str[];

    u16 buf[0x40];
    u8 *strBase;
    s32 count;
    u16 *p;
    s32 i;
    void *unit;
    s8 slot;
    void *inner;
    void *list;

    inner = *(void **)((u8 *)arg0 + 0x30);
    list = *(void **)((u8 *)inner + 0x5C);
    *((u8 *)inner + 3) = 0x1E;
    if (list != NULL) {
        count = fn_8005F8E4(list, buf);
        p = buf;
        i = 0;
        strBase = GActor_str;
        goto check;
        do {
            unit = fn_8004AF30(*p);
            if (unit != NULL) {
                slot = fn_80146BE4(unit);
                if (slot >= 0) {
                    DebugPrint(strBase + 0x106, unit);
                    SeCue_FadeOut(slot, 0xFA);
                }
            }
            p++;
            i++;
        check:
            ;
        } while (i < count);
    }
}
#pragma use_lmw_stmw reset
void fn_80053658(void *arg0, s32 arg1, s32 arg2) {
    u8 *p;

    p = *(u8 **)((u8 *)arg0 + 0x30);
    p = p + (arg1 << 2);
    *(s32 *)(p + 0x4C) = arg2;
}

void fn_8005366C(void *arg0, s32 arg1, s32 arg2) {
    u8 *p;

    p = *(u8 **)((u8 *)arg0 + 0x30);
    p = p + (arg1 << 2);
    *(s32 *)(p + 0x4C) = arg2;
}

#pragma scheduling off
#pragma global_optimizer off
void fn_80053680(void *arg0, void *arg1)
{
    extern f32 lbl_8036909C;
    f32 x;
    f32 z;
    f32 bias;
    f32 y;
    f32 *dst;

    z = *(f32 *)((u8 *)arg1 + 0xC);
    y = *(f32 *)((u8 *)arg1 + 0x8);
    x = *(f32 *)((u8 *)arg1 + 0x4);
    dst = *(f32 **)((u8 *)arg0 + 0x30);
    bias = lbl_8036909C;
    dst[3] = x;
    x = bias + z;
    dst = *(f32 **)((u8 *)arg0 + 0x30);
    dst[4] = y;
    arg0 = *(f32 **)((u8 *)arg0 + 0x30);
    ((f32 *)arg0)[5] = x;
}
#pragma global_optimizer on
#pragma scheduling on
void Effect_SetPos(void *arg0, f32 farg0, f32 farg1, f32 farg2) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0xC) = farg0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x10) = farg1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x14) = farg2;
}

void fn_800536CC(void *arg0, s32 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x34) = arg1;
}

void fn_800536D8(void *arg0, s32 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x30) = arg1;
}

void fn_800536E4(void *arg0, void *arg1) {
    if ((u32) M2C_FIELD(arg0, u32 *, 0x18) == (u32) M2C_FIELD(arg1, u32 *, 0)) {
        M2C_FIELD(arg1, void **, 4) = arg0;
    }
}

void *fn_800536FC(u16 arg0) {
    void fn_80053750(void *, void *);
    void GfxEnt_ForEachKey(void *, void *, void *);
    extern u8 lbl_80285990[];
    struct {
        u16 value;
        u16 padding;
        void *result;
    } data;

    data.value = arg0;
    data.result = NULL;
    GfxEnt_ForEachKey(lbl_80285990, fn_80053750, &data);
    if (data.result != NULL) {
        return data.result;
    }
    return NULL;
}

void fn_80053750(void *arg0, void *arg1) {
    if ((u16) M2C_FIELD(arg1, u16 *, 0) == (u16) *M2C_FIELD(arg0, u16 **, 0x30)) {
        M2C_FIELD(arg1, void **, 4) = arg0;
    }
}

void fn_8005376C(void) {
    u32 Process_Find(u32 *);
    void *Process_UnlinkByKey(u32 *);
    void *Process_Create(void *, s32);
    s32 fn_801451BC(void);
    u8 fn_80145308(void);
    void DebugPrint(const char *, ...);
    void *temp_r3;

    extern u32 lbl_80285990[];
    extern u8 GActor_str[];
    extern u8 lbl_80285968[];

    Process_UnlinkByKey(lbl_80285990);
    if ((Process_Find(lbl_80285990) == 0U) && (fn_80145308() == 0)) {
        fn_801451BC();
        DebugPrint((const char *)((u8 *) &GActor_str + 0x12E));
        return;
    }
    temp_r3 = Process_Create(lbl_80285968, 4);
    *(s32 *)((u8 *) temp_r3 + 0x60) = 0;
}
#pragma cplusplus reset
s32 fn_800537E8(void) {
    extern u16 lbl_80285990[];
    s32 v = Process_Find(lbl_80285990);
    return v != 0;
}

void *fn_8005381C(void *name, void *parent)
{
  extern u8 lbl_80285990[];
  extern u32 lbl_80369080;
  extern const f32 lbl_80369084;
  extern const f32 lbl_80369088;
  extern const f32 lbl_8036908C;
  extern const f32 lbl_803690C0;
  void *Process_CreateChild(void *, void *);
  void *Heap_Alloc(s32);
  void *Res_GetByName(void *);
  void *nameSave;
  void *new_var2[2];
  u8 *new_var;
  u32 color;
  f32 zero;
  nameSave = name;
  new_var2[1] = Process_CreateChild(lbl_80285990, parent);
  *((void **) (((u8 *) new_var2[1]) + 0x30)) = Heap_Alloc(0x60);
  new_var2[0] = *((void **) (((u8 *) new_var2[1]) + 0x30));
  zero = lbl_80369084;
  *((f32 *) (((u8 *) new_var2[0]) + 0xC)) = zero;
  *((f32 *) (((u8 *) new_var2[0]) + 0x10)) = zero;
  *((f32 *) (((u8 *) new_var2[0]) + 0x14)) = zero;
  *((u16 *) (((u8 *) new_var2[0]) + 0)) = 0;
  *((s8 *) (((u8 *) new_var2[0]) + 3)) = -1;
  *((s8 *) (((u8 *) new_var2[0]) + 4)) = -1;
  *((u32 *) (((u8 *) new_var2[0]) + 0x30)) = 0;
  *((u32 *) (((u8 *) new_var2[0]) + 0x34)) = 0;
  *((u32 *) (((u8 *) new_var2[0]) + 0x3C)) = 0;
  *((u32 *) (((u8 *) new_var2[0]) + 0x40)) = 0;
  *((u32 *) (((u8 *) new_var2[0]) + 0x44)) = 0;
  *((u32 *) (((u8 *) new_var2[0]) + 8)) = 0;
  *((u32 *) (((u8 *) new_var2[0]) + 0x5C)) = 0;
  *((u32 *) (((u8 *) new_var2[0]) + 0x48)) = 0;
  color = lbl_80369080;
  ((u8 *) new_var2[0])[0x38] = ((u8 *) (&color))[0];
  ((u8 *) new_var2[0])[0x39] = ((u8 *) (&color))[1];
  ((u8 *) new_var2[0])[0x3A] = ((u8 *) (&color))[2];
  ((u8 *) new_var2[0])[0x3B] = ((u8 *) (&color))[3];
  *((void **) (((u8 *) new_var2[0]) + 0x2C)) = Res_GetByName(nameSave);
  *((f32 *) (((u8 *) new_var2[0]) + 0x20)) = lbl_80369084;
  *((f32 *) (((u8 *) new_var2[0]) + 0x24)) = lbl_80369084;
  *((f32 *) (((u8 *) new_var2[0]) + 0x28)) = lbl_80369084;
  *((f32 *) (((u8 *) new_var2[0]) + 0x1C)) = lbl_80369088;
  *((f32 *) (((u8 *) new_var2[0]) + 0x18)) = lbl_8036908C;
  ((u8 *) new_var2[0])[5] = 3;
  *((u32 *) (((u8 *) new_var2[0]) + 0x4C)) = 0;
  *((u32 *) (((u8 *) new_var2[0]) + 0x50)) = 0;
  *((u32 *) (((u8 *) new_var2[0]) + 0x54)) = 0;
  *((u32 *) (((u8 *) new_var2[0]) + 0x58)) = 0;
  new_var2[0] = *((void **) (((u8 *) new_var2[1]) + 0x30));
  *((u32 *) (((u8 *) new_var2[0]) + 8)) |= 0x08000000;
  new_var2[0] = *((void **) (((u8 *) new_var2[1]) + 0x30));
  new_var = (u8 *) new_var2[1];
  if (((*(((u8 *) (*((void **) (((u8 *) new_var2[0]) + 0x2C)))) + 4)) & 0xC) == 4U)
  {
    *((u32 *) (((u8 *) new_var2[0]) + 8)) |= 0x20000000;
  }
  new_var2[0] = *((void **) (new_var + 0x30));
  *((u32 *) (((u8 *) new_var2[0]) + 8)) |= 8;
  new_var2[0] = *((void **) (new_var + 0x30));
  *((f32 *) (((u8 *) new_var2[0]) + 0x1C)) = lbl_803690C0;
  return new_var2[1];
}

void *fn_8005397C(void *name, u32 priority) {
    extern u8 lbl_80285990[];
    extern u32 lbl_80369080;
    extern const f32 lbl_80369084;
    extern const f32 lbl_80369088;
    extern const f32 lbl_8036908C;
extern const f32 lbl_803690C0;
    void *Process_Create(void *, s32);
    void *Heap_Alloc(s32);
    void *Res_GetByName(void *);
    void *nameSave;
    void *init;
    void *proc;
    u32 color;
    f32 zero;
    nameSave = name;
    if (priority == 0) priority = 4;
    proc = Process_Create(lbl_80285990, priority);
    init = Heap_Alloc(0x60);
    *(void **)((u8 *)proc + 0x30) = init;
    init = *(void **)((u8 *)proc + 0x30);
    zero = lbl_80369084;
    *(f32 *)((u8 *)init + 0xC) = zero;
    *(f32 *)((u8 *)init + 0x10) = zero;
    *(f32 *)((u8 *)init + 0x14) = zero;
    *(u16 *)((u8 *)init + 0) = 0;
    *(s8 *)((u8 *)init + 3) = -1;
    *(s8 *)((u8 *)init + 4) = -1;
    *(u32 *)((u8 *)init + 0x30) = 0;
    *(u32 *)((u8 *)init + 0x34) = 0;
    *(u32 *)((u8 *)init + 0x3C) = 0;
    *(u32 *)((u8 *)init + 0x40) = 0;
    *(u32 *)((u8 *)init + 0x44) = 0;
    *(u32 *)((u8 *)init + 8) = 0;
    *(u32 *)((u8 *)init + 0x5C) = 0;
    *(u32 *)((u8 *)init + 0x48) = 0;
    color = lbl_80369080;
    ((u8 *)init)[0x38] = ((u8 *)&color)[0];
    ((u8 *)init)[0x39] = ((u8 *)&color)[1];
    ((u8 *)init)[0x3A] = ((u8 *)&color)[2];
    ((u8 *)init)[0x3B] = ((u8 *)&color)[3];
    *(void **)((u8 *)init + 0x2C) = Res_GetByName(nameSave);
    *(f32 *)((u8 *)init + 0x20) = lbl_80369084;
    *(f32 *)((u8 *)init + 0x24) = lbl_80369084;
    *(f32 *)((u8 *)init + 0x28) = lbl_80369084;
    *(f32 *)((u8 *)init + 0x1C) = lbl_80369088;
    *(f32 *)((u8 *)init + 0x18) = lbl_8036908C;
    ((u8 *)init)[5] = 3;
    *(u32 *)((u8 *)init + 0x4C) = 0;
    *(u32 *)((u8 *)init + 0x50) = 0;
    *(u32 *)((u8 *)init + 0x54) = 0;
    *(u32 *)((u8 *)init + 0x58) = 0;
    init = *(void **)((u8 *)proc + 0x30);
    *(u32 *)((u8 *)init + 8) |= 0x08000000;
    init = *(void **)((u8 *)proc + 0x30);
    if (((*((u8 *)(*(void **)((u8 *)init + 0x2C)) + 4)) & 0xC) == 4U) {
        *(u32 *)((u8 *)init + 8) |= 0x20000000;
    }
    init = *(void **)((u8 *)proc + 0x30);
    *(u32 *)((u8 *)init + 8) |= 8;
    init = *(void **)((u8 *)proc + 0x30);
    *(f32 *)((u8 *)init + 0x1C) = lbl_803690C0;
    return proc;
}

void *fn_80053AE8(void *name, void *parent) {
    extern u8 lbl_80285990[];
    extern u32 lbl_80369080;
    extern const f32 lbl_80369084;
    extern const f32 lbl_80369088;
    extern const f32 lbl_8036908C;
    void *Process_CreateChild(void *, void *);
    void *Heap_Alloc(s32);
    void *Res_GetByName(void *);
    void *nameSave;
    void *init;
    void *proc;
    u32 color;
    f32 zero;
    nameSave = name;
    proc = Process_CreateChild(lbl_80285990, parent);
    *(void **)((u8 *)proc + 0x30) = Heap_Alloc(0x60);
    init = *(void **)((u8 *)proc + 0x30);
    zero = lbl_80369084;
    *(f32 *)((u8 *)init + 0xC) = zero;
    *(f32 *)((u8 *)init + 0x10) = zero;
    *(f32 *)((u8 *)init + 0x14) = zero;
    *(u16 *)((u8 *)init + 0) = 0;
    *(s8 *)((u8 *)init + 3) = -1;
    *(s8 *)((u8 *)init + 4) = -1;
    *(u32 *)((u8 *)init + 0x30) = 0;
    *(u32 *)((u8 *)init + 0x34) = 0;
    *(u32 *)((u8 *)init + 0x3C) = 0;
    *(u32 *)((u8 *)init + 0x40) = 0;
    *(u32 *)((u8 *)init + 0x44) = 0;
    *(u32 *)((u8 *)init + 8) = 0;
    *(u32 *)((u8 *)init + 0x5C) = 0;
    *(u32 *)((u8 *)init + 0x48) = 0;
    color = lbl_80369080;
    ((u8 *)init)[0x38] = ((u8 *)&color)[0];
    ((u8 *)init)[0x39] = ((u8 *)&color)[1];
    ((u8 *)init)[0x3A] = ((u8 *)&color)[2];
    ((u8 *)init)[0x3B] = ((u8 *)&color)[3];
    *(void **)((u8 *)init + 0x2C) = Res_GetByName(nameSave);
    *(f32 *)((u8 *)init + 0x20) = lbl_80369084;
    *(f32 *)((u8 *)init + 0x24) = lbl_80369084;
    *(f32 *)((u8 *)init + 0x28) = lbl_80369084;
    *(f32 *)((u8 *)init + 0x1C) = lbl_80369088;
    *(f32 *)((u8 *)init + 0x18) = lbl_8036908C;
    ((u8 *)init)[5] = 3;
    *(u32 *)((u8 *)init + 0x4C) = 0;
    *(u32 *)((u8 *)init + 0x50) = 0;
    *(u32 *)((u8 *)init + 0x54) = 0;
    *(u32 *)((u8 *)init + 0x58) = 0;
    init = *(void **)((u8 *)proc + 0x30);
    *(u32 *)((u8 *)init + 8) |= 0x08000000;
    init = *(void **)((u8 *)proc + 0x30);
    if (((*((u8 *)(*(void **)((u8 *)init + 0x2C)) + 4)) & 0xC) == 4U) {
        *(u32 *)((u8 *)init + 8) |= 0x20000000;
    }
    return proc;
}

void *Effect_Create(void *name, u32 priority) {
    extern u8 lbl_80285990[];
    extern u32 lbl_80369080;
    extern const f32 lbl_80369084;
    extern const f32 lbl_80369088;
    extern const f32 lbl_8036908C;
    void *Process_Create(void *, s32);
    void *Heap_Alloc(s32);
    void *Res_GetByName(void *);
    void *nameSave;
    void *init;
    void *proc;
    u32 color;
    f32 zero;

    nameSave = name;
    if (priority == 0) {
        priority = 4;
    }
    proc = Process_Create(lbl_80285990, priority);
    *(void **)((u8 *)proc + 0x30) = Heap_Alloc(0x60);
    init = *(void **)((u8 *)proc + 0x30);
    zero = lbl_80369084;
    *(f32 *)((u8 *)init + 0xC) = zero;
    *(f32 *)((u8 *)init + 0x10) = zero;
    *(f32 *)((u8 *)init + 0x14) = zero;
    *(u16 *)((u8 *)init + 0) = 0;
    *(s8 *)((u8 *)init + 3) = -1;
    *(s8 *)((u8 *)init + 4) = -1;
    *(u32 *)((u8 *)init + 0x30) = 0;
    *(u32 *)((u8 *)init + 0x34) = 0;
    *(u32 *)((u8 *)init + 0x3C) = 0;
    *(u32 *)((u8 *)init + 0x40) = 0;
    *(u32 *)((u8 *)init + 0x44) = 0;
    *(u32 *)((u8 *)init + 8) = 0;
    *(u32 *)((u8 *)init + 0x5C) = 0;
    *(u32 *)((u8 *)init + 0x48) = 0;
    color = lbl_80369080;
    ((u8 *)init)[0x38] = ((u8 *)&color)[0];
    ((u8 *)init)[0x39] = ((u8 *)&color)[1];
    ((u8 *)init)[0x3A] = ((u8 *)&color)[2];
    ((u8 *)init)[0x3B] = ((u8 *)&color)[3];
    *(void **)((u8 *)init + 0x2C) = Res_GetByName(nameSave);
    *(f32 *)((u8 *)init + 0x20) = lbl_80369084;
    *(f32 *)((u8 *)init + 0x24) = lbl_80369084;
    *(f32 *)((u8 *)init + 0x28) = lbl_80369084;
    *(f32 *)((u8 *)init + 0x1C) = lbl_80369088;
    *(f32 *)((u8 *)init + 0x18) = lbl_8036908C;
    ((u8 *)init)[5] = 3;
    *(u32 *)((u8 *)init + 0x4C) = 0;
    *(u32 *)((u8 *)init + 0x50) = 0;
    *(u32 *)((u8 *)init + 0x54) = 0;
    *(u32 *)((u8 *)init + 0x58) = 0;
    init = *(void **)((u8 *)proc + 0x30);
    *(u32 *)((u8 *)init + 8) |= 0x08000000;
    init = *(void **)((u8 *)proc + 0x30);
    if (((*((u8 *)(*(void **)((u8 *)init + 0x2C)) + 4)) & 0xC) == 4U) {
        *(u32 *)((u8 *)init + 8) |= 0x20000000;
    }
    return proc;
}

void fn_80053D84(void *arg0) {
    void *temp_r3;

    temp_r3 = M2C_FIELD(arg0, void **, 0x30);
    M2C_FIELD(temp_r3, s32 *, 8) = (s32) (M2C_FIELD(temp_r3, s32 *, 8) | 0x80000000);
}

void fn_80053D98(void *arg0, s32 arg1) {
 void fn_80055D9C(void *);
 void *Process_Create(void *, s32);
 void fn_800616A0(void *);
 void sprintf(void *, void *, ...);
 void fn_8005C7C8(void *);
 void fn_800C4588(void *);
 void fn_80053E9C(void *);
 void fn_80059138(void (*)(void *), void *, s32, s32);
 extern u32 gGameFlags;
 extern u8 lbl_80285968[];
 extern u8 GActor_str[];
 char buf[0x40];
 void *obj;
 void (*callback)(void *, void *);
 obj=M2C_FIELD(arg0,void **,0x30);
 callback=M2C_FIELD(obj,void (**)(void *,void *),0x44);
 if(callback) callback(arg0,obj);
 fn_80055D9C(M2C_FIELD(M2C_FIELD(arg0,void **,0x30),void **,0x48));
 if(M2C_FIELD(M2C_FIELD(arg0,void **,0x30),u32 *,8)&0x40000000) gGameFlags &= ~1U;
 if(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void **,0x30),void **,0x2C),u8 *,5)) {
 void *proc=Process_Create(lbl_80285968,4);
 M2C_FIELD(proc,s32 *,0x60)=0x708;
 }
 arg0=M2C_FIELD(arg0,void **,0x30);
 if(M2C_FIELD(arg0,u32 *,8)&0x88000000) {
 obj=M2C_FIELD(arg0,void **,0x5C);
 if(obj) {
 fn_800616A0(obj);
 sprintf(buf,GActor_str+0x120,GActor_str+0x129,**(void ***)((u8 *)arg0+0x2C));
 fn_8005C7C8(buf);
 }
 fn_800C4588(arg0);
 } else fn_80059138(fn_80053E9C,arg0,1,2);
}

void fn_80053E9C(void *arg0) {
    void fn_800616A0(void *);
    void sprintf(void *, void *, ...);
    void fn_8005C7C8(void *);
    void fn_800C4588(void *);
    extern u8 GActor_str[];
    char sp8[0x40];
    void *temp;

    temp = *(void **)((u8 *)arg0 + 0x5C);
    if (temp != NULL) {
        fn_800616A0(temp);
        sprintf(sp8, GActor_str + 0x120, GActor_str + 0x129,
                    **(void ***)((u8 *)arg0 + 0x2C));
        fn_8005C7C8(sp8);
    }
    fn_800C4588(arg0);
}

void fn_80053F08(void *arg0) {
    void fn_800536E4(void *, void *);
    void GfxEnt_ForEachKey(void *, void *, void *);
    void Process_ClearFunc(void *);
    extern u8 lbl_80285990[];
    struct {
        void *value;
        void *result;
    } data;

    data.value = arg0;
    data.result = NULL;
    GfxEnt_ForEachKey(lbl_80285990, fn_800536E4, &data);
    if (data.result == NULL) {
        Process_ClearFunc(arg0);
    }
}

#pragma use_lmw_stmw on
void fn_80053F68(void *arg0) {
    f32 Math_Lerp(f32, f32, f32, f32);
    void Model_SetColor(void *, u8, u8, u8);
    void Model_SetAlpha(void *, u8);
    void fn_8005E644(void *);
    void fn_80060060(void *);
    void fn_800609DC(void *);
    void fn_8006CAD4(void *);
    void Process_ClearFunc(void *);
    void MapObj_UpdateMatrix(void *);
    void fn_800548E8(void *);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_SetColorByte(u8);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Prim2D_AddPrim(s32);
    void fn_80007340(void *, void *);
    void Prim2D_EndPrim(void);
    u8 fn_800AA188(void);
    extern f32 lbl_80369084;
    extern f32 lbl_8036908C;
    extern f64 lbl_80369090;
    extern f32 lbl_803690C4;
    extern f32 lbl_803690C8;
    extern void fn_80054314;

    typedef struct { f32 x, y, z; } Vec3;
    u32 color;
    Vec3 tmp2;
    Vec3 tmp;
    void *inner;
    void *gfx;
    u8 ok;
    void *other;
    s32 alpha;
    u8 (*cb)(void *);
    void (*cb2)(void *);
    s32 cnt;
    void *dst;
    void *src;
    u32 flags;
    u32 fl;
    u8 b;

    inner = *(void **)((u8 *)arg0 + 0x30);
    flags = *(u32 *)((u8 *)inner + 8);
    gfx = *(void **)((u8 *)inner + 0x5C);

    if ((flags & 0x30) == 0) {
        ok = 1;
    } else if (flags & 0x10) {
        ok = 0;
    } else if ((flags & 0x20) && fn_800AA188() == 0) {
        ok = 0;
    } else {
        ok = 1;
    }

    if (ok) {
        inner = *(void **)((u8 *)arg0 + 0x30);
        if ((((fl = *(u32 *)((u8 *)inner + 8)) >> 28) & 1) &&
            (other = *(void **)((u8 *)arg0 + 0x18)) != 0) {
            *(u32 *)((u8 *)inner + 8) = fl | 0x10000000;
            *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x30) =
                *(s32 *)((u8 *)*(void **)((u8 *)other + 0x30) + 0x30);
            *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x34) =
                *(s32 *)((u8 *)*(void **)((u8 *)other + 0x30) + 0x34);
            dst = *(void **)((u8 *)arg0 + 0x30);
            src = *(void **)((u8 *)other + 0x30);
            tmp.x = *(f32 *)((u8 *)src + 0xC);
            tmp.y = *(f32 *)((u8 *)src + 0x10);
            tmp.z = *(f32 *)((u8 *)src + 0x14);
            tmp2 = tmp;
            *(f32 *)((u8 *)dst + 0xC) = tmp2.x;
            dst = *(void **)((u8 *)arg0 + 0x30);
            *(f32 *)((u8 *)dst + 0x10) = tmp2.y;
            dst = *(void **)((u8 *)arg0 + 0x30);
            *(f32 *)((u8 *)dst + 0x14) = tmp2.z;
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x18) =
                *(f32 *)((u8 *)*(void **)((u8 *)other + 0x30) + 0x18);
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x20) =
                *(f32 *)((u8 *)*(void **)((u8 *)other + 0x30) + 0x20);
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x24) =
                *(f32 *)((u8 *)*(void **)((u8 *)other + 0x30) + 0x24);
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x28) =
                *(f32 *)((u8 *)*(void **)((u8 *)other + 0x30) + 0x28);
            ((u8 *)*(void **)((u8 *)arg0 + 0x30))[3] =
                ((u8 *)*(void **)((u8 *)other + 0x30))[3];
        }

        dst = *(void **)((u8 *)arg0 + 0x30);
        alpha = 0xFF;
        cnt = *(s8 *)((u8 *)dst + 3);
        if (cnt > 0) {
            *(s8 *)((u8 *)dst + 3) = (s8)(cnt - 1);
            dst = *(void **)((u8 *)arg0 + 0x30);
            alpha = (s32)Math_Lerp(lbl_80369084, lbl_803690C4, lbl_803690C8,
                                     (f32)*(s8 *)((u8 *)dst + 3));
            if (alpha == 0) {
                Process_ClearFunc(arg0);
            }
        }

        color = *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x38);
        Model_SetColor(gfx, ((u8 *)&color)[0], ((u8 *)&color)[1], ((u8 *)&color)[2]);
        Model_SetAlpha(gfx, (u8)((((u8 *)&color)[3] * alpha) / 255));
        fn_8005E644(gfx);

        inner = *(void **)((u8 *)arg0 + 0x30);
        flags = *(u32 *)((u8 *)inner + 8);
        if (flags & 0x08000000) {
            cb2 = *(void (**)(void *))((u8 *)inner + 0x3C);
            if (cb2 != 0) {
                cb2(arg0);
            }
            inner = *(void **)((u8 *)arg0 + 0x30);
            *(u32 *)((u8 *)inner + 8) = *(u32 *)((u8 *)inner + 8) & ~0x08000000;
        } else if ((flags & 0x800) == 0) {
            fn_80060060(gfx);
        }

        cb = *(u8 (**)(void *))((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x40);
        if (cb == 0 || cb(arg0) != 1) {
            MapObj_UpdateMatrix(arg0);
        }

        fn_800609DC(gfx);

        inner = *(void **)((u8 *)arg0 + 0x30);
        if ((*(u32 *)((u8 *)inner + 8) & 8) == 0 &&
            (*(u8 *)((u8 *)*(void **)((u8 *)inner + 0x2C) + 4) & 3) == 0) {
            fn_8006CAD4(gfx);
        } else {
            Prim2D_Begin();
            inner = *(void **)((u8 *)arg0 + 0x30);
            Prim2D_SetTransform(lbl_80369084, lbl_80369084,
                        (f32)(s32)*(f32 *)((u8 *)inner + 0x1C), lbl_8036908C);
            Prim2D_SetTex(0, 0x410);
            Prim2D_SetColorByte(0xFF);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(0xB);
            fn_80007340(&fn_80054314, gfx);
            Prim2D_EndPrim();
        }

        fn_800548E8(arg0);

        {
            void *p = *(void **)((u8 *)arg0 + 0x30);
            if ((*(u32 *)((u8 *)p + 8) & 4) == 0 && (*(u32 *)gfx & 0x10)) {
                b = ((u8 *)p)[4];
                if ((s8)b >= 0) {
                    ((u8 *)p)[4] = b - 1;
                } else {
                    Process_ClearFunc(arg0);
                }
            }
        }
    }
}
#pragma use_lmw_stmw reset

void fn_80054314(void *arg0) {
    u8 fn_8000A268(void);
    void fn_80069F04(void *);
    void Model_SetAlpha(void *, s32);
    u8 temp_r31;
    u8 tmp;

    temp_r31 = *(u8 *)((u8 *)arg0 + 0xB);
    tmp = (u8)((temp_r31 * fn_8000A268()) / 255);
    if (tmp != 0) {
        Model_SetAlpha(arg0, tmp);
        fn_80069F04(arg0);
        Model_SetAlpha(arg0, temp_r31);
    }
}

#pragma use_lmw_stmw on
/* Build map-object model node from path templates; optionally spawn a linked child object. */
void MapObj_InitGraphics(void *arg0) {
#pragma use_lmw_stmw on
#pragma opt_common_subs off
 void sprintf(void *, void *, ...);
 void fn_8005C82C(void *, s32);
 void *GActor_Create(void);
 void GActor_LoadGs(void *, void *);
 void GActor_LoadG(void *, void *);
 void fn_8005F5B4(void *, void *);
 void GActor_LoadTpl(void *, void *);
 u8 FileCache_Exists(void *);
 void GActor_Finalize(void *);
 void fn_8005EBCC(void *, u8);
 void *Process_Create(void *, void *);
 void *Heap_Alloc(s32);
 void *Res_GetByName(void *);
 void *fn_80060664(void *);
 u32 Game_GetFrameCount(void);
 void fn_8005FEE8(void *, f32);
 extern u8 GActor_str[];
 extern u8 lbl_80285990[];
 extern u32 lbl_80369080;
 extern const f32 lbl_80369084, lbl_80369088, lbl_8036908C;
 typedef struct { f32 x,y,z; } Vec;
 char buf[0x40];
 Vec b,a;
 u32 color;
 u32 name;
 void *child,*node,*init,*base,*ref,*parent;
 u32 range,rnd;
 s32 lo;
 u32 quotient;
 u8 mode;
 f32 zero;
 s32 flag;
 sprintf(buf,GActor_str+0x120,GActor_str+0x129,M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),void * *,0x2C),void * *,0));
 flag=0;
 if (M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),u32 *,8)&0x100) flag=8;
 fn_8005C82C(buf,flag);
 node=M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),void * *,0x5C)=GActor_Create();
 M2C_FIELD(node,u8 *,0x87)=M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),u8 *,5);
 if (!(M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),u32 *,8)&1)) M2C_FIELD(node,u32 *,0)|=0x400;
 if (!(M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),u32 *,8)&2)) M2C_FIELD(node,u32 *,0)|=0x40000;
 if (M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),u32 *,8)&4) M2C_FIELD(node,u32 *,0)|=0x180;
 if (M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),u32 *,8)&0x80) M2C_FIELD(node,u32 *,0)|=0x10000000;
 sprintf(buf,GActor_str+330,GActor_str+0x129,M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),void * *,0x2C),void * *,0)); GActor_LoadGs(node,buf);
sprintf(buf,GActor_str+338,GActor_str+0x129,M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),void * *,0x2C),void * *,0)); GActor_LoadG(node,buf);
sprintf(buf,GActor_str+345,GActor_str+0x129,M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),void * *,0x2C),void * *,0)); fn_8005F5B4(node,buf);
sprintf(buf,GActor_str+353,GActor_str+0x129,M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),void * *,0x2C),void * *,0)); if(FileCache_Exists(buf)) GActor_LoadTpl(node,buf);
 GActor_Finalize(node);
 base=M2C_FIELD(arg0,void * *,0x30);
 mode=M2C_FIELD(M2C_FIELD(base,void * *,0x2C),u8 *,7);
 if(mode) {M2C_FIELD(base,u8 *,4)=mode; fn_8005EBCC(node,mode);}
 name=M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),void * *,0x2C),u32 *,8);
 if(name) {
 parent=arg0;
 if(!arg0) parent=(void *)4;
 child=Process_Create(lbl_80285990,parent);
 M2C_FIELD(child,void * *,0x30)=Heap_Alloc(0x60);
 init=M2C_FIELD(child,void * *,0x30);
 zero=lbl_80369084;
 M2C_FIELD(init,f32 *,0xC)=zero; M2C_FIELD(init,f32 *,0x10)=zero; M2C_FIELD(init,f32 *,0x14)=zero;
 M2C_FIELD(init,u16 *,0)=0; M2C_FIELD(init,s8 *,3)=-1; M2C_FIELD(init,s8 *,4)=-1;
 M2C_FIELD(init,u32 *,48)=0; M2C_FIELD(init,u32 *,52)=0; M2C_FIELD(init,u32 *,60)=0; M2C_FIELD(init,u32 *,64)=0; M2C_FIELD(init,u32 *,68)=0; M2C_FIELD(init,u32 *,8)=0; M2C_FIELD(init,u32 *,92)=0; M2C_FIELD(init,u32 *,72)=0;
 color=lbl_80369080;
 M2C_FIELD(init,u8 *,0x38)=((u8 *)&color)[0]; M2C_FIELD(init,u8 *,0x39)=((u8 *)&color)[1]; M2C_FIELD(init,u8 *,0x3A)=((u8 *)&color)[2]; M2C_FIELD(init,u8 *,0x3B)=((u8 *)&color)[3];
 M2C_FIELD(init,void * *,0x2C)=Res_GetByName((void *)name);
 zero=lbl_80369084;
 M2C_FIELD(init,f32 *,0x20)=zero; M2C_FIELD(init,f32 *,0x24)=zero; M2C_FIELD(init,f32 *,0x28)=zero;
 M2C_FIELD(init,f32 *,0x1C)=lbl_80369088; M2C_FIELD(init,f32 *,0x18)=lbl_8036908C; M2C_FIELD(init,u8 *,5)=3;
 M2C_FIELD(init,u32 *,76)=0; M2C_FIELD(init,u32 *,80)=0; M2C_FIELD(init,u32 *,84)=0; M2C_FIELD(init,u32 *,88)=0;
 M2C_FIELD(M2C_FIELD(child,void * *,0x30),u32 *,8)|=0x08000000;
 base=M2C_FIELD(child,void * *,0x30);
 if((M2C_FIELD(M2C_FIELD(base,void * *,0x2C),u8 *,4)&0xCU)==4U) M2C_FIELD(base,u32 *,8)|=0x20000000;
 if(arg0) {
 M2C_FIELD(M2C_FIELD(child,void * *,0x30),u32 *,8)|=0x10000000;
 M2C_FIELD(M2C_FIELD(child,void * *,0x30),u32 *,48)=M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),u32 *,48);
M2C_FIELD(M2C_FIELD(child,void * *,0x30),u32 *,52)=M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),u32 *,52);
 base=M2C_FIELD(arg0,void * *,0x30);
 a.x=M2C_FIELD(base,f32 *,0xC); a.y=M2C_FIELD(base,f32 *,0x10); a.z=M2C_FIELD(base,f32 *,0x14); b=a;
 M2C_FIELD(M2C_FIELD(child,void * *,0x30),f32 *,0xC)=b.x; M2C_FIELD(M2C_FIELD(child,void * *,0x30),f32 *,0x10)=b.y; M2C_FIELD(M2C_FIELD(child,void * *,0x30),f32 *,0x14)=b.z;
 M2C_FIELD(M2C_FIELD(child,void * *,0x30),f32 *,24)=M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),f32 *,24);
M2C_FIELD(M2C_FIELD(child,void * *,0x30),f32 *,32)=M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),f32 *,32);
M2C_FIELD(M2C_FIELD(child,void * *,0x30),f32 *,36)=M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),f32 *,36);
M2C_FIELD(M2C_FIELD(child,void * *,0x30),f32 *,40)=M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),f32 *,40);
M2C_FIELD(M2C_FIELD(child,void * *,0x30),u8 *,3)=M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),u8 *,3);
 }}
 if(M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),u32 *,8)&0x1000) {
 ref=fn_80060664(node); range=M2C_FIELD(ref,u32 *,0x18)-M2C_FIELD(ref,s32 *,0x14);
 rnd=Game_GetFrameCount();
 quotient=rnd/range;
 rnd-=quotient*range;
 lo=M2C_FIELD(ref,s32 *,0x14);
 fn_8005FEE8(node,(f32)(s32)(lo+rnd));
 }
}
#pragma use_lmw_stmw reset

void fn_80054808(void *arg0) {
    M2C_UNK Process_ClearFunc(void *);
    u8 GActor_CheckResources(s32);
    if (GActor_CheckResources(*M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 **, 0x2C)) != 0) {
        Process_ClearFunc(arg0);
    }
}

void fn_80054850(void *arg0) {
    s64 OSGetTime(void);
    void Process_Goto(void *, s32);
    void fn_800555EC(s32, s32);
    u8 GActor_CheckResources(s32);
    s32 temp_r31;
    u32 flags;
    void *temp_r3;
    s32 var_r4;

    *(s64 *)((u8 *)arg0 + 0x38) = OSGetTime();
    temp_r3 = *(void **)((u8 *)arg0 + 0x30);
    flags = *(u32 *)((u8 *)temp_r3 + 8);
    temp_r31 = **(s32 **)((u8 *)temp_r3 + 0x2C);
    if ((flags >> 28) & 1) {
        Process_Goto(arg0, 0);
        return;
    }
    var_r4 = 0;
    if (flags & 0x100) {
        var_r4 = 8;
    }
    fn_800555EC(temp_r31, var_r4);
    if (GActor_CheckResources(temp_r31) != 0) {
        Process_Goto(arg0, 0);
    }
}

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern void* jumptable_80285A50;

extern u32 lbl_80369058;
extern u32 lbl_8036905C;
extern u32 lbl_80369060;
extern u32 lbl_80369064;
extern u32 lbl_80369068;
extern u32 lbl_8036906C;
extern u32 lbl_80369070;
extern u32 lbl_80369074;
extern u32 lbl_80369078;
extern u32 lbl_8036907C;
extern u32 jumptable_80285ACC[];

extern u16 *gMap;
#include "common.h"
#include "global.h"

extern u16 lbl_8026A660;
extern void* lbl_803672A8;
extern u8 gBattleMap[0x24F60];
extern u32* lbl_803672CC;
#include "global.h"
#include "common.h"

extern u32 jumptable_8028561C[];
extern u32 jumptable_802855E4[];
#include "global.h"
extern s32* gUnitShadowMat;
extern f32 lbl_80368FCC;
extern f32 gUnitShadowZ;
extern u16* gUnits;
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    char pad[0x30 - 0x18];
    s32 unk30;
    s32 unk34;
    s32 unk38;
} Struct_800330F8;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    char pad[0x20 - 0x18];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
} Struct_800330F8_A;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    char pad[0xBC - 0x18];
    s32 unkBC;
} Struct_800330F8_B;

void fn_8004781C(void *arg0) {
    // body of function will go here
}
#include "common.h"
extern f32 lbl_80368FD8;
extern u16 lbl_8026AB18;
extern f32 lbl_80368FC4;
extern u16 lbl_802EFE20;
