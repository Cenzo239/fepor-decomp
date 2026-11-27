/* Functions from 0x800330F8 to 0x80055C70, found by decomp-toolkit. */
#include "common.h"

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

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma peephole off

#pragma peephole on

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

extern u8 lbl_8026A3A8[176];
void *fn_800A88E0(u32);

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma global_optimizer off

#pragma global_optimizer on

void *Unit_GetActiveItemPtr(void *);
void *fn_80037C20(void *);

#pragma opt_peephole off

#pragma opt_peephole reset

#pragma opt_peephole reset

extern s32 gGameState;

extern u16 gAffinityStr[];

void *Res_GetByName(s32);

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

void fn_8005C7E8(void *);

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern f32 lbl_80368EE4;

#pragma use_lmw_stmw on
#pragma opt_loop_invariants off
#pragma opt_peephole off

#pragma opt_peephole reset
#pragma opt_loop_invariants reset
#pragma use_lmw_stmw reset

extern u16* gMap;

extern u16 lbl_8026A9B0[40];
extern u16 lbl_802EFFC8[16];

extern s32 gGMaterialCurrent;
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern double lbl_80368FE0;
extern float lbl_80368FF8;
extern float lbl_80368FD8;

#pragma cplusplus reset

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

#include "common.h"
extern f32 lbl_80368FD8;
extern u16 lbl_8026AB18;
extern f32 lbl_80368FC4;
extern u16 lbl_802EFE20;

typedef struct { f32 x, y, z; } CameraVec;
typedef struct { u16 buttons[14]; } CameraButtons;
extern CameraButtons lbl_8026ABF0;
extern const f32 lbl_80369098, lbl_8036909C, lbl_80369084;
extern u8 lbl_802859E0[];
static inline void Camera_SetPosition(u8 *proc, f32 x, f32 y, f32 z) {
    *(f32 *)(*(u8 **)(proc+0x30)+0xc)=x;
    *(f32 *)(*(u8 **)(proc+0x30)+0x10)=y;
    *(f32 *)(*(u8 **)(proc+0x30)+0x14)=z;
}
#pragma use_lmw_stmw on
#pragma opt_propagation reset
#pragma peephole on
#pragma global_optimizer on
#pragma optimization_level reset
void fn_80054C14(void *arg0) {
    u8 Pad_IsActive(void *);
    u8 Pad_IsButton(void *, s32);
    u16 fn_8005F92C(void *, void *);
    s32 fn_8005F84C(void *, s32, s32);
    f32 Map_SampleHeightRaw(void *, f32, f32);
    f32 Math_Angle2D(f32, f32, f32, f32);
    void *Process_Create(void *, void *);
    void *Camera_GetActive(void);
    void fn_80019384(void *, s32);
    void fn_80025624(void *, s32);
    void fn_8018CFA4(s32, s32, s32, s32, void *);
    void fn_8018CF08(void);
    void fn_8018CF48(s32);
    extern void *gPadInput;
    u8 *unit2, *unit1;
    CameraVec *b, *a;
    void *pad;
    u8 *proc = arg0;
    CameraButtons buttons;
    CameraVec target, pos2, pos1;
    pad = *(void **)(*(u8 **)(proc + 0x30) + 0x5c);
    if (!Pad_IsActive(pad)) return;
    buttons = lbl_8026ABF0;
    switch (fn_8005F92C(pad, &buttons)) {
    case 10: fn_8018CFA4(15,6,2,1,proc); break;
    case 9: fn_8018CFA4(30,6,2,1,proc); break;
    case 11: fn_8018CFA4(60,6,2,1,proc); break;
    case 31: fn_8018CFA4(15,6,0,1,proc); break;
    case 30: fn_8018CFA4(30,6,0,1,proc); break;
    case 32: fn_8018CFA4(60,6,0,1,proc); break;
    case 33: fn_8018CF08(); break;
    case 34: fn_8018CF48(-15); break;
    case 35: fn_8018CF48(-7); break;
    case 36: fn_8018CF48(-30); break;
    case 37: fn_8018CF48(15); break;
    case 38: fn_8018CF48(7); break;
    case 39: fn_8018CF48(30); break;
    }
    if (Pad_IsButton(pad,17)) {
        *(u32 *)(*(u8 **)(proc+0x30)+8) ^= 0x20000000;
        a = NULL; b = NULL;
        unit1 = *(u8 **)(*(u8 **)(proc+0x30)+0x34);
        unit2 = *(u8 **)(*(u8 **)(proc+0x30)+0x30);
        if (unit1) {
            pos1.x=lbl_80369098+(s8)unit1[0x19e];
            pos1.y=lbl_80369098+(s8)unit1[0x19f];
            pos1.z=Map_SampleHeightRaw(gBattleMap,(s8)unit1[0x19e],(s8)unit1[0x19f]);
            a=&pos1;
        }
        if (unit2) {
            pos2.x=lbl_80369098+(s8)unit2[0x19e];
            pos2.y=lbl_80369098+(s8)unit2[0x19f];
            pos2.z=Map_SampleHeightRaw(gBattleMap,(s8)unit2[0x19e],(s8)unit2[0x19f]);
            b=&pos2;
        }
        if(a && b) *(f32 *)(*(u8 **)(proc+0x30)+0x24)=Math_Angle2D(a->x,a->y,b->x,b->y);
        if ((*(u32 *)(*(u8 **)(proc+0x30)+8)&0x20000000) && a) {
            a = a;
        } else {
            a = b;
        }
        if(a) {
            Camera_SetPosition(proc,a->x,a->y,lbl_8036909C+a->z);
        }
    }
    if (Pad_IsButton(pad,18)) {
        u8 *state=*(u8 **)(proc+0x30);
        if (*(void **)(state+0x34) && *(void **)(state+0x30)) {

            void *control;
            *(u32 *)(state+8)^=0x20000000;
            if ((*(u32 *)(*(u8 **)(proc+0x30)+8)&0x20000000) && *(void **)(*(u8 **)(proc+0x30)+0x34)) unit1=*(u8 **)(*(u8 **)(proc+0x30)+0x34);
            else unit1=*(u8 **)(*(u8 **)(proc+0x30)+0x30);
            { s8 x=*(s8 *)(unit1+0x19e); s8 y=*(s8 *)(unit1+0x19f);
            target.x=lbl_80369098+x;
            target.y=lbl_80369098+y;
            target.z=lbl_8036909C+Map_SampleHeightRaw(gBattleMap,x,y); }
            control=*(void **)(*(u8 **)(proc+0x30)+0x5c);
            if(control) {
                f32 duration=fn_8005F84C(control,(s32)*(f32 *)((u8 *)control+0x58),19);
                if(!(duration<lbl_80369084)) {
                    CameraVec to, from, start;
                    u8 *child;
                    state=*(u8 **)(proc+0x30);
                    duration-=*(f32 *)((u8 *)control+0x58);
                    start.x=*(f32 *)(state+0xc);
                    start.y=*(f32 *)(state+0x10);
                    start.z=*(f32 *)(state+0x14);
                    to=target;
                    from=start;
                    if(!(duration<lbl_80369084)) {
                        child=Process_Create(lbl_802859E0,proc);
                        *(f32 *)(child+0x34)=from.x;
                        *(f32 *)(child+0x38)=from.y;
                        *(f32 *)(child+0x3c)=from.z;
                        *(f32 *)(child+0x40)=to.x;
                        *(f32 *)(child+0x44)=to.y;
                        *(f32 *)(child+0x48)=to.z;
                        *(void **)(child+0x30)=proc;
                        *(f32 *)(child+0x4c)=duration;
                    }
                }
            }
        }
    }
    if(Pad_IsButton(pad,15)) fn_80019384(Camera_GetActive(),0);
    if(Pad_IsButton(pad,16)) fn_80019384(Camera_GetActive(),1);
    if(Pad_IsButton(pad,47)) fn_80025624(gPadInput,8);
    if(Pad_IsButton(pad,48)) fn_80025624(gPadInput,16);
}

#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma peephole on
#pragma global_optimizer on
#pragma optimization_level reset
void *fn_80055204(void *arg0, s32 arg1) {
    if (arg0 == 0) {
        return 0;
    }
    arg0 = (void *)((u8 *)arg0 + 0x28C);
    if (arg0 == 0) {
        return 0;
    }
    arg0 = *(void **)arg0;
    if (arg0 != 0) {
        arg0 = (void *)((u8 *)arg0 + (arg1 << 2));
        return *(void **)((u8 *)arg0 + 0x40);
    }
    return 0;
}

#pragma global_optimizer off
/* Walk a GActor link chain and return whether each node's resource path is present. */
u8 GActor_CheckResources(s32 name) {
    void *Res_GetByName(s32);
    void sprintf(void *, void *, void *, ...);
    u8 FileCache_IsReady(void *);
    u8 fn_800B2FF4(s32);
    s32 fn_80055C84(void *);
    s32 GActor_FormatPath(s32 *, s32);
    u8 fn_80055C7C(void *);
    u32 fn_80055C74(void *);
    extern u8 GActor_str[];
    u8 path0[0x40];
    u8 path1[0x40];
    u8 path2[0x40];
    u8 path3[0x40];
    u8 path4[0x40];
    u8 path5[0x40];
    u8 path6[0x40];
    void *node;
    u8 ok;
    s32 v;

    node = Res_GetByName(name);
    sprintf(path0, GActor_str + 0x120, GActor_str + 0x129, *(s32 *)node);
    if ((u8)FileCache_IsReady(path0) == 0) {
        return 0;
    }
    v = *(u8 *)((u8 *)node + 5);
    if (v != 0) {
        if ((u8)fn_800B2FF4(v) == 0) {
            return 0;
        }
    }
    if (*(u32 *)((u8 *)node + 8) == 0) {
        goto success1;
    }

    node = Res_GetByName(*(s32 *)((u8 *)node + 8));
    sprintf(path1, GActor_str + 0x120, GActor_str + 0x129, *(s32 *)node);
    if ((u8)FileCache_IsReady(path1) == 0) {
        ok = 0;
        goto check2;
    }
    v = *(u8 *)((u8 *)node + 5);
    if (v != 0) {
        if ((u8)fn_800B2FF4(v) == 0) {
            ok = 0;
            goto check2;
        }
    }
    if (*(u32 *)((u8 *)node + 8) == 0) {
        goto success2;
    }

    node = Res_GetByName(*(s32 *)((u8 *)node + 8));
    sprintf(path2, GActor_str + 0x120, GActor_str + 0x129, *(s32 *)node);
    if ((u8)FileCache_IsReady(path2) == 0) {
        ok = 0;
        goto check3;
    }
    v = *(u8 *)((u8 *)node + 5);
    if (v != 0) {
        if ((u8)fn_800B2FF4(v) == 0) {
            ok = 0;
            goto check3;
        }
    }
    if (*(u32 *)((u8 *)node + 8) == 0) {
        goto success3;
    }

    node = Res_GetByName(*(s32 *)((u8 *)node + 8));
    sprintf(path3, GActor_str + 0x120, GActor_str + 0x129, *(s32 *)node);
    if ((u8)FileCache_IsReady(path3) == 0) {
        ok = 0;
        goto check4;
    }
    v = *(u8 *)((u8 *)node + 5);
    if (v != 0) {
        if ((u8)fn_800B2FF4(v) == 0) {
            ok = 0;
            goto check4;
        }
    }
    if (*(u32 *)((u8 *)node + 8) == 0) {
        goto success4;
    }

    node = Res_GetByName(*(s32 *)((u8 *)node + 8));
    sprintf(path4, GActor_str + 0x120, GActor_str + 0x129, *(s32 *)node);
    if ((u8)FileCache_IsReady(path4) == 0) {
        ok = 0;
        goto check5;
    }
    v = *(u8 *)((u8 *)node + 5);
    if (v != 0) {
        if ((u8)fn_800B2FF4(v) == 0) {
            ok = 0;
            goto check5;
        }
    }
    if (*(u32 *)((u8 *)node + 8) == 0) {
        goto success5;
    }

    node = Res_GetByName(*(s32 *)((u8 *)node + 8));
    sprintf(path5, GActor_str + 0x120, GActor_str + 0x129, fn_80055C84(node));
    if ((u8)FileCache_IsReady(path5) == 0) {
        ok = 0;
        goto check6;
    }
    v = *(u8 *)((u8 *)node + 5);
    if (v != 0) {
        if ((u8)fn_800B2FF4(v) == 0) {
            ok = 0;
            goto check6;
        }
    }
    if (*(u32 *)((u8 *)node + 8) == 0) {
        goto success6;
    }

    node = Res_GetByName(*(s32 *)((u8 *)node + 8));
    GActor_FormatPath(node, (s32)path6);
    if ((u8)FileCache_IsReady(path6) == 0) {
        ok = 0;
        goto check7;
    }
    v = (u8)fn_80055C7C(node);
    if (v != 0) {
        if ((u8)fn_800B2FF4(v) == 0) {
            ok = 0;
            goto check7;
        }
    }
    if (fn_80055C74(node) != 0) {
        if ((u8)GActor_CheckResources(fn_80055C74(node)) == 0) {
            ok = 0;
            goto check7;
        }
    }

    ok = 1;
check7:
    if ((u8)ok != 0) {
        goto success6;
    }
    ok = 0;
    goto check6;

success6:
    ok = 1;
check6:
    if ((u8)ok != 0) {
        goto success5;
    }
    ok = 0;
    goto check5;

success5:
    ok = 1;
check5:
    if ((u8)ok != 0) {
        goto success4;
    }
    ok = 0;
    goto check4;

success4:
    ok = 1;
check4:
    if ((u8)ok != 0) {
        goto success3;
    }
    ok = 0;
    goto check3;

success3:
    ok = 1;
check3:
    if ((u8)ok != 0) {
        goto success2;
    }
    ok = 0;
    goto check2;

success2:
    ok = 1;
check2:
    if ((u8)ok != 0) {
        goto success1;
    }
    return 0;

success1:
    return 1;
}

void fn_800555EC(s32 name, s32 arg1) {
    void *Res_GetByName(s32);
    void sprintf(void *, void *, void *, ...);
    void fn_8005C870(void *, s32);
    void fn_800056A0(s32);
    void fn_801451BC(void);
    void fn_801452A8(u8);
    u8 fn_801452C8(u8);
    s32 fn_801452E8(void);
    void *Process_Create(void *, s32);
    s32 fn_80055C84(void *);
    s32 GActor_FormatPath(void *, void *);
    u8 fn_80055C7C(void *);
    u32 fn_80055C74(void *);
    void fn_80055B0C(s32);
    void fn_80055B64(s32);
    extern u8 GActor_str[];
    extern u8 lbl_80285968[];
    u8 path0[0x40];
    u8 path1[0x40];
    u8 path2[0x40];
    u8 path3[0x40];
    u8 path4[0x40];
    void *node;
    s32 id;
    void *proc;
    u8 flag;

    node = Res_GetByName(name);
    sprintf(path0, GActor_str + 0x120, GActor_str + 0x129, *(s32 *)node);
    fn_8005C870(path0, arg1);
    id = *(u8 *)((u8 *)node + 5);
    if (id != 0) {
        if (fn_801452C8((u8)id) == 0) {
            if (fn_801452E8() >= 0x10) {
                fn_800056A0(0);
                fn_801451BC();
            }
            fn_801452A8((u8)id);
        }
        proc = Process_Create(lbl_80285968, 4);
        *(s32 *)((u8 *)proc + 0x60) = 0x708;
    }
    if (*(u32 *)((u8 *)node + 8) == 0) {
        return;
    }

    node = Res_GetByName(*(s32 *)((u8 *)node + 8));
    sprintf(path1, GActor_str + 0x120, GActor_str + 0x129, *(s32 *)node);
    fn_8005C870(path1, arg1);
    id = *(u8 *)((u8 *)node + 5);
    if (id != 0) {
        if (fn_801452C8((u8)id) == 0) {
            if (fn_801452E8() >= 0x10) {
                fn_800056A0(0);
                fn_801451BC();
            }
            fn_801452A8((u8)id);
        }
        proc = Process_Create(lbl_80285968, 4);
        *(s32 *)((u8 *)proc + 0x60) = 0x708;
    }
    if (*(u32 *)((u8 *)node + 8) == 0) {
        return;
    }

    node = Res_GetByName(*(s32 *)((u8 *)node + 8));
    sprintf(path2, GActor_str + 0x120, GActor_str + 0x129, *(s32 *)node);
    fn_8005C870(path2, arg1);
    id = *(u8 *)((u8 *)node + 5);
    if (id != 0) {
        if (fn_801452C8((u8)id) == 0) {
            if (fn_801452E8() >= 0x10) {
                fn_800056A0(0);
                fn_801451BC();
            }
            fn_801452A8((u8)id);
        }
        proc = Process_Create(lbl_80285968, 4);
        *(s32 *)((u8 *)proc + 0x60) = 0x708;
    }
    if (*(u32 *)((u8 *)node + 8) == 0) {
        return;
    }

    node = Res_GetByName(*(s32 *)((u8 *)node + 8));
    sprintf(path3, GActor_str + 0x120, GActor_str + 0x129, fn_80055C84(node));
    fn_8005C870(path3, arg1);
    id = *(u8 *)((u8 *)node + 5);
    if (id != 0) {
        if (fn_801452C8((u8)id) == 0) {
            if (fn_801452E8() >= 0x10) {
                fn_800056A0(0);
                fn_801451BC();
            }
            fn_801452A8((u8)id);
        }
        proc = Process_Create(lbl_80285968, 4);
        *(s32 *)((u8 *)proc + 0x60) = 0x708;
    }
    if (*(u32 *)((u8 *)node + 8) == 0) {
        return;
    }

    id = (s32)Res_GetByName(fn_80055C74(node));
    GActor_FormatPath((void *)id, path4);
    fn_8005C870(path4, arg1);
    flag = fn_80055C7C((void *)id);
    if (flag != 0) {
        fn_80055B0C(flag);
        fn_80055B64(0x708);
    }
    if (fn_80055C74((void *)id) != 0) {
        fn_800555EC(fn_80055C74((void *)id), arg1);
    }
}

void GActor_RequestRes(s32 arg0) {
    void fn_800555EC(s32, s32);
    fn_800555EC(arg0, 0);
}

u32 fn_800558FC(u8 *arg0) {
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
    typedef struct Color { u8 r, g, b, a; } Color;
    Color result;
    Color t0, t1, t2, t3, t4, t5, t6, t7, t8;

    *(u32 *)&result = lbl_80369058;
    switch (arg0[6]) {
    case 0:
        *(u32 *)&t0 = lbl_8036905C;
        result.r = t0.r; result.g = t0.g; result.b = t0.b; result.a = t0.a;
        break;
    case 1:
        *(u32 *)&t1 = lbl_80369060;
        result.r = t1.r; result.g = t1.g; result.b = t1.b; result.a = t1.a;
        break;
    case 2:
        *(u32 *)&t2 = lbl_80369064;
        result.r = t2.r; result.g = t2.g; result.b = t2.b; result.a = t2.a;
        break;
    case 3:
        *(u32 *)&t3 = lbl_80369068;
        result.r = t3.r; result.g = t3.g; result.b = t3.b; result.a = t3.a;
        break;
    case 4:
        *(u32 *)&t4 = lbl_8036906C;
        result.r = t4.r; result.g = t4.g; result.b = t4.b; result.a = t4.a;
        break;
    case 5:
        *(u32 *)&t5 = lbl_80369070;
        result.r = t5.r; result.g = t5.g; result.b = t5.b; result.a = t5.a;
        break;
    case 6:
        *(u32 *)&t6 = lbl_80369074;
        result.r = t6.r; result.g = t6.g; result.b = t6.b; result.a = t6.a;
        break;
    case 7:
        *(u32 *)&t7 = lbl_80369078;
        result.r = t7.r; result.g = t7.g; result.b = t7.b; result.a = t7.a;
        break;
    case 8:
        *(u32 *)&t8 = lbl_8036907C;
        result.r = t8.r; result.g = t8.g; result.b = t8.b; result.a = t8.a;
        break;
    }
    return *(u32 *)&result;
}

s32 GActor_FormatPath(s32 *arg0, s32 arg1) {
    void sprintf(s32, void *, void *, ...);
    extern u8 GActor_str[];

    sprintf(arg1, GActor_str + 0x120, GActor_str + 0x129, *arg0);
    return arg1;
}

void fn_80055B0C(s32 arg0) {
    void fn_800056A0(s32);
    void fn_801451BC(void);
    void fn_801452A8(u8);
    u8 fn_801452C8(u8);
    s32 fn_801452E8(void);

    if (fn_801452C8((u8)arg0) == 0) {
        if (fn_801452E8() >= 0x10) {
            fn_800056A0(0);
            fn_801451BC();
        }
        fn_801452A8((u8)arg0);
    }
}
