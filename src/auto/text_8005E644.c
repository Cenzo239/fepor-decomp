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

static inline void *GActor_FindNodeTableLocal(void *p) {
    while (p) {
        void *info = *(void **)((u8 *)p + 0x40);
        if (info) return info;
        p = *(void **)((u8 *)p + 4);
    }
    return 0;
}

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
    while (arg0 != NULL) {
        u32 temp = M2C_FIELD(arg0, u32 *, 0x48);
        if (temp != 0U) {
            return temp;
        }
        arg0 = M2C_FIELD(arg0, void **, 4);
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

void fn_8005E644(void *arg0) {
    void fn_8005F12C(void *, void *);
    void fn_8005F230(void *);
    s32 fn_8005F378(void *);
    s32 fn_8005F3B8(void *);
    void *fn_8005F410(void *);
    void Model_SetAlpha(void *, u8);
    void Model_SetColor(void *, u8, u8, u8);
    void *GActor_GetNodeTable(void *);
    void fn_8006D378(void *);
    void fn_801505A8(void *, void *);
    void PSMTXCopy(void *, void *);

    u32 color;
    void *p;
    void *q;
    void *r;
    s32 n;
    s32 depth;
    s32 dist;
    s32 b;
    u8 ub;
    u8 alpha;
    u8 t;
    s32 off;
    void *great;
    s32 i;
    void *info;
    void *grand;
    void *child;

    child = *(void **)((u8 *)arg0 + 0x8C);
    if (child == NULL) {
        return;
    }

    grand = *(void **)((u8 *)child + 0x8C);
    if (grand != NULL) {
        great = *(void **)((u8 *)grand + 0x8C);
        if (great != NULL) {
            fn_8005E644(great);
            fn_8005F12C(grand, great);
            fn_8005F230(great);
        }

        if (child != NULL && grand != NULL) {
            info = GActor_GetNodeTable(child);
            i = 0;
            off = i;
            while (i < *(s32 *)((u8 *)info + 8)) {
                PSMTXCopy((u8 *)*(void **)((u8 *)child + 0x60) + off,
                            (u8 *)*(void **)((u8 *)grand + 0x60) + off);
                off += 0x30;
                i += 1;
            }
            if (*(u32 *)((u8 *)child + 0x64) != 0) {
                i = 0;
                off = i;
                while (i < *(s32 *)((u8 *)info + 8)) {
                    PSMTXCopy((u8 *)*(void **)((u8 *)child + 0x64) + off,
                                (u8 *)*(void **)((u8 *)grand + 0x64) + off);
                    off += 0x30;
                    i += 1;
                }
                fn_8006D378(grand);
            }
            PSMTXCopy((u8 *)child + 0x10, (u8 *)grand + 0x10);
            if (*(u32 *)((u8 *)child + 0x54) != 0) {
                fn_801505A8(child, grand);
            }
            *(f32 *)((u8 *)grand + 0x58) = *(f32 *)((u8 *)child + 0x58);
        }

        info = fn_8005F410(grand);
        if (info != NULL) {
            n = fn_8005F378(grand);
            b = fn_8005F3B8(grand);
            ub = ((u8 *)info)[0xB];
            color = *(u32 *)((u8 *)info + 0x88);
            alpha = (u8)(((ub - (ub * b) / (n + 1)) * ((u8 *)&color)[3]) / 255);
            ((u8 *)&color)[3] = alpha;
            Model_SetAlpha(grand, alpha);
            Model_SetColor(grand, ((u8 *)&color)[0], ((u8 *)&color)[1], ((u8 *)&color)[2]);
        }
    }

    if (arg0 != NULL && child != NULL) {
        p = arg0;
        goto loop_2;
    loop_1:
        if (*(u32 *)((u8 *)p + 0x40) != 0U) {
            goto block_7;
        }
        p = *(void **)((u8 *)p + 4);
    loop_2:
        if (p != NULL) {
            goto loop_1;
        }
        i = 0;
        goto block_8;
    block_7:
        i = *(s32 *)((u8 *)p + 0x40);
    block_8:
        info = (void *)i;

        i = 0;
        off = i;
        while (i < *(s32 *)((u8 *)info + 8)) {
            PSMTXCopy((u8 *)*(void **)((u8 *)arg0 + 0x60) + off,
                        (u8 *)*(void **)((u8 *)child + 0x60) + off);
            off += 0x30;
            i += 1;
        }
        if (*(u32 *)((u8 *)arg0 + 0x64) != 0) {
            i = 0;
            off = i;
            while (i < *(s32 *)((u8 *)info + 8)) {
                PSMTXCopy((u8 *)*(void **)((u8 *)arg0 + 0x64) + off,
                            (u8 *)*(void **)((u8 *)child + 0x64) + off);
                off += 0x30;
                i += 1;
            }
            fn_8006D378(child);
        }
        PSMTXCopy((u8 *)arg0 + 0x10, (u8 *)child + 0x10);
        if (*(u32 *)((u8 *)arg0 + 0x54) != 0) {
            fn_801505A8(arg0, child);
        }
        *(f32 *)((u8 *)child + 0x58) = *(f32 *)((u8 *)arg0 + 0x58);
    }

    p = child;
    for (;;) {
        q = *(void **)((u8 *)p + 4);
        if (q != NULL && *(u32 *)((u8 *)q + 0x8C) != 0) {
            p = q;
        } else {
            break;
        }
    }

    if (p != NULL) {
        q = child;
        for (;;) {
            r = *(void **)((u8 *)q + 4);
            if (r != NULL && *(u32 *)((u8 *)r + 0x8C) != 0) {
                q = r;
            } else {
                break;
            }
        }
        depth = 0;
        for (;;) {
            q = *(void **)((u8 *)q + 0x8C);
            if (q != NULL) {
                depth += 1;
            } else {
                break;
            }
        }

        r = child;
        for (;;) {
            q = *(void **)((u8 *)r + 4);
            if (q != NULL && *(u32 *)((u8 *)r + 0x8C) != 0) {
                r = q;
            } else {
                break;
            }
        }
        dist = 0;
        if (r != child) {
            for (;;) {
                r = *(void **)((u8 *)r + 0x8C);
                if (r != NULL) {
                    dist += 1;
                } else {
                    dist = 0;
                    break;
                }
            }
        }

        ub = ((u8 *)p)[0xB];
        color = *(u32 *)((u8 *)p + 0x88);
        t = (u8)(((ub - (ub * dist) / (depth + 1)) * ((u8 *)&color)[3]) / 255);
        ((u8 *)&color)[3] = t;
        ((u8 *)child)[0xB] = t;
        if (t != 0xFF) {
            *(u32 *)child |= 0x20;
        } else {
            *(u32 *)child &= ~0x20;
        }
        ((u8 *)child)[8] = ((u8 *)&color)[0];
        ((u8 *)child)[9] = ((u8 *)&color)[1];
        ((u8 *)child)[0xA] = ((u8 *)&color)[2];
    }
}
