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

#pragma opt_strength_reduction off
#pragma inline_depth(8)
#pragma inline_max_size(256)
static inline void MenuEntries_8006F10C(s32 *table, s32 **entries, s32 a, s32 b) {
    entries[0] = table;
    table = entries[0];
    table[1] = a;
    entries[1] = table + 2;
    entries[1][1] = b;
    entries[2] = 0;
}
#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
u8 lbl_80311CA8[0x10];
u8 lbl_80311CB8[0x28];
u8 lbl_80311CE0[0x14];
static s32 menuItems[8];
static s32 *menuEntries[5];
static u8 menuWork[0x28];

void fn_8006F10C(s32 arg0, s32 arg1)
{
  s32 fn_800C0658(void);
  void Ui_CreateMenu(void *, s32, s32);
  s32 *table;
  s32 **list;
  /* MWCC lays out the BSS pool in first-reference order. */
  (void)lbl_80311CA8;
  (void)lbl_80311CB8;
  (void)lbl_80311CE0;
  table = menuItems;
  list = menuEntries;
  list[0] = table;
  table = list[0];
  table[1] = arg0;
  list[1] = table + 2;
  table[3] = arg1;
  list[2] = 0;
  Ui_CreateMenu(menuWork, fn_800C0658(), 0);
}
#pragma pop

