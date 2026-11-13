/* Functions from 0x80074370 to 0x8007C534, found by decomp-toolkit. */
#include "common.h"
#include "structs.h"
static inline s32 get_B4D8_mode(u16 flags) {
 s32 mode=3;
 if(flags&2)mode=6;
 return mode;
}

typedef struct {
    s16 unk0;
    s16 unk2;
    u16 unk4;
} Entry_80079300;
extern u8 D_802EF4C8[24];
extern u8 lbl_8036723A;
s32 Ui_CreateMenu();
void fn_8007A524(void *arg0, s32 arg1, s32 arg2);

void fn_80074370(void *arg0) {
    extern s32 lbl_80367468;
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) lbl_80367468;
}

extern u8 gUnitInfoPopup[];
s32 fn_8007437C(void) {
    u8 Ui_IsUnitInfoPopupOpen(void *);

    return Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) ? 0x40 : 0x10;
}

u32 fn_800745E8(u8 arg2) {
    if (arg2 == 4)
        return 1;
    else
        return 0;
}

s32 fn_80074758(s32 arg0, s32 arg1, void *arg2) {
    extern u8 gUiContext[];
    extern u8 lbl_80311FF4[];
    if (*((u8 *) arg2 + 0x39) != 0) {
        return 0x10;
    }
    gUiContext[0xA] = *((u8 *) arg2 + 0x3A);
    Ui_CreateMenu(lbl_80311FF4, arg1, 0);
    return 4;
}

#pragma cplusplus on
extern "C" void fn_800747AC(void *arg0, s32 arg1, void *arg2) {
struct Obj { virtual void v0() = 0;
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
virtual void v17() = 0; };
u64 *Item_GetFlagsPtr(void *);
void *Unit_GetItemSlot(void *, s32);
void UnitRef_Draw(void *, bool, s16, s16);
extern u64 lbl_8036746C;
extern void *lbl_80367468;
void *result;
s32 index;
((Obj *)arg0)->v17();
index=((u8 *)arg2)[0x3A];
if(index==4) result=&lbl_8036746C;
else {
u64 flags=*Item_GetFlagsPtr(&lbl_8036746C);
void *base=lbl_80367468;
result=Unit_GetItemSlot(base, ((flags & 5ULL)?0:4)+index);
}
UnitRef_Draw(result,((u8 *)arg2)[0x39]==0,*(s16 *)((u8 *)arg2+0x30),*(s16 *)((u8 *)arg2+0x32));
}
#pragma cplusplus reset

s32 fn_8007485C(void) {
    return 0;
}

s32 fn_80074864(void) {
    return 0;
}

void *fn_8007486C(void *unused, void *arg1)
{
  u64 *Item_GetFlagsPtr(void *);
  u64 *new_var;
  void *Unit_GetItemSlot(void *, s32);
  extern u64 lbl_8036746C;
  extern void *lbl_80367468;
  void *dst;
  s32 addend;
  u64 val;
  u64 *new_var2;
  s32 index;
  index = ((u8 *) arg1)[0x3A];
  if (index == 4)
  {
    new_var = &lbl_8036746C;
    return new_var;
  }
  new_var2 = Item_GetFlagsPtr(&lbl_8036746C);
  val = *new_var2;
  ;
  addend = ((val & 5ULL) != 0ULL) ? (0) : (4);
  return Unit_GetItemSlot(lbl_80367468, addend + index);
}

void fn_800748E8(void) {
    u64 *Item_GetFlagsPtr(void *);
    void *Unit_GetItemSlot(void *, s32);
    s32 UnitRef_GetName(void);
    void sprintf(void *, char *, ...);
    void fn_8000D864(s32, void *);
    void Msg_Expand(char *);
    extern u8 gUiContext[24];
    extern char lbl_8026C0B8[];
    extern u8 lbl_80312010[];
    extern u64 lbl_8036746C;
    extern void *lbl_80367468;
    s32 index;
    void *result;
    void *obj;
    u8 value;

    index = (s8)gUiContext[0xA];
    if (index == 4) {
        result = &lbl_8036746C;
    } else {
        result = Unit_GetItemSlot(lbl_80367468,
            ((*Item_GetFlagsPtr(&lbl_8036746C) & 5ULL) ? 0 : 4) + index);
    }
    obj = *(void **)result;
    if (obj != NULL) {
        value = *((u8 *)obj + 0x15);
    } else {
        value = 0;
    }
    sprintf(lbl_80312010, lbl_8026C0B8 + 0x122, (u8)value + 0x60, UnitRef_GetName());
    fn_8000D864(0, lbl_80312010);
    Msg_Expand(lbl_8026C0B8 + 0x12B);
}

void fn_800749D4(void) {
    extern u8 lbl_8026C0B8[];
    extern u8 gBattleState[];
    u8 fn_8014D8DC(void *);
    void Msg_Expand(u8 *);

    if ((u8)fn_8014D8DC(gBattleState) != 0) {
        Msg_Expand(lbl_8026C0B8 + 0x134);
    } else {
        Msg_Expand(lbl_8026C0B8 + 0x141);
    }
}

s32 fn_80074A28(void) {
    return 9;
}

s32 fn_80074A30(void) {
    return 0x18;
}

s32 fn_80074A38(void) {
    u8 Status_Test(void *, s32);
    void fn_80029C08(void *);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;

    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x18) == 0) {
        return 3;
    }
    fn_80029C08(*(u8 **)gUiContext);
    return lbl_802EF4E0.n ? 0 : 2;
}

#pragma cplusplus on
extern "C" void fn_80074AA8(void *arg0) {
    struct Obj {
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
    };
    void Res_GetEntry(void);
    void fn_8010586C(void);
    ((Obj *)arg0)->v19();
    Res_GetEntry();
    fn_8010586C();
}
#pragma cplusplus reset
s32 fn_80074ADC(void) {
    return 0;
}

#pragma cplusplus on
extern "C" void fn_80074AE4(void *arg0, s32 arg1, void *arg2) {
    struct Obj {
        virtual void v0() = 0;
        virtual void *v1() = 0;
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
    };
    void fn_8001003C(s16, s16, s32, s32, s32, void *, ...);
    extern f32 lbl_80369394;
    extern f32 lbl_803693A8;
    bool flag;

    flag = *(u8 *)((u8 *)arg2 + 0x39) == 0;
    ((Obj *)arg0)->v17();
    fn_8001003C(*(s16 *)((u8 *)arg2 + 0x30), *(s16 *)((u8 *)arg2 + 0x32), (u8)flag, 1, 0, ((Obj *)arg0)->v1(), lbl_80369394, lbl_803693A8);
}

extern "C" s32 fn_80074B78(s32 arg0, s32 arg1, void *arg2) {
    extern u8 gUiContext[];
    u8 *p;
    u8 v;
    if (*((u8 *)arg2 + 0x39) != 0) {
        return 0x10;
    }
    v = *((u8 *)arg2 + 0x3A);
    p = gUiContext;
    p[0xA] = v;
    return 5;
}

extern "C" s32 fn_80074BA4(void *arg0) {
    struct Obj {
        virtual s32 v0() = 0;
        virtual s32 v1() = 0;
        virtual s32 v2() = 0;
        virtual s32 v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        virtual s32 v6() = 0;
        virtual s32 v7() = 0;
        virtual s32 v8() = 0;
        virtual s32 v9() = 0;
        virtual s32 v10() = 0;
        virtual s32 v11() = 0;
        virtual s32 v12() = 0;
        virtual s32 v13() = 0;
        virtual s32 v14() = 0;
        virtual s32 v15() = 0;
        virtual s32 v16() = 0;
        virtual s32 v17() = 0;
        virtual s32 v18() = 0;
        virtual s32 v19() = 0;
    };
    u8 Status_Test(void *, s32);
    void fn_800299B8(void *);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;
    u8 *base;
    void *p;
    void *slot;

    base = gUiContext;
    p = *(void **)base;
    slot = (u8 *)p + 0x1BC;
    if (Status_Test(slot, ((Obj *)arg0)->v19()) == 0) {
        return 3;
    }
    fn_800299B8(*(void **)gUiContext);
    return lbl_802EF4E0.n ? 0 : 2;
}
#pragma cplusplus reset

void fn_80074C30(void *arg0) {
    extern s32 gUiContext[];
    *(s32 *)((u8 *)arg0 + 0xC) = gUiContext[1];
}

#pragma cplusplus on
extern "C" void UiWin_DrawTitleBody(void *win, void *state) {
    /* Draw faded window title and body; optional caption bar when text is tall enough. */
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
    f32 UiWin_GetFade(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetColorByte(s32);
    void Prim2D_PrepareTex(void);
    void fn_80071740(void *, f32, f32, s32);
    void fn_8007149C(void *, void *, f32, f32, s32, s32);
    void Prim2D_AddZ(f32);
    s32 Text_MeasureHeight(s32, f32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    f32 fade;

    fade = UiWin_GetFade(state);
    *(s16 *)((u8 *)state + 0x30) = 0;
    *(s16 *)((u8 *)state + 0x32) = 0;
    Prim2D_Begin();
    Prim2D_SetColorByte((s32)(255.0f * fade));
    Prim2D_PrepareTex();
    fn_80071740(win, 16.0f * fade + 16.0f, 35.0f, *(s32 *)((u8 *)win + 0xC));
    fn_8007149C(win, state, 16.0f * fade + 16.0f, 136.0f, *(s32 *)((u8 *)win + 0xC), 1);
    if (*(s16 *)((u8 *)state + 0x3A) >= 5) {
        Prim2D_Begin();
        Prim2D_AddZ(-0.1f);
        Prim2D_PrepareTex();
        fn_8008AB7C(((Obj *)win)->v18() / 2 + 0x28, *(s16 *)((u8 *)state + 0x3A) + Text_MeasureHeight(-1, 1.0f) / 2,
                    (s32)(0.9f * ((Obj *)win)->v18()), 0x18, 0x19, 0x4B, 1);
        Prim2D_Begin();
        Prim2D_AddZ(0.1f);
        Prim2D_PrepareTex();
    }
}
#pragma cplusplus reset

void *fn_80074DDC(void) {
    extern u8 lbl_8026C0B8[];
    return &lbl_8026C0B8[0x191];
}

extern s32 *Unit_GetItemSlot(s32, u8);
extern u8 fn_8001C0C8(void);
s32 fn_80074DEC(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 gUiContext[24];
    s32 *Unit_GetItemSlot(s32, u8);
    u8 fn_8001C0C8(void);

    if ((u32)*Unit_GetItemSlot(*(s32 *)(gUiContext + 4), (u8)arg2) == 0U) {
        return 3;
    }
    return (fn_8001C0C8() == 0) ? 2 : 0;
}

#pragma cplusplus on
extern "C" void fn_80074E4C(void *arg0, s32 arg1, void *arg2) {
    struct Obj {
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
    };
    s32 Unit_GetItemSlot(s32, u8);
    void UnitRef_Draw(s32, bool, s16, s16);
    extern s32 gUiContext[];
    ((Obj *)arg0)->v17();
    UnitRef_Draw(Unit_GetItemSlot(gUiContext[1], *(u8 *)((u8 *)arg2 + 0x3A)), *(u8 *)((u8 *)arg2 + 0x39) == 0, *(s16 *)((u8 *)arg2 + 0x30), *(s16 *)((u8 *)arg2 + 0x32));
}

extern "C" s32 fn_80074EB0(s32 arg0, s32 arg1, void *arg2) {
    extern u8 gUiContext[];
    u8 *p;
    if (*((u8 *)arg2 + 0x39) != 0) {
        return 0x10;
    }
    p = gUiContext;
    p[0x14] = *((u8 *)arg2 + 0x3A);
    return 5;
}

#pragma cplusplus reset
void fn_80074EDC(s32 arg0, void *arg1) {
    extern s32 gUiContext[];
    
    Unit_GetItemSlot(gUiContext[1], *(u8*)((char*)arg1 + 0x3A));
}

void fn_80074F0C(void *arg0) {
    extern s32 gUiContext[];
    *(s32 *)((u8 *)arg0 + 0xC) = gUiContext[1];
}

void fn_80074F20(void *arg0, void *arg1) {
    extern f32 lbl_80369378;
    extern f32 lbl_8036937C;
    extern f32 lbl_80369380;
    extern f32 lbl_80369384;
    extern f32 lbl_80369390;
    extern f32 lbl_80369394;
    extern f32 lbl_80369398;
    extern f32 lbl_8036939C;
    extern f32 lbl_803693A0;
    extern u8 lbl_8026C0B8[];
    extern f32 UiWin_GetFade(void *);
    extern void Prim2D_Begin(void);
    extern void Prim2D_SetColorByte(s32);
    extern void Prim2D_PrepareTex(void);
    extern void fn_80071740(void *, f32, f32, s32);
    extern void fn_8007149C(void *, void *, f32, f32, s32, s32);
    extern void Prim2D_AddZ(f32);
    extern s32 Text_MeasureHeight(s32, f32);
    extern void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    extern void Ui_DrawCenteredMsgLines(u32, u32, void *, void *, void *);

    typedef s16 (*v18_fn)(void *);
    f32 t;
    v18_fn fn1;
    v18_fn fn2;
    s16 v18_1;
    s16 v18_2;
    s32 r29;
    s32 temp;
    s32 r30;
    s32 part2;
    u32 *vtable;

    vtable = (u32 *)*(u32 *)((u8 *)arg0 + 4);
    t = UiWin_GetFade(arg1);
    *(s16 *)((u8 *)arg1 + 0x30) = 0;
    *(s16 *)((u8 *)arg1 + 0x32) = 0;
    Prim2D_Begin();
    Prim2D_SetColorByte((s32)(lbl_80369378 * t));
    Prim2D_PrepareTex();
    fn_80071740(arg0, lbl_8036937C * t + lbl_8036937C, lbl_80369380, *(s32 *)((u8 *)arg0 + 0xC));
    fn_8007149C(arg0, arg1, lbl_8036937C * t + lbl_8036937C, lbl_80369384, *(s32 *)((u8 *)arg0 + 0xC), 0);
    if ((s16) *(s16 *)((u8 *)arg1 + 0x3A) >= 5) {
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369390);
        Prim2D_PrepareTex();
        fn1 = (v18_fn)*(u32 *)((u8 *)arg0 + 0x54);
        v18_1 = fn1(arg0);
        r29 = (s32)(lbl_80369398 * (((f32)(s16)v18_1) - lbl_803693A0));
        temp = Text_MeasureHeight(-1, lbl_80369394);
        r30 = (temp + (temp < 0 ? 1 : 0)) >> 1;
        fn2 = (v18_fn)*(u32 *)((u8 *)arg0 + 0x54);
        v18_2 = fn2(arg0);
        part2 = (v18_2 + (v18_2 < 0 ? 1 : 0)) >> 1;
        fn_8008AB7C(0x28 + part2, (s16) *(s16 *)((u8 *)arg1 + 0x3A) + r30, r29, 0x17, 0x19, 0x4b, 1);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036939C);
        Prim2D_PrepareTex();
    }
    Ui_DrawCenteredMsgLines(0x138, 0xa0, (void *)(lbl_8026C0B8 + 0x1a1), (void *)(lbl_8026C0B8 + 0x1a7), (void *)(lbl_8026C0B8 + 0x1ad));
}

void fn_800750D8(s32 arg0, void *arg1) {
    extern s32 gUiContext[];
    
    Unit_GetItemSlot(gUiContext[1], *(u8*)((char*)arg1 + 0x3A));
}

s32 fn_80075108(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 gUiContext[24];
    s32 *Unit_GetItemSlot(s32, u8);
    u8 fn_8003DAC4(s32, s32 *);
    s32 *temp;

    temp = Unit_GetItemSlot(*(s32 *)(gUiContext + 4), (u8)arg2);
    if ((u32)*temp == 0U) {
        return 3;
    }
    return (fn_8003DAC4(*(s32 *)gUiContext, temp) == 0) ? 2 : 0;
}

s32 fn_80075178(void *arg1, void *arg2) {
    s32 Msg_Expand(void *);
    s32 Unit_GetItemSlot(s32, u8);
    u8 fn_8003DBA8(s32, s32, M2C_UNK *);
    M2C_UNK fn_80166AE8(s32, s16, s32, void *);
    extern M2C_UNK lbl_8026C0B8;
    extern M2C_UNK gUiContext;
    s16 temp_r28;
    s16 temp_r29;
    s32 temp_r30;
    u8 temp_r3;
    void *temp_r27;
    void *var_r27;

    if ((u8) M2C_FIELD(arg2, u8 *, 0x39) != 0) {
        var_r27 = NULL;
        temp_r3 = fn_8003DBA8(M2C_FIELD(&gUiContext, s32 *, 0), Unit_GetItemSlot(M2C_FIELD(&gUiContext, s32 *, 4), M2C_FIELD(arg2, u8 *, 0x3A)), &gUiContext);
        switch ((s32) temp_r3) {                    /* irregular */
        case 1:
            var_r27 = &lbl_8026C0B8 + 0x1B3;
            break;
        case 2:
            var_r27 = &lbl_8026C0B8 + 0x1BA;
            break;
        case 3:
            var_r27 = &lbl_8026C0B8 + 0x1C1;
            break;
        }
        temp_r29 = M2C_FIELD(arg2, s16 *, 0x32);
        temp_r28 = M2C_FIELD(arg2, s16 *, 0x30);
        temp_r27 = M2C_FIELD(arg1, void **, 0x3C);
        temp_r30 = Msg_Expand(var_r27);
        fn_80166AE8(M2C_FIELD(M2C_FIELD(temp_r27, void **, 4), s16 (**)(void *), 0x5C)(temp_r27) + temp_r28, temp_r29, temp_r30, arg1);
        return 0;
    }
    M2C_FIELD(&gUiContext, u8 *, 0xA) = (u8) M2C_FIELD(arg2, u8 *, 0x3A);
    return 5;
}

#pragma cplusplus on
extern "C" void fn_80075290(void *arg0, s32 arg1, void *arg2) {
    struct Obj {
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
    };
    s32 Unit_GetItemSlot(s32, u8);
    void UnitRef_Draw(s32, bool, s16, s16);
    extern s32 gUiContext[];
    ((Obj *)arg0)->v17();
    UnitRef_Draw(Unit_GetItemSlot(gUiContext[1], *(u8 *)((u8 *)arg2 + 0x3A)), *(u8 *)((u8 *)arg2 + 0x39) == 0, *(s16 *)((u8 *)arg2 + 0x30), *(s16 *)((u8 *)arg2 + 0x32));
}
#pragma cplusplus reset

void fn_800752F4(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x1C8);
}

void fn_80075320(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x1D0);
}

s32 fn_8007534C(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0;
    return 9;
}

void fn_80075364(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x1D6);
}

void fn_80075390(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x1DC);
}

s32 fn_800753BC(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0;
    return 9;
}

void fn_800753D4(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x1E3);
}

void fn_80075400(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x1e9);
}

s32 fn_8007542C(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0;
    return 9;
}

void fn_80075444(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x1EF);
}

void fn_80075470(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x1e9);
}

s32 fn_8007549C(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0;
    return 9;
}

void fn_800754B4(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x1f5);
}

s32 fn_800754E0(void) {
    return 1;
}

s32 fn_800754E8(void) {
    return 9;
}

void fn_800754F0(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x1f5);
}

s32 fn_8007551C(void) {
    return 1;
}

s32 fn_80075524(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0;
    return 9;
}

void fn_8007553C(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand(&lbl_8026C0B8[0x212 / sizeof(u16)]);
}

s32 fn_80075568(void) {
    return 0;
}

s32 fn_80075570(void) {
    return 6;
}

void fn_80075578(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x21A);
}

s32 fn_800755A4(void) {
    M2C_UNK fn_800919D8();
    fn_800919D8();
    return 9;
}

void fn_800755C8(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x1f5);
}

s32 fn_800755F4(void) {
    return 1;
}

s32 fn_800755FC(void) {
    extern u16 lbl_8026C0B8[];
    Ui_PlaySeCue(&lbl_8026C0B8[0x7F], 0x64);
    return 1;
}

void fn_80075630(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand(&lbl_8026C0B8[0x212 / sizeof(u16)]);
}

s32 fn_8007565C(void) {
    return 0;
}

#pragma cplusplus on
extern "C" s32 fn_80075784(void *arg0, void *arg1, s32 arg2) {
    void **Unit_GetItemSlot(void *, u8);
    u8 fn_800939FC(void *);
    extern void *gUiContext[];
    void **ret;
    u8 val;

    ret = Unit_GetItemSlot(gUiContext[0], (u8)arg2);
    if (*ret == NULL) {
        return 3;
    }
    val = (*ret != NULL) ? *(u8 *)((char *)*ret + 0x12) : 0xC;
    if (val == 7) {
        return 2;
    }
    return (fn_800939FC(gUiContext[0]) == 0) ? 2 : 0;
}

extern "C" s32 fn_80075814(s32 arg0, s32 arg1, void *arg2) {
    extern u8 gUiContext[];
    extern u8 lbl_8036743C[8];
    void fn_80091CD8(s32);
    void *Ui_CreateMenu(void *, s32, s32);
    void *tmp;

    gUiContext[0xA] = *((u8 *)arg2 + 0x3A);
    fn_80091CD8(*(s32 *)gUiContext);
    tmp = Ui_CreateMenu(lbl_8036743C, arg1, 0);
    *(s16 *)((u8 *)tmp + 0x30) = 0x180;
    *(s16 *)((u8 *)tmp + 0x32) = 0x46;
    return 4;
}

#pragma cplusplus off
void fn_80075878(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand(&lbl_8026C0B8[0x220 / sizeof(u16)]);
}

void fn_800758A4(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand(&lbl_8026C0B8[0x22A / sizeof(u16)]);
}

s32 fn_800758D0(void) {
    u64 *Item_GetFlagsPtr(void *);
    void *fn_800285C0(void *);
    extern u8 gUiContext[];

    if (*Item_GetFlagsPtr(fn_800285C0(gUiContext)) & 0x20000000000ULL) {
        return 2;
    }
    return 0;
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void fn_80166AE8(s32, s32, s32, void *);
#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma global_optimizer off
extern "C" s32 fn_80075930(void *arg0, void *arg1, void *arg2) {
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
    extern u8 lbl_8026C0B8[];
    extern u8 lbl_80311F80[];
    s32 Msg_Expand(void *);
    void fn_80166AE8(s32, s32, s32, void *);
    s32 Ui_CreateMenu(void *, void *, s32);
    s32 y;
    s32 a;
    s32 str;
    s16 x;
    Obj *obj;
    s32 b;

    if (*(u8 *)((char *)arg2 + 0x39) != 0) {
        obj = *(Obj **)((char *)arg1 + 0x3C);
        y = *(s16 *)((char *)arg2 + 0x32);
        x = *(s16 *)((char *)arg2 + 0x30);
        str = Msg_Expand(lbl_8026C0B8 + 0x235);
        a = obj->v22();
        y = y - 0x3C;
        b = obj->v21();
        fn_80166AE8(b + x, a + y, str, arg1);
        return 0;
    }
    Ui_CreateMenu(lbl_80311F80, arg1, 0);
    return 4;
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma cplusplus off

s32 fn_800759E8(void) {
    u64 *Item_GetFlagsPtr(void *);
    void *fn_800285C0(void *);
    void fn_8002C194(void *, u8);
    extern u8 gUiContext[];
    extern s32 lbl_802EF4E0[];

    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    if (gUiContext[0x16] & 2) {
        return 3;
    }
    fn_8002C194(*(void **)gUiContext, gUiContext[0xA]);
    if (lbl_802EF4E0[0] == 0) {
        return 3;
    }
    if (*Item_GetFlagsPtr(fn_800285C0(gUiContext)) & 0x200ULL) {
        return 2;
    }
    return 0;
}

#pragma cplusplus on
extern "C" s32 fn_80075A9C(s32 arg0, void *arg1, void *arg2) {
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
    extern u8 lbl_8026C0B8[];
    extern u8 gUiContext[];
    s32 Msg_Expand(void *);
    void fn_80166AE8(s32, s32, s32, void *);
    s16 y;
    s32 a;
    s32 str;
    s16 x;
    Obj *obj;
    s32 b;

    if (((u8 *)arg2)[0x39] != 0) {
        obj = *(Obj **)((u8 *)arg1 + 0x3C);
        y = *(s16 *)((u8 *)arg2 + 0x32);
        x = *(s16 *)((u8 *)arg2 + 0x30);
        str = Msg_Expand(lbl_8026C0B8 + 0x23c);
        a = obj->v22();
        y = (s16)(y - 0x3c);
        b = obj->v21();
        fn_80166AE8(b + x, a + y, str, arg1);
        return 0;
    }
    gUiContext[8] = 0x28;
    return 6;
}
#pragma cplusplus reset
void fn_80075B54(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand(&lbl_8026C0B8[0x244 / sizeof(u16)]);
}

void fn_80075B80(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x24f);
}

void fn_80075BAC(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x25B);
}

void fn_80075BD8(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x267);
}

s32 fn_80075C04(void) {
    u64 *Item_GetFlagsPtr(void *);
    void *fn_800285C0(void *);
    extern u8 gUiContext[];
    void *item;

    item = fn_800285C0(gUiContext);
    if (!((*(u8 *)((char *)item + 5) >> 7) & 1)) {
        return 3;
    }
    if (*Item_GetFlagsPtr(item) & 0x200ULL) {
        return 2;
    }
    return 0;
}

void fn_80075DAC(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x28a);
}

void fn_80075DD8(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x295);
}

s32 fn_80075E04(void) {
    u64 *Item_GetFlagsPtr(void *);
    void *fn_800285C0(void *);
    u8 fn_80091EF0(void *, void *);
    extern void *gUiContext[];
    void *item;
    void *temp_r31;
    void *temp_r30;

    item = fn_800285C0(gUiContext);
    temp_r31 = *(void **)item;
    temp_r30 = gUiContext[0];
    if ((*(u8 *)((char *)item + 5) >> 7) & 1) {
        return 3;
    }
    if (*Item_GetFlagsPtr(item) & 4ULL) {
        return 3;
    }
    return fn_80091EF0(temp_r30, temp_r31) ? 0 : 3;
}

s32 fn_80075EB4(void *arg1, void *arg2) {
    M2C_UNK Process_CreateChild(M2C_UNK *, void *);
    void *Item_GetFlagsPtr();
    M2C_UNK fn_80023FF4(void *);
    M2C_UNK fn_800285C0(M2C_UNK *);
    s8 fn_80037E00(void *);
    M2C_UNK fn_80094CDC(void *, s8);
    M2C_UNK Ui_PlaySeCue(void *, M2C_UNK);
    extern M2C_UNK lbl_8026C0B8;
    extern M2C_UNK lbl_802872B0;
    extern M2C_UNK gUiContext;
    u8 temp_r31;
    void *temp_r30;
    void *temp_r30_2;
    void *temp_r3;

    if ((u8) M2C_FIELD(arg2, u8 *, 0x39) != 0) {
        return 0x10;
    }
    Ui_PlaySeCue(&lbl_8026C0B8 + 0x29E, 0x64);
    fn_80094CDC(M2C_FIELD(&gUiContext, void **, 0), (s8) M2C_FIELD(&gUiContext, u8 *, 0xA));
    if ((s8) M2C_FIELD(&gUiContext, u8 *, 0xA) < 4) {
        temp_r30 = M2C_FIELD(arg1, void **, 0x18);
        M2C_FIELD(temp_r30, s8 *, 0x62) = fn_80037E00(M2C_FIELD(&gUiContext, void **, 0));
    }
    if ((M2C_FIELD(M2C_FIELD(&gUiContext, void **, 0), s32 *, 0x1A0) & 0x800000) || (fn_800285C0(&gUiContext), temp_r3 = Item_GetFlagsPtr(), (((((M2C_FIELD(temp_r3, s32 *, 4) & 0) ^ 0) | ((M2C_FIELD(temp_r3, s32 *, 0) & 1) ^ 0)) == 0) == 0))) {
        Process_CreateChild(&lbl_802872B0, M2C_FIELD(arg1, void **, 0x18));
    }
    temp_r30_2 = M2C_FIELD(arg1, void **, 0x18);
    temp_r31 = M2C_FIELD(temp_r30_2, u8 *, 0x62);
    fn_80023FF4(temp_r30_2);
    M2C_FIELD(temp_r30_2, u8 *, 0x62) = temp_r31;
    return 5;
}

void fn_80075FB8(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand(&lbl_8026C0B8[0x2B0 / sizeof(u16)]);
}

void fn_80075FE4(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x2B9);
}

s32 fn_80076010(void) {
    void *fn_800285C0(void *);
    u8 fn_80091F70(void *, void *);
    u8 fn_80093218(void *, void *);
    extern void *gUiContext[];
    void *item;
    void *temp_r31;
    void *temp_r30;
    u8 var_r0;

    item = fn_800285C0(gUiContext);
    temp_r30 = *(void **)item;
    temp_r31 = gUiContext[0];
    if (temp_r30 != NULL) {
        var_r0 = *(u8 *)((char *)temp_r30 + 0x12);
    } else {
        var_r0 = 0xC;
    }
    if (var_r0 == 7) {
        return 3;
    }
    if (fn_80091F70(temp_r31, temp_r30) != 0) {
        return 0;
    }
    return fn_80093218(temp_r31, temp_r30) ? 2 : 3;
}

s32 fn_800760B8(s32 arg0, s32 arg1, void *arg2) {
    extern u8 gUiContext[];
    u8 *p;
    if (*((u8 *)arg2 + 0x39) != 0) {
        return 0x10;
    }
    p = gUiContext;
    p[8] = 4;
    return 6;
}

s32 fn_800760E4(s32 arg0, s32 arg1, s32 arg2) {
    u32 *Unit_GetHeldItemSlot(s32, u8);
    u8 fn_8009204C(s32, u32);
    extern u8 gUiContext[];
    u32 value;
    value = *Unit_GetHeldItemSlot(*(s32 *)gUiContext, (u8)arg2);
    if (value == 0U) return 3;
    return (fn_8009204C(*(s32 *)gUiContext, value) == 0) + 1;
}

s32 fn_80076148(s32 arg0, s32 arg1, void *arg2) {
    extern u8 gUiContext[];
    u8 *p;
    s32 ret;
    if (*((u8 *)arg2 + 0x39) == 2) {
        return 0x10;
    }
    p = gUiContext;
    p[0xA] = *((u8 *)arg2 + 0x3A);
    ret = 5;
    return ret;
}

#pragma cplusplus on
extern "C" void Prim2D_SetColorByte(s32);
extern "C" void Prim2D_AddZ(f32);
extern "C" void Prim2D_PrepareTex(void);
extern "C" void Prim2D_Begin(void);
extern "C" s32 Text_MeasureHeight(s32, f32);
extern "C" f32 UiWin_GetFade(void *);
extern "C" void fn_80070F54(void *, void *, f32, f32);
extern "C" void fn_80071410(void *, void *, f32, f32);
extern "C" void fn_8007149C(void *, void *, f32, f32, s32, s32);
extern "C" void fn_80071740(void *, f32, f32, s32);
extern "C" void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
/* Draw the battle info window: title, body, optional text box, and battle HUD bits. */
extern "C" void BattleInfoWin_Draw(void *win, void *state) {
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
    extern u8 gBattle[];
    f32 fade;

    fade = UiWin_GetFade(state);
    *(s16 *)((u8 *)state + 0x30) = 0;
    *(s16 *)((u8 *)state + 0x32) = 0;
    Prim2D_Begin();
    Prim2D_SetColorByte((s32)(255.0f * fade));
    Prim2D_PrepareTex();
    fn_80071740(win, 16.0f * fade + 16.0f, 35.0f, *(s32 *)((u8 *)win + 0xC));
    fn_8007149C(win, state, 16.0f * fade + 16.0f, 136.0f, *(s32 *)((u8 *)win + 0xC), 1);
    if (*(s16 *)((u8 *)state + 0x3A) >= 5) {
        Prim2D_Begin();
        Prim2D_AddZ(-0.1f);
        Prim2D_PrepareTex();
        fn_8008AB7C(((Obj *)win)->v18() / 2 + 0x28, *(s16 *)((u8 *)state + 0x3A) + Text_MeasureHeight(-1, 1.0f) / 2,
                    (s32)(0.9f * ((Obj *)win)->v18()), 0x18, 0x19, 0x4B, 1);
        Prim2D_Begin();
        Prim2D_AddZ(0.1f);
        Prim2D_PrepareTex();
    }
    fn_80071410(win, gBattle, 312.0f, 282.0f);
    fn_80070F54(win, gBattle, 500.0f, 212.0f);
}
#pragma cplusplus off
s32 fn_8007633C(void) {
    void MapObjEvent_Find(void *, u8, u8, s32);
    extern u8 gUiContext[];
    extern u8 gMapObjEventList[];
    u8 *base;
    void *ptr;
    u8 a;
    u8 b;

    base = gUiContext;
    ptr = *(void **)base;
    a = *((u8 *)ptr + 0x19F);
    b = *((u8 *)ptr + 0x19E);
    MapObjEvent_Find(gMapObjEventList, b, a, 7);
    return 0;
}

s32 fn_80076380(s32 arg0, s32 arg1, void *arg2) {
    if (*(u8 *)((u8 *)arg2 + 0x39) == 2) {
        return 0x10;
    }
    return 5;
}

#pragma global_optimizer off
void fn_80076398(void) {
    void MapObjEvent_Find(void *, u8, u8, s32);
    void fn_8010FA2C(void);
    extern u8 gUiContext[];
    extern u8 gMapObjEventList[];
    u8 *base;
    void *ptr;
    u8 a;
    u8 b;

    base = gUiContext;
    ptr = *(void **)base;
    a = *((u8 *)ptr + 0x19F);
    b = *((u8 *)ptr + 0x19E);
    MapObjEvent_Find(gMapObjEventList, b, a, 7);
    fn_8010FA2C();
}
#pragma global_optimizer reset
s32 fn_800763DC(void){void*fn_80019E24(u8);s32 fn_8001DDBC(void);void fn_8001EF80(void*,u8,u8,u8);void fn_8002011C(void*,u8,u8,u8,s32);void Map_ShowMoveLimitView(void);void fn_80070EE0(void);void*MapObjEvent_Find(void*,u8,u8,s32);extern u8 gBattleMap[],gUiContext[],gMapObjEventList[];u8*p;u8 a,b,c;fn_80070EE0();p=MapObjEvent_Find(gMapObjEventList,gUiContext[13],gUiContext[14],7);a=*((u8*)fn_80019E24(p[4])+29);b=p[1];c=p[0];fn_8002011C(gBattleMap,c,b,a,fn_8001DDBC());fn_8001EF80(gBattleMap,p[0],p[1],p[3]);Map_ShowMoveLimitView();return 0;}

s32 fn_80076494(void) {
    M2C_UNK Map_HideMoveLimitView();
    Map_HideMoveLimitView();
    return 0;
}

#pragma global_optimizer off
s32 fn_800764B8(s32 a0, s32 a1, u8 arg2)
{
    u32 *Unit_GetHeldItemSlot(s32, s32);
    u8 fn_8009339C(s32);
    void fn_8002BEFC(s32, u32);
    void fn_8002C034(s32, u32);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;
    u32 *entry;

    entry = Unit_GetHeldItemSlot(*(s32 *)gUiContext, arg2);
    if (*entry == 0) {
        return 3;
    }
    if (!fn_8009339C(*(s32 *)gUiContext)) {
        return 2;
    }
    if (gUiContext[8] == 0x27) {
        fn_8002BEFC(*(s32 *)gUiContext, *entry);
    } else {
        fn_8002C034(*(s32 *)gUiContext, *entry);
    }
    if (lbl_802EF4E0.n == 0) {
        return 2;
    }
    return 1;
}
#pragma global_optimizer reset
s32 fn_80076574(s32 arg0, s32 arg1, void *arg2) {
    void fn_800951D0(void *, u8);
    extern u8 gUiContext[];
    if (*(u8 *)((u8 *)arg2 + 0x39) == 2) {
        return 0x10;
    }
    fn_800951D0(*(void **)gUiContext, *(u8 *)((u8 *)arg2 + 0x3A));
    return 5;
}

s32 fn_800765BC(s32 arg0, s32 arg1, void *arg2) {
    void fn_80070EE0(void);
    void *Unit_GetHeldItemSlot(void *, u8);
    s32 fn_8001DDBC(void);
    void fn_80022DAC(void *, s32, s32);
    void fn_80022FD8(void *, u8);
    void fn_8002011C(void *, u8, u8, u8, u8);
    void Map_ShowMoveLimitView(void);
    extern u8 gUiContext[];
    extern u8 gBattleMap[];
    u8 a;
    void *p;
    s32 b;

    fn_80070EE0();
    p = arg2;
    if (*(u8 *)((u8 *)p + 0x39) != 0) {
        return 0;
    }
    {
        u8 idx = *(u8 *)((u8 *)p + 0x3A);
        void *f;
        s32 tmp;
        p = *(void **)gUiContext;
        f = *(void **)Unit_GetHeldItemSlot(p, idx);
        if (f != 0) {
            tmp = ((u8 *)f)[0x1D];
        } else {
            tmp = 0;
        }
        a = (u8)tmp;
        if (f != 0) {
            b = (u8)fn_8001DDBC();
        } else {
            b = 0;
        }
    }
    fn_80022DAC(gBattleMap, 5, -1);
    fn_80022DAC(gBattleMap, 8, 0);
    fn_80022FD8(gBattleMap, 6);
    fn_8002011C(gBattleMap, ((u8 *)p)[0x19E], ((u8 *)p)[0x19F], a, (u8)b);
    Map_ShowMoveLimitView();
    return 0;
}

s32 fn_800766B0(void) {
    M2C_UNK Map_HideMoveLimitView();
    Map_HideMoveLimitView();
    return 0;
}

s32 fn_800766D4(void) {
    u8 fn_800281F4(void *);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    extern u8 gUnitInfoPopup[];
    extern u8 gUiContext[24];

    if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
        return 0x40;
    }
    if (fn_800281F4(gUiContext) == 0 && gUiContext[0x16] != 0) {
        return 0x10;
    }
    return 9;
}

void fn_80076740(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x2C3);
}

void fn_8007676C(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x2C9);
}

s32 fn_80076798(void) {
    void *MapObjEvent_Find(void *, u8, u8, s32);
    extern u8 gUiContext[];
    extern u8 gMapObjEventList[];
    u8 *p;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    return MapObjEvent_Find(gMapObjEventList, p[0xD], p[0xE], 0xA) ? 0 : 3;
}

s32 fn_800767FC(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x2E;
    return 5;
}

void fn_80076814(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand(&lbl_8026C0B8[0x2D0 / sizeof(u16)]);
}

void fn_80076840(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand(&lbl_8026C0B8[0x2DC / sizeof(u16)]);
}

s32 fn_8007686C(void) {
    u8 Status_Test(void *, s32);
    s32 Item_GetByIid(u8 *);
    void fn_8002C034(void *, s32);
    extern u8 gUiContext[];
    extern s32 lbl_802EF4E0[];
    extern u8 lbl_8026C0B8[];
    void *temp;

    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x43) == 0) {
        return 3;
    }
    temp = *(void **)gUiContext;
    fn_8002C034(temp, Item_GetByIid(lbl_8026C0B8 + 0x2E3));
    return lbl_802EF4E0[0] == 0 ? 3 : 0;
}

s32 fn_80076910(s32 arg0, s32 arg1, void *arg2) {
    extern u8 gUiContext[];
    u8 *p;
    if (*((u8 *)arg2 + 0x39) != 0) {
        return 0x10;
    }
    p = gUiContext;
    p[8] = 0x1d;
    return 5;
}

s32 fn_8007693C(void) {
    M2C_UNK Map_ShowMoveLimitView();
    M2C_UNK fn_800AA80C(s32);
    extern s32 gUiContext[];
    fn_800AA80C(gUiContext[0]);
    Map_ShowMoveLimitView();
    return 0;
}

s32 fn_80076970(void) {
    M2C_UNK Map_HideMoveLimitView();
    Map_HideMoveLimitView();
    return 0;
}

void fn_80076994(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x2EF);
}

void fn_800769C0(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x2F5);
}

s32 fn_800769EC(void) {
    u8 Status_Test(void *, s32);
    void fn_80029E4C(void);
    extern u8 gUiContext[];
    extern s32 lbl_802EF4E0[];

    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x46) == 0) {
        return 3;
    }
    if (*(u32 *)(*(u8 **)gUiContext + 0x1A0) & 0x1000) {
        return 2;
    }
    fn_80029E4C();
    return lbl_802EF4E0[0] == 0 ? 3 : 0;
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" s32 fn_80076A88(s32 arg0, void *arg1, void *arg2) {
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
    extern u8 lbl_8026C0B8[];
    extern u8 gUiContext[];
    s32 Msg_Expand(void *);
    void fn_80166AE8(s32, s32, s32, void *);
    s32 a;
    s32 str;
    s16 y;
    s16 x;
    Obj *obj;

    if (*(u8 *)((char *)arg2 + 0x39) != 0) {
        obj = *(Obj **)((char *)arg1 + 0x3C);
        y = *(s16 *)((char *)arg2 + 0x32);
        x = *(s16 *)((char *)arg2 + 0x30);
        str = Msg_Expand(lbl_8026C0B8 + 0x2fc);
        a = obj->v22();
        fn_80166AE8(obj->v21() + x, a + y, str, arg1);
        return 0;
    }
    gUiContext[8] = 0x1e;
    return 5;
}
#pragma use_lmw_stmw reset
#pragma cplusplus off
void fn_80076B3C(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x305);
}

void fn_80076B68(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x309);
}

s32 fn_80076B94(void) {
    u8 Status_Test(void *, s32);
    s32 Item_GetByIid(u8 *);
    void fn_8002AD04(void *, s32);
    extern u8 gUiContext[];
    extern s32 lbl_802EF4E0[];
    extern u8 lbl_8026C0B8[];
    void *temp;

    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x4A) == 0) {
        return 3;
    }
    temp = *(void **)gUiContext;
    fn_8002AD04(temp, Item_GetByIid(lbl_8026C0B8 + 0x30E));
    return lbl_802EF4E0[0] == 0 ? 3 : 0;
}

s32 fn_80076C38(void) {
    extern u8 gUiContext[];
    u8 *p = gUiContext;
    p[8] = 0x21;
    return 5;
}

void fn_80076C50(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x317);
}

void fn_80076C7C(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x31B);
}

s32 fn_80076CA8(void) {
    u8 Status_Test(void *, s32);
    s32 Item_GetByIid(u8 *);
    void fn_8002AB9C(void *, s32);
    extern u8 gUiContext[];
    extern s32 lbl_802EF4E0[];
    extern u8 lbl_8026C0B8[];
    void *temp;

    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x49) == 0) {
        return 3;
    }
    temp = *(void **)gUiContext;
    fn_8002AB9C(temp, Item_GetByIid(lbl_8026C0B8 + 0x320));
    return lbl_802EF4E0[0] == 0 ? 3 : 0;
}

s32 fn_80076D4C(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x22;
    return 5;
}

void fn_80076D64(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x329);
}

void fn_80076D90(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x333);
}

s32 fn_80076DBC(void) {
    u8 Status_Test(void *, s32);
    void fn_80029C08(void *);
    extern u8 gUiContext[];
    extern s32 lbl_802EF4E0[];

    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x18) != 0) {
        fn_80029C08(*(u8 **)gUiContext);
        if (lbl_802EF4E0[0] != 0) {
            return 0;
        }
    }
    return 3;
}

s32 fn_80076E38(void) {
    u8 Status_Test(void *, s32);
    extern u8 gUiContext[];

    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 9) != 0) {
        u8 *p = gUiContext;
        p[8] = 0x2B;
    } else {
        u8 *p = gUiContext;
        p[8] = 0x12;
    }
    return 5;
}

s32 fn_80076E9C(void) {
    extern u8 gUiContext[];
    u8 *p = gUiContext;
    p[8] = 6;
    return 5;
}

s32 fn_80076EB4(void) {
    void fn_8002C194(void *, s32);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;
    u8 *p;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    if (p[0x16] & 2) {
        return 3;
    }
    fn_8002C194(*(void **)p, -1);
    return lbl_802EF4E0.n ? 0 : 3;
}

void fn_80076F28(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x33e);
}

void fn_80076F54(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x349);
}

s32 fn_80076F80(void) {
    extern u8 gUiContext[];
    extern u8 gUnitLists[];
    extern u8 gBattleState[];
    u8 Status_Test(void *, s32);
    s32 fn_80015680(u8 *);
    u8 fn_8014D8BC(u8 *);

    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0) == 0) {
        return 3;
    }
    if (fn_80015680(gUnitLists + 0x24) == 0) {
        return 3;
    }
    return (fn_8014D8BC(gBattleState) == 0) ? 3 : 0;
}

void fn_80077008(void) {
    M2C_UNK Prim2D_SetColorPacked(s32 *);
    s32 *Ui_GetColor(M2C_UNK);
    s32 sp8;

    sp8 = *Ui_GetColor(6);
    Prim2D_SetColorPacked(&sp8);
}

s32 fn_8007703C(s32 unused, s32 arg1) {
    void fn_801832F8(s32);
    extern u8 gUiContext[24];
    u8 *p = gUiContext;
    p[8] = 0x33;
    fn_801832F8(arg1);
    return 4;
}

void fn_80077074(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x353);
}

void fn_800770A0(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x35d);
}

s32 fn_800770CC(void) {
    extern u8 gUiContext[];
    extern u8 gUnitLists[];
    extern u8 gBattleState[];
    u8 Status_Test(void *, s32);
    s32 fn_80015680(u8 *);
    u8 fn_8014D8BC(u32 *);

    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0) == 0) {
        return 3;
    }
    if (fn_80015680(gUnitLists) <= 1) {
        return 3;
    }
    return (fn_8014D8BC((u32 *)gBattleState) == 0) ? 3 : 0;
}

void fn_80077150(void) {
    extern u32 *Ui_GetColor(int);
    extern void Prim2D_SetColorPacked(void *);

    u32 value;

    value = *Ui_GetColor(7);
    Prim2D_SetColorPacked(&value);
}

s32 fn_80077184(s32 unused, s32 arg1) {
    void fn_801832F8(s32);
    extern u8 gUiContext[24];
    u8 *p = gUiContext;
    p[8] = 0x32;
    fn_801832F8(arg1);
    return 4;
}

void fn_800771BC(void) {
    extern u16 lbl_8026C0B8[];
    M2C_UNK Msg_Expand(void *);
    Msg_Expand(&lbl_8026C0B8[0x366 / sizeof(u16)]);
}

void fn_800771E8(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x36F);
}

s32 fn_80077214(void) {
    u8 Status_Test(void *, s32);
    s32 fn_800AA288(s32);
    extern u8 gUiContext[];
    extern u8 gBattleState[];

    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x48) == 0) {
        return 3;
    }
    if (gBattleState[0x50] >= 2) {
        return 3;
    }
    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    return fn_800AA288(0) == 0 ? 3 : 0;
}

s32 fn_800772AC(s32 arg0, s32 arg1) {
    extern u8 gUiContext[];
    extern u8 lbl_80311FB0[];
    gUiContext[8] = 0x20;
    Ui_CreateMenu(lbl_80311FB0, arg1, 0);
    return 4;
}

void fn_800772EC(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x377);
}

void fn_80077318(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x381);
}

s32 fn_80077344(void) {
    u8 Status_Test(void *, s32);
    void fn_8002AE6C(void *);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;

    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x3C) == 0) {
        return 3;
    }
    fn_8002AE6C(*(void **)gUiContext);
    return lbl_802EF4E0.n ? 0 : 3;
}

s32 fn_800773C8(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x11;
    return 5;
}

void fn_800773E0(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x38c);
}

void fn_8007740C(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x394);
}

s32 fn_80077438(void) {
    u8 fn_800BE968(s32, u8, u8);
    extern u8 gUiContext[];
    u8 *p;
    u8 *obj;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    obj = *(u8 **)p;
    return (fn_800BE968(0xE, obj[0x19E], obj[0x19F]) == 0) ? 3 : 0;
}

s32 fn_8007749C(s32 arg0, s32 arg1) {
    extern u8 gUiContext[];
    extern u8 lbl_80311FA4[];
    gUiContext[8] = 0xE;
    Ui_CreateMenu(lbl_80311FA4, arg1, 0);
    return 4;
}

void fn_800774DC(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x39d);
}

void fn_80077508(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x3a6);
}

void fn_80077534(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x3ae);
}

s32 fn_80077560(void) {
    return 0xB;
}

void fn_80077568(s8 *arg0) {
    *arg0 = 2;
}

void fn_80077574(void *arg0, u32 arg1, void *arg2) {
    s32 r31;
    s32 temp_r3;
    s32 temp_r4;
    
    temp_r3 = (s32)arg1 & 0xFFFF;
    r31 = *(s32*)((char*)arg0 + 0x14);
    
    if (temp_r3 == 0) {
        *(s32*)((char*)arg0 + 0x48) = *(s32*)arg2;
    }
    
    if ((r31 & 0x06000000) != 0) {
        temp_r4 = *(s32*)((char*)arg0 + 0x10);
        if (temp_r4 == 0x03) {
            // Return early
            return;
        }
    }
    
    if ((r31 & 0x01000000) != 0) {
        temp_r4 = *(s32*)((char*)arg0 + 0x8);
        if (temp_r4 == 0x02) {
            // Return early
            return;
        }
    }
    
   fn_80019D60(arg0, temp_r3, arg2);
}

void fn_80077694(s8 *arg0) {
    *arg0 = 1;
}

s32 fn_800777D4(void) {
    return 0xC;
}

void fn_800777DC(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x3b6);
}

void fn_80077808(void) {
    extern u8 lbl_8026C0B8[];
    extern void Msg_Expand(void *);

    Msg_Expand(lbl_8026C0B8 + 0x3BE);
}

void fn_80077834(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x3C7);
}

void fn_80077860(void) {
    extern u8 lbl_8026C0B8[];
    Msg_Expand(&lbl_8026C0B8[0x3CF]);
}

void fn_8007788C(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x3d9);
}

s32 fn_800778B8(void) {
    u8 fn_800BE968(s32, u8, u8);
    extern u8 gUiContext[];
    u8 *p;
    u8 *obj;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    obj = *(u8 **)p;
    return (fn_800BE968(9, obj[0x19E], obj[0x19F]) == 0) ? 3 : 0;
}

s32 fn_8007791C(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x9;
    return 5;
}

s32 fn_80077934(void) {
    return 0;
}

void fn_8007793C(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x3e4);
}

void fn_80077968(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x3EE);
}

s32 fn_80077994(void) {
    void fn_8002B2E8(void);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;
    u8 *p;

    p = gUiContext;
    if (p[0x16] & 4) {
        return 3;
    }
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    if (*(u32 *)(*(u8 **)p + 0x1A0) & 2) {
        return 3;
    }
    fn_8002B2E8();
    return lbl_802EF4E0.n ? 0 : 3;
}

s32 fn_80077A18(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x1C;
    return 5;
}

s32 fn_80077A30(void) {
    return 0;
}

void fn_80077A38(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x3F6);
}

void fn_80077A64(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x400);
}

s32 fn_80077A90(void) {
    void fn_8002B520(void *);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;
    u8 *p;
    void *obj;
    s32 flags;

    p = gUiContext;
    if (p[0x16] & 4) {
        return 3;
    }
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    obj = *(void **)p;
    flags = *(s32 *)((u8 *)obj + 0x1A0);
    if (!(flags & 2)) {
        return 3;
    }
    if (flags & 0x100000) {
        return 3;
    }
    fn_8002B520(obj);
    return lbl_802EF4E0.n ? 0 : 3;
}

s32 fn_80077B24(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x1B;
    return 5;
}

void *fn_80077B3C(void) {
    extern u16 lbl_8026C0B8[];
    return (void*)((uintptr_t)&lbl_8026C0B8 + 0x408);
}

s32 fn_80077B4C(void) {
    return 0;
}

void fn_80077B54(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand(&lbl_8026C0B8[0x410 / sizeof(u16)]);
}

void fn_80077B80(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand(&lbl_8026C0B8[0x418 / sizeof(u16)]);
}

s32 fn_80077BAC(void) {
    u8 fn_8001C914(s32, u32);
    u32 *Unit_GetHeldItemSlot(s32, s32);
    u8 fn_8009326C(s32);
    extern u8 gUiContext[];
    s32 obj;
    s32 i;
    u8 *p;
    u32 *entry;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    obj = *(s32 *)p;
    i = 0;
    goto loop;
body:
    entry = Unit_GetHeldItemSlot(obj, i);
    if (*entry == 0) {
        goto next;
    }
    if (fn_8009326C(obj) == 0) {
        goto next;
    }
    if (fn_8001C914(*(s32 *)p, *entry) == 0) {
        goto next;
    }
    return 0;
next:
    i += 1;
loop:
    if (i < 4) {
        goto body;
    }
    return 3;
}

s32 fn_80077C64(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x10;
    return 5;
}

void *fn_80077C7C(void) {
    extern u16 lbl_8026C0B8[];
    return (void*)((uintptr_t)&lbl_8026C0B8 + 0x421);
}

s32 fn_80077C8C(void) {
    return 0;
}

void fn_80077C94(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x42d);
}

void fn_80077CC0(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x439);
}

s32 fn_80077CEC(void) {
    void fn_8002B758(void);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;
    u8 *p;
    u8 *obj;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    obj = *(u8 **)p;
    if (*(u32 *)(obj + 0x194) == 0) {
        return 3;
    }
    if (*(u32 *)(obj + 0x1A0) & 0x100000) {
        return 3;
    }
    fn_8002B758();
    return lbl_802EF4E0.n ? 0 : 3;
}

s32 fn_80077D70(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x1A;
    return 5;
}

void *fn_80077D88(void) {
    extern u8 lbl_8026C0B8[];
    return &lbl_8026C0B8[0x442];
}

s32 fn_80077D98(void) {
    return 0;
}

void fn_80077DA0(void) {
    extern u32 gUiContext[];
    extern u8 lbl_8026C0B8[];
    u8 Status_Test(void *, s32);
    u8 *Msg_Expand(u8 *);

    if (Status_Test((void *)(gUiContext[0] + 0x1BC), 0x16) != 0) {
        Msg_Expand(lbl_8026C0B8 + 0x44D);
    } else {
        Msg_Expand(lbl_8026C0B8 + 0x459);
    }
}

void fn_80077E00(void) {
    extern u32 gUiContext[];
    extern u8 lbl_8026C0B8[];
    u8 Status_Test(void *, s32);
    u8 *Msg_Expand(u8 *);

    if (Status_Test((void *)(gUiContext[0] + 0x1BC), 0x16) != 0) {
        Msg_Expand(lbl_8026C0B8 + 0x464);
    } else {
        Msg_Expand(lbl_8026C0B8 + 0x46E);
    }
}

s32 fn_80077E60(void) {
    void fn_8002B89C(void);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;
    u8 *p;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    if (*(u32 *)(*(u8 **)p + 0x1A0) & 6) {
        return 3;
    }
    fn_8002B89C();
    return lbl_802EF4E0.n ? 0 : 3;
}

s32 fn_80077ED0(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x19;
    return 5;
}

void *fn_80077EE8(void) {
    extern u16 lbl_8026C0B8[];
    return (void*)((uintptr_t)&lbl_8026C0B8 + 0x478);
}

s32 fn_80077EF8(void) {
    return 0;
}

void fn_80077F00(void) {
    s32 Msg_Expand(void *);
    extern u8 lbl_8026C0B8[];
    Msg_Expand(lbl_8026C0B8 + 0x484);
}

void fn_80077F2C(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand(&lbl_8026C0B8[0x490 / sizeof(u16)]);
}

s32 fn_80077F58(void) {
    u8 Status_Test(void *, s32);
    void fn_8002BAFC(void *, s32);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;

    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x45) == 0) {
        return 3;
    }
    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    fn_8002BAFC(*(void **)gUiContext, 2);
    return lbl_802EF4E0.n ? 0 : 3;
}

s32 fn_80077FE0(void) {
    extern u8 gUiContext[];
    u8 *p = gUiContext;
    p[8] = 0x14;
    return 5;
}

void *fn_80077FF8(void) {
    extern u16 lbl_8026C0B8[];
    return (void*)((uintptr_t)&lbl_8026C0B8 + 0x498);
}

void fn_80078008(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x4A3);
}

void fn_80078034(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x4AF);
}

s32 fn_80078060(void) {
    u8 Status_Test(void *, s32);
    void fn_8002BAFC(void *, s32);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;
    u8 *p;

    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x44) == 0) {
        return 3;
    }
    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    fn_8002BAFC(*(void **)p, 1);
    return lbl_802EF4E0.n ? 0 : 3;
}

s32 fn_800780E8(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x13;
    return 5;
}

void fn_80078100(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x4b7);
}

void fn_8007812C(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u16*)((u8*)lbl_8026C0B8 + 0x4BE));
}

s32 fn_80078158(void) {
    extern u8 gUiContext[], gMapObjEventList[], lbl_802EF4E0[];
    u8 Status_Test(void *, s32); void *MapObjEvent_Find(void *, s32, s32, s32); void fn_8002BD44(void *, void *);
    void *obj; void *entry;
    if (*(s8 *)(gUiContext + 0x12)) return 3;
    obj = *(void **)gUiContext;
    if (!Status_Test((u8 *)obj + 0x1BC, 0x4F)) return 3;
    entry = MapObjEvent_Find(gMapObjEventList, *(u8 *)((u8 *)obj + 0x19E), *(u8 *)((u8 *)obj + 0x19F), 7);
    if (!entry) return 3;
    fn_8002BD44(*(void **)gUiContext, entry);
    if (*(s32 *)lbl_802EF4E0 == 0) return 3;
    if (*(u8 *)((u8 *)entry + 5) == 0) return 2;
    return 0;
}

s32 fn_80078334(void) {
    void *fn_80019E24(u8);
    s32 fn_8001DDBC(void);
    void fn_8001EF80(void *, u8, u8, u8);
    void fn_8002011C(void *, u8, u8, u8, s32);
    void fn_80022DAC(void *, s32, s32);
    void fn_80022FD8(void *, s32);
    void Map_ShowMoveLimitView(void);
    void *MapObjEvent_Find(void *, u8, u8, s32);
    extern u8 gBattleMap[];
    extern u8 gUiContext[];
    extern u8 gMapObjEventList[];
    u8 *p;
    u8 a, b, c;

    fn_80022DAC(gBattleMap, 5, -1);
    fn_80022DAC(gBattleMap, 8, 0);
    fn_80022FD8(gBattleMap, 6);
    p = MapObjEvent_Find(gMapObjEventList, gUiContext[13], gUiContext[14], 7);
    a = *((u8 *)fn_80019E24(p[4]) + 29);
    b = p[1];
    c = p[0];
    fn_8002011C(gBattleMap, c, b, a, fn_8001DDBC());
    fn_8001EF80(gBattleMap, p[0], p[1], p[3]);
    Map_ShowMoveLimitView();
    return 0;
}

s32 fn_80078420(void) {
    M2C_UNK Map_HideMoveLimitView();
    Map_HideMoveLimitView();
    return 0;
}

void fn_80078444(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u16*)((u8*)lbl_8026C0B8 + 0x4DA));
}

void fn_80078470(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u16*)((u8*)lbl_8026C0B8 + 0x4E5));
}

s32 fn_8007849C(void) {
    extern u8 gUiContext[];
    u8 *p = gUiContext;
    p[8] = 0x15;
    return 5;
}

s32 fn_800785E4(void) {
    M2C_UNK Map_ShowMoveLimitView();
    M2C_UNK fn_800AAB3C(s32);
    extern s32 gUiContext[];
    fn_800AAB3C(gUiContext[0]);
    Map_ShowMoveLimitView();
    return 0;
}

s32 fn_80078618(void) {
    M2C_UNK Map_HideMoveLimitView();
    Map_HideMoveLimitView();
    return 0;
}

void fn_8007863C(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u16*)((u8*)lbl_8026C0B8 + 0x4EE));
}

void fn_80078668(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u16*)((u8*)lbl_8026C0B8 + 0x4F6));
}

s32 fn_80078694(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x27;
    return 5;
}

s32 fn_800786AC(void) {
    void *Item_GetFlagsPtr(void);
    void fn_8002BEFC(void *, u32);
    u32 *Unit_GetHeldItemSlot(void *, s32);
    u8 fn_8009339C(void *, u32);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;
    u32 *entry;
    s32 i;
    u8 *p;
    void *tmp;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    i = 0;
    do {
        entry = Unit_GetHeldItemSlot(*(void **)p, i);
        if (*entry != 0) {
            tmp = Item_GetFlagsPtr();
            if ((*(u64 *)tmp & 1) != 0
                && fn_8009339C(*(void **)gUiContext, *entry) != 0) {
                fn_8002BEFC(*(void **)gUiContext, *entry);
                if (lbl_802EF4E0.n != 0) {
                    return 0;
                }
            }
            i += 1;
        } else {
            break;
        }
    } while (i < 4);
    return 3;
}

void fn_800787A0(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u16*)((u8*)lbl_8026C0B8 + 0x4FE));
}

void fn_800787CC(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x509);
}

s32 fn_800787F8(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0xF;
    return 5;
}

s32 fn_80078810(void) {
    void *Item_GetFlagsPtr(void);
    void fn_8002C034(void *, u32);
    u32 *Unit_GetHeldItemSlot(void *, s32);
    u8 fn_8009339C(void *, u32);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;
    u32 *entry;
    s32 i;
    u8 *p;
    void *tmp;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    i = 0;
    do {
        entry = Unit_GetHeldItemSlot(*(void **)p, i);
        if (*entry != 0) {
            tmp = Item_GetFlagsPtr();
            if ((*(u64 *)tmp & 1) != 0
                && fn_8009339C(*(void **)gUiContext, *entry) != 0) {
                fn_8002C034(*(void **)gUiContext, *entry);
                if (lbl_802EF4E0.n != 0) {
                    return 0;
                }
            }
            i += 1;
        } else {
            break;
        }
    } while (i < 4);
    return 3;
}

void fn_80078904(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x512);
}

void fn_80078930(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x51b);
}

s32 fn_8007895C(void) {
    u8 fn_80093088(s32);
    extern u8 gUiContext[];
    u8 *p;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    return (fn_80093088(*(s32 *)p) != 0) ? 3 : 0;
}

s32 fn_800789B4(void) {
    *(u8 *)((u32)&D_802EF4C8 + 8) = 2;
    return 5;
}

void fn_800789CC(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x522);
}

void fn_800789F8(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x52b);
}

s32 fn_80078A24(void) {
    void fn_8002B0A4(void *);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } lbl_802EF4E0;
    u8 *p;
    void *obj;
    u8 v;

    p = gUiContext;
    if (p[0x16] & 1) {
        return 3;
    }
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    obj = *(void **)p;
    fn_8002B0A4(obj);
    if (lbl_802EF4E0.n == 0) {
        return 3;
    }
    v = *(u8 *)((u8 *)*(void **)gUiContext + 0x1A5);
    return ((v >> 4) & 7) ? 2 : 0;
}

#pragma cplusplus on
extern "C" s32 fn_80078AB8(s32 arg0, void *arg1, void *arg2) {
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
    extern u8 lbl_8026C0B8[];
    extern u8 gUiContext[];
    s32 Msg_Expand(void *);
    void fn_80166AE8(s32, s32, s32, void *);
    s32 a;
    s32 str;
    s16 y;
    s16 x;
    Obj *obj;
    s32 b;

    if (((u8 *)arg2)[0x39] != 0) {
        obj = *(Obj **)((u8 *)arg1 + 0x3C);
        y = *(s16 *)((u8 *)arg2 + 0x32);
        x = *(s16 *)((u8 *)arg2 + 0x30);
        str = Msg_Expand(lbl_8026C0B8 + 0x535);
        a = obj->v22();
        b = obj->v21();
        fn_80166AE8(b + x, a + y, str, arg1);
        return 0;
    }
    {
        u8 *p = gUiContext;
        p[8] = 7;
    }
    return 5;
}
#pragma cplusplus reset
void fn_80078B6C(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x53d);
}

void fn_80078B98(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x545);
}

s32 fn_80078BC4(void) {
    u8 fn_800BE968(s32, u8, u8);
    extern u8 gUiContext[];
    u8 *p;
    u8 *obj;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    obj = *(u8 **)p;
    return (fn_800BE968(0x29, obj[0x19E], obj[0x19F]) == 0) ? 3 : 0;
}

s32 fn_80078C28(s32 arg0, s32 arg1) {
    extern u8 gUiContext[];
    extern u8 lbl_80311F98[];
    gUiContext[8] = 0x29;
    Ui_CreateMenu(lbl_80311F98, arg1, 0);
    return 4;
}

void fn_80078C68(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x54e);
}

void fn_80078C94(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x557);
}

s32 fn_80078CC0(void) {
    void *fn_80105C5C(void *, s32);
    u8 fn_800BE968(s32, u8, u8);
    extern u8 gUiContext[];
    u8 *p;
    u8 *obj;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    obj = *(u8 **)p;
    if (fn_80105C5C(obj + 0x1BC, 0) == 0) {
        return 3;
    }
    return (fn_800BE968(0xD, obj[0x19E], obj[0x19F]) == 0) ? 3 : 0;
}

s32 fn_80078D48(s32 arg0, s32 arg1) {
    extern u8 gUiContext[];
    extern u8 lbl_80311F8C[];
    gUiContext[8] = 0xD;
    Ui_CreateMenu(lbl_80311F8C, arg1, 0);
    return 4;
}

void fn_80078D88(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x561);
}

void fn_80078DB4(void) {
    extern u16 lbl_8026C0B8[];
    Msg_Expand((u8 *)lbl_8026C0B8 + 0x56b);
}

s32 fn_80078DE0(void) {
    *(u8 *)((u32)&D_802EF4C8 + 8) = 1;
    return 5;
}

void fn_80078DF8(void) {
    extern u8 lbl_80288AA8[];
    void fn_8000A440(s32, void *);
    fn_8000A440(2, lbl_80288AA8);
}

s32 fn_80078E24(void *arg0) {
    s32 fn_80006220(s16);
    s32 temp_r3 = ((s32 *) arg0)[1];
    fn_80006220((s16) (((u32) ((s32 *) temp_r3)[0]) >> 16));
    ((u8 **) arg0)[1] = (u8 *) ((s32 *) arg0)[1] + 4;
    return 1;
}

s32 fn_80078E70(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_80078E84(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_80078E98(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_80078EAC(void *arg0) {
    u8 fn_80018A08(M2C_UNK);
    if (fn_80018A08(0) != 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_80078EFC(void *arg0) {
    Msg_Expand(((s32 **) arg0)[1][1]);
    fn_80091A1C();
    ((s32 **) arg0)[1] = (s32 *) (((s32 **) arg0)[1]) + 2;
    return 1;
}

s32 fn_80078F44(void *arg0) {
    s32 fn_80091A1C(s32);
    fn_80091A1C(((s32 **) arg0)[1][1]);
    ((s32 **) arg0)[1] = ((s32 **) arg0)[1] + 2;
    return 1;
}

s32 fn_80078F88(void *arg0)
{
    extern u8 lbl_8036723A;

    u8 *data;
    void (*callback)(void *);

    if (lbl_8036723A == 9) {
        data = *(u8 **)((u8 *)arg0 + 4);
        callback = *(void (**)(void *))(data + 4);

        *(u8 **)((u8 *)arg0 + 4) = data + 8;

        callback(arg0);

        data = *(u8 **)((u8 *)arg0 + 4);
        *(u8 **)((u8 *)arg0 + 4) = data - 8;
    }

    data = *(u8 **)((u8 *)arg0 + 4);
    *(u8 **)((u8 *)arg0 + 4) = data + 8;

    return 1;
}

s32 fn_80078FF0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_80079004(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_80079018(void *arg0) {
    void Process_Goto(void *, u8);
    extern u8 lbl_8036723A;
    u32 *ptr;

    if (lbl_8036723A == 9) {
        ptr = *(u32 **)((u8 *)arg0 + 4);
        Process_Goto(arg0, (u8)(*ptr >> 16));
    }
    *(u8 **)((u8 *)arg0 + 4) = *(u8 **)((u8 *)arg0 + 4) + 4;
    return 1;
}

s32 fn_8007906C(void *arg0) {
    void Process_Goto(void *, u8);
    extern u8 gUiContext[];
    u32 *ptr;
    u32 val;

    ptr = *(u32 **)((u8 *)arg0 + 4);
    val = *ptr;
    if ((val >> 24) == gUiContext[8]) {
        Process_Goto(arg0, (u8)(val >> 16));
    }
    *(u8 **)((u8 *)arg0 + 4) = *(u8 **)((u8 *)arg0 + 4) + 4;
    return 1;
}

s32 fn_800790CC(void) {
    return 0;
}

void fn_800790D4(s32 arg0, s32 arg1) {
    void *fn_8000CA64(void *, s32);
    void fn_8000C068(void *, s32);
    extern u8 lbl_80288CAC[];
    extern void fn_80079138(void);
    void *temp_r3;

    temp_r3 = fn_8000CA64(lbl_80288CAC, arg1);
    *(s32 *)((char *)temp_r3 + 0x30) = arg0;
    *(s32 *)((char *)temp_r3 + 0x34) = 0;
    *(s32 *)((char *)temp_r3 + 0x38) = 8;
    *(s16 *)((char *)temp_r3 + 0x28) = 8;
    *(s32 *)((char *)temp_r3 + 0x3C) = 0xFF;
    *(s32 *)((char *)temp_r3 + 0x40) = 0;
    fn_8000C068(temp_r3, (s32)fn_80079138);
}

void fn_80079138(void *arg0) {
    extern void *gFaceSlots[];
    void Process_Unlink(void *);
    void *temp_r3;

    temp_r3 = M2C_FIELD(arg0, void **, 0x30);
    if (temp_r3 != NULL) {
        s32 index = *(u8 *)((u8 *)temp_r3 + 0x40);
        if (gFaceSlots[index] != NULL) {
            Process_Unlink(gFaceSlots[index]);
        }
        gFaceSlots[index] = NULL;
    }
}

void fn_80079198(s32 arg0, s32 arg1) {
    void *fn_8000CA64(void *, s32);
    extern u8 lbl_80288CAC[];
    void *temp_r3;

    temp_r3 = fn_8000CA64(lbl_80288CAC, arg1);
    *(s32 *)((char *)temp_r3 + 0x30) = arg0;
    *(s32 *)((char *)temp_r3 + 0x34) = 0;
    *(s32 *)((char *)temp_r3 + 0x38) = 8;
    *(s16 *)((char *)temp_r3 + 0x28) = 8;
    *(s32 *)((char *)temp_r3 + 0x3C) = 0xFF;
    *(s32 *)((char *)temp_r3 + 0x40) = 0;
}

void fn_800791F0(s32 arg0, s32 arg1) {
    void *fn_8000CA64(void *, s32);
    extern u8 lbl_80288CAC[];
    void *temp_r3;

    temp_r3 = fn_8000CA64(lbl_80288CAC, arg1);
    *(s32 *)((char *)temp_r3 + 0x30) = arg0;
    *(s32 *)((char *)temp_r3 + 0x34) = 0;
    *(s32 *)((char *)temp_r3 + 0x38) = 8;
    *(s16 *)((char *)temp_r3 + 0x28) = 8;
    *(s32 *)((char *)temp_r3 + 0x3C) = 0;
    *(s32 *)((char *)temp_r3 + 0x40) = 0xFF;
}

void fn_80079248(void*p){f32 Math_Ease(s32,f32,f32,f32,f32);*(s32*)((u8*)p+0x34)+=1;*(s8*)((u8*)*(void**)((u8*)p+0x30)+0x42)=Math_Ease(0,(f32)*(s32*)((u8*)p+0x3c),(f32)*(s32*)((u8*)p+0x40),(f32)*(s32*)((u8*)p+0x34),(f32)*(s32*)((u8*)p+0x38));}

void fn_80079300(void *arg0, s8 arg1) {
    extern s16 lbl_80312060[];
    u8 *temp_r4;

    if (arg1 >= 0) {
        M2C_FIELD(arg0, s8 *, 0x43) = arg1;
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) lbl_80312060[arg1 * 3];
        temp_r4 = (u8 *)lbl_80312060 + arg1 * 6;
        M2C_FIELD(arg0, f32 *, 0x3C) = (f32) *(s16 *)(temp_r4 + 2);
        M2C_FIELD(arg0, u16 *, 0x46) = (u16) (M2C_FIELD(arg0, u16 *, 0x46) | (s16) *(u16 *)(temp_r4 + 4));
    }
}

void *fn_80079380(s8 arg0) {
extern void *gFaceSlots[];
void **p; void *v; s32 i;
if(arg0<0) return NULL;
p=gFaceSlots;
for(i=0;i<8;p++,i++) {
v=*p;
if(v && arg0==*(s8 *)((u8 *)v+0x43)) return gFaceSlots[i];
}
return NULL;
}

void fn_800793EC(void *arg0,s32 arg1){
void *Res_GetByName(void *); void *fn_802002F0(void *); void fn_80200270(void *); void fn_80009EB0(void *,s32,s32,s32); extern u8 lbl_8026C640[];
s32 idx; void *node;
node=Res_GetByName(arg0); node=node ? node : Res_GetByName(lbl_8026C640+0xef);
idx=*(u16*)((u8*)node+0x1a); if(idx==65535)idx=0;
fn_80009EB0(fn_802002F0(arg0),idx,0,arg1); fn_80200270(arg0);
}

void Face_DebugScaleProc(void *proc) {
    void Prim2D_SetText(void *);
    void Prim2D_SetScale(f32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Process_Unlink(void *);
    void Process_ClearFunc(void *);
    void fn_8007B4D8(s32, s32, s32, void *);
    void sprintf(void *, void *, ...);
    extern u8 lbl_8026C640[];
    extern void *gFaceSlots[];
    extern void *gPadInput;
    extern f32 gFaceDbgScaleStep;
    extern f32 lbl_803693D4;
    extern f32 lbl_803693D8;
    extern f32 gFaceDbgTextX;
    extern f32 gFaceDbgPosY;
    extern f32 gFaceDbgTextScale;
    extern f32 gFaceDbgPosX;
    // Adjust face draw scale with up/down, overlay the value, draw the face; B clears the slot.
    char buf[0x100];
    s32 buttons;
    s32 prev;
    f32 scale;
    void *face;
    s32 index;
    void *slot;

    buttons = *(s32 *)((u8 *)gPadInput + 4);
    prev = *(s32 *)((u8 *)gPadInput + 8);
    if (buttons & (prev ^ buttons) & 0x08000008) {
        *(f32 *)((u8 *)proc + 0x34) = *(f32 *)((u8 *)proc + 0x34) + gFaceDbgScaleStep;
    }
    buttons = *(s32 *)((u8 *)gPadInput + 4);
    prev = *(s32 *)((u8 *)gPadInput + 8);
    if (buttons & (prev ^ buttons) & 0x04000004) {
        *(f32 *)((u8 *)proc + 0x34) = *(f32 *)((u8 *)proc + 0x34) - gFaceDbgScaleStep;
    }
    sprintf(buf, lbl_8026C640 + 0xF9, *(f32 *)((u8 *)proc + 0x34));
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_803693D4, lbl_803693D4, lbl_803693D4, lbl_803693D8);
    Prim2D_SetTex(0, 3);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(5);
    Prim2D_SetPos(gFaceDbgTextX, gFaceDbgPosY);
    Prim2D_SetText(buf);
    Prim2D_SetScale(gFaceDbgTextScale);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_803693D4, lbl_803693D4, lbl_803693D4, *(f32 *)((u8 *)proc + 0x34));
    Prim2D_PrepareTex();
    scale = *(f32 *)((u8 *)proc + 0x34);
    fn_8007B4D8((s32)(gFaceDbgPosY / scale), (s32)(gFaceDbgPosX / scale), 0xFF,
                *(void **)((u8 *)proc + 0x30));
    buttons = *(s32 *)((u8 *)gPadInput + 4);
    prev = *(s32 *)((u8 *)gPadInput + 8);
    if (buttons & (prev ^ buttons) & 0x200) {
        face = *(void **)((u8 *)proc + 0x30);
        if (face != NULL) {
            index = *(u8 *)((u8 *)face + 0x40);
            slot = gFaceSlots[index];
            if (slot != NULL) {
                Process_Unlink(slot);
            }
            gFaceSlots[index] = NULL;
        }
        Process_ClearFunc(proc);
    }
}

void fn_80079B9C(void *arg1, void *arg2) {
    // Placeholder function to examine structure; we'll need exact matching later
    
    // This function likely does coordinate processing and calls
    // Based on the pattern in other functions in this file:
    // It's modifying coordinates and making calls that use global state
}

void fn_80079CD8(void *arg0) {
    M2C_UNK Process_Goto(void *, s32);
    u32 Rand_Next();
    void fn_8007A524(void *, s32, s32);
    s32 var_r31 = 0;
    s32 temp_r0 = M2C_FIELD(arg0, s16 *, 0x38);
    u32 temp_r3;
    s16 temp_r0_2;
    s32 var_r0;

    if (temp_r0 < 0xc) {
        if (temp_r0 < 6) {
            if (temp_r0 < 0) {
            } else {
                var_r31 = 1;
            }
        } else {
            if (temp_r0 == 0x12) {
                var_r31 = 2;
            } else if (temp_r0 >= 0x12) {
                var_r31 = 0;
            } else {
                var_r31 = 1;
            }
        }
    } else {
        Process_Goto(arg0, 1);
        M2C_FIELD(arg0, s16 *, 0x36) = 1;
        temp_r3 = Rand_Next() >> 0x10U;
        temp_r0_2 = M2C_FIELD(arg0, s16 *, 0x34);
        switch (temp_r0_2) {
        case 3:
            var_r0 = ((s32) temp_r3 >> 7) + 0x12C;
            break;
        case 1:
            var_r0 = ((s32) temp_r3 >> 7) + 0x1E;
            break;
        case 2:
            var_r0 = 1;
            break;
        case 4:
            var_r0 = ((s32) temp_r3 >> 10) + 1;
            break;
        case 5:
            var_r0 = 0x7FFFFFFF;
            break;
        default:
            var_r0 = 1;
            break;
        }
        M2C_FIELD(arg0, s32 *, 0x3C) = var_r0;
    }

    fn_8007A524(arg0, 0, 7);
    fn_8007A524(arg0, var_r31, 0xA);
    M2C_FIELD(arg0, s16 *, 0x38) = (s16) (M2C_FIELD(arg0, s16 *, 0x38) + 1);
}

void fn_80079E08(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
}

void fn_80079E14(void *arg0) {
    void Process_Goto(void *, s32);
    u32 Rand_Next();
    void fn_8007A524(void *, s32, s32);
    s32 var_r31;
    s32 var_r0;
    u32 temp_r3;

    var_r31 = 0;
    switch ((s16)M2C_FIELD(arg0, s16 *, 0x38)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        var_r31 = 1;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        var_r31 = 2;
        break;
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
        var_r31 = 1;
        break;
    case 18:
        Process_Goto(arg0, 1);
        M2C_FIELD(arg0, s16 *, 0x36) = 1;
        temp_r3 = Rand_Next() >> 0x10U;
        switch ((s16)M2C_FIELD(arg0, s16 *, 0x34)) {
        case 3:
            var_r0 = ((s32)temp_r3 >> 7) + 0x12C;
            break;
        case 1:
            var_r0 = ((s32)temp_r3 >> 7) + 0x1E;
            break;
        case 2:
            var_r0 = ((s32)temp_r3 >> 0xA) + 1;
            break;
        case 4:
            var_r0 = 1;
            break;
        case 5:
            var_r0 = 0x7FFFFFFF;
            break;
        default:
            var_r0 = 1;
            break;
        }
        M2C_FIELD(arg0, s32 *, 0x3C) = var_r0;
        break;
    }
    fn_8007A524(arg0, var_r31, 7);
    fn_8007A524(arg0, 0, 0xA);
    M2C_FIELD(arg0, s16 *, 0x38) = (s16)(M2C_FIELD(arg0, s16 *, 0x38) + 1);
}

void fn_80079F44(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
}

void fn_80079F50(void *arg0) {
    void Process_Goto(void *, s32);
    u32 Rand_Next();
    void fn_8007A524(void *, s32, s32);
    s32 var_r0;
    u32 temp_r3;

    fn_8007A524(arg0, 0, 7);
    fn_8007A524(arg0, 0, 0xA);
    if ((s16) M2C_FIELD(arg0, s16 *, 0x36) != 5) {
        Process_Goto(arg0, 1);
        temp_r3 = Rand_Next() >> 0x10U;
        switch ((s16) M2C_FIELD(arg0, s16 *, 0x34)) {
        case 3:
            var_r0 = ((s32) temp_r3 >> 7) + 0x12C;
            break;
        case 1:
            var_r0 = ((s32) temp_r3 >> 7) + 0x1E;
            break;
        case 2:
            var_r0 = ((s32) temp_r3 >> 0xA) + 1;
            break;
        case 4:
            var_r0 = 1;
            break;
        case 5:
            var_r0 = 0x7FFFFFFF;
            break;
        default:
            var_r0 = 1;
            break;
        }
        M2C_FIELD(arg0, s32 *, 0x3C) = var_r0;
    }
}

void fn_8007A024(void *arg0) {
    M2C_UNK var_r31;
    s32 temp_r0;
    s32 var_r0;
    u32 temp_r3;
    u32 temp_r3_hi;

    temp_r0 = M2C_FIELD(arg0, s16 *, 0x38);
    if (temp_r0 <= 2) {
        var_r31 = 0;
        if (temp_r0 == 9) {
        } else if (temp_r0 < 9) {
            if (temp_r0 >= 3) {
                if (temp_r0 >= 6) {
                    var_r31 = 1;
                } else {
                    var_r31 = 2;
                }
            } else {
                if (temp_r0 >= 0) {
                    var_r31 = 1;
                }
            }
        } else if (temp_r0 < 0xB) {
            var_r31 = 1;
        }
        Process_Goto(arg0, 1);
        fn_8007A524(arg0, var_r31, 7);
        fn_8007A524(arg0, var_r31, 0xA);
        M2C_FIELD(arg0, s16 *, 0x38) = (s16)(M2C_FIELD(arg0, s16 *, 0x38) + 1);
        return;
    }
    fn_8007A524(arg0, 1, 7);
    fn_8007A524(arg0, 1, 0xA);
    if ((s16)M2C_FIELD(arg0, s16 *, 0x36) != 4) {
        Process_Goto(arg0, 1);
        temp_r3 = Rand_Next();
        temp_r3_hi = temp_r3 >> 0x10U;
        switch ((s16)M2C_FIELD(arg0, s16 *, 0x34)) {
        case 3:
            var_r0 = ((s32)temp_r3_hi >> 7) + 0x12C;
            break;
        case 1:
            var_r0 = ((s32)temp_r3_hi >> 7) + 0x1E;
            break;
        case 2:
            var_r0 = ((s32)temp_r3_hi >> 0xA) + 1;
            break;
        case 4:
            var_r0 = 1;
            break;
        case 5:
            var_r0 = 0x7FFFFFFF;
            break;
        default:
            var_r0 = 1;
            break;
        }
        M2C_FIELD(arg0, s32 *, 0x3C) = var_r0;
    }
}

void fn_8007A198(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
}

void fn_8007A1A4(void *arg0) {
    s32 r31;
    s32 v;

    if (*(s16 *)((u8 *)arg0 + 0x38) > 5) goto A;
    v = *(s16 *)((u8 *)arg0 + 0x38);
    r31 = 0;
    if (v == 9) goto B;
    if (v >= 9) goto C;
    if (v >= 3) goto D;
    if (v >= 0) goto E;
    goto B;
D:
    if (v >= 6) goto F;
    goto G;
C:
    if (v >= 0xB) goto B;
    goto H;
F:
    r31 = 1;
    goto B;
G:
    r31 = 2;
    goto B;
E:
    r31 = 1;
    goto B;
H:
    r31 = 1;
    goto B;
B:
    Process_Goto(arg0, 1);
    fn_8007A524(arg0, r31, 7);
    fn_8007A524(arg0, r31, 10);
    *(s16 *)((u8 *)arg0 + 0x38) = *(s16 *)((u8 *)arg0 + 0x38) + 1;
    return;
A:
    fn_8007A524(arg0, 2, 7);
    fn_8007A524(arg0, 2, 10);
    if (*(s16 *)((u8 *)arg0 + 0x36) != 3) {
        Process_Goto(arg0, 2);
    }
}

void fn_8007A2A0(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
}

void fn_8007A2AC(void *arg0) {
    void Process_Goto(void *, s32);
    void fn_8007A524(void *, s32, s32);
    s32 var_r31;

    var_r31 = 0;
    switch ((s16)*(s16 *)((u8 *)arg0 + 0x38)) {
    case 0:
    case 1:
    case 2:
        var_r31 = 1;
        break;
    case 3:
    case 4:
    case 5:
        var_r31 = 2;
        break;
    case 6:
    case 7:
    case 8:
        var_r31 = 1;
        break;
    case 9:
        break;
    case 10:
        Process_Goto(arg0, 1);
        break;
    default:
        break;
    }

    fn_8007A524(arg0, var_r31, 7);
    fn_8007A524(arg0, var_r31, 0xA);
    *(s16 *)((u8 *)arg0 + 0x38) = (s16)(*(s16 *)((u8 *)arg0 + 0x38) + 1);
}

void fn_8007A368(void *arg0) {
    void Process_Goto(void *, s32);
    u32 Rand_Next(void);
    void fn_8007A524(void *, s32, s32);
    s16 unk36;
    s16 unk34;
    s32 val;
    u32 rnd;

    val = *(s32 *)((u8 *)arg0 + 0x3C);
    *(s32 *)((u8 *)arg0 + 0x3C) = val - 1;
    fn_8007A524(arg0, 0, 7);
    fn_8007A524(arg0, 0, 0xA);
    unk36 = *(s16 *)((u8 *)arg0 + 0x36);
    if (unk36 != 1) {
        Process_Goto(arg0, (u8)unk36);
        return;
    }
    if (*(s32 *)((u8 *)arg0 + 0x3C) >= 0) {
        return;
    }
    rnd = Rand_Next();
    unk34 = *(s16 *)((u8 *)arg0 + 0x34);
    rnd >>= 16;
    switch (unk34) {
    case 3:
        val = ((s32)rnd >> 7) + 0x12C;
        break;
    case 1:
        val = ((s32)rnd >> 7) + 0x1E;
        break;
    case 2:
        val = ((s32)rnd >> 10) + 1;
        break;
    case 4:
        val = 1;
        break;
    case 5:
        val = 0x7FFFFFFF;
        break;
    default:
        val = 1;
        break;
    }
    *(s32 *)((u8 *)arg0 + 0x3C) = val;
    *(s16 *)((u8 *)arg0 + 0x38) = 0;
    Process_Goto(arg0, 2);
}

#pragma dont_inline on
void fn_8007A46C(void *p) {
    u32 Rand_Next(s32);
    s32 x;
    s32 t;
    s32 v;

    x = *(s32 *)((u8 *)p + 0x18);
    *(s32 *)((u8 *)p + 0x30) = x;
    *(s16 *)((u8 *)p + 0x34) = 1;
    t = Rand_Next(x) >> 16;
    switch (*(s16 *)((u8 *)p + 0x34)) {
    case 3:
        v = (t >> 7) + 0x12c;
        break;
    case 1:
        v = (t >> 7) + 0x1e;
        break;
    case 2:
        v = (t >> 10) + 1;
        break;
    case 4:
        v = 1;
        break;
    case 5:
        v = 0x7fffffff;
        break;
    default:
        v = 1;
        break;
    }
    *(s32 *)((u8 *)p + 0x3c) = v;
    *(s16 *)((u8 *)p + 0x36) = 1;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8007A524(void *arg0, s32 arg1, s32 arg2) {
    void **fn_8006EDD8(void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void fn_80009EB0(void *, s32, u8, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, u8);
    void Prim2D_EndPrim(void);
    extern f64 lbl_803693C8;
    extern f32 lbl_803693D4;
    extern f64 lbl_803693F0;
    extern f32 lbl_803693EC;
    extern f32 lbl_80366E00;
    int w2;
    s32 h2;
    s16 x;
    s16 y;
    s32 mode;
    void *obj;
    void *info;
    void **pp;
    void *entry;
    register void *state;
    int w;
    int h;
    register u8 tint;
    u8 pad;
    f32 stackpad[4];

    mode = arg2;
    obj = *(void **)((u8 *)arg0 + 0x30);
    info = *(void **)((u8 *)obj + 0x34);
    if ((*(u16 *)((u8 *)info + 0x18) & 2) == 0) {
        mode -= 6;
    }
    if ((u32)(mode - 7) > 1U) {
        if (mode == 9) {
            if (*(u16 *)((u8 *)info + 0xC) == *(u16 *)((u8 *)info + 0x10)) {
                return;
            }
        }
    }
    if (arg2 == 7) {
        x = *(u16 *)((u8 *)info + 0xC);
        y = *(u16 *)((u8 *)info + 0xE);
    } else {
        x = *(u16 *)((u8 *)info + 0x10);
        y = *(u16 *)((u8 *)info + 0x12);
    }
    switch (arg1) {
    case 0: break;
    case 1: case 3: mode++; break;
    case 2: mode += 2; break;
    }
    pp = fn_8006EDD8(*(void **)((u8 *)obj + 0x30), 0);
    entry = *pp;
    w = *(u16 *)((u8 *)entry + 2);
    h = *(u16 *)((u8 *)entry + 0);
    obj = *(void **)((u8 *)arg0 + 0x30);
    if ((*(u16 *)((u8 *)obj + 0x46) & 1) != 0) {
        x = (s16)(w - x);
    }
    x = (s16)((f32)x + (*(f32 *)((u8 *)obj + 0x38) - (f32)(w >> 1)));
    y = (s16)((f32)y + (*(f32 *)((u8 *)obj + 0x3C) - (f32)h));
    pp = fn_8006EDD8(*(void **)((u8 *)obj + 0x30), mode);
    entry = *pp;
    w2 = *(u16 *)((u8 *)entry + 2);
    h2 = *(u16 *)((u8 *)entry + 0);
    if ((*(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x46) & 1) != 0) {
        x = (s16)(x - w2);
    }
    Prim2D_Begin();
    state = *(void **)((u8 *)arg0 + 0x30);
    obj = state;
    tint = *(u8 *)((u8 *)*(void **)((u8 *)obj + 0x34) + 0x1D);
    Prim2D_SetTransform(lbl_803693D4, lbl_803693D4, lbl_80366E00 + ((f32)(u32)tint / lbl_803693EC), *(f32 *)((u8 *)obj + 0x4C));
    obj = *(void **)((u8 *)arg0 + 0x30);
    fn_80009EB0(*(void **)((u8 *)obj + 0x30), mode, *(u8 *)((u8 *)obj + 0x40), 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    if ((*(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x46) & 1) != 0) {
        Prim2D_SetQuadMin((f32)x, (f32)y, (f32)w2, lbl_803693D4);
        Prim2D_SetQuadMax((f32)(x + w2), (f32)(y + h2), lbl_803693D4, (f32)h2);
    } else {
        Prim2D_SetQuadMin((f32)x, (f32)y, lbl_803693D4, lbl_803693D4);
        Prim2D_SetQuadMax((f32)(x + w2), (f32)(y + h2), (f32)w2, (f32)h2);
    }
    state = *(void **)((u8 *)arg0 + 0x30);
    obj = state;
    tint = *(u8 *)((u8 *)obj + 0x41);
    pad = *(u8 *)((u8 *)obj + 0x42);
    Prim2D_SetColor(tint, tint, tint, pad);
    Prim2D_EndPrim();
    (void)stackpad[0];
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8007A8D8(void *arg0) {
    s32 fn_8000CEE4(s32);
    void **fn_8006EDD8(void *, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void fn_80009EB0(void *, s32, u8, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, u8);
    void Prim2D_EndPrim(void);
    extern f64 lbl_803693C8;
    extern f32 lbl_803693D4;
    extern f64 lbl_803693F0;
    extern f32 lbl_803693EC;
    extern f32 lbl_80366E00;
    double stackpad[2];
    s32 w2;
    s32 h2;
    s16 x;
    s16 y;
    s32 base;
    s32 mode;
    u8 *obj;
    void *info;
    void **pp;
    void *entry;
    s32 w;
    s32 h;
    u8 tint;
    f32 alpha;
    u8 pad;
    u16 flags;
    s32 timer;

    timer = *(s16 *)((u8 *)arg0 + 0x36);
    if (timer > 0) {
        *(s16 *)((u8 *)arg0 + 0x36) = (s16)(timer - 1);
        if (*(s16 *)((u8 *)arg0 + 0x36) == 0) {
            *(s16 *)((u8 *)arg0 + 0x36) = (s16)(fn_8000CEE4(8) + 1);
            *(s16 *)((u8 *)arg0 + 0x34) = (s16)((*(s16 *)((u8 *)arg0 + 0x34) + 1) & 3);
        }
    }

    obj = *(void **)((u8 *)arg0 + 0x30);
    base = 1;
    flags = *(u16 *)(obj + 0x46);
    info = *(void **)(obj + 0x34);
    x = *(u16 *)((u8 *)info + 0x14);
    y = *(u16 *)((u8 *)info + 0x16);
    if ((flags & 2) != 0) {
        base = 4;
    }
    mode = base;
    switch (*(s16 *)((u8 *)arg0 + 0x34)) {
    case 0:
        if ((flags & 0x20) != 0) {
            *(s16 *)((u8 *)arg0 + 0x36) = -1;
        }
        break;
    case 1:
    case 3:
        mode += 1;
        if ((flags & 0x40) != 0) {
            *(s16 *)((u8 *)arg0 + 0x36) = -1;
        }
        break;
    case 2:
        mode = base + 2;
        if ((flags & 0x80) != 0) {
            *(s16 *)((u8 *)arg0 + 0x36) = -1;
        }
        break;
    }

    obj = *(void **)((u8 *)arg0 + 0x30);
    pp = fn_8006EDD8(*(void **)(obj + 0x30), 0);
    entry = *pp;
    w = *(u16 *)((u8 *)entry + 2);
    h = *(u16 *)((u8 *)entry + 0);
    obj = *(void **)((u8 *)arg0 + 0x30);
    if ((*(u16 *)(obj + 0x46) & 1) != 0) {
        x = (s16)(w - x);
    }
    x = (s16)((f32)x + (*(f32 *)(obj + 0x38) - (f32)(w >> 1)));
    y = (s16)((f32)y + (*(f32 *)(obj + 0x3C) - (f32)h));
    pp = fn_8006EDD8(*(void **)(obj + 0x30), mode);
    entry = *pp;
    w2 = *(u16 *)((u8 *)entry + 2);
    h2 = *(u16 *)((u8 *)entry + 0);
    if ((*(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x46) & 1) != 0) {
        x -= w2;
    }
    Prim2D_Begin();
    obj = *(void **)((u8 *)arg0 + 0x30);
    tint = *(u8 *)((u8 *)*(void **)(obj + 0x34) + 0x1D);
    alpha = *(f32 *)(obj + 0x4C);
    Prim2D_SetTransform(lbl_803693D4, lbl_803693D4, lbl_80366E00 + ((f32)(u32)tint / lbl_803693EC), alpha);
    obj = *(void **)((u8 *)arg0 + 0x30);
    fn_80009EB0(*(void **)(obj + 0x30), mode, *(u8 *)(obj + 0x40), 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    if ((*(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x46) & 1) != 0) {
        Prim2D_SetQuadMin((f32)x, (f32)y, (f32)w2, lbl_803693D4);
        Prim2D_SetQuadMax((f32)(x + w2), (f32)(y + h2), lbl_803693D4, (f32)h2);
    } else {
        Prim2D_SetQuadMin((f32)x, (f32)y, lbl_803693D4, lbl_803693D4);
        Prim2D_SetQuadMax((f32)(x + w2), (f32)(y + h2), (f32)w2, (f32)h2);
    }
    obj = *(void **)((u8 *)arg0 + 0x30);
    tint = *(u8 *)(obj + 0x41);
    pad = *(u8 *)(obj + 0x42);
    Prim2D_SetColor(tint, tint, tint, pad);
    Prim2D_EndPrim();
    (void)stackpad[0];
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

void fn_8007ACCC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(arg0, s16 *, 0x36) = 1;
    M2C_FIELD(arg0, s16 *, 0x34) = 1;
}

void fn_8007ACE4(void *arg0) {
    void *temp_r5;

    temp_r5 = M2C_FIELD(arg0, void **, 0x50);
    if (temp_r5 != NULL) {
        M2C_FIELD(arg0, u16 *, 0x46) = (u16) (M2C_FIELD(arg0, u16 *, 0x46) & 0xFFFFFF1F);
        M2C_FIELD(temp_r5, s16 *, 0x36) = 1;
    }
}

void fn_8007AD08(void *arg0, s16 arg1, s16 arg2) {
    void *temp_r3;

    temp_r3 = M2C_FIELD(arg0, void **, 0x54);
    if (temp_r3 != NULL) {
        if (arg1 > 0) {
            M2C_FIELD(temp_r3, s16 *, 0x34) = arg1;
        }
        if (arg2 > 0) {
            M2C_FIELD(temp_r3, s16 *, 0x36) = arg2;
        }
    }
}

void fn_8007AD30(void *arg0, s32 arg1) {
    void *temp_r5;

    temp_r5 = M2C_FIELD(arg0, void **, 0x50);
    if (temp_r5 != NULL) {
        M2C_FIELD(arg0, u16 *, 0x46) = (u16) (M2C_FIELD(arg0, u16 *, 0x46) & 0xFFFFFF1F);
        if ((s16) M2C_FIELD(temp_r5, s16 *, 0x36) != -1) {
            M2C_FIELD(temp_r5, s16 *, 0x36) = 1;
        }
        M2C_FIELD(arg0, u16 *, 0x46) = (u16) (M2C_FIELD(arg0, u16 *, 0x46) | arg1);
    }
}

void fn_8007AD6C(void *arg0) {
    extern void *gFaceSlots[];
    void Process_Unlink(void *);

    if (arg0 != NULL) {
        s32 index = *(u8 *)((u8 *)arg0 + 0x40);
        if (gFaceSlots[index] != NULL) {
            Process_Unlink(gFaceSlots[index]);
        }
        gFaceSlots[index] = NULL;
    }
}

void fn_8007ADC8(s32 index) {
    extern void *gFaceSlots[];
    void Process_Unlink(void *);
    void **base;
    void *p;

    base = gFaceSlots;
    p = base[index];
    if (p == NULL) {
        return;
    }
    Process_Unlink(p);
    base[index] = NULL;
}

void fn_8007AE18(void *arg0)
{
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern void *gFaceSlots[];
    void *entry;
    s32 idx;

    entry = gFaceSlots[*(s32 *)((u8 *)arg0 + 0x30)];
    *((s8 *)((u8 *)entry + 0x41)) = (s8)Math_Ease(
        *(s32 *)((u8 *)arg0 + 0x44),
        (f32)*(s32 *)((u8 *)arg0 + 0x3c),
        (f32)*(s32 *)((u8 *)arg0 + 0x40),
        (f32)*(s32 *)((u8 *)arg0 + 0x34),
        (f32)*(s32 *)((u8 *)arg0 + 0x38));
    idx = *(s32 *)((u8 *)arg0 + 0x34);
    if (idx == *(s32 *)((u8 *)arg0 + 0x38)) {
        Process_ClearFunc(arg0);
    } else {
        *(s32 *)((u8 *)arg0 + 0x34) = idx + 1;
    }
}

void fn_8007AF00(void *arg0) {
    extern void *gFaceSlots[];
    s32 idx = *(s32 *)((u8 *)arg0 + 0x30);
    u8 *entry = (u8 *)gFaceSlots[idx];
    *(s32 *)((u8 *)arg0 + 0x34) = 0;
    *(s32 *)((u8 *)arg0 + 0x3C) = entry[0x41];
    if (*(s32 *)((u8 *)arg0 + 0x3C) < *(s32 *)((u8 *)arg0 + 0x40)) {
        *(s32 *)((u8 *)arg0 + 0x44) = 0;
        return;
    }
    *(s32 *)((u8 *)arg0 + 0x44) = 4;
}

void fn_8007AF48(void *arg0)
{
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern void *gFaceSlots[];
    extern f32 lbl_803693D4;
    f32 scale;
    void *entry;
    s32 v64;
    s32 v68;

    scale = lbl_803693D4;
    entry = gFaceSlots[*(s32 *)((u8 *)arg0 + 0x60)];
    *((s8 *)((u8 *)entry + 0x42)) = (s8)Math_Ease(
        0,
        (f32)*(s32 *)((u8 *)arg0 + 0x6C),
        scale,
        (f32)*(s32 *)((u8 *)arg0 + 0x68),
        (f32)*(s32 *)((u8 *)arg0 + 0x64));
    v64 = *(s32 *)((u8 *)arg0 + 0x64);
    if (v64 == *(s32 *)((u8 *)arg0 + 0x68)) {
        Process_ClearFunc(arg0);
    } else {
        *(s32 *)((u8 *)arg0 + 0x68) = *(s32 *)((u8 *)arg0 + 0x68) + 1;
    }
}

void fn_8007B01C(void *arg0) {
    extern void *gFaceSlots[];
    void *ptr = gFaceSlots[*(s32 *)((char *)arg0 + 0x60)];
    *(s32 *)((char *)arg0 + 0x68) = 0;
    *(s32 *)((char *)arg0 + 0x6c) = *(u8 *)((char *)ptr + 0x42);
}

void fn_8007B044(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern void *gFaceSlots[];
    extern f64 lbl_803693C8;
    extern f32 lbl_803693D4;
    extern f32 lbl_803693EC;
    void *entry;
    s32 idx;
    f32 fa;
    f32 fb;

    fa = lbl_803693D4;
    fb = lbl_803693EC;
    entry = gFaceSlots[*(s32 *)((u8 *)arg0 + 0x60)];
    *((s8 *)((u8 *)entry + 0x42)) = (s8)Math_Ease(
        0, fa, fb,
        (f32)*(s32 *)((u8 *)arg0 + 0x68),
        (f32)*(s32 *)((u8 *)arg0 + 0x64));
    idx = *(s32 *)((u8 *)arg0 + 0x64);
    if (idx == *(s32 *)((u8 *)arg0 + 0x68)) {
        Process_ClearFunc(arg0);
    } else {
        idx = *(s32 *)((u8 *)arg0 + 0x68);
        *(s32 *)((u8 *)arg0 + 0x68) = idx + 1;
    }
}

void fn_8007B104(void *arg0) {
    extern void *gFaceSlots[];
    void *ptr = gFaceSlots[*(s32 *)((char *)arg0 + 0x60)];
    *(s32 *)((char *)arg0 + 0x68) = 0;
    *(u8 *)((char *)ptr + 0x42) = 0;
}

void fn_8007B128(void *arg0) {
    f32 Math_Ease(M2C_UNK, f32, f32, f32, f32);
    M2C_UNK Process_ClearFunc(void *);
    s32 temp_r3;

    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), f32 *, 0x38) = Math_Ease(5, M2C_FIELD(arg0, f32 *, 0x30), M2C_FIELD(arg0, f32 *, 0x34), (f32) M2C_FIELD(arg0, s32 *, 0x3C), (f32) M2C_FIELD(arg0, s32 *, 0x38));
    temp_r3 = M2C_FIELD(arg0, s32 *, 0x3C);
    if (temp_r3 == (s32) M2C_FIELD(arg0, s32 *, 0x38)) {
        Process_ClearFunc(arg0);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (temp_r3 + 1);
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8007B1C4(void *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    void **fn_8006EDD8(void *, s32);
    void Prim2D_Begin(void);
    void fn_80009EB0(void *, s32, u8, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, u8);
    void Prim2D_EndPrim(void);
    extern f32 lbl_803693D4;
    u8 tint;
    s16 x;
    s16 y;
    s32 mode;
    u8 pad;
    void *obj;
    void *info;
    void **pp;
    void *entry;
    s32 w;
    s32 h;
    s32 w2;
    s32 h2;
    f32 scale;

    x = 0;
    y = 0;
    mode = arg4;
    obj = arg0;
    pad = arg3;
    tint = *(u8 *)((u8 *)arg0 + 0x41);
    if ((u32)(mode - 7) > 1U) {
        if (mode == 9) {
            info = *(void **)((u8 *)obj + 0x34);
            if (*(u16 *)((u8 *)info + 0xC) == *(u16 *)((u8 *)info + 0x10)) {
                return;
            }
        }
    }
    if (mode == 7) {
        info = *(void **)((u8 *)obj + 0x34);
        x = *(u16 *)((u8 *)info + 0xC);
        y = *(u16 *)((u8 *)info + 0xE);
    } else {
        info = *(void **)((u8 *)obj + 0x34);
        x = *(u16 *)((u8 *)info + 0x10);
        y = *(u16 *)((u8 *)info + 0x12);
    }
    if (x != -1) {
        info = *(void **)((u8 *)obj + 0x34);
        if ((*(u16 *)((u8 *)info + 0x18) & 2) == 0) {
            mode -= 6;
        }
        pp = fn_8006EDD8(*(void **)((u8 *)obj + 0x30), 0);
        entry = *pp;
        w = *(u16 *)((u8 *)entry + 2);
        h = *(u16 *)((u8 *)entry + 0);
        if ((*(u16 *)((u8 *)obj + 0x46) & 1) != 0) {
            x = w - x;
        }
        x += arg1 - (w >> 1);
        y += arg2 - h;
        pp = fn_8006EDD8(*(void **)((u8 *)obj + 0x30), mode);
        entry = *pp;
        w2 = *(u16 *)((u8 *)entry + 2);
        h2 = *(u16 *)((u8 *)entry + 0);
        if ((*(u16 *)((u8 *)obj + 0x46) & 1) != 0) {
            x -= w2;
        }
        Prim2D_Begin();
        fn_80009EB0(*(void **)((u8 *)obj + 0x30), mode, *(u8 *)((u8 *)obj + 0x40), 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        if ((*(u16 *)((u8 *)obj + 0x46) & 1) != 0) {
            scale = *(f32 *)((u8 *)obj + 0x4C);
            Prim2D_SetQuadMin((f32)x, (f32)y, (f32)w2, lbl_803693D4);
            Prim2D_SetQuadMax((f32)w2 * scale + (f32)x, (f32)h2 * scale + (f32)y, lbl_803693D4,
                        (f32)h2, scale);
        } else {
            scale = *(f32 *)((u8 *)obj + 0x4C);
            Prim2D_SetQuadMin((f32)x, (f32)y, lbl_803693D4, lbl_803693D4);
            Prim2D_SetQuadMax((f32)w2 * scale + (f32)x, (f32)h2 * scale + (f32)y, (f32)w2, (f32)h2,
                        scale);
        }
        Prim2D_SetColor(tint, tint, tint, pad);
        Prim2D_EndPrim();
    }
}

void fn_8007B4D8(s32 arg0,s32 arg1,u32 a2,void *a3) {
#pragma opt_common_subs off
#pragma dont_inline off
 void **fn_8006EDD8(void *,s32);
 void Prim2D_Begin(void);
 void fn_80009EB0(void *,s32,u8,s32);
 void Prim2D_PrepareTex(void);
 void Prim2D_AddPrim(s32);
 void Prim2D_SetQuadMin(f32,f32,f32,f32);
 void Prim2D_SetQuadMax(f32,f32,f32,f32);
 void Prim2D_SetColor(u8,u8,u8,u8);
 void Prim2D_EndPrim(void);
 void fn_8007B1C4(void *,s32,s32,u32,s32);
 extern f32 lbl_803693D4;
 u16 *dim;
 void *meta;
 u8 shade;
 s32 x,y,xx,yy;
 s32 height,width,hh,ww;
 void *arg3;
 u32 arg2;
 s32 mode;
 u16 flags;
  arg2=a2;arg3=a3;
 shade=M2C_FIELD(arg3,u8 *,0x41);
 dim=*fn_8006EDD8(M2C_FIELD(arg3,void * *,0x30),0);
 width=dim[1];height=dim[0];
 x=arg0-(width>>1);y=arg1-height;
 Prim2D_Begin();fn_80009EB0(M2C_FIELD(arg3,void * *,0x30),0,M2C_FIELD(arg3,u8 *,0x40),0x11);Prim2D_PrepareTex();
 Prim2D_AddPrim(1);
 if(M2C_FIELD(arg3,u16 *,0x46)&1) {
 f32 scale;
 Prim2D_SetQuadMin((f32)x,(f32)y,(f32)width,lbl_803693D4);
 scale=M2C_FIELD(arg3,f32 *,0x4C);
 Prim2D_SetQuadMax((f32)width*scale+(f32)x,(f32)height*scale+(f32)y,lbl_803693D4,(f32)height);
 } else {
 f32 scale;
 Prim2D_SetQuadMin((f32)x,(f32)y,lbl_803693D4,lbl_803693D4);
 scale=M2C_FIELD(arg3,f32 *,0x4C);
 Prim2D_SetQuadMax((f32)width*scale+(f32)x,(f32)height*scale+(f32)y,(f32)width,(f32)height);
 }
 Prim2D_SetColor(shade,shade,shade,arg2);Prim2D_EndPrim();
 meta=M2C_FIELD(arg3,void * *,0x34);
 if(M2C_FIELD(meta,u16 *,0x18)&2) {
 flags=M2C_FIELD(arg3,u16 *,0x46);
 mode=get_B4D8_mode(flags);
 xx=M2C_FIELD(meta,u16 *,0x14);yy=M2C_FIELD(meta,u16 *,0x16);
 if(flags&1)xx=width-xx;
 xx+=x; yy+=y;
 dim=*fn_8006EDD8(M2C_FIELD(arg3,void * *,0x30),mode);
 ww=dim[1];hh=dim[0];
 if(M2C_FIELD(arg3,u16 *,0x46)&1)xx-=ww;
 Prim2D_Begin();fn_80009EB0(M2C_FIELD(arg3,void * *,0x30),mode,M2C_FIELD(arg3,u8 *,0x40),0x11);Prim2D_PrepareTex();
 Prim2D_AddPrim(1);
 if(M2C_FIELD(arg3,u16 *,0x46)&1) {
 f32 scale;
 Prim2D_SetQuadMin((f32)xx,(f32)yy,(f32)ww,lbl_803693D4);
 scale=M2C_FIELD(arg3,f32 *,0x4C);
 Prim2D_SetQuadMax((f32)ww*scale+(f32)xx,(f32)hh*scale+(f32)yy,lbl_803693D4,(f32)hh);
 } else {
 f32 scale;
 Prim2D_SetQuadMin((f32)xx,(f32)yy,lbl_803693D4,lbl_803693D4);
 scale=M2C_FIELD(arg3,f32 *,0x4C);
 Prim2D_SetQuadMax((f32)ww*scale+(f32)xx,(f32)hh*scale+(f32)yy,(f32)ww,(f32)hh);
 }
 Prim2D_SetColor(shade,shade,shade,arg2);Prim2D_EndPrim();
 }
 if(M2C_FIELD(M2C_FIELD(arg3,void * *,0x34),u16 *,0x18)&1) {
 fn_8007B1C4(arg3,arg0,arg1,arg2,7);
 fn_8007B1C4(arg3,arg0,arg1,arg2,10);
 }
}

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma opt_common_subs reset
#pragma global_optimizer reset
void fn_8007B990(void *arg0) {
    extern void *gFaceSlots[];
    void Process_Unlink(void *);

    if (arg0 != NULL) {
        s32 index = *(u8 *)((u8 *)arg0 + 0x40);
        if (gFaceSlots[index] != NULL) {
            Process_Unlink(gFaceSlots[index]);
        }
        gFaceSlots[index] = NULL;
    }
}

void fn_8007B9EC(void *arg0) {
    extern void *gFaceSlots[];
    void Process_Unlink(void *);
    void *obj = *(void **)((u8 *)arg0 + 0x54);
    if (obj != NULL) {
        s32 index = *(u8 *)((u8 *)obj + 0x40);
        if (gFaceSlots[index] != NULL) {
            Process_Unlink(gFaceSlots[index]);
        }
        gFaceSlots[index] = NULL;
    }
}

s32 fn_8007BA4C(s32 arg0) {
    s32 sp30;
    s32 *var_r29;
    u32 r28;
    s32 r31;

    sp30 = 0x0;
    if (arg0 == 0x0) {
        r31 = 0x15;
    } else if (arg0 == 0x1) {
        r31 = 0xE;
    } else if (arg0 == 0x2) {
        r31 = 0xD;
    } else if (arg0 == 0x3) {
        r31 = 0xB;
    } else if (arg0 == 0x4) {
        r31 = 0xC;
    } else {
        r31 = 0x8;
    }
    
    var_r29 = &sp30;
    r28 = r31 * 0x8;
    if (r31 < 0x20) {
        while (1) {
            *(var_r29 + r28) = 0x0;
            r28 -= 0x1;
            if ((s32)(r28 + 0x1) <= 0x0) break;
        }
    }
    
    return sp30;
}

void fn_8007BC3C(s32 a, s32 b, s32 c, s32 d, s32 e)
{
    void fn_8007BD30(s8, s32, s32, s32, s32, s32, s32);
    extern void *gFaceSlots[];
    void **p;
    void **q;
    s32 n;

    p = gFaceSlots;
    if (*p == NULL) {
        n = 0;
    } else {
        q = p + 1;
        if (p[1] == NULL) {
            n = 1;
        } else if (*++q == NULL) {
            n = 2;
        } else if (*++q == NULL) {
            n = 3;
        } else if (*++q == NULL) {
            n = 4;
        } else if (*++q == NULL) {
            n = 5;
        } else if (*++q == NULL) {
            n = 6;
        } else if (q[1] == NULL) {
            n = 7;
        } else {
            n = -1;
        }
    }
    fn_8007BD30((s8)n, a, b, c, d, 0, e);
}

void fn_8007C018(void *arg0) {
    M2C_UNK fn_80200270(s32);
    if ((u32) M2C_FIELD(arg0, u32 *, 0x30) != 0U) {
        fn_80200270(*M2C_FIELD(arg0, s32 **, 0x34));
    }
}

void fn_8007C318(s32 unused, u32 arg1) {
    void GXSetScissor(u32, s32, u32, s32);
    GXSetScissor(arg1 >> 16, 0, arg1 & 0xFFFF, 0x1E0);
}

void fn_8007C34C(void) {
    extern u32 gFaceSlots[];
    u32 *p;

    p = gFaceSlots;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
}

#pragma peephole off
void fn_8007C378(void) {
    void *Res_GetByName();
    void Msg_Expand(u32);
    extern u8 lbl_8026C640[];
    void *x;

    x = Res_GetByName();
    switch ((u32)x) {
    case 0:
        Msg_Expand(*(u32 *)((u8 *)Res_GetByName(lbl_8026C640 + 0xEF) + 4));
        break;
    }
}
#pragma peephole reset
void fn_8007C3BC(void) {
    extern u8 lbl_8026C640[];
    unsigned int Res_GetByName();

    switch ((unsigned int)Res_GetByName()) {
    case 0U:
        Res_GetByName(lbl_8026C640 + 0xEF);
        break;
    }
}

s32 fn_8007C3F8(void) {
    extern s32 lbl_80367478;
    return lbl_80367478;
}

s32 fn_8007C400(void) {
    extern s32 lbl_8036747C;
    return lbl_8036747C;
}

void fn_8007C408(void)
{
    extern u8 lbl_8026C640[];
    extern s32 lbl_8036747C;
    extern u8 *lbl_80367478;

    extern void *fn_8003FCCC(void *);
    extern void fn_8000D3EC(void *, void *);

    long offset;
    u32 *data;
    s32 i;
    register u8 *entry;

    data = (u32 *)fn_8003FCCC(lbl_8026C640 + 0x110);

    lbl_8036747C = data[0];
    lbl_80367478 = (u8 *)data[1];

    i = 0;
    offset = 0;

    while (lbl_8036747C > i) {
        entry = lbl_80367478 + offset;

        fn_8000D3EC(*(void **)entry, entry);

        offset += (u32)0x20;
        i += 1;
    }
}

void fn_8007C484(void *arg0) {
    void strcpy(void *, void *);
    void strcat(void *, s32);
    void FileCache_IsReady(void *);
    extern u16 lbl_8026C640[];
    char sp8[0x40];

    strcpy(sp8, (u8 *)lbl_8026C640 + 0x122);
    strcat(sp8, *(s32 *)((char *)arg0 + 8));
    FileCache_IsReady(sp8);
}

void fn_8007C4D4(void *arg0, s32 arg1) {
    void strcpy(void *, void *, void *);
    void strcat(void *, s32);
    void fn_8005C870(void *, s32);
    extern u16 lbl_8026C640[];
    char sp8[0x40];

    strcpy(sp8, (u8 *)lbl_8026C640 + 0x122, lbl_8026C640);
    strcat(sp8, *(s32 *)((char *)arg0 + 8));
    fn_8005C870(sp8, arg1);
}

#include "common.h"
#include "structs.h"

extern u16 gUiContext[12];
extern s32 lbl_802EF4E0[];
extern void *Item_GetFlagsPtr(void);
extern void *fn_800285C0(void *);
extern u16 lbl_8026C0B8[];
#include "global.h"
extern u8 D_802EF4C8[24];
extern u16 lbl_80288CAC;
#include "global.h"
extern void* (*fn_80024398_ptr)(void*, s32, s32);

extern u16 lbl_80288CAC;
#include "common.h"
#include "structs.h"
extern u16 gFaceSlots[8];
#include <common.h>

extern u16 gUiContext[12];
extern s32 lbl_802EF4E0[502];
#include "global.h"
