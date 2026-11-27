/* Functions from 0x8012C3D0 to 0x8013275C, found by decomp-toolkit. */
#include "common.h"


#include "global.h"
extern f64 lbl_8036A4F0;
extern f64 lbl_8036A4F8;
#include "unit.h"
#pragma cplusplus on
struct UnitListDrawablePanel {
    u8 pad[0x24];
    s16 offsets[20];
    virtual void *getDrawable(void *, s32);
};
#pragma cplusplus reset

f32 lbl_8036A500 = 300.0f;
f32 lbl_8036A50C = 1.0f;
f32 lbl_8036A510 = 0.0f;
f32 lbl_8036A514 = 288.0f;
f32 lbl_8036A518 = 24.0f;

s32 fn_8012C3D0(void) {
    return 0x168;
}

s32 fn_8012C3D8(void) {
    return 0x128;
}

s32 fn_8012C3E0(void) {
    return 0x16;
}

#pragma cplusplus on
extern "C" void fn_8012C3E8(void *arg0) {
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
        virtual void v28();
        virtual void v29();
    };
    ((Obj *)arg0)->v29();
}
#pragma cplusplus reset
char *fn_8012C414(void) {
    u8 fn_80109B0C(s32);
    void sprintf(void *, void *, ...);
    extern s32 lbl_80367A88;
    extern u8 lbl_802758F8[];
    extern char lbl_8032FE60[];

    sprintf(lbl_8032FE60, lbl_802758F8 + 0x10a, (u8)fn_80109B0C(lbl_80367A88));
    return lbl_8032FE60;
}

void *fn_8012C460(void) {
    extern u16 lbl_802758F8[];
    return (u8 *)lbl_802758F8 + 0x11B;
}

s32 fn_8012C470(void) {
    void fn_80109B00(void *, u8);
    u8 fn_80109B0C(void *);
    extern void *gPadInput;
    extern void *lbl_80367A88;
    u32 flags;
    s32 val;

    val = fn_80109B0C(lbl_80367A88);
    flags = *(u32 *)((u8 *)gPadInput + 0x10);
    if (flags & 0x01000001) {
        val -= 1;
    }
    if (flags & 0x02000002) {
        val += 1;
    }
    if (val > 0xFF) {
        val = 0xFF;
    }
    if (val < 0) {
        val = 0;
    }
    fn_80109B00(lbl_80367A88, val);
    return 0;
}

char *fn_8012C4F0(void) {
    u8 fn_80109B24(s32);
    void sprintf(void *, void *, ...);
    extern s32 lbl_80367A88;
    extern u8 lbl_802758F8[];
    extern char lbl_8032FE60[];

    sprintf(lbl_8032FE60, lbl_802758F8 + 0x13C, (u8)fn_80109B24(lbl_80367A88));
    return lbl_8032FE60;
}

void *fn_8012C53C(void) {
    extern u16 lbl_802758F8[];
    return (u8 *)lbl_802758F8 + 0x14d;
}

s32 fn_8012C54C(void) {
    void fn_80109B18(void *, u8);
    u8 fn_80109B24(void *);
    extern void *gPadInput;
    extern void *lbl_80367A88;
    u32 flags;
    s32 val;

    val = fn_80109B24(lbl_80367A88);
    flags = *(u32 *)((u8 *)gPadInput + 0x10);
    if (flags & 0x01000001) {
        val -= 1;
    }
    if (flags & 0x02000002) {
        val += 1;
    }
    if (val > 0xFF) {
        val = 0xFF;
    }
    if (val < 0) {
        val = 0;
    }
    fn_80109B18(lbl_80367A88, val);
    return 0;
}

char *fn_8012C5CC(void) {
    u8 fn_80109B48(s32);
    void sprintf(void *, void *, ...);
    extern s32 lbl_80367A88;
    extern u8 lbl_802758F8[];
    extern char lbl_8032FE60[];

    sprintf(lbl_8032FE60, lbl_802758F8 + 0x164, (u8)fn_80109B48(lbl_80367A88));
    return lbl_8032FE60;
}

void *fn_8012C618(void) {
    extern u16 lbl_802758F8[];
    return (u8 *)lbl_802758F8 + 0x175;
}

s32 fn_8012C628(void) {
    void fn_80109B30(void *, u8);
    u8 fn_80109B48(void *);
    extern void *gPadInput;
    extern void *lbl_80367A88;
    u32 flags;
    s32 val;

    val = fn_80109B48(lbl_80367A88);
    flags = *(u32 *)((u8 *)gPadInput + 0x10);
    if (flags & 0x01000001) {
        val -= 1;
    }
    if (flags & 0x02000002) {
        val += 1;
    }
    if (val > 0xFF) {
        val = 0xFF;
    }
    if (val < 0) {
        val = 0;
    }
    fn_80109B30(lbl_80367A88, val);
    return 0;
}

char *fn_8012C6A8(void) {
 double fn_80109BA8(s32); void sprintf(void *, ...);
 extern s32 lbl_80367A88; extern char lbl_802758F8[]; extern char lbl_8032FE60[];
 sprintf(lbl_8032FE60, lbl_802758F8 + 0x188, fn_80109BA8(lbl_80367A88));
 return lbl_8032FE60;
}

void *fn_8012C6F0(void) {
    extern char lbl_802758F8[];
    return &lbl_802758F8[0x19B];
}

s32 fn_8012C700(void) {
    M2C_UNK fn_80109B54(s32, f32);
    f32 fn_80109BA8(s32);
    extern void *gPadInput;
    extern s32 lbl_80367A88;
    extern f32 lbl_8036A4AC;
    extern f32 lbl_8036A4D8;
    f32 var_f1;
    s32 temp_r4;

    var_f1 = fn_80109BA8(lbl_80367A88);
    temp_r4 = M2C_FIELD(gPadInput, s32 *, 0x10);
    if (temp_r4 & 0x01000001) {
        var_f1 -= lbl_8036A4D8;
    }
    if (temp_r4 & 0x02000002) {
        var_f1 += lbl_8036A4D8;
    }
    if (var_f1 > lbl_8036A4AC) {
        var_f1 = lbl_8036A4AC;
    }
    if (var_f1 < lbl_8036A4D8) {
        var_f1 = lbl_8036A4D8;
    }
    fn_80109B54(lbl_80367A88, var_f1);
    return 0;
}

void fn_8012C788(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    extern u8 lbl_80291084[];
    void *temp_r3;

    temp_r3 = Process_CreateChild(lbl_80291084, arg1);
    *(s32 *)((u8 *)temp_r3 + 0x54) = arg0;
    *(u8 *)((u8 *)temp_r3 + 0x6C) = 2;
}

void fn_8012C7C8(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    extern u8 lbl_80291084[];
    void *temp_r3;

    temp_r3 = Process_CreateChild(lbl_80291084, arg1);
    *(s32 *)((u8 *)temp_r3 + 0x54) = arg0;
    *(u8 *)((u8 *)temp_r3 + 0x6C) = 1;
}

/* Refresh the select-menu help banner text from mode and whether a row is selected. */
void Ui_RefreshSelectPrompt(void *proc) {
    M2C_UNK Process_Goto(void *, s32);
    s32 Msg_Expand(void *);
    M2C_UNK TextBanner_SetString(s32, s32);
    extern u8 gUiContext[];
    extern u8 gUiSelectMenuStrings[];

    if ((u8)gUiContext[8] == 0x81) {
        Process_Goto(proc, 0);
    }

    if ((s8)M2C_FIELD(proc, u8 *, 0x62) < 0) {
        switch (M2C_FIELD(proc, u8 *, 0x6C)) {
        case 1:
        case 2:
            TextBanner_SetString(M2C_FIELD(proc, s32 *, 0x50), Msg_Expand((void *)(gUiSelectMenuStrings + 0x5A)));
            return;
        case 4:
            TextBanner_SetString(M2C_FIELD(proc, s32 *, 0x50), Msg_Expand((void *)(gUiSelectMenuStrings + 0x6B)));
            return;
        default:
            TextBanner_SetString(M2C_FIELD(proc, s32 *, 0x50), Msg_Expand((void *)(gUiSelectMenuStrings + 0x7B)));
            return;
        }
    } else {
        switch (M2C_FIELD(proc, u8 *, 0x6C)) {
        case 1:
        case 2:
            TextBanner_SetString(M2C_FIELD(proc, s32 *, 0x50), Msg_Expand((void *)(gUiSelectMenuStrings + 0x8A)));
            return;
        case 4:
            TextBanner_SetString(M2C_FIELD(proc, s32 *, 0x50), Msg_Expand((void *)(gUiSelectMenuStrings + 0x9B)));
            return;
        default:
            TextBanner_SetString(M2C_FIELD(proc, s32 *, 0x50), Msg_Expand((void *)(gUiSelectMenuStrings + 0xAB)));
            return;
        }
    }
}

void fn_8012C964(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    extern u8 lbl_80290FA0[];
    void *temp_r3;
    temp_r3 = Process_CreateChild(lbl_80290FA0, arg0);
    *(u32 *)((u8 *)temp_r3 + 0x54) = 0;
    *(u8 *)((u8 *)temp_r3 + 0x6C) = 3;
}

void fn_8012C9A0(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    s32 fn_8012C9E8(s32, void *);
    extern u8 lbl_80290EB0[];
    void *temp_r3;

    temp_r3 = Process_CreateChild(lbl_80290EB0, arg0);
    *(u8 *)((u8 *)temp_r3 + 0x60) = 0;
    *(void **)((u8 *)temp_r3 + 0x54) = fn_8012C9E8;
    *(u8 *)((u8 *)temp_r3 + 0x6C) = 4;
}

s32 fn_8012C9E8(s32 unused, void *arg1)
{
    *(s32 *)((u8 *)arg1 + 0x1A0) ^= 0x80000000;
    return 1;
}

void fn_8012C9FC(s32 arg0, s32 arg1) {
    extern u8 lbl_80290EB0[];
    void *Process_CreateChild(void *, s32);
    void *obj;

    obj = Process_CreateChild(lbl_80290EB0, arg1);
    *(u8 *)((u8 *)obj + 0x60) = (u8)arg0;
    *(s32 *)((u8 *)obj + 0x54) = 0;
    *(u8 *)((u8 *)obj + 0x6C) = 0;
}

extern u8 lbl_80290E88[16];
void fn_8012CA40(s32 arg0) {
    void Process_CreateChild(void *, s32);
    extern u8 lbl_80290E88[16];
    Process_CreateChild(lbl_80290E88, arg0);
}

#pragma cplusplus on
void fn_8012CA6C(void *arg0) {
    struct Tab {
        u8 pad[0x38];
        s16 arr[1];
    };
    extern u8 gBattleState[];
    extern u8 gUiSelectMenuStrings[];
    void fn_80057860(void *, s16);
    void Sound_Create(void *, void *);
    void *Process_AttachFunc(void *, void *);
    void fn_8012F360(void);
    u8 *object = *(u8 **)((u8 *)arg0 + 0x18);
    register s32 i = 0;
    u8 *entry;
    u32 selected;
    register s32 count = object[0x61];
    s32 index;
    s32 delta;
    selected = *(u32 *)(gBattleState + 0xAC);
    entry = *(u8 **)(object + 0x3C);
    for (; i < count; i++, entry += 0x24) {
        if (*(u32 *)entry == selected) { object[0x62] = i; break; }
    }
    delta = (s8)object[0x62] - *(s16 *)(object + 0x6A) / 32;
    index = (s8)object[0x62];
    if (delta < 1 || delta >= 8) {
        if (index == 0) *(s16 *)(object + 0x6A) = 0;
        else {
            register int count = object[0x61];
            if (index == count - 1) *(s16 *)(object + 0x6A) = (count - 9) << 5;
            else if (delta <= 0) *(s16 *)(object + 0x6A) = (index - 1) << 5;
            else *(s16 *)(object + 0x6A) = (index - 7) << 5;
        }
    }
    fn_80057860(*(void **)(object + 0x4C), *(s16 *)(object + 0x6A));
    if ((s8)object[0x62] < 0) {
        *(s16 *)(object + 0x58) = (*(struct Tab ***)(object + 0x38))[object[0x63]]->arr[(s8)object[0x65]];
        *(s16 *)(object + 0x5A) = 0x42;
        *(s16 *)(object + 0x5C) = 0;
        *(s16 *)(object + 0x5E) = 0;
    } else {
        *(s16 *)(object + 0x58) = 0x28;
        *(s16 *)(object + 0x5A) = ((s8)object[0x62] << 5) + 0x60 - *(s16 *)(object + 0x6A);
        *(s16 *)(object + 0x5C) = 0x1B8;
        *(s16 *)(object + 0x5E) = 0x16;
    }
    Sound_Create(gUiSelectMenuStrings + 0xBA, object);
    *(void **)(object + 0x34) = Process_AttachFunc(fn_8012F360, object);
}
#pragma cplusplus reset
void fn_8012CC0C(void *arg0)
{
    extern u8 gUiSelectMenuStrings[];
    void Process_Unlink(void *);
    void fn_80109020(void *);
    void fn_8007D064(void *, void *, s32);

    u8 *object;
    void *entry;
    s32 index;
    s32 mode;

    object = *(u8 **)((u8 *)arg0 + 0x18);

    Process_Unlink(*(void **)(object + 0x34));
    fn_80109020(gUiSelectMenuStrings + 0xBA);

    *(u32 *)(object + 0x34) = 0;

    index = (s8)object[0x62];
    mode = object[0x6C];
    entry = *(void **)(*(u8 **)(object + 0x3C) + index * 0x24);

    switch (mode) {
    case 0:
    case 4:
        fn_8007D064(entry, object, 0);
        break;
    case 1:
    case 2:
    case 3:
        fn_8007D064(entry, object, 0x01000000);
        break;
    }
}

#pragma cplusplus on
extern "C" void fn_8012CCA4(void *arg0)
{
    struct VObj {
        u8 pad[0x2C];
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6(s32);
    };
    struct Entry {
        u32 a;
        void *b;
        u8 pad[0x1C];
    };
    extern u8 gBattleState[];
    extern u8 gUiSelectMenuStrings[];

    void Heap_Free(void *);
    void Heap_FreeRaw(void *);
    void fn_800616A0(void *);
    void fn_80056A04(void *, s32);
    void fn_80057A10(void *, s32);
    void Process_Unlink(void *);
    void fn_80109020(void *);
    void fn_8003F670(void *);
    void fn_8006D8E8(void *);
    void fn_8005C7C8(void *);

    u8 *object;
    u8 *bs;
    u32 flags;
    VObj *obj4c;

    object = (u8 *)arg0;

    if ((signed char)object[0x62] < 0) {
        *(u32 *)(gBattleState + 0xB0) = 0;
    } else {
        *(u32 *)(gBattleState + 0xB0) =
            *(u32 *)((u8 *)*(u32 **)(object + 0x3C) + *(s8 *)(object + 0x62) * 0x24);
    }

    bs = gBattleState;
    bs[0xA9] = object[0x63];

    flags = object[0x66];
    if ((s8)object[0x67] < 0) {
        flags |= 0x80;
    }
    bs[0xAA] = flags;

    for (s32 i = 0; i < object[0x6D]; i++) {
        Heap_Free((*(void ***)(object + 0x38))[i]);
    }
    Heap_FreeRaw(*(void **)(object + 0x38));

    if (object[0x61] != 0) {
        for (s32 i = 0; i < object[0x61]; i++) {
            fn_800616A0((*(Entry **)(object + 0x3C))[i].b);
        }
        Heap_FreeRaw(*(void **)(object + 0x3C));
    }

    fn_80056A04(*(void **)(object + 0x50), 1);

    obj4c = *(VObj **)(object + 0x4C);
    if (obj4c != 0) {
        obj4c->v6(1);
    }

    fn_80057A10(*(void **)(object + 0x44), 1);
    fn_80057A10(*(void **)(object + 0x48), 1);
    Process_Unlink(*(void **)(object + 0x34));

    fn_80109020(gUiSelectMenuStrings + 0xBA);
    fn_8003F670(*(void **)(object + 0x30));
    fn_8006D8E8(*(void **)(object + 0x40));
    fn_8005C7C8(gUiSelectMenuStrings + 0xC7);
}
#pragma cplusplus reset
void Ui_ResetSelectPrompt(void *proc) {
    /* Clear select cursor index, then set the text banner from mode (0x6C) and selection state. */
    s32 Msg_Expand(void *);
    void TextBanner_SetString(s32, s32);
    extern u8 gUiSelectMenuStrings[];
    u8 mode;

    *(u8 *)((char *)proc + 0x62) = 0;
    if ((s8)*(u8 *)((char *)proc + 0x62) < 0) {
        mode = *(u8 *)((char *)proc + 0x6C);
        switch (mode) {
        case 1:
        case 2:
            TextBanner_SetString(*(s32 *)((char *)proc + 0x50), Msg_Expand(gUiSelectMenuStrings + 0x5A));
            break;
        case 4:
            TextBanner_SetString(*(s32 *)((char *)proc + 0x50), Msg_Expand(gUiSelectMenuStrings + 0x6B));
            break;
        default:
            TextBanner_SetString(*(s32 *)((char *)proc + 0x50), Msg_Expand(gUiSelectMenuStrings + 0x7B));
            break;
        }
    } else {
        mode = *(u8 *)((char *)proc + 0x6C);
        switch (mode) {
        case 1:
        case 2:
            TextBanner_SetString(*(s32 *)((char *)proc + 0x50), Msg_Expand(gUiSelectMenuStrings + 0x8A));
            break;
        case 4:
            TextBanner_SetString(*(s32 *)((char *)proc + 0x50), Msg_Expand(gUiSelectMenuStrings + 0x9B));
            break;
        default:
            TextBanner_SetString(*(s32 *)((char *)proc + 0x50), Msg_Expand(gUiSelectMenuStrings + 0xAB));
            break;
        }
    }
}

#pragma cplusplus on
extern "C" void fn_8012CF7C(void *arg0) {
    void fn_8000C070(void *, s32);
    void fn_8000C188(void *);
    void fn_80057E6C(void *);
    void fn_801305F8(void *);
    void fn_801475FC(void *, s32);
    f32 fn_8005A028(s32, f32, f32, f32, f32);
    u8 fn_80166D8C(void *);
    void fn_801673D0(void *);
    void fn_80167190(void *, s32, f32, f32);
    void fn_8016758C(void *, void *, s32, f32, f32);
    extern u8 lbl_80275AC0[];
    extern u8 lbl_80330D68[];
    extern void *lbl_80367240;
    extern s32 lbl_80368DC4;
    extern f32 lbl_8036A4EC;
    extern f32 lbl_8036A4E8;

    struct Obj {
        u8 pad[0x4C];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual s32 v2(s32) = 0;
    };

    long pressed;
    u32 trig;
    u8 col_u;
    s16 xpos;
    s8 col;
    u32 cur;
    u32 text;
    u32 prev;
    s32 sel;
    u8 flag;
    u8 *base;
    u8 idx;
    u8 fr;
    void **table;
    unsigned int a;
    register unsigned long b;
    u32 *pad;
    register Obj *item;
    register void *self;
    u8 *entry;

    self = arg0;
    pad = (u32 *)lbl_80367240;
    cur = pad[1];
    prev = pad[2];
    trig = pad[3];
    pressed = cur & (prev ^ cur);

    if (pressed & 0x800) {
        if (fn_80166D8C(lbl_80330D68) == 0) {
            table = *(void ***)((u8 *)self + 0x38);
            col_u = *((u8 *)self + 0x65);
            item = (Obj *)table[*((u8 *)self + 0x63)];
            col = (s8)col_u;
            base = (u8 *)item;
            base += col * 2;
            xpos = *(s16 *)(base + 0x38);
            text = item->v2(col);
            fn_8016758C(lbl_80330D68, self, text, (f32)xpos, lbl_8036A4E8);
            *(s32 *)lbl_80330D68 |= lbl_80368DC4;
        } else {
            fn_801673D0(lbl_80330D68);
        }
    }

    if (trig & 0x04000004) {
        fn_8000C188(self);
        fn_801475FC(lbl_80275AC0 + 0xDB, 0x64);
        fn_801673D0(lbl_80330D68);
        return;
    }

    if (trig & 0x01000001) {
        if ((s8)*((u8 *)self + 0x65) == 0) {
            if (*((u8 *)self + 0x64) == 0) {
                if (*((u8 *)self + 0x63) == 0) {
                    flag = 0;
                } else {
                    *((u8 *)self + 0x63) = *((u8 *)self + 0x63) - 1;
                    if ((s8)*((u8 *)self + 0x62) < 0) {
                        table = *(void ***)((u8 *)self + 0x38);
                        entry = (u8 *)table[*((u8 *)self + 0x63)];
                        *((u8 *)self + 0x65) = entry[0x21] - 1;
                    } else {
                        *((u8 *)self + 0x65) = 0;
                    }
                    goto anim_left;
                }
            } else {
            anim_left:
                *((u8 *)self + 0x64) = *((u8 *)self + 0x64) + 1;
                idx = *((u8 *)self + 0x63);
                fr = *((u8 *)self + 0x64);
                a = (idx + 1) * 0x120;
                b = idx * 0x120;
                *(s16 *)((u8 *)self + 0x68) = (s16)fn_8005A028(2, (f32)a, (f32)b, lbl_8036A4EC, (f32)fr);
                if (*((u8 *)self + 0x64) == 0x10) {
                    *((u8 *)self + 0x64) = 0;
                    if ((s8)*((u8 *)self + 0x62) < 0) {
                        fn_8000C070(self, 6);
                    } else {
                        fn_8000C070(self, 1);
                    }
                }
                flag = 1;
            }
            if (flag) {
                fn_801475FC(lbl_80275AC0 + 0xFC, 0x64);
                fn_80057E6C(*(void **)((u8 *)self + 0x44));
                fn_8000C070(self, 4);
            }
        } else {
            *((u8 *)self + 0x65) = *((u8 *)self + 0x65) - 1;
            {
                u8 *str = lbl_80275AC0 + 0x118;
                fn_801475FC(str, 0x64);
            }
        }
        if (fn_80166D8C(lbl_80330D68) != 0) {
            table = *(void ***)((u8 *)self + 0x38);
            col_u = *((u8 *)self + 0x65);
            item = (Obj *)table[*((u8 *)self + 0x63)];
            col = (s8)col_u;
            base = (u8 *)item;
            base += col * 2;
            register int xpos = *(s16 *)(base + 0x38);
            text = item->v2(col);
            fn_80167190(lbl_80330D68, text, (f32)xpos, lbl_8036A4E8);
        }
    } else if (trig & 0x02000002) {
        idx = *((u8 *)self + 0x63);
        table = *(void ***)((u8 *)self + 0x38);
        col_u = *((u8 *)self + 0x65);
        entry = (u8 *)table[idx];
        col = (s8)col_u;
        if (col == (s32)(entry[0x21] - 1)) {
            if (*((u8 *)self + 0x64) == 0) {
                if (idx == (s32)(*((u8 *)self + 0x6D) - 1)) {
                    flag = 0;
                } else {
                    *((u8 *)self + 0x63) = idx + 1;
                    *((u8 *)self + 0x65) = 0;
                    goto anim_right;
                }
            } else {
            anim_right:
                *((u8 *)self + 0x64) = *((u8 *)self + 0x64) + 1;
                idx = *((u8 *)self + 0x63);
                fr = *((u8 *)self + 0x64);
                a = (idx - 1) * 0x120;
                b = idx * 0x120;
                *(s16 *)((u8 *)self + 0x68) = (s16)fn_8005A028(2, (f32)a, (f32)b, lbl_8036A4EC, (f32)fr);
                if (*((u8 *)self + 0x64) == 0x10) {
                    *((u8 *)self + 0x64) = 0;
                    if ((s8)*((u8 *)self + 0x62) < 0) {
                        fn_8000C070(self, 6);
                    } else {
                        fn_8000C070(self, 1);
                    }
                }
                flag = 1;
            }
            if (flag) {
                fn_801475FC(lbl_80275AC0 + 0xFC, 0x64);
                fn_80057E6C(*(void **)((u8 *)self + 0x48));
                fn_8000C070(self, 5);
            }
        } else {
            *((u8 *)self + 0x65) = col + 1;
            {
                u8 *str = lbl_80275AC0 + 0x118;
                fn_801475FC(str, 0x64);
            }
        }
        if (fn_80166D8C(lbl_80330D68) != 0) {
            table = *(void ***)((u8 *)self + 0x38);
            col_u = *((u8 *)self + 0x65);
            item = (Obj *)table[*((u8 *)self + 0x63)];
            col = (s8)col_u;
            base = (u8 *)item;
            base += col * 2;
            register int xpos = *(s16 *)(base + 0x38);
            text = item->v2(col);
            fn_80167190(lbl_80330D68, text, (f32)xpos, lbl_8036A4E8);
        }
    } else if (pressed & 0x100) {
        sel = (s8)*((u8 *)self + 0x65) + *((u8 *)self + 0x63) * 0xA;
        if ((s32)*((u8 *)self + 0x66) == sel) {
#pragma global_optimizer off
            *((u8 *)self + 0x67) *= -1;
#pragma global_optimizer reset
        } else {
            *((u8 *)self + 0x66) = (u8)sel;
            *((u8 *)self + 0x67) = 1;
        }
        fn_801305F8(self);
        fn_801475FC(lbl_80275AC0 + 0x134, 0x64);
    } else if (pressed & 0x200) {
        if (fn_80166D8C(lbl_80330D68) != 0) {
            fn_801673D0(lbl_80330D68);
        } else {
            fn_8000C070(self, 0);
        }
    }
}
#pragma cplusplus reset

s32 fn_8012D554(void) {
    return 0;
}

void fn_8012D55C(void *proc) {
s32 Msg_Expand(void *);
void TextBanner_SetString(s32, s32);
extern u8 gUiSelectMenuStrings[];
u8 mode;
*(s8 *)((char *)proc+0x62)=-1;
if (*(s8 *)((char *)proc+0x62)<0) {mode=*(u8 *)((char *)proc+0x6C); switch(mode) {case 1: case 2: TextBanner_SetString(*(s32 *)((char *)proc+0x50),Msg_Expand(gUiSelectMenuStrings+90)); break;case 4: TextBanner_SetString(*(s32 *)((char *)proc+0x50),Msg_Expand(gUiSelectMenuStrings+107)); break;default: TextBanner_SetString(*(s32 *)((char *)proc+0x50),Msg_Expand(gUiSelectMenuStrings+123)); break;}} else {mode=*(u8 *)((char *)proc+0x6C); switch(mode) {case 1: case 2: TextBanner_SetString(*(s32 *)((char *)proc+0x50),Msg_Expand(gUiSelectMenuStrings+138)); break;case 4: TextBanner_SetString(*(s32 *)((char *)proc+0x50),Msg_Expand(gUiSelectMenuStrings+155)); break;default: TextBanner_SetString(*(s32 *)((char *)proc+0x50),Msg_Expand(gUiSelectMenuStrings+171)); break;}}}

#pragma push
#pragma optimization_level 4
void fn_8012D6A4(void *arg0) {
    void Process_Goto(void *, s32);
    s32 Msg_Expand(void *);
    void Unit_FocusCamera(void *, s32);
    void TextBanner_SetString(void *, s32);
    void fn_80057860(void *, s32);
    void fn_80057E6C(void *);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    void fn_8011ABC0(void *);
    void Ui_PlaySeCue(void *, s32);
    void fn_801EAA38(void *);
    extern u8 gUiSelectMenuStrings[];
    extern void *gPadInput;
    extern f32 lbl_8036A4EC;

    void *self;
    u32 *pad;
    s32 cur;
    u32 prev;
    u32 trig;
    u32 pressed;
    u8 flag;
    u8 mode;
    s16 pos;
    u8 (*cb)(void *, void *);
    void *item;
    void **table;
    u8 *entry;
    u8 idx;
    u8 fr;
    s32 a;
    s32 b;

    self = arg0;
    pad = (u32 *)gPadInput;
    cur = pad[1];
    prev = pad[2];
    trig = pad[3];
    pressed = cur & (prev ^ cur);

    if (cur & 0x400) {
        *((u8 *)self + 0x6F) = 0x10;
        trig = *(u32 *)((u8 *)gPadInput + 0x10);
    } else {
        *((u8 *)self + 0x6F) = 8;
    }

    if (pressed & 0x1000) {
        mode = *((u8 *)self + 0x6C);
        if (mode == 1) {
            fn_8011ABC0(self);
            TextBanner_SetString(*(void **)((u8 *)self + 0x50), Msg_Expand(gUiSelectMenuStrings + 0x155));
            Process_Goto(self, 8);
        } else if (mode == 2) {
            fn_801EAA38(self);
            TextBanner_SetString(*(void **)((u8 *)self + 0x50), Msg_Expand(gUiSelectMenuStrings + 0x155));
            Process_Goto(self, 8);
        }
    } else if (pressed & 0x800) {
        Process_Goto(self, 7);
    } else if (trig & 0x01000001) {
        if (*((u8 *)self + 0x64) == 0) {
            if (*((u8 *)self + 0x63) == 0) {
                flag = 0;
            } else {
                *((u8 *)self + 0x63) = *((u8 *)self + 0x63) - 1;
                if ((s8)*((u8 *)self + 0x62) < 0) {
                    table = *(void ***)((u8 *)self + 0x38);
                    entry = (u8 *)table[*((u8 *)self + 0x63)];
                    *((u8 *)self + 0x65) = entry[0x21] - 1;
                } else {
                    *((u8 *)self + 0x65) = 0;
                }
                goto anim_up;
            }
        } else {
        anim_up:
            *((u8 *)self + 0x64) = *((u8 *)self + 0x64) + 1;
            idx = *((u8 *)self + 0x63);
            fr = *((u8 *)self + 0x64);
            a = (idx + 1) * 0x120;
            b = idx * 0x120;
            *(s16 *)((u8 *)self + 0x68) = (s16)Math_EaseOutPow(2, (f32)a, (f32)b, lbl_8036A4EC, (f32)fr);
            if (*((u8 *)self + 0x64) == 0x10) {
                *((u8 *)self + 0x64) = 0;
                if ((s8)*((u8 *)self + 0x62) < 0) {
                    Process_Goto(self, 6);
                } else {
                    Process_Goto(self, 1);
                }
            }
            flag = 1;
        }
        if (flag != 0) {
            Ui_PlaySeCue(gUiSelectMenuStrings + 0xFC, 0x64);
            fn_80057E6C(*(void **)((u8 *)self + 0x44));
            Process_Goto(self, 4);
        }
    } else if (trig & 0x02000002) {
        if (*((u8 *)self + 0x64) == 0) {
            if ((s32)*((u8 *)self + 0x63) == (s32)(*((u8 *)self + 0x6D) - 1)) {
                flag = 0;
            } else {
                *((u8 *)self + 0x63) = *((u8 *)self + 0x63) + 1;
                *((u8 *)self + 0x65) = 0;
                goto anim_down;
            }
        } else {
        anim_down:
            *((u8 *)self + 0x64) = *((u8 *)self + 0x64) + 1;
            idx = *((u8 *)self + 0x63);
            fr = *((u8 *)self + 0x64);
            a = (idx - 1) * 0x120;
            b = idx * 0x120;
            *(s16 *)((u8 *)self + 0x68) = (s16)Math_EaseOutPow(2, (f32)a, (f32)b, lbl_8036A4EC, (f32)fr);
            if (*((u8 *)self + 0x64) == 0x10) {
                *((u8 *)self + 0x64) = 0;
                if ((s8)*((u8 *)self + 0x62) < 0) {
                    Process_Goto(self, 6);
                } else {
                    Process_Goto(self, 1);
                }
            }
            flag = 1;
        }
        if (flag != 0) {
            Ui_PlaySeCue(gUiSelectMenuStrings + 0xFC, 0x64);
            fn_80057E6C(*(void **)((u8 *)self + 0x48));
            Process_Goto(self, 5);
        }
    } else if (trig & 0x08000008) {
        s32 mode = *((u8 *)self + 0x62);
        if ((s8)mode == 0) {
            if (pressed & 0x08000008) {
                Process_Goto(self, 6);
                Ui_PlaySeCue(gUiSelectMenuStrings + 0xDB, 0x64);
            }
        } else {
            *((u8 *)self + 0x62) = mode - 1;
            Ui_PlaySeCue(gUiSelectMenuStrings + 0xDB, 0x64);
            mode = *((u8 *)self + 0x62);
            if ((s8)mode != 0) {
                pos = *(s16 *)((u8 *)self + 0x6A);
                if ((s8)mode - (pos / 32) == 0) {
                    *(s16 *)((u8 *)self + 0x6A) = (s16)(pos - *((u8 *)self + 0x6F));
                    fn_80057860(*(void **)((u8 *)self + 0x4C), *(s16 *)((u8 *)self + 0x6A));
                    Process_Goto(self, 2);
                }
            }
        }
    } else if (trig & 0x04000004) {
        mode = *((u8 *)self + 0x62);
        if ((s8)mode == (s32)(*((u8 *)self + 0x61) - 1)) {
            if (pressed & 0x04000004) {
                *((u8 *)self + 0x62) = 0;
                *(s16 *)((u8 *)self + 0x6A) = 0;
                fn_80057860(*(void **)((u8 *)self + 0x4C), *(s16 *)((u8 *)self + 0x6A));
                Ui_PlaySeCue(gUiSelectMenuStrings + 0xDB, 0x64);
            }
        } else {
            *((u8 *)self + 0x62) = mode + 1;
            Ui_PlaySeCue(gUiSelectMenuStrings + 0xDB, 0x64);
            mode = *((u8 *)self + 0x62);
            if ((s8)mode != (s32)(*((u8 *)self + 0x61) - 1)) {
                pos = *(s16 *)((u8 *)self + 0x6A);
                if ((s8)mode - (pos / 32) == 8) {
                    *(s16 *)((u8 *)self + 0x6A) = (s16)(pos + *((u8 *)self + 0x6F));
                    fn_80057860(*(void **)((u8 *)self + 0x4C), *(s16 *)((u8 *)self + 0x6A));
                    Process_Goto(self, 3);
                }
            }
        }
    } else if (pressed & 0x200) {
        Ui_PlaySeCue(gUiSelectMenuStrings + 0x166, 0x64);
        Process_Goto(self, 0);
    } else if (pressed & 0x100) {
        cb = *(u8 (**)(void *, void *))((u8 *)self + 0x54);
        item = *(void **)((u8 *)*(void **)((u8 *)self + 0x3C) + (s8)*((u8 *)self + 0x62) * 0x24);
        if (cb != NULL) {
            if (cb(self, item) != 0) {
                Ui_PlaySeCue(gUiSelectMenuStrings + 0x176, 0x64);
            } else {
                Ui_PlaySeCue(gUiSelectMenuStrings + 0x186, 0x64);
            }
        } else {
            Unit_FocusCamera(item, 1);
            Process_Goto(self, 0);
        }
    }
}
#pragma pop
s32 fn_8012DC74(void *arg0)
{
    void Process_Goto(void *, s32);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    extern f32 lbl_8036A4EC;
    u8 *state;
    u8 idx;
    u8 fr;
    s32 a;
    s32 b;

    state = (u8 *)arg0;

    if (state[0x64] == 0) {
        if (state[0x63] == (s32)(state[0x6D] - 1)) {
            return 0;
        }
        state[0x63]++;
        state[0x65] = 0;
    }

    state[0x64]++;
    idx = state[0x63];
    fr = state[0x64];
    a = (idx - 1) * 0x120;
    b = idx * 0x120;
    *(s16 *)(state + 0x68) = (s16)Math_EaseOutPow(2, (f32)a, (f32)b, lbl_8036A4EC, (f32)fr);

    if (state[0x64] == 0x10) {
        state[0x64] = 0;
        if ((s8)state[0x62] < 0) {
            Process_Goto(state, 6);
        } else {
            Process_Goto(state, 1);
        }
    }

    return 1;
}

s32 fn_8012DD94(void *arg0)
{
    void Process_Goto(void *, s32);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    extern f32 lbl_8036A4EC;
    u8 *state;
    u8 *table;
    u8 *entry;
    u8 idx;
    u8 fr;
    s32 a;
    s32 b;

    state = (u8 *)arg0;

    if (state[0x64] == 0) {
        if (state[0x63] == 0) {
            return 0;
        }
        state[0x63]--;
        if ((s8)state[0x62] < 0) {
            table = *(u8 **)(state + 0x38);
            entry = *(u8 **)(table + state[0x63] * 4);
            state[0x65] = entry[0x21] - 1;
        } else {
            state[0x65] = 0;
        }
    }

    state[0x64]++;
    idx = state[0x63];
    fr = state[0x64];
    a = (idx + 1) * 0x120;
    b = idx * 0x120;
    *(s16 *)(state + 0x68) = (s16)Math_EaseOutPow(2, (f32)a, (f32)b, lbl_8036A4EC, (f32)fr);

    if (state[0x64] == 0x10) {
        state[0x64] = 0;
        if ((s8)state[0x62] < 0) {
            Process_Goto(state, 6);
        } else {
            Process_Goto(state, 1);
        }
    }

    return 1;
}

void fn_8012DED8(void *arg0) {
    void fn_80057860(s32, s32);
    void Process_ClearFunc(void *);
    s16 *p;

    p = (s16 *)((u8 *)arg0 + 0x6A);
    *p = (s16)(*p - *((u8 *)arg0 + 0x6F));
    fn_80057860(*(s32 *)((u8 *)arg0 + 0x4C), *p);
    if (*p % 32 == 0) {
        Process_ClearFunc(arg0);
    }
}

void fn_8012DF40(void *arg0) {
    void fn_80057860(s32, s32);
    void Process_ClearFunc(void *);
    s16 *p;

    p = (s16 *)((u8 *)arg0 + 0x6A);
    *p = (s16)(*p + *((u8 *)arg0 + 0x6F));
    fn_80057860(*(s32 *)((u8 *)arg0 + 0x4C), *p);
    if (*p % 32 == 0) {
        Process_ClearFunc(arg0);
    }
}

#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
#pragma optimization_level 3
void fn_8012DFA8(void *arg0) {
    typedef struct { s16 a; s16 b; } S16Pair;
    void Process_Goto(void *, s32);
    void *Msg_Expand(void *);
    s32 Item_GetMaxRange(void *);
    void *Archive_Load(void *);
    void fn_800506E0(void *, s32);
    void *fn_80056A60(void *);
    void TextBanner_SetString(void *, void *);
    void ScrollBar_RecreateArrows(void *, s32);
    void fn_80057860(void *, s16);
    void fn_80057880(void *, s32);
    void fn_80057898(void *, s32);
    void fn_800578A0(void *, f32);
    void fn_800578A8(void *, s32, s32, s32);
    void *fn_80057998(void *);
    void *fn_80057A64(void *, s32);
    void fn_80057E98(void *, s32, s32);
    void *Process_AttachFunc(void *, void *);
    void FileCache_Load(void *);
    void GActor_Finalize(void *);
    void *GActor_Create(void);
    s32 fn_800639B4(void);
    void *fn_8006D948(void *);
    void fn_800C1F1C(void *, void *);
    void *Heap_AllocRaw(s32);
    void *Heap_Alloc(s32);
    void Sound_Create(void *, void *);
    void fn_801305F8(void *);
    void fn_801A7218(void *, void *, s32);
    extern void fn_8012F360;
    extern u8 gUiSelectMenuStrings[];
    extern u8 lbl_8029115C[];
    extern u8 lbl_80291180[];
    extern u8 lbl_802911A4[];
    extern u8 lbl_80291258[];
    extern u8 lbl_8029127C[];
    extern u8 lbl_802912F4[];
    extern u8 lbl_80291318[];
    extern u8 lbl_802913BC[];
    extern u8 lbl_802913E0[];
    extern u8 lbl_80291404[];
    extern u8 gUnitLists[];
    extern u8 gUiContext[];
    extern u8 gBattleState[];
    extern u8 gBattle[];
    extern S16Pair lbl_8036A4E0;
    extern S16Pair lbl_8036A4E4;
    extern f32 lbl_8036A500;

    S16Pair spC;
    S16Pair sp8;
    s16 y;
    u8 *self;
    u8 *slot;
    void *node;
    void *tmp;
    void *entry;
    void *next;
    void *find;
    void *item;
    s32 off;
    s32 mask;
    s32 flags;
    s32 sel;
    s32 i;
    u8 mode;
    u8 *p;
    void **p28c;
    u8 aa;
    u8 v21;
    u8 v22;

    self = arg0;
    self[0x64] = 0;
    self[0x62] = 0;
    self[0x63] = 0;
    *(s16 *)(self + 0x68) = 0;
    *(s16 *)(self + 0x6A) = 0;
    self[0x6E] = 0;
    self[0x6F] = 8;
    self[0x66] = 0;
    self[0x65] = 0;
    self[0x67] = 1;
    FileCache_Load(gUiSelectMenuStrings + 0xC7);
    *(void **)(self + 0x40) = fn_8006D948(gUiSelectMenuStrings + 0x194);
    *(void **)(self + 0x30) = Archive_Load(gUiSelectMenuStrings + 0x1A8);
    Sound_Create(gUiSelectMenuStrings + 0xBA, self);
    self[0x61] = 0;
    mode = self[0x6C];
    switch (mode) {
    case 1:
        node = *(void **)gUnitLists;
        while (node != NULL) {
            node = *(void **)((u8 *)node + 0x184);
            self[0x61]++;
        }
        break;
    case 2:
        node = *(void **)(gUnitLists + 0x3C);
        while (node != NULL) {
            node = *(void **)((u8 *)node + 0x184);
            self[0x61]++;
        }
        break;
    case 3:
        node = *(void **)gUnitLists;
        while (node != NULL) {
            node = *(void **)((u8 *)node + 0x184);
            self[0x61]++;
        }
        node = *(void **)(gUnitLists + 0x3C);
        while (node != NULL) {
            node = *(void **)((u8 *)node + 0x184);
            self[0x61]++;
        }
        break;
    default:
        node = *(void **)(gUnitLists + self[0x60] * 0xC);
        while (node != NULL) {
            flags = *(s32 *)((u8 *)node + 0x1A0);
            node = *(void **)((u8 *)node + 0x184);
            if (!(flags & 8) && !(flags & 0x10)) {
                self[0x61]++;
            }
        }
        break;
    }
    if (self[0x61] == 0) {
        Process_Goto(self, 0);
        return;
    }
    *(void **)(self + 0x3C) = Heap_AllocRaw(self[0x61] * 0x24);
    slot = *(u8 **)(self + 0x3C);
    mode = self[0x6C];
    switch (mode) {
    case 1:
        mask = 0x010000DC;
        node = *(void **)gUnitLists;
        while (node != NULL) {
            next = *(void **)((u8 *)node + 0x184);
            if (!(*(s32 *)((u8 *)node + 0x1A0) & mask)) {
                *(void **)slot = node;
                tmp = *(void **)(slot + 4) = GActor_Create();
                *(void **)((u8 *)tmp + 4) = (u8 *)node + 0x1C;
                fn_800506E0(node, 0);
                *(s32 *)((u8 *)tmp + 0x44) = fn_800639B4();
                *(u32 *)tmp = *(u32 *)tmp | 0x50028400;
                GActor_Finalize(tmp);
                slot += 0x24;
            }
            node = next;
        }
        node = *(void **)gUnitLists;
        while (node != NULL) {
            next = *(void **)((u8 *)node + 0x184);
            if (*(s32 *)((u8 *)node + 0x1A0) & mask) {
                *(void **)slot = node;
                tmp = *(void **)(slot + 4) = GActor_Create();
                *(void **)((u8 *)tmp + 4) = (u8 *)node + 0x1C;
                fn_800506E0(node, 0);
                *(s32 *)((u8 *)tmp + 0x44) = fn_800639B4();
                *(u32 *)tmp = *(u32 *)tmp | 0x50028400;
                GActor_Finalize(tmp);
                slot += 0x24;
            }
            node = next;
        }
        break;
    case 2:
        node = *(void **)(gUnitLists + 0x3C);
        while (node != NULL) {
            next = *(void **)((u8 *)node + 0x184);
            if (*(s32 *)((u8 *)node + 0x1A0) & 0x400000) {
                *(void **)slot = node;
                tmp = *(void **)(slot + 4) = GActor_Create();
                *(void **)((u8 *)tmp + 4) = (u8 *)node + 0x1C;
                fn_800506E0(node, 0);
                *(s32 *)((u8 *)tmp + 0x44) = fn_800639B4();
                *(u32 *)tmp = *(u32 *)tmp | 0x50028400;
                GActor_Finalize(tmp);
                slot += 0x24;
            }
            node = next;
        }
        node = *(void **)(gUnitLists + 0x3C);
        while (node != NULL) {
            next = *(void **)((u8 *)node + 0x184);
            if (!(*(s32 *)((u8 *)node + 0x1A0) & 0x400000)) {
                *(void **)slot = node;
                tmp = *(void **)(slot + 4) = GActor_Create();
                *(void **)((u8 *)tmp + 4) = (u8 *)node + 0x1C;
                fn_800506E0(node, 0);
                *(s32 *)((u8 *)tmp + 0x44) = fn_800639B4();
                *(u32 *)tmp = *(u32 *)tmp | 0x50028400;
                GActor_Finalize(tmp);
                slot += 0x24;
            }
            node = next;
        }
        break;
    case 3:
        node = *(void **)gUnitLists;
        while (node != NULL) {
            next = *(void **)((u8 *)node + 0x184);
            *(void **)slot = node;
            tmp = *(void **)(slot + 4) = GActor_Create();
            *(void **)((u8 *)tmp + 4) = (u8 *)node + 0x1C;
            fn_800506E0(node, 0);
            *(s32 *)((u8 *)tmp + 0x44) = fn_800639B4();
            *(u32 *)tmp = *(u32 *)tmp | 0x50028400;
            GActor_Finalize(tmp);
            slot += 0x24;
            node = next;
        }
        node = *(void **)(gUnitLists + 0x3C);
        while (node != NULL) {
            next = *(void **)((u8 *)node + 0x184);
            *(void **)slot = node;
            tmp = *(void **)(slot + 4) = GActor_Create();
            *(void **)((u8 *)tmp + 4) = (u8 *)node + 0x1C;
            fn_800506E0(node, 0);
            *(s32 *)((u8 *)tmp + 0x44) = fn_800639B4();
            *(u32 *)tmp = *(u32 *)tmp | 0x50028400;
            GActor_Finalize(tmp);
            slot += 0x24;
            node = next;
        }
        break;
    default:
        node = *(void **)(gUnitLists + self[0x60] * 0xC);
        while (node != NULL) {
            flags = *(s32 *)((u8 *)node + 0x1A0);
            next = *(void **)((u8 *)node + 0x184);
            if (!(flags & 8) && !(flags & 0x10)) {
                *(void **)slot = node;
                tmp = *(void **)(slot + 4) = GActor_Create();
                *(void **)((u8 *)tmp + 4) = (u8 *)node + 0x1C;
                fn_800506E0(node, 0);
                *(s32 *)((u8 *)tmp + 0x44) = fn_800639B4();
                *(u32 *)tmp = *(u32 *)tmp | 0x50028400;
                GActor_Finalize(tmp);
                slot += 0x24;
            }
            node = next;
        }
        break;
    }

    slot = *(u8 **)(self + 0x3C);
    i = 0;
    while (i < self[0x61]) {
        p28c = (void **)(gBattle + 0x28C);
        fn_801A7218(gBattle, *(void **)slot, -1);
        *(s32 *)(slot + 0xC) = 0;
        *(s32 *)(slot + 0x10) = 0;
        fn_800C1F1C(*(void **)slot, slot + 0xC);
        if (p28c != NULL && *p28c != NULL) {
            *(void **)(slot + 8) = *p28c;
            item = *p28c;
            if (item != NULL) {
                v21 = *((u8 *)item + 0x1D);
            } else {
                v21 = 0;
            }
            slot[0x21] = v21;
            item = *p28c;
            if (item != NULL) {
                v22 = (u8)Item_GetMaxRange(item);
            } else {
                v22 = 0;
            }
            slot[0x22] = v22;
            slot[0x1C] = (u8)*(s16 *)(gBattle + 0x298);
            slot[0x1D] = (u8)*(s16 *)(gBattle + 0x29E);
            slot[0x1E] = (u8)*(s16 *)(gBattle + 0x2A0);
            slot[0x1F] = (u8)*(s16 *)(gBattle + 0x2A4);
            slot[0x20] = (u8)*(s16 *)(gBattle + 0x2A6);
        } else {
            *(void **)(slot + 8) = NULL;
            slot[0x21] = 0;
            slot[0x22] = 0;
            slot[0x1C] = 0;
            slot[0x1D] = 0;
            slot[0x1E] = (u8)*(s16 *)(gBattle + 0x2A0);
            slot[0x1F] = 0;
            slot[0x20] = (u8)*(s16 *)(gBattle + 0x2A6);
        }
        i++;
        slot += 0x24;
    }

    if (self[0x6C] == 4) {
        self[0x6D] = 1;
        *(void **)(self + 0x38) = Heap_AllocRaw(4);
        entry = Heap_Alloc(0x50);
        if (entry != NULL) {
            *(void **)((u8 *)entry + 0x4C) = lbl_80291404;
            *(void **)((u8 *)entry + 0x4C) = lbl_802913E0;
            ((u8 *)entry)[0x22] = 8;
            ((u8 *)entry)[0x20] = 3;
            *(s16 *)((u8 *)entry + 0x24) = 0x70;
            *(s16 *)((u8 *)entry + 0x26) = 0xF8;
            *(s16 *)((u8 *)entry + 0x28) = 0x189;
            ((u8 *)entry)[0x21] = ((u8 *)entry)[0x20];
            p = entry;
            i = 0;
            while (i < ((u8 *)entry)[0x21]) {
                *(s16 *)(p + 0x38) = *(s16 *)(p + 0x24);
                i++;
                p += 2;
            }
        }
        **(void ***)(self + 0x38) = entry;
        self[0x66] = 0;
        self[0x63] = 0;
    } else {
        self[0x6D] = 8;
        *(void **)(self + 0x38) = Heap_AllocRaw(0x20);
        entry = Heap_Alloc(0x50);
        if (entry != NULL) {
            *(void **)((u8 *)entry + 0x4C) = lbl_80291404;
            *(void **)((u8 *)entry + 0x4C) = lbl_802913BC;
            ((u8 *)entry)[0x22] = 0;
            ((u8 *)entry)[0x20] = 6;
            *(s16 *)((u8 *)entry + 0x24) = 0x70;
            *(s16 *)((u8 *)entry + 0x26) = 0xF8;
            *(s16 *)((u8 *)entry + 0x28) = 0x189;
            *(s16 *)((u8 *)entry + 0x2A) = 0x1B1;
            *(s16 *)((u8 *)entry + 0x2C) = 0x1D9;
            *(s16 *)((u8 *)entry + 0x2E) = 0x1F7;
            ((u8 *)entry)[0x21] = ((u8 *)entry)[0x20];
            p = entry;
            i = 0;
            while (i < ((u8 *)entry)[0x21]) {
                *(s16 *)(p + 0x38) = *(s16 *)(p + 0x24);
                i++;
                p += 2;
            }
        }
        *(void **)(*(u8 **)(self + 0x38) + 0) = entry;
        entry = Heap_Alloc(0x50);
        if (entry != NULL) {
            *(void **)((u8 *)entry + 0x4C) = lbl_80291404;
            *(void **)((u8 *)entry + 0x4C) = lbl_80291318;
            ((u8 *)entry)[0x22] = 1;
            ((u8 *)entry)[0x20] = 8;
            *(s16 *)((u8 *)entry + 0x24) = 0x70;
            *(s16 *)((u8 *)entry + 0x26) = 0x10C;
            *(s16 *)((u8 *)entry + 0x28) = 0x134;
            *(s16 *)((u8 *)entry + 0x2A) = 0x15C;
            *(s16 *)((u8 *)entry + 0x2C) = 0x184;
            *(s16 *)((u8 *)entry + 0x2E) = 0x1AC;
            *(s16 *)((u8 *)entry + 0x30) = 0x1D4;
            *(s16 *)((u8 *)entry + 0x32) = 0x1FC;
            ((u8 *)entry)[0x21] = ((u8 *)entry)[0x20];
            p = entry;
            i = 0;
            while (i < ((u8 *)entry)[0x21]) {
                *(s16 *)(p + 0x38) = *(s16 *)(p + 0x24);
                i++;
                p += 2;
            }
        }
        *(void **)(*(u8 **)(self + 0x38) + 4) = entry;
        entry = Heap_Alloc(0x50);
        if (entry != NULL) {
            *(void **)((u8 *)entry + 0x4C) = lbl_80291404;
            *(void **)((u8 *)entry + 0x4C) = lbl_802912F4;
            ((u8 *)entry)[0x22] = 2;
            ((u8 *)entry)[0x20] = 5;
            *(s16 *)((u8 *)entry + 0x24) = 0x70;
            *(s16 *)((u8 *)entry + 0x26) = 0x102;
            *(s16 *)((u8 *)entry + 0x28) = 0x189;
            *(s16 *)((u8 *)entry + 0x2A) = 0x1BB;
            *(s16 *)((u8 *)entry + 0x2C) = 0x1ED;
            ((u8 *)entry)[0x21] = ((u8 *)entry)[0x20];
            p = entry;
            i = 0;
            while (i < ((u8 *)entry)[0x21]) {
                *(s16 *)(p + 0x38) = *(s16 *)(p + 0x24);
                i++;
                p += 2;
            }
        }
        *(void **)(*(u8 **)(self + 0x38) + 8) = entry;
        entry = Heap_Alloc(0x50);
        if (entry != NULL) {
            *(void **)((u8 *)entry + 0x4C) = lbl_80291404;
            *(void **)((u8 *)entry + 0x4C) = lbl_8029127C;
            ((u8 *)entry)[0x22] = 3;
            ((u8 *)entry)[0x20] = 7;
            *(s16 *)((u8 *)entry + 0x24) = 0x70;
            *(s16 *)((u8 *)entry + 0x26) = 0x10C;
            *(s16 *)((u8 *)entry + 0x28) = 0x13E;
            *(s16 *)((u8 *)entry + 0x2A) = 0x166;
            *(s16 *)((u8 *)entry + 0x2C) = 0x198;
            *(s16 *)((u8 *)entry + 0x2E) = 0x1CA;
            *(s16 *)((u8 *)entry + 0x30) = 0x1FC;
            ((u8 *)entry)[0x21] = ((u8 *)entry)[0x20];
            p = entry;
            i = 0;
            while (i < ((u8 *)entry)[0x21]) {
                *(s16 *)(p + 0x38) = *(s16 *)(p + 0x24);
                i++;
                p += 2;
            }
        }
        *(void **)(*(u8 **)(self + 0x38) + 0xC) = entry;
        entry = Heap_Alloc(0x50);
        if (entry != NULL) {
            *(void **)((u8 *)entry + 0x4C) = lbl_80291404;
            *(void **)((u8 *)entry + 0x4C) = lbl_80291258;
            ((u8 *)entry)[0x22] = 4;
            ((u8 *)entry)[0x20] = 3;
            *(s16 *)((u8 *)entry + 0x24) = 0x70;
            *(s16 *)((u8 *)entry + 0x26) = 0x102;
            *(s16 *)((u8 *)entry + 0x28) = 0x184;
            ((u8 *)entry)[0x21] = ((u8 *)entry)[0x20];
            p = entry;
            i = 0;
            while (i < ((u8 *)entry)[0x21]) {
                *(s16 *)(p + 0x38) = *(s16 *)(p + 0x24);
                i++;
                p += 2;
            }
        }
        *(void **)(*(u8 **)(self + 0x38) + 0x10) = entry;
        entry = Heap_Alloc(0x50);
        if (entry != NULL) {
            *(void **)((u8 *)entry + 0x4C) = lbl_80291404;
            *(void **)((u8 *)entry + 0x4C) = lbl_802911A4;
            ((u8 *)entry)[0x22] = 5;
            ((u8 *)entry)[0x20] = 9;
            *(s16 *)((u8 *)entry + 0x24) = 0x70;
            *(s16 *)((u8 *)entry + 0x26) = 0x10F;
            *(s16 *)((u8 *)entry + 0x28) = 0x131;
            *(s16 *)((u8 *)entry + 0x2A) = 0x153;
            *(s16 *)((u8 *)entry + 0x2C) = 0x175;
            *(s16 *)((u8 *)entry + 0x2E) = 0x197;
            *(s16 *)((u8 *)entry + 0x30) = 0x1B9;
            *(s16 *)((u8 *)entry + 0x32) = 0x1DB;
            *(s16 *)((u8 *)entry + 0x34) = 0x1FD;
            ((u8 *)entry)[0x21] = ((u8 *)entry)[0x20];
            p = entry;
            i = 0;
            while (i < ((u8 *)entry)[0x21]) {
                *(s16 *)(p + 0x38) = *(s16 *)(p + 0x24);
                i++;
                p += 2;
            }
        }
        *(void **)(*(u8 **)(self + 0x38) + 0x14) = entry;
        entry = Heap_Alloc(0x50);
        if (entry != NULL) {
            *(void **)((u8 *)entry + 0x4C) = lbl_80291404;
            *(void **)((u8 *)entry + 0x4C) = lbl_80291180;
            ((u8 *)entry)[0x22] = 6;
            ((u8 *)entry)[0x20] = 3;
            *(s16 *)((u8 *)entry + 0x24) = 0x70;
            *(s16 *)((u8 *)entry + 0x26) = 0x102;
            *(s16 *)((u8 *)entry + 0x28) = 0x198;
            ((u8 *)entry)[0x21] = ((u8 *)entry)[0x20];
            p = entry;
            i = 0;
            while (i < ((u8 *)entry)[0x21]) {
                *(s16 *)(p + 0x38) = *(s16 *)(p + 0x24);
                i++;
                p += 2;
            }
            ((u8 *)entry)[0x21] = 2;
        }
        *(void **)(*(u8 **)(self + 0x38) + 0x18) = entry;
        entry = Heap_Alloc(0x50);
        if (entry != NULL) {
            *(void **)((u8 *)entry + 0x4C) = lbl_80291404;
            *(void **)((u8 *)entry + 0x4C) = lbl_8029115C;
            ((u8 *)entry)[0x22] = 7;
            ((u8 *)entry)[0x20] = 2;
            *(s16 *)((u8 *)entry + 0x24) = 0x70;
            *(s16 *)((u8 *)entry + 0x26) = 0x102;
            ((u8 *)entry)[0x21] = ((u8 *)entry)[0x20];
            p = entry;
            i = 0;
            while (i < ((u8 *)entry)[0x21]) {
                *(s16 *)(p + 0x38) = *(s16 *)(p + 0x24);
                i++;
                p += 2;
            }
        }
        *(void **)(*(u8 **)(self + 0x38) + 0x1C) = entry;
        aa = gBattleState[0xAA];
        self[0x66] = aa & 0x7F;
        if (aa & 0x80) {
            *(s8 *)(self + 0x67) = -1;
        }
        self[0x63] = gBattleState[0xA9];
    }

    *(s16 *)(self + 0x68) = (s16)(self[0x63] * 0x120);
    mode = self[0x6C];
    if ((s32)mode >= 3 || (s32)mode < 1) {
        fn_801305F8(self);
    }
    find = *(void **)(gBattleState + 0xB0);
    if (find == NULL) {
        sel = -1;
    } else {
        sel = 0;
        off = 0;
        slot = *(u8 **)(self + 0x3C);
        for (i = self[0x61]; i > 0; i--) {
            if (*(void **)(slot + off) == find) {
                goto found_sel;
            }
            off += 0x24;
            sel++;
        }
        sel = -1;
    found_sel:;
    }
    if (sel >= 0) {
        self[0x62] = (u8)sel;
        if ((sel - (*(s16 *)(self + 0x6A) / 32)) >= 8) {
            if (sel == (self[0x61] - 1)) {
                *(s16 *)(self + 0x6A) = (s16)((sel - 8) << 5);
            } else {
                *(s16 *)(self + 0x6A) = (s16)((sel - 7) << 5);
            }
        }
    }
    sp8 = lbl_8036A4E0;
    spC = lbl_8036A4E4;
    y = (s16)((((s8)self[0x62] << 5) + 0x60) - *(s16 *)(self + 0x6A));
    *(s16 *)(self + 0x58) = sp8.a;
    *(s16 *)(self + 0x5A) = y;
    *(s16 *)(self + 0x5C) = spC.a;
    sp8.b = y;
    *(s16 *)(self + 0x5E) = spC.b;

    tmp = Heap_Alloc(0x58);
    if (tmp != NULL) {
        tmp = fn_80057A64(tmp, 1);
    }
    *(void **)(self + 0x44) = tmp;
    fn_80057E98(*(void **)(self + 0x44), 0x32, 0x4C);
    tmp = Heap_Alloc(0x58);
    if (tmp != NULL) {
        tmp = fn_80057A64(tmp, 2);
    }
    *(void **)(self + 0x48) = tmp;
    fn_80057E98(*(void **)(self + 0x48), 0x230, 0x4C);
    tmp = Heap_Alloc(0x30);
    if (tmp != NULL) {
        tmp = fn_80057998(tmp);
    }
    *(void **)(self + 0x4C) = tmp;
    fn_800578A8(*(void **)(self + 0x4C), 0x22A, 0x60, 0x118);
    fn_80057898(*(void **)(self + 0x4C), self[0x61] << 5);
    fn_80057880(*(void **)(self + 0x4C), 0x120);
    fn_80057860(*(void **)(self + 0x4C), *(s16 *)(self + 0x6A));
    fn_800578A0(*(void **)(self + 0x4C), lbl_8036A500);
    ScrollBar_RecreateArrows(*(void **)(self + 0x4C), 1);
    tmp = Heap_Alloc(0x18);
    if (tmp != NULL) {
        tmp = fn_80056A60(tmp);
    }
    *(void **)(self + 0x50) = tmp;
    if ((s8)self[0x62] < 0) {
        mode = self[0x6C];
        switch (mode) {
        case 1:
        case 2:
            TextBanner_SetString(*(void **)(self + 0x50), Msg_Expand(gUiSelectMenuStrings + 0x5A));
            break;
        case 4:
            TextBanner_SetString(*(void **)(self + 0x50), Msg_Expand(gUiSelectMenuStrings + 0x6B));
            break;
        default:
            TextBanner_SetString(*(void **)(self + 0x50), Msg_Expand(gUiSelectMenuStrings + 0x7B));
            break;
        }
    } else {
        mode = self[0x6C];
        switch (mode) {
        case 1:
        case 2:
            TextBanner_SetString(*(void **)(self + 0x50), Msg_Expand(gUiSelectMenuStrings + 0x8A));
            break;
        case 4:
            TextBanner_SetString(*(void **)(self + 0x50), Msg_Expand(gUiSelectMenuStrings + 0x9B));
            break;
        default:
            TextBanner_SetString(*(void **)(self + 0x50), Msg_Expand(gUiSelectMenuStrings + 0xAB));
            break;
        }
    }
    *(void **)(self + 0x34) = Process_AttachFunc(&fn_8012F360, self);
    gUiContext[8] = 0x80;
}
#pragma pop
#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8012EF04(void *arg0) {
    u8 FileCache_IsReady(void *);
    void fn_8005C8B4(void *);
    void Process_ClearFunc(void *);
    extern u8 gUiSelectMenuStrings[];

    fn_8005C8B4(gUiSelectMenuStrings + 0xC7);
    if (FileCache_IsReady(gUiSelectMenuStrings + 0xC7)) {
        Process_ClearFunc(arg0);
    }
}

void fn_8012EF5C(void *arg0, void *arg1, s32 arg2) {
#pragma cplusplus on
    extern f32 lbl_8036A504;
    extern f32 lbl_8036A508;
    struct Drawer {
        u8 pad[0x4C];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void header(void *, f32, f32) = 0;
        virtual void row(void *, s32, s32, f32, f32) = 0;
    };
    f32 x;
    f32 y;
    s32 rowY;
    s32 offset;
    s32 i;
    u8 *entry;
    s32 column;
    u8 *self = (u8 *)arg1;
    x = (f32)(arg2 * 0x120 - *(s16 *)(self + 0x68));
    ((Drawer *)arg0)->header(*(void **)(self + 0x40), lbl_8036A504 + x, lbl_8036A508);
    entry = *(u8 **)(self + 0x3C);
    i = 0;
    rowY = 0x60;
    offset = 0;
    while (i < self[0x61]) {
        s32 scroll = *(s16 *)(self + 0x6A);
        s32 lo = scroll / 32;
        s32 hi = lo + 8;
        u8 visible;
        y = (f32)(rowY - scroll);
        if (scroll % 32 != 0) hi++;
        if (i >= lo && i <= hi) visible = 1;
        else visible = 0;
        if (visible) {
            for (column = 1; column < ((u8 *)arg0)[0x20]; column++) {
                u8 mode = self[0x6C];
                s32 color = 1;
                if (mode == 1) {
                    u32 flags = *(u32 *)(*(u8 **)entry + 0x1A0);
                    if (flags & 0x200000) color = 3;
                    else if (flags & 0x10) color = 0;
                    else if (flags & 0x10000) color = 0x13;
                } else if (mode == 2) {
                    u32 flags = *(u32 *)(*(u8 **)entry + 0x1A0);
                    if (flags & 0x200000) color = 3;
                    else if (!(flags & 0x400000)) color = 0;
                }
                ((Drawer *)arg0)->row(*(u8 **)(self + 0x3C) + offset, color, column, x, y);
            }
        }
        rowY += 0x20;
        offset += 0x24;
        i++;
        entry += 0x24;
    }
#pragma cplusplus reset
}

void fn_8012F154(void *arg0, void *arg1, u8 arg2, s32 arg3, f32 x, f32 y) {
#pragma cplusplus on
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetCallback(void (*)(void), s32);
    void Prim2D_PrepareTex(void);
    void Ui_ScissorUnitListRightRows(void);
    void fn_8001003C(s16, s16, s32, s32, s32, void *, ...);

    extern f32 lbl_8036A500;
    extern f32 lbl_8036A50C;
    extern f32 lbl_8036A510;

    struct Obj {
        u8 pad[0x4C];
        virtual void *v0(void *, s32);
    };

    f32 fx = x;
    f32 fy = y;
    s32 idx = arg3;
    u8 flag = arg2;
    Obj *self = (Obj *)arg0;
    void *drawable;
    s16 offset;
    u8 *row;

    drawable = self->v0(arg1, idx);

    row = (u8 *)self + idx * 2;
    offset = *(s16 *)(row + 0x24);
    fx += (f32)offset;

    if (drawable != 0) {
        Prim2D_Begin();
        Prim2D_SetTransform(fx, fy, lbl_8036A500, lbl_8036A50C);
        Prim2D_SetTex(0, 0x13);
        Prim2D_SetColorByte(0xFF);
        Prim2D_SetCallback(Ui_ScissorUnitListRightRows, 0);
        Prim2D_PrepareTex();
        fn_8001003C(0, 0, flag, 1, 0, drawable, lbl_8036A50C, lbl_8036A510);
    }
#pragma cplusplus reset
}

#pragma global_optimizer on
s32 fn_8012F26C(void) {
    return 0;
}

/* Draw a translucent fill for the unit-list body at (x, y), height = rowCount*24. */
void Ui_DrawUnitListFill(void *panel, void *tex, f32 x, f32 y) {
    void Prim2D_EmitQuad(void);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetCallback(void (*)(void), s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Ui_ScissorUnitListRight(void);
    extern f32 lbl_8036A500;
    extern f32 lbl_8036A50C;
    extern f32 lbl_8036A510;
    extern f32 lbl_8036A514;
    extern f32 lbl_8036A518;

    Prim2D_Begin();
    Prim2D_SetTransform(x, y, lbl_8036A500, lbl_8036A50C);
    Prim2D_BindTexture(tex, 3, 0x11);
    Prim2D_SetCallback(Ui_ScissorUnitListRight, 0);
    Prim2D_SetColorByte(0xC0);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv(lbl_8036A510, lbl_8036A510, lbl_8036A510, (f32)(*(u8 *)((u8 *)panel + 0x22) * 0x18), lbl_8036A514, lbl_8036A518);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
}

#pragma cplusplus on
#pragma opt_lifetimes off
extern "C" void fn_8012F360(void *arg0) {
    void Prim2D_EmitQuad(void);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Prim2D_ResetState(void);
    void Ui_DrawUnitListModels(void *);
    void Ui_DrawUnitCountBanner(void *);
    void fn_8012EF5C(void *, void *, s32);
    void fn_8012F5CC(void *);
    void fn_801302F4(void *);
    extern f32 lbl_8036A500;
    extern f32 lbl_8036A50C;
    extern f32 lbl_8036A510;
    extern f32 lbl_8036A51C;
    extern f32 lbl_8036A520;
    extern f64 lbl_8036A4F0;
    struct Obj {
        u8 pad[0x4C];
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6(s32, s32 *, s32 *, s32 *, s32 *);
    };
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 var_r29;
    s32 var_r28;
    s32 var_r31;
    void *var_r30;
    s32 sp8;

    Ui_DrawUnitListModels(arg0);
    var_r30 = arg0;
    Ui_DrawUnitCountBanner(var_r30);
    fn_8012F5CC(var_r30);
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036A51C, lbl_8036A520, lbl_8036A500, lbl_8036A50C);
    Prim2D_BindTexture(*(void **)((u8 *)var_r30 + 0x40), 4, 0x11);
    Prim2D_ClearCallbacks();
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
    {
        u8 digit_pair = *((u8 *)var_r30 + 0x66);
        void *item = ((void **)*(void **)((u8 *)var_r30 + 0x38))[digit_pair / 10];
        ((Obj *)item)->v6(digit_pair % 10, &sp8, &spC, &sp10, &sp14);
    }
    var_r31 = sp10 - sp8;
    var_r29 = sp14 - spC;
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv((f32)((0x30 - var_r31) / 2), lbl_8036A510, (f32)sp8, (f32)spC, (f32)var_r31, (f32)var_r29);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    var_r28 = 0;
    var_r31 = var_r28;
    Prim2D_ResetState();
    var_r29 = 0x38E38E39;
    for (; var_r28 < *((u8 *)var_r30 + 0x6D); var_r31 += 4, var_r28 += 1) {
        s16 val = *(s16 *)((u8 *)var_r30 + 0x68);
        s32 adj;
        s32 quot;
        u8 in_range;
        quot = val / 288;
        adj = quot;
        if ((val % 288) != 0) {
            adj = quot + 1;
        }
        if ((var_r28 >= quot) && (var_r28 <= adj)) {
            in_range = 1;
        } else {
            in_range = 0;
        }
        if (in_range != 0) {
            fn_8012EF5C(*(void **)((u8 *)*(void **)((u8 *)var_r30 + 0x38) + var_r31), var_r30, var_r28);
        }
    }
    fn_801302F4(var_r30);
    *((u8 *)var_r30 + 0x6E) += 1;
}
#pragma opt_lifetimes reset
#pragma cplusplus reset

void fn_8012F5A8(s32 unused0, s32 unused1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5) {
    *arg2 = 0;
    *arg3 = 0x14;
    *arg4 = 0x30;
    *arg5 = 0x28;
}

#pragma use_lmw_stmw on
void fn_8012F5CC(void *arg0) {
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SwapUvV(void);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_SetCallback(void (*)(void), s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void fn_8001003C(s32, s32, s32, s32, s32, f32, f32, void *, ...);
    f32 fn_80059EB8(f32, s32, f32, s32);
    void *Msg_ResolveName(s32);
    void Ui_ScissorUnitListRows(void);
    extern f64 lbl_8036A4F0;
    extern f32 lbl_8036A4EC;
    extern f32 lbl_8036A500;
    extern f32 lbl_8036A50C;
    extern f32 lbl_8036A510;
    extern f32 lbl_8036A518;
    extern f32 lbl_8036A524;
    extern f32 lbl_8036A528;
    extern f32 lbl_8036A52C;
    extern f32 lbl_8036A530;
    extern f32 lbl_8036A534;
    extern f32 lbl_8036A538;
    extern f32 lbl_8036A53C;
    extern f32 lbl_8036A540;
    extern f32 lbl_8036A544;
    extern f32 lbl_8036A548;
    extern f32 lbl_8036A54C;
    extern f32 lbl_8036A550;
    extern u8 gUiSelectMenuStrings[];

    s32 unk6A;
    s32 lo;
    s32 hi;
    u8 inRange;
    u8 mode;
    void *item;
    f32 f30;
    void *str;
    u8 *self;
    s32 y1;
    s32 y2;
    s32 y3;
    void *list;
    s32 i;
    u8 icon;

    self = (u8 *)arg0;
    list = *(void **)(self + 0x3C);
    i = 0;
    y1 = 0x60;
    y2 = 0x6C;
    y3 = 0x77;
    while (i < self[0x61]) {
        unk6A = *(s16 *)(self + 0x6A);
        f30 = (f32)(y1 - unk6A);
        item = *(void **)list;
        lo = unk6A / 32;
        hi = lo + 8;
        if ((unk6A % 32) != 0) {
            hi += 1;
        }
        if ((i >= lo) && (i <= hi)) {
            inRange = 1;
        } else {
            inRange = 0;
        }
        if (inRange != 0) {
            mode = self[0x6C];
            icon = 1;
            if (mode == 1) {
                s32 flags = *(s32 *)((u8 *)item + 0x1A0);
                if (flags & 0x200000) {
                    icon = 3;
                } else if (flags & 0x10) {
                    icon = 0;
                } else if (flags & 0x10000) {
                    icon = 0x13;
                }
            } else if (mode == 2) {
                s32 flags = *(s32 *)((u8 *)item + 0x1A0);
                if (flags & 0x200000) {
                    icon = 3;
                } else if (!(flags & 0x400000)) {
                    icon = 0;
                }
            }
            str = Msg_ResolveName(*(s32 *)((u8 *)item + 0x188));
            if (str != NULL) {
                Prim2D_Begin();
                Prim2D_SetTransform(lbl_8036A524, f30, lbl_8036A500, lbl_8036A50C);
                Prim2D_SetTex(0, 0x13);
                Prim2D_SetColorByte(0xFF);
                Prim2D_SetCallback(Ui_ScissorUnitListRows, 0);
                Prim2D_PrepareTex();
                fn_8001003C(0, 0, icon, 1, 0, lbl_8036A50C, lbl_8036A510, str);
            }
            unk6A = *(s16 *)(self + 0x6A);
            f30 = (f32)(y2 - unk6A);
            Prim2D_Begin();
            Prim2D_SetTransform(lbl_8036A528, f30, lbl_8036A52C, lbl_8036A50C);
            Prim2D_BindTexture(*(void **)(self + 0x40), 2, 0x11);
            Prim2D_SetCallback(Ui_ScissorUnitListRows, 0);
            Prim2D_SetColorByte(0xFF);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRectUv(lbl_8036A510, lbl_8036A510, lbl_8036A510, lbl_8036A510, lbl_8036A530, lbl_8036A4EC);
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            unk6A = *(s16 *)(self + 0x6A);
            f30 = (f32)(y3 - unk6A);
            Prim2D_Begin();
            Prim2D_SetTransform(lbl_8036A534, f30, lbl_8036A52C, lbl_8036A50C);
            Prim2D_SetTex(0, 0x12);
            Prim2D_SetCallback(Ui_ScissorUnitListRows, 0);
            Prim2D_SetColorByte(0x60);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_8036A510, lbl_8036A510, lbl_8036A538, lbl_8036A50C);
            Prim2D_EmitQuad();
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EndPrim();
        }
        y1 += 0x20;
        y2 += 0x20;
        y3 += 0x20;
        i += 1;
        list = (u8 *)list + 0x24;
    }
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036A53C, lbl_8036A540, lbl_8036A500, lbl_8036A50C);
    Prim2D_SetTex(0, 0x13);
    Prim2D_ClearCallbacks();
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
    fn_8001003C(0, 0, 1, 0, 1, lbl_8036A50C, lbl_8036A510, &gUiSelectMenuStrings[0x1C3], self[0x63] + 1);
    fn_8001003C(0x10, 0, 6, 0, 1, lbl_8036A50C, lbl_8036A510, &gUiSelectMenuStrings[0x1C6]);
    fn_8001003C(0x20, 0, 6, 0, 1, lbl_8036A50C, lbl_8036A510, (char *)gUiSelectMenuStrings + 0x1C3, self[0x6D]);
    {
        f32 f30_post = fn_80059EB8(lbl_8036A510, 0x40, lbl_8036A544, self[0x6E]) - lbl_8036A548;
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_8036A54C, lbl_8036A550 + (lbl_8036A518 + f30_post), lbl_8036A500, lbl_8036A50C);
        Prim2D_BindTexture(*(void **)(self + 0x40), 0x12, 0x11);
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_8036A510, lbl_8036A510, lbl_8036A510, lbl_8036A510, lbl_8036A4EC, lbl_8036A518);
        if ((s8)self[0x67] < 0) {
            Prim2D_SwapUvV();
        }
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
    }
}
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" void Ui_DrawUnitCountBanner(void *arg0) {
    /* Draw the unit-count banner for player (mode 1) or enemy (mode 2) lists. */
    void Prim2D_EmitQuad(void);
    void Prim2D_SwapUvU(void);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void fn_8000D8BC(s32, s32);
    void *Msg_Expand(void *);
    void Text_Draw(s32, s32, s32, void *, ...);
    extern f32 lbl_8036A4EC;
    extern f32 lbl_8036A50C;
    extern f32 lbl_8036A510;
    extern f32 lbl_8036A554;
    extern f32 lbl_8036A558;
    extern f32 lbl_8036A55C;
    extern f32 lbl_8036A560;
    extern f32 lbl_8036A564;
    extern f32 lbl_8036A568;
    extern u8 gUiSelectMenuStrings[];
    extern u8 gUnitLists[];
    extern s32 gTargetList[];

    struct Node {
        u8 pad0[0x184];
        struct Node *next;
        u8 pad1[0x1A0 - 0x188];
        s32 flags;
    };

    struct Drawer {
        u8 pad[0x4C];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void Draw(void *, f32, f32) = 0;
    };

    u8 *self = (u8 *)arg0;
    s16 limit;
    s16 count;
    Node *node;
    Drawer *drawer;

    switch (self[0x6C]) {
    case 1:
        Prim2D_Begin();
        Prim2D_ClearCallbacks();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_8036A510, lbl_8036A4EC, lbl_8036A554, lbl_8036A50C);
        Prim2D_BindTexture(*(void **)(self + 0x40), 0x14, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_8036A510, lbl_8036A510, lbl_8036A510, lbl_8036A510, lbl_8036A558, lbl_8036A55C);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_8036A558, lbl_8036A510, lbl_8036A510, lbl_8036A510, lbl_8036A558, lbl_8036A55C);
        Prim2D_SwapUvU();
        Prim2D_EndPrim();
        count = 0;
        node = *(Node **)gUnitLists;
        while (node != NULL) {
            s32 flags = node->flags;
            node = node->next;
            if (!(flags & 0x10))
                count++;
        }
        limit = (s16)gTargetList[0];
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A560);
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        if (count == limit) {
            Text_Draw(0x40, 0x10, 2, Msg_Expand(gUiSelectMenuStrings + 0x1C8));
            Text_Draw(0x140, 0x10, 1, gUiSelectMenuStrings + 0x1DA, count, limit);
        } else {
            fn_8000D8BC(0, limit - count);
            Text_Draw(0x40, 0x10, 2, Msg_Expand(gUiSelectMenuStrings + 0x1E7));
            Text_Draw(0x140, 0x10, 1, gUiSelectMenuStrings + 0x1F7, count, limit);
        }
        break;
    case 2:
        Prim2D_Begin();
        Prim2D_ClearCallbacks();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_8036A510, lbl_8036A4EC, lbl_8036A554, lbl_8036A50C);
        Prim2D_BindTexture(*(void **)(self + 0x40), 0x14, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_8036A510, lbl_8036A510, lbl_8036A510, lbl_8036A510, lbl_8036A558, lbl_8036A55C);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_8036A558, lbl_8036A510, lbl_8036A510, lbl_8036A510, lbl_8036A558, lbl_8036A55C);
        Prim2D_SwapUvU();
        Prim2D_EndPrim();
        limit = 0;
        node = *(Node **)(gUnitLists + 0x3C);
        while (node != NULL) {
            s32 flags = node->flags;
            node = node->next;
            if (flags & 0x400000)
                limit++;
        }
        count = (s16)gTargetList[0];
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A560);
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        if (limit == count) {
            Text_Draw(0x40, 0x10, 2, Msg_Expand(gUiSelectMenuStrings + 0x208));
            Text_Draw(0x128, 0x10, 1, gUiSelectMenuStrings + 0x1DA, limit, count);
        } else {
            fn_8000D8BC(0, count - limit);
            Text_Draw(0x40, 0x10, 2, Msg_Expand(gUiSelectMenuStrings + 0x21E));
            Text_Draw(0x128, 0x10, 1, gUiSelectMenuStrings + 0x1F7, limit, count);
        }
        break;
    default:
        drawer = *(Drawer **)(*(u8 **)(self + 0x38) + (self[0x63] << 2));
        drawer->Draw(*(void **)(self + 0x40), lbl_8036A564, lbl_8036A568);
        break;
    }
}
#pragma cplusplus reset

/* Draw the unit-list panel frame and scrolled body at (x, y). */
void Ui_DrawUnitListPanel(void *panel, void *tex, f32 x, f32 y) {
    void Prim2D_EmitQuad(void);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    extern f32 lbl_8036A550;
    extern f32 lbl_8036A554;
    extern f32 lbl_8036A56C;
    extern f32 lbl_8036A570;
    extern f32 lbl_8036A574;
    extern f32 lbl_8036A578;
    extern f32 lbl_8036A500;
    extern f32 lbl_8036A50C;
    extern f32 lbl_8036A510;

    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTransform(x, y, lbl_8036A554, lbl_8036A50C);
    Prim2D_BindTexture(tex, 0, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv(lbl_8036A510, lbl_8036A510, lbl_8036A510, lbl_8036A510, lbl_8036A56C, lbl_8036A570);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036A550 + x, lbl_8036A550 + y, lbl_8036A500, lbl_8036A50C);
    Prim2D_BindTexture(tex, 0x11, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv(lbl_8036A510, lbl_8036A510, lbl_8036A510, (f32)(*(u8 *)((u8 *)panel + 0x22) << 5), lbl_8036A574, lbl_8036A578);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
}

#pragma use_lmw_stmw on
void Ui_DrawUnitListModels(void *arg0) {
    /* Draw scrolled unit-list 3D models, dimming entries by filter mode. */
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void PSMTXConcat(void *, void *, void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetCallback(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void fn_80007340(void *, s32);
    void Prim2D_EndPrim(void);
    void fn_8004BD1C(void *, f32 *, f32);
    void Model_SetColor(void *, s32, s32, s32);
    void PSMTXTrans(void *, f32, f32, f32);
    void Model_SetAlpha(void *, s32);
    void fn_8005F780(void *, s32);
    void fn_80060060(void *);
    void fn_800609DC(void *);
    void fn_8004DDB8(s32);
    void Prim2D_ClearCallbacks(void);
    void Ui_ScissorUnitListLeft(void);
    void fn_801302C0(void);
    void Ui_ScissorUnitListRows(void);
    void fn_80069F04(void);
    void Ui_ScissorUnitListNarrow(void);
    extern f32 lbl_8036A57C;
    extern f32 lbl_8036A580;
    extern f32 lbl_8036A584;
    extern f32 lbl_8036A510;
    extern f32 lbl_8036A588;
    extern f32 lbl_8036A50C;
    extern f32 lbl_8036A4E8;
    extern f64 lbl_8036A4F0;
    extern f32 lbl_8036A518;
    extern f32 lbl_8036A58C;
    u8 spD4[0x30];
    u8 spA4[0x30];
    u8 sp74[0x30];
    u8 sp44[0x30];
    u8 sp14[0x30];
    f32 sp8[3];
    s32 y;
    void *list;
    s32 i;
    void *unit;
    void *model;
    void *self;
    s32 firstVis;
    s32 lastVis;
    s32 scrollY;
    u8 inRange;
    u8 filterMode;
    f32 baseX;
    f32 posX;
    f32 posY;

    self = arg0;
    PSMTXRotRad(spA4, 0x58, lbl_8036A57C);
    PSMTXRotRad(sp74, 0x59, lbl_8036A580);
    PSMTXRotRad(sp44, 0x58, lbl_8036A580);
    PSMTXScale(sp14, lbl_8036A584, lbl_8036A584, lbl_8036A584);
    PSMTXConcat(spA4, sp14, sp14);
    PSMTXConcat(sp74, sp14, sp14);
    PSMTXConcat(sp44, sp14, sp14);
    list = *(void **)((u8 *)self + 0x3C);
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036A510, lbl_8036A510, lbl_8036A588, lbl_8036A50C);
    Prim2D_SetTex(0, 0x410);
    Prim2D_SetColorByte(0xFF);
    Prim2D_SetCallback(Ui_ScissorUnitListLeft, 0);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(0xB);
    fn_80007340(fn_801302C0, 0);
    Prim2D_EndPrim();
    baseX = lbl_8036A4E8;
    i = 0;
    y = 0x60;
    while (i < *(u8 *)((u8 *)self + 0x61)) {
        unit = *(void **)list;
        model = *((void **)list + 1);
        fn_8004BD1C(unit, sp8, lbl_8036A584);
        scrollY = *(s16 *)((u8 *)self + 0x6A);
        posX = baseX + sp8[0];
        posY = sp8[1] + (f32)(y - scrollY);
        firstVis = scrollY / 32;
        lastVis = firstVis + 8;
        if ((scrollY % 32) != 0) {
            lastVis += 1;
        }
        if ((i >= firstVis) && (i <= lastVis)) {
            inRange = 1;
        } else {
            inRange = 0;
        }
        if (inRange != 0) {
            filterMode = *(u8 *)((u8 *)self + 0x6C);
            if ((filterMode == 1) && (*(u32 *)((u8 *)unit + 0x1A0) & 0x10)) {
                Model_SetColor(model, 0x40, 0x40, 0x40);
            } else if ((filterMode == 2) && !(*(u32 *)((u8 *)unit + 0x1A0) & 0x400000)) {
                Model_SetColor(model, 0x40, 0x40, 0x40);
            } else {
                Model_SetColor(model, 0x80, 0x80, 0x80);
            }
            PSMTXTrans(spD4, posX, lbl_8036A518 + posY, lbl_8036A58C);
            PSMTXConcat(spD4, sp14, (u8 *)model + 0x10);
            Model_SetAlpha(model, 0xFF);
            fn_8005F780(model, 0xFF);
            fn_80060060(model);
            fn_800609DC(model);
            Prim2D_Begin();
            Prim2D_SetTransform(lbl_8036A510, lbl_8036A510, lbl_8036A58C, lbl_8036A50C);
            Prim2D_SetTex(0, 0x410);
            Prim2D_SetColorByte(0xFF);
            scrollY = *(s16 *)((u8 *)self + 0x6A);
            if ((scrollY % 32) != 0) {
                Prim2D_SetCallback(Ui_ScissorUnitListRows, 0);
            }
            Prim2D_PrepareTex();
            Prim2D_AddPrim(0xB);
            fn_80007340(fn_80069F04, (s32)model);
            Prim2D_EndPrim();
        }
        y += 0x20;
        i += 1;
        list = (u8 *)list + 0x24;
    }
    Prim2D_Begin();
    Prim2D_SetCallback(Ui_ScissorUnitListNarrow, 0);
    Prim2D_PrepareTex();
    fn_8004DDB8(0x64);
    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
}
#pragma use_lmw_stmw reset

void fn_801302C0(void) {
    M2C_UNK fn_80059C2C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    fn_80059C2C(0, 0, 0x260, 0x1E0, 0);
}

#pragma cplusplus reset
#pragma push
#pragma optimization_level 4
void fn_801302F4(void *arg0) {
    void Prim2D_ClearCallbacks(void);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetColorByte(s32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Ui_DrawRouteIconEx(s16, s16, s32);
    void Prim2D_ResetState(void);
    void fn_80057E64(void *, s32);
    void fn_80057AE0(void *);
    void fn_80057020(void *);
    void fn_80056B0C(void *);
    extern f64 lbl_8036A4F0;
    extern f32 lbl_8036A50C;
    extern f32 lbl_8036A500;
    extern f32 lbl_8036A590;
    extern f32 lbl_8036A594;
    extern f32 lbl_8036A510;
    extern f32 lbl_8036A598;

    register s16 x;
    int ah;
    s8 unk62;
    int t;
    s16 temp;
    s16 y;
    register s16 w;
    register s16 h;
    register s32 aw;

    temp = *(s16 *)((u8 *)arg0 + 0x6A);
    if (temp % 32 == 0) {
        s16 var4;
        s16 var6;
        s16 var7;
        register s16 var8;
        void **arr;
        register u8 *ptr;

        unk62 = *(s8 *)((u8 *)arg0 + 0x62);
        if (0 > unk62) {
            var7 = 0;
            var8 = var7;
            var6 = 0x42;
            arr = *(void ***)((u8 *)arg0 + 0x38);
            ptr = (u8 *)arr[*(u8 *)((u8 *)arg0 + 0x63)];
            ptr += *(s8 *)((u8 *)arg0 + 0x65) * 2;
            var4 = *(s16 *)(ptr + 0x38);
        } else {
            var4 = 0x28;
            var7 = 0x1B8;
            var8 = 0x16;
            var6 = (s16)(((unk62 << 5) + 0x60) - temp);
        }
        t = *(s16 *)((u8 *)arg0 + 0x58) + var4;
        *(s16 *)((u8 *)arg0 + 0x58) = (s16)(t / 2);
        t = *(s16 *)((u8 *)arg0 + 0x5A) + var6;
        *(s16 *)((u8 *)arg0 + 0x5A) = (s16)(t / 2);
        t = *(s16 *)((u8 *)arg0 + 0x5C) + var7;
        *(s16 *)((u8 *)arg0 + 0x5C) = (s16)(t / 2);
        t = *(s16 *)((u8 *)arg0 + 0x5E) + var8;
        *(s16 *)((u8 *)arg0 + 0x5E) = (s16)(t / 2);
    }
    x = *(s16 *)((u8 *)arg0 + 0x58);
    y = *(s16 *)((u8 *)arg0 + 0x5A);
    w = *(s16 *)((u8 *)arg0 + 0x5C);
    h = *(s16 *)((u8 *)arg0 + 0x5E);
    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
    if ((s8)*(u8 *)((u8 *)arg0 + 0x62) >= 0) {
        s32 bw;
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x2E), (f32)(y + 5), lbl_8036A500, lbl_8036A50C);
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
        t = w + 0x10;
        aw = (s32)(lbl_8036A590 * (f32)t);
        ah = h / 2;
        bw = (s32)(lbl_8036A594 * (f32)t);
        fn_8008AB7C(aw / 2, ah, aw, 0x18, 0x19, 0x4B, 1);
        fn_8008AB7C(aw + bw / 2, ah, bw, 0x18, 0x19, 0x4B, 1);
    }
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036A510, lbl_8036A510, lbl_8036A598, lbl_8036A50C);
    Prim2D_SetTex(0, 0x11);
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
    Ui_DrawRouteIconEx(x, y, 1);
    Prim2D_ResetState();
    if (*(u8 *)((u8 *)arg0 + 0x63) != 0) {
        fn_80057E64(*(void **)((u8 *)arg0 + 0x44), 1);
    } else {
        fn_80057E64(*(void **)((u8 *)arg0 + 0x44), 0);
    }
    if ((s32)*(u8 *)((u8 *)arg0 + 0x63) < (s32)(*(u8 *)((u8 *)arg0 + 0x6D) - 1)) {
        fn_80057E64(*(void **)((u8 *)arg0 + 0x48), 1);
    } else {
        fn_80057E64(*(void **)((u8 *)arg0 + 0x48), 0);
    }
    fn_80057AE0(*(void **)((u8 *)arg0 + 0x44));
    fn_80057AE0(*(void **)((u8 *)arg0 + 0x48));
    fn_80057020(*(void **)((u8 *)arg0 + 0x4C));
    fn_80056B0C(*(void **)((u8 *)arg0 + 0x50));
}
#pragma cplusplus on
#pragma push
#pragma opt_lifetimes off
extern "C" void fn_801305F8(void *arg0) {
    struct Obj {
        u8 pad[0x4C];
        virtual void v0() = 0;
        virtual s32 v1(void *, s32) = 0;
    };
    struct Pair {
        s32 a, b;
    };
    struct Entry {
        s32 w0, w1, w2;
        Pair p1;
        Pair p2;
        u8 b0, b1, b2, b3, b4, b5, b6, b7;
        Entry &operator=(const Entry &rhs) {
            w0 = rhs.w0; w1 = rhs.w1; w2 = rhs.w2;
            p1 = rhs.p1;
            p2 = rhs.p2;
            b0 = rhs.b0; b1 = rhs.b1; b2 = rhs.b2; b3 = rhs.b3;
            b4 = rhs.b4; b5 = rhs.b5; b6 = rhs.b6; b7 = rhs.b7;
            return *this;
        }
    };
    struct Self {
        u8 pad0[0x38];
        Obj **table;
        Entry *entries;
        u8 pad40[0x21];
        u8 count;
        u8 pad62[4];
        u8 unk66;
        s8 unk67;
    };
    Self *self = (Self *)arg0;
    s32 i;
    s32 j;

    for (i = 0; i < self->count; i++) {
        for (j = 0; j < self->count - 1 - i; j++) {
            s32 a = self->unk67 * self->table[self->unk66 / 10]->v1(&self->entries[j + 1], self->unk66 % 10);
            s32 b = self->unk67 * self->table[self->unk66 / 10]->v1(&self->entries[j], self->unk66 % 10);
            if (b < a) {
                Entry tmp = self->entries[j];
                self->entries[j] = self->entries[j + 1];
                self->entries[j + 1] = tmp;
            }
        }
    }
}
#pragma pop
#pragma cplusplus reset

s32 fn_80130858(void) {
    return 0;
}

void Ui_ScissorUnitListLeft(void) {
    M2C_UNK GXSetScissor(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    GXSetScissor(0, 0, 0x80, 0x1E0);
}

void Ui_ScissorUnitListNarrow(void) {
    GXSetScissor(0, 0, 0x78, 0x1E0);
}

void Ui_ScissorUnitListRight(void) {
    GXSetScissor(0xF8, 0, 0x120, 0x1E0);
}

void Ui_ScissorUnitListRows(void) {
    GXSetScissor(0, 0x60, 0x260, 0x120);
}

void Ui_ScissorUnitListRightRows(void) {
    GXSetScissor(0xF8, 0x60, 0x120, 0x120);
}

void fn_80130950(void *unused, void *arg1, f32 farg0, f32 farg1) {
    void fn_8000A258(void);
    void fn_80009D74(f32, f32, f32, f32);
    void Prim2D_SetCallback(void (*)(void), s32);
    void fn_80009B8C(s32);
    void fn_8000A248(void);
    void *fn_80105C5C(void *, u8);
    void Ui_DrawIcon(void *, s32, s32, s32);
    void Ui_ScissorUnitListRightRows(void);
    extern f32 lbl_8036A500;
    extern f32 lbl_8036A50C;
    extern u8 gItemIconDrawer[];
    u8 *base;
    s32 off;
    s32 unit;
    s32 i;
    void *temp;

    fn_8000A258();
    fn_80009D74(farg0, farg1, lbl_8036A500, lbl_8036A50C);
    Prim2D_SetCallback(Ui_ScissorUnitListRightRows, 0);
    fn_80009B8C(0xFF);
    fn_8000A248();
    off = 0x102;
    unit = (s32)*(void **)arg1;
    base = gItemIconDrawer;
    i = 0;
    do {
        temp = fn_80105C5C((void *)(unit + 0x1BC), (u8)i);
        if (temp != NULL && *(u8 *)((u8 *)temp + 0x19) != 0) {
            Ui_DrawIcon(base, off, 0, *(u8 *)((u8 *)temp + 0x19));
            off += 0x20;
        }
        i += 1;
    } while (i < 0x62);
}

s32 fn_80130A40(void *arg0, void *arg1, s32 arg2) {
 void *fn_80105C5C(void *, u8);
 struct Unit { u8 pad[0x188]; void *data; u8 pad2[0x30]; u8 entries[1]; };
 s32 count=0;
 struct Unit *unit=*(struct Unit **)arg1;
 s32 i;
 void *temp;
 switch(arg2) {
 case 0: return -(s32)*(u16 *)((u8 *)unit->data+0x5A);
 case 1:
 for(i=0;i<0x62;i++) {temp=fn_80105C5C(unit->entries,(u8)i); if(temp && *((u8 *)temp+0x19)) count++;}
 return count;
 default: return 0;
 }
}

void *fn_80130AE4(void *unused, s32 arg1) {
    extern u16 gUiSelectMenuStrings[];

    switch (arg1) {
    case 1:
        return (u8 *)gUiSelectMenuStrings + 0x232;
    default:
        return (u8 *)gUiSelectMenuStrings + 0x247;
    }
}

void fn_80130B10(s32 unused, s32 kind, s32 *a, s32 *b, s32 *c, s32 *d) {
    switch (kind) {
    case 0:
        *a = 0;
        *b = 0;
        *c = 0x30;
        *d = 0x14;
        break;
    case 1:
        *a = 0;
        *b = 0x2A8;
        *c = 0x30;
        *d = 0x2BC;
        break;
    }
}

void *Ui_FormatSelectUnitName(void *buf, void *entry, s32 kind) {
    /* Format select-menu unit name into buf; kind 1/2 pick units at entry+0xC/+0x10. */
    s32 Msg_ResolveName(s32);
    s32 sprintf(char *dest, const char *fmt, ...);
    extern char gUiSelectMenuStrings[];

    switch (kind) {
    case 0:
        return 0;
    case 1: {
        void *unit = *(void **)((char *)entry + 0xC);
        if (unit == 0) {
            sprintf(buf, &gUiSelectMenuStrings[0x25B]);
        } else {
            sprintf(buf, &gUiSelectMenuStrings[0x264], Msg_ResolveName(*(s32 *)((char *)unit + 0x188)));
        }
        break;
    }
    case 2: {
        void *unit = *(void **)((char *)entry + 0x10);
        if (unit == 0) {
            sprintf(buf, &gUiSelectMenuStrings[0x25B]);
        } else {
            sprintf(buf, &gUiSelectMenuStrings[0x264], Msg_ResolveName(*(s32 *)((char *)unit + 0x188)));
        }
        break;
    }
    default:
        break;
    }
    return buf;
}

s32 fn_80130C54(s32 unused, void *arg1, s32 arg2) {
    void *obj;
    s32 n;

    obj = *(void **)arg1;
    n = 0;
    switch (arg2) {
    case 0:
        return -(s32)*(u16 *)((u8 *)*(void **)((u8 *)obj + 0x188) + 0x5A);
    case 1:
        if (*(u32 *)((u8 *)arg1 + 0xC) != 0) {
            n = 1;
        }
        if (*(u32 *)((u8 *)arg1 + 0x10) == 0) {
            return n;
        }
        return n + 1;
    default:
        return 0;
    }
}

void *fn_80130CB0(void *unused, s32 arg1) {
    extern u16 gUiSelectMenuStrings[];

    switch (arg1) {
    case 1:
        return (u8 *)gUiSelectMenuStrings + 0x267;
    default:
        return (u8 *)gUiSelectMenuStrings + 0x247;
    }
}

void fn_80130CDC(s32 unused, s32 kind, s32 *a, s32 *b, s32 *c, s32 *d) {
    switch (kind) {
    case 0:
        *a = 0;
        *b = 0;
        *c = 0x30;
        *d = 0x14;
        break;
    case 1:
        *a = 0;
        *b = 0x294;
        *c = 0x30;
        *d = 0x2A8;
        break;
    }
}

#pragma push
#pragma opt_pointer off
void fn_80130D34(void *arg0, void *arg1, u8 arg2, s32 arg3, f32 x, f32 y) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetCallback(void (*)(void), s32);
    void Prim2D_PrepareTex(void);
    void Ui_ScissorUnitListRightRows(void);
    void fn_8001003C(s16, s16, s32, s32, s32, void *, ...);

    extern f32 lbl_8036A500;
    extern f32 lbl_8036A50C;
    extern f32 lbl_8036A510;

    f32 drawY = y;
    f32 drawX = x;
    u8 *self;
    void *drawable;
    void **vtable;
    s16 offset;

    vtable = *(void ***)((u8 *)arg0 + 0x4C);
    self = (u8 *)arg0;
    drawable = ((void *(*)(void *, void *, s32))vtable[2])(
        self,
        arg1,
        arg3
    );

    offset = *(s16 *)((u8 *)((s16 *)self + arg3) + 0x24);
    drawX += (f32)offset;

    if (drawable != 0) {
        Prim2D_Begin();

        Prim2D_SetTransform(
            drawX,
            drawY,
            lbl_8036A500,
            lbl_8036A50C
        );

        Prim2D_SetTex(0, 0x13);
        Prim2D_SetColorByte(0xFF);
        Prim2D_SetCallback(Ui_ScissorUnitListRightRows, 0);
        Prim2D_PrepareTex();

        fn_8001003C(
            0,
            0,
            arg2,
            1,
            0,
            drawable,
            lbl_8036A50C,
            lbl_8036A510
        );
    }
}
#pragma pop
char *fn_80130E4C(char *buf, void **pUnit, u32 kind) {
    s32 Unit_GetWpnExp(void *, s32);
    s32 WpnRank_GetLetter(s32);
    int sprintf(char *, const char *, ...);
    extern u8 gUiSelectMenuStrings[];
    void *unit;

    unit = *pUnit;
    switch (kind) {
    case 0:
        return NULL;
    case 1:
        sprintf(buf, (char *)gUiSelectMenuStrings + 0x264, WpnRank_GetLetter(Unit_GetWpnExp(unit, 0)));
        break;
    case 2:
        sprintf(buf, (char *)gUiSelectMenuStrings + 0x264, WpnRank_GetLetter(Unit_GetWpnExp(unit, 1)));
        break;
    case 3:
        sprintf(buf, (char *)gUiSelectMenuStrings + 0x264, WpnRank_GetLetter(Unit_GetWpnExp(unit, 2)));
        break;
    case 4:
        sprintf(buf, (char *)gUiSelectMenuStrings + 0x264, WpnRank_GetLetter(Unit_GetWpnExp(unit, 3)));
        break;
    case 5:
        sprintf(buf, (char *)gUiSelectMenuStrings + 0x264, WpnRank_GetLetter(Unit_GetWpnExp(unit, 4)));
        break;
    case 6:
        sprintf(buf, (char *)gUiSelectMenuStrings + 0x264, WpnRank_GetLetter(Unit_GetWpnExp(unit, 5)));
        break;
    case 7:
        sprintf(buf, (char *)gUiSelectMenuStrings + 0x264, WpnRank_GetLetter(Unit_GetWpnExp(unit, 6)));
        break;
    case 8:
        sprintf(buf, (char *)gUiSelectMenuStrings + 0x264, WpnRank_GetLetter(Unit_GetWpnExp(unit, 7)));
        break;
    }
    return buf;
}

extern u16 jumptable_802911EC[];
s32 Ui_GetSelectMenuWpnExp(void *menu, void *entry, u32 col) {
    /* Select-menu column value: negated person sort key, or Unit_GetWpnExp for weapon types 0–7. */
    u8 Unit_GetWpnExp(void *, s32);
    void *unit;

    unit = *(void **)entry;
    switch (col) {
    case 0:
        return -(s32)*(u16 *)((u8 *)*(void **)((u8 *)unit + 0x188) + 0x5A);
    case 1:
        return (u8)Unit_GetWpnExp(unit, 0);
    case 2:
        return (u8)Unit_GetWpnExp(unit, 1);
    case 3:
        return (u8)Unit_GetWpnExp(unit, 2);
    case 4:
        return (u8)Unit_GetWpnExp(unit, 3);
    case 5:
        return (u8)Unit_GetWpnExp(unit, 4);
    case 6:
        return (u8)Unit_GetWpnExp(unit, 5);
    case 7:
        return (u8)Unit_GetWpnExp(unit, 6);
    case 8:
        return (u8)Unit_GetWpnExp(unit, 7);
    default:
        return 0;
    }
}

void *fn_801310F4(s32 arg0, u32 arg1) {
    extern u8 gUiSelectMenuStrings[];
    switch (arg1) {
    case 1:
        return &gUiSelectMenuStrings[0x27B];
    case 2:
        return &gUiSelectMenuStrings[0x28D];
    case 3:
        return &gUiSelectMenuStrings[0x29F];
    case 4:
        return &gUiSelectMenuStrings[0x2B1];
    case 5:
        return &gUiSelectMenuStrings[0x2C3];
    case 6:
        return &gUiSelectMenuStrings[0x2D5];
    case 7:
        return &gUiSelectMenuStrings[0x2E7];
    case 8:
        return &gUiSelectMenuStrings[0x2F9];
    case 0:
    default:
        return &gUiSelectMenuStrings[0x247];
    }
}

void fn_801311A4(s32 unused,s32 index,s32 *left,s32 *top,s32 *right,s32 *bottom) { switch(index) {case 0: *left=0; *top=1; *right=0x30; *bottom=20; return;
case 1: *left=0; *top=500; *right=0x30; *bottom=520; return;
case 2: *left=0; *top=520; *right=0x30; *bottom=540; return;
case 3: *left=0; *top=540; *right=0x30; *bottom=560; return;
case 4: *left=0; *top=560; *right=0x30; *bottom=580; return;
case 5: *left=0; *top=580; *right=0x30; *bottom=600; return;
case 6: *left=0; *top=600; *right=0x30; *bottom=620; return;
case 7: *left=0; *top=620; *right=0x30; *bottom=640; return;
case 8: *left=0; *top=640; *right=0x30; *bottom=660; return;
}}

void *fn_80131308(void *arg0, void **arg1, s32 arg2) {
s32 Msg_ResolveName(s32);
s32 fn_8010418C(void *,s32);
s32 fn_8010424C(void *);
s32 sprintf(char *,const char *,...);
char *strcat(char *,const char *);
extern char gUiSelectMenuStrings[];
char buf[8];
void *out;
void *list;
s32 i;
char *strings;
out=arg0;
list=(u8 *)*arg1+0x1a4;
switch(arg2) {
case 0: return 0;
case 1: {
void *name=*(void **)((u8 *)*arg1+0x194);
if(name) sprintf(out,gUiSelectMenuStrings+0x264,Msg_ResolveName(*(s32 *)((u8 *)name+0x188)));
else sprintf(out,gUiSelectMenuStrings+0x25b);
break;
}
case 2:
if(fn_8010424C(list)==0) sprintf(out,gUiSelectMenuStrings+0x25b);
else {
sprintf(out,gUiSelectMenuStrings+0x30c);
strings=gUiSelectMenuStrings;
for(i=0;i<fn_8010424C(list);i++) {
sprintf(buf,strings+0x30d,fn_8010418C(list,i)-1);
strcat(out,buf);
}
}
break;
}
return out;
}

extern s32 fn_8010424C(void*);
s32 fn_80131464(s32 unused, void **arg1, s32 arg2) {
    void *temp_r3;

    temp_r3 = *arg1;
    switch (arg2) {
    case 0:
        return -*(u16 *)((u8 *)*(void **)((u8 *)temp_r3 + 0x188) + 0x5A);
    case 1:
        return *(s32 *)((u8 *)temp_r3 + 0x194) != 0;
    case 2:
        return fn_8010424C((u8 *)temp_r3 + 0x1A4);
    default:
        return 0;
    }
}

void *fn_801314DC(void *unused, s32 arg1) {
    extern u16 gUiSelectMenuStrings[];

    switch (arg1) {
    case 1:
        return (u8 *)gUiSelectMenuStrings + 0x314;
    case 2:
        return (u8 *)gUiSelectMenuStrings + 0x328;
    default:
        return (u8 *)gUiSelectMenuStrings + 0x247;
    }
}

void fn_80131524(s32 unused, s32 kind, s32 *a, s32 *b, s32 *c, s32 *d) {
    switch (kind) {
    case 0:
        *a = 0;
        *b = 0;
        *c = 0x30;
        *d = 0x14;
        break;
    case 1:
        *a = 0;
        *b = 0x1CC;
        *c = 0x30;
        *d = 0x1E0;
        break;
    case 2:
        *a = 0;
        *b = 0x1E0;
        *c = 0x30;
        *d = 0x1F4;
        break;
    }
}

void *fn_801315B0(void *arg0,void *arg1,s32 index) {
s32 sprintf(char *,const char *,...);
s8 Unit_GetMov(void *);
s8 Unit_GetCon(void *);
s8 fn_8003A1E0(void *);
extern char gUiSelectMenuStrings[];
void *unit=*(void **)arg1;
u32 a,b;
switch(index) {
case 0:return 0;
case 1:sprintf(arg0,gUiSelectMenuStrings+0x33c,*(u8 *)((u8 *)arg1+0x1f)); break;
case 2:sprintf(arg0,gUiSelectMenuStrings+0x33c,*(u8 *)((u8 *)arg1+0x20)); break;
case 3:
a=*(u8 *)((u8 *)arg1+0x21);
if(a==0) sprintf(arg0,gUiSelectMenuStrings+0x340);
else { b=*(u8 *)((u8 *)arg1+0x22);
if(a!=b) sprintf(arg0,gUiSelectMenuStrings+0x345,a,b);
else sprintf(arg0,gUiSelectMenuStrings+0x33c,a);
}
break;
case 4:sprintf(arg0,gUiSelectMenuStrings+0x33c,Unit_GetMov(unit));break;
case 5:sprintf(arg0,gUiSelectMenuStrings+0x33c,Unit_GetCon(unit));break;
case 6:sprintf(arg0,gUiSelectMenuStrings+0x33c,fn_8003A1E0(unit));break;
}
return arg0;
}

s32 fn_80131714(void *arg0, u8 *arg1, u32 arg2)
{
    s32 Unit_GetMov(void *);
    s32 Unit_GetCon(void *);
    s32 fn_8003A1E0(void *);

    void *p;

    p = *(void **)arg1;

    switch (arg2) {
    case 0:
        return -(s32)*(u16 *)((u8 *)*(void **)((u8 *)p + 0x188) + 0x5A);
    case 1:
        return arg1[0x1F];
    case 2:
        return arg1[0x20];
    case 3:
        return arg1[0x21] + arg1[0x22] * 100;
    case 4:
        return (s8)Unit_GetMov(p);
    case 5:
        return (s8)Unit_GetCon(p);
    case 6:
        return (s8)fn_8003A1E0(p);
    default:
        return 0;
    }
}

void *fn_801317B0(s32 arg0, s32 arg1) {
    extern u8 gUiSelectMenuStrings[];
    switch (arg1) {
    case 1:
        return &gUiSelectMenuStrings[0x34B];
    case 2:
        return &gUiSelectMenuStrings[0x35F];
    case 3:
        return &gUiSelectMenuStrings[0x376];
    case 4:
        return &gUiSelectMenuStrings[0x38B];
    case 5:
        return &gUiSelectMenuStrings[0x39F];
    case 6:
        return &gUiSelectMenuStrings[0x3B4];
    default:
        return &gUiSelectMenuStrings[0x247];
    }
}

/* Return the atlas UV rect for select-menu icon index. */
void Ui_GetSelectMenuIconRect(s32 unused, s32 index, s32 *left, s32 *top, s32 *right, s32 *bottom)
{
  switch (index)
  {
    case 0:
      *left = 0;
      *top = 0;
      *right = 0x30;
      *bottom = 0x14;
      return;

    case 1:
      *left = 0;
      *top = 0x154;
      *right = 0x30;
      *bottom = 0x168;
      return;

    case 2:
      *left = 0;
      *top = 0x168;
      *right = 0x30;
      *bottom = 0x17c;
      return;

    case 3:
      *left = 0;
      *top = 0x17c;
      *right = 0x30;
      *bottom = 0x190;
      return;

    case 4:
      *left = 0;
      *top = 0x190;
      *right = 0x30;
      *bottom = 0x1a4;
      return;

    case 5:
      *left = 0;
      *top = 0x1a4;
      *right = 0x30;
      *bottom = 0x1b8;
      return;

    case 6:
      *left = 0;
      *top = 0x1b8;
      *right = 0x30;
      *bottom = 0x1cc;
      return;
  }
}

void *fn_8013196C(void *arg0,void *arg1,s32 arg2) {
 void *fn_8001ED58(u32);
 s32 sprintf(char *,const char *,...);
 extern char gUiSelectMenuStrings[];
 u32 value;
 switch(arg2) {
 case 0: return 0;
 case 1:
 value=M2C_FIELD(arg1,u32 *,8);
 if(value==0) sprintf(arg0,gUiSelectMenuStrings+0x25b);
 else sprintf(arg0,gUiSelectMenuStrings+0x264,fn_8001ED58(value));
 break;
 case 2:
 value=M2C_FIELD(arg1,u8 *,0x1c);
 if(value==0) sprintf(arg0,gUiSelectMenuStrings+0x340);
 else sprintf(arg0,gUiSelectMenuStrings+0x3ca,value);
 break;
 case 3:
 value=M2C_FIELD(arg1,u8 *,0x1d);
 if(value==0) sprintf(arg0,gUiSelectMenuStrings+0x340);
 else sprintf(arg0,gUiSelectMenuStrings+0x3ca,value);
 break;
 case 4:
 sprintf(arg0,gUiSelectMenuStrings+0x3ca,M2C_FIELD(arg1,u8 *,0x1e));
 break;
 }
 return arg0;
}

s32 fn_80131AA8(s32 arg0, void *arg1, s32 arg2) {
    void *temp_r3;
    u16 temp_r0;
    temp_r3 = M2C_FIELD(arg1, void **, 0);
    switch (arg2) {
    case 0:
        temp_r3 = M2C_FIELD(temp_r3, void **, 0x188);
        temp_r0 = M2C_FIELD(temp_r3, u16 *, 0x5A);
        return -temp_r0;
    case 1:
        temp_r3 = M2C_FIELD(arg1, void **, 8);
        if (temp_r3 == NULL) {
            return 0;
        }
        return M2C_FIELD(temp_r3, u16 *, 0xE);
    case 2:
        return M2C_FIELD(arg1, u8 *, 0x1C);
    case 3:
        return M2C_FIELD(arg1, u8 *, 0x1D);
    case 4:
        return M2C_FIELD(arg1, u8 *, 0x1E);
    default:
        return 0;
    }
}

void *fn_80131B24(s32 arg0, s32 arg1) {
    extern u8 gUiSelectMenuStrings[];
    switch (arg1) {
    case 1:
        return &gUiSelectMenuStrings[0x3CE];
    case 2:
        return &gUiSelectMenuStrings[0x3E3];
    case 3:
        return &gUiSelectMenuStrings[0x3F5];
    case 4:
        return &gUiSelectMenuStrings[0x408];
    default:
        return &gUiSelectMenuStrings[0x247];
    }
}

/* Write the atlas left/top/right/bottom for select-menu combat icon index 0-4. */
void Ui_GetSelectMenuCombatIconRect(s32 unused, s32 index, s32 *left, s32 *top, s32 *right, s32 *bottom)
{
  switch (index)
  {
    case 0:
      *left = 0;
      *top = 0;
      *right = 0x30;
      *bottom = 0x14;
      return;

    case 1:
      *left = 0;
      *top = 0x104;
      *right = 0x30;
      *bottom = 0x118;
      return;

    case 2:
      *left = 0;
      *top = 0x118;
      *right = 0x30;
      *bottom = 0x12C;
      return;

    case 3:
      *left = 0;
      *top = 0x12C;
      *right = 0x30;
      *bottom = 0x140;
      return;

    case 4:
      *left = 0;
      *top = 0x140;
      *right = 0x30;
      *bottom = 0x154;
      return;
  }
}

char *fn_80131C78(char *buf, void **pUnit, u32 kind) {
    s32 Unit_GetCarryWtLimit(void *);
    s32 Unit_GetMagAtk(void *);
    s32 fn_8003AF28(void *);
    s32 fn_8003AEB0(void *);
    s32 fn_8003ACF8(void *);
    s32 fn_8003AA40(void *);
    s32 fn_8003A778(void *);
    int sprintf(char *, const char *, ...);
    extern u8 gUiSelectMenuStrings[];
    void *unit;
    u8 *cls;
    s8 val;

    unit = *pUnit;
    cls = *(u8 **)((u8 *)unit + 0x18c);

    switch (kind) {
    case 0:
        return NULL;
    case 1:
        val = Unit_GetCarryWtLimit(unit);
        if (val >= (s8)cls[0x4d]) {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x41b,
                    (char *)gUiSelectMenuStrings + 0x423, val,
                    (char *)gUiSelectMenuStrings + 0x428);
        } else {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x33c, val);
        }
        break;
    case 2:
        val = Unit_GetMagAtk(unit);
        if (val >= (s8)cls[0x4e]) {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x41b,
                    (char *)gUiSelectMenuStrings + 0x423, val,
                    (char *)gUiSelectMenuStrings + 0x428);
        } else {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x33c, val);
        }
        break;
    case 3:
        val = fn_8003AF28(unit);
        if (val >= (s8)cls[0x4f]) {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x41b,
                    (char *)gUiSelectMenuStrings + 0x423, val,
                    (char *)gUiSelectMenuStrings + 0x428);
        } else {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x33c, val);
        }
        break;
    case 4:
        val = fn_8003AEB0(unit);
        if (val >= (s8)cls[0x50]) {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x41b,
                    (char *)gUiSelectMenuStrings + 0x423, val,
                    (char *)gUiSelectMenuStrings + 0x428);
        } else {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x33c, val);
        }
        break;
    case 5:
        val = fn_8003ACF8(unit);
        if (val >= 0x28) {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x41b,
                    (char *)gUiSelectMenuStrings + 0x423, val,
                    (char *)gUiSelectMenuStrings + 0x428);
        } else {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x33c, val);
        }
        break;
    case 6:
        val = fn_8003AA40(unit);
        if (val >= (s8)cls[0x52]) {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x41b,
                    (char *)gUiSelectMenuStrings + 0x423, val,
                    (char *)gUiSelectMenuStrings + 0x428);
        } else {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x33c, val);
        }
        break;
    case 7:
        val = fn_8003A778(unit);
        if (val >= (s8)cls[0x53]) {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x41b,
                    (char *)gUiSelectMenuStrings + 0x423, val,
                    (char *)gUiSelectMenuStrings + 0x428);
        } else {
            sprintf(buf, (char *)gUiSelectMenuStrings + 0x33c, val);
        }
        break;
    }
    return buf;
}

s32 fn_80131F70(void *arg0, void *arg1, u32 arg2) {
    s32 Unit_GetCarryWtLimit(void *);
    s32 Unit_GetMagAtk(void *);
    s32 fn_8003AF28(void *);
    s32 fn_8003AEB0(void *);
    s32 fn_8003ACF8(void *);
    s32 fn_8003AA40(void *);
    s32 fn_8003A778(void *);
    void *p;

    p = *(void **)arg1;
    switch (arg2) {
    case 0:
        return -(s32)*(u16 *)((u8 *)*(void **)((u8 *)p + 0x188) + 0x5A);
    case 1:
        return (s8)Unit_GetCarryWtLimit(p);
    case 2:
        return (s8)Unit_GetMagAtk(p);
    case 3:
        return (s8)fn_8003AF28(p);
    case 4:
        return (s8)fn_8003AEB0(p);
    case 5:
        return (s8)fn_8003ACF8(p);
    case 6:
        return (s8)fn_8003AA40(p);
    case 7:
        return (s8)fn_8003A778(p);
    default:
        return 0;
    }
}

void *fn_80132018(s32 arg0, u32 arg1) {
    extern u8 gUiSelectMenuStrings[];
    switch (arg1) {
    case 1:
        return &gUiSelectMenuStrings[0x42B];
    case 2:
        return &gUiSelectMenuStrings[0x43E];
    case 3:
        return &gUiSelectMenuStrings[0x452];
    case 4:
        return &gUiSelectMenuStrings[0x466];
    case 5:
        return &gUiSelectMenuStrings[0x47B];
    case 6:
        return &gUiSelectMenuStrings[0x48F];
    case 7:
        return &gUiSelectMenuStrings[0x4A2];
    case 0:
    default:
        return &gUiSelectMenuStrings[0x247];
    }
}

void fn_801320B8(s32 unused, s32 index, s32 *left, s32 *top, s32 *right, s32 *bottom)
{
 switch(index) {
case 0: *left=0; *top=0; *right=0x30; *bottom=20; return;
case 1: *left=0; *top=120; *right=0x30; *bottom=140; return;
case 2: *left=0; *top=140; *right=0x30; *bottom=160; return;
case 3: *left=0; *top=160; *right=0x30; *bottom=180; return;
case 4: *left=0; *top=180; *right=0x30; *bottom=200; return;
case 5: *left=0; *top=200; *right=0x30; *bottom=220; return;
case 6: *left=0; *top=220; *right=0x30; *bottom=240; return;
case 7: *left=0; *top=240; *right=0x30; *bottom=260; return;
}
}

void *fn_801321F4(void *arg0,void **arg1,s32 arg2) {
u8 fn_800386B0(void *);
s8 Unit_GetMaxHp(void *);
void *fn_800A8978(void *);
s32 sprintf(char *,const char *,...);
extern char gUiSelectMenuStrings[];
s8 hp;
void *unit=*arg1;
switch(arg2) {
case 0:return 0;
case 1:return fn_800A8978(*(void **)((u8 *)unit+0x18c));
case 2:sprintf(arg0,gUiSelectMenuStrings+0x33c,*(s8 *)((u8 *)unit+0x19a));break;
case 3:
if(fn_800386B0(unit)==0xff) sprintf(arg0,gUiSelectMenuStrings+0x340);
else sprintf(arg0,gUiSelectMenuStrings+0x33c,fn_800386B0(unit));
break;
case 4:sprintf(arg0,gUiSelectMenuStrings+0x33c,*(s8 *)((u8 *)unit+0x1a8));break;
case 5:
hp=Unit_GetMaxHp(unit);
if(hp>=*(s8 *)((u8 *)*(void **)((u8 *)unit+0x18c)+0x4c))
sprintf(arg0,gUiSelectMenuStrings+0x4b6,gUiSelectMenuStrings+0x423,hp,gUiSelectMenuStrings+0x428);
else sprintf(arg0,gUiSelectMenuStrings+0x4bf,hp);
break;
}
return arg0;
}

s32 fn_8013236C(s32 unused, void **arg1, s32 arg2) {
    u8 fn_800386B0(void *);
    s8 Unit_GetMaxHp(void *);
    void *temp_r3;

    temp_r3 = *arg1;
    switch (arg2) {
    case 0:
        return -*(u16 *)((u8 *)*(void **)((u8 *)temp_r3 + 0x188) + 0x5A);
    case 1:
        return -*(u16 *)((u8 *)*(void **)((u8 *)temp_r3 + 0x18C) + 0x38);
    case 2:
        return *(s8 *)((u8 *)temp_r3 + 0x19A);
    case 3:
        return (u8)fn_800386B0(temp_r3);
    case 4:
        return *(s8 *)((u8 *)temp_r3 + 0x1A8);
    case 5:
        return Unit_GetMaxHp(temp_r3);
    default:
        return 0;
    }
}

void *fn_80132414(s32 arg0, s32 arg1) {
    extern u8 gUiSelectMenuStrings[];
    switch (arg1) {
    case 1:
        return &gUiSelectMenuStrings[0x4C4];
    case 2:
        return &gUiSelectMenuStrings[0x4D9];
    case 3:
        return &gUiSelectMenuStrings[0x4EB];
    case 4:
        return &gUiSelectMenuStrings[0x4FE];
    case 5:
        return &gUiSelectMenuStrings[0x510];
    default:
        return &gUiSelectMenuStrings[0x247];
    }
}

/* Write the atlas left/top/right/bottom for select-menu stat icon index 0-5. */
void Ui_GetSelectMenuStatIconRect(s32 unused, s32 index, s32 *left, s32 *top, s32 *right, s32 *bottom)
{
  switch (index)
  {
    case 0:
      *left = 0;
      *top = 0;
      *right = 0x30;
      *bottom = 0x14;
      return;

    case 1:
      *left = 0;
      *top = 0x14;
      *right = 0x30;
      *bottom = 0x28;
      return;

    case 2:
      *left = 0;
      *top = 0x28;
      *right = 0x30;
      *bottom = 0x3C;
      return;

    case 3:
      *left = 0;
      *top = 0x3C;
      *right = 0x30;
      *bottom = 0x50;
      return;

    case 4:
      *left = 0;
      *top = 0x50;
      *right = 0x30;
      *bottom = 0x64;
      return;

    case 5:
      *left = 0;
      *top = 0x64;
      *right = 0x30;
      *bottom = 0x78;
      return;
  }
}

void *fn_801325A8(s32 unused, void **arg1, s32 arg2) {
    void *fn_800A8978(s32);
    extern u8 gUiSelectMenuStrings[];
    void *temp_r3;
    void *var_r3;

    temp_r3 = *arg1;
    switch (arg2) {
    case 0:
        return NULL;
    case 1:
        return fn_800A8978(*(s32 *)((u8 *)temp_r3 + 0x18C));
    case 2:
        var_r3 = (u8 *)gUiSelectMenuStrings + 0x527;
        if (*(s32 *)((u8 *)temp_r3 + 0x1A0) & 0x80000000) {
            var_r3 = (u8 *)gUiSelectMenuStrings + 0x523;
        }
        return var_r3;
    default:
        return NULL;
    }
}

#pragma peephole off
s32 fn_80132624(s32 unused, void **arg1, s32 arg2) {
    void *temp_r3;

    temp_r3 = *arg1;
    switch (arg2) {
    case 0:
        return -*(u16 *)((u8 *)*(void **)((u8 *)temp_r3 + 0x188) + 0x5A);
    case 1:
        return -*(u16 *)((u8 *)*(void **)((u8 *)temp_r3 + 0x18C) + 0x38);
    case 2:
        return (*(u32 *)((u8 *)temp_r3 + 0x1A0) & 0x80000000U) == 0;
    default:
        return 0;
    }
}
#pragma peephole reset
void *fn_80132688(void *unused, s32 arg1) {
    extern u16 gUiSelectMenuStrings[];

    switch (arg1) {
    case 1:
        return (u8 *)gUiSelectMenuStrings + 0x4C4;
    case 2:
        return (u8 *)gUiSelectMenuStrings + 0x52E;
    default:
        return (u8 *)gUiSelectMenuStrings + 0x247;
    }
}

void fn_801326D0(s32 unused, s32 kind, s32 *a, s32 *b, s32 *c, s32 *d) {
    switch (kind) {
    case 0:
        *a = 0;
        *b = 0;
        *c = 0x30;
        *d = 0x14;
        break;
    case 1:
        *a = 0;
        *b = 0x14;
        *c = 0x30;
        *d = 0x28;
        break;
    case 2:
        *a = 0;
        *b = 0x2BC;
        *c = 0x30;
        *d = 0x2D0;
        break;
    }
}

extern f32 lbl_8036A500;
extern f32 lbl_8036A50C;
extern f32 lbl_8036A510;
extern f64 lbl_8036A4F0;
extern f64 lbl_8036A4F8;
extern u8 gUiSelectMenuStrings[];
extern u32 jumptable_8029137C[];
extern u8 gUiSelectMenuStrings[];
