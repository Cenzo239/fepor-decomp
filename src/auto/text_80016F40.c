/* Functions from 0x80016F40 to 0x80019558, found by decomp-toolkit. */
#include "common.h"

extern u16 gBattleState[700]; // 1400 bytes / 2 = 700 u16s

void* fn_8014C5A8(u16 *, u8);
extern u8 lbl_802841B0[16];


void fn_80016F40(void) {
    extern u16 gUnits[];
    extern void fn_800169A8(void);
    Array_Destroy(gUnits, fn_800169A8, 0x280, 0x9F);
}

void *fn_80016F78(void *arg0) {
    void fn_8022C260(void *, s32 (*)(s32), s32 (*)(s32, s16), s32, s32);
    s32 fn_8001C76C(s32);
    s32 Item_Destroy(s32, s16);

    M2C_FIELD(arg0, s32 *, 0x1A0) = 0;
    fn_8022C260((u8 *)arg0 + 0x1CC, fn_8001C76C, Item_Destroy, 8, 4);
    fn_8022C260((u8 *)arg0 + 0x1EC, fn_8001C76C, Item_Destroy, 8, 4);
    M2C_FIELD(arg0, s16 *, 0x228) = 0;
    M2C_FIELD(arg0, s16 *, 0x22A) = 0;
    M2C_FIELD(arg0, s16 *, 0x22C) = 0;
    M2C_FIELD(arg0, s16 *, 0x22E) = 0;
    M2C_FIELD(arg0, s16 *, 0x230) = 0;
    M2C_FIELD(arg0, s16 *, 0x232) = 0;
    M2C_FIELD(arg0, s8 *, 0x234) = 0;
    M2C_FIELD(arg0, s8 *, 0x235) = 0;
    return arg0;
}

void *fn_80017010(u8 *arg0) {
    void *Msg_Expand(void *);
    extern u8 lbl_80268128[];
    u8 *temp_r3;
    void *var_r31 = lbl_80268128 + 0x1D;
    u8 temp_r4 = *arg0;
    u8 var_r0;

    switch (temp_r4) {
    case 0:
    case 5:
    case 6: {
        temp_r3 = fn_8014C5A8(gBattleState, temp_r4);
        if (temp_r3 == NULL) {
            var_r0 = 0;
        } else {
            u8 temp_r0 = *temp_r3;
            switch (temp_r0) {
            case 0: var_r0 = 0; break;
            case 1: var_r0 = 8; break;
            case 2: var_r0 = 7; break;
            case 3: var_r0 = 4; break;
            case 4: var_r0 = 5; break;
            default: var_r0 = 0; break;
            }
            switch (var_r0) {
            case 5: var_r31 = lbl_80268128 + 0x40; break;
            case 8: var_r31 = lbl_80268128 + 0x46; break;
            case 0: var_r31 = lbl_80268128 + 0x34; break;
            case 4: var_r31 = lbl_80268128 + 0x3A; break;
            default: break;
            }
        }
        break;
    }
    case 3: {
        temp_r3 = fn_8014C5A8(gBattleState, temp_r4);
        if (temp_r3 == NULL) {
            var_r0 = 0;
        } else {
            u8 temp_r0 = *temp_r3;
            switch (temp_r0) {
            case 0: var_r0 = 0; break;
            case 1: var_r0 = 8; break;
            case 2: var_r0 = 7; break;
            case 3: var_r0 = 4; break;
            case 4: var_r0 = 5; break;
            default: var_r0 = 0; break;
            }
            switch (var_r0) {
            case 6: break;
            case 7: var_r31 = lbl_80268128 + 0x22; break;
            case 4: var_r31 = lbl_80268128 + 0x28; break;
            case 5: var_r31 = lbl_80268128 + 0x2E; break;
            default: break;
            }
        }
        break;
    }
    default:
        break;
    }
    if (var_r31 != NULL) {
        var_r31 = Msg_Expand(var_r31);
    }
    return var_r31;
}

void *Unit_FindIke(u8 *arg0) {
    void *Unit_FindByName(char *);
    extern char lbl_80268128[];

    if (fn_8014C5A8(gBattleState, *arg0) == NULL) {
        return NULL;
    }
    return Unit_FindByName(lbl_80268128 + 0x4C);
}

s32 fn_80017290(u8 *arg0) {
    void *fn_8014C5A8(void *, u8);
    void *temp_r3;

    temp_r3 = fn_8014C5A8(gBattleState, *arg0);
    if (temp_r3 == NULL) {
        return -1;
    }
    return *(u8 *)((char *)temp_r3 + 3);
}

s32 fn_800172D4(u8 *arg0) {
    void *fn_8014C5A8(void *, u8);
    void *temp_r3;

    temp_r3 = fn_8014C5A8(gBattleState, *arg0);
    if (temp_r3 == NULL) {
        return -1;
    }
    return *(u8 *)((char *)temp_r3 + 2);
}

s32 fn_80017318(u8 *arg0) {
    u8 *p;

    p = fn_8014C5A8(gBattleState, *arg0);
    if (p == NULL) {
        return 0;
    }
    switch (*p) {
    case 0:
        return 0;
    case 1:
        return 8;
    case 2:
        return 7;
    case 3:
        return 4;
    case 4:
        return 5;
    }
    return 0;
}

void fn_800173B4(u8 *arg0, void *arg1) {
    u8 Status_Test(void *, M2C_UNK);
    if (Status_Test((u8 *)arg1 + 0x1BC, 0)) {
        *arg0 = 1;
        return;
    }
    *arg0 = M2C_FIELD(M2C_FIELD(arg1, void **, 0x190), u8 *, 8);
}

void fn_80017414(void *arg0, s32 arg1) {
    s16 Stream_ReadU16(s32);
    s8 Stream_ReadU8(s32);
    M2C_FIELD(arg0, s16 *, 0) = Stream_ReadU16(arg1);
    M2C_FIELD(arg0, s16 *, 2) = Stream_ReadU16(arg1);
    M2C_FIELD(arg0, s16 *, 4) = Stream_ReadU16(arg1);
    M2C_FIELD(arg0, s16 *, 6) = Stream_ReadU16(arg1);
    M2C_FIELD(arg0, s16 *, 8) = Stream_ReadU16(arg1);
    M2C_FIELD(arg0, s16 *, 0xA) = Stream_ReadU16(arg1);
    M2C_FIELD(arg0, s8 *, 0xC) = Stream_ReadU8(arg1);
    M2C_FIELD(arg0, s8 *, 0xD) = Stream_ReadU8(arg1);
}

void fn_800174A8(void *arg0, s32 arg1) {
    M2C_UNK Stream_WriteU16(s32, u16);
    M2C_UNK Stream_WriteU8(s32, u8);
    Stream_WriteU16(arg1, M2C_FIELD(arg0, u16 *, 0));
    Stream_WriteU16(arg1, M2C_FIELD(arg0, u16 *, 2));
    Stream_WriteU16(arg1, M2C_FIELD(arg0, u16 *, 4));
    Stream_WriteU16(arg1, M2C_FIELD(arg0, u16 *, 6));
    Stream_WriteU16(arg1, M2C_FIELD(arg0, u16 *, 8));
    Stream_WriteU16(arg1, M2C_FIELD(arg0, u16 *, 0xA));
    Stream_WriteU8(arg1, M2C_FIELD(arg0, u8 *, 0xC));
    Stream_WriteU8(arg1, M2C_FIELD(arg0, u8 *, 0xD));
}

void fn_8001753C(s16 *arg0) {
    s16 fn_8000CEE4(M2C_UNK);
    *arg0 = fn_8000CEE4(0xE4C);
}

void fn_80017570(s32 arg0)
{
    if (arg0 >= 0x17) {
        return;
    }
    
    switch(arg0) {
        case 0:
            // Load lbl_80268128 + 0xE8
            break;
        case 1:
            // Load lbl_80268128 + 0xEE
            break;
        case 2:
            // Load lbl_80268128 + 0xF5
            break;
        case 3:
            // Load lbl_80268128 + 0xFD
            break;
        case 4:
            // Load lbl_80268128 + 0x105
            break;
        case 5:
            // Load lbl_80268128 + 0x10E
            break;
        case 6:
            // Load lbl_80268128 + 0x116
            break;
        case 7:
            // Load lbl_80268128 + 0x11D
            break;
        case 8:
            // Load lbl_80268128 + 0x125
            break;
        case 9:
            // Load lbl_80268128 + 0x12E
            break;
        case 10:
            // Load lbl_80268128 + 0x135
            break;
        case 11:
            // Load lbl_80268128 + 0x13B
            break;
        case 12:
            // Load lbl_80268128 + 0x141
            break;
        case 13:
            // Load lbl_80268128 + 0x148
            break;
        case 14:
            // Load lbl_80268128 + 0x14F
            break;
        case 15:
            // Load lbl_80268128 + 0x158
            break;
        case 16:
            // Load lbl_80268128 + 0x15F
            break;
        case 17:
            // Load lbl_80268128 + 0x166
            break;
        case 18:
            // Load lbl_80268128 + 0x16D
            break;
        case 19:
            // Load lbl_80268128 + 0x175
            break;
        case 20:
            // Load lbl_80268128 + 0x17D
            break;
        case 21:
            // Load lbl_80268128 + 0x186
            break;
        case 22:
            // Load lbl_80268128 + 0x18D
            break;
        case 23:
            // Load lbl_80268128 + 0x195
            break;
    }
    
    Msg_Expand();
}

s32 fn_8001772C(void) {
    void *Process_Find(void *);
    void *p;

    p = Process_Find(lbl_802841B0);
    if (p != NULL && M2C_FIELD(p, u8 *, 0x3C) == 0) {
        return 1;
    }
    return 0;
}

void fn_80017774(void) {
    Process_UnlinkByKey(&lbl_802841B0);
}

void fn_8001779C(s32 arg0) {
    void *Process_Find(void *);
    void fn_800180F4(void *, u8);
    void *p;

    p = Process_Find(lbl_802841B0);
    if (p != NULL) {
        fn_800180F4(p, arg0);
    }
}

void fn_800177E0(s32 arg0) {
    void *Process_Create(void *, s32);
    s32 fn_800C4638(s32, void *, s32);
    extern char lbl_80268330[];
    void *p;

    p = Process_Create(lbl_802841B0, arg0);
    M2C_FIELD(p, s32 *, 0x40) = fn_800C4638(0x1400, lbl_80268330 + 0x4E, 0);
    M2C_FIELD(p, u8 *, 0x44) = 0;
    M2C_FIELD(p, u8 *, 0x3C) = 0;
}

s32 CamPath_AddPoint(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 sp0;
    s32 v5;
    s32 v6;
    
    if (arg4 == 0) {
        return 0;
    }
    
    v5 = *(s32*)((char*)0x800000F8 + arg1);
    sp0 = *(s32*)((char*)0x800000F8 + arg2);
    v6 = *(s32*)((char*)0x800000F8 + arg3);
    
    if (v5 == 0) {
        return 0;
    }
    
    if (sp0 == 0) {
        if (v6 == 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

extern s32 gUiInputFlags;
extern f32 lbl_80368C88;
extern f64 lbl_80368C98;
extern f32 lbl_80368CA0;
extern f32 lbl_80368C8C;
extern u8 lbl_802CA434[];
void Process_ClearFunc(void *);
void CamPath_Apply(void *, f32);
f32 Math_Lerp(f32, f32, f32, f32);
f32 Math_EaseInPow(s32, f32, f32, f32, f32);
f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
/* Advance a camera-path process: tick/skip timer, ease progress, apply to camera. */
void CamPath_Update(void *proc) {
    void Process_ClearFunc(void *);
    void CamPath_Apply(void *, f32);
    f32 Math_Lerp(f32, f32, f32, f32);
    f32 Math_EaseInPow(s32, f32, f32, f32, f32);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    extern s32 gUiInputFlags;
    extern f32 lbl_80368C88;

    s32 ease_mode;
    s32 duration;
    f32 t;

    *(s32 *)((u8 *)proc + 0x34) = *(s32 *)((u8 *)proc + 0x34) + 1;
    if ((gUiInputFlags & 1) != 0) {
        *(s32 *)((u8 *)proc + 0x34) = *(s32 *)((u8 *)proc + 0x38);
    }
    if (*(s32 *)((u8 *)proc + 0x34) >= *(s32 *)((u8 *)proc + 0x38)) {
        *(s32 *)((u8 *)proc + 0x34) = *(s32 *)((u8 *)proc + 0x38);
        Process_ClearFunc(proc);
        *((u8 *)proc + 0x3c) = 1;
    }
    t = lbl_80368C88;
    ease_mode = *(s32 *)((u8 *)proc + 0x30);
    switch (ease_mode) {
    case 0:
        duration = *(s32 *)((u8 *)proc + 0x38);
        t = Math_Lerp(t, (f32)duration, (f32)duration, (f32)*(s32 *)((u8 *)proc + 0x34));
        break;
    case 1:
        duration = *(s32 *)((u8 *)proc + 0x38);
        t = Math_EaseInPow(2, t, (f32)duration, (f32)duration, (f32)*(s32 *)((u8 *)proc + 0x34));
        break;
    case 2:
        duration = *(s32 *)((u8 *)proc + 0x38);
        t = Math_EaseOutPow(2, t, (f32)duration, (f32)duration, (f32)*(s32 *)((u8 *)proc + 0x34));
        break;
    case 3: {
        s32 half;
        duration = *(s32 *)((u8 *)proc + 0x38);
        half = duration / 2;
        if (*(s32 *)((u8 *)proc + 0x34) < half) {
            t = Math_EaseInPow(2, t, (f32)half, (f32)half, (f32)*(s32 *)((u8 *)proc + 0x34));
        } else {
            t = Math_EaseOutPow(2, (f32)half, (f32)duration, (f32)half, (f32)(*(s32 *)((u8 *)proc + 0x34) - half));
        }
        break;
    }
    }
    CamPath_Apply(proc, t);
}

void fn_80017BFC(void) {
    M2C_UNK fn_8001840C();
    fn_8001840C();
}

#pragma use_lmw_stmw on
void CamPath_Apply(void *arg0, f32 farg0) {
    f32 Math_Hermite(f32, f32, f32, f32, f32);
    extern s32 lbl_80268318[];
    extern s32 gActiveCam;
    extern f32 lbl_80368C88;
    extern f32 lbl_80368C8C;

    typedef struct { s32 x, y, z; } Vec;
    Vec sp74, sp68, sp5C, sp50, sp44, sp38, sp2C, sp20, sp14, sp8;
    s32 hole[8];
    s32 n;
    register Vec *src;
    Vec *out;
    Vec def;
    s32 prevKey;
    void *self;
    s32 i;
    void *cam;
    Vec *vp;
    f32 denom;
    s32 key;
    void *pt;
    s32 delta;
    f32 t;
    s32 ctr;
    f32 prev_f;

    n = *((u8 *)arg0 + 0x45);
    cam = (void *)gActiveCam;
    self = arg0;
    if (((u32)(-(s32)n | n) >> 31) != 0) {
        src = (Vec *)lbl_80268318;
        def = *src;
        vp = &sp14; *vp = def;
        vp = &sp44; *vp = def;
        vp = &sp38; *vp = def;
        vp = (Vec *)hole; *vp = def;
        if (n == 0) {
            sp68 = def;
            out = &sp68;
        } else {
            pt = *(void **)((u8 *)self + 0x48);
            i = 0;
            for (ctr = n; ctr > 0; ctr--) {
                key = *(s32 *)((u8 *)pt + 4);
                if ((f32)key >= farg0) {
                    if (i == 0) {
                        *(f32 *)&sp38.x = *(f32 *)((u8 *)pt + 8);
                        *(f32 *)&sp38.y = *(f32 *)((u8 *)pt + 0xC);
                        *(f32 *)&sp38.z = *(f32 *)((u8 *)pt + 0x10);
                    } else {
                        register prevKey = *(s32 *)((u8 *)pt - 0x10);
                        delta = key - prevKey;
                        denom = (f32)delta;
                        prev_f = (f32)prevKey;
                        if (lbl_80368C88 == denom) {
                            t = lbl_80368C8C;
                        } else {
                            t = (farg0 - prev_f) / denom;
                        }
                        {
                            void *p0 = (2 <= i) ? (void *)((u8 *)pt - 0x28) : (void *)((u8 *)pt - 0x14);
                            void *p2 = (i < n - 1) ? (void *)((u8 *)pt + 0x14) : pt;
                            *(f32 *)&sp38.x = Math_Hermite(*(f32 *)((u8 *)p0 + 8), *(f32 *)((u8 *)pt - 0xC), *(f32 *)((u8 *)pt + 8), *(f32 *)((u8 *)p2 + 8), t);
                            *(f32 *)&sp38.y = Math_Hermite(*(f32 *)((u8 *)p0 + 0xC), *(f32 *)((u8 *)pt - 8), *(f32 *)((u8 *)pt + 0xC), *(f32 *)((u8 *)p2 + 0xC), t);
                            *(f32 *)&sp38.z = Math_Hermite(*(f32 *)((u8 *)p0 + 0x10), *(f32 *)((u8 *)pt - 4), *(f32 *)((u8 *)pt + 0x10), *(f32 *)((u8 *)p2 + 0x10), t);
                        }
                    }
                    sp68 = sp38;
                    out = &sp68;
                    goto first_store;
                }
                i += 1;
                pt = (u8 *)pt + 0x14;
            }
            {
                u8 *last = (u8 *)pt + ((n - 1) * 0x14) + 8;
                *(f32 *)&sp38.x = *(f32 *)(last + 0);
                *(f32 *)&sp38.y = *(f32 *)(last + 4);
                *(f32 *)&sp38.z = *(f32 *)(last + 8);
                sp68 = sp38;
                out = &sp68;
            }
        }
    first_store:
        sp5C = *out;
        *(f32 *)((u8 *)cam + 0x4C) = *(f32 *)&sp5C.x;
        *(f32 *)((u8 *)cam + 0x50) = *(f32 *)&sp5C.y;
        *(f32 *)((u8 *)cam + 0x54) = *(f32 *)&sp5C.z;
        *(f32 *)((u8 *)cam + 0x40) = *(f32 *)((u8 *)cam + 0x4C);
        *(f32 *)((u8 *)cam + 0x44) = *(f32 *)((u8 *)cam + 0x50);
        *(f32 *)((u8 *)cam + 0x48) = *(f32 *)((u8 *)cam + 0x54);
    }

    n = *((u8 *)self + 0x46);
    if (((u32)(-n | n) >> 31) != 0) {
        src = (Vec *)lbl_80268318;
        def = *src;
        vp = &sp8; *vp = def;
        vp = &sp2C; *vp = def;
        vp = &sp20; *vp = def;
        if (n == 0) {
            sp50 = def;
            out = &sp50;
        } else {
            pt = *(void **)((u8 *)self + 0x4C);
            i = 0;
            for (ctr = n; ctr > 0; ctr--) {
                key = *(s32 *)((u8 *)pt + 4);
                if ((f32)key >= farg0) {
                    if (!i) {
                        *(f32 *)&sp20.x = *(f32 *)((u8 *)pt + 8);
                        *(f32 *)&sp20.y = *(f32 *)((u8 *)pt + 0xC);
                        *(f32 *)&sp20.z = *(f32 *)((u8 *)pt + 0x10);
                    } else {
                        prevKey = *(s32 *)((u8 *)pt - 0x10);
                        delta = key - prevKey;
                        denom = (f32)delta;
                        prev_f = (f32)prevKey;
                        if (lbl_80368C88 == denom) {
                            t = lbl_80368C8C;
                        } else {
                            t = (farg0 - prev_f) / denom;
                        }
                        {
                            void *p0 = (2 <= i) ? (void *)((u8 *)pt - 0x28) : (void *)((u8 *)pt - 0x14);
                            void *p2 = (i < n - 1) ? (void *)((u8 *)pt + 0x14) : pt;
                            *(f32 *)&sp20.x = Math_Hermite(*(f32 *)((u8 *)p0 + 8), *(f32 *)((u8 *)pt - 0xC), *(f32 *)((u8 *)pt + 8), *(f32 *)((u8 *)p2 + 8), t);
                            *(f32 *)&sp20.y = Math_Hermite(*(f32 *)((u8 *)p0 + 0xC), *(f32 *)((u8 *)pt - 8), *(f32 *)((u8 *)pt + 0xC), *(f32 *)((u8 *)p2 + 0xC), t);
                            *(f32 *)&sp20.z = Math_Hermite(*(f32 *)((u8 *)p0 + 0x10), *(f32 *)((u8 *)pt - 4), *(f32 *)((u8 *)pt + 0x10), *(f32 *)((u8 *)p2 + 0x10), t);
                        }
                    }
                    sp50 = sp20;
                    out = &sp50;
                    goto second_store;
                }
                ++i;
                pt = (u8 *)pt + 0x14;
            }
            {
                u8 *last = (u8 *)pt + ((n - 1) * 0x14) + 8;
                *(f32 *)&sp20.x = *(f32 *)(last + 0);
                *(f32 *)&sp20.y = *(f32 *)(last + 4);
                *(f32 *)&sp20.z = *(f32 *)(last + 8);
                sp50 = sp20;
                out = &sp50;
            }
        }
    second_store:
        sp74 = *out;
        *(f32 *)((u8 *)cam + 4) = *(f32 *)&sp74.x;
        *(f32 *)((u8 *)cam + 8) = *(f32 *)&sp74.y;
        *(f32 *)((u8 *)cam + 0xC) = *(f32 *)&sp74.z;
    }
}
#pragma use_lmw_stmw reset

void fn_800180F4(void *arg0, u8 arg1) {
    void fn_80018594(void *);
    void CamPath_Apply(void *, f32);
    void Process_Goto(void *, s32);
    extern s32 gActiveCam;
    extern u8 gActiveCamIndex;
    extern u8 lbl_802CA434[];
    extern f32 lbl_80368CA0;
    extern f32 lbl_80368C88;
    extern f32 lbl_80368C8C;
    extern f64 lbl_80368C98;

    s32 sp20[3];
    s32 sp14[3];
    s32 sp2C[3];
    s32 sp8[3];
    void *cam;
    u8 *dst;
    s32 found;
    s32 c45;
    s32 c46;
    u8 idx;
    void *walk;
    void *slot;
    f32 f1;
    f32 f2;
    f32 f0;
    s32 t;
    s32 i;

    cam = (void *)gActiveCam;
    *(s32 *)((u8 *)arg0 + 0x30) = arg1;
    fn_80018594(arg0);
    dst = lbl_802CA434;
    f1 = lbl_80368CA0;
    f2 = lbl_80368C88;
    f0 = lbl_80368C8C;
    found = 0;
    *(f32 *)(dst + 0x28) = f1;
    *(f32 *)(dst + 0x34) = f1;
    *(f32 *)(dst + 0x58) = f2;
    *(f32 *)(dst + 0x5c) = f2;
    *(f32 *)(dst + 0x60) = f2;
    *(f32 *)(dst + 0x64) = f2;
    *(f32 *)(dst + 0x68) = f2;
    *(f32 *)(dst + 0x6c) = f2;
    *(s32 *)(dst + 0x1c) = found;
    *(f32 *)(dst + 0x70) = f0;
    c45 = *((u8 *)arg0 + 0x45);
    if (((u32)(-c45 | c45) >> 31) == 0) {
        sp20[0] = *(s32 *)((u8 *)cam + 0x40);
        sp20[1] = *(s32 *)((u8 *)cam + 0x44);
        sp20[2] = *(s32 *)((u8 *)cam + 0x48);
        *(f32 *)(dst + 0x4c) = *(f32 *)&sp20[0];
        *(f32 *)(dst + 0x50) = *(f32 *)&sp20[1];
        *(f32 *)(dst + 0x54) = *(f32 *)&sp20[2];
        *(f32 *)(dst + 0x40) = *(f32 *)&sp20[0];
        *(f32 *)(dst + 0x44) = *(f32 *)&sp20[1];
        *(f32 *)(dst + 0x48) = *(f32 *)&sp20[2];
    } else {
        if (c45 == 0) {
            found = 0;
        } else {
            walk = *(void **)((u8 *)arg0 + 0x48);
            found = 0;
            for (i = c45; i != 0; i--) {
                t = *(s32 *)((u8 *)walk + 4);
                if ((f32)t == f2) {
                    found = 1;
                    break;
                }
                walk = (u8 *)walk + 0x14;
            }
        }
        if ((u8)found == 0) {
            idx = *((u8 *)arg0 + 0x44);
            found = 0;
            sp14[0] = *(s32 *)((u8 *)cam + 0x40);
            *((u8 *)*(void **)((u8 *)arg0 + 0x40) + idx * 0x14) = (u8)found;
            sp14[1] = *(s32 *)((u8 *)cam + 0x44);
            sp14[2] = *(s32 *)((u8 *)cam + 0x48);
            slot = (u8 *)*(void **)((u8 *)arg0 + 0x40) + idx * 0x14;
            *(s32 *)((u8 *)slot + 4) = found;
            idx = *((u8 *)arg0 + 0x44);
            slot = (u8 *)*(void **)((u8 *)arg0 + 0x40) + (idx * 0x14);
            *(f32 *)((u8 *)slot + 8) = *(f32 *)&sp14[0];
            *(f32 *)((u8 *)slot + 0xc) = *(f32 *)&sp14[1];
            *(f32 *)((u8 *)slot + 0x10) = *(f32 *)&sp14[2];
            *((u8 *)arg0 + 0x44) = idx + 1;
        }
    }
    c46 = *((u8 *)arg0 + 0x46);
    if (((u32)(-c46 | c46) >> 31) == 0) {
        f32 tf;
        dst = lbl_802CA434;
        tf = *(f32 *)((u8 *)cam + 4);
        *(f32 *)(dst + 4) = tf;
        *(f32 *)(dst + 0x10) = tf;
        tf = *(f32 *)((u8 *)cam + 8);
        *(f32 *)(dst + 8) = tf;
        *(f32 *)(dst + 0x14) = tf;
        tf = *(f32 *)((u8 *)cam + 0xc);
        *(f32 *)(dst + 0xc) = tf;
        *(f32 *)(dst + 0x18) = tf;
    } else {
        if (c46 == 0) {
            found = 0;
        } else {
            walk = *(void **)((u8 *)arg0 + 0x4c);
            found = 0;
            f0 = lbl_80368C88;
            for (i = c46; i != 0; i--) {
                t = *(s32 *)((u8 *)walk + 4);
                if ((f32)t == f0) {
                    found = 1;
                    break;
                }
                walk = (u8 *)walk + 0x14;
            }
        }
        if ((u8)found == 0) {
            f32 fx, fy, fz;
            idx = *((u8 *)arg0 + 0x44);
            fx = *(f32 *)((u8 *)cam + 4);
            fy = *(f32 *)((u8 *)cam + 8);
            fz = *(f32 *)((u8 *)cam + 0xc);
            *((u8 *)*(void **)((u8 *)arg0 + 0x40) + idx * 0x14) = 1;
            sp2C[0] = *(s32 *)&fx;
            sp2C[1] = *(s32 *)&fy;
            sp2C[2] = *(s32 *)&fz;
            slot = (u8 *)*(void **)((u8 *)arg0 + 0x40) + idx * 0x14;
            *(s32 *)((u8 *)slot + 4) = 0;
            idx = *((u8 *)arg0 + 0x44);
            sp8[0] = sp2C[0];
            sp8[1] = sp2C[1];
            sp8[2] = sp2C[2];
            slot = (u8 *)*(void **)((u8 *)arg0 + 0x40) + (idx * 0x14);
            *(f32 *)((u8 *)slot + 8) = *(f32 *)&sp8[0];
            *(f32 *)((u8 *)slot + 0xc) = *(f32 *)&sp8[1];
            *(f32 *)((u8 *)slot + 0x10) = *(f32 *)&sp8[2];
            *((u8 *)arg0 + 0x44) = idx + 1;
        }
    }
    fn_80018594(arg0);
    gActiveCamIndex = 3;
    gActiveCam = (s32)lbl_802CA434;
    CamPath_Apply(arg0, lbl_80368C88);
    Process_Goto(arg0, 0);
}

void fn_8001840C(void *arg0)
{
    extern s32 gActiveCam;
    extern u8 gActiveCamIndex;
    extern s32 gUiInputFlags;
    extern u16 gBattleState[700];
    extern u8 lbl_802CA2C8[];

    extern f32 lbl_80368CA4;
    extern f32 lbl_80368CA0;
    extern f32 lbl_80368C88;
    extern f32 lbl_80368C8C;
    extern f32 lbl_80368CA8;

    void BattleState_SetCamPos(void *, f32, f32);
    void fn_800C4588(void *);

    u8 *dst;
    u8 *src;
    u8 *obj;
    u8 *data;
    f32 x;
    f32 y;
    f32 z;
    f32 a;
    f32 b;
    f32 c;
    f32 v0;
    f32 v1;
    f32 v2;

    obj = (u8 *)arg0;
    src = (u8 *)gActiveCam;
    data = (u8 *)gBattleState;
    dst = lbl_802CA2C8;

    x = *(f32 *)(src + 0x40);
    y = *(f32 *)(src + 0x44);
    z = *(f32 *)(src + 0x48);

    BattleState_SetCamPos(data, x - lbl_80368CA4, y - lbl_80368CA4);

    *(f32 *)(dst + 0x28) = lbl_80368CA0;
    *(f32 *)(dst + 0x34) = lbl_80368CA0;

    *(f32 *)(dst + 0x58) = lbl_80368C88;
    *(f32 *)(dst + 0x5C) = lbl_80368C88;
    *(f32 *)(dst + 0x60) = lbl_80368C88;
    *(f32 *)(dst + 0x64) = lbl_80368C88;
    *(f32 *)(dst + 0x68) = lbl_80368C88;
    *(f32 *)(dst + 0x6C) = lbl_80368C88;

    *(s32 *)(dst + 0x1C) = 0;
    *(f32 *)(dst + 0x70) = lbl_80368C8C;

    a = *(f32 *)(src + 0x40);
    b = *(f32 *)(src + 0x44);
    c = *(f32 *)(src + 0x48);

    *(f32 *)(dst + 0x4C) = a;
    *(f32 *)(dst + 0x50) = b;
    *(f32 *)(dst + 0x54) = c;

    *(f32 *)(dst + 0x40) = a;
    *(f32 *)(dst + 0x44) = b;
    *(f32 *)(dst + 0x48) = c;

    v2 = *(f32 *)(src + 0x18);
    *(f32 *)(dst + 0x0C) = v2;
    *(f32 *)(dst + 0x18) = v2;

    v0 = *(f32 *)(src + 0x10);
    *(f32 *)(dst + 0x04) = v0;
    *(f32 *)(dst + 0x10) = v0;

    v1 = *(f32 *)(src + 0x14);
    *(f32 *)(dst + 0x08) = v1;
    *(f32 *)(dst + 0x14) = v1;

    *(f32 *)(dst + 0x70) = lbl_80368CA8;

    if (gUiInputFlags & 1) {
        *(f32 *)(dst + 0x10) = v0;

        x = *(f32 *)(data + 0x52C);
        y = *(f32 *)(data + 0x530);
        z = *(f32 *)(data + 0x53C);

        *(f32 *)(dst + 0x4C) = x;
        *(f32 *)(dst + 0x50) = y;
        *(f32 *)(dst + 0x54) = z;

        *(f32 *)(dst + 0x40) = x;
        *(f32 *)(dst + 0x44) = y;
        *(f32 *)(dst + 0x48) = z;

        *(f32 *)(dst + 0x14) = v1;
        *(f32 *)(dst + 0x18) = v2;
    }

    gActiveCamIndex = 0;
    gActiveCam = (s32)lbl_802CA2C8;

    obj[0x3C] = 1;

    fn_800C4588(*(void **)(obj + 0x40));

    *(s32 *)(obj + 0x40) = 0;
}

void fn_80018594(void *arg0) {
    s32 i;
    s32 j;
    s32 off;
    void *base;
    void *cur;
    void *nxt;
    s32 t4, t8, tc, t10;
    u8 t0;
    u8 idx;
    void *slot;

    i = 0;
    *((u8 *)arg0 + 0x45) = 0;
    *(s32 *)((u8 *)arg0 + 0x48) = 0;
    *((u8 *)arg0 + 0x46) = 0;
    *(s32 *)((u8 *)arg0 + 0x4C) = 0;
    *((u8 *)arg0 + 0x47) = 0;
    *(s32 *)((u8 *)arg0 + 0x50) = 0;
    *(s32 *)((u8 *)arg0 + 0x34) = 0;
    *(s32 *)((u8 *)arg0 + 0x38) = 0;

    while (i < *((u8 *)arg0 + 0x44)) {
        j = 0;
        off = 0;
        while (j < (*((u8 *)arg0 + 0x44) - 1) - i) {
            base = *(void **)((u8 *)arg0 + 0x40);
            cur = (u8 *)base + off;
            if (*(s32 *)((u8 *)cur + 4) > *(s32 *)((u8 *)cur + 0x18)) {
                nxt = (u8 *)base + (j + 1) * 0x14;
                t0 = *(u8 *)cur;
                t4 = *(s32 *)((u8 *)cur + 4);
                t8 = *(s32 *)((u8 *)cur + 8);
                tc = *(s32 *)((u8 *)cur + 0xc);
                t10 = *(s32 *)((u8 *)cur + 0x10);
                *(u8 *)cur = *(u8 *)nxt;
                *(s32 *)((u8 *)cur + 4) = *(s32 *)((u8 *)nxt + 4);
                *(s32 *)((u8 *)cur + 8) = *(s32 *)((u8 *)nxt + 8);
                *(s32 *)((u8 *)cur + 0xc) = *(s32 *)((u8 *)nxt + 0xc);
                *(s32 *)((u8 *)cur + 0x10) = *(s32 *)((u8 *)nxt + 0x10);
                nxt = (u8 *)*(void **)((u8 *)arg0 + 0x40) + (j + 1) * 0x14;
                *(u8 *)nxt = t0;
                *(s32 *)((u8 *)nxt + 4) = t4;
                *(s32 *)((u8 *)nxt + 8) = t8;
                *(s32 *)((u8 *)nxt + 0xc) = tc;
                *(s32 *)((u8 *)nxt + 0x10) = t10;
            }
            off += 0x14;
            j += 1;
        }
        i += 1;
    }

    i = 0;
    while (i < *((u8 *)arg0 + 0x44)) {
        j = 0;
        off = 0;
        while (j < (*((u8 *)arg0 + 0x44) - 1) - i) {
            base = *(void **)((u8 *)arg0 + 0x40);
            cur = (u8 *)base + off;
            if (*(u8 *)cur > *(u8 *)((u8 *)cur + 0x14)) {
                nxt = (u8 *)base + (j + 1) * 0x14;
                t0 = *(u8 *)cur;
                t4 = *(s32 *)((u8 *)cur + 4);
                t8 = *(s32 *)((u8 *)cur + 8);
                tc = *(s32 *)((u8 *)cur + 0xc);
                t10 = *(s32 *)((u8 *)cur + 0x10);
                *(u8 *)cur = *(u8 *)nxt;
                *(s32 *)((u8 *)cur + 4) = *(s32 *)((u8 *)nxt + 4);
                *(s32 *)((u8 *)cur + 8) = *(s32 *)((u8 *)nxt + 8);
                *(s32 *)((u8 *)cur + 0xc) = *(s32 *)((u8 *)nxt + 0xc);
                *(s32 *)((u8 *)cur + 0x10) = *(s32 *)((u8 *)nxt + 0x10);
                nxt = (u8 *)*(void **)((u8 *)arg0 + 0x40) + (j + 1) * 0x14;
                *(u8 *)nxt = t0;
                *(s32 *)((u8 *)nxt + 4) = t4;
                *(s32 *)((u8 *)nxt + 8) = t8;
                *(s32 *)((u8 *)nxt + 0xc) = tc;
                *(s32 *)((u8 *)nxt + 0x10) = t10;
            }
            off += 0x14;
            j += 1;
        }
        i += 1;
    }

    i = 0;
    off = 0;
    while (i < *((u8 *)arg0 + 0x44)) {
        cur = (u8 *)*(void **)((u8 *)arg0 + 0x40) + off;
        idx = *(u8 *)cur;
        slot = (u8 *)arg0 + (idx * 4) + 0x48;
        if (*(void **)slot == NULL) {
            *(void **)slot = cur;
        }
        *((u8 *)arg0 + idx + 0x45) = *((u8 *)arg0 + idx + 0x45) + 1;
        t4 = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x40) + off + 4);
        if (t4 > *(s32 *)((u8 *)arg0 + 0x38)) {
            *(s32 *)((u8 *)arg0 + 0x38) = t4;
        }
        off += 0x14;
        i += 1;
    }
}

void fn_800187F0(void) {
    void *p;

    p = (void *)gActiveCam;
    if (p != NULL) {
        M2C_FIELD(p, f32 *, 0x4C) = M2C_FIELD(gBattleState, f32 *, 0x52C);
        M2C_FIELD(p, f32 *, 0x50) = M2C_FIELD(gBattleState, f32 *, 0x530);
        M2C_FIELD(p, f32 *, 0x54) = M2C_FIELD(gBattleState, f32 *, 0x53C);
        M2C_FIELD(p, f32 *, 0x40) = M2C_FIELD(p, f32 *, 0x4C);
        M2C_FIELD(p, f32 *, 0x44) = M2C_FIELD(p, f32 *, 0x50);
        M2C_FIELD(p, f32 *, 0x48) = M2C_FIELD(p, f32 *, 0x54);
    }
    p = (void *)gActiveCam;
    if (p != NULL) {
        M2C_FIELD(p, f32 *, 0x10) = M2C_FIELD(p, f32 *, 0x4);
        M2C_FIELD(p, f32 *, 0x14) = M2C_FIELD(p, f32 *, 0x8);
        M2C_FIELD(p, f32 *, 0x18) = M2C_FIELD(p, f32 *, 0xC);
    }
}

void fn_8001885C(void) {
    void *p;

    p = (void *)gActiveCam;
    if (p != NULL) {
        M2C_FIELD(p, f32 *, 0x4C) = M2C_FIELD(gBattleState, f32 *, 0x52C);
        M2C_FIELD(p, f32 *, 0x50) = M2C_FIELD(gBattleState, f32 *, 0x530);
        M2C_FIELD(p, f32 *, 0x54) = M2C_FIELD(gBattleState, f32 *, 0x53C);
        M2C_FIELD(p, f32 *, 0x40) = M2C_FIELD(p, f32 *, 0x4C);
        M2C_FIELD(p, f32 *, 0x44) = M2C_FIELD(p, f32 *, 0x50);
        M2C_FIELD(p, f32 *, 0x48) = M2C_FIELD(p, f32 *, 0x54);
    }
}

/* Returns 1 if active cam look-at (XY) or eye moved past the last snapshot beyond a threshold. */
s32 Camera_HasMoved(u8 tight) {
    extern f32 gCamEyeMoveThreshLoose;
    f32 thresh;
    u8 moved;
    void *cam;
    void *cam2;

    cam = (void *) gActiveCam;
    if (cam == NULL) {
        moved = 0;
    } else {
        if ((u8) gActiveCamIndex == 0) {
            M2C_FIELD(cam, f32 *, 0x4C) = M2C_FIELD(gBattleState, f32 *, 0x52C);
            M2C_FIELD(cam, f32 *, 0x50) = M2C_FIELD(gBattleState, f32 *, 0x530);
            M2C_FIELD(cam, f32 *, 0x54) = M2C_FIELD(gBattleState, f32 *, 0x53C);
        }
        cam = (void *) gActiveCam;
        thresh = lbl_80368C8C;
        if (tight != 0) {
            thresh = gCamAtMoveThreshTight;
        }
        if ((f32) __fabs((f64) (M2C_FIELD(cam, f32 *, 0x4C) - M2C_FIELD(cam, f32 *, 0x40))) > thresh) {
            moved = 1;
        } else if ((f32) __fabs((f64) (M2C_FIELD(cam, f32 *, 0x50) - M2C_FIELD(cam, f32 *, 0x44))) > thresh) {
            moved = 1;
        } else {
            moved = 0;
        }
    }
    if (moved == 1) {
        return 1;
    }
    cam2 = (void *) gActiveCam;
    if (cam2 == NULL) {
        moved = 0;
    } else {
        thresh = gCamEyeMoveThreshLoose;
        if (tight != 0) {
            thresh = lbl_80368C8C;
        }
        if ((f32) __fabs((f64) (M2C_FIELD(cam2, f32 *, 0x4) - M2C_FIELD(cam2, f32 *, 0x10))) > thresh) {
            moved = 1;
        } else if ((f32) __fabs((f64) (M2C_FIELD(cam2, f32 *, 0x8) - M2C_FIELD(cam2, f32 *, 0x14))) > thresh) {
            moved = 1;
        } else if ((f32) __fabs((f64) (M2C_FIELD(cam2, f32 *, 0xC) - M2C_FIELD(cam2, f32 *, 0x18))) > thresh) {
            moved = 1;
        } else {
            moved = 0;
        }
    }
    if (moved != 1) {
        goto zero;
    }
    return 1;
zero:
    return 0;
}

s32 fn_80018A08(u8 arg0) {
    extern long gActiveCam;
    extern u8 gActiveCamIndex;
    extern u16 gBattleState[700];
    extern f32 lbl_80368C8C;
    extern f32 gCamAtMoveThreshTight;
    f32 var_f2;
    void *p;
    s32 r;

    p = (void *)gActiveCam;
    if (p == NULL) {
        return 0;
    }
    if ((u8)gActiveCamIndex == 0) {
        *(f32 *)((u8 *)p + 0x4C) = *(f32 *)((u8 *)gBattleState + 0x52C);
        *(f32 *)((u8 *)p + 0x50) = *(f32 *)((u8 *)gBattleState + 0x530);
        *(f32 *)((u8 *)p + 0x54) = *(f32 *)((u8 *)gBattleState + 0x53C);
    }
    p = (void *)gActiveCam;
    var_f2 = lbl_80368C8C;
    if (arg0 != 0) {
        var_f2 = gCamAtMoveThreshTight;
    }
    if ((f32)__fabs((f64)(*(f32 *)((u8 *)p + 0x4C) - *(f32 *)((u8 *)p + 0x40))) > var_f2) {
        return 1;
    }
    if ((f32)__fabs((f64)(*(f32 *)((u8 *)p + 0x50) - *(f32 *)((u8 *)p + 0x44))) > var_f2) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

#pragma cplusplus on
extern "C" void fn_80018AAC(void) {
    extern s32 gActiveCam;
    struct Cam {
        u8 pad[0x74];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
    };
    ((Cam *)gActiveCam)->v0();
}
#pragma cplusplus off
s32 Camera_GetActive(void) {
    extern s32 gActiveCam;
    return gActiveCam;
}

void fn_80018AE4(void) {
    extern u8 lbl_803671C0;
    lbl_803671C0 -= 1;
}

void fn_80018AF4(void) {
    lbl_803671C0 += 1;
}

void fn_80018B04(void) {
    u8 temp = lbl_80366DB0;
    lbl_803671C0 = temp;
    lbl_80366DB0 = 0xFF;
}

void fn_80018B18(void) {
    extern u8 lbl_80366DB0;
    extern u8 lbl_803671C0;
    lbl_80366DB0 = lbl_803671C0;
}

#pragma cplusplus on
extern "C" void fn_80018B24(void) {
    f32 Math_Lerp(f32, f32, f32, f32);
    void *Map_Get(void);
    void PSMTXRotRad(f32 *, s32, f32);
    void PSMTXConcat(f32 *, f32 *, f32 *);
    void fn_802029C4(f32 *, f32 *, f32 *);
    void fn_80067FE8(f32 *, f32 *, f32 *);
    void fn_8006785C(s32, void (*)(void *), void *);
    void fn_800193D8(void *);
    extern long gActiveCam;
    extern u8 lbl_8036728B;
    extern s32 gBattleMap[];
    extern f32 lbl_80368C88;
    extern f32 lbl_80368CA4;
    extern f32 lbl_80368CBC;
    extern f32 lbl_80368CB4;
    extern f32 lbl_80368CB8;
    extern f32 lbl_80368CC0;
    extern f32 lbl_80368CC4;
    struct Cam {
        u8 pad[0x74];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
    };
    f32 sp38[12];
    f32 sp8[12];
    void *r31;
    f32 f31;
    f32 f30;
    f32 f29;
    void *child;
    f32 t;
    f32 a;
    f32 b;

    ((Cam *)gActiveCam)->v3();
    r31 = (void *)gActiveCam;
    if ((lbl_8036728B & 1) != 0) {
        t = lbl_80368C88;
        *(f32 *)((u8 *)r31 + 0x64) = t;
        *(f32 *)((u8 *)r31 + 0x68) = t;
    } else {
        f29 = lbl_80368CA4 * (f32)gBattleMap[1];
        f30 = lbl_80368CA4 * (f32)gBattleMap[0];
        f31 = Math_Lerp(lbl_80368C88, lbl_80368CB4, lbl_80368CB8,
                          *(f32 *)((u8 *)r31 + 0x18) - lbl_80368CBC);
        if (f31 < lbl_80368C88) {
            f31 = lbl_80368C88;
        }
        if (f31 > lbl_80368CB4) {
            f31 = lbl_80368CB4;
        }
        a = *(f32 *)((u8 *)r31 + 0x40);
        *(f32 *)((u8 *)r31 + 0x64) = -Math_Lerp(lbl_80368C88, f31, f30, a - f30);
        a = *(f32 *)((u8 *)r31 + 0x44);
        *(f32 *)((u8 *)r31 + 0x68) = -Math_Lerp(lbl_80368C88, f31, f29, a - f29);
    }
    t = *(f32 *)((u8 *)r31 + 0x18);
    child = *(void **)r31;
    *(f32 *)((u8 *)child + 0xF8) = t;
    t = *(f32 *)((u8 *)r31 + 0x10);
    child = *(void **)r31;
    *(f32 *)((u8 *)child + 0xFC) = t;
    t = *(f32 *)((u8 *)r31 + 0x14);
    child = *(void **)r31;
    *(f32 *)((u8 *)child + 0x100) = t;
    a = *(f32 *)((u8 *)r31 + 0x40);
    b = *(f32 *)((u8 *)r31 + 0x58);
    t = *(f32 *)((u8 *)r31 + 0x64);
    child = *(void **)r31;
    *(f32 *)((u8 *)child + 0xE0) = (a + b) + t;
    a = *(f32 *)((u8 *)r31 + 0x44);
    b = *(f32 *)((u8 *)r31 + 0x5C);
    t = *(f32 *)((u8 *)r31 + 0x68);
    child = *(void **)r31;
    *(f32 *)((u8 *)child + 0xE4) = (a + b) + t;
    {
        void *cam = Map_Get();
        f32 z;
        f32 c0;
        f32 c4;
        a = *(f32 *)((u8 *)r31 + 0x48);
        b = *(f32 *)((u8 *)r31 + 0x60);
        t = *(f32 *)((u8 *)*(void **)((u8 *)cam + 0x30) + 0x48);
        z = lbl_80368C88;
        c0 = lbl_80368CC0;
        c4 = lbl_80368CC4;
        child = *(void **)r31;
        *(f32 *)((u8 *)child + 0xE8) = (a + b) - t;
        child = *(void **)r31;
        *(f32 *)((u8 *)child + 0xEC) = z;
        child = *(void **)r31;
        *(f32 *)((u8 *)child + 0xF0) = c0;
        child = *(void **)r31;
        *(f32 *)((u8 *)child + 0xF4) = z;
        child = *(void **)r31;
        *(f32 *)((u8 *)child + 0xD4) = z;
        child = *(void **)r31;
        *(f32 *)((u8 *)child + 0xD8) = z;
        child = *(void **)r31;
        *(f32 *)((u8 *)child + 0xDC) = -*(f32 *)((u8 *)child + 0xF8);
        child = *(void **)r31;
        PSMTXRotRad(sp8, 0x58, c4 * *(f32 *)((u8 *)child + 0x100));
        child = *(void **)r31;
        PSMTXRotRad(sp38, 0x5A, c4 * *(f32 *)((u8 *)child + 0xFC));
    }
    PSMTXConcat(sp38, sp8, sp38);
    child = *(void **)r31;
    fn_802029C4(sp38, (f32 *)((u8 *)child + 0xD4), (f32 *)((u8 *)child + 0xD4));
    child = *(void **)r31;
    fn_802029C4(sp38, (f32 *)((u8 *)child + 0xEC), (f32 *)((u8 *)child + 0xEC));
    child = *(void **)r31;
    *(f32 *)((u8 *)child + 0xD4) =
        *(f32 *)((u8 *)child + 0xD4) + *(f32 *)((u8 *)child + 0xE0);
    child = *(void **)r31;
    *(f32 *)((u8 *)child + 0xD8) =
        *(f32 *)((u8 *)child + 0xD8) + *(f32 *)((u8 *)child + 0xE4);
    child = *(void **)r31;
    *(f32 *)((u8 *)child + 0xDC) =
        *(f32 *)((u8 *)child + 0xDC) + *(f32 *)((u8 *)child + 0xE8);
    child = *(void **)r31;
    fn_80067FE8((f32 *)((u8 *)child + 0xD4), (f32 *)((u8 *)child + 0xEC), (f32 *)((u8 *)child + 0xE0));
    fn_8006785C(0, fn_800193D8, r31);
}

extern "C" void fn_80018E0C(void)
{
    void Ui_PlaySeCue(void *, s32);
    extern u8 lbl_803671C0;
    extern u8 gActiveCamIndex;
    extern s32 gActiveCam;
    extern u8 lbl_802CA2C8[];
    extern u8 lbl_80268330[];
    u8 *base;
    s32 index;

    base = lbl_802CA2C8;
    if (lbl_803671C0 == 0) {
        index = (gActiveCamIndex + 1) % 2;
        gActiveCamIndex = index;
        switch (index) {
        case 0:
            gActiveCam = (s32)base + 0;
            break;
        case 1:
            gActiveCam = (s32)base + 0x78;
            break;
        case 2:
            gActiveCam = (s32)base + 0xF0;
            break;
        case 3:
            gActiveCam = (s32)base + 0x16C;
            break;
        }
    }
    Ui_PlaySeCue(lbl_80268330 + 0x18C, 0x64);
}

extern "C" void fn_80018EC0(void)
{
  extern s32 gActiveCam;
  extern f32 lbl_80368C88;
  extern f32 lbl_80368C8C;
  void *new_var;
  void *p;
  f32 f2;
  f32 f1;
  f32 f0;
  s32 z;
  p = (void *) gActiveCam;
  if (p != NULL)
  {
    f2 = lbl_80368C8C;
    z = 0;
    f1 = lbl_80368C88;
    if ((f1 && f1) && f1)
    {
    }
    *((f32 *) (((s8 *) p) + 0x28)) = f2;
    f0 = lbl_80368C8C;
    *((f32 *) (((s8 *) p) + 0x34)) = lbl_80368C8C;
    *((f32 *) (((s8 *) p) + 0x58)) = f1;
    new_var = p;
    *((f32 *) (((s8 *) new_var) + 0x5C)) = f1;
    *((f32 *) (((s8 *) new_var) + 0x60)) = f1;
    *((f32 *) (((s8 *) new_var) + 0x64)) = f1;
    *((f32 *) (((s8 *) new_var) + 0x68)) = f1;
    *((f32 *) (((s8 *) p) + 0x6C)) = f1;
    *((s32 *) (((s8 *) new_var) + 0x1C)) = z;
    *((f32 *) (((s8 *) new_var) + ((0, 0x70)))) = f0;
  }
}

#pragma cplusplus on
#pragma optimization_level 2
#pragma peephole off
extern "C" void Camera_InitSlots(void) {
    s32 Camera_Get(void);
    extern u8 lbl_802CA2C8[];
    extern u8 lbl_803671C1;
    extern f32 lbl_80368C88;
    extern f32 lbl_80368CC8;
    extern f32 lbl_80368CA0;
    struct Obj {
        u8 pad[0x74];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual f32 v2(s32) = 0;
    };
    struct Slot { u8 pad[0x78]; };
    struct Slot *base;
    struct Slot *slot;
    f32 f1;

    base = (struct Slot *)lbl_802CA2C8;
    slot = (struct Slot *)((char *)base + 0);
    *(s32 *)((u8 *)slot + 0x20) = 0;
    *(s32 *)base = Camera_Get();
    *(f32 *)((u8 *)slot + 0x10) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x4) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x14) = lbl_80368CC8;
    *(f32 *)((u8 *)slot + 0x8) = lbl_80368CC8;
    f1 = ((Obj *)slot)->v2(*(s32 *)((u8 *)slot + 0x20));
    {
        struct Slot *saved = slot;
        slot = (struct Slot *)((char *)base + 0x78);
        *(f32 *)((u8 *)saved + 0x18) = f1;
        *(f32 *)((u8 *)saved + 0xC) = f1;
        *((u8 *)saved + 0x24) = 1;
        lbl_803671C0 = 0;
        lbl_803671C1 = 0;
        *(f32 *)((u8 *)saved + 0x40) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x4C) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x44) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x50) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x48) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x54) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x28) = lbl_80368CA0;
        *(f32 *)((u8 *)saved + 0x34) = lbl_80368CA0;
        *(f32 *)((u8 *)saved + 0x58) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x5C) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x60) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x64) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x68) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x6C) = lbl_80368C88;
        *(s32 *)((u8 *)saved + 0x1C) = 0;
        *(f32 *)((u8 *)saved + 0x70) = lbl_80368C8C;
    }

    *(s32 *)((u8 *)slot + 0x20) = 0;
    *(s32 *)((u8 *)base + 0x78) = Camera_Get();
    *(f32 *)((u8 *)slot + 0x10) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x4) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x14) = lbl_80368CC8;
    *(f32 *)((u8 *)slot + 0x8) = lbl_80368CC8;
    f1 = ((Obj *)slot)->v2(*(s32 *)((u8 *)slot + 0x20));
    {
        struct Slot *saved = slot;
        slot = (struct Slot *)((char *)base + 0xF0);
        *(f32 *)((u8 *)saved + 0x18) = f1;
        *(f32 *)((u8 *)saved + 0xC) = f1;
        *((u8 *)saved + 0x24) = 1;
        lbl_803671C0 = 0;
        lbl_803671C1 = 0;
        *(f32 *)((u8 *)saved + 0x40) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x4C) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x44) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x50) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x48) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x54) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x28) = lbl_80368CA0;
        *(f32 *)((u8 *)saved + 0x34) = lbl_80368CA0;
        *(f32 *)((u8 *)saved + 0x58) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x5C) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x60) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x64) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x68) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x6C) = lbl_80368C88;
        *(s32 *)((u8 *)saved + 0x1C) = 0;
        *(f32 *)((u8 *)saved + 0x70) = lbl_80368C8C;
    }

    *(s32 *)((u8 *)slot + 0x20) = 0;
    *(s32 *)((u8 *)base + 0xF0) = Camera_Get();
    *(f32 *)((u8 *)slot + 0x10) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x4) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x14) = lbl_80368CC8;
    *(f32 *)((u8 *)slot + 0x8) = lbl_80368CC8;
    f1 = ((Obj *)slot)->v2(*(s32 *)((u8 *)slot + 0x20));
    {
        struct Slot *saved = slot;
        slot = (struct Slot *)((char *)base + 0x16C);
        *(f32 *)((u8 *)saved + 0x18) = f1;
        *(f32 *)((u8 *)saved + 0xC) = f1;
        *((u8 *)saved + 0x24) = 1;
        lbl_803671C0 = 0;
        lbl_803671C1 = 0;
        *(f32 *)((u8 *)saved + 0x40) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x4C) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x44) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x50) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x48) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x54) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x28) = lbl_80368CA0;
        *(f32 *)((u8 *)saved + 0x34) = lbl_80368CA0;
        *(f32 *)((u8 *)saved + 0x58) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x5C) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x60) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x64) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x68) = lbl_80368C88;
        *(f32 *)((u8 *)saved + 0x6C) = lbl_80368C88;
        *(s32 *)((u8 *)saved + 0x1C) = 0;
        *(f32 *)((u8 *)saved + 0x70) = lbl_80368C8C;
    }

    *(s32 *)((u8 *)slot + 0x20) = 0;
    *(s32 *)((u8 *)base + 0x16C) = Camera_Get();
    *(f32 *)((u8 *)slot + 0x10) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x4) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x14) = lbl_80368CC8;
    *(f32 *)((u8 *)slot + 0x8) = lbl_80368CC8;
    f1 = ((Obj *)slot)->v2(*(s32 *)((u8 *)slot + 0x20));
    *(f32 *)((u8 *)slot + 0x18) = f1;
    *(f32 *)((u8 *)slot + 0xC) = f1;
    *((u8 *)slot + 0x24) = 1;
    lbl_803671C0 = 0;
    lbl_803671C1 = 0;
    *(f32 *)((u8 *)slot + 0x40) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x4C) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x44) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x50) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x48) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x54) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x28) = lbl_80368CA0;
    *(f32 *)((u8 *)slot + 0x34) = lbl_80368CA0;
    *(f32 *)((u8 *)slot + 0x58) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x5C) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x60) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x64) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x68) = lbl_80368C88;
    *(f32 *)((u8 *)slot + 0x6C) = lbl_80368C88;
    *(s32 *)((u8 *)slot + 0x1C) = 0;
    *(f32 *)((u8 *)slot + 0x70) = lbl_80368C8C;
    gActiveCamIndex = 0;
    gActiveCam = (s32)base;
}
#pragma peephole reset
#pragma optimization_level reset
#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on
static inline void fn_80018F08_init(u8 *base, u8 *slot) {
    s32 Camera_Get(void);
    extern u8 lbl_803671C1;
    extern f32 lbl_80368C88;
    extern f32 lbl_80368CC8;
    extern f32 lbl_80368CA0;
    struct Obj {
        u8 pad[0x74];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual f32 v2(s32) = 0;
    };
    f32 f1;
    *(s32 *)(slot + 0x20) = 0;
    *(s32 *)slot = Camera_Get();
    *(f32 *)(slot + 0x10) = lbl_80368C88;
    *(f32 *)(slot + 0x4) = lbl_80368C88;
    *(f32 *)(slot + 0x14) = lbl_80368CC8;
    *(f32 *)(slot + 0x8) = lbl_80368CC8;
    f1 = ((Obj *)slot)->v2(*(s32 *)(slot + 0x20));
    *(f32 *)(slot + 0x18) = f1;
    *(f32 *)(slot + 0xC) = f1;
    slot[0x24] = 1;
    lbl_803671C0 = 0;
    lbl_803671C1 = 0;
    *(f32 *)(slot + 0x40) = lbl_80368C88;
    *(f32 *)(slot + 0x4C) = lbl_80368C88;
    *(f32 *)(slot + 0x44) = lbl_80368C88;
    *(f32 *)(slot + 0x50) = lbl_80368C88;
    *(f32 *)(slot + 0x48) = lbl_80368C88;
    *(f32 *)(slot + 0x54) = lbl_80368C88;
    *(f32 *)(slot + 0x28) = lbl_80368CA0;
    *(f32 *)(slot + 0x34) = lbl_80368CA0;
    *(f32 *)(slot + 0x58) = lbl_80368C88;
    *(f32 *)(slot + 0x5C) = lbl_80368C88;
    *(f32 *)(slot + 0x60) = lbl_80368C88;
    *(f32 *)(slot + 0x64) = lbl_80368C88;
    *(f32 *)(slot + 0x68) = lbl_80368C88;
    *(f32 *)(slot + 0x6C) = lbl_80368C88;
    *(s32 *)(slot + 0x1C) = 0;
    *(f32 *)(slot + 0x70) = lbl_80368C8C;
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_80019384(void *arg0, s32 arg1) {
    struct Obj {
        u8 pad[0x74];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual f32 v2(s32) = 0;
    };
    *(s32 *)((char *)arg0 + 0x20) = arg1 & 3;
    *(f32 *)((char *)arg0 + 0xC) = ((Obj *)arg0)->v2(*(s32 *)((char *)arg0 + 0x20));
}
#pragma cplusplus reset

void fn_800193CC(void *arg0, f32 farg0) {
    M2C_FIELD(arg0, f32 *, 0xC) = farg0;
    M2C_FIELD(arg0, f32 *, 0x18) = farg0;
}

void fn_800193D8(void *arg0)
{
    s32 temp = *(s32*)((u8*)arg0 + 0x274);
    if (temp < 1) {
        return;
    }
    *(f32*)((u8*)arg0 + 0x1A0) = 0.0f;
    *(f32*)((u8*)arg0 + 0x1A4) = 0.0f;
    *(f32*)((u8*)arg0 + 0x1A8) = 0.0f;
    *(f32*)((u8*)arg0 + 0x1AC) = 0.0f;
}

