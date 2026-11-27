/* Functions from 0x801101D0 to 0x80120CC0, found by decomp-toolkit. */
#include "common.h"
#include "actor.h"
static inline s32 TalkUi_FindSlot20354(s32 want, void *object) {
    u8 *self = object;
    u8 *child;
    if (want < 0) return -1;
    child = *(u8 **)(self + 0x48);
    if (child && *(s8 *)(child + 0x43) == want) return 0;
    child = *(u8 **)(self + 0x4c);
    if (child && *(s8 *)(child + 0x43) == want) return 1;
    child = *(u8 **)(self + 0x50);
    if (child && *(s8 *)(child + 0x43) == want) return 2;
    child = *(u8 **)(self + 0x54);
    if (child && *(s8 *)(child + 0x43) == want) return 3;
    return -1;
}

typedef struct UiListRect { s32 x0, y0, x1, y1; } UiListRect;
extern u8 lbl_8032FE24[];
extern u16 gActorXmlStrs[];
extern u16 lbl_80296128[];
extern u8 lbl_80273DF8[];

typedef struct String {
    u32 size;
    u32 cap;
    char *data;
} String;

typedef struct Fn80116F84Args {
    s32 a;
    s32 b;
    s32 c;
} Fn80116F84Args;

extern f32 lbl_8036A1DC;
extern f32 fActorDefaultRadius;
extern f32 lbl_8036A1C8;
extern u16 lbl_8028F6C8[];
void String_Init(void *, char *, void *);
void String_Destroy(void *, s32);
void fn_800E6418(void *, s32, void *, s32, s32, void *);
void fn_800D6878(void *, void *, void *);
void String_AssignCStr(void *, char *, u32);
s32 String_Compare(void *, s32, void *, char *, s32);
s32 fn_800C9400(void *, u32, void *, char *, s32);
void fn_800C9ABC(void *, void *, void *);
void fn_800C96F8(void *, void *, u32);
void fn_800C9A60(void *, s32);
s32 String_Find(void *, char *, s32, s32);
u8 Actor_IsBusy(void *);
void Actor_LoadAnim(void *, void *, s32, s32, s32);
void fn_801134EC(void *, void *, void *);
void String_Assign(void *, void *, s32, s32);
void *String_CStr(void *);
extern u16 gUiPanelFlags;

extern s32 gUiInputFlags;

extern s32 gBattleState[];
extern f32 lbl_8036A184;
extern f32 lbl_8036A1BC;
extern f32 lbl_8036A1B0;
extern f64 lbl_8036A198;
extern f32 lbl_8036A1D8;
void fn_8005FEE8(void *, f32);
void fn_800608AC(void *);
void PSMTXRotRad(void *, s32, void *, f32, f32);
void fn_802029C4(void *, void *, void *);
#define VCALL(ptr, offset) (((void(**)(void *, void *))((u8*)(ptr) + (offset)))[0])

typedef struct {
    void *unk0;
    void *unk4;
    void *unk8;
    void *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
    void *unk28;
    void *unk2C;
    void *unk30;
    void *unk34;
    void *unk38;
    void *unk3C;
    void *unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    // ... (more fields if needed)
} UnitStruct;

extern u8 lbl_8028FDB0[];
extern u8 lbl_80292230[];
extern u8 lbl_802921E0[];

extern f32 lbl_8036A1E8;
extern f32 lbl_8036A1F8;

extern u8 lbl_80367A48;

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma use_lmw_stmw on
#pragma optimization_level 3
#pragma cplusplus on

#pragma use_lmw_stmw on

#pragma cplusplus reset
#pragma optimization_level reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset
#pragma use_lmw_stmw on
#pragma global_optimizer off
/* Parse actor XML at path into self: string-map entries, scalars, then apply defaults. */

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

#pragma cplusplus on
typedef struct Vec3f {
    f32 x, y, z;
    Vec3f() {}
    Vec3f(f32 _x, f32 _y, f32 _z) {
        x = _x;
        y = _y;
        z = _z;
    }
} Vec3f;
extern "C" f32 PSVECDistance(const Vec3f &, const Vec3f &);

#pragma cplusplus reset

#pragma global_optimizer off

#pragma global_optimizer off

#pragma global_optimizer on
/* Load an actor animation from a relative path under the actor base dir. */

#pragma global_optimizer off

#pragma global_optimizer on

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

typedef struct { f32 x, y, z; } PVector3;
#pragma cplusplus on
struct ActorMotionInterface {
    u8 pad[0x40];
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual PVector3 GetPos(s32) = 0;
    virtual void v13() = 0;
    virtual void Adjust(void *, f32, f32) = 0;
};
#pragma cplusplus on
#pragma push
#pragma dont_inline on
#pragma optimization_level 3
#pragma global_optimizer off

  #pragma pop
  #pragma cplusplus off

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer off
#pragma cplusplus on

#pragma cplusplus reset
#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma peephole off

#pragma peephole reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma global_optimizer off
#pragma cplusplus on

#pragma cplusplus reset
#pragma global_optimizer reset

#pragma optimization_level 1

#pragma optimization_level reset
#pragma cplusplus off
#pragma cplusplus on
#pragma cplusplus on
static inline s32 ActorUpdate_Compare(void *str, char *text) {
 s32 strlen(char *);
 return String_Compare(str,0,*(void **)str,text,strlen(text));
}
static inline void ActorUpdate_CopyVector(Vec3f *dst, const Vec3f *src) {
 const u32 *in=(const u32 *)src;
 u32 *out=(u32 *)dst;
 out[0]=in[0];out[1]=in[1];out[2]=in[2];
}
static inline void ActorUpdate_ReadPosition(Vec3f *out, void *actor) {
 typedef void (*Callback)(Vec3f *,void *,s32);
 Callback *vtable=*(Callback **)((u8 *)actor+0x40);
 Callback callback=vtable[14];
 callback(out,actor,0);
}
struct ActorUpdateSceneInterface {
 u8 pad[0x10];
 virtual void v0()=0;virtual void v1()=0;virtual void v2()=0;virtual void v3()=0;virtual void v4()=0;
 virtual void Add(void *)=0;
};
struct ActorUpdateInterface {
 u8 pad[0x40];
 virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
 virtual void v4()=0; virtual void v5()=0; virtual void v6()=0;
 virtual void SetScale(f32,f32,f32)=0;
 virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void v11()=0;
 virtual Vec3f GetPos(s32)=0;
 virtual void v13()=0; virtual void v14()=0; virtual void v15()=0;
 virtual u8 IsBusy()=0;
};
#pragma cplusplus off
#pragma cplusplus on
#pragma global_optimizer off
#pragma optimization_level reset
#pragma global_optimizer off

#pragma optimization_level reset
#pragma global_optimizer reset
#pragma cplusplus off

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer on

#pragma optimization_level 3

#pragma optimization_level reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma global_optimizer on

void fn_8011AB98(void) {
    M2C_UNK fn_801620AC();
    M2C_UNK fn_8005C8B4();
    M2C_UNK fn_80162018();
    fn_801620AC();
    fn_8005C8B4();
    fn_80162018();
}

void fn_8011ABC0(s32 arg0) {
    void Msg_Expand(void *);
    void Ui_CreateMenu(void *, s32, s32);
    void *fn_8013BFFC(void);
    extern char lbl_80274508[];
    void *tmp;

    Msg_Expand(lbl_80274508 + 0x17c);
    tmp = fn_8013BFFC();
    *((u8 *)tmp + 0x24) = 1;
    Ui_CreateMenu(tmp, arg0, 0);
}

s32 fn_8011AC10(void) {
    extern u16 lbl_8028F814[];
    s32 v = Process_Find(lbl_8028F814);
    return v != 0;
}

void fn_8011AC44(void) {
    u32 Process_Find(void *);
    void Process_Unlink(void);
    extern u8 lbl_8028F814[];
    if (Process_Find(lbl_8028F814) != 0U) {
        Process_Unlink();
    }
}

void *fn_8011AC78(void *arg0)
{
    extern u8 lbl_8028F814[];
    extern u8 lbl_8028F7D8[];

    extern void *Process_CreateChild(void *, void *);
    extern void *Process_Create(void *, void *);
    extern void fn_801403F0(void *);

    u8 *result;

    if (arg0 != 0) {
        result = (u8 *)Process_CreateChild(lbl_8028F814, arg0);
    } else {
        result = (u8 *)Process_Create(lbl_8028F814, arg0);
    }

    if (result != 0) {
        fn_801403F0(result);
        *(u32 *)(result + 0x40) = 0;
    }

    Process_Create(lbl_8028F7D8, result);

    return result;
}

#pragma push
#pragma opt_lifetimes off
void fn_8011ACFC(void) {
    void fn_8001594C(void *, s8);
    void fn_800156A0(void *, void *);
    void fn_80015718(void *, void *);
    extern u8 gUnitLists[];
    void *list[3];
    u8 *next;
    u8 *next3;
    u32 flags;
    u8 *node;
    u8 *iter;

    fn_8001594C(list, 0);
    node = *(u8 **)gUnitLists;
    while (node != NULL) {
        next = *(u8 **)(node + 0x184);
        if (!(*(u32 *)(node + 0x1A0) & 0x010000DC)) {
            fn_800156A0(*(void **)(node + 0x190), node);
            fn_80015718(list, node);
        }
        node = next;
    }
    node = *(u8 **)gUnitLists;
    while (node != NULL) {
        next = *(u8 **)(node + 0x184);
        if (!(*(u32 *)(node + 0x1A0) & 0x010000DC))
            break;
        fn_800156A0(*(void **)(node + 0x190), node);
        fn_80015718(list, node);
        *(u32 *)(node + 0x1A0) |= 0x010000DC;
        node = next;
    }
    for (iter = list[0]; iter != NULL; iter = next3) {
        next3 = *(u8 **)(iter + 0x184);
        flags = *(u32 *)(iter + 0x1A0) & 0x010000DC;
        fn_800156A0(*(void **)(iter + 0x190), iter);
        fn_80015718(gUnitLists, iter);
        if (flags)
            *(u32 *)(iter + 0x1A0) |= 0x010000DC;
    }
}
#pragma pop
void fn_8011AE2C(void *arg0) {
    M2C_UNK Unit_SetMapPos(s32, u8, u8);
    M2C_UNK fn_80050C90(s32);
    Unit_SetMapPos(M2C_FIELD(arg0, s32 *, 0x30), M2C_FIELD(arg0, u8 *, 0x58), M2C_FIELD(arg0, u8 *, 0x59));
    fn_80050C90(M2C_FIELD(arg0, s32 *, 0x30));
}

void fn_8011AE6C(void *arg0) {
    f32 Map_SampleHeightRaw(void *, f32, f32);
    extern u8 gBattleMap[];
    extern const f32 lbl_8036A200;
    extern f32 lbl_8036A1F8;
    extern const f64 lbl_8036A208;
    extern const f64 lbl_8036A210;
    extern const f64 lbl_8036A218;
    extern f32 lbl_80367068[];
    extern const f32 lbl_8036A224;
    extern const f32 lbl_8036A228;
    extern const f32 lbl_8036A220;
    extern const f32 lbl_8036A22C;
    extern const f32 lbl_8036A230;
    f32 spC;
    f32 sp8;
    f32 c;
    f32 half;
    f32 x, y, z;
    f32 x2, y2, z2;
    f32 mx, my, mz;
    f32 dx, dy, dz;
    f32 len;
    f32 len2;
    f32 clamped;
    f32 ratio;
    f32 nx, ny;
    f32 zoff;
    f32 eps;
    f64 g, g2, g3;
    s32 cls;
    s32 word;
    void *p;

    p = *(void **)((u8 *)arg0 + 0x30);
    *(f32 *)((u8 *)arg0 + 0x34) = *(f32 *)((u8 *)p + 4);
    p = *(void **)((u8 *)arg0 + 0x30);
    *(f32 *)((u8 *)arg0 + 0x38) = *(f32 *)((u8 *)p + 8);
    *(f32 *)((u8 *)arg0 + 0x3C) = Map_SampleHeightRaw(gBattleMap,
        *(f32 *)((u8 *)arg0 + 0x34), *(f32 *)((u8 *)arg0 + 0x38));
    c = lbl_8036A200;
    *(f32 *)((u8 *)arg0 + 0x4C) = c + (f32)(s8)((u8 *)arg0)[0x58];
    *(f32 *)((u8 *)arg0 + 0x50) = c + (f32)(s8)((u8 *)arg0)[0x59];
    *(f32 *)((u8 *)arg0 + 0x54) = Map_SampleHeightRaw(gBattleMap,
        (f32)(s8)((u8 *)arg0)[0x58], (f32)(s8)((u8 *)arg0)[0x59]);
    half = lbl_8036A200;
    y = *(f32 *)((u8 *)arg0 + 0x38);
    y2 = *(f32 *)((u8 *)arg0 + 0x50);
    x = *(f32 *)((u8 *)arg0 + 0x34);
    x2 = *(f32 *)((u8 *)arg0 + 0x4C);
    my = y + y2;
    dy = y2 - y;
    z = *(f32 *)((u8 *)arg0 + 0x3C);
    dx = x2 - x;
    z2 = *(f32 *)((u8 *)arg0 + 0x54);

    mx = x + x2;
    dz = z2 - z;

    mz = z + z2;
    mx = half * mx;
    len = dz * dz + (dx * dx + dy * dy);
    my = half * my;
    mz = half * mz;
    if (len > lbl_8036A1F8) {
        g = __frsqrte(len);
        g2 = lbl_8036A208 * g * -(((f64)len * (g * g)) - lbl_8036A210);
        g3 = lbl_8036A208 * g2 * -(((f64)len * (g2 * g2)) - lbl_8036A210);
        len = (f32)((f64)len * (lbl_8036A208 * g3 * -(((f64)len * (g3 * g3)) - lbl_8036A210)));
    } else if ((f64)len < lbl_8036A218) {
        len = lbl_80367068[0];
    } else {
        spC = len;
        word = *(s32 *)&spC;
        switch (word & 0x7F800000) {
        case 0x7F800000:
            if (word & 0x7FFFFF) {
                cls = 1;
            } else {
                cls = 2;
            }
            break;
        case 0x0:
            if (word & 0x7FFFFF) {
                cls = 5;
            } else {
                cls = 3;
            }
            break;
        default:
            cls = 4;
            break;
        }
        if (cls == 1) {
            len = lbl_80367068[0];
        }
    }
    eps = lbl_8036A1F8;
    *(s16 *)((u8 *)arg0 + 0x5C) = (s16)(((lbl_8036A220 * (lbl_8036A224 - len)) + (lbl_8036A228 * len)) * lbl_8036A22C);
    *(s16 *)((u8 *)arg0 + 0x5A) = 0;
    dy = *(f32 *)((u8 *)arg0 + 0x50) - my;
    ny = *(f32 *)((u8 *)arg0 + 0x4C) - mx;
    nx = -dy;
    len2 = (nx * nx) + (ny * ny);
    if (len2 > eps) {
        g = __frsqrte(len2);
        g2 = lbl_8036A208 * g * -(((f64)len2 * (g * g)) - lbl_8036A210);
        g3 = lbl_8036A208 * g2 * -(((f64)len2 * (g2 * g2)) - lbl_8036A210);
        len2 = (f32)((f64)len2 * (lbl_8036A208 * g3 * -(((f64)len2 * (g3 * g3)) - lbl_8036A210)));
    } else if ((f64)len2 < lbl_8036A218) {
        len2 = lbl_80367068[0];
    } else {
        sp8 = len2;
        word = *(s32 *)&sp8;
        switch (word & 0x7F800000) {
        case 0x7F800000:
            if (word & 0x7FFFFF) {
                cls = 1;
            } else {
                cls = 2;
            }
            break;
        case 0x0:
            if (word & 0x7FFFFF) {
                cls = 5;
            } else {
                cls = 3;
            }
            break;
        default:
            cls = 4;
            break;
        }
        if (cls == 1) {
            len2 = lbl_80367068[0];
        }
    }
    clamped = len2;
    if (len2 > lbl_8036A230) {
        clamped = lbl_8036A230;
    }
    ratio = clamped / len2;
    nx = nx * ratio;
    ny = ny * ratio;
    zoff = lbl_8036A230;
    zoff = zoff * clamped;
    *(f32 *)((u8 *)arg0 + 0x40) = mx + nx;
    *(f32 *)((u8 *)arg0 + 0x44) = my + ny;
    *(f32 *)((u8 *)arg0 + 0x48) = mz - zoff;
    if (*(s16 *)((u8 *)arg0 + 0x5C) > 0x30) {
        *(s16 *)((u8 *)arg0 + 0x5C) = 0x30;
    }
}

#pragma global_optimizer off
void fn_8011B204(void *arg0) {
    void Process_ClearFunc(void *);
    extern f64 lbl_8036A1F0;
    extern f32 lbl_8036A1E8;
    extern f32 lbl_8036A230;
    f32 c1;
    s16 num;
    s16 den;
    f32 c2;
    f32 p1y;
    f32 tn;
    f32 p1x;
    f32 td;
    f32 p1z;
    f32 p0x;
    f32 p0y;
    f32 p2y;
    f32 t;
    f32 p2x;
    f32 p0z;
    f32 p2z;
    void *out;
    f32 u;
    f32 t2;
    f32 w;
    f32 u2;
    f32 x;
    f32 y;
    f32 z;
    s16 cur;

    c1 = lbl_8036A1E8;
    num = *(s16 *)((u8 *)arg0 + 0x5A);
    den = *(s16 *)((u8 *)arg0 + 0x5C);
    c2 = lbl_8036A230;
    p1y = *(f32 *)((u8 *)arg0 + 0x44);
    tn = (f32)num;
    p1x = *(f32 *)((u8 *)arg0 + 0x40);
    td = (f32)den;
    p1z = *(f32 *)((u8 *)arg0 + 0x48);
    p0x = *(f32 *)((u8 *)arg0 + 0x34);
    p0y = *(f32 *)((u8 *)arg0 + 0x38);
    p2y = *(f32 *)((u8 *)arg0 + 0x50);
    t = tn / td;
    p2x = *(f32 *)((u8 *)arg0 + 0x4C);
    p0z = *(f32 *)((u8 *)arg0 + 0x3C);
    p2z = *(f32 *)((u8 *)arg0 + 0x54);
    out = *(void **)((u8 *)arg0 + 0x30);

    u = c1 - t;
    t2 = t * t;
    w = c2 * u;
    u2 = u * u;
    w = w * t;

    x = p1x * w;
    y = p1y * w;
    z = p1z * w;
    x = p0x * u2 + x;
    y = p0y * u2 + y;
    z = p0z * u2 + z;
    x = p2x * t2 + x;
    y = p2y * t2 + y;
    z = p2z * t2 + z;

    *(f32 *)((u8 *)out + 4) = x;
    *(f32 *)((u8 *)out + 8) = y;
    *(f32 *)((u8 *)out + 0xC) = z;

    cur = *(s16 *)((u8 *)arg0 + 0x5A);
    *(s16 *)((u8 *)arg0 + 0x5A) = (s16)(cur + 1);
    if (cur == *(s16 *)((u8 *)arg0 + 0x5C)) {
        Process_ClearFunc(arg0);
    }
}
#pragma global_optimizer reset
void fn_8011B2EC(void) {
    M2C_UNK fn_800F20E0();
    M2C_UNK fn_800F214C();
    fn_800F214C();
    fn_800F20E0();
}

#pragma use_lmw_stmw on
void fn_8011B310(void *arg0) {
    void fn_800F20E0(void);
    void fn_800F214C(void);
    void Ui_PlaySeCue(void *, s32);
    void BattleState_SetCamPos(void *, f32, f32);
    extern s32 gUiInputFlags;
    extern s32 *gPadInput;
    extern u8 lbl_80274508[];
    register s32 flags;
    register u8 saved_x;
    register u8 saved_y;
    register u8 *node;
    register u8 skip;
    register u8 *base;

    base = (u8 *)gBattleState;
    saved_x = (u8)(s32)*(f32 *)(base + 0x524);
    saved_y = (u8)(s32)*(f32 *)(base + 0x528);
    skip = (gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20);
    if (skip == 0) {
        flags = gPadInput[3];
        if (flags & 1) {
            node = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 4);
            *(void **)((u8 *)arg0 + 0x30) = node;
            BattleState_SetCamPos(gBattleState, (f32)(s8)node[0], (f32)(s8)node[1]);
        }
        if (flags & 8) {
            node = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0xC);
            *(void **)((u8 *)arg0 + 0x30) = node;
            BattleState_SetCamPos(gBattleState, (f32)(s8)node[0], (f32)(s8)node[1]);
        }
        if (flags & 2) {
            node = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 8);
            *(void **)((u8 *)arg0 + 0x30) = node;
            BattleState_SetCamPos(gBattleState, (f32)(s8)node[0], (f32)(s8)node[1]);
        }
        if (flags & 4) {
            node = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0x10);
            *(void **)((u8 *)arg0 + 0x30) = node;
            BattleState_SetCamPos(gBattleState, (f32)(s8)node[0], (f32)(s8)node[1]);
        }
        if ((flags & 0xF) == 0) {
            fn_800F214C();
        }
        if ((s32)saved_x != (s8)(s32)*(f32 *)(base + 0x524) ||
            (s32)saved_y != (s8)(s32)*(f32 *)(base + 0x528)) {
            Ui_PlaySeCue(lbl_80274508 + 0x307, 0x64);
        }
    }
    fn_800F20E0();
}
#pragma use_lmw_stmw reset

void fn_8011B570(void) {

}

void fn_8011B574(void) {

}

s32 fn_8011B578(void) {
    return 0xB0;
}

#pragma cplusplus on
extern "C" void fn_8011B580(void *arg0, void *arg1) {
void fn_8008C1D8(s32,s32,s32,s32,s32);
struct Obj { u8 pad[4]; virtual void v0()=0;
virtual void v1()=0;
virtual void v2()=0;
virtual void v3()=0;
virtual void v4()=0;
virtual void v5()=0;
virtual void v6()=0;
virtual void v7()=0;
virtual void v8()=0;
virtual void v9()=0;
virtual void v10()=0;
virtual void v11()=0;
virtual void v12()=0;
virtual void v13()=0;
virtual void v14()=0;
virtual void v15()=0;
virtual void v16()=0;
virtual void v17()=0;
virtual void v18()=0;
virtual void v19()=0;
virtual s16 v20()=0;
virtual void v21()=0;
virtual void v22()=0;
virtual void v23()=0;
virtual void v24()=0;
virtual void v25()=0;
virtual void v26()=0;
virtual void v27()=0;
virtual void v28()=0;
virtual void v29()=0; };
s32 value=*(s8 *)((u8 *)arg1+0x60);
s32 count=value;
((Obj *)arg0)->v29();
fn_8008C1D8(0,0,0,count*((Obj *)*(void **)((u8 *)arg1+0x3C))->v20()+0x20,2);
}
#pragma cplusplus on
extern "C" void fn_8011B5FC(void *self, void *ctx)
{
    void Ui_DrawObjRouteIcon(void *, void *);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    s32 Text_MeasureHeight(s32, f32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    extern f32 lbl_8036A234;
    extern f32 lbl_8036A238;
    extern f32 lbl_8036A1E8;
    extern f32 lbl_8036A23C;

    struct DrawObj {
        u8 pad04[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual s32 v20() = 0;
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual void v25() = 0;
        virtual void v26() = 0;
        virtual void v27() = 0;
        virtual void v28() = 0;
        virtual void v29() = 0;
        virtual void v30() = 0;
        virtual void v31(void *ctx) = 0;
    };

    s16 top;
    register unsigned int heightOffset;
    s32 width;
    s32 scaled;

    Ui_DrawObjRouteIcon(self, ctx);
    ((DrawObj *)self)->v31(ctx);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A234);
    Prim2D_PrepareTex();

    scaled = (s32)((f32)(s16)((DrawObj *)self)->v20() * lbl_8036A238);

    heightOffset = Text_MeasureHeight(-1, lbl_8036A1E8) >> 1;

    top = *(s16 *)((u8 *)ctx + 0x3A);
    width = (s16)((DrawObj *)self)->v20();

    fn_8008AB7C(width >> 1, top + heightOffset, scaled, 0x17, 0xA, 0x28, 1);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A23C);
    Prim2D_PrepareTex();
}
#pragma cplusplus reset
extern "C" s16 fn_8011B710(void *arg0) {
    struct Obj {
        u8 pad[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual s16 v18() = 0;
    };
    s16 temp = ((Obj *)arg0)->v18();
    return (s16)((0x260 - temp) >> 1);
}
#pragma cplusplus reset
s32 fn_8011B74C(void) {
    return 0x40;
}

extern u8 gUnitInfoPopup[];
s32 fn_8011B754(void) {
    u8 Ui_IsUnitInfoPopupOpen(void *);

    return Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) ? 0x40 : 0x10;
}

#pragma cplusplus on
extern "C" void *GfxEnt_Get(u8);
extern "C" u8 Ui_IsUnitInfoPopupOpen(void *);
extern "C" s32 fn_8011B78C(void *arg0, u8 *arg1) {
    extern void *gPadInput;
    extern u8 gUiContext[];
    struct Handler {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual s32 OnA(void *, void *) = 0;
        virtual s32 OnL(void *, void *) = 0;
        virtual s32 OnZ(void *, void *) = 0;
        virtual void v12() = 0;
        virtual s32 OnDefault(void *, void *) = 0;
    };
    struct Menu {
        u8 pad0[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual s32 OnB(void *, void *) = 0;
        virtual s32 OnR(void *, void *) = 0;
    };
    u32 buttons;
    void *unit;
    u8 flag;

    unit = GfxEnt_Get(arg1[0x40 + (s8)arg1[0x62]]);
    flag = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        flag = 1;
    }
    if (flag) {
        return M2C_FIELD(unit, Handler **, 0x34)->OnDefault(arg1, unit);
    }
    buttons = M2C_FIELD(gPadInput, u32 *, 4) & (M2C_FIELD(gPadInput, u32 *, 8) ^ M2C_FIELD(gPadInput, u32 *, 4));
    lbl_80367A48 = M2C_FIELD(unit, u8 *, 0x3A) + 0x80;
    if ((buttons & 0x100) && !Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
        return M2C_FIELD(unit, Handler **, 0x34)->OnA(arg1, unit);
    }
    if (buttons & 0x200) {
        return M2C_FIELD(arg1, Menu **, 0x3C)->OnB(arg1, unit);
    }
    if (buttons & 0x400) {
        return M2C_FIELD(unit, Handler **, 0x34)->OnL(arg1, unit);
    }
    if (buttons & 0x800) {
        return M2C_FIELD(arg1, Menu **, 0x3C)->OnR(arg1, unit);
    }
    if (buttons & 0x10) {
        return M2C_FIELD(unit, Handler **, 0x34)->OnZ(arg1, unit);
    }
    if ((buttons & 0x1000) && !Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x18), u8 *, 0x48) = 1;
        gUiContext[8] = 0x88;
        return 5;
    }
    return M2C_FIELD(unit, Handler **, 0x34)->OnDefault(arg1, unit);
}
#pragma cplusplus reset
void fn_8011B978(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x357);
}

void *fn_8011B9A4(void) {
    extern u16 lbl_80274508[];
    return &lbl_80274508[0x364 / sizeof(u16)];
}

u8 fn_8011B9B4(void) {
    extern u8 lbl_80367A48;
    return (u8) (lbl_80367A48 == 0x88);
}

s32 fn_8011B9C8(s32 unused, u8 *arg1) {
    extern u8 gUiContext[24];
    u8 *p;
    u8 *obj;
    obj = *(u8 **)(arg1 + 0x18);
    obj[0x48] = 1;
    p = gUiContext;
    p[8] = 0x88;
    return 5;
}

#pragma cplusplus on
extern "C" void fn_8011B9EC(void *self, void *panel, void *entry) {
    s32 Text_MeasureWidth(void *, s32, f32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    extern f32 lbl_8036A1E8;

    struct Obj {
        u8 pad[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual s16 v18() = 0;
    };
    struct TextSrc {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void *v4(void *) = 0;
    };
    struct Host {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17(void *) = 0;
        virtual void v18(void *) = 0;
    };

    s16 w;
    s32 tw;
    void *text;

    w = ((Obj *)*(void **)((u8 *)panel + 0x3C))->v18();
    text = ((TextSrc *)*(void **)((u8 *)entry + 0x34))->v4(entry);
    tw = Text_MeasureWidth(text, -1, lbl_8036A1E8);
    ((Host *)self)->v17(panel);
    Prim2D_AddPrim(6);
    Prim2D_SetPos((f32)((w - tw) >> 1), (f32)*(s16 *)((u8 *)entry + 0x32));
    ((Host *)self)->v18(entry);
    text = ((TextSrc *)*(void **)((u8 *)entry + 0x34))->v4(entry);
    Prim2D_SetText(text);
    Prim2D_EndPrim();
}
#pragma cplusplus reset

void fn_8011BAF8(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x385);
}

void *fn_8011BB24(void) {
    extern u16 lbl_80274508[];
    return (u8 *) &lbl_80274508 + 0x38F;
}

u8 fn_8011BB34(void) {
    u8 fn_801E3620(void *);
    extern u8 gSystemSave[];

    if (((u8 *)gBattleState)[0x10] > 0x1FU) {
        return 2;
    }
    if (!(gUiInputFlags & 0x10) && fn_801E3620(gSystemSave) == 0) {
        return 2;
    }
    return (u8)(lbl_80367A48 == 0x87);
}

#pragma cplusplus on
extern "C" s32 fn_8011BBA4(void *arg0, void *panel, void *entry) {
    void Ui_CreateMsgPopup(void *, void *, f32, f32);
    u8 fn_801E3620(void *);
    extern u8 lbl_80274508[];
    extern u8 gSystemSave[];
    extern u8 gUiContext[];
    struct Obj {
        u8 pad[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual void v18() = 0;
        virtual void v19() = 0;
        virtual void v20() = 0;
        virtual s16 v21() = 0;
        virtual s16 v22() = 0;
    };
    f32 fx;
    f32 fy;
    s16 base;

    if (*(u8 *)((u8 *)entry + 0x39) == 2) {
        base = ((Obj *)*(void **)((u8 *)panel + 0x3C))->v21();
        fx = (f32)(base + *(s16 *)((u8 *)entry + 0x30));
        base = ((Obj *)*(void **)((u8 *)panel + 0x3C))->v22();
        fy = (f32)(base + *(s16 *)((u8 *)entry + 0x32));
        if (((u8 *)gBattleState)[0x10] > 0x1FU) {
            Ui_CreateMsgPopup(lbl_80274508 + 0x398, panel, fx, fy);
        } else if (!(gUiInputFlags & 0x10) && fn_801E3620(gSystemSave) == 0) {
            Ui_CreateMsgPopup(lbl_80274508 + 0x3AD, panel, fx, fy);
        }
        return 0;
    }
    gUiContext[8] = 0x87;
    return 5;
}
#pragma cplusplus reset
void fn_8011BD08(void) {
    extern u8 lbl_80274508[];
    extern void Msg_Expand(void *);

    Msg_Expand(lbl_80274508 + 0x3BE);
}

void *fn_8011BD34(void) {
    extern u16 lbl_80274508[];
    return (u8 *)lbl_80274508 + 0x3C6;
}

u8 fn_8011BD44(void) {
    extern u8 lbl_80367A48;
    return (u8) (lbl_80367A48 == 0x86);
}

s32 fn_8011BD58(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x86;
    return 5;
}

void fn_8011BD70(void) {
    extern u8 lbl_80274508[];
    Msg_Expand(&lbl_80274508[0x3CF]);
}

void *fn_8011BD9C(void) {
    extern u16 lbl_80274508[];
    return (u8 *)lbl_80274508 + 0x3D8;
}

u8 fn_8011BDAC(void) {
    extern u8 lbl_80367A48;
    u32 temp;

    temp = __cntlzw(0x85 - lbl_80367A48);
    return (u8)((temp >> 5) & 0xFF);
}

extern u8 gUiContext[24];
s32 fn_8011BDC0(void) {
    gUiContext[8] = 0x85;
    return 5;
}

void fn_8011BDD8(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x3E1);
}

void *fn_8011BE04(void) {
    extern u16 lbl_80274508[];
    return (u8 *)lbl_80274508 + 0x3ED;
}

s32 fn_8011BE14(void) {
    u32 Res_GetByName(void *);
    extern u8 lbl_80274508[];
    extern u8 lbl_80367A48;

    if (Res_GetByName(lbl_80274508 + 0x3f9) == 0) {
        return 3;
    }
    return (u8)(lbl_80367A48 == 0x84);
}

s32 fn_8011BE60(void) {
    gUiContext[8] = 0x84;
    return 5;
}

void fn_8011BE78(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x402);
}

void *fn_8011BEA4(void) {
    extern u16 lbl_80274508[];
    return (u8 *)lbl_80274508 + 0x412;
}

u8 fn_8011BEB4(void) {
    extern u8 lbl_80367A48;
    u32 temp;

    temp = __cntlzw(0x83 - lbl_80367A48);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_8011BEC8(void) {
    gUiContext[8] = 0x83;
    return 5;
}

void fn_8011BEE0(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x41D);
}

void *fn_8011BF0C(void) {
    extern u16 lbl_80274508[];
    return (u8 *)lbl_80274508 + 0x429;
}

u8 fn_8011BF1C(void) {
    extern u8 lbl_80367A48;
    u32 temp;

    temp = __cntlzw(0x82 - lbl_80367A48);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_8011BF30(void) {
    gUiContext[8] = 0x82;
    return 5;
}

void fn_8011BF48(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x435);
}

void *fn_8011BF74(void) {
    extern u8 lbl_80274508[];
    return &lbl_80274508[0x442];
}

u8 fn_8011BF84(void) {
    extern u8 lbl_80367A48;
    u32 temp;

    temp = __cntlzw(0x81 - lbl_80367A48);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_8011BF98(void) {
    *(u8*)((u32)&gUiContext + 8) = 0x81;
    return 5;
}

void fn_8011BFB0(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x44F);
}

void *fn_8011BFDC(void) {
    extern u16 lbl_80274508[];
    return (u8 *)lbl_80274508 + 0x45C;
}

u8 fn_8011BFEC(void) {
    extern u8 lbl_80367A48;
    u32 temp;

    temp = __cntlzw(0x80 - lbl_80367A48);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_8011C000(void) {
    gUiContext[8] = 0x80;
    return 5;
}

#pragma push
#pragma optimization_level 3
s32 fn_8011C018(void *self) {
#pragma use_lmw_stmw on
    void *TargetList_GetAt(void *, s32);
    extern u8 gTargetList[];
    s16 bestDist;
    void *best;
    s32 i;
    void *other;
    s32 dy;
    s32 dx;
    s16 dist;
    u8 prefer;
    void *result;
    u32 oy;
    u32 ox;
    u32 sy;
    u32 sx;

    bestDist = 0x7FFF;
    best = NULL;
    for (i = 0; i < *(s32 *)gTargetList; i++) {
        other = TargetList_GetAt(gTargetList, i);
        if (self == other) {
            continue;
        }
        oy = ((u8 *)other)[1];
        sy = ((u8 *)self)[1];
        if ((s8)sy >= (s8)oy) {
            continue;
        }
        dy = ((s8)sy - (s8)oy) < 0 ? -((s8)sy - (s8)oy) : ((s8)sy - (s8)oy);
        ox = ((u8 *)other)[0];
        sx = ((u8 *)self)[0];
        dx = (s8)sx - (s8)ox;
        if (((s8)((u8 *)self)[0] - (s8)((u8 *)other)[0]) < 0) {
            dx = -dx;
        }
        dist = (s16)(dx + dy);
        if (bestDist < dist) {
            continue;
        }
        if (best != NULL && bestDist == dist) {
            if ((s8)((u8 *)best)[1] == (s8)oy) {
                prefer = ((s8)((u8 *)best)[0] < (s8)ox);
            } else {
                prefer = ((s8)((u8 *)best)[1] < (s8)oy);
            }
            if (!prefer) {
                continue;
            }
        }
        bestDist = dist;
        best = other;
    }
    if (best != NULL) {
        result = best;
    } else {
        result = self;
    }
    *(void **)((u8 *)self + 0x10) = result;
    return best != NULL;
}
#pragma pop
s32 fn_8011C164(void *self) {
    void *TargetList_GetAt(void *, s32);
    extern u8 gTargetList[];
    s16 bestDist;
    void *best;
    s32 i;
    void *other;
    u32 oy;
    u32 ox;
    u32 sy;
    u32 sx;
    s32 dy;
    s32 dx;
    s16 dist;
    u8 prefer;
    void *result;

    bestDist = 0x7FFF;
    best = NULL;
    for (i = 0; i < *(s32 *)gTargetList; i++) {
        other = TargetList_GetAt(gTargetList, i);
        if (self == other) {
            continue;
        }
        ox = ((u8 *)other)[0];
        sx = ((u8 *)self)[0];
        if ((s8)sx >= (s8)ox) {
            continue;
        }
        oy = ((u8 *)other)[1];
        sy = ((u8 *)self)[1];
        dy = (s8)sy - (s8)oy;
        if (((s8)((u8 *)self)[1] - (s8)((u8 *)other)[1]) < 0) {
            dy = -dy;
        }
        dx = ((s8)sx - (s8)ox) < 0 ? -((s8)sx - (s8)ox) : ((s8)sx - (s8)ox);
        dist = (s16)(dx + dy);
        if (bestDist < dist) {
            continue;
        }
        if (best != NULL && bestDist == dist) {
            if ((s8)((u8 *)best)[0] == (s8)ox) {
                prefer = (s8)oy > (s8)((u8 *)best)[1];
            } else {
                prefer = (s8)((u8 *)best)[0] > (s8)ox;
            }
            if (prefer == 0) {
                continue;
            }
        }
        bestDist = dist;
        best = other;
    }
    if (best != NULL) {
        result = best;
    } else {
        result = self;
    }
    *(void **)((u8 *)self + 0x8) = result;
    return best != NULL;
}
#pragma push
#pragma opt_propagation off
s32 fn_8011C2B8(void *self) {
    void *TargetList_GetAt(void *, s32);
    extern u8 gTargetList[];
    s16 bestDist;
    void *best;
    s32 i;
    void *other;
    s32 dy;
    s32 dx;
    s16 dist;
    u8 prefer;
    void *result;
    u32 oy;
    u32 ox;
    u32 sy;
    u32 sx;

    bestDist = 0x7FFF;
    best = NULL;
    for (i = 0; i < *(s32 *)gTargetList; i++) {
        other = TargetList_GetAt(gTargetList, i);
        if (self == other) {
            continue;
        }
        oy = ((u8 *)other)[1];
        sy = ((u8 *)self)[1];
        if ((s8)sy <= (s8)oy) {
            continue;
        }
        dy = ((s8)sy - (s8)oy) < 0 ? -((s8)sy - (s8)oy) : ((s8)sy - (s8)oy);
        ox = ((u8 *)other)[0];
        sx = ((u8 *)self)[0];
        dx = (s8)sx - (s8)ox;
        if (((s8)((u8 *)self)[0] - (s8)ox) < 0) {
            dx = -dx;
        }
        dist = (s16)(dx + dy);
        if (bestDist < dist) {
            continue;
        }
        if (best != NULL && bestDist == dist) {
            if ((s8)((u8 *)best)[1] == (s8)oy) {
                prefer = (s8)ox > (s8)((u8 *)best)[0];
            } else {
                prefer = (s8)oy > (s8)((u8 *)best)[1];
            }
            if (prefer == 0) {
                continue;
            }
        }
        bestDist = dist;
        best = other;
    }
    if (best != NULL) {
        result = best;
    } else {
        result = self;
    }
    *(void **)((u8 *)self + 0xC) = result;
    return best != NULL;
}
#pragma pop
s32 fn_8011C404(void *self) {
    void *TargetList_GetAt(void *, s32);
    extern u8 gTargetList[];
    s16 bestDist;
    void *best;
    s32 i;
    void *other;
    u32 oy;
    u32 ox;
    u32 sy;
    u32 sx;
    s32 dy;
    s32 dx;
    s16 dist;
    u8 prefer;
    void *result;

    bestDist = 0x7FFF;
    best = NULL;
    for (i = 0; i < *(s32 *)gTargetList; i++) {
        other = TargetList_GetAt(gTargetList, i);
        if (self == other) {
            continue;
        }
        ox = ((u8 *)other)[0];
        sx = ((u8 *)self)[0];
        if ((s8)sx <= (s8)ox) {
            continue;
        }
        oy = ((u8 *)other)[1];
        sy = ((u8 *)self)[1];
        dy = (s8)sy - (s8)oy;
        if (((s8)((u8 *)self)[1] - (s8)((u8 *)other)[1]) < 0) {
            dy = -dy;
        }
        dx = ((s8)sx - (s8)ox) < 0 ? -((s8)sx - (s8)ox) : ((s8)sx - (s8)ox);
        dist = (s16)(dx + dy);
        if (bestDist < dist) {
            continue;
        }
        if (best != NULL && bestDist == dist) {
            if ((s8)((u8 *)best)[0] == (s8)ox) {
                prefer = (s8)((u8 *)best)[1] > (s8)oy;
            } else {
                prefer = (s8)ox > (s8)((u8 *)best)[0];
            }
            if (prefer == 0) {
                continue;
            }
        }
        bestDist = dist;
        best = other;
    }
    if (best != NULL) {
        result = best;
    } else {
        result = self;
    }
    *(void **)((u8 *)self + 0x4) = result;
    return best != NULL;
}
#pragma global_optimizer on
void *fn_8011C558(void *arg0, s16 arg1) {
    void Heap_Free(void *);

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80292230;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_8028FDB0;
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

s32 BgWin_OnCancel(void) {
    M2C_UNK fn_800D758C(s32);
    extern s32 gBgWin;
    fn_800D758C(gBgWin);
    return 0;
}

s32 BgWin_OnOk(void)
{
    extern u8 *gBgWin;

    extern void fn_800D758C(void *);
    extern s32 fn_8011C9E4(void *);
    extern void fn_800DA894(s32, s32, s32);

    u8 *obj;
    s32 value1;
    s32 value2;
    s32 value3;

    fn_800D758C(gBgWin);

    obj = gBgWin;
    value3 = fn_8011C9E4(*(void **)(obj + 0x42C));

    obj = gBgWin;
    value2 = fn_8011C9E4(*(void **)(obj + 0x428));

    obj = gBgWin;
    value1 = fn_8011C9E4(*(void **)(obj + 0x424));

    fn_800DA894(value1, value2, value3);

    return 0;
}

void fn_8011C64C(void *arg0, s32 arg1) {
    void fn_8011CAAC(s32, s32, s32);
    fn_8011CAAC(*(s32 *)((u8 *)arg0 + 0x428), arg1, 0);
}

void fn_8011C674(void *arg0, s32 arg1) {
    void fn_8011CAAC(s32, s32, s32);
    fn_8011CAAC(*(s32 *)((u8 *)arg0 + 0x424), arg1, 0);
}

void *BgWin_Create(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    /* Construct the ztool BgWin window and wire its Terrain/Sky/Obj/Ok/Cancel controls. */
    void String_ConcatCStr(void *, void *, char *);
    void *fn_800D75FC(void *, void *);
    void fn_800D764C(void *, s32, s32, s32, void *, void *);
    void fn_800E3F54(void *);
    extern char BgWin_str[];
    extern u8 BgWin_vtable[];
    extern void BgWin_OnOk(void);
    extern void BgWin_OnCancel(void);
    String pathBase;
    String dbxPath;
    String winName;
    String terrainBox;
    String skyBox;
    String objBox;
    String okBtn;
    String cancelBtn;
    void *sp20;
    void *sp1C;
    void *sp18;
    void *sp14;
    void *sp10;
    void *spC;
    void *sp8;
    void *temp;
    void *self;

    self = arg0;
    String_Init(&pathBase, BgWin_str, &sp20);
    String_ConcatCStr(&dbxPath, &pathBase, BgWin_str + 7);
    String_Init(&winName, BgWin_str + 0x11, &sp1C);
    fn_800D764C(self, arg1, arg2, arg3, &dbxPath, &winName);
    String_Destroy(&winName, -1);
    String_Destroy(&dbxPath, -1);
    String_Destroy(&pathBase, -1);
    *(void **)((u8 *)self + 0xC) = BgWin_vtable;
    String_Init(&terrainBox, BgWin_str + 0x17, &sp18);
    *(void **)((u8 *)self + 0x424) = fn_800D75FC(self, &terrainBox);
    String_Destroy(&terrainBox, -1);
    String_Init(&skyBox, BgWin_str + 0x22, &sp14);
    *(void **)((u8 *)self + 0x428) = fn_800D75FC(self, &skyBox);
    String_Destroy(&skyBox, -1);
    String_Init(&objBox, BgWin_str + 0x29, &sp10);
    *(void **)((u8 *)self + 0x42C) = fn_800D75FC(self, &objBox);
    String_Destroy(&objBox, -1);
    String_Init(&okBtn, BgWin_str + 0x30, &spC);
    temp = fn_800D75FC(self, &okBtn);
    *(void **)((u8 *)self + 0x430) = temp;
    *(void **)((u8 *)self + 0x418) = temp;
    String_Destroy(&okBtn, -1);
    String_Init(&cancelBtn, BgWin_str + 0x36, &sp8);
    temp = fn_800D75FC(self, &cancelBtn);
    *(void **)((u8 *)self + 0x434) = temp;
    *(void **)((u8 *)self + 0x41C) = temp;
    String_Destroy(&cancelBtn, -1);
    temp = *(void **)((u8 *)self + 0x430);
    *(void **)((u8 *)temp + 0xA4) = (void *)BgWin_OnOk;
    temp = *(void **)((u8 *)self + 0x434);
    *(void **)((u8 *)temp + 0xA4) = (void *)BgWin_OnCancel;
    *(void **)((u8 *)self + 0x14) = *(void **)((u8 *)self + 0x424);
    *(void **)((u8 *)self + 0x54) = *(void **)((u8 *)self + 0x428);
    *(void **)((u8 *)self + 0x94) = *(void **)((u8 *)self + 0x42C);
    *(void **)((u8 *)self + 0xD4) = *(void **)((u8 *)self + 0x430);
    *(void **)((u8 *)self + 0x414) = *(void **)((u8 *)self + 0x424);
    fn_800E3F54(*(void **)((u8 *)self + 0x424));
    return self;
}

void *fn_8011C8DC(void *arg0, s16 arg1) {
#pragma global_optimizer off
    extern u8 lbl_8028FDD0[];
    void Heap_Free(void *);
    void *fn_800CA6C8(void *, s16);
    void fn_800E45EC(void *, s16);
    u8 *p;

    if (arg0 != NULL) {
        p = (u8 *)arg0;
        *(void **)(p + 0x40) = lbl_8028FDD0;
        if (p + 0xB8)
            if (p + 0xB8)
                if (p + 0xB8)
                    if (*(void **)(p + 0xC0))
                        Heap_Free(*(void **)(p + 0xC0));
        if (p + 0xAC)
            if (p + 0xAC)
                fn_800CA6C8(p + 0xAC, 0);
        fn_800E45EC(arg0, 0);
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
#pragma global_optimizer reset
}

void *fn_8011C984(void *arg0, u32 arg1) {
    u32 count;
    void **array;

    count = *(u32 *)((u8 *)arg0 + 0xBC);

    if (arg1 < count) {
        array = *(void ***)((u8 *)arg0 + 0xC0);
        return array[arg1];
    }

    return NULL;
}

void fn_8011C9A8(void *arg0, s32 arg1) {
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;

    M2C_FIELD(arg0, s32 *, 0xEC) = arg1;
    temp_r6 = M2C_FIELD(arg0, s32 *, 0xF4);
    temp_r4 = M2C_FIELD(arg0, s32 *, 0xF8);
    temp_r5 = M2C_FIELD(arg0, s32 *, 0xEC);
    if (temp_r5 >= (s32) (temp_r6 + temp_r4)) {
        M2C_FIELD(arg0, s32 *, 0xF4) = (s32) ((temp_r5 - temp_r4) + 1);
        return;
    }
    if (temp_r5 < temp_r6) {
        M2C_FIELD(arg0, s32 *, 0xF4) = temp_r5;
    }
}

s32 fn_8011C9E4(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xEC);
}

s32 fn_8011C9EC(s32 arg0) {
    return arg0 + 0xAC;
}

M2C_UNK *fn_8011C9F4(void *arg0) {
    extern u8 lbl_80274A88[];
    u32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, u32 *, 0xEC);
    if (temp_r4 < (u32) M2C_FIELD(arg0, u32 *, 0xB0)) {
        return (M2C_UNK *)String_CStr((void *)(M2C_FIELD(arg0, s32 *, 0xB4) + (temp_r4 * 0xC)));
    }
    return (M2C_UNK *)lbl_80274A88;
}

extern void fn_800CA91C(void *arg0);
extern void fn_800DD598(s32 arg0, s32 arg1, u8 *arg2);
#pragma global_optimizer off
void fn_8011CA3C(void *arg0, void *arg1) {
    void fn_800CA91C(void *);
    void fn_800DD598(void *, void *, void *, u8 *);
    u8 sp8;

    fn_800CA91C((char *)arg0 + 0xAC);
    *(s32 *)((char *)arg0 + 0xBC) = 0;
    if ((void *)((char *)arg0 + 0xAC) != arg1) {
        sp8 = *(u8 *)((char *)&sp8 + 4);
        fn_800DD598((char *)arg0 + 0xAC,
                    *(void **)((char *)arg1 + 8),
                    (char *)*(void **)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 4) * 0xC,
                    &sp8);
    }
}
#pragma global_optimizer on
void fn_8011CAAC(void *arg0, void *arg1, void *arg2)
{
    extern void fn_800CA18C(void *, void *, s32, void *);
    extern void fn_800C9BC4(void *, void *, s32, void *);

    u8 *obj;
    u8 *source;
    u8 *destination;
    void *value;

    obj = (u8 *)arg0;
    value = arg2;

    source = *(u8 **)(obj + 0xB4);
    source += *(s32 *)(obj + 0xB0) * 0xC;

    fn_800CA18C(
        obj + 0xAC,
        source,
        1,
        arg1
    );

    destination = *(u8 **)(obj + 0xC0);
    destination += *(s32 *)(obj + 0xBC) * 4;

    fn_800C9BC4(
        obj + 0xB8,
        destination,
        1,
        &value
    );
}

void fn_8011CB18(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0xF0) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = (s32) M2C_FIELD(arg0, s32 *, 0xC8);
}

void fn_8011CB2C(void *arg0) {
    M2C_UNK (*temp_r12)();

    M2C_FIELD(arg0, s8 *, 0xF0) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = (s32) M2C_FIELD(arg0, s32 *, 0xC8);
    temp_r12 = M2C_FIELD(arg0, M2C_UNK (**)(), 0xFC);
    if (temp_r12 != NULL) {
        temp_r12();
    }
}

void fn_8011CB6C(void *arg0, s32 arg1, s32 arg2) {
    s32 t48;
    s32 t4c;
    u8 flag;
    s32 x;
    s32 t64;
    s32 y;
    s32 t60;
    s32 tc8;

    t48 = *(s32 *)((u8 *)arg0 + 0x48);
    flag = 0;
    t4c = *(s32 *)((u8 *)arg0 + 0x4C);
    x = arg1 - t48;
    t64 = *(s32 *)((u8 *)arg0 + 0x64);
    y = arg2 - t4c;
    t60 = *(s32 *)((u8 *)arg0 + 0x60);
    tc8 = *(s32 *)((u8 *)arg0 + 0xC8);
    *(s32 *)((u8 *)arg0 + 0xCC) = flag;
    *(s32 *)((u8 *)arg0 + 0xD0) = tc8;
    *(s32 *)((u8 *)arg0 + 0xD4) = t60;
    *(s32 *)((u8 *)arg0 + 0xD8) = t64;
    if (x >= *(s32 *)((u8 *)arg0 + 0xCC) && x <= *(s32 *)((u8 *)arg0 + 0xD4) &&
        y >= *(s32 *)((u8 *)arg0 + 0xD0) && y <= *(s32 *)((u8 *)arg0 + 0xD8)) {
        flag = 1;
    }
    if (flag != 0) {
        *(s32 *)((u8 *)arg0 + 0xEC) = (y / 16) - 1;
        if (*(u32 *)((u8 *)arg0 + 0xEC) >= *(u32 *)((u8 *)arg0 + 0xB0)) {
            *(s32 *)((u8 *)arg0 + 0xEC) = *(s32 *)((u8 *)arg0 + 0xB0) - 1;
        }
    }
}

#pragma global_optimizer off
void fn_8011CC04(u8 *arg0) {
    s32 a;
    s32 b;
    s32 shifted;
    s32 base;

    arg0[0xF0] = 1;
    a = *(s32 *)(arg0 + 0xB0);
    b = *(s32 *)(arg0 + 0xF8);
    if (a > b) {
        a = b;
    }
    shifted = a << 4;
    base = *(s32 *)(arg0 + 0xC8);
    *(s32 *)(arg0 + 0x64) = base + shifted + 2;
}

#pragma push
#pragma opt_strength_reduction off
void fn_8011CC38(void *arg0, s32 arg1) {
    void *String_CStr(void *);
    void String_Init(void *, char *, void *);
    void String_Destroy(void *, s32);
    s32 fn_800E7FB4(s32, void *);
    void fn_800E3040(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern char lbl_80274A88[];
    extern f32 lbl_8036A240;
    String spA4;
    String sp98;



    UiListRect rect1;



    UiListRect rect1copy;
    String sp6C;
    String sp60;



    UiListRect rect2;



    UiListRect rect2copy;
    String sp34;
    M2C_UNK sp30;
    M2C_UNK sp2C;
    M2C_UNK sp28;
    M2C_UNK sp24;
    M2C_UNK sp20;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r10;
    s32 temp_r10_2;
    s32 temp_r11;
    s32 temp_r24;
    s32 temp_r24_2;
    s32 temp_r24_3;
    s32 temp_r24_4;
    s32 temp_r25;
    s32 temp_r25_2;
    s32 temp_r25_3;
    s32 temp_r29;
    s32 temp_r29_2;
    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r31;
    s32 temp_r4;
    s32 temp_r8;
    s32 temp_r9;
    s32 temp_r9_2;
    s32 var_r23;
    s32 var_r24;
    s32 var_r28;

    temp_r24 = M2C_FIELD(arg0, s32 *, 0x48) + M2C_FIELD(arg0, s32 *, 0x68);
    temp_r31 = M2C_FIELD(arg0, s32 *, 0);
    temp_r30 = M2C_FIELD(arg0, s32 *, 0xC4);
    temp_r25 = M2C_FIELD(arg0, s32 *, 0x4C) + M2C_FIELD(arg0, s32 *, 0x6C);
    temp_r29 = M2C_FIELD(arg0, s32 *, 0xC8);
    if ((s32) M2C_FIELD(arg0, s32 *, 0xB0) != 0) {
        String_Init(&spA4, String_CStr((void *)(M2C_FIELD(arg0, s32 *, 0xB4) + (M2C_FIELD(arg0, s32 *, 0xEC) * 0xC))), &sp30);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), M2C_UNK (**)(void *, s32, s32, void *, s32, s32, f32), 0x20)(arg0, temp_r24, temp_r25, &spA4, 1, 0xFF, lbl_8036A240);
        String_Destroy(&spA4, -1);
    }
    String_Init(&sp98, lbl_80274A88 + 1, &sp2C);
    temp_r24_2 = fn_800E7FB4(temp_r31, &sp98);
    String_Destroy(&sp98, -1);
    sp8 = 0xFF;
    spC = 0xFF;
    sp10 = 0xFF;
    sp14 = 0xFF;
    sp18 = 0;
    fn_800E3040(temp_r24_2, arg1, 1, M2C_FIELD(arg0, s32 *, 0x48) + (M2C_FIELD(arg0, s32 *, 0x60) - 0xE), M2C_FIELD(arg0, s32 *, 0x4C), M2C_FIELD(arg0, s32 *, 0x44), 0x10, 0x10, 255, 255, 255, 255, 0);
    if (((u8) M2C_FIELD(arg0, u8 *, 0x9C) != 0) && ((u8) M2C_FIELD(arg0, u8 *, 0xF0) == 0)) {
        temp_r10 = M2C_FIELD(arg0, s32 *, 0x4C);
        temp_r11 = M2C_FIELD(arg0, s32 *, 0x48);
        temp_r9 = temp_r10 + 0x10;
        rect1copy.y0 = temp_r10;
        temp_r0 = temp_r11 + (M2C_FIELD(arg0, s32 *, 0x60) - 8);
        rect1.x0 = temp_r11;
        rect1.y0 = temp_r10;
        rect1.x1 = temp_r0;
        rect1.y1 = temp_r9;
        rect1copy.x0 = temp_r11;
        rect1copy.x1 = temp_r0;
        rect1copy.y1 = temp_r9;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), M2C_UNK (**)(void *, UiListRect *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x24)(arg0, &rect1, 0, 0xFF, 0xFF, 0x80);
    }
    String_Init(&sp6C, lbl_80274A88 + 7, &sp28);
    temp_r24_3 = fn_800E7FB4(temp_r31, &sp6C);
    String_Destroy(&sp6C, -1);
    sp8 = 0xFF;
    spC = 0xFF;
    sp10 = 0xFF;
    sp14 = 0xFF;
    sp18 = 0;
    fn_800E3040(temp_r24_3, arg1, 0, M2C_FIELD(arg0, s32 *, 0x48), M2C_FIELD(arg0, s32 *, 0x4C), M2C_FIELD(arg0, s32 *, 0x44), temp_r30, temp_r29, 255, 255, 255, 255, 0);
    if ((u8) M2C_FIELD(arg0, u8 *, 0xF0) != 0) {
        temp_r0_2 = M2C_FIELD(arg0, s32 *, 0xB0);
        temp_r4 = M2C_FIELD(arg0, s32 *, 0xF8);
        var_r28 = temp_r0_2;
        temp_r29_2 = M2C_FIELD(arg0, s32 *, 0x48);
        temp_r30_2 = M2C_FIELD(arg0, s32 *, 0x4C) + (M2C_FIELD(arg0, s32 *, 0xC8) + 2);
        if (temp_r0_2 > temp_r4) {
            var_r28 = temp_r4;
        }
        var_r23 = 0;
        temp_r25_2 = temp_r29_2 + M2C_FIELD(arg0, s32 *, 0x68);
        var_r24 = temp_r30_2 + M2C_FIELD(arg0, s32 *, 0x6C);
        while (var_r23 < var_r28) {
            String_Init(&sp60, String_CStr((void *)(M2C_FIELD(arg0, s32 *, 0xB4) + ((var_r23 + M2C_FIELD(arg0, s32 *, 0xF4)) * 0xC))), &sp24);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), M2C_UNK (**)(void *, s32, s32, void *, s32, s32, f32), 0x20)(arg0, temp_r25_2, var_r24, &sp60, 1, 0xFF, lbl_8036A240);
            String_Destroy(&sp60, -1);
            var_r24 += 0x10;
            var_r23 += 1;
        }
        temp_r8 = temp_r29_2 + 4;
        rect2copy.x0 = temp_r8;
        temp_r10_2 = temp_r30_2 + (M2C_FIELD(arg0, s32 *, 0x6C) + ((M2C_FIELD(arg0, s32 *, 0xEC) - M2C_FIELD(arg0, s32 *, 0xF4)) * 0x10));
        rect2.x0 = temp_r8;
        temp_r9_2 = temp_r8 + (M2C_FIELD(arg0, s32 *, 0x60) - 8);
        temp_r0_3 = temp_r10_2 + 0x10;
        rect2.y0 = temp_r10_2;
        rect2.x1 = temp_r9_2;
        rect2.y1 = temp_r0_3;
        rect2copy.y0 = temp_r10_2;
        rect2copy.x1 = temp_r9_2;
        rect2copy.y1 = temp_r0_3;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), M2C_UNK (**)(void *, UiListRect *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x24)(arg0, &rect2, 0, 0xFF, 0xFF, 0x80);
        temp_r24_4 = M2C_FIELD(arg0, s32 *, 0xC4);
        String_Init(&sp34, lbl_80274A88 + 7, &sp20);
        temp_r25_3 = fn_800E7FB4(temp_r31, &sp34);
        String_Destroy(&sp34, -1);
        sp8 = 0xFF;
        spC = 0xFF;
        sp10 = 0xFF;
        sp14 = 0xFF;
        sp18 = 0;
        fn_800E3040(temp_r25_3, arg1, 0, temp_r29_2, temp_r30_2, M2C_FIELD(arg0, s32 *, 0x44), temp_r24_4, (var_r28 * 0x10) + 2, 255, 255, 255, 255, 0);
    }
}
#pragma pop
#pragma optimization_level reset
void ListBox_HandleInput(void *list) {
    void Win_UpdatePos(void *);
    void Win_SetDirty(void *);
    extern void *gPadInput;
    void *owner;
    u32 buttons;

    /* Move list-box cursor with D-pad (1/10 steps) and keep the scroll window in range. */
    Win_UpdatePos(list);
    owner = M2C_FIELD(list, void **, 0x0);
    buttons = M2C_FIELD(gPadInput, u32 *, 0xC);
    if (M2C_FIELD(list, u8 *, 0xF0) != 0) {
        if (buttons & 8) {
            M2C_FIELD(list, s32 *, 0xEC) -= 1;
        } else if (buttons & 4) {
            M2C_FIELD(list, s32 *, 0xEC) += 1;
        } else if (buttons & 1) {
            M2C_FIELD(list, s32 *, 0xEC) -= 10;
        } else if (buttons & 2) {
            M2C_FIELD(list, s32 *, 0xEC) += 10;
        }
        if (M2C_FIELD(list, s32 *, 0xEC) < 0) {
            M2C_FIELD(list, s32 *, 0xEC) = 0;
        }
        if (M2C_FIELD(list, s32 *, 0xEC) >= M2C_FIELD(list, s32 *, 0xB0)) {
            M2C_FIELD(list, s32 *, 0xEC) = M2C_FIELD(list, s32 *, 0xB0) - 1;
        }
        if (M2C_FIELD(list, s32 *, 0xEC) >= M2C_FIELD(list, s32 *, 0xF4) + M2C_FIELD(list, s32 *, 0xF8)) {
            M2C_FIELD(list, s32 *, 0xF4) = M2C_FIELD(list, s32 *, 0xEC) - M2C_FIELD(list, s32 *, 0xF8) + 1;
        } else if (M2C_FIELD(list, s32 *, 0xEC) < M2C_FIELD(list, s32 *, 0xF4)) {
            M2C_FIELD(list, s32 *, 0xF4) = M2C_FIELD(list, s32 *, 0xEC);
        }
        Win_SetDirty(owner);
    }
}

#pragma optimization_level 3
void *fn_8011D118(void *arg0, void *arg1, void *xml) {
    void fn_800E4688(void *);
    void Xml_GetChildValue(char *, void *);
    u8 Xml_AdvanceChild(void *);
    void String_Init(String *, char *, void *);
    void String_Destroy(String *, s32);
    void fn_800CA18C(void *, void *, s32, void *);
    void fn_800C9BC4(void *, void *, s32, void *);
    extern u8 lbl_8028FDD0[];
    char childVal[0x18];
    String name;
    s32 idx;
    char tmp;
    char *pChild;
    u8 *self;

    self = (u8 *)arg0;
    fn_800E4688(self);
    pChild = childVal;
    *(void **)(self + 0x40) = lbl_8028FDD0;
    *(s32 *)(self + 0xAC) = 0;
    *(s32 *)(self + 0xB0) = 0;
    *(s32 *)(self + 0xB4) = 0;
    *(s32 *)(self + 0xB8) = 0;
    *(s32 *)(self + 0xBC) = 0;
    *(s32 *)(self + 0xC0) = 0;
    *(s32 *)(self + 0xD8) = 0;
    *(s32 *)(self + 0xD4) = 0;
    *(s32 *)(self + 0xD0) = 0;
    *(s32 *)(self + 0xCC) = 0;
    *(s32 *)(self + 0xE8) = 0;
    *(s32 *)(self + 0xE4) = 0;
    *(s32 *)(self + 0xE0) = 0;
    *(s32 *)(self + 0xDC) = 0;

    while (Xml_AdvanceChild(xml)) {
        Xml_GetChildValue(childVal, xml);
        String_Init(&name, pChild, &tmp);
        idx = 0;
        fn_800CA18C(self + 0xAC, *(u8 **)(self + 0xB4) + *(s32 *)(self + 0xB0) * 12, 1, &name);
        fn_800C9BC4(self + 0xB8, *(u8 **)(self + 0xC0) + (*(s32 *)(self + 0xBC) << 2), 1, &idx);
        String_Destroy(&name, -1);
    }

    *(s32 *)(self + 0x68) = 8;
    *(s32 *)(self + 0x6C) = 1;
    *(s32 *)(self + 0xC4) = *(s32 *)(self + 0x60);
    *(s32 *)(self + 0xC8) = *(s32 *)(self + 0x64);
    *(s32 *)(self + 0xFC) = 0;
    {
        s32 n;
        s32 w;
        s32 c8;
        n = *(s32 *)(self + 0xB0);
        c8 = *(s32 *)(self + 0xC8);
        w = *(s32 *)(self + 0x60);
        *(s32 *)(self + 0xCC) = 0;
        *(s32 *)(self + 0xD0) = c8;
        *(s32 *)(self + 0xD4) = w;
        *(s32 *)(self + 0xD8) = c8 + (n << 4) + 2;
        w = *(s32 *)(self + 0x60);
        *(s32 *)(self + 0xDC) = w - 0x10;
        *(s32 *)(self + 0xE0) = 0;
        *(s32 *)(self + 0xE4) = w;
        *(s32 *)(self + 0xE8) = 0x10;
        *(s32 *)(self + 0xEC) = 0;
        self[0xF0] = 0;
        *(s32 *)(self + 0xF4) = 0;
        *(s32 *)(self + 0xF8) = 0xA;
    }
    return self;
}
#pragma optimization_level reset
void fn_8011D2AC(void *arg0) {
 void **fn_8007C3BC(void *); void *fn_8007BC3C(void *,s32,s32,u16,void *);
 u8 fn_80109B24(void *); void fn_80079300(void *,u8); void fn_800791F0(void *,void *); void fn_80120F94(void);
 s32 i; u8 *unit=(u8 *)arg0+0x30; u8 *self=*(u8 **)((u8 *)arg0+0x18); u8 *entry;
 for(i=0;i<4;i++) {
 if(*(void **)(self+0x48+i*4)==0) {
 u8 *info; u8 flag; u8 v; void *obj;
 if(gUiInputFlags&3) *(u16 *)(self+0x5c)=0x180;
 info=*fn_8007C3BC(unit); flag=0;
 if((s8)info[3]==(s8)info[5] && (s32)info[4]==0x4c) flag=1;
 if(!flag) *(u16 *)(self+0x5c)|=0x4000;
 obj=fn_8007BC3C(unit,0,0,*(u16 *)(self+0x5c),self);
 entry=self+i*4; *(void **)(entry+0x48)=obj; *(u16 *)(self+0x5c)=0x82;
 if(*(void **)(self+0x58) && fn_80109B24(*(void **)(self+0x58))!=0 && fn_80109B24(*(void **)(self+0x58))!=255) v=fn_80109B24(*(void **)(self+0x58)); else v=255;
 (*(u8 **)(entry+0x48))[0x41]=v-0x4d;
 fn_80079300(*(void **)(entry+0x48),self[0x5e]);
 if(!(gUiInputFlags&3)) fn_800791F0(*(void **)(entry+0x48),self);
 { s32 s=(s8)self[0x5e]; u8 t=self[0x5e]; if(s!=(s8)t) { self[0x65]=t; self[0x5e]=s; fn_80120F94(); } }
 break;
 }}
}

void fn_8011D428(void *arg0) {
    void *fn_8007C3BC(void *);
    char *strcat(char *, s32);
    char *strcpy(char *, char *);
    void fn_8005C8B4(char *);
    extern u8 TalkUi_str[];
    char sp8[0x40];

    strcpy(sp8, (char *)TalkUi_str + 0x2F);
    strcat(sp8, *(s32 *)((char *)fn_8007C3BC((u8 *)arg0 + 0x30) + 8));
    fn_8005C8B4(sp8);
}

u32 fn_8011D484(void) {
    void *Process_Find(void *);
    extern u8 gUiPanelProc[];
    void *p;
    u32 v;

    p = Process_Find(gUiPanelProc);
    if (p != NULL) {
        v = *(u32 *)((u8 *)p + 0x58);
        if (v != 0U) {
            return v;
        }
    }
    return 0U;
}

typedef struct { u16 flags; u16 pad; } Flags;
typedef struct { u8 pad[0x30]; void *x30; void *x34[4]; s32 x44; void *x48[4]; void *x58; } Obj_8011D4C8;
static inline void Shutdown(Obj_8011D4C8 *o) {
    extern u16 gUiPanelFlags;
    extern s32 gUiInputFlags;
    extern u32 lbl_80367A5C;
    void fn_80122C84(void *);
    void fn_8007AD6C(void *);
    void fn_80109020(void *);
    void Process_Unlink(void *);
    void fn_80120F0C(void);
    void fn_800AA208(void);
    s32 i;
    for (i = 0; i < 4; i++) {
        if (o->x34[i]) {
            fn_80122C84(o->x34[i]);
            o->x34[i] = NULL;
        }
    }
    for (i = 0; i < 4; i++) {
        if (o->x48[i]) {
            fn_8007AD6C(o->x48[i]);
            o->x48[i] = NULL;
        }
    }
    o->x30 = NULL;
    if ((*(void * *)&lbl_80367A5C)) {
        fn_80109020((*(void * *)&lbl_80367A5C));
        (*(void * *)&lbl_80367A5C) = NULL;
    }
    if (o->x58) {
        Process_Unlink(o->x58);
        o->x58 = NULL;
    }
    fn_80120F0C();
    if ((*(Flags *)&gUiPanelFlags).flags & 0x80) {
        fn_800AA208();
        (*(Flags *)&gUiPanelFlags).flags &= ~0x80;
    }
    (*(u32 *)&gUiInputFlags) &= ~2;
    (*(Flags *)&gUiPanelFlags).flags = 0;
}
void fn_8011D4C8(void) {
    void Process_Unlink(void *);
    void *Process_Find(void *);
    extern u16 gUiPanelProc[];
    Obj_8011D4C8 *o = Process_Find(((u8 *)gUiPanelProc));
    if (o) {
        Shutdown(o);
        Process_Unlink(o);
    }
}

void fn_8011D5EC(void) {
    extern u8 gUiPanelProc[];
    extern u16 gUiPanelFlags;
    void *Process_Find(void *);
    void UiPanel_ClearShowFlags(u16 *);
    void Process_Goto(void *, s32);
    u8 *obj;

    obj = Process_Find(gUiPanelProc);
    UiPanel_ClearShowFlags(&gUiPanelFlags);
    *(u32 *)(obj + 0x30) = *(u32 *)(obj + 0x30) + 2;
    gUiPanelFlags &= ~0x10;
    Process_Goto(obj, 1);
}

void fn_8011D650(void) {
    extern u8 gUiPanelProc[];
    extern u16 gUiPanelFlags;
    extern s32 gUiInputFlags;
    void *Process_Find(void *);
    void UiPanel_ClearShowFlags(u16 *);
    void Process_MarkActive(void *);
    void Process_Goto(void *, s32);
    void UiPanel_PollSkip(u16 *);
    void UiPanel_Finish(void *);
    void Process_Unlink(void *);
    void fn_80013864(void);
    void *obj;
    u32 flags;

    obj = Process_Find(gUiPanelProc);
    UiPanel_ClearShowFlags(&gUiPanelFlags);
    Process_MarkActive(obj);
    *(s32 *)((u8 *)obj + 0x30) = *(s32 *)((u8 *)obj + 0x30) + 2;
    flags = gUiPanelFlags;
    flags &= ~0x10;
    gUiPanelFlags = flags;
    Process_Goto(obj, 1);
    UiPanel_PollSkip(&gUiPanelFlags);
    if (gUiInputFlags & 3) {
        UiPanel_Finish(obj);
        if (!(gUiPanelFlags & 0x10)) {
            Process_Unlink(obj);
        }
    } else {
        fn_80013864();
    }
}

void fn_8011D6F4(s32 arg0) {
    extern u8 gUiPanelProc[];
    extern u16 gUiPanelFlags;
    extern s32 gUiInputFlags;
    void *Process_Find(void *);
    void UiPanel_ClearShowFlags(u16 *);
    void Process_MarkActive(void *);
    void Process_Goto(void *, s32);
    void UiPanel_PollSkip(u16 *);
    void UiPanel_Finish(void *);
    void Process_Unlink(void *);
    void fn_80013864(void);
    void *obj;
    u32 flags;

    obj = Process_Find(gUiPanelProc);
    UiPanel_ClearShowFlags(&gUiPanelFlags);
    Process_MarkActive(obj);
    *(s32 *)((u8 *)obj + 0x30) = arg0;
    flags = gUiPanelFlags;
    flags &= ~0x10;
    gUiPanelFlags = flags;
    Process_Goto(obj, 1);
    UiPanel_PollSkip(&gUiPanelFlags);
    if (gUiInputFlags & 3) {
        UiPanel_Finish(obj);
        if (!(gUiPanelFlags & 0x10)) {
            Process_Unlink(obj);
        }
    } else {
        fn_80013864();
    }
}

extern u16 TalkUi_str[];
extern u16 gTalkUiLastMsg[];
extern u16 gUiPanelProc[];
/* Expand msg, show it on the UI panel, then finish sync or yield. */
void TalkUi_ShowMsg(void *msg) {
    s32 DebugPrint(const char *, ...);
    void *Msg_Expand(void *);
    void Str_CopyPad(void *, const void *, s32);
    extern u16 gUiPanelFlags;
    extern s32 gUiInputFlags;
    void *Process_Find(void *);
    void UiPanel_ClearShowFlags(u16 *);
    void Process_MarkActive(void *);
    void Process_Goto(void *, s32);
    void UiPanel_PollSkip(u16 *);
    void UiPanel_Finish(void *);
    void Process_Unlink(void *);
    void fn_80013864(void);
    void *expanded;
    void *panel;
    u32 flags;

    DebugPrint((char *)TalkUi_str + 0x35, msg);
    expanded = Msg_Expand(msg);
    Str_CopyPad(gTalkUiLastMsg, msg, 0x1E);
    panel = Process_Find(gUiPanelProc);
    UiPanel_ClearShowFlags(&gUiPanelFlags);
    Process_MarkActive(panel);
    *(void **)((u8 *)panel + 0x30) = expanded;
    flags = gUiPanelFlags;
    flags &= ~0x10;
    gUiPanelFlags = flags;
    Process_Goto(panel, 1);
    UiPanel_PollSkip(&gUiPanelFlags);
    if (gUiInputFlags & 3) {
        UiPanel_Finish(panel);
        if (!(gUiPanelFlags & 0x10)) {
            Process_Unlink(panel);
        }
    } else {
        fn_80013864();
    }
}

void fn_8011D87C(void *arg0)
{
    s32 DebugPrint(const char *, ...);
    void *Msg_Expand(void *);
    void Str_CopyPad(void *, const void *, s32);
    void *Process_Find(void *);
    void Process_Goto(void *, u8);

    void *result;
    u8 *obj;
    u16 flags;

    DebugPrint((char *)TalkUi_str + 0x35, arg0);

    result = Msg_Expand(arg0);

    Str_CopyPad(gTalkUiLastMsg, arg0, 0x1E);

    obj = (u8 *)Process_Find(gUiPanelProc);
    *(void **)(obj + 0x30) = result;

    flags = gUiPanelFlags;
    flags &= ~0x10;
    gUiPanelFlags = flags;

    Process_Goto(obj, 1);
}

void fn_8011D908(void *msg, void *parent) {
    s32 DebugPrint(const char *, ...);
    void *Msg_Expand(void *);
    void Str_CopyPad(void *, const void *, s32);
    void UiPanel_ClearFlags(u16 *);
    void *Process_CreateEx(void *, void *);
    void fn_8012205C(void *);
    void UiPanel_PollSkip(u16 *);
    void UiPanel_Finish(void *);
    void Process_Unlink(void *);
    void fn_80013864(void);
    extern u16 TalkUi_str[];
    extern u16 gTalkUiLastMsg[];
    extern u16 gUiPanelFlags;
    extern u16 gUiPanelProc[];
    extern u8 lbl_8032BDE8[];
    extern s32 gUiInputFlags;
    void *expanded;
    u8 *panel;

    DebugPrint((char *)TalkUi_str + 0x52, msg);
    expanded = Msg_Expand(msg);
    Str_CopyPad(gTalkUiLastMsg, msg, 0x1E);
    UiPanel_ClearFlags(&gUiPanelFlags);
    panel = (u8 *)Process_CreateEx(gUiPanelProc, parent);
    *(s32 *)(panel + 0x34) = 0;
    *(s32 *)(panel + 0x38) = 0;
    *(s32 *)(panel + 0x3C) = 0;
    *(s32 *)(panel + 0x40) = 0;
    *(s32 *)(panel + 0x48) = 0;
    *(s32 *)(panel + 0x4C) = 0;
    *(s32 *)(panel + 0x50) = 0;
    *(s32 *)(panel + 0x54) = 0;
    *(s32 *)(panel + 0x58) = 0;
    *(s32 *)(panel + 0x44) = 0;
    *(s8 *)(panel + 0x5E) = -1;
    *(s8 *)(panel + 0x65) = -1;
    *(void **)(panel + 0x30) = expanded;
    panel[0x5F] = 1;
    *(s16 *)(panel + 0x68) = 0x10B;
    panel[0x63] = 0;
    *(s16 *)(panel + 0x5C) = 0x82;
    panel[0x61] = 0;
    panel[0x60] = 0;
    panel[0x62] = 1;
    fn_8012205C(lbl_8032BDE8);
    panel[0x66] = 1;
    UiPanel_PollSkip(&gUiPanelFlags);
    if (gUiInputFlags & 1) {
        UiPanel_Finish(panel);
        if (!(gUiPanelFlags & 0x10)) {
            Process_Unlink(panel);
        }
    } else {
        fn_80013864();
    }
}

void UiPanel_Create(void *owner, void *parent) {
    void UiPanel_ClearFlags(void *);
    void *Process_CreateEx(void *, void *);
    void fn_8012205C(void *);
    void UiPanel_PollSkip(void *);
    void UiPanel_Finish(void *);
    void Process_Unlink(void *);
    void fn_80013864(void);
    extern u16 gUiPanelFlags;
    extern u16 gUiPanelProc[];
    extern u8 lbl_8032BDE8[];
    extern s32 gUiInputFlags;
    u8 *panel;

    /* Create the UI panel process, init its slots, and run or yield for input. */
    UiPanel_ClearFlags(&gUiPanelFlags);
    panel = (u8 *)Process_CreateEx(gUiPanelProc, parent);
    *(s32 *)(panel + 0x34) = 0;
    *(s32 *)(panel + 0x38) = 0;
    *(s32 *)(panel + 0x3C) = 0;
    *(s32 *)(panel + 0x40) = 0;
    *(s32 *)(panel + 0x48) = 0;
    *(s32 *)(panel + 0x4C) = 0;
    *(s32 *)(panel + 0x50) = 0;
    *(s32 *)(panel + 0x54) = 0;
    *(s32 *)(panel + 0x58) = 0;
    *(s32 *)(panel + 0x44) = 0;
    *(s8 *)(panel + 0x5E) = -1;
    *(s8 *)(panel + 0x65) = -1;
    *(void **)(panel + 0x30) = owner;
    panel[0x5F] = 1;
    *(s16 *)(panel + 0x68) = 0x10B;
    panel[0x63] = 0;
    *(s16 *)(panel + 0x5C) = 0x82;
    panel[0x61] = 0;
    panel[0x60] = 0;
    panel[0x62] = 1;
    fn_8012205C(lbl_8032BDE8);
    panel[0x66] = 1;
    UiPanel_PollSkip(&gUiPanelFlags);
    if (gUiInputFlags & 1) {
        UiPanel_Finish(panel);
        if (!(gUiPanelFlags & 0x10)) {
            Process_Unlink(panel);
        }
    } else {
        fn_80013864();
    }
}

typedef struct { u8 pad[0x30]; void *x30; void *x34[4]; void *x44; void *x48[4]; void *x58; u8 pad2[7]; u8 x63; u8 pad3[4]; s16 x68; } Obj_8011DB48;
typedef struct { u8 pad[0x6a]; u8 x6a, x6b; } Win;
typedef struct { u8 pad[8]; void *x8; void *xc; void *x10; s16 x14, x16, x18, x1a, x1c; u8 x1e, x1f, x20, x21, x22, x23, x24, x25; } Cfg;
static inline Win *New(Obj_8011DB48 *o) {
    void *fn_80122998(Obj_8011DB48 *);
    Win *fn_80122CE0(void *); Win *w = NULL; s32 i;
    for (i = 0; i < 4; i++) {
        if (o->x34[i] == NULL) {
            o->x34[i] = fn_80122998(o);
            w = fn_80122CE0(o->x34[i]);
            o->x44 = o->x34[i];
            break;
        }
    }
    return w; }
void fn_8011DB48(void *c_) {
    Cfg *c = (Cfg *)c_;
    extern u16 gUiPanelProc[];
    extern u32 lbl_80367A5C;
    Obj_8011DB48 *Process_Find(void *);
    void fn_80122E34(Win *, void *);
    void fn_80122E28(Win *, s32, s32);
    void fn_80122E10(Win *, s32);
    void fn_80122E04(Win *, s32, s32);
    void fn_80122E20(Win *, s32);
    void fn_80122E18(Win *, s32);
    void fn_80122DFC(Win *, s32);
    void fn_80122DEC(Win *, void *, s32, s32);
    void *Sound_Create(void *, Obj_8011DB48 *);
    void Sound_FadeFromZero(void *, s32);
    Obj_8011DB48 *o = Process_Find(((u8 *)gUiPanelProc));
    Win *w = New(o);
    fn_80122E34(w, c->x8);
    fn_80122E28(w, c->x14, c->x16);
    fn_80122E10(w, c->x1c);
    fn_80122E04(w, c->x1e, c->x1f);
    fn_80122E20(w, c->x20);
    fn_80122E18(w, c->x21);
    fn_80122DFC(w, c->x22);
    w->x6a = c->x23;
    fn_80122DEC(w, c->x10, c->x18, c->x1a);
    w->x6b = c->x25;
    (*(void * *)&lbl_80367A5C) = c->xc;
    o->x63 = c->x24 != 0;
    if (c->x24 == 0 && c->xc != NULL) {
        Sound_FadeFromZero(Sound_Create(c->xc, o), (u8)o->x68);
    }
}

void fn_8011DCB4(void) {
    M2C_UNK fn_8008A290(M2C_UNK, M2C_UNK);
    fn_8008A290(2, 0x10B);
}

void fn_8011DCDC(void *arg0) {
    fn_8008A290(3, M2C_FIELD(arg0, s16 *, 0x68));
}

void fn_8011DD08(void *arg0) {
    s32 fn_8008A56C();
    if (fn_8008A56C() & 2) {
        if (fn_8008A56C() & 4) {
            M2C_FIELD(arg0, s8 *, 0x64) = 2;
            return;
        }
        if (fn_8008A56C() & 8) {
            M2C_FIELD(arg0, s8 *, 0x64) = 5;
            return;
        }
        goto block_5;
    }
block_5:
    fn_8008A290(3, M2C_FIELD(arg0, s16 *, 0x68));
    M2C_FIELD(arg0, s8 *, 0x64) = 2;
}

void fn_8011DD80(void *arg0)
{
    void fn_800AA1CC(void *);
    void Sound_Create(void *, void *);

    extern u16 gUiPanelFlags;
    extern void *lbl_80367A5C;

    void *ptr;

    fn_800AA1CC(arg0);

    gUiPanelFlags |= 0x80;

    ptr = lbl_80367A5C;

    if (ptr != 0) {
        Sound_Create(ptr, arg0);
    }
}

extern u32 lbl_80367A5C;
typedef struct { u8 pad[0x30]; void *x30; void *x34[4]; s32 x44; void *x48[4]; void *x58; } Obj_8011DDCC;
static inline void Free1(Obj_8011DDCC *o, void *z) {
    void fn_80122C84(void *); s32 i; for (i = 0; i < 4; i++) { if (o->x34[i]) { fn_80122C84(o->x34[i]); o->x34[i] = z; } } }
static inline void Free3(Obj_8011DDCC *o, void *z) {
    void fn_8007AD6C(void *); s32 i; for (i = 0; i < 4; i++) { if (o->x48[i]) { fn_8007AD6C(o->x48[i]); o->x48[i] = z; } } }
void fn_8011DDCC(void *o_) {
    Obj_8011DDCC *o = (Obj_8011DDCC *)o_;
    extern u16 gUiPanelFlags;
    extern s32 gUiInputFlags;
    extern u32 lbl_80367A5C;
    void fn_80109020(void *);
    void Process_Unlink(void *);
    void fn_80120F0C(void);
    void fn_800AA208(void);
    s32 i;
    Free1(o, NULL);
    Free3(o, NULL);
    o->x30 = NULL;
    if ((*(void * *)&lbl_80367A5C)) {
        fn_80109020((*(void * *)&lbl_80367A5C));
        (*(void * *)&lbl_80367A5C) = NULL;
    }
    if (o->x58) {
        Process_Unlink(o->x58);
        o->x58 = NULL;
    }
    fn_80120F0C();
    if ((*(Flags *)&gUiPanelFlags).flags & 0x80) {
        fn_800AA208();
        (*(Flags *)&gUiPanelFlags).flags &= ~0x80;
    }
    (*(u32 *)&gUiInputFlags) &= ~2;
    (*(Flags *)&gUiPanelFlags).flags = 0;
}

void UiPanel_Finish(void *arg0) {
void Process_Goto(void *, s32);
void Process_Unlink(void *);
void fn_800790D4(void *, void *);
void fn_8007AD6C(void *);
void fn_80089650(s32, s32);
void fn_800AA208(void);
void fn_80109020(void *);
void *Sound_FindByName(void *);
void fn_80109BB4(void *, u8);
void fn_8011E12C(void *);
void fn_80120F0C(void);
void fn_80120F94(void);
void fn_80122000(void *);
void fn_80122238(void *, void *);
void fn_80122C84(void *);
extern u8 lbl_8032BDE8[];
u8 *p;
u32 nv[2];
void *self;
self = arg0;
while (!(gUiPanelFlags & 0x20)) {
fn_8011E12C(self);
}
if (gUiPanelFlags & 0x10) {
Process_Goto(self, 2);
return;
}
fn_80122000(lbl_8032BDE8);
if ((gUiInputFlags & 2) && (*(u8 *)((u8 *)self + 0x63) != 0) && !(gUiInputFlags & 1)) {
fn_80089650(2, 0x85);
}
if (gUiInputFlags & 3) {
nv[1] = 0;
p = self;
nv[0] = nv[1];
do {
void *obj = *(void **)(p + 0x34);
if (obj) {
fn_80122C84(obj);
*(s32 *)(p + 0x34) = (s32)nv[0];
}
nv[1] += 1;
p += 4;
} while ((s32)nv[1] < 4);
{
u8 *p2;
u32 nv2[2];
nv2[1] = 0;
p2 = self;
nv2[0] = nv2[1];
do {
void *obj = *(void **)(p2 + 0x48);
if (obj) {
fn_8007AD6C(obj);
*(s32 *)(p2 + 0x48) = (s32)nv2[0];
}
nv2[1] += 1;
p2 += 4;
} while ((s32)nv2[1] < 4);
}
*(s32 *)((u8 *)self + 0x30) = 0;
if (lbl_80367A5C != 0) {
fn_80109020((void *)lbl_80367A5C);
lbl_80367A5C = 0;
}
if (*(void **)((u8 *)self + 0x58) != NULL) {
Process_Unlink(*(void **)((u8 *)self + 0x58));
*(s32 *)((u8 *)self + 0x58) = 0;
}
fn_80120F0C();
if (gUiPanelFlags & 0x80) {
fn_800AA208();
*(volatile u16 *)&gUiPanelFlags &= ~0x80;
}
{
s32 t = gUiInputFlags;
*(volatile u16 *)&gUiPanelFlags = 0;
gUiInputFlags = t & ~2;
Process_Goto(self, 4);
}
return;
}
if (*(u8 *)((u8 *)self + 0x63) != 0) {
Process_Goto(self, 3);
return;
}
fn_80120F94();
{
void *p2;
s32 i2;
i2 = 0;
p2 = self;
do {
void *obj = *(void **)((u8 *)p2 + 0x34);
if (obj != NULL) {
fn_80122238(obj, self);
}
i2 += 1;
p2 = (u8 *)p2 + 4;
} while (i2 < 4);
}
{
void *p2;
s32 i2;
i2 = 0;
p2 = self;
do {
void *obj = *(void **)((u8 *)p2 + 0x48);
if (obj != NULL) {
if (gUiInputFlags & 3) {
fn_8007AD6C(obj);
} else {
fn_800790D4(obj, self);
}
}
i2 += 1;
p2 = (u8 *)p2 + 4;
} while (i2 < 4);
}
if (lbl_80367A5C != 0) {
fn_80109BB4(Sound_FindByName((void *)lbl_80367A5C), (u8)((*(s16 *)((u8 *)self + 0x68) * 0x3C) / 1000));
}
}

#pragma push
#pragma optimization_level 4
s32 fn_8011E12C(void *arg0) {
    u8 fn_8011E4B8(void *, void *, u16);
    void Process_ClearFunc(void *);
    u8 fn_801229C4(void *);
    void fn_801226D0(void *, void *);
    void fn_801222A4(void *, void *);
    void fn_80121D60(void *, void *);
    void Ui_SetTooltip(void *, s32, s32, void *);
    u8 fn_80109B24(void *);
    void Obj_StartTintEase(void *, u8);
    void fn_80122114(void *, u8);
    void fn_80122A2C(void *, u8);
    extern u16 gUiPanelFlags;
    extern u8 lbl_8032BDE8[];
    struct Item {
        u8 pad[0x34];
        void **unk34;
        f32 unk38;
        f32 unk3C;
        u8 pad40[3];
        u8 unk43;
    };
    struct Obj {
        u8 pad0[0x30];
        u8 *text;
        void *pad34[4];
        void *unk44;
        struct Item *items[4];
        void *unk58;
        u8 pad5C[2];
        u8 unk5E;
        u8 pad5F;
        u8 unk60;
        u8 pad61;
        u8 unk62;
        u8 pad63[2];
        u8 unk65;
        u8 pad66;
        u8 unk67;
    };
    struct Sda {
        u16 unk0;
        u16 unk2;
    };
    struct Obj *self;
    struct Sda *sda;
    struct Item *slot;
    u16 old;
    s32 code;
    s8 idx;
    struct Item *it;
    s32 i;
    u8 ch;
    u8 v;
    u8 *text;
    struct Obj *cur;

    self = (struct Obj *)arg0;
    sda = (struct Sda *)&gUiPanelFlags;
    old = sda->unk2;
    sda->unk2 = (u16)(old + 1);
    code = (u8)fn_8011E4B8(self, &self->text, old);
    switch (code) {
    case 0:
        Process_ClearFunc(self);
        return 0;
    case 2:
        return 2;
    default:
        break;
    }
    if (fn_801229C4(self->unk44) != 0) {
        fn_801226D0(self->unk44, self);
        return 2;
    }
    if (*(u8 *)((u8 *)self->unk44 + 0x68) == 0) {
        fn_801222A4(self->unk44, self);
        return 2;
    }
    ch = self->unk5E;
    if ((s8)ch < 0) {
        idx = -1;
    } else if (self->items[0] != 0 && (s8)self->items[0]->unk43 == (s8)ch) {
        idx = 0;
    } else if (self->items[1] != 0 && (s8)self->items[1]->unk43 == (s8)ch) {
        idx = 1;
    } else if (self->items[2] != 0 && (s8)self->items[2]->unk43 == (s8)ch) {
        idx = 2;
    } else if (self->items[3] != 0 && (s8)self->items[3]->unk43 == (s8)ch) {
        idx = 3;
    } else {
        idx = -1;
    }
    if ((s8)idx < 0) {
        slot = 0;
    } else {
        slot = self->items[idx];
    }
    if (slot != 0) {
        fn_80121D60(lbl_8032BDE8, *slot->unk34);
        if (self->unk67 == 0) {
            self->unk67 = 1;
            Ui_SetTooltip(*slot->unk34, (s32)slot->unk38, (s32)slot->unk3C, self);
            ch = self->unk5E;
            if ((s8)self->unk65 != (s8)ch) {
                self->unk65 = ch;
                cur = self;
                i = 0;
                do {
                    it = *(struct Item **)((u8 *)cur + 0x48);
                    if (it != 0) {
                        if ((s8)it->unk43 == (s8)self->unk5E) {
                            if (self->unk58 != 0 && fn_80109B24(self->unk58) != 0
                                && (u8)fn_80109B24(self->unk58) != 0xFF) {
                                v = fn_80109B24(self->unk58);
                            } else {
                                v = 0xFF;
                            }
                            Obj_StartTintEase(*(void **)((u8 *)cur + 0x48), v);
                        } else {
                            if (self->unk58 != 0 && fn_80109B24(self->unk58) != 0
                                && (u8)fn_80109B24(self->unk58) != 0xFF) {
                                v = fn_80109B24(self->unk58);
                            } else {
                                v = 0xFF;
                            }
                            Obj_StartTintEase(*(void **)((u8 *)cur + 0x48), (u8)(v - 0x4D));
                        }
                    }
                    i += 1;
                    cur = (struct Obj *)((u8 *)cur + 4);
                } while (i < 4);
            }
        }
    }
    text = self->text;
    ch = *text;
    if ((s8)ch >= 0x20 && (s8)ch < 0x7F) {
        fn_80122114(lbl_8032BDE8, ch);
        text = self->text;
        self->text = text + 1;
        fn_80122A2C(self->unk44, *text);
    } else {
        fn_80122114(lbl_8032BDE8, ch);
        text = self->text;
        self->text = text + 1;
        fn_80122A2C(self->unk44, *text);
        fn_80122114(lbl_8032BDE8, *self->text);
        text = self->text;
        self->text = text + 1;
        fn_80122A2C(self->unk44, *text);
    }
    self->unk60 = self->unk62;
    return 3;
}
#pragma pop

#pragma push
#pragma opt_strength_reduction off
u8 fn_8011E4B8(void *arg0, void *arg1, u16 arg2)
{
    extern u16 gUiPanelFlags;
    extern s32 gUiInputFlags;
    extern u32 lbl_80367A5C;
    extern s32 gBattleState[];
    extern u8 lbl_8032BDE8[];
    extern u8 lbl_8032FE24[];
    extern u16 TalkUi_str[];

    void fn_801220B8(void *);
    void fn_801229F8(void *);
    void fn_80121D60(void *, void *);
    void Ui_SetTooltip(void *, s32, s32, void *);
    u8 fn_80109B24(void *);
    void Obj_StartTintEase(void *, u8);
    s32 fn_80010710(u8 *);
    void fn_80122114(void *, u8);
    void fn_80122A2C(void *, u8);
    void TalkUi_SpawnKeyWait2(void *, void *, u8);
    void fn_801225D4(void *, void *);
    s32 TalkUi_LayoutSlot(void *, u32);
    void fn_80120F94(void);
    void *fn_80049DA4(s32, s32, u32);
    void fn_8011FB58(void *, s32);
    void fn_80122238(void *, void *);
    void fn_8007AD6C(void *);
    void fn_800790D4(void *, void *);
    void fn_80079198(void *, void *);
    void fn_800791F0(void *, void *);
    void fn_801222A4(void *, void *);
    void fn_80122170(void *, void *, s32);
    u8 fn_8011F184(void *, u8 **);
    void *Sound_FindByName(void *);
    void Sound_FadeToVol(void *, s32);
    void Sound_FadeFromZero(void *, s32);
    void *Sound_Create(void *, void *);
    void Process_Goto(void *, s32);
    void Process_DetachChild(void *);
    s32 Str_Cmp(void *, void *);
    void *fn_8014D8FC(void *);
    void fn_8008A290(s32, s32);

    struct Item {
        u8 pad[0x34];
        void **unk34;
        f32 unk38;
        f32 unk3C;
        u8 pad40[3];
        u8 unk43;
    };
    struct Obj {
        u8 pad0[0x18];
        void *unk18;
        u8 pad1C[0x14];
        u8 *text;
        void *pad34[4];
        void *unk44;
        struct Item *items[4];
        void *unk58;
        u8 pad5C[2];
        s8 unk5E;
        u8 pad5F;
        u8 unk60;
        u8 pad61;
        u8 unk62;
        u8 unk63;
        u8 unk64;
        u8 unk65;
        u8 unk66;
        u8 unk67;
        s16 unk68;
    };

    struct Obj *self;
    u8 **textRef;
    u8 *text;
    struct Item *item;
    u8 *buffer;
    u8 *soundName;
    void *object;
    void *sound;
    s32 ch;
    s32 command;
    s32 index;
    u8 selected;
    s32 count;
    s32 i;
    struct Obj *cur;
    s32 result;
    u8 color;
    s32 speed;
    u8 oldSlot;
    s8 idx;
    s32 bit;

    self = (struct Obj *)arg0;
    textRef = (u8 **)arg1;

    text = *textRef;
    ch = *text;

    if ((s8)ch == 0) {
        gUiPanelFlags |= 0x20;
        return 0;
    }

    if ((s8)ch == 0xA) {
        fn_801220B8(lbl_8032BDE8);
        fn_801229F8(self->unk44);
        text = *textRef;
        *textRef = text + 1;
        return 1;
    }

    if ((s8)ch == '#') {
        selected = self->unk5E;
        if ((s8)selected < 0) {
            idx = -1;
        } else if (self->items[0] != 0 && (s8)self->items[0]->unk43 == (s8)selected) {
            idx = 0;
        } else if (self->items[1] != 0 && (s8)self->items[1]->unk43 == (s8)selected) {
            idx = 1;
        } else if (self->items[2] != 0 && (s8)self->items[2]->unk43 == (s8)selected) {
            idx = 2;
        } else if (self->items[3] != 0 && (s8)self->items[3]->unk43 == (s8)selected) {
            idx = 3;
        } else {
            idx = -1;
        }

        if (idx < 0) {
            item = 0;
        } else {
            item = self->items[idx];
        }

        if (item != 0) {
            fn_80121D60(lbl_8032BDE8, *item->unk34);
            if (self->unk67 == 0) {
                self->unk67 = 1;
                Ui_SetTooltip(*item->unk34, (s32)item->unk38, (s32)item->unk3C, self);
                if ((s8)self->unk65 != (s8)self->unk5E) {
                    self->unk65 = self->unk5E;
                    cur = self;
                    i = 0;
                    do {
                        item = *(struct Item **)((u8 *)cur + 0x48);
                        if (item != 0) {
                            if ((s8)item->unk43 == (s8)self->unk5E) {
                                if (self->unk58 != 0 && fn_80109B24(self->unk58) != 0
                                    && (u8)fn_80109B24(self->unk58) != 0xFF) {
                                    color = fn_80109B24(self->unk58);
                                } else {
                                    color = 0xFF;
                                }
                                Obj_StartTintEase(*(void **)((u8 *)cur + 0x48), color);
                            } else {
                                if (self->unk58 != 0 && fn_80109B24(self->unk58) != 0
                                    && (u8)fn_80109B24(self->unk58) != 0xFF) {
                                    color = fn_80109B24(self->unk58);
                                } else {
                                    color = 0xFF;
                                }
                                Obj_StartTintEase(*(void **)((u8 *)cur + 0x48), (u8)(color - 0x4D));
                            }
                        }
                        i += 1;
                        cur = (struct Obj *)((u8 *)cur + 4);
                    } while (i < 4);
                }
            }
        }

        count = fn_80010710(*textRef);
        i = 0;
        while (i < count) {
            text = *textRef;
            fn_80122114(lbl_8032BDE8, *text);
            object = self->unk44;
            text = *textRef;
            *textRef = text + 1;
            fn_80122A2C(object, *text);
            i++;
        }
        return 1;
    }

    if ((s8)ch != '$') {
        return 3;
    }

    text = *textRef;
    *textRef = text + 1;
    text = *textRef;
    *textRef = text + 1;
    command = (s8)*text;

    switch (command) {
    case 'K':
        self->unk60 = 0;
        text = *textRef;
        TalkUi_SpawnKeyWait2(self->unk44, self, (s8)text[1] == 'P');
        return 2;

    case 'P':
    clear_box:
        fn_801220B8(lbl_8032BDE8);
        object = self->unk44;
        if (object != 0) {
            fn_801225D4(object, self);
        }
        return 2;

    case 'c':
        text = *textRef;
        *textRef = text + 1;
        index = (u8)(*text - '0');
        *textRef -= 3;
        TalkUi_LayoutSlot(self, index);
        text = *textRef;
        *textRef = text + 3;
        oldSlot = self->unk5E;
        if ((s8)oldSlot != index) {
            self->unk65 = oldSlot;
            self->unk5E = (s8)index;
            fn_80120F94();
        }
        buffer = lbl_8032FE24;
        while ((s8)**textRef != '|') { *buffer++ = *(*textRef)++; }
        *buffer = 0;
        text = *textRef;
        *textRef = text + 1;
        object = fn_80049DA4((s32)((u8 *)TalkUi_str + 0x6F), (s32)lbl_8032FE24, 0);
        fn_8011FB58(self, (s32)object);
        return 2;

    case 'd':
        text = *textRef;
        *textRef = text + 1;
        index = (u8)(*text - '0');
        *textRef -= 3;
        TalkUi_LayoutSlot(self, index);
        text = *textRef;
        *textRef = text + 3;
        oldSlot = self->unk5E;
        if ((s8)oldSlot == index) {
            result = 0;
        } else {
            self->unk65 = oldSlot;
            self->unk5E = (s8)index;
            fn_80120F94();
            result = 1;
        }
        if ((u8)result == 0) {
            fn_80120F94();
        }
        if (!(gUiInputFlags & 3)) {
            fn_80122238(self->unk44, self);
        }
        selected = self->unk5E;
        if ((s8)selected < 0) {
            idx = -1;
        } else if (self->items[0] != 0 && (s8)self->items[0]->unk43 == (s8)selected) {
            idx = 0;
        } else if (self->items[1] != 0 && (s8)self->items[1]->unk43 == (s8)selected) {
            idx = 1;
        } else if (self->items[2] != 0 && (s8)self->items[2]->unk43 == (s8)selected) {
            idx = 2;
        } else if (self->items[3] != 0 && (s8)self->items[3]->unk43 == (s8)selected) {
            idx = 3;
        } else {
            idx = -1;
        }
        if (gUiInputFlags & 3) {
            fn_8007AD6C(self->items[idx]);
        } else {
            fn_800790D4(self->items[idx], self);
        }
        self->items[idx] = 0;
        self->unk5E = -1;
        return 2;

    case 's':
        text = *textRef;
        *textRef = text + 1;
        index = (u8)(*text - '0');
        if ((s8)self->unk5E != index) {
            self->unk65 = self->unk5E;
            self->unk5E = (s8)index;
            fn_80120F94();
        }
        object = self->pad34[index];
        if (object != 0 && *(u8 *)((u8 *)object + 0x68) != 0) {
            *textRef -= 3;
            TalkUi_LayoutSlot(self, index);
            *textRef += 3;
            goto clear_box;
        }
        return 1;

    case 'W':
        text = *textRef;
        ch = *text;
        switch ((s8)ch) {
        case 'D':
            *textRef = text + 1;
            if (!(gUiInputFlags & 3)) {
                fn_80122238(self->unk44, self);
            }
            fn_80120F94();
            return 2;
        case '-':
            *textRef = text + 1;
            if (!(gUiInputFlags & 3)) {
                if (lbl_80367A5C != 0) {
                    sound = Sound_FindByName((void *)lbl_80367A5C);
                    Sound_FadeToVol(sound, 8);
                }
                i = 0;
                cur = self;
                do {
                    object = *(void **)((u8 *)cur + 0x34);
                    if (object != 0) fn_80122238(object, self);
                    i++;
                    cur = (struct Obj *)((u8 *)cur + 4);
                } while (i < 4);
                i = 0;
                cur = self;
                do {
                    object = *(void **)((u8 *)cur + 0x48);
                    if (object != 0) fn_80079198(object, self);
                    i++;
                    cur = (struct Obj *)((u8 *)cur + 4);
                } while (i < 4);
            }
            return 2;
        case '+':
            *textRef = text + 1;
            if (!(gUiInputFlags & 3)) {
                if (lbl_80367A5C != 0) {
                    sound = Sound_FindByName((void *)lbl_80367A5C);
                    Sound_FadeFromZero(sound, 8);
                }
                i = 0;
                cur = self;
                do {
                    object = *(void **)((u8 *)cur + 0x34);
                    if (object != 0) fn_801222A4(object, self);
                    i++;
                    cur = (struct Obj *)((u8 *)cur + 4);
                } while (i < 4);
                i = 0;
                cur = self;
                do {
                    object = *(void **)((u8 *)cur + 0x48);
                    if (object != 0) fn_800791F0(object, self);
                    i++;
                    cur = (struct Obj *)((u8 *)cur + 4);
                } while (i < 4);
            }
            return 2;
        default:
            text = *textRef;
            *textRef = text + 1;
            index = (u8)(*text - '0');
            result = TalkUi_LayoutSlot(self, index);
            return (u8)result ? 2 : 1;
        }

    case 'w':
        self->unk60 = 0;
        text = *textRef;
        object = self->unk44;
        *textRef = text + 1;
        index = (s8)*text - '0';
        fn_80122170(object, self, 1 << index);
        bit = gUiPanelFlags & 0x200;
        return 2 + ((-bit | bit) >> 31);

    case 'Y':
        return 2;

    case 'F':
        return fn_8011F184(self, textRef);

    case 'R':
        buffer = lbl_8032FE24;
        while ((s8)**textRef != '|') { *buffer++ = *(*textRef)++; }
        *buffer = 0;
        text = *textRef;
        *textRef = text + 1;
        sound = fn_80049DA4((s32)((u8 *)TalkUi_str + 0x74), (s32)lbl_8032FE24, 0);
        Sound_Create(sound, self);
        if (self->unk63 != 0 && !(gUiInputFlags & 3)) {
            Process_Goto(self, 0);
            return 2;
        }
        return 1;

    case '<':
        fn_8008A290(self->unk64, self->unk68);
        return 1;

    case '>':
        fn_8008A290(3, self->unk68);
        return 1;

    case 'B':
        buffer = lbl_8032FE24;
        while ((s8)**textRef != '|') { *buffer++ = *(*textRef)++; }
        *buffer = 0;
        text = *textRef;
        *textRef = text + 1;
        soundName = lbl_8032FE24;
        if (Str_Cmp(soundName, (u8 *)TalkUi_str + 0x79) == 0) {
            soundName = (u8 *)TalkUi_str + 0x82;
            object = fn_8014D8FC(gBattleState);
            if (object != 0) {
                soundName = *(u8 **)((u8 *)object + 0x50) + 4;
            }
        }
        if (!(gUiInputFlags & 3)) {
            sound = fn_80049DA4((s32)((u8 *)TalkUi_str + 0x74), (s32)soundName, 0);
            self->unk58 = Sound_Create(sound, self);
        }
        return 1;

    case 'U':
        if (self->unk18 == 0) {
            text = *textRef;
            *textRef = text + 1;
            return 1;
        }
        text = *textRef;
        switch ((s8)*text) {
        case 'b':
            gUiPanelFlags |= 0x100;
        case 'B':
            ++*textRef;
            Process_DetachChild(self);
            return 1;
        default:
            goto invalid_command;
        }

    case 'H':
        self->unk60 = 0;
        text = *textRef;
        *textRef = text - 2;
        gUiPanelFlags |= 0x30;
        return 2;

    case 'D':
        text = *textRef;
        if ((s8)*text == 'C') {
            *textRef = text + 1;
            gUiPanelFlags |= 8;
            return 1;
        }
        goto invalid_command;

    case 'S':
        text = *textRef;
        ch = *text;
        if ((s8)ch == 'D') {
            *textRef = text + 1;
            gUiPanelFlags |= 8;
            return 1;
        }
        if ((s8)ch == 'E') {
            *textRef = text + 1;
            gUiPanelFlags &= ~8;
            return 1;
        }
    case 'N':
        text = *textRef;
        if ((s8)*text == 'D') {
            *textRef = text + 1;
            gUiPanelFlags ^= 0x40;
            return 1;
        }
        fn_801220B8(lbl_8032BDE8);
        fn_801229F8(self->unk44);
        return 1;

    case 'M':
        text = *textRef;
        switch ((s8)*text) {
        case 'C':
            self->unk62 = 0;
            ++*textRef;
            break;
        case 'D':
            self->unk62 = 1;
            ++*textRef;
            break;
        }
        return 1;

    case 'O':
        text = *textRef;
        *textRef = text + 1;
        self->unk66 = (u8)(*text - '0');
        return 1;

    case '=':
        text = *textRef;
        *textRef = text + 1;
        self->unk68 = ((s8)*text - '0') * 1000;
        text = *textRef;
        speed = self->unk68;
        *textRef = text + 1;
        self->unk68 = speed + ((s8)*text - '0') * 100;
        text = *textRef;
        speed = self->unk68;
        *textRef = text + 1;
        self->unk68 = speed + ((s8)*text - '0') * 10;
        text = *textRef;
        speed = self->unk68;
        *textRef = text + 1;
        self->unk68 = speed + ((s8)*text - '0');
        if (self->unk68 == 9999) {
            self->unk68 = 0x10B;
        }
        return 1;

    case 'G':
        fn_80121D60(lbl_8032BDE8, (u8 *)TalkUi_str + 0x8E);
        return 1;

    default:
        break;
    }
invalid_command:
    return 3;
}
#pragma pop
typedef struct TalkUi {
    u8 pad0[0x48];
    void *slots[4];
    u8 pad58[4];
    u16 flags;
    s8 curSlot;
    u8 pad5F[6];
    u8 prevSlot;
} TalkUi;

static inline s8 TalkUi_FindSlot(TalkUi *self) {
    s32 want = self->curSlot;
    if (want < 0) return -1;
    if (self->slots[0] && M2C_FIELD(self->slots[0], s8 *, 0x43) == want) return 0;
    if (self->slots[1] && M2C_FIELD(self->slots[1], s8 *, 0x43) == want) return 1;
    if (self->slots[2] && M2C_FIELD(self->slots[2], s8 *, 0x43) == want) return 2;
    if (self->slots[3] && M2C_FIELD(self->slots[3], s8 *, 0x43) == want) return 3;
    return -1;
}

static inline void *TalkUi_GetCurrentSlot(TalkUi *self) {
    s8 slot = TalkUi_FindSlot(self);
    return slot < 0 ? NULL : self->slots[slot];
}

static inline void TalkUi_CopyToken(u8 *dst, u8 **text) {
    while ((s32)**text != '|') {
        *dst++ = *(*text)++;
    }
    *dst = 0;
    ++*text;
}

s32 fn_8011F184(TalkUi *self, u8 **text) {
    void fn_80120F94(void);
    s32 fn_80049DA4(void *, void *, s32);
    void fn_8011FB58(void *, s32);
    void fn_800790D4(void *, void *);
    void fn_8007AD6C(void *);
    void fn_8007AD08(void *, s32, s32);
    extern u8 lbl_8032FE24[];

    void *child;
    s8 slot;
    s32 c;
    s32 want;
    s8 previous;

    previous = self->curSlot;
    want = previous;
    if (want < 0) slot = -1;
    else if (self->slots[0] && M2C_FIELD(self->slots[0], s8 *, 0x43) == want) slot = 0;
    else if (self->slots[1] && M2C_FIELD(self->slots[1], s8 *, 0x43) == want) slot = 1;
    else if (self->slots[2] && M2C_FIELD(self->slots[2], s8 *, 0x43) == want) slot = 2;
    else if (self->slots[3] && M2C_FIELD(self->slots[3], s8 *, 0x43) == want) slot = 3;
    else slot = -1;
    child = slot < 0 ? NULL : self->slots[slot];

    c = (s8)**text;
    if (c >= '0' && c <= '9') {
        if (want != c - '0') {
            self->prevSlot = previous;
            self->curSlot = c - '0';
            fn_80120F94();
        }
        ++*text;
        return 1;
    }
    c = (s8)*(*text)++;
    switch (c) {
        case 'C':
            if (TalkUi_GetCurrentSlot(self)) {
                *text -= 2;
            } else {
                TalkUi_CopyToken(lbl_8032FE24, text);
                fn_8011FB58(self, fn_80049DA4((u8 *)TalkUi_str + 0x6f, lbl_8032FE24, 0));
                return 2;
            }
        case 'D':
            slot = TalkUi_FindSlot(self);
            if (!(gUiInputFlags & 3)) {
                fn_800790D4(self->slots[slot], self);
                fn_80120F94();
            } else {
                fn_8007AD6C(self->slots[slot]);
            }
            self->slots[slot] = 0;
            self->curSlot = -1;
            return 2;
        case 'S':
            if (child) M2C_FIELD(child, u16 *, 0x46) &= ~0x202;
            else self->flags &= ~0x202;
            return 1;
        case 'A':
            if (child) {
                M2C_FIELD(child, u16 *, 0x46) &= ~0x202;
                M2C_FIELD(child, u16 *, 0x46) |= 2;
            } else {
                self->flags &= ~0x202;
                self->flags |= 2;
            }
            return 1;
        case 'f':
            fn_8007AD08(TalkUi_GetCurrentSlot(self), 2, -1);
            return 1;
        case 's':
            fn_8007AD08(TalkUi_GetCurrentSlot(self), 1, -1);
            return 1;
        case 'd':
            fn_8007AD08(TalkUi_GetCurrentSlot(self), 1, 1);
            return 1;
        case 'c':
            if (child) {
                fn_8007AD08(TalkUi_GetCurrentSlot(self), -1, 3);
            } else {
                self->flags |= 4;
            }
            return 1;
        case 'h':
            if (child) {
                fn_8007AD08(TalkUi_GetCurrentSlot(self), -1, 4);
            } else {
                self->flags |= 8;
            }
            return 1;
        case 'o':
            if (child) {
                fn_8007AD08(TalkUi_GetCurrentSlot(self), 5, 5);
            } else {
                self->flags |= 12;
            }
            return 1;
    }
    return 2;
}

static inline void *TalkUi_ResolveNamedUnit(s32 arg) {
    s32 Str_Cmp(s32, void *);
    void *Unit_FindByName(void *);
    void *fn_8003A114(void *);
    void *fn_8003A064(void *);
    extern u16 TalkUi_str[];
    void *tmp;
    if (Str_Cmp(arg, (u8 *)TalkUi_str + 0x9F) == 0) {
        tmp = Unit_FindByName((u8 *)TalkUi_str + 0xA7);
        if (tmp) return fn_8003A114(tmp);
    }
    if (Str_Cmp(arg, (u8 *)TalkUi_str + 0xAF) == 0) {
        tmp = Unit_FindByName((u8 *)TalkUi_str + 0xA7);
        if (tmp) return fn_8003A064(tmp);
    }
    if (Str_Cmp(arg, (u8 *)TalkUi_str + 0xB9) == 0) {
        tmp = Unit_FindByName((u8 *)TalkUi_str + 0xC2);
        if (tmp) return fn_8003A114(tmp);
    }
    if (Str_Cmp(arg, (u8 *)TalkUi_str + 0xCB) == 0) {
        tmp = Unit_FindByName((u8 *)TalkUi_str + 0xC2);
        if (tmp) return fn_8003A064(tmp);
    }
    return (void *)arg;
}

void fn_8011FB58(void *arg0, s32 arg1) {
    s32 Str_Cmp(s32, void *);
    void *fn_8003A114(void *);
    void *fn_8003A064(void *);
    void *Unit_FindByName(void *);
    void **fn_8007C3BC(void *);
    void *fn_8007BC3C(void *, s32, s32, u16, void *);
    u8 fn_80109B24(void *);
    void fn_80079300(void *, u8);
    void fn_800791F0(void *, void *);
    void fn_80120F94(void);
    void strcpy(void *, void *);
    void strcat(void *, void *);
    s32 FileCache_Probe(void *);
    void *Process_CreateChild(void *, void *);
    void Str_CopyPad(void *, void *, s32);
    extern u16 TalkUi_str[];
    extern u8 gUiContext[24];
    extern s32 gUiInputFlags;
    extern u8 lbl_8028FED0[];
    void *unit;
    s32 i;
    u8 flag;
    void **infop;
    u8 *info;
    u8 v;
    u8 sp[0x40];
    u32 flags;
    void *tmp;
    void *self;
    s32 arg;

    self = arg0;
    arg = arg1;
    if (Str_Cmp(arg, (u8 *)TalkUi_str + 0x90) == 0) {
        unit = fn_8003A114(*(void **)gUiContext);
        goto got_unit;
    }
    if (Str_Cmp(arg, (u8 *)TalkUi_str + 0x97) == 0) {
        unit = fn_8003A064(*(void **)gUiContext);
        goto got_unit;
    }
    unit = TalkUi_ResolveNamedUnit(arg);
got_unit:
    flags = gUiInputFlags & 3;
    if (flags != 0) {
        for (i = 0; i < 4; i++) {
            if (*(void **)(((u8 *)self + i * 4) + 0x48) == NULL) {
                if (flags != 0) {
                    *(u16 *)((u8 *)self + 0x5C) = 0x180;
                }
                infop = fn_8007C3BC(unit);
                info = (u8 *)*infop;
                flag = 0;
                if ((s8)info[3] == (s8)info[5] && (s32)info[4] == 0x4C) {
                    flag = 1;
                }
                if (flag == 0) {
                    *(u16 *)((u8 *)self + 0x5C) |= 0x4000;
                }
                *(void **)(((u8 *)self + i * 4) + 0x48) = fn_8007BC3C(unit, 0, 0, *(u16 *)((u8 *)self + 0x5C), self);
                *(u16 *)((u8 *)self + 0x5C) = 0x82;
                if (*(void **)((u8 *)self + 0x58) != NULL && fn_80109B24(*(void **)((u8 *)self + 0x58)) != 0
                    && fn_80109B24(*(void **)((u8 *)self + 0x58)) != 0xFF) {
                    v = fn_80109B24(*(void **)((u8 *)self + 0x58));
                } else {
                    v = 0xFF;
                }
                *(u8 *)((u8 *)*(void **)(((u8 *)self + i * 4) + 0x48) + 0x41) = (u8)(v - 0x4D);
                fn_80079300(*(void **)(((u8 *)self + i * 4) + 0x48), *(u8 *)((u8 *)self + 0x5E));
                if ((gUiInputFlags & 3) == 0) {
                    fn_800791F0(*(void **)(((u8 *)self + i * 4) + 0x48), self);
                }
                {
                    u8 t = *(u8 *)((u8 *)self + 0x5E);
                    s8 s = (s8)t;
                    if (s != s) {
                        *(u8 *)((u8 *)self + 0x65) = t;
                        *(u8 *)((u8 *)self + 0x5E) = (u8)s;
                        fn_80120F94();
                    }
                }
                return;
            }
        }
    } else {
        strcpy(sp, (u8 *)TalkUi_str + 0x2F);
        strcat(sp, *(void **)((u8 *)fn_8007C3BC(unit) + 8));
        if (FileCache_Probe(sp) & 0x2000) {
            for (i = 0; i < 4; i++) {
                if (*(void **)(((u8 *)self + i * 4) + 0x48) == NULL) {
                    if (gUiInputFlags & 3) {
                        *(u16 *)((u8 *)self + 0x5C) = 0x180;
                    }
                    infop = fn_8007C3BC(unit);
                    info = (u8 *)*infop;
                    flag = 0;
                    if ((s8)info[3] == (s8)info[5] && (s32)info[4] == 0x4C) {
                        flag = 1;
                    }
                    if (flag == 0) {
                        *(u16 *)((u8 *)self + 0x5C) |= 0x4000;
                    }
                    *(void **)(((u8 *)self + i * 4) + 0x48) = fn_8007BC3C(unit, 0, 0, *(u16 *)((u8 *)self + 0x5C), self);
                    *(u16 *)((u8 *)self + 0x5C) = 0x82;
                    if (*(void **)((u8 *)self + 0x58) != NULL && fn_80109B24(*(void **)((u8 *)self + 0x58)) != 0
                        && fn_80109B24(*(void **)((u8 *)self + 0x58)) != 0xFF) {
                        v = fn_80109B24(*(void **)((u8 *)self + 0x58));
                    } else {
                        v = 0xFF;
                    }
                    *(u8 *)((u8 *)*(void **)(((u8 *)self + i * 4) + 0x48) + 0x41) = (u8)(v - 0x4D);
                    fn_80079300(*(void **)(((u8 *)self + i * 4) + 0x48), *(u8 *)((u8 *)self + 0x5E));
                    if ((gUiInputFlags & 3) == 0) {
                        fn_800791F0(*(void **)(((u8 *)self + i * 4) + 0x48), self);
                    }
                    {
                        u8 t = *(u8 *)((u8 *)self + 0x5E);
                        s8 s = (s8)t;
                        if (s != s) {
                            *(u8 *)((u8 *)self + 0x65) = t;
                            *(u8 *)((u8 *)self + 0x5E) = (u8)s;
                            fn_80120F94();
                        }
                    }
                    return;
                }
            }
        } else {
            Str_CopyPad((u8 *)Process_CreateChild(lbl_8028FED0, self) + 0x30, unit, 0x3A);
        }
    }
}

#pragma global_optimizer off
s32 TalkUi_LayoutSlot(void *talk, u32 slot) {
    s32 fn_801208BC(void *, u32);
    void fn_80108BD0(void *, s32, s32, s32);
    void fn_80122DD0(void *, s16, s16);
    void fn_80122E28(void *, s16, s16);
    void fn_801222A4(void *, void *);
    extern u16 TalkUi_str[];
    extern s16 lbl_80312060[];
    void *self;
    s32 width;
    u32 idx;
    s32 side;
    void *panel;
    s32 baseW;
    u8 *slotPtr;

    /* Position the talk window and portrait for speaker slot 0-3 from text width. */
    self = talk;
    slotPtr = (u8 *)self + ((slot << 2) & 0x3FC);
    *(void **)((u8 *)self + 0x44) = *(void **)(slotPtr + 0x34);
    idx = slot & 0xFF;
    panel = *(void **)((u8 *)self + 0x44);
    if ((u32)panel != 0 && *(u8 *)((u8 *)panel + 0x68) == 0) {
        baseW = fn_801208BC(*(void **)((u8 *)self + 0x30), idx) + 0xE0;
        switch (idx) {
        case 0:
            panel = *(void **)((u8 *)self + 0x34);
            width = baseW;
            if ((u32)panel != 0 && *(u8 *)((u8 *)panel + 0x6B) != 0) {
                if (baseW < 0x170) {
                    width = 0x170;
                }
                if (width > 0x230) {
                    width = 0x230;
                }
                fn_80108BD0((char *)TalkUi_str + 0xD6, 0x18, 0x14, width);
                panel = *(void **)((u8 *)self + 0x34);
                if ((u32)panel != 0) {
                    fn_80122DD0(panel, (s16)(width - 0x40), 0x7C);
                }
            }
            break;
        case 1:
            panel = *(void **)((u8 *)self + 0x38);
            width = baseW;
            if ((u32)panel != 0 && *(u8 *)((u8 *)panel + 0x6B) != 0) {
                if (baseW < 0x170) {
                    width = 0x170;
                }
                if (width > 0x230) {
                    width = 0x230;
                }
                fn_80108BD0((char *)TalkUi_str + 0xDF, 0x248 - width, 0x13C, width);
                fn_80122E28(*(void **)((u8 *)self + 0x38), (s16)(0x278 - width), 0x14C);
                panel = *(void **)((u8 *)self + 0x38);
                if ((u32)panel != 0) {
                    fn_80122DD0(panel, (s16)(0x288 - width), 0x1A4);
                }
            }
            break;
        case 2:
            panel = *(void **)((u8 *)self + 0x3C);
            side = baseW;
            if ((u32)panel != 0 && *(u8 *)((u8 *)panel + 0x6B) != 0) {
                width = 0x60;
                if (baseW < 0x170) {
                    side = 0x170;
                }
                if (side > 0x230) {
                    side = 0x230;
                }
                if (side + 0x60 > 0x230) {
                    width = 0x230 - side;
                }
                fn_80108BD0((char *)TalkUi_str + 0xE8, width + 0x18, 0xA0, side);
                fn_80122E28(*(void **)((u8 *)self + 0x3C), (s16)(width + 0xC0), 0xB0);
                lbl_80312060[6] = (s16)(width + 0x70);
                lbl_80312060[7] = 0x10F;
                lbl_80312060[8] = 1;
                panel = *(void **)((u8 *)self + 0x3C);
                if ((u32)panel != 0) {
                    s32 t = side - 0x40;
                    fn_80122DD0(panel, (s16)(width + t), 0x108);
                }
            }
            break;
        case 3:
            panel = *(void **)((u8 *)self + 0x40);
            width = baseW;
            if ((u32)panel != 0 && *(u8 *)((u8 *)panel + 0x6B) != 0) {
                side = 0x60;
                if (baseW < 0x170) {
                    width = 0x170;
                }
                if (width > 0x230) {
                    width = 0x230;
                }
                if (width + 0x60 > 0x230) {
                    side = 0x230 - width;
                }
                fn_80108BD0((char *)TalkUi_str + 0xF1, (0x248 - width) - side, 0xB4, width);
                fn_80122E28(*(void **)((u8 *)self + 0x40), (s16)((0x278 - width) - side), 0xC4);
                lbl_80312060[9] = (s16)(0x1F0 - side);
                lbl_80312060[10] = 0x123;
                lbl_80312060[11] = 0;
                panel = *(void **)((u8 *)self + 0x40);
                if ((u32)panel != 0) {
                    fn_80122DD0(panel, (s16)((0x288 - width) - side), 0x11C);
                }
            }
            break;
        }
        fn_801222A4(*(void **)((u8 *)self + 0x44), self);
        return 1;
    }
    return 0;
}
#pragma global_optimizer reset
void fn_80120354(void *);

void fn_80120304(void *arg0)
{
    void UiPanel_PollSkip(u16 *);
    u8 fn_8008A59C(void);
    void fn_80120354(void *);
    extern u16 gUiPanelFlags;

    UiPanel_PollSkip(&gUiPanelFlags);

    if (*((u8 *)arg0 + 0x63) == 0 || (u8)fn_8008A59C() == 0) {
        fn_80120354(arg0);
    }
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
void fn_80120354(void *arg0) {
    void Process_ClearFunc(void *);
    void *Process_CreateChild(void *, void *);
    void fn_8007ACE4(void *);
    void fn_8007AD30(void *, s32);
    s32 fn_8011E12C(void *);
    void Ui_PlaySeCue(void *, s32);
    u32 fn_80211690(void);
    extern u16 TalkUi_str[];
    extern u8 lbl_8028FE30[];
    extern s32 gUiInputFlags;
    extern void *gPadInput;
    extern u16 gUiPanelFlags;
    extern u32 lbl_80367A60;
    extern s8 lbl_80367A64;
    struct Item {
        u8 pad[0x43];
        s8 unk43;
    };
    struct Obj {
        u8 pad0[0x48];
        struct Item *items[4];
        u8 pad58[6];
        u8 unk5E;
        u8 unk5F;
        u8 unk60;
        u8 unk61;
        u8 pad62[4];
        u8 unk66;
        u8 unk67;
    };

    long i;
    s32 limit;
    struct Obj *self;
    u16 cleared;
    void *pad;
    u16 raw;
    int flags;
    s32 t;
    s32 pad4;
    s32 btn;
    register unsigned int trigger;
    s8 delay;
    s32 slot;
    register s32 want;
    void *tmp;
    struct Item *child;

    self = (struct Obj *)arg0;
    self->unk5F = self->unk5F - 1;
    flags = gUiInputFlags;
    if (flags & 0x2000) {
        t = 1;
    } else if ((u32)((((u8 *)gBattleState)[0x9c] >> 3) & 3) == 3) {
        t = 0xffff;
    } else {
        t = 1;
    }
    limit = t;
    if ((gUiPanelFlags & 4) && !(flags & 3)) {
        tmp = Process_CreateChild(lbl_8028FE30, self);
        *(void **)((u8 *)tmp + 0x30) = self;
        *(s32 *)((u8 *)tmp + 0x34) = 0;
        return;
    }
    raw = *(volatile u16 *)&gUiPanelFlags;
    pad = gPadInput;
    cleared = raw & 0xfffffbff;
    *(volatile u16 *)&gUiPanelFlags = cleared;
    pad4 = *(s32 *)((u8 *)pad + 4);
    btn = pad4 & (*(s32 *)((u8 *)pad + 8) ^ pad4);
    if (!(btn & 0x100)) {
        if (!(pad4 & 0x04000004) || !(pad4 & 0x100)) {
            if (*(volatile u16 *)&gUiPanelFlags & 8) {
                if (!(btn & 0x200)) {
                    trigger = 0;
                    goto after_trig;
                }
            } else if (flags & 3) {
                trigger = 1;
                goto after_trig;
            } else {
                trigger = 0;
                goto after_trig;
            }
        } else {
            *(volatile u16 *)&gUiPanelFlags = cleared | 0x400;
        }
    }
    trigger = 1;
    *(volatile u16 *)&gUiPanelFlags |= 0x200;
after_trig:
    if ((u8)trigger) {
        self->unk5F = 0;
        limit = 0xffff;
    }
    flags = gUiInputFlags;
    if (flags & 3) {
        Process_ClearFunc(self);
        return;
    }
    if ((s8)self->unk5F != 0) {
        return;
    }
    if (flags & 0x2000) {
        delay = 5;
    } else {
        switch ((s32)((((u8 *)gBattleState)[0x9c] >> 3) & 3)) {
        case 0:
            delay = 0xa;
            break;
        case 1:
            delay = 4;
            break;
        case 2:
            delay = 1;
            break;
        case 3:
            delay = 1;
            break;
        default:
            delay = -1;
            break;
        }
    }
    self->unk5F = delay;
    i = 0;
    self->unk67 = 0;
    while (limit > i) {
        if ((u8)fn_8011E12C(self) != 3) {
            break;
        }
        ++i;
    }
    if (self->unk60 != 0) {
        if (!lbl_80367A64) {
            lbl_80367A60 = -1;
            lbl_80367A64 = 1;
        }
        if (lbl_80367A60 != fn_80211690() - 1) {
            lbl_80367A60 = fn_80211690();
            if (!((((u8 *)gBattleState)[0x9f] >> 5) & 1)) {
                switch ((s32)self->unk66) {
                case 0:
                    break;
                case 1:
                    Ui_PlaySeCue((char *)TalkUi_str + 0xfa, 0x64);
                    break;
                case 2:
                    Ui_PlaySeCue((char *)TalkUi_str + 0x107, 0x64);
                    break;
                case 3:
                    Ui_PlaySeCue((char *)TalkUi_str + 0x114, 0x64);
                    break;
                case 4:
                    Ui_PlaySeCue((char *)TalkUi_str + 0x121, 0x64);
                    break;
                }
            }
        }
    }
    want = (s8)self->unk5E;
    if (0 > want) {
        slot = -1;
    } else {
        child = self->items[0];
        if (child != NULL && child->unk43 == want) {
            slot = 0;
        } else {
            child = self->items[1];
            if (child != NULL && child->unk43 == want) {
                slot = 1;
            } else {
                child = self->items[2];
                if (child != NULL && child->unk43 == want) {
                    slot = 2;
                } else {
                    child = self->items[3];
                    if (child != NULL && child->unk43 == want) {
                        slot = 3;
                    } else {
                        slot = -1;
                    }
                }
            }
        }
    }
    if ((s8)slot < 0) {
        child = 0;
    } else {
        child = self->items[(s8)slot];
    }
    if (child != NULL) {
        if (self->unk60 != self->unk61) {
            if (self->unk60 != 0) {
                fn_8007ACE4(child);
            } else {
                fn_8007AD30(child, 0x80);
            }
        }
    }
    self->unk61 = self->unk60;
}
#pragma pop
void fn_8012075C(void *arg0) {
    void fn_80122AA8(void *);
    extern s32 gUiInputFlags;
    s32 i;
    void *p;
    void *obj;

    if ((gUiInputFlags & 3) == 0) {
        i = 0;
        p = arg0;
        do {
            obj = *(void **)((u8 *)p + 0x34);
            if (obj != NULL) {
                fn_80122AA8(obj);
            }
            i += 1;
            p = (u8 *)p + 4;
        } while (i < 4);
    }
}

void fn_801207BC(void) {
    extern s32 gUiInputFlags;
    extern u16 gUiPanelFlags;
    gUiPanelFlags &= 0xFFFFFFFB;
    gUiInputFlags |= 2;
}

void fn_801207D8(void *arg0) {
    void fn_80089650(s32, s32);
    void Process_ClearFunc(void *);
    void fn_80079198(void *, void *);
    void fn_80122238(void *, void *);
    void fn_80120F94(void);
    void *fn_801090C0(void *);
    void fn_80109BB4(void *, u8);
    extern u32 lbl_80367A5C;
    void *self = arg0;
    void *p;
    void *obj;
    s32 i;
    void *t;
    s32 i2;

    obj = *(void **)((u8 *)self + 0x30);
    if (*(u8 *)((u8 *)obj + 0x63) != 0) {
        fn_80089650(3, 0x85);
        Process_ClearFunc(self);
        return;
    }
    for (i = 0, p = obj; i < 4; i += 1, p = (u8 *)p + 4) {
        t = *(void **)((u8 *)p + 0x48);
        if (t != NULL) {
            fn_80079198(t, self);
        }
    }
    for (i2 = 0, p = obj; i2 < 4; i2 += 1, p = (u8 *)p + 4) {
        t = *(void **)((u8 *)p + 0x34);
        if (t != NULL) {
            fn_80122238(t, self);
        }
    }
    fn_80120F94();
    if (lbl_80367A5C != 0) {
        fn_80109BB4(fn_801090C0((void *)lbl_80367A5C), 8);
    }
    Process_ClearFunc(self);
}

extern s32 fn_80010710(u8* arg0);
extern s32 gActiveCam;
#pragma scheduling on
/* TODO: verify command mappings after table index 23. read_data truncates
 * jumptable_80290110 relocations there; cases s/n/w remain provisional.
 * Instruction match alone does not validate those jump-table entries. */
static inline s8 Text_NextChar(s8 **text)
{
    return *(*text)++;
}

static inline void Text_CopyDelimited(s8 **text, u8 *out)
{
    while ((s32)(u8)**text != '|') {
        *out++ = *(*text)++;
    }
    *out = 0;
    ++*text;
}

#pragma scheduling on
#pragma peephole on
s32 fn_801208BC(s8 *text, s32 wanted)
{
  s32 fn_80010428(s8 **, s32, f32);
  s8 *fn_80104970(s8 *);
  extern f32 lbl_8036A248;
  s32 longest = -1;
  s32 width;
  s32 selected = wanted;
  s32 font = 2;
  for (;;)
  {
    width = 0;
    for (;;)
    {
      if (!((s8) (*text)))
      {
        goto done;
      }
      if (((s8) (*text)) == '\n')
      {
        ++text;
        break;
      }
      if (((s8) (*text)) == '#')
      {
        if (((s32) ((u8) text[1])) == 'F')
        {
          font = ((s8) text[3]) - '0';
        }
        text += fn_80010710((u8 *) text);
      }
      if (((s32) ((u8) (*text))) == '$')
      {
        ++text;
        switch ((s8) (*(text++)))
        {
          case 'N':
            if (((s32) ((u8) (*text))) == 'D')
          {
            ++text;
            continue;
          }

          case 's':
            switch ((s8) (*(text++)))
          {
            case '0':
              selected = 0;
              continue;

            case '1':
              selected = 1;
              continue;

            break;
            case '2':
              selected = 2;
              continue;

            case '3':
              selected = 3;
              continue;

            case '4':
              selected = 4;
              continue;

            case 'D':
              if (selected == wanted)
            {
              goto done;
            }
              continue;

            default:
              continue;

          }


          case 'n':
          {
            switch ((s8) (*(text++)))
            {
              case '0':
                selected = 0;
                break;

              case '1':
                selected = 1;
                break;

              case '2':
                selected = 2;
                break;

              case '3':
                selected = 3;
                break;

            }

            Text_CopyDelimited(&text, lbl_8032FE24);
            continue;
          }

          case 'w':
            switch ((s8) (*(text++)))
          {
            case '0':
              selected = 0;
              break;

            case '1':
              selected = 1;
              break;

            case '2':
              selected = 2;
              break;

            case '3':
              selected = 3;
              break;

          }

            if (selected == wanted)
          {
            goto done;
          }
            continue;

          case 'D':

          case 'M':

          case 'O':

          case 'S':
            ++text;
            continue;

          case '=':
            text += 4;
            continue;

          case 'F':
            switch ((s32) ((u8) (*(text++))))
          {
            case 'C':
            {
              Text_CopyDelimited(&text, lbl_8032FE24);
              continue;
            }
              break;

          }

            continue;

          case 'B':

          case 'R':
          {
            Text_CopyDelimited(&text, lbl_8032FE24);
            continue;
          }

          case 'P':
            goto done;

          default:
            continue;

        }

        break;
      }
      if (selected == wanted)
      {
        width += fn_80010428(&text, font, lbl_8036A248);
      }
      else
      {
        text = fn_80104970(text);
      }
    }

    if (longest < width)
    {
      longest = width;
    }
  }

  done:
  if (longest < width)
  {
    longest = width;
  }

  return longest;
}
#include "common.h"

extern u16 lbl_8028F6C8[];
extern u16 lbl_80296128[];
extern void *gUnitLists;
extern u16 gTargetList[];

s32 fn_80120C2C(void) {
    extern u16 gUiPanelFlags;
    extern void *gPadInput;
    extern s32 gUiInputFlags;
    u32 raw;
    u16 cleared;
    void *pad;
    s32 buttons;
    s32 pressed;

    raw = gUiPanelFlags;
    pad = gPadInput;
    raw &= ~0x400;
    cleared = (u16)raw;
    gUiPanelFlags = cleared;
    buttons = *(s32 *)((u8 *)pad + 4);
    pressed = buttons & (*(s32 *)((u8 *)pad + 8) ^ buttons);
    if (!(pressed & 0x100)) {
        if (!(buttons & 0x04000004) || !(buttons & 0x100)) {
            if (*(volatile u16 *)&gUiPanelFlags & 8) {
                if (!(pressed & 0x200)) {
                    return 0;
                }
            } else {
                return (gUiInputFlags & 3) != 0;
            }
        } else {
            gUiPanelFlags = (u16)(cleared | 0x400);
        }
    }
    gUiPanelFlags |= 0x200;
    return 1;
}

