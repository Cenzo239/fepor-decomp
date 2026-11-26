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

static inline void *GActor_FindNodeTableIn(void *p) {
    while (p) {
        void *table = *(void **)((u8 *)p + 0x40);
        if (table) return table;
        p = *(void **)((u8 *)p + 4);
    }
    return 0;
}

static inline void GActor_CopyMatrixArray(void *from, void *to, void *table, s32 i) {
    void PSMTXCopy(void *, void *);
    s32 off = i * 0x30;
    for (; i < *(s32 *)((u8 *)table + 8); ++i, off += 0x30)
        PSMTXCopy((u8 *)from + off, (u8 *)to + off);
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

#pragma use_lmw_stmw reset

#pragma dont_inline reset

void fn_8005EB5C(u8 *dst, u8 *src)
{
  u8 b;
  u8 a;

  a = src[0];
  b = src[1];
  dst[0x88] = a;
  a = src[2];
  dst[0x89] = b;
  b = src[3];
  dst[0x8A] = a;
  dst[0x8B] = b;
}

void fn_8005EB80(s32 arg0, s32 arg1) {
    M2C_UNK fn_8005EA14();
    void fn_8005EC18(void *, s32, s32);
    if (arg0 != 0) {
        fn_8005EA14();
        fn_8005EC18((void *)arg0, arg1, 0x40800000);
    }
}

void fn_8005EBCC(s32 arg0, s32 arg1) {
    void fn_8005EC18(void *, s32, s32);
    if (arg0 != 0) {
        fn_8005EA14();
        fn_8005EC18((void *)arg0, arg1, 0x40400000);
    }
}

#pragma global_optimizer off
#pragma push
#pragma optimization_level 4
#pragma global_optimizer off
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_8005EC18(void *arg0, s32 arg1, s32 arg2) {
    void *fn_800C4638(s32, void *, s32);
    void Game_Assert(void *, s32, void *);
    void fn_800618E4(void *);
    void GActor_Finalize(void *);
    void *GActor_GetNodeTable(void *);
    void PSMTXCopy(void *, void *);
    void fn_8006D378(void *);
    void fn_801505A8(void *, void *);
    void *GActor_Create(void);
    void fn_8005F12C(void *, void *);
    s32 fn_8005F230(void *);
    void *fn_8005F410(void *);
    s32 fn_8005F378(void *);
    s32 fn_8005F3B8(void *);
    void Model_SetAlpha(void *, u8);
    void Model_SetColor(void *, u8, u8, u8);
    extern char lbl_8026B590[];

    u8 spC[4];
    u8 sp8[4];
    void *node;
    void *self;
    s32 count;
    s32 flags;
    s32 i;
    s32 off;
    void *anim;

    self = arg0;
    count = arg1;
    flags = arg2;

    if (count - 1 < 0) {
        return;
    }

    node = fn_800C4638(0xA0, lbl_8026B590 + 0x27, 0);
    if (node == 0) {
        Game_Assert(lbl_8026B590 + 0x28, 0x46, lbl_8026B590 + 0x31);
    }
    fn_800618E4(node);
    *(u32 *)node |= 4;
    *(u32 *)node |= *(u32 *)self | flags;
    *(void **)((u8 *)node + 4) = self;
    *(u32 *)((u8 *)node + 0x90) = *(u32 *)((u8 *)self + 0x90);
    *(void **)((u8 *)self + 0x8C) = node;
    GActor_Finalize(node);
    ((u8 *)node)[0x87] = ((u8 *)self)[0x87];

    if (self != 0 && node != 0) {
        void *p = self;
        goto anim_check;
    anim_load:
        anim = *(void **)((u8 *)p + 0x40);
        if (anim == 0) goto anim_parent;
        goto anim_found;
    anim_parent:
        p = *(void **)((u8 *)p + 4);
        goto anim_check;
    anim_check:
        if (p != 0) {
            goto anim_load;
        }
        anim = 0;
    anim_found:
        i = 0;
        off = i;
        goto copy60_test;
    copy60_body:
        PSMTXCopy((u8 *)*(void **)((u8 *)self + 0x60) + off, (u8 *)*(void **)((u8 *)node + 0x60) + off);
        off += 0x30;
        i += 1;
    copy60_test:
        if (i < *(s32 *)((u8 *)anim + 8)) {
            goto copy60_body;
        }
        if (*(u32 *)((u8 *)self + 0x64) != 0) {
            i = 0;
            off = i;
            goto copy64_test;
        copy64_body:
            PSMTXCopy((u8 *)*(void **)((u8 *)self + 0x64) + off, (u8 *)*(void **)((u8 *)node + 0x64) + off);
            off += 0x30;
            i += 1;
        copy64_test:
            if (i < *(s32 *)((u8 *)anim + 8)) {
                goto copy64_body;
            }
        }
        fn_8006D378(node);
        PSMTXCopy((u8 *)self + 0x10, (u8 *)node + 0x10);
        if (*(u32 *)((u8 *)self + 0x54) != 0) {
            fn_801505A8(self, node);
        }
        *(f32 *)((u8 *)node + 0x58) = *(f32 *)((u8 *)self + 0x58);
    }

    self = (void *)(count - 1);
    if ((s32)self - 1 < 0) {
        goto root_walk;
    }

    count = (s32)fn_800C4638(0xA0, lbl_8026B590 + 0x27, 0);
    if ((void *)count == 0) {
        Game_Assert(lbl_8026B590 + 0x28, 0x46, lbl_8026B590 + 0x31);
    }
    fn_800618E4((void *)count);
    *(u32 *)count |= 4;
    *(u32 *)count |= *(u32 *)node | flags;
    *(void **)((u8 *)count + 4) = node;
    *(u32 *)((u8 *)count + 0x90) = *(u32 *)((u8 *)node + 0x90);
    *(void **)((u8 *)node + 0x8C) = (void *)count;
    GActor_Finalize((void *)count);
    ((u8 *)count)[0x87] = ((u8 *)node)[0x87];

    if (node != 0 && (void *)count != 0) {
        off = 0;
        i = (s32)GActor_GetNodeTable(node);
        anim = (void *)off;
        goto copy60b_test;
    copy60b_body:
        PSMTXCopy((u8 *)*(void **)((u8 *)node + 0x60) + (s32)anim, (u8 *)*(void **)((u8 *)count + 0x60) + (s32)anim);
        anim = (void *)((s32)anim + 0x30);
        off += 1;
    copy60b_test:
        if (off < *(s32 *)((u8 *)i + 8)) {
            goto copy60b_body;
        }
        if (*(u32 *)((u8 *)node + 0x64) != 0) {
            off = 0;
            anim = (void *)off;
            goto copy64b_test;
        copy64b_body:
            PSMTXCopy((u8 *)*(void **)((u8 *)node + 0x64) + (s32)anim, (u8 *)*(void **)((u8 *)count + 0x64) + (s32)anim);
            anim = (void *)((s32)anim + 0x30);
            off += 1;
        copy64b_test:
            if (off < *(s32 *)((u8 *)i + 8)) {
                goto copy64b_body;
            }
        }
        fn_8006D378((void *)count);
        PSMTXCopy((u8 *)node + 0x10, (u8 *)count + 0x10);
        if (*(u32 *)((u8 *)node + 0x54) != 0) {
            fn_801505A8(node, (void *)count);
        }
        *(f32 *)((u8 *)count + 0x58) = *(f32 *)((u8 *)node + 0x58);
    }

    i = (s32)self - 1;
    if (i - 1 >= 0) {
        off = (s32)GActor_Create();
        *(u32 *)off |= *(u32 *)count | flags;
        *(void **)((u8 *)off + 4) = (void *)count;
        *(u32 *)((u8 *)off + 0x90) = *(u32 *)((u8 *)count + 0x90);
        *(void **)((u8 *)count + 0x8C) = (void *)off;
        GActor_Finalize((void *)off);
        ((u8 *)off)[0x87] = ((u8 *)count)[0x87];
        fn_8005F12C((void *)count, (void *)off);
        fn_8005EC18((void *)off, i - 1, flags);
        fn_8005F230((void *)off);
    }

    self = fn_8005F410((void *)count);
    if (self != 0) {
        flags = fn_8005F378((void *)count);
        i = fn_8005F3B8((void *)count);
        {
            u8 t;
            u8 alpha;
            *(u32 *)sp8 = *(u32 *)((u8 *)self + 0x88);
            t = ((u8 *)self)[0xB];
            alpha = (u8)(((t - (t * i) / (flags + 1)) * sp8[3]) / 255);
            sp8[3] = alpha;
            Model_SetAlpha((void *)count, alpha);
            Model_SetColor((void *)count, sp8[0], sp8[1], sp8[2]);
        }
    }

root_walk:
    {
        void *root = node;
        void *w;
        void *n;
    root_loop:
        n = *(void **)((u8 *)root + 4);
        if (n != 0 && *(u32 *)((u8 *)n + 0x8C) != 0) {
            root = n;
            goto root_loop;
        }
        if (root == 0) {
            return;
        }

        w = node;
    count_parent:
        n = *(void **)((u8 *)w + 4);
        if (n != 0 && *(u32 *)((u8 *)n + 0x8C) != 0) {
            w = n;
            goto count_parent;
        }
        i = 0;
    count_child:
        w = *(void **)((u8 *)w + 0x8C);
        if (w != 0) {
            i += 1;
            goto count_child;
        }

        w = node;
    depth_parent:
        n = *(void **)((u8 *)w + 4);
        if (n != 0 && *(u32 *)((u8 *)n + 0x8C) != 0) {
            w = n;
            goto depth_parent;
        }
        off = 0;
    depth_loop:
        if (w != node) {
            goto depth_step;
        }
        goto depth_done;
    depth_step:
        w = *(void **)((u8 *)w + 0x8C);
        if (w != 0) {
            off += 1;
            goto depth_loop;
        }
        off = 0;
    depth_done:

        *(u32 *)spC = *(u32 *)((u8 *)root + 0x88);
        {
            u8 t = ((u8 *)root)[0xB];
            u8 alpha = (u8)(((t - (t * off) / (i + 1)) * spC[3]) / 255);
            spC[3] = alpha;
            ((u8 *)node)[0xB] = alpha;
            if (alpha != 0xFF) {
                *(u32 *)node |= 0x20;
            } else {
                *(u32 *)node &= ~0x20;
            }
        }
        ((u8 *)node)[8] = spC[0];
        ((u8 *)node)[9] = spC[1];
        ((u8 *)node)[10] = spC[2];
    }
}
#pragma pop
void fn_8005F12C(void *arg0, void *arg1)
{
  void PSMTXCopy(void *, void *);
  void *new_var2;
  void fn_8006D378(void *);
  void fn_801505A8(void *, void *);
  s32 offset;
  u32 info;
  s32 i;
  u32 dest;
  u32 source;
  s32 new_var;
  u32 node;
  ;
  new_var2 = arg1;
  dest = (u32) new_var2;
  if (((u32) arg0) == 0)
  {
    return;
  }
  if (dest == 0)
  {
    return;
  }
  node = source;
  while (node != 0)
  {
    info = *((u32 *) (node + 0x40));
    if (info != 0)
    {
      break;
    }
    ;
  }

  if ((*((u32 *) (node + 4))) == 0)
  {
    info = 0;
  }
  i = 0;
  offset = 0;
  while (i < (*((s32 *) (info + 8))))
  {
    PSMTXCopy((void *) ((*((u32 *) (((u32) arg0) + 0x60))) + offset), (void *) ((*((u32 *) (dest + 0x60))) + offset));
    offset += 0x30;
    i++;
  }

  if ((*((u32 *) (((u32) arg0) + 0x64))) != 0)
  {
    i = 0;
    offset = 0;
    while (i < (*((s32 *) (info + 8))))
    {
      new_var = offset;
      PSMTXCopy((void *) ((*((u32 *) (((u32) arg0) + 0x64))) + new_var), (void *) ((*((u32 *) (dest + 0x64))) + new_var));
      offset += 0x30;
      i++;
    }

  }
  fn_8006D378((void *) dest);
  PSMTXCopy((void *) (((u32) arg0) + 0x10), (void *) (dest + 0x10));
  if ((*((u32 *) (((u32) arg0) + 0x54))) != 0)
  {
    fn_801505A8((void *) ((u32) arg0), (void *) dest);
  }
  *((f32 *) (dest + 0x58)) = *((f32 *) (((u32) arg0) + 0x58));
}

#pragma global_optimizer on
void fn_8005F230(void *node) {
#pragma cplusplus on
    struct Chain {
        static void *root(void *p) {
            for (;;) {
                void *n=M2C_FIELD(p,void **,4);
                if(n && M2C_FIELD(n,u32 *,0x8C)) p=n;
                else return p;
            }
        }
        static s32 count(void *p) {
            s32 i;
            p=root(p);
            i=0;
            for (;;) {
                p=M2C_FIELD(p,void **,0x8C);
                if(p) i++; else break;
            }
            return i;
        }
        static s32 index(void *node) {
            s32 i;
            void *p=root(node);
            i=0;
            for (;;) {
                if(p==node) return i;
                p=M2C_FIELD(p,void **,0x8C);
                if(p) i++; else break;
            }
            return 0;
        }
    };
    u8 color[4];
    void *root=Chain::root(node);
    if(root) {
        s32 count=Chain::count(node);
        s32 index=Chain::index(node);
        s32 t; s32 alpha;
        *(u32 *)color=M2C_FIELD(root,u32 *,0x88);
        t=M2C_FIELD(root,u8 *,0xB);
        alpha=((t-(t*index)/(count+1))*color[3])/255;
        color[3]=alpha;
        M2C_FIELD(node,u8 *,0xB)=alpha;
        if((u8)alpha!=255) M2C_FIELD(node,u32 *,0)|=0x20;
        else M2C_FIELD(node,u32 *,0)&=~0x20;
        M2C_FIELD(node,u8 *,8)=color[0];
        M2C_FIELD(node,u8 *,9)=color[1];
        M2C_FIELD(node,u8 *,10)=color[2];
    }
#pragma cplusplus reset
}

s32 fn_8005F378(void *node) {
    void *child;
    unsigned int count;

loop:
    child = *(void **)((u8 *)node + 4);
    if (child != NULL && *(u32 *)((u8 *)child + 0x8C) != 0U) {
        node = child;
        goto loop;
    }
    count = 0;
    for (;;) {
        node = *(void **)((u8 *)node + 0x8C);
        if (node == NULL) {
            break;
        }
        count += 1;
    }
    return count;
}

s32 fn_8005F3B8(void *arg0) {
    void *var_r4;
    void *temp_r0;
    void *temp_r5;
    unsigned int var_r5;

    var_r4 = arg0;
loop_1:
    temp_r5 = M2C_FIELD(var_r4, void **, 4);
    if ((temp_r5 != NULL) && (M2C_FIELD(temp_r5, u32 *, 0x8C) != 0U)) {
        var_r4 = temp_r5;
        goto loop_1;
    }
    var_r5 = 0;
loop_5:
    if (var_r4 == arg0) {
        return var_r5;
    }
    temp_r0 = M2C_FIELD(var_r4, void **, 0x8C);
    if (temp_r0 != NULL) {
        var_r4 = temp_r0;
        var_r5 += 1;
        goto loop_5;
    }
    return 0;
}

#pragma peephole off
void *fn_8005F410(void *arg0)
{
    void *next;

    for (;;) {
        next = *(void **)((u8 *)arg0 + 4);
        if (next == NULL) {
            return arg0;
        }
        if (*(void **)((u8 *)next + 0x8c) == NULL) {
            return arg0;
        }
        arg0 = next;
    }
}
#pragma peephole on
void fn_8005F434(void *arg0, void *arg1, void *arg2) {
    void *fn_8006D910(void *, void *);
    void fn_8006D8E8(void *);
    void *saved;
    void *temp;

    saved = *(void **)((u8 *)arg0 + 0x4C);
    temp = fn_8006D910(arg1, arg2);
    if (temp != *(void **)((u8 *)arg0 + 0x4C)) {
        *(void **)((u8 *)arg0 + 0x4C) = temp;
    }
    if (saved != NULL) {
        fn_8006D8E8(saved);
    }
}

void GActor_LoadTpl(void *arg0, void *arg1) {
    void *fn_8006D910(void *, void *);
    void fn_8006D8E8(void *);
    void *saved;
    void *temp;

    saved = *(void **)((u8 *)arg0 + 0x4C);
    temp = fn_8006D910(arg1, 0);
    if (temp != *(void **)((u8 *)arg0 + 0x4C)) {
        *(void **)((u8 *)arg0 + 0x4C) = temp;
    }
    if (saved != NULL) {
        fn_8006D8E8(saved);
    }
}

extern u32 fn_80065E88(s32, s32);
extern void fn_80065E68(void);
void GActor_LoadG(void *arg0, s32 arg1) {
    void *fn_80065E88(s32, s32);
    void fn_80065E68(void *);
    void *saved;
    void *temp;

    saved = *(void **)((u8 *)arg0 + 0x40);
    temp = fn_80065E88(arg1, 0);
    if (temp != *(void **)((u8 *)arg0 + 0x40)) {
        *(void **)((u8 *)arg0 + 0x40) = temp;
    }
    if (saved != NULL) {
        fn_80065E68(saved);
    }
}

void GActor_LoadGs(void *arg0, void *arg1) {
    void *fn_8006CCBC(void *, void *);
    void fn_8006CC6C(void *);
    void *saved;
    void *temp;

    saved = *(void **)((u8 *)arg0 + 0x48);
    temp = fn_8006CCBC(arg1, 0);
    if (temp != *(void **)((u8 *)arg0 + 0x48)) {
        *(void **)((u8 *)arg0 + 0x48) = temp;
    }
    if (saved != NULL) {
        fn_8006CC6C(saved);
    }
}

void fn_8005F5B4(void *arg0, s32 arg1) {
    void *fn_80063954(s32, s32);
    void fn_80063934(void *);
    void *fn_80065634(void ***, s32);
#pragma cplusplus on
    struct Lookup {
        static u8 *find(u8 *p) {
            while (p) {
                u8 *a = *(u8 **)(p + 0x44);
                if (a) return a;
                p = *(u8 **)(p + 4);
            }
            return 0;
        }
    };
    void *old;
    u8 *self;
    void *neu;
    u8 *anim;
    u8 *entry;
    s32 i;
    u8 *r5;
    u8 *r6;
    f32 frame;

    old = *(void **)((u8 *)arg0 + 0x44);
    self = (u8 *)arg0;
    neu = fn_80063954(arg1, 0);
    if (neu != *(void **)(self + 0x44)) {
        *(void **)(self + 0x44) = neu;
        frame = (f32)*(s32 *)((u8 *)neu + 0x14);
        anim = Lookup::find(self);
        if (anim) {
            *(u32 *)self &= ~0x10;
            if (frame < 0.0f || frame > (f32)*(s32 *)(anim + 0x18)) {
                frame = (f32)*(s32 *)(anim + 0x18);
                *(u32 *)self |= 0x10;
            }
            if (frame <= (f32)*(s32 *)(anim + 0x14))
                frame = (f32)*(s32 *)(anim + 0x14);
            *(u16 *)(self + 0x7C) = 0xFFFF;
            *(u16 *)(self + 0x7E) = 0xFFFF;
            *(u16 *)(self + 0x80) = 0xFFFF;
            *(u16 *)(self + 0x82) = 0xFFFF;
            entry = (u8 *)fn_80065634((void ***)anim, (s32)frame);
            if (entry) {
                r5 = entry;
                r6 = self;
                for (i = 0; i < *(u16 *)(entry + 2); i++) {
                    *(u16 *)(r6 + 0x7C) = *(u16 *)(r5 + 4);
                    r5 += 2;
                    r6 += 2;
                }
            }
            *(f32 *)(self + 0x58) = frame;
        }
    }
    if (old) {
        fn_80063934(old);
    }
#pragma cplusplus reset
}

void fn_8005F780(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x84) = arg1;
}

void fn_8005F788(u8 *arg0, s32 arg1, u8 arg2) {
    arg0[0x86] = arg1;
    arg0[0x85] = (u8)(1 << arg1);
    if (arg2 != 0) {
        arg0[0x85] |= 0xF0;
    }
}

void Model_SetAlpha(void *arg0, u8 arg1) {
    M2C_FIELD(arg0, u8 *, 0xB) = arg1;
    if (arg1 != 0xFF) {
        M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) | 0x20);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) & 0xFFFFFFDF);
}

void Model_SetColor(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    M2C_FIELD(arg0, s8 *, 8) = arg1;
    M2C_FIELD(arg0, s8 *, 9) = arg2;
    M2C_FIELD(arg0, s8 *, 0xA) = arg3;
}

#pragma global_optimizer off
#pragma opt_strength_reduction off
