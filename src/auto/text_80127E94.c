/* Functions from 0x80127E94 to 0x8012C368, found by decomp-toolkit. */
#include "common.h"
typedef struct AiItemEntry { char *name; u32 key; u8 (*fn)(void *, s32); } AiItemEntry;
static inline AiItemEntry *Ai_FindItemEntry(void *unit, u32 key) {
extern AiItemEntry lbl_802909F8[];
u8 fn_80093218(void *, u32);
AiItemEntry *walk;
if(fn_80093218(unit,key)) {
for(walk=lbl_802909F8;walk->key;walk++) {
if(key==walk->key && walk->fn) return walk;
}
}
return 0;
}

static inline u8 Ai_TryMoveAndAttack(void *arg0, s32 arg1) {
    u8 *fn_8001FC40(void *, s8, s8);
    u8 Status_Test(void *, s32);
    u8 fn_80100130(void *, s32, s16 *, s16 *);
    u8 fn_800BE968(s32, s8, s8);
    u8 fn_80100BA4(s16, s16, s8, s8);
    void Ai_SetUnitMoveTo(void *, s16, s16, s32, u16, s32, s32, s32);
    void *TargetList_GetAt(void *, s32);
    void fn_800FB96C(s32, u8, u8, s32, s32, s32, s8, s32, s32);
    extern u8 gBattleMap[], gAiState[], gUiContext[], gTargetList[];
    s16 x, y;
    u8 *path;
    s32 px, py;
    u8 found, out;
    u8 *target;
    s32 i;
    if (!(*(u32 *)((u8 *)arg0 + 0x254) & 0x20000000)) return 0;
    if (Status_Test((u8 *)arg0 + 0x1bc, 0x5b)) {
        if (!fn_80100130(arg0, 0x100, &x, &y)) return 0;
        path = fn_8001FC40(gBattleMap, (s8)x, (s8)y);
        px = *(s8 *)((u8 *)arg0 + 0x19e);
        py = *(s8 *)((u8 *)arg0 + 0x19f);
        for (; *path != 0x10; path++) {
            switch ((s32)*path) {
            case 1: px--; break;
            case 2: px++; break;
            case 8: py--; break;
            case 4: py++; break;
            }
            out = 0;
            if ((s16)px < (s8)gBattleMap[8] || (s8)gBattleMap[10] - 1 < (s16)px ||
                (s16)py < (s8)gBattleMap[9] || (s8)gBattleMap[11] - 1 < (s16)py) out = 1;
            if (!out && fn_800BE968(11, (s8)px, (s8)py)) {
                x = px; y = py; found = 1; goto checked;
            }
        }
        found = 0;
checked:
        if (found) {
            Ai_SetUnitMoveTo(arg0, x, y, 1, *(u16 *)(gAiState + 4), 0, 0, -1);
            if (gAiState[0x21c] && fn_80100BA4(x, y, (s8)gUiContext[13], (s8)gUiContext[14]))
                fn_800FB96C(11, gUiContext[13], gUiContext[14], *(s32 *)(gUiContext + 4), (s8)x, (s8)y, (s8)(arg1 < 0 ? arg1 : arg1 + 4), 0, 0);
            return gAiState[0x21c];
        }
    } else if (!fn_80100130(arg0, 0, &x, &y)) return 0;
    target = 0;
    for (i = 0; i < *(s32 *)gTargetList; i++) {
        target = TargetList_GetAt(gTargetList, 0);
        break;
    }
    if (!target) return 0;
    Ai_SetUnitMoveTo(arg0, x, y, 1, *(u16 *)(gAiState + 4), 0, 0, -1);
    if (gAiState[0x21c] && x == (s8)gUiContext[13] && y == (s8)gUiContext[14])
        fn_800FB96C(12, gUiContext[13], gUiContext[14], *(s32 *)(gUiContext + 4), target[0], target[1], (s8)(arg1 < 0 ? arg1 : arg1 + 4), 0, 0);
    return gAiState[0x21c];
}

static inline void Ai_TryFallbackMove(void *arg0) {
    u8 fn_801001B8(void *, s32, s16 *, s16 *);
    void Ai_SetUnitMoveTo(void *, s16, s16, s32, u16, s32, s32, s32);
    void *TargetList_GetAt(void *, s32);
    void fn_800FB96C(s32, u8, u8, void *, s32, s32, s32, s32, s32);
    extern u8 gAiState[], gUiContext[], gTargetList[];
    s16 x2, y2;
    if (!(*(u32 *)((u8 *)arg0 + 0x254) & 0x10000000)) return;
    if (fn_801001B8(arg0, 0, &x2, &y2)) {
        Ai_SetUnitMoveTo(arg0, x2, y2, 1, *(u16 *)(gAiState + 4), 0, 0, -1);
        if (gAiState[0x21C]) {
            if (x2 == (s8)gUiContext[13] && y2 == (s8)gUiContext[14]) {
                u8 tx = ((u8 *)TargetList_GetAt(gTargetList, 0))[0];
                u8 *p = TargetList_GetAt(gTargetList, 0);
                fn_800FB96C(11, gUiContext[13], gUiContext[14], *(void **)(gUiContext + 4),
                    (s8)tx, (s8)p[1], -1, 0, 0);
            }
        }
    }
}

extern u8 lbl_80290AA0[0x40];
extern u8 gMapObjEventList[0x200];
extern u8 gBattleState[0x578];

extern s32 lbl_80367A88;

extern const f32 lbl_8036A3C0;
extern const f32 lbl_8036A3C4;
extern f64 lbl_8036A3C8;
extern f64 lbl_8036A418;

#pragma cplusplus on
extern "C" void fn_80127E94(void *arg0) {
    struct Obj {
        u8 pad[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
    };
    ((Obj *)arg0)->v6();
}
#pragma cplusplus reset
s32 fn_80127EC0(void) {
    extern u16 gScriptCmdNames[];
    Ui_PlaySeCue((u16 *)((u8 *)gScriptCmdNames + 0x521), 0x64);
    return 9;
}

void fn_80127EF4(void) {
    extern u16 gScriptCmdNames[];
    Msg_Expand(&gScriptCmdNames[0x580 / sizeof(u16)]);
}

#pragma cplusplus on
extern "C" s32 fn_80127F20(void *arg0, void *arg1, void *arg2) {
    struct Obj {
        u8 pad[4];
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void v21();
        virtual void v22();
        virtual void v23();
        virtual void v24();
        virtual void v25();
        virtual void v26();
        virtual void v27();
        virtual u32 v28();
    };
    extern u8 lbl_80367A6C;
    s32 Ui_PlaySeCue(u32, s32);
    Obj *obj;

    (void)arg0;
    lbl_80367A6C = *(u8 *)((u8 *)arg2 + 0x3A);
    obj = *(Obj **)((u8 *)arg1 + 0x3C);
    if (obj->v28() != 0U) {
        obj = *(Obj **)((u8 *)arg1 + 0x3C);
        Ui_PlaySeCue(obj->v28(), 0x64);
    }
    return 5;
}
#pragma cplusplus reset

#pragma push
#pragma cplusplus on
extern "C" void fn_80127F8C(void *arg0, void *arg1, void *arg2) {
    void Prim2D_SetText(void *);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    s32 Text_MeasureHeight(s32, f32);
    s32 Text_MeasureWidth(void *, s32, f32);
    extern f32 lbl_8036A404;
    struct Model {
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
        virtual s32 width() = 0;
        virtual void v19() = 0;
        virtual s32 height() = 0;
    };
    struct Item {
        virtual void v0() = 0;
        virtual void *text() = 0;
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
        virtual void setup(void *) = 0;
    };
    f32 x;
    s32 height, width, y;
    Model *model;
    model = M2C_FIELD(arg1, Model **, 0x3c);
    height = (s16)model->height();
    height = (height - Text_MeasureHeight(-1, lbl_8036A404)) >> 1;
    y = (s16)(M2C_FIELD(arg2, s16 *, 0x32) + height);
    model = M2C_FIELD(arg1, Model **, 0x3c);
    width = (s16)model->width();
    x = (f32)((width - Text_MeasureWidth(((Item *)arg0)->text(), -1, lbl_8036A404)) / 2);
    ((Item *)arg0)->setup(arg1);
    Prim2D_AddPrim(6);
    Prim2D_SetPos(x, (f32)y);
    Prim2D_SetColor(0, 0, 0, 255);
    Prim2D_SetText(((Item *)arg0)->text());
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A404);
    Prim2D_PrepareTex();
}
#pragma cplusplus off
#pragma pop
void fn_80128108(void) {
    extern u16 gScriptCmdNames[];
    Msg_Expand((u8 *)gScriptCmdNames + 0x5C4);
}

void fn_80128134(void) {
    extern u16 gScriptCmdNames[];
    Msg_Expand((u8 *)gScriptCmdNames + 0x5CD);
}

void fn_80128160(s32 arg0, s32 arg1, s32 arg2) {
    void *Process_Create(void *, u32);
    u32 Sound_FindByName(s32);
    extern u8 lbl_802905C0[];
    u32 temp_r3;
    void *temp_r3_2;
    temp_r3 = Sound_FindByName(arg0);
    if (temp_r3 != 0U) {
        temp_r3_2 = Process_Create(lbl_802905C0, temp_r3);
        M2C_FIELD(temp_r3_2, s32 *, 0x38) = arg1;
        M2C_FIELD(temp_r3_2, f32 *, 0x3C) = (f32)arg2;
        M2C_FIELD(temp_r3_2, f32 *, 0x40) = lbl_8036A3C0;
        M2C_FIELD(temp_r3_2, f32 *, 0x44) = lbl_8036A3C4;
    }
}

void fn_801281E4(s32 arg0, s32 arg1, s32 arg2) {
    void *Process_Create(void *, u32);
    u32 Sound_FindByName(s32);
    extern u8 lbl_802905C0[];
    extern const f32 lbl_8036A3D0, lbl_8036A3D4;
    u32 temp_r3;
    void *temp_r3_2;
    temp_r3 = Sound_FindByName(arg0);
    if (temp_r3 != 0U) {
        temp_r3_2 = Process_Create(lbl_802905C0, temp_r3);
        M2C_FIELD(temp_r3_2, s32 *, 0x38) = arg1;
        M2C_FIELD(temp_r3_2, f32 *, 0x3C) = (f32)arg2;
        M2C_FIELD(temp_r3_2, f32 *, 0x40) = lbl_8036A3D0;
        M2C_FIELD(temp_r3_2, f32 *, 0x44) = lbl_8036A3D4;
    }
}

void fn_80128268(s32 arg0,s32 arg1,s32 arg2) {
void *Process_Create(void *,u32);
u32 Sound_FindByName(s32);
extern u8 lbl_802905C0[];
u32 id;
void *obj;
id=Sound_FindByName(arg0);
if(id!=0){
obj=Process_Create(lbl_802905C0,id);
M2C_FIELD(obj,s32 *,0x38)=arg1;
M2C_FIELD(obj,f32 *,0x3C)=(f32)arg2;
M2C_FIELD(obj,f32 *,0x40)=3.0f;
M2C_FIELD(obj,f32 *,0x44)=3.0f;
}
}

void fn_801282E8(s32 arg0, s32 arg1, s32 arg2) {
    void *Process_Create(void *, u32);
    u32 Sound_FindByName(s32);
    extern u8 lbl_80290598[];
    u32 temp_r3;
    void *temp_r3_2;

    temp_r3 = Sound_FindByName(arg0);
    if (temp_r3 != 0U) {
        temp_r3_2 = Process_Create(lbl_80290598, temp_r3);
        M2C_FIELD(temp_r3_2, s32 *, 0x38) = arg1;
        M2C_FIELD(temp_r3_2, f32 *, 0x3C) = (f32)arg2;
    }
}

void fn_8012835C(s32 arg0, s32 arg1, s32 arg2) {
    void *Process_Create(void *, u32);
    u32 Sound_FindByName(s32);
    extern u8 lbl_80290598[];
    u32 temp_r3;
    void *temp_r3_2;

    temp_r3 = Sound_FindByName(arg0);
    if (temp_r3 != 0U) {
        temp_r3_2 = Process_Create(lbl_80290598, temp_r3);
        M2C_FIELD(temp_r3_2, s32 *, 0x38) = arg1;
        M2C_FIELD(temp_r3_2, f32 *, 0x3C) = (f32)-arg2;
    }
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
void fn_801283D4(void *arg0) {
    u32 OSGetTick(void);
    f64 sin(f64);
    extern f32 lbl_80367068[];
    extern f32 lbl_8036A3D4, lbl_8036A3F0, lbl_8036A3F4;
    extern f64 lbl_8036A3D8, lbl_8036A3E0, lbl_8036A3E8;
    u8 *self = arg0;
    u8 *dest;
    f32 dy, dx, length, x, y, wave, amplitude;
    f32 outx, outy;
    f64 estimate;
    union { f32 f; u32 u; } bits;
    s32 kind;
    u32 ticks, period;
    dx = *(f32 *)(self + 0x40);
    dy = *(f32 *)(self + 0x44);
    dest = *(u8 **)(self + 0x18);
    length = (f32)(dx * dx) + (f32)(dy * dy);
    if (length > lbl_8036A3D4) {
        estimate = __frsqrte(length);
        estimate = lbl_8036A3D8 * estimate * (lbl_8036A3E0 - length * (estimate * estimate));
        estimate = lbl_8036A3D8 * estimate * (lbl_8036A3E0 - length * (estimate * estimate));
        estimate = lbl_8036A3D8 * estimate * (lbl_8036A3E0 - length * (estimate * estimate));
        length = (f32)(length * estimate);
    } else if (length < lbl_8036A3E8) {
        length = lbl_80367068[0];
    } else {
        bits.f = length;
        switch (bits.u & 0x7F800000) {
        case 0x7F800000: if (bits.u & 0x7FFFFF) kind = 1; else kind = 2; break;
        case 0: if (bits.u & 0x7FFFFF) kind = 5; else kind = 3; break;
        default: kind = 4; break;
        }
        if (kind == 1) length = lbl_80367068[0];
    }
    x = *(f32 *)(self + 0x40) / length;
    y = *(f32 *)(self + 0x44) / length;
    ticks = OSGetTick();
    period = *(s32 *)(self + 0x38);
    wave = (f32)sin(((f32)((ticks / ((*(u32 *)0x800000F8 >> 2) / 1000)) % period) / (f32)(s32)period) * lbl_8036A3F0);
    amplitude = *(f32 *)(self + 0x3C);
    wave = amplitude * wave - lbl_8036A3F4 * amplitude;
    outx = wave * x + *(f32 *)(self + 0x30);
    outy = wave * y + *(f32 *)(self + 0x34);
    *(f32 *)(dest + 0x40) = outx;
    *(f32 *)(dest + 0x44) = outy;
}
#pragma pop
void fn_801285C4(void *arg0) {
    f32 fn_801099A0(s32, M2C_UNK);
    s32 temp_r31;

    temp_r31 = M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(arg0, f32 *, 0x30) = fn_801099A0(temp_r31, 0);
    M2C_FIELD(arg0, f32 *, 0x34) = fn_801099A0(temp_r31, 1);
}

void fn_80128618(void *arg0) {
    void *p;
    f32 a;
    f32 b;

    p = *(void **)((u8 *)arg0 + 0x18);
    a = *(f32 *)((u8 *)arg0 + 0x34);
    b = *(f32 *)((u8 *)arg0 + 0x30);
    *(f32 *)((u8 *)p + 0x40) = b;
    *(f32 *)((u8 *)p + 0x44) = a;
}

#pragma opt_lifetimes off
void fn_80128630(void *arg0) {
    f64 fn_80238638(f32);
    u32 OSGetTick(void);
    extern f32 lbl_8036A3F0;
    void *obj;
    u32 ms;
    u32 rem;
    s32 period;
    f32 x;
    register f32 scale;
    f32 y;
    register f32 wave;

    obj = *(void **)((u8 *)arg0 + 0x18);
    ms = OSGetTick() / ((*(u32 *)0x800000F8 >> 2) / 1000);
    period = *(s32 *)((u8 *)arg0 + 0x38);
    rem = ms % period;
    wave = (f32)fn_80238638(((f32)rem / (f32)period) * lbl_8036A3F0);
    scale = *(f32 *)((u8 *)arg0 + 0x3C);
    y = *(f32 *)((u8 *)arg0 + 0x34);
    x = *(f32 *)((u8 *)arg0 + 0x30);
    scale *= wave;
    *(f32 *)((u8 *)obj + 0x40) = x;
    *(f32 *)((u8 *)obj + 0x44) = y + scale;
}
#pragma opt_lifetimes reset
void fn_801286F8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, u8 *, 9) = (u8) (M2C_FIELD(arg0, u8 *, 9) & ~arg1);
}

void fn_80128708(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 8) = arg1;
}

s32 fn_80128710(void) {
    return 0;
}

u8 fn_80128718(void *arg0, s32 arg1) {
    void fn_800FB96C(s32, s8, s8, void *, s8, s8, s8, s32, s32);
    u8 fn_801025BC(void *, s16 *, s16 *);
    extern u8 gAiState[];
    struct { u8 hi:3; u8 lo:5; } *bf;
    s16 sp12;
    s16 sp10;

    bf = (void *)((char *)arg0 + 0x1A4);
    if (!bf->hi) {
        return 0U;
    }
    if (fn_801025BC(arg0, &sp12, &sp10) != 0) {
        fn_800FB96C(4, (s8)sp12, (s8)sp10, arg0, (s8)sp12, (s8)sp10, (s8)(arg1 + 4), 0, 0);
    }
    return gAiState[0x21C];
}

s32 fn_801287B8(void) {
    return 0;
}

#pragma push
#pragma use_lmw_stmw on
#pragma opt_propagation off
#pragma opt_lifetimes off
u8 fn_801287C0(void *arg0)
{
    u8 Status_Test(void *, s32);
    extern u8 gAiState[];

    u8 *self;
    u32 oldFlags;

    self = (u8 *)arg0;

    if (!Status_Test(self + 0x1BC, 0x5B)) {
        return 0;
    }

    oldFlags = *(u32 *)(self + 0x254);
    *(u32 *)(self + 0x254) |= 0x30000000;

    if (!Ai_TryMoveAndAttack(self, -1)) {
        Ai_TryFallbackMove(self);
    }

    *(u32 *)(self + 0x254) = oldFlags;
    return gAiState[0x21C];
}
#pragma pop
u8 fn_80128C3C(void *arg0, s32 arg1) {
    u8 fn_801001B8(void *, s32, s16 *, s16 *);
    void Ai_SetUnitMoveTo(void *,s16,s16,s32,u16,s32,s32,s32);
    void *TargetList_GetAt(void *,s32);
    void fn_800FB96C(s32,u8,u8,s32,s8,s8,s8,s32,s32);
    extern u8 gAiState[], gUiContext[], gTargetList[];
    s16 x,y;
    s32 tx;
    s32 ty;
    s32 slot;
    if (!(*(u32 *)((u8 *)arg0+0x254)&0x10000000)) return 0;
    if (!fn_801001B8(arg0,0,&x,&y)) return 0;
    Ai_SetUnitMoveTo(arg0,x,y,1,*(u16 *)(gAiState+4),0,0,-1);
    if(gAiState[0x21c] && x==(s8)gUiContext[13] && y==(s8)gUiContext[14]) {
        tx=*(s8 *)TargetList_GetAt(gTargetList,0);
        ty=((s8 *)TargetList_GetAt(gTargetList,0))[1];
        
        fn_800FB96C(11,gUiContext[13],gUiContext[14],*(s32 *)(gUiContext+4),tx,(s8)ty,(s8)(arg1<0?arg1:arg1+4),0,0);
    }
    return gAiState[0x21c];
}

#pragma use_lmw_stmw on
u8 fn_80128D98(void *arg0, s32 arg1) {
    u8 *fn_8001FC40(void *,s8,s8);
    u8 Status_Test(void *,s32);
    u8 fn_80100130(void *,s32,s16 *,s16 *);
    u8 fn_800BE968(s32,s8,s8);
    u8 fn_80100BA4(s16,s16,s8,s8);
    void Ai_SetUnitMoveTo(void *,s16,s16,s32,u16,s32,s32,s32);
    void *TargetList_GetAt(void *,s32);
    void fn_800FB96C(s32,u8,u8,s32,s32,s32,s8,s32,s32);
    extern u8 gBattleMap[],gAiState[],gUiContext[],gTargetList[];
    s16 x,y;
    s32 py,px;
    u8 *path;
    u8 found,out;
    u8 *target;
    s16 i;
    if (!(M2C_FIELD(arg0,u32 *,0x254)&0x20000000)) return 0;
    if (Status_Test((u8 *)arg0+0x1bc,0x5b)) {
        if (!fn_80100130(arg0,0x100,&x,&y)) return 0;
        path=fn_8001FC40(gBattleMap,(s8)x,(s8)y);
        px=M2C_FIELD(arg0,s8 *,0x19e);
        py=M2C_FIELD(arg0,s8 *,0x19f);
        for (;*path!=0x10;path++) {
            switch ((s32)*path) {
            case 1: px--; break;
            case 2: px++; break;
            case 8: py--; break;
            case 4: py++; break;
            }
            out=0;
            if ((s16)px<(s8)gBattleMap[8] || (s8)gBattleMap[10]-1<(s16)px || (s16)py<(s8)gBattleMap[9] || (s8)gBattleMap[11]-1<(s16)py) out=1;
            if (!out && fn_800BE968(11,(s8)px,(s8)py)) {
                x=px; found=1; y=py; goto checked;
            }
        }
        found=0;
checked:
        if (found) {
            Ai_SetUnitMoveTo(arg0,x,y,1,*(u16 *)(gAiState+4),0,0,-1);
            if (gAiState[0x21c] && fn_80100BA4(x,y,(s8)gUiContext[13],(s8)gUiContext[14]))
                fn_800FB96C(11,gUiContext[13],gUiContext[14],*(s32 *)(gUiContext+4),(s8)x,(s8)y,(s8)(arg1<0?arg1:arg1+4),0,0);
            return gAiState[0x21c];
        }
    } else if (!fn_80100130(arg0,0,&x,&y)) return 0;
    target=0;
    for(i=0;i<*(s32 *)gTargetList;i++) {
        target=TargetList_GetAt(gTargetList,0);
        break;
    }
    if (!target) return 0;
    Ai_SetUnitMoveTo(arg0,x,y,1,*(u16 *)(gAiState+4),0,0,-1);
    if(gAiState[0x21c] && x==(s8)gUiContext[13] && y==(s8)gUiContext[14])
        fn_800FB96C(12,gUiContext[13],gUiContext[14],*(s32 *)(gUiContext+4),target[0],target[1],(s8)(arg1<0?arg1:arg1+4),0,0);
    return gAiState[0x21c];
}
#pragma cplusplus off
u8 fn_80129104(void *arg0) {
extern u8 gAiState[];
typedef AiItemEntry Tbl;
extern Tbl lbl_802909F8[];
u8 fn_801001F0(u32);
s32 Unit_FindKeyItemSlot(void *,u8);
u8 fn_80093218(void *,u32);
u8 fn_801287C0(void *);
Tbl *entry;
u32 key;
u8 kind;
u8 *p;
s32 i;
if ((gAiState[1]&2) || (M2C_FIELD(arg0,u32 *,0x254)&0x03000000)) return 0;
if(fn_801287C0(arg0)==0) {
for(i=0,p=arg0;i<4;i++,p+=8) {
if(M2C_FIELD(p,u32 *,0x1EC)==0) break;
kind=fn_801001F0(M2C_FIELD(p,u32 *,0x1EC));
if(kind!=0 && i==Unit_FindKeyItemSlot(arg0,kind)) {
key=M2C_FIELD(p,u32 *,0x1EC);
entry=Ai_FindItemEntry(arg0,key);
if(entry && entry->fn(arg0,i)) break;
}
}
}
return gAiState[0x21C];
}
u8 fn_8012923C(void *arg0) {
extern u8 gAiState[];
typedef AiItemEntry Tbl;
extern Tbl lbl_802909F8[];
u8 fn_801001F0(u32);
s32 Unit_FindKeyItemSlot(void *,u8);
u8 fn_80093218(void *,u32);
u8 fn_801287C0(void *);
Tbl *entry;
u32 key;
u8 kind;
u8 *p;
s32 i;
if ((gAiState[1]&2) || (M2C_FIELD(arg0,u32 *,0x254)&0x03000000)) return 0;
if(fn_801287C0(arg0)==0) {
for(i=0,p=arg0;i<4;i++,p+=8) {
if(M2C_FIELD(p,u32 *,0x1EC)==0) break;
kind=fn_801001F0(M2C_FIELD(p,u32 *,0x1EC));
if(kind==0 || i==Unit_FindKeyItemSlot(arg0,kind)) {
key=M2C_FIELD(p,u32 *,0x1EC);
entry=Ai_FindItemEntry(arg0,key);
if(entry && entry->fn(arg0,i)) break;
}
}
}
return gAiState[0x21C];
}

void fn_80129374(void) {
    u32 Item_GetByIid(u32);
    extern u32 lbl_802909F8[48];
    u32 *p;

    for (p = lbl_802909F8; p[0] != 0; p += 3) {
        p[1] = Item_GetByIid(p[0]);
    }
}

void fn_801293C0(void) {
    void Process_UnlinkByKey(void *);
    extern u8 lbl_80290A40[];
    s32 base;

    base = (s32)lbl_80290A40;
    Process_UnlinkByKey((void *)(base + 0x1BC));
    Process_UnlinkByKey((void *)(base + 0x190));
    Process_UnlinkByKey((void *)(base + 0x164));
    Process_UnlinkByKey((void *)(base + 0x130));
    Process_UnlinkByKey((void *)(base + 0xFC));
    Process_UnlinkByKey((void *)(base + 0xA0));
    Process_UnlinkByKey((void *)(base + 0x18));
    Process_UnlinkByKey((void *)(base + 0x60));
}

void fn_8012942C(s32 arg0, s32 arg1) {
    extern u8 lbl_80290BFC[];
    void *Process_CreateChild(u8 *, s32);
    s32 *obj;
    obj = (s32 *)Process_CreateChild(lbl_80290BFC, arg1);
    obj[0x30 / 4] = arg0;
}

void fn_80129464(void *arg0) {
    f32 Map_SampleHeight(void *, f32, f32);
    void fn_800498A4(void *, void *, s32);
    void Effect_SetPos(s32, f32, f32, f32);
    s32 Effect_Create(void *, void *);
    extern u8 lbl_80275740[];
    extern u8 gBattleMap[];
    extern f32 gTileCenter;

    f32 f31;
    f32 f30;
    s32 b0;
    s32 t;
    s32 b1;
    void *ptr;
    void *self;

    self = arg0;
    ptr = *(void **)((u8 *)self + 0x30);
    b0 = *(s8 *)ptr;
    b1 = *((s8 *)ptr + 1);
    fn_800498A4(ptr, self, 0);
    t = b1;
    b1 = Effect_Create(lbl_80275740 + 0x15B, self);
    f31 = gTileCenter + (f32)t;
    f30 = gTileCenter + (f32)b0;
    Effect_SetPos(b1, f30, f31, Map_SampleHeight(gBattleMap, f30, f31));
}

void fn_8012955C(void) {
    extern u16 lbl_80275740[];
    GActor_RequestRes((u8 *)lbl_80275740 + 0x15B);
}

void fn_80129588(s32 arg0, u32 arg1) {
    void *Process_CreateChild(void *);
    void *Process_Create(void *, s32);
    extern u8 lbl_80290BA4[];
    void *var_r3;

    if (arg1 != 0U) {
        var_r3 = Process_CreateChild(lbl_80290BA4);
    } else {
        var_r3 = Process_Create(lbl_80290BA4, 3);
    }
    *(s32 *)((char *)var_r3 + 0x30) = arg0;
}

void fn_801295DC(void *arg0) {
    u8 fn_80040824();
    M2C_UNK MapObj_FadeIn(s32, M2C_UNK);
    if (fn_80040824() != 0) {
        MapObj_FadeIn(M2C_FIELD(arg0, s32 *, 0x30), 1);
    }
}

void MapObj_StartLinkedFadeIn(void *arg0) {
    /* Clear the map-object flag, refresh the map, and fade in any hidden linked object at its tile. */
    void *Map_Get(void);
    void fn_80044450(void *, s32);
    void fn_80016180(void);
    void fn_800498A4(void *, void *, s32);
    void *Map_FindObjNear(void *, s32, s32, u32, s32);
    u8 MapObj_IsHidden(void *);
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, s32);
    s32 Map_CollectLinkedObjs(void *, void *, void *);
    extern u8 E_MapObjFadeIn_script[];
    void *self = arg0;
    void *temp;
    s32 y;
    void *cam;
    void *entry;

    temp = *(void **)((u8 *)arg0 + 0x30);
    ((u8 *)temp)[2] &= ~2;
    fn_80044450(Map_Get(), 1);
    fn_80016180();
    fn_800498A4(*(void **)((u8 *)self + 0x30), self, 1);

    temp = *(void **)((u8 *)self + 0x30);
    y = *(s8 *)((u8 *)temp + 1);
    cam = Map_Get();
    if ((temp = Map_FindObjNear(cam, *(s8 *)((u8 *)temp + 0), y, 0x800, 0)) != NULL && MapObj_IsHidden(temp)) {
        if (self != NULL) {
            entry = Process_CreateChild(E_MapObjFadeIn_script, self);
        } else {
            entry = Process_Create(E_MapObjFadeIn_script, 3);
        }
        *(s32 *)((u8 *)entry + 0x50) = Map_CollectLinkedObjs(Map_Get(), temp, (u8 *)entry + 0x30);
    }
}

void fn_80129708(s32 arg0, u32 arg1) {
    void *Process_CreateChild(void *);
    void *Process_Create(void *, s32);
    extern u8 lbl_80290BA4[];
    void *var_r3;

    if (arg1 != 0U) {
        var_r3 = Process_CreateChild(lbl_80290BA4);
    } else {
        var_r3 = Process_Create(lbl_80290BA4, 3);
    }
    *(s32 *)((char *)var_r3 + 0x30) = arg0;
}

void fn_8012975C(void *arg0) {
    u8 fn_80040824();
    M2C_UNK MapObj_FadeOut(s32, M2C_UNK);
    if (fn_80040824() != 0) {
        MapObj_FadeOut(M2C_FIELD(arg0, s32 *, 0x30), 1);
    }
}

void MapObj_StartLinkedFadeOut(void *arg0) {
    /* Flag the map object, refresh the map, and fade out any visible linked object at its tile. */
    void *Map_Get(void);
    void fn_80044450(void *, s32);
    void fn_80016180(void);
    void fn_800498A4(void *, void *, s32);
    void *Map_FindObjNear(void *, s32, s32, u32, s32);
    u8 MapObj_IsVisible(void *);
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, s32);
    s32 Map_CollectLinkedObjs(void *, void *, void *);
    extern u8 E_MapObjFadeOut_script[];
    void *self = arg0;
    void *temp;
    s32 y;
    void *cam;
    void *entry;

    temp = *(void **)((u8 *)arg0 + 0x30);
    ((u8 *)temp)[2] |= 2;
    fn_80044450(Map_Get(), 1);
    fn_80016180();
    fn_800498A4(*(void **)((u8 *)self + 0x30), self, 0);

    temp = *(void **)((u8 *)self + 0x30);
    y = *(s8 *)((u8 *)temp + 1);
    cam = Map_Get();
    if ((temp = Map_FindObjNear(cam, *(s8 *)((u8 *)temp + 0), y, 0x800, 0x10)) != NULL && MapObj_IsVisible(temp)) {
        if (self != NULL) {
            entry = Process_CreateChild(E_MapObjFadeOut_script, self);
        } else {
            entry = Process_Create(E_MapObjFadeOut_script, 3);
        }
        *(s32 *)((u8 *)entry + 0x50) = Map_CollectLinkedObjs(Map_Get(), temp, (u8 *)entry + 0x30);
    }
}

void fn_80129888(void *arg0, void *arg1)
{
    extern u8 E_MapObjFadeIn_script[];

    extern void *Process_CreateChild(void *, void *);
    extern void *Process_Create(void *, s32);
    extern void *Map_Get(void);
    extern s32 Map_CollectLinkedObjs(void *, void *, void *);

    u8 *entry;
    void *result;

    if (arg1 != 0) {
        entry = (u8 *)Process_CreateChild(E_MapObjFadeIn_script, arg1);
    } else {
        entry = (u8 *)Process_Create(E_MapObjFadeIn_script, 3);
    }

    result = Map_Get();

    *(s32 *)(entry + 0x50) =
        Map_CollectLinkedObjs(result, arg0, entry + 0x30);
}

void fn_801298FC(void *arg0) {
    u8 fn_80040824(void);
    void MapObj_Show(void *, u8);

    void *p;
    s32 i;
    s32 n;
    void *v;

    if ((u8)fn_80040824() != 0) {
        p = arg0;
        i = 0;
        while (i < *(s32 *)((u8 *)arg0 + 0x50)) {
            n = *(s32 *)((u8 *)arg0 + 0x50);
            v = *(void **)((u8 *)p + 0x30);
            if (i == n - 1) {
                MapObj_Show(v, 1);
            } else {
                MapObj_Show(v, 0);
            }
            p = (u8 *)p + 4;
            i += 1;
        }
    }
}

#pragma use_lmw_stmw on
/* Fade each listed model from transparent to opaque over 60 frames, then clear the process. */
void ModelList_FadeInProcess(void *proc) {
    f32 Math_Lerp(f32, f32, f32, f32);
    void Model_SetAlpha(void *, s32);
    void Process_ClearFunc(void *);
    extern f64 lbl_8036A418;
    extern f32 gZeroF;
    extern f32 gAlphaOpaque;
    extern f32 gModelListFadeDuration;
    u8 *walk;
    s32 i;
    u8 *model;

    M2C_FIELD(proc, s32 *, 0x54) = M2C_FIELD(proc, s32 *, 0x54) + 1;
    walk = (u8 *)proc;
    i = 0;
    while (i < M2C_FIELD(proc, s32 *, 0x50)) {
        model = *(u8 **)(walk + 0x30) + 0x14;
        Model_SetAlpha(model, (s32)Math_Lerp(gZeroF, gAlphaOpaque, gModelListFadeDuration, (f32)M2C_FIELD(proc, s32 *, 0x54)));
        walk += 4;
        i += 1;
    }
    if (M2C_FIELD(proc, s32 *, 0x54) == 0x3C) {
        Process_ClearFunc(proc);
    }
}
#pragma use_lmw_stmw off
void fn_80129A48(void *arg0) {
    void *entry;
    char *walk;
    s32 i;

    *(s32 *)((char *)arg0 + 0x54) = 0;
    walk = arg0;
    for (i = 0; i < *(s32 *)((char *)arg0 + 0x50);) {
        entry = *(void **)(walk + 0x30);
        walk += 4;
        i += 1;
        *(u8 *)((char *)entry + 2) &= 0xFC;
    }
}

void fn_80129A84(void *arg0, void *arg1)
{
    extern u8 E_MapObjFadeOut_script[];

    extern void *Process_CreateChild(void *, void *);
    extern void *Process_Create(void *, s32);
    extern void *Map_Get(void);
    extern s32 Map_CollectLinkedObjs(void *, void *, void *);

    u8 *entry;
    void *result;

    if (arg1 != 0) {
        entry = (u8 *)Process_CreateChild(E_MapObjFadeOut_script, arg1);
    } else {
        entry = (u8 *)Process_Create(E_MapObjFadeOut_script, 3);
    }

    result = Map_Get();

    *(s32 *)(entry + 0x50) =
        Map_CollectLinkedObjs(result, arg0, entry + 0x30);
}

void fn_80129AF8(void *arg0) {
    u8 fn_80040824(void);
    void MapObj_Hide(void *, u8);

    void *p;
    s32 i;
    s32 n;
    void *v;

    if ((u8)fn_80040824() != 0) {
        p = arg0;
        i = 0;
        while (i < *(s32 *)((u8 *)arg0 + 0x50)) {
            n = *(s32 *)((u8 *)arg0 + 0x50);
            v = *(void **)((u8 *)p + 0x30);
            if (i == n - 1) {
                MapObj_Hide(v, 1);
            } else {
                MapObj_Hide(v, 0);
            }
            p = (u8 *)p + 4;
            i += 1;
        }
    }
}

#pragma use_lmw_stmw on
/* Fade each listed model from opaque to transparent over 60 frames, then clear the process. */
void ModelList_FadeOutProcess(void *proc) {
    f32 Math_Lerp(f32, f32, f32, f32);
    void Model_SetAlpha(void *, s32);
    void Process_ClearFunc(void *);
    extern f64 lbl_8036A418;
    extern f32 gAlphaOpaque;
    extern f32 lbl_8036A420;
    extern f32 gModelListFadeDuration;
    u8 *walk;
    s32 i;
    u8 *model;

    M2C_FIELD(proc, s32 *, 0x54) = M2C_FIELD(proc, s32 *, 0x54) + 1;
    walk = (u8 *)proc;
    i = 0;
    while (i < M2C_FIELD(proc, s32 *, 0x50)) {
        model = *(u8 **)(walk + 0x30) + 0x14;
        Model_SetAlpha(model, (s32)Math_Lerp(gAlphaOpaque, lbl_8036A420, gModelListFadeDuration, (f32)M2C_FIELD(proc, s32 *, 0x54)));
        walk += 4;
        i += 1;
    }
    if (M2C_FIELD(proc, s32 *, 0x54) == 0x3C) {
        Process_ClearFunc(proc);
    }
}
#pragma use_lmw_stmw off
void fn_80129C44(void *arg0) {
    void *Map_Get(void);
    void fn_80044450(void *, s32);
    void fn_80016180(void);
    void *entry;
    u8 *p;
    s32 i;

    p = (u8 *)arg0;
    i = 0;
    *(s32 *)((u8 *)arg0 + 0x54) = 0;
    goto check;
loop:
    entry = *(void **)(p + 0x30);
    p += 4;
    i += 1;
    *(u8 *)((u8 *)entry + 2) |= 2;
check:
    if (i < *(s32 *)((u8 *)arg0 + 0x50)) {
        goto loop;
    }
    fn_80044450(Map_Get(), 1);
    fn_80016180();
}

#pragma use_lmw_stmw on
void fn_80129CA8(s32 arg0, s32 arg1, u8 arg2, s32 arg3, s32 arg4, u32 arg5) {
    void fn_800056A0(s32);
    void *fn_8000CAA0(void *, u32);
    void *fn_8000CAF0(void *, s32);
    void fn_8001EEEC(void *);
    void *fn_80040844(void);
    void *fn_8004721C(void *, s32, s32, s32, s32);
    void fn_80049CB4(void *, void *);
    void fn_80049D30(void *);
    void fn_800558D8(void *, void *, void *);
    void *fn_800C45B8(s32, void *, s32);
    void fn_8010FE08(void *, s8, s8, s32);
    void fn_8010FEEC(void *, s8, s8, s32, s32);
    void fn_80201FC4(void *);
    void fn_80234450(void *, s32);
    extern u8 lbl_80275740[];
    extern u8 lbl_80290AE0[];
    extern u8 lbl_802EF4C8[];
    extern u8 lbl_8032BB58[0x200];
    extern u32 lbl_8036A408;
    extern f32 lbl_8036A420;
    extern f32 lbl_8036A42C;
    extern f32 lbl_8036A430;
    s32 y;
    void *obj;
    void *node;
    s32 a3;
    u32 sp8;
    void *sub;
    f32 f42c;
    s32 dy;
    s32 dx;
    unsigned int a5;
    s32 x;
    s32 a4;
    f32 f420;
    f32 f430;

    a5 = arg5;
    a4 = arg4;
    a3 = arg3;
    switch (arg2) {
    case 1:
        dx = -1;
        break;
    case 2:
        dx = 1;
        break;
    default:
        dx = 0;
        break;
    }
    x = arg0 + dx;
    switch (arg2) {
    case 4:
        dy = 1;
        break;
    case 8:
        dy = -1;
        break;
    default:
        dy = 0;
        break;
    }
    y = arg1 + dy;
    fn_8010FE08(lbl_8032BB58, (s8)(x - 1), (s8)y, 0xA);
    fn_8010FE08(lbl_8032BB58, (s8)(x + 1), (s8)y, 0xA);
    fn_8010FE08(lbl_8032BB58, (s8)x, (s8)(y - 1), 0xA);
    fn_8010FE08(lbl_8032BB58, (s8)x, (s8)(y + 1), 0xA);
    fn_8010FEEC(lbl_8032BB58, (s8)x, (s8)y, 0x27, 0);
    obj = fn_8004721C(fn_80040844(), x, y, 0x10000, 0);
    if (obj == NULL) {
        fn_800056A0(0);
        return;
    }
    if (a5) {
        node = fn_8000CAA0(lbl_80290AE0, a5);
    } else {
        node = fn_8000CAF0(lbl_80290AE0, 3);
    }
    *(void **)((u8 *)node + 0x30) = fn_800C45B8(-0xAC, lbl_80275740 + 0x164, 0);
    f42c = lbl_8036A42C;
    f420 = lbl_8036A420;
    f430 = lbl_8036A430;
    sub = *(void **)((u8 *)node + 0x30);
    *(void **)sub = obj;
    *(s32 *)((u8 *)*(void **)((u8 *)node + 0x30) + 0x34) = a4;
    *(f32 *)((u8 *)*(void **)((u8 *)node + 0x30) + 0x10) = (f32)(s8)*(u8 *)obj;
    *(f32 *)((u8 *)*(void **)((u8 *)node + 0x30) + 0x14) = (f32)(s8)*((u8 *)obj + 1);
    *(f32 *)((u8 *)*(void **)((u8 *)node + 0x30) + 0x18) = *(f32 *)((u8 *)obj + 0xC);
    *(f32 *)((u8 *)*(void **)((u8 *)node + 0x30) + 0x1C) = f42c;
    *(u8 *)((u8 *)*(void **)((u8 *)node + 0x30) + 0xB) = 0;
    *(f32 *)((u8 *)*(void **)((u8 *)node + 0x30) + 0x38) = f420;
    *(f32 *)((u8 *)*(void **)((u8 *)node + 0x30) + 0x2C) = f430;
    *(f32 *)((u8 *)*(void **)((u8 *)node + 0x30) + 0x30) = f420;
    fn_80201FC4((u8 *)*(void **)((u8 *)node + 0x30) + 0x3C);
    fn_80234450((u8 *)*(void **)((u8 *)node + 0x30) + 0x6C, a3);
    fn_8001EEEC((u8 *)*(void **)((u8 *)node + 0x30) + 0x6C);
    fn_80049D30(*(void **)*(void **)((u8 *)node + 0x30));
    sp8 = lbl_8036A408;
    fn_80049CB4(*(void **)*(void **)((u8 *)node + 0x30), &sp8);
    {
        void *child = *(void **)*(void **)((u8 *)node + 0x30);
        *(u8 *)((u8 *)child + 2) = (u8)(*(u8 *)((u8 *)child + 2) & 0xFE);
        *(s32 *)((u8 *)*(void **)((u8 *)node + 0x30) + 4) = *(s32 *)lbl_802EF4C8;
        fn_800558D8(lbl_80275740 + 0x165, *(void **)((u8 *)node + 0x30), child);
    }
}
void fn_80129F68(void *arg0) {
    M2C_UNK fn_80049174(s32, void *, s32 *, M2C_UNK);
    extern s32 lbl_8036A40C;
    s32 sp8;

    sp8 = lbl_8036A40C;
    fn_80049174(*M2C_FIELD(arg0, s32 **, 0x30), arg0, &sp8, 0xA);
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
void fn_80129FA4(void *arg0) {
    void fn_80025624(s32, s32);
    void *fn_80040844(void);
    void fn_800498A4(void *, void *, s32, f32);
    void fn_800536B0(void *, f32, f32, f32);
    void *fn_80053AE8(void *, void *);
    void fn_80147578(void *, s32, f32, f32, f32);
    void fn_8018CFA4(s32, s32, s32, s32, void *);
    void fn_80201FC4(void *);
    void fn_80202024(void *, void *, void *);
    void fn_802024D0(void *, void *, f32);
    void fn_80202540(void *, f32, f32, f32);
    void fn_802025C0(void *, f32, f32, f32);
    extern u8 lbl_80275740[];
    extern s32 lbl_80367240;
    extern f32 lbl_8036A410;
    extern f32 lbl_8036A420;
    extern f32 lbl_8036A430;
    extern f32 lbl_8036A434;
    extern f32 lbl_8036A438;
    extern f32 lbl_8036A43C;
    extern f32 lbl_8036A440;
    extern f32 lbl_8036A444;
    extern f32 lbl_8036A448;
    u8 sp98[0x30];
    u8 sp68[0x30];
    u8 sp38[0x30];
    u8 sp8[0x30];
    void *self;
    void *sub;
    void *child;
    void *cam;
    f32 scale;
    f32 unk38;
    f32 unk2c;
    s32 ib;
    s32 ia;
    void *path;

    self = arg0;
    sub = *(void **)((u8 *)self + 0x30);
    *(f32 *)((u8 *)sub + 0x2C) = lbl_8036A420;
    sub = *(void **)((u8 *)self + 0x30);
    fn_80201FC4((u8 *)sub + 0x3C);
    cam = fn_80040844();
    sub = *(void **)((u8 *)self + 0x30);
    child = *(void **)sub;
    fn_802024D0(sp38, (u8 *)sub + 0x20, lbl_8036A434 * *(f32 *)((u8 *)sub + 0x2C));
    sub = *(void **)((u8 *)self + 0x30);
    fn_80202024(sp38, (u8 *)sub + 0x3C, (u8 *)sub + 0x3C);
    fn_80202540(sp68, lbl_8036A438, lbl_8036A43C, lbl_8036A438);
    sub = *(void **)((u8 *)self + 0x30);
    fn_80202024((u8 *)sub + 0x3C, sp68, sp38);
    fn_80202540(sp68, lbl_8036A440, lbl_8036A444, lbl_8036A440);
    fn_80202024(sp68, sp38, sp98);
    scale = *(f32 *)((u8 *)cam + 0x6C);
    fn_802025C0(sp8, scale, scale, scale);
    fn_80202024(sp8, sp98, sp98);
    sub = *(void **)((u8 *)self + 0x30);
    fn_80202540(sp68,
        lbl_8036A430 * (*(f32 *)((u8 *)sub + 0x10) * scale),
        lbl_8036A430 * (-*(f32 *)((u8 *)sub + 0x18) * scale),
        lbl_8036A430 * (*(f32 *)((u8 *)sub + 0x14) * scale));
    fn_80202024(sp68, sp98, sp98);
    fn_80202024((u8 *)cam + 0x70, sp98, (u8 *)child + 0x24);
    sub = *(void **)((u8 *)self + 0x30);
    unk38 = *(f32 *)((u8 *)sub + 0x38);
    unk2c = *(f32 *)((u8 *)sub + 0x2C);
    ia = (s32)(unk38 / lbl_8036A448);
    ib = (s32)((unk38 + unk2c) / lbl_8036A448);
    if (!(lbl_8036A420 != unk38 && ia == ib)) {
        fn_80147578(lbl_80275740 + 0x16F, 0x64,
            lbl_8036A410 + *(f32 *)((u8 *)sub + 0x10),
            lbl_8036A410 + *(f32 *)((u8 *)sub + 0x14),
            *(f32 *)((u8 *)sub + 0x18));
    }
    sub = *(void **)((u8 *)self + 0x30);
    unk38 = *(f32 *)((u8 *)sub + 0x38);
    *(f32 *)((u8 *)sub + 0x38) = unk38 + *(f32 *)((u8 *)sub + 0x2C);
    fn_800498A4(*(void **)(*(void **)((u8 *)self + 0x30)), self, 0, unk38);
    sub = *(void **)((u8 *)self + 0x30);
    fn_80147578(lbl_80275740 + 0x182, 0x64,
        lbl_8036A410 + *(f32 *)((u8 *)sub + 0x10),
        lbl_8036A410 + *(f32 *)((u8 *)sub + 0x14),
        *(f32 *)((u8 *)sub + 0x18));
    fn_80025624(lbl_80367240, 8);
    fn_8018CFA4(0x1E, 6, 2, 0, self);
    path = fn_80053AE8(lbl_80275740 + 0x165, self);
    sub = *(void **)((u8 *)self + 0x30);
    fn_800536B0(path,
        lbl_8036A410 + *(f32 *)((u8 *)sub + 0x10),
        lbl_8036A410 + *(f32 *)((u8 *)sub + 0x14),
        *(f32 *)((u8 *)sub + 0x18));
    *(f32 *)((u8 *)*(void **)((u8 *)path + 0x30) + 0x18) = lbl_8036A410;
}
#pragma pop
void fn_8012A240(void) {
    M2C_UNK fn_8012A530();
    fn_8012A530();
}

void fn_8012A260(void *arg0) {
    void Process_Goto(void *, s32);
    extern u8 lbl_80275688[];
    extern f32 gTileCenter;
    struct Vec { f32 x,y,z; };
    struct Vec d,c,b,a;
    u8 *self=arg0;
    u8 *state;
    u8 *table=lbl_80275688;
    f32 center;
    s32 coord;
    u32 index;
    *(u16 *)(*(u8 **)(self+0x30)+8)=0;
    state=*(u8 **)(self+0x30);
    if ((s32)state[0x6C+state[0xB]] == 16) {
        Process_Goto(self,2);
        return;
    }
    center=gTileCenter;
    coord=(s32)(center+*(f32 *)(state+0x10));
    state[0xC]=coord;
    (*(u8 **)(self+0x30))[0xE]=coord;
    state=*(u8 **)(self+0x30);
    coord=(s32)(center+*(f32 *)(state+0x14));
    state[0xD]=coord;
    (*(u8 **)(self+0x30))[0xF]=coord;
    state=*(u8 **)(self+0x30);
    index=state[0xB]++;
    state[0xA]=state[0x6C+index];
    state=*(u8 **)(self+0x30);
    switch(state[0xA]) {
    case 8:
        a=*(struct Vec *)(table+0x7C);
        *(f32 *)(state+0x20)=a.x; *(f32 *)(state+0x24)=a.y; *(f32 *)(state+0x28)=a.z;
        state=*(u8 **)(self+0x30); state[0xD]=state[0xF]-1;
        break;
    case 4:
        b=*(struct Vec *)(table+0x88);
        *(f32 *)(state+0x20)=b.x; *(f32 *)(state+0x24)=b.y; *(f32 *)(state+0x28)=b.z;
        state=*(u8 **)(self+0x30); state[0xD]=state[0xF]+1;
        break;
    case 1:
        c=*(struct Vec *)(table+0x94);
        *(f32 *)(state+0x20)=c.x; *(f32 *)(state+0x24)=c.y; *(f32 *)(state+0x28)=c.z;
        state=*(u8 **)(self+0x30); state[0xC]=state[0xE]-1;
        break;
    case 2:
        d=*(struct Vec *)(table+0xA0);
        *(f32 *)(state+0x20)=d.x; *(f32 *)(state+0x24)=d.y; *(f32 *)(state+0x28)=d.z;
        state=*(u8 **)(self+0x30); state[0xC]=state[0xE]+1;
        break;
    }
}

void fn_8012A45C(void *arg0) {
    void Process_Goto(void *, s32);
    void fn_80183E3C(s32, void *, void *, s32, s32, s32);
    s32 fn_8012AA68(void *);
    void *sub;
    u32 id;

    sub = *(void **)((u8 *)arg0 + 0x30);
    id = *(u32 *)((u8 *)sub + 4);
    if (id == 0) {
        Process_Goto(arg0, 1);
        return;
    }
    fn_80183E3C(id, (void *)fn_8012AA68, arg0,
                (s32)*(f32 *)((u8 *)sub + 0x10),
                (s32)*(f32 *)((u8 *)sub + 0x14), 0);
}

void fn_8012A4CC(void *arg0) {
    u8 fn_80040824(void);
    void *Map_Get(void);
    void fn_80044450(void *, s32);
    void fn_800C4588(void *);
    void *inner;

    inner = **(void ***)((u8 *)arg0 + 0x30);
    *(u8 *)((u8 *)inner + 2) |= 1;
    if ((u8)fn_80040824() != 0) {
        fn_80044450(Map_Get(), 1);
    }
    fn_800C4588(*(void **)((u8 *)arg0 + 0x30));
    *(void **)((u8 *)arg0 + 0x30) = NULL;
}

#pragma global_optimizer on
#pragma opt_propagation off
#pragma use_lmw_stmw on
void fn_8012A530(void *arg0) {
    void fn_8000C188(void *);
    f32 fn_8001F53C(void *, s8, s8, s32);
    f32 fn_80023068(void *, f32, f32);
    void *fn_80040844(void);
    void fn_80147578(void *, s32, f32, f32, f32);
    void fn_8014CBD8(void *, f32, f32);
    void fn_80184688(void *, s32, s32, s32);
    void fn_80184BE8(void *, s32, s32, s32);
    void fn_80184C7C(void *, s32, s32, s32);
    void fn_80202024(void *, void *, void *);
    void fn_802024D0(void *, void *, f32);
    void fn_80202540(void *, f32, f32, f32);
    void fn_802025C0(void *, f32, f32, f32);
    void fn_802029C4(void *, void *, void *);
    extern u32 lbl_80275734[3];
    extern u8 lbl_80275740[];
    extern u16 lbl_802B14E4[];
    extern u8 lbl_802CA518[];
    extern f32 lbl_8036A410;
    extern f64 lbl_8036A418;
    extern f32 lbl_8036A420;
    extern f32 lbl_8036A42C;
    extern f32 lbl_8036A430;
    extern f32 lbl_8036A434;
    extern f32 lbl_8036A438;
    extern f32 lbl_8036A43C;
    extern f32 lbl_8036A440;
    extern f32 lbl_8036A444;
    extern f32 lbl_8036A448;
    extern const f32 lbl_8036A44C;
    extern const f32 lbl_8036A450;
    extern const f32 lbl_8036A454;
    extern const f32 lbl_8036A458;
    extern const f32 lbl_8036A45C;
    extern const f32 lbl_8036A460;
    extern const f32 lbl_8036A464;
    extern u8 lbl_80330708[0x578];

    u8 spD4[0x30];
    u8 spA4[0x30];
    u8 sp74[0x30];
    u8 sp44[0x30];
    u8 sp14[0x30];
    u32 vec[3];
    s32 oldX;
    s32 oldY;
    s32 newX;
    s32 newY;
    int ib;
    void *sub;
    void *child;
    f32 z;
    f32 unk38;
    void *unit;
    void *cam;
    f32 scale;
    int ia;
    void *self;
    void (*cb)(s32, s32, void *);
    u8 id;
    f32 t;
    f32 x;
    f32 y;
    f32 vx;
    f32 vz;

    self = arg0;
    vec[0] = lbl_80275734[0];
    vec[1] = lbl_80275734[1];
    vec[2] = lbl_80275734[2];
    sub = *(void **)((u8 *)self + 0x30);
    fn_802024D0(spD4, (u8 *)sub + 0x20, lbl_8036A44C);
    fn_802029C4(spD4, vec, vec);

    {
        f32 c;
        sub = *(void **)((u8 *)self + 0x30);
        scale = (lbl_8036A450 * *(f32 *)((u8 *)sub + 0x2C)) / lbl_8036A454;
        vx = *(f32 *)&vec[0] * scale;
        vz = *(f32 *)&vec[2] * scale;
        x = *(f32 *)((u8 *)sub + 0x10);
        y = *(f32 *)((u8 *)sub + 0x14);
        c = lbl_8036A410;
        oldX = (s32)(c + x);
        oldY = (s32)(c + y);
        *(f32 *)((u8 *)sub + 0x10) = x + vx;
        sub = *(void **)((u8 *)self + 0x30);
        *(f32 *)((u8 *)sub + 0x14) = *(f32 *)((u8 *)sub + 0x14) + vz;

        sub = *(void **)((u8 *)self + 0x30);
        {
            s32 tx = (s32)(c + *(f32 *)((u8 *)sub + 0x10));
            s32 ty = (s32)(c + *(f32 *)((u8 *)sub + 0x14));
            newX = tx;
            newY = ty;
            *(f32 *)((u8 *)*(void **)((u8 *)self + 0x30) + 0x30) =
                lbl_8036A458 * fn_8001F53C(lbl_802CA518, (s8)tx, (s8)ty, *((u8 *)sub + 0xA));
        }
    }

    sub = *(void **)((u8 *)self + 0x30);
    *(f32 *)((u8 *)sub + 0x2C) = *(f32 *)((u8 *)sub + 0x2C) + *(f32 *)((u8 *)sub + 0x30);
    sub = *(void **)((u8 *)self + 0x30);
    if (*(f32 *)((u8 *)sub + 0x2C) > lbl_8036A45C) {
        *(f32 *)((u8 *)sub + 0x2C) = lbl_8036A45C;
    }
    sub = *(void **)((u8 *)self + 0x30);
    if (*(f32 *)((u8 *)sub + 0x2C) < lbl_8036A430) {
        *(f32 *)((u8 *)sub + 0x2C) = lbl_8036A430;
    }

    sub = *(void **)((u8 *)self + 0x30);
    if ((s32)*(f32 *)((u8 *)sub + 0x10) > (s32)*((u8 *)sub + 0xE)
        || (s32)*(f32 *)((u8 *)sub + 0x14) > (s32)*((u8 *)sub + 0xF)
        || (s32)(lbl_8036A460 + *(f32 *)((u8 *)sub + 0x10)) < (s32)*((u8 *)sub + 0xE)
        || (s32)(lbl_8036A460 + *(f32 *)((u8 *)sub + 0x14)) < (s32)*((u8 *)sub + 0xF)) {
        {
            u8 *p = (u8 *)sub + *((u8 *)sub + 0xB);
            if ((s32)p[0x6C] == 0x10) {
                *(f32 *)((u8 *)sub + 0x10) = (f32)(s32)*((u8 *)sub + 0xC);
                sub = *(void **)((u8 *)self + 0x30);
                *(f32 *)((u8 *)sub + 0x14) = (f32)(s32)*((u8 *)sub + 0xD);
            }
        }
        fn_8000C188(self);
    }

    if (oldX != newX || oldY != newY) {
        sub = *(void **)((u8 *)self + 0x30);
        cb = *(void (**)(s32, s32, void *))((u8 *)sub + 0x34);
        if (cb) {
            cb(newX, newY, self);
        } else {
            id = *(u8 *)((lbl_802CA518 + (s8)newX) + ((s8)newY << 6) + 0xD);
            if (id) {
                unit = (u8 *)lbl_802B14E4 + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit) {
                fn_80184C7C(unit, 9, 8, 0);
                fn_80184BE8(unit, 0, 8, 0);
                fn_80184688(unit, 1, 2, 0);
            }
        }
    }

    sub = *(void **)((u8 *)self + 0x30);
    z = fn_80023068(lbl_802CA518,
        lbl_8036A410 + *(f32 *)((u8 *)sub + 0x10),
        lbl_8036A410 + *(f32 *)((u8 *)sub + 0x14));
    sub = *(void **)((u8 *)self + 0x30);
    if (*(f32 *)((u8 *)sub + 0x18) < z) {
        *(f32 *)((u8 *)sub + 0x1C) = *(f32 *)((u8 *)sub + 0x1C) * lbl_8036A464;
    } else {
        *(f32 *)((u8 *)sub + 0x1C) = lbl_8036A42C;
    }
    sub = *(void **)((u8 *)self + 0x30);
    *(f32 *)((u8 *)sub + 0x18) = *(f32 *)((u8 *)sub + 0x18) + *(f32 *)((u8 *)sub + 0x1C);
    sub = *(void **)((u8 *)self + 0x30);
    if (*(f32 *)((u8 *)sub + 0x18) > z) {
        *(f32 *)((u8 *)sub + 0x18) = z;
    }

    cam = fn_80040844();
    sub = *(void **)((u8 *)self + 0x30);
    child = *(void **)sub;
    fn_802024D0(sp44, (u8 *)sub + 0x20, lbl_8036A434 * *(f32 *)((u8 *)sub + 0x2C));
    sub = *(void **)((u8 *)self + 0x30);
    fn_80202024(sp44, (u8 *)sub + 0x3C, (u8 *)sub + 0x3C);
    fn_80202540(sp74, lbl_8036A438, lbl_8036A43C, lbl_8036A438);
    sub = *(void **)((u8 *)self + 0x30);
    fn_80202024((u8 *)sub + 0x3C, sp74, sp44);
    fn_80202540(sp74, lbl_8036A440, lbl_8036A444, lbl_8036A440);
    fn_80202024(sp74, sp44, spA4);
    t = *(f32 *)((u8 *)cam + 0x6C);
    fn_802025C0(sp14, t, t, t);
    fn_80202024(sp14, spA4, spA4);
    sub = *(void **)((u8 *)self + 0x30);
    fn_80202540(sp74,
        lbl_8036A430 * (*(f32 *)((u8 *)sub + 0x10) * t),
        lbl_8036A430 * (-*(f32 *)((u8 *)sub + 0x18) * t),
        lbl_8036A430 * (*(f32 *)((u8 *)sub + 0x14) * t));
    fn_80202024(sp74, spA4, spA4);
    fn_80202024((u8 *)cam + 0x70, spA4, (u8 *)child + 0x24);

    sub = *(void **)((u8 *)self + 0x30);
    unk38 = *(f32 *)((u8 *)sub + 0x38);
    ia = (s32)(unk38 / lbl_8036A448);
    ib = (s32)((unk38 + *(f32 *)((u8 *)sub + 0x2C)) / lbl_8036A448);
    if (lbl_8036A420 == unk38 || ia != ib) {
        fn_80147578(lbl_80275740 + 0x16F, 0x64,
            lbl_8036A410 + *(f32 *)((u8 *)sub + 0x10),
            lbl_8036A410 + *(f32 *)((u8 *)sub + 0x14),
            *(f32 *)((u8 *)sub + 0x18));
    }
    sub = *(void **)((u8 *)self + 0x30);
    *(f32 *)((u8 *)sub + 0x38) = *(f32 *)((u8 *)sub + 0x38) + *(f32 *)((u8 *)sub + 0x2C);
    sub = *(void **)((u8 *)self + 0x30);
    fn_8014CBD8(lbl_80330708,
        *(f32 *)((u8 *)sub + 0x10),
        *(f32 *)((u8 *)sub + 0x14));
}
#pragma opt_propagation on

s32 fn_8012AA68(void *arg0) {
    void Process_Goto(void *, s32);
    Process_Goto(arg0, 1);
    return 1;
}

void fn_8012AA90(s32 arg0,s32 arg1,void *arg2) {
void MapObjEvent_Remove(void *,s8,s8,s32);
void MapObjEvent_Push(void *,s8,s8,s32,s32);
void *Map_Get(void);
void *Map_FindObjAt(void *,s32,s32,s32,s32);
void fn_800056A0(s32);
void *Process_CreateChild(void *,void *);
void *Process_Create(void *,s32);
void BattleState_SetCamPos(void *,f32,f32);
void *obj;
void *proc;
MapObjEvent_Remove(gMapObjEventList,arg0,arg1,9);
MapObjEvent_Push(gMapObjEventList,arg0,arg1,0x26,0);
obj=Map_FindObjAt(Map_Get(),arg0,arg1,0x800,0x10);
if(!obj) { fn_800056A0(0); return; }
if(arg2) proc=Process_CreateChild(lbl_80290AA0,arg2);
else proc=Process_Create(lbl_80290AA0,3);
M2C_FIELD(proc,void **,0x30)=obj;
BattleState_SetCamPos(gBattleState,(f32)arg0,(f32)arg1);
}

/* Fade the map object at +0x30 out if visible, else in; collect linked objs into the fade process. */
void MapObj_ToggleLinkedFade(void *proc) {
    u8 MapObj_IsVisible(void *);
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, s32);
    void *Map_Get(void);
    s32 Map_CollectLinkedObjs(void *, void *, void *);
    extern u8 E_MapObjFadeOut_script[];
    extern u8 E_MapObjFadeIn_script[];
    void *mapObj;
    u8 *fadeProc;
    void *map;

    if ((u8)MapObj_IsVisible(*(void **)((u8 *)proc + 0x30)) != 0) {
        mapObj = *(void **)((u8 *)proc + 0x30);
        if (proc != NULL) {
            fadeProc = (u8 *)Process_CreateChild(E_MapObjFadeOut_script, proc);
        } else {
            fadeProc = (u8 *)Process_Create(E_MapObjFadeOut_script, 3);
        }
        map = Map_Get();
        *(s32 *)(fadeProc + 0x50) = Map_CollectLinkedObjs(map, mapObj, fadeProc + 0x30);
    } else {
        mapObj = *(void **)((u8 *)proc + 0x30);
        if (proc != NULL) {
            fadeProc = (u8 *)Process_CreateChild(E_MapObjFadeIn_script, proc);
        } else {
            fadeProc = (u8 *)Process_Create(E_MapObjFadeIn_script, 3);
        }
        map = Map_Get();
        *(s32 *)(fadeProc + 0x50) = Map_CollectLinkedObjs(map, mapObj, fadeProc + 0x30);
    }
}

/* Spawn map effect and SE at the tile stored in the process userdata. */
void Effect_SpawnAtMapTile(void *proc) {
    f32 Map_SampleHeight(void *, f32, f32);
    void Effect_Create(void *, s32);
    void Effect_SetPos(f32, f32, f32);
    void SeCue_PlayAt(void *, s32, f32, f32, f32);
    extern u8 lbl_80275740[];
    extern u8 gBattleMap[];
    extern f32 gTileCenter;
    u8 *tile;
    f32 y;
    f32 x;
    f32 z;

    tile = *(u8 **)((u8 *)proc + 0x30);
    x = gTileCenter + (f32)(s8)tile[0];
    y = gTileCenter + (f32)(s8)tile[1];
    z = Map_SampleHeight(gBattleMap, x, y);
    Effect_Create(lbl_80275740 + 0x165, 0);
    Effect_SetPos(x, y, z);
    SeCue_PlayAt(lbl_80275740 + 0x196, 0x64, x, y, z);
}

void fn_8012AD80(void) {
    extern u16 lbl_80275740[];
    GActor_RequestRes((u8 *)lbl_80275740 + 0x165);
}

#pragma use_lmw_stmw on
void fn_8012ADAC(s32 arg0, s32 arg1, u32 arg2) {
    extern u8 lbl_80290A58[72];
    extern u8 gBattleState[1400];

    void *fn_800056A0(void *);
    void *Process_CreateChild(void *, u32);
    void *Process_Create(void *, s32);
    void *Map_Get(void);
    void *Map_FindObjNear(void *, s32, s32, u32, u32);
    s32 Map_FindObjAt(void *, s8, s8, u32, u32);
    void BattleState_SetCamPos(void *, f32, f32);

    s32 t31;
    void *t30;
    void *r6;
    u32 a2 = arg2;
    s32 a1 = arg1;
    s32 a0 = arg0;

    t30 = Map_FindObjNear(Map_Get(), a0, a1, 0xA00, 0);
    if (t30 == NULL) {
        fn_800056A0(0);
        return;
    }
    a1 = *(s8 *)t30;
    a0 = *((s8 *)t30 + 1);
    t31 = Map_FindObjAt(Map_Get(), (s8)a1, (s8)a0, 0x20000, 0);
    if (t31 == 0) {
        fn_800056A0(0);
        return;
    }
    if (a2 != 0) {
        r6 = Process_CreateChild(lbl_80290A58, a2);
    } else {
        r6 = Process_Create(lbl_80290A58, 3);
    }
    *(void **)((u8 *)r6 + 0x38) = t30;
    *(s32 *)((u8 *)r6 + 0x3c) = t31;
    *(s32 *)((u8 *)r6 + 0x30) = a1;
    *(s32 *)((u8 *)r6 + 0x34) = a0;
    BattleState_SetCamPos(gBattleState, (f32)a1, (f32)a0);
}
#pragma use_lmw_stmw reset
void fn_8012AEC4(void *arg0) {
    u8 fn_80040824(void);
    void *Map_Get(void);
    void fn_80044450(void *, s32);
    void Model_SetAlpha(void *, s32);
    void fn_80049D08(void *);
    void *p;

    p = *(void **)((u8 *)arg0 + 0x38);
    Model_SetAlpha((u8 *)p + 0x14, 0);
    p = *(void **)((u8 *)arg0 + 0x38);
    *(u8 *)((u8 *)p + 2) |= 1;
    p = *(void **)((u8 *)arg0 + 0x3C);
    Model_SetAlpha((u8 *)p + 0x14, 0xFF);
    p = *(void **)((u8 *)arg0 + 0x3C);
    *(u8 *)((u8 *)p + 2) &= ~1;
    fn_80049D08(*(void **)((u8 *)arg0 + 0x3C));
    if ((u8)fn_80040824() != 0) {
        fn_80044450(Map_Get(), 1);
    }
}

#pragma push
#pragma optimization_level 4
#pragma opt_lifetimes off
void fn_8012AF4C(void *arg0) {
    void fn_8000C188(void *);
    f32 fn_80059F64(f32, f32, f32, f32);
    void fn_8005F7B0(void *, s32);
    void fn_80202024(void *, void *, void *);
    void fn_802025C0(void *, f32, f32, f32);
    void fn_80202300(void *, s32, f32);
    void fn_80202540(void *, f32, f32, f32);
    f64 fn_802380D0(f32);
    f64 fn_80238638(f32);
    extern f32 lbl_8036A410;
    extern f32 lbl_8036A420;
    extern f32 lbl_8036A424;
    extern f32 lbl_8036A434;
    extern f32 lbl_8036A460;
    extern f32 lbl_8036A468;
    extern f32 lbl_8036A46C;
    extern f32 lbl_8036A474;
    extern f32 lbl_8036A470;
    extern f32 lbl_8036A478;

    u8 sp98[0x30];
    u8 sp68[0x30];
    u8 sp38[0x30];
    u8 sp8[0x30];
    register void *node;
    register f32 x;
    void *sub;
    f32 scale;
    f32 z;
    f32 y;
    register void *self;

    self = arg0;
    *(s32 *)((u8 *)self + 0x40) = *(s32 *)((u8 *)self + 0x40) + 1;
    sub = *(void **)((u8 *)self + 0x38);
    node = (u8 *)sub + 0x14;
    scale = *(f32 *)((u8 *)sub + 8);
    z = *(f32 *)((u8 *)sub + 0xC);
    y = (f32)*(s8 *)((u8 *)sub + 1);
    x = (f32)*(s8 *)((u8 *)sub + 0);

    z += fn_80059F64(lbl_8036A420, lbl_8036A460, lbl_8036A468, (f32)*(s32 *)((u8 *)self + 0x40));
    x = (lbl_8036A46C * (f32)fn_80238638((f32)*(s32 *)((u8 *)self + 0x40))) + x;
    y = (lbl_8036A46C * (f32)fn_802380D0((f32)*(s32 *)((u8 *)self + 0x40))) + y;

    fn_802025C0(sp98, lbl_8036A470, lbl_8036A470, lbl_8036A470);
    fn_80202300(sp68, 0x58, lbl_8036A474);
    fn_80202024(sp68, sp98, sp8);
    fn_80202540(sp38, lbl_8036A478, lbl_8036A478, lbl_8036A420);
    fn_80202024(sp38, sp8, sp8);
    fn_80202300(sp68, 0x5A, lbl_8036A434 * scale);
    fn_80202024(sp68, sp8, sp8);
    fn_80202540(sp38, lbl_8036A410, lbl_8036A410, lbl_8036A420);
    fn_80202024(sp38, sp8, sp8);
    fn_80202540(sp38, x, y, z);
    fn_80202024(sp38, sp8, (u8 *)node + 0x10);

    fn_8005F7B0(node, fn_80059F64(lbl_8036A424, lbl_8036A420, lbl_8036A468, (f32)*(s32 *)((u8 *)self + 0x40)));
    node = (u8 *)*(void **)((u8 *)self + 0x3C) + 0x14;
    fn_8005F7B0(node, fn_80059F64(lbl_8036A420, lbl_8036A424, lbl_8036A468, (f32)*(s32 *)((u8 *)self + 0x40)));

    if ((f32)*(s32 *)((u8 *)self + 0x40) >= lbl_8036A468) {
        fn_8000C188(self);
    }
}
#pragma pop
void fn_8012B230(void *arg0) {
    u8 fn_80049D84(void *);
    void fn_800498A4(void *, s32, s32);
    void PSMTXRotRad(void *, s32, f32);
    void fn_802029C4(void *, void *, void *);
    void *Effect_Create(void *, void *);
    f32 Map_SampleHeight(void *, f32, f32);
    void Effect_SetPos(void *, f32, f32, f32);
    extern s32 lbl_802756F8[];
    extern u8 lbl_80275740[];
    extern u8 gBattleMap[];
    extern f32 lbl_8036A434;
    extern f32 gTileCenter;
    u8 mtx[0x30];
    s32 vec[3];
    f32 x;
    f32 y;
    f32 fx;
    f32 fy;
    void *effect;
    void *obj;
    s32 *src;

    *(s32 *)((u8 *)arg0 + 0x40) = 0;
    obj = *(void **)((u8 *)arg0 + 0x3C);
    *(u8 *)((u8 *)obj + 2) &= ~1;
    if ((u8)fn_80049D84(*(void **)((u8 *)arg0 + 0x3C)) != 0) {
        fn_800498A4(*(void **)((u8 *)arg0 + 0x3C), 0, 0);
    }
    src = lbl_802756F8;
    vec[0] = src[0];
    vec[1] = src[1];
    vec[2] = src[2];
    PSMTXRotRad(mtx, 0x5A, lbl_8036A434 * *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x3C) + 8));
    fn_802029C4(mtx, vec, vec);
    fx = gTileCenter + (f32)*(s32 *)((u8 *)arg0 + 0x30);
    fy = gTileCenter + (f32)*(s32 *)((u8 *)arg0 + 0x34);
    x = fx + ((f32 *)vec)[0];
    y = fy + ((f32 *)vec)[1];
    effect = Effect_Create(lbl_80275740 + 0x1A7, arg0);
    Effect_SetPos(effect, x, y, Map_SampleHeight(gBattleMap, x, y));
}

void fn_8012B394(void) {
    extern u16 lbl_80275740[];
    GActor_RequestRes((u8 *)lbl_80275740 + 0x1a7);
}

void fn_8012B3C0(s32 arg0, s32 arg1, s32 arg2) {
    s32 r = Map_Get();
    r = Map_FindObjAt(r, arg0, arg1, 0x4200, 0);
    if ((u32)r != 0U) {
        fn_800498A4(r, arg2, 0);
    }
}

extern u8 lbl_80290A40[16];
void fn_8012B42C(s32 arg0) {
    void Process_Create(void *, s32);
    extern u8 lbl_80290A40[16];
    Process_Create(lbl_80290A40, arg0);
}

void fn_8012B458(void *arg0) {
    M2C_UNK Process_Unlink(s32);
    extern s32 gUiInputFlags;
    if (gUiInputFlags & 1) {
        Process_Unlink(M2C_FIELD(arg0, s32 *, 0x18));
    }
}

#pragma optimization_level 3
void fn_8012B488(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    void *FileCache_Load(void *);
    s32 fn_8003F47C(void);
    void *Heap_AllocRaw(s32);
    s32 fn_8003F224(void *, s32);
    extern u8 lbl_80290C44[];
    extern u8 lbl_802758F8[];
    void *self;
    s32 i;
    void *src;
    register s32 off;
    void *arr;

    self = Process_CreateChild(lbl_80290C44, arg0);
    src = FileCache_Load(lbl_802758F8 + 0x21);
    *(s32 *)((u8 *)self + 0x38) = fn_8003F47C();
    arr = Heap_AllocRaw(*(s32 *)((u8 *)self + 0x38) << 2);
    i = 0;
    *(void **)((u8 *)self + 0x3C) = arr;
    off = i;
    while (i < *(s32 *)((u8 *)self + 0x38)) {
        s32 v = fn_8003F224(src, i);
        i += 1;
        *(s32 *)((u8 *)*(void **)((u8 *)self + 0x3C) + off) = v;
        off += 4;
    }
    *(s32 *)((u8 *)self + 0x30) = 0;
    *(s32 *)((u8 *)self + 0x34) = 0;
    *((u8 *)self + 0x40) = 0;
    *((u8 *)self + 0x41) = 0;
    *(s32 *)((u8 *)self + 0x48) = 0;
    *(s32 *)((u8 *)self + 0x44) = 0;
}
#pragma optimization_level reset
#pragma opt_propagation off
void fn_8012B554(void *arg0) {
    s32 Rand_Range(s32);
    void fn_8007ADC8(s32);
    void *fn_8007BD30(s32, void *, s32, s32, s32, s32, void *);
    void **fn_8007C3F8(void);
    s32 fn_8007C400(void);

    void **list;
    u8 *p;
    unsigned int count;
    s32 i;
    s32 remaining;
    s32 index;
    void *sel;
    void *item;
    u8 flag;

    if (*(u8 *)((u8 *)arg0 + 0x41) != 0) {
        *(u8 *)((u8 *)arg0 + 0x41) = (*(u8 *)((u8 *)arg0 + 0x41) == 0);
        if (*(u8 *)((u8 *)arg0 + 0x41) != 0) {
            list = fn_8007C3F8();
            count = 0;
            i = count;
            p = (u8 *)list;
            for (; fn_8007C400() > i; ) {
                item = *(void **)p;
                flag = 0;
                if ((s8)*(u8 *)((u8 *)item + 3) == (s8)*(u8 *)((u8 *)item + 5)
                    && (s32)*(u8 *)((u8 *)item + 4) == 0x4C) {
                    flag = 1;
                }
                if (flag != 0) {
                    count += 1;
                }
                p += 0x20;
                i += 1;
            }
            remaining = Rand_Range(count);
            p = (u8 *)list;
            index = 0;
            for (; fn_8007C400() > index; ) {
                item = *(void **)p;
                flag = 0;
                if ((s8)*(u8 *)((u8 *)item + 3) == (s8)*(u8 *)((u8 *)item + 5)
                    && (s32)*(u8 *)((u8 *)item + 4) == 0x4C) {
                    flag = 1;
                }
                if (flag != 0) {
                    remaining -= 1;
                    if (remaining == 0) {
                        sel = *(void **)((u8 *)list + (index << 5));
                        goto found1;
                    }
                }
                p += 0x20;
                index += 1;
            }
            sel = NULL;
        found1:
            *(void **)((u8 *)arg0 + 0x44) = fn_8007BD30(0, sel, 0xCC, 0x128, 0x81, 0, arg0);
            list = fn_8007C3F8();
            count = 0;
            i = count;
            p = (u8 *)list;
            for (; fn_8007C400() > i; ) {
                item = *(void **)p;
                flag = 0;
                if ((s8)*(u8 *)((u8 *)item + 3) == (s8)*(u8 *)((u8 *)item + 5)
                    && (s32)*(u8 *)((u8 *)item + 4) == 0x4C) {
                    flag = 1;
                }
                if (flag != 0) {
                    count += 1;
                }
                p += 0x20;
                i += 1;
            }
            count = Rand_Range(count);
            p = (u8 *)list;
            i = 0;
            for (; fn_8007C400() > i; ) {
                item = *(void **)p;
                flag = 0;
                if ((s8)*(u8 *)((u8 *)item + 3) == (s8)*(u8 *)((u8 *)item + 5)
                    && (s32)*(u8 *)((u8 *)item + 4) == 0x4C) {
                    flag = 1;
                }
                if (flag != 0) {
                    count -= 1;
                    if (count == 0) {
                        sel = *(void **)((u8 *)list + (i << 5));
                        goto found2;
                    }
                }
                p += 0x20;
                i += 1;
            }
            sel = NULL;
        found2:
            *(void **)((u8 *)arg0 + 0x48) = fn_8007BD30(1, sel, 0x194, 0x128, 0x80, 0, arg0);
            *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x44) + 0x42) = 0xFF;
            *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 0x42) = 0xFF;
        } else {
            fn_8007ADC8(0);
            fn_8007ADC8(1);
            *(void **)((u8 *)arg0 + 0x48) = NULL;
            *(void **)((u8 *)arg0 + 0x44) = NULL;
        }
    }
}
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs on
#pragma opt_common_subs off
#pragma opt_strength_reduction off
void fn_8012B7DC(void *self) {
    void fn_80007124(void *);
    void fn_80007698(u8);
    void fn_800076AC(s32, s32, s32, u8);
    void fn_800077D8(f32, f32, f32, f32);
    void fn_80007858(f32, f32);
    void fn_80007870(f32);
    void fn_80007884(void);
    void fn_80007898(s32);
    void fn_80009D74(f32, f32, f32, f32);
    void fn_8000A174(s32, s32);
    void fn_8000A248(void);
    void fn_8000A258(void);
    void fn_8000C188(void *);
    s32 fn_8000CEE4(s32);
    void fn_8001003C(s16, s16, s32, s32, s32, void *, ...);
    void fn_80024398(void *, void *, s32);
    void fn_8007ADC8(s32);
    void *fn_8007BD30(s32, void *, s32, s32, s32, s32, void *);
    void **fn_8007C3F8(void);
    s32 fn_8007C400(void);
    void fn_80109EEC(void *);
    void fn_80231D94(void *, void *, ...);
    extern char lbl_802758F8[];
    extern s32 lbl_80367240;
    extern s32 lbl_80367A88;
    extern s32 lbl_80367A9C;
    extern const f32 lbl_8036A480;
    extern const f32 lbl_8036A484;
    extern const f32 lbl_8036A488;
    extern const f32 lbl_8036A48C;
    extern const f32 lbl_8036A490;
    extern const f32 lbl_8036A494;
    extern const f32 lbl_8036A498;
    extern const f32 lbl_8036A49C;
    extern const f32 lbl_8036A4A0;
    extern const f32 lbl_8036A4A4;
    extern const f32 lbl_8036A4A8;
    extern const f32 lbl_8036A4AC;
    extern const f32 lbl_8036A4B0;
    extern const f32 lbl_8036A4B4;
    extern const f32 lbl_8036A4B8;
    extern const f32 lbl_8036A4BC;
    extern const f32 lbl_8036A4C0;
    extern const f32 lbl_8036A4C4;

    void *arg0 = self;
    char buf[0x40];
    void **list;
    u8 *p;
    s32 count;
    s32 i;
    void *sel;
    void *item;
    u8 flag;
    s32 n;
    s32 idx;
    s32 *table;
    s16 y;
    void *cam;
    void *pad;
    u8 *stick;
    s32 buttons;
    s32 prev;
    s32 held;
    f32 scale;
    f32 t;

    scale = lbl_8036A480;
    pad = (void *)lbl_80367240;
    if (*(s32 *)((u8 *)pad + 4) & 0x10) {
        scale = lbl_8036A484;
    }
    {
        f64 conv_s;
        f64 conv_u;
        stick = *(u8 **)pad;
        cam = (void *)lbl_80367A88;
        t = scale * (f32)*(s8 *)(stick + 2);
        *(f32 *)((u8 *)cam + 0x40) -= t * lbl_8036A488;
        pad = (void *)lbl_80367240;
        cam = (void *)lbl_80367A88;
        stick = *(u8 **)pad;
        t = scale * (f32)*(s8 *)(stick + 3);
        *(f32 *)((u8 *)cam + 0x44) += t * lbl_8036A488;
        pad = (void *)lbl_80367240;
        cam = (void *)lbl_80367A88;
        stick = *(u8 **)pad;
        *(f32 *)((u8 *)cam + 0x54) -= (scale * (f32)stick[6]) / lbl_8036A48C;
        pad = (void *)lbl_80367240;
        cam = (void *)lbl_80367A88;
        stick = *(u8 **)pad;
        *(f32 *)((u8 *)cam + 0x54) += (scale * (f32)stick[7]) / lbl_8036A48C;
        cam = (void *)lbl_80367A88;
        if (*(f32 *)((u8 *)cam + 0x54) < lbl_8036A490) {
            *(f32 *)((u8 *)cam + 0x54) = lbl_8036A490;
        }
        cam = (void *)lbl_80367A88;
        *(f32 *)((u8 *)cam + 0x58) = *(f32 *)((u8 *)cam + 0x54);
        pad = (void *)lbl_80367240;
        cam = (void *)lbl_80367A88;
        stick = *(u8 **)pad;
        t = scale * (f32)*(s8 *)(stick + 4);
        *(f32 *)((u8 *)cam + 0x5C) += t * lbl_8036A494;
        (void)conv_s;
        (void)conv_u;
    }

    pad = (void *)lbl_80367240;
    buttons = *(s32 *)((u8 *)pad + 4);
    prev = *(s32 *)((u8 *)pad + 8);
    if (buttons & (prev ^ buttons) & 0x1000) {
        cam = (void *)lbl_80367A88;
        *(f32 *)((u8 *)cam + 0x48) = lbl_8036A498;
        cam = (void *)lbl_80367A88;
        *(f32 *)((u8 *)cam + 0x44) = lbl_8036A498;
        cam = (void *)lbl_80367A88;
        *(f32 *)((u8 *)cam + 0x40) = lbl_8036A498;
        cam = (void *)lbl_80367A88;
        *(f32 *)((u8 *)cam + 0x58) = lbl_8036A480;
        cam = (void *)lbl_80367A88;
        *(f32 *)((u8 *)cam + 0x54) = lbl_8036A480;
        cam = (void *)lbl_80367A88;
        *(f32 *)((u8 *)cam + 0x5C) = lbl_8036A498;
        fn_80109EEC((void *)lbl_80367A88);
    }

    *(s16 *)((u8 *)arg0 + 0x4C) = *(s16 *)((u8 *)arg0 + 0x4C) - 1;
    if (*(s16 *)((u8 *)arg0 + 0x4C) < 0) {
        *(s16 *)((u8 *)arg0 + 0x4C) = 0;
    }
    if (*(s32 *)((u8 *)(void *)lbl_80367240 + 4) & 0x10) {
        *(s16 *)((u8 *)arg0 + 0x4C) = 0xFF;
    }

    if (*(s16 *)((u8 *)arg0 + 0x4C) != 0) {
        fn_8000A258();
        fn_80009D74(lbl_8036A498, lbl_8036A498, lbl_8036A498, lbl_8036A480);
        fn_8000A174(0, 0x13);
        fn_8000A248();
        cam = (void *)lbl_80367A88;
        fn_80231D94(buf, lbl_802758F8 + 0x2C,
                    (s32)*(f32 *)((u8 *)cam + 0x40),
                    (s32)*(f32 *)((u8 *)cam + 0x44));
        fn_80007898(7);
        fn_80007698((u8)*(s16 *)((u8 *)arg0 + 0x4C));
        fn_80007858(lbl_8036A49C, lbl_8036A49C);
        fn_80007124(buf);
        fn_80007884();
        cam = (void *)lbl_80367A88;
        fn_80231D94(buf, lbl_802758F8 + 0x39,
                    (s32)(lbl_8036A4A0 * *(f32 *)((u8 *)cam + 0x54)));
        fn_80007898(7);
        fn_80007698((u8)*(s16 *)((u8 *)arg0 + 0x4C));
        fn_80007858(lbl_8036A49C, lbl_8036A4A4);
        fn_80007124(buf);
        fn_80007884();
        cam = (void *)lbl_80367A88;
        fn_80231D94(buf, lbl_802758F8 + 0x45,
                    (s32)*(f32 *)((u8 *)cam + 0x5C));
        fn_80007898(7);
        fn_80007698((u8)*(s16 *)((u8 *)arg0 + 0x4C));
        fn_80007858(lbl_8036A49C, lbl_8036A4A8);
        fn_80007124(buf);
        fn_80007884();
        fn_8000A258();
        fn_80009D74(lbl_8036A498, lbl_8036A498, lbl_8036A4AC, lbl_8036A480);
        fn_8000A174(0, 0x10);
        fn_8000A248();
        fn_80007898(1);
        fn_800077D8(lbl_8036A49C, lbl_8036A49C, lbl_8036A4B0, lbl_8036A4B4);
        fn_800076AC(0, 0, 0, (u8)*(s16 *)((u8 *)arg0 + 0x4C));
        fn_80007884();
    }

    pad = (void *)lbl_80367240;
    held = *(s32 *)((u8 *)pad + 0xC);
    if (held & 9) {
        *(s32 *)((u8 *)arg0 + 0x34) =
            *(s32 *)((u8 *)arg0 + 0x30) + (*(s32 *)((u8 *)arg0 + 0x38) - 1);
        *(s32 *)((u8 *)arg0 + 0x34) %=
            *(s32 *)((u8 *)arg0 + 0x38);
        fn_8000C188(arg0);
    } else if (held & 6) {
        *(s32 *)((u8 *)arg0 + 0x34) = *(s32 *)((u8 *)arg0 + 0x30) + 1;
        *(s32 *)((u8 *)arg0 + 0x34) %=
            *(s32 *)((u8 *)arg0 + 0x38);
        fn_8000C188(arg0);
    } else {
        buttons = *(s32 *)((u8 *)pad + 4);
        if ((u32)(buttons & 0x210) == 0x210U) {
            *(s32 *)((u8 *)arg0 + 0x34) = 0x270F;
            fn_8000C188(arg0);
        } else {
            prev = *(s32 *)((u8 *)pad + 8);
            if (buttons & (prev ^ buttons) & 0x400) {
                *(u8 *)((u8 *)arg0 + 0x40) =
                    *(u8 *)((u8 *)arg0 + 0x40) + 1;
            }
            pad = (void *)lbl_80367240;
            buttons = *(s32 *)((u8 *)pad + 4);
            prev = *(s32 *)((u8 *)pad + 8);
            if (buttons & (prev ^ buttons) & 0x800) {
                *(u8 *)((u8 *)arg0 + 0x41) =
                    (*(u8 *)((u8 *)arg0 + 0x41) == 0);
                if (*(u8 *)((u8 *)arg0 + 0x41) != 0) {
                    list = fn_8007C3F8();
                    count = 0;
                    i = count;
                    p = (u8 *)list;
                    for (; fn_8007C400() > i; ) {
                        item = *(void **)p;
                        flag = 0;
                        if ((s8)*(u8 *)((u8 *)item + 3) == (s8)*(u8 *)((u8 *)item + 5)
                            && (s32)*(u8 *)((u8 *)item + 4) == 0x4C) {
                            flag = 1;
                        }
                        if (flag != 0) {
                            count += 1;
                        }
                        p += 0x20;
                        i += 1;
                    }
                    count = fn_8000CEE4(count);
                    p = (u8 *)list;
                    i = 0;
                    for (; fn_8007C400() > i; ) {
                        item = *(void **)p;
                        flag = 0;
                        if ((s8)*(u8 *)((u8 *)item + 3) == (s8)*(u8 *)((u8 *)item + 5)
                            && (s32)*(u8 *)((u8 *)item + 4) == 0x4C) {
                            flag = 1;
                        }
                        if (flag != 0) {
                            count -= 1;
                            if (count == 0) {
                                sel = *(void **)((u8 *)list + (i << 5));
                                goto found1;
                            }
                        }
                        p += 0x20;
                        i += 1;
                    }
                    sel = NULL;
                found1:
                    *(void **)((u8 *)arg0 + 0x44) =
                        fn_8007BD30(0, sel, 0xCC, 0x128, 0x81, 0, arg0);
                    list = fn_8007C3F8();
                    count = 0;
                    i = count;
                    p = (u8 *)list;
                    for (; fn_8007C400() > i; ) {
                        item = *(void **)p;
                        flag = 0;
                        if ((s8)*(u8 *)((u8 *)item + 3) == (s8)*(u8 *)((u8 *)item + 5)
                            && (s32)*(u8 *)((u8 *)item + 4) == 0x4C) {
                            flag = 1;
                        }
                        if (flag != 0) {
                            count += 1;
                        }
                        p += 0x20;
                        i += 1;
                    }
                    count = fn_8000CEE4(count);
                    p = (u8 *)list;
                    i = 0;
                    for (; fn_8007C400() > i; ) {
                        item = *(void **)p;
                        flag = 0;
                        if ((s8)*(u8 *)((u8 *)item + 3) == (s8)*(u8 *)((u8 *)item + 5)
                            && (s32)*(u8 *)((u8 *)item + 4) == 0x4C) {
                            flag = 1;
                        }
                        if (flag != 0) {
                            count -= 1;
                            if (count == 0) {
                                sel = *(void **)((u8 *)list + (i << 5));
                                goto found2;
                            }
                        }
                        p += 0x20;
                        i += 1;
                    }
                    sel = NULL;
                found2:
                    *(void **)((u8 *)arg0 + 0x48) =
                        fn_8007BD30(1, sel, 0x194, 0x128, 0x80, 0, arg0);
                    *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x44) + 0x42) = 0xFF;
                    *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 0x42) = 0xFF;
                } else {
                    fn_8007ADC8(0);
                    fn_8007ADC8(1);
                    *(void **)((u8 *)arg0 + 0x48) = NULL;
                    *(void **)((u8 *)arg0 + 0x44) = NULL;
                }
            }
            pad = (void *)lbl_80367240;
            buttons = *(s32 *)((u8 *)pad + 4);
            prev = *(s32 *)((u8 *)pad + 8);
            if (buttons & (prev ^ buttons) & 0x100) {
                fn_80024398(&lbl_80367A9C, arg0, 0);
                return;
            }
        }
    }

    if (!(*(u8 *)((u8 *)arg0 + 0x40) & 1)) {
        fn_8000A258();
        fn_80009D74(lbl_8036A498, lbl_8036A498, lbl_8036A498, lbl_8036A480);
        fn_8000A174(0, 0x13);
        fn_8000A248();
        i = 0;
        y = 0x10;
        do {
            n = *(s32 *)((u8 *)arg0 + 0x38);
            table = *(s32 **)((u8 *)arg0 + 0x3C);
            idx = (*(s32 *)((u8 *)arg0 + 0x30) - 8 + i + n) % n;
            fn_8001003C(0x168, y, (u8)(i == 8), 0, 1, lbl_802758F8 + 0x4C,
                        idx + 1, n, table[idx] + 4, lbl_8036A480, lbl_8036A498);
            i += 1;
            y += 0x18;
        } while (i < 0x12);
        fn_8001003C(0xE0, 0x140, 1, 0, 1, lbl_802758F8 + 0x5A, lbl_8036A480, lbl_8036A498);
        fn_8001003C(0xE0, 0x158, 1, 0, 1, lbl_802758F8 + 0x64, lbl_8036A480, lbl_8036A498);
        fn_8001003C(0xE0, 0x170, 1, 0, 1, lbl_802758F8 + 0x6E, lbl_8036A480, lbl_8036A498);
        fn_8001003C(0xE0, 0x188, 1, 0, 1, lbl_802758F8 + 0x7E, lbl_8036A480, lbl_8036A498);
        fn_8001003C(0xC8, 0x1A0, 1, 0, 1, lbl_802758F8 + 0x90, lbl_8036A480, lbl_8036A498);
        fn_8001003C(0x50, 0x140, 1, 0, 1, lbl_802758F8 + 0xA4, lbl_8036A480, lbl_8036A498);
        fn_8001003C(0x38, 0x158, 1, 0, 1, lbl_802758F8 + 0xAE, lbl_8036A480, lbl_8036A498);
        fn_8001003C(0x38, 0x170, 1, 0, 1, lbl_802758F8 + 0xC0, lbl_8036A480, lbl_8036A498);
        fn_8001003C(0x50, 0x188, 1, 0, 1, lbl_802758F8 + 0xD1, lbl_8036A480, lbl_8036A498);
        fn_8001003C(0x38, 0x1A0, 1, 0, 1, lbl_802758F8 + 0xDD, lbl_8036A480, lbl_8036A498);
        fn_8000A258();
        fn_80009D74(lbl_8036A498, lbl_8036A498, lbl_8036A4AC, lbl_8036A480);
        fn_8000A174(0, 0x10);
        fn_8000A248();
        fn_80007898(1);
        fn_800077D8(lbl_8036A4B8, lbl_8036A498, lbl_8036A4BC, lbl_8036A4C0);
        fn_800076AC(0, 0, 0, 0xB4);
        fn_80007870(lbl_8036A4C4);
        fn_80007884();
    }
}
#pragma pop
void fn_8012C21C(void *arg0) {
    u8 fn_80109B48(void *);
    void fn_80109B30(void *, u8);
    u8 fn_80109B24(void *);
    s32 Game_GetFrameCount(void);
    extern s32 lbl_80367A88;

    if ((u32)lbl_80367A88 != 0) {
        fn_80109B30((void *)lbl_80367A88, fn_80109B48((void *)lbl_80367A88));
    }
    if (*(void **)((u8 *)arg0 + 0x44) != NULL) {
        if ((Game_GetFrameCount() & 0x1FF) < 0x100) {
            *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x44) + 0x41) = fn_80109B24((void *)lbl_80367A88);
            *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 0x41) = fn_80109B24((void *)lbl_80367A88) - 0x4D;
        } else {
            *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x44) + 0x41) = fn_80109B24((void *)lbl_80367A88) - 0x4D;
            *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 0x41) = fn_80109B24((void *)lbl_80367A88);
        }
    }
}

void fn_8012C2CC(void *arg0) {
    void fn_80109020(void *);
    void Process_Goto(void *, s32);
    extern s32 lbl_80367A88;
    s32 temp_r0;
    void **table;

    table = *(void ***)((u8 *)arg0 + 0x3C);
    fn_80109020(table[*(s32 *)((u8 *)arg0 + 0x30)]);
    lbl_80367A88 = 0;
    temp_r0 = *(s32 *)((u8 *)arg0 + 0x34);
    if (temp_r0 == 0x270F) {
        Process_Goto(arg0, 0x63);
        return;
    }
    *(s32 *)((u8 *)arg0 + 0x30) = temp_r0;
}

void fn_8012C330(void *arg0) {
    s32 idx;
    s32 *arr;

    idx = *(s32 *)((u8 *)arg0 + 0x30);
    arr = *(s32 **)((u8 *)arg0 + 0x3c);
    lbl_80367A88 = Sound_Create(arr[idx], 0);
}
#include "common.h"
#include "structs.h"

extern s32 lbl_80367A88;

