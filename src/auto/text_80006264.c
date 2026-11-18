/* Functions from 0x80006264 to 0x80011968, found by decomp-toolkit. */
#include "common.h"
#include "process.h"

typedef struct {
    void *unk0;
    void *unk4;
    s32 unk8;
} Struct_8000B090;

extern s32 lbl_802AEE20[5]; // array of 5 pointers
extern f64 lbl_80368C28;    // global float constant
extern u16 jumptable_80283AE8[];

#pragma optimization_level 4
#pragma global_optimizer on
s32 fn_80006264(u32 *a,u32 *b,u32 n) {
a--; n>>=2; b--;
do {u32 x=*++a; u32 y=*++b; if(x!=y) goto different;} while(--n!=0);
return 0; different: return 1;
}
#pragma global_optimizer reset
#pragma optimization_level reset
void fn_80006298(u32 *dst, u32 val, u32 n) { n >>= 2; --dst; do { *++dst = val; } while (--n != 0); }
#pragma opt_unroll off
void fn_800062B0(u32 *arg0, u32 arg1, u32 arg2) {
    u32 count;

    count = arg2 >> 3;
    arg0--;

    do {
        *++arg0 = arg1;
        *++arg0 = arg1;
    } while (--count != 0);
}
void fn_800062CC(u32 *dst, u32 *src, u32 n) {
    register u32 tmp;
    dst--;
    n >>= 2;
    src--;
    do {
        tmp = *++src;
        *++dst = tmp;
    } while (--n);
}
#pragma global_optimizer reset
void fn_800062EC(u32 *dst, u32 *src, u32 n) {
    dst--;
    n >>= 3;
    src--;
    do {
        *++dst = *++src;
        *++dst = *++src;
    } while (--n);
}
#pragma global_optimizer on
#pragma opt_strength_reduction on
