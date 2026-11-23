/* Functions from 0x80006264 to 0x80011968, found by decomp-toolkit. */
#include "common.h"
#include "process.h"

static inline u32 Process_CompareName(const s8 *a, const s8 *b)
{
    while (*a | *b) {
        if (*a != *b) return *a - *b;
        a++;
        b++;
    }
    return 0;
}

static inline u32 Process_CompareNameExt(const u8 *a, const u8 *b)
{
    s32 c2;
    s32 c1;
    u32 raw2;
    u32 raw1;
    goto ld;
cmp:
    if ((s8)raw1 != (s8)raw2)
        return (u32)(c1 - c2);
    a++;
    b++;
ld:
    raw1 = *a;
    raw2 = *b;
    c1 = (s8)raw1;
    c2 = (s8)raw2;
    if ((c1 | c2) != 0)
        goto cmp;
    return 0;
}

static inline void *Process_FindName(const s8 *source)
{
    extern u8 gProcesses[];
    u8 *entry = gProcesses;
    s32 i;
    for (i = 0; i < 256; i++, entry += 0x70) {
        if (*(u32 *)entry != 0 && Process_CompareName(*(s8 **)(entry + 0x14), source) == 0) return entry;
    }
    return 0;
}

typedef struct {
    void *unk0;
    void *unk4;
    s32 unk8;
} Struct_8000B090;

extern s32 lbl_802AEE20[5]; // array of 5 pointers
extern f64 lbl_80368C28;    // global float constant
extern u16 jumptable_80283AE8[];

#pragma optimization_level 2

#pragma optimization_level reset

#pragma opt_unroll off

#pragma global_optimizer reset

#pragma global_optimizer on
#pragma opt_strength_reduction on

#pragma optimization_level 4
#pragma scheduling on

#pragma scheduling reset
#pragma optimization_level reset

#pragma optimization_level 3

#pragma optimization_level reset

#pragma opt_unroll reset

#pragma global_optimizer off
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma global_optimizer reset
extern f64 lbl_80368C28;

#pragma global_optimizer off
#pragma scheduling off

#pragma scheduling reset
#pragma global_optimizer reset

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer on

#pragma use_lmw_stmw on

extern u16 gPrim2D;

/* Build XY(Z) translate and optional uniform scale into gPrim2D's matrix; store z and clear flag 0x800. */

#pragma peephole off

#pragma peephole on

#pragma optimization_level 3

#pragma optimization_level reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset
void *fn_800C4638(s32, void *, s32);

#pragma peephole on

#pragma peephole reset

#pragma global_optimizer off
#pragma scheduling off
#pragma opt_common_subs off

#pragma opt_common_subs on
#pragma scheduling on
#pragma global_optimizer on

#pragma global_optimizer off
#pragma opt_strength_reduction off
#pragma opt_common_subs off

#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
#pragma global_optimizer reset

#pragma optimization_level 3

#pragma optimization_level reset

extern void *(*lbl_80366DA0)(s32);
extern f32 gFloat1, lbl_80368BB8, lbl_80368B98;
extern u32 gProcessOpcodeTables[9];

#pragma use_lmw_stmw on
#pragma inline_depth(0)
#pragma optimization_level 3

#pragma optimization_level 4

#pragma global_optimizer off

#pragma global_optimizer reset

/* Find the first process whose code pointer matches `code`. */

void Process_RunScript(void *);
void Process_ClearFunc(void *);
/* Recursively tick a process subtree: run scripts/funcs with timers, then post callbacks and children. */

/* Recursively destroy a process tree (next and child), run destructors, and return nodes to the freelist. */

extern void *fn_8000A738(void *, s32);
extern void fn_8000B5F0(void *);
extern void fn_8000B70C(void *);

#pragma global_optimizer off

#pragma global_optimizer off

s32 Rand_Range(s32 arg0)
{
  struct RandSt
  {
    u16 a;
    u16 b;
    u16 c;
  };
  extern struct RandSt lbl_80367150;
  unsigned int t6;
  s32 t4;
  s32 s1;
  s32 s0;
  struct RandSt *st;
  st = &lbl_80367150;
  s0 = lbl_80367150.a;
  s1 = st->b;
  t4 = (st->c * 2) & 0xFFFE;
  t6 = (u16) ((s0 >> 5) + (s1 << 11));
  st->c = t4;
 do { if (s1 & 0x8000) { st->c = 1 + t4; } t6 ^= st->c; st->c = st->b; st->b = lbl_80367150.a; } while (0);
  lbl_80367150.a = t6;
  return (arg0 * ((u16) t6)) / 65536;
}
#pragma global_optimizer reset
void fn_8000CF4C(u32 arg0)
{
  struct RandSt
  {
    u16 a;
    u16 b;
    u16 c;
  };
  extern struct RandSt lbl_80367150;
  extern u32 lbl_80267D30[];
  u32 stack[4];
  u16 *tbl;
  struct RandSt *st;
  u32 rem7;
  u32 *p = lbl_80267D30;
  s32 rem23;
  s32 s0;
  s32 s2;
  s32 t4;
  s32 s1;
  u16 t6;
  ;
  {
    stack[0] = p[0];
    stack[1] = p[1];
    stack[2] = p[2];
    stack[3] = p[3];
  }
  if (1)
  {
    ;
    st = &lbl_80367150;
  }
  lbl_80367150.a = ((u16 *) stack)[(arg0 % 7U) & 7];
  st->b = ((u16 *) stack)[((arg0 % 7U) + 1) & 7];
  st->c = ((u16 *) stack)[((arg0 % 7U) + 2) & 7];
  for (rem23 = (s32) (arg0 % 23U); rem23 > 0; rem23--)
  {
    s1 = st->b;
    s2 = st->c;
    s0 = lbl_80367150.a;
    ;
    t6 = (u16) ((s1 << 11) + (s0 >> 5));
    st->c = (s2 * 2) & 0xFFFE;
    if (s1 & 0x8000)
    {
      st->c = ((s2 * 2) & 0xFFFE) + 1;
    }
    t6 ^= st->c;
    st->c = st->b;
    st->b = lbl_80367150.a;
    lbl_80367150.a = t6;
  }

}

void fn_8000D048(void)
{
    s32 DebugPrint(const char *, ...);
    extern u8 lbl_802ADB20[];
    extern u8 lbl_80267D40[];
    u32 *table;
    s32 index;
    s32 total;
    s32 i;
    u8 *entry;

    entry = *(u8 **)(lbl_802ADB20 + 4);
    total = 0;

    for (index = 0; index < 0x2800; index++) {
        if (*(s8 **)(entry + 8) != 0) {
            DebugPrint((const char *)lbl_80267D40, index, *(u32 *)(entry + 0xC), *(u32 *)(entry + 4), *(s8 **)(entry + 8));
            {
                s8 *p = *(s8 **)(entry + 8);
                while (*p++ != 0) {
                    total++;
                }
            }
        }
        entry += 0x10;
    }

    table = (u32 *)lbl_802ADB20;
    for (i = 0; i < 0x1FD; i++) {
        if ((i % 18) == 0) {
            DebugPrint((const char *)(lbl_80267D40 + 0x13));
        }
        DebugPrint((const char *)(lbl_80267D40 + 0x15), table[0x1FF]);
        table++;
    }
    DebugPrint((const char *)(lbl_80267D40 + 0x1A));
    DebugPrint((const char *)(lbl_80267D40 + 0x1D), *(u32 *)lbl_802ADB20);
    DebugPrint((const char *)(lbl_80267D40 + 0x3D), total);
    DebugPrint((const char *)(lbl_80267D40 + 0x59), 0x28FF0);
    DebugPrint((const char *)(lbl_80267D40 + 0x13));
}

s32 fn_8000D1B4(s32 arg0) {
extern u8 lbl_802ADB20[];
s32 off=arg0*16;
u8 *p=*(u8 **)(lbl_802ADB20+4);
p+=off;
return *(s32 *)(p+8);
}

typedef struct HashKey {
    u32 h1;
    u32 h2;
} HashKey;

#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset
#pragma inline_depth reset
#pragma global_optimizer on
#pragma optimization_level 4
s32 Hash_Remove(s8 *str) {
    extern u8 lbl_802ADB20[];
    HashKey key;
    u32 **bucket;
    u32 *node;
    u32 *prev;
    u32 index;

    key.h2 = 0;
    key.h1 = 0;
    key.h2 = key.h1;
    while (*str != 0) {
        key.h1 = *str + key.h1 * 37;
        key.h2 = *str + key.h2 * 31;
        str++;
    }
    index = key.h1 % 509;
    bucket = (u32 **)(lbl_802ADB20 + 8) + index;
    for (node = *bucket; node != NULL; node = (u32 *)node[0]) {
        if (key.h2 == node[1]) {
            *(s32 *)(lbl_802ADB20 + index * 4 + 0x7fc) -= 1;
            if (*bucket == node) {
                *bucket = (u32 *)node[0];
                node[2] = 0;
                return 1;
            }
            for (prev = *bucket; (u32 *)prev[0] != node; prev = (u32 *)prev[0]) {
            }
            prev[0] = node[0];
            node[2] = 0;
            return 1;
        }
    }
    return 0;
}
s32 Hash_Lookup(s8 *str) {
    extern u8 lbl_802ADB20[];
    struct {
        u32 h2;
        u32 h1;
    } key;
    u32 *node;

    if (str == NULL) {
        return 0;
    }
    key.h2 = 0;
    key.h1 = 0;
    key.h2 = key.h1;
    while (*str != 0) {
        key.h1 = *str + key.h1 * 37;
        key.h2 = *str + key.h2 * 31;
        str++;
    }
    for (node = ((u32 **)(lbl_802ADB20 + 8))[key.h1 % 509]; node != NULL; node = (u32 *)node[0]) {
        if (key.h2 == node[1]) {
            return node[3];
        }
    }
    return 0;
}
#pragma optimization_level reset
#pragma global_optimizer reset
extern struct UnkStruct_802AEE80 gUnk_802AEE80;

extern s32 gUnknown_0x80369C84;
extern s32 gUnknown_0x80369C88;

