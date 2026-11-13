/* Functions from 0x8014A370 to 0x8014E350, found by decomp-toolkit. */
#include "common.h"

extern s32 lbl_80367B00;
extern s32 lbl_80367B04;
extern u8 lbl_80367B0E;
extern u8 lbl_80367B44;

typedef struct { u8 a; u8 b; } Entry;
typedef struct { u8 pad[0x544]; s8 count; Entry entries[256]; } Obj;
extern u8 lbl_80367B08;
extern u8 lbl_80367B09;
extern u8 lbl_80367B0A;
extern u8 lbl_80367B0B;
extern u16 lbl_80292F60[];
extern f32 lbl_8036A7D0;
extern f32 lbl_8036A7D4;
extern f32 lbl_8036A7D8;
extern f32 lbl_8036A7DC;
extern f32 lbl_8036A7E0;
extern f64 lbl_8036A7E8;
extern u8 lbl_80367B0C;
extern u8 lbl_80367B0D;

void fn_800C426C(s32);
s32 fn_800C42AC(s32);
void *fn_8003FCCC(void *);
void fn_80024398(void *, s32, s32);
#pragma opt_strength_reduction off

extern s32 lbl_80367B00;
extern u8 lbl_80367B0D;

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

extern u16 *g_AccessoryArray;

void Stream_Write(void *, s32, void *);
void Stream_WriteU8(void *, u8);
void Stream_WriteS32(void *, s32);
void Stream_WriteU16(void *, u16);
void fn_8017A4CC(void *, s32, s32);
void fn_80105A30(void *, void *);
void fn_80014F94(void *, void *);
void fn_80199B88(void *, void *);
void fn_800BDAF8(void *, void *);
void fn_8017A480(void *, s32, void *);
void fn_8017A3E0(void *, s32, u8);
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
extern u16 lbl_80367B68;

void strcpy(s32, u32);

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#include "common.h"
extern f32 lbl_8036A7F0;
extern u8 gBattleMap[];
extern s32 lbl_80367B00;
extern s32 lbl_80367B04;
extern u8 lbl_80367B0D;

void Ui_PlaySeCue(s32, s32); /* extern */
#include "global.h"

extern void* fn_80019F04();
#include "common.h"
extern u8 gUnitLists[];
extern u8 gUnits[];
#include "common.h"
#include "ef.h"
#include "global.h"

extern u8 gBattleState[];
extern u8 lbl_80277060[];
extern u8 lbl_8032BB58[];
#include "global.h"
extern u8 gBattleState[];

void BattleState_Write(void *arg0, void *arg1) {
    void Stream_Write(void *, s32, void *);
    void Stream_WriteU8(void *, u8);
    void Stream_WriteU16(void *, u16);
    void Stream_WriteS32(void *, s32);
    void fn_8017A4CC(void *, s64);
    void fn_8017A480(void *, s32, void *);
    void fn_8017A3E0(void *, s32, s32);
    void fn_80105A30(void *, void *);
    void fn_80014F94(void *, void *);
    void fn_80199B88(void *, void *);
    void fn_800BDAF8(void *, void *);
    s32 i;

    Stream_Write(arg1, 0x10, arg0);
    Stream_WriteU8(arg1, *(u8 *)((u8 *)arg0 + 0x10));
    Stream_WriteU8(arg1, *(u8 *)((u8 *)arg0 + 0x11));
    Stream_WriteU16(arg1, (u16)*(s16 *)((u8 *)arg0 + 0x12));
    for (i = 0; i < 4; i++) {
        Stream_WriteU8(arg1, *(u8 *)((u8 *)arg0 + 0x14 + i));
    }
    Stream_WriteS32(arg1, *(s32 *)((u8 *)arg0 + 0x18));
    Stream_WriteS32(arg1, *(s32 *)((u8 *)arg0 + 0x1c));
    Stream_Write(arg1, 0x30, (u8 *)arg0 + 0x20);
    Stream_WriteU8(arg1, *(u8 *)((u8 *)arg0 + 0x50));
    Stream_WriteU8(arg1, *(u8 *)((u8 *)arg0 + 0x51));
    Stream_WriteU8(arg1, (u8)(s32)*(f32 *)((u8 *)arg0 + 0x524));
    Stream_WriteU8(arg1, (u8)(s32)*(f32 *)((u8 *)arg0 + 0x528));
    Stream_WriteU8(arg1, *(u8 *)((u8 *)arg0 + 0x54));
    Stream_WriteU8(arg1, *(u8 *)((u8 *)arg0 + 0x55));
    Stream_WriteU8(arg1, *(u8 *)((u8 *)arg0 + 0x56));
    Stream_WriteU8(arg1, *(u8 *)((u8 *)arg0 + 0x57));
    fn_8017A4CC(arg1, *(s64 *)((u8 *)arg0 + 0x58));
    fn_8017A4CC(arg1, *(s64 *)((u8 *)arg0 + 0x60));
    Stream_WriteS32(arg1, *(s32 *)((u8 *)arg0 + 0x68));
    Stream_WriteS32(arg1, *(s32 *)((u8 *)arg0 + 0x6c));
    Stream_WriteU16(arg1, (u16)*(s16 *)((u8 *)arg0 + 0x70));
    Stream_WriteU16(arg1, (u16)*(s16 *)((u8 *)arg0 + 0x72));
    fn_80105A30((u8 *)arg0 + 0x74, arg1);
    fn_80105A30((u8 *)arg0 + 0x84, arg1);
    fn_80014F94((u8 *)arg0 + 0x94, arg1);
    fn_80014F94((u8 *)arg0 + 0x98, arg1);
    fn_80199B88((u8 *)arg0 + 0x9c, arg1);
    fn_800BDAF8((u8 *)arg0 + 0xb4, arg1);
    Stream_Write(arg1, 0x140, (u8 *)arg0 + 0x3c4);
    fn_8017A480(arg1, 0x18, (u8 *)arg0 + 0x504);
    fn_8017A3E0(arg1, 8, 0);
}

s32* fn_8014C5A8(s32 arg0, u8 arg1) {
    if (arg1 == 0) {
        return (s32*)(arg0 + 0x94);
    }
    if (arg1 == 3) {
        return (s32*)(arg0 + 0x98);
    }
    fn_8001520C(&lbl_80367B68, 1);
    return (s32*)&lbl_80367B68;
}

void fn_8014C5F4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x70) = (s16) (M2C_FIELD(arg0, s16 *, 0x70) + arg1);
}

void *fn_8014C604(void) {
    void Allegiance_FillMask(s32, void *);
    extern u8 gUnits[];
    u8 sp8[8];
    u8 *best;
    s32 best_val;
    u8 *unit;
    s32 i;

    best = NULL;
    best_val = 0;
    Allegiance_FillMask(4, sp8);
    for (i = 1; i <= 0x9F; i++) {
        if ((u8)i != 0) {
            unit = (u8 *)gUnits + ((u8)i - 1) * 0x280;
        } else {
            unit = NULL;
        }
        if (*(u32 *)(unit + 0x188) != 0) {
            if (sp8[*(u8 *)(*(u8 **)(unit + 0x190) + 8)] != 0) {
                s32 v = *(u16 *)(unit + 0x22C);
                if (best_val < v) {
                    best_val = v;
                    best = unit;
                }
            }
        }
    }
    return best;
}

s32 fn_8014C6B8(void) {
    M2C_UNK Map_Get();
    M2C_UNK fn_80040854();
    Map_Get();
    fn_80040854();
    return 1;
}

s32 fn_8014C6E0(void) {
    u8 fn_80040824();
    M2C_UNK fn_800AA134();
    if (fn_80040824() == 0) {
        return 0;
    }
    fn_800AA134();
    return 1;
}

void fn_8014C718(void *arg0, u32 arg1) {
    u8 fn_80040824(void);
    void *fn_8000CA64(void *, u32);
    extern u8 lbl_80293760[];
    if (fn_80040824() != 0) {
        if (arg1 == 0) {
            fn_800AA134();
            Map_Get();
            fn_80040854();
        } else {
            fn_8000CA64(lbl_80293760, arg1);
        }
    }
}

void fn_8014C774(void) {
    M2C_UNK fn_80040854();
    M2C_UNK Map_Get();
    Map_Get();
    fn_80040854();
}

void fn_8014C798(void) {
    M2C_UNK fn_80018EC0();
    M2C_UNK Map_Get();
    M2C_UNK fn_80042558();
    fn_80018EC0();
    Map_Get();
    fn_80042558();
}

void fn_8014C7C0(void *arg0, char *arg1) {
    void *fn_80019F04(u8);
    void strcpy(char *, char *);
    void sprintf(char *, char *, ...);
    void *fn_800408A8(s32);
    void fn_8004084C(void *);
    void *Map_Get(void);
    void fn_80041514(void *, char *);
    void fn_80023D14(void *);
    void fn_800AA15C(void);
    void fn_800056CC(char *, ...);
    extern u8 lbl_80277060[];
    extern u8 gBattleMap[];
    char buffer[0x40];
    char *str;

    if ((str = arg1) == NULL) {
        void *tmp = fn_80019F04(*(u8 *)((u8 *)arg0 + 0x10));
        str = *(char **)((u8 *)tmp + 4);
        if (str == NULL) {
            *((u8 *)arg0 + 0x504) = 0;
            goto after_copy;
        }
        goto copy;
    }
copy:
    strcpy((char *)((u8 *)arg0 + 0x504), str);
after_copy:
    sprintf(buffer, (char *)lbl_80277060 + 0x155, str);
    fn_8004084C(fn_800408A8(0));
    fn_80041514(Map_Get(), buffer);
    fn_80023D14(gBattleMap);
    fn_800AA15C();
    fn_800056CC((char *)lbl_80277060 + 0x15e, str);
}

void fn_8014CA20(void *arg0, s32 arg1) {
    void *base = arg0;
    Msg_Expand((u8 *)base + (arg1 + 2) * 0xC + 0x20, base);
}

s32 fn_8014CA54(s32 arg0, s32 arg1) {
    return (arg1 * 0xC) + arg0 + 0x20;
}

void fn_8014CA68(s32 arg0, s32 arg1) {
 void Msg_Expand(s32, s32);
 s32 t=arg1*12;
 u8 *p=(u8*)(t+0x20);
 Msg_Expand((s32)&p[arg0],t);
}

void fn_8014CA98(s32 arg0, s32 arg1, u32 arg2) {
    M2C_UNK strcpy(s32, u32);
    if (arg2 != 0U) {
        strcpy(arg0 + ((arg1 * 0xC) + 0x20), arg2);
    }
}

void fn_8014CAD4(void *arg0, f32 farg0, f32 farg1) {
    f32 fn_80023068(void *);
    *(f32 *)((u8 *)arg0 + 0x52C) = farg0;
    *(f32 *)((u8 *)arg0 + 0x530) = farg1;
    *(f32 *)((u8 *)arg0 + 0x53C) = fn_80023068(gBattleMap);
}

void fn_8014CB14(void *arg0, void *arg1) {
    f32 fn_80023068(void *, f32, f32);
    extern u8 gBattleMap[];
    extern f32 lbl_8036A7F0;
    f32 temp_f31;
    f32 temp_f30;

    temp_f30 = (s8)((u8 *)arg1)[0x19F];
    temp_f31 = (s8)((u8 *)arg1)[0x19E];
    temp_f31 += lbl_8036A7F0;
    temp_f30 += lbl_8036A7F0;
    *(f32 *)((u8 *)arg0 + 0x524) = temp_f31;
    *(f32 *)((u8 *)arg0 + 0x528) = temp_f30;
    *(f32 *)((u8 *)arg0 + 0x52C) = temp_f31;
    *(f32 *)((u8 *)arg0 + 0x530) = temp_f30;
    *(f32 *)((u8 *)arg0 + 0x53C) = fn_80023068(gBattleMap, temp_f31, temp_f30);
    *(f32 *)((u8 *)arg0 + 0x534) = temp_f31;
    *(f32 *)((u8 *)arg0 + 0x538) = temp_f30;
}

void fn_8014CBD8(void *arg0, f32 farg0, f32 farg1) {
    f32 fn_80023068(void *, f32, f32);
    extern f32 lbl_8036A7F0;
    f32 temp_f31;
    f32 temp_f30;

    temp_f30 = farg0 + lbl_8036A7F0;
    temp_f31 = farg1 + lbl_8036A7F0;
    *(f32 *)((u8 *)arg0 + 0x524) = temp_f30;
    *(f32 *)((u8 *)arg0 + 0x528) = temp_f31;
    *(f32 *)((u8 *)arg0 + 0x52C) = temp_f30;
    *(f32 *)((u8 *)arg0 + 0x530) = temp_f31;
    *(f32 *)((u8 *)arg0 + 0x53C) = fn_80023068(gBattleMap, temp_f30, temp_f31);
    *(f32 *)((u8 *)arg0 + 0x534) = temp_f30;
    *(f32 *)((u8 *)arg0 + 0x538) = temp_f31;
}
