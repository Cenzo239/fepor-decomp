/* Functions from 0x8007C5E4 to 0x8009F0BC, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
extern void* lbl_803674E8;
extern f32 lbl_803696C8;

extern s32 gSaveDataBase;
extern void *lbl_8026CC58;
extern void *lbl_80289998;
extern f32 gScreenOrigin;
extern f32 lbl_803696A8;
extern f32 lbl_803696AC;

extern void* gActiveFace;
extern s32 gFaceDbgMouthStartStr;
extern s32 lbl_803693C4;
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

#pragma scheduling reset

u8 fn_800981D0(void **arg0) {
    void *temp_r3;
    void *temp_r3_2;
    void *var_r0;
    void *var_r3;

    temp_r3_2 = *arg0;
    if (temp_r3_2 != NULL) {
        var_r0 = M2C_FIELD(temp_r3_2, void **, 0x280);
    } else {
        var_r0 = NULL;
    }
    if (var_r0 != NULL) {
        if (temp_r3_2 != NULL) {
            var_r3 = M2C_FIELD(temp_r3_2, void **, 0x280);
        } else {
            var_r3 = NULL;
        }
        return M2C_FIELD(M2C_FIELD(var_r3, void **, 0x190), u8 *, 8);
    }
    temp_r3 = M2C_FIELD(temp_r3_2, void **, 0x190);
    if (temp_r3 == NULL) {
        return 0U;
    }
    return M2C_FIELD(temp_r3, u8 *, 8);
}

void fn_800983E0(void *arg0, void **arg1) {
    f32 fn_80023068(M2C_UNK *, f32, f32, f32);
    extern M2C_UNK gBattleMap;
    extern f32 lbl_803697D0;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1;
    f32 temp_f2;
    void *temp_r6;
    void *var_r0;
    void *var_r3;
    void *var_r3_2;
    void *var_r3_3;

    temp_r6 = *arg1;
    if (temp_r6 != NULL) {
        var_r0 = M2C_FIELD(temp_r6, void **, 0x280);
    } else {
        var_r0 = NULL;
    }
    if (var_r0 != NULL) {
        if (temp_r6 != NULL) {
            var_r3 = M2C_FIELD(temp_r6, void **, 0x280);
        } else {
            var_r3 = NULL;
        }
        sp8 = M2C_FIELD(var_r3, f32 *, 4);
        if (temp_r6 != NULL) {
            var_r3_2 = M2C_FIELD(temp_r6, void **, 0x280);
        } else {
            var_r3_2 = NULL;
        }
        spC = M2C_FIELD(var_r3_2, f32 *, 8);
        if (temp_r6 != NULL) {
            var_r3_3 = M2C_FIELD(temp_r6, void **, 0x280);
        } else {
            var_r3_3 = NULL;
        }
        sp10 = M2C_FIELD(var_r3_3, f32 *, 0xC);
    } else {
        temp_f1 = lbl_803697D0 + (f32) (s8) M2C_FIELD(temp_r6, u8 *, 0x19E);
        temp_f2 = lbl_803697D0 + (f32) (s8) M2C_FIELD(temp_r6, u8 *, 0x19F);
        sp8 = temp_f1;
        spC = temp_f2;
        sp10 = fn_80023068(&gBattleMap, temp_f1, temp_f2, lbl_803697D0);
    }
    M2C_FIELD(arg0, f32 *, 0) = sp8;
    M2C_FIELD(arg0, f32 *, 4) = spC;
    M2C_FIELD(arg0, f32 *, 8) = sp10;
}

void *fn_800984FC(void **arg0) {
    void *temp_r3;

    temp_r3 = *arg0;
    if (temp_r3 == NULL) {
        return NULL;
    }
    if (*(u32 *)((char *)temp_r3 + 0x28C) == 0) {
        return NULL;
    }
    return (char *)temp_r3 + 0x28C;
}

void fn_80098524(void **arg0) {
    void *var;

    var = *arg0;
    if (var != NULL) {
        var = *(void **)((char *)var + 0x280);
    } else {
        var = NULL;
    }
    if (var != NULL) {
        fn_8004BE88(var, 0);
    }
}

#pragma use_lmw_stmw on
/* Handle pad input for event-script item commands (opcodes 0x50-0x52): confirm give/take/trade. */
s32 Event_HandleItemCmd(void *arg0)
{
    u8 Pad_IsActive(void *);
    u8 Pad_IsButton(void *, s32);
    void fn_80054C14(void *);
    s32 Event_GetCmdKind(s16);
    s32 Event_GetCmdFlags(s16);
    void Event_AdvanceCmd(s16);
    s32 fn_800958C4(s32);
    void *fn_80095934(void *, s32, s32);
    void *fn_80053C30(void *, void *);
    void fn_800536CC(void *, void *);
    void fn_800536D8(void *, void *);
    void fn_8005306C(void *);
    void fn_80184688(void *, s32, s32, void *);
    void fn_800983E0(void *, void *);
    void SeCue_PlayAtPos(void *, void *, s32);
    void fn_80025624(s32, s32);
    void fn_8017F70C(void *, void *);
    void fn_8017E0C0(void *, s32, void *);
    void fn_8017F040(void *, s32, void *);
    void fn_8017DF54(void *, void *, void *);
    void fn_8009A0A4(void *, s16);
    void fn_80184C7C(void *, s32, s32, s32);
    void fn_80184BE8(void *, s32, s32, s32);
    void fn_8017F474(void *, void *);
    void fn_800535B0(void *);
    void fn_8005366C(void *, s32, s32);
    extern u8 gEventUiSeCues[];
    extern s32 gPadInput;
    s32 sp2C[3];
    s32 sp20[3];
    s32 sp14[3];
    s32 sp8[3];
    void *pad;
    void *unit;
    s32 id_raw;
    s16 id;
    void *self;
    s32 kind;
    s32 flags;
    void *tmp;
    void *p280;

    pad = M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), void **, 0x5C);
    if (pad == NULL) {
        return 0;
    }
    if (Pad_IsActive(pad) == 0) {
        return 0;
    }
    fn_80054C14(arg0);
    self = M2C_FIELD(arg0, void **, 0x18);
    if (Pad_IsButton(pad, 0x37) != 0) {
        tmp = M2C_FIELD(M2C_FIELD(self, void **, 0x38), void **, 0);
        if (tmp != NULL) {
            p280 = M2C_FIELD(tmp, void **, 0x280);
        } else {
            p280 = NULL;
        }
        M2C_FIELD(p280, s32 *, 0x1C) = M2C_FIELD(p280, s32 *, 0x1C) & 0xFFFFFF3F;
    }
    id_raw = M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x4C);
    id = (s16)id_raw;
    if (id == 0) {
        return 0;
    }
    kind = Event_GetCmdKind(id);
    flags = Event_GetCmdFlags(id);
    switch (kind) {
    case 0x50:
    case 0x51:
        if (flags & 4) {
            if (flags & 1) {
                if (Pad_IsButton(pad, 0x31) != 0) {
                    unit = M2C_FIELD(self, void **, 0x38);
                    kind = (s32)M2C_FIELD(unit, f32 *, 0xC);
                    if (kind != 0) {
                        fn_8017E0C0(unit, kind, self);
                        if (M2C_FIELD(self, u8 *, 0x34) != 2) {
                            fn_8017F040(M2C_FIELD(self, void **, 0x38), kind, self);
                        }
                        tmp = M2C_FIELD(M2C_FIELD(self, void **, 0x38), void **, 0);
                        if (tmp != NULL) {
                            p280 = M2C_FIELD(tmp, void **, 0x280);
                        } else {
                            p280 = NULL;
                        }
                        fn_80184688(p280, 1, 0x20, self);
                    }
                    return 0;
                }
            } else if (Pad_IsButton(pad, 8) != 0) {
                fn_800535B0(arg0);
                fn_8005366C(arg0, 0, 0);
                return 0;
            }
        }
        if (Pad_IsButton(pad, 0) != 0) {
            flags = Event_GetCmdFlags(id);
            Event_AdvanceCmd(id);
            tmp = (void *)fn_800958C4(flags);
            if (tmp != NULL) {
                fn_8017DF54(M2C_FIELD(self, void **, 0x3C), tmp, self);
            }
            unit = M2C_FIELD(self, void **, 0x3C);
            kind = (s32)M2C_FIELD(unit, f32 *, 0xC);
            if (kind == 0) {
                kind = Event_GetCmdKind(id);
                flags = Event_GetCmdFlags(id);
                tmp = fn_80095934(M2C_FIELD(self, void **, 0x38), kind, flags);
                if (tmp != NULL) {
                    kind = (s32)fn_80053C30(tmp, self);
                    fn_800536CC((void *)kind, M2C_FIELD(M2C_FIELD(self, void **, 0x38), void **, 0));
                    fn_800536D8((void *)kind, M2C_FIELD(M2C_FIELD(self, void **, 0x3C), void **, 0));
                    fn_8005306C((void *)kind);
                }
                tmp = M2C_FIELD(M2C_FIELD(self, void **, 0x3C), void **, 0);
                if (tmp != NULL) {
                    p280 = M2C_FIELD(tmp, void **, 0x280);
                } else {
                    p280 = NULL;
                }
                fn_80184688(p280, 1, 2, self);
                fn_800983E0(sp14, M2C_FIELD(self, void **, 0x3C));
                sp8[0] = sp14[0];
                sp8[1] = sp14[1];
                sp8[2] = sp14[2];
                SeCue_PlayAtPos(gEventUiSeCues + 0xE3, sp8, 0x64);
                fn_80025624(gPadInput, 4);
                if (M2C_FIELD(self, u8 *, 0x34) != 2) {
                    fn_8017F70C(M2C_FIELD(self, void **, 0x3C), self);
                }
            } else {
                fn_8009A0A4(self, id);
                fn_8017E0C0(M2C_FIELD(self, void **, 0x3C), kind, self);
                if (M2C_FIELD(self, u8 *, 0x34) != 2) {
                    fn_8017F040(M2C_FIELD(self, void **, 0x3C), kind, self);
                }
            }
        }
        break;
    case 0x52:
        if (Pad_IsButton(pad, 1) != 0) {
            Event_AdvanceCmd(id);
            if (M2C_FIELD(self, u8 *, 0x34) != 1) {
                tmp = M2C_FIELD(M2C_FIELD(self, void **, 0x3C), void **, 0);
                if (tmp != NULL) {
                    p280 = M2C_FIELD(tmp, void **, 0x280);
                } else {
                    p280 = NULL;
                }
                fn_80184C7C(p280, 7, 2, 0);
                tmp = M2C_FIELD(M2C_FIELD(self, void **, 0x3C), void **, 0);
                if (tmp != NULL) {
                    p280 = M2C_FIELD(tmp, void **, 0x280);
                } else {
                    p280 = NULL;
                }
                fn_80184BE8(p280, 8, 8, 0);
            }
            if (M2C_FIELD(self, u8 *, 0x34) != 2) {
                fn_8017F474(M2C_FIELD(self, void **, 0x3C), self);
            }
            fn_800983E0(sp2C, M2C_FIELD(self, void **, 0x3C));
            sp20[0] = sp2C[0];
            sp20[1] = sp2C[1];
            sp20[2] = sp2C[2];
            SeCue_PlayAtPos(gEventUiSeCues + 0xF6, sp20, 0x64);
            fn_800535B0(arg0);
            fn_8005366C(arg0, 0, 0);
        }
        break;
    }
    return 0;
}
void fn_80098A9C(s32 arg0) {
    void fn_8019A7E8(void);
    void Process_CreateChild(void *, s32);
    extern u8 gBattle[];
    extern u8 lbl_80289C54[];

    if (*(u32 *)(gBattle + 0xCAC) & 0x200) {
        fn_8019A7E8();
    } else {
        Process_CreateChild(lbl_80289C54, arg0);
    }
}

