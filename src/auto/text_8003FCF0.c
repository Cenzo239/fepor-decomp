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

void *fn_8003FCF0(void *arg0) {
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

    if (ok) {
        return ptr;
    }

    ptr = (u8 *)ptr - 0x20;

    for (k = 0; k < 7; k++) {
        if ((s8)((u8 *)ptr)[0x18 + k] != ref[k]) {
            ok = 0;
            goto done2;
        }
    }
    ok = 1;
done2:

    if (ok) {
        return ptr;
    }
    return 0;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma push
#pragma optimization_level 2
void fn_8003FED8(u8 *arg0) {
    void Hash_Remove(void *);
    u32 j;
    u8 *obj;
    u32 *p28;
    u32 *p30;
    u8 *p29;
    u32 *scan;
    u32 count;
    u32 i;
    void *da;

    obj = arg0;
    j = 0;
    {
        u32 t4 = *(u32 *)(arg0 + 4);
        u32 tC = *(u32 *)(arg0 + 0xC);
        u32 t8 = *(u32 *)(arg0 + 8);
        u32 t10 = *(u32 *)(obj + 0x10);
        p30 = (u32 *)(obj + (t4 & ~3u));
        t8 <<= 2;
        tC <<= 3;
        t10 <<= 3;
        p30 = (u32 *)((u8 *)p30 + 0x20);
        p28 = (u32 *)((u8 *)p30 + t8);
        p29 = (u8 *)p28 + tC + t10;
    }
    while (j < *(u32 *)(obj + 0xC)) {
        scan = p30;
        count = *(u32 *)(obj + 8);
        da = p29 + p28[1];
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
#pragma pop
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

void fn_80040028(void *arg0, void *arg1)
{
 extern u8 *gMap;
 void fn_80044450(void *, s32);
 u8 *obj;
 u8 *list[64];
 u32 flags;
 s32 count;
 s32 i;
 arg0=gMap;
 if(arg0) {
  count=0;
  for(i=0;i<*(s16 *)((u8 *)arg0+6);i++) {
   obj=*(u8 **)((u8 *)arg0+0x14)+i*0xB4;
   flags=*(u32 *)(*(u8 **)(obj+0x10)+0xBC);
   if(MapObj_HasActionFlag(flags) && !MapObj_HasBlockedAction(flags) &&
      ((u8)(u32)arg1 || !(flags&0x1000)) && !MapObj_GetState(obj)) {
       list[count++]=obj;
       obj[2]|=2;
   }
  }
  fn_80044450(arg0,0);
  for(i=0;i<count;i++) list[i][2]&=~2;
 }
}

void fn_8004022C(void) {
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
    extern s32 gGameFlags;
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
    u8 flags;
    f32 f29v, f28v, f31v, f30v;
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
                        f30v = (f32)(s8)ent[1] + lbl_80368EE4;
                        f31v = *(f32 *)(ent + 8) + lbl_80368EE4;
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

void *fn_800408A8(s32 which) {
    void fn_80040B78(void *, s32);
    extern u8 lbl_802EFE60[];
    extern u8 lbl_802EFF14[];
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
    union { u8 bytes[12]; u32 words[3]; } colors0;
    union { u8 bytes[12]; u32 words[3]; } colors1;

    switch (which) {
    case 0: {
        u8 c11, c10, c9, c8, c7, c6, c5, c4, c3, c2, c1, c0;
        u8 *p90, *p9c, *p98, *self;
        s32 three, one, zero;
        colors0.words[0] = lbl_80368ED0;
        zero = 0;
        colors0.words[1] = lbl_80368ED4;
        self = lbl_802EFE60;
        colors0.words[2] = lbl_80368ED8;
        one = 1;
        three = 3;
        c0 = colors0.bytes[0];
        p98 = lbl_80367298;
        p9c = lbl_8036729C;
        c1 = colors0.bytes[1];
        p90 = lbl_80367290;
        *(u32 *)(self + 0xA4) = zero;
        c2 = colors0.bytes[2];
        c3 = colors0.bytes[3];
        c4 = colors0.bytes[4];
        c5 = colors0.bytes[5];
        c6 = colors0.bytes[6];
        c7 = colors0.bytes[7];
        c8 = colors0.bytes[8];
        c9 = colors0.bytes[9];
        c10 = colors0.bytes[10];
        c11 = colors0.bytes[11];
        *(u32 *)(self + 0x64) = zero;
        *(u32 *)(self + 0x8) = zero;
        *(u32 *)(self + 0xC) = zero;
        *(u32 *)(self + 0x10) = zero;
        *(u32 *)(self + 0x14) = zero;
        *(u32 *)(self + 0x18) = zero;
        *(u32 *)(self + 0x1C) = zero;
        *(u32 *)(self + 0x20) = zero;
        *(u32 *)(self + 0x24) = zero;
        *(u32 *)(self + 0x28) = zero;
        *(u32 *)(self + 0x2C) = zero;
        *(u32 *)(self + 0x30) = zero;
        *(u32 *)(self + 0xA4) = zero;
        *(u32 *)(self + 0x34) = zero;
        lbl_80367288 = one;
        gBattleSkyIndex = zero;
        gMapBlendMode = three;
        lbl_8036728C = zero;
        lbl_8036728D = zero;
        lbl_8036728E = zero;
        lbl_80367294 = zero;
        lbl_80367295 = zero;
        p98[0] = c0;
        p98[1] = c1;
        p98[2] = c2;
        p98[3] = c3;
        p9c[0] = c4;
        p9c[1] = c5;
        p9c[2] = c6;
        p9c[3] = c7;
        p90[0] = c8;
        p90[1] = c9;
        p90[2] = c10;
        p90[3] = c11;
        lbl_8036728B = zero;
        fn_80040B78(self, 0);
        self = lbl_802EFE60;
        lbl_80367AF6 = 0;
        self[0x68] = 0;
        return self;
    }
    case 1: {
        u8 c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11;
        u8 *self, *p98, *p9c, *p90;
        s32 zero, one, three;
        colors1.words[0] = lbl_80368ED0;
        zero = 0;
        colors1.words[1] = lbl_80368ED4;
        self = lbl_802EFF14;
        colors1.words[2] = lbl_80368ED8;
        one = 1;
        three = 3;
        c0 = colors1.bytes[0];
        p98 = lbl_80367298;
        p9c = lbl_8036729C;
        c1 = colors1.bytes[1];
        p90 = lbl_80367290;
        *(u32 *)(self + 0xA4) = zero;
        c2 = colors1.bytes[2];
        c3 = colors1.bytes[3];
        c4 = colors1.bytes[4];
        c5 = colors1.bytes[5];
        c6 = colors1.bytes[6];
        c7 = colors1.bytes[7];
        c8 = colors1.bytes[8];
        c9 = colors1.bytes[9];
        c10 = colors1.bytes[10];
        c11 = colors1.bytes[11];
        *(u32 *)(self + 0x64) = zero;
        *(u32 *)(self + 0x8) = zero;
        *(u32 *)(self + 0xC) = zero;
        *(u32 *)(self + 0x10) = zero;
        *(u32 *)(self + 0x14) = zero;
        *(u32 *)(self + 0x18) = zero;
        *(u32 *)(self + 0x1C) = zero;
        *(u32 *)(self + 0x20) = zero;
        *(u32 *)(self + 0x24) = zero;
        *(u32 *)(self + 0x28) = zero;
        *(u32 *)(self + 0x2C) = zero;
        *(u32 *)(self + 0x30) = zero;
        *(u32 *)(self + 0xA4) = zero;
        *(u32 *)(self + 0x34) = zero;
        lbl_80367288 = one;
        gBattleSkyIndex = zero;
        gMapBlendMode = three;
        lbl_8036728C = zero;
        lbl_8036728D = zero;
        lbl_8036728E = zero;
        lbl_80367294 = zero;
        lbl_80367295 = zero;
        p98[0] = c0;
        p98[1] = c1;
        p98[2] = c2;
        p98[3] = c3;
        p9c[0] = c4;
        p9c[1] = c5;
        p9c[2] = c6;
        p9c[3] = c7;
        p90[0] = c8;
        p90[1] = c9;
        p90[2] = c10;
        p90[3] = c11;
        lbl_8036728B = zero;
        fn_80040B78(self, 0);
        self = lbl_802EFF14;
        lbl_80367AF6 = 0;
        self[0x68] = 1;
        return self;
    }
    }
    return 0;
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
    void Light_CopyChannel(void *, void *); void fn_8006720C(void *);
    void fn_800675C8(s32); void *Fog_GetColor(void); void fn_80067480(void);
    extern u8 gMapBlendMode, lbl_80367294, lbl_80367295, lbl_8036729C, lbl_80367298, lbl_8036728C, lbl_8036728D, lbl_8036728E, lbl_80367290;
    extern f32 lbl_80368EF4;
    u8 enabled;
    u8 *light;
    u8 *fog;
    fn_8012391C(M2C_FIELD(arg0, void **, 0x30));
    switch (M2C_FIELD(arg0, u8 *, 0x68)) {
    case 0:
        fn_800C1BDC();
        fn_800C1984();
        enabled = (gMapBlendMode == 1 || gMapBlendMode == 2);
        if (enabled) fn_8014716C(1); else fn_8014716C(0);
        break;
    }
    fn_80067460(0); fn_80066F64();
    light = Light_GetChannel(0);
    *(f32 *)(light + 0x24) = (f32)(s8)lbl_80367294;
    *(f32 *)(light + 0x28) = (f32)(s8)lbl_80367295;
    light[0] = (&lbl_8036729C)[0]; light[1] = (&lbl_8036729C)[1]; light[2] = (&lbl_8036729C)[2];
    light[4] = (&lbl_80367298)[0]; light[5] = (&lbl_80367298)[1]; light[6] = (&lbl_80367298)[2];
    light = Light_GetChannel(2); Light_CopyChannel(Light_GetChannel(0), light);
    fn_8006720C((u8 *)arg0 + 0x70);
    fn_800675C8(0); fog = Fog_GetColor(); fn_80067480();
    fog[0] = lbl_8036728C;
    *(f32 *)(fog + 4) = 5.0f * ((f32)(s8)lbl_8036728D * M2C_FIELD(arg0, f32 *, 0x6C));
    *(f32 *)(fog + 8) = 5.0f * ((f32)(s8)lbl_8036728E * M2C_FIELD(arg0, f32 *, 0x6C));
    fog[1] = (&lbl_80367290)[0]; fog[2] = (&lbl_80367290)[1]; fog[3] = (&lbl_80367290)[2];
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
#pragma global_optimizer off
#pragma opt_lifetimes on
