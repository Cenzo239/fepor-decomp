/* Functions from 0x801E4540 to 0x801EA8C0, found by decomp-toolkit. */
#include "common.h"
#include "global.h"

struct UnkStruct {
    u32 field_0[0x10];
    u32 field_8;
};

#pragma global_optimizer off
void fn_801E4540(void)
{
    void fn_800C0818(s32);
    void fn_8008A290(s32, s32);
    s32 fn_801270A4(void);
    void *fn_8000CAA0(void *, s32);
    void fn_80142060(void *);
    void fn_8000C070(void *, s32);
    extern u8 lbl_80299FE0[];
    u8 *ptr;

    fn_800C0818(1);
    fn_8008A290(1, 0);
    ptr = (u8 *)fn_8000CAA0(lbl_80299FE0, fn_801270A4());
    if (ptr != 0) {
        *(u8 *)(ptr + 0x30) = 0;
        *(u8 *)(ptr + 0x31) = 0;
        *(u8 *)(ptr + 0x32) = 0;
        *(u8 *)(ptr + 0x33) = 0;
        *(u8 *)(ptr + 0x34) = 0;

        *(u16 *)(ptr + 0x36) = 0;
        *(u16 *)(ptr + 0x38) = 0;
        *(u16 *)(ptr + 0x3A) = 8;
        *(s16 *)(ptr + 0x3C) = -1;
        *(s16 *)(ptr + 0x3E) = -1;

        *(u32 *)(ptr + 0x40) = 0;
        *(u32 *)(ptr + 0x44) = 0;
        *(u32 *)(ptr + 0x48) = 0;
        *(u32 *)(ptr + 0x4C) = 0;

        fn_80142060(ptr + 0x50);

        *(u32 *)(ptr + 0x5C) = 0;
        *(u32 *)(ptr + 0x60) = 0;
        *(u32 *)(ptr + 0x64) = 0;

        fn_8000C070(ptr, 3);
    }
}
#pragma global_optimizer on
s32 fn_801E45FC(void) {
    extern char lbl_80299FA8[];
    return *(s32*)((u8*)lbl_80299FA8 + 4);
}

void TabMenu_HandleInput(void *arg0) {
    /* Handle tab-menu pad input: L/R change tab, A advance in mode 1, X info, B back; tick active mode. */
    void Process_Goto(void *, s32);
    void Ui_PlaySeCue(void *, s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_HideUnitInfoPopup(void *);
    void Ui_OpenUnitInfoText(void *, void *, void *, f32, f32);
    void fn_801E4900(s16 *, void *);
    void TabMenu_SetTab(void *, s8);
    void fn_801E80B4(void *);
    void fn_801E8D34(void *);
    extern u8 gTabMenuStrings[];
    extern u8 gUnitInfoPopup[];
    extern u32 gUiInputFlags;
    extern u32 *gPadInput;
    extern u32 gUnitInfoPopupFlag;
    s16 posCopy[2];
    s16 pos[2];
    s16 holdVal;
    s32 pressed;
    s32 held;
    s32 mode;
    s8 tab;
    u8 skip;
    void *msg;

    skip = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        skip = 1;
    }
    if (skip == 0) {
        held = gPadInput[1];
        pressed = held & (gPadInput[2] ^ held);
        if ((pressed & 0x100) != 0) {
            mode = *(u8 *)((u8 *)arg0 + 0x31);
            if (mode == 1 && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
                Process_Goto(arg0, 2);
                return;
            }
        }
        if ((pressed & 0x40) && (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0)) {
            tab = *(u8 *)((u8 *)arg0 + 0x30);
            if (tab > 0) {
                TabMenu_SetTab(arg0, (s8)(tab - 1));
            } else {
                TabMenu_SetTab(arg0, 2);
            }
            Ui_PlaySeCue(gTabMenuStrings + 0x13F, 0x64);
            return;
        }
        if ((pressed & 0x20) && (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0)) {
            tab = *(u8 *)((u8 *)arg0 + 0x30);
            if (tab < 2) {
                TabMenu_SetTab(arg0, (s8)(tab + 1));
            } else {
                TabMenu_SetTab(arg0, 0);
            }
            Ui_PlaySeCue(gTabMenuStrings + 0x13F, 0x64);
            return;
        }
        if ((pressed & 0x800) && (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0)) {
            fn_801E4900(pos, arg0);
            msg = NULL;
            *(s32 *)posCopy = *(s32 *)pos;
            switch ((s8)*(u8 *)((u8 *)arg0 + 0x31)) {
            case 0:
                msg = gTabMenuStrings + 0x15B;
                break;
            case 1:
                msg = gTabMenuStrings + 0x166;
                break;
            }
            Ui_OpenUnitInfoText(gUnitInfoPopup, arg0, msg, (f32)posCopy[0], (f32)posCopy[1]);
            *(u32 *)gUnitInfoPopup |= gUnitInfoPopupFlag;
            return;
        }
        if ((pressed & 0xA00) && (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0)) {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
            return;
        }
        if ((pressed & 0x200) && (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0)) {
            Process_Goto(arg0, 5);
            Ui_PlaySeCue(gTabMenuStrings + 0x172, 0x64);
            return;
        }
        holdVal = 8;
        if (held & 0x400) {
            holdVal = 0x10;
        }
        *(s16 *)((u8 *)arg0 + 0x3A) = holdVal;
        switch ((s8)*(u8 *)((u8 *)arg0 + 0x31)) {
        case 0:
            fn_801E8D34(arg0);
            break;
        case 1:
            fn_801E80B4(arg0);
            break;
        }
    }
}

void fn_801E4900(s16 *arg0, void *arg1) {
    s32 Text_MeasureHeight(s32, s32, f32);
    s32 fn_801E4A60(void *, s8);
    extern s16 lbl_80332260[];
    extern s8 lbl_803682F8;
    extern f32 gTabMenuOne;

    struct Pair { s16 a; s16 b; };
    struct Pair sp10;
    struct Pair spC;
    struct Pair sp8;
    register s8 row;
    s16 x;
    s16 y;

    if (lbl_803682F8 == 0) {
        sp10.a = 0x100;
        sp10.b = 0x1B;
        ((struct Pair *)lbl_80332260)[0] = sp10;
        spC.a = 0x16A;
        spC.b = 0x1B;
        ((struct Pair *)lbl_80332260)[1] = spC;
        sp8.a = 0x1D4;
        sp8.b = 0x1B;
        ((struct Pair *)lbl_80332260)[2] = sp8;
        lbl_803682F8 = 1;
    }
    switch (*(s8 *)((u8 *)arg1 + 0x31)) {
    case 0: {
        unsigned temp = fn_801E4A60(arg1, (s8)*(u8 *)((u8 *)arg1 + 0x32));
        s16 half;
        register row = (s8)((s8)temp - (*(s16 *)((u8 *)arg1 + 0x38) / 32));
        half = (s16)((0x20 - Text_MeasureHeight(-1, (s8)temp, gTabMenuOne)) >> 1);
        half = (s16)(half + 0x62);
        x = 0x28;
        y = (s16)(half + (row << 5));
        break;
    }
    case 1: {
        unsigned div = *(s16 *)((u8 *)arg1 + 0x38) / 32;
        register s16 half;
        row = (s8)((s8)*(u8 *)((u8 *)arg1 + 0x33) - div);
        half = (s16)((0x20 - Text_MeasureHeight(-1, div, gTabMenuOne)) >> 1);
        half = (s16)(half + 0x62);
        x = 0xA0;
        y = (s16)(half + (row << 5));
        break;
    }
    }
    arg0[0] = x;
    arg0[1] = y;
}

s8 fn_801E4A60(void *arg0, u8 arg1) {
    typedef struct Frame {
        u8 sp8;
        u8 pad9[3];
        u8 spC;
        u8 padD[3];
        u8 sp10;
        u8 pad11[3];
        u8 sp14;
        u8 pad15[3];
        u8 sp18;
        u8 pad19[3];
        u8 sp1C;
        u8 pad1D[3];
        void *sp20;
        void *sp24;
        void *sp28;
        void *sp2C;
        void *sp30;
        void *sp34;
        void *sp38;
        void *sp3C;
        void *sp40;
        void *sp44;
        void *sp48;
        void *sp4C;
        void *sp50;
        void *sp54;
        void *sp58;
        void *sp5C;
        void *sp60;
        void *sp64;
    } Frame;
    Frame fr;
    Frame *p;
    void *list;
    void *first;
    void *data;
    s8 key;
    s8 count;
    u8 match;
    s8 mode;

    p = &fr;
    mode = *(s8 *)((char *)arg0 + 0x30);
    list = (char *)arg0 + 0x54;
    first = *(void **)((char *)list + 4);

    p->sp24 = list;
    p->sp2C = first;
    p->sp28 = first;
    p->sp60 = first;
    p->sp20 = list;
    p->sp5C = list;
    p->sp64 = p->sp60;

    switch (mode) {
    case 0:
        p->sp18 = arg1;
        p->sp1C = arg1;
        key = (s8)(arg1 & 0xFF);
        p->sp50 = list;
        p->sp54 = first;
        goto cond0;
    incr0:
        p->sp54 = *(void **)((char *)p->sp54 + 4);
    cond0:
        if (p->sp54 == list) break;
        data = *(void **)((char *)p->sp54 + 8);
        match = 0;
        if ((s8)*(u8 *)data >= 0) {
            if (key == (s8)*((u8 *)data + 2)) match = 1;
        }
        if (!match) goto incr0;
        p->sp58 = p->sp54;
        p->sp64 = p->sp54;
        break;
    case 1:
        p->sp10 = arg1;
        p->sp14 = arg1;
        key = (s8)(arg1 & 0xFF);
        p->sp44 = list;
        p->sp48 = first;
        goto cond1;
    incr1:
        p->sp48 = *(void **)((char *)p->sp48 + 4);
    cond1:
        if (p->sp48 == list) break;
        data = *(void **)((char *)p->sp48 + 8);
        match = 0;
        if ((s8)*(u8 *)data >= 0) {
            if (key == (s8)*((u8 *)data + 1)) match = 1;
        }
        if (!match) goto incr1;
        p->sp4C = p->sp48;
        p->sp64 = p->sp48;
        break;
    case 2:
        p->sp8 = arg1;
        p->spC = arg1;
        key = (s8)(arg1 & 0xFF);
        p->sp38 = list;
        p->sp3C = first;
        goto cond2;
    incr2:
        p->sp3C = *(void **)((char *)p->sp3C + 4);
    cond2:
        if (p->sp3C == list) break;
        data = *(void **)((char *)p->sp3C + 8);
        match = 0;
        if ((s8)*(u8 *)data >= 0) {
            if (key == (s8)*((u8 *)data + 4)) match = 1;
        }
        if (!match) goto incr2;
        p->sp40 = p->sp3C;
        p->sp64 = p->sp3C;
        break;
    default:
        break;
    }

    count = 0;
    p->sp30 = p->sp60;
    p->sp34 = p->sp64;
    while (p->sp30 != p->sp64) {
        count++;
        p->sp30 = *(void **)((char *)p->sp30 + 4);
    }
    return count;
}

#pragma global_optimizer off
void TabMenu_SetTab(void *arg0, s8 arg1) {
    void *Msg_Expand(void *);
    void TextBanner_SetString(void *, void *);
    void fn_80057860(void *, s16);
    void fn_801E4CF8(void *);
    extern u8 gTabMenuStrings[];
    s32 zero;
    s16 t;

    *(u8 *)((u8 *)arg0 + 0x30) = (u8)arg1;
    fn_801E4CF8(arg0);
    zero = 0;
    *(u8 *)((u8 *)arg0 + 0x31) = (u8)zero;
    switch (zero) {
    case 0:
        TextBanner_SetString(*(void **)((u8 *)arg0 + 0x60), Msg_Expand(gTabMenuStrings + 0x182));
        break;
    case 1:
        TextBanner_SetString(*(void **)((u8 *)arg0 + 0x60), Msg_Expand(gTabMenuStrings + 0x18D));
        break;
    }
    *(u8 *)((u8 *)arg0 + 0x32) = 0;
    *(u8 *)((u8 *)arg0 + 0x33) = 0;
    *(u8 *)((u8 *)arg0 + 0x34) = 0;
    *(s16 *)((u8 *)arg0 + 0x36) = 0;
    *(s16 *)((u8 *)arg0 + 0x38) = 0;
    t = *(s16 *)((u8 *)arg0 + 0x36);
    fn_80057860(*(void **)((u8 *)arg0 + 0x5C), t);
}
#pragma global_optimizer on
void fn_801E4CF8(void *arg0) {
    M2C_UNK fn_801E4D54();
    M2C_UNK fn_801E4E8C();
    M2C_UNK fn_801E4FB8();
    u8 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x30);
    switch ((s8) temp_r0) {                         /* irregular */
    case 0:
        fn_801E4FB8();
        return;
    case 1:
        fn_801E4E8C();
        return;
    case 2:
        fn_801E4D54();
        return;
    }
}

#pragma push
#pragma optimization_level 3
#pragma global_optimizer off
#pragma opt_lifetimes off
void fn_801E4D54(void *arg0) {
    void fn_801EA430(void *, void *);
    void fn_801E9E30(void *, void *);
    void List_Insert(void *, void *, void *, void *);
    void fn_80057898(void *, s32);
    extern u8 lbl_80332020[];
    struct { void *node; } iter, data, copy, pos, result;
    struct { u8 value; } initB, initA, keyCopy, key, bCopy, b, aCopy, a;
    u8 *entry;
    void *end;
    u32 index;
    void *node;
    u8 found;

    bCopy = initB; b = bCopy;
    fn_801EA430((u8*)arg0+0x50, &b);
    aCopy = initA; a = aCopy;
    fn_801E9E30((u8*)arg0+0x50, &a);
    entry = lbl_80332020;
    end = (u8*)arg0+0x54; index = 0;
    iter.node = *(void **)((u8*)arg0+0x58);
    for (;;) {
        key.value = index + 1; keyCopy = key;
        node = iter.node;
        goto search;
        next: node = *(void **)((u8*)node+4);
        search:
        if (node != end) {
            s8 *p = *(s8 **)((u8*)node+8);
            found = 0;
            if (p[0] >= 0 && (s8)keyCopy.value == p[4]) found = 1;
            if (!found) goto next;
        }
        copy.node = node; iter = copy;
        if (node == end) break;
        data.node = entry; entry[4] = index; entry[3] = (*(u8 **)((u8*)node+8))[3]; pos.node = node;
        List_Insert(&result, (u8*)arg0+0x50, &pos, &data);
        entry += 0x18; index++;
    }
    fn_80057898(*(void **)((u8*)arg0+0x5C), *(s32*)((u8*)arg0+0x50)<<5);
}
#pragma pop
void fn_801E4E8C(void *arg0)
{
  void fn_801EA430(void *, void *);
  void fn_801EA018(void *, void *);
  void List_Insert(void *, void *, void *, void *);
  void fn_80057898(void *, s32);
  extern u8 lbl_80332020[];
  struct _PermuterAnon1
  {
    void *node;
  } iter;
  struct _PermuterAnon1 data;
  struct _PermuterAnon1 copy;
  struct _PermuterAnon1 pos;
  unsigned short new_var;
  struct _PermuterAnon1 result;
  struct _PermuterAnon2
  {
    u8 value;
  } initB;
  struct _PermuterAnon2 initA;
  struct _PermuterAnon2 keyCopy;
  struct _PermuterAnon2 key;
  struct _PermuterAnon2 bCopy;
  struct _PermuterAnon2 b;
  struct _PermuterAnon2 aCopy;
  struct _PermuterAnon2 a;
  u8 *entry;
  void *end;
  s32 index;
  void *node;
  u8 found;
  bCopy = initB;
  b = bCopy;
  fn_801EA430(((u8 *) arg0) + 0x50, &b);
  aCopy = initA;
  a = aCopy;
  fn_801EA018(((u8 *) arg0) + 0x50, &a);
  ;
  end = ((u8 *) arg0) + 0x54;
  index = 0;
  iter.node = *((void **) (((u8 *) arg0) + 0x58));
  for (;;)
  {
    new_var = index + 1;
    keyCopy.value = new_var;
    key = keyCopy;
    node = iter.node;
    goto search;
    next:
    node = *((void **) (((u8 *) node) + 4));

    search:
    if (node != end)
    {
      s8 *p = *((s8 **) (((u8 *) node) + 8));
      found = 0;
      if ((p[0] >= 0) && (((s8) key.value) == p[1]))
      {
        found = 1;
      }
      if (!found)
      {
        goto next;
      }
    }

    copy.node = node;
    iter = copy;
    if (node == end)
    {
      break;
    }
    data.node = lbl_80332020;
    lbl_80332020[1] = index;
    pos.node = node;
    List_Insert(&result, ((u8 *) arg0) + 0x50, &pos, &data);
    entry += 0x18;
    index++;
  }

  fn_80057898(*((void **) (((u8 *) arg0) + 0x5C)), (*((s32 *) (((u8 *) arg0) + 0x50))) << 5);
}
#pragma global_optimizer on

#pragma global_optimizer off
#pragma use_lmw_stmw on
static inline void fn_801E4FB8_Impl(void *arg0, void *end, u8 *entry, s32 index) {
    void List_Insert(void *, void *, void *, void *);
    struct { u8 value; } keyCopy, key;
    void *sp[5];
    void *node;
    u8 found;

    sp[4] = *(void **)((u8 *)arg0 + 0x58);
    for (;;) {
        keyCopy.value = index + 1;
        key = keyCopy;
        node = sp[4];
        goto search;
    next:
        node = *(void **)((u8 *)node + 4);
    search:
        if (node != end) {
            s8 *p = *(s8 **)((u8 *)node + 8);
            found = 0;
            if (p[0] >= 0 && (s8)key.value == p[2]) {
                found = 1;
            }
            if (!found) {
                goto next;
            }
        }
        sp[2] = node;
        sp[4] = node;
        if (node == end) {
            break;
        }
        sp[3] = entry;
        entry[2] = index;
        sp[1] = node;
        List_Insert(&sp[0], (u8 *)arg0 + 0x50, &sp[1], &sp[3]);
        entry += 0x18;
        index++;
    }
}

void fn_801E4FB8(void *arg0) {
    void fn_801EA430(void *, void *);
    void fn_801EA248(void *, void *);
    void fn_80057898(void *, s32);
    extern u8 lbl_80332020[];
    struct { u8 value; } initB, initA, bCopy, b, aCopy, a;

    bCopy = initB;
    b = bCopy;
    fn_801EA430((u8 *)arg0 + 0x50, &b);
    aCopy = initA;
    a = aCopy;
    fn_801EA248((u8 *)arg0 + 0x50, &a);
    fn_801E4FB8_Impl(arg0, lbl_80332020, (u8 *)arg0 + 0x54, 0);
    fn_80057898(*(void **)((u8 *)arg0 + 0x5C), *(s32 *)((u8 *)arg0 + 0x50) << 5);
}
#pragma use_lmw_stmw reset
#pragma global_optimizer on
/* Draw the 3-tab menu frame (header + tabs) and the selected tab's contents. */
void TabMenu_Draw(void *menu)
{
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_PrepareTex(void);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetAlphaByte(u8);
    void fn_80056B0C(s32);
    void fn_801E6CEC(void *);
    void Prim2D_SetCallback(void *, s32);
    void TabMenu_DrawTab0(void *);
    void TabMenu_DrawTab1(void *);
    void TabMenu_DrawTab2(void *);
    void Prim2D_ClearCallbacks(void);
    void fn_801E551C(void);
    extern f32 gTabMenuZero;
    extern f32 gTabMenuZ;
    extern f32 gTabMenuOne;
    extern u8 lbl_80332000[];
    extern s16 gTabMenuHeaderRect;
    extern f64 lbl_8036B6E0;
    extern f32 lbl_8036B6F4;
    extern f32 lbl_8036B6F8;
    extern s16 gTabMenuTabRect;
    extern f32 lbl_8036B6FC;
    extern f32 lbl_8036B700;
    extern f32 lbl_8036B704;
    extern f32 lbl_8036B708;

    u8 *rect;
    s16 *p;
    s16 t2, t6, t0, t4;
    s32 alpha;

    Prim2D_Begin();
    Prim2D_SetTransform(gTabMenuZero, gTabMenuZero, gTabMenuZ, gTabMenuOne);
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(*(s32 *)((u8 *)menu + 0x64), lbl_80332000, 0);
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    p = &gTabMenuHeaderRect;
    t2 = p[1];
    t6 = p[3];
    t0 = gTabMenuHeaderRect;
    t4 = p[2];
    Prim2D_SetRectUv(lbl_8036B6F4, lbl_8036B6F8, (f32)gTabMenuHeaderRect, (f32)p[1], (f32)(s16)(t4 - t0),
                     (f32)(s16)(t6 - t2));
    Prim2D_Begin();
    alpha = 0x40;
    if ((s8)*(u8 *)((u8 *)menu + 0x30) == 0) {
        alpha = 0x80;
    }
    Prim2D_SetAlphaByte((u8)alpha);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(*(s32 *)((u8 *)menu + 0x64), lbl_80332000, 4);
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    rect = (u8 *)&gTabMenuTabRect;
    t2 = *(s16 *)(rect + 2);
    t6 = *(s16 *)(rect + 6);
    t0 = gTabMenuTabRect;
    t4 = *(s16 *)(rect + 4);
    Prim2D_SetRectUv(lbl_8036B6FC, lbl_8036B700, (f32)gTabMenuTabRect, (f32)*(s16 *)(rect + 2), (f32)(s16)(t4 - t0),
                     (f32)(s16)(t6 - t2));
    Prim2D_Begin();
    alpha = 0x40;
    if ((s32)*(u8 *)((u8 *)menu + 0x30) == 1) {
        alpha = 0x80;
    }
    Prim2D_SetAlphaByte((u8)alpha);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(*(s32 *)((u8 *)menu + 0x64), lbl_80332000, 5);
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    t2 = *(s16 *)(rect + 2);
    t6 = *(s16 *)(rect + 6);
    t0 = gTabMenuTabRect;
    t4 = *(s16 *)(rect + 4);
    Prim2D_SetRectUv(lbl_8036B704, lbl_8036B700, (f32)gTabMenuTabRect, (f32)*(s16 *)(rect + 2), (f32)(s16)(t4 - t0),
                     (f32)(s16)(t6 - t2));
    Prim2D_Begin();
    alpha = 0x40;
    if ((s32)*(u8 *)((u8 *)menu + 0x30) == 2) {
        alpha = 0x80;
    }
    Prim2D_SetAlphaByte((u8)alpha);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(*(s32 *)((u8 *)menu + 0x64), lbl_80332000, 6);
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    t2 = *(s16 *)(rect + 2);
    t6 = *(s16 *)(rect + 6);
    t0 = gTabMenuTabRect;
    t4 = *(s16 *)(rect + 4);
    Prim2D_SetRectUv(lbl_8036B708, lbl_8036B700, (f32)gTabMenuTabRect, (f32)*(s16 *)(rect + 2), (f32)(s16)(t4 - t0),
                     (f32)(s16)(t6 - t2));
    Prim2D_Begin();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
    fn_80056B0C(*(s32 *)((u8 *)menu + 0x60));
    fn_801E6CEC(menu);
    Prim2D_Begin();
    Prim2D_SetCallback((void *)fn_801E551C, 0);
    Prim2D_PrepareTex();
    switch ((s8)*(u8 *)((u8 *)menu + 0x30)) {
    case 0:
        TabMenu_DrawTab0(menu);
        break;
    case 1:
        TabMenu_DrawTab1(menu);
        break;
    case 2:
        TabMenu_DrawTab2(menu);
        break;
    }
    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
}
void fn_801E551C(void) {
    M2C_UNK GXSetScissor(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    GXSetScissor(0x20, 0x5A, 0x220, 0x136);
}

#pragma use_lmw_stmw on
void TabMenu_DrawTab2(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    s32 Text_MeasureHeight(s32, f32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SwapUvU(void);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_EndPrim(void);
    void *Msg_Expand(void *);
    void fn_8001003C(s32, s16, u8, s32, s32, void *, f32, f32);
    s32 Text_MeasureWidth(void *, s32, f32);
    u8 Status_Test(void *, u8);
    s8 fn_801E4A60(void *, u8);
    void fn_801E5C1C(void *, s16, s16, s16, s16, u8, void *);
    extern f32 lbl_8036B70C, lbl_8036B710, lbl_8036B714, gTabMenuOne, gTabMenuZero, lbl_8036B718, lbl_8036B71C;
    extern u8 gBattleState[];
    extern u8 lbl_80332000[];
    extern s16 lbl_8036833C;

    struct Node { struct Node *prev; struct Node *next; u8 *data; };

    u8 color[4];
    s32 color_word;
    void *self;
    struct Node *node;
    s16 *rect;
    void *tbl74;
    void *tbl84;
    s8 row;
    s8 t;
    s16 y0;
    s16 y1;
    s16 pad;
    s16 pad2;
    s16 y;
    s16 w;
    s16 x2;
    s16 yline;
    s32 rem;
    s32 page;
    s8 lim;
    u8 in_view;
    u8 mark;
    u8 sel;
    void *str;
    void *str2;
    s32 unk36;
    u8 *data;
    struct Node *cur;

    self = arg0;
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B70C, lbl_8036B710, lbl_8036B714, gTabMenuOne);
    Prim2D_PrepareTex();

    unk36 = *(s16 *)((u8 *)self + 0x36);
    node = *(struct Node **)((u8 *)self + 0x58);
    row = (s8)(unk36 / 32);
    t = row;
    if (row >= 0) {
        goto walk_fwd_chk;
        walk_fwd:
        node = node->next;
        t -= 1;
        walk_fwd_chk:
        if (t > 0) goto walk_fwd;
    } else {
        goto walk_back_chk;
        walk_back:
        node = node->prev;
        t += 1;
        walk_back_chk:
        if (t < 0) goto walk_back;
    }

    rem = unk36 % 32;
    y0 = (s16)(8 - rem);
    y1 = (s16)(y0 + ((0x20 - Text_MeasureHeight(-1, gTabMenuOne)) >> 1));
    tbl74 = gBattleState + 0x74;
    tbl84 = gBattleState + 0x84;
    goto loop_chk;

    loop_body:
    data = node->data;
    if ((s8)data[0] < 0) {
        pad = (s16)((0x20 - (s16)(((s16 *)&lbl_8036833C)[3] - ((s16 *)&lbl_8036833C)[1])) >> 1);
        pad2 = (s16)(pad + 0xC);
        Ui_LoadAtlasTex(*(s32 *)((u8 *)self + 0x64), lbl_80332000, 0xC);
        Prim2D_Begin();
        Prim2D_SetTex(lbl_80332000, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        y = (s16)((((s8)(row - (s8)page) << 5) + 8) - rem);
        yline = (s16)(y + pad);
        w = (s16)(((s16 *)&lbl_8036833C)[2] - ((s16 *)&lbl_8036833C)[0]);
        Prim2D_SetRectUv(lbl_8036B718, (f32)yline, (f32)((s16 *)&lbl_8036833C)[0], (f32)((s16 *)&lbl_8036833C)[1],
                    (f32)w, (f32)(s16)(((s16 *)&lbl_8036833C)[3] - ((s16 *)&lbl_8036833C)[1]));
        Prim2D_SwapUvU();
        x2 = (s16)(0x208 - (s16)(((s16 *)&lbl_8036833C)[2] - ((s16 *)&lbl_8036833C)[0]));
        Prim2D_Begin();
        Prim2D_SetTex(lbl_80332000, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x2, (f32)yline, (f32)((s16 *)&lbl_8036833C)[0], (f32)((s16 *)&lbl_8036833C)[1],
                    (f32)(s16)(((s16 *)&lbl_8036833C)[2] - ((s16 *)&lbl_8036833C)[0]), (f32)(s16)(((s16 *)&lbl_8036833C)[3] - ((s16 *)&lbl_8036833C)[1]));
        color[0] = 0xFF;
        w = (s16)(((s16 *)&lbl_8036833C)[2] - ((s16 *)&lbl_8036833C)[0]);
        color[1] = 0xFF;
        color[2] = 0xFF;
        x2 = (s16)(0x208 - w);
        color[3] = 0x4C;
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x12);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(4);
        {
            f32 fy = lbl_8036B71C + (f32)(s16)(y + pad2);
            Prim2D_SetPosCorners(lbl_8036B71C + (f32)(s16)(w + 8), fy,
                        lbl_8036B71C + (f32)x2, fy);
        }
        color_word = *(s32 *)color;
        Prim2D_SetColorPacked(&color_word);
        Prim2D_EndPrim();
    } else {
        if (fn_801E4A60(self, data[4]) == row) {
            str = Msg_Expand(((void **)*(void **)((u8 *)self + 0x4C))[(s8)data[4]]);
            sel = 0;
            t = (s8)*(u8 *)((u8 *)self + 0x33);
            cur = *(struct Node **)((u8 *)self + 0x58);
            {
                s8 idx = (s8)data[4];
                if (t >= 0) {
                    goto sel_fwd_chk;
                    sel_fwd:
                    cur = cur->next;
                    t -= 1;
                    sel_fwd_chk:
                    if (t > 0) goto sel_fwd;
                } else {
                    goto sel_back_chk;
                    sel_back:
                    cur = cur->prev;
                    t += 1;
                    sel_back_chk:
                    if (t < 0) goto sel_back;
                }
                switch ((s8)*(u8 *)((u8 *)self + 0x31)) {
                case 0:
                    sel = (u8)(idx == (s8)*(u8 *)((u8 *)self + 0x32));
                    break;
                case 1:
                    switch ((s8)*(u8 *)((u8 *)self + 0x30)) {
                    case 0:
                        sel = (u8)(idx == (s8)cur->data[2]);
                        break;
                    case 1:
                        sel = (u8)(idx == (s8)cur->data[1]);
                        break;
                    case 2:
                        sel = (u8)(idx == (s8)cur->data[4]);
                        break;
                    }
                    break;
                }
            }
            fn_801E5C1C(self, 0x13, (s16)(y0 + 3), 0x5A, 0x1A, sel, str);
        }
        mark = 0;
        if (Status_Test(tbl74, data[0]) != 0) {
            mark = 0x14;
            if (Status_Test(tbl84, data[0]) != 0) {
                mark = 1;
            }
        }
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        fn_8001003C(0x88, y1, mark, 1, 0, Msg_Expand(*(void **)(data + 0xC)),
                    gTabMenuOne, gTabMenuZero);
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        str2 = Msg_Expand(((void **)*(void **)((u8 *)self + 0x44))[(s8)data[2]]);
        {
            s16 x = (s16)(((0x58 - Text_MeasureWidth(str2, -1, gTabMenuOne)) >> 1) + 0x140);
            fn_8001003C(x, y1, mark, 1, 0, str2, gTabMenuOne, gTabMenuZero);
        }
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        fn_8001003C(0x1A0, y1, mark, 1, 0,
                    Msg_Expand(((void **)*(void **)((u8 *)self + 0x48))[(s8)data[1]]),
                    gTabMenuOne, gTabMenuZero);
    }

    node = node->next;
    y1 = (s16)(y1 + 0x20);
    y0 = (s16)(y0 + 0x20);
    row = (s8)(row + 1);

    loop_chk:
    unk36 = *(s16 *)((u8 *)self + 0x36);
    rem = unk36 % 32;
    page = unk36 / 32;
    lim = (s8)((s8)page + 8);
    if (rem != 0) {
        lim = (s8)((s8)page + 9);
    }
    in_view = 0;
    if ((s8)page <= row && row <= lim) {
        in_view = 1;
    }
    if (in_view != 0 && node != (struct Node *)((u8 *)self + 0x54)) {
        goto loop_body;
    }
}
void fn_801E5C1C(s32 unused, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8 arg5, void *arg6) {
    s32 fn_80010B78(void *, s32, f32);
    s32 fn_800102BC(s32, f32);
    void fn_8000A258(void);
    void fn_8000A174(s32, s32);
    void fn_8000A248(void);
    void fn_80007898(s32);
    void fn_80007790(f32, f32, f32, f32);
    void fn_80007668(s32 *);
    void fn_80007884(void);
    void fn_8001019C(s16, s16, u8, void *, ...);
    void fn_80009C0C(f32);
    void fn_800077D8(f32, f32, f32, f32);
    extern f32 lbl_8036B6E8;
    extern f32 lbl_8036B71C;
    extern f32 lbl_8036B720;
    extern f32 lbl_8036B724;
    u8 border[4];
    u8 fill[4];
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    f32 f_top;
    f32 f_right;
    f32 f_bottom;
    f32 f_left;
    s16 x;
    s16 y;
    s16 left;
    s16 top;
    s16 right;
    s16 bottom;
    s16 half_w;
    s16 half_h;
    u32 c;
    s16 tw;
    s32 th;
    s32 mode;
    s32 px;
    s32 py;

    tw = (s16)fn_80010B78(arg6, -1, lbl_8036B6E8);
    th = fn_800102BC(-1, lbl_8036B6E8);
    x = arg1;
    y = arg2;
    left = (s16)(x - 1);
    top = (s16)(y - 1);
    right = (s16)(x + arg3);
    bottom = (s16)(y + arg4);
    half_w = (s16)((arg3 - tw) >> 1);
    half_h = (s16)((arg4 - (s16)th) >> 1);

    c = 0x0B4A39FF;
    if (arg5 != 0) {
        c = 0x318D7FFF;
    }
    border[0] = (u8)(c >> 24);
    c = 0x0B4A39FF;
    if (arg5 != 0) {
        c = 0x318D7FFF;
    }
    border[1] = (u8)(c >> 16);
    c = 0x0B4A39FF;
    if (arg5 != 0) {
        c = 0x318D7FFF;
    }
    border[2] = (u8)(c >> 8);
    c = 0x0B4A39FF;
    if (arg5 != 0) {
        c = 0x318D7FFF;
    }
    border[3] = (u8)c;

    fill[0] = 0x1E;
    fill[1] = 0x1E;
    fill[2] = 0x1E;
    fill[3] = 0xFF;

    fn_8000A258();
    fn_8000A174(0, 0x12);
    fn_8000A248();
    fn_80007898(4);
    f_top = lbl_8036B71C + (f32)top;
    f_left = lbl_8036B71C + (f32)left;
    f_right = lbl_8036B71C + (f32)right;
    fn_80007790(f_left, f_top, f_right, f_top);
    sp14 = *(s32 *)border;
    fn_80007668(&sp14);
    fn_80007884();

    fn_8000A258();
    fn_8000A174(0, 0x12);
    fn_8000A248();
    fn_80007898(4);
    f_bottom = lbl_8036B71C + (f32)bottom;
    fn_80007790(f_right, f_top, f_right, f_bottom);
    sp10 = *(s32 *)border;
    fn_80007668(&sp10);
    fn_80007884();

    fn_8000A258();
    fn_8000A174(0, 0x12);
    fn_8000A248();
    fn_80007898(4);
    fn_80007790(f_right, f_bottom, f_left, f_bottom);
    spC = *(s32 *)border;
    fn_80007668(&spC);
    fn_80007884();

    fn_8000A258();
    fn_8000A174(0, 0x12);
    fn_8000A248();
    fn_80007898(4);
    fn_80007790(f_left, f_bottom, f_left, f_top);
    sp8 = *(s32 *)border;
    fn_80007668(&sp8);
    fn_80007884();

    fn_8000A258();
    fn_8000A174(0, 0x13);
    fn_8000A248();
    px = (s32)(s16)(x + half_w);
    py = y + half_h;
    mode = 0x16;
    if (arg5 != 0) {
        mode = 0x15;
    }
    fn_8001019C((s16)px, (s16)py, (u8)mode, arg6);

    fn_8000A258();
    fn_80009C0C(lbl_8036B720);
    fn_8000A248();

    fn_8000A258();
    fn_8000A174(0, 0x12);
    fn_8000A248();
    fn_80007898(1);
    fn_800077D8((f32)arg1, (f32)arg2, (f32)arg3, (f32)arg4);
    sp18 = *(s32 *)fill;
    fn_80007668(&sp18);

    fn_8000A258();
    fn_80009C0C(lbl_8036B724);
    fn_8000A248();
}

#pragma use_lmw_stmw on
void TabMenu_DrawTab1(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    s32 Text_MeasureHeight(s32, f32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SwapUvU(void);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_EndPrim(void);
    void *Msg_Expand(void *);
    void fn_8001003C(s32, s16, u8, s32, s32, void *, f32, f32);
    s32 Text_MeasureWidth(void *, s32, f32);
    u8 Status_Test(void *, u8);
    s8 fn_801E4A60(void *, u8);
    void fn_801E5C1C(void *, s16, s16, s16, s16, u8, void *);
    extern f32 lbl_8036B70C, lbl_8036B710, lbl_8036B714, gTabMenuOne, gTabMenuZero, lbl_8036B718, lbl_8036B71C;
    extern u8 gBattleState[];
    extern u8 lbl_80332000[];
    extern s16 lbl_8036833C;

    struct Node { struct Node *prev; struct Node *next; u8 *data; };

    u8 color[4];
    s32 color_word;
    void *self;
    struct Node *node;
    s16 *rect;
    void *tbl74;
    void *tbl84;
    s8 row;
    s8 t;
    s16 y0;
    s16 y1;
    s16 pad;
    s16 pad2;
    s16 y;
    s16 w;
    s16 x2;
    s16 yline;
    s32 rem;
    s32 page;
    s8 lim;
    u8 in_view;
    u8 mark;
    u8 sel;
    void *str;
    void *str2;
    s32 unk36;
    u8 *data;
    struct Node *cur;

    self = arg0;
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B70C, lbl_8036B710, lbl_8036B714, gTabMenuOne);
    Prim2D_PrepareTex();

    unk36 = *(s16 *)((u8 *)self + 0x36);
    node = *(struct Node **)((u8 *)self + 0x58);
    row = (s8)(unk36 / 32);
    t = row;
    if (row >= 0) {
        goto walk_fwd_chk;
        walk_fwd:
        node = node->next;
        t -= 1;
        walk_fwd_chk:
        if (t > 0) goto walk_fwd;
    } else {
        goto walk_back_chk;
        walk_back:
        node = node->prev;
        t += 1;
        walk_back_chk:
        if (t < 0) goto walk_back;
    }

    rem = unk36 % 32;
    y0 = (s16)(8 - rem);
    y1 = (s16)(y0 + ((0x20 - Text_MeasureHeight(-1, gTabMenuOne)) >> 1));
    rect = &lbl_8036833C;
    tbl74 = gBattleState + 0x74;
    tbl84 = gBattleState + 0x84;
    goto loop_chk;

    loop_body:
    data = node->data;
    if ((s8)data[0] < 0) {
        pad = (s16)((0x20 - (s16)(rect[3] - rect[1])) >> 1);
        pad2 = (s16)(pad + 0xC);
        Ui_LoadAtlasTex(*(s32 *)((u8 *)self + 0x64), lbl_80332000, 0xC);
        Prim2D_Begin();
        Prim2D_SetTex(lbl_80332000, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        y = (s16)((((s8)(row - (s8)page) << 5) + 8) - rem);
        yline = (s16)(y + pad);
        w = (s16)(rect[2] - rect[0]);
        Prim2D_SetRectUv(lbl_8036B718, (f32)yline, (f32)rect[0], (f32)rect[1],
                    (f32)w, (f32)(s16)(rect[3] - rect[1]));
        Prim2D_SwapUvU();
        x2 = (s16)(0x208 - (s16)(rect[2] - rect[0]));
        Prim2D_Begin();
        Prim2D_SetTex(lbl_80332000, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x2, (f32)yline, (f32)rect[0], (f32)rect[1],
                    (f32)(s16)(rect[2] - rect[0]), (f32)(s16)(rect[3] - rect[1]));
        color[0] = 0xFF;
        w = (s16)(rect[2] - rect[0]);
        color[1] = 0xFF;
        color[2] = 0xFF;
        x2 = (s16)(0x208 - w);
        color[3] = 0x4C;
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x12);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(4);
        {
            f32 fy = lbl_8036B71C + (f32)(s16)(y + pad2);
            Prim2D_SetPosCorners(lbl_8036B71C + (f32)(s16)(w + 8), fy,
                        lbl_8036B71C + (f32)x2, fy);
        }
        color_word = *(s32 *)color;
        Prim2D_SetColorPacked(&color_word);
        Prim2D_EndPrim();
    } else {
        if (fn_801E4A60(self, data[1]) == row) {
            str = Msg_Expand(((void **)*(void **)((u8 *)self + 0x48))[(s8)data[1]]);
            sel = 0;
            t = (s8)*(u8 *)((u8 *)self + 0x33);
            cur = *(struct Node **)((u8 *)self + 0x58);
            {
                s8 idx = (s8)data[1];
                if (t >= 0) {
                    goto sel_fwd_chk;
                    sel_fwd:
                    cur = cur->next;
                    t -= 1;
                    sel_fwd_chk:
                    if (t > 0) goto sel_fwd;
                } else {
                    goto sel_back_chk;
                    sel_back:
                    cur = cur->prev;
                    t += 1;
                    sel_back_chk:
                    if (t < 0) goto sel_back;
                }
                switch ((s8)*(u8 *)((u8 *)self + 0x31)) {
                case 0:
                    sel = (u8)(idx == (s8)*(u8 *)((u8 *)self + 0x32));
                    break;
                case 1:
                    switch ((s8)*(u8 *)((u8 *)self + 0x30)) {
                    case 0:
                        sel = (u8)(idx == (s8)cur->data[2]);
                        break;
                    case 1:
                        sel = (u8)(idx == (s8)cur->data[1]);
                        break;
                    case 2:
                        sel = (u8)(idx == (s8)cur->data[4]);
                        break;
                    }
                    break;
                }
            }
            fn_801E5C1C(self, 0x13, (s16)(y0 + 3), 0x5A, 0x1A, sel, str);
        }
        mark = 0;
        if (Status_Test(tbl74, data[0]) != 0) {
            mark = 0x14;
            if (Status_Test(tbl84, data[0]) != 0) {
                mark = 1;
            }
        }
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        fn_8001003C(0x88, y1, mark, 1, 0, Msg_Expand(*(void **)(data + 0xC)),
                    gTabMenuOne, gTabMenuZero);
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        str2 = Msg_Expand(((void **)*(void **)((u8 *)self + 0x44))[(s8)data[2]]);
        {
            s16 x = (s16)(((0x58 - Text_MeasureWidth(str2, -1, gTabMenuOne)) >> 1) + 0x140);
            fn_8001003C(x, y1, mark, 1, 0, str2, gTabMenuOne, gTabMenuZero);
        }
    }

    node = node->next;
    y1 = (s16)(y1 + 0x20);
    y0 = (s16)(y0 + 0x20);
    row = (s8)(row + 1);

    loop_chk:
    unk36 = *(s16 *)((u8 *)self + 0x36);
    rem = unk36 % 32;
    page = unk36 / 32;
    lim = (s8)((s8)page + 8);
    if (rem != 0) {
        lim = (s8)((s8)page + 9);
    }
    in_view = 0;
    if ((s8)page <= row && row <= lim) {
        in_view = 1;
    }
    if (in_view != 0 && node != (struct Node *)((u8 *)self + 0x54)) {
        goto loop_body;
    }
}

#pragma use_lmw_stmw on
void TabMenu_DrawTab0(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    s32 Text_MeasureHeight(s32, f32);
    void Ui_LoadAtlasTex(s32, void *, s32);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SwapUvU(void);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_EndPrim(void);
    void *Msg_Expand(void *);
    void fn_8001003C(s32, s16, u8, s32, s32, void *, f32, f32);
    u8 Status_Test(void *, u8);
    s8 fn_801E4A60(void *, u8);
    void fn_801E5C1C(void *, s16, s16, s16, s16, u8, void *);
    extern f32 lbl_8036B70C, lbl_8036B710, lbl_8036B714, gTabMenuOne, gTabMenuZero, lbl_8036B718, lbl_8036B71C;
    extern u8 gBattleState[];
    extern u8 lbl_80332000[];
    extern s16 lbl_8036833C[4];

    struct Node { struct Node *prev; struct Node *next; u8 *data; };

    u8 color[4];
    s32 color_word;
    void *self = arg0;
    struct Node *node;
    void *tbl74;
    void *tbl84;
    s8 row;
    s8 t;
    s16 y0;
    s16 y1;
    s16 pad;
    s16 pad2;
    s16 y;
    s16 w;
    s16 x2;
    s16 yline;
    s32 rem;
    s32 page;
    s8 lim;
    u8 in_view;
    u8 mark;
    u8 sel;
    void *str;
    s32 unk36;
    u8 *data;
    struct Node *cur;

    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B70C, lbl_8036B710, lbl_8036B714, gTabMenuOne);
    Prim2D_PrepareTex();

    unk36 = *(s16 *)((u8 *)self + 0x36);
    node = *(struct Node **)((u8 *)self + 0x58);
    row = (s8)(unk36 / 32);
    t = row;
    if (row >= 0) {
        goto walk_fwd_chk;
        walk_fwd:
        node = node->next;
        t -= 1;
        walk_fwd_chk:
        if (t > 0) goto walk_fwd;
    } else {
        goto walk_back_chk;
        walk_back:
        node = node->prev;
        t += 1;
        walk_back_chk:
        if (t < 0) goto walk_back;
    }

    rem = unk36 % 32;
    y0 = (s16)(8 - rem);
    y1 = (s16)(y0 + ((0x20 - Text_MeasureHeight(-1, gTabMenuOne)) >> 1));
    tbl74 = gBattleState + 0x74;
    tbl84 = gBattleState + 0x84;
    goto loop_chk;

    loop_body:
    data = node->data;
    if ((s8)data[0] < 0) {
        pad = (s16)((0x20 - (s16)(lbl_8036833C[3] - lbl_8036833C[1])) >> 1);
        pad2 = (s16)(pad + 0xC);
        Ui_LoadAtlasTex(*(s32 *)((u8 *)self + 0x64), lbl_80332000, 0xC);
        Prim2D_Begin();
        Prim2D_SetTex(lbl_80332000, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        y = (s16)((((s8)(row - (s8)page) << 5) + 8) - rem);
        yline = (s16)(y + pad);
        w = (s16)(lbl_8036833C[2] - lbl_8036833C[0]);
        Prim2D_SetRectUv(lbl_8036B718, (f32)yline, (f32)lbl_8036833C[0], (f32)lbl_8036833C[1],
                    (f32)w, (f32)(s16)(lbl_8036833C[3] - lbl_8036833C[1]));
        Prim2D_SwapUvU();
        x2 = (s16)(0x208 - (s16)(lbl_8036833C[2] - lbl_8036833C[0]));
        Prim2D_Begin();
        Prim2D_SetTex(lbl_80332000, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x2, (f32)yline, (f32)lbl_8036833C[0], (f32)lbl_8036833C[1],
                    (f32)(s16)(lbl_8036833C[2] - lbl_8036833C[0]), (f32)(s16)(lbl_8036833C[3] - lbl_8036833C[1]));
        color[0] = 0xFF;
        w = (s16)(lbl_8036833C[2] - lbl_8036833C[0]);
        color[1] = 0xFF;
        color[2] = 0xFF;
        x2 = (s16)(0x208 - w);
        color[3] = 0x4C;
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x12);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(4);
        {
            f32 fy = lbl_8036B71C + (f32)(s16)(y + pad2);
            Prim2D_SetPosCorners(lbl_8036B71C + (f32)(s16)(w + 8), fy,
                        lbl_8036B71C + (f32)x2, fy);
        }
        color_word = *(s32 *)color;
        Prim2D_SetColorPacked(&color_word);
        Prim2D_EndPrim();
    } else {
        if (fn_801E4A60(self, data[2]) == row) {
            str = Msg_Expand(((void **)*(void **)((u8 *)self + 0x44))[(s8)data[2]]);
            sel = 0;
            t = (s8)*(u8 *)((u8 *)self + 0x33);
            cur = *(struct Node **)((u8 *)self + 0x58);
            {
                s8 idx = (s8)data[2];
                if (t >= 0) {
                    goto sel_fwd_chk;
                    sel_fwd:
                    cur = cur->next;
                    t -= 1;
                    sel_fwd_chk:
                    if (t > 0) goto sel_fwd;
                } else {
                    goto sel_back_chk;
                    sel_back:
                    cur = cur->prev;
                    t += 1;
                    sel_back_chk:
                    if (t < 0) goto sel_back;
                }
                switch ((s8)*(u8 *)((u8 *)self + 0x31)) {
                case 0:
                    sel = (u8)(idx == (s8)*(u8 *)((u8 *)self + 0x32));
                    break;
                case 1:
                    switch ((s8)*(u8 *)((u8 *)self + 0x30)) {
                    case 0:
                        sel = (u8)(idx == (s8)cur->data[2]);
                        break;
                    case 1:
                        sel = (u8)(idx == (s8)cur->data[1]);
                        break;
                    case 2:
                        sel = (u8)(idx == (s8)cur->data[4]);
                        break;
                    }
                    break;
                }
            }
            fn_801E5C1C(self, 0x13, (s16)(y0 + 3), 0x5A, 0x1A, sel, str);
        }
        mark = 0;
        if (Status_Test(tbl74, data[0]) != 0) {
            mark = 0x14;
            if (Status_Test(tbl84, data[0]) != 0) {
                mark = 1;
            }
            mark = mark;
        }
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        fn_8001003C(0x88, y1, mark, 1, 0, Msg_Expand(*(void **)(data + 0xC)),
                    gTabMenuOne, gTabMenuZero);
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        fn_8001003C(0x148, y1, mark, 1, 0,
                    Msg_Expand(((void **)*(void **)((u8 *)self + 0x48))[(s8)data[1]]),
                    gTabMenuOne, gTabMenuZero);
    }

    node = node->next;
    y1 = (s16)(y1 + 0x20);
    y0 = (s16)(y0 + 0x20);
    row = (s8)(row + 1);

    loop_chk:
    unk36 = *(s16 *)((u8 *)self + 0x36);
    rem = unk36 % 32;
    page = unk36 / 32;
    lim = (s8)((s8)page + 8);
    if (rem != 0) {
        lim = (s8)((s8)page + 9);
    }
    in_view = 0;
    if ((s8)page <= row && row <= lim) {
        in_view = 1;
    }
    if (in_view != 0 && node != (struct Node *)((u8 *)self + 0x54)) {
        goto loop_body;
    }
}

#pragma peephole off
void fn_801E6CEC(void *arg0) {
    typedef struct { s16 x, y, x2, y2; } Rect;
    typedef struct { u8 r, g, b, a; } Color;
    void fn_80007358(f32, f32);
    void Prim2D_SetColorPacked(Color *);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_SetUvRect(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void fn_80057020(void *);
    void Ui_LoadAtlasTex(void *, void *, s32);
    extern u8 lbl_80332000[];
    extern Rect lbl_80368304;
    extern Rect lbl_8036831C;
    extern Rect lbl_80368324;
    extern Rect lbl_8036832C;
    extern Rect lbl_80368334;
    extern Rect lbl_80368344;
    extern Rect lbl_8036834C;
    extern Rect lbl_80368354;
    extern u16 lbl_8036B6D8;
    extern u8 lbl_8036B6DA;
    extern f32 gTabMenuOne;
    extern f32 gTabMenuZero;
    extern f32 gTabMenuZ;
    extern f32 lbl_8036B70C;
    extern f32 lbl_8036B710;
    extern f32 lbl_8036B71C;
    extern f32 lbl_8036B728;
    extern f32 lbl_8036B72C;
    extern f32 lbl_8036B730;
    extern f32 lbl_8036B734;
    extern f32 lbl_8036B738;
    extern f32 lbl_8036B73C;
    extern f32 lbl_8036B740;
    extern f32 lbl_8036B744;
    extern f32 lbl_8036B748;
    extern f32 lbl_8036B74C;
    extern f32 lbl_8036B750;
    extern f32 lbl_8036B754;

    Color c1, c0;
    Color tmp;
    u8 pal[3];
    s16 h;
    s16 y0;
    f32 fy0, fy1;
    s16 w1, w2, w3, h2;
    s16 xL, xR;

    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B70C, lbl_8036B728, gTabMenuZ, gTabMenuOne);
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
    *(u16 *)pal = lbl_8036B6D8;
    pal[2] = lbl_8036B6DA;
    Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, pal[(s8)((u8 *)arg0)[0x30]]);
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv(gTabMenuZero, gTabMenuZero, (f32)lbl_80368304.x, (f32)lbl_80368304.y, (f32)(s16)(lbl_80368304.x2 - lbl_80368304.x), (f32)(s16)(lbl_80368304.y2 - lbl_80368304.y));
    h = (s16)(lbl_80368304.y2 - lbl_80368304.y);
    c0.r = 0xC5; c0.g = 0xA6; c0.b = 0x4B; c0.a = 0xFF;
    c1.r = 0x66; c1.g = 0x45; c1.b = 0x18; c1.a = 0xFF;
    Prim2D_Begin();
    Prim2D_SetTex(NULL, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    y0 = (s16)(h + 0x136);
    fy0 = lbl_8036B71C + (f32)h;
    fy1 = lbl_8036B71C + (f32)y0;
    Prim2D_SetPosCorners(lbl_8036B71C, fy0, lbl_8036B71C, fy1);
    tmp = c0;
    Prim2D_SetColorPacked(&tmp);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTex(NULL, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_8036B72C, fy0, lbl_8036B72C, fy1);
    tmp = c1;
    Prim2D_SetColorPacked(&tmp);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTex(NULL, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_8036B730, fy0, lbl_8036B730, fy1);
    tmp = c0;
    Prim2D_SetColorPacked(&tmp);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTex(NULL, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_8036B734, fy0, lbl_8036B734, fy1);
    tmp = c1;
    Prim2D_SetColorPacked(&tmp);
    Prim2D_EndPrim();
    Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 0xD);
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv(gTabMenuZero, (f32)y0, (f32)lbl_80368344.x, (f32)lbl_80368344.y, (f32)(s16)(lbl_80368344.x2 - lbl_80368344.x), (f32)(s16)(lbl_80368344.y2 - lbl_80368344.y));
    Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 0xE);
    w1 = (s16)(lbl_80368344.x2 - lbl_80368344.x);
    w2 = (s16)(lbl_80368354.x2 - lbl_80368354.x);
    h2 = (s16)(lbl_8036834C.y2 - lbl_8036834C.y);
    w3 = (s16)((0x220 - w1) - w2);
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(9);
    Prim2D_SetRect((f32)w1, (f32)y0, (f32)w3, (f32)h2);
    Prim2D_SetUvRect((f32)lbl_8036834C.x, (f32)lbl_8036834C.y, (f32)lbl_8036834C.x, (f32)lbl_8036834C.y, (f32)(s16)(lbl_8036834C.x2 - lbl_8036834C.x), (f32)(s16)(lbl_8036834C.y2 - lbl_8036834C.y));
    fn_80007358(gTabMenuZero, gTabMenuZero);
    Prim2D_EndPrim();
    Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 0xF);
    xR = (s16)(0x220 - (s16)(lbl_80368354.x2 - lbl_80368354.x));
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv((f32)xR, (f32)y0, (f32)lbl_80368354.x, (f32)lbl_80368354.y, (f32)(s16)(lbl_80368354.x2 - lbl_80368354.x), (f32)(s16)(lbl_80368354.y2 - lbl_80368354.y));
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B70C, lbl_8036B710, gTabMenuZ, gTabMenuOne);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B738);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 8);
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(9);
    Prim2D_SetRect(gTabMenuZero, gTabMenuZero, lbl_8036B73C, lbl_8036B740);
    Prim2D_SetUvRect((f32)lbl_8036831C.x, (f32)lbl_8036831C.y, (f32)lbl_8036831C.x, (f32)lbl_8036831C.y, (f32)(s16)(lbl_8036831C.x2 - lbl_8036831C.x), (f32)(s16)(lbl_8036831C.y2 - lbl_8036831C.y));
    fn_80007358(gTabMenuZero, gTabMenuZero);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTransform(gTabMenuZero, gTabMenuZero, gTabMenuZ, gTabMenuOne);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B70C, lbl_8036B710, lbl_8036B744, gTabMenuOne);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 9);
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv(lbl_8036B748, lbl_8036B74C, (f32)lbl_80368324.x, (f32)lbl_80368324.y, (f32)(s16)(lbl_80368324.x2 - lbl_80368324.x), (f32)(s16)(lbl_80368324.y2 - lbl_80368324.y));
    Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 0xA);
    h2 = (s16)(lbl_80368324.y2 - lbl_80368324.y);
    w2 = (s16)(lbl_80368334.y2 - lbl_80368334.y);
    w3 = (s16)((0x12E - h2) - w2);
    w1 = (s16)(lbl_8036832C.x2 - lbl_8036832C.x);
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(9);
    Prim2D_SetRect(lbl_8036B748, (f32)(s16)(h2 + 4), (f32)w1, (f32)w3);
    Prim2D_SetUvRect((f32)lbl_8036832C.x, (f32)lbl_8036832C.y, (f32)lbl_8036832C.x, (f32)lbl_8036832C.y, (f32)(s16)(lbl_8036832C.x2 - lbl_8036832C.x), (f32)(s16)(lbl_8036832C.y2 - lbl_8036832C.y));
    fn_80007358(gTabMenuZero, gTabMenuZero);
    Prim2D_EndPrim();
    Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 0xB);
    xL = (s16)(0x132 - (s16)(lbl_80368334.y2 - lbl_80368334.y));
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv(lbl_8036B748, (f32)xL, (f32)lbl_80368334.x, (f32)lbl_80368334.y, (f32)(s16)(lbl_80368334.x2 - lbl_80368334.x), (f32)(s16)(lbl_80368334.y2 - lbl_80368334.y));
    Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 9);
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv(lbl_8036B750, lbl_8036B74C, (f32)lbl_80368324.x, (f32)lbl_80368324.y, (f32)(s16)(lbl_80368324.x2 - lbl_80368324.x), (f32)(s16)(lbl_80368324.y2 - lbl_80368324.y));
    Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 0xA);
    h2 = (s16)(lbl_80368324.y2 - lbl_80368324.y);
    w2 = (s16)(lbl_80368334.y2 - lbl_80368334.y);
    w3 = (s16)((0x12E - h2) - w2);
    w1 = (s16)(lbl_8036832C.x2 - lbl_8036832C.x);
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(9);
    Prim2D_SetRect(lbl_8036B750, (f32)(s16)(h2 + 4), (f32)w1, (f32)w3);
    Prim2D_SetUvRect((f32)lbl_8036832C.x, (f32)lbl_8036832C.y, (f32)lbl_8036832C.x, (f32)lbl_8036832C.y, (f32)(s16)(lbl_8036832C.x2 - lbl_8036832C.x), (f32)(s16)(lbl_8036832C.y2 - lbl_8036832C.y));
    fn_80007358(gTabMenuZero, gTabMenuZero);
    Prim2D_EndPrim();
    Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 0xB);
    xL = (s16)(0x132 - (s16)(lbl_80368334.y2 - lbl_80368334.y));
    Prim2D_Begin();
    Prim2D_SetTex(lbl_80332000, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRectUv(lbl_8036B750, (f32)xL, (f32)lbl_80368334.x, (f32)lbl_80368334.y, (f32)(s16)(lbl_80368334.x2 - lbl_80368334.x), (f32)(s16)(lbl_80368334.y2 - lbl_80368334.y));
    if ((s32)((u8 *)arg0)[0x30] == 2) {
        Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 9);
        Prim2D_Begin();
        Prim2D_SetTex(lbl_80332000, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_8036B754, lbl_8036B74C, (f32)lbl_80368324.x, (f32)lbl_80368324.y, (f32)(s16)(lbl_80368324.x2 - lbl_80368324.x), (f32)(s16)(lbl_80368324.y2 - lbl_80368324.y));
        Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 0xA);
        h2 = (s16)(lbl_80368324.y2 - lbl_80368324.y);
        w2 = (s16)(lbl_80368334.y2 - lbl_80368334.y);
        w3 = (s16)((0x12E - h2) - w2);
        w1 = (s16)(lbl_8036832C.x2 - lbl_8036832C.x);
        Prim2D_Begin();
        Prim2D_SetTex(lbl_80332000, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(9);
        Prim2D_SetRect(lbl_8036B754, (f32)(s16)(h2 + 4), (f32)w1, (f32)w3);
        Prim2D_SetUvRect((f32)lbl_8036832C.x, (f32)lbl_8036832C.y, (f32)lbl_8036832C.x, (f32)lbl_8036832C.y, (f32)(s16)(lbl_8036832C.x2 - lbl_8036832C.x), (f32)(s16)(lbl_8036832C.y2 - lbl_8036832C.y));
        fn_80007358(gTabMenuZero, gTabMenuZero);
        Prim2D_EndPrim();
        Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x64), lbl_80332000, 0xB);
        xL = (s16)(0x132 - (s16)(lbl_80368334.y2 - lbl_80368334.y));
        Prim2D_Begin();
        Prim2D_SetTex(lbl_80332000, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_8036B754, (f32)xL, (f32)lbl_80368334.x, (f32)lbl_80368334.y, (f32)(s16)(lbl_80368334.x2 - lbl_80368334.x), (f32)(s16)(lbl_80368334.y2 - lbl_80368334.y));
    }
    fn_80057020(*(void **)((u8 *)arg0 + 0x5C));
}
#pragma push
#pragma optimization_level 4
#pragma peephole on
#pragma opt_propagation off
#pragma opt_lifetimes off
#pragma opt_common_subs off
void TabMenu_DrawHud(void *arg0) {
    f32 Math_Ease(s32, u8, f32, f32, f32, f32);
    void Prim2D_SetColorByte(s32);
    void fn_80009C20( f32, f32, f32, f32, f32, f32, f32, f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    s32 Text_MeasureHeight(s32, s32, f32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    void Ui_DrawRouteIconEx(s16, s16, s32);
    void fn_801E7FC0(void *);
    extern f64 lbl_8036B6E0;
    extern f32 gTabMenuOne;
    extern f32 gTabMenuZero;
    extern f32 lbl_8036B718;
    extern f32 lbl_8036B758;
    extern f32 lbl_8036B75C;
    extern f32 lbl_8036B760;
    extern f32 lbl_8036B764;
    extern f32 lbl_8036B768;
    extern f32 lbl_8036B76C;
    extern f32 lbl_8036B770;
    extern f64 lbl_8036B778;

    void *self;
    s8 row;
    s32 mode;
    s32 div;
    s16 y;
    s16 x;
    s32 flag;
    s32 m;
    f32 fade;
    f32 scale;
    s16 xpos;
    s16 drawX;
    s16 drawY;

    self = arg0;
    Prim2D_Begin();
    Prim2D_SetTransform(gTabMenuZero, gTabMenuZero, lbl_8036B758, gTabMenuOne);
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();

    mode = (s8)*(u8 *)((u8 *)self + 0x31);
    switch (mode) {
    case 0:
        fn_801E7FC0(self);
        break;
    case 1:
        div = *(s16 *)((u8 *)self + 0x38) / 32;
        row = (s8)*(u8 *)((u8 *)self + 0x33) - div;
        y = (s16)((0x20 - Text_MeasureHeight(-1, div, gTabMenuOne)) >> 1);
        x = *(s16 *)((u8 *)self + 0x3C);
        y = (s16)((s16)(y + 0x62) + (row << 5));
        if (x < 0 || *(s16 *)((u8 *)self + 0x3E) < 0) {
            *(s16 *)((u8 *)self + 0x3C) = 0xA0;
            *(s16 *)((u8 *)self + 0x3E) = y;
        } else {
            s32 targetX = (x + 0xA1) >> 1;
            s32 targetY = y + 1;
            *(s16 *)((u8 *)self + 0x3C) = targetX;
            *(s16 *)((u8 *)self + 0x3E) = (s16)((targetY + *(s16 *)((u8 *)self + 0x3E)) >> 1);
        }
        drawX = *(s16 *)((u8 *)self + 0x3C);
        drawY = *(s16 *)((u8 *)self + 0x3E);
        flag = 0;
        if (*(u8 *)((u8 *)self + 0x2D) == 0 && *(u8 *)((u8 *)self + 0x2E) == 0) {
            flag = 1;
        }
        Ui_DrawRouteIconEx(drawX, drawY, flag);
        break;
    }

    m = *(u8 *)((u8 *)self + 0x31);
    if (m == 1) {
        if (*(u8 *)((u8 *)arg0 + 0x34) < 8) {
            *(u8 *)((u8 *)self + 0x34) = *(u8 *)((u8 *)self + 0x34) + 1;
        }
    } else if (*(u8 *)((u8 *)arg0 + 0x34) != 0) {
        *(u8 *)((u8 *)self + 0x34) = *(u8 *)((u8 *)self + 0x34) - 1;
    }

    fade = Math_Ease(5, *(u8 *)((u8 *)self + 0x34), gTabMenuZero, gTabMenuOne, (f32)*(u8 *)((u8 *)self + 0x34), lbl_8036B718);
    div = *(s16 *)((u8 *)self + 0x38) / 32;
    row = (s8)*(u8 *)((u8 *)self + 0x33) - div;
    scale = (f32)*(u8 *)((u8 *)self + 0x34) * lbl_8036B75C;
    Prim2D_Begin();
    xpos = (s16)((row << 5) + 0x62);
    fn_80009C20(lbl_8036B760, (f32)xpos, lbl_8036B764, lbl_8036B768, lbl_8036B76C, scale, scale, gTabMenuZero);
    Prim2D_SetColorByte((s32)(lbl_8036B770 * fade));
    Prim2D_PrepareTex();
    fn_8008AB7C(0xC4, 0x10, 0x188, 0x18, 0x19, 0x4B, 1);
    Prim2D_Begin();
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
}
#pragma pop
#pragma optimization_level reset
#pragma peephole on
void fn_801E7FC0(void *arg0) {
    s32 Text_MeasureHeight(s32, s32, f32);
    void Ui_DrawRouteIconEx(s16, s16, s32);
    s32 fn_801E4A60(void *, s8);
    extern f32 gTabMenuOne;
    void *self;
    s8 row;
    s8 v;
    s16 x;
    s16 y;
    s32 flag;
    s32 y1;
    self = arg0;
    v = (s8)fn_801E4A60(self, (s8)*(u8 *)((u8 *)self + 0x32));
    row = (s8)(v - (*(s16 *)((u8 *)self + 0x38) / 32));
    y = (s16)((0x20 - Text_MeasureHeight(-1, v, gTabMenuOne)) >> 1);
    x = *(s16 *)((u8 *)self + 0x3C);
    y = (s16)((s16)(y + 0x62) + (row << 5));
    if (x < 0 || *(s16 *)((u8 *)self + 0x3E) < 0) {
        *(s16 *)((u8 *)self + 0x3C) = 0x28;
        *(s16 *)((u8 *)self + 0x3E) = y;
    } else {
        y1 = (s16)(y + 1);
        *(s16 *)((u8 *)self + 0x3C) = (s16)((x + 0x29) >> 1);
        *(s16 *)((u8 *)self + 0x3E) = (s16)((*(s16 *)((u8 *)self + 0x3E) + y1) >> 1);
    }
    flag = 0;
    x = *(s16 *)((u8 *)self + 0x3C);
    y = *(s16 *)((u8 *)self + 0x3E);
    if (*(u8 *)((u8 *)self + 0x2D) == 0 && *(u8 *)((u8 *)self + 0x2E) == 0) flag = 1;
    Ui_DrawRouteIconEx(x, y, flag);
}

void fn_801E80B4(void *arg0) {
    u8 fn_801E8B38(void *, void *, s8);
    s32 Abs(s32);
    void Process_ClearFunc(void *);
    void Process_Goto(void *, s32);
    void fn_80057860(void *, s16);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void fn_801E4900(s16 *, void *);
    void Ui_ShowUnitInfoText(void *, void *, f32, f32);
    void Ui_PlaySeCue(void *, s32);
    u8 fn_801E85A4(void *, s8);
    void *Msg_Expand(void *);
    void TextBanner_SetString(void *, void *);
    extern u32 *gPadInput;
    extern u8 gUnitInfoPopup[];
    extern u8 gTabMenuStrings[];
    extern f64 lbl_8036B6E0;
    s16 sp14[2];
    s16 sp1C[2];
    s16 sp10[2];
    s16 sp18[2];
    s8 old33;
    u8 *p33;
    u32 held;
    u32 buttons;
    u32 cur;
    u32 *pad;
    u8 t;
    s32 max;
    s16 pos;
    s16 tgt;
    s32 pos32;
    s32 tgt32;
    void *str;
    void **node;
    s8 idx;
    s8 mode;
    u8 b;
    s32 zero;

    pad = gPadInput;
    t = *(u8 *)((u8 *)arg0 + 0x33);
    p33 = (u8 *)((u8 *)arg0 + 0x33);
    held = *(u32 *)((u8 *)pad + 0x10);
    old33 = (s8)t;
    cur = *(u32 *)((u8 *)pad + 4);
    buttons = cur & (*(u32 *)((u8 *)pad + 8) ^ cur);
    max = *(s32 *)((u8 *)arg0 + 0x50);

    if (held & 0x08000008U) {
        t = *p33;
        if ((s8)t == 0) {
            if (buttons == held) {
                *p33 = (u8)(max - 1);
            }
        } else {
            *p33 = (u8)(t - 1);
        }
    } else if (held & 0x04000004U) {
        t = *p33;
        max = max - 1;
        if ((u32)max == (u32)(s8)t) {
            if (buttons == held) {
                *p33 = 0;
            }
        } else {
            *p33 = (u8)(t + 1);
        }
    }

    t = *p33;
    if (old33 != (s8)t) {
        if (fn_801E8B38(arg0, p33, old33) != 0) {
            if (Abs((s32)(old33 - (s8)*p33)) <= 2) {
                pos = *(s16 *)((u8 *)arg0 + 0x36);
                tgt = *(s16 *)((u8 *)arg0 + 0x38);
                if (pos == tgt) {
                    Process_ClearFunc(arg0);
                } else {
                    pos32 = pos;
                    tgt32 = tgt;
                    if (pos32 < tgt32) {
                        *(s16 *)((u8 *)arg0 + 0x36) = (s16)(*(s16 *)((u8 *)arg0 + 0x3A) + pos);
                    } else {
                        *(s16 *)((u8 *)arg0 + 0x36) = (s16)(pos - *(s16 *)((u8 *)arg0 + 0x3A));
                    }
                    fn_80057860(*(void **)((u8 *)arg0 + 0x5C), *(s16 *)((u8 *)arg0 + 0x36));
                    if (*(s16 *)((u8 *)arg0 + 0x36) == *(s16 *)((u8 *)arg0 + 0x38)) {
                        Process_ClearFunc(arg0);
                    }
                }
                Process_Goto(arg0, 4);
            } else if ((s8)*p33 < old33) {
                *(s16 *)((u8 *)arg0 + 0x36) = 0;
                *(s16 *)((u8 *)arg0 + 0x38) = 0;
                fn_80057860(*(void **)((u8 *)arg0 + 0x5C), *(s16 *)((u8 *)arg0 + 0x36));
            } else {
                *(s16 *)((u8 *)arg0 + 0x36) = *(s16 *)((u8 *)arg0 + 0x38);
                fn_80057860(*(void **)((u8 *)arg0 + 0x5C), *(s16 *)((u8 *)arg0 + 0x36));
            }
        }
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            fn_801E4900(sp14, arg0);
            str = NULL;
            *(s32 *)sp1C = *(s32 *)sp14;
            switch ((s8)*(u8 *)((u8 *)arg0 + 0x31)) {
            case 0:
                str = gTabMenuStrings + 0x15B;
                break;
            case 1:
                str = gTabMenuStrings + 0x166;
                break;
            }
            Ui_ShowUnitInfoText(gUnitInfoPopup, str, (f32)sp1C[0], (f32)sp1C[1]);
        }
        Ui_PlaySeCue(gTabMenuStrings + 0x199, 0x64);
        return;
    }

    if (buttons & 0x01000001U) {
        node = *(void ***)((u8 *)arg0 + 0x58);
        idx = (s8)t;
        if (idx >= 0) {
            while (idx > 0) {
                node = (void **)node[1];
                idx = (s8)(idx - 1);
            }
        } else {
            while (idx < 0) {
                node = (void **)*node;
                idx = (s8)(idx + 1);
            }
        }
        mode = (s8)*(u8 *)((u8 *)arg0 + 0x30);
        switch (mode) {
        case 0:
            b = ((u8 *)node[2])[2];
            break;
        case 1:
            b = ((u8 *)node[2])[1];
            break;
        case 2:
            b = ((u8 *)node[2])[4];
            break;
        }
        *(u8 *)((u8 *)arg0 + 0x32) = b;
        zero = 0;
        *(u8 *)((u8 *)arg0 + 0x31) = (u8)zero;
        switch (zero) {
        case 0:
            TextBanner_SetString(*(void **)((u8 *)arg0 + 0x60), Msg_Expand(gTabMenuStrings + 0x182));
            break;
        case 1:
            TextBanner_SetString(*(void **)((u8 *)arg0 + 0x60), Msg_Expand(gTabMenuStrings + 0x18D));
            break;
        }
        if (fn_801E85A4(arg0, (s8)*(u8 *)((u8 *)arg0 + 0x32)) != 0) {
            *(s16 *)((u8 *)arg0 + 0x3A) = 0x10;
            pos = *(s16 *)((u8 *)arg0 + 0x36);
            tgt = *(s16 *)((u8 *)arg0 + 0x38);
            if (pos == tgt) {
                Process_ClearFunc(arg0);
            } else {
                pos32 = pos;
                tgt32 = tgt;
                if (pos32 < tgt32) {
                    *(s16 *)((u8 *)arg0 + 0x36) = (s16)(*(s16 *)((u8 *)arg0 + 0x3A) + pos);
                } else {
                    *(s16 *)((u8 *)arg0 + 0x36) = (s16)(pos - *(s16 *)((u8 *)arg0 + 0x3A));
                }
                fn_80057860(*(void **)((u8 *)arg0 + 0x5C), *(s16 *)((u8 *)arg0 + 0x36));
                if (*(s16 *)((u8 *)arg0 + 0x36) == *(s16 *)((u8 *)arg0 + 0x38)) {
                    Process_ClearFunc(arg0);
                }
            }
            Process_Goto(arg0, 4);
        }
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            fn_801E4900(sp10, arg0);
            str = NULL;
            *(s32 *)sp18 = *(s32 *)sp10;
            switch ((s8)*(u8 *)((u8 *)arg0 + 0x31)) {
            case 0:
                str = gTabMenuStrings + 0x15B;
                break;
            case 1:
                str = gTabMenuStrings + 0x166;
                break;
            }
            Ui_ShowUnitInfoText(gUnitInfoPopup, str, (f32)sp18[0], (f32)sp18[1]);
        }
        Ui_PlaySeCue(gTabMenuStrings + 0x13F, 0x64);
    }
}

#pragma global_optimizer on
s32 fn_801E85A4(void *arg0, s32 arg1) {
    s8 fn_801E4A60(void);
    s32 fn_801E8734(void *, s32);
    s32 fn_801E87EC(void *, s32);
    s8 fn_801E8920(void *, s32);
    s32 result;
    s8 v0;
    s8 v1;
    s8 field50;
    s16 f36;
    s32 q;
    s32 rem;
    s32 band;
    u8 inrange;

    result = 0;
    v0 = fn_801E4A60();
    v1 = fn_801E8920(arg0, arg1);
    field50 = *(s32 *)((u8 *)arg0 + 0x50);
    if (v0 > 0) {
        v0 -= 1;
    }
    if (v1 < field50 - 1) {
        v1 += 1;
    }
    f36 = *(s16 *)((u8 *)arg0 + 0x36);
    q = f36 / 32;
    rem = f36 % 32;
    band = (s8)q + 8;
    if (rem != 0) {
        band = (s8)q + 9;
    }
    inrange = 0;
    if ((s8)q <= v0) {
        if (v0 <= (s8)band) {
            inrange = 1;
        }
    }
    if (inrange == 0) {
        if ((s8)q < v0) {
            result = fn_801E87EC(arg0, arg1);
        } else {
            result = fn_801E8734(arg0, arg1);
        }
    } else {
        band = (s8)q + 8;
        if (rem != 0) {
            band = (s8)q + 9;
        }
        inrange = 0;
        if ((s8)q <= v1) {
            if (v1 <= (s8)band) {
                inrange = 1;
            }
        }
        if (inrange == 0) {
            if ((s8)q < v1) {
                result = fn_801E87EC(arg0, arg1);
            } else {
                result = fn_801E8734(arg0, arg1);
            }
        }
    }
    return result;
}

#pragma push
#pragma optimization_level 3
#pragma opt_common_subs off
s32 fn_801E8734(void *arg0) {
    s8 fn_801E4A60();
    s32 v;
    s32 lower;
    s32 q, r, lo;
    u8 ok;
    s8 count;
    count = fn_801E4A60();
    if (count > 0) count--;
    v = M2C_FIELD(arg0, s16 *, 0x36);
    q = v / 32;
    lower = (s8)q;
    lo = lower + 8;
    if (v % 32 != 0) lo = lower + 9;
    { s32 upper = (s8)lo; s32 index = (s8)count;
    ok = 0;
    if (lower <= index && index <= upper) ok = 1;
    }
    if (!ok) {
        M2C_FIELD(arg0, s16 *, 0x38) = v - ((s8)((s8)q - count) << 5);
        return 1;
    }
    return 0;
}
#pragma push
#pragma optimization_level 2
#pragma opt_common_subs off
s32 fn_801E87EC(void *arg0, s32 arg1)
{
  s8 fn_801E4A60();
  s8 fn_801E8920(void *, s32);
  s8 v0;
  s8 v1;
  s32 f36;
  s32 q;
  s32 rem;
  s32 band;
  s32 t;
  s32 lower;
  s32 first;
  s32 last;
  u8 inrange;
  v0 = fn_801E4A60();
  v1 = fn_801E8920(arg0, arg1);
  if (v0 > 0)
  {
    v0--;
  }
  if (((u32) v1) < ((u32) ((*((s32 *) (((s8 *) arg0) + 0x50))) - 1)))
  {
    v1++;
  }
  f36 = *((s16 *) (((s8 *) arg0) + 0x36));
  q = f36 / 32;
  first = v0;
  last = v1;
  t = (s8) ((last - first) + 1);
  rem = f36 % 32;
  lower = (s8) q;
  band = lower + 8;
  if (rem)
  {
    band = lower + 9;
  }
  {
    s32 index = v1;
    s32 upper = (s8) band;
    inrange = 0;
    if ((lower <= index) && (index <= upper))
    {
      inrange = 1;
      rem = f36 % 32;
    }
  }
  if (!inrange)
  {
    if (t <= 9)
    {
      *((s16 *) (((s8 *) arg0) + 0x38)) = (((s8) (last - (((s8) q) + 8))) << 5) + f36;
    }
    else
    {
      *((s16 *) (((s8 *) arg0) + 0x38)) = f36 - (((s8) (((s8) q) - first)) << 5);
    }
    return 1;
  }
  return 0;
}
#pragma pop
s8 fn_801E8920(void *arg0, s32 arg1) {
    typedef struct Frame {
        u8 sp8;
        u8 pad9[3];
        u8 spC;
        u8 padD[3];
        u8 sp10;
        u8 pad11[3];
        u8 sp14;
        u8 pad15[3];
        u8 sp18;
        u8 pad19[3];
        u8 sp1C;
        u8 pad1D[3];
        void *sp20;
        void *sp24;
        void *sp28;
        void *sp2C;
        void *sp30;
        void *sp34;
        void *sp38;
        void *sp3C;
        void *sp40;
        void *sp44;
        void *sp48;
        void *sp4C;
        void *sp50;
        void *sp54;
        void *sp58;
        void *sp5C;
        void *sp60;
        void *sp64;
        void *sp68;
        void *sp6C;
        void *sp70;
        void *sp74;
    } Frame;
    Frame fr;
    Frame *p;
    void *head;
    void *tail;
    u8 match;
    void *node;
    void *data;
    s8 key;
    s8 count;
    s8 flag;
    s8 mode;

    p = &fr;
    mode = *(s8 *)((char *)arg0 + 0x30);
    head = (char *)arg0 + 0x54;
    tail = *(void **)((char *)arg0 + 0x58);

    p->sp3C = head;
    p->sp38 = head;
    p->sp34 = head;
    p->sp30 = head;
    p->sp70 = head;
    p->sp2C = tail;
    p->sp28 = tail;
    p->sp24 = tail;
    p->sp20 = tail;
    p->sp6C = tail;

    switch (mode) {
    case 0:
        p->sp18 = (u8)arg1;
        p->sp1C = (u8)arg1;
        key = (s8)(arg1 & 0xFF);
        p->sp60 = tail;
        p->sp64 = p->sp70;
        goto cond0;
    incr0:
        p->sp64 = node;
    cond0:
        if (*(void *volatile *)&p->sp64 == tail)
            break;
        match = 0;
        node = *(void **)*(void *volatile *)&p->sp64;
        data = *(void **)((char *)node + 8);
        if ((s8)*(u8 *)data >= 0) {
            if (key == (s8)*((u8 *)data + 2))
                match = 1;
        }
        if (!match)
            goto incr0;
        p->sp68 = p->sp64;
        p->sp74 = p->sp64;
        break;
    case 1:
        p->sp10 = (u8)arg1;
        p->sp14 = (u8)arg1;
        key = (s8)(arg1 & 0xFF);
        p->sp54 = tail;
        p->sp58 = p->sp70;
        goto cond1;
    incr1:
        p->sp58 = node;
    cond1:
        if (*(void *volatile *)&p->sp58 == tail)
            break;
        match = 0;
        node = *(void **)*(void *volatile *)&p->sp58;
        data = *(void **)((char *)node + 8);
        if ((s8)*(u8 *)data >= 0) {
            if (key == (s8)*((u8 *)data + 1))
                match = 1;
        }
        if (!match)
            goto incr1;
        p->sp5C = p->sp58;
        p->sp74 = p->sp58;
        break;
    case 2:
        p->sp8 = (u8)arg1;
        p->spC = (u8)arg1;
        key = (s8)(arg1 & 0xFF);
        p->sp48 = tail;
        p->sp4C = p->sp70;
        goto cond2;
    incr2:
        p->sp4C = node;
    cond2:
        if (*(void *volatile *)&p->sp4C == tail)
            break;
        match = 0;
        node = *(void **)*(void *volatile *)&p->sp4C;
        data = *(void **)((char *)node + 8);
        if ((s8)*(u8 *)data >= 0) {
            if (key == (s8)*((u8 *)data + 4))
                match = 1;
        }
        if (!match)
            goto incr2;
        p->sp50 = p->sp4C;
        p->sp74 = p->sp4C;
        break;
    default:
        p->sp74 = (void *)arg1;
        break;
    }

    node = *(void **)p->sp74;
    data = *(void **)((char *)node + 8);
    flag = (s8)*(u8 *)data;
    if (flag >= 0) {
        count = 0;
        p->sp40 = p->sp74;
        p->sp44 = p->sp6C;
        while (p->sp40 != p->sp6C) {
            count++;
            p->sp40 = *(void **)p->sp40;
        }
        flag = (s8)(count - 1);
    }
    return flag;
}
#pragma push
#pragma optimization_level 3
#pragma opt_common_subs off
s32 fn_801E8B38(void *arg0, u8 *arg1, s8 arg2) {
    s8 thresh;
    s32 var_r6;
    u8 var_r7;
    void *var_r5;
    s32 var_r0;
    s32 var_r8;
    s32 temp_r7;
    s32 scroll;
    u8 temp_r8;
    s32 temp_r9;
    s32 temp_r6;
    s8 var_r6_2;

    var_r7 = *arg1;
    thresh = arg2;
    var_r6 = 0;
    if ((s8)var_r7 < thresh) {
        var_r5 = *(void **)((u8 *)arg0 + 0x58);
        var_r0 = 0;
        if ((s8)var_r7 >= 0) {
            while ((s8)var_r7 > 0) {
                var_r5 = *(void **)((u8 *)var_r5 + 4);
                var_r7 -= 1;
            }
        } else {
            while ((s8)var_r7 < 0) {
                var_r5 = *(void **)var_r5;
                var_r7 += 1;
            }
        }
        do {
            temp_r8 = *arg1;
            if ((((s8)temp_r8 >= 0) && ((s8)(temp_r8 - (*(s16 *)((u8 *)arg0 + 0x38) / 32)) < 0))
                || (((s8)temp_r8 > 0) && ((s8)(temp_r8 - (*(s16 *)((u8 *)arg0 + 0x38) / 32)) == 0))) {
                temp_r7 = *(s16 *)((u8 *)arg0 + 0x36);
                var_r0 = 1;
                *(s16 *)((u8 *)arg0 + 0x38) = (s16)(temp_r7 - ((s8)(((s8)(temp_r7 / 32) - temp_r8) + 1) << 5));
            }
            if ((s8)*(u8 *)(*(void **)((u8 *)var_r5 + 8)) >= 0) {
                break;
            }
            var_r5 = *(void **)var_r5;
            *arg1 -= 1;
        } while (1);
        var_r6 = var_r0;
    } else if (thresh < (s8)var_r7) {
        var_r5 = *(void **)((u8 *)arg0 + 0x58);
        var_r8 = 0;
        if ((s8)var_r7 >= 0) {
            while ((s8)var_r7 > 0) {
                var_r5 = *(void **)((u8 *)var_r5 + 4);
                var_r7 -= 1;
            }
        } else {
            while ((s8)var_r7 < 0) {
                var_r5 = *(void **)var_r5;
                var_r7 += 1;
            }
        }
        do {
            temp_r9 = *(s8 *)arg1;
            temp_r6 = *(s32 *)((u8 *)arg0 + 0x50) - 1;
            if ((((u32)temp_r9 <= (u32)temp_r6) && ((s8)(temp_r9 - (*(s16 *)((u8 *)arg0 + 0x38) / 32)) > 8))
                || (((u32)temp_r9 < (u32)temp_r6) && ((s8)(temp_r9 - (*(s16 *)((u8 *)arg0 + 0x38) / 32)) == 8))) {
                scroll = *(s16 *)((u8 *)arg0 + 0x36);
                var_r6_2 = (s8)(temp_r9 - ((s8)(scroll / 32) + 8));
                if ((u32)temp_r9 < (u32)temp_r6) {
                    var_r6_2 += 1;
                }
                var_r8 = 1;
                *(s16 *)((u8 *)arg0 + 0x38) = (s16)((var_r6_2 << 5) + scroll);
            }
            if ((s8)*(u8 *)(*(void **)((u8 *)var_r5 + 8)) >= 0) {
                break;
            }
            var_r5 = *(void **)((u8 *)var_r5 + 4);
            *arg1 += 1;
        } while (1);
        var_r6 = var_r8;
    }
    return var_r6;
}
#pragma pop
#pragma optimization_level reset
#pragma global_optimizer on
void fn_801E8D34(u8 *arg0) {
    s32 fn_801E9410(void);
    u8 fn_801E85A4(void *, s32);
    s32 Abs(s32);
    void Process_ClearFunc(void *);
    void Process_Goto(void *, s32);
    void fn_80057860(s32, s16);
    s8 fn_801E4A60(void *, u8);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void fn_801E4900(s16 *, void *);
    void Ui_ShowUnitInfoText(void *, void *, f32, f32);
    void Ui_PlaySeCue(void *, s32);
    s8 fn_801E8920(void *, u8);
    void *Msg_Expand(void *);
    void TextBanner_SetString(void *, void *);
    u8 fn_801E91E8(void *, void *);
    extern u32 *gPadInput;
    extern u8 gUnitInfoPopup[];
    extern u8 gTabMenuStrings[];
    extern f64 lbl_8036B6E0;
    s32 max;
    s8 old32;
    u32 held;
    u32 buttons;
    u32 cur;
    u32 *pad;
    u8 t;
    s32 pos32;
    s32 tgt32;
    s16 t36;
    s8 lo;
    s8 hi;
    void *str;
    s16 spC[2];
    s16 sp14[2];
    s16 sp8[2];
    s16 sp10[2];

    max = fn_801E9410();
    pad = gPadInput;
    t = *(u8 *)(arg0 + 0x32);
    held = pad[3];
    cur = pad[1];
    old32 = (s8)t;
    buttons = cur & (pad[2] ^ cur);

    if (held & 0x08000008U) {
        t = *(volatile u8 *)(arg0 + 0x32);
        if ((s8)t == 0) {
            if (buttons == held) {
                *(u8 *)(arg0 + 0x32) = (u8)(max - 1);
            }
        } else {
            *(u8 *)(arg0 + 0x32) = t - 1;
        }
    } else if (held & 0x04000004U) {
        t = *(volatile u8 *)(arg0 + 0x32);
        max = max - 1;
        if ((u32)max == (u32)(s8)t) {
            if (buttons == held) {
                *(u8 *)(arg0 + 0x32) = 0;
            }
        } else {
            *(u8 *)(arg0 + 0x32) = t + 1;
        }
    }

    if (old32 != (s8)*(u8 *)(arg0 + 0x32)) {
        if (fn_801E85A4(arg0, *(u8 *)(arg0 + 0x32))) {
#pragma optimization_level 2
            if (Abs(old32 - (s8)*(u8 *)(arg0 + 0x32)) == 1) {
                *(s16 *)(arg0 + 0x3A) = 0x10;
                pos32 = *(s16 *)(arg0 + 0x36);
                tgt32 = *(s16 *)(arg0 + 0x38);
                if (pos32 == tgt32) {
                    Process_ClearFunc(arg0);
                } else {
                    if ((s16)pos32 < (s16)tgt32) {
                        *(s16 *)(arg0 + 0x36) = (s16)(*(s16 *)(arg0 + 0x3A) + pos32);
                    } else {
                        *(s16 *)(arg0 + 0x36) = (s16)(pos32 - *(s16 *)(arg0 + 0x3A));
                    }
                    t36 = *(s16 *)(arg0 + 0x36);
                    fn_80057860(*(s32 *)(arg0 + 0x5C), t36);
                    if (*(s16 *)(arg0 + 0x36) == *(s16 *)(arg0 + 0x38)) {
                        Process_ClearFunc(arg0);
                    }
                }
                Process_Goto(arg0, 4);
#pragma optimization_level reset
            } else if ((s8)*(u8 *)(arg0 + 0x32) < old32) {
                *(u8 *)(arg0 + 0x33) = 0;
                *(s16 *)(arg0 + 0x36) = 0;
                *(s16 *)(arg0 + 0x38) = 0;
                t36 = *(s16 *)(arg0 + 0x36);
                fn_80057860(*(s32 *)(arg0 + 0x5C), t36);
            } else {
                *(u8 *)(arg0 + 0x33) = (u8)fn_801E4A60(arg0, *(u8 *)(arg0 + 0x32));
                *(s16 *)(arg0 + 0x36) = *(s16 *)(arg0 + 0x38);
                t36 = *(s16 *)(arg0 + 0x36);
                fn_80057860(*(s32 *)(arg0 + 0x5C), t36);
            }
        }
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
            fn_801E4900(spC, arg0);
            str = NULL;
            *(s32 *)sp14 = *(s32 *)spC;
            switch ((s8)*(u8 *)(arg0 + 0x31)) {
            case 0:
                str = gTabMenuStrings + 0x15B;
                break;
            case 1:
                str = gTabMenuStrings + 0x166;
                break;
            }
            Ui_ShowUnitInfoText(gUnitInfoPopup, str, (f32)sp14[0], (f32)sp14[1]);
        }
        Ui_PlaySeCue(gTabMenuStrings + 0x1AB, 0x64);
        return;
    }

    if (buttons & 0x02000002U) {
        lo = fn_801E4A60(arg0, *(u8 *)(arg0 + 0x32));
        hi = fn_801E8920(arg0, *(u8 *)(arg0 + 0x32));
        *(u8 *)(arg0 + 0x31) = 1;
        switch ((s8)*(u8 *)(arg0 + 0x31)) {
        case 0:
            TextBanner_SetString(*(void **)(arg0 + 0x60), Msg_Expand(gTabMenuStrings + 0x182));
            break;
        case 1:
            TextBanner_SetString(*(void **)(arg0 + 0x60), Msg_Expand(gTabMenuStrings + 0x18D));
            break;
        }
        if ((s8)*(u8 *)(arg0 + 0x33) > hi) {
            *(u8 *)(arg0 + 0x33) = (u8)hi;
        }
        if ((s8)*(u8 *)(arg0 + 0x33) < lo) {
            *(u8 *)(arg0 + 0x33) = (u8)lo;
        }
        if (fn_801E91E8(arg0, arg0 + 0x33)) {
#pragma optimization_level 2
            *(s16 *)(arg0 + 0x3A) = 0x10;
            pos32 = *(s16 *)(arg0 + 0x36);
            tgt32 = *(s16 *)(arg0 + 0x38);
            if (pos32 == tgt32) {
                Process_ClearFunc(arg0);
            } else {
                if ((s16)pos32 < (s16)tgt32) {
                    *(s16 *)(arg0 + 0x36) = (s16)(*(s16 *)(arg0 + 0x3A) + pos32);
                } else {
                    *(s16 *)(arg0 + 0x36) = (s16)(pos32 - *(s16 *)(arg0 + 0x3A));
                }
                t36 = *(s16 *)(arg0 + 0x36);
                fn_80057860(*(s32 *)(arg0 + 0x5C), t36);
                if (*(s16 *)(arg0 + 0x36) == *(s16 *)(arg0 + 0x38)) {
                    Process_ClearFunc(arg0);
                }
            }
            Process_Goto(arg0, 4);
#pragma optimization_level reset
        }
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
            fn_801E4900(sp8, arg0);
            str = NULL;
            *(s32 *)sp10 = *(s32 *)sp8;
            switch ((s8)*(u8 *)(arg0 + 0x31)) {
            case 0:
                str = gTabMenuStrings + 0x15B;
                break;
            case 1:
                str = gTabMenuStrings + 0x166;
                break;
            }
            Ui_ShowUnitInfoText(gUnitInfoPopup, str, (f32)sp10[0], (f32)sp10[1]);
        }
        Ui_PlaySeCue(gTabMenuStrings + 0x13F, 0x64);
    }
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
s32 fn_801E91E8(void *arg0, u8 *arg1) {
    s32 top, bottom, position;
    
    u8 var_r7;
    void *var_r5;
    s32 var_r0;
    s32 var_r8;
    s32 temp_r7;
    s32 scroll;
    u8 temp_r8;
    s32 temp_r9;
    s32 temp_r6;
    s8 var_r6_2;

    position = *(s16 *)((u8 *)arg0 + 0x36);
    top = (s8)(position / 32);
    bottom = top + 8;
    if (position % 32) bottom = top + 9;
    bottom = (s8)bottom;
    var_r7 = *arg1;
    var_r8 = 0;
    if ((s8)var_r7 <= top) {
        var_r5 = *(void **)((u8 *)arg0 + 0x58);
        var_r0 = 0;
        if ((s8)var_r7 >= 0) {
            while ((s8)var_r7 > 0) {
                var_r5 = *(void **)((u8 *)var_r5 + 4);
                var_r7 -= 1;
            }
        } else {
            while ((s8)var_r7 < 0) {
                var_r5 = *(void **)var_r5;
                var_r7 += 1;
            }
        }
        do {
            temp_r8 = *arg1;
            if ((((s8)temp_r8 >= 0) && ((s8)(temp_r8 - (*(s16 *)((u8 *)arg0 + 0x38) / 32)) < 0))
                || (((s8)temp_r8 > 0) && ((s8)(temp_r8 - (*(s16 *)((u8 *)arg0 + 0x38) / 32)) == 0))) {
                temp_r7 = *(s16 *)((u8 *)arg0 + 0x36);
                var_r0 = 1;
                *(s16 *)((u8 *)arg0 + 0x38) = (s16)(temp_r7 - ((s8)(((s8)(temp_r7 / 32) - temp_r8) + 1) << 5));
            }
            if ((s8)*(u8 *)(*(void **)((u8 *)var_r5 + 8)) >= 0) {
                break;
            }
            var_r5 = *(void **)var_r5;
            *arg1 -= 1;
        } while (1);
        var_r8 = var_r0;
    } else if (bottom <= (s8)var_r7) {
        var_r5 = *(void **)((u8 *)arg0 + 0x58);
        var_r8 = 0;
        if ((s8)var_r7 >= 0) {
            while ((s8)var_r7 > 0) {
                var_r5 = *(void **)((u8 *)var_r5 + 4);
                var_r7 -= 1;
            }
        } else {
            while ((s8)var_r7 < 0) {
                var_r5 = *(void **)var_r5;
                var_r7 += 1;
            }
        }
        do {
            temp_r9 = *(s8 *)arg1;
            temp_r6 = *(s32 *)((u8 *)arg0 + 0x50) - 1;
            if ((((u32)temp_r9 <= (u32)temp_r6) && ((s8)(temp_r9 - (*(s16 *)((u8 *)arg0 + 0x38) / 32)) > 8))
                || (((u32)temp_r9 < (u32)temp_r6) && ((s8)(temp_r9 - (*(s16 *)((u8 *)arg0 + 0x38) / 32)) == 8))) {
                scroll = *(s16 *)((u8 *)arg0 + 0x36);
                var_r6_2 = (s8)(temp_r9 - ((s8)(scroll / 32) + 8));
                if ((u32)temp_r9 < (u32)temp_r6) {
                    var_r6_2 += 1;
                }
                var_r8 = 1;
                *(s16 *)((u8 *)arg0 + 0x38) = (s16)((var_r6_2 << 5) + scroll);
            }
            if ((s8)*(u8 *)(*(void **)((u8 *)var_r5 + 8)) >= 0) {
                break;
            }
            var_r5 = *(void **)((u8 *)var_r5 + 4);
            *arg1 += 1;
        } while (1);
    }
    return var_r8;
}
#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_lifetimes off
s32 fn_801E9410(void *arg0) {
typedef struct {void *node;} It;
It aeCopy, ae, aCopy, a, beCopy, be, bCopy, b, ceCopy, ce, cCopy, c;
It beginACopy, beginA, endACopy, endA, beginBCopy, beginB, endBCopy, endB, beginCCopy, beginC, endCCopy, endC;
struct {s8 value;} initA, keyA, initB, keyB, initC, keyC;
s32 previous;
s32 count0, count1, count2;
void *end0, *end1, *end2;
s32 ret;
u8 found;
u8 value;
switch ((s8)*((u8 *)arg0 + 0x30)) {
case 0:
end0 = (u8 *)arg0 + 0x54;
arg0 = *(void **)((u8 *)arg0 + 0x58);
endACopy.node = end0;
beginACopy.node = arg0;
beginA = beginACopy;
aCopy = beginA; a = aCopy;
endA = endACopy; aeCopy = endA; ae = aeCopy;
initA.value = -1; keyA = initA;
count0 = 0;
while (a.node != end0) {
previous = (s8)*(u8 *)&keyA.value;
value = (*(u8 **)((u8 *)a.node + 8))[2];
if (previous != (s8)value) { *(u8 *)&keyA.value = value; found = 1; } else found = 0;
if (found) count0++;
a.node = *(void **)((u8 *)a.node + 4);
}
ret = count0;
break;
case 1:
end1 = (u8 *)arg0 + 0x54;
arg0 = *(void **)((u8 *)arg0 + 0x58);
endBCopy.node = end1;
beginBCopy.node = arg0;
beginB = beginBCopy;
bCopy = beginB; b = bCopy;
endB = endBCopy; beCopy = endB; be = beCopy;
initB.value = -1; keyB = initB;
count1 = 0;
while (b.node != end1) {
previous = (s8)*(u8 *)&keyB.value;
value = (*(u8 **)((u8 *)b.node + 8))[1];
if (previous != (s8)value) { *(u8 *)&keyB.value = value; found = 1; } else found = 0;
if (found) count1++;
b.node = *(void **)((u8 *)b.node + 4);
}
ret = count1;
break;
case 2:
end2 = (u8 *)arg0 + 0x54;
arg0 = *(void **)((u8 *)arg0 + 0x58);
endCCopy.node = end2;
beginCCopy.node = arg0;
beginC = beginCCopy;
cCopy = beginC; c = cCopy;
endC = endCCopy; ceCopy = endC; ce = ceCopy;
initC.value = -1; keyC = initC;
count2 = 0;
while (c.node != end2) {
previous = (s8)*(u8 *)&keyC.value;
value = (*(u8 **)((u8 *)c.node + 8))[4];
if (previous != (s8)value) { *(u8 *)&keyC.value = value; found = 1; } else found = 0;
if (found) count2++;
c.node = *(void **)((u8 *)c.node + 4);
}
ret = count2;
break;
default:
ret = (s32)arg0;
break;
}
return ret;
}
#pragma pop
/* Clear the status under the tab-menu cursor and run its clear event. */
void TabMenu_ClearSelectedStatus(void *menu) {
    void Status_Clear(void *, u8);
    void ScriptCtx_Begin(void *);
    void ScriptCtx_Push(void *);
    void ScriptCtx_Call(void);
    void Event_StartByName(void *, void *);
    extern u8 gBattleState[];
    extern u8 gTabMenuStrings[];
    void **node;
    s8 idx;
    u8 cursor;

    cursor = *(u8 *)((u8 *)menu + 0x33);
    node = *(void ***)((u8 *)menu + 0x58);
    idx = (s8)cursor;
    if (idx >= 0) {
        while (idx > 0) {
            node = (void **)node[1];
            idx -= 1;
        }
    } else {
        while (idx < 0) {
            node = (void **)*node;
            idx += 1;
        }
    }
    Status_Clear(gBattleState + 0x84, *(u8 *)node[2]);
    ScriptCtx_Begin(gTabMenuStrings + 0x1C7);
    ScriptCtx_Push(*(void **)((u8 *)node[2] + 0x10));
    ScriptCtx_Push(*(void **)((u8 *)node[2] + 0x14));
    ScriptCtx_Call();
    Event_StartByName(gTabMenuStrings + 0x1D6, menu);
}

void fn_801E96D0(void *menu) {
u8 Status_Test(void *,u8);
void Process_Goto(void *,s32);
void Ui_PlaySeCue(void *,s32);
extern u8 gBattleState[],gTabMenuStrings[];
void **node;
s8 idx;
u8 cursor;
cursor=*(u8 *)((u8 *)menu+0x33);
node=*(void ***)((u8 *)menu+0x58);
idx=(s8)cursor;
if(idx>=0) {
while(idx>0) { node=(void **)node[1]; idx--; }
} else {
while(idx<0) { node=(void **)*node; idx++; }
}
if(!Status_Test(gBattleState+0x74,*(u8 *)node[2])) {
Process_Goto(menu,1);
Ui_PlaySeCue(gTabMenuStrings+0x1e3,100);
} else if(!*(void **)((u8 *)node[2]+0x10) || !*(void **)((u8 *)node[2]+0x14)) {
Process_Goto(menu,1);
Ui_PlaySeCue(gTabMenuStrings+0x1e3,100);
} else {
Ui_PlaySeCue(gTabMenuStrings+0x1f1,100);
}
}

#pragma optimization_level 2
void fn_801E97D4(void *arg0) {
    void Process_ClearFunc(void *);
    void fn_80057860(s32, s16);
    s32 a;
    s32 b;
    s16 t;

    a = *(s16 *)((u8 *)arg0 + 0x36);
    b = *(s16 *)((u8 *)arg0 + 0x38);
    if (a == b) {
        Process_ClearFunc(arg0);
        return;
    }
    if ((s16)a < (s16)b) {
        *(s16 *)((u8 *)arg0 + 0x36) = (s16)(*(s16 *)((u8 *)arg0 + 0x3A) + a);
    } else {
        *(s16 *)((u8 *)arg0 + 0x36) = (s16)(a - *(s16 *)((u8 *)arg0 + 0x3A));
    }
    t = *(s16 *)((u8 *)arg0 + 0x36);
    fn_80057860(*(s32 *)((u8 *)arg0 + 0x5C), t);
    if (*(s16 *)((u8 *)arg0 + 0x36) == *(s16 *)((u8 *)arg0 + 0x38)) {
        Process_ClearFunc(arg0);
    }
}

void fn_801E9864(void *arg0)
{
    typedef struct ListNode {
        struct ListNode *prev;
        struct ListNode *next;
        void *val;
    } ListNode;
    typedef struct Owner {
        u8 pad[0x50];
        u32 list;
        ListNode node;
    } Owner;
    extern u8 gTabMenuDefaultTab;
    extern u8 gTabMenuDefaultMode;
    extern u8 gTabMenuDefaultUnk32;
    extern u8 gTabMenuDefaultUnk33;
    extern u8 gTabMenuDefaultFade;
    extern s16 gTabMenuDefaultUnk36;
    extern s16 gTabMenuDefaultScroll;
    extern s16 gTabMenuDefaultCursor;
    void fn_8003F670(void *);
    void fn_8006D8E8(void *);
    void fn_80056A04(void *, s32);
    void List_EraseRange(void *, void *, void *, void *);
    Owner *self;
    s16 *p68;
    void *obj;
    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;

    self = (Owner *)arg0;
    p68 = &gTabMenuDefaultCursor;
    gTabMenuDefaultTab = *(u8 *)((u8 *)arg0 + 0x30);
    gTabMenuDefaultMode = *(u8 *)((u8 *)arg0 + 0x31);
    gTabMenuDefaultUnk32 = *(u8 *)((u8 *)arg0 + 0x32);
    gTabMenuDefaultUnk33 = *(u8 *)((u8 *)arg0 + 0x33);
    gTabMenuDefaultFade = *(u8 *)((u8 *)arg0 + 0x34);
    gTabMenuDefaultUnk36 = *(s16 *)((u8 *)arg0 + 0x36);
    gTabMenuDefaultScroll = *(s16 *)((u8 *)arg0 + 0x38);
    gTabMenuDefaultCursor = *(s16 *)((u8 *)arg0 + 0x3C);
    p68[1] = *(s16 *)((u8 *)arg0 + 0x3E);
    fn_8003F670(*(void **)((u8 *)arg0 + 0x40));
    fn_8006D8E8(*(void **)((u8 *)arg0 + 0x64));
    obj = *(void **)((u8 *)arg0 + 0x5C);
    if (obj != NULL) {
#pragma cplusplus on
        struct Widget {
            u8 pad[0x2C];
            virtual void v0(s32) = 0;
            virtual void v1(s32) = 0;
            virtual void v2(s32) = 0;
            virtual void v3(s32) = 0;
            virtual void v4(s32) = 0;
            virtual void v5(s32) = 0;
            virtual void v6(s32) = 0;
        };
        ((Widget *)obj)->v6(1);
#pragma cplusplus reset
    }
    fn_80056A04(*(void **)((u8 *)arg0 + 0x60), 1);
    if (arg0 != NULL) {
        if (&self->list != NULL) {
            if (&self->list != NULL) {
                if (&self->list != NULL) {
                    end = &self->node;
                    sp10 = end;
                    spC = end->next;
                    List_EraseRange(sp8, &self->list, &spC, &sp10);
                }
            }
        }
    }
}

#pragma optimization_level reset
void fn_801E9958(void) {
    M2C_UNK TabMenu_Init();
    TabMenu_Init();
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
/* Initialize a tab menu: look up assets, copy defaults, build text widgets, attach draw callbacks. */
void TabMenu_Init(void *menu) {
    void *Hash_Lookup(void *);
    void *Msg_Expand(void *);
    void *fn_80056A60(void *);
    void TextBanner_SetString(void *, void *);
    void ScrollBar_RecreateArrows(void *, s32);
    void fn_80057860(void *, s16);
    void fn_80057880(void *, s32);
    void fn_800578A0(void *, f32);
    void fn_800578A8(void *, s32, s32, s32);
    void *fn_80057998(void *);
    void Process_AttachFunc(void (*)(void), void *);
    void *Heap_Alloc(s32);
    void List_Insert(void *, void *, void **, void **);
    void fn_801E4CF8(void *);
    void TabMenu_Draw(void);
    void TabMenu_DrawHud(void);
    extern u8 gTabMenuStrings[];
    extern void *lbl_802981AC[];
    extern u8 gTabMenuDefaultTab;
    extern u8 gTabMenuDefaultMode;
    extern u8 gTabMenuDefaultUnk32;
    extern u8 gTabMenuDefaultUnk33;
    extern u8 gTabMenuDefaultFade;
    extern s16 gTabMenuDefaultUnk36;
    extern s16 gTabMenuDefaultScroll;
    extern s16 gTabMenuDefaultCursor;
    extern f32 lbl_8036B714;

    void *sp10;
    void *spC;
    void *sp8;
    void *entry;
    void *listHead;
    u32 count;
    u32 i;
    u32 *table;
    void *textBox;
    void *caption;
    s16 scroll;
    s16 *cursor;

    *(void **)((u8 *)menu + 0x44) = Hash_Lookup(gTabMenuStrings + 0x201);
    *(void **)((u8 *)menu + 0x48) = Hash_Lookup(gTabMenuStrings + 0x20D);
    *(void **)((u8 *)menu + 0x4C) = Hash_Lookup(gTabMenuStrings + 0x21A);
    table = (u32 *)Hash_Lookup(gTabMenuStrings + 0x226);
    count = table[0];
    entry = table + 1;
    listHead = (u8 *)menu + 0x54;
    for (i = 0; i < count; i += 1) {
        sp10 = entry;
        spC = listHead;
        List_Insert(&sp8, (u8 *)menu + 0x50, &spC, &sp10);
        entry = (u8 *)entry + 0x18;
    }
    *(u8 *)((u8 *)menu + 0x30) = gTabMenuDefaultTab;
    *(u8 *)((u8 *)menu + 0x31) = gTabMenuDefaultMode;
    *(u8 *)((u8 *)menu + 0x32) = gTabMenuDefaultUnk32;
    *(u8 *)((u8 *)menu + 0x33) = gTabMenuDefaultUnk33;
    *(u8 *)((u8 *)menu + 0x34) = gTabMenuDefaultFade;
    *(s16 *)((u8 *)menu + 0x36) = gTabMenuDefaultUnk36;
    *(s16 *)((u8 *)menu + 0x38) = gTabMenuDefaultScroll;
    cursor = &gTabMenuDefaultCursor;
    *(s16 *)((u8 *)menu + 0x3C) = cursor[0];
    *(s16 *)((u8 *)menu + 0x3E) = cursor[1];
    textBox = Heap_Alloc(0x30);
    if (textBox == 0) {
        goto skip_obj;
    }
    fn_80057998(textBox);
    *(void **)((u8 *)textBox + 0x2C) = lbl_802981AC;
skip_obj:
    *(void **)((u8 *)menu + 0x5C) = textBox;
    fn_800578A8(*(void **)((u8 *)menu + 0x5C), 0x22A, 0x6A, 0x110);
    ScrollBar_RecreateArrows(*(void **)((u8 *)menu + 0x5C), 1);
    caption = Heap_Alloc(0x18);
    if (caption == 0) {
        goto skip_sub;
    }
    caption = fn_80056A60(caption);
skip_sub:
    *(void **)((u8 *)menu + 0x60) = caption;
    switch ((s8)*(u8 *)((u8 *)menu + 0x31)) {
    case 0:
        TextBanner_SetString(*(void **)((u8 *)menu + 0x60), Msg_Expand(gTabMenuStrings + 0x182));
        break;
    case 1:
        TextBanner_SetString(*(void **)((u8 *)menu + 0x60), Msg_Expand(gTabMenuStrings + 0x18D));
        break;
    }
    fn_801E4CF8(menu);
    fn_80057880(*(void **)((u8 *)menu + 0x5C), 0x120);
    scroll = *(s16 *)((u8 *)menu + 0x36);
    fn_80057860(*(void **)((u8 *)menu + 0x5C), scroll);
    fn_800578A0(*(void **)((u8 *)menu + 0x5C), lbl_8036B714);
    Process_AttachFunc(TabMenu_Draw, menu);
    Process_AttachFunc(TabMenu_DrawHud, menu);
}

void fn_801E9B80(void *arg0) {
 u8 FileCache_IsReady(void *); s32 Archive_Load(void *); s32 fn_8006D948(void *); void Process_ClearFunc(void *);
 extern u32 lbl_80299FA8[],lbl_80299FC4[]; extern u8 gTabMenuStrings[];
 u32 *a; u32 *b;
 a=lbl_80299FA8;
 if(!FileCache_IsReady((void *)a[1]) || (b=lbl_80299FC4,!FileCache_IsReady((void *)b[1])) || !FileCache_IsReady(gTabMenuStrings+0x22f)) return;
 {
 *(s32 *)((u8 *)arg0+0x40)=Archive_Load((void *)a[1]);
 *(s32 *)((u8 *)arg0+0x64)=fn_8006D948((void *)b[1]);
 Process_ClearFunc(arg0);
 }
}

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

void fn_801E9C24(void) {
      void fn_8005C8B4(void *);
      extern u32 lbl_80299FA8[];
      extern u32 lbl_80299FC4[];
      extern u8 gTabMenuStrings[];

      fn_8005C8B4((void *)lbl_80299FA8[1]);
    fn_8005C8B4((void *)lbl_80299FC4[1]);
    fn_8005C8B4(&gTabMenuStrings[0x22f]);
}

void *fn_801E9C70(void *arg0)
{
    void *Process_CreateChild(void *, void *);
    void fn_80142060(void *);

    extern u8 lbl_80299FE0[];

    u8 *ptr;

    ptr = (u8 *)Process_CreateChild(lbl_80299FE0, arg0);

    if (ptr != 0) {
        *(u8 *)(ptr + 0x30) = 0;
        *(u8 *)(ptr + 0x31) = 0;
        *(u8 *)(ptr + 0x32) = 0;
        *(u8 *)(ptr + 0x33) = 0;
        *(u8 *)(ptr + 0x34) = 0;

        *(u16 *)(ptr + 0x36) = 0;
        *(u16 *)(ptr + 0x38) = 0;
        *(u16 *)(ptr + 0x3A) = 8;
        *(s16 *)(ptr + 0x3C) = -1;
        *(s16 *)(ptr + 0x3E) = -1;

        *(u32 *)(ptr + 0x40) = 0;
        *(u32 *)(ptr + 0x44) = 0;
        *(u32 *)(ptr + 0x48) = 0;
        *(u32 *)(ptr + 0x4C) = 0;

        fn_80142060(ptr + 0x50);

        *(u32 *)(ptr + 0x5C) = 0;
        *(u32 *)(ptr + 0x60) = 0;
        *(u32 *)(ptr + 0x64) = 0;
    }

    return ptr;
}

void fn_801E9D0C(void) {
    extern u16 gTabMenuStrings[40];
    ScriptCtx_Begin(&gTabMenuStrings[0x244 / 2]);
    ScriptCtx_Call();
}

void fn_801E9D3C(s32 arg0) {
    void fn_8014C718(void *, s32);
    extern u8 gBattleState[16];
    fn_8014C718(gBattleState, arg0);
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
/* Reload four map resources and refresh the unit map, preserving unit bitmasks. */
void Battle_ReloadMapLayers(void) {
    extern u8 gTabMenuStrings[];
    extern u8 gBattleState[];
    extern u8 gBattleMap[];
    void ScriptCtx_Begin(void *);
    void ScriptCtx_Call(void);
    void Map_RefreshUnitMap(void *);

    u8 *battle;
    u32 mask84;
    u32 mask90;
    u32 mask8c;
    u32 mask88;

    battle = gBattleState;
    mask84 = *(u32 *)(battle + 0x84);
    mask88 = *(u32 *)(battle + 0x88);
    mask8c = *(u32 *)(battle + 0x8C);
    mask90 = *(u32 *)(battle + 0x90);

    ScriptCtx_Begin(gTabMenuStrings + 0x24C);
    ScriptCtx_Call();
    ScriptCtx_Begin(gTabMenuStrings + 0x253);
    ScriptCtx_Call();
    ScriptCtx_Begin(gTabMenuStrings + 0x25D);
    ScriptCtx_Call();
    ScriptCtx_Begin(gTabMenuStrings + 0x26C);
    ScriptCtx_Call();
    Map_RefreshUnitMap(gBattleMap);

    *(u32 *)(battle + 0x84) = *(u32 *)(battle + 0x84) | mask84;
    *(u32 *)(battle + 0x88) = *(u32 *)(battle + 0x88) | mask88;
    *(u32 *)(battle + 0x8C) = *(u32 *)(battle + 0x8C) | mask8c;
    *(u32 *)(battle + 0x90) = *(u32 *)(battle + 0x90) | mask90;
}
#pragma global_optimizer on
#pragma use_lmw_stmw reset

void fn_801E9E30(s32 *arg0, u8 *arg1) {
    void Heap_Free(void *);
    void fn_801EA7BC(s32 *, s32 *, u8 *);
    struct {s32 count; void *prev,*next;} list;
    struct Key { u8 value; } sp10,spC,sp8;
    u32 var_r0;
    void *var_r29;
    u32 n;
    u32 temp_r6;
    u32 temp_r8;
    u32 temp_r9;
    u32 temp_r5;
    u32 node8;
    void *tmp;
    void *var_r7;
    s32 temp_r0;
    u32 var_r3;
    u32 half;
    void *temp_r3;

    temp_r0 = arg0[0];
    switch (temp_r0) {
case 0: case 1: break;
case 2: {
        temp_r6 = (u32)arg0[2];
        temp_r8 = *(u32 *)(temp_r6 + 4);
        temp_r5 = *(u32 *)(temp_r6 + 8);
        node8 = *(u32 *)(temp_r8 + 8);
        if ((s8)*(u8 *)(node8 + 3) < (s8)*(u8 *)(temp_r5 + 3)) {
            tmp = *(void **)temp_r6;
            *(void **)temp_r6 = *(void **)((u8 *)temp_r6 + 4);
            *(void **)((u8 *)temp_r6 + 4) = tmp;
            tmp = *(void **)temp_r8;
            *(void **)temp_r8 = *(void **)((u8 *)temp_r8 + 4);
            *(void **)((u8 *)temp_r8 + 4) = tmp;
            tmp = (void *)arg0[1];
            arg0[1] = arg0[2];
            arg0[2] = (s32)tmp;
        }
    break; }
default: {
        half = (u32)temp_r0 >> 1;
        var_r7 = (void *)arg0[2];
        for (n=half;n!=0;--n) var_r7=*(void **)((u8 *)var_r7+4);
        list.count = 0;
        list.next = &list.prev;
        list.prev = &list.prev;
        temp_r9 = (u32)arg0[1];
        tmp = *(void **)var_r7;
        *(void **)((u8 *)tmp + 4) = *(void **)((u8 *)(void *)temp_r9 + 4);
        tmp = *(void **)var_r7;
        **(void ***)((u8 *)(void *)temp_r9 + 4) = tmp;
        *(void **)((u8 *)list.prev + 4) = var_r7;
        *(void **)var_r7 = list.prev;
        list.prev = (void *)temp_r9;
        *(void **)((u8 *)(void *)temp_r9 + 4) = &list.prev;
        list.count = arg0[0] - half;
        arg0[0] = half;
        sp10.value = *arg1;
        fn_801E9E30(arg0, &sp10.value);
        spC.value = *arg1;
        fn_801E9E30(&list.count, &spC.value);
        sp8.value = *arg1;
        fn_801EA7BC(arg0, &list.count, &sp8.value);
        var_r29 = list.next;
        if (var_r29 != &list.prev) {
            tmp = *(void **)var_r29;
            *(void **)((u8 *)tmp + 4) = *(void **)((u8 *)list.prev + 4);
            **(void ***)((u8 *)list.prev + 4) = tmp;
            while (var_r29 != &list.prev) {
                temp_r3 = var_r29;
                var_r29 = *(void **)((u8 *)var_r29 + 4);
                Heap_Free(temp_r3);
                list.count -= 1;
            }
        }
    }
}
}

void fn_801EA018(s32 *arg0, u8 *arg1) {
    void fn_800C428C(void *);
    void fn_801EA618(s32 *, s32 *, u8 *);
    s32 sp14;
    u8 sp10;
    u8 spC;
    u8 sp8;
    void *temp_r3;
    void *var_r29;
    void *var_r7;
    void *temp_r6;
    void *temp_r8;
    void *temp_r9;
    void *temp_r5;
    void *node8;
    void *tmp;
    s32 temp_r0;
    u32 half;
    u32 var_r3;
    u32 n;
    u8 var_r0;
    void *sp1C;
    void *sp18;

    temp_r0 = arg0[0];
    switch (temp_r0) {
    case 2: {
        temp_r6 = (void *)arg0[2];
        temp_r8 = *(void **)((u8 *)temp_r6 + 4);
        temp_r5 = *(void **)((u8 *)temp_r6 + 8);
        node8 = *(void **)((u8 *)temp_r8 + 8);
        if ((s8)*(u8 *)((u8 *)node8 + 1) == (s8)*(u8 *)((u8 *)temp_r5 + 1)) {
            var_r0 = (s8)*(u8 *)((u8 *)node8 + 3) < (s8)*(u8 *)((u8 *)temp_r5 + 3);
        } else {
            var_r0 = (s8)*(u8 *)((u8 *)node8 + 1) < (s8)*(u8 *)((u8 *)temp_r5 + 1);
        }
        if (var_r0 != 0) {
            tmp = *(void **)temp_r6;
            *(void **)temp_r6 = *(void **)((u8 *)temp_r6 + 4);
            *(void **)((u8 *)temp_r6 + 4) = tmp;
            tmp = *(void **)temp_r8;
            *(void **)temp_r8 = *(void **)((u8 *)temp_r8 + 4);
            *(void **)((u8 *)temp_r8 + 4) = tmp;
            tmp = (void *)arg0[1];
            arg0[1] = arg0[2];
            arg0[2] = (s32)tmp;
        }
        break;
    }
    case 0:
    case 1:
        break;
    default: {
        half = (u32)temp_r0 >> 1;
        var_r7 = (void *)arg0[2];
        var_r3 = half;
        if (half != 0) {
            n = half >> 3;
            if (n != 0) {
                do {
                    var_r7 = *(void **)((u8 *)var_r7 + 4);
                    var_r7 = *(void **)((u8 *)var_r7 + 4);
                    var_r7 = *(void **)((u8 *)var_r7 + 4);
                    var_r7 = *(void **)((u8 *)var_r7 + 4);
                    var_r7 = *(void **)((u8 *)var_r7 + 4);
                    var_r7 = *(void **)((u8 *)var_r7 + 4);
                    var_r7 = *(void **)((u8 *)var_r7 + 4);
                    var_r7 = *(void **)((u8 *)var_r7 + 4);
                    n -= 1;
                } while (n != 0);
                var_r3 &= 7;
            }
            if (var_r3 != 0) {
                do {
                    var_r7 = *(void **)((u8 *)var_r7 + 4);
                    var_r3 -= 1;
                } while (var_r3 != 0);
            }
        }
        sp14 = 0;
        sp1C = &sp18;
        sp18 = &sp18;
        temp_r9 = (void *)arg0[1];
        tmp = *(void **)var_r7;
        *(void **)((u8 *)tmp + 4) = *(void **)((u8 *)temp_r9 + 4);
        tmp = *(void **)var_r7;
        **(void ***)((u8 *)temp_r9 + 4) = tmp;
        *(void **)((u8 *)sp18 + 4) = var_r7;
        *(void **)var_r7 = sp18;
        sp18 = temp_r9;
        *(void **)((u8 *)temp_r9 + 4) = &sp18;
        sp14 = arg0[0] - (s32)half;
        arg0[0] = (s32)half;
        sp10 = *arg1;
        fn_801EA018(arg0, &sp10);
        spC = *arg1;
        fn_801EA018(&sp14, &spC);
        sp8 = *arg1;
        fn_801EA618(arg0, &sp14, &sp8);
        var_r29 = sp1C;
        if (var_r29 != &sp18) {
            tmp = *(void **)var_r29;
            *(void **)((u8 *)tmp + 4) = *(void **)((u8 *)sp18 + 4);
            tmp = *(void **)var_r29;
            **(void ***)((u8 *)sp18 + 4) = tmp;
            while (var_r29 != &sp18) {
                temp_r3 = var_r29;
                var_r29 = *(void **)((u8 *)var_r29 + 4);
                fn_800C428C(temp_r3);
                sp14 -= 1;
            }
        }
        break;
    }
    }
}

#pragma optimization_level 3
void fn_801EA248(s32 *arg0, u8 *arg1) {
    void Heap_Free(void *);
    void fn_801EA514(s32 *, s32 *, u8 *);
    struct {s32 count; void *prev,*next;} list;
    struct Key { u8 value; } sp10,spC,sp8;
    void *temp_r3;
    void *var_r29;
    void *node8;
    unsigned n;
    void *temp_r8;
    void *tmp;
    void *temp_r5;
    void *temp_r9;
    void *var_r7;
    s32 temp_r0;
    void *temp_r6;
    u32 half;

    temp_r0 = arg0[0];
    switch (temp_r0) {
    case 0:
    case 1:
        break;
    case 2: {
        temp_r6 = (void *)arg0[2];
        temp_r8 = *(void **)((u8 *)temp_r6 + 4);
        temp_r5 = *(void **)((u8 *)temp_r6 + 8);
        node8 = *(void **)((u8 *)temp_r8 + 8);
        if ((s8)*(u8 *)node8 < (s8)*(u8 *)temp_r5) {
            tmp = *(void **)temp_r6;
            *(void **)temp_r6 = *(void **)((u8 *)temp_r6 + 4);
            *(void **)((u8 *)temp_r6 + 4) = tmp;
            tmp = *(void **)temp_r8;
            *(void **)temp_r8 = *(void **)((u8 *)temp_r8 + 4);
            *(void **)((u8 *)temp_r8 + 4) = tmp;
            tmp = (void *)arg0[1];
            arg0[1] = arg0[2];
            arg0[2] = (s32)tmp;
        }
        break;
    }
    default: {
        half = (u32)temp_r0 >> 1;
        var_r7 = (void *)arg0[2];
        for (n = half; n != 0; --n) {
            var_r7 = *(void **)((u8 *)var_r7 + 4);
        }
        list.count = 0;
        list.next = &list.prev;
        list.prev = &list.prev;
        temp_r9 = (void *)arg0[1];
        tmp = *(void **)var_r7;
        *(void **)((u8 *)tmp + 4) = *(void **)((u8 *)temp_r9 + 4);
        tmp = *(void **)var_r7;
        **(void ***)((u8 *)temp_r9 + 4) = tmp;
        *(void **)((u8 *)list.prev + 4) = var_r7;
        *(void **)var_r7 = list.prev;
        list.prev = temp_r9;
        *(void **)((u8 *)temp_r9 + 4) = &list.prev;
        list.count = arg0[0] - half;
        arg0[0] = (s32)half;
        sp10.value = *arg1;
        fn_801EA248(arg0, &sp10.value);
        spC.value = *arg1;
        fn_801EA248(&list.count, &spC.value);
        sp8.value = *arg1;
        fn_801EA514(arg0, &list.count, &sp8.value);
        var_r29 = list.next;
        if (var_r29 != &list.prev) {
            tmp = *(void **)var_r29;
            tmp = *(void **)var_r29;
            *(void **)((u8 *)tmp + 4) = *(void **)((u8 *)list.prev + 4);
            **(void ***)((u8 *)list.prev + 4) = tmp;
            while (var_r29 != &list.prev) {
                temp_r3 = var_r29;
                var_r29 = *(void **)((u8 *)var_r29 + 4);
                Heap_Free(temp_r3);
                list.count--;
            }
        }
    }
    }
}
#pragma optimization_level reset
void fn_801EA430(void *arg0) {
    void Heap_Free(void *);
    void *head;
    void *cur;
    void *end;
    void *self = arg0;
    void *node;
    void *a;
    head = (u8 *)self + 4;
    cur = *(void **)((u8 *)self + 8);
    while (cur != head) {
        if ((s8)*(u8 *)*(void **)((u8 *)cur + 8) < 0) {
            end = *(void **)((u8 *)cur + 4);
            while (end != head) {
                if ((s8)*(u8 *)*(void **)((u8 *)end + 8) >= 0) break;
                end = *(void **)((u8 *)end + 4);
            }
            if (cur != end) goto erase;
            goto done;
erase:
            a = *(void **)end;
            *(void **)((u8 *)*(void **)cur + 4) = *(void **)((u8 *)a + 4);
            **(void ***)((u8 *)a + 4) = *(void **)cur;
            while (cur != end) {
                node = cur;
                cur = *(void **)((u8 *)cur + 4);
                Heap_Free(node);
                --*(s32 *)self;
            }
done:
            cur = end;
            if (end == head) break;
        }
        cur = *(void **)((u8 *)cur + 4);
    }
}
#pragma optimization_level reset
void fn_801EA514(s32 *arg0, s32 *arg1) {
    void fn_80182514(s32 *, void **, s32 *);

    void **node;
    void *sentinel1;
    void **node2;
    void *sentinel2;
    void **walk;
    void *last;
    void *previous;
    void *remaining;
    s8 key;
    unsigned count;

    if (arg0 == arg1) {
        return;
    }

    node = (void **)arg0[2];
    sentinel1 = arg0 + 1;
    node2 = (void **)arg1[2];
    sentinel2 = arg1 + 1;

    while (node != sentinel1 && node2 != sentinel2) {
        if (*(s8 *)node2[2] < *(s8 *)node[2]) {
            walk = (void **)node2[1];
            count = 1;
            key = *(s8 *)node[2];

            while (walk != sentinel2) {
                if (*(s8 *)walk[2] >= key) {
                    break;
                }
                walk = (void **)walk[1];
                count++;
            }

            last = walk[0];
            previous = node2[0];

            ((void **)previous)[1] = ((void **)last)[1];
            ((void **)((void **)last)[1])[0] = node2[0];

            ((void **)node[0])[1] = node2;
            node2[0] = node[0];

            node2 = walk;
            node[0] = last;
            ((void **)last)[1] = node;

            *arg1 -= count;
            *arg0 += count;
        }

        node = (void **)node[1];
    }

    if (node2 != sentinel2) {
        remaining = node;
        fn_80182514(arg0, &remaining, arg1);
    }
}

void fn_801EA618(s32 *arg0,s32 *arg1,u8 *unused) {
typedef struct Node {struct Node *prev,*next; s8 *data;} Node;
void fn_80182514(s32 *,Node **,s32 *);
Node *first,*second,*end1,*end2,*scan,*last;
s32 count;
u8 less;
s8 *data;
if(arg0!=arg1) {
first=(Node*)arg0[2]; 
second=(Node*)arg1[2]; end2=(Node*)(arg1+1);
while(first!=(Node*)(arg0+1) && second!=end2) {
data=first->data;
if(second->data[1]==data[1]) less=second->data[3]<data[3];
else less=second->data[1]<data[1];
if(less) {
scan=second->next; count=1;
while(scan!=end2) {
data=first->data;
if(scan->data[1]==data[1]) less=scan->data[3]<data[3];
else less=scan->data[1]<data[1];
if(!less) break;
scan=scan->next; count++;
}
last=scan->prev;
second->prev->next=last->next;
last->next->prev=second->prev;
first->prev->next=second;
second->prev=first->prev;
second=scan;
first->prev=last;
last->next=first;
*arg1-=count; *arg0+=count;
}
first=first->next;
}
if(second!=end2) {Node *remaining=first; fn_80182514(arg0,&remaining,arg1);}
}
}

void fn_801EA7BC(void *arg0, void *arg1) {
    typedef struct Node {
        struct Node *prev;
        struct Node *next;
        s8 *data;
    } Node;

    typedef struct List {
        s32 count;
        Node sentinel;
    } List;

    void fn_80182514(u32 *, Node **, List *);

    List *dst;
    List *src;
    Node *first;
    Node *dstEnd;
    Node *second;
    Node *srcEnd;
    Node *scan;
    Node *last;
    s32 count;
    s8 value;

    dst = (List *)arg0;
    src = (List *)arg1;

    if (dst == src) {
        return;
    }

    first = dst->sentinel.next;
    dstEnd = &dst->sentinel;
    second = src->sentinel.next;
    srcEnd = &src->sentinel;

    while (first != dstEnd && second != srcEnd) {
        if (second->data[3] < first->data[3]) {
            scan = second->next;
            count = 1;
            value = first->data[3];

            while (scan != srcEnd) {
                if (scan->data[3] >= value) {
                    break;
                }

                scan = scan->next;
                count++;
            }

            last = scan->prev;

            second->prev->next = last->next;
            last->next->prev = second->prev;

            first->prev->next = second;
            second->prev = first->prev;

            second = scan;
            first->prev = last;
            last->next = first;

            src->count -= count;
            dst->count += count;
        }

        first = first->next;
    }

    if (second != srcEnd) {
        Node *remaining = first;
        fn_80182514((u32 *)dst, &remaining, src);
    }
}

/* Functions from 0x801E4540 to 0x801EA8C0, found by decomp-toolkit. */
#include "common.h"
#include "global.h"

extern f32 gTabMenuOne;
#include "global.h"
#include "ef.h"

extern u16* lbl_80332020;

