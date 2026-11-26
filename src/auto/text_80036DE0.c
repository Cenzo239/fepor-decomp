/* Functions from 0x800330F8 to 0x80055C70, found by decomp-toolkit. */
#include "common.h"

static inline s8 Unit_StatTotalForClamp(u8 *self, s32 personOffset, s32 classOffset, s32 bonusOffset) {
    u8 *person = *(u8 **)(self + 0x188);
    u8 *cls = *(u8 **)(self + 0x18C);
    return self[bonusOffset] + (person[personOffset] + cls[classOffset]);
}
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
#pragma push
#pragma scheduling off
#pragma cplusplus off
#pragma global_optimizer on
#pragma optimization_level 4
#pragma scheduling on
#pragma peephole on
#pragma opt_strength_reduction on
#pragma opt_common_subs on
#pragma opt_loop_invariants on
#pragma opt_propagation on
#pragma opt_lifetimes on
#pragma dont_inline off
#pragma use_lmw_stmw off
typedef struct { u32 x0; u32 x4; struct { void *v; u32 w; } e[1]; } Tbl_80036DE0;
typedef struct { u8 pad[0x50]; Tbl_80036DE0 *x50; } Sub_80036DE0;
typedef struct { u8 pad[0x188]; Sub_80036DE0 *x188; } Obj_80036DE0;
static inline u8 Count_80036DE0(Sub_80036DE0 *s) {
    if (s->x50 == 0) return 0;
    return s->x50->x4;
}
static inline void *Get_80036DE0(Sub_80036DE0 *s, s32 i) { return s->x50->e[i].v; }
static inline s32 Find_80036DE0(Obj_80036DE0 *a, void *v, s32 start) {
    s32 i;
    for (i = start; i < Count_80036DE0(a->x188); i++) {
        if (Get_80036DE0(a->x188, i) == v) return (s8)i;
    }
    return -1;
}
s32 fn_80036DE0(void *a_, void *b_) {
    Obj_80036DE0 *a = (Obj_80036DE0 *)a_;
    Obj_80036DE0 *b = (Obj_80036DE0 *)b_;
    return Find_80036DE0(a, (void *)b->x188, 0);
}
#pragma pop
s32 Unit_FindSupportPartnerIndex(void *arg0, u32 arg1)
{
    u8 *table;
    s32 offset;
    u8 *obj;
    s32 index;
    u8 lim;
    u32 entry;

    obj = *(u8 **)((u8 *)arg0 + 0x188);
    index = 0;
    offset = 0;

    goto check;

loop:
    table = *(u8 **)(obj + 0x50);
    entry = *(u32 *)(table + offset + 8);

    if (entry == arg1) {
        return (s8)index;
    }

    offset += 8;
    index++;

check:
    table = *(u8 **)(obj + 0x50);

    if ((u32)table == 0) {
        lim = 0;
    } else {
        lim = (u8)*(u32 *)(table + 4);
        lim = (u8)(lim & 0xFF);
    }

    if (index < (s32)lim) {
        goto loop;
    }

    return -1;
}
#pragma global_optimizer on
s32 fn_80036EAC(void *arg0, s32 arg1) {
    s32 result;
    u8 value;
    u8 *table;
    u8 t;

    result = 3;
    table = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x188) + 0x50);
    table = table + arg1 * 8 + 8;
    if (table == NULL) {
        value = 0;
    } else {
        arg0 = (u8 *)arg0 + arg1;
        t = table[4];
        value = *((u8 *)arg0 + 0x214);
        if (value <= t) {
            value = 0;
        } else if (value <= table[5]) {
            value = 1;
        } else if (value <= table[6]) {
            value = 2;
        } else {
            value = 3;
        }
    }
    switch (value) {
    case 0:
        result = 1;
        break;
    case 1:
        result = 2;
        break;
    case 2:
        result = 3;
        break;
    }
    return result;
}

s32 Unit_GetSupportRank(void *arg0, s32 arg1)
{
    u8 *obj;
    u8 *entry;
    u32 value;

    obj = *(u8 **)((u8 *)arg0 + 0x188);
    entry = *(u8 **)(obj + 0x50) + (arg1 * 8) + 8;
    if (entry == 0) {
        return 0;
    }
    arg0 = (u8 *)arg0 + arg1;
    value = *((u8 *)arg0 + 0x214);
    if (value <= entry[4]) {
        return 0;
    }
    if (value <= entry[5]) {
        return 1;
    }
    if (value <= entry[6]) {
        return 2;
    }
    return 3;
}

#pragma peephole off
u8 fn_80036FC4(u8 *arg0, s32 arg1) {
    return arg0[arg1 + 0x214];
}
#pragma peephole on
void Unit_GetSupportPartner(void *arg0, s32 arg1) {
    void **temp_r3;
    void *temp_r3_2;

    temp_r3 = (void **)M2C_FIELD(arg0, void **, 0x188);
    temp_r3_2 = M2C_FIELD(temp_r3, void **, 0x50);
    temp_r3_2 = (void*)((s32)temp_r3_2 + (arg1 * 8));
    Unit_FindByPerson((s32)M2C_FIELD(temp_r3_2, void **, 8));
}

s32 fn_80037004(void *arg0, s32 idx) {
    void *a;
    s32 off;
    u8 *b;
    a = *(void **)((u8 *)arg0 + 0x188);
    off = idx * 8;
    b = *(u8 **)((u8 *)a + 0x50);
    b += off;
    return *(s32 *)(b + 8);
}

u8 Unit_CountSupportPartners(void *arg0) {
    void *temp_r3;

    temp_r3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), void **, 0x50);
    if (temp_r3 == NULL) {
        return 0U;
    }
    return (u8) M2C_FIELD(temp_r3, s32 *, 4);
}

void fn_80037040(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, u8 *, 0x1A9) = (u8) (M2C_FIELD(arg0, u8 *, 0x1A9) + arg1);
    M2C_FIELD(arg0, u8 *, 0x1AA) = (u8) (M2C_FIELD(arg0, u8 *, 0x1AA) + arg2);
    if ((s8) M2C_FIELD(arg0, u8 *, 0x1A9) > 0x63) {
        M2C_FIELD(arg0, u8 *, 0x1A9) = 0x63U;
    }
    if ((s8) M2C_FIELD(arg0, u8 *, 0x1AA) > 0x14) {
        M2C_FIELD(arg0, u8 *, 0x1AA) = 0x14U;
    }
}

void fn_8003708C(void *arg0, void *arg1) {
    void fn_8003712C(void);
    M2C_FIELD(arg0,u8*,0x1AB)=(u8)(M2C_FIELD(arg0,u8*,0x1AB)+M2C_FIELD(arg1,u8*,0));
    M2C_FIELD(arg0,u8*,0x1AC)=(u8)(M2C_FIELD(arg0,u8*,0x1AC)+M2C_FIELD(arg1,u8*,1));
    M2C_FIELD(arg0,u8*,0x1AD)=(u8)(M2C_FIELD(arg0,u8*,0x1AD)+M2C_FIELD(arg1,u8*,2));
    M2C_FIELD(arg0,u8*,0x1AE)=(u8)(M2C_FIELD(arg0,u8*,0x1AE)+M2C_FIELD(arg1,u8*,3));
    M2C_FIELD(arg0,u8*,0x1AF)=(u8)(M2C_FIELD(arg0,u8*,0x1AF)+M2C_FIELD(arg1,u8*,4));
    M2C_FIELD(arg0,u8*,0x1B0)=(u8)(M2C_FIELD(arg0,u8*,0x1B0)+M2C_FIELD(arg1,u8*,5));
    M2C_FIELD(arg0,u8*,0x1B1)=(u8)(M2C_FIELD(arg0,u8*,0x1B1)+M2C_FIELD(arg1,u8*,6));
    M2C_FIELD(arg0,u8*,0x1B2)=(u8)(M2C_FIELD(arg0,u8*,0x1B2)+M2C_FIELD(arg1,u8*,7));
    fn_8003712C();
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma global_optimizer off
void fn_8003712C(void *arg0) {
    void *cls;
    void *unit;
    s8 excess;
    s8 v;
    s8 lim;
    s8 sum;
    s8 bonus;
    u8 lim_u;
    s32 index;
    s32 ptr;
    s8 slot_bonus;
    s8 cur;

    {
        u8 *c = (u8 *)*(void **)((u8 *)arg0 + 0x18C);
        u8 *u = (u8 *)*(void **)((u8 *)arg0 + 0x188);
        u8 s = c[0x44];
        u8 t = u[0x1D];
        u8 b = *(u8 *)((u8 *)arg0 + 0x1AB);
        u32 p = t + s;
        u8 l = c[0x4C];
        s8 sm = (s8)(b + p);
        excess = (s8)(sm - l);
    }
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1AB) = (u8)(*(u8 *)((u8 *)arg0 + 0x1AB) - excess);

    {
        u8 *c = (u8 *)*(void **)((u8 *)arg0 + 0x18C);
        u8 *u = (u8 *)*(void **)((u8 *)arg0 + 0x188);
        u8 s = c[0x45];
        u8 t = u[0x1E];
        u8 b = *(u8 *)((u8 *)arg0 + 0x1AC);
        u32 p = t + s;
        u8 l = c[0x4D];
        s8 sm = (s8)(b + p);
        excess = (s8)(sm - l);
    }
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1AC) = (u8)(*(u8 *)((u8 *)arg0 + 0x1AC) - excess);

    {
        u8 *c = (u8 *)*(void **)((u8 *)arg0 + 0x18C);
        u8 *u = (u8 *)*(void **)((u8 *)arg0 + 0x188);
        u8 s = c[0x46];
        u8 t = u[0x1F];
        u8 b = *(u8 *)((u8 *)arg0 + 0x1AD);
        u32 p = t + s;
        u8 l = c[0x4E];
        s8 sm = (s8)(b + p);
        excess = (s8)(sm - l);
    }
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1AD) = (u8)(*(u8 *)((u8 *)arg0 + 0x1AD) - excess);

    {
        u8 *c = (u8 *)*(void **)((u8 *)arg0 + 0x18C);
        u8 *u = (u8 *)*(void **)((u8 *)arg0 + 0x188);
        u8 s = c[0x47];
        u8 t = u[0x20];
        u8 b = *(u8 *)((u8 *)arg0 + 0x1AE);
        u32 p = t + s;
        u8 l = c[0x4F];
        s8 sm = (s8)(b + p);
        excess = (s8)(sm - l);
    }
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1AE) = (u8)(*(u8 *)((u8 *)arg0 + 0x1AE) - excess);

    {
        u8 *c = (u8 *)*(void **)((u8 *)arg0 + 0x18C);
        u8 *u = (u8 *)*(void **)((u8 *)arg0 + 0x188);
        u8 s = c[0x48];
        u8 t = u[0x21];
        u8 b = *(u8 *)((u8 *)arg0 + 0x1AF);
        u32 p = t + s;
        u8 l = c[0x50];
        s8 sm = (s8)(b + p);
        excess = (s8)(sm - l);
    }
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1AF) = (u8)(*(u8 *)((u8 *)arg0 + 0x1AF) - excess);

    {
        u8 *u = (u8 *)*(void **)((u8 *)arg0 + 0x188);
        u8 *c = (u8 *)*(void **)((u8 *)arg0 + 0x18C);
        u8 t = u[0x22];
        u8 s = c[0x49];
        u8 b = *(u8 *)((u8 *)arg0 + 0x1B0);
        u32 p = t + s;
        s8 sm = (s8)(b + p);
        excess = (s8)(sm - 0x28);
    }
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1B0) = (u8)(*(u8 *)((u8 *)arg0 + 0x1B0) - excess);

    {
        u8 *c = (u8 *)*(void **)((u8 *)arg0 + 0x18C);
        u8 *u = (u8 *)*(void **)((u8 *)arg0 + 0x188);
        u8 s = c[0x4A];
        u8 t = u[0x23];
        u8 b = *(u8 *)((u8 *)arg0 + 0x1B1);
        u32 p = t + s;
        u8 l = c[0x52];
        s8 sm = (s8)(b + p);
        excess = (s8)(sm - l);
    }
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1B1) = (u8)(*(u8 *)((u8 *)arg0 + 0x1B1) - excess);

    {
        u8 *c = (u8 *)*(void **)((u8 *)arg0 + 0x18C);
        u8 *u = (u8 *)*(void **)((u8 *)arg0 + 0x188);
        u8 s = c[0x4B];
        u8 t = u[0x24];
        u8 b = *(u8 *)((u8 *)arg0 + 0x1B2);
        u32 p = t + s;
        u8 l = c[0x53];
        s8 sm = (s8)(b + p);
        excess = (s8)(sm - l);
    }
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1B2) = (u8)(*(u8 *)((u8 *)arg0 + 0x1B2) - excess);

    {
        u8 *u = (u8 *)*(void **)((u8 *)arg0 + 0x188);
        u8 *c = (u8 *)*(void **)((u8 *)arg0 + 0x18C);
        u8 t = u[0x1B];
        u8 s = c[0x3C];
        u8 b = *(u8 *)((u8 *)arg0 + 0x1A9);
        u32 p = t + s;
        s8 sm = (s8)(b + p);
        excess = (s8)(sm - 0x63);
    }
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1A9) = (u8)(*(u8 *)((u8 *)arg0 + 0x1A9) - excess);

    {
        u8 *c = (u8 *)*(void **)((u8 *)arg0 + 0x18C);
        u8 b = *(u8 *)((u8 *)arg0 + 0x1AA);
        u8 s = c[0x3E];
        u32 p = b + s;
        s8 sm = (s8)p;
        excess = (s8)(sm - 0x14);
    }
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1AA) = (u8)(*(u8 *)((u8 *)arg0 + 0x1AA) - excess);

    cls = *(void **)((u8 *)arg0 + 0x18C);
    unit = *(void **)((u8 *)arg0 + 0x188);
    bonus = *(s8 *)((u8 *)arg0 + 0x1AB);
    lim_u = *(u8 *)((u8 *)cls + 0x4C);
    lim = (s8)lim_u;
    sum = (s8)(*(u8 *)((u8 *)unit + 0x1D) + (*(u8 *)((u8 *)cls + 0x44) + bonus));
    if (sum > lim) {
        sum = lim;
    }
    if (sum < 0) {
        sum = 0;
    }
    slot_bonus = 0;
    if ((((*(u8 *)((u8 *)arg0 + 0x1D1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1CC) != 0)) {
        index = 0;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1D9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1D4) != 0)) {
        index = 1;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1E1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1DC) != 0)) {
        index = 2;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1E9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1E4) != 0)) {
        index = 3;
    } else {
        index = -1;
    }
    if ((s8)index < 0) {
        ptr = 0;
    } else {
        ptr = (s8)index * 8;
        ptr = ptr + 0x1CC;
        ptr = ptr + (s32)arg0;
    }
    if ((u32)ptr != 0) {
        slot_bonus = *(s8 *)((u8 *)*(void **)ptr + 0x1F);
    }
    if ((((*(u8 *)((u8 *)arg0 + 0x1F1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1EC) != 0)) {
        index = 0;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1F9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1F4) != 0)) {
        index = 1;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x201) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1FC) != 0)) {
        index = 2;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x209) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x204) != 0)) {
        index = 3;
    } else {
        index = -1;
    }
    if ((s8)index < 0) {
        ptr = 0;
    } else {
        ptr = (s8)index * 8;
        ptr = ptr + 0x1EC;
        ptr = ptr + (s32)arg0;
    }
    if ((u32)ptr != 0) {
        slot_bonus = (s8)(slot_bonus + *(s8 *)((u8 *)*(void **)ptr + 0x1F));
    }
    cur = *(s8 *)((u8 *)arg0 + 0x1A8);
    if (cur > (s8)(sum + slot_bonus)) {
        v = (s8)(*(u8 *)((u8 *)cls + 0x44) + bonus + *(u8 *)((u8 *)unit + 0x1D));
        if (v > lim) {
            v = lim;
        }
        if (v < 0) {
            v = 0;
        }
        slot_bonus = 0;
        if ((((*(u8 *)((u8 *)arg0 + 0x1D1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1CC) != 0)) {
            index = 0;
        } else if ((((*(u8 *)((u8 *)arg0 + 0x1D9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1D4) != 0)) {
            index = 1;
        } else if ((((*(u8 *)((u8 *)arg0 + 0x1E1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1DC) != 0)) {
            index = 2;
        } else if ((((*(u8 *)((u8 *)arg0 + 0x1E9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1E4) != 0)) {
            index = 3;
        } else {
            index = -1;
        }
        if ((s8)index < 0) {
            ptr = 0;
        } else {
            ptr = (s8)index * 8;
            ptr = ptr + 0x1CC;
            ptr = ptr + (s32)arg0;
        }
        if ((u32)ptr != 0) {
            slot_bonus = *(s8 *)((u8 *)*(void **)ptr + 0x1F);
        }
        if ((((*(u8 *)((u8 *)arg0 + 0x1F1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1EC) != 0)) {
            index = 0;
        } else if ((((*(u8 *)((u8 *)arg0 + 0x1F9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1F4) != 0)) {
            index = 1;
        } else if ((((*(u8 *)((u8 *)arg0 + 0x201) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1FC) != 0)) {
            index = 2;
        } else if ((((*(u8 *)((u8 *)arg0 + 0x209) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x204) != 0)) {
            index = 3;
        } else {
            index = -1;
        }
        if ((s8)index < 0) {
            ptr = 0;
        } else {
            ptr = (s8)index * 8;
            ptr = ptr + 0x1EC;
            ptr = ptr + (s32)arg0;
        }
        if ((u32)ptr != 0) {
            slot_bonus = (s8)(slot_bonus + *(s8 *)((u8 *)*(void **)ptr + 0x1F));
        }
        *(u8 *)((u8 *)arg0 + 0x1A8) = (u8)(v + slot_bonus);
    }
}
#pragma pop
/* Return the first deployed unit with the same faction and disposId as unit, and state flags 0x100 set / 8 clear. */
void *Unit_FindDisposLeader(u8 *unit) {
    void Allegiance_FillMask(s32, void *);
    extern u8 gUnits[];
    u8 allegMask[8];
    u8 *faction;
    u8 *other;
    s32 i;
    u32 flags;

    faction = NULL;
    Allegiance_FillMask(5, allegMask);
    for (i = 1; i <= 0x9F; i++) {
        if ((u8)i != 0) {
            other = gUnits + ((u8)i - 1) * 0x280;
        } else {
            other = NULL;
        }
        if (*(u32 *)(other + 0x188) != 0) {
            faction = *(u8 **)(other + 0x190);
            if (allegMask[*(u8 *)(faction + 8)] != 0) {
                flags = *(u32 *)(other + 0x1A0);
                if ((flags & 0x100) != 0) {
                    if ((flags & 8) == 0) {
                        if (faction == *(u8 **)(unit + 0x190)) {
                            if (unit[0x199] == other[0x199]) {
                                return other;
                            }
                        }
                    }
                }
            }
        }
    }
    return NULL;
}

void *fn_800377D8(void *arg0) {
    extern u8 lbl_8026A3A8[176];
    void *fn_80014EDC(s32);
    u8 v;

    v = *(u8 *)((u8 *)arg0 + 0x199);
    if (v == 0) {
        return lbl_8026A3A8 + 0x1D;
    }
    return fn_80014EDC(v);
}

void fn_80037814(void) {

}

extern f32 lbl_80368EA8;
extern f32 lbl_80368EAC;
extern f32 lbl_80368EB0;
extern f32 lbl_80368EB4;
extern f64 lbl_80368EB8;
f32 Unit_CalcBaseGoldCost(void *arg0,u8 arg1) {
    u8 value;
    u8 Status_Test(s32,s32);
    f32 result;
    if (arg1 == 0) return lbl_80368EA8;
    if ((u8)Status_Test((s32)arg0+0x1BC,2)) value=M2C_FIELD(arg0,u8*,0x19A)+0x14;
    else value=M2C_FIELD(arg0,u8*,0x19A);
    result = (f32)arg1 / (lbl_80368EAC - lbl_80368EB0 * (f32)value);
    return result + lbl_80368EB4;
}

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
} UnkRet800378CC;

M2C_UNK fn_80165E90(s32 *, s32);
UnkRet800378CC fn_800378CC(s32 arg0) {
    UnkRet800378CC ret;

    fn_80165E90((s32 *)&ret.unk0, arg0 + 0x1BC);
    return ret;
}

void fn_80037904(void *arg0, s32 arg1) {
    s32 fn_801660A8(void *);
    void fn_801660C4(s32, u16, u16, u8);
    extern u8 gBattleState[];
    s32 var_r4;
    void *temp_r6;

    var_r4 = arg1;
    if (var_r4 < 0) {
        var_r4 = fn_801660A8(gBattleState + 0x3C0);
    }
    temp_r6 = *(void **)((u8 *)arg0 + 0x188);
    fn_801660C4(var_r4, *(u16 *)((u8 *)temp_r6 + 0x58), *(u16 *)((u8 *)arg0 + 0x228), *(u8 *)((u8 *)temp_r6 + 0x55));
}

s32 Unit_MatchesId(void *unit, s32 idName) {
    /* True if unit matches a PID_/JID_, or if an IID_ is in the convoy or held by a same-side unit. */
    void Allegiance_FillMask(s32, void *);
    u8 Id_GetKind(s32);
    s32 Item_GetByIid(s32);
    s32 Job_GetByJid(s32);
    s32 Person_GetByPid(s32);
    s8 Unit_FindItemSlot(void *, s32);
    s32 Convoy_FindByIid(void *, s32);
    extern u8 gUnits[];
    extern u8 gConvoy[];
    u8 allegianceMask[8];
    s32 personOrJob;
    void *other;
    s32 i;

    switch ((s32)(u8)Id_GetKind(idName)) {
    case 1: /* PID_ */
        personOrJob = *(s32 *)((u8 *)unit + 0x188);
        return personOrJob == Person_GetByPid(idName);
    case 2: /* JID_ */
        personOrJob = *(s32 *)((u8 *)unit + 0x18C);
        return personOrJob == Job_GetByJid(idName);
    case 3: /* IID_ */
        if (Convoy_FindByIid(gConvoy, idName) >= 0) {
            return 1;
        }
        Allegiance_FillMask(4, allegianceMask);
        i = 1;
        do {
            if ((u8)i != 0) {
                other = gUnits + ((u8)i - 1) * 0x280;
            } else {
                other = NULL;
            }
            if (*(u32 *)((u8 *)other + 0x188) != 0 &&
                allegianceMask[*(u8 *)(*(u8 **)((u8 *)other + 0x190) + 8)] != 0 &&
                (s8)Unit_FindItemSlot(other, Item_GetByIid(idName)) >= 0) {
                return 1;
            }
            i += 1;
        } while (i <= 0x9F);
        return 0;
    default:
        return 0;
    }
}

void Unit_SetStatBonusesToCap(void *unit) {
    /* Set HP/Str/Mag/Skl/Spd/Lck/Def/Res/Move bonuses so totals equal class caps. */
    void *cls;
    void *cls2;
    void *cls3;
    void *cls4;
    void *cls5;
    void *cls6;
    void *cls7;

    cls = M2C_FIELD(unit, void **, 0x18C);
    M2C_FIELD(unit, s8 *, 0x1AB) = (s8) ((M2C_FIELD(cls, u8 *, 0x4C) - M2C_FIELD(cls, u8 *, 0x44)) - M2C_FIELD(M2C_FIELD(unit, void **, 0x188), u8 *, 0x1D));
    cls2 = M2C_FIELD(unit, void **, 0x18C);
    M2C_FIELD(unit, s8 *, 0x1AC) = (s8) ((M2C_FIELD(cls2, u8 *, 0x4D) - M2C_FIELD(cls2, u8 *, 0x45)) - M2C_FIELD(M2C_FIELD(unit, void **, 0x188), u8 *, 0x1E));
    cls3 = M2C_FIELD(unit, void **, 0x18C);
    M2C_FIELD(unit, s8 *, 0x1AD) = (s8) ((M2C_FIELD(cls3, u8 *, 0x4E) - M2C_FIELD(cls3, u8 *, 0x46)) - M2C_FIELD(M2C_FIELD(unit, void **, 0x188), u8 *, 0x1F));
    cls4 = M2C_FIELD(unit, void **, 0x18C);
    M2C_FIELD(unit, s8 *, 0x1AE) = (s8) ((M2C_FIELD(cls4, u8 *, 0x4F) - M2C_FIELD(cls4, u8 *, 0x47)) - M2C_FIELD(M2C_FIELD(unit, void **, 0x188), u8 *, 0x20));
    cls5 = M2C_FIELD(unit, void **, 0x18C);
    M2C_FIELD(unit, s8 *, 0x1AF) = (s8) ((M2C_FIELD(cls5, u8 *, 0x50) - M2C_FIELD(cls5, u8 *, 0x48)) - M2C_FIELD(M2C_FIELD(unit, void **, 0x188), u8 *, 0x21));
    M2C_FIELD(unit, s8 *, 0x1B0) = (s8) (0x28 - M2C_FIELD(M2C_FIELD(unit, void **, 0x188), u8 *, 0x22));
    cls6 = M2C_FIELD(unit, void **, 0x18C);
    M2C_FIELD(unit, s8 *, 0x1B1) = (s8) ((M2C_FIELD(cls6, u8 *, 0x52) - M2C_FIELD(cls6, u8 *, 0x4A)) - M2C_FIELD(M2C_FIELD(unit, void **, 0x188), u8 *, 0x23));
    cls7 = M2C_FIELD(unit, void **, 0x18C);
    M2C_FIELD(unit, s8 *, 0x1B2) = (s8) ((M2C_FIELD(cls7, u8 *, 0x53) - M2C_FIELD(cls7, u8 *, 0x4B)) - M2C_FIELD(M2C_FIELD(unit, void **, 0x188), u8 *, 0x24));
    M2C_FIELD(unit, s8 *, 0x1AA) = (s8) (0x14 - M2C_FIELD(M2C_FIELD(unit, void **, 0x18C), u8 *, 0x3E));
}

s32 Unit_GetHeldItemSlot(s32 arg0, s32 arg1) {
    return (arg1 * 8) + arg0 + 0x1CC;
}

s32 Unit_GetItemSlot(s32 arg0, s32 arg1) {
    s32 base = arg0;
    if (arg1 >= 0 && arg1 < 4) return base + (arg1 << 3) + 0x1CC;
    if (arg1 >= 4 && arg1 < 8) return base + ((arg1 - 4) << 3) + 0x1EC;
    return 0;
}

void *fn_80037C20(void *arg0) {
    s8 index;
    if ((((u8)M2C_FIELD(arg0, u8 *, 0x1F1) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1EC) != 0) index = 0;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x1F9) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1F4) != 0) index = 1;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x201) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1FC) != 0) index = 2;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x209) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x204) != 0) index = 3;
    else index = -1;
    if (index < 0) return NULL;
    return (u8 *)arg0 + (index * 8) + 0x1EC;
}

s32 fn_80037CCC(void *arg0) {
    if ((((u8) M2C_FIELD(arg0, u8 *, 0x1F1) >> 7U) & 1) && ((u32) M2C_FIELD(arg0, u32 *, 0x1EC) != 0U)) {
        return 0;
    }
    if ((((u8) M2C_FIELD(arg0, u8 *, 0x1F9) >> 7U) & 1) && ((u32) M2C_FIELD(arg0, u32 *, 0x1F4) != 0U)) {
        return 1;
    }
    if ((((u8) M2C_FIELD(arg0, u8 *, 0x201) >> 7U) & 1) && ((u32) M2C_FIELD(arg0, u32 *, 0x1FC) != 0U)) {
        return 2;
    }
    if ((((u8) M2C_FIELD(arg0, u8 *, 0x209) >> 7U) & 1) && ((u32) M2C_FIELD(arg0, u32 *, 0x204) != 0U)) {
        return 3;
    }
    return -1;
}

void *Unit_GetActiveItemPtr(void *arg0) {
    s8 index;
    if ((((u8)M2C_FIELD(arg0, u8 *, 0x1D1) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1CC) != 0) index = 0;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x1D9) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1D4) != 0) index = 1;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x1E1) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1DC) != 0) index = 2;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x1E9) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1E4) != 0) index = 3;
    else index = -1;
    if (index < 0) return NULL;
    return (u8 *)arg0 + (index * 8) + 0x1CC;
}

s32 Unit_GetActiveItemSlot(void *arg0) {
    if ((((u8) M2C_FIELD(arg0, u8 *, 0x1D1) >> 7U) & 1) && ((u32) M2C_FIELD(arg0, u32 *, 0x1CC) != 0U)) {
        return 0;
    }
    if ((((u8) M2C_FIELD(arg0, u8 *, 0x1D9) >> 7U) & 1) && ((u32) M2C_FIELD(arg0, u32 *, 0x1D4) != 0U)) {
        return 1;
    }
    if ((((u8) M2C_FIELD(arg0, u8 *, 0x1E1) >> 7U) & 1) && ((u32) M2C_FIELD(arg0, u32 *, 0x1DC) != 0U)) {
        return 2;
    }
    if ((((u8) M2C_FIELD(arg0, u8 *, 0x1E9) >> 7U) & 1) && ((u32) M2C_FIELD(arg0, u32 *, 0x1E4) != 0U)) {
        return 3;
    }
    return -1;
}

#pragma use_lmw_stmw on
void Unit_Copy(void *dstUnit, void *srcUnit) {
    /* Copy battle-unit fields and inventory from src to dst; leave link slots 0x180/0x184 cleared. */
    void Item_Copy(void *, void *);
    struct Pair { s32 x; s32 y; };
    void *dst;
    void *src;
    void *srcWalk;
    void *dstWalk;
    s32 i;

    dst = dstUnit;
    src = srcUnit;
    if (src != dst) {
        *(s32 *)((u8 *)dst + 0x180) = 0;
        srcWalk = src;
        dstWalk = dst;
        i = 0;
        *(s32 *)((u8 *)dst + 0x184) = 0;
        *(s32 *)((u8 *)dst + 0x188) = *(s32 *)((u8 *)src + 0x188);
        *(s32 *)((u8 *)dst + 0x18C) = *(s32 *)((u8 *)src + 0x18C);
        *(s32 *)((u8 *)dst + 0x190) = *(s32 *)((u8 *)src + 0x190);
        *(s32 *)((u8 *)dst + 0x194) = *(s32 *)((u8 *)src + 0x194);
        *(u8 *)((u8 *)dst + 0x198) = *(u8 *)((u8 *)src + 0x198);
        *(u8 *)((u8 *)dst + 0x199) = *(u8 *)((u8 *)src + 0x199);
        *(u8 *)((u8 *)dst + 0x19A) = *(u8 *)((u8 *)src + 0x19A);
        *(u8 *)((u8 *)dst + 0x19B) = *(u8 *)((u8 *)src + 0x19B);
        *(u8 *)((u8 *)dst + 0x19C) = *(u8 *)((u8 *)src + 0x19C);
        *(u8 *)((u8 *)dst + 0x19D) = *(u8 *)((u8 *)src + 0x19D);
        *(u8 *)((u8 *)dst + 0x19E) = *(u8 *)((u8 *)src + 0x19E);
        *(u8 *)((u8 *)dst + 0x19F) = *(u8 *)((u8 *)src + 0x19F);
        *(s32 *)((u8 *)dst + 0x1A0) = *(s32 *)((u8 *)src + 0x1A0);
        *(u16 *)((u8 *)dst + 0x1A4) = *(u16 *)((u8 *)src + 0x1A4);
        *(u16 *)((u8 *)dst + 0x1A6) = *(u16 *)((u8 *)src + 0x1A6);
        *(u8 *)((u8 *)dst + 0x1A8) = *(u8 *)((u8 *)src + 0x1A8);
        *(u8 *)((u8 *)dst + 0x1A9) = *(u8 *)((u8 *)src + 0x1A9);
        *(u8 *)((u8 *)dst + 0x1AA) = *(u8 *)((u8 *)src + 0x1AA);
        *(u8 *)((u8 *)dst + 0x1AB) = *(u8 *)((u8 *)src + 0x1AB);
        *(u8 *)((u8 *)dst + 0x1AC) = *(u8 *)((u8 *)src + 0x1AC);
        *(u8 *)((u8 *)dst + 0x1AD) = *(u8 *)((u8 *)src + 0x1AD);
        *(u8 *)((u8 *)dst + 0x1AE) = *(u8 *)((u8 *)src + 0x1AE);
        *(u8 *)((u8 *)dst + 0x1AF) = *(u8 *)((u8 *)src + 0x1AF);
        *(u8 *)((u8 *)dst + 0x1B0) = *(u8 *)((u8 *)src + 0x1B0);
        *(u8 *)((u8 *)dst + 0x1B1) = *(u8 *)((u8 *)src + 0x1B1);
        *(u8 *)((u8 *)dst + 0x1B2) = *(u8 *)((u8 *)src + 0x1B2);
        *(u8 *)((u8 *)dst + 0x1B4) = *(u8 *)((u8 *)src + 0x1B4);
        *(u8 *)((u8 *)dst + 0x1B5) = *(u8 *)((u8 *)src + 0x1B5);
        *(u8 *)((u8 *)dst + 0x1B6) = *(u8 *)((u8 *)src + 0x1B6);
        *(u8 *)((u8 *)dst + 0x1B7) = *(u8 *)((u8 *)src + 0x1B7);
        *(u8 *)((u8 *)dst + 0x1B8) = *(u8 *)((u8 *)src + 0x1B8);
        *(u8 *)((u8 *)dst + 0x1B9) = *(u8 *)((u8 *)src + 0x1B9);
        *(u8 *)((u8 *)dst + 0x1BA) = *(u8 *)((u8 *)src + 0x1BA);
        *(u8 *)((u8 *)dst + 0x1BB) = *(u8 *)((u8 *)src + 0x1BB);
        *(struct Pair *)((u8 *)dst + 0x1BC) = *(struct Pair *)((u8 *)src + 0x1BC);
        *(struct Pair *)((u8 *)dst + 0x1C4) = *(struct Pair *)((u8 *)src + 0x1C4);
        do {
            Item_Copy((u8 *)dstWalk + 0x1CC, (u8 *)srcWalk + 0x1CC);
            Item_Copy((u8 *)dstWalk + 0x1EC, (u8 *)srcWalk + 0x1EC);
            i += 1;
            srcWalk = (u8 *)srcWalk + 8;
            dstWalk = (u8 *)dstWalk + 8;
        } while (i < 4);
        *(struct Pair *)((u8 *)dst + 0x20C) = *(struct Pair *)((u8 *)src + 0x20C);
        *(u8 *)((u8 *)dst + 0x214) = *(u8 *)((u8 *)src + 0x214);
        *(u8 *)((u8 *)dst + 0x21E) = *(u8 *)((u8 *)src + 0x21E);
        *(u8 *)((u8 *)dst + 0x215) = *(u8 *)((u8 *)src + 0x215);
        *(u8 *)((u8 *)dst + 0x21F) = *(u8 *)((u8 *)src + 0x21F);
        *(u8 *)((u8 *)dst + 0x216) = *(u8 *)((u8 *)src + 0x216);
        *(u8 *)((u8 *)dst + 0x220) = *(u8 *)((u8 *)src + 0x220);
        *(u8 *)((u8 *)dst + 0x217) = *(u8 *)((u8 *)src + 0x217);
        *(u8 *)((u8 *)dst + 0x221) = *(u8 *)((u8 *)src + 0x221);
        *(u8 *)((u8 *)dst + 0x218) = *(u8 *)((u8 *)src + 0x218);
        *(u8 *)((u8 *)dst + 0x222) = *(u8 *)((u8 *)src + 0x222);
        *(u8 *)((u8 *)dst + 0x219) = *(u8 *)((u8 *)src + 0x219);
        *(u8 *)((u8 *)dst + 0x223) = *(u8 *)((u8 *)src + 0x223);
        *(u8 *)((u8 *)dst + 0x21A) = *(u8 *)((u8 *)src + 0x21A);
        *(u8 *)((u8 *)dst + 0x224) = *(u8 *)((u8 *)src + 0x224);
        *(u8 *)((u8 *)dst + 0x21B) = *(u8 *)((u8 *)src + 0x21B);
        *(u8 *)((u8 *)dst + 0x225) = *(u8 *)((u8 *)src + 0x225);
        *(u8 *)((u8 *)dst + 0x21C) = *(u8 *)((u8 *)src + 0x21C);
        *(u8 *)((u8 *)dst + 0x226) = *(u8 *)((u8 *)src + 0x226);
        *(u8 *)((u8 *)dst + 0x21D) = *(u8 *)((u8 *)src + 0x21D);
        *(u8 *)((u8 *)dst + 0x227) = *(u8 *)((u8 *)src + 0x227);
        *(u16 *)((u8 *)dst + 0x228) = *(u16 *)((u8 *)src + 0x228);
        *(u16 *)((u8 *)dst + 0x22A) = *(u16 *)((u8 *)src + 0x22A);
        *(u16 *)((u8 *)dst + 0x22C) = *(u16 *)((u8 *)src + 0x22C);
        *(u16 *)((u8 *)dst + 0x22E) = *(u16 *)((u8 *)src + 0x22E);
        *(u16 *)((u8 *)dst + 0x230) = *(u16 *)((u8 *)src + 0x230);
        *(u16 *)((u8 *)dst + 0x232) = *(u16 *)((u8 *)src + 0x232);
        *(u8 *)((u8 *)dst + 0x234) = *(u8 *)((u8 *)src + 0x234);
        *(u8 *)((u8 *)dst + 0x235) = *(u8 *)((u8 *)src + 0x235);
        *(u8 *)((u8 *)dst + 0x236) = *(u8 *)((u8 *)src + 0x236);
    }
}
#pragma use_lmw_stmw reset

#pragma global_optimizer off
