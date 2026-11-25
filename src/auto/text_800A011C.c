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

#pragma push
#pragma opt_lifetimes on
#pragma cplusplus off
#pragma global_optimizer on
#pragma optimization_level 4
#pragma scheduling on
#pragma peephole on
#pragma opt_strength_reduction on
#pragma opt_common_subs on
#pragma opt_loop_invariants on
#pragma opt_propagation on
#pragma opt_lifetimes on
#pragma dont_inline off
#pragma use_lmw_stmw off
s32 fn_800A011C(s32 a, s32 b, void *item) {
    extern u8 lbl_80366E25;
    enum { MENU_TOGGLE_ON = 0, MENU_TOGGLE_OFF = 2 };

    lbl_80366E25 ^= 1;
    *((u8 *)item + 0x39) = lbl_80366E25 ? MENU_TOGGLE_ON : MENU_TOGGLE_OFF;
    return 0;
}
#pragma pop
extern u8 lbl_80366E25;
