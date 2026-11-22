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
