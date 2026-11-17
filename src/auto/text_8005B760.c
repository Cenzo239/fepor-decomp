/* Functions from 0x8005AE20 to 0x80072408, found by decomp-toolkit. */
#include "common.h"
#include "global.h"

typedef struct MaterialColor { u8 r, g, b, a; } MaterialColor;

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

s32 fn_8005B760(s32 arg0) {
    switch (arg0) {
    case 10:
    case 26:
        return 0x1A;
    case 24:
        return 0x18;
    case 25:
        return 0x19;
    default:
        return 0;
    }
}
#pragma optimization_level reset
