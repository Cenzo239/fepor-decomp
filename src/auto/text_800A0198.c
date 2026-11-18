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

u32 fn_800A0198(void) {
    extern u8 lbl_80367708;
    u32 var_r3;

    var_r3 = 2;
    if (lbl_80367708 != 0) {
        var_r3 = 0;
    }
    return (u8)var_r3;
}

void fn_800A01B4(void) {
    M2C_UNK fn_80018AAC();
    fn_80018AAC();
}

#pragma cplusplus on
extern "C" s32 fn_800A01D4(void *arg0, void *arg1, s32 arg2) {
    struct Obj {
        virtual s32 v0(void *, s32) = 0;
        virtual s32 v1(void *, s32) = 0;
        virtual s32 v2(void *, s32) = 0;
        virtual s32 v3(void *, s32) = 0;
        virtual s32 v4(void *, s32) = 0;
        virtual s32 v5(void *, s32) = 0;
        virtual s32 v6(void *, s32) = 0;
        virtual s32 v7(void *, s32) = 0;
        virtual s32 v8(void *, s32) = 0;
        virtual s32 v9(void *, s32) = 0;
    };
    extern void *gPadInput;
    s32 temp_r8;

    temp_r8 = M2C_FIELD(gPadInput, s32 *, 4);
    if (temp_r8 & (M2C_FIELD(gPadInput, s32 *, 8) ^ temp_r8) & 0x03000003) {
        return ((Obj *)arg0)->v9(arg1, arg2);
    }
    return 0;
}
#pragma cplusplus reset
