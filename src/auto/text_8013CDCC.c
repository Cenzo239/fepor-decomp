/* Functions from 0x80132800 to 0x80149F38, found by decomp-toolkit. */
#include "common.h"
typedef struct MenuSortTag { u8 value; } MenuSortTag;
static inline void *MenuSortAddress(void *base, s32 offset) { return (u8 *)base + offset; }
#pragma cplusplus on
struct MenuCenteredLabel {
virtual void v0()=0;
virtual void *getText()=0;
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
virtual void v20()=0;
virtual u8 test(s32)=0;
};
struct MenuCenteredPanel { u32 pad;
virtual void v0()=0;
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
virtual void v20()=0;
virtual void v21()=0;
virtual void v22()=0;
virtual void v23()=0;
virtual void v24()=0;
virtual void v25()=0;
virtual void v26()=0;
virtual void v27()=0;
virtual void v28()=0;
virtual void v29()=0;
virtual void v30()=0;
virtual void v31()=0;
virtual void v32()=0;
virtual void v33()=0;
virtual void v34()=0;
virtual void v35()=0;
virtual void v36()=0;
virtual void v37()=0;
virtual s32 height()=0;
};
#pragma cplusplus reset
#pragma cplusplus on
struct MenuDDEntry { u8 pad[0x40]; u8 id; };
struct MenuDD { u8 pad[4];
virtual s32 v0()=0;
virtual s32 v1()=0;
virtual s32 v2()=0;
virtual s32 v3()=0;
virtual s32 v4()=0;
virtual s32 v5()=0;
virtual s32 v6()=0;
virtual s32 v7()=0;
virtual s32 v8()=0;
virtual s32 v9()=0;
virtual s32 v10()=0;
virtual s32 v11()=0;
virtual s32 v12()=0;
virtual s32 v13()=0;
virtual s32 v14()=0;
virtual s32 v15()=0;
virtual s32 v16()=0;
virtual s32 v17()=0;
virtual s32 v18()=0;
virtual s32 v19()=0;
virtual s32 v20()=0;
virtual s32 v21()=0;
virtual s32 v22()=0;
virtual s32 v23()=0;
virtual s32 v24()=0;
virtual s32 v25()=0;
virtual s32 v26()=0;
virtual s32 v27()=0;
virtual s32 v28()=0;
virtual s32 v29()=0;
virtual s32 v30()=0;
virtual s32 v31()=0;
virtual s32 v32()=0;
virtual s32 v33()=0;
virtual s32 v34()=0;
virtual s32 v35()=0;
};
struct Menu349 {
virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void prepare()=0;
virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0; virtual void v8()=0; virtual void v9()=0; virtual void v10()=0;
virtual void draw(s16,s16,s16,s16,u8)=0;
};
struct Menu42 {
virtual void v0()=0; virtual void v1()=0; virtual void v2()=0;
virtual void draw(s32)=0;
virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0;
virtual void v8()=0; virtual void v9()=0; virtual s32 page()=0;
virtual void v11()=0; virtual void v12()=0; virtual void v13()=0;
virtual s32 item(void *)=0; virtual void row(s16,s16,s32,void *,s32)=0;
virtual void v16()=0; virtual void prepare()=0;
};
struct Menu42Callback { void (Menu42::*method)(s32); s32 arg; };
static inline void Menu42Visit(void *first, void *last, Menu42Callback cb) {
while(first!=last) {
Menu42 *obj=*(Menu42 **)((u8*)first+8);
(obj->*cb.method)(cb.arg);
first=*(void **)((u8*)first+4);
}
}
#pragma cplusplus reset
#include "common.h"
#include "dolphin/os.h"

extern u16 gSystemSave[36]; // 72 bytes 
extern f32 lbl_8036A6D0;
extern f32 gUiMenuSlotPlainTextScale;
extern f64 lbl_8036A720;

extern u16 gSystemSave[36]; // 72 bytes = 36 * 2-byte entries
extern f32 lbl_8036A5A8;
extern f32 lbl_8036A5AC;
extern f32 lbl_8036A5B8;

extern u8 gSeCueSlots[1344];

static inline s32 mul_ss(s32 a, s32 b) {
    return a * b;
}

static inline f32 mul_ss_f(s32 a, s32 b) {
    return (f32)(a * b);
}

typedef struct Vec2s {
    s16 x;
    s16 y;
} Vec2s;
#pragma cplusplus on
struct MenuPopupPosition {
 s16 x, y;
 MenuPopupPosition(s16 xx, s16 yy): x(xx), y(yy) {}
 MenuPopupPosition(const MenuPopupPosition &other) { *(u32 *)this = *(const u32 *)&other; }
};
static inline u8 *MenuPopup_AdvanceNode(s16 distance, u8 *node) {
 s16 count = distance;
 if (count >= 0) {
  while (count > 0) { node = *(u8 **)(node + 4); --count; }
 } else {
  while (count < 0) { node = *(u8 **)node; ++count; }
 }
 return node + 8;
}
static inline u8 *MenuPopup_AdvanceNode(u8 *node, s16 count) { return MenuPopup_AdvanceNode(count, node); }
struct MenuPopupHost {
virtual void v0()=0;
virtual void v1()=0;
virtual void v2()=0;
virtual void v3()=0;
virtual void v4()=0;
virtual void v5()=0;
virtual void v6()=0;
virtual void v7()=0;
virtual void v8()=0;
virtual void setSelection(void *)=0;
virtual s32 getPage()=0;
virtual void v11()=0;
virtual void v12()=0;
virtual MenuPopupPosition getPosition()=0;
};
#pragma cplusplus reset

typedef struct {
    u8 unk0;
} Unk1;


typedef struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    void *val;
} ListNode;

typedef struct ListIter {
    ListNode *node;
} ListIter;

typedef struct List {
    s32 size;
} List;

typedef struct Anim Anim;
typedef void (*AnimFn)(Anim *);

struct Anim {
    u8 pad0[8];
    AnimFn *funcs;      /* +0x08 */
    u8 flags;           /* +0x0C */
    u8 unk_d;           /* +0x0D */
    u8 unk_e;           /* +0x0E */
    u8 pad_f;           /* +0x0F */
    u8 unk_10;          /* +0x10 */
    u8 delay;           /* +0x11 */
    s16 unk_12;         /* +0x12 */
    u8 pad14[2];
    u8 cur;             /* +0x16 */
    u8 prev;            /* +0x17 */
    AnimFn *draw;       /* +0x18 */
    u8 pad1C[0xC];
    u8 start;           /* +0x28 */
    u8 end;             /* +0x29 */
    u8 pad2A[2];
    u16 frame;          /* +0x2C */
    u16 frames;         /* +0x2E */
};

#pragma global_optimizer off

#pragma global_optimizer on

#pragma cplusplus on

#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma scheduling on
#pragma opt_lifetimes off

#pragma opt_lifetimes reset
#pragma scheduling reset
#pragma use_lmw_stmw reset

void Item_Copy(void *);

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma push
#pragma global_optimizer on
#pragma scheduling on

#pragma pop
#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma global_optimizer off

#pragma optimization_level reset
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma scheduling on
#pragma scheduling on
#pragma global_optimizer off
#pragma optimization_level 3
#pragma peephole off

#pragma peephole reset
#pragma optimization_level reset
#pragma global_optimizer reset
#pragma scheduling reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset
#pragma global_optimizer off
#pragma cplusplus on

#pragma cplusplus reset
#pragma global_optimizer reset

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma global_optimizer off
#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma cplusplus reset
#pragma global_optimizer reset

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma cplusplus on
/* C++ destructor for a unit-panel widget (gUiUnitPanelVtbl): destroy embeds, clear list, base dtor, optional free. */

#pragma cplusplus reset

#pragma cplusplus on
/* C++ destructor for a mid unit-panel widget (gUiUnitPanelMidVtbl): destroy embeds, clear list, base dtor, optional free. */

#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

extern f32 lbl_8036A620;
extern f32 lbl_8036A628;
extern f64 lbl_8036A630;
extern u8 lbl_802767E0[192];
extern void Prim2D_Begin(void);
extern s32 Prim2D_SetTex(s32, u16);
extern void Prim2D_PrepareTex(void);
extern void *Msg_Expand(s32);
extern s32 fn_8001003C(s16, s16, u8, u8, u8, void*, f32, f32, f32);
extern s32 fn_8007CCE8(s32, f32, f32);

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma cplusplus reset
#pragma peephole off

#pragma peephole on

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus reset

extern s32 fn_80138AB8(void *);

#pragma dont_inline on

#pragma dont_inline reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" void Prim2D_AddZ(f32);
extern "C" void Text_Draw(s16, s16, u8, char *, ...);
extern "C" s32 Text_MeasureHeight(s32, f32);
extern "C" s32 Convoy_FindEmpty(void *);
extern "C" u8 fn_8014D8DC(void *);
extern "C" void fn_80155F20(s32, s32, s16, s16, s32, s32);
extern "C" void Ui_DrawLine(s16, s16, s16, s16, s32, u8 *);

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma global_optimizer off

#pragma global_optimizer on
#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma global_optimizer off
#pragma cplusplus on

#pragma cplusplus reset
#pragma global_optimizer reset

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma global_optimizer off

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma global_optimizer on
#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
/* C++ destructor for a UI panel (gUiPanelVtbl): destroy embeds, clear list, run base dtor, optional free. */

#pragma cplusplus reset

#pragma cplusplus on
/* C++ destructor for a UI panel (gUiPanelExVtbl): destroy embeds, clear list, run base dtor, optional free. */

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
struct RefObj {
    virtual ~RefObj();
    s32 refCount;
};
extern "C" void Ui_DrawAtlasRect75(s32, s32, s32);
extern "C" void fn_8013692C(s32, s32, s32, s32, s32, s32);

#pragma cplusplus on
/* Space each child gfx ent evenly across parent width (v18); y = panel v37-v38. */

#pragma cplusplus reset

#pragma cplusplus reset

#pragma optimization_level 2
#pragma scheduling on

#pragma scheduling reset
#pragma optimization_level reset

s32 fn_8013CDCC(void) {
    s8 Ui_PlaySeCue(void *, int);
    extern u8 gUiContext[24];
    extern u8 lbl_80276908[];
    u8 *ptr1 = (u8 *)&gUiContext;
    u8 *ptr2 = (u8 *)&lbl_80276908;
    ptr1[8] = 0x80;
    Ui_PlaySeCue(ptr2 + 0x73, 0x64);
    return 1;
}

void fn_8013CE10(void *arg0) {
    extern u16 lbl_8028459C[];
    extern u16 lbl_80291BEC[];
    extern u16 lbl_80292090[];
    extern u16 lbl_80276908[];
    extern u16 lbl_80291E48[];
    
    *(u16 **)arg0 = lbl_8028459C;
    *(u16 **)arg0 = lbl_80291BEC;
    *(u16 **)arg0 = lbl_80292090;
    *(void **)((char *)arg0 + 4) = (void *)((s32)lbl_80276908 + 0x4E);
    *((u8 *)arg0 + 8) = 2;
    *((u8 *)arg0 + 9) = 0;
    *(u16 **)arg0 = lbl_80291E48;
}

s32 fn_8013CE64(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x81;
    return 5;
}

void fn_8013CE7C(void *arg0) {
    extern u16 lbl_8028459C[];
    extern u16 lbl_80292090[];
    extern u16 lbl_80291BEC[];
    extern u16 lbl_80276908[];
    extern u16 lbl_80291EAC[];

    *(u16 **)arg0 = lbl_8028459C;
    *(u16 **)arg0 = lbl_80292090;
    *(u16 **)arg0 = lbl_80291BEC;
    *(void **)((char *)arg0 + 4) = (void *)((s32)lbl_80276908 + 0x46);
    *((u8 *)arg0 + 8) = 2;
    *((u8 *)arg0 + 9) = 0;
    *(u16 **)arg0 = lbl_80291EAC;
}

#pragma opt_lifetimes off
void fn_8013CED0(void *arg0, void *arg1) {
    extern u8 gUiMenuDrawVtbl[];
    extern u8 lbl_802920E0[];
    extern u8 lbl_80291DA0[];
    extern f32 lbl_8036A6B8;
    f32 f;
    s32 z;

    z = 0;
    *(void **)((u8 *)arg0 + 4) = gUiMenuDrawVtbl;
    *(void **)arg0 = arg1;
    f = lbl_8036A6B8;
    *(void **)((u8 *)arg0 + 4) = lbl_802920E0;
    *(s16 *)((u8 *)arg0 + 8) = 0x80;
    *(s16 *)((u8 *)arg0 + 0xA) = 0x9C;
    *(s16 *)((u8 *)arg0 + 0xC) = 0x160;
    *(s16 *)((u8 *)arg0 + 0xE) = 0x88;
    *(s16 *)((u8 *)arg0 + 0x10) = z;
    *(s16 *)((u8 *)arg0 + 0x12) = z;
    *(s16 *)((u8 *)arg0 + 0x14) = z;
    *(s16 *)((u8 *)arg0 + 0x16) = z;
    *(f32 *)((u8 *)arg0 + 0x18) = f;
    *(s16 *)((u8 *)arg0 + 0x1C) = 0x20;
    *(s16 *)((u8 *)arg0 + 0x1E) = 4;
    *(void **)((u8 *)arg0 + 4) = lbl_80291DA0;
    *(s32 *)((u8 *)arg0 + 0x20) = z;
    *(s8 *)((u8 *)arg0 + 0x24) = z;
}
#pragma opt_lifetimes reset
#pragma cplusplus on
extern "C" void Ui_DrawMenuSlotPlain(void *self, void *unused, void *slot) {
    void Prim2D_SetText(s32);
    void Prim2D_SetTextScale(s32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    s32 Text_MeasureHeight(s32, f32);
    s32 Text_MeasureWidth(s32, s32, f32);
    void Ui_DrawSlotFrame(s32, s32, u8, s32);
    s32 *Ui_GetColor(s32);
    extern f32 lbl_8036A6C0;
    extern f32 gUiMenuSlotPlainTextScale;
    extern f32 gUiMenuSlotPlainTextZ;
    extern f32 gUiMenuSlotPlainFrameZ;
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual s32 getLabel(void *) = 0;
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
        virtual void draw() = 0;
    };
    // Draw a menu slot's centered label and frame (no dimming).
    s32 padX;
    s32 padY;
    void *item;
    s32 colorSel;
    f32 x;
    f32 y;
    void *labelObj;
    s32 label;
    void *labelObj2;
    s32 label2;

    item = slot;
    ((Obj *)self)->draw();
    Prim2D_Begin();
    Prim2D_AddZ(gUiMenuSlotPlainTextZ);
    Prim2D_PrepareTex();
    labelObj = M2C_FIELD(item, void **, 0x34);
    label = ((Obj *)labelObj)->getLabel(item);
    padX = (0x9A - Text_MeasureWidth(label, -1, lbl_8036A6C0)) >> 1;
    padY = (0x24 - Text_MeasureHeight(-1, lbl_8036A6C0)) >> 1;
    x = (f32)M2C_FIELD(item, s16 *, 0x30);
    y = (f32)M2C_FIELD(item, s16 *, 0x32);
    Prim2D_AddPrim(6);
    Prim2D_SetPos(x + (f32)padX, y + (f32)padY);
    if ((u8)M2C_FIELD(item, u8 *, 0x39) == 2) {
        colorSel = *Ui_GetColor(0);
        Prim2D_SetColorPacked(&colorSel);
    } else {
        Prim2D_SetTextScale(1, gUiMenuSlotPlainTextScale);
    }
    labelObj2 = M2C_FIELD(item, void **, 0x34);
    label2 = ((Obj *)labelObj2)->getLabel(item);
    Prim2D_SetText(label2);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(gUiMenuSlotPlainFrameZ);
    Prim2D_PrepareTex();
    Ui_DrawSlotFrame((s32)x, (s32)y, M2C_FIELD(item, u8 *, 0x38), 0x10);
}
#pragma cplusplus reset
void fn_8013D10C(void) {
    M2C_UNK Prim2D_SetTex(M2C_UNK, M2C_UNK);
    M2C_UNK Prim2D_PrepareTex();
    M2C_UNK Prim2D_Begin();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
}

void fn_8013D13C(void) {

}

#pragma cplusplus on
extern "C" void fn_8013D140(void *arg0) {
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
    };
    void Ui_DrawAtlasLCorner(s32, s32, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetAlphaByte(s32);
    void Prim2D_PrepareTex(void);

    ((Obj *)arg0)->v30();
    Ui_DrawAtlasLCorner(0, 0, 0x10);
    Prim2D_Begin();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}

#pragma cplusplus on
extern "C" void fn_8013D18C(void *arg0, s32 arg1) {
    f32 UiWin_GetFade(s32);
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Prim2D_Begin(void);
    void Prim2D_SetColorByte(s32);
    void Prim2D_PrepareTex(void);
    void fn_80009C20(f32, f32, f32, f32, f32, f32, f32, f32);
    struct Obj {
        u8 pad[4];
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
        virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
        virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0;
        virtual void v15() = 0; virtual void v16() = 0; virtual void v17() = 0;
        virtual void v18() = 0; virtual void v19() = 0; virtual void v20() = 0;
        virtual s16 getX() = 0;
        virtual s16 getY() = 0;
        virtual void v23() = 0; virtual void v24() = 0;
        virtual f32 getZ() = 0;
    };
    f32 fade;
    f32 eased;

    fade = UiWin_GetFade(arg1);
    eased = Math_Ease(5, 0.0f, 1.0f, fade, 1.0f);
    Prim2D_Begin();
    fn_80009C20(((Obj *)arg0)->getX(), ((Obj *)arg0)->getY(), ((Obj *)arg0)->getZ(), 0.0f, 0.0f, eased, eased, 0.0f);
    Prim2D_SetColorByte((s32)(255.99f * fade));
    Prim2D_PrepareTex();
}
#pragma cplusplus reset
#pragma push
#pragma optimization_level 4
extern "C" void fn_8013D2E0(void *arg0, void *arg1) {
    void *GfxEnt_Get(u8);
    void Ui_PlaySeCue(void *, s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoPopup(void *, void *, f32, f32);
    void Ui_ShowUnitInfoText(void *, void *, f32, f32);
    extern s32 gUiInputFlags;
    extern u32 *gPadInput;
    extern u8 gUnitInfoPopup[];
    extern f64 lbl_8036A6C8;
    extern u8 lbl_80276908[];

    struct Outer {
        u8 pad[4];
        virtual s32 v0() = 0; virtual s32 v1() = 0; virtual s32 v2() = 0;
        virtual s32 v3() = 0; virtual s32 v4() = 0; virtual s32 v5() = 0;
        virtual s32 v6() = 0; virtual s32 v7() = 0; virtual s32 v8() = 0;
        virtual s32 v9() = 0; virtual s32 v10() = 0; virtual s32 v11() = 0;
        virtual s32 v12() = 0; virtual s32 v13() = 0; virtual s32 v14() = 0;
        virtual s32 v15() = 0; virtual s32 v16() = 0; virtual s32 v17() = 0;
        virtual s32 v18() = 0; virtual s32 v19() = 0; virtual s32 v20() = 0;
        virtual s32 v21() = 0; virtual s32 v22() = 0; virtual s32 v23() = 0;
        virtual s32 v24() = 0; virtual s32 v25() = 0; virtual s32 v26() = 0;
        virtual s32 v27() = 0; virtual s32 v28() = 0; virtual s32 v29() = 0;
        virtual s32 v30() = 0; virtual s32 v31() = 0; virtual s32 v32() = 0;
        virtual s32 Rows() = 0;
        virtual s32 Cols() = 0;
    };
    struct Inner {
        virtual void v0() = 0; virtual void v1() = 0; virtual void *v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
        virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
        virtual void v12() = 0; virtual void v13() = 0;
        virtual void Select(void *, void *) = 0;
        virtual void Deselect(void *, void *) = 0;
        virtual void *GetObj(void *) = 0;
    };

    Outer *self = (Outer *)arg0;
    u8 *p = (u8 *)arg1;
    s8 maxIdx = (s8)p[0x60];
    s32 rows = self->Rows();
    s32 cols = self->Cols();
    u8 skip = 0;
    s16 row = (s16)((s8)p[0x62] / (s16)cols);
    s16 col = (s16)((s8)p[0x62] % (s16)cols);
    u32 trig, held, edge;
    s16 rem;
    s16 sum;
    void *item;
    Inner *inner;
    f32 fx, fy;
    void *obj;

    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20))
        skip = 1;
    if (skip == 0) {
        trig = gPadInput[3];
        held = gPadInput[1];
        edge = held & (gPadInput[2] ^ held);
        p[0x63] = p[0x62];
        if ((s16)cols > 1) {
            rem = (s16)(maxIdx - row * (s16)cols);
            if (rem > (s16)cols)
                rem = cols;
            if (trig & 0x01000001) {
                if (col > 0)
                    p[0x62] = (u8)(p[0x62] - 1);
                else if (trig == edge) {
                    sum = (s16)(rem + p[0x62]);
                    p[0x62] = (u8)(sum - 1);
                }
            } else if (trig & 0x02000002) {
                if (col < rem - 1)
                    p[0x62] = (u8)(p[0x62] + 1);
                else if (trig == edge)
                    p[0x62] = (u8)(p[0x62] - (rem - 1));
            }
        }
        if (trig & 0x08000008) {
            if (row == 0) {
                if (trig == edge) {
                    p[0x62] = (u8)(p[0x62] + (rows - 1) * (s16)cols);
                    if ((s8)p[0x62] > maxIdx - 1)
                        p[0x62] = (u8)(maxIdx - 1);
                }
            } else {
                p[0x62] = (u8)(p[0x62] - cols);
            }
        } else if (trig & 0x04000004) {
            if (row == (s16)rows - 1) {
                if (trig == edge)
                    p[0x62] = (u8)(p[0x62] - ((s16)rows - 1) * (s16)cols);
            } else {
                p[0x62] = (u8)(p[0x62] + cols);
                if ((s8)p[0x62] > maxIdx - 1)
                    p[0x62] = (u8)(maxIdx - 1);
            }
        }
        if ((s8)p[0x62] != (s8)p[0x63]) {
            item = GfxEnt_Get(p[0x40 + (s8)p[0x63]]);
            inner = *(Inner **)((u8 *)item + 0x34);
            inner->Deselect(arg1, item);
            item = GfxEnt_Get(p[0x40 + (s8)p[0x62]]);
            inner = *(Inner **)((u8 *)item + 0x34);
            inner->Select(arg1, item);
            if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
                item = GfxEnt_Get(p[0x40 + (s8)p[0x62]]);
                fx = (f32)(*(s16 *)(p + 0x30) + *(s16 *)((u8 *)item + 0x30));
                item = GfxEnt_Get(p[0x40 + (s8)p[0x62]]);
                fy = (f32)(*(s16 *)(p + 0x32) + *(s16 *)((u8 *)item + 0x32));
                item = GfxEnt_Get(p[0x40 + (s8)p[0x62]]);
                inner = *(Inner **)((u8 *)item + 0x34);
                obj = inner->v2();
                if (obj != NULL) {
                    Ui_ShowUnitInfoText(gUnitInfoPopup, obj, fx, fy);
                } else {
                    item = GfxEnt_Get(p[0x40 + (s8)p[0x62]]);
                    inner = *(Inner **)((u8 *)item + 0x34);
                    Ui_ShowUnitInfoPopup(gUnitInfoPopup, inner->GetObj(item), fx, fy);
                }
            }
            Ui_PlaySeCue(lbl_80276908 + 0x83, 0x64);
        }
    }
}
#pragma pop

extern "C" void fn_8013D6E0(void *arg0, void *arg1) {
void *GfxEnt_Get(u8);
#pragma cplusplus on
struct Obj { u8 pad[4];
virtual s32 v0()=0; virtual s32 v1()=0; virtual s32 v2()=0;
virtual s32 v3()=0; virtual s32 v4()=0; virtual s32 v5()=0;
virtual s32 v6()=0; virtual s32 v7()=0; virtual s32 v8()=0;
virtual s32 v9()=0; virtual s32 v10()=0; virtual s32 v11()=0;
virtual s32 v12()=0; virtual s32 v13()=0; virtual s32 v14()=0;
virtual s32 v15()=0; virtual s32 v16()=0; virtual s32 v17()=0;
virtual s32 v18()=0; virtual s32 v19()=0; virtual s16 v20()=0;
virtual s32 v21()=0; virtual s32 v22()=0; virtual s32 v23()=0;
virtual s32 v24()=0; virtual s32 v25()=0; virtual s32 v26()=0;
virtual s32 v27()=0; virtual s32 v28()=0; virtual s32 v29()=0;
virtual s32 v30()=0; virtual s32 v31()=0; virtual s32 v32()=0;
virtual s16 v33(void *)=0; virtual s16 v34()=0; virtual s16 v35()=0;
};
u8 *p=(u8*)arg1;
s16 dx=((Obj*)arg0)->v35();
Obj *self=(Obj*)arg0;
s16 dy=self->v20();
s16 x=self->v16()+self->v31();
s16 y=self->v17()+self->v32();
s16 rows=self->v33(arg1);
s16 cols=self->v34();
s32 row=0, index=0;
for (;row<rows && index<(s8)p[0x60]; ++row) {
s32 yy=y+row*dy;
s32 col=0;
for (;col<cols && index<(s8)p[0x60];++col,++index) {
void *ent=GfxEnt_Get(p[0x40+index]);
*(s16*)((u8*)ent+0x30)=x+col*dx;
*(s16*)((u8*)ent+0x32)=(int)yy;
}
}
#pragma cplusplus reset
}

extern "C" void fn_8013D85C(void *self, void *host, void *slot) {
    void Prim2D_SetText(s32);
    void Prim2D_SetTextScale(s32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetAlphaByte(u8);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    s32 Text_MeasureHeight(s32, f32);
    s16 Text_MeasureWidth(s32, s32, f32);
    void Ui_DrawIcon(void *, s32, s32, s32);
    s32 *Ui_GetColor(s32);
    extern u8 gUiIconDrawer[];
    extern f32 lbl_8036A6C0;
    extern f32 gUiMenuSlotPlainTextScale;

    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual s32 getLabel(void *) = 0;
        virtual s32 getIconId() = 0;
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
        virtual void draw() = 0;
    };
    struct Host {
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
        virtual s16 getInnerH() = 0;
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
        virtual void v31() = 0;
        virtual void v32() = 0;
        virtual void v33() = 0;
        virtual void v34() = 0;
        virtual s16 getInnerW() = 0;
    };

    s32 packedColor;
    s32 hostH;
    s32 iconPad;
    s32 yOff;
    s32 iconYOff;
    s32 labelWidth;
    s16 hostW;
    f32 drawX;
    f32 drawY;
    s32 xPad;

    ((Obj *)self)->draw();

    {
        s32 v = ((Obj *)*(void **)((u8 *)slot + 0x34))->getIconId();
        void *p3c = *(void **)((u8 *)host + 0x3c);
        iconPad = v != 0 ? 0x18 : 0;
        hostH = ((Host *)p3c)->getInnerH();
    }
    yOff = (hostH - Text_MeasureHeight(-1, lbl_8036A6C0)) >> 1;
    iconYOff = ((((Host *)*(void **)((u8 *)host + 0x3c))->getInnerH() - 0x18) >> 1);

    labelWidth = Text_MeasureWidth(((Obj *)*(void **)((u8 *)slot + 0x34))->getLabel(slot), -1, lbl_8036A6C0);
    hostW = ((Host *)*(void **)((u8 *)host + 0x3c))->getInnerW();
    xPad = hostW - (labelWidth + iconPad);
    drawX = (f32)(*(s16 *)((u8 *)slot + 0x30) + (xPad >> 1));
    drawY = (f32)*(s16 *)((u8 *)slot + 0x32);
    Prim2D_AddPrim(6);
    Prim2D_SetPos(drawX + (f32)iconPad, drawY + (f32)yOff);
    if (*(u8 *)((u8 *)slot + 0x39) == 2) {
        packedColor = *Ui_GetColor(0);
        Prim2D_SetColorPacked(&packedColor);
    } else {
        Prim2D_SetTextScale(1, gUiMenuSlotPlainTextScale);
    }
    Prim2D_SetText(((Obj *)*(void **)((u8 *)slot + 0x34))->getLabel(slot));
    Prim2D_EndPrim();
    if (((Obj *)*(void **)((u8 *)slot + 0x34))->getIconId() != 0) {
        Ui_DrawIcon(gUiIconDrawer, (s32)drawX, (s32)(drawY + (f32)iconYOff), ((Obj *)*(void **)((u8 *)slot + 0x34))->getIconId());
    }
    Prim2D_Begin();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_8013DAD8(void *self, void *host, void *slot) {
    void Prim2D_SetText(s32);
    void Prim2D_SetTextScale(s32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetAlphaByte(u8);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    s32 Text_MeasureHeight(s32, f32);
    void Ui_DrawIcon(void *, s32, s32, s32);
    s32 *Ui_GetColor(s32);
    extern u8 gUiIconDrawer[];
    extern f32 lbl_8036A6C0;
    extern f32 gUiMenuSlotPlainTextScale;

    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual s32 getLabel(void *) = 0;
        virtual s32 getIconId() = 0;
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
        virtual void draw() = 0;
    };
    struct Host {
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
        virtual s16 getInnerH() = 0;
    };

    s32 packedColor;
    s32 iconPad;
    s32 hostH;
    s32 yOff;
    s32 iconYOff;
    s32 iconId;
    f32 drawX;
    f32 drawY;
    void *p3c;

    ((Obj *)self)->draw();

    iconId = ((Obj *)*(void **)((u8 *)slot + 0x34))->getIconId();
    p3c = *(void **)((u8 *)host + 0x3C);
    iconPad = iconId != 0 ? 0x18 : 0;
    hostH = ((Host *)p3c)->getInnerH();
    yOff = (hostH - Text_MeasureHeight(-1, lbl_8036A6C0)) >> 1;
    iconYOff = (((Host *)*(void **)((u8 *)host + 0x3C))->getInnerH() - 0x18) >> 1;

    drawX = (f32) *(s16 *)((u8 *)slot + 0x30);
    drawY = (f32) *(s16 *)((u8 *)slot + 0x32);
    Prim2D_AddPrim(6);
    Prim2D_SetPos(drawX + (f32)iconPad, drawY + (f32)yOff);

    if (*(u8 *)((u8 *)slot + 0x39) == 2) {
        packedColor = *Ui_GetColor(0);
        Prim2D_SetColorPacked(&packedColor);
    } else {
        Prim2D_SetTextScale(1, gUiMenuSlotPlainTextScale);
    }

    Prim2D_SetText(((Obj *)*(void **)((u8 *)slot + 0x34))->getLabel(slot));
    Prim2D_EndPrim();

    if (((Obj *)*(void **)((u8 *)slot + 0x34))->getIconId() != 0) {
        Ui_DrawIcon(gUiIconDrawer, (s32)drawX, (s32)(drawY + (f32)iconYOff), ((Obj *)*(void **)((u8 *)slot + 0x34))->getIconId());
    }

    Prim2D_Begin();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}
#pragma cplusplus reset
void fn_8013DD1C(s32 arg0, void *arg1) {
    M2C_UNK Prim2D_SetAlphaByte(M2C_UNK);
    u8 var_r3;
    u8 var_r3_2;

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    var_r3 = 0;
    if ((M2C_FIELD(arg1, u8 *, 0x2D) == 0) && (M2C_FIELD(arg1, u8 *, 0x2E) == 0)) {
        var_r3 = 1;
    }
    var_r3_2 = 0x40;
    if (var_r3 != 0) {
        var_r3_2 = 0x80;
    }
    Prim2D_SetAlphaByte(var_r3_2);
    Prim2D_PrepareTex();
}

#pragma cplusplus on
#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
#pragma global_optimizer on
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_lifetimes off
extern "C" void fn_8013DD90(MenuDD *self,u8 *ctx) {
void *GfxEnt_Get(s32);
void Prim2D_Begin(); void Prim2D_AddZ(f32); void Prim2D_PrepareTex(); void Prim2D_SetAlphaByte(u8);
void Ui_DrawRouteIconEx(s16,s32,u8);
void fn_8008AB7C(s32,s32,s32,s32,s32,s32,s32);
s32 width,height; s32 x,y; u8 idle; s32 active;
self->v30();
x=*(s16*)((u8*)GfxEnt_Get(ctx[(s8)ctx[0x62]+0x40])+0x30);
y=*(s16*)((u8*)GfxEnt_Get(ctx[(s8)ctx[0x62]+0x40])+0x32);
width=self->v35(); height=self->v20();
if(*(s16*)(ctx+0x3a)<0) { *(s16*)(ctx+0x38)=x; *(s16*)(ctx+0x3a)=y; }
else { s32 nx=x+1; s32 ny=y+1; s32 cur=*(s16*)(ctx+0x38);
cur+=nx; *(s16*)(ctx+0x38)=cur/2;
ny+=*(s16*)(ctx+0x3a); *(s16*)(ctx+0x3a)=ny/2;
}
Prim2D_Begin(); Prim2D_AddZ(lbl_8036A6D0);
idle=0; if(!ctx[0x2d] && !ctx[0x2e]) idle=1;
Prim2D_SetAlphaByte(idle?0x80:0x40); Prim2D_PrepareTex();
s16 ix=*(s16*)(ctx+0x38); s32 iy=*(s16*)(ctx+0x3a);
u8 iconIdle=0; if(!ctx[0x2d] && !ctx[0x2e]) iconIdle=1;
Ui_DrawRouteIconEx(ix,iy,iconIdle);
Prim2D_Begin(); Prim2D_AddZ(gUiMenuSlotPlainTextScale); Prim2D_PrepareTex();
active=0; if(!ctx[0x2d] && !ctx[0x2e]) active=1;
s16 w=width; s32 offset=(s16)self->v31();
s32 left=x-offset;
fn_8008AB7C((w>>1)+left,y+((s16)height>>1),w,0x17,0x19,0x4c,active);
Prim2D_Begin(); Prim2D_SetAlphaByte(0x80); Prim2D_PrepareTex();
}
#pragma pop
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
extern "C" void Ui_DrawListWindowFrame(s32, s32, s32, s16, s32, s32);
s32 Prim2D_SetAlphaByte(u8);
extern "C" void Ui_DrawListPanelBg(void *panel, s32 count) {
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
        virtual s16 v17() = 0;
        virtual s32 v18() = 0;
        virtual s16 v19() = 0;
        virtual s16 v20() = 0;
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
        virtual void v31() = 0;
        virtual void v32() = 0;
        virtual s16 v33(s32) = 0;
    };
    s16 height;

    /* Draw a list panel's framed window chrome (no footer separator). */
    ((Obj *)panel)->v30();
    height = ((Obj *)panel)->v19();
    if (height == 0) {
        height = ((Obj *)panel)->v20() * ((Obj *)panel)->v33(count) + ((Obj *)panel)->v17() * 2;
    }
    Ui_DrawListWindowFrame(0, 0, ((Obj *)panel)->v18(), height, 0xE6, 0x10);
    Prim2D_Begin();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}

#pragma push
#pragma optimization_level 4
extern "C" void fn_8013E080(void *arg0, void *arg1) {
struct Obj { u8 pad[4];
virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0;
virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void v11()=0;
virtual void v12()=0; virtual void v13()=0; virtual void v14()=0; virtual void v15()=0;
virtual void v16()=0; virtual void v17()=0; virtual void v18()=0; virtual void v19()=0;
virtual void v20()=0;
virtual s16 getX()=0; virtual s16 getY()=0; virtual void v23()=0; virtual void v24()=0; virtual f32 getZ()=0;
};
f32 UiWin_GetFade(void *); f32 Math_Ease(s32,f32,f32,f32,f32);
void fn_80009C20(f32,f32,f32,f32,f32,f32,f32,f32);
void Prim2D_Begin(void); void Prim2D_SetColorByte(s32); void Prim2D_SetAlphaByte(s32); void Prim2D_PrepareTex(void);

f32 y, z, fade, scale; s16 x;
u8 focused, alpha;
void *o;
fade=UiWin_GetFade(arg1);
scale=Math_Ease(5,0.0f,1.0f,fade,1.0f);
Prim2D_Begin();
o=arg0;
fn_80009C20(((Obj *)o)->getX(),((Obj *)o)->getY(),((Obj *)o)->getZ(),0.0f,0.0f,scale,scale,0.0f);
Prim2D_SetColorByte((s32)(255.99f*fade));
focused=0;
if(*((u8 *)arg1+0x2D)==0 && *((u8 *)arg1+0x2E)==0) focused=1;
alpha=0x40;
if(focused) alpha=0x80;
Prim2D_SetAlphaByte(alpha);
Prim2D_PrepareTex();
}
#pragma pop
extern "C" void *GfxEnt_Get(u8);
extern "C" void fn_8013E218(void *arg0, void *arg1) {
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
        virtual s16 v31() = 0;
        virtual s16 v32() = 0;
    };
    s32 i;
    void *p;
    u8 *arg1_bytes = (u8 *)arg1;

    for (i = 0; i < *(s8 *)&arg1_bytes[0x60]; i++) {
        p = GfxEnt_Get(arg1_bytes[0x40 + i]);
        *(s16 *)((u32)p + 0x30) += ((Obj *)arg0)->v31();
        *(s16 *)((u32)p + 0x32) += ((Obj *)arg0)->v32();
    }
}

extern "C" void fn_8013E2C8(void *arg0) {
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
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual void v25() = 0;
        virtual void v26() = 0;
        virtual void v27() = 0;
        virtual void v28() = 0;
        virtual void v29(s32) = 0;
    };
    if (arg0 != NULL) {
        ((Obj *)arg0)->v29(1);
    }
}

#pragma cplusplus reset

void fn_8013E300(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0;
}

void *fn_8013E314(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_80291C50[];
    extern void *lbl_80291DA0[];
    extern void *lbl_802920E0[];

    if (arg0 != NULL) {
        *(void **)((u8 *)arg0 + 4) = lbl_80291C50;
        if (arg0 != NULL) {
            *(void **)((u8 *)arg0 + 4) = lbl_80291DA0;
            if (arg0 != NULL) {
                *(void **)((u8 *)arg0 + 4) = lbl_802920E0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

s32 fn_8013E380(void) {
    return 0x38;
}

s32 fn_8013E388(void) {
    return 0x62;
}

s32 fn_8013E390(void) {
    return 0x1C;
}

#pragma cplusplus on
extern "C" void fn_8015B820(s32, s32, s32);
extern "C" void fn_8013E398(void *arg0) {
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
    };
    ((Obj *)arg0)->v30();
    fn_8015B820(0, 0, 0x10);
}

#pragma cplusplus reset
void *fn_8013E3D4(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_80291CF8[];
    extern void *lbl_80291DA0[];
    extern void *lbl_802920E0[];

    if (arg0 != NULL) {
        *(void **)((u8 *)arg0 + 4) = lbl_80291CF8;
        if (arg0 != NULL) {
            *(void **)((u8 *)arg0 + 4) = lbl_80291DA0;
            if (arg0 != NULL) {
                *(void **)((u8 *)arg0 + 4) = lbl_802920E0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void *fn_8013E440(void) {
    extern u16 lbl_80276908[];
    return (u8 *)lbl_80276908 + 0x9f;
}

s32 fn_8013E450(void) {
    return 0;
}

s32 fn_8013E458(void) {
    return 0;
}

s32 fn_8013E460(void) {
    return 0x1C;
}

s32 fn_8013E468(void) {
    return 0x1C;
}

s32 fn_8013E470(void) {
    return 0x1C;
}

#pragma cplusplus on
extern "C" void fn_8013E478(void *arg0) {
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
    };
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetAlphaByte(s32);
    void Prim2D_PrepareTex(void);
    extern f32 lbl_8036A6D0;

    ((Obj *)arg0)->v30();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A6D0);
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}
#pragma cplusplus reset
void fn_8013E4BC(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, u8 *, 9) = (u8) (M2C_FIELD(arg0, u8 *, 9) | arg1);
}

u8 fn_8013E4CC(void *arg0, s32 arg1) {
    return (u8) (M2C_FIELD(arg0, u8 *, 9) & arg1);
}

void fn_8013E4DC(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
}

void *fn_8013E4E4(void *arg0, s16 arg1) {
    extern u16 lbl_80291DA0[76];
    extern u16 lbl_802920E0[76];
    
    if (arg0 != NULL) {
        *(u16**)((char*)arg0 + 4) = lbl_80291DA0;
        if (arg0 != NULL) {
            *(u16**)((char*)arg0 + 4) = lbl_802920E0;
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void *fn_8013E540(void *arg0, s16 arg1) {
    extern u16 lbl_802920E0[76];
    if (arg0 != NULL) {
        *(u16**)((char*)arg0 + 4) = lbl_802920E0;
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

s32 fn_8013E588(void) {
    return 0x1C;
}

#pragma cplusplus on
extern "C" void fn_8013E590(void *arg0) {
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
        virtual void v31() = 0;
        virtual void v32() = 0;
        virtual void v33() = 0;
        virtual void v34() = 0;
        virtual void v35() = 0;
        virtual void v36() = 0;
        virtual void v37() = 0;
        virtual void v38() = 0;
    };
    ((Obj *)arg0)->v38();
}
#pragma cplusplus reset
#pragma cplusplus on
extern "C" s16 fn_8013E5BC(void *arg0) {
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
        virtual s16 v16() = 0;
        virtual void v17() = 0;
        virtual s32 v18() = 0;
    };
    s16 t = ((Obj *)arg0)->v18() - ((Obj *)arg0)->v16() * 2;
    return t / 3;
}

extern "C" s16 fn_8013E63C(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x10);
}

extern "C" s16 fn_8013E644(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0xC);
}

extern "C" s32 fn_8013E64C(void) {
    return 0x3B;
}

extern "C" s16 fn_8013E654(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0xE);
}

extern "C" f32 fn_8013E65C(void *arg0) {
    return M2C_FIELD(arg0, f32 *, 0x18);
}

extern "C" s16 fn_8013E664(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0xA);
}

extern "C" s16 fn_8013E66C(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 8);
}

extern "C" s32 fn_8013E674(void) {
    return 0x68;
}
#pragma cplusplus reset

s16 fn_8013E67C(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x20);
}

#pragma cplusplus on
extern "C" s16 fn_8013E684(void *arg0, void *arg1) {
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
        virtual void v31() = 0;
        virtual void v32() = 0;
        virtual void v33() = 0;
        virtual s16 v34() = 0;
    };
    struct Arg1 {
        u8 pad[0x60];
        s8 field_60;
    };
    s16 temp;
    s32 d;
    s32 sum;

    temp = ((Obj *)arg0)->v34();
    d = temp;
    sum = d;
    sum += ((Arg1 *)arg1)->field_60;
    sum -= 1;
    return (s16)(sum / d);
}
#pragma cplusplus reset
s16 fn_8013E6D8(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x16);
}

s16 fn_8013E6E0(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x12);
}

s16 fn_8013E6E8(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x14);
}

s16 fn_8013E6F0(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x1C);
}

#pragma cplusplus on
extern "C" s16 fn_8013E6F8(void *arg0) {
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
        virtual s16 v16() = 0;
        virtual void v17() = 0;
        virtual s32 v18() = 0;
        virtual void v19() = 0;
        virtual void v20() = 0;
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
        virtual void v31() = 0;
        virtual void v32() = 0;
        virtual void v33() = 0;
        virtual s16 v34() = 0;
    };
    s16 t = ((Obj *)arg0)->v18() - ((Obj *)arg0)->v16() * 2;
    return t / ((Obj *)arg0)->v34();
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" s16 fn_8013E780(void *arg0) {
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
        virtual s16 v16() = 0;
        virtual void v17() = 0;
        virtual s32 v18() = 0;
    };
    return (s16)(((Obj *)arg0)->v18() - ((Obj *)arg0)->v16() * 2);
}
#pragma cplusplus reset
s32 fn_8013E7E8(s32 unused, void *arg1) {
    return *(s8 *)((u8 *)arg1 + 0x60);
}

void *fn_8013E7F4(void) {
    extern u16 lbl_80276908[];
    return (u8 *)lbl_80276908 + 0x9f;
}

void *fn_8013E804(void) {
    extern u8 lbl_80276908[];
    return &lbl_80276908[0xAF];
}

void *fn_8013E814(void) {
    extern u8 lbl_80276908[];
    return &lbl_80276908[0xC8];
}

s32 fn_8013E824(void) {
    return 1;
}

s16 fn_8013E82C(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x1E);
}

s16 fn_8013E834(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x1E);
}

void *fn_8013E83C(void *arg0, s16 arg1) {
    extern u16 lbl_80291F60[76];
    extern u16 lbl_802920E0[76];
    
    if (arg0 != NULL) {
        *(u16**)((char*)arg0 + 4) = lbl_80291F60;
        if (arg0 != NULL) {
            *(u16**)((char*)arg0 + 4) = lbl_802920E0;
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void *fn_8013E898(void *arg0, s16 arg1) {
    extern u16 lbl_80291FF8[76];
    extern u16 lbl_802920E0[76];
    
    if (arg0 != NULL) {
        *(u16**)((char*)arg0 + 4) = lbl_80291FF8;
        if (arg0 != NULL) {
            *(u16**)((char*)arg0 + 4) = lbl_802920E0;
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void *fn_8013E8F4(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_80292178[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80292178;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma cplusplus on
extern "C" void fn_8013E960(void *arg0, s32 arg1) {
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
        virtual void v10(s32) = 0;
    };
    ((Obj *)arg0)->v9();
    ((Obj *)arg0)->v10(arg1);
}

#pragma optimization_level 3
extern "C" void fn_8013E9BC(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        u8 pad4[0xE];
        s16 unk12;
        s16 unk14;
        s16 unk16;
        s16 unk18;
        u8 pad1A[0x1A];
        u32 unk34;
        u8 pad38[4];
        s32 unk3C;
        void *unk40;
        s16 unk44;
        s16 unk46;
        s16 unk48;
        s16 unk4A;
        s16 unk4C;
        s16 unk4E;
    };
    void fn_8013F748(void *, s16 *, s16 *);
    void Prim2D_Begin(void);
    void Prim2D_SetCallback(void (*)(void *), s16 *);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_ScissorFromRect(void *);
    s32 Text_MeasureHeight(s32, f32);
    s32 Text_MeasureWidth(void *, s32, f32);
    void *Msg_Expand(void *);
    extern f32 lbl_8036A6F0;
    extern f32 lbl_8036A6F4;
    extern u8 lbl_802769F8[];
    s16 ax;
    Obj *self;
    s16 ay;
    void *text;

    self = (Obj *)arg0;
    self->v3();
    ay = self->unk46;
    ax = self->unk44;
    {
        s32 measured = Text_MeasureHeight(-1, lbl_8036A6F0);
        void *msg = self->unk40;
        ay = (s16)((ay + (0x40 - measured)) >> 1);
        if (msg != NULL) {
            text = Msg_Expand(msg);
        } else {
            text = lbl_802769F8;
        }
    }
    if (text != NULL) {
        s16 tw;
        s32 w;
        s16 h;
        s16 *rect;
        s32 color;
        tw = (s16)Text_MeasureWidth(text, -1, lbl_8036A6F0);
        w = (s16)(self->unk16 - self->unk12);
        h = (s16)(self->unk18 - self->unk14);
        rect = &self->unk48;
        self->unk48 = 0;
        self->unk4A = 0;
        self->unk4C = w;
        self->unk4E = h;
        ax = (s16)(ax + (((s16)w - tw) >> 1));
        fn_8013F748(self, rect, rect);
        rect = &self->unk4C;
        fn_8013F748(self, rect, rect);
        Prim2D_Begin();
        Prim2D_SetCallback(Prim2D_ScissorFromRect, &self->unk48);
        Prim2D_AddZ(lbl_8036A6F4);
        Prim2D_SetTex(0, (u16)(self->unk34 | 3));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(6);
        Prim2D_SetPos((f32)ax, (f32)ay);
        color = self->unk3C;
        Prim2D_SetColorPacked(&color);
        Prim2D_SetText(text);
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_ClearCallbacks();
        Prim2D_PrepareTex();
    }
}
#pragma optimization_level reset

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_8013EB6C(void *arg0) {
    void fn_801528E4(s32, s32, s32);
    ((Menu42 *)arg0)->v2();
    fn_801528E4(0, 0, 0x10);
}
#pragma cplusplus reset
void fn_8013EBA8(void *arg0) {
    s16 h = M2C_FIELD(arg0, s16 *, 0x10) - M2C_FIELD(arg0, s16 *, 0xc);
    s16 w = M2C_FIELD(arg0, s16 *, 0xe) - M2C_FIELD(arg0, s16 *, 0xa);

    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    M2C_FIELD(arg0, s16 *, 0x16) = w;
    M2C_FIELD(arg0, s16 *, 0x18) = h;
}

#pragma cplusplus on
extern "C" void fn_8013EBD8(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_PrepareTex(void);
    void fn_8015385C(s8, s32, s32, s16, s16, s32, s32, s32);

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
        virtual s16 v9() = 0;
    };
    struct Obj2 {
        virtual void w0() = 0;
        virtual void w1() = 0;
        virtual void w2() = 0;
        virtual void w3() = 0;
        virtual void w4() = 0;
        virtual void w5() = 0;
        virtual void w6() = 0;
        virtual void w7() = 0;
        virtual void w8() = 0;
        virtual void w9(s32) = 0;
    };

    Obj *self = (Obj *)arg0;
    s16 vret;
    s16 a, b, c;
    s16 dx, dy;
    f32 ratio;
    s32 mulA, mulB;

    if (*(s16 *)((u8 *)arg0 + 0x3C) > *(s16 *)((u8 *)arg0 + 0x3E)) {
        self->v3();
        Prim2D_Begin();
        Prim2D_SetTex(0, (u16)(*(u32 *)((u8 *)self + 0x34) | 0x10));
        Prim2D_PrepareTex();

        vret = self->v9();
        a = *(s16 *)((u8 *)self + 0x3C);
        c = *(s16 *)((u8 *)self + 0x40);
        b = *(s16 *)((u8 *)self + 0x3E);
        ratio = (f32)vret / (f32)a;
        dx = (s16)(*(s16 *)((u8 *)self + 0x16) - *(s16 *)((u8 *)self + 0x12));
        dy = (s16)(*(s16 *)((u8 *)self + 0x18) - *(s16 *)((u8 *)self + 0x14));
        mulA = (s32)(ratio * (f32)c);
        mulB = (s32)(ratio * (f32)b);

        fn_8015385C(
            (s8)*(s32 *)((u8 *)self + 0x48),
            0,
            0,
            dx,
            dy,
            mulA,
            mulB,
            *(u32 *)((u8 *)self + 0x34) | 0x10
        );

        *(u8 *)((u8 *)self + 0x58) = (u8)(*(s16 *)((u8 *)self + 0x40) > 0);
        {
            s32 d = *(s16 *)((u8 *)self + 0x3C) - *(s16 *)((u8 *)self + 0x3E);
            *(u8 *)((u8 *)self + 0x80) = (u8)(*(s16 *)((u8 *)self + 0x40) < d);
        }

        ((Obj2 *)((u8 *)self + 0x4C))->w9(*(u32 *)((u8 *)self + 0x34));
        ((Obj2 *)((u8 *)self + 0x74))->w9(*(u32 *)((u8 *)self + 0x34));
    }
}
#pragma cplusplus reset
void fn_8013ED84(void *arg0, s16 arg1) {
    s16 temp_r5;

    if ((s16) M2C_FIELD(arg0, s16 *, 0x3C) > 0) {
        temp_r5 = M2C_FIELD(arg0, s16 *, 0x40);
        if (temp_r5 != arg1) {
            if (arg1 < temp_r5) {
                M2C_FIELD(arg0, s16 *, 0x62) = 1;
                M2C_FIELD(arg0, s8 *, 0x59) = 0;
            } else {
                M2C_FIELD(arg0, s16 *, 0x8A) = 1;
                M2C_FIELD(arg0, s8 *, 0x81) = 0;
            }
            M2C_FIELD(arg0, s16 *, 0x40) = arg1;
        }
    }
}

#pragma cplusplus on
extern "C" void *fn_8013EDD4(void *self, s16 doFree) {
    extern u8 lbl_802921B0[];
    extern u8 lbl_80291914[];
    extern u8 lbl_802918E0[];
    extern u8 lbl_80292230[];
    extern u8 lbl_8028FDB0[];
    extern u8 gEmptyVtbl[];
    void Heap_Free(void *);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    struct Owner {
        void *vtbl;
        u8 pad4[0x48];
        void *sub4c;
        u8 pad50[0x24];
        void *sub74;
    };
    Owner *owner;

    owner = (Owner *)self;
    if (self != NULL) {
        owner->vtbl = lbl_802921B0;
        if (self != NULL) {
            owner->vtbl = lbl_80291914;
            if (&owner->sub74 != NULL) {
                owner->sub74 = lbl_802918E0;
                if (&owner->sub74 != NULL) {
                    owner->sub74 = gEmptyVtbl;
                    ((Obj *)&owner->sub74)->v2();
                }
            }
            if (&owner->sub4c != NULL) {
                owner->sub4c = lbl_802918E0;
                if (&owner->sub4c != NULL) {
                    owner->sub4c = gEmptyVtbl;
                    ((Obj *)&owner->sub4c)->v2();
                }
            }
            if (self != NULL) {
                owner->vtbl = lbl_80292230;
                if (self != NULL) {
                    owner->vtbl = lbl_8028FDB0;
                }
            }
        }
        if (doFree > 0) {
            Heap_Free(self);
        }
    }
    return self;
}
#pragma cplusplus reset
s16 fn_8013EED8(void *arg0) {
    return (s16) (M2C_FIELD(arg0, s16 *, 0xE) - M2C_FIELD(arg0, s16 *, 0xA));
}

s16 fn_8013EEEC(void *arg0) {
    return (s16) (M2C_FIELD(arg0, s16 *, 0x18) - M2C_FIELD(arg0, s16 *, 0x14));
}

#pragma cplusplus on
extern "C" void fn_8013EF00(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
    };
    void Prim2D_Begin(void);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_EndPrim(void);
    extern f32 lbl_8036A708;
    s32 sp8;
    struct { s16 w, h; } size;

    ((Obj *)arg0)->v3();
    Prim2D_Begin();
    Prim2D_SetTex(0, (u16)(*(u32 *)((u8 *)arg0 + 0x34) | 2));
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    size.w = (s16)(*(s16 *)((u8 *)arg0 + 0x16) - *(s16 *)((u8 *)arg0 + 0x12));
    size.h = (s16)(*(s16 *)((u8 *)arg0 + 0x18) - *(s16 *)((u8 *)arg0 + 0x14));
    Prim2D_SetRect(lbl_8036A708, lbl_8036A708, (f32)size.w, (f32)size.h);
    sp8 = *(s32 *)((u8 *)arg0 + 0x1E);
    Prim2D_SetColorPacked(&sp8);
    Prim2D_EndPrim();
}
#pragma cplusplus reset

void *fn_8013EFCC(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_802921E0[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_802921E0;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma cplusplus on
extern "C" void *fn_8013F038(void *arg0, s16 arg1, u8 arg2) {
    struct Item { virtual ~Item(); virtual void *find(s16, u8); u8 pad[4]; s16 id; };
    struct Node { Node *next; void *pad; Item *item; };
    struct Iter {
        Node *node;
        Iter(Node *n) : node(n) {}
        Iter(const Iter &other) : node(other.node) {}
        ~Iter() {}
    };
    Node *cursor = (Node *)((char *)arg0 + 0x40);
    Iter begin(cursor);
    Iter first(begin);
    Iter current(first);
    Iter it(current);
    Iter end(*(Node **)((char *)arg0 + 0x44));
    Iter last(end);
    Iter finish(last);
    Iter stop(finish);
    Item *res = 0;
    while (cursor != stop.node) {
        Item *item = cursor->next->item;
        if (arg1 == item->id) { res = item; break; }
        if (arg2) {
            res = (Item *)item->find(arg1, arg2);
            if (res) break;
        }
        cursor = cursor->next;
    }
    return res;
}
#pragma cplusplus reset

#pragma cplusplus on
#pragma cplusplus on
extern "C" void fn_8013F0F0(void *arg0, void *arg1) {
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
    void List_Erase(void *, void *, void *);
    void *found;
    u32 ret;
    u8 *node;
    u8 *sentinel;

    if (arg1 != NULL) {
        sentinel = (u8 *)arg0 + 0x40;
        node = *(u8 **)(sentinel + 4);
        while (node != sentinel && *(void **)(node + 8) != arg1) {
            node = *(u8 **)(node + 4);
        }
        if (node != sentinel) {
            *(s32 *)((u8 *)arg1 + 0x38) = 0;
            found = node;
            List_Erase(&ret, (u8 *)arg0 + 0x3C, &found);
            if (arg1 != NULL) {
                if (--((Obj *)arg1)->refcount == 0) {
                    if (arg1 != NULL) {
                        ((Obj *)arg1)->destroy(1);
                    }
                }
            }
        }
    }
}

extern "C" void fn_8013F1A0(void *arg0, void *arg1) {
    void List_Insert(void *, void *, void *, void *);
    Vec2s sp1c;
    void *sp18;
    void *sp14;
    Vec2s sp10;
    Vec2s spC;
    void *sp8;
    void *node;
    void *sentinel;
    void *parent;
    void *child;

    sp8 = arg1;
    if (arg1 != 0) {
        sentinel = (u8 *)arg0 + 0x40;
        node = *(void **)((u8 *)sentinel + 4);
        goto check;
        for (;;) {
            node = *(void **)((u8 *)node + 4);
        check:
            if (node != sentinel) {
                if (*(void **)((u8 *)node + 8) != arg1) {
                    continue;
                }
            }
            if (node != sentinel) {
                return;
            }
            *(void **)((u8 *)arg1 + 0x38) = arg0;
            sp18 = sentinel;
            List_Insert(&sp14, (u8 *)arg0 + 0x3c, &sp18, &sp8);
            if (sp8 != 0) {
                *(u32 *)((u8 *)sp8 + 4) = *(u32 *)((u8 *)sp8 + 4) + 1;
            }
            child = sp8;
            parent = *(void **)((u8 *)child + 0x38);
            if (parent != 0) {
                sp10 = *(Vec2s *)((u8 *)parent + 0xa);
                sp10.x = (s16)(sp10.x + *(s16 *)((u8 *)parent + 0x1a));
                sp10.y = (s16)(sp10.y + *(s16 *)((u8 *)parent + 0x1c));
                spC = sp10;
                spC.x = (s16)(spC.x - *(s16 *)((u8 *)child + 0xa));
                spC.y = (s16)(spC.y - *(s16 *)((u8 *)child + 0xc));
                sp1c = spC;
                *(s16 *)((u8 *)child + 0x1a) = sp1c.x;
                *(s16 *)((u8 *)child + 0x1c) = sp1c.y;
            }
            break;
        }
    }
}

extern "C" void *fn_8013F2A4(void *self, s16 doFree) {
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
    typedef struct {
        u32 unk0;
        ListNode node;
    } DtorList;
    typedef struct Owner {
        void *vtbl;
        u8 pad[0x38];
        DtorList list;
    } Owner;
    void List_Erase(void *, void *, void *);
    void List_EraseRange(void *, void *, void *, void *);
    void Heap_Free(void *);
    extern u8 lbl_80292208[];
    extern u8 lbl_80292230[];
    extern u8 lbl_8028FDB0[];

    void *found;
    u8 ret[4];
    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    Owner *owner;
    Obj *obj;

    owner = (Owner *)self;
    if (self != NULL) {
        owner->vtbl = lbl_80292208;
        while (owner->list.unk0 != 0) {
            obj = (Obj *)owner->list.node.prev->val;
            if (obj != NULL) {
                if (--obj->refcount == 0 && obj != NULL) {
                    obj->destroy(1);
                }
            }
            found = owner->list.node.prev;
            List_Erase(ret, &owner->list, &found);
        }
        if (&owner->list != NULL) {
            if (&owner->list != NULL) {
                if (&owner->list != NULL) {
                    end = &owner->list.node;
                    sp10 = end;
                    spC = end->next;
                    List_EraseRange(sp8, &owner->list, &spC, &sp10);
                }
            }
        }
        if (self != NULL) {
            owner->vtbl = lbl_80292230;
            if (self != NULL) {
                owner->vtbl = lbl_8028FDB0;
            }
        }
        if (doFree > 0) {
            Heap_Free(self);
        }
    }
    return self;
}

#pragma cplusplus off

void fn_8013F3C0(void) {

}

void fn_8013F3C4(void) {

}

void fn_8013F3C8(void) {

}

void fn_8013F3CC(void) {

}

void fn_80059C2C(s32, s32, s32, s32, s32);
#pragma push
#pragma optimization_level 2
#pragma global_optimizer off
void fn_8013F3D0(void *arg0) {
    void fn_8013F748(void *, void *, void *);
    f32 fn_8013FA44(void *);
    s32 fn_80138908(void *);
    s32 fn_8013FA10(void *);
    void fn_80009C20(f32, f32, f32, f32, f32, f32, f32, f32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetAlphaByte(s32);
    void Prim2D_PrepareTex(void);
    extern f32 lbl_8036A718;

    struct Point { s16 x, y; } pt;
    s32 midY;
    s32 midX;
    s32 z;
    f32 scale;

    pt.x = 0;
    pt.y = 0;
    fn_8013F748(arg0, &pt, &pt);

    midX = (s16)(((s16)(M2C_FIELD(arg0, s16 *, 0xE) - M2C_FIELD(arg0, s16 *, 0xA)) >> 1) - M2C_FIELD(arg0, s16 *, 0x12));
    midY = (s16)(((s16)(M2C_FIELD(arg0, s16 *, 0x10) - M2C_FIELD(arg0, s16 *, 0xC)) >> 1) - M2C_FIELD(arg0, s16 *, 0x14));

    Prim2D_Begin();
    z = M2C_FIELD(arg0, s16 *, 0x22);
    scale = fn_8013FA44(arg0);
    fn_80009C20((f32)pt.x, (f32)pt.y, (f32)(s16)z, (f32)midX, (f32)midY, fn_8013FA44(arg0), scale, lbl_8036A718);
    Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 2));
    Prim2D_SetColorByte(fn_80138908(arg0));
    Prim2D_SetAlphaByte(fn_8013FA10(arg0));
    Prim2D_PrepareTex();
}
#pragma pop
void fn_8013F54C(void *arg0) {
    void fn_8013F748(void *, void *, void *);
    f32 fn_8013FA44(void *);
    s32 fn_80138908(void *);
    s32 fn_8013FA10(void *);
    void fn_80009C20(f32, f32, f32, f32, f32, f32, f32, f32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetAlphaByte(s32);
    extern const f32 lbl_8036A718;
    struct Point { s16 x, y; } pt;
    s32 z;
    s16 height, width;
    f32 scale;

    *(u32 *)&pt = M2C_FIELD(arg0, u32 *, 0xA);
    if (M2C_FIELD(arg0, void **, 0x38))
        fn_8013F748(M2C_FIELD(arg0, void **, 0x38), &pt, &pt);
    Prim2D_Begin();
    height = (s16)(M2C_FIELD(arg0, s16 *, 0x10) - M2C_FIELD(arg0, s16 *, 0xC));
    width = (s16)(M2C_FIELD(arg0, s16 *, 0xE) - M2C_FIELD(arg0, s16 *, 0xA));
    z = M2C_FIELD(arg0, s16 *, 0x22);
    scale = fn_8013FA44(arg0);
    fn_80009C20((f32)pt.x, (f32)pt.y, (f32)(s16)z, (f32)(width >> 1), (f32)(height >> 1), fn_8013FA44(arg0), scale, lbl_8036A718);
    Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 2));
    Prim2D_SetColorByte(fn_80138908(arg0));
    Prim2D_SetAlphaByte(fn_8013FA10(arg0));
    Prim2D_PrepareTex();
}

void *fn_8013F6B8(void *arg0, void *arg1, void *arg2) {
    void fn_8013F748(void *, void *, void *);
    struct Point {
        s16 x;
        s16 y;
    };
    struct Point pt;
    struct Point temp2;
    struct Point temp;

    pt.x = 0;
    pt.y = 0;
    fn_8013F748(arg0, &pt, &pt);
    temp = *(struct Point *)arg2;
    temp.x -= pt.x;
    temp.y -= pt.y;
    temp2 = temp;
    *(s16 *)((char *)arg1 + 0) = temp2.x;
    *(s16 *)((char *)arg1 + 2) = temp2.y;
    return arg1;
}

s32 *fn_8013FBC8(s32 *, s32 *);
s32 fn_8013FBD4(s32);
s16 *fn_8013FBDC(s16 *, s16 *);
void fn_8013FC00(s16 *, s16 *);
void fn_8013FC14(s16 *, s16 *);
void fn_8013FC28(s32 *, s32 *, s16 *);
s32 fn_8013FBC0(s32);
s32 fn_80138AB8(void *);

Vec2s *fn_8013FC64(Vec2s *);
#pragma global_optimizer off
Vec2s *fn_8013F748(void *arg0, Vec2s *arg1, Vec2s *arg2) {
    Vec2s sp3C;
    Vec2s sp38;
    Vec2s sp34;
    Vec2s sp30;
    Vec2s sp2C;
    Vec2s sp28;
    Vec2s sp24;
    Vec2s sp20;
    Vec2s sp1C;
    Vec2s sp18;
    Vec2s sp14;
    Vec2s sp10;
    Vec2s spC;
    Vec2s sp8;
    u32 ggf;
    u32 parent;
    u32 gp;

    parent = *(u32 *)((u8 *)arg0 + 0x38);
    sp3C = *(Vec2s *)((u8 *)arg0 + 0xA);
    if (parent != 0) {
        sp24 = *fn_8013FC64((Vec2s *)((u8 *)parent + 0xA));
        gp = *(u32 *)((u8 *)parent + 0x38);
        if (gp != 0) {
            sp18 = *(Vec2s *)fn_8013FBD4((s32)gp);
            if (*(u32 *)((u8 *)gp + 0x38) != 0) {
                ggf = (u32)fn_80138AB8((void *)gp);
                fn_8013FBC8((s32 *)&spC, (s32 *)fn_8013FBD4((s32)ggf));
                if ((u32)fn_80138AB8((void *)ggf) != 0) {
                    fn_8013F748((void *)fn_80138AB8((void *)ggf), &spC, &spC);
                }
                fn_8013FC28((s32 *)&sp14, (s32 *)&spC, (s16 *)fn_8013FBC0((s32)ggf));
                fn_8013FC28((s32 *)&sp10, (s32 *)&sp14, (s16 *)&sp18);
                fn_8013FC14((s16 *)&sp18, (s16 *)&sp10);
            }
            fn_8013FC28((s32 *)&sp20, (s32 *)&sp18, (s16 *)fn_8013FBC0((s32)gp));
            fn_8013FC28((s32 *)&sp1C, (s32 *)&sp20, (s16 *)&sp24);
            fn_8013FC00((s16 *)&sp24, (s16 *)&sp1C);
        }
        fn_8013FC28((s32 *)&sp2C, (s32 *)&sp24, (s16 *)fn_8013FBC0((s32)parent));
        {
            s32 *src = (s32 *)&sp2C;
            s32 *fb = (s32 *)fn_8013FBC8((s32 *)&sp8, src);
            fn_8013FBC8((s32 *)&sp28, (s32 *)fn_8013FBDC((s16 *)fb, (s16 *)&sp3C));
        }
        sp3C.x = sp28.x;
        sp3C.y = sp28.y;
    }
    sp30 = sp3C;
    sp30.x = (s16)(sp30.x + *(s16 *)((u8 *)arg0 + 0x12));
    sp30.y = (s16)(sp30.y + *(s16 *)((u8 *)arg0 + 0x14));
    sp34 = sp30;
    sp34.x = (s16)(sp34.x + arg2->x);
    sp34.y = (s16)(sp34.y + arg2->y);
    sp38 = sp34;
    arg1->x = sp38.x;
    arg1->y = sp38.y;
    return arg1;
}
#pragma global_optimizer on
void Prim2D_ScissorFromRect(void *unused, void *rectSrc) {
    void GXSetScissor(u32, u32, u32, u32);
    struct {
        s16 x;
        s16 y;
        s16 x2;
        s16 y2;
    } r;
    s16 v;
    s16 clamped;

    /* Clamp a pixel rect to [0, 0x7FF] and set GX scissor to its width/height. */
    ((u32 *)&r)[0] = ((u32 *)rectSrc)[0];
    ((u32 *)&r)[1] = ((u32 *)rectSrc)[1];

    v = r.x;
    if (v < 0) {
        clamped = 0;
    } else {
        clamped = 0x7FF;
        if (v <= 0x7FF) {
            clamped = v;
        }
    }
    r.x = clamped;

    v = r.y;
    if (v < 0) {
        clamped = 0;
    } else {
        clamped = 0x7FF;
        if (v <= 0x7FF) {
            clamped = v;
        }
    }
    r.y = clamped;

    v = r.x2;
    if (v < 0) {
        clamped = 0;
    } else {
        clamped = 0x7FF;
        if (v <= 0x7FF) {
            clamped = v;
        }
    }
    r.x2 = clamped;

    v = r.y2;
    if (v < 0) {
        clamped = 0;
    } else {
        clamped = 0x7FF;
        if (v <= 0x7FF) {
            clamped = v;
        }
    }
    r.y2 = clamped;

    GXSetScissor(r.x, r.y, (s16)(r.x2 - r.x), (s16)(r.y2 - r.y));
}

s32 fn_8013FA10(void) {
    f32 fn_80138AC0();
    extern f32 lbl_8036A728;
    return (s32) (lbl_8036A728 * fn_80138AC0());
}

f32 fn_8013FA44(void *arg0) {
#pragma cplusplus on
 struct Node { u8 pad[0x28]; f32 scale; u8 pad2c[12]; Node *parent; Node *getParent() { return parent; } };
 Node *node = (Node *)arg0;
 f32 scale = node->scale;
 if (node->getParent() != NULL) scale *= fn_8013FA44(node->getParent());
 return scale;
#pragma cplusplus reset
}

s32 fn_8013FBC0(s32 arg0) {
    return arg0 + 0x12;
}

s32 *fn_8013FBC8(s32 *arg0, s32 *arg1) {
    *arg0 = *arg1;
    return arg0;
}

s32 fn_8013FBD4(s32 arg0) {
    return arg0 + 0xA;
}

#pragma global_optimizer off
s16 *fn_8013FBDC(s16 *dst, s16 *src) {
s16 c,b,a,d;
a=dst[0]; b=src[0]; c=src[1];
d=a;
d+=b;
dst[0]=d;
d=dst[1]; c=d+c; dst[1]=c;
return dst;
}
#pragma global_optimizer reset
void fn_8013FC00(s16 *dst, s16 *src)
{
  s16 a;
  s16 b;
  int new_var;
  b = src[0];
  a = b;
  b = src[1];
  dst[0] = a;
  new_var = 1;
  dst[new_var] = b;
}

#pragma scheduling off
void fn_8013FC14(s16 *dst, s16 *src)
{
  s16 a;
  s16 b;
  int new_var;
  b = src[0];
  a = b;
  b = src[1];
  dst[0] = a;
  new_var = 1;
  dst[new_var] = b;
}

#pragma scheduling on
void fn_8013FC28(s32 *dst, s32 *src, s16 *off)
{
  s16 local[2];
  s32 a;
  s32 b;
  s16 x;
  s16 y;
  s32 packed = *src;
  *((s32 *) local) = packed;
  a = off[0];
  b = off[1];
  x = local[0];
  y = local[1];
  x = x + a;
  local[1] = (y = y + b);
  local[0] = x;
  *dst = *((s32 *) local);
}
#pragma scheduling on
Vec2s *fn_8013FC64(Vec2s *p) {
    return p;
}

void List_Erase(ListIter *ret, List *list, ListIter *it) {
    ListNode *node = it->node;
    ListNode *next = node->next;
    ListNode *prev = node->prev;
    s32 size;

    it->node = next;
    prev->next = next;
    node->next->prev = node->prev;
    Heap_Free(node);
    size = list->size;
    next = it->node;
    list->size = --size;
    ret->node = next;
}

#pragma cplusplus on
extern "C" void List_Insert(void *outNode, void *list, void *posRef, void *value) {
    void *Heap_Alloc(s32);
    void Heap_Free(void *);
    void fprintf(void *, void *, ...);
    void abort(void);
    extern char __files[];
    extern char List_allocFailMsg[];
    struct Node {
        Node *prev;
        Node *next;
        s32 value;
    };
    struct Holder {
        void *list;
        Node *node;
        Holder(void *l, Node *n) : list(l), node(n) {}
        ~Holder() {
            if (node != 0) {
                Heap_Free(node);
            }
        }
    };
    Node *node;
    Node *pos;
    Node *n;
    void *listPtr;

    // Allocate a node, copy *value into it, and splice it into the list before *posRef.
    listPtr = (s32 *)list + 1;
    node = (Node *)Heap_Alloc(0xC);
    if (node == 0) {
        fprintf(__files + 0xA0, List_allocFailMsg, __files);
        abort();
    }
    {
        Holder h(listPtr, node);
        if (&h.node->value != 0) {
            h.node->value = *(s32 *)value;
        }
        pos = *(Node **)posRef;
        n = h.node;
        h.node = 0;
        pos->prev->next = n;
        n->prev = pos->prev;
        pos->prev = n;
        n->next = pos;
        (*(s32 *)list)++;
        *(void **)outNode = n;
    }
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void Ui_UpdatePanelWidgets(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7(void *) = 0;
    };
    struct Panel {
        u8 pad[0x34];
        void *flag;
        u8 *inner;
    };
    Panel *p = (Panel *)arg0;
    void *flag = p->flag;
    if ((flag ? *(Obj **)(p->inner + 8) : (Obj *)0) != 0) {
        (flag ? *(Obj **)(p->inner + 8) : (Obj *)0)->v7(arg0);
    }
}

#pragma cplusplus on
extern "C" void fn_8013FE0C(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4(void *) = 0;
        virtual void v5(void *) = 0;
    };
    extern u8 lbl_80367AD8;
    void Prim2D_Begin(void);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetAlphaByte(s32);
    void Prim2D_PrepareTex(void);
    ListNode *node;
    ListNode *sent;

    if ((s8)lbl_80367AD8 <= 0 && *(s8 *)((u8 *)arg0 + 0x30) <= 0) {
        node = *(ListNode **)((u8 *)arg0 + 0x3C);
        sent = (ListNode *)((u8 *)arg0 + 0x38);
        while (node != sent) {
            ((Obj *)node->val)->v4(arg0);
            ((Obj *)node->val)->v5(arg0);
            node = node->next;
        }
    }
    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_SetColorByte(0xFF);
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}
#pragma cplusplus reset

#pragma cplusplus reset
void Ui_DecBusy(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x30) = (u8) (M2C_FIELD(arg0, u8 *, 0x30) - 1);
}

void fn_8013FED0(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x30) = (u8) (M2C_FIELD(arg0, u8 *, 0x30) + 1);
}

void fn_8013FEE0(void) {
    extern u8 lbl_80367AD8;
    lbl_80367AD8 -= 1;
}

void fn_8013FEF0(void) {
    gEventLockDepth += 1;
}

void Ui_BringChildToFront(void *arg0, void *arg1) {
void List_Erase(void *,void *,void *);
void List_Insert(void *,void *,void *,void *);
u8 *self;
void *found;
u32 temp14;
void *end;
u32 tempC;
void *key;
u8 *sentinel;
u8 *node;
self=(u8 *)arg0;
key=arg1;
if(arg1!=0) {
sentinel=self+0x38;
node=*(u8 **)(sentinel+4);
goto check;
for(;;) {
node=*(u8 **)(node+4);
check:
if(node!=sentinel) {
if(*(void **)(node+8)!=arg1) continue;
}
break;
}
if(node!=sentinel) {
found=node;
List_Erase(&temp14,self+0x34,&found);
end=sentinel;
List_Insert(&tempC,self+0x34,&end,&key);
}
}}

#pragma cplusplus on
extern "C" void *Ui_FindChild(void *arg0, s16 arg1, u8 arg2) {
    struct Item { virtual ~Item(); virtual void *find(s16, u8); u8 pad[4]; s16 id; };
    struct Node { Node *next; void *pad; Item *item; };
    struct Iter {
        Node *node;
        Iter(Node *n) : node(n) {}
        Iter(const Iter &other) : node(other.node) {}
        ~Iter() {}
    };
    Node *cursor = (Node *)((char *)arg0 + 0x38);
    Iter begin(cursor);
    Iter first(begin);
    Iter current(first);
    Iter it(current);
    Iter end(*(Node **)((char *)arg0 + 0x3C));
    Iter last(end);
    Iter finish(last);
    Iter stop(finish);
    Item *res = 0;
    while (cursor != stop.node) {
        Item *item = cursor->next->item;
        if (arg1 == item->id) { res = item; break; }
        if (arg2) {
            res = (Item *)item->find(arg1, arg2);
            if (res) break;
        }
        cursor = cursor->next;
    }
    return res;
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void Ui_RemoveChild(void *arg0, void *arg1) {
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
    void List_Erase(void *, void *, void *);
    void *found;
    u32 ret;
    u8 *node;
    u8 *sentinel;

    if (arg1 != NULL) {
        sentinel = (u8 *)arg0 + 0x38;
        node = *(u8 **)(sentinel + 4);
        while (node != sentinel && *(void **)(node + 8) != arg1) {
            node = *(u8 **)(node + 4);
        }
        if (node != sentinel) {
            found = node;
            List_Erase(&ret, (u8 *)arg0 + 0x34, &found);
            if (arg1 != NULL) {
                if (--((Obj *)arg1)->refcount == 0) {
                    if (arg1 != NULL) {
                        ((Obj *)arg1)->destroy(1);
                    }
                }
            }
        }
    }
}
#pragma cplusplus reset
void Ui_AddChild(void *arg0, void *arg1) {
    void List_Insert(void *, void *, void *, void *);
    void *sp10;
    void *spC;
    void *sp8;
    void *node;
    void *sentinel;

    sp8 = arg1;
    if (arg1 != 0) {
        sentinel = (u8 *)arg0 + 0x38;
        node = *(void **)((u8 *)sentinel + 4);
        goto check;
        for (;;) {
            node = *(void **)((u8 *)node + 4);
        check:
            if (node != sentinel) {
                if (*(void **)((u8 *)node + 8) != arg1) {
                    continue;
                }
            }
            if (node != sentinel) {
                return;
            }
            sp10 = sentinel;
            List_Insert(&spC, (u8 *)arg0 + 0x34, &sp10, &sp8);
            if (sp8 != 0) {
                *(u32 *)((u8 *)sp8 + 4) = *(u32 *)((u8 *)sp8 + 4) + 1;
            }
            break;
        }
    }
}

#pragma global_optimizer off
void fn_8014017C(s32 arg0, void *arg1, void *arg2, s32 arg3) {
    struct Vec { s32 x, y, z; };
    void fn_80140830(s32, void *, void *, void *, void *, s32);
    extern u8 lbl_802922E4[];
    extern u8 lbl_802922D8[];
    struct Vec v[4];
    v[0] = *(struct Vec *)&lbl_802922E4[0];
    v[1] = *(struct Vec *)&lbl_802922E4[0];
    v[2] = *(struct Vec *)&lbl_802922D8[0];
    v[3] = *(struct Vec *)&lbl_802922D8[0];
    fn_80140830(arg0, arg1, arg2, &v[3], &v[1], arg3);
}
#pragma global_optimizer on
void Ui_CloseChildAnim(void *arg0, void *arg1, void *arg2) {
    M2C_UNK fn_80140E58(void *, void *, void *, M2C_UNK);
    fn_80140E58(arg0, arg1, arg2, 1);
}

void Ui_OpenChildAnim(void *arg0, void *arg1, void *arg2) {
    M2C_UNK fn_80140E58(void *, void *, void *, M2C_UNK);
    fn_80140E58(arg0, arg1, arg2, 0);
}

void Ui_SlideWidgetChild(void *arg0, void *arg1, void *arg2, void *arg3) {
    M2C_UNK fn_801414F8(void *, void *, void *, void *, M2C_UNK);
    fn_801414F8(arg0, arg1, arg2, arg3, 2);
}

void Ui_SlideWidgetChildMode1(void *arg0, void *arg1, void *arg2, void *arg3) {
    M2C_UNK fn_801414F8(void *, void *, void *, void *, M2C_UNK);
    fn_801414F8(arg0, arg1, arg2, arg3, 1);
}

void fn_801402A0(void *arg0, void *arg1, void *arg2, void *arg3) {
    M2C_UNK fn_801414F8(void *, void *, void *, void *, M2C_UNK);
    fn_801414F8(arg0, arg1, arg2, arg3, 0);
}

void fn_801402C4(void) {
    M2C_UNK fn_80141B00();
    fn_80141B00();
}

void fn_801402E4(void) {
    M2C_UNK fn_80141D94();
    fn_80141D94();
}

#pragma cplusplus on
extern "C" void *Ui_DtorPanelBase(void *self, s16 doFree) {
    /* Release refcounted children on the panel dtor list, clear the list, optionally free. */
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
    typedef struct {
        u32 unk0;
        ListNode node;
    } DtorList;
    typedef struct Owner {
        u8 pad[0x34];
        DtorList list;
    } Owner;
    void List_Erase(void *, void *, void *);
    void List_EraseRange(void *, void *, void *, void *);
    void Heap_Free(void *);

    void *found;
    u8 ret[4];
    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    Owner *owner;
    Obj *obj;

    owner = (Owner *)self;
    if (self != NULL) {
        while (owner->list.unk0 != 0) {
            obj = (Obj *)owner->list.node.prev->val;
            if (obj != NULL) {
                if (--obj->refcount == 0 && obj != NULL) {
                    obj->destroy(1);
                }
            }
            found = owner->list.node.prev;
            List_Erase(ret, &owner->list, &found);
        }
        if (&owner->list != NULL) {
            if (&owner->list != NULL) {
                if (&owner->list != NULL) {
                    end = &owner->list.node;
                    sp10 = end;
                    spC = end->next;
                    List_EraseRange(sp8, &owner->list, &spC, &sp10);
                }
            }
        }
        if (doFree > 0) {
            Heap_Free(self);
        }
    }
    return self;
}
#pragma cplusplus reset

void *fn_801403F0(void *arg0) {
    *(u8 *)((uintptr_t)arg0 + 0x30) = 0;
    fn_80142060((char *)arg0 + 0x34);
    return arg0;
}

#pragma cplusplus on
extern "C" void fn_8014042C(void *arg0) {
extern f32 lbl_8036A730, lbl_8036A740;
f32 Math_Ease(s32, s16, f32, f32, f32, f32);
void Ui_ClearPanelChildrenMid(void *);
#pragma cplusplus on
struct Point {
s16 x,y;
Point operator-(const Point &p) const { struct Point q=*this; q.x-=p.x; q.y-=p.y; return q; }
Point &operator*=(f32 t) { x=x*t; y=y*t; return *this; }
Point &operator+=(const Point &p) { x+=p.x; y+=p.y; return *this; }
};
struct Target { u8 pad[0x24]; s16 duration; };
struct Link { void *prev,*next; Target *value; };
struct State { u8 pad[0x28]; s16 time; u8 pad2a[10]; u32 count; Link *first; u8 pad3c[4]; Point start,end; void (Target::*callback)(Point *); Target *get() { return count ? first->value : 0; } };
State *self=(State*)arg0;
Point *end=&self->end;
(self->get()->*(self->callback))(end);
{
s32 timeInt=self->time+1;
s32 durationInt=self->get()->duration+1;
f32 duration=durationInt;
f32 time=timeInt;
f32 t=Math_Ease(5,self->time,lbl_8036A740,lbl_8036A730,(lbl_8036A730/duration)*(duration-time),lbl_8036A730);
Point p=self->end-self->start;
p*=t;
p+=self->start;
(self->get()->*(self->callback))(&p);
}
Ui_ClearPanelChildrenMid(self);
#pragma cplusplus reset
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void Ui_ClearPanelChildrenMid(void *self) {
    /* Release refcounted children on the panel dtor list and clear the list. */
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
    typedef struct {
        u32 size;
        ListNode node;
    } DtorList;
    typedef struct Owner {
        u8 pad[0x34];
        DtorList list;
    } Owner;
    void List_Erase(void *, void *, void *);
    void List_EraseRange(void *, void *, void *, void *);

    void *found;
    u8 ret[4];
    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    Owner *owner;
    Obj *obj;

    owner = (Owner *)self;
    if (self != NULL) {
        if (self != NULL) {
            while (owner->list.size != 0) {
                obj = (Obj *)owner->list.node.prev->val;
                if (obj != NULL) {
                    if (--obj->refcount == 0 && obj != NULL) {
                        obj->destroy(1);
                    }
                }
                found = owner->list.node.prev;
                List_Erase(ret, &owner->list, &found);
            }
            if (&owner->list != NULL) {
                if (&owner->list != NULL) {
                    if (&owner->list != NULL) {
                        end = &owner->list.node;
                        sp10 = end;
                        spC = end->next;
                        List_EraseRange(sp8, &owner->list, &spC, &sp10);
                    }
                }
            }
        }
    }
}
#pragma cplusplus reset

void fn_801406B0(void *arg0) {
f32 Math_Ease(s32,f32,f32,f32,f32);
#pragma cplusplus on
struct Point {
s16 x,y;
Point operator-(const Point &p) const { struct Point q=*this; q.x-=p.x; q.y-=p.y; return q; }
Point &operator*=(f32 t) { x=x*t; y=y*t; return *this; }
Point &operator+=(const Point &p) { x+=p.x; y+=p.y; return *this; }
};
struct Target { u8 pad[0x24]; s16 duration; };
struct Link { void *prev,*next; Target *value; };
struct State { u8 pad[0x28]; s16 time; u8 pad2a[10]; u32 count; Link *first; u8 pad3c[4]; Point start,end; void (Target::*callback)(Point *); Target *get() { return count ? first->value : 0; } };
State *self=(State*)arg0;
f32 duration = self->get()->duration + 1;
f32 time = self->time + 1;
f32 t=Math_Ease(5, 0.0f, 1.0f, (1.0f/duration)*(duration-time), 1.0f);
Point p=self->end-self->start;
p*=t;
p+=self->start;
(self->get()->*(self->callback))(&p);
#pragma cplusplus reset
}

void *fn_80140830(void *arg0, void *arg1, Vec2s *arg2, void *arg3, void (*arg4)(Vec2s *, void *), u8 arg5) {
void *Process_CreateChild(void *,void *); void *Process_Create(void *,void *);
void *fn_80140B04(void *); void fn_80142060(void *);
void List_Insert(void *,void *,void *,void *);
void fn_8022C518(void *,void *);
f32 Math_Ease(s32,f32,f32,f32,f32);
extern u8 lbl_802922B8[]; extern u32 lbl_80282AC0[];
extern f32 lbl_8036A730, lbl_8036A740;
typedef struct { u32 a,b,c; } Triple;
Vec2s start;
void *value;
Vec2s pos;
void *iter, *result;
Vec2s delta;
u8 *obj; void *end; ListNode *node; void *child;
f32 duration, scale;
if(arg5) obj=Process_CreateChild(lbl_802922B8,arg0);
else obj=Process_Create(lbl_802922B8,arg0);
if(obj) {
obj[0x30]=0; fn_80142060(obj+0x34);
*(Triple *)(obj+0x48)=*(Triple *)lbl_80282AC0;
}
value=arg1;
if(arg1) {
end=fn_80140B04(obj+0x34);
node=((ListNode *)fn_80140B04(obj+0x34))->next;
while(node!=end && node->val!=value) node=node->next;
if(node==(void *)(obj+0x38)) {
iter=obj+0x38; List_Insert(&result,obj+0x34,&iter,&value);
if(value) ++*(u32 *)((u8 *)value+4);
}
}
*(s16 *)(obj+0x28)=*(s16 *)((u8 *)arg1+0x24);
arg4(&start,arg1);
{ s16 x=arg2->x, y=arg2->y;
*(s16 *)(obj+0x40)=start.x;
*(s16 *)(obj+0x42)=start.y;
*(s16 *)(obj+0x44)=x;
*(s16 *)(obj+0x46)=y; }
*(Triple *)(obj+0x48)=*(Triple *)arg3;
if(*(u32 *)(obj+0x34)) child=(*(ListNode **)(obj+0x38))->val; else child=0;
duration=(f32)(*(s16 *)((u8 *)child+0x24)+1);
scale=Math_Ease(5,lbl_8036A740,lbl_8036A730,(lbl_8036A730/duration)*(duration-(f32)(*(s16 *)(obj+0x28)+1)),lbl_8036A730);
delta=*(Vec2s *)(obj+0x44);
delta.x-=*(s16 *)(obj+0x40); delta.y-=*(s16 *)(obj+0x42);
pos=delta; pos.x=(s16)(pos.x*scale); pos.y=(s16)(pos.y*scale);
pos.x+=*(s16 *)(obj+0x40); pos.y+=*(s16 *)(obj+0x42);
if(*(u32 *)(obj+0x34)) child=(*(ListNode **)(obj+0x38))->val; else child=0;
fn_8022C518(child,&pos);
return obj;
}

s32 fn_80140B04(s32 arg0) {
    return arg0 + 4;
}

void fn_80140B0C(void *self) {
    void *fn_80140B04(void *);
    void List_Erase(void *, void *, void *);
    void Ui_ClearPanelChildren(void *);
    extern f32 lbl_8036A730;
    void *child;
    void *end;
    u8 *parent;
    void *node;
    void *found;
    u32 ret;
    u32 flag;
    f32 var_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 inv;
    s32 mode;
#pragma cplusplus on
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
#pragma cplusplus reset

    flag = *(u32 *)((u8 *)self + 0x34);
    parent = *(u8 **)((u8 *)self + 0x18);

    if (flag != 0) {
        child = *(void **)(*(u8 **)((u8 *)self + 0x38) + 8);
    } else {
        child = NULL;
    }

    temp_f4 = (f32)(*(s16 *)((u8 *)child + 0x24) + 1);
    temp_f3 = (f32)(*(s16 *)((u8 *)self + 0x28) + 1);
    mode = *(s32 *)((u8 *)self + 0x40);
    switch (mode) {
    case 0:
        var_f2 = (lbl_8036A730 / temp_f4) * (temp_f4 - temp_f3);
        break;
    case 1:
        inv = lbl_8036A730 / temp_f4;
        var_f2 = inv * temp_f3;
        break;
    }

    if (flag != 0) {
        child = *(void **)(*(u8 **)((u8 *)self + 0x38) + 8);
    } else {
        child = NULL;
    }
    *(f32 *)((u8 *)child + 0x2C) = var_f2;

    if (*(s32 *)((u8 *)self + 0x40) == 1) {
        if (*(u32 *)((u8 *)self + 0x34) != 0) {
            child = *(void **)(*(u8 **)((u8 *)self + 0x38) + 8);
        } else {
            child = NULL;
        }
        if (child != NULL) {
            end = fn_80140B04(parent + 0x34);
            node = ((void **)fn_80140B04(parent + 0x34))[1];
            goto check;
            for (;;) {
                node = ((void **)node)[1];
            check:
                if (node != end) {
                    if (((void **)node)[2] != child) {
                        continue;
                    }
                }
                break;
            }
            if (node != parent + 0x38) {
                found = node;
                List_Erase(&ret, parent + 0x34, &found);
                if (child != NULL) {
                    if (--*(s32 *)((u8 *)child + 4) == 0) {
                        if (child != NULL) {
#pragma cplusplus on
                            ((Obj *)child)->destroy(1);
#pragma cplusplus reset
                        }
                    }
                }
            }
        }
    }
    Ui_ClearPanelChildren(self);
}

#pragma cplusplus on
extern "C" void Ui_ClearPanelChildren(void *self) {
    /* Release refcounted children on the panel dtor list and clear the list. */
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
    typedef struct {
        u32 size;
        ListNode node;
    } DtorList;
    typedef struct Owner {
        u8 pad[0x34];
        DtorList list;
    } Owner;
    void List_Erase(void *, void *, void *);
    void List_EraseRange(void *, void *, void *, void *);

    void *found;
    u8 ret[4];
    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    Owner *owner;
    Obj *obj;

    owner = (Owner *)self;
    if (self != NULL) {
        if (self != NULL) {
            while (owner->list.size != 0) {
                obj = (Obj *)owner->list.node.prev->val;
                if (obj != NULL) {
                    if (--obj->refcount == 0 && obj != NULL) {
                        obj->destroy(1);
                    }
                }
                found = owner->list.node.prev;
                List_Erase(ret, &owner->list, &found);
            }
            if (&owner->list != NULL) {
                if (&owner->list != NULL) {
                    if (&owner->list != NULL) {
                        end = &owner->list.node;
                        sp10 = end;
                        spC = end->next;
                        List_EraseRange(sp8, &owner->list, &spC, &sp10);
                    }
                }
            }
        }
    }
}
#pragma cplusplus reset

void fn_80140D98(void *arg0) {
extern f32 lbl_8036A730;
extern f64 lbl_8036A738;
f32 var_f2;
f32 temp_f3;
f32 temp_f4;
f32 inv;
s32 temp_r0;
u32 temp_r7;
void *var_r3;
void *var_r4;
(void)lbl_8036A738;
temp_r7=*(u32*)((u8*)arg0+0x34);
if(temp_r7!=0U) var_r4=*(void**)(*(u8**)((u8*)arg0+0x38)+8); else var_r4=NULL;
temp_f4=(f32)(*(s16*)((u8*)var_r4+0x24)+1);
temp_f3=(f32)(*(s16*)((u8*)arg0+0x28)+1);
temp_r0=*(s32*)((u8*)arg0+0x40);
switch(temp_r0) {
case 0: var_f2=(lbl_8036A730/temp_f4)*(temp_f4-temp_f3); break;
case 1: inv=lbl_8036A730/temp_f4; var_f2=inv*temp_f3; break;
default: break;
}
if(temp_r7!=0U) var_r3=*(void**)(*(u8**)((u8*)arg0+0x38)+8); else var_r3=NULL;
*(f32*)((u8*)var_r3+0x2C)=var_f2;
}

void *fn_80140E58(void *arg0, void *arg1, u8 arg2, s32 arg3)
{
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, void *);
    void *List_Insert(void *, void *, void *, void *);
    void *fn_80140B04(void *);
    void fn_80142060(void *);

    extern u8 lbl_80292298[];
    extern f32 lbl_8036A730;
    extern f64 lbl_8036A738;

    u8 *obj;
    u8 *node;
    void *end;
    void *child;
    void *sp8;
    u32 key;
    void *searchKey;
    void *pos;
    u32 ret;
    f32 var_f31;
    f32 temp_f3;
    f32 temp_f4;
    f32 inv;
    s32 temp_r0;
    u32 temp_r7;
    void *var_r3;
    void *var_r4;

    (void)lbl_8036A738;

    if (arg2) obj = Process_CreateChild(lbl_80292298, arg0);
    else obj = Process_Create(lbl_80292298, arg0);
    if (obj != NULL) {
        obj[0x30] = 0;
        fn_80142060(obj + 0x34);
    }
    key = (u32)arg1;
    if (arg1 != NULL) {
        end = fn_80140B04(obj + 0x34);
        node = (u8 *)fn_80140B04(obj + 0x34);
        node = *(u8 **)(node + 4);
        searchKey = (void *)key;
        goto check;
        for (;;) {
            node = *(u8 **)(node + 4);
        check:
            if (node != (u8 *)end) {
                if (*(void **)(node + 8) != searchKey) continue;
            }
            break;
        }
        if (node == obj + 0x38) {
            pos = obj + 0x38;
            List_Insert(&ret, obj + 0x34, &pos, &key);
            if (key != 0) {
                *(s32 *)((u8 *)key + 4) += 1;
            }
        }
    }
    *(s16 *)(obj + 0x28) = *(s16 *)((u8 *)arg1 + 0x24);
    *(s32 *)(obj + 0x40) = arg3;

    temp_r7 = *(u32 *)(obj + 0x34);
    if (temp_r7 != 0U) var_r4 = *(void **)(*(u8 **)(obj + 0x38) + 8); else var_r4 = NULL;
    temp_f4 = (f32)(*(s16 *)((u8 *)var_r4 + 0x24) + 1);
    temp_f3 = (f32)(*(s16 *)(obj + 0x28) + 1);
    temp_r0 = *(s32 *)(obj + 0x40);
    switch (temp_r0) {
    case 0: var_f31 = (lbl_8036A730 / temp_f4) * (temp_f4 - temp_f3); break;
    case 1: inv = lbl_8036A730 / temp_f4; var_f31 = inv * temp_f3; break;
    default: break;
    }
    if (temp_r7 != 0U) var_r3 = *(void **)(*(u8 **)(obj + 0x38) + 8); else var_r3 = NULL;
    *(f32 *)((u8 *)var_r3 + 0x2C) = var_f31;
    return obj;
}

void fn_80141040(void *self) {
    void fn_8014127C(void *);
    void *fn_80140B04(void *);
    void List_Erase(void *, void *, void *);
    void Ui_ClearPanelChildrenB(void *);
    void *child;
    void *end;
    u8 *parent;
    void *node;
    void *found;
    u32 ret;
    s16 tmp;
#pragma cplusplus on
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
#pragma cplusplus reset

    parent = *(u8 **)((u8 *)self + 0x18);

    if (*(u32 *)((u8 *)self + 0x34) != 0) {
        child = *(void **)(*(u8 **)((u8 *)self + 0x38) + 8);
    } else {
        child = NULL;
    }

    tmp = *(s16 *)((u8 *)self + 0x44);
    *(s16 *)((u8 *)child + 0xE) = (s16)(tmp + (s16)(*(s16 *)((u8 *)child + 0xE) - *(s16 *)((u8 *)child + 0xA)));
    *(s16 *)((u8 *)child + 0xA) = tmp;
    tmp = *(s16 *)((u8 *)self + 0x46);
    *(s16 *)((u8 *)child + 0x10) = (s16)(tmp + (s16)(*(s16 *)((u8 *)child + 0x10) - *(s16 *)((u8 *)child + 0xC)));
    *(s16 *)((u8 *)child + 0xC) = tmp;

    fn_8014127C(self);

    if (*(s32 *)((u8 *)self + 0x48) == 2) {
        if (*(u32 *)((u8 *)self + 0x34) != 0) {
            child = *(void **)(*(u8 **)((u8 *)self + 0x38) + 8);
        } else {
            child = NULL;
        }
        if (child != NULL) {
            end = fn_80140B04(parent + 0x34);
            node = ((void **)fn_80140B04(parent + 0x34))[1];
            goto check;
            for (;;) {
                node = ((void **)node)[1];
            check:
                if (node != end) {
                    if (((void **)node)[2] != child) {
                        continue;
                    }
                }
                break;
            }
            if (node != parent + 0x38) {
                found = node;
                List_Erase(&ret, parent + 0x34, &found);
                if (child != NULL) {
                    if (--*(s32 *)((u8 *)child + 4) == 0) {
                        if (child != NULL) {
#pragma cplusplus on
                            ((Obj *)child)->destroy(1);
#pragma cplusplus reset
                        }
                    }
                }
            }
        }
    }
    Ui_ClearPanelChildrenB(self);
}

#pragma cplusplus on
extern "C" void Ui_ClearPanelChildrenB(void *self) {
    /* Release refcounted children on the panel dtor list and clear the list. */
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
    typedef struct {
        u32 size;
        ListNode node;
    } DtorList;
    typedef struct Owner {
        u8 pad[0x34];
        DtorList list;
    } Owner;
    void List_Erase(void *, void *, void *);
    void List_EraseRange(void *, void *, void *, void *);

    void *found;
    u8 ret[4];
    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    Owner *owner;
    Obj *obj;

    owner = (Owner *)self;
    if (self != NULL) {
        if (self != NULL) {
            while (owner->list.size != 0) {
                obj = (Obj *)owner->list.node.prev->val;
                if (obj != NULL) {
                    if (--obj->refcount == 0 && obj != NULL) {
                        obj->destroy(1);
                    }
                }
                found = owner->list.node.prev;
                List_Erase(ret, &owner->list, &found);
            }
            if (&owner->list != NULL) {
                if (&owner->list != NULL) {
                    if (&owner->list != NULL) {
                        end = &owner->list.node;
                        sp10 = end;
                        spC = end->next;
                        List_EraseRange(sp8, &owner->list, &spC, &sp10);
                    }
                }
            }
        }
    }
}
#pragma cplusplus reset

void fn_8014127C(void *arg0) {
extern f32 lbl_8036A730,lbl_8036A740;
f32 Math_Ease(s32,f32,f32,f32,f32);
#pragma cplusplus on
struct Point { s16 x,y;
Point operator-(const Point &p) const { struct Point q=*this; q.y-=p.y; q.x-=p.x; return q; }
Point &operator*=(f32 t) { x=x*t; y=y*t; return *this; }
Point &operator+=(const Point &p) { x+=p.x; y+=p.y; return *this; }
};
struct Target { u8 pad[10]; s16 x,y,right,bottom; u8 pad12[18]; s16 duration; u8 pad26[6]; f32 alpha;
void move(Point *p) { s16 width=right-x; s16 height; right=p->x+width; x=p->x; height=bottom-y; bottom=p->y+height; y=p->y; }
};
struct Link { void *prev,*next; Target *value; };
struct State { u8 pad[0x28]; s16 time; u8 pad2a[10]; u32 count; Link *first; u8 pad3c[4]; Point start,end; s32 mode;
f32 opacity() { s32 d=get()->duration+1; s32 t=time+1; f32 duration=d, elapsed=t; f32 a; switch(mode) {case 0:a=lbl_8036A730;break;case 1:a=(lbl_8036A730/duration)*(duration-elapsed);break;case 2: { f32 inverse=lbl_8036A730/duration; a=inverse*elapsed; break; }} return a; }
Target *get() { return count?first->value:0; }};
State *self=(State *)arg0;
s32 durationInt=self->get()->duration+1;
s32 timeInt=self->time+1;
f32 duration=durationInt;
f32 time=timeInt;
f32 inverse=lbl_8036A730/duration;
f32 progress=inverse*(duration-time);
f32 alpha=self->opacity();
f32 t=Math_Ease(5,lbl_8036A740,lbl_8036A730,progress,lbl_8036A730);
Point p=self->end-self->start;
p*=t; p+=self->start;
self->get()->move(&p);
self->get()->alpha=alpha;
#pragma cplusplus reset
}

#pragma optimization_level 3
void *fn_801414F8(void *arg0, void *arg1, s16 *arg2, u8 arg3, s32 arg4) {
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, void *);
    void List_Insert(void *, void *, void *, void *);
    void *fn_80140B04(void *);
    void fn_80142060(void *);
    void fn_8014127C(void *);
    extern u8 lbl_80292278[];
    typedef struct {
        u8 pad[0x34];
        u8 list;
    } Panel;
    void *sp10;
    void *spC;
    void *sp8;
    void *end;
    void *node;
    void *key;
    Panel *obj;
    s16 a[1];
    s16 b[1];
    s16 c[1];

    if (arg3 != 0) {
        obj = (Panel *)Process_CreateChild(lbl_80292278, arg0);
    } else {
        obj = (Panel *)Process_Create(lbl_80292278, arg0);
    }
    if (obj != NULL) {
        ((u8 *)obj)[0x30] = 0;
        fn_80142060(&obj->list);
    }
    sp10 = arg1;
    if (arg1 != NULL) {
        end = fn_80140B04(&obj->list);
        node = fn_80140B04(&obj->list);
        node = *(void **)((u8 *)node + 4);
        key = sp10;
        goto check;
        for (;;) {
            node = *(void **)((u8 *)node + 4);
        check:
            if (node != end) {
                if (*(void **)((u8 *)node + 8) != key) {
                    continue;
                }
            }
            break;
        }
        if (node == (u8 *)obj + 0x38) {
            spC = (u8 *)obj + 0x38;
            List_Insert(&sp8, &obj->list, &spC, &sp10);
            if (sp10 != NULL) {
                *(s32 *)((u8 *)sp10 + 4) = *(s32 *)((u8 *)sp10 + 4) + 1;
            }
        }
    }
    a[0] = *(s16 *)((u8 *)arg1 + 0x24);
    b[0] = arg2[0];
    *(s16 *)((u8 *)obj + 0x28) = a[0];
    a[0] = arg2[1];
    c[0] = *(s16 *)((u8 *)arg1 + 0xA);
    *(s16 *)((u8 *)obj + 0x40) = c[0];
    c[0] = *(s16 *)((u8 *)arg1 + 0xC);
    *(s16 *)((u8 *)obj + 0x42) = c[0];
    *(s16 *)((u8 *)obj + 0x44) = b[0];
    *(s16 *)((u8 *)obj + 0x46) = a[0];
    *(s32 *)((u8 *)obj + 0x48) = arg4;
    fn_8014127C(obj);
    return obj;
}
#pragma optimization_level reset
void fn_80141630(void *self, s32 arg1) {
void *fn_80140B04(void *);
void List_Erase(void *,void *,void *);
void Ui_ClearPanelChildrenEx(void *);
f32 Math_Ease(s32,f32,f32,f32,f32);
extern f32 lbl_8036A740;
void *child,*end;
u8 *parent;
void *node,*found;
u32 ret;
f32 alpha[1],t;
s32 time,duration;
#pragma cplusplus on
struct Obj { virtual void destroy(s32)=0; s32 refcount; };
#pragma cplusplus reset
alpha[0]=1.0f;
parent=*(u8 **)((u8 *)self+0x18);
time=*(s16 *)((u8 *)self+0x28)+1;
switch(*(s32 *)((u8 *)self+0x40)) {
case 0:
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
duration=*(s16 *)((u8 *)child+0x24)+1;
alpha[0]=(1.0f/(f32)duration)*(f32)(duration-time);
break;
case 1:
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
duration=*(s16 *)((u8 *)child+0x24)+1;
{ f32 inverse=1.0f/(f32)duration; alpha[0]=inverse*(f32)time; }
break;
}
t=Math_Ease(5,lbl_8036A740,1.0f,alpha[0],1.0f);
alpha[0]=*((u8 *)self+0x44)?alpha[0]:1.0f;
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
*(f32 *)((u8 *)child+0x2c)=alpha[0];
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
*(f32 *)((u8 *)child+0x28)=t;
if(*(s32 *)((u8 *)self+0x40)==1) {
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
if(child) {
end=fn_80140B04(parent+0x34);
node=((void **)fn_80140B04(parent+0x34))[1];
goto check;
for(;;) {
node=((void **)node)[1];
check:
if(node!=end) { if(((void **)node)[2]!=child) continue; }
break;
}
if(node!=parent+0x38) {
found=node; List_Erase(&ret,parent+0x34,&found);
if(child) {
if(--*(s32 *)((u8 *)child+4)==0) {
if(child) {
#pragma cplusplus on
((Obj *)child)->destroy(1);
#pragma cplusplus reset
}
}
}
}
}
}
Ui_ClearPanelChildrenEx(self);
}

#pragma cplusplus on
extern "C" void Ui_ClearPanelChildrenEx(void *self) {
    /* Release refcounted children on the panel dtor list and clear the list. */
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
    typedef struct {
        u32 size;
        ListNode node;
    } DtorList;
    typedef struct Owner {
        u8 pad[0x34];
        DtorList list;
    } Owner;
    void List_Erase(void *, void *, void *);
    void List_EraseRange(void *, void *, void *, void *);

    void *found;
    u8 ret[4];
    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    Owner *owner;
    Obj *obj;

    owner = (Owner *)self;
    if (self != NULL) {
        if (self != NULL) {
            while (owner->list.size != 0) {
                obj = (Obj *)owner->list.node.prev->val;
                if (obj != NULL) {
                    if (--obj->refcount == 0 && obj != NULL) {
                        obj->destroy(1);
                    }
                }
                found = owner->list.node.prev;
                List_Erase(ret, &owner->list, &found);
            }
            if (&owner->list != NULL) {
                if (&owner->list != NULL) {
                    if (&owner->list != NULL) {
                        end = &owner->list.node;
                        sp10 = end;
                        spC = end->next;
                        List_EraseRange(sp8, &owner->list, &spC, &sp10);
                    }
                }
            }
        }
    }
}
#pragma cplusplus reset

#pragma push
#pragma optimization_level 4
void fn_80141970(void *self, s32 arg1) {
f32 Math_Ease(s32,f32,f32,f32,f32);
extern f32 lbl_8036A740;
void *child;
f32 alpha[1],t;
s32 time,duration;
alpha[0]=1.0f;
time=*(s16 *)((u8 *)self+0x28)+1;
switch(*(s32 *)((u8 *)self+0x40)) {
case 0:
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
duration=*(s16 *)((u8 *)child+0x24)+1;
alpha[0]=(1.0f/(f32)duration)*(f32)(duration-time);
break;
case 1:
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
duration=*(s16 *)((u8 *)child+0x24)+1;
{ f32 inverse=1.0f/(f32)duration; alpha[0]=inverse*(f32)time; }
break;
}
t=Math_Ease(5,lbl_8036A740,1.0f,alpha[0],1.0f);
alpha[0]=*((u8 *)self+0x44)?alpha[0]:1.0f;
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
*(f32 *)((u8 *)child+0x2c)=alpha[0];
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
*(f32 *)((u8 *)child+0x28)=t;
}
#pragma pop
#pragma opt_common_subs off
void *fn_80141B00(void *arg0, void *arg1, u8 arg2, u8 arg3) {
void *Process_CreateChild(void *, void *);
void *Process_Create(void *, void *);
void fn_80142060(void *);
void *fn_80140B04(void *);
void List_Insert(void *, void *, void *, void *);
f32 Math_Ease(s32,f32,f32,f32,f32);
extern u8 lbl_80292258[];
extern f32 lbl_8036A740;
void *result,*self,*child,*end,*node;
u32 key;
void *searchKey;
void *pos;
u32 ret;
f32 alpha[1],t;
s32 time,duration;
if(arg2) result=Process_CreateChild(&lbl_80292258,arg0);
else result=Process_Create(&lbl_80292258,arg0);
self=result;
if(result!=0) {
*(u8 *)((u8 *)self+0x30)=0;
fn_80142060((u8 *)self+0x34);
}
key=(u32)arg1;
if(arg1!=0) {
end=fn_80140B04((u8 *)self+0x34);
node=fn_80140B04((u8 *)self+0x34);
node=*(void **)((u8 *)node+4);
searchKey=(void *)key;
goto check;
for(;;) {
node=*(void **)((u8 *)node+4);
check:
if(node!=end) {
if(*(void **)((u8 *)node+8)!=searchKey) continue;
}
break;
}
if(node==(u8 *)self+0x38) {
pos=(u8 *)self+0x38;
List_Insert(&ret,(u8 *)self+0x34,&pos,&key);
if(key!=0) {
*(s32 *)((u8 *)key+4)+=1;
}
}
}
alpha[0]=1.0f;
*(s16 *)((u8 *)self+0x28)=*(s16 *)((u8 *)arg1+0x24);
*(s32 *)((u8 *)self+0x40)=1;
*(u8 *)((u8 *)self+0x44)=arg3;
time=*(s16 *)((u8 *)self+0x28)+1;
switch(*(s32 *)((u8 *)self+0x40)) {
case 0:
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
duration=*(s16 *)((u8 *)child+0x24)+1;
alpha[0]=(1.0f/(f32)duration)*(f32)(duration-time);
break;
case 1:
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
duration=*(s16 *)((u8 *)child+0x24)+1;
{ f32 inverse=1.0f/(f32)duration; alpha[0]=inverse*(f32)time; }
break;
}
t=Math_Ease(5,lbl_8036A740,1.0f,alpha[0],1.0f);
alpha[0]=*((u8 *)self+0x44)?alpha[0]:1.0f;
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
*(f32 *)((u8 *)child+0x2c)=alpha[0];
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
*(f32 *)((u8 *)child+0x28)=t;
return self;
}
#pragma opt_common_subs off
void *fn_80141D94(void *arg0, void *arg1, u8 arg2, u8 arg3) {
void *Process_CreateChild(void *, void *);
void *Process_Create(void *, void *);
void fn_80142060(void *);
void *fn_80140B04(void *);
void List_Insert(void *, void *, void *, void *);
f32 Math_Ease(s32,f32,f32,f32,f32);
extern u8 lbl_80292258[];
extern f32 lbl_8036A740;
void *result,*self,*child,*end,*node;
u32 key;
void *searchKey;
void *pos;
u32 ret;
f32 alpha[1],t;
s32 time,duration;
if(arg2) result=Process_CreateChild(&lbl_80292258,arg0);
else result=Process_Create(&lbl_80292258,arg0);
self=result;
if(result!=0) {
*(u8 *)((u8 *)self+0x30)=0;
fn_80142060((u8 *)self+0x34);
}
key=(u32)arg1;
if(arg1!=0) {
end=fn_80140B04((u8 *)self+0x34);
node=fn_80140B04((u8 *)self+0x34);
node=*(void **)((u8 *)node+4);
searchKey=(void *)key;
goto check;
for(;;) {
node=*(void **)((u8 *)node+4);
check:
if(node!=end) {
if(*(void **)((u8 *)node+8)!=searchKey) continue;
}
break;
}
if(node==(u8 *)self+0x38) {
pos=(u8 *)self+0x38;
List_Insert(&ret,(u8 *)self+0x34,&pos,&key);
if(key!=0) {
*(s32 *)((u8 *)key+4)+=1;
}
}
}
alpha[0]=1.0f;
*(s16 *)((u8 *)self+0x28)=*(s16 *)((u8 *)arg1+0x24);
*(s32 *)((u8 *)self+0x40)=0;
*(u8 *)((u8 *)self+0x44)=arg3;
time=*(s16 *)((u8 *)self+0x28)+1;
switch(*(s32 *)((u8 *)self+0x40)) {
case 0:
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
duration=*(s16 *)((u8 *)child+0x24)+1;
alpha[0]=(1.0f/(f32)duration)*(f32)(duration-time);
break;
case 1:
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
duration=*(s16 *)((u8 *)child+0x24)+1;
{ f32 inverse=1.0f/(f32)duration; alpha[0]=inverse*(f32)time; }
break;
}
t=Math_Ease(5,lbl_8036A740,1.0f,alpha[0],1.0f);
alpha[0]=*((u8 *)self+0x44)?alpha[0]:1.0f;
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
*(f32 *)((u8 *)child+0x2c)=alpha[0];
if(*(u32 *)((u8 *)self+0x34)) child=*(void **)(*(u8 **)((u8 *)self+0x38)+8); else child=0;
*(f32 *)((u8 *)child+0x28)=t;
return self;
}
#pragma opt_common_subs on
#pragma scheduling off
void fn_80142018(Vec2s *out, s16 *arg0)
{
  s16 top;
  s16 bottom;
  s16 left;
  s16 right;
  bottom = arg0[5];
  left = bottom;
  top = left;
  bottom = arg0[7];
  left = arg0[6];
  bottom = bottom;
  bottom = bottom - top;
  right = arg0[8];
  out->x = bottom;
  out->y = right - left;
}
#pragma global_optimizer off
void fn_8014203C(void *arg0, Vec2s *size) {
  s16 h, w, xa, d;
  xa = *(s16 *)((u8 *)arg0 + 0xA);
  w = size->x;
  h = size->y;
  d = xa;
  d += w;
  *(s16 *)((u8 *)arg0 + 0xE) = d;
  d = *(s16 *)((u8 *)arg0 + 0xC);
  h = d + h;
  *(s16 *)((u8 *)arg0 + 0x10) = h;
}
#pragma global_optimizer reset
#pragma scheduling on
int fn_80142060(void *arg0) {
    u32 *ptr;

    ptr = (u32 *)((u8 *)arg0 + 0x4);
    *(u32 *)arg0 = 0;
    ptr[1] = (u32)ptr;
    ptr[0] = (u32)ptr;
}

void fn_80142078(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern f32 lbl_8036A75C;
    extern f64 lbl_8036A750;
    register s16 temp_r31;
    register void *var_r30;
    register s32 var_r29;
    s16 temp_r28;
    f32 temp_f1;
    s16 temp_r4_2;
    s32 temp_r0;
    u32 temp_r4;
    void *var_r3;
    void *var_r4;
    register void *var_r6;

    (void)lbl_8036A750;

    temp_r4 = *(u32 *)((u8 *)arg0 + 0x34);
    if (temp_r4 != 0U) {
        var_r30 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8);
    } else {
        var_r30 = NULL;
    }
    if (temp_r4 != 0U) {
        var_r3 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8);
    } else {
        var_r3 = NULL;
    }
    temp_r0 = *(s32 *)((u8 *)arg0 + 0x48);
    var_r6 = NULL;
    temp_r31 = *(s16 *)((u8 *)var_r3 + 0x24);
    var_r29 = (s32)var_r6;
    switch (temp_r0) {
    case 0:
        if (temp_r4 != 0U) {
            var_r6 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8);
        }
        var_r6 = (void *)(s16)(*(s16 *)((u8 *)var_r6 + 0x16) - *(s16 *)((u8 *)var_r6 + 0x12));
        break;
    case 1:
        if (temp_r4 != 0U) {
            var_r6 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8);
        }
        var_r6 = (void *)-(s16)(*(s16 *)((u8 *)var_r6 + 0x16) - *(s16 *)((u8 *)var_r6 + 0x12));
        break;
    case 2:
        if (temp_r4 != 0U) {
            var_r4 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8);
        } else {
            var_r4 = var_r6;
        }
        var_r29 = (s16)(*(s16 *)((u8 *)var_r4 + 0x18) - *(s16 *)((u8 *)var_r4 + 0x14));
        break;
    case 3:
        if (temp_r4 != 0U) {
            var_r4 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8);
        } else {
            var_r4 = var_r6;
        }
        var_r29 = -(s16)(*(s16 *)((u8 *)var_r4 + 0x18) - *(s16 *)((u8 *)var_r4 + 0x14));
        break;
    }
    temp_r4_2 = *(s16 *)((u8 *)arg0 + 0x40);
    if (temp_r4_2 >= (s16)temp_r31) {
        Process_ClearFunc(arg0);
        return;
    }
    *(s16 *)((u8 *)arg0 + 0x40) = (s16)(temp_r4_2 + 1);
    temp_r28 = (s16)Math_Ease(5, (f32)(s16)(s32)var_r6, lbl_8036A75C, (f32)*(s16 *)((u8 *)arg0 + 0x40), (f32)temp_r31);
    temp_f1 = Math_Ease(5, (f32)var_r29, lbl_8036A75C, (f32)*(s16 *)((u8 *)arg0 + 0x40), (f32)temp_r31);
    *(s16 *)((u8 *)var_r30 + 0x8C) = temp_r28;
    *(s16 *)((u8 *)var_r30 + 0x8E) = (s16)temp_f1;
}

#pragma push
#pragma cplusplus on
#pragma optimization_level 4
#pragma opt_common_subs off
extern "C" void fn_801422C0(void *arg0)
{
    extern u8 gUnitInfoPopup[];

    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoPopup(void *, void *, f32, f32);
    void Ui_HideUnitInfoPopup(void *);

    u8 *self;
    u8 *child;
    u8 *selected;
    u8 *entry;
    u8 *node;
    s32 index;
    s32 count;
    s32 offset;
    s32 idx2;
    
    s16 x;
    s16 y;
    void *unit;

    self = (u8 *)arg0;

    *(s16 *)(self + 0x40) = 0;

    if (*(void **)(self + 0x34) != 0) {
        child = *(u8 **)(*(u8 **)(self + 0x38) + 8);
    } else {
        child = 0;
    }

    ((MenuPopupHost *)child)->setSelection(*(void **)(self + 0x44));

    if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
        if (*(void **)(self + 0x34) != 0) {
            child = *(u8 **)(*(u8 **)(self + 0x38) + 8);
        } else {
            child = 0;
        }

        index = ((MenuPopupHost *)child)->getPage();

        offset = index * 12;
        idx2 = index * 2 + 0x64;
        entry = child + 0x90 + offset;

        if (*(void **)entry == 0) {
            selected = 0;
        } else {
            count = *(s16 *)(child + idx2);
            node = *(u8 **)(entry + 8);
            selected = MenuPopup_AdvanceNode(count, node);
        }

        if (selected != 0) {
            if (*(void **)(self + 0x34) != 0) {
                child = *(u8 **)(*(u8 **)(self + 0x38) + 8);
            } else {
                child = 0;
            }

            MenuPopupPosition pos = ((MenuPopupHost *)child)->getPosition();
            x = pos.x;
            y = pos.y;
            Ui_ShowUnitInfoPopup(
                gUnitInfoPopup,
                *(void **)selected,
                (f32)x,
                (f32)y
            );
        } else {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
        }
    }
}
#pragma pop
#pragma cplusplus reset
void fn_8014246C(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    extern f32 lbl_8036A75C;
    extern f64 lbl_8036A750;
    register s16 temp_r31;
    register void *var_r30;
    register s32 var_r29;
    s16 temp_r28;
    f32 temp_f1;
    s16 temp_r4_2;
    s32 temp_r0;
    u32 temp_r4;
    void *var_r3;
    void *var_r4;
    void *var_r6;

    (void)lbl_8036A750;

    temp_r4 = *(u32 *)((u8 *)arg0 + 0x34);
    if (temp_r4 != 0U) {
        var_r30 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8);
    } else {
        var_r30 = NULL;
    }
    if (temp_r4 != 0U) {
        var_r3 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8);
    } else {
        var_r3 = NULL;
    }
    temp_r0 = *(s32 *)((u8 *)arg0 + 0x48);
    var_r6 = NULL;
    var_r29 = (s32)var_r6;
    temp_r31 = *(s16 *)((u8 *)var_r3 + 0x24);
    switch (temp_r0) {
    case 0:
        if (temp_r4 != 0U) {
            var_r6 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8);
        }
        var_r6 = (void *)-(s16)(*(s16 *)((u8 *)var_r6 + 0x16) - *(s16 *)((u8 *)var_r6 + 0x12));
        break;
    case 1:
        if (temp_r4 != 0U) {
            var_r6 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8);
        }
        var_r6 = (void *)(s16)(*(s16 *)((u8 *)var_r6 + 0x16) - *(s16 *)((u8 *)var_r6 + 0x12));
        break;
    case 2:
        if (temp_r4 != 0U) {
            var_r4 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8);
        } else {
            var_r4 = var_r6;
        }
        var_r29 = -(s16)(*(s16 *)((u8 *)var_r4 + 0x18) - *(s16 *)((u8 *)var_r4 + 0x14));
        break;
    case 3:
        if (temp_r4 != 0U) {
            var_r4 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8);
        } else {
            var_r4 = var_r6;
        }
        var_r29 = (s16)(*(s16 *)((u8 *)var_r4 + 0x18) - *(s16 *)((u8 *)var_r4 + 0x14));
        break;
    }
    temp_r4_2 = *(s16 *)((u8 *)arg0 + 0x40);
    if (temp_r4_2 >= (s16)temp_r31) {
        Process_ClearFunc(arg0);
        return;
    }
    *(s16 *)((u8 *)arg0 + 0x40) = (s16)(temp_r4_2 + 1);
    temp_r28 = (s16)Math_Ease(2, (f32)(s16)(s32)var_r6, lbl_8036A75C, (f32)*(s16 *)((u8 *)arg0 + 0x40), (f32)temp_r31);
    temp_f1 = Math_Ease(2, (f32)var_r29, lbl_8036A75C, (f32)*(s16 *)((u8 *)arg0 + 0x40), (f32)temp_r31);
    *(s16 *)((u8 *)var_r30 + 0x8C) = temp_r28;
    *(s16 *)((u8 *)var_r30 + 0x8E) = (s16)temp_f1;
}

void fn_801426B4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x40) = 0;
}

void fn_801426C0(void *arg0) {
    void Ui_DtorPanelBase(void *, s32);
    void *var_r4;

    if (*(u32 *)((u8 *)arg0 + 0x34) != 0U) {
        var_r4 = *(void **)(*(u8 **)((u8 *)arg0 + 0x38) + 8);
    } else {
        var_r4 = NULL;
    }
    *(s16 *)((u8 *)var_r4 + 0x8C) = 0;
    *(s16 *)((u8 *)var_r4 + 0x8E) = 0;
    if (arg0 != NULL) {
        Ui_DtorPanelBase(arg0, 0);
    }
}

#pragma cplusplus on
extern "C" void fn_80142714(void *arg0) {
    void fn_801569C4(s32, s32, s16, s16, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_801569C4(0, 0,
        (s16)(*(s16 *)((u8 *)arg0 + 0xE) - *(s16 *)((u8 *)arg0 + 0xA)),
        (s16)(*(s16 *)((u8 *)arg0 + 0x10) - *(s16 *)((u8 *)arg0 + 0xC)),
        0xE6, 0x10);
}
#pragma cplusplus reset
void fn_80142780(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5) {
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    fn_8008AB7C(arg1 + (arg3 >> 1), arg2 + (arg4 >> 1), arg3, 0x17, 0x19, 0x4C, arg5);
}

void fn_801427D4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5) {
    void UnitRef_DrawScaled(s32, s32, s16, s16, f32);
    s16 t1;
    s16 t2;
    void *p = arg0;
    t2 = (s16)arg2;
    t1 = (s16)arg1;
    UnitRef_DrawScaled(*arg4, arg5, t1, t2, *(f32 *)((u8 *)p + 0x128));
}

void fn_80142814(s32 arg0, s16 arg1, s16 arg2, s32 arg3, s32 *arg4, s32 arg5) {
    M2C_UNK UnitRef_DrawSell(s32, s32, s32, s32);
    UnitRef_DrawSell(*arg4, arg5, arg1, arg2);
}

s32 Item_GetUiKind(s32 unused, void **itemRef) {
    /* Return the item's kind for UI; kind 7 keeps 7 only when flags & 3, else becomes 8. */
    void *Item_GetFlagsPtr(void **);
    s32 result = 12;
    void *item = *itemRef;
    u8 kind;

    if (item) {
        kind = *(u8 *)((u8 *)item + 0x12);
    } else {
        kind = 12;
    }
    switch (kind) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 1;
        break;
    case 2:
        result = 2;
        break;
    case 3:
        result = 3;
        break;
    case 4:
        result = 4;
        break;
    case 5:
        result = 5;
        break;
    case 6:
        result = 6;
        break;
    case 7:
        if ((*(u64 *)Item_GetFlagsPtr(itemRef) & 3ULL) != 0) {
            result = 7;
            break;
        }
    case 8:
        result = 8;
        break;
    case 9:
        result = 9;
        break;
    case 10:
        result = 10;
        break;
    case 11:
    case 12:
        result = 12;
        break;
    }
    return result;
}

#pragma cplusplus on
extern "C" void fn_80142934(void *arg0, s32 arg1) {
extern u8 lbl_80292314[];
struct Obj { virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0; virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; };
struct Node { Node *prev; Node *next; Obj *obj; };
typedef void (Obj::*PTMF)(s32);
struct Pair { PTMF ptmf; s32 arg; };
Pair p[2];
Node *it;
Node *sent;
((Obj*)arg0)->v6();
sent=(Node*)((u8*)arg0+0x40);
p[0].ptmf=*(PTMF*)lbl_80292314;
p[0].arg=arg1;
((u32*)&p[1].ptmf)[0]=((u32*)&p[0].ptmf)[0];
it=sent->next;
((u32*)&p[1].ptmf)[1]=((u32*)&p[0].ptmf)[1];
((u32*)&p[1].ptmf)[2]=((u32*)&p[0].ptmf)[2];
p[1].arg=arg1;
while(it!=sent) { (it->obj->*p[0].ptmf)(p[0].arg); it=it->next; }
}

struct UiPageSelector {
virtual void v0()=0;
virtual void v1()=0;
virtual void v2()=0;
virtual void v3()=0;
virtual void v4()=0;
virtual void v5()=0;
virtual void v6()=0;
virtual void v7()=0;
virtual void v8()=0;
virtual void v9()=0;
virtual s32 page()=0;
};
extern "C" void fn_801429E0(void *arg0)
{
  extern u32 gUiInputFlags;
  extern u32 *gPadInput;
  extern u8 lbl_80276B3C[];
  extern f32 lbl_8036A764;
  extern f32 lbl_8036A768;
  void Ui_PlaySeCue(void *, s32);
  void fn_8013ED84(void *, s16);
  u8 *self = (u8 *) arg0;
  s32 index;
  u8 *page;
  s32 repeat;
  u32 visible;
  s32 edge;
  s32 held;
  s16 old;
  s16 count;
  u8 blocked;
  index = ((UiPageSelector *) arg0)->page();
  page = self + (index * 2);
  count = *((s32 *) ((self + 0x90) + (index * 12)));
  if (count == 0)
  {
    *((s16 *) (page + 0x4e)) = 0;
    *((s16 *) (page + 0x64)) = 0;
    return;
  }
  visible = *((u16 *) (self + 0x80));
  blocked = ((gUiInputFlags & 0x10) != 0) && ((gUiInputFlags & 0x20) == 0);
  if (!blocked)
  {
    old = *((s16 *) (page + 0x64));
    held = gPadInput[1];
    edge = gPadInput[2] ^ held;
    repeat = gPadInput[3];
    edge = held & edge;
    if (((s16) (*((f32 *) (self + 0x84)))) == 0)
    {
      if (repeat & 0x08000008)
      {
        if (((s16) old) == 0)
        {
          if (repeat == edge)
          {
            *((s16 *) (page + 0x64)) = count - 1;
            *((s16 *) (page + 0x4e)) = (count > ((s16) visible)) ? (count - ((s16) visible)) : (0);
          }
        }
        else
        {
          *((s16 *) (page + 0x64)) = old - 1;
          if ((((s16) (*((s16 *) (page + 0x64)))) > 0) && (((*((s16 *) (page + 0x64))) - (*((s16 *) (page + 0x4e)))) == 0))
          {
            *((s16 *) (page + 0x4e)) -= 1;
            *((f32 *) (self + 0x84)) = -32.0f;
          }
        }
        if (old != (*((s16 *) (page + 0x64))))
        {
          Ui_PlaySeCue(lbl_80276B3C + 0x1d, 100);
        }
      }
      else
        if (repeat & 0x04000004)
      {
        s32 last = count - 1;
        if (old == last)
        {
          if (repeat == edge)
          {
            *((s16 *) (page + 0x64)) = 0;
            *((s16 *) (page + 0x4e)) = 0;
          }
        }
        else
        {
          *((s16 *) (page + 0x64)) = old + 1;
          if (((*((s16 *) (page + 0x64))) < last) && (((*((s16 *) (page + 0x64))) - (*((s16 *) (page + 0x4e)))) == (((s16) visible) - 1)))
          {
            *((s16 *) (page + 0x4e)) += 1;
            *((f32 *) (self + 0x84)) = 32.0f;
          }
        }
        if (old != (*((s16 *) (page + 0x64))))
        {
          Ui_PlaySeCue(lbl_80276B3C + 0x1d, 100);
        }
      }
    }
  }
  fn_8013ED84(*((void **) (self + 0x48)), (s16) (((*((s16 *) (page + 0x4e))) << 5) - ((s32) (*((f32 *) (self + 0x84))))));
}

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma global_optimizer on
extern "C" void fn_80142C00(void *self, void *other) {
    struct Obj {
        virtual void v1() = 0;
        virtual void v0() = 0;
        virtual void v2() = 0;
        virtual void v3(void *) = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual s32 v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v14() = 0;
        virtual void v13() = 0;
        virtual void v15() = 0;
        virtual void v16(s16, s16, s32, s16, u8) = 0;
    };
    struct Sub {
        virtual void v0() = 0;
    };
    struct Node {
        Node *prev;
        Node *next;
        Sub *obj;
    };
    typedef void (Sub::*PTMF)(void *);
    struct Pair {
        PTMF ptmf;
        void *arg;
    };
    void fn_8000A258(void);
    void fn_80009C0C(f32);
    void fn_8000A248(void);
    s32 fn_800102BC(s32, f32);
    void fn_8008BF68(s16, s32, u8);
    void fn_80009B80(s32);
    extern u8 lbl_80292308[];
    extern f32 lbl_8036A76C;
    extern f32 lbl_8036A758;
    extern f32 lbl_8036A770;
    Pair p[2];
    s32 t31;
    u8 r30;
    u8 *slot;
    s16 val;
    s16 t27;
    Node *it;
    Node *sent;
    s16 t7c;
    u8 flag;
    void *ptr;
    s16 t25;
    s16 t26;

    p[1].arg = other;
    sent = (Node *)((u8 *)self + 0x40);
    p[0].ptmf = *(PTMF *)lbl_80292308;
    p[0].arg = other;
    it = *(Node **)((u8 *)self + 0x44);
    p[1].ptmf = p[0].ptmf;
    while (it != sent) {
        (it->obj->*p[0].ptmf)(p[0].arg);
        it = it->next;
    }
    ((Obj *)self)->v3(other);
    {
        s32 idx = ((Obj *)self)->v10();
        int raw;
        slot = (u8 *)self + (idx << 1);
        raw = *(s32 *)((u8 *)self + (idx * 0xC) + 0x90);
        val = (s16)raw;
        if (val == 0) {
            *(s16 *)(slot + 0x4E) = 0;
            *(s16 *)(slot + 0x64) = 0;
        }
    }
    {
        s16 a = *(s16 *)(slot + 0x4E);
        s16 b = *(s16 *)(slot + 0x64);
        t7c = *(s16 *)((u8 *)self + 0x7C);
        s16 diff = (s16)(b - a);
        s16 c = *(s16 *)((u8 *)self + 0x8A);
        register t31 = *(s16 *)((u8 *)self + 0x88);
        t27 = (s16)((diff << 5) + c);
    }
    if (t7c < 0 || *(s16 *)((u8 *)self + 0x7E) < 0) {
        *(s16 *)((u8 *)self + 0x7C) = (s16)t31;
        *(s16 *)((u8 *)self + 0x7E) = t27;
    } else {
        *(s16 *)((u8 *)self + 0x7C) = (t7c + (s16)t31 + 1) >> 1;
        *(s16 *)((u8 *)self + 0x7E) = (*(s16 *)((u8 *)self + 0x7E) + t27 + 1) >> 1;
    }
    if (*(u8 *)((u8 *)self + 0x4C) != 0) {
        u8 b1 = *(u8 *)((u8 *)other + 0x2D);
        r30 = 0;
        flag = r30;
        if (b1 == 0) {
            if (*(u8 *)((u8 *)other + 0x2E) == 0) {
                flag = 1;
            }
        }
        if (flag) {
            if (*(u32 *)((u8 *)other + 0x34) != 0) {
                ptr = (*(void ***)((u8 *)other + 0x38))[2];
            } else {
                ptr = 0;
            }
            if (ptr == self) {
                r30 = 1;
            }
        }
        fn_8000A258();
        fn_80009C0C(lbl_8036A76C);
        fn_8000A248();
        fn_8008BF68(*(s16 *)((u8 *)self + 0x7C),
                    *(s16 *)((u8 *)self + 0x7E) + (s16)((0x20 - fn_800102BC(-1, lbl_8036A758)) >> 1),
                    r30);
        fn_8000A258();
        fn_80009C0C(lbl_8036A758);
        fn_8000A248();
        ((Obj *)self)->v16(0, t27,
            (s16)(*(s16 *)((u8 *)self + 0x16) - *(s16 *)((u8 *)self + 0x12)),
            0x20, r30);
    }
    if (val != 0 && *(u8 *)((u8 *)self + 0x4D) != 0) {
        ((Obj *)self)->v3(other);
        fn_8000A258();
        fn_80009C0C(lbl_8036A770);
        fn_8000A248();
        {
            s16 a = *(s16 *)(slot + 0x4E);
            s16 b = *(s16 *)((u8 *)self + 0x7A);
            s16 c = *(s16 *)((u8 *)self + 0x8A);
            t25 = (s16)(((s16)(b - a) << 5) + c);
        }
        t26 = (s16)((0x20 - fn_800102BC(-1, lbl_8036A758)) >> 1);
        fn_8000A258();
        fn_80009B80(0x40);
        fn_8000A248();
        fn_8008BF68((s16)t31, t25 + t26, 0);
    }
    fn_8000A258();
    fn_80009B80(0x80);
    fn_8000A248();
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs on
#pragma opt_strength_reduction on
#pragma use_lmw_stmw on
extern "C" void fn_80142ED0(Menu42 *self, s32 arg) {
void fn_8013F748(void *,s16 *,s16 *);
void Prim2D_ScissorFromRect(void *);
void Prim2D_Begin(void); void Prim2D_PrepareTex(void);
void Prim2D_SetCallback(void (*)(void *),s16 *);
void Prim2D_AddZ(f32); void Prim2D_ClearCallbacks(void);
void Prim2D_SetTex(s32,s32);
void *Msg_Expand(void *);
s32 Text_MeasureWidth(void *,s32,f32);
void Text_Draw(s16,s16,s32,void *,...);
void *fn_8003A064(void *); void *fn_8003A114(void *);
void *Face_Create(void *,s32);
void fn_8007B4D8(s16,s16,s32,void *);
void Face_ClearSlot(void *);
extern const f32 lbl_8036A770,lbl_8036A75C,lbl_8036A760,lbl_8036A758,lbl_8036A748;
extern f32 lbl_80367098[];
extern u8 lbl_80276B3C[];
extern void (Menu42::*lbl_802922FC)(s32);
Menu42Callback cb;
s16 rows, scroll, x, y;
s32 sign;
s32 page;
u8 *table, *slot, *node;
s16 count;
self->prepare();
self->draw(arg);
{
s16 *rect = (s16 *)((u8 *)self + 0x114);
s16 h = M2C_FIELD(self, s16 *, 0x18) - M2C_FIELD(self, s16 *, 0x14);
s16 w = M2C_FIELD(self, s16 *, 0x16) - M2C_FIELD(self, s16 *, 0x12);
rect[0] = 0; rect[1] = 0; rect[2] = w; rect[3] = h;
fn_8013F748(self, rect, rect);
rect = (s16 *)((u8 *)self + 0x118);
fn_8013F748(self, rect, rect);
}
{
s32 pg = self->page();
s32 mul12 = pg * 12;
s32 mul2 = pg << 1;
rows = M2C_FIELD(self, s16 *, 0x80);
slot = (u8 *)self + mul2;
page = pg;
{
s16 index = *(s16 *)(slot + 0x4e);
table = (u8 *)self + mul12 + 0x90;
count = (s16)*(s32 *)table;
Prim2D_Begin();
Prim2D_SetCallback(Prim2D_ScissorFromRect, (s16 *)((u8 *)self + 0x114));
Prim2D_AddZ(lbl_8036A770);
Prim2D_PrepareTex();
{
f32 f = M2C_FIELD(self, f32 *, 0x84);
f32 zero = lbl_8036A75C;
scroll = (s16)f;
if (f < zero) {
f = M2C_FIELD(self, f32 *, 0x84) + lbl_8036A760;
M2C_FIELD(self, f32 *, 0x84) = f;
if (f >= -lbl_80367098[0]) M2C_FIELD(self, f32 *, 0x84) = zero;
} else if (f > zero) {
f = M2C_FIELD(self, f32 *, 0x84) - lbl_8036A760;
M2C_FIELD(self, f32 *, 0x84) = f;
if (f <= lbl_80367098[0]) M2C_FIELD(self, f32 *, 0x84) = zero;
}
}
if (scroll < 0) sign = -1; else sign = (scroll > 0);
if ((s16)sign > 0 && index > 0) --index;
node = *(u8 **)(table + 8);
{
s16 n = index;
if (index >= 0) { while (n > 0) { node = *(u8 **)(node + 4); --n; } }
else { while (n < 0) { node = *(u8 **)(node + 0); ++n; } }
}
y = M2C_FIELD(self, s16 *, 0x8e) + M2C_FIELD(self, s16 *, 0x8a) + 4;
x = M2C_FIELD(self, s16 *, 0x8c) + M2C_FIELD(self, s16 *, 0x88);
{
s16 row = sign > 0 ? -1 : 0;
s32 end = (s16)rows;
if ((s16)sign < 0) ++end;
{
s32 ypos = y + (row << 5);
s32 remaining = count - index;
for (; row < (s16)end; ypos += 32, ++row) {
if (row >= remaining) break;
self->row(x, (s16)(scroll + ypos), -1, node + 8, self->item(node + 8));
node = *(u8 **)(node + 4);
}
}
}
}
}
page = self->page();
table = (u8 *)self + page * 12 + 0x90;
{
u8 *selected;
s32 selectionOffset = (page << 1) + 0x64;
if (*(u32 *)table == 0) selected = 0;
else {
node = *(u8 **)(table + 8);
{
s16 n = *(s16 *)((u8 *)self + selectionOffset);
if (n >= 0) { while (n > 0) { node = *(u8 **)(node + 4); --n; } }
else { while (n < 0) { node = *(u8 **)(node + 0); ++n; } }
}
selected = node + 8;
}
if (selected == 0) {
void *text = Msg_Expand(lbl_80276B3C + 0x39);
s16 width = M2C_FIELD(self, s16 *, 0x16) - M2C_FIELD(self, s16 *, 0x12);
s16 left = (width - Text_MeasureWidth(text, -1, lbl_8036A758)) >> 1;
Prim2D_Begin(); Prim2D_SetTex(0, 0x13); Prim2D_PrepareTex();
Text_Draw((s16)(left + M2C_FIELD(self, s16 *, 0x8c)), y, 0, text);
}
if (selected != 0 && M2C_FIELD(self, s32 *, 0x11c) != 0 && *(void **)(selected + 4) != 0) {
s16 cx = (M2C_FIELD(self, s16 *, 0x8c) + (s16)(M2C_FIELD(self, s16 *, 0x16) - M2C_FIELD(self, s16 *, 0x12))) >> 1;
s16 cy = M2C_FIELD(self, s16 *, 0x8e) + (s16)(M2C_FIELD(self, s16 *, 0x18) - M2C_FIELD(self, s16 *, 0x14));
s32 mode = M2C_FIELD(self, s32 *, 0x11c);
u8 *sprite;
if (mode == 1 || mode == 2) sprite = (u8 *)Face_Create(fn_8003A064(*(void **)(selected + 4)), 0x100);
else sprite = (u8 *)Face_Create(fn_8003A114(*(void **)(selected + 4)), 0x100);
{
s16 a = M2C_FIELD(self, s16 *, 0xa);
s16 mid = (s16)(a + ((s16)(M2C_FIELD(self, s16 *, 0xe) - a) >> 1));
*(u16 *)(sprite + 0x46) &= 0xfffe;
*(u16 *)(sprite + 0x46) |= mid < 0x130;
}
Prim2D_Begin(); Prim2D_AddZ(lbl_8036A748); Prim2D_PrepareTex();
if (M2C_FIELD(self, s32 *, 0x11c) == 2) cy += *(s16 *)(*(u8 **)(sprite + 0x34) + 0x1e);
fn_8007B4D8(cx, cy, 0x7f, sprite); Face_ClearSlot(sprite);
}
}
Prim2D_Begin(); Prim2D_ClearCallbacks(); Prim2D_PrepareTex();
{
u8 *child = M2C_FIELD(self, u8 **, 0x48);
*(s16 *)(child + 0x3c) = count << 5;
*(s16 *)(child + 0x3e) = rows << 5;
*(s16 *)(child + 0x40) = (*(s16 *)(slot + 0x4e) << 5) - scroll;
}
cb.method = lbl_802922FC; cb.arg = arg;
Menu42Visit(M2C_FIELD(self, void **, 0x44), (u8 *)self + 0x40, cb);
}
#pragma pop
#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_80143424(void *arg0) {
    void fn_8015DE0C(s32, s32, s16, s16, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_8015DE0C(0, 0,
        (s16)(*(s16 *)((u8 *)arg0 + 0xE) - *(s16 *)((u8 *)arg0 + 0xA)),
        (s16)(*(s16 *)((u8 *)arg0 + 0x10) - *(s16 *)((u8 *)arg0 + 0xC)),
        0xFF, 0x10);
}
#pragma cplusplus reset
void fn_80143490(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5) {
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    fn_8008AB7C(arg1 + (arg3 >> 1), arg2 + (arg4 >> 1), arg3, 0x18, 0x19, 0x4C, arg5);
}

void fn_801434E4(s32 arg0, s16 arg1, s16 arg2, s32 arg3, s32 *arg4, s32 arg5) {
    M2C_UNK UnitRef_Draw(s32, s32, s32, s32);
    UnitRef_Draw(*arg4, arg5, arg1, arg2);
}

s32 fn_8014351C(void *arg0, s32 arg1) {
    u8 (*temp_r12)(s32, s32);

    temp_r12 = M2C_FIELD(arg0, u8 (**)(s32, s32), 0x120);
    if (temp_r12 != NULL) {
        return temp_r12(arg1, M2C_FIELD(arg0, s32 *, 0x124)) != 0;
    }
    return 1;
}

#pragma push
#pragma opt_strength_reduction off
void fn_80143570(void *arg0) {
    void fn_80144B60(void *, MenuSortTag);
    struct {
        u8 pad[0x90];
        struct {
            u8 data[12];
        } items[11];
    } *s = arg0;
    s32 i;
    MenuSortTag tag;
    for (i = 0; i != 11; i++) {
        fn_80144B60(&s->items[i], tag);
    }
}
#pragma pop
#pragma cplusplus on
extern "C" s16 fn_801435E0(void *arg0, u32 arg1) {
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
        virtual s32 v12() = 0;
    };
    struct Node {
        struct Node *prev;
        struct Node *next;
        u32 key;
    };
    struct S {
        u8 f;
        u32 v;
    };
    u8 flag;
    s32 table;
    struct Node *sentinel;
    struct Node *head;
    struct Node *node;
    s32 idx;
    s32 i;
    void *self;

    self = arg0;
    idx = ((Obj *)self)->v12();
    if (idx == 0xC) {
        return -1;
    }
    S a = { flag, arg1 };
    table = (s32)self + idx * 0xC + 0x90;
    sentinel = (struct Node *)(table + 4);
    head = *(struct Node **)(table + 8);
    S b = a;
    node = head;
    while (node != sentinel && node->key != arg1) {
        node = node->next;
    }
    i = -1;
    if (node != (struct Node *)(table + 4)) {
        i = 0;
        while (head != node) {
            head = head->next;
            i += 1;
        }
    }
    return (s16)i;
}
#pragma cplusplus reset

#pragma cplusplus on
