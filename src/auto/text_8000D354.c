/* Functions from 0x80006264 to 0x80011968, found by decomp-toolkit. */
#include "common.h"

typedef struct {
    void *unk0;
    void *unk4;
    s32 unk8;
} Struct_8000B090;

extern s32 lbl_802AEE20[5]; // array of 5 pointers
extern f64 lbl_80368C28;    // global float constant
extern u16 jumptable_80283AE8[];

extern f64 lbl_80368C28;

extern u16 gPrim2D;

extern void *(*lbl_80366DA0)(s32);
extern f32 gFloat1, lbl_80368BB8, lbl_80368B98;
extern u32 gProcessOpcodeTables[9];

extern void *fn_8000A738(void *, s32);
extern void fn_8000B5F0(void *);
extern void fn_8000B70C(void *);

typedef struct ResHashNode {
    struct ResHashNode *next;
    u32 hash;
    char *name;
    void *value;
} ResHashNode;
typedef struct ResHashTable {
    s32 cursor;
    ResHashNode *pool;
    ResHashNode *buckets[509];
    u32 counts[509];
} ResHashTable;

typedef struct HashKey {
    u32 h1;
    u32 h2;
} HashKey;



extern struct UnkStruct_802AEE80 gUnk_802AEE80;

extern s32 gUnknown_0x80369C84;
extern s32 gUnknown_0x80369C88;

s32 Res_GetByName(s8 *str) {
    extern u8 lbl_802ADB20[];
    struct {
        u32 h1;
        u32 h2;
    } h;
    u32 *node;

    if (str == NULL) {
        return 0;
    }
    h.h2 = 0;
    h.h1 = h.h2;
    while (*str != 0) {
        h.h1 = *str + h.h1 * 37;
        h.h2 = *str + h.h2 * 31;
        str++;
    }
    for (node = ((u32 **)(lbl_802ADB20 + 8))[h.h1 % 509]; node != NULL; node = (u32 *)node[0]) {
        if (h.h2 == node[1]) {
            return node[3];
        }
    }
    return 0;
}

#pragma opt_propagation off
void fn_8000D3EC(char *arg0, void *arg1)
{
  extern u8 lbl_802ADB20[];
  u8 *new_var2;
  u8 *bucket;
  u8 *entry;
  u8 *next;
  u8 *prev;
  u32 hash37;
  char *str;
  int new_var;
  char ch;
  u8 *new_var3;
  u32 index;
  s32 slot;
  u8 **new_var4;
  hash37 = 0;
  index = hash37;
  str = arg0;
  while (((s8) (ch = *str)) != 0)
  {
    hash37 = ((s8) ch) + (hash37 * 37);
    index = ((s8) ch) + (index * 31);
    str++;
  }

  new_var2 = (u8 *) lbl_802ADB20;
  index = hash37 % 0x1FD;
  bucket = new_var2 + (index * 4);
  entry = *((u8 **) (bucket + 8));
  new_var3 = bucket + 0x7FC;
  *((u32 *) new_var3) += 1;
  bucket += 8;
  if (entry == 0)
  {
    do
    {
      slot = *((u32 *) lbl_802ADB20);
      entry = *((u8 **) (((u8 *) lbl_802ADB20) + 4));
      entry += slot * 0x10;
      *((u32 *) lbl_802ADB20) = slot + 1;
      *((u32 *) lbl_802ADB20) = (slot + 1) % 0x2800;
    }
    while ((((*((u32 *) (entry + 8))) & 0xFFFF) & 0xFFFF) != 0);
    *((u32 *) entry) = 0;
    index = 0;
    str = arg0;
    while ((*str) != 0)
    {
      index = ((s8) (*(str++))) + (index * 31);
    }

    *((s32 *) (entry + 4)) = index;
    *((char **) (entry + 8)) = arg0;
    *((void **) (entry + 0xC)) = arg1;
    *((u8 **) bucket) = entry;
  }
  else
  {
    while (entry != 0)
    {
      prev = entry;
      entry = *((u8 **) entry);
    }

    do
    {
      new_var4 = (u8 **) (((u8 *) lbl_802ADB20) + 4);
      slot = *((u32 *) lbl_802ADB20);
      next = *new_var4;
      new_var = slot + 1;
      next += slot * 0x10;
      *((u32 *) lbl_802ADB20) = slot + 1;
      *((u32 *) lbl_802ADB20) = new_var % 0x2800;
    }
    while ((*((u32 *) (next + 8))) != 0);
    *((u32 *) next) = 0;
    index = 0;
    str = arg0;
    while ((*str) != 0)
    {
      index = ((s8) (*(str++))) + (index * 31);
    }

    *((s32 *) (next + 4)) = index;
    *((char **) (next + 8)) = arg0;
    *((void **) (next + 0xC)) = arg1;
    *((u8 **) prev) = next;
  }
}
#pragma opt_propagation reset
