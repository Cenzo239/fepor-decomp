/* Functions from 0x800330F8 to 0x80055C70, found by decomp-toolkit. */
#include "common.h"
extern u8 gBattleMap[];

typedef struct { f32 x, y, z; } Vec;
typedef struct MapHeightCell444 { u8 pad[0x142D4]; s16 lower; u8 gap[0x8002]; s16 upper; } MapHeightCell444;
static inline void Map_CopyHeights444(u8 *map, s32 index, const s16 *lower, const s16 *upper)
{
    s32 k;
    MapHeightCell444 *cell;
    for (k = 0; k < 4; k++) {
        cell = (MapHeightCell444 *)(map + 2 * (index * 4 + k));
        cell->lower = lower[k];
        cell->upper = upper[k];
    }
}

static inline void Map_SetHeights444(u8 *map, s32 index, const s16 *heights)
{
    s32 k;
    MapHeightCell444 *cell;
    s16 height;
    for (k = 0; k < 4; k++) {
        height = heights[k];
        cell = (MapHeightCell444 *)(map + 2 * (index * 4 + k));
        cell->lower = height;
        cell->upper = height;
    }
}

static inline u8 DirFromIndex_80042558(s32 i)
{
    switch (i) {
    case 0: return 1;
    case 1: return 2;
    case 2: return 4;
    case 3: return 8;
    default: return 16;
    }
}

static inline s32 DirGetDX_80042558(s32 dir)
{
    switch (dir) {
    case 1: return -1;
    case 2: return 1;
    default: return 0;
    }
}

static inline s32 DirGetDY_80042558(s32 dir)
{
    switch (dir) {
    case 4: return 1;
    case 8: return -1;
    default: return 0;
    }
}

typedef struct {
    u8 pad0[4];
    s8 x0;
    s8 y0;
    s8 x1;
    s8 y1;
    u8 pad8[8];
    void *unk10;
    u8 pad14[0xA0];
} MapObj_80042558;

static inline u8 IsInRect_80042558(MapObj_80042558 *ent, s32 x, s32 y)
{
    if (x >= ent->x0 && x <= ent->x1 && y >= ent->y0 && y <= ent->y1) {
        return 1;
    }
    return 0;
}

typedef struct {
    u8 pad0[6];
    s16 count;
    u8 pad8[0xC];
    MapObj_80042558 *objs;
} Map_80042558;

static inline u8 *FindMapObj_80042558(Map_80042558 *map, s32 x, s32 y, u32 forbid, u32 require)
{
    s32 i;
    for (i = map->count - 1; i >= 0; i--) {
        if (forbid != 0 && (M2C_FIELD(map->objs[i].unk10, u32 *, 0xBC) & forbid)) continue;
        if ((M2C_FIELD(map->objs[i].unk10, u32 *, 0xBC) & require) != require) continue;
        if (IsInRect_80042558(&map->objs[i], x, y)) {
            return (u8 *)&map->objs[i];
        }
    }
    return 0;
}

static inline u8 *FindMapObjNear_80042558(Map_80042558 *map, s32 x, s32 y, u32 require)
{
    u8 *found = FindMapObj_80042558(map, x, y, 0, require);
    if (found != 0) {
        return found;
    }
    {
        s32 dir;
        for (dir = 0; dir < 4; dir++) {
            s32 d = DirFromIndex_80042558(dir);
            found = FindMapObj_80042558(map, x + DirGetDX_80042558(d), y + DirGetDY_80042558(d), 0, require);
            if (found != 0) {
                return found;
            }
        }
    }
    return 0;
}

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
static inline void fn_80050E14_Body(u8 *obj, s32 zero) {
 s32 tableOffset, offset, i, n;
 u8 *table, *base;
 i = zero;
 *(s32 *)(obj+0x14) = i;
 offset = i;
 tableOffset = i;
 while (i < (n = *(s32 *)(obj+0x18))) {
  base = *(u8 **)obj;
  i++;
  table = *(u8 **)(obj+4);
  *(u32 *)(table+tableOffset) = (u32)base + offset;
  offset += 20;
  tableOffset += 4;
 }
 table = *(u8 **)(obj+4);
 *(u32 *)(table+n*4) = 0;
 *(void **)(obj+8) = *(void **)(obj+4);
 *(s32 *)(obj+12) = 0;
 *(s32 *)(obj+16) = 0;
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


static inline void *Unit_ResolveDisplayResource(s32 value,void *arg0) {
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

static inline void *Unit_GetDisplayTexture(void *unit) {
 void *fn_8004B078(void *, s32);
 void *resource = get_4F128_resource(unit, get_4F128_id(unit));
 switch(M2C_FIELD(M2C_FIELD(unit,void **,0x190),u8 *,8)) {
 case 0: return fn_8004B078(resource,0);
 case 1: return fn_8004B078(resource,1);
 case 2: return fn_8004B078(resource,2);
 case 3: return fn_8004B078(resource,3);
 default: return fn_8004B078(resource,0);
 }
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

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern s32 gGameState;

extern u16 gAffinityStr[];

/* If the unit has status flag 8, clear held items and equip the class default weapon. */

#pragma global_optimizer off
/* Tick laguz transform gauge by +4 (or -3 if transformed); return 1 if it hit 0 or 0x14. */

/* Tick laguz transform gauge by +2 (or -1 if transformed); return 1 if it hit 0 or 0x14. */

#pragma global_optimizer reset

/* Write unit aux fields (hash refs at +0x238.., counters, ids) to stream. */

void *Res_GetByName(s32);

#pragma global_optimizer off
/* Read a unit record from stream into unit; return 0 if person id is 0 (empty). */

#pragma use_lmw_stmw on

#pragma global_optimizer on

#pragma opt_strength_reduction off
#pragma optimization_level 3

#pragma optimization_level reset
#pragma opt_strength_reduction reset

#pragma opt_strength_reduction reset

#pragma use_lmw_stmw on

#pragma dont_inline on

#pragma dont_inline reset

#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

void fn_8005C7E8(void *);

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer on
#pragma use_lmw_stmw reset

static inline u8 MapObj_HasActionFlag(u32 flags)
{
    if (flags & 0x10) return 0;
    if (flags & 0x800) return 1;
    if (flags & 0x1000) return 1;
    return 0;
}

static inline u8 MapObj_HasBlockedAction(u32 flags)
{
    if (flags & 0x10) return 0;
    if (flags & 0x100000) return 1;
    return 0;
}

static inline u8 MapObj_GetState(u8 *obj)
{
    return obj[2] & 3;
}

static inline u8 MapObj_IsIdle(u8 *obj)
{
    u8 idle = MapObj_GetState(obj) == 0;
    return idle;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
/* Per-frame map update: alternate half-range prepare, rebuild entry matrices, queue deferred work. */

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

/* Decode map header flags at +0x64 into gMapBlendMode and gBattleSkyIndex. */

#pragma optimization_level 3

#pragma optimization_level reset
#pragma global_optimizer off
#pragma opt_lifetimes on

#pragma global_optimizer on
#pragma use_lmw_stmw on

void fn_80042558(Map_80042558 *arg0)
{
    void fn_8005FEE8(void *, f32);
    void MapObj_FadeOut(void *, s32);
    s32 Map_CollectLinkedObjs(void *, void *, void *);
    void MapObj_Hide(void *, s32);
    s32 fn_8010FF88(void *);
    void fn_80044450(void *, s32);
    void Map_RefreshUnitMap(void *);
    void fn_8012391C(void *);
    void fn_800C1BDC(void);
    void fn_800C1984(void);
    void fn_8014716C(s32);
    void fn_80067460(s32);
    void fn_80066F64(void);
    void *Light_GetChannel(s32);
    void Light_CopyChannel(void *, void *);
    void fn_8006720C(void *);
    void fn_800675C8(s32);
    void *Fog_GetColor(void);
    void fn_80067480(void);
    void fn_80016180(void);

    extern u8 gMapObjEventList[];
    extern u8 gBattleMap[];
    extern u8 gMapBlendMode;
    extern f32 lbl_80368F2C;
    extern const f32 lbl_80368EF4;
    extern u8 lbl_80367294;
    extern u8 lbl_80367295;
    extern u8 lbl_80367298[3];
    extern u8 lbl_8036729C[3];
    extern u8 lbl_8036728C;
    extern u8 lbl_8036728D;
    extern u8 lbl_8036728E;
    extern u8 lbl_80367290[3];

    void *list[8];
    s32 eventIndex;

    for (eventIndex = 0; eventIndex < fn_8010FF88(gMapObjEventList); eventIndex++) {
        s8 *rec = (s8 *)(gMapObjEventList + eventIndex * 8);
        s32 x = rec[0];
        s32 y = rec[1];
        switch ((u8)rec[2] - 0x21) {
        case 3:
        {
            u8 *found = FindMapObj_80042558(arg0, x, y, 0x410, 0xA00);
            if (found != 0) {
                fn_8005FEE8(found + 0x14, lbl_80368F2C);
            }
            break;
        }
        case 0:
        {
            u8 *found = FindMapObj_80042558(arg0, x, y, 0, 0x1000);
            if (found != 0) {
                MapObj_FadeOut(found, 0);
                found = FindMapObjNear_80042558(arg0, x, y, 0x800);
                if (found != 0) {
                    s32 count = Map_CollectLinkedObjs(arg0, found, list);
                    s32 k;
                    for (k = 0; k < count; k++) {
                        MapObj_Hide(list[k], 0);
                    }
                }
            }
            break;
        }
        case 1:
        {
            u8 *found = FindMapObj_80042558(arg0, x, y, 0x410, 0x800);
            if (found != 0) {
                s32 count = Map_CollectLinkedObjs(arg0, found, list);
                s32 k;
                for (k = 0; k < count; k++) {
                    MapObj_Hide(list[k], 0);
                }
            }
            break;
        }
        case 2:
        {
            u8 *found = FindMapObj_80042558(arg0, x, y, 0x410, 0x200);
            if (found != 0) {
                fn_8005FEE8(found + 0x14, lbl_80368F2C);
            }
            break;
        }
        case 4:
        {
            u8 *found = FindMapObj_80042558(arg0, x, y, 0x410, 0xA00);
            if (found != 0) {
                found[2] |= 1;
                found = FindMapObj_80042558(arg0, x, y, 0, 0x20000);
                if (found != 0) {
                    fn_8005FEE8(found + 0x14, lbl_80368F2C);
                    found[2] &= ~1;
                }
            }
            break;
        }
        case 5:
        {
            u8 *found = FindMapObj_80042558(arg0, x, y, 0x410, 0x800);
            if (found != 0) {
                MapObj_Hide(found, 0);
            }
            break;
        }
        case 6:
        {
            u8 *found = FindMapObj_80042558(arg0, x, y, 0, 0x10000);
            if (found != 0) {
                MapObj_Hide(found, 0);
            }
            break;
        }
        case 7:
        {
            u8 *found = FindMapObj_80042558(arg0, x, y, 0x410, 0x200);
            if (found != 0) {
                fn_8005FEE8(found + 0x14, lbl_80368F2C);
            }
            break;
        }
        case 8:
        {
            u8 *found = FindMapObj_80042558(arg0, x, y, 0x10, 0x80000);
            if (found != 0) {
                found[2] |= 1;
            }
            break;
        }
        }
    }

    fn_80044450(arg0, 1);
    Map_RefreshUnitMap(gBattleMap);
    fn_8012391C(M2C_FIELD(arg0, void **, 0x30));

    switch (M2C_FIELD(arg0, u8 *, 0x68)) {
    case 0:
    {
        u8 validBlend;
        fn_800C1BDC();
        fn_800C1984();
        validBlend = (gMapBlendMode == 1 || gMapBlendMode == 2);
        if (validBlend) {
            fn_8014716C(1);
        } else {
            fn_8014716C(0);
        }
        break;
    }
    }

    fn_80067460(0);
    fn_80066F64();
    {
        u8 *channel = Light_GetChannel(0);
        *(f32 *)(channel + 0x24) = (f32)(s8)lbl_80367294;
        *(f32 *)(channel + 0x28) = (f32)(s8)lbl_80367295;
        channel[0] = lbl_8036729C[0];
        channel[1] = lbl_8036729C[1];
        channel[2] = lbl_8036729C[2];
        channel[4] = lbl_80367298[0];
        channel[5] = lbl_80367298[1];
        channel[6] = lbl_80367298[2];
    }
    Light_CopyChannel(Light_GetChannel(0), Light_GetChannel(2));
    fn_8006720C((u8 *)arg0 + 0x70);
    fn_800675C8(0);
    {
        u8 *fog = Fog_GetColor();
        fn_80067480();
        fog[0] = lbl_8036728C;
        *(f32 *)(fog + 4) = (f32)(s8)lbl_8036728D *
            M2C_FIELD(arg0, f32 *, 0x6C) * lbl_80368EF4;
        *(f32 *)(fog + 8) = (f32)(s8)lbl_8036728E *
            M2C_FIELD(arg0, f32 *, 0x6C) * lbl_80368EF4;
        fog[1] = lbl_80367290[0];
        fog[2] = lbl_80367290[1];
        fog[3] = lbl_80367290[2];
    }
    fn_80016180();
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
    u8 flags;
    f32 f31v, f30v, f29v, f28v;
    f32 t30;
    s16 h;
    s32 a, b;
    f32 scale;
    f32 temp_f0;

    fn_80067708(0, 1, fn_80043E88, arg0);
    if (*(u32 *)((u8 *)arg0 + 0xC) != 0) {
        s32 n;
        u8 *e;
        e = *(u8 **)((u8 *)arg0 + 0x14);
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
        if (n < *(s16 *)((u8 *)arg0 + 6)) {
            goto clear_body;
        }
    }
    if ((*(u32 *)((u8 *)arg0 + 0x64) & 0x80000000) == 0 && (*(u32 *)((u8 *)arg0 + 0x64) & 0x40000000) != 0) {
        ent = *(u8 **)((u8 *)arg0 + 0x14);
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
                    if (*(u8 *)((u8 *)arg0 + 0x68) == 1) {
                        a = *(s16 *)arg0;
                        h = *(s16 *)((u8 *)arg0 + 2);
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
                    scale = *(f32 *)((u8 *)arg0 + 0x6C);
                    PSMTXScale(spF8, scale, scale, scale);
                    PSMTXConcat(spF8, spC8, spC8);
                    temp_f0 = *(f32 *)((u8 *)arg0 + 0x6C);
                    PSMTXTrans(sp158, lbl_80368EF4 * (f28v * temp_f0), lbl_80368EF4 * (f29v * temp_f0), lbl_80368EF4 * (f30v * temp_f0));
                    PSMTXConcat(sp158, spC8, spC8);
                    PSMTXConcat((u8 *)arg0 + 0x70, spC8, ent + 0x24);
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
        if (i < *(s16 *)((u8 *)arg0 + 6)) {
            goto loop1_body;
        }
    }
    if (*(u32 *)((u8 *)arg0 + 0xC) != 0 && (*(u32 *)((u8 *)arg0 + 0x64) & 0x80000000) == 0) {
        fn_8006785C(2, fn_800449C8, arg0);
    }
    if ((*(u32 *)((u8 *)arg0 + 0x64) & 0x80000000) == 0 && (*(u32 *)((u8 *)arg0 + 0x64) & 0x40000000) != 0) {
        u32 m;
        s32 n;
        ent = *(u8 **)((u8 *)arg0 + 0x14);
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
                    if (*(u8 *)((u8 *)arg0 + 0x68) == 1) {
                        a = *(s16 *)arg0;
                        h = *(s16 *)((u8 *)arg0 + 2);
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
                    scale = *(f32 *)((u8 *)arg0 + 0x6C);
                    PSMTXScale(sp38, scale, scale, scale);
                    PSMTXConcat(sp38, sp8, sp8);
                    temp_f0 = *(f32 *)((u8 *)arg0 + 0x6C);
                    PSMTXTrans(sp98, lbl_80368EF4 * (f31v * temp_f0), lbl_80368EF4 * (f30v * temp_f0), lbl_80368EF4 * (f29v * temp_f0));
                    PSMTXConcat(sp98, sp8, sp8);
                    PSMTXConcat((u8 *)arg0 + 0x70, sp8, ent + 0x24);
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
        if (n < *(s16 *)((u8 *)arg0 + 6)) {
            goto loop2_body;
        }
    }
    fn_80067708(2, 3, fn_80043DEC, arg0);
}

void fn_80043838(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7)
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

    f32 scale;
    u32 size;
    void *buffer;

    lbl_803672A8 = Heap_Alloc(0x20);

    *(f32 *)((u8 *)lbl_803672A8 + 0x00) = arg2;
    *(f32 *)((u8 *)lbl_803672A8 + 0x04) = arg3;
    *(f32 *)((u8 *)lbl_803672A8 + 0x10) = arg6;
    *(f32 *)((u8 *)lbl_803672A8 + 0x14) = arg7;

    scale = arg4;
    if (arg4 * arg7 / arg6 < arg5) {
        scale = arg5;
    }
    if (scale > lbl_80368F30) {
        scale = lbl_80368F30;
    }

    *(f32 *)((u8 *)lbl_803672A8 + 0x08) = scale;
    *(f32 *)((u8 *)lbl_803672A8 + 0x0C) = scale;

    if (arg6 > arg7) {
        *(f32 *)((u8 *)lbl_803672A8 + 0x08) *= arg6 / arg7;
    } else {
        *(f32 *)((u8 *)lbl_803672A8 + 0x0C) *= arg7 / arg6;
    }

    size = GXGetTexBufferSize((s32)arg6, (s32)arg7, 4, 0, 0);
    buffer = fn_800C45B8(-(s32)size, lbl_8026A660 + 0x245, 0);
    *(void **)((u8 *)lbl_803672A8 + 0x1C) = buffer;
    DCInvalidateRange(*(void **)((u8 *)lbl_803672A8 + 0x1C), size);

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
    extern u32 gGameFlags;
    void *temp_r31;

    fn_80068550(M2C_FIELD(arg0, s32 *, 0x54));
    temp_r31 = M2C_FIELD(arg0, void **, 0x58);
    fn_800C4588(M2C_FIELD(temp_r31, void **, 0x114));
    M2C_FIELD(temp_r31, void **, 0x114) = NULL;
    fn_800C4588(temp_r31);
    gGameFlags &= ~8U;
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
    f32 b;
    f32 a;
    f32 zero;
    f32 p1;
    f32 p3;
    f32 t;
    f32 fy;
    f32 fx;
    f32 p0;
    f32 half;
    f32 scale;
    f32 p2;
    f32 hi;

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

#pragma global_optimizer off
u8 fn_8004434C(void *arg0, s32 x, s32 y) {
u8 *map=arg0; u8 *entry; s32 count; u32 flags, disabled; u8 valid; s32 x0,y0,x1,y1;
if (!(*(u32 *)(map+0x64)&0x10000000)) return 0;
count=*(s16 *)(map+6); entry=*(u8 **)(map+0x14);
while(count>0) {
flags=*(u32 *)(*(u8 **)(entry+0x10)+0xBC); disabled=flags&0x10;
if(disabled) valid=0;
else if(flags&0x800) valid=1;
else if(flags&0x1000) valid=1;
else valid=0;
if(valid) {
if(disabled) valid=0;
else if(flags&0x100000) valid=1;
else valid=0;
if(!valid) {
valid=(entry[2]&3)==0;
if(valid) {
x0=entry[4]; y0=entry[5]; x1=entry[6]; y1=entry[7];
y1=(s8)y1; y0=(s8)y0; x1=(s8)x1; x0=(s8)x0;
if(x>=x0 && x<=x1 && y>=y0 && y<=y1) return 1;
}
}
}
entry+=0xB4; count--;
}
return 0;
}
#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
#pragma opt_common_subs off
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
    s32 k;
    MapHeightCell444 *cell;

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
        for (col = 0; col < *(s16 *)((u8 *)arg0 + 0); col++) {
            tileA = (u8 *)tblA + *idxA++ * 0xC;
            tileB = (u8 *)tblB + *idxB++ * 0xC;
            ok = fn_8005B7A4(*(void **)(tileA + 8));
            c = (s8)col;
            off = c + 0x100D;
            rowPtr[off] = ok;
            t = c + rowSl;
            Map_CopyHeights444(ca, t, (s16*)tileA, (s16*)tileB);
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
                    src = idxA + (x0 + yy * *(s16 *)((u8 *)arg0 + 0));
                    rowSl = (s8)yy << 6;
                    rowPtr = ca + rowSl;
                    xx = x0;
                    for (; xx <= x1; xx++) {
                        ia = *src;
                        src += 1;
                        tile = (u8 *)tblA + ia * 0xC;
                        ok = fn_8005B7A4(*(void **)(tile + 8));
                        c = (s8)xx;
                        off = c + 0x100D;
                        rowPtr[off] = ok;
                        t = c + rowSl;
                        Map_SetHeights444(ca, t, (s16*)tile);
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
                    src = idxA + (x0 + yy * *(s16 *)((u8 *)arg0 + 0));
                    rowSl = (s8)yy << 6;
                    rowPtr = ca + rowSl;
                    xx = x0;
                    for (; xx <= x1; xx++) {
                        ia = *src;
                        src += 1;
                        tile = (u8 *)tblA + ia * 0xC;
                        ok = fn_8005B7A4(*(void **)(tile + 8));
                        c = (s8)xx;
                        off = c + 0x100D;
                        rowPtr[off] = ok;
                        t = c + rowSl;
                        sh = t << 3;
                        p = ca + sh;
                        *(s16 *)(p + 0x142D4) = *(s16 *)tile;
                        q = t << 2;
                        p = ca + ((q + 1) << 1);
                        *(s16 *)(p + 0x142D4) = *(s16 *)(tile + 2);
                        p = ca + ((q + 2) << 1);
                        *(s16 *)(p + 0x142D4) = *(s16 *)(tile + 4);
                        p = ca + ((q + 3) << 1);
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
#pragma pop

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
s32 flag;
u32 t;
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
flag=1;
t=((u8)(gMapBlendMode-1)<=(u32)flag);
if(!t) flag=0;
if((u8)flag) fn_800C15A8();
GXSetNumTevStages(fn_80069E74());
GXSetNumChans(fn_80069DB4());
fn_80224A68(M2C_FIELD(arg0,s32 *,0xa4),M2C_FIELD(arg0,s32 *,0xa8));
fn_80066D00(-1);
}

void fn_80044BE4(void *arg0) {
    f32 Map_GetTileCornerHeight(void *, s8, s8, u8);
    void *fn_800C45B8(s32, void *, s32);
    void fn_800C4588(void *);
    void *fn_800C4638(s32, void *, s32);
    void DCInvalidateRange(void *, u32);
    void DCFlushRange(void *, u32);
    void *fn_802248D8(void *, u32);
    s32 fn_802249A4(void);
    void GXBegin(s32, s32, s32);
    void DebugPrint(void *, ...);
    void *memcpy(void *, void *, s32);
    extern u8 lbl_8026A660[];
    extern u8 gBattleMap[];
    extern f32 lbl_80368F58;
    void *buf;
    void *disp;
    s32 y;
    s32 x;
    u8 *row;
    u8 *base;
    u8 *cell;
    s32 margin;
    u8 *above;
    u8 *mapRow;
    s32 tile;
    f32 dx;
    f32 dy;
    f32 a;
    s32 size;
    void *out;

    margin = M2C_FIELD(arg0, u8 *, 0x61);
    buf = fn_800C45B8(-0x4000, lbl_8026A660 + 0x245, 0);
    base = (u8 *)buf + (margin << 7);
    row = base;
    y = margin;
    while (y < M2C_FIELD(arg0, s16 *, 2) - margin) {
        x = margin;
        cell = row + margin;
        above = (u8 *)buf + (((y - 1) << 7) + margin);
        mapRow = gBattleMap + ((s8)y << 6);
        while (x < M2C_FIELD(arg0, s16 *, 0) - margin) {
            s32 off;
            *cell = 0;
            off = (s8)x + 0x100D;
            tile = mapRow[off];
            if (tile == 0xB) goto next_cell;
            if (tile < 0xB) {
                if (tile == 4) goto next_cell;
                if (tile >= 4) goto do_edge;
                if (tile == 0) goto next_cell;
            } else {
                if (tile >= 0x49) goto do_edge;
                if (tile >= 0x45) goto next_cell;
            }
        do_edge:
            *cell = 6;
            if (x == margin) {
                *cell |= 1;
            } else if (cell[-1] == 0) {
                *cell |= 1;
            } else {
                a = Map_GetTileCornerHeight(gBattleMap, x - 1, y, 1);
                dx = Map_GetTileCornerHeight(gBattleMap, x, y, 0) - a;
                a = Map_GetTileCornerHeight(gBattleMap, x - 1, y, 3);
                dy = Map_GetTileCornerHeight(gBattleMap, x, y, 2) - a;
                if (dx * dx + dy * dy >= lbl_80368F58) {
                    *cell |= 1;
                }
            }
            if (y == margin) {
                *cell |= 8;
            } else if (*above == 0) {
                *cell |= 8;
            } else {
                a = Map_GetTileCornerHeight(gBattleMap, x, y - 1, 2);
                dx = Map_GetTileCornerHeight(gBattleMap, x, y, 0) - a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y - 1, 3);
                dy = Map_GetTileCornerHeight(gBattleMap, x, y, 1) - a;
                if (dx * dx + dy * dy >= lbl_80368F58) {
                    *cell |= 8;
                }
            }
        next_cell:
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
    y = margin;
    while (y < M2C_FIELD(arg0, s16 *, 2) - margin) {
        x = margin;
        cell = base + margin;
        while (x < M2C_FIELD(arg0, s16 *, 0) - margin) {
            tile = *cell;
            if ((u32)tile != 0) {
                if (tile == 0xE) {
                    goto case_e;
                }
                if (tile < 0xE) {
                    if (tile == 7) goto case_7;
                    if (tile >= 7) goto next2;
                    if (tile >= 6) goto tri;
                    goto next2;
                } else {
                    if (tile >= 0x10) goto next2;
                    goto case_f;
                }
            tri:
                GXBegin(0xB0, 0, 3);
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 1);
                *(volatile f32 *)0xCC008000 = (f32)(x + 1);
                *(volatile f32 *)0xCC008000 = (f32)y;
                *(volatile f32 *)0xCC008000 = a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 3);
                *(volatile f32 *)0xCC008000 = (f32)(x + 1);
                *(volatile f32 *)0xCC008000 = (f32)(y + 1);
                *(volatile f32 *)0xCC008000 = a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 2);
                *(volatile f32 *)0xCC008000 = (f32)x;
                *(volatile f32 *)0xCC008000 = (f32)(y + 1);
                *(volatile f32 *)0xCC008000 = a;
                goto next2;
            case_7:
                GXBegin(0xB0, 0, 4);
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 1);
                *(volatile f32 *)0xCC008000 = (f32)(x + 1);
                *(volatile f32 *)0xCC008000 = (f32)y;
                *(volatile f32 *)0xCC008000 = a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 3);
                *(volatile f32 *)0xCC008000 = (f32)(x + 1);
                *(volatile f32 *)0xCC008000 = (f32)(y + 1);
                *(volatile f32 *)0xCC008000 = a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 2);
                *(volatile f32 *)0xCC008000 = (f32)x;
                *(volatile f32 *)0xCC008000 = (f32)(y + 1);
                *(volatile f32 *)0xCC008000 = a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 0);
                *(volatile f32 *)0xCC008000 = (f32)x;
                *(volatile f32 *)0xCC008000 = (f32)y;
                *(volatile f32 *)0xCC008000 = a;
                goto next2;
            case_e:
                GXBegin(0xB0, 0, 4);
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 0);
                *(volatile f32 *)0xCC008000 = (f32)x;
                *(volatile f32 *)0xCC008000 = (f32)y;
                *(volatile f32 *)0xCC008000 = a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 1);
                *(volatile f32 *)0xCC008000 = (f32)(x + 1);
                *(volatile f32 *)0xCC008000 = (f32)y;
                *(volatile f32 *)0xCC008000 = a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 3);
                *(volatile f32 *)0xCC008000 = (f32)(x + 1);
                *(volatile f32 *)0xCC008000 = (f32)(y + 1);
                *(volatile f32 *)0xCC008000 = a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 2);
                *(volatile f32 *)0xCC008000 = (f32)x;
                *(volatile f32 *)0xCC008000 = (f32)(y + 1);
                *(volatile f32 *)0xCC008000 = a;
                goto next2;
            case_f:
                GXBegin(0xB0, 0, 5);
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 0);
                *(volatile f32 *)0xCC008000 = (f32)x;
                *(volatile f32 *)0xCC008000 = (f32)y;
                *(volatile f32 *)0xCC008000 = a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 1);
                *(volatile f32 *)0xCC008000 = (f32)(x + 1);
                *(volatile f32 *)0xCC008000 = (f32)y;
                *(volatile f32 *)0xCC008000 = a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 3);
                *(volatile f32 *)0xCC008000 = (f32)(x + 1);
                *(volatile f32 *)0xCC008000 = (f32)(y + 1);
                *(volatile f32 *)0xCC008000 = a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 2);
                *(volatile f32 *)0xCC008000 = (f32)x;
                *(volatile f32 *)0xCC008000 = (f32)(y + 1);
                *(volatile f32 *)0xCC008000 = a;
                a = Map_GetTileCornerHeight(gBattleMap, x, y, 0);
                *(volatile f32 *)0xCC008000 = (f32)x;
                *(volatile f32 *)0xCC008000 = (f32)y;
                *(volatile f32 *)0xCC008000 = a;
            }
        next2:
            cell += 1;
            x += 1;
        }
        base += 0x80;
        y += 1;
    }

    size = fn_802249A4();
    out = M2C_FIELD(arg0, void **, 0xA4);
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

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_80045604(s32 unused) {
    void *fn_8000D2BC(void *);
    u32 fn_8000D354(void *);
    extern u8 lbl_8026A660[];
    extern u8 lbl_802CA518[];

    typedef struct { u8 pad[0x408E]; u16 flags; } FlagTile;

    s16 *data;
    s16 count;
    register s32 n;
    register u8 *p;
    s32 i;
    s32 x;
    s32 y;
    u8 v;
    FlagTile *fp;
    u32 pairs;
    u8 *base;

    if (fn_8000D354(lbl_8026A660 + 0x2D3) != 0) {
        data = fn_8000D2BC(lbl_8026A660 + 0x2D3);
        count = *data;
        p = (u8 *)data + 2;
        i = 0;
        n = count;
        {
            for (i = 0; i < n; i++) {
                x = (s8)p[0];
                y = (s8)p[1];
                v = p[2];
                p += 3;
                ((FlagTile *)(lbl_802CA518 + ((x + (y << 6)) * 2)))->flags = v;
            }
        }
    }

    if (fn_8000D354(lbl_8026A660 + 0x2DB) != 0) {
        data = fn_8000D2BC(lbl_8026A660 + 0x2DB);
        count = *data;
        p = (u8 *)data + 2;
        base = lbl_802CA518;
        n = count;
        for (i = 0; i < n; i++, p += 3) {
            x = (s8)p[0]; y = (s8)p[1]; v = p[2];
            fp = (FlagTile *)(base + ((x + (y << 6)) * 2));
            fp->flags = (fp->flags & ~0x0F00) | (v << 8);
        }
    }

    if (fn_8000D354(lbl_8026A660 + 0x2E5) != 0) {
        data = fn_8000D2BC(lbl_8026A660 + 0x2E5);
        count = *data;
        p = (u8 *)data + 2;
        i = 0;
        n = count;
        {
            for (i = 0; i < n; i++) {
                x = (s8)p[0];
                y = (s8)p[1];
                v = p[2];
                p += 3;
                ((FlagTile *)(lbl_802CA518 + ((x + (y << 6)) * 2)))->flags =
                    (u16)(v + (((~v) << 4) & 0xF0));
            }
        }
    }
}
#pragma pop
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

void fn_80045C68(s32 arg0)
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
    fn_8006720C((u8 *)arg0 + 0x70);
}

#pragma push
#pragma optimization_level 4
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
    r26v = *sp8++;
    r29v = *sp8++;
    ent[4] = *sp8++;
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
        f24v -= (f32)(*(s16 *)self / 2);
        f26v -= (f32)(*(s16 *)((u8 *)self + 2) / 2);
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
    *(void **)(sub + 4) = (u8 *)*(void **)((u8 *)self + 0x10) + r29v + 4;
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

    {
    u8 *entry2;
    s32 groupIndex;
    s32 frameCount;
    r29v = 0;
    r26v = 0;
    groupIndex = r29v;
    sub = (u8 *)r29v;
    goto loop2_test;
loop2_body:
    base = *(u8 **)((u8 *)self + 0x14);
    entry2 = base + (s32)sub;
    if (*(u32 *)(*(u8 **)(entry2 + 0x10) + 0xBC) & 0x400) {
        if (r26v == 0) {
            m = r29v + 1;
            idx = m * 0xB4;
            {
                for (; m < count; m++) {
                    other = base + idx;
                    if (*(void **)(entry2 + 0x10) != *(void **)(other + 0x10)
                        || (s8)entry2[0] != (s8)other[0]
                        || (s8)entry2[1] != (s8)other[1]) {
                        break;
                    }
                    r26v += 1;
                    idx += 0xB4;
                }
            }
            groupIndex = 0;
        }
        if (r26v > 0) {
            u8 *s2 = entry2 + 0x14;
            ref = fn_80060664(s2);
            frameCount = *(s32 *)((u8 *)ref + 0x18);
            tmp = r26v + 1;
            fn_8005FEE8(s2, (f32)((groupIndex * frameCount) / tmp));
            groupIndex += 1;
            if (groupIndex > r26v) {
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
}}
#pragma pop
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

static inline void *Map_FindObjAt_80046424(void *arg0, s32 x, s32 y, u32 mask, s32 excl) {
    s32 i;
    for (i = *(s16 *)((u8 *)arg0 + 6) - 1; i >= 0; i--) {
        u8 *base = *(u8 **)((u8 *)arg0 + 0x14);
        u8 *entry = base + i * 0xB4;
        u32 flags = *(u32 *)((u8 *)*(void **)(entry + 0x10) + 0xBC);
        if (!(flags & excl)) {
            if (mask == 0 || mask == (mask & flags)) {
                u8 ok;
                if (x >= (s8)*(u8 *)(entry + 4) && x <= (s8)*(u8 *)(entry + 6) &&
                    y >= (s8)*(u8 *)(entry + 5) && y <= (s8)*(u8 *)(entry + 7)) {
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
    return NULL;
}

static inline s32 fn_80046424_step(void *arg0, void *arg1, void **arg2, s32 arg3) {
    void *Map_FindObjAt(void *, s32, s32, u32, s32);
    void *fn_80049E1C(void *);
    s32 fn_80046424(void *, void *, void **, s32);
    u32 mask;
    s32 i;

    if (arg1 == NULL) {
        return arg3;
    }
    for (i = 0; i < arg3; i++) {
        if (arg2[i] == arg1) {
            return arg3;
        }
    }
    arg2[arg3++] = arg1;
    mask = *(u32 *)((u8 *)fn_80049E1C(arg1) + 0xBC) | 0x200000;
    arg3 = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)arg1 + 4) - 1, ((s8)*(u8 *)((u8 *)arg1 + 5) + (s8)*(u8 *)((u8 *)arg1 + 7)) / 2, mask, 0x10), arg2, arg3);
    arg3 = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)arg1 + 6) + 1, ((s8)*(u8 *)((u8 *)arg1 + 5) + (s8)*(u8 *)((u8 *)arg1 + 7)) / 2, mask, 0x10), arg2, arg3);
    arg3 = fn_80046424(arg0, Map_FindObjAt(arg0, ((s8)*(u8 *)((u8 *)arg1 + 4) + (s8)*(u8 *)((u8 *)arg1 + 6)) / 2, (s8)*(u8 *)((u8 *)arg1 + 5) - 1, mask, 0x10), arg2, arg3);
    arg3 = fn_80046424(arg0, Map_FindObjAt(arg0, ((s8)*(u8 *)((u8 *)arg1 + 4) + (s8)*(u8 *)((u8 *)arg1 + 6)) / 2, (s8)*(u8 *)((u8 *)arg1 + 7) + 1, mask, 0x10), arg2, arg3);
    return arg3;
}

s32 fn_80046424(void *arg0, void *arg1, void **arg2, s32 arg3) {
    u32 mask;
    s32 i;

    if (arg1 == NULL) {
        return arg3;
    }
    for (i = 0; i < arg3; i++) {
        if (arg2[i] == arg1) {
            return arg3;
        }
    }
    arg2[arg3++] = arg1;
    mask = *(u32 *)((u8 *)*(void **)((u8 *)arg1 + 0x10) + 0xBC) | 0x200000;
    arg3 = fn_80046424_step(arg0, Map_FindObjAt_80046424(arg0, (s8)*(u8 *)((u8 *)arg1 + 4) - 1, ((s8)*(u8 *)((u8 *)arg1 + 5) + (s8)*(u8 *)((u8 *)arg1 + 7)) / 2, mask, 0x10), arg2, arg3);
    arg3 = fn_80046424_step(arg0, Map_FindObjAt_80046424(arg0, (s8)*(u8 *)((u8 *)arg1 + 6) + 1, ((s8)*(u8 *)((u8 *)arg1 + 5) + (s8)*(u8 *)((u8 *)arg1 + 7)) / 2, mask, 0x10), arg2, arg3);
    arg3 = fn_80046424_step(arg0, Map_FindObjAt_80046424(arg0, ((s8)*(u8 *)((u8 *)arg1 + 4) + (s8)*(u8 *)((u8 *)arg1 + 6)) / 2, (s8)*(u8 *)((u8 *)arg1 + 5) - 1, mask, 0x10), arg2, arg3);
    arg3 = fn_80046424_step(arg0, Map_FindObjAt_80046424(arg0, ((s8)*(u8 *)((u8 *)arg1 + 4) + (s8)*(u8 *)((u8 *)arg1 + 6)) / 2, (s8)*(u8 *)((u8 *)arg1 + 7) + 1, mask, 0x10), arg2, arg3);
    return arg3;
}

void *fn_80046EB8(void *arg0,void *arg1) { u8 *base; s32 i; if(arg1==0)return 0; for(i=*(s16*)((u8*)arg0+6)-1;i>=0;i--) {base=*(u8**)((u8*)arg0+0x14); if(arg1==*(void**)(base+i*0xB4+0x10))return base+i*0xB4;} return 0; }

static inline u8 MapObj_Contains(u8 *entry, s32 x, s32 y) {
    if (x >= *(s8 *)(entry + 4) &&
        x <= *(s8 *)(entry + 6) &&
        y >= *(s8 *)(entry + 5) &&
        y <= *(s8 *)(entry + 7)) {
        return 1;
    }
    return 0;
}

static inline void *Map_FindObjAt_Inline(void *arg0, s32 n, s32 x, s32 y, u32 arg3, u32 arg4) {
    typedef struct { u8 pad[0xB4]; } MapObjEntry;
    u8 *entry;
    MapObjEntry *base;
    s32 i;
    for (i = n; i >= 0; i--) {
        base = *(MapObjEntry **)((u8 *)arg0 + 0x14);
        entry = (u8 *)&base[i];
        {
            u32 flags = *(u32 *)((u8 *)*(void **)(entry + 0x10) + 0xBC);
            if (!(flags & arg4)) {
                if (arg3 == 0 || (arg3 & flags) == arg3) {
                    if (MapObj_Contains(entry, x, y)) {
                        return &base[i];
                    }
                }
            }
        }
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
void *Map_FindObjNear(void *arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4) {
    void *found;
    s32 n;
    s32 direction;
    s32 dx;
    s32 dy;
    s32 dir;

    n = *(s16 *)((u8 *)arg0 + 6) - 1;
    found = Map_FindObjAt_Inline(arg0, n, arg1, arg2, arg3, arg4);
    if (found != 0) {
        return found;
    }

    for (direction = 0; direction < 4; direction++) {
        switch (direction) {
        case 0: dir = 1; break;
        case 1: dir = 2; break;
        case 2: dir = 4; break;
        case 3: dir = 8; break;
        default: dir = 0x10; break;
        }
        dir = (u8)dir;
        switch (dir) {
        case 1: dx = -1; break;
        case 2: dx = 1; break;
        default: dx = 0; break;
        }
        switch (dir) {
        case 4: dy = 1; break;
        case 8: dy = -1; break;
        default: dy = 0; break;
        }

        found = Map_FindObjAt_Inline(arg0, n, arg1 + dx, arg2 + dy, arg3, arg4);
        if (found != 0) {
            return found;
        }
    }

    return 0;
}
#pragma pop
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
    extern const f32 lbl_80368F64;
    extern const f32 lbl_80368F68;
    struct Work { f32 quat[4]; f32 corners[8][3]; } wk;
    u8 bufF8[0x30], bufC8[0x30], buf98[0x30], buf68[0x30], buf38[0x30], buf8[0x30];
    f32 *c1 = &wk.corners[1][0]; f32 *c2 = &wk.corners[2][0];
    f32 *c3 = &wk.corners[3][0]; f32 *c4 = &wk.corners[4][0];
    f32 *c5 = &wk.corners[5][0]; f32 *c6 = &wk.corners[6][0];
    f32 *c7 = &wk.corners[7][0];
    u8 *sub;
    u8 *entry = M2C_FIELD(arg0, u8 **, 0x14) + arg1 * 0xB4;
    s32 i; u8 *e; u32 mask = 0x10040;
    f32 minX, minY, maxX, maxY, x, y, *p; s32 j; u8 hit;

    for (i = arg1; i < arg2; i++, entry += 0xB4) {
        e = entry + 0x14;
        fn_80060638(e);
        sub = M2C_FIELD(entry, u8 **, 0x10);
        M2C_FIELD(entry, u8 *, 2) &= 0x7F;
        if (M2C_FIELD(sub, u32 *, 0xBC) & mask) continue;
        fn_8006049C(e);
        switch (M2C_FIELD(e, u32 *, 0xC)) {
            case 0: break;
            case 1:
                PSMTXRotRad(buf68, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                PSMTXRotRad(buf98, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                PSMTXRotRad(bufC8, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24)); break;
            case 2:
                PSMTXRotRad(buf68, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                PSMTXRotRad(buf98, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                PSMTXRotRad(bufC8, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C)); break;
            case 3:
                PSMTXRotRad(buf68, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                PSMTXRotRad(buf98, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                PSMTXRotRad(bufC8, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20)); break;
            case 4:
                PSMTXRotRad(buf68, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                PSMTXRotRad(buf98, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                PSMTXRotRad(bufC8, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20)); break;
            case 5:
                PSMTXRotRad(buf68, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                PSMTXRotRad(buf98, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                PSMTXRotRad(bufC8, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24)); break;
            case 6:
                PSMTXRotRad(buf68, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                PSMTXRotRad(buf98, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                PSMTXRotRad(bufC8, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C)); break;
            case 8:
                PSMTXScale(buf8, M2C_FIELD(e, f32 *, 0x28), M2C_FIELD(e, f32 *, 0x2C), M2C_FIELD(e, f32 *, 0x30));
                PSMTXTrans(buf38, M2C_FIELD(e, f32 *, 0x10), M2C_FIELD(e, f32 *, 0x14), M2C_FIELD(e, f32 *, 0x18));
                QUATMtx(e + 0x10, buf68);
                PSMTXConcat(buf68, buf8, bufF8);
                PSMTXConcat(buf68, bufF8, bufF8);
                PSMTXConcat(buf38, bufF8, bufF8); goto checks;
            case 7: PSMTXCopy(e + 0x10, bufF8); goto checks;
            default: Game_Assert(lbl_8026A660 + 0x2F7, 0xB8, lbl_8026A660 + 0x2FF); break;
        }
        PSMTXScale(buf8, M2C_FIELD(e, f32 *, 0x28), M2C_FIELD(e, f32 *, 0x2C), M2C_FIELD(e, f32 *, 0x30));
        PSMTXTrans(buf38, M2C_FIELD(e, f32 *, 0x10), M2C_FIELD(e, f32 *, 0x14), M2C_FIELD(e, f32 *, 0x18));
        PSMTXConcat(buf68, buf8, bufF8);
        PSMTXConcat(buf98, bufF8, bufF8);
        PSMTXConcat(bufC8, bufF8, bufF8);
        PSMTXConcat(buf38, bufF8, bufF8);
checks:
        wk.quat[0] = lbl_80368EE4; wk.quat[1] = lbl_80368EE4;
        wk.quat[2] = lbl_80368EE4; wk.quat[3] = lbl_80368F10;
        fn_80202C18(fn_80067FD0(), bufF8, bufF8);
        wk.corners[0][0] = M2C_FIELD(sub, f32 *, 0xA4);
        wk.corners[0][1] = M2C_FIELD(sub, f32 *, 0xA8);
        wk.corners[0][2] = M2C_FIELD(sub, f32 *, 0xAC);
        fn_8020310C(bufF8, &wk.corners[0][0], &wk.corners[0][0]);
        if (wk.corners[0][0]*wk.corners[0][0] < lbl_80368F5C && wk.corners[0][1]*wk.corners[0][1] < lbl_80368F60 &&
            wk.corners[0][2] > lbl_80368F2C && wk.corners[0][2] < lbl_80368EE4) hit = 0; else hit = 1;
        if (!hit) continue;
        c1[0] = M2C_FIELD(sub, f32 *, 0xB0); c1[1] = M2C_FIELD(sub, f32 *, 0xA8); c1[2] = M2C_FIELD(sub, f32 *, 0xAC);
        fn_8020310C(bufF8, c1, c1);
        if (c1[0]*c1[0] < lbl_80368F5C && c1[1]*c1[1] < lbl_80368F60 && c1[2] > lbl_80368F2C && c1[2] < lbl_80368EE4) hit = 0; else hit = 1;
        if (!hit) continue;
        c2[0] = M2C_FIELD(sub, f32 *, 0xB0); c2[1] = M2C_FIELD(sub, f32 *, 0xB4); c2[2] = M2C_FIELD(sub, f32 *, 0xAC);
        fn_8020310C(bufF8, c2, c2);
        if (c2[0]*c2[0] < lbl_80368F5C && c2[1]*c2[1] < lbl_80368F60 && c2[2] > lbl_80368F2C && c2[2] < lbl_80368EE4) hit = 0; else hit = 1;
        if (!hit) continue;
        c3[0] = M2C_FIELD(sub, f32 *, 0xA4); c3[1] = M2C_FIELD(sub, f32 *, 0xB4); c3[2] = M2C_FIELD(sub, f32 *, 0xAC);
        fn_8020310C(bufF8, c3, c3);
        if (c3[0]*c3[0] < lbl_80368F5C && c3[1]*c3[1] < lbl_80368F60 && c3[2] > lbl_80368F2C && c3[2] < lbl_80368EE4) hit = 0; else hit = 1;
        if (!hit) continue;
        c4[0] = M2C_FIELD(sub, f32 *, 0xA4); c4[1] = M2C_FIELD(sub, f32 *, 0xA8); c4[2] = M2C_FIELD(sub, f32 *, 0xB8);
        fn_8020310C(bufF8, c4, c4);
        if (c4[0]*c4[0] < lbl_80368F5C && c4[1]*c4[1] < lbl_80368F60 && c4[2] > lbl_80368F2C && c4[2] < lbl_80368EE4) hit = 0; else hit = 1;
        if (!hit) continue;
        c5[0] = M2C_FIELD(sub, f32 *, 0xB0); c5[1] = M2C_FIELD(sub, f32 *, 0xA8); c5[2] = M2C_FIELD(sub, f32 *, 0xB8);
        fn_8020310C(bufF8, c5, c5);
        if (c5[0]*c5[0] < lbl_80368F5C && c5[1]*c5[1] < lbl_80368F60 && c5[2] > lbl_80368F2C && c5[2] < lbl_80368EE4) hit = 0; else hit = 1;
        if (!hit) continue;
        c6[0] = M2C_FIELD(sub, f32 *, 0xB0); c6[1] = M2C_FIELD(sub, f32 *, 0xB4); c6[2] = M2C_FIELD(sub, f32 *, 0xB8);
        fn_8020310C(bufF8, c6, c6);
        if (c6[0]*c6[0] < lbl_80368F5C && c6[1]*c6[1] < lbl_80368F60 && c6[2] > lbl_80368F2C && c6[2] < lbl_80368EE4) hit = 0; else hit = 1;
        if (!hit) continue;
        c7[0] = M2C_FIELD(sub, f32 *, 0xA4); c7[1] = M2C_FIELD(sub, f32 *, 0xB4); c7[2] = M2C_FIELD(sub, f32 *, 0xB8);
        fn_8020310C(bufF8, c7, c7);
        if (c7[0]*c7[0] < lbl_80368F5C && c7[1]*c7[1] < lbl_80368F60 && c7[2] > lbl_80368F2C && c7[2] < lbl_80368EE4) hit = 0; else hit = 1;
        if (!hit) continue;
        if (!(M2C_FIELD(sub, u32 *, 0xBC) & 8)) goto mark;
        minX = lbl_80368F64; minY = minX; maxX = lbl_80368F68; maxY = maxX;
        p = &wk.corners[0][0];
        for (j = 0; j < 8; p += 3, j++) {
            x = p[0]; y = p[1];
            if (p[2] > lbl_80368EE4) { x *= lbl_80368F2C; y *= lbl_80368F2C; }
            if (minX > x) minX = x; if (minY > y) minY = y;
            if (maxX < x) maxX = x; if (maxY < y) maxY = y;
        }
        if (!(minX < lbl_80368F2C)) goto corners;
        if (!(maxX > lbl_80368F10)) goto corners;
        if (!(minY < lbl_80368F2C)) goto corners;
        if (maxY > lbl_80368F10) continue;
corners:
        if (minX*minX < lbl_80368F10 && minY*minY < lbl_80368F10) continue;
        if (maxX*maxX < lbl_80368F10 && minY*minY < lbl_80368F10) continue;
        if (maxX*maxX < lbl_80368F10 && maxY*maxY < lbl_80368F10) continue;
        if (minX*minX < lbl_80368F10 && maxY*maxY < lbl_80368F10) continue;
        if (minX < lbl_80368F2C && maxX > lbl_80368F10 && (minY*minY < lbl_80368F10 || maxY*maxY < lbl_80368F10)) continue;
        if (!(minY < lbl_80368F2C)) goto mark;
        if (!(maxY > lbl_80368F10)) goto mark;
        if (minX*minX < lbl_80368F10) continue;
        if (maxX*maxX < lbl_80368F10) continue;
mark:
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

#pragma push
#pragma opt_lifetimes off
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
#pragma pop

#pragma opt_peephole reset
#pragma opt_loop_invariants reset
#pragma use_lmw_stmw reset
void fn_80048A3C(u8 arg0, u8 arg1, u8 arg2, u8 *arg3) {
    extern volatile u8 lbl_8036728C;
    extern volatile u8 lbl_8036728D;
    extern volatile u8 lbl_8036728E;
    extern volatile u8 lbl_80367290;
    volatile u8 *p;
    u8 d, c, b, a;

    a = arg3[0];
    b = arg3[1];
    c = arg3[2];
    d = arg3[3];
    lbl_8036728C = arg0;
    lbl_8036728D = arg1;
    lbl_8036728E = arg2;
    p = &lbl_80367290;
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
    extern u8 lbl_80367290;
    extern u8 lbl_80367294;
    extern u8 lbl_80367295;
    extern u8 lbl_80367298;
    extern u8 lbl_8036729C;
    extern const f32 lbl_80368F6C;

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

    *(u8 *)&lbl_80367290 = Stream_ReadU8(stream);
    *((u8 *)&lbl_80367290 + 1) = Stream_ReadU8(stream);
    *((u8 *)&lbl_80367290 + 2) = Stream_ReadU8(stream);

    lbl_80367294 = Stream_ReadU8(stream);
    lbl_80367295 = Stream_ReadU8(stream);

    *(u8 *)&lbl_80367298 = Stream_ReadU8(stream);
    *((u8 *)&lbl_80367298 + 1) = Stream_ReadU8(stream);
    *((u8 *)&lbl_80367298 + 2) = Stream_ReadU8(stream);

    *(u8 *)&lbl_8036729C = Stream_ReadU8(stream);
    *((u8 *)&lbl_8036729C + 1) = Stream_ReadU8(stream);
    *((u8 *)&lbl_8036729C + 2) = Stream_ReadU8(stream);

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

    *((u8 *)&lbl_80367298 + 3) = 0xFF;
    *((u8 *)&lbl_8036729C + 3) = 0xFF;
    *((u8 *)&lbl_80367290 + 3) = 0xFF;
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
    struct Color { u8 r, g, b, a; } color, copy;
    struct Proc { u8 pad[0x30]; u8 *model; s32 frame, duration; u8 start[4], end[4]; };
    struct Proc *proc = (struct Proc *)arg0;
    void *model;
    s32 t;

    ++proc->frame;
    t = (s32)fn_80059EB8(proc->duration, proc->frame, 0.0f, 256.0f);
    color.r = Math_Lerp((f32)proc->start[0], (f32)proc->end[0], 256.0f, (f32)t);
    color.g = Math_Lerp((f32)proc->start[1], (f32)proc->end[1], 256.0f, (f32)t);
    color.b = Math_Lerp((f32)proc->start[2], (f32)proc->end[2], 256.0f, (f32)t);
    color.a = Math_Lerp((f32)proc->start[3], (f32)proc->end[3], 256.0f, (f32)t);
    model = proc->model + 0x14;
    copy = color;
    Model_SetColor(model, copy.r, copy.g, copy.b);
    Model_SetAlpha(model, copy.a);
    if (proc->duration == proc->frame) {
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
    s32 owner;
    u8 c1;
    u8 c0;
    u8 c3;
    u8 c2;

    self = arg0;
    color = arg2;
    owner = (s32)arg3;

    if (owner) {
        goto create;
    }

    rgba = *(u32 *)color;
    model = self + 0x14;
    Model_SetColor(model, ((u8 *)&rgba)[0], ((u8 *)&rgba)[1], ((u8 *)&rgba)[2]);
    Model_SetAlpha(model, ((u8 *)&rgba)[3]);
    return;

create:
    if (arg1) {
        process = Process_CreateChild(lbl_80285710, arg1);
    } else {
        process = Process_Create(lbl_80285710, 3);
    }

    c0 = color[0];
    c1 = color[1];
    process[0x40] = c0;
    c2 = color[2];
    process[0x41] = c1;
    c3 = color[3];
    process[0x42] = c2;
    process[0x43] = c3;

    *(void **)(process + 0x38) = (void *)owner;
    *(void **)(process + 0x30) = self;
}

void fn_80049238(void *arg0) {
    f32 Math_Lerp(f32, f32, f32, f32);
    void Model_SetColor(void *, u8, u8, u8);
    void Model_SetAlpha(void *, u8);
    void Process_ClearFunc(void *);
    struct Color { u8 r, g, b, a; } color, copy;
    struct Proc { u8 pad[0x30]; u8 *model; s32 frame, duration; u8 start[4], end[4]; };
    struct Proc *proc = (struct Proc *)arg0;
    void *model;
    ++proc->frame;
    color.r = Math_Lerp((f32)proc->start[0], (f32)proc->end[0], (f32)proc->duration, (f32)proc->frame);
    color.g = Math_Lerp((f32)proc->start[1], (f32)proc->end[1], (f32)proc->duration, (f32)proc->frame);
    color.b = Math_Lerp((f32)proc->start[2], (f32)proc->end[2], (f32)proc->duration, (f32)proc->frame);
    color.a = Math_Lerp((f32)proc->start[3], (f32)proc->end[3], (f32)proc->duration, (f32)proc->frame);
    model = proc->model + 0x14;
    copy = color;
    Model_SetColor(model, copy.r, copy.g, copy.b);
    Model_SetAlpha(model, copy.a);
    if (proc->duration == proc->frame) {
        Process_ClearFunc(arg0);
    }
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

#pragma push
#pragma opt_strength_reduction off
void fn_80049594(void *self)
{
  f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
  void PSMTXTrans(void *, f32, f32, f32);
  void PSMTXRotRad(void *, s32, f32);
  void PSMTXConcat(void *, void *, void *);
  void PSMTXScale(void *, f32, f32, f32);
  void Process_ClearFunc(void *);
  extern void *gMap;
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
  u8 *ent;
  u8 *map;
  s32 a;
  s32 b;
  f32 f31v;
  f32 f30v;
  f32 f29v;
  f32 f28v;
  f32 t30;
  f32 scale;
  f32 temp_f0;
  s32 ival;
  *((s32 *) (((u8 *) self) + 0x40)) = (*((s32 *) (((u8 *) self) + 0x40))) + 1;
  ival = (s32) Math_EaseOutPow(2, *((f32 *) (((u8 *) self) + 0x44)), *((f32 *) (((u8 *) self) + 0x48)), (f32) (*((s32 *) (((u8 *) self) + 0x3C))), (f32) (*((s32 *) (((u8 *) self) + 0x40))));
  *((f32 *) ((*((u8 **) (((u8 *) self) + 0x30))) + 8)) = (f32) ival;
  ent = *((u8 **) (((u8 *) self) + 0x30));
  map = (u8 *) gMap;
  f28v = ((f32) ((s8) ent[0])) + 0.5f;
  f29v = -((*((f32 *) (ent + 0xC))) + 0.5f);
  t30 = (f32) ((s8) ent[1]);
  f31v = (*((f32 *) (ent + 8))) + 0.5f;
  f30v = t30 + 0.5f;
  if ((*((u8 *) (map + 0x68))) == 1)
  {
    a = *(s16 *)map / 2;
    b = *(s16 *)(map + 2) / 2;
    f28v -= (f32)a;
    f30v -= (f32)b;
  }
  PSMTXTrans(sp98, lbl_80368EE8, lbl_80368EE4, lbl_80368EE8);
  PSMTXRotRad(sp68, 0x59, lbl_80368EEC * f31v);
  PSMTXConcat(sp68, sp98, sp68);
  PSMTXTrans(sp98, lbl_80368EF0, lbl_80368EE4, lbl_80368EF0);
  PSMTXConcat(sp98, sp68, sp8);
  scale = *((f32 *) (map + 0x6C));
  PSMTXScale(sp38, scale, scale, scale);
  PSMTXConcat(sp38, sp8, sp8);
  temp_f0 = *((f32 *) (map + 0x6C));
  PSMTXTrans(sp98, lbl_80368EF4 * (f28v * temp_f0), lbl_80368EF4 * (f29v * temp_f0), lbl_80368EF4 * (f30v * temp_f0));
  PSMTXConcat(sp98, sp8, sp8);
  PSMTXConcat(map + 0x70, sp8, ent + 0x24);
  if ((*((s32 *) (((u8 *) self) + 0x3C))) == (*((s32 *) (((u8 *) self) + 0x40))))
  {
    Process_ClearFunc(self);
  }
}
#pragma pop
void fn_8004982C(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x48);
}

void fn_8004983C(void *arg0) {
    extern const f32 lbl_80368F74;
    extern f32 lbl_80368F78;
    f32 temp_f2;
    f32 temp_f3;

    *(s32 *)((u8 *)arg0 + 0x40) = 0;
    *(f32 *)((u8 *)arg0 + 0x44) = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 8);
    *(f32 *)((u8 *)arg0 + 0x48) = *(f32 *)((u8 *)arg0 + 0x38);
    temp_f3 = *(f32 *)((u8 *)arg0 + 0x44);
    temp_f2 = *(f32 *)((u8 *)arg0 + 0x48);
    if ((f32)__fabs((f64)(temp_f3 - temp_f2)) > lbl_80368F74) {
        if (temp_f3 < temp_f2) {
            *(f32 *)((u8 *)arg0 + 0x44) = temp_f3 + lbl_80368F78;
            return;
        }
        if (temp_f3 > temp_f2) {
            *(f32 *)((u8 *)arg0 + 0x48) = temp_f2 + lbl_80368F78;
        }
    }
}

#pragma push
#pragma opt_propagation off
void fn_800498A4(void *arg0, void *arg1, u8 arg2)
{
    extern u8 lbl_802856C8[];
    extern f32 lbl_80368EE4;
    extern f32 lbl_80368F10;
    extern f32 lbl_80368F2C;

    void fn_8005FEE8(void *, f32);
    void *Process_CreateEx(void *);

    u8 *obj;
    s32 mode;
    u8 *node;
    u8 *process;
    u32 flags;
    u8 enabled;

    obj = (u8 *)arg0;
    flags = *(u32 *)(*(u8 **)(obj + 0x10) + 0xBC);

    if (flags & 0x400) {
        enabled = 0;
    } else if (flags & 0x200) {
        enabled = 1;
    } else {
        enabled = 0;
    }

    if (!enabled) {
        return;
    }

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
    default:
        process = (u8 *)Process_CreateEx(lbl_802856C8);
        *(void **)(process + 0x34) = node;
        *(void **)(process + 0x30) = obj;
        *(s32 *)(process + 0x44) = mode;
        process[0x48] = 0;
        *(f32 *)(process + 0x38) = (f32)((s8)obj[4] + (s8)obj[6]) / 2.0f;
        *(f32 *)(process + 0x3C) = (f32)((s8)obj[5] + (s8)obj[7]) / 2.0f;
        *(f32 *)(process + 0x40) = *(f32 *)(obj + 0xC);
        switch (mode) {
        case 0:
            fn_8005FEE8(obj + 0x14, lbl_80368EE4);
            *(f32 *)(node + 0x5C) = lbl_80368F10;
            break;
        case 1:
            fn_8005FEE8(obj + 0x14, lbl_80368F2C);
            *(f32 *)(node + 0x5C) = lbl_80368F2C;
            break;
        }
        break;
    }
}
#pragma pop
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
void MapObj_FadeIn(void *arg0,u8 arg1) { void fn_8005FEE8(void *,f32); void fn_80044450(void *,s32); void fn_80016180(void); extern void *gMap; u8 *ptr=arg0; ptr[2]&=~2; fn_8005FEE8(ptr+0x14,0.0f); if(arg1) {fn_80044450(gMap,1); fn_80016180();} }
#pragma global_optimizer reset
void MapObj_FadeOut(void *arg0, u8 arg1) {
    void fn_8005FEE8(void *, f32);
    void fn_80044450(void *, s32);
    void fn_80016180(void);
    extern f32 lbl_80368F2C;
    extern void *gMap;
    u8 temp;

    temp = *(u8 *)((u8 *)arg0 + 2);
    temp |= 2;
    *(u8 *)((u8 *)arg0 + 2) = temp;

    fn_8005FEE8((u8 *)arg0 + 0x14, -1.0f);

    if (arg1 != 0) {
        fn_80044450(gMap, 1);
        fn_80016180();
    }
}

void MapObj_Show(void *arg0, u8 arg1) {
    void Model_SetAlpha(void *, s32, void *);
    void fn_80044450(void *, s32);
    void fn_80016180(void);
    extern void *gMap;
    u8 temp;

    temp = *(u8 *)((u8 *)arg0 + 2);
    temp &= 0xFC;
    *(u8 *)((u8 *)arg0 + 2) = temp;

    Model_SetAlpha((u8 *)arg0 + 0x14, 0xFF, arg0);

    if (arg1 != 0) {
        fn_80044450(gMap, 1);
        fn_80016180();
    }
}

void MapObj_Hide(void *arg0, u8 arg1)
{
    void Model_SetAlpha(void *, s32, void *);
    void fn_80044450(void *, s32);
    void fn_80016180(void);
    extern void *gMap;
    u8 temp;

    temp = *(u8 *)((u8 *)arg0 + 2);
    temp |= 3;
    *(u8 *)((u8 *)arg0 + 2) = temp;

    Model_SetAlpha((u8 *)arg0 + 0x14, 0, arg0);

    if (arg1 != 0) {
        fn_80044450(gMap, 1);
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
    return !(*(u8 *)((u8 *)arg0 + 2) & 3);
}

s32 MapObj_IsHidden(u8 *arg0) {
    unsigned int flag = arg0[2] & 3;
    return (unsigned int)(-flag | flag) >> 31;
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

#pragma push
#pragma global_optimizer on
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
    extern const f32 lbl_80368F8C;
    extern u8 gBattleMap[];
    extern u8 lbl_80285828[];

    f32 sp8[12];
    s8 y;
    s8 x;
    f32 fy;

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

        for (y = *(s32 *)(gBattleMap + 4) - 1; y >= 0; y--) {
            x = *(s32 *)gBattleMap - 1;
            fy = lbl_80368F8C + (f32)y;
            for (; x >= 0; x--) {
                if ((s8)gBattleMap[y * 0x40 + x + 0xE18E] == 0) {
                    if (*(s16 *)(gBattleMap + ((y * 0x40 + x) << 1) + 0x610E) >= 0) {
                        f32 y1, x1, y0, x0, margin, z;
                        margin = *(f32 *)((u8 *)arg0 + 0x34);
                        y0 = fy - margin;
                        x0 = (f32)x;
                        x1 = x0 + margin;
                        y1 = (f32)(y + 1);
                        GXBegin(0x98, 0, 4);
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 0);
                        *(f32 *)0xCC008000 = x0;
                        *(f32 *)0xCC008000 = y0;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = lbl_80285828[0x10];
                        *(u8 *)0xCC008000 = lbl_80285828[0x11];
                        *(u8 *)0xCC008000 = lbl_80285828[0x12];
                        *(u8 *)0xCC008000 = lbl_80285828[0x13];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 1);
                        *(f32 *)0xCC008000 = x1;
                        *(f32 *)0xCC008000 = y0;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = lbl_80285828[0x14];
                        *(u8 *)0xCC008000 = lbl_80285828[0x15];
                        *(u8 *)0xCC008000 = lbl_80285828[0x16];
                        *(u8 *)0xCC008000 = lbl_80285828[0x17];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 2);
                        *(f32 *)0xCC008000 = x0;
                        *(f32 *)0xCC008000 = y1;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = lbl_80285828[0x18];
                        *(u8 *)0xCC008000 = lbl_80285828[0x19];
                        *(u8 *)0xCC008000 = lbl_80285828[0x1A];
                        *(u8 *)0xCC008000 = lbl_80285828[0x1B];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 3);
                        *(f32 *)0xCC008000 = x1;
                        *(f32 *)0xCC008000 = y1;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = lbl_80285828[0x1C];
                        *(u8 *)0xCC008000 = lbl_80285828[0x1D];
                        *(u8 *)0xCC008000 = lbl_80285828[0x1E];
                        *(u8 *)0xCC008000 = lbl_80285828[0x1F];
                    } else if (*(u16 *)(gBattleMap + ((y * 0x40 + x) << 1) + 0xC18E) != 0) {
                        f32 x0, y0, x1, y1, margin, z;
                        margin = *(f32 *)((u8 *)arg0 + 0x34);
                        y0 = fy - margin;
                        x0 = (f32)x;
                        x1 = x0 + margin;
                        y1 = (f32)(y + 1);
                        GXBegin(0x98, 0, 4);
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 0);
                        *(f32 *)0xCC008000 = x0;
                        *(f32 *)0xCC008000 = y0;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = lbl_80285828[0x20];
                        *(u8 *)0xCC008000 = lbl_80285828[0x21];
                        *(u8 *)0xCC008000 = lbl_80285828[0x22];
                        *(u8 *)0xCC008000 = lbl_80285828[0x23];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 1);
                        *(f32 *)0xCC008000 = x1;
                        *(f32 *)0xCC008000 = y0;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = lbl_80285828[0x24];
                        *(u8 *)0xCC008000 = lbl_80285828[0x25];
                        *(u8 *)0xCC008000 = lbl_80285828[0x26];
                        *(u8 *)0xCC008000 = lbl_80285828[0x27];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 2);
                        *(f32 *)0xCC008000 = x0;
                        *(f32 *)0xCC008000 = y1;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = lbl_80285828[0x28];
                        *(u8 *)0xCC008000 = lbl_80285828[0x29];
                        *(u8 *)0xCC008000 = lbl_80285828[0x2A];
                        *(u8 *)0xCC008000 = lbl_80285828[0x2B];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 3);
                        *(f32 *)0xCC008000 = x1;
                        *(f32 *)0xCC008000 = y1;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = lbl_80285828[0x2C];
                        *(u8 *)0xCC008000 = lbl_80285828[0x2D];
                        *(u8 *)0xCC008000 = lbl_80285828[0x2E];
                        *(u8 *)0xCC008000 = lbl_80285828[0x2F];
                    }
                }
            }
        }
        fn_80066D00(-1);
    }
}
#pragma pop

#pragma global_optimizer on
void fn_8004A864(s32 x,s32 y,u8 *color) {
void GXBegin(s32,s32,s32);
f32 fn_800233D0(void *,s8,s8,s32);
extern u8 gBattleMap[];
extern f64 lbl_80368F90;
f32 z;
union { f64 d; u32 w[2]; } u;
GXBegin(0x98,0,4);
{
u8 a,b,g,r;
z=fn_800233D0(gBattleMap,(s8)x,(s8)y,0);
r=color[0];g=color[1];b=color[2];a=color[3];
u.w[0]=0x43300000u; u.w[1]=(u32)x^0x8000u;
*(f32 *)0xCC008000=(f32)(u.d-lbl_80368F90);
*(f32 *)0xCC008000=(f32)(y);
*(f32 *)0xCC008000=z;
*(u8 *)0xCC008000=r;
*(u8 *)0xCC008000=g;
*(u8 *)0xCC008000=b;
*(u8 *)0xCC008000=a;
}
{
u8 a,b,g,r;
z=fn_800233D0(gBattleMap,(s8)x,(s8)y,1);
r=color[0];g=color[1];b=color[2];a=color[3];
*(f32 *)0xCC008000=(f32)(x+1);
*(f32 *)0xCC008000=(f32)(y);
*(f32 *)0xCC008000=z;
*(u8 *)0xCC008000=r;
*(u8 *)0xCC008000=g;
*(u8 *)0xCC008000=b;
*(u8 *)0xCC008000=a;
}
{
u8 a,b,g,r;
z=fn_800233D0(gBattleMap,(s8)x,(s8)y,2);
r=color[0];g=color[1];b=color[2];a=color[3];
*(f32 *)0xCC008000=(f32)(x);
*(f32 *)0xCC008000=(f32)(y+1);
*(f32 *)0xCC008000=z;
*(u8 *)0xCC008000=r;
*(u8 *)0xCC008000=g;
*(u8 *)0xCC008000=b;
*(u8 *)0xCC008000=a;
}
{
u8 a,b,g,r;
z=fn_800233D0(gBattleMap,(s8)x,(s8)y,3);
r=color[0];g=color[1];b=color[2];a=color[3];
*(f32 *)0xCC008000=(f32)(x+1);
*(f32 *)0xCC008000=(f32)(y+1);
*(f32 *)0xCC008000=z;
*(u8 *)0xCC008000=r;
*(u8 *)0xCC008000=g;
*(u8 *)0xCC008000=b;
*(u8 *)0xCC008000=a;
}
}
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

#pragma push
#pragma global_optimizer on
#pragma optimization_level 4
#pragma opt_propagation off
s32 fn_8004ABD4(void *arg0, u8 arg1) {
    s32 Item_GetMaxRange(void *);
    u64 *Item_GetFlagsPtr(void *);
    u8 range;
    u8 kind;

    if (arg0 != NULL) {
        if (arg1 == 0) {
            if (*(void **)arg0 != NULL) {
                range = (u8)Item_GetMaxRange(*(void **)arg0);
            } else {
                range = 0;
            }
            if (range > 1U) {
                if ((*Item_GetFlagsPtr(arg0) & 0x40ULL) == 0ULL) {
                    if (*(void **)arg0 != NULL) {
                        kind = *((u8 *)*(void **)arg0 + 0x12);
                    } else {
                        kind = 0xC;
                    }
                    switch (kind) {
                    case 1:
                        return 5;
                    case 2:
                        return 3;
                    }
                }
            }
        }
        if (*(void **)arg0 != NULL) {
            kind = *((u8 *)*(void **)arg0 + 0x12);
        } else {
            kind = 0xC;
        }
        switch (kind) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 2;
        case 3:
            return 6;
        case 8:
            return 0;
        }
    }
    return 0;
}
#pragma pop
#pragma global_optimizer off
void fn_8004AD20(void *arg0, f32 *arg1) {
    void *fn_80146B10(s32);
    void DebugPrint(void *, ...);
    void SeCue_PlayAt(void *, s32, f32, f32, f32);
    void Ui_PlaySeCue(void *, s32);
    extern u16 lbl_8026A9B0[40];
    extern f32 lbl_80368FA0;
    s32 i;
    void *cue;
    u16 *entry;
    f32 x, y, z;
    z = arg1[2]; y = arg1[1]; x = arg1[0];
    entry = (u16 *)arg0;
    for (i = 0; i < 4; i++, entry++) {
        u16 id = *(u16 *)((u8 *)entry + 0x7C);
        if (id == 0xFFFF) cue = 0;
        else if (id < 0x3E8) cue = 0;
        else cue = fn_80146B10(id);
        if (cue != 0) {
            DebugPrint((u8 *)lbl_8026A9B0 + 0x8A, cue);
            if (z > lbl_80368FA0) SeCue_PlayAt(cue, 0x64, x, y, z);
            else Ui_PlaySeCue(cue, 0x64);
        }
    }
}
void fn_8004AE28(void *arg0, f32 x, f32 y, f32 z) {
    void *fn_80146B10(s32);
    void DebugPrint(void *, ...);
    void SeCue_PlayAt(void *, s32, f32, f32, f32);
    void Ui_PlaySeCue(void *, s32);
    extern u16 lbl_8026A9B0[40];
    extern f32 lbl_80368FA0;
    void *cue;
    u16 *entry;
    s32 i;
    f32 fz, fy, fx;
    entry = (u16 *)arg0;
    fx = x; fy = y; fz = z;
    for (i = 0; i < 4; i++, entry++) {
        u16 id = *(u16 *)((u8 *)entry + 0x7C);
        if (id == 0xFFFF) cue = 0;
        else if (id < 0x3E8) cue = 0;
        else cue = fn_80146B10(id);
        if (cue != 0) {
            DebugPrint((u8 *)lbl_8026A9B0 + 0x8A, cue);
            if (fz > lbl_80368FA0) SeCue_PlayAt(cue, 0x64, fx, fy, fz);
            else Ui_PlaySeCue(cue, 0x64);
        }
    }
}
#pragma global_optimizer on
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
extern u16 lbl_8026A9B0[40]; extern s32 lbl_80285880[]; extern s32 lbl_802858C4[]; extern u16 lbl_802EFFC8[16];
if ((*(s32 *)((u8 *)arg0+0x10) & (1 << arg1)) == 0) {arg1=6; fn_800056A0(0);}
sprintf((u8 *)lbl_802EFFC8,(u8 *)lbl_8026A9B0+0x9C,(u8 *)lbl_8026A9B0+0xA8,*(s32 *)((u8 *)arg0+4),lbl_80285880[arg1],lbl_802858C4[*(u8 *)((u8 *)arg0+8)]);
return (char *)lbl_802EFFC8;
}

typedef struct StringValueByte { u8 pad0[0xC]; u8 value; } StringValueByte;
char *fn_8004B078(void *arg0, s32 arg1) {
      void sprintf(void *, void *, ...);
      extern u16 lbl_8026A9B0[40];
      extern u16 lbl_802EFFC8[16];
      u8 *p = (u8 *)arg0;

      sprintf((u8 *)lbl_802EFFC8, (u8 *)lbl_8026A9B0 + 0xAD, (u8 *)lbl_8026A9B0 + 0xA8,
              *(void **)(p + 4),
              (p + arg1)[0xC]);
      return (char *)lbl_802EFFC8;
  }
char *fn_8004B0C8(void *arg0) {
    void sprintf(char *, const char *, ...);
    extern u8 lbl_8026A9B0[];
    extern char lbl_802EFFC8[];

    sprintf(lbl_802EFFC8, (const char *)(lbl_8026A9B0 + 0xBC), (const char *)(lbl_8026A9B0 + 0xA8), *(s32 *)((u8 *)arg0 + 4));
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

#pragma push
#pragma optimization_level 4
#pragma optimization_level 3
void fn_8004B588(u8 *arg0)
{
    f32 fn_80059F64(f32, f32, f32, f32);
    f32 fn_8005A028(s32, f32, f32, f32, f32);
    void fn_8006ECCC(s32, void *, s32);
    void fn_80222C50(void *, s32);
    void fn_80202300(void *, s32, f32);
    void fn_802026E4(void *, void *, void *, void *);
    void fn_8020293C(void *, f32, f32, f32, f32, f32, f32, f32, f32);
    void fn_80202024(void *, void *, void *);
    void fn_80202540(void *, f32, f32, f32);
    void fn_80224E50(void *, s32, s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80051564(void *, s32, f32, f32);
    extern u8 lbl_8026AA98[];
    extern s32 lbl_803672B0;
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
    u8 sp4C[0x20];
    Vec sp40;
    Vec sp34;
    Vec sp28;
    Vec sp1C;
    Vec sp10;
    u32 spC;
    u32 sp8;
    f32 scale;
    s32 alpha;
    u8 *tbl;
    f32 angle;
    f32 x;
    f32 y;
    u8 param;

    tbl = lbl_8026AA98;
    scale = lbl_80368FC4;
    alpha = 0xFF;
    switch (arg0[0]) {
    case 0:
        param = arg0[1];
        alpha = 0xC0;
        if (param > 0x78) {
            alpha = (s32)fn_80059F64(lbl_80368FC8, lbl_80368FCC, lbl_80368FD0, (f32)(s32)(param - 0x78));
        }
        fn_8006ECCC(lbl_803672B0, sp4C, 3);
        break;
    case 1:
        param = arg0[1];
        alpha = (s32)fn_8005A028(2, lbl_80368FD4, lbl_80368FCC, lbl_80368FD0, (f32)param);
        scale = fn_8005A028(2, lbl_80368FBC, lbl_80368FC4, lbl_80368FD0, (f32)arg0[1]);
        fn_8006ECCC(lbl_803672B0, sp4C, 4);
        break;
    }
    fn_80222C50(sp4C, 0);
    angle = (f32)*(s16 *)(arg0 + 2);
    sp34 = *(Vec *)(tbl + 0x1C);
    sp40 = *(Vec *)(tbl + 0x28);
    sp34.x = *(f32 *)(arg0 + 4);
    sp34.y = *(f32 *)(arg0 + 8);
    sp40.y = *(f32 *)(arg0 + 8);
    spC = lbl_80368FB4;
    sp40.x = *(f32 *)(arg0 + 4);
    ((u8 *)&spC)[3] = (u8)alpha;
    sp10 = sp34;
    sp1C = sp40;
    sp28 = *(Vec *)(tbl + 0x34);
    if (lbl_80368FCC != angle) {
        fn_80202300(spCC, 0x5A, lbl_80368FD8 * angle);
        fn_802026E4(sp9C, &sp1C, &sp28, &sp10);
        fn_8020293C(sp6C, -scale, scale, -scale, scale, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
        fn_80202024(sp6C, sp9C, sp12C);
        fn_80202540(spFC, lbl_80368FDC, lbl_80368FDC, lbl_80368FCC);
        fn_80202024(spCC, spFC, spCC);
        fn_80202540(spFC, lbl_80368FC4, lbl_80368FC4, lbl_80368FCC);
        fn_80202024(spFC, spCC, spCC);
        fn_80202024(spCC, sp12C, sp12C);
    } else {
        fn_802026E4(sp9C, &sp1C, &sp28, &sp10);
        fn_8020293C(sp6C, -scale, scale, -scale, scale, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
        fn_80202024(sp6C, sp9C, sp12C);
    }
    fn_80224E50(sp12C, 0x1E, 0);
    fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
    sp8 = spC;
    fn_80051564(&sp8, 0, *(f32 *)(arg0 + 4), *(f32 *)(arg0 + 8));
}
#pragma pop
void fn_8004B8F8(int arg0, int arg1, float arg2, float arg3)
{
  extern void *lbl_803672CC;
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
    void fn_80067708(s32, s32, void *, s32);
    void fn_8004BAC4(void);
    extern void *lbl_803672CC;
    struct Node {
        struct Node *next;
        struct Node *prev;
        u8 kind;
        u8 timer;
    };
    struct Pool {
        u8 pad[8];
        struct Node **free;
        struct Node *head;
        struct Node *tail;
        s32 count;
    };
    struct Pool *pool;
    struct Node *node;
    struct Node *link;
    u8 keep;

    if (lbl_803672CC) {
        node = 0;
        goto next;
        do {
            node->timer++;
            switch (node->kind) {
            case 0:
                if (node->timer == 0xb4) {
                    keep = 0;
                    break;
                }
                goto alive;
            case 1:
                if (node->timer == 0x3c) {
                    keep = 0;
                    break;
                }
                goto alive;
            default:
            alive:
                keep = 1;
                break;
            }
            if (!keep) {
                pool = (struct Pool *)lbl_803672CC;
                if (node != 0) {
                    link = node->next;
                    if (link != 0) {
                        link->prev = node->prev;
                    }
                    link = node->prev;
                    if (link != 0) {
                        link->next = node->next;
                    }
                    if (node == pool->head) {
                        pool->head = node->next;
                    }
                    if (node == pool->tail) {
                        pool->tail = node->prev;
                    }
                    pool->free--;
                    pool->count--;
                    *pool->free = node;
                }
            }
        next:
            pool = (struct Pool *)lbl_803672CC;
            if (node == 0) {
                node = pool->head;
            } else {
                node = node->next;
            }
        } while (node != 0);
        fn_80067708(2, 2, fn_8004BAC4, 0);
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

void fn_8004BC48(void *arg0, void *stream) {
    u16 Stream_ReadU16(void *);
    u8 Stream_ReadU8(void *);
    extern const f32 lbl_80368FCC;
    f32 f;
    s32 z;

    z = 0;
    f = lbl_80368FCC;
    *(u8 *)((u8 *)arg0 + 3) = z;
    *(s16 *)((u8 *)arg0 + 0x15C) = z;
    *(s16 *)((u8 *)arg0 + 0) = z;
    *(s16 *)((u8 *)arg0 + 0x16E) = -1;
    *(s8 *)((u8 *)arg0 + 0x16D) = -1;
    *(s8 *)((u8 *)arg0 + 0x16C) = -1;
    *(f32 *)((u8 *)arg0 + 0x170) = f;
    *(f32 *)((u8 *)arg0 + 0x174) = f;
    *(f32 *)((u8 *)arg0 + 0x178) = f;
    *(s32 *)((u8 *)arg0 + 0x17C) = z;
    *(s16 *)((u8 *)arg0 + 0x15C) = Stream_ReadU16(stream);
    Stream_ReadU8(stream);
    Stream_ReadU8(stream);
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
f32 a,b,t,y,x,k,z; u8 *p;
a=lbl_80368FCC; p=*(u8 **)((u8 *)arg0+0x17c); b=a;
if(p){ a=(f32)(s8)p[0xa]; b=(f32)(s8)p[0xb]; }
x=a*scale; k=lbl_80368FF4; y=b*scale; t=lbl_80368FCC;
x=x*k; t=t*scale; z=y*k; out[0]=x; t=t*k; out[1]=z; out[2]=t;
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

#pragma global_optimizer off
u8 fn_8004C00C(void *arg0) {
    extern f32 lbl_80368FC4;
    if ((lbl_80368FC4 + (f32) (s8) M2C_FIELD(arg0, u8 *, 0x19E)) != (M2C_FIELD(arg0, f32 *, 4) + M2C_FIELD(arg0, f32 *, 0x10))) {
        return 1U;
    }
    return (u8) ((lbl_80368FC4 + (f32) (s8) M2C_FIELD(arg0, u8 *, 0x19F)) != (M2C_FIELD(arg0, f32 *, 8) + M2C_FIELD(arg0, f32 *, 0x14)));
}
#pragma global_optimizer reset
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

void fn_8004C148(void)
{
  void Ui_LoadAtlasTex(s32, void *, s32);
  void fn_80222C50(void *, s32);
  void fn_8022100C(s32);
  void GXClearVtxDesc(void);
  void GXSetVtxDesc(s32, s32);
  void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
  void GXSetCullMode(s32);
  void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
  void *Light_GetChannel(s32);
  void fn_80222164(s32, void *);
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
  void Allegiance_FillMask(s32, void *);
  void *Map_Get(void);
  u8 fn_80040B1C(void *, s32, s32);
  void fn_8004C444(void *);
  void fn_80066D00(s32);
  extern s32 gUnitShadowMat;
  extern f32 lbl_80368FCC;
  extern f32 gUnitShadowZ;
  extern u32 lbl_80368FB0;
  extern u8 gUnits[];
  u32 color2;
  u32 color;
  u8 mask[4];
  u8 tex[0x20];
  f32 view[3][4];
  f32 trans[3][4];
  u8 *channel;
  u8 *classData;
  s32 red;
  s32 green;
  s32 blue;
  s32 id;
  register u8 *unit;
  s32 x;
  s32 y;
  s32 valid;

  Ui_LoadAtlasTex(gUnitShadowMat, tex, 1);
  fn_80222C50(tex, 0);
  fn_8022100C(2);
  GXClearVtxDesc();
  GXSetVtxDesc(9, 1);
  GXSetVtxDesc(11, 1);
  GXSetVtxAttrFmt(0, 9, 1, 4, 0);
  GXSetVtxAttrFmt(0, 11, 1, 5, 0);
  GXSetCullMode(1);
  GXSetBlendMode(0, 1, 0, 1, 0, 0, 2);
  GXSetBlendMode(2, 0, 1, 1, 0, 0, 2);
  channel = Light_GetChannel(0);
  red = channel[4] + channel[0];
  green = channel[5] + channel[1];
  blue = channel[6] + channel[2];
  if (red > 255) red = 255;
  if (green > 255) green = 255;
  if (blue > 255) blue = 255;
  color = lbl_80368FB0;
  ((u8 *)&color)[0] = red;
  ((u8 *)&color)[1] = green;
  ((u8 *)&color)[2] = blue;
  color2 = color;
  fn_80222164(4, &color2);
  GXSetNumTevStages(1);
  GXSetTevOrder(0, 0, 0, 4);
  GXSetNumChans(1);
  PSMTXTrans(trans, lbl_80368FCC, lbl_80368FCC, gUnitShadowZ);
  PSMTXConcat(Camera_GetViewMtx(), trans, view);
  GXLoadPosMtxImm(view, 0);
  GXSetCurrentMtx(0);
  GXSetZMode(1, 3, 0);
  fn_802245D8(1, 4, 5, 7);
  fn_80223E5C(7, 0, 1, 7, 0);
  GXSetNumTexGens(0, 0);
  Allegiance_FillMask(3, mask);
  for (id = 1; id <= 159; id++)
  {
    if ((u8)id != 0)
    {
      unit = gUnits + ((u8)id - 1) * 0x280;
    }
    else
    {
      unit = 0;
    }
    if (*(void **)(unit + 0x188) == 0) continue;
    classData = *(u8 **)(unit + 0x190);
    if (mask[classData[8]] == 0) continue;
    x = (s32)*(f32 *)(unit + 4);
    y = (s32)*(f32 *)(unit + 8);
    if (fn_80040B1C(Map_Get(), x, y) != 0) continue;
    if ((*(u32 *)(unit + 0x1A0) & 0x010000FC) != 0)
    {
      valid = 0;
    }
    else if ((unit[3] & 0x22) != 2)
    {
      valid = 0;
    }
    else if (unit[0x27] == 0)
    {
      valid = 0;
    }
    else
    {
      valid = 1;
    }
    if (valid != 0)
    {
      fn_8004C444(unit);
    }
  }
  fn_80066D00(-1);
}

#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
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
    u8 sp4C[0x10];
    Vec b, a, up, target, eye;
    u32 spC;
    u32 sp8;
    f32 x, y, angle, f1;
    s32 alpha;
    u8 *tbl;

    tbl = lbl_8026AA98;
    angle = (f32)*(u16 *)arg0;
    x = *(f32 *)((u8 *)arg0 + 4);
    y = *(f32 *)((u8 *)arg0 + 8);
    f1 = fn_80059EB8(0x80, Game_GetFrameCount(), lbl_80368FD4, lbl_80369000);

    alpha = (s32)(((f32)((u8 *)arg0)[0x27] * f1) / lbl_80369000);
    a = *(Vec *)(tbl + 0x1C);
    a.x = x; a.y = y;
    eye = a;
    b = *(Vec *)(tbl + 0x28);
    b.x = x; b.y = y;
    target = b;
    up = *(Vec *)(tbl + 0x34);

    if (lbl_80368FCC != angle) {
        PSMTXRotRad(spBC, 0x5A, lbl_80368FD8 * angle);
        fn_802026E4(sp8C, &target, &up, &eye);
        C_MTXLightOrtho(sp5C, -lbl_80368FC4, lbl_80368FC4, -lbl_80368FC4, lbl_80368FC4,
                    lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
        PSMTXConcat(sp5C, sp8C, sp11C);
        PSMTXTrans(spEC, lbl_80368FDC, lbl_80368FDC, lbl_80368FCC);
        PSMTXConcat(spBC, spEC, spBC);
        PSMTXTrans(spEC, lbl_80368FC4, lbl_80368FC4, lbl_80368FCC);
        PSMTXConcat(spEC, spBC, spBC);
        PSMTXConcat(spBC, sp11C, sp11C);
    } else {
        fn_802026E4(sp8C, &target, &up, &eye);
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
#pragma pop

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
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_lifetimes off
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
    extern u8 gBattleMap[];
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
    u8 m[11][0x30];
    u32 vec3[9];
    u32 q3[6];
    u32 vec2[9];
    u32 q2[6];
    u32 vec1[9];
    u32 q1[6];
    u32 vec[9];
    u32 q[6];
    f32 tmp2[3];
    f32 tmp[3];
    f32 out[3];
    f32 dir[3];
    f32 nrm[3];
    f32 pos[2][3];
    u32 sp8, spC, sp10, sp14, sp18;
    f32 f30, f29, f28, f27, f26, f25, f31, f24;
    f32 dx, t, lim;
    u8 *r28;
    s32 r27;
    s32 r29;
    s32 r30;
    u8 *tbl;

    f30 = *(f32 *)(arg0 + 4);
    f29 = *(f32 *)(arg0 + 8);
    r28 = arg0 + 0x1C;
    f28 = lbl_80369004 * ((f32)*(s16 *)(arg0 + 0x15E) / lbl_80369008);
    f27 = lbl_80369004 * ((f32)*(s16 *)(arg0 + 0x162) / lbl_80369008);
    f25 = *(f32 *)(arg0 + 0xC);
    r29 = (s8)arg0[0x168];
    r27 = (s8)arg0[0x169];
    r30 = (arg1 * arg0[0x27]) / 255;
    tbl = lbl_8026AA98;
    lim = -(f25 - Map_SampleHeight(gBattleMap));
    if (lim > lbl_8036900C) lim = lbl_8036900C;
    f31 = Math_Lerp(lbl_80368FC0, lbl_80368FBC, lbl_8036900C, lim);
    if (r29 >= 0 && r27 >= 0) {
        fn_80060F70(r28, r29, pos[0]);
        fn_80060F70(r28, r27, pos[1]);
        f30 = (pos[0][0] + pos[1][0]) * lbl_80368FC4;
        f29 = (pos[0][1] + pos[1][1]) * lbl_80368FC4;
        f26 = f30 - pos[0][0];
        f25 = f29 - pos[0][1];
        if (lbl_80368FCC != f26 || lbl_80368FCC != f25) {
            *(u32 *)&tmp[0] = *(u32 *)(tbl + 0x58);
            *(u32 *)&tmp[1] = *(u32 *)(tbl + 0x5C);
            tmp[0] = (f32)(s32)(lbl_80369008 * f26);
            tmp[1] = (f32)(s32)(lbl_80369008 * f25);
            *(u32 *)&nrm[0] = *(u32 *)(tbl + 0x4C);
            *(u32 *)&nrm[1] = *(u32 *)(tbl + 0x50);
            *(u32 *)&nrm[2] = *(u32 *)(tbl + 0x54);
            *(u32 *)&tmp[2] = *(u32 *)(tbl + 0x60);
            *(u32 *)&dir[0] = *(u32 *)&tmp[0];
            *(u32 *)&dir[1] = *(u32 *)&tmp[1];
            *(u32 *)&dir[2] = *(u32 *)&tmp[2];
            fn_802031E8(dir, dir);
            t = fn_80203270(nrm, dir);
            if (t > lbl_80368FC0) t = lbl_80368FC0;
            if (t < lbl_80368FFC) t = lbl_80368FFC;
            f24 = fn_80238788(t);
            if (f25 < lbl_80368FCC) f24 *= lbl_80368FFC;
            *(u32 *)&tmp2[0] = *(u32 *)(tbl + 0x64);
            *(u32 *)&tmp2[1] = *(u32 *)(tbl + 0x68);
            *(u32 *)&tmp2[2] = *(u32 *)(tbl + 0x6C);
            tmp2[0] = f26;
            tmp2[1] = f25;
            dir[0] = tmp2[0];
            dir[1] = tmp2[1];
            dir[2] = tmp2[2];
            PSMTXRotRad(m[10], 0x7A, -f24);
            fn_802029C4(m[10], dir, dir);
            f26 = lbl_80369010 + dir[0];
            f25 = lbl_80369010 + dir[1];
            dx = lbl_80369014 * f24;
        }
        if (f26 < f28) f26 = f28;
        if (f25 < f27) f25 = f27;
        q[0] = *(u32 *)(tbl + 0x1C);
        q[1] = *(u32 *)(tbl + 0x20);
        q[2] = *(u32 *)(tbl + 0x24);
        q[3] = *(u32 *)(tbl + 0x28);
        q[4] = *(u32 *)(tbl + 0x2C);
        q[5] = *(u32 *)(tbl + 0x30);
        *(f32 *)&q[0] = f30;
        *(f32 *)&q[1] = f29;
        *(f32 *)&q[3] = f30;
        *(f32 *)&q[4] = f29;
        vec[0] = q[0];
        vec[1] = q[1];
        vec[2] = q[2];
        vec[3] = q[3];
        vec[4] = q[4];
        vec[5] = q[5];
        vec[6] = *(u32 *)(tbl + 0x34);
        vec[7] = *(u32 *)(tbl + 0x38);
        vec[8] = *(u32 *)(tbl + 0x3C);
        if (lbl_80368FCC != dx) {
            PSMTXRotRad(m[8], 0x5A, lbl_80368FD8 * dx);
            fn_802029C4(m[8], &vec[6], &vec[6]);
            fn_802026E4(m[7], &vec[3], &vec[6], &vec[0]);
            C_MTXLightOrtho(m[6], -(f25 * f31), f25 * f31, -(f26 * f31), f26 * f31, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
            PSMTXConcat(m[6], m[7], m[10]);
            PSMTXTrans(m[9], lbl_80368FDC, lbl_80368FDC, lbl_80368FCC);
            PSMTXConcat(m[8], m[9], m[8]);
            PSMTXTrans(m[9], lbl_80368FC4, lbl_80368FC4, lbl_80368FCC);
            PSMTXConcat(m[9], m[8], m[8]);
            PSMTXConcat(m[8], m[10], m[10]);
        } else {
            fn_802026E4(m[7], &vec[3], &vec[6], &vec[0]);
            C_MTXLightOrtho(m[6], -(f25 * f31), f25 * f31, -(f26 * f31), f26 * f31, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
            PSMTXConcat(m[6], m[7], m[10]);
        }
        if (fn_80055D94(0x100) != 0) {
            sp18 = lbl_80368FA8;
            ((u8 *)&sp18)[3] = r30;
            q1[0] = *(u32 *)(tbl + 0x1C);
            q1[1] = *(u32 *)(tbl + 0x20);
            q1[2] = *(u32 *)(tbl + 0x24);
            q1[3] = *(u32 *)(tbl + 0x28);
            q1[4] = *(u32 *)(tbl + 0x2C);
            q1[5] = *(u32 *)(tbl + 0x30);
            *(f32 *)&q1[0] = pos[0][0];
            *(f32 *)&q1[1] = pos[0][1];
            *(f32 *)&q1[3] = pos[0][0];
            *(f32 *)&q1[4] = pos[0][1];
            vec1[0] = q1[0];
            vec1[1] = q1[1];
            vec1[2] = q1[2];
            vec1[3] = q1[3];
            vec1[4] = q1[4];
            vec1[5] = q1[5];
            vec1[6] = *(u32 *)(tbl + 0x34);
            vec1[7] = *(u32 *)(tbl + 0x38);
            vec1[8] = *(u32 *)(tbl + 0x3C);
            fn_802026E4(m[5], &vec1[3], &vec1[6], &vec1[0]);
            C_MTXLightOrtho(m[4], lbl_80369018, lbl_80369010, lbl_80369018, lbl_80369010, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
            PSMTXConcat(m[4], m[5], m[10]);
            fn_80224E50(m[10], 0x1E, 0);
            fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
            sp10 = sp18;
            fn_80051564(&sp10, 1, f30, f29);
            q2[0] = *(u32 *)(tbl + 0x1C);
            q2[1] = *(u32 *)(tbl + 0x20);
            q2[2] = *(u32 *)(tbl + 0x24);
            q2[3] = *(u32 *)(tbl + 0x28);
            q2[4] = *(u32 *)(tbl + 0x2C);
            q2[5] = *(u32 *)(tbl + 0x30);
            *(f32 *)&q2[0] = pos[1][0];
            *(f32 *)&q2[1] = pos[1][1];
            *(f32 *)&q2[3] = pos[1][0];
            *(f32 *)&q2[4] = pos[1][1];
            vec2[0] = q2[0];
            vec2[1] = q2[1];
            vec2[2] = q2[2];
            vec2[3] = q2[3];
            vec2[4] = q2[4];
            vec2[5] = q2[5];
            vec2[6] = *(u32 *)(tbl + 0x34);
            vec2[7] = *(u32 *)(tbl + 0x38);
            vec2[8] = *(u32 *)(tbl + 0x3C);
            fn_802026E4(m[3], &vec2[3], &vec2[6], &vec2[0]);
            C_MTXLightOrtho(m[2], lbl_80369018, lbl_80369010, lbl_80369018, lbl_80369010, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
            PSMTXConcat(m[2], m[3], m[10]);
            fn_80224E50(m[10], 0x1E, 0);
            fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
            spC = sp18;
            fn_80051564(&spC, 1, f30, f29);
            return;
        }
    } else {
        fn_80060F70(r28, 1, out);
        q3[0] = *(u32 *)(tbl + 0x1C);
        q3[1] = *(u32 *)(tbl + 0x20);
        q3[2] = *(u32 *)(tbl + 0x24);
        q3[3] = *(u32 *)(tbl + 0x28);
        q3[4] = *(u32 *)(tbl + 0x2C);
        q3[5] = *(u32 *)(tbl + 0x30);
        *(f32 *)&q3[0] = out[0];
        *(f32 *)&q3[1] = out[1];
        *(f32 *)&q3[3] = out[0];
        *(f32 *)&q3[4] = out[1];
        vec3[0] = q3[0];
        vec3[1] = q3[1];
        vec3[2] = q3[2];
        vec3[3] = q3[3];
        vec3[4] = q3[4];
        vec3[5] = q3[5];
        vec3[6] = *(u32 *)(tbl + 0x34);
        vec3[7] = *(u32 *)(tbl + 0x38);
        vec3[8] = *(u32 *)(tbl + 0x3C);
        fn_802026E4(m[1], &vec3[3], &vec3[6], &vec3[0]);
        C_MTXLightOrtho(m[0], -(f28 * f31), f28 * f31, -(f27 * f31), f27 * f31, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
        PSMTXConcat(m[0], m[1], m[10]);
    }
    fn_80224E50(m[10], 0x1E, 0);
    fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
    sp14 = lbl_80368FAC;
    ((u8 *)&sp14)[3] = r30;
    sp8 = sp14;
    fn_80051564(&sp8, 1, f30, f29);
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma opt_lifetimes reset
#pragma scheduling reset
#pragma optimization_level reset

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

void fn_8004D688(void) {
    void *Camera_GetActive(void);
    f32 Math_Lerp(f32, f32, f32, f32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void fn_80222C50(void *, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxDesc(s32, s32);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void fn_8022100C(s32);
    void GXSetTevColorIn(s32, s32, s32, s32, s32);
    void GXSetTevColorOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
    void GXSetTevAlphaOp(s32, s32, s32, s32, s32, s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetZMode(s32, s32, s32);
    void Allegiance_FillMask(s32, void *);
    void fn_8004DAFC(void *, f32);
    u8 fn_800F2E60(void);
    f32 Map_SampleHeight(void *, f32, f32);
    void fn_8005A1E8(s32, void *, void *);
    void fn_80068070(f32, f32, f32, f32);
    void fn_800680AC(s32, s32, s32, s32);
    void Camera_ApplyOrtho(s32);
    void GXBegin(s32, s32, s32);
    void fn_80067984(s32);
    void fn_800F2E50(s32);
    void fn_8022124C(s32, s32, s32, s32);
    void fn_802212FC(s32, s32, s32, s32);
    void GXCopyTex(s32, s32);
    void fn_802209FC(void);
    void fn_80222EB4(void);
    void fn_80066D00(s32);
    extern s32 gUnitShadowMat;
    extern u8 gUnits[];
    extern u8 gBattleState[];
    extern u8 gBattleMap[];
    extern u32 lbl_8026AAD8[];
    extern s32 lbl_803672B8;
    extern f32 lbl_80368FC0;
    extern f32 lbl_80368FCC;
    extern f32 lbl_80369020;
    extern f32 lbl_80369024;
    extern f32 lbl_80369028;
    extern f32 lbl_8036902C;
    extern f32 lbl_80369030;
    extern f32 lbl_80369034;

    u8 matBuf[0x20];
    f32 pos[3];
    u8 allegMask[8];
    f32 y;
    f32 scale;
    void *unit;
    void *cam;
    s32 unitId;
    s32 canDraw;
    u32 *src;

    scale = lbl_80369020;
    cam = Camera_GetActive();
    if (cam != NULL) {
        scale = Math_Lerp(lbl_80369020, lbl_80369024, lbl_80369024,
                          *(f32 *)((u8 *)cam + 0x18) - lbl_80369028);
    }
    Ui_LoadAtlasTex(gUnitShadowMat, matBuf, 2);
    fn_80222C50(matBuf, 0);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxDesc(0xD, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
    GXSetVtxAttrFmt(0, 0xD, 1, 4, 0);
    GXSetNumChans(1);
    fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
    GXSetCullMode(1);
    GXSetBlendMode(4, 0, 1, 1, 0, 0, 2);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    fn_8022100C(2);
    GXSetTevColorIn(0, 0xF, 8, 0xA, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 6);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    fn_802245D8(1, 1, 1, 0);
    GXSetZMode(0, 3, 0);
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
                fn_8004DAFC(unit, scale);
            }
        }
        unitId += 1;
    } while (unitId <= 0x9F);
    if (fn_800F2E60() != 0) {
        src = lbl_8026AAD8;
        ((u32 *)pos)[0] = src[0];
        ((u32 *)pos)[1] = src[1];
        ((u32 *)pos)[2] = src[2];
        pos[0] = *(f32 *)(gBattleState + 0x534);
        pos[1] = *(f32 *)(gBattleState + 0x538);
        pos[2] = Map_SampleHeight(gBattleMap, pos[0], pos[1]);
        fn_8005A1E8(0, pos, pos);
        y = pos[0];
        scale = pos[1];
        fn_80068070(lbl_80368FCC, lbl_80368FCC, lbl_8036902C, lbl_80369030);
        fn_800680AC(0, 0, 0xA0, 0x78);
        Camera_ApplyOrtho(0);
        GXBegin(0x98, 0, 4);
        {
            f32 one;
            f32 x1;
            f32 z;
            f32 y0;
            f32 x0;
            f32 half;
            f32 y1;
            half = lbl_80369034;
            z = lbl_80368FCC;
            x0 = y - half;
            one = lbl_80368FC0;
            y0 = scale - half;
            x1 = y + half;
            *(volatile f32 *)0xCC008000 = x0;
            y1 = scale + half;
            *(volatile f32 *)0xCC008000 = y0;
            *(volatile f32 *)0xCC008000 = z;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile f32 *)0xCC008000 = z;
            *(volatile f32 *)0xCC008000 = z;
            *(volatile f32 *)0xCC008000 = x1;
            *(volatile f32 *)0xCC008000 = y0;
            *(volatile f32 *)0xCC008000 = z;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile f32 *)0xCC008000 = one;
            *(volatile f32 *)0xCC008000 = z;
            *(volatile f32 *)0xCC008000 = x0;
            *(volatile f32 *)0xCC008000 = y1;
            *(volatile f32 *)0xCC008000 = z;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile f32 *)0xCC008000 = z;
            *(volatile f32 *)0xCC008000 = one;
            *(volatile f32 *)0xCC008000 = x1;
            *(volatile f32 *)0xCC008000 = y1;
            *(volatile f32 *)0xCC008000 = z;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile f32 *)0xCC008000 = one;
            *(volatile f32 *)0xCC008000 = one;
        }
        fn_80067984(0);
        fn_800F2E50(0);
    }
    fn_8022124C(0, 0, 0xA0, 0x78);
    fn_802212FC(0xA0, 0x78, 0x20, 0);
    GXCopyTex(lbl_803672B8, 1);
    fn_802209FC();
    fn_80222EB4();
    fn_80066D00(-1);
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

#pragma scheduling on
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
    u8 *p;
    u8 c;
    u8 flag;

    if (fn_80055D94(0x80) == 0) {
        p = &lbl_803672C0;
        c = 0x60;
        flag = 1;
        *p = c;
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

#pragma push
#pragma opt_strength_reduction off
static inline void Unit_SetModelNodes(void *unit, const unsigned *nodes) {
    M2C_FIELD(unit, u8 *, 0x168) = nodes[0];
    M2C_FIELD(unit, u8 *, 0x169) = nodes[1];
}

void fn_8004EB14(void *arg0, u32 arg1) {
#pragma opt_common_subs off
    void fn_800056A0(s32);
    void fn_800056CC(void *, ...);
    s32 fn_8004ABD4(void *, s32);
    void *fn_80037D54(void *);
    void *fn_8000D354(void *);
    void *fn_8004B078(void *, s32);
    s32 fn_8004B0C8(void *);
    s32 fn_8004B110(void *);
    void *fn_8004B158(void *);
    s32 fn_8004B1A0(s32);
    void fn_8004FE98(void *, s32);
    u16 fn_8005C144(void *);
    void *fn_8005C82C(void *, u16);
    void fn_8005F434(void *, void *, u16);
    void fn_8005F4F4(void *, s32);
    void fn_8005F554(void *, s32);
    void fn_8005F7B0(void *, s32);
    void fn_8005FEE8(void *, f32);
    void *fn_80060638(void *);
    s32 fn_8006135C(void *, void *);
    void *fn_80060664(void *);
    void fn_8006140C(void *);
    void fn_80061824(void *);
    void fn_800688D4(void *, s32, void *, s32);
    u8 fn_80105BC0(void *, s32);
    void fn_80231D94(void *, void *, ...);
    void fn_8004B3DC(void);
    extern u8 lbl_8026AB18[];
    extern void *lbl_80366DC8;
    extern const f32 lbl_80368FCC;
    extern f32 lbl_80368FFC;
    extern u8 lbl_802EFFE8[];

    unsigned nodes[2];
    void *res;
    register void *sub;
    s32 id;
    register void *tmp;
    u8 flags;
    void *sub2;

    flags = M2C_FIELD(arg0, u8 *, 3);
    if (!(flags & 2)) {
        M2C_FIELD(arg0, u8 *, 3) = flags & 0xFE;
        M2C_FIELD(arg0, u8 *, 3) |= 2;
        id = get_4F128_id(arg0);
        res = Unit_ResolveDisplayResource(id, arg0);
        sub = (u8 *)arg0 + 0x1C;
        M2C_FIELD(arg0, void **, 0x17C) = res;
        arg1 = (u16)arg1 | 8;
        fn_80061824(sub);
        M2C_FIELD(sub, u8 *, 0x87) = 1;
        M2C_FIELD(arg0, void **, 0x164) = fn_8005C82C(fn_8004B158(res), (u16)arg1);
        fn_8005F4F4(sub, fn_8004B0C8(res));
        fn_8005F554(sub, fn_8004B110(res));
        id = get_4F128_id(arg0);
        res = Unit_ResolveDisplayResource(id, arg0);
        switch (M2C_FIELD(M2C_FIELD(arg0, void **, 0x190), u8 *, 8)) {
        case 0: res = fn_8004B078(res, 0); break;
        case 1: res = fn_8004B078(res, 1); break;
        case 2: res = fn_8004B078(res, 2); break;
        case 3: res = fn_8004B078(res, 3); break;
        default: res = fn_8004B078(res, 0); break;
        }
        if (!res || fn_8005C144(res) == 0x8000U) {
            res = lbl_80366DC8;
        }
        fn_8005F434(sub, res, (u16)arg1);
        fn_8006140C(sub);
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
            M2C_FIELD(arg0, u8 *, 3) &= ~0x10;
        } else {
            fn_8004FE98(arg0, 0);
        }
        {
            register u32 bits = M2C_FIELD(sub, u32 *, 0);
            bits = (bits | 0x61100000) | 0x8000;
            M2C_FIELD(sub, u32 *, 0) = bits;
        }
        M2C_FIELD(arg0, f32 *, 0x10) = lbl_80368FCC;
        M2C_FIELD(arg0, f32 *, 0x14) = lbl_80368FCC;
        M2C_FIELD(arg0, f32 *, 0x18) = lbl_80368FCC;
        M2C_FIELD(arg0, s16 *, 0x15E) = 0x3C;
        M2C_FIELD(arg0, s16 *, 0x160) = 0x3C;
        M2C_FIELD(arg0, s16 *, 0x162) = 0x3C;
        nodes[0] = fn_8006135C(sub, lbl_8026AB18 + 0x8F);
        nodes[1] = fn_8006135C(sub, lbl_8026AB18 + 0x92);
        sub2 = (u8 *)arg0 + 0x1C;
        M2C_FIELD(arg0, u8 *, 0x168) = nodes[0];
        M2C_FIELD(arg0, u8 *, 0x169) = nodes[1];
        fn_800688D4(fn_80060638(sub2), 0, fn_8004B3DC, 0x4000);
        M2C_FIELD(sub2, void **, 0x90) = arg0;
        fn_8005F7B0(sub2, 0);
        sub2 = (u8 *)arg0 + 0xBC;
        fn_80061824(sub2);
        M2C_FIELD(sub2, void **, 4) = lbl_802EFFE8;
        fn_8006140C(sub2);
        M2C_FIELD(sub2, u32 *, 0) |= 0x100;
        M2C_FIELD(sub2, void **, 4) = NULL;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_loop_invariants off
s32 Unit_IsDisplayReady(void *arg0) {

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
 s32 id;
 void *res;
 void *obj=arg0;
 u8 flags=M2C_FIELD(arg0,u8 *,3);
 if(flags&2) return 1;
 if(!(flags&1)) return 1;
 id=get_4F128_id(arg0);
 res=get_4F128_resource(obj,id);
 if(!FileCache_IsReady(fn_8004B158(res))) return 0;
 if(!fn_8004AF74(res,M2C_FIELD(M2C_FIELD(arg0,void **,0x190),u8 *,8))) {
 res=Unit_ResolveDisplayResource(get_4F128_id(arg0),arg0);
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
#pragma pop
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
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_8004F5EC(void *arg0,u32 arg1) {
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
 name = get_4F5EC_resource(arg0);
 switch(M2C_FIELD(M2C_FIELD(arg0,void **,0x190),u8 *,8)) {
 case 0: res=fn_8004B078(name,0);break;
 case 1: res=fn_8004B078(name,1);break;
 case 2: res=fn_8004B078(name,2);break;
 case 3: res=fn_8004B078(name,3);break;
 default: res=fn_8004B078(name,0);break;
 }
 if(!res||FileCache_Probe(res)==0x8000U) res=lbl_80366DC8;
 if(res!=lbl_80366DC8) fn_8005C870(res,arg1);
 }
 M2C_FIELD(arg0,u8 *,3)|=1;
 }
}
#pragma pop
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
void fn_8004FE98(s32 arg0, s8 arg1)
{
  unsigned int new_var2;
  char *fn_8004AFD4(void *, s8);
  void fn_8005FA14(void *, s32);
  char *new_var;
  void fn_8005F5B4(void *, void *);
  void *res;
  void *result;
  void *dest;
  s32 item;
  if (((*((u8 *) (((s8 *) arg0) + 3))) & 2) != 0)
  {
    item = get_4F128_id((void *) arg0);
    res = get_4F128_resource((void *) arg0, item);
    *((void **) (((s8 *) arg0) + 0x17C)) = res;
    dest = ((u8 *) arg0) + 0x1C;
    item = (new_var2 = get_4F128_id((void *) arg0));
    res = get_4F128_resource((void *) arg0, item);
    new_var = fn_8004AFD4(res, arg1);
    result = new_var;
    if (result != 0)
    {
      fn_8005FA14(dest, 1);
      fn_8005F5B4(dest, result);
      *((s8 *) (((s8 *) arg0) + 2)) = arg1;
    }
  }
}

#pragma opt_common_subs off
void fn_80050268(void *arg0) {
void *fn_8004B078(void *,s32);
u16 FileCache_Probe(void *);
void fn_8005F434(void *,void *,s32);
extern void *lbl_80366DC8;
s32 value;
void *result; void *dest;
if(M2C_FIELD(arg0,u8 *,3)&2) {
dest=(u8 *)arg0+0x1C;
value=get_4F128_id(arg0);
result=get_4F128_resource(arg0,value);
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
#pragma push
#pragma optimization_level 4
void fn_800504FC(void *arg0, s32 arg1) {
void fn_8004AFB4(void *, s32);
s32 value = get_4F128_id(arg0);
void *res = get_4F128_resource(arg0, value);
fn_8004AFB4(res, arg1);
}
#pragma pop
#pragma optimization_level reset
void fn_800506E0(void *arg0, s32 arg1) {
void fn_8004AFD4(void *, s32);
s32 value = get_4F128_id(arg0);
void *res = get_4F128_resource(arg0, value);
fn_8004AFD4(res, arg1);
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
 u32 value;
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
 sprintf(buf,lbl_8026AB18+0x5F,name,fn_8004B1A0((s32)value));
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
    f32 fx;
    f32 fy;
    u32 flags;
    u8 mode;
    u8 enabled;
    u32 value;

    unit = (u8 *)arg0;

    if (fn_80040824(unit) != 0) {
        x = *(s8 *)(unit + 0x19E);
        y = *(s8 *)(unit + 0x19F);

        fx = lbl_80368FC4 + (f32)x;
        fy = lbl_80368FC4 + (f32)y;
        *(f32 *)(unit + 4) = fx;
        *(f32 *)(unit + 8) = fy;

        *(f32 *)(unit + 0xC) = Map_SampleHeightRaw(gBattleMap, fx, fy);

        flags = *(u32 *)(unit + 0x1A0);
        *(u32 *)(unit + 0x1A0) = flags & ~0x240;

        Model_SetAlpha(unit + 0x1C, 0xFF);

        enabled = 1;
        mode = (u8)(gMapBlendMode - 1);

        if (((u32)((enabled | ~mode) -
            ((u32)(enabled - mode) >> 1)) >> 31) == 0) {
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
 u8 *obj = lbl_803672CC;
 if (!obj) return;
 fn_80050E14_Body(obj, 0);
}
#pragma peephole on
void fn_80050E80(void)
{
#pragma push
#pragma global_optimizer off
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
    extern s32 gUnitShadowMat;
    char *p;
    s32 i;
    void *a;
    void *b;

    fn_800162B8();
    i = 0;
    p = (char *)lbl_802EFFE8;
    do {
        fn_800616A0(p);
        i += 1;
        p += 0xA0;
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
    p = (char *)lbl_803672CC;
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
    b = (void *)gUnitShadowMat;
    lbl_803672CC = 0;
    fn_8006D8E8(b);
#pragma pop
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_propagation off
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
    extern s32 gUnitShadowMat;
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
    f32 height;

    gUnitShadowMat = (s32)fn_8006D948(lbl_8026AB18 + 0x95);
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
        s32 i, off, idx;
        i = 0;
        *(s32 *)(a + 0x14) = i;
        off = *(s32 *)(a + 0x14);
        idx = *(s32 *)(a + 0x14);
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
        s32 id = 1;
        s32 ctr;
        void *unit;
        height = lbl_80368FCC;
        for (ctr = 0x9F; ctr != 0; ctr--) {
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
                *(f32 *)((u8 *)unit + 0x170) = height;
                *(f32 *)((u8 *)unit + 0x174) = height;
                *(f32 *)((u8 *)unit + 0x178) = height;
                *(s32 *)((u8 *)unit + 0x17C) = z;
            }
            id += 1;
        }
    }

    lbl_803672BC = 1;
}
#pragma pop
#pragma opt_common_subs off

void fn_80051328(u8 arg0, void *arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    void fn_802029C4(void *, void *, void *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXTrans(void *, f32, f32, f32);
    void fn_802026E4(void *, void *, void *, void *);
    void C_MTXLightOrtho(void *, f32, f32, f32, f32, f32, f32, f32, f32);
    extern u8 lbl_8026AA98[];
    extern f32 lbl_80368FC4, lbl_80368FCC, lbl_80368FD8, lbl_80368FDC;
    struct Stack {
        u32 f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34, f38, f3C, f40;
        u8 a44[0x30];
        u8 a74[0x30];
        u8 aA4[0x30];
        u8 aD4[0x30];
    };
    struct Stack s;
    u8 *tbl;

    tbl = lbl_8026AA98;
    s.f2C = *(u32 *)(tbl + 0x1C);
    s.f30 = *(u32 *)(tbl + 0x20);
    s.f38 = *(u32 *)(tbl + 0x28);
    s.f3C = *(u32 *)(tbl + 0x2C);
    *(f32 *)&s.f2C = farg0;
    *(f32 *)&s.f30 = farg1;
    *(f32 *)&s.f38 = farg0;
    *(f32 *)&s.f3C = farg1;
    s.f34 = *(u32 *)(tbl + 0x24);
    s.f8 = s.f2C;
    s.fC = s.f30;
    s.f10 = s.f34;
    s.f40 = *(u32 *)(tbl + 0x30);
    s.f14 = s.f38;
    s.f18 = s.f3C;
    s.f1C = s.f40;
    s.f20 = *(u32 *)(tbl + 0x34);
    s.f24 = *(u32 *)(tbl + 0x38);
    s.f28 = *(u32 *)(tbl + 0x3C);
    if (lbl_80368FCC != farg4) {
        PSMTXRotRad(s.aA4, 0x5A, lbl_80368FD8 * farg4);
        if (arg0 == 0) {
            fn_802029C4(s.aA4, &s.f20, &s.f20);
        }
        fn_802026E4(s.a74, &s.f14, &s.f20, &s.f8);
        C_MTXLightOrtho(s.a44, -farg2, farg2, -farg3, farg3, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
        PSMTXConcat(s.a44, s.a74, arg1);
        PSMTXTrans(s.aD4, lbl_80368FDC, lbl_80368FDC, lbl_80368FCC);
        PSMTXConcat(s.aA4, s.aD4, s.aA4);
        PSMTXTrans(s.aD4, lbl_80368FC4, lbl_80368FC4, lbl_80368FCC);
        PSMTXConcat(s.aD4, s.aA4, s.aA4);
        PSMTXConcat(s.aA4, arg1, arg1);
        return;
    }
    fn_802026E4(s.a74, &s.f14, &s.f20, &s.f8);
    C_MTXLightOrtho(s.a44, -farg2, farg2, -farg3, farg3, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
    PSMTXConcat(s.a44, s.a74, arg1);
}

void fn_80051538(s32 *arg0) {
    M2C_UNK fn_80051564(s32 *);
    s32 sp8;

    sp8 = *arg0;
    fn_80051564(&sp8);
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma use_lmw_stmw on
void fn_80051564(u32 *arg0, u8 arg1, f32 fx, f32 fy)
{
    void GXBegin(s32, s32, s32);
    f32 Map_GetTileCornerHeight(void *, s8, s8, s32);
    extern u8 gBattleMap[];
    extern f32 lbl_8036904C;
    extern f32 lbl_80369050;

    volatile f32 *wgpipe = (volatile f32 *)0xCC008000;
    volatile u8 *colorpipe = (volatile u8 *)0xCC008000;
    u8 rbottom, gbottom, abottom, bbottom;
    s32 x = (s32)fx;
    s32 y = (s32)fy;
    f32 dy0;
    f32 dx;
    f32 dy2, dy1;
    f32 height;
    u32 color0,color1,color2,color3,color4,color5,color6,color7,color8;
    u8 a,b,g,r;
    u8 redge, gedge, aedge, bedge;
    u8 *rgba;

    /* Center: tile (x, y) */
    color0 = *arg0;
if ((x) >= 0 && (y) >= 0 &&
        (x) < *(s32 *)(gBattleMap + 0) &&
        (y) < *(s32 *)(gBattleMap + 4) &&
        (arg1 == 0 || (s32)gBattleMap[0x100D + (s8)(x) + ((s8)(y) << 6)] != 0x1A)) {
        
        rgba = (u8 *)&color0;
        GXBegin(0x98, 0, 4);

        height = Map_GetTileCornerHeight(gBattleMap, (s8)(x), (s8)(y), 0);
        r = rgba[0]; g = rgba[1]; b = rgba[2]; a = rgba[3];
        *wgpipe = (f32)(x);
        *wgpipe = (f32)(y);
        *wgpipe = height;
        *colorpipe = r;
        *colorpipe = g;
        *colorpipe = b;
        *colorpipe = a;

        height = Map_GetTileCornerHeight(gBattleMap, (s8)(x), (s8)(y), 1);
        *wgpipe = (f32)(x + 1);
        *wgpipe = (f32)(y);
        *wgpipe = height;
        *colorpipe = r;
        *colorpipe = g;
        *colorpipe = b;
        *colorpipe = a;

        height = Map_GetTileCornerHeight(gBattleMap, (s8)(x), (s8)(y), 2);
        *wgpipe = (f32)(x);
        *wgpipe = (f32)(y + 1);
        *wgpipe = height;
        *colorpipe = r;
        *colorpipe = g;
        *colorpipe = b;
        *colorpipe = a;

        height = Map_GetTileCornerHeight(gBattleMap, (s8)(x), (s8)(y), 3);
        *wgpipe = (f32)(x + 1);
        *wgpipe = (f32)(y + 1);
        *wgpipe = height;
        *colorpipe = r;
        *colorpipe = g;
        *colorpipe = b;
        *colorpipe = a;
    }

    dx = fx - (f32)x;
    if (dx < lbl_8036904C) {
        /* Left: tile (x - 1, y) */
        color1 = *arg0;
if ((x - 1) >= 0 && (y) >= 0 &&
            (x - 1) < *(s32 *)(gBattleMap + 0) &&
            (y) < *(s32 *)(gBattleMap + 4) &&
            (arg1 == 0 || (s32)gBattleMap[0x100D + (s8)(x - 1) + ((s8)(y) << 6)] != 0x1A)) {
            
            rgba = (u8 *)&color1;
            GXBegin(0x98, 0, 4);

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)(y), 0);
        r = rgba[0]; g = rgba[1]; b = rgba[2]; a = rgba[3];
            *wgpipe = (f32)(x - 1);
            *wgpipe = (f32)(y);
            *wgpipe = height;
            *colorpipe = r;
            *colorpipe = g;
            *colorpipe = b;
            *colorpipe = a;

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)(y), 1);
            *wgpipe = (f32)(x - 1 + 1);
            *wgpipe = (f32)(y);
            *wgpipe = height;
            *colorpipe = r;
            *colorpipe = g;
            *colorpipe = b;
            *colorpipe = a;

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)(y), 2);
            *wgpipe = (f32)(x - 1);
            *wgpipe = (f32)(y + 1);
            *wgpipe = height;
            *colorpipe = r;
            *colorpipe = g;
            *colorpipe = b;
            *colorpipe = a;

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)(y), 3);
            *wgpipe = (f32)(x - 1 + 1);
            *wgpipe = (f32)(y + 1);
            *wgpipe = height;
            *colorpipe = r;
            *colorpipe = g;
            *colorpipe = b;
            *colorpipe = a;
        }

        dy0 = fy - (f32)y;
        if (dy0 < lbl_8036904C) {
            /* Upper-left: tile (x - 1, y - 1) */
            color2 = *arg0;
if ((x - 1) >= 0 && (y - 1) >= 0 &&
                (x - 1) < *(s32 *)(gBattleMap + 0) &&
                (y - 1) < *(s32 *)(gBattleMap + 4) &&
                (arg1 == 0 || (s32)gBattleMap[0x100D + (s8)(x - 1) + ((s8)(y - 1) << 6)] != 0x1A)) {
                
                rgba = (u8 *)&color2;
                GXBegin(0x98, 0, 4);

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)(y - 1), 0);
        r = rgba[0]; g = rgba[1]; b = rgba[2]; a = rgba[3];
                *wgpipe = (f32)(x - 1);
                *wgpipe = (f32)(y - 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)(y - 1), 1);
                *wgpipe = (f32)(x - 1 + 1);
                *wgpipe = (f32)(y - 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)(y - 1), 2);
                *wgpipe = (f32)(x - 1);
                *wgpipe = (f32)(y - 1 + 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)(y - 1), 3);
                *wgpipe = (f32)(x - 1 + 1);
                *wgpipe = (f32)(y - 1 + 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;
            }
        }
        if (dy0 > lbl_80369050) {
            /* Lower-left: tile (x - 1, y + 1) */
            color3 = *arg0;
if ((x - 1) >= 0 && (y + 1) >= 0 &&
                (x - 1) < *(s32 *)(gBattleMap + 0) &&
                (y + 1) < *(s32 *)(gBattleMap + 4) &&
                (arg1 == 0 || (s32)gBattleMap[0x100D + (s8)(x - 1) + ((s8)(y + 1) << 6)] != 0x1A)) {
                
                rgba = (u8 *)&color3;
                GXBegin(0x98, 0, 4);

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)(y + 1), 0);
        r = rgba[0]; g = rgba[1]; b = rgba[2]; a = rgba[3];
                *wgpipe = (f32)(x - 1);
                *wgpipe = (f32)(y + 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)(y + 1), 1);
                *wgpipe = (f32)(x - 1 + 1);
                *wgpipe = (f32)(y + 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)(y + 1), 2);
                *wgpipe = (f32)(x - 1);
                *wgpipe = (f32)(y + 1 + 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)(y + 1), 3);
                *wgpipe = (f32)(x - 1 + 1);
                *wgpipe = (f32)(y + 1 + 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;
            }
        }
    }

    if (dx > lbl_80369050) {
        /* Right: tile (x + 1, y) */
        color4 = *arg0;
if ((x + 1) >= 0 && (y) >= 0 &&
            (x + 1) < *(s32 *)(gBattleMap + 0) &&
            (y) < *(s32 *)(gBattleMap + 4) &&
            (arg1 == 0 || (s32)gBattleMap[0x100D + (s8)(x + 1) + ((s8)(y) << 6)] != 0x1A)) {
            
            rgba = (u8 *)&color4;
            GXBegin(0x98, 0, 4);

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x + 1), (s8)(y), 0);
        r = rgba[0]; g = rgba[1]; b = rgba[2]; a = rgba[3];
            *wgpipe = (f32)(x + 1);
            *wgpipe = (f32)(y);
            *wgpipe = height;
            *colorpipe = r;
            *colorpipe = g;
            *colorpipe = b;
            *colorpipe = a;

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x + 1), (s8)(y), 1);
            *wgpipe = (f32)(x + 1 + 1);
            *wgpipe = (f32)(y);
            *wgpipe = height;
            *colorpipe = r;
            *colorpipe = g;
            *colorpipe = b;
            *colorpipe = a;

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x + 1), (s8)(y), 2);
            *wgpipe = (f32)(x + 1);
            *wgpipe = (f32)(y + 1);
            *wgpipe = height;
            *colorpipe = r;
            *colorpipe = g;
            *colorpipe = b;
            *colorpipe = a;

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x + 1), (s8)(y), 3);
            *wgpipe = (f32)(x + 1 + 1);
            *wgpipe = (f32)(y + 1);
            *wgpipe = height;
            *colorpipe = r;
            *colorpipe = g;
            *colorpipe = b;
            *colorpipe = a;
        }

        dy1 = fy - (f32)y;
        if (dy1 < lbl_8036904C) {
            /* Upper-right: tile (x + 1, y - 1) */
            color5 = *arg0;
if ((x + 1) >= 0 && (y - 1) >= 0 &&
                (x + 1) < *(s32 *)(gBattleMap + 0) &&
                (y - 1) < *(s32 *)(gBattleMap + 4) &&
                (arg1 == 0 || (s32)gBattleMap[0x100D + (s8)(x + 1) + ((s8)(y - 1) << 6)] != 0x1A)) {
                
                rgba = (u8 *)&color5;
                GXBegin(0x98, 0, 4);

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x + 1), (s8)(y - 1), 0);
        r = rgba[0]; g = rgba[1]; b = rgba[2]; a = rgba[3];
                *wgpipe = (f32)(x + 1);
                *wgpipe = (f32)(y - 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x + 1), (s8)(y - 1), 1);
                *wgpipe = (f32)(x + 1 + 1);
                *wgpipe = (f32)(y - 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x + 1), (s8)(y - 1), 2);
                *wgpipe = (f32)(x + 1);
                *wgpipe = (f32)(y - 1 + 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x + 1), (s8)(y - 1), 3);
                *wgpipe = (f32)(x + 1 + 1);
                *wgpipe = (f32)(y - 1 + 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;
            }
        }
        if (dy1 > lbl_80369050) {
            /* Lower-right: tile (x + 1, y + 1) */
            color6 = *arg0;
if ((x + 1) >= 0 && (y + 1) >= 0 &&
                (x + 1) < *(s32 *)(gBattleMap + 0) &&
                (y + 1) < *(s32 *)(gBattleMap + 4) &&
                (arg1 == 0 || (s32)gBattleMap[0x100D + (s8)(x + 1) + ((s8)(y + 1) << 6)] != 0x1A)) {
                
                rgba = (u8 *)&color6;
                GXBegin(0x98, 0, 4);

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x + 1), (s8)(y + 1), 0);
        r = rgba[0]; g = rgba[1]; b = rgba[2]; a = rgba[3];
                *wgpipe = (f32)(x + 1);
                *wgpipe = (f32)(y + 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x + 1), (s8)(y + 1), 1);
                *wgpipe = (f32)(x + 1 + 1);
                *wgpipe = (f32)(y + 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x + 1), (s8)(y + 1), 2);
                *wgpipe = (f32)(x + 1);
                *wgpipe = (f32)(y + 1 + 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;

                height = Map_GetTileCornerHeight(gBattleMap, (s8)(x + 1), (s8)(y + 1), 3);
                *wgpipe = (f32)(x + 1 + 1);
                *wgpipe = (f32)(y + 1 + 1);
                *wgpipe = height;
                *colorpipe = r;
                *colorpipe = g;
                *colorpipe = b;
                *colorpipe = a;
            }
        }
    }

    dy2 = fy - (f32)y;
    if (dy2 < lbl_8036904C) {
        /* Above: tile (x, y - 1) */
        color7 = *arg0;
if ((x) >= 0 && (y - 1) >= 0 &&
            (x) < *(s32 *)(gBattleMap + 0) &&
            (y - 1) < *(s32 *)(gBattleMap + 4) &&
            (arg1 == 0 || (s32)gBattleMap[0x100D + (s8)(x) + ((s8)(y - 1) << 6)] != 0x1A)) {
            
            rgba = (u8 *)&color7;
            GXBegin(0x98, 0, 4);

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x), (s8)(y - 1), 0);
        redge = rgba[0]; gedge = rgba[1]; bedge = rgba[2]; aedge = rgba[3];
            *wgpipe = (f32)(x);
            *wgpipe = (f32)(y - 1);
            *wgpipe = height;
            *colorpipe = redge;
            *colorpipe = gedge;
            *colorpipe = bedge;
            *colorpipe = aedge;

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x), (s8)(y - 1), 1);
            *wgpipe = (f32)(x + 1);
            *wgpipe = (f32)(y - 1);
            *wgpipe = height;
            *colorpipe = redge;
            *colorpipe = gedge;
            *colorpipe = bedge;
            *colorpipe = aedge;

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x), (s8)(y - 1), 2);
            *wgpipe = (f32)(x);
            *wgpipe = (f32)(y - 1 + 1);
            *wgpipe = height;
            *colorpipe = redge;
            *colorpipe = gedge;
            *colorpipe = bedge;
            *colorpipe = aedge;

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x), (s8)(y - 1), 3);
            *wgpipe = (f32)(x + 1);
            *wgpipe = (f32)(y - 1 + 1);
            *wgpipe = height;
            *colorpipe = redge;
            *colorpipe = gedge;
            *colorpipe = bedge;
            *colorpipe = aedge;
        }
    }
    if (dy2 > lbl_80369050) {
        /* Below: tile (x, y + 1) */
        color8 = *arg0;
if ((x) >= 0 && (y + 1) >= 0 &&
            (x) < *(s32 *)(gBattleMap + 0) &&
            (y + 1) < *(s32 *)(gBattleMap + 4) &&
            (arg1 == 0 || (s32)gBattleMap[0x100D + (s8)(x) + ((s8)(y + 1) << 6)] != 0x1A)) {
            
            rgba = (u8 *)&color8;
            GXBegin(0x98, 0, 4);

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x), (s8)(y + 1), 0);
        rbottom = rgba[0]; gbottom = rgba[1]; bbottom = rgba[2]; abottom = rgba[3];
            *wgpipe = (f32)(x);
            *wgpipe = (f32)(y + 1);
            *wgpipe = height;
            *colorpipe = rbottom;
            *colorpipe = gbottom;
            *colorpipe = bbottom;
            *colorpipe = abottom;

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x), (s8)(y + 1), 1);
            *wgpipe = (f32)(x + 1);
            *wgpipe = (f32)(y + 1);
            *wgpipe = height;
            *colorpipe = rbottom;
            *colorpipe = gbottom;
            *colorpipe = bbottom;
            *colorpipe = abottom;

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x), (s8)(y + 1), 2);
            *wgpipe = (f32)(x);
            *wgpipe = (f32)(y + 1 + 1);
            *wgpipe = height;
            *colorpipe = rbottom;
            *colorpipe = gbottom;
            *colorpipe = bbottom;
            *colorpipe = abottom;

            height = Map_GetTileCornerHeight(gBattleMap, (s8)(x), (s8)(y + 1), 3);
            *wgpipe = (f32)(x + 1);
            *wgpipe = (f32)(y + 1 + 1);
            *wgpipe = height;
            *colorpipe = rbottom;
            *colorpipe = gbottom;
            *colorpipe = bbottom;
            *colorpipe = abottom;
        }
    }
}
#pragma pop
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

static inline void Obj_GetActiveUnit(u8 *object, u8 **out) {
    if (*(u32 *)(object + 8) & 0x20000000) {
        *out = *(u8 **)(object + 0x34);
        if (*out != 0) {
            return;
        }
    }
    *out = *(u8 **)(object + 0x30);
}

#pragma push
#pragma opt_dead_code off
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
 if(!(*(u32 *)(object+8)&0x20000000) || (unit=*(u8 **)(object+0x34))==0) {
     unit=*(u8 **)(object+0x30);
 }
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
#pragma pop
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
    extern const f32 lbl_8036909C;
    void *temp_r3;
    f32 *var_r4;
    f32 x;
    f32 z;
    f32 y;

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
        *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x10) = y;
        *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x14) = lbl_8036909C + z;
    }
}

#pragma push
#pragma optimization_level 4
void fn_8005306C(void *arg0) {
    typedef struct { f32 x, y, z; } Triple;
    f32 Map_SampleHeightRaw(M2C_UNK *, f32, f32, f32);
    f32 Math_Angle2D(f32, f32, f32, f32);
    extern u8 gBattleMap[];
    extern const f32 lbl_80369098;
    extern const f32 lbl_8036909C;
    Triple a;
    Triple b;
    f32 *var_r3;
    f32 temp_f3;
    f32 temp_f3_2;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r0_3;
    u8 temp_r0_4;

    void *temp_r3;
    void *temp_r4;
    void *temp_r5;


    f32 *var_r31;
    f32 *var_r30;
    void *temp_r29;
    var_r31 = NULL;
    var_r30 = NULL;
    temp_r3 = M2C_FIELD(arg0, void **, 0x30);
    temp_r5 = M2C_FIELD(temp_r3, void **, 0x34);
    temp_r29 = M2C_FIELD(temp_r3, void **, 0x30);
    if (temp_r5 != NULL) {
        temp_r0 = M2C_FIELD(temp_r5, u8 *, 0x19E);
        a.x = lbl_80369098 + (f32) (s8) temp_r0;
        temp_r0_2 = M2C_FIELD(temp_r5, u8 *, 0x19F);
        temp_f3 = lbl_80369098 + (f32) (s8) temp_r0_2;
        a.y = temp_f3;
        a.z = Map_SampleHeightRaw((M2C_UNK *)gBattleMap, (f32) (s8) temp_r0, (f32) (s8) temp_r0_2, temp_f3);
        var_r31 = &a.x;
    }
    if (temp_r29 != NULL) {
        temp_r0_3 = M2C_FIELD(temp_r29, u8 *, 0x19E);
        b.x = lbl_80369098 + (f32) (s8) temp_r0_3;
        temp_r0_4 = M2C_FIELD(temp_r29, u8 *, 0x19F);
        temp_f3_2 = lbl_80369098 + (f32) (s8) temp_r0_4;
        b.y = temp_f3_2;
        b.z = Map_SampleHeightRaw((M2C_UNK *)gBattleMap, (f32) (s8) temp_r0_3, (f32) (s8) temp_r0_4, temp_f3_2);
        var_r30 = &b.x;
    }
    if ((var_r31 != NULL) && (var_r30 != NULL)) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x24) = Math_Angle2D(var_r31[0], var_r31[1], var_r30[0], var_r30[1]);
    }
    temp_r4 = M2C_FIELD(arg0, void **, 0x30);
    if ((M2C_FIELD(temp_r4, s32 *, 8) & 0x20000000) && (var_r31 != NULL)) {
        var_r3 = var_r31;
    } else {
        var_r3 = var_r30;
    }
    if (var_r3 != NULL) {
 f32 x,z,height,y; z=var_r3[2]; y=var_r3[1]; x=var_r3[0]; height=lbl_8036909C;
        M2C_FIELD(temp_r4, f32 *, 0xC) = x;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x10) = y;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x14) = height+z;
    }
}
#pragma pop
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

#pragma cplusplus reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
/* Build map-object model node from path templates; optionally spawn a linked child object. */

#pragma use_lmw_stmw reset

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

extern void *gMap;
#include "common.h"
#include "global.h"

extern u8 lbl_8026A660[];
extern void* lbl_803672A8;
extern u8 gBattleMap[];
extern void *lbl_803672CC;
#include "global.h"
#include "common.h"

extern u32 jumptable_8028561C[];
extern u32 jumptable_802855E4[];
#include "global.h"
extern s32 gUnitShadowMat;
extern f32 lbl_80368FCC;
extern f32 gUnitShadowZ;
extern u8 gUnits[];
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

#pragma push
#pragma optimization_level 3
void fn_8004781C(void *arg0)
{
    struct EntryTail {
        u32 data[40];
    };

    struct MapEntry {
        u8 bytes[8];
        f32 x;
        f32 y;
        void *object;
        struct EntryTail tail;
    };

    u8 *map;
    u8 *base;
    u8 *node;
    struct MapEntry temp;
    u32 flags;
    u32 firstPriority;
    u32 secondPriority;
    struct MapEntry *first;
    struct MapEntry *second;
    s32 offset;
    s32 i;
    s32 j;
    s32 count;

    map = (u8 *)arg0;

    i = 0;
    goto outer_test;

outer_loop:
    j = 0;
    offset = 0;
    goto inner_test;

inner_loop:
    base = *(u8 *volatile *)(map + 0x14);
    first = (struct MapEntry *)(base + offset);

    flags = *(u32 *)(*(u8 **)((u8 *)first + 0x10) + 0xBC);

    firstPriority = 0;

    if (flags & 0x10) {
        firstPriority = 1;
    }

    if (flags & 0x80) {
        firstPriority += 2;
    }

    if (flags & 0x20000) {
        firstPriority += 0x10000;
    }

    if (flags & 0x800) {
        firstPriority += 0x20000;
    }

    if (flags & 0x2000) {
        firstPriority += 0x40000;
    }

    if (flags & 0x20) {
        firstPriority += 0x80000;
    }

    flags = *(u32 *)(*(u8 **)((u8 *)first + 0xC4) + 0xBC);

    secondPriority = 0;

    if (flags & 0x10) {
        secondPriority = 1;
    }

    if (flags & 0x80) {
        secondPriority += 2;
    }

    if (flags & 0x20000) {
        secondPriority += 0x10000;
    }

    if (flags & 0x800) {
        secondPriority += 0x20000;
    }

    if (flags & 0x2000) {
        secondPriority += 0x40000;
    }

    if (flags & 0x20) {
        secondPriority += 0x80000;
    }

    if (firstPriority > secondPriority) {
        s32 nextOffset;
        u8 *swapBase;

        temp = *first;

        nextOffset = (j + 1) * 0xB4;

        swapBase = *(u8 **)(map + 0x14);
        second = (struct MapEntry *)(swapBase + nextOffset);
        first = (struct MapEntry *)(swapBase + offset);

        first->bytes[0] = second->bytes[0];
        first->bytes[1] = second->bytes[1];
        first->bytes[2] = second->bytes[2];
        first->bytes[3] = second->bytes[3];
        first->bytes[4] = second->bytes[4];
        first->bytes[5] = second->bytes[5];
        first->bytes[6] = second->bytes[6];
        first->bytes[7] = second->bytes[7];

        first->x = second->x;
        first->y = second->y;
        first->object = second->object;
        first->tail = second->tail;

        swapBase = *(u8 **)(map + 0x14);
        first = (struct MapEntry *)(swapBase + nextOffset);

        first->bytes[0] = temp.bytes[0];
        first->bytes[1] = temp.bytes[1];
        first->bytes[2] = temp.bytes[2];
        first->bytes[3] = temp.bytes[3];
        first->bytes[4] = temp.bytes[4];
        first->bytes[5] = temp.bytes[5];
        first->bytes[6] = temp.bytes[6];
        first->bytes[7] = temp.bytes[7];

        first->x = temp.x;
        first->y = temp.y;
        first->object = temp.object;
        first->tail = temp.tail;
    }

    offset += 0xB4;
    j++;

inner_test:
    count = *(s16 *)(map + 6);

    if (j < count - 1 - i) {
        goto inner_loop;
    }

    i++;

outer_test:
    if (i < *(s16 *)(map + 6)) {
        goto outer_loop;
    }

    node = *(u8 **)(map + 0x10);
    j = 0;

    while (j < *(s16 *)(map + 4)) {
        flags = *(u32 *)(node + 0xBC);
        firstPriority = 0;

        if (flags & 0x10) {
            firstPriority = 1;
        }

        if (flags & 0x80) {
            firstPriority += 2;
        }

        if (flags & 0x20000) {
            firstPriority += 0x10000;
        }

        if (flags & 0x800) {
            firstPriority += 0x20000;
        }

        if (flags & 0x2000) {
            firstPriority += 0x40000;
        }

        if (flags & 0x20) {
            firstPriority += 0x80000;
        }

        if (firstPriority >= 0x10000) {
            *(u32 *)(node + 0xBC) |= 1;
        } else {
            *(u32 *)(node + 0xBC) &= ~1U;
        }

        j++;
        node += 0xC0;
    }
}
#include "common.h"
extern f32 lbl_80368FD8;
extern u8 lbl_8026AB18[];
extern f32 lbl_80368FC4;
extern u8 lbl_802EFE20[64];
