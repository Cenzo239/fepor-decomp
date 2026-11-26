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

s32 fn_800A022C(void) {
    M2C_UNK fn_80018E0C();
    fn_80018E0C();
    return 0;
}

void *fn_800A0250(void) {
    extern u16 gMenuCmdStrings[];
    return (char *)gMenuCmdStrings + 0x3C3;
}

s32 fn_800A0260(s32 a, s32 b, void *arg2) {
    return fn_800A0260_Body(arg2, 2);
}

u32 fn_800A02C8(void) {
    extern u8 lbl_80366E24;
    u32 var_r3;

    var_r3 = 2;
    if (lbl_80366E24 != 0) {
        var_r3 = 0;
    }
    return (u8)var_r3;
}

void *fn_800A02E4(void) {
    extern u16 gMenuCmdStrings[];
    return (u8 *)gMenuCmdStrings + 0x3E0;
}

#pragma global_optimizer off
