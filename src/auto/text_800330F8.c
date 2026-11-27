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
void fn_8003333C(u8 *arg0, s32 arg1)
{
  s32 t3;
  int new_var;
  s32 t2;
  s32 t1;
  s32 t4;
  s32 idx;
  u8 n;
  n = arg0[0x60];
  t1 = arg1 + 1;
  t2 = arg1 + 2;
  t3 = arg1 + 3;
  idx = n + arg1;
  t4 = (new_var = arg1 + 4);
  idx = (s32) (arg0 + (idx << 1));
  *((u16 *) (idx + 0x20)) |= 1;
  n = arg0[0x60];
  t1 = n + t1;
  t1 = (s32) (arg0 + (t1 << 1));
  *((u16 *) (t1 + 0x20)) |= 1;
  n = arg0[0x60];
  t2 = n + t2;
  t2 = (s32) (arg0 + (t2 << 1));
  *((u16 *) (t2 + 0x20)) |= 1;
  n = arg0[0x60];
  t3 = n + t3;
  t3 = (s32) (arg0 + (t3 << 1));
  *((u16 *) (t3 + 0x20)) |= 1;
  n = arg0[0x60];
  t4 = n + t4;
  arg0 = arg0 + (t4 << 1);
  *((u16 *) (arg0 + 0x20)) |= 1;
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

#pragma push
#pragma opt_loop_invariants off
void fn_80033418(s16 *script) {
    void DebugPrint(void *, ...);
    void *Msg_ResolveName(void *);
    extern u8 lbl_80269750[];
    extern u8 gUnits[];
    s32 i;
    s16 val;
    u8 *base;
    u8 *unit;

    *script = 0;
    DebugPrint(lbl_80269750 + 0x1d);
    i = 0;
    while (1) {
        if (*(((u8 *)script) + ((*script) * 4) + 4) == 0) {
            break;
        }
        base = ((u8 *)script) + ((*script) * 4);
        switch (base[4]) {
        case 3:
            DebugPrint(lbl_80269750 + 0x2b, (s8)(*(s16 *)(base + 6)));
            break;
        case 4:
            DebugPrint(lbl_80269750 + 0x51, (s8)(*(s16 *)(base + 6)));
            break;
        case 5:
            DebugPrint(lbl_80269750 + 0x73, (s8)(*(s16 *)(base + 6)));
            break;
        case 6:
            DebugPrint(lbl_80269750 + 0x97, (s8)(*(s16 *)(base + 6)));
            break;
        case 7:
            DebugPrint(lbl_80269750 + 0xbb, (s8)(*(s16 *)(base + 6)));
            break;
        case 8:
            DebugPrint(lbl_80269750 + 0xdf, (s8)(*(s16 *)(base + 6)));
            break;
        case 9:
            val = *(s16 *)(base + 6);
            if ((s8)val == 0) {
                DebugPrint(lbl_80269750 + 0x103);
            }
            val = *(s16 *)(((u8 *)script) + ((*script) * 4) + 6);
            if ((s8)val > 0) {
                DebugPrint(lbl_80269750 + 0x129, (s8)val);
            }
            val = *(s16 *)(((u8 *)script) + ((*script) * 4) + 6);
            if ((s8)val < 0) {
                DebugPrint(lbl_80269750 + 0x147, -(s8)val);
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
            DebugPrint(lbl_80269750 + 0x1e3, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x10:
            DebugPrint(lbl_80269750 + 0x209, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x11:
            DebugPrint(lbl_80269750 + 0x22b, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x12:
            DebugPrint(lbl_80269750 + 0x24f, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x13:
            DebugPrint(lbl_80269750 + 0x273, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x14:
            DebugPrint(lbl_80269750 + 0x297, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x15:
            val = *(s16 *)(base + 6);
            if ((s8)val == 0) {
                DebugPrint(lbl_80269750 + 0x2bb);
            }
            val = *(s16 *)(((u8 *)script) + ((*script) * 4) + 6);
            if ((s8)val > 0) {
                DebugPrint(lbl_80269750 + 0x2e1, (s8)val);
            }
            val = *(s16 *)(((u8 *)script) + ((*script) * 4) + 6);
            if ((s8)val < 0) {
                DebugPrint(lbl_80269750 + 0x2ff, -(s8)val);
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
            DebugPrint(lbl_80269750 + 0x709, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x3F:
            DebugPrint(lbl_80269750 + 0x729, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x40:
            DebugPrint(lbl_80269750 + 0x745, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x41:
            DebugPrint(lbl_80269750 + 0x75d);
            break;
        case 0x42:
            DebugPrint(lbl_80269750 + 0x777);
            break;
        case 0x43:
            DebugPrint(lbl_80269750 + 0x791, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x44:
            DebugPrint(lbl_80269750 + 0x7a2, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x45:
            DebugPrint(lbl_80269750 + 0x7b1);
            break;
        case 0x46:
            DebugPrint(lbl_80269750 + 0x7c3, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x47:
            DebugPrint(lbl_80269750 + 0x7d9, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x48:
            DebugPrint(lbl_80269750 + 0x7e9, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x49:
            DebugPrint(lbl_80269750 + 0x7fb, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x4A:
            DebugPrint(lbl_80269750 + 0x80b, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x4B:
            DebugPrint(lbl_80269750 + 0x81d, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x4C:
            DebugPrint(lbl_80269750 + 0x82f, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x4D:
            DebugPrint(lbl_80269750 + 0x841, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x4E:
            DebugPrint(lbl_80269750 + 0x853, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x4F:
            DebugPrint(lbl_80269750 + 0x865, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x19:
            val = *(s16 *)(base + 6);
            if ((u8)(s8)val != 0) {
                unit = gUnits + (((u8)(s8)val - 1) * 0x280);
            } else {
                unit = 0;
            }
            DebugPrint(lbl_80269750 + 0x877, Msg_ResolveName(*(void **)(unit + 0x188)));
            break;
        case 0x1A:
            DebugPrint(lbl_80269750 + 0x89d, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x53:
            DebugPrint(lbl_80269750 + 0x8cd, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x54:
            DebugPrint(lbl_80269750 + 0x8f9, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x55:
            DebugPrint(lbl_80269750 + 0x927, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x56:
            DebugPrint(lbl_80269750 + 0x955, (s8)(*(s16 *)(base + 6)));
            break;
        case 0x57:
            DebugPrint(lbl_80269750 + 0x983, (s8)(*(s16 *)(base + 6)));
            break;
        case 0xD:
        case 0xE:
            break;
        }
        i++;
        *script = (s16)((*script) + 1);
    }
    DebugPrint(lbl_80269750 + 0x9b1, i);
}
#pragma pop
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

#pragma push
#pragma optimization_level 3
#pragma opt_dead_assignments off
#pragma use_lmw_stmw on
void fn_80034130(void *arg0, void *arg1) {
    u8 Status_Test(void *, s32);
    void *fn_80037C20(void *);
    u8 Rand_Chance(s32);
    s32 Unit_GetHp(void *);
    s32 Unit_GetStr(void *);
    s32 Unit_GetMag(void *);
    s32 Unit_GetSkl(void *);
    s32 Unit_GetSpd(void *);
    s32 Unit_GetLck(void *);
    s32 Unit_GetDef(void *);
    s32 Unit_GetRes(void *);
    void BattleAnim_Queue(void *, s32, u8);

    s16 gr[8];
    u8 flag;
    u8 *cls;
    void **slot;
    u8 *bonus;
    s32 i;
    s8 excess;
    s32 stat;
    s32 adj;
    u8 *cap;
    u8 g;

    flag = Status_Test((u8 *)arg0 + 0x1BC, 0x4B);
    cls = *(u8 **)((u8 *)arg0 + 0x188);
    for (i = 0; i < 8; i++) {
        gr[i] = cls[0x25 + i];
    }
    slot = (void **)fn_80037C20(arg0);
    if (slot != NULL && slot[0] != NULL) {
        bonus = (u8 *)slot[0];
        for (i = 0; i < 8; i++) {
            gr[i] += (s8)bonus[0x2A + i];
        }
    }

    {
        u8 gain = 0;
        s16 v;
        for (i = 7; i >= 0; i--) {
            ((u8 *)arg0)[0x2D7 + i] = gain;
        }
        v = gr[0];
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (flag != 0) {
            s32 r = v;
            if (Rand_Chance(r) != 0 || Rand_Chance(r) != 0) {
                gain += 1;
            }
        } else if (Rand_Chance(v) != 0) {
            gain += 1;
        }
        *(u8 *)((u8 *)arg0 + 0x2D7) = gain;
    }

    {
        s16 v = gr[1];
        u8 gain = 0;
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (flag != 0) {
            s32 r = v;
            if (Rand_Chance(r) != 0 || Rand_Chance(r) != 0) {
                gain += 1;
            }
        } else if (Rand_Chance(v) != 0) {
            gain += 1;
        }
        *(u8 *)((u8 *)arg0 + 0x2D8) = gain;
    }

    {
        s16 v = gr[2];
        u8 gain = 0;
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (flag != 0) {
            s32 r = v;
            if (Rand_Chance(r) != 0 || Rand_Chance(r) != 0) {
                gain += 1;
            }
        } else if (Rand_Chance(v) != 0) {
            gain += 1;
        }
        *(u8 *)((u8 *)arg0 + 0x2D9) = gain;
    }

    {
        s16 v = gr[3];
        u8 gain = 0;
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (flag != 0) {
            s32 r = v;
            if (Rand_Chance(r) != 0 || Rand_Chance(r) != 0) {
                gain += 1;
            }
        } else if (Rand_Chance(v) != 0) {
            gain += 1;
        }
        *(u8 *)((u8 *)arg0 + 0x2DA) = gain;
    }

    {
        s16 v = gr[4];
        u8 gain = 0;
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (flag != 0) {
            s32 r = v;
            if (Rand_Chance(r) != 0 || Rand_Chance(r) != 0) {
                gain += 1;
            }
        } else if (Rand_Chance(v) != 0) {
            gain += 1;
        }
        *(u8 *)((u8 *)arg0 + 0x2DB) = gain;
    }

    {
        s16 v = gr[5];
        u8 gain = 0;
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (flag != 0) {
            s32 r = v;
            if (Rand_Chance(r) != 0 || Rand_Chance(r) != 0) {
                gain += 1;
            }
        } else if (Rand_Chance(v) != 0) {
            gain += 1;
        }
        *(u8 *)((u8 *)arg0 + 0x2DC) = gain;
    }

    {
        s16 v = gr[6];
        u8 gain = 0;
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (flag != 0) {
            s32 r = v;
            if (Rand_Chance(r) != 0 || Rand_Chance(r) != 0) {
                gain += 1;
            }
        } else if (Rand_Chance(v) != 0) {
            gain += 1;
        }
        *(u8 *)((u8 *)arg0 + 0x2DD) = gain;
    }

    {
        s16 v = gr[7];
        u8 gain = 0;
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (v >= 0x64) {
            v -= 0x64;
            gain += 1;
        }
        if (flag != 0) {
            s32 r = v;
            if (Rand_Chance(r) != 0 || Rand_Chance(r) != 0) {
                gain += 1;
            }
        } else if (Rand_Chance(v) != 0) {
            gain += 1;
        }
        *(u8 *)((u8 *)arg0 + 0x2DE) = gain;
    }

    stat = Unit_GetHp(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2D7);
    stat = g + stat;
    excess = (s8)(stat - cap[0x4C]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2D7) = g - excess;
    }
    stat = Unit_GetStr(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2D8);
    stat = g + stat;
    excess = (s8)(stat - cap[0x4D]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2D8) = g - excess;
    }
    stat = Unit_GetMag(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2D9);
    stat = g + stat;
    excess = (s8)(stat - cap[0x4E]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2D9) = g - excess;
    }
    stat = Unit_GetSkl(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2DA);
    stat = g + stat;
    excess = (s8)(stat - cap[0x4F]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2DA) = g - excess;
    }
    stat = Unit_GetSpd(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2DB);
    stat = g + stat;
    excess = (s8)(stat - cap[0x50]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2DB) = g - excess;
    }
    {
        u32 g_lck;
        stat = Unit_GetLck(arg0);
        g_lck = *(u8 *)((u8 *)arg0 + 0x2DC);
        adj = stat - 0x28;
        adj = g_lck + adj;
        excess = (s8)adj;
        if (excess >= 0) {
            *(u8 *)((u8 *)arg0 + 0x2DC) = g_lck - excess;
        }
    }
    stat = Unit_GetDef(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2DD);
    stat = g + stat;
    excess = (s8)(stat - cap[0x52]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2DD) = g - excess;
    }
    stat = Unit_GetRes(arg0);
    cap = *(u8 **)((u8 *)arg0 + 0x18C);
    g = *(u8 *)((u8 *)arg0 + 0x2DE);
    stat = g + stat;
    excess = (s8)(stat - cap[0x53]);
    if (excess >= 0) {
        *(u8 *)((u8 *)arg0 + 0x2DE) = g - excess;
    }

    g = *(u8 *)((u8 *)arg0 + 0x2D7);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x2A, g);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2D8);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x2B, g);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2D9);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x2C, g);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2DA);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x2D, g);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2DB);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x2E, g);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2DC);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x2F, g);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2DD);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x30, g);
    }
    g = *(u8 *)((u8 *)arg0 + 0x2DE);
    if ((s8)g != 0) {
        BattleAnim_Queue(arg1, 0x31, g);
    }
}
#pragma pop

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

void fn_80034A8C(u8 *arg0, void *arg1, u8 value, void *arg3, u8 arg4) {
    u8 fn_8003D094(void *, u8);
    u8 fn_8003D13C(void *);
    void Battle_SetupUnit(void *, void *, s32);
    s32 fn_800386B0(void *);
    void BattleAnim_Queue(void *, s32, s8);
    void fn_8014C5F4(void *, s32);
    void fn_800351FC(void *, u8, s32, void *);
    void Battle_TryStartGrowSeq(void *);
    extern u8 gBattleState[];

    if (arg4) {
        value = fn_8003D094(arg1, value);
    }
    if (value > fn_8003D13C(arg1)) {
        value = fn_8003D13C(arg1);
    }
    if (value != 0) {
        Battle_SetupUnit(arg0, arg1, -1);
        BattleAnim_Queue(arg0 + 0x8A0, 0x27, (s8)fn_800386B0(arg1));
        if (value > fn_8003D13C(arg1)) {
            value = fn_8003D13C(arg1);
        }
        BattleAnim_Queue(arg0 + 0x8A0, 0x28, (s8)value);
        arg0[0x2C9] = value;
        fn_8014C5F4(gBattleState, value);
        fn_800351FC(arg0, value, 0, arg0 + 0x8A0);
        Battle_TryStartGrowSeq(arg3);
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

void fn_80034F40(void *arg0_) {
    s8 *arg0 = (s8 *)arg0_;
    M2C_UNK fn_8003708C();
    M2C_UNK fn_8003868C();
    u8 fn_800386B0();
    u8 temp_r0;
    s8 *temp_r3;
    s8 *temp_r4;

    temp_r4 = M2C_FIELD(arg0, s8 **, 0x280);
    temp_r0 = M2C_FIELD(M2C_FIELD(temp_r4, s8 **, 0x190), u8 *, 8);
    if ((temp_r0 == 0) || (temp_r0 == 5)) {
        M2C_FIELD(temp_r4, u8 *, 0x19A) = (u8) M2C_FIELD(arg0, u8 *, 0x19A);
        fn_8003868C(M2C_FIELD(arg0, s8 **, 0x280), fn_800386B0(arg0));
    }
    fn_8003708C(M2C_FIELD(arg0, s8 **, 0x280), arg0 + 0x2D7);
    temp_r3 = M2C_FIELD(arg0, s8 **, 0x280);
    M2C_FIELD(temp_r3, u8 *, 0x1B4) = (u8) M2C_FIELD(arg0, u8 *, 0x1B4);
    M2C_FIELD(temp_r3, u8 *, 0x1B5) = (u8) M2C_FIELD(arg0, u8 *, 0x1B5);
    M2C_FIELD(temp_r3, u8 *, 0x1B6) = (u8) M2C_FIELD(arg0, u8 *, 0x1B6);
    M2C_FIELD(temp_r3, u8 *, 0x1B7) = (u8) M2C_FIELD(arg0, u8 *, 0x1B7);
    M2C_FIELD(temp_r3, u8 *, 0x1B8) = (u8) M2C_FIELD(arg0, u8 *, 0x1B8);
    M2C_FIELD(temp_r3, u8 *, 0x1B9) = (u8) M2C_FIELD(arg0, u8 *, 0x1B9);
    M2C_FIELD(temp_r3, u8 *, 0x1BA) = (u8) M2C_FIELD(arg0, u8 *, 0x1BA);
    M2C_FIELD(temp_r3, u8 *, 0x1BB) = (u8) M2C_FIELD(arg0, u8 *, 0x1BB);
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

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
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
    extern const f32 lbl_80368E8C;
    extern const f32 lbl_80368EA0;

    f32 vals[8];
    s8 *p;
    void *tmp;
    void **pp;
    s32 i;

    if (fn_8014DA68() == 0) {
        if (arg1 != 0) {
            *(u32 *)(gBattle + 0xCAC) |= 0x400;
        }
        arg1 += fn_800386B0(arg0);
        if (arg1 >= 0x64) {
            arg1 -= 0x64;
            ((s8 *)arg0)[0x19A]++;
            *(u32 *)(gBattle + 0xCAC) |= 0x800;
            if (Unit_GetLevel_19A(arg0) > 0x14) {
                *(u32 *)((u8 *)arg0 + 0x1A0) |= 0x40000;
                *(u32 *)(gBattle + 0xCAC) |= 0x10;
            } else {
                BattleAnim_Queue(arg3, 0x29);
                fn_80034130(arg0, arg3);
            }
        }
        ((u8 *)arg0)[0x19B] = arg1;
        if (fn_8003D13C(arg0) == 0) {
            ((u8 *)arg0)[0x19B] = 0xFF;
        }
        return;
    }

    for (i = 7; i >= 0; i--) {
        vals[i] = lbl_80368EA0;
    }
    tmp = *(void **)((u8 *)arg0 + 0x188);
    if (tmp != NULL) {
        for (i = 0; i < 8; i++) {
            vals[i] = lbl_80368EA0 + (f32)((u8 *)tmp)[0x25 + i];
        }
    }
    DebugPrint(lbl_8026A120 + 0xCE);
    {
        s8 zeros[8];
        for (i = 7; i >= 0; i--) {
            zeros[i] = 0;
        }
        p = zeros;
        DebugPrint(lbl_8026A120 + 0xE6, 0, vals[0]);
        DebugPrint(lbl_8026A120 + 0xFA, p[1], vals[1]);
        DebugPrint(lbl_8026A120 + 0x10E, p[2], vals[2]);
        DebugPrint(lbl_8026A120 + 0x122, p[3], vals[3]);
        DebugPrint(lbl_8026A120 + 0x136, p[4], vals[4]);
        DebugPrint(lbl_8026A120 + 0x14A, p[5], vals[5]);
        DebugPrint(lbl_8026A120 + 0x15E, p[6], vals[6]);
        DebugPrint(lbl_8026A120 + 0x172, p[7], vals[7]);
    }

    if (arg2 != NULL) {
        tmp = *(void **)((u8 *)arg2 + 0x18C);
        if (tmp != NULL) {
            for (i = 0; i < 8; i++) {
                vals[i] += (f32)((s8 *)tmp)[0x5C + i];
            }
        }
        DebugPrint(lbl_8026A120 + 0x186);
        {
            s8 zeros[8];
            p = (s8 *)*(void **)((u8 *)arg2 + 0x18C) + 0x5C;
            if (p == NULL) {
                for (i = 7; i >= 0; i--) {
                    zeros[i] = 0;
                }
                p = zeros;
            }
            DebugPrint(lbl_8026A120 + 0xE6, p[0], vals[0]);
            DebugPrint(lbl_8026A120 + 0xFA, p[1], vals[1]);
            DebugPrint(lbl_8026A120 + 0x10E, p[2], vals[2]);
            DebugPrint(lbl_8026A120 + 0x122, p[3], vals[3]);
            DebugPrint(lbl_8026A120 + 0x136, p[4], vals[4]);
            DebugPrint(lbl_8026A120 + 0x14A, p[5], vals[5]);
            DebugPrint(lbl_8026A120 + 0x15E, p[6], vals[6]);
            DebugPrint(lbl_8026A120 + 0x172, p[7], vals[7]);
        }
    }

    pp = (void **)((u8 *)arg0 + 0x28C);
    if (pp != NULL) {
        tmp = *pp;
        if (tmp != NULL) {
            for (i = 0; i < 8; i++) {
                vals[i] += (f32)((s8 *)tmp)[0x2A + i];
            }
        }
    }
    DebugPrint(lbl_8026A120 + 0x194);
    {
        s8 zeros[8];
        tmp = *(void **)((u8 *)arg0 + 0x28C);
        if (tmp != NULL) {
            p = (s8 *)tmp + 0x2A;
        } else {
            p = NULL;
        }
        if (p == NULL) {
            for (i = 7; i >= 0; i--) {
                zeros[i] = 0;
            }
            p = zeros;
        }
        DebugPrint(lbl_8026A120 + 0xE6, p[0], vals[0]);
        DebugPrint(lbl_8026A120 + 0xFA, p[1], vals[1]);
        DebugPrint(lbl_8026A120 + 0x10E, p[2], vals[2]);
        DebugPrint(lbl_8026A120 + 0x122, p[3], vals[3]);
        DebugPrint(lbl_8026A120 + 0x136, p[4], vals[4]);
        DebugPrint(lbl_8026A120 + 0x14A, p[5], vals[5]);
        DebugPrint(lbl_8026A120 + 0x15E, p[6], vals[6]);
        DebugPrint(lbl_8026A120 + 0x172, p[7], vals[7]);
    }

    pp = fn_80037C20(arg0);
    if (pp != NULL) {
        tmp = *pp;
        if (tmp != NULL) {
            for (i = 0; i < 8; i++) {
                vals[i] += (f32)((s8 *)tmp)[0x2A + i];
            }
        }
    }
    DebugPrint(lbl_8026A120 + 0x1A0);
    {
        s8 zeros[8];
        if (fn_80037CCC(arg0) >= 0) {
            p = (s8 *)(*fn_80037C20(arg0)) + 0x2A;
        } else {
            p = NULL;
        }
        if (p == NULL) {
            for (i = 7; i >= 0; i--) {
                zeros[i] = 0;
            }
            p = zeros;
        }
        DebugPrint(lbl_8026A120 + 0xE6, p[0], vals[0]);
        DebugPrint(lbl_8026A120 + 0xFA, p[1], vals[1]);
        DebugPrint(lbl_8026A120 + 0x10E, p[2], vals[2]);
        DebugPrint(lbl_8026A120 + 0x122, p[3], vals[3]);
        DebugPrint(lbl_8026A120 + 0x136, p[4], vals[4]);
        DebugPrint(lbl_8026A120 + 0x14A, p[5], vals[5]);
        DebugPrint(lbl_8026A120 + 0x15E, p[6], vals[6]);
        DebugPrint(lbl_8026A120 + 0x172, p[7], vals[7]);
    }

    vals[0] = (vals[0] * (f32)arg1) / lbl_80368E8C;
    vals[1] = (vals[1] * (f32)arg1) / lbl_80368E8C;
    vals[2] = (vals[2] * (f32)arg1) / lbl_80368E8C;
    vals[3] = (vals[3] * (f32)arg1) / lbl_80368E8C;
    vals[4] = (vals[4] * (f32)arg1) / lbl_80368E8C;
    vals[5] = (vals[5] * (f32)arg1) / lbl_80368E8C;
    vals[6] = (vals[6] * (f32)arg1) / lbl_80368E8C;
    vals[7] = (vals[7] * (f32)arg1) / lbl_80368E8C;
    DebugPrint(lbl_8026A120 + 0x1B2, arg1);
    {
        s8 zeros[8];
        for (i = 7; i >= 0; i--) {
            zeros[i] = 0;
        }
        p = zeros;
        DebugPrint(lbl_8026A120 + 0xE6, 0, vals[0]);
        DebugPrint(lbl_8026A120 + 0xFA, p[1], vals[1]);
        DebugPrint(lbl_8026A120 + 0x10E, p[2], vals[2]);
        DebugPrint(lbl_8026A120 + 0x122, p[3], vals[3]);
        DebugPrint(lbl_8026A120 + 0x136, p[4], vals[4]);
        DebugPrint(lbl_8026A120 + 0x14A, p[5], vals[5]);
        DebugPrint(lbl_8026A120 + 0x15E, p[6], vals[6]);
        DebugPrint(lbl_8026A120 + 0x172, p[7], vals[7]);
    }
    DebugPrint(lbl_8026A120 + 0x1D0);
    DebugPrint(lbl_8026A120 + 0x1EA);
    DebugPrint(lbl_8026A120 + 0x213,
        ((u8 *)arg0)[0x1B4], ((u8 *)arg0)[0x1B5],
        ((u8 *)arg0)[0x1B6], ((u8 *)arg0)[0x1B7],
        ((u8 *)arg0)[0x1B8], ((u8 *)arg0)[0x1B9],
        ((u8 *)arg0)[0x1BA], ((u8 *)arg0)[0x1BB]);
    Unit_AddGrowthProgress(arg0, vals);
    DebugPrint(lbl_8026A120 + 0x23C);
    DebugPrint(lbl_8026A120 + 0x1EA);
    DebugPrint(lbl_8026A120 + 0x213,
        ((u8 *)arg0)[0x1B4], ((u8 *)arg0)[0x1B5],
        ((u8 *)arg0)[0x1B6], ((u8 *)arg0)[0x1B7],
        ((u8 *)arg0)[0x1B8], ((u8 *)arg0)[0x1B9],
        ((u8 *)arg0)[0x1BA], ((u8 *)arg0)[0x1BB]);

    if (arg1 != 0) {
        *(u32 *)(gBattle + 0xCAC) |= 0x400;
    }
    arg1 += fn_800386B0(arg0);
    if (arg1 >= 0x64) {
        arg1 -= 0x64;
        ((s8 *)arg0)[0x19A]++;
        *(u32 *)(gBattle + 0xCAC) |= 0x800;
        if (Unit_GetLevel_19A(arg0) > 0x14) {
            *(u32 *)((u8 *)arg0 + 0x1A0) |= 0x40000;
            *(u32 *)(gBattle + 0xCAC) |= 0x10;
        } else {
            BattleAnim_Queue(arg3, 0x29);
            Unit_CalcLevelUpGrowths(arg0, arg3);
        }
    }
    ((u8 *)arg0)[0x19B] = arg1;
    if (fn_8003D13C(arg0) == 0) {
        ((u8 *)arg0)[0x19B] = 0xFF;
    }
}
#pragma pop
void fn_80036150(s32 arg0) {
    u8 fn_8003D13C(s32);
    void BattleAnim_Queue(s32, s32, s8);
    s32 fn_800386B0(s32);
    u8 fn_8003D094(s32, u8);
    void fn_8014C5F4(void *, s32);
    void fn_800351FC(s32, u8, s32, s32);
    extern u8 gBattleState[];
    u8 var_r30;

    if (fn_8003D13C(arg0) != 0) {
        BattleAnim_Queue(arg0 + 0x8A0, 0x25, 0);
        BattleAnim_Queue(arg0 + 0x8A0, 0x27, (s8)fn_800386B0(arg0));
        var_r30 = fn_8003D094(arg0, (u8)(*(u16 *)((u8 *)*(void **)(arg0 + 0x28C) + 0x10) / 20 + 0xA));
        if (var_r30 > fn_8003D13C(arg0)) {
            var_r30 = fn_8003D13C(arg0);
        }
        BattleAnim_Queue(arg0 + 0x8A0, 0x28, (s8)var_r30);
        *(u8 *)(arg0 + 0x2C9) = var_r30;
        fn_8014C5F4(gBattleState, var_r30);
        fn_800351FC(arg0, var_r30, 0, arg0 + 0x8A0);
    }
}
static inline u8 Battle_CalcBaseExp(s32 atk, s32 def) {
    s8 fn_801F1C5C(void);
    u8 fn_8003863C(void *);
    s32 t = fn_801F1C5C();
    s32 u = (u8)fn_8003863C((void *)def);
    t = t + (u - (u8)fn_8003863C((void *)atk));
    t = (t + 1) / 2;
    if (t < 1) {
        t = 1;
    }
    return (u8)t;
}

static inline u8 Battle_CalcBonusExp(s32 atk, s32 def) {
    s8 fn_801F1CE8(void);
    u8 fn_800385E4(void *);
    u8 fn_80038570(void *);
    s32 t;
    if (*(s8 *)(def + 0x1A8) != 0) {
        return 0;
    }
    t = fn_801F1CE8();
    t = t + (u8)fn_800385E4((void *)def);
    t = t - (u8)fn_800385E4((void *)atk);
    t = t + (u8)fn_80038570((void *)def);
    if (t < 0) {
        t = 0;
    }
    return (u8)t;
}

static inline u8 Battle_CalcSideHits(s32 atk, s32 def, s32 out) {
    extern u8 lbl_8026A120[];
    extern u8 gBattleState[];
    void DebugPrint(void *, ...);
    void BattleAnim_Queue(void *, s32, s8);
    u8 fn_800386B0(void *);
    u8 fn_8003D094(void *, u8);
    u8 fn_8003D13C(void *);
    u8 Status_Test(void *, s32);
    void fn_8014C5F4(void *, s32);
    u8 hit;

    if ((u8)Status_Test((void *)(def + 0x1BC), 7) != 0) {
        return 0;
    }
    BattleAnim_Queue((void *)out, 0x27, (s8)fn_800386B0((void *)atk));
    if (*(u8 *)(atk + 0x2D6) == 0) {
        hit = fn_8003D094((void *)atk, 1);
    } else {
        u8 base = Battle_CalcBaseExp(atk, def);
        u8 bonus = Battle_CalcBonusExp(atk, def);
        hit = fn_8003D094((void *)atk, (u8)(base + bonus));
    }
    if ((u8)hit > (u8)fn_8003D13C((void *)atk)) {
        hit = fn_8003D13C((void *)atk);
    }
    BattleAnim_Queue((void *)out, 0x28, (s8)hit);
    *(u8 *)(atk + 0x2C9) = hit;
    fn_8014C5F4(gBattleState, (u8)hit);
    {
        u8 base = Battle_CalcBaseExp(atk, def);
        u8 bonus = Battle_CalcBonusExp(atk, def);
        DebugPrint(lbl_8026A120 + 0x256, (u8)hit, base, bonus);
    }
    return hit;
}

#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
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
    s32 t;
    s32 u;
    u8 v;
    u8 hit;
    u32 out;

    if (*(u32 *)(self + 0x190) != *(u32 *)(self + 0x470)) {
        if ((u8)fn_8003D13C((void *)self) != 0) {
            out = self + 0x8A0;
            if ((u8)Status_Test((void *)(self + 0x49C), 7) != 0) {
                hit = 0;
            } else {
                u8 arg;
                BattleAnim_Queue((void *)out, 0x27, (s8)fn_800386B0((void *)self));
                if (*(u8 *)(self + 0x2D6) == 0) {
                    arg = 1;
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
                        t = t + (u8)fn_80038570((void *)(self + 0x2E0));
                        if (t < 0) {
                            t = 0;
                        }
                        v = (u8)t;
                    }
                    arg = (u8)((u8)u + v);
                }
                hit = fn_8003D094((void *)self, arg);
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
                    t = t + (u8)fn_80038570((void *)(self + 0x2E0));
                    if (t < 0) {
                        t = 0;
                    }
                    v = (u8)t;
                }
                DebugPrint(lbl_8026A120 + 0x256, (u8)out, (u8)u, v);
            }
            if ((u8)hit == 0) {
                return;
            }
            BattleAnim_Queue((void *)(self + 0x8A0), 0x25, 0);
            fn_800351FC((void *)self, hit, (void *)(self + 0x2E0), (void *)(self + 0x8A0));
        }
        if ((u8)fn_8003D13C((void *)(self + 0x2E0)) != 0) {
            out = self + 0x8A0;
            if ((u8)Status_Test((void *)(self + 0x1BC), 7) != 0) {
                hit = 0;
            } else {
                u8 arg;
                BattleAnim_Queue((void *)out, 0x27, (s8)fn_800386B0((void *)(self + 0x2E0)));
                if (*(u8 *)(self + 0x5B6) == 0) {
                    arg = 1;
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
                        t = t + (u8)fn_80038570((void *)self);
                        if (t < 0) {
                            t = 0;
                        }
                        v = (u8)t;
                    }
                    arg = (u8)((u8)u + v);
                }
                hit = fn_8003D094((void *)(self + 0x2E0), arg);
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
                    t = t + (u8)fn_80038570((void *)self);
                    if (t < 0) {
                        t = 0;
                    }
                    v = (u8)t;
                }
                DebugPrint(lbl_8026A120 + 0x256, (u8)out, (u8)u, v);
            }
            if ((u8)hit != 0) {
                BattleAnim_Queue((void *)(self + 0x8A0), 0x26, 0);
                fn_800351FC((void *)(self + 0x2E0), hit, (void *)self, (void *)(self + 0x8A0));
            }
        }
    }
}
#pragma pop
