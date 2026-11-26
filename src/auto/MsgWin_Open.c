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

#pragma global_optimizer reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
/* Begin Prim2D for a UiWin: transform, fade-tinted color, and lock/pause alpha. */

#pragma cplusplus reset

void MsgWin_OpenMulti(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    extern u32 lbl_80311CB8[];
    extern s8 lbl_80366DE8;
    extern u32 lbl_80367350[2];
    extern u32 lbl_80367358[2];

    lbl_80366DE8 = -1;
    if (arg1 != 0U) {
        lbl_80311CB8[3] = arg1;
    }
    if (arg2 != 0U) {
        lbl_80367350[1] = arg2;
    }
    if (arg3 != 0U) {
        lbl_80367358[1] = arg3;
    }
    Ui_CreateMenu(lbl_80311CB8, arg0, 0);
}

void fn_8006FC50(void *arg0) {
    void Ui_DrawMsgPanelBg(s32, s32);
    void *Heap_AllocRaw(s32);
    void Heap_FreeRaw(void *);
    void strcpy(char *, char *);
    s32 strlen(char *);
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
    extern f32 lbl_803692E0;
    extern f64 lbl_803692E8;
    extern f32 lbl_803692FC;
    extern f32 lbl_80369300;
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
        virtual s32 v16() = 0;
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
    char *buf = 0;
    char *line = 0;
    Obj *self;
    char *p;
    f32 posX;
    f32 posY;
    char c;

    self = (Obj *)arg0;
    self->v29();
    Ui_DrawMsgPanelBg(0, 0);
    buf = (char *)Heap_AllocRaw(strlen(self->v0()) + 1);
    line = buf;
    strcpy(buf, self->v0());
    posX = (f32)(s16)self->v16();
    posY = lbl_803692FC;
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

#pragma push
#pragma opt_propagation off
void fn_8006FE44(void *arg0, void *arg1) {
    void *GfxEnt_Get(u8);
    s32 Text_MeasureWidth(void *, s32, f32);
    s32 fn_80010428(u8 **, s32, f32);
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
    s16 maxLine;
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
        -1, 1.0f);
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
    maxLine = -1;
    text = (u8 *)((Obj *)arg0)->v0();
    while ((s8)(ch = *text) != 0) {
        switch ((s8)ch) {
        case 10:
            if (lineW > maxLine) {
                maxLine = lineW;
            }
            lineW = 0;
            text += 1;
            break;
        default:
            lineW += fn_80010428(&text, -1, 1.0f);
            break;
        }
    }
    if (lineW > maxLine) {
        maxLine = lineW;
    }
    *(s16 *)(self + 0x10) = (s16)((((Obj *)arg0)->v18() - maxLine) >> 1);
#pragma cplusplus off
}
#pragma pop
void MsgWin_OpenSingle(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    extern u32 lbl_80311CA8[];
    extern s8 lbl_80366DE8;
    extern u32 lbl_80367350[2];
    extern u32 lbl_80367358[2];

    lbl_80366DE8 = -1;
    if (arg1 != 0U) {
        lbl_80311CA8[3] = arg1;
    }
    if (arg2 != 0U) {
        lbl_80367350[1] = arg2;
    }
    if (arg3 != 0U) {
        lbl_80367358[1] = arg3;
    }
    Ui_CreateMenu(lbl_80311CA8, arg0, 0);
}

void fn_80070084(void *arg0, void *arg1, void *arg2) {
void Prim2D_AddPrim(s32);
void Prim2D_SetPos(f32,f32);
void Prim2D_SetColor(s32,s32,s32,s32);
void Prim2D_SetText(void *);
void Prim2D_EndPrim(void);
void Prim2D_Begin(void);
void Prim2D_AddZ(f32);
void Prim2D_PrepareTex(void);
s32 Text_MeasureHeight(s32,f32);
s32 Text_MeasureWidth(void *,s32,f32);
#pragma cplusplus on
struct Model {u8 pad[4]; virtual void v0()=0;
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
virtual s16 v20()=0; };
struct Item {virtual void v0()=0;
virtual void * v1()=0;
virtual void v2()=0;
virtual void v3()=0;
virtual void * v4(void *)=0;
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
virtual void v17(void *)=0; };
f32 x;
s16 y;
s32 height;
x=(f32)(M2C_FIELD((short)arg2,s16 *,0x30)-(Text_MeasureWidth(((Item*)arg0)->v1(),-1,1.0f)>>1));
height=(s16)M2C_FIELD(arg1,Model **,0x3C)->v20();
y=M2C_FIELD(arg2,s16 *,0x32)+((height-Text_MeasureHeight(-1,1.0f))>>1);
((Item*)arg0)->v17(arg1);
Prim2D_AddPrim(6);
Prim2D_SetPos(x,(f32)y);
Prim2D_SetColor(0,0,0,255);
Prim2D_SetText(((Item*)arg0)->v4(arg2));
Prim2D_EndPrim();Prim2D_Begin();Prim2D_AddZ(1.0f);Prim2D_PrepareTex();
#pragma cplusplus reset
}

extern u8 lbl_80366DE9;
u8 fn_800701E0(s32 arg0, s32 arg1, u8 arg2) {
    extern u8 lbl_80366DE9;
    s8 temp = lbl_80366DE9;
    return (u8)(arg2 == temp);
}

void fn_800701FC(void *arg0) {
    void Ui_DrawMsgPanelBg(s32, s32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    s32 Text_MeasureWidth(void *, s32, f32);
    extern f32 lbl_80369304;
    extern f32 lbl_80369308;
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
        virtual void *v30() = 0;
    };
    Obj *self = (Obj *)arg0;
    s32 width;
    void *text;
    f32 posX;

    self->v29();
    Ui_DrawMsgPanelBg(0, 0);
    Prim2D_Begin();
    Prim2D_AddZ(-1.0f);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    width = (s16)self->v18();
    text = self->v0();
    posX = (f32)((width - Text_MeasureWidth(text, -1, 1.0f)) / 2);
    Prim2D_AddPrim(6);
    Prim2D_SetPos(posX, lbl_80369304);
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_SetText(self->v0());
    Prim2D_EndPrim();

    width = (s16)self->v18();
    text = self->v30();
    posX = (f32)((width - Text_MeasureWidth(text, -1, 1.0f)) / 2);
    Prim2D_AddPrim(6);
    Prim2D_SetPos(posX, lbl_80369308);
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_SetText(self->v30());
    Prim2D_EndPrim();
#pragma cplusplus reset
}

u32 fn_800703C4(void) {
    extern u8 lbl_80366DE8;

    lbl_80366DE8 = 0;
    return 9;
}

s32 fn_800703D4(void) {
    return 0;
}

#pragma cplusplus on
extern "C" void fn_800703DC(void *arg0, void *arg1) {
    extern u8 *gPadInput;
    extern char lbl_8026BB84[];

    void *GfxEnt_Get(u8);
    void Ui_PlaySeCue(void *, s32);

    u8 *self;
    u8 *entity;
    UiSelectionHandler *obj;
    u32 buttons;
    u8 index;
    s32 limit;
    s8 *p;

    self = (u8 *)arg1;
    buttons = *(u32 *)(gPadInput + 0xC);

    self[0x63] = self[0x62];

    index = self[0x62];

    if ((s8)index != 0 && (buttons & 0x01000001) != 0) {
        self[0x62] = index - 1;
    }

    index = self[0x62];
    limit = (s8)self[0x60];

    if ((s8)index != limit - 1 && (buttons & 0x02000002) != 0) {
        self[0x62]++;
    }

    p = (s8 *)(self + 0x62);
    if (p[0] != p[1]) {
        entity = (u8 *)GfxEnt_Get(self[0x40 + p[1]]);

        obj = *(UiSelectionHandler **)(entity + 0x34);
        obj->deselect(self, entity);

        entity = (u8 *)GfxEnt_Get(self[0x40 + (s8)self[0x62]]);

        obj = *(UiSelectionHandler **)(entity + 0x34);
        obj->select(self, entity);

        Ui_PlaySeCue(lbl_8026BB84 + 0x53, 0x64);
    }
}
#pragma push
#pragma optimization_level 4
#pragma cplusplus on
extern "C" void fn_800704F0(void *arg0, void *arg1) {
void *GfxEnt_Get(s32);
s32 Text_MeasureHeight(s32,f32);
void Prim2D_Begin(void);
void Prim2D_AddZ(f32);
void Prim2D_PrepareTex(void);
void Ui_DrawRouteIconEx(s32,s32,s32);
void fn_8008AB7C(s32,s32,s32,s32,s32,s32,s32);
extern f32 lbl_803692E0,lbl_803692F0,lbl_803692F4;
#pragma cplusplus on
struct Obj {u8 pad[4]; virtual void v0()=0;
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
virtual s16 v20()=0; };
u8 *self=(u8*)arg0;
u8 *obj=(u8*)arg1;
u8 *row;
void *ent;
s32 sx;
s16 sy;
s32 height,pulse;
s32 iconX,iconY;
s16 barW,barH;
row=obj;
row+=*(s8*)(row+0x62);
ent=GfxEnt_Get(row[0x40]);
sx=*(s16*)(self+0x8)>>1;
sx=*(s16*)((u8*)ent+0x30)-sx;
sx=(s16)(sx-0x10);
row=obj;
row+=*(s8*)(row+0x62);
ent=GfxEnt_Get(row[0x40]);
sy=*(s16*)((u8*)ent+0x32);
height=(s16)((Obj*)arg0)->v20();
sy+=(height-Text_MeasureHeight(-1,lbl_803692E0))>>1;
if(*(s16*)(obj+0x3A)<0) {
*(s16*)(obj+0x38)=sx; *(s16*)(obj+0x3A)=sy;
} else {
*(s16*)(obj+0x38)=(*(s16*)(obj+0x38)+sx)/2;
*(s16*)(obj+0x3A)=(*(s16*)(obj+0x3A)+sy)/2;
}
Prim2D_Begin();Prim2D_AddZ(lbl_803692F0);Prim2D_PrepareTex();
iconX=*(s16*)(obj+0x38);
iconY=*(s16*)(obj+0x3A);
pulse=0;
if(!obj[0x2D]&&!obj[0x2E]) pulse=1;
Ui_DrawRouteIconEx(iconX,iconY,pulse);
barW=(s16)(*(s16*)(self+0x8)+0x40);
barH=(s16)Text_MeasureHeight(-1,lbl_803692E0);
Prim2D_Begin();Prim2D_AddZ(lbl_803692F4);Prim2D_PrepareTex();
fn_8008AB7C(*(s16*)(obj+0x38)+(barW>>1)-0x10,*(s16*)(obj+0x3A)+(barH>>1),barW,0x18,0x19,0x4B,1);
#pragma cplusplus off
}
#pragma pop
#pragma cplusplus off
void fn_80070678(void *arg0) {
    void Ui_DrawMsgPanelBg(s32, s32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    s32 Text_MeasureWidth(void *, s32, f32);
    extern f32 lbl_80369300;
    extern f32 lbl_803692E0;
    extern f32 lbl_8036930C;
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
        virtual void *v30() = 0;
    };
    Obj *self = (Obj *)arg0;
    s32 width;
    void *text;
    f32 posX;

    self->v29();
    Ui_DrawMsgPanelBg(0, 0);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369300);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    width = (s16)self->v18();
    text = self->v0();
    posX = (f32)((width - Text_MeasureWidth(text, -1, lbl_803692E0)) / 2);
    Prim2D_AddPrim(6);
    Prim2D_SetPos(posX, lbl_8036930C);
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_SetText(self->v0());
    Prim2D_EndPrim();
#pragma cplusplus reset
}

void fn_80070798(u8 *self, u8 *arg1) {
    void *GfxEnt_Get(s32);
    s32 Text_MeasureWidth(void *, s32, f32);
    extern f32 lbl_803692E0;
#pragma cplusplus on
    struct EntObj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void *v4(void *) = 0;
    };
    struct Group {
        u8 pad[0x40];
        u8 ent[0x20];
        s8 count;
        inline u8 *GetEnt(s32 idx) {
            return (u8 *)GfxEnt_Get(ent[idx]);
        }
    };
    struct SelfObj {
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
        virtual s16 v18() = 0;
    };

    Group *group = (Group *)arg1;
    s32 i;
    s8 count;
    s16 spacing;
    s16 x;
    s16 y;

    *(s16 *)(self + 8) = 0;

    for (i = 0; i < group->count; i++) {
        s16 width = Text_MeasureWidth(
            (*(EntObj **)(group->GetEnt(i) + 0x34))->v4(group->GetEnt(i)),
            -1,
            lbl_803692E0);
        if (width >= *(s16 *)(self + 8)) {
            *(s16 *)(self + 8) = width;
        }
    }

    count = group->count;
    spacing = ((SelfObj *)self)->v18() / (count + 1);
    x = spacing;
    y = ((SelfObj *)self)->v17();

    for (s32 j = 0; j < count; j++) {
        *(s16 *)(group->GetEnt(j) + 0x30) = x;
        *(s16 *)(group->GetEnt(j) + 0x32) = y;
        x += spacing;
    }
#pragma cplusplus reset
}

extern u16 lbl_80286860[];
void fn_800708B0(void *arg0, void *arg1) { void *Process_Find(void *); void fn_8018DC58(void); extern u16 lbl_80286860[]; extern u8 lbl_80366DE9; void *p; p=*(void **)((u8*)arg1+0x18); if(p==Process_Find(&lbl_80286860)) fn_8018DC58(); *(s8*)&lbl_80366DE9=-1; }

#pragma cplusplus on
extern "C" void fn_800708F8(void *win, void *state) {
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
        virtual void v19() = 0;
        virtual void v20() = 0;
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual f32 v25() = 0;
    };
    extern u8 gBattle[];
    extern f32 lbl_8036932C, lbl_80369330, lbl_80369334, lbl_80369338;
    f32 UiWin_GetFade(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetColorByte(s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_AddZ(f32);
    void fn_8008B464(s32, s32, s32);
    void fn_8007149C(void *, void *, f32, f32, s32, s32);
    s32 Text_MeasureHeight(s32, f32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    u64 *Item_GetFlagsPtr(void *);
    void fn_8007CFB8(void *, s32, f32, f32);
    void Ui_DrawWeaponTriangle(void *, void *, f32, f32);
    f32 fade;
    s32 tex;
    s32 flag;
    void *p;
    void *btl;

    fade = UiWin_GetFade(state);
    *(s16 *)((u8 *)state + 0x30) = 0;
    *(s16 *)((u8 *)state + 0x32) = 0;
    Prim2D_Begin();
    Prim2D_SetColorByte((s32)(255.0f * fade));
    Prim2D_PrepareTex();
    tex = *(s32 *)((u8 *)win + 0xC);
    Prim2D_Begin();
    Prim2D_SetTransform(0.0f, 0.0f, ((Obj *)win)->v25(), 1.0f);
    Prim2D_PrepareTex();
    fade = 16.0f * fade + 16.0f;
    fn_8008B464(tex, (s32)fade, 0x23);
    fn_8007149C(win, state, fade, 136.0f, *(s32 *)((u8 *)win + 0xC), 0);
    if (*(s16 *)((u8 *)state + 0x3A) >= 5) {
        Prim2D_Begin();
        Prim2D_AddZ(-0.1f);
        Prim2D_PrepareTex();
        flag = 0;
        if ((*(u8 *)((u8 *)state + 0x2D) == 0) && (*(u8 *)((u8 *)state + 0x2E) == 0))
            flag = 1;
        fn_8008AB7C(((Obj *)win)->v18() / 2 + 0x28,
                    *(s16 *)((u8 *)state + 0x3A) + Text_MeasureHeight(-1, 1.0f) / 2,
                    (s32)(0.9f * ((Obj *)win)->v18()), 0x18, 0x19, 0x4B, flag);
        Prim2D_Begin();
        Prim2D_AddZ(0.1f);
        Prim2D_PrepareTex();
    }
    btl = gBattle;
    if (btl != NULL) {
        p = (u8 *)btl + 0x28C;
        if (p != NULL) {
            if ((*Item_GetFlagsPtr(p) & 1ULL) != 0) {
                fn_8007CFB8(btl, 0, lbl_8036932C, lbl_80369330);
            }
        }
    }
    Ui_DrawWeaponTriangle(win, btl, lbl_80369334, lbl_80369338);
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void *GfxEnt_Get(u8);
#pragma cplusplus on
extern "C" void fn_80070B3C(void *arg0, void *arg1) {
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
        virtual s32 v17() = 0;
        virtual void v18() = 0;
        virtual void v19() = 0;
        virtual s32 v20() = 0;
    };
    struct Grp {
        u8 pad[0x3C];
        Obj *obj;
        u8 ids[0x20];
        s8 count;
    };
    struct Ent {
        u8 pad[0x32];
        s16 y;
        u8 pad2[6];
        u8 level;
    };
    Grp *g = (Grp *)arg1;
    s32 i;
    Ent *p;

    for (i = 0; i < g->count; i++) {
        p = (Ent *)GfxEnt_Get(g->ids[i]);
        if (p->level >= 4) {
            p->y = g->obj->v17() + 0x90;
            s32 step = g->obj->v20();
            step *= p->level - 4;
            p->y += step;
        }
    }
}
#pragma cplusplus reset
extern "C" void fn_80070BF4(s32 arg0, void *arg1) {
    void *Unit_GetItemSlot(s32, u8);
    extern s32 gUiContext[];
    Unit_GetItemSlot(gUiContext[0], *(u8 *)((char *)arg1 + 0x3A));
}

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_80070C24(void *arg0, s32 arg1, void *arg2) {
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
        virtual s32 v16(void *) = 0;
        virtual void v17() = 0;
    };
    void UnitRef_Draw(s32, bool, s16, s16);
    ((Obj *)arg0)->v17();
    UnitRef_Draw(((Obj *)arg0)->v16(arg2), *(u8 *)((u8 *)arg2 + 0x39) == 0, *(s16 *)((u8 *)arg2 + 0x30), *(s16 *)((u8 *)arg2 + 0x32));
}

#pragma cplusplus on
extern "C" void fn_80070C98(void *win, void *state) {
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
        virtual void v19() = 0;
        virtual void v20() = 0;
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual f32 v25() = 0;
    };
    f32 UiWin_GetFade(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetColorByte(s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_AddZ(f32);
    void fn_8008B464(s32, s32, s32);
    void fn_8007149C(void *, void *, f32, f32, s32, s32);
    s32 Text_MeasureHeight(s32, f32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    void fn_8007CFB8(void *, s32, f32, f32);
    u64 *Item_GetFlagsPtr(void *);
    void Ui_DrawWeaponTriangle(void *, void *, f32, f32);
    extern u8 gBattle[];
    f32 fade;
    s32 tex;
    s32 flag;
    void *p;
    void *battle;

    fade = UiWin_GetFade(state);
    *(s16 *)((u8 *)state + 0x30) = 0;
    *(s16 *)((u8 *)state + 0x32) = 0;
    Prim2D_Begin();
    Prim2D_SetColorByte((s32)(255.0f * fade));
    Prim2D_PrepareTex();
    tex = *(s32 *)((u8 *)win + 0xC);
    Prim2D_Begin();
    Prim2D_SetTransform(0.0f, 0.0f, ((Obj *)win)->v25(), 1.0f);
    Prim2D_PrepareTex();
    fn_8008B464(tex, (s32)(16.0f * fade + 16.0f), 35);
    fn_8007149C(win, state, 16.0f * fade + 16.0f, 136.0f, *(s32 *)((u8 *)win + 0xC), 1);
    if (*(s16 *)((u8 *)state + 0x3A) >= 5) {
        Prim2D_Begin();
        Prim2D_AddZ(-0.1f);
        Prim2D_PrepareTex();
        flag = 0;
        if ((*(u8 *)((u8 *)state + 0x2D) == 0) && (*(u8 *)((u8 *)state + 0x2E) == 0))
            flag = 1;
        fn_8008AB7C(((Obj *)win)->v18() / 2 + 0x28,
                    *(s16 *)((u8 *)state + 0x3A) + Text_MeasureHeight(-1, 1.0f) / 2,
                    (s32)(0.9f * ((Obj *)win)->v18()), 0x18, 0x19, 0x4B, flag);
        Prim2D_Begin();
        Prim2D_AddZ(0.1f);
        Prim2D_PrepareTex();
    }
    battle = gBattle;
    if (battle != NULL) {
        p = (u8 *)battle + 0x28C;
        if (p != NULL) {
            if ((*Item_GetFlagsPtr(p) & 1ULL) != 0) {
                fn_8007CFB8(battle, 0, 312.0f, 282.0f);
            }
        }
    }
    Ui_DrawWeaponTriangle(win, battle, 500.0f, 212.0f);
}
#pragma cplusplus reset

#pragma cplusplus reset
void fn_80070EDC(void) {

}

#pragma cplusplus on
extern "C" s32 fn_80070EE0(void *arg0, s32 unused, s32 arg2) {
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
        virtual s32 v16(s32) = 0;
    };
    extern s32 gUiContext[];
    extern u8 gBattle[];
    void fn_801A6FB4(void *, s32, s32);
    s32 saved;

    saved = gUiContext[0];
    fn_801A6FB4(gBattle, saved, ((Obj *)arg0)->v16(arg2));
    return 0;
}
#pragma cplusplus reset
void fn_80070F3C(void *arg0) {
    extern s32 gUiContext[];
    extern s32 gUiAtlas;
    *(s32 *)((u8 *)arg0 + 0xC) = gUiContext[0];
    *(s32 *)((u8 *)arg0 + 8) = gUiAtlas;
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void Ui_DrawWeaponTriangle(void *self, void *unit, f32 x, f32 y) {
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
        virtual f32 v25() = 0;
    };
    void Ui_DrawWindowTexture(void *, s32, s32, s32, s32, f32, f32, f32);
    void Ui_DrawIcon(void *, s32, s32, s32);
    extern u8 gUiIconDrawer[];
    extern u8 gUiWeaponTriangleData[];
    extern s32 lbl_80367348;
    extern s8 lbl_8036734C;
    extern f32 lbl_8036933C;
    extern f32 lbl_80369340;
    extern f32 lbl_80369344;
    extern f32 lbl_80369348;
    extern f32 lbl_8036934C;
    extern f32 lbl_803692E0;
    u8 *tbl;
    s8 row;
    s32 col;
    s32 icons[2][3];
    s32 xOff[9];
    s32 yOff[9];
    s32 *p;
    s32 type;
    void *sub;
    s32 idx;
    s32 iy;

    tbl = gUiWeaponTriangleData;
    row = -1;
    col = 0;
    p = (s32 *)(tbl + 0x1C);
    icons[0][0] = p[0];
    icons[0][1] = p[1];
    icons[0][2] = p[2];
    icons[1][0] = p[3];
    icons[1][1] = p[4];
    icons[1][2] = p[5];
    if (unit == NULL) {
        return;
    }
    sub = (u8 *)unit + 0x28C;
    if (sub == NULL) {
        return;
    }
    sub = *(void **)sub;
    if (sub != NULL) {
        type = *((u8 *)sub + 0x13);
    } else {
        type = 0xC;
    }
    type = (s8)(u8)type;
    switch (type) {
    case 0:
        row = 0;
        col = 0;
        break;
    case 1:
        row = 0;
        col = 1;
        break;
    case 2:
        row = 0;
        col = 2;
        break;
    case 3:
        row = 1;
        col = 0;
        break;
    case 4:
        row = 1;
        col = 1;
        break;
    case 5:
        row = 1;
        col = 2;
        break;
    case 6:
        break;
    }
    if (row == -1) {
        return;
    }
    Ui_DrawWindowTexture(self, 1, 0xFF, 0x39, 0, x, y, ((Obj *)self)->v25());
    p = (s32 *)(tbl + 0x34);
    xOff[0] = p[0];
    xOff[1] = p[1];
    xOff[2] = p[2];
    xOff[3] = p[3];
    xOff[4] = p[4];
    xOff[5] = p[5];
    xOff[6] = p[6];
    xOff[7] = p[7];
    xOff[8] = p[8];
    p = (s32 *)(tbl + 0x58);
    yOff[0] = p[0];
    yOff[1] = p[1];
    yOff[2] = p[2];
    yOff[3] = p[3];
    yOff[4] = p[4];
    yOff[5] = p[5];
    yOff[6] = p[6];
    yOff[7] = p[7];
    yOff[8] = p[8];
    if ((s8)lbl_8036734C == 0) {
        lbl_80367348 = 0;
        lbl_8036734C = 1;
    }
    lbl_80367348 = lbl_80367348 + 1;
    lbl_80367348 = lbl_80367348 % 24;
    idx = lbl_80367348 / 8;
    Ui_DrawWindowTexture(self, 1, 0xFF, 0x3A, 0, x + (f32)xOff[idx], y + (f32)yOff[idx], ((Obj *)self)->v25() - lbl_803692E0);
    Ui_DrawWindowTexture(self, 1, 0xFF, 0x3B, 0, x + (f32)xOff[idx + 3], y + (f32)yOff[idx + 3], ((Obj *)self)->v25() - lbl_803692E0);
    Ui_DrawWindowTexture(self, 1, 0xFF, 0x3C, 0, x + (f32)xOff[idx + 6], y + (f32)yOff[idx + 6], ((Obj *)self)->v25() - lbl_803692E0);
    Ui_DrawIcon(gUiIconDrawer, (s32)(lbl_8036933C + x), (s32)(y - lbl_80369340), icons[row][col]);
    Ui_DrawIcon(gUiIconDrawer, (s32)(lbl_80369344 + x), (iy = (s32)(lbl_80369348 + y)), icons[row][(col + 1) % 3]);
    Ui_DrawIcon(gUiIconDrawer, (s32)(x - lbl_8036934C), iy, icons[row][(col + 2) % 3]);
}
#pragma cplusplus reset

void fn_80071410(s32 unused, void *arg1, f32 f1, f32 f2) {
    u64 *Item_GetFlagsPtr(void *);
    void fn_8007CFB8(void *, s32, f32, f32);
    void *p;

    if (arg1 != NULL) {
        p = (u8 *)arg1 + 0x28C;
        if (p != NULL) {
            if ((*Item_GetFlagsPtr(p) & 1ULL) != 0) {
                fn_8007CFB8(arg1, 0, f1, f2);
            }
        }
    }
}

#pragma cplusplus on
extern "C" void fn_8007149C(void *self, u8 *list, u8 *data, u8 mode, f32 x, f32 y) {
    void *GfxEnt_Get(u8);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void fn_8008BBF8(s32, s32, s32, u16, u8, s32);
    extern f32 lbl_80369348, lbl_80369350, lbl_80369354;
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
        virtual f32 v25() = 0;
    };
    f32 baseX = lbl_80369348 + x;
    f32 baseY = lbl_80369350 + y;
    f32 lowerY = lbl_80369354 + y;
    f32 px, py;
    s32 i;
    u32 height;
    for (i = 0; i < (s8)list[0x60]; i++) {
        u8 *ent = (u8 *)GfxEnt_Get(list[i + 0x40]);
        s32 row = ent[0x3a];
        if (mode == 2)
            row += 4;
        if (mode == 0) {
            px = baseX;
            if (row < 4)
                py = baseY + (f32)(row * 28);
            else
                py = lowerY + (f32)((row - 4) * 28);
        }
        if (mode == 1) {
            px = baseX;
            py = baseY + (f32)(row * 28);
        }
        if (mode == 2) {
            px = baseX;
            py = baseY + (f32)((row - 4) * 28);
        }
        if (mode == 3) {
            px = baseX;
            py = baseY + (f32)(row * 28);
        }
        *(s16 *)(ent + 0x30) = (s16)px;
        *(s16 *)(ent + 0x32) = (s16)py;
    }
    switch (mode) {
    case 0:
        height = 0x110;
        break;
    case 1:
    case 2:
        height = 0x88;
        break;
    default:
        return;
    }
    Prim2D_Begin();
    Prim2D_SetTransform(0.0f, 0.0f, ((Obj *)self)->v25(), 1.0f);
    Prim2D_PrepareTex();
    fn_8008BBF8((s32)x, (s32)y, 0x108, (u16)height, (*(u8 **)(data + 0x190))[8], 0x9a);
}
extern "C" M2C_UNK Prim2D_Begin();
extern "C" M2C_UNK Prim2D_PrepareTex();
extern "C" void Prim2D_SetTransform(f32, f32, f32, f32);
extern "C" void fn_8008B464(s32, s32, s32);
extern "C" void fn_80071740(void *arg0, s32 arg1, f32 x, f32 y) {
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
        virtual f32 v25() = 0;
    };

    Prim2D_Begin();
    Prim2D_SetTransform(0.0f, 0.0f, ((Obj *)arg0)->v25(), 1.0f);
    Prim2D_PrepareTex();
    fn_8008B464(arg1, (s32)x, (s32)y);
}

extern "C" void Ui_DrawWindowTexture(void *arg0, s32 color, s32 alpha, s32 texId, s32 flags, f32 x, f32 y, f32 z) {
#pragma inline_depth(0)
    u32 *Ui_GetColor(s32);
    s32 fn_8006EDD8(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void fn_80009EB0(void *, u16, s32, s32);
    void Prim2D_BindTexture(void *, u16, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);

    u32 packed;
    f32 u0;
    f32 u1;
    f32 v0;
    f32 v1;
    u16 w;
    u16 h;
    s32 *entry;

    packed = *Ui_GetColor(color);
    entry = (s32 *)fn_8006EDD8(*(void **)((u8 *)arg0 + 8), texId);
    w = (*(u16 **)entry)[1];
    h = (*(u16 **)entry)[0];
    u0 = 0.0f;
    v0 = u0;
    u1 = (f32)w;
    v1 = (f32)h;
    if (flags & 1) {
        u0 = u1;
        u1 = v0;
    }
    if (flags & 2) {
        v0 = v1;
        v1 = 0.0f;
    }
    Prim2D_Begin();
    Prim2D_SetTransform(0.0f, 0.0f, z, 1.0f);
    if ((u32)entry[1] != 0) {
        fn_80009EB0(*(void **)((u8 *)arg0 + 8), texId, 0, 0x11);
    } else {
        Prim2D_BindTexture(*(void **)((u8 *)arg0 + 8), texId, 0x11);
    }
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(0.0f);
    Prim2D_SetQuadMin(x, y, u0, v0);
    Prim2D_SetQuadMax(x + (f32)w, y + (f32)h, u1, v1);
    Prim2D_SetColor(((u8 *)&packed)[0], ((u8 *)&packed)[1], ((u8 *)&packed)[2], alpha);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
}

#pragma cplusplus reset
void fn_800719E4(void *arg0, void *arg1) {
#pragma cplusplus on
struct Obj { u8 pad[4];
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
s32 Text_MeasureHeight(s32, f32);
void fn_8008AB7C(s32,s32,s32,s32,s32,s32,s32);
void fn_8008C1D8(s32,s32,s32,s32,s32);
void Prim2D_AddZ(f32);
s32 flag;
s32 n = *(s8*)((u8*)arg1+0x60);
((Obj*)arg0)->v29();
fn_8008C1D8(0,0,0,(n<<5)+0x20,0);
if (*(s16*)((u8*)arg1+0x3A)>=5) {
Prim2D_Begin(); Prim2D_AddZ(-0.1f); Prim2D_PrepareTex();
flag=0;
if (!*(u8*)((u8*)arg1+0x2D) && !*(u8*)((u8*)arg1+0x2E)) flag=1;
fn_8008AB7C(((Obj*)arg0)->v18()/2, *(s16*)((u8*)arg1+0x3A)+Text_MeasureHeight(-1,1.0f)/2, (s32)(0.9f*((Obj*)arg0)->v18()),0x17,0x19,0x4B,flag);
Prim2D_Begin(); Prim2D_AddZ(0.1f); Prim2D_PrepareTex();
}
#pragma cplusplus reset
}
void fn_80071B34(void) {
    M2C_UNK fn_8018DAD4();
    fn_8018DAD4();
}

void fn_80071B54(void) {
    M2C_FIELD(&gBattleState, s8 *, 0x51D) = 0xF;
    fn_8018DBD8(&gBattleState);
    fn_8018DB10();
}

void fn_80071B88(void) {
    M2C_UNK Prim2D_AddZ(f32);
    M2C_UNK Prim2D_SetTex(M2C_UNK, M2C_UNK);
    M2C_UNK Prim2D_PrepareTex();
    M2C_UNK Prim2D_Begin();
    extern f32 lbl_80369300;
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369300);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
}

#pragma cplusplus on
extern "C" void fn_80071BC0(void *arg0, void *arg1, void *arg2) {
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    s32 Text_MeasureWidth(void *, s32, f32);
    struct T { virtual void *a()=0; virtual void *b()=0; virtual void *c()=0; virtual void *d()=0; virtual void *e(void *)=0; };
    struct W { u8 pad[4]; virtual s32 a()=0; virtual s32 b()=0; virtual s32 c()=0; virtual s32 d()=0; virtual s32 e()=0; virtual s32 f()=0; virtual s32 g()=0; virtual s32 h()=0; virtual s32 i()=0; virtual s32 j()=0; virtual s32 k()=0; virtual s32 l()=0; virtual s32 m()=0; virtual s32 n()=0; virtual s32 o()=0; virtual s32 p()=0; virtual s32 q()=0; virtual s32 r()=0; virtual s16 s()=0; };
    struct S { virtual void a()=0; virtual void b()=0; virtual void c()=0; virtual void d()=0; virtual void e()=0; virtual void f()=0; virtual void g()=0; virtual void h()=0; virtual void i()=0; virtual void j()=0; virtual void k()=0; virtual void l()=0; virtual void m()=0; virtual void n()=0; virtual void o()=0; virtual void p()=0; virtual void q()=0; virtual void r(void *)=0; virtual void s(void *)=0; };
    void *self;
    void *param;
    void *win;
    s32 textWidth;
    void *text;

    win = arg2;
    param = arg1;
    self = arg0;
    text = ((T *)*(void **)((u8 *)win + 0x34))->e(win);
    textWidth = Text_MeasureWidth(text, -1, 1.0f);
    textWidth = ((*(W **)((u8 *)param + 0x3C))->s() - textWidth) / 2;
    ((S *)self)->r(param);
    Prim2D_AddPrim(6);
    Prim2D_SetPos((f32)textWidth, (f32)*(s16 *)((u8 *)win + 0x32));
    ((S *)self)->s(win);
    text = ((T *)*(void **)((u8 *)win + 0x34))->e(win);
    Prim2D_SetText(text);
    Prim2D_EndPrim();
}
#pragma cplusplus reset
void fn_80071CE8(void *arg0, void *arg1) {
    void Prim2D_SetColorPacked(s32 *);
    s32 *Ui_GetColor(s32);
    s32 sp8;

    if (*(u8 *)((u8 *)arg1 + 0x39) == 2) {
        sp8 = *Ui_GetColor(0);
        Prim2D_SetColorPacked(&sp8);
    }
}

/* Average obj screen pos toward its linked gfx entity, then draw the route icon. */
void Ui_DrawObjRouteIcon(void *unused, void *obj) {
    void *GfxEnt_Get(s32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Ui_DrawRouteIconEx(s32, s32, s32);
    extern f32 lbl_803692F0;
    u8 *row;
    void *ent;
    s16 sx;
    s16 sy;
    s32 pulse;

    (void)unused;
    row = (u8 *)obj;
    row += *(s8 *)(row + 0x62);
    ent = GfxEnt_Get(*(u8 *)(row + 0x40));
    sx = *(s16 *)((u8 *)ent + 0x30);

    row = (u8 *)obj;
    row += *(s8 *)(row + 0x62);
    ent = GfxEnt_Get(*(u8 *)(row + 0x40));
    sy = *(s16 *)((u8 *)ent + 0x32);

    if (*(s16 *)((u8 *)obj + 0x3A) < 0) {
        *(s16 *)((u8 *)obj + 0x38) = sx;
        *(s16 *)((u8 *)obj + 0x3A) = sy;
    } else {
        *(s16 *)((u8 *)obj + 0x38) = (s16)((*(s16 *)((u8 *)obj + 0x38) + sx) / 2);
        *(s16 *)((u8 *)obj + 0x3A) = (s16)((*(s16 *)((u8 *)obj + 0x3A) + sy) / 2);
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_803692F0);
    Prim2D_PrepareTex();

    pulse = 0;
    if (((u8 *)obj)[0x2D] == 0 && ((u8 *)obj)[0x2E] == 0) {
        pulse = 1;
    }
    Ui_DrawRouteIconEx(*(s16 *)((u8 *)obj + 0x38), *(s16 *)((u8 *)obj + 0x3A), pulse);
}

void fn_80071E0C(void *arg0, void *arg1) {
#pragma cplusplus on
struct Obj { u8 pad[4];
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
s32 Text_MeasureHeight(s32, f32);
void fn_8008AB7C(s32,s32,s32,s32,s32,s32,s32);
void fn_8008C1D8(s32,s32,s32,s32,s32);
void Prim2D_AddZ(f32);
s32 flag;
s32 n = *(s8*)((u8*)arg1+0x60);
((Obj*)arg0)->v29();
fn_8008C1D8(0,0,0x90,(n<<5)+0x20,1);
if (*(s16*)((u8*)arg1+0x3A)>=5) {
Prim2D_Begin(); Prim2D_AddZ(-0.1f); Prim2D_PrepareTex();
flag=0;
if (!*(u8*)((u8*)arg1+0x2D) && !*(u8*)((u8*)arg1+0x2E)) flag=1;
fn_8008AB7C(((Obj*)arg0)->v18()/2, *(s16*)((u8*)arg1+0x3A)+Text_MeasureHeight(-1,1.0f)/2, (s32)(0.9f*((Obj*)arg0)->v18()),0x18,0x19,0x4B,flag);
Prim2D_Begin(); Prim2D_AddZ(0.1f); Prim2D_PrepareTex();
}
#pragma cplusplus reset
}

void fn_80071F5C(void *unused, void *win) {
#pragma cplusplus on
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetColorByte(s32);
    f32 UiWin_GetFade(void *);
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void fn_80009C20(f32,f32,f32,f32,f32,f32,f32,f32);
    extern f32 lbl_803692E0, lbl_80369314, lbl_803692F8;
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
    f32 scale = Math_Ease(5, lbl_80369314, lbl_803692E0, UiWin_GetFade(win), lbl_803692E0);
    Prim2D_Begin();
    fn_80009C20((f32)M2C_FIELD(win,s16 *,0x30), (f32)M2C_FIELD(win,s16 *,0x32),
        M2C_FIELD(win,Model **,0x3C)->v25(), (f32)(M2C_FIELD(win,s16 *,0x34)/2),
        (f32)(M2C_FIELD(win,s16 *,0x36)/2), scale, scale, lbl_80369314);
    Prim2D_SetColorByte((s32)(lbl_803692F8 * UiWin_GetFade(win)));
    Prim2D_PrepareTex();
#pragma cplusplus reset
}

void fn_80072088(void *arg0, void *arg1) {
    void *Process_Find(void *);
    void fn_8018DC58(void);
    extern u16 lbl_80286860[];
    void *p;

    p = *(void **)((u8 *)arg1 + 0x18);
    if (p == Process_Find(&lbl_80286860)) {
        fn_8018DC58();
    }
}

void fn_800720C8(s32 unused, void *arg1) {
    s16 temp_r5;
    s32 temp_r3;

    temp_r5 = *(s16 *)((u8 *)arg1 + 0x36);
    temp_r3 = *(s16 *)((u8 *)arg1 + 0x32) + temp_r5;
    if (temp_r3 / 2 > 0xE0) {
        *(s16 *)((u8 *)arg1 + 0x32) = (s16)((0x1C0 - temp_r5) / 2);
    }
}

void fn_80072100(void *arg0, void *arg1) {
    void *Process_Find(void *);
    void fn_8018DBD8(void);
    void *temp_r31;
    void *result;

    *(u8 *)((u8 *)gBattleState + 0x51D) = 0xF;
    temp_r31 = *(void **)((u8 *)arg1 + 0x18);
    result = Process_Find(lbl_80286860);
    if (temp_r31 == result) {
        fn_8018DBD8();
    }
}

s32 fn_80072150(void) {
    extern s8 lbl_80366DE8;
    lbl_80366DE8 = 0;
    return 5;
}

u32 fn_80072160(void) {
    extern u8 lbl_80366DE8;

    lbl_80366DE8 = 1;
    return 5;
}

void fn_80072170(void *arg0) {
    Msg_Expand(M2C_FIELD(arg0, s32 *, 4));
}

s32 fn_80072194(void) {
    return 0xA0;
}

s32 fn_8007219C(void) {
    return 0x100;
}

s32 fn_800721A4(void) {
    return 0x20;
}

s32 fn_800721AC(void) {
    return 0x88;
}

void fn_800721B4(void *arg0) {
    Msg_Expand(M2C_FIELD(arg0, s32 *, 0xC));
}

s32 fn_800721D8(void) {
    return 0x160;
}

s32 fn_800721E0(void) {
    return 0x48;
}

s16 fn_800721E8(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x10);
}

void *fn_800721F0(void) {
    extern u16 lbl_8026BB84[];
    return (u8 *)lbl_8026BB84 + 0x46;
}

s32 fn_80072200(void) {
    return 0x108;
}

s32 fn_80072208(void) {
    return 0x78;
}

s32 fn_80072210(void) {
    return 0x78;
}

s32 fn_80072218(void) {
    return 0x98;
}

s16 fn_80072220(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0xE);
}

s16 fn_80072228(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x10);
}

s32 fn_80072230(void) {
    return 0xB0;
}

f32 fn_80072238(void) {
    extern f32 lbl_80369360;
    return lbl_80369360;
}

void *fn_80072240(void) {
    extern u8 lbl_8026BB84[];

    return lbl_8026BB84 + 0x6F;
}

void *fn_80072250(void) {
    extern u16 lbl_8026BB84[];
    return (u8 *)lbl_8026BB84 + 0x88;
}

void *fn_80072260(void) {
    extern u16 lbl_8026BB84[];
    return (u8 *)lbl_8026BB84 + 0xA2;
}

s32 fn_80072270(void) {
    return 4;
}

s32 fn_80072278(void) {
    return 4;
}

s32 fn_80072280(void) {
    return 0xB0;
}

s32 fn_80072288(void) {
    return 8;
}

s32 fn_80072290(void) {
    return 8;
}

#pragma cplusplus on
extern "C" s16 fn_80072298(void *arg0) {
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
    s16 temp = ((Obj *)arg0)->v18();
    return (s16)(0x130 - (temp / 2));
}
extern "C" s16 fn_800722DC(void *arg0) {
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
        virtual s16 v19() = 0;
    };
    s16 temp = ((Obj *)arg0)->v19();
    return (s16)(0xE0 - (temp / 2));
}
#pragma cplusplus reset
s32 fn_80072320(void) {
    return 0x54;
}

s32 fn_80072328(u8 *arg0) {
    if (*(s16 *)(arg0 + 0x12) < *(s16 *)(arg0 + 0x10)) {
        arg0 += 0x12;
    } else {
        arg0 += 0x10;
    }
    return *(s16 *)arg0;
}

s32 fn_8007234C(void) {
    return 0x54;
}

s32 fn_80072354(void) {
    return 0x50;
}

s32 fn_8007235C(void) {
    return 0x42;
}

s32 fn_80072364(void) {
    return 0x12C;
}

s32 fn_8007236C(void) {
    return 0x1C;
}

s32 fn_80072374(void) {
    return 0x14;
}

s32 fn_8007237C(void) {
    return 0x1E;
}

s32 fn_80072384(void) {
    return 0x28;
}

s32 fn_8007238C(void) {
    return 0xB4;
}

s32 fn_80072394(void) {
    return 0;
}

s32 fn_8007239C(void) {
    return 0x90;
}

void *fn_800723A4(void) {
    extern u16 lbl_8026BB84[];
    return (u8 *)lbl_8026BB84 + 0xC2;
}

void *fn_800723B4(void) {
    extern u8 lbl_8026BB84[];

    return lbl_8026BB84 + 0xD7;
}

s32 fn_800723C4(void) {
    return 0;
}

s32 fn_800723CC(void) {
    return 0x14;
}

s32 fn_800723D4(void) {
    return 0x190;
}

s32 fn_800723DC(void) {
    return 0x80;
}

void fn_800723E4(void *arg0) {
    Msg_Expand(M2C_FIELD(arg0, s32 *, 4));
}
extern void *gCamera;
extern s32 *jumptable_80285D18;
extern u8 lbl_80366DE9;
extern struct Unit {
    /* Some fields are guessed based on usage and context of similar structs */
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u16 unk22;
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u16 unk2A;
    u16 unk2C;
    u16 unk2E;
} Unit; 
#include "common.h"
#include "global.h"

extern u16 lbl_8026B980[8];
#include "common.h"
#include "global.h"
extern f32 lbl_803692E0;
extern f32 lbl_80369310;
extern f32 lbl_80369314;
extern f32 lbl_80369318;
extern f32 lbl_8036931C;
extern f32 lbl_80369320;
extern f32 lbl_80369324;
extern f32 lbl_80369328;
extern f32 lbl_8036932C;
extern f32 lbl_80369330;
extern f32 lbl_80369334;
extern f32 lbl_80369338;
extern u8 gBattle[];

extern u8 gFileCacheWorkQueue[];
extern u8 gFileCacheWorkWrite;
extern u32 gFileCacheWorkThreadQueue;
extern s32 RunQueueBits_80368518;
extern s32 RunQueueHint_8036851C;
extern void *RunQueue_80339478[256];
/* Functions from 0x8005AE20 to 0x80072408, found by decomp-toolkit. */
#include "common.h"
#include "global.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
} Struct_80067304;

typedef struct { f32 x, y, z; } Vec3f_67304;
extern Vec3f_67304 lbl_8026B744;
extern Vec3f_67304 lbl_8026B750;
extern f32 lbl_80369224;
extern f32 lbl_80369228;
extern s32 lbl_8036C444;
extern s32 lbl_8036C448;
#include "common.h"
#include "global.h"

extern f32 lbl_803692E0;
extern f32 lbl_803692F8;
extern f64 lbl_803692E8;
#include "global.h"

extern f32 lbl_803692F0;
#include "common.h"
#include "global.h"

extern s32 lbl_80366DDC;
extern f32 lbl_80369248;
extern const s32 lbl_8026B75C[3];
#include "common.h"
#include "global.h"

extern void fn_80225D6C(s32* a, s32* b, s32* c, s32* d);
extern void fn_8021F168(void* a, void* b, u8* c, u8* d, void* e, s32 f, s32 g, s32 h);
extern void OSReport(const char* fmt, ...);
extern char DEMOInit_str[];
#include "common.h"
#include "global.h"

extern f32 lbl_803691E0;
extern f32 lbl_80369200;
extern f32 lbl_80369208;
#include "common.h"
#include "structs.h"

extern f32 gMtxZero;
extern f32 gDegToRad;
extern u8 gGUtilAssertMsg[];
