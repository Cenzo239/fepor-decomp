/* Functions from 0x801101D0 to 0x80120CC0, found by decomp-toolkit. */
#include "common.h"
#include "actor.h"
static inline void Ui_StoreCursorTile(void *process, s8 x, s8 y) { extern u8 gUiContext[]; void Process_Goto(void *, s32); gUiContext[0xD] = x; gUiContext[0xE] = y; Process_Goto(process, 6); }
static inline u8 Ui_IsTargetTile(s8 x, s8 y)
{
    extern u8 gBattleMap[], gUnits[], gTargetList[];
    void *TargetList_GetAt(void *, s32);
    u8 selected = 0;
    u8 id = gBattleMap[x + (y << 6) + 0xD];
    s32 i;
    u8 *unit;
    u8 *entry;
    if (id) {
        unit = id ? gUnits + (id - 1) * 0x280 : 0;
        if (*(u32 *)(unit + 0x1A0) & 0x20000) return 0;
    }
    for (i = 0; i < *(s32 *)gTargetList; i++) {
        entry = TargetList_GetAt(gTargetList, i);
        if (x == (s8)entry[0] && y == (s8)entry[1]) {
            selected = 1;
            break;
        }
    }
    return selected;
}
static inline u8 Ui_InputLocked(u32 flags) { u8 locked = 0; if ((flags & 0x10) && !(flags & 0x20)) locked = 1; return locked; }


static inline u8 ClearUnitSelections(void *cur)
{
    u8 changed = 0;
    void *next;
    u32 flags;
    while (cur != NULL) {
        flags = *(u32 *)((u8 *)cur + 0x1A0);
        next = *(void **)((u8 *)cur + 0x184);
        if (flags & 0x800) {
            changed = 1;
            *(u32 *)((u8 *)cur + 0x1A0) = flags & ~0x800;
        }
        cur = next;
    }
    return changed;
}
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

void fn_801101D0(void *arg0, s32 arg1) {
    void fn_800E5A4C(void *, s32);
    void fn_801C6978(void *);
    void *tmp = *(void **)((u8 *)arg0 + 0xE0);
    if (tmp != NULL) {
        fn_801C6978(tmp);
    }
    fn_800E5A4C(arg0, arg1);
}

u8 fn_80110220(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x1A7);
}

#pragma cplusplus on
extern "C" void fn_80110228(void *arg0) {
    s32 strlen(char *);
    void *Heap_Alloc(s32);
    s32 String_Compare(void *, s32, void *, char *, s32);
    void String_AssignCStr(void *, char *, u32);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_Init(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void String_JoinCStr(void *, void *, void *);
    void Camera_GetLookAt(void *, void *);
    void fn_800DB67C(void *, void *, s32);
    s32 fn_800DDAA4(void *, void *);
    void fn_800DF670(void *);
    void fn_800E4E7C(void *, void *, char *);
    void fn_800E4FE8(void *, void *, char *);
    s32 fn_800E5200(void *, s32, s32, f32);
    u8 fn_800E5248(void *, s32);
    void UiObj_SetCamerasTransitionDecay(void *, f32);
    void UiObj_SetCamerasTransition(void *, s32, s32, f32);
    void fn_80111740(void *);
    void fn_80151894(void *);
    void *fn_80151D50(void *, void *, void *, void *, void *, void *, s32);
    void *fn_801992F8(void *);
    s32 fn_80199310(void);
    void fn_80203184(void *, void *, void *);
    void fn_802031CC(void *, void *, f32);
    void fn_802031E8(void *, void *);
    extern void *gGame;
    extern f32 lbl_8036A188;
    extern f32 lbl_8036A18C;

    struct V3 {
        f32 x, y, z;
        V3() {}
        V3(f32 _x, f32 _y, f32 _z) { x = _x; y = _y; z = _z; }
    };

    struct Actor {
        u8 pad[0x40];
        virtual void v1() = 0;
        virtual void v0() = 0;
        virtual void v3() = 0;
        virtual void v2() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v10() = 0;
        virtual void v9() = 0;
        virtual void Color(f32, f32, f32) = 0;
        virtual V3 GetPos(s32) = 0;
    };

    struct Manager {
        u8 pad[0x10];
        virtual void v2() = 0;
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void Add(void *) = 0;
    };

    typedef struct {
        s32 x, y, z;
    } Word3;

    typedef void (*GetPosFn)(V3 *, void *, s32);

    V3 sp384;
    V3 sp378;
    V3 sp360;
    V3 sp348;
    V3 sp324;
    V3 sp318;
    V3 sp2DC;
    V3 sp2D0;
    Word3 w300;
    Word3 w2B8;
    String str2E8;
    String str2A0;
    String str294;
    String str288;
    String str27C;
    String str270;
    String str264;
    String str258;
    String str24C;
    String str240;
    Word3 copyB1;
    Word3 tmpVec1;
    Word3 copyA1;
    V3 got1;
    Word3 pos1;
    String str1F8;
    Word3 copyB2;
    Word3 tmpVec2;
    Word3 copyA2;
    V3 got2;
    Word3 pos2;
    String str1B0;
    Word3 copyB3;
    Word3 tmpVec3;
    Word3 copyA3;
    V3 got3;
    Word3 pos3;
    String str168;
    Word3 copyB4;
    Word3 tmpVec4;
    Word3 copyA4;
    V3 got4;
    Word3 pos4;
    V3 sp114;
    V3 sp120;
    V3 spFC;
    V3 sp108;
    V3 spE4;
    V3 spF0;
    V3 spCC;
    V3 spD8;
    V3 spB4;
    V3 spC0;
    V3 sp90;
    V3 spA8;
    V3 sp9C;
    V3 sp78;
    V3 sp84;
    V3 sp54;
    V3 sp6C;
    V3 sp60;
    V3 sp3C;
    V3 sp48;
    V3 sp24;
    V3 sp30;
    void *scratch;
    void *scratch2;
    void *scratch3;
    void *scratch4;
    void *scratch5;
    void *scratch6;
    void *self;
    s32 n;
    s8 flag;
    void *obj;
    void *other;
    f32 a0, a1, a2;
    f32 z;
    f32 temp_f;
    s32 t;
    void *tmp;

    self = arg0;
    sp384.z = lbl_8036A184;
    sp384.y = lbl_8036A184;
    sp384.x = lbl_8036A184;
    sp378.z = lbl_8036A184;
    sp378.y = lbl_8036A184;
    sp378.x = lbl_8036A184;

    if ((u8)fn_800E5248(self, 9) != 0) {
        UiObj_SetCamerasTransition(*(void **)((u8 *)self + 0xAC), 0, 0x3C, *(f32 *)((u8 *)gGame + 0x98));
    }
    if ((u8)fn_800E5248(self, 0xA) != 0) {
        UiObj_SetCamerasTransition(*(void **)((u8 *)self + 0xAC), 0, 0x3C, *(f32 *)((u8 *)gGame + 0x9C));
    }
    if ((u8)fn_800E5248(self, 0xB) != 0) {
        UiObj_SetCamerasTransition(*(void **)((u8 *)self + 0xAC), 0, 0x3C, *(f32 *)((u8 *)gGame + 0xA0));
    }
    if ((u8)fn_800E5248(self, 0x1E) != 0) {
        UiObj_SetCamerasTransition(*(void **)((u8 *)self + 0xAC), 0, -1, *(f32 *)((u8 *)gGame + 0x98));
    }
    if ((u8)fn_800E5248(self, 0x1F) != 0) {
        UiObj_SetCamerasTransition(*(void **)((u8 *)self + 0xAC), 0, -1, *(f32 *)((u8 *)gGame + 0x9C));
    }
    if ((u8)fn_800E5248(self, 0x20) != 0) {
        UiObj_SetCamerasTransition(*(void **)((u8 *)self + 0xAC), 0, -1, *(f32 *)((u8 *)gGame + 0xA0));
    }
    if ((u8)fn_800E5248(self, 0x21) != 0) {
        UiObj_SetCamerasTransitionDecay(*(void **)((u8 *)self + 0xAC), *(f32 *)((u8 *)gGame + 0x98));
    }

    if ((u8)fn_800E5248(self, 0x2B) != 0) {
        str294.size = 0;
        str294.cap = 0;
        str294.data = 0;
        str294.cap = 0;
        switch (*(s32 *)((u8 *)self + 0x1CC)) {
        case 1:
            String_AssignCStr(&str294, (char *)gActorXmlStrs + 0x1D, strlen((char *)gActorXmlStrs + 0x1D));
            break;
        case 2:
            String_AssignCStr(&str294, (char *)gActorXmlStrs + 0x2D, strlen((char *)gActorXmlStrs + 0x2D));
            break;
        case 3:
            String_AssignCStr(&str294, (char *)gActorXmlStrs + 0x3E, strlen((char *)gActorXmlStrs + 0x3E));
            break;
        default:
            String_Destroy(&str294, -1);
            goto after_2b;
        }
        *(f32 *)&pos1.z = lbl_8036A184;
        *(f32 *)&pos1.y = lbl_8036A184;
        *(f32 *)&pos1.x = lbl_8036A184;
        if (String_Compare(&str294, 0, (void *)str294.size, (char *)gActorXmlStrs + 0x4E, strlen((char *)gActorXmlStrs + 0x4E)) != 0) {
            got1 = ((Actor *)self)->GetPos(0);
            flag = 0;
            *(f32 *)&pos1.y = got1.y;
            *(f32 *)&pos1.x = got1.x;
            *(f32 *)&pos1.z = got1.z;
            *(f32 *)&pos1.y = lbl_8036A184;
            obj = Heap_Alloc(0xC8);
            if (obj != NULL) {
                Camera_GetLookAt(&tmpVec1, self);
                copyA1 = tmpVec1;
                copyB1 = pos1;
                String_Init(&str240, (char *)gActorXmlStrs + 0x51, &scratch);
                flag = 1;
                obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str240, &str294, &copyB1, &copyA1, 0);
            }
            if (flag) {
                String_Destroy(&str240, -1);
            }
            ((Actor *)obj)->Color(
                *(f32 *)((u8 *)gGame + 0x104),
                *(f32 *)((u8 *)gGame + 0x108),
                *(f32 *)((u8 *)gGame + 0x10C));
            fn_80151894(obj);
            (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
        }
        String_Destroy(&str294, -1);
    }
after_2b:

    if ((u8)fn_800E5248(self, 0x2C) != 0) {
        str288.size = 0;
        str288.cap = 0;
        str288.data = 0;
        str288.cap = 0;
        switch (*(s32 *)((u8 *)self + 0x1CC)) {
        case 1:
            String_AssignCStr(&str288, (char *)gActorXmlStrs + 0x55, strlen((char *)gActorXmlStrs + 0x55));
            break;
        case 2:
            String_AssignCStr(&str288, (char *)gActorXmlStrs + 0x66, strlen((char *)gActorXmlStrs + 0x66));
            break;
        case 3:
            String_AssignCStr(&str288, (char *)gActorXmlStrs + 0x77, strlen((char *)gActorXmlStrs + 0x77));
            break;
        default:
            String_Destroy(&str288, -1);
            goto after_2c;
        }
        *(f32 *)&pos2.z = lbl_8036A184;
        *(f32 *)&pos2.y = lbl_8036A184;
        *(f32 *)&pos2.x = lbl_8036A184;
        if (String_Compare(&str288, 0, (void *)str288.size, (char *)gActorXmlStrs + 0x4E, strlen((char *)gActorXmlStrs + 0x4E)) != 0) {
            got2 = ((Actor *)self)->GetPos(0);
            flag = 0;
            *(f32 *)&pos2.y = got2.y;
            *(f32 *)&pos2.x = got2.x;
            *(f32 *)&pos2.z = got2.z;
            *(f32 *)&pos2.y = lbl_8036A184;
            obj = Heap_Alloc(0xC8);
            if (obj != NULL) {
                Camera_GetLookAt(&tmpVec2, self);
                copyA2 = tmpVec2;
                copyB2 = pos2;
                String_Init(&str1F8, (char *)gActorXmlStrs + 0x51, &scratch2);
                flag = 1;
                obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str1F8, &str288, &copyB2, &copyA2, 0);
            }
            if (flag) {
                String_Destroy(&str1F8, -1);
            }
            ((Actor *)obj)->Color(
                *(f32 *)((u8 *)gGame + 0x104),
                *(f32 *)((u8 *)gGame + 0x108),
                *(f32 *)((u8 *)gGame + 0x10C));
            fn_80151894(obj);
            (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
        }
        String_Destroy(&str288, -1);
    }
after_2c:

    if ((u8)fn_800E5248(self, 0x2D) != 0) {
        fn_80111740(self);
    }

    if ((u8)fn_800E5248(self, 0x2E) != 0) {
        str27C.size = 0;
        str27C.cap = 0;
        str27C.data = 0;
        str27C.cap = 0;
        switch (*(s32 *)((u8 *)self + 0x1CC)) {
        case 1:
            String_AssignCStr(&str27C, (char *)gActorXmlStrs + 0x88, strlen((char *)gActorXmlStrs + 0x88));
            break;
        case 2:
            String_AssignCStr(&str27C, (char *)gActorXmlStrs + 0x99, strlen((char *)gActorXmlStrs + 0x99));
            break;
        case 3:
            String_AssignCStr(&str27C, (char *)gActorXmlStrs + 0xAA, strlen((char *)gActorXmlStrs + 0xAA));
            break;
        default:
            String_Destroy(&str27C, -1);
            goto after_2e;
        }
        *(f32 *)&pos3.z = lbl_8036A184;
        *(f32 *)&pos3.y = lbl_8036A184;
        *(f32 *)&pos3.x = lbl_8036A184;
        if (String_Compare(&str27C, 0, (void *)str27C.size, (char *)gActorXmlStrs + 0x4E, strlen((char *)gActorXmlStrs + 0x4E)) != 0) {
            got3 = ((Actor *)self)->GetPos(0);
            flag = 0;
            *(f32 *)&pos3.y = got3.y;
            *(f32 *)&pos3.x = got3.x;
            *(f32 *)&pos3.z = got3.z;
            *(f32 *)&pos3.y = lbl_8036A184;
            obj = Heap_Alloc(0xC8);
            if (obj != NULL) {
                Camera_GetLookAt(&tmpVec3, self);
                copyA3 = tmpVec3;
                copyB3 = pos3;
                String_Init(&str1B0, (char *)gActorXmlStrs + 0x51, &scratch3);
                flag = 1;
                obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str1B0, &str27C, &copyB3, &copyA3, 0);
            }
            if (flag) {
                String_Destroy(&str1B0, -1);
            }
            ((Actor *)obj)->Color(
                *(f32 *)((u8 *)gGame + 0x104),
                *(f32 *)((u8 *)gGame + 0x108),
                *(f32 *)((u8 *)gGame + 0x10C));
            fn_80151894(obj);
            (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
        }
        String_Destroy(&str27C, -1);
    }
after_2e:

    if ((u8)fn_800E5248(self, 0x3C) != 0) {
        str270.size = 0;
        str270.cap = 0;
        str270.data = 0;
        str270.cap = 0;
        switch (*(s32 *)((u8 *)self + 0x1CC)) {
        case 1:
            String_AssignCStr(&str270, (char *)gActorXmlStrs + 0xBB, strlen((char *)gActorXmlStrs + 0xBB));
            break;
        case 2:
            String_AssignCStr(&str270, (char *)gActorXmlStrs + 0xCC, strlen((char *)gActorXmlStrs + 0xCC));
            break;
        case 3:
            String_AssignCStr(&str270, (char *)gActorXmlStrs + 0xDD, strlen((char *)gActorXmlStrs + 0xDD));
            break;
        default:
            String_Destroy(&str270, -1);
            goto after_3c;
        }
        *(f32 *)&pos4.z = lbl_8036A184;
        *(f32 *)&pos4.y = lbl_8036A184;
        *(f32 *)&pos4.x = lbl_8036A184;
        if (String_Compare(&str270, 0, (void *)str270.size, (char *)gActorXmlStrs + 0x4E, strlen((char *)gActorXmlStrs + 0x4E)) != 0) {
            got4 = ((Actor *)self)->GetPos(0);
            flag = 0;
            *(f32 *)&pos4.y = got4.y;
            *(f32 *)&pos4.x = got4.x;
            *(f32 *)&pos4.z = got4.z;
            *(f32 *)&pos4.y = lbl_8036A184;
            obj = Heap_Alloc(0xC8);
            if (obj != NULL) {
                Camera_GetLookAt(&tmpVec4, self);
                copyA4 = tmpVec4;
                copyB4 = pos4;
                String_Init(&str168, (char *)gActorXmlStrs + 0x51, &scratch4);
                flag = 1;
                obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str168, &str270, &copyB4, &copyA4, 0);
            }
            if (flag) {
                String_Destroy(&str168, -1);
            }
            ((Actor *)obj)->Color(
                *(f32 *)((u8 *)gGame + 0x104),
                *(f32 *)((u8 *)gGame + 0x108),
                *(f32 *)((u8 *)gGame + 0x10C));
            fn_80151894(obj);
            (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
        }
        String_Destroy(&str270, -1);
    }
after_3c:

    if ((u8)fn_800E5248(self, 0xC) != 0 && *(s32 *)((u8 *)self + 0x1B8) == 1) {
        if (*(s32 *)((u8 *)self + 0x19C) != 0) {
            if (*(void **)((u8 *)self + 0x118) == NULL) {
                a0 = *(f32 *)((u8 *)self + 0x48);
                a2 = *(f32 *)((u8 *)self + 0x50);
            } else {
                ((GetPosFn)((void **)*(void **)((u8 *)self + 0x40))[0xE])(&sp114, self, 0);
                other = *(void **)((u8 *)self + 0x118);
                ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&sp120, other, 0);
                z = lbl_8036A184;
                spFC.y = z;
                spFC.x = sp120.x - (sp114.x - *(f32 *)((u8 *)self + 0x48));
                spFC.z = z;
                sp108.y = z;
                sp108.z = z;
                sp108.x = -*(f32 *)((u8 *)self + 0x60);
                fn_802031CC(&sp108, &sp108, *(f32 *)((u8 *)self + 0x128) * lbl_8036A188);
                fn_80203184(&spFC, &sp108, &spFC);
                a0 = spFC.x;
                a2 = lbl_8036A184;
            }
            sp384.x = a0;
            sp384.y = lbl_8036A184;
            sp384.z = a2;
        } else {
            if (*(void **)((u8 *)self + 0x118) == NULL) {
                a0 = *(f32 *)((u8 *)self + 0x48);
                a2 = *(f32 *)((u8 *)self + 0x50);
            } else {
                ((GetPosFn)((void **)*(void **)((u8 *)self + 0x40))[0xE])(&spE4, self, 0);
                other = *(void **)((u8 *)self + 0x118);
                ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&spF0, other, 0);
                z = lbl_8036A184;
                spCC.y = z;
                spCC.x = spF0.x - (spE4.x - *(f32 *)((u8 *)self + 0x48));
                spCC.z = z;
                spD8.y = z;
                spD8.z = z;
                spD8.x = -*(f32 *)((u8 *)self + 0x60);
                fn_802031CC(&spD8, &spD8, *(f32 *)((u8 *)self + 0x128) * lbl_8036A18C);
                fn_80203184(&spCC, &spD8, &spCC);
                a0 = spCC.x;
                a2 = lbl_8036A184;
            }
            sp384.x = a0;
            sp384.y = lbl_8036A184;
            sp384.z = a2;
        }
        *(u8 *)((u8 *)self + 0x195) = 0;
        *(u8 *)((u8 *)self + 0x194) = 1;
        got1 = sp384;
        fn_800DB67C(self, &got1, fn_800E5200(self, 0xD, *(s32 *)((u8 *)self + 0xCC), sp384.x) - *(s32 *)((u8 *)self + 0xCC));
        *(s32 *)((u8 *)self + 0x1A8) = 0;
    }

    if ((u8)fn_800E5248(self, 5) != 0 && *(s32 *)((u8 *)self + 0x1B8) == 1) {
        other = *(void **)((u8 *)self + 0x118);
        if (other != NULL) {
            temp_f = *(f32 *)((u8 *)gGame + 0x100);
            ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&spB4, other, 0);
            tmp = *(void **)((u8 *)other + 0x118);
            ((GetPosFn)((void **)*(void **)((u8 *)tmp + 0x40))[0xE])(&spC0, tmp, 0);
            sp90.x = spB4.x;
            sp90.y = lbl_8036A184;
            sp90.z = lbl_8036A184;
            spA8.y = lbl_8036A184;
            spA8.z = lbl_8036A184;
            spA8.x = -*(f32 *)((u8 *)other + 0x60);
            fn_802031E8(&spA8, &spA8);
            fn_802031CC(&spA8, &spA8, temp_f);
            fn_80203184(&sp90, &spA8, &sp9C);
            sp384.y = lbl_8036A184;
            sp384.x = sp9C.x;
            sp384.z = lbl_8036A184;
        } else {
            got1 = ((Actor *)self)->GetPos(0);
            sp384 = got1;
        }
        *(u8 *)((u8 *)self + 0x195) = 0;
        got1 = sp384;
        fn_800DB67C(self, &got1, fn_800E5200(self, 0xD, *(s32 *)((u8 *)self + 0xCC), sp384.x) - *(s32 *)((u8 *)self + 0xCC));
        fn_80111740(self);
        *(s32 *)((u8 *)self + 0x1A8) = 0;
    }

    if ((u8)fn_800E5248(self, *(s32 *)((u8 *)gGame + 0x16C)) != 0) {
        other = *(void **)((u8 *)self + 0x118);
        if (other != NULL) {
            temp_f = *(f32 *)((u8 *)gGame + 0x17C);
            ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&sp78, other, 0);
            tmp = *(void **)((u8 *)other + 0x118);
            ((GetPosFn)((void **)*(void **)((u8 *)tmp + 0x40))[0xE])(&sp84, tmp, 0);
            sp54.x = sp78.x;
            sp54.y = lbl_8036A184;
            sp54.z = lbl_8036A184;
            sp6C.y = lbl_8036A184;
            sp6C.z = lbl_8036A184;
            sp6C.x = -*(f32 *)((u8 *)other + 0x60);
            fn_802031E8(&sp6C, &sp6C);
            fn_802031CC(&sp6C, &sp6C, temp_f);
            fn_80203184(&sp54, &sp6C, &sp60);
            sp384.y = lbl_8036A184;
            sp384.x = sp60.x;
            sp384.z = lbl_8036A184;
        } else {
            got1 = ((Actor *)self)->GetPos(0);
            sp384 = got1;
        }
        *(u8 *)((u8 *)self + 0x195) = 0;
        got1 = sp384;
        fn_800DB67C(self, &got1, fn_800E5200(self, *(s32 *)((u8 *)gGame + 0x170), *(s32 *)((u8 *)self + 0xCC), sp384.x) - *(s32 *)((u8 *)self + 0xCC));
        fn_80111740(self);
        *(s32 *)((u8 *)self + 0x1A8) = 0;
    }

    if ((u8)fn_800E5248(self, *(s32 *)((u8 *)gGame + 0x174)) != 0) {
        if (*(void **)((u8 *)self + 0x118) == NULL) {
            a0 = *(f32 *)((u8 *)self + 0x48);
            a2 = *(f32 *)((u8 *)self + 0x50);
        } else {
            ((GetPosFn)((void **)*(void **)((u8 *)self + 0x40))[0xE])(&sp3C, self, 0);
            other = *(void **)((u8 *)self + 0x118);
            ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&sp48, other, 0);
            z = lbl_8036A184;
            sp24.y = z;
            sp24.x = sp48.x - (sp3C.x - *(f32 *)((u8 *)self + 0x48));
            sp24.z = z;
            sp30.y = z;
            sp30.z = z;
            sp30.x = -*(f32 *)((u8 *)self + 0x60);
            fn_802031CC(&sp30, &sp30, *(f32 *)((u8 *)self + 0x128) * lbl_8036A18C);
            fn_80203184(&sp24, &sp30, &sp24);
            a0 = sp24.x;
            a2 = lbl_8036A184;
        }
        sp384.x = a0;
        sp384.y = lbl_8036A184;
        *(u8 *)((u8 *)self + 0x195) = 0;
        sp384.z = a2;
        got1 = sp384;
        fn_800DB67C(self, &got1, fn_800E5200(self, *(s32 *)((u8 *)gGame + 0x178), *(s32 *)((u8 *)self + 0xCC), sp384.x) - *(s32 *)((u8 *)self + 0xCC));
        fn_80111740(self);
        *(s32 *)((u8 *)self + 0x1A8) = 0;
    }

    if ((u8)fn_800E5248(self, 0xE) != 0) {
        if (*(void **)((u8 *)self + 0x11C) != NULL) {
            t = fn_80199310();
            fn_800DF670(*(void **)((u8 *)self + 0x11C));
            if (t == 3) {
                fn_800E4FE8(*(void **)((u8 *)self + 0x11C), self, (char *)gActorXmlStrs + 0xEE);
            } else {
                fn_800E4FE8(*(void **)((u8 *)self + 0x11C), self, (char *)gActorXmlStrs + 0xF5);
            }
            String_Init(&str24C, (char *)gActorXmlStrs + 0xFC, &scratch5);
            String_JoinCStr(&str258, fn_801992F8(*(void **)((u8 *)self + 0x11C)), &str24C);
            String_Assign((u8 *)self + 0x154, &str258, 0, -1);
            String_Destroy(&str258, -1);
            String_Destroy(&str24C, -1);
        }
        String_ConcatCStr(&str264, (u8 *)self + 0x154, (char *)gActorXmlStrs + 0xFE);
        t = fn_800DDAA4(*(void **)((u8 *)self + 0xDC), &str264) == 0 ? 1 : 0;
        String_Destroy(&str264, -1);
        if ((u8)t != 0) {
            *(u8 *)((u8 *)self + 0x1A4) = 1;
        }
    }

    if ((u8)fn_800E5248(self, 3) != 0) {
        *(s32 *)((u8 *)self + 0x1B4) = 1;
    }

    if (*(s32 *)((u8 *)gGame + 0x194) != 0 && (u8)fn_800E5248(self, 3) != 0) {
        tmp = *(void **)((u8 *)self + 0x11C);
        if (tmp != NULL) {
            if (*(u32 *)((u8 *)self + 0x120) != 0) {
                fn_800E4E7C(&sp324, self, (char *)gActorXmlStrs + 0x103);
                sp378 = sp324;
            } else {
                fn_800E4E7C(&sp318, tmp, (char *)gActorXmlStrs + 0x103);
                sp378 = sp318;
            }
            flag = 0;
            obj = Heap_Alloc(0xC8);
            if (obj != NULL) {
                Camera_GetLookAt(&w300, self);
                copyA1 = w300;
                *(f32 *)&copyB1.x = sp378.x;
                *(f32 *)&copyB1.y = sp378.y;
                *(f32 *)&copyB1.z = sp378.z;
                String_Init(&str2E8, (char *)gActorXmlStrs + 0x51, &scratch6);
                flag = 1;
                obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str2E8, (u8 *)gGame + 0x19C, &copyB1, &copyA1, 0);
            }
            (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
            if (flag) {
                String_Destroy(&str2E8, -1);
            }
        }
    }

    if (*(s32 *)((u8 *)gGame + 0x198) != 0 && (u8)fn_800E5248(self, 3) != 0) {
        tmp = *(void **)((u8 *)self + 0x11C);
        if (tmp != NULL) {
            if (*(u32 *)((u8 *)self + 0x120) != 0) {
                fn_800E4E7C(&sp2DC, self, (char *)gActorXmlStrs + 0x103);
                sp378 = sp2DC;
            } else {
                fn_800E4E7C(&sp2D0, tmp, (char *)gActorXmlStrs + 0x103);
                sp378 = sp2D0;
            }
            flag = 0;
            obj = Heap_Alloc(0xC8);
            if (obj != NULL) {
                Camera_GetLookAt(&w2B8, self);
                copyA2 = w2B8;
                *(f32 *)&copyB2.x = sp378.x;
                *(f32 *)&copyB2.y = sp378.y;
                *(f32 *)&copyB2.z = sp378.z;
                String_Init(&str2A0, (char *)gActorXmlStrs + 0x51, &scratch);
                flag = 1;
                obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str2A0, (u8 *)gGame + 0x1A8, &copyB2, &copyA2, 0);
            }
            (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
            if (flag) {
                String_Destroy(&str2A0, -1);
            }
        }
    }
}
#pragma cplusplus reset

#pragma cplusplus on
#pragma push
#pragma optimization_level 4
extern "C" void fn_80111740(void *self) {
    s32 strlen(char *);
    void *Heap_Alloc(s32);
    s32 String_Compare(void *, s32, void *, char *, s32);
    void String_Destroy(void *, s32);
    void String_Init(void *, char *, void *);
    void Camera_GetLookAt(void *, void *);
    void fn_80151894(void *);
    void *fn_80151D50(void *, void *, void *, void *, void *, void *, s32);
    void fn_800DBB74(void *, void *);
    extern void *gGame;

    struct V3 {
        f32 x, y, z;
    };

    struct Actor {
        u8 pad[0x40];
        virtual void v1() = 0;
        virtual void v0() = 0;
        virtual void v3() = 0;
        virtual void v2() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v10() = 0;
        virtual void v9() = 0;
        virtual void Color(f32, f32, f32) = 0;
        virtual V3 GetPos(s32) = 0;
    };

    struct Manager {
        u8 pad[0x10];
        virtual void v2() = 0;
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void Add(void *) = 0;
    };

    typedef struct {
        s32 x, y, z;
    } Word3;

    typedef void (*GetPosFn)(V3 *, void *, s32);

    String sp54;
    String sp48;
    Word3 copyB;
    Word3 tmpVec;
    Word3 copyA;
    V3 got;
    Word3 pos;
    void *scratch;
    void *obj;
    s8 flag;
    s32 n;

    sp54.size = 0;
    sp54.cap = 0;
    sp54.data = 0;
    sp54.cap = 0;

    if ((n = strlen((char *)((u8 *)gActorXmlStrs + 0x109)), String_Compare((void *)((u8 *)self + 0xB0), 0, (void *)*(u32 *)((u8 *)self + 0xB0), (char *)((u32)gActorXmlStrs + 0x109), n) == 0) ||
        (n = strlen((char *)((u8 *)gActorXmlStrs + 0x10E)), String_Compare((void *)((u8 *)self + 0xB0), 0, (void *)*(u32 *)((u8 *)self + 0xB0), (char *)((u32)gActorXmlStrs + 0x10E), n) == 0) ||
        (n = strlen((char *)((u8 *)gActorXmlStrs + 0x113)), String_Compare((void *)((u8 *)self + 0xB0), 0, (void *)*(u32 *)((u8 *)self + 0xB0), (char *)((u32)gActorXmlStrs + 0x113), n) == 0) ||
        (n = strlen((char *)((u8 *)gActorXmlStrs + 0x118)), String_Compare((void *)((u8 *)self + 0xB0), 0, (void *)*(u32 *)((u8 *)self + 0xB0), (char *)((u32)gActorXmlStrs + 0x118), n) == 0) ||
        (n = strlen((char *)((u8 *)gActorXmlStrs + 0x11D)), String_Compare((void *)((u8 *)self + 0xB0), 0, (void *)*(u32 *)((u8 *)self + 0xB0), (char *)((u32)gActorXmlStrs + 0x11D), n) == 0)) {
        String_Destroy(&sp54, -1);
        return;
    }

    switch (*(s32 *)((u8 *)self + 0x1CC)) {
    case 1:
        String_AssignCStr(&sp54, (char *)((u32)gActorXmlStrs + 0x122), strlen((char *)gActorXmlStrs + 0x122));
        break;
    case 2:
        String_AssignCStr(&sp54, (char *)((u32)gActorXmlStrs + 0x133), strlen((char *)gActorXmlStrs + 0x133));
        break;
    case 3:
        String_AssignCStr(&sp54, (char *)((u32)gActorXmlStrs + 0x144), strlen((char *)gActorXmlStrs + 0x144));
        break;
    default:
        String_Destroy(&sp54, -1);
        return;
    }

    *(f32 *)&pos.z = lbl_8036A184;
    *(f32 *)&pos.y = lbl_8036A184;
    *(f32 *)&pos.x = lbl_8036A184;
    n = strlen((char *)gActorXmlStrs + 0x4E);
    if (String_Compare(&sp54, 0, (void *)sp54.size, (char *)gActorXmlStrs + 0x4E, n) != 0) {
        ((GetPosFn)((void **)*(void **)((u8 *)self + 0x40))[0xE])(&got, self, 0);
        flag = 0;
        *(f32 *)&pos.y = got.y;
        *(f32 *)&pos.x = got.x;
        *(f32 *)&pos.z = got.z;
        *(f32 *)&pos.y = lbl_8036A184;
        if ((obj = Heap_Alloc(0xC8)) != 0) {
            Camera_GetLookAt(&tmpVec, self);
            copyA = tmpVec;
            copyB = pos;
            String_Init(&sp48, (char *)gActorXmlStrs + 0x51, &scratch);
            flag = 1;
            obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &sp48, &sp54, &copyB, &copyA, 0);
        }
        if (flag) {
            String_Destroy(&sp48, -1);
        }
        ((Actor *)obj)->Color(
            *(f32 *)((u8 *)gGame + 0x104),
            *(f32 *)((u8 *)gGame + 0x108),
            *(f32 *)((u8 *)gGame + 0x10C));
        fn_80151894(obj);
        (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
    }
    String_Destroy(&sp54, -1);
}
#pragma pop
#pragma use_lmw_stmw on
#pragma optimization_level 3
#pragma cplusplus on
extern "C" void fn_80111AE8(void *self, String *name, u8 doSomething) {
    s32 strlen(char *);
    void *Heap_Alloc(s32);
    s32 String_Compare(void *, s32, void *, char *, s32);
    void String_Destroy(void *, s32);
    void String_Init(void *, char *, void *);
    void Camera_GetLookAt(void *, void *);
    void fn_80151894(void *);
    void *fn_80151D50(void *, void *, void *, void *, void *, void *, s32);
    extern void *gGame;

    struct V3 {
        f32 x, y, z;
    };

    struct Actor {
        u8 pad[0x40];
        virtual void v1() = 0;
        virtual void v0() = 0;
        virtual void v3() = 0;
        virtual void v2() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v10() = 0;
        virtual void v9() = 0;
        virtual void Color(f32, f32, f32) = 0;
        virtual V3 GetPos(s32) = 0;
    };

    struct Manager {
        u8 pad[0x10];
        virtual void v2() = 0;
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void Add(void *) = 0;
    };

    typedef struct {
        s32 x, y, z;
    } Word3;

    typedef void (*GetPosFn)(V3 *, void *, s32);

    Word3 pos;
    V3 got;
    Word3 copyA;
    Word3 tmpVec;
    Word3 copyB;
    String str;
    void *scratch;
    void *obj;
    s8 flag;
    s32 n;

    *(f32 *)&pos.z = 0.0f;
    *(f32 *)&pos.y = 0.0f;
    *(f32 *)&pos.x = 0.0f;
    n = strlen((char *)gActorXmlStrs + 0x4E);
    if (String_Compare(name, 0, (void *)name->size, (char *)gActorXmlStrs + 0x4E, n) != 0) {
        ((GetPosFn)((void **)*(void **)((u8 *)self + 0x40))[0xE])(&got, self, 0);
        flag = 0;
        *(f32 *)&pos.y = got.y;
        *(f32 *)&pos.x = got.x;
        *(f32 *)&pos.z = got.z;
        *(f32 *)&pos.y = 0.0f;
        if ((obj = Heap_Alloc(0xC8)) != 0) {
            Camera_GetLookAt(&tmpVec, self);
            copyA = tmpVec;
            copyB = pos;
            String_Init(&str, (char *)gActorXmlStrs + 0x51, &scratch);
            flag = 1;
            obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str, name, &copyB, &copyA, 0);
        }
        if (flag) {
            String_Destroy(&str, -1);
        }
        ((Actor *)obj)->Color(
            *(f32 *)((u8 *)gGame + 0x104),
            *(f32 *)((u8 *)gGame + 0x108),
            *(f32 *)((u8 *)gGame + 0x10C));
        if (doSomething) {
            fn_80151894(obj);
        }
        (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
    }
}

#pragma use_lmw_stmw on
#pragma opt_common_subs off
extern "C" void fn_80111C8C(void *arg0, void *arg1) {
    s32 strlen(char *);
    s32 String_Compare(void *, s32, s32, char *, s32);
    void SeCue_PlayAt(char *, u8, f32, f32, f32);
    void UiObj_SetCamerasTransition(void *, s32, s32, f32);
    s8 *fn_80117CC0(void *, s32);
    extern void *gGame;
    struct NameStr {
        s32 len;
    };
    s32 vol;
    u8 flagA;
    u8 flagB;
    s32 n;
    #define CMPAT(off) (n = strlen((char *)((u8 *)gActorXmlStrs + (off))), String_Compare((void *)((u8 *)arg0 + 0xB0), 0, ((struct NameStr *)((u8 *)arg0 + 0xB0))->len, (char *)((u8 *)gActorXmlStrs + (off)), n) == 0)
    #define PLAY(off) SeCue_PlayAt((char *)((u8 *)gActorXmlStrs + (off)), vol, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2])
    flagA = 0;
    flagB = 0;
    vol = 0x50;
    if (*(s32 *)((u8 *)arg0 + 0x1D0) == 0) vol = 0x64;
    if (CMPAT(0x155) || CMPAT(0x15A) || CMPAT(0x15F)) {
        PLAY(0x164);
        flagA = 1;
    } else if (CMPAT(0x178) || CMPAT(0x17D) || CMPAT(0x182) || CMPAT(0x187)) {
        PLAY(0x18C);
        flagA = 1;
    } else if (CMPAT(0x1A0) || CMPAT(0x1A5) || CMPAT(0x1AA)) {
        PLAY(0x1AF);
        flagB = 1;
    } else if (CMPAT(0x1C3) || CMPAT(0x1C8)) {
        PLAY(0x1CD);
        flagB = 1;
    } else if (CMPAT(0x1E1) || CMPAT(0x1E6) || CMPAT(0x1EB)) {
        PLAY(0x1F0);
    } else if (CMPAT(0x205)) {
        PLAY(0x20A);
    } else if (CMPAT(0x109) || CMPAT(0x10E) || CMPAT(0x113) || CMPAT(0x118) || CMPAT(0x11D)) {
        PLAY(0x21E);
        UiObj_SetCamerasTransition(*(void **)((u8 *)arg0 + 0xAC), 1, 0x3C, *(f32 *)((u8 *)gGame + 0x94));
    } else if (CMPAT(0x232) || CMPAT(0x237) || CMPAT(0x23C) || CMPAT(0x241) || CMPAT(0x246) || (*fn_80117CC0((u8 *)arg0 + 0xB0, 2) == 0x66)) {
        PLAY(0x24B);
    } else if (CMPAT(0x25F) || CMPAT(0x264) || CMPAT(0x269) || CMPAT(0x26E) || CMPAT(0x273) || CMPAT(0x278)) {
        PLAY(0x27D);
    } else {
        PLAY(0x20A);
    }
    switch (*(s32 *)((u8 *)arg0 + 0x1D0)) {
    case 1:
        if (flagA || flagB) SeCue_PlayAt((char *)((u8 *)gActorXmlStrs + 0x291), 0x64, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2]);
        else SeCue_PlayAt((char *)((u8 *)gActorXmlStrs + 0x2A4), 0x64, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2]);
        break;
    case 2:
        if (flagA || flagB) SeCue_PlayAt((char *)((u8 *)gActorXmlStrs + 0x2B7), 0x64, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2]);
        else SeCue_PlayAt((char *)((u8 *)gActorXmlStrs + 0x2CB), 0x64, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2]);
        break;
    case 3:
        if (flagA || flagB) SeCue_PlayAt((char *)((u8 *)gActorXmlStrs + 0x2DF), 0x64, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2]);
        else SeCue_PlayAt((char *)((u8 *)gActorXmlStrs + 0x2F2), 0x64, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2]);
        break;
    }
}

#pragma cplusplus reset
#pragma optimization_level reset
#pragma use_lmw_stmw reset
#pragma opt_common_subs off

extern "C" void fn_801126A4(void *arg0, s32 arg1, s32 arg2) {
 void Prim2D_Begin(void); void Prim2D_SetTransform(f32,f32,f32,f32); void Prim2D_SetTex(s32,s32); void Prim2D_PrepareTex(void);
 void Prim2D_AddPrim(s32); void Prim2D_SetPos(f32,f32); void Prim2D_SetText(void *); void Prim2D_SetScale(f32); void Prim2D_SetTint(s32,s32,s32,s32); void Prim2D_EndPrim(void);
 void *fn_800DDB94(void *,void *); int sprintf(char *,const char *,...);
 extern f32 lbl_8036A18C,lbl_8036A190;
 char buf[128];
 s32 y=arg2; s32 x=arg1; u8 *self=(u8 *)arg0;
 Prim2D_Begin(); Prim2D_SetTransform(0.0f,0.0f,0.0f,lbl_8036A18C);
 Prim2D_SetTex(0,19); Prim2D_PrepareTex();
 sprintf(buf,(char *)gActorXmlStrs+0x38b,String_CStr(self+0xbc));
 Prim2D_AddPrim(5); Prim2D_SetPos((f32)x,(f32)y); Prim2D_SetText(buf); Prim2D_SetScale(lbl_8036A190); Prim2D_SetTint(255,255,255,255); Prim2D_EndPrim();
 sprintf(buf,(char *)gActorXmlStrs+0x38b,fn_800DDB94(*(void **)(self+0xdc),self+0xbc));
 Prim2D_AddPrim(5); Prim2D_SetPos((f32)x,(f32)(y+16)); Prim2D_SetText(buf); Prim2D_SetScale(lbl_8036A190); Prim2D_SetTint(255,255,255,255); Prim2D_EndPrim();
}

#pragma opt_common_subs reset
#pragma cplusplus reset
#pragma use_lmw_stmw on
#pragma global_optimizer off
/* Parse actor XML at path into self: string-map entries, scalars, then apply defaults. */
void Actor_LoadXml(void *arg0, void *arg1) {
    void *Heap_Alloc(s32);
    void Xml_GetChildName(String *, void *);
    void Xml_GetChildValue(char *, void *);
    void Xml_GetNamedValue(void *, void *, String *);
    void Xml_AdvanceChild(void *);
    void Xml_Destroy(void *, s32);
    void *Xml_ParseFile(void *, void *, String *);
    void String_AssignCStr(String *, char *, u32);
    void String_Assign(String *, String *, s32, s32);
    void String_Destroy(String *, s32);
    void String_Init(String *, char *, void *);
    void *StringMap_FindOrInsert(void *, String *);
    u32 strlen(char *);
    extern void *gGame;
    extern f32 fActorDefaultHeight;

    char sp33C[0x20];
    char sp31C[0x20];
    char sp2FC[0x20];
    char sp2DC[0x20];
    char sp2BC[0x20];
    char sp29C[0x20];
    char sp27C[0x20];
    char sp25C[0x20];
    char sp23C[0x20];
    char sp21C[0x20];
    char sp1FC[0x20];
    char sp1DC[0x20];
    char sp1BC[0x20];
    char sp19C[0x20];
    char sp17C[0x20];
    char sp15C[0x20];
    char sp13C[0x20];
    String str130;
    String str124;
    String sp118;
    String sp10C;
    String sp100;
    String spF4;
    String spE8;
    String spDC;
    String spD0;
    String spC4;
    String spB8;
    String spAC;
    String spA0;
    String sp94;
    String sp88;
    String sp7C;
    String sp70;
    String sp64;
    String sp58;
    String sp4C;
    void *sc48;
    void *sc44;
    void *sc40;
    void *sc3C;
    void *sc38;
    void *sc34;
    void *sc30;
    void *sc2C;
    void *sc28;
    void *sc24;
    void *sc20;
    void *sc1C;
    void *sc18;
    void *sc14;
    void *sc10;
    void *scC;
    void *sc8;
    BattleActor *self;
    void *xml;
    char *nameBuf;
    s32 count;
    s32 i;
    void *path;
    s8 made;
    s32 tmp;
    String *node;

    self = (BattleActor *)arg0;
    path = arg1;
    made = 0;
    str130.cap = 0;
    str124.cap = 0;
    str130.size = 0;
    str130.data = 0;
    str130.cap = 0;
    str124.size = 0;
    str124.data = 0;
    str124.cap = 0;

    xml = Heap_Alloc(0x60);
    if (xml != 0) {
        String_Init(&sp118, (char *)gActorXmlStrs + 0x38E, &sc48);
        made = 1;
        xml = Xml_ParseFile(xml, path, &sp118);
    }
    if (made != 0) {
        String_Destroy(&sp118, -1);
    }

    String_Init(&sp10C, (char *)gActorXmlStrs + 0x393, &sc44);
    Xml_GetNamedValue(sp33C, xml, &sp10C);
    count = *(s32 *)sp33C;
    String_Destroy(&sp10C, -1);

    nameBuf = sp31C;
    for (i = 0; i < count; i++) {
        Xml_AdvanceChild(xml);
        Xml_GetChildName(&sp100, xml);
        String_Assign(&str130, &sp100, 0, -1);
        String_Destroy(&sp100, -1);
        Xml_GetChildValue(sp31C, xml);
        String_AssignCStr(&str124, nameBuf, strlen(nameBuf));
        node = (String *)((u8 *)StringMap_FindOrInsert((u8 *)self + 0x1BC, &str130) + 0xC);
        String_Assign(node, &str124, 0, -1);
    }

    String_Init(&spF4, (char *)gActorXmlStrs + 0x39A, &sc40);
    Xml_GetNamedValue(sp2FC, xml, &spF4);
    self->height = *(f32 *)sp2FC;
    String_Destroy(&spF4, -1);

    String_Init(&spE8, (char *)gActorXmlStrs + 0x3A3, &sc3C);
    Xml_GetNamedValue(sp2DC, xml, &spE8);
    self->radius = *(f32 *)sp2DC;
    String_Destroy(&spE8, -1);

    String_Init(&spDC, (char *)gActorXmlStrs + 0x3AA, &sc38);
    Xml_GetNamedValue(sp2BC, xml, &spDC);
    self->unk_12C = *(s32 *)sp2BC;
    String_Destroy(&spDC, -1);

    String_Init(&spD0, (char *)gActorXmlStrs + 0x3B7, &sc34);
    Xml_GetNamedValue(sp29C, xml, &spD0);
    self->unk_130 = *(s32 *)sp29C;
    String_Destroy(&spD0, -1);

    String_Init(&spC4, (char *)gActorXmlStrs + 0x3C6, &sc30);
    Xml_GetNamedValue(sp27C, xml, &spC4);
    self->unk_134 = *(s32 *)sp27C;
    String_Destroy(&spC4, -1);

    String_Init(&spB8, (char *)gActorXmlStrs + 0x3D3, &sc2C);
    Xml_GetNamedValue(sp25C, xml, &spB8);
    self->unk_138 = *(s32 *)sp25C;
    String_Destroy(&spB8, -1);

    String_Init(&spAC, (char *)gActorXmlStrs + 0x3E0, &sc28);
    Xml_GetNamedValue(sp23C, xml, &spAC);
    self->unk_13C = *(s32 *)sp23C;
    String_Destroy(&spAC, -1);

    String_Init(&spA0, (char *)gActorXmlStrs + 0x3ED, &sc24);
    Xml_GetNamedValue(sp21C, xml, &spA0);
    self->heightFlag = *(s32 *)sp21C;
    String_Destroy(&spA0, -1);

    String_Init(&sp94, (char *)gActorXmlStrs + 0x3F4, &sc20);
    Xml_GetNamedValue(sp1FC, xml, &sp94);
    tmp = *(s32 *)sp1FC;
    self->flag_1A1 = (u8)(tmp != 0);
    String_Destroy(&sp94, -1);

    String_Init(&sp88, (char *)gActorXmlStrs + 0x401, &sc1C);
    Xml_GetNamedValue(sp1DC, xml, &sp88);
    self->rate = *(s32 *)sp1DC;
    String_Destroy(&sp88, -1);

    String_Init(&sp7C, (char *)gActorXmlStrs + 0x40A, &sc18);
    Xml_GetNamedValue(sp1BC, xml, &sp7C);
    self->unk_150 = *(f32 *)sp1BC;
    String_Destroy(&sp7C, -1);

    String_Init(&sp70, (char *)gActorXmlStrs + 0x417, &sc14);
    Xml_GetNamedValue(sp19C, xml, &sp70);
    self->unk_188 = *(s32 *)sp19C;
    String_Destroy(&sp70, -1);

    String_Init(&sp64, (char *)gActorXmlStrs + 0x420, &sc10);
    Xml_GetNamedValue(sp17C, xml, &sp64);
    self->unk_18C = *(s32 *)sp17C;
    String_Destroy(&sp64, -1);

    String_Init(&sp58, (char *)gActorXmlStrs + 0x42D, &scC);
    Xml_GetNamedValue(sp15C, xml, &sp58);
    self->unk_190 = *(s32 *)sp15C;
    String_Destroy(&sp58, -1);

    String_Init(&sp4C, (char *)gActorXmlStrs + 0x43A, &sc8);
    Xml_GetNamedValue(sp13C, xml, &sp4C);
    tmp = *(s32 *)sp13C;
    self->flag_1B6 = (u8)(tmp != 0);
    String_Destroy(&sp4C, -1);

    if (lbl_8036A184 == self->height) {
        self->height = fActorDefaultHeight;
    }
    if (lbl_8036A184 == self->radius) {
        self->radius = fActorDefaultRadius;
    }
    if (self->rate == 0) {
        self->rate = 1;
    }
    if (lbl_8036A184 == self->unk_150) {
        self->unk_150 = *(f32 *)((u8 *)gGame + 0xEC);
    }
    if (self->unk_188 == 0) {
        self->unk_188 = *(s32 *)((u8 *)gGame + 0x180);
    }
    if (self->unk_18C == 0) {
        self->unk_18C = *(s32 *)((u8 *)gGame + 0x188);
    }
    if (self->unk_190 == 0) {
        self->unk_190 = *(s32 *)((u8 *)gGame + 0x184);
    }

    Xml_Destroy(xml, 1);
    String_Destroy(&str124, -1);
    String_Destroy(&str130, -1);
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

void fn_80112DFC(void *arg0, u8 arg1) {
    s32 *temp_r3;

    temp_r3 = M2C_FIELD(arg0, s32 **, 0xE0);
    if (temp_r3 != NULL) {
        if (arg1 != 0) {
            *temp_r3 |= 0x80;
            return;
        }
        *temp_r3 &= 0xFFFFFF7F;
    }
}

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
extern "C" void fn_80112E30(void *arg0) {
    extern f32 lbl_8036A1A8;
    typedef void (*GetPosFn)(Vec3f *, void *, s32);
    void *target;
    void *self;
    f32 dist;
    Vec3f t2, t1, pb, pa, b, a;

    self = arg0;
    target = M2C_FIELD(arg0, void **, 0x118);
    if (target == NULL) {
        dist = lbl_8036A184;
    } else {
        a.z=lbl_8036A184; a.y=lbl_8036A184; a.x=lbl_8036A184;
        b.z=lbl_8036A184; b.y=lbl_8036A184; b.x=lbl_8036A184;
        ((GetPosFn)M2C_FIELD(M2C_FIELD(self,void **,0x40),void **,0x38))(&t1, self, 0);
        pa = a = t1;
        ((GetPosFn)M2C_FIELD(M2C_FIELD(target,void **,0x40),void **,0x38))(&t2, target, 0);
        pb = b = t2;
        dist = PSVECDistance(pa, pb);
    }
    if (dist >= lbl_8036A1A8 + M2C_FIELD(arg0, f32 *, 0x128)) {
        M2C_FIELD(arg0, u8 *, 0x1A4) = 0;
    }
}
#pragma cplusplus reset

u8 fn_80112F3C(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x1A4);
}

#pragma global_optimizer off
s32 Actor_IsWaitAnim(void *actor) {
    /* True if the actor's current anim path is Wait, contains Wait, or contains the +0x444 name while idle. */
    s32 n;
    extern u16 gActorXmlStrs[];
    s32 strlen(char *);
    s32 String_Compare(void *, s32, void *, char *, s32);
    s32 String_Find(void *, char *, s32, s32);
    u8 Actor_IsBusy(void *);

    n = strlen((char *)gActorXmlStrs + 0x43F);
    if (String_Compare((u8 *)actor + 0x178, 0, (void *)*(s32 *)((u8 *)actor + 0x178),
                      (char *)gActorXmlStrs + 0x43F, n) == 0 ||
        (u32)(String_Find((u8 *)actor + 0x178, (char *)gActorXmlStrs + 0x43F, 0,
                         strlen((char *)gActorXmlStrs + 0x43F)) + 0x10000) != 0xFFFF ||
        ((u32)(String_Find((u8 *)actor + 0x178, (char *)gActorXmlStrs + 0x444, 0,
                          strlen((char *)gActorXmlStrs + 0x444)) + 0x10000) != 0xFFFF &&
         Actor_IsBusy(actor) == 0)) {
        return 1;
    }
    return 0;
}
#pragma global_optimizer off
void fn_80113030(void *arg0, s32 arg1, void *arg2, void *arg3) {
    void *StringMap_FindOrInsert(void *, void *);
    void String_Assign(void *, void *, s32, s32);
    s32 String_Compare(void *, s32, void *, char *, s32);
    void String_Init(void *, char *, void *);
    void String_Destroy(void *, s32);
    void String_JoinCStr(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void fn_800C99A0(void *, void *, s32, s32);
    void *String_CStr(void *);
    void fn_800E5044(void *, void *);
    extern char *lbl_8028F6B8[];
    String sp48;
    String sp3C;
    String sp30;
    String sp24;
    String sp18;
    String spC;
    void *sp8;
    s32 n;
    u8 *p;

    sp48.cap = 0;
    sp3C.cap = 0;
    sp48.size = 0;
    sp48.data = 0;
    sp48.cap = 0;
    sp3C.size = 0;
    sp3C.data = 0;
    sp3C.cap = 0;

    p = (u8 *)StringMap_FindOrInsert((u8 *)arg0 + 0x1BC, arg3) + 0xC;
    String_Assign(&sp3C, p, 0, -1);
    n = strlen((char *)((u8 *)gActorXmlStrs + 0x1C));
    if (String_Compare(&sp3C, 0, (void *)sp3C.size, (char *)((u32)gActorXmlStrs + 0x1C), n) == 0) {
        p = (u8 *)StringMap_FindOrInsert((u8 *)arg0 + 0x1BC, arg2) + 0xC;
        String_Assign(&sp3C, p, 0, -1);
    }
    n = strlen((char *)((u8 *)gActorXmlStrs + 0x1C));
    if (String_Compare(&sp3C, 0, (void *)sp3C.size, (char *)((u32)gActorXmlStrs + 0x1C), n) == 0) {
        String_Init(&sp30, lbl_8028F6B8[arg1 & 3], &sp8);
        p = (u8 *)StringMap_FindOrInsert((u8 *)arg0 + 0x1BC, &sp30) + 0xC;
        String_Assign(&sp3C, p, 0, -1);
        String_Destroy(&sp30, -1);
    }
    n = strlen((char *)((u8 *)gActorXmlStrs + 0x449));
    if (String_Compare(&sp3C, 0, (void *)sp3C.size, (char *)((u32)gActorXmlStrs + 0x449), n) == 0) {
        String_Assign(&sp3C, (u8 *)arg0 + 0xB0, 0, -1);
    }
    String_JoinCStr(&sp24, (char *)((u8 *)gActorXmlStrs + 0x450), (u8 *)arg0 + 0xB0);
    String_ConcatCStr(&sp18, &sp24, (char *)((u8 *)gActorXmlStrs + 0x454));
    String_Assign(&sp48, &sp18, 0, -1);
    String_Destroy(&sp18, -1);
    String_Destroy(&sp24, -1);
    String_ConcatCStr(&spC, &sp3C, (char *)((u8 *)gActorXmlStrs + 0x456));
    fn_800C99A0(&sp48, &spC, 0, -1);
    String_Destroy(&spC, -1);
    fn_800E5044(arg0, String_CStr(&sp48));
    String_Destroy(&sp3C, -1);
    String_Destroy(&sp48, -1);
}
#pragma global_optimizer on
/* Load an actor animation from a relative path under the actor base dir. */
void Actor_LoadAnim(void *actor, void *relPath, s32 flag, s32 arg3, s32 arg4) {
    void String_Concat(void *, void *, void *);
    void String_Substr(void *, void *, s32, s32);
    void fn_800E574C(void *, void *, f32, s32, s32, s32, s32);
    char *fn_800DDB94(void *, void *);
    u8 fn_800E7AD4(void *, void *, void *, u8, u8);
    extern f32 lbl_8036A18C;
    String fullPath;
    String pathStr;
    String concat;
    String prefix;
    String cueName;
    String cueCopy;
    String mapped;
    void *scratch;
    void *path;
    s32 a2;
    s32 a3;
    s32 a4;
    void *self;
    void *strMap;
    void *cstr;

    path = relPath;
    self = actor;
    a2 = flag;
    a3 = arg3;
    a4 = arg4;
    fullPath.size = 0;
    fullPath.cap = 0;
    fullPath.data = 0;
    fullPath.cap = 0;
    String_AssignCStr((u8 *)self + 0x178, path, strlen(path));
    String_Init(&pathStr, path, &scratch);
    String_Concat(&concat, (u8 *)self + 0x154, &pathStr);
    String_Assign(&fullPath, &concat, 0, -1);
    String_Destroy(&concat, -1);
    String_Destroy(&pathStr, -1);
    cstr = String_CStr(&fullPath);
    fn_800E574C(self, cstr, lbl_8036A18C, a3, a4, *(u8 *)((u8 *)self + 0x184), a2);
    mapped.cap = 0;
    cueCopy.cap = 0;
    cueName.cap = 0;
    mapped.size = 0;
    mapped.data = 0;
    mapped.cap = 0;
    cueCopy.size = 0;
    cueCopy.data = 0;
    cueCopy.cap = 0;
    cueName.size = 0;
    cueName.data = 0;
    cueName.cap = 0;
    strMap = *(void **)((u8 *)self + 0xDC);
    if (strMap == NULL) {
        String_Destroy(&cueName, -1);
        String_Destroy(&cueCopy, -1);
        String_Destroy(&mapped, -1);
    } else {
        char *mappedCstr;
        s32 n;
        mappedCstr = fn_800DDB94(strMap, (u8 *)self + 0xBC);
        String_AssignCStr(&mapped, mappedCstr, strlen(mappedCstr));
        n = strlen((char *)((u8 *)gActorXmlStrs + 0x1C));
        if (String_Compare(&mapped, 0, (void *)mapped.size, (char *)((u32)gActorXmlStrs + 0x1C), n) == 0) {
            String_Destroy(&cueName, -1);
            String_Destroy(&cueCopy, -1);
            String_Destroy(&mapped, -1);
        } else {
            String_Substr(&prefix, &mapped, 0, 0xB);
            String_Assign(&cueCopy, &prefix, 0, -1);
            String_Destroy(&prefix, -1);
            String_Assign(&cueName, &cueCopy, 0, -1);
            *(u8 *)((u8 *)self + 0x1A7) = fn_800E7AD4(*(void **)((u8 *)self + 0xAC), &cueName, *(void **)((u8 *)self + 0x1AC), *(u8 *)((u8 *)self + 0x1A2), *(u8 *)((u8 *)self + 0x1A3));
            String_Destroy(&cueName, -1);
            String_Destroy(&cueCopy, -1);
            String_Destroy(&mapped, -1);
        }
    }
    String_Destroy(&fullPath, -1);
}

#pragma global_optimizer off
void fn_801134EC(void *out, void *actor, void *name) {
    s32 strlen(char *);
    s32 String_Compare(void *, s32, void *, char *, s32);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_Concat(void *, void *, void *);
    void String_Copy(void *, void *);
    void fn_800C992C(void *, char *, u32);
    void fn_800C99A0(void *, void *, s32, s32);
    s32 fn_800DDC04(void *, void *);
    String path;
    String joined;
    u32 n;
    s32 ok;

    path.cap = 0;
    path.size = 0;
    path.data = 0;
    path.cap = 0;
    String_Assign(&path, name, 0, -1);
    n = strlen((char *)gActorXmlStrs + 0x1C);
    if (String_Compare((u8 *)actor + 0x160, 0, (void *)*(u32 *)((u8 *)actor + 0x160),
                       (char *)gActorXmlStrs + 0x1C, n) != 0) {
        fn_800C992C(&path, (char *)gActorXmlStrs + 0xFC,
                    strlen((char *)gActorXmlStrs + 0xFC));
        fn_800C99A0(&path, (u8 *)actor + 0x160, 0, -1);
    }
    String_Concat(&joined, (u8 *)actor + 0x154, &path);
    ok = fn_800DDC04(*(void **)((u8 *)actor + 0xDC), &joined) == 0;
    String_Destroy(&joined, -1);
    if ((u8)ok != 0) {
        String_Assign(&path, name, 0, -1);
        *(u8 *)((u8 *)actor + 0x184) = 1;
    } else {
        *(u8 *)((u8 *)actor + 0x184) = 1;
    }
    String_Copy(out, &path);
    String_Destroy(&path, -1);
}
#pragma global_optimizer on

void Actor_SetRadius(void *arg0, f32 farg0) {
    M2C_FIELD(arg0, f32 *, 0x128) = farg0;
}

f32 Actor_GetRadius(void *arg0) {
    return M2C_FIELD(arg0, f32 *, 0x128);
}

#pragma cplusplus on
extern "C" void fn_80113658(void *arg0, void *arg1) {
    struct Actor {
        u8 pad0[0x40];
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
        virtual Vec3f GetPos() = 0;
    };
    Vec3f a;
    Vec3f b;

    a = ((Actor *)arg0)->GetPos();
    b = ((Actor *)arg1)->GetPos();
    PSVECDistance(a, b);
}
#pragma cplusplus reset
void fn_801136EC(f32 *arg0, void *arg1) {
    s32 fn_800E4F0C(void *, char *);
    void fn_80060F70(void *, s32, f32 *);
    extern f32 lbl_8036A1B4;
    extern f32 lbl_8036A1B8;

    f32 pos[3];
    f32 x;
    f32 y;
    f32 z;
    s32 index;

    index = fn_800E4F0C(arg1, (char *)((u32)gActorXmlStrs + 0x45b));
    if (index == -1) {
        (*(void (**)(f32 *, void *, s32))(*(u8 **)((u8 *)arg1 + 0x40) + 0x38))(arg0, arg1, 0);
    } else {
        fn_80060F70(*(void **)((u8 *)arg1 + 0xE0), index, pos);
        x = pos[0];
        if (x > lbl_8036A1B4 && x < lbl_8036A1B8) {
            y = pos[1];
            z = pos[2];
        } else {
            z = lbl_8036A184;
            y = z;
            x = z;
        }
        arg0[0] = x;
        arg0[1] = y;
        arg0[2] = z;
    }
}

void fn_801137AC(f32 *out, void *arg1, u8 arg2) {
    s32 fn_800E4F0C(void *, char *);
    void fn_80060F70(void *, s32, f32 *);
    extern f32 lbl_8036A184;
    extern f32 lbl_8036A1B4;
    extern f32 lbl_8036A1B8;
    f32 sp8[3];
    int idx;
    register f32 x;
    f32 z;
    register f32 y;

    idx = fn_800E4F0C(arg1, (char *)lbl_80273DF8 + 0x45F);
    fn_80060F70(M2C_FIELD(arg1, void **, 0xE0), idx, sp8);
    x = sp8[0];
    if (x > lbl_8036A1B4 && x < lbl_8036A1B8) {
        y = lbl_8036A184;
        z = sp8[2];
    } else {
        z = lbl_8036A184;
        x = z;
        y = z;
    }
    if (M2C_FIELD(arg1, s32 *, 0x19C) != 0 || arg2 != 0) {
        y = sp8[1];
    }
    out[1] = y;
    out[0] = x;
    out[2] = z;
}

void fn_8011386C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x14C) = -1;
}

s32 Actor_HasHeightFlag(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x19C) != 0;
}

u8 fn_8011388C(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x1B4);
}

s32 fn_80113894(void *arg0) {
    u8 fn_8019906C(s32);
    s32 fn_80199114(s32);
    if ((fn_8019906C(M2C_FIELD(arg0, s32 *, 0x11C)) != 0) && (fn_80199114(M2C_FIELD(arg0, s32 *, 0x11C)) != -1)) {
        return 1;
    }
    return 0;
}

void fn_801138E8(void *arg0) {
    M2C_UNK fn_801990A4(s32);
    fn_801990A4(M2C_FIELD(arg0, s32 *, 0x11C));
}

void fn_8011390C(void *arg0) {
    M2C_UNK fn_801990DC(s32);
    fn_801990DC(M2C_FIELD(arg0, s32 *, 0x11C));
}

#pragma cplusplus on
extern "C" void fn_80113930(void *arg0) {
    struct Vec3 {
        f32 x, y, z;
Vec3() {}
Vec3(f32 v) { z=v; y=v; x=v; }
    };
    struct Actor {
        u8 pad0[0x40];
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
        virtual Vec3 GetPos(s32) = 0;
    };
    void fn_800E4E7C(void *, void *, char *);
    void Camera_GetLookAt(void *, void *);
    void fn_8019914C(void *, void *, void *, void *);
    void fn_801985C4(void *);
    extern f32 lbl_8036A184;
    extern u16 gActorXmlStrs[];
    Vec3 a(0.0f);
    Vec3 b(0.0f);
    Vec3 c(0.0f);
    Vec3 tmpA;
    Vec3 tmpB;
    Actor *other;


    fn_800E4E7C(&tmpA, arg0, (char *)gActorXmlStrs + 0x464);
    a.x = tmpA.x;
    a.y = tmpA.y;
    a.z = tmpA.z;

    Camera_GetLookAt(&tmpB, arg0);
    b.x = tmpB.x;
    b.y = tmpB.y;
    b.z = tmpB.z;

    other = *(Actor **)((u8 *)arg0 + 0x118);
    c = other->GetPos(0);

    fn_8019914C(*(void **)((u8 *)arg0 + 0x11C), &a, &b, &c);
    fn_801985C4(*(void **)((u8 *)arg0 + 0x11C));
}

extern "C" void fn_80113A24(void *arg0, u8 arg1) {
 struct Vec3 { f32 x,y,z; Vec3() {} Vec3(f32 f) { z=f; y=f; x=f; } };
 struct VTable { u8 pad[0x38]; Vec3 (*GetPos)(void *, s32); };
 struct Actor {
 u8 pad[0x40];
 virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
 virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0;
 virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void v11()=0;
 virtual Vec3 GetPos(s32)=0;
 };
 Vec3 Camera_GetLookAt(void *); s32 fn_801992F0(void *); void fn_8019914C(void *,void *,void *,void *);
 Vec3 a(0.0f), b(0.0f), c(0.0f);
 if(arg1 || fn_801992F0(*(void **)((u8 *)arg0+0x11c))==1 || fn_801992F0(*(void **)((u8 *)arg0+0x11c))==2) {
 VTable *vt = *(VTable **)((u8 *)arg0+0x40);
 Vec3 (*fp)(void *, s32) = vt->GetPos;
 a=fp(arg0,0);
 b=Camera_GetLookAt(arg0);
 } else {
 a=(*(Actor **)((u8 *)arg0+0x118))->GetPos(0);
 b=Camera_GetLookAt(*(void **)((u8 *)arg0+0x118));
 }
 c=(*(Actor **)((u8 *)arg0+0x118))->GetPos(0);
 a.y=0.0f;
 fn_8019914C(*(void **)((u8 *)arg0+0x11c),&a,&b,&c);
}

extern "C" void fn_80113BA0(void *arg0) {
    struct V3 {
        f32 x, y, z;
    };
    struct Actor {
        u8 pad[0x40];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v7() = 0;
        virtual void v6() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual V3 GetPos(s32) = 0;
    };
    void *fn_80117CC0(void *, s32);
    s32 fn_80199310(void *);
    void fn_80198910(void *, V3 *, s32);
    extern f32 lbl_8036A184;
    extern f32 lbl_8036A1BC;

    V3 pos;
    void *actor;
    V3 got;
    f32 twenty;
    f32 zero;
    s32 ch;

    zero = 0.0f;
    twenty = 20.0f;
    pos.x = twenty;
    pos.y = zero;
    pos.z = zero;

    actor = *(void **)((u8 *)arg0 + 0x118);
    if (actor != NULL) {
        got = ((Actor *)actor)->GetPos(1);
        pos.x = got.x;
        pos.y = got.y;
        pos.z = got.z;
    }
    if (fn_80199310(*(void **)((u8 *)arg0 + 0x11C)) == 3 && *(void **)((u8 *)arg0 + 0x120) != NULL) {
        register ch = *(u8 *)fn_80117CC0((u8 *)arg0 + 0xB0, 0);
        if (ch == 0x73) {
            fn_80198910(*(void **)((u8 *)arg0 + 0x120), &pos, *(s32 *)((u8 *)arg0 + 0x144));
        } else {
            fn_80198910(*(void **)((u8 *)arg0 + 0x120), &pos, 0);
        }
    } else {
        fn_80198910(*(void **)((u8 *)arg0 + 0x11C), &pos, 0);
    }
}
#pragma cplusplus reset

#pragma push
#pragma opt_common_subs off
void fn_80113C84(void *self, s32 mode) {
    s32 strlen(char *);
    s32 fn_800DDC04(void *, void *);
    void String_Concat(void *, void *, void *);
    void String_AssignCStr(void *, char *, s32);
    s32 String_Compare(void *, s32, void *, char *, s32);
    void String_Init(void *, void *, void *);
    void *String_CStr(void *);
    void String_Destroy(void *, s32);
    void String_Assign(void *, void *, s32, s32);
    void fn_801134EC(void *, void *, void *);
    void Actor_LoadAnim(void *, void *, s32, s32, s32);
    String sp3C;
    String sp30;
    String sp24;
    String sp18;
    String spC;
    s32 sp8;
    u32 ok;
    s32 n;

    sp3C.size = 0;
    sp3C.cap = 0;
    sp3C.data = 0;
    sp3C.cap = 0;
    sp30.size = 0;
    sp30.cap = 0;
    sp30.data = 0;
    sp30.cap = 0;

    String_AssignCStr((u8 *)self + 0x16C, (char *)gActorXmlStrs + 0x1C, strlen((char *)((u32)gActorXmlStrs + 0x1C)));
    *(s32 *)((u8 *)self + 0x144) = mode;

    switch (mode) {
    case 0:
        String_AssignCStr(&sp3C, (char *)gActorXmlStrs + 0x46A, strlen((char *)((u32)&gActorXmlStrs[0] + 0x46A)));
        break;
    case 1:
        String_AssignCStr(&sp3C, (char *)gActorXmlStrs + 0x46F, strlen((char *)((unsigned long)gActorXmlStrs + 0x46F)));
        break;
    case 2:
        String_AssignCStr(&sp3C, (char *)gActorXmlStrs + 0x46F, strlen((char *)((u32)&gActorXmlStrs[0] + 0x46F)));
        break;
    case 3:
        String_AssignCStr(&sp3C, (char *)gActorXmlStrs + 0x478, strlen((char *)((unsigned long)gActorXmlStrs + 0x478)));
        break;
    }

    n = strlen((char *)gActorXmlStrs + 0x478);
    if (String_Compare(&sp3C, 0, (void *)sp3C.size, (char *)gActorXmlStrs + 0x478, n) == 0) {
        String_Init(&spC, String_CStr(&sp3C), &sp8);
        String_Concat(&sp18, (u8 *)self + 0x154, &spC);
        ok = fn_800DDC04(*(void **)((u8 *)self + 0xDC), &sp18) != 0;
        String_Destroy(&sp18, -1);
        String_Destroy(&spC, -1);
        if (ok == 0) {
            String_AssignCStr(&sp3C, (char *)gActorXmlStrs + 0x46A, strlen((char *)((u32)&gActorXmlStrs[0] + 0x46A)));
        }
    }

    String_Assign(&sp30, &sp3C, 0, -1);
    fn_801134EC(&sp24, self, &sp3C);
    String_Assign(&sp3C, &sp24, 0, -1);
    String_Destroy(&sp24, -1);
    String_AssignCStr((u8 *)self + 0x16C, (char *)gActorXmlStrs + 0x43F, strlen((char *)((unsigned long)gActorXmlStrs + 0x43F)));
    Actor_LoadAnim(self, String_CStr(&sp3C), *(s32 *)((u8 *)self + 0x188), 0, 1);
    String_Assign((u8 *)self + 0x160, &sp30, 0, -1);
    *(u8 *)(*(u8 **)((u8 *)self + 0x11C) + 0x14D) = 0;
    *(u8 *)((u8 *)self + 0x1A4) = 1;
    String_Destroy(&sp30, -1);
    String_Destroy(&sp3C, -1);
}
#pragma pop
u8 fn_80113F68(void *arg0) {
    extern f32 lbl_8036A184;
    return (u8) (lbl_8036A184 != M2C_FIELD(arg0, f32 *, 0x104));
}

#pragma cplusplus reset
void fn_80113F88(void *arg0) {
    void fn_800E4C14(void *, f32);
    void fn_800E4BE0(void *, s32, s32, f32);
    void SeCue_PlayAt(void *, s32, f32, f32, f32);
    extern f32 lbl_8036A1C0;
    extern f32 lbl_8036A1C4;

    typedef struct { f32 x, y, z; } Vec3f;
    f32 fx;
    f32 fy;
    f32 fz;
    Vec3f pos;
    void *child;

    (*(void (**)(Vec3f *, void *, s32))(*(u8 **)((u8 *)arg0 + 0x40) + 0x38))(&pos, arg0, 0);
    fx = pos.x;
    fy = pos.y;
    fz = pos.z;

    fn_800E4C14(arg0, lbl_8036A1C0);
    child = *(void **)((u8 *)arg0 + 0x11C);
    if (child != 0) {
        fn_800E4C14(child, lbl_8036A1C0);
    }
    fn_800E4BE0(arg0, 0x80, 0x270f, lbl_8036A1C4);
    child = *(void **)((u8 *)arg0 + 0x11C);
    if (child != 0) {
        fn_800E4BE0(child, 0x80, 0x270f, lbl_8036A1C4);
    }
    SeCue_PlayAt((char *)gActorXmlStrs + 0x481, 0x64, fx, fy, fz);
}
#pragma push
#pragma optimization_level 1
void fn_80114078(void *arg0)
{
  void *self = arg0;
  s32 n;
  u8 *new_var;
  void *new_var2;
  *((u8 *) (((u8 *) self) + 0x184)) = 1;
  new_var2 = self;
  new_var = (u8 *) new_var2;
  Actor_LoadAnim(self, ((u8 *) (&gActorXmlStrs)) + 0x498, (*((s32 *) (((u8 *) self) + 0x188))) * 2, 0, 1);
  n = strlen(((char *) (&gActorXmlStrs)) + 0x1C);
  String_AssignCStr(((u8 *) new_var2) + 0x160, ((char *) (&gActorXmlStrs)) + 0x1C, n);
  n = strlen(((char *) (&gActorXmlStrs)) + 0x1C);
  String_AssignCStr(new_var + 0x16C, ((char *) (&gActorXmlStrs)) + 0x1C, n);
  *((u8 *) (new_var + 0x1A6)) = (*((u8 *) (new_var + 0x1A4)) = 1);
}
#pragma pop
#pragma cplusplus on
#pragma global_optimizer off
extern "C" void fn_80114124(void *arg0, s32 arg1) {
    s32 strlen(char *);
    void fn_800C96F8(void *, char *, u32);
    void fn_800C9758(void *, void *, s32, s32);
    void fn_800C9A60(void *, s32);
    void fn_800C9ABC(void *, char *, void *);
    void fn_800CB8A4(void *, void *, void *);
    void fn_800CB90C(void *, void *, char *);
    void *fn_800C93EC(void *);
    void fn_800CBF24(void *, void *, void *);
    s32 fn_800C9400(void *, s32, void *, char *, s32);
    s32 fn_800DDAA4(void *, void *);
    s32 fn_800DDC04(void *, void *);
    void fn_800DF670(void *);
    void fn_800E4FE8(void *, void *, char *);
    void fn_80113298(void *, void *, s32, s32, s32);
    void fn_801134EC(void *, void *, void *);
    void fn_80147578(char *, s32, f32, f32, f32);
    void *fn_801992F8(void *);
    s32 fn_80199310(void *);
    void fn_80203184(void *, void *, void *);
    void fn_802031CC(void *, void *, f32);
    extern f32 fn_802032CC(const Vec3f &, const Vec3f &);
    extern void *lbl_80368278;

    struct Actor {
        u8 pad0[0x40];
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
        virtual Vec3f GetPos(s32) = 0;
        virtual void v13() = 0;
        virtual void Adjust(Vec3f *, f32, f32) = 0;
    };

    typedef void (*GetPosFn)(Vec3f *, void *, s32);

    s32 t;
    f32 fx;
    f32 fy;
    f32 fz;
    f32 adj_x;
    f32 scale;
    String sp104;
    Vec3f spF8;
    Vec3f spEC;
    String spE0;
    String spD4;
    Vec3f spC8;
    String spBC;
    String spB0;
    String spA4;
    String sp98;
    String sp8C;
    Vec3f sp80;
    Vec3f sp74;
    Vec3f sp68;
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;
    Vec3f sp38;
    Vec3f sp2C;
    Vec3f sp20;
    Vec3f sp14;
    void *scratch1;
    void *scratch0;
    void *scratch2;

    sp104.size = 0;
    sp104.cap = 0;
    sp104.data = 0;
    sp104.cap = 0;

    ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&spEC, arg0, 0);
    fx = spEC.x;
    fy = spEC.y;
    fz = spEC.z;

    fn_800C96F8((u8 *)arg0 + 0x16C, (char *)&lbl_80273DF8 + 0x1C,
                strlen((char *)&lbl_80273DF8 + 0x1C));

    if (*(void **)((u8 *)arg0 + 0x11C) != 0) {
        t = fn_80199310(*(void **)((u8 *)arg0 + 0x11C));
        fn_800DF670(*(void **)((u8 *)arg0 + 0x11C));
        if (t == 3) {
            fn_800E4FE8(*(void **)((u8 *)arg0 + 0x11C), arg0, (char *)&lbl_80273DF8 + 0xEE);
        } else {
            fn_800E4FE8(*(void **)((u8 *)arg0 + 0x11C), arg0, (char *)&lbl_80273DF8 + 0xF5);
        }
        fn_800C9ABC(&spA4, (char *)&lbl_80273DF8 + 0xFC, &scratch0);
        fn_800CBF24(&spB0, fn_801992F8(*(void **)((u8 *)arg0 + 0x11C)), &spA4);
        fn_800C9758((u8 *)arg0 + 0x154, &spB0, 0, -1);
        fn_800C9A60(&spB0, -1);
        fn_800C9A60(&spA4, -1);
    }

    fn_800CB90C(&spBC, (u8 *)arg0 + 0x154, (char *)&lbl_80273DF8 + 0xFE);
    t = fn_800DDAA4(*(void **)((u8 *)arg0 + 0xDC), &spBC) == 0 ? 1 : 0;
    fn_800C9A60(&spBC, -1);
    if ((u8)t != 0) {
        *(u8 *)((u8 *)arg0 + 0x1A4) = 1;
    }

    fn_800C9ABC(&spE0, (char *)&lbl_80273DF8 + 0x444, &scratch1);
    fn_801134EC(&spD4, arg0, &spE0);
    fn_800C9758(&sp104, &spD4, 0, -1);
    fn_800C9A60(&spD4, -1);
    fn_800C9A60(&spE0, -1);

    if (arg1 != 0) {
        fn_800C9ABC(&sp8C, (char *)&lbl_80273DF8 + 0x49D, &scratch2);
        fn_800CB8A4(&sp98, (u8 *)arg0 + 0x154, &sp8C);
        t = fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), &sp98) != 0 ? 1 : 0;
        fn_800C9A60(&sp98, -1);
        fn_800C9A60(&sp8C, -1);
        if ((u32)t == 0) {
            goto do_43f;
        }
        goto skip_43f;
    }
do_43f:
    fn_800C96F8((u8 *)arg0 + 0x16C, (char *)&lbl_80273DF8 + 0x43F,
                strlen((char *)&lbl_80273DF8 + 0x43F));
skip_43f:

    fn_80113298(arg0, fn_800C93EC(&sp104), *(s32 *)((u8 *)arg0 + 0x188), 0, 1);

    {
        u32 n;
        n = strlen((char *)((u32)&lbl_80273DF8 + 0x49D));
        if (fn_800C9400(&sp104, 0, (void *)sp104.size, (char *)((u32)&lbl_80273DF8 + 0x49D), n) == 0) {
            fn_800C96F8((u8 *)arg0 + 0x160, (char *)&lbl_80273DF8 + 0x1C,
                        strlen((char *)&lbl_80273DF8 + 0x1C));
        } else {
            fn_800C96F8((u8 *)arg0 + 0x160, (char *)&lbl_80273DF8 + 0x444,
                        strlen((char *)&lbl_80273DF8 + 0x444));
        }
    }

    {
        f32 d;
        void *other;
        f32 z;
        f32 dx;
        other = *(void **)((u8 *)arg0 + 0x118);
        d = lbl_8036A184;
        spF8.z = d;
        spF8.y = d;
        spF8.x = d;
        if (other != 0) {
            goto do_dist;
        }
        goto after_dist;
do_dist:
        sp44.z = d;
        sp44.y = d;
        sp44.x = d;
        sp50.z = d;
        sp50.y = d;
        sp50.x = d;
        ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp74, arg0, 0);
        sp5C = sp74;
        sp44 = sp74;
        ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&sp80, other, 0);
        sp50 = sp80;
        sp68 = sp80;
        d = fn_802032CC(sp5C, sp68);
after_dist:

        scale = *(f32 *)((u8 *)lbl_80368278 + 0xE0);
        if (d < *(f32 *)((u8 *)arg0 + 0x128) * scale) {
            f32 a0, a1, a2;
            if (*(u32 *)((u8 *)arg0 + 0x118) == 0) {
                a0 = *(f32 *)((u8 *)arg0 + 0x48);
                a1 = lbl_8036A184;
                a2 = *(f32 *)((u8 *)arg0 + 0x50);
            } else {
                ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp2C, arg0, 0);
                adj_x = sp2C.x;
                ((GetPosFn)((void **)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x118) + 0x40))[0xE])(
                    &sp38, *(void **)((u8 *)arg0 + 0x118), 0);
                z = lbl_8036A184;
                dx = adj_x - *(f32 *)((u8 *)arg0 + 0x48);
                sp14.x = sp38.x - dx;
                sp14.y = z;
                sp14.z = z;
                sp20.x = -*(f32 *)((u8 *)arg0 + 0x60);
                sp20.y = z;
                sp20.z = z;
                fn_802031CC(&sp20, &sp20, *(f32 *)((u8 *)arg0 + 0x128) * scale);
                fn_80203184(&sp14, &sp20, &sp14);
                a0 = sp14.x;
                a1 = lbl_8036A184;
                a2 = lbl_8036A184;
            }
            spF8.x = a0;
            spF8.y = a1;
            spF8.z = a2;
            *(u32 *)&spC8.x = *(u32 *)&spF8.x;
            *(u32 *)&spC8.y = *(u32 *)&spF8.y;
            *(u32 *)&spC8.z = *(u32 *)&spF8.z;
            ((Actor *)arg0)->Adjust(&spC8, *(f32 *)((u8 *)lbl_80368278 + 0xE4), lbl_8036A184);
        }
    }

    *(s32 *)((u8 *)arg0 + 0x140) = 0;
    fn_80147578((char *)&lbl_80273DF8 + 0x4A7, 0x64, fx, fy, fz);
    *(u8 *)((u8 *)arg0 + 0x1A4) = 1;
    fn_800C9A60(&sp104, -1);
}

extern "C" void fn_801146BC(void *arg0) {
    void *Heap_Alloc(s32);
    void String_Init(void *, char *, void *);
    void Camera_GetLookAt(void *, void *);
    void String_Destroy(void *, s32);
    void *fn_80151D50(void *, void *, void *, void *, void *, void *, s32);
    struct Actor {
        u8 pad[0x40];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v4() = 0;
        virtual void v3() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual Vec3f GetPos(s32) = 0;
    };
    struct Manager {
        u8 pad[0x10];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v3() = 0;
        virtual void v2() = 0;
        virtual void v4() = 0;
        virtual void Add(void *) = 0;
    };
    typedef struct { s32 x, y, z; } Word3;
    register Vec3f pos;
    Vec3f got;
    String strShort;
    register Word3 copyA;
    Word3 lookAt;
    void *scratch1;
    Word3 copyB;
    String strLong;
    void *scratch2;
    register void *obj;
    s8 flagLong;
    s8 flagShort;

    pos.z = 0.0f;
    pos.y = 0.0f;
    pos.x = 0.0f;
    got = ((Actor *)arg0)->GetPos(0);
    flagLong = 0;
    flagShort = 0;
    pos.x = got.x;
    pos.y = got.y;
    pos.z = got.z;
    pos.y = 6.0f + *(f32 *)((u8 *)arg0 + 0x4C);
    obj = Heap_Alloc(0xC8);
    if (obj != NULL) {
        Camera_GetLookAt(&lookAt, arg0);
        copyA = lookAt;
        *(u32 *)&copyB.x = *(u32 *)&pos.x;
        *(u32 *)&copyB.y = *(u32 *)&pos.y;
        *(u32 *)&copyB.z = *(u32 *)&pos.z;
        String_Init(&strLong, (char *)gActorXmlStrs + 0x4B5, &scratch1);
        flagLong = 1;
        String_Init(&strShort, (char *)gActorXmlStrs + 0x51, &scratch2);
        flagShort = 1;
        obj = fn_80151D50(obj, *(void **)((u8 *)arg0 + 0xAC), &strShort, &strLong, &copyB, &copyA, 0);
    }
    (*(Manager **)((u8 *)arg0 + 0xAC))->Add(obj);
    if (flagShort) {
        String_Destroy(&strShort, -1);
    }
    if (flagLong) {
        String_Destroy(&strLong, -1);
    }
}

#pragma global_optimizer reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
extern "C" void fn_80114840(void *arg0) {
    void *Heap_Alloc(s32);
    void String_Init(void *, char *, void *);
    void Camera_GetLookAt(void *, void *);
    void String_Destroy(void *, s32);
    void *fn_80151D50(void *, void *, void *, void *, void *, void *, s32);
    void SeCue_PlayAt(void *, s32, f32, f32, f32);
    extern void *gPadInput;
    void fn_80025624(void *, s32);

    struct Actor {
        u8 pad[0x40];
        virtual void v1() = 0;
        virtual void v0() = 0;
        virtual void v3() = 0;
        virtual void v2() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v10() = 0;
        virtual void v9() = 0;
        virtual void v11() = 0;
        virtual Vec3f GetPos(s32) = 0;
    };

    struct Manager {
        u8 pad[0x10];
        virtual void v2() = 0;
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5(void *) = 0;
    };

    typedef struct {
        s32 x, y, z;
    } Word3;

    void *self;
    Word3 pos;
    s8 flagA;
    register s8 flagB;
    register String strC;
    Vec3f got;
    Word3 copyA;
    register Word3 tmpVec;
    Word3 copyB2;
    register String strB;
    register String strA;
    Word3 copyB;
    void *obj;
    Word3 tmpVec2;
    Word3 copyA2;
    String strD;
    void *scratch;
    void *scratch2;
    void *scratch3;
    void *scratch4;

    self = arg0;
    *(f32 *)&pos.z = 0.0f;
    *(f32 *)&pos.y = 0.0f;
    *(f32 *)&pos.x = 0.0f;
    got = ((Actor *)self)->GetPos(0);
    flagB = 0;
    flagA = 0;
    *(f32 *)&pos.y = got.y;
    *(f32 *)&pos.x = got.x;
    *(f32 *)&pos.z = got.z;
    *(f32 *)&pos.y = lbl_8036A1C8 + *(f32 *)((u8 *)self + 0x4C);
    *(s32 *)((u8 *)self + 0x140) = 0;
    obj = Heap_Alloc(0xC8);
    if (obj != NULL) {
        Camera_GetLookAt(&tmpVec, self);
        copyA = tmpVec;
        copyB = pos;
        String_Init(&strB, (char *)gActorXmlStrs + 0x4BE, &scratch);
        flagB = 1;
        String_Init(&strA, (char *)gActorXmlStrs + 0x51, &scratch2);
        flagA = 1;
        obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &strA, &strB, &copyB, &copyA, 0);
    }
    (*(Manager **)((u8 *)self + 0xAC))->v5(obj);
    if (flagA) {
        String_Destroy(&strA, -1);
    }
    if (flagB) {
        String_Destroy(&strB, -1);
    }
    flagA = 0;
    flagB = 0;
    obj = Heap_Alloc(0xC8);
    if (obj != NULL) {
        Camera_GetLookAt(&tmpVec2, self);
        copyA2 = tmpVec2;
        copyB2 = pos;
        String_Init(&strD, (char *)gActorXmlStrs + 0x4CB, &scratch3);
        flagA = 1;
        String_Init(&strC, (char *)gActorXmlStrs + 0x51, &scratch4);
        flagB = 1;
        obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &strC, &strD, &copyB2, &copyA2, 0);
    }
    (*(Manager **)((u8 *)self + 0xAC))->v5(obj);
    if (flagB) {
        String_Destroy(&strC, -1);
    }
    if (flagA) {
        String_Destroy(&strD, -1);
    }
    SeCue_PlayAt((char *)gActorXmlStrs + 0x4DA, 0x64, *(f32 *)&pos.x, *(f32 *)&pos.y, *(f32 *)&pos.z);
    fn_80025624(gPadInput, 4);
    *(u8 *)((u8 *)self + 0x1A4) = 1;
}
#pragma pop
#pragma cplusplus off

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
    virtual void v15() = 0;
    virtual u8 IsBusy() = 0;
};
#pragma cplusplus on
#pragma push
#pragma dont_inline on
#pragma optimization_level 3
#pragma global_optimizer off
extern "C" void fn_80114AF0(void *arg0, s32 mode, u8 flag, u8 force) {
s32 strlen(char *);
s32 fn_80199310(void *);
void fn_800DF670(void *);
void fn_800E4FE8(void *,void *,char *);
void *fn_801992F8(void *);
void String_JoinCStr(void *,void *,void *);
void String_ConcatCStr(void *,void *,char *);
s32 fn_800DDAA4(void *,void *);
void fn_802031E8(void *,void *);
void fn_802031CC(void *,void *,f32);
void fn_80203184(void *,void *,void *);
void fn_800E4BE0(void *,s32,s32,f32);
void SeCue_PlayAt(char *,s32,f32,f32,f32);
void *fn_800E7E4C(void *,void *);
void fn_800DBF38(void *,s32,f32,f32);
void fn_80025624(void *,s32);
extern void *gGame;
extern void *gPadInput;
extern f32 lbl_8036A18C, lbl_8036A1C4, lbl_8036A1CC;
String anim;
f32 move[3];
PVector3 pos;
String se8, se7;
u32 copy[3];
String se6,se5,se4,se3,se2,se1,test,joined,suffix;
PVector3 other;
f32 current[3];
f32 dir[3], result[3], origin[3];
void *scratch7,*scratch6,*scratch5,*scratch4,*scratch3,*scratch2,*scratch1,*scratch0;
f32 scale,x,y,z,px;
s32 kind;
s32 missing;
anim.cap=0; anim.size=0; anim.data=0; anim.cap=0;
pos = ((ActorMotionInterface*)arg0)->GetPos(0);
x=pos.x;y=pos.y;z=pos.z;
if (*(void **)((u8*)arg0+0x11C)) {
kind=fn_80199310(*(void **)((u8*)arg0+0x11C));
fn_800DF670(*(void **)((u8*)arg0+0x11C));
if(kind==3) fn_800E4FE8(*(void **)((u8*)arg0+0x11C),arg0,(char*)gActorXmlStrs+0xEE);
else fn_800E4FE8(*(void **)((u8*)arg0+0x11C),arg0,(char*)gActorXmlStrs+0xF5);
String_Init(&suffix,(char*)gActorXmlStrs+0xFC,&scratch0);
String_JoinCStr(&joined,fn_801992F8(*(void **)((u8*)arg0+0x11C)),&suffix);
String_Assign((u8*)arg0+0x154,&joined,0,-1);
String_Destroy(&joined,-1);String_Destroy(&suffix,-1);
}
String_ConcatCStr(&test,(u8*)arg0+0x154,(char*)gActorXmlStrs+0xFE);
missing=fn_800DDAA4(*(void **)((u8*)arg0+0xDC),&test)==0 ? 1 : 0;
String_Destroy(&test,-1);
if((u8)missing) *(u8*)((u8*)arg0+0x1A4)=1;
if(!flag) {
*(u32*)((u8*)arg0+0x14C)=*(u32*)((u8*)gGame+0xE8);
*(s32*)((u8*)arg0+0x148)=mode;
}
String_Init(&se8,(char*)gActorXmlStrs+0x4ED,&scratch7);
fn_801134EC(&se7,arg0,&se8);
String_Assign(&anim,&se7,0,-1);
String_Destroy(&se7,-1);String_Destroy(&se8,-1);
String_AssignCStr((u8*)arg0+0x16C,(char*)gActorXmlStrs+0x43F,strlen((char*)gActorXmlStrs+0x43F));
Actor_LoadAnim(arg0,String_CStr(&anim),*(s32*)((u8*)arg0+0x188),0,1);
String_AssignCStr((u8*)arg0+0x160,(char*)gActorXmlStrs+0x4ED,strlen((char*)gActorXmlStrs+0x4ED));
move[2]=lbl_8036A184;move[1]=lbl_8036A184;move[0]=lbl_8036A184;
scale=*(f32*)((u8*)arg0+0x150);
((void (*)(void *,void *,s32))(*(void ***)((u8*)arg0+0x40))[14])(&current,arg0,0);
px=current[0];
other = ((ActorMotionInterface*)*(void **)((u8*)arg0+0x118))->GetPos(0);
origin[0]=px;origin[1]=lbl_8036A184;origin[2]=lbl_8036A184;
dir[0]=-*(f32*)((u8*)arg0+0x60);dir[1]=lbl_8036A184;dir[2]=lbl_8036A184;
fn_802031E8(&dir,&dir);fn_802031CC(&dir,&dir,scale);fn_80203184(&origin,&dir,&result);
move[1]=lbl_8036A184;move[0]=result[0];move[2]=lbl_8036A184;
*(u32*)&copy[0]=*(u32*)&move[0];*(u32*)&copy[1]=*(u32*)&move[1];*(u32*)&copy[2]=*(u32*)&move[2];
((ActorMotionInterface*)arg0)->Adjust(&copy,*(f32*)((u8*)gGame+0xF0),lbl_8036A184);
*(s32*)((u8*)arg0+0x140)=0;
{
f32 rate=*(f32*)((u8*)gGame+0xF8);
s32 frames=(s32)*(f32*)((u8*)gGame+0xF4);
fn_800E4BE0(arg0,frames,*(s32*)((u8*)gGame+0xFC),rate);
}
switch(*(s32*)((u8*)*(void **)((u8*)arg0+0x118)+0x144)){
case 3: SeCue_PlayAt((char*)gActorXmlStrs+0x305,100,x,y,z);
case 2: SeCue_PlayAt((char*)gActorXmlStrs+0x31D,100,x,y,z);
SeCue_PlayAt((char*)gActorXmlStrs+0x334,100,x,y,z);break;
case 1: SeCue_PlayAt((char*)gActorXmlStrs+0x334,100,x,y,z);
default:
if(force) SeCue_PlayAt((char*)gActorXmlStrs+0x31D,100,x,y,z);
else {
void *p=*(void **)((u8*)*(void **)((u8*)arg0+0x118)+0x11C);
kind=p?fn_80199310(p):0;
switch(kind){
case 0:case 2:case 5:case 7:case 10:
if(*(s32*)((u8*)*(void **)((u8*)arg0+0x118)+0x140)==0) SeCue_PlayAt((char*)gActorXmlStrs+0x34C,100,x,y,z);
else SeCue_PlayAt((char*)gActorXmlStrs+0x361,100,x,y,z);break;
case 1:case 3:case 6:SeCue_PlayAt((char*)gActorXmlStrs+0x374,100,x,y,z);break;
case 4:case 8:case 11:SeCue_PlayAt((char*)gActorXmlStrs+0x34C,100,x,y,z);break;
default:SeCue_PlayAt((char*)gActorXmlStrs+0x34C,100,x,y,z);break;
}
}
}
if(mode==1) {
String_Init(&se6,(char*)gActorXmlStrs+0x4F6,&scratch6);
{
void *obj=fn_800E7E4C(*(void **)((u8*)arg0+0xAC),&se6);
fn_800DBF38(obj,60,lbl_8036A18C,lbl_8036A18C);
}
String_Destroy(&se6,-1);
String_Init(&se5,(char*)gActorXmlStrs+0x4FD,&scratch5);
{
void *obj=fn_800E7E4C(*(void **)((u8*)arg0+0xAC),&se5);
fn_800DBF38(obj,60,lbl_8036A18C,lbl_8036A18C);
}
String_Destroy(&se5,-1);
fn_80025624(gPadInput,16);
}
else if(mode==2) {
String_Init(&se4,(char*)gActorXmlStrs+0x4F6,&scratch4);
{
void *obj=fn_800E7E4C(*(void **)((u8*)arg0+0xAC),&se4);
fn_800DBF38(obj,60,lbl_8036A1C4,lbl_8036A18C);
}
String_Destroy(&se4,-1);
String_Init(&se3,(char*)gActorXmlStrs+0x4FD,&scratch3);
{
void *obj=fn_800E7E4C(*(void **)((u8*)arg0+0xAC),&se3);
fn_800DBF38(obj,60,lbl_8036A1C4,lbl_8036A18C);
}
String_Destroy(&se3,-1);
fn_80025624(gPadInput,16);
}
else if(mode==3) {
String_Init(&se2,(char*)gActorXmlStrs+0x4F6,&scratch2);
{
void *obj=fn_800E7E4C(*(void **)((u8*)arg0+0xAC),&se2);
fn_800DBF38(obj,60,lbl_8036A1CC,lbl_8036A18C);
}
String_Destroy(&se2,-1);
String_Init(&se1,(char*)gActorXmlStrs+0x4FD,&scratch1);
{
void *obj=fn_800E7E4C(*(void **)((u8*)arg0+0xAC),&se1);
fn_800DBF38(obj,60,lbl_8036A1CC,lbl_8036A18C);
}
String_Destroy(&se1,-1);
fn_80025624(gPadInput,16);
}
else fn_80025624(gPadInput,8);
*(u8*)((u8*)arg0+0x1A4)=1;*(u8*)((u8*)arg0+0x1A0)=0;
String_Destroy(&anim,-1);
}
  #pragma pop
  #pragma cplusplus off
void fn_80115264(void *self, s32 mode, s32 flag)
{
  s32 strlen(char *);
  void *new_var4;
  s32 fn_80199310(void *);
  s32 fn_800DDC04(void *, void *);
  void String_Concat(void *, void *, void *);
  void fn_800C992C(void *, char *, s32);
  char *new_var2;
  String spC8;
  String spBC;
  String spB0;
  String spA4;
  String sp98;
  String sp8C;
  String sp80;
  String sp74;
  String sp68;
  String sp5C;
  String sp50;
  String sp44;
  String sp38;
  String sp2C;
  String sp20;
  s32 sc1C;
  s32 sc18;
  s32 sc14;
  s32 sc10;
  s32 scC;
  u8 *new_var;
  void *new_var3;
  s32 sc8;
  s32 kind;
  u32 ok;
  u8 saved;
  spC8.cap = 0;
  spBC.cap = 0;
  spC8.size = 0;
  spC8.data = 0;
  spC8.cap = 0;
  spBC.size = 0;
  spBC.data = 0;
  spBC.cap = 0;
  new_var4 = (void *) spC8.size;
  *((u8 *) (((s8 *) self) + 0x1A8)) = 1;
  *((s32 *) (((s8 *) self) + 0x144)) = mode;
  switch (mode)
  {
    case 0:
    {
      s32 n = strlen(((char *) gActorXmlStrs) + 0x505);
      String_AssignCStr(&spC8, ((char *) gActorXmlStrs) + 0x505, n);
      break;
    }

    case 1:
      new_var3 = self;
    {
      s32 n = strlen(((char *) gActorXmlStrs) + 0x50A);
      String_AssignCStr(&spC8, ((char *) gActorXmlStrs) + 0x50A, n);
      *((s32 *) (((s8 *) new_var3) + 0x140)) = 0;
      break;
    }

    case 2:
    {
      s32 n = strlen(((char *) gActorXmlStrs) + 0x50A);
      String_AssignCStr(&spC8, ((char *) gActorXmlStrs) + 0x50A, n);
      *((s32 *) (((s8 *) self) + 0x140)) = 1;
      break;
    }

    case 3:
    {
      s32 n = strlen(((char *) gActorXmlStrs) + 0x50F);
      String_AssignCStr(&spC8, ((char *) gActorXmlStrs) + 0x50F, n);
      *((s32 *) (((s8 *) self) + 0x140)) = 0;
      if (*((s32 *) (((s8 *) new_var3) + 0x19C)))
      {
        *((u8 *) (((s8 *) self) + 0x1A8)) = 0;
      }
      break;
    }

    case 4:
    {
      s32 n = strlen(((char *) gActorXmlStrs) + 0x46A);
      String_AssignCStr(&spC8, ((char *) gActorXmlStrs) + 0x46A, n);
      *((s32 *) (((s8 *) new_var3) + 0x140)) = 0;
      break;
    }

    case 5:
    {
      s32 n = strlen(((char *) gActorXmlStrs) + 0x46F);
      String_AssignCStr(&spC8, ((char *) gActorXmlStrs) + 0x46F, n);
      *((s32 *) (((s8 *) self) + 0x140)) = 0;
      break;
    }
      new_var2 = (char *) gActorXmlStrs;

    case 6:
    {
      s32 n = strlen(new_var2 + 0x46F);
      String_AssignCStr(&spC8, ((char *) gActorXmlStrs) + 0x46F, n);
      *((s32 *) (((s8 *) self) + 0x140)) = 0;
      break;
    }

    case 7:
    {
      s32 n = strlen(((char *) gActorXmlStrs) + 0x478);
      String_AssignCStr(&spC8, new_var2 + 0x478, n);
      *((s32 *) (((s8 *) new_var3) + 0x140)) = 0;
      break;
    }

  }

  if (mode < 3)
  {
    if (!(*((s32 *) (((s8 *) self) + 0x140))))
    {
      s32 n = strlen(new_var2 + 0x514);
      fn_800C992C(&spC8, ((char *) gActorXmlStrs) + 0x514, n);
    }
    else
    {
      s32 n = strlen(((char *) gActorXmlStrs) + 0x516);
      fn_800C992C(&spC8, ((char *) gActorXmlStrs) + (kind = 0x516), n);
    }
  }
  if (String_Compare(&spC8, 0, new_var4, new_var2 + 0x518, strlen(new_var2 + 0x518)) == 0)
  {
    String_Init(&sp80, String_CStr(&spC8), &sc18);
    String_Concat(&sp8C, ((u8 *) self) + 0x154, &sp80);
    ok = fn_800DDC04(*((void **) (((s8 *) new_var3) + 0xDC)), &sp8C) != 0;
    String_Destroy(&sp8C, -1);
    String_Destroy(&sp80, -1);
    if (!ok)
    {
      s32 n = strlen(new_var2 + 0x51E);
      String_AssignCStr(&spC8, ((char *) gActorXmlStrs) + 0x51E, n);
    }
  }
  if (String_Compare(&spC8, 0, new_var4, ((char *) gActorXmlStrs) + 0x524, strlen(((char *) gActorXmlStrs) + 0x524)) == 0)
  {
    String_Init(&sp68, String_CStr(&spC8), &sc14);
    String_Concat(&sp74, ((u8 *) new_var3) + 0x154, &sp68);
    ok = fn_800DDC04(*((void **) (((s8 *) new_var3) + 0xDC)), &sp74) != 0;
    String_Destroy(&sp74, -1);
    String_Destroy(&sp68, -1);
    if (!ok)
    {
      s32 n = strlen(new_var2 + 0x52A);
      String_AssignCStr(&spC8, new_var2 + 0x52A, n);
    }
  }
  if (String_Compare(&spC8, 0, new_var4, new_var2 + 0x50F, strlen(((char *) gActorXmlStrs) + 0x50F)) == 0)
  {
    String_Init(&sp50, String_CStr(&spC8), &sc10);
    String_Concat(&sp5C, ((u8 *) new_var3) + 0x154, &sp50);
    ok = fn_800DDC04(*((void **) (((s8 *) self) + 0xDC)), &sp5C) != 0;
    String_Destroy(&sp5C, -1);
    String_Destroy(&sp50, -1);
    if (!ok)
    {
      s32 n = strlen(((char *) gActorXmlStrs) + 0x51E);
      String_AssignCStr(&spC8, new_var2 + 0x51E, n);
    }
  }
  if (String_Compare(&spC8, 0, new_var4, new_var2 + 0x478, strlen(((char *) gActorXmlStrs) + 0x478)) == 0)
  {
    String_Init(&sp38, String_CStr(&spC8), &scC);
    String_Concat(&sp44, ((u8 *) self) + 0x154, &sp38);
    ok = fn_800DDC04(*((void **) (((s8 *) self) + 0xDC)), &sp44) != 0;
    String_Destroy(&sp44, -1);
    String_Destroy(&sp38, -1);
    if (!ok)
    {
      s32 n = strlen(((char *) gActorXmlStrs) + 0x46A);
      String_AssignCStr(&spC8, new_var2 + 0x46A, n);
    }
  }
  saved = *((u8 *) (((s8 *) self) + 0x1A2));
  if ((((*((u8 *) (((s8 *) (*((void **) (((s8 *) self) + 0x118)))) + 0x1B6))) && (!(*((u8 *) (((s8 *) self) + 0x1B6))))) && ((*((s32 *) (((s8 *) new_var3) + 0x1B8))) == 1)) != 0U)
  {
    if (saved)
    {
      *((u8 *) (((s8 *) self) + 0x1A2)) = 0;
    }
    else
    {
      *((u8 *) (((s8 *) new_var3) + 0x1A2)) = 1;
    }
  }
  String_Assign(&spBC, &spC8, 0, -1);
  {
    void (*format_anim)(void *, void *, void *) = (void (*)(void *, void *, void *)) fn_801134EC;
    format_anim(&spB0, new_var3, &spC8);
  }
  String_Assign(&spC8, &spB0, 0, -1);
  String_Destroy(&spB0, -1);
  Actor_LoadAnim(new_var3, String_CStr(&spC8), *((s32 *) (((s8 *) self) + 0x188)), 0, 1);
  String_Assign(((u8 *) new_var3) + 0x160, &spBC, 0, -1);
  *((u8 *) (((s8 *) self) + 0x1A2)) = saved;
  if (mode)
  {
    *((s32 *) (((s8 *) new_var3) + 0x140)) = 0;
  }
  else
  {
    (*((s32 *) (((s8 *) new_var3) + 0x140)))++;
    if (((*((s32 *) (((s8 *) self) + 0x140))) - 1) >= 1)
    {
      *((s32 *) (((s8 *) self) + 0x140)) = 0;
    }
  }
  *((u8 *) (((s8 *) new_var3) + 0x1A4)) = 1;
  String_Init(&sp20, ((char *) gActorXmlStrs) + 0x518, &sc8);
  String_Concat(&sp2C, ((u8 *) new_var3) + 0x154, &sp20);
  new_var = (u8 *) new_var3;
  ok = fn_800DDC04(*((void **) (((s8 *) new_var3) + 0xDC)), &sp2C) != 0;
  String_Destroy(&sp2C, -1);
  String_Destroy(&sp20, -1);
  if (!ok)
  {
    *((s32 *) (((s8 *) new_var3) + 0x140)) = 0;
    flag = 0;
  }
  if (flag)
  {
    s32 n = strlen(((char *) gActorXmlStrs) + 0x1C);
    String_AssignCStr(new_var + 0x16C, new_var2 + 0x1C, n);
  }
  else
  {
    String_Init(&spA4, new_var2 + 0x43F, &sc1C);
    {
      void (*format_anim)(void *, void *, void *) = (void (*)(void *, void *, void *)) fn_801134EC;
      format_anim(&sp98, self, &spA4);
    }
    String_Assign(((u8 *) self) + 0x16C, &sp98, 0, -1);
    String_Destroy(&sp98, -1);
    String_Destroy(&spA4, -1);
  }
  if (((*((u8 *) (((s8 *) new_var3) + 0x1A1))) && (mode == 2)) && (String_Compare(new_var + 0xB0, 0, *((void **) (((s8 *) self) + 0xB0)), new_var2 + 0x530, strlen(((char *) gActorXmlStrs) + 0x530)) != 0))
  {
    *((u8 *) (((s8 *) new_var3) + 0x1B5)) = 1;
  }
  if (((*((u8 *) (((s8 *) new_var3) + 0x1A1))) && (mode == 2)) && (String_Compare(new_var + 0xB0, 0, *((void **) (((s8 *) new_var3) + 0xB0)), new_var2 + 0x530, strlen(new_var2 + 0x530)) == 0))
  {
    if (*((void **) (((s8 *) new_var3) + 0x11C)))
    {
      kind = fn_80199310(*((void **) (((s8 *) new_var3) + 0x11C)));
    }
    else
    {
      kind = -1;
    }
    if (kind == 2)
    {
      *((u8 *) (((s8 *) new_var3) + 0x1B5)) = 1;
    }
  }
  if (*((s32 *) (((s8 *) self) + 0x19C)))
  {
    *((u8 *) (((s8 *) self) + 0x1A0)) = 1;
  }
  String_Destroy(&spBC, -1);
  String_Destroy(&spC8, -1);
}

#pragma global_optimizer off
s32 fn_80115AF0(void *actor) {
    s32 n;
    extern u16 gActorXmlStrs[];
    s32 strlen(char *);
    s32 String_Compare(void *, s32, void *, char *, s32);
    s32 String_Find(void *, char *, s32, s32);

    n = strlen((char *)gActorXmlStrs + 0x4ED);
    if (String_Compare((u8 *)actor + 0x160, 0, (void *)*(s32 *)((u8 *)actor + 0x160),
                      (char *)gActorXmlStrs + 0x4ED, n) == 0 ||
        (n = strlen((char *)gActorXmlStrs + 0x444),
         String_Compare((u8 *)actor + 0x160, 0, (void *)*(s32 *)((u8 *)actor + 0x160),
                        (char *)gActorXmlStrs + 0x444, n) == 0)) {
        n = strlen((char *)gActorXmlStrs + 0x43F);
        if (String_Compare((u8 *)actor + 0x178, 0, (void *)*(s32 *)((u8 *)actor + 0x178),
                          (char *)gActorXmlStrs + 0x43F, n) == 0 ||
            (u32)(String_Find((u8 *)actor + 0x178, (char *)gActorXmlStrs + 0x43F, 0,
                             strlen((char *)gActorXmlStrs + 0x43F)) + 0x10000) != 0xFFFF) {
            return 1;
        }
        return 0;
    }
    return 0;
}
#pragma global_optimizer on

#pragma push
#pragma cplusplus on
#pragma optimization_level 4
#pragma opt_loop_invariants off
extern "C" s32 fn_80115C0C(void *arg0, s32 arg1) {
    s32 strlen(char *);
    void String_AssignCStr(void *, char *, s32);
    s32 String_Compare(void *, s32, s32, char *, s32);
    void String_Init(void *, char *, void *);
    void String_Concat(void *, void *, void *);
    s32 fn_800DDC04(void *, void *);
    void String_Destroy(void *, s32);
    void Actor_ClearBusy(void *);
    void fn_80111740(void *);
    void Actor_LoadAnim(void *, char *, s32, s32, s32);
    void fn_80203184(f32 *, f32 *, f32 *);
    void fn_802031CC(f32 *, f32 *, f32);
    f32 PSVECDistance(f32 *, f32 *);
    extern u16 gActorXmlStrs[];
    extern void *gGame;
    extern f32 lbl_8036A184;
    extern f32 lbl_8036A1D0;
    extern f32 lbl_8036A1D4;

    typedef struct { f32 x, y, z; } Vec3f;
    typedef struct { u32 x, y, z; } U3;
    typedef void (*GetPosFn)(Vec3f *, void *, s32);
    typedef u8 (*BoolFn)(void *);
    typedef void (*AdjustFn)(void *, Vec3f *, f32, f32);


    U3 spA8;
    U3 sp9C;
    u8 sp90[0xC];
    u8 sp84[0xC];
    Vec3f sp78, sp6C, sp60, sp54;
    Vec3f sp48, sp3C;
    Vec3f sp30, sp24;
    f32 sp18[3];
    f32 spC[3];
    u8 sp8[4];
    f32 dist;
    f32 pad;
    void *other;
    s32 ret;
    u8 doMove;
    u32 ok;

    *(f32 *)&spA8.z = lbl_8036A184;
    *(f32 *)&spA8.y = lbl_8036A184;
    doMove = 0;
    *(f32 *)&spA8.x = lbl_8036A184;
    ret = 0;
    String_AssignCStr((u8 *)arg0 + 0x16C, (char *)&gActorXmlStrs + 0x1C, strlen((char *)&gActorXmlStrs + 0x1C));
    other = *(void **)((u8 *)arg0 + 0x118);
    if (other == 0) return 1;
    if (*(u8 *)((u8 *)arg0 + 0x195) != 0) return 1;
    if (*(s32 *)((u8 *)arg0 + 0x12C) != 0 && arg1 == 0 && *(s32 *)((u8 *)arg0 + 0x140) == 0) {
        Actor_ClearBusy(arg0); return 1;
    }
    if (*(s32 *)((u8 *)arg0 + 0x130) != 0 && arg1 == 0 && *(s32 *)((u8 *)arg0 + 0x140) != 0) {
        Actor_ClearBusy(arg0); return 1;
    }
    if (*(s32 *)((u8 *)arg0 + 0x134) != 0 && arg1 == 1) {
        Actor_ClearBusy(arg0); return 1;
    }
    if (*(s32 *)((u8 *)arg0 + 0x138) != 0 && arg1 == 2) {
        Actor_ClearBusy(arg0); return 1;
    }
    if (*(s32 *)((u8 *)arg0 + 0x13C) != 0 && arg1 == 3) {
        Actor_ClearBusy(arg0); return 1;
    }
    if (other == 0) {
        dist = lbl_8036A184;
    } else {
        sp3C.x = sp3C.y = sp3C.z = lbl_8036A184;
        sp48.x = sp48.y = sp48.z = lbl_8036A184;
        ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp6C, arg0, 0);
        sp54 = sp6C;
        sp3C = sp6C;
        ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&sp78, other, 0);
        sp48 = sp78;
        sp60 = sp78;
        dist = PSVECDistance((f32 *)&sp54, (f32 *)&sp60);
    }
    pad = lbl_8036A1D4;
    if (String_Compare((u8 *)arg0 + 0xB0, 0, *(s32 *)((u8 *)arg0 + 0xB0), (char *)&gActorXmlStrs + 0x15F, strlen((char *)&gActorXmlStrs + 0x15F)) == 0) {
        pad = lbl_8036A1D0;
    }
    if (dist <= pad + (*(f32 *)((u8 *)arg0 + 0x128) + *(f32 *)((u8 *)arg0 + 0x1B0))) {
        Actor_ClearBusy(arg0); return 1;
    }
    if (((ActorMotionInterface *)arg0)->IsBusy() == 0
        && dist > (*(f32 *)((u8 *)arg0 + 0x128) + *(f32 *)((u8 *)arg0 + 0x1B0))
        && *(u8 *)((u8 *)arg0 + 0x1A4) != 0
        && *(u8 *)((u8 *)arg0 + 0x1A5) == 0) {
        *(u8 *)((u8 *)arg0 + 0x184) = 1;
        Actor_LoadAnim(arg0, (char *)&gActorXmlStrs + 0x535, *(s32 *)((u8 *)arg0 + 0x188), 0, 1);
        *(s32 *)((u8 *)arg0 + 0x140) = 0;
        String_AssignCStr((u8 *)arg0 + 0x160, (char *)&gActorXmlStrs + 0x535, strlen((char *)&gActorXmlStrs + 0x535));
        return 1;
    }
    if (*(u8 *)((u8 *)arg0 + 0x1A4) != 0) {
        Actor_ClearBusy(arg0); return 1;
    }
    if (String_Compare((u8 *)arg0 + 0x178, 0, *(s32 *)((u8 *)arg0 + 0x178), (char *)&gActorXmlStrs + 0x53A, strlen((char *)&gActorXmlStrs + 0x53A)) == 0
        || String_Compare((u8 *)arg0 + 0x178, 0, *(s32 *)((u8 *)arg0 + 0x178), (char *)&gActorXmlStrs + 0x43F, strlen((char *)&gActorXmlStrs + 0x43F)) == 0) {
        String_Init(sp84, (char *)&gActorXmlStrs + 0x53F, sp8);
        String_Concat(sp90, (u8 *)arg0 + 0x154, sp84);
        ok = fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), sp90) != 0;
        String_Destroy(sp90, -1);
        String_Destroy(sp84, -1);
        if (ok) {
            *(u8 *)((u8 *)arg0 + 0x184) = 1;
            Actor_LoadAnim(arg0, (char *)&gActorXmlStrs + 0x53F, *(s32 *)((u8 *)arg0 + 0x18C), 0, 1);
            fn_80111740(arg0);
            goto move_actor;
        }
    }
    if (String_Compare((u8 *)arg0 + 0x178, 0, *(s32 *)((u8 *)arg0 + 0x178), (char *)&gActorXmlStrs + 0x53F, strlen((char *)&gActorXmlStrs + 0x53F)) == 0) {
        if (*(u8 *)((u8 *)arg0 + 0xD0) == 0) {
            *(u8 *)((u8 *)arg0 + 0x184) = 1;
            Actor_LoadAnim(arg0, (char *)&gActorXmlStrs + 0xFE, *(s32 *)((u8 *)arg0 + 0x18C), 1, 1);
            String_AssignCStr((u8 *)arg0 + 0x160, (char *)&gActorXmlStrs + 0xFE, strlen((char *)&gActorXmlStrs + 0xFE));
            doMove = 1;
            ret = 1;
        }
    } else {
        *(u8 *)((u8 *)arg0 + 0x184) = 1;
        if (*(s32 *)((u8 *)arg0 + 0x19C) == 0) {
            Actor_LoadAnim(arg0, (char *)&gActorXmlStrs + 0xFE, *(s32 *)((u8 *)arg0 + 0x18C), 0, 1);
            String_AssignCStr((u8 *)arg0 + 0x160, (char *)&gActorXmlStrs + 0xFE, strlen((char *)&gActorXmlStrs + 0xFE));
            fn_80111740(arg0);
            doMove = 1;
            ret = 0;
        } else {
            Actor_LoadAnim(arg0, (char *)&gActorXmlStrs + 0xFE, *(s32 *)((u8 *)arg0 + 0x18C), 0, 1);
            String_AssignCStr((u8 *)arg0 + 0x160, (char *)&gActorXmlStrs + 0x1C, strlen((char *)&gActorXmlStrs + 0x1C));
            fn_80111740(arg0);
            doMove = 0;
            *(u8 *)((u8 *)arg0 + 0x1A0) = 1;
            ret = 1;
            *(u8 *)((u8 *)arg0 + 0x1A4) = 1;
        }
    }
move_actor:
    if (doMove != 0) {
        f32 px;
        f32 x, y, z;
        f32 scale;
        *(u8 *)((u8 *)arg0 + 0x195) = 1;
        scale = *(f32 *)((u8 *)gGame + 0xDC);
        if (*(void **)((u8 *)arg0 + 0x118) == 0) {
            x = *(f32 *)((u8 *)arg0 + 0x48);
            y = lbl_8036A184;
            z = *(f32 *)((u8 *)arg0 + 0x50);
        } else {
            void *oth;

            ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp24, arg0, 0);
            px = sp24.x;
            oth = *(void **)((u8 *)arg0 + 0x118);
            ((GetPosFn)((void **)*(void **)((u8 *)oth + 0x40))[0xE])(&sp30, oth, 0);
            spC[1] = lbl_8036A184;
            spC[2] = lbl_8036A184;
            spC[0] = sp30.x - (px - *(f32 *)((u8 *)arg0 + 0x48));
            sp18[1] = lbl_8036A184;
            sp18[2] = lbl_8036A184;
            sp18[0] = -*(f32 *)((u8 *)arg0 + 0x60);
            fn_802031CC(sp18, sp18, *(f32 *)((u8 *)arg0 + 0x128) * scale);
            fn_80203184(spC, sp18, spC);
            y = lbl_8036A184;
            x = spC[0];
            z = lbl_8036A184;
        }
        *(f32 *)&spA8.y = y;
        *(f32 *)&spA8.x = x;
        *(f32 *)&spA8.z = z;
        sp9C = spA8;
        ((ActorMotionInterface *)arg0)->Adjust(&sp9C, *(f32 *)((u8 *)arg0 + 0x124), lbl_8036A184);
        *(s32 *)((u8 *)arg0 + 0x140) = 0;
        *(u8 *)((u8 *)arg0 + 0x1A4) = 1;
    }
    return ret;
}
#pragma pop
#pragma cplusplus off

#pragma global_optimizer off
void fn_8011631C(void *arg0, s8 arg1)
{
    String sp24;
    String sp18;
    String spC;
    s32 sp8;
    u8 flag;
    s32 n;
    s32 n2;
    extern u16 gActorXmlStrs[];
    s32 strlen(char *);
    s32 String_Compare(void *, s32, void *, char *, s32);
    s32 String_Find(void *, char *, s32, s32);
    u8 Actor_IsBusy(void *);
    void String_Init(void *, char *, void *);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_AssignCStr(void *, char *, s32);
    void *String_CStr(void *);
    void fn_801134EC(void *, void *, void *);
    void Actor_LoadAnim(void *, void *, s32, s32, s32);

    sp24.size = 0;
    sp24.cap = 0;
    sp24.data = 0;
    sp24.cap = 0;

    n = strlen((char *)gActorXmlStrs + 0x43F);
    if (String_Compare((u8 *)arg0 + 0x178, 0, (void *)*(s32 *)((u8 *)arg0 + 0x178),
                       (char *)gActorXmlStrs + 0x43F, n) == 0
        || (u32)(String_Find((u8 *)arg0 + 0x178, (char *)gActorXmlStrs + 0x43F, 0,
                             strlen((char *)gActorXmlStrs + 0x43F)) + 0x10000) != 0xFFFF
        || ((u32)(String_Find((u8 *)arg0 + 0x178, (char *)gActorXmlStrs + 0x444, 0,
                              strlen((char *)gActorXmlStrs + 0x444)) + 0x10000) != 0xFFFF
            && Actor_IsBusy(arg0) == 0)) {
        flag = 1;
    } else {
        flag = 0;
    }

    if (flag == 0 && *(u8 *)((u8 *)arg0 + 0x1A6) == 0) {
        String_Init(&sp18, (char *)gActorXmlStrs + 0x43F, &sp8);
        fn_801134EC(&spC, arg0, &sp18);
        String_Assign(&sp24, &spC, 0, -1);
        String_Destroy(&spC, -1);
        String_Destroy(&sp18, -1);
        *(u8 *)((u8 *)arg0 + 0x184) = arg1;

        n2 = strlen((char *)gActorXmlStrs + 0x43F);
        if (String_Compare(&sp24, 0, (void *)sp24.size, (char *)gActorXmlStrs + 0x43F, n2) == 0) {
            Actor_LoadAnim(arg0, String_CStr(&sp24), *(s32 *)((u8 *)arg0 + 0x190), 1, 1);
        } else {
            Actor_LoadAnim(arg0, String_CStr(&sp24), *(s32 *)((u8 *)arg0 + 0x188), 0, 1);
            String_AssignCStr((u8 *)arg0 + 0x16C, (char *)gActorXmlStrs + 0x43F,
                              strlen((char *)gActorXmlStrs + 0x43F));
        }
    }

    *(u8 *)((u8 *)arg0 + 0x1A8) = 0;
    String_Destroy(&sp24, -1);
}
#pragma global_optimizer reset
s32 fn_8011654C(void *arg0) {
    s32 fn_801992F0(void *);
    void *v;

    v = *(void **)((u8 *)arg0 + 0x11C);
    if (v != NULL) {
        return fn_801992F0(v);
    }
    return 0;
}

s32 fn_80116580(void *arg0) {
    s32 fn_80199310(void *);
    void *v;

    v = *(void **)((u8 *)arg0 + 0x11C);
    if (v != NULL) {
        return fn_80199310(v);
    }
    return -1;
}

#pragma peephole off
void *fn_801165B4(void *arg0, void *arg1) {
    void fn_80199318(void *, void *);
    u8 sp8[8];
    void *self;
    void *v;

    self = arg0;
    v = *(void **)((u8 *)arg1 + 0x11C);
    if (v != NULL) {
        fn_80199318(self, v);
    } else {
        String_Init(self, (char *)((u8 *)gActorXmlStrs + 0x1C), sp8);
    }
    return self;
}
#pragma peephole reset
s32 fn_80116604(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x11C);
}

void fn_8011660C(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1B8) = arg1;
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1B8) > 1) {
        M2C_FIELD(arg0, s8 *, 0x1A4) = 1;
        M2C_FIELD(arg0, s8 *, 0x1A5) = 1;
    }
}

void fn_8011662C(void *arg0, s32 arg1) {
    s32 fn_80165B04(s32);
    s32 fn_80165B0C(s32);
    M2C_UNK fn_801C4468(s32);
    M2C_UNK fn_801C6008(s32);
    s32 temp_r3;

    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x1CC) = fn_80165B0C(arg1);
        M2C_FIELD(arg0, s32 *, 0x1D0) = fn_80165B04(arg1);
        if ((s32) M2C_FIELD(arg0, s32 *, 0x1CC) == 2) {
            fn_801C4468(M2C_FIELD(arg0, s32 *, 0xE0));
        }
        temp_r3 = M2C_FIELD(arg0, s32 *, 0x1CC);
        if (((temp_r3 == 1) && ((s32) M2C_FIELD(arg0, s32 *, 0x1D0) == 1)) || ((temp_r3 == 3) && ((s32) M2C_FIELD(arg0, s32 *, 0x1D0) == 3))) {
            fn_801C6008(M2C_FIELD(arg0, s32 *, 0xE0));
        }
    }
}

#pragma cplusplus on
extern "C" void fn_801166C4(void *arg0, void *arg1) {
    struct Obj {
        u8 pad[0x40];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7(f32, f32, f32) = 0;
        virtual void v8() = 0;
        virtual void v9(f32, f32, f32) = 0;
    };
    extern f32 lbl_8036A184;
    extern u16 gActorXmlStrs[];

    void fn_800DF670(void *);
    void fn_800E4FE8(void *, void *, void *);

    u8 *obj;
    Obj *ptr;
    f32 value;

    obj = (u8 *)arg0;

    if (arg1 != NULL) {
        *(void **)(obj + 0x120) = arg1;
    }

    ptr = *(Obj **)(obj + 0x120);

    if (ptr != NULL) {
        value = lbl_8036A184;
        ptr->v7(value, value, value);

        ptr = *(Obj **)(obj + 0x120);
        value = lbl_8036A184;
        ptr->v9(value, value, value);

        fn_800DF670(*(void **)(obj + 0x120));

        fn_800E4FE8(
            *(void **)(obj + 0x120),
            obj,
            (u8 *)gActorXmlStrs + 0xF5
        );
    }
}
#pragma cplusplus reset
void fn_80116760(s32 arg0, s32 arg1) {
    extern u16 gActorXmlStrs[];
    s32 sp8;

    String_ConcatCStr(&sp8, arg1, (u8 *)gActorXmlStrs + 0xfc);
    String_Assign((void *)(arg0 + 0x154), &sp8, 0, -1);
    String_Destroy(&sp8, -1);
}

void fn_801167BC(void *actor, u32 arg1) {
    void *scratch;
    String str24;
    String str18;
    String strC;
    s32 kind;
    s32 fn_80199310(void *);
    void fn_800DF670(void *);
    void fn_800E4FE8(void *, void *, char *);
    char *fn_801992F8(void *);
    void String_JoinCStr(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    s32 fn_800DDAA4(void *, void *);

    if (arg1 != 0) {
        *(u32 *)((u8 *)actor + 0x11C) = arg1;
    }
    if (*(u32 *)((u8 *)actor + 0x11C) != 0) {
        kind = fn_80199310(*(void **)((u8 *)actor + 0x11C));
        fn_800DF670(*(void **)((u8 *)actor + 0x11C));
        if (kind == 3) {
            fn_800E4FE8(*(void **)((u8 *)actor + 0x11C), actor, (char *)gActorXmlStrs + 0xEE);
        } else {
            fn_800E4FE8(*(void **)((u8 *)actor + 0x11C), actor, (char *)gActorXmlStrs + 0xF5);
        }
        String_Init(&str24, (char *)gActorXmlStrs + 0xFC, &scratch);
        String_JoinCStr(&str18, fn_801992F8(*(void **)((u8 *)actor + 0x11C)), &str24);
        String_Assign((u8 *)actor + 0x154, &str18, 0, -1);
        String_Destroy(&str18, -1);
        String_Destroy(&str24, -1);
    }
    String_ConcatCStr(&strC, (u8 *)actor + 0x154, (char *)gActorXmlStrs + 0xFE);
    kind = fn_800DDAA4(*(void **)((u8 *)actor + 0xDC), &strC) == 0;
    String_Destroy(&strC, -1);
    if ((u8)kind != 0) {
        *(u8 *)((u8 *)actor + 0x1A4) = 1;
    }
}

void fn_801168F4(void *arg0, char *arg1) {
    void String_Destroy(void *, s32);
    void String_Init(void *, char *, void *);
    s32 fn_800E7DA4(s32, void *);
    M2C_UNK spC;
    M2C_UNK sp8;

    String_Init(&spC, arg1, &sp8);
    *(s32 *)((u8 *)arg0 + 0x118) = fn_800E7DA4(*(s32 *)((u8 *)arg0 + 0xAC), &spC);
    String_Destroy(&spC, -1);
}

#pragma cplusplus on
extern "C" void fn_80116944(void *arg0) {
    struct Obj {
        u8 pad[0x40];
        virtual void v0();
        virtual void v1();
    };
    void fn_800608AC(s32);
    fn_800608AC(M2C_FIELD(arg0, s32 *, 0xE0));
    ((Obj *)arg0)->v1();
}

#pragma push
#pragma optimization_level 4
#pragma global_optimizer on
#pragma opt_common_subs off
#pragma opt_lifetimes off
extern "C" void fn_80116988(void *arg0, s32 arg1, f32 farg0) {
    s32 strlen(char *);
    void String_AssignCStr(void *, char *, u32);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_ConcatCStr(void *, void *, char *);
    s32 fn_800DDAA4(void *, void *);
    u32 fn_800DDC04(void *, void *);
    extern void *gGame;

    struct Actor {
        u8 pad0[0x40];
        virtual void v0() = 0;
        virtual void Unk() = 0;
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
        virtual Vec3f GetPos(s32) = 0;
        virtual void v13() = 0;
        virtual void Adjust(Vec3f *, f32, f32) = 0;
    };

    typedef void (*GetPosFn)(Vec3f *, void *, s32);

    f32 f31;
    f32 f30;
    f32 f29;
    f32 f28;
    f32 f27;
    f32 f26;
    u8 sp98[0x30];
    String sp8C;
    Vec3f sp80;
    Vec3f sp74;
    String sp68;
    String sp5C;
    String sp50;
    String sp44;
    String sp38;
    Vec3f sp2C;
    Vec3f sp20;
    Vec3f sp14;
    Vec3f sp8;

    sp8C.size = 0;
    sp8C.cap = 0;
    sp8C.data = 0;
    sp8C.cap = 0;

    f30 = farg0;
    {
        void *oth = *(void **)((u8 *)arg0 + 0x118);
        ((GetPosFn)((void **)*(void **)((u8 *)oth + 0x40))[0xE])(&sp74, oth, 0);
    }
    f31 = *(f32 *)((u8 *)arg0 + 0x128) * f30 + sp74.x;

    if (*(s32 *)((u8 *)arg0 + 0x19C) == 0) {
        String_ConcatCStr(&sp68, (u8 *)arg0 + 0x154, (char *)&gActorXmlStrs + 0x53F);
        String_Assign(&sp8C, &sp68, 0, -1);
        String_Destroy(&sp68, -1);
        if (fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), &sp8C) != 0) {
            u32 res;
            f27 = *(f32 *)((u8 *)arg0 + 0x48);
            f28 = *(f32 *)((u8 *)arg0 + 0x4C);
            f29 = *(f32 *)((u8 *)arg0 + 0x50);
            res = fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), &sp8C);
            if (res != 0) {
                f32 z = lbl_8036A184;
                void *e0;
                *(f32 *)((u8 *)arg0 + 0x50) = z;
                *(f32 *)((u8 *)arg0 + 0x4C) = z;
                *(f32 *)((u8 *)arg0 + 0x48) = z;
                e0 = *(void **)((u8 *)arg0 + 0xE0);
                *(u32 *)((u8 *)e0 + 0x44) = res;
                e0 = *(void **)((u8 *)arg0 + 0xE0);
                *(u32 *)((u8 *)e0 + 0x74) = 0;
                ((Actor *)arg0)->Unk();
                fn_8005FEE8(*(void **)((u8 *)arg0 + 0xE0), lbl_8036A1B0);
                fn_800608AC(*(void **)((u8 *)arg0 + 0xE0));
                ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp20, arg0, 0);
                f26 = sp20.x;
            } else {
                f26 = lbl_8036A184;
            }
            *(f32 *)((u8 *)arg0 + 0x48) = f27;
            *(f32 *)((u8 *)arg0 + 0x4C) = f28;
            *(f32 *)((u8 *)arg0 + 0x50) = f29;
        } else {
            f26 = lbl_8036A184;
        }
        String_ConcatCStr(&sp5C, (u8 *)arg0 + 0x154, (char *)&gActorXmlStrs + 0xFE);
        String_Assign(&sp8C, &sp5C, 0, -1);
        String_Destroy(&sp5C, -1);
        {
            s32 daa = fn_800DDAA4(*(void **)((u8 *)arg0 + 0xDC), &sp8C);
            if (daa != 0) {
                *(f32 *)((u8 *)arg0 + 0x48) =
                    f30 * (*(f32 *)((u8 *)arg0 + 0x124) * ((f32)daa * (f32)*(s32 *)((u8 *)arg0 + 0x198))) + f31;
                *(f32 *)((u8 *)arg0 + 0x48) = *(f32 *)((u8 *)arg0 + 0x48) + f26;
            } else {
                *(f32 *)((u8 *)arg0 + 0x48) = lbl_8036A1BC * f30;
            }
        }
    } else {
        f32 tmp;
        String_ConcatCStr(&sp50, (u8 *)arg0 + 0x154, (char *)&gActorXmlStrs + 0xFE);
        String_Assign(&sp8C, &sp50, 0, -1);
        String_Destroy(&sp50, -1);
        f28 = *(f32 *)((u8 *)arg0 + 0x48);
        f27 = *(f32 *)((u8 *)arg0 + 0x4C);
        f26 = *(f32 *)((u8 *)arg0 + 0x50);
        {
            u32 res = fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), &sp8C);
            if (res != 0) {
                f32 z = lbl_8036A184;
                void *e0;
                *(f32 *)((u8 *)arg0 + 0x50) = z;
                *(f32 *)((u8 *)arg0 + 0x4C) = z;
                *(f32 *)((u8 *)arg0 + 0x48) = z;
                e0 = *(void **)((u8 *)arg0 + 0xE0);
                *(u32 *)((u8 *)e0 + 0x44) = res;
                e0 = *(void **)((u8 *)arg0 + 0xE0);
                *(u32 *)((u8 *)e0 + 0x74) = 0;
                ((Actor *)arg0)->Unk();
                fn_8005FEE8(*(void **)((u8 *)arg0 + 0xE0), lbl_8036A1B0);
                fn_800608AC(*(void **)((u8 *)arg0 + 0xE0));
                ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp14, arg0, 0);
                tmp = sp14.x;
            } else {
                tmp = lbl_8036A184;
            }
        }
        *(f32 *)((u8 *)arg0 + 0x48) = f28;
        *(f32 *)((u8 *)arg0 + 0x4C) = f27;
        *(f32 *)((u8 *)arg0 + 0x50) = f26;
        *(f32 *)((u8 *)arg0 + 0x48) = f31 - tmp;
    }

    if ((u8)arg1 != 0) {
        void *oth;
        f32 dx;
        f32 z;
        oth = *(void **)((u8 *)arg0 + 0x118);
        dx = *(f32 *)((u8 *)arg0 + 0x48);
        z = lbl_8036A184;
        dx = dx - *(f32 *)((u8 *)oth + 0x48);
        sp80.y = z;
        sp80.x = dx;
        sp80.z = z;
        PSMTXRotRad(sp98, 0x59, gGame,
                    lbl_8036A1D8 * (*(f32 *)((u8 *)gGame + 0x164) * f30),
                    dx);
        fn_802029C4(sp98, &sp80, &sp80);
        *(f32 *)((u8 *)arg0 + 0x48) =
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x118) + 0x48) + sp80.x;
        *(f32 *)((u8 *)arg0 + 0x4C) =
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x118) + 0x4C) + sp80.y;
        *(f32 *)((u8 *)arg0 + 0x50) =
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x118) + 0x50) + sp80.z;
        *(f32 *)((u8 *)arg0 + 0x58) =
            *(f32 *)((u8 *)gGame + 0x164) * f30 + *(f32 *)((u8 *)arg0 + 0x58);
    }

    {
        f32 tmp;
        String_ConcatCStr(&sp44, (u8 *)arg0 + 0x154, (char *)&gActorXmlStrs + 0x535);
        String_Assign(&sp8C, &sp44, 0, -1);
        String_Destroy(&sp44, -1);
        f28 = *(f32 *)((u8 *)arg0 + 0x48);
        f27 = *(f32 *)((u8 *)arg0 + 0x4C);
        f26 = *(f32 *)((u8 *)arg0 + 0x50);
        {
            u32 res = fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), &sp8C);
            if (res != 0) {
                f32 z = lbl_8036A184;
                void *e0;
                *(f32 *)((u8 *)arg0 + 0x50) = z;
                *(f32 *)((u8 *)arg0 + 0x4C) = z;
                *(f32 *)((u8 *)arg0 + 0x48) = z;
                e0 = *(void **)((u8 *)arg0 + 0xE0);
                *(u32 *)((u8 *)e0 + 0x44) = res;
                e0 = *(void **)((u8 *)arg0 + 0xE0);
                *(u32 *)((u8 *)e0 + 0x74) = 0;
                ((Actor *)arg0)->Unk();
                fn_8005FEE8(*(void **)((u8 *)arg0 + 0xE0), lbl_8036A1B0);
                fn_800608AC(*(void **)((u8 *)arg0 + 0xE0));
                ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp8, arg0, 0);
                tmp = sp8.x;
            } else {
                tmp = lbl_8036A184;
            }
        }
        *(f32 *)((u8 *)arg0 + 0x48) = f28;
        tmp = (f32)__fabs((f64)tmp);
        *(f32 *)((u8 *)arg0 + 0x4C) = f27;
        *(f32 *)((u8 *)arg0 + 0x50) = f26;
        *(f32 *)((u8 *)arg0 + 0x1B0) = tmp;
        *(u8 *)((u8 *)arg0 + 0x1A4) = 0;
    }

    String_ConcatCStr(&sp38, (u8 *)arg0 + 0x154, (char *)&gActorXmlStrs + 0x53A);
    String_Assign(&sp8C, &sp38, 0, -1);
    String_Destroy(&sp38, -1);
    f28 = *(f32 *)((u8 *)arg0 + 0x48);
    f27 = *(f32 *)((u8 *)arg0 + 0x4C);
    f26 = *(f32 *)((u8 *)arg0 + 0x50);
    {
        u32 res = fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), &sp8C);
        if (res != 0) {
            f32 z = lbl_8036A184;
            void *e0;
            *(f32 *)((u8 *)arg0 + 0x50) = z;
            *(f32 *)((u8 *)arg0 + 0x4C) = z;
            *(f32 *)((u8 *)arg0 + 0x48) = z;
            e0 = *(void **)((u8 *)arg0 + 0xE0);
            *(u32 *)((u8 *)e0 + 0x44) = res;
            e0 = *(void **)((u8 *)arg0 + 0xE0);
            *(u32 *)((u8 *)e0 + 0x74) = 0;
            ((Actor *)arg0)->Unk();
            fn_8005FEE8(*(void **)((u8 *)arg0 + 0xE0), lbl_8036A1B0);
            fn_800608AC(*(void **)((u8 *)arg0 + 0xE0));
            ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp2C, arg0, 0);
        }
    }
    *(f32 *)((u8 *)arg0 + 0x48) = f28;
    *(f32 *)((u8 *)arg0 + 0x4C) = f27;
    *(f32 *)((u8 *)arg0 + 0x50) = f26;

    String_AssignCStr((u8 *)arg0 + 0x160, (char *)&gActorXmlStrs + 0x1C,
                strlen((char *)&gActorXmlStrs + 0x1C));
    String_Destroy(&sp8C, -1);
}
#pragma pop
#pragma cplusplus on
#pragma global_optimizer reset
#pragma optimization_level 1

#pragma optimization_level 1
extern "C" void fn_80116F84(void *arg0, s32 *arg1) {
 void fn_800DB7A4(void *, s32 (*)[3]);
 s32 copy[3];
 s32 *src = arg1;
 s32 c = src[2];
 s32 a = src[0];
 s32 b = src[1];
 copy[0]=a; copy[1]=b; copy[2]=c;
 fn_800DB7A4(arg0,&copy);
 if(M2C_FIELD(arg0,u8*,0x195)) M2C_FIELD(arg0,s32*,0x9C)=M2C_FIELD(arg0,s32*,0xC8)*M2C_FIELD(arg0,s32*,0x198);
}
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
extern "C" void fn_80116FE8(void *self) {
 s32 Str_Cmp(void *,char *); void fn_80111C8C(void *,void *);
 void fn_800E5DEC(void *); void fn_800DBAB8(void *,void *); void fn_800DF664(void *);
 s32 strlen(char *); s32 fn_80199310(void *); u8 fn_800E5248(void *,s32);
 void fn_80198FB0(void *); void Actor_ClearNodeLink(void *); void *Actor_SetNodeLink(void *,char *,char *,s32);
 void GActor_SetNodeLinkParam(void *,void *); void fn_80198F8C(void *,void *); s32 fn_801992F0(void *);
 void *Heap_Alloc(s32); void Camera_GetLookAt(void *,void *);
 void *fn_80151D50(void *,void *,void *,void *,void *,void *,s32);
 void fn_802031A8(void *,void *,void *); void fn_802031E8(void *,void *);
 void fn_802031CC(void *,void *,f32); void fn_80203184(void *,void *,void *);
 extern s32 lbl_8036A180; extern void *gGame; extern f32 lbl_8036A1AC;
 typedef void (*GetPosFn)(Vec3f *,void *,s32);
 typedef u8 (*BusyFn)(void *);
 typedef void (*SetFn)(void *,f32,f32,f32);
 typedef void (*AddFn)(void *,void *);
 Vec3f pos;
 String name;
 Vec3f oldPos;
 String a,b;
 Vec3f p,copyLook,look,copyPos;
 String effect;
 Vec3f discarded,origin,other1,other2,footp,foot,current;
 Vec3f b1,a1,cb1,ca1,pb1,pa1;
 Vec3f b2,a2,cb2,ca2,pb2,pa2;
 void *node;
 s32 compare;
 s32 length;
 f32 radius, distance, separation;
 pos.z=lbl_8036A184; pos.y=lbl_8036A184; pos.x=lbl_8036A184;
 fn_800E5DEC(self);
 fn_800DBAB8(&oldPos,self);
 if(!Actor_IsBusy(self) && M2C_FIELD(self,u8 *,0x1B5)) {
   fn_800DF664(self);
   if(M2C_FIELD(self,void **,0x11C)) fn_800DF664(M2C_FIELD(self,void **,0x11C));
   f32 zero=lbl_8036A184;
   f32 scale=fActorDefaultRadius;
   M2C_FIELD(self,u8 *,0x1B5)=0;
   ((ActorUpdateInterface *)self)->SetScale(zero,scale,zero);
 }
 if(!Actor_IsBusy(self) && (length=strlen((char *)gActorXmlStrs+0x1C), String_Compare((u8 *)self+0x16C,0,M2C_FIELD(self,void **,0x16C),(char *)gActorXmlStrs+0x1C,length))) {
   if(!(length=strlen((char *)gActorXmlStrs+0x43F), String_Compare((u8 *)self+0x16C,0,M2C_FIELD(self,void **,0x16C),(char *)gActorXmlStrs+0x43F,length))) {
     M2C_FIELD(self,u8 *,0x184)=1;
     Actor_LoadAnim(self,String_CStr((u8 *)self+0x16C),M2C_FIELD(self,s32 *,0x190),1,1);
     String_Assign((u8 *)self+0x160,(u8 *)self+0x16C,0,-1);
     String_AssignCStr((u8 *)self+0x16C,(char *)gActorXmlStrs+0x1C,strlen((char *)gActorXmlStrs+0x1C));
   } else {
     M2C_FIELD(self,u8 *,0x184)=1;
     Actor_LoadAnim(self,String_CStr((u8 *)self+0x16C),M2C_FIELD(self,s32 *,0x188),0,1);
     String_AssignCStr((u8 *)self+0x16C,(char *)gActorXmlStrs+0x43F,strlen((char *)gActorXmlStrs+0x43F));
   }
   M2C_FIELD(self,u8 *,0x1A8)=0;
 }
 fn_80110228(self);
 if(M2C_FIELD(self,void **,0x11C) && fn_80199310(M2C_FIELD(self,void **,0x11C))!=4) {
   s32 event;
   switch(fn_80199310(M2C_FIELD(self,void **,0x11C))) {
   case 0:event=20;break; case 1:case 6:event=21;break; case 2:case 7:event=22;break;case 3:event=23;break;default:event=20;break;
   }
   if(fn_800E5248(self,event)) fn_80198FB0(M2C_FIELD(self,void **,0x11C));
   if(fn_800E5248(self,25)) Actor_ClearNodeLink(M2C_FIELD(self,void **,0x11C));
   if(M2C_FIELD(self,void **,0x120)) {
     if(fn_800E5248(self,24)) fn_80198FB0(M2C_FIELD(self,void **,0x120));
     if(fn_800E5248(self,25)) Actor_ClearNodeLink(M2C_FIELD(self,void **,0x120));
   }
 } else if(M2C_FIELD(self,void **,0x11C) && fn_80199310(M2C_FIELD(self,void **,0x11C))==4) {
   if(fn_800E5248(self,24)) {
     void *p=Actor_SetNodeLink(self,(char *)gActorXmlStrs+0x549,(char *)gActorXmlStrs+0x54D,0);
     if(p) { s32 param=lbl_8036A180; GActor_SetNodeLinkParam(p,&param); }
   }
   if(fn_800E5248(self,25)) Actor_ClearNodeLink(self);
 }
 name.cap=0;name.size=0;name.data=0;name.cap=0;
 if(M2C_FIELD(self,s32 *,0x14C)>0) --M2C_FIELD(self,s32 *,0x14C);
 if(M2C_FIELD(self,s32 *,0x14C)==0) {
   if(M2C_FIELD(self,s32 *,0x148)==99) {
     String_AssignCStr(&name,(char *)gActorXmlStrs+0x551,strlen((char *)gActorXmlStrs+0x551));
   } else {
     if(M2C_FIELD(self,s32 *,0x148)!=0) String_AssignCStr(&name,(char *)gActorXmlStrs+0x55E,strlen((char *)gActorXmlStrs+0x55E));
     else String_AssignCStr(&name,(char *)gActorXmlStrs+0x551,strlen((char *)gActorXmlStrs+0x551));
     node=M2C_FIELD(M2C_FIELD(self,void **,0x118),void **,0x11C);
     if(node) {
       fn_80198F8C(&a,node);
       length=strlen((char *)gActorXmlStrs+0x1C);
       compare=String_Compare(&a,0,(void *)a.size,(char *)gActorXmlStrs+0x1C,length);
       String_Destroy(&a,-1);
       if(compare && (fn_801992F0(node)==1 || M2C_FIELD(self,s32 *,0x1B8)==1)) {
         fn_80198F8C(&b,node); String_Assign(&name,&b,0,-1); String_Destroy(&b,-1);
       }
     }
   }
   {
     void *effectNode;
     s8 initialized;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(self,void **,0x40),void **,0x38))(&p,self,0);
     pos.y=p.y;pos.x=p.x;pos.z=p.z;pos.y=lbl_8036A184;initialized=0;
     effectNode=Heap_Alloc(0xC8);
     if(effectNode) {
       u8 allocator;
       Camera_GetLookAt(&look,self);ActorUpdate_CopyVector(&copyLook,&look);ActorUpdate_CopyVector(&copyPos,&pos);
       String_Init(&effect,(char *)gActorXmlStrs+0x51,&allocator);
       initialized=1;
       effectNode=fn_80151D50(effectNode,M2C_FIELD(self,void **,0xAC),&effect,&name,&copyPos,&copyLook,0);
     }
     ((ActorUpdateSceneInterface *)M2C_FIELD(self,void **,0xAC))->Add(effectNode);
     if(initialized) String_Destroy(&effect,-1);
   }
   M2C_FIELD(self,s32 *,0x14C)=-1;
 }
 if(M2C_FIELD(self,u8 *,0x195) && !((ActorUpdateInterface *)self)->IsBusy()) {
   M2C_FIELD(self,u8 *,0xD1)=0;M2C_FIELD(self,u8 *,0x195)=0;
 }
 {
   
   origin.z=lbl_8036A184;origin.y=lbl_8036A184;origin.x=lbl_8036A184;
   radius=M2C_FIELD(gGame,f32 *,0xD8);
   current.x=M2C_FIELD(self,f32 *,0x48);current.y=lbl_8036A184;current.z=M2C_FIELD(self,f32 *,0x50);
   if(PSVECDistance(origin,current)>radius) {
     fn_802031A8(&current,&origin,&current);fn_802031E8(&current,&current);fn_802031CC(&current,&current,radius);fn_80203184(&origin,&current,&current);
     M2C_FIELD(self,f32 *,0x48)=current.x;M2C_FIELD(self,f32 *,0x50)=current.z;
   }
 }
 if(!((ActorUpdateInterface *)self)->IsBusy() && M2C_FIELD(self,u8 *,0x1A8)) {
   node=M2C_FIELD(self,void **,0x118);
   if(!node) distance=lbl_8036A184;
   else {
     
     pa1.z=lbl_8036A184;pa1.y=lbl_8036A184;pa1.x=lbl_8036A184;pb1.z=lbl_8036A184;pb1.y=lbl_8036A184;pb1.x=lbl_8036A184;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(self,void **,0x40),void **,0x38))(&a1,self,0);
     ca1=a1;pa1=a1;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(node,void **,0x40),void **,0x38))(&b1,node,0);
     pb1=b1;cb1=b1;distance=PSVECDistance(ca1,cb1);
   }
   separation=lbl_8036A1AC*M2C_FIELD(self,f32 *,0x128);
   if(distance<separation) {
     radius=separation-distance;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(M2C_FIELD(self,void **,0x118),void **,0x40),void **,0x38))(&other1,M2C_FIELD(self,void **,0x118),0);
     if(M2C_FIELD(self,f32 *,0x48)<other1.x) M2C_FIELD(self,f32 *,0x48)-=radius;
     else M2C_FIELD(self,f32 *,0x48)+=radius;
   }
 }
 else if(!Str_Cmp(String_CStr((u8 *)self+0x160),(char *)gActorXmlStrs+0x535) || !Str_Cmp(String_CStr((u8 *)self+0x160),(char *)gActorXmlStrs+0xFE)) {
   node=M2C_FIELD(self,void **,0x118);
   if(!node) distance=lbl_8036A184;
   else {
     
     pa2.z=lbl_8036A184;pa2.y=lbl_8036A184;pa2.x=lbl_8036A184;pb2.z=lbl_8036A184;pb2.y=lbl_8036A184;pb2.x=lbl_8036A184;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(self,void **,0x40),void **,0x38))(&a2,self,0);
     ca2=a2;pa2=a2;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(node,void **,0x40),void **,0x38))(&b2,node,0);
     pb2=b2;cb2=b2;distance=PSVECDistance(ca2,cb2);
   }
   separation=lbl_8036A1AC*M2C_FIELD(self,f32 *,0x128);
   if(distance<separation) {
     radius=separation-distance;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(M2C_FIELD(self,void **,0x118),void **,0x40),void **,0x38))(&other2,M2C_FIELD(self,void **,0x118),0);
     if(M2C_FIELD(self,f32 *,0x48)<other2.x) M2C_FIELD(self,f32 *,0x48)-=radius;
     else M2C_FIELD(self,f32 *,0x48)+=radius;
   }
 }
 {
 
 foot.z=lbl_8036A184;foot.y=lbl_8036A184;foot.x=lbl_8036A184;
 if(fn_800E5248(self,50)) {
 ((GetPosFn)M2C_FIELD(M2C_FIELD(self,void **,0x40),void **,0x38))(&footp,self,0);
 foot=footp;fn_80111C8C(self,&foot);
 }
 }
 if(!(length=strlen((char *)gActorXmlStrs+0x56E), String_Compare((u8 *)self+0xB0,0,M2C_FIELD(self,void **,0xB0),(char *)gActorXmlStrs+0x56E,length))) {
 ((GetPosFn)M2C_FIELD(M2C_FIELD(self,void **,0x40),void **,0x38))(&discarded,self,0);
 }
 String_Destroy(&name,-1);
}
#pragma optimization_level reset
#pragma global_optimizer reset
#pragma cplusplus off

void *fn_801179DC(void *arg0, s16 arg1) {
    void BinTree_Destroy(void *, void *);
    void String_Destroy(void *, s32);
    void Actor_Dtor(void *, s32);
    void Heap_Free(void *);
    extern u16 lbl_8028F6C8[];
    u8 *p;

    if (arg0 != NULL) {
        p = (u8 *)arg0;
        *(void **)(p + 0x40) = lbl_8028F6C8;
        if (p + 0x1BC)
            if (p + 0x1BC)
                if (*(void **)(p + 0x1C0))
                    BinTree_Destroy(p + 0x1BC, *(void **)(p + 0x1C0));
        String_Destroy(p + 0x178, -1);
        String_Destroy(p + 0x16C, -1);
        String_Destroy(p + 0x160, -1);
        String_Destroy(p + 0x154, -1);
        Actor_Dtor(arg0, 0);
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma global_optimizer off
void *fn_80117A94(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s8 arg5)
{
    String sp24;
    String sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 a3;
    s32 a4;
    s8 a5;

    String_Init(&sp24, (char *)gActorXmlStrs + 0x573, &sp14);
    String_Init(&sp18, (char *)gActorXmlStrs + 0x579, &sp10);
    a3 = arg3;
    a4 = arg4;
    a5 = arg5;
    fn_800E6418(arg0, arg1, &sp24, arg2, a3, &sp18);
    String_Destroy(&sp18, -1);
    String_Destroy(&sp24, -1);

    {
        u8 *self = (u8 *)arg0;
        f32 fv1B0;
        f32 fv128;
        f32 fv124;

        *(void **)(self + 0x40) = lbl_8028F6C8;

        *(u32 *)(self + 0x154) = 0;
        *(u32 *)(self + 0x158) = 0;
        *(u32 *)(self + 0x15C) = 0;
        *(u32 *)(self + 0x158) = 0;
        *(u32 *)(self + 0x160) = 0;
        *(u32 *)(self + 0x164) = 0;
        *(u32 *)(self + 0x168) = 0;
        *(u32 *)(self + 0x164) = 0;
        *(u32 *)(self + 0x16C) = 0;
        *(u32 *)(self + 0x170) = 0;
        *(u32 *)(self + 0x174) = 0;
        *(u32 *)(self + 0x170) = 0;
        *(u32 *)(self + 0x178) = 0;
        *(u32 *)(self + 0x17C) = 0;
        *(u32 *)(self + 0x180) = 0;
        *(u32 *)(self + 0x17C) = 0;

        fn_800D6878(self + 0x1BC, &sp8, &spC);

        *(s32 *)(self + 0x118) = 0;
        fv124 = lbl_8036A1DC;
        *(s32 *)(self + 0x11C) = 0;
        fv128 = fActorDefaultRadius;
        *(s32 *)(self + 0x120) = 0;
        fv1B0 = lbl_8036A1C8;
        *(f32 *)(self + 0x124) = fv124;
        *(f32 *)(self + 0x128) = fv128;
        *(s32 *)(self + 0x12C) = 0;
        *(s32 *)(self + 0x130) = 0;
        *(s32 *)(self + 0x134) = 0;
        *(s32 *)(self + 0x138) = 0;
        *(s32 *)(self + 0x13C) = 0;
        *(s32 *)(self + 0x140) = 0;
        *(s32 *)(self + 0x14C) = -1;
        *(s32 *)(self + 0x148) = 0;
        self[0x184] = 0;
        self[0x194] = 0;
        self[0x195] = 0;
        *(s32 *)(self + 0x198) = 1;
        *(s32 *)(self + 0x19C) = 0;
        self[0x1A0] = 0;
        self[0x1A1] = 0;
        self[0x1A2] = a5;
        self[0x1A3] = a5;
        self[0x1A4] = 0;
        self[0x1A5] = 0;
        self[0x1A6] = 0;
        self[0x1A7] = 0;
        self[0x1A8] = 0;
        *(s32 *)(self + 0x1AC) = a4;
        *(f32 *)(self + 0x1B0) = fv1B0;
        self[0x1B4] = 0;
        self[0x1B5] = 0;
        self[0x1B6] = 0;
        *(s32 *)(self + 0x1B8) = 1;

        String_AssignCStr(self + 0x154, (char *)gActorXmlStrs + 0x581, strlen((char *)gActorXmlStrs + 0x581));
        String_AssignCStr(self + 0x160, (char *)gActorXmlStrs + 0x1C, strlen((char *)gActorXmlStrs + 0x1C));
        String_AssignCStr(self + 0x16C, (char *)gActorXmlStrs + 0x1C, strlen((char *)gActorXmlStrs + 0x1C));

        self[0x1D7] = 1;
        self[0x1D6] = 1;
        self[0x1D5] = 1;
        self[0x1D4] = 1;
        return self;
    }
}
#pragma global_optimizer reset

s32 fn_80117CC0(void *arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 8) + arg1;
}

void fn_80117CCC(void) {
    void fn_8014C798(void *);
    void fn_800163F8(void);
    void fn_80016180(void);
    void *Unit_FindByName(void *);
    void Unit_FocusCamera(void *, s32);
    void Camera_SyncFromBattleState(void);
    extern s32 gBattleState[];
    extern u8 lbl_80274508[];
    void *temp_r3;

    fn_8014C798(gBattleState);
    fn_800163F8();
    fn_80016180();
    temp_r3 = Unit_FindByName(lbl_80274508 + 0x130);
    if (temp_r3 != 0) {
        Unit_FocusCamera(temp_r3, 0);
        Camera_SyncFromBattleState();
    }
}

void fn_80117D20(s32 arg0) {
    void BattleState_LoadMap(void *, s32);
    void ScriptCtx_Begin(void *);
    void ScriptCtx_Call(void);
    void Event_StartByName(void *, s32);
    extern s32 gBattleState[];
    extern u8 lbl_80274508[];

    BattleState_LoadMap(gBattleState, 0);
    ScriptCtx_Begin(lbl_80274508 + 0x138);
    ScriptCtx_Call();
    Event_StartByName(lbl_80274508 + 0x150, arg0);
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
s32 fn_80117D80(void *arg0, void *unit) {
    void Map_RefreshUnitMap(void *);
    void fn_800C1060(s32);
    void *TargetList_GetAt(void *, s32);
    void Unit_SetMapPos(void *, u8, u8);
    void fn_80050C90(void *);
    extern u8 gBattleMap[];
    extern u8 gMapBlendMode;
    extern u8 gTargetList[];
    u32 flags;
    s32 var_r4;
    u32 t;
    s32 i;
    u8 *tgt;
    s8 x;
    s8 y;
    s32 result;

    result = 0;
    flags = *(u32 *)((u8 *)unit + 0x1A0);
    if ((flags & 0x010000DC) == 0) {
        if ((flags & 0x10000) != 0) {
            return 0;
        }
        *(u32 *)((u8 *)unit + 0x1A0) = flags | 0x010000DC;
        Map_RefreshUnitMap(gBattleMap);
        var_r4 = 1;
        t = ((u8)(gMapBlendMode - 1) <= (u32)var_r4);
        if (!t) {
            var_r4 = 0;
        }
        if ((u8)var_r4 != 0) {
            fn_800C1060(0);
        }
        result = 1;
    } else if ((flags & 0x00200000) != 0) {
        return 0;
    } else {
        for (i = 0; i < *(s32 *)gTargetList; i++) {
            tgt = (u8 *)TargetList_GetAt(gTargetList, i);
            x = (s8)tgt[0];
            y = (s8)tgt[1];
            if (*(u8 *)(gBattleMap + x + (y << 6) + 0xD) == 0) {
                *(u32 *)((u8 *)unit + 0x1A0) &= ~0x010000DCU;
                Unit_SetMapPos(unit, tgt[0], tgt[1]);
                fn_80050C90(unit);
                Map_RefreshUnitMap(gBattleMap);
                var_r4 = 1;
                t = ((u8)(gMapBlendMode - 1) <= (u32)var_r4);
                if (!t) {
                    var_r4 = 0;
                }
                if ((u8)var_r4 != 0) {
                    fn_800C1060(0);
                }
                result = 1;
                break;
            }
        }
    }
    return result;
}
#pragma global_optimizer on
void fn_80117F1C(void *arg0) {
    M2C_UNK Process_Goto(void *, u8);
    M2C_UNK Ui_DecBusy();
    Ui_DecBusy();
    Process_Goto(arg0, M2C_FIELD(arg0, u8 *, 0x48));
}

void fn_80117F54(s32 arg0) {
    extern s32 gUiContext[];
    
    void fn_8013FED0(void);
    void fn_8007D064(s32, s32, s32);

    fn_8013FED0();
    fn_8007D064(gUiContext[0], arg0, 0);
}

void fn_80117F98(void *arg0) {
    typedef struct {
        void *unk0;
        s32 unk4;
        s16 unk8;
        s16 unkA;
        s16 unkC;
        s16 unkE;
        s16 unk10;
        s16 unk12;
        s16 unk14;
        s16 unk16;
        s16 unk18;
        s16 unk1A;
        s16 unk1C;
        u8 unk1E;
        u8 unk1F;
        u8 unk20;
        u8 unk21;
        s16 unk22;
        s16 unk24;
        f32 unk28;
        f32 unk2C;
        f32 unk30;
        s32 unk34;
        s32 unk38;
        s32 unk3C;
        s32 unk40;
        s32 unk44;
        s32 unk48;
        u8 unk4C;
        u8 pad4D;
        s16 unk4E;
        s16 unk50;
        s16 unk52;
        s16 unk54;
        s32 unk58;
    } Unk5C;
    void *Heap_Alloc(s32);
    void String_AssignCStr(void *, char *, s32);
    s32 strlen(char *);
    void Ui_AddChild(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Process_RetreatStep(void *);
    void Process_ClearFunc(void *);
    void Process_Goto(void *, s32);
    void fn_8011ACFC(void);
    extern u8 gUiContext[];
    extern u8 lbl_80293C84[];
    extern u8 lbl_80293C58[];
    extern u8 lbl_80274508[];
    Unk5C *temp_r3;
    Unk5C *found;
    s32 len;

    switch (gUiContext[8]) {
    case 0x81:
        Process_Goto(arg0, 0x13);
        break;
    default:
        Process_RetreatStep(*(void **)((u8 *)arg0 + 0x44));
        temp_r3 = (Unk5C *)Heap_Alloc(0x5C);
        if (temp_r3) {
            temp_r3->unk0 = lbl_8028FDB0;
            temp_r3->unk4 = 0;
            temp_r3->unk0 = lbl_80292230;
            temp_r3->unk8 = -1;
            temp_r3->unkA = 0;
            temp_r3->unkC = 0x190;
            temp_r3->unkE = 0x260;
            temp_r3->unk10 = 0x1C0;
            temp_r3->unk12 = 0;
            temp_r3->unk14 = 0;
            temp_r3->unk16 = 0x260;
            temp_r3->unk18 = 0x30;
            temp_r3->unk1A = 0;
            temp_r3->unk1C = 0;
            temp_r3->unk1E = 0xFF;
            temp_r3->unk1F = 0xFF;
            temp_r3->unk20 = 0xFF;
            temp_r3->unk21 = 0xFF;
            temp_r3->unk22 = 0x316;
            temp_r3->unk24 = 0;
            temp_r3->unk28 = 1.0f;
            temp_r3->unk2C = 1.0f;
            temp_r3->unk30 = 1.0f;
            temp_r3->unk34 = 0;
            temp_r3->unk38 = 0;
            temp_r3->unk0 = lbl_80293C84;
            temp_r3->unk3C = 0;
            temp_r3->unk40 = 0;
            temp_r3->unk44 = 0;
            temp_r3->unk40 = 0;
            temp_r3->unk48 = 0;
            temp_r3->unk4C = 1;
            temp_r3->unk4E = 0;
            temp_r3->unk50 = 0;
            temp_r3->unk52 = 0;
            temp_r3->unk54 = 0;
            temp_r3->unk0 = lbl_80293C58;
            temp_r3->unk58 = 1;
            temp_r3->unk4E = 0x30;
            temp_r3->unk52 = 0x30;
        }
        temp_r3->unk8 = -0x1000;
        temp_r3->unk48 = 1;
        len = strlen((char *)lbl_80274508 + 0x161);
        String_AssignCStr(&temp_r3->unk3C, (char *)(lbl_80274508 + 353), len);
        temp_r3->unk34 |= 0x10;
        temp_r3->unk58 = 1;
        Ui_AddChild(arg0, temp_r3);
        found = (Unk5C *)Ui_FindChild(arg0, -0x1000, 0);
        if (found) {
            found->unk58 = 0;
        }
        fn_8011ACFC();
        Process_ClearFunc(arg0);
        break;
    }
}

void fn_80118170(void *arg0) {
    void fn_8012C7C8(void *, void *);
    void Process_AdvanceStep(s32);
    s32 Ui_FindChild(void *, s32, s32);
    void Ui_RemoveChild(void *, s32);
    void fn_80117D80(void);
    s32 tmp;

    fn_8012C7C8((void *)fn_80117D80, arg0);
    Process_AdvanceStep(*(s32 *)((u8 *)arg0 + 0x44));
    tmp = Ui_FindChild(arg0, -0x1000, 0);
    if (tmp != 0) {
        Ui_RemoveChild(arg0, tmp);
    }
}

void fn_801181D0(void) {
    M2C_UNK fn_80006198();
    M2C_UNK Game_SetState(M2C_UNK);
    Game_SetState(0xE);
    fn_80006198();
}

void fn_801181F8(s32 arg0) {
    extern u8 gUiContext[];
    switch ((s32)gUiContext[8]) {
    case 0x81:
        Process_Goto(arg0, 0x12);
        return;
    case 0x80:
        Process_Goto(arg0, 1);
        return;
    }
}

void fn_8011824C(s32 arg0) {
    void Msg_Expand(void *);
    void Ui_CreateMenu(void *, s32, s32);
    void *fn_8013BFFC(void);
    extern char lbl_80274508[];
    void *tmp;

    Msg_Expand(lbl_80274508 + 0x162);
    tmp = fn_8013BFFC();
    *((u8 *)tmp + 0x24) = 1;
    Ui_CreateMenu(tmp, arg0, 0);
}

void fn_8011829C(void *arg0) {
    void EventLock_Dec(void);
    void Process_Goto(void *, s32);
    extern u8 gUiContext[];

    EventLock_Dec();
    switch ((s32)gUiContext[8]) {
    case 0x81:
        Process_Goto(arg0, 0x13);
        return;
    case 0x80:
        Process_Goto(arg0, *(u8 *)((u8 *)arg0 + 0x48));
        return;
    }
}

void fn_80118308(s32 arg0) {
    void Msg_Expand(void *);
    void EventLock_Inc(void);
    void Ui_CreateMenu(void *, s32, s32);
    void fn_8011A2FC(void);
    void *fn_8013BFFC(void);
    u32 Ui_FindChild(s32, s32, s32);
    void Ui_SetWidgetText(u32, void *);
    extern char lbl_80274508[];
    void *tmp;
    u32 result;

    fn_8011A2FC();
    EventLock_Inc();
    Msg_Expand(lbl_80274508 + 0x17C);
    tmp = fn_8013BFFC();
    *((u8 *)tmp + 0x24) = 1;
    Ui_CreateMenu(tmp, arg0, 0);
    result = Ui_FindChild(arg0, -0x1000, 0);
    if (result != 0) {
        Ui_SetWidgetText(result, lbl_80274508 + 0x194);
    }
}

void fn_80118388(s32 arg0) {
    M2C_UNK Process_ClearFunc(s32);
    M2C_UNK fn_800A8400();
    Ui_DecBusy();
    fn_800A8400();
    Process_ClearFunc(arg0);
}

void fn_801183C0(s32 arg0) {
    void fn_8013FED0(s32);
    void fn_801D3B14(s32);
    extern s32 gBattleState[];

    fn_8013FED0(arg0);
    *((u8 *)gBattleState + 0x54) = 2;
    fn_801D3B14(arg0);
}

void fn_80118404(s32 arg0) {
    Ui_DecBusy();
    fn_800A8400();
    Process_ClearFunc(arg0);
}

void fn_8011843C(s32 arg0) {
    M2C_UNK fn_8013FED0();
    M2C_UNK fn_801AA120(s32);
    fn_8013FED0();
    fn_801AA120(arg0);
}

void fn_80118470(s32 arg0) {
    Ui_DecBusy();
    fn_800A8400();
    Process_ClearFunc(arg0);
}

void fn_801184A8(s32 arg0) {
    M2C_UNK fn_8016B730(s32);
    fn_8013FED0();
    fn_8016B730(arg0);
}

void fn_801184DC(void *arg0) {
    typedef struct {
        void *unk0;
        s32 unk4;
        s16 unk8;
        s16 unkA;
        s16 unkC;
        s16 unkE;
        s16 unk10;
        s16 unk12;
        s16 unk14;
        s16 unk16;
        s16 unk18;
        s16 unk1A;
        s16 unk1C;
        u8 unk1E;
        u8 unk1F;
        u8 unk20;
        u8 unk21;
        s16 unk22;
        s16 unk24;
        f32 unk28;
        f32 unk2C;
        f32 unk30;
        s32 unk34;
        s32 unk38;
        s32 unk3C;
        s32 unk40;
        s32 unk44;
        s32 unk48;
        u8 unk4C;
        u8 pad4D;
        s16 unk4E;
        s16 unk50;
        s16 unk52;
        s16 unk54;
        s32 unk58;
    } Unk5C;
    void *Heap_Alloc(s32);
    void String_AssignCStr(void *, char *, s32);
    s32 strlen(char *);
    void Ui_AddChild(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Process_RetreatStep(void *);
    void Process_ClearFunc(void *);
    extern u8 lbl_80293C84[];
    extern u8 lbl_80293C58[];
    extern u8 lbl_80274508[];
    Unk5C *temp_r3;
    Unk5C *found;
    s32 len;

    temp_r3 = (Unk5C *)Heap_Alloc(0x5C);
    if (temp_r3) {
        temp_r3->unk0 = lbl_8028FDB0;
        temp_r3->unk4 = 0;
        temp_r3->unk0 = lbl_80292230;
        temp_r3->unk8 = -1;
        temp_r3->unkA = 0;
        temp_r3->unkC = 0x190;
        temp_r3->unkE = 0x260;
        temp_r3->unk10 = 0x1C0;
        temp_r3->unk12 = 0;
        temp_r3->unk14 = 0;
        temp_r3->unk16 = 0x260;
        temp_r3->unk18 = 0x30;
        temp_r3->unk1A = 0;
        temp_r3->unk1C = 0;
        temp_r3->unk1E = 0xFF;
        temp_r3->unk1F = 0xFF;
        temp_r3->unk20 = 0xFF;
        temp_r3->unk21 = 0xFF;
        temp_r3->unk22 = 0x316;
        temp_r3->unk24 = 0;
        temp_r3->unk28 = 1.0f;
        temp_r3->unk2C = 1.0f;
        temp_r3->unk30 = 1.0f;
        temp_r3->unk34 = 0;
        temp_r3->unk38 = 0;
        temp_r3->unk0 = lbl_80293C84;
        temp_r3->unk3C = 0;
        temp_r3->unk40 = 0;
        temp_r3->unk44 = 0;
        temp_r3->unk40 = 0;
        temp_r3->unk48 = 0;
        temp_r3->unk4C = 1;
        temp_r3->unk4E = 0;
        temp_r3->unk50 = 0;
        temp_r3->unk52 = 0;
        temp_r3->unk54 = 0;
        temp_r3->unk0 = lbl_80293C58;
        temp_r3->unk58 = 1;
        temp_r3->unk4E = 0x30;
        temp_r3->unk52 = 0x30;
    }
    temp_r3->unk8 = -0x1000;
    temp_r3->unk48 = 1;
    len = strlen((char *)lbl_80274508 + 0x161);
    String_AssignCStr(&temp_r3->unk3C, (char *)(lbl_80274508 + 353), len);
    temp_r3->unk34 |= 0x10;
    temp_r3->unk58 = 1;
    Ui_AddChild(arg0, temp_r3);
    found = (Unk5C *)Ui_FindChild(arg0, -0x1000, 0);
    if (found) {
        found->unk58 = 0;
    }
    Process_RetreatStep(*(void **)((u8 *)arg0 + 0x44));
    Process_ClearFunc(arg0);
}

void fn_8011868C(void *arg0) {
    M2C_UNK Process_AdvanceStep(s32);
    s32 Ui_FindChild(void *, M2C_UNK, M2C_UNK);
    M2C_UNK Ui_RemoveChild(void *, s32);
    M2C_UNK fn_8016E9DC(void *);
    s32 tmp;

    Process_AdvanceStep(M2C_FIELD(arg0, s32 *, 0x44));
    tmp = Ui_FindChild(arg0, -0x1000, 0);
    if (tmp != 0) {
        Ui_RemoveChild(arg0, tmp);
    }
    fn_8016E9DC(arg0);
}

#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
void fn_801186E4(void *arg0)
{
    void Process_Goto(void *, s32);
    u8 Allegiance_CompareIds(s32, u8);
    void Map_RefreshUnitMap(u8 *);
    void UiCtx_BindUnit(u8 *, void *);
    void Map_HideMoveLimitView(void);
    void Map_ShowMoveLimitView(void);
    void fn_800A8400(void);
    void *Map_GetCursorUnit(void);
    void Map_SetupUnitMoveLimit(void *);
    u32 Ui_FindChild(void *, s32, s32);
    void Ui_PlaySeCue(u8 *, s32);
    void Ui_SetWidgetText(u32, u8 *);
    extern u8 lbl_80274508[];
    extern u8 gUnitLists[];
    extern u8 gBattleMap[];
    extern u8 gUiContext[];
    extern s32 gUiInputFlags;
    extern void *gPadInput;
    extern void *lbl_803679F0;
    extern s8 lbl_803679F4;
    void *unit;
    void *self;
    void *unit2;
    u8 flag;
    u8 skip;
    u32 held;
    u32 buttons;
    s32 inputFlags;
    void *iter;
    void *next;
    u32 flags;
    u32 ret;

    self = arg0;
    unit = Map_GetCursorUnit();
    if (unit != NULL) {
        if (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1) {
            if (!(*(u32 *)((u8 *)unit + 0x1A0) & 0x800)) {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != 0) {
                    Ui_SetWidgetText(ret, lbl_80274508 + 0x1A7);
                }
            } else {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != 0) {
                    Ui_SetWidgetText(ret, lbl_80274508 + 0x1B9);
                }
            }
        } else {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != 0) {
                Ui_SetWidgetText(ret, lbl_80274508 + 0x1CB);
            }
        }
    } else {
        flag = 0;
        iter = *(void **)(gUnitLists + 0xC);
        while (iter != NULL) {
            flags = *(u32 *)((u8 *)iter + 0x1A0);
            iter = *(void **)((u8 *)iter + 0x184);
            if (flags & 0x800) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != 0) {
                Ui_SetWidgetText(ret, lbl_80274508 + 0x1DD);
            }
        } else {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != 0) {
                Ui_SetWidgetText(ret, lbl_80274508 + 0x1EF);
            }
        }
    }
    if (lbl_803679F4 == 0) {
        lbl_803679F0 = NULL;
        lbl_803679F4 = 1;
    }
    unit2 = Map_GetCursorUnit();
    if (unit2 == NULL && (gUiInputFlags & 0x400)) {
        Map_HideMoveLimitView();
    }
    skip = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        skip = 1;
    }
    if ((skip != 0) ||
        ((!( *(u32 *)((u8 *)gPadInput + 4) & 0xF)) &&
         ((s8)(*(u8 **)gPadInput)[2] == 0) &&
         ((s8)(*(u8 **)gPadInput)[3] == 0))) {
        if ((lbl_803679F0 != unit2) || !(gUiInputFlags & 0x400)) {
            lbl_803679F0 = unit2;
            if ((unit2 == NULL) || (*(u8 *)(*(u8 **)((u8 *)unit2 + 0x190) + 8) == 0)) {
                if (gUiInputFlags & 0x400) {
                    Map_HideMoveLimitView();
                }
            } else {
                Map_SetupUnitMoveLimit(unit2);
                Map_ShowMoveLimitView();
            }
        }
    }
    inputFlags = gUiInputFlags;
    skip = 0;
    if ((inputFlags & 0x10) && !(inputFlags & 0x20)) {
        skip = 1;
    }
    if (skip == 0) {
        held = *(u32 *)((u8 *)gPadInput + 4);
        buttons = held & (*(u32 *)((u8 *)gPadInput + 8) ^ held);
        if ((unit != NULL) && (buttons & 0x800)) {
            fn_800A8400();
            if (gUiInputFlags & 0x400) {
                Map_HideMoveLimitView();
            }
            UiCtx_BindUnit(gUiContext, unit);
            Ui_PlaySeCue(lbl_80274508 + 0x201, 0x64);
            *((u8 *)self + 0x48) = 4;
            Process_Goto(self, 0x11);
            return;
        }
        if (buttons & 0x100) {
            if ((unit != NULL) && (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1)) {
                flags = *(u32 *)((u8 *)unit + 0x1A0);
                if (!(flags & 0x800)) {
                    *(u32 *)((u8 *)unit + 0x1A0) = flags | 0x800;
                    Map_RefreshUnitMap(gBattleMap);
                    Map_SetupUnitMoveLimit(unit);
                    Ui_PlaySeCue(lbl_80274508 + 0x211, 0x64);
                }
            } else {
                goto block_65;
            }
        } else if (buttons & 0x200) {
            if ((unit != NULL) && (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1)) {
                flags = *(u32 *)((u8 *)unit + 0x1A0);
                if (flags & 0x800) {
                    *(u32 *)((u8 *)unit + 0x1A0) = flags & ~0x800;
                    Map_RefreshUnitMap(gBattleMap);
                    Map_SetupUnitMoveLimit(unit);
                    Ui_PlaySeCue(lbl_80274508 + 0x22C, 0x64);
                }
            } else if (unit == NULL) {
                flag = ClearUnitSelections(*(void **)(gUnitLists + 0xC));
                if (flag != 0) {
                    Ui_PlaySeCue(lbl_80274508 + 0x22C, 0x64);
                    Map_RefreshUnitMap(gBattleMap);
                }
            }
        } else {
            if (buttons & 0x10) {
            block_65:
                if (gUiInputFlags & 0x400) {
                    Map_HideMoveLimitView();
                }
                Ui_PlaySeCue(lbl_80274508 + 0x247, 0x64);
                Process_Goto(self, 1);
                return;
            }
            if (buttons & 0x1000) {
                if (gUiInputFlags & 0x400) {
                    Map_HideMoveLimitView();
                }
                *((u8 *)self + 0x48) = 4;
                Process_Goto(self, 9);
            }
        }
    }
}
#pragma pop
void fn_80118B7C(void *arg0) {
    void EventLock_Dec(void);
    void fn_800A8478(void);
    void fn_8018DB4C(void);
    void fn_8000C060(void *, void *);
    void Process_Goto(void *, s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_CloseChildAnim(void *, void *, s32);
    extern u8 gEventLockDepth;
    void *temp_r31;

    while (gEventLockDepth != 0) {
        EventLock_Dec();
    }
    fn_800A8478();
    fn_8018DB4C();
    temp_r31 = *(void **)((u8 *)arg0 + 0x44);
    fn_8000C060(temp_r31, 0);
    Process_Goto(temp_r31, 0);
    if (Ui_FindChild(arg0, 0x40, 0) != NULL) {
        Ui_CloseChildAnim(arg0, Ui_FindChild(arg0, 0x40, 0), 1);
    }
}

void fn_80118C1C(void) {
    void fn_800A6AE4(void);
    void Map_RefreshUnitMap(void *);
    void fn_800C1060(s32);
    extern u8 gBattleMap[];
    extern u8 gMapBlendMode;
    u8 flag;

    fn_800A6AE4();
    Map_RefreshUnitMap(gBattleMap);
    flag = (gMapBlendMode == 1 || gMapBlendMode == 2);
    if (flag) {
        fn_800C1060(0);
    }
}

#pragma use_lmw_stmw on
void fn_80118C84(void *arg0) {
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, s32);
    u8 Allegiance_CompareIds(s32, u8);
    void Map_RefreshUnitMap(u8 *);
    void UiCtx_BindUnit(u8 *, void *);
    void *TargetList_GetAt(void *, s32);
    void Map_HideMoveLimitView(void);
    void Map_ShowMoveLimitView(void);
    void fn_800A6AAC(void);
    void fn_800A8400(void);
    void *Map_GetCursorUnit(void);
    void Map_SetupUnitMoveLimit(void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_PlaySeCue(u8 *, s32);
    void BattleState_SetCamPos(void *, f32, f32);
    void Ui_SetWidgetText(void *, u8 *);
    extern u8 lbl_80274508[];
    extern u8 lbl_8028F7B8[];
    extern u8 gUnits[];
    extern u8 gUnitLists[];
    extern u8 gBattleMap[];
    extern u8 gUiContext[];
    extern u8 gTargetList[];
    extern s32 gBattleState[];
    extern s32 gUiInputFlags;
    extern void *gPadInput;
    extern void *lbl_803679F0;
    extern s8 lbl_803679F4;
    void *other;
    void *unit2;
    void *iter;
    void *p;
    void *node;
    void *ret;
    u8 *map;
    u8 *ef;
    s8 cur_y;
    s8 cur_x;
    s32 sel_x;
    s32 sel_y;
    s32 idx;
    u8 id;
    u8 found;
    u8 flag;
    u8 skip;
    u32 buttons;
    u32 flags;
    s32 i;
    void *self;
    void *unit;

    self = arg0;
    unit = Map_GetCursorUnit();
    ef = gUiContext;
    cur_y = (s8)ef[0xE];
    sel_x = (s32)*(f32 *)((u8 *)gBattleState + 0x524);
    sel_y = (s32)*(f32 *)((u8 *)gBattleState + 0x528);
    cur_x = (s8)ef[0xD];
    map = gBattleMap + 0xD;
    idx = cur_x + (cur_y << 6);
    id = map[idx];
    if (id != 0) {
        other = &gUnits[(id - 1) * 0x280];
    } else {
        other = NULL;
    }
    if (unit != NULL) {
        if (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1) {
            if (!(*(u32 *)((u8 *)unit + 0x1A0) & 0x800)) {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != NULL)
                    Ui_SetWidgetText(ret, lbl_80274508 + 0x1A7);
            } else {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != NULL)
                    Ui_SetWidgetText(ret, lbl_80274508 + 0x1B9);
            }
        } else if (other != unit) {
            found = 0;
            id = map[(s8)sel_x + ((s8)sel_y << 6)];
            if (id != 0) {
                p = &gUnits[(id - 1) * 0x280];
                if (*(u32 *)((u8 *)p + 0x1A0) & 0x20000) {
                    found = 0;
                } else {
                    goto search1;
                }
            } else {
            search1:
                for (i = 0; i < *(s32 *)gTargetList; i++) {
                    p = TargetList_GetAt(gTargetList, i);
                    if ((s8)sel_x == (s8)*(u8 *)p && (s8)sel_y == (s8)*((u8 *)p + 1)) {
                        found = 1;
                        break;
                    }
                }
            }
            if (found != 0) {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != NULL)
                    Ui_SetWidgetText(ret, lbl_80274508 + 0x257);
            } else {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != NULL)
                    Ui_SetWidgetText(ret, lbl_80274508 + 0x269);
            }
        } else {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != NULL)
                Ui_SetWidgetText(ret, lbl_80274508 + 0x27B);
        }
    } else {
        flag = 0;
        iter = *(void **)(gUnitLists + 0xC);
        while (iter != NULL) {
            flags = *(u32 *)((u8 *)iter + 0x1A0);
            iter = *(void **)((u8 *)iter + 0x184);
            if (flags & 0x800) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != NULL)
                Ui_SetWidgetText(ret, lbl_80274508 + 0x28D);
        } else {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != NULL)
                Ui_SetWidgetText(ret, lbl_80274508 + 0x1EF);
        }
    }
    if (lbl_803679F4 == 0) {
        lbl_803679F0 = NULL;
        lbl_803679F4 = 1;
    }
    unit2 = Map_GetCursorUnit();
    if (unit2 == NULL && (gUiInputFlags & 0x400))
        Map_HideMoveLimitView();
    skip = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20))
        skip = 1;
    if ((skip != 0) ||
        ((!(*(u32 *)((u8 *)gPadInput + 4) & 0xF)) &&
         ((s8)(*(u8 **)gPadInput)[2] == 0) &&
         ((s8)(*(u8 **)gPadInput)[3] == 0))) {
        if ((lbl_803679F0 != unit2) || !(gUiInputFlags & 0x400)) {
            lbl_803679F0 = unit2;
            if ((unit2 == NULL) || (*(u8 *)(*(u8 **)((u8 *)unit2 + 0x190) + 8) == 0)) {
                if (gUiInputFlags & 0x400)
                    Map_HideMoveLimitView();
            } else {
                Map_SetupUnitMoveLimit(unit2);
                Map_ShowMoveLimitView();
            }
        }
    }
    skip = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20))
        skip = 1;
    if (skip != 0)
        return;
    buttons = *(u32 *)((u8 *)gPadInput + 4);
    buttons = buttons & (*(u32 *)((u8 *)gPadInput + 8) ^ buttons);
    if ((unit != NULL) && (buttons & 0x800)) {
        fn_800A8400();
        if (gUiInputFlags & 0x400)
            Map_HideMoveLimitView();
        UiCtx_BindUnit(gUiContext, unit);
        ef[0xD] = (u8)cur_x;
        ef[0xE] = (u8)cur_y;
        Ui_PlaySeCue(lbl_80274508 + 0x201, 0x64);
        *((u8 *)self + 0x48) = 6;
        Process_Goto(self, 0x11);
        return;
    }
    if (buttons & 0x100) {
        if (unit != NULL) {
            found = 0;
            id = map[(s8)sel_x + ((s8)sel_y << 6)];
            if (id != 0) {
                p = &gUnits[(id - 1) * 0x280];
                if (*(u32 *)((u8 *)p + 0x1A0) & 0x20000) {
                    found = 0;
                } else {
                    goto search2;
                }
            } else {
            search2:
                for (i = 0; i < *(s32 *)gTargetList; i++) {
                    p = TargetList_GetAt(gTargetList, i);
                    if ((s8)sel_x == (s8)*(u8 *)p && (s8)sel_y == (s8)*((u8 *)p + 1)) {
                        found = 1;
                        break;
                    }
                }
            }
            if (found == 0) {
                if (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1) {
                    flags = *(u32 *)((u8 *)unit + 0x1A0);
                    if (!(flags & 0x800)) {
                        *(u32 *)((u8 *)unit + 0x1A0) = flags | 0x800;
                        Map_RefreshUnitMap(gBattleMap);
                        Map_SetupUnitMoveLimit(unit);
                        Ui_PlaySeCue(lbl_80274508 + 0x211, 0x64);
                    }
                } else {
                    Ui_PlaySeCue(lbl_80274508 + 0x29F, 0x64);
                }
                return;
            }
        }
        if ((s8)sel_x != cur_x || (s8)sel_y != cur_y) {
            found = 0;
            id = map[(s8)sel_x + ((s8)sel_y << 6)];
            if (id != 0) {
                p = &gUnits[(id - 1) * 0x280];
                if (*(u32 *)((u8 *)p + 0x1A0) & 0x20000) {
                    found = 0;
                } else {
                    goto search3;
                }
            } else {
            search3:
                for (i = 0; i < *(s32 *)gTargetList; i++) {
                    p = TargetList_GetAt(gTargetList, i);
                    if ((s8)sel_x == (s8)*(u8 *)p && (s8)sel_y == (s8)*((u8 *)p + 1)) {
                        found = 1;
                        break;
                    }
                }
            }
            if (found != 0) {
                fn_800A6AAC();
                if (gUiInputFlags & 0x400)
                    Map_HideMoveLimitView();
                id = map[idx];
                if (id != 0)
                    other = &gUnits[(id - 1) * 0x280];
                else
                    other = NULL;
                if (other != NULL) {
                    if (self != NULL)
                        node = Process_CreateChild(lbl_8028F7B8, self);
                    else
                        node = Process_Create(lbl_8028F7B8, 4);
                    *(void **)((u8 *)node + 0x30) = other;
                    *((u8 *)node + 0x58) = (u8)sel_x;
                    *((u8 *)node + 0x59) = (u8)sel_y;
                }
                if (unit != NULL) {
                    if (self != NULL)
                        node = Process_CreateChild(lbl_8028F7B8, self);
                    else
                        node = Process_Create(lbl_8028F7B8, 4);
                    *(void **)((u8 *)node + 0x30) = unit;
                    *((u8 *)node + 0x58) = (u8)cur_x;
                    *((u8 *)node + 0x59) = (u8)cur_y;
                }
                Ui_PlaySeCue(lbl_80274508 + 0x2AD, 0x64);
                Process_ClearFunc(self);
                return;
            }
        }
        goto cancel;
    } else if (buttons & 0x200) {
        if (unit != NULL) {
            found = 0;
            id = map[(s8)sel_x + ((s8)sel_y << 6)];
            if (id != 0) {
                p = &gUnits[(id - 1) * 0x280];
                if (*(u32 *)((u8 *)p + 0x1A0) & 0x20000) {
                    found = 0;
                } else {
                    goto search4;
                }
            } else {
            search4:
                for (i = 0; i < *(s32 *)gTargetList; i++) {
                    p = TargetList_GetAt(gTargetList, i);
                    if ((s8)sel_x == (s8)*(u8 *)p && (s8)sel_y == (s8)*((u8 *)p + 1)) {
                        found = 1;
                        break;
                    }
                }
            }
            if (found == 0 && Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1) {
                flags = *(u32 *)((u8 *)unit + 0x1A0);
                if (flags & 0x800) {
                    *(u32 *)((u8 *)unit + 0x1A0) = flags & ~0x800;
                    Map_RefreshUnitMap(gBattleMap);
                    Map_SetupUnitMoveLimit(unit);
                    Ui_PlaySeCue(lbl_80274508 + 0x22C, 0x64);
                }
                return;
            }
        }
        if (unit == NULL) {
            flag = 0;
            iter = *(void **)(gUnitLists + 0xC);
            while (iter != NULL) {
                flags = *(u32 *)((u8 *)iter + 0x1A0);
                if (flags & 0x800) {
                    flag = 1;
                    *(u32 *)((u8 *)iter + 0x1A0) = flags & ~0x800;
                }
                iter = *(void **)((u8 *)iter + 0x184);
            }
            if (flag != 0) {
                Ui_PlaySeCue(lbl_80274508 + 0x22C, 0x64);
                Map_RefreshUnitMap(gBattleMap);
                return;
            }
        }
        if (gUiInputFlags & 0x400)
            Map_HideMoveLimitView();
        Ui_PlaySeCue(lbl_80274508 + 0x247, 0x64);
        BattleState_SetCamPos(gBattleState, (f32)(s8)ef[0xD], (f32)(s8)ef[0xE]);
        Process_Goto(self, 2);
        return;
    } else {
        if (buttons & 0x10) {
        cancel:
            if (gUiInputFlags & 0x400)
                Map_HideMoveLimitView();
            Ui_PlaySeCue(lbl_80274508 + 0x247, 0x64);
            BattleState_SetCamPos(gBattleState, (f32)(s8)ef[0xD], (f32)(s8)ef[0xE]);
            Process_Goto(self, 1);
            return;
        }
        if (buttons & 0x1000) {
            if (gUiInputFlags & 0x400)
                Map_HideMoveLimitView();
            *((u8 *)self + 0x48) = 6;
            Process_Goto(self, 9);
        }
    }
}
#pragma use_lmw_stmw reset

void fn_801196A8(void *arg0) {
    void fn_800A8478(void);
    void fn_8018DB4C(void);
    void fn_8000C060(void *, void *);
    void Process_Goto(void *, s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_CloseChildAnim(void *, void *, s32);
    void fn_80119738(void);
    void *temp_r31;

    fn_800A8478();
    fn_8018DB4C();
    temp_r31 = *(void **)((u8 *)arg0 + 0x44);
    fn_8000C060(temp_r31, fn_80119738);
    Process_Goto(temp_r31, 1);
    if (Ui_FindChild(arg0, 0x40, 0) != NULL) {
        Ui_CloseChildAnim(arg0, Ui_FindChild(arg0, 0x40, 0), 1);
    }
}

void fn_80119738(void *arg0) {
    void fn_8006785C(s32, void (*)(void *), void *);
    void fn_80119768(void *);
    fn_8006785C(2, fn_80119768, arg0);
}

#pragma use_lmw_stmw on
void fn_80119768(void) {
    void *TargetList_GetAt(void *, s32);
    void fn_8004A864(s32, s32, u8 *);
    void Map_SetupColorGx(void);
    void fn_802245D8(s32, s32, s32, s32);
    extern u8 gUiContext[];
    extern s32 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    extern s32 lbl_8036A1E0;
    extern s32 lbl_8036A1E4;
    s32 spC;
    s32 sp8;
    s8 t29;
    s8 t28;
    s32 i;
    u8 b0;
    s32 y;
    u8 id;
    void *unit;

    Map_SetupColorGx();
    i = 0;
    t28 = (s8)gUiContext[0xD];
    t29 = (s8)gUiContext[0xE];
    for (i = 0; i < gTargetList[0]; i++) {
        b0 = *(u8 *)TargetList_GetAt(gTargetList, i);
        y = ((s8 *)TargetList_GetAt(gTargetList, i))[1];
        id = (gBattleMap + (s8)b0)[0xD + (y << 6)];
        if (id == 0) {
            goto sound;
        }
        if (id != 0) {
            unit = &gUnits[(id - 1) * 0x280];
        } else {
            unit = NULL;
        }
        if (*(u32 *)((u8 *)unit + 0x1A0) & 0x20000) {
            continue;
        }
sound:
        if (((s8)b0 != t28) || (y != t29)) {
            spC = lbl_8036A1E0;
            fn_8004A864((s8)b0, y, (u8 *)&spC);
        } else {
            sp8 = lbl_8036A1E4;
            fn_8004A864((s8)b0, y, (u8 *)&sp8);
        }
    }
    fn_802245D8(1, 4, 5, 0);
}
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_80119884(void *arg0)
{
    void *Map_GetCursorUnit(void);
    u8 Allegiance_CompareIds(s32, u8);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, const char *);
    void *TargetList_GetAt(void *, s32);
    void Map_HideMoveLimitView(void);
    void Map_ShowMoveLimitView(void);
    void Map_SetupUnitMoveLimit(void *);
    void Map_RefreshUnitMap(void *);
    void fn_800A8400(void);
    void UiCtx_BindUnit(void *, void *);
    void Ui_PlaySeCue(const char *, s32);
    void Process_Goto(void *, s32);
    extern s32 gBattleState[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    extern u8 gTargetList[];
    extern u8 gUnitLists[];
    extern u8 gUiContext[];
    extern u8 lbl_80274508[];
    extern s8 lbl_803679F4;
    extern void *lbl_803679F0;
    extern s32 gUiInputFlags;
    extern u32 *gPadInput;

    s32 cx;
    s32 cy;
    u8 *unit;
    u8 *process;
    u8 *other;
    u8 *tileUnit;
    u8 *widget;
    u8 *entry;
    u8 *pad;
    s32 i;
    u8 selected;
    u8 found;
    u32 flags;
    u32 pressed;
    u32 input;
    u32 lastInput;
    u32 unitFlags;
    u8 unitId;
    u8 locked;

    process = (u8 *)arg0;
    unit = (u8 *)Map_GetCursorUnit();
    cx = (s32)*(f32 *)((u8 *)gBattleState + 0x524);
    cy = (s32)*(f32 *)((u8 *)gBattleState + 0x528);

    if (unit != 0) {
        if (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)(unit + 0x190) + 8)) == 1) {
            if ((*(u32 *)(unit + 0x1A0) & 0x800) == 0) {
                widget = (u8 *)Ui_FindChild(process, -0x1000, 0);
                if (widget != 0) {
                    Ui_SetWidgetText(widget, (const char *)(lbl_80274508 + 0x1A7));
                }
            } else {
                widget = (u8 *)Ui_FindChild(process, -0x1000, 0);
                if (widget != 0) {
                    Ui_SetWidgetText(widget, (const char *)(lbl_80274508 + 0x1B9));
                }
            }
        } else {
            selected = Ui_IsTargetTile((s8)cx, (s8)cy);
            if (selected) {
                widget = (u8 *)Ui_FindChild(process, -0x1000, 0);
                if (widget) Ui_SetWidgetText(widget, (const char *)(lbl_80274508 + 0x1A7));
            } else {
                widget = (u8 *)Ui_FindChild(process, -0x1000, 0);
                if (widget) Ui_SetWidgetText(widget, (const char *)(lbl_80274508 + 0x2C2));
            }
        }
    } else {
        found = 0;
        other = *(u8 **)(gUnitLists + 0xC);
        while (other != 0) {
            unitFlags = *(u32 *)(other + 0x1A0);
            other = *(u8 **)(other + 0x184);
            if (unitFlags & 0x800) {
                found = 1;
                break;
            }
        }
        if (!found) {
            widget = (u8 *)Ui_FindChild(process, -0x1000, 0);
            if (widget) Ui_SetWidgetText(widget, (const char *)(lbl_80274508 + 0x1DD));
        } else {
            widget = (u8 *)Ui_FindChild(process, -0x1000, 0);
            if (widget) Ui_SetWidgetText(widget, (const char *)(lbl_80274508 + 0x1EF));
        }
    }

    if (lbl_803679F4 == 0) {
        lbl_803679F0 = 0;
        lbl_803679F4 = 1;
    }

    other = (u8 *)Map_GetCursorUnit();
    if (other == 0 && (gUiInputFlags & 0x400)) {
        Map_HideMoveLimitView();
    }

    flags = gUiInputFlags;
    locked = Ui_InputLocked(flags);
    if (!locked) {
        pad = (u8 *)gPadInput;
        if (*(u32 *)(pad + 4) & 0xF) goto move_limit_done;
        {
            s8 *axes = *(s8 **)pad;
            if ((s8)axes[2] || (s8)axes[3]) goto move_limit_done;
        }
    }
    if (lbl_803679F0 != other || (flags & 0x400) == 0) {
        lbl_803679F0 = other;
        if (other == 0 || *(u8 *)(*(u8 **)(other + 0x190) + 8) == 0) {
            if (flags & 0x400) Map_HideMoveLimitView();
        } else {
            Map_SetupUnitMoveLimit(other);
            Map_ShowMoveLimitView();
        }
    }
move_limit_done:

    flags = gUiInputFlags;
    locked = Ui_InputLocked(flags);
    if (locked) {
        return;
    }

    pad = (u8 *)gPadInput;
    input = *(u32 *)(pad + 4);
    lastInput = *(u32 *)(pad + 8);
    pressed = input & (lastInput ^ input);

    if (unit != 0 && (pressed & 0x800)) {
        fn_800A8400();
        if (gUiInputFlags & 0x400) {
            Map_HideMoveLimitView();
        }
        UiCtx_BindUnit(gUiContext, unit);
        Ui_PlaySeCue((const char *)(lbl_80274508 + 0x201), 0x64);
        process[0x48] = 2;
        Process_Goto(process, 0x11);
        return;
    }

    if (pressed & 0x100) {
        if (unit != 0) {
            selected = Ui_IsTargetTile((s8)cx, (s8)cy);
            if (selected == 0) {
                if (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)(unit + 0x190) + 8)) == 1) {
                    unitFlags = *(u32 *)(unit + 0x1A0);
                    if (unitFlags & 0x800) {
                        return;
                    }
                    *(u32 *)(unit + 0x1A0) = unitFlags | 0x800;
                    Map_RefreshUnitMap(gBattleMap);
                    Map_SetupUnitMoveLimit(unit);
                    Ui_PlaySeCue((const char *)(lbl_80274508 + 0x211), 0x64);
                } else {
                    Ui_PlaySeCue((const char *)(lbl_80274508 + 0x29F), 0x64);
                }
                return;
            }
        }

        selected = Ui_IsTargetTile((s8)cx, (s8)cy);
        if (selected != 0) {
            if (gUiInputFlags & 0x400) {
                Map_HideMoveLimitView();
            }
            gUiContext[0xD] = (u8)cx;
            gUiContext[0xE] = (u8)cy;
            Process_Goto(process, 6);
            Ui_PlaySeCue((const char *)(lbl_80274508 + 0x2D4), 0x64);
        } else goto cancel_menu;
        return;
    }

    if (pressed & 0x200) {
        if (unit != 0) {
            selected = Ui_IsTargetTile((s8)cx, (s8)cy);
            if (selected == 0 && Allegiance_CompareIds(0, *(u8 *)(*(u8 **)(unit + 0x190) + 8)) == 1) {
                unitFlags = *(u32 *)(unit + 0x1A0);
                if (unitFlags & 0x800) {
                    *(u32 *)(unit + 0x1A0) = unitFlags & ~0x800;
                    Map_RefreshUnitMap(gBattleMap);
                    Map_SetupUnitMoveLimit(unit);
                    Ui_PlaySeCue((const char *)(lbl_80274508 + 0x22C), 0x64);
                }
                return;
            }
        }
        if (unit == 0) {
            found = ClearUnitSelections(*(void **)(gUnitLists + 0xC));
            if (found != 0) {
                Ui_PlaySeCue((const char *)(lbl_80274508 + 0x22C), 0x64);
                Map_RefreshUnitMap(gBattleMap);
            }
        }
        return;
    }

    if (pressed & 0x10) {
cancel_menu:
        if (gUiInputFlags & 0x400) {
            Map_HideMoveLimitView();
        }
        Ui_PlaySeCue((const char *)(lbl_80274508 + 0x247), 0x64);
        Process_Goto(process, 1);
        return;
    }

    if (pressed & 0x1000) {
        if (flags & 0x400) {
            Map_HideMoveLimitView();
        }
        process[0x48] = 2;
        Process_Goto(process, 9);
    }
}
#pragma pop
void fn_8011A0CC(void *arg0) {
    void EventLock_Dec(void);
    void fn_800A8478(void);
    void fn_8018DB4C(void);
    void fn_8000C060(void *, void *);
    void Process_Goto(void *, s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_CloseChildAnim(void *, void *, s32);
    void fn_80119738(void);
    extern u8 gEventLockDepth;
    extern s8 gUiContext[];
    void *temp_r31;

    while (gEventLockDepth != 0) {
        EventLock_Dec();
    }
    fn_800A8478();
    fn_8018DB4C();
    temp_r31 = *(void **)((u8 *)arg0 + 0x44);
    fn_8000C060(temp_r31, fn_80119738);
    Process_Goto(temp_r31, 1);
    if (Ui_FindChild(arg0, 0x40, 0) != NULL) {
        Ui_CloseChildAnim(arg0, Ui_FindChild(arg0, 0x40, 0), 1);
    }
    gUiContext[0xD] = -1;
    gUiContext[0xE] = -1;
}

void fn_8011A184(void *arg0) {
 void fn_8011ACFC(void); void Unit_MoveToList(void *,s32); s32 fn_80015680(void *);
 void fn_800A8400(void); void Map_RefreshUnitMap(void *); void fn_80161F7C(void); void fn_8003F670(void *);
 void EventLock_Dec(void); void Ui_DtorPanelBase(void *,s32); void fn_801481CC(void *,s32); void fn_80148980(void *,s32); void fn_80018B04(void);
 extern u8 gUnitLists[],gTargetList[],gBattleMap[],gFxChannels[],lbl_80274508[];
 extern s16 lbl_80366E88; extern u8 gEventLockDepth;
 s16 count; s16 *limit; u8 *next; u8 *unit; s32 n;
 unit=*(u8 **)(gUnitLists+0xc);
 while(unit) { next=*(u8 **)(unit+0x184); *(u32 *)(unit+0x1a0)&=~0x800; unit=next; }
 fn_8011ACFC();
 unit=*(u8 **)gUnitLists;
 while(unit) {
 u32 flags=*(u32 *)(unit+0x1a0); next=*(u8 **)(unit+0x184);
 if(flags&0x010000DC) { *(u32 *)(unit+0x1a0)=flags&~0x010000DC; Unit_MoveToList(unit,5); }
 unit=next;
 }
 n=*(s32 *)gTargetList;
 count=n-fn_80015680(gUnitLists);
 limit=&count;
 if(count<lbl_80366E88) limit=&lbl_80366E88;
 ((u8 *)gBattleState)[0x56]=*limit;
 fn_800A8400(); Map_RefreshUnitMap(gBattleMap); fn_80161F7C(); fn_8003F670(*(void **)((u8 *)arg0+0x40));
 while(gEventLockDepth) EventLock_Dec();
 if(arg0) Ui_DtorPanelBase(arg0,0);
 if(!(gUiInputFlags&0x10)) { fn_801481CC(lbl_80274508+0x2e9,250); fn_80148980(gFxChannels,500); }
 fn_80018B04();
}

#pragma use_lmw_stmw reset
void fn_8011A2FC(void *arg0) {
    typedef struct {
        void *unk0;
        void *unk4;
        s16 unk8;
        s16 unkA;
        s16 unkC;
        s16 unkE;
        s16 unk10;
        s16 unk12;
        s16 unk14;
        s16 unk16;
        s16 unk18;
        s16 unk1A;
        s16 unk1C;
        u8 unk1E;
        u8 unk1F;
        u8 unk20;
        u8 unk21;
        s16 unk22;
        s16 unk24;
        f32 unk28;
        f32 unk2C;
        f32 unk30;
        s32 unk34;
        s32 unk38;
    } Unk5C;
    void *Ui_FindChild(void *, s32, s32);
    void *Heap_Alloc(s32);
    void Ui_AddChild(void *, void *);
    void Ui_OpenChildAnim(void *, void *, s32);
    Unk5C *widget;
    u8 color[4];

    if (Ui_FindChild(arg0, 0x40, 0) == 0) {
        widget = Heap_Alloc(0x3C);
        if (widget) {
            widget->unk0 = lbl_8028FDB0;
            widget->unk4 = NULL;
            widget->unk0 = lbl_80292230;
            widget->unk8 = -1;
            widget->unkA = 0;
            widget->unkC = 0;
            widget->unkE = 0x260;
            widget->unk10 = 0x1C0;
            widget->unk12 = 0;
            widget->unk14 = 0;
            widget->unk16 = 0x260;
            widget->unk18 = 0x1C0;
            widget->unk1A = 0;
            widget->unk1C = 0;
            widget->unk1E = 0xFF;
            widget->unk1F = 0xFF;
            widget->unk20 = 0xFF;
            widget->unk21 = 0xFF;
            widget->unk22 = 0x316;
            widget->unk24 = 0;
            widget->unk28 = 1.0f;
            widget->unk2C = 1.0f;
            widget->unk30 = 1.0f;
            widget->unk34 = 0;
            widget->unk38 = 0;
            widget->unk0 = lbl_802921E0;
        }
        widget->unk8 = 0x40;
        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        color[3] = 0x80;
        if (&widget->unk1E != &color[0]) {
            widget->unk1E = color[0];
            widget->unk1F = color[1];
            widget->unk20 = color[2];
            widget->unk21 = color[3];
        }
        widget->unk34 |= 0x10;
        widget->unk24 = 8;
        widget->unk2C = 0.0f;
        Ui_AddChild(arg0, widget);
        Ui_OpenChildAnim(arg0, widget, 1);
    }
}

void fn_8011A470(s32 arg0) {
    void EventLock_Inc(void);
    void fn_800A8450(void);
    void fn_8011A2FC(s32);
    void fn_8011A4E4(s32);
    u32 Ui_FindChild(s32, s32, s32);
    void Ui_SetWidgetText(u32, u8 *);
    extern u8 gEventLockDepth;
    extern u8 lbl_80274508[];
    u32 temp;

    if (gEventLockDepth == 0) {
        EventLock_Inc();
    }
    fn_800A8450();
    fn_8011A4E4(arg0);
    fn_8011A2FC(arg0);
    temp = Ui_FindChild(arg0, -0x1000, 0);
    if (temp != 0) {
        Ui_SetWidgetText(temp, lbl_80274508 + 0x2F5);
    }
}

void fn_8011A4E4(s32 arg0) {
    void Ui_CreateMenu(void *, s32, s32);
    extern u8 gUiContext[];
    extern u8 gUiMenuDrawVtbl[];
    extern u8 lbl_80286664[];
    extern u8 lbl_80286590[];
    extern u8 lbl_8028F7EC[];
    extern u8 lbl_8028FA3C[];
    extern u8 lbl_8028FABC[];
    extern u8 lbl_8028FB10[];
    extern u8 lbl_8028FB64[];
    extern u8 lbl_8028FBB8[];
    extern u8 lbl_8028FC0C[];
    extern u8 lbl_8028FC60[];
    extern u8 lbl_8028FCB4[];
    extern u8 lbl_8028FD08[];
    extern u8 lbl_8028FD5C[];
    extern s8 lbl_803679F5;
    extern void *lbl_803679F8;
    extern s8 lbl_803679FC;
    extern void *lbl_80367A00;
    extern s8 lbl_80367A04;
    extern void *lbl_80367A08;
    extern s8 lbl_80367A0C;
    extern void *lbl_80367A10;
    extern s8 lbl_80367A14;
    extern void *lbl_80367A18;
    extern s8 lbl_80367A1C;
    extern void *lbl_80367A20;
    extern s8 lbl_80367A24;
    extern void *lbl_80367A28;
    extern s8 lbl_80367A2C;
    extern void *lbl_80367A30;
    extern s8 lbl_80367A34;
    extern void *lbl_80367A38;
    extern s8 lbl_80367A3C;
    extern void *lbl_80367A40[2];

    if (lbl_803679F5 == 0) {
        lbl_803679F8 = lbl_8028FD5C;
        lbl_803679F5 = 1;
    }
    if (lbl_803679FC == 0) {
        lbl_80367A00 = lbl_8028FD08;
        lbl_803679FC = 1;
    }
    if (lbl_80367A04 == 0) {
        lbl_80367A08 = lbl_8028FCB4;
        lbl_80367A04 = 1;
    }
    if (lbl_80367A0C == 0) {
        lbl_80367A10 = lbl_8028FC60;
        lbl_80367A0C = 1;
    }
    if (lbl_80367A14 == 0) {
        lbl_80367A18 = lbl_8028FC0C;
        lbl_80367A14 = 1;
    }
    if (lbl_80367A1C == 0) {
        lbl_80367A20 = lbl_8028FBB8;
        lbl_80367A1C = 1;
    }
    if (lbl_80367A24 == 0) {
        lbl_80367A28 = lbl_8028FB64;
        lbl_80367A24 = 1;
    }
    if (lbl_80367A2C == 0) {
        lbl_80367A30 = lbl_8028FB10;
        lbl_80367A2C = 1;
    }
    if (lbl_80367A34 == 0) {
        lbl_80367A38 = lbl_8028FABC;
        lbl_80367A34 = 1;
    }
    if (lbl_80367A3C == 0) {
        lbl_80367A40[1] = gUiMenuDrawVtbl;
        lbl_80367A40[1] = lbl_80286664;
        lbl_80367A40[1] = lbl_80286590;
        lbl_80367A40[0] = lbl_8028F7EC;
        lbl_80367A40[1] = lbl_8028FA3C;
        lbl_80367A3C = 1;
    }
    gUiContext[8] = 0;
    Ui_CreateMenu(lbl_80367A40, arg0, 0);
}

static inline u8 Map_IsBlendMode(u8 mode) {
    u8 enabled = 1;
    if (!(1 >= (u8)(mode - 1))) enabled = 0;
    return enabled;
}

#pragma push
#pragma opt_lifetimes off
void fn_8011A694(void) {
    void Unit_MoveToListHead(void *, s32);
    void Unit_MoveToList(void *, s32);
    void *Unit_FindByName(void *);
    void Map_RefreshUnitMap(void *);
    void fn_800C1060(s32);
    extern u8 gUnitLists[];
    extern u8 lbl_80274508[];
    extern u8 gBattleMap[];
    extern u8 gMapBlendMode;

    void *head;
    void *next;
    void *unit;
    void *found;
    void *q;
    void *p;
    u8 blend;

    head = *(void **)gUnitLists;
    unit = *(void **)(gUnitLists + 4);
    while (unit != NULL) {
        next = *(void **)((u8 *)unit + 0x180);
        if ((*(u32 *)((u8 *)unit + 0x1A0) & 0x10000) != 0) {
            Unit_MoveToListHead(unit, 0);
            if (unit == head) {
                break;
            }
        }
        unit = next;
    }

    unit = *(void **)(gUnitLists + 0x3C);
    while (unit != NULL) {
        next = *(void **)((u8 *)unit + 0x184);
        Unit_MoveToList(unit, 0);
        *(u32 *)((u8 *)unit + 0x1A0) |= 0x010000DC;
        unit = next;
    }

    found = Unit_FindByName(lbl_80274508 + 0x130);
    p = *(void **)gUnitLists;
    while (p != NULL) {
        q = *(void **)((u8 *)p + 0x184);
        if (p != found) {
            *(s16 *)((u8 *)p + 0x15C) =
                (s16)(50.0f * ((f32)*(s16 *)((u8 *)found + 0x15C) / 50.0f));
        }
        p = q;
    }

    Map_RefreshUnitMap(gBattleMap);
    blend = Map_IsBlendMode(gMapBlendMode);
    if (blend) {
        fn_800C1060(0);
    }
}
#pragma pop
void fn_8011A7FC(void *arg0) {
    extern u8 gUnitLists[], gTargetList[], lbl_8028F790[], lbl_80274508[], lbl_80293C84[], lbl_80293C58[];
    extern u8 lbl_80367A48;
    void Unit_MoveToListHead(void *, s32);
    void fn_8002F728(void *);
    void fn_8002F6E8(void *, s8, s8, s32, s32);
    void *TargetList_GetAt(void *, s32);
    void *TargetList_GetCurrent(void *);
    void fn_8011C404(void *, void *);
    void fn_8011C2B8(void *, void *);
    void fn_8011C164(void *, void *);
    void fn_8011C018(void *, void *);
    void *Process_Create(void *, void *);
    void GfxEnt_UnlinkByName(char *);
    void *Heap_Alloc(s32);
    s32 strlen(char *);
    void Ui_AddChild(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Fx_StartSlot(s32,char *,s32,s32);
    void fn_80018B18(void);
    s32 d,c,b,a;
    s32 count;
    void *entry;
    s32 j;
    u8 *next, *unit, *coords;
    s32 i;
    s32 len;
    u8 *p;
    lbl_80367A48=0;
    gUiInputFlags &= ~1;
    for(unit=*(u8 **)(gUnitLists+4);unit;unit=next) {
        next=*(u8 **)(unit+0x180);
        if(*(u32 *)(unit+0x1A0)&0x010000DC) Unit_MoveToListHead(unit,5);
    }
    count=(s8)((u8 *)gBattleState)[0x544];
    fn_8002F728(gTargetList);
    coords=(u8 *)gBattleState+0x545;
    for(i=0;i<count;coords+=2,i++) fn_8002F6E8(gTargetList,(s8)coords[0],(s8)coords[1],0,0);
    for(j=0;j<*(s32 *)gTargetList;j++) {
        entry=TargetList_GetAt(gTargetList,j);
        fn_8011C404(entry,&a); fn_8011C2B8(entry,&b);
        fn_8011C164(entry,&c); fn_8011C018(entry,&d);
    }
    p=Process_Create(lbl_8028F790,arg0);
    if(p) *(void **)(p+0x30)=TargetList_GetCurrent(gTargetList);
    *(u8 **)((u8 *)arg0+0x44)=p;
    p=*(u8 **)((u8 *)arg0+0x44); p[0x2c]|=4;
    GfxEnt_UnlinkByName((char *)lbl_80274508+0x115);
    p=Heap_Alloc(0x5C);
    if(p) {
            M2C_FIELD(p, void * *, 0x0) = lbl_8028FDB0;
            M2C_FIELD(p, s32 *, 0x4) = 0;
            M2C_FIELD(p, void * *, 0x0) = lbl_80292230;
            M2C_FIELD(p, s16 *, 0x8) = -1;
            M2C_FIELD(p, s16 *, 0xA) = 0;
            M2C_FIELD(p, s16 *, 0xC) = 0x190;
            M2C_FIELD(p, s16 *, 0xE) = 0x260;
            M2C_FIELD(p, s16 *, 0x10) = 0x1C0;
            M2C_FIELD(p, s16 *, 0x12) = 0;
            M2C_FIELD(p, s16 *, 0x14) = 0;
            M2C_FIELD(p, s16 *, 0x16) = 0x260;
            M2C_FIELD(p, s16 *, 0x18) = 0x30;
            M2C_FIELD(p, s16 *, 0x1A) = 0;
            M2C_FIELD(p, s16 *, 0x1C) = 0;
            M2C_FIELD(p, u8 *, 0x1E) = 0xFF;
            M2C_FIELD(p, u8 *, 0x1F) = 0xFF;
            M2C_FIELD(p, u8 *, 0x20) = 0xFF;
            M2C_FIELD(p, u8 *, 0x21) = 0xFF;
            M2C_FIELD(p, s16 *, 0x22) = 0x316;
            M2C_FIELD(p, s16 *, 0x24) = 0;
            M2C_FIELD(p, f32 *, 0x28) = 1.0f;
            M2C_FIELD(p, f32 *, 0x2C) = 1.0f;
            M2C_FIELD(p, f32 *, 0x30) = 1.0f;
            M2C_FIELD(p, s32 *, 0x34) = 0;
            M2C_FIELD(p, s32 *, 0x38) = 0;
            M2C_FIELD(p, void * *, 0x0) = lbl_80293C84;
            M2C_FIELD(p, s32 *, 0x3C) = 0;
            M2C_FIELD(p, s32 *, 0x40) = 0;
            M2C_FIELD(p, s32 *, 0x44) = 0;
            M2C_FIELD(p, s32 *, 0x40) = 0;
            M2C_FIELD(p, s32 *, 0x48) = 0;
            M2C_FIELD(p, u8 *, 0x4C) = 1;
            M2C_FIELD(p, s16 *, 0x4E) = 0;
            M2C_FIELD(p, s16 *, 0x50) = 0;
            M2C_FIELD(p, s16 *, 0x52) = 0;
            M2C_FIELD(p, s16 *, 0x54) = 0;
            M2C_FIELD(p, void * *, 0x0) = lbl_80293C58;
            M2C_FIELD(p, s32 *, 0x58) = 1;
            M2C_FIELD(p, s16 *, 0x4E) = 0x30;
            M2C_FIELD(p, s16 *, 0x52) = 0x30;
    }
    *(s16 *)(p+8)=-0x1000; *(s32 *)(p+0x48)=1;
    len=strlen(&((char *)lbl_80274508)[353]);
    String_AssignCStr(&p[0x3C],(char *)&lbl_80274508[353],len);
    *(u32 *)(p+0x34)|=0x10; *(s32 *)(p+0x58)=1;
    Ui_AddChild(arg0,p);
    p=Ui_FindChild(arg0,-0x1000,0);
    if(p) *(s32 *)(p+0x58)=0;
    ((u8 *)gBattleState)[0xA9]=0; ((u8 *)gBattleState)[0xAA]=0; *(s32 *)((u8 *)gBattleState+0xB0)=0;
    if(!(gUiInputFlags&0x10)) Fx_StartSlot(0,(char *)lbl_80274508+0x2E9,100,1);
    fn_80018B18();
}

#pragma global_optimizer off
