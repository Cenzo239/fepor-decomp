/* Functions from 0x8007C5E4 to 0x8009F0BC, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
static inline void MenuTypeCleanup(void *arg0, u8 *base, s32 first) {
    void fn_8000A408(void *);
    if (*(u8 *)((u8 *)arg0 + 0x2b) != 0x7b) {
        u32 value = *(u32 *)arg0;
        if (value != (u32)(base + 0x7c) && value != (u32)(base + first) && value != (u32)(base + 0x58) && value != (u32)(base + 0x48)) fn_8000A408(arg0);
    }
}
static inline int TypeEquals_80089490(u32 value, u8 *base, s32 offset) {
    return value == (u32)(base + offset);
}
typedef struct {
    f32 x, y;
    u8 unk8[4];
    s8 next;
    u8 type;
    u8 unkE[6];
} Menu888Entry;
extern void* lbl_803674E8;
extern f64 lbl_80369688;
extern f32 lbl_803696C8;
typedef struct { u16 a, b, c; } Fn89980Struct;
typedef struct { f32 a, b; } FloatPair892E8;
typedef struct {
    void *f00;
    u8 pad04[0x44];
    void *f48;
    u8 pad50[0xC];
    void *f58;
    u8 pad5C[0x20];
    void *f7C;
} Struct_80089490;

extern s32 gSaveDataBase;
extern u8 lbl_8026CC58[];
extern u8 lbl_80289998[];
extern f32 gScreenOrigin;
extern f32 lbl_803696A8;
extern f32 lbl_803696AC;
extern f64 lbl_803696C0;

extern void* gActiveFace;
extern s32 gFaceDbgMouthStartStr;
extern s32 gFaceDbgMouthEndStr;
extern f64 lbl_803693C8;
extern f32 lbl_803693D4;
extern f32 lbl_803693D8;
extern f32 gFaceDbgTextScale;

extern u8 gBattleState[1400];

extern u16 *lbl_803674E0;

#pragma inline

extern f32 lbl_8036A118;
extern f32 lbl_8036A120;
extern f32 lbl_8036A130;
extern f32 gTextScale2;

extern f32 lbl_80369768;
extern u16 lbl_80289A60[];

extern u8 lbl_80289B00[16];

extern void* fn_800980D4(s32 arg0);
extern void fn_8017E394(void* arg0, void* arg1, void* arg2, s32 arg3);

extern u8 lbl_80289EB8[16];

extern f32 lbl_803697E0;
extern f32 lbl_803697E4;

/* Draw the unit info panel: child widgets, gradient bar, and status text. */

#pragma use_lmw_stmw on

#pragma optimization_level 3
#pragma opt_strength_reduction off

#pragma optimization_level reset

#pragma scheduling on

#pragma scheduling reset

void fn_8000BFEC(void (*arg0)(void *));
void fn_80089490(void *);

#pragma opt_strength_reduction off

#pragma opt_propagation on
static inline u8 *fn_80089490_add(u8 *base, s32 off) { return base + off; }
#pragma opt_dead_code off
static inline s32 IsSpecialAddr(u32 v, u8 *base, s32 off) {
    return v == (u32)(base + off);
}

#pragma optimization_level 4
#pragma opt_strength_reduction on
#pragma opt_dead_code on
void fn_80089490(void *arg0) {
    extern u8 lbl_80289950[];
    void fn_8000A408(void *);
    u8 *tbl = lbl_80289950;
    u8 *p;
    u32 v;
    if (*(u8 *)((u8 *)arg0 + 0x2B) != 0x7B) {
        v = *(u32 *)arg0;
        p = tbl + 0x7C;
        if (v != (u32)p && v != (u32)(p - 0x7C) && v != (u32)(p - 0x24) && v != (u32)(p - 0x34))
            fn_8000A408(arg0);
    }
}
#pragma optimization_level reset

