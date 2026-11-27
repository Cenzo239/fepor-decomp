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

s32 fn_8014A370(void) {
    return 0x10;
}

s32 fn_8014A378(void) {
    return 0x10;
}

s32 fn_8014A380(void) {
    return 0x10;
}

void *fn_8014A388(void) {
    extern u16 gSoundMenuStrings[];
    return (u8 *)gSoundMenuStrings + 0x99;
}

void *fn_8014A398(void) {
    extern u16 gSoundMenuStrings[];
    return (u8 *)gSoundMenuStrings + 0xc6;
}

s32 fn_8014A3A8(void)
{
    extern u8 gFxChannels[];
    extern u8 gSeCueSlots[];
#pragma cplusplus on
    struct Pad {
        u8 pad[8];
    };
    struct Chan : Pad {
        virtual u8 check();
        virtual void gap();
        virtual void update();
        u8 flags;
    };

    s32 i;
    Chan *p;
    u8 active;
    u8 *base;

    base = gFxChannels;
    i = 0;
    while (i < 4) {
        p = (Chan *)(base + (u8)i * 0x30);
        active = 0;
        if ((p->flags & 1) && p->check())
            active = 1;
        if (active)
            p->update();
        i++;
    }

    base = gSeCueSlots;
    active = 0;
    i = 0;
    while (i < 28) {
        p = (Chan *)(base + (u8)i * 0x30);
        active = 0;
        if ((p->flags & 1) && p->check())
            active = 1;
        if (active)
            p->update();
        i++;
    }

    return 0;
#pragma cplusplus reset
}

void *fn_8014A4C8(void) {
    extern char gSoundMenuStrings[];
    return &gSoundMenuStrings[0xCF];
}

s32 fn_8014A4D8(void) {
    return 2;
}

s32 fn_8014A4E0(void) {
    return 0;
}

void *fn_8014A4E8(void) {
    extern u16 gSoundMenuStrings[];
    return (char *)gSoundMenuStrings + 0xDE;
}

void Heap_FreeRaw(s32);
s32 Heap_AllocRaw(s32);
void *Archive_Load(void *);
void Ui_CreateMenu(void *, s32, s32);
#pragma opt_strength_reduction off
s32 fn_8014A4F8(s32 arg0, s32 arg1)
{
    extern u16 lbl_80276F00[];
    void fn_800C426C(s32);
    s32 fn_800C42AC(s32);
    void *fn_8003FCCC(void *);
    void fn_80024398(void *, s32, s32);
    s32 var_r11;
    s32 var_ctr;
    s32 temp_r9, temp_r8, temp_r7, temp_r6, temp_r5, temp_r4, temp_r0, temp_r11;
    u8 *var_r3;
    u8 var_r5;
    s32 temp_r4_2;

    (void)arg0;
    lbl_80367B08 = 1;
    fn_800C426C(lbl_80367B00);
    lbl_80367B00 = 0;
    var_ctr = 0x60;
    lbl_80367B00 = fn_800C42AC(0x1800);
    var_r11 = 0;
    for (; var_ctr != 0; var_ctr--) {
        *(s32 *)(lbl_80367B00 + var_r11) = 0;
        *(s32 *)(lbl_80367B00 + (var_r11 + 4)) = 0;
        temp_r9 = var_r11 + 0x24;
        *(s32 *)(lbl_80367B00 + (var_r11 + 8)) = 0;
        temp_r8 = var_r11 + 0x28;
        *(s32 *)(lbl_80367B00 + (var_r11 + 0xC)) = 0;
        temp_r7 = var_r11 + 0x2C;
        *(s32 *)(lbl_80367B00 + (var_r11 + 0x10)) = 0;
        temp_r6 = var_r11 + 0x30;
        *(s32 *)(lbl_80367B00 + (var_r11 + 0x14)) = 0;
        temp_r5 = var_r11 + 0x34;
        *(s32 *)(lbl_80367B00 + (var_r11 + 0x18)) = 0;
        temp_r4 = var_r11 + 0x38;
        *(s32 *)(lbl_80367B00 + (var_r11 + 0x1C)) = 0;
        temp_r0 = var_r11 + 0x3C;
        temp_r11 = var_r11 + 0x20;
        *(s32 *)(lbl_80367B00 + temp_r11) = 0;
        var_r11 = temp_r11 + 0x20;
        *(s32 *)(lbl_80367B00 + temp_r9) = 0;
        *(s32 *)(lbl_80367B00 + temp_r8) = 0;
        *(s32 *)(lbl_80367B00 + temp_r7) = 0;
        *(s32 *)(lbl_80367B00 + temp_r6) = 0;
        *(s32 *)(lbl_80367B00 + temp_r5) = 0;
        *(s32 *)(lbl_80367B00 + temp_r4) = 0;
        *(s32 *)(lbl_80367B00 + temp_r0) = 0;
    }
    lbl_80367B04 = 0;
    var_r3 = fn_8003FCCC((u8 *)lbl_80276F00 + 0x6b);
    goto loop_check;
loop_body:
    if ((s8)lbl_80367B08 == 0) {
        if (var_r3[5] & 4) {
            goto block_7;
        }
    } else if (!(var_r3[5] & 4)) {
    block_7:
        temp_r4_2 = lbl_80367B04;
        lbl_80367B04 = temp_r4_2 + 1;
        *(s32 *)(lbl_80367B00 + (temp_r4_2 * 4)) = *(s32 *)var_r3;
    }
    if (var_r3[4] == 0) {
        var_r3 = 0;
    } else {
        var_r3 += var_r3[4];
    }
loop_check:
    if ((var_r3[4] == 0) ? 0 : (s32)(var_r3 + var_r3[4])) {
        goto loop_body;
    }
    var_r5 = lbl_80367B0A;
    if ((s8)lbl_80367B08 == 0) {
        var_r5 = lbl_80367B09;
    }
    lbl_80367B0D = var_r5;
    lbl_80367B0E = (lbl_80367B04 + 0x17) / 24;
    fn_80024398(&lbl_80367B44, arg1, 0);
    return 0;
}
void *fn_8014A6FC(void) {
    extern u16 gSoundMenuStrings[];
    return (u8 *)gSoundMenuStrings + 0xEC;
}

#pragma opt_strength_reduction on
#pragma peephole on
#pragma global_optimizer on
s32 fn_8014A70C(s32 arg0, s32 arg1)
{
    extern u16 gSoundMenuStrings[];
    u32 off;
    s32 ctr;
    u8 *node;
    u8 *next;
    u8 flag;
    s32 idx;

    (void)arg0;
    lbl_80367B08 = 0;
    Heap_FreeRaw(lbl_80367B00);
    lbl_80367B00 = 0;
    lbl_80367B00 = Heap_AllocRaw(0x1800);

    for (off=0; off<0x600; off++) {
        ((s32 *)lbl_80367B00)[off]=0;
    }

    lbl_80367B04 = 0;
    node = Archive_Load((u8 *)gSoundMenuStrings + 0x6b);
    goto check;

loop:
    if ((s8)lbl_80367B08 == 0) {
        if (node[5] & 4) goto store_node;
        goto skip_store;
    } else if (node[5] & 4) {
        goto skip_store;
    }
store_node:
    idx = lbl_80367B04;
    { s32 value=*(s32 *)node;
      s32 *dst=(s32 *)lbl_80367B00;
      lbl_80367B04 = idx + 1;
      dst[idx] = value; }
skip_store:
    if (node[4] == 0) {
        node = NULL;
    } else {
        node += node[4];
    }
check:
    if (node[4] == 0) {
        next = NULL;
    } else {
        next = node + node[4];
    }
    if (next != NULL) {
        goto loop;
    }

    flag = lbl_80367B0A;
    if ((s8)lbl_80367B08 == 0) {
        flag = lbl_80367B09;
    }
    lbl_80367B0D = flag;
    lbl_80367B0E = (lbl_80367B04 + 0x17) / 24;
    Ui_CreateMenu(&lbl_80367B44, arg1, 0);
    return 0;
}

s32 fn_8014A910(void) {
    return 0x40;
}

s32 fn_8014A918(void) {
    return 0x10;
}

s32 fn_8014A920(void) {
    return 0x130;
}

extern s32 lbl_80367B00;
extern u8 lbl_80367B0D;

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

extern u16 *g_AccessoryArray;

void Stream_Write(void *, s32, void *);
void Stream_WriteU8(void *, u8);
void Stream_WriteS32(void *, s32);
void Stream_WriteU16(void *, u16);
void Stream_WriteS64(void *, s32, s32);
void fn_80105A30(void *, void *);
void fn_80014F94(void *, void *);
void fn_80199B88(void *, void *);
void fn_800BDAF8(void *, void *);
void Stream_WriteStr(void *, s32, void *);
void Stream_WritePad(void *, s32, u8);
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
extern M2C_UNK gBattleMap;
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
extern u8 gMapObjEventList[];
#include "global.h"
extern u8 gBattleState[];
