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
#pragma global_optimizer off
#pragma opt_lifetimes on

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
    s32 Archive_Load(void *);
    void *Archive_LoadFlags(void *, u32);
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
    void Light_CopyChannel(void *, void *);
    void fn_8006720C(void *);
    void fn_800675C8(s32);
    void *Fog_GetColor(void);
    void fn_80067480(void);
    void fn_80040B78(void *, u32);
    void *fn_80145EBC(void *);
    void DebugPrint(void *, ...);
    s64 __div2i(s64, s64);
    extern u8 lbl_802EFE20[];
    extern u8 lbl_8026A660[];
    extern const f32 lbl_80368F18;
    extern const f32 lbl_80368F1C;
    extern const f32 lbl_80368F10;
    extern const f32 lbl_80368F14;
    extern const f32 lbl_80368F20;
    extern const f32 lbl_80368F24;
    extern const f32 lbl_80368F28;
    extern const f32 lbl_80368EF4;
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

    char *p;
    char *dst;
    u8 c;
    u8 mode;
    u8 enabled;
    f32 scale;
    s32 i;
    void *entry;
    void *name;
    void *sub;
    void *tmp;
    u8 *bytes;
    s32 b;
    void *light;
    void *fog;
    char *buf;
    char *strBase;
    char *b0;
    char *b1;
    char *b2;
    char *b3;
    char *b4;
    char *b5;
    char *b6;
    char *b7;
    char *b8;
    s8 defLight;

    fn_80041254(arg0);
    dst = (char *)arg0 + 0x3C;
    p = arg1 + strlen(arg1);
    p--;
    while (p != arg1) {
        c = *--p;
        if ((s8)c == '/' || (s8)c == '\\') {
            p++;
            break;
        }
    }
    while ((s8)(c = *p) != 0) {
        if ((s8)c == '/' || (s8)c == '\\') {
            break;
        }
        *dst++ = *p++;
    }
    *dst = 0;

    t0 = OSGetTime();
    switch (((u8 *)arg0)[0x68]) {
    case 0: {
 s16 *header;
 void *cursor;
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x161);
        M2C_FIELD(arg0, s32 *, 8) = FileCache_Load(lbl_802EFE20);
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x169);
        M2C_FIELD(arg0, s32 *, 0xC) = Archive_Load(lbl_802EFE20);
        PSMTXRotRad(sp18, 0x58, lbl_80368F18);
        M2C_FIELD(arg0, f32 *, 0x6C) = lbl_80368F1C;
        PSMTXCopy(sp18, (u8 *)arg0 + 0x70);

        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x122);
        dst = (char *)lbl_802EFE20;
        if (FileCache_Probe(dst) != 0x8000) {
            M2C_FIELD(arg0, void **, 0x18) = Archive_LoadFlags(dst, 8);
        }
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x12D);
        dst = (char *)lbl_802EFE20;
        if (FileCache_Probe(dst) != 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x1C) = Archive_Load(dst);
        }
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x13A);
        dst = (char *)lbl_802EFE20;
        if (FileCache_Probe(dst) != 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x20) = Archive_Load(dst);
        }
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x147);
        dst = (char *)lbl_802EFE20;
        if (FileCache_Probe(dst) != 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x24) = Archive_Load(dst);
        }
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x154);
        dst = (char *)lbl_802EFE20;
        if (FileCache_Probe(dst) != 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x28) = Archive_Load(dst);
        }

        scale = lbl_80368F10;
        if (Res_GetByName(lbl_8026A660 + 0x171) != 0) {
            header = Hash_Lookup(lbl_8026A660 + 0x171);
            M2C_FIELD(arg0, s16 *, 0) = *header++;
            M2C_FIELD(arg0, s16 *, 2) = *header++;
            M2C_FIELD(arg0, s16 *, 4) = *header++;
            M2C_FIELD(arg0, s16 *, 6) = *header++;
            scale = lbl_80368F10 / fn_8001B84C(&header);
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
        buf = (char *)lbl_802EFE20;
        strBase = (char *)lbl_8026A660;
        b0 = buf; b1 = buf; b2 = buf; b3 = buf; b4 = buf;
        b5 = buf; b6 = buf; b7 = buf; b8 = buf;
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
            strcpy(buf, arg1);
            strcat(buf, name);
            strcat(buf, strBase + 0x193);
            M2C_FIELD(sub, s32 *, 0x40) = fn_80065EE8(b0);
            strcpy(b1, arg1);
            strcat(b2, name);
            strcat(b3, strBase + 0x196);
            M2C_FIELD(sub, s32 *, 0x48) = fn_8006CE14(b4);
            strcpy(b5, arg1);
            strcat(b6, strBase + 0x19A);
            strcat(b7, strBase + 0x1A2);
            if (FileCache_Exists(b8) != 0) {
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
            defLight = -0x1E;
            lbl_80367294 = defLight;
            lbl_80367295 = defLight;
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
            lbl_8036728C = (u8)((u8)((s8)bytes[1] + 1) & ((s32)(-b | b) >> 31));
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
        tmp = (char *)arg0 + 0x3C;
        if (tmp == 0) {
            lbl_80367AF6 = 0;
        } else {
            tmp = fn_80145EBC(tmp);
            if (tmp != 0) {
                lbl_80367AF6 = ((u8 *)tmp)[4];
            } else {
                lbl_80367AF6 = 0;
            }
        }
        lbl_80366E90 = 1;
        fn_8006805C(lbl_80368F10, lbl_80368F14);
        break;
    }
    case 1: {
 s16 *header;
 void *cursor;
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x1D0);
        M2C_FIELD(arg0, s32 *, 8) = FileCache_Load(lbl_802EFE20);
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x169);
        M2C_FIELD(arg0, s32 *, 0xC) = Archive_Load(lbl_802EFE20);
        PSMTXIdentity(sp18);
        M2C_FIELD(arg0, f32 *, 0x6C) = lbl_80368F20;
        PSMTXCopy(sp18, (u8 *)arg0 + 0x70);

        if (Res_GetByName(lbl_8026A660 + 0x1D7) != 0) {
            header = Hash_Lookup(lbl_8026A660 + 0x1D7);
            M2C_FIELD(arg0, s16 *, 0) = *header++;
            M2C_FIELD(arg0, s16 *, 2) = *header++;
            M2C_FIELD(arg0, s16 *, 4) = *header++;
            M2C_FIELD(arg0, s16 *, 6) = *header++;
            fn_8001B84C(&header);
        }
        if (Res_GetByName(lbl_8026A660 + 0x1E4) != 0) {
            bytes = (u8 *)Hash_Lookup(lbl_8026A660 + 0x1E4);
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
        cursor = Hash_Lookup(lbl_8026A660 + 0x1EE);
        M2C_FIELD(arg0, void **, 0x10) = Heap_AllocRaw(M2C_FIELD(arg0, s16 *, 4) * 0xC0);
        buf = (char *)lbl_802EFE20;
        strBase = (char *)lbl_8026A660;
        b0 = buf; b1 = buf; b2 = buf; b3 = buf; b4 = buf;
        b5 = buf; b6 = buf; b7 = buf; b8 = buf;
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
            strcpy(buf, arg1);
            strcat(buf, name);
            strcat(buf, strBase + 0x193);
            M2C_FIELD(sub, s32 *, 0x40) = fn_80065EE8(b0);
            strcpy(b1, arg1);
            strcat(b2, name);
            strcat(b3, strBase + 0x196);
            M2C_FIELD(sub, s32 *, 0x48) = fn_8006CE14(b4);
            strcpy(b5, arg1);
            strcat(b6, strBase + 0x19A);
            strcat(b7, strBase + 0x1A2);
            if (FileCache_Exists(b8) != 0) {
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
        fn_80045D50(arg0, lbl_8026A660 + 0x1FC);

        if (Res_GetByName(lbl_8026A660 + 0x20A) != 0) {
            bytes = (u8 *)Hash_Lookup(lbl_8026A660 + 0x20A);
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
            defLight = -0x1E;
            lbl_80367294 = defLight;
            lbl_80367295 = defLight;
            (&lbl_8036729C)[0] = 0x80;
            (&lbl_8036729C)[1] = 0x80;
            (&lbl_8036729C)[2] = 0x80;
            (&lbl_80367298)[0] = 0xFF;
            (&lbl_80367298)[1] = 0xFF;
            (&lbl_80367298)[2] = 0xFF;
        }
        if (Res_GetByName(lbl_8026A660 + 0x214) != 0) {
            bytes = (u8 *)Hash_Lookup(lbl_8026A660 + 0x214);
            b = (s8)bytes[0] != 0;
            lbl_8036728C = (u8)((u8)((s8)bytes[1] + 1) & ((s32)(-b | b) >> 31));
            lbl_8036728D = bytes[2];
            lbl_8036728E = bytes[3];
            (&lbl_80367290)[0] = bytes[4];
            (&lbl_80367290)[1] = bytes[5];
            (&lbl_80367290)[2] = bytes[6];
        } else {
            lbl_8036728C = 0;
        }
        lbl_80366E90 = 0xF;
        fn_8006805C(lbl_80368F24, lbl_80368F28);
        break;
    }
    }

    FileCache_Load(lbl_8026A660 + 0x112);
    M2C_FIELD(arg0, s32 *, 0x38) = fn_8006D948(lbl_8026A660 + 0x21C);
    M2C_FIELD(arg0, s32 *, 0x2C) = fn_800EE490();
    M2C_FIELD(arg0, s32 *, 0x30) = fn_80123BA8();
    M2C_FIELD(arg0, s32 *, 0x64) |= 0x40000000;
    fn_8012391C(M2C_FIELD(arg0, s32 *, 0x30));
    switch (((u8 *)arg0)[0x68]) { case 0:
        fn_800C1BDC();
        fn_800C1984();
        enabled = 1;
        mode = gMapBlendMode - 1;
        if (((u32)((1U | ~mode) - ((u32)(1 - mode) >> 1)) >> 31) == 0) {
            enabled = 0;
        }
        if (enabled) {
            fn_8014716C(1);
        } else {
            fn_8014716C(0);
        }
    break;
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
    Light_CopyChannel(Light_GetChannel(0), Light_GetChannel(2));
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
    fn_80040B78(arg0, (u32)((char *)arg0 + 0x3C));
    DebugPrint(lbl_8026A660 + 0x22C, __div2i(OSGetTime() - t0, (s64)((*(u32 *)0x800000F8 >> 2) / 1000)));
}
