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

    struct { s16 a; s16 b; } sp10;
    struct { s16 a; s16 b; } spC;
    struct { s16 a; s16 b; } sp8;
    s16 y;
    s16 x;
    s8 row;

    if (lbl_803682F8 == 0) {
        sp10.a = 0x100;
        sp10.b = 0x1B;
        spC.a = 0x16A;
        spC.b = 0x1B;
        sp8.a = 0x1D4;
        sp8.b = 0x1B;
        ((s32 *)lbl_80332260)[0] = *(s32 *)&sp10;
        ((s32 *)lbl_80332260)[1] = *(s32 *)&spC;
        ((s32 *)lbl_80332260)[2] = *(s32 *)&sp8;
        lbl_803682F8 = 1;
    }
    switch (*(s8 *)((u8 *)arg1 + 0x31)) {
    case 0: {
        s32 temp = fn_801E4A60(arg1, (s8)*(u8 *)((u8 *)arg1 + 0x32));
        row = (s8)((s8)temp - (*(s16 *)((u8 *)arg1 + 0x38) / 32));
        {
            s16 half = (s16)((0x20 - Text_MeasureHeight(-1, (s8)temp, gTabMenuOne)) >> 1);
            y = (s16)((s16)(half + 0x62) + (row << 5));
        }
        x = 0x28;
        break;
    }
    case 1: {
        s32 div = *(s16 *)((u8 *)arg1 + 0x38) / 32;
        row = (s8)((s8)*(u8 *)((u8 *)arg1 + 0x33) - div);
        {
            s16 half = (s16)((0x20 - Text_MeasureHeight(-1, div, gTabMenuOne)) >> 1);
            y = (s16)((s16)(half + 0x62) + (row << 5));
        }
        x = 0xA0;
        break;
    }
    }
    arg0[0] = x;
    arg0[1] = y;
}

s8 fn_801E4A60(void *arg0, u8 arg1) {
    void *temp_r3;
    void *temp_r6;
    s8 var_r5;
    u8 temp_r0;
    u8 var_r4;
    u8 var_r4_2;
    u8 var_r4_3;
    void *temp_r6_2;
    void *temp_r6_3;
    void *temp_r6_4;
    void *sp54;
    void *sp48;
    void *sp3C;
    void *sp50;
    void *sp44;
    void *sp38;
    void *sp58;
    void *sp4C;
    void *sp40;
    void *sp60;
    void *sp2C;
    void *sp28;
    void *sp24;
    void *sp20;
    void *sp30;
    void *sp34;
    u8 sp1C;
    u8 sp18;
    u8 sp14;
    u8 sp10;
    u8 spC;
    u8 sp8;

    temp_r0 = *(u8 *)((char *)arg0 + 0x30);
    temp_r3 = (char *)arg0 + 0x54;
    temp_r6 = *(void **)((char *)temp_r3 + 0x4);
    
    switch ((s8) temp_r0) {
    case 0:
        sp18 = arg1;
        sp1C = arg1;
        sp50 = temp_r3;
        sp54 = temp_r6;
        while (sp54 != temp_r3) {
            temp_r6_2 = *(void **)((char *)sp54 + 0x8);
            var_r4 = 0;
            if (((s8) *(u8 *)((char *)temp_r6_2 + 0x0) >= 0) && ((s8) arg1 == (s8) *(u8 *)((char *)temp_r6_2 + 0x2))) {
                var_r4 = 1;
            }
            if (var_r4 == 0) {
                sp54 = *(void **)((char *)sp54 + 0x4);
                continue;
            }
            break;
        }
        sp58 = sp54;
        sp30 = sp54;
        break;
    case 1:
        sp10 = arg1;
        sp14 = arg1;
        sp44 = temp_r3;
        sp48 = temp_r6;
        while (sp48 != temp_r3) {
            temp_r6_3 = *(void **)((char *)sp48 + 0x8);
            var_r4_2 = 0;
            if (((s8) *(u8 *)((char *)temp_r6_3 + 0x0) >= 0) && ((s8) arg1 == (s8) *(u8 *)((char *)temp_r6_3 + 0x1))) {
                var_r4_2 = 1;
            }
            if (var_r4_2 == 0) {
                sp48 = *(void **)((char *)sp48 + 0x4);
                continue;
            }
            break;
        }
        sp4C = sp48;
        sp30 = sp48;
        break;
    case 2:
        sp8 = arg1;
        spC = arg1;
        sp38 = temp_r3;
        sp3C = temp_r6;
        while (sp3C != temp_r3) {
            temp_r6_4 = *(void **)((char *)sp3C + 0x8);
            var_r4_3 = 0;
            if (((s8) *(u8 *)((char *)temp_r6_4 + 0x0) >= 0) && ((s8) arg1 == (s8) *(u8 *)((char *)temp_r6_4 + 0x4))) {
                var_r4_3 = 1;
            }
            if (var_r4_3 == 0) {
                sp3C = *(void **)((char *)sp3C + 0x4);
                continue;
            }
            break;
        }
        sp40 = sp3C;
        sp30 = sp3C;
        break;
    default:
        return 0;
    }
    
    var_r5 = 0;
    sp34 = sp60;
    while (sp34 != sp30) {
        var_r5 += 1;
        sp34 = *(void **)((char *)sp34 + 0x4);
    }
    return var_r5;
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

void fn_801E4D54(void *arg0) {
    void fn_801EA430(void *, void *);
    void fn_801E9E30(void *, void *);
    void List_Insert(void *, void *, void *, void *);
    void fn_80057898(void *, s32);
    extern u8 lbl_80332020[];
    struct { void *node; } iter, copy;
    void *data, *pos, *result;
    struct { u8 value; } keyCopy, key, initA, initB, aCopy, a, bCopy, b;
    u8 *entry;
    void *end;
    s32 index;
    void *node;
    u8 found;
    bCopy = initB; b = bCopy;
    fn_801EA430((u8*)arg0+0x50, &b);
    aCopy = initA; a = aCopy;
    fn_801E9E30((u8*)arg0+0x50, &a);
    end = (u8*)arg0+0x54; index = 0;
    iter.node = *(void **)((u8*)arg0+0x58);
    entry = lbl_80332020;
    for (;;) {
        keyCopy.value = index + 1; key = keyCopy;
        node = iter.node;
        goto search;
        next: node = *(void **)((u8*)node+4);
        search:
        if (node != end) {
            s8 *p = *(s8 **)((u8*)node+8);
            found = 0;
            if (p[0] >= 0 && (s8)key.value == p[4]) found = 1;
            if (!found) goto next;
        }
        copy.node = node; iter = copy;
        if (node == end) break;
        data = entry; entry[4] = index; entry[3] = (*(u8 **)((u8*)node+8))[3]; pos = node;
        List_Insert(&result, (u8*)arg0+0x50, &pos, &data);
        entry += 0x18; index++;
    }
    fn_80057898(*(void **)((u8*)arg0+0x5C), *(s32*)((u8*)arg0+0x50)<<5);
}

void fn_801E4E8C(void *arg0) {
    void fn_801EA430(void *, void *);
    void fn_801EA018(void *, void *);
    void List_Insert(void *, void *, void *, void *);
    void fn_80057898(void *, s32);
    extern u8 lbl_80332020[];
    void *iter, *data, *copy, *pos, *result;
    struct { u8 value; } keyCopy, key, initA, initB, aCopy, a, bCopy, b;
    u8 *entry;
    void *end;
    s32 index;
    void *node;
    u8 found;
    bCopy = initB; b = initB;
    fn_801EA430((u8*)arg0+0x50, &b);
    aCopy = initA; a = initA;
    fn_801EA018((u8*)arg0+0x50, &a);
    end = (u8*)arg0+0x54; index = 0;
    iter = *(void **)((u8*)arg0+0x58);
    entry = lbl_80332020;
    for (;;) {
        key.value = index + 1; keyCopy = key;
        node = iter;
        search:
        if (node != end) {
            s8 *p = *(s8 **)((u8*)node+8);
            found = 0;
            if (p[0] >= 0 && (s8)key.value == p[1]) found = 1;
            if (!found) { node = *(void **)((u8*)node+4); goto search; }
        }
        copy = node; iter = node;
        if (node == end) break;
        data = entry; entry[1] = index; pos = node;
        List_Insert(&result, (u8*)arg0+0x50, &pos, &data);
        entry += 0x18; index++;
    }
    fn_80057898(*(void **)((u8*)arg0+0x5C), *(s32*)((u8*)arg0+0x50)<<5);
}

void fn_801E4FB8(void *arg0) {
    void fn_801EA430(void *, void *);
    void fn_801EA248(void *, void *);
    void List_Insert(void *, void *, void *, void *);
    void fn_80057898(void *, s32);
    extern u8 lbl_80332020[];
    struct { void *node; } iter, copy;
    void *data, *pos, *result;
    struct { u8 value; } keyCopy, key, initA, initB, aCopy, a, bCopy, b;
    u8 *entry;
    void *end;
    s32 index;
    void *node;
    u8 found;
    bCopy = initB; b = initB;
    fn_801EA430((u8*)arg0+0x50, &b);
    aCopy = initA; a = initA;
    fn_801EA248((u8*)arg0+0x50, &a);
    end = (u8*)arg0+0x54; index = 0;
    iter.node = *(void **)((u8*)arg0+0x58);
    entry = lbl_80332020;
    for (;;) {
        key.value = index + 1; keyCopy = key;
        node = iter.node;
        goto search;
        next: node = *(void **)((u8*)node+4);
        search:
        if (node != end) {
            s8 *p = *(s8 **)((u8*)node+8);
            found = 0;
            if (p[0] >= 0 && (s8)key.value == p[2]) found = 1;
            if (!found) goto next;
        }
        copy.node = node; iter.node = node;
        if (node == end) break;
        data = entry; entry[2] = index; pos = node;
        List_Insert(&result, (u8*)arg0+0x50, &pos, &data);
        entry += 0x18; index++;
    }
    fn_80057898(*(void **)((u8*)arg0+0x5C), *(s32*)((u8*)arg0+0x50)<<5);
}

#pragma use_lmw_stmw on
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
    s32 Text_MeasureWidth(void *, s32, f32);
    s32 Text_MeasureHeight(s32, f32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_EndPrim(void);
    void Text_Draw(s16, s16, u8, void *, ...);
    void Prim2D_AddZ(f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    extern f32 gTabMenuOne;
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
    s16 px;
    s32 py;

    tw = (s16)Text_MeasureWidth(arg6, -1, gTabMenuOne);
    th = Text_MeasureHeight(-1, gTabMenuOne);
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

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    f_top = lbl_8036B71C + (f32)top;
    f_left = lbl_8036B71C + (f32)left;
    f_right = lbl_8036B71C + (f32)right;
    Prim2D_SetPosCorners(f_left, f_top, f_right, f_top);
    sp14 = *(s32 *)border;
    Prim2D_SetColorPacked(&sp14);
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    f_bottom = lbl_8036B71C + (f32)bottom;
    Prim2D_SetPosCorners(f_right, f_top, f_right, f_bottom);
    sp10 = *(s32 *)border;
    Prim2D_SetColorPacked(&sp10);
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(f_right, f_bottom, f_left, f_bottom);
    spC = *(s32 *)border;
    Prim2D_SetColorPacked(&spC);
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(f_left, f_bottom, f_left, f_top);
    sp8 = *(s32 *)border;
    Prim2D_SetColorPacked(&sp8);
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    px = (s16)(x + half_w);
    mode = 0x16;
    py = y + half_h;
    if (arg5 != 0) {
        mode = 0x15;
    }
    Text_Draw(px, (s16)py, (u8)mode, arg6);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B720);
    Prim2D_PrepareTex();

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)arg1, (f32)arg2, (f32)arg3, (f32)arg4);
    sp18 = *(s32 *)fill;
    Prim2D_SetColorPacked(&sp18);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B724);
    Prim2D_PrepareTex();
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
    extern s16 lbl_8036833C;

    struct Node { struct Node *prev; struct Node *next; u8 *data; };

    u8 color[4];
    s32 color_word;
    void *self = arg0;
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

    u8 pal[3];
    Color c0, c1;
    Color tmp;
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
#pragma peephole on
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
            s32 targetY = y + 1;
            *(s16 *)((u8 *)self + 0x3C) = (s16)((x + 0xA1) >> 1);
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

s32 fn_801E8734(void *arg0) {
    s8 fn_801E4A60();
    s16 v;
    s32 q;
    s32 r;
    s8 lo;
    u8 ok;
    s32 count;

    count = fn_801E4A60();
    if ((s8)count > 0) {
        count--;
    }
    v = M2C_FIELD(arg0, s16 *, 0x36);
    q = v / 32;
    r = v % 32;
    lo = (s8)q + 8;
    if (r != 0) {
        lo = (s8)q + 9;
    }
    ok = 0;
    if (((s8)q <= (s8)count) && ((s8)count <= lo)) {
        ok = 1;
    }
    if (ok == 0) {
        M2C_FIELD(arg0, s16 *, 0x38) = (s16)(v - ((s8)((s8)q - (s8)count) << 5));
        return 1;
    }
    return 0;
}

s32 fn_801E87EC(void *arg0, s32 arg1) {
    s8 fn_801E4A60();
    s8 fn_801E8920(void *, s32);
    s8 v0;
    s8 v1;
    s16 f36;
    s32 q;
    s32 rem;
    s32 band;
    s32 t;
    u8 inrange;

    v0 = fn_801E4A60();
    v1 = fn_801E8920(arg0, arg1);
    if (v0 > 0) {
        v0 -= 1;
    }
    if ((u32) v1 < (u32) (M2C_FIELD(arg0, s32 *, 0x50) - 1)) {
        v1 += 1;
    }
    f36 = M2C_FIELD(arg0, s16 *, 0x36);
    q = f36 / 32;
    t = v1 - v0 + 1;
    rem = f36 % 32;
    band = (s8) q + 8;
    if (rem != 0) {
        band = (s8) q + 9;
    }
    inrange = 0;
    if ((s8) q <= v1 && v1 <= (s8) band) {
        inrange = 1;
    }
    if (inrange == 0) {
        if ((s8) t <= 9) {
            M2C_FIELD(arg0, s16 *, 0x38) = (s16) (((s8) (v1 - ((s8) q + 8)) << 5) + f36);
        } else {
            M2C_FIELD(arg0, s16 *, 0x38) = (s16) (f36 - ((s8) ((s8) q - v0) << 5));
        }
        return 1;
    }
    return 0;
}

s8 fn_801E8920(void *arg0, u8 arg1) {
    typedef struct { void *node; } It;
    It sp74;
    It sp70;
    It sp6C;
    It sp68;
    It sp64;
    It sp60;
    It sp5C;
    It sp58;
    It sp54;
    It sp50;
    It sp4C;
    It sp48;
    It sp44;
    It sp40;
    It sp3C;
    It sp38;
    It sp34;
    It sp30;
    It sp2C;
    It sp28;
    It sp24;
    It sp20;
    u8 sp1C;
    u8 sp18;
    u8 sp14;
    u8 sp10;
    u8 spC;
    u8 sp8;
    void *head;
    void *tail;
    void *node;
    void *data;
    s32 count;
    u8 found;
    s8 key;

    key = *(s8 *)((u8 *)arg0 + 0x30);
    head = (u8 *)arg0 + 0x54;
    tail = *(void **)((u8 *)arg0 + 0x58);
    sp3C.node = head;
    sp38.node = head;
    sp34.node = head;
    sp30.node = head;
    sp70.node = head;
    sp2C.node = tail;
    sp28.node = tail;
    sp24.node = tail;
    sp20.node = tail;
    sp6C.node = tail;

    switch (key) {
    case 0:
        sp18 = arg1;
        sp1C = arg1;
        sp60.node = tail;
        sp64.node = head;
        while (sp64.node != tail) {
            found = 0;
            node = *(void **)sp64.node;
            data = *(void **)((u8 *)node + 8);
            if (*(s8 *)data >= 0 && (s8)arg1 == *(s8 *)((u8 *)data + 2)) {
                found = 1;
            }
            if (found == 0) {
                sp64.node = node;
                continue;
            }
            break;
        }
        sp68 = sp64;
        sp74 = sp64;
        break;
    case 1:
        sp10 = arg1;
        sp14 = arg1;
        sp54.node = tail;
        sp58.node = head;
        while (sp58.node != tail) {
            found = 0;
            node = *(void **)sp58.node;
            data = *(void **)((u8 *)node + 8);
            if (*(s8 *)data >= 0 && (s8)arg1 == *(s8 *)((u8 *)data + 1)) {
                found = 1;
            }
            if (found == 0) {
                sp58.node = node;
                continue;
            }
            break;
        }
        sp5C = sp58;
        sp74 = sp58;
        break;
    case 2:
        sp8 = arg1;
        spC = arg1;
        sp48.node = tail;
        sp4C.node = head;
        while (sp4C.node != tail) {
            found = 0;
            node = *(void **)sp4C.node;
            data = *(void **)((u8 *)node + 8);
            if (*(s8 *)data >= 0 && (s8)arg1 == *(s8 *)((u8 *)data + 4)) {
                found = 1;
            }
            if (found == 0) {
                sp4C.node = node;
                continue;
            }
            break;
        }
        sp50 = sp4C;
        sp74 = sp4C;
        break;
    }

    node = *(void **)sp74.node;
    data = *(void **)((u8 *)node + 8);
    if (*(s8 *)data >= 0) {
        count = 0;
        sp40 = sp74;
        sp44 = sp6C;
        while (sp40.node != sp6C.node) {
            count += 1;
            sp40.node = *(void **)sp40.node;
        }
        return (s8)(count - 1);
    }
          return *(s8 *)data;
}

#pragma global_optimizer off
#pragma optimization_level 3
s32 fn_801E8B38(void *arg0, u8 *arg1, s8 arg2) {
    s8 thresh;
    s32 var_r6;
    u8 var_r7;
    void *var_r5;
    s32 var_r0;
    s32 var_r8;
    u8 temp_r8;
    s16 temp_r7;
    u8 temp_r9;
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
            temp_r9 = *arg1;
            temp_r6 = *(s32 *)((u8 *)arg0 + 0x50) - 1;
            if ((((u32)(s8)temp_r9 <= (u32)temp_r6) && ((s8)((s8)temp_r9 - (*(s16 *)((u8 *)arg0 + 0x38) / 32)) > 8))
                || (((u32)(s8)temp_r9 < (u32)temp_r6) && ((s8)((s8)temp_r9 - (*(s16 *)((u8 *)arg0 + 0x38) / 32)) == 8))) {
                temp_r7 = *(s16 *)((u8 *)arg0 + 0x36);
                var_r6_2 = (s8)((s8)temp_r9 - ((s8)(temp_r7 / 32) + 8));
                if ((u32)(s8)temp_r9 < (u32)temp_r6) {
                    var_r6_2 += 1;
                }
                var_r8 = 1;
                *(s16 *)((u8 *)arg0 + 0x38) = (s16)((var_r6_2 << 5) + temp_r7);
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
#pragma optimization_level reset
#pragma global_optimizer on
void fn_801E8D34(void *arg0) {
    s32 fn_801E9410(void);
    u8 fn_801E85A4(void *, s32);
    s32 Abs(s32);
    void Process_ClearFunc(void *);
    void Process_Goto(void *, s32);
    void fn_80057860(void *, s16);
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
    s16 pos;
    s16 tgt;
    s32 pos32;
    s32 tgt32;
    s8 lo;
    s8 hi;
    void *str;
    s16 spC[2];
    s16 sp14[2];
    s16 sp8[2];
    s16 sp10[2];

    max = fn_801E9410();
    pad = gPadInput;
    t = *(u8 *)((u8 *)arg0 + 0x32);
    held = pad[3];
    cur = pad[1];
    old32 = (s8)t;
    buttons = cur & (pad[2] ^ cur);

    if (held & 0x08000008U) {
        t = *(u8 *)((u8 *)arg0 + 0x32);
        if ((s8)t == 0) {
            if (buttons == held) {
                *(u8 *)((u8 *)arg0 + 0x32) = (u8)(max - 1);
            }
        } else {
            *(u8 *)((u8 *)arg0 + 0x32) = t - 1;
        }
    } else if (held & 0x04000004U) {
        t = *(u8 *)((u8 *)arg0 + 0x32);
        max = max - 1;
        if ((u32)max == (u32)(s8)t) {
            if (buttons == held) {
                *(u8 *)((u8 *)arg0 + 0x32) = 0;
            }
        } else {
            *(u8 *)((u8 *)arg0 + 0x32) = t + 1;
        }
    }

    if (old32 != (s8)*(u8 *)((u8 *)arg0 + 0x32)) {
        if (fn_801E85A4(arg0, *(u8 *)((u8 *)arg0 + 0x32))) {
            if (Abs(old32 - (s8)*(u8 *)((u8 *)arg0 + 0x32)) == 1) {
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
            } else if ((s8)*(u8 *)((u8 *)arg0 + 0x32) < old32) {
                *(u8 *)((u8 *)arg0 + 0x33) = 0;
                *(s16 *)((u8 *)arg0 + 0x36) = 0;
                *(s16 *)((u8 *)arg0 + 0x38) = 0;
                fn_80057860(*(void **)((u8 *)arg0 + 0x5C), *(s16 *)((u8 *)arg0 + 0x36));
            } else {
                *(u8 *)((u8 *)arg0 + 0x33) = (u8)fn_801E4A60(arg0, *(u8 *)((u8 *)arg0 + 0x32));
                *(s16 *)((u8 *)arg0 + 0x36) = *(s16 *)((u8 *)arg0 + 0x38);
                fn_80057860(*(void **)((u8 *)arg0 + 0x5C), *(s16 *)((u8 *)arg0 + 0x36));
            }
        }
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
            fn_801E4900(spC, arg0);
            str = NULL;
            *(s32 *)sp14 = *(s32 *)spC;
            switch ((s8)*(u8 *)((u8 *)arg0 + 0x31)) {
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
        lo = fn_801E4A60(arg0, *(u8 *)((u8 *)arg0 + 0x32));
        hi = fn_801E8920(arg0, *(u8 *)((u8 *)arg0 + 0x32));
        *(u8 *)((u8 *)arg0 + 0x31) = 1;
        switch ((s8)*(u8 *)((u8 *)arg0 + 0x31)) {
        case 0:
            TextBanner_SetString(*(void **)((u8 *)arg0 + 0x60), Msg_Expand(gTabMenuStrings + 0x182));
            break;
        case 1:
            TextBanner_SetString(*(void **)((u8 *)arg0 + 0x60), Msg_Expand(gTabMenuStrings + 0x18D));
            break;
        }
        if ((s8)*(u8 *)((u8 *)arg0 + 0x33) > hi) {
            *(u8 *)((u8 *)arg0 + 0x33) = (u8)hi;
        }
        if ((s8)*(u8 *)((u8 *)arg0 + 0x33) < lo) {
            *(u8 *)((u8 *)arg0 + 0x33) = (u8)lo;
        }
        if (fn_801E91E8(arg0, (u8 *)arg0 + 0x33)) {
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
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
            fn_801E4900(sp8, arg0);
            str = NULL;
            *(s32 *)sp10 = *(s32 *)sp8;
            switch ((s8)*(u8 *)((u8 *)arg0 + 0x31)) {
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

s32 fn_801E91E8(void *arg0, u8 *arg1) {
    s16 temp_r6;
    s32 var_r8;
    u32 temp_r5;
    u32 temp_r0;
    s32 temp_r6_2;
    s8 var_r0;
    u8 var_r7;
    void *var_r5;
    s32 var_r0_2;
    u8 temp_r8;
    s16 temp_r7;
    u8 temp_r9;
    s32 temp_r6_3;
    s8 var_r6;

    temp_r6 = *(s16 *)((u8 *)arg0 + 0x36);
    var_r8 = 0;
    temp_r5 = (u32)temp_r6 >> 0x1F;
    temp_r0 = (temp_r6 << 0x1B) - temp_r5;
    temp_r6_2 = temp_r6 / 32;
    var_r0 = (s8)temp_r6_2 + 8;
    if ((((temp_r0 << 5) | (temp_r0 >> 0x1B)) + temp_r5) != 0) {
        var_r0 = (s8)temp_r6_2 + 9;
    }
    var_r7 = *arg1;
    if ((s8)var_r7 <= (s8)temp_r6_2) {
        var_r5 = *(void **)((u8 *)arg0 + 0x58);
        var_r0_2 = 0;
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
                var_r0_2 = 1;
                *(s16 *)((u8 *)arg0 + 0x38) = (s16)(temp_r7 - ((s8)(((s8)(temp_r7 / 32) - temp_r8) + 1) << 5));
            }
            if ((s8)*(u8 *)(*(void **)((u8 *)var_r5 + 8)) >= 0) {
                break;
            }
            var_r5 = *(void **)var_r5;
            *arg1 -= 1;
        } while (1);
        var_r8 = var_r0_2;
    } else if (var_r0 <= (s8)var_r7) {
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
            temp_r9 = *arg1;
            temp_r6_3 = *(s32 *)((u8 *)arg0 + 0x50) - 1;
            if ((((u32)(s8)temp_r9 <= (u32)temp_r6_3) && ((s8)((s8)temp_r9 - (*(s16 *)((u8 *)arg0 + 0x38) / 32)) > 8))
                || (((u32)(s8)temp_r9 < (u32)temp_r6_3) && ((s8)((s8)temp_r9 - (*(s16 *)((u8 *)arg0 + 0x38) / 32)) == 8))) {
                temp_r7 = *(s16 *)((u8 *)arg0 + 0x36);
                var_r6 = (s8)((s8)temp_r9 - ((s8)(temp_r7 / 32) + 8));
                if ((u32)(s8)temp_r9 < (u32)temp_r6_3) {
                    var_r6 += 1;
                }
                var_r8 = 1;
                *(s16 *)((u8 *)arg0 + 0x38) = (s16)((var_r6 << 5) + temp_r7);
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

#pragma global_optimizer off
s32 fn_801E9410(void *arg0) {
typedef struct {void *node;} It;
It aeCopy, ae, aCopy, a, beCopy, be, bCopy, b, ceCopy, ce, cCopy, c;
It beginACopy, beginA, endACopy, endA, beginBCopy, beginB, endBCopy, endB, beginCCopy, beginC, endCCopy, endC;
struct {s8 value;} initA, keyA, initB, keyB, initC, keyC;
void *end;
s32 count;
s32 result;
u8 found;
u8 value;
s8 tab;
tab = (s8)*((u8*)arg0+0x30);
switch(tab) {
case 0:
end=(u8*)arg0+0x54;
endACopy.node=end;
beginACopy.node=*(void**)((u8*)arg0+0x58);
beginA=beginACopy;
aCopy=beginA; a=aCopy;
endA=endACopy; aeCopy=endA; ae=aeCopy;
initA.value=-1;keyA=initA;
count=0;
while(a.node!=end) {
value=(*(u8**)((u8*)a.node+8))[2];
if(keyA.value!=(s8)value) {keyA.value=(s8)value;found=1;} else found=0;
if(found) count++;
a.node=*(void**)((u8*)a.node+4);
}
result=count; break;
case 1:
end=(u8*)arg0+0x54;
endBCopy.node=end;
beginBCopy.node=*(void**)((u8*)arg0+0x58);
beginB=beginBCopy;
bCopy=beginB; b=bCopy;
endB=endBCopy; beCopy=endB; be=beCopy;
initB.value=-1;keyB=initB;
count=0;
while(b.node!=end) {
value=(*(u8**)((u8*)b.node+8))[1];
if(keyB.value!=(s8)value) {keyB.value=(s8)value;found=1;} else found=0;
if(found) count++;
b.node=*(void**)((u8*)b.node+4);
}
result=count; break;
case 2:
end=(u8*)arg0+0x54;
endCCopy.node=end;
beginCCopy.node=*(void**)((u8*)arg0+0x58);
beginC=beginCCopy;
cCopy=beginC; c=cCopy;
endC=endCCopy; ceCopy=endC; ce=ceCopy;
initC.value=-1;keyC=initC;
count=0;
while(c.node!=end) {
value=(*(u8**)((u8*)c.node+8))[4];
if(keyC.value!=(s8)value) {keyC.value=(s8)value;found=1;} else found=0;
if(found) count++;
c.node=*(void**)((u8*)c.node+4);
}
result=count; break;
}
return result;
}
#pragma global_optimizer on
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
    table = Hash_Lookup(gTabMenuStrings + 0x226);
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

    temp_r0 = arg0[0];
    switch (temp_r0) {
case 0: case 1: break;
case 2: {
        temp_r6 = (void *)arg0[2];
        temp_r8 = *(void **)((u8 *)temp_r6 + 4);
        temp_r5 = *(void **)((u8 *)temp_r6 + 8);
        node8 = *(void **)((u8 *)temp_r8 + 8);
        if ((s8)*(u8 *)((u8 *)node8 + 3) < (s8)*(u8 *)((u8 *)temp_r5 + 3)) {
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
        temp_r9 = (void *)arg0[1];
        tmp = *(void **)var_r7;
        *(void **)((u8 *)tmp + 4) = *(void **)((u8 *)temp_r9 + 4);
        tmp = *(void **)var_r7;
        **(void ***)((u8 *)temp_r9 + 4) = tmp;
        *(void **)((u8 *)list.prev + 4) = var_r7;
        *(void **)var_r7 = list.prev;
        list.prev = temp_r9;
        *(void **)((u8 *)temp_r9 + 4) = &list.prev;
        list.count = arg0[0] - (s32)half;
        arg0[0] = (s32)half;
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
            tmp = *(void **)var_r29;
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
    void Heap_Free(void *);
    void fn_801EA618(s32 *, s32 *, u8 *);
    void *sp1C;
    void *sp18;
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

    temp_r0 = arg0[0];
    if (temp_r0 == 2) {
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
    } else if (temp_r0 < 0 || temp_r0 >= 3) {
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
                Heap_Free(temp_r3);
                sp14 -= 1;
            }
        }
    }
}

#pragma optimization_level 3
void fn_801EA248(s32 *arg0, u8 *arg1) {
    typedef struct Node { void *unk0; void *unk4; u8 *unk8; } Node;
    void Heap_Free(void *);
    void fn_801EA514(s32 *, s32 *, u8 *);
    struct { s32 count; void *prev; void *next; } list;
    struct Key { u8 value; } sp10, spC, sp8;
    Node *temp_r5;
    Node *temp_r6;
    Node *var_r7;
    void *temp_r3;
    void *var_r29;
    void *temp_r9;
    void *tmp;
    s32 temp_r0;
    u32 half;
    u32 n;

    temp_r0 = arg0[0];
    switch (temp_r0) {
    case 0:
    case 1:
        break;
    case 2:
        temp_r5 = (Node *)arg0[2];
        temp_r6 = (Node *)temp_r5->unk4;
        if ((s8)temp_r6->unk8[0] < (s8)temp_r5->unk8[0]) {
            tmp = temp_r5->unk0;
            temp_r5->unk0 = temp_r5->unk4;
            temp_r5->unk4 = tmp;
            tmp = temp_r6->unk0;
            temp_r6->unk0 = temp_r6->unk4;
            temp_r6->unk4 = tmp;
            tmp = (void *)arg0[1];
            arg0[1] = arg0[2];
            arg0[2] = (s32)tmp;
        }
        break;
    default:
        half = (u32)temp_r0 >> 1;
        var_r7 = (Node *)arg0[2];
        for (n = half; n != 0; --n) {
            var_r7 = (Node *)var_r7->unk4;
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
        list.count = arg0[0] - (s32)half;
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
            *(void **)((u8 *)tmp + 4) = *(void **)((u8 *)list.prev + 4);
            tmp = *(void **)var_r29;
            **(void ***)((u8 *)list.prev + 4) = tmp;
            while (var_r29 != &list.prev) {
                temp_r3 = var_r29;
                var_r29 = *(void **)((u8 *)var_r29 + 4);
                Heap_Free(temp_r3);
                list.count -= 1;
            }
        }
        break;
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
    void **node2;
    void **walk;
    void *sentinel1;
    void *sentinel2;
    void *last;
    void *previous;
    void *remaining;
    s8 key;
    s32 count;

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
            walk[0] = previous;

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
        u8 *data;
    } Node;

    typedef struct List {
        s32 count;
        Node sentinel;
    } List;

    void fn_80182514(u32 *, Node **, List *);

    List *dst;
    List *src;
    Node *first;
    Node *second;
    Node *dstEnd;
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
        if ((s8)second->data[3] < (s8)first->data[3]) {
            scan = second->next;
            count = 1;
            value = (s8)first->data[3];

            while (scan != srcEnd) {
                if ((s8)scan->data[3] >= value) {
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
