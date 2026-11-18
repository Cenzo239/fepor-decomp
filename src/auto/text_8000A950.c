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
    u32 raw1;
    u32 raw2;
    s32 c1;
    s32 c2;
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

s32 fn_8000A950(void *arg0) {
    extern u8 gProcesses[];
    u8 *entry;
    u8 *search;
    s32 i;
    u8 *p;
    u32 diff;

    p = *(u8 **)((u8 *)arg0 + 4);
    search = *(u8 **)(p + 4);
    entry = gProcesses;
    for (i = 0; i < 256; i++, entry += 0x70) {
        if (*(u32 *)entry != 0) {
            diff = Process_CompareNameExt(*(u8 **)(entry + 0x14), search);
            if (diff != 0)
                goto next;
            goto found;
        }
    next:
        ;
    }
    entry = 0;
found:
    if (entry != 0) {
        *(u32 *)(entry + 0x10) = 0;
        *(u32 *)((u8 *)arg0 + 4) += 8;
        return 1;
    }
    return 0;
}
#pragma peephole reset
