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

void fn_80054808(void *arg0) {
    M2C_UNK Process_ClearFunc(void *);
    u8 GActor_CheckResources(s32);
    if (GActor_CheckResources(*M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 **, 0x2C)) != 0) {
        Process_ClearFunc(arg0);
    }
}
