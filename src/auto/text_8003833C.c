/* Functions from 0x800330F8 to 0x80055C70, found by decomp-toolkit. */
#include "common.h"
static inline void *Unit_GetActiveItemPtr_Inline(void *arg0) {
    s8 index;
    if ((((u8)M2C_FIELD(arg0, u8 *, 0x1D1) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1CC) != 0) index = 0;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x1D9) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1D4) != 0) index = 1;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x1E1) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1DC) != 0) index = 2;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x1E9) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1E4) != 0) index = 3;
    else index = -1;
    if (index < 0) return NULL;
    return (u8 *)arg0 + (index * 8) + 0x1CC;
}
static inline void *Unit_GetActiveEquipPtr_Inline(void *arg0) {
    s8 index;
    if ((((u8)M2C_FIELD(arg0, u8 *, 0x1F1) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1EC) != 0) index = 0;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x1F9) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1F4) != 0) index = 1;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x201) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1FC) != 0) index = 2;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x209) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x204) != 0) index = 3;
    else index = -1;
    if (index < 0) return NULL;
    return (u8 *)arg0 + (index * 8) + 0x1EC;
}
static inline s8 Unit_39408BaseStat(void *self, s32 index) {
    void *class = *(void **)((u8 *)self + 0x18C);
    void *unit = *(void **)((u8 *)self + 0x188);
    s8 value = *(u8 *)((u8 *)unit + 0x1D + index) +
        (*(u8 *)((u8 *)class + 0x44 + index) + *(u8 *)((u8 *)self + 0x1AB + index));
    s8 limit = *(s8 *)((u8 *)class + 0x4C + index);
    if (value > limit) value = limit;
    if (value < 0) value = 0;
    return value;
}
static inline s8 Unit_GetCappedStatIn(u8 *self, s32 classOffset, s32 unitOffset, s32 bonusOffset) {
    u8 *c=*(u8 **)(self+0x18C);
    u8 *u=*(u8 **)(self+0x188);
    s8 value=(s8)(u[unitOffset]+(c[classOffset]+self[bonusOffset]));
    s8 limit=(s8)c[classOffset+8];
    if(value>limit) value=limit;
    if(value<0) value=0;
    return value;
}
static inline s8 Unit_FindEquippedIndexIn(u8 *self, s32 offset) {
    s32 i;
    for (i=0; i<4; ++i) {
        if (((self[offset+i*8+5] >> 7) & 1) && *(void **)(self+offset+i*8)) return i;
    }
    return -1;
}
static inline void *Unit_FindEquippedSlotIn(u8 *self, s32 offset) {
    s8 index=Unit_FindEquippedIndexIn(self,offset);
    if(index<0) return 0;
    return self+offset+index*8;
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
void *Unit_GetActiveItemPtr(void *);
void *fn_80037C20(void *);

void Unit_SetMapPos(void *arg0, s8 arg1, s8 arg2) {
void Unit_SetWorldXY(void *, f32, f32);
extern f32 lbl_80368EC0;
void *child;
f32 base, fx, fy;
*(s8*)((u8*)arg0+0x19e)=arg1;
*(s8*)((u8*)arg0+0x19f)=arg2;
child=*(void**)((u8*)arg0+0x194);
if(child!=NULL) {
*(s8*)((u8*)child+0x19e)=arg1;
base=lbl_80368EC0;
fx=(f32)arg1;
fy=(f32)arg2;
fx=base+fx;
*(s8*)((u8*)child+0x19f)=arg2;
fy=base+fy;
Unit_SetWorldXY(child,fx,fy);
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

#pragma push
#pragma optimization_level 4
s8 fn_80038748(void *arg0) {
    struct Slot {
        s8 *item;
        u8 pad;
        u8 flags;
        u8 pad2[2];
    };
    struct Unit {
        u8 pad[0x1CC];
        struct Slot weapons[4];
        struct Slot acc[4];
    };
    struct Unit *u = (struct Unit *)arg0;
    s8 result;
    s8 temp;
    s32 i;
    struct Slot *slot;

    result = 0;
    for (i = 0; i < 4; i++) {
        if (((u->weapons[i].flags >> 7) & 1) && u->weapons[i].item != 0) {
            temp = i;
            goto found1;
        }
    }
    temp = -1;
found1:
    if (temp < 0) {
        slot = 0;
    } else {
        slot = &u->weapons[temp];
    }
    if (slot != 0) {
        result += slot->item[0x27];
    }
    for (i = 0; i < 4; i++) {
        if (((u->acc[i].flags >> 7) & 1) && u->acc[i].item != 0) {
            temp = i;
            goto found2;
        }
    }
    temp = -1;
found2:
    if (temp < 0) {
        slot = 0;
    } else {
        slot = &u->acc[temp];
    }
    if (slot != 0) {
        result += slot->item[0x27];
    }
    return result;
}
#pragma pop
s8 fn_800388C8(void *arg0) {
    struct Slot {
        s8 *item;
        u8 pad;
        u8 flags;
        u8 pad2[2];
    };
    struct Unit {
        u8 pad[0x1CC];
        struct Slot weapons[4];
        struct Slot acc[4];
    };
    struct Unit *u = (struct Unit *)arg0;
    s8 result;
    s8 temp;
    s32 i;
    struct Slot *slot;

    result = 0;
    for (i = 0; i < 4; i++) {
        if (((u->weapons[i].flags >> 7) & 1) && u->weapons[i].item != 0) {
            temp = i;
            goto found1;
        }
    }
    temp = -1;
found1:
    if (temp < 0) {
        slot = 0;
    } else {
        slot = &u->weapons[temp];
    }
    if (slot != 0) {
        result += slot->item[0x28];
    }
    for (i = 0; i < 4; i++) {
        if (((u->acc[i].flags >> 7) & 1) && u->acc[i].item != 0) {
            temp = i;
            goto found2;
        }
    }
    temp = -1;
found2:
    if (temp < 0) {
        slot = 0;
    } else {
        slot = &u->acc[temp];
    }
    if (slot != 0) {
        result += slot->item[0x28];
    }
    return result;
}
#pragma push
#pragma optimization_level 4
#pragma opt_strength_reduction off
s8 fn_80038A48(void *arg0) {
    u8 fn_80105BC0(void *, s32);
    void *fn_8001CB64(void *);
    void *fn_8000D354(void *);

    s8 var_r31;
    void *class;
    void *unit;
    u8 b;
    unsigned long s;
    u8 lim_u;
    s8 lim;
    s8 var_r5;
    s8 var_r4;
    s32 index;
    unsigned long ptr;
    u64 *bits;
    void *item;
    void *other;
    s8 tmp;
    s32 diff;
    int sum;

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
    if (0 > var_r5) {
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
        lim = *(u8 *)((u8 *)*(void **)ptr + 0x1F);
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
        lim = (s8)(lim + *(u8 *)((u8 *)*(void **)ptr + 0x1F));
    }
    tmp = (s8)(var_r5 + lim);
    if (var_r4 <= tmp / 2 && (u8)fn_80105BC0((u8 *)arg0 + 0x1BC, 0x10) != 0) {
        class = *(void **)((u8 *)arg0 + 0x18C);
        unit = *(void **)((u8 *)arg0 + 0x188);
        s = *(u8 *)((u8 *)class + 0x48);
        b = *(u8 *)((u8 *)arg0 + 0x1AF);
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
    if ((*(u32 *)((u8 *)arg0 + 0x1A0) & 2) != 0 && (u8)fn_80105BC0((u8 *)arg0 + 0x1BC, 0x16) == 0) {
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
    } else if ((((*(u8 *)((u8 *)arg0 + (s32)0x1E1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1DC) != 0)) {
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
        bits = (u64 *)fn_8001CB64((void *)ptr);
        if ((*bits & 0x200000000ULL) != 0) {
            other = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0xC);
            if (other != 0) {
                other = fn_8000D354(other);
            } else {
                other = 0;
            }
            class = *(void **)((u8 *)arg0 + 0x18C);
            diff = (s8)*(u8 *)((u8 *)class + 0x48) - (s8)*(u8 *)((u8 *)other + 0x48);
            var_r31 = (s8)(var_r31 - (diff / 2));
        }
    }
    return var_r31;
}
#pragma pop
s8 fn_80038F28(void *arg0) {
void *fn_8001CB64(void *);
void *fn_8000D354(void *);
u8 fn_80105BC0(void *,s32);
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
if((s8)current<=(s8)(hp+bonus)/2 && fn_80105BC0((u8 *)arg0+0x1BC,0x10)){
base=M2C_FIELD(arg0,void **,0x18C);
person=M2C_FIELD(arg0,void **,0x188);
value=M2C_FIELD(person,u8 *,0x20)+(M2C_FIELD(base,u8 *,0x47)+M2C_FIELD(arg0,u8 *,0x1AE));
if(value>(s8)M2C_FIELD(base,u8 *,0x4F))value=(s8)M2C_FIELD(base,u8 *,0x4F);
if(value<0)value=0;
result=value/2;}
if((M2C_FIELD(arg0,u32 *,0x1A0)&2)&&!fn_80105BC0((u8 *)arg0+0x1BC,0x16)){
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
flags=fn_8001CB64(item);
if((M2C_FIELD(flags,u64 *,0)&2)!=0){
base=M2C_FIELD(arg0,void **,0x18C);
if(M2C_FIELD(base,void **,0xC))other=fn_8000D354(M2C_FIELD(base,void **,0xC));else other=0;
base=M2C_FIELD(arg0,void **,0x18C);
result-=((s8)M2C_FIELD(base,u8 *,0x47)-(s8)M2C_FIELD(other,u8 *,0x47))/2;
}}
return result;
}
s32 fn_80039408(void *arg0) {
    u8 fn_80105BC0(void *, s32);
    void *fn_8001CB64(void *);
    void *fn_8000D354(void *);
    s32 fn_801660A8(void *);
    void fn_801660C4(s32, u16, u16, u8);
    void fn_80165E90(s32 *, void *);
    extern u8 lbl_80330708[];

    u8 sp[0x10];
    s8 var_r31;
    void *class;
    u64 *bits;
    u8 b;
    register s32 s;
    s8 lim;
    register s8 var_r5;
    s8 tmp;
    s8 var_r6;
    s32 index;
    s32 ptr;
    void *item;
    s8 var_r4;
    void *other;
    void *unit;
    s32 id;
    s32 diff;

    var_r31 = 0;
    class = *(void **)((u8 *)arg0 + 0x18C);
    unit = *(void **)((u8 *)arg0 + 0x188);
    b = *(u8 *)((u8 *)arg0 + 0x1AB);
    s = *(u8 *)((u8 *)class + 0x44);
    lim = *(s8 *)((u8 *)class + 0x4C);
    s = s + b;
    s = *(u8 *)((u8 *)unit + 0x1D) + (s32)s;
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
        ptr = (s32)((u8 *)arg0 + (s8)index * 8 + 0x1CC);
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
        ptr = (s32)((u8 *)arg0 + (s8)index * 8 + 0x1EC);
    }
    if ((u32)ptr != 0) {
        var_r6 = (s8)(var_r6 + *(s8 *)((u8 *)*(void **)ptr + 0x1F));
    }
    tmp = (s8)(var_r5 + var_r6);
    if (var_r4 <= (s8)(tmp / 2) && (u8)fn_80105BC0((u8 *)arg0 + 0x1BC, 0x10) != 0) {
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
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1E1) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + (short)0x1DC) != 0)) {
        index = 2;
    } else if ((((*(u8 *)((u8 *)arg0 + 0x1E9) >> 7) & 1) != 0) && (*(u32 *)((u8 *)arg0 + 0x1E4) != 0)) {
        index = 3;
    } else {
        index = -1;
    }
    if ((s8)index < 0) {
        ptr = 0;
    } else {
        ptr = (s32)((u8 *)arg0 + (s8)index * 8 + 0x1CC);
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
        ptr = (s32)((u8 *)arg0 + (s8)index * 8 + 0x1EC);
    }
    if ((u32)ptr != 0) {
        item = *(void **)ptr;
        var_r31 = (s8)(var_r31 + *(u8 *)((u8 *)item + 0x20));
        bits = (u64 *)fn_8001CB64(item);
        if ((*bits & 2ULL) != 0) {
            other = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0xC);
            if (other) {
                other = fn_8000D354(other);
            } else {
                other = 0;
            }
            class = *(void **)((u8 *)arg0 + 0x18C);
            diff = (s8)*(u8 *)((u8 *)class + 0x45) - (s8)*(u8 *)((u8 *)other + 0x45);
            var_r31 = (s8)(var_r31 - (s8)(diff / 2));
        }
    }
    id = fn_801660A8(lbl_80330708 + 0x3C0);
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
s8 fn_800398B0(void *arg0, u8 arg1) {
    s8 Unit_GetCarryWtLimit(void *);
    s8 Unit_GetMagAtk(void *);
    s8 fn_8003AF28(void *);
    s8 fn_8003AEB0(void *);
    s8 fn_8003AA40(void *);
    s8 fn_8003A778(void *);
    u8 Status_Test(void *, s32);
    s8 hp, bonus, value;
    u8 cap, flag;
    s32 sum, raw;
    void *ptr, *base, *person;

    switch (arg1) {
    case 0: {
        base = M2C_FIELD(arg0, void **, 0x18C);
        person = M2C_FIELD(arg0, void **, 0x188);
        cap = M2C_FIELD(base, u8 *, 0x4C);
        raw = M2C_FIELD(arg0, u8 *, 0x1AB) + M2C_FIELD(base, u8 *, 0x44);
        hp = M2C_FIELD(person, u8 *, 0x1D) + raw;
        if (hp > (s8)cap) hp = (s8)cap;
        if (hp < 0) hp = 0;
        bonus = 0;
        ptr = Unit_GetActiveItemPtr_Inline(arg0);
        if (ptr) bonus = M2C_FIELD(*(void **)ptr, u8 *, 31);
        ptr = Unit_GetActiveEquipPtr_Inline(arg0);
        if (ptr) bonus = (s8)(bonus + M2C_FIELD(*(void **)ptr, u8 *, 31));
        return (s8)(hp + bonus);
    }
    case 1: return Unit_GetCarryWtLimit(arg0);
    case 2: return Unit_GetMagAtk(arg0);
    case 3: return fn_8003AF28(arg0);
    case 4: return fn_8003AEB0(arg0);
    case 5: {
        value = M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x22) + M2C_FIELD(arg0, u8 *, 0x1B0);
        if (value > 40) value = 40;
        if (value < 0) value = 0;
        bonus = 0;
        ptr = Unit_GetActiveItemPtr_Inline(arg0);
        if (ptr) bonus = M2C_FIELD(*(void **)ptr, s8 *, 36);
        ptr = Unit_GetActiveEquipPtr_Inline(arg0);
        if (ptr) bonus = (s8)(bonus + M2C_FIELD(*(void **)ptr, u8 *, 36));
        value += bonus;
        if (value < 0) value = 0;
        return value;
    }
    case 6: return fn_8003AA40(arg0);
    case 7: return fn_8003A778(arg0);
    case 8: {
        sum = M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), s8 *, 0x1B) + M2C_FIELD(M2C_FIELD(arg0, void **, 0x18C), u8 *, 0x3C);
        sum += M2C_FIELD(arg0, s8 *, 0x1A9);
        bonus = 0;
        ptr = Unit_GetActiveItemPtr_Inline(arg0);
        if (ptr) bonus = M2C_FIELD(*(void **)ptr, s8 *, 40);
        ptr = Unit_GetActiveEquipPtr_Inline(arg0);
        if (ptr) bonus = (s8)(bonus + M2C_FIELD(*(void **)ptr, u8 *, 40));
        sum += (s8)bonus;
        if (sum > 99) sum = 99;
        if (sum < 0) sum = 0;
        return (s8)sum;
    }
    case 9: {
        if ((M2C_FIELD(arg0, u8 *, 0x1A4) >> 2) & 7) return 0;
        sum = M2C_FIELD(M2C_FIELD(arg0, void **, 0x18C), u8 *, 0x3E);
        sum += M2C_FIELD(arg0, s8 *, 0x1AA);
        flag = Status_Test((u8 *)arg0 + 0x1BC, 14);
        bonus = 0;
        sum += 2 & ((-(s32)flag | (s32)flag) >> 31);
        ptr = Unit_GetActiveItemPtr_Inline(arg0);
        if (ptr) bonus = M2C_FIELD(*(void **)ptr, s8 *, 39);
        ptr = Unit_GetActiveEquipPtr_Inline(arg0);
        if (ptr) bonus = (s8)(bonus + M2C_FIELD(*(void **)ptr, u8 *, 39));
        sum += (s8)bonus;
        if (sum > 20) sum = 20;
        if (sum < 0) sum = 0;
        return (s8)sum;
    }
    default: return -1;
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
    s8 ret;
    s32 tmp = M2C_FIELD(M2C_FIELD(arg0, void **, 0x18C), u8 *, 0x41) + (((u8) M2C_FIELD(arg0, u8 *, 0x1A6) >> 2U) & 7);
    ret = (s8) tmp;
    return ret;
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
    struct Slot {
        s8 *item;
        u8 pad;
        u8 flags;
        u8 pad2[2];
    };
    struct Unit {
        u8 pad[0x18C];
        u8 *job;
        u8 pad1[0x1A4 - 0x190];
        u8 flags1A4;
        u8 pad2[0x1AA - 0x1A5];
        s8 movBonus;
        u8 pad3[0x1BC - 0x1AB];
        u8 status[0x10];
        struct Slot weapons[4];
        struct Slot acc[4];
    };
    struct Unit *u = (struct Unit *)arg0;
    s32 sum;
    s32 i;
    s8 result;
    s8 temp;
    struct Slot *slot;

    if (((u->flags1A4 >> 2) & 7) != 0) {
        return 0;
    }
    sum = u->job[0x3E];
    sum += u->movBonus;
    sum += Status_Test(u->status, 0xE) ? 2 : 0;

    result = 0;
    for (i = 0; i < 4; i++) {
        if (((u->weapons[i].flags >> 7) & 1) && u->weapons[i].item != 0) {
            temp = i;
            goto found1;
        }
    }
    temp = -1;
found1:
    if (temp < 0) {
        slot = 0;
    } else {
        slot = &u->weapons[temp];
    }
    if (slot != 0) {
        result += slot->item[0x27];
    }
    for (i = 0; i < 4; i++) {
        if (((u->acc[i].flags >> 7) & 1) && u->acc[i].item != 0) {
            temp = i;
            goto found2;
        }
    }
    temp = -1;
found2:
    if (temp < 0) {
        slot = 0;
    } else {
        slot = &u->acc[temp];
    }
    if (slot != 0) {
        result += slot->item[0x27];
    }

    sum += result;
    if (sum > 0x14) {
        sum = 0x14;
    }
    if (sum < 0) {
        sum = 0;
    }
    return sum;
}
#pragma opt_strength_reduction reset
s8 Unit_GetCon(void *arg0) {
    struct Slot {
        s8 *item;
        u8 pad;
        u8 flags;
        u8 pad2[2];
    };
    struct Unit {
        u8 pad0[0x188];
        s8 *p188;
        u8 *p18C;
        u8 pad1[0x19];
        s8 f1A9;
        u8 pad2[0x22];
        struct Slot weapons[4];
        struct Slot acc[4];
    };
    struct Unit *u = (struct Unit *)arg0;
    s8 result;
    s32 sum;
    s8 temp;
    s32 i;
    struct Slot *slot;

    sum = u->p188[0x1B];
    sum += u->p18C[0x3C];
    sum += u->f1A9;
    result = 0;
    for (i = 0; i < 4; i++) {
        if (((u->weapons[i].flags >> 7) & 1) && u->weapons[i].item != 0) {
            temp = i;
            goto found1;
        }
    }
    temp = -1;
found1:
    if (temp < 0) {
        slot = 0;
    } else {
        slot = &u->weapons[temp];
    }
    if (slot != 0) {
        result += slot->item[0x28];
    }
    for (i = 0; i < 4; i++) {
        if (((u->acc[i].flags >> 7) & 1) && u->acc[i].item != 0) {
            temp = i;
            goto found2;
        }
    }
    temp = -1;
found2:
    if (temp < 0) {
        slot = 0;
    } else {
        slot = &u->acc[temp];
    }
    if (slot != 0) {
        result += slot->item[0x28];
    }
    sum += result;
    if (sum > 0x63) {
        sum = 0x63;
    }
    if (sum < 0) {
        sum = 0;
    }
    return (s8)sum;
}

#pragma push
#pragma optimization_level 4
#pragma opt_lifetimes off
#pragma opt_dead_code off
s8 fn_8003A778(void *arg0) {
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
    s32 cls;

    cls = (s32)*(void **)((u8 *)arg0 + 0x18C);
    var_r31 = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x24) + *(u8 *)(cls + 0x4B)) + *(u8 *)((u8 *)arg0 + 0x1B2);
    cls = *(s8 *)(cls + 0x53);
    if (var_r31 > (s8)cls) var_r31 = (s8)cls;
    if (var_r31 < 0) var_r31 = 0;

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
        var_r30 = *(s8 *)((u8 *)*(void **)temp + 0x26);
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
        var_r30 += *(u8 *)((u8 *)obj + 0x26);
        if ((*Item_GetFlagsPtr((void *)temp) & 0x200000000ULL) != 0) {
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
#pragma pop
#pragma push
#pragma optimization_level 4
#pragma opt_strength_reduction off
s8 fn_8003AA40(void *arg0) {
    void *Res_GetByName(void *);
    u64 *Item_GetFlagsPtr(void *);
    void fn_80165E90(u8 *, void *, f32);
    s32 fn_801660A8(void *);
    f32 fn_801660C4(s32, s32, u16, u8);
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
    s32 cls;
    s32 lim;
    f32 angle;

    cls = (s32)*(void **)((u8 *)arg0 + 0x18C);
    var_r31 = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x23) + *(u8 *)(cls + 0x4A)) + *(u8 *)((u8 *)arg0 + 0x1B1);
    cls = *(s8 *)(cls + 0x52);
    if (var_r31 > (s8)cls) var_r31 = (s8)cls;
    if (var_r31 < 0) var_r31 = 0;

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
        var_r30 = *(s8 *)((u8 *)*(void **)temp + 0x25);
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
    angle = fn_801660C4(id, *(u16 *)((u8 *)t + 0x58), *(u16 *)((u8 *)arg0 + 0x228), *(u8 *)((u8 *)t + 0x55));
    fn_80165E90((u8 *)&sp8, (u8 *)arg0 + 0x1BC, angle);
    sp10 = sp8;
    var_r30 += sp10.unk1;
    result = (s8)(var_r31 + var_r30);
    if (result < 0) {
        result = 0;
    }
    return result;
}
#pragma pop
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
    s32 p;
    s8 var_r31;
    s8 var_r3;

    p = (s32)*(void **)((u8 *)arg0 + 0x18C);
    var_r31 = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x21) + *(u8 *)(p + 0x48)) + *(u8 *)((u8 *)arg0 + 0x1AF);
    p = *(s8 *)(p + 0x50);
    if (var_r31 > (s8)p) {
        var_r31 = (s8)p;
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
    s8 fn_80038F28(void *);
    s32 p;
    s8 var_r31;
    s8 var_r3;

    p = (s32)*(void **)((u8 *)arg0 + 0x18C);
    var_r31 = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x20) + *(u8 *)(p + 0x47)) + *(u8 *)((u8 *)arg0 + 0x1AE);
    p = *(s8 *)(p + 0x4F);
    if (var_r31 > (s8)p) {
        var_r31 = (s8)p;
    }
    if (var_r31 < 0) {
        var_r31 = 0;
    }
    var_r3 = var_r31 + fn_80038F28(arg0);
    if (var_r3 < 0) {
        var_r3 = 0;
    }
    return var_r3;
}

#pragma push
#pragma optimization_level 4
#pragma opt_strength_reduction off
#pragma opt_common_subs off
s8 Unit_GetMagAtk(void *arg0) {
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

    a = (void *)*(u32 *)((u8 *)arg0 + 0x18C);
    var_r31 = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x1F) + *(u8 *)((u8 *)a + 0x46)) + *(u8 *)((u8 *)arg0 + 0x1AD);
    lim = *(s8 *)((u8 *)a + 0x4E);
    if (var_r31 > (s8)lim) var_r31 = (s8)lim;
    if (var_r31 < 0) var_r31 = 0;

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
        var_r30 = *(s8 *)((u8 *)*(void **)temp + 0x21);
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
        var_r30 += *(u8 *)((u8 *)obj + 0x21);
        if ((*Item_GetFlagsPtr((void *)temp) & 0x200000000ULL) != 0) {
            p = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0xC);
            if (p != NULL) {
                other = Res_GetByName(p);
            } else {
                other = NULL;
            }
            diff = (s8)*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0x46) - (s8)*(u8 *)((u8 *)other + 0x46);
            var_r30 = (s8)(var_r30 - diff / 2);
        }
    }

    id = fn_801660A8(gBattleState + 0x3C0);
    t = *(void **)((u8 *)arg0 + 0x188);
    fn_801660C4(id, *(u16 *)((u8 *)t + 0x58), *(u16 *)((u8 *)arg0 + 0x228), *(u8 *)((u8 *)t + 0x55));
    fn_80165E90(&sp8, (u8 *)arg0 + 0x1BC);
    sp10 = sp8;
    var_r30 += sp10.unk0;
    result = (s8)(var_r31 + var_r30);
    if (result < 0) {
        result = 0;
    }
    return result;
}
#pragma peephole reset
#pragma pop
s8 Unit_GetCarryWtLimit(void *arg0) {
    s8 fn_80039408(void *);
    s32 p;
    s8 var_r31;
    s8 var_r3;

    p = (s32)*(void **)((u8 *)arg0 + 0x18C);
    var_r31 = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x1E) + *(u8 *)(p + 0x45)) + *(u8 *)((u8 *)arg0 + 0x1AC);
    p = *(s8 *)(p + 0x4D);
    if (var_r31 > (s8)p) {
        var_r31 = (s8)p;
    }
    if (var_r31 < 0) {
        var_r31 = 0;
    }
    var_r3 = var_r31 + fn_80039408(arg0);
    if (var_r3 < 0) {
        var_r3 = 0;
    }
    return var_r3;
}

void *Unit_GetActiveItemPtr(void *);
void *fn_80037C20(void *);
s8 Unit_GetMaxHp(void *arg0) {
    s32 p;
    s8 hp;
    s8 bonus;
    s8 index;
    void *slot;

    p = (s32)*(void **)((u8 *)arg0 + 0x18C);
    hp = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x1D) + *(u8 *)(p + 0x44)) + *(u8 *)((u8 *)arg0 + 0x1AB);
    p = *(s8 *)(p + 0x4C);
    if (hp > (s8)p) {
        hp = (s8)p;
    }
    if (hp < 0) {
        hp = 0;
    }

    bonus = 0;
    if ((((u8)*((u8 *)arg0 + 0x1D1) >> 7) & 1) && *(u32 *)((u8 *)arg0 + 0x1CC) != 0) {
        index = bonus;
    } else if ((((u8)*((u8 *)arg0 + 0x1D9) >> 7) & 1) && *(u32 *)((u8 *)arg0 + 0x1D4) != 0) {
        index = 1;
    } else if ((((u8)*((u8 *)arg0 + 0x1E1) >> 7) & 1) && *(u32 *)((u8 *)arg0 + 0x1DC) != 0) {
        index = 2;
    } else if ((((u8)*((u8 *)arg0 + 0x1E9) >> 7) & 1) && *(u32 *)((u8 *)arg0 + 0x1E4) != 0) {
        index = 3;
    } else {
        index = -1;
    }
    if (index < 0) {
        slot = 0;
    } else {
        slot = (u8 *)arg0 + (index * 8) + 0x1CC;
    }
    if (slot != 0) {
        bonus = *(u8 *)(*(u8 **)slot + 0x1F);
    }

    if ((((u8)*((u8 *)arg0 + 0x1F1) >> 7) & 1) && *(u32 *)((u8 *)arg0 + 0x1EC) != 0) {
        index = 0;
    } else if ((((u8)*((u8 *)arg0 + 0x1F9) >> 7) & 1) && *(u32 *)((u8 *)arg0 + 0x1F4) != 0) {
        index = 1;
    } else if ((((u8)*((u8 *)arg0 + 0x201) >> 7) & 1) && *(u32 *)((u8 *)arg0 + 0x1FC) != 0) {
        index = 2;
    } else if ((((u8)*((u8 *)arg0 + 0x209) >> 7) & 1) && *(u32 *)((u8 *)arg0 + 0x204) != 0) {
        index = 3;
    } else {
        index = -1;
    }
    if (index < 0) {
        slot = 0;
    } else {
        slot = (u8 *)arg0 + (index * 8) + 0x1EC;
    }
    if (slot != 0) {
        bonus += *(u8 *)(*(u8 **)slot + 0x1F);
    }

    return (s8)(hp + bonus);
}

#pragma opt_peephole on
s8 Unit_GetRes(void *arg0) {
    s32 p;
    s8 var;

    p = (s32)*(void **)((u8 *)arg0 + 0x18C);
    var = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x24) + *(u8 *)(p + 0x4B)) + *(u8 *)((u8 *)arg0 + 0x1B2);
    p = *(s8 *)(p + 0x53);
    if (var > (s8)p) {
        var = (s8)p;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}
s8 Unit_GetDef(void *arg0) {
    s32 p;
    s8 var;

    p = (s32)*(void **)((u8 *)arg0 + 0x18C);
    var = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x23) + *(u8 *)(p + 0x4A)) + *(u8 *)((u8 *)arg0 + 0x1B1);
    p = *(s8 *)(p + 0x52);
    if (var > (s8)p) {
        var = (s8)p;
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
    s32 p;
    s8 var;

    p = (s32)*(void **)((u8 *)arg0 + 0x18C);
    var = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x21) + *(u8 *)(p + 0x48)) + *(u8 *)((u8 *)arg0 + 0x1AF);
    p = *(s8 *)(p + 0x50);
    if (var > (s8)p) {
        var = (s8)p;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}
#pragma opt_peephole reset
s8 Unit_GetSkl(void *arg0) {
    s32 p;
    s8 var;

    p = (s32)*(void **)((u8 *)arg0 + 0x18C);
    var = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x20) + *(u8 *)(p + 0x47)) + *(u8 *)((u8 *)arg0 + 0x1AE);
    p = *(s8 *)(p + 0x4F);
    if (var > (s8)p) {
        var = (s8)p;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}
#pragma opt_peephole reset
s8 Unit_GetMag(void *arg0) {
    s32 p;
    s8 var;

    p = (s32)*(void **)((u8 *)arg0 + 0x18C);
    var = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x1F) + *(u8 *)(p + 0x46)) + *(u8 *)((u8 *)arg0 + 0x1AD);
    p = *(s8 *)(p + 0x4E);
    if (var > (s8)p) {
        var = (s8)p;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}
#pragma opt_peephole reset
s8 Unit_GetStr(void *arg0) {
    s32 p;
    s8 var;

    p = (s32)*(void **)((u8 *)arg0 + 0x18C);
    var = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x1E) + *(u8 *)(p + 0x45)) + *(u8 *)((u8 *)arg0 + 0x1AC);
    p = *(s8 *)(p + 0x4D);
    if (var > (s8)p) {
        var = (s8)p;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}

#pragma optimization_level 3
