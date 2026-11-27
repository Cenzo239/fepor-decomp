/* Functions from 0x80074370 to 0x8007C534, found by decomp-toolkit. */
#include "common.h"
#include "structs.h"
#pragma cplusplus on
struct PopupDrawObj {
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
#pragma cplusplus reset

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
extern u8 gMapUiResult;
s32 Ui_CreateMenu();
void Face_DrawEyes(void *arg0, s32 arg1, s32 arg2);

void fn_80074370(void *arg0) {
    extern s32 lbl_80367468;
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) lbl_80367468;
}

extern u8 gUnitInfoPopup[];
s32 fn_8007437C(void) {
    u8 Ui_IsUnitInfoPopupOpen(void *);

    return Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) ? 0x40 : 0x10;
}

#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" void fn_800743B4(void *arg0, void *arg1) {
    s32 Prim2D_SetColorByte(s32);
    s32 Prim2D_AddZ(f32);
    s32 Prim2D_PrepareTex();
    s32 Prim2D_Begin();
    s32 Text_MeasureHeight(s32, f32);
    f32 UiWin_GetFade(void *);
    s32 fn_8007149C(void *, void *, f32, f32, void *, s32);
    s32 fn_80071740(void *, f32, f32, void *);
    s32 fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    s32 fn_8008BBF8(s32, s32, s32, s32, u8, s32);
    s32 fn_8008CD64(f32);
    s32 Ui_DrawCenteredMsgLines(s32, s32, void *, void *, void *);
    u8 fn_8014D8DC(void *);
    extern u8 lbl_8026C0B8[];
    extern u8 gBattleState[];
    extern f32 lbl_80369378;
    extern f32 lbl_8036937C;
    extern f32 lbl_80369380;
    extern f32 lbl_80369384;
    extern f32 lbl_80369388;
    extern f32 lbl_8036938C;
    extern f32 lbl_80369390;
    extern f32 lbl_80369394;
    extern f32 lbl_80369398;
    extern f32 lbl_8036939C;
    s32 var_r28;
    f32 temp_f2;
    f32 temp_f31;
    f32 temp_f31_2;
    s16 temp_r31;
    s16 temp_r3_2;
    s32 temp_r29;
    s32 temp_r30;
    s32 temp_r3;

    temp_f31 = UiWin_GetFade(arg1);
    M2C_FIELD(arg1, s16 *, 0x30) = 0;
    M2C_FIELD(arg1, s16 *, 0x32) = 0;
    Prim2D_Begin();
    Prim2D_SetColorByte((s32) (lbl_80369378 * temp_f31));
    Prim2D_PrepareTex();
    temp_f31_2 = (lbl_8036937C * temp_f31) + lbl_8036937C;
    fn_80071740(arg0, temp_f31_2, lbl_80369380, M2C_FIELD(arg0, void **, 0xC));
    fn_8007149C(arg0, arg1, temp_f31_2, lbl_80369384, M2C_FIELD(arg0, void **, 0xC), 3);
    fn_8008CD64(lbl_80369388);
    fn_8008BBF8((s32) temp_f31_2, 0x88, 0, 0xA6, M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0x190), u8 *, 8), 0x9A);
    fn_8008CD64(lbl_8036938C);
    if ((s16) M2C_FIELD(arg1, s16 *, 0x3A) >= 5) {
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369390);
        Prim2D_PrepareTex();
        var_r28 = 0;
        if (((u8) M2C_FIELD(arg1, u8 *, 0x2D) == 0) && ((u8) M2C_FIELD(arg1, u8 *, 0x2E) == 0)) {
            var_r28 = 1;
        }
        fn_8008AB7C(((PopupDrawObj *)arg0)->v18() / 2 + 0x28,
            M2C_FIELD(arg1, s16 *, 0x3A) + Text_MeasureHeight(-1, lbl_80369394) / 2,
            (s32)(lbl_80369398 * ((PopupDrawObj *)arg0)->v18()), 0x18, 0x19, 0x4B, var_r28);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036939C);
        Prim2D_PrepareTex();
    }
    if (fn_8014D8DC(gBattleState) != 0) {
        Ui_DrawCenteredMsgLines(0x138, 0xA0, lbl_8026C0B8 + 0xCE, lbl_8026C0B8 + 0xD4, lbl_8026C0B8 + 0xDA);
        return;
    }
    Ui_DrawCenteredMsgLines(0x138, 0xA0, lbl_8026C0B8 + 0xE0, lbl_8026C0B8 + 0xE6, lbl_8026C0B8 + 0xEC);
}

#pragma cplusplus reset
#pragma use_lmw_stmw reset
u32 fn_800745E8(void *arg0, void *arg1, u8 arg2) {
    u64 *Item_GetFlagsPtr(void *);
    void *Unit_GetItemSlot(void *, s32);
    u8 fn_8014D8DC(void *);
    extern u64 lbl_8036746C;
    extern void *lbl_80367468;
    extern u8 gBattleState[];
    s32 index=arg2;
    void *item;
    if(index==4) item=&lbl_8036746C;
    else {
        u64 *fp=Item_GetFlagsPtr(&lbl_8036746C);
        s32 offset=((*fp & 5) != 0) ? 0 : 4;
        item=Unit_GetItemSlot(lbl_80367468,offset+index);
    }
    if(*Item_GetFlagsPtr(item)&0x200ULL) return 2;
    if(!fn_8014D8DC(gBattleState)) {
        if(index==4) item=&lbl_8036746C;
        else {
            u64 *fp=Item_GetFlagsPtr(&lbl_8036746C);
            s32 offset=((*fp & 5) != 0) ? 0 : 4;
            item=Unit_GetItemSlot(lbl_80367468,offset+index);
        }
        if(*Item_GetFlagsPtr(item)&0x20000000000ULL) return 2;
    }
    if(arg2==4) return 1;
    else return 0;
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
s32 addend;
u64 val;
u64 *new_var2;
s32 index;

((Obj *)arg0)->v17();
index = ((u8 *)arg2)[0x3A];
if (index == 4) {
    result = &lbl_8036746C;
} else {
    new_var2 = Item_GetFlagsPtr(&lbl_8036746C);
    val = *new_var2;
    addend = ((val & 5ULL) != 0ULL) ? 0 : 4;
    result = Unit_GetItemSlot(lbl_80367468, addend + index);
}
UnitRef_Draw(result, ((u8 *)arg2)[0x39] == 0, *(s16 *)((u8 *)arg2 + 0x30), *(s16 *)((u8 *)arg2 + 0x32));
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
    s32 UnitRef_GetName(void *);
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
    s32 offset;

    index = *(s8 *)(gUiContext + 0xA);
    if (index == 4) {
        result = &lbl_8036746C;
    } else {
        u64 *fp = Item_GetFlagsPtr(&lbl_8036746C);
        offset = ((*fp & 5) != 0) ? 0 : 4;
        result = Unit_GetItemSlot(lbl_80367468, offset + index);
    }
    obj = *(void **)result;
    if (obj) {
        index = *((u8 *)obj + 0x15);
    } else {
        index = 0;
    }
    sprintf(lbl_80312010, lbl_8026C0B8 + 0x122, (u8)index + 0x60, UnitRef_GetName(result));
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
    extern struct { s32 n; u8 pad[2004]; } gTargetList;

    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x18) == 0) {
        return 3;
    }
    fn_80029C08(*(u8 **)gUiContext);
    return gTargetList.n ? 0 : 2;
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

#pragma optimization_level 3
extern "C" s32 fn_80074B78(s32 arg0, s32 arg1, void *arg2) {
    extern u8 gUiContext[];
    volatile u8 *p;
    if (*((u8 *)arg2 + 0x39) != 0) {
        return 0x10;
    }
    p = gUiContext;
    p[0xA] = *((u8 *)arg2 + 0x3A);
    return 5;
}
#pragma optimization_level reset
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
    extern struct { s32 n; u8 pad[2004]; } gTargetList;
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
    return gTargetList.n ? 0 : 2;
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

#pragma cplusplus on
extern "C" void fn_80074F20(void *arg0, void *arg1) {
    extern f32 lbl_80369378;
    extern f32 lbl_8036937C;
    extern f32 lbl_80369380;
    extern f32 lbl_80369384;
    extern f32 lbl_80369390;
    extern f32 lbl_80369394;
    extern f32 lbl_80369398;
    extern f32 lbl_8036939C;
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

    f32 t;
    t = UiWin_GetFade(arg1);
    *(s16 *)((u8 *)arg1 + 0x30) = 0;
    *(s16 *)((u8 *)arg1 + 0x32) = 0;
    Prim2D_Begin();
    Prim2D_SetColorByte((s32)(lbl_80369378 * t));
    Prim2D_PrepareTex();
    t = lbl_8036937C * t + lbl_8036937C;
    fn_80071740(arg0, t, lbl_80369380, *(s32 *)((u8 *)arg0 + 0xC));
    fn_8007149C(arg0, arg1, t, lbl_80369384, *(s32 *)((u8 *)arg0 + 0xC), 0);
    if (*(s16 *)((u8 *)arg1 + 0x3A) >= 5) {
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80369390);
        Prim2D_PrepareTex();
        fn_8008AB7C(((PopupDrawObj *)arg0)->v18() / 2 + 0x28,
            *(s16 *)((u8 *)arg1 + 0x3A) + Text_MeasureHeight(-1, lbl_80369394) / 2,
            (s32)(lbl_80369398 * ((PopupDrawObj *)arg0)->v18()), 0x17, 0x19, 0x4B, 1);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036939C);
        Prim2D_PrepareTex();
    }
    Ui_DrawCenteredMsgLines(0x138, 0xa0, (void *)(lbl_8026C0B8 + 0x1a1), (void *)(lbl_8026C0B8 + 0x1a7), (void *)(lbl_8026C0B8 + 0x1ad));
}

#pragma cplusplus reset
void fn_800750D8(s32 arg0, void *arg1) {
    extern s32 gUiContext[];
    
    Unit_GetItemSlot(gUiContext[1], *(u8*)((char*)arg1 + 0x3A));
}

s32 fn_80075108(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 gUiContext[24];
    s32 *Unit_GetItemSlot(s32, u8);
    u8 Unit_CanReceiveItem(s32, s32 *);
    s32 *temp;

    temp = Unit_GetItemSlot(*(s32 *)(gUiContext + 4), (u8)arg2);
    if ((u32)*temp == 0U) {
        return 3;
    }
    return (Unit_CanReceiveItem(*(s32 *)gUiContext, temp) == 0) ? 2 : 0;
}

#pragma use_lmw_stmw on

s32 fn_80075178(void *arg0, void *arg1, void *arg2) {
    s32 Msg_Expand(void *);
    s32 Unit_GetItemSlot(s32, u8);
    u8 Unit_CheckReceiveItem(s32, s32, void *);
    void fn_80166AE8(s32, s32, s32, void *);
    extern u8 lbl_8026C0B8[];
    extern u8 gUiContext[];
    struct Vtbl { u8 pad[0x5C]; s16 (*getx)(void *); };
    typedef struct Obj { u8 pad[4]; struct Vtbl *vtbl; } Obj;
    void *self;
    s32 str;
    s16 y;
    s16 x;
    u8 *entry;
    Obj *obj;
    void *msg;
    s32 vx;
    s32 slot;
    self = arg1;
    entry = (u8 *)arg2;
    if (*(entry + 0x39)) {
        slot = Unit_GetItemSlot(*(s32 *)(gUiContext + 4), *(entry + 0x3A));
        msg = 0;
        switch (Unit_CheckReceiveItem(*(s32 *)gUiContext, slot, gUiContext)) {
        case 1: msg = lbl_8026C0B8 + 0x1B3; break;
        case 2: msg = lbl_8026C0B8 + 0x1BA; break;
        case 3: msg = lbl_8026C0B8 + 0x1C1; break;
        }
        y = *(s16 *)(entry + 0x32);
        x = *(s16 *)(entry + 0x30);
        obj = *(Obj **)((u8 *)self + 0x3C);
        str = Msg_Expand(msg);
        vx = obj->vtbl->getx(obj);
        fn_80166AE8(vx + x, y, str, self);
        return 0;
    }
    gUiContext[0xA] = *(entry + 0x3A);
    return 5;
}

#pragma use_lmw_stmw reset

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

s32 fn_80075664(void *arg0, void *arg1) {
    void Process_CreateChild(void *, void *);
    u64 *Item_GetFlagsPtr(void *);
    void Ui_RebuildListEntries(void *);
    void *fn_800241C8(void *);
    void *UiCtx_GetItemSlot(void *);
    u8 fn_80093088(void *);
    void Unit_RemoveItem(void *, u8);
    void Process_ClearFunc(void *);
    extern u8 lbl_802872B0[];
    extern u8 gUiContext[];
    u8 flag = 0;
    if ((*Item_GetFlagsPtr(UiCtx_GetItemSlot(gUiContext)) & 0x100000000ULL) &&
        (*(u32 *)(*(u8 **)gUiContext + 0x1A0) & 0x800000)) flag = 1;
    Unit_RemoveItem(*(void **)gUiContext, gUiContext[0xA]);
    if (fn_80093088(*(void **)gUiContext)) {
        gUiContext[8] = 0;
        if (flag) Process_CreateChild(lbl_802872B0, *(void **)((u8 *)fn_800241C8(arg1) + 0x18));
        return 6;
    }
    Ui_RebuildListEntries(*(void **)(*(u8 **)((u8 *)arg1 + 0x18) + 0x18));
    Process_ClearFunc(*(void **)((u8 *)arg1 + 0x18));
    if (flag) Process_CreateChild(lbl_802872B0, *(void **)((u8 *)arg1 + 0x18));
    return 5;
}

#pragma cplusplus on
extern "C" s32 fn_80075784(void *arg0, void *arg1, s32 arg2) {
    void **Unit_GetItemSlot(void *, u8);
    u8 fn_800939FC(void *, void *);
    extern u8 gUiContext[24];
    void *temp_r4;
    u8 val;

    temp_r4 = *Unit_GetItemSlot(*(void **)gUiContext, arg2);
    if (temp_r4 == NULL) {
        return 3;
    }
    val = (temp_r4 != NULL) ? *(u8 *)((char *)temp_r4 + 0x12) : 0xC;
    if (val == 7) {
        return 2;
    }
    return (fn_800939FC(*(void **)gUiContext, temp_r4) == 0) ? 2 : 0;
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
    void *UiCtx_GetItemSlot(void *);
    extern u8 gUiContext[];

    if (*Item_GetFlagsPtr(UiCtx_GetItemSlot(gUiContext)) & 0x20000000000ULL) {
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
    s32 fn_80024398(void *, void *, s32);
    s16 y;
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
        y = (s16)(y - 0x3C);
        b = obj->v21();
        fn_80166AE8(b + x, a + y, str, arg1);
        return 0;
    }
    fn_80024398(lbl_80311F80, arg1, 0);
    return 4;
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma cplusplus off

s32 fn_800759E8(void) {
    u64 *Item_GetFlagsPtr(void *);
    void *UiCtx_GetItemSlot(void *);
    void fn_8002C194(void *, u8);
    extern u8 gUiContext[];
    extern s32 gTargetList[];

    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    if (gUiContext[0x16] & 2) {
        return 3;
    }
    fn_8002C194(*(void **)gUiContext, gUiContext[0xA]);
    if (gTargetList[0] == 0) {
        return 3;
    }
    if (*Item_GetFlagsPtr(UiCtx_GetItemSlot(gUiContext)) & 0x200ULL) {
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
    extern u8 lbl_802EF4C8[];
    s32 fn_8000E0E4(void *);
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
        str = fn_8000E0E4(lbl_8026C0B8 + 0x23c);
        a = obj->v22();
        y = (s16)(y - 0x3c);
        b = obj->v21();
        fn_80166AE8(b + x, a + y, str, arg1);
        return 0;
    }
    lbl_802EF4C8[8] = 0x28;
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
    void *UiCtx_GetItemSlot(void *);
    extern u8 gUiContext[];
    void *item;

    item = UiCtx_GetItemSlot(gUiContext);
    if (!((*(u8 *)((char *)item + 5) >> 7) & 1)) {
        return 3;
    }
    if (*Item_GetFlagsPtr(item) & 0x200ULL) {
        return 2;
    }
    return 0;
}

#pragma push
#pragma opt_propagation off
s32 fn_80075C78(void *arg0, void *arg1, void *arg2) {
    s32 Msg_Expand(void *);
    void fn_80166AE8(s32, s32, s32, void *);
    void Ui_PlaySeCue(void *, s32);
    void *UiCtx_GetItemSlot(void *);
    u64 *Item_GetFlagsPtr(void *);
    void Process_CreateChild(void *, void *);
    void Ui_RebuildListEntries(void *);
    extern u8 lbl_8026C0B8[];
    extern u8 lbl_802872B0[];
    extern u8 gUiContext[];
#pragma cplusplus on
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

    u8 saved;
    s32 y;
    s16 x;
    Obj *obj;
    u8 *slot;
    u8 *parent;
    if (*((u8 *)arg2 + 0x39)) {
        obj = *(Obj **)((u8 *)arg1 + 0x3C);
        y = *(s16 *)((u8 *)arg2 + 0x32);
        x = *(s16 *)((u8 *)arg2 + 0x30);
        fn_80166AE8(
            obj->v21() + x,
            obj->v22() + (y - 0x3C),
            Msg_Expand(lbl_8026C0B8 + 0x270),
            arg1
        );
        return 0;
    }
    Ui_PlaySeCue(lbl_8026C0B8 + 0x277, 100);
    slot = (u8 *)UiCtx_GetItemSlot(gUiContext);
    { struct Slot { u8 pad[5]; u8 enabled:1; u8 other:7; };
      ((Slot *)slot)->enabled = 0;
    }
    if (*Item_GetFlagsPtr(UiCtx_GetItemSlot(gUiContext)) & 0x100000000ULL)
        Process_CreateChild(lbl_802872B0, *(void **)((u8 *)arg1 + 0x18));
    parent = *(u8 **)((u8 *)arg1 + 0x18);
    saved = parent[0x62];
    Ui_RebuildListEntries(parent);
    parent[0x62] = saved;
    return 5;
#pragma cplusplus reset
}
#pragma pop
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
    void *UiCtx_GetItemSlot(void *);
    u8 Unit_CanUseItem(void *, void *);
    extern void *gUiContext[];
    void *item;
    void *temp_r31;
    void *temp_r30;

    item = UiCtx_GetItemSlot(gUiContext);
    temp_r31 = *(void **)item;
    temp_r30 = gUiContext[0];
    if ((*(u8 *)((char *)item + 5) >> 7) & 1) {
        return 3;
    }
    if (*Item_GetFlagsPtr(item) & 4ULL) {
        return 3;
    }
    return Unit_CanUseItem(temp_r30, temp_r31) ? 0 : 3;
}

s32 fn_80075EB4(void *arg0, void *arg1, void *arg2) {
    void Process_CreateChild(void *, void *);
    u64 *Item_GetFlagsPtr(void *);
    void Ui_RebuildListEntries(void *);
    void *UiCtx_GetItemSlot(void *);
    s8 Unit_GetActiveItemSlot(void *);
    void fn_80094CDC(void *, s32);
    void Ui_PlaySeCue(void *, s32);
    extern u8 lbl_8026C0B8[];
    extern u8 lbl_802872B0[];
    extern u8 gUiContext[];
    u8 saved;
    u8 *parent;
    if (*((u8 *)arg2 + 0x39)) return 0x10;
    Ui_PlaySeCue(lbl_8026C0B8 + 0x29E, 100);
    fn_80094CDC(*(void **)gUiContext, *(s8 *)(gUiContext + 0xA));
    if (*(s8 *)(gUiContext + 0xA) < 4) {
        parent = *(u8 **)((u8 *)arg1 + 0x18);
        parent[0x62] = Unit_GetActiveItemSlot(*(void **)gUiContext);
    }
    if ((*(u32 *)(*(u8 **)gUiContext + 0x1A0) & 0x800000) ||
        (*Item_GetFlagsPtr(UiCtx_GetItemSlot(gUiContext)) & 0x100000000ULL)) {
        Process_CreateChild(lbl_802872B0, *(void **)((u8 *)arg1 + 0x18));
    }
    parent = *(u8 **)((u8 *)arg1 + 0x18);
    saved = parent[0x62];
    Ui_RebuildListEntries(parent);
    parent[0x62] = saved;
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
    void *UiCtx_GetItemSlot(void *);
    u8 Item_TryCallUfx(void *, void *);
    u8 fn_80093218(void *, void *);
    extern void *gUiContext[];
    void *item;
    void *temp_r31;
    void *temp_r30;
    u8 var_r0;

    item = UiCtx_GetItemSlot(gUiContext);
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
    if (Item_TryCallUfx(temp_r31, temp_r30) != 0) {
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

#pragma cplusplus on
#pragma optimization_level 3
extern "C" s32 fn_80076148(s32 arg0, s32 arg1, void *arg2) {
    extern u8 gUiContext[];
    volatile u8 *p;
    if (*((u8 *)arg2 + 0x39) == 2) {
        return 0x10;
    }
    p = gUiContext;
    p[0xA] = *((u8 *)arg2 + 0x3A);
    return 5;
}
#pragma optimization_level reset
#pragma cplusplus reset
#pragma cplusplus on
extern "C" void Prim2D_SetColorByte(s32);
extern "C" void Prim2D_AddZ(f32);
extern "C" void Prim2D_PrepareTex(void);
extern "C" void Prim2D_Begin(void);
extern "C" s32 Text_MeasureHeight(s32, f32);
extern "C" f32 UiWin_GetFade(void *);
extern "C" void Ui_DrawWeaponTriangle(void *, void *, f32, f32);
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
    Ui_DrawWeaponTriangle(win, gBattle, 500.0f, 212.0f);
}
#pragma cplusplus off
#pragma global_optimizer off
s32 fn_8007633C(void) {
    void MapObjEvent_Find(void *, u8, u8, s32);
    extern void *gUiContext[];
    extern u8 gMapObjEventList[];
    void *ptr;
    u8 a;
    u8 b;

    ptr = gUiContext[0];
    a = *((u8 *)ptr + 0x19F);
    b = *((u8 *)ptr + 0x19E);
    MapObjEvent_Find(gMapObjEventList, b, a, 7);
    return 0;
}
#pragma global_optimizer reset
#pragma cplusplus off
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
s32 fn_800763DC(void){void*Item_Get(u8);s32 Item_GetMaxRange(void);void Map_ClipRangeByFacing(void*,u8,u8,u8);void Map_FillAttackRange(void*,u8,u8,u8,s32);void Map_ShowMoveLimitView(void);void fn_80070EE0(void);void*MapObjEvent_Find(void*,u8,u8,s32);extern u8 gBattleMap[],gUiContext[],gMapObjEventList[];u8*p;u8 a,b,c;fn_80070EE0();p=MapObjEvent_Find(gMapObjEventList,gUiContext[13],gUiContext[14],7);a=*((u8*)Item_Get(p[4])+29);b=p[1];c=p[0];Map_FillAttackRange(gBattleMap,c,b,a,Item_GetMaxRange());Map_ClipRangeByFacing(gBattleMap,p[0],p[1],p[3]);Map_ShowMoveLimitView();return 0;}

s32 fn_80076494(void) {
    M2C_UNK Map_HideMoveLimitView();
    Map_HideMoveLimitView();
    return 0;
}

#pragma global_optimizer off
s32 fn_800764B8(s32 a0, s32 a1, u8 arg2)
{
    u32 *Unit_GetHeldItemSlot(s32, s32);
    u8 fn_8009339C(s32, u32);
    void fn_8002BEFC(s32, u32);
    void fn_8002C034(s32, u32);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } gTargetList;
    u32 *entry;

    entry = Unit_GetHeldItemSlot(*(s32 *)gUiContext, arg2);
    if (*entry == 0) {
        return 3;
    }
    if (!fn_8009339C(*(s32 *)gUiContext, *entry)) {
        return 2;
    }
    if (gUiContext[8] == 0x27) {
        fn_8002BEFC(*(s32 *)gUiContext, *entry);
    } else {
        fn_8002C034(*(s32 *)gUiContext, *entry);
    }
    if (gTargetList.n == 0) {
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

/* Show the move-limit overlay for the selected held item's attack range; no-op if menu flag +0x39 is set. */
s32 Ui_ShowHeldItemRange(s32 unused0, s32 unused1, void *menu) {
    void fn_80070EE0(void);
    void *Unit_GetHeldItemSlot(void *, u8);
    s32 Item_GetMaxRange(void);
    void Map_FillLayer(void *, s32, s32);
    void Map_SelectRangeBuffer(void *, u8);
    void Map_FillAttackRange(void *, u8, u8, u8, u8);
    void Map_ShowMoveLimitView(void);
    extern u8 gUiContext[];
    extern u8 gBattleMap[];
    u8 minRange;
    void *unit;
    s32 maxRange;

    fn_80070EE0();
    unit = menu;
    if (*(u8 *)((u8 *)unit + 0x39) != 0) {
        return 0;
    }
    {
        u8 slot = *(u8 *)((u8 *)unit + 0x3A);
        void *item;
        s32 tmp;
        unit = *(void **)gUiContext;
        item = *(void **)Unit_GetHeldItemSlot(unit, slot);
        if (item != 0) {
            tmp = ((u8 *)item)[0x1D];
        } else {
            tmp = 0;
        }
        minRange = (u8)tmp;
        if (item != 0) {
            maxRange = (u8)Item_GetMaxRange();
        } else {
            maxRange = 0;
        }
    }
    Map_FillLayer(gBattleMap, 5, -1);
    Map_FillLayer(gBattleMap, 8, 0);
    Map_SelectRangeBuffer(gBattleMap, 6);
    Map_FillAttackRange(gBattleMap, ((u8 *)unit)[0x19E], ((u8 *)unit)[0x19F], minRange, (u8)maxRange);
    Map_ShowMoveLimitView();
    return 0;
}

s32 fn_800766B0(void) {
    M2C_UNK Map_HideMoveLimitView();
    Map_HideMoveLimitView();
    return 0;
}

s32 fn_800766D4(void) {
    u8 Ui_CanConfirmUnitSelect(void *);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    extern u8 gUnitInfoPopup[];
    extern u8 gUiContext[24];

    if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
        return 0x40;
    }
    if (Ui_CanConfirmUnitSelect(gUiContext) == 0 && gUiContext[0x16] != 0) {
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
    extern s32 gTargetList[];
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
    return gTargetList[0] == 0 ? 3 : 0;
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
    extern s32 gTargetList[];

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
    return gTargetList[0] == 0 ? 3 : 0;
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
    s32 b;
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
        b = obj->v21();
        fn_80166AE8(b + x, a + y, str, arg1);
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
    extern s32 gTargetList[];
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
    return gTargetList[0] == 0 ? 3 : 0;
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
    extern s32 gTargetList[];
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
    return gTargetList[0] == 0 ? 3 : 0;
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
    extern s32 gTargetList[];

    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x18) != 0) {
        fn_80029C08(*(u8 **)gUiContext);
        if (gTargetList[0] != 0) {
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
    extern struct { s32 n; u8 pad[2004]; } gTargetList;
    u8 *p;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    if (p[0x16] & 2) {
        return 3;
    }
    fn_8002C194(*(void **)p, -1);
    return gTargetList.n ? 0 : 3;
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
    u8 BattleState_IsPhaseZero(u8 *);

    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0) == 0) {
        return 3;
    }
    if (fn_80015680(gUnitLists + 0x24) == 0) {
        return 3;
    }
    return (BattleState_IsPhaseZero(gBattleState) == 0) ? 3 : 0;
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
    u8 BattleState_IsPhaseZero(u32 *);

    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0) == 0) {
        return 3;
    }
    if (fn_80015680(gUnitLists) <= 1) {
        return 3;
    }
    return (BattleState_IsPhaseZero((u32 *)gBattleState) == 0) ? 3 : 0;
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
    extern struct { s32 n; u8 pad[2004]; } gTargetList;

    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x3C) == 0) {
        return 3;
    }
    fn_8002AE6C(*(void **)gUiContext);
    return gTargetList.n ? 0 : 3;
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

#pragma push
#pragma opt_lifetimes off
s32 fn_80077574(void *arg0) {
    void fn_8009233C(void *, void *);
    void fn_8002A784(void *, void *);
    extern u8 gUiContext[];
    extern s32 gTargetList[];
#pragma cplusplus on
    struct Flags {
        u8 bits;
        Flags() {}
        Flags(const Flags &other) : bits(other.bits) {}
    };
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
        virtual void v20() = 0;
        virtual Flags flags() = 0;
    };
    u8 bits;
    void *unit;
    Obj *obj = (Obj *)arg0;
    Flags result;
    if (*(s8 *)(gUiContext + 0x12)) return 3;
    fn_8009233C(&result, *(void **)gUiContext);
    bits = result.bits;
    if (!(bits & 0x38) && !(u8)(bits & obj->flags().bits)) return 3;
    unit = *(void **)gUiContext;
    fn_8002A784(unit, &obj->flags());
    if (gTargetList[0] == 0) return 3;
    if ((bits & 0x20) && !(u8)(bits & obj->flags().bits)) return 2;
    return 0;
#pragma cplusplus reset
}
#pragma pop
void fn_80077694(s8 *arg0) {
    *arg0 = 1;
}

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma global_optimizer off
extern "C" s32 fn_800776A0(void *arg0, void *arg1, void *arg2) {
    struct Flags {
        u8 bits;
        Flags() {}
        Flags(const Flags &o) : bits(o.bits) {}
    };
    struct Menu {
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
        virtual s32 getStr() = 0;
        virtual u8 getCmd() = 0;
        virtual Flags getFlags() = 0;
    };
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
    void fn_8009233C(u8 *, void *);
    void fn_80026770(void *, u8 *);
    s32 fn_8009226C(void *, u8 *);
    void fn_80166AE8(s32, s32, s32, void *);
    extern u8 gUiContext[];
    s16 y;
    s16 x;
    s32 idx;
    s32 val;
    void *unit;
    u8 sp10[4];
    u8 spC[4];
    void *self;
    void *proc;

    self = arg0;
    proc = arg1;
    if (*(u8 *)((u8 *)arg2 + 0x39) != 0) {
        self = *(void **)((u8 *)proc + 0x3C);
        y = *(s16 *)((u8 *)arg2 + 0x32);
        x = *(s16 *)((u8 *)arg2 + 0x30);
        fn_80166AE8(((Obj *)self)->v21() + x, ((Obj *)self)->v22() + y, ((Menu *)arg0)->getStr(), proc);
        return 0;
    }
    gUiContext[8] = ((Menu *)self)->getCmd();
    fn_8009233C(sp10, *(void **)gUiContext);
    spC[0] = sp10[0];
    fn_80026770(gUiContext, spC);
    unit = *(void **)gUiContext;
    idx = fn_8009226C(unit, (u8 *)&((Menu *)self)->getFlags());
    val = -1;
    if (idx >= 0) {
        val = idx + 4;
    }
    gUiContext[0xA] = val;
    return 5;
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma cplusplus reset

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
    extern struct { s32 n; u8 pad[2004]; } gTargetList;
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
    return gTargetList.n ? 0 : 3;
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
    extern struct { s32 n; u8 pad[2004]; } gTargetList;
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
    return gTargetList.n ? 0 : 3;
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
    u8 Item_CallUfx(s32, u32);
    u32 *Unit_GetHeldItemSlot(s32, s32);
    u8 fn_8009326C(s32, u32);
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
        goto done;
    }
    if (fn_8009326C(obj, *entry) == 0) {
        goto next;
    }
    if (Item_CallUfx(*(s32 *)p, *entry) == 0) {
        goto next;
    }
    return 0;
next:
    i += 1;
loop:
    if (i < 4) {
        goto body;
    }
done:
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
    extern struct { s32 n; u8 pad[2004]; } gTargetList;
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
    return gTargetList.n ? 0 : 3;
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
    extern struct { s32 n; u8 pad[2004]; } gTargetList;
    u8 *p;

    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    if (*(u32 *)(*(u8 **)p + 0x1A0) & 6) {
        return 3;
    }
    fn_8002B89C();
    return gTargetList.n ? 0 : 3;
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
    extern struct { s32 n; u8 pad[2004]; } gTargetList;

    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x45) == 0) {
        return 3;
    }
    if ((s8)gUiContext[0x12] != 0) {
        return 3;
    }
    fn_8002BAFC(*(void **)gUiContext, 2);
    return gTargetList.n ? 0 : 3;
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
    extern struct { s32 n; u8 pad[2004]; } gTargetList;
    u8 *p;

    if (Status_Test(*(u8 **)gUiContext + 0x1BC, 0x44) == 0) {
        return 3;
    }
    p = gUiContext;
    if ((s8)p[0x12] != 0) {
        return 3;
    }
    fn_8002BAFC(*(void **)p, 1);
    return gTargetList.n ? 0 : 3;
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

s32 Ui_CanMapObjAttack(void) {
    /* Menu check for type-7 map-obj attack: hide if no targets, grey if event flag off. */
    extern u8 gUiContext[], gMapObjEventList[], gTargetList[];
    u8 Status_Test(void *, s32);
    void *MapObjEvent_Find(void *, s32, s32, s32);
    void MapObj_BuildAttackTargetList(void *, void *);
    void *unit;
    void *event;

    if (*(s8 *)(gUiContext + 0x12)) {
        return 3;
    }
    unit = *(void **)gUiContext;
    if (!Status_Test((u8 *)unit + 0x1BC, 0x4F)) {
        return 3;
    }
    event = MapObjEvent_Find(gMapObjEventList, *(u8 *)((u8 *)unit + 0x19E), *(u8 *)((u8 *)unit + 0x19F), 7);
    if (!event) {
        return 3;
    }
    MapObj_BuildAttackTargetList(*(void **)gUiContext, event);
    if (*(s32 *)gTargetList == 0) {
        return 3;
    }
    if (*(u8 *)((u8 *)event + 5) == 0) {
        return 2;
    }
    return 0;
}

#pragma global_optimizer off
s32 fn_80078224(void *arg0, void *arg1, void *arg2) {
    s32 Msg_Expand(void *);
    void fn_80166AE8(s32, s32, s32, void *);
    void *MapObjEvent_Find(void *, u8, u8, s32);
    void *Item_GetByIid(void *);
    extern u8 lbl_8026C0B8[];
    extern void *gUiContext[];
    extern u8 gMapObjEventList[];
#pragma cplusplus on
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
    s16 y;
    s16 x;
    Obj *obj;
    u8 *event;
    void *ptr;
    u8 *item;
    u8 a;
    u8 b;
    if (*((u8 *)arg2 + 0x39)) {
        obj = *(Obj **)((u8 *)arg1 + 0x3C);
        y = *(s16 *)((u8 *)arg2 + 0x32);
        x = *(s16 *)((u8 *)arg2 + 0x30);
        fn_80166AE8(obj->v21() + x, obj->v22() + y, Msg_Expand(lbl_8026C0B8 + 0x4C6), arg1);
        return 0;
    }
#pragma cplusplus reset
    ptr = gUiContext[0];
    a = *((u8 *)ptr + 0x19F);
    b = *((u8 *)ptr + 0x19E);
    event = (u8 *)MapObjEvent_Find(gMapObjEventList, b, a, 7);
    item = (u8 *)Item_GetByIid(lbl_8026C0B8 + 0x4CF);
    if (event[4] == *(u16 *)(item + 0xE))
        *((u8 *)gUiContext + 8) = 0x31;
    else
        *((u8 *)gUiContext + 8) = 0x2A;
    return 5;
}
#pragma global_optimizer reset
/* Show move-limit overlay for the type-7 map-obj event at the UI cursor. */
s32 Ui_ShowMapObjAttackRange(void) {
    void *Item_Get(u8);
    s32 Item_GetMaxRange(void);
    void Map_ClipRangeByFacing(void *, u8, u8, u8);
    void Map_FillAttackRange(void *, u8, u8, u8, s32);
    void Map_FillLayer(void *, s32, s32);
    void Map_SelectRangeBuffer(void *, s32);
    void Map_ShowMoveLimitView(void);
    void *MapObjEvent_Find(void *, u8, u8, s32);
    extern u8 gBattleMap[];
    extern u8 gUiContext[];
    extern u8 gMapObjEventList[];
    u8 *event;
    u8 minRange, y, x;

    Map_FillLayer(gBattleMap, 5, -1);
    Map_FillLayer(gBattleMap, 8, 0);
    Map_SelectRangeBuffer(gBattleMap, 6);
    event = MapObjEvent_Find(gMapObjEventList, gUiContext[13], gUiContext[14], 7);
    minRange = *((u8 *)Item_Get(event[4]) + 29);
    y = event[1];
    x = event[0];
    Map_FillAttackRange(gBattleMap, x, y, minRange, Item_GetMaxRange());
    Map_ClipRangeByFacing(gBattleMap, event[0], event[1], event[3]);
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

s32 fn_800784B4(void) {
    u64 *Item_GetFlagsPtr(void *);
    void fn_8002C034(void *, u32);
    u32 *Unit_GetHeldItemSlot(void *, s32);
    u8 fn_8009339C(void *, u32);
    u8 Status_Test(void *, s32);
    extern u8 gUiContext[];
    extern s32 gTargetList[];
    u32 *entry;
    s32 i;
    u8 *ctx;
    {
        u8 *initial = gUiContext;
        if (*(s8 *)(initial + 0x12)) return 3;
        if (!Status_Test(*(u8 **)initial + 0x1BC, 0x3F)) return 3;
        if (*(s8 *)(initial + 0x12)) return 3;
    }
    ctx = gUiContext;
    i = 0;
    do {
        entry = Unit_GetHeldItemSlot(*(void **)ctx, i);
        if (*entry != 0) {
            if ((*Item_GetFlagsPtr(entry) & 1) != 0 &&
                fn_8009339C(*(void **)gUiContext, *entry)) {
                fn_8002C034(*(void **)gUiContext, *entry);
                if (gTargetList[0]) return 0;
            }
            i++;
        } else break;
    } while (i < 4);
    return 3;
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

/* Return 0 if the UI unit has a weapon with in-range tile targets, else 3 (menu grayed). */
s32 Ui_HasWeaponTileTarget(void) {
    void *Item_GetFlagsPtr(void);
    void fn_8002BEFC(void *, u32);
    u32 *Unit_GetHeldItemSlot(void *, s32);
    u8 fn_8009339C(void *, u32);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } gTargetList;
    u32 *entry;
    s32 i;
    u8 *ctx;
    void *flags;

    ctx = gUiContext;
    if ((s8)ctx[0x12] != 0) {
        return 3;
    }
    i = 0;
    do {
        entry = Unit_GetHeldItemSlot(*(void **)ctx, i);
        if (*entry != 0) {
            flags = Item_GetFlagsPtr();
            if ((*(u64 *)flags & 1) != 0
                && fn_8009339C(*(void **)gUiContext, *entry) != 0) {
                fn_8002BEFC(*(void **)gUiContext, *entry);
                if (gTargetList.n != 0) {
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

s32 Ui_HasWeaponTarget(void) {
    /* Return 0 if the UI unit has a weapon with map targets, else 3 (menu grayed). */
    void *Item_GetFlagsPtr(void);
    void fn_8002C034(void *, u32);
    u32 *Unit_GetHeldItemSlot(void *, s32);
    u8 fn_8009339C(void *, u32);
    extern u8 gUiContext[];
    extern struct { s32 n; u8 pad[2004]; } gTargetList;
    u32 *entry;
    s32 i;
    u8 *ctx;
    void *flags;

    ctx = gUiContext;
    if ((s8)ctx[0x12] != 0) {
        return 3;
    }
    i = 0;
    do {
        entry = Unit_GetHeldItemSlot(*(void **)ctx, i);
        if (*entry != 0) {
            flags = Item_GetFlagsPtr();
            if ((*(u64 *)flags & 1) != 0
                && fn_8009339C(*(void **)gUiContext, *entry) != 0) {
                fn_8002C034(*(void **)gUiContext, *entry);
                if (gTargetList.n != 0) {
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
    extern struct { s32 n; u8 pad[2004]; } gTargetList;
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
    if (gTargetList.n == 0) {
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
    extern u8 lbl_802EF4C8[];
    s32 fn_8000E0E4(void *);
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
        str = fn_8000E0E4(lbl_8026C0B8 + 0x535);
        a = obj->v22();
        b = obj->v21();
        fn_80166AE8(b + x, a + y, str, arg1);
        return 0;
    }
    {
        u8 *p = lbl_802EF4C8;
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
    s32 Game_SetState(s16);
    s32 temp_r3 = ((s32 *) arg0)[1];
    Game_SetState((s16) (((u32) ((s32 *) temp_r3)[0]) >> 16));
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
    extern u8 gMapUiResult;

    u8 *data;
    void (*callback)(void *);

    if (gMapUiResult == 9) {
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
    extern u8 gMapUiResult;
    u32 *ptr;

    if (gMapUiResult == 9) {
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
    void *Process_CreateEx(void *, s32);
    void fn_8000C068(void *, s32);
    extern u8 lbl_80288CAC[];
    extern void fn_80079138(void);
    void *temp_r3;

    temp_r3 = Process_CreateEx(lbl_80288CAC, arg1);
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
    void *Process_CreateEx(void *, s32);
    extern u8 lbl_80288CAC[];
    void *temp_r3;

    temp_r3 = Process_CreateEx(lbl_80288CAC, arg1);
    *(s32 *)((char *)temp_r3 + 0x30) = arg0;
    *(s32 *)((char *)temp_r3 + 0x34) = 0;
    *(s32 *)((char *)temp_r3 + 0x38) = 8;
    *(s16 *)((char *)temp_r3 + 0x28) = 8;
    *(s32 *)((char *)temp_r3 + 0x3C) = 0xFF;
    *(s32 *)((char *)temp_r3 + 0x40) = 0;
}

void fn_800791F0(s32 arg0, s32 arg1) {
    void *Process_CreateEx(void *, s32);
    extern u8 lbl_80288CAC[];
    void *temp_r3;

    temp_r3 = Process_CreateEx(lbl_80288CAC, arg1);
    *(s32 *)((char *)temp_r3 + 0x30) = arg0;
    *(s32 *)((char *)temp_r3 + 0x34) = 0;
    *(s32 *)((char *)temp_r3 + 0x38) = 8;
    *(s16 *)((char *)temp_r3 + 0x28) = 8;
    *(s32 *)((char *)temp_r3 + 0x3C) = 0;
    *(s32 *)((char *)temp_r3 + 0x40) = 0xFF;
}

void fn_80079248(void*p){f32 Math_Ease(s32,f32,f32,f32,f32);*(s32*)((u8*)p+0x34)+=1;*(s8*)((u8*)*(void**)((u8*)p+0x30)+0x42)=Math_Ease(0,(f32)*(s32*)((u8*)p+0x3c),(f32)*(s32*)((u8*)p+0x40),(f32)*(s32*)((u8*)p+0x34),(f32)*(s32*)((u8*)p+0x38));}

void fn_80079300(void *arg0, s8 arg1) {
    struct Row {
        s16 x;
        s16 y;
        u16 flags;
    };
    extern struct Row lbl_80312060[];

    if (arg1 >= 0) {
        M2C_FIELD(arg0, s8 *, 0x43) = arg1;
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) lbl_80312060[arg1].x;
        M2C_FIELD(arg0, f32 *, 0x3C) = (f32) lbl_80312060[arg1].y;
        M2C_FIELD(arg0, u16 *, 0x46) |= (s16) lbl_80312060[arg1].flags;
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

void fn_80079634(u8 *obj) {
 extern void *gFaceSlots[]; extern u8 lbl_80288AD8[],lbl_8026C640[];
 extern f32 lbl_803693D8,lbl_803693D4;
 void *Process_Create(void*,s32); void *Res_GetByName(void*); void *fn_802002F0(void*);
 u8 *face; s32 index,i; void *res; void **p=gFaceSlots;
 for(i=0;i<8;i++,p++) { if(*p==0) {index=i;break;} }
 if(i==8) face=0;
 else if(gFaceSlots[index]!=0) face=0;
 else {
 face=Process_Create(lbl_80288AD8,3);
 res=Res_GetByName(lbl_8026C640+0x105); res=res?res:Res_GetByName(lbl_8026C640+0xEF);
 *(void**)(face+0x34)=res;
 face[0x40]=index; *(u16*)(face+0x46)=0;
 face[0x41]=0xFF; face[0x42]=0;
 *(f32*)(face+0x4C)=1.0f; *(f32*)(face+0x48)=0.0f;
 *(u16*)(face+0x46)|=0x200;
 if(*(u16*)(face+0x46)&0x200) {
 *(u16*)(face+0x46)&=~0x202;
 if((*(u8**)(face+0x34))[0x1C]==0) *(u16*)(face+0x46)|=2;
 }
 *(s8*)(face+0x43)=-1; gFaceSlots[index]=face;
 *(void**)(face+0x30)=fn_802002F0(**(void***)(face+0x34)); }
 *(void**)(obj+0x30)=face; *(f32*)(obj+0x34)=1.0f;
}

#pragma global_optimizer off
void fn_8007982C(s32 arg0) {
    void *fn_8007BD30(s8, s32, s32, s32, s32, s32, s32);
    void *Process_Create(void *, s32);
    extern void *gFaceSlots[];
    extern s32 lbl_80367480, lbl_80367484;
    extern s32 *lbl_80367478;
    extern void *gActiveFace;
    extern u8 lbl_80288B40[];
    extern void *lbl_803674B0[2];
    void **p;
    s32 n, i;
    s32 text;
    u8 face;
    void *proc;
    n = 0;
    lbl_80367480 = n;
    gActiveFace = (void *)n;
    lbl_80367484 = n;
    text = *lbl_80367478;
    p = gFaceSlots;
    for (i = 0; i < 8; i++, p++) {
        if (*p == 0) {
            n = i;
            goto found;
        }
    }
    n = -1;
found:
    gActiveFace = fn_8007BD30((s8)n, text, 0x1E0, 0x17C, 0, 0, 0);
    face = *((u8 *)gActiveFace + 0x40);
    proc = Process_Create(lbl_80288B40, 3);
    *(s32 *)((u8 *)proc + 0x60) = face;
    *(s32 *)((u8 *)proc + 0x64) = 8;
    Ui_CreateMenu(lbl_803674B0, arg0, 0);
}
#pragma global_optimizer reset
s32 fn_80079974(void *unused,void *parent) {
 void Process_CreateChild(void *,void *);
 void Process_Unlink(void *);
 void *Process_Create(void *,s32);
 void *fn_8007BD30(s8,s32,s32,s32,s32,s32,s32);
 extern u8 *gPadInput;
 extern u8 lbl_80288C90[],lbl_80288B40[];
 extern s32 lbl_80367480,lbl_8036747C,lbl_80367484;
 extern u8 *lbl_80367478;
 extern void *gActiveFace;
 extern void *gFaceSlots[];
 u8 changed=0;
 u8 *pad=gPadInput;
 u32 held=*(u32 *)(pad+4);
 u32 id;
 s32 text;
 s32 slot;
 void **slots;
 void *face;
 void *proc;
 s8 n;
 s32 i;
 s32 flags;
 if(held&(*(u32 *)(pad+8)^held)&0x400) {
 Process_CreateChild(lbl_80288C90,parent);return 0;
 }
 if(*(u32 *)(pad+12)&0x01000001) {
 changed=1;
 if(lbl_80367480>0)lbl_80367480--;else lbl_80367480=lbl_8036747C-1;
 }
 if(*(u32 *)(pad+12)&0x02000002) {
 changed=1;
 if(lbl_80367480<lbl_8036747C-1)lbl_80367480++;else lbl_80367480=0;
 }
 if(changed) {
 text=*(s32 *)(lbl_80367478+lbl_80367480*32);
 face=gActiveFace;
 if(face) {
 if(face) {
 slot=*((u8 *)face+0x40);
 slots=gFaceSlots;
 if(slots[slot])Process_Unlink(slots[slot]);
 slots[slot]=0;
 }
 }
 flags=lbl_80367484;
 slots=gFaceSlots;
 for(i=0;i<8;i++,slots++) {if(*slots==0){n=i;goto found;}}
 n=-1;
 found:
 gActiveFace=fn_8007BD30((s8)n,text,0x1e0,0x17c,flags,0,0);
 id=*((u8 *)gActiveFace+0x40);
 proc=Process_Create(lbl_80288B40,3);
 *(s32 *)((u8 *)proc+0x60)=id;
 *(s32 *)((u8 *)proc+0x64)=8;
 }
 return 0;
}

void fn_80079B9C(void *unused, void *parent, void *node) {
    void Prim2D_SetText(void *);
    void Prim2D_SetScale(f32);
    void Prim2D_SetTint(s32, s32, s32, s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    extern u8 *lbl_80367478;
    extern s32 lbl_80367480;
    extern f32 lbl_803693D4, lbl_803693D8, gFaceDbgTextScale;
    void *text = *(void **)(lbl_80367478 + lbl_80367480 * 32);
    Prim2D_Begin();
    Prim2D_SetTransform((f32)*(s16*)((u8*)parent+0x30), (f32)*(s16*)((u8*)parent+0x32), lbl_803693D4, lbl_803693D8);
    Prim2D_SetTex(0,3);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(5);
    Prim2D_SetPos((f32)*(s16*)((u8*)node+0x30), (f32)*(s16*)((u8*)node+0x32));
    Prim2D_SetText(text);
    Prim2D_SetScale(gFaceDbgTextScale);
    if (*(u8*)((u8*)node+0x38)) Prim2D_SetTint(255,255,0,255);
    if (*(u8*)((u8*)node+0x39)==2) Prim2D_SetTint(0,0,0,255);
    Prim2D_EndPrim();
}

#pragma push
#pragma optimization_level 2
void fn_80079CD8(void *arg0) {
    void Process_Goto(void *, s32);
    u32 Rand_Next(void);
    void Face_DrawEyes(void *, s32, s32);
    s32 var_r31 = 0;
    u32 temp_r3;
    s32 var_r0;

    switch (M2C_FIELD(arg0, s16 *, 0x38)) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        var_r31 = 1;
        break;
    case 6: case 7: case 8: case 9: case 10: case 11:
        var_r31 = 2;
        break;
    case 12: case 13: case 14: case 15: case 16: case 17:
        var_r31 = 1;
        break;
    case 18:
        Process_Goto(arg0, 1);
        M2C_FIELD(arg0, s16 *, 0x36) = 1;
        temp_r3 = Rand_Next() >> 0x10U;
        switch (M2C_FIELD(arg0, s16 *, 0x34)) {
        case 3:
            var_r0 = ((s32)temp_r3 >> 7) + 0x12C;
            break;
        case 1:
            var_r0 = ((s32)temp_r3 >> 7) + 0x1E;
            break;
        case 2:
            var_r0 = ((s32)temp_r3 >> 10) + 1;
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

    Face_DrawEyes(arg0, 0, 7);
    Face_DrawEyes(arg0, var_r31, 0xA);
    M2C_FIELD(arg0, s16 *, 0x38)++;
}
#pragma pop
void fn_80079E08(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
}

#pragma push
#pragma optimization_level 2
void fn_80079E14(void *arg0) {
    void Process_Goto(void *, s32);
    u32 Rand_Next(void);
    void Face_DrawEyes(void *, s32, s32);
    s32 var_r31 = 0;
    u32 temp_r3;
    s32 var_r0;

    switch (M2C_FIELD(arg0, s16 *, 0x38)) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        var_r31 = 1;
        break;
    case 6: case 7: case 8: case 9: case 10: case 11:
        var_r31 = 2;
        break;
    case 12: case 13: case 14: case 15: case 16: case 17:
        var_r31 = 1;
        break;
    case 18:
        Process_Goto(arg0, 1);
        M2C_FIELD(arg0, s16 *, 0x36) = 1;
        temp_r3 = Rand_Next() >> 0x10U;
        switch (M2C_FIELD(arg0, s16 *, 0x34)) {
        case 3:
            var_r0 = ((s32)temp_r3 >> 7) + 0x12C;
            break;
        case 1:
            var_r0 = ((s32)temp_r3 >> 7) + 0x1E;
            break;
        case 2:
            var_r0 = ((s32)temp_r3 >> 10) + 1;
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

    Face_DrawEyes(arg0, var_r31, 7);
    Face_DrawEyes(arg0, 0, 0xA);
    M2C_FIELD(arg0, s16 *, 0x38)++;
}
#pragma pop
void fn_80079F44(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
}

void Face_BlinkWaitProc(void *proc) {
    /* Draw both eye layers; unless blink-held, jump to state 1 and roll a random wait timer. */
    void Process_Goto(void *, s32);
    u32 Rand_Next();
    void Face_DrawEyes(void *, s32, s32);
    s32 wait;
    u32 rnd;

    Face_DrawEyes(proc, 0, 7);
    Face_DrawEyes(proc, 0, 0xA);
    if ((s16) M2C_FIELD(proc, s16 *, 0x36) != 5) {
        Process_Goto(proc, 1);
        rnd = Rand_Next() >> 0x10U;
        switch ((s16) M2C_FIELD(proc, s16 *, 0x34)) {
        case 3:
            wait = ((s32) rnd >> 7) + 0x12C;
            break;
        case 1:
            wait = ((s32) rnd >> 7) + 0x1E;
            break;
        case 2:
            wait = ((s32) rnd >> 0xA) + 1;
            break;
        case 4:
            wait = 1;
            break;
        case 5:
            wait = 0x7FFFFFFF;
            break;
        default:
            wait = 1;
            break;
        }
        M2C_FIELD(proc, s32 *, 0x3C) = wait;
    }
}

void fn_8007A024(void *arg0) {
    void Process_Goto(void *, s32);
    u32 Rand_Next(void);
    void Face_DrawEyes(void *, s32, s32);
    s32 var_r31;
    s32 var_r0;
    u32 temp_r3;
    u32 temp_r3_hi;

    if (M2C_FIELD(arg0, s16 *, 0x38) <= 2) {
        var_r31 = 0;
        switch (M2C_FIELD(arg0, s16 *, 0x38)) {
        case 0: case 1: case 2:
            var_r31 = 1;
            break;
        case 3: case 4: case 5:
            var_r31 = 2;
            break;
        case 6: case 7: case 8:
            var_r31 = 1;
            break;
        case 10:
            Process_Goto(arg0, 1);
            break;
        }
        Face_DrawEyes(arg0, var_r31, 7);
        Face_DrawEyes(arg0, var_r31, 0xA);
        M2C_FIELD(arg0, s16 *, 0x38) = (s16)(M2C_FIELD(arg0, s16 *, 0x38) + 1);
        return;
    }
    Face_DrawEyes(arg0, 1, 7);
    Face_DrawEyes(arg0, 1, 0xA);
    if (M2C_FIELD(arg0, s16 *, 0x36) != 4) {
        Process_Goto(arg0, 1);
        temp_r3 = Rand_Next();
        temp_r3_hi = temp_r3 >> 0x10U;
        switch (M2C_FIELD(arg0, s16 *, 0x34)) {
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
    void Process_Goto(void *, s32);
    void Face_DrawEyes(void *, s32, s32);
    s32 frame;
    if (*(s16 *)((u8 *)arg0 + 0x38) <= 5) {
        frame = 0;
        switch (*(s16 *)((u8 *)arg0 + 0x38)) {
        case 0: case 1: case 2: frame = 1; break;
        case 3: case 4: case 5: frame = 2; break;
        case 6: case 7: case 8: frame = 1; break;
        case 9: break;
        case 10: Process_Goto(arg0,1); break;
        default: break;
        }
        Face_DrawEyes(arg0,frame,7);
        Face_DrawEyes(arg0,frame,10);
        ++*(s16 *)((u8 *)arg0 + 0x38);
    } else {
        Face_DrawEyes(arg0,2,7);
        Face_DrawEyes(arg0,2,10);
        if (*(s16 *)((u8 *)arg0+0x36) != 3) Process_Goto(arg0,2);
    }
}

void fn_8007A2A0(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
}

void fn_8007A2AC(void *arg0) {
    void Process_Goto(void *, s32);
    void Face_DrawEyes(void *, s32, s32);
    register s32 var_r31;

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

    Face_DrawEyes(arg0, var_r31, 7);
    Face_DrawEyes(arg0, var_r31, 0xA);
    ++*(s16 *)((u8 *)arg0 + 0x38);
}

void fn_8007A368(void *arg0) {
    void Process_Goto(void *, u8);
    u32 Rand_Next(void);
    void Face_DrawEyes(void *, s32, s32);
    s16 unk36;
    s32 wait;
    s32 val;
    u32 rnd;

    val = M2C_FIELD(arg0, s32 *, 0x3C);
    M2C_FIELD(arg0, s32 *, 0x3C) = val - 1;
    Face_DrawEyes(arg0, 0, 7);
    Face_DrawEyes(arg0, 0, 0xA);
    unk36 = M2C_FIELD(arg0, s16 *, 0x36);
    if (unk36 != 1) {
        Process_Goto(arg0, unk36);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) < 0) {
        rnd = Rand_Next() >> 0x10;
        switch ((s16)M2C_FIELD(arg0, s16 *, 0x34)) {
        case 3:
            wait = ((s32)rnd >> 7) + 0x12C;
            break;
        case 1:
            wait = ((s32)rnd >> 7) + 0x1E;
            break;
        case 2:
            wait = ((s32)rnd >> 0xA) + 1;
            break;
        case 4:
            wait = 1;
            break;
        case 5:
            wait = 0x7FFFFFFF;
            break;
        default:
            wait = 1;
            break;
        }
        M2C_FIELD(arg0, s32 *, 0x3C) = wait;
        M2C_FIELD(arg0, s16 *, 0x38) = 0;
        Process_Goto(arg0, 2);
    }
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
void Face_DrawEyes(void *arg0, s32 arg1, s32 arg2) {
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
    void *state;
    int w;
    int h;
    register u8 tint;
    u8 pad;

    mode = arg2;
    obj = *(void **)((u8 *)arg0 + 0x30);
    info = *(void **)((u8 *)obj + 0x34);
    if ((*(u16 *)((u8 *)info + 0x18) & 2) == 0) {
        mode -= 6;
    }
    if ((u32)(mode - 7) <= 1U || mode == 9) {
        if (*(u16 *)((u8 *)info + 0xC) == *(u16 *)((u8 *)info + 0x10)) return;
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
    Prim2D_SetTransform(lbl_803693D4, lbl_803693D4, lbl_80366E00 + ((f32)tint / lbl_803693EC), *(f32 *)((u8 *)obj + 0x4C));
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
}

#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma opt_common_subs off
void fn_8007A8D8(void *arg0) {
    s32 Rand_Range(s32);
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
    s32 w2;
    s32 h2;
    s16 x;
    s16 y;
    u8 *obj;
    s32 mode;
    s32 base;
    void *info;
    void **pp;
    void *entry;
    s32 w;
    s32 h;
    u32 tint;
    f32 alpha;
    u8 pad;
    u16 flags;
    s32 timer;

    timer = *(s16 *)((u8 *)arg0 + 0x36);
    if (timer > 0) {
        *(s16 *)((u8 *)arg0 + 0x36) = (s16)(timer - 1);
        if (*(s16 *)((u8 *)arg0 + 0x36) == 0) {
            *(s16 *)((u8 *)arg0 + 0x36) = (s16)(Rand_Range(8) + 1);
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
}
#pragma pop

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

void fn_8007ADC8(s32 index) { extern void *gFaceSlots[]; void Process_Unlink(void *); void **base=gFaceSlots; void *p=base[index]; if(p!=NULL) Process_Unlink(p); base[index]=NULL; }

/* Ease the face slot's tint (+0x41) toward the target; clear when the frame count finishes. */
void Face_EaseTintProc(void *proc)
{
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern void *gFaceSlots[];
    void *face;
    s32 frame;

    face = gFaceSlots[*(s32 *)((u8 *)proc + 0x30)];
    *((s8 *)((u8 *)face + 0x41)) = (s8)Math_Ease(
        *(s32 *)((u8 *)proc + 0x44),
        (f32)*(s32 *)((u8 *)proc + 0x3c),
        (f32)*(s32 *)((u8 *)proc + 0x40),
        (f32)*(s32 *)((u8 *)proc + 0x34),
        (f32)*(s32 *)((u8 *)proc + 0x38));
    frame = *(s32 *)((u8 *)proc + 0x34);
    if (frame == *(s32 *)((u8 *)proc + 0x38)) {
        Process_ClearFunc(proc);
    } else {
        *(s32 *)((u8 *)proc + 0x34) = frame + 1;
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

    scale = 0.0f;
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
    extern f32 lbl_803693D4;
    extern f32 lbl_803693EC;
    void *entry;
    s32 idx;
    f32 frame = (f32)*(s32 *)((u8 *)arg0 + 0x68);
    f32 duration = (f32)*(s32 *)((u8 *)arg0 + 0x64);
    entry = gFaceSlots[*(s32 *)((u8 *)arg0 + 0x60)];
    *(s8 *)((u8 *)entry + 0x42) = (s8)Math_Ease(0, 0.0f, 255.0f, frame, duration);
    idx = *(s32 *)((u8 *)arg0 + 0x64);
    if (idx == *(s32 *)((u8 *)arg0 + 0x68)) Process_ClearFunc(arg0);
    else *(s32 *)((u8 *)arg0 + 0x68) = *(s32 *)((u8 *)arg0 + 0x68) + 1;
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

#pragma push
#pragma optimization_level 3
#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8007B1C4(void *arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4) {
    void **fn_8006EDD8(void *, s32);
    void Prim2D_Begin(void);
    void fn_80009EB0(void *, s32, u8, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, u8);
    void Prim2D_EndPrim(void);
    extern const f32 lbl_803693D4;
    u8 tint;
    s16 x;
    s16 y;
    s32 mode;
    u32 pad;
    void *obj;
    void *info;
    void **pp;
    void *entry;
    s32 w;
    s32 h;
    s32 w2;
    s32 h2;
    f32 scale;

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
            Prim2D_SetQuadMin((f32)x, (f32)y, (f32)w2, lbl_803693D4);
            scale = *(f32 *)((u8 *)obj + 0x4C);
            Prim2D_SetQuadMax((f32)w2 * scale + (f32)x, (f32)h2 * scale + (f32)y, lbl_803693D4, (f32)h2);
        } else {
            Prim2D_SetQuadMin((f32)x, (f32)y, lbl_803693D4, lbl_803693D4);
            scale = *(f32 *)((u8 *)obj + 0x4C);
            Prim2D_SetQuadMax((f32)w2 * scale + (f32)x, (f32)h2 * scale + (f32)y, (f32)w2, (f32)h2);
        }
        Prim2D_SetColor(tint, tint, tint, pad);
        Prim2D_EndPrim();
    }
}
#pragma pop
#pragma global_optimizer off
#pragma use_lmw_stmw on
void fn_8007B4D8(s32 arg0, s32 arg1, u32 a2, void *a3) {
#pragma opt_common_subs off
#pragma dont_inline off
    void **fn_8006EDD8(void *, s32);
    void Prim2D_Begin(void);
    void fn_80009EB0(void *, s32, u8, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, u8);
    void Prim2D_EndPrim(void);
    void fn_8007B1C4(void *, s32, s32, u32, s32);
    extern f32 lbl_803693D4;
    u16 *dim;
    void *meta;
    u8 shade;
    s32 x, y, xx;
    s32 height, width;
    void *arg3;
    u32 arg2;
    s32 mode;
    u16 flags;

    arg2 = a2;
    arg3 = a3;
    shade = M2C_FIELD(arg3, u8 *, 0x41);
    dim = *fn_8006EDD8(M2C_FIELD(arg3, void **, 0x30), 0);
    width = dim[1];
    height = dim[0];
    x = arg0 - (width >> 1);
    y = arg1 - height;
    Prim2D_Begin();
    fn_80009EB0(M2C_FIELD(arg3, void **, 0x30), 0, M2C_FIELD(arg3, u8 *, 0x40), 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    if (M2C_FIELD(arg3, u16 *, 0x46) & 1) {
        f32 scale;
        Prim2D_SetQuadMin((f32)x, (f32)y, (f32)width, lbl_803693D4);
        scale = M2C_FIELD(arg3, f32 *, 0x4C);
        Prim2D_SetQuadMax((f32)width * scale + (f32)x, (f32)height * scale + (f32)y, lbl_803693D4, (f32)height);
    } else {
        f32 scale;
        Prim2D_SetQuadMin((f32)x, (f32)y, lbl_803693D4, lbl_803693D4);
        scale = M2C_FIELD(arg3, f32 *, 0x4C);
        Prim2D_SetQuadMax((f32)width * scale + (f32)x, (f32)height * scale + (f32)y, (f32)width, (f32)height);
    }
    Prim2D_SetColor(shade, shade, shade, arg2);
    Prim2D_EndPrim();
    meta = M2C_FIELD(arg3, void **, 0x34);
    if (M2C_FIELD(meta, u16 *, 0x18) & 2) {
        flags = M2C_FIELD(arg3, u16 *, 0x46);
        mode = get_B4D8_mode(flags);
        xx = M2C_FIELD(meta, u16 *, 0x14);
        height = M2C_FIELD(meta, u16 *, 0x16);
        if (flags & 1) {
            xx = width - xx;
        }
        xx += x;
        height += y;
        dim = *fn_8006EDD8(M2C_FIELD(arg3, void **, 0x30), mode);
        y = dim[1];
        x = dim[0];
        if (M2C_FIELD(arg3, u16 *, 0x46) & 1) {
            xx -= y;
        }
        Prim2D_Begin();
        fn_80009EB0(M2C_FIELD(arg3, void **, 0x30), mode, M2C_FIELD(arg3, u8 *, 0x40), 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        if (M2C_FIELD(arg3, u16 *, 0x46) & 1) {
            f32 scale;
            Prim2D_SetQuadMin((f32)xx, (f32)height, (f32)y, lbl_803693D4);
            scale = M2C_FIELD(arg3, f32 *, 0x4C);
            Prim2D_SetQuadMax((f32)y * scale + (f32)xx, (f32)x * scale + (f32)height, lbl_803693D4, (f32)x);
        } else {
            f32 scale;
            Prim2D_SetQuadMin((f32)xx, (f32)height, lbl_803693D4, lbl_803693D4);
            scale = M2C_FIELD(arg3, f32 *, 0x4C);
            Prim2D_SetQuadMax((f32)y * scale + (f32)xx, (f32)x * scale + (f32)height, (f32)y, (f32)x);
        }
        Prim2D_SetColor(shade, shade, shade, arg2);
        Prim2D_EndPrim();
    }
    if (M2C_FIELD(M2C_FIELD(arg3, void **, 0x34), u16 *, 0x18) & 1) {
        fn_8007B1C4(arg3, arg0, arg1, arg2, 7);
        fn_8007B1C4(arg3, arg0, arg1, arg2, 10);
    }
}

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma opt_common_subs reset
#pragma global_optimizer reset
void Face_ClearSlot(void *arg0) {
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

void *Face_Create(void *name, s32 flags) {
 extern void *gFaceSlots[]; extern u8 lbl_80288AD8[],lbl_8026C640[];
 extern f32 lbl_803693D8,lbl_803693D4;
 void *Process_Create(void*,s32); void *Res_GetByName(void*); void *fn_802002F0(void*);
 s32 index,i; u8 *face; void *res; void **p=gFaceSlots;
 for(i=0;i<8;i++,p++) { if(*p==0) {index=i;break;} }
 if(i==8) return 0;
 if(gFaceSlots[index]!=0) return 0;
 face=Process_Create(lbl_80288AD8,3);
 res=Res_GetByName(name); res=res?res:Res_GetByName(lbl_8026C640+0xEF);
 *(void**)(face+0x34)=res;
 face[0x40]=index; *(u16*)(face+0x46)=flags;
 face[0x41]=0xFF; face[0x42]=0;
 *(f32*)(face+0x4C)=1.0f; *(f32*)(face+0x48)=0.0f;
 *(u16*)(face+0x46)|=0x200;
 if(*(u16*)(face+0x46)&0x200) {
 *(u16*)(face+0x46)&=~0x202;
 if((*(u8**)(face+0x34))[0x1C]==0) *(u16*)(face+0x46)|=2;
 }
 *(s8*)(face+0x43)=-1; gFaceSlots[index]=face;
 *(void**)(face+0x30)=fn_802002F0(**(void***)(face+0x34)); return face;
}

void fn_8007BC3C(s32 a, s32 b, s32 c, s32 d, s32 e)
{
    void fn_8007BD30(s8, s32, s32, s32, s32, s32, s32);
    extern void *gFaceSlots[];
    void **p = gFaceSlots;
    s32 n, i;
    for(i=0; i<8; i++,p++) {
        if(*p == NULL) { n=i; goto found; }
    }
    n=-1;
found:
    fn_8007BD30((s8)n,a,b,c,d,0,e);
}

#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
void *fn_8007BD30(s32 index, void *name, s32 x, s32 y, u32 flags, s32 unused, void *parent) {
extern void *gFaceSlots[]; extern u8 lbl_80288AD8[],lbl_8026C640[];
extern f32 lbl_803693D8,lbl_803693D4;
void *Res_GetByName(void *); void *Process_Create(void *,void *); void Process_Goto(void *,s32); s32 fn_802002F0(s32);
u8 *found; u8 *res; u8 *face; u8 *child; s32 mode; u8 (*scripts)[0x18]=(void *)lbl_80288AD8;
found=Res_GetByName(name);
if(found) res=found; else res=Res_GetByName(lbl_8026C640+0xef);
if(gFaceSlots[index]) return 0;
mode=flags&0x100;
if(mode) {
if(!parent) parent=(void *)3;
face=Process_Create(scripts[0],parent);
M2C_FIELD(face,void **,0x34)=res; face[0x40]=index;
M2C_FIELD(face,f32 *,0x38)=x; M2C_FIELD(face,f32 *,0x3c)=y;
M2C_FIELD(face,u16 *,0x46)=flags; face[0x41]=255; face[0x42]=0;
M2C_FIELD(face,f32 *,0x4c)=1.0f; M2C_FIELD(face,f32 *,0x48)=0.0f;
if(flags&0x200) { M2C_FIELD(face,u16 *,0x46)&=~0x202; if(M2C_FIELD(M2C_FIELD(face,void **,0x34),u8 *,0x1c)==0) M2C_FIELD(face,u16 *,0x46)|=2; }
M2C_FIELD(face,void **,0x50)=0; M2C_FIELD(face,void **,0x54)=0;
gFaceSlots[index]=face; M2C_FIELD(face,s32 *,0x30)=0; return face;
}
if(!parent) parent=(void *)3;
face=Process_Create(scripts[1],parent);
M2C_FIELD(face,void **,0x34)=res; face[0x40]=index;
M2C_FIELD(face,f32 *,0x38)=x; M2C_FIELD(face,f32 *,0x3c)=y;
M2C_FIELD(face,u16 *,0x46)=flags; face[0x41]=255; face[0x42]=0;
M2C_FIELD(face,f32 *,0x4c)=1.0f; M2C_FIELD(face,f32 *,0x48)=0.0f;
if(flags&0x200) { M2C_FIELD(face,u16 *,0x46)&=~0x202; if(M2C_FIELD(M2C_FIELD(face,void **,0x34),u8 *,0x1c)==0) M2C_FIELD(face,u16 *,0x46)|=2; }
M2C_FIELD(face,void **,0x50)=0; M2C_FIELD(face,void **,0x54)=0;
if(!mode) {
if(M2C_FIELD(res,u16 *,0x18)&2) M2C_FIELD(face,void **,0x50)=Process_Create((u8 *)scripts+0xc8,face);
if(M2C_FIELD(res,u16 *,0x18)&1) {
M2C_FIELD(face,void **,0x54)=Process_Create((u8 *)scripts+0xe4,face);
switch((s32)(flags&12)) {
case 12: break;
case 4: child=M2C_FIELD(face,void **,0x54); if(child) { M2C_FIELD(child,u16 *,0x36)=3; M2C_FIELD(child,u16 *,0x38)=5; Process_Goto(child,8); } break;
case 8: child=M2C_FIELD(face,void **,0x54); if(child) { M2C_FIELD(child,u16 *,0x36)=4; M2C_FIELD(child,u16 *,0x38)=2; Process_Goto(child,9); } break;
}
}
}
gFaceSlots[index]=face;
M2C_FIELD(face,s32 *,0x30)=fn_802002F0(M2C_FIELD(M2C_FIELD(face,void **,0x34),s32 *,0));
return face;
}
#pragma pop
void fn_8007C018(void *arg0) {
    M2C_UNK fn_80200270(s32);
    if ((u32) M2C_FIELD(arg0, u32 *, 0x30) != 0U) {
        fn_80200270(*M2C_FIELD(arg0, s32 **, 0x34));
    }
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
void fn_8007C04C(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void fn_80009EB0(s32, s32, u8, s32);
    void Prim2D_SetCallback(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, u8);
    void Prim2D_EndPrim(void);
    void Prim2D_ClearCallbacks(void);
    void **fn_8006EDD8(s32, s32);
    s32 __cvt_fp2unsigned(f32);
    extern f64 lbl_803693C8;
    extern f32 lbl_803693D4;
    extern f32 lbl_803693D8;
    extern f32 lbl_803693EC;
    extern f64 lbl_803693F0;
    extern f32 lbl_803693F8;
    extern f32 lbl_80366E00;
    extern void fn_8007C318(void);
    s32 temp_r31;
    s32 temp_r30;
    s32 var_r3;
    s32 temp_r29;
    s32 temp_r28;
    u16 temp_r3_2;
    u8 temp_r3;
    u8 temp_r3_3;
    void *temp_r4;

    temp_r4 = *fn_8006EDD8(*(s32 *)((u8 *)arg0 + 0x30), 0);
    temp_r29 = *(u16 *)((u8 *)temp_r4 + 2);
    temp_r28 = *(u16 *)((u8 *)temp_r4 + 0);
    temp_r31 = (s32)(*(f32 *)((u8 *)arg0 + 0x38) - (f32)(temp_r29 / 2));
    temp_r30 = (s32)(*(f32 *)((u8 *)arg0 + 0x3C) - (f32)temp_r28);
    if (temp_r31 <= 0x260) {
        Prim2D_Begin();
        temp_r3 = *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x1D);
        Prim2D_SetTransform(lbl_803693D4, lbl_803693D4, lbl_80366E00 + ((f32)temp_r3 / lbl_803693EC), lbl_803693D8);
        fn_80009EB0(*(s32 *)((u8 *)arg0 + 0x30), 0, *(u8 *)((u8 *)arg0 + 0x40), 0x11);
        temp_r3_2 = *(u16 *)((u8 *)arg0 + 0x46);
        if ((temp_r3_2 & 0x4000) != 0) {
            if ((temp_r3_2 & 1) != 0) {
                var_r3 = (__cvt_fp2unsigned(*(f32 *)((u8 *)arg0 + 0x38) - lbl_803693F8) << 0x10) + 0x12C;
            } else {
                var_r3 = __cvt_fp2unsigned(lbl_803693F8 + *(f32 *)((u8 *)arg0 + 0x38));
            }
            Prim2D_SetCallback(&fn_8007C318, var_r3);
        }
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        if ((*(u16 *)((u8 *)arg0 + 0x46) & 1) != 0) {
            Prim2D_SetQuadMin((f32)temp_r31, (f32)temp_r30, (f32)temp_r29, lbl_803693D4);
            Prim2D_SetQuadMax((f32)(temp_r31 + temp_r29), (f32)(temp_r30 + temp_r28), lbl_803693D4, (f32)temp_r28);
        } else {
            Prim2D_SetQuadMin((f32)temp_r31, (f32)temp_r30, lbl_803693D4, lbl_803693D4);
            Prim2D_SetQuadMax((f32)(temp_r31 + temp_r29), (f32)(temp_r30 + temp_r28), (f32)temp_r29, (f32)temp_r28);
        }
        temp_r3_3 = *(u8 *)((u8 *)arg0 + 0x41);
        Prim2D_SetColor(temp_r3_3, temp_r3_3, temp_r3_3, *(u8 *)((u8 *)arg0 + 0x42));
        Prim2D_EndPrim();
        Prim2D_ClearCallbacks();
    }
}
#pragma pop
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

#pragma global_optimizer off
static void *fn_8007C378_Pick(void) {
    void *Res_GetByName();
    extern u8 lbl_8026C640[];
    void *result = Res_GetByName();
    if (result)
        return result;
    else
        return Res_GetByName(lbl_8026C640 + 0xEF);
}
void fn_8007C378(void) {
    void Msg_Expand(u32);
    void *x = fn_8007C378_Pick();
    Msg_Expand(*(u32 *)((u8 *)x + 4));
}
#pragma global_optimizer reset
void *fn_8007C3BC(void *arg0) {
 extern u8 lbl_8026C640[];
 void *Res_GetByName(void *);
 void *result=Res_GetByName(arg0);
 if(result) return result;
 else return Res_GetByName(lbl_8026C640+0xEF);
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

    extern void *Archive_Load(void *);
    extern void fn_8000D3EC(void *, void *);

    long offset;
    u32 *data;
    s32 i;
    register u8 *entry;

    data = (u32 *)Archive_Load(lbl_8026C640 + 0x110);

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
extern s32 gTargetList[];
extern void *Item_GetFlagsPtr(void);
extern void *UiCtx_GetItemSlot(void *);
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
extern s32 gTargetList[502];
#include "global.h"
