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

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern f32 lbl_80368EE4;

#pragma global_optimizer off

#pragma global_optimizer off
/* Build a terrain-aligned 3x4 basis matrix from map tile corner heights at (x, y). */

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma global_optimizer on

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer off
/* Update map-entry world matrices; alternate half-ranges each frame, then transform visible entries. */

#pragma global_optimizer on

#pragma use_lmw_stmw on
#pragma opt_loop_invariants off
#pragma opt_peephole off

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma opt_peephole reset
#pragma opt_loop_invariants reset
#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma global_optimizer off
#pragma fp_contract off

#pragma fp_contract reset
#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer on

/* Set up GX for untextured POS+CLR0 map color overlays and load the camera view with a small Z bias. */

#pragma global_optimizer off

#pragma global_optimizer on

#pragma peephole on

typedef struct StringValueByte { u8 pad0[0xC]; u8 value; } StringValueByte;

extern u16 lbl_8026A9B0[40];
extern u16 lbl_802EFFC8[16];

extern s32 gGMaterialCurrent;
#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma peephole off

#pragma peephole on

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

/* Set up GX and draw a ground shadow for each visible unit. */

#pragma use_lmw_stmw on
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_lifetimes off

#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma opt_lifetimes reset
#pragma scheduling reset
#pragma optimization_level reset

#pragma scheduling on

/* Per-frame unit visual: update the model if drawable, and idle-spin mapAngle on the active phase. */

extern double lbl_80368FE0;
extern float lbl_80368FF8;
extern float lbl_80368FD8;

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

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

#pragma use_lmw_stmw on

#pragma opt_common_subs off

#pragma optimization_level 2

#pragma optimization_level reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma peephole off

#pragma peephole on

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma use_lmw_stmw on
static inline void *MapObj_GetOwner(void *base) {
    void *obj;
    if (*(u32 *)((u8 *)base + 8) & 0x20000000) {
        obj = *(void **)((u8 *)base + 0x34);
        if (obj != NULL) return obj;
    }
    return *(void **)((u8 *)base + 0x30);
}

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma scheduling off
#pragma global_optimizer off

#pragma global_optimizer on
#pragma scheduling on

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

#include "common.h"
extern f32 lbl_80368FD8;
extern u8 lbl_8026AB18[];
extern f32 lbl_80368FC4;
extern u8 lbl_802EFE20[64];

#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
static inline u32 MapObj_GetInheritFlag(u32 flags) {
    return (flags >> 28) & 1;
}

#pragma push
#pragma optimization_level 3

void fn_80053F68(void *arg0) {
    f32 fn_80059F64(f32, f32, f32, f32);
    void fn_8005F7E0(void *, u8, u8, u8);
    void fn_8005F7B0(void *, u8);
    void fn_8005E644(void *);
    void fn_80060060(void *);
    void fn_800609DC(void *);
    void fn_8006CAD4(void *);
    void fn_8000C188(void *);
    void fn_80053260(void *);
    void fn_800548E8(void *);
    void fn_80009D74(f32, f32, f32, f32);
    void fn_8000A174(s32, s32);
    void fn_80009B8C(u8);
    void fn_8000A248(void);
    void fn_8000A258(void);
    void fn_80007898(s32);
    void fn_80007340(void *, void *);
    void fn_80007884(void);
    u8 fn_800AA188(void);
    extern f32 lbl_80369084;
    extern f32 lbl_8036908C;
    extern f64 lbl_80369090;
    extern f32 lbl_803690C4;
    extern f32 lbl_803690C8;
    extern void fn_80054314;

    typedef struct { f32 x, y, z; } Vec3;
    u32 bit;
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
        flags = *(u32 *)((u8 *)inner + 8);
        bit = (flags >> 28) & 1;
        if (bit) {
            other = *(void **)((u8 *)arg0 + 0x18);
            if (other != 0) {
                *(u32 *)((u8 *)inner + 8) = flags | 0x10000000;
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
        }

        dst = *(void **)((u8 *)arg0 + 0x30);
        alpha = 0xFF;
        cnt = *(s8 *)((u8 *)dst + 3);
        if (cnt > 0) {
            *(s8 *)((u8 *)dst + 3) = (s8)(cnt - 1);
            dst = *(void **)((u8 *)arg0 + 0x30);
            alpha = (s32)fn_80059F64(lbl_80369084, lbl_803690C4, lbl_803690C8,
                                     (f32)*(s8 *)((u8 *)dst + 3));
            if (alpha == 0) {
                fn_8000C188(arg0);
            }
        }

        color = *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x38);
        fn_8005F7E0(gfx, ((u8 *)&color)[0], ((u8 *)&color)[1], ((u8 *)&color)[2]);
        fn_8005F7B0(gfx, (u8)((((u8 *)&color)[3] * alpha) / 255));
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
            fn_80053260(arg0);
        }

        fn_800609DC(gfx);

        inner = *(void **)((u8 *)arg0 + 0x30);
        if ((*(u32 *)((u8 *)inner + 8) & 8) == 0 &&
            (*(u8 *)((u8 *)*(void **)((u8 *)inner + 0x2C) + 4) & 3) == 0) {
            fn_8006CAD4(gfx);
        } else {
            fn_8000A258();
            inner = *(void **)((u8 *)arg0 + 0x30);
            fn_80009D74(lbl_80369084, lbl_80369084,
                        (f32)(s32)*(f32 *)((u8 *)inner + 0x1C), lbl_8036908C);
            fn_8000A174(0, 0x410);
            fn_80009B8C(0xFF);
            fn_8000A248();
            fn_80007898(0xB);
            fn_80007340(&fn_80054314, gfx);
            fn_80007884();
        }

        fn_800548E8(arg0);

        {
            void *p = *(void **)((u8 *)arg0 + 0x30);
            if ((*(u32 *)((u8 *)p + 8) & 4) == 0 && (*(u32 *)gfx & 0x10)) {
                b = ((u8 *)p)[4];
                if ((s8)b >= 0) {
                    ((u8 *)p)[4] = b - 1;
                } else {
                    fn_8000C188(arg0);
                }
            }
        }
    }
}
#pragma pop
