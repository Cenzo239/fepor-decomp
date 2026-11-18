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

typedef struct HashKey {
    u32 h1;
    u32 h2;
} HashKey;

static inline HashKey Res_HashPair(char *str) {
    HashKey key;
    key.h2 = key.h1 = 0;
    while (*str) {
        key.h1 = (s8)*str + key.h1 * 37;
        key.h2 = (s8)*str + key.h2 * 31;
        str++;
    }
    return key;
}

static inline u8 *Res_AllocEntry(char *name, void *value) {
    extern u8 lbl_802ADB20[];
    u8 *entry;
    s32 slot;
    u32 hash;
    char *str;
    do {
        slot = *(s32 *)lbl_802ADB20;
        entry = *(u8 **)(lbl_802ADB20 + 4);
        entry += slot * 16;
        *(s32 *)lbl_802ADB20 = slot + 1;
        *(s32 *)lbl_802ADB20 %= 0x2800;
    } while (*(char **)(entry + 8));
    *(u8 **)entry = 0;
    hash = 0;
    for(str=name; *str; str++)
        hash = (s8)*str + hash * 31;
    *(u32 *)(entry+4) = hash;
    *(char **)(entry+8) = name;
    *(void **)(entry+12) = value;
    return entry;
}

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

    u8 *bucket;
    u8 *entry;
    u8 *next;
    u8 *prev;
    s32 hash31;
    char *str;
    u32 hash37;
    u8 ch;
    u32 index;
    s32 slot;

    hash37 = 0;
    hash31 = hash37;
    str = arg0;

    while ((s8)(ch = *str) != 0) {
        hash37 = (s8)ch + hash37 * 37;
        hash31 = (s8)ch + hash31 * 31;
        str++;
    }

    index = hash37 % 0x1FD;
    bucket = (u8 *)lbl_802ADB20 + index * 4;

    entry = *(u8 **)(bucket + 8);
    *(u32 *)(bucket + 0x7FC) += 1;
    bucket += 8;

    if (entry == 0) {
        do {
            slot = *(u32 *)lbl_802ADB20;
            entry = *(u8 **)((u8 *)lbl_802ADB20 + 4);
            entry += slot * 0x10;
            *(u32 *)lbl_802ADB20 = slot + 1;
            *(u32 *)lbl_802ADB20 = (slot + 1) % 0x2800;
        } while (*(u32 *)(entry + 8) != 0);

        *(u32 *)entry = 0;

        hash31 = 0;
        str = arg0;

        while (*str != 0) {
            hash31 = (s8)*str++ + hash31 * 31;
        }

        *(s32 *)(entry + 4) = hash31;
        *(char **)(entry + 8) = arg0;
        *(void **)(entry + 0xC) = arg1;
        *(u8 **)bucket = entry;
    } else {
        while(entry != 0) {
            prev = entry;
            entry = *(u8 **)entry;
        }

        do {
            slot = *(u32 *)lbl_802ADB20;
            next = *(u8 **)((u8 *)lbl_802ADB20 + 4);
            next += slot * 0x10;
            *(u32 *)lbl_802ADB20 = slot + 1;
            *(u32 *)lbl_802ADB20 = (slot + 1) % 0x2800;
        } while (*(u32 *)(next + 8) != 0);

        *(u32 *)next = 0;

        hash31 = 0;
        str = arg0;

        while (*str != 0) {
            hash31 = (s8)*str++ + hash31 * 31;
        }

        *(s32 *)(next + 4) = hash31;
        *(char **)(next + 8) = arg0;
        *(void **)(next + 0xC) = arg1;
        *(u8 **)prev = next;
    }
}
#pragma opt_propagation reset
