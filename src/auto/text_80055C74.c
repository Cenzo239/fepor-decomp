/* Functions from 0x80055C74 to 0x8005A29C, found by decomp-toolkit. */
#include "common.h"

s32 fn_80055C74(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 8);
}

u8 fn_80055C7C(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 5);
}

s32 fn_80055C84(s32 *arg0) {
    return *arg0;
}

void *Process_CreateChild(void *, s32, void *);             /* extern */
s32 strcpy(void *, s32);                       /* extern */
extern u16 lbl_80285BD0[16];
extern const f64 lbl_80369160;    /* 0.5 double constant, .sdata2 */
void fn_80055C8C(s32 arg0, s32 arg1, s32 arg2) {
    void *Process_CreateChild(void *, s32);
    void *temp_r3;

    temp_r3 = Process_CreateChild(lbl_80285BD0, arg2);
    *(s32 *)((char *)temp_r3 + 0x6C) = arg1;
    strcpy((char *)temp_r3 + 0x30, arg0);
}
