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

void *fn_800330F8(void) {
    extern u16 gMapUiStrs[];
    return (u8 *)gMapUiStrs + 0x14F;
}

#pragma cplusplus on
extern "C" void Prim2D_SetColorByte(u8);
extern "C" void Prim2D_SetTransform(f32, f32, f32, f32);
extern "C" void Prim2D_PrepareTex(void);
extern "C" void Prim2D_Begin(void);
extern "C" s32 UnitRef_GetUnit(u32);
extern "C" void UnitInfo_DrawStatus(s32);
extern "C" void UnitInfo_Draw(void *win, void *slot) {
    /* Draw the status unit-info panel for the unit in slot. */
    extern f32 gUnitInfoDrawScale;
    extern f32 gUnitInfoDrawDepth;
    struct Obj {
        u8 pad[4];
        virtual void getPos(s32 *, s32 *, s32 *) = 0;
    };
    s32 x;
    s32 y;
    s32 alpha;

    if (M2C_FIELD(slot, u32 *, 0x40) != 0) {
        ((Obj *)win)->getPos(&x, &y, &alpha);
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0x30), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_SetColorByte((u8)alpha);
        Prim2D_PrepareTex();
        UnitInfo_DrawStatus(UnitRef_GetUnit(M2C_FIELD(slot, u32 *, 0x40)));
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}
#pragma cplusplus reset

/* Set brave-weapon flag (bit 3) on count*2 hit-table entries from the current cursor. */
void BattleHit_SetBraveFlags(u8 *hitTbl, s32 count) {
    s32 n;
    s32 i;

    n = count * 2;
    for (i = 0; i < n; i++) {
        ((u16 *)hitTbl)[hitTbl[0x60] + i + 0x10] |= 8;
    }
}

#pragma global_optimizer off
#pragma opt_strength_reduction off
void fn_8003333C(u8 *arg0, s32 arg1) {
    s32 t3;
    s32 t2;
    s32 t1;
    s32 idx;
    s32 t4;
    u8 n;

    n = arg0[0x60];
    t1 = arg1 + 1;
    t2 = arg1 + 2;
    t3 = arg1 + 3;
    idx = n + arg1;
    t4 = arg1 + 4;
    idx = (s32)(arg0 + (idx << 1));
    *(u16 *)(idx + 0x20) |= 1;

    n = arg0[0x60];
    idx = n + t1;
    t1 = (s32)(arg0 + (idx << 1));
    *(u16 *)(t1 + 0x20) |= 1;

    n = arg0[0x60];
    idx = n + t2;
    t2 = (s32)(arg0 + (idx << 1));
    *(u16 *)(t2 + 0x20) |= 1;

    n = arg0[0x60];
    idx = n + t3;
    t3 = (s32)(arg0 + (idx << 1));
    *(u16 *)(t3 + 0x20) |= 1;

    n = arg0[0x60];
    idx = n + t4;
    arg0 = arg0 + (idx << 1);
    *(u16 *)(arg0 + 0x20) |= 1;
}
#pragma opt_strength_reduction reset
#pragma global_optimizer reset
void fn_800333DC(u8 *arg0, s32 arg1) {
    u8 *p;
    u16 v;

    p = arg0 + ((arg0[0x60] + arg1) << 1);
    v = *(u16 *)(p + 0x20);
    v |= 0x4002;
    *(u16 *)(p + 0x20) = v;

    p = arg0 + ((arg0[0x60] + arg1) << 1);
    v = *(u16 *)(p + 0x22);
    v |= 4;
    *(u16 *)(p + 0x22) = v;
}

void fn_80033418(s16 *script) {
    void DebugPrint(void *, ...);
    extern u8 lbl_80269750[];
    extern u8 gUnits[];
    u32 i;
    s8 param;
    u8 cmd;
    u8 *base;
    u8 *unit;

    *script = 0;
    DebugPrint(lbl_80269750 + 0x1d);
    i = 0;

    while ((cmd = *((u8 *)script + (*script * 4) + 4)) != 0) {
        base = (u8 *)script + (*script * 4);
        switch (base[4]) {
        case 3:
            DebugPrint(lbl_80269750 + 0x2b, (s8)*(s16 *)(base + 6));
            break;
        case 4:
            DebugPrint(lbl_80269750 + 0x51, (s8)*(s16 *)(base + 6));
            break;
        case 5:
            DebugPrint(lbl_80269750 + 0x73, (s8)*(s16 *)(base + 6));
            break;
        case 6:
            DebugPrint(lbl_80269750 + 0x97, (s8)*(s16 *)(base + 6));
            break;
        case 7:
            DebugPrint(lbl_80269750 + 0xbb, (s8)*(s16 *)(base + 6));
            break;
        case 8:
            DebugPrint(lbl_80269750 + 0xdf, (s8)*(s16 *)(base + 6));
            break;
        case 9:
            param = (s8)*(s16 *)(base + 6);
            if (param == 0) {
                DebugPrint(lbl_80269750 + 0x103);
            }
            param = (s8)*(s16 *)((u8 *)script + (*script * 4) + 6);
            if (param > 0) {
                DebugPrint(lbl_80269750 + 0x129, param);
            }
            param = (s8)*(s16 *)((u8 *)script + (*script * 4) + 6);
            if (param < 0) {
                DebugPrint(lbl_80269750 + 0x147, -param);
            }
            break;
        case 0xA:
            DebugPrint(lbl_80269750 + 0x169);
            break;
        case 0xB:
            DebugPrint(lbl_80269750 + 0x18d);
            break;
        case 0x1B:
            DebugPrint(lbl_80269750 + 0x1a7);
            break;
        case 0x1C:
            DebugPrint(lbl_80269750 + 0x1c3);
            break;
        case 0xF:
            DebugPrint(lbl_80269750 + 0x1e3, (s8)*(s16 *)(base + 6));
            break;
        case 0x10:
            DebugPrint(lbl_80269750 + 0x209, (s8)*(s16 *)(base + 6));
            break;
        case 0x11:
            DebugPrint(lbl_80269750 + 0x22b, (s8)*(s16 *)(base + 6));
            break;
        case 0x12:
            DebugPrint(lbl_80269750 + 0x24f, (s8)*(s16 *)(base + 6));
            break;
        case 0x13:
            DebugPrint(lbl_80269750 + 0x273, (s8)*(s16 *)(base + 6));
            break;
        case 0x14:
            DebugPrint(lbl_80269750 + 0x297, (s8)*(s16 *)(base + 6));
            break;
        case 0x15:
            param = (s8)*(s16 *)(base + 6);
            if (param == 0) {
                DebugPrint(lbl_80269750 + 0x2bb);
            }
            param = (s8)*(s16 *)((u8 *)script + (*script * 4) + 6);
            if (param > 0) {
                DebugPrint(lbl_80269750 + 0x2e1, param);
            }
            param = (s8)*(s16 *)((u8 *)script + (*script * 4) + 6);
            if (param < 0) {
                DebugPrint(lbl_80269750 + 0x2ff, -param);
            }
            break;
        case 0x16:
            DebugPrint(lbl_80269750 + 0x321);
            break;
        case 0x17:
            DebugPrint(lbl_80269750 + 0x345);
            break;
        case 0x1D:
            DebugPrint(lbl_80269750 + 0x35f);
            break;
        case 0x1E:
            DebugPrint(lbl_80269750 + 0x387);
            break;
        case 0x1F:
            DebugPrint(lbl_80269750 + 0x3af);
            break;
        case 0x20:
            DebugPrint(lbl_80269750 + 0x3e1);
            break;
        case 0x21:
            DebugPrint(lbl_80269750 + 0x3f9);
            break;
        case 0x22:
            DebugPrint(lbl_80269750 + 0x421);
            break;
        case 0xC:
            DebugPrint(lbl_80269750 + 0x431);
            break;
        case 0x18:
            DebugPrint(lbl_80269750 + 0x44b);
            break;
        case 0x23:
            DebugPrint(lbl_80269750 + 0x465);
            break;
        case 0x24:
            DebugPrint(lbl_80269750 + 0x47d);
            break;
        case 0x25:
            DebugPrint(lbl_80269750 + 0x495);
            break;
        case 0x26:
            DebugPrint(lbl_80269750 + 0x4ad);
            break;
        case 0x27:
            DebugPrint(lbl_80269750 + 0x4c3);
            break;
        case 0x28:
            DebugPrint(lbl_80269750 + 0x4d9);
            break;
        case 0x29:
            DebugPrint(lbl_80269750 + 0x4f3);
            break;
        case 0x2A:
            DebugPrint(lbl_80269750 + 0x50d);
            break;
        case 0x2B:
            DebugPrint(lbl_80269750 + 0x523);
            break;
        case 0x2C:
            DebugPrint(lbl_80269750 + 0x539);
            break;
        case 0x2D:
            DebugPrint(lbl_80269750 + 0x55f);
            break;
        case 0x2E:
            DebugPrint(lbl_80269750 + 0x575);
            break;
        case 0x2F:
            DebugPrint(lbl_80269750 + 0x58f);
            break;
        case 0x30:
            DebugPrint(lbl_80269750 + 0x5a7);
            break;
        case 0x31:
            DebugPrint(lbl_80269750 + 0x5bd);
            break;
        case 0x32:
            DebugPrint(lbl_80269750 + 0x5d5);
            break;
        case 0x33:
            DebugPrint(lbl_80269750 + 0x5f1);
            break;
        case 0x34:
            DebugPrint(lbl_80269750 + 0x607);
            break;
        case 0x35:
            DebugPrint(lbl_80269750 + 0x61d);
            break;
        case 0x36:
            DebugPrint(lbl_80269750 + 0x633);
            break;
        case 0x37:
            DebugPrint(lbl_80269750 + 0x64b);
            break;
        case 0x38:
            DebugPrint(lbl_80269750 + 0x663);
            break;
        case 0x39:
            DebugPrint(lbl_80269750 + 0x679);
            break;
        case 0x3A:
            DebugPrint(lbl_80269750 + 0x69b);
            break;
        case 0x3B:
            DebugPrint(lbl_80269750 + 0x6c1);
            break;
        case 0x3C:
            DebugPrint(lbl_80269750 + 0x6db);
            break;
        case 0x3D:
            DebugPrint(lbl_80269750 + 0x6ef);
            break;
        case 0x3E:
            DebugPrint(lbl_80269750 + 0x709, (s8)*(s16 *)(base + 6));
            break;
        case 0x3F:
            DebugPrint(lbl_80269750 + 0x729, (s8)*(s16 *)(base + 6));
            break;
        case 0x40:
            DebugPrint(lbl_80269750 + 0x745, (s8)*(s16 *)(base + 6));
            break;
        case 0x41:
            DebugPrint(lbl_80269750 + 0x75d);
            break;
        case 0x42:
            DebugPrint(lbl_80269750 + 0x777);
            break;
        case 0x43:
            DebugPrint(lbl_80269750 + 0x791, (s8)*(s16 *)(base + 6));
            break;
        case 0x44:
            DebugPrint(lbl_80269750 + 0x7a2, (s8)*(s16 *)(base + 6));
            break;
        case 0x45:
            DebugPrint(lbl_80269750 + 0x7b1);
            break;
        case 0x46:
            DebugPrint(lbl_80269750 + 0x7c0, (s8)*(s16 *)(base + 6));
            break;
        case 0x47:
            DebugPrint(lbl_80269750 + 0x7d0, (s8)*(s16 *)(base + 6));
            break;
        case 0x48:
            DebugPrint(lbl_80269750 + 0x7e0, (s8)*(s16 *)(base + 6));
            break;
        case 0x49:
            DebugPrint(lbl_80269750 + 0x7f0);
            break;
        case 0x4A:
            DebugPrint(lbl_80269750 + 0x800);
            break;
        case 0x4B:
            DebugPrint(lbl_80269750 + 0x810, (s8)*(s16 *)(base + 6));
            break;
        case 0x4C:
            DebugPrint(lbl_80269750 + 0x820, (s8)*(s16 *)(base + 6));
            break;
        case 0x4D:
            DebugPrint(lbl_80269750 + 0x830);
            break;
        case 0x4E:
            DebugPrint(lbl_80269750 + 0x840);
            break;
        case 0x4F:
            DebugPrint(lbl_80269750 + 0x850);
            break;
        case 0x50:
            DebugPrint(lbl_80269750 + 0x860);
            break;
        case 0x51:
            DebugPrint(lbl_80269750 + 0x870);
            break;
        case 0x52:
            DebugPrint(lbl_80269750 + 0x880);
            break;
        case 0x53:
            DebugPrint(lbl_80269750 + 0x890);
            break;
        case 0x54:
            DebugPrint(lbl_80269750 + 0x8a0);
            break;
        case 0x55:
            DebugPrint(lbl_80269750 + 0x8b0);
            break;
        case 0x56:
            DebugPrint(lbl_80269750 + 0x8c0);
            break;
        case 0x57:
            DebugPrint(lbl_80269750 + 0x8d0);
            break;
        case 0x19:
            param = (s8)*(s16 *)(base + 6);
            if ((u8)param != 0) {
                unit = gUnits + ((u8)param - 1) * 0x280;
            } else {
                unit = 0;
            }
            DebugPrint(lbl_80269750 + 0x8e0, unit);
            break;
        case 0x1A:
            i = 0;
            do {
                unit = gUnits + i * 0x280;
                if (*(u32 *)(unit + 0x188) != 0) {
                    DebugPrint(lbl_80269750 + 0x900, i, unit);
                }
                i += 1;
            } while (i < 0x9F);
            break;
        case 0xD:
        case 0xE:
            break;
        }
        *script = (s16)(*script + 1);
    }
}

#pragma opt_strength_reduction reset
void fn_80033E70(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x400), s16 *, 2) = (s16) (M2C_FIELD(arg0, s16 *, 0) - M2C_FIELD(arg0, s16 *, 2));
    M2C_FIELD(arg0, void **, 0x400) = NULL;
}

void fn_80033E90(void *arg0, s32 arg1) {
    s8 fn_80033F18(void *, s32);
    s8 ret;
    u8 *e;

    *(void **)((u8 *)arg0 + 0x400) = (u8 *)arg0 + *(s16 *)arg0 * 4 + 4;
    ret = fn_80033F18(arg0, arg1);
    e = (u8 *)arg0 + *(s16 *)arg0 * 4 + 4;
    *e = ret;
    *(s16 *)(e + 2) = 0;
    *(s16 *)arg0 = *(s16 *)arg0 + 1;
    e = (u8 *)arg0 + *(s16 *)arg0 * 4 + 4;
    *e = 0;
    *(s16 *)(e + 2) = 0;
    *(s16 *)((u8 *)arg0 + 2) = *(s16 *)arg0;
}

s32 fn_80033F18(void *self, s32 code) {
    u8 c = (u8)code;

    if (c < 0x58) {
        return code;
    }
    if (((u8 *)self)[0x404] == 0) {
        switch (c - 0x59) {
        case 0: return 3;
        case 1: return 4;
        case 2: return 5;
        case 3: return 6;
        case 4: return 7;
        case 5: return 8;
        case 6: return 9;
        case 7: return 0xF;
        case 8: return 0x10;
        case 9: return 0x11;
        case 10: return 0x12;
        case 11: return 0x13;
        case 12: return 0x14;
        case 13: return 0x15;
        }
    } else {
        switch (c - 0x59) {
        case 0: return 0xF;
        case 1: return 0x10;
        case 2: return 0x11;
        case 3: return 0x12;
        case 4: return 0x13;
        case 5: return 0x14;
        case 6: return 0x15;
        case 7: return 3;
        case 8: return 4;
        case 9: return 5;
        case 10: return 6;
        case 11: return 7;
        case 12: return 8;
        case 13: return 9;
        }
    }
    return 0;
}

#pragma global_optimizer off
void BattleAnim_Queue(s16 *arg0, s32 arg1, s8 arg2) {
    s8 fn_80033F18(s16 *, s32);
    u8 *entry;
    s8 ret;
    s32 p;

    ret = fn_80033F18(arg0, arg1);
    entry = (u8 *)arg0 + (*arg0 << 2) + 4;
    *entry = ret;
    *(s16 *)(entry + 2) = arg2;
    (*arg0)++;
    p = *arg0 << 2;
    p = p + 4;
    p = (s32)arg0 + p;
    *(u8 *)p = 0;
    *(s16 *)(p + 2) = 0;
}
#pragma global_optimizer on
void fn_800340E4(s16 *arg0) {
    *arg0 = 0;
}

void fn_800340F0(void *arg0) {
    s32 zero;
    s16 idx;
    u8 *p;

    zero = 0;
    *(u8 *)((u8 *)arg0 + 0x404) = zero;
    *(s16 *)((u8 *)arg0 + 0) = zero;
    *(s16 *)((u8 *)arg0 + 2) = zero;
    *(s32 *)((u8 *)arg0 + 0x400) = zero;
    idx = *(s16 *)((u8 *)arg0 + 0);
    p = (u8 *)arg0 + (idx * 4) + 4;
    *p = zero;
    *(s16 *)(p + 2) = zero;
}

void fn_80034120(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x60) = (u8) (M2C_FIELD(arg0, u8 *, 0x60) + 1);
}

#pragma use_lmw_stmw on
void fn_80034130(void *arg0, void *arg1) {
    u8 Status_Test(void *, s32);
    void *fn_80037C20(void *);
    u8 Rand_Chance(s16);
    s32 Unit_GetHp(void *);
    s32 Unit_GetStr(void *);
    s32 Unit_GetMag(void *);
    s32 Unit_GetSkl(void *);
    s32 Unit_GetSpd(void *);
    s32 Unit_GetLck(void *);
    s32 Unit_GetDef(void *);
    s32 Unit_GetRes(void *);
    void BattleAnim_Queue(void *, s32);

    struct { s16 v[8]; } gr;
    u8 flag;
    u8 *cls;
    void **slot;
    u8 *bonus;
    s16 v;
    u8 g;
    s8 excess;
    s32 stat;
    u8 *cap;

    flag = Status_Test((u8 *)arg0 + 0x1BC, 0x4B);
    cls = *(u8 **)((u8 *)arg0 + 0x188);
    gr.v[0] = (s16)cls[0x25];
    gr.v[1] = (s16)cls[0x26];
    gr.v[2] = (s16)cls[0x27];
    gr.v[3] = (s16)cls[0x28];
    gr.v[4] = (s16)cls[0x29];
    gr.v[5] = (s16)cls[0x2A];
    gr.v[6] = (s16)cls[0x2B];
    gr.v[7] = (s16)cls[0x2C];
    slot = (void **)fn_80037C20(arg0);
    if (slot != NULL) {
        bonus = (u8 *)slot[0];
        if (bonus != NULL) {
            gr.v[0] += (s8)bonus[0x2A];
            gr.v[1] += (s8)bonus[0x2B];
            gr.v[2] += (s8)bonus[0x2C];
            gr.v[3] += (s8)bonus[0x2D];
            gr.v[4] += (s8)bonus[0x2E];
            gr.v[5] += (s8)bonus[0x2F];
            gr.v[6] += (s8)bonus[0x30];
            gr.v[7] += (s8)bonus[0x31];
        }
    }

    *(u8 *)((u8 *)arg0 + 0x2DE) = 0;
    *(u8 *)((u8 *)arg0 + 0x2DD) = 0;
    *(u8 *)((u8 *)arg0 + 0x2DC) = 0;
    *(u8 *)((u8 *)arg0 + 0x2DB) = 0;
    *(u8 *)((u8 *)arg0 + 0x2DA) = 0;
    *(u8 *)((u8 *)arg0 + 0x2D9) = 0;
    *(u8 *)((u8 *)arg0 + 0x2D8) = 0;
    *(u8 *)((u8 *)arg0 + 0x2D7) = 0;

    g = 0;
    v = gr.v[0];
    if (v >= 0x64) {
        v -= 0x64;
        g = 1;
    }
    if ((s16)v >= 0x64) {
        v -= 0x64;
        g += 1;
    }
    if (flag != 0) {
        if (Rand_Chance(v) != 0 || Rand_Chance(v) != 0) {
            g += 1;
        }
    } else if (Rand_Chance(v) != 0) {
        g += 1;
    }
    *(u8 *)((u8 *)arg0 + 0x2D7) = g;

    g = 0;
    v = gr.v[1];
    if (v >= 0x64) {
        g = 1;
        v -= 0x64;
    }
    if ((s16)v >= 0x64) {
        v -= 0x64;
        g += 1;
    }
    if (flag != 0) {
        if (Rand_Chance(v) != 0 || Rand_Chance(v) != 0) {
            g += 1;
        }
    } else if (Rand_Chance(v) != 0) {
        g += 1;
    }
    *(u8 *)((u8 *)arg0 + 0x2D8) = g;

    g = 0;
    v = gr.v[2];
    if (v >= 0x64) {
        g = 1;
        v -= 0x64;
    }
    if ((s16)v >= 0x64) {
        v -= 0x64;
        g += 1;
    }
    if (flag != 0) {
        if (Rand_Chance(v) != 0 || Rand_Chance(v) != 0) {
            g += 1;
        }
    } else if (Rand_Chance(v) != 0) {
        g += 1;
    }
    *(u8 *)((u8 *)arg0 + 0x2D9) = g;

    g = 0;
    v = gr.v[3];
    if (v >= 0x64) {
        g = 1;
        v -= 0x64;
    }
    if ((s16)v >= 0x64) {
        v -= 0x64;
        g += 1;
    }
    if (flag != 0) {
        if (Rand_Chance(v) != 0 || Rand_Chance(v) != 0) {
            g += 1;
        }
    } else if (Rand_Chance(v) != 0) {
        g += 1;
    }
    *(u8 *)((u8 *)arg0 + 0x2DA) = g;

    g = 0;
    v = gr.v[4];
    if (v >= 0x64) {
        g = 1;
        v -= 0x64;
    }
    if ((s16)v >= 0x64) {
        v -= 0x64;
        g += 1;
    }
    if (flag != 0) {
        if (Rand_Chance(v) != 0 || Rand_Chance(v) != 0) {
            g += 1;
        }
    } else if (Rand_Chance(v) != 0) {
        g += 1;
    }
    *(u8 *)((u8 *)arg0 + 0x2DB) = g;

    g = 0;
    v = gr.v[5];
    if (v >= 0x64) {
        g = 1;
        v -= 0x64;
    }
    if ((s16)v >= 0x64) {
        v -= 0x64;
        g += 1;
    }
    if (flag != 0) {
        if (Rand_Chance(v) != 0 || Rand_Chance(v) != 0) {
            g += 1;
        }
    } else if (Rand_Chance(v) != 0) {
        g += 1;
    }
    *(u8 *)((u8 *)arg0 + 0x2DC) = g;

    g = 0;
    v = gr.v[6];
    if (v >= 0x64) {
        g = 1;
        v -= 0x64;
    }
    if ((s16)v >= 0x64) {
        v -= 0x64;
        g += 1;
    }
    if (flag != 0) {
        if (Rand_Chance(v) != 0 || Rand_Chance(v) != 0) {
            g += 1;
        }
    } else if (Rand_Chance(v) != 0) {
        g += 1;
    }
    *(u8 *)((u8 *)arg0 + 0x2DD) = g;

    g = 0;
    v = gr.v[7];
    if (v >= 0x64) {
        g = 1;
        v -= 0x64;
    }
    if ((s16)v >= 0x64) {
        v -= 0x64;
        g += 1;
    }
    if (flag != 0) {
        if (Rand_Chance(v) != 0 || Rand_Chance(v) != 0) {
            g += 1;
        }
    } else if (Rand_Chance(v) != 0) {
        g += 1;
    }
    *(u8 *)((u8 *)arg0 + 0x2DE) = g;

    stat = Unit_GetHp(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2D7);
    excess = (s8)((g + stat) - cap[0x4C]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2D7) = g - excess;
    }
    stat = Unit_GetStr(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2D8);
    excess = (s8)((g + stat) - cap[0x4D]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2D8) = g - excess;
    }
    stat = Unit_GetMag(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2D9);
    excess = (s8)((g + stat) - cap[0x4E]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2D9) = g - excess;
    }
    stat = Unit_GetSkl(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2DA);
    excess = (s8)((g + stat) - cap[0x4F]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2DA) = g - excess;
    }
    stat = Unit_GetSpd(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2DB);
    excess = (s8)((g + stat) - cap[0x50]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2DB) = g - excess;
    }
    stat = Unit_GetLck(arg0);
    g = *(u8 *)((u8 *)arg0 + 0x2DC);
    excess = (s8)(g + (stat - 0x28));
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2DC) = g - excess;
    }
    stat = Unit_GetDef(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2DD);
    excess = (s8)((g + stat) - cap[0x52]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2DD) = g - excess;
    }
    stat = Unit_GetRes(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2DE);
    excess = (s8)((g + stat) - cap[0x53]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2DE) = g - excess;
    }

    g = *(u8 *)((u8 *)arg0 + 0x2D7);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x2A);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2D8);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x2B);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2D9);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x2C);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2DA);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x2D);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2DB);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x2E);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2DC);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x2F);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2DD);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x30);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2DE);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x31);
    }
}
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
/* Promote the foe copy, then queue battle anims for each stat gain vs the base unit. */
void Battle_QueuePromotionGains(s32 battle, void *unit) {
    void Battle_SetupPair(void *, void *, void *);
    void Unit_Promote(void *);
    void fn_801A981C(void *, s32, s32);
    s32 Unit_GetHp(void *);
    s32 Unit_GetStr(void *);
    s32 Unit_GetMag(void *);
    s32 Unit_GetSkl(void *);
    s32 Unit_GetSpd(void *);
    s32 Unit_GetLck(void *);
    s32 Unit_GetDef(void *);
    s32 Unit_GetRes(void *);
    s32 Unit_GetMov(void *);
    s32 Unit_GetCon(void *);
    void BattleAnim_Queue(void *, s32, s8);
    void fn_801A442C(void *);
    s8 dHp;
    s8 dStr;
    s8 dMag;
    s8 dSkl;
    s8 dSpd;
    s8 dLck;
    s8 dDef;
    s8 dRes;
    s8 dMov;
    s8 dCon;
    s32 t;

    Battle_SetupPair((void *)battle, unit, unit);
    Unit_Promote((void *)(battle + 0x2E0));
    *(u32 *)(battle + 0xCAC) |= 0x2000;
    fn_801A981C((void *)battle, 0, -1);
    fn_801A981C((void *)(battle + 0x2E0), 0, -1);
    t = Unit_GetHp((void *)(battle + 0x2E0));
    dHp = (s8)(t - Unit_GetHp((void *)battle));
    t = Unit_GetStr((void *)(battle + 0x2E0));
    dStr = (s8)(t - Unit_GetStr((void *)battle));
    t = Unit_GetMag((void *)(battle + 0x2E0));
    dMag = (s8)(t - Unit_GetMag((void *)battle));
    t = Unit_GetSkl((void *)(battle + 0x2E0));
    dSkl = (s8)(t - Unit_GetSkl((void *)battle));
    t = Unit_GetSpd((void *)(battle + 0x2E0));
    dSpd = (s8)(t - Unit_GetSpd((void *)battle));
    t = Unit_GetLck((void *)(battle + 0x2E0));
    dLck = (s8)(t - Unit_GetLck((void *)battle));
    t = Unit_GetDef((void *)(battle + 0x2E0));
    dDef = (s8)(t - Unit_GetDef((void *)battle));
    t = Unit_GetRes((void *)(battle + 0x2E0));
    dRes = (s8)(t - Unit_GetRes((void *)battle));
    t = Unit_GetMov((void *)(battle + 0x2E0));
    dMov = (s8)(t - Unit_GetMov((void *)battle));
    t = Unit_GetCon((void *)(battle + 0x2E0));
    dCon = (s8)(t - Unit_GetCon((void *)battle));
    t = battle + 0x8A0;
    BattleAnim_Queue((void *)t, 0x2A, dHp);
    BattleAnim_Queue((void *)t, 0x2B, dStr);
    BattleAnim_Queue((void *)t, 0x2C, dMag);
    BattleAnim_Queue((void *)t, 0x2D, dSkl);
    BattleAnim_Queue((void *)t, 0x2E, dSpd);
    BattleAnim_Queue((void *)t, 0x2F, dLck);
    BattleAnim_Queue((void *)t, 0x30, dDef);
    BattleAnim_Queue((void *)t, 0x31, dRes);
    BattleAnim_Queue((void *)t, 0x32, dMov);
    BattleAnim_Queue((void *)t, 0x33, dCon);
    fn_801A442C((void *)battle);
}
#pragma use_lmw_stmw reset

void fn_80034A8C(void *arg0, void *arg1, u8 arg2, void *arg3, u8 arg4) {
 u8 fn_8003D094(void *, u8);
 u8 fn_8003D13C(void *);
 void Battle_SetupUnit(void *,void *,s32);
 s32 fn_800386B0(void *);
 void BattleAnim_Queue(void *,s32,s8);
 void fn_8014C5F4(void *,u32);
 void fn_800351FC(void *,u8,s32,void *);
 void Battle_TryStartGrowSeq(void *);
 extern u8 gBattleState[];
 struct BattleUnitView { u8 pad[0x2C9]; u8 gain; u8 pad2[0x5D6]; u8 anim[1]; };
 void *grow=arg3;
 u8 value=arg2;
 void *other=arg1;
 struct BattleUnitView *unit=arg0;
 if(arg4) value=fn_8003D094(other,value);
 if(value>fn_8003D13C(other)) value=fn_8003D13C(other);
 if(value) {
 Battle_SetupUnit(unit,other,-1);
 BattleAnim_Queue(unit->anim,0x27,(s8)fn_800386B0(other));
 if(value>fn_8003D13C(other)) value=fn_8003D13C(other);
 BattleAnim_Queue(unit->anim,0x28,(s8)value);
 unit->gain=value;
 fn_8014C5F4(gBattleState,(u8)value);
 fn_800351FC(unit,value,0,unit->anim);
 Battle_TryStartGrowSeq(grow);
 }
}

/* Roll level-up growths from rates, clamp to class caps, and queue non-zero gains. */
void Unit_CalcLevelUpGrowths(void *unit, void *gains) {
    void BattleAnim_Queue(void *, s32, u8);
    s32 Unit_GetRes(void *);
    s32 Unit_GetDef(void *);
    s32 Unit_GetLck(void *);
    s32 Unit_GetSpd(void *);
    s32 Unit_GetSkl(void *);
    s32 Unit_GetMag(void *);
    s32 Unit_GetStr(void *);
    s32 Unit_GetHp(void *);
    u8 Status_Test(void *, s32);
    void *self;
    void *out;
    s32 thr;
    s32 ctr;
    s32 stat;
    s32 adj;
    u8 g;
    s8 excess;
    void *cls;
    u8 ret;
    u32 first;
    u8 *firstClass;

    self = unit;
    out = gains;
    *(u8 *)((u8 *)self + 0x2DE) = 0;
    *(u8 *)((u8 *)self + 0x2DD) = 0;
    *(u8 *)((u8 *)self + 0x2DC) = 0;
    *(u8 *)((u8 *)self + 0x2DB) = 0;
    *(u8 *)((u8 *)self + 0x2DA) = 0;
    *(u8 *)((u8 *)self + 0x2D9) = 0;
    *(u8 *)((u8 *)self + 0x2D8) = 0;
    *(u8 *)((u8 *)self + 0x2D7) = 0;
    ret = Status_Test((u8 *)self + 0x1BC, 0x4B);
    thr = 0x64;
    if (ret != 0) {
        thr = 0x5A;
    }
    for (ctr = 2; ctr != 0; ctr--) {
        if (*(u8 *)((u8 *)self + 0x1B4) >= thr) {
            *(u8 *)((u8 *)self + 0x1B4) = *(u8 *)((u8 *)self + 0x1B4) - thr;
            *(u8 *)((u8 *)self + 0x2D7) = *(u8 *)((u8 *)self + 0x2D7) + 1;
        }
        if (*(u8 *)((u8 *)self + 0x1B5) >= thr) {
            *(u8 *)((u8 *)self + 0x1B5) = *(u8 *)((u8 *)self + 0x1B5) - thr;
            *(u8 *)((u8 *)self + 0x2D8) = *(u8 *)((u8 *)self + 0x2D8) + 1;
        }
        if (*(u8 *)((u8 *)self + 0x1B6) >= thr) {
            *(u8 *)((u8 *)self + 0x1B6) = *(u8 *)((u8 *)self + 0x1B6) - thr;
            *(u8 *)((u8 *)self + 0x2D9) = *(u8 *)((u8 *)self + 0x2D9) + 1;
        }
        if (*(u8 *)((u8 *)self + 0x1B7) >= thr) {
            *(u8 *)((u8 *)self + 0x1B7) = *(u8 *)((u8 *)self + 0x1B7) - thr;
            *(u8 *)((u8 *)self + 0x2DA) = *(u8 *)((u8 *)self + 0x2DA) + 1;
        }
        if (*(u8 *)((u8 *)self + 0x1B8) >= thr) {
            *(u8 *)((u8 *)self + 0x1B8) = *(u8 *)((u8 *)self + 0x1B8) - thr;
            *(u8 *)((u8 *)self + 0x2DB) = *(u8 *)((u8 *)self + 0x2DB) + 1;
        }
        if (*(u8 *)((u8 *)self + 0x1B9) >= thr) {
            *(u8 *)((u8 *)self + 0x1B9) = *(u8 *)((u8 *)self + 0x1B9) - thr;
            *(u8 *)((u8 *)self + 0x2DC) = *(u8 *)((u8 *)self + 0x2DC) + 1;
        }
        if (*(u8 *)((u8 *)self + 0x1BA) >= thr) {
            *(u8 *)((u8 *)self + 0x1BA) = *(u8 *)((u8 *)self + 0x1BA) - thr;
            *(u8 *)((u8 *)self + 0x2DD) = *(u8 *)((u8 *)self + 0x2DD) + 1;
        }
        if (*(u8 *)((u8 *)self + 0x1BB) >= thr) {
            *(u8 *)((u8 *)self + 0x1BB) = *(u8 *)((u8 *)self + 0x1BB) - thr;
            *(u8 *)((u8 *)self + 0x2DE) = *(u8 *)((u8 *)self + 0x2DE) + 1;
        }
    }
    stat = Unit_GetHp(self);
    firstClass = *(u8 **)((u8 *)self + 0x18C);
    first = *(u8 *)((u8 *)self + 0x2D7);
    stat = first + stat;
    excess = (s8)(stat - *(u8 *)((u8 *)firstClass + 0x4C));
    if (excess >= 0) {
        *(u8 *)((u8 *)self + 0x2D7) = first - excess;
    }
    stat = Unit_GetStr(self);
    cls = *(void **)((u8 *)self + 0x18C);
    g = *(u8 *)((u8 *)self + 0x2D8);
    stat = g + stat;
    excess = (s8)(stat - *(u8 *)((u8 *)cls + 0x4D));
    if (0 <= excess) {
        *(u8 *)((u8 *)self + 0x2D8) = g - excess;
    }
    stat = Unit_GetMag(self);
    cls = *(void **)((u8 *)self + 0x18C);
    g = *(u8 *)((u8 *)self + 0x2D9);
    stat = g + stat;
    excess = (s8)(stat - *(u8 *)((u8 *)cls + 0x4E));
    if (excess >= 0) {
        *(u8 *)((u8 *)self + 0x2D9) = g - excess;
    }
    stat = Unit_GetSkl(self);
    cls = *(void **)((u8 *)self + 0x18C);
    g = *(u8 *)((u8 *)self + 0x2DA);
    stat = g + stat;
    excess = (s8)(stat - *(u8 *)((u8 *)cls + 0x4F));
    if (excess >= 0) {
        *(u8 *)((u8 *)self + 0x2DA) = g - excess;
    }
    stat = Unit_GetSpd(self);
    cls = *(void **)((u8 *)self + 0x18C);
    g = *(u8 *)((u8 *)self + 0x2DB);
    stat = g + stat;
    excess = (s8)(stat - *(u8 *)((u8 *)cls + 0x50));
    if (excess >= 0) {
        *(u8 *)((u8 *)self + 0x2DB) = g - excess;
    }
    stat = Unit_GetLck(self);
    g = *(u8 *)((u8 *)self + 0x2DC);
    adj = stat - 0x28;
    adj = g + adj;
    excess = (s8)adj;
    if (excess >= 0) {
        *(u8 *)((u8 *)self + 0x2DC) = (u32)g - excess;
    }
    stat = Unit_GetDef(self);
    cls = *(void **)((u8 *)self + 0x18C);
    g = *(u8 *)((u8 *)self + 0x2DD);
    stat = g + stat;
    excess = (s8)(stat - *(u8 *)((u8 *)cls + 0x52));
    if (excess >= 0) {
        *(u8 *)((u8 *)self + 0x2DD) = g - excess;
    }
    stat = Unit_GetRes(self);
    cls = *(void **)((u8 *)self + 0x18C);
    g = *(u8 *)((u8 *)self + 0x2DE);
    stat = g + stat;
    excess = (s8)(stat - *(u8 *)((u8 *)cls + 0x53));
    if (excess >= 0) {
        *(u8 *)((u8 *)self + 0x2DE) = g - excess;
    }
    g = *(u8 *)((u8 *)self + 0x2D7);
    if ((s8)g != 0) {
        BattleAnim_Queue(out, 0x2A, g);
    }
    g = *(u8 *)((u8 *)self + 0x2D8);
    if ((s8)g != 0) {
        BattleAnim_Queue(out, 0x2B, g);
    }
    g = *(u8 *)((u8 *)self + 0x2D9);
    if ((s8)g != 0) {
        BattleAnim_Queue(out, 0x2C, g);
    }
    g = *(u8 *)((u8 *)self + 0x2DA);
    if ((s8)g != 0) {
        BattleAnim_Queue(out, 0x2D, g);
    }
    g = *(u8 *)((u8 *)self + 0x2DB);
    if ((s8)g != 0) {
        BattleAnim_Queue(out, 0x2E, g);
    }
    g = *(u8 *)((u8 *)self + 0x2DC);
    if ((s8)g != 0) {
        BattleAnim_Queue(out, 0x2F, g);
    }
    g = *(u8 *)((u8 *)self + 0x2DD);
    if ((s8)g != 0) {
        BattleAnim_Queue(out, 0x30, g);
    }
    g = *(u8 *)((u8 *)self + 0x2DE);
    if ((s8)g != 0) {
        BattleAnim_Queue(out, 0x31, g);
    }
}

void fn_80034F40(void *arg0) {
 void *obj=M2C_FIELD(arg0,void**,0x280);
 void fn_8003868C(void*,u8); u8 fn_800386B0(void*); void fn_8003708C(void*,void*);
 u8 status=M2C_FIELD(M2C_FIELD(obj,void**,0x190),u8*,8);
 if (status==0) goto copy;
 if (status==5) {
   M2C_FIELD((short)obj,u8*,0x19A)=M2C_FIELD(arg0,u8*,0x19A);
   fn_8003868C(M2C_FIELD(arg0,void**,0x280),(u8)fn_800386B0(arg0));
 }
 copy:
 fn_8003708C(M2C_FIELD(arg0,void**,0x280),(u8*)arg0+0x2D7);
 obj=M2C_FIELD(arg0,void**,0x280);
 M2C_FIELD(obj,u8*,0x1B4)=M2C_FIELD(arg0,u8*,0x1B4);
 M2C_FIELD(obj,u8*,0x1B5)=M2C_FIELD(arg0,u8*,0x1B5);
 M2C_FIELD(obj,u8*,0x1B6)=M2C_FIELD((u32)arg0,u8*,0x1B6);
 M2C_FIELD(obj,u8*,0x1B7)=M2C_FIELD(arg0,u8*,0x1B7);
 M2C_FIELD(obj,u8*,0x1B8)=M2C_FIELD(arg0,u8*,0x1B8);
 M2C_FIELD(obj,u8*,0x1B9)=M2C_FIELD(arg0,u8*,0x1B9);
 M2C_FIELD((s32)obj,u8*,0x1BA)=M2C_FIELD(arg0,u8*,0x1BA);
 M2C_FIELD(obj,u8*,0x1BB)=M2C_FIELD(arg0,u8*,0x1BB);
}

/* Add rounded growth deltas into the unit's eight growth-progress bytes (clamp 0..255). */
void Unit_AddGrowthProgress(void *unit, void *deltas) {
    s16 res;
    s16 hp;
    s16 str;
    s16 mag;
    s16 skl;
    s16 spd;
    s16 lck;
    s16 def;

    hp = M2C_FIELD(unit, u8 *, 0x1B4) + (s32) (0.5f + M2C_FIELD(deltas, f32 *, 0));
    if (hp < 0) {
        hp = 0;
    }
    if (hp > 0xFF) {
        hp = 0xFF;
    }
    M2C_FIELD(unit, u8 *, 0x1B4) = (u8) hp;
    str = M2C_FIELD(unit, u8 *, 0x1B5) + (s32) (0.5f + M2C_FIELD(deltas, f32 *, 4));
    if (str < 0) {
        str = 0;
    }
    if (str > 0xFF) {
        str = 0xFF;
    }
    M2C_FIELD(unit, u8 *, 0x1B5) = (u8) str;
    mag = M2C_FIELD(unit, u8 *, 0x1B6) + (s32) (0.5f + M2C_FIELD(deltas, f32 *, 8));
    if (mag < 0) {
        mag = 0;
    }
    if (mag > 0xFF) {
        mag = 0xFF;
    }
    M2C_FIELD(unit, u8 *, 0x1B6) = (u8) mag;
    skl = M2C_FIELD(unit, u8 *, 0x1B7) + (s32) (0.5f + M2C_FIELD(deltas, f32 *, 0xC));
    if (skl < 0) {
        skl = 0;
    }
    if (skl > 0xFF) {
        skl = 0xFF;
    }
    M2C_FIELD(unit, u8 *, 0x1B7) = (u8) skl;
    spd = M2C_FIELD(unit, u8 *, 0x1B8) + (s32) (0.5f + M2C_FIELD(deltas, f32 *, 0x10));
    if (spd < 0) {
        spd = 0;
    }
    if (spd > 0xFF) {
        spd = 0xFF;
    }
    M2C_FIELD(unit, u8 *, 0x1B8) = (u8) spd;
    lck = M2C_FIELD(unit, u8 *, 0x1B9) + (s32) (0.5f + M2C_FIELD(deltas, f32 *, 0x14));
    if (lck < 0) {
        lck = 0;
    }
    if (lck > 0xFF) {
        lck = 0xFF;
    }
    M2C_FIELD(unit, u8 *, 0x1B9) = (u8) lck;
    def = M2C_FIELD(unit, u8 *, 0x1BA) + (s32) (0.5f + M2C_FIELD(deltas, f32 *, 0x18));
    if (def < 0) {
        def = 0;
    }
    if (def > 0xFF) {
        def = 0xFF;
    }
    M2C_FIELD(unit, u8 *, 0x1BA) = (u8) def;
    res = M2C_FIELD(unit, u8 *, 0x1BB) + (s32) (0.5f + M2C_FIELD(deltas, f32 *, 0x1C));
    if (res < 0) {
        res = 0;
    }
    if (res > 0xFF) {
        res = 0xFF;
    }
    M2C_FIELD(unit, u8 *, 0x1BB) = (u8) res;
}

void fn_800351FC(void *arg0, u8 arg1, void *arg2, void *arg3) {
    void DebugPrint(void *, ...);
    void BattleAnim_Queue(void *, s32);
    void fn_80034130(void *, void *);
    void Unit_CalcLevelUpGrowths(void *, void *);
    void Unit_AddGrowthProgress(void *, void *);
    void **fn_80037C20(void *);
    s8 fn_80037CCC(void *);
    u8 fn_800386B0(void *);
    u8 fn_8003D13C(void *);
    u8 fn_8014DA68(void);
    extern u8 lbl_8026A120[];
    extern u8 gBattle[];
    extern f32 lbl_80368E8C;
    extern f32 lbl_80368EA0;

    f32 vals[8];
    u8 zeros[8];
    u8 zeros2[8];
    u8 zeros3[8];
    u8 zeros4[8];
    u8 *p;
    void *tmp;
    void **pp;
    u8 exp;
    s32 i;

    if (fn_8014DA68() == 0) {
        if (arg1 != 0) {
            *(u32 *)(gBattle + 0xCAC) |= 0x400;
        }
        exp = (u8)(arg1 + fn_800386B0(arg0));
        if (exp >= 0x64) {
            exp -= 0x64;
            ((u8 *)arg0)[0x19A]++;
            *(u32 *)(gBattle + 0xCAC) |= 0x800;
            if ((s8)((u8 *)arg0)[0x19A] > 0x14) {
                *(u32 *)((u8 *)arg0 + 0x1A0) |= 0x40000;
                *(u32 *)(gBattle + 0xCAC) |= 0x10;
            } else {
                BattleAnim_Queue(arg3, 0x29);
                fn_80034130(arg0, arg3);
            }
        }
        ((u8 *)arg0)[0x19B] = exp;
        if (fn_8003D13C(arg0) == 0) {
            ((u8 *)arg0)[0x19B] = 0xFF;
        }
        return;
    }

    for (i = 0; i < 8; i++) {
        vals[i] = lbl_80368EA0;
    }
    tmp = *(void **)((u8 *)arg0 + 0x188);
    if (tmp != NULL) {
        vals[0] = lbl_80368EA0 + (f32)((u8 *)tmp)[0x25];
        vals[1] = lbl_80368EA0 + (f32)((u8 *)tmp)[0x26];
        vals[2] = lbl_80368EA0 + (f32)((u8 *)tmp)[0x27];
        vals[3] = lbl_80368EA0 + (f32)((u8 *)tmp)[0x28];
        vals[4] = lbl_80368EA0 + (f32)((u8 *)tmp)[0x29];
        vals[5] = lbl_80368EA0 + (f32)((u8 *)tmp)[0x2A];
        vals[6] = lbl_80368EA0 + (f32)((u8 *)tmp)[0x2B];
        vals[7] = lbl_80368EA0 + (f32)((u8 *)tmp)[0x2C];
    }
    DebugPrint(lbl_8026A120 + 0xCE);
    for (i = 0; i < 8; i++) {
        zeros[i] = 0;
    }
    DebugPrint(lbl_8026A120 + 0xE6, 0, vals[0]);
    DebugPrint(lbl_8026A120 + 0xFA, (s8)zeros[1], vals[1]);
    DebugPrint(lbl_8026A120 + 0x10E, (s8)zeros[2], vals[2]);
    DebugPrint(lbl_8026A120 + 0x122, (s8)zeros[3], vals[3]);
    DebugPrint(lbl_8026A120 + 0x136, (s8)zeros[4], vals[4]);
    DebugPrint(lbl_8026A120 + 0x14A, (s8)zeros[5], vals[5]);
    DebugPrint(lbl_8026A120 + 0x15E, (s8)zeros[6], vals[6]);
    DebugPrint(lbl_8026A120 + 0x172, (s8)zeros[7], vals[7]);

    if (arg2 != NULL) {
        tmp = *(void **)((u8 *)arg2 + 0x18C);
        if (tmp != NULL) {
            vals[0] += (f32)(s8)((u8 *)tmp)[0x5C];
            vals[1] += (f32)(s8)((u8 *)tmp)[0x5D];
            vals[2] += (f32)(s8)((u8 *)tmp)[0x5E];
            vals[3] += (f32)(s8)((u8 *)tmp)[0x5F];
            vals[4] += (f32)(s8)((u8 *)tmp)[0x60];
            vals[5] += (f32)(s8)((u8 *)tmp)[0x61];
            vals[6] += (f32)(s8)((u8 *)tmp)[0x62];
            vals[7] += (f32)(s8)((u8 *)tmp)[0x63];
        }
        DebugPrint(lbl_8026A120 + 0x186);
        tmp = *(void **)((u8 *)arg2 + 0x18C);
        if (tmp != NULL) {
            p = (u8 *)tmp + 0x5C;
        } else {
            for (i = 0; i < 8; i++) {
                zeros2[i] = 0;
            }
            p = zeros2;
        }
        DebugPrint(lbl_8026A120 + 0xE6, (s8)p[0], vals[0]);
        DebugPrint(lbl_8026A120 + 0xFA, (s8)p[1], vals[1]);
        DebugPrint(lbl_8026A120 + 0x10E, (s8)p[2], vals[2]);
        DebugPrint(lbl_8026A120 + 0x122, (s8)p[3], vals[3]);
        DebugPrint(lbl_8026A120 + 0x136, (s8)p[4], vals[4]);
        DebugPrint(lbl_8026A120 + 0x14A, (s8)p[5], vals[5]);
        DebugPrint(lbl_8026A120 + 0x15E, (s8)p[6], vals[6]);
        DebugPrint(lbl_8026A120 + 0x172, (s8)p[7], vals[7]);
    }

    tmp = *(void **)((u8 *)arg0 + 0x28C);
    if (tmp != NULL) {
        vals[0] += (f32)(s8)((u8 *)tmp)[0x2A];
        vals[1] += (f32)(s8)((u8 *)tmp)[0x2B];
        vals[2] += (f32)(s8)((u8 *)tmp)[0x2C];
        vals[3] += (f32)(s8)((u8 *)tmp)[0x2D];
        vals[4] += (f32)(s8)((u8 *)tmp)[0x2E];
        vals[5] += (f32)(s8)((u8 *)tmp)[0x2F];
        vals[6] += (f32)(s8)((u8 *)tmp)[0x30];
        vals[7] += (f32)(s8)((u8 *)tmp)[0x31];
    }
    DebugPrint(lbl_8026A120 + 0x194);
    tmp = *(void **)((u8 *)arg0 + 0x28C);
    if (tmp != NULL) {
        p = (u8 *)tmp + 0x2A;
    } else {
        p = NULL;
    }
    if (p == NULL) {
        for (i = 0; i < 8; i++) {
            zeros3[i] = 0;
        }
        p = zeros3;
    }
    DebugPrint(lbl_8026A120 + 0xE6, (s8)p[0], vals[0]);
    DebugPrint(lbl_8026A120 + 0xFA, (s8)p[1], vals[1]);
    DebugPrint(lbl_8026A120 + 0x10E, (s8)p[2], vals[2]);
    DebugPrint(lbl_8026A120 + 0x122, (s8)p[3], vals[3]);
    DebugPrint(lbl_8026A120 + 0x136, (s8)p[4], vals[4]);
    DebugPrint(lbl_8026A120 + 0x14A, (s8)p[5], vals[5]);
    DebugPrint(lbl_8026A120 + 0x15E, (s8)p[6], vals[6]);
    DebugPrint(lbl_8026A120 + 0x172, (s8)p[7], vals[7]);

    pp = fn_80037C20(arg0);
    if (pp != NULL) {
        tmp = *pp;
        if (tmp != NULL) {
            vals[0] += (f32)(s8)((u8 *)tmp)[0x2A];
            vals[1] += (f32)(s8)((u8 *)tmp)[0x2B];
            vals[2] += (f32)(s8)((u8 *)tmp)[0x2C];
            vals[3] += (f32)(s8)((u8 *)tmp)[0x2D];
            vals[4] += (f32)(s8)((u8 *)tmp)[0x2E];
            vals[5] += (f32)(s8)((u8 *)tmp)[0x2F];
            vals[6] += (f32)(s8)((u8 *)tmp)[0x30];
            vals[7] += (f32)(s8)((u8 *)tmp)[0x31];
        }
    }
    DebugPrint(lbl_8026A120 + 0x1A0);
    if (fn_80037CCC(arg0) >= 0) {
        p = (u8 *)(*fn_80037C20(arg0)) + 0x2A;
    } else {
        p = NULL;
    }
    if (p == NULL) {
        for (i = 0; i < 8; i++) {
            zeros4[i] = 0;
        }
        p = zeros4;
    }
    DebugPrint(lbl_8026A120 + 0xE6, (s8)p[0], vals[0]);
    DebugPrint(lbl_8026A120 + 0xFA, (s8)p[1], vals[1]);
    DebugPrint(lbl_8026A120 + 0x10E, (s8)p[2], vals[2]);
    DebugPrint(lbl_8026A120 + 0x122, (s8)p[3], vals[3]);
    DebugPrint(lbl_8026A120 + 0x136, (s8)p[4], vals[4]);
    DebugPrint(lbl_8026A120 + 0x14A, (s8)p[5], vals[5]);
    DebugPrint(lbl_8026A120 + 0x15E, (s8)p[6], vals[6]);
    DebugPrint(lbl_8026A120 + 0x172, (s8)p[7], vals[7]);

    vals[0] = (vals[0] * (f32)arg1) / lbl_80368E8C;
    vals[1] = (vals[1] * (f32)arg1) / lbl_80368E8C;
    vals[2] = (vals[2] * (f32)arg1) / lbl_80368E8C;
    vals[3] = (vals[3] * (f32)arg1) / lbl_80368E8C;
    vals[4] = (vals[4] * (f32)arg1) / lbl_80368E8C;
    vals[5] = (vals[5] * (f32)arg1) / lbl_80368E8C;
    vals[6] = (vals[6] * (f32)arg1) / lbl_80368E8C;
    vals[7] = (vals[7] * (f32)arg1) / lbl_80368E8C;
    DebugPrint(lbl_8026A120 + 0x1B2, (s8)arg1);
    for (i = 0; i < 8; i++) {
        zeros[i] = 0;
    }
    DebugPrint(lbl_8026A120 + 0xE6, 0, vals[0]);
    DebugPrint(lbl_8026A120 + 0xFA, (s8)zeros[1], vals[1]);
    DebugPrint(lbl_8026A120 + 0x10E, (s8)zeros[2], vals[2]);
    DebugPrint(lbl_8026A120 + 0x122, (s8)zeros[3], vals[3]);
    DebugPrint(lbl_8026A120 + 0x136, (s8)zeros[4], vals[4]);
    DebugPrint(lbl_8026A120 + 0x14A, (s8)zeros[5], vals[5]);
    DebugPrint(lbl_8026A120 + 0x15E, (s8)zeros[6], vals[6]);
    DebugPrint(lbl_8026A120 + 0x172, (s8)zeros[7], vals[7]);
    DebugPrint(lbl_8026A120 + 0x1D0);
    DebugPrint(lbl_8026A120 + 0x1EA);
    DebugPrint(lbl_8026A120 + 0x213, (s8)((u8 *)arg0)[0x1B4], (s8)((u8 *)arg0)[0x1B5], (s8)((u8 *)arg0)[0x1B6], (s8)((u8 *)arg0)[0x1B7], (s8)((u8 *)arg0)[0x1B8], (s8)((u8 *)arg0)[0x1B9], (s8)((u8 *)arg0)[0x1BA], (s8)((u8 *)arg0)[0x1BB]);
    Unit_AddGrowthProgress(arg0, vals);
    DebugPrint(lbl_8026A120 + 0x23C);
    DebugPrint(lbl_8026A120 + 0x1EA);
    DebugPrint(lbl_8026A120 + 0x213, (s8)((u8 *)arg0)[0x1B4], (s8)((u8 *)arg0)[0x1B5], (s8)((u8 *)arg0)[0x1B6], (s8)((u8 *)arg0)[0x1B7], (s8)((u8 *)arg0)[0x1B8], (s8)((u8 *)arg0)[0x1B9], (s8)((u8 *)arg0)[0x1BA], (s8)((u8 *)arg0)[0x1BB]);

    if (arg1 != 0) {
        *(u32 *)(gBattle + 0xCAC) |= 0x400;
    }
    exp = (u8)(arg1 + fn_800386B0(arg0));
    if (exp >= 0x64) {
        exp -= 0x64;
        ((u8 *)arg0)[0x19A]++;
        *(u32 *)(gBattle + 0xCAC) |= 0x800;
        if ((s8)((u8 *)arg0)[0x19A] > 0x14) {
            *(u32 *)((u8 *)arg0 + 0x1A0) |= 0x40000;
            *(u32 *)(gBattle + 0xCAC) |= 0x10;
        } else {
            BattleAnim_Queue(arg3, 0x29);
            Unit_CalcLevelUpGrowths(arg0, arg3);
        }
    }
    ((u8 *)arg0)[0x19B] = exp;
    if (fn_8003D13C(arg0) == 0) {
        ((u8 *)arg0)[0x19B] = 0xFF;
    }
}

#pragma global_optimizer off
void fn_80036150(s32 arg0) {
    u8 fn_8003D13C(s32);
    void BattleAnim_Queue(s32, s32, s8);
    s32 fn_800386B0(s32);
    u8 fn_8003D094(s32, u8);
    void fn_8014C5F4(void *, s32);
    void fn_800351FC(s32, u8, s32, s32);
    extern u8 gBattleState[];
    u8 var_r30;
    u16 *p16;

    if (fn_8003D13C(arg0) != 0) {
        BattleAnim_Queue(arg0 + 0x8A0, 0x25, 0);
        BattleAnim_Queue(arg0 + 0x8A0, 0x27, (s8)fn_800386B0(arg0));
        p16 = (u16 *)((u8 *)*(void **)(arg0 + 0x28C) + 0x10);
        var_r30 = fn_8003D094(arg0, (u8)(*p16 / 20 + 0xA));
        if (var_r30 > fn_8003D13C(arg0)) {
            var_r30 = fn_8003D13C(arg0);
        }
        BattleAnim_Queue(arg0 + 0x8A0, 0x28, (s8)var_r30);
        *(u8 *)(arg0 + 0x2C9) = var_r30;
        fn_8014C5F4(gBattleState, var_r30);
        fn_800351FC(arg0, var_r30, 0, arg0 + 0x8A0);
    }
}
#pragma global_optimizer reset
void Battle_CalcHits(s32 self) {
    extern u8 lbl_8026A120[];
    extern u8 gBattleState[];
    void DebugPrint(void *, ...);
    void BattleAnim_Queue(void *, s32, s8);
    void fn_800351FC(void *, u8, void *, void *);
    u8 fn_80038570(void *);
    u8 fn_800385E4(void *);
    u8 fn_8003863C(void *);
    u8 fn_800386B0(void *);
    u8 fn_8003D094(void *, u8);
    u8 fn_8003D13C(void *);
    u8 Status_Test(void *, s32);
    void fn_8014C5F4(void *, s32);
    s8 fn_801F1C5C(void);
    s8 fn_801F1CE8(void);
    s32 out;
    s32 t;
    s32 u;
    s32 v;
    u8 hit;

    hit = 0;
    if (*(u32 *)(self + 0x190) != *(u32 *)(self + 0x470)) {
        if ((u8)fn_8003D13C((void *)self) != 0) {
            out = self + 0x8A0;
            if ((u8)Status_Test((void *)(self + 0x49C), 7) != 0) {
                hit = 0;
            } else {
                BattleAnim_Queue((void *)out, 0x27, (s8)fn_800386B0((void *)self));
                if (*(u8 *)(self + 0x2D6) == 0) {
                    u = 1;
                } else {
                    t = fn_801F1C5C();
                    u = (u8)fn_8003863C((void *)(self + 0x2E0));
                    t = t + (u - (u8)fn_8003863C((void *)self));
                    t = (t + 1) / 2;
                    if (t < 1) {
                        t = 1;
                    }
                    u = (u8)t;
                    if ((s8)*(u8 *)(self + 0x488) != 0) {
                        v = 0;
                    } else {
                        t = fn_801F1CE8();
                        t = t + (u8)fn_800385E4((void *)(self + 0x2E0));
                        t = t - (u8)fn_800385E4((void *)self);
                        v = t + (u8)fn_80038570((void *)(self + 0x2E0));
                        if (v < 0) {
                            v = 0;
                        }
                    }
                    u = (u8)u + (u8)v;
                }
                hit = fn_8003D094((void *)self, (u8)u);
                if ((u8)hit > (u8)fn_8003D13C((void *)self)) {
                    hit = fn_8003D13C((void *)self);
                }
                BattleAnim_Queue((void *)out, 0x28, (s8)hit);
                out = (u8)hit;
                *(u8 *)(self + 0x2C9) = hit;
                fn_8014C5F4(gBattleState, out);
                t = fn_801F1C5C();
                u = (u8)fn_8003863C((void *)(self + 0x2E0));
                t = t + (u - (u8)fn_8003863C((void *)self));
                t = (t + 1) / 2;
                if (t < 1) {
                    t = 1;
                }
                u = (u8)t;
                if ((s8)*(u8 *)(self + 0x488) != 0) {
                    v = 0;
                } else {
                    t = fn_801F1CE8();
                    t = t + (u8)fn_800385E4((void *)(self + 0x2E0));
                    t = t - (u8)fn_800385E4((void *)self);
                    v = t + (u8)fn_80038570((void *)(self + 0x2E0));
                    if (v < 0) {
                        v = 0;
                    }
                }
                DebugPrint(lbl_8026A120 + 0x256, (u8)out, (u8)u, (u8)v);
            }
            if ((u8)hit != 0) {
                BattleAnim_Queue((void *)(self + 0x8A0), 0x25, 0);
                fn_800351FC((void *)self, hit, (void *)(self + 0x2E0), (void *)(self + 0x8A0));
            } else {
                return;
            }
        }
        if ((u8)fn_8003D13C((void *)(self + 0x2E0)) != 0) {
            out = self + 0x8A0;
            if ((u8)Status_Test((void *)(self + 0x1BC), 7) != 0) {
                hit = 0;
            } else {
                BattleAnim_Queue((void *)out, 0x27, (s8)fn_800386B0((void *)(self + 0x2E0)));
                if (*(u8 *)(self + 0x5B6) == 0) {
                    u = 1;
                } else {
                    t = fn_801F1C5C();
                    u = (u8)fn_8003863C((void *)self);
                    t = t + (u - (u8)fn_8003863C((void *)(self + 0x2E0)));
                    t = (t + 1) / 2;
                    if (t < 1) {
                        t = 1;
                    }
                    u = (u8)t;
                    if ((s8)*(u8 *)(self + 0x1A8) != 0) {
                        v = 0;
                    } else {
                        t = fn_801F1CE8();
                        t = t + (u8)fn_800385E4((void *)self);
                        t = t - (u8)fn_800385E4((void *)(self + 0x2E0));
                        v = t + (u8)fn_80038570((void *)self);
                        if (v < 0) {
                            v = 0;
                        }
                    }
                    u = (u8)u + (u8)v;
                }
                hit = fn_8003D094((void *)(self + 0x2E0), (u8)u);
                if ((u8)hit > (u8)fn_8003D13C((void *)(self + 0x2E0))) {
                    hit = fn_8003D13C((void *)(self + 0x2E0));
                }
                BattleAnim_Queue((void *)out, 0x28, (s8)hit);
                out = (u8)hit;
                *(u8 *)(self + 0x5A9) = hit;
                fn_8014C5F4(gBattleState, out);
                t = fn_801F1C5C();
                u = (u8)fn_8003863C((void *)self);
                t = t + (u - (u8)fn_8003863C((void *)(self + 0x2E0)));
                t = (t + 1) / 2;
                if (t < 1) {
                    t = 1;
                }
                u = (u8)t;
                if ((s8)*(u8 *)(self + 0x1A8) != 0) {
                    v = 0;
                } else {
                    t = fn_801F1CE8();
                    t = t + (u8)fn_800385E4((void *)self);
                    t = t - (u8)fn_800385E4((void *)(self + 0x2E0));
                    v = t + (u8)fn_80038570((void *)self);
                    if (v < 0) {
                        v = 0;
                    }
                }
                DebugPrint(lbl_8026A120 + 0x256, (u8)out, (u8)u, (u8)v);
            }
            if ((u8)hit != 0) {
                BattleAnim_Queue((void *)(self + 0x8A0), 0x26, 0);
                fn_800351FC((void *)(self + 0x2E0), hit, (void *)self, (void *)(self + 0x8A0));
            }
        }
    }
}

void fn_8003670C(void *arg0) {
    void *Unit_FindByPerson(void *);

    u8 *unit;
    u8 *partner;
    u8 *person;
    u8 *partnerPerson;
    u8 *table;
    u8 *partnerTable;
    s32 i;
    s32 j;
    s32 offset;
    s32 partnerOffset;
    s32 count;
    s32 partnerCount;
    s8 partnerIndex;

    unit = (u8 *)arg0;
    person = *(u8 **)(unit + 0x188);
    table = *(u8 **)(person + 0x50);

    if (table != 0) {
        i = 0;
        offset = 0;

        while (i < (u8)*(u32 *)(table + 4)) {
            person = *(u8 **)(unit + 0x188);
            table = *(u8 **)(person + 0x50);

            partner = (u8 *)Unit_FindByPerson(
                *(void **)(table + offset + 8)
            );

            if (partner != 0) {
                person = *(u8 **)(unit + 0x188);
                partnerPerson = *(u8 **)(partner + 0x188);

                j = 0;
                partnerOffset = 0;

                while (1) {
                    table = *(u8 **)(partner + 0x188);
                    table = *(u8 **)(table + 0x50);

                    if (*(void **)(table + partnerOffset + 8) == person) {
                        partnerIndex = (s8)j;
                        break;
                    }

                    partnerOffset += 8;
                    j++;

                    partnerTable = *(u8 **)(partnerPerson + 0x50);

                    if (partnerTable != 0) {
                        partnerCount = (u8)*(u32 *)(partnerTable + 4);
                    } else {
                        partnerCount = 0;
                    }

                    if (j >= partnerCount) {
                        partnerIndex = -1;
                        break;
                    }
                }

                if (partnerIndex >= 0) {
                    unit[0x214 + i] = 0;
                    partner[0x214 + partnerIndex] = 0;
                }
            }

            offset += 8;
            i++;

            person = *(u8 **)(unit + 0x188);
            table = *(u8 **)(person + 0x50);

            if (table != 0) {
                count = (u8)*(u32 *)(table + 4);
            } else {
                count = 0;
            }

            if (i >= count) {
                break;
            }
        }
    }
}

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
  u8 *obj;
  s32 result;
  s32 index;
  s32 offset;
  u8 value;
  u8 unit_val;
  u8 lim;
  obj = *((u8 **) (arg0 + 0x188));
  if ((*((void **) (obj + 0x50))) == NULL)
  {
    return 0;
  }
  result = 0;
  new_var2 = 0;
  new_var3[1] = obj + 0x50;
  index = new_var2;
  offset = new_var2;
  goto check;
  loop:
  table = *((u8 **) new_var3[1]);

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
  table = *((u8 **) (obj + 0x50));

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
s32 fn_80036DE0(void *arg0, void *arg1)
{
    s32 index;
    u32 value;
    u8 *obj;
    s32 offset;

    index = 0;
    value = *(u32 *)((u8 *)arg1 + 0x188);
    obj = *(u8 **)((u8 *)arg0 + 0x188);
    offset = (s32)(u32)index;

    goto check;

loop:
    {
        u8 *table;
        u32 entry;
        table = *(u8 **)((u8 *)obj + 0x50);
        entry = *(u32 *)(table + offset + 8);

        if (entry == value) {
            return (s8)index;
        }
    }

    offset += 8;
    index++;

check:
    {
        u8 *table;
        u8 lim;
        table = *(u8 **)((u8 *)obj + 0x50);

        if (table == 0) {
            lim = 0;
        } else {
            lim = (u8)*(u32 *)(table + 4);
            lim = (u8)(lim & 0xFF);
        }

        if (index < (s32)lim) {
            goto loop;
        }
    }

    return -1;
}
#pragma scheduling reset
s32 Unit_FindSupportPartnerIndex(void *arg0, u32 arg1)
{
    s32 offset;
    u8 *obj;
    s32 index;

    obj = *(u8 **)((u8 *)arg0 + 0x188);
    index = 0;
    offset = 0;

    goto check;

loop:
    {
        u8 *table;
        u32 entry;
        table = *(u8 **)(obj + 0x50);
        entry = *(u32 *)(table + offset + 8);

        if (entry == arg1) {
            return (s8)index;
        }
    }

    offset += 8;
    index++;

check:
    {
        u8 *table;
        u8 lim;
        table = *(u8 **)(obj + 0x50);

        if (table == NULL) {
            lim = 0;
        } else {
            lim = (u8)*(u32 *)(table + 4);
            lim = (u8)(lim & 0xFF);
        }

        if (index < (s32)lim) {
            goto loop;
        }
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
    return (value > entry[6]) ? 3 : 2;
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

    cls = *(void **)((u8 *)arg0 + 0x18C);
    unit = *(void **)((u8 *)arg0 + 0x188);
    excess = (s8)(*(u8 *)((u8 *)arg0 + 0x1AB) + (*(u8 *)((u8 *)unit + 0x1D) + *(u8 *)((u8 *)cls + 0x44))) - *(u8 *)((u8 *)cls + 0x4C);
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1AB) = (u8)(*(u8 *)((u8 *)arg0 + 0x1AB) - excess);

    cls = *(void **)((u8 *)arg0 + 0x18C);
    unit = *(void **)((u8 *)arg0 + 0x188);
    excess = (s8)(*(u8 *)((u8 *)arg0 + 0x1AC) + (*(u8 *)((u8 *)unit + 0x1E) + *(u8 *)((u8 *)cls + 0x45))) - *(u8 *)((u8 *)cls + 0x4D);
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1AC) = (u8)(*(u8 *)((u8 *)arg0 + 0x1AC) - excess);

    cls = *(void **)((u8 *)arg0 + 0x18C);
    unit = *(void **)((u8 *)arg0 + 0x188);
    excess = (s8)(*(u8 *)((u8 *)arg0 + 0x1AD) + (*(u8 *)((u8 *)unit + 0x1F) + *(u8 *)((u8 *)cls + 0x46))) - *(u8 *)((u8 *)cls + 0x4E);
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1AD) = (u8)(*(u8 *)((u8 *)arg0 + 0x1AD) - excess);

    cls = *(void **)((u8 *)arg0 + 0x18C);
    unit = *(void **)((u8 *)arg0 + 0x188);
    excess = (s8)(*(u8 *)((u8 *)arg0 + 0x1AE) + (*(u8 *)((u8 *)unit + 0x20) + *(u8 *)((u8 *)cls + 0x47))) - *(u8 *)((u8 *)cls + 0x4F);
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1AE) = (u8)(*(u8 *)((u8 *)arg0 + 0x1AE) - excess);

    cls = *(void **)((u8 *)arg0 + 0x18C);
    unit = *(void **)((u8 *)arg0 + 0x188);
    excess = (s8)(*(u8 *)((u8 *)arg0 + 0x1AF) + (*(u8 *)((u8 *)unit + 0x21) + *(u8 *)((u8 *)cls + 0x48))) - *(u8 *)((u8 *)cls + 0x50);
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1AF) = (u8)(*(u8 *)((u8 *)arg0 + 0x1AF) - excess);

    unit = *(void **)((u8 *)arg0 + 0x188);
    cls = *(void **)((u8 *)arg0 + 0x18C);
    excess = (s8)(*(u8 *)((u8 *)arg0 + 0x1B0) + (*(u8 *)((u8 *)unit + 0x22) + *(u8 *)((u8 *)cls + 0x49))) - 0x28;
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1B0) = (u8)(*(u8 *)((u8 *)arg0 + 0x1B0) - excess);

    cls = *(void **)((u8 *)arg0 + 0x18C);
    unit = *(void **)((u8 *)arg0 + 0x188);
    excess = (s8)(*(u8 *)((u8 *)arg0 + 0x1B1) + (*(u8 *)((u8 *)unit + 0x23) + *(u8 *)((u8 *)cls + 0x4A))) - *(u8 *)((u8 *)cls + 0x52);
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1B1) = (u8)(*(u8 *)((u8 *)arg0 + 0x1B1) - excess);

    cls = *(void **)((u8 *)arg0 + 0x18C);
    unit = *(void **)((u8 *)arg0 + 0x188);
    excess = (s8)(*(u8 *)((u8 *)arg0 + 0x1B2) + (*(u8 *)((u8 *)unit + 0x24) + *(u8 *)((u8 *)cls + 0x4B))) - *(u8 *)((u8 *)cls + 0x53);
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1B2) = (u8)(*(u8 *)((u8 *)arg0 + 0x1B2) - excess);

    unit = *(void **)((u8 *)arg0 + 0x188);
    cls = *(void **)((u8 *)arg0 + 0x18C);
    excess = (s8)(*(u8 *)((u8 *)arg0 + 0x1A9) + (*(u8 *)((u8 *)unit + 0x1B) + *(u8 *)((u8 *)cls + 0x3C))) - 0x63;
    if (excess < 0) {
        excess = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x1A9) = (u8)(*(u8 *)((u8 *)arg0 + 0x1A9) - excess);

    cls = *(void **)((u8 *)arg0 + 0x18C);
    excess = (s8)(*(u8 *)((u8 *)arg0 + 0x1AA) + *(u8 *)((u8 *)cls + 0x3E)) - 0x14;
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
u8 Unit_GetDistance(void *a, void *b) {
    s32 dy;
    s32 dx;

    dy = *(s8 *)((u8 *)b + 0x19F);
    dy = *(s8 *)((u8 *)a + 0x19F) - dy;
    if (dy < 0) {
        dy = -dy;
    }
    {
        s8 xa;
        s8 xb;
        xa = *(s8 *)((u8 *)a + 0x19E);
        xb = *(s8 *)((u8 *)b + 0x19E);
        dx = xa - xb;
    }
    if (dx < 0) {
        dx = -dx;
    }
    return (u8)(dx + dy);
}
#pragma global_optimizer reset
void Unit_SetMapPos(void *arg0, s8 arg1, s8 arg2) {
    void Unit_SetWorldXY(void *, f32, f32);
    extern f32 lbl_80368EC0;
    void *child;
    f32 base;
    f32 fx;
    f32 fy;

    *(s8 *)((u8 *)arg0 + 0x19E) = arg1;
    *(s8 *)((u8 *)arg0 + 0x19F) = arg2;
    child = *(void **)((u8 *)arg0 + 0x194);
    if (child != NULL) {
        base = lbl_80368EC0;
        *(s8 *)((u8 *)child + 0x19E) = arg1;
        fx = (f32)arg1;
        fx = base + fx;
        *(s8 *)((u8 *)child + 0x19F) = arg2;
        fy = (f32)arg2;
        fy = base + fy;
        Unit_SetWorldXY(child, fx, fy);
    }
}

void Unit_SetHp(void *arg0, s8 arg1) {
    s8 var_r4;
    s8 var_r5;
    s8 var_r9;
    s8 idx;
    s32 ptr;
    u8 var_r10;
    u8 var_r6;
    u8 lim_u;
    s8 lim;
    u8 b;
    s32 s;

    var_r4 = arg1;
    {
        void *c;
        void *u;
        c = *(void **)((u8 *)arg0 + 0x18C);
        u = *(void **)((u8 *)arg0 + 0x188);
        b = *(u8 *)((u8 *)arg0 + 0x1AB);
        s = *(u8 *)((u8 *)c + 0x44);
        lim_u = *(u8 *)((u8 *)c + 0x4C);
        s = s + b;
        b = *(u8 *)((u8 *)u + 0x1D);
        lim = (s8)lim_u;
        var_r9 = (s8)(b + s);
    }
    if (var_r9 > lim) {
        var_r9 = lim;
    }
    if (var_r9 < 0) {
        var_r9 = 0;
    }
    lim = 0;
    if ((((*(u8 *)((u8 *)arg0 + 0x1D1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1CC) != 0)) {
        idx = lim;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1D9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1D4) != 0)) {
        idx = 1;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1E1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1DC) != 0)) {
        idx = 2;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1E9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1E4) != 0)) {
        idx = 3;
    } else {
        idx = -1;
    }
    if (idx < 0) {
        ptr = 0;
    } else {
        ptr = (s8)idx * 8;
        ptr = ptr + 0x1CC;
        ptr = ptr + (s32)arg0;
    }
    var_r10 = 0;
    if ((u32)ptr != 0) {
        var_r10 = *(u8 *)((u8 *)*(void **)ptr + 0x1F);
    }
    if ((((*(u8 *)((u8 *)arg0 + 0x1F1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1EC) != 0)) {
        idx = 0;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1F9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1F4) != 0)) {
        idx = 1;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x201) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1FC) != 0)) {
        idx = 2;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x209) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x204) != 0)) {
        idx = 3;
    } else {
        idx = -1;
    }
    if (idx < 0) {
        ptr = 0;
    } else {
        ptr = (s8)idx * 8;
        ptr = ptr + 0x1EC;
        ptr = ptr + (s32)arg0;
    }
    if ((u32)ptr != 0) {
        var_r10 = (u8)(s8)(var_r10 + *(u8 *)((u8 *)*(void **)ptr + 0x1F));
    }
    if (var_r4 > (s8)(var_r9 + (s8)var_r10)) {
        {
            void *c;
            void *u;
            c = *(void **)((u8 *)arg0 + 0x18C);
            u = *(void **)((u8 *)arg0 + 0x188);
            b = *(u8 *)((u8 *)arg0 + 0x1AB);
            s = *(u8 *)((u8 *)c + 0x44);
            lim_u = *(u8 *)((u8 *)c + 0x4C);
            s = s + b;
            b = *(u8 *)((u8 *)u + 0x1D);
            lim = (s8)lim_u;
            var_r5 = (s8)(b + s);
        }
        if (var_r5 > lim) {
            var_r5 = lim;
        }
        if (var_r5 < 0) {
            var_r5 = 0;
        }
        lim = 0;
        if ((((*(u8 *)((u8 *)arg0 + 0x1D1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1CC) != 0)) {
            idx = lim;
        } else if ((((*(u8 *)((u8 *)arg0 + 0x1D9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1D4) != 0)) {
            idx = 1;
        } else if ((((*(u8 *)((u8 *)arg0 + 0x1E1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1DC) != 0)) {
            idx = 2;
        } else if ((((*(u8 *)((u8 *)arg0 + 0x1E9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1E4) != 0)) {
            idx = 3;
        } else {
            idx = -1;
        }
        if (idx < 0) {
            ptr = 0;
        } else {
            ptr = (s8)idx * 8;
            ptr = ptr + 0x1CC;
            ptr = ptr + (s32)arg0;
        }
        var_r6 = 0;
        if ((u32)ptr != 0) {
            var_r6 = *(u8 *)((u8 *)*(void **)ptr + 0x1F);
        }
        if ((((*(u8 *)((u8 *)arg0 + 0x1F1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1EC) != 0)) {
            idx = 0;
        } else if ((((*(u8 *)((u8 *)arg0 + 0x1F9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1F4) != 0)) {
            idx = 1;
        } else if ((((*(u8 *)((u8 *)arg0 + 0x201) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1FC) != 0)) {
            idx = 2;
        } else if ((((*(u8 *)((u8 *)arg0 + 0x209) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x204) != 0)) {
            idx = 3;
        } else {
            idx = -1;
        }
        if (idx < 0) {
            ptr = 0;
        } else {
            ptr = (s8)idx * 8;
            ptr = ptr + 0x1EC;
            ptr = ptr + (s32)arg0;
        }
        if ((u32)ptr != 0) {
            var_r6 = (u8)(s8)(var_r6 + *(u8 *)((u8 *)*(void **)ptr + 0x1F));
        }
        var_r4 = (s8)(var_r5 + (s8)var_r6);
    }
    if (var_r4 < 0) {
        var_r4 = 0;
    }
    *(s8 *)((u8 *)arg0 + 0x1A8) = var_r4;
}

u8 fn_80038570(s32 arg0) {
    u8 Status_Test(s32, s32);
    s32 fn_801F1B44(void);
    u8 fn_801F1AB8(void);

    u8 var_r31;

    var_r31 = 0;
    if (Status_Test(arg0 + 0x1BC, 6) != 0) {
        var_r31 = (u8)fn_801F1B44();
    }
    if (Status_Test(arg0 + 0x1BC, 0x3C) != 0) {
        var_r31 += fn_801F1AB8();
    }
    return var_r31;
}

u8 fn_800385E4(void *arg0) {
    s32 byte_val;
    s32 result;

    if ((u8)Status_Test((u8 *)arg0 + 0x1BC, 2) != 0) {
        byte_val = *((u8 *)arg0 + 0x19A);
        result = byte_val + fn_801F1BD0();
        result = result + 0x14;
        return (u8)result;
    }
    return *((u8 *)arg0 + 0x19A);
}

u8 fn_8003863C(u8 *arg0) {
    u8 Status_Test(u8 *, s32);

    if ((u8)Status_Test(arg0 + 0x1BC, 2) != 0) {
        return (u8)(arg0[0x19A] + 0x14);
    }
    return arg0[0x19A];
}

#pragma scheduling off
void fn_8003868C(void *arg0, s32 arg1) {
    if (arg1 != 0xff && (arg1 < 0 || arg1 > 0x64)) {
        return;
    }
    *(u8 *)((u8 *)arg0 + 0x19B) = (u8)arg1;
}
#pragma scheduling reset
u8 fn_800386B0(void *arg0) {
    u8 one = 1;
    u8 two = 2;
    u8 three = 3;
    u8 value = M2C_FIELD(M2C_FIELD(arg0, void **, 0x190), u8 *, 8);
    if (value == one || value == two || value == three) return 0xFF;
    return M2C_FIELD(arg0, u8 *, 0x19B);
}

s32 fn_800386E0(s32 arg0) {
    u8 Status_Test(s32, s32);
    s32 var_r31;

    var_r31 = 0;
    if (Status_Test(arg0 + 0x1BC, 0x3D) != 0) {
        var_r31 = 0x32;
    }
    if (Status_Test(arg0 + 0x1BC, 0x3E) != 0) {
        var_r31 = -0x32;
    }
    return var_r31;
}

s8 fn_80038748(void *arg0) {
    s32 result;
    s32 temp;

    result = 0;
    if ((((*(u8 *)((u8 *)arg0 + 0x1D1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1CC) != 0)) {
        temp = 0;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1D9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1D4) != 0)) {
        temp = 1;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1E1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1DC) != 0)) {
        temp = 2;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1E9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1E4) != 0)) {
        temp = 3;
    } else {
        temp = -1;
    }
    if ((s8)temp < 0) {
        temp = 0;
    } else {
        temp = (s8)temp * 8;
        temp = temp + 0x1CC;
        temp = temp + (s32)arg0;
    }
    if ((u32)temp != 0) {
        result = *(s8 *)((u8 *)*(void **)temp + 0x27);
    }
    if ((((*(u8 *)((u8 *)arg0 + 0x1F1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1EC) != 0)) {
        temp = 0;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1F9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1F4) != 0)) {
        temp = 1;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x201) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1FC) != 0)) {
        temp = 2;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x209) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x204) != 0)) {
        temp = 3;
    } else {
        temp = -1;
    }
    if ((s8)temp < 0) {
        temp = 0;
    } else {
        temp = (s8)temp * 8;
        temp = temp + 0x1EC;
        temp = temp + (s32)arg0;
    }
    if ((u32)temp != 0) {
        result += *(u8 *)((u8 *)*(void **)temp + 0x27);
        result = (s8)result;
    }
    return (s8)result;
}

#pragma optimization_level 2
s8 fn_800388C8(void *arg0) {
    void **slot;
    s32 result;

    result = 0;
    slot = Unit_GetActiveItemPtr(arg0);
    if (slot != NULL) {
        result = *(s8 *)((u8 *)*slot + 0x28);
    }
    slot = fn_80037C20(arg0);
    if (slot != NULL) {
        result += *(u8 *)((u8 *)*slot + 0x28);
        result = (s8)result;
    }
    return (s8)result;
}
#pragma optimization_level reset
s8 fn_80038A48(void *arg0) {
    u8 Status_Test(void *, s32);
    void *Item_GetFlagsPtr(void *);
    void *Res_GetByName(void *);

    s8 var_r31;
    void *class;
    void *unit;
    u8 b;
    s32 s;
    u8 lim_u;
    s8 lim;
    s8 var_r5;
    s8 var_r4;
    s32 index;
    s32 ptr;
    s8 tmp;
    void *item;
    void *other;
    u64 *bits;
    s32 diff;
    s32 sum;

    var_r31 = 0;
    {
        void *c;
        void *u;
        c = *(void **)((u8 *)arg0 + 0x18C);
        u = *(void **)((u8 *)arg0 + 0x188);
        b = *(u8 *)((u8 *)arg0 + 0x1AB);
        s = *(u8 *)((u8 *)c + 0x44);
        lim_u = *(u8 *)((u8 *)c + 0x4C);
        s = s + b;
        b = *(u8 *)((u8 *)u + 0x1D);
        lim = (s8)lim_u;
        var_r4 = *(s8 *)((u8 *)arg0 + 0x1A8);
        var_r5 = (s8)(b + s);
    }
    if (var_r5 > lim) {
        var_r5 = lim;
    }
    if (var_r5 < 0) {
        var_r5 = 0;
    }
    lim = 0;
    if ((((*(u8 *)((u8 *)arg0 + 0x1D1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1CC) != 0)) {
        index = lim;
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
        lim = *(s8 *)((u8 *)*(void **)ptr + 0x1F);
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
        lim = (s8)(lim + *(s8 *)((u8 *)*(void **)ptr + 0x1F));
    }
    tmp = (s8)(var_r5 + lim);
    if (var_r4 <= (s8)(tmp / 2) && (u8)Status_Test((u8 *)arg0 + 0x1BC, 0x10) != 0) {
        class = *(void **)((u8 *)arg0 + 0x18C);
        unit = *(void **)((u8 *)arg0 + 0x188);
        b = *(u8 *)((u8 *)arg0 + 0x1AF);
        s = *(u8 *)((u8 *)class + 0x48);
        lim_u = *(u8 *)((u8 *)class + 0x50);
        s = s + b;
        b = *(u8 *)((u8 *)unit + 0x21);
        lim = (s8)lim_u;
        tmp = (s8)(b + s);
        if (tmp > lim) {
            tmp = lim;
        }
        if (tmp < 0) {
            tmp = 0;
        }
        var_r31 = (s8)(tmp / 2);
    }
    if ((*(u32 *)((u8 *)arg0 + 0x1A0) & 2) != 0 && (u8)Status_Test((u8 *)arg0 + 0x1BC, 0x16) == 0) {
        class = *(void **)((u8 *)arg0 + 0x18C);
        unit = *(void **)((u8 *)arg0 + 0x188);
        b = *(u8 *)((u8 *)arg0 + 0x1AF);
        s = *(u8 *)((u8 *)class + 0x48);
        lim_u = *(u8 *)((u8 *)class + 0x50);
        s = s + b;
        b = *(u8 *)((u8 *)unit + 0x21);
        lim = (s8)lim_u;
        tmp = (s8)(b + s);
        if (tmp > lim) {
            tmp = lim;
        }
        if (tmp < 0) {
            tmp = 0;
        }
        sum = (s8)var_r31 + (s8)tmp;
        var_r31 = (s8)(var_r31 - (sum / 2));
    }
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
        var_r31 = (s8)(var_r31 + *(u8 *)((u8 *)*(void **)ptr + 0x23));
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
        item = *(void **)ptr;
        var_r31 += *(u8 *)((u8 *)item + 0x23);
        bits = (u64 *)Item_GetFlagsPtr(item);
        if ((*bits & 2ULL) != 0) {
            other = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0xC);
            if (other != 0) {
                other = Res_GetByName(other);
            } else {
                other = 0;
            }
            class = *(void **)((u8 *)arg0 + 0x18C);
            diff = (s8)*(u8 *)((u8 *)class + 0x48) - (s8)*(u8 *)((u8 *)other + 0x48);
            var_r31 = (s8)(var_r31 - (s8)(diff / 2));
        }
    }
    return var_r31;
}

#pragma cplusplus off
s8 fn_80038F28(void *arg0) {
void *Item_GetFlagsPtr(void *);
void *Res_GetByName(void *);
u8 Status_Test(void *,s32);
s8 result=0, hp, value, idx;
u8 cap,current;
s8 bonus;
void *base,*person,**slot,*item,*flags,*other;
base=M2C_FIELD(arg0,void **,0x18C);
person=M2C_FIELD(arg0,void **,0x188);
cap=M2C_FIELD(base,u8 *,0x4C);
current=M2C_FIELD(arg0,u8 *,0x1A8);
hp=M2C_FIELD(person,u8 *,0x1D)+(M2C_FIELD(base,u8 *,0x44)+M2C_FIELD(arg0,u8 *,0x1AB));
if(hp>(s8)cap)hp=(s8)cap;
if(hp<0)hp=0;
bonus=0;
if(((M2C_FIELD(arg0,u8 *,465)>>7)&1)&&M2C_FIELD(arg0,void **,460))idx=0;
else if(((M2C_FIELD(arg0,u8 *,473)>>7)&1)&&M2C_FIELD(arg0,void **,468))idx=1;
else if(((M2C_FIELD(arg0,u8 *,481)>>7)&1)&&M2C_FIELD(arg0,void **,476))idx=2;
else if(((M2C_FIELD(arg0,u8 *,489)>>7)&1)&&M2C_FIELD(arg0,void **,484))idx=3;
else idx=-1;
if(idx<0)slot=0;else slot=(void **)((u8 *)arg0+460+idx*8);
if(slot)bonus=M2C_FIELD(*slot,u8 *,0x1F);
if(((M2C_FIELD(arg0,u8 *,497)>>7)&1)&&M2C_FIELD(arg0,void **,492))idx=0;
else if(((M2C_FIELD(arg0,u8 *,505)>>7)&1)&&M2C_FIELD(arg0,void **,500))idx=1;
else if(((M2C_FIELD(arg0,u8 *,513)>>7)&1)&&M2C_FIELD(arg0,void **,508))idx=2;
else if(((M2C_FIELD(arg0,u8 *,521)>>7)&1)&&M2C_FIELD(arg0,void **,516))idx=3;
else idx=-1;
if(idx<0)slot=0;else slot=(void **)((u8 *)arg0+492+idx*8);
if(slot)bonus=(s8)(bonus+M2C_FIELD(*slot,u8 *,0x1F));
if((s8)current<=(s8)(hp+bonus)/2 && Status_Test((u8 *)arg0+0x1BC,0x10)){
base=M2C_FIELD(arg0,void **,0x18C);
person=M2C_FIELD(arg0,void **,0x188);
value=M2C_FIELD(person,u8 *,0x20)+(M2C_FIELD(base,u8 *,0x47)+M2C_FIELD(arg0,u8 *,0x1AE));
if(value>(s8)M2C_FIELD(base,u8 *,0x4F))value=(s8)M2C_FIELD(base,u8 *,0x4F);
if(value<0)value=0;
result=value/2;}
if((M2C_FIELD(arg0,u32 *,0x1A0)&2)&&!Status_Test((u8 *)arg0+0x1BC,0x16)){
base=M2C_FIELD(arg0,void **,0x18C);
person=M2C_FIELD(arg0,void **,0x188);
value=M2C_FIELD(person,u8 *,0x20)+(M2C_FIELD(base,u8 *,0x47)+M2C_FIELD(arg0,u8 *,0x1AE));
if(value>(s8)M2C_FIELD(base,u8 *,0x4F))value=(s8)M2C_FIELD(base,u8 *,0x4F);
if(value<0)value=0;
result-=(result+value)/2;}
if(((M2C_FIELD(arg0,u8 *,465)>>7)&1)&&M2C_FIELD(arg0,void **,460))idx=0;
else if(((M2C_FIELD(arg0,u8 *,473)>>7)&1)&&M2C_FIELD(arg0,void **,468))idx=1;
else if(((M2C_FIELD(arg0,u8 *,481)>>7)&1)&&M2C_FIELD(arg0,void **,476))idx=2;
else if(((M2C_FIELD(arg0,u8 *,489)>>7)&1)&&M2C_FIELD(arg0,void **,484))idx=3;
else idx=-1;
if(idx<0)slot=0;else slot=(void **)((u8 *)arg0+460+idx*8);
if(slot)result+=M2C_FIELD(*slot,u8 *,0x22);
if(((M2C_FIELD(arg0,u8 *,497)>>7)&1)&&M2C_FIELD(arg0,void **,492))idx=0;
else if(((M2C_FIELD(arg0,u8 *,505)>>7)&1)&&M2C_FIELD(arg0,void **,500))idx=1;
else if(((M2C_FIELD(arg0,u8 *,513)>>7)&1)&&M2C_FIELD(arg0,void **,508))idx=2;
else if(((M2C_FIELD(arg0,u8 *,521)>>7)&1)&&M2C_FIELD(arg0,void **,516))idx=3;
else idx=-1;
if(idx<0)slot=0;else slot=(void **)((u8 *)arg0+492+idx*8);
if(slot){
item=*slot;result+=M2C_FIELD(item,u8 *,0x22);
flags=Item_GetFlagsPtr(item);
if((M2C_FIELD(flags,u64 *,0)&2)!=0){
base=M2C_FIELD(arg0,void **,0x18C);
if(M2C_FIELD(base,void **,0xC))other=Res_GetByName(M2C_FIELD(base,void **,0xC));else other=0;
base=M2C_FIELD(arg0,void **,0x18C);
result-=((s8)M2C_FIELD(base,u8 *,0x47)-(s8)M2C_FIELD(other,u8 *,0x47))/2;
}}
return result;
}
s32 fn_80039408(void *arg0) {
    u8 Status_Test(void *, s32);
    void *Item_GetFlagsPtr(void *);
    void *Res_GetByName(void *);
    s32 fn_801660A8(void *);
    void fn_801660C4(s32, u16, u16, u8);
    void fn_80165E90(s32 *, void *);
    extern u8 gBattleState[];

    u8 sp[0x10];
    s8 var_r31;
    void *class;
    void *unit;
    u8 b;
    s32 s;
    s8 lim;
    s8 var_r5;
    s8 var_r4;
    s8 var_r6;
    s32 index;
    s32 ptr;
    s8 tmp;
    void *item;
    void *other;
    u64 *bits;
    s32 id;
    s32 diff;

    var_r31 = 0;
    class = *(void **)((u8 *)arg0 + 0x18C);
    unit = *(void **)((u8 *)arg0 + 0x188);
    b = *(u8 *)((u8 *)arg0 + 0x1AB);
    s = *(u8 *)((u8 *)class + 0x44);
    lim = *(s8 *)((u8 *)class + 0x4C);
    s = s + b;
    s = *(u8 *)((u8 *)unit + 0x1D) + s;
    var_r4 = *(s8 *)((u8 *)arg0 + 0x1A8);
    var_r5 = (s8)s;
    if (var_r5 > lim) {
        var_r5 = lim;
    }
    if (var_r5 < 0) {
        var_r5 = 0;
    }
    var_r6 = 0;
    if ((((*(u8 *)((u8 *)arg0 + 0x1D1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1CC) != 0)) {
        index = var_r6;
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
        var_r6 = *(s8 *)((u8 *)*(void **)ptr + 0x1F);
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
        var_r6 = (s8)(var_r6 + *(s8 *)((u8 *)*(void **)ptr + 0x1F));
    }
    tmp = (s8)(var_r5 + var_r6);
    if (var_r4 <= (s8)(tmp / 2) && (u8)Status_Test((u8 *)arg0 + 0x1BC, 0x10) != 0) {
        class = *(void **)((u8 *)arg0 + 0x18C);
        unit = *(void **)((u8 *)arg0 + 0x188);
        b = *(u8 *)((u8 *)arg0 + 0x1AC);
        s = *(u8 *)((u8 *)class + 0x45);
        lim = *(s8 *)((u8 *)class + 0x4D);
        s = s + b;
        s = *(u8 *)((u8 *)unit + 0x1E) + s;
        tmp = (s8)s;
        if (tmp > lim) {
            tmp = lim;
        }
        if (tmp < 0) {
            tmp = 0;
        }
        var_r31 = (s8)(tmp / 2);
    }
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
        var_r31 = (s8)(var_r31 + *(u8 *)((u8 *)*(void **)ptr + 0x20));
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
        item = *(void **)ptr;
        var_r31 = (s8)(var_r31 + *(u8 *)((u8 *)item + 0x20));
        bits = (u64 *)Item_GetFlagsPtr(item);
        if ((*bits & 2ULL) != 0) {
            other = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0xC);
            if (other != 0) {
                other = Res_GetByName(other);
            } else {
                other = 0;
            }
            class = *(void **)((u8 *)arg0 + 0x18C);
            diff = (s8)*(u8 *)((u8 *)class + 0x45) - (s8)*(u8 *)((u8 *)other + 0x45);
            var_r31 = (s8)(var_r31 - (s8)(diff / 2));
        }
    }
    id = fn_801660A8(gBattleState + 0x3C0);
    unit = *(void **)((u8 *)arg0 + 0x188);
    fn_801660C4(id, *(u16 *)((u8 *)unit + 0x58), *(u16 *)((u8 *)arg0 + 0x228), *(u8 *)((u8 *)unit + 0x55));
    fn_80165E90((s32 *)sp, (u8 *)arg0 + 0x1BC);
    *(u32 *)(sp + 8) = *(u32 *)sp;
    sp[0xC] = sp[4];
    var_r31 += sp[8];
    return var_r31;
}
#pragma dont_inline off
#pragma global_optimizer off
s8 fn_800398B0(void *arg0,u8 arg1) {
 s8 Unit_GetCarryWtLimit(void *);s8 Unit_GetMagAtk(void *);s8 fn_8003AF28(void *);s8 fn_8003AEB0(void *);s8 fn_8003AA40(void *);s8 fn_8003A778(void *);
 u8 Status_Test(void *,s32);
 s8 hp,bonus,value;u8 cap,flag;s32 sum,index,raw;void *ptr,*other,*base,*person;
 switch(arg1){
 case 0:{

 base=M2C_FIELD(arg0,void **,0x18C);person=M2C_FIELD(arg0,void **,0x188);
 cap=M2C_FIELD(base,u8 *,0x4C);
 raw=M2C_FIELD(arg0,u8 *,0x1AB)+M2C_FIELD(base,u8 *,0x44);
 hp=M2C_FIELD(person,u8 *,0x1D)+raw;
 if(hp>(s8)cap)hp=(s8)cap;
 if(hp<0)hp=0;
 bonus=0;
ptr=Unit_GetActiveItemPtr(arg0);
if(ptr)bonus=M2C_FIELD(*(void **)ptr,u8 *,31);
other=fn_80037C20(arg0);
if(other)bonus=(s8)(bonus+M2C_FIELD(*(void **)other,u8 *,31));

 return (s8)(hp+bonus);}
 case 1:return Unit_GetCarryWtLimit(arg0);
 case 2:return Unit_GetMagAtk(arg0);
 case 3:return fn_8003AF28(arg0);
 case 4:return fn_8003AEB0(arg0);
 case 5:{

 value=M2C_FIELD(M2C_FIELD(arg0,void **,0x188),u8 *,0x22)+M2C_FIELD(arg0,u8 *,0x1B0);
 if(value>40)value=40;if(value<0)value=0;
 bonus=0;
ptr=Unit_GetActiveItemPtr(arg0);
if(ptr)bonus=M2C_FIELD(*(void **)ptr,s8 *,36);
other=fn_80037C20(arg0);
if(other)bonus=(s8)(bonus+M2C_FIELD(*(void **)other,u8 *,36));

 value+=bonus;if(value<0)value=0;return value;}
 case 6:return fn_8003AA40(arg0);
 case 7:return fn_8003A778(arg0);
 case 8:{

 sum=M2C_FIELD(M2C_FIELD(arg0,void **,0x188),s8 *,0x1B)+M2C_FIELD(M2C_FIELD(arg0,void **,0x18C),u8 *,0x3C);
 sum+=M2C_FIELD(arg0,s8 *,0x1A9);
 bonus=0;
ptr=Unit_GetActiveItemPtr(arg0);
if(ptr)bonus=M2C_FIELD(*(void **)ptr,s8 *,40);
other=fn_80037C20(arg0);
if(other)bonus=(s8)(bonus+M2C_FIELD(*(void **)other,u8 *,40));

 sum+=(s8)bonus;
 if(sum>99)sum=99;if(sum<0)sum=0;
 return (s8)sum;}
 case 9:{

 if((M2C_FIELD(arg0,u8 *,0x1A4)>>2)&7)return 0;
 sum=M2C_FIELD(M2C_FIELD(arg0,void **,0x18C),u8 *,0x3E);
 sum+=M2C_FIELD(arg0,s8 *,0x1AA);
 flag=Status_Test((u8 *)arg0+0x1BC,14);
 bonus=0;
 sum+=2&((-(s32)flag|(s32)flag)>>31);
ptr=Unit_GetActiveItemPtr(arg0);
if(ptr)bonus=M2C_FIELD(*(void **)ptr,s8 *,39);
other=fn_80037C20(arg0);
if(other)bonus=(s8)(bonus+M2C_FIELD(*(void **)other,u8 *,39));

 sum+=(s8)bonus;
 if(sum>20)sum=20;if(sum<0)sum=0;
 return (s8)sum;}
 default:return -1;
 }
}
#pragma global_optimizer reset
#pragma dont_inline reset
extern u8 lbl_8026A3A8[176];
void *fn_800A88E0(u32);
void *fn_8003A064(void *arg0) {
 void *value;
 if ((u8)Status_Test((u8*)arg0+0x1BC,2)==0) return fn_800A88E0(M2C_FIELD(arg0,u32*,0x188));
 value=(void*)M2C_FIELD(arg0,void**,0x188);
 if (value==(void*)Person_GetByPid(lbl_8026A3A8+0x75)) return lbl_8026A3A8+0x7D;
 value=(void*)M2C_FIELD(arg0,void**,0x188);
 if (value==(void*)Person_GetByPid(lbl_8026A3A8+0x94)) return lbl_8026A3A8+0x88;
 return fn_800A88E0(M2C_FIELD(arg0,u32*,0x188));
}

void *fn_8003A114(void *arg0) {
 void *value;
 if ((u8)Status_Test((u8*)arg0+0x1BC,2)==0) return M2C_FIELD(M2C_FIELD(arg0,void**,0x188),void**,0xC);
 value=M2C_FIELD(arg0,void**,0x188);
 if (value==(void*)Person_GetByPid(lbl_8026A3A8+0x75)) return lbl_8026A3A8+0x9D;
 value=M2C_FIELD(arg0,void**,0x188);
 if (value==(void*)Person_GetByPid(lbl_8026A3A8+0x94)) return lbl_8026A3A8+0xA6;
 return M2C_FIELD(M2C_FIELD(arg0,void**,0x188),void**,0xC);
}

s8 fn_8003A1C4(void *arg0) {
    return (s8) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x18C), u8 *, 0x41) + (((u8) M2C_FIELD(arg0, u8 *, 0x1A6) >> 2U) & 7));
}

#pragma global_optimizer off
s8 fn_8003A1E0(void *arg0)
{
  s32 bonus;
  int new_var;
  s32 value;
  void *ptr;
  bonus = 0;
  new_var = 0x188;
  value = (*((s8 *) (((s8 *) (*((void **) (((s8 *) arg0) + new_var)))) + 0x1C))) + (*((u8 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0x18C)))) + 0x3D)));
  ptr = Unit_GetActiveItemPtr(arg0);
  if (ptr)
  {
    bonus = *((s8 *) (((s8 *) (*((void **) (((s8 *) ptr) + 0)))) + 0x28));
  }
  ptr = fn_80037C20(arg0);
  if (ptr)
  {
    bonus = (s8) (bonus + (*((u8 *) (((s8 *) (*((void **) (((s8 *) ptr) + 0)))) + 0x28))));
  }
  value = ((s8) bonus) + value;
  value = (*((s8 *) (((s8 *) arg0) + 0x1A9))) + value;
  if (value > 99)
  {
    value = 99;
  }
  return (s8) value;
}
#pragma global_optimizer reset
s8 Unit_GetMov(void *arg0) {
    u8 Status_Test(void *, s32);
    s32 sum;
    s32 index;
    s32 ptr;
    s8 bonus;
    u8 flag_ret;
    void *base;

    if (((*(u8 *)((u8 *)arg0 + 0x1A4) >> 2) & 7) != 0) {
        return 0;
    }
    base = *(void **)((u8 *)arg0 + 0x18C);
    sum = *(u8 *)((u8 *)base + 0x3E);
    sum = sum + (s8)*(u8 *)((u8 *)arg0 + 0x1AA);
    flag_ret = Status_Test((u8 *)arg0 + 0x1BC, 0xE);
    bonus = 0;
    sum = sum + (2 & ((-(s32)flag_ret | (s32)flag_ret) >> 31));
    if ((((*(u8 *)((u8 *)arg0 + 0x1D1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1CC) != 0)) {
        index = bonus;
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
        bonus = (s8)*(u8 *)((u8 *)*(void **)ptr + 0x27);
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
        bonus += (s8)*(u8 *)((u8 *)*(void **)ptr + 0x27);
    }
    sum = sum + bonus;
    if (sum > 0x14) {
        sum = 0x14;
    }
    if (sum < 0) {
        sum = 0;
    }
    return (s8)sum;
}
#pragma opt_strength_reduction reset
s8 Unit_GetCon(void *arg0) {
s8 bonus; s32 ptr; s32 index; s32 sum;
sum=(s8)M2C_FIELD(M2C_FIELD(arg0,void **,0x188),u8 *,0x1B);
sum+=M2C_FIELD(M2C_FIELD(arg0,void **,0x18C),u8 *,0x3C);
sum+=(s8)M2C_FIELD(arg0,u8 *,0x1A9);
bonus=0;
    if ((((*(u8 *)((u8 *)arg0 + 0x1D1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1CC) != 0)) {
        index = bonus;
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
        bonus = (s8)*(u8 *)((u8 *)*(void **)ptr + 0x28);
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
        bonus += *(u8 *)((u8 *)*(void **)ptr + 0x28);
    }
    sum = sum + bonus;
    if (sum > 0x63) {
        sum = 0x63;
    }
    if (sum < 0) {
        sum = 0;
    }
    return (s8)sum;
}

s8 fn_8003A778(void *arg0) {
    void *Res_GetByName(void *);
    u64 *Item_GetFlagsPtr(void *);
    void fn_80165E90(void *, void *);
    s32 fn_801660A8(void *);
    void fn_801660C4(s32, u16, u16, u8);
    extern u8 gBattleState[];
    UnkRet800378CC sp10;
    UnkRet800378CC sp8;
    s8 result;
    s8 var_r31;
    s32 var_r30;
    s32 temp;
    void *obj;
    void *other;
    void *p;
    s32 diff;
    s32 id;
    void *t;
    void *b;
    void *a;
    u8 lim;
    s32 sum;

    a = *(void **)((u8 *)arg0 + 0x18C);
    b = *(void **)((u8 *)arg0 + 0x188);
    sum = *(u8 *)((u8 *)a + 0x4B);
    sum += *(u8 *)((u8 *)arg0 + 0x1B2);
    lim = *(u8 *)((u8 *)a + 0x53);
    sum += *(u8 *)((u8 *)b + 0x24);
    var_r31 = (s8)sum;
    if (var_r31 > (s8)lim) {
        var_r31 = (s8)lim;
    }
    if (var_r31 < 0) {
        var_r31 = 0;
    }

    var_r30 = 0;
    if ((((*(u8 *)((u8 *)arg0 + 0x1D1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1CC) != 0)) {
        temp = var_r30;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1D9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1D4) != 0)) {
        temp = 1;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1E1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1DC) != 0)) {
        temp = 2;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1E9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1E4) != 0)) {
        temp = 3;
    } else {
        temp = -1;
    }
    if ((s8)temp < 0) {
        temp = 0;
    } else {
        temp = (s8)temp * 8;
        temp = temp + 0x1CC;
        temp = temp + (s32)arg0;
    }
    if ((u32)temp != 0) {
        var_r30 = (s8)*(u8 *)((u8 *)*(void **)temp + 0x26);
    }

    if ((((*(u8 *)((u8 *)arg0 + 0x1F1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1EC) != 0)) {
        temp = 0;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1F9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1F4) != 0)) {
        temp = 1;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x201) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1FC) != 0)) {
        temp = 2;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x209) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x204) != 0)) {
        temp = 3;
    } else {
        temp = -1;
    }
    if ((s8)temp < 0) {
        temp = 0;
    } else {
        temp = (s8)temp * 8;
        temp = temp + 0x1EC;
        temp = temp + (s32)arg0;
    }
    if ((u32)temp != 0) {
        obj = *(void **)temp;
        var_r30 += *(u8 *)((u8 *)obj + 0x26);
        if ((*Item_GetFlagsPtr((void *)temp) & 2ULL) != 0) {
            p = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0xC);
            if (p != NULL) {
                other = Res_GetByName(p);
            } else {
                other = NULL;
            }
            diff = (s8)*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0x4B) - (s8)*(u8 *)((u8 *)other + 0x4B);
            var_r30 = (s8)(var_r30 - diff / 2);
        }
    }

    var_r30 = (s8)(var_r30 + ((*(u8 *)((u8 *)arg0 + 0x1A6) >> 5) & 7));
    id = fn_801660A8(gBattleState + 0x3C0);
    t = *(void **)((u8 *)arg0 + 0x188);
    fn_801660C4(id, *(u16 *)((u8 *)t + 0x58), *(u16 *)((u8 *)arg0 + 0x228), *(u8 *)((u8 *)t + 0x55));
    fn_80165E90(&sp8, (u8 *)arg0 + 0x1BC);
    sp10 = sp8;
    var_r30 += sp10.unk1;
    result = (s8)(var_r31 + var_r30);
    if (result < 0) {
        result = 0;
    }
    return result;
}

s8 fn_8003AA40(void *arg0) {
    void *Res_GetByName(void *);
    u64 *Item_GetFlagsPtr(void *);
    void fn_80165E90(void *, void *);
    s32 fn_801660A8(void *);
    void fn_801660C4(s32, u16, u16, u8);
    extern u8 gBattleState[];
    UnkRet800378CC sp10;
    UnkRet800378CC sp8;
    void *b;
    s8 var_r31;
    int var_r30;
    u32 temp;
    void *obj;
    void *other;
    void *p;
    s32 diff;
    s32 id;
    void *t;
    s8 result;
    void *a;
    s32 sum;
    s32 lim;

    a = *(void **)((u8 *)arg0 + 0x18C);
    b = *(void **)((u8 *)arg0 + 0x188);
    sum = *(u8 *)((u8 *)a + 0x4A);
    sum += *(u8 *)((u8 *)arg0 + 0x1B1);
    lim = *(s8 *)((u8 *)a + 0x52);
    sum = *(u8 *)((u8 *)b + 0x23) + sum;
    var_r31 = (s8)sum;
    if (var_r31 > lim) {
        var_r31 = lim;
    }
    if (0 > var_r31) {
        var_r31 = 0;
    }

    var_r30 = 0;
    if ((((*(u8 *)((u8 *)arg0 + 0x1D1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1CC) != 0)) {
        temp = var_r30;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1D9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1D4) != 0)) {
        temp = 1;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1E1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1DC) != 0)) {
        temp = 2;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1E9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1E4) != 0)) {
        temp = 3;
    } else {
        temp = -1;
    }
    if ((s8)temp < 0) {
        temp = 0;
    } else {
        temp = (s8)temp * 8;
        temp = temp + 0x1CC;
        temp = temp + (s32)arg0;
    }
    if (temp != 0) {
        var_r30 = (s8)*(u8 *)((u8 *)*(void **)temp + 0x25);
    }

    if ((((*(u8 *)((u8 *)arg0 + 0x1F1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1EC) != 0)) {
        temp = 0;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1F9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1F4) != 0)) {
        temp = 1;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x201) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1FC) != 0)) {
        temp = 2;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x209) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x204) != 0)) {
        temp = 3;
    } else {
        temp = -1;
    }
    if ((s8)temp < 0) {
        temp = 0;
    } else {
        temp = (s8)temp * 8;
        temp = temp + 0x1EC;
        temp = temp + (s32)arg0;
    }
    if (temp != 0) {
        obj = *(void **)temp;
        var_r30 += *(u8 *)((u8 *)obj + 0x25);
        if ((*Item_GetFlagsPtr((void *)temp) & 0x200000000ULL) != 0) {
            p = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0xC);
            if (p != NULL) {
                other = Res_GetByName(p);
            } else {
                other = NULL;
            }
            diff = (s8)*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0x4A) - (s8)*(u8 *)((u8 *)other + 0x4A);
            var_r30 = (s8)(var_r30 - diff / 2);
        }
    }

    id = fn_801660A8(gBattleState + 0x3C0);
    t = *(void **)((u8 *)arg0 + 0x188);
    fn_801660C4(id, *(u16 *)((u8 *)t + 0x58), *(u16 *)((u8 *)arg0 + 0x228), *(u8 *)((u8 *)t + 0x55));
    fn_80165E90(&sp8, (u8 *)arg0 + 0x1BC);
    sp10 = sp8;
    var_r30 += sp10.unk1;
    result = (s8)(var_r31 + var_r30);
    if (result < 0) {
        result = 0;
    }
    return result;
}

s32 fn_8003ACF8(void *arg0) {
u8 *unit = arg0;
s32 temp;
s8 value;
s8 bonus;
s8 result;
value = (s8)(*(u8 *)(*(u8 **)(unit+0x188)+0x22)+unit[0x1B0]);
if(value>40) value=40;
if(value<0) value=0;
bonus=0;
if (((unit[465] >> 7)&1) && *(u32 *)(unit+460) != 0) temp=bonus;
else if (((unit[473] >> 7)&1) && *(u32 *)(unit+468) != 0) temp=1;
else if (((unit[481] >> 7)&1) && *(u32 *)(unit+476) != 0) temp=2;
else if (((unit[489] >> 7)&1) && *(u32 *)(unit+484) != 0) temp=3;
else temp=-1;
if ((s8)temp<0) temp=0;
else {temp=(s8)temp*8; temp+=460; temp+=(s32)unit;}
if(temp!=0) bonus=(s8)*(u8 *)(*(u8 **)temp+0x24);
if (((unit[497] >> 7)&1) && *(u32 *)(unit+492) != 0) temp=0;
else if (((unit[505] >> 7)&1) && *(u32 *)(unit+500) != 0) temp=1;
else if (((unit[513] >> 7)&1) && *(u32 *)(unit+508) != 0) temp=2;
else if (((unit[521] >> 7)&1) && *(u32 *)(unit+516) != 0) temp=3;
else temp=-1;
if ((s8)temp<0) temp=0;
else {temp=(s8)temp*8; temp+=492; temp+=(s32)unit;}
if(temp!=0) bonus=(s8)(bonus+*(u8 *)(*(u8 **)temp+0x24));
result=(s8)(value+bonus); if(result<0) result=0; return result;
}

s8 fn_8003AEB0(void *arg0) {
    s8 fn_80038A48(void *);
    s8 var_r31;
    s8 var_r3;
    u8 temp_r6_2;
    void *temp_r6;

    temp_r6 = M2C_FIELD(arg0, void **, 0x18C);
    temp_r6_2 = M2C_FIELD(temp_r6, u8 *, 0x50);
    var_r31 = M2C_FIELD(temp_r6, u8 *, 0x48) + (M2C_FIELD(arg0, u8 *, 0x1AF) + M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x21));
    if (var_r31 > (s8) temp_r6_2) {
        var_r31 = (s8) temp_r6_2;
    }
    if (var_r31 < 0) {
        var_r31 = 0;
    }
    var_r3 = var_r31 + fn_80038A48(arg0);
    if (var_r3 < 0) {
        var_r3 = 0;
    }
    return var_r3;
}

s8 fn_8003AF28(void *arg0) {
    s8 fn_80038F28(void);
    s8 result;
    s8 lim;
    {
        void *c;
        void *u;
        u8 b;
        s32 s;
        u8 lim_u;
        c = *(void **)((u8 *)arg0 + 0x18C);
        u = *(void **)((u8 *)arg0 + 0x188);
        s = *(u8 *)((u8 *)c + 0x47);
        b = *(u8 *)((u8 *)arg0 + 0x1AE);
        lim_u = *(u8 *)((u8 *)c + 0x4F);
        s = s + b;
        b = *(u8 *)((u8 *)u + 0x20);
        lim = (s8)lim_u;
        result = (s8)(b + s);
    }
    if (result > lim) {
        result = lim;
    }
    if (result < 0) {
        result = 0;
    }
    result = (s8)(result + fn_80038F28());
    if (result < 0) {
        result = 0;
    }
    return result;
}

#pragma global_optimizer off
s8 Unit_GetMagAtk(void *arg0) {
    void *Res_GetByName(void *);
    u64 *Item_GetFlagsPtr(void *);
    void fn_80165E90(void *, void *);
    s32 fn_801660A8(void *);
    void fn_801660C4(s32, u16, u16, u8);
    extern u8 gBattleState[];
    UnkRet800378CC sp10;
    UnkRet800378CC sp8;
    s8 result;
    s8 var_r31;
    s8 var_r30;
    s32 temp;
    void *obj;
    void *other;
    void *p;
    s32 diff;
    s32 id;
    void *t;
    void *a;
    void *unit;
    u8 lim;
    s32 sum;

    unit = arg0;
    a = *(void **)((u8 *)arg0 + 0x18C);
    arg0 = *(void **)((u8 *)arg0 + 0x188);
    sum = *(u8 *)((u8 *)a + 0x46);
    sum += *(u8 *)((u8 *)unit + 0x1AD);
    lim = *(u8 *)((u8 *)a + 0x4E);
    sum += *(u8 *)((u8 *)arg0 + 0x1F);
    var_r31 = (s8)sum;
    if (var_r31 > (s8)lim) {
        var_r31 = (s8)lim;
    }
    if (var_r31 < 0) {
        var_r31 = 0;
    }

    var_r30 = 0;
    if ((((*(u8 *)((u8 *)unit + 0x1D1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)unit + 0x1CC) != 0)) {
        temp = var_r30;
    } else if ((((*(u8 *)((u8 *)unit + 0x1D9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)unit + 0x1D4) != 0)) {
        temp = 1;
    } else if ((((*(u8 *)((u8 *)unit + 0x1E1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)unit + 0x1DC) != 0)) {
        temp = 2;
    } else if ((((*(u8 *)((u8 *)unit + 0x1E9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)unit + 0x1E4) != 0)) {
        temp = 3;
    } else {
        temp = -1;
    }
    if ((s8)temp < 0) {
        temp = 0;
    } else {
        temp = (s8)temp * 8;
        temp = temp + 0x1CC;
        temp = (s32)unit + temp;
    }
    if ((u32)temp != 0) {
        var_r30 = *(u8 *)((u8 *)*(void **)temp + 0x21);
    }

    if ((((*(u8 *)((u8 *)unit + 0x1F1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)unit + 0x1EC) != 0)) {
        temp = 0;
    } else if ((((*(u8 *)((u8 *)unit + 0x1F9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)unit + 0x1F4) != 0)) {
        temp = 1;
    } else if ((((*(u8 *)((u8 *)unit + 0x201) >> 7) & 1) != 0) && (*(u32 *)((u8 *)unit + 0x1FC) != 0)) {
        temp = 2;
    } else if ((((*(u8 *)((u8 *)unit + 0x209) >> 7) & 1) != 0) && (*(u32 *)((u8 *)unit + 0x204) != 0)) {
        temp = 3;
    } else {
        temp = -1;
    }
    if ((s8)temp < 0) {
        temp = 0;
    } else {
        temp = (s8)temp * 8;
        temp = temp + 0x1EC;
        temp = (s32)unit + temp;
    }
    if ((u32)temp != 0) {
        obj = *(void **)temp;
        var_r30 += *(u8 *)((u8 *)obj + 0x21);
        if ((*Item_GetFlagsPtr((void *)temp) & 2ULL) != 0) {
            p = *(void **)((u8 *)*(void **)((u8 *)unit + 0x18C) + 0xC);
            if (p != NULL) {
                other = Res_GetByName(p);
            } else {
                other = (void *)0;
            }
            diff = (s8)*(u8 *)((u8 *)*(void **)((u8 *)unit + 0x18C) + 0x46) - (s8)*(u8 *)((u8 *)other + 0x46);
            var_r30 = (s8)(var_r30 - diff / 2);
        }
    }

    id = fn_801660A8(gBattleState + 0x3C0);
    t = *(void **)((u8 *)unit + 0x188);
    fn_801660C4(id, *(u16 *)((u8 *)t + 0x58), *(u16 *)((u8 *)unit + 0x228), *(u8 *)((u8 *)t + 0x55));
    fn_80165E90(&sp8, (u8 *)unit + 0x1BC);
    sp10 = sp8;
    var_r30 += sp10.unk0;
    result = (s8)(var_r31 + var_r30);
    if (result < 0) {
        result = 0;
    }
    return result;
}
#pragma global_optimizer on
s8 Unit_GetCarryWtLimit(void *arg0) {
    s8 fn_80039408();
    s8 lim;
    void *p188;
    void *p18c;
    s8 var_r31;
    s8 var_r3;

    p18c = *(void **)((u8 *)arg0 + 0x18C);
    p188 = *(void **)((u8 *)arg0 + 0x188);
    lim = *(u8 *)((u8 *)p18c + 0x4D);
    var_r31 = *(u8 *)((u8 *)p18c + 0x45) + (*(u8 *)((u8 *)arg0 + 0x1AC) + *(u8 *)((u8 *)p188 + 0x1E));
    if (var_r31 > lim) {
        var_r31 = lim;
    }
    if (var_r31 < 0) {
        var_r31 = 0;
    }
    var_r3 = var_r31 + fn_80039408();
    if (var_r3 < 0) {
        var_r3 = 0;
    }
    return var_r3;
}

void *Unit_GetActiveItemPtr(void *);
void *fn_80037C20(void *);
s8 Unit_GetMaxHp(void *arg0)
{
    s8 var_r5;
    s8 var_r6;
    void **slot;
    void *temp_r6;
    void *temp_r4;

    temp_r6 = *(void **)((char *)arg0 + 0x18C);
    temp_r4 = *(void **)((char *)arg0 + 0x188);
    var_r5 = (s8)(*(u8 *)((char *)temp_r6 + 0x44) + *(u8 *)((char *)arg0 + 0x1AB)
                 + *(u8 *)((char *)temp_r4 + 0x1D));
    var_r6 = (s8)*(u8 *)((char *)temp_r6 + 0x4C);

    if (var_r5 > var_r6) {
        var_r5 = var_r6;
    }
    if (var_r5 < 0) {
        var_r5 = 0;
    }

    var_r6 = 0;
    slot = Unit_GetActiveItemPtr(arg0);
    if (slot != NULL) {
        var_r6 = (s8)*(u8 *)((char *)*(void **)slot + 0x1F);
    }

    slot = fn_80037C20(arg0);
    if (slot != NULL) {
        var_r6 = (s8)(var_r6 + *(u8 *)((char *)*(void **)slot + 0x1F));
    }

    return (s8)(var_r5 + var_r6);
}

#pragma opt_peephole off
s8 Unit_GetRes(void *arg0) {
    void *p;
    void *q;
    u8 t;
    u8 a;
    s8 lim;
    s8 var;

    p = *(void **)((u8 *)arg0 + 0x18C);
    q = *(void **)((u8 *)arg0 + 0x188);
    t = *(u8 *)((u8 *)arg0 + 0x1B2);
    a = *(u8 *)((u8 *)p + 0x4B);
    lim = *(u8 *)((u8 *)p + 0x53);
    var = *(u8 *)((u8 *)q + 0x24) + a + t;
    if (var > lim) {
        var = lim;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}
#pragma opt_peephole off
s8 Unit_GetDef(void *arg0) {
    void *p18c;
    void *p188;
    u8 t;
    s8 lim;
    s8 var;

    p18c = *(void **)((u8 *)arg0 + 0x18C);
    p188 = *(void **)((u8 *)arg0 + 0x188);
    t = *(u8 *)((u8 *)arg0 + 0x1B1);
    lim = *(u8 *)((u8 *)p18c + 0x52);
    var = (*(u8 *)((u8 *)p188 + 0x23) + *(u8 *)((u8 *)p18c + 0x4A)) + t;
    if (var > lim) {
        var = lim;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}
#pragma opt_peephole reset
s8 Unit_GetLck(void *arg0) {
    s8 var_r3;

    var_r3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x22) + M2C_FIELD(arg0, u8 *, 0x1B0);
    if (var_r3 > 0x28) {
        var_r3 = 0x28;
    }
    if (var_r3 < 0) {
        return 0;
    }
    return var_r3;
}

#pragma opt_peephole off
s8 Unit_GetSpd(void *arg0) {
    void *p18c;
    void *p188;
    u8 t;
    u8 a;
    s8 lim;
    s8 var;

    p18c = *(void **)((u8 *)arg0 + 0x18C);
    p188 = *(void **)((u8 *)arg0 + 0x188);
    t = *(u8 *)((u8 *)arg0 + 0x1AF);
    a = *(u8 *)((u8 *)p18c + 0x48);
    lim = *(u8 *)((u8 *)p18c + 0x50);
    var = (*(u8 *)((u8 *)p188 + 0x21) + a) + t;
    if (var > lim) {
        var = lim;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}
#pragma opt_peephole reset
s8 Unit_GetSkl(void *arg0) {
    void *p18c;
    s8 lim;
    u8 t;
    s8 var;

    p18c = *(void **)((u8 *)arg0 + 0x18C);
    t = *(u8 *)((u8 *)arg0 + 0x1AE);
    lim = *(u8 *)((u8 *)p18c + 0x4F);
    var = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x20) + *(u8 *)((u8 *)p18c + 0x47)) + t;
    if (var > lim) {
        var = lim;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}
#pragma opt_peephole reset
s8 Unit_GetMag(void *arg0) {
    void *p18c;
    u8 t;
    u8 a;
    s8 lim;
    s8 var;

    p18c = *(void **)((u8 *)arg0 + 0x18C);
    t = *(u8 *)((u8 *)arg0 + 0x1AD);
    a = *(u8 *)((u8 *)p18c + 0x46);
    lim = *(u8 *)((u8 *)p18c + 0x4E);
    var = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x1F) + a) + t;
    if (var > lim) {
        var = lim;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}
#pragma opt_peephole reset
s8 Unit_GetStr(void *arg0) {
    void *p18c;
    s8 lim;
    u8 t;
    s8 var;

    p18c = *(void **)((u8 *)arg0 + 0x18C);
    t = *(u8 *)((u8 *)arg0 + 0x1AC);
    lim = *(u8 *)((u8 *)p18c + 0x4D);
    var = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x1E) + *(u8 *)((u8 *)p18c + 0x45)) + t;
    if (var > lim) {
        var = lim;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}

#pragma optimization_level 3
