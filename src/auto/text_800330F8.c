/* Functions from 0x800330F8 to 0x80055C70, found by decomp-toolkit. */
#include "common.h"
static inline s32 get_4F128_id(void *arg0) {
 void *fn_80037D54(void *);
 s32 fn_8004ABD4(void *,s32);
 s32 value=M2C_FIELD(arg0,s8 *,0x16C);
 if(value>=0)return value;
 return fn_8004ABD4(fn_80037D54(arg0),0);
}
static inline void *get_4F128_resource(void *arg0,s32 value) {
  void fn_800056A0(s32);
 void DebugPrint(void *, ...);
 void *Res_GetByName(void *);
 void *fn_80037D54(void *);
 s32 fn_8004ABD4(void *,s32);
 u8 fn_8004AF74(void *,u8);
 void *fn_8004B078(void *,s32);
 void *fn_8004B158(void *);
 s32 fn_8004B1A0(s32);
 u16 fn_8005C144(void *);
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
 if(fn_8005C144(buf)==0x8000U) {
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
extern f32 lbl_80368FC0;
extern f32 lbl_80368FC4;
extern f32 lbl_8036901C;
extern f64 lbl_80368FE0;
extern f64 lbl_80368E80;
extern f32 lbl_80368E24;
extern f32 lbl_80368E28;

void *fn_800330F8(void) {
    extern u16 lbl_802695F0[];
    return (u8 *)lbl_802695F0 + 0x14F;
}

#pragma cplusplus on
extern "C" void Prim2D_SetColorByte(u8);
extern "C" void Prim2D_SetTransform(f32, f32, f32, f32);
extern "C" void Prim2D_PrepareTex(void);
extern "C" void Prim2D_Begin(void);
extern "C" s32 UnitRef_GetUnit(u32);
extern "C" void UnitInfo_DrawStatus(s32);
extern "C" void fn_80033108(void *arg0, void *arg1) {
    extern f32 lbl_80368E24;
    extern f32 lbl_80368E28;
    struct Obj {
        u8 pad[4];
        virtual void v0(s32 *, s32 *, s32 *) = 0;
    };
    s32 x;
    s32 y;
    s32 alpha;

    if (M2C_FIELD(arg1, u32 *, 0x40) != 0) {
        ((Obj *)arg0)->v0(&x, &y, &alpha);
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0x30), lbl_80368E24, lbl_80368E28);
        Prim2D_SetColorByte((u8)alpha);
        Prim2D_PrepareTex();
        UnitInfo_DrawStatus(UnitRef_GetUnit(M2C_FIELD(arg1, u32 *, 0x40)));
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

void fn_8003333C(u8 *arg0, s32 arg1) {
#pragma scheduling off
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 idx;
    u8 *p;

    t1 = arg1 + 1;
    t2 = arg1 + 2;
    t3 = arg1 + 3;
    idx = arg0[0x60] + arg1;
    t4 = arg1 + 4;
    p = arg0 + (idx * 2);
    *(u16 *)(p + 0x20) |= 1;

    idx = arg0[0x60] + t1;
    p = arg0 + (idx * 2);
    *(u16 *)(p + 0x20) |= 1;

    idx = arg0[0x60] + t2;
    p = arg0 + (idx * 2);
    *(u16 *)(p + 0x20) |= 1;

    idx = arg0[0x60] + t3;
    p = arg0 + (idx * 2);
    *(u16 *)(p + 0x20) |= 1;

    idx = arg0[0x60] + t4;
    p = arg0 + (idx * 2);
    *(u16 *)(p + 0x20) |= 1;
#pragma scheduling reset
}

#pragma opt_strength_reduction off
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
#pragma opt_strength_reduction reset
void fn_80033E70(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x400), s16 *, 2) = (s16) (M2C_FIELD(arg0, s16 *, 0) - M2C_FIELD(arg0, s16 *, 2));
    M2C_FIELD(arg0, void **, 0x400) = NULL;
}

void fn_80033E90(void *arg0) {
    s8 fn_80033F18(void);
    void *self;
    s8 ret;
    u8 *e;

    self = arg0;
    *(void **)((u8 *)arg0 + 0x400) = (u8 *)self + *(s16 *)self * 4 + 4;
    ret = fn_80033F18();
    e = (u8 *)self + *(s16 *)self * 4 + 4;
    *e = ret;
    *(s16 *)(e + 2) = 0;
    *(s16 *)self = *(s16 *)self + 1;
    e = (u8 *)self + *(s16 *)self * 4 + 4;
    *e = 0;
    *(s16 *)(e + 2) = 0;
    *(s16 *)((u8 *)self + 2) = *(s16 *)self;
}

#pragma global_optimizer off
void BattleAnim_Queue(s16 *arg0, s32 arg1, s8 arg2) {
    s8 fn_80033F18(s16 *, s32);
    u8 *entry;
    s8 ret;
    s32 off;

    ret = fn_80033F18(arg0, arg1);
    off = *arg0 << 2;
    entry = (u8 *)arg0 + off + 4;
    *entry = ret;
    *(s16 *)(entry + 2) = arg2;
    (*arg0)++;
    off = *arg0 << 2;
    entry = (u8 *)arg0 + off + 4;
    *entry = 0;
    *(s16 *)(entry + 2) = 0;
}
#pragma global_optimizer reset
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
    u8 fn_8000CE68(s16);
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
        if (fn_8000CE68(v) != 0 || fn_8000CE68(v) != 0) {
            g += 1;
        }
    } else if (fn_8000CE68(v) != 0) {
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
        if (fn_8000CE68(v) != 0 || fn_8000CE68(v) != 0) {
            g += 1;
        }
    } else if (fn_8000CE68(v) != 0) {
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
        if (fn_8000CE68(v) != 0 || fn_8000CE68(v) != 0) {
            g += 1;
        }
    } else if (fn_8000CE68(v) != 0) {
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
        if (fn_8000CE68(v) != 0 || fn_8000CE68(v) != 0) {
            g += 1;
        }
    } else if (fn_8000CE68(v) != 0) {
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
        if (fn_8000CE68(v) != 0 || fn_8000CE68(v) != 0) {
            g += 1;
        }
    } else if (fn_8000CE68(v) != 0) {
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
        if (fn_8000CE68(v) != 0 || fn_8000CE68(v) != 0) {
            g += 1;
        }
    } else if (fn_8000CE68(v) != 0) {
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
        if (fn_8000CE68(v) != 0 || fn_8000CE68(v) != 0) {
            g += 1;
        }
    } else if (fn_8000CE68(v) != 0) {
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
        if (fn_8000CE68(v) != 0 || fn_8000CE68(v) != 0) {
            g += 1;
        }
    } else if (fn_8000CE68(v) != 0) {
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
    void fn_801A7794(void *, void *, void *);
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

    fn_801A7794((void *)battle, unit, unit);
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

u8 fn_80034A8C(s32 arg0, u8 arg1) {
    s32 temp_r3;
    s32 temp_r30;
    s32 temp_r31;

    if (arg1 == 0) {
        return 0U;
    }
    temp_r31 = arg1;
    if (Status_Test(arg0 + 0x1BC, 0xB) != 0) {
        temp_r31 *= 2;
    }
    if (Status_Test(arg0 + 0x1BC, 0x4B) != 0) {
        temp_r3 = (temp_r31 * 7) / 10;
        temp_r31 = temp_r3;
        if (temp_r31 < 1) {
            temp_r31 = 1;
        }
    }
    if (temp_r31 > 0x64) {
        temp_r31 = 0x64;
    }
    return temp_r31;
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
    void *p;

    if (fn_8003D13C(arg0) != 0) {
        BattleAnim_Queue(arg0 + 0x8A0, 0x25, 0);
        BattleAnim_Queue(arg0 + 0x8A0, 0x27, (s8)fn_800386B0(arg0));
        p = *(void **)(arg0 + 0x28C);
        var_r30 = fn_8003D094(arg0, (u8)(*(u16 *)((u8 *)p + 0x10) / 20 + 0xA));
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
void fn_80036248(s32 self) {
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
void fn_800368C8(void *arg0, u8 arg1, void *arg2) {
    void *fn_80019DA8(u8);
    void *temp_r3;

    temp_r3 = fn_80019DA8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x54));
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
void fn_80036998(void *arg0, s32 arg1) {
    u8 fn_80036B20(void *, s32);
    u8 *target;
    s32 offset;
    s32 off8;
    u8 *table;
    u8 *row;
    u8 cur;

    if (fn_80036B20(arg0, arg1)) {
        return;
    }
    target = (u8 *)arg0 + arg1;
    offset = arg1 << 3;
    target[0x214]++;
    off8 = offset + 8;
    table = *(u8 **)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x50);
    row = table + off8;
    cur = target[0x214];
    if (cur > (u8)(row[6] + 1)) {
        target[0x214] = *(table + offset + 0xE) + 1;
    }
}
#pragma global_optimizer reset
#pragma opt_strength_reduction reset
s32 fn_80036A24(u8 *arg0)
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

#pragma global_optimizer off
s32 fn_80036DE0(void *arg0, void *arg1)
{
    s32 index;
    u32 value;
    u8 *obj;
    s32 offset;
    u8 *table;
    s32 count;

    index = 0;
    value = *(u32 *)((u8 *)arg1 + 0x188);
    obj = *(u8 **)((u8 *)arg0 + 0x188);
    offset = index;

    goto check;

loop:
    table = *(u8 **)(obj + 0x50);

    if (*(u32 *)(table + offset + 8) == value) {
        return (s8)index;
    }

    offset += 8;
    index++;

check:
    table = *(u8 **)(obj + 0x50);

    if (table == NULL) {
        count = 0;
    } else {
        count = (u8)*(u32 *)(table + 4);
        count = (u8)count;
    }

    if (index < count) {
        goto loop;
    }

    return -1;
}
#pragma global_optimizer on
s32 fn_80036E48(void *arg0, u32 arg1)
{
    s32 offset;
    s32 index;
    u8 *obj;
    u8 *table;
    s32 count;

    obj = *(u8 **)((u8 *)arg0 + 0x188);
    index = 0;
    offset = 0;

    goto check;

loop:
    table = *(u8 **)(obj + 0x50);

    if (*(u32 *)(table + offset + 8) == arg1) {
        return (s8)index;
    }

    offset += 8;
    index++;

check:
    table = *(u8 **)(obj + 0x50);

    if (table == NULL) {
        count = 0;
    } else {
        count = (u8)*(u32 *)(table + 4);
        count = (u8)count;
    }

    if (index < count) {
        goto loop;
    }

    return -1;
}

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

s32 fn_80036F5C(void *arg0, s32 arg1)
{
    u8 *obj;
    u8 *entry;
    u8 value;

    obj = *(u8 **)((u8 *)arg0 + 0x188);
    entry = *(u8 **)(obj + 0x50) + (arg1 * 8) + 8;
    if (entry == 0) {
        return 0;
    }
    value = *((u8 *)arg0 + arg1 + 0x214);
    if (value <= entry[4]) {
        return 0;
    }
    if (value <= entry[5]) {
        return 1;
    }
    return 2 + (value > entry[6]);
}

#pragma peephole off
u8 fn_80036FC4(u8 *arg0, s32 arg1) {
    return arg0[arg1 + 0x214];
}
#pragma peephole on
void fn_80036FD0(void *arg0, s32 arg1) {
    void **temp_r3;
    void *temp_r3_2;

    temp_r3 = (void **)M2C_FIELD(arg0, void **, 0x188);
    temp_r3_2 = M2C_FIELD(temp_r3, void **, 0x50);
    temp_r3_2 = (void*)((s32)temp_r3_2 + (arg1 * 8));
    fn_80016B7C((s32)M2C_FIELD(temp_r3_2, void **, 8));
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

u8 fn_8003701C(void *arg0) {
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

void *fn_80037710(u8 *arg0) {
    void Allegiance_FillMask(s32, void *);
    extern u8 gUnits[];
    u8 sp8[8];
    u8 *sub;
    u8 *unit;
    s32 i;
    u32 flags;

    sub = NULL;
    Allegiance_FillMask(5, sp8);
    for (i = 1; i <= 0x9F; i++) {
        if ((u8)i != 0) {
            unit = gUnits + ((u8)i - 1) * 0x280;
        } else {
            unit = NULL;
        }
        if (*(u32 *)(unit + 0x188) != 0) {
            sub = *(u8 **)(unit + 0x190);
            if (sp8[*(u8 *)(sub + 8)] != 0) {
                flags = *(u32 *)(unit + 0x1A0);
                if ((flags & 0x100) != 0) {
                    if ((flags & 8) == 0) {
                        if (sub == *(u8 **)(arg0 + 0x190)) {
                            if (arg0[0x199] == unit[0x199]) {
                                return unit;
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
f32 fn_80037818(void *arg0,u8 arg1) {
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

void fn_80037AB8(void *arg0) {
    void *temp_r6;
    void *temp_r6_2;
    void *temp_r6_3;
    void *temp_r6_4;
    void *temp_r6_5;
    void *temp_r6_6;
    void *temp_r6_7;

    temp_r6 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1AB) = (s8) ((M2C_FIELD(temp_r6, u8 *, 0x4C) - M2C_FIELD(temp_r6, u8 *, 0x44)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x1D));
    temp_r6_2 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1AC) = (s8) ((M2C_FIELD(temp_r6_2, u8 *, 0x4D) - M2C_FIELD(temp_r6_2, u8 *, 0x45)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x1E));
    temp_r6_3 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1AD) = (s8) ((M2C_FIELD(temp_r6_3, u8 *, 0x4E) - M2C_FIELD(temp_r6_3, u8 *, 0x46)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x1F));
    temp_r6_4 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1AE) = (s8) ((M2C_FIELD(temp_r6_4, u8 *, 0x4F) - M2C_FIELD(temp_r6_4, u8 *, 0x47)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x20));
    temp_r6_5 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1AF) = (s8) ((M2C_FIELD(temp_r6_5, u8 *, 0x50) - M2C_FIELD(temp_r6_5, u8 *, 0x48)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x21));
    M2C_FIELD(arg0, s8 *, 0x1B0) = (s8) (0x28 - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x22));
    temp_r6_6 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1B1) = (s8) ((M2C_FIELD(temp_r6_6, u8 *, 0x52) - M2C_FIELD(temp_r6_6, u8 *, 0x4A)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x23));
    temp_r6_7 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1B2) = (s8) ((M2C_FIELD(temp_r6_7, u8 *, 0x53) - M2C_FIELD(temp_r6_7, u8 *, 0x4B)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x24));
    M2C_FIELD(arg0, s8 *, 0x1AA) = (s8) (0x14 - M2C_FIELD(M2C_FIELD(arg0, void **, 0x18C), u8 *, 0x3E));
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

void *fn_80037D54(void *arg0) {
    s8 index;
    if ((((u8)M2C_FIELD(arg0, u8 *, 0x1D1) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1CC) != 0) index = 0;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x1D9) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1D4) != 0) index = 1;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x1E1) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1DC) != 0) index = 2;
    else if ((((u8)M2C_FIELD(arg0, u8 *, 0x1E9) >> 7) & 1) && M2C_FIELD(arg0, u32 *, 0x1E4) != 0) index = 3;
    else index = -1;
    if (index < 0) return NULL;
    return (u8 *)arg0 + (index * 8) + 0x1CC;
}

s32 fn_80037E00(void *arg0) {
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

u8 fn_80038128(void *arg0, void *arg1) {
    s32 var_r5;
    s32 var_r0;
    s32 first;
    s32 second;

    first = *(volatile s8 *)((u8 *)arg1 + 0x19F);
    second = *(volatile s8 *)((u8 *)arg0 + 0x19F);
    var_r5 = second - first;

    if (var_r5 >= 0) {
        goto second_pair;
    }
    var_r5 = -var_r5;

second_pair:
    first = *(volatile s8 *)((u8 *)arg0 + 0x19E);
    second = *(volatile s8 *)((u8 *)arg1 + 0x19E);
    var_r0 = first - second;

    if (var_r0 >= 0) {
        goto finish;
    }
    var_r0 = -var_r0;

finish:
    return (u8)(var_r0 + var_r5);
}

void Unit_SetMapPos(void *arg0, s8 arg1, s8 arg2) {
    void fn_80050C50(void *, f32, f32);
    extern f32 lbl_80368EC0;
    void *child;
    f32 fx;
    f32 fy;

    *(s8 *)((u8 *)arg0 + 0x19E) = arg1;
    *(s8 *)((u8 *)arg0 + 0x19F) = arg2;
    child = *(void **)((u8 *)arg0 + 0x194);
    if (child != NULL) {
        *(s8 *)((u8 *)child + 0x19E) = arg1;
        fx = lbl_80368EC0 + (f32)arg1;
        *(s8 *)((u8 *)child + 0x19F) = arg2;
        fy = lbl_80368EC0 + (f32)arg2;
        fn_80050C50(child, fx, fy);
    }
}

void fn_800381EC(void *arg0, s8 arg1) {
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

void fn_8003868C(void *arg0, s32 arg1) {
    if (arg1 != 0xff) {
        if (arg1 < 0) {
            return;
        }
        if (arg1 > 0x64) {
            return;
        }
    }
    *(u8 *)((u8 *)arg0 + 0x19B) = (u8)arg1;
}

u8 fn_800386B0(void *arg0) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x190), u8 *, 8);
    if ((temp_r0 == 1) || (temp_r0 == 2) || (temp_r0 == 3)) {
        return 0xFFU;
    }
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

s8 fn_800388C8(void *arg0) {
    s8 var_r4;
    s8 var_r5;
    void **ptr1;
    void **ptr2;
    
    var_r5 = 0;
    // First check block
    if ((*(u8*)((u8*)arg0 + 0x1D1) & 0x80) != 0 && (*(u32*)((u8*)arg0 + 0x1CC) != 0)) {
        var_r4 = 0;
    } else if ((*(u8*)((u8*)arg0 + 0x1D9) & 0x80) != 0 && (*(u32*)((u8*)arg0 + 0x1D4) != 0)) {
        var_r4 = 1;
    } else if ((*(u8*)((u8*)arg0 + 0x1E1) & 0x80) != 0 && (*(u32*)((u8*)arg0 + 0x1DC) != 0)) {
        var_r4 = 2;
    } else if ((*(u8*)((u8*)arg0 + 0x1E9) & 0x80) != 0 && (*(u32*)((u8*)arg0 + 0x1E4) != 0)) {
        var_r4 = 3;
    } else {
        var_r4 = -1;
    }
    
    if (var_r4 >= 0) {
        ptr1 = (void**)((u8*)arg0 + ((var_r4 * 8) + 0x1CC));
        if (*ptr1 != NULL) {
            var_r5 = *(s8*)((u8*)(*ptr1) + 0x28);
        }
    }
    
    // Second check block
    if ((*(u8*)((u8*)arg0 + 0x1F1) & 0x80) != 0 && (*(u32*)((u8*)arg0 + 0x1EC) != 0)) {
        var_r4 = 0;
    } else if ((*(u8*)((u8*)arg0 + 0x1F9) & 0x80) != 0 && (*(u32*)((u8*)arg0 + 0x1F4) != 0)) {
        var_r4 = 1;
    } else if ((*(u8*)((u8*)arg0 + 0x201) & 0x80) != 0 && (*(u32*)((u8*)arg0 + 0x1FC) != 0)) {
        var_r4 = 2;
    } else if ((*(u8*)((u8*)arg0 + 0x209) & 0x80) != 0 && (*(u32*)((u8*)arg0 + 0x204) != 0)) {
        var_r4 = 3;
    } else {
        var_r4 = -1;
    }
    
    if (var_r4 >= 0) {
        ptr2 = (void**)((u8*)arg0 + ((var_r4 * 8) + 0x1EC));
        if (*ptr2 != NULL) {
            var_r5 += *(s8*)((u8*)(*ptr2) + 0x28);
        }
    }
    
    return var_r5;
}

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
#pragma opt_strength_reduction reset
s32 fn_800398B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (arg0 < 0 || arg0 > 9)
        return -1;
    
    // Simple case handling to start
    switch (arg0) {
        case 0:
            return 0; // Placeholder for complex logic
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 0;
        case 9:
            return -1;
    }
    
    return -1;
}

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

#pragma opt_strength_reduction off
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
    s8 var_r4;
    s8 var_r6;
    s8 var_r7;
    void **var_r4_2;
    
    var_r6 = 0;
    
    // First conditional block
    if ((((u8*)arg0)[0x1D1] & 0x80) && (*(int*)((char*)arg0 + 0x1CC) != 0)) {
        var_r4 = 0;
    } else if ((((u8*)arg0)[0x1D9] & 0x80) && (*(int*)((char*)arg0 + 0x1D4) != 0)) {
        var_r4 = 1;
    } else if ((((u8*)arg0)[0x1E1] & 0x80) && (*(int*)((char*)arg0 + 0x1DC) != 0)) {
        var_r4 = 2;
    } else if ((((u8*)arg0)[0x1E9] & 0x80) && (*(int*)((char*)arg0 + 0x1E4) != 0)) {
        var_r4 = 3;
    } else {
        var_r4 = -1;
    }
    
    // Handle the pointer calculation
    if (var_r4 < 0) {
        var_r4_2 = NULL;
    } else {
        var_r4_2 = (void**)((char*)arg0 + (var_r4 * 8) + 0x1CC);
    }
    
    // Second conditional block - similar logic
    if (var_r4_2 != NULL) {
        var_r6 = *(u8*)((char*)(*var_r4_2) + 0x28);
    }
    
    // Calculate final value using known struct offsets
    var_r7 = ((u8*)arg0)[0x188] + 
             ((u8*)arg0)[0x18C] + 
             ((u8*)arg0)[0x1A9] + 
             var_r6;
    
    // Bounds checking
    if (var_r7 > 99) {
        var_r7 = 99;
    }
    if (var_r7 < 0) {
        var_r7 = 0;
    }
    
    return var_r7;
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
s8 fn_8003AFA0(void *arg0) {
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
s8 fn_8003B258(void *arg0) {
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

void *fn_80037D54(void *);
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
    slot = fn_80037D54(arg0);
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
    void *temp_r4;
    s8 temp_r6_2;
    u8 temp_r5;
    s8 var_r3;

    temp_r4 = *(void **)((u8 *)arg0 + 0x18C);
    temp_r5 = *(u8 *)((u8 *)arg0 + 0x1B2);
    temp_r6_2 = *(u8 *)((u8 *)temp_r4 + 0x53);
    var_r3 = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x24) + *(u8 *)((u8 *)temp_r4 + 0x4B)) + temp_r5;
    if (var_r3 > temp_r6_2) {
        var_r3 = temp_r6_2;
    }
    if (var_r3 < 0) {
        return 0;
    }
    return var_r3;
}
#pragma opt_peephole reset
s8 Unit_GetDef(void *arg0) {
    void *temp_r4;
    s8 temp_r6_2;
    u8 temp_r5;
    s8 var_r3;

    temp_r4 = *(void **)((u8 *)arg0 + 0x18C);
    temp_r5 = *(u8 *)((u8 *)arg0 + 0x1B1);
    temp_r6_2 = *(u8 *)((u8 *)temp_r4 + 0x52);
    var_r3 = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x23) + *(u8 *)((u8 *)temp_r4 + 0x4A)) + temp_r5;
    if (var_r3 > temp_r6_2) {
        var_r3 = temp_r6_2;
    }
    if (var_r3 < 0) {
        return 0;
    }
    return var_r3;
}

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

s8 Unit_GetSpd(void *arg0) {
    void *p18c;
    s8 lim;
    u8 t;
    s8 var;

    p18c = *(void **)((u8 *)arg0 + 0x18C);
    t = *(u8 *)((u8 *)arg0 + 0x1AF);
    lim = *(u8 *)((u8 *)p18c + 0x50);
    var = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x21) + *(u8 *)((u8 *)p18c + 0x48)) + t;
    if (var > lim) {
        var = lim;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}

#pragma opt_peephole off
s8 Unit_GetSkl(void *arg0) {
    void *temp_r4;
    s8 temp_r6_2;
    u8 temp_r5;
    s8 var_r3;

    temp_r4 = *(void **)((u8 *)arg0 + 0x18C);
    temp_r5 = *(u8 *)((u8 *)arg0 + 0x1AE);
    temp_r6_2 = *(u8 *)((u8 *)temp_r4 + 0x4F);
    var_r3 = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x20) + *(u8 *)((u8 *)temp_r4 + 0x47)) + temp_r5;
    if (var_r3 > temp_r6_2) {
        var_r3 = temp_r6_2;
    }
    if (var_r3 < 0) {
        return 0;
    }
    return var_r3;
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

s8 Unit_GetHp(void *arg0) {
    void *p18c;
    s8 lim;
    u8 t;
    s8 var;
    u8 base;

    p18c = *(void **)((u8 *)arg0 + 0x18C);
    t = *(u8 *)((u8 *)arg0 + 0x1AB);
    base = *(u8 *)((u8 *)p18c + 0x44);
    lim = *(u8 *)((u8 *)p18c + 0x4C);
    var = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x188) + 0x1D) + base) + t;
    if (var > lim) {
        var = lim;
    }
    if (var < 0) {
        return 0;
    }
    return var;
}

void fn_8003B69C(s32 arg0) {
    M2C_UNK fn_800173B4(s32, s32);
    fn_800173B4(arg0 + 0x236, arg0);
}

void fn_8003B6C4(void* arg0, s32 arg1) {
    *(s32*)((char*)arg0 + 0x190) = arg1;
    fn_800173B4((char*)arg0 + 0x236, arg0);
}

void Unit_Clear(u8 *unit, s32 slotId) {
    /* Zero unit battle/runtime fields and inventory; set slot id when slotId >= 0. */
    void fn_80104410(void *);
    void Item_Clear(void *);
    u8 *slot;
    s32 i;

    *(u32 *)(unit + 0x180) = 0;
    *(u32 *)(unit + 0x184) = 0;
    *(u32 *)(unit + 0x188) = 0;
    *(u32 *)(unit + 0x18C) = 0;
    *(u32 *)(unit + 0x190) = 0;
    *(u32 *)(unit + 0x194) = 0;
    unit[0x19A] = 0;
    unit[0x19B] = 0;
    unit[0x19C] = 0;
    unit[0x19D] = 0;
    unit[0x19E] = 0;
    unit[0x19F] = 0;
    *(u32 *)(unit + 0x1A0) = 0;

    fn_80104410(unit + 0x1A4);

    slot = unit;
    unit[0x1A8] = 0;
    i = 0;

    unit[0x1B2] = 0;
    unit[0x1B1] = 0;
    unit[0x1B0] = 0;
    unit[0x1AF] = 0;
    unit[0x1AE] = 0;
    unit[0x1AD] = 0;
    unit[0x1AC] = 0;
    unit[0x1AB] = 0;
    unit[0x1BB] = 0;
    unit[0x1BA] = 0;
    unit[0x1B9] = 0;
    unit[0x1B8] = 0;
    unit[0x1B7] = 0;
    unit[0x1B6] = 0;
    unit[0x1B5] = 0;
    unit[0x1B4] = 0;
    *(u32 *)(unit + 0x1C8) = 0;
    *(u32 *)(unit + 0x1C4) = 0;
    *(u32 *)(unit + 0x1C0) = 0;
    *(u32 *)(unit + 0x1BC) = 0;

    do {
        Item_Clear(slot + 0x1CC);
        Item_Clear(slot + 0x1EC);
        i += 1;
        slot += 8;
    } while (i < 4);

    unit[0x20C] = 0;
    unit[0x20D] = 0;
    unit[0x20E] = 0;
    unit[0x20F] = 0;
    unit[0x210] = 0;
    unit[0x211] = 0;
    unit[0x212] = 0;
    unit[0x213] = 0;
    *(u16 *)(unit + 0x228) = 0;
    *(u16 *)(unit + 0x22A) = 0;
    *(u16 *)(unit + 0x22C) = 0;
    *(u16 *)(unit + 0x22E) = 0;
    *(u16 *)(unit + 0x230) = 0;
    *(u16 *)(unit + 0x232) = 0;
    unit[0x234] = 0;
    unit[0x235] = 0;

    if (slotId >= 0) {
        unit[0x198] = slotId;
    }
}

void fn_8003B844(void *arg0,s32 arg1) {
 void *outer=arg0;
 s32 i=0;
 void *entry;
 s32 j;
 while(i<arg1) {
  entry=outer; j=0;
  while(j<M2C_FIELD(outer,s32*,4)) {
   if (M2C_FIELD(entry,void**,8)!=0) M2C_FIELD(entry,void**,8)=(void*)Person_GetByPid(M2C_FIELD(entry,void**,8));
   entry=(u8*)entry+8; j++;
  }
  M2C_FIELD(Person_GetByPid(M2C_FIELD(outer,void**,0)),void**,0x50)=outer;
  i++;
  outer=(u8*)outer+(M2C_FIELD(outer,s32*,4)*8)+8;
 }
}

void fn_8003B8D4(void *arg0) {
    M2C_FIELD(arg0, u8 *, 4) = (u8) ((s8) M2C_FIELD(arg0, u8 *, 4) >> 1);
    M2C_FIELD(arg0, u8 *, 5) = (u8) ((s8) M2C_FIELD(arg0, u8 *, 5) >> 1);
    M2C_FIELD(arg0, u8 *, 6) = (u8) ((s8) M2C_FIELD(arg0, u8 *, 6) >> 1);
    M2C_FIELD(arg0, u8 *, 7) = (u8) ((s8) M2C_FIELD(arg0, u8 *, 7) >> 1);
    M2C_FIELD(arg0, u8 *, 8) = (u8) ((s8) M2C_FIELD(arg0, u8 *, 8) >> 1);
    M2C_FIELD(arg0, u8 *, 9) = (u8) ((s8) M2C_FIELD(arg0, u8 *, 9) >> 1);
}

s32 fn_8003B938(u8 arg0) {
    switch (arg0) {
    case 0:
        return 0;
    case 1:
        return 0x7;
    case 2:
        return 0x9;
    case 3:
        return 0x8;
    case 4:
        return 0x4;
    case 5:
        return 0x6;
    case 6:
        return 0x5;
    case 7:
        return 0x2;
    case 8:
        return 0x3;
    default:
        return 0;
    }
}

extern s32 gGameState;
void fn_8003B9AC(u32 arg0) {
    void fn_8000E0E4(void *);
    extern u16 gAffinityStr[];
    u8 *s;

    switch ((u8)arg0) {
    case 0:
        s = (u8 *)gAffinityStr + 0x8;
        break;
    case 1:
        s = (u8 *)gAffinityStr + 0xF;
        break;
    case 2:
        s = (u8 *)gAffinityStr + 0x16;
        break;
    case 3:
        s = (u8 *)gAffinityStr + 0x1D;
        break;
    case 4:
        s = (u8 *)gAffinityStr + 0x25;
        break;
    case 5:
        s = (u8 *)gAffinityStr + 0x2B;
        break;
    case 6:
        s = (u8 *)gAffinityStr + 0x33;
        break;
    case 7:
        s = (u8 *)gAffinityStr + 0x3A;
        break;
    case 8:
    default:
        s = (u8 *)gAffinityStr + 0x43;
        break;
    }
    fn_8000E0E4(s);
}

extern u16 gAffinityStr[];
s32 Affinity_FromName(void *name) {
    /* Map affinity name (fire..telius) to id 1-8; 0 if unknown or NULL. */
    s32 Str_Cmp(void *, void *);
    extern u16 gAffinityStr[];
    s32 cmp;

    if (name == NULL) {
        return 0;
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x44) == 0) {
        return 1; /* fire */
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x49) == 0) {
        return 2; /* thunder */
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x51) == 0) {
        return 3; /* wind */
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x56) == 0) {
        return 4; /* water */
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x5C) == 0) {
        return 5; /* dark */
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x61) == 0) {
        return 6; /* light */
    }
    if (Str_Cmp(name, (u8 *)gAffinityStr + 0x67) == 0) {
        return 7; /* heaven */
    }
    cmp = Str_Cmp(name, (u8 *)gAffinityStr + 0x6E);
    if (cmp != 0) {
        return 0;
    }
    return 8; /* telius */
}

void fn_8003BD58(void *arg0) {
    u8 Status_Test(void *, s32);
    void *Unit_GetHeldItemSlot(void *, s32);
    void Item_Clear(void *);
    void *Res_GetByName(void *);
    void fn_80094A54(void *, void *);
    struct Bit7 {
        u8 flag : 1;
        u8 rest : 7;
    };

    s32 i;
    u32 val;
    void *cls;
    void *obj;
    void *slot;

    if ((u8)Status_Test((u8 *)arg0 + 0x1BC, 8) != 0) {
        for (i = 0; i < 4; i++) {
            Item_Clear(Unit_GetHeldItemSlot(arg0, i));
        }

        cls = *(void **)((u8 *)arg0 + 0x18C);
        val = 0;
        if (*(u32 *)((u8 *)cls + 0x14) != 0) {
            val = *(u32 *)((u8 *)cls + 0x14);
        }
        if (val == 0) {
            obj = *(void **)((u8 *)cls + 0xC);
            if (obj != 0) {
                obj = Res_GetByName(obj);
            } else {
                obj = 0;
            }
            if (*(u32 *)((u8 *)obj + 0x14) != 0) {
                obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0xC);
                if (obj != 0) {
                    obj = Res_GetByName(obj);
                } else {
                    obj = 0;
                }
                val = *(u32 *)((u8 *)obj + 0x14);
            }
        }
        if (val != 0) {
            fn_80094A54(arg0, (void *)val);
            slot = Unit_GetHeldItemSlot(arg0, 0);
            ((struct Bit7 *)((u8 *)slot + 5))->flag = 1;
        }
    }
}

s32 fn_8003BE50(s32 arg0)
{
    if (arg0 < 0)
    {
        return 0;
    }
    else
    {
        return arg0;
    }
}

#pragma global_optimizer off
s32 fn_8003BF5C(void *arg0) {
    u8 Status_Test(void *, s32);
    u8 fn_80091D74(void *);
    s32 adj;
    u8 temp;
    u8 flag;

    if (Status_Test((u8 *)arg0 + 0x1BC, 8) == 0) {
        return 0;
    }
    if (Status_Test((u8 *)arg0 + 0x1BC, 0xA) != 0) {
        return 0;
    }
    if (fn_80091D74(arg0) != 0) {
        return 0;
    }
    flag = Status_Test((u8 *)arg0 + 0x1BC, 9);
    adj = 4;
    if (flag != 0) {
        adj = -3;
    }
    *((u8 *)arg0 + 0x19C) = (u8)(*((u8 *)arg0 + 0x19C) + adj);
    temp = *((u8 *)arg0 + 0x19C);
    if ((s8)temp <= 0) {
        *((u8 *)arg0 + 0x19C) = 0;
        return 1;
    }
    if ((s8)temp >= 0x14) {
        *((u8 *)arg0 + 0x19C) = 0x14;
        return 1;
    }
    return 0;
}
s32 fn_8003C038(void *arg0) {
    u8 Status_Test(void *, s32);
    u8 fn_80091D74(void *);
    s32 delta;
    u8 temp;
    u8 flag;

    if (Status_Test((u8 *)arg0 + 0x1BC, 8) == 0) {
        return 0;
    }
    if (Status_Test((u8 *)arg0 + 0x1BC, 0xA) != 0) {
        return 0;
    }
    if (fn_80091D74(arg0) != 0) {
        return 0;
    }
    flag = Status_Test((u8 *)arg0 + 0x1BC, 9);
    delta = 2;
    if (flag != 0) {
        delta = -1;
    }
    *((u8 *)arg0 + 0x19C) = (u8)(*((u8 *)arg0 + 0x19C) + delta);
    temp = *((u8 *)arg0 + 0x19C);
    if ((s8)temp <= 0) {
        *((u8 *)arg0 + 0x19C) = 0;
        return 1;
    }
    if ((s8)temp >= 0x14) {
        *((u8 *)arg0 + 0x19C) = 0x14;
        return 1;
    }
    return 0;
}
#pragma global_optimizer reset

u8 fn_8003C114(u8 *arg0) {
    u8 Status_Test(u8 *, s32);

    if ((u8)Status_Test(arg0 + 0x1BC, 0xA) != 0) {
        return 0x14;
    }
    return arg0[0x19C];
}

void fn_8003C15C(void *arg0) {
    u8 Status_Test(s32, M2C_UNK);
    M2C_UNK fn_80091CD8(void *);

    if (Status_Test((s32)((char *)arg0 + 0x1BC), 9) != 0) {
        *(u8 *)((char *)arg0 + 0x19C) = 0x14;
    } else {
        *(u8 *)((char *)arg0 + 0x19C) = 0;
    }
    fn_80091CD8(arg0);
}

void fn_8003C1B4(s32 arg0) {
    u8 Status_Test(s32, s32);

    if (Status_Test(arg0 + 0x1BC, 8) != 0) {
        if (Status_Test(arg0 + 0x1BC, 9) != 0) {
            *(u8 *)(arg0 + 0x19C) = 0x14;
        } else {
            *(u8 *)(arg0 + 0x19C) = *(u8 *)(*(s32 *)(arg0 + 0x188) + 0x56);
        }
    }
}

void fn_8003C3CC(void *arg0, s32 arg1) {
    void *Hash_Lookup(void *);
    void Stream_WriteU8(s32, u8);
    void Stream_WriteS32(s32, s32);
    void Stream_WriteU16(s32, u16);
    void *p;

    p = Hash_Lookup(*(void **)((u8 *)arg0 + 0x238));
    Stream_WriteU8(arg1, (u8)*(u32 *)((u8 *)p + 0x20));
    p = Hash_Lookup(*(void **)((u8 *)arg0 + 0x23C));
    Stream_WriteU8(arg1, (u8)*(u32 *)((u8 *)p + 0x20));
    p = Hash_Lookup(*(void **)((u8 *)arg0 + 0x240));
    Stream_WriteU8(arg1, *((u8 *)p + 4));
    p = Hash_Lookup(*(void **)((u8 *)arg0 + 0x244));
    Stream_WriteU8(arg1, *((u8 *)p + 4));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x250));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x251));
    Stream_WriteS32(arg1, *(s32 *)((u8 *)arg0 + 0x254));
    Stream_WriteU16(arg1, *(u16 *)((u8 *)arg0 + 0x258));
    Stream_WriteU16(arg1, *(u16 *)((u8 *)arg0 + 0x25A));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x248));
}

void fn_8003C56C(void *arg0, s32 arg1) {
    s32 *Res_GetByName(s32);
    s32 *temp_r3;

    temp_r3 = Res_GetByName(arg1);
    if (temp_r3 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x244) = (s32) *temp_r3;
    }
}

void fn_8003C5AC(void *arg0, s32 arg1) {
    s32 *Res_GetByName(s32);
    s32 *temp_r3;

    temp_r3 = Res_GetByName(arg1);
    if (temp_r3 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x240) = (s32)*temp_r3;
    }
}

void *Res_GetByName(s32);
void fn_8003C5EC(void *arg0, s32 arg1) {
    void *temp_r3;

    temp_r3 = Res_GetByName(arg1);
    if (temp_r3 != NULL) {
        *(s32*)((char*)arg0 + 0x23C) = *(s32*)((char*)temp_r3 + 0x14);
        *(u8*)((char*)arg0 + 0x251) = 0;
    }
}

void fn_8003C634(void *arg0, s32 arg1) {
    void *temp_r3;

    temp_r3 = Res_GetByName(arg1);
    if (temp_r3 != NULL) {
        *(s32*)((char*)arg0 + 0x238) = *(s32*)((char*)temp_r3 + 0x14);
        *(u8*)((char*)arg0 + 0x250) = 0;
    }
}

void fn_8003C67C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x238) = 0;
    M2C_FIELD(arg0, s32 *, 0x23C) = 0;
    M2C_FIELD(arg0, s32 *, 0x240) = 0;
    M2C_FIELD(arg0, s32 *, 0x244) = 0;
    M2C_FIELD(arg0, s8 *, 0x248) = 0;
    M2C_FIELD(arg0, s32 *, 0x24C) = 0;
    M2C_FIELD(arg0, s8 *, 0x250) = 0;
    M2C_FIELD(arg0, s8 *, 0x251) = 0;
    M2C_FIELD(arg0, s32 *, 0x254) = 0;
    M2C_FIELD(arg0, s16 *, 0x258) = 0;
    M2C_FIELD(arg0, s16 *, 0x25A) = 0;
    M2C_FIELD(arg0, s32 *, 0x25C) = 0;
    M2C_FIELD(arg0, s8 *, 0x260) = 0x10;
}

s32 fn_8003C7D0(s32 arg0) {
    u8 Status_Test(s32, M2C_UNK);
    if (Status_Test(arg0 + 0x1BC, 6) != 0) {
        return 1;
    }
    return Status_Test(arg0 + 0x1BC, 7) != 0;
}

#pragma global_optimizer off
/* Read a unit record from stream into unit; return 0 if person id is 0 (empty). */
s32 Unit_Read(void *unit, void *stream) {
    u16 Stream_ReadU16(void *);
    u8 Stream_ReadU8(void *);
    s32 Person_Get(u16);
    s32 Job_Get(u16);
    void fn_8003B6C4(void *, s32);
    void Stream_Read(void *, s32, void *);
    void fn_80104134(void *, void *);
    void fn_80105A04(void *, void *);
    s32 Unit_GetItemSlot(s32, s32);
    void Item_Read(void *, void *);
    void fn_8001D018(void *, void *);
    void fn_80017414(void *, void *);
    void fn_8003C21C(void *, void *);
    void fn_8004BC48(void *, void *);
    void fn_8003B69C(s32);
    extern u8 gUnitLists[];
    extern u8 gUnits[];
    void *src;
    void *dst;
    u32 pid;
    s32 person;
    s32 job;
    u8 id;
    void *p;

    src = stream;
    dst = unit;
    pid = Stream_ReadU16(src);
    if ((u16)pid == 0) {
        return 0;
    }
    person = Person_Get((u16)pid);
    job = Job_Get((u16)Stream_ReadU16(src));
    *(s32 *)((u8 *)dst + 0x188) = person;
    *(s32 *)((u8 *)dst + 0x18C) = job;
    id = Stream_ReadU8(src);
    fn_8003B6C4(dst, (s32)(gUnitLists + id * 0xC));
    id = Stream_ReadU8(src);
    if (id != 0) {
        p = gUnits + (id - 1) * 0x280;
    } else {
        p = NULL;
    }
    *(void **)((u8 *)dst + 0x180) = p;
    id = Stream_ReadU8(src);
    if (id != 0) {
        p = gUnits + (id - 1) * 0x280;
    } else {
        p = NULL;
    }
    *(void **)((u8 *)dst + 0x184) = p;
    id = Stream_ReadU8(src);
    if (id != 0) {
        p = gUnits + (id - 1) * 0x280;
    } else {
        p = NULL;
    }
    *(void **)((u8 *)dst + 0x194) = p;
    *((u8 *)dst + 0x199) = Stream_ReadU8(src);
    *((u8 *)dst + 0x19A) = Stream_ReadU8(src);
    *((u8 *)dst + 0x19B) = Stream_ReadU8(src);
    *((u8 *)dst + 0x19C) = Stream_ReadU8(src);
    *((u8 *)dst + 0x19D) = Stream_ReadU8(src);
    *((u8 *)dst + 0x19E) = Stream_ReadU8(src);
    *((u8 *)dst + 0x19F) = Stream_ReadU8(src);
    Stream_Read(src, 4, (u8 *)dst + 0x1A0);
    fn_80104134((u8 *)dst + 0x1A4, src);
    *((u8 *)dst + 0x1A8) = Stream_ReadU8(src);
    *((u8 *)dst + 0x1A9) = Stream_ReadU8(src);
    *((u8 *)dst + 0x1AA) = Stream_ReadU8(src);
    Stream_Read(src, 8, (u8 *)dst + 0x1AB);
    Stream_Read(src, 8, (u8 *)dst + 0x1B4);
    fn_80105A04((u8 *)dst + 0x1BC, src);
    for (person = 0; person < 8; person++) {
        Item_Read((void *)Unit_GetItemSlot((s32)dst, person), src);
    }
    fn_8001D018((u8 *)dst + 0x20C, src);
    fn_80017414((u8 *)dst + 0x228, src);
    Stream_Read(src, 0xA, (u8 *)dst + 0x214);
    fn_8003C21C(dst, src);
    fn_8004BC48(dst, src);
    *(s32 *)((u8 *)src + 4) = *(s32 *)((u8 *)src + 4) + 2;
    fn_8003B69C((s32)dst);
    return 1;
}
#pragma global_optimizer reset
void fn_8003CA94(void *arg0, s32 arg1) {
    void Stream_WriteU16(s32, u16);
    void Stream_WriteU8(s32, u8);
    void Stream_Write(s32, s32, void *);
    void fn_80104160(void *, s32);
    void fn_80105A30(void *, s32);
    s32 Unit_GetItemSlot(s32, s32);
    void fn_8001C21C(void *, s32);
    void fn_8001D044(void *, s32);
    void fn_800174A8(void *, s32);
    void fn_8003C3CC(void *, s32);
    void fn_8004BCCC(void *, s32);
    s32 i;
    u32 tmp;
    void *p;

    p = *(void **)((u8 *)arg0 + 0x188);
    if (p == NULL) {
        Stream_WriteU16(arg1, 0);
        return;
    }
    Stream_WriteU16(arg1, *(u16 *)((u8 *)p + 0x18));
    Stream_WriteU16(arg1, *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x18C) + 0x38));
    Stream_WriteU8(arg1, *((u8 *)*(void **)((u8 *)arg0 + 0x190) + 8));
    p = *(void **)((u8 *)arg0 + 0x180);
    if (p != NULL) {
        tmp = *((u8 *)p + 0x198);
    } else {
        tmp = 0;
    }
    Stream_WriteU8(arg1, (u8)tmp);
    p = *(void **)((u8 *)arg0 + 0x184);
    if (p != NULL) {
        tmp = *((u8 *)p + 0x198);
    } else {
        tmp = 0;
    }
    Stream_WriteU8(arg1, (u8)tmp);
    p = *(void **)((u8 *)arg0 + 0x194);
    if (p != NULL) {
        tmp = *((u8 *)p + 0x198);
    } else {
        tmp = 0;
    }
    Stream_WriteU8(arg1, (u8)tmp);
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x199));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x19A));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x19B));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x19C));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x19D));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x19E));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x19F));
    Stream_Write(arg1, 4, (u8 *)arg0 + 0x1A0);
    fn_80104160((u8 *)arg0 + 0x1A4, arg1);
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x1A8));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x1A9));
    Stream_WriteU8(arg1, *((u8 *)arg0 + 0x1AA));
    Stream_Write(arg1, 8, (u8 *)arg0 + 0x1AB);
    Stream_Write(arg1, 8, (u8 *)arg0 + 0x1B4);
    fn_80105A30((u8 *)arg0 + 0x1BC, arg1);
    for (i = 0; i < 8; i++) {
        fn_8001C21C((void *)Unit_GetItemSlot((s32)arg0, i), arg1);
    }
    fn_8001D044((u8 *)arg0 + 0x20C, arg1);
    fn_800174A8((u8 *)arg0 + 0x228, arg1);
    Stream_Write(arg1, 0xA, (u8 *)arg0 + 0x214);
    fn_8003C3CC(arg0, arg1);
    fn_8004BCCC(arg0, arg1);
    Stream_WriteU16(arg1, 0);
}

void fn_8003CCB0(struct unit* arg0)
{
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s32*, 0x1C) = 0;
        M2C_FIELD(arg0, s32*, 0x18) = 0;
        
        if (M2C_FIELD(arg0, s32*, 0x14) > 0) {
            M2C_FIELD(arg0, s32*, 0x14) = 0;
        }
        
        M2C_FIELD(arg0, s32*, 0xA8) = 0;
        
        lbl_803672A8 = arg0;
    }
}

void* fn_8003CE88(void* arg0, s32 arg1, void* arg2) {
    // Simple version that might work better - the exact implementation needs to match structure of target
    if (arg0 == 0) {
        return arg2;
    }
    
    // Let's look at this simpler approach based on what we know from other functions
    *(s32*)((char*)arg2 + 0x0) = (s32)arg0;
    *(u8*)((char*)arg2 + 0x4) = (u8)arg1;
    *(u8*)((char*)arg2 + 0x5) = (u8)arg1;
    
    return arg2;
}

u8 fn_8003CFF0(void *arg0, void *arg1) {
    s32 fn_8003AFA0(void *);
    s32 fn_8003A778(void *);
    s32 fn_8003AF28(void *);
    u8 fn_80038128(void *, void *);
    s32 t;
    s32 scaled;
    s32 u;
    s32 sum;
    s32 v;

    t = (s8)fn_8003AFA0(arg0);
    scaled = (t - (s8)fn_8003A778(arg1)) * 5;
    u = (s8)fn_8003AF28(arg0);
    sum = scaled + u;
    v = (sum + 0x1E) - ((u8)fn_80038128(arg0, arg1) << 1);
    if (v > 0x64) {
        v = 0x64;
    }
    if (v < 0) {
        v = 0;
    }
    return (u8)v;
}

u8 fn_8003D094(s32 arg0, u8 arg1) {
    s32 v;
    u8 Status_Test(s32, s32);

    if (arg1 == 0) {
        return 0;
    }
    v = arg1;
    if ((u8)Status_Test(arg0 + 0x1BC, 0xB) != 0) {
        v <<= 1;
    }
    if ((u8)Status_Test(arg0 + 0x1BC, 0x4B) != 0) {
        v = (v * 7) / 10;
        if (v < 1) {
            v = 1;
        }
    }
    if (v > 0x64) {
        v = 0x64;
    }
    return (u8)v;
}

#pragma opt_strength_reduction off
void Unit_Promote(void *arg0) {
    void *Res_GetByName(void *);
    void fn_800381EC(void *, s8);
    void fn_8003868C(void *, s32);
    u8 Status_Test(void *, s32);
    s32 Unit_GetMaxHp(void *);
    void Status_Set(void *, s32);
    typedef struct {
        u8 pad0[0xC];
        void *unkC;
        u8 pad10[0xC];
        u32 unk1C;
        u32 unk20;
        u32 unk24;
        u32 unk28;
        u8 unk2C[8];
    } Item;
    typedef struct {
        u8 pad0[0x18C];
        Item *unk18C;
        u8 pad190[0xA];
        u8 unk19A;
        u8 pad19B[5];
        u32 unk1A0;
        u8 pad1A4[0x10];
        u8 unk1B4;
        u8 unk1B5;
        u8 unk1B6;
        u8 unk1B7;
        u8 unk1B8;
        u8 unk1B9;
        u8 unk1BA;
        u8 unk1BB;
        u32 unk1BC;
        u32 unk1C0;
        u32 unk1C4;
        u32 unk1C8;
        u8 pad1CC[0x40];
        u8 unk20C[8];
    } Unit;
    Unit *self;
    Item *item;
    void *child;
    void *flags;
    s32 code;
    s32 i;
    s32 ctr;
    u8 t;
    u32 tmp;
    u8 *dp;
    Item *ip;

    self = (Unit *)arg0;
    item = self->unk18C;
    self->unk1BC &= ~item->unk1C;
    self->unk1C0 &= ~item->unk20;
    self->unk1C4 &= ~item->unk24;
    self->unk1C8 &= ~item->unk28;
    child = self->unk18C->unkC;
    if (child != NULL) {
        child = Res_GetByName(child);
    } else {
        child = NULL;
    }
    self->unk18C = child;
    flags = &self->unk1BC;
    code = 0x44;
    item = self->unk18C;
    self->unk1BC |= item->unk1C;
    self->unk1C0 |= item->unk20;
    self->unk1C4 |= item->unk24;
    self->unk1C8 |= item->unk28;
    if (Status_Test(flags, code) == 0) {
        Status_Set(&self->unk1BC, 0x45);
    }
    i = 0;
    for (ctr = 2; ctr != 0; ctr--) {
        item = self->unk18C;
        ip = (Item *)((u8 *)item + (u8)i);
        dp = (u8 *)self + (u8)i;
        t = ip->unk2C[0];
        if (dp[0x20C] < t) {
            dp[0x20C] = t;
        }
        i = (s32)i + 1;
        item = self->unk18C;
        ip = (Item *)((u8 *)item + (u8)i);
        dp = (u8 *)self + (u8)i;
        t = ip->unk2C[0];
        if (dp[0x20C] < t) {
            dp[0x20C] = t;
        }
        i = i + 1;
        item = self->unk18C;
        ip = (Item *)((u8 *)item + (u8)i);
        dp = (u8 *)self + (u8)i;
        t = ip->unk2C[0];
        if (dp[0x20C] < t) {
            dp[0x20C] = t;
        }
        i = i + 1;
        item = self->unk18C;
        ip = (Item *)((u8 *)item + (u8)i);
        dp = (u8 *)self + (u8)i;
        t = ip->unk2C[0];
        if (dp[0x20C] < t) {
            dp[0x20C] = t;
        }
        i = i + 1;
    }
    self->unk19A = 1;
    fn_8003868C(self, 0);
    tmp = self->unk1B4;
    self->unk1B4 = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    tmp = self->unk1B5;
    self->unk1B5 = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    tmp = self->unk1B6;
    self->unk1B6 = (u8)((s32)(((u32)tmp >> 31) + (int)tmp) >> 1);
    tmp = self->unk1B7;
    self->unk1B7 = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    tmp = self->unk1B8;
    self->unk1B8 = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    tmp = self->unk1B9;
    self->unk1B9 = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    tmp = self->unk1BA;
    self->unk1BA = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    tmp = self->unk1BB;
    self->unk1BB = (u8)((s32)(((u32)tmp >> 31) + tmp) >> 1);
    self->unk1A0 &= 0xFFFBFFFF;
    fn_800381EC(self, (s8)Unit_GetMaxHp(self));
}

s32 fn_8003D538(s32 arg0) {
    u8 Status_Test(s32, s32);
    void *Res_GetByName(void *);
    void *tmp;
    void *resolved;

    if (Status_Test(arg0 + 0x1BC, 2) != 0) {
        return 0;
    }
    if (Status_Test(arg0 + 0x1BC, 8) != 0) {
        return 0;
    }
    if (Status_Test(arg0 + 0x1BC, 0x4D) != 0) {
        return 0;
    }
    tmp = *(void **)((u8 *)*(void **)(arg0 + 0x18C) + 0xC);
    if (tmp != NULL) {
        resolved = Res_GetByName(tmp);
    } else {
        resolved = NULL;
    }
    if (resolved == NULL) {
        return 0;
    }
    return (s8)*(u8 *)(arg0 + 0x19A) >= 0xA;
}

#pragma opt_strength_reduction reset
void Unit_SetDisposId(void *arg0, u8 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, u8 *, 0x199) = arg1;
    }
}

void Unit_MoveToList(void *arg0, s32 arg1) {
    void fn_800156A0(void *, void *);
    void fn_80015718(void *, void *, s32);
    void fn_800946F0(void *);
    extern u8 gUnitLists[];
    s32 listId;
    void *unit;
    s32 off;

    listId = arg1;
    unit = arg0;
    switch (listId) {
    case 0:
    case 2:
    case 3:
        fn_800946F0(unit);
        fn_800156A0(*(void **)((u8 *)unit + 0x190), unit);
        off = listId * 0xC;
        fn_80015718(gUnitLists + off, unit, off);
        break;
    }
}

void Unit_MoveToListHead(void *arg0, s32 arg1)
{
    extern u8 gUnitLists[];

    extern void fn_800946F0(void *);
    extern void fn_800156A0(void *, void *);
    extern void fn_800157DC(void *, void *);

    u8 *obj;
    s32 index;

    obj = (u8 *)arg0;
    index = arg1;

    if (index != 1) {
        if (index < 1) {
            if (index >= 0) {
                fn_800946F0(obj);
            }
        } else {
            if (index < 4) {
                fn_800946F0(obj);
            }
        }
    }

    fn_800156A0(*(void **)(obj + 0x190), obj);

    fn_800157DC(
        gUnitLists + index * 0xC,
        obj
    );
}

#pragma use_lmw_stmw on
void fn_8003D70C(s32 arg0) {
    extern u8 gBattleState[];
    void *fn_8014D8FC(void *);
    s32 fn_801661CC(void *);
    void *Res_GetByName(void *);
    u8 Status_Test(s32, s32);
    s8 fn_801F1A2C(void);
    s32 fn_8000CEE4(s32);

    void *partner;
    s16 s7;
    s16 s6;
    s16 s5;
    s16 s4;
    s16 s3;
    s16 s2;
    s16 s1;
    s16 s0;
    s32 bonus;
    s32 level;
    u8 *cls;
    s32 factor;

    level = fn_801661CC(fn_8014D8FC(gBattleState));
    if (*(u8 *)(*(u8 **)(arg0 + 0x190) + 8) != 1) {
        level = 0;
    }
    level += (s8)*(u8 *)(arg0 + 0x19A);
    if (level > 0x14) {
        level = 0x14;
    }
    if (level < 1) {
        level = 1;
    }
    *(u8 *)(arg0 + 0x19A) = level;

    cls = *(u8 **)(arg0 + 0x18C);
    s0 = (s16)(level * cls[0x54]);
    s1 = (s16)(level * cls[0x55]);
    s2 = (s16)(level * cls[0x56]);
    s3 = (s16)(level * cls[0x57]);
    s4 = (s16)(level * cls[0x58]);
    s5 = (s16)(level * cls[0x59]);
    s6 = (s16)(level * cls[0x5A]);
    s7 = (s16)(level * cls[0x5B]);
    {
        void *name = *(void **)(cls + 0xC);
        if (name != NULL) {
            partner = Res_GetByName(name);
        } else {
            partner = NULL;
        }
    }

    if (partner != NULL && Status_Test(arg0 + 0x1BC, 2) != 0 && Status_Test(arg0 + 0x1BC, 8) == 0 && Status_Test((s32)partner + 0x1C, 2) == 0) {
        u8 *p = (u8 *)partner;
        bonus = (s8)fn_801F1A2C();
        bonus += fn_801661CC(fn_8014D8FC(gBattleState));
        s0 = (s16)(s0 + bonus * p[0x54]);
        s1 = (s16)(s1 + bonus * p[0x55]);
        s2 = (s16)(s2 + bonus * p[0x56]);
        s3 = (s16)(s3 + bonus * p[0x57]);
        s4 = (s16)(s4 + bonus * p[0x58]);
        s5 = (s16)(s5 + bonus * p[0x59]);
        s6 = (s16)(s6 + bonus * p[0x5A]);
        s7 = (s16)(s7 + bonus * p[0x5B]);
    }

    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1AB) = *(u8 *)(arg0 + 0x1AB) + (s0 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1AC) = *(u8 *)(arg0 + 0x1AC) + (s1 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1AD) = *(u8 *)(arg0 + 0x1AD) + (s2 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1AE) = *(u8 *)(arg0 + 0x1AE) + (s3 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1AF) = *(u8 *)(arg0 + 0x1AF) + (s4 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1B0) = *(u8 *)(arg0 + 0x1B0) + (s5 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1B1) = *(u8 *)(arg0 + 0x1B1) + (s6 * factor) / 10000;
    factor = 0x64 - (0xA - fn_8000CEE4(0x14));
    *(u8 *)(arg0 + 0x1B2) = *(u8 *)(arg0 + 0x1B2) + (s7 * factor) / 10000;
}

s32 fn_8003DAC4(s32 arg0, void *arg1) {
    u64 *Item_GetFlagsPtr(void *);
    u8 fn_8001D37C(void *);
    s32 fn_8003B258(void);
    s32 fn_800955BC(s32);
    s32 fn_80095614(s32);
    s8 lim;
    u8 code;

    if (((*(u8 *)((u8 *)arg1 + 5) >> 7) & 1) != 0) {
        code = 2;
    } else {
        lim = (s8)fn_8003B258();
        if ((s32)fn_8001D37C(arg1) >= (s32)lim) {
            code = 1;
        } else {
            if ((*Item_GetFlagsPtr(arg1) & 5ULL) != 0) {
                if (fn_80095614(arg0) < 0) {
                    code = 3;
                    goto end;
                }
            } else if (fn_800955BC(arg0) < 0) {
                code = 3;
                goto end;
            }
            code = 0;
        }
    }
end:
    return code == 0;
}

s32 fn_8003DBA8(s32 arg0, void *arg1) {
    u64 *Item_GetFlagsPtr(void *);
    u8 fn_8001D37C(void *);
    s32 fn_8003B258(void);
    s32 fn_800955BC(s32);
    s32 fn_80095614(s32);
    s8 lim;

    if (((*(u8 *)((u8 *)arg1 + 5) >> 7) & 1) != 0) {
        return 2;
    }
    lim = (s8)fn_8003B258();
    if ((s32)fn_8001D37C(arg1) >= (s32)lim) {
        return 1;
    }
    if ((*Item_GetFlagsPtr(arg1) & 5ULL) != 0) {
        if (fn_80095614(arg0) < 0) {
            return 3;
        }
    } else {
        if (fn_800955BC(arg0) < 0) {
            return 3;
        }
    }
    return 0;
}

s32 fn_8003DC80(s32 arg0, s32 arg1)
{
    s8 fn_8003AEB0(s32);
    s32 b;
    s32 a;

    b = (s8)fn_8003AEB0(arg1);
    a = (s8)fn_8003AEB0(arg0);
    return b > a;
}

void fn_8003DCDC(u8 *arg0, u8 *arg1, s32 arg2, s8 *arg3, s8 *arg4) {
    s32 b19e;
    s32 a19e;
    s32 a19f;
    s32 b19f;
    s32 d0;
    s32 d1;
    s32 product;
    b19e = arg1[0x19E];
    a19e = arg0[0x19E];
    b19e = (s8)b19e;
    a19f = arg0[0x19F];
    d0 = (s8)(b19e - a19e);
    b19f = arg1[0x19F];
    d1 = (s8)(b19f - a19f);
    product = arg2 * d0;
    *arg3 = (s8)(product + b19e);
    d1 = d1 * arg2;
    *arg4 = (s8)(d1 + arg1[0x19F]);
}

s32 fn_8003DD20(s32 arg0, s32 arg1) {
    s8 fn_8003A1E0(s32);
    s32 temp_r31;
    s32 temp_r4;

    temp_r31 = (s8)fn_8003A1E0(arg1);
    temp_r4 = (s8)fn_8003A1E0(arg0);
    return temp_r31 <= (temp_r4 + 2);
}

s32 fn_8003DD7C(s32 arg0, s32 arg1) {
    s8 fn_8003A1E0(s32);
    u8 Status_Test(s32, s32);
    s32 temp_r31;
    s32 temp_r4;

    if (Status_Test(arg1 + 0x1BC, 3) != 0) {
        return 0;
    }
    temp_r31 = fn_8003A1E0(arg1);
    temp_r4 = fn_8003A1E0(arg0);
    return (temp_r31 <= (temp_r4 - 2));
}

#pragma use_lmw_stmw on
void fn_8003DFB8(void *arg0) {
    void fn_800156A0(void *);
    void fn_80015718(void *, void *);
    void fn_800157DC(void *, void *);
    void Unit_SetMapPos(void *, u8, u8);
    void Unit_Clear(void *, s32);
    void Unit_MoveToListHead(void *, s32);
    void Unit_SeparateRescue(void *, s32, s32);
    void *fn_8003F1AC(s32);
    u8 fn_8003F1C0(void *);
    void *fn_8003F1C8(void *);
    s32 fn_8003F1D0(s32 *, s32);
    void fn_8003F1DC(s32 *, s32);
    void fn_8003F1EC(void *, s32);
    void fn_8003F1F4(s32 *, s32);
    void *fn_8003F204(void *);
    u8 fn_8003F20C(void *);
    u8 fn_8003F214(void *);
    s32 *fn_8003F21C(void *);
    void fn_8004EA60(void *, s32);
    extern u8 gUnitLists[];

    void *self = arg0;
    void *partner = *(void **)((u8 *)self + 0x194);
    s32 flags;
    void *other;
    void *next;
    u8 a, b;
    void *p;

    if (partner == NULL) {
        goto finish;
    }

    flags = *(s32 *)((u8 *)self + 0x1A0);
    if (flags & 2) {
        a = ((u8 *)self)[0x19F];
        *(s32 *)((u8 *)self + 0x1A0) = flags & ~2;
        b = ((u8 *)self)[0x19E];
        *(s32 *)((u8 *)partner + 0x1A0) = *(s32 *)((u8 *)partner + 0x1A0) & ~4;
        *(void **)((u8 *)self + 0x194) = NULL;
        *(void **)((u8 *)partner + 0x194) = NULL;
        Unit_SetMapPos(partner, b, a);
        *(s32 *)((u8 *)partner + 0x1A0) |= 1;

        if (*(void **)((u8 *)partner + 0x194) != NULL) {
            if (*fn_8003F21C(partner) & 2) {
                other = *(void **)((u8 *)partner + 0x194);
                a = fn_8003F214(partner);
                b = fn_8003F20C(partner);
                p = fn_8003F204(partner);
                fn_8003F1F4(fn_8003F21C(partner), 2);
                fn_8003F1F4(fn_8003F21C(p), 4);
                fn_8003F1EC(partner, 0);
                fn_8003F1EC(p, 0);
                Unit_SetMapPos(p, b, a);
                fn_8003F1DC(fn_8003F21C(p), 1);
                if (fn_8003F204(other) != NULL) {
                    if (fn_8003F1D0(fn_8003F21C(other), 2) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(other, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    } else if (fn_8003F1D0(fn_8003F21C(other), 4) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(next, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    }
                }
                fn_8004EA60(other, 1);
                if (fn_8003F1C0(fn_8003F1C8(other)) == 0) {
                    Unit_MoveToListHead(other, 5);
                    fn_8003F1DC(fn_8003F21C(other), 0x4000);
                } else {
                    fn_8003F1C8(other);
                    fn_800156A0(other);
                    Unit_Clear(other, -1);
                    fn_80015718(fn_8003F1AC(4), other);
                }
            } else if (*fn_8003F21C(partner) & 4) {
                other = *(void **)((u8 *)partner + 0x194);
                a = fn_8003F214(partner);
                b = fn_8003F20C(partner);
                p = fn_8003F204(other);
                fn_8003F1F4(fn_8003F21C(other), 2);
                fn_8003F1F4(fn_8003F21C(p), 4);
                fn_8003F1EC(other, 0);
                fn_8003F1EC(p, 0);
                Unit_SetMapPos(p, b, a);
                fn_8003F1DC(fn_8003F21C(p), 1);
                if (fn_8003F204(other) != NULL) {
                    if (fn_8003F1D0(fn_8003F21C(other), 2) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(other, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    } else if (fn_8003F1D0(fn_8003F21C(other), 4) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(next, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    }
                }
                fn_8004EA60(other, 1);
                if (fn_8003F1C0(fn_8003F1C8(other)) == 0) {
                    Unit_MoveToListHead(other, 5);
                    fn_8003F1DC(fn_8003F21C(other), 0x4000);
                } else {
                    fn_8003F1C8(other);
                    fn_800156A0(other);
                    Unit_Clear(other, -1);
                    fn_80015718(fn_8003F1AC(4), other);
                }
            }
        }

        fn_8004EA60(partner, 1);
        if (*(u8 *)(*(u8 **)((u8 *)partner + 0x190) + 8) == 0) {
            fn_8003F1C8(partner);
            fn_800156A0(partner);
            fn_800157DC(fn_8003F1AC(5), partner);
            *fn_8003F21C(partner) |= 0x4000;
        } else {
            fn_800156A0(partner);
            Unit_Clear(partner, -1);
            fn_80015718(gUnitLists + 0x30, partner);
        }
    } else if (flags & 4) {
        other = *(void **)((u8 *)partner + 0x194);
        *(s32 *)((u8 *)partner + 0x1A0) = *(s32 *)((u8 *)partner + 0x1A0) & ~2;
        a = ((u8 *)self)[0x19F];
        b = ((u8 *)self)[0x19E];
        *(s32 *)((u8 *)other + 0x1A0) = *(s32 *)((u8 *)other + 0x1A0) & ~4;
        *(void **)((u8 *)partner + 0x194) = NULL;
        *(void **)((u8 *)other + 0x194) = NULL;
        Unit_SetMapPos(other, b, a);
        *(s32 *)((u8 *)other + 0x1A0) |= 1;

        if (*(void **)((u8 *)partner + 0x194) != NULL) {
            if (*fn_8003F21C(partner) & 2) {
                other = *(void **)((u8 *)partner + 0x194);
                a = fn_8003F214(partner);
                b = fn_8003F20C(partner);
                p = fn_8003F204(partner);
                fn_8003F1F4(fn_8003F21C(partner), 2);
                fn_8003F1F4(fn_8003F21C(p), 4);
                fn_8003F1EC(partner, 0);
                fn_8003F1EC(p, 0);
                Unit_SetMapPos(p, b, a);
                fn_8003F1DC(fn_8003F21C(p), 1);
                if (fn_8003F204(other) != NULL) {
                    if (fn_8003F1D0(fn_8003F21C(other), 2) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(other, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    } else if (fn_8003F1D0(fn_8003F21C(other), 4) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(next, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    }
                }
                fn_8004EA60(other, 1);
                if (fn_8003F1C0(fn_8003F1C8(other)) == 0) {
                    Unit_MoveToListHead(other, 5);
                    fn_8003F1DC(fn_8003F21C(other), 0x4000);
                } else {
                    fn_8003F1C8(other);
                    fn_800156A0(other);
                    Unit_Clear(other, -1);
                    fn_80015718(fn_8003F1AC(4), other);
                }
            } else if (*fn_8003F21C(partner) & 4) {
                other = *(void **)((u8 *)partner + 0x194);
                a = fn_8003F214(partner);
                b = fn_8003F20C(partner);
                p = fn_8003F204(other);
                fn_8003F1F4(fn_8003F21C(other), 2);
                fn_8003F1F4(fn_8003F21C(p), 4);
                fn_8003F1EC(other, 0);
                fn_8003F1EC(p, 0);
                Unit_SetMapPos(p, b, a);
                fn_8003F1DC(fn_8003F21C(p), 1);
                if (fn_8003F204(other) != NULL) {
                    if (fn_8003F1D0(fn_8003F21C(other), 2) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(other, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    } else if (fn_8003F1D0(fn_8003F21C(other), 4) != 0) {
                        next = fn_8003F204(other);
                        a = fn_8003F214(other);
                        Unit_SeparateRescue(next, fn_8003F20C(other), a);
                        fn_8003DFB8(next);
                    }
                }
                fn_8004EA60(other, 1);
                if (fn_8003F1C0(fn_8003F1C8(other)) == 0) {
                    Unit_MoveToListHead(other, 5);
                    fn_8003F1DC(fn_8003F21C(other), 0x4000);
                } else {
                    fn_8003F1C8(other);
                    fn_800156A0(other);
                    Unit_Clear(other, -1);
                    fn_80015718(fn_8003F1AC(4), other);
                }
            }
        }

        fn_8004EA60(partner, 1);
        if (*(u8 *)(*(u8 **)((u8 *)partner + 0x190) + 8) == 0) {
            fn_8003F1C8(partner);
            fn_800156A0(partner);
            fn_800157DC(fn_8003F1AC(5), partner);
            *fn_8003F21C(partner) |= 0x4000;
        } else {
            fn_800156A0(partner);
            Unit_Clear(partner, -1);
            fn_80015718(gUnitLists + 0x30, partner);
        }
    }

finish:
    fn_8004EA60(self, 1);
    if (*(u8 *)(*(u8 **)((u8 *)self + 0x190) + 8) == 0) {
        fn_800156A0(self);
        fn_800157DC(fn_8003F1AC(5), self);
        *(s32 *)((u8 *)self + 0x1A0) |= 0x4000;
    } else {
        fn_800156A0(self);
        Unit_Clear(self, -1);
        fn_80015718(gUnitLists + 0x30, self);
    }
}
#pragma use_lmw_stmw reset

void fn_8003E8DC(void *arg0, void *arg1) {
    u8 temp_r0;
    u8 temp_r4;
    u8 temp_r5;
    u8 temp_r6;
    u8 temp_r7;
    void *temp_r3;
    void *temp_r6_2;
    void *temp_r6_3;
    void *temp_r6_4;
    void *temp_r6_5;
    void *temp_r6_6;
    void *temp_r6_7;
    
    temp_r3 = M2C_FIELD(arg0, void **, 0x188);
    if (M2C_FIELD(temp_r3, u32 *, 0x1C) != 0) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, u8 *, 0x19D);
    if ((temp_r0 == 1) || (temp_r0 == 2)) {
        temp_r4 = M2C_FIELD(arg0, u8 *, 0x1A4);
        M2C_FIELD(arg0, u8 *, 0x1A4) = temp_r4 + 1;
        if ((temp_r4 + 1) == M2C_FIELD(M2C_FIELD(arg0, void **, 0x18C), u8 *, 0x30)) {
            temp_r5 = M2C_FIELD(arg0, u8 *, 0x1A5);
            M2C_FIELD(arg0, u8 *, 0x1A5) = temp_r5 + 1;
        }
        return;
    }
    if ((temp_r0 != 3) && (temp_r0 != 4)) {
        return;
    }
    temp_r6 = M2C_FIELD(arg0, u8 *, 0x1A4);
    if (temp_r6 != 0) {
        M2C_FIELD(arg0, u8 *, 0x1A4) = temp_r6 - 1;
        if ((temp_r6 - 1) == 0) {
            temp_r7 = M2C_FIELD(arg0, u8 *, 0x1A5);
            M2C_FIELD(arg0, u8 *, 0x1A5) = temp_r7 - 1;
        }
    }
    if (M2C_FIELD(arg1, s32 *, 0x4) == 0) {
        return;
    }
    temp_r6_2 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1AC) = (s8) ((M2C_FIELD(temp_r6_2, u8 *, 0x4D) - M2C_FIELD(temp_r6_2, u8 *, 0x45)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x1E));
    temp_r6_3 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1AD) = (s8) ((M2C_FIELD(temp_r6_3, u8 *, 0x4E) - M2C_FIELD(temp_r6_3, u8 *, 0x46)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x1F));
    temp_r6_4 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1AE) = (s8) ((M2C_FIELD(temp_r6_4, u8 *, 0x4F) - M2C_FIELD(temp_r6_4, u8 *, 0x47)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x20));
    temp_r6_5 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1AF) = (s8) ((M2C_FIELD(temp_r6_5, u8 *, 0x50) - M2C_FIELD(temp_r6_5, u8 *, 0x48)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x21));
    M2C_FIELD(arg0, s8 *, 0x1B0) = (s8) (0x28 - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x22));
    temp_r6_6 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1B1) = (s8) ((M2C_FIELD(temp_r6_6, u8 *, 0x52) - M2C_FIELD(temp_r6_6, u8 *, 0x4A)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x23));
    temp_r6_7 = M2C_FIELD(arg0, void **, 0x18C);
    M2C_FIELD(arg0, s8 *, 0x1B2) = (s8) ((M2C_FIELD(temp_r6_7, u8 *, 0x53) - M2C_FIELD(temp_r6_7, u8 *, 0x4B)) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x188), u8 *, 0x24));
    M2C_FIELD(arg0, s8 *, 0x1AA) = (s8) (0x14 - M2C_FIELD(M2C_FIELD(arg0, void **, 0x18C), u8 *, 0x3E));
}

void Unit_SeparateRescue(void *arg0, s32 arg1, s32 arg2) {
    void Unit_SetMapPos(void *, s32, s32);
    s32 flags;
    void *partner;

    flags = *(s32 *)((u8 *)arg0 + 0x1A0);
    partner = *(void **)((u8 *)arg0 + 0x194);
    *(s32 *)((u8 *)arg0 + 0x1A0) = flags & ~2;
    *(s32 *)((u8 *)partner + 0x1A0) = *(s32 *)((u8 *)partner + 0x1A0) & ~4;
    *(void **)((u8 *)arg0 + 0x194) = NULL;
    *(void **)((u8 *)partner + 0x194) = NULL;
    Unit_SetMapPos(partner, arg1, arg2);
    *(s32 *)((u8 *)partner + 0x1A0) |= 1;
}

void fn_8003EA84(void *arg0, void *arg1) {
    Unit_SetMapPos(arg1, *(u8*)((u8*)arg0 + 0x19F), *(u8*)((u8*)arg0 + 0x19E));
    *(s32*)((u8*)arg0 + 0x1A0) |= 2;
    *(s32*)((u8*)arg1 + 0x1A0) |= 4;
    *(void**)((u8*)arg0 + 0x194) = arg1;
    *(void**)((u8*)arg1 + 0x194) = arg0;
}

#pragma use_lmw_stmw on
void Unit_InitFromDispos(void *arg0, void *arg1) {
    void *Res_GetByName(void *);
    void fn_80104410(void *);
    void Unit_SetMapPos(void *, u8, u8);
    void fn_80105DAC(void *, void *);
    s32 Str_Cmp(void *, void *);
    u8 Status_Test(void *, s32);
    void *fn_80028854(void);
    void fn_8003C1B4(void *);
    void fn_8003D70C(void *);
    void fn_8001753C(void *);
    void fn_8003708C(void *, u8 *);
    void fn_80094A54(void *);
    void fn_800946F0(void *);
    void *Unit_GetItemSlot(void *, s32);
    u8 fn_80094768(void *);
    void fn_8003BD58(void *);
    void fn_80092438(void *);
    u8 fn_80092ADC(void *, u8);
    void *Unit_GetHeldItemSlot(void *, s32);
    u8 fn_80093DA8(void *);
    void fn_800056A0(s32);
    void fn_80036834(void *);
    void fn_800951D0(void *, s32);
    void fn_80095070(void *, s32);
    s8 Unit_GetMaxHp(void *);
    void fn_800381EC(void *, s8);
    u8 fn_80091D74(void *);
    void fn_8003BE50(void *);
    void fn_8004FE58(void *);
    void fn_8003C67C(void *);
    void fn_8003C4B0(void *, void *);
    void fn_801E35EC(void *, void *);
    extern u8 gBattleState[];
    extern u8 gSystemSave[];

    struct Self {
        u8 pad[0x188];
        void *unk188;
        void *unk18C;
        u8 pad190[4];
        s32 unk194;
        u8 pad198;
        u8 unk199;
        u8 unk19A;
        u8 unk19B;
        u8 unk19C;
        u8 pad19D[3];
        s32 unk1A0;
        u8 pad1A4[5];
        u8 unk1A9;
        u8 unk1AA;
        u8 pad1AB[9];
        u8 unk1B4;
        u8 unk1B5;
        u8 unk1B6;
        u8 unk1B7;
        u8 unk1B8;
        u8 unk1B9;
        u8 unk1BA;
        u8 unk1BB;
        u32 unk1BC;
        u32 unk1C0;
        u32 unk1C4;
        u32 unk1C8;
        u8 pad1CC[0x40];
        u8 unk20C[8];
        u8 pad214[0x14];
        s16 unk228;
        s16 unk22A;
        s16 unk22C;
        s16 unk22E;
        s16 unk230;
        s16 unk232;
        u8 unk234;
        u8 unk235;
        u8 pad236[0x12];
        u8 unk248;
        u8 pad249[0xB];
        u32 unk254;
    };
    struct Src {
        void *unk0;
        void *unk4;
        u8 unk8;
        u8 pad9;
        u8 unkA;
        u8 unkB;
        u8 unkC;
        u8 padD[3];
        void *unk10[8];
        u8 pad30[8];
        void *unk48[5];
        u8 unk5C[8];
        u8 unk64;
        u8 pad65;
        u8 unk66;
        u8 unk67;
    };
    struct Cls {
        u8 pad[0x10];
        void *unk10;
        u8 pad14[6];
        u8 unk1A;
        u8 pad1B[0x25];
        u8 unk40[0x10];
        u8 unk2D_dummy;
    };

    u8 sp8[8];
    struct Self *self;
    struct Src *src;
    struct Src *walk;
    s32 i;
    u8 t;
    void *item;
    void *p;
    u8 a, b;
    u8 j;
    void *c;

    self = (struct Self *)arg0;
    src = (struct Src *)arg1;
    self->unk188 = Res_GetByName(src->unk0);
    self->unk19B = 0;
    self->unk1A9 = 0;
    self->unk1AA = 0;
    self->unk1A0 = 0;
    fn_80104410((u8 *)self + 0x1A4);
    self->unk194 = 0;
    self->unk1C8 = 0;
    self->unk1C4 = 0;
    self->unk1C0 = 0;
    self->unk1BC = 0;
    self->unk228 = 0;
    self->unk22A = 0;
    self->unk22C = 0;
    self->unk22E = 0;
    self->unk230 = 0;
    self->unk232 = 0;
    self->unk234 = 0;
    self->unk235 = 0;
    if (src->unk4 == 0) {
        self->unk18C = Res_GetByName(*(void **)((u8 *)self->unk188 + 0x10));
    } else {
        self->unk18C = Res_GetByName(src->unk4);
    }
    Unit_SetMapPos(self, src->unkB, src->unkC);
    c = self->unk188;
    self->unk1BC |= *(u32 *)((u8 *)c + 0x40);
    self->unk1C0 |= *(u32 *)((u8 *)c + 0x44);
    self->unk1C4 |= *(u32 *)((u8 *)c + 0x48);
    self->unk1C8 |= *(u32 *)((u8 *)c + 0x4C);
    c = self->unk18C;
    self->unk1BC |= *(u32 *)((u8 *)c + 0x1C);
    self->unk1C0 |= *(u32 *)((u8 *)c + 0x20);
    self->unk1C4 |= *(u32 *)((u8 *)c + 0x24);
    self->unk1C8 |= *(u32 *)((u8 *)c + 0x28);
    walk = src;
    for (i = 0; i < 5; i++) {
        if (walk->unk48[0] != 0) {
            fn_80105DAC(&self->unk1BC, walk->unk48[0]);
        }
        walk = (struct Src *)((u8 *)walk + 4);
    }
    c = self->unk188;
    if (Str_Cmp(src->unk4, *(void **)((u8 *)c + 0x10)) != 0 ||
        src->unkA > (s8)*(u8 *)((u8 *)c + 0x1A)) {
        self->unk19A = src->unkA;
    } else {
        self->unk19A = *(u8 *)((u8 *)c + 0x1A);
    }
    if (Status_Test(&self->unk1BC, 0x4E) != 0) {
        if (fn_80028854() != 0) {
            fn_80028854();
        }
        if (Status_Test(&self->unk1BC, 2) != 0) {
            self->unk19A = 1;
        } else {
            self->unk19A = 0xA;
        }
    }
    fn_8003C1B4(self);
    t = src->unk64;
    if (t != 0 && t < 0x14) {
        self->unk19C = t;
    }
    if (src->unk8 & 1) {
        fn_8003D70C(self);
        fn_8001753C(&self->unk228);
    }
    sp8[0] = src->unk5C[0];
    sp8[1] = src->unk5C[1];
    sp8[2] = src->unk5C[2];
    sp8[3] = src->unk5C[3];
    sp8[4] = src->unk5C[4];
    sp8[5] = src->unk5C[5];
    sp8[6] = src->unk5C[6];
    sp8[7] = src->unk5C[7];
    fn_8003708C(self, sp8);
    walk = src;
    self->unk1B4 = *((u8 *)self->unk188 + 0x2D);
    self->unk1B5 = *((u8 *)self->unk188 + 0x2E);
    self->unk1B6 = *((u8 *)self->unk188 + 0x2F);
    self->unk1B7 = *((u8 *)self->unk188 + 0x30);
    self->unk1B8 = *((u8 *)self->unk188 + 0x31);
    self->unk1B9 = *((u8 *)self->unk188 + 0x32);
    self->unk1BA = *((u8 *)self->unk188 + 0x33);
    self->unk1BB = *((u8 *)self->unk188 + 0x34);
    for (i = 0; i < 8; i++) {
        if (walk->unk10[0] != 0) {
            t = *((u8 *)src + i + 0x30);
            if ((t & 2) == 0 || gBattleState[0x57] != 1) {
                fn_80094A54(self);
                t = *((u8 *)src + i + 0x30);
                if (t & 1) {
                    if (t & 2) {
                        fn_800946F0(self);
                        p = Unit_GetItemSlot(self, i);
                        *(u8 *)((u8 *)p + 5) |= 0x40;
                    } else if (fn_80094768(self) == 0) {
                        p = Unit_GetItemSlot(self, i);
                        *(u8 *)((u8 *)p + 5) |= 0x40;
                    }
                }
            }
        }
        walk = (struct Src *)((u8 *)walk + 4);
    }
    fn_8003BD58(self);
    self->unk20C[0] = *((u8 *)self->unk18C + 0x2C);
    self->unk20C[1] = *((u8 *)self->unk18C + 0x2D);
    self->unk20C[2] = *((u8 *)self->unk18C + 0x2E);
    self->unk20C[3] = *((u8 *)self->unk18C + 0x2F);
    self->unk20C[4] = *((u8 *)self->unk18C + 0x30);
    self->unk20C[5] = *((u8 *)self->unk18C + 0x31);
    self->unk20C[6] = *((u8 *)self->unk18C + 0x32);
    self->unk20C[7] = *((u8 *)self->unk18C + 0x33);
    fn_80092438(self);
    for (j = 0; j < 8; j++) {
        if (fn_80092ADC(self, j) != 0) {
            t = *((u8 *)self->unk188 + 0x35 + j);
            if (t != 0) {
                self->unk20C[j] = t;
            }
        }
    }
    if (src->unk8 & 1) {
        for (i = 0; i < 4; i++) {
            item = Unit_GetHeldItemSlot(self, i);
            if (item != 0 && *(void **)item != 0 && fn_80093DA8(self) == 0) {
                p = *(void **)item;
                a = p ? *(u8 *)((u8 *)p + 0x12) : 0xC;
                if (a < 8) {
                    p = *(void **)item;
                    a = p ? *(u8 *)((u8 *)p + 0x12) : 0xC;
                    if (fn_80092ADC(self, a) == 0) {
                        if (((*(u8 *)((u8 *)item + 5) >> 6) & 1) == 0) {
                            fn_800056A0(0);
                        }
                    } else {
                        p = *(void **)item;
                        b = p ? *(u8 *)((u8 *)p + 0x16) : 0;
                        p = *(void **)item;
                        a = p ? *(u8 *)((u8 *)p + 0x12) : 0xC;
                        if ((u8)fn_80092ADC(self, a) < b) {
                            p = *(void **)item;
                            b = p ? *(u8 *)((u8 *)p + 0x16) : 0;
                            p = *(void **)item;
                            a = p ? *(u8 *)((u8 *)p + 0x12) : 0xC;
                            self->unk20C[a] = b;
                        }
                    }
                }
            }
        }
    }
    fn_80036834(self);
    fn_800951D0(self, -1);
    fn_80095070(self, -1);
    fn_800381EC(self, Unit_GetMaxHp(self));
    if (fn_80091D74(self) != 0 && Status_Test(&self->unk1BC, 9) == 0) {
        fn_8003BE50(self);
    }
    fn_8004FE58(self);
    t = src->unk67;
    if (t != 0) {
        self->unk199 = t;
    }
    if (src->unk8 & 4) {
        self->unk1A0 |= 0x100;
    }
    fn_8003C67C(self);
    fn_8003C4B0(self, src);
    self->unk248 = src->unk66;
    if (src->unk8 & 2) {
        self->unk254 |= 0x02000000;
    }
    if (src->unk8 & 0x10) {
        self->unk254 |= 0x10000000;
    }
    if (src->unk8 & 0x20) {
        self->unk254 |= 0x20000000;
    }
    if (src->unk8 & 0x40) {
        self->unk254 |= 0x20000;
    }
    fn_801E35EC(gSystemSave, self->unk188);
    self->unk1A0 |= 0x80000;
}
#pragma use_lmw_stmw reset

void *fn_8003F1AC(s32 arg0) {
    extern u8 gUnitLists[];
    return gUnitLists + arg0 * 0xC;
}

u8 fn_8003F1C0(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 8);
}

s32 fn_8003F1C8(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x190);
}

s32 fn_8003F1D0(s32 *arg0, s32 arg1) {
    return *arg0 & arg1;
}

void fn_8003F1DC(s32 *arg0, s32 arg1) {
    *arg0 |= arg1;
}

void fn_8003F1EC(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x194) = arg1;
}

void fn_8003F1F4(s32 *arg0, s32 arg1) {
    *arg0 &= ~arg1;
}

s32 fn_8003F204(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x194);
}

u8 fn_8003F20C(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x19E);
}

u8 fn_8003F214(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x19F);
}

s32 fn_8003F21C(s32 arg0) {
    return arg0 + 0x1A0;
}

void *fn_8003F224(void *arg0, s32 arg1) {
    u8 ok;
    void *ptr;
    s8 *ref;
    s8 c;
    u32 *var_r7;
    u32 *base;
    u32 *entry;
    void *result;
    u32 count;
    u32 unk4;
    u32 unkC;
    u32 unk10;
    u32 idx8;
    u32 t;
    u32 ctr;

    ref = lbl_80366DC0;
    ptr = arg0;
    c = ((u8 *)ptr)[0x18];
    if ((s8)c != ref[0]) {
        ok = 0;
    } else {
        c = ((u8 *)ptr)[0x19];
        if ((s8)c != ref[1]) {
            ok = 0;
        } else {
            c = ((u8 *)ptr)[0x1A];
            if ((s8)c != ref[2]) {
                ok = 0;
            } else {
                c = ((u8 *)ptr)[0x1B];
                if ((s8)c != ref[3]) {
                    ok = 0;
                } else {
                    c = ((u8 *)ptr)[0x1C];
                    if ((s8)c != ref[4]) {
                        ok = 0;
                    } else {
                        c = ((u8 *)ptr)[0x1D];
                        if ((s8)c != ref[5]) {
                            ok = 0;
                        } else {
                            c = ((u8 *)ptr)[0x1E];
                            if ((s8)c != ref[6]) {
                                ok = 0;
                            } else {
                                ok = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (ok == 0) {
        ptr = (u8 *)ptr - 0x20;
        c = ((u8 *)ptr)[0x18];
        if ((s8)c != ref[0]) {
            ok = 0;
        } else {
            c = ((u8 *)ptr)[0x19];
            if ((s8)c != ref[1]) {
                ok = 0;
            } else {
                c = ((u8 *)ptr)[0x1A];
                if ((s8)c != ref[2]) {
                    ok = 0;
                } else {
                    c = ((u8 *)ptr)[0x1B];
                    if ((s8)c != ref[3]) {
                        ok = 0;
                    } else {
                        c = ((u8 *)ptr)[0x1C];
                        if ((s8)c != ref[4]) {
                            ok = 0;
                        } else {
                            c = ((u8 *)ptr)[0x1D];
                            if ((s8)c != ref[5]) {
                                ok = 0;
                            } else {
                                c = ((u8 *)ptr)[0x1E];
                                if ((s8)c != ref[6]) {
                                    ok = 0;
                                } else {
                                    ok = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (ok == 0) {
            ptr = 0;
        }
    } else {
        goto calc;
    }
calc:
    unk4 = *(u32 *)((u8 *)ptr + 4);
    idx8 = arg1 * 8;
    unkC = *(u32 *)((u8 *)ptr + 0xC);
    unk4 &= ~3u;
    count = *(u32 *)((u8 *)ptr + 8);
    var_r7 = (u32 *)((u8 *)ptr + unk4);
    unk10 = *(u32 *)((u8 *)ptr + 0x10);
    t = count * 4;
    unkC = unkC * 8;
    var_r7 = (u32 *)((u8 *)var_r7 + 0x20);
    base = (u32 *)((u8 *)var_r7 + t);
    t = unk10 * 8;
    entry = (u32 *)((u8 *)base + idx8);
    result = (u8 *)base + unkC + t + entry[1];

    for (ctr = count; ctr != 0; ctr--) {
        if (entry[0] == *var_r7) {
            return result;
        }
        var_r7++;
    }
    return result;
}

void fn_8005C7E8(void *);
void fn_8003F670(void *arg0) {
    s8 *ref;
    void *ptr;
    u8 ok;

    ptr = arg0;
    ref = lbl_80366DC0;
    if ((s8)((u8 *)ptr)[0x18] != ref[0]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x19] != ref[1]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1A] != ref[2]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1B] != ref[3]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1C] != ref[4]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1D] != ref[5]) {
        ok = 0;
    } else if ((s8)((u8 *)ptr)[0x1E] != ref[6]) {
        ok = 0;
    } else {
        ok = 1;
    }
    if (ok) {
    } else {
        ptr = (u8 *)ptr - 0x20;
        if ((s8)((u8 *)ptr)[0x18] != ref[0]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x19] != ref[1]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1A] != ref[2]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1B] != ref[3]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1C] != ref[4]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1D] != ref[5]) {
            ok = 0;
        } else if ((s8)((u8 *)ptr)[0x1E] != ref[6]) {
            ok = 0;
        } else {
            ok = 1;
        }
        if (ok) {
        } else {
            ptr = 0;
        }
    }
    fn_8005C7E8(ptr);
}

void *fn_8003F87C(s32 arg0, u32 arg1) {
    void *fn_8005C82C(s32, u16);
    void fn_8005C5A8(s32);
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

    fn_8005C5A8(self);
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

void fn_8003FCCC(s32 arg0) {
    void fn_8003F87C(s32, s32);
    fn_8003F87C(arg0, 0);
}

int fn_8003FCF0(void *arg0) {
    int i;
    char* ptr;
    s8 *ref;

    ref = lbl_80366DC0;
    ptr = (char*)arg0 + 0x18;
    for (i = 0; i < 7; i++) {
        if (((s8*)ptr)[i] != ref[i]) {
            goto label_1;
        }
    }

    return 1;

label_1:
    ptr = (char*)arg0 - 0x20 + 0x18;
    for (i = 0; i < 7; i++) {
        if (((s8*)ptr)[i] != ref[i]) {
            return 0;
        }
    }

    return 1;
}

#pragma use_lmw_stmw on
void fn_8003FED8(u8 *arg0) {
    void fn_8000D1D0(void *);
    u32 j;
    u8 *obj;
    u32 *p30;
    u8 *p29;
    u32 *p28;
    u32 *scan;
    u32 count;
    void *da;

    obj = arg0;
    j = 0;
    {
        u32 t4 = *(u32 *)(arg0 + 4);
        u32 t8 = *(u32 *)(arg0 + 8);
        u32 tC = *(u32 *)(arg0 + 0xC);
        u32 t10 = *(u32 *)(obj + 0x10);
        p30 = (u32 *)((u8 *)obj + (t4 & ~3u));
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
        for (; count != 0; count--) {
            if (*p28 == *scan) {
                break;
            }
            scan += 1;
        }
        fn_8000D1D0(da);
        p28 += 2;
        j += 1;
    }
    obj[0x1F] = 0;
}
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

void fn_800408A8(void* arg0, void* arg1, s32 arg2) {
    if (arg2 == 0) {
        return;
    }
    
    // Initialize to zero first
    M2C_FIELD(arg0, u8*, 0x196) = 0;
    M2C_FIELD(arg0, u8*, 0x197) = 0;
    M2C_FIELD(arg0, u8*, 0x1A0) = 0;
    M2C_FIELD(arg0, u8*, 0x1A4) = 0;
    M2C_FIELD(arg0, u8*, 0x1A8) = 0;
    M2C_FIELD(arg0, u8*, 0x1A9) = 0;
    M2C_FIELD(arg0, u8*, 0x1B0) = 0;
    M2C_FIELD(arg0, u8*, 0x1B7) = 0;
    M2C_FIELD(arg0, u8*, 0x1B8) = 0;
    M2C_FIELD(arg0, u8*, 0x1B9) = 0;
    M2C_FIELD(arg0, u8*, 0x1BA) = 0;

    if (arg2 & 1) {
        M2C_FIELD(arg0, u8*, 0x196) = 1;
    }
    
    if (arg2 & 2) {
        M2C_FIELD(arg0, u8*, 0x197) = 2;
    }

    if (arg2 & 4) {
        M2C_FIELD(arg0, u8*, 0x1A0) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
    }
    
    if (arg2 & 8) {
        M2C_FIELD(arg0, u8*, 0x1A4) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
    }

    if (arg2 & 0x10) {
        *(u8*)arg1; // Read into temp value, then advance
        arg1 = (u8*)arg1 + 1; 
        M2C_FIELD(arg0, u8*, 0x1A8) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
        M2C_FIELD(arg0, u8*, 0x1A9) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
    }

    if (arg2 & 0x20) {
        M2C_FIELD(arg0, u8*, 0x1B0) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
    }

    if (arg2 & 0x40) {
        M2C_FIELD(arg0, u8*, 0x1B7) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
        M2C_FIELD(arg0, u8*, 0x1B8) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
    }
   
    if (arg2 & 0x80) {
        *(u8*)arg1; // Read first byte
        arg1 = (u8*)arg1 + 1; 
        M2C_FIELD(arg0, u8*, 0x1B9) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
        M2C_FIELD(arg0, u8*, 0x1BA) = *(u8*)arg1;
        arg1 = (u8*)arg1 + 1;
    }
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

void fn_80041514(void *arg0, char *arg1)
{
    s64 OSGetTime(void);
    s32 strlen(char *);
    void strcpy(void *, char *);
    void strcat(void *, void *);
    s32 fn_8005C84C(void *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXCopy(void *, void *);
    void PSMTXIdentity(void *);
    u16 fn_8005C144(void *);
    u32 Res_GetByName(void *);
    void *Hash_Lookup(void *);
    f32 fn_8001B84C(void *);
    s32 fn_8001B8E0(void *);
    void *Bin_ReadU32(void *);
    void *fn_800C42AC(s32);
    void fn_80061824(void *);
    s32 fn_80065EE8(void *);
    s32 fn_8006CE14(void *);
    u8 fn_8005C3C4(void *);
    s32 fn_8006D948(void *);
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
    void fn_800673E4(void *);
    void fn_8006720C(void *);
    void fn_800675C8(s32);
    void *Fog_GetColor(void);
    void fn_80067480(void);
    void fn_80040B78(void *, void *, void *, s8, f32, f32);
    void *fn_80145EBC(void);
    extern u8 lbl_802EFE20[];
    extern u8 lbl_8026A660[];
    extern f32 lbl_80368F18;
    extern f32 lbl_80368F1C;
    extern f32 lbl_80368F10;
    extern f32 lbl_80368F14;
    extern f32 lbl_80368F20;
    extern f32 lbl_80368F24;
    extern f32 lbl_80368F28;
    extern f32 lbl_80368EF4;
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
    void *cursor;
    char *p;
    char *dst;
    char c;
    s32 mode;
    f32 scale;
    s32 i;
    void *entry;
    void *sub;
    void *name;
    void *tmp;
    u8 *bytes;
    s32 b;
    void *light;
    void *fog;
    s32 (*fccc)(void *) = (s32 (*)(void *))fn_8003FCCC;
    void *(*f87c)(void *, s32) = (void *(*)(void *, s32))fn_8003F87C;

    fn_80041254(arg0);
    dst = (char *)arg0 + 0x3C;
    p = arg1 + strlen(arg1) - 1;
    while (p != arg1) {
        c = p[-1];
        p--;
        if ((s8)c == '/' || (s8)c == '\\') {
            p++;
            break;
        }
    }
    for (;;) {
        c = *p;
        if ((s8)c == 0) break;
        if ((s8)c == '/' || (s8)c == '\\') break;
        *dst++ = *p++;
    }
    *dst = 0;

    t0 = OSGetTime();
    mode = ((u8 *)arg0)[0x68];
    if (mode == 0) {
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x161);
        M2C_FIELD(arg0, s32 *, 8) = fn_8005C84C(lbl_802EFE20);
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x169);
        M2C_FIELD(arg0, s32 *, 0xC) = fccc(lbl_802EFE20);
        PSMTXRotRad(sp18, 0x58, lbl_80368F18);
        M2C_FIELD(arg0, f32 *, 0x6C) = lbl_80368F1C;
        PSMTXCopy(sp18, (u8 *)arg0 + 0x70);

        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x122);
        if (fn_8005C144(lbl_802EFE20) != 0x8000) {
            M2C_FIELD(arg0, void **, 0x18) = f87c(lbl_802EFE20, 8);
        }
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x12D);
        if (fn_8005C144(lbl_802EFE20) != 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x1C) = fccc(lbl_802EFE20);
        }
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x13A);
        if (fn_8005C144(lbl_802EFE20) != 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x20) = fccc(lbl_802EFE20);
        }
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x147);
        if (fn_8005C144(lbl_802EFE20) != 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x24) = fccc(lbl_802EFE20);
        }
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x154);
        if (fn_8005C144(lbl_802EFE20) != 0x8000) {
            M2C_FIELD(arg0, s32 *, 0x28) = fccc(lbl_802EFE20);
        }

        scale = lbl_80368F10;
        if (Res_GetByName(lbl_8026A660 + 0x171) != 0) {
            cursor = Hash_Lookup(lbl_8026A660 + 0x171);
            M2C_FIELD(arg0, s16 *, 0) = *(s16 *)cursor;
            cursor = (u8 *)cursor + 2;
            M2C_FIELD(arg0, s16 *, 2) = *(s16 *)cursor;
            cursor = (u8 *)cursor + 2;
            M2C_FIELD(arg0, s16 *, 4) = *(s16 *)cursor;
            cursor = (u8 *)cursor + 2;
            M2C_FIELD(arg0, s16 *, 6) = *(s16 *)cursor;
            cursor = (u8 *)cursor + 2;
            scale = lbl_80368F10 / fn_8001B84C(&cursor);
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
        M2C_FIELD(arg0, void **, 0x10) = fn_800C42AC(M2C_FIELD(arg0, s16 *, 4) * 0xC0);
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
            strcpy(lbl_802EFE20, arg1);
            strcat(lbl_802EFE20, name);
            strcat(lbl_802EFE20, lbl_8026A660 + 0x193);
            M2C_FIELD(sub, s32 *, 0x40) = fn_80065EE8(lbl_802EFE20);
            strcpy(lbl_802EFE20, arg1);
            strcat(lbl_802EFE20, name);
            strcat(lbl_802EFE20, lbl_8026A660 + 0x196);
            M2C_FIELD(sub, s32 *, 0x48) = fn_8006CE14(lbl_802EFE20);
            strcpy(lbl_802EFE20, arg1);
            strcat(lbl_802EFE20, lbl_8026A660 + 0x19A);
            strcat(lbl_802EFE20, lbl_8026A660 + 0x1A2);
            if (fn_8005C3C4(lbl_802EFE20) != 0) {
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
            lbl_80367294 = (u8)-0x1E;
            lbl_80367295 = (u8)-0x1E;
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
            lbl_8036728C = (u8)(((s8)bytes[1] + 1) & ((s32)(-b | b) >> 31));
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
        tmp = fn_80145EBC();
        if (tmp != NULL) {
            lbl_80367AF6 = ((u8 *)tmp)[4];
        } else {
            lbl_80367AF6 = 0;
        }
        lbl_80366E90 = 1;
        fn_8006805C(lbl_80368F10, lbl_80368F14);
    } else if (mode == 1) {
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x1D0);
        M2C_FIELD(arg0, s32 *, 8) = fn_8005C84C(lbl_802EFE20);
        strcpy(lbl_802EFE20, arg1);
        strcat(lbl_802EFE20, lbl_8026A660 + 0x169);
        M2C_FIELD(arg0, s32 *, 0xC) = fccc(lbl_802EFE20);
        PSMTXIdentity(sp18);
        M2C_FIELD(arg0, f32 *, 0x6C) = lbl_80368F20;
        PSMTXCopy(sp18, (u8 *)arg0 + 0x70);
        lbl_80366E90 = 0xF;
        fn_8006805C(lbl_80368F24, lbl_80368F28);
    }

    fn_8005C84C(lbl_8026A660 + 0x112);
    M2C_FIELD(arg0, s32 *, 0x38) = fn_8006D948(lbl_8026A660 + 0x21C);
    M2C_FIELD(arg0, s32 *, 0x2C) = fn_800EE490();
    M2C_FIELD(arg0, s32 *, 0x30) = fn_80123BA8();
    M2C_FIELD(arg0, s32 *, 0x64) |= 0x40000000;
    fn_8012391C(M2C_FIELD(arg0, s32 *, 0x30));
    if (M2C_FIELD(arg0, s32 *, 0x68) == 0) {
        fn_800C1BDC();
        fn_800C1984();
        if ((u8)(gMapBlendMode - 1) >= 1) {
            fn_8014716C(1);
        } else {
            fn_8014716C(0);
        }
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
    tmp = Light_GetChannel(2);
    Light_GetChannel(0);
    fn_800673E4(tmp);
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
    fn_80040B78(arg0, (u8 *)arg0 + 0x3C, &lbl_80367290, (s8)lbl_8036728D, (f32)(s8)lbl_8036728E, lbl_80368EF4);
    (void)t0;
    (void)OSGetTime();
}

#pragma use_lmw_stmw on
void fn_80042558(void *arg0) {
    void fn_8005FEE8(void *, f32);
    void fn_80049B78(void *, s32);
    s32 fn_80046400(void *, void *);
    void fn_80049C30(void *, s32);
    extern u8 gMapObjEventList[];
    extern f32 lbl_80368F2C;
    u32 list[19];
    u8 *start = gMapObjEventList;
    u8 *rec;
    s32 foundCount = 0;
    s8 x;
    s8 y;
    s32 i;
    s32 k;
    u8 *ent;
    u8 *found;
    u32 flags;
    s32 count;

    rec = start;
    while (rec[2] != 0) {
        x = (s8) rec[0];
        y = (s8) rec[1];
        switch (rec[2] - 0x21) {
            case 0:
                found = NULL;
                count = M2C_FIELD(arg0, s16 *, 6);
                for (i = count - 1; i >= 0; i--) {
                    ent = M2C_FIELD(arg0, u8 **, 0x14) + i * 0xB4;
                    flags = M2C_FIELD(M2C_FIELD(ent, u8 **, 0x10), u32 *, 0xBC);
                    if (flags & 0x410) {
                        continue;
                    }
                    if ((flags & 0xA00) != 0xA00) {
                        continue;
                    }
                    if (x < (s8) M2C_FIELD(ent, u8 *, 4)) {
                        continue;
                    }
                    if (x > (s8) M2C_FIELD(ent, u8 *, 6)) {
                        continue;
                    }
                    if (y < (s8) M2C_FIELD(ent, u8 *, 5)) {
                        continue;
                    }
                    if (y > (s8) M2C_FIELD(ent, u8 *, 7)) {
                        continue;
                    }
                    found = ent;
                    break;
                }
                if (found == NULL) {
                    break;
                }
                fn_8005FEE8(found + 0x14, lbl_80368F2C);
                break;
            case 1:
                found = NULL;
                count = M2C_FIELD(arg0, s16 *, 6);
                for (i = count - 1; i >= 0; i--) {
                    ent = M2C_FIELD(arg0, u8 **, 0x14) + i * 0xB4;
                    flags = M2C_FIELD(M2C_FIELD(ent, u8 **, 0x10), u32 *, 0xBC);
                    if ((flags & 0x1000) == 0) {
                        continue;
                    }
                    if (x < (s8) M2C_FIELD(ent, u8 *, 4)) {
                        continue;
                    }
                    if (x > (s8) M2C_FIELD(ent, u8 *, 6)) {
                        continue;
                    }
                    if (y < (s8) M2C_FIELD(ent, u8 *, 5)) {
                        continue;
                    }
                    if (y > (s8) M2C_FIELD(ent, u8 *, 7)) {
                        continue;
                    }
                    found = ent;
                    break;
                }
                if (found == NULL) {
                    break;
                }
                fn_80049B78(found, 0);
                break;
            case 2:
                found = NULL;
                count = M2C_FIELD(arg0, s16 *, 6);
                for (i = count - 1; i >= 0; i--) {
                    ent = M2C_FIELD(arg0, u8 **, 0x14) + i * 0xB4;
                    flags = M2C_FIELD(M2C_FIELD(ent, u8 **, 0x10), u32 *, 0xBC);
                    if ((flags & 0x800) == 0) {
                        continue;
                    }
                    if (x < (s8) M2C_FIELD(ent, u8 *, 4)) {
                        continue;
                    }
                    if (x > (s8) M2C_FIELD(ent, u8 *, 6)) {
                        continue;
                    }
                    if (y < (s8) M2C_FIELD(ent, u8 *, 5)) {
                        continue;
                    }
                    if (y > (s8) M2C_FIELD(ent, u8 *, 7)) {
                        continue;
                    }
                    found = ent;
                    break;
                }
                if (found == NULL) {
                    break;
                }
                fn_80046400(arg0, list);
                break;
            case 3:
                found = NULL;
                count = M2C_FIELD(arg0, s16 *, 6);
                for (i = count - 1; i >= 0; i--) {
                    ent = M2C_FIELD(arg0, u8 **, 0x14) + i * 0xB4;
                    flags = M2C_FIELD(M2C_FIELD(ent, u8 **, 0x10), u32 *, 0xBC);
                    if (flags & 0x410) {
                        continue;
                    }
                    if ((flags & 0x800) == 0) {
                        continue;
                    }
                    if (x < (s8) M2C_FIELD(ent, u8 *, 4)) {
                        continue;
                    }
                    if (x > (s8) M2C_FIELD(ent, u8 *, 6)) {
                        continue;
                    }
                    if (y < (s8) M2C_FIELD(ent, u8 *, 5)) {
                        continue;
                    }
                    if (y > (s8) M2C_FIELD(ent, u8 *, 7)) {
                        continue;
                    }
                    found = ent;
                    break;
                }
                if (found == NULL) {
                    break;
                }
                count = fn_80046400(arg0, list);
                for (k = 0; k < count; k++) {
                    fn_80049C30((void *) list[k], 0);
                }
                break;
            case 4:
                break;
            case 5:
                found = NULL;
                count = M2C_FIELD(arg0, s16 *, 6);
                for (i = count - 1; i >= 0; i--) {
                    ent = M2C_FIELD(arg0, u8 **, 0x14) + i * 0xB4;
                    flags = M2C_FIELD(M2C_FIELD(ent, u8 **, 0x10), u32 *, 0xBC);
                    if (flags & 0x410) {
                        continue;
                    }
                    if ((flags & 0x200) == 0) {
                        continue;
                    }
                    if (x < (s8) M2C_FIELD(ent, u8 *, 4)) {
                        continue;
                    }
                    if (x > (s8) M2C_FIELD(ent, u8 *, 6)) {
                        continue;
                    }
                    if (y < (s8) M2C_FIELD(ent, u8 *, 5)) {
                        continue;
                    }
                    if (y > (s8) M2C_FIELD(ent, u8 *, 7)) {
                        continue;
                    }
                    found = ent;
                    break;
                }
                if (found == NULL) {
                    break;
                }
                fn_8005FEE8(found + 0x14, lbl_80368F2C);
                break;
            case 6:
                found = NULL;
                count = M2C_FIELD(arg0, s16 *, 6);
                for (i = count - 1; i >= 0; i--) {
                    ent = M2C_FIELD(arg0, u8 **, 0x14) + i * 0xB4;
                    flags = M2C_FIELD(M2C_FIELD(ent, u8 **, 0x10), u32 *, 0xBC);
                    if (flags & 0x410) {
                        continue;
                    }
                    if ((flags & 0xA00) != 0xA00) {
                        continue;
                    }
                    if (x < (s8) M2C_FIELD(ent, u8 *, 4)) {
                        continue;
                    }
                    if (x > (s8) M2C_FIELD(ent, u8 *, 6)) {
                        continue;
                    }
                    if (y < (s8) M2C_FIELD(ent, u8 *, 5)) {
                        continue;
                    }
                    if (y > (s8) M2C_FIELD(ent, u8 *, 7)) {
                        continue;
                    }
                    found = ent;
                    break;
                }
                if (found == NULL) {
                    break;
                }
                M2C_FIELD(found, u8 *, 2) |= 1;
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                break;
        }
        rec += 3;
    }
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

void fn_8004327C(void) {
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
    void *self;
    u8 flags;
    f32 f31v, f30v, f29v, f28v;
    f32 t30;
    s32 a, b;
    f32 scale;
    f32 temp_f0;
    s16 h;

    self = arg0;
    fn_80067708(0, 1, fn_80043E88, self);
    if (*(u32 *)((u8 *)self + 0xC) != 0) {
        s32 n;
        u8 *e;
        e = *(u8 **)((u8 *)self + 0x14);
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
        if (n < *(s16 *)((u8 *)self + 6)) {
            goto clear_body;
        }
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
    if (*(u32 *)((u8 *)self + 0xC) != 0 && (*(u32 *)((u8 *)self + 0x64) & 0x80000000) == 0) {
        fn_8006785C(2, fn_800449C8, self);
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
    fn_80067708(2, 3, fn_80043DEC, self);
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
    extern s32 gGameFlags;
    void *temp_r31;

    fn_80068550(M2C_FIELD(arg0, s32 *, 0x54));
    temp_r31 = M2C_FIELD(arg0, void **, 0x58);
    fn_800C4588(M2C_FIELD(temp_r31, void **, 0x114));
    M2C_FIELD(temp_r31, void **, 0x114) = NULL;
    fn_800C4588(temp_r31);
    gGameFlags &= 0xFFFFFFF7;
}

void fn_80043B20(void) {
    extern void *gMap;
    extern void fn_800432D8(void *);

    fn_800432D8(gMap);
}

void fn_80043B44(void* arg0, s32 arg1) {
    if (arg0 == NULL) {
        return;
    }
    
    // Just a basic skeleton to test compilation
}

s32 fn_80043D18(s32 unused, s32 x, s32 y, f32 *out) {
    extern void *lbl_803672A8;
    extern f64 lbl_80368EF8;
    extern f32 lbl_80368F00;
    extern f32 lbl_80368EE4;
    f32 *p;
    f32 hi;
    f32 p2;
    f32 scale;
    f32 half;
    f32 p0;
    f32 fx;
    f32 fy;
    f32 t;
    f32 p3;
    f32 p1;
    f32 zero;
    f32 a;
    f32 b;

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
    f32 *temp_r3;
    f32 temp_f26;
    f32 temp_f27;
    f32 temp_f28;
    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    
    temp_r3 = (f32*)lbl_803672A8;
    temp_f31 = temp_r3[0];
    temp_f30 = temp_r3[1];
    temp_f29 = temp_r3[4];
    temp_f28 = temp_r3[5];
    temp_f27 = temp_r3[2];
    temp_f26 = temp_r3[3];
    
    Camera_Get(temp_r3);
    
    temp_r3[0x38] = temp_f31;
    temp_r3[0x39] = temp_f30;
    
    temp_r3[0x3A] = 0.0f;   // lbl_80368EE4
    temp_r3[0x3B] = 0.0f;   // lbl_80368EE4
    temp_r3[0x3C] = -1.0f;  // lbl_80368F2C 
    temp_r3[0x3D] = 0.0f;   // lbl_80368EE4
    
    temp_r3[0x35] = temp_f31;
    temp_r3[0x36] = temp_f30;
    temp_r3[0x37] = -30.0f; // lbl_80368F4C
    
    fn_80068070(0.0f, 0.0f, temp_f29, temp_f28, -1.0f);
    
    temp_f29 = (f32)((s32)temp_f29); // fctiwz equivalent
    temp_f28 = (f32)((s32)temp_f28); // fctiwz equivalent
    
    fn_800680AC(0, 0, (s32)temp_f29, (s32)temp_f28);
    
    fn_80067C48(0, temp_f27, temp_f26);
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
        for (col = 0; col < *(s16 *)((u8 *)arg0 + 0); ) {
            ia = *idxA;
            idxA += 1;
            ib = *idxB;
            idxB += 1;
            tileA = (u8 *)tblA + ia * 0xC;
            tileB = (u8 *)tblB + ib * 0xC;
            ok = fn_8005B7A4(*(void **)(tileA + 8));
            c = (s8)col;
            col += 1;
            off = c + 0x100D;
            rowPtr[off] = ok;
            t = c + rowSl;
            sh = t << 3;
            q = t << 2;
            v = *(s16 *)tileA;
            q1 = q + 1;
            p = ca + sh;
            *(s16 *)(p + 0x142D4) = v;
            v = *(s16 *)tileB;
            *(s16 *)(p + 0x1C2D8) = v;
            p = ca + (q1 << 1);
            v = *(s16 *)(tileA + 2);
            q1 = q + 2;
            *(s16 *)(p + 0x142D4) = v;
            v = *(s16 *)(tileB + 2);
            *(s16 *)(p + 0x1C2D8) = v;
            p = ca + (q1 << 1);
            v = *(s16 *)(tileA + 4);
            q1 = q + 3;
            *(s16 *)(p + 0x142D4) = v;
            v = *(s16 *)(tileB + 4);
            *(s16 *)(p + 0x1C2D8) = v;
            p = ca + (q1 << 1);
            v = *(s16 *)(tileA + 6);
            *(s16 *)(p + 0x142D4) = v;
            v = *(s16 *)(tileB + 6);
            *(s16 *)(p + 0x1C2D8) = v;
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
                    rowSl = (s8)yy << 6;
                    rowPtr = ca + rowSl;
                    xx = x0;
                    src = idxA + (x0 + yy * *(s16 *)((u8 *)arg0 + 0));
                    for (; xx <= x1; ) {
                        ia = *src;
                        src += 1;
                        tile = (u8 *)tblA + ia * 0xC;
                        ok = fn_8005B7A4(*(void **)(tile + 8));
                        c = (s8)xx;
                        xx += 1;
                        off = c + 0x100D;
                        rowPtr[off] = ok;
                        t = c + rowSl;
                        q = t << 2;
                        sh = t << 3;
                        v = *(s16 *)tile;
                        q1 = q + 1;
                        p = ca + sh;
                        *(s16 *)(p + 0x142D4) = v;
                        *(s16 *)(p + 0x1C2D8) = v;
                        p = ca + (q1 << 1);
                        v = *(s16 *)(tile + 2);
                        q1 = q + 2;
                        *(s16 *)(p + 0x142D4) = v;
                        *(s16 *)(p + 0x1C2D8) = v;
                        p = ca + (q1 << 1);
                        v = *(s16 *)(tile + 4);
                        q1 = q + 3;
                        *(s16 *)(p + 0x142D4) = v;
                        *(s16 *)(p + 0x1C2D8) = v;
                        p = ca + (q1 << 1);
                        v = *(s16 *)(tile + 6);
                        *(s16 *)(p + 0x142D4) = v;
                        *(s16 *)(p + 0x1C2D8) = v;
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
                    rowSl = (s8)yy << 6;
                    rowPtr = ca + rowSl;
                    xx = x0;
                    src = idxA + (x0 + yy * *(s16 *)((u8 *)arg0 + 0));
                    for (; xx <= x1; ) {
                        ia = *src;
                        src += 1;
                        tile = (u8 *)tblA + ia * 0xC;
                        ok = fn_8005B7A4(*(void **)(tile + 8));
                        c = (s8)xx;
                        xx += 1;
                        off = c + 0x100D;
                        rowPtr[off] = ok;
                        t = c + rowSl;
                        sh = t << 3;
                        p = ca + sh;
                        *(s16 *)(p + 0x142D4) = *(s16 *)tile;
                        q = t << 2;
                        q1 = q + 1;
                        p = ca + (q1 << 1);
                        *(s16 *)(p + 0x142D4) = *(s16 *)(tile + 2);
                        q1 = q + 2;
                        p = ca + (q1 << 1);
                        *(s16 *)(p + 0x142D4) = *(s16 *)(tile + 4);
                        q1 = q + 3;
                        p = ca + (q1 << 1);
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
#pragma global_optimizer on

void fn_8004496C(void *arg0, u8 arg1) {
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

void fn_80044BE4(void *arg0) {
    f32 Map_GetTileCornerHeight(void *, s32, s32, s32);
    void *fn_800C45B8(s32, void *, s32);
    void fn_800C4588(void *);
    void *fn_800C4638(s32, void *, s32);
    void DCInvalidateRange(void *, u32);
    void DCFlushRange(void *, u32);
    void *fn_802248D8(void *, u32);
    s32 fn_802249A4(void *);
    void GXBegin(s32, s32, s32);
    void DebugPrint(void *, s32);
    void *memcpy(void *, void *, s32);
    extern u8 lbl_8026A660[];
    extern u8 gBattleMap[];
    extern f32 lbl_80368F58;
    volatile f32 *wgpipe;
    void *buf;
    void *disp;
    u8 *row;
    u8 *cell;
    u8 *above;
    u8 *base;
    s32 margin;
    s32 y;
    s32 x;
    s32 tile;
    f32 dx;
    f32 dy;
    f32 a;
    s32 size;
    void *out;
    s32 do_edge;

    margin = M2C_FIELD(arg0, u8 *, 0x61);
    buf = fn_800C45B8(-0x4000, lbl_8026A660 + 0x245, 0);
    base = (u8 *)buf + (margin << 7);
    row = base;
    y = margin;
    while (y < M2C_FIELD(arg0, s16 *, 2) - margin) {
        x = margin;
        cell = row + margin;
        above = (u8 *)buf + (((y - 1) << 7) + margin);
        while (x < M2C_FIELD(arg0, s16 *, 0) - margin) {
            *cell = 0;
            tile = gBattleMap[((s8)y << 6) + ((s8)x + 0x100D)];
            do_edge = 0;
            if (tile == 0xB) {
            } else if (tile >= 0xB) {
                if (tile >= 0x49) {
                    do_edge = 1;
                } else if (tile < 0x45) {
                    do_edge = 1;
                }
            } else if (tile == 4) {
            } else if (tile >= 4) {
                do_edge = 1;
            } else if (tile == 0) {
            } else {
                do_edge = 1;
            }
            if (do_edge) {
                *cell = 6;
                if (x == margin) {
                    *cell |= 1;
                } else if (cell[-1] == 0) {
                    *cell |= 1;
                } else {
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)y, 1);
                    dx = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0) - a;
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)(x - 1), (s8)y, 3);
                    dy = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 2) - a;
                    if (dy * dy + dx * dx >= lbl_80368F58) {
                        *cell |= 1;
                    }
                }
                if (y == margin) {
                    *cell |= 8;
                } else if (*above == 0) {
                    *cell |= 8;
                } else {
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)(y - 1), 2);
                    dx = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0) - a;
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)(y - 1), 3);
                    dy = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 1) - a;
                    if (dy * dy + dx * dx >= lbl_80368F58) {
                        *cell |= 8;
                    }
                }
            }
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
    wgpipe = (volatile f32 *)0xCC008000;
    row = base;
    y = margin;
    while (y < M2C_FIELD(arg0, s16 *, 2) - margin) {
        x = margin;
        cell = row + margin;
        while (x < M2C_FIELD(arg0, s16 *, 0) - margin) {
            tile = *cell;
            if (tile != 0) {
                if (tile == 0xE) {
                    goto case_e;
                } else if (tile >= 0xE) {
                    if (tile >= 0x10) {
                    } else {
                        goto case_f;
                    }
                } else if (tile == 7) {
                    goto case_7;
                } else if (tile >= 7) {
                } else if (tile >= 6) {
                    GXBegin(0xB0, 0, 3);
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 1);
                    wgpipe[0] = (f32)(x + 1);
                    wgpipe[0] = (f32)y;
                    wgpipe[0] = a;
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 3);
                    wgpipe[0] = (f32)(x + 1);
                    wgpipe[0] = (f32)(y + 1);
                    wgpipe[0] = a;
                    a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 2);
                    wgpipe[0] = (f32)x;
                    wgpipe[0] = (f32)(y + 1);
                    wgpipe[0] = a;
                }
                goto next2;
            case_7:
                GXBegin(0xB0, 0, 4);
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 1);
                wgpipe[0] = (f32)(x + 1);
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 3);
                wgpipe[0] = (f32)(x + 1);
                wgpipe[0] = (f32)(y + 1);
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 2);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)(y + 1);
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
                goto next2;
            case_e:
                GXBegin(0xB0, 0, 4);
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 1);
                wgpipe[0] = (f32)(x + 1);
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 3);
                wgpipe[0] = (f32)(x + 1);
                wgpipe[0] = (f32)(y + 1);
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 2);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)(y + 1);
                wgpipe[0] = a;
                goto next2;
            case_f:
                GXBegin(0xB0, 0, 5);
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 1);
                wgpipe[0] = (f32)(x + 1);
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 3);
                wgpipe[0] = (f32)(x + 1);
                wgpipe[0] = (f32)(y + 1);
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 2);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)(y + 1);
                wgpipe[0] = a;
                a = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0);
                wgpipe[0] = (f32)x;
                wgpipe[0] = (f32)y;
                wgpipe[0] = a;
            }
        next2:
            cell += 1;
            x += 1;
        }
        row += 0x80;
        y += 1;
    }

    out = M2C_FIELD(arg0, void **, 0xA4);
    size = fn_802249A4(disp);
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

void fn_80045604(s32 unused) {
    void *Hash_Lookup(void *);
    u32 Res_GetByName(void *);
    extern u8 lbl_8026A660[];
    extern u8 gBattleMap[];

    typedef struct { u8 pad[0x408E]; u16 flags; } FlagTile;

    s16 *data;
    s16 count;
    s32 n;
    u8 *p;
    s32 i;
    s32 x;
    s32 y;
    u8 v;
    FlagTile *fp;
    u32 pairs;
    u8 *base;

    if (Res_GetByName(lbl_8026A660 + 0x2D3) != 0) {
        data = Hash_Lookup(lbl_8026A660 + 0x2D3);
        count = *data;
        p = (u8 *)data + 2;
        i = 0;
        n = count;
        if (n > 0) {
            for (i = 0; i < n; i++) {
                x = (s8)p[0];
                y = (s8)p[1];
                v = p[2];
                p += 3;
                ((FlagTile *)(gBattleMap + ((x + (y << 6)) * 2)))->flags = v;
            }
        }
    }

    if (Res_GetByName(lbl_8026A660 + 0x2DB) != 0) {
        data = Hash_Lookup(lbl_8026A660 + 0x2DB);
        count = *data;
        p = (u8 *)data + 2;
        base = gBattleMap;
        n = count;
        if (n > 0) {
            pairs = (u32)n >> 1;
            if (pairs != 0) {
                do {
                    x = (s8)p[0];
                    y = (s8)p[1];
                    v = p[2];
                    fp = (FlagTile *)(base + ((x + (y << 6)) * 2));
                    fp->flags = (fp->flags & ~0x0F00) | (v << 8);
                    x = (s8)p[3];
                    y = (s8)p[4];
                    v = p[5];
                    p += 6;
                    fp = (FlagTile *)(base + ((x + (y << 6)) * 2));
                    fp->flags = (fp->flags & ~0x0F00) | (v << 8);
                    pairs -= 1;
                } while (pairs != 0);
                n &= 1;
            }
            if (n != 0) {
                do {
                    x = (s8)p[0];
                    y = (s8)p[1];
                    v = p[2];
                    p += 3;
                    fp = (FlagTile *)(base + ((x + (y << 6)) * 2));
                    fp->flags = (fp->flags & ~0x0F00) | (v << 8);
                    n -= 1;
                } while (n != 0);
            }
        }
    }

    if (Res_GetByName(lbl_8026A660 + 0x2E5) != 0) {
        data = Hash_Lookup(lbl_8026A660 + 0x2E5);
        count = *data;
        p = (u8 *)data + 2;
        i = 0;
        n = count;
        if (n > 0) {
            for (i = 0; i < n; i++) {
                x = (s8)p[0];
                y = (s8)p[1];
                v = p[2];
                p += 3;
                ((FlagTile *)(gBattleMap + ((x + (y << 6)) * 2)))->flags =
                    (u16)(v + (((~v) << 4) & 0xF0));
            }
        }
    }
}

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
    M2C_FIELD(temp_r31, f32 *, 4) = (f32) (lbl_80368EF4 * ((f32) (s8) lbl_8036728D * M2C_FIELD(arg0, f32 *, 0x6C)));
    M2C_FIELD(temp_r31, f32 *, 8) = (f32) (lbl_80368EF4 * ((f32) (s8) lbl_8036728E * M2C_FIELD(arg0, f32 *, 0x6C)));
    M2C_FIELD(temp_r31, u8 *, 1) = (u8) M2C_FIELD(&lbl_80367290, u8 *, 0);
    M2C_FIELD(temp_r31, u8 *, 2) = (u8) M2C_FIELD(&lbl_80367290, u8 *, 1);
    M2C_FIELD(temp_r31, u8 *, 3) = (u8) M2C_FIELD(&lbl_80367290, u8 *, 2);
}

void fn_80045C68(void *arg0)
{
    void fn_80067460(s32);
    void fn_80066F64(void);
    void *Light_GetChannel(s32);
    void fn_800673E4(void *, void *);
    void fn_8006720C(void *);
    extern u8 lbl_80367294;
    extern u8 lbl_80367295;
    extern u8 lbl_8036729C;
    extern u8 lbl_80367298;
    void *light;
    void *self;

    self = arg0;
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
    fn_800673E4(Light_GetChannel(0), light);
    fn_8006720C((u8 *)self + 0x70);
}

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
    void *fn_800C42AC(s32);
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
    *(void **)((u8 *)self + 0x14) = fn_800C42AC(*(s16 *)((u8 *)self + 6) * 0xB4);
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
    t6 = sp8;
    t5 = t6 + 1;
    sp8 = t5;
    t4 = t5 + 1;
    tmp = (s32)(t4 + 1);
    r26v = (u8)t6[0];
    sp8 = t4;
    r29v = (u8)t6[1];
    sp8 = (u8 *)tmp;
    ent[4] = t6[2];
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
        a = *(s16 *)self;
        h = *(s16 *)((u8 *)self + 2);
        a = ((u32)a >> 31) + a;
        a >>= 1;
        f24v -= (f32)a;
        f26v -= (f32)((s32)(((u32)h >> 31) + h) >> 1);
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
    tmp = r29v + 4;
    *(void **)(sub + 4) = (u8 *)*(void **)((u8 *)self + 0x10) + tmp;
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

    r29v = 0;
    r26v = 0;
    sub = (u8 *)r29v;
    i = 0;
    goto loop2_test;
loop2_body:
    base = *(u8 **)((u8 *)self + 0x14);
    ent = base + (s32)sub;
    if (*(u32 *)(*(u8 **)(ent + 0x10) + 0xBC) & 0x400) {
        if (r26v == 0) {
            m = r29v + 1;
            ctr = count - m;
            idx = m * 0xB4;
            if (m < count) {
                for (; ctr != 0; ctr--) {
                    other = base + idx;
                    if (*(void **)(ent + 0x10) != *(void **)(other + 0x10)
                        || (s8)ent[0] != (s8)other[0]
                        || (s8)ent[1] != (s8)other[1]) {
                        break;
                    }
                    r26v += 1;
                    idx += 0xB4;
                    m += 1;
                }
            }
            i = 0;
        }
        if (r26v > 0) {
            u8 *s2 = ent + 0x14;
            ref = fn_80060664(s2);
            tmp = r26v + 1;
            fn_8005FEE8(s2, (f32)((s32)(i * *(s32 *)((u8 *)ref + 0x18)) / tmp));
            i += 1;
            if (i > r26v) {
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
}
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

void fn_80046400(void *arg0, void *arg1, void *arg2) {
    M2C_UNK fn_80046424(void *, void *, void *, M2C_UNK);
    fn_80046424(arg0, arg1, arg2, 0);
}

s32 fn_80046424(void *arg0, void *arg1, void **arg2, s32 arg3) {
    void *Map_FindObjAt(void *, s32, s32, u32, s32);
    void *fn_80049E1C(void *);
    void **p;
    s32 n;
    s32 i;
    s32 mid;
    s32 edge;
    u32 mask;
    u32 flags;
    void *found;
    u8 *entry;
    u8 *base;
    u32 nmask;
    u8 ok;
    s32 count;

    if (arg1 == NULL) {
        return arg3;
    }
    p = arg2;
    n = arg3;
    if (n > 0) {
        do {
            if (*p == arg1) {
                return arg3;
            }
            p++;
        } while (--n != 0);
    }
    arg2[arg3] = arg1;
    mask = *(u32 *)((u8 *)*(void **)((u8 *)arg1 + 0x10) + 0xBC) | 0x200000;
    count = arg3 + 1;

    /* left */
    mid = ((s8)*(u8 *)((u8 *)arg1 + 5) + (s8)*(u8 *)((u8 *)arg1 + 7)) / 2;
    edge = (s8)*(u8 *)((u8 *)arg1 + 4) - 1;
    found = NULL;
    for (i = *(s16 *)((u8 *)arg0 + 6) - 1; i >= 0; i--) {
        base = *(u8 **)((u8 *)arg0 + 0x14);
        entry = base + i * 0xB4;
        flags = *(u32 *)((u8 *)*(void **)(entry + 0x10) + 0xBC);
        if (!(flags & 0x10)) {
            if (mask == 0 || mask == (mask & flags)) {
                if (edge >= (s8)*(u8 *)(entry + 4) && edge <= (s8)*(u8 *)(entry + 6) &&
                    mid >= (s8)*(u8 *)(entry + 5) && mid <= (s8)*(u8 *)(entry + 7)) {
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok != 0) {
                    found = base + i * 0xB4;
                    break;
                }
            }
        }
    }
    if (found != NULL) {
        p = arg2;
        n = count;
        if (n > 0) {
            do {
                if (*p == found) {
                    goto right;
                }
                p++;
            } while (--n != 0);
        }
        arg2[count] = found;
        n = count + 1;
        nmask = *(u32 *)((u8 *)fn_80049E1C(found) + 0xBC) | 0x200000;
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 4) - 1, mid, nmask, 0x10), arg2, n);
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 6) + 1, mid, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 5) - 1, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 7) + 1, nmask, 0x10), arg2, count);
    }
right:
    mid = ((s8)*(u8 *)((u8 *)arg1 + 5) + (s8)*(u8 *)((u8 *)arg1 + 7)) / 2;
    edge = (s8)*(u8 *)((u8 *)arg1 + 6) + 1;
    found = NULL;
    for (i = *(s16 *)((u8 *)arg0 + 6) - 1; i >= 0; i--) {
        base = *(u8 **)((u8 *)arg0 + 0x14);
        entry = base + i * 0xB4;
        flags = *(u32 *)((u8 *)*(void **)(entry + 0x10) + 0xBC);
        if (!(flags & 0x10)) {
            if (mask == 0 || mask == (mask & flags)) {
                if (edge >= (s8)*(u8 *)(entry + 4) && edge <= (s8)*(u8 *)(entry + 6) &&
                    mid >= (s8)*(u8 *)(entry + 5) && mid <= (s8)*(u8 *)(entry + 7)) {
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok != 0) {
                    found = base + i * 0xB4;
                    break;
                }
            }
        }
    }
    if (found != NULL) {
        p = arg2;
        n = count;
        if (n > 0) {
            do {
                if (*p == found) {
                    goto up;
                }
                p++;
            } while (--n != 0);
        }
        arg2[count] = found;
        n = count + 1;
        nmask = *(u32 *)((u8 *)fn_80049E1C(found) + 0xBC) | 0x200000;
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 4) - 1, mid, nmask, 0x10), arg2, n);
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 6) + 1, mid, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 5) - 1, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 7) + 1, nmask, 0x10), arg2, count);
    }
up:
    mid = ((s8)*(u8 *)((u8 *)arg1 + 4) + (s8)*(u8 *)((u8 *)arg1 + 6)) / 2;
    edge = (s8)*(u8 *)((u8 *)arg1 + 5) - 1;
    found = NULL;
    for (i = *(s16 *)((u8 *)arg0 + 6) - 1; i >= 0; i--) {
        base = *(u8 **)((u8 *)arg0 + 0x14);
        entry = base + i * 0xB4;
        flags = *(u32 *)((u8 *)*(void **)(entry + 0x10) + 0xBC);
        if (!(flags & 0x10)) {
            if (mask == 0 || mask == (mask & flags)) {
                if (mid >= (s8)*(u8 *)(entry + 4) && mid <= (s8)*(u8 *)(entry + 6) &&
                    edge >= (s8)*(u8 *)(entry + 5) && edge <= (s8)*(u8 *)(entry + 7)) {
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok != 0) {
                    found = base + i * 0xB4;
                    break;
                }
            }
        }
    }
    if (found != NULL) {
        p = arg2;
        n = count;
        if (n > 0) {
            do {
                if (*p == found) {
                    goto down;
                }
                p++;
            } while (--n != 0);
        }
        arg2[count] = found;
        n = count + 1;
        nmask = *(u32 *)((u8 *)fn_80049E1C(found) + 0xBC) | 0x200000;
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 4) - 1, mid, nmask, 0x10), arg2, n);
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 6) + 1, mid, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 5) - 1, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 7) + 1, nmask, 0x10), arg2, count);
    }
down:
    mid = ((s8)*(u8 *)((u8 *)arg1 + 4) + (s8)*(u8 *)((u8 *)arg1 + 6)) / 2;
    edge = (s8)*(u8 *)((u8 *)arg1 + 7) + 1;
    found = NULL;
    for (i = *(s16 *)((u8 *)arg0 + 6) - 1; i >= 0; i--) {
        base = *(u8 **)((u8 *)arg0 + 0x14);
        entry = base + i * 0xB4;
        flags = *(u32 *)((u8 *)*(void **)(entry + 0x10) + 0xBC);
        if (!(flags & 0x10)) {
            if (mask == 0 || mask == (mask & flags)) {
                if (mid >= (s8)*(u8 *)(entry + 4) && mid <= (s8)*(u8 *)(entry + 6) &&
                    edge >= (s8)*(u8 *)(entry + 5) && edge <= (s8)*(u8 *)(entry + 7)) {
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok != 0) {
                    found = base + i * 0xB4;
                    break;
                }
            }
        }
    }
    if (found != NULL) {
        p = arg2;
        n = count;
        if (n > 0) {
            do {
                if (*p == found) {
                    goto done;
                }
                p++;
            } while (--n != 0);
        }
        arg2[count] = found;
        n = count + 1;
        nmask = *(u32 *)((u8 *)fn_80049E1C(found) + 0xBC) | 0x200000;
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 4) - 1, mid, nmask, 0x10), arg2, n);
        mid = ((s8)*(u8 *)((u8 *)found + 5) + (s8)*(u8 *)((u8 *)found + 7)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, (s8)*(u8 *)((u8 *)found + 6) + 1, mid, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 5) - 1, nmask, 0x10), arg2, count);
        mid = ((s8)*(u8 *)((u8 *)found + 4) + (s8)*(u8 *)((u8 *)found + 6)) / 2;
        count = fn_80046424(arg0, Map_FindObjAt(arg0, mid, (s8)*(u8 *)((u8 *)found + 7) + 1, nmask, 0x10), arg2, count);
    }
done:
    return count;
}

void *fn_80046EB8(void *arg0, void *arg1) {
    s32 n;
    s32 i;
    s32 off;
    u8 *base;

    if (arg1 == 0) {
        return 0;
    }

    n = *(s16 *)((u8 *)arg0 + 6) - 1;
    i = n + 1;
    off = n * 0xB4;
    for (; i != 0; i--) {
        base = *(u8 **)((u8 *)arg0 + 0x14);
        if (arg1 == *(void **)(base + off + 0x10)) {
            return base + n * 0xB4;
        }
        off -= 0xB4;
        n -= 1;
    }

    return 0;
}

s32 fn_80046F14(void *arg0, s32 arg1) {
    void **temp_r7;
    s32 var_r9;
    void *temp_r5;
    s32 *temp_r3;

    temp_r7 = (void **)((char *)arg0 + 0x188);
    if (*(void **)temp_r7 == NULL) {
        return 0;
    }
    temp_r5 = (char *)temp_r7 + 0x50;
    if (*(void **)temp_r5 == NULL) {
        return 0;
    }

    temp_r3 = (s32 *)((char *)arg0 + 0x210);
    var_r9 = *(s32 *)((char *)temp_r5 + arg1 * 8);
    if (var_r9 >= 0) {
        if ((u32)(var_r9 - *(s32 *)temp_r3) > 0U) {
            return 0;
        }
    } else {
        s32 temp = *(s32 *)((char *)arg0 + arg1 * 8 + 0x24C);
        if (temp >= 0) {
            if ((u32)(temp - *(s32 *)temp_r3) > 0U) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

s32 fn_80047178(void *arg0, s32 arg1, s32 arg2)
{
  s32 i;
  u8 *entry;
  s32 base;
  s32 count;
  u8 ok;
  count = *((s16 *) (((u8 *) arg0) + 0x6));
  for (i = count - 1; i >= 0; i--)
  {
    base = *((s32 *) (((u8 *) arg0) + 0x14));
    entry = ((u8 *) base) + (i * 0xB4);
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
    extern f32 lbl_80368F64;
    extern f32 lbl_80368F68;
    struct Work {
        f32 quat[4];
        f32 corners[8][3];
    } wk;
    u8 bufF8[0x30];
    u8 bufC8[0x30];
    u8 buf98[0x30];
    u8 buf68[0x30];
    u8 buf38[0x30];
    u8 buf8[0x30];
    s32 i;
    u8 *entry = M2C_FIELD(arg0, u8 **, 0x14) + arg1 * 0xB4;
    u8 *sub;
    f32 *c7 = &wk.corners[7][0];
    f32 *c6 = &wk.corners[6][0];
    f32 *c5 = &wk.corners[5][0];
    f32 *c4 = &wk.corners[4][0];
    f32 *c3 = &wk.corners[3][0];
    f32 *c2 = &wk.corners[2][0];
    f32 *c1 = &wk.corners[1][0];
    u8 *e;
    u32 mask = 0x1040;
    f32 minX;
    f32 minY;
    f32 maxX;
    f32 maxY;
    f32 x;
    f32 y;
    f32 *p;
    s32 j;
    u8 hit;

    for (i = arg1; i < arg2; i++, entry += 0xB4) {
        e = entry + 0x14;
        fn_80060638(e);
        sub = M2C_FIELD(entry, u8 **, 0x10);
        M2C_FIELD(entry, u8 *, 2) &= 0x7F;
        if (M2C_FIELD(sub, u32 *, 0xBC) & mask) {
            continue;
        }
        fn_8006049C(e);
        switch (M2C_FIELD(e, u32 *, 0xC)) {
            case 0:
                break;
            case 1:
                PSMTXRotRad(buf68, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                PSMTXRotRad(buf98, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                PSMTXRotRad(bufC8, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                break;
            case 2:
                PSMTXRotRad(buf68, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                PSMTXRotRad(buf98, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                PSMTXRotRad(bufC8, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                break;
            case 3:
                PSMTXRotRad(buf68, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                PSMTXRotRad(buf98, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                PSMTXRotRad(bufC8, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                break;
            case 4:
                PSMTXRotRad(buf68, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                PSMTXRotRad(buf98, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                PSMTXRotRad(bufC8, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                break;
            case 5:
                PSMTXRotRad(buf68, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                PSMTXRotRad(buf98, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                PSMTXRotRad(bufC8, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                break;
            case 6:
                PSMTXRotRad(buf68, 0x5A, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x24));
                PSMTXRotRad(buf98, 0x59, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x20));
                PSMTXRotRad(bufC8, 0x58, lbl_80368EEC * M2C_FIELD(e, f32 *, 0x1C));
                break;
            case 7:
                PSMTXCopy(e + 0x10, bufF8);
                goto checks;
            case 8:
                PSMTXScale(buf8, M2C_FIELD(e, f32 *, 0x28), M2C_FIELD(e, f32 *, 0x2C), M2C_FIELD(e, f32 *, 0x30));
                PSMTXTrans(buf38, M2C_FIELD(e, f32 *, 0x10), M2C_FIELD(e, f32 *, 0x14), M2C_FIELD(e, f32 *, 0x18));
                QUATMtx(e + 0x10, buf68);
                PSMTXConcat(buf68, buf8, bufF8);
                PSMTXConcat(buf68, bufF8, bufF8);
                PSMTXConcat(buf38, bufF8, bufF8);
                goto checks;
            default:
                goto checks;
        }
        Game_Assert(lbl_8026A660 + 0x2F7, 0xB8, lbl_8026A660 + 0x2FF);
        PSMTXScale(buf8, M2C_FIELD(e, f32 *, 0x28), M2C_FIELD(e, f32 *, 0x2C), M2C_FIELD(e, f32 *, 0x30));
        PSMTXTrans(buf38, M2C_FIELD(e, f32 *, 0x10), M2C_FIELD(e, f32 *, 0x14), M2C_FIELD(e, f32 *, 0x18));
        PSMTXConcat(buf68, buf8, bufF8);
        PSMTXConcat(buf98, bufF8, bufF8);
        PSMTXConcat(bufC8, bufF8, bufF8);
        PSMTXConcat(buf38, bufF8, bufF8);
        wk.quat[0] = lbl_80368EE4;
        wk.quat[1] = lbl_80368EE4;
        wk.quat[2] = lbl_80368EE4;
        wk.quat[3] = lbl_80368F10;
        fn_80202C18(fn_80067FD0(), bufF8, bufF8);
checks:
        wk.corners[0][0] = M2C_FIELD(sub, f32 *, 0xA4);
        wk.corners[0][1] = M2C_FIELD(sub, f32 *, 0xA8);
        wk.corners[0][2] = M2C_FIELD(sub, f32 *, 0xAC);
        fn_8020310C(bufF8, &wk.corners[0][0], &wk.corners[0][0]);
        hit = !(wk.corners[0][0] * wk.corners[0][0] < lbl_80368F5C && wk.corners[0][1] * wk.corners[0][1] < lbl_80368F60 &&
                wk.corners[0][2] > lbl_80368F2C && wk.corners[0][2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c1[0] = M2C_FIELD(sub, f32 *, 0xB0);
        c1[1] = M2C_FIELD(sub, f32 *, 0xA8);
        c1[2] = M2C_FIELD(sub, f32 *, 0xAC);
        fn_8020310C(bufF8, c1, c1);
        hit = !(c1[0] * c1[0] < lbl_80368F5C && c1[1] * c1[1] < lbl_80368F60 &&
                c1[2] > lbl_80368F2C && c1[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c2[0] = M2C_FIELD(sub, f32 *, 0xB0);
        c2[1] = M2C_FIELD(sub, f32 *, 0xB4);
        c2[2] = M2C_FIELD(sub, f32 *, 0xAC);
        fn_8020310C(bufF8, c2, c2);
        hit = !(c2[0] * c2[0] < lbl_80368F5C && c2[1] * c2[1] < lbl_80368F60 &&
                c2[2] > lbl_80368F2C && c2[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c3[0] = M2C_FIELD(sub, f32 *, 0xA4);
        c3[1] = M2C_FIELD(sub, f32 *, 0xB4);
        c3[2] = M2C_FIELD(sub, f32 *, 0xAC);
        fn_8020310C(bufF8, c3, c3);
        hit = !(c3[0] * c3[0] < lbl_80368F5C && c3[1] * c3[1] < lbl_80368F60 &&
                c3[2] > lbl_80368F2C && c3[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c4[0] = M2C_FIELD(sub, f32 *, 0xA4);
        c4[1] = M2C_FIELD(sub, f32 *, 0xA8);
        c4[2] = M2C_FIELD(sub, f32 *, 0xB8);
        fn_8020310C(bufF8, c4, c4);
        hit = !(c4[0] * c4[0] < lbl_80368F5C && c4[1] * c4[1] < lbl_80368F60 &&
                c4[2] > lbl_80368F2C && c4[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c5[0] = M2C_FIELD(sub, f32 *, 0xB0);
        c5[1] = M2C_FIELD(sub, f32 *, 0xA8);
        c5[2] = M2C_FIELD(sub, f32 *, 0xB8);
        fn_8020310C(bufF8, c5, c5);
        hit = !(c5[0] * c5[0] < lbl_80368F5C && c5[1] * c5[1] < lbl_80368F60 &&
                c5[2] > lbl_80368F2C && c5[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c6[0] = M2C_FIELD(sub, f32 *, 0xB0);
        c6[1] = M2C_FIELD(sub, f32 *, 0xB4);
        c6[2] = M2C_FIELD(sub, f32 *, 0xB8);
        fn_8020310C(bufF8, c6, c6);
        hit = !(c6[0] * c6[0] < lbl_80368F5C && c6[1] * c6[1] < lbl_80368F60 &&
                c6[2] > lbl_80368F2C && c6[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        c7[0] = M2C_FIELD(sub, f32 *, 0xA4);
        c7[1] = M2C_FIELD(sub, f32 *, 0xB4);
        c7[2] = M2C_FIELD(sub, f32 *, 0xB8);
        fn_8020310C(bufF8, c7, c7);
        hit = !(c7[0] * c7[0] < lbl_80368F5C && c7[1] * c7[1] < lbl_80368F60 &&
                c7[2] > lbl_80368F2C && c7[2] < lbl_80368EE4);
        if (hit == 0) {
            continue;
        }
        if (!(M2C_FIELD(sub, u32 *, 0xBC) & 8)) {
            continue;
        }
        minX = lbl_80368F64;
        minY = minX;
        maxX = lbl_80368F68;
        maxY = maxX;
        p = &wk.corners[0][0];
        for (j = 0; j < 4; j++, p += 2) {
            x = p[0];
            y = p[1];
            if (p[2] > lbl_80368EE4) {
                x *= lbl_80368F2C;
                y *= lbl_80368F2C;
            }
            if (minX > x) {
                minX = x;
            }
            if (minY > y) {
                minY = y;
            }
            if (maxX < x) {
                maxX = x;
            }
            if (maxY < y) {
                maxY = y;
            }
            x = p[3];
            y = p[4];
            if (p[5] > lbl_80368EE4) {
                x *= lbl_80368F2C;
                y *= lbl_80368F2C;
            }
            if (minX > x) {
                minX = x;
            }
            if (minY > y) {
                minY = y;
            }
            if (maxX < x) {
                maxX = x;
            }
            if (maxY < y) {
                maxY = y;
            }
        }
        if (minX >= lbl_80368F2C) {
            goto res2;
        }
        if (maxX <= lbl_80368F10) {
            goto res2;
        }
        if (minY >= lbl_80368F2C) {
            goto res2;
        }
        if (maxY > lbl_80368F10) {
            continue;
        }
        if (minX * minX < lbl_80368F10 && minY * minY < lbl_80368F10) {
            continue;
        }
        if (maxX * maxX < lbl_80368F10 && minY * minY < lbl_80368F10) {
            continue;
        }
        if (maxX * maxX < lbl_80368F10 && maxY * maxY < lbl_80368F10) {
            continue;
        }
        if (minX * minX < lbl_80368F10 && maxY * maxY < lbl_80368F10) {
            continue;
        }
res2:
        if (minX < lbl_80368F2C && maxX > lbl_80368F10 && minY * minY < lbl_80368F10 && maxY * maxY < lbl_80368F10) {
            continue;
        }
        if (minY >= lbl_80368F2C) {
            continue;
        }
        if (maxY <= lbl_80368F10) {
            continue;
        }
        if (minX * minX < lbl_80368F10) {
            continue;
        }
        if (maxX * maxX < lbl_80368F10) {
            continue;
        }
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
#pragma use_lmw_stmw reset

#pragma opt_peephole reset
#pragma opt_loop_invariants reset
#pragma use_lmw_stmw reset
void fn_80048A3C(s8 arg0, s8 arg1, s8 arg2, u8 *arg3) {
    extern s8 lbl_8036728C;
    extern s8 lbl_8036728D;
    extern s8 lbl_8036728E;
    extern u8 lbl_80367290[];
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u8 *p;

    a = arg3[0];
    b = arg3[1];
    c = arg3[2];
    d = arg3[3];
    p = lbl_80367290;
    lbl_8036728C = arg0;
    lbl_8036728D = arg1;
    lbl_8036728E = arg2;
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

void fn_80048C5C(void *arg0, s32 arg1, s32 arg2) {
    u8 *temp_r4;
    s32 *temp_r5;
    
    if ((u32)(arg2 - 8) <= (u32)0x7) {
        temp_r5 = (s32 *)arg0;
        arg2 = arg2 << 1;
        arg2 = (arg1 & 0xFFFF) | (arg2 << 0x10);
        *temp_r5 = arg2;
        *(temp_r5 + 4) = arg2 >> 0x10;
    } else {
        temp_r5 = (s32 *)arg0;
        temp_r4 = (u8 *)arg0 + 8;
        *temp_r5 = arg1;
        *(u32 *)temp_r4 = arg2;
        *((s32 *)temp_r4 + 1) = arg2 >> 0x10;
    }
}

void fn_80048E08(s32 arg0, u32 arg1, void *arg2, s32 arg3) {
    void *Process_CreateChild(void *);
    void *Process_Create(void *, s32);
    void Model_SetColor(s32, u8, u8, u8);
    void Model_SetAlpha(s32, u8);
    extern u8 lbl_80285738[];
    s32 sp8;
    u8 b;
    void *var_r3;
    u8 a;
    s32 temp_r31;

    if (arg3 == 0) {
        temp_r31 = arg0 + 0x14;
        sp8 = *(s32 *)arg2;
        Model_SetColor(temp_r31, ((u8 *)&sp8)[0], ((u8 *)&sp8)[1], ((u8 *)&sp8)[2]);
        Model_SetAlpha(temp_r31, ((u8 *)&sp8)[3]);
        return;
    }
    if (arg1 != 0U) {
        var_r3 = Process_CreateChild(lbl_80285738);
    } else {
        var_r3 = Process_Create(lbl_80285738, 3);
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

s32 fn_80049594(s32 arg0, s32 arg1, s32 arg2)
{
    if (arg0 < 0 || arg1 < 0 || arg2 < 0) {
        return -1;
    }

    if ((u32)(arg0 + 0x40) > 0xFFFF || (u32)(arg1 + 0x40) > 0xFFFF || (u32)(arg2 + 0x40) > 0xFFFF) {
        return -1;
    }

    return 0;
}

void fn_8004982C(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x48);
}

void fn_8004983C(void *arg0) {
    extern f32 lbl_80368F74;
    extern f32 lbl_80368F78;
    struct Obj {
        u8 pad[0x30];
        f32 *ptr;
        u8 pad2[4];
        f32 unk38;
        u8 pad3[4];
        s32 flag;
        f32 a;
        f32 b;
    };
    struct Obj *obj = (struct Obj *)arg0;
    f32 diff;

    obj->flag = 0;
    obj->a = obj->ptr[2];
    obj->b = obj->unk38;
    diff = (f32)__fabs((f64)(obj->a - obj->b));
    if (diff > lbl_80368F74) {
        if (obj->a < obj->b) {
            obj->a = obj->a + lbl_80368F78;
            return;
        }
        if (obj->a > obj->b) {
            obj->b = obj->b + lbl_80368F78;
        }
    }
}

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

void fn_80049B1C(void *arg0, u8 arg1)
{
    void fn_8005FEE8(void *, f32);
    void fn_80044450(void *, s32);
    void fn_80016180(void);

    extern f32 lbl_80368EE4;
    extern u32 gMap;

    u8 *ptr;
    u8 flags;

    ptr = (u8 *)arg0;

    flags = ptr[2];
    flags &= ~2;
    ptr[2] = flags;

    fn_8005FEE8(ptr + 0x14, lbl_80368EE4);

    if (arg1 != 0) {
        fn_80044450((void *)gMap, 1);
    }

    fn_80016180();
}

void fn_80049B78(void *arg0, u8 arg1) {
    void fn_8005FEE8(void *, f32);
    void fn_80044450(s32, s32);
    void fn_80016180(void);
    extern f32 lbl_80368F2C;
    extern u16 *gMap;
    u8 temp;

    temp = *(u8 *)((u8 *)arg0 + 2);
    temp |= 2;
    *(u8 *)((u8 *)arg0 + 2) = temp;

    fn_8005FEE8((u8 *)arg0 + 0x14, -1.0f);

    if (arg1 != 0) {
        fn_80044450((s32)gMap, 1);
        fn_80016180();
    }
}

extern u16* gMap;
void fn_80049BD4(void *arg0, u8 arg1) {
    void Model_SetAlpha(void *, s32, void *);
    void fn_80044450(s32, s32);
    void fn_80016180(void);
    extern u16 *gMap;
    u8 temp;

    temp = *(u8 *)((u8 *)arg0 + 2);
    temp &= 0xFC;
    *(u8 *)((u8 *)arg0 + 2) = temp;

    Model_SetAlpha((u8 *)arg0 + 0x14, 0xFF, arg0);

    if (arg1 != 0) {
        fn_80044450((s32)gMap, 1);
        fn_80016180();
    }
}

void fn_80049C30(void *arg0, u8 arg1)
{
    void Model_SetAlpha(void *, s32, void *);
    void fn_80044450(s32, s32);
    void fn_80016180(void);
    extern u16 *gMap;
    u8 temp;

    temp = *(u8 *)((u8 *)arg0 + 2);
    temp |= 3;
    *(u8 *)((u8 *)arg0 + 2) = temp;

    Model_SetAlpha((u8 *)arg0 + 0x14, 0, arg0);

    if (arg1 != 0) {
        fn_80044450((s32)gMap, 1);
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

#pragma peephole off
void fn_80049D08(void *arg0) {
    extern f32 lbl_80368F2C;
    void fn_8005FEE8(void *, f32);
    fn_8005FEE8((char *)arg0 + 0x14, lbl_80368F2C);
}
#pragma peephole on
void fn_80049D30(s32 arg0) {
    extern f32 lbl_80368EE4;
    s32 temp_r3 = arg0 + 0x14;
    void *temp_r0 = (void *)arg0;
    fn_8005FEE8(temp_r3, lbl_80368EE4);
}

s32 fn_80049D58(void *arg0) {
    return (M2C_FIELD(arg0, u8 *, 2) & 3) == 0;
}

s32 fn_80049D6C(void *arg0) {
    return (M2C_FIELD(arg0, u8 *, 2) & 3) != 0;
}

#pragma optimization_level 1
s32 fn_80049D84(s32 arg0) {
    arg0 = *(s32 *)(arg0 + 0x10);
    arg0 = *(s32 *)(arg0 + 0xBC);
    if ((arg0 & 0x400) == 0) {
        return (arg0 >> 9) & 1;
    }
    return 0;
}
#pragma optimization_level reset
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
    void *fn_80067FDC(void);
    void PSMTXConcat(void *, void *, void *);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void fn_802245D8(s32, s32, s32, s32);
    void fn_80223D94(s32, s32, s32);
    void fn_80223DDC(s32, s32, s32, s32, s32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void fn_80222C50(void *, s32);
    void GXBegin(s32, s32, s32);
    f32 Map_GetTileCornerHeight(void *, s8, s8, s32);
    void fn_80066D00(s32);
    extern s32 gUiInputFlags;
    extern u32 lbl_80368F80;
    extern f32 lbl_80368F84;
    extern f32 lbl_80368F88;
    extern f32 lbl_80368F8C;
    extern f64 lbl_80368F90;
    extern s32 lbl_803674F0;
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
        PSMTXTrans(mtx, lbl_80368F84, lbl_80368F84, lbl_80368F88);
        PSMTXConcat(fn_80067FDC(), mtx, mtx);
        GXLoadPosMtxImm(mtx, 0);
        GXSetCurrentMtx(0);
        fn_802245D8(1, 4, 5, 0);
        fn_80223D94(0, 0, 3);
        fn_80223DDC(3, 0, 1, 2, 0);
        texId = lbl_803674F0;
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
        fn_80223D94(0, 0, 0);
        fn_80223DDC(3, 0, 1, 2, 3);
        fn_80066D00(-1);
    }
}
#pragma global_optimizer reset

void fn_8004A1F0(void) {
    extern u8 lbl_80285858[];
    extern u32 gUiInputFlags;
    void Process_UnlinkByKey(void *);
    Process_UnlinkByKey(lbl_80285858);
    gUiInputFlags &= ~0x400u;
}

void fn_8004A224(void) {
    void *Process_Create(void *, s32);
    extern u8 lbl_80285858[];
    extern u32 gUiInputFlags;
    void *p;

    p = Process_Create(lbl_80285858, 4);
    *(s32 *)((u8 *)p + 0x30) = 0;
    gUiInputFlags |= 0x400;
}

void fn_8004A264(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void fn_8006785C(s32, void *, void *);
    void fn_8004A2EC(void *);
    extern f32 lbl_80368F84;
    extern f32 lbl_80368F8C;
    extern f32 lbl_80368F98;
    s32 temp_r0;

    *(s32 *)((u8 *)arg0 + 0x30) = *(s32 *)((u8 *)arg0 + 0x30) + 1;
    temp_r0 = *(s32 *)((u8 *)arg0 + 0x30);
    if (temp_r0 <= 8) {
        *(f32 *)((u8 *)arg0 + 0x34) = Math_Ease(6, lbl_80368F84, lbl_80368F8C, (f32)temp_r0, lbl_80368F98);
    }
    fn_8006785C(2, fn_8004A2EC, arg0);
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
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
void *fn_80067FDC(void);
void PSMTXConcat(void *, void *, void *);
void GXLoadPosMtxImm(void *, s32);
void GXSetCurrentMtx(s32);
void fn_802245D8(s32, s32, s32, s32);
void GXBegin(s32, s32, s32);
f32 Map_GetTileCornerHeight(void *, s8, s8, s32);
void fn_80066D00(s32);
extern f32 lbl_80368F84;
extern f32 lbl_80368F88;
extern f32 lbl_80368F8C;
extern f64 lbl_80368F90;
extern u8 gBattleMap[];
extern u8 lbl_80285828[];
    f32 sp8[12];
    u8 *ca;
    u8 *row;
    s32 yOff;
    s32 y1;
    s32 idx;
    u8 *cell;
    u8 *pal;
    void *self;
    s8 x;
    s8 y;
    f32 k8c;
    f64 k90;
    f32 f31v;
    f32 margin;
    f32 f25v, f26v, f27v, f28v;
    f32 z;
    s32 th;

    self = arg0;
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
        PSMTXTrans(sp8, lbl_80368F84, lbl_80368F84, lbl_80368F88);
        PSMTXConcat(fn_80067FDC(), sp8, sp8);
        GXLoadPosMtxImm(sp8, 0);
        GXSetCurrentMtx(0);
        fn_802245D8(1, 4, 1, 0);
        ca = gBattleMap;
        k8c = lbl_80368F8C;
        pal = lbl_80285828;
        k90 = lbl_80368F90;
        y = *(s32 *)(ca + 4) - 1;
        yOff = y << 6;
        row = ca + yOff;
        goto y_test;
        do {
            y1 = (s8)y + 1;
            x = *(s32 *)ca - 1;
            idx = x + yOff;
            cell = row + x;
            f31v = k8c + (f32)(s8)y;
            goto x_test;
            do {
                if ((s8)*(cell + 0xE18E) == 0) {
                    th = *(s16 *)(gBattleMap + (idx << 1) + 0x610E);
                    if (th >= 0) {
                        margin = *(f32 *)((u8 *)self + 0x34);
                        f26v = f31v - margin;
                        f25v = (f32)x;
                        f27v = f25v + margin;
                        f28v = (f32)y1;
                        GXBegin(0x98, 0, 4);
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 0);
                        *(f32 *)0xCC008000 = f25v;
                        *(f32 *)0xCC008000 = f26v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x10];
                        *(u8 *)0xCC008000 = pal[0x11];
                        *(u8 *)0xCC008000 = pal[0x12];
                        *(u8 *)0xCC008000 = pal[0x13];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 1);
                        *(f32 *)0xCC008000 = f27v;
                        *(f32 *)0xCC008000 = f26v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x14];
                        *(u8 *)0xCC008000 = pal[0x15];
                        *(u8 *)0xCC008000 = pal[0x16];
                        *(u8 *)0xCC008000 = pal[0x17];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 2);
                        *(f32 *)0xCC008000 = f25v;
                        *(f32 *)0xCC008000 = f28v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x18];
                        *(u8 *)0xCC008000 = pal[0x19];
                        *(u8 *)0xCC008000 = pal[0x1A];
                        *(u8 *)0xCC008000 = pal[0x1B];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 3);
                        *(f32 *)0xCC008000 = f27v;
                        *(f32 *)0xCC008000 = f28v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x1C];
                        *(u8 *)0xCC008000 = pal[0x1D];
                        *(u8 *)0xCC008000 = pal[0x1E];
                        *(u8 *)0xCC008000 = pal[0x1F];
                    } else if (*(u16 *)(gBattleMap + (idx << 1) + 0xC18E) != 0) {
                        margin = *(f32 *)((u8 *)self + 0x34);
                        f27v = f31v - margin;
                        f28v = (f32)x;
                        f26v = f28v + margin;
                        f25v = (f32)y1;
                        GXBegin(0x98, 0, 4);
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 0);
                        *(f32 *)0xCC008000 = f28v;
                        *(f32 *)0xCC008000 = f27v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x20];
                        *(u8 *)0xCC008000 = pal[0x21];
                        *(u8 *)0xCC008000 = pal[0x22];
                        *(u8 *)0xCC008000 = pal[0x23];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 1);
                        *(f32 *)0xCC008000 = f26v;
                        *(f32 *)0xCC008000 = f27v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x24];
                        *(u8 *)0xCC008000 = pal[0x25];
                        *(u8 *)0xCC008000 = pal[0x26];
                        *(u8 *)0xCC008000 = pal[0x27];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 2);
                        *(f32 *)0xCC008000 = f28v;
                        *(f32 *)0xCC008000 = f25v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x28];
                        *(u8 *)0xCC008000 = pal[0x29];
                        *(u8 *)0xCC008000 = pal[0x2A];
                        *(u8 *)0xCC008000 = pal[0x2B];
                        z = Map_GetTileCornerHeight(gBattleMap, x, y, 3);
                        *(f32 *)0xCC008000 = f26v;
                        *(f32 *)0xCC008000 = f25v;
                        *(f32 *)0xCC008000 = z;
                        *(u8 *)0xCC008000 = pal[0x2C];
                        *(u8 *)0xCC008000 = pal[0x2D];
                        *(u8 *)0xCC008000 = pal[0x2E];
                        *(u8 *)0xCC008000 = pal[0x2F];
                    }
                }
                cell -= 1;
                idx -= 1;
                x -= 1;
            x_test:
                ;
            } while ((s8)x >= 0);
            row -= 0x40;
            yOff -= 0x40;
            y -= 1;
        y_test:
            ;
        } while ((s8)y >= 0);
        fn_80066D00(-1);
    }
}
#pragma global_optimizer on

void fn_8004A864(void* arg0, s32 arg1) {
    u8* ptr = (u8*)arg0 + 0x60;
    s32 temp_r3 = *ptr;
    s32 count = temp_r3 + arg1;

    if (count < 0) {
        return;
    }

    *ptr = (u8)count;
}

void fn_8004AAA4(void) {
    M2C_UNK fn_80067FDC();
    M2C_UNK PSMTXConcat(M2C_UNK, M2C_UNK *, M2C_UNK *);
    M2C_UNK PSMTXTrans(M2C_UNK *, f32, f32, f32);
    M2C_UNK GXSetVtxDesc(M2C_UNK, M2C_UNK);
    M2C_UNK GXClearVtxDesc();
    M2C_UNK GXSetVtxAttrFmt(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK fn_802201A8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetNumChans(M2C_UNK);
    M2C_UNK fn_8022100C(M2C_UNK);
    M2C_UNK GXSetCullMode(M2C_UNK);
    M2C_UNK GXSetBlendMode(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetNumTexGens(M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevOrder(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetNumTevStages(M2C_UNK);
    M2C_UNK fn_802245D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXLoadPosMtxImm(M2C_UNK *, M2C_UNK);
    M2C_UNK GXSetCurrentMtx(M2C_UNK);
    extern f32 lbl_80368F84;
    extern f32 lbl_80368F88;
    M2C_UNK sp8[14];

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
    PSMTXTrans(sp8, lbl_80368F84, lbl_80368F84, lbl_80368F88);
    PSMTXConcat(fn_80067FDC(), sp8, sp8);
    GXLoadPosMtxImm(sp8, 0);
    GXSetCurrentMtx(0);
    fn_802245D8(1, 4, 1, 0);
}

s32 fn_8004ABD4(void **arg0, u8 arg1) {
    void *Item_GetFlagsPtr(void **);
    u8 fn_8001DDBC();
    u8 var_r0;
    u8 var_r0_2;
    u8 var_r0_3;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;

    if (arg0 != NULL) {
        if (arg1 == 0) {
            if ((void *) *arg0 != NULL) {
                var_r0 = fn_8001DDBC();
            } else {
                var_r0 = 0;
            }
            if ((var_r0 > 1U) && (temp_r3 = Item_GetFlagsPtr(arg0), (((((M2C_FIELD(temp_r3, s32 *, 4) & 0x40) ^ 0) | ((M2C_FIELD(temp_r3, s32 *, 0) & 0) ^ 0)) == 0) != 0))) {
                temp_r3_2 = *arg0;
                if (temp_r3_2 != NULL) {
                    var_r0_2 = M2C_FIELD(temp_r3_2, u8 *, 0x12);
                } else {
                    var_r0_2 = 0xC;
                }
                switch ((s32) var_r0_2) {           /* switch 1; irregular */
                case 2:                             /* switch 1 */
                    return 3;
                case 1:                             /* switch 1 */
                    return 5;
                }
            } else {
                goto block_16;
            }
        } else {
block_16:
            temp_r3_3 = *arg0;
            if (temp_r3_3 != NULL) {
                var_r0_3 = M2C_FIELD(temp_r3_3, u8 *, 0x12);
            } else {
                var_r0_3 = 0xC;
            }
            switch ((s32) var_r0_3) {               /* switch 2; irregular */
            case 1:                                 /* switch 2 */
                return 4;
            case 3:                                 /* switch 2 */
                return 6;
            case 8:                                 /* switch 2 */
                return 0;
            case 2:                                 /* switch 2 */
                return 2;
            case 0:                                 /* switch 2 */
                return 1;
            }
        }
    } else {
        return 0;
    }
}

s32 fn_8004AE28(s32 arg0, s32 arg1, s32 arg2)
{
    s32 var_r3;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    u8 *ptr;
    
    ptr = (u8*)arg0;
    if (ptr == NULL)
        return 0;
    
    var_r3 = *(ptr + 0x10);
    if ((var_r3 >= 0) && (var_r3 < 0x40)) {
        return (s32)*(ptr + 0x8 * var_r3 + 0x14);
    }
    
    var_r4 = *(ptr + arg1 + 0x14);
    if ((var_r4 >= 0) && (var_r4 < 0x10)) {
        return (s32)*(ptr + var_r4 * 0x8 + 0x14);
    }
    
    return 0;
}

s32 fn_8004AF30(u16 arg0) {
    if (arg0 == 0xFFFF) {
        return 0;
    }
    if (arg0 < 0x3E8) {
        return 0;
    }
    return fn_80146B10();
}

#pragma peephole off
s32 fn_8004AF74(u8 *arg0, s32 arg1) {
    s32 v = (arg0 + arg1)[0xc];
    if (v / 64 == 0 && (v % 64) < 0x20) {
        return 1;
    }
    return 0;
}
#pragma peephole on
s32 fn_8004AFB4(void *arg0, s32 arg1) {
    return (M2C_FIELD(arg0, s32 *, 0x10) & (1 << arg1)) != 0;
}

char *fn_8004AFD4(void *arg0, s32 arg1) {
void fn_800056A0(s32); void sprintf(void *, void *, ...);
extern u8 lbl_8026A9B0[]; extern s32 lbl_80285880[]; extern s32 lbl_802858C4[]; extern u8 lbl_802EFFC8[];
if ((*(s32 *)((u8 *)arg0+0x10) & (1 << arg1)) == 0) {arg1=6; fn_800056A0(0);}
sprintf(lbl_802EFFC8,lbl_8026A9B0+0x9C,lbl_8026A9B0+0xA8,*(s32 *)((u8 *)arg0+4),lbl_80285880[arg1],lbl_802858C4[*(u8 *)((u8 *)arg0+8)]);
return (char *)lbl_802EFFC8;
}

#pragma opt_strength_reduction off
char *fn_8004B078(void *arg0, s32 arg1)
{
    void sprintf(void *, void *, ...);
    extern u8 lbl_8026A9B0[];
    extern u8 lbl_802EFFC8[];

    u8 *fmt;
    u8 *address;
    void *value;
    u8 b;

    fmt = lbl_8026A9B0;
    address = (u8 *)arg0 + arg1;
    value = *(void **)((u8 *)arg0 + 4);
    b = address[0xC];

    sprintf(
        lbl_802EFFC8,
        fmt + 0xAD,
        fmt + 0xA8,
        value,
        b
    );

    return (char *)lbl_802EFFC8;
}
#pragma opt_strength_reduction on
void *fn_8004B0C8(void *arg0) {
    void sprintf(void *, void *, ...);
    extern u8 lbl_8026A9B0[];
    extern u8 lbl_802EFFC8[];

    sprintf(lbl_802EFFC8, lbl_8026A9B0 + 0xBC, lbl_8026A9B0 + 0xA8, *(s32 *)((u8 *)arg0 + 4));
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
    void fn_80223DDC(s32, s32, s32, s32, s32);
    void fn_80223D94(s32, s32, s32);
    void GXSetTevColorIn(s32, s32, s32, s32, s32);
    void GXSetTevColorOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
    void GXSetTevAlphaOp(s32, s32, s32, s32, s32, s32);
    void fn_80069010(s32, s32);
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
        fn_80223DDC(1, 1, 1, 1, 3);
        fn_80223D94(tevStage, 0, 1);
        GXSetTevColorIn(tevStage, 0xF, 8, 0xA, 0xA);
        GXSetTevColorOp(tevStage, 0, 2, 3, 1, 0);
        GXSetTevAlphaIn(tevStage, 7, 4, 5, 7);
        GXSetTevAlphaOp(tevStage, 0, 0, 0, 1, 0);
    }
    fn_80069010(mat, node);
    fn_800690D4(mat, node, obj);
    GMaterial_SetupColor(mat, 0, node, obj);
    return 1;
}

#pragma use_lmw_stmw on
void fn_8004B588(u8 *arg0)
{
    f32 Math_Lerp(f32, f32, f32, f32);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void fn_80222C50(void *, s32);
    void PSMTXRotRad(void *, s32, f32);
    void fn_802026E4(void *, void *, void *, void *);
    void C_MTXLightOrtho(void *, f32, f32, f32, f32, f32, f32, f32, f32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXTrans(void *, f32, f32, f32);
    void fn_80224E50(void *, s32, s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80051564(void *, s32, f32, f32);
    extern u8 lbl_8026AA98[];
    extern s32 gUnitShadowMat;
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
    u8 sp4C[0x50];
    u32 sp48;
    f32 sp44;
    f32 sp40;
    u32 sp3C;
    f32 sp38;
    f32 sp34;
    u32 sp30;
    u32 sp2C;
    u32 sp28;
    u32 sp24;
    f32 sp20;
    f32 sp1C;
    u32 sp18;
    f32 sp14;
    f32 sp10;
    u32 spC;
    u32 sp8;
    f32 scale;
    s32 alpha;
    u8 *tbl;

    tbl = lbl_8026AA98;
    scale = lbl_80368FC4;
    alpha = 0xFF;
    switch (arg0[0]) {
    case 0:
        alpha = 0xC0;
        if (arg0[1] > 0x78U) {
            alpha = (s32)Math_Lerp(lbl_80368FC8, lbl_80368FCC, lbl_80368FD0, (f32)(s32)(arg0[1] - 0x78));
        }
        Ui_LoadAtlasTex(gUnitShadowMat, sp4C, 3);
        break;
    case 1:
        alpha = (s32)Math_EaseOutPow(2, lbl_80368FD4, lbl_80368FCC, lbl_80368FD0, (f32)arg0[1]);
        scale = Math_EaseOutPow(2, lbl_80368FBC, lbl_80368FC4, lbl_80368FD0, (f32)arg0[1]);
        Ui_LoadAtlasTex(gUnitShadowMat, sp4C, 4);
        break;
    }
    fn_80222C50(sp4C, 0);
    {
        f32 angle = (f32)*(s16 *)(arg0 + 2);
        f32 y = *(f32 *)(arg0 + 8);
        f32 x = *(f32 *)(arg0 + 4);
        sp38 = *(f32 *)(tbl + 0x20);
        sp44 = *(f32 *)(tbl + 0x2C);
        sp40 = *(f32 *)(tbl + 0x28);
        sp34 = *(f32 *)(tbl + 0x1C);
        sp34 = x;
        sp38 = y;
        sp44 = y;
        spC = lbl_80368FB4;
        sp40 = x;
        ((u8 *)&spC)[3] = (u8)alpha;
        sp3C = *(u32 *)(tbl + 0x24);
        sp10 = sp34;
        sp14 = sp38;
        sp18 = *(u32 *)(tbl + 0x24);
        sp48 = *(u32 *)(tbl + 0x30);
        sp1C = sp40;
        sp20 = sp44;
        sp24 = *(u32 *)(tbl + 0x30);
        sp28 = *(u32 *)(tbl + 0x34);
        sp2C = *(u32 *)(tbl + 0x38);
        sp30 = *(u32 *)(tbl + 0x3C);
        if (lbl_80368FCC != angle) {
            PSMTXRotRad(spCC, 0x5A, lbl_80368FD8 * angle);
            fn_802026E4(sp9C, &sp1C, &sp28, &sp10);
            C_MTXLightOrtho(sp6C, -scale, scale, -scale, scale, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
            PSMTXConcat(sp6C, sp9C, sp12C);
            PSMTXTrans(spFC, lbl_80368FDC, lbl_80368FDC, lbl_80368FCC);
            PSMTXConcat(spCC, spFC, spCC);
            PSMTXTrans(spFC, lbl_80368FC4, lbl_80368FC4, lbl_80368FCC);
            PSMTXConcat(spFC, spCC, spCC);
            PSMTXConcat(spCC, sp12C, sp12C);
        } else {
            fn_802026E4(sp9C, &sp1C, &sp28, &sp10);
            C_MTXLightOrtho(sp6C, -scale, scale, -scale, scale, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
            PSMTXConcat(sp6C, sp9C, sp12C);
        }
    }
    fn_80224E50(sp12C, 0x1E, 0);
    fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
    sp8 = spC;
    fn_80051564(&sp8, 0, *(f32 *)(arg0 + 4), *(f32 *)(arg0 + 8));
}

void fn_8004B8F8(int arg0, int arg1, float arg2, float arg3)
{
  extern u8 *lbl_803672CC;
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

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset
s32 fn_8004BAC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r3_2;

    if (arg0 < 0x0) {
        temp_r3 = arg0 + 0x1F;
    } else {
        temp_r3 = arg0;
    }
    temp_r3 = temp_r3 >> 5;
    
    if (arg1 < 0x0) {
        temp_r6 = arg1 + 0x1F;
    } else {
        temp_r6 = arg1;
    }
    temp_r6 = temp_r6 >> 5;
    
    if (arg2 < 0x0) {
        temp_r5 = arg2 + 0x1F;
    } else {
        temp_r5 = arg2;
    }
    temp_r5 = temp_r5 >> 5;
    
    if (arg3 < 0x0) {
        temp_r3_2 = arg3 + 0x1F;
    } else {
        temp_r3_2 = arg3;
    }
    temp_r3_2 = temp_r3_2 >> 5;
    
    return ((temp_r6 * 0x7D8600) + (temp_r3 * 0x32E100)) + ((temp_r5 * 0x7D8600) + (temp_r3_2 * 0x32E100));
}

void fn_8004BC48(void *arg0, s32 arg1) {
    s16 Stream_ReadU16(s32);
    M2C_UNK Stream_ReadU8(s32);
    extern f32 lbl_80368FCC;
    M2C_FIELD(arg0, s8 *, 3) = 0;
    M2C_FIELD(arg0, s16 *, 0x15C) = 0;
    M2C_FIELD(arg0, s16 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 0x16E) = -1;
    M2C_FIELD(arg0, s8 *, 0x16D) = -1;
    M2C_FIELD(arg0, s8 *, 0x16C) = -1;
    M2C_FIELD(arg0, f32 *, 0x170) = (f32) lbl_80368FCC;
    M2C_FIELD(arg0, f32 *, 0x174) = (f32) lbl_80368FCC;
    M2C_FIELD(arg0, f32 *, 0x178) = (f32) lbl_80368FCC;
    M2C_FIELD(arg0, s32 *, 0x17C) = 0;
    M2C_FIELD(arg0, s16 *, 0x15C) = Stream_ReadU16(arg1);
    Stream_ReadU8(arg1);
    Stream_ReadU8(arg1);
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
f32 a,b,k,t,x,y; u8 *p;
a=lbl_80368FCC; p=*(u8 **)((u8 *)arg0+0x17c); b=a;
if(p){ a=(f32)(s8)p[0xa]; b=(f32)(s8)p[0xb]; }
x=a*scale; k=lbl_80368FF4; y=b*scale; t=lbl_80368FCC;
x=x*k; t=t*scale; y=y*k; out[0]=x; t=t*k; out[1]=y; out[2]=t;
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

f32 fn_8004BE18(void *arg0, void *arg1) {
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

void fn_8004BE88(void *arg0, u8 arg1) {
    void fn_8001885C(void);
    void fn_8014CBD8(void *, f32, f32);
    extern u8 gBattleState[];

    if (!(M2C_FIELD(arg0, s32 *, 0x1A0) & 0x18)) {
        fn_8014CBD8(gBattleState, (f32)(s32)M2C_FIELD(arg0, f32 *, 4), (f32)(s32)M2C_FIELD(arg0, f32 *, 8));
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

s32 fn_8004BF80(void *arg0) {
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

u8 fn_8004C00C(void *arg0) {
    extern f32 lbl_80368FC4;
    if ((lbl_80368FC4 + (f32) (s8) M2C_FIELD(arg0, u8 *, 0x19E)) != (M2C_FIELD(arg0, f32 *, 4) + M2C_FIELD(arg0, f32 *, 0x10))) {
        return 1U;
    }
    return (u8) ((lbl_80368FC4 + (f32) (s8) M2C_FIELD(arg0, u8 *, 0x19F)) != (M2C_FIELD(arg0, f32 *, 8) + M2C_FIELD(arg0, f32 *, 0x14)));
}

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

void fn_8004C148(void) {
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8004C444(void *arg0) {
    s32 fn_800067B4(void);
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
    u8 sp4C[0x30];
    u32 sp48;
    f32 sp44;
    f32 sp40;
    u32 sp3C;
    f32 sp38;
    f32 sp34;
    u32 sp30;
    u32 sp2C;
    u32 sp28;
    u32 sp24;
    f32 sp20;
    f32 sp1C;
    u32 sp18;
    f32 sp14;
    f32 sp10;
    u32 spC;
    u32 sp8;
    f32 x, y, angle, f1;
    s32 alpha;
    u8 *tbl;
    u32 t24, t30, t1c, t20, t28, t2c, t34, t38, t3c;

    tbl = lbl_8026AA98;
    angle = (f32)*(u16 *)arg0;
    x = *(f32 *)((u8 *)arg0 + 4);
    y = *(f32 *)((u8 *)arg0 + 8);
    f1 = fn_80059EB8(0x80, fn_800067B4(), lbl_80368FD4, lbl_80369000);

    t24 = *(u32 *)(tbl + 0x24);
    t30 = *(u32 *)(tbl + 0x30);
    t1c = *(u32 *)(tbl + 0x1C);
    t20 = *(u32 *)(tbl + 0x20);
    t28 = *(u32 *)(tbl + 0x28);
    t2c = *(u32 *)(tbl + 0x2C);
    alpha = (s32)(((f32)((u8 *)arg0)[0x27] * f1) / lbl_80369000);
    *(u32 *)&sp34 = t1c;
    *(u32 *)&sp38 = t20;
    *(u32 *)&sp40 = t28;
    *(u32 *)&sp44 = t2c;
    t34 = *(u32 *)(tbl + 0x34);
    t38 = *(u32 *)(tbl + 0x38);
    t3c = *(u32 *)(tbl + 0x3C);
    sp34 = x;
    sp38 = y;
    sp40 = x;
    sp44 = y;
    sp3C = t24;
    sp10 = sp34;
    sp14 = sp38;
    sp18 = t24;
    sp48 = t30;
    sp1C = sp40;
    sp20 = sp44;
    sp24 = t30;
    sp28 = t34;
    sp2C = t38;
    sp30 = t3c;

    if (angle != lbl_80368FCC) {
        PSMTXRotRad(spBC, 0x5A, lbl_80368FD8 * angle);
        fn_802026E4(sp8C, &sp1C, &sp28, &sp10);
        C_MTXLightOrtho(sp5C, -lbl_80368FC4, lbl_80368FC4, -lbl_80368FC4, lbl_80368FC4,
                    lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
        PSMTXConcat(sp5C, sp8C, sp11C);
        PSMTXTrans(spEC, lbl_80368FDC, lbl_80368FDC, lbl_80368FCC);
        PSMTXConcat(spBC, spEC, spBC);
        PSMTXTrans(spEC, lbl_80368FC4, lbl_80368FC4, lbl_80368FCC);
        PSMTXConcat(spEC, spBC, spBC);
        PSMTXConcat(spBC, sp11C, sp11C);
    } else {
        fn_802026E4(sp8C, &sp1C, &sp28, &sp10);
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
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

/* Set up GX and draw a ground shadow for each visible unit. */
void Unit_DrawShadows(void) {
    void Allegiance_FillMask(s32, void *);
    void Unit_DrawShadow(void *, s32);
    void fn_80066D00(s32);
    void *Light_GetChannel(s32);
    void *fn_80067FDC(void);
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
    PSMTXConcat(fn_80067FDC(), mtxTrans, mtxOut);
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
void Unit_DrawShadow(u8 *arg0, s32 arg1) {
    f32 fn_80023068(void *);
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
    extern void *gBattleMap;
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
    u8 sp340[0x30];
    u8 sp310[0x30];
    u8 sp2E0[0x30];
    u8 sp2B0[0x30];
    u8 sp280[0x30];
    u8 sp250[0x30];
    u8 sp220[0x30];
    u8 sp1F0[0x30];
    u8 sp1C0[0x30];
    u8 sp190[0x30];
    u8 sp160[0x30];
    f32 sp154;
    f32 sp158;
    f32 sp15C;
    f32 sp148;
    f32 sp14C;
    f32 sp150;
    f32 sp124;
    f32 sp128;
    f32 sp12C;
    u8 scratch[0x120];
    u32 sp18;
    u32 sp14;
    u32 sp10;
    u32 spC;
    u32 sp8;
    f32 f30, f29, f28, f27, f26, f25, f31, f24;
    f32 dx, dy, t;
    s8 r29, r27;
    u8 r30;
    u8 *r28;
    u8 *tbl;
    f32 lim;

    f30 = *(f32 *)(arg0 + 4);
    f29 = *(f32 *)(arg0 + 8);
    r28 = arg0 + 0x1C;
    f28 = lbl_80369004 * ((f32)*(s16 *)(arg0 + 0x15E) / lbl_80369008);
    f25 = *(f32 *)(arg0 + 0xC);
    r29 = (s8)arg0[0x168];
    r27 = (s8)arg0[0x169];
    f27 = lbl_80369004 * ((f32)*(s16 *)(arg0 + 0x162) / lbl_80369008);
    r30 = (u8)((arg1 * arg0[0x27]) / 255);
    tbl = lbl_8026AA98;
    (void)gBattleMap;
    lim = -(f25 - fn_80023068(gBattleMap));
    if (lim > lbl_8036900C) lim = lbl_8036900C;
    f31 = Math_Lerp(lbl_80368FC0, lbl_80368FBC, lbl_8036900C, lim);
    if (r29 >= 0 && r27 >= 0) {
        fn_80060F70(r28, r29, &sp148);
        fn_80060F70(r28, r27, &sp154);
        f30 = (sp148 + sp154) * lbl_80368FC4;
        f29 = (sp14C + sp158) * lbl_80368FC4;
        f26 = f30 - sp148;
        f25 = f29 - sp14C;
        if (lbl_80368FCC != f26 || lbl_80368FCC != f25) {
            *(f32 *)(scratch + 0) = (f32)(s32)(lbl_80369008 * f26);
            *(f32 *)(scratch + 4) = (f32)(s32)(lbl_80369008 * f25);
            *(u32 *)(scratch + 0x10) = *(u32 *)(tbl + 0x4C);
            *(u32 *)(scratch + 0x14) = *(u32 *)(tbl + 0x50);
            *(u32 *)(scratch + 0x18) = *(u32 *)(tbl + 0x54);
            *(f32 *)(scratch + 0x20) = *(f32 *)(scratch + 0);
            *(f32 *)(scratch + 0x24) = *(f32 *)(scratch + 4);
            *(u32 *)(scratch + 0x28) = *(u32 *)(tbl + 0x60);
            fn_802031E8(scratch + 0x20, scratch + 0x20);
            t = fn_80203270(scratch + 0x10, scratch + 0x20);
            if (t > lbl_80368FC0) t = lbl_80368FC0;
            if (t < lbl_80368FFC) t = lbl_80368FFC;
            f24 = (f32)fn_80238788(t);
            if (f25 < lbl_80368FCC) f24 *= lbl_80368FFC;
            PSMTXRotRad(sp340, 0x7A, -f24);
            *(f32 *)(scratch + 0x20) = f26;
            *(f32 *)(scratch + 0x24) = f25;
            *(u32 *)(scratch + 0x28) = *(u32 *)(tbl + 0x6C);
            fn_802029C4(sp340, scratch + 0x20, scratch + 0x20);
            f26 = lbl_80369010 + *(f32 *)(scratch + 0x20);
            f25 = lbl_80369010 + *(f32 *)(scratch + 0x24);
            dx = lbl_80369014 * f24;
        } else {
            dx = lbl_80368FCC;
        }
        if (f26 < f28) f26 = f28;
        if (f25 < f27) f25 = f27;
        {
            f32 x1 = f30, y1 = f29;
            *(f32 *)(scratch + 0x30) = x1;
            *(f32 *)(scratch + 0x34) = y1;
            *(u32 *)(scratch + 0x38) = *(u32 *)(tbl + 0x24);
            *(f32 *)(scratch + 0x3C) = x1;
            *(f32 *)(scratch + 0x40) = y1;
            *(u32 *)(scratch + 0x44) = *(u32 *)(tbl + 0x30);
            *(u32 *)(scratch + 0x48) = *(u32 *)(tbl + 0x34);
            *(u32 *)(scratch + 0x4C) = *(u32 *)(tbl + 0x38);
            *(u32 *)(scratch + 0x50) = *(u32 *)(tbl + 0x3C);
            if (lbl_80368FCC != dx) {
                PSMTXRotRad(sp2E0, 0x5A, lbl_80368FD8 * dx);
                fn_802029C4(sp2E0, scratch + 0x48, scratch + 0x48);
                fn_802026E4(sp2B0, scratch + 0x3C, scratch + 0x48, scratch + 0x30);
                C_MTXLightOrtho(sp280, -(f25 * f31), f25 * f31, -(f26 * f31), f26 * f31, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
                PSMTXConcat(sp280, sp2B0, sp340);
                PSMTXTrans(sp310, lbl_80368FDC, lbl_80368FDC, lbl_80368FCC);
                PSMTXConcat(sp2E0, sp310, sp2E0);
                PSMTXTrans(sp310, lbl_80368FC4, lbl_80368FC4, lbl_80368FCC);
                PSMTXConcat(sp310, sp2E0, sp2E0);
                PSMTXConcat(sp2E0, sp340, sp340);
            } else {
                fn_802026E4(sp2B0, scratch + 0x3C, scratch + 0x48, scratch + 0x30);
                C_MTXLightOrtho(sp280, -(f25 * f31), f25 * f31, -(f26 * f31), f26 * f31, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
                PSMTXConcat(sp280, sp2B0, sp340);
            }
        }
        if (fn_80055D94(0x100) != 0) {
            sp18 = lbl_80368FA8;
            ((u8 *)&sp18)[3] = r30;
            fn_802026E4(sp250, scratch + 0x60, scratch + 0x6C, scratch + 0x54);
            C_MTXLightOrtho(sp220, lbl_80369018, lbl_80369010, lbl_80369018, lbl_80369010, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
            PSMTXConcat(sp220, sp250, sp340);
            fn_80224E50(sp340, 0x1E, 0);
            fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
            sp10 = sp18;
            fn_80051564(&sp10, 1, f30, f29);
            fn_802026E4(sp1F0, scratch + 0x80, scratch + 0x8C, scratch + 0x74);
            C_MTXLightOrtho(sp1C0, lbl_80369018, lbl_80369010, lbl_80369018, lbl_80369010, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
            PSMTXConcat(sp1C0, sp1F0, sp340);
            fn_80224E50(sp340, 0x1E, 0);
            fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
            spC = sp18;
            fn_80051564(&spC, 1, f30, f29);
            return;
        }
    } else {
        fn_80060F70(r28, 1, &sp124);
        fn_802026E4(sp190, scratch + 0xA0, scratch + 0xAC, scratch + 0x94);
        C_MTXLightOrtho(sp160, -(f28 * f31), f28 * f31, -(f27 * f31), f27 * f31, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
        PSMTXConcat(sp160, sp190, sp340);
    }
    fn_80224E50(sp340, 0x1E, 0);
    fn_802201A8(0, 0, 0, 0x1E, 0, 0x7D);
    sp14 = lbl_80368FAC;
    ((u8 *)&sp14)[3] = r30;
    sp8 = sp14;
    fn_80051564(&sp8, 1, f30, f29);
}

void fn_8004D370(void) {
    void fn_80067708(s32, s32, void (*)(void), s32);
    void Unit_DrawShadows(void);
    fn_80067708(2, 1, Unit_DrawShadows, 0);
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

void fn_8004DAFC(void *arg0, f32 farg0) {
    extern f32 lbl_80368FCC;
    extern f32 lbl_8036902C;
    extern f32 lbl_80369030;
    extern f32 lbl_80368FC0;

    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    u8 temp_r31;
    f32 var_f30;
    f32 var_f29;
    f32 var_f28;

    sp8 = *(f32 *)((u8 *)arg0 + 0x170);
    spC = *(f32 *)((u8 *)arg0 + 0x174);
    sp10 = *(s32 *)((u8 *)arg0 + 0x178);

    fn_80068070(spC, sp8, lbl_80368FCC, lbl_80368FCC, lbl_8036902C, lbl_80369030);
    fn_800680AC(0, 0, 0xA0, 0x78);
    fn_80067EDC(0);
    temp_r31 = *(u8 *)((u8 *)arg0 + 0x27);
    GXBegin(0x98, 0, 4);

    var_f28 = *(f32 *)((u8 *)arg0 + 0x170);
    var_f29 = *(f32 *)((u8 *)arg0 + 0x174);
    temp_f5 = *(s32 *)((u8 *)arg0 + 0x178);

    var_f30 = farg0;

    temp_f4 = var_f28 - var_f30;
    temp_f3 = var_f29 - var_f30;
    temp_f2 = var_f28 + var_f30;

    *(f32 *)0xCC008000 = temp_f4;
    *(f32 *)0xCC008000 = temp_f3;
    *(f32 *)0xCC008000 = lbl_80368FCC;
    *(u8 *)0xCC008000 = temp_r31;
    *(u8 *)0xCC008000 = temp_r31;
    *(u8 *)0xCC008000 = temp_r31;
    *(u8 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = lbl_80368FCC;
    *(f32 *)0xCC008000 = lbl_80368FCC;
    *(f32 *)0xCC008000 = temp_f2;
    *(f32 *)0xCC008000 = temp_f3;
    *(f32 *)0xCC008000 = lbl_80368FCC;
    *(u8 *)0xCC008000 = temp_r31;
    *(u8 *)0xCC008000 = temp_r31;
    *(u8 *)0xCC008000 = temp_r31;
    *(u8 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = lbl_80368FC0;
    *(f32 *)0xCC008000 = lbl_80368FCC;
    *(f32 *)0xCC008000 = temp_f4;
    *(f32 *)0xCC008000 = temp_f5;
    *(f32 *)0xCC008000 = lbl_80368FCC;
    *(u8 *)0xCC008000 = temp_r31;
    *(u8 *)0xCC008000 = temp_r31;
    *(u8 *)0xCC008000 = temp_r31;
    *(u8 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = lbl_80368FCC;
    *(f32 *)0xCC008000 = lbl_80368FC0;
    *(f32 *)0xCC008000 = temp_f2;
    *(f32 *)0xCC008000 = temp_f5;
    *(f32 *)0xCC008000 = lbl_80368FCC;
    *(u8 *)0xCC008000 = temp_r31;
    *(u8 *)0xCC008000 = temp_r31;
    *(u8 *)0xCC008000 = temp_r31;
    *(u8 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = lbl_80368FC0;
    *(f32 *)0xCC008000 = lbl_80368FC0;

    fn_80067984(0, 0xCC010000, lbl_80368FCC, temp_f2, temp_f3, temp_f4, temp_f5);
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

void fn_8004DDB8(s32 arg0) {
    void fn_80007340(void (*)(void), s32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void fn_80009B28(void);
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
        c = 0x60;
        p = &lbl_803672C0;
        flag = !!c;
        lbl_803672C0 = c;
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
        fn_80009B28();
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

void fn_8004DF58(void *arg0)
{
    void fn_800609DC(void *);
    extern u8 gBattleState[];
    u8 flags;
    void *p;
    u8 ok;
    s32 n;

    flags = *((u8 *)arg0 + 3);
    p = (u8 *)arg0 + 0x1c;
    if (!(flags & 8)) {
        if (*(u32 *)((u8 *)arg0 + 0x1a0) & 0x010000FC) {
            ok = 0;
        } else if ((u8)(flags & 0x22) != 2) {
            ok = 0;
        } else if (*((u8 *)arg0 + 0x27) == 0) {
            ok = 0;
        } else {
            ok = 1;
        }
        if (ok) {
            fn_800609DC(p);
        }
        if (!(*(u32 *)((u8 *)arg0 + 0x1a0) & 1)) {
            if (*(*(u8 **)((u8 *)arg0 + 0x190) + 8) == gBattleState[0x11]) {
                n = *(u16 *)arg0 + 1;
                *(u16 *)arg0 = n % 360;
            }
        }
    }
}

extern double lbl_80368FE0;
extern float lbl_80368FF8;
extern float lbl_80368FD8;
void fn_8004E040(void) {
    float val = *(float*)lbl_803672A8;
    *(float*)lbl_803672A8 = (val - lbl_80368FE0) / lbl_80368FF8 * lbl_80368FD8;
    lbl_80368EF8 = *(float*)lbl_803672A8;
}

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

#pragma use_lmw_stmw on
void fn_8004EB14(void *arg0, u32 arg1) {
#pragma opt_common_subs off
    void fn_800056A0(s32);
    void DebugPrint(void *, ...);
    void *Res_GetByName(void *);
    void *fn_80037D54(void *);
    s32 fn_8004ABD4(void *, s32);
    void *fn_8004B078(void *, s32);
    s32 fn_8004B0C8(void *);
    s32 fn_8004B110(void *);
    void *fn_8004B158(void *);
    s32 fn_8004B1A0(s32);
    void fn_8004FE98(void *, s32);
    u16 fn_8005C144(void *);
    void *fn_8005C82C(void *, u16);
    void fn_8005F434(void *, void *, u16);
    void GActor_LoadG(void *, s32);
    void GActor_LoadGs(void *, s32);
    void Model_SetAlpha(void *, s32);
    void fn_8005FEE8(void *, f32);
    void fn_80060638(void *);
    void *fn_80060664(void *);
    s32 GActor_FindNode(void *, void *);
    void GActor_Finalize(void *);
    void fn_80061824(void *);
    void fn_800688D4(void *, s32, void *, s32);
    u8 Status_Test(void *, s32);
    void sprintf(void *, void *, ...);
    void GMaterial_SetupAtlasTev(void);
    extern u8 lbl_8026AB18[];
    extern void *lbl_80366DC8;
    extern f32 lbl_80368FCC;
    extern f32 lbl_80368FFC;
    extern u8 lbl_802EFFE8[];

    s32 sp[2];
    void *res;
    void *sub;
    void *sub2;
    void *tmp;
    u8 flags;
    u8 t;
    s32 id;

    flags = M2C_FIELD(arg0, u8 *, 3);
    if (!(flags & 2)) {
        M2C_FIELD(arg0, u8 *, 3) = flags & 0xFE;
        M2C_FIELD(arg0, u8 *, 3) |= 2;
        id = get_4F128_id(arg0);
        res = get_4F128_resource(arg0, id);
        sub = (u8 *)arg0 + 0x1C;
        M2C_FIELD(arg0, void **, 0x17C) = res;
        fn_80061824(sub);
        M2C_FIELD(sub, u8 *, 0x87) = 1;
        arg1 = (u16)arg1 | 8;
        M2C_FIELD(arg0, void **, 0x164) = fn_8005C82C(fn_8004B158(res), (u16)arg1);
        GActor_LoadG(sub, fn_8004B0C8(res));
        GActor_LoadGs(sub, fn_8004B110(res));
        id = get_4F128_id(arg0);
        res = get_4F128_resource(arg0, id);
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
        GActor_Finalize(sub);
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
            t = M2C_FIELD(arg0, u8 *, 3);
            M2C_FIELD(arg0, u8 *, 3) = t & 0xEF;
        } else {
            fn_8004FE98(arg0, 0);
        }
        {
            u32 bits = M2C_FIELD(sub, u32 *, 0);
            M2C_FIELD(sub, u32 *, 0) = (bits | 0x61100000) | 0x8000;
        }
        M2C_FIELD(arg0, f32 *, 0x10) = lbl_80368FCC;
        M2C_FIELD(arg0, f32 *, 0x14) = lbl_80368FCC;
        M2C_FIELD(arg0, f32 *, 0x18) = lbl_80368FCC;
        M2C_FIELD(arg0, s16 *, 0x15E) = 0x3C;
        M2C_FIELD(arg0, s16 *, 0x160) = 0x3C;
        M2C_FIELD(arg0, s16 *, 0x162) = 0x3C;
        sp[0] = GActor_FindNode(sub, lbl_8026AB18 + 0x8F);
        sp[1] = GActor_FindNode(sub, lbl_8026AB18 + 0x92);
        sub2 = (u8 *)arg0 + 0x1C;
        M2C_FIELD(arg0, u8 *, 0x168) = sp[0];
        M2C_FIELD(arg0, u8 *, 0x169) = sp[1];
        fn_80060638(sub2);
        fn_800688D4(sub2, 0, GMaterial_SetupAtlasTev, 0x4000);
        M2C_FIELD(sub2, void **, 0x90) = arg0;
        Model_SetAlpha(sub2, 0);
        sub2 = (u8 *)arg0 + 0xBC;
        fn_80061824(sub2);
        M2C_FIELD(sub2, void **, 4) = lbl_802EFFE8;
        GActor_Finalize(sub2);
        M2C_FIELD(sub2, u32 *, 0) |= 0x100;
        M2C_FIELD(sub2, void **, 4) = NULL;
    }
}
#pragma use_lmw_stmw reset

s32 fn_8004F128(void *arg0) {
#pragma opt_common_subs off
  void fn_800056A0(s32);
 void DebugPrint(void *, ...);
 void *Res_GetByName(void *);
 void *fn_80037D54(void *);
 s32 fn_8004ABD4(void *,s32);
 u8 fn_8004AF74(void *,u8);
 void *fn_8004B078(void *,s32);
 void *fn_8004B158(void *);
 s32 fn_8004B1A0(s32);
 u16 fn_8005C144(void *);
 void fn_8005C870(void *,u16);
 u8 Status_Test(void *,s32);
 void sprintf(void *,void *,...);
 extern u8 lbl_8026AB18[];
 extern void *lbl_80366DC8;

 u8 fn_8005BA10(void *);
 void *res;
 s32 id;
 void *obj=arg0;
 u8 flags=M2C_FIELD(arg0,u8 *,3);
 if(flags&2) return 1;
 if(!(flags&1)) return 1;
 id=get_4F128_id(arg0);
 res=get_4F128_resource(obj,id);
 if(!fn_8005BA10(fn_8004B158(res))) return 0;
 if(!fn_8004AF74(res,M2C_FIELD(M2C_FIELD(arg0,void **,0x190),u8 *,8))) {
 res=get_4F128_resource(arg0,get_4F128_id(arg0));
 switch(M2C_FIELD(M2C_FIELD(arg0,void **,0x190),u8 *,8)) {
 case 0: res=fn_8004B078(res,0);break;
case 1: res=fn_8004B078(res,1);break;
case 2: res=fn_8004B078(res,2);break;
case 3: res=fn_8004B078(res,3);break;
default: res=fn_8004B078(res,0);break;
 }
 if(!res||fn_8005C144(res)==0x8000U) res=lbl_80366DC8;
 if(res!=lbl_80366DC8&&!fn_8005BA10(res))return 0;
 }
 return 1;
}

static inline s32 get_4F5EC_id(void *arg0) {
 void *fn_80037D54(void *);
 s32 fn_8004ABD4(void *,s32);
 s32 value=M2C_FIELD(arg0,s8 *,0x16C);
 if(value>=0) return value;
 return fn_8004ABD4(fn_80037D54(arg0),0);
}
static inline void *get_4F5EC_resource(void *arg0) {
 void fn_800056A0(s32);
 void DebugPrint(void *, ...);
 void *Res_GetByName(void *);
 void *fn_80037D54(void *);
 s32 fn_8004ABD4(void *,s32);
 u8 fn_8004AF74(void *,u8);
 void *fn_8004B078(void *,s32);
 void *fn_8004B158(void *);
 s32 fn_8004B1A0(s32);
 u16 fn_8005C144(void *);
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
 if(fn_8005C144(buf)==0x8000U) {
 DebugPrint(lbl_8026AB18+0x67,buf);
 return Res_GetByName(lbl_8026AB18+0x53);
 }
 return resolved;
}
void fn_8004F5EC(void *arg0,u32 arg1) {
#pragma opt_common_subs off
 void fn_800056A0(s32);
 void DebugPrint(void *, ...);
 void *Res_GetByName(void *);
 void *fn_80037D54(void *);
 s32 fn_8004ABD4(void *,s32);
 u8 fn_8004AF74(void *,u8);
 void *fn_8004B078(void *,s32);
 void *fn_8004B158(void *);
 s32 fn_8004B1A0(s32);
 u16 fn_8005C144(void *);
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
 res=get_4F5EC_resource(arg0);
 switch(M2C_FIELD(M2C_FIELD(arg0,void **,0x190),u8 *,8)) {
 case 0: res=fn_8004B078(res,0);break;
case 1: res=fn_8004B078(res,1);break;
case 2: res=fn_8004B078(res,2);break;
case 3: res=fn_8004B078(res,3);break;
default: res=fn_8004B078(res,0);break;
 }
 if(!res||fn_8005C144(res)==0x8000U) res=lbl_80366DC8;
 if(res!=lbl_80366DC8) fn_8005C870(res,arg1);
 }
 M2C_FIELD(arg0,u8 *,3)|=1;
 }
}

s32 fn_8004FA88(void *arg0) {
    s32 *temp_r3 = (s32 *) arg0;
    if (temp_r3[0] == 0x1000) {
        return 0x5C;
    }
    if (temp_r3[0] == 0x4B03) {
        if (*((u8 *) temp_r3 + 0x4) != 0) {
            return 0x60;
        }
    } else {
        if (temp_r3[0] == 0x4B07) {
            return 0x5E;
        }
    }

    return 0x5A;
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
void fn_8004FE98(s32 arg0, s8 arg1) {
    extern u8 lbl_8026AB18[];
    Unit *unit = (Unit *)arg0;
    Unk18CObj *var_r27;
    Unk18CObj *var_r26;
    s32 var_r30;
    s32 var_r27_2;
    s8 var_r28;
    s8 var_r3_3;
    void *var_r30_2;
    void *var_r27_3;
    void *var_r3_2;
    void *var_r3_5;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;
    void *temp_r30;
    u8 sp28[0x20];
    u8 sp8[0x20];

    if (unit->unk3 & 2) {
        var_r28 = unit->unk16C;
        if (var_r28 < 0) {
            var_r28 = (s8)fn_8004ABD4((void **)fn_80037D54((void *)arg0), 0);
        }
        var_r27 = unit->unk18C;
        if (unit->unk3 & 4) {
            void *tmp;
            tmp = var_r27->unkC ? Res_GetByName((s32)var_r27) : NULL;
            var_r27 = tmp;
        }
        var_r30 = 0;
        if (Status_Test((u8 *)arg0 + 0x1BC, 8)) {
            if (Status_Test((u8 *)var_r27 + 0x1C, 9)) {
                var_r30 = 1;
            }
        } else if (Status_Test((u8 *)var_r27 + 0x1C, 2)) {
            var_r30 = 1;
        }
        var_r30_2 = *(void **)((u8 *)unit->unk188 + var_r30 * 4 + 0x5C);
        if (var_r30_2 == NULL) {
            var_r30_2 = var_r27->unk18;
        }
        if (var_r30_2 == NULL) {
            fn_800056A0(0);
            var_r30_2 = (u8 *)(lbl_8026AB18 + 0x52);
        }
        if (var_r30_2 == NULL || *(s8 *)var_r30_2 == 0) {
            var_r3_2 = Res_GetByName((s32)(lbl_8026AB18 + 0x53));
        } else {
            sprintf(sp28, (char *)(lbl_8026AB18 + 0x5F), var_r30_2, fn_8004B1A0(var_r28));
            temp_r3 = Res_GetByName((s32)(void *)sp28);
            if (temp_r3 == NULL) {
                fn_800056A0(0);
                var_r3_2 = Res_GetByName((s32)(lbl_8026AB18 + 0x53));
            } else {
                sprintf(sp28, (char *)(lbl_8026AB18 + 0x64), fn_8004B158((void *)arg0));
                if ((u16)fn_8005C144(sp28) == 0x8000U) {
                    DebugPrint((char *)(lbl_8026AB18 + 0x67), sp28);
                    var_r3_2 = Res_GetByName((s32)(lbl_8026AB18 + 0x53));
                } else {
                    var_r3_2 = temp_r3;
                }
            }
        }
        unit->unk17C = var_r3_2;
        temp_r30 = (u8 *)arg0 + 0x1C;
        var_r3_3 = unit->unk16C;
        if (var_r3_3 < 0) {
            var_r3_3 = (s8)fn_8004ABD4((void **)fn_80037D54((void *)arg0), 0);
        }
        var_r26 = unit->unk18C;
        if (unit->unk3 & 4) {
            void *tmp;
            tmp = var_r26->unkC ? Res_GetByName((s32)var_r26) : NULL;
            var_r26 = tmp;
        }
        var_r27_2 = 0;
        if (Status_Test((u8 *)arg0 + 0x1BC, 8)) {
            if (Status_Test((u8 *)var_r26 + 0x1C, 9)) {
                var_r27_2 = 1;
            }
        } else if (Status_Test((u8 *)var_r26 + 0x1C, 2)) {
            var_r27_2 = 1;
        }
        var_r27_3 = *(void **)((u8 *)unit->unk188 + var_r27_2 * 4 + 0x5C);
        if (var_r27_3 == NULL) {
            var_r27_3 = var_r26->unk18;
        }
        if (var_r27_3 == NULL) {
            fn_800056A0(0);
            var_r27_3 = (u8 *)(lbl_8026AB18 + 0x52);
        }
        if (var_r27_3 == NULL || *(s8 *)var_r27_3 == 0) {
            var_r3_5 = Res_GetByName((s32)(lbl_8026AB18 + 0x53));
        } else {
            sprintf(sp8, (char *)(lbl_8026AB18 + 0x5F), var_r27_3, fn_8004B1A0(var_r3_3));
            temp_r3_2 = Res_GetByName((s32)(void *)sp8);
            if (temp_r3_2 == NULL) {
                fn_800056A0(0);
                var_r3_5 = Res_GetByName((s32)(lbl_8026AB18 + 0x53));
            } else {
                sprintf(sp8, (char *)(lbl_8026AB18 + 0x64), fn_8004B158((void *)arg0));
                if ((u16)fn_8005C144(sp8) == 0x8000U) {
                    DebugPrint((char *)(lbl_8026AB18 + 0x67), sp8);
                    var_r3_5 = Res_GetByName((s32)(lbl_8026AB18 + 0x53));
                } else {
                    var_r3_5 = temp_r3_2;
                }
            }
        }
        temp_r3_3 = (void *)0xDEADBEEF;
        if (temp_r3_3 != 0) {
            fn_8005FA14(temp_r30, 1);
            fn_8005F5B4(temp_r30, temp_r3_3);
            unit->unk2 = arg1;
        }
    }
}
#pragma use_lmw_stmw reset
void fn_800504FC(void *arg0) {
    s32 fn_8004B1A0(s32);
    
    s32 temp_r3 = fn_8004B1A0(0);
    if (temp_r3 != 0) {
        M2C_FIELD(arg0, s32 *, 0x280) = temp_r3;
        M2C_FIELD(arg0, s32 *, 0x284) = fn_8004B1A0(1);
        M2C_FIELD(arg0, s32 *, 0x288) = fn_8004B1A0(2);
        M2C_FIELD(arg0, s32 *, 0x28C) = fn_8004B1A0(3);
    }
}

void fn_800508C4(void* arg0, s32 arg1, s32 arg2) {
    u8 zero = 0;
    
    if (arg2 == 0) {
        M2C_FIELD(arg0, u8 *, 0xA) = zero;
        M2C_FIELD(arg0, u8 *, 0x9) = zero;
        M2C_FIELD(arg0, u8 *, 0xB) = zero;
    } else {
        s32 temp = *(u8*)((char*)arg0 + 0xA);
        if (temp < arg1) {
            M2C_FIELD(arg0, u8 *, 0xA) = arg1;
        }
        if (*(u8*)((char*)arg0 + 0x9) == 0) {
            if (arg2 >= 3) {
                M2C_FIELD(arg0, u8 *, 0x9) = 1;
            } else if (arg2 <= -3) {
                M2C_FIELD(arg0, u8 *, 0x9) = 2;
            }
        } else if (*(u8*)((char*)arg0 + 0x9) == 1) {
            if (arg2 >= 5) {
                M2C_FIELD(arg0, u8 *, 0x9) = 3;
            } else if (arg2 <= -5) {
                M2C_FIELD(arg0, u8 *, 0x9) = 4;
            }
        } else if (*(u8*)((char*)arg0 + 0x9) == 2) {
            if (arg2 >= 5) {
                M2C_FIELD(arg0, u8 *, 0x9) = 3;
            } else if (arg2 <= -5) {
                M2C_FIELD(arg0, u8 *, 0x9) = 4;
            }
        } else if (*(u8*)((char*)arg0 + 0x9) == 3) {
            if (arg2 >= 7) {
                M2C_FIELD(arg0, u8 *, 0x9) = 5;
            } else if (arg2 <= -7) {
                M2C_FIELD(arg0, u8 *, 0x9) = 6;
            }
        } else if (*(u8*)((char*)arg0 + 0x9) == 4) {
            if (arg2 >= 7) {
                M2C_FIELD(arg0, u8 *, 0x9) = 5;
            } else if (arg2 <= -7) {
                M2C_FIELD(arg0, u8 *, 0x9) = 6;
            }
        } else if (*(u8*)((char*)arg0 + 0x9) == 5) {
            if (arg2 >= 9) {
                M2C_FIELD(arg0, u8 *, 0x9) = 7;
            } else if (arg2 <= -9) {
                M2C_FIELD(arg0, u8 *, 0x9) = 8;
            }
        } else if (*(u8*)((char*)arg0 + 0x9) == 6) {
            if (arg2 >= 9) {
                M2C_FIELD(arg0, u8 *, 0x9) = 7;
            } else if (arg2 <= -9) {
                M2C_FIELD(arg0, u8 *, 0x9) = 8;
            }
        }
    }
}

#pragma global_optimizer off
void *fn_80050AB8(void *arg0) {
    void fn_800056A0(s32);
    void *Res_GetByName(void *);
    u8 Status_Test(void *, s32);
    extern u8 lbl_8026AB18[];
    void *result;
    void *base;
    s32 idx;
    void *r;
    u32 tmp;

    r = *(void **)((u8 *)arg0 + 0x18C);
    base = r;
    if (*(u8 *)((u8 *)arg0 + 3) & 4) {
        r = *(void **)((u8 *)r + 0xC);
        if (r != 0) {
            r = Res_GetByName(r);
        } else {
            r = 0;
        }
        base = r;
    }
    idx = 0;
    if (Status_Test((u8 *)arg0 + 0x1BC, 8) != 0) {
        if (Status_Test((u8 *)base + 0x1C, 9) != 0) {
            idx = 1;
        }
    } else if (Status_Test((u8 *)base + 0x1C, 2) != 0) {
        idx = 1;
    }
    result = *(void **)((u8 *)arg0 + 0x188);
    result = (void *)((u8 *)result + (idx * 4));
    tmp = *(u32 *)((u8 *)result + 0x5C);
    result = (void *)tmp;
    if (tmp == 0) {
        result = *(void **)((u8 *)base + 0x18);
    }
    if (result == 0) {
        fn_800056A0(0);
        result = lbl_8026AB18 + 0x52;
    }
    return result;
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
    extern s32 lbl_802858E8[];
    s32 sp8;
    void *r31;

    r31 = (u8 *)arg0 + 0x1c;
    sp8 = lbl_802858E8[arg1];
    Model_SetColor(r31, ((u8 *)&sp8)[0], ((u8 *)&sp8)[1], ((u8 *)&sp8)[2]);
    Model_SetAlpha(r31, ((u8 *)&sp8)[3]);
}

void fn_80050C50(void *arg0, f32 farg0, f32 farg1) {
    f32 fn_80023430(void *);
    extern u8 gBattleMap[];

    *(f32 *)((u8 *)arg0 + 4) = farg0;
    *(f32 *)((u8 *)arg0 + 8) = farg1;
    *(f32 *)((u8 *)arg0 + 0xC) = fn_80023430(gBattleMap);
}

#pragma peephole off
void fn_80050E14(void)
{
    extern u8 *lbl_803672CC;
    s32 i;
    s32 offset;
    s32 tableOffset;
    s32 n;
    u8 *obj;
    u8 *table;
    u8 *base;

    obj = lbl_803672CC;
    if (obj == 0) {
        return;
    }

    i = 0;
    *(s32 *)(obj + 0x14) = i;
    offset = i;
    tableOffset = i;

    for (; i < (n = *(s32 *)(obj + 0x18)); ) {
        base = *(u8 **)obj;
        i += 1;
        table = *(u8 **)(obj + 4);
        *(u32 *)(table + tableOffset) = (u32)base + offset;
        offset += 0x14;
        tableOffset += 4;
    }

    table = *(u8 **)(obj + 4);
    *(u32 *)(table + (n * 4)) = 0;
    *(void **)(obj + 8) = *(void **)(obj + 4);
    *(s32 *)(obj + 0xC) = 0;
    *(s32 *)(obj + 0x10) = 0;
}
#pragma peephole on
void fn_80050E80(void)
{
    void fn_800162B8(void);
    void fn_800616A0(void *);
    void fn_800C4588(void *);
    void fn_800C426C(void *);
    void Heap_Free(void *);
    void fn_8006D8E8(void *);
    extern u8 lbl_802EFFE8[];
    extern void *lbl_803672B8;
    extern void *lbl_803672B4;
    extern void *lbl_803672CC;
    extern void *gUnitShadowMat;
    void *p;
    s32 i;
    void *a;
    void *b;

    fn_800162B8();
    i = 0;
    p = lbl_802EFFE8;
    do {
        fn_800616A0(p);
        i += 1;
        p = (u8 *)p + 0xA0;
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
    p = lbl_803672CC;
    lbl_803672B4 = 0;
    if (p != 0 && p != 0) {
        a = *(void **)p;
        if (a != 0) {
            if (a != 0) {
                fn_800C426C((u8 *)a - 0x10);
            }
            *(void **)p = 0;
        }
        a = *(void **)((u8 *)p + 4);
        if (a != 0) {
            fn_800C426C(a);
            *(void **)((u8 *)p + 4) = 0;
        }
        Heap_Free(p);
    }
    b = gUnitShadowMat;
    lbl_803672CC = 0;
    fn_8006D8E8(b);
}

#pragma global_optimizer off
void fn_80050F64(void) {
    void *fn_8006D948(void *);
    void *Heap_Alloc(s32);
    void *fn_800C42AC(s32);
    void *fn_8022C414(void *, void (*)(void *, s32), void *, s32, s32);
    void DCFlushRange(void *, u32);
    void *fn_80222420(s32, s32, s32, s32, s32);
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
    extern void *gUnitShadowMat;
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

    gUnitShadowMat = fn_8006D948(lbl_8026AB18 + 0x95);
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
    *(s32 *)(a + 0) = (s32)fn_8022C414(fn_800C42AC(b + 0x10),
                    (void (*)(void *, s32))fn_80052B44, NULL, 0x14, c);
    *(s32 *)(a + 4) = (s32)fn_800C42AC((*(s32 *)(a + 0x18) + 1) * 4);
    DCFlushRange((void *)*(s32 *)(a + 0), (u32)b);
    DCFlushRange((void *)*(s32 *)(a + 4),
                 (u32)((*(s32 *)(a + 0x18) + 1) * 4));

    {
        s32 i = 0;
        s32 off;
        s32 idx;
        *(s32 *)(a + 0x14) = i;
        off = i;
        idx = i;
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

    lbl_803672B4 = fn_800C45B8(fn_80222420(0x260, 0x1C0, 0x27, 0, 0),
                               lbl_8026AB18 + 0x52, 0);
    lbl_803672B8 = fn_800C45B8(fn_80222420(0xA0, 0x78, 0, 0, 0),
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
        u8 id = 1;
        s32 ctr = 0x9F;
        void *unit;
        do {
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
                *(f32 *)((u8 *)unit + 0x170) = lbl_80368FCC;
                *(f32 *)((u8 *)unit + 0x174) = lbl_80368FCC;
                *(f32 *)((u8 *)unit + 0x178) = lbl_80368FCC;
                *(s32 *)((u8 *)unit + 0x17C) = z;
            }
            id += 1;
        } while (--ctr);
    }

    lbl_803672BC = 1;
}
#pragma global_optimizer reset

void fn_80051328(u8 arg0, M2C_UNK *arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    M2C_UNK PSMTXConcat(M2C_UNK *, M2C_UNK *, M2C_UNK *);
    M2C_UNK PSMTXRotRad(M2C_UNK *, M2C_UNK, f32);
    M2C_UNK PSMTXTrans(M2C_UNK *, f32, f32, f32);
    M2C_UNK fn_802026E4(M2C_UNK *, f32 *, s32 *, f32 *);
    M2C_UNK C_MTXLightOrtho(M2C_UNK *, f32, f32, f32, f32, f32, f32, f32, f32);
    M2C_UNK fn_802029C4(M2C_UNK *, s32 *, s32 *);
    extern M2C_UNK lbl_8026AA98;
    extern f32 lbl_80368FC4;
    extern f32 lbl_80368FCC;
    extern f32 lbl_80368FD8;
    extern f32 lbl_80368FDC;
    M2C_UNK spD4;
    M2C_UNK spA4;
    M2C_UNK sp74;
    M2C_UNK sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    s32 sp34;
    f32 sp30;
    f32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;

    sp2C = M2C_FIELD(&lbl_8026AA98, f32 *, 0x1C);
    sp30 = M2C_FIELD(&lbl_8026AA98, f32 *, 0x20);
    sp38 = M2C_FIELD(&lbl_8026AA98, f32 *, 0x28);
    sp3C = M2C_FIELD(&lbl_8026AA98, f32 *, 0x2C);
    sp2C = farg0;
    sp30 = farg1;
    sp38 = farg0;
    sp3C = farg1;
    sp34 = M2C_FIELD(&lbl_8026AA98, s32 *, 0x24);
    sp8 = sp2C;
    spC = sp30;
    sp10 = M2C_FIELD(&lbl_8026AA98, s32 *, 0x24);
    sp40 = M2C_FIELD(&lbl_8026AA98, s32 *, 0x30);
    sp14 = sp38;
    sp18 = sp3C;
    sp1C = M2C_FIELD(&lbl_8026AA98, s32 *, 0x30);
    sp20 = M2C_FIELD(&lbl_8026AA98, s32 *, 0x34);
    sp24 = M2C_FIELD(&lbl_8026AA98, s32 *, 0x38);
    sp28 = M2C_FIELD(&lbl_8026AA98, s32 *, 0x3C);
    if (lbl_80368FCC != farg4) {
        PSMTXRotRad(&spA4, 0x5A, lbl_80368FD8 * farg4);
        if (arg0 == 0) {
            fn_802029C4(&spA4, &sp20, &sp20);
        }
        fn_802026E4(&sp74, &sp14, &sp20, &sp8);
        C_MTXLightOrtho(&sp44, -farg2, farg2, -farg3, farg3, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
        PSMTXConcat(&sp44, &sp74, arg1);
        PSMTXTrans(&spD4, lbl_80368FDC, lbl_80368FDC, lbl_80368FCC);
        PSMTXConcat(&spA4, &spD4, &spA4);
        PSMTXTrans(&spD4, lbl_80368FC4, lbl_80368FC4, lbl_80368FCC);
        PSMTXConcat(&spD4, &spA4, &spA4);
        PSMTXConcat(&spA4, arg1, arg1);
        return;
    }
    fn_802026E4(&sp74, &sp14, &sp20, &sp8);
    C_MTXLightOrtho(&sp44, -farg2, farg2, -farg3, farg3, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4, lbl_80368FC4);
    PSMTXConcat(&sp44, &sp74, arg1);
}

void fn_80051538(s32 *arg0) {
    M2C_UNK fn_80051564(s32 *);
    s32 sp8;

    sp8 = *arg0;
    fn_80051564(&sp8);
}

void fn_80051564(u32 *arg0, u8 arg1, f32 fx, f32 fy) {
    void GXBegin(s32, s32, s32);
    f32 Map_GetTileCornerHeight(void *, s8, s8, s32);
    extern s32 gBattleMap[];
    extern f32 lbl_8036904C;
    extern f32 lbl_80369050;
    volatile f32 *wgpipe = (volatile f32 *)0xCC008000;
    u32 color;
    s32 x;
    s32 y;
    f32 z;
    u8 r, g, b, a;

    color = *arg0;
    x = (s32)fx;
    y = (s32)fy;
    if (x < 0 || y < 0 || x >= gBattleMap[0] || y >= gBattleMap[1]) {
        return;
    }
    if (arg1 != 0 && *(((u8 *)gBattleMap) + x + (y << 6) + 0x100D) == 0x1A) {
        return;
    }
    GXBegin(0x98, 0, 4);
    z = Map_GetTileCornerHeight(gBattleMap, (s8)x, (s8)y, 0);
    r = ((u8 *)&color)[0];
    g = ((u8 *)&color)[1];
    b = ((u8 *)&color)[2];
    a = ((u8 *)&color)[3];
    wgpipe[0] = (f32)x;
    wgpipe[0] = (f32)y;
    wgpipe[0] = z;
    *(volatile u8 *)wgpipe = r;
    *(volatile u8 *)wgpipe = g;
    *(volatile u8 *)wgpipe = b;
    *(volatile u8 *)wgpipe = a;
    (void)lbl_8036904C;
    (void)lbl_80369050;
}

s32 fn_80052B30(s32 arg0) {
    extern s32 lbl_802858E8[];
    return lbl_802858E8[arg0];
}

void fn_80052B44(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
}

void fn_80052B54(void *arg0) {
    void **temp_r31;
    void *temp_r30;
    
    if (arg0 == 0) {
        return;
    }
    temp_r31 = (void **)((char *)arg0 + 0x30);
    if (*temp_r31 == 0) {
        return;
    }
    temp_r30 = *(void **)((char *)arg0 + 0x34);
    *(s32 *)((char *)temp_r30 + 0x30) = 0x0;
    
    *(f32 *)((char *)*temp_r31 + 0xc) = *(f32 *)0x80369084;
    *(f32 *)((char *)*temp_r31 + 0x10) = *(f32 *)0x80369084;
    *(f32 *)((char *)*temp_r31 + 0x14) = *(f32 *)0x80369084;
    *(s16 *)((char *)*temp_r31 + 0x0) = 0x0;
    *(s8 *)((char *)*temp_r31 + 0x3) = -0x1;
    *(s8 *)((char *)*temp_r31 + 0x4) = -0x1;
    *(s32 *)((char *)*temp_r31 + 0x30) = 0x0;
    *(s32 *)((char *)*temp_r31 + 0x34) = 0x0;
    *(s32 *)((char *)*temp_r31 + 0x3c) = 0x0;
    *(s32 *)((char *)*temp_r31 + 0x40) = 0x0;
    *(s32 *)((char *)*temp_r31 + 0x44) = 0x0;
    *(s32 *)((char *)*temp_r31 + 0x8) = 0x0;
    *(s32 *)((char *)*temp_r31 + 0x5c) = 0x0;
    *(s32 *)((char *)*temp_r31 + 0x48) = 0x0;
    
    *(s32 *)((char *)arg0 + 0x8) = *(s32 *)0x80369080;
    *(s8 *)((char *)arg0 + 0x8) = *(s8 *)((char *)arg0 + 0x8);
    *(s8 *)((char *)arg0 + 0x9) = *(s8 *)((char *)arg0 + 0x9);
    *(s8 *)((char *)arg0 + 0x38) = *(s8 *)((char *)arg0 + 0x8);
    *(s8 *)((char *)arg0 + 0xa) = *(s8 *)((char *)arg0 + 0xa);
    *(s8 *)((char *)arg0 + 0x39) = *(s8 *)((char *)arg0 + 0x9);
    *(s8 *)((char *)arg0 + 0xb) = *(s8 *)((char *)arg0 + 0xb);
    *(s8 *)((char *)arg0 + 0x3a) = *(s8 *)((char *)arg0 + 0xa);
    *(s8 *)((char *)arg0 + 0x3b) = *(s8 *)((char *)arg0 + 0xb);
    
    *(s32 *)((char *)*temp_r31 + 0x2c) = 0x0;
    *(f32 *)((char *)*temp_r31 + 0x20) = *(f32 *)0x80369084;
    *(f32 *)((char *)*temp_r31 + 0x24) = *(f32 *)0x80369084;
    *(f32 *)((char *)*temp_r31 + 0x28) = *(f32 *)0x80369084;
    *(f32 *)((char *)*temp_r31 + 0x1c) = *(f32 *)0x80369088;
    *(f32 *)((char *)*temp_r31 + 0x18) = *(f32 *)0x8036908C;
    *(s8 *)((char *)*temp_r31 + 0x5) = 0x3;
    *(s32 *)((char *)*temp_r31 + 0x4c) = 0x0;
    *(s32 *)((char *)*temp_r31 + 0x50) = 0x0;
    *(s32 *)((char *)*temp_r31 + 0x54) = 0x0;
    *(s32 *)((char *)*temp_r31 + 0x58) = 0x0;
    
    *(s32 *)((char *)*temp_r31 + 0x8) |= 0x800;
    *(s32 *)((char *)*temp_r31 + 0x8) |= 0x2000;
}

void fn_80052EBC(u8 *arg0) {
    f32 Math_Lerp(f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern f32 lbl_8036908C;
    f32 temp_f30;
    f32 temp_f31;
    f32 temp_f1;
    u8 *temp_r4;

    *(f32 *)(arg0 + 0x50) = *(f32 *)(arg0 + 0x50) + lbl_8036908C;
    temp_f30 = Math_Lerp(*(f32 *)(arg0 + 0x34), *(f32 *)(arg0 + 0x40), *(f32 *)(arg0 + 0x4C), *(f32 *)(arg0 + 0x50));
    temp_f31 = Math_Lerp(*(f32 *)(arg0 + 0x38), *(f32 *)(arg0 + 0x44), *(f32 *)(arg0 + 0x4C), *(f32 *)(arg0 + 0x50));
    temp_f1 = Math_Lerp(*(f32 *)(arg0 + 0x3C), *(f32 *)(arg0 + 0x48), *(f32 *)(arg0 + 0x4C), *(f32 *)(arg0 + 0x50));
    temp_r4 = *(u8 **)(arg0 + 0x30);
    *(f32 *)(*(u8 **)(temp_r4 + 0x30) + 0xC) = temp_f30;
    *(f32 *)(*(u8 **)(temp_r4 + 0x30) + 0x10) = temp_f31;
    *(f32 *)(*(u8 **)(temp_r4 + 0x30) + 0x14) = temp_f1;
    if (*(f32 *)(arg0 + 0x50) >= *(f32 *)(arg0 + 0x4C)) {
        Process_ClearFunc(arg0);
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
    f32 Math_Angle2D(f32, f32, f32, f32);
    extern f32 lbl_8036909C;
    void *temp_r3;
    f32 *var_r4;
    f32 x;
    f32 y;
    f32 z;

    if (arg1 != NULL && arg2 != NULL) {
        *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x24) =
            Math_Angle2D(arg1[0], arg1[1], arg2[0], arg2[1]);
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
        z = lbl_8036909C + z;
        *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x10) = y;
        *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x14) = z;
    }
}

void fn_8005306C(void *arg0) {
    f32 fn_80023430(M2C_UNK *, f32, f32, f32);
    f32 Math_Angle2D(f32, f32, f32, f32);
    extern M2C_UNK gBattleMap;
    extern f32 lbl_80369098;
    extern f32 lbl_8036909C;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 *var_r30;
    f32 *var_r31;
    f32 *var_r3;
    f32 temp_f3;
    f32 temp_f3_2;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r0_3;
    u8 temp_r0_4;
    void *temp_r29;
    void *temp_r3;
    void *temp_r4;
    void *temp_r5;

    var_r31 = NULL;
    var_r30 = NULL;
    temp_r3 = M2C_FIELD(arg0, void **, 0x30);
    temp_r5 = M2C_FIELD(temp_r3, void **, 0x34);
    temp_r29 = M2C_FIELD(temp_r3, void **, 0x30);
    if (temp_r5 != NULL) {
        temp_r0 = M2C_FIELD(temp_r5, u8 *, 0x19E);
        sp14 = lbl_80369098 + (f32) (s8) temp_r0;
        temp_r0_2 = M2C_FIELD(temp_r5, u8 *, 0x19F);
        temp_f3 = lbl_80369098 + (f32) (s8) temp_r0_2;
        sp18 = temp_f3;
        sp1C = fn_80023430(&gBattleMap, (f32) (s8) temp_r0, (f32) (s8) temp_r0_2, temp_f3);
        var_r31 = &sp14;
    }
    if (temp_r29 != NULL) {
        temp_r0_3 = M2C_FIELD(temp_r29, u8 *, 0x19E);
        sp8 = lbl_80369098 + (f32) (s8) temp_r0_3;
        temp_r0_4 = M2C_FIELD(temp_r29, u8 *, 0x19F);
        temp_f3_2 = lbl_80369098 + (f32) (s8) temp_r0_4;
        spC = temp_f3_2;
        sp10 = fn_80023430(&gBattleMap, (f32) (s8) temp_r0_3, (f32) (s8) temp_r0_4, temp_f3_2);
        var_r30 = &sp8;
    }
    if ((var_r31 != NULL) && (var_r30 != NULL)) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x24) = Math_Angle2D(M2C_FIELD(var_r31, f32 *, 0), M2C_FIELD(var_r31, f32 *, 4), M2C_FIELD(var_r30, f32 *, 0), M2C_FIELD(var_r30, f32 *, 4));
    }
    temp_r4 = M2C_FIELD(arg0, void **, 0x30);
    if ((M2C_FIELD(temp_r4, s32 *, 8) & 0x20000000) && (var_r31 != NULL)) {
        var_r3 = var_r31;
    } else {
        var_r3 = var_r30;
    }
    if (var_r3 != NULL) {
        M2C_FIELD(temp_r4, f32 *, 0xC) = (f32) M2C_FIELD(var_r3, f32 *, 0);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x10) = (f32) M2C_FIELD(var_r3, f32 *, 4);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x14) = (f32) (lbl_8036909C + M2C_FIELD(var_r3, f32 *, 8));
    }
}

#pragma use_lmw_stmw on
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
    void fn_8014746C(s8, s32);
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
                    fn_8014746C(slot, 0xFA);
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

void fn_80053680(void *arg0, void *arg1) {
    extern f32 lbl_8036909C;
    f32 z;
    f32 y;
    f32 x;
    z = *(f32 *)((char *)arg1 + 0xC);
    y = *(f32 *)((char *)arg1 + 0x8);
    x = *(f32 *)((char *)arg1 + 0x4);
    *(f32 *)((char *)*(void **)((char *)arg0 + 0x30) + 0xC) = x;
    z = lbl_8036909C + z;
    *(f32 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x10) = y;
    *(f32 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x14) = z;
}

void fn_800536B0(void *arg0, f32 farg0, f32 farg1, f32 farg2) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0xC) = farg0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x10) = farg1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x14) = farg2;
}

void fn_800536CC(void *arg0, s32 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x34) = arg1;
}

void fn_800536D8(void *arg0, s32 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x30) = arg1;
}

void fn_800536E4(void *arg0, void *arg1) {
    if ((u32) M2C_FIELD(arg0, u32 *, 0x18) == (u32) M2C_FIELD(arg1, u32 *, 0)) {
        M2C_FIELD(arg1, void **, 4) = arg0;
    }
}

void *fn_800536FC(u16 arg0) {
    void fn_80053750(void *, void *);
    void fn_8000A388(void *, void *, void *);
    extern u8 lbl_80285990[];
    struct {
        u16 value;
        u16 padding;
        void *result;
    } data;

    data.value = arg0;
    data.result = NULL;
    fn_8000A388(lbl_80285990, fn_80053750, &data);
    if (data.result != NULL) {
        return data.result;
    }
    return NULL;
}

void fn_80053750(void *arg0, void *arg1) {
    if ((u16) M2C_FIELD(arg1, u16 *, 0) == (u16) *M2C_FIELD(arg0, u16 **, 0x30)) {
        M2C_FIELD(arg1, void **, 4) = arg0;
    }
}

void fn_8005376C(void) {
    u32 Process_Find(u32 *);
    void *Process_UnlinkByKey(u32 *);
    void *Process_Create(void *, s32);
    s32 fn_801451BC(void);
    u8 fn_80145308(void);
    void DebugPrint(const char *, ...);
    void *temp_r3;

    extern u32 lbl_80285990[];
    extern u8 GActor_str[];
    extern u8 lbl_80285968[];

    Process_UnlinkByKey(lbl_80285990);
    if ((Process_Find(lbl_80285990) == 0U) && (fn_80145308() == 0)) {
        fn_801451BC();
        DebugPrint((const char *)((u8 *) &GActor_str + 0x12E));
        return;
    }
    temp_r3 = Process_Create(lbl_80285968, 4);
    *(s32 *)((u8 *) temp_r3 + 0x60) = 0;
}
#pragma cplusplus reset
s32 fn_800537E8(void) {
    extern u16 lbl_80285990[];
    s32 v = Process_Find(lbl_80285990);
    return v != 0;
}

void fn_80053D84(void *arg0) {
    void *temp_r3;

    temp_r3 = M2C_FIELD(arg0, void **, 0x30);
    M2C_FIELD(temp_r3, s32 *, 8) = (s32) (M2C_FIELD(temp_r3, s32 *, 8) | 0x80000000);
}

void fn_80053D98(void* arg0, s32 arg1) {
    u16* r3;
    void* temp_r3;
    s32 var_r7;
    
    r3 = (u16*)((u8*)arg0 + 0x60);
    var_r7 = *(u8*)r3;
    *r3 += 1;
    
    temp_r3 = (u8*)arg0 + 0x20;
    r3 = (u16*)((u8*)temp_r3 + (var_r7 * 2));
    *r3 |= 0x8000;
    
    temp_r3 = (u8*)arg0 + 0x20;
    r3 = (u16*)((u8*)temp_r3 + ((var_r7 + arg1) * 2));
    *r3 |= 0x4000;
}

void fn_80053E9C(void *arg0) {
    void fn_800616A0(void *);
    void sprintf(void *, void *, ...);
    void fn_8005C7C8(void *);
    void fn_800C4588(void *);
    extern u8 GActor_str[];
    char sp8[0x40];
    void *temp;

    temp = *(void **)((u8 *)arg0 + 0x5C);
    if (temp != NULL) {
        fn_800616A0(temp);
        sprintf(sp8, GActor_str + 0x120, GActor_str + 0x129,
                    **(void ***)((u8 *)arg0 + 0x2C));
        fn_8005C7C8(sp8);
    }
    fn_800C4588(arg0);
}

void fn_80053F08(void *arg0) {
    void fn_800536E4(void *, void *);
    void fn_8000A388(void *, void *, void *);
    void Process_ClearFunc(void *);
    extern u8 lbl_80285990[];
    struct {
        void *value;
        void *result;
    } data;

    data.value = arg0;
    data.result = NULL;
    fn_8000A388(lbl_80285990, fn_800536E4, &data);
    if (data.result == NULL) {
        Process_ClearFunc(arg0);
    }
}

#pragma use_lmw_stmw on
void fn_80053F68(void *arg0) {
    f32 Math_Lerp(f32, f32, f32, f32);
    void Model_SetColor(void *, u8, u8, u8);
    void Model_SetAlpha(void *, u8);
    void fn_8005E644(void *);
    void fn_80060060(void *);
    void fn_800609DC(void *);
    void fn_8006CAD4(void *);
    void Process_ClearFunc(void *);
    void MapObj_UpdateMatrix(void *);
    void fn_800548E8(void *);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_SetColorByte(u8);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Prim2D_AddPrim(s32);
    void fn_80007340(void *, void *);
    void Prim2D_EndPrim(void);
    u8 fn_800AA188(void);
    extern f32 lbl_80369084;
    extern f32 lbl_8036908C;
    extern f64 lbl_80369090;
    extern f32 lbl_803690C4;
    extern f32 lbl_803690C8;
    extern void fn_80054314;

    typedef struct { f32 x, y, z; } Vec3;
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
    u32 fl;
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
        if ((((fl = *(u32 *)((u8 *)inner + 8)) >> 28) & 1) &&
            (other = *(void **)((u8 *)arg0 + 0x18)) != 0) {
            *(u32 *)((u8 *)inner + 8) = fl | 0x10000000;
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

        dst = *(void **)((u8 *)arg0 + 0x30);
        alpha = 0xFF;
        cnt = *(s8 *)((u8 *)dst + 3);
        if (cnt > 0) {
            *(s8 *)((u8 *)dst + 3) = (s8)(cnt - 1);
            dst = *(void **)((u8 *)arg0 + 0x30);
            alpha = (s32)Math_Lerp(lbl_80369084, lbl_803690C4, lbl_803690C8,
                                     (f32)*(s8 *)((u8 *)dst + 3));
            if (alpha == 0) {
                Process_ClearFunc(arg0);
            }
        }

        color = *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x38);
        Model_SetColor(gfx, ((u8 *)&color)[0], ((u8 *)&color)[1], ((u8 *)&color)[2]);
        Model_SetAlpha(gfx, (u8)((((u8 *)&color)[3] * alpha) / 255));
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
            MapObj_UpdateMatrix(arg0);
        }

        fn_800609DC(gfx);

        inner = *(void **)((u8 *)arg0 + 0x30);
        if ((*(u32 *)((u8 *)inner + 8) & 8) == 0 &&
            (*(u8 *)((u8 *)*(void **)((u8 *)inner + 0x2C) + 4) & 3) == 0) {
            fn_8006CAD4(gfx);
        } else {
            Prim2D_Begin();
            inner = *(void **)((u8 *)arg0 + 0x30);
            Prim2D_SetTransform(lbl_80369084, lbl_80369084,
                        (f32)(s32)*(f32 *)((u8 *)inner + 0x1C), lbl_8036908C);
            Prim2D_SetTex(0, 0x410);
            Prim2D_SetColorByte(0xFF);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(0xB);
            fn_80007340(&fn_80054314, gfx);
            Prim2D_EndPrim();
        }

        fn_800548E8(arg0);

        {
            void *p = *(void **)((u8 *)arg0 + 0x30);
            if ((*(u32 *)((u8 *)p + 8) & 4) == 0 && (*(u32 *)gfx & 0x10)) {
                b = ((u8 *)p)[4];
                if ((s8)b >= 0) {
                    ((u8 *)p)[4] = b - 1;
                } else {
                    Process_ClearFunc(arg0);
                }
            }
        }
    }
}
#pragma use_lmw_stmw reset

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

#pragma use_lmw_stmw on
/* Build map-object model node from path templates; optionally spawn a linked child object. */
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
 u8 fn_8005C3C4(void *);
 void GActor_Finalize(void *);
 void fn_8005EBCC(void *, u8);
 void *Process_Create(void *, void *);
 void *Heap_Alloc(s32);
 void *Res_GetByName(void *);
 void *fn_80060664(void *);
 u32 fn_800067B4(void);
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
sprintf(buf,GActor_str+353,GActor_str+0x129,M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void * *,0x30),void * *,0x2C),void * *,0)); if(fn_8005C3C4(buf)) GActor_LoadTpl(node,buf);
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
 rnd=fn_800067B4();
 quotient=rnd/range;
 rnd-=quotient*range;
 lo=M2C_FIELD(ref,s32 *,0x14);
 fn_8005FEE8(node,(f32)(s32)(lo+rnd));
 }
}
#pragma use_lmw_stmw reset

void fn_80054808(void *arg0) {
    M2C_UNK Process_ClearFunc(void *);
    u8 GActor_CheckResources(s32);
    if (GActor_CheckResources(*M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 **, 0x2C)) != 0) {
        Process_ClearFunc(arg0);
    }
}

void fn_80054850(void *arg0) {
    s64 OSGetTime(void);
    void Process_Goto(void *, s32);
    void fn_800555EC(s32, s32);
    u8 GActor_CheckResources(s32);
    s32 temp_r31;
    u32 flags;
    void *temp_r3;
    s32 var_r4;

    *(s64 *)((u8 *)arg0 + 0x38) = OSGetTime();
    temp_r3 = *(void **)((u8 *)arg0 + 0x30);
    flags = *(u32 *)((u8 *)temp_r3 + 8);
    temp_r31 = **(s32 **)((u8 *)temp_r3 + 0x2C);
    if ((flags >> 28) & 1) {
        Process_Goto(arg0, 0);
        return;
    }
    var_r4 = 0;
    if (flags & 0x100) {
        var_r4 = 8;
    }
    fn_800555EC(temp_r31, var_r4);
    if (GActor_CheckResources(temp_r31) != 0) {
        Process_Goto(arg0, 0);
    }
}

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

extern u16 *gMap;
#include "common.h"
#include "global.h"

extern u16 lbl_8026A660;
extern void* lbl_803672A8;
extern u8 gBattleMap[0x24F60];
extern u32* lbl_803672CC;
#include "global.h"
#include "common.h"

extern u32 jumptable_8028561C[];
extern u32 jumptable_802855E4[];
#include "global.h"
extern s32* gUnitShadowMat;
extern f32 lbl_80368FCC;
extern f32 gUnitShadowZ;
extern u16* gUnits;
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

void fn_8004781C(void *arg0) {
    // body of function will go here
}
#include "common.h"
extern f32 lbl_80368FD8;
extern u16 lbl_8026AB18;
extern f32 lbl_80368FC4;
extern u16 lbl_802EFE20;
