/* Functions from 0x8009F85C to 0x800A399C, found by decomp-toolkit. */
#include "common.h"

static inline u8 *MenuCmd_FindStatus(s32 slot) {
    void *Map_GetCursorUnit(void);
    void *fn_80105C5C(void *, u8);
    u8 *unit = Map_GetCursorUnit();
    s32 count = 0;
    s32 i = count;
    for (; i < 0x62; i++) {
        u8 *status = fn_80105C5C(unit + 0x1BC, (u8)i);
        if (status != 0) {
            if (count == slot) return status;
            count++;
        }
    }
    return 0;
}

extern s32 lbl_80367788;
extern u8 lbl_80367704;

/* Draw a menu text item, then overlay the cursor unit's weapon exp and rank letter. */

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset


#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern s32 lbl_8036773C;

extern s32 lbl_80367550;

extern s32 lbl_8036757C;

extern s32 lbl_803676D4;

extern s32 lbl_803676F8;

#pragma global_optimizer off

#pragma opt_lifetimes off

#pragma opt_lifetimes on
#pragma global_optimizer reset
extern u8 lbl_80366E25;

extern u8 lbl_80367708;
#pragma global_optimizer off

#pragma global_optimizer reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma global_optimizer off

s32 fn_800A02F4(s32 a, s32 b, void *arg2) {
    extern u8 lbl_80367707;
    s32 t = lbl_80367707;
    s32 v = 2;

    b = t ^ 1;
    lbl_80367707 = (u8)b;
    if ((u8)b != 0) {
        v = 0;
    }
    *(u8 *)((char *)arg2 + 0x39) = (u8)v;
    return 0;
}
#pragma global_optimizer on
