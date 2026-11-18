/* Functions from 0x80132800 to 0x80149F38, found by decomp-toolkit. */
#include "common.h"
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

void *fn_8013CD90(void **arg0) {
    void *Msg_Expand(void *);
    extern u8 lbl_80276908[];
    void *p = arg0[8];
    return p != NULL ? Msg_Expand(p) : lbl_80276908 + 0x72;
}
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
    extern u8 lbl_802845E8[];
    extern u8 lbl_802920E0[];
    extern u8 lbl_80291DA0[];
    extern f32 lbl_8036A6B8;
    f32 f;
    s32 z;

    z = 0;
    *(void **)((u8 *)arg0 + 4) = lbl_802845E8;
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

extern "C" void fn_8013D2E0(void *arg0, void *arg1) {
    void *GfxEnt_Get(u8);
    void Ui_PlaySeCue(void *, s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoPopup(void *, void *, f32, f32);
    void Ui_ShowUnitInfoText(void *, f32, f32);
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
    s16 rows = (s16)self->Rows();
    s16 cols = (s16)self->Cols();
    s16 colW = cols;
    u8 skip = 0;
    s16 row = (s16)((s8)p[0x62] / colW);
    s16 col = (s16)((s8)p[0x62] % colW);
    u32 trig, held, edge;
    s16 rem;
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
        if (cols > 1) {
            rem = (s16)(maxIdx - row * colW);
            if (rem > cols)
                rem = cols;
            if (trig & 0x01000001) {
                if (col > 0)
                    p[0x62] = (u8)(p[0x62] - 1);
                else if (trig == edge)
                    p[0x62] = (u8)((rem + p[0x62]) - 1);
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
                    p[0x62] = (u8)(p[0x62] + (rows - 1) * colW);
                    if ((s8)p[0x62] > maxIdx - 1)
                        p[0x62] = (u8)(maxIdx - 1);
                }
            } else {
                p[0x62] = (u8)(p[0x62] - cols);
            }
        } else if (trig & 0x04000004) {
            if (row == rows - 1) {
                if (trig == edge)
                    p[0x62] = (u8)(p[0x62] - (rows - 1) * colW);
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
                    Ui_ShowUnitInfoText(gUnitInfoPopup, fx, fy);
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

extern "C" void fn_8013D6E0(void *arg0, void *arg1) {
void *GfxEnt_Get(u8);
#pragma cplusplus on
struct Obj { u8 pad[4];
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
virtual s16 v20()=0;
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
virtual s16 v33(void *)=0;
virtual s16 v34()=0;
virtual s16 v35()=0;
};
Obj *self=(Obj*)arg0; u8 *p=(u8*)arg1;
s16 dx=self->v35();
s16 dy=self->v20();
s32 xoff=self->v31();
s16 x=xoff+self->v16();
s32 yoff=self->v32();
s16 y=yoff+self->v17();
s16 rows=self->v33(arg1);
s16 cols=self->v34();
s32 row=0, index=0;
for (;row<rows && index<(s8)p[0x60]; ++row) {
s32 yy=y+row*dy;
s32 col=0;
for (;col<cols && index<(s8)p[0x60];++col,++index) {
void *ent=GfxEnt_Get(p[0x40+index]);
*(s16*)((u8*)ent+0x30)=x+col*dx;

*(s16*)((u8*)ent+0x32)=yy;
}
}
#pragma cplusplus reset
}

#pragma cplusplus reset

void fn_8013DAD8(void **arg0, void *arg1, void *arg2) {
    M2C_UNK Prim2D_SetText();
    M2C_UNK Prim2D_SetTextScale(M2C_UNK, f32);
    M2C_UNK Prim2D_SetColorPacked(s32 *);
    M2C_UNK Prim2D_SetPos(f32, f32);
    M2C_UNK Prim2D_EndPrim();
    M2C_UNK Prim2D_AddPrim(M2C_UNK, s32, s16);
    M2C_UNK Prim2D_SetAlphaByte(M2C_UNK);
    s32 Text_MeasureHeight(M2C_UNK, f32);
    M2C_UNK Ui_DrawIcon(M2C_UNK *, s32, s32, s32);
    s32 *Ui_GetColor(M2C_UNK);
    extern M2C_UNK gUiIconDrawer;
    extern f32 lbl_8036A6C0;
    extern f32 gUiMenuSlotPlainTextScale;
    s32 sp8;
    f32 temp_f30;
    f32 temp_f31;
    s16 temp_r30;
    s16 temp_r3_4;
    s32 temp_r30_2;
    s32 temp_r3_2;
    s32 temp_r4;
    s32 temp_r5_2;
    void **temp_r3;
    void **temp_r3_5;
    void **temp_r3_6;
    void **temp_r3_7;
    void *temp_r3_3;
    void *temp_r5;

    M2C_FIELD(*arg0, M2C_UNK (**)(), 0x4C)();
    temp_r3 = M2C_FIELD(arg2, void ***, 0x34);
    temp_r3_2 = M2C_FIELD(*temp_r3, s32 (**)(void **), 0x1C)(temp_r3);
    temp_r5 = M2C_FIELD(arg1, void **, 0x3C);
    temp_r4 = (s32) (-temp_r3_2 | temp_r3_2) >> 0x1F;
    temp_r30 = M2C_FIELD(M2C_FIELD(temp_r5, void **, 4), s16 (**)(void *, s32, void *), 0x58)(temp_r5, temp_r4, temp_r5);
    temp_r3_3 = M2C_FIELD(arg1, void **, 0x3C);
    temp_r30_2 = (s32) (temp_r30 - Text_MeasureHeight(-1, lbl_8036A6C0)) >> 1;
    temp_r3_4 = M2C_FIELD(M2C_FIELD(temp_r3_3, void **, 4), s16 (**)(void *), 0x58)(temp_r3_3);
    temp_r5_2 = temp_r3_4 - 0x18;
    temp_f31 = (f32) M2C_FIELD(arg2, s16 *, 0x30);
    temp_f30 = (f32) M2C_FIELD(arg2, s16 *, 0x32);
    Prim2D_AddPrim(6, temp_r5_2, temp_r3_4);
    Prim2D_SetPos(temp_f31 + (f32) (0x18 & temp_r4), temp_f30 + (f32) temp_r30_2);
    if ((u8) M2C_FIELD(arg2, u8 *, 0x39) == 2) {
        sp8 = *Ui_GetColor(0);
        Prim2D_SetColorPacked(&sp8);
    } else {
        Prim2D_SetTextScale(1, gUiMenuSlotPlainTextScale);
    }
    temp_r3_5 = M2C_FIELD(arg2, void ***, 0x34);
    M2C_FIELD(*temp_r3_5, M2C_UNK (**)(void **, void *), 0x18)(temp_r3_5, arg2);
    Prim2D_SetText();
    Prim2D_EndPrim();
    temp_r3_6 = M2C_FIELD(arg2, void ***, 0x34);
    if (M2C_FIELD(*temp_r3_6, s32 (**)(void **), 0x1C)(temp_r3_6) != 0) {
        temp_r3_7 = M2C_FIELD(arg2, void ***, 0x34);
        Ui_DrawIcon(&gUiIconDrawer, (s32) temp_f31, (s32) (temp_f30 + (f32) (temp_r5_2 >> 1)), M2C_FIELD(*temp_r3_7, s32 (**)(void **), 0x1C)(temp_r3_7));
    }
    Prim2D_Begin();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}

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
#pragma use_lmw_stmw on
#pragma global_optimizer off
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
else { u32 ny=y+1; u32 nx=x+1;
nx+=*(s16*)(ctx+0x38); *(s16*)(ctx+0x38)=(s32)nx/2;
ny+=*(s16*)(ctx+0x3a); *(s16*)(ctx+0x3a)=(s32)ny/2;
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

extern "C" void fn_8013E080(void *arg0, void *arg1) {
struct Obj { u8 pad[4];
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
virtual s16 getX()=0; virtual s16 getY()=0; virtual void v23()=0; virtual void v24()=0; virtual f32 getZ()=0;
};
f32 UiWin_GetFade(void *); f32 Math_Ease(s32,f32,f32,f32,f32);
void fn_80009C20(f32,f32,f32,f32,f32,f32,f32,f32);
void Prim2D_Begin(void); void Prim2D_SetColorByte(s32); void Prim2D_SetAlphaByte(s32); void Prim2D_PrepareTex(void);
extern f32 lbl_8036A6C0, lbl_8036A6E0, lbl_8036A6E4;
f32 y, z, fade, scale; s16 x;
u8 focused, alpha;
fade=UiWin_GetFade(arg1);
scale=Math_Ease(5,lbl_8036A6E0,lbl_8036A6C0,fade,lbl_8036A6C0);
Prim2D_Begin();
z=((Obj *)arg0)->getZ();
y=((Obj *)arg0)->getY();
x=((Obj *)arg0)->getX();
fn_80009C20(x,y,z,lbl_8036A6E0,lbl_8036A6E0,scale,scale,lbl_8036A6E0);
Prim2D_SetColorByte((s32)(lbl_8036A6E4*fade));
focused=0;
if(*((u8 *)arg1+0x2D)==0 && *((u8 *)arg1+0x2E)==0) focused=1;
alpha=0x40;
if(focused) alpha=0x80;
Prim2D_SetAlphaByte(alpha);
Prim2D_PrepareTex();
}

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
s16 fn_8013E684(void *arg0, void *arg1) {
    s16 (*vm)(void *);
    s16 temp;
    s32 sum;

    vm = *(s16 (**)(void *))(*(u8 **)((u8 *)arg0 + 4) + 0x90);
    temp = vm(arg0);
    sum = (s32)temp + *(s8 *)((u8 *)arg1 + 0x60);
    sum -= 1;
    return (s16)(sum / (s32)temp);
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

void *fn_8013EDD4(void *arg0, s16 arg1) {
    extern u8 lbl_802921B0[];
    extern u8 lbl_80291914[];
    extern u8 lbl_802918E0[];
    extern u8 lbl_80292230[];
    extern u8 lbl_8028FDB0[];
    extern u8 gEmptyVtbl[];
    void Heap_Free(void *);

    u8 *self;
    u8 *sub;
    void (**vtbl)(void *);

    self = (u8 *)arg0;

    if (self != NULL) {
        *(void **)self = lbl_802921B0;

        if (self != NULL) {
            *(void **)self = lbl_80291914;

            if (self + 0x74 != NULL) {
                *(void **)(self + 0x74) = lbl_802918E0;

                if (self + 0x74 != NULL) {
                    sub = self + 0x74;
                    *(void **)sub = gEmptyVtbl;
                    vtbl = *(void (***)(void *))sub;
                    vtbl[4](sub);
                }
            }

            if (self + 0x4C != NULL) {
                *(void **)(self + 0x4C) = lbl_802918E0;

                if (self + 0x4C != NULL) {
                    sub = self + 0x4C;
                    *(void **)sub = gEmptyVtbl;
                    vtbl = *(void (***)(void *))sub;
                    vtbl[4](sub);
                }
            }

            if (self != NULL) {
                *(void **)self = lbl_80292230;

                if (self != NULL) {
                    *(void **)self = lbl_8028FDB0;
                }
            }
        }

        if (arg1 > 0) {
            Heap_Free(self);
        }
    }

    return self;
}

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
    s16 z;
    s16 midX;
    s16 midY;
    f32 scale;

    pt.x = 0;
    pt.y = 0;
    fn_8013F748(arg0, &pt, &pt);

    midX = (s16)(((s16)(M2C_FIELD(arg0, s16 *, 0xE) - M2C_FIELD(arg0, s16 *, 0xA)) >> 1) - M2C_FIELD(arg0, s16 *, 0x12));
    midY = (s16)(((s16)(M2C_FIELD(arg0, s16 *, 0x10) - M2C_FIELD(arg0, s16 *, 0xC)) >> 1) - M2C_FIELD(arg0, s16 *, 0x14));

    Prim2D_Begin();
    z = M2C_FIELD(arg0, s16 *, 0x22);
    scale = fn_8013FA44(arg0);
    fn_80009C20((f32)pt.x, (f32)pt.y, (f32)z, (f32)midX, (f32)midY, fn_8013FA44(arg0), scale, lbl_8036A718);
    Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 2));
    Prim2D_SetColorByte(fn_80138908(arg0));
    Prim2D_SetAlphaByte(fn_8013FA10(arg0));
    Prim2D_PrepareTex();
}

void fn_8013F54C(void *arg0) {
#pragma opt_common_subs off
void fn_8013F748(void *,void *,void *);
f32 fn_8013FA44(void *);
s32 fn_80138908(void *);
s32 fn_8013FA10(void *);
void fn_80009C20(f32,f32,f32,f32,f32,f32,f32,f32);
void Prim2D_SetColorByte(s32);
void Prim2D_SetAlphaByte(s32);
extern f32 lbl_8036A718;
struct Point { s16 x,y; } pt;
s16 z,height,width;
f32 scale;
*(u32 *)&pt=M2C_FIELD(arg0,u32 *,0xA);
if(M2C_FIELD(arg0,void **,0x38)) fn_8013F748(M2C_FIELD(arg0,void **,0x38),&pt,&pt);
Prim2D_Begin();
height=(s16)(M2C_FIELD(arg0,s16 *,0x10)-M2C_FIELD(arg0,s16 *,0xC));
width=(s16)(M2C_FIELD(arg0,s16 *,0xE)-M2C_FIELD(arg0,s16 *,0xA));
z=M2C_FIELD(arg0,s16 *,0x22);
scale=fn_8013FA44(arg0);
fn_80009C20((f32)pt.x,(f32)pt.y,(f32)z,(f32)(width>>1),(f32)(height>>1),fn_8013FA44(arg0),scale,lbl_8036A718);
Prim2D_SetTex(0,(u16)(M2C_FIELD(arg0,u32 *,0x34)|2));
Prim2D_SetColorByte(fn_80138908(arg0));
Prim2D_SetAlphaByte(fn_8013FA10(arg0));
Prim2D_PrepareTex();
#pragma opt_common_subs reset
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

void fn_8013FBC8(s32 *, s32 *);
s32 fn_8013FBD4(s32);
void fn_8013FBDC(s16 *, s16 *);
void fn_8013FC00(s16 *, s16 *);
void fn_8013FC14(s16 *, s16 *);
void fn_8013FC28(s32 *, s32 *, s16 *);
s32 fn_8013FBC0(s32);
s32 fn_80138AB8(void *);

Vec2s *fn_8013FC64(Vec2s *);
#pragma inline_depth(0)
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
    void *ggf;
    void *gp;
    void *parent;
    s32 *p8;

    parent = *(void **)((u8 *)arg0 + 0x38);
    sp3C = *(Vec2s *)((u8 *)arg0 + 0xA);
    if (parent != NULL) {
        sp24 = *fn_8013FC64((Vec2s *)((u8 *)parent + 0xA));
        gp = *(void **)((u8 *)parent + 0x38);
        if (gp != NULL) {
            sp18 = *(Vec2s *)fn_8013FBD4((s32)gp);
            if (*(u32 *)((u8 *)gp + 0x38) != 0) {
                ggf = (void *)fn_80138AB8(gp);
                fn_8013FBC8((s32 *)&spC, (s32 *)fn_8013FBD4((s32)ggf));
                if ((u32)fn_80138AB8(ggf) != 0) {
                    fn_8013F748((void *)fn_80138AB8(ggf), &spC, &spC);
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
        p8 = (s32 *)&sp8;
        fn_8013FBC8(p8, (s32 *)&sp2C);
        fn_8013FBDC((s16 *)p8, (s16 *)&sp3C);
        fn_8013FBC8((s32 *)&sp28, p8);
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
#pragma inline_depth(8)
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

void fn_8013FBC8(s32 *arg0, s32 *arg1) {
    *arg0 = *arg1;
}

s32 fn_8013FBD4(s32 arg0) {
    return arg0 + 0xA;
}

#pragma global_optimizer off
void fn_8013FBDC(s16 *dst, s16 *src) {
s16 c,b,a,d;
a=dst[0]; b=src[0]; c=src[1];
d=a;
d+=b;
dst[0]=d;
d=dst[1]; c=d+c; dst[1]=c;
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
struct Obj { virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0; virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0; };
void *self=arg0;
void *flag=*(void **)((u8 *)arg0+0x34);
Obj *p;
Obj *q;
if(flag) { p=*(Obj **)((u8 *)*(void **)((u8 *)self+0x38)+8); } else p=0;
if(p) { q=flag ? *(Obj **)((u8 *)*(void **)((u8 *)self+0x38)+8):0; q->v7(); }
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

void fn_8014017C(s32 arg0, void *arg1, void *arg2, s32 arg3) {
    struct Vec { s32 x, y, z; };
    void fn_80140830(s32, void *, void *, struct Vec, struct Vec, s32);
    extern struct Vec lbl_802922E4;
    extern struct Vec lbl_802922D8;
    struct Vec a;
    struct Vec b;
    a.x = lbl_802922E4.x; a.y = lbl_802922E4.y; a.z = lbl_802922E4.z;
    b.x = lbl_802922D8.x; b.y = lbl_802922D8.y; b.z = lbl_802922D8.z;
    fn_80140830(arg0, arg1, arg2, b, a, arg3);
}

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
extern f32 lbl_8036A730, lbl_8036A740;
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
s32 durationInt=self->get()->duration+1;
s32 timeInt=self->time+1;
f32 duration=durationInt;
f32 time=timeInt;
f32 t=Math_Ease(5,lbl_8036A740,lbl_8036A730,(lbl_8036A730/duration)*(duration-time),lbl_8036A730);
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

    u8 *obj;
    u8 *node;
    void *end;
    void *child;
    void *sp10;
    void *spC;
    void *sp8;
    s32 duration;
    s32 time;
    f32 f31;
    f32 f2;
    f32 f3;

    if (arg2 != 0) {
        obj = Process_CreateChild(lbl_80292298, arg0);
    } else {
        obj = Process_Create(lbl_80292298, arg0);
    }

    if (obj != NULL) {
        obj[0x30] = 0;
        fn_80142060(obj + 0x34);
    }

    sp10 = arg1;

    if (arg1 != NULL) {
        end = fn_80140B04(obj + 0x34);
        node = (u8 *)fn_80140B04(obj + 0x34);
        node = *(u8 **)(node + 4);

        while (node != (u8 *)end) {
            if (*(void **)(node + 8) == arg1) {
                break;
            }
            node = *(u8 **)(node + 4);
        }

        if (node == obj + 0x38) {
            spC = obj + 0x38;

            List_Insert(
                &sp8,
                obj + 0x34,
                &spC,
                &sp10
            );
        }
    }

    if (sp10 != NULL) {
        *(u32 *)((u8 *)sp10 + 4) =
            *(u32 *)((u8 *)sp10 + 4) + 1;
    }

    *(s16 *)(obj + 0x28) =
        *(s16 *)((u8 *)arg1 + 0x24);

    *(s32 *)(obj + 0x40) = arg3;

    if (*(u32 *)(obj + 0x34) != 0) {
        child = *(void **)(*(u8 **)(obj + 0x38) + 8);
    } else {
        child = NULL;
    }

    duration = (s32)*(s16 *)((u8 *)child + 0x24) + 1;
    time = (s32)*(s16 *)(obj + 0x28) + 1;

    f3 = (f32)duration;
    f2 = (f32)time;

    switch (arg3) {
    case 0:
        f31 = (lbl_8036A730 / f3) * (f3 - f2);
        break;

    case 1:
        f31 = (lbl_8036A730 / f3) * f2;
        break;
    }

    if (*(u32 *)(obj + 0x34) != 0) {
        child = *(void **)(*(u8 **)(obj + 0x38) + 8);
    } else {
        child = NULL;
    }

    *(f32 *)((u8 *)child + 0x2C) = f31;

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
Point operator-(const Point &p) const { struct Point q=*this; q.x-=p.x; q.y-=p.y; return q; }
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

void fn_80141970(void *arg0, s32 arg1) {
    f32 Math_Ease(s32, s32, f32, f32, f32, f32);
    extern f32 lbl_8036A730;
    extern f64 lbl_8036A738;
    extern f32 lbl_8036A740;
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r5;
    f32 temp_f0;
    f32 temp_f1;
    f32 var_f31;
    void *var_r3;
    void *var_r3_2;
    void *var_r3_3;
    void *var_r3_4;
    (void)lbl_8036A738;
    var_f31 = 1.0f;
    temp_r0 = *(s32 *)((char *)arg0 + 0x40);
    temp_r5 = *(s16 *)((char *)arg0 + 0x28) + 1;
    switch (temp_r0) {
    case 0:
        if (*(u32 *)((char *)arg0 + 0x34) != 0) {
            var_r3 = *(void **)((char *)arg0 + 0x38);
            var_r3 = *(void **)((char *)var_r3 + 0x8);
        } else {
            var_r3 = NULL;
        }
        temp_r4 = *(s16 *)((char *)var_r3 + 0x24) + 1;
        temp_f0 = (f32)(temp_r4 - temp_r5);
        temp_f1 = (f32)temp_r4;
        var_f31 = (lbl_8036A730 / temp_f1) * temp_f0;
        break;
    case 1:
        if (*(u32 *)((char *)arg0 + 0x34) != 0) {
            var_r3_2 = *(void **)((char *)arg0 + 0x38);
            var_r3_2 = *(void **)((char *)var_r3_2 + 0x8);
        } else {
            var_r3_2 = NULL;
        }
        temp_r4 = *(s16 *)((char *)var_r3_2 + 0x24) + 1;
        temp_r4 ^= 0x80000000;
        temp_f0 = (f32)temp_r5;
        temp_f1 = (f32)temp_r4;
        var_f31 = (var_f31 / temp_f1) * temp_f0;
        break;
    }
    temp_f1 = Math_Ease(5, temp_r4, lbl_8036A740, lbl_8036A730, var_f31, lbl_8036A730);
    if (*(u8 *)((char *)arg0 + 0x44) == 0) {
        var_f31 = lbl_8036A730;
    }
    if (*(u32 *)((char *)arg0 + 0x34) != 0) {
        var_r3_3 = *(void **)((char *)arg0 + 0x38);
        var_r3_3 = *(void **)((char *)var_r3_3 + 0x8);
    } else {
        var_r3_3 = NULL;
    }
    *(f32 *)((char *)var_r3_3 + 0x2c) = var_f31;
    if (*(u32 *)((char *)arg0 + 0x34) != 0) {
        var_r3_4 = *(void **)((char *)arg0 + 0x38);
        var_r3_4 = *(void **)((char *)var_r3_4 + 0x8);
    } else {
        var_r3_4 = NULL;
    }
    *(f32 *)((char *)var_r3_4 + 0x28) = temp_f1;
}

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
key=(u32)arg1;
if(arg1!=0) {
end=fn_80140B04((u8 *)self+0x34);
node=fn_80140B04((u8 *)self+0x34);
node=*(void **)((u8 *)node+4);
goto check;
for(;;) {
node=*(void **)((u8 *)node+4);
check:
if(node!=end) {
if(*(void **)((u8 *)node+8)!=(void *)key) continue;
}
break;
}
pos=(u8 *)self+0x38;
if(node==pos) {
List_Insert(&ret,(u8 *)self+0x34,&pos,&key);
if(key!=0) {
*(s32 *)((u8 *)key+4)+=1;
}
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
    f32 Math_Ease(M2C_UNK, f32, f32, f32, f32);
    extern f32 lbl_8036A75C;
    f32 temp_f1;
    s16 temp_r28;
    s16 temp_r31;
    s16 temp_r4_2;
    void *var_r30;
    s16 var_r29;
    s32 temp_r0;
    u32 temp_r4;
    void *var_r3;
    void *var_r4;
    void *var_r4_2;
    void *var_r6;
    temp_r4 = M2C_FIELD(arg0, u32 *, 0x34);
    if (temp_r4 != 0U) {
        var_r30 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), void **, 8);
    } else {
        var_r30 = NULL;
    }
    if (temp_r4 != 0U) {
        var_r3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), void **, 8);
    } else {
        var_r3 = NULL;
    }
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x48);
    var_r6 = NULL;
    temp_r31 = M2C_FIELD(var_r3, s16 *, 0x24);
    var_r29 = 0;
    switch (temp_r0) {
    case 0:
        if (temp_r4 != 0U) {
            var_r6 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), void **, 8);
        }
        var_r6 = (void *) (s16) (M2C_FIELD(var_r6, s16 *, 0x16) - M2C_FIELD(var_r6, s16 *, 0x12));
        break;
    case 1:
        if (temp_r4 != 0U) {
            var_r6 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), void **, 8);
        }
        var_r6 = (void *) -(s16) (M2C_FIELD(var_r6, s16 *, 0x16) - M2C_FIELD(var_r6, s16 *, 0x12));
        break;
    case 2:
        if (temp_r4 != 0U) {
            var_r4 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), void **, 8);
        } else {
            var_r4 = NULL;
        }
        var_r29 = M2C_FIELD(var_r4, s16 *, 0x18) - M2C_FIELD(var_r4, s16 *, 0x14);
        break;
    case 3:
        if (temp_r4 != 0U) {
            var_r4_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), void **, 8);
        } else {
            var_r4_2 = NULL;
        }
        var_r29 = -(s16) (M2C_FIELD(var_r4_2, s16 *, 0x18) - M2C_FIELD(var_r4_2, s16 *, 0x14));
        break;
    }
    temp_r4_2 = M2C_FIELD(arg0, s16 *, 0x40);
    if (temp_r4_2 >= temp_r31) {
        Process_ClearFunc(arg0);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x40) = (s16) (temp_r4_2 + 1);
    temp_r28 = (s16) Math_Ease(5, (f32) (s16) var_r6, lbl_8036A75C, (f32) M2C_FIELD(arg0, s16 *, 0x40), (f32) temp_r31);
    temp_f1 = Math_Ease(5, (f32) var_r29, lbl_8036A75C, (f32) M2C_FIELD(arg0, s16 *, 0x40), (f32) temp_r31);
    M2C_FIELD(var_r30, s16 *, 0x8C) = temp_r28;
    M2C_FIELD(var_r30, s16 *, 0x8E) = (s16) temp_f1;
}

void fn_801422C0(void *arg0)
{
    extern u8 gUnitInfoPopup[];
    extern f64 lbl_8036A750;

    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoPopup(void *, void *, f32, f32);
    void Ui_HideUnitInfoPopup(void *);

    u8 *self;
    u8 *child;
    u8 *selected;
    u8 *entry;
    u8 *node;
    s32 index;
    s16 count;
    s32 offset;
    s32 pos[2];
    s16 x;
    s16 y;

    self = (u8 *)arg0;

    *(s16 *)(self + 0x40) = 0;

    if (*(void **)(self + 0x34) != 0) {
        child = *(u8 **)(*(u8 **)(self + 0x38) + 8);
    } else {
        child = 0;
    }

    ((void (*)(void *, void *))
        (*(void ***)((u8 *)child))[11])(
            child,
            *(void **)(self + 0x44)
        );

    if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
        if (*(void **)(self + 0x34) != 0) {
            child = *(u8 **)(*(u8 **)(self + 0x38) + 8);
        } else {
            child = 0;
        }

        index = ((s32 (*)(void *))
            (*(void ***)child)[12])(child);

        offset = index * 12;
        entry = child + 0x90 + offset;

        if (*(void **)entry == 0) {
            selected = 0;
        } else {
            count = *(s16 *)(child + 0x64 + index * 2);
            node = *(u8 **)(entry + 8);

            if (count >= 0) {
                while (count > 0) {
                    node = *(u8 **)(node + 4);
                    count--;
                }
            } else {
                while (count < 0) {
                    node = *(u8 **)node;
                    count++;
                }
            }

            selected = node + 8;
        }

        if (selected != 0) {
            if (*(void **)(self + 0x34) != 0) {
                child = *(u8 **)(*(u8 **)(self + 0x38) + 8);
            } else {
                child = 0;
            }

            ((void (*)(void *, void *))
                (*(void ***)child)[15])(child, pos);

            *(u32 *)((u8 *)pos + 4) = *(u32 *)pos;

            x = *(s16 *)((u8 *)pos + 4);
            y = *(s16 *)((u8 *)pos + 6);

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

void fn_8014246C(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    extern f32 lbl_8036A75C;
    s16 temp_r31;
    void *var_r30;
    s16 var_r29;
    s16 temp_r28;
    f32 temp_f1;
    s16 temp_r4_2;
    s32 temp_r0;
    u32 temp_r4;
    void *var_r3;
    void *var_r4;
    void *var_r6;

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
    var_r29 = (s16)(s32)var_r6;
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
    if (temp_r4_2 >= temp_r31) {
        Process_ClearFunc(arg0);
        return;
    }
    *(s16 *)((u8 *)arg0 + 0x40) = (s16)(temp_r4_2 + 1);
    temp_r28 = (s16)Math_Ease(2, lbl_8036A75C, (f32)(s16)(s32)var_r6, (f32)*(s16 *)((u8 *)arg0 + 0x40), (f32)temp_r31);
    temp_f1 = Math_Ease(2, lbl_8036A75C, (f32)var_r29, (f32)*(s16 *)((u8 *)arg0 + 0x40), (f32)temp_r31);
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
extern "C" void fn_801429E0(void *arg0) {
extern u32 gUiInputFlags;
extern u32 *gPadInput;
extern u8 lbl_80276B3C[];
extern f32 lbl_8036A764, lbl_8036A768;
void Ui_PlaySeCue(void *,s32);
void fn_8013ED84(void *,s16);
u8 *self=(u8 *)arg0;
s32 index;
u8 *page;
s32 repeat,edge,held;
s16 old;
s16 count;
u32 visible;
u8 blocked;
index=((UiPageSelector *)arg0)->page();
page=self+index*2;
count=*(s32 *)(self+0x90+index*12);
if(count==0) {
*(s16 *)(page+0x4e)=0;
*(s16 *)(page+0x64)=0;
return;
}
visible=*(u16 *)(self+0x80);
blocked=(gUiInputFlags&0x10)!=0 && (gUiInputFlags&0x20)==0;
if(!blocked) {
old=*(s16 *)(page+0x64);
held=gPadInput[1];
edge=gPadInput[2]^held;
repeat=gPadInput[3];
edge=held&edge;
if((s16)*(f32 *)(self+0x84)==0) {
if(repeat&0x08000008) {
if((s16)old==0) {
if(repeat==edge) {
*(s16 *)(page+0x64)=count-1;
*(s16 *)(page+0x4e)=count>(s16)visible?count-(s16)visible:0;
}
} else {
*(s16 *)(page+0x64)=old-1;
if((s16)*(s16 *)(page+0x64)>0 && *(s16 *)(page+0x64)-*(s16 *)(page+0x4e)==0) {
*(s16 *)(page+0x4e)-=1;
*(f32 *)(self+0x84)=-32.0f;
}
}
if(old!=*(s16 *)(page+0x64)) Ui_PlaySeCue(lbl_80276B3C+0x1d,100);
} else if(repeat&0x04000004) {
s32 last=count-1;
if(old==last) {
if(repeat==edge) {
*(s16 *)(page+0x64)=0;
*(s16 *)(page+0x4e)=0;
}
} else {
*(s16 *)(page+0x64)=old+1;
if(*(s16 *)(page+0x64)<last && *(s16 *)(page+0x64)-*(s16 *)(page+0x4e)==(s16)visible-1) {
*(s16 *)(page+0x4e)+=1;
*(f32 *)(self+0x84)=32.0f;
}
}
if(old!=*(s16 *)(page+0x64)) Ui_PlaySeCue(lbl_80276B3C+0x1d,100);
}
}
}
fn_8013ED84(*(void **)(self+0x48),(s16)((*(s16 *)(page+0x4e)<<5)-(s32)*(f32 *)(self+0x84)));
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
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    s32 Text_MeasureHeight(s32, f32);
    void Ui_DrawRouteIconEx(s16, s32, u8);
    void Prim2D_SetAlphaByte(s32);
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
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A76C);
        Prim2D_PrepareTex();
        Ui_DrawRouteIconEx(*(s16 *)((u8 *)self + 0x7C),
                    *(s16 *)((u8 *)self + 0x7E) + (s16)((0x20 - Text_MeasureHeight(-1, lbl_8036A758)) >> 1),
                    r30);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A758);
        Prim2D_PrepareTex();
        ((Obj *)self)->v16(0, t27,
            (s16)(*(s16 *)((u8 *)self + 0x16) - *(s16 *)((u8 *)self + 0x12)),
            0x20, r30);
    }
    if (val != 0 && *(u8 *)((u8 *)self + 0x4D) != 0) {
        ((Obj *)self)->v3(other);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A770);
        Prim2D_PrepareTex();
        {
            s16 a = *(s16 *)(slot + 0x4E);
            s16 b = *(s16 *)((u8 *)self + 0x7A);
            s16 c = *(s16 *)((u8 *)self + 0x8A);
            t25 = (s16)(((s16)(b - a) << 5) + c);
        }
        t26 = (s16)((0x20 - Text_MeasureHeight(-1, lbl_8036A758)) >> 1);
        Prim2D_Begin();
        Prim2D_SetAlphaByte(0x40);
        Prim2D_PrepareTex();
        Ui_DrawRouteIconEx((s16)t31, t25 + t26, 0);
    }
    Prim2D_Begin();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
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
extern f32 lbl_8036A770,lbl_8036A75C,lbl_8036A760,lbl_8036A758,lbl_8036A748;
extern f32 lbl_80367098[];
extern u8 lbl_80276B3C[];
extern void (Menu42::*lbl_802922FC)(s32);
Menu42Callback cb;
s16 rows, scroll, sign, x, y;
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
if (sign > 0 && index > 0) --index;
node = *(u8 **)(table + 8);
{
s16 n = index;
if (index >= 0) { while (n > 0) { node = *(u8 **)(node + 4); --n; } }
else { while (n < 0) { node = *(u8 **)(node + 0); ++n; } }
}
y = M2C_FIELD(self, s16 *, 0x8e) + M2C_FIELD(self, s16 *, 0x8a) + 4;
x = M2C_FIELD(self, s16 *, 0x8c) + M2C_FIELD(self, s16 *, 0x88);
{
s16 row = (-sign & ~sign) >> 31;
s16 end = rows;
if (sign < 0) ++end;
{
s32 ypos = y + (row << 5);
s32 remaining = count - index;
for (; row < end; ++row, ypos += 32) {
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
if (*(u32 *)table == 0) selected = 0;
else {
node = *(u8 **)(table + 8);
{
s16 n = *(s16 *)((u8 *)self + page * 2 + 0x64);
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

void fn_80143570(void *arg0) {
    void fn_80144B60(void *, u8);
    s32 off;
    u8 e;
    s32 i;

    off = 0;
    for (i = 0; i != 11; i++) {
        fn_80144B60((u8 *)arg0 + (off + 0x90), e);
        off += 0xC;
    }
}

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
        S(u8 flag, u32 value) : f(flag), v(value) {}
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
    S a(flag, arg1);
    table = (s32)self + idx * 0xC + 0x90;
    sentinel = (struct Node *)(table + 4);
    head = *(struct Node **)(table + 8);
    S b = a;
    node = head;
    while (node != sentinel && node->key != b.v) {
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
extern "C" void fn_801436AC(void *arg0, void *arg1) {
    void fn_80144E34(ListIter *, List *, ListIter *);
    struct Pair {
        u8 f;
        u32 v;
    };
    Unk1 unk;
    ListIter ret;
    ListIter it;
    ListIter dummy;
    u8 *cursor = (u8 *)arg0;
    for (s32 i = 0; i < 11; cursor += 12, i++) {
        Pair a;
        Pair b;
        a.f = unk.unk0;
        a.v = (u32)arg1;
        *(u32 *)&b = *(u32 *)&a;
        b.v = a.v;
        List *list = (List *)(cursor + 0x90);
        ListNode *sentinel = (ListNode *)((u8 *)list + 4);
        ListNode *node = *(ListNode **)(cursor + 0x98);
        goto check;
        for (;;) {
            node = node->next;
        check:
            if (node == sentinel)
                break;
            if (node->val != (void *)arg1)
                continue;
            if (node != (ListNode *)(cursor + 0x94)) {
                it.node = node;
                fn_80144E34(&ret, list, &it);
                if ((u32)*(s16 *)((u8 *)arg0 + (i << 1) + 0x64) >= (u32)list->size)
                    *(s16 *)((u8 *)arg0 + (i << 1) + 0x64) = list->size - 1;
            }
            return;
        }
        dummy.node = 0;
    }
}
#pragma cplusplus on
extern "C" void fn_80143784(void *arg0, void *arg1) {
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
        virtual s32 v12(void *) = 0;
    };
    struct PNode {
        PNode *prev;
        PNode *next;
        void *key;
        void *owner;
    };
    struct Pair {
        u8 f;
        u32 v;
    };
    extern u32 lbl_8036C4E8;
    extern u32 lbl_8036C4EC;
    void *Unit_GetHeldItemSlot(void *, s32);
    void fn_80144E34(ListIter *, List *, ListIter *);
    void fn_80144EAC(void *, void *, void *, void *);
    void memcpy(void *, void *, u32);

    u8 saved[0x16];
    ListIter ret;
    ListIter it;
    u32 pair1[2];
    u32 pair2[2];
    void *entry1;
    void *entry2;
    u32 result1;
    u32 result2;
    u8 flag;
    Pair pa;
    Pair pb;
    s32 j;
    List *lst;
    s32 oi;
    void *self;
    void *unit;
    u8 *p;
    PNode *sent;
    PNode *node;

    memcpy(saved, (u8 *)arg0 + 0x64, 0x16);
    self = arg0;
    unit = arg1;

    for (oi = 0, p = (u8 *)self; oi < 11; p += 0xc, oi++) {
        node = *(PNode **)(p + 0x98);
        sent = (PNode *)(p + 0x94);
        goto ocheck;
        for (;;) {
            if (node->owner == unit) {
                u8 *c2;
                PNode *n;
                PNode *s;
                void *key;
                key = node->key;
                pa.f = flag;
                pa.v = (u32)key;
                pb.f = pa.f;
                pb.v = pa.v;
                j = 0;
                c2 = (u8 *)self;
                for (; j < 11; c2 += 0xc, j++) {
                    lst = (List *)(c2 + 0x90);
                    n = *(PNode **)(c2 + 0x98);
                    s = (PNode *)((u8 *)lst + 4);
                    goto scheck;
                    for (;;) {
                        n = n->next;
                    scheck:
                        if (n == s)
                            break;
                        if (n->key != (void *)pb.v)
                            continue;
                        if (n != (PNode *)((u8 *)lst + 4)) {
                            it.node = (ListNode *)n;
                            fn_80144E34(&ret, lst, &it);
                            if ((u32)*(s16 *)((u8 *)self + (j << 1) + 0x64) >= (u32)lst->size)
                                *(s16 *)((u8 *)self + (j << 1) + 0x64) = lst->size - 1;
                        }
                        goto onext;
                    }
                }
            }
        onext:
            node = node->next;
        ocheck:
            if (node == sent)
                break;
        }
    }

    {
        s32 hi;
        void *slot;
        s32 index;
        for (hi = 0; hi < 4; hi++) {
            slot = Unit_GetHeldItemSlot(unit, hi);
            if (*(u32 *)slot == 0)
                continue;
            index = ((Obj *)self)->v12(slot);
            if (index == 0xc)
                continue;
            pair1[0] = lbl_8036C4E8;
            pair1[1] = lbl_8036C4EC;
            lst = (List *)((u8 *)self + index * 0xc + 0x90);
            pair1[0] = (u32)slot;
            pair1[1] = (u32)unit;
            entry1 = (u8 *)lst + 4;
            fn_80144EAC(&result1, lst, &entry1, pair1);
        }
    }

    {
        s32 ei;
        void *itemp;
        s32 index;
        for (ei = 0, p = (u8 *)unit; ei < 4; p += 8, ei++) {
            itemp = p + 0x1ec;
            if (*(u32 *)(p + 0x1ec) == 0)
                continue;
            index = ((Obj *)self)->v12(itemp);
            if (index == 0xc)
                continue;
            pair2[0] = lbl_8036C4E8;
            pair2[1] = lbl_8036C4EC;
            lst = (List *)((u8 *)self + index * 0xc + 0x90);
            pair2[0] = (u32)itemp;
            pair2[1] = (u32)unit;
            entry2 = (u8 *)lst + 4;
            fn_80144EAC(&result2, lst, &entry2, pair2);
        }
    }

    memcpy((u8 *)arg0 + 0x64, saved, 0x16);

    {
        u8 *a = (u8 *)self;
        u8 *b = (u8 *)self;
        for (oi = 0; oi < 11; oi++) {
            if ((u32)*(s16 *)(b + 0x64) >= (u32)*(s32 *)(a + 0x90))
                *(s16 *)(b + 0x64) = *(s32 *)(a + 0x90) - 1;
            a += 0xc;
            b += 2;
        }
    }
}
#pragma cplusplus reset
extern "C" void fn_801439F0(void *arg0, s32 arg1, s32 arg2) {
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
virtual void v11() = 0; virtual s32 v12()=0; };
 extern u32 lbl_8036C4E8; extern u32 lbl_8036C4EC;
 void fn_80144EAC(void *,void *,void *,void *);
 u32 pair[2]; void *entry; u32 result; s32 index; void *base;
 index=((Obj *)arg0)->v12();
 if(index!=12) {
 
 pair[0]=lbl_8036C4E8; pair[1]=lbl_8036C4EC;
 index*=12;
 base=(u8 *)arg0+index+0x90;
 pair[0]=arg1; pair[1]=arg2; entry=(u8 *)base+4;
 fn_80144EAC(&result,base,&entry,pair);
 }
}
#pragma cplusplus on
extern "C" void *ListWidget_GetSelected(void *arg0) {
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
        virtual s32 v10() = 0;
    };
    struct Node {
        struct Node *prev;
        struct Node *next;
    };
    s32 index;
    s32 off;
    u8 *record;
    s32 tmp;
    s16 n;
    Node *node;

    index = ((Obj *)arg0)->v10();
    off = (index << 1) + 0x64;
    record = (u8 *)arg0 + index * 0xC + 0x90;
    if (*(u32 *)record == 0) {
        return NULL;
    }
    tmp = *(s16 *)((u8 *)arg0 + off);
    node = *(Node **)(record + 8);
    n = (s16)tmp;
    if (n >= 0) {
        goto loop_pos;
        do {
            node = node->next;
            n -= 1;
        loop_pos:
            ;
        } while (n > 0);
    } else {
        goto loop_neg;
        do {
            node = node->prev;
            n += 1;
        loop_neg:
            ;
        } while (n < 0);
    }
    return (u8 *)node + 8;
}
#pragma cplusplus on
extern "C" void fn_80143B24(void *arg0) {
    void *memset(void *, int, unsigned long);
    struct Slot {
        u8 pad[0xC];
        void clear();
    };
    typedef void (Slot::*PTMF)();
    extern PTMF lbl_802922F0;
    PTMF meth[2];
    Slot *it;
    u8 *p;

    p = (u8 *)arg0;
    memset(p + 0x4E, 0, 0x16);
    memset(p + 0x64, 0, 0x16);
    meth[1] = lbl_802922F0;
    meth[0] = meth[1];
    it = (Slot *)(p + 0x90);
    p += 0x114;
    while (it != (Slot *)p) {
        (it->*meth[0])();
        it++;
    }
}
#pragma cplusplus reset
extern "C" void fn_80143BC8(s32 *arg0, void *arg1) {
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
        virtual s32 v10() = 0;
    };
    struct Point {
        s16 x;
        s16 y;
    };
    struct Point *fn_8013F748(void *, struct Point *, struct Point *);
    struct Point out;
    struct Point in;
    s32 idx;
    u8 *slot;
    s16 x88;
    s16 c;
    s16 a;
    s16 b;

    idx = ((Obj *)arg1)->v10();
    slot = (u8 *)arg1 + (idx << 1);
    x88 = *(s16 *)((u8 *)arg1 + 0x88);
    c = *(s16 *)((u8 *)arg1 + 0x8A);
    a = *(s16 *)(slot + 0x4E);
    b = *(s16 *)(slot + 0x64);
    in.x = x88;
    in.y = (s16)(((s16)(b - a) << 5) + c);
    *arg0 = *(s32 *)fn_8013F748(arg1, &out, &in);
}
extern "C" s16 fn_80143C58(void *arg0) {
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
        virtual u16 v10() = 0;
    };
    typedef struct {
        u8 pad[0x64];
        s16 unk64[1];
    } Unk80143C58;
    Unk80143C58 *obj = (Unk80143C58 *)arg0;

    return obj->unk64[((Obj *)arg0)->v10()];
}

extern "C" void fn_80143C9C(void *unit) {
#pragma cplusplus on
struct Panel {
virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0;
virtual void v8()=0; virtual void v9()=0; virtual s32 page()=0;
};
s16 arg1;
u8 *p;
u8 *initial;
s16 visible;
u32 count;
initial=(u8 *)unit+((Panel *)unit)->page()*2;
arg1=*(s16 *)(initial+0x64);
if(arg1 > *(u32 *)((u8 *)unit+((Panel *)unit)->page()*12+0x90)-1) {
arg1=*(u32 *)((u8 *)unit+((Panel *)unit)->page()*12+0x90)-1;
}
if(arg1<0) arg1=0;
p=(u8 *)unit+((Panel *)unit)->page()*2;
count=*(u32 *)((u8 *)unit+((Panel *)unit)->page()*12+0x90);
visible=*(s16 *)((u8 *)unit+0x80);
if(count<=visible) {
*(s16 *)(p+0x64)=arg1;
*(s16 *)(p+0x4E)=0;
} else if(count-arg1<visible) {
*(s16 *)(p+0x64)=arg1;
*(s16 *)(p+0x4E)=(int)count-visible;
} else if(*(s16 *)(p+0x4E)<arg1 && arg1-*(s16 *)(p+0x4E)<visible-1) {
*(s16 *)(p+0x64)=arg1;
} else if(arg1==0) {
*(s16 *)(p+0x4E)=arg1;
*(s16 *)(p+0x64)=arg1;
} else {
*(s16 *)(p+0x64)=arg1;
*(s16 *)(p+0x4E)=arg1-1;
}
#pragma cplusplus reset
}

#pragma cplusplus reset
extern "C" void fn_80143E0C(void *unit, s16 arg1) {
#pragma cplusplus on
struct Panel {
virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0;
virtual void v8()=0; virtual void v9()=0; virtual s32 page()=0;
u32 size(){ return *(u32 *)((u8 *)this+page()*12+0x90); }
};
u8 *p;
s16 visible;
u32 count;
if((u32)arg1 > ((Panel *)unit)->size()-1) {
arg1=((Panel *)unit)->size()-1;
}
if(arg1<0) arg1=0;
p=(u8 *)unit+((Panel *)unit)->page()*2;
count=((Panel *)unit)->size();
visible=*(s16 *)((u8 *)unit+0x80);
if(count<=(u32)visible) {
*(s16 *)(p+0x64)=arg1;
*(s16 *)(p+0x4E)=0;
} else if(count-arg1<(u32)visible) {
*(s16 *)(p+0x64)=arg1;
*(s16 *)(p+0x4E)=count-visible;
} else if(*(s16 *)(p+0x4E)<arg1 && arg1-*(s16 *)(p+0x4E)<visible-1) {
*(s16 *)(p+0x64)=arg1;
} else if(arg1==0) {
*(s16 *)(p+0x4E)=arg1;
*(s16 *)(p+0x64)=arg1;
} else {
*(s16 *)(p+0x64)=arg1;
*(s16 *)(p+0x4E)=arg1-1;
}
#pragma cplusplus reset
}

#pragma cplusplus on
extern "C" void fn_80143F64(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *Process_CreateChild(void *, s32);
    void Ui_AddChild(void *, void *);
    void fn_801403F0(void);
    extern u8 lbl_80292320[];
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
    };
    void *temp;

    if (arg2 != ((Obj *)arg0)->v10()) {
        *(s16 *)((u8 *)arg0 + 0x24) = 6;
        temp = Process_CreateChild(lbl_80292320, arg1);
        if (temp != NULL) {
            fn_801403F0();
        }
        Ui_AddChild(temp, arg0);
        *(s32 *)((u8 *)temp + 0x44) = arg2;
        *(s32 *)((u8 *)temp + 0x48) = arg3;
    }
}
#pragma cplusplus off

#pragma cplusplus on
extern "C" void fn_80144000(void *arg0) {
    struct Obj {
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

#pragma cplusplus on
extern "C" void Ui_HandleWrappedCursorInput(void *panel, s32 animArg) {
    /* Move the panel cursor left/right with wraparound 0..10, play SE, and notify the child widget. */
    s32 Ui_PlaySeCue(u8 *, s32);
    extern u8 lbl_80276B3C[];
    extern s32 gUiInputFlags;
    extern void *gPadInput;
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
        virtual void v18(s32, s32, s32) = 0;
    };
    u8 skip = 0;
    s32 buttons;
    s32 cursor;
    s32 next;

    if ((gUiInputFlags & 0x10) != 0 && (gUiInputFlags & 0x20) == 0) {
        skip = 1;
    }
    if (skip != 0) {
        return;
    }
    cursor = *(s32 *)((u8 *)panel + 0x3C);
    buttons = *(s32 *)((u8 *)gPadInput + 0xC);
    if (buttons & 0x01000001) {
        next = cursor - 1;
        if (cursor == 0) {
            next = 0xA;
        }
        if (cursor != next) {
            *(s16 *)((u8 *)panel + 0x9E) = 1;
            *(u8 *)((u8 *)panel + 0x95) = 1;
            (*(Obj **)((u8 *)panel + 0x38))->v18(animArg, next, 1);
            Ui_PlaySeCue(lbl_80276B3C + 0x46, 0x64);
        }
    } else if (buttons & 0x02000002) {
        next = cursor + 1;
        if (cursor == 0xA) {
            next = 0;
        }
        if (cursor != next) {
            *(s16 *)((u8 *)panel + 0xC6) = 1;
            *(u8 *)((u8 *)panel + 0xBD) = 1;
            (*(Obj **)((u8 *)panel + 0x38))->v18(animArg, next, 0);
            Ui_PlaySeCue(lbl_80276B3C + 0x46, 0x64);
        }
    }
}
extern "C" void fn_8014413C(void *arg0) {
    struct Sub {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9(s32);
        u8 pad[0x24];
    };
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        u8 pad4[0x30];
        s32 unk34;
        u8 pad38[0x50];
        Sub sub88;
        Sub subB0;
    };
    Obj *self = (Obj *)arg0;
    self->v3();
    self->sub88.v9(self->unk34);
    self->subB0.v9(self->unk34);
}

extern "C" void Ui_DrawMenuSlots(void *arg0) {
    /* Update the menu, then draw its 11 slots; cursor item is white, others grey. */
    extern f32 lbl_8036A75C;
    typedef struct {
        u8 r, g, b, a;
    } Color;
    struct Drawer {
        u8 pad0[0x44];
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
        virtual void Draw(s32, s32, s32, Color *, s32, s32);
    };
    struct Menu {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void Update() = 0;
        u8 pad4[4];
        s16 left;
        s16 top;
        s16 right;
        s16 bottom;
        u8 pad10[0x24];
        s32 unk34;
        s32 unk38;
        s32 cursor;
        Drawer drawer;
    };
    Menu *self = (Menu *)arg0;
    Color white;
    Color grey;
    f32 y;
    f32 shade;
    f32 step;
    s32 i;

    self->Update();
    shade = 1.0f;
    y = lbl_8036A75C;
    step = (f32)(s16)(self->bottom - self->top) / 11.0f;
    white.r = 0xFF;
    white.g = 0xFF;
    white.b = 0xFF;
    white.a = 0xFF;
    grey.r = 0x30;
    grey.g = 0x30;
    grey.b = 0x30;
    grey.a = 0xFF;
    for (i = 0; i < 11; i++) {
        if (i == self->cursor) {
            self->drawer.Draw(y, lbl_8036A75C, 0, &white, self->unk34, i);
        } else {
            self->drawer.Draw(y, lbl_8036A75C, shade, &grey, self->unk34, i);
        }
        y += step;
        shade += 1.0f;
    }
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void fn_8014433C(void *arg0, s16 arg1, s16 arg2, s16 arg3, s32 *arg4, s32 arg5, s32 arg6) {
    void Prim2D_Begin(void);
    void fn_8000A03C(void *, void *, s32, u16);
    void Prim2D_SetTex(void *, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_EndPrim(void);
    extern s32 lbl_80276B10[];
    struct Obj {
        u8 pad[0x44];
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
        virtual void v13() = 0;
        virtual s32 v14() = 0;
        virtual s32 v15() = 0;
    };
    f32 f31;
    f32 f30;
    f32 f29;
    s32 sp8;
    s32 temp_r25;
    s32 temp_r26;
    void *obj;
    s16 var_r28;
    s16 var_r29;
    s16 var_r30;
    s32 *var_r31;

    obj = arg0;
    var_r28 = arg1;
    var_r29 = arg2;
    var_r30 = arg3;
    var_r31 = arg4;
    temp_r26 = arg5;
    temp_r25 = lbl_80276B10[arg6] - 1;
    Prim2D_Begin();
    if (*(u8 *)((u8 *)obj + 0x40) != 0) {
        fn_8000A03C((u8 *)obj + 4, (u8 *)obj + 0x24, 0, (u16)(temp_r26 | 1));
    } else {
        Prim2D_SetTex((u8 *)obj + 4, (u16)(temp_r26 | 1));
    }
    Prim2D_PrepareTex();
    temp_r26 = ((Obj *)obj)->v14();
    f30 = (f32)((temp_r25 % ((Obj *)obj)->v12()) * temp_r26);
    temp_r26 = ((Obj *)obj)->v15();
    f29 = (f32)((temp_r25 / ((Obj *)obj)->v12()) * temp_r26);
    Prim2D_AddPrim(1);
    f31 = (f32)((Obj *)obj)->v15();
    Prim2D_SetRectUv((f32)var_r28, (f32)var_r29, f30, f29, (f32)((Obj *)obj)->v14(), f31);
    Prim2D_SetPrimParam((f32)var_r30);
    sp8 = *var_r31;
    Prim2D_SetColorPacked(&sp8);
    Prim2D_EndPrim();
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus reset

void *fn_80144584(void *arg0, s16 arg1) {
    void fn_8013F2A4(void *, s32);
    void Array_Destroy(void *, void *, s32, s32);
    void Heap_Free(void *);
    void *fn_80144610(void *, s16);
    extern void *lbl_80292358[];
    extern void *lbl_80292488[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80292358;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292488;
            Array_Destroy((u8 *)arg0 + 0x90, (void *)fn_80144610, 0xC, 0xB);
            fn_8013F2A4(arg0, 0);
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_80144D84(ListIter *ret, List *list, ListIter *start, ListIter *end);

void *fn_80144610(void *arg0, s16 arg1) {
    void fn_80144D84(void *, void *, void *, void *);
    void Heap_Free(void *);
    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];

    if (arg0 != NULL) {
        if (arg0 != NULL) {
            if (arg0 != NULL) {
                sp10 = (ListNode *)((u8 *)arg0 + 4);
                spC = *(ListNode **)((u8 *)arg0 + 8);
                fn_80144D84(sp8, arg0, &spC, &sp10);
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_80144688(void) {

}

s32 fn_8014468C(void) {
    return 0;
}

void fn_80144694(void) {

}

#pragma cplusplus on
extern "C" void fn_80144698(void *arg0) {
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
    };
    ((Obj *)arg0)->v10();
}

#pragma cplusplus reset
extern void fn_801446C4(void *arg0);
void fn_801446C4(void *arg0) {
    void *Heap_Alloc(s32);
    void *fn_8013692C(void *, s32, s32, s32, s32, s32);
    void fn_8013F0F0(void *, void *);
    void fn_8013F1A0(void *, void *);
    void *child;
    s16 t;
    s16 s;
    s16 r8;
    s16 r7;
    s16 r6;
    s16 r5;

    t = 3;
    s = 6;
    r8 = *(s16 *)((u8 *)arg0 + 0xc);
    r7 = *(s16 *)((u8 *)arg0 + 0x10);
    r6 = *(s16 *)((u8 *)arg0 + 0xa);
    r5 = *(s16 *)((u8 *)arg0 + 0xe);
    r7 = (s16)(r7 - r8);
    *(s16 *)((u8 *)arg0 + 0x12) = t;
    t = (s16)(r5 - r6);
    r5 = r7 - 6;
    *(s16 *)((u8 *)arg0 + 0x14) = s;
    t = t - 3;
    *(s16 *)((u8 *)arg0 + 0x16) = t;
    *(s16 *)((u8 *)arg0 + 0x18) = r5;
    if (*(void **)((u8 *)arg0 + 0x48)) {
        fn_8013F0F0(arg0, *(void **)((u8 *)arg0 + 0x48));
    }
    child = Heap_Alloc(0x9c);
    if (child) {
        child = fn_8013692C(
            child,
            (s16)(*(s16 *)((u8 *)arg0 + 0x16) - *(s16 *)((u8 *)arg0 + 0x12)) - 12,
            0,
            9,
            (s16)(*(s16 *)((u8 *)arg0 + 0x18) - *(s16 *)((u8 *)arg0 + 0x14)),
            *(s16 *)((u8 *)arg0 + 0x22) - 5);
    }
    *(void **)((u8 *)arg0 + 0x48) = child;
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 0x48) = 1;
    fn_8013F1A0(arg0, *(void **)((u8 *)arg0 + 0x48));
}

void fn_801447A4(void *arg0, s32 arg1) {
    extern s32 lbl_80367AE0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x128), s32 *, 0x3C) = arg1;
    lbl_80367AE0 = arg1;
}

void *fn_801447B4(void *arg0, s16 arg1) {
    void fn_8013F2A4(void *, s32);
    void Array_Destroy(void *, void *, s32, s32);
    void Heap_Free(void *);
    void *fn_80144610(void *, s16);
    extern void *lbl_802923E0[];
    extern void *lbl_80292434[];
    extern void *lbl_80292488[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_802923E0;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292434;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_80292488;
                Array_Destroy((u8 *)arg0 + 0x90, (void *)fn_80144610, 0xC, 0xB);
                fn_8013F2A4(arg0, 0);
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

s32 fn_80144850(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x128), s32 *, 0x3C);
}

#pragma cplusplus on
extern "C" void fn_8014485C(void *arg0) {
    extern s32 lbl_80367AE0;
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
        virtual void v9(s32) = 0;
    };
    ((Obj *)arg0)->v9(lbl_80367AE0);
}
#pragma cplusplus reset
void *fn_8014488C(void *arg0, s16 arg1) {
    void fn_8013F2A4(void *, s32);
    void Array_Destroy(void *, void *, s32, s32);
    void Heap_Free(void *);
    void *fn_80144610(void *, s16);
    extern void *lbl_80292434[];
    extern void *lbl_80292488[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80292434;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292488;
            Array_Destroy((u8 *)arg0 + 0x90, (void *)fn_80144610, 0xC, 0xB);
            fn_8013F2A4(arg0, 0);
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma cplusplus on
extern "C" void *Ui_DtorPanelC(void *self, s16 doFree) {
    /* C++ destructor for UI panel C (gUiPanelCVtbl): destroy embeds, chain base vtors, optional free. */
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    struct Sub40 {
        u8 pad[0x44];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    struct Owner {
        void *vtbl;
        u8 pad4[0x3C];
        u8 sub40[0x48];
        void *sub88;
        u8 pad8c[0x24];
        void *subB0;
    };
    void Heap_Free(void *);
    extern u8 gUiPanelCVtbl[];
    extern u8 gEmptyVtbl[];
    extern u8 gUiPanelCMidVtbl[];
    extern u8 lbl_80292230[];
    extern u8 lbl_8028FDB0[];
    Owner *owner;

    owner = (Owner *)self;
    if (self != NULL) {
        owner->vtbl = gUiPanelCVtbl;
        if (&owner->subB0 != NULL) {
            owner->subB0 = gEmptyVtbl;
            ((Obj *)&owner->subB0)->v2();
        }
        if (&owner->sub88 != NULL) {
            owner->sub88 = gEmptyVtbl;
            ((Obj *)&owner->sub88)->v2();
        }
        if (&owner->sub40[0] != NULL) {
            *(void **)((u8 *)owner + 0x84) = gUiPanelCMidVtbl;
            ((Sub40 *)&owner->sub40[0])->v2();
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
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void *fn_80144A0C(void *arg0, s16 arg1) {
    struct Obj {
        u8 pad[0x44];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    extern u8 gUiPanelCMidVtbl[];
    extern void Heap_Free(void *);
    if (arg0 != NULL) {
        *(void **)((u8 *)arg0 + 0x44) = gUiPanelCMidVtbl;
        ((Obj *)arg0)->v2();
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80144A74(void *arg0) {
    void fn_80144B1C(void *, void *);
    void fn_80144B5C(void *, void *);
    void fn_80144B38(void *, void *, s32);
    void *fn_80144D74(void *);
    s32 *fn_80144D7C(void *);
    void *fn_80144D80(void *);
    struct Node {
        struct Node *prev;
        struct Node *next;
    };
    Node *tmp;
    void *sentinel;
    Node *node;
    s32 *count;

    sentinel = (u8 *)arg0 + 4;
    node = *(Node **)((u8 *)arg0 + 8);
    if (node != (Node *)sentinel) {
        fn_80144B1C(node, *(void **)sentinel);
        while (node != (Node *)sentinel) {
            fn_80144B5C(fn_80144D80(arg0), (u8 *)node + 8);
            tmp = node;
            node = node->next;
            fn_80144B38(fn_80144D74(arg0), tmp, 1);
            count = fn_80144D7C(arg0);
            *count -= 1;
        }
    }
}

#pragma cplusplus off
void fn_80144B1C(void **arg0, void *arg1) {
    M2C_FIELD(*arg0, void ***, 4) = (void **) M2C_FIELD(arg1, void ***, 4);
    *M2C_FIELD(arg1, void ***, 4) = *arg0;
}

void fn_80144B38(void *arg0, void *arg1) {
    void Heap_Free(void *);
    Heap_Free(arg1);
}

void fn_80144B5C(void) {

}

void fn_80144B60(s32 *arg0, u8 *arg1) {
    typedef struct {
        u8 pad[0xe];
        u16 key;
    } KeyObj;
    typedef struct {
        KeyObj *obj;
        u8 unk4;
    } Entry;
    typedef struct Node {
        struct Node *prev;
        struct Node *next;
        Entry *val;
    } Node;
    typedef struct {
        s32 count;
        Node *prev;
        Node *next;
    } SortList;

    void fn_8014510C(void *);
    void fn_80144F78(s32 *, s32 *, u8 *);
    void Heap_Free(void *);

    SortList other;
    struct { u8 value; } sp10, spC, sp8;
    void **p;
    void *tmp;
    void *tmp2;
    Entry *a;
    Entry *b;
    Node *first;
    Node *second;
    Node *node;
    Node *last;
    Node *sentinel;
    s32 temp_r0;
    u32 half;
    u32 n;
    u8 less;
    u8 key;

    temp_r0 = arg0[0];
    switch (temp_r0) {
    case 0:
    case 1:
        break;
    case 2:
        first = (Node *)arg0[2];
        second = first->next;
        a = first->val;
        b = second->val;
        if (a->obj->key == b->obj->key) {
            if (a->unk4 != b->unk4) {
                less = b->unk4 < a->unk4;
            } else {
                less = (u32)b < (u32)a;
            }
        } else {
            less = b->obj->key < a->obj->key;
        }
        if (less) {
            p = (void **)arg0[2];
            tmp = p[0];
            tmp2 = p[1];
            p[0] = tmp2;
            p[1] = tmp;
            p = (void **)second;
            tmp = p[0];
            tmp2 = p[1];
            p[0] = tmp2;
            p[1] = tmp;
            tmp = (void *)arg0[1];
            arg0[1] = arg0[2];
            arg0[2] = (s32)tmp;
        }
        break;
    default:
        half = (u32)temp_r0 >> 1;
        node = (Node *)arg0[2];
        for (n = half; n != 0; --n) {
            node = node->next;
        }
        fn_8014510C(&other);
        sentinel = (Node *)&other.prev;
        last = (Node *)arg0[1];
        tmp = node->prev;
        tmp2 = *(void **)((u8 *)last + 4);
        key = *arg1;
        *(void **)((u8 *)tmp + 4) = tmp2;
        tmp = node->prev;
        tmp2 = *(void **)((u8 *)last + 4);
        *(void **)tmp2 = tmp;
        other.prev->next = node;
        node->prev = other.prev;
        other.prev = last;
        last->next = sentinel;
        other.count = arg0[0] - (s32)half;
        arg0[0] = (s32)half;
        sp10.value = key;
        fn_80144B60(arg0, &sp10.value);
        spC.value = *arg1;
        fn_80144B60(&other.count, &spC.value);
        sp8.value = *arg1;
        fn_80144F78(arg0, &other.count, &sp8.value);
        node = other.next;
        if (node != sentinel) {
            last = other.prev;
            node->prev->next = last->next;
            last->next->prev = node->prev;
            while (node != sentinel) {
                tmp = node;
                node = node->next;
                Heap_Free(tmp);
                other.count = other.count - 1;
            }
        }
        break;
    }
}

s32 fn_80144D74(s32 arg0) {
    return arg0 + 4;
}

void fn_80144D7C(void) {

}

void fn_80144D80(void) {

}

void fn_80144D84(ListIter *ret, List *list, ListIter *start, ListIter *end) {
    ListNode *first;
    ListNode *last;
    ListNode *a;
    ListNode *node;

    first = start->node;
    last = end->node;
    if (first == last) {
        ret->node = last;
        return;
    }
    a = last->prev;
    first->prev->next = a->next;
    a->next->prev = first->prev;
    while (start->node != end->node) {
        node = start->node;
        start->node = node->next;
        Heap_Free(node);
        list->size--;
    }
    ret->node = end->node;
}

void fn_80144E34(ListIter *ret, List *list, ListIter *it) {
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
extern "C" void fn_80144EAC(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *Heap_Alloc(s32);
    void Heap_Free(void *);
    void fprintf(void *, void *, ...);
    void abort(void);
    extern char __files[];
    extern char lbl_80276B3C[];
    struct Node {
        Node *prev;
        Node *next;
        s32 data[2];
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
    void *list;
    s32 a;
    s32 b;

    list = (s32 *)arg1 + 1;
    node = (Node *)Heap_Alloc(0x10);
    if (node == 0) {
        fprintf(__files + 0xA0, lbl_80276B3C + 0x72, __files);
        abort();
    }
    {
        Holder h(list, node);
        if (&node->data[0] != 0) {
            a = ((s32 *)arg3)[0];
            b = ((s32 *)arg3)[1];
            node->data[0] = a;
            node->data[1] = b;
        }
        pos = *(Node **)arg2;
        n = h.node;
        h.node = 0;
        pos->prev->next = n;
        n->prev = pos->prev;
        pos->prev = n;
        n->next = pos;
        (*(s32 *)arg1)++;
        *(void **)arg0 = n;
    }
}

extern "C" void fn_80144F78(List *dst, List *src)
{
#pragma scheduling off
    typedef struct {
        u8 pad[0xe];
        u16 key;
    } KeyObj;
    typedef struct {
        KeyObj *obj;
        u8 unk4;
    } Entry;
    typedef struct Node {
        struct Node *prev;
        struct Node *next;
        Entry *val;
    } Node;

    void fn_80145124(u32 *, Node **, List *);

    Node *first;
    Node *second;
    Node *dstEnd;
    Node *srcEnd;
    Node *scan;
    Node *last;
    Entry *a;
    Entry *b;
    s32 count;
    u8 less;

    if (dst == src) {
        return;
    }

    first = *(Node **)((u8 *)dst + 8);
    dstEnd = (Node *)((u8 *)dst + 4);
    second = *(Node **)((u8 *)src + 8);
    srcEnd = (Node *)((u8 *)src + 4);

    while (first != dstEnd && second != srcEnd) {
        b = second->val;
        a = first->val;
        if (b->obj->key == a->obj->key) {
            u8 a4 = a->unk4;
            u8 b4 = b->unk4;
            if (b4 != a4) {
                less = b4 < a4;
            } else {
                less = (u32)b < (u32)a;
            }
        } else {
            less = b->obj->key < a->obj->key;
        }
        if (less) {
            a = first->val;
            scan = second->next;
            count = 1;
            while (scan != srcEnd) {
                b = scan->val;
                if (b->obj->key == a->obj->key) {
                    u8 a4 = a->unk4;
                    u8 b4 = b->unk4;
                    if (b4 != a4) {
                        less = b4 < a4;
                    } else {
                        less = (u32)b < (u32)a;
                    }
                } else {
                    less = b->obj->key < a->obj->key;
                }
                if (!less) {
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
            *(s32 *)src -= count;
            *(s32 *)dst += count;
        }
        first = first->next;
    }

    if (second != srcEnd) {
        Node *remaining = first;
        fn_80145124((u32 *)dst, &remaining, src);
    }
#pragma scheduling reset
}

#pragma cplusplus reset

int fn_8014510C(void *arg0) {
    u32 *ptr;

    ptr = (u32 *)((u8 *)arg0 + 0x4);
    *(u32 *)arg0 = 0;
    ptr[1] = (u32)ptr;
    ptr[0] = (u32)ptr;
}

void fn_80145124(u32 *arg0, ListNode **arg1, List *arg2)
{
    ListNode *list;
    ListNode *sentinel;
    ListNode *next;
    ListNode *prev;

    if (*(u32 *)arg2 == 0) {
        return;
    }

    sentinel = (ListNode *)((u8 *)arg2 + 4);
    list = *arg1;
    next = sentinel->next;
    prev = sentinel->prev;

    sentinel->next = sentinel;
    sentinel->prev = sentinel;

    list->prev->next = next;
    next->prev = list->prev;
    list->prev = prev;
    prev->next = list;

    *arg0 = *arg0 + *(u32 *)arg2;
    *(u32 *)arg2 = 0;
}

void fn_8014517C(void) {
    M2C_UNK fn_800B2CCC();
    fn_800B2CCC();
}

void fn_8014519C(void) {
    M2C_UNK fn_800B2D94();
    fn_800B2D94();
}

#pragma cplusplus on
extern "C" void fn_801451BC(void) {
    struct Obj {
        u8 pad[8];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    typedef struct {
        s8 **names;
        u8 pad[8];
        u8 flags;
        u8 pad2[0x23];
    } Entry;
    extern u8 lbl_80276BC8[];
    extern u8 lbl_803301A8[1344];
    void fn_800B3194(void);

    Entry *entry;
    s8 *str;
    s8 *b;
    s8 *a;
    s8 ca;
    s32 i;

    str = (s8 *)(lbl_80276BC8 + 0x8a);
    entry = (Entry *)lbl_803301A8;
    i = 0;
    do {
        if (entry->flags & 1) {
            a = str;
            b = (s8 *)*entry->names;
            goto loop;
        loop:
            ca = *a;
            if (ca == 0) {
                if ((s8)i >= 0) {
                    Obj *obj = (Obj *)(lbl_803301A8 + (s8)i * 0x30);
                    if (*((u8 *)obj + 0xC) & 1) {
                        obj->v2();
                    }
                }
            } else {
                s8 cb = *b;
                a += 1;
                b += 1;
                if (ca == cb) {
                    if (*b != 0) {
                        goto loop;
                    }
                }
            }
        }
        i += 1;
        entry = (Entry *)((u8 *)entry + 0x30);
    } while (i < 0x1C);
    fn_800B3194();
}
#pragma cplusplus reset

void fn_801452A8(void) {
    M2C_UNK fn_800B3248();
    fn_800B3248();
}

void fn_801452C8(void) {
    M2C_UNK Sound_HasId();
    Sound_HasId();
}

void fn_801452E8(void) {
    M2C_UNK fn_800B2E78();
    fn_800B2E78();
}

s32 fn_80145308(void) {
extern u8 lbl_80276BC8[]; extern u8 lbl_803301A8[1344];
s8 *str=(s8*)lbl_80276BC8+0x8a;
u8 *entry;
s32 i;
for(i=0,entry=lbl_803301A8;i<28;entry+=0x30,i++){
if(entry[0xc]&1){
s8 *b; s8 *a;
a=str;
b=**(s8***)entry;
while(*b){
if(!*a)return 1;
if(*a++ != *b++)break;
}
}
}
return 0;
}

void fn_801453F0(void) {
    void fn_8000BF00(void *);
    void *fn_8000CAF0(void *, s32);
    extern u8 lbl_80292558[];
    extern u8 lbl_80367AEE;
    extern f32 lbl_8036A778;
    extern f32 lbl_8036A77C;
    s32 base;
    void *temp_r3;
    f32 a;
    f32 b;

    base = (s32)lbl_80292558;
    fn_8000BF00((void *)(base + 0x28));
    fn_8000BF00((void *)(base + 0x3C));
    fn_8000BF00((void *)(base + 0x50));
    fn_8000BF00((void *)(base + 0x64));
    fn_8000BF00((void *)(base + 0x78));
    fn_8000BF00((void *)(base + 0x8C));
    temp_r3 = fn_8000CAF0((void *)(base + 0x8C), 3);
    a = lbl_8036A778;
    b = lbl_8036A77C;
    *(f32 *)((u8 *)temp_r3 + 0x30) = a;
    *(f32 *)((u8 *)temp_r3 + 0x34) = b;
    *(f32 *)((u8 *)temp_r3 + 0x38) = (f32)lbl_80367AEE;
}

void fn_80145488(void) {
 void Process_UnlinkByKey(void *); void *Process_Create(void *,s32);
 extern u8 gBgmVolFadeProcs[]; extern u8 gBgmVol;
 extern f32 gBgmVolTimerZero; extern f32 lbl_8036A77C;
 s32 base=(s32)gBgmVolFadeProcs; f32 *proc;
 Process_UnlinkByKey((void *)(base+0x28)); Process_UnlinkByKey((void *)(base+0x3C));
 Process_UnlinkByKey((void *)(base+0x50)); Process_UnlinkByKey((void *)(base+0x64));
 Process_UnlinkByKey((void *)(base+0x78)); Process_UnlinkByKey((void *)(base+0x8C));
 proc=Process_Create((void *)(base+0x78),3);
 { f32 a=gBgmVolTimerZero; f32 b=lbl_8036A77C;
 proc[12]=a; proc[13]=b; }
 proc[14]=(f32)(u32)gBgmVol;
}

void fn_80145520(void) {
    void Process_UnlinkByKey(void *);
    void *Process_Create(void *, s32);
    extern u8 gBgmVolFadeProcs[];
    extern u8 gBgmVol;
    extern f32 gBgmVolTimerZero;
    extern f32 lbl_8036A77C;
    extern f64 lbl_8036A780;
    s32 base;
    void *temp_r3;
    f32 a;
    f32 b;

    (void)lbl_8036A780;
    base = (s32)gBgmVolFadeProcs;
    Process_UnlinkByKey((void *)(base + 0x28));
    Process_UnlinkByKey((void *)(base + 0x3C));
    Process_UnlinkByKey((void *)(base + 0x50));
    Process_UnlinkByKey((void *)(base + 0x64));
    Process_UnlinkByKey((void *)(base + 0x78));
    Process_UnlinkByKey((void *)(base + 0x8C));
    temp_r3 = Process_Create((void *)(base + 0x64), 3);
    a = gBgmVolTimerZero;
    b = lbl_8036A77C;
    *(f32 *)((u8 *)temp_r3 + 0x30) = a;
    *(f32 *)((u8 *)temp_r3 + 0x34) = b;
    *(f32 *)((u8 *)temp_r3 + 0x38) = (f32)gBgmVol;
}

/* Stop BGM volume fades; snap gBgmVol to 0, or start a fade-out over `frames` ticks. */
void BgmVol_FadeOut(s32 frames) {
    void Process_UnlinkByKey(void *);
    void *Process_Create(void *, s32);
    extern u8 gBgmVolFadeProcs[];
    extern u8 gBgmVol;
    extern f32 lbl_8036A778;
    extern f64 lbl_8036A788;
    extern f64 lbl_8036A780;
    s32 base;
    void *proc;
    s32 arg;

    (void)lbl_8036A788;
    (void)lbl_8036A780;
    base = (s32)gBgmVolFadeProcs;
    arg = frames;
    Process_UnlinkByKey((void *)(base + 0x28));
    Process_UnlinkByKey((void *)(base + 0x3C));
    Process_UnlinkByKey((void *)(base + 0x50));
    Process_UnlinkByKey((void *)(base + 0x64));
    Process_UnlinkByKey((void *)(base + 0x78));
    Process_UnlinkByKey((void *)(base + 0x8C));
    if (arg == 0) {
        gBgmVol = 0;
        return;
    }
    proc = Process_Create((void *)(base + 0x50), 3);
    *(f32 *)((u8 *)proc + 0x30) = lbl_8036A778;
    *(f32 *)((u8 *)proc + 0x34) = (f32)arg;
    *(f32 *)((u8 *)proc + 0x38) = (f32)gBgmVol;
}

void fn_80145684(void) {
    void fn_8000BF00(void *);
    void *fn_8000CAF0(void *, s32);
    extern u8 lbl_80292558[];
    extern u8 lbl_80367AEE;
    extern f32 lbl_8036A778;
    extern f32 lbl_8036A77C;
    s32 base;
    void *temp_r3;
    f32 a;
    f32 b;

    base = (s32)lbl_80292558;
    fn_8000BF00((void *)(base + 0x28));
    fn_8000BF00((void *)(base + 0x3C));
    fn_8000BF00((void *)(base + 0x50));
    fn_8000BF00((void *)(base + 0x64));
    fn_8000BF00((void *)(base + 0x78));
    fn_8000BF00((void *)(base + 0x8C));
    temp_r3 = fn_8000CAF0((void *)(base + 0x3C), 3);
    a = lbl_8036A778;
    b = lbl_8036A77C;
    *(f32 *)((u8 *)temp_r3 + 0x30) = a;
    *(f32 *)((u8 *)temp_r3 + 0x34) = b;
    *(f32 *)((u8 *)temp_r3 + 0x38) = (f32)lbl_80367AEE;
}

void fn_8014571C(void) {
    void Process_UnlinkByKey(void *);
    void *Process_Create(void *, s32);
    extern u8 gBgmVolFadeProcs[];
    extern u8 gBgmVol;
    extern f32 gBgmVolTimerZero;
    extern f32 lbl_8036A77C;
    s32 base;
    void *temp_r3;
    f32 a;
    f32 b;

    base = (s32)gBgmVolFadeProcs;
    Process_UnlinkByKey((void *)(base + 0x28));
    Process_UnlinkByKey((void *)(base + 0x3C));
    Process_UnlinkByKey((void *)(base + 0x50));
    Process_UnlinkByKey((void *)(base + 0x64));
    Process_UnlinkByKey((void *)(base + 0x78));
    Process_UnlinkByKey((void *)(base + 0x8C));
    temp_r3 = Process_Create((void *)(base + 0x28), 3);
    a = gBgmVolTimerZero;
    b = lbl_8036A77C;
    *(f32 *)((u8 *)temp_r3 + 0x30) = a;
    *(f32 *)((u8 *)temp_r3 + 0x34) = b;
    *(f32 *)((u8 *)temp_r3 + 0x38) = (f32)gBgmVol;
}

void fn_801457B4(void) {
    void fn_8000BF00(void *);
    void *fn_8000CAF0(void *, s32);
    extern u8 lbl_80292558[];
    extern u8 lbl_8029256C[];
    extern u8 lbl_80367AEC;
    extern f32 lbl_8036A778;
    extern f32 lbl_8036A77C;
    void *temp_r3;
    f32 a;
    f32 b;

    fn_8000BF00(lbl_80292558);
    fn_8000BF00(lbl_8029256C);
    temp_r3 = fn_8000CAF0(lbl_8029256C, 3);
    a = lbl_8036A778;
    b = lbl_8036A77C;
    *(f32 *)((u8 *)temp_r3 + 0x30) = a;
    *(f32 *)((u8 *)temp_r3 + 0x34) = b;
    *(f32 *)((u8 *)temp_r3 + 0x38) = (f32)lbl_80367AEC;
}

typedef struct BgmFadeFields { u8 pad[0x30]; f32 timer, duration, volume; } BgmFadeFields;
void fn_80145828(void) {
void Process_UnlinkByKey(void *);
void *Process_Create(void *,s32);
extern u8 gBgmVolFadeProcs[], lbl_8029256C[], gBgmQuietVol;
extern f32 gBgmVolTimerZero, lbl_8036A77C;
BgmFadeFields *proc;
f32 a,b;
Process_UnlinkByKey(gBgmVolFadeProcs);
Process_UnlinkByKey(lbl_8029256C);
proc=(BgmFadeFields *)Process_Create(gBgmVolFadeProcs,3);
a=gBgmVolTimerZero;
b=lbl_8036A77C;
proc->timer=a;
proc->duration=b;
proc->volume=(f32)(u32)gBgmQuietVol;
}

void BgmVol_FadeInProcess3(void *proc) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern s32 gUiInputFlags;
    extern u8 gBgmVol;
    u8 startVol = M2C_FIELD(proc, f32 *, 0x38);

    // Ease gBgmVol up to 100 over the process duration; snap and clear if UI skips.
    if (gUiInputFlags & 3) {
        gBgmVol = 100;
        Process_ClearFunc(proc);
        return;
    }
    M2C_FIELD(proc, f32 *, 0x30) += 1.0f;
    gBgmVol = Math_Ease(0, startVol, 100.0f, M2C_FIELD(proc, f32 *, 0x30), M2C_FIELD(proc, f32 *, 0x34));
    if (M2C_FIELD(proc, f32 *, 0x30) >= M2C_FIELD(proc, f32 *, 0x34)) {
        Process_ClearFunc(proc);
    }
}

void fn_8014595C(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern s32 gUiInputFlags;
    extern u8 gBgmVol;
    u8 alpha = M2C_FIELD(arg0, f32 *, 0x38);

    if (gUiInputFlags & 3) {
        gBgmVol = 120;
        Process_ClearFunc(arg0);
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x30) += 1.0f;
    gBgmVol = Math_Ease(0, alpha, 120.0f, M2C_FIELD(arg0, f32 *, 0x30), M2C_FIELD(arg0, f32 *, 0x34));
    if (M2C_FIELD(arg0, f32 *, 0x30) >= M2C_FIELD(arg0, f32 *, 0x34)) {
        Process_ClearFunc(arg0);
    }
}

/* Ease BGM volume up to 100 over the process duration; snap and clear if UI skips. */
void BgmVol_FadeInProcess(void *proc) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern s32 gUiInputFlags;
    extern u8 gBgmVol;
    u8 startVol = M2C_FIELD(proc, f32 *, 0x38);

    if (gUiInputFlags & 3) {
        gBgmVol = 100;
        Process_ClearFunc(proc);
        return;
    }
    M2C_FIELD(proc, f32 *, 0x30) += 1.0f;
    gBgmVol = Math_Ease(0, startVol, 100.0f, M2C_FIELD(proc, f32 *, 0x30), M2C_FIELD(proc, f32 *, 0x34));
    if (M2C_FIELD(proc, f32 *, 0x30) >= M2C_FIELD(proc, f32 *, 0x34)) {
        Process_ClearFunc(proc);
    }
}

void fn_80145ADC(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern s32 gUiInputFlags;
    extern u8 gBgmVol;
    u8 alpha = M2C_FIELD(arg0, f32 *, 0x38);

    if (gUiInputFlags & 3) {
        gBgmVol = 0;
        Process_ClearFunc(arg0);
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x30) += 1.0f;
    gBgmVol = Math_Ease(0, alpha, 0.0f, M2C_FIELD(arg0, f32 *, 0x30), M2C_FIELD(arg0, f32 *, 0x34));
    if (M2C_FIELD(arg0, f32 *, 0x30) >= M2C_FIELD(arg0, f32 *, 0x34)) {
        Process_ClearFunc(arg0);
    }
}

/* Ease BGM volume up to 100 over the process duration; snap and clear if UI skips. */
void BgmVol_FadeInProcess2(void *proc) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern s32 gUiInputFlags;
    extern u8 gBgmVol;
    u8 startVol = M2C_FIELD(proc, f32 *, 0x38);

    if (gUiInputFlags & 3) {
        gBgmVol = 100;
        Process_ClearFunc(proc);
        return;
    }
    M2C_FIELD(proc, f32 *, 0x30) += 1.0f;
    gBgmVol = Math_Ease(0, startVol, 100.0f, M2C_FIELD(proc, f32 *, 0x30), M2C_FIELD(proc, f32 *, 0x34));
    if (M2C_FIELD(proc, f32 *, 0x30) >= M2C_FIELD(proc, f32 *, 0x34)) {
        Process_ClearFunc(proc);
    }
}

void BgmVol_FadeQuietProcess(void *proc) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern s32 gUiInputFlags;
    extern u8 gBgmVol;
    u8 startVol = M2C_FIELD(proc, f32 *, 0x38);

    // Ease gBgmVol down to 70 over the process duration; snap and clear if UI skips.
    if (gUiInputFlags & 3) {
        gBgmVol = 0x46;
        Process_ClearFunc(proc);
        return;
    }
    M2C_FIELD(proc, f32 *, 0x30) += 1.0f;
    gBgmVol = Math_Ease(0, startVol, 70.0f, M2C_FIELD(proc, f32 *, 0x30), M2C_FIELD(proc, f32 *, 0x34));
    if (M2C_FIELD(proc, f32 *, 0x30) >= M2C_FIELD(proc, f32 *, 0x34)) {
        Process_ClearFunc(proc);
    }
}

/* Ease gBgmQuietVol up to 100 over the process duration; snap and clear if UI skips. */
void BgmQuietVol_FadeInProcess(void *proc) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern s32 gUiInputFlags;
    extern u8 gBgmQuietVol;
    u8 startVol = M2C_FIELD(proc, f32 *, 0x38);

    if (gUiInputFlags & 3) {
        gBgmQuietVol = 100;
        Process_ClearFunc(proc);
        return;
    }
    M2C_FIELD(proc, f32 *, 0x30) += 1.0f;
    gBgmQuietVol = Math_Ease(0, startVol, 100.0f, M2C_FIELD(proc, f32 *, 0x30), M2C_FIELD(proc, f32 *, 0x34));
    if (M2C_FIELD(proc, f32 *, 0x30) >= M2C_FIELD(proc, f32 *, 0x34)) {
        Process_ClearFunc(proc);
    }
}

/* Ease gBgmQuietVol down to 70 over the process duration; snap and clear if UI skips. */
void BgmQuietVol_FadeQuietProcess(void *proc) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern s32 gUiInputFlags;
    extern u8 gBgmQuietVol;
    u8 startVol = M2C_FIELD(proc, f32 *, 0x38);

    if (gUiInputFlags & 3) {
        gBgmQuietVol = 70;
        Process_ClearFunc(proc);
        return;
    }
    M2C_FIELD(proc, f32 *, 0x30) += 1.0f;
    gBgmQuietVol = Math_Ease(0, startVol, 70.0f, M2C_FIELD(proc, f32 *, 0x30), M2C_FIELD(proc, f32 *, 0x34));
    if (M2C_FIELD(proc, f32 *, 0x30) >= M2C_FIELD(proc, f32 *, 0x34)) {
        Process_ClearFunc(proc);
    }
}

void fn_80145E9C(void) {
    M2C_UNK fn_800B28FC();
    fn_800B28FC();
}

void *fn_80145EBC(void *arg0) {
 extern u8 lbl_80276BC8[];
 void *Hash_Lookup(void *); s32 Str_Cmp(void *,void *);
 s32 count; u8 *entry; s32 index; u8 *table;
 table=Hash_Lookup(lbl_80276BC8+0x94);
 entry=table; count=*(s32 *)entry; entry+=4; index=0;
 while(index<count) {
 if(*(void **)entry && Str_Cmp(*(void **)entry,arg0)==0) return entry;
 index++; entry+=8;
 }
 return NULL;
}

s32 fn_80145F58(void *arg0, void **arg1) {
 extern u8 lbl_80276BC8[];
 void *Hash_Lookup(void *); s32 Str_Cmp(void *, void *);
 s32 count; u8 *entry; s32 matches; s32 index; u8 *table;
 table=Hash_Lookup(lbl_80276BC8+0x9D);
 entry=table+4;
 count=*((s32 *)(table=entry)-1);
 matches=0; index=0;
 while(index<count) {
 if(*(void **)entry && Str_Cmp(*(void **)entry,arg0)==0) { *arg1++=entry; matches++; }
 index++; entry+=0x10;
 } return matches;
}

s32 fn_80146AE4(void) {
    extern s32 lbl_80367AF8;
    return lbl_80367AF8 & 1;
}

void fn_80146AF0(void) {
    extern s32 lbl_80367AF8;
    lbl_80367AF8 &= 0xFFFFFFFE;
}

void fn_80146B00(void) {
    extern s32 lbl_80367AF8;
    lbl_80367AF8 |= 1;
}

s32 fn_80146B10(s32 arg0) {
    void *Hash_Lookup(void *);
    void fn_800056A0(s32);
    extern u8 lbl_80276BC8[];
    s32 *table;
    s32 count;
    s32 lo;
    s32 hi;
    s32 mid;
    s32 key;
    s32 result;

    table = (s32 *)Hash_Lookup(lbl_80276BC8 + 0x30b);
    count = *table;
    table++;
    lo = 0;
    hi = count - 1;
    while (lo <= hi) {
        mid = lo + ((hi - lo) >> 1);
        key = table[mid * 2];
        if (key < arg0) {
            lo = mid + 1;
        } else if (key > arg0) {
            hi = mid - 1;
        } else {
            return table[mid * 2 + 1];
        }
    }
    result = 0;
    for (; count > 0; count--) {
        if ((u32)table[0] == (u32)arg0) {
            result = table[1];
            break;
        }
        table += 2;
    }
    fn_800056A0(0);
    return result;
}

#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" s8 fn_80146BE4(void *arg0) {
    void *Hash_Lookup(void *);
    struct Entry {
        void **names;
        u8 pad4[4];
        virtual u8 v0() = 0;
        u8 flags;
    };
    u8 active;
    Entry *entry;
    s32 i;
    Entry *base;
    void *h1;

    base = (Entry *)gSeCueSlots;
    i = 0;
    do {
        active = 0;
        entry = (Entry *)((u8 *)base + ((u8)i * 0x30));
        if ((entry->flags & 1) && entry->v0() != 0) {
            active = 1;
        }
        if (active != 0) {
            h1 = Hash_Lookup(arg0);
            if (h1 == Hash_Lookup(*entry->names)) {
                return (s8)i;
            }
        }
        i += 1;
    } while (i < 0x1C);
    return -1;
}

#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" s8 Fx_FindSlotByName(void *arg0) {
    void *Hash_Lookup(void *);
    struct Entry {
        void **names;
        u8 pad4[4];
        virtual u8 v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        u8 flags;
        u8 pad[0x23];
    };
    extern Entry gFxChannels[];
    void *self;
    u8 active;
    Entry *entry;
    s32 i;
    Entry *base;
    void *h1;

    self = arg0;
    base = gFxChannels;
    i = 0;
    do {
        active = 0;
        entry = (Entry *)((u8 *)base + ((u8)i * 0x30));
        if ((entry->flags & 1) && entry->v0() != 0) {
            active = 1;
        }
        if (active != 0) {
            h1 = Hash_Lookup(self);
            if (h1 == Hash_Lookup(*entry->names)) {
                return (s8)i;
            }
        }
        i += 1;
    } while (i < 4);
    return -1;
}

extern "C" void fn_80146D44(void) {
    void fn_801490C8(void *);
    void fn_80148D54(void *);
    void fn_80148A28(void *);
    u8 fn_801696E0(void);
    u8 fn_8011AC10(void);
    void fn_800B4080(void);
    extern u8 gFxChannels[];
    extern u8 lbl_80367AE8, lbl_80367AE9, lbl_80367AEA, lbl_80367AEB;
    extern u8 gBgmQuietVol, gBgmVol;
    extern u8 lbl_80367AED, lbl_80367AEF;
    extern u8 lbl_80367AF0, lbl_80367AF1, lbl_80367AF2, lbl_80367AF3, lbl_80367AF4, lbl_80367AF5;
    extern s32 lbl_80367AF8, gUiInputFlags;
    s32 i;
    s32 t;
    u8 *p;
    u8 *base;

    base = gFxChannels;
    p = (u8 *)((u32)base + 0);
    i = 0;
    do {
        fn_801490C8(p);
        i++;
        p += 0x30;
    } while (i < 4);

    i = 0;
    p = (u8 *)((u32)base + 0xC0);
    do {
        fn_80148D54(p);
        i++;
        p += 0x30;
    } while (i < 0xA);

    i = 0;
    p = (u8 *)((u32)base + 0x2A0);
    do {
        fn_80148A28(p);
        i++;
        p += 0x30;
    } while (i < 0x1C);

    (void)base;

    lbl_80367AE9 = lbl_80367AE8;
    lbl_80367AEB = lbl_80367AEA;
    lbl_80367AED = gBgmQuietVol;
    lbl_80367AEF = gBgmVol;

    if (lbl_80367AF0 > lbl_80367AF2) {
        t = lbl_80367AF0 - 1;
        lbl_80367AF1 = lbl_80367AF0;
        lbl_80367AF0 = t;
        if ((u8)t < lbl_80367AF2)
            lbl_80367AF0 = lbl_80367AF2;
    }
    if (lbl_80367AF0 < lbl_80367AF2) {
        t = lbl_80367AF0 + 1;
        lbl_80367AF1 = lbl_80367AF0;
        lbl_80367AF0 = t;
        if ((u8)t > lbl_80367AF2)
            lbl_80367AF0 = lbl_80367AF2;
    }
    if (lbl_80367AF3 > lbl_80367AF5) {
        t = lbl_80367AF3 - 1;
        lbl_80367AF4 = lbl_80367AF3;
        lbl_80367AF3 = t;
        if ((u8)t < lbl_80367AF5)
            lbl_80367AF0 = lbl_80367AF5;
    }
    if (lbl_80367AF3 < lbl_80367AF5) {
        t = lbl_80367AF3 + 1;
        lbl_80367AF4 = lbl_80367AF3;
        lbl_80367AF3 = t;
        if ((u8)t > lbl_80367AF5)
            lbl_80367AF0 = lbl_80367AF5;
    }

    if (lbl_80367AF8 & 2) {
        if ((gUiInputFlags & 0x10) || fn_801696E0() || fn_8011AC10()) {
            lbl_80367AF2 = 100;
            lbl_80367AF5 = 100;
        } else {
            lbl_80367AF2 = 0x37;
            lbl_80367AF5 = 0x87;
        }
    } else {
        lbl_80367AF2 = 100;
        lbl_80367AF5 = 100;
    }
    fn_800B4080();
}

#pragma cplusplus reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

void fn_80146F0C(void)
{
    s32 fn_800C44F4(s32);
    void Heap_AdjustExtent(s32);
    void fn_800B36D8(void *);
    void fn_800B34B0(s32);
    void fn_800B3490(void);
    void Sound_LoadPack(void *);
    void *Archive_Load(void *);
    void fn_8000D3EC(u32, void *);
    u32 fn_802097D4(void);
    void fn_800B28FC(s32);

    extern u8 lbl_80276BC8[];
    extern u8 lbl_80367AE8;
    extern u8 lbl_80367AEA;
    extern u8 gBgmQuietVol;
    extern u8 gBgmVol;
    extern u8 lbl_80367AF0;
    extern u8 lbl_80367AF1;
    extern u8 lbl_80367AF2;
    extern u8 lbl_80367AF3;
    extern u8 lbl_80367AF4;
    extern u8 lbl_80367AF5;
    extern u8 lbl_80367AF6;

    s32 value;
    u8 *ptr;
    u8 offset;

    value = 0xF00000 - fn_800C44F4(-1);

    fn_800B36D8(lbl_80276BC8 + 0x326);

    Heap_AdjustExtent(value);

    fn_800B34B0(0);
    fn_800B3490();

    Heap_AdjustExtent(-value);

    Sound_LoadPack(lbl_80276BC8 + 0x326);

    ptr = (u8 *)Archive_Load(lbl_80276BC8 + 0x314);

    while (ptr != 0) {
        offset = ptr[4];

        if (offset == 0) {
            break;
        }

        fn_8000D3EC(*(u32 *)ptr, ptr);

        offset = ptr[4];

        if (offset == 0) {
            break;
        }

        ptr += offset;
    }

    lbl_80367AE8 = 100;
    lbl_80367AEA = 100;
    gBgmQuietVol = 100;
    gBgmVol = 100;
    lbl_80367AF0 = 100;
    lbl_80367AF1 = 100;
    lbl_80367AF2 = 100;
    lbl_80367AF3 = 100;
    lbl_80367AF4 = 100;
    lbl_80367AF5 = 100;
    lbl_80367AF6 = 0;

    if (fn_802097D4() == 1) {
        fn_800B28FC(1);
    } else {
        fn_800B28FC(0);
    }
}

#pragma global_optimizer off
void fn_8014702C(u8 arg0)
{
    void fn_800B503C(void);
    void fn_800B412C(void);
    void fn_80210008(void *);
    void fn_800B4060(void);
    s32 fn_800C44F4(s32);
    void Heap_AdjustExtent(s32);
    void fn_800B36D8(void *);
    void fn_800B34B0(s32);
    void fn_800B3490(void);
    void Sound_LoadPack(void *);
    void *Archive_Load(void *);
    void fn_8000D3EC(u32, void *);
    u32 fn_802097D4(void);
    void fn_800B28FC(s32);

    extern u8 lbl_80276BC8[];
    extern u8 lbl_80367AE8;
    extern u8 lbl_80367AEA;
    extern u8 gBgmQuietVol;
    extern u8 gBgmVol;
    extern u8 lbl_80367AF0;
    extern u8 lbl_80367AF1;
    extern u8 lbl_80367AF2;
    extern u8 lbl_80367AF3;
    extern u8 lbl_80367AF4;
    extern u8 lbl_80367AF5;
    extern u8 lbl_80367AF6;

    s32 value;
    u8 *ptr;
    u32 next;
    u8 offset;

    fn_800B503C();
    fn_800B412C();
    fn_80210008(fn_800B4060);

    if (arg0) {
        value = 0xF00000 - fn_800C44F4(-1);
        fn_800B36D8(lbl_80276BC8 + 0x326);
        Heap_AdjustExtent(value);
        fn_800B34B0(0);
        fn_800B3490();
        Heap_AdjustExtent(-value);
        Sound_LoadPack(lbl_80276BC8 + 0x326);
        ptr = (u8 *)Archive_Load(lbl_80276BC8 + 0x314);

        goto check;
    body:
        fn_8000D3EC(*(u32 *)ptr, ptr);
        offset = ptr[4];
        if (offset == 0) {
            ptr = NULL;
        } else {
            ptr += offset;
        }
    check:
        offset = ptr[4];
        if (offset == 0) {
            next = 0;
        } else {
            next = (u32)ptr + offset;
        }
        if (next != 0) {
            goto body;
        }

        lbl_80367AE8 = 100;
        lbl_80367AEA = 100;
        gBgmQuietVol = 100;
        gBgmVol = 100;
        lbl_80367AF0 = 100;
        lbl_80367AF1 = 100;
        lbl_80367AF2 = 100;
        lbl_80367AF3 = 100;
        lbl_80367AF4 = 100;
        lbl_80367AF5 = 100;
        lbl_80367AF6 = 0;

        if (fn_802097D4() == 1) {
            fn_800B28FC(1);
        } else {
            fn_800B28FC(0);
        }
    }
}
#pragma global_optimizer on
s32 fn_8014716C(u8 arg0) {
 extern s32 lbl_80367AF8;
 return lbl_80367AF8 = arg0 ? (lbl_80367AF8 | 2) : (lbl_80367AF8 & ~2);
}

#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" void fn_80147188(s32 arg0) {
    void fn_800B3194(void);
    extern f32 gMsPerFrame;
    extern u8 lbl_80276BC8[];

    struct Entry {
        char **names;
        u8 pad4[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        u8 flags;
        u8 pad_d[9];
        u8 unk_16;
        u8 pad_17[0x11];
        u8 unk_28;
        u8 unk_29;
        u8 pad_2a[2];
        s16 unk_2c;
        s16 unk_2e;
    };
    extern Entry gFxChannels[];

    Entry *p;
    s32 i;
    s32 arg_save;
    Entry *base;
    s16 ext;
    s8 idx;
    s8 *str;
    s8 *a;
    s8 *b;
    s8 ca;
    s32 temp;

    arg_save = arg0;
    base = gFxChannels;
    i = 0;
    p = base + 0;
    ext = arg_save;
    do {
        if (p->flags & 1) {
            if ((s16)arg_save <= 0) {
                p->v2();
            } else if (!(p->flags & 8)) {
                temp = (s32)((f32)ext / gMsPerFrame);
                {
                    s16 n = (s16)temp;
                    if (n <= 0) {
                        n = 1;
                    }
                    p->unk_28 = p->unk_16;
                    p->unk_29 = 0;
                    p->unk_2e = n;
                    p->unk_2c = 0;
                    p->flags |= 8;
                }
            }
        }
        i += 1;
        p += 1;
    } while (i < 4);

    i = 0;
    p = (Entry *)((u8 *)base + 0xc0);
    do {
        if (p->flags & 1) {
            if ((s16)arg_save <= 0) {
                p->v2();
            } else if (!(p->flags & 8)) {
                temp = (s32)((f32)ext / gMsPerFrame);
                {
                    s16 n = (s16)temp;
                    if (n <= 0) {
                        n = 1;
                    }
                    p->unk_28 = p->unk_16;
                    p->unk_29 = 0;
                    p->unk_2e = n;
                    p->unk_2c = 0;
                    p->flags |= 8;
                }
            }
        }
        i += 1;
        p += 1;
    } while (i < 0xa);

    {
        Entry *w;
        p = (Entry *)((u8 *)base + 0x2a0);
        i = 0;
        w = p;
        do {
            if (w->flags & 1) {
                if ((s16)arg_save <= 0) {
                    w->v2();
                } else if (!(w->flags & 8)) {
                    temp = (s32)((f32)ext / gMsPerFrame);
                    {
                        s16 n = (s16)temp;
                        if (n <= 0) {
                            n = 1;
                        }
                        w->unk_28 = w->unk_16;
                        w->unk_29 = 0;
                        w->unk_2e = n;
                        w->unk_2c = 0;
                        w->flags |= 8;
                    }
                }
            }
            i += 1;
            w += 1;
        } while (i < 0x1c);
    }

    idx = 0;
    str = (s8 *)((u8 *)lbl_80276BC8 + 0x8a);
    do {
        if (p->flags & 1) {
            a = str;
            b = (s8 *)*p->names;
            goto check_b;
        loop:
            ca = *(s8 *)((u8 *)a);
            if (ca == 0) {
                if (idx >= 0) {
                    temp = (s32)idx * 0x30;
                    {
                        Entry *hit = (Entry *)((u8 *)base + 0x2a0 + temp);
                        if (hit->flags & 1) {
                            hit->v2();
                        }
                    }
                }
                goto next;
            }
            {
                s8 cb = *(s8 *)((u8 *)b);
                a += 1;
                b += 1;
                if (ca != cb) {
                    goto next;
                }
            }
        check_b:
            if (*(s8 *)((u8 *)b) != 0) {
                goto loop;
            }
        }
    next:
        idx += 1;
        p += 1;
    } while (idx < 0x1c);

    fn_800B3194();
}

#pragma cplusplus on
/* Fade an active SE cue slot to silence over durationMs (immediate stop if <= 0). */
extern "C" void SeCue_FadeOut(s8 slot, s16 durationMs) {
    struct Obj {
        u8 pad[8];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    extern u8 gSeCueSlots[1344];
    extern f32 gMsPerFrame;
    Anim *entry;
    s16 duration;
    u8 flags;
    s32 off;
    u8 *flags_ptr;

    if (slot < 0) {
        return;
    }
    off = slot * 0x30;
    flags_ptr = (u8 *)((s32)gSeCueSlots + off);
    flags = *(flags_ptr += 0xc);
    if (!(flags & 1)) {
        return;
    }
    if (durationMs <= 0) {
        ((Obj *)(gSeCueSlots + off))->v2();
        return;
    }
    if (!(flags & 8)) {
        duration = (s16)(s32)((f32)durationMs / gMsPerFrame);
        if (duration <= 0) {
            duration = 1;
        }
        entry = (Anim *)((u32)gSeCueSlots + off);
        entry->start = entry->cur;
        entry->end = 0;
        entry->frames = duration;
        entry->frame = 0;
        *flags_ptr |= 8;
    }
}
#pragma cplusplus reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

s32 SeCue_PlayAt(void *, s32, f32, f32, f32);

#pragma opt_peephole on
void SeCue_PlayAtPos(void *arg0, const f32 *arg1, s32 arg2) {
    void SeCue_PlayAt(void *, f32, f32, f32, s32);
    SeCue_PlayAt(arg0, arg1[0], arg1[1], arg1[2], arg2);
}
s32 SeCue_PlayAt(void *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2) {
    s32 Ui_PlaySeCue(void *, s32);
    extern u8 gSeCueSlots[1344];
    s32 temp_r3;
    u8 *temp_r4;

    temp_r3 = Ui_PlaySeCue(arg0, arg1);
    if ((s8)temp_r3 == -1) {
        return -1;
    }
    temp_r4 = gSeCueSlots + ((u8)temp_r3 * 0x30);
    *(f32 *)(temp_r4 + 0x1C) = farg0;
    *(f32 *)(temp_r4 + 0x20) = farg1;
    *(f32 *)(temp_r4 + 0x24) = farg2;
    temp_r4[0xC] |= 2;
    return temp_r3;
}

/* Allocate an SE cue slot from a named cue and start it at the given volume. */
s8 Ui_PlaySeCue(void *cueName, int volume) {
    void *Hash_Lookup(void *);
    extern u8 gSeCueSlots[1344];
    extern s32 gUiInputFlags;
    extern u8 gSeCueVtblBase[];
    extern u8 gSeCueVtbl0[];
    extern u8 gSeCueVtbl1[];
    extern u8 gSeCueVtbl2[];

    s8 slot;
    u8 *found;
    u8 *src;
    s32 i;
    u8 *entry;
    s32 kind;
    s32 tmp;
    u8 val;

    entry = gSeCueSlots;
    for (i = 0; i < 0x1C; i++) {
        if (!(entry[0xC] & 1)) {
            slot = i;
            goto found;
        }
        entry += 0x30;
    }
    slot = -1;
found:
    if (slot == -1) {
        return -1;
    }
    if (gUiInputFlags & 1) {
        return -1;
    }
    found = gSeCueSlots + ((u8)slot * 0x30);
    src = Hash_Lookup(cueName);
    kind = src[5] & 3;
    switch (kind) {
    case 0:
        if (found != NULL) {
            *(void **)(found + 8) = gSeCueVtblBase;
            *(void **)found = src;
            *(void **)(found + 8) = gSeCueVtbl0;
        }
        break;
    case 1:
        if (found != NULL) {
            *(void **)(found + 8) = gSeCueVtblBase;
            *(void **)found = src;
            *(void **)(found + 8) = gSeCueVtbl1;
        }
        break;
    case 2:
        if (found != NULL) {
            *(void **)(found + 8) = gSeCueVtblBase;
            *(void **)found = src;
            *(void **)(found + 8) = gSeCueVtbl2;
        }
        break;
    }
    found[0xC] = 1;
    found[0xD] = src[6];
    found[0xE] = src[7];
    found[0xF] = 0;
    if (src[5] & 4) {
        val = 0;
    } else {
        val = src[0xC];
    }
    found[0x10] = val;
    if (src[5] & 4) {
        tmp = 0;
    } else {
        tmp = *(s16 *)(src + 0x10);
    }
    *(s16 *)(found + 0x12) = tmp;
    if (src[5] & 4) {
        tmp = 0x3E8;
    } else {
        tmp = *(u16 *)(src + 0x12);
    }
    *(u16 *)(found + 0x14) = tmp;
    found[0x16] = 0x64;
    found[0x17] = 0;
    if (src[5] & 4) {
        val = 0;
    } else {
        val = src[0xF];
    }
    tmp = (u8)val + 1;
    if (tmp > 0xFF) {
        tmp = 0xFF;
    }
    if (tmp == 0) {
        tmp = 1;
    }
    found[0x11] = tmp;
    found[0x16] = volume;
    found[0x28] = found[0x16];
    found[0x29] = volume;
    *(s16 *)(found + 0x2E) = 1;
    *(s16 *)(found + 0x2C) = 0;
    return slot;
}

#pragma cplusplus on
extern "C" void fn_801478D0(s32 arg0) {
    struct Obj {
        u8 pad[8];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    extern u8 lbl_8032FFC8[];
    extern f32 lbl_8036A7A0;
    s16 a;
    u8 *entry;
    s32 i;
    s32 temp;
    s16 var_r5;
    u8 flags;

    a = (s16)arg0;
    entry = lbl_8032FFC8;
    i = 0;
    do {
        flags = entry[0xC];
        if (flags & 1) {
            if ((s16)arg0 <= 0) {
                ((Obj *)entry)->v2();
            } else if (!(flags & 8)) {
                temp = (s32)((f32)a / lbl_8036A7A0);
                var_r5 = (s16)temp;
                if (var_r5 <= 0) {
                    var_r5 = 1;
                }
                entry[0x28] = entry[0x16];
                entry[0x29] = 0;
                *(s16 *)(entry + 0x2E) = var_r5;
                *(s16 *)(entry + 0x2C) = 0;
                entry[0xC] = entry[0xC] | 8;
            }
        }
        i += 1;
        entry += 0x30;
    } while (i < 0xA);
}

#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" void fn_801479C4(void *arg0, s16 arg1) {
    void *Hash_Lookup(void *);
    struct Entry {
        void **names;
        u8 pad4[4];
        virtual u8 v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        u8 flags;
        u8 pad_d[9];
        u8 unk_16;
        u8 pad_17[0x11];
        u8 unk_28;
        u8 unk_29;
        u8 pad_2a[2];
        s16 unk_2c;
        s16 unk_2e;
    };
    extern Entry gFxSlots[];
    extern f32 gMsPerFrame;

    u8 active;
    s32 i;
    Entry *entry;
    Entry *base;
    void *h1;
    s8 slot;
    Entry *fx;
    s32 temp;
    s16 frames;

    base = gFxSlots;
    i = 0;
    do {
        active = 0;
        entry = (Entry *)((u8 *)base + ((u8)i * 0x30));
        if ((entry->flags & 1) && entry->v0() != 0) {
            active = 1;
        }
        if (active != 0) {
            h1 = Hash_Lookup(arg0);
            if (h1 == Hash_Lookup(*entry->names)) {
                slot = (s8)i;
                goto found;
            }
        }
        i += 1;
    } while (i < 0xA);
    slot = -1;
found:
    if (slot != -1) {
        fx = (Entry *)((u8 *)gFxSlots + ((u8)slot * 0x30));
        if (arg1 <= 0) {
            fx->v2();
        } else if (!(fx->flags & 8)) {
            temp = (s32)((f32)arg1 / gMsPerFrame);
            frames = (s16)temp;
            if (frames <= 0) {
                frames = 1;
            }
            fx->unk_28 = fx->unk_16;
            fx->unk_29 = 0;
            fx->unk_2e = frames;
            fx->unk_2c = 0;
            fx->flags = (u8)(fx->flags | 8);
        }
    }
}
#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset
s32 fn_80147B24(f32 farg0, f32 farg1, f32 farg2) {
    s32 Fx_AllocSlot(void);
    extern u8 gFxSlots[];
    s32 temp_r3;
    u8 *temp_r4;

    temp_r3 = Fx_AllocSlot();
    if ((s8)temp_r3 >= 0) {
        temp_r4 = (u8 *)gFxSlots + ((s8)temp_r3 * 0x30);
        *(f32 *)(temp_r4 + 0x1C) = farg0;
        *(f32 *)(temp_r4 + 0x20) = farg1;
        *(f32 *)(temp_r4 + 0x24) = farg2;
        temp_r4[0xC] |= 2;
    }
    return temp_r3;
}

s8 Fx_AllocSlot(void *name, s8 param, s16 duration) {
    void *Hash_Lookup(void *);
    extern u8 gFxSlots[];
    extern u8 gSeCueVtblBase[];
    extern u8 gSeCueVtbl0[];
    extern u8 gSeCueVtbl1[];
    extern u8 gSeCueVtbl2[];
    extern f32 gMsPerFrame;
    s8 slot;
    u8 *fx;
    u8 *def;
    s32 i;
    u8 *entry;
    s32 kind;
    s32 tmp;
    u8 val;
    s16 frames;
    s32 temp;

    /* Find a free FX slot and initialize it from the named definition. */
    entry = gFxSlots;
    for (i = 0; i < 0xA; i++) {
        if (!(entry[0xC] & 1)) {
            slot = i;
            goto found;
        }
        entry += 0x30;
    }
    slot = -1;
found:
    if (slot >= 0) {
        fx = gFxSlots + ((u8)slot * 0x30);
        def = Hash_Lookup(name);
        kind = def[5] & 3;
        switch (kind) {
        case 0:
            if (fx != NULL) {
                *(void **)(fx + 8) = gSeCueVtblBase;
                *(void **)fx = def;
                *(void **)(fx + 8) = gSeCueVtbl0;
            }
            break;
        case 1:
            if (fx != NULL) {
                *(void **)(fx + 8) = gSeCueVtblBase;
                *(void **)fx = def;
                *(void **)(fx + 8) = gSeCueVtbl1;
            }
            break;
        case 2:
            if (fx != NULL) {
                *(void **)(fx + 8) = gSeCueVtblBase;
                *(void **)fx = def;
                *(void **)(fx + 8) = gSeCueVtbl2;
            }
            break;
        }
        fx[0xC] = 1;
        fx[0xD] = def[6];
        fx[0xE] = def[7];
        fx[0xF] = 0;
        if (def[5] & 4) {
            val = 0;
        } else {
            val = def[0xC];
        }
        fx[0x10] = val;
        if (def[5] & 4) {
            tmp = 0;
        } else {
            tmp = *(s16 *)(def + 0x10);
        }
        *(s16 *)(fx + 0x12) = tmp;
        if (def[5] & 4) {
            tmp = 0x3E8;
        } else {
            tmp = *(u16 *)(def + 0x12);
        }
        *(u16 *)(fx + 0x14) = tmp;
        fx[0x16] = 0x64;
        fx[0x17] = 0;
        if (def[5] & 4) {
            val = 0;
        } else {
            val = def[0xF];
        }
        tmp = (u8)val + 1;
        if (tmp > 0xFF) {
            tmp = 0xFF;
        }
        if (tmp == 0) {
            tmp = 1;
        }
        fx[0x11] = tmp;
        fx[0x16] = 0;
        temp = (s32)((f32)duration / gMsPerFrame);
        frames = (s16)temp;
        if (frames <= 0) {
            frames = 1;
        }
        fx[0x28] = fx[0x16];
        fx[0x29] = param;
        *(s16 *)(fx + 0x2E) = frames;
        *(s16 *)(fx + 0x2C) = 0;
        fx[0xE] = 0x40;
        fx[0xF] = 0x40;
    }
    return slot;
}

#pragma opt_common_subs off
#pragma cplusplus on
extern "C" void fn_80147EBC(s16 arg0) {
    struct Obj {
        u8 pad[8];
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
        virtual u8 v25() = 0;
    };
    extern Obj gFxChannels[];
    extern f32 gMsPerFrame;
    s32 a;
    s16 val;
    Obj *p;
    s32 i;
    s32 temp;
    u8 t;

    a = arg0;
    p = gFxChannels;
    i = 0;
    do {
        if ((*(u8 *)((u8 *)p + 0xC) & 1) && p->v25() != 0) {
            temp = (s32)((f32)a / gMsPerFrame);
            val = (s16)temp;
            if (val <= 0) {
                val = 1;
            }
            p->v4();
            t = *(u8 *)((u8 *)p + 0x2A);
            *(u8 *)((u8 *)p + 0x28) = 0;
            *(u8 *)((u8 *)p + 0x29) = t;
            *(s16 *)((u8 *)p + 0x2E) = val;
            *(s16 *)((u8 *)p + 0x2C) = 0;
        }
        i += 1;
        p = (Obj *)((u8 *)p + 0x30);
    } while (i < 4);
}
#pragma cplusplus reset
#pragma opt_common_subs reset
void fn_80147FA8(s16 arg0) {
    extern struct Unk30 {
        u8 pad_0x0[8];
        void **vtbl;     /* +0x8 */
        u8 flags;        /* +0xC */
        u8 pad_d[9];
        u8 unk_16;       /* +0x16 */
        u8 pad_17[0x11];
        u8 unk_28;       /* +0x28 */
        u8 unk_29;       /* +0x29 */
        u8 unk_2A;       /* +0x2A */
        u8 pad_2B;
        s16 unk_2C;      /* +0x2C */
        s16 unk_2E;      /* +0x2E */
    } gFxChannels;
    extern f32 gMsPerFrame;
    s32 var_r31;
    struct Unk30 *var_r30;
    s32 var_r29;
    s32 temp;
    s16 var_r4;

    var_r31 = arg0;
    var_r30 = &gFxChannels;
    var_r29 = 0;
    do {
        if ((var_r30->flags & 1) &&
            (((u8 (*)(M2C_UNK *))var_r30->vtbl[0x6C / 4])((M2C_UNK *)var_r30) == 0)) {
            if (arg0 <= 0) {
                if (!(var_r30->flags & 4)) {
                    var_r30->unk_2A = var_r30->unk_16;
                    ((void (*)(M2C_UNK *))var_r30->vtbl[0x14 / 4])((M2C_UNK *)var_r30);
                }
            } else {
                temp = (s32) ((f32) var_r31 / gMsPerFrame);
                var_r4 = (s16) temp;
                if (var_r4 <= 0) {
                    var_r4 = 1;
                }
                var_r30->unk_2A = var_r30->unk_16;
                var_r30->unk_28 = var_r30->unk_16;
                var_r30->unk_29 = 0;
                var_r30->unk_2E = var_r4;
                var_r30->unk_2C = 0;
                var_r30->flags = (u8)(var_r30->flags | 4);
            }
        }
        var_r29 += 1;
        var_r30 = (struct Unk30 *)((u8 *)var_r30 + 0x30);
    } while (var_r29 < 4);
}

#pragma peephole on
#pragma cplusplus on
extern "C" void fn_801480D8(s16 arg0) {
    struct Obj {
        u8 pad[8];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    extern Obj gFxChannels[];
    extern f32 gMsPerFrame;
    s16 raw;
    s32 a;
    unsigned int temp;
    Obj *p;
    register s32 i;
    s16 val;
    u8 flags;

    raw = arg0;
    a = raw;
    p = gFxChannels;
    i = 0;
    do {
        flags = *(u8 *)((u8 *)p + 0xC);
        if (flags & 1) {
            if (0 >= raw) {
                p->v2();
            } else if (!(flags & 8)) {
                temp = (s32)((f32)a / gMsPerFrame);
                val = (s16)temp;
                if (0 >= val) {
                    val = 1;
                }
                *(u8 *)((u8 *)p + 0x28) = *(u8 *)((u8 *)p + 0x16);
                *(u8 *)((u8 *)p + 0x29) = 0;
                *(s16 *)((u8 *)p + 0x2E) = val;
                *(s16 *)((u8 *)p + 0x2C) = 0;
                *(u8 *)((u8 *)p + (unsigned)0xC) = (u8)(*(u8 *)((u8 *)p + (u32)0xC) | 8);
            }
        }
        ++i;
        p = (Obj *)((u8 *)p + 0x30);
    } while (i < 4);
}

extern "C" void fn_801481CC(void *arg0, s16 arg1) {
    void *Hash_Lookup(void *);
    struct Entry {
        void **names;
        u8 pad4[4];
        virtual u8 v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        u8 flags;
        u8 pad_d[9];
        u8 unk_16;
        u8 pad_17[0x11];
        u8 unk_28;
        u8 unk_29;
        u8 pad_2a[2];
        s16 unk_2c;
        s16 unk_2e;
    };
    extern Entry gFxChannels[];
    extern f32 gMsPerFrame;

    u8 active;
    s32 i;
    Entry *entry;
    Entry *base;
    void *h1;
    s8 slot;
    Entry *fx;
    s32 temp;
    s16 frames;

    base = gFxChannels;
    i = 0;
    do {
        active = 0;
        entry = (Entry *)((u8 *)base + ((u8)i * 0x30));
        if ((entry->flags & 1) && entry->v0() != 0) {
            active = 1;
        }
        if (active != 0) {
            h1 = Hash_Lookup(arg0);
            if (h1 == Hash_Lookup(*entry->names)) {
                slot = (s8)i;
                goto found;
            }
        }
        i += 1;
    } while (i < 4);
    slot = -1;
found:
    if (slot != -1) {
        fx = (Entry *)((u8 *)gFxChannels + ((u8)slot * 0x30));
        if (arg1 <= 0) {
            fx->v2();
        } else if (!(fx->flags & 8)) {
            temp = (s32)((f32)arg1 / gMsPerFrame);
            frames = (s16)temp;
            if (frames <= 0) {
                frames = 1;
            }
            fx->unk_28 = fx->unk_16;
            fx->unk_29 = 0;
            fx->unk_2e = frames;
            fx->unk_2c = 0;
            fx->flags = (u8)(fx->flags | 8);
        }
    }
}

#pragma cplusplus reset
#pragma peephole reset

#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" s8 Fx_StartSlot(u8 arg0, void *arg1, s8 arg2, s16 arg3) {
    /* Start named FX in channel arg0; return -1 if that name is already active in any channel. */
    void *Hash_Lookup(void *);
    extern u8 gSeCueVtblBase[];
    extern u8 gSeCueVtbl0[];
    extern u8 gSeCueVtbl1[];
    extern u8 gSeCueVtbl2[];
    extern f32 gMsPerFrame;

    struct Entry {
        void **names;
        u8 pad4[4];
        virtual u8 v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        u8 flags;
        u8 unk_d;
        u8 unk_e;
        u8 unk_f;
        u8 unk_10;
        u8 unk_11;
        s16 unk_12;
        u16 unk_14;
        u8 unk_16;
        u8 unk_17;
        u8 pad_18[0x10];
        u8 unk_28;
        u8 unk_29;
        u8 pad_2a[2];
        s16 unk_2c;
        s16 unk_2e;
    };
    extern Entry gFxChannels[];

    u8 active;
    s32 i;
    Entry *entry;
    Entry *slot;
    Entry *base;
    s8 existing;
    void *def;
    s32 kind;
    s32 tmp;
    u8 val;
    s32 temp;
    s16 frames;
    void *h1;

    base = gFxChannels;
    slot = (Entry *)((u8 *)base + (arg0 * 0x30));
    i = 0;
    do {
        active = 0;
        entry = (Entry *)((u8 *)base + ((u8)i * 0x30));
        if ((entry->flags & 1) && entry->v0() != 0) {
            active = 1;
        }
        if (active != 0) {
            h1 = Hash_Lookup(arg1);
            if (h1 == Hash_Lookup(*entry->names)) {
                existing = i;
                goto after_search;
            }
        }
        i += 1;
    } while (i < 4);
    existing = -1;
after_search:
    if (existing != -1) {
        return -1;
    }

    active = 0;
    if ((slot->flags & 1) && slot->v0() != 0) {
        active = 1;
    }
    if (active != 0) {
        slot->v2();
    }

    def = Hash_Lookup(arg1);
    kind = *((u8 *)def + 5) & 3;
    switch (kind) {
    case 0:
        if (slot != NULL) {
            *(void **)((u8 *)slot + 8) = gSeCueVtblBase;
            slot->names = (void **)def;
            *(void **)((u8 *)slot + 8) = gSeCueVtbl0;
        }
        break;
    case 1:
        if (slot != NULL) {
            *(void **)((u8 *)slot + 8) = gSeCueVtblBase;
            slot->names = (void **)def;
            *(void **)((u8 *)slot + 8) = gSeCueVtbl1;
        }
        break;
    case 2:
        if (slot != NULL) {
            *(void **)((u8 *)slot + 8) = gSeCueVtblBase;
            slot->names = (void **)def;
            *(void **)((u8 *)slot + 8) = gSeCueVtbl2;
        }
        break;
    }
    slot->flags = 1;
    slot->unk_d = *((u8 *)def + 6);
    slot->unk_e = *((u8 *)def + 7);
    slot->unk_f = 0;
    if (*((u8 *)def + 5) & 4) {
        val = 0;
    } else {
        val = *((u8 *)def + 0xc);
    }
    slot->unk_10 = val;
    if (*((u8 *)def + 5) & 4) {
        tmp = 0;
    } else {
        tmp = *(s16 *)((u8 *)def + 0x10);
    }
    slot->unk_12 = tmp;
    if (*((u8 *)def + 5) & 4) {
        tmp = 0x3e8;
    } else {
        tmp = *(u16 *)((u8 *)def + 0x12);
    }
    slot->unk_14 = tmp;
    slot->unk_16 = 0x64;
    slot->unk_17 = 0;
    if (*((u8 *)def + 5) & 4) {
        val = 0;
    } else {
        val = *((u8 *)def + 0xf);
    }
    tmp = (u8)val + 1;
    if (tmp > 0xff) {
        tmp = 0xff;
    }
    if (tmp == 0) {
        tmp = 1;
    }
    slot->unk_11 = tmp;
    slot->unk_16 = 0;
    temp = (s32)((f32)arg3 / gMsPerFrame);
    frames = (s16)temp;
    if (frames <= 0) {
        frames = 1;
    }
    slot->unk_28 = slot->unk_16;
    slot->unk_29 = arg2;
    slot->unk_2e = frames;
    slot->unk_2c = 0;
    return arg0;
}

extern "C" s32 fn_80148618(void *arg0, void *arg1) {
    struct Entry {
        void **names;
        u8 pad4[4];
        virtual u8 v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        u8 flags;
        u8 pad_d[9];
        u8 unk_16;
        u8 pad_17[0x11];
        u8 unk_28;
        u8 unk_29;
        u8 pad_2a[2];
        s16 unk_2c;
        s16 unk_2e;
    };
    extern Entry gFxChannels[];
    u32 Hash_Lookup(void *);
    s32 Fx_StartSlot(u32, void *, s32, void *);

    u8 active;
    s32 i;
    Entry *entry;
    Entry *base;
    u32 h1;
    s8 slot;
    s32 freeSlot;

    base = gFxChannels;
    i = 0;
    do {
        active = 0;
        entry = (Entry *)((u8 *)base + ((u8)i * 0x30));
        if ((entry->flags & 1) && entry->v0() != 0) {
            active = 1;
        }
        if (active != 0) {
            h1 = Hash_Lookup(arg0);
            if (h1 == Hash_Lookup(*entry->names)) {
                slot = (s8)i;
                goto found;
            }
        }
        i += 1;
    } while (i < 4);
    slot = -1;
found:
    if (slot != -1) {
        return -1;
    }
    if (!(gFxChannels[0].flags & 1)) {
        freeSlot = 0;
    } else if (!(gFxChannels[1].flags & 1)) {
        freeSlot = 1;
    } else if (!(gFxChannels[2].flags & 1)) {
        freeSlot = 2;
    } else if (!(gFxChannels[3].flags & 1)) {
        freeSlot = 3;
    } else {
        freeSlot = -1;
    }
    if ((s8)freeSlot == -1) {
        return -1;
    }
    return Fx_StartSlot((u8)freeSlot, arg0, 0x64, arg1);
}

#pragma cplusplus reset
#pragma use_lmw_stmw reset

void fn_8014876C(void *arg0, s8 arg1, s16 arg2) {
    extern f32 gMsPerFrame;
    s16 frames = (s16)((s32)((f32)arg2 / gMsPerFrame));
    if (frames <= 0) {
        frames = 1;
    }
    M2C_FIELD(arg0, u8 *, 0x28) = (u8)M2C_FIELD(arg0, u8 *, 0x16);
    M2C_FIELD(arg0, s8 *, 0x29) = arg1;
    M2C_FIELD(arg0, s16 *, 0x2E) = frames;
    M2C_FIELD(arg0, s16 *, 0x2C) = 0;
}

extern f64 lbl_8036A788;
#pragma cplusplus on
extern "C" void Fx_FadeIn(void *arg0, s16 arg1) {
    struct Obj {
        u8 pad[8];
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
        virtual u8 v25() = 0;
    };
    extern f32 gMsPerFrame;
    s32 temp;
    s16 var_r31;
    u8 t;

    if (((Obj *)arg0)->v25() != 0) {
        temp = (s32)((f32)arg1 / gMsPerFrame);
        var_r31 = (s16)temp;
        if (var_r31 <= 0) {
            var_r31 = 1;
        }
        ((Obj *)arg0)->v4();
        t = M2C_FIELD(arg0, u8 *, 0x2A);
        M2C_FIELD(arg0, u8 *, 0x28) = 0;
        M2C_FIELD(arg0, u8 *, 0x29) = t;
        M2C_FIELD(arg0, s16 *, 0x2E) = var_r31;
        M2C_FIELD(arg0, s16 *, 0x2C) = 0;
    }
}

/* Fade an FX channel's alpha to 0 over durationMs, or finish immediately if durationMs <= 0. */
extern "C" void Fx_FadeOut(void *channel, s16 durationMs) {
    struct Obj {
        u8 pad[8];
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
        virtual u8 v25() = 0;
    };
    extern f32 gMsPerFrame;
    s32 frames;
    s16 duration;

    if (((Obj *)channel)->v25() == 0) {
        if (durationMs <= 0) {
            if (!(M2C_FIELD(channel, u8 *, 0xC) & 4)) {
                M2C_FIELD(channel, u8 *, 0x2A) = M2C_FIELD(channel, u8 *, 0x16);
            }
            ((Obj *)channel)->v3();
            return;
        }
        if (!(M2C_FIELD(channel, u8 *, 0xC) & 4)) {
            frames = (s32)((f32)durationMs / gMsPerFrame);
            duration = (s16)frames;
            if (duration <= 0) {
                duration = 1;
            }
            M2C_FIELD(channel, u8 *, 0x2A) = M2C_FIELD(channel, u8 *, 0x16);
            M2C_FIELD(channel, u8 *, 0x28) = M2C_FIELD(channel, u8 *, 0x16);
            M2C_FIELD(channel, u8 *, 0x29) = 0;
            M2C_FIELD(channel, s16 *, 0x2E) = duration;
            M2C_FIELD(channel, s16 *, 0x2C) = 0;
            M2C_FIELD(channel, u8 *, 0xC) = (u8)(M2C_FIELD(channel, u8 *, 0xC) | 4);
        }
    }
}
extern "C" void fn_80148980(void *arg0, s16 arg1) {
    struct Obj {
        u8 pad[8];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    extern f32 gMsPerFrame;
    s32 temp;
    s16 var_r5;

    if (arg1 <= 0) {
        ((Obj *)arg0)->v2();
        return;
    }
    if (!(M2C_FIELD(arg0, u8 *, 0xC) & 8)) {
        temp = (s32)((f32)arg1 / gMsPerFrame);
        var_r5 = (s16)temp;
        if (var_r5 <= 0) {
            var_r5 = 1;
        }
        M2C_FIELD(arg0, u8 *, 0x28) = M2C_FIELD(arg0, u8 *, 0x16);
        M2C_FIELD(arg0, u8 *, 0x29) = 0;
        M2C_FIELD(arg0, s16 *, 0x2E) = var_r5;
        M2C_FIELD(arg0, s16 *, 0x2C) = 0;
        M2C_FIELD(arg0, u8 *, 0xC) = (u8)(M2C_FIELD(arg0, u8 *, 0xC) | 8);
    }
}
#pragma cplusplus reset
extern u8 lbl_80367AEA;
extern u8 lbl_80367AEB;
s32 fn_8014953C(u8 *);
#pragma cplusplus on
extern "C" void fn_80148A28(void *arg0) {
    struct Obj {
        u8 pad0[8];
        virtual u8 v0() = 0;
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
        virtual u8 v19() = 0;
        u8 flags;
        u8 unk_d;
        u8 unk_e;
        u8 pad_f;
        u8 unk_10;
        u8 delay;
        s16 unk_12;
        u8 pad14[2];
        u8 cur;
        u8 prev;
        u8 pad18[0x10];
        u8 start;
        u8 end;
        u8 pad2A[2];
        u16 frame;
        u16 frames;
    };
    struct DrawIface {
        u8 pad0[0x18];
        virtual void Set(u8, u8, u8, u16) = 0;
        virtual void Draw() = 0;
    };
    s32 rate;
    Obj *self = (Obj *)arg0;
    u8 flags;
    u8 level;
    u8 alive;

    rate = 0x64;
    flags = self->flags;
    if (flags & 1) {
        u8 delay = self->delay;
        if (delay == 0) {
            if (flags & 2) {
                rate = fn_8014953C((u8 *)self);
            }
            if (self->frame <= self->frames) {
                self->cur = (u8)((f32)self->start + (f32)self->frame * ((f32)self->end - (f32)self->start) / (f32)self->frames);
                self->frame++;
                if (self->frame > self->frames && (self->flags & 4)) {
                    self->v3();
                    self->flags &= ~4;
                }
                if (self->frame > self->frames && (self->flags & 8)) {
                    self->v2();
                    self->flags &= ~8;
                }
            }
            if (self->cur != self->prev || lbl_80367AEA != lbl_80367AEB || (self->flags & 2)) {
                level = (u8)(lbl_80367AEA * rate / 100);
                self->unk_d = (u8)(level * (self->cur * self->v19()) / 10000);
                self->prev = self->cur;
            }
            ((DrawIface *)self)->Draw();
            alive = 0;
            if ((self->flags & 1) && self->v0()) {
                alive = 1;
            }
            if (alive == 0) {
                self->flags &= ~1;
            }
        } else {
            self->delay = delay - 1;
            if (self->delay == 0) {
                if (self->flags & 2) {
                    rate = fn_8014953C((u8 *)self);
                }
                level = (u8)(lbl_80367AEA * rate / 100);
                self->unk_d = (u8)(level * (self->cur * self->v19()) / 10000);
                ((DrawIface *)self)->Set(self->unk_d, self->unk_e, self->unk_10, (u16)self->unk_12);
                ((DrawIface *)self)->Draw();
            }
        }
    }
}

extern "C" void fn_80148D54(void *arg0) {
    s32 fn_8014953C(u8 *);
    extern u8 lbl_80367AE8;
    extern u8 lbl_80367AE9;
    extern u8 lbl_80367AEE;
    extern u8 lbl_80367AEF;
    extern u8 lbl_80367AF0;
    extern u8 lbl_80367AF1;
    extern u8 lbl_80367AF3;
    struct Obj {
        u8 pad0[8];
        virtual u8 v0() = 0;
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
        virtual u8 v19() = 0;
        u8 flags;
        u8 unk_d;
        u8 unk_e;
        u8 pad_f;
        u8 unk_10;
        u8 delay;
        s16 unk_12;
        u8 pad14[2];
        u8 cur;
        u8 prev;
        u8 pad18[0x10];
        u8 start;
        u8 end;
        u8 pad2A[2];
        u16 frame;
        u16 frames;
    };
    struct DrawIface {
        u8 pad0[0x18];
        virtual void Set(u8, u8, u8, u16) = 0;
        virtual void Draw() = 0;
    };
    s32 rate;
    Obj *self = (Obj *)arg0;
    register u8 flags;
    u8 level;
    u8 factor;
    u8 alive;

    rate = 0x64;
    flags = self->flags;
    if (flags & 1) {
        register u8 delay = self->delay;
        if (delay == 0) {
            if (flags & 2) {
                rate = fn_8014953C((u8 *)self);
            }
            if (self->frame <= self->frames) {
                self->cur = (u8)((f32)self->start + (f32)self->frame * ((f32)self->end - (f32)self->start) / (f32)self->frames);
                self->frame++;
                if (self->frame > self->frames && (self->flags & 4)) {
                    self->v3();
                    self->flags &= ~4;
                }
                if (self->frame > self->frames && (self->flags & 8)) {
                    self->v2();
                    self->flags &= ~8;
                }
            }
            if (self->cur != self->prev || lbl_80367AE8 != lbl_80367AE9 || lbl_80367AEE != lbl_80367AEF || lbl_80367AF0 != lbl_80367AF1 || (self->flags & 2)) {
                level = (u8)(lbl_80367AF3 * (lbl_80367AEE * rate) / 10000);
                factor = lbl_80367AE8;
                self->unk_d = (u8)(level * (factor * (self->cur * self->v19())) / 1000000);
                self->prev = self->cur;
            }
            ((DrawIface *)self)->Draw();
            alive = 0;
            if ((self->flags & 1) && self->v0()) {
                alive = 1;
            }
            if (alive == 0) {
                self->flags &= ~1;
            }
        } else {
            self->delay = delay - 1;
            if (self->delay == 0) {
                if (self->flags & 2) {
                    rate = fn_8014953C((u8 *)self);
                }
                level = (u8)(lbl_80367AF3 * (lbl_80367AEE * rate) / 10000);
                factor = lbl_80367AE8;
                self->unk_d = (u8)(level * (factor * (self->cur * self->v19())) / 1000000);
                ((DrawIface *)self)->Set(self->unk_d, self->unk_e, self->unk_10, (u16)self->unk_12);
                ((DrawIface *)self)->Draw();
            }
        }
    }
}

#pragma cplusplus on
extern "C" void fn_801490C8(void *arg0) {
    extern u8 lbl_80367AE8;
    extern u8 lbl_80367AE9;
    extern u8 lbl_80367AEC;
    extern u8 lbl_80367AED;
    extern u8 lbl_80367AF0;
    extern u8 lbl_80367AF1;
    extern u8 lbl_8032FF08[];
    struct Obj {
        u8 pad0[8];
        virtual u8 v0() = 0;
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
        virtual u8 v19() = 0;
        u8 flags;
        u8 unk_d;
        u8 unk_e;
        u8 pad_f;
        u8 unk_10;
        u8 delay;
        s16 unk_12;
        u8 pad14[2];
        u8 cur;
        u8 prev;
        u8 pad18[0x10];
        u8 start;
        u8 end;
        u8 pad2A[2];
        u16 frame;
        u16 frames;
    };
    struct DrawIface {
        u8 pad0[0x18];
        virtual void Set(u8, u8, u8, u16) = 0;
        virtual void Draw() = 0;
    };
    s32 rate;
    Obj *self = (Obj *)arg0;
    s32 flags;
    
    u8 factor;
    u8 alive;

    rate = 0x64;
    flags = self->flags;
    if (flags & 1) {
        register u8 delay = self->delay;
        if (delay == 0) {
            if (flags & 2) {
                rate = fn_8014953C((u8 *)self);
            }
            if (self->frame <= self->frames) {
                self->cur = (u8)((f32)self->start + (f32)self->frame * ((f32)self->end - (f32)self->start) / (f32)self->frames);
                self->frame++;
                if (self->frame > self->frames && (self->flags & 4)) {
                    self->v3();
                    self->flags &= ~4;
                }
                if (self->frame > self->frames && (self->flags & 8)) {
                    self->v2();
                    self->flags &= ~8;
                }
            }
            if (self->cur != self->prev || lbl_80367AE8 != lbl_80367AE9 || lbl_80367AEC != lbl_80367AED || lbl_80367AF0 != lbl_80367AF1 || (self->flags & 2)) {
                if((void *)lbl_8032FF08==self) {
 rate=(u8)(rate*(lbl_80367AEC*lbl_80367AF0)/10000);
 factor=lbl_80367AE8;
 self->unk_d=(u8)(rate*(factor*(self->cur*self->v19()))/1000000);
 } else {
 factor=lbl_80367AE8;
 rate=(u8)(lbl_80367AEC*rate/100);
 self->unk_d=(u8)(rate*(factor*(self->cur*self->v19()))/1000000);
 }
                self->prev = self->cur;
            }
            ((DrawIface *)self)->Draw();
            alive = 0;
            if ((self->flags & 1) && self->v0()) {
                alive = 1;
            }
            if (alive == 0) {
                self->flags &= ~1;
            }
        } else {
            self->delay = delay - 1;
            if (self->delay == 0) {
                if (self->flags & 2) {
                    rate = fn_8014953C((u8 *)self);
                }
                if((void *)lbl_8032FF08==self) {
 rate=(u8)(rate*(lbl_80367AEC*lbl_80367AF0)/10000);
 factor=lbl_80367AE8;
 self->unk_d=(u8)(rate*(factor*(self->cur*self->v19()))/1000000);
 } else {
 factor=lbl_80367AE8;
 rate=(u8)(lbl_80367AEC*rate/100);
 self->unk_d=(u8)(rate*(factor*(self->cur*self->v19()))/1000000);
 }
                ((DrawIface *)self)->Set(self->unk_d, self->unk_e, self->unk_10, (u16)self->unk_12);
                ((DrawIface *)self)->Draw();
            }
        }
    }
}

s32 fn_8014953C(u8 *self) {
    void *Camera_Get(void);
    void fn_802029C4(void *, void *, void *);
    void fn_802031A8(void *, void *, void *);
    f32 Vec_Length(void *);
    f32 Math_Ease(s32, f32, f32, f32, f32);
    extern u8 lbl_80366E90, lbl_80367AF6;
    extern f64 lbl_8036A780;
    extern f32 gBgmVolTimerZero, lbl_8036A790, lbl_8036A794, lbl_8036A7A4, lbl_8036A7A8, lbl_8036A7AC, lbl_8036A7B0;
    f32 delta[3], a[3], b[3];
    f32 scale, den, x, y, len, lim, sx, sy;
    u8 *cam;
    cam = (u8 *)Camera_Get();
    scale = (f32)lbl_80366E90;
    if (scale <= gBgmVolTimerZero)
        scale = lbl_8036A790;
    self[0x10] = (u8)(lbl_80367AF6 + (*(s32(**)(void *))(*(u8 **)(self + 8) + 0x60))(self));
    fn_802029C4(cam + 0xA4, self + 0x1C, a);
    fn_802029C4(cam + 0xA4, cam + 0xE0, b);
    fn_802031A8(a, b, delta);
    if (gBgmVolTimerZero == Vec_Length(delta)) {
        self[0xE] = 0x40;
        self[0xF] = 0x40;
    } else {
        den = lbl_8036A7A4 * scale;
        x = lbl_8036A7A8 * delta[0] / den;
        y = lbl_8036A7AC * delta[1] / den;
        lim = lbl_8036A7AC;
        if (x < lim)
            x = lim;
        lim = lbl_8036A7B0;
        if (x > lim)
            x = lim;
        lim = lbl_8036A7AC;
        if (y < lim)
            y = lim;
        lim = lbl_8036A7B0;
        if (y > lim)
            y = lim;
        sx = lbl_8036A7A8 + x;
        sy = lbl_8036A7A8 + y;
        self[0xE] = (s32)sx;
        self[0xF] = (s32)sy;
    }
    fn_802031A8(self + 0x1C, cam + 0xD4, delta);
    scale *= (u16)(*(u16(**)(void *))(*(u8 **)(self + 8) + 0x5C))(self);
    len = Vec_Length(delta);
    if (len > scale)
        len = scale;
    return (s32)Math_Ease(0, lbl_8036A794, gBgmVolTimerZero, len, scale);
}
#pragma cplusplus reset

#pragma cplusplus reset
s8 fn_80149734(void) {
    s32 Fx_GetFlags(s32);
    s32 i;

    for (i = 0; i < 3; i++) {
        if (Fx_GetFlags(i) == 0U) {
            return (s8)i;
        }
    }
    return -1;
}

void fn_80149784(void *arg0) {
    fn_800AFAFC(*(s8*)((uintptr_t)arg0 + 4));
}

void fn_801497AC(void *arg0) {
    fn_800AF7F0(*(s8*)((uintptr_t)arg0 + 4));
}

void fn_801497D4(void *arg0) {
    fn_800AF96C(*(s8*)((uintptr_t)arg0 + 4));
}

void fn_801497FC(void *arg0) {
    Fx_SetVolume(*(s8*)((uintptr_t)arg0 + 4));
}

#pragma cplusplus on
extern "C" void fn_80149824(void *arg0, s32 arg1, s32 arg2) {
    struct Obj {
        u8 pad[8];
        virtual s32 v0();
        virtual s32 v1();
        virtual s32 v2();
        virtual s32 v3();
        virtual s32 v4();
        virtual s32 v5();
        virtual s32 v6();
        virtual s32 v7();
        virtual s32 v8();
        virtual s32 v9();
        virtual s32 v10();
        virtual s32 v11();
        virtual s32 v12();
        virtual s32 v13();
        virtual s32 v14();
        virtual s32 v15();
        virtual s32 v16();
        virtual s32 v17();
        virtual s32 v18();
        virtual s32 v19();
        virtual s32 v20();
        virtual s32 v21();
        virtual s32 v22();
        virtual s32 v23();
        virtual s32 v24();
    };
    void fn_800B0AC8(s32, s32);
    void fn_800AF96C(s32, s32);
    void fn_800AFAFC(s32, s32);

    *(s8 *)((u8 *)arg0 + 4) = (s8)((Obj *)arg0)->v5();
    if (*(s8 *)((u8 *)arg0 + 4) >= 0) {
        fn_800B0AC8((s32)*(s8 *)((u8 *)arg0 + 4), ((Obj *)arg0)->v24());
        fn_800AF96C((s32)*(s8 *)((u8 *)arg0 + 4), arg1);
        fn_800AFAFC((s32)*(s8 *)((u8 *)arg0 + 4), arg2);
    }
}
#pragma cplusplus reset

void fn_801498C8(void *arg0) {
    fn_800AFE0C(*(s8*)((uintptr_t)arg0 + 4));
}

void fn_801498F0(void *arg0) {
    fn_800AFCFC(*(s8*)((uintptr_t)arg0 + 4));
}

void fn_80149918(void *arg0) {
    fn_800AFC54(*(s8*)((uintptr_t)arg0 + 4));
}

s32 fn_80149940(void *arg0) {
    s32 Fx_GetFlags(s32);
    return Fx_GetFlags(*(s8 *)((char *)arg0 + 4)) != 0;
}

s32 fn_80149974(void *arg0) {
    return (Fx_GetFlags(*(s8 *)((u8 *)arg0 + 4)) >> 1) & 1;
}

s8 fn_801499A0(void) {
    u8 fn_800B2494(s32);
    s32 i;

    for (i = 0; i < 8; i++) {
        if (fn_800B2494(i) == 0) {
            return i;
        }
    }
    return -1;
}

void fn_801499F0(void *arg0) {
    fn_800B24D8(*(s8*)((uintptr_t)arg0 + 4));
}

#pragma cplusplus on
extern "C" void fn_80149A18(void *arg0, s32 arg1) {
    struct Obj {
        u8 pad[8];
        virtual s32 v0();
        virtual s32 v1();
        virtual s32 v2();
        virtual s32 v3();
        virtual s32 v4();
        virtual s32 v5();
        virtual s32 v6();
        virtual s32 v7();
        virtual s32 v8();
        virtual s32 v9();
        virtual s32 v10();
        virtual s32 v11();
        virtual s32 v12();
        virtual s32 v13();
        virtual s32 v14();
        virtual s32 v15();
        virtual s32 v16();
        virtual s32 v17();
        virtual s32 v18();
        virtual s32 v19();
        virtual s32 v20();
        virtual s32 v21();
        virtual s32 v22();
        virtual s32 v23();
    };
    void fn_800B24D8(s32, s32);
    s32 fn_800B26B0(s32, s32);

    s32 tmp = ((Obj *)arg0)->v5();
    *(s8 *)((u8 *)arg0 + 4) = (s8)tmp;
    s8 b = *(s8 *)((u8 *)arg0 + 4);
    if (b >= 0) {
        fn_800B24D8((s32)b, arg1);
        fn_800B26B0((s32)*(s8 *)((u8 *)arg0 + 4), ((Obj *)arg0)->v23());
    }
}
#pragma cplusplus reset
void fn_80149A9C(void *arg0) {
    fn_800B25EC(*(s8*)((uintptr_t)arg0 + 4));
}

void fn_80149AC4(void *arg0) {
    fn_800B2584(*(s8*)((uintptr_t)arg0 + 4));
}

void fn_80149AEC(void *arg0) {
    fn_800B2648(*(s8*)((uintptr_t)arg0 + 4));
}

void fn_80149B14(void *arg0) {
    fn_800B2494(*(s8*)((uintptr_t)arg0 + 4));
}

s32 fn_80149B3C(void) {
    return 0;
}

void fn_80149B44(void *arg0) {
    void fn_800B1C54(s32);
    s32 temp;

    temp = *(u8 *)((u8 *)arg0 + 4);
    if ((s8)temp >= 0) {
        fn_800B1C54((s8)temp);
    }
}

void fn_80149B74(void *arg0) {
    void fn_800B1BFC(s32);
    s32 temp;

    temp = *(u8 *)((u8 *)arg0 + 4);
    if ((s8)temp >= 0) {
        fn_800B1BFC((s8)temp);
    }
}

void fn_80149BA4(void *arg0) {
    void fn_800B1D68(s32);
    s32 temp;

    temp = *(u8 *)((u8 *)arg0 + 4);
    if ((s8)temp >= 0) {
        fn_800B1D68((s8)temp);
    }
}

void fn_80149BD4(void *arg0) {
    void fn_800B1DEC(s32);
    s32 temp;

    temp = *(u8 *)((u8 *)arg0 + 4);
    if ((s8)temp >= 0) {
        fn_800B1DEC((s8)temp);
    }
}

void fn_80149C04(void *arg0) {
    void fn_800B1D0C(s32);
    s32 temp;

    temp = *(u8 *)((u8 *)arg0 + 4);
    if ((s8)temp >= 0) {
        fn_800B1D0C((s8)temp);
    }
}

void fn_80149C34(void *arg0) {
    void fn_800B1CB0(s32);
    s32 temp;

    temp = *(u8 *)((u8 *)arg0 + 4);
    if ((s8)temp >= 0) {
        fn_800B1CB0((s8)temp);
    }
}

void fn_80149C64(void *arg0) {
    void fn_800B1B80(s32);
    s32 temp;

    temp = *(u8 *)((u8 *)arg0 + 4);
    if ((s8)temp >= 0) {
        fn_800B1B80((s8)temp);
    }
}

#pragma cplusplus on
extern "C" void fn_80149C94(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct Obj {
        u8 pad[8];
        virtual s32 v0();
        virtual s32 v1();
        virtual s32 v2();
        virtual s32 v3();
        virtual s32 v4();
        virtual s32 v5();
        virtual s32 v6();
        virtual s32 v7();
        virtual s32 v8();
        virtual s32 v9();
        virtual s32 v10();
        virtual s32 v11();
        virtual s32 v12();
        virtual s32 v13();
        virtual s32 v14();
        virtual s32 v15();
        virtual s32 v16();
        virtual s32 v17();
        virtual s32 v18();
        virtual s32 v19();
        virtual s32 v20();
        virtual s32 v21();
        virtual s32 v22();
        virtual s32 v23();
    };
    u8 Sound_PlaySE(u16, s32, s32, s32);
    void fn_800B1D0C(s32, s32);
    void fn_800B1DEC(s32, s16);
    s8 b;

    *(u8 *)((u8 *)arg0 + 4) = Sound_PlaySE((u16)((Obj *)arg0)->v23(), 0, arg1, arg2);
    b = *(s8 *)((u8 *)arg0 + 4);
    if (b >= 0) {
        fn_800B1D0C((s32)b, arg3);
        fn_800B1DEC((s32)*(s8 *)((u8 *)arg0 + 4), (s16)arg4);
    }
}
#pragma cplusplus reset

void fn_80149D1C(void *arg0) {
    void fn_800B1E44(s32);
    s32 temp;

    temp = *(u8 *)((u8 *)arg0 + 4);
    if ((s8)temp >= 0) {
        fn_800B1E44((s8)temp);
    }
}

s32 fn_80149D4C(void *arg0)
{
    s32 fn_800B1B24(s32);
    s32 temp;

    temp = *(u8 *)((u8 *)arg0 + 4);
    if ((s8)temp < 0) {
        return 0;
    }
    return fn_800B1B24((s8)temp);
}

#pragma cplusplus on
extern "C" void fn_80149D84(void *arg0) {
    struct Obj {
        u8 pad[8];
        virtual void v0() = 0;
        virtual void v1() = 0;
    };
    ((Obj *)arg0)->v1();
}
#pragma cplusplus reset
void fn_80149DB0(void) {

}

#pragma cplusplus on
extern "C" void fn_80149DB4(void *arg0) {
    struct Obj {
        u8 pad[8];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6(u8) = 0;
        virtual void v7(u8) = 0;
        virtual void v8(u8) = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12(s16) = 0;
        virtual void v13(u8) = 0;
        u8 unkC;
        u8 unkD;
        u8 unkE;
        u8 unkF;
        u8 unk10;
        u8 unk11;
        s16 unk12;
    };
    Obj *self = (Obj *)arg0;
    self->v8(self->unkD);
    self->v6(self->unkE);
    self->v7(self->unkF);
    self->v13(self->unk10);
    self->v12(self->unk12);
}
#pragma cplusplus reset
void fn_80149E50(void) {

}

void fn_80149E54(void) {

}

void fn_80149E58(void) {

}

void fn_80149E5C(void) {

}

void fn_80149E60(void) {

}

void fn_80149E64(void) {

}

void fn_80149E68(void) {

}

s32 fn_80149E6C(void) {
    return 0;
}

void fn_80149E74(void) {

}

u8 fn_80149E78(void **arg0) {
    return M2C_FIELD(*arg0, u8 *, 6);
}

s32 fn_80149E84(void **arg0) {
    u16 var_r0;
    void *temp_r3;

    temp_r3 = *arg0;
    if (*(u8 *)((u8 *)temp_r3 + 5) & 4) {
        var_r0 = 0x3E8;
    } else {
        var_r0 = *(u16 *)((u8 *)temp_r3 + 0x12);
    }
    return var_r0;
}

s32 fn_80149EA8(void **arg0) {
    u8 var_r0;
    void *temp_r3;

    temp_r3 = *arg0;
    if (*(u8 *)((u8 *)temp_r3 + 5) & 4) {
        var_r0 = 0;
    } else {
        var_r0 = *(u8 *)((u8 *)temp_r3 + 0xC);
    }
    return var_r0;
}

void fn_80149ECC(void) {

}

void fn_80149ED0(void) {

}

void fn_80149ED4(void) {

}

void fn_80149ED8(void) {

}

void fn_80149EDC(void) {

}

u8 fn_80149EE0(void **arg0) {
    return M2C_FIELD(*arg0, u8 *, 7);
}

s32 fn_80149EEC(void **arg0) {
    u8 var_r0;
    void *temp_r3;

    temp_r3 = *arg0;
    if (*(u8 *)((u8 *)temp_r3 + 5) & 4) {
        var_r0 = 0;
    } else {
        var_r0 = *(u8 *)((u8 *)temp_r3 + 0xF);
    }
    return var_r0;
}

s32 fn_80149F10(void **arg0) {
    return M2C_FIELD(*arg0, s32 *, 8);
}

s32 fn_80149F1C(void **arg0) {
    return M2C_FIELD(*arg0, s32 *, 8);
}

void fn_80149F28(void) {

}

void fn_80149F2C(void) {

}

s32 fn_80149F30(void) {
    return -1;
}
#include "common.h"
#include "global.h"

typedef struct {
    void *unk0;
    s32 unk4;
} Struct801405E0;

typedef struct {
    Struct801405E0 *unk0;
    s32 unk4;
} Struct801405E0_2;

typedef struct {
    Struct801405E0_2 *unk38;
    s32 unk34;
    s32 unk3C;
} Struct8013FC68_Args;
extern u32 gUiPanelBVtbl;
extern u32 gUiPanelMidVtbl;
extern u32 gEmptyVtbl;
extern u8 gSeCueSlots[];
extern u8 gFxChannels[];
#include "common.h"
extern u32 lbl_802922F0;

extern u8 lbl_80292298[];
extern f32 lbl_8036A730;
extern f64 lbl_8036A738;
#include "include/structs.h"
extern s32 gUnknown_0x8013C030;
#include "global.h"
#include "unit.h"
extern u32 lbl_802918E0;
extern u32 gEmptyVtbl;

extern s32 fn_800B503C(void);
extern s32 fn_800B412C(void);
extern void fn_80210008(void *arg0);
extern s32 fn_800C44F4(s32 arg0);
extern void fn_800B36D8(void *arg0, void *arg1);
extern void Heap_AdjustExtent(s32 arg0);
extern void fn_800B34B0(s32 arg0);
extern void fn_800B3490(void);
extern void Sound_LoadPack(void *arg0);
extern void* Archive_Load(void *arg0);
extern s32 fn_8000D3EC(s32 arg0, void *arg1);
extern s32 fn_802097D4(s32 arg0);
extern s32 fn_800B28FC(s32 arg0);
extern void fn_800B4060(void);
extern u8* gUnknown_802C9248;
extern f32 lbl_8036A674;
extern u8 lbl_802768A0[];
extern f32 lbl_8036A6B0;
extern f32 lbl_8036A6B4;
extern u8 lbl_80367AD2;
extern u8 lbl_80367AD3;
extern u32 lbl_8028459C;
extern u32 lbl_8032FED8;
extern u32 lbl_80292090;
extern u32 lbl_80291BEC;
extern u32 lbl_80276908;
extern u32 lbl_80291EAC;
extern u32 lbl_8032FEE4;
extern u32 lbl_80291E48;
extern u32 gUiMenuDrawVtbl;
extern u32 lbl_80291BD4;
extern u32 lbl_80291DA0;
extern u32 lbl_80291C50;
extern u32 lbl_802920E0;
extern f32 lbl_8036A6B8;

void* Heap_Alloc(int);
#include "common.h"
#include "dolphin/os.h"

extern f32 lbl_8036A6C0;
extern f32 gUiMenuSlotPlainTextScale;
extern f32 lbl_8036A6C8;
extern u16 lbl_80291730[];
#include "common.h"
#include "dolphin/os.h"

extern f64 lbl_8036A600;

typedef s32 (*FuncPtr0)(void);

