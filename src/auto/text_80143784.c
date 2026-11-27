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

#pragma scheduling reset
#pragma optimization_level reset

#pragma opt_lifetimes off

#pragma opt_lifetimes reset
#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma use_lmw_stmw reset
extern "C" void Ui_DrawListWindowFrame(s32, s32, s32, s16, s32, s32);
s32 Prim2D_SetAlphaByte(u8);

extern "C" void *GfxEnt_Get(u8);

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_8015B820(s32, s32, s32);

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset
#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma optimization_level 3

#pragma optimization_level reset

#pragma cplusplus reset

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

#pragma cplusplus off

void fn_80059C2C(s32, s32, s32, s32, s32);

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

#pragma inline_depth(8)

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma scheduling off

#pragma scheduling on

#pragma scheduling on

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma optimization_level 3

#pragma optimization_level reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma opt_common_subs off

#pragma opt_common_subs off

#pragma opt_common_subs on
#pragma scheduling off

#pragma global_optimizer off

#pragma global_optimizer reset
#pragma scheduling on

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

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

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma global_optimizer on

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on

extern "C" void fn_80143784(void *arg0, void *arg1) {
    struct Obj {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
        virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
        virtual s32 v12(void *) = 0;
    };
    struct PNode { PNode *prev; PNode *next; void *key; void *owner; };
    struct Pair { u8 f; u32 v; };
    extern u32 lbl_8036C4E8; extern u32 lbl_8036C4EC;
    void *Unit_GetHeldItemSlot(void *, s32);
    void fn_80144E34(ListIter *, List *, ListIter *);
    void fn_80144EAC(void *, void *, void *, void *);
    void memcpy(void *, void *, u32);

    u8 saved[0x16];
    ListIter ret; ListIter it;
    u32 pairA[2]; u32 pairB[2];
    void *entry1; void *entry2;
    u32 result1; u32 result2;
    Unk1 unk;
    Pair pairs[2];
    ListNode *sentinel;
    ListNode *node2;
    u8 *fp;
    u8 flag;
    s32 j; List *lst; s32 oi;
    void *self; void *unit; u8 *p;
    PNode *sent; PNode *node;

    memcpy(saved, (u8 *)arg0 + 0x64, 0x16);
    self = arg0; unit = arg1;
    fp = &unk.unk0;
    flag = *fp;

    for (oi = 0, p = (u8 *)self; oi < 11; p += 0xc, oi++) {
        node = *(PNode **)(p + 0x98);
        sent = (PNode *)(p + 0x94);
        goto ocheck;
        for (;;) {
            if (node->owner == unit) {
                u8 *c2; void *key;
                key = node->key;
                j = 0; c2 = (u8 *)self;
                for (; j < 11; c2 += 0xc, j++) {
                    pairs[0].f = flag;
                    lst = (List *)(c2 + 0x90);
                    node2 = *(ListNode **)(c2 + 0x98);
                    sentinel = (ListNode *)((u8 *)lst + 4);
                    pairs[0].v = (u32)key;
                    *(u32 *)&pairs[1] = *(u32 *)&pairs[0];
                    pairs[1].v = (u32)key;
                    goto scheck;
                    for (;;) {
                        node2 = node2->next;
                    scheck:
                        if (node2 != sentinel) {
                            if (node2->val != (void *)pairs[1].v)
                                continue;
                        }
                        if ((u32)node2 == (u32)lst + 4)
                            break;
                        it.node = node2;
                        fn_80144E34(&ret, lst, &it);
                        if ((u32)*(s16 *)((u8 *)self + (j << 1) + 0x64) >= (u32)lst->size)
                            *(s16 *)((u8 *)self + (j << 1) + 0x64) = lst->size - 1;
                        goto onext;
                    }
                }
            }
        onext:
            node = node->next;
        ocheck:
            if (node == sent) break;
        }
    }

    {
        s32 hi; void *slot; s32 index;
        for (hi = 0; hi < 4; hi++) {
            slot = Unit_GetHeldItemSlot(unit, hi);
            if (*(u32 *)slot == 0) continue;
            index = ((Obj *)self)->v12(slot);
            if (index == 0xc) continue;
            pairA[0] = lbl_8036C4E8; pairA[1] = lbl_8036C4EC;
            lst = (List *)((u8 *)self + index * 0xc + 0x90);
            pairA[0] = (u32)slot; pairA[1] = (u32)unit;
            entry1 = (u8 *)lst + 4;
            fn_80144EAC(&result1, lst, &entry1, pairA);
        }
    }

    {
        s32 ei; void *itemp; s32 index;
        for (ei = 0, p = (u8 *)unit; ei < 4; p += 8, ei++) {
            itemp = p + 0x1ec;
            if (*(u32 *)(p + 0x1ec) == 0) continue;
            index = ((Obj *)self)->v12(itemp);
            if (index == 0xc) continue;
            pairB[0] = lbl_8036C4E8; pairB[1] = lbl_8036C4EC;
            lst = (List *)((u8 *)self + index * 0xc + 0x90);
            pairB[0] = (u32)itemp; pairB[1] = (u32)unit;
            entry2 = (u8 *)lst + 4;
            fn_80144EAC(&result2, lst, &entry2, pairB);
        }
    }

    memcpy((u8 *)arg0 + 0x64, saved, 0x16);
    {
        u8 *a = (u8 *)self; u8 *b = (u8 *)self;
        for (oi = 0; oi < 11; oi++) {
            u32 end = (u32)lst + 4;
            if ((u32)*(s16 *)(b + 0x64) >= (u32)*(s32 *)(a + 0x90))
                *(s16 *)(b + 0x64) = *(s32 *)(a + 0x90) - 1;
            a += 0xc; b += 2;
        }
    }
}
#pragma cplusplus reset
extern "C" void fn_801439F0(void *arg0, s32 arg1, s32 arg2) {
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
    extern u32 lbl_8036C4E8;
    extern u32 lbl_8036C4EC;
    void fn_80144EAC(void *, void *, void *, void *);
    u32 pair[2];
    void *entry;
    u32 result;
    s32 index;
    void *base;

    index = ((Obj *)arg0)->v12();
    if (index != 12) {
        base = (u8 *)arg0 + index * 12 + 0x90;
        pair[0] = lbl_8036C4E8;
        pair[1] = lbl_8036C4EC;
        pair[0] = arg1;
        pair[1] = arg2;
        entry = (u8 *)base + 4;
        fn_80144EAC(&result, base, &entry, pair);
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
#pragma opt_strength_reduction off
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
        virtual u32 v10() = 0;
    };
    typedef struct {
        u8 pad[0x64];
        s16 unk64[1];
    } Unk80143C58;
    Unk80143C58 *obj = (Unk80143C58 *)arg0;
    s16 result = obj->unk64[((Obj *)arg0)->v10()];
    return result;
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
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
        virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
        virtual void v8() = 0; virtual void v9() = 0; virtual s32 page() = 0;
    };
    u8 *p;
    u32 count;
    s16 visible;
    s32 pg = ((Panel *)unit)->page();
    if ((u32)arg1 > *(u32 *)((u8 *)unit + pg * 12 + 0x90) - 1) {
        arg1 = *(u32 *)((u8 *)unit + ((Panel *)unit)->page() * 12 + 0x90) - 1;
    }
    if (arg1 < 0) arg1 = 0;
    p = (u8 *)unit + ((Panel *)unit)->page() * 2;
    count = *(u32 *)((u8 *)unit + ((Panel *)unit)->page() * 12 + 0x90);
    visible = *(s16 *)((u8 *)unit + 0x80);
    if (count <= visible) {
        *(s16 *)(p + 0x64) = arg1;
        *(s16 *)(p + 0x4E) = 0;
    } else if (count - arg1 < visible) {
        *(s16 *)(p + 0x64) = arg1;
        *(s16 *)(p + 0x4E) = (unsigned)count - visible;
    } else if (*(s16 *)(p + 0x4E) < arg1 && arg1 - *(s16 *)(p + 0x4E) < visible - 1) {
        *(s16 *)(p + 0x64) = arg1;
    } else if (arg1 == 0) {
        *(s16 *)(p + 0x4E) = arg1;
        *(s16 *)(p + 0x64) = arg1;
    } else {
        *(s16 *)(p + 0x64) = arg1;
        *(s16 *)(p + 0x4E) = arg1 - 1;
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
#pragma optimization_level 2
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
    f30 = (f32)(temp_r26 * (temp_r25 % ((Obj *)obj)->v12()));
    temp_r26 = ((Obj *)obj)->v15();
    f29 = (f32)(temp_r26 * (temp_r25 / ((Obj *)obj)->v12()));
    Prim2D_AddPrim(1);
    f31 = (f32)((Obj *)obj)->v15();
    Prim2D_SetRectUv((f32)var_r28, (f32)var_r29, f30, f29, (f32)((Obj *)obj)->v14(), f31);
    Prim2D_SetPrimParam((f32)var_r30);
    sp8 = *var_r31;
    Prim2D_SetColorPacked(&sp8);
    Prim2D_EndPrim();
}
#pragma optimization_level reset
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
    r7 = *(s16 *)((u8 *)arg0 + 0x10);
    r8 = *(s16 *)((u8 *)arg0 + 0xc);
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

void fn_80144B60(s32 *arg0, u8 *arg1)
{
  typedef struct 
  {
    u8 pad[0xe];
    u16 key;
  } KeyObj;
  typedef struct 
  {
    KeyObj *obj;
    u8 unk4;
  } Entry;
  typedef struct Node
  {
    struct Node *prev;
    struct Node *next;
    Entry *val;
  } Node;
  typedef struct 
  {
    s32 count;
    Node *prev;
    Node *next;
  } SortList;
  void fn_8014510C(void *);
  void fn_80144F78(s32 *, s32 *, u8 *);
  void Heap_Free(void *);
  SortList other;
  struct _PermuterAnon1
  {
    u8 value;
  } sp10;
  struct _PermuterAnon1 spC;
  struct _PermuterAnon1 sp8;
  void **p;
  void *tmp2;
  void *tmp;
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
  temp_r0 = arg0[0];
  switch (temp_r0)
  {
    case 0:

    case 1:
      break;

    case 2:
      first = (Node *) arg0[2];
      second = first->next;
      a = first->val;
      b = second->val;
      if (a->obj->key == b->obj->key)
    {
      if (a->unk4 != b->unk4)
      {
        do
        {
          less = b->unk4 < a->unk4;
        }
        while (0);
      }
      else
      {
        less = ((u32) b) < ((u32) a);
      }
    }
    else
    {
      less = b->obj->key < a->obj->key;
    }
      if (less)
    {
      p = (void **) arg0[2];
      tmp = p[0];
      tmp2 = p[1];
      p[0] = tmp2;
      p[1] = tmp;
      p = (void **) second;
      tmp = p[0];
      tmp2 = p[1];
      p[0] = tmp2;
      p[1] = tmp;
      tmp = (void *) arg0[1];
      arg0[1] = arg0[2];
      arg0[2] = (s32) tmp;
    }
      break;

    default:
      half = ((u32) temp_r0) >> 1;
      node = (Node *) arg0[2];
      for (n = half; n != 0; --n)
    {
      node = node->next;
    }

      fn_8014510C(&other);
      sentinel = (Node *) (&other.prev);
      last = (Node *) arg0[1];
      tmp = node->prev;
      tmp2 = *((void **) (((u8 *) last) + 4));
      temp_r0 = *arg1;
      *((void **) (((u8 *) tmp) + 4)) = tmp2;
      tmp = node->prev;
      tmp2 = *((void **) (((u8 *) last) + 4));
      *((void **) tmp2) = tmp;
      other.prev->next = node;
      node->prev = other.prev;
      other.prev = last;
      last->next = sentinel;
      other.count = arg0[0] - ((s32) half);
      arg0[0] = (s32) half;
      sp10.value = temp_r0;
      fn_80144B60(arg0, &sp10.value);
      spC.value = *arg1;
      fn_80144B60(&other.count, &spC.value);
      sp8.value = *arg1;
      fn_80144F78(arg0, &other.count, &sp8.value);
      node = other.next;
      if (node != sentinel)
    {
      last = other.prev;
      node->prev->next = last->next;
      last->next->prev = node->prev;
      while (node != sentinel)
      {
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

#pragma opt_propagation off
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
        fn_800C428C(node);
        list->size--;
    }
    ret->node = end->node;
}
#pragma opt_propagation reset
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
    struct Pair { s32 v[2]; };
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
    s32 *dst;

    list = (s32 *)arg1 + 1;
    node = (Node *)Heap_Alloc(0x10);
    if (node == 0) {
        fprintf(__files + 0xA0, lbl_80276B3C + 0x72, __files);
        abort();
    }
    {
        Holder h(list, node);
        dst = &node->data[0];
        if (dst != 0) {
            *(struct Pair *)dst = *(struct Pair *)arg3;
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

#pragma push
#pragma cplusplus on
#pragma optimization_level 4
extern "C" void fn_80144F78(List *dst, List *src)
{
  typedef struct 
  {
    u8 pad[0xe];
    u16 key;
  } KeyObj;
  typedef struct 
  {
    KeyObj *obj;
    u8 unk4;
  } Entry;
  typedef struct Node
  {
    struct Node *prev;
    struct Node *next;
    Entry *val;
  } Node;
  void fn_80145124(u32 *, Node **, List *);
  Node *second;
  Node *first;
  Node *dstEnd;
  Node *scan;
  Node *srcEnd;
  Node *last;
  Entry *a;
  Entry *b;
  s32 count;
  u8 less;
  u8 a4;
  u8 b4;
  if (dst != src) {
  first = *((Node **) (((u8 *) dst) + 8));
  dstEnd = (Node *) (((u8 *) dst) + 4);
  second = *((Node **) (((u8 *) src) + 8));
  srcEnd = (Node *) (((u8 *) src) + 4);
  while ((first != dstEnd) && (second != srcEnd))
  {
    b = second->val;
    a = first->val;
    if (a->obj->key == b->obj->key)
    {
      a4 = a->unk4;
      b4 = b->unk4;
      if (b4 != a4)
      {
        less = b4 < a4;
      }
      else
      {
        less = ((u32) b) < ((u32) a);
      }
    }
    else
    {
      less = a->obj->key > b->obj->key;
    }
    if (less)
    {
      scan = second->next;
      a = first->val;
      count = 1;
      while (scan != srcEnd)
      {
        b = scan->val;
        if (b->obj->key == a->obj->key)
        {
          a4 = a->unk4;
          b4 = b->unk4;
          if (b4 != a4)
          {
            less = b4 < a4;
          }
          else
          {
            less = ((u32) b) < ((u32) a);
          }
        }
        else
        {
          less = b->obj->key < a->obj->key;
        }
        if (!less)
        {
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
      *((s32 *) src) -= count;
      *((s32 *) dst) += count;
    }
    first = first->next;
  }

  if (second != srcEnd)
  {
    Node *remaining = first;
    fn_80145124((u32 *) dst, &remaining, src);
  }
}
}
#pragma pop
#pragma cplusplus off

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
    void fn_800B3194(void);

    s8 *str;
    s8 *b;
    s8 *a;
    s8 ca;
    s32 i;

    str = (s8 *)(lbl_80276BC8 + 0x8a);
    i = 0;
    do {
        Entry *entry = (Entry *)(gSeCueSlots + i * 0x30);
        if (entry->flags & 1) {
            a = str;
            b = (s8 *)*entry->names;
            goto loop;
        loop:
            ca = *a;
            if (ca == 0) {
                if ((s8)i >= 0) {
                    Obj *obj = (Obj *)(gSeCueSlots + (s8)i * 0x30);
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
extern u8 lbl_80276BC8[];
s8 *str=(s8*)lbl_80276BC8+0x8a;
s32 i;
for(i=0;i<28;i++){
if(gSeCueSlots[i*0x30+0xc]&1){
s8 *b=**(s8***)(gSeCueSlots+i*0x30);
s8 *a=str;
while(*b){
if(!*a)return 1;
if(*a++ != *b++)break;
}
}
}
return 0;
}

void fn_801453F0(void) {
    void Process_UnlinkByKey(void *);
    void *Process_Create(void *, s32);
    extern u8 gBgmVolFadeProcs[];
    extern u8 gBgmVol;
    extern const f32 gBgmVolTimerZero;
    extern const f32 lbl_8036A77C;
    s32 base;
    u8 *p;

    base = (s32)gBgmVolFadeProcs;
    Process_UnlinkByKey((void *)(base + 0x28));
    Process_UnlinkByKey((void *)(base + 0x3C));
    Process_UnlinkByKey((void *)(base + 0x50));
    Process_UnlinkByKey((void *)(base + 0x64));
    Process_UnlinkByKey((void *)(base + 0x78));
    Process_UnlinkByKey((void *)(base + 0x8C));
    p = (u8 *)Process_Create((void *)(base + 0x8C), 3);
    *(f32 *)(p + 0x30) = gBgmVolTimerZero;
    *(f32 *)(p + 0x34) = lbl_8036A77C;
    *(f32 *)(p + 0x38) = (f32)gBgmVol;
}

void fn_80145488(void) {
 void Process_UnlinkByKey(void *); void *Process_Create(void *,s32);
 extern u8 gBgmVolFadeProcs[]; extern u8 gBgmVol;
 extern const f32 gBgmVolTimerZero; extern f32 lbl_8036A77C;
 s32 base=(s32)gBgmVolFadeProcs; f32 *proc;
 f32 a; f32 b; f32 c; u32 vol;
 Process_UnlinkByKey((void *)(base+0x28)); Process_UnlinkByKey((void *)(base+0x3C));
 Process_UnlinkByKey((void *)(base+0x50)); Process_UnlinkByKey((void *)(base+0x64));
 Process_UnlinkByKey((void *)(base+0x78)); Process_UnlinkByKey((void *)(base+0x8C));
 proc=Process_Create((void *)(base+0x78),3);
 a=gBgmVolTimerZero; b=lbl_8036A77C;
 proc[12]=a; proc[13]=b;
 vol=gBgmVol; c=(f32)vol; proc[14]=c;
}

void fn_80145520(void) {
    void Process_UnlinkByKey(void *);
    void *Process_Create(void *, s32);
    extern u8 gBgmVolFadeProcs[];
    extern u8 gBgmVol;
    extern const f32 gBgmVolTimerZero;
    extern const f32 lbl_8036A77C;
    s32 base;
    u8 *p;

    base = (s32)gBgmVolFadeProcs;
    Process_UnlinkByKey((void *)(base + 0x28));
    Process_UnlinkByKey((void *)(base + 0x3C));
    Process_UnlinkByKey((void *)(base + 0x50));
    Process_UnlinkByKey((void *)(base + 0x64));
    Process_UnlinkByKey((void *)(base + 0x78));
    Process_UnlinkByKey((void *)(base + 0x8C));
    p = (u8 *)Process_Create((void *)(base + 0x64), 3);
    *(f32 *)(p + 0x30) = gBgmVolTimerZero;
    *(f32 *)(p + 0x34) = lbl_8036A77C;
    *(f32 *)(p + 0x38) = (f32)gBgmVol;
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
    void Process_UnlinkByKey(void *);
    void *Process_Create(void *, s32);
    extern u8 gBgmVolFadeProcs[];
    extern u8 gBgmVol;
    extern const f32 gBgmVolTimerZero;
    extern const f32 lbl_8036A77C;
    s32 base;
    u8 *p;

    base = (s32)gBgmVolFadeProcs;
    Process_UnlinkByKey((void *)(base + 0x28));
    Process_UnlinkByKey((void *)(base + 0x3C));
    Process_UnlinkByKey((void *)(base + 0x50));
    Process_UnlinkByKey((void *)(base + 0x64));
    Process_UnlinkByKey((void *)(base + 0x78));
    Process_UnlinkByKey((void *)(base + 0x8C));
    p = (u8 *)Process_Create((void *)(base + 0x3C), 3);
    *(f32 *)(p + 0x30) = gBgmVolTimerZero;
    *(f32 *)(p + 0x34) = lbl_8036A77C;
    *(f32 *)(p + 0x38) = (f32)gBgmVol;
}

void fn_8014571C(void) {
    void Process_UnlinkByKey(void *);
    void *Process_Create(void *, s32);
    extern u8 gBgmVolFadeProcs[];
    extern u8 gBgmVol;
    extern const f32 gBgmVolTimerZero;
    extern const f32 lbl_8036A77C;
    s32 base;
    u8 *p;

    base = (s32)gBgmVolFadeProcs;
    Process_UnlinkByKey((void *)(base + 0x28));
    Process_UnlinkByKey((void *)(base + 0x3C));
    Process_UnlinkByKey((void *)(base + 0x50));
    Process_UnlinkByKey((void *)(base + 0x64));
    Process_UnlinkByKey((void *)(base + 0x78));
    Process_UnlinkByKey((void *)(base + 0x8C));
    p = (u8 *)Process_Create((void *)(base + 0x28), 3);
    *(f32 *)(p + 0x30) = gBgmVolTimerZero;
    *(f32 *)(p + 0x34) = lbl_8036A77C;
    *(f32 *)(p + 0x38) = (f32)gBgmVol;
}

void fn_801457B4(void) {
    void Process_UnlinkByKey(void *);
    void *Process_Create(void *, s32);
    extern u8 gBgmVolFadeProcs[];
    extern u8 lbl_8029256C[];
    extern u8 gBgmQuietVol;
    extern const f32 gBgmVolTimerZero;
    extern const f32 lbl_8036A77C;
    u8 *p;

    Process_UnlinkByKey(gBgmVolFadeProcs);
    Process_UnlinkByKey(lbl_8029256C);
    p = (u8 *)Process_Create(lbl_8029256C, 3);
    *(f32 *)(p + 0x30) = gBgmVolTimerZero;
    *(f32 *)(p + 0x34) = lbl_8036A77C;
    *(f32 *)(p + 0x38) = (f32)gBgmQuietVol;
}

typedef struct BgmFadeFields { u8 pad[0x30]; f32 timer, duration, volume; } BgmFadeFields;
void fn_80145828(void) {
    void Process_UnlinkByKey(void *);
    void *Process_Create(void *, s32);
    extern u8 gBgmVolFadeProcs[];
    extern u8 lbl_8029256C[];
    extern u8 gBgmQuietVol;
    extern const f32 gBgmVolTimerZero;
    extern const f32 lbl_8036A77C;
    u8 *p;

    Process_UnlinkByKey(gBgmVolFadeProcs);
    Process_UnlinkByKey(lbl_8029256C);
    p = (u8 *)Process_Create(gBgmVolFadeProcs, 3);
    *(f32 *)(p + 0x30) = gBgmVolTimerZero;
    *(f32 *)(p + 0x34) = lbl_8036A77C;
    *(f32 *)(p + 0x38) = (f32)gBgmQuietVol;
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
    void *Hash_Lookup(void *);
    s32 Str_Cmp(void *, void *);
    s32 count;
    u8 *entry;
    s32 matches;
    s32 index;
    s32 *p;

    p = (s32 *)Hash_Lookup(lbl_80276BC8 + 0x9D);
    count = *p++;
    entry = (u8 *)p;
    matches = 0;
    index = 0;
    while (index < count) {
        if (*(void **)entry && Str_Cmp(*(void **)entry, arg0) == 0) {
            *arg1++ = entry;
            matches++;
        }
        index++;
        entry += 0x10;
    }
    return matches;
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
void *fn_80145FE8(void) {
    u8 EventFlag_IsSet(void *, void *, void *);
    void *fn_8014D8FC(void *, void *, void *);
    s32 Str_Cmp(void *, void *);
    extern u8 lbl_80276BC8[];
    extern u8 gBattleState[];
    extern u8 gBattle[];
    u8 *battle = gBattle;
    void *a;
    void *b;
    s32 var_r28;
    void *pa;
    void *pb;
    u8 state;

    pa = *(void **)(battle + 0x188);
    pb = *(void **)(battle + 0x468);
    a = *(void **)pa;
    b = *(void **)pb;
    state = *(u8 *)((u8 *)fn_8014D8FC(gBattleState, *(void **)(battle + 0x468), *(void **)(battle + 0x188)) + 0x3C);
    var_r28 = state;
    if (var_r28 >= 0x32) {
        var_r28 = var_r28 - 0x32;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0xA6) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0xA6) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0xC3) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0xC3) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0xCF) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0xCF) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0xDA) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0xDA) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0xE7) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0xE7) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0xF2) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0xF2) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0xFD) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0xFD) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x109) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x109) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x114) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x114) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x11F) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x11F) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x12C) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x12C) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x139) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x139) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x146) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x146) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x150) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x150) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x15B) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x15B) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if (((Str_Cmp(a, lbl_80276BC8 + 0x168) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x168) == 0)) && (var_r28 == 0x10)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x173) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x173) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x17F) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x17F) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x18A) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x18A) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x197) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x197) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x1A1) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x1A1) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x1AD) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x1AD) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if (((Str_Cmp(a, lbl_80276BC8 + 0x1B9) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x1B9) == 0)) && (var_r28 == 0x16)) {
        return lbl_80276BC8 + 0x1C1;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x1CF) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x1CF) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x1DB) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x1DB) == 0)) {
        return lbl_80276BC8 + 0x1C1;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x1E6) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x1E6) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x1F3) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x1F3) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x201) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x201) == 0)) {
        return lbl_80276BC8 + 0x1C1;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x20F) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x20F) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x21C) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x21C) == 0) ||
        (Str_Cmp(a, lbl_80276BC8 + 0x22C) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x22C) == 0) ||
        (Str_Cmp(a, lbl_80276BC8 + 0x240) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x240) == 0)) {
        return lbl_80276BC8 + 0x254;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x269) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x269) == 0)) {
        return lbl_80276BC8 + 0xB5;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x274) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x274) == 0)) {
        return lbl_80276BC8 + 0x1C1;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x280) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x280) == 0)) {
        return lbl_80276BC8 + 0x28C;
    }
    if ((Str_Cmp(a, lbl_80276BC8 + 0x2A2) == 0) || (Str_Cmp(b, lbl_80276BC8 + 0x2A2) == 0)) {
        if (EventFlag_IsSet(gBattleState + 0xB4, lbl_80276BC8 + 0x2AF, gBattleState) == 0) {
            return lbl_80276BC8 + 0x2C4;
        }
        return lbl_80276BC8 + 0x28C;
    }
    if (*(u8 *)(*(u8 **)(battle + 0x190) + 8) == 0) {
        if (var_r28 < 0x13) {
            return lbl_80276BC8 + 0x2D7;
        }
        return lbl_80276BC8 + 0x2E4;
    }
    if (var_r28 < 0x13) {
        return lbl_80276BC8 + 0x2F1;
    }
    return lbl_80276BC8 + 0x2FE;
}
#pragma pop
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
    table = (s32 *)((s32)table + 4);
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

#pragma push
#pragma opt_lifetimes off
#pragma opt_propagation off
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
    u8 *p;
    s32 i;
    u8 *base;

    base = gFxChannels;
    p = base + 0;
    for (i = 0; i < 4; i++, p += 0x30) {
        fn_801490C8(p);
    }
    for (i = 0, p = base + 0xC0; i < 0xA; i++, p += 0x30) {
        fn_80148D54(p);
    }
    for (i = 0, p = base + 0x2A0; i < 0x1C; i++, p += 0x30) {
        fn_80148A28(p);
    }

    lbl_80367AE9 = lbl_80367AE8;
    lbl_80367AEB = lbl_80367AEA;
    lbl_80367AED = gBgmQuietVol;
    lbl_80367AEF = gBgmVol;

    if (lbl_80367AF0 > lbl_80367AF2) {
        lbl_80367AF1 = lbl_80367AF0;
        lbl_80367AF0--;
        if (lbl_80367AF0 < lbl_80367AF2)
            lbl_80367AF0 = lbl_80367AF2;
    }
    if (lbl_80367AF0 < lbl_80367AF2) {
        lbl_80367AF1 = lbl_80367AF0;
        lbl_80367AF0++;
        if (lbl_80367AF0 > lbl_80367AF2)
            lbl_80367AF0 = lbl_80367AF2;
    }
    if (lbl_80367AF3 > lbl_80367AF5) {
        lbl_80367AF4 = lbl_80367AF3;
        lbl_80367AF3--;
        if (lbl_80367AF3 < lbl_80367AF5)
            lbl_80367AF0 = lbl_80367AF5;
    }
    if (lbl_80367AF3 < lbl_80367AF5) {
        lbl_80367AF4 = lbl_80367AF3;
        lbl_80367AF3++;
        if (lbl_80367AF3 > lbl_80367AF5)
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
#pragma pop
#pragma cplusplus reset
#pragma use_lmw_stmw reset

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
    u32 next;
    u8 offset;

    value = 0xF00000 - fn_800C44F4(-1);
    fn_800B36D8((char *)lbl_80276BC8 + 0x326);
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
#pragma push
#pragma optimization_level 4
#pragma opt_strength_reduction off
#pragma opt_common_subs off
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
    s32 j;
    Entry *base;
    s32 ext;
    s32 idx;
    s8 *str;
    s8 *a;
    s8 *b;
    s8 ca;
    s32 temp;

    base = gFxChannels;
    i = 0;
    p = base + 0;
    ext = (s16)arg0;
    do {
        if (p->flags & 1) {
            if ((s16)arg0 <= 0) {
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

    j = 0;
    p = (Entry *)((u8 *)base + 0xc0);
    do {
        if (p->flags & 1) {
            if ((s16)arg0 <= 0) {
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
        j += 1;
        p += 1;
    } while (j < 0xa);

    {
        Entry *w;
        p = (Entry *)((u8 *)base + 0x2a0);
        i = 0;
        w = p;
        do {
            if (w->flags & 1) {
                if ((s16)arg0 <= 0) {
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
                temp = (s8)idx;
                if (temp >= 0) {
                    temp = temp * 0x30;
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
#pragma pop

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
    i = 0;
    p = gFxChannels;
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
    extern u8 gFxChannels[];
    extern f32 gMsPerFrame;
    s16 raw;
    s32 a;
    unsigned int temp;
    u8 *p;
    register s32 i;
    s16 val;
    u8 flags;

    raw = arg0;
    a = raw;
    p = gFxChannels;
    i = 0;
    do {
        flags = *(u8 *)(p + 0xC);
        if (flags & 1) {
            if (0 >= raw) {
                ((Obj *)p)->v2();
            } else if (!(flags & 8)) {
                temp = (s32)((f32)a / gMsPerFrame);
                val = (s16)temp;
                if (0 >= val) {
                    val = 1;
                }
                *(u8 *)(p + 0x28) = *(u8 *)(p + 0x16);
                *(u8 *)(p + 0x29) = 0;
                *(s16 *)(p + 0x2E) = val;
                *(s16 *)(p + 0x2C) = 0;
                *(u8 *)(p + 0xC) = (u8)(*(u8 *)(p + 0xC) | 8);
            }
        }
        ++i;
        p += 0x30;
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
    s32 Fx_StartSlot(u8, void *, s32, void *);

    u8 active;
    s32 i;
    Entry *entry;
    Entry *base;
    u32 h1;
    s8 slot;
    s8 freeSlot;

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
    entry = gFxChannels;
    for (i = 0; i < 4; i++) {
        if (!(entry->flags & 1)) {
            freeSlot = i;
            goto found_free;
        }
        entry = (Entry *)((u8 *)entry + 0x30);
    }
    freeSlot = -1;
found_free:
    if (freeSlot == -1) {
        return -1;
    }
    return Fx_StartSlot(freeSlot, arg0, 0x64, arg1);
}

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma scheduling on
void fn_8014876C(void *arg0, s8 arg1, s16 arg2) {
    extern const f32 gMsPerFrame;
    s32 temp;
    s16 var_r6;

    temp = (s32)((f32)arg2 / gMsPerFrame);
    var_r6 = (s16)temp;
    if (var_r6 <= 0) {
        var_r6 = 1;
    }
    M2C_FIELD(arg0, u8 *, 0x28) = (u8)M2C_FIELD(arg0, u8 *, 0x16);
    M2C_FIELD(arg0, s8 *, 0x29) = arg1;
    M2C_FIELD(arg0, s16 *, 0x2E) = var_r6;
    M2C_FIELD(arg0, s16 *, 0x2C) = 0;
}
#pragma scheduling reset
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

