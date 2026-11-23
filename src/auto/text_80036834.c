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

void fn_80036834(u8 *arg0)
{
    s32 i;

    i = 0;
    arg0[0x214] = i;
    arg0[0x21E] = i;
    arg0[0x215] = i;
    arg0[0x21F] = i;
    arg0[0x216] = i;
    arg0[0x220] = i;
    arg0[0x217] = i;
    arg0[0x221] = i;
    arg0[0x218] = i;
    arg0[0x222] = i;
    arg0[0x219] = i;
    arg0[0x223] = i;
    arg0[0x21A] = i;
    arg0[0x224] = i;
    arg0[0x21B] = i;
    arg0[0x225] = i;
    arg0[0x21C] = i;
    arg0[0x226] = i;
    arg0[0x21D] = i;
    arg0[0x227] = i;

    if (*(u32 *)((u8 *)*(void **)(arg0 + 0x188) + 0x50) == 0) {
        return;
    }
    while (i < (u8)*(s32 *)((u8 *)*(void **)((u8 *)*(void **)(arg0 + 0x188) + 0x50) + 4)) {
        *(arg0 + i + 0x21E) = 5;
        i += 1;
    }
}
#pragma global_optimizer reset
void Unit_AddAffinityBonuses(void *arg0, u8 arg1, void *arg2) {
    void *Affinity_GetEntry(u8);
    void *temp_r3;

    temp_r3 = Affinity_GetEntry(M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x54));
    M2C_FIELD(arg2, u8 *, 4) = (u8) (M2C_FIELD(arg2, u8 *, 4) + (arg1 * M2C_FIELD(temp_r3, u8 *, 4)));
    M2C_FIELD(arg2, u8 *, 5) = (u8) (M2C_FIELD(arg2, u8 *, 5) + (arg1 * M2C_FIELD(temp_r3, u8 *, 5)));
    M2C_FIELD(arg2, u8 *, 6) = (u8) (M2C_FIELD(arg2, u8 *, 6) + (arg1 * M2C_FIELD(temp_r3, u8 *, 6)));
    M2C_FIELD(arg2, u8 *, 7) = (u8) (M2C_FIELD(arg2, u8 *, 7) + (arg1 * M2C_FIELD(temp_r3, u8 *, 7)));
    M2C_FIELD(arg2, u8 *, 8) = (u8) (M2C_FIELD(arg2, u8 *, 8) + (arg1 * M2C_FIELD(temp_r3, u8 *, 8)));
    M2C_FIELD(arg2, u8 *, 9) = (u8) (M2C_FIELD(arg2, u8 *, 9) + (arg1 * M2C_FIELD(temp_r3, u8 *, 9)));
}

void fn_80036984(s32 arg0, s32 arg1) {
    u8 *ptr = (u8 *)(arg0 + 0x214);
    ptr[arg1] += 1;
}

#pragma opt_strength_reduction off
#pragma global_optimizer off
void Unit_AddSupportPoints(void *arg0, s32 arg1) {
    u8 fn_80036B20(void *, s32);
    u8 cur;
    u8 *table;
    s32 off8;
    u8 *target;
    s32 offset;

    if (fn_80036B20(arg0, arg1)) {
        return;
    }
    target = (u8 *)arg0 + arg1;
    offset = arg1 << 3;
    target[0x214]++;
    off8 = offset + 8;
    table = *(u8 **)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x50);
    off8 = (s32)table + off8;
    cur = target[0x214];
    if (cur > (u8)(*(u8 *)(off8 + 6) + 1)) {
        target[0x214] = *(table + offset + 0xE) + 1;
    }
}
#pragma opt_strength_reduction reset
#pragma global_optimizer reset
s32 Unit_GetSupportRankTotal(u8 *arg0)
{
  u8 *table;
  u8 *entry;
  u8 *new_var3[2];
  int new_var2;
  s32 offset;
  u8 *obj;
  s32 result;
  s32 index;
  u8 value;
  u8 unit_val;
  u8 lim;
  obj = *((u8 **) (arg0 + 0x188));
  if ((*(void * volatile *) (obj + 0x50)) == NULL)
  {
    return 0;
  }
  result = 0;
  new_var2 = 0;
  index = new_var2;
  offset = new_var2;
  goto check;
  loop:
  table = *((u8 * volatile *) (obj + 0x50));

  entry = table + offset;
  if ((*((u32 *) (entry + 8))) != new_var2)
  {
    new_var3[0] = entry + 8;
    if (new_var3[0] == NULL)
    {
      value = new_var2;
    }
    else
    {
      unit_val = arg0[index + 0x214];
      if (unit_val <= new_var3[0][4])
      {
        value = new_var2;
      }
      else
        if (unit_val <= new_var3[0][5])
      {
        value = 1;
      }
      else
        if (unit_val <= new_var3[0][6])
      {
        value = 2;
      }
      else
      {
        value = 3;
      }
    }
    switch (value)
    {
      case 3:
        result += 1;

      case 2:
        result += 1;

      case 1:
        result += 1;
        break;

    }

  }
  offset += 8;
  index += 1;
  check:
  table = *((u8 * volatile *) (obj + 0x50));

  if (table == NULL)
  {
    lim = new_var2;
  }
  else
  {
    lim = (u8) (*((u32 *) (table + 4)));
    lim = (u8) (lim & 0xFFu);
  }
  if (index < ((s32) lim))
  {
    goto loop;
  }
  return result;
}

#pragma opt_strength_reduction off
s32 fn_80036B20(void *arg0, s32 arg1) {
    void *Unit_FindByPerson(s32);
    u8 *p;
    u8 *base;
    u8 *person, *person2;
    u8 *base2;
    u8 *elem;
    u8 *e;
    void *unit;
    s32 cnt, cnt2;
    s32 j, i;
    s32 off2, off;
    u8 rank;
    u8 value;

    p = (u8 *)arg0;
    person = *(u8 **)(p + 0x188);
    base = *(u8 **)(person + 0x50);
    if (base == 0) return 0;
    if (base == 0) { cnt = 0; } else {
        cnt = 0;
        i = cnt;
        off = cnt;
        while (i < (u8)(*(u8 **)(person + 0x50) == 0 ? 0 : (u8)*(u32 *)(*(u8 **)(person + 0x50) + 4))) {
            elem = base + off;
            if (*(u32 *)(elem + 8) != 0) {
                e = elem + 8;
                if (e == 0) {
                    rank = 0;
                } else {
                    value = p[i + 0x214];
                    if (value <= *(u8 *)(e + 4)) rank = 0;
                    else if (value <= *(u8 *)(e + 5)) rank = 1;
                    else if (value <= *(u8 *)(e + 6)) rank = 2;
                    else rank = 3;
                }
                switch (rank) {
                case 3: cnt++;
                case 2: cnt++;
                case 1: cnt++;
                    break;
                }
            }
            off += 8;
            i++;
        }
    }
    if (cnt >= 5) return 0;
    elem = base + arg1 * 8;
    unit = Unit_FindByPerson(*(s32 *)(elem + 8));
    if (unit == 0) return 0;
    person2 = *(u8 **)((u8 *)unit + 0x188);
    base2 = *(u8 **)(person2 + 0x50);
    if (base2 == 0) {
        cnt2 = 0;
    } else {
        cnt2 = 0;
        j = cnt2;
        off2 = cnt2;
        while (j < (u8)(*(u8 **)(person2 + 0x50) == 0 ? 0 : (u8)*(u32 *)(*(u8 **)(person2 + 0x50) + 4))) {
            base2 = *(u8 **)(*(u8 **)((u8 *)unit + 0x188) + 0x50);
            elem = base2 + off2 + 8;
            if (*(u32 *)elem != 0) {
                e = elem;
                if (e == 0) {
                    rank = 0;
                } else {
                    value = ((u8 *)unit)[j + 0x214];
                    if (value <= *(u8 *)(e + 4)) rank = 0;
                    else if (value <= *(u8 *)(e + 5)) rank = 1;
                    else if (value <= *(u8 *)(e + 6)) rank = 2;
                    else rank = 3;
                }
                switch (rank) {
                case 3: cnt2++;
                case 2: cnt2++;
                case 1: cnt2++;
                    break;
                }
            }
            off2 += 8;
            j++;
        }
    }
    if (cnt2 >= 5) return 0;
    e = *(u8 **)(*(u8 **)(p + 0x188) + 0x50) + (arg1 * 8 + 8);
    if (e == 0) return 0;
    value = p[arg1 + 0x214];
    if (value == *(u8 *)(e + 4) || value == *(u8 *)(e + 5) || value == *(u8 *)(e + 6)) return 1;
    return 0;
}
#pragma global_optimizer off
#pragma scheduling off
