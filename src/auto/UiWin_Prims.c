/* Functions from 0x8005AE20 to 0x80072408, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
#pragma cplusplus on
struct UiSelectionHandler {
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
virtual void select(void *, void *) = 0;
virtual void deselect(void *, void *) = 0;
};
#pragma cplusplus reset

typedef struct MaterialColor { u8 r, g, b, a; } MaterialColor;


static inline u8 *GActor_FindAnimation(u8 *p) {
    while (p) {
        u8 *anim = *(u8 **)(p + 0x44);
        if (anim) return anim;
        p = *(u8 **)(p + 4);
    }
    return 0;
}

typedef struct {
    s32 at0[16];
    s32 at40[8];
    s32 at60[8];
    s32 at80[16];
} StagePool;

// Structure definition for the argument passed to fn_80063A14
typedef struct {
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkC;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    s32 unk34;
} SomeStruct;

struct UnkStruct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

extern u16 gBattleState[1400];
extern f32 lbl_803692E0;
extern f32 lbl_80369300;
extern f32 lbl_8036930C;
extern f64 lbl_803692C0;
extern f32 lbl_803692B8;
extern u16 lbl_80285D18[];
extern char lbl_8026B590[];
extern f32 lbl_803691E0;
extern f32 lbl_803691E4;
extern f32 lbl_803691E8;
extern u8 lbl_8026B658[];

static inline u8 *FindEntryByName(char *name) {
    extern u8 gFileCache[];
    s32 Str_Cmp();
    u8 *e;
    char *start;
    u32 hash;
    s32 i;

    if (*name == '/') {
        name++;
    }
    start = name;
    hash = 0;
    while (*name != 0) {
        if (*name >= 'A' && *name <= 'Z') {
            *name += 0x20;
        }
        hash = *name++ + hash * 37;
    }
    for (i = 0, e = gFileCache; i < 0x400; i++, e += 0x7C) {
        if (hash == *(u32 *)(e + 0x2C) && Str_Cmp(start, e) == 0) {
            return gFileCache + i * 0x7C;
        }
    }
    return NULL;
}

static inline u32 FindUnk48(void *arg0) {
    u32 temp;
    void *current = arg0;
    while (current != NULL) {
        temp = M2C_FIELD(current, u32 *, 0x48);
        if (temp != 0U) {
            return temp;
        }
        current = M2C_FIELD(current, void **, 4);
    }
    return 0U;
}

static inline u32 CalcUnk48Size(u32 found) {
    s16 t = M2C_FIELD(M2C_FIELD(found, void **, 0x48), s16 *, 0xA);
    return (((t * 12) + 31) & ~31) / 2 * 2;
}

static inline u32 AddUnk48Size(u32 base, void *node) {
    void *current = node;

    while (current != NULL) {
        u32 temp = M2C_FIELD(current, u32 *, 0x48);
        if (temp != 0U) {
            return base + CalcUnk48Size(temp);
        }
        current = M2C_FIELD(current, void **, 4);
    }
    return base + CalcUnk48Size(0);
}

#pragma use_lmw_stmw on

#pragma use_lmw_stmw off

#pragma global_optimizer off

static inline u32 HashString(u8 *s) {
    u32 hash;
    u8 b;
    hash = 0;
    while ((b = *s, (s8)b != 0)) {
        hash += b;
        s++;
        hash <<= 4;
    }
    return hash;
}

static inline u32 ColFromHash(u32 hash) {
    extern u32 lbl_802F03A8[0x4D];
    u32 *p;
    s32 i;
    s32 ctr;
    p = lbl_802F03A8;
    i = 0;
    for (ctr = 0x4D; ctr != 0; ctr--) {
        if (hash == *p) {
            switch (i) {
            case 9:
            case 0x21:
                return 0x1C;
            default:
                return (u8)i;
            }
        }
        p++;
        i++;
    }
    return 0;
}

#pragma use_lmw_stmw on

#pragma optimization_level reset
#pragma use_lmw_stmw off

#pragma optimization_level 4

#pragma optimization_level reset

extern void *lbl_803672F4;

/* Return whether the named file is ready: load-done (0x2000) or absent (0x8000). */

void fn_8005C8D8();

/* Forever drain the FileCache async work ring, sleeping when empty. */

/* After DVD load: optionally start ARAM DMA (flag 8), else expand buffer / spawn archive children and mark load-done. */

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
/* Return the byte size of the named file-cache entry, or 0 if absent. */

/* Return 1 if a file-cache entry with this name exists, else 0. */

#pragma no_register_save_helpers on
#pragma use_lmw_stmw on

/* Mark the named file-cache entry as relocated (flags |= 0x4000). */

#pragma opt_common_subs off

#pragma opt_common_subs reset

#pragma global_optimizer off

#pragma global_optimizer on
void FileCache_Release(u8 *);
/* Look up a file-cache entry by path/name and release it. */

#pragma global_optimizer off

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma global_optimizer reset
/* Drop one ref on a file-cache entry; when the count hits zero, cancel loads, wait, and free it. */

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer on

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma dont_inline on

#pragma dont_inline reset

#pragma use_lmw_stmw reset

#pragma dont_inline reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma peephole off

#pragma peephole on

extern u32 fn_80065E88(s32, s32);
extern void fn_80065E68(void);

#pragma global_optimizer off
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma global_optimizer reset
static inline u32 GetListField44(void *p) {
    while (p != NULL) {
        u32 v = *(u32 *)((u8 *)p + 0x44);
        if (v != 0) {
            return v;
        }
        p = *(void **)((u8 *)p + 4);
    }
    return 0;
}

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma inline_depth(8)
#pragma scheduling off

#pragma inline_max_size(48)
#pragma scheduling on
#pragma auto_inline off

#pragma auto_inline reset
#pragma inline_max_size reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma opt_common_subs off

#pragma opt_common_subs reset
static inline void *GActor_FindNode_Model(void *p) {
    for (; p; p = M2C_FIELD(p, void **, 4)) {
        void *v = M2C_FIELD(p, void **, 0x40);
        if (v) return v;
    }
    return 0;
}

void fn_800062CC(void *, void *, s32);
void fn_800062EC(void *, void *, s32);
void fn_80062920(void *, s32, f32 *, u8 *, void *, void *);
void fn_80063614(void *, void *, s16, f32 *, f32);
void QUATMtx(f32 *, void *);
void QUATSlerp(f32 *, f32 *, f32 *, f32);
#pragma inline_depth(0)

#pragma inline_depth(8)

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma inline_depth(8)

static inline void *fn_800639B4_Body(void *res, char *p) {
    M2C_UNK fn_80063A14(M2C_UNK);
    if (!(FileCache_GetFlags(p) & 0x4000)) {
        fn_80063A14((M2C_UNK)res);
        FileCache_MarkRelocated(p);
    }
    return res;
}
#pragma cplusplus on
extern "C" void fn_80063A14(SomeStruct *);

#pragma inline_depth(0)
#pragma cplusplus off

extern f32 lbl_803691E4;
extern f32 lbl_8036920C;

void FileCache_Load(s32);

#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma optimization_level 2
/* Walk a node chain and accumulate each node's euler rotations (degrees) into out, using the node's axis order. */

#pragma optimization_level 4
#pragma inline_depth(3)
#pragma use_lmw_stmw on

#pragma optimization_level reset

#pragma optimization_level 4

#pragma inline_depth(0)

static inline void *fn_80065EE8_Body(void *res, char *p) {
    void fn_80065F48(void *);
    if (!(FileCache_GetFlags(p) & 0x4000)) {
        fn_80065F48(res);
        FileCache_MarkRelocated(p);
    }
    return res;
}
#pragma inline_depth(4)

#pragma inline_depth(0)

#pragma optimization_level 2

#pragma optimization_level reset

#pragma optimization_level 3

#pragma optimization_level reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma scheduling off

#pragma scheduling reset

#pragma peephole off

#pragma peephole on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma global_optimizer reset

// Build default 640x480 ortho, reset view/pos matrices, and apply camera scissor/viewport/projection to GX.

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma use_lmw_stmw on

#pragma opt_loop_invariants off

/* Set GX cull mode from material mirror flag (0x1000) and node cull bits (0x1800). */

#pragma use_lmw_stmw on

/* Compute material color/alpha and bind it to GX channel + optional TEV stages. */

#pragma global_optimizer off
#pragma push
#pragma optimization_level 4

#pragma pop
#pragma global_optimizer off

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer on

extern u16 gMaterialStageIds[0x20];

#pragma global_optimizer off

#pragma global_optimizer on

#pragma use_lmw_stmw on
#pragma inline_depth(3)


#pragma use_lmw_stmw on

void GXSetCullMode(s32);
void GXClearVtxDesc(void);
void GXSetVtxDescv(s32 *);
void GXSetVtxAttrFmtv(s32, s32 *);
/* Build GX vtx-desc and attr-fmt lists from format flags, then apply them. */

#pragma global_optimizer off
#pragma fp_contract off

#pragma optimization_level 4
#pragma fp_contract on
#pragma global_optimizer reset

#pragma use_lmw_stmw on

/* Apply GX blend, Z-mode, and channel-update state from a material's flag word. */

#pragma optimization_level 1

#pragma optimization_level reset

#pragma use_lmw_stmw on

#pragma optimization_level 3

#pragma optimization_level reset

/* True if s contains _pat_ (or, if pat is null, if s is _..._). Used by GActor_FindNode. */

#pragma use_lmw_stmw on
/* Set up GX fifos and VI render mode; reuse existing demo XFB pointers. */

#pragma use_lmw_stmw reset

extern s32 gDemoStatEnable;
extern u32 gDemoStatHangLimit;
extern s32 gDvdCheckSnapshot;
extern f32 lbl_803692C8;
extern f64 lbl_803692D0;
extern f32 lbl_803692CC;
/* Enable DEMO GP hang stats (non-zero limit) or disable them (0); program GX FIFO for the overlay. */

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer off

#pragma global_optimizer reset
extern void FileCache_ReleaseByKey(u32);

#pragma global_optimizer off

#pragma global_optimizer off
#pragma opt_strength_reduction off

#pragma opt_strength_reduction on
#pragma global_optimizer on

#pragma global_optimizer off

void fn_8006F170(void *arg0, void *arg1, void *arg2) {
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32,f32);
    void Prim2D_SetColor(s32,s32,s32,s32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    s32 Text_MeasureHeight(s32,f32);
    extern f32 lbl_803692E0;
#pragma cplusplus on
    struct Model {
        u8 pad[4];
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
        virtual s32 height()=0;
    };
    struct Item {
        virtual void v0()=0;
        virtual void *text()=0;
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
        virtual void setup(void *)=0;
    };
    f32 x;
    f32 y;
    s32 height;
    Model *model;
    model=M2C_FIELD(arg1,Model **,0x3C);
    x=(f32)M2C_FIELD(arg2,s16 *,0x30);
    height=(s16)model->height();
    y=(f32)(M2C_FIELD(arg2,s16 *,0x32)+((height-Text_MeasureHeight(-1,lbl_803692E0))>>1));
    ((Item *)arg0)->setup(arg1);
    Prim2D_AddPrim(6);
    Prim2D_SetPos(x,y);
    Prim2D_SetColor(0,0,0,255);
    Prim2D_SetText(((Item *)arg0)->text());
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_803692E0);
    Prim2D_PrepareTex();
#pragma cplusplus reset
}

#pragma global_optimizer reset
s32 fn_8006F2B8(s32 arg0, s32 arg1) {
    M2C_UNK fn_80121630(s32);
    fn_80121630(arg1);
    return 0;
}

s32 fn_8006F2E0(void *arg0, void *arg1, void *arg2) {
    extern u8 lbl_80366DE8;
    lbl_80366DE8 = *(u8 *)((u8 *)arg2 + 0x3A);
    return 5;
}

#pragma cplusplus on
extern "C" void fn_8006F2F0(void *arg0) {
    void fn_8008B09C(s32, s32, s16, s16);
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
        virtual s32 v18() = 0;
        virtual s32 v19() = 0;
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
    };
    s16 t;
    ((Obj *)arg0)->v29();
    t = (s16)((Obj *)arg0)->v19();
    fn_8008B09C(0, 0, (s16)((Obj *)arg0)->v18(), t);
}
#pragma cplusplus reset

s32 fn_8006F370(void) {
    return 0;
}

void fn_8006F378(void) {
    M2C_UNK fn_80024DE4();
    fn_80024DE4();
}

void fn_8006F398(void *arg0, void *arg1) {
    void *GfxEnt_Get(s32);
    s32 Text_MeasureHeight(s32, f32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Ui_DrawRouteIconEx(s32, s32, s32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    extern f32 lbl_803692E0, lbl_803692F0, lbl_803692F4;
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
        virtual s16 v20() = 0;
    };
    u8 *self = (u8 *)arg0;
    u8 *obj = (u8 *)arg1;
    s16 sx;
    s16 sy;
    s32 height;
    s32 iconX;
    s32 iconY;
    s32 pulse;
    s16 w;
    s16 h;

    sx = *(s16 *)((u8 *)GfxEnt_Get(obj[*(s8 *)(obj + 0x62) + 0x40]) + 0x30) - 0x10;
    sy = *(s16 *)((u8 *)GfxEnt_Get(obj[*(s8 *)(obj + 0x62) + 0x40]) + 0x32);
    height = (s16)((Obj *)arg0)->v20();
    sy += (height - Text_MeasureHeight(-1, lbl_803692E0)) >> 1;

    if (*(s16 *)(obj + 0x3A) < 0) {
        *(s16 *)(obj + 0x38) = sx;
        *(s16 *)(obj + 0x3A) = sy;
    } else {
        *(s16 *)(obj + 0x38) = (*(s16 *)(obj + 0x38) + sx) / 2;
        *(s16 *)(obj + 0x3A) = (*(s16 *)(obj + 0x3A) + sy) / 2;
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_803692F0);
    Prim2D_PrepareTex();

    iconX = *(s16 *)(obj + 0x38);
    iconY = *(s16 *)(obj + 0x3A);
    pulse = 0;
    if (!obj[0x2D] && !obj[0x2E]) {
        pulse = 1;
    }
    Ui_DrawRouteIconEx(iconX, iconY, pulse);

    w = *(s16 *)(self + 0xC) + 0x40;
    h = Text_MeasureHeight(-1, lbl_803692E0);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_803692F4);
    Prim2D_PrepareTex();
    fn_8008AB7C(*(s16 *)(obj + 0x38) + (w >> 1) - 0x10, *(s16 *)(obj + 0x3A) + (h >> 1), w, 0x18, 0x19, 0x4B, 1);
#pragma cplusplus reset
}

#pragma cplusplus on
extern "C" void fn_8006F514(void *arg0) {
    void Ui_DrawMsgPanelBg(s32, s32);
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
    };
    ((Obj *)arg0)->v29();
    Ui_DrawMsgPanelBg(0, 0);
}

extern "C" void fn_8006F54C(void *arg0, void *arg1) {
#pragma cplusplus off
    void *GfxEnt_Get(u8);
    s32 Text_MeasureWidth(void *, s32, f32);
#pragma cplusplus reset
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
        virtual s16 v19() = 0;
        virtual s16 v20() = 0;
    };
    struct TextObj {
        virtual void v0() = 0;
        virtual void *v1() = 0;
    };
    struct Group {
        u8 pad[0x40];
        u8 ids[0x20];
        s8 count;
        inline s8 GetCount() { return count; }
    };
    u8 *self = (u8 *)arg0;
    Group *group = (Group *)arg1;
    s16 height;
    s32 i;
    s16 x;
    s32 y;

    *(s16 *)(self + 0xC) = 0;
    height = group->GetCount() * ((Obj *)arg0)->v20();
    for (i = 0; i < group->count; i++) {
        TextObj *obj = *(TextObj **)((u8 *)GfxEnt_Get(group->ids[i]) + 0x34);
        s16 width = Text_MeasureWidth(obj->v1(), -1, 1.0f);
        if (width >= *(s16 *)(self + 0xC)) {
            *(s16 *)(self + 0xC) = width;
        }
    }
    *(s16 *)(self + 0xE) = (((Obj *)arg0)->v18() - *(s16 *)(self + 0xC)) >> 1;
    *(s16 *)(self + 0x10) = (((Obj *)arg0)->v19() - height) >> 1;
    x = *(s16 *)(self + 0xE);
    y = *(s16 *)(self + 0x10);
    for (i = 0; i < group->count;) {
        u8 *ent;
        ent = (u8 *)GfxEnt_Get(group->ids[i]);
        *(s16 *)(ent + 0x30) = x;
        ent = (u8 *)GfxEnt_Get(group->ids[i]);
        *(s16 *)(ent + 0x32) = y;
        i++;
        y += ((Obj *)arg0)->v20();
    }
}

#pragma cplusplus reset
void fn_8006F6A4(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    extern u32 lbl_80311CE0[];
    extern s8 lbl_80366DE8;
    extern u32 lbl_80367350[2];
    extern u32 lbl_80367358[2];

    lbl_80366DE8 = -1;
    if (arg1 != 0U) {
        lbl_80311CE0[3] = arg1;
    }
    if (arg2 != 0U) {
        lbl_80367350[1] = arg2;
    }
    if (arg3 != 0U) {
        lbl_80367358[1] = arg3;
    }
    Ui_CreateMenu(lbl_80311CE0, arg0, 0);
}

#pragma cplusplus on
/* Begin Prim2D for a UiWin: transform, fade-tinted color, and lock/pause alpha. */
extern "C"
void UiWin_SetupPrim2D(void *unused, void *win) {
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    f32 UiWin_GetFade(void *);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetAlphaByte(u8);
    struct Model {
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
        virtual f32 v25() = 0;
    };
    extern f32 lbl_803692E0;
    extern f32 lbl_803692F8;
    s32 idle;
    s32 alpha;

    Prim2D_Begin();
    Prim2D_SetTransform((f32)M2C_FIELD(win, s16 *, 0x30), (f32)M2C_FIELD(win, s16 *, 0x32),
                M2C_FIELD(win, Model **, 0x3C)->v25(), lbl_803692E0);
    Prim2D_SetColorByte((s32)(lbl_803692F8 * UiWin_GetFade(win)));
    idle = 0;
    if ((u8)M2C_FIELD(win, u8 *, 0x2D) == 0 && (u8)M2C_FIELD(win, u8 *, 0x2E) == 0) {
        idle = 1;
    }
    alpha = 0x58;
    if ((u8)idle != 0) {
        alpha = 0x80;
    }
    Prim2D_SetAlphaByte((u8)alpha);
    Prim2D_PrepareTex();
}
#pragma cplusplus reset

#pragma optimization_level 2
void fn_8006F7F0(void *arg0)
{
    void Ui_DrawMsgPanelAlt(s32, s32);
    void *Heap_AllocRaw(u32);
    void Heap_FreeRaw(void *);
    u32 strlen(const char *);
    char *strcpy(char *, const char *);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    s32 Text_MeasureHeight(s32, f32);
    extern f64 lbl_803692E8;
    extern f32 lbl_803692E0;
    extern f32 lbl_803692FC;
    extern f32 lbl_80369300;
    char *buf;
    char *p;
    void *self;
    char *line;
    f32 posX;
    f32 posY;
    s32 lineIndex;
    char c;
#pragma cplusplus on
    struct Obj {
        u8 pad[4];
        virtual char *v0() = 0;
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
    };

    self = arg0;
    ((Obj *)self)->v29();
    Ui_DrawMsgPanelAlt(0, 0);
    buf = (char *)Heap_AllocRaw(strlen(((Obj *)self)->v0()) + 1);
    line = buf;
    strcpy(buf, ((Obj *)self)->v0());
    posX = (f32)*(s16 *)((u8 *)self + 0x10);
    posY = lbl_803692FC;
    lineIndex = 0;
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369300);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    for (p = buf; (c = *p) != 0; p++) {
        if ((s8)c == 0xA) {
            *p = 0;
            Prim2D_AddPrim(6);
            Prim2D_SetPos(posX, posY);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_SetText(line);
            Prim2D_EndPrim();
            lineIndex++;
            posX = (f32)*(s16 *)((u8 *)self + 0x10 + (s16)lineIndex * 2);
            posY += (f32)(Text_MeasureHeight(-1, lbl_803692E0) + 2);
            line = p + 1;
        }
    }
    Prim2D_AddPrim(6);
    Prim2D_SetPos(posX, posY);
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_SetText(line);
    Prim2D_EndPrim();
    Heap_FreeRaw(buf);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_803692E0);
    Prim2D_PrepareTex();
#pragma cplusplus reset
}
#pragma optimization_level reset
#pragma push
void fn_8006F9F4(void *arg0, void *arg1) {
    void *GfxEnt_Get(u8);
    s32 Text_MeasureWidth(void *, s32, f32);
    s32 fn_80010428(u8 **, s32, f32);
    extern f32 lbl_803692E0;
#pragma cplusplus on
    struct Obj {
        u8 pad[4];
        virtual void *v0() = 0;
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
        virtual s16 v18() = 0;
    };
    struct TextObj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void *v4(void *) = 0;
    };
    u8 *group;
    u8 *self;
    s16 y;
    s32 c;
    s16 step;
    s32 i;
    s32 t26;
    s32 j;
    s16 lineW;
    s32 lineIdx;
    u8 *text;
    s16 w;
    u8 ch;

    i = 0;
    self = (u8 *)arg0;
    group = (u8 *)arg1;
    *(s16 *)((u8 *)arg0 + 8) = i;
    goto check1;
loop1:
    w = (s16)Text_MeasureWidth(
        (*(TextObj **)((u8 *)GfxEnt_Get(group[i + 0x40]) + 0x34))->v4(GfxEnt_Get(group[i + 0x40])),
        -1, lbl_803692E0);
    if (w >= *(s16 *)(self + 8)) {
        *(s16 *)(self + 8) = w;
    }
    i += 1;
check1:
    t26 = group[0x60];
    if (i < (s8)t26) {
        goto loop1;
    }
    w = ((Obj *)arg0)->v18();
    c = (s8)t26;
    step = (s16)((s32)w / (c + 1));
    t26 = step;
    y = ((Obj *)arg0)->v17();
    j = 0;
    goto check2;
loop2:
    {
        u8 *ent = (u8 *)GfxEnt_Get(group[j + 0x40]);
        *(s16 *)(ent + 0x30) = t26;
    }
    *(s16 *)((u8 *)GfxEnt_Get(group[j + 0x40]) + 0x32) = y;
    t26 = t26 + step;
    j += 1;
check2:
    if (j < c) {
        goto loop2;
    }
    lineW = 0;
    lineIdx = 0;
    text = (u8 *)((Obj *)arg0)->v0();
    while ((s8)(ch = *text) != 0) {
        switch ((s8)ch) {
        case 10: {
            s16 v = ((Obj *)arg0)->v18();
            s16 centered = (s16)(((s32)v - (s32)lineW) >> 1);
            lineW = 0;
            *(s16 *)(self + ((s32)(s16)lineIdx << 1) + 0x10) = centered;
            lineIdx += 1;
            text += 1;
            break;
        }
        default:
            lineW += fn_80010428(&text, -1, lbl_803692E0);
            break;
        }
    }
    ((s16 *)(self + 0x10))[(s16)lineIdx] = (((Obj *)arg0)->v18() - lineW) >> 1;
#pragma cplusplus reset
}
#pragma pop
