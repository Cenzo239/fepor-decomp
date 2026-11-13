/* Functions from 0x800AD24C to 0x800C3F18, found by decomp-toolkit. */
#include "common.h"

typedef struct {
    u8 flag : 1;
    u8 unk : 7;
} ItemFlagBits;

static inline u32 LoadSoundBankB(void *path) {
    s32 fn_800B4A84(void *, s32, s32);
    s32 fn_800B49C8(void *);
    s32 fn_800B4A14(void *, s32, s32, s32);
    void fn_800B49D0(void *);
    s32 fn_800C4638(s32, void *, s32);
    void fn_800C4588(s32);
    extern u8 Sound_str[];
    s32 handle;
    s32 size;
    u32 buffer;
    u32 value;
    handle = fn_800B4A84(path, 2, 0);
    if (handle == 0) return 0;
    value = fn_800B49C8((void *)handle);
    if (value == 0) return 0;
    size = (value + 31) & ~31;
    buffer = fn_800C4638(size, Sound_str + 0x2E, 0);
    if (buffer == 0) return 0;
    if (fn_800B4A14((void *)handle, buffer, size, 0) <= 0) {
        fn_800C4588(buffer);
        return 0;
    }
    fn_800B49D0((void *)handle);
    return buffer;
}

static inline u32 SoundReadSizeB(u32 offset, u32 limit) {
    u32 size = 0x8000;
    u32 step = 0x10000;
    u32 n;
    if (offset + 0x8000 > limit) size = limit - offset;
    else {
        for (n=2;n<6;n++) {
            if (offset + step > limit) {
                size -= (0x8000 - (limit - (offset + ((n-1)<<15)))) / n;
                size += 0x20 - (size & 31);
                break;
            }
            step += 0x8000;
        }
    }
    return size;
}

typedef struct StreamB { u8 pad[0x2C]; s32 buffers[2]; u8 pad34[0x14]; u32 size; u16 index; } StreamB;
typedef struct {
    u8 pad[0x30];
    void *entries[0xC];
    u8 kinds[0xC];
    s16 count;
    s16 cursor;
} EventBlessProc;
extern s32 fn_80010710(u8* arg0);
  extern s32 gUnitRef;
  extern s32 lbl_8028D544[];
  extern s32 lbl_80319A68[];
  void Battle_ClearPhaseBannerChild(void *);
  void Battle_DrawPhaseBanner(void *);

void fn_800AD24C(void) {
    extern u16 lbl_80312ACC[];
    extern void fn_800AD284(void);
    Array_Destroy(lbl_80312ACC, fn_800AD284, 0x10, 0x10);
}

s32 fn_800AD284(s32 arg0, s16 arg1) {
    M2C_UNK Item_Destroy(s32, M2C_UNK);
    M2C_UNK Heap_Free(s32);
    if (arg0 != 0) {
        Item_Destroy(arg0 + 4, -1);
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

s32 fn_800AD2DC(s32 arg0) {
    M2C_UNK fn_8001C76C(s32);
    fn_8001C76C(arg0 + 4);
    return arg0;
}

#pragma optimization_level 2
/* Collect same-allegiance units with Live/Rest statuses into an E_Bless process; return 0 if none. */
s32 Event_StartBless(s32 parent) {
    void *Process_CreateChild(void *, s32);
    void Process_Unlink(void *);
    void Allegiance_FillMask(s32, void *);
    s32 Item_GetByIid(void *);
    void fn_8002AB9C(void *, s32);
    void fn_8002AD04(void *, s32);
    u8 Status_Test(void *, s32);
    extern u8 lbl_8026E988[];
    extern u8 E_Bless_script[];
    extern u8 gUnits[];
    extern u8 gTargetList[];
    u8 allegMask;
    s16 count;
    void *unit;
    void *proc;
    s32 i;

    proc = Process_CreateChild(E_Bless_script, parent);
    *(s16 *)((u8 *)proc + 0x6C) = 0;
    *(s16 *)((u8 *)proc + 0x6E) = 0;
    *(s32 *)((u8 *)proc + 0x30) = 0;
    *((u8 *)proc + 0x60) = 0;
    *(s32 *)((u8 *)proc + 0x34) = 0;
    *((u8 *)proc + 0x61) = 0;
    *(s32 *)((u8 *)proc + 0x38) = 0;
    *((u8 *)proc + 0x62) = 0;
    *(s32 *)((u8 *)proc + 0x3C) = 0;
    *((u8 *)proc + 0x63) = 0;
    *(s32 *)((u8 *)proc + 0x40) = 0;
    *((u8 *)proc + 0x64) = 0;
    *(s32 *)((u8 *)proc + 0x44) = 0;
    *((u8 *)proc + 0x65) = 0;
    *(s32 *)((u8 *)proc + 0x48) = 0;
    *((u8 *)proc + 0x66) = 0;
    *(s32 *)((u8 *)proc + 0x4C) = 0;
    *((u8 *)proc + 0x67) = 0;
    *(s32 *)((u8 *)proc + 0x50) = 0;
    *((u8 *)proc + 0x68) = 0;
    *(s32 *)((u8 *)proc + 0x54) = 0;
    *((u8 *)proc + 0x69) = 0;
    *(s32 *)((u8 *)proc + 0x58) = 0;
    *((u8 *)proc + 0x6A) = 0;
    *(s32 *)((u8 *)proc + 0x5C) = 0;
    *((u8 *)proc + 0x6B) = 0;
    Allegiance_FillMask(0, &allegMask);
    i = 1;
    do {
        if ((u8)i != 0) {
            unit = gUnits + (((u8)i - 1) * 0x280);
        } else {
            unit = NULL;
        }
        if (*(u32 *)((u8 *)unit + 0x188) != 0
            && *((u8 *)&allegMask + *((u8 *)*(void **)((u8 *)unit + 0x190) + 8)) != 0
            && !(*(u32 *)((u8 *)unit + 0x1A0) & 4)
            && !((*(u16 *)((u8 *)unit + 0x1A4) >> 7) & 7)
            && !(*((u8 *)unit + 0x1A5) & 7)) {
            if (Status_Test((u8 *)unit + 0x1BC, 0x4A) != 0) {
                fn_8002AD04(unit, Item_GetByIid(lbl_8026E988 + 0x101));
                if (*(s32 *)gTargetList != 0) {
                    count = *(s16 *)((u8 *)proc + 0x6C);
                    if (count != 0xB) {
                        *(void **)((u8 *)proc + (count * 4) + 0x30) = unit;
                        *((u8 *)proc + *(s16 *)((u8 *)proc + 0x6C) + 0x60) = 1;
                        *(s16 *)((u8 *)proc + 0x6C) = (s16)(*(s16 *)((u8 *)proc + 0x6C) + 1);
                    }
                }
            }
            if (Status_Test((void *)((u32)unit + 0x1BC), 0x49) != 0) {
                fn_8002AB9C(unit, Item_GetByIid(lbl_8026E988 + 0x10A));
                if (*(s32 *)gTargetList != 0) {
                    count = *(s16 *)((u8 *)proc + 0x6C);
                    if (count != 0xB) {
                        *(void **)((u8 *)proc + (count * 4) + 0x30) = unit;
                        *((u8 *)proc + *(s16 *)((u8 *)proc + 0x6C) + 0x60) = 2;
                        *(s16 *)((u8 *)proc + 0x6C) = (s16)(*(s16 *)((u8 *)proc + 0x6C) + 1);
                    }
                }
            }
        }
        i += 1;
    } while (i <= 0x9F);
    if (*(s16 *)((u8 *)proc + 0x6C) == 0) {
        Process_Unlink(proc);
        return 0;
    }
    return 1;
}

/* Advance the E_Bless queue: begin move-select for the next unit, or finish at label 0x63. */
void Event_BlessNextUnit(EventBlessProc *proc) {
    void Process_Goto(void *, s32);
    void UiCtx_BeginMoveSelect(void *, void *);
    void fn_8002629C(void *, void *);
    void fn_800264BC(void *, void *);
    extern u8 gUiContext[];
    s32 idx;
    s32 count;
    void *unit;
    u8 kind;
    idx = proc->cursor;
    proc->cursor = idx + 1;
    count = proc->count;
    if (count >= 0xC) unit = NULL;
    else unit = proc->entries[idx];
    if (unit == NULL) {
        Process_Goto(proc, 0x63);
        return;
    }
    UiCtx_BeginMoveSelect(gUiContext, count >= 0xC ? NULL : proc->entries[idx]);
    if (proc->count >= 0xC) kind = 0;
    else kind = proc->kinds[idx];
    switch (kind) {
    case 1: fn_8002629C(gUiContext, proc); break;
    case 2: fn_800264BC(gUiContext, proc); break;
    }
}

extern u8 lbl_8028D064[16];
void fn_800AD64C(s32 arg0) {
    void Process_CreateChild(void *, s32);
    extern u8 lbl_8028D064[16];
    Process_CreateChild(lbl_8028D064, arg0);
}

#pragma optimization_level reset
void fn_800AD678(void) {
    void fn_801A4BE0(void *);
    extern u8 gBattle[];
    *(s32 *)(gBattle + 0xCAC) |= 1;
    fn_801A4BE0(gBattle);
}

void fn_800AD6AC(void *arg0) {
    void Process_Goto(void *, s32);
    void fn_80034A8C(void *, void *, u8, void *, s32);
    extern u16 gBattle[];
    void *temp_r4;
    void *temp_r5;

    temp_r4 = *(void **)((u8 *)arg0 + 0x30);
    temp_r5 = *(void **)((u8 *)temp_r4 + 0x190);
    if (*(u8 *)((u8 *)temp_r5 + 8) != 0) {
        Process_Goto(arg0, 0x64);
        return;
    }
    fn_80034A8C(gBattle, temp_r4, *(u8 *)((u8 *)arg0 + 0x3A), arg0, 1);
}

void fn_800AD700(void *arg0) {
    void fn_8014CBD8(void *, f32, f32);
    extern u8 gBattleState[];
    struct {
        u8 pad[0x19E];
        s8 x;
        s8 y;
    } *u;

    u = *(void **)((u8 *)arg0 + 0x30);
    fn_8014CBD8(gBattleState, (f32)u->y, (f32)u->x);
}

void fn_800AD76C(void *arg0) {
    void fn_801A4BE0(void *);
    void *TargetList_GetCurrent(void *);
    void *UnitRef_GetUnit(void);
    void Battle_SetupPair(void *, void *, void *);
    void fn_80036248(void *);
    extern u8 gBattle[];
    extern u8 gTargetList[];
    void *p;
    void *unit;
    void *f740;
    u8 lim;

    fn_801A4BE0(gBattle);
    if ((s8)gBattle[0x1A8] == 0) {
        p = *(void **)(gBattle + 0x190);
        if (*(u8 *)((u8 *)p + 8) == 1) {
            unit = *(void **)((u8 *)arg0 + 0x30);
            *(u16 *)((u8 *)unit + 0x22A) = *(u16 *)((u8 *)unit + 0x22A) + 1;
            unit = *(void **)((u8 *)arg0 + 0x30);
            *(u16 *)((u8 *)unit + 0x22C) = *(u16 *)((u8 *)unit + 0x22C) + 1;
        }
    }
    TargetList_GetCurrent(gTargetList);
    f740 = UnitRef_GetUnit();
    unit = *(void **)((u8 *)arg0 + 0x30);
    Battle_SetupPair(gBattle, unit, f740);
    if (*(u8 *)((u8 *)arg0 + 0x3B) != 0) {
        gBattle[0x2D6] = 1;
    }
    fn_80036248(gBattle);
    lim = gBattle[0x2C9];
    if (*(u8 *)((u8 *)arg0 + 0x3A) < lim) {
        *(u8 *)((u8 *)arg0 + 0x3A) = lim;
    }
}

void fn_800AD84C(void *arg0) {
void *TargetList_GetCurrent(void *);
void *UnitRef_GetUnit(void);
void fn_801A7218(void *, void *, s32);
void Battle_QueueDeathAnim(void *);
s8 Unit_GetMaxHp(void *);
void fn_801A4A88(void *, s8);
void fn_8019B704(void *, s32);
extern u8 gTargetList[];
extern u8 gBattle[];
void *p;
void *eac;
s32 diff;
s32 neg;
void *f740;
u8 div;
p=TargetList_GetCurrent(gTargetList);
f740=UnitRef_GetUnit();
fn_801A7218(gBattle,f740,-1);
Battle_QueueDeathAnim(gBattle);
div=*((u8*)p+3);
eac=gBattle;
diff=*(s16*)((u8*)arg0+0x34)-*(s16*)((u8*)eac+0x29A);
diff/=div;
if(diff>Unit_GetMaxHp(eac)) diff=Unit_GetMaxHp(eac);
if(diff<1) diff=1;
neg=-diff;
*((u8*)arg0+0x3B)=(u32)(neg|diff)>>31;
fn_801A4A88(gBattle,(s8)neg);
fn_8019B704(arg0,0);
}

void fn_800AD92C(s32 arg0) {
    void Process_Goto(s32, s32);
    void *TargetList_GetCurrent(void *);
    void *UnitRef_GetUnit(void);
    void fn_8014CBD8(void *, f32, f32);
    extern u8 gTargetList[];
    extern u8 gBattleState[];
    void *temp_r3;

    if (TargetList_GetCurrent(gTargetList) == NULL) {
        Process_Goto(arg0, 0x63);
        return;
    }
    temp_r3 = UnitRef_GetUnit();
    fn_8014CBD8(gBattleState, (f32)*(s8 *)((u8 *)temp_r3 + 0x19E), (f32)*(s8 *)((u8 *)temp_r3 + 0x19F));
}

void fn_800AD9C8(u8 *self) {
void fn_80029858(u8, u8);
void fn_80199CC0(void *);
extern u8 gUiContext[];
extern u8 gBattle[];
void *p;
fn_80029858(gUiContext[0xF], gUiContext[0x10]);
*(void **)(self + 0x30) = *(void **)(gBattle + 0x280);
*(s16 *)(self + 0x34) = *(s16 *)(gBattle + 0x298);
*(s16 *)(self + 0x36) = *(s16 *)(gBattle + 0x29E);
*(s16 *)(self + 0x38) = *(s16 *)(gBattle + 0x2A4);
self[0x3A] = 0;
p = *(void **)(self + 0x30);
++*(u16 *)((u8 *)p + 0x228);
fn_80199CC0(self);
}

s32 fn_800ADB74(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp0, temp1, temp2, temp3;
    s32 var_r3, var_r4;
    
    if (arg0 < 0) {
        temp0 = (arg0 + 0x1F) >> 5;
    } else {
        temp0 = arg0 >> 5;
    }

    if (arg1 < 0) {
        temp1 = (arg1 + 0x1F) >> 5;
    } else {
        temp1 = arg1 >> 5;
    }
    
    if (arg2 < 0) {
        temp2 = (arg2 + 0x1F) >> 5;
    } else {
        temp2 = arg2 >> 5;
    }

    if (arg3 < 0) {
        temp3 = (arg3 + 0x1F) >> 5;
    } else {
        temp3 = arg3 >> 5;
    }
    
    var_r4 = temp1 * 0x32E100;
    var_r3 = temp0 * 0x7D8600;
    var_r3 += var_r4;
    var_r4 = temp2 * 0x19400;
    var_r3 += var_r4;
    var_r4 = temp3 * 0x564;
    var_r3 += var_r4;
    
    return var_r3 + 0x800000;
}

void fn_800ADD04(void);
void fn_800ADC9C(s32 arg0) {
    extern u8 gTargetList[];
    extern u8 gBattle[];
    void *TargetList_GetCurrent(void *);
    u8 *UnitRef_GetUnit(void);
    M2C_UNK fn_8019B6B4(s32, void (*)(void));
    M2C_UNK Battle_QueueDeathAnim(void *);
    M2C_UNK Battle_SetupUnit(void *, u8 *, s32);
    u8 *p;

    TargetList_GetCurrent(gTargetList);
    p = UnitRef_GetUnit();
    Battle_SetupUnit(gBattle, p, -1);
    Battle_QueueDeathAnim(gBattle);
    fn_8019B6B4(arg0, fn_800ADD04);
}

void fn_800ADD04(void) {
    extern u8 gTargetList[];
    void *TargetList_GetCurrent(void *);
    u8 *UnitRef_GetUnit(void);
    M2C_UNK fn_8010455C(void *, u8);
    void *p;

    p = TargetList_GetCurrent(gTargetList);
    fn_8010455C(UnitRef_GetUnit() + 0x1A4, M2C_FIELD(p, u8 *, 3));
}

extern u8 gTargetList[];
extern void fn_8002F61C(void *);
extern void *TargetList_GetCurrent(void *);
extern u8 *UnitRef_GetUnit(void);
extern void Unit_OnZeroHp(void);
void fn_800ADD48(void) {
    TargetList_GetCurrent(gTargetList);
    UnitRef_GetUnit();
    Unit_OnZeroHp();
    fn_8002F61C(gTargetList);
}

void fn_800ADD84(void) {
    M2C_UNK fn_80033418(void *);
    M2C_UNK fn_801A4BE0(void *);
    extern u8 gBattle[];

    fn_801A4BE0(gBattle);
    fn_80033418(gBattle + 0x8A0);
}

/* Init gBattle from the current target entry's unit, apply optional HP delta, and open MapSelect. */
void Battle_SetupTargetSelect(s32 parent) {
    void *TargetList_GetCurrent(void *);
    u8 *UnitRef_GetUnit(void);
    void fn_8019B79C(s32, s32);
    void fn_8019B83C(s32, s32);
    void fn_8019B8A0(s32, s32);
    void Battle_QueueDeathAnim(void *);
    void fn_801A4A88(void *, s8);
    void Battle_SetupUnit(void *, u8 *, s32);
    extern u8 gTargetList[];
    extern u8 gBattle[];
    void *entry;
    u8 *unit;
    s8 hpDelta;

    entry = TargetList_GetCurrent(gTargetList);
    unit = UnitRef_GetUnit();
    Battle_SetupUnit(gBattle, unit, -1);
    Battle_QueueDeathAnim(gBattle);
    hpDelta = *(s8 *)((u8 *)entry + 1);
    if (hpDelta != 0) {
        fn_801A4A88(gBattle, hpDelta);
    }
    if (!(*(s32 *)((u8 *)unit + 0x1A0) & 0x010000DC)) {
        switch (*(s8 *)((u8 *)entry + 0)) {
        case 0:
            fn_8019B8A0(parent, 0);
            break;
        case 1:
            fn_8019B83C(parent, 0);
            break;
        case 2:
            fn_8019B79C(parent, 0);
            break;
        }
    }
}

s32 fn_800ADEB0(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 < 0) {
        return -1;
    }
    if (arg0 >= 0x100) {
        return -2;
    }
    if (arg1 < 0) {
        return -3;
    }
    if (arg1 >= 0x100) {
        return -4;
    }
    if (arg2 < 0) {
        return -5;
    }
    if (arg2 >= 0x100) {
        return -6;
    }

    return arg0 + ((arg1 & 0xFF) << 8) + ((arg2 & 0xFF) << 16);
}

extern void fn_8003BE50(void);
void fn_800AE1FC(void) {
    TargetList_GetCurrent(&gTargetList);
    UnitRef_GetUnit();
    fn_8003BE50();
    fn_8002F61C(&gTargetList);
}

void fn_800AE238(s32 arg0) {
    void *TargetList_GetCurrent(void *);
    void *UnitRef_GetUnit(void);
    void fn_80183BE4(void *, s32);
    extern u8 gTargetList[];

    TargetList_GetCurrent(gTargetList);
    fn_80183BE4(UnitRef_GetUnit(), arg0);
}

void fn_800AE278(s32 arg0) {
    void Process_Goto(s32, s32);
    void *TargetList_GetCurrent(void *);
    void *UnitRef_GetUnit(void);
    void fn_8014CBD8(void *, f32, f32);
    extern u8 gTargetList[];
    extern u8 gBattleState[];
    void *temp_r3;

    if (TargetList_GetCurrent(gTargetList) == NULL) {
        Process_Goto(arg0, 0x63);
        return;
    }
    temp_r3 = UnitRef_GetUnit();
    if ((*(u32 *)((u8 *)temp_r3 + 0x1A0) & 0x010000DC) == 0) {
        fn_8014CBD8(gBattleState, (f32)*(s8 *)((u8 *)temp_r3 + 0x19E), (f32)*(s8 *)((u8 *)temp_r3 + 0x19F));
    }
}

s32 fn_800AE328(s32 arg0) {
    void fn_8003DDF8(void *, u8 *, u8 *);
    void Unit_SeparateRescue(void *, u8, u8);
    void fn_80183C6C(void *, s8, s8, s8, s8, s32);
    void *Battle_GetActiveCombatant(void *);
    extern u8 gBattle[];
    u8 sp9;
    u8 sp8;
    void *temp_r31;
    void *temp_r3;
    void *temp_r3_2;
    s8 a;
    s8 b;
    s8 c;
    s8 d;

    temp_r3 = Battle_GetActiveCombatant(gBattle);
    if (temp_r3 == NULL) {
        return 0;
    }
    if (!(*(s32 *)((u8 *)temp_r3 + 0x1A0) & 2)) {
        return 0;
    }
    temp_r31 = *(void **)((u8 *)temp_r3 + 0x280);
    fn_8003DDF8(temp_r31, &sp9, &sp8);
    temp_r3_2 = *(void **)((u8 *)temp_r31 + 0x194);
    a = (s8)sp9;
    b = (s8)*(u8 *)((u8 *)temp_r3_2 + 0x19E);
    c = (s8)*(u8 *)((u8 *)temp_r3_2 + 0x19F);
    d = (s8)sp8;
    fn_80183C6C(temp_r3_2, b, c, a, d, arg0);
    Unit_SeparateRescue(temp_r31, sp9, sp8);
    return 1;
}

void fn_800AE3DC(s32 arg0) {
    void Process_CreateChild(void *, s32);
    extern u8 gBattleState[];
    extern u8 gUnitLists[];
    extern u8 lbl_8028D138[];
    u8 *entry;

    entry = *(u8 **)(gUnitLists + gBattleState[0x11] * 0xC);
    while (entry != 0) {
        u32 flags = *(u32 *)(entry + 0x1A0);
        entry = *(u8 **)(entry + 0x184);
        if (!(flags & 4))
            goto do_call;
    }
    return;
do_call:
    Process_CreateChild(lbl_8028D138, arg0);
}

void fn_800AE444(void *arg0) {
    f32 Math_Lerp(f32, f32, f32, f32);
    f32 Math_EaseOutPow(M2C_UNK, f32, f32, f32, f32);
    extern f32 lbl_80369C78;
    extern f32 gPhaseBannerZero;
    extern f32 lbl_80369C80;
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) - 1);
    M2C_FIELD(arg0, f32 *, 0x38) = Math_EaseOutPow(2, lbl_80369C78, gPhaseBannerZero, (f32) M2C_FIELD(arg0, s32 *, 0x44), (f32) M2C_FIELD(arg0, s32 *, 0x30));
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) Math_Lerp(gPhaseBannerZero, lbl_80369C80, (f32) M2C_FIELD(arg0, s32 *, 0x44), (f32) M2C_FIELD(arg0, s32 *, 0x30));
    if ((s32) M2C_FIELD(arg0, s32 *, 0x30) <= 0) {
        Process_ClearFunc(arg0);
    }
}

void fn_800AE52C(void *arg0)
{
    extern u8 *gPadInput;

    extern void Process_ClearFunc(void *);
    extern void fn_800535B0(void *);

    u8 *obj;
    u8 *input;
    u32 previous;
    u32 current;

    obj = (u8 *)arg0;

    *(s32 *)(obj + 0x48) -= 1;

    if (*(s32 *)(obj + 0x48) == 0) {
        Process_ClearFunc(obj);
    } else {
        input = gPadInput;

        previous = *(u32 *)(input + 0x4);
        current = *(u32 *)(input + 0x8);

        if ((previous & (current ^ previous)) & 0x100) {
            if (*(void **)(obj + 0x4C) != 0) {
                fn_800535B0(*(void **)(obj + 0x4C));
            }

            Process_ClearFunc(obj);
        }
    }
}

void fn_800AE5A8(void *arg0) {
    f32 Math_Lerp(f32, f32, f32, f32);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern f64 lbl_80369C88;
    extern f32 gPhaseBannerZero;
    extern f32 lbl_80369C80;
    extern f32 lbl_80369C90;
    void *self;

    self = arg0;
    *(s32 *)((u8 *)self + 0x30) = *(s32 *)((u8 *)self + 0x30) + 1;
    *(f32 *)((u8 *)self + 0x38) = Math_EaseOutPow(2, lbl_80369C90, gPhaseBannerZero, (f32)*(s32 *)((u8 *)self + 0x44), (f32)*(s32 *)((u8 *)self + 0x30));
    *(s32 *)((u8 *)self + 0x34) = (s32)Math_Lerp(gPhaseBannerZero, lbl_80369C80, (f32)*(s32 *)((u8 *)self + 0x44), (f32)*(s32 *)((u8 *)self + 0x30));
    if (*(s32 *)((u8 *)self + 0x30) >= *(s32 *)((u8 *)self + 0x44)) {
        Process_ClearFunc(self);
    }
}

/* Set up the phase-change banner: ambient FX for this army, banner widget, and draw callback. */
void Battle_InitPhaseBanner(void *proc) {
    void *fn_8014D8FC(void *);
    s8 Fx_FindSlotByName(void *);
    void Fx_StartSlot(s32, void *, s32, s32);
    void *Effect_Create(void *, void *);
    void fn_80053658(void *, s32, void *);
    void Process_AttachFunc(void *, void *);
    extern u8 gBattleState[];
    extern u8 lbl_8026EAA0[];
    extern u8 gFxChannels[];
    extern f32 gPhaseBannerZero;

    void *chapter;
    void *fxName;
    void *bannerName;
    u8 chapterId;
    u8 slot;
    s32 remaining;
    f32 f0;

    chapter = fn_8014D8FC(gBattleState);
    *(s32 *)((u8 *)proc + 0x30) = 0;
    *(s32 *)((u8 *)proc + 0x34) = 0;
    *(f32 *)((u8 *)proc + 0x38) = 0.0f;
    *(f32 *)((u8 *)proc + 0x3C) = 0.0f;
    *(s32 *)((u8 *)proc + 0x44) = 0xF;
    *(s32 *)((u8 *)proc + 0x48) = 0x1E;
    fxName = NULL;
    if ((s8)Fx_FindSlotByName(lbl_8026EAA0 + 0x2B) == -1) {
        switch (gBattleState[0x11]) {
        case 0:
            chapterId = *((u8 *)chapter + 0x3C);
            if ((s32)chapterId <= 0x12 || (s32)chapterId >= 0x32) {
                fxName = lbl_8026EAA0 + 0x38;
            } else {
                fxName = lbl_8026EAA0 + 0x46;
            }
            break;
        case 1:
            chapterId = *((u8 *)chapter + 0x3C);
            if ((s32)chapterId <= 0x12 || (s32)chapterId >= 0x32) {
                fxName = lbl_8026EAA0 + 0x54;
            } else {
                fxName = lbl_8026EAA0 + 0x62;
            }
            break;
        case 2:
            fxName = lbl_8026EAA0 + 0x70;
            break;
        case 3:
            fxName = lbl_8026EAA0 + 0x80;
            break;
        }
        if (fxName != NULL) {
            for (slot = 1, remaining = 3; remaining != 0; remaining--, slot++) {
                if (!(gFxChannels[slot * 0x30 + 0xC] & 1)) {
                    Fx_StartSlot(slot, fxName, 0x64, 1);
                    break;
                }
            }
        }
    }
    switch (gBattleState[0x11]) {
    case 0:
        bannerName = lbl_8026EAA0 + 0x90;
        break;
    case 1:
        bannerName = lbl_8026EAA0 + 0xA0;
        break;
    case 2:
        bannerName = lbl_8026EAA0 + 0xAF;
        break;
    case 3:
        bannerName = lbl_8026EAA0 + 0xBE;
        break;
    default:
        bannerName = NULL;
        break;
    }
    *(void **)((u8 *)proc + 0x4C) = Effect_Create(bannerName, proc);
    *(f32 *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)proc + 0x4C) + 0x30) + 0x1C) = 0.0f;
    *(s16 *)*(void **)((u8 *)*(void **)((u8 *)proc + 0x4C) + 0x30) = 0x63;
    fn_80053658(*(void **)((u8 *)proc + 0x4C), 0, proc);
    *(void **)((u8 *)*(void **)((u8 *)*(void **)((u8 *)proc + 0x4C) + 0x30) + 0x44) = Battle_ClearPhaseBannerChild;
    Process_AttachFunc(Battle_DrawPhaseBanner, proc);
}

void Battle_ClearPhaseBannerChild(void *arg0) {
    M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), void **, 0x4C), s32 *, 0x4C) = 0;
}

void fn_800AE918(s32 arg0) {
    u8 GActor_CheckResources(void *);
    void Process_ClearFunc(s32);
    extern u8 gBattleState[];
    extern u8 lbl_8026EAA0[];
    void *var_r3;

    switch (gBattleState[0x11]) {
    case 0:
        var_r3 = lbl_8026EAA0 + 0x90;
        break;
    case 1:
        var_r3 = lbl_8026EAA0 + 0xA0;
        break;
    case 2:
        var_r3 = lbl_8026EAA0 + 0xAF;
        break;
    case 3:
        var_r3 = lbl_8026EAA0 + 0xBE;
        break;
    default:
        var_r3 = NULL;
        break;
    }
    if (GActor_CheckResources(var_r3) != 0) {
        Process_ClearFunc(arg0);
    }
}

void fn_800AE9CC(void) {
    void fn_8002DEB4(s32);
    void fn_800288E4(void);
    void fn_800555EC(void *, s32);
    extern u8 gBattleState[];
    extern u8 lbl_8026EAA0[];
    void *var_r3;

    fn_8002DEB4(0xFA);
    fn_800288E4();
    switch (gBattleState[0x11]) {
    case 0:
        var_r3 = lbl_8026EAA0 + 0x90;
        break;
    case 1:
        var_r3 = lbl_8026EAA0 + 0xA0;
        break;
    case 2:
        var_r3 = lbl_8026EAA0 + 0xAF;
        break;
    case 3:
        var_r3 = lbl_8026EAA0 + 0xBE;
        break;
    default:
        var_r3 = NULL;
        break;
    }
    fn_800555EC(var_r3, 0);
}

/* Draw the player/enemy phase banner as two full-width gradient bars. */
void Battle_DrawPhaseBanner(void *proc) {
    void Prim2D_SetCornerColors(s32 *, s32 *, s32 *, s32 *);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_ResetState(void);
    void Prim2D_SetColorByte(u8);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    extern s32 gPhaseBannerBlack0;
    extern s32 gPhaseBannerBlack1;
    extern s32 gPhaseBannerBlack2;
    extern s32 gPhaseBannerBlack3;
    extern f32 gPhaseBannerZero;
    extern f32 gPhaseBannerPrimParam;
    extern f32 gPhaseBannerTopY;
    extern f32 gPhaseBannerWidth;
    extern f32 gPhaseBannerBarH;
    extern f32 gPhaseBannerBottomY;
    extern s32 gPhaseBannerTopColor0;
    extern s32 gPhaseBannerTopColor1;
    extern s32 gPhaseBannerBottomColor0;
    extern s32 gPhaseBannerBottomColor1;
    s32 topC0;
    s32 topC1;
    s32 topBlack0;
    s32 topBlack1;
    s32 botBlack0;
    s32 botBlack1;
    s32 botC0;
    s32 botC1;
    s32 alpha;

    alpha = *(s32 *)((u8 *)proc + 0x34);
    Prim2D_Begin();
    {
        f32 z = gPhaseBannerZero;
        f32 o = 1.0f;
        Prim2D_SetTransform(z, z, o, o);
    }
    Prim2D_SetTex(0, 0x12);
    Prim2D_SetColorByte((u8)alpha);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(3);
    Prim2D_SetPrimParam(gPhaseBannerPrimParam);
    Prim2D_SetRect(gPhaseBannerZero, gPhaseBannerTopY, gPhaseBannerWidth, gPhaseBannerBarH);
    Prim2D_EmitQuad();
    topBlack1 = gPhaseBannerBlack1;
    topBlack0 = gPhaseBannerBlack0;
    topC1 = gPhaseBannerTopColor1;
    topC0 = gPhaseBannerTopColor0;
    Prim2D_SetCornerColors(&topC0, &topC1, &topBlack0, &topBlack1);
    Prim2D_EndPrim();
    Prim2D_AddPrim(3);
    Prim2D_SetPrimParam(gPhaseBannerPrimParam);
    Prim2D_SetRect(gPhaseBannerZero, gPhaseBannerBottomY, gPhaseBannerWidth, gPhaseBannerBarH);
    Prim2D_EmitQuad();
    botC1 = gPhaseBannerBottomColor1;
    botC0 = gPhaseBannerBottomColor0;
    botBlack1 = gPhaseBannerBlack3;
    botBlack0 = gPhaseBannerBlack2;
    Prim2D_SetCornerColors(&botBlack0, &botBlack1, &botC0, &botC1);
    Prim2D_EndPrim();
    Prim2D_ResetState();
}

#pragma use_lmw_stmw on
void fn_800AECC0(void) {
    void fn_800B1720(void *);
    void fn_800B16EC(void *);
    void fn_800B49E0(void *,s32,s32,s32,void *);
    void DCInvalidateRange(void *,u32);
    void ARQPostRequest(void *,void *,s32,s32,u32,void *,u32,void *);
    extern u8 gSoundSys[];
    s32 i;
    u8 *entry;
    u8 *stream;
    u32 size, aligned;
    s32 position;
    u32 base, offset, limit, n, step;
    u16 flags;
    i = 0;
    position = 0;
    do {
        entry = *(u8 **)((u8 *)gSoundSys + 0xF8) + position;
        flags = *(u16 *)entry;
        if ((flags & 8) && !(flags & 2)) {
            if (flags & 1) {
                if (*(u32 *)(entry+0x70) != 0 && *(s16 *)(entry+0x80)==0 && !(flags&0x1000)) {
        stream = entry + 0x2C;
        offset = *(u32 *)(entry + 0x60);
        limit = *(u32 *)(entry + 0x8C);
        size = SoundReadSizeB(offset,limit);
        aligned = (size + 0x1F) & ~0x1F;
        if (!(flags & 0x400)) {
            fn_800B49E0(*(void **)stream, *(s32 *)(stream + (1 - *(u16 *)(stream + 0x4C))*4 + 0x2C), aligned, *(u16 *)(entry + 4) + offset, fn_800B1720);
        } else {
            base = *(u32 *)((u8 *)gSoundSys + *(u16 *)(entry + 2)*4 + 0x134) + offset + *(u16 *)(entry + 4);
            DCInvalidateRange(*(void **)(stream + (1 - *(u16 *)(stream + 0x4C))*4 + 0x2C), 0x8000);
            ARQPostRequest(stream + 4, stream, 1, 0, base, *(void **)(stream + (1 - *(u16 *)(stream + 0x4C))*4 + 0x2C), aligned, fn_800B16EC);
        }
        *(u32 *)(stream + 0x48) = size;

                    *(u16 *)entry |= 0x1000;
                    if (*(u16 *)entry & 0x400) *(u16 *)(entry+0x80)=1;
                }
                if (*(u16 *)(entry+0x1E)==2 && *(u32 *)(entry+0xF8)!=0 && *(s16 *)(entry+0x108)==0) {
                    flags = *(u16 *)entry;
                    if (!(flags&0x2000)) {
            stream = entry + 0xB4;
            offset = *(u32 *)(entry + 0xE8);
            limit = *(u32 *)(entry + 0x114);
            base = limit + (32 - (limit & 31));
            size = SoundReadSizeB(offset,limit);
            aligned = (size + 0x1F) & ~0x1F;
            if (!(flags & 0x400)) {
                fn_800B49E0(*(void **)stream, *(s32 *)(stream + (1 - *(u16 *)(stream + 0x4C))*4 + 0x2C), aligned, *(u16 *)(entry + 4) + (offset + base), fn_800B1720);
            } else {
                base = offset + base + *(u32 *)((u8 *)gSoundSys + *(u16 *)(entry + 2)*4 + 0x134) + *(u16 *)(entry + 4);
                DCInvalidateRange(*(void **)(stream + (1 - *(u16 *)(stream + 0x4C))*4 + 0x2C), 0x8000);
                ARQPostRequest(stream + 4, stream, 1, 0, base, *(void **)(stream + (1 - *(u16 *)(stream + 0x4C))*4 + 0x2C), aligned, fn_800B16EC);
            }
            *(u32 *)(stream + 0x48) = size;

                        *(u16 *)entry |= 0x2000;
                        if (*(u16 *)entry & 0x400) *(u16 *)(entry+0x108)=1;
                    }
                }
            }
            if (*(u16 *)(entry+0x1E)==2 && *(s16 *)(entry+0x80)==0 && *(s16 *)(entry+0x108)==0) {
                u16 state = *(u16 *)(entry+0x78);
                if (state != *(u16 *)(entry+0x100)) {
                    *(u16 *)(entry+0x100)=state;
                    *(u32 *)(entry+0xF8)=*(u32 *)(entry+0x70);
                    *(u32 *)(entry+0xEC)=*(u32 *)(entry+0x64);
                    *(u32 *)(entry+0xE8)=*(u32 *)(entry+0x60);
                }
            }
        }
        i++;
        position += 0x13C;
    } while (i<3);
}

#pragma use_lmw_stmw on
void fn_800AF0B4(void) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void fn_800B49D0(void *);
    void fn_8024CE60(void *, s32, u8, u8, s32);
    void fn_8024DA2C(void *);
    extern u8 gSoundSys[];
    extern f32 lbl_80369CB0;
    extern f32 lbl_80369CB4;
    s32 off;
    u8 *e;
    s32 i;
    u8 *e2;
    s32 off2;
    u8 *sys;
    u16 flags;
    u16 flags2;
    u16 nest;
    u8 vol;
    f32 f;
    f32 f31;
    f32 cur;
    f32 tgt;

    off = 0;
    off2 = off;
    i = 0;
    sys = gSoundSys;
    do {
        e = *(u8 **)(sys + 0xF8) + off2;
        flags = *(u16 *)e;
        if ((flags & 8) && !(flags & 2)) {
            if (flags & 4) {
                *(u16 *)e = (u16)(flags & ~4);
                e2 = *(u8 **)(sys + 0xF8) + off;
                flags2 = *(u16 *)e2;
                if (flags2 != 0) {
                    if (!(flags2 & 8)) {
                        *(u16 *)e2 = (u16)(flags2 | 4);
                    } else {
                        if (flags2 & 0x400) {
                            *(u16 *)(gSoundSys + (*(u16 *)(e2 + 2) << 1) + 0x13E) = 0;
                        }
                        *(u16 *)e2 = 0;
                        if (*(u16 *)(sys + 0x124) == 0) {
                            *(s32 *)(sys + 0x128) = OSDisableInterrupts();
                        }
                        *(u16 *)(sys + 0x124) = (u16)(*(u16 *)(sys + 0x124) + 1);
                        fn_800B49D0(*(void **)(e2 + 0x2C));
                        fn_800B49D0(*(void **)(e2 + 0xB4));
                        fn_8024DA2C(*(void **)(e2 + 0x50));
                        if (*(u16 *)(e2 + 0x1E) == 2) {
                            fn_8024DA2C(*(void **)(e2 + 0xD8));
                        }
                        nest = *(u16 *)(sys + 0x124);
                        if (nest != 0) {
                            nest -= 1;
                            *(u16 *)(sys + 0x124) = nest;
                            if ((u16)nest == 0) {
                                OSRestoreInterrupts(*(s32 *)(sys + 0x128));
                            }
                        }
                        *(s32 *)(sys + 0xFC) = -1;
                    }
                }
            } else if (flags & 0x40) {
                cur = *(f32 *)(e + 0x10);
                tgt = *(f32 *)(e + 0x14);
                if (cur == tgt) {
                    if (lbl_80369CB0 == cur) {
                        *(u16 *)e = (u16)(flags | 2);
                    }
                    *(u16 *)e = (u16)(*(u16 *)e & ~0x40);
                } else {
                    *(f32 *)(e + 0x10) = cur - *(f32 *)(e + 0x18);
                    if (*(f32 *)(e + 0x10) <= *(f32 *)(e + 0x14)) {
                        *(f32 *)(e + 0x10) = *(f32 *)(e + 0x14);
                    }
                    vol = (u8)*(u16 *)(e + 6);
                    e2 = *(u8 **)(sys + 0xF8) + off;
                    if (*(u16 *)e2 != 0) {
                        *(u16 *)(e2 + 6) = vol;
                        if (*(u16 *)e2 & 8) {
                            if (*(u16 *)(e2 + 0x1E) == 1) {
                                fn_8024CE60(*(void **)(e2 + 0x50), (s32)*(f32 *)(e2 + 0x10), vol, (u8)*(u16 *)(e2 + 8), 0);
                            } else {
                                f = *(f32 *)(e2 + 0x10);
                                f31 = f;
                                if (vol < 0x40) {
                                    f31 = ((f32)vol * f) / lbl_80369CB4;
                                }
                                if ((u32)(vol - 0x40) >> 31 == 0) {
                                    f = ((f32)(s32)(0x7F - vol) * f) / lbl_80369CB4;
                                }
                                fn_8024CE60(*(void **)(e2 + 0x50), (s32)f, 0, (u8)*(u16 *)(e2 + 8), 0);
                                fn_8024CE60(*(void **)(e2 + 0xD8), (s32)f31, 0x7F, (u8)*(u16 *)(e2 + 8), 0);
                            }
                        }
                    }
                    goto check20;
                }
            } else {
            check20:
                flags = *(u16 *)e;
                if (flags & 0x20) {
                    tgt = lbl_80369CB0;
                    cur = *(f32 *)(e + 0x10);
                    if (tgt == cur) {
                        *(u16 *)e = (u16)(flags & ~0x20);
                        e2 = *(u8 **)(sys + 0xF8) + off;
                        flags2 = *(u16 *)e2;
                        if (flags2 != 0) {
                            if (!(flags2 & 8)) {
                                *(u16 *)e2 = (u16)(flags2 | 4);
                            } else {
                                if (flags2 & 0x400) {
                                    *(u16 *)(gSoundSys + (*(u16 *)(e2 + 2) << 1) + 0x13E) = 0;
                                }
                                *(u16 *)e2 = 0;
                                if (*(u16 *)(sys + 0x124) == 0) {
                                    *(s32 *)(sys + 0x128) = OSDisableInterrupts();
                                }
                                *(u16 *)(sys + 0x124) = (u16)(*(u16 *)(sys + 0x124) + 1);
                                fn_800B49D0(*(void **)(e2 + 0x2C));
                                fn_800B49D0(*(void **)(e2 + 0xB4));
                                fn_8024DA2C(*(void **)(e2 + 0x50));
                                if (*(u16 *)(e2 + 0x1E) == 2) {
                                    fn_8024DA2C(*(void **)(e2 + 0xD8));
                                }
                                nest = *(u16 *)(sys + 0x124);
                                if (nest != 0) {
                                    nest -= 1;
                                    *(u16 *)(sys + 0x124) = nest;
                                    if ((u16)nest == 0) {
                                        OSRestoreInterrupts(*(s32 *)(sys + 0x128));
                                    }
                                }
                                *(s32 *)(sys + 0xFC) = -1;
                            }
                        }
                    } else {
                        *(f32 *)(e + 0x10) = cur - *(f32 *)(e + 0x18);
                        if (*(f32 *)(e + 0x10) <= tgt) {
                            *(f32 *)(e + 0x10) = tgt;
                        }
                        vol = (u8)*(u16 *)(e + 6);
                        e2 = *(u8 **)(sys + 0xF8) + off;
                        if (*(u16 *)e2 != 0) {
                            *(u16 *)(e2 + 6) = vol;
                            if (*(u16 *)e2 & 8) {
                                if (*(u16 *)(e2 + 0x1E) == 1) {
                                    fn_8024CE60(*(void **)(e2 + 0x50), (s32)*(f32 *)(e2 + 0x10), vol, (u8)*(u16 *)(e2 + 8), 0);
                                } else {
                                    f = *(f32 *)(e2 + 0x10);
                                    f31 = f;
                                    if (vol < 0x40) {
                                        f31 = ((f32)vol * f) / lbl_80369CB4;
                                    }
                                    if ((u32)(vol - 0x40) >> 31 == 0) {
                                        f = ((f32)(s32)(0x7F - vol) * f) / lbl_80369CB4;
                                    }
                                    fn_8024CE60(*(void **)(e2 + 0x50), (s32)f, 0, (u8)*(u16 *)(e2 + 8), 0);
                                    fn_8024CE60(*(void **)(e2 + 0xD8), (s32)f31, 0x7F, (u8)*(u16 *)(e2 + 8), 0);
                                }
                            }
                        }
                        goto check10;
                    }
                } else {
                check10:
                    if (*(u16 *)e & 0x10) {
                        *(f32 *)(e + 0x10) = *(f32 *)(e + 0x10) + *(f32 *)(e + 0x18);
                        tgt = *(f32 *)(e + 0xC);
                        if (*(f32 *)(e + 0x10) >= tgt) {
                            *(f32 *)(e + 0x10) = tgt;
                            *(f32 *)(e + 0x18) = lbl_80369CB0;
                            *(u16 *)e = (u16)(*(u16 *)e & ~0x10);
                        }
                        vol = (u8)*(u16 *)(e + 6);
                        e2 = *(u8 **)(sys + 0xF8) + off;
                        if (*(u16 *)e2 != 0) {
                            *(u16 *)(e2 + 6) = vol;
                            if (*(u16 *)e2 & 8) {
                                if (*(u16 *)(e2 + 0x1E) == 1) {
                                    fn_8024CE60(*(void **)(e2 + 0x50), (s32)*(f32 *)(e2 + 0x10), vol, (u8)*(u16 *)(e2 + 8), 0);
                                } else {
                                    f = *(f32 *)(e2 + 0x10);
                                    f31 = f;
                                    if (vol < 0x40) {
                                        f31 = ((f32)vol * f) / lbl_80369CB4;
                                    }
                                    if ((u32)(vol - 0x40) >> 31 == 0) {
                                        f = ((f32)(s32)(0x7F - vol) * f) / lbl_80369CB4;
                                    }
                                    fn_8024CE60(*(void **)(e2 + 0x50), (s32)f, 0, (u8)*(u16 *)(e2 + 8), 0);
                                    fn_8024CE60(*(void **)(e2 + 0xD8), (s32)f31, 0x7F, (u8)*(u16 *)(e2 + 8), 0);
                                }
                            }
                        }
                    }
                }
            }
        }
        i += 1;
        off += 0x13C;
        off2 += 0x13C;
    } while (i < 3);
}
void fn_800B16EC(void *arg0) {
    M2C_UNK fn_800B1720(M2C_UNK, s32);
    fn_800B1720(0, *M2C_FIELD(arg0, s32 **, 4) + 0x40);
}

#pragma use_lmw_stmw on
void fn_800B1720(s32 arg0, u8 *arg1)
{
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void fn_8024CE60(void *, s32, u8, u8, s32);
    void fn_8024E100(void *);
    extern u8 gSoundSys[];
    extern f32 lbl_80369CB4;
    u8 *base;
    u8 *base2;
    s32 i;
    u8 *entry;
    u8 *sub;
    s32 which;
    u32 flags;
    u8 vol;
    u8 *entry2;
    f32 f;
    f32 f31;
    s32 j;
    s32 off;
    s32 ctr;
    u8 *e2;
    u32 nest;
    s32 z;

    base = gSoundSys;
    if (*(u16 *)(base + 0x124) == 0) {
        *(s32 *)(gSoundSys + 0x128) = OSDisableInterrupts();
    }
    *(u16 *)(base + 0x124) = (u16)(*(u16 *)(base + 0x124) + 1);
    base2 = gSoundSys;

    for (i = 0; i < 3; i++) {
        entry = *(u8 **)(base2 + 0xF8) + i * 0x13C;
        if (*(u16 *)entry != 0) {
            sub = NULL;
            which = 0;
            if (*(u8 **)(entry + 0x2C) + 0x40 == arg1) {
                sub = entry + 0x2C;
                which = 0;
            }
            if (*(u8 **)(entry + 0xB4) + 0x40 == arg1) {
                sub = entry + 0xB4;
                which = 1;
            }
            if (sub != NULL) {
                if (arg0 < 0) {
                    goto cleanup;
                }
                *(u32 *)(sub + 0x34) = *(u32 *)(sub + 0x34) + *(u32 *)(sub + 0x48);
                *(u32 *)(sub + 0x3C + ((1 - *(u16 *)(sub + 0x4C)) << 2)) = *(u32 *)(sub + 0x48);
                *(u16 *)(sub + 0x54) = 1;
                if (*(u32 *)(sub + 0x34) >= *(u32 *)(sub + 0x60)) {
                    *(u32 *)(sub + 0x34) = *(u32 *)(sub + 0x64);
                    flags = *(u16 *)entry;
                    if (flags & 0x200) {
                        if (which == 0) {
                            *(u16 *)entry = flags & 0xFFFFEFFF;
                        } else {
                            *(u16 *)entry = flags & 0xFFFFDFFF;
                        }
                    } else {
                        *(u16 *)entry = flags | 0x4000;
                    }
                } else if (which == 0) {
                    *(u16 *)entry = *(u16 *)entry & 0xFFFFEFFF;
                } else {
                    *(u16 *)entry = *(u16 *)entry & 0xFFFFDFFF;
                }
                if (*(u16 *)(entry + 0x1E) == 2) {
                    if (*(u16 *)(base2 + 0x12C) == 2 && *(s16 *)(entry + 0x80) == 1 && *(s16 *)(entry + 0x108) == 1) {
                        *(u16 *)(base2 + 0x12C) = 0;
                    }
                } else if (*(u16 *)(base2 + 0x12C) == 2 && *(s16 *)(entry + 0x80) == 1) {
                    *(u16 *)(base2 + 0x12C) = 0;
                }
            }
        }
    }

    z = 0;
    j = z;
    ctr = 3;
    off = j;
    for (; ctr != 0; ctr--) {
        e2 = *(u8 **)(base2 + 0xF8) + off;
        flags = *(u16 *)e2;
        if (flags != 0 && !(flags & 8)) {
            if (*(u8 **)(e2 + 0x2C) + 0x40 == arg1) {
                *(u16 *)(e2 + 0x82) = 1;
            }
            if (*(u8 **)(e2 + 0xB4) + 0x40 == arg1) {
                *(u16 *)(e2 + 0x10A) = 1;
            }
            if (*(u16 *)(e2 + 0x1E) == 2) {
                if (*(s16 *)(e2 + 0x82) != 0) {
                    if (*(s16 *)(e2 + 0x10A) != 0) {
                        goto process;
                    }
                }
                goto cont2;
            }
            if (*(s16 *)(e2 + 0x82) == 0) {
                goto cont2;
            }
        process:
            *(u16 *)(e2 + 0x78) = 0;
            *(u16 *)(e2 + 0x100) = 0;
            *(u16 *)(e2 + 0x80) = 0;
            *(u16 *)(e2 + 0x108) = 0;
            fn_8024E100(*(void **)(e2 + 0x50));
            if (*(u16 *)(e2 + 0x1E) == 2) {
                fn_8024E100(*(void **)(e2 + 0xD8));
            }
            vol = (u8)*(u16 *)(e2 + 6);
            entry2 = *(u8 **)(base2 + 0xF8) + j * 0x13C;
            if (*(u16 *)entry2 != 0) {
                *(u16 *)(entry2 + 6) = vol;
                if (*(u16 *)entry2 & 8) {
                    if (*(u16 *)(entry2 + 0x1E) == 1) {
                        fn_8024CE60(*(void **)(entry2 + 0x50), (s32)*(f32 *)(entry2 + 0x10), vol, (u8)*(u16 *)(entry2 + 8), 0);
                    } else {
                        f = *(f32 *)(entry2 + 0x10);
                        f31 = f;
                        if (vol < 0x40) {
                            f31 = ((f32)vol * f) / lbl_80369CB4;
                        }
                        if ((u32)(vol - 0x40) >> 31 == 0) {
                            f = ((f32)(s32)(0x7F - vol) * f) / lbl_80369CB4;
                        }
                        fn_8024CE60(*(void **)(entry2 + 0x50), (s32)f, 0, (u8)*(u16 *)(entry2 + 8), 0);
                        fn_8024CE60(*(void **)(entry2 + 0xD8), (s32)f31, 0x7F, (u8)*(u16 *)(entry2 + 8), 0);
                    }
                }
            }
            *(u16 *)e2 = (u16)(*(u16 *)e2 | 8);
            goto cleanup;
        }
    cont2:
        off += 0x13C;
        j += 1;
    }

cleanup:
    nest = *(u16 *)(base + 0x124);
    if (nest != 0) {
        nest -= 1;
        *(u16 *)(base + 0x124) = nest;
        if ((u16)nest == 0) {
            OSRestoreInterrupts(*(s32 *)(gSoundSys + 0x128));
        }
    }
}
s32 fn_800B1B24(s32 arg0)
{
    extern u8 gSoundSys[];
    extern s32 fn_8024B7DC(void *);

    u8 *entry;
    s32 result;

    entry = *(u8 **)(gSoundSys + 0xF4) + arg0 * 0x14;

    if (*(u16 *)entry == 0) {
        return 0;
    }

    result = fn_8024B7DC(*(void **)(entry + 0xC));

    return result != -1;
}

void fn_800B1B80(s32 arg0, s16 arg1)
{
    extern u8 gSoundSys[];
    extern void fn_8024B828(s32, s32, s32);

    u8 *base;
    s32 value;

    base = *(u8 **)(gSoundSys + 0xF4);
    value = *(s32 *)(base + arg0 * 0x14 + 0xC);

    if ((u32)value + 0x10000 != 0xFFFFU) {
        if (arg1 == 0) {
            fn_8024B828(value, 0, 0);
        } else if (arg1 >= 0x3E80) {
            fn_8024B828(value, 0, 0);
        } else {
            fn_8024B828(value, 1, arg1);
        }
    }
}

void fn_800B1BFC(s32 arg0, s32 arg1) {
extern u8 gSoundSys[]; void Snd_SetParamU8(s32,s32,s32);
u8 *sys; u8 *p; s32 off; u32 value;
sys=gSoundSys; off=arg0*20+8;
p=*(u8 **)(sys+0xF4); p[off]=arg1;
value=*(u32 *)(*(u8 **)(sys+0xF4)+(off+4));
if(value!=0xFFFFFFFFu) Snd_SetParamU8(value,0x83,arg1);
}

void fn_800B1C54(s32 arg0, s32 arg1)
{
    extern u8 gSoundSys[];
    void Snd_SetParamU8(s32, s32, s32);
    u8 *sys;
    u8 *p;
    s32 off;
    u32 value;

    sys = gSoundSys;
    off = arg0 * 0x14 + 6;
    p = *(u8 **)(sys + 0xF4);
    *(u16 *)(p + off) = (u8)arg1;
    value = *(u32 *)(*(u8 **)(sys + 0xF4) + off + 6);
    if (value != 0xFFFFFFFFu) {
        Snd_SetParamU8((s32)value, 0xA, arg1);
    }
}

void fn_800B1CB0(s32 arg0, s32 arg1)
{
    extern u8 gSoundSys[];
    void Snd_SetParamU8(s32, s32, s32);
    u8 *base;
    s32 off;
    u32 value;

    base = *(u8 **)(gSoundSys + 0xF4);
    off = arg0 * 0x14;
    value = *(u32 *)(base + off + 0xC);

    if (value != 0xFFFFFFFFu) {
        if ((u8)arg1 > 0x7F) {
            arg1 = 0x7F;
        }
        Snd_SetParamU8((s32)value, 0x5D, arg1);
    }
}

void fn_800B1D0C(s32 arg0, s32 arg1)
{
    extern u8 gSoundSys[];
    void Snd_SetParamU8(s32, s32, s32);
    u8 *base;
    s32 off;
    u32 value;

    base = *(u8 **)(gSoundSys + 0xF4);
    off = arg0 * 0x14;
    value = *(u32 *)(base + off + 0xC);

    if (value != 0xFFFFFFFFu) {
        if ((u8)arg1 > 0x7F) {
            arg1 = 0x7F;
        }
        Snd_SetParamU8((s32)value, 0x5B, arg1);
    }
}

void fn_800B1D68(s32 arg0, u8 arg1) {
    void Snd_SetParamU8(u32, s32, u8);
    extern u8 gSoundSys[];
    u8 *entry;
    u32 handle;

    entry = M2C_FIELD(gSoundSys, u8 **, 0xF4) + arg0 * 0x14;
    handle = M2C_FIELD(entry, u32 *, 0xC);
    if (handle != 0xFFFFFFFF) {
        M2C_FIELD(entry, u16 *, 4) = arg1;
        Snd_SetParamU8(handle, 7, arg1);
        if (M2C_FIELD(gSoundSys, u16 *, 0x12C) != 0) {
            Snd_SetParamU8(handle, 7, 0);
        }
    }
}

void fn_800B1DEC(s32 arg0, s32 arg1)
{
    void Snd_SetParamU16(s32, s32, s32);
    extern u8 gSoundSys[];
    u8 *entry;
    u8 *base;
    u32 handle;

    base = *(u8 **)(gSoundSys + 0xF4);
    entry = base + arg0 * 0x14;
    handle = *(u32 *)(entry + 0xC);
    if (handle != 0xFFFFFFFFu) {
        Snd_SetParamU16((s32)handle, 0x80, (u16)(*(u16 *)(entry + 0xA) + arg1));
    }
}

void fn_800B1E44(s32 arg0)
{
    void fn_8024B714(u32);
    extern u8 gSoundSys[];

    u8 *entry;
    u8 *base;

    base = *(u8 **)(gSoundSys + 0xF4);
    entry = base + arg0 * 0x14;

    if (*(u16 *)entry != 0) {
        fn_8024B714(*(u32 *)(entry + 0xC));
        *(u16 *)entry = 0;
    }
}

#pragma use_lmw_stmw on
/* Play a sound effect: find an SE slot, duck pan/vol if the same id is already playing, start the voice. */
s32 Sound_PlaySE(u16 soundId, u8 priority, u8 volParam, u8 paramA)
{
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void *Snd_Start(u16, u8, s32, s32);
    void Snd_SetParamU8(void *, s32, u8);
    void Snd_SetParamU16(void *, s32, u16);
    extern u8 gSoundSys[];

    u8 *sys;
    u8 *base;
    u8 *p;
    s32 i;
    u8 state;
    s32 id;
    u8 *slot;
    s32 idx;
    s32 pan;
    s32 vol;

    base = *(u8 **)(gSoundSys + 0xF4);
    slot = base;
    for (idx = 0; idx < 40; idx++, slot += 0x14) {
        if (*(u16 *)slot == 0) {
            break;
        }
    }
    if (idx >= 0x28) {
        slot = base;
        for (idx = 0; idx < 40; idx++, slot += 0x14) {
            if ((s32)*(u16 *)(slot + 2) <= (s32)priority) {
                break;
            }
        }
        if (idx >= 0x28) {
            return -1;
        }
    }

    id = soundId;
    pan = 0x2000;
    vol = 0x7F;
    p = base;
    for (i = 0; i < 40; i++, p += 0x14) {
        if (*(u16 *)p != 0 && (s32)*(u16 *)(p + 0x10) == id) {
            state = *(u8 *)(p + 9);
            if (state == 0) {
                return -1;
            }
            if (state < 4) {
                pan -= 0x400;
                vol -= 0x1E;
            }
        }
    }
    if (pan < 0) {
        pan += 0x4000;
    }
    if (vol < 0) {
        vol = 0;
    }

    *(u16 *)slot = 0;
    sys = gSoundSys;
    if (*(u16 *)(sys + 0x124) == 0) {
        *(s32 *)(gSoundSys + 0x128) = OSDisableInterrupts();
    }
    *(u16 *)(sys + 0x124) = *(u16 *)(sys + 0x124) + 1;
    *(void **)(slot + 0xC) = Snd_Start(soundId, (u8)vol, 0x40, 0);
    Snd_SetParamU8(*(void **)(slot + 0xC), 7, volParam);
    Snd_SetParamU16(*(void **)(slot + 0xC), 0x80, (u16)pan);
    Snd_SetParamU8(*(void **)(slot + 0xC), 0xA, paramA);
    {
        u16 nest;
        nest = *(u16 *)(sys + 0x124);
        if (nest != 0) {
            nest -= 1;
            *(u16 *)(sys + 0x124) = nest;
            if ((u16)nest == 0) {
                OSRestoreInterrupts(*(s32 *)(gSoundSys + 0x128));
            }
        }
    }
    if ((u32)*(void **)(slot + 0xC) + 0x10000 == 0xFFFFU) {
        return -1;
    }
    *(u16 *)slot = 1;
    *(u16 *)(slot + 2) = priority;
    *(u16 *)(slot + 4) = volParam;
    *(u16 *)(slot + 6) = paramA;
    *(u8 *)(slot + 8) = 0;
    *(u16 *)(slot + 0x10) = (u16)id;
    *(u8 *)(slot + 9) = 0;
    *(u16 *)(slot + 0xA) = (u16)pan;
    if (*(u16 *)(gSoundSys + 0x12C) != 0) {
        Snd_SetParamU8(*(void **)(slot + 0xC), 7, 0);
    }
    return idx;
}
s32 fn_800B2494(s32 arg0)
{
    s32 fn_8024B370(void *);
    extern u8 gSoundSys[];

    u8 *base;
    void *entry;
    s32 result;

    base = *(u8 **)(gSoundSys + 0xF0);
    entry = *(void **)(base + (arg0 << 4));

    result = fn_8024B370(entry);

    return (u8)result != 0;
}

void fn_800B24D8(s32 arg0, u8 arg1) {
    u8 fn_8024B370(s32);
    void fn_8024B4B0(u8, s32, s32, s32);
    extern u8 gSoundSys[];
    s32 *entry;

    entry = (s32 *)(M2C_FIELD(gSoundSys, u8 **, 0xF0) + arg0 * 16);
    if (fn_8024B370(entry[0])) {
        if (arg1 > 0x7F) {
            arg1 = 0x7F;
        }
        entry[1] = arg1;
        fn_8024B4B0(entry[1], 0, entry[0], 0);
        if (M2C_FIELD(gSoundSys, u16 *, 0x12C) != 0) {
            fn_8024B4B0(0, 0, entry[0], 0);
        }
    }
}

void fn_800B2584(s32 arg0)
{
    extern u8 gSoundSys[];

    extern s32 fn_8024B370(s32);
    extern void fn_8024B4B0(s32, u32, s32, s32);

    u8 *base;
    u8 *table;
    s32 offset;
    s32 handle;

    base = gSoundSys;
    offset = arg0 << 4;
    table = *(u8 **)(base + 0xF0);

    handle = *(s32 *)(table + offset);

    if ((u8)fn_8024B370(handle) != 0) {
        fn_8024B4B0(
            0,
            *(u16 *)(gSoundSys + 0x122),
            *(s32 *)(table + offset),
            2
        );
    }
}

void fn_800B25EC(s32 arg0)
{
    extern u8 gSoundSys[];
    s32 fn_8024B370(s32);
    void fn_8024B3A0(s32);
    u8 *base;
    u8 *table;
    s32 offset;

    base = gSoundSys;
    offset = arg0 << 4;
    table = *(u8 **)(base + 0xF0);

    if ((u8)fn_8024B370(*(s32 *)(table + offset)) != 0) {
        fn_8024B3A0(*(s32 *)(table + offset));
        *(s32 *)(table + offset) = -1;
    }
}

void fn_800B2648(s32 arg0) {
    u8 fn_8024B370(s32);
    void fn_8024B420(s32);
    void fn_8024B4B0(u8, s32, s32, s32);
    extern u8 gSoundSys[];
    s32 *entry;

    entry = (s32 *)(M2C_FIELD(gSoundSys, u8 **, 0xF0) + arg0 * 16);
    if (fn_8024B370(entry[0])) {
        fn_8024B420(entry[0]);
        fn_8024B4B0(entry[1], 0, entry[0], 0);
    }
}

extern void *vidListRoot;
s32 fn_800B26B0(u32 arg0) {
    u32 temp_r0;
    void *var_r4;
    
    if ((u32)(arg0 + 0x10000) != -1U) {
        var_r4 = vidListRoot;
        if (var_r4 == NULL) {
            return -1;
        }
        
        do {
            temp_r0 = *(u32 *)((char *)var_r4 + 0x8);
            if (temp_r0 == arg0) {
                return *(s32 *)((char *)var_r4 + 0xC);
            }
            if (temp_r0 > arg0) {
                var_r4 = *(void **)((char *)var_r4 + 0x0);
                if (var_r4 == NULL) {
                    return -1;
                }
            } else {
                var_r4 = *(void **)((char *)var_r4 + 0x4);
                if (var_r4 == NULL) {
                    return -1;
                }
            }
        } while (1);
    }
    return -1;
}

void fn_800B27BC(void) {
    u8 Sound_IsReady(void);
    extern u8 gSoundSys[];
    u8 *base;
    void *unit;
    s32 flag;

    if (Sound_IsReady() != 0) {
        base = gSoundSys;
        if (*(u16 *)(base + 0x12C) == 1) {
            unit = *(void **)(base + 0xF8);
            flag = 0;
            {
                u16 bits = *(u16 *)unit;
                if ((bits & 8) && !(bits & 0x400) && !(bits & 2)) {
                    if (bits & 0x1000) {
                        flag = 1;
                    }
                    if (*(u16 *)((u8 *)unit + 0x1E) == 2 && (bits & 0x2000)) {
                        flag = 1;
                    }
                }
            }
            {
                u16 bits = *(u16 *)((u8 *)unit + 0x13C);
                if ((bits & 8) && !(bits & 0x400) && !(bits & 2)) {
                    if (bits & 0x1000) {
                        flag = 1;
                    }
                    if (*(u16 *)((u8 *)unit + 0x15A) == 2 && (bits & 0x2000)) {
                        flag = 1;
                    }
                }
            }
            {
                u16 bits = *(u16 *)((u8 *)unit + 0x278);
                if ((bits & 8) && !(bits & 0x400) && !(bits & 2)) {
                    if (bits & 0x1000) {
                        flag = 1;
                    }
                    if (*(u16 *)((u8 *)unit + 0x296) == 2 && (bits & 0x2000)) {
                        flag = 1;
                    }
                }
            }
            if (flag != 0) {
                *(u16 *)(base + 0x12C) = 2;
            } else {
                *(u16 *)(base + 0x12C) = 0;
            }
        }
    }
}

void fn_800B28DC(void) {
    extern u8 gSoundSys[];

    if (M2C_FIELD(gSoundSys, u16 *, 0x12C) == 0) {
        M2C_FIELD(gSoundSys, u16 *, 0x12C) = 1;
    }
}

void fn_800B28FC(s32 arg0) {
    extern u8 gSoundSys[];
    void fn_8024B94C(void);
    *(s32 *)(gSoundSys + 0x130) = arg0;
    fn_8024B94C();
}

#pragma global_optimizer off
#pragma use_lmw_stmw on
/* Load .stm/.slib/.stbl sound banks for pack id into the next gSoundSys slot. */
s32 Sound_LoadPack(s32 arg0) {
    s32 fn_800B4A84(void *, s32, s32);
    s32 fn_800B49C8(void *);
    void fn_800B49D0(void *);
    s32 fn_800B4A14(void *, s32, s32, s32);
    extern u8 gSoundSys[];
    s32 fn_800C4638(s32, void *, s32);
    void fn_800C4588(s32);
    void sprintf(void *, void *, ...);
    extern u8 Sound_str[], gSoundPathBuf[];
    u32 value;
    u32 buffer;
    s32 size;
    s32 handle;
    u8 *base;
    u8 *p, *node, *tail;
    u8 *loopBase, *names;
    s32 id = arg0;
    u32 length;
    u16 index;
    base = (u8 *)gSoundSys;
    if (*(u32 *)(base + 0xE4) >= 8) return 0;
    sprintf(gSoundPathBuf, Sound_str + 0x1E, id, Sound_str + 0x2F);

    buffer = LoadSoundBankB(gSoundPathBuf);
    if (buffer == 0) return 0;

    value = *(u32 *)(base + 0xE4);
    loopBase = (u8 *)gSoundSys;
    names = Sound_str;
    p = loopBase + value*4;
    *(u32 *)(p + 0x60) = buffer;
    for (;;) {
        length = *(u32 *)buffer;
        if (length == 0xFFFFFFFF) break;
        node = (u8 *)fn_800C4638(0x10, names + 0x2E, 0);
        if (node == 0) { for (;;) {} }
        index = 0;
        if (*(u8 **)(loopBase + 0xEC) == 0) *(u8 **)(loopBase + 0xEC) = node;
        else {
            tail = *(u8 **)(loopBase + 0xEC);
            for (;;) {
                u8 *next = *(u8 **)(tail + 0xC);
                index++;
                if (next == 0) break;
                tail = next;
            }
            *(u8 **)(tail + 0xC) = node;
        }
        *(u16 *)node = 1;
        *(u16 *)(node + 2) = index;
        *(u16 *)(node + 4) = 0;
        *(u16 *)(node + 6) = 0;
        *(u8 **)(node + 8) = (u8 *)buffer + 0x20;
        *(u32 *)(node + 0xC) = 0;
        buffer += length;
    }
    sprintf(gSoundPathBuf, (u8 *)Sound_str + 0x1E, id, (u8 *)Sound_str + 0x35);

    buffer = LoadSoundBankB(gSoundPathBuf);
    if (buffer == 0) return 0;

    {
        u32 slot = *(u32 *)(base + 0xE4);
        u8 *table = (u8 *)gSoundSys;
        table += slot * 4;
        *(u32 *)(table + 0x80) = buffer;
    }
    sprintf(gSoundPathBuf, &Sound_str[0x1E], id, &Sound_str[0x3B]);

    buffer = LoadSoundBankB(gSoundPathBuf);
    if (buffer == 0) return 0;

    {
        u32 slot = *(u32 *)(base + 0xE4);
        u8 *table = (u8 *)gSoundSys;
        table += slot * 4;
        *(u32 *)(table + 0xA0) = buffer;
    }
    *(u32 *)(base + 0xE4) += 1;
    return 1;
}
#pragma global_optimizer reset
s32 fn_800B2CCC(void) {
    s32 *p;
    s32 i;
    s32 n;

    p = (s32 *)lbl_80319A68;
    for (i = 0, n = 0; i < 2; i++, n += 7) {
        if (*p != 0) {
            return 0;
        }
        if (*++p != 0) {
            return 0;
        }
        if (*++p != 0) {
            return 0;
        }
        if (*++p != 0) {
            return 0;
        }
        if (*++p != 0) {
            return 0;
        }
        if (*++p != 0) {
            return 0;
        }
        if (*++p != 0) {
            return 0;
        }
        if (*++p != 0) {
            return 0;
        }
        p++;
    }
    return n | 1;
}

s32 fn_800B2D94(void) {
    lbl_80319A68[0] = 2;
    lbl_80319A68[1] = 3;
    lbl_80319A68[2] = 7;
    lbl_80319A68[3] = 8;
    lbl_80319A68[4] = 9;
    lbl_80319A68[5] = 10;
    lbl_80319A68[6] = 11;
    lbl_80319A68[7] = 12;
    return 1;
}

s32 fn_800B2DE4(s32 arg0, s32 arg1) {
    s32 fn_8020C6D4(char *, void *);
    s32 fn_8020CC28(void *, s32, s32, s32, s32);
    s32 fn_8020C79C(void *);
    extern u8 gSoundSys[];
    u8 sp8[0x3C];

    if (fn_8020C6D4((char *)gSoundSys + 0x342, sp8) == 0) {
        return 0;
    }
    if (fn_8020CC28(sp8, M2C_FIELD(gSoundSys, s32 *, 0x448), arg1, arg0, 2) <= 0) {
        return 0;
    }
    fn_8020C79C(sp8);
    return M2C_FIELD(gSoundSys, s32 *, 0x448);
}

s32 fn_800B2E78(void) {
    extern u8 lbl_80319A58[16];
    s32 i;
    s32 count;

    count = 0;
    for (i = 0; i < 16; i++) {
        if (lbl_80319A58[i] != 0) {
            count++;
        }
    }
    return count;
}

s32 fn_800B2F20(s32 arg0) {
extern u8 lbl_80319A58[];
s32 i;
u8 *p = lbl_80319A58;
arg0=(u8)arg0+1;
for(i=0;i<16;p++,i++) {
if(*p==(u8)arg0) return 1;
}
return 0;
}

extern u16 lbl_80319A18[];
s32 fn_800B2FF4(u8 arg0) {
    u16 *ptr;
    s32 count;
    
    if (arg0 == 0) {
        ptr = &lbl_80319A18[0];
        count = 2;
loop_1:
        if (*ptr != 0) {
            return 0;
        }
        ptr += 1;
        if (*ptr != 0) {
            return 0;
        }
        ptr += 1;
        if (*ptr != 0) {
            return 0;
        }
        ptr += 1;
        if (*ptr != 0) {
            return 0;
        }
        ptr += 1;
        if (*ptr != 0) {
            return 0;
        }
        ptr += 1;
        if (*ptr != 0) {
            return 0;
        }
        ptr += 1;
        if (*ptr != 0) {
            return 0;
        }
        ptr += 1;
        count -= 1;
        if (count == 0) {
            return 1;
        }
        goto loop_1;
    } else {
        s32 temp_arg0 = arg0 + 1;
        ptr = &lbl_80319A18[0];
        count = 2;
loop_2:
        if (temp_arg0 == *ptr) {
            return 0;
        }
        ptr += 1;
        if (temp_arg0 == *ptr) {
            return 0;
        }
        ptr += 1;
        if (temp_arg0 == *ptr) {
            return 0;
        }
        ptr += 1;
        if (temp_arg0 == *ptr) {
            return 0;
        }
        ptr += 1;
        if (temp_arg0 == *ptr) {
            return 0;
        }
        ptr += 1;
        if (temp_arg0 == *ptr) {
            return 0;
        }
        ptr += 1;
        if (temp_arg0 == *ptr) {
            return 0;
        }
        ptr += 1;
        count -= 1;
        if (count == 0) {
            return 1;
        }
        goto loop_2;
    }
}

s32 fn_800B3194(void) {
    void fn_802590E0(void);
    extern u8 gSoundSys[];
    extern u8 lbl_80319A58[16];
    u32 i;

    while (M2C_FIELD(gSoundSys, u32 *, 0xC4) != 0) {
        fn_802590E0();
        M2C_FIELD(gSoundSys, u32 *, 0xC4)--;
    }
    for (i = 0; i < 16; i++) {
        lbl_80319A58[i] = 0;
    }
    if (M2C_FIELD(gSoundSys, u32 *, 0x444) != 0) {
        M2C_FIELD(gSoundSys, u32 *, 0x444) = 0;
    }
    return 1;
}

s32 fn_800B33FC(s32 arg0, s32 arg1) {
    s32 fn_8020C6D4(char *, void *);
    s32 fn_8020CC28(void *, s32, s32, s32, s32);
    s32 fn_8020C79C(void *);
    extern u8 gSoundSys[];
    u8 sp8[0x3C];

    if (fn_8020C6D4((char *)gSoundSys + 0x242, sp8) == 0) {
        return 0;
    }
    if (fn_8020CC28(sp8, M2C_FIELD(gSoundSys, s32 *, 0x444), arg1, arg0, 2) <= 0) {
        return 0;
    }
    fn_8020C79C(sp8);
    return M2C_FIELD(gSoundSys, s32 *, 0x444);
}

void fn_800B3490(void) {
    extern u16 gSoundSys[];
    u32 *p = (u32 *)((u8 *)gSoundSys + 0x444);
    if (*p != 0) {
        *p = 0;
    }
}

#pragma use_lmw_stmw on
s32 fn_800B34B0(u8 *arg0) {
    s32 fn_800B4A84(void *, s32, s32);
    s32 fn_800B49C8(void *);
    void fn_800B49D0(void *);
    s32 fn_800B4A14(void *, s32, s32, s32);
    s32 fn_800C4638(s32, void *, s32);
    void fn_800C4588(s32);
    void fn_800062EC(s32, s32, u32);
    u32 OSGetResetCode();
    void DCFlushRange(void *, u32);
    void fn_80258D74(u8 *(*)(s32, u32), s32);
    u8 Sound_PushGroup(s32, u16, s32, s32, s32);
    u8 *fn_800B3F8C(s32, u32);
    extern u8 gSoundSys[];
    extern void *lbl_80367814;
    extern s32 lbl_8036780C;
    extern u8 Sound_str[];
    u8 *base;
    s32 handle;
    u32 buffer;
    s32 size;
    u32 value;
    s32 i;
    u32 *counter_ptr;
    
    base = gSoundSys;
    if (*(u32 *)(base + 0xE0) >= 8) {
        return 0;
    }
    lbl_80367814 = NULL;
    handle = fn_800B4A84(base + 0x142, 2, 0);
    if (handle == 0) {
        buffer = 0;
    } else {
        value = fn_800B49C8((void *)handle);
        if (value == 0) {
            buffer = 0;
        } else {
            size = (value + 0x1F) & 0xFFFFFFE0;
            buffer = fn_800C4638(size, Sound_str + 0x2E, 0);
            if (buffer == 0) {
                buffer = 0;
            } else {
                lbl_8036780C = size;
                if (((OSGetResetCode() >> 31) != 0) && ((OSGetResetCode() & 0x100) != 0)) {
                    fn_800062EC(buffer, 0x81200000 - size, size);
                    DCFlushRange((void *)buffer, size);
                } else if (fn_800B4A14((void *)handle, buffer, size, 0) <= 0) {
                    fn_800C4588(buffer);
                    buffer = 0;
                    goto stored;
                }
                fn_800B49D0((void *)handle);
            }
        }
    }
stored:
    lbl_80367814 = (void *)buffer;
    if (buffer == 0) {
        return 0;
    }
    {
        u8 *p = gSoundSys;
        if (*(u32 *)(p + 0x444) == 0) {
            *(u32 *)(p + 0x444) = *(u32 *)(p + 0x448);
            fn_80258D74(fn_800B3F8C, 0x20000);
        }
    }
    {
        u8 *ptr = gSoundSys;
        counter_ptr = (u32 *)(ptr + 0xC0);
        *(u32 *)(ptr + 0xC0) = 0;
        if (arg0 != NULL) {
            while (*arg0 != 0xFF) {
                Sound_PushGroup(*(s32 *)(ptr + 0x20), *arg0, 0, *(s32 *)(ptr + 0x40), *(s32 *)(ptr + 0x0));
                *(u32 *)counter_ptr += 1;
                arg0++;
            }
        } else {
            for (i = 0; i < 6; i++) {
                if (Sound_PushGroup(*(s32 *)(ptr + 0x20), i, 0, *(s32 *)(ptr + 0x40), *(s32 *)(ptr + 0x0)) == 1) {
                    *(u32 *)counter_ptr += 1;
                    *(u32 *)(ptr + 0xE8) += 1;
                }
            }
        }
    }
    if (lbl_80367814 != NULL) {
        fn_800C4588((s32)lbl_80367814);
    }
    *(u32 *)((u8 *)counter_ptr + *(u32 *)(base + 0xE0) * 4) = 0;
    return 1;
}

#pragma global_optimizer off
s32 fn_800B36D8(s32 arg0) {
    void sprintf(void *, void *, ...);
    void strcpy(void *, void *, void *);
    extern u8 Sound_str[], gSoundPathBuf[], gSoundSys[];
    u32 buf;

    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg0, Sound_str + 0x6C);
    buf = LoadSoundBankB(gSoundPathBuf);
    if (buf == 0) return 0;
    *(u32 *)(gSoundSys + 0x0) = buf;

    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg0, Sound_str + 0x72);
    buf = LoadSoundBankB(gSoundPathBuf);
    if (buf == 0) return 0;
    *(u32 *)(gSoundSys + 0x20) = buf;

    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg0, Sound_str + 0x78);
    buf = LoadSoundBankB(gSoundPathBuf);
    if (buf == 0) return 0;
    *(u32 *)(gSoundSys + 0x40) = buf;

    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg0, Sound_str + 0x7E);
    strcpy(gSoundSys + 0x142, gSoundPathBuf, gSoundSys);

    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg0, Sound_str + 0x84);
    buf = LoadSoundBankB(gSoundPathBuf);
    if (buf == 0) return 0;
    *(u32 *)(gSoundSys + 0x8) = buf;

    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg0, Sound_str + 0x8E);
    buf = LoadSoundBankB(gSoundPathBuf);
    if (buf == 0) return 0;
    *(u32 *)(gSoundSys + 0x28) = buf;

    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg0, Sound_str + 0x98);
    buf = LoadSoundBankB(gSoundPathBuf);
    if (buf == 0) return 0;
    *(u32 *)(gSoundSys + 0x48) = buf;

    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg0, Sound_str + 0xA2);
    strcpy(gSoundSys + 0x342, gSoundPathBuf, gSoundSys);

    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg0, Sound_str + 0xAC);
    buf = LoadSoundBankB(gSoundPathBuf);
    if (buf == 0) return 0;
    *(u32 *)(gSoundSys + 0x4) = buf;

    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg0, Sound_str + 0xB8);
    buf = LoadSoundBankB(gSoundPathBuf);
    if (buf == 0) return 0;
    *(u32 *)(gSoundSys + 0x24) = buf;

    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg0, Sound_str + 0xC4);
    buf = LoadSoundBankB(gSoundPathBuf);
    if (buf == 0) return 0;
    *(u32 *)(gSoundSys + 0x44) = buf;

    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg0, Sound_str + 0xD0);
    strcpy(gSoundSys + 0x242, gSoundPathBuf, gSoundSys);
    return 1;
}

u8 *fn_800B3F8C(s32 arg0, u32 arg1) {
extern u8 gSoundSys[];
extern void *lbl_80367814;
void fn_800062EC(u8 *, u8 *, u32);
u8 *base=gSoundSys;
u8 *dst=*(u8 **)(base+0x444);
u8 *src=(u8*)lbl_80367814+arg0;
if((arg1 & 7)==0) fn_800062EC(dst,src,arg1);
else {
for(;arg1!=0;arg1--) *dst++=*src++;
}
return *(u8 **)(base+0x444);
}

#pragma global_optimizer on
void fn_800B4060(void) {
    M2C_UNK fn_800AECC0();
    fn_800AECC0();
}

void fn_800B4080(void) {
    void fn_800B22D8(void);
    void fn_800AF0B4(void);
    s32 fn_8024B7DC(void *);
    extern u8 gSoundSys[];
    void fn_8024B714(u32);
    unsigned long off;
    u8 *sys;
    long i;
    register u8 *entry;
    u8 *p;
    unsigned long result;

    fn_800B22D8();
    i = 0;
    sys = gSoundSys;
    entry = *(u8 **)(sys + 0xF4);
    off = i;
    while (i < 0x28) {
        if (*(u16 *)entry != 0) {
            entry[9] = (u8)(entry[9] + 1);
            result = fn_8024B7DC(*(void **)(*(u8 **)(sys + 0xF4) + off + 0xC));
            if ((u32)(result + 0x10000) == 0xFFFFU) {
                p = *(u8 **)(sys + 0xF4) + off;
                if (*(u16 *)p != 0) {
                    fn_8024B714(*(u32 *)(p + 0xC));
                    *(u16 *)p = 0;
                }
            }
        }
        ++i;
        off += 0x14;
        entry += 0x14;
    }
    fn_800AF0B4();
}

void fn_800B412C(void) {
void fn_800B47F0(void);
extern u8 lbl_80312BD0[], Sound_str[];
extern s32 lbl_80369CA8,lbl_80369CAC;
extern f32 lbl_80369CB0,lbl_80369CD8,lbl_80369CDC,lbl_80369CE0,lbl_80369CE4,lbl_80369CE8,lbl_80369CEC;
void fn_802141EC(void *,s32); void fn_80215D2C(void); void fn_80213B44(s32); void fn_80214184(s32);
void fn_802624DC(void *); void Sound_Init(s32,s32,s32,s32,s32,s32);
void fn_80263CF0(void *); void fn_80263830(void *); void fn_80265230(void *); void fn_80264B7C(void *);
void fn_80263C94(void); void fn_80264F74(void); void fn_800AEB90(void);
void fn_8024BA38(s32,void *,void *,s32,s32,void *,void *,s32,s32);
void fn_8024B8EC(s32,s32,s32); void fn_8024B94C(s32);
s32 fn_8021371C(void *); u32 fn_80213800(void); u32 fn_8021381C(void);
void OSReport(void *,...); void *fn_800C4638(s32,void *,s32);
s32 fn_8024CE1C(s32,s32); void *memset(void *,s32,u32);
s32 fn_8020A558(void *,void *,s32,void *,s32,s32,s32); void fn_8020A9E0(void *);
s32 config[2]; u8 *p; u8 *stream; s32 i; u8 *base=lbl_80312BD0;
config[0]=lbl_80369CA8; config[1]=lbl_80369CAC;
fn_802141EC(base,8); fn_80215D2C(); fn_80213B44(0); fn_80214184(0xbfc000);
fn_802624DC(config); Sound_Init(64,64,64,1,1,0xbfc000);
{ u8 *p=base+0x20;
M2C_FIELD(p,u8 *,452)=0;
M2C_FIELD(p,f32 *,464)=lbl_80369CD8;
M2C_FIELD(p,f32 *,472)=lbl_80369CDC;
M2C_FIELD(p,f32 *,468)=lbl_80369CE0;
M2C_FIELD(p,f32 *,456)=lbl_80369CB0;
M2C_FIELD(p,f32 *,476)=lbl_80369CB0;
M2C_FIELD(p,f32 *,460)=lbl_80369CE4;
fn_80263CF0(p); } { u8 *p=base+0x200;M2C_FIELD(p,u8 *,316)=0;
M2C_FIELD(p,f32 *,328)=lbl_80369CE8;
M2C_FIELD(p,f32 *,336)=lbl_80369CDC;
M2C_FIELD(p,f32 *,332)=lbl_80369CEC;
M2C_FIELD(p,f32 *,320)=lbl_80369CEC;
M2C_FIELD(p,f32 *,324)=lbl_80369CEC;
fn_80263830(p); } { u8 *p=base+0x354; M2C_FIELD(p,s32 *,0x90)=10; M2C_FIELD(p,s32 *,0x94)=0; M2C_FIELD(p,s32 *,0x98)=500; fn_80265230(p); } { u8 *p=base+0x3f0;M2C_FIELD(p,s32 *,60)=150;M2C_FIELD(p,s32 *,64)=150;M2C_FIELD(p,s32 *,68)=50;M2C_FIELD(p,s32 *,72)=30;M2C_FIELD(p,s32 *,76)=30;M2C_FIELD(p,s32 *,80)=30;M2C_FIELD(p,s32 *,84)=50;M2C_FIELD(p,s32 *,88)=50;M2C_FIELD(p,s32 *,92)=50;fn_80264B7C(p); }
fn_8024BA38(0,fn_80263C94,base+0x20,255,0,fn_80264F74,base+0x354,255,0);
fn_8024B8EC(127,0,255); M2C_FIELD(base,s32 *,0x4898)=1; fn_8024B94C(1);
M2C_FIELD(base,s32 *,0x4e40)=fn_8021371C(fn_800AEB90);
M2C_FIELD(base,u32 *,0x4bb8)=fn_80213800()|0x80000000;
{u32 size=fn_8021381C(); p=base+0x4768; M2C_FIELD(p,u32 *,0x454)=size;
if(size>640) {OSReport(Sound_str); for(;;) {} }}
M2C_FIELD(p,s16 *,1100)=0;M2C_FIELD(p,s32 *,9948)=0;M2C_FIELD(p,s16 *,288)=10;M2C_FIELD(p,s16 *,290)=500;M2C_FIELD(p,s32 *,224)=0;M2C_FIELD(p,s32 *,228)=0;M2C_FIELD(p,s16 *,300)=0;M2C_FIELD(p,s16 *,316)=0;M2C_FIELD(p,s32 *,232)=0;M2C_FIELD(p,s32 *,1092)=0;M2C_FIELD(base,void **,0x4bb0)=fn_800C4638(0x20000,Sound_str+46,0);
M2C_FIELD(base,s32 *,0x4854)=0;
p=fn_800C4638(128,Sound_str+46,0); M2C_FIELD(base,void **,0x4858)=p;
if(!p) for(;;) {}
for(i=0;i<8;i++){M2C_FIELD(p,s32 *,i*16)=-1; M2C_FIELD(p,s32 *,i*16+8)=0;}
p=fn_800C4638(800,Sound_str+46,0); M2C_FIELD(base,void **,0x485c)=p;
if(!p) for(;;) {}
for(i=0;i<40;i++,p+=20){M2C_FIELD(p,s16 *,0)=0;M2C_FIELD(p,s32 *,12)=-1;M2C_FIELD(p,s16 *,2)=0;M2C_FIELD(p,s16 *,4)=127;M2C_FIELD(p,s16 *,6)=64;}
p=fn_800C4638(0x3b4,Sound_str+46,0); M2C_FIELD(base,void **,0x4860)=p;
if(!p) for(;;) {}
stream=p;
for(i=0;i<3;i++,stream+=0x13c) {
M2C_FIELD(stream,s16 *,0)=0;
p=fn_800C4638(0x8000,Sound_str+46,0); if(!p) for(;;) {} M2C_FIELD(stream,void **,88)=p;p=fn_800C4638(0x8000,Sound_str+46,0); if(!p) for(;;) {} M2C_FIELD(stream,void **,92)=p;p=fn_800C4638(fn_8024CE1C(0xe00,0),Sound_str+46,0); if(!p) for(;;) {} M2C_FIELD(stream,void **,84)=p;p=fn_800C4638(0x8000,Sound_str+46,0); if(!p) for(;;) {} M2C_FIELD(stream,void **,224)=p;p=fn_800C4638(0x8000,Sound_str+46,0); if(!p) for(;;) {} M2C_FIELD(stream,void **,228)=p;p=fn_800C4638(fn_8024CE1C(0xe00,0),Sound_str+46,0); if(!p) for(;;) {} M2C_FIELD(stream,void **,220)=p;} p=base+0x4768;
M2C_FIELD(p,void **,0x100)=fn_80263C94; M2C_FIELD(p,void **,0x104)=base+0x20;
M2C_FIELD(p,u8 *,0x108)=255; M2C_FIELD(p,s32 *,0x10c)=0;
M2C_FIELD(p,void **,0x110)=fn_80264F74; M2C_FIELD(p,void **,0x114)=base+0x354;
M2C_FIELD(p,u8 *,0x118)=255; M2C_FIELD(p,s32 *,0x11c)=0;
memset(base+0x6e48,0,64); memset(base+0x6e98,0,64); memset(base+0x6e88,0,16);
if(!fn_8020A558(base+0x450,fn_800B47F0,0,base+0x768+0x4000,0x4000,16,1)) for(;;) {}
fn_8020A9E0(base+0x450);
}

void fn_800B46D8(void) {
void DCInvalidateRange(void *,u32); void fn_8005E0F0(void); void fn_80208780(void *,u32); void fn_8020A824(void *); s32 fn_802142B0(void); void ARQPostRequest(void *,s32,s32,s32,s32,void *,s32,void *); void fn_80215EF8(void); void fn_800B4794(void);
extern s32 lbl_8036780C; extern u8 lbl_80367810; extern u8 lbl_80313020[];
u8 sp8[0x1C]; s32 dest; s32 size; u8 *base;
if(lbl_8036780C!=0) {
size=lbl_8036780C; base=(u8*)fn_802142B0()+0x500; lbl_80367810=1; dest=0x81200000-size;
fn_8005E0F0(); fn_8020A824(lbl_80313020); fn_80215EF8(); DCInvalidateRange((void*)dest,size);
ARQPostRequest(sp8,0,1,0,(s32)base,(void*)dest,size,fn_800B4794);
while(lbl_80367810!=0) {} fn_80208780((void*)dest,0x81200000);
}}

void fn_800B4794(void) {
    extern s8 lbl_80367810;
    lbl_80367810 = 0;
}

void fn_800B47A0(void) {
    M2C_UNK fn_800C4588();
    fn_800C4588();
}

void *fn_800C4638(s32, void *, s32);
void fn_800B47C0(s32 arg0) {
    extern u8 Sound_str[];
    fn_800C4638(arg0, Sound_str + 0x2E, 0);
}

void fn_800B47F0(void) {
    extern M2C_UNK lbl_80312BD0;
    s32 temp_r27_2;
    s32 temp_r4;
    u8 temp_r27;
    void *temp_r30;
    void *temp_r5;
    void *temp_r5_2;

    temp_r30 = &lbl_80312BD0 + 0x4768;
loop_1:
    if ((s32) M2C_FIELD(&lbl_80312BD0, s32 *, 0x6E48) != 0) {
        temp_r27 = M2C_FIELD(&lbl_80312BD0, s32 *, 0x6E48) - 1;
        if ((u32) M2C_FIELD(temp_r30, u32 *, 0x444) == 0U) {
            M2C_FIELD(temp_r30, u32 *, 0x444) = (u32) M2C_FIELD(temp_r30, u32 *, 0x448);
            fn_80258D74(&fn_800B33FC, 0x20000);
        }
        Sound_PushGroup(M2C_FIELD(temp_r30, s32 *, 0x24), temp_r27, 0, M2C_FIELD(temp_r30, s32 *, 0x44), M2C_FIELD(temp_r30, s32 *, 4));
        M2C_FIELD(temp_r30, s32 *, 0xC4) = (s32) (M2C_FIELD(temp_r30, s32 *, 0xC4) + 1);
    }
    temp_r5 = &lbl_80312BD0 + 0x6E48;
    temp_r27_2 = M2C_FIELD(&lbl_80312BD0, s32 *, 0x6E98);
    M2C_FIELD(&lbl_80312BD0, s32 *, 0x6E48) = (s32) M2C_FIELD(temp_r5, s32 *, 4);
    M2C_FIELD(temp_r5, s32 *, 4) = (s32) M2C_FIELD(temp_r5, s32 *, 8);
    M2C_FIELD(temp_r5, s32 *, 8) = (s32) M2C_FIELD(temp_r5, s32 *, 0xC);
    M2C_FIELD(temp_r5, s32 *, 0xC) = (s32) M2C_FIELD(temp_r5, s32 *, 0x10);
    M2C_FIELD(temp_r5, s32 *, 0x10) = (s32) M2C_FIELD(temp_r5, s32 *, 0x14);
    M2C_FIELD(temp_r5, s32 *, 0x14) = (s32) M2C_FIELD(temp_r5, s32 *, 0x18);
    M2C_FIELD(temp_r5, s32 *, 0x18) = (s32) M2C_FIELD(temp_r5, s32 *, 0x1C);
    M2C_FIELD(temp_r5, s32 *, 0x1C) = (s32) M2C_FIELD(temp_r5, s32 *, 0x20);
    M2C_FIELD(temp_r5, s32 *, 0x20) = (s32) M2C_FIELD(temp_r5, s32 *, 0x24);
    M2C_FIELD(temp_r5, s32 *, 0x24) = (s32) M2C_FIELD(temp_r5, s32 *, 0x28);
    M2C_FIELD(temp_r5, s32 *, 0x28) = (s32) M2C_FIELD(temp_r5, s32 *, 0x2C);
    M2C_FIELD(temp_r5, s32 *, 0x2C) = (s32) M2C_FIELD(temp_r5, s32 *, 0x30);
    M2C_FIELD(temp_r5, s32 *, 0x30) = (s32) M2C_FIELD(temp_r5, s32 *, 0x34);
    M2C_FIELD(temp_r5, s32 *, 0x34) = (s32) M2C_FIELD(temp_r5, s32 *, 0x38);
    M2C_FIELD(temp_r5, s32 *, 0x38) = (s32) M2C_FIELD(temp_r5, s32 *, 0x3C);
    M2C_FIELD((&lbl_80312BD0 + 0x6E48), s32 *, 0x3C) = 0;
    if (temp_r27_2 != 0) {
        fn_80258D74(&fn_800B2DE4, 0x20000);
        Sound_PushGroup(M2C_FIELD(temp_r30, s32 *, 0x28), (u8) (temp_r27_2 - 1), 0, M2C_FIELD(temp_r30, s32 *, 0x48), M2C_FIELD(temp_r30, s32 *, 8));
    }
    temp_r5_2 = &lbl_80312BD0 + 0x6E98;
    M2C_FIELD(&lbl_80312BD0, s32 *, 0x6E98) = (s32) M2C_FIELD(temp_r5_2, s32 *, 4);
    M2C_FIELD(temp_r5_2, s32 *, 4) = (s32) M2C_FIELD(temp_r5_2, s32 *, 8);
    M2C_FIELD(temp_r5_2, s32 *, 8) = (s32) M2C_FIELD(temp_r5_2, s32 *, 0xC);
    M2C_FIELD(temp_r5_2, s32 *, 0xC) = (s32) M2C_FIELD(temp_r5_2, s32 *, 0x10);
    M2C_FIELD(temp_r5_2, s32 *, 0x10) = (s32) M2C_FIELD(temp_r5_2, s32 *, 0x14);
    M2C_FIELD(temp_r5_2, s32 *, 0x14) = (s32) M2C_FIELD(temp_r5_2, s32 *, 0x18);
    M2C_FIELD(temp_r5_2, s32 *, 0x18) = (s32) M2C_FIELD(temp_r5_2, s32 *, 0x1C);
    M2C_FIELD(temp_r5_2, s32 *, 0x1C) = (s32) M2C_FIELD(temp_r5_2, s32 *, 0x20);
    M2C_FIELD(temp_r5_2, s32 *, 0x20) = (s32) M2C_FIELD(temp_r5_2, s32 *, 0x24);
    M2C_FIELD(temp_r5_2, s32 *, 0x24) = (s32) M2C_FIELD(temp_r5_2, s32 *, 0x28);
    M2C_FIELD(temp_r5_2, s32 *, 0x28) = (s32) M2C_FIELD(temp_r5_2, s32 *, 0x2C);
    M2C_FIELD(temp_r5_2, s32 *, 0x2C) = (s32) M2C_FIELD(temp_r5_2, s32 *, 0x30);
    M2C_FIELD(temp_r5_2, s32 *, 0x30) = (s32) M2C_FIELD(temp_r5_2, s32 *, 0x34);
    M2C_FIELD(temp_r5_2, s32 *, 0x34) = (s32) M2C_FIELD(temp_r5_2, s32 *, 0x38);
    temp_r4 = M2C_FIELD(temp_r5_2, s32 *, 0x3C);
    M2C_FIELD(temp_r5_2, s32 *, 0x38) = temp_r4;
    M2C_FIELD((&lbl_80312BD0 + 0x6E98), s32 *, 0x3C) = 0;
    OS_YieldThread(0, temp_r4, temp_r5_2);
    goto loop_1;
}

s32 fn_800B49C8(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x74);
}

void fn_800B49D0(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) | 8);
}

void fn_800B49E0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, s32 *, 0x7C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x80) = arg2;
    M2C_FIELD(arg0, s32 *, 0x84) = arg3;
    M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) | 1);
    M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) & 0xFFFFFFFD);
    M2C_FIELD(arg0, s32 *, 0x8C) = arg4;
    M2C_FIELD(arg0, s32 *, 0x88) = 0;
}

s32 fn_800B4A14(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s32 *, 0x7C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x80) = arg2;
    M2C_FIELD(arg0, s32 *, 0x84) = arg3;
    M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) | 1);
    M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) & 0xFFFFFFFD);
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    M2C_FIELD(arg0, s32 *, 0x88) = 0;
loop_1:
    if (!(M2C_FIELD(arg0, u16 *, 0x90) & 2)) {
        OS_YieldThread();
        goto loop_1;
    }
    return M2C_FIELD(arg0, s32 *, 0x74);
}

extern u16 lbl_8028D0FC[];
s32 fn_800B4A84(void* arg0, s32 arg1, s32 arg2) {
    s32 r31_2 = (s32)arg1;
    s32 r31_3 = (r31_2 & 0x7F);
    s32 r31_5 = r31_2 >> 7;
    s32 r31_4 = lbl_8028D544[r31_3];
    if (r31_4 == 0) {
        *(u16*)arg0 = lbl_8028D0FC[(s32)(r31_5)];
    } else {
        *(u16*)arg0 = r31_4;
    }
}

#pragma global_optimizer off
#pragma use_lmw_stmw on
void fn_800B4C20(void) {
    void *memset(void *, s32, u32);
    void *memcpy(void *, const void *, u32);
    void fn_800B50FC(u8 **, u32);
    s32 fn_8020C79C(void *);
    s32 fn_8020CC28(void *, s32, s32, s32, s32);
    void OSReport(void *, ...);
    s32 fn_800B4FF8(u8 *, u8 *);
    extern u8 *lbl_80367820;
    extern u8 *lbl_8031DEC0[];
    extern u8 lbl_8031FEC0[];
    extern void (*lbl_80367824)(void);
    extern s32 (*lbl_80367828)(u8 *,u8 *);
    extern u8 lbl_8026EC50[];
    u8 list[256];
    u8 *dst, *entry, *cur, *saved;
    u8 **table, **slot, **walk;
    u32 i, n;
    s32 j, moved, size, result;
    void (*callback)(s32, void *);
    u32 count;
    count = 0;
    memset(list, 0, 256);
    {
    u8 *dst;
    u8 *entry;
    u32 i;
    dst = list;
    entry = lbl_80367820;
    for (i = 0; i < 256; i++) {
        if (*(u16 *)(entry + 0x90) & 0x8000) {
            *dst = i;
            count++;
            dst++;
        }
        entry += 0x98;
    }
    }
    lbl_80367828 = fn_800B4FF8;
    {
    u32 i, n;
    u8 *dst, *cur, *saved;
    u8 **slot, **walk, **table;
    table = lbl_8031DEC0;
    n = count;
    saved = lbl_8031FEC0;
    if (count > 1) {
        walk = table;
        cur = list;
        for (i = count; (s32)i > 0; i--) {
            *walk++ = cur++;
        }
        fn_800B50FC(table, n);
        walk = table;
        cur = list;
        i = 0;
        while (i++ < n) {
            if (*walk != 0) {
                slot = walk;
                if (*walk != cur) {
                dst = cur;
                memcpy(saved, cur, 1);
                do {
                    memcpy(dst, *slot, 1);
                    dst = *slot;
                    *slot = 0;
                    slot = table + (dst - list);
                } while (*slot != cur);
                memcpy(dst, saved, 1);
                *slot = 0;
                }
            }
            cur++;
            walk++;
        }
    }
    }
    cur = list;
    for (j = 0; j < (s32)count; j++, cur++) {
        moved = 0;
        entry = lbl_80367820 + *cur * 0x98;
        if (!(*(u16 *)(entry + 0x90) & 0x80) && (*(u16 *)(entry + 0x90) & 1)) {
            size = *(s32 *)(entry + 0x80);
            if (*(u16 *)(entry + 0x92) != 0 && size > 0x40000) size = 0x40000;
            result = fn_8020CC28(entry + 0x40, *(s32 *)(entry + 0x7C), size, *(s32 *)(entry + 0x84) + *(s32 *)(entry + 0x88), 2);
            if (result == -3) {
                *(u16 *)(entry + 0x90) &= ~1;
                *(u16 *)(entry + 0x90) |= 2;
                callback = *(void (**)(s32,void *))(entry + 0x8C);
                if (callback) callback(result, entry + 0x40);
            } else if (result < 0) {
                OSReport(lbl_8026EC50, entry);
                *(u16 *)(entry + 0x90) |= 0x20;
                *(u16 *)(entry + 0x90) |= 0x80;
            } else {
                *(s32 *)(entry + 0x80) -= size;
                *(s32 *)(entry + 0x88) += size;
                *(s32 *)(entry + 0x7C) += size;
                if (*(s32 *)(entry + 0x80) == 0) {
                    *(u16 *)(entry + 0x90) &= ~1;
                    *(u16 *)(entry + 0x90) |= 2;
                    callback = *(void (**)(s32,void *))(entry + 0x8C);
                    if (callback) callback(result, entry + 0x40);
                }
                moved = 1;
            }
        }
        if (*(u16 *)(entry + 0x90) & 8) {
            if (fn_8020C79C(entry + 0x40) == 0) OSReport(lbl_8026EC50 + 0x1E, entry);
            memset(entry, 0, 0x98);
        }
        if (moved) goto done;

    }
done:
    if (lbl_80367824) lbl_80367824();
}
#pragma global_optimizer reset
extern u8 *lbl_80367820;
s32 fn_800B4FF8(u8 *arg0, u8 *arg1) {
    u8 *temp_r4;
    u8 temp_r3;
    u8 temp_r0_2;

    temp_r4 = lbl_80367820 + 0x92;
    temp_r3 = *(u16*)(temp_r4 + (*arg0 * 0x98));
    temp_r0_2 = *(u16*)(temp_r4 + (*arg1 * 0x98));
    if (temp_r3 > temp_r0_2) {
        return 1;
    }
    if (temp_r3 < temp_r0_2) {
        return -1;
    }
    return 0;
}

void fn_800B503C(void) {
    void *fn_800C4638(s32, void *, s32);
    void *memset(void *, s32, u32);
    s32 fn_8020A558(void *, void *, s32, void *, s32, s32, s32);
    void fn_8020A9E0(void *);
    void OSReport(char *, ...);
    void fn_800B50E4(void);
    extern u8 lbl_8026EC50[];
    extern u8 *lbl_80367820;
    extern u8 lbl_80319EC0[];
    extern u8 lbl_80319BA8[];
    void *ptr;

    ptr = fn_800C4638(0x9800, lbl_8026EC50 + 0x3A, 0);
    lbl_80367820 = ptr;
    memset(ptr, 0, 0x9800);
    if (fn_8020A558(lbl_80319BA8, fn_800B50E4, 0, lbl_80319EC0 + 0x4000, 0x4000, 0x10, 1) == 0) {
        OSReport((char *)(lbl_8026EC50 + 0x3B));
        for (;;) {
        }
    }
    fn_8020A9E0(lbl_80319BA8);
}

void fn_800B50E4(void) {
    M2C_UNK fn_800B4C20();
    M2C_UNK OS_YieldThread();
loop_1:
    fn_800B4C20();
    OS_YieldThread();
    goto loop_1;
}

#pragma use_lmw_stmw on
void fn_800B50FC(u8 **arg0, u32 arg1) {
    extern s32 (*lbl_80367828)(u8 *, u8 *);
    extern u8 **lbl_8036782C;
    extern u8 **lbl_80367830;
    extern u8 **lbl_80367834;
    extern u8 **lbl_80367838;
    extern u8 *lbl_8036783C;

    u8 **base;
    u32 n;
    u8 **last;
    u8 **mid;
    u8 **left;
    u8 **right;
    u8 **pivot;
    s32 cmp;
    u32 bit;
    s32 shift;
    s32 pos;
    u32 mask;
    u32 stride;
    u32 half;
    s32 step;
    u32 left_n;

    base = arg0;
    n = arg1;

loop:
    last = base + (n - 1);
    lbl_80367838 = last;
    if (n == 2) {
        if (lbl_80367828(*base, *last) > 0) {
            lbl_8036783C = *base;
            *base = *lbl_80367838;
            *lbl_80367838 = lbl_8036783C;
        }
    } else if (n == 4) {
        lbl_8036782C = base;
        mid = last;
        lbl_80367834 = last;
        lbl_80367830 = last - 1;
        goto partition;
    } else if (n < 0x28U) {
        mid = base + (n >> 1);
        if (lbl_80367828(*base, *last) > 0) {
            if (lbl_80367828(*base, *mid) < 0) {
                lbl_8036783C = *lbl_80367838;
                *lbl_80367838 = *mid;
                *mid = *base;
                *base = lbl_8036783C;
            } else if (lbl_80367828(*mid, *lbl_80367838) < 0) {
                lbl_8036783C = *base;
                *base = *mid;
                *mid = *lbl_80367838;
                *lbl_80367838 = lbl_8036783C;
            } else {
                lbl_8036783C = *base;
                *base = *lbl_80367838;
                *lbl_80367838 = lbl_8036783C;
            }
        } else if (lbl_80367828(*base, *mid) > 0) {
            lbl_8036783C = *base;
            *base = *mid;
            *mid = lbl_8036783C;
        } else if (lbl_80367828(*mid, *lbl_80367838) > 0) {
            lbl_8036783C = *mid;
            *mid = *lbl_80367838;
            *lbl_80367838 = lbl_8036783C;
        }
        if (n != 3) {
            lbl_8036782C = base + 1;
            lbl_80367834 = lbl_80367838;
            lbl_80367830 = lbl_80367838 - 1;
            goto partition;
        }
    } else {
        mask = 0xFFFFFFFFU;
        shift = 0x20;
        pos = 0x3F;
        do {
            step = shift >> 1;
            bit = mask & n;
            half = 1;
            if (step != 0) {
                half = (u32)step;
            }
            mask &= mask << half;
            if (bit != 0) {
                pos -= shift;
            }
            if (bit == 0) {
                mask >>= shift;
            }
            shift = step;
        } while (mask != 0);
        {
            s32 t = 0x20 - pos;
            s32 c = t;
            /* subfc/subfe/andc idiom for (t >= 0) ? t : 0 roughly via carry */
            {
                s32 a = 0x20 - pos;
                s32 b = -(0x20 - pos);
                /* match: subfc r0,r5,r0; subfe r3,r0,r0; subfic r0,r5,0x20; andc r3,r0,r3 */
                s32 x = 0x20 - pos;
                s32 y = (0x20 - pos);
                /* simpler: use clz-style result */
                c = pos <= 0x20 ? (0x20 - pos) : 0;
            }
            half = n >> (c >> 1);
            if (c & 1) {
                half = 1U << (c >> 1);
            }
            stride = n / half;
            left = base;
            lbl_80367838 = base + (half - 1) * stride;
            mid = base + ((s32)((half >> 31) + half) >> 1) * stride;
            step = (s32)(stride * 4); /* unused; use pointer stride */
        }
        for (;;) {
            lbl_8036782C = left;
            lbl_80367834 = lbl_80367838;
            lbl_80367830 = lbl_80367838;
            pivot = left + stride * (((u32)((((u32)(lbl_80367838 - left) >> 31) + (lbl_80367838 - left)) >> 1)) / stride);
            for (;;) {
                while (lbl_80367830 >= lbl_8036782C) {
                    cmp = lbl_80367828(*lbl_80367830, *pivot);
                    if (cmp > 0) {
                        lbl_80367834 = lbl_80367830;
                        lbl_80367830 -= stride;
                        continue;
                    }
                    if (cmp >= 0) {
                        lbl_80367830 -= stride;
                        continue;
                    }
                    break;
                }
                if (lbl_80367830 < lbl_8036782C) {
                    break;
                }
                for (;;) {
                    if (lbl_8036782C >= lbl_80367830) {
                        break;
                    }
                    cmp = lbl_80367828(*lbl_8036782C, *pivot);
                    if (cmp >= 0) {
                        lbl_8036783C = *lbl_8036782C;
                        *lbl_8036782C = *lbl_80367830;
                        *lbl_80367830 = lbl_8036783C;
                        if (cmp > 0) {
                            lbl_80367834 = lbl_80367830;
                        }
                        if (((u32)(-cmp & ~cmp) >> 31) == 0) {
                            pivot = lbl_80367830;
                        }
                        lbl_8036782C += stride;
                        lbl_80367830 -= stride;
                        break;
                    }
                    lbl_8036782C += stride;
                }
                if (lbl_8036782C >= lbl_80367830) {
                    break;
                }
            }
            if (lbl_80367834 < pivot) {
                lbl_8036783C = *lbl_80367834;
                *lbl_80367834 = *pivot;
                *pivot = lbl_8036783C;
                lbl_80367834 += stride;
            }
            if (lbl_80367834 <= mid) {
                left = lbl_80367834;
            } else if (lbl_80367830 >= mid) {
                lbl_80367838 = lbl_80367830;
            } else {
                break;
            }
            if (left >= lbl_80367838) {
                break;
            }
        }
        lbl_8036782C = base;
        lbl_80367838 = last;
        lbl_80367834 = last;
        lbl_80367830 = last;
partition:
        for (;;) {
            while (lbl_80367830 >= lbl_8036782C) {
                cmp = lbl_80367828(*lbl_80367830, *mid);
                if (cmp > 0) {
                    lbl_80367834 = lbl_80367830;
                    lbl_80367830 -= 1;
                    continue;
                }
                if (cmp >= 0) {
                    lbl_80367830 -= 1;
                    continue;
                }
                break;
            }
            if (lbl_80367830 < lbl_8036782C) {
                break;
            }
            for (;;) {
                if (lbl_8036782C >= lbl_80367830) {
                    break;
                }
                cmp = lbl_80367828(*lbl_8036782C, *mid);
                if (cmp >= 0) {
                    lbl_8036783C = *lbl_8036782C;
                    *lbl_8036782C = *lbl_80367830;
                    *lbl_80367830 = lbl_8036783C;
                    if (cmp > 0) {
                        lbl_80367834 = lbl_80367830;
                    }
                    if (((u32)(-cmp & ~cmp) >> 31) == 0) {
                        mid = lbl_80367830;
                    }
                    lbl_8036782C += 1;
                    lbl_80367830 -= 1;
                    break;
                }
                lbl_8036782C += 1;
            }
            if (lbl_8036782C >= lbl_80367830) {
                break;
            }
        }
        if (lbl_80367834 < mid) {
            lbl_8036783C = *lbl_80367834;
            lbl_80367834 += 1;
            *lbl_80367834; /* keep order */
            {
                u8 **t = lbl_80367834 - 1;
                *t = *mid;
                *mid = lbl_8036783C;
            }
        }
        {
            u8 **p30 = lbl_80367830;
            u8 **p34 = lbl_80367834;
            if ((s32)(p30 - base) < (s32)(lbl_80367838 - p34)) {
                lbl_80367830 = base;
                base = p34;
                lbl_8036782C = p30;
            } else {
                lbl_8036782C = lbl_80367838;
                lbl_80367838 = p30;
                lbl_80367830 = p34;
            }
        }
        n = (u32)(lbl_80367838 - base) + 1;
        if (lbl_8036782C > lbl_80367830) {
            fn_800B50FC(lbl_80367830, (u32)(lbl_8036782C - lbl_80367830) + 1);
        }
        if (n > 1U) {
            goto loop;
        }
    }
}

void fn_800B5708(void) {
    void Script_RegisterCommand(void *, void *, s32);
    void Script_RegisterWinCondCommands(void);
    extern u8 lbl_8026ECB8[];
    void fn_800BAD9C(void);
    void fn_800BAE4C(void);
    void fn_800BAB64(void);
    void fn_800BACCC(void);
    void fn_800BABFC(void);
    void fn_800BAAD4(void);
    void fn_800BA9BC(void);
    void fn_800BA8F8(void);
    void fn_800BA784(void);
    void fn_800BA75C(void);
    void fn_800BA638(void);
    void fn_800BA69C(void);
    void fn_800BB0B4(void);
    void fn_800BB080(void);
    void fn_800BB04C(void);
    void fn_800BB018(void);
    void fn_800BAFE4(void);
    void fn_800BAEAC(void);
    void fn_800BAF1C(void);
    void fn_800BAEF8(void);
    void fn_800BAF80(void);
    void fn_800BA5AC(void);
    void fn_800BA528(void);
    void fn_800BA4A8(void);
    void ScriptCmd_SetPos(void);
    void fn_800B9B58(void);
    void fn_800B9A9C(void);
    void fn_800B9A34(void);
    void fn_800B9C14(void);
    void fn_800B9C38(void);
    void fn_800B99B8(void);
    void fn_800B98B8(void);
    void fn_800B983C(void);
    void fn_800B97B8(void);
    void fn_800B9724(void);
    void ScriptCmd_PlayEffect(void);
    void fn_800B95B4(void);
    void fn_800B9548(void);
    void fn_800B94CC(void);
    void fn_800B9450(void);
    void fn_800B93D4(void);
    void fn_800B9368(void);
    void fn_800B92EC(void);
    void fn_800B9258(void);
    void fn_800B91AC(void);
    void fn_800B9130(void);
    void fn_800B90C4(void);
    void fn_800BA438(void);
    void fn_800BA38C(void);
    void ScriptCmd_SoundSetParam(void);
    void fn_80108FA8(void);
    void fn_800BA230(void);
    void fn_8005BB2C(void);
    void fn_800B6E8C(void);
    void fn_800B9060(void);
    void fn_800B8FFC(void);
    void fn_8006F014(void);
    void fn_8006F00C(void);
    void fn_800B8E5C(void);
    void fn_800B8DE4(void);
    void fn_800B8D54(void);
    void fn_800B8D34(void);
    void fn_800B8F98(void);
    void fn_800B8ED0(void);
    void fn_800B8EBC(void);
    void fn_800B8CB0(void);
    void fn_800B8C34(void);
    void fn_800B8BA8(void);
    void fn_800B8B24(void);
    void fn_800B8AFC(void);
    void fn_800B8AD8(void);
    void fn_800B8A5C(void);
    void fn_800B8A28(void);
    void fn_800B8A04(void);
    void fn_800B8974(void);
    void fn_800B88E8(void);
    void fn_800B88C4(void);
    void fn_800B8894(void);
    void fn_800B8864(void);
    void fn_800B8840(void);
    void fn_800B87B4(void);
    void fn_800B8790(void);
    void fn_800B874C(void);
    void fn_800B870C(void);
    void fn_800B861C(void);
    void fn_800B85EC(void);
    void fn_800B8534(void);
    void fn_800B850C(void);
    void ScriptCmd_Battle(void);
    void fn_800B8070(void);
    void fn_800B7FD8(void);
    void fn_800B7F98(void);
    void fn_800B7EF8(void);
    void fn_800B7E60(void);
    void fn_800B7DB4(void);
    void fn_800B7D08(void);
    void fn_800B7C4C(void);
    void fn_800B7C28(void);
    void fn_800B7C04(void);
    void fn_800B7A80(void);
    void fn_800B7A2C(void);
    void fn_800B7A08(void);
    void fn_800B79E4(void);
    void fn_800B79B4(void);
    void fn_800B7990(void);
    void fn_800B796C(void);
    void fn_800B7948(void);
    void fn_800B7828(void);
    void fn_800B7790(void);
    void fn_800B83A4(void);
    void fn_800B8340(void);
    void fn_800B82D8(void);
    void fn_800B8298(void);
    void fn_800B8250(void);
    void fn_800B7938(void);
    void fn_800B790C(void);
    void fn_800B78F0(void);
    void fn_800B78D4(void);
    void fn_800B81C0(void);
    void fn_800B8198(void);
    void fn_800B812C(void);
    void fn_800B8174(void);
    void fn_800B8150(void);
    void fn_800B8108(void);
    void fn_800B76D0(void);
    void fn_800B7658(void);
    void fn_80089524(void);
    void fn_800894F8(void);
    void fn_800B7580(void);
    void fn_800B74AC(void);
    void fn_800B7410(void);
    void fn_800B7378(void);
    void fn_800B7210(void);
    void fn_80110094(void);
    void fn_80110048(void);
    void fn_800B72CC(void);
    void fn_800B727C(void);
    void fn_800C4384(void);
    void fn_800C0AF4(void);
    void fn_800C0AE0(void);
    void fn_800C0ACC(void);
    void fn_800B7200(void);
    void fn_800B719C(void);
    void fn_800B7140(void);
    void fn_800B70EC(void);
    void fn_800B7098(void);
    void fn_800B7044(void);
    void fn_800B6DF0(void);
    void fn_800B6DB8(void);
    void fn_800B6D88(void);
    void fn_800B6D50(void);
    void fn_800B6D20(void);
    void fn_800B6FE4(void);
    void fn_800B6CD8(void);
    void fn_800B6C6C(void);
    void fn_800B6C00(void);
    void fn_800B6B94(void);
    void fn_800B6B20(void);
    void fn_800B6AE4(void);
    void fn_800B6AA8(void);
    void fn_80016538(void);
    void fn_800B7250(void);
    void fn_80023DC0(void);
    void fn_8014C6E0(void);
    void fn_8014C6B8(void);
    void fn_800B6F10(void);
    void Card_GetResult(void);
    void fn_800C0750(void);
    void fn_800C068C(void);
    void fn_801E4540(void);
    void fn_800B6E00(void);
    void fn_800B6A70(void);
    void fn_800B6A38(void);
    void fn_800B6A30(void);

    Script_RegisterCommand(lbl_8026ECB8 + 0x1A3, fn_800BAD9C, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x1A9, fn_800BAE4C, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x1B6, fn_800BAB64, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x1C0, fn_800BACCC, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x1CA, fn_800BABFC, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x1D8, fn_800BAAD4, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x1EA, fn_800BA9BC, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x1F9, fn_800BA8F8, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x204, fn_800BA784, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x212, fn_800BA75C, 3);
    Script_RegisterCommand(lbl_8026ECB8 + 0x21D, fn_800BA638, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x22A, fn_800BA69C, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x22E, fn_800BB0B4, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x235, fn_800BB080, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x23C, fn_800BB04C, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x240, fn_800BB018, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x244, fn_800BAFE4, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x248, fn_800BAEAC, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x252, fn_800BAF1C, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x25C, fn_800BAEF8, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x267, fn_800BAF80, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x277, fn_800BA5AC, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x281, fn_800BA528, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x28B, fn_800BA4A8, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x294, ScriptCmd_SetPos, 3);
    Script_RegisterCommand(lbl_8026ECB8 + 0x29F, fn_800B9B58, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x2AA, fn_800B9A9C, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x2B6, fn_800B9A34, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x2C8, fn_800B9C14, 5);
    Script_RegisterCommand(lbl_8026ECB8 + 0x2D7, fn_800B9C38, 6);
    Script_RegisterCommand(lbl_8026ECB8 + 0x2E0, fn_800B99B8, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x2F0, fn_800B98B8, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x300, fn_800B983C, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x30D, fn_800B97B8, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x31E, fn_800B9724, 3);
    Script_RegisterCommand(lbl_8026ECB8 + 0x32F, ScriptCmd_PlayEffect, 6);
    Script_RegisterCommand(lbl_8026ECB8 + 0x33B, fn_800B95B4, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x348, fn_800B9548, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x358, fn_800B94CC, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x365, fn_800B9450, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x37B, fn_800B93D4, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x389, fn_800B9368, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x39A, fn_800B92EC, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x3AE, fn_800B9258, 3);
    Script_RegisterCommand(lbl_8026ECB8 + 0x3C3, fn_800B91AC, 5);
    Script_RegisterCommand(lbl_8026ECB8 + 0x3D2, fn_800B9130, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x3E2, fn_800B90C4, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x3F5, fn_800BA438, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x3FD, fn_800BA38C, 3);
    Script_RegisterCommand(lbl_8026ECB8 + 0x405, ScriptCmd_SoundSetParam, 6);
    Script_RegisterCommand(lbl_8026ECB8 + 0x412, fn_80108FA8, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x41E, fn_800BA230, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x431, fn_8005BB2C, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x439, fn_800B6E8C, 5);
    Script_RegisterCommand(lbl_8026ECB8 + 0x447, fn_800B9060, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x454, fn_800B8FFC, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x45B, fn_8006F014, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x468, fn_8006F00C, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x479, fn_800B8E5C, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x486, fn_800B8DE4, 3);
    Script_RegisterCommand(lbl_8026ECB8 + 0x493, fn_800B8D54, 4);
    Script_RegisterCommand(lbl_8026ECB8 + 0x4A0, fn_800B8D34, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x4AD, fn_800B8F98, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x4BC, fn_800B8ED0, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x4BF, fn_800B8EBC, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x4C3, fn_800B8CB0, 6);
    Script_RegisterCommand(lbl_8026ECB8 + 0x4CD, fn_800B8C34, 5);
    Script_RegisterCommand(lbl_8026ECB8 + 0x4DB, fn_800B8BA8, 7);
    Script_RegisterCommand(lbl_8026ECB8 + 0x4E9, fn_800B8B24, 6);
    Script_RegisterCommand(lbl_8026ECB8 + 0x4FB, fn_800B8AFC, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x50C, fn_800B8AD8, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x520, fn_800B8A5C, 5);
    Script_RegisterCommand(lbl_8026ECB8 + 0x52C, fn_800B8A28, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x531, fn_800B8A04, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x53A, fn_800B8974, 5);
    Script_RegisterCommand(lbl_8026ECB8 + 0x540, fn_800B88E8, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x54A, fn_800B88C4, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x552, fn_800B8894, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x55A, fn_800B8864, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x561, fn_800B8840, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x569, fn_800B87B4, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x572, fn_800B8790, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x579, fn_800B874C, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x582, fn_800B870C, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x58D, fn_800B861C, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x598, fn_800B85EC, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x5A5, fn_800B8534, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x5B0, fn_800B850C, 3);
    Script_RegisterCommand(lbl_8026ECB8 + 0x5BA, ScriptCmd_Battle, 3);
    Script_RegisterCommand(lbl_8026ECB8 + 0x5C7, fn_800B8070, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x5CF, fn_800B7FD8, 3);
    Script_RegisterCommand(lbl_8026ECB8 + 0x5DA, fn_800B7F98, 3);
    Script_RegisterCommand(lbl_8026ECB8 + 0x5E4, fn_800B7EF8, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x5EC, fn_800B7E60, 3);
    Script_RegisterCommand(lbl_8026ECB8 + 0x5F6, fn_800B7DB4, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x601, fn_800B7D08, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x609, fn_800B7C4C, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x611, fn_800B7C28, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x61C, fn_800B7C04, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x628, fn_800B7A80, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x632, fn_800B7A2C, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x63A, fn_800B7A08, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x645, fn_800B79E4, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x651, fn_800B79B4, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x65D, fn_800B7990, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x66A, fn_800B796C, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x675, fn_800B7948, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x681, fn_800B7828, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x687, fn_800B7790, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x68D, fn_800B83A4, 6);
    Script_RegisterCommand(lbl_8026ECB8 + 0x693, fn_800B8340, 3);
    Script_RegisterCommand(lbl_8026ECB8 + 0x69E, fn_800B82D8, 4);
    Script_RegisterCommand(lbl_8026ECB8 + 0x6A9, fn_800B8298, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x6B0, fn_800B8250, 4);
    Script_RegisterCommand(lbl_8026ECB8 + 0x6B8, fn_800B7938, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x6C0, fn_800B790C, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x6C7, fn_800B78F0, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x6CC, fn_800B78D4, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x6D3, fn_800B81C0, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x6E4, fn_800B8198, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x6F2, fn_800B812C, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x700, fn_800B8174, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x712, fn_800B8150, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x723, fn_800B8108, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x733, fn_800B76D0, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x73D, fn_800B7658, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x74E, fn_80089524, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x75F, fn_800894F8, 0);
    Script_RegisterWinCondCommands();
    Script_RegisterCommand(lbl_8026ECB8 + 0x76E, fn_800B7580, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x778, fn_800B74AC, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x78F, fn_800B7410, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x798, fn_800B7378, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x7AB, fn_800B7210, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x7BB, fn_80110094, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x7C4, fn_80110048, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x7CE, fn_800B72CC, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x7D6, fn_800B727C, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x7DD, fn_800C4384, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x7E7, fn_800C0AF4, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x7F0, fn_800C0AE0, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x7FC, fn_800C0ACC, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x807, fn_800B7200, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x80D, fn_800B719C, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x81D, fn_800B7140, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x822, fn_800B70EC, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x838, fn_800B7098, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x84B, fn_800B7044, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x85E, fn_800B6DF0, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x86E, fn_800B6DB8, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x87C, fn_800B6D88, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x88C, fn_800B6D50, 2);
    Script_RegisterCommand(lbl_8026ECB8 + 0x89A, fn_800B6D20, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x8AA, fn_800B6FE4, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x8BA, fn_800B6CD8, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x8C1, fn_800B6C6C, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x8CB, fn_800B6C00, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x8D5, fn_800B6B94, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x193, fn_800B6B20, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x8E9, fn_800B6AE4, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x8F4, fn_800B6AA8, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x8FF, fn_80016538, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x904, fn_800B7250, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x913, fn_80023DC0, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x91D, fn_8014C6E0, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x922, fn_8014C6B8, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x927, fn_800B6F10, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x92D, Card_GetResult, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x936, fn_800C0750, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x943, fn_800C068C, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x94F, fn_801E4540, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x95E, fn_800B6E00, 1);
    Script_RegisterCommand(lbl_8026ECB8 + 0x969, fn_800B6A70, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x975, fn_800B6A38, 0);
    Script_RegisterCommand(lbl_8026ECB8 + 0x97F, fn_800B6A30, 0);
}

#pragma use_lmw_stmw reset

s32 fn_800B6A30(void) {
    return 0;
}

s32 fn_800B6A38(void) {
    void Pad_ClearDisableMask(s32, s32);
    extern s32 gPadInput;
    extern s32 gUiInputFlags;

    Pad_ClearDisableMask(gPadInput, 0x1F70);
    gUiInputFlags &= ~0x2000;
    return 1;
}

s32 fn_800B6A70(void) {
    void Pad_SetDisableMask(s32, s32);
    extern s32 gPadInput;
    extern s32 gUiInputFlags;

    Pad_SetDisableMask(gPadInput, 0x1F70);
    gUiInputFlags |= 0x2000;
    return 1;
}

s32 fn_800B6AA8(s32 arg0) {
    extern f32 lbl_80369CF4;
    return (s32) (lbl_80369CF4 * (f32) arg0);
}

s32 fn_800B6AE4(s32 arg0)
{
    extern f32 lbl_80369CF4;
    return (s32)((f32)arg0 / lbl_80369CF4);
}

s32 fn_800B6B20(void)
{
    s32 fn_800C0658(void);
    void Process_CreateChild(u16 *, s32);
    void fn_80013864(void);
    extern u16 lbl_8028D298[];

    Process_CreateChild(lbl_8028D298, fn_800C0658());
    fn_80013864();
    return 1;
}

void fn_800B6B58(s32 arg0) {
    extern void *gPadInput;
    s32 temp_r5;

    temp_r5 = M2C_FIELD(gPadInput, s32 *, 4);
    if (temp_r5 & (M2C_FIELD(gPadInput, s32 *, 8) ^ temp_r5) & 0x1F70) {
        Process_ClearFunc(arg0);
    }
}

extern s32 lbl_8036B3A4;
extern s32 lbl_8036B3A4;
s32 fn_800B6B94(s32 arg0) {
    M2C_UNK fn_801F89AC(s32, s32);
    extern f32 lbl_80369CF4;

    fn_801F89AC((f32) arg0 / lbl_80369CF4, fn_800C0658());
    fn_80013864();
    return 1;
}

s32 fn_800B6C00(s32 arg0) {
    M2C_UNK fn_801F9D1C(s32, s32);
    extern f32 lbl_80369CF4;

    fn_801F9D1C((f32) arg0 / lbl_80369CF4, fn_800C0658());
    fn_80013864();
    return 1;
}

s32 fn_800B6C6C(s32 arg0) {
    M2C_UNK fn_801FA4B8(s32, s32);
    extern f32 lbl_80369CF4;

    fn_801FA4B8((f32) arg0 / lbl_80369CF4, fn_800C0658());
    fn_80013864();
    return 1;
}

extern u8 lbl_8028E7F8[];
s32 fn_800B6CD8(u32 arg0) {
    void OSReport(void *, ...);
    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    OSReport((void *)arg0);
    return 1;
}

s32 fn_800B6D20(s32 arg0) {
    M2C_UNK fn_8014CC5C(void *, s32);
    extern u8 gBattleState[];

    fn_8014CC5C(gBattleState, arg0);
    return 1;
}

s32 fn_800B6D50(s32 arg0, s32 arg1) {
    M2C_UNK fn_8014CF10(void *, s8, s8);
    extern u8 gBattleState[];

    fn_8014CF10(gBattleState, arg0, arg1);
    return 1;
}

s32 fn_800B6D88(s32 arg0) {
    M2C_UNK fn_8014CF48(void *, s32);
    extern u8 gBattleState[];

    fn_8014CF48(gBattleState, arg0);
    return 1;
}

s32 fn_800B6DB8(s32 arg0, s32 arg1) {
    M2C_UNK fn_8014D204(void *, s8, s8);
    extern u8 gBattleState[];

    fn_8014D204(gBattleState, arg0, arg1);
    return 1;
}

u8 fn_800B6DF0(void) {
    extern u16 gBattleState[];
    return *(u8 *)((u8 *)gBattleState + 0x56);
}

s32 fn_800B6E00(s32 arg0) {
    void fn_8002D780(s32, void *);
    void fn_8000BD98(void *);
    void Process_UnlinkByKey(void *);
    extern u8 gBattleState[];
    extern u8 lbl_8026ECB8[];
    struct { u8 pad[0x54]; u8 f54; } *p;
    s32 var;

    var = 0;
    switch (arg0) {
    case 1:
        var = 5;
        break;
    case 2:
        var = 6;
        break;
    case 3:
        var = 7;
        break;
    }
    p = (void *)gBattleState;
    p->f54 = (u8)var;
    fn_8002D780(2, p);
    fn_8000BD98(lbl_8026ECB8 + 0x98b);
    Process_UnlinkByKey(lbl_8028E7F8);
    return 1;
}

s32 fn_800B6E8C(s32 mode, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    return (s32)Math_Ease(mode, (f32)arg1, (f32)arg2, (f32)arg3, (f32)arg4);
}

s32 fn_800B6F10(void)
{
    s32 fn_800C0658(void);
    void Process_CreateChild(u16 *, s32);
    void fn_80013864(void);
    extern u16 lbl_8028D26C[];

    Process_CreateChild(lbl_8028D26C, fn_800C0658());
    fn_80013864();
    return 1;
}

void fn_800B6F48(void) {
    M2C_UNK SaveData_Release(M2C_UNK *);
    extern M2C_UNK gSaveDataBase;
    SaveData_Release(&gSaveDataBase);
}

void fn_800B6F6C(void *arg0) {
    s32 Card_GetResult(void);
    void Process_ClearFunc(void *);
    void fn_801E047C(void *, void *);
    extern s32 gSaveDataBase;

    if (Card_GetResult() < 0) {
        Process_ClearFunc(arg0);
    } else {
        fn_801E047C(&gSaveDataBase, arg0);
    }
}

void fn_800B6FB8(s32 arg0) {
    M2C_UNK fn_801E3118(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK gSaveDataBase;
    fn_801E3118(&gSaveDataBase, arg0, 1);
}

s32 fn_800B6FE4(u32 arg0) {
    M2C_UNK fn_80013864();
    M2C_UNK fn_801EAABC(u32, s32);
    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    fn_801EAABC(arg0, fn_800C0658());
    fn_80013864();
    return 1;
}

s32 fn_800B7044(s32 arg0)
{
    void fn_8004EA60(void *, s32);
    extern u8 gUnitLists[];

    u8 *entry;
    u8 *next;

    entry = *(u8 **)(gUnitLists + arg0 * 0xC);

    while (entry != 0) {
        next = *(u8 **)(entry + 0x184);

        fn_8004EA60(entry, 0);

        entry = next;
    }

    return 1;
}

s32 fn_800B7098(s32 arg0)
{
    void fn_8004EB14(void *, s32);
    extern u8 gUnitLists[];

    u8 *entry;
    u8 *next;

    entry = *(u8 **)(gUnitLists + arg0 * 0xC);

    while (entry != 0) {
        next = *(u8 **)(entry + 0x184);

        fn_8004EB14(entry, 0);

        entry = next;
    }

    return 1;
}

s32 fn_800B70EC(s32 arg0)
{
    void fn_8004F5EC(void *, s32);
    extern u8 gUnitLists[];

    u8 *entry;
    u8 *next;

    entry = *(u8 **)(gUnitLists + arg0 * 0xC);

    while (entry != 0) {
        next = *(u8 **)(entry + 0x184);

        fn_8004F5EC(entry, 0);

        entry = next;
    }

    return 1;
}

s32 fn_800B7140(u32 arg0) {
    void fn_801070FC(u32);
    void fn_80107294(u32, s32);
    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    fn_80107294(arg0, 5);
    fn_801070FC(arg0);
    return 1;
}

u8 fn_800B719C(u8 arg0) {
    s32 fn_800F32A4(void);
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    return (u8)fn_800F32A4();
}

u8 fn_800B7200(void) {
    extern u8 lbl_8031FFC0[];
    return lbl_8031FFC0[0xa];
}

s32 fn_800B7210(void)
{
    void fn_800162B8(void);
    void fn_801A7CDC(void *);
    void fn_80016DE0(void);
    void Map_RefreshUnitMap(void *);
    extern u8 gBattle[];
    extern u8 gBattleMap[];

    fn_800162B8();
    fn_801A7CDC(gBattle);
    fn_80016DE0();
    Map_RefreshUnitMap(gBattleMap);
    return 1;
}

s32 fn_800B7250(void) {
    M2C_UNK fn_800162B8();
    M2C_UNK fn_800163F8();
    fn_800162B8();
    fn_800163F8();
    fn_80016180();
    return 1;
}

s32 fn_800B727C(void) {
    void fn_800BDED8(void *);
    void fn_800162B8(void);
    void fn_801E3654(void *, s32);
    void fn_800C4588(s32);
    extern u8 gBattleState[];
    extern s32 lbl_80367840;
    u8 sp[0x78];

    fn_800BDED8(gBattleState + 0xB4);
    fn_800162B8();
    fn_801E3654(sp, lbl_80367840);
    fn_800C4588(lbl_80367840);
    lbl_80367840 = 0;
    return 1;
}

s32 fn_800B72CC(void) {
    void fn_800162B8(void);
    void fn_80016DE0(void);
    void Map_RefreshUnitMap(void *);
    void fn_800BDED8(void *);
    void fn_800C32A4(void *);
    void fn_800C341C(void *);
    s32 fn_800C4638(s32, void *, s32);
    void fn_8010FF90(void *);
    void fn_801A7CDC(void *);
    void fn_801E38E0(void *, s32);
    extern u8 lbl_8026ECB8[];
    extern u8 gBattleMap[];
    extern u8 gConvoy[];
    extern u8 gIconSlots[];
    extern u8 gMapObjEventList[];
    extern u8 gBattleState[];
    extern u8 gBattle[];
    extern s32 lbl_80367840;
    u8 sp[0x70];

    fn_801E38E0(sp, lbl_80367840 = fn_800C4638(0xA000, lbl_8026ECB8 + 0x996, 0));
    fn_800162B8();
    fn_801A7CDC(gBattle);
    fn_80016DE0();
    Map_RefreshUnitMap(gBattleMap);
    fn_800BDED8(gBattleState + 0xB4);
    fn_8010FF90(gMapObjEventList);
    fn_800C341C(gConvoy);
    fn_800C32A4(gIconSlots);
    Map_RefreshUnitMap(gBattleMap);
    return 1;
}

s32 fn_800B7378(void) {
    M2C_UNK fn_80016628(void *);
    M2C_UNK fn_800C2930(void *, void *);
    M2C_UNK fn_8017A7D4(void *, s32);
    extern u8 lbl_802842A4[];
    extern u8 lbl_802842B8[];
    extern u8 gIconSlots[];
    extern s32 lbl_80367840;
    struct {
        s32 handle;
        u8 pad4[8];
        u8 owned;
        u8 padD[3];
        void *vtbl;
    } obj;

    fn_800162B8();
    fn_8017A7D4(&obj, lbl_80367840);
    fn_80016628(&obj);
    fn_800C2930(gIconSlots, &obj);
    fn_800163F8();
    fn_80016180();
    fn_800C4588(lbl_80367840);
    lbl_80367840 = 0;
    obj.vtbl = lbl_802842B8;
    obj.vtbl = lbl_802842A4;
    if (obj.owned) {
        fn_800C4588(obj.handle);
        obj.handle = 0;
        obj.owned = 0;
    }
    return 1;
}

s32 fn_800B7410(void) {
    M2C_UNK fn_80016628(void *);
    M2C_UNK fn_800C2930(void *, void *);
    M2C_UNK fn_8017A7D4(void *, s32);
    M2C_UNK fn_80023DC0();
    extern u8 lbl_802842A4[];
    extern u8 lbl_802842B8[];
    extern u8 gIconSlots[];
    extern s32 lbl_80367840;
    struct {
        s32 handle;
        u8 pad4[8];
        u8 owned;
        u8 padD[3];
        void *vtbl;
    } obj;

    fn_800162B8();
    fn_8017A7D4(&obj, lbl_80367840);
    fn_80016628(&obj);
    fn_800C2930(gIconSlots, &obj);
    fn_80023DC0();
    fn_800163F8();
    fn_80016180();
    fn_800C4588(lbl_80367840);
    lbl_80367840 = 0;
    obj.vtbl = lbl_802842B8;
    obj.vtbl = lbl_802842A4;
    if (obj.owned) {
        fn_800C4588(obj.handle);
        obj.handle = 0;
        obj.owned = 0;
    }
    return 1;
}

s32 fn_800B74AC(void) {
    void fn_80016A3C(void *);
    void fn_800C2980(void *, void *);
    void *fn_800C4638(s32, void *, s32);
    void fn_800C4588(void *);
    extern u8 lbl_8026ECB8[];
    extern u8 lbl_802842A4[];
    extern u8 lbl_80284C98[];
    extern u8 gIconSlots[];
    extern s32 lbl_80367840;
    struct {
        void *start;
        void *cur;
        u32 size;
        u8 owned;
        u8 pad[3];
        void *vtbl;
    } w;
    u8 *pw;
    void *p;

    p = fn_800C4638(0xA000, lbl_8026ECB8 + 0x996, 0);
    pw = (u8 *)&w;
    *(void **)(pw + 16) = lbl_802842A4;
    *(void **)(pw + 4) = NULL;
    *(void **)pw = NULL;
    *(u32 *)(pw + 8) = 0;
    pw[12] = 0;
    lbl_80367840 = (s32)p;
    *(void **)(pw + 16) = lbl_80284C98;
    pw[12] = 0;
    *(void **)pw = p;
    *(void **)(pw + 4) = p;
    *(u32 *)(pw + 8) = 0x100000;
    fn_80016A3C(pw);
    fn_800C2980(gIconSlots, &w);
    w.vtbl = lbl_80284C98;
    w.vtbl = lbl_802842A4;
    if (w.owned != 0) {
        fn_800C4588(w.start);
        w.start = NULL;
        w.owned = 0;
    }
    return 1;
}

s32 fn_800B7580(void) {
void fn_80016A3C(void *);
void fn_80016DE0(void);
void fn_800C2980(void *, void *);
void *fn_800C4638(s32, void *, s32);
void fn_800C4588(void *);
extern u8 lbl_8026ECB8[];
extern u8 lbl_802842A4[];
extern u8 lbl_80284C98[];
extern u8 gIconSlots[];
extern s32 lbl_80367840;
struct { void *start; void *cur; u32 size; u8 owned; u8 pad[3]; void *vtbl; } w;
u8 *pw;
void *p;
p=fn_800C4638(0xA000,lbl_8026ECB8+0x996,0);
pw=(u8*)&w;
*(void **)(pw+16)=lbl_802842A4;
*(void **)(pw+4)=NULL;
*(void **)pw=NULL;
*(u32*)(pw+8)=0;
pw[12]=0;
lbl_80367840=(s32)p;
*(void **)(pw+16)=lbl_80284C98;
pw[12]=0;
*(void **)pw=p;
*(void **)(pw+4)=p;
*(u32*)(pw+8)=0x100000;
fn_80016A3C(pw);
fn_800C2980(gIconSlots,&w);
fn_80016DE0();
w.vtbl=lbl_80284C98;
w.vtbl=lbl_802842A4;
if(w.owned!=0) {fn_800C4588(w.start);w.start=NULL;w.owned=0;}
return 1;
}

s32 fn_800B7658(s32 arg0) {
    M2C_UNK fn_800A5D1C(void *, s32, s32);
    M2C_UNK fn_800A58F0(s32);
    M2C_UNK Process_CreateChild(void *, s32);
    extern u8 lbl_8026ECB8[];
    extern u8 lbl_8028D244[];
    extern s32 gUiInputFlags;

    if (gUiInputFlags & 1) {
        return 0;
    }
    fn_800A5D1C(lbl_8026ECB8 + 0x997, 0, 1);
    fn_800A58F0(arg0);
    Process_CreateChild(lbl_8028D244, fn_800C0658());
    fn_80013864();
    return 1;
}

s32 fn_800B76D0(u32 arg0) {
    M2C_UNK fn_800A5D1C(u32, s32, s32);
    M2C_UNK Process_CreateChild(void *, s32);
    extern u8 lbl_8028D244[];
    extern s32 gUiInputFlags;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    fn_800A5D1C(arg0, 0, 1);
    Process_CreateChild(lbl_8028D244, fn_800C0658());
    fn_80013864();
    return 1;
}

void fn_800B7748(s32 arg0) {
    u8 fn_800A5C88(void);
    extern s32 gUiInputFlags;

    if (fn_800A5C88() == 0 || (gUiInputFlags & 1)) {
        Process_ClearFunc(arg0);
    }
}

s32 fn_800B7790(s32 arg0) {
    M2C_UNK Process_CreateChild(void *, s32);
    extern u8 lbl_8028D22C[];
    extern s32 gUiInputFlags;
    extern f32 lbl_80369CF4;
    void *obj;
    s32 count;

    fn_80013864();
    if (gUiInputFlags & 1) {
        return 0;
    }
    count = (f32) arg0 / lbl_80369CF4;
    if (count > 1) {
        obj = (void *) Process_CreateChild(lbl_8028D22C, fn_800C0658());
        M2C_FIELD(obj, s32 *, 0x60) = count - 1;
    }
    return 1;
}

s32 fn_800B7828(s32 arg0) {
    M2C_UNK Process_CreateChild(void *, s32);
    extern u8 lbl_8028D22C[];
    extern s32 gUiInputFlags;
    void *obj;

    fn_80013864();
    if (gUiInputFlags & 1) {
        return 0;
    }
    if (arg0 > 1) {
        obj = (void *) Process_CreateChild(lbl_8028D22C, fn_800C0658());
        M2C_FIELD(obj, s32 *, 0x60) = arg0 - 1;
    }
    return 1;
}

void fn_800B7890(void *arg0) {
    extern s32 gUiInputFlags;

    M2C_FIELD(arg0, s32 *, 0x60) = M2C_FIELD(arg0, s32 *, 0x60) - 1;
    if (M2C_FIELD(arg0, s32 *, 0x60) < 0 || (gUiInputFlags & 1)) {
        Process_ClearFunc(arg0);
    }
}

u8 fn_800B78D4(void) {
    extern u8 gBattleState[];
    return gBattleState[0xA6] == 2;
}

u8 fn_800B78F0(void) {
    extern u8 gBattleState[];
    return gBattleState[0xA6] == 1;
}

u8 fn_800B790C(void) {
    extern u8 gBattleState[];
    s32 state;

    state = gBattleState[0xA6];
    return state == 0 || state == 3;
}

u8 fn_800B7938(void) {
    extern u8 gBattleState[];
    return gBattleState[0xA6];
}

s32 fn_800B7948(void) {
    M2C_UNK fn_801453F0();
    fn_801453F0();
    return 1;
}

s32 fn_800B796C(void) {
    M2C_UNK fn_80145488();
    fn_80145488();
    return 1;
}

s32 fn_800B7990(void) {
    M2C_UNK fn_80145520();
    fn_80145520();
    return 1;
}

s32 fn_800B79B4(s32 arg0) {
    M2C_UNK fn_801455B8(s32);
    s32 var_r3;

    var_r3 = arg0;
    if (var_r3 < 0) {
        var_r3 = 0;
    }
    fn_801455B8(var_r3);
    return 1;
}

s32 fn_800B79E4(void) {
    M2C_UNK fn_80145684();
    fn_80145684();
    return 1;
}

s32 fn_800B7A08(void) {
    M2C_UNK fn_8014571C();
    fn_8014571C();
    return 1;
}

s32 fn_800B7A2C(u32 arg0) {
    M2C_UNK Ui_PlaySeCue(u32, s32);
    extern s32 gUiInputFlags;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (!(gUiInputFlags & 3)) {
        Ui_PlaySeCue(arg0, 100);
    }
    return 1;
}

#pragma cplusplus on
extern "C" s32 fn_800B7A80(void) {
    struct Obj {
        u8 pad[8];
        virtual u8 v0() = 0;
        u8 flag;
        u8 pad2[0x23];
    };
    extern Obj gFxChannels;
    void fn_801457B4(void);
    void Fx_FadeIn(void *, s32);
    void fn_80146AF0(void);
    void fn_8014876C(void *, s32, s32);
    void fn_80148980(void *, s32);

    Obj *obj;
    u8 ok;

    fn_801457B4();

    ok = 0;
    obj = &gFxChannels;
    if (obj->flag & 1) {
        if (obj->v0()) {
            ok = 1;
        }
    }
    if (ok) {
        Fx_FadeIn(obj, 0xC8);
    }
    fn_80146AF0();
    fn_8014876C(obj, 0x64, 0xC8);

    ok = 0;
    obj = (Obj *)((u8 *)&gFxChannels + 0x30);
    if (*((u8 *)&gFxChannels + 0x3C) & 1) {
        if (obj->v0()) {
            ok = 1;
        }
    }
    if (ok) {
        fn_80148980(obj, 0xC8);
    }

    ok = 0;
    obj = (Obj *)((u8 *)&gFxChannels + 0x60);
    if (*((u8 *)&gFxChannels + 0x6C) & 1) {
        if (obj->v0()) {
            ok = 1;
        }
    }
    if (ok) {
        fn_80148980(obj, 0xC8);
    }

    ok = 0;
    obj = (Obj *)((u8 *)&gFxChannels + 0x90);
    if (*((u8 *)&gFxChannels + 0x9C) & 1) {
        if (obj->v0()) {
            ok = 1;
        }
    }
    if (ok) {
        fn_80148980(obj, 0xC8);
    }

    return 1;
}
#pragma cplusplus reset
s32 fn_800B7C04(void) {
    M2C_UNK fn_801457B4();
    fn_801457B4();
    return 1;
}

s32 fn_800B7C28(void) {
    M2C_UNK fn_80145828();
    fn_80145828();
    return 1;
}

#pragma cplusplus on
extern "C" s32 fn_800B7C4C(s32 arg0, s32 arg1) {
    struct Obj {
        u8 pad[8];
        virtual u8 v0() = 0;
        u8 flag;
        u8 pad2[0x23];
    };
    extern Obj gFxChannels[];
    void fn_80146AF0(void);
    void fn_8014876C(void *, s32, s16);
    void Fx_FadeIn(void *, s16);
    u8 ok;
    Obj *obj;

    ok = 0;
    obj = &gFxChannels[(u8)arg0];
    if (obj->flag & 1) {
        if (obj->v0()) {
            ok = 1;
        }
    }
    if (ok) {
        Fx_FadeIn(obj, (s16)arg1);
    }
    if (arg0 == 0) {
        fn_80146AF0();
        fn_8014876C(obj, 0x64, (s16)arg1);
    }
    return 1;
}

extern "C" s32 fn_800B7D08(s32 arg0, s32 arg1) {
    struct Obj {
        u8 pad[8];
        virtual u8 v0() = 0;
        u8 flag;
        u8 pad2[0x23];
    };
    extern Obj gFxChannels[];
    void fn_80146B00(void);
    void Fx_FadeOut(void *, s16);
    u8 ok;
    Obj *obj;

    ok = 0;
    obj = &gFxChannels[(u8)arg0];
    if (obj->flag & 1) {
        if (obj->v0()) {
            ok = 1;
        }
    }
    if (ok) {
        Fx_FadeOut(obj, (s16)arg1);
    }
    if (arg0 == 0) {
        fn_80146B00();
    }
    return 1;
}

extern "C" s32 fn_800B7DB4(s32 arg0, s32 arg1) {
    struct Obj {
        u8 pad[8];
        virtual u8 v0() = 0;
        u8 flag;
        u8 pad2[0x23];
    };
    extern Obj gFxChannels[];
    void fn_80146B00(void);
    void fn_80148980(void *, s16);
    u8 ok;
    Obj *obj;

    ok = 0;
    obj = &gFxChannels[(u8)arg0];
    if (obj->flag & 1) {
        if (obj->v0()) {
            ok = 1;
        }
    }
    if (ok) {
        fn_80148980(obj, (s16)arg1);
    }
    if (arg0 == 0) {
        fn_80146B00();
    }
    return 1;
}

#pragma cplusplus reset
s32 fn_800B7E60(s32 arg0, u32 arg1, s32 arg2) {
    void Fx_StartSlot(s32, void *, s32, s32);
    void DebugPrint(void *, ...);
    void fn_80146AF0(void);
    extern s32 gUiInputFlags;
    extern u8 lbl_8026ECB8[];

    if ((arg1 < 0x80000000U) || (arg1 >= 0x81800000U)) {
        return 0;
    }
    if (!(gUiInputFlags & 3)) {
        Fx_StartSlot((u8)arg0, (void *)arg1, 0x64, arg2);
        DebugPrint(lbl_8026ECB8 + 0x9A9, arg1);
    }
    if (arg0 == 0) {
        fn_80146AF0();
    }
    return 1;
}

#pragma cplusplus on
extern "C" s32 fn_800B7EF8(s32 arg0) {
    struct Obj {
        u8 pad[8];
        virtual u8 v0() = 0;
        u8 flag;
        u8 pad2[0x23];
    };
    extern Obj gFxChannels[];
    void fn_80146B00(void);
    void fn_80148980(void *, s32);
    u8 ok;
    Obj *obj;

    ok = 0;
    obj = &gFxChannels[(u8)arg0];
    if (obj->flag & 1) {
        if (obj->v0()) {
            ok = 1;
        }
    }
    if (ok) {
        fn_80148980(obj, 1);
    }
    if (arg0 == 0) {
        fn_80146B00();
    }
    return 1;
}
#pragma cplusplus reset

s32 fn_800B7F98(s32 arg0, s32 arg1, s32 arg2) {
    void fn_8014876C(void *, u8, s16);
    extern u8 gFxChannels[];

    fn_8014876C(gFxChannels + (u8)arg0 * 0x30, (u8)arg1, (s16)arg2);
    return 1;
}

s32 fn_800B7FD8(s32 arg0, u32 arg1, s32 arg2) {
    extern s32 gUiInputFlags;
    extern u8 lbl_8026ECB8[];
    void Fx_StartSlot(u8, u32, u8, s32);
    void DebugPrint(void *, ...);
    void fn_80146AF0(void);

    if ((arg1 < 0x80000000U) || (arg1 >= 0x81800000U)) {
        return 0;
    }
    if (!(gUiInputFlags & 3)) {
        Fx_StartSlot((u8)arg0, arg1, (u8)arg2, 1);
        DebugPrint(lbl_8026ECB8 + 0x9d4, arg1);
    }
    if (arg0 == 0) {
        fn_80146AF0();
    }
    return 1;
}

s32 fn_800B8070(s32 arg0, u32 arg1) {
    extern s32 gUiInputFlags;
    extern u8 lbl_8026ECB8[];
    void Fx_StartSlot(u8, u32, u8, s32);
    void DebugPrint(void *, ...);
    void fn_80146AF0(void);

    if ((arg1 < 0x80000000U) || (arg1 >= 0x81800000U)) {
        return 0;
    }
    if (!(gUiInputFlags & 3)) {
        Fx_StartSlot((u8)arg0, arg1, 0x64, 1);
        DebugPrint(lbl_8026ECB8 + 0xa00, arg1);
    }
    if (arg0 == 0) {
        fn_80146AF0();
    }
    return 1;
}

s32 fn_800B8108(void) {
    M2C_UNK fn_8016B5E8();
    fn_8016B5E8();
    return 1;
}

s32 fn_800B812C(void) {
    M2C_UNK fn_8016B68C();
    fn_8016B68C();
    return 1;
}

s32 fn_800B8150(void) {
    M2C_UNK fn_8016B60C();
    fn_8016B60C();
    return 1;
}

s32 fn_800B8174(void) {
    M2C_UNK fn_8016B64C();
    fn_8016B64C();
    return 1;
}

s32 fn_800B8198(void) {
    M2C_UNK fn_800C0658();
    M2C_UNK fn_8016B6D4();
    fn_800C0658();
    fn_8016B6D4();
    return 1;
}

s32 fn_800B81C0(void) {
    void fn_8016B700(void);
    s32 fn_800C0658(void);
    void Process_CreateChild(void *, s32);
    void fn_80013864(void);
    void fn_80013874(void *);
    extern u8 lbl_8028D218[];
    extern u8 lbl_80320060[];

    fn_8016B700();
    Process_CreateChild(lbl_8028D218, fn_800C0658());
    fn_80013864();
    fn_80013874(lbl_80320060);
    return 1;
}

void fn_800B8208(s32 arg0) {
    extern u8 lbl_8026ECB8[];
    u32 Process_FindByName(void *);
    void Process_ClearFunc(s32);

    if (Process_FindByName(lbl_8026ECB8 + 0xA29) == 0U) {
        Process_ClearFunc(arg0);
    }
}

s32 fn_800B8250(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void fn_8010FD70(void *, s8, s8, u8, s32);
    extern u8 gMapObjEventList[];

    fn_8010FD70(gMapObjEventList, arg0, arg1, arg2, arg3);
    return 1;
}

extern u8 gMapObjEventList[];
s32 fn_800B8298(s8 arg0, s8 arg1) {
    void *MapObjEvent_Push(void *, s32, s32, s32, s32);
    MapObjEvent_Push(gMapObjEventList, arg0, arg1, 9, 0);
    return 1;
}

s32 fn_800B82D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 Item_GetByIid(s32);
    void fn_8010FDB8(void *, s8, s8, u8, s32);
    extern u8 gMapObjEventList[];

    fn_8010FDB8(gMapObjEventList, (s8)arg0, (s8)arg1, (u8)arg2, Item_GetByIid(arg3));
    return 1;
}

s32 fn_800B8340(s32 arg0, s32 arg1, s32 arg2) {
    void *MapObjEvent_Push(void *, s8, s8, s32, s32);
    extern u8 gMapObjEventList[];
    u8 *temp_r3;
    s32 t2;

    t2 = arg2;
    temp_r3 = MapObjEvent_Push(gMapObjEventList, arg0, arg1, 4, 0);
    temp_r3[4] = t2;
    temp_r3[5] = t2;
    temp_r3[6] = 0;
    temp_r3[7] = 0;
    return 1;
}

s32 fn_800B83A4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void *MapObjEvent_Push(void *, s8, s8, u8, u8);
    extern u8 gMapObjEventList[];
    u8 *temp_r3;
    s32 t5;
    s32 t4;

    t5 = arg5;
    t4 = arg4;
    temp_r3 = MapObjEvent_Push(gMapObjEventList, arg0, arg1, arg2, arg3);
    temp_r3[4] = t4;
    temp_r3[5] = t5;
    temp_r3[6] = 0;
    temp_r3[7] = 0;
    return 1;
}

/* Script command: set up and run a battle between two units by deployment id. */
s32 ScriptCmd_Battle(u8 attackerId, u8 defenderId, u8 flag) {
    void Process_CreateChild(void *, s32);
    void fn_80033418(void *);
    void Battle_Execute(void *, s32);
    void Battle_SetupPair(void *, void *, void *);
    s32 fn_800C0658(void);
    void fn_80013864(void);
    extern u8 lbl_8028D200[];
    extern u8 gUnits[];
    extern u8 gBattle[];
    void *defender;
    void *attacker;

    if (attackerId != 0) {
        attacker = gUnits + (attackerId - 1) * 0x280;
    } else {
        attacker = NULL;
    }
    if (defenderId != 0) {
        defender = gUnits + (defenderId - 1) * 0x280;
    } else {
        defender = NULL;
    }
    Battle_SetupPair(gBattle, attacker, defender);
    Battle_Execute(gBattle, 0xF);
    fn_80033418(gBattle + 0x8A0);
    if (flag != 0) {
        *(u32 *)(gBattle + 0xCAC) = *(u32 *)(gBattle + 0xCAC) | 0x80000000;
    } else {
        *(u32 *)(gBattle + 0xCAC) = *(u32 *)(gBattle + 0xCAC) & 0x7FFFFFFF;
    }
    Process_CreateChild(lbl_8028D200, fn_800C0658());
    fn_80013864();
    return 1;
}

s32 fn_800B850C(s32 arg0, s8 arg1, s16 arg2) {
    extern u8 gBattleHitTbl[];
    gBattleHitTbl[0x61] = 1;
    gBattleHitTbl[arg0] = arg1;
    *(s16 *)(gBattleHitTbl + 0x20 + arg0 * 2) = arg2;
    return 1;
}

s32 fn_800B8534(void) {
    extern u8 gBattleHitTbl[];
    u8 *p;
    u8 *q;
    s32 i;

    p = gBattleHitTbl;
    p[0x61] = 0;
    q = p;
    p[0x60] = 0;
    for (i = 0; i < 2; i++) {
        p[0] = 0;
        *(u16 *)(q + 0x20) = 0;
        p[1] = 0;
        *(u16 *)(q + 0x22) = 0;
        p[2] = 0;
        *(u16 *)(q + 0x24) = 0;
        p[3] = 0;
        *(u16 *)(q + 0x26) = 0;
        p[4] = 0;
        *(u16 *)(q + 0x28) = 0;
        p[5] = 0;
        *(u16 *)(q + 0x2A) = 0;
        p[6] = 0;
        *(u16 *)(q + 0x2C) = 0;
        p[7] = 0;
        *(u16 *)(q + 0x2E) = 0;
        p[8] = 0;
        *(u16 *)(q + 0x30) = 0;
        p[9] = 0;
        *(u16 *)(q + 0x32) = 0;
        p[10] = 0;
        *(u16 *)(q + 0x34) = 0;
        p[11] = 0;
        *(u16 *)(q + 0x36) = 0;
        p[12] = 0;
        *(u16 *)(q + 0x38) = 0;
        p[13] = 0;
        *(u16 *)(q + 0x3A) = 0;
        p[14] = 0;
        *(u16 *)(q + 0x3C) = 0;
        p[15] = 0;
        p += 0x10;
        *(u16 *)(q + 0x3E) = 0;
        q += 0x20;
    }
    return 1;
}

s32 fn_800B85EC(void) {
    M2C_UNK Pad_ClearDisableMask(s32, s32);
    s32 fn_800B864C();
    extern s32 gPadInput;
    Pad_ClearDisableMask(gPadInput, fn_800B864C());
    return 0;
}

s32 fn_800B861C(void) {
    M2C_UNK Pad_SetDisableMask(s32, s32);
    s32 fn_800B864C();
    extern s32 gPadInput;
    Pad_SetDisableMask(gPadInput, fn_800B864C());
    return 0;
}

u32 fn_800B864C(u8 *p) {
s32 flags=0; u8 ch;
while ((s8)(ch=*p)!=0) {
switch((s8)ch) {
case '2': flags|=0x04000004; break;
case '4': flags|=0x01000001; break;
case '6': flags|=0x02000002; break;
case '8': flags|=0x08000008; break;
case 'A': flags|=0x100; break;
case 'B': flags|=0x200; break;
case 'X': flags|=0x400; break;
case 'Y': flags|=0x800; break;
case 'Z': flags|=0x10; break;
case 'L': flags|=0x40; break;
case 'R': flags|=0x20; break;
case 'S': flags|=0x1000; break;
case '*': flags=-1; break;
}
p++;
}
return flags;
}

s32 fn_800B870C(u32 arg0) {
    s32 Process_FindByName();
    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    return Process_FindByName();
}

s32 fn_800B874C(u32 arg0) {
    M2C_UNK fn_8000BD98();
    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    fn_8000BD98();
    return 0;
}

u8 fn_800B8790(void) {
    return fn_80089948();
}

s32 fn_800B87B4(void) {
    u8 fn_80089948();
    M2C_UNK Process_CreateChild(void *, s32);
    M2C_UNK fn_80013874(void *);
    extern u8 lbl_8028D1EC[];
    extern u8 lbl_80320060[];
    if (fn_80089948() != 0) {
        Process_CreateChild(lbl_8028D1EC, fn_800C0658());
        fn_80013864();
        fn_80013874(lbl_80320060);
    }
    return 1;
}

void fn_800B8804(s32 arg0) {
    M2C_UNK Process_ClearFunc(s32);
    u8 fn_80089948();
    if (fn_80089948() == 0) {
        Process_ClearFunc(arg0);
    }
}

s32 fn_800B8840(void) {
    M2C_UNK fn_80089970();
    fn_80089970();
    return 1;
}

s32 fn_800B8864(s32 arg0) {
    M2C_UNK fn_80089980(s32);
    s32 var_r3;

    var_r3 = arg0;
    if (var_r3 < 0) {
        var_r3 = 0x7D0;
    }
    fn_80089980(var_r3);
    return 1;
}

s32 fn_800B8894(s32 arg0) {
    M2C_UNK fn_800899D4(s32);
    s32 var_r3;

    var_r3 = arg0;
    if (var_r3 < 0) {
        var_r3 = 0x7D0;
    }
    fn_800899D4(var_r3);
    return 1;
}

u8 fn_800B88C4(void) {
    return fn_80089ED8();
}

s32 fn_800B88E8(void) {
    u8 fn_80089ED8();
    M2C_UNK Process_CreateChild(void *, s32);
    M2C_UNK fn_80013874(void *);
    extern u8 lbl_8028D1D8[];
    extern u8 lbl_80320060[];
    if (fn_80089ED8() != 0) {
        Process_CreateChild(lbl_8028D1D8, fn_800C0658());
        fn_80013864();
        fn_80013874(lbl_80320060);
    }
    return 1;
}

void fn_800B8938(s32 arg0) {
    u8 fn_80089ED8();
    if (fn_80089ED8() == 0) {
        Process_ClearFunc(arg0);
    }
}

s32 fn_800B8974(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_UNK fn_80089F00(u8, u8, u8, s32, s32);
    s32 var_r3;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;

    var_r3 = arg0;
    var_r4 = arg1;
    var_r5 = arg2;
    var_r6 = arg3;
    var_r7 = arg4;
    if (var_r3 < 0) {
        var_r3 = 0;
    }
    if (var_r3 > 0xFF) {
        var_r3 = 0xFF;
    }
    if (var_r4 < 0) {
        var_r4 = 0;
    }
    if (var_r4 > 0xFF) {
        var_r4 = 0xFF;
    }
    if (var_r5 < 0) {
        var_r5 = 0;
    }
    if (var_r5 > 0xFF) {
        var_r5 = 0xFF;
    }
    if (var_r6 < 0) {
        var_r6 = 0x1F4;
    }
    if (var_r7 < 0) {
        var_r7 = 0x1F4;
    }
    fn_80089F00((u8) var_r3, (u8) var_r4, (u8) var_r5, var_r6, var_r7);
    return 1;
}

u8 fn_800B8A04(void) {
    return fn_8008A59C();
}

s32 fn_800B8A28(u8 arg0, s32 arg1) {
    s32 var_r4;

    var_r4 = arg1;
    if (var_r4 < 0) {
        var_r4 = 0x1F4;
    }
    fn_8008A290(arg0, var_r4);
    return 1;
}

#pragma use_lmw_stmw on
s32 fn_800B8A5C(s32 arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    M2C_UNK fn_801C1D54(s16, s16, u32, s32, s32, s32);
    if ((arg2 < 0x80000000U) || (arg2 >= 0x81800000U)) {
        return 0;
    }
    fn_801C1D54(arg0, arg1, arg2, arg3, arg4, fn_800C0658());
    return 1;
}
#pragma use_lmw_stmw reset
s32 fn_800B8AD8(void) {
    M2C_UNK fn_801C18FC();
    fn_801C18FC();
    return 1;
}

s32 fn_800B8AFC(s32 arg0) {
    M2C_UNK fn_801C1970(s8);
    fn_801C1970(arg0);
    return 1;
}

#pragma use_lmw_stmw on
s32 fn_800B8B24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5) {
    M2C_UNK fn_801C1A18(s8, s16, s16, s16, u32, s32, s32);
    if ((arg4 < 0x80000000U) || (arg4 >= 0x81800000U)) {
        return 0;
    }
    fn_801C1A18(arg0, arg1, arg2, arg3, arg4, arg5, fn_800C0658());
    return 1;
}
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
s32 fn_800B8BA8(s32 arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    M2C_UNK fn_801C1AC8(s16, s16, s16, u32, s32, s32, s32, s32);
    if ((arg3 < 0x80000000U) || (arg3 >= 0x81800000U)) {
        return 0;
    }
    fn_801C1AC8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, fn_800C0658());
    return 1;
}
#pragma use_lmw_stmw reset

s32 fn_800B8C34(s32 arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4) {
    void *fn_800C0658(void);
    void fn_801C1BC0(s8, s16, s16, u32, s32, void *);

    if ((arg3 < 0x80000000U) || (arg3 >= 0x81800000U)) {
        return 0;
    }
    fn_801C1BC0((s8)arg0, (s16)arg1, (s16)arg2, arg3, arg4, fn_800C0658());
    return 1;
}

s32 fn_800B8CB0(s32 arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void fn_801C1C64(s16, s16, u32, s32, s32, s32, s32);
    s32 fn_800C0658(void);
    if ((arg2 < 0x80000000U) || (arg2 >= 0x81800000U)) {
        return 0;
    }
    fn_801C1C64(arg0, arg1, arg2, arg3, arg4, arg5, fn_800C0658());
    return 1;
}

void fn_800B8D34(void) {
    M2C_UNK fn_8006F014();
    fn_8006F014();
}

s32 fn_800B8D54(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    M2C_UNK fn_8006F020();
    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if ((arg1 < 0x80000000U) || (arg1 >= 0x81800000U)) {
        return 0;
    }
    if ((arg2 < 0x80000000U) || (arg2 >= 0x81800000U)) {
        return 0;
    }
    if ((arg3 < 0x80000000U) || (arg3 >= 0x81800000U)) {
        return 0;
    }
    fn_8006F020();
    fn_80013864();
    return 1;
}

s32 fn_800B8DE4(u32 arg0, u32 arg1, u32 arg2) {
    M2C_UNK fn_8006F09C();
    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if ((arg1 < 0x80000000U) || (arg1 >= 0x81800000U)) {
        return 0;
    }
    if ((arg2 < 0x80000000U) || (arg2 >= 0x81800000U)) {
        return 0;
    }
    fn_8006F09C();
    fn_80013864();
    return 1;
}

s32 fn_800B8E5C(u32 arg0, u32 arg1) {
    M2C_UNK fn_8006F10C();
    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if ((arg1 < 0x80000000U) || (arg1 >= 0x81800000U)) {
        return 0;
    }
    fn_8006F10C();
    fn_80013864();
    return 1;
}

s32 fn_800B8EBC(void) {
    extern s32 gUiInputFlags;
    gUiInputFlags |= 0x10;
    return 1;
}

s32 fn_800B8ED0(u32 arg0) {
    char *Msg_Expand(void);
    char *strchr(char *, s32);
    void *Process_FindByName(void *);
    void fn_80070018(void *, u32, s32, s32);
    void fn_8006FBE4(void *, u32, s32, s32);
    void fn_80013864(void);
    void fn_80013874(void *);
    extern u8 lbl_8026ECB8[];
    extern u8 lbl_80320060[];
    extern s32 gUiInputFlags;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (strchr(Msg_Expand(), 0xA) == NULL) {
        fn_80070018(Process_FindByName(lbl_8026ECB8 + 0xA3C), arg0, 0, 0);
    } else {
        fn_8006FBE4(Process_FindByName(lbl_8026ECB8 + 0xA3C), arg0, 0, 0);
    }
    fn_80013864();
    fn_80013874(lbl_80320060);
    gUiInputFlags &= ~0x80;
    gUiInputFlags &= ~0x10;
    return 0;
}

extern void fn_8006F6A4(u32 arg0, u32 arg1, u32 arg2);
s32 fn_800B8F98(u32 arg0) {
    M2C_UNK fn_8006F6A4(s32, u32, s32, s32);
    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    fn_8006F6A4(fn_800C0658(), arg0, 0, 0);
    fn_80013864();
    return 0;
}

extern void fn_80070018(u32 arg0, u32 arg1, u32 arg2);
s32 fn_800B8FFC(u32 arg0) {
    M2C_UNK fn_80070018(s32, u32, s32, s32);
    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    fn_80070018(fn_800C0658(), arg0, 0, 0);
    fn_80013864();
    return 0;
}

extern void fn_80070018(u32 arg0, u32 arg1, u32 arg2);
s32 fn_800B9060(u32 arg0) {
    M2C_UNK fn_80070018(s32, u32, s32, s32);
    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    fn_80070018(fn_800C0658(), arg0, 0, 0);
    fn_80013864();
    return 0;
}

s32 fn_800B90C4(u32 arg0) {
    extern s32 gUiInputFlags;
    u32 ScriptObj_FindByName(void);
    void fn_801CFCB4(void);

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    if (ScriptObj_FindByName() == 0) {
        return 0;
    }
    fn_801CFCB4();
    return 1;
}

s32 fn_800B9130(u32 arg0, s32 arg1) {
    extern s32 gUiInputFlags;
    void *ScriptObj_FindByName(void);
    void fn_801CFD40(void *, s32);
    void *tmp;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    tmp = ScriptObj_FindByName();
    if (tmp == 0) {
        return 0;
    }
    fn_801CFD40(tmp, arg1);
    return 1;
}

s32 fn_800B91AC(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *ScriptObj_FindByName(u32);
    void fn_801CFD60(void *, s32, s32, s32, s32);
    extern s32 gUiInputFlags;
    void *p;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    p = ScriptObj_FindByName(arg0);
    if (p == NULL) {
        return 0;
    }
    fn_801CFD60(p, arg1, arg2, arg3, arg4);
    return 1;
}

s32 fn_800B9258(u32 arg0, s32 arg1, s32 arg2) {
    void *ScriptObj_FindByName(u32);
    void fn_801CFD8C(void *, s32, s32);
    extern s32 gUiInputFlags;
    void *p;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    p = ScriptObj_FindByName(arg0);
    if (p == NULL) {
        return 0;
    }
    fn_801CFD8C(p, arg1, arg2 != 0);
    return 1;
}

s32 fn_800B92EC(u32 arg0, s32 arg1) {
    extern s32 gUiInputFlags;
    void *ScriptObj_FindByName(void);
    void fn_801CFDBC(void *, s32);
    void *tmp;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    tmp = ScriptObj_FindByName();
    if (tmp == 0) {
        return 0;
    }
    fn_801CFDBC(tmp, arg1);
    return 1;
}

s32 fn_800B9368(u32 arg0) {
    extern s32 gUiInputFlags;
    u32 ScriptObj_FindByName(void);
    void fn_801CFDD4(void);

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    if (ScriptObj_FindByName() == 0) {
        return 0;
    }
    fn_801CFDD4();
    return 1;
}

s32 fn_800B93D4(u32 arg0, s32 arg1) {
    extern s32 gUiInputFlags;
    void *ScriptObj_FindByName(void);
    void fn_801CFE80(void *, s32);
    void *tmp;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    tmp = ScriptObj_FindByName();
    if (tmp == 0) {
        return 0;
    }
    fn_801CFE80(tmp, arg1);
    return 1;
}

s32 fn_800B9450(u32 arg0, s32 arg1) {
    extern s32 gUiInputFlags;
    void *ScriptObj_FindByName(void);
    void fn_801CFEA4(void *, s32);
    void *tmp;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    tmp = ScriptObj_FindByName();
    if (tmp == 0) {
        return 0;
    }
    fn_801CFEA4(tmp, arg1);
    return 1;
}

s32 fn_800B94CC(u32 arg0, s32 arg1) {
    extern s32 gUiInputFlags;
    void *ScriptObj_FindByName(void);
    void fn_801CFEF4(void *, s32);
    void *tmp;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    tmp = ScriptObj_FindByName();
    if (tmp == 0) {
        return 0;
    }
    fn_801CFEF4(tmp, arg1);
    return 1;
}

s32 fn_800B9548(u32 arg0) {
    extern s32 gUiInputFlags;
    u32 ScriptObj_FindByName(void);
    void fn_801D0200(void);

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    if (ScriptObj_FindByName() == 0) {
        return 0;
    }
    fn_801D0200();
    return 1;
}

s32 fn_800B95B4(u32 arg0, s32 arg1) {
    extern s32 gUiInputFlags;
    void *ScriptObj_FindByName(void);
    void fn_801D027C(void *, s32);
    void *tmp;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    tmp = ScriptObj_FindByName();
    if (tmp == 0) {
        return 0;
    }
    fn_801D027C(tmp, arg1);
    return 1;
}

/* Script command: play a colored, scaled effect on a named script object at (x,y). */
s32 ScriptCmd_PlayEffect(u32 name, s32 slot, s32 x, s32 y, s32 scalePct, u32 rgb) {
    void *ScriptObj_FindByName(u32);
    void fn_801D029C(void *, s32, s32, s32, void *, f32);
    extern s32 gUiInputFlags;
    extern u32 gColorAlphaFF;
    extern f64 lbl_80369CF8;
    extern f32 gPercentToFloat;
    void *obj;
    u32 packed;
    u32 tmp;
    u32 color;
    u8 g;
    u8 r;

    if ((name < 0x80000000U) || (name >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    obj = ScriptObj_FindByName(name);
    if (obj == NULL) {
        return 0;
    }
    r = (u8)(rgb >> 16);
    g = (u8)(rgb >> 8);
    tmp = gColorAlphaFF;
    ((u8 *)&packed)[0] = r;
    ((u8 *)&packed)[1] = g;
    ((u8 *)&packed)[2] = (u8)rgb;
    ((u8 *)&packed)[3] = ((u8 *)&tmp)[3];
    ((u8 *)&tmp)[0] = r;
    ((u8 *)&tmp)[1] = g;
    ((u8 *)&tmp)[2] = (u8)rgb;
    color = packed;
    fn_801D029C(obj, slot, x, y, &color, gPercentToFloat * (f32)scalePct);
    return 1;
}

s32 fn_800B9724(u32 arg0, s32 arg1, s32 arg2) {
    void *ScriptObj_FindByName(u32);
    void fn_801D03E4(void *, s32, s32);
    extern s32 gUiInputFlags;
    void *p;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    p = ScriptObj_FindByName(arg0);
    if (p == NULL) {
        return 0;
    }
    fn_801D03E4(p, arg1, arg2 != 0);
    return 1;
}

s32 fn_800B97B8(u32 arg0, s32 arg1) {
    void *ScriptObj_FindByName(u32);
    M2C_UNK fn_801D041C(void *, s32);
    extern s32 gUiInputFlags;
    void *p;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    p = ScriptObj_FindByName(arg0);
    if (p == NULL) {
        return 0;
    }
    fn_801D041C(p, arg1 != 0);
    return 1;
}

s32 fn_800B983C(u32 arg0, s32 arg1) {
    extern s32 gUiInputFlags;
    void *ScriptObj_FindByName(void);
    void fn_801D0444(void *, s32);
    void *tmp;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    tmp = ScriptObj_FindByName();
    if (tmp == 0) {
        return 0;
    }
    fn_801D0444(tmp, arg1);
    return 1;
}

s32 fn_800B98B8(u32 arg0) {
    extern s32 gUiInputFlags;
    extern u8 lbl_8028D1C4[];
    extern u8 lbl_80320060[];
    void *ScriptObj_FindByName(void);
    void *fn_800C0658(void);
    void *Process_CreateChild(void *, void *);
    void fn_80013864(void);
    void fn_80013874(void *);
    void *tmp;
    void *obj;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    tmp = ScriptObj_FindByName();
    if (tmp == 0) {
        return 0;
    }
    obj = Process_CreateChild(lbl_8028D1C4, fn_800C0658());
    fn_80013864();
    fn_80013874(lbl_80320060);
    *(void **)((u8 *)obj + 0x54) = tmp;
    return 1;
}

#pragma optimization_level 1
void fn_800B995C(void *arg0) {
    void Process_ClearFunc();
    s32 base;
    s32 shift;
    s32 flags;
    base = 0x100;
    shift = 0;
    flags = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x54) + 8);
    if (flags & (base << shift)) return;
    shift = 1;
    if (flags & (base << shift)) return;
    shift = 2;
    if (flags & (base << shift)) return;
    Process_ClearFunc(arg0, base);
}
#pragma optimization_level 4
s32 fn_800B99B8(u32 arg0, s32 arg1) {
    extern s32 gUiInputFlags;
    void *ScriptObj_FindByName(void);
    void fn_801D0460(void *, s32);
    void *tmp;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (gUiInputFlags & 1) {
        return 0;
    }
    tmp = ScriptObj_FindByName();
    if (tmp == 0) {
        return 0;
    }
    fn_801D0460(tmp, arg1);
    return 1;
}

s32 fn_800B9A34(u32 arg0, s32 arg1) {
    u32 Sound_FindByName(void);
    void fn_80109BB4(u32, u8);
    u32 tmp;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    tmp = Sound_FindByName();
    if (tmp == 0U) {
        return 0;
    }
    fn_80109BB4(tmp, (u8)arg1);
    return 1;
}

s32 fn_800B9A9C(u32 arg0, s32 arg1) {
    u32 Sound_FindByName(u32);
    void Sound_FadeToVol(u32, u8);
    u32 ScriptObj_FindByName(u32);
    void fn_801CFC4C(u32, s32);
    s32 Str_NCmp(void *, void *, s32);
    extern u8 lbl_8026ECB8[];
    u32 temp;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }

    if (Str_NCmp((void *)arg0, lbl_8026ECB8 + 0xA47, 8) != 0) {
        temp = Sound_FindByName(arg0);
        if (temp == 0U) {
            return 0;
        }
        Sound_FadeToVol(temp, arg1);
        return 1;
    }

    temp = ScriptObj_FindByName(arg0);
    if (temp == 0U) {
        return 0;
    }

    fn_801CFC4C(temp, arg1);
    return 1;
}

s32 fn_800B9B58(u32 arg0, s32 arg1) {
    u32 Sound_FindByName(u32);
    void Sound_FadeFromZero(u32, u8);
    u32 ScriptObj_FindByName(u32);
    void fn_801CFC80(u32, s32);
    s32 Str_NCmp(void *, void *, s32);
    extern u8 lbl_8026ECB8[];
    u32 temp;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }

    if (Str_NCmp((void *)arg0, lbl_8026ECB8 + 0xA47, 8) != 0) {
        temp = Sound_FindByName(arg0);
        if (temp == 0U) {
            return 0;
        }
        Sound_FadeFromZero(temp, arg1);
        return 1;
    }

    temp = ScriptObj_FindByName(arg0);
    if (temp == 0U) {
        return 0;
    }

    fn_801CFC80(temp, arg1);
    return 1;
}

void fn_800B9C14(void) {
    f32 var = 1.0f;
    fn_800B9CD4(var);
}

void fn_800B9C38(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void fn_800B9CD4(s32, s32, s32, s32, s32);
    extern f32 lbl_80369D08;
    extern f32 lbl_80369D0C;
    extern f32 lbl_80369D10;
    f32 scale;
    f32 t1;
    f32 t2;

    scale = (f32)arg3 / lbl_80369D08;
    t1 = (f32)arg1;
    t2 = (f32)arg2;
    fn_800B9CD4(arg0, (s32)(lbl_80369D0C - t1 * scale), (s32)(lbl_80369D10 - t2 * scale), arg4, arg5);
}

s32 fn_800B9EA8(u8* arg0, u8* arg1, s32 arg2)
{
    return fn_80010710(arg0);
}

s32 ScriptCmd_SetPos(u32 name, s32 x, s32 y) {
    /* Set X/Y on a named sound (floats) or script object (s16s); 0 if missing. */
    void *Sound_FindByName(u32);
    void *ScriptObj_FindByName(u32);
    s32 Str_NCmp(void *, void *, s32);
    extern u8 lbl_8026ECB8[];

    if ((name < 0x80000000U) || (name >= 0x81800000U)) {
        return 0;
    }

    if (Str_NCmp((void *)name, lbl_8026ECB8 + 0xA47, 8) != 0) {
        void *snd = Sound_FindByName(name);
        if (snd == NULL) {
            return 0;
        }
        *(f32 *)((u8 *)snd + 0x40) = (f32)x;
        *(f32 *)((u8 *)snd + 0x44) = (f32)y;
        return 1;
    } else {
        void *obj = ScriptObj_FindByName(name);
        if (obj == NULL) {
            return 0;
        }
        *(s16 *)((u8 *)obj + 0x18) = (s16)x;
        *(s16 *)((u8 *)obj + 0x1A) = (s16)y;
        return 1;
    }
}

s32 fn_800BA230(u32 arg0, s32 arg1) {
    u32 Sound_FindByName(void);
    void fn_80109DC0(u32, s32);
    u32 tmp;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    tmp = Sound_FindByName();
    if (tmp == 0U) {
        return 0;
    }
    fn_80109DC0(tmp, arg1);
    return 1;
}

/* Script command: look up a sound by name and tween/set a typed parameter (percent-scaled for types 5-7). */
s32 ScriptCmd_SoundSetParam(u32 name, s32 type, s32 mode, s32 valueA, s32 valueB, s32 frames) {
    u32 Sound_FindByName(void);
    void Sound_TweenParam(u32, s32, s32, f32, f32, f32);
    extern f32 gPercentToFloat;
    extern f64 lbl_80369CF8;
    u32 snd;
    f32 fromVal;
    f32 toVal;

    if ((name < 0x80000000U) || (name >= 0x81800000U)) {
        return 0;
    }
    snd = Sound_FindByName();
    if (snd == 0U) {
        return 0;
    }
    fromVal = (f32)valueA;
    toVal = (f32)valueB;
    switch (type) {
    case 5:
    case 6:
    case 7:
        toVal *= gPercentToFloat;
        if (valueA != 123456789) {
            fromVal *= gPercentToFloat;
        }
        break;
    }
    Sound_TweenParam(snd, type, mode, fromVal, toVal, (f32)frames);
    return 1;
}

s32 fn_800BA38C(u32 arg0, s32 arg1, s32 arg2) {
    u32 Sound_FindByName(void);
    void fn_80109A54(u32, u8, f32);
    extern f32 gPercentToFloat;
    u32 tmp;
    f32 var_f1;

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    tmp = Sound_FindByName();
    if (tmp == 0U) {
        return 0;
    }
    var_f1 = (f32) arg2;
    switch (arg1) {
    case 5:
    case 6:
    case 7:
        var_f1 *= gPercentToFloat;
        break;
    }
    fn_80109A54(tmp, (u8) arg1, var_f1);
    return 1;
}

s32 fn_800BA438(u32 arg0, s32 arg1)
{
  u32 Sound_FindByName(void);
  f32 fn_801099A0(u32, u8);
  u32 tmp;

  if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U))
  {
    return 0;
  }
  tmp = Sound_FindByName();
  if (tmp == 0U)
  {
    return 0;
  }
  return (s32)fn_801099A0(tmp, (u8)arg1);
}

s32 fn_800BA4A8(u32 arg0) {
    void fn_80109020(u32);
    void ScriptObj_FindByName(u32);
    void fn_801CFA44(void);
    s32 Str_NCmp(void *, void *, s32);
    extern u8 lbl_8026ECB8[];

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }

    if (Str_NCmp((void *)arg0, lbl_8026ECB8 + 0xA47, 8) != 0) {
        fn_80109020(arg0);
    } else {
        ScriptObj_FindByName(arg0);
        fn_801CFA44();
    }

    return 0;
}

s32 fn_800BA528(u32 arg0) {
    void fn_80109180(u32, s32);
    void ScriptObj_Start(u32, s32);
    s32 Str_NCmp(void *, void *, s32);
    extern u16 lbl_8026ECB8[];

    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }

    if (Str_NCmp((void *)arg0, (u8 *)lbl_8026ECB8 + 0xA47, 8) != 0) {
        fn_80109180(arg0, 0);
    } else {
        ScriptObj_Start(arg0, 0);
    }

    return 0;
}

s32 fn_800BA5AC(u32 arg0) {
    s32 Str_NCmp(void *, void *, s32);
    void fn_80109180(u32, s32);
    void ScriptObj_Start(u32, s32);
    s32 fn_800C0658(void);
    extern u8 lbl_8026ECB8[];
    if ((arg0 < 0x80000000U) || (arg0 >= 0x81800000U)) {
        return 0;
    }
    if (Str_NCmp((void *)arg0, lbl_8026ECB8 + 0xA47, 8) != 0) {
        fn_80109180(arg0, fn_800C0658());
    } else {
        ScriptObj_Start(arg0, fn_800C0658());
    }
    return 0;
}

s32 fn_800BA638(s32 arg0) {
    void fn_8014D268(void *, s32);
    void fn_8009149C(s32, s32, s32);
    s32 fn_800C0658(void);
    extern u8 gBattleState[];
    extern s32 gUiContext[];

    fn_8014D268(gBattleState, arg0 + *(s32 *)(gBattleState + 0x18));
    {
        s32 g = *gUiContext;
        fn_8009149C(arg0, fn_800C0658(), g);
    }
    return 0;
}

s32 fn_800BA69C(u8 arg0, s32 arg1) {
    void fn_8001C76C(void *);
    void fn_8001D780(void *, s32);
    void Item_Clone(void *, void *);
    void Item_Destroy(void *, s32);
    s32 fn_800C0658(void);
    void Unit_OfferItem(void *, void *, s32);
    extern u8 gUnits[];
    u8 sp10[8];
    u8 sp8[8];
    void *var_r31;

    if (arg0 != 0) {
        var_r31 = gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r31 = NULL;
    }
    if ((var_r31 == NULL) || (*(u32 *)((u8 *)var_r31 + 0x188) == 0U)) {
        return 0;
    }
    fn_8001C76C(sp10);
    fn_8001D780(sp10, arg1);
    Item_Clone(sp8, sp10);
    Unit_OfferItem(var_r31, sp8, fn_800C0658());
    Item_Destroy(sp8, -1);
    Item_Destroy(sp10, -1);
    return 1;
}

s32 fn_800BA75C(s8 arg0, s8 arg1, s8 arg2) {
    extern u8 gBattleMap[];
    gBattleMap[arg0 + (arg1 << 6) + 0x100D] = (u8)arg2;
    return 0;
}

s32 fn_800BA784(void) {
    M2C_UNK Allegiance_FillMask(M2C_UNK, M2C_UNK *);
    M2C_UNK Map_RefreshUnitMap(M2C_UNK *);
    M2C_UNK fn_8003DFB8();
    M2C_UNK Unit_SeparateRescue(u8, u8);
    M2C_UNK fn_800C1060();
    extern M2C_UNK gUnits;
    extern M2C_UNK gUnitLists;
    extern M2C_UNK gBattleMap;
    
    s32 sp10;
    s32 sp8;
    u8 var_r29;
    u8 var_r31;
    void *temp_r30;
    void *temp_r30_2;
    void *var_r3;
    void *var_r3_2;
    void *var_r3_3;

    Allegiance_FillMask(3, &sp10);
    var_r31 = 1;
    do {
        if (var_r31 != 0) {
            var_r3 = &gUnits + ((var_r31 - 1) * 0x280);
        } else {
            var_r3 = NULL;
        }
        if (((u32) M2C_FIELD(var_r3, u32 *, 0x188) != 0U) && ((u8) *(&sp10 + M2C_FIELD(M2C_FIELD(var_r3, void **, 0x190), u8 *, 8)) != 0)) {
            temp_r30 = M2C_FIELD(var_r3, void **, 0x194);
            if ((temp_r30 != NULL) && (M2C_FIELD(var_r3, s32 *, 0x1A0) & 2)) {
                Unit_SeparateRescue(M2C_FIELD(var_r3, u8 *, 0x19E), M2C_FIELD(var_r3, u8 *, 0x19F));
                if (temp_r30 != NULL) {
                    M2C_FIELD(temp_r30, s32 *, 0x1A0) = (s32) (M2C_FIELD(temp_r30, s32 *, 0x1A0) & 0xFFFFFFFE);
                }
            }
        }
        var_r31 += 1;
    } while ((s32) var_r31 <= 0x9F);
    
    var_r3_2 = M2C_FIELD(&gUnitLists, void **, 4);
loop_13:
    if (var_r3_2 != NULL) {
        temp_r30_2 = M2C_FIELD(var_r3_2, void **, 0x180);
        fn_8003DFB8();
        var_r3_2 = temp_r30_2;
        goto loop_13;
    }
    
    Allegiance_FillMask(3, &sp8);
    var_r29 = 1;
    do {
        if (var_r29 != 0) {
            var_r3_3 = &gUnits + ((var_r29 - 1) * 0x280);
        } else {
            var_r3_3 = NULL;
        }
        if (((u32) M2C_FIELD(var_r3_3, u32 *, 0x188) != 0U) && ((u8) *(&sp8 + M2C_FIELD(M2C_FIELD(var_r3_3, void **, 0x190), u8 *, 8)) != 0)) {
            fn_8003DFB8();
        }
        var_r29 += 1;
    } while ((s32) var_r29 <= 0x9F);
    
    Map_RefreshUnitMap(&gBattleMap);
    fn_800C0658();
    fn_800C1060();
    return 1;
}

s32 fn_800BA8F8(u8 arg0) {
    void Map_RefreshUnitMap(void *);
    M2C_UNK fn_8003DFB8(void *);
    M2C_UNK fn_801A251C(void);
    extern u8 gUnits[];
    extern u8 gBattleMap[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || M2C_FIELD(unit, void **, 0x188) == NULL) {
        return 0;
    }
    fn_8003DFB8(unit);
    Map_RefreshUnitMap(gBattleMap);
    fn_801A251C();
    return 1;
}

s32 fn_800BA96C(void) {
    void *Res_GetByName(void);
    M2C_UNK fn_800A87D4(s32);
    void *Battle_GetActiveCombatant(void *);
    extern u8 gBattle[];
    void *p;

    p = Battle_GetActiveCombatant(gBattle);
    if (p == NULL) {
        return 0;
    }
    fn_800A87D4(M2C_FIELD(p, s32 *, 0x188));
    return Res_GetByName() != NULL;
}

extern void *Battle_GetActiveCombatant(u32 *);
extern s32 Res_GetByName();
extern s32 fn_800A87D4(s32);
s32 fn_800BA9BC(void) {
    void *temp_r3;
    
    temp_r3 = Battle_GetActiveCombatant((u32*)0x80330EAC);
    if (temp_r3 == 0) {
        return 0;
    }
    
    if (Res_GetByName() == 0) {
        return 0;
    }
    
    // Call with constant offset
    fn_800A87D4(*(s32*)((char*)temp_r3 + 0x188));
    
    return 1;
}

s32 fn_800BAAD4(void) {
    void *Res_GetByName(void);
    void *Process_FindByName(void *);
    s32 fn_800A876C(s32);
    M2C_UNK TalkUi_ShowMsg(s32);
    M2C_UNK fn_8011D908(s32, s32);
    extern u8 lbl_8026ECB8[];
    extern void *gUiContext[];
    s32 obj;

    if (gUiContext[0] == NULL) {
        return 0;
    }
    obj = fn_800A876C(M2C_FIELD(gUiContext[0], s32 *, 0x188));
    if (Res_GetByName() != NULL) {
        if (Process_FindByName(lbl_8026ECB8 + 0xA50) != NULL) {
            TalkUi_ShowMsg(obj);
        } else {
            fn_8011D908(obj, fn_800C0658());
        }
    }
    return 0;
}

s32 fn_800BAB64(u8 arg0) {
    M2C_UNK fn_8014CBD8(void *, f32, f32);
    extern u8 gUnits[];
    extern u8 gBattleState[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit != NULL) {
        fn_8014CBD8(gBattleState, M2C_FIELD(unit, s8 *, 0x19E), M2C_FIELD(unit, s8 *, 0x19F));
    }
    return 1;
}

s32 fn_800BABFC(void) {
    u8 Camera_HasMoved(s32);
    M2C_UNK fn_800187F0(void);
    M2C_UNK Process_CreateChild(void *, s32);
    M2C_UNK fn_80013874(void *);
    extern u8 lbl_8028D19C[];
    extern u8 lbl_80320060[];
    extern s32 gUiInputFlags;

    if (gUiInputFlags & 1) {
        fn_800187F0();
        return 0;
    }
    if (Camera_HasMoved(1) == 0) {
        return 0;
    }
    Process_CreateChild(lbl_8028D19C, fn_800C0658());
    fn_80013864();
    fn_80013874(lbl_80320060);
    return 1;
}

void fn_800BAC70(s32 arg0) {
    u8 Camera_HasMoved(s32);
    M2C_UNK fn_800187F0(void);
    extern s32 gUiInputFlags;

    if (Camera_HasMoved(1) == 0) {
        Process_ClearFunc(arg0);
    } else if (gUiInputFlags & 1) {
        fn_800187F0();
        Process_ClearFunc(arg0);
    }
}

s32 fn_800BACCC(void) {
    u8 Camera_HasMoved(s32);
    M2C_UNK fn_800187F0(void);
    M2C_UNK Process_CreateChild(void *, s32);
    M2C_UNK fn_80013874(void *);
    extern u8 lbl_8028D188[];
    extern u8 lbl_80320060[];
    extern s32 gUiInputFlags;

    if (gUiInputFlags & 1) {
        fn_800187F0();
        return 0;
    }
    if (Camera_HasMoved(0) == 0) {
        return 0;
    }
    Process_CreateChild(lbl_8028D188, fn_800C0658());
    fn_80013864();
    fn_80013874(lbl_80320060);
    return 1;
}

void fn_800BAD40(s32 arg0) {
    u8 Camera_HasMoved(s32);
    M2C_UNK fn_800187F0(void);
    extern s32 gUiInputFlags;

    if (Camera_HasMoved(0) == 0) {
        Process_ClearFunc(arg0);
    } else if (gUiInputFlags & 1) {
        fn_800187F0();
        Process_ClearFunc(arg0);
    }
}

s32 fn_800BAD9C(s32 arg0, s32 arg1) {
    M2C_UNK fn_8001885C(void);
    M2C_UNK fn_8014CBD8(void *, f32, f32);
    extern u8 gBattleState[];
    extern s32 gUiInputFlags;

    if (gUiInputFlags & 1) {
        fn_8014CBD8(gBattleState, arg0, arg1);
        fn_8001885C();
        return 0;
    }
    fn_8014CBD8(gBattleState, arg0, arg1);
    return 0;
}

s32 fn_800BAE4C(s32 arg0, s32 arg1) {
    void fn_8001885C(void);
    void fn_8014CBD8(void *, f32, f32);
    extern u8 gBattleState[];

    fn_8014CBD8(gBattleState, (f32)arg0, (f32)arg1);
    fn_8001885C();
    return 0;
}

s32 fn_800BAEAC(void) {
    void *Process_FindByName(void *);
    extern u16 gUiPanelFlags;
    extern u8 lbl_8026ECB8[];
    void *p;
    s32 flags;

    p = Process_FindByName(lbl_8026ECB8 + 0xA50);
    if (p == NULL) {
        return 0;
    }
    flags = gUiPanelFlags;
    return (flags & 0x10) == 0;
}

s32 fn_800BAEF8(void) {
    M2C_UNK fn_8011D650();
    fn_8011D650();
    return 1;
}

s32 fn_800BAF1C(s32 arg0) {
    void *Process_FindByName(void *);
    M2C_UNK TalkUi_ShowMsg(s32);
    M2C_UNK fn_8011D908(s32, s32);
    extern u8 lbl_8026ECB8[];

    if (Process_FindByName(lbl_8026ECB8 + 0xA50) != NULL) {
        TalkUi_ShowMsg(arg0);
        return 1;
    }
    fn_8011D908(arg0, fn_800C0658());
    return 1;
}

s32 fn_800BAF80(s32 arg0) {
    void *Process_FindByName(void *);
    M2C_UNK fn_8011D6F4(s32);
    M2C_UNK UiPanel_Create(s32, s32);
    extern u8 lbl_8026ECB8[];

    if (Process_FindByName(lbl_8026ECB8 + 0xA50) != NULL) {
        fn_8011D6F4(arg0);
        return 1;
    }
    UiPanel_Create(arg0, fn_800C0658());
    return 1;
}

s32 fn_800BAFE4(s32 arg0) {
    M2C_UNK fn_800BDBC8(void *, s32);
    extern u8 gBattleState[];

    fn_800BDBC8(gBattleState + 0xB4, arg0);
    return 0;
}

s32 fn_800BB018(s32 arg0) {
    M2C_UNK fn_800BDC68(void *, s32);
    extern u8 gBattleState[];

    fn_800BDC68(gBattleState + 0xB4, arg0);
    return 0;
}

u8 fn_800BB04C(s32 arg0) {
    s32 fn_800BDD08(void *, s32, void *);
    extern u8 gBattleState[];

    return (u8)fn_800BDD08(gBattleState + 0xB4, arg0, gBattleState);
}

s32 fn_800BB080(s32 arg0) {
    M2C_UNK fn_800BDDCC(void *, s32);
    extern u8 gBattleState[];

    fn_800BDDCC(gBattleState + 0xB4, arg0);
    return 1;
}

s32 fn_800BB0B4(s32 arg0) {
    M2C_UNK fn_800BDE40(void *, s32);
    extern u8 gBattleState[];

    fn_800BDE40(gBattleState + 0xB4, arg0);
    return 1;
}

void fn_800BB0E8(void) {
    void Script_RegisterCommand(void *, void *, s32);
    extern u8 lbl_8026F728[];
    void fn_800BD610(void);
    void fn_800BD5E0(void);
    void fn_800BD704(void);
    void fn_800BD638(void);
    void fn_800BD470(void);
    void fn_800BD424(void);
    void fn_800BD5AC(void);
    void ScriptCmd_UnitGetByPos(void);
    void fn_800BD0CC(void);
    void fn_800BD08C(void);
    void fn_800BD034(void);
    void fn_800BCFF4(void);
    void fn_800BCC88(void);
    void fn_800BD3DC(void);
    void fn_800BD388(void);
    void fn_800BD334(void);
    void fn_800BCF9C(void);
    void fn_800BCF44(void);
    void fn_800BCDF0(void);
    void fn_800BCD7C(void);
    void fn_800BCD58(void);
    void fn_800BCD34(void);
    void fn_800BCD24(void);
    void fn_800BCC44(void);
    void fn_800BCED4(void);
    void fn_800BCE64(void);
    void fn_800BCA38(void);
    void fn_800BD284(void);
    void fn_800BD1A4(void);
    void fn_800BD10C(void);
    void fn_800BC9D4(void);
    void fn_800BC970(void);
    void fn_800BC90C(void);
    void fn_800BC8A8(void);
    void fn_800BC82C(void);
    void fn_800BC7C8(void);
    void fn_800BC760(void);
    void fn_800BC6E8(void);
    void fn_800BC684(void);
    void fn_800BC5FC(void);
    void fn_800BC588(void);
    void fn_800BC458(void);
    void fn_800BC4FC(void);
    void fn_800BC3F4(void);
    void fn_800BC380(void);
    void fn_800BC29C(void);
    void fn_800BC204(void);
    void Unit_SetItemDroppable(void);
    void fn_800BC0A4(void);
    void fn_800BBFD0(void);
    void fn_800BBF04(void);
    void fn_800BCC34(void);
    void fn_800BCC14(void);
    void fn_800BCBBC(void);
    void fn_800BCB80(void);
    void fn_800BCB38(void);
    void fn_800BCB0C(void);
    void fn_800BCAFC(void);
    void fn_800BCC24(void);
    void fn_800BCC04(void);
    void fn_800BCB24(void);
    void fn_800BCB70(void);
    void fn_800BCAEC(void);
    void fn_800BCADC(void);
    void fn_800BBD68(void);
    void fn_800BBE9C(void);
    void fn_800BBE1C(void);
    void fn_800BBD9C(void);
    void fn_8000CEE4(void);
    void fn_800BBD44(void);
    void fn_800BBD20(void);
    void fn_800BBCFC(void);
    void fn_800BBC58(void);
    void fn_800BBC50(void);
    void fn_800BBC40(void);
    void fn_800BBC14(void);
    void fn_800BBB58(void);
    void fn_800BBA38(void);
    void fn_800BB9E8(void);
    void fn_800BB9E0(void);

    Script_RegisterCommand(lbl_8026F728 + 0x101, fn_800BD610, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x10F, fn_800BD5E0, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x11D, fn_800BD704, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x125, fn_800BD638, 3);
    Script_RegisterCommand(lbl_8026F728 + 0x12D, fn_800BD470, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x139, fn_800BD424, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x146, fn_800BD5AC, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x153, ScriptCmd_UnitGetByPos, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x160, fn_800BD0CC, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x169, fn_800BD08C, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x172, fn_800BD034, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x17F, fn_800BCFF4, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x189, fn_800BCC88, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x195, fn_800BD3DC, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x1A3, fn_800BD388, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x1B1, fn_800BD334, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x1BF, fn_800BCF9C, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x1C9, fn_800BCF44, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x1D4, fn_800BCDF0, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x1E4, fn_800BCD7C, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x1F6, fn_800BCD58, 0);
    Script_RegisterCommand(lbl_8026F728 + 0x200, fn_800BCD34, 0);
    Script_RegisterCommand(lbl_8026F728 + 0x20E, fn_800BCD24, 0);
    Script_RegisterCommand(lbl_8026F728 + 0x21A, fn_800BCC44, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x225, fn_800BCED4, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x232, fn_800BCE64, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x23F, fn_800BCA38, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x253, fn_800BD284, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x25F, fn_800BD1A4, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x26A, fn_800BD10C, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x27A, fn_800BC9D4, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x28D, fn_800BC970, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x29E, fn_800BC90C, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x2AF, fn_800BC8A8, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x2C0, fn_800BC82C, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x2CF, fn_800BC7C8, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x2DB, fn_800BC760, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x2E7, fn_800BC6E8, 3);
    Script_RegisterCommand(lbl_8026F728 + 0x2F7, fn_800BC684, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x30A, fn_800BC5FC, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x31B, fn_800BC588, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x32A, fn_800BC458, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x337, fn_800BC4FC, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x344, fn_800BC3F4, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x355, fn_800BC380, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x366, fn_800BC29C, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x378, fn_800BC204, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x387, Unit_SetItemDroppable, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x397, fn_800BC0A4, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x3AC, fn_800BBFD0, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x3BF, fn_800BBFD0, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x3DA, fn_800BBF04, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x3F2, fn_800BCC34, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x3FC, fn_800BCC14, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x407, fn_800BCBBC, 4);
    Script_RegisterCommand(lbl_8026F728 + 0x412, fn_800BCB80, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x41D, fn_800BCB38, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x427, fn_800BCB0C, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x432, fn_800BCAFC, 0);
    Script_RegisterCommand(lbl_8026F728 + 0x43F, fn_800BCC24, 0);
    Script_RegisterCommand(lbl_8026F728 + 0x449, fn_800BCC04, 0);
    Script_RegisterCommand(lbl_8026F728 + 0x454, fn_800BCB24, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x45F, fn_800BCB70, 0);
    Script_RegisterCommand(lbl_8026F728 + 0x46A, fn_800BCAEC, 0);
    Script_RegisterCommand(lbl_8026F728 + 0x474, fn_800BCADC, 0);
    Script_RegisterCommand(lbl_8026F728 + 0x47E, fn_800BBD68, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x48B, fn_800BBE9C, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x498, fn_800BBE1C, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x4A5, fn_800BBD9C, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x4B2, fn_8000CEE4, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x4B9, fn_800BBD44, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x4C4, fn_800BBD20, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x4D2, fn_800BBCFC, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x4DE, fn_800BBC58, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x4EE, fn_800BBC50, 0);
    Script_RegisterCommand(lbl_8026F728 + 0x4F3, fn_800BBC40, 0);
    Script_RegisterCommand(lbl_8026F728 + 0x501, fn_800BBC14, 0);
    Script_RegisterCommand(lbl_8026F728 + 0x50D, fn_800BBB58, 2);
    Script_RegisterCommand(lbl_8026F728 + 0x520, fn_800BBA38, 3);
    Script_RegisterCommand(lbl_8026F728 + 0x533, fn_800BB9E8, 1);
    Script_RegisterCommand(lbl_8026F728 + 0x543, fn_800BB9E0, 0);
}

s32 fn_800BB9E0(void) {
    return 1;
}

s32 fn_800BB9E8(u8 arg0) {
    extern u8 gUnits[];
    u8 *var_r4;
    s32 temp_r3;

    if (arg0 != 0) {
        var_r4 = gUnits + (arg0 - 1) * 0x280;
    } else {
        var_r4 = NULL;
    }
    if ((var_r4 == NULL) || (*(u32 *)(var_r4 + 0x188) == 0U)) {
        return 0;
    }
    temp_r3 = *(s32 *)(var_r4 + 0x254) & 0xFCFFFFFF;
    *(s32 *)(var_r4 + 0x254) = temp_r3;
    return temp_r3;
}

s32 fn_800BBB58(s32 arg0, s32 arg1) {
    u32 Unit_FindByName(s32);
    s8 fn_80036DE0(u32, u32);
    void fn_80036FC4(u32, s8);
    u8 Unit_GetSupportRank(u32, s8);
    s8 temp_r31;
    u32 temp_r30;
    u32 temp_r29;
    s8 temp_r3;

    temp_r30 = Unit_FindByName(arg0);
    temp_r29 = Unit_FindByName(arg1);
    if (temp_r30 == 0 || temp_r29 == 0) {
        return -1;
    }
    temp_r31 = fn_80036DE0(temp_r30, temp_r29);
    temp_r3 = fn_80036DE0(temp_r29, temp_r30);
    if (temp_r31 < 0 || temp_r3 < 0) {
        return -1;
    }
    temp_r31 = (s8)temp_r31;
    fn_80036FC4(temp_r30, temp_r31);
    return (u8)Unit_GetSupportRank(temp_r30, temp_r31);
}

u8 fn_800BBC14(void) {
    s32 SystemSave_CountPackedSlots(void *);
    extern u8 gSystemSave[];
    return (u8)SystemSave_CountPackedSlots(gSystemSave);
}

s32 fn_800BBC40(void) {
    extern u16 gBattle[];
    return *(s32 *)((u8 *)gBattle + 0xcac);
}

s32 fn_800BBC50(void) {
    extern s32 gUiInputFlags;
    return gUiInputFlags;
}

s16 fn_800BBC58(u8 arg0, s32 arg1) {
    void fn_800227F8(void *, s32);
    extern u8 gUnits[];
    extern u8 gBattleMap[];
    s16 var_r3;
    u16 temp_r0;
    void *var_r4;

    if (arg0 != 0) {
        var_r4 = gUnits + (arg0 - 1) * 0x280;
    } else {
        var_r4 = NULL;
    }
    if ((var_r4 == NULL) || ((u32) M2C_FIELD(var_r4, u32 *, 0x188) == 0U)) {
        return 0;
    }
    fn_800227F8(gBattleMap, M2C_FIELD(var_r4, s32 *, 0x18C));
    temp_r0 = ((u16 *)(gBattleMap + 0x10000) + arg1)[0x210A];
    var_r3 = (s16) temp_r0;
    if ((s16) temp_r0 > 0x7530) {
        var_r3 = -1;
    }
    return var_r3;
}

u8 fn_800BBCFC(s8 arg0, s8 arg1) {
    extern u8 gBattleMap[];
    return gBattleMap[arg0 + (arg1 << 6) + 0x200D];
}

u8 fn_800BBD20(s8 arg0, s8 arg1) {
    extern u8 gBattleMap[];
    return gBattleMap[arg0 + (arg1 << 6) + 0x100D];
}

u8 fn_800BBD44(s8 arg0, s8 arg1) {
    extern u8 gBattleMap[];
    return gBattleMap[arg0 + (arg1 << 6) + 0xD];
}

u16 fn_800BBD68(void) {
    void *Item_GetByIid();
    void *temp_r3;

    temp_r3 = Item_GetByIid();
    if (temp_r3 == NULL) {
        return 0U;
    }
    return M2C_FIELD(temp_r3, u16 *, 0xE);
}

s32 fn_800BBD9C(u32 arg0, void *arg1)
{
    extern u8 gUnits[];

    extern u8 *fn_80019DD0(void *);
    extern void Status_Set(void *, u32);

    u8 *entry;
    u8 *result;

    if ((u8)arg0 != 0) {
        entry = gUnits + ((u8)arg0 - 1) * 0x280;
    } else {
        entry = 0;
    }

    if (entry == 0 || *(u32 *)(entry + 0x188) == 0) {
        return 0;
    }

    result = fn_80019DD0(arg1);

    Status_Set(entry + 0x1BC, result[0x18]);

    return 1;
}

u32 fn_800BBE1C(u32 arg0, void *arg1)
{
    extern u8 gUnits[];

    extern u8 *fn_80019DD0(void *);
    extern u32 Status_Test(void *, u32);

    u8 *entry;
    u8 *result;

    if ((u8)arg0 != 0) {
        entry = gUnits + ((u8)arg0 - 1) * 0x280;
    } else {
        entry = 0;
    }

    if (entry == 0 || *(u32 *)(entry + 0x188) == 0) {
        return 0;
    }

    result = fn_80019DD0(arg1);

    return (u8)Status_Test(entry + 0x1BC, result[0x18]);
}

s32 fn_800BBE9C(u8 arg0, s32 arg1) {
    void fn_80105DAC(void *);
    extern u8 gUnits[];
    void *unit;

    (void)arg1;
    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    fn_80105DAC((u8 *)unit + 0x1BC);
    return 1;
}

s32 fn_800BBF04(u8 arg0, s32 arg1) {
    u32 *Unit_GetItemSlot(void *, s32);
    void fn_800949A4(void *, s8);
    void fn_800C35C4(void *, u32 *);
    u8 fn_8014D8DC(void *);
    extern u8 gUnits[];
    extern u8 gConvoy[];
    extern u8 gBattleState[];
    u32 *temp_r3;
    void *var_r31;

    if (arg0 != 0) {
        var_r31 = gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r31 = NULL;
    }
    if ((var_r31 == NULL) || (*(u32 *)((u8 *)var_r31 + 0x188) == 0U)) {
        return 0;
    }
    if (fn_8014D8DC(gBattleState) == 0) {
        return 0;
    }
    temp_r3 = Unit_GetItemSlot(var_r31, arg1);
    if (*temp_r3 == 0U) {
        return 0;
    }
    fn_800C35C4(gConvoy, temp_r3);
    fn_800949A4(var_r31, (s8)arg1);
    return 1;
}

s32 fn_800BBFD0(u8 arg0) {
    u32 *Unit_GetItemSlot(void *, s32);
    void fn_800947E0(void *);
    void fn_800C35C4(void *, u32 *);
    void Item_Clear(u32 *);
    extern u8 gUnits[];
    extern u8 gConvoy[];
    void *var_r30;
    u32 *temp_r3;
    s32 var_r28;

    if (arg0 != 0) {
        var_r30 = gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r30 = NULL;
    }
    if ((var_r30 == NULL) || (*(u32 *)((u8 *)var_r30 + 0x188) == 0U)) {
        return 0;
    }
    var_r28 = 0;
    do {
        temp_r3 = Unit_GetItemSlot(var_r30, var_r28);
        if ((temp_r3 != NULL) && (*temp_r3 != 0U)) {
            fn_800C35C4(gConvoy, temp_r3);
            Item_Clear(temp_r3);
        }
        var_r28 += 1;
    } while (var_r28 < 8);
    fn_800947E0(var_r30);
    return 1;
}

s32 fn_800BC0A4(u8 arg0, s32 arg1) {
    s32 fn_8001CA2C(void *);
    u32 *Unit_GetItemSlot(void *, s32);
    extern u8 gUnits[];
    void *unit;
    u32 *temp;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    temp = Unit_GetItemSlot(unit, arg1);
    if (*temp == 0) {
        return 0;
    }
    return fn_8001CA2C(temp);
}

s32 Unit_SetItemDroppable(u8 arg0, s32 arg1) {
    u8 *Unit_GetItemSlot(void *, s32);
    extern u8 gUnits[];
    typedef struct {
        u8 pad:1;
        u8 flag:1;
        u8 rest:6;
    } Bit6;
    void *var_r31;
    s32 i;
    u8 *temp;

    if (arg0 != 0) {
        var_r31 = gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r31 = NULL;
    }
    if ((var_r31 == NULL) || (*(u32 *)((u8 *)var_r31 + 0x188) == 0U)) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        temp = Unit_GetItemSlot(var_r31, i);
        if (*(u32 *)temp != 0U && ((Bit6 *)&temp[5])->flag) {
            return 0;
        }
    }
    temp = Unit_GetItemSlot(var_r31, arg1);
    if (*(u32 *)temp == 0U) {
        return 0;
    }
    ((Bit6 *)&temp[5])->flag = 1;
    return 1;
}

s32 fn_800BC204(u8 arg0) {
    s8 fn_80037CCC(void *);
    extern u8 gUnits[];
    typedef struct {
        u8 flag : 1;
        u8 rest : 7;
    } Bit7;
    void *unit;
    s32 temp;
    s8 slot;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    temp = fn_80037CCC(unit);
    slot = (s8)temp;
    if (slot < 0) {
        return -1;
    }
    ((Bit7 *)((u8 *)unit + slot * 8 + 0x1F1))->flag = 0;
    return slot + 4;
}

s32 fn_800BC29C(u8 arg0) {
    void *Unit_GetHeldItemSlot(void *, s32);
    s32 Unit_GetActiveItemSlot(void *);
    u8 Status_Test(void *, s32);
    void Mu_StartBlend(void *, s32, s32, s32);
    extern u8 gUnits[];
    void *var_r31;
    s8 var_r30;
    void *item;
    u8 t;

    if (arg0 != 0) {
        var_r31 = gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r31 = NULL;
    }
    if ((var_r31 == NULL) || (*(u32 *)((u8 *)var_r31 + 0x188) == 0U)) {
        return 0;
    }
    if (Status_Test((u8 *)var_r31 + 0x1BC, 8) != 0) {
        return -1;
    }
    var_r30 = (s8)Unit_GetActiveItemSlot(var_r31);
    if (var_r30 < 0) {
        return -1;
    }
    item = Unit_GetHeldItemSlot(var_r31, var_r30);
    t = *((u8 *)item + 5);
    *((u8 *)item + 5) = (u8)__rlwimi(t, 0, 7, 24, 24);
    if ((var_r30 >= 0) && (var_r30 <= 3)) {
        Mu_StartBlend(var_r31, 0, 4, 0);
    }
    return var_r30;
}

s8 fn_800BC380(u8 arg0) {
    s32 fn_80037CCC(void *);
    extern u8 gUnits[];
    void *unit;
    s32 temp;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    temp = fn_80037CCC(unit);
    if ((s8)temp >= 0) {
        temp = (s8)(temp + 4);
    }
    return (s8)temp;
}

s8 fn_800BC3F4(u8 arg0) {
    s32 Unit_GetActiveItemSlot(void *);
    extern u8 gUnits[];
    void *unit;
    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    return Unit_GetActiveItemSlot(unit);
}

s32 fn_800BC458(u8 arg0, s32 arg1) {
    void fn_80094CDC(void *, s32);
    void Mu_StartBlend(void *, s32, s32, s32);
    extern u8 gUnits[];
    void *var_r31;

    if (arg0 != 0) {
        var_r31 = gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r31 = NULL;
    }
    if ((var_r31 == NULL) || (*(u32 *)((u8 *)var_r31 + 0x188) == 0U)) {
        return 0;
    }
    fn_80094CDC(var_r31, arg1);
    if ((arg1 >= 0) && (arg1 <= 3)) {
        Mu_StartBlend(var_r31, 0, 4, 0);
    }
    return 1;
}

u8 fn_800BC4FC(u8 arg0, s32 arg1) {
    u32 *Unit_GetItemSlot(s32, s32);
    s32 fn_800939FC(void *, u32);
    extern u8 gUnits[];
    u32 temp_r4;
    void *var_r31;

    if (arg0 != 0) {
        var_r31 = gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r31 = NULL;
    }
    if ((var_r31 == NULL) || ((u32) M2C_FIELD(var_r31, u32 *, 0x188) == 0U)) {
        return 0U;
    }
    temp_r4 = *Unit_GetItemSlot((s32) var_r31, arg1);
    if (temp_r4 != 0U) {
        return fn_800939FC(var_r31, temp_r4);
    }
    return 0U;
}

s32 fn_800BC588(u8 arg0, s32 arg1) {
    u8 *Unit_GetItemSlot(void *, s32);
    extern u8 gUnits[];
    void *unit;
    u8 *p;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    p = Unit_GetItemSlot(unit, arg1);
    return ((p[5] & 0x80) >> 7) != 0;
}

s32 fn_800BC5FC(u8 arg0) {
    s32 fn_80092F38(void *);
    s32 fn_80092F9C(void *);
    extern u8 gUnits[];
    u8 temp_r31;
    u8 temp_r0;
    void *var_r30;

    if (arg0 != 0) {
        var_r30 = gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r30 = NULL;
    }
    if ((var_r30 == NULL) || (*(u32 *)((u8 *)var_r30 + 0x188) == 0U)) {
        return 0;
    }
    temp_r31 = (u8)fn_80092F38(var_r30);
    temp_r0 = (u8)fn_80092F9C(var_r30);
    return temp_r0 + temp_r31;
}

u8 fn_800BC684(u8 arg0) {
    s32 fn_80092F9C(void);
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    return (u8)fn_80092F9C();
}

s32 fn_800BC6E8(u8 arg0, s32 arg1, s32 arg2) {
    void *Unit_GetItemSlot(void *, s32);
    void fn_8001D780(void *, s32);
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    fn_8001D780(Unit_GetItemSlot(unit, arg1), arg2);
    return 1;
}

s32 fn_800BC760(u8 arg0, s8 arg1) {
    void fn_800949A4(void *, s32);
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    fn_800949A4(unit, arg1);
    return 1;
}

s32 fn_800BC7C8(u8 arg0, s32 arg1) {
    void fn_80094A54(void *, s32);
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    fn_80094A54(unit, arg1);
    return 1;
}

s32 fn_800BC82C(u8 arg0, s32 arg1) {
    s32 Item_GetByIid(s32);
    s32 fn_80093010(void *, s32);
    extern u8 gUnits[];
    u8 *entry;
    s32 tmp;

    if (arg0 != 0) {
        entry = gUnits + (arg0 - 1) * 0x280;
    } else {
        entry = 0;
    }

    if (entry == 0 || *(u32 *)(entry + 0x188) == 0) {
        return 0;
    }

    tmp = Item_GetByIid(arg1);
    return fn_80093010(entry, tmp);
}

s32 fn_800BC8A8(u8 arg0, s32 arg1) {
    void fn_8003C56C(void *, s32);
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    fn_8003C56C(unit, arg1);
    return 1;
}

s32 fn_800BC90C(u8 arg0, s32 arg1) {
    void fn_8003C5AC(void *, s32);
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    fn_8003C5AC(unit, arg1);
    return 1;
}

s32 fn_800BC970(u8 arg0, s32 arg1) {
    void fn_8003C5EC(void *, s32);
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    fn_8003C5EC(unit, arg1);
    return 1;
}

s32 fn_800BC9D4(u8 arg0, s32 arg1) {
    void fn_8003C634(void *, s32);
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    fn_8003C634(unit, arg1);
    return 1;
}

s32 fn_800BCA38(u8 arg0, s32 arg1) {
    void *fn_80016A9C(s32);
    void Unit_SetDisposId(void *, u8);
    void Unit_MoveToList(void *, s32);
    void fn_80050268(void *);
    extern u8 gUnits[];
    void *temp_r3;
    void *var_r31;

    if (arg0 != 0) {
        var_r31 = gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r31 = NULL;
    }
    if ((var_r31 == NULL) || (*(u32 *)((u8 *)var_r31 + 0x188) == 0U)) {
        return 0;
    }
    temp_r3 = fn_80016A9C(arg1);
    if (temp_r3 != NULL) {
        Unit_SetDisposId(var_r31, *(u8 *)((u8 *)temp_r3 + 0x199));
    }
    Unit_MoveToList(var_r31, arg1);
    fn_80050268(var_r31);
    return 1;
}

s16 fn_800BCADC(void) {
    extern u8 lbl_8031FFC0[];
    return *(s16 *)((char *)lbl_8031FFC0 + 2);
}

s16 fn_800BCAEC(void) {
    extern u8 lbl_8031FFC0[];
    return *(s16 *)((char *)lbl_8031FFC0 + 0);
}

u8 fn_800BCAFC(void) {
    extern u16 gBattleState[];
    return (*(u8*)((u8*)&gBattleState[0x10/2]));
}

s16 fn_800BCB0C(s32 arg0, s16 arg1) {
    extern u16 gBattleState[];
    gBattleState[arg0] = arg1;
    return arg1;
}

extern u16 gBattleState[700];
s32 fn_800BCB24(s32 arg0) {
    return ((s16 *)gBattleState)[arg0];
}

s32 fn_800BCB38(s32 arg0, s32 arg1) {
    void fn_8014CA98(void *, s32, s32);
    extern u16 gBattleState[700];

    fn_8014CA98(gBattleState, arg0, arg1);
    return 1;
}

extern u16 gBattleState[];
s32 fn_800BCB70(void) {
    return *(s32*)(((char*)&gBattleState) + 0x18);
}

s32 fn_800BCB80(s32 arg0) {
    extern u16 gBattleState[700];
    fn_8014D268(gBattleState, arg0);
    return arg0;
}

s32 fn_800BCBBC(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    fn_8014D254(gBattleState, arg0, arg1, arg2, arg3);
    return 1;
}

u8 fn_800BCC04(void) {
    return *(u8 *)((u8 *)gBattleState + 0x11);
}

void fn_800BCC14(s8 arg0) {
    *(u8*)((u8*)gBattleState + 0x11) = arg0;
}

s16 fn_800BCC24(void) {
    return *(s16*)((char*)gBattleState + 0x12);
}

void fn_800BCC34(s16 arg0) {
    *(u16*)((char*)gBattleState + 0x12) = arg0;
}

#pragma peephole off
s32 fn_800BCC44(void) {
    void *Unit_FindByPerson(void);
    void Person_GetByPid(void);
    void *temp_r3;

    Person_GetByPid();
    temp_r3 = Unit_FindByPerson();
    if (temp_r3 == NULL) {
        return 0;
    }
    return (*(s32 *)((u8 *)temp_r3 + 0x1A0) & 8) == 0;
}

#pragma peephole reset
s32 fn_800BCC88(u8 arg0) {
    u8 Status_Test(void *, s32);
    extern u8 gUnits[];
    void *var_r31;

    if (arg0 != 0) {
        var_r31 = gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r31 = NULL;
    }
    if ((var_r31 == NULL) || ((u32) *(u32 *)((u8 *)var_r31 + 0x188) == 0U)) {
        return 0;
    }
    if (Status_Test((u8 *)var_r31 + 0x1BC, 9) != 0) {
        return 2;
    }
    return Status_Test((void *)((u32)var_r31 + 0x1BC), 8) != 0;
}
extern u8 gUiContext[24];
u8 fn_800BCD24(void) {
    return gUiContext[9];
}

u8 fn_800BCD34(void) {
    extern u8 gUiContext[24];
    u8 *p = *(u8 **)(gUiContext + 4);
    if (p != NULL) {
        return p[0x198];
    }
    return 0;
}

u8 fn_800BCD58(void) {
    extern u8 gUiContext[24];
    u8 *p = *(u8 **)gUiContext;
    if (p != NULL) {
        return p[0x198];
    }
    return 0;
}

s32 fn_800BCD7C(u8 arg0) {
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(void **)((u8 *)unit + 0x188) == NULL) {
        return 0;
    }
    switch (*(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) {
    case 0:
    case 5:
        *(u32 *)((u8 *)unit + 0x1A0) |= 0x20000;
        break;
    }
    return 1;
}

s32 fn_800BCDF0(u8 arg0) {
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || M2C_FIELD(unit, void **, 0x188) == NULL) {
        return 0;
    }
    switch (M2C_FIELD(M2C_FIELD(unit, void **, 0x190), u8 *, 8)) {
    case 0:
    case 5:
        M2C_FIELD(unit, u32 *, 0x1A0) |= 0x10000;
        break;
    }
    return 1;
}

s32 fn_800BCE64(u32 arg0, s32 arg1)
{
    extern u8 gUnits[];
    s32 Job_GetByJid(s32);

    u8 *unit;
    s32 value;

    if ((u8)arg0 != 0) {
        unit = gUnits + ((u8)arg0 - 1) * 0x280;
    } else {
        unit = 0;
    }

    if (unit == 0) {
        return 0;
    }

    value = *(s32 *)(unit + 0x18C);

    return (u8)(value == Job_GetByJid(arg1));
}

s32 fn_800BCED4(u32 arg0, void *arg1)
{
    extern u8 gUnits[];
    extern void *Person_GetByPid(void *);

    u8 *unit;
    void *value;

    if ((u8)arg0 != 0) {
        unit = gUnits + ((u8)arg0 - 1) * 0x280;
    } else {
        unit = 0;
    }

    if (unit == 0) {
        return 0;
    }

    value = *(void **)(unit + 0x188);

    return (u8)(value == Person_GetByPid(arg1));
}

s32 fn_800BCF44(u8 arg0, s32 arg1) {
    M2C_UNK fn_8003868C(void *, s32);
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL) {
        return 0;
    }
    fn_8003868C(unit, arg1);
    return 0;
}

s32 fn_800BCF9C(u8 arg0, s32 arg1) {
    M2C_UNK Unit_SetHp(void *, s32);
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL) {
        return 0;
    }
    Unit_SetHp(unit, arg1);
    return 0;
}

s32 fn_800BCFF4(u8 arg0)
{
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL) {
        return 0;
    }
    return *(s8 *)((u8 *)unit + 0x1A8);
}

s32 fn_800BD034(u8 arg0) {
    s8 Unit_GetMaxHp(void *);
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL) {
        return 0;
    }
    return Unit_GetMaxHp(unit);
}

s32 fn_800BD08C(u8 arg0) {
    extern u8 gUnits[];
    void *unit;

    if (arg0 != 0) {
        unit = gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL) {
        return 0;
    }
    return M2C_FIELD(unit, s8 *, 0x19F);
}

extern u16 gUnits[];
s32 fn_800BD0CC(u8 arg0) {
    void *var_r3;

    if (arg0 != 0) {
        var_r3 = &gUnits[(arg0 - 1) * 0x140];
    } else {
        var_r3 = NULL;
    }
    if (var_r3 == NULL) {
        return 0;
    }
    return *(s8 *)((u8 *)var_r3 + 0x19E);
}

s32 fn_800BD10C(u8 arg0) {
    u8 Status_Test(void *, s32);
    s32 fn_800C0658(void);
    void fn_801EDA88(void *, s32);
    void fn_80013864(void);
    void *unit;

    if (arg0 != 0) {
        unit = (u8 *)gUnits + (arg0 - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    if (Status_Test((u8 *)unit + 0x1bc, 0x4d) == 0) {
        return 0;
    }
    fn_801EDA88(unit, fn_800C0658());
    fn_80013864();
    return 1;
}

s32 fn_800BD1A4(u8 arg0, u8 arg1) {
    void Unit_SetMapPos(void *, s8, u8);
    void fn_8003EA84(void *, void *);
    void Map_RefreshUnitMap(void *);
    extern u8 gBattleMap[];
    void *var_r31;
    void *var_r30;

    if (arg0 != 0) {
        var_r31 = (u8 *)gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r31 = NULL;
    }
    if (var_r31 == NULL || *(u32 *)((u8 *)var_r31 + 0x188) == 0U) {
        return 0;
    }
    if (arg1 != 0) {
        var_r30 = (u8 *)gUnits + ((arg1 - 1) * 0x280);
    } else {
        var_r30 = NULL;
    }
    if (var_r30 == NULL || *(u32 *)((u8 *)var_r30 + 0x188) == 0U) {
        return 0;
    }
    Unit_SetMapPos(var_r30, (s8)(*(u8 *)((u8 *)var_r31 + 0x19E) + 1), *(u8 *)((u8 *)var_r31 + 0x19F));
    fn_8003EA84(var_r31, var_r30);
    Map_RefreshUnitMap(&gBattleMap);
    return 1;
}

s32 fn_800BD284(u8 arg0) {
    void Unit_SeparateRescue(void *, u8, u8);
    extern u16 gUnits[];
    void *temp_r31;
    void *var_r30;
    void *var_r3;

    if (arg0 != 0) {
        var_r3 = (u8 *)gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r3 = NULL;
    }
    var_r30 = var_r3;
    if ((var_r3 == NULL) || (*(u32 *)((u8 *)var_r3 + 0x188) == 0U)) {
        return 0;
    }
    if (*(s32 *)((u8 *)var_r3 + 0x1A0) & 4) {
        var_r30 = *(void **)((u8 *)var_r3 + 0x194);
    }
    temp_r31 = *(void **)((u8 *)var_r30 + 0x194);
    Unit_SeparateRescue(var_r30, *(u8 *)((u8 *)var_r30 + 0x19E), *(u8 *)((u8 *)var_r30 + 0x19F));
    *(s32 *)((u8 *)var_r30 + 0x1A0) = *(s32 *)((u8 *)var_r30 + 0x1A0) & ~1;
    *(s32 *)((u8 *)temp_r31 + 0x1A0) = *(s32 *)((u8 *)temp_r31 + 0x1A0) & ~1;
    return 1;
}

s32 fn_800BD334(u8 arg0, s32 arg1)
{
  extern u16 gUnits[];
  u8 *new_var;
  void *var_r3;
  if (arg0 != 0)
  {
    var_r3 = &gUnits[(arg0 - 1) * 0x140];
  }
  else
  {
    var_r3 = NULL;
  }
  if ((var_r3 == NULL) || ((*((u32 *) (((u8 *) var_r3) + 0x188))) == 0U))
  {
    return 0;
  }
  new_var = (u8 *) var_r3;
  *((s32 *) (new_var + 0x1A0)) = (*((s32 *) (new_var + 0x1A0))) | arg1;
  return *((s32 *) (new_var + 0x1A0));
}

s32 fn_800BD388(u8 arg0, s32 arg1)
{
  u8 *new_var;
  void *var_r3;
  if (arg0 != 0)
  {
    var_r3 = &gUnits[(arg0 - 1) * 0x140];
  }
  else
  {
    var_r3 = NULL;
  }
  if ((var_r3 == NULL) || ((*((u32 *) (((u8 *) var_r3) + 0x188))) == 0U))
  {
    return 0;
  }
  new_var = (u8 *) var_r3;
  *((s32 *) (new_var + 0x1A0)) = *((s32 *) (new_var + 0x1A0));
  *((s32 *) (new_var + 0x1A0)) = (*((s32 *) (new_var + 0x1A0))) & (~arg1);
  return *((s32 *) (new_var + 0x1A0));
}

s32 fn_800BD3DC(u8 arg0) {
    extern u16 gUnits[];
    void *var_r3;

    if (arg0 != 0) {
        var_r3 = &gUnits[(arg0 - 1) * 0x140];
    } else {
        var_r3 = NULL;
    }
    if ((var_r3 == NULL) || (*(u32 *)((u8 *)var_r3 + 0x188) == 0U)) {
        return 0;
    }
    return *(s32 *)((u8 *)var_r3 + 0x1A0);
}

u8 fn_800BD424(u8 arg0) {
    extern u16 gUnits[];
    void *var_r3;

    if (arg0 != 0) {
        var_r3 = &gUnits[(arg0 - 1) * 0x140];
    } else {
        var_r3 = NULL;
    }
    if ((var_r3 == NULL) || (*(u32 *)((u8 *)var_r3 + 0x188) == 0U)) {
        return 0U;
    }
    return *(u8 *)((u8 *)*(void **)((u8 *)var_r3 + 0x190) + 8);
}

u8 fn_800BD470(u8 arg0) {
    extern u16 gUnits[];
    void *temp_r3;
    void *var_r3;

    if (arg0 != 0) {
        var_r3 = (void *)((u8 *)gUnits + ((arg0 - 1) * 0x280));
    } else {
        var_r3 = NULL;
    }
    if (var_r3 == NULL) {
        return 0U;
    }
    temp_r3 = *(void **)((u8 *)var_r3 + 0x184);
    if (temp_r3 != NULL) {
        return *(u8 *)((u8 *)temp_r3 + 0x198);
    }
    return 0U;
}

u8 ScriptCmd_UnitGetByPos(s32 mapX, s32 mapY) {
    /* Return the unit index at (mapX, mapY), or 0 if none among allegiances 0-3. */
    void Allegiance_FillMask(s32, void *);
    extern u16 gUnits[];
    u8 allegMask[8];
    u8 *found;
    u8 *unit;
    s32 i;

    found = NULL;
    Allegiance_FillMask(3, allegMask);
    for (i = 1; i <= 0x9F; i++) {
        if ((u8)i != 0) {
            unit = (u8 *)gUnits + ((u8)i - 1) * 0x280;
        } else {
            unit = NULL;
        }
        if (*(u32 *)(unit + 0x188) != 0) {
            if (allegMask[*(u8 *)(*(u8 **)(unit + 0x190) + 8)] != 0) {
                if (!(*(u32 *)(unit + 0x1A0) & 0x1C)) {
                    if (mapX == (s8)*(u8 *)(unit + 0x19E)) {
                        if (mapY == (s8)*(u8 *)(unit + 0x19F)) {
                            found = unit;
                        }
                    }
                }
            }
        }
    }
    if (found == NULL) {
        return 0;
    }
    return found[0x198];
}

u8 fn_800BD5AC(void) {
    void *Unit_FindByName();
    void *temp_r3;

    temp_r3 = Unit_FindByName();
    if (temp_r3 == NULL) {
        return 0U;
    }
    return M2C_FIELD(temp_r3, u8 *, 0x198);
}

void fn_800BD5E0(s32 arg0) {
    void fn_80015680(void *);
    extern u8 gUnitLists[];
    fn_80015680(&gUnitLists[arg0 * 0xC]);
}

extern u16 gUnitLists[50];
u8 fn_800BD610(s32 arg0) {
    extern u16 gUnitLists[50];
    void *temp_r3;

    temp_r3 = *(void **)((u8 *)gUnitLists + (arg0 * 0xC));
    if (temp_r3 == NULL) {
        return 0U;
    }
    return *(u8 *)((u8 *)temp_r3 + 0x198);
}

s32 fn_800BD638(u8 id,s32 mid,s32 val) {
extern u16 gUnits[]; void fn_8003868C(void*,s32); void Unit_SetHp(void*,s32); void Unit_SetDisposId(void*,u8);
u8 *unit;
if(id!=0) unit=(u8*)gUnits+(id-1)*0x280; else unit=0;
if(unit==0 || *(u32*)(unit+0x188)==0) return 0;
switch(mid) {
case 1: case 2: case 3: case 4: case 5: case 9: case 10: case 11: case 12: case 14: case 15: case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23: case 24: case 25: case 27: case 28: case 29: case 30: case 31: case 32: case 33: case 34: case 35: case 36: case 37: return 0;
case 0: unit[0x19A]=val; break;
case 6: fn_8003868C(unit,val); break;
case 7: unit[0x19C]=val; break;
case 8: Unit_SetHp(unit,val); break;
case 13: *(s16*)(unit+0x228)=val; break;
case 0x26: Unit_SetDisposId(unit,(u8)val); break;
}
return val;
}

void fn_800BDA9C(u8 *arg0, void *arg1)
{
    extern u8 Stream_ReadU8(void *);
    u8 *a0;
    void *a1;
    s32 i;

    a0 = arg0;
    a1 = arg1;
    i = 0;
    do {
        a0[i + 0x300] = Stream_ReadU8(a1);
        i++;
    } while (i < 12);
}

void fn_800BDAF8(u8 *arg0, void *arg1)
{
    extern void Stream_WriteU8(void *, s32);
    u8 *a0;
    void *a1;
    s32 i;

    a0 = arg0;
    a1 = arg1;
    i = 0;
    do {
        Stream_WriteU8(a1, a0[i + 0x300]);
        i++;
    } while (i < 12);
}

void fn_800BDB54(s32 arg0, s32 arg1) {
    s32 addr;
    u8 v;
    s32 bit;

    addr = arg0 + (arg1 >> 3);
    bit = 1 << (arg1 & 7);
    v = *(u8 *)(addr + 0x300);
    *(u8 *)(addr + 0x300) = v & ~bit;
}

void fn_800BDB78(s32 arg0, s32 arg1) {
    s32 addr;
    u8 v;
    s32 bit;

    addr = arg0 + (arg1 >> 3);
    bit = 1 << (arg1 & 7);
    v = *(u8 *)(addr + 0x300);
    *(u8 *)(addr + 0x300) = v | bit;
}

s32 fn_800BDB9C(s32 arg0, s32 arg1) {
    s32 addr;
    u8 *p;

    addr = arg0 + (arg1 >> 3);
    p = (u8 *)addr;
    return (p[0x300] & (1 << (arg1 & 7))) != 0;
}

#pragma use_lmw_stmw on
void fn_800BDBC8(s32 arg0, s32 arg1) {
    s32 var_r30;
    u32 temp_r31;
    s32 temp_r5;
    s32 var_r29;

    temp_r31 = fn_8000D598(arg1);
    var_r29 = arg0;
    var_r30 = 0;
loop_1:
    if ((temp_r31 == *(u32 *)(var_r29 + 0x180)) && (Str_Cmp(*(s32 *)var_r29, arg1) == 0)) {

    } else {
        var_r30 += 1;
        var_r29 += 4;
        if (var_r30 >= 0x60) {
            var_r30 = -1;
        } else {
            goto loop_1;
        }
    }
    if (var_r30 >= 0) {
        temp_r5 = arg0 + (var_r30 >> 3);
        *(u8 *)(temp_r5 + 0x300) = *(u8 *)(temp_r5 + 0x300) & ~(1 << (var_r30 & 7));
    }
}

#pragma dont_inline on
#pragma use_lmw_stmw on
void fn_800BDC68(void *arg0, void *arg1) {
    s32 var_r30;
    u32 temp_r31;
    s32 temp_r5;
    s32 var_r29;
    s32 a0 = (s32)arg0;
    s32 a1 = (s32)arg1;

    temp_r31 = fn_8000D598(a1);
    var_r29 = a0;
    var_r30 = 0;
loop_1:
    if ((temp_r31 == *(u32 *)(var_r29 + 0x180)) && (Str_Cmp(*(s32 *)var_r29, a1) == 0)) {

    } else {
        var_r30 += 1;
        var_r29 += 4;
        if (var_r30 >= 0x60) {
            var_r30 = -1;
        } else {
            goto loop_1;
        }
    }
    if (var_r30 >= 0) {
        temp_r5 = a0 + (var_r30 >> 3);
        *(u8 *)(temp_r5 + 0x300) = *(u8 *)(temp_r5 + 0x300) | (1 << (var_r30 & 7));
    }
}
#pragma use_lmw_stmw reset
#pragma dont_inline reset

#pragma use_lmw_stmw on
s32 fn_800BDD08(s32 arg0, s32 arg1) {
    s32 fn_8000D598(s32);
    s32 Str_Cmp(s32, s32);
    s32 var_r30;
    u32 temp_r31;
    s32 var_r29;
    s32 bit;
    s32 addr;
    u8 bits;

    if ((s8)*(u8 *)arg1 == 0) {
        return 0;
    }
    temp_r31 = fn_8000D598(arg1);
    var_r29 = arg0;
    var_r30 = 0;
loop_1:
    if ((temp_r31 == *(u32 *)(var_r29 + 0x180)) && (Str_Cmp(*(s32 *)var_r29, arg1) == 0)) {

    } else {
        var_r30 += 1;
        var_r29 += 4;
        if (var_r30 >= 0x60) {
            var_r30 = -1;
        } else {
            goto loop_1;
        }
    }
    if (var_r30 < 0) {
        return 0;
    }
    bit = var_r30 & 7;
    addr = arg0 + (var_r30 >> 3);
    bits = *(u8 *)(addr + 0x300);
    return (bits & (1 << bit)) != 0;
}
#pragma use_lmw_stmw reset
void fn_800BDDCC(void *arg0, s32 arg1) {
    s32 fn_8000D598(s32);
    void *self;
    s32 i;
    u32 *p;
    s32 n;

    self = arg0;
    i = 0x5F;
    n = 0x60;
    p = (u32 *)((u8 *)self + 0x17C);
    do {
        if (*p == 0) {
            ((s32 *)self)[i] = arg1;
            *(s32 *)((u8 *)self + (i << 2) + 0x180) = fn_8000D598(arg1);
            return;
        }
        p--;
        i--;
    } while (--n);
}

void fn_800BDE40(void *arg0, s32 arg1) {
s32 fn_8000D598(s32); void *self; s32 i; u32 *p; s32 off; s32 bitbase;
self=arg0; p=(u32*)arg0;
for(i=0;i<0x60;i++) { if(*p==0) { off=i<<2;
*(s32 *)((u8*)self+off)=arg1;
*(s32 *)((u8*)self+0x180+off)=fn_8000D598(arg1);
bitbase=(s32)self+(i>>3);
*(u8*)(bitbase+0x300)&=~(1<<(i&7));
return; } p++; }
}

void fn_800BDED8(void *arg0) {
    int i;
    u32 *ptr;
    u8 *byte_ptr;

    // First loop: clear 10 fields starting at arg0 + 0x17C
    ptr = (u32*)((char*)arg0 + 0x17C);
    for (i = 0; i < 10; i++) {
        if (*ptr != 0) {
            *ptr = 0;
            *(ptr + 0x60) = 0; // offset 0x180
        }
        ptr -= 0x8; // move to next field
    }

    // Second loop: clear bits in a bitset
    byte_ptr = (u8*)arg0;
    for (i = 0; i < 0x18; i++) {
        if (*(u32*)((char*)arg0 + i * 0x4) != 0) {
            s32 index = i >> 3;
            s32 bit = i & 7;
            u32 mask = (1 << bit);
            byte_ptr[index + 0x300] &= ~mask;
        }
    }

    // This function is complete - no additional work needed
}

void fn_800BE068(void *arg0) {
    s32 i;
    s32 *ptr;
    u8 *byte_ptr;

    *(u8*)((uintptr_t)arg0 + 0x300) = 0;
    *(u8*)((uintptr_t)arg0 + 0x301) = 0;
    *(u8*)((uintptr_t)arg0 + 0x302) = 0;
    *(u8*)((uintptr_t)arg0 + 0x303) = 0;
    *(u8*)((uintptr_t)arg0 + 0x304) = 0;
    *(u8*)((uintptr_t)arg0 + 0x305) = 0;
    *(u8*)((uintptr_t)arg0 + 0x306) = 0;
    *(u8*)((uintptr_t)arg0 + 0x307) = 0;
    *(u8*)((uintptr_t)arg0 + 0x308) = 0;
    *(u8*)((uintptr_t)arg0 + 0x309) = 0;
    *(u8*)((uintptr_t)arg0 + 0x30A) = 0;
    *(u8*)((uintptr_t)arg0 + 0x30B) = 0;

    ptr = (s32*)((uintptr_t)arg0 + 0x17C);
    for (i = 0xC; i > 0; i--) {
        if (*ptr != 0) {
            *ptr = 0;
            *(ptr + 0x60) = 0;
        }

        ptr--;
        if (*ptr != 0) {
            *ptr = 0;
            *(ptr + 0x5F) = 0;
        }

        ptr--;
        if (*ptr != 0) {
            *ptr = 0;
            *(ptr + 0x5E) = 0;
        }

        ptr--;
        if (*ptr != 0) {
            *ptr = 0;
            *(ptr + 0x5D) = 0;
        }

        ptr--;
        if (*ptr != 0) {
            *ptr = 0;
            *(ptr + 0x5C) = 0;
        }

        ptr--;
        if (*ptr != 0) {
            *ptr = 0;
            *(ptr + 0x5B) = 0;
        }

        ptr--;
        if (*ptr != 0) {
            *ptr = 0;
            *(ptr + 0x5A) = 0;
        }

        ptr--;
        if (*ptr != 0) {
            *ptr = 0;
            *(ptr + 0x59) = 0;
        }
    }

    byte_ptr = (u8*)arg0;

    i = 0;
    do {
        s32 temp_r5 = i << 3;
        s32 *ptr = (s32*)(byte_ptr + temp_r5);
        
        if (*ptr != 0) {
            u32 byte_idx = temp_r5 >> 3;
            u8 bit = temp_r5 & 7;
            u8* target_byte = (u8*)((uintptr_t)arg0 + 0x300 + byte_idx);
            *target_byte &= ~((1 << bit));
        }
        
        ptr++;
        if (*ptr != 0) {
            u32 byte_idx = (temp_r5 + 4) >> 3;
            u8 bit = (temp_r5 + 4) & 7;
            u8* target_byte = (u8*)((uintptr_t)arg0 + 0x300 + byte_idx);
            *target_byte &= ~((1 << bit));
        }
        
        ptr++;
        if (*ptr != 0) {
            u32 byte_idx = (temp_r5 + 8) >> 3;
            u8 bit = (temp_r5 + 8) & 7;
            u8* target_byte = (u8*)((uintptr_t)arg0 + 0x300 + byte_idx);
            *target_byte &= ~((1 << bit));
        }
        
        ptr++;
        if (*ptr != 0) {
            u32 byte_idx = (temp_r5 + 12) >> 3;
            u8 bit = (temp_r5 + 12) & 7;
            u8* target_byte = (u8*)((uintptr_t)arg0 + 0x300 + byte_idx);
            *target_byte &= ~((1 << bit));
        }

        i++;
    } while (i < 0x18);
}

void fn_800BE228(s32 *arg0) {
    s32 *p;
    s32 i;

    p = arg0;
    for (i = 0; i < 6; i++) {
        p[0] = 0;
        p[0x60] = 0;
        p[1] = 0;
        p[0x61] = 0;
        p[2] = 0;
        p[0x62] = 0;
        p[3] = 0;
        p[0x63] = 0;
        p[4] = 0;
        p[0x64] = 0;
        p[5] = 0;
        p[0x65] = 0;
        p[6] = 0;
        p[0x66] = 0;
        p[7] = 0;
        p[0x67] = 0;
        p[8] = 0;
        p[0x68] = 0;
        p[9] = 0;
        p[0x69] = 0;
        p[10] = 0;
        p[0x6A] = 0;
        p[11] = 0;
        p[0x6B] = 0;
        p[12] = 0;
        p[0x6C] = 0;
        p[13] = 0;
        p[0x6D] = 0;
        p[14] = 0;
        p[0x6E] = 0;
        p[15] = 0;
        p[0x6F] = 0;
        p += 16;
    }

    ((u8 *)arg0)[0x300] = 0;
    ((u8 *)arg0)[0x301] = 0;
    ((u8 *)arg0)[0x302] = 0;
    ((u8 *)arg0)[0x303] = 0;
    ((u8 *)arg0)[0x304] = 0;
    ((u8 *)arg0)[0x305] = 0;
    ((u8 *)arg0)[0x306] = 0;
    ((u8 *)arg0)[0x307] = 0;
    ((u8 *)arg0)[0x308] = 0;
    ((u8 *)arg0)[0x309] = 0;
    ((u8 *)arg0)[0x30A] = 0;
    ((u8 *)arg0)[0x30B] = 0;
}

#pragma global_optimizer off
s32 fn_800BE2F4(void) {
    u8 fn_800BDD08(void *, void *);
    void fn_8002D780(s32);
    void fn_8000BD98(void *);
    void Process_UnlinkByKey(void *);
    extern u8 lbl_8026FC78[];
    extern u8 lbl_8028E7F8[];
    void *obj;

    obj = (u8 *)gBattleState + 0xB4;
    if (fn_800BDD08(obj, lbl_8026FC78 + 0xF9) != 0) {
        fn_8002D780(3);
    }
    if (fn_800BDD08(obj, lbl_8026FC78 + 0x105) != 0) {
        fn_8002D780(1);
    }
    if (fn_800BDD08(obj, lbl_8026FC78 + 0xF9) != 0 ||
        fn_800BDD08(obj, lbl_8026FC78 + 0x105) != 0) {
        fn_8000BD98(lbl_8026FC78 + 0x111);
        Process_UnlinkByKey(lbl_8028E7F8);
        return 1;
    }
    return 0;
}
#pragma global_optimizer off
s32 fn_800BE57C(void *arg0) {
    void fn_800C273C(void *, u32);
    void *Person_GetByPid(void);
    void *Person_Get(s32);
    extern s16 lbl_8031FFC0[];
    void *obj;
    void *v1;
    void *v2;
    void *v3;
    void *v4;

    obj = arg0;
    if (lbl_8031FFC0[0] != *(s16 *)((u8 *)obj + 0x18)) {
        return 0;
    }
    fn_800C273C(obj, (u16)*(s16 *)((u8 *)obj + 0x14));
    v1 = Person_GetByPid();
    fn_800C273C(obj, (u16)*(s16 *)((u8 *)obj + 0x16));
    v2 = Person_GetByPid();
    v3 = Person_Get(lbl_8031FFC0[3]);
    v4 = Person_Get(lbl_8031FFC0[4]);
    if (v3 == v1 && v4 == v2) {
        return 1;
    }
    if (v3 == v2 && v4 == v1) {
        return 1;
    }
    return 0;
}
#pragma global_optimizer on
void fn_800BE658(s32 arg0, s32 arg1) {
    void *fn_80013B60(void *);
    void *Process_CreateChild(void *, s32);
    void fn_800BDBC8(void *, void *);
    extern u8 lbl_8031FFC0[];
    extern u8 lbl_8028D4F8[];
    extern u8 lbl_8026FC78[];
    extern s32 gUiInputFlags;
    s32 count;
    u8 *entry;
    s32 kind;
    void *tmp;

    entry = fn_80013B60(0);
    count = 0;
    kind = 0xE;
    while (entry != 0) {
        if (entry[0xC] == kind) {
            if (count++ == arg0) {
                break;
            }
        }
        entry = fn_80013B60(entry);
    }
    lbl_8031FFC0[0xA] = 0;
    tmp = Process_CreateChild(lbl_8028D4F8, arg1);
    *(void **)((u8 *)tmp + 0x30) = entry;
    fn_800BDBC8((u8 *)gBattleState + 0xB4, lbl_8026FC78 + 0x11C);
    gUiInputFlags &= ~1;
}

void fn_800BE728(s32 arg0) {
    void *fn_80013B60(void *);
    void fn_800C273C(void *, u32);
    u8 *entry;
    s32 count;
    s32 kind;

    kind = 0xE;
    entry = fn_80013B60(0);
    count = 0;
    while (entry != 0) {
        if (entry[0xC] == kind) {
            if (count++ == arg0) {
                break;
            }
        }
        entry = fn_80013B60(entry);
    }
    fn_800C273C(entry, (u16)*(s16 *)(entry + 0x16));
}

s16 fn_800BE798(s32 arg0) {
    void *fn_80013B60(void *);
    u8 *entry;
    s32 count;
    s32 kind;

    kind = 0xE;
    entry = fn_80013B60(0);
    count = 0;
    while (entry != 0) {
        if (entry[0xC] == kind) {
            if (count++ == arg0) {
                break;
            }
        }
        entry = fn_80013B60(entry);
    }
    return *(s16 *)(entry + 0x18);
}

s32 fn_800BE800(s32 arg0) {
    void *fn_80013B60(void *);
    void fn_80013778(s32, void *);
    s32 fn_80013880(void);
    extern u8 lbl_8031FFC0[];
    u8 *entry;
    s32 count;
    s32 kind;

    kind = 0xE;
    entry = fn_80013B60(0);
    count = 0;
    while (entry != 0) {
        if (entry[0xC] == kind) {
            if (count++ == arg0) {
                break;
            }
        }
        entry = fn_80013B60(entry);
    }
    lbl_8031FFC0[0xa] = 1;
    fn_80013778(0, entry);
    return fn_80013880() != 0;
}

extern u8 lbl_80317334[];
extern s32 lbl_80368320;
void fn_800BE890(s32 arg0) {
    void *fn_80013B60(void *);
    s32 fn_800C273C(void *, u32);
    s32 fn_800BDD08(void *, s32, void *);
    u8 *entry;
    s32 count;
    s32 kind;

    kind = 0xE;
    entry = fn_80013B60(0);
    count = 0;
    while (entry != 0) {
        if (entry[0xC] == kind) {
            if (count++ == arg0) {
                break;
            }
        }
        entry = fn_80013B60(entry);
    }
    fn_800BDD08((u8 *)gBattleState + 0xb4, fn_800C273C(entry, (u16)*(s16 *)(entry + 0x14)), gBattleState);
}

s32 fn_800BE914(void)
{
  void *fn_80013B60(void *);
  u8 *entry;
  s32 count;
  int new_var;
  count = 0;
  new_var = 0xE;
  entry = (u8 *) fn_80013B60(0);
  while (entry != 0)
  {
    if (entry[0xC] == new_var)
    {
      count++;
    }
    entry = (u8 *) fn_80013B60(entry);
  }

  return count;
}

void fn_800BEAC0(void* arg0, void* arg1, int arg2) {
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r5;
    
    if (arg2 < 0) {
        return;
    }

    temp_r3 = *(s32*)arg1;
    temp_r4 = *(s32*)((char*)arg1 + 0x1C);
    temp_r5 = *(s32*)((char*)arg1 + 0x20);

    if (temp_r3 < 0) {
        *(s32*)arg0 = -temp_r3;
        *(s32*)((char*)arg0 + 0x1C) = -temp_r4;
        *(s32*)((char*)arg0 + 0x20) = -temp_r5;
    } else {
        *(s32*)arg0 = temp_r3;
        *(s32*)((char*)arg0 + 0x1C) = temp_r4;
        *(s32*)((char*)arg0 + 0x20) = temp_r5;
    }
}

s32 fn_800BF1E8(s32 arg0, s32 arg1, s32 arg2)
{
    M2C_UNK fn_801A5430(s32);
    M2C_UNK fn_801A92F0(s32, s32, s32);
    M2C_UNK fn_801A9290(s32, s32, s32);
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r5;
    
    if (arg0 == 0) {
        arg0 = fn_801A5430(arg2);
    }
    else {
        temp_r3 = arg0;
        
        if (arg1 < 0)
            arg1 += 0x1F;
            
        arg1 >>= 5;
        
        if (arg2 < 0)
            arg2 += 0x1F;
            
        arg2 >>= 5;
        
        temp_r4 = arg2 * 0x564;
        temp_r5 = arg1 * 0x7D8600;
        temp_r5 += temp_r4;
        if (temp_r3 == 1) {
            temp_r3 = fn_801A92F0(temp_r5, 0, 0);
            return temp_r3;
        }
        else {
            temp_r3 = fn_801A9290(temp_r5, 0, 0);
            return temp_r3;
        }
    }
    
    return arg0;
}

s32 fn_800BF32C(void* arg0, void* arg1, s32 arg2) {
    s32* ptr = (s32*)arg0;
    s32 count = arg2 >> 2;
    s32 val;

    if (count <= 0)
        return 0;

    do {
        val = *ptr++;
        if (val == 0)
            return 0;
        *(ptr - 1) = val;
        count--;
    } while (count != 0);

    return 1;
}

s32 fn_800BF494(void *arg0) {
    void *fn_800C273C(void *, u32);
    u8 fn_800BDD08(void *, void *);
    void *Person_GetByPid(void);
    extern u8 gUiContext[24];
    void *v1;
    void *v2;
    void *a;
    void *b;

    if (fn_800BDD08((u8 *)gBattleState + 0xB4,
                    fn_800C273C(arg0, (u16)*(s16 *)((u8 *)arg0 + 0x1A))) != 0) {
        return 0;
    }
    fn_800C273C(arg0, (u16)*(s16 *)((u8 *)arg0 + 0x14));
    v1 = Person_GetByPid();
    fn_800C273C(arg0, (u16)*(s16 *)((u8 *)arg0 + 0x16));
    v2 = Person_GetByPid();
    a = *(void **)(*(u8 **)gUiContext + 0x188);
    b = *(void **)(*(u8 **)(gUiContext + 4) + 0x188);
    if (a == v1 && b == v2) {
        return 1;
    }
    if (*(s16 *)((u8 *)arg0 + 0x18) != 0 && a == v2 && b == v1) {
        return 1;
    }
    return 0;
}

s32 fn_800BF574(s32 arg0) {
    void *fn_80013B60(void *);
    void *Process_CreateChild(void *, s32);
    s32 fn_800BF694(void);
    u8 *entry;
    u8 found;
    void *obj;
    s32 kind;

    kind = 0xF;
    entry = fn_80013B60(0);
    while (entry != 0) {
        if (entry[0xC] == kind) {
            found = 1;
            goto check;
        }
        entry = fn_80013B60(entry);
    }
    found = 0;
check:
    if (found == 0) {
        return 0;
    }
    obj = Process_CreateChild(lbl_8028D544, arg0);
    *(s32 *)((u8 *)obj + 0x34) = 0xF;
    *(s32 *)((u8 *)obj + 0x38) = (s32)fn_800BF694;
    return 1;
}

s32 fn_800BF604(s32 arg0) {
    void *fn_80013B60(void *);
    void *Process_CreateChild(void *, s32);
    s32 fn_800BF694(void);
    u8 *entry;
    u8 found;
    void *obj;
    s32 kind;

    kind = 0x7;
    entry = fn_80013B60(0);
    while (entry != 0) {
        if (entry[0xC] == kind) {
            found = 1;
            goto check;
        }
        entry = fn_80013B60(entry);
    }
    found = 0;
check:
    if (found == 0) {
        return 0;
    }
    obj = Process_CreateChild(lbl_8028D544, arg0);
    *(s32 *)((u8 *)obj + 0x34) = 0x7;
    *(s32 *)((u8 *)obj + 0x38) = (s32)fn_800BF694;
    return 1;
}

s32 fn_800BF694(void) {
    return 1;
}

s32 fn_800BF9D8(void)
{
    extern u32 *gSoundSys;
    extern s8 lbl_80319A58[];
    extern s32 lbl_8028D544[];
    s32 i;
    
    void fn_802C7610(void);
    
    while (gSoundSys[0x31] != 0) {
        fn_802C7610();
        gSoundSys[0x31]--;
    }
    
    for (i = 0; i < 16; i++) {
        lbl_80319A58[i] = 0;
    }
    
    if (gSoundSys[0x111] != 0) {
        gSoundSys[0x111] = 0;
    }
    
    return 1;
}

extern u16* const lbl_8036A0D0;
void fn_800BFCA8(void) {
    gUnitRef = 0x22;
    lbl_8036A0D0[4] = 0;
}

s32 fn_800BFECC(void *arg0)
{
    extern u8 gBattle[];

    extern void fn_800C273C(void *, u32);
    extern void *Person_GetByPid(void);
    extern void *Battle_GetActiveCombatant(void *);

    void *value;
    u8 *unit;
    s16 index;

    index = *(s16 *)((u8 *)arg0 + 0x14);

    fn_800C273C(arg0, (u16)index);

    value = Person_GetByPid();

    unit = (u8 *)Battle_GetActiveCombatant(gBattle);

    if (unit == 0) {
        return 0;
    }

    return *(void **)(unit + 0x188) == value;
}

s32 fn_800BFF30(s32 arg0) {
    void *fn_80013B60(void *);
    void *Process_CreateChild(void *, s32);
    void *fn_800C273C(void *, u32);
    u8 fn_800BDD08(void *, void *);
    s32 fn_800C0190(s32);
    u8 *entry;
    u8 *base;
    u8 found;
    void *obj;
    s32 kind;

    kind = 2;
    entry = fn_80013B60(0);
    base = (u8 *)gBattleState + 0xB4;
    while (entry != 0) {
        if (entry[0xC] == kind) {
            if (fn_800BDD08(base, fn_800C273C(entry, (u16)*(s16 *)(entry + 0x14))) != 0) {
                found = 1;
                goto check;
            }
        }
        entry = fn_80013B60(entry);
    }
    found = 0;
check:
    if (found == 0) {
        return 0;
    }
    obj = Process_CreateChild(lbl_8028D544, arg0);
    *(s32 *)((u8 *)obj + 0x34) = 2;
    *(s32 *)((u8 *)obj + 0x38) = (s32)fn_800C0190;
    return 1;
}

extern s32 lbl_80367FCC;
void fn_800C0190(void *arg0) {
    void *fn_800C273C(void *, u16);
    void fn_800BDD08(void *, void *, void *);
    extern u16 gBattleState[700];

    fn_800BDD08((u8 *)gBattleState + 0xB4, fn_800C273C(arg0, (u16)*(s16 *)((u8 *)arg0 + 0x14)), gBattleState);
}

u32 fn_800C02D4(void *arg0) {
    extern void *lbl_80367190;
    u32 ret;

    if (arg0 == NULL) {
        return **(u32 **)((u8 *)lbl_80367190 + 0x28);
    }
    
    ret = (*(u32 **)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x28))[*(s16 *)((u8 *)arg0 + 0x10) + 1];
    
    if (ret != 0) {
        return ret;
    }
    
    {
        void *p = *(void **)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x1C);
        while (p != NULL) {
            if ((s32)*(u8 *)((u8 *)p + 3) != 0x53) {
                break;
            }
            p = *(void **)((u8 *)p + 0x1C);
        }
        
        if (p == NULL) {
            return 0;
        }
        return **(u32 **)((u8 *)p + 0x28);
    }
}

s32 fn_800C03DC(void *arg0)
{
  s16 *new_var2;
  s16 temp_r5;
  s16 temp_r5_2;
  s16 *new_var;
  temp_r5 = *((s16 *) (((u8 *) arg0) + 0x18));
  if ((temp_r5 >= 0) && (temp_r5 != (*((u8 *) (((u8 *) (&gBattleState)) + 0x11)))))
  {
    return 0;
  }
  ;
  if ((*((s16 *) (((u8 *) arg0) + 0x14))) == 0)
  {
    return 1;
  }
  new_var = (s16 *) (((u8 *) (&gBattleState)) + 0x12);
  new_var2 = new_var;
  if ((*((s16 *) (((u8 *) arg0) + 0x14))) > (*new_var2))
  {
    return 0;
  }
  return (*new_var2) <= (*((s16 *) (((u8 *) arg0) + 0x16)));
}

s32 fn_800C044C(s32 arg0)
{
    void *fn_80013B60(void *);
    u8 *entry;
    s32 count;

    count = 0;
    entry = (u8 *)fn_80013B60(0);
    while (entry != 0) {
        if ((s8)entry[0xC] == arg0) {
            count++;
        }
        entry = (u8 *)fn_80013B60(entry);
    }
    return count;
}

s32 fn_800C04B0(s32 arg0, u8 (*arg1)(void *)) {
    void *fn_80013B60(void *);

    s32 count;
    u8 *entry;

    count = 0;
    entry = (u8 *)fn_80013B60(0);

    while (entry != 0) {
        if ((s8)entry[0xC] == arg0) {
            if (arg1(entry) != 0) {
                count++;
            }
        }

        entry = (u8 *)fn_80013B60(entry);
    }

    return count;
}

void fn_800C054C(void *arg0) {
    void *fn_80013B60(void *);
    void *Process_CreateChild(void *, void *);
    void fn_800BDBC8(void *, void *);
    void Process_ClearFunc(void *);
    extern u8 lbl_8028D4F8[];
    extern u8 lbl_8026FC78[];
    extern s32 gUiInputFlags;

    void *self;
    void *saved;
    void *entry;
    void *tmp;

    self = arg0;
    while ((entry = *(void **)((u8 *)self + 0x30)) != 0) {
        if ((s32)(s8)((u8 *)entry)[0xC] == *(s32 *)((u8 *)self + 0x34)) {
            if (((u8 (*)(void *))*(void **)((u8 *)self + 0x38))(entry) != 0) {
                saved = *(void **)((u8 *)self + 0x30);
                tmp = Process_CreateChild(lbl_8028D4F8, self);
                *(void **)((u8 *)tmp + 0x30) = saved;
                fn_800BDBC8((u8 *)gBattleState + 0xB4, lbl_8026FC78 + 0x11C);
                gUiInputFlags &= ~1;
                *(void **)((u8 *)self + 0x30) = fn_80013B60(*(void **)((u8 *)self + 0x30));
                if (*(void **)((u8 *)self + 0x30) == 0) {
                    goto destroy;
                }
                return;
            }
        }
        *(void **)((u8 *)self + 0x30) = fn_80013B60(*(void **)((u8 *)self + 0x30));
    }
destroy:
    Process_ClearFunc(self);
}

void fn_800C0624(void *arg0) {
    s32 fn_80013B60(M2C_UNK);
    M2C_FIELD(arg0, s32 *, 0x30) = fn_80013B60(0);
}

int fn_800C0658(void) {
    unsigned int Process_Find(void *);
    int fn_801270A4(void);
    extern u8 lbl_8028D4F8[];
    if (Process_Find(lbl_8028D4F8) == 0U) {
        return fn_801270A4();
    }
}

void fn_800C068C(void) {
    void fn_8002846C(void *);
    void fn_80127AC4(void);
    void *Process_Find(void *);
    void Process_UnlinkByKey(void *);
    void *Process_CreateChild(void *, void *);
    void fn_800142D4(void *);
    void *fn_801270A4(void);
    void Process_Goto(void *, s32);
    void fn_80018AE4(void);
    extern u8 gUiContext[24];
    extern s32 gUiInputFlags;
    extern u8 lbl_80284E78[];
    extern u32 lbl_80367848;
    extern u32 lbl_8036784C;
    extern u8 lbl_80284AC8[];
    extern u8 lbl_80320040[];
    extern u8 lbl_8028D4F8[];
    void *obj;
    void *obj2;

    fn_8002846C(gUiContext);
    fn_80127AC4();
    gUiInputFlags &= ~0x890;
    obj = Process_Find(lbl_80284E78);
    if (lbl_80367848 != 0) {
        *(u32 *)((u8 *)obj + 4) = lbl_80367848;
    } else {
        Process_UnlinkByKey(lbl_80284E78);
    }
    if (lbl_8036784C != 0) {
        obj2 = Process_CreateChild(lbl_80284AC8, obj);
        *(u32 *)((u8 *)obj2 + 4) = lbl_8036784C;
    }
    fn_800142D4(lbl_80320040);
    Process_Goto(Process_CreateChild(lbl_8028D4F8, fn_801270A4()), 0);
    fn_80018AE4();
}

void fn_800C0750(void) {
    extern s32 gUiInputFlags;
    extern s32 lbl_80367848;
    extern s32 lbl_8036784C;
    extern u8 lbl_80284E78[];
    extern u8 lbl_80284E30[];
    extern u8 lbl_80284AC8[];
    extern u8 lbl_8026FC78[];
    extern u8 lbl_80320080[];
    void *Process_Find(void *);
    void *Process_FindByName(void *);
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, void *);
    void fn_8000BD98(void *);
    void fn_800142D4(void *);
    void fn_80018AF4(void);
    void *temp;
    s32 val;

    gUiInputFlags |= 0x10;
    temp = Process_Find(lbl_80284E78);
    if (temp != 0) {
        val = *(s32 *)((u8 *)temp + 4);
    } else {
        val = 0;
    }
    lbl_80367848 = val;
    if (temp == 0) {
        Process_Create(lbl_80284E30, Process_CreateChild(lbl_80284E78, Process_FindByName(lbl_8026FC78 + 0x138)));
    }
    temp = Process_Find(lbl_80284AC8);
    if (temp != 0) {
        val = *(s32 *)((u8 *)temp + 4);
    } else {
        val = 0;
    }
    lbl_8036784C = val;
    fn_8000BD98(lbl_8026FC78 + 0xE3);
    fn_800142D4(lbl_80320080);
    fn_80018AF4();
}

void fn_800C0818(u8 flag) {
    extern u8 lbl_8028D4F8[];
    extern u16 gBattleState[700];
    extern u8 lbl_8026FC78[];
    extern s32 gUiInputFlags;
    void *Process_Find(void *);
    void Process_Unlink(void *);
    void fn_800BDBC8(void *, void *);
    void fn_80089650(s32, s32);
    void fn_8008A290(s32, s32);

    void *obj;

    obj = Process_Find(lbl_8028D4F8);
    if (obj != 0) {
        if (flag != 0) {
            fn_800BDBC8((u8 *)gBattleState + 0xB4, lbl_8026FC78 + 0x11C);
            gUiInputFlags &= ~1;
            fn_80089650(0, 0);
            fn_8008A290(0, 0);
        }
        Process_Unlink(obj);
    }
}

void fn_800C08AC(void *arg0, void *arg1)
{
    extern u8 lbl_8028D4F8[];
    extern u8 lbl_8026FC78[];
    extern s32 gUiInputFlags;

    extern void *Res_GetByName(void *);
    extern void *Process_CreateChild(void *, void *);
    extern void fn_800BDBC8(void *, void *);

    void *result;
    u8 *entry;

    result = Res_GetByName(arg0);

    if (result != 0) {
        entry = (u8 *)Process_CreateChild(lbl_8028D4F8, arg1);

        *(void **)(entry + 0x30) = result;

        fn_800BDBC8(
            (u8 *)gBattleState + 0xB4,
            lbl_8026FC78 + 0x11C
        );

        gUiInputFlags &= ~1;
    }
}

void fn_800C0924(void)
{
    extern u16 gBattleState[700];
    extern u8 lbl_8026FC78[];
    extern s32 gUiInputFlags;

    extern void fn_800BDBC8(void *, void *);
    extern void fn_80089650(s32, s32);
    extern void fn_8008A290(s32, s32);

    fn_800BDBC8(
        (u8 *)gBattleState + 0xB4,
        lbl_8026FC78 + 0x11C
    );

    gUiInputFlags &= ~1;

    fn_80089650(0, 0);
    fn_8008A290(0, 0);
}

void fn_800C0980(void) {
    M2C_UNK fn_80018AE4();
    fn_80018AE4();
}

void fn_800C09A0(void) {
    M2C_UNK fn_80089634(void);
    M2C_UNK fn_80089650(M2C_UNK, M2C_UNK);
    M2C_UNK fn_8008A290(M2C_UNK, M2C_UNK);
    if ((u16)fn_80089634() == 6) {
        fn_80089650(2, 0x85);
        fn_8008A290(0, 0);
    }
}

void fn_800C09E4(s32 arg0) {
    s32 fn_800142B8();
    fn_80013880();
    if (fn_800142B8() != 6) {
        Process_ClearFunc(arg0);
    }
}

void fn_800C0A24(void *arg0) {
    void fn_80013778(s32, void *);
    void fn_80018AF4(void);
    extern u32 gUiInputFlags;

    fn_80013778(0, *(void **)((u8 *)arg0 + 0x30));
    fn_80018AF4();

    gUiInputFlags &= ~0x4;
}

void fn_800C0A60(void *arg0)
{
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 lbl_8028D4D0[];

    u32 current;
    u32 previous;

    if ((gUiInputFlags & 0x84) != 0) {
        return;
    }

    current = *(u32 *)((u8 *)gPadInput + 4);
    previous = *(u32 *)((u8 *)gPadInput + 8);

    if (((current & (previous ^ current)) & 0x1000) == 0) {
        return;
    }

    if ((u8)fn_80089640() != 0) {
        return;
    }

    Process_CreateChild(lbl_8028D4D0, arg0);
}

s32 fn_800C0ACC(void) {
    extern s32 gUiInputFlags;
    gUiInputFlags &= ~0x4;
    return 1;
}

s32 fn_800C0AE0(void)
{
    extern s32 gUiInputFlags;
    gUiInputFlags |= 0x4;
    return 1;
}

s32 fn_800C0AF4(void) {
    extern u8 lbl_8028D4D0[];
    extern u16 gBattleState[700];
    extern u8 lbl_8026FC78[];
    extern s32 gUiInputFlags;
    u8 fn_800BDD08(void *, void *);
    void *Process_Find(void *);
    void Process_UnlinkByKey(void *);
    void fn_800BDBC8(void *, void *);
    void fn_80089650(s32, s32);
    void fn_8008A290(s32, s32);

    if (!(gUiInputFlags & 1)) {
        if (fn_800BDD08((u8 *)gBattleState + 0xB4, lbl_8026FC78 + 0x11C) == 0
            && Process_Find(lbl_8028D4D0) == 0) {
            return 0;
        }
    }

    Process_UnlinkByKey(lbl_8028D4D0);
    fn_800BDBC8((u8 *)gBattleState + 0xB4, lbl_8026FC78 + 0x11C);
    gUiInputFlags &= ~1;
    fn_80089650(0, 0);
    fn_8008A290(0, 0);
    return 1;
}

extern u8 lbl_8028D4D0[16];
void fn_800C0BAC(s32 arg0) {
    void Process_CreateChild(void *, s32);
    extern u8 lbl_8028D4D0[16];
    Process_CreateChild(lbl_8028D4D0, arg0);
}

void fn_800C0BD8(void)
{
    extern s32 gUiInputFlags;
    extern u8 lbl_8026FC78[];

    fn_800BDC68(
        (u8 *)gBattleState + 0xB4,
        lbl_8026FC78 + 0x11C
    );

    gUiInputFlags |= 1;
}

void fn_800C0C1C(void) {
    u16 fn_80089634();
    M2C_UNK fn_80089650(M2C_UNK, M2C_UNK);
    if (fn_80089634() != 6) {
        fn_80089650(3, 0x85);
    }
}

void fn_800C0C54(void)
{
  extern u16 lbl_8028D5B8[];
  if (Process_Find(lbl_8028D5B8) != (0 & 0xFFFFu))
  {
    Process_UnlinkByKey(lbl_8028D5B8);
    return;
  }
  Process_Create(lbl_8028D5B8, 7);
}

void fn_800C0CA4(void *arg0) {
    fn_800C4588(M2C_FIELD(arg0, s32 *, 0x50));
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
}

/* Copy the EFB into the capture buffer, then draw it as a Z-rotated textured strip. */
void Capture_DrawRotated(void *cap) {
    void fn_8022097C(void);
    void fn_8022124C(s32, s32, s32, s32);
    void fn_802212FC(s32, s32, s32, s32);
    void GXCopyTex(s32, s32);
    void fn_802209FC(void);
    void fn_80222EB4(void);
    void Camera_ApplyOrtho(s32);
    void GXClearVtxDesc(void);
    void GXSetVtxDesc(s32, s32);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void GXSetCullMode(s32);
    void GXSetNumTevStages(s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void PSMTXConcat(void *, void *, void *);
    void GXLoadPosMtxImm(void *, s32);
    void fn_80222C50(void *, s32);
    void GXBegin(s32, s32, s32);
    extern f32 lbl_80369D24;
    extern f32 lbl_80369D28;
    extern f32 lbl_80369D2C;
    extern f32 lbl_80369D30;
    extern f32 lbl_80369D34;
    extern f32 lbl_80369D38;
    extern f32 lbl_80369D3C;
    extern f32 lbl_80369D40;
    u8 mtx_rot[0x30];
    u8 mtx_center[0x30];
    u8 mtx_origin[0x30];
    u8 mtx_scale[0x30];
    u8 mtx[0x30];
    void *self;
    f32 vals[2];
    volatile f32 *wgpipe;

    self = cap;
    fn_8022097C();
    fn_8022124C(0, 0, 0x260, 0x1E0);
    fn_802212FC(0x260, 0x1E0, 4, 0);
    GXCopyTex(*(s32 *)((u8 *)self + 0x50), 1);
    fn_802209FC();
    fn_80222EB4();
    Camera_ApplyOrtho(0);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xD, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xD, 1, 4, 0);
    GXSetNumChans(1);
    fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
    GXSetCullMode(0);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 0xFF);
    GXSetNumTexGens(0, 3);
    PSMTXTrans(mtx_center, lbl_80369D24, lbl_80369D24, lbl_80369D28);
    PSMTXTrans(mtx_origin, lbl_80369D2C, lbl_80369D30, lbl_80369D28);
    PSMTXRotRad(mtx_rot, 0x5A, lbl_80369D34);
    PSMTXScale(mtx_scale, lbl_80369D38, lbl_80369D3C, lbl_80369D40);
    PSMTXConcat(mtx_scale, mtx_center, mtx);
    PSMTXConcat(mtx_rot, mtx, mtx);
    PSMTXConcat(mtx_origin, mtx, mtx);
    GXLoadPosMtxImm(mtx, 0);
    fn_80222C50((u8 *)self + 0x30, 0);
    GXBegin(0x98, 0, 4);
    vals[0] = lbl_80369D28;
    wgpipe = (volatile f32 *)0xCC008000;
    vals[1] = lbl_80369D40;
    *wgpipe = vals[0];
    *wgpipe = vals[0];
    *wgpipe = vals[0];
    *wgpipe = vals[0];
    *wgpipe = vals[0];
    *wgpipe = vals[1];
    *wgpipe = vals[0];
    *wgpipe = vals[0];
    *wgpipe = vals[1];
    *wgpipe = vals[0];
    *wgpipe = vals[0];
    *wgpipe = vals[1];
    *wgpipe = vals[0];
    *wgpipe = vals[0];
    *wgpipe = vals[1];
    *wgpipe = vals[1];
    *wgpipe = vals[1];
    *wgpipe = vals[0];
    *wgpipe = vals[1];
    *wgpipe = vals[1];
}

s32 GXGetTexBufferSize(s32, s32, s32, s32, s32);
void *fn_800C45B8(s32, void *, s32);
void fn_80222644(void *, void *, s32, s32, s32, s32, s32, s32);
void GXInitTexObjLOD(void *, s32, s32, s32, s32, s32, f32, f32, f32);
void fn_800C0EEC(u8 *obj) {
    extern char lbl_8026FDC0[];
    extern f32 lbl_80369D28;
    s32 size;

    size = GXGetTexBufferSize(0x260, 0x1E0, 4, 0, 0);
    *(void **)(obj + 0x50) = fn_800C45B8(-size, lbl_8026FDC0 + 0x53, 0);
    fn_80222644(obj + 0x30, *(void **)(obj + 0x50), 0x260, 0x1E0, 4, 0, 0, 0);
    GXInitTexObjLOD(obj + 0x30, 1, 1, 0, 0, 0, lbl_80369D28, lbl_80369D28, lbl_80369D28);
}

void fn_800C0F94(void) {
    void Process_UnlinkByKey(void *);
    void fn_800C4588(void *);
    extern u8 lbl_8028D588[];
    extern u8 lbl_8028D560[];
    extern void *lbl_80320030[];
    void *zero;
    void **p;
    s32 i;

    Process_UnlinkByKey(lbl_8028D588);
    Process_UnlinkByKey(lbl_8028D560);
    i = 0;
    zero = NULL;
    p = lbl_80320030;
    do {
        fn_800C4588(*p);
        *p = zero;
        i += 1;
        *p = zero;
        p += 1;
    } while (i < 3);
}

s32 fn_800C1010(void)
{
  unsigned int new_var;
  extern u16 lbl_8028D560[20];
  extern u16 lbl_8028D588[24];
  new_var = 0;
  if (Process_Find(lbl_8028D560) != new_var)
  {
    return 1;
  }
  return Process_Find(lbl_8028D588) != 0;
}

void fn_800C1060(s32 arg0) {
    u8 fn_80040824(void);
    extern u16 lbl_8028D560[20];
    extern u16 lbl_8028D588[24];
    
    if (fn_80040824() != 0) {
        Process_CreateEx(lbl_8028D560, arg0);
        Process_CreateEx(lbl_8028D588, arg0);
    }
}

void fn_800C10B4(void) {
    M2C_UNK fn_80016180();
    fn_80016180();
}

void fn_800C11F4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x60) = -1;
    M2C_FIELD(arg0, s16 *, 0x28) = 0x10;
}

s32 fn_800C1360(s32 arg0, s32 arg1, s32 arg2)
{
    s32 var_r30;
    s32 var_r29;
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r7;
    s32 temp_r8;
    
    if (arg0 <= 0)
        return -1;
        
    if (arg2 < 0)
        arg2 = 0;
        
    var_r30 = 0;
    var_r29 = 0;
    
    do {
        temp_r3 = var_r30;
        if ((temp_r3 & 0x1) == 0)
            temp_r4 = arg2;
        else
            temp_r4 = 0;
            
        temp_r5 = (arg1 - arg1 * temp_r4) >> 14;
        temp_r6 = temp_r5 + arg2;
        
        if (arg0 < temp_r6) {
            temp_r7 = var_r30;
            if ((temp_r7 & 0x1) == 0)
                temp_r8 = 0;
            else
                temp_r8 = arg2;
                
            arg2 = temp_r8 + arg2;
            var_r30++;
        } else {
            arg2 = temp_r6;
            var_r30++;
        }
        
    } while (var_r30 < 10);
    
    return arg2;
}

void fn_800C14D0(void *arg0) {
    void fn_800062EC(s32, s32, u32);
    void DCFlushRange(void *, u32);
    void fn_800C1BDC();
    extern s32 lbl_80320030[];
    extern s32 lbl_8036785C;
    s32 temp_r29;
    s32 var_r28;

    var_r28 = 1;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    do {
        temp_r29 = lbl_80320030[(lbl_8036785C + var_r28) % 3];
        fn_800062EC(temp_r29, lbl_80320030[lbl_8036785C], 0x2000);
        DCFlushRange((void *)temp_r29, 0x2000);
        var_r28 += 1;
    } while (var_r28 < 3);
    fn_800C1BDC();
    lbl_8036785C += 1;
    lbl_8036785C %= 3;
}

void fn_800C15A8(void) {
    s32 GMaterial_AllocMtx(void);
    s32 GMaterial_AllocTexCoord(void);
    s32 GMaterial_AllocTexMap(void);
    s32 GMaterial_AllocTevStage(void);
    void PSMTXIdentity(void *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXTrans(void *, f32, f32, f32);
    void C_MTXLightOrtho(void *, f32, f32, f32, f32, f32, f32, f32, f32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80222C50(void *, s32);
    void GXSetTevColorIn(s32, s32, s32, s32, s32);
    void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
    void GXSetTevColorOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevAlphaOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void fn_80224E50(void *, s32, s32);
    extern u8 lbl_8031FFD0[];
    extern s32 lbl_8036785C;
    extern f32 lbl_80369D28;
    extern f32 lbl_80369D44;
    extern f32 lbl_80369D48;
    extern f32 lbl_80369D4C;
    extern f32 lbl_80369D50;
    u8 sp68[0x30];
    u8 sp38[0x30];
    u8 sp8[0x30];
    f32 t5;
    void *p;
    f32 t1;
    f32 t2;
    s32 r31;
    s32 r30;
    s32 r29;
    s32 r28;

    t5 = lbl_80369D4C;
    p = sp38;
    t1 = lbl_80369D44;
    t2 = lbl_80369D48;
    C_MTXLightOrtho(p, t1, t2, t2, t1, t5, t5, t5, t5);
    PSMTXTrans(sp68, lbl_80369D50, lbl_80369D50, lbl_80369D28);
    PSMTXIdentity(sp8);
    PSMTXConcat(sp68, sp8, sp8);
    PSMTXConcat(sp38, sp8, sp8);
    r31 = GMaterial_AllocTevStage();
    r30 = GMaterial_AllocTexCoord();
    r29 = GMaterial_AllocTexMap();
    fn_80222C50(lbl_8031FFD0 + (lbl_8036785C << 5), r29);
    r28 = GMaterial_AllocMtx();
    fn_80224E50(sp8, r28, 1);
    fn_802201A8(r30, 1, 0, r28, 0, 0x7D);
    GXSetTevOrder(r31, r30, r29, 0xFF);
    GXSetTevColorIn(r31, 0xF, 0, 8, 0xF);
    GXSetTevColorOp(r31, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(r31, 7, 7, 7, 0);
    GXSetTevAlphaOp(r31, 0, 0, 0, 1, 0);
}

#pragma optimization_level 2
/* Set up map blend-mode TEV (ortho UV, texture, blend ops). Returns 0 if blend off. */
s32 Map_SetupBlendTev(void) {
    s32 GMaterial_AllocMtx(void);
    s32 GMaterial_AllocTexCoord(void);
    s32 GMaterial_AllocTexMap(void);
    s32 GMaterial_AllocTevStage(void);
    void fn_8006A384(void *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXTrans(void *, f32, f32, f32);
    void C_MTXLightOrtho(void *, f32, f32, f32, f32, f32, f32, f32, f32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80222C50(void *, s32);
    void GXSetTevColorIn(s32, s32, s32, s32, s32);
    void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
    void GXSetTevColorOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevAlphaOp(s32, s32, s32, s32, s32, s32);
    void fn_80223C78(s32, s32 *);
    void fn_80223CDC(s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void fn_80224E50(void *, s32, s32);
    extern u8 lbl_8031FFD0[];
    extern u8 gMapBlendMode;
    extern s32 lbl_8036785C;
    extern s32 lbl_80369D20;
    extern f32 lbl_80369D28;
    extern f32 lbl_80369D44;
    extern f32 lbl_80369D48;
    extern f32 lbl_80369D4C;
    extern f32 lbl_80369D50;
    u8 mtxTrans[0x30];
    u8 mtxOrtho[0x30];
    u8 mtxOut[0x30];
    s32 tevColor;
    s32 tevStage;
    s32 texCoord;
    s32 texMap;
    s32 mtxId;
    f32 half;
    void *ortho;
    f32 top;
    f32 bottom;

    if ((s32)gMapBlendMode == 0) {
        return 0;
    }
    half = lbl_80369D4C;
    ortho = mtxOrtho;
    top = lbl_80369D44;
    bottom = lbl_80369D48;
    C_MTXLightOrtho(ortho, top, bottom, bottom, top, half, half, half, half);
    PSMTXTrans(mtxTrans, lbl_80369D50, lbl_80369D50, lbl_80369D28);
    fn_8006A384(mtxOut);
    PSMTXConcat(mtxTrans, mtxOut, mtxOut);
    PSMTXConcat(mtxOrtho, mtxOut, mtxOut);
    tevStage = GMaterial_AllocTevStage();
    texCoord = GMaterial_AllocTexCoord();
    texMap = GMaterial_AllocTexMap();
    mtxId = GMaterial_AllocMtx();
    fn_80222C50(lbl_8031FFD0 + (lbl_8036785C << 5), texMap);
    fn_80224E50(mtxOut, mtxId, 1);
    fn_802201A8(texCoord, 1, 0, mtxId, 0, 0x7D);
    GXSetTevOrder(tevStage, texCoord, texMap, 4);
    switch ((s32)gMapBlendMode) {
    case 1:
        GXSetTevColorIn(tevStage, 0xF, 0, 8, 0xF);
        GXSetTevColorOp(tevStage, 0, 0, 0, 1, 0);
        break;
    case 2:
        GXSetTevColorIn(tevStage, 0xD, 0xF, 8, 0);
        GXSetTevColorOp(tevStage, 0, 0, 0, 1, 0);
        break;
    case 3:
        tevColor = lbl_80369D20;
        fn_80223C78(3, &tevColor);
        fn_80223CDC(tevStage, 0xF);
        GXSetTevColorIn(tevStage, 0, 0xE, 8, 0);
        GXSetTevColorOp(tevStage, 0, 0, 3, 1, 0);
        break;
    }
    GXSetTevAlphaIn(tevStage, 7, 7, 7, 0);
    GXSetTevAlphaOp(tevStage, 0, 0, 0, 1, 0);
    return 1;
}
#pragma optimization_level 4
void fn_800C1984(void) {
    s32 Map_Get(void);
    void fn_800462FC(s32, s32, void *);
    void fn_80046360(s32, s32, void *, s32, s32, s32);
    void Map_SetupBlendTev(void);
    extern u8 gMapBlendMode;

    if (gMapBlendMode == 0) {
        fn_800462FC(Map_Get(), 0, Map_SetupBlendTev);
        return;
    }
    fn_80046360(Map_Get(), 0, Map_SetupBlendTev, 0, 0, 0x8000);
}

void fn_800C1E24(void) {
    M2C_UNK DCFlushRange(s32, M2C_UNK);
    M2C_UNK fn_800C1BDC();
    s32 fn_800C4638(M2C_UNK, void *, M2C_UNK);
    M2C_UNK fn_80222644(M2C_UNK *, s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXInitTexObjLOD(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32, f32, f32);
    extern M2C_UNK lbl_8026FDC0;
    extern M2C_UNK lbl_8031FFD0;
    extern s32 lbl_80320030;
    extern s32 lbl_80367850;
    extern s32 lbl_80367854;
    extern s32 lbl_80367858;
    extern s32 lbl_8036785C;
    extern f32 lbl_80369D28;
    M2C_UNK *var_r29;
    s32 *var_r30;
    s32 var_r28;

    var_r30 = &lbl_80320030;
    var_r29 = &lbl_8031FFD0;
    var_r28 = 0;
    lbl_80367850 = 0x4000;
    lbl_80367854 = 0x80;
    lbl_80367858 = 0x80;
    lbl_8036785C = 0;
    do {
        *var_r30 = fn_800C4638(0x2000, &lbl_8026FDC0 + 0x53, 0);
        fn_80222644(var_r29, *var_r30, 0x80, 0x80, 0, 0, 0, 0);
        GXInitTexObjLOD(var_r29, 1, 1, 0, 0, 0, lbl_80369D28, lbl_80369D28, lbl_80369D28);
        DCFlushRange(*var_r30, 0x2000);
        var_r28 += 1;
        var_r29 += 0x20;
        var_r30 += 4;
    } while (var_r28 < 3);
    fn_800C1BDC();
}

s32 fn_800C1F1C(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 temp0 = (arg0 < 0) ? ((arg0 + 0x1F) >> 5) : (arg0 >> 5);
    s32 temp1 = (arg1 < 0) ? ((arg1 + 0x1F) >> 5) : (arg1 >> 5);
    s32 temp2 = (arg2 < 0) ? ((arg2 + 0x1F) >> 5) : (arg2 >> 5);
    s32 temp3 = (arg3 < 0) ? ((arg3 + 0x1F) >> 5) : (arg3 >> 5);
    
    s32 var_r4 = temp1 * 0x32E100;
    s32 var_r3 = temp0 * 0x7D8600;
    var_r3 += var_r4;
    var_r4 = temp2 * 0x19400;
    var_r3 += var_r4;
    var_r4 = temp3 * 0x564;
    var_r3 += var_r4;

    return var_r3 + 0x800000;
}

char *fn_800C2048(s8 arg0, s8 arg1) {
    void *fn_80013B60(void *);
    u8 fn_800BDD08(void *, char *);
    s32 Str_Cmp(char *, char *);
    u8 cont;
    u8 *p;
    s32 value;
    void *node;
    char *base;

    for (node = fn_80013B60(NULL); node != NULL; node = fn_80013B60(node)) {
        if ((s32) M2C_FIELD(node, u8 *, 0xC) == 5 && arg0 == M2C_FIELD(node, s16 *, 0x14) && arg1 == M2C_FIELD(node, s16 *, 0x16)) {
            if (fn_800BDD08((u8 *) gBattleState + 0xB4, M2C_FIELD(M2C_FIELD(node, void **, 8), char **, 0x24) + (u16) M2C_FIELD(node, s16 *, 0x1A)) == 0) {
                p = M2C_FIELD(node, u8 **, 4);
                value = 0;
                cont = 1;
                while (cont) {
                    switch (*p++) {
                    case 0:
                        cont = 0;
                        break;
                    case 1: case 3: case 5: case 7: case 9: case 11: case 13: case 15: case 17: case 19: case 21: case 23: case 25:
                    case 55: case 65:
                        p += 1;
                        break;
                    case 2: case 4: case 6: case 8: case 10: case 12: case 14: case 16: case 18: case 20: case 22: case 24: case 26:
                    case 58: case 59: case 60: case 61: case 62:
                        p += 2;
                        break;
                    case 27: case 64:
                        p += 4;
                        break;
                    case 28:
                        value = *p++;
                        break;
                    case 29:
                        {
                            s16 hw = (s16) (((p[0] & 0xFF) << 8) + p[1]);
                            p += 2;
                            value = hw;
                        }
                        break;
                    case 30:
                        value = p[0] << 24;
                        value += (p[1] & 0xFF) << 16;
                        value += (p[2] & 0xFF) << 8;
                        value += p[3];
                        p += 4;
                        break;
                    case 56:
                        base = M2C_FIELD(M2C_FIELD(node, void **, 8), char **, 0x24);
                        base += (s16) (((p[0] & 0xFF) << 8) + p[1]);
                        p += 3;
                        if (Str_Cmp("MindGetItem", base) == 0) {
                            return M2C_FIELD(M2C_FIELD(node, void **, 8), char **, 0x24) + value;
                        }
                        break;
                    }
                }
                return NULL;
            }
        }
    }
    return NULL;
}

int fn_800C221C(void* arg0, void* arg1, u32 arg2)
{
    void** r3 = (void**)arg0;
    if (*r3 == NULL) {
        return 0;
    }
    return 1;
}

s32 fn_800C273C(void *arg0, u16 arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0x24) + arg1;
}

extern u8 lbl_8028D768[16];
void fn_800C28A0(s32 arg0) {
    void Process_CreateChild(void *, s32);
    extern u8 lbl_8028D768[16];
    Process_CreateChild(lbl_8028D768, arg0);
}

void fn_800C28CC(void) {
    M2C_UNK fn_80013880();
    fn_80013880();
}

void fn_800C28EC(void) {
    M2C_UNK fn_800138F4();
    M2C_UNK fn_80013A90(void *);
    M2C_UNK ScriptCmd_CmLoadScript(void *);
    M2C_UNK fn_800AA1CC();
    extern u8 lbl_80270000[];
    fn_800AA1CC();
    ScriptCmd_CmLoadScript(lbl_80270000 + 0x26);
    fn_80013A90(lbl_80270000 + 0x37);
    fn_800138F4();
}

void fn_800C2930(s32 arg0, s32 arg1) {
    M2C_UNK Stream_Read(s32, s32, s32);
    M2C_UNK fn_801A7CDC(void *);
    extern u8 gBattle[];
    fn_801A7CDC(gBattle);
    Stream_Read(arg1, 0x480, arg0);
}

void fn_800C2980(s32 arg0, s32 arg1) {
    M2C_UNK Stream_Write(s32, s32, s32);
    M2C_UNK fn_801A7CDC(void *);
    extern u8 gBattle[];
    fn_801A7CDC(gBattle);
    Stream_Write(arg1, 0x480, arg0);
}

s32 fn_800C29D0(s32 arg0, s32 arg1) {
    return (s32)&((u8 (*)[0x18])arg0)[arg1 - 1][0x14];
}

s32 fn_800C29E8(u8 *arg0, s32 arg1, u8 *arg2) {
    s32 off;
    u8 *p;
    u8 *q;
    u8 b0, b1, b2, b3;
    u8 flag;

    off = arg1 * 0x18;
    b0 = arg2[0];
    b1 = arg2[1];
    flag = 0;
    b2 = arg2[2];
    b3 = arg2[3];
    p = arg0 + off;
    p[-4] = b0;
    p[-3] = b1;
    p[-2] = b2;
    p[-1] = b3;
    if ((s8)p[-0x17] == 0 &&
        (s8)p[-8] == 0 &&
        (s8)p[-7] == 0 &&
        (s8)p[-6] == 0 &&
        (s8)p[-5] == 0 &&
        p[-4] == 0x80 &&
        p[-3] == 0x80 &&
        p[-2] == 0x80 &&
        p[-1] == 0xFF) {
        flag = 1;
    }
    if (flag != 0) {
        q = arg0 + off;
        b0 = 0;
        q[-0x18] = b0;
        b1 = 0x80;
        b2 = 0xFF;
        p[-0x17] = b0;
        q[-5] = b0;
        q[-6] = b0;
        q[-7] = b0;
        q[-8] = b0;
        p[-2] = b1;
        p[-3] = b1;
        p[-4] = b1;
        p[-1] = b2;
        return b0;
    }
    return 0;
}

s8 fn_800C2ACC(Unk800C2ACC *arg0, s32 arg1) {
    return (s8)arg0[arg1 - 1].unk13;
}

s32 fn_800C2AE0(Unk800C2ACC *arr, s32 idx, u8 val) {
    s32 off = idx * 0x18;
    u8 flag = 0;
    Unk800C2ACC *p = &arr[idx];

    ((u8 *)p)[-5] = val;
    if ((s8)((u8 *)p)[-0x17] == 0 && (s8)((u8 *)p)[-8] == 0 && (s8)((u8 *)p)[-7] == 0 &&
        (s8)((u8 *)p)[-6] == 0 && (s8)((u8 *)p)[-5] == 0 && ((u8 *)p)[-4] == 0x80 &&
        ((u8 *)p)[-3] == 0x80 && ((u8 *)p)[-2] == 0x80 && ((u8 *)p)[-1] == 0xFF) {
        flag = 1;
    }
    if (flag) {
        u8 *q = (u8 *)arr + off;
        idx = 0;
        q[-0x18] = idx;
        ((u8 *)p)[-0x17] = idx;
        ((u8 *)p)[-5] = idx;
        q[-6] = idx;
        q[-7] = idx;
        q[-8] = idx;
        q[-2] = 0x80;
        q[-3] = 0x80;
        q[-4] = 0x80;
        q[-1] = 0xFF;
    }
    return idx;
}

s8 fn_800C2BA8(s32 arg0, s32 arg1) {
    u8 *ptr = (u8 *)arg0;
    return ptr[(arg1 * 0x18) - 6];
}

s32 fn_800C2BBC(Unk800C2ACC *arr, s32 idx, u8 val) {
    u8 flag;
    s32 off;
    Unk800C2ACC *p;
    u8 *q;

    off = idx * 0x18;
    flag = 0;
    p = &arr[idx];
    ((u8 *)p)[-6] = val;
    if ((s8)((u8 *)p)[-0x17] != 0)
        goto done;
    if ((s8)((u8 *)p)[-8] != 0)
        goto done;
    if ((s8)((u8 *)p)[-7] != 0)
        goto done;
    if ((s8)((u8 *)p)[-6] != 0)
        goto done;
    if ((s8)((u8 *)p)[-5] != 0)
        goto done;
    if (((u8 *)p)[-4] != 0x80)
        goto done;
    if (((u8 *)p)[-3] != 0x80)
        goto done;
    if (((u8 *)p)[-2] != 0x80)
        goto done;
    if (((u8 *)p)[-1] != 0xFF)
        goto done;
    flag = 1;
done:
    if (flag) {
        q = (u8 *)arr + off;
        idx = 0;
        q[-0x18] = (u8)idx;
        ((u8 *)p)[-0x17] = (u8)idx;
        q[-5] = (u8)idx;
        ((u8 *)p)[-6] = (u8)idx;
        q[-7] = (u8)idx;
        q[-8] = (u8)idx;
        q[-2] = 0x80;
        q[-3] = 0x80;
        q[-4] = 0x80;
        q[-1] = 0xFF;
    }
    return idx;
}

s8 fn_800C2C84(s32 arg0, s32 arg1) {
    u8 *ptr = (u8 *)arg0;
    return ptr[(arg1 * 0x18) - 7];
}

#pragma optimization_level 2
s32 fn_800C2C98(Unk800C2ACC *arr, s32 idx, u8 val) {
    u8 flag;
    s32 off;
    Unk800C2ACC *p;
    {
        u8 *pin;
        pin = (u8 *)arr;
        (void)pin;
    }
    off = idx * 0x18;
    flag = 0;
    p = &arr[idx];
    ((u8 *)p)[-7] = val;
    if ((s8)((u8 *)p)[-0x17] == 0 && (s8)((u8 *)p)[-8] == 0 && (s8)((u8 *)p)[-7] == 0 &&
        (s8)((u8 *)p)[-6] == 0 && (s8)((u8 *)p)[-5] == 0 && ((u8 *)p)[-4] == 0x80 &&
        ((u8 *)p)[-3] == 0x80 && ((u8 *)p)[-2] == 0x80 && ((u8 *)p)[-1] == 0xFF) {
        flag = 1;
    }
    if (flag) {
        u8 *q = (u8 *)arr + off;
        idx = 0;
        q[-0x18] = (u8)idx;
        ((u8 *)p)[-0x17] = (u8)idx;
        q[-5] = (u8)idx;
        q[-6] = (u8)idx;
        ((u8 *)p)[-7] = (u8)idx;
        q[-8] = (u8)idx;
        q[-2] = 0x80;
        q[-3] = 0x80;
        q[-4] = 0x80;
        q[-1] = 0xFF;
    }
    return idx;
}
#pragma optimization_level reset
s8 fn_800C2D60(s32 arg0, s32 arg1) {
    u8 *ptr = (u8 *)arg0;
    return ptr[(arg1 * 0x18) - 8];
}

s32 fn_800C2D74(Unk800C2ACC *arr, s32 idx, u8 val) {
    s32 off = idx * 0x18;
    u8 flag = 0;
    Unk800C2ACC *p = &arr[idx];

    ((u8 *)p)[-8] = val;
    if ((s8)((u8 *)p)[-0x17] == 0 && (s8)((u8 *)p)[-8] == 0 && (s8)((u8 *)p)[-7] == 0 &&
        (s8)((u8 *)p)[-6] == 0 && (s8)((u8 *)p)[-5] == 0 && ((u8 *)p)[-4] == 0x80 &&
        ((u8 *)p)[-3] == 0x80 && ((u8 *)p)[-2] == 0x80 && ((u8 *)p)[-1] == 0xFF) {
        flag = 1;
    }
    if (flag) {
        u8 *q = (u8 *)arr + off;
        idx = 0;
        q[-0x18] = (u8)idx;
        ((u8 *)p)[-0x17] = (u8)idx;
        q[-5] = (u8)idx;
        q[-6] = (u8)idx;
        q[-7] = (u8)idx;
        ((u8 *)p)[-8] = (u8)idx;
        q[-2] = 0x80;
        q[-3] = 0x80;
        q[-4] = 0x80;
        q[-1] = 0xFF;
    }
    return idx;
}

char *fn_800C2E3C(void *arg0, s32 index) {
    extern f32 lbl_80369D58;
    extern f32 lbl_80369D5C;
    extern f32 lbl_80369D60;
    extern char lbl_80270088[];
    extern char lbl_80320B6C[];
    s32 fn_80010B78(void *, s32, f32);
    s32 fn_80231D94(char *, const char *, ...);
    f32 scale;
    s32 offset;
    char *text;
    s16 width;

    scale = lbl_80369D58;
    offset = (index - 1) * 0x18;
    offset = offset + 1;
    text = (char *)offset;
    text += (u32)arg0;
    width = (s16)fn_80010B78(text, -1, scale);

    if (width < 0x70) {
        return text;
    }

    fn_80231D94(lbl_80320B6C, lbl_80270088 + 8,
                (u8)(s32)(lbl_80369D5C * (lbl_80369D60 / (f32)width)),
                text);
    return lbl_80320B6C;
}

s32 Icon_GetSlot(s32 arg0, s32 arg1) {
    return arg0 + ((arg1 - 1) * 0x18);
}

s32 Icon_CopySlot(s32 arg0, s32 arg1, void *arg2) {
    s32 temp_r31;
    u8 temp_r6;
    void *temp_r30;
    void *temp_r5;
    
    temp_r6 = *(u8*)arg2;
    temp_r31 = arg1 * 0x18;
    temp_r30 = (u8*)arg0 + temp_r31;
    *(u8*)((u8*)temp_r30 - 0x18) = temp_r6;
    
    fn_8022C1B8(((u8*)arg0 + (((arg1 - 1) * 0x18) + 1)), 
                (u8*)arg2 + 1, 
                0xF, 
                temp_r6);
    
    *(u8*)((u8*)temp_r30 - 0x8) = *(u8*)((u8*)arg2 + 0x10);
    *(u8*)((u8*)temp_r30 - 0x7) = *(u8*)((u8*)arg2 + 0x11);
    *(u8*)((u8*)temp_r30 - 0x6) = *(u8*)((u8*)arg2 + 0x12);
    *(u8*)((u8*)temp_r30 - 0x5) = *(u8*)((u8*)arg2 + 0x13);
    *(u32*)((u8*)temp_r30 - 0x4) = *(u32*)((u8*)arg2 + 0x14);
    
    if (((s8)*(u8*)((u8*)temp_r30 - 0x17) == 0) && 
        ((s8)*(u8*)((u8*)temp_r30 - 0x8) == 0) && 
        ((s8)*(u8*)((u8*)temp_r30 - 0x7) == 0) && 
        ((s8)*(u8*)((u8*)temp_r30 - 0x6) == 0) && 
        ((s8)*(u8*)((u8*)temp_r30 - 0x5) == 0) && 
        (*(u8*)((u8*)temp_r30 - 0x4) == 0x80) && 
        (*(u8*)((u8*)temp_r30 - 0x3) == 0x80) && 
        (*(u8*)((u8*)temp_r30 - 0x2) == 0x80) && 
        (*(u8*)((u8*)temp_r30 - 0x1) == 0xFF)) {
        
        temp_r5 = (u8*)arg0 + temp_r31;
        *(u8*)((u8*)temp_r30 - 0x18) = 0;
        *(u8*)((u8*)temp_r30 - 0x17) = 0;
        *(u8*)((u8*)temp_r30 - 0x5) = 0;
        *(u8*)((u8*)temp_r30 - 0x6) = 0;
        *(u8*)((u8*)temp_r30 - 0x7) = 0;
        *(u8*)((u8*)temp_r30 - 0x8) = 0;
        *(u8*)((u8*)temp_r5 - 0x2) = 0x80;
        *(u8*)((u8*)temp_r5 - 0x3) = 0x80;
        *(u8*)((u8*)temp_r30 - 0x4) = 0x80;
        *(u8*)((u8*)temp_r5 - 0x1) = 0xFF;
        
        return 1;
    }
    
    return arg1;
}

void Icon_FreeSlot(s32 arg0, s32 arg1) {
    u8 *temp_r3;

    temp_r3 = (u8 *)(arg0 + (arg1 * 0x18));
    *(temp_r3 - 0x18) = 0;
    *(temp_r3 - 0x17) = 0;
    *(temp_r3 - 0x5) = 0;
    *(temp_r3 - 0x6) = 0;
    *(temp_r3 - 0x7) = 0;
    *(temp_r3 - 0x8) = 0;
    *(temp_r3 - 0x2) = 0x80;
    *(temp_r3 - 0x3) = 0x80;
    *(temp_r3 - 0x4) = 0x80;
    *(temp_r3 - 0x1) = 0xFF;
}

s32 Icon_AllocSlot(u8* arg0) {
    s32 i;
    u8* p;

    p = arg0;
    for (i = 0; i < 0x30; i++) {
        if (*arg0 == 0) {
            p[i * 0x18] = 1;
            return i + 1;
        }
        arg0 = arg0 + 0x18;
    }
    return 0;
}

void fn_800C32A4(u8 *p) {
    s32 n;
    u8 z;
    u8 m;
    u8 f;

    n = 0xC;
    z = 0;
    m = 0x80;
    f = 0xFF;
    do {
        p[0] = z;
        p[1] = z;
        p[0x13] = z;
        p[0x12] = z;
        p[0x11] = z;
        p[0x10] = z;
        p[0x16] = m;
        p[0x15] = m;
        p[0x14] = m;
        p[0x17] = f;
        p[0x18] = z;
        p[0x19] = z;
        p[0x2B] = z;
        p[0x2A] = z;
        p[0x29] = z;
        p[0x28] = z;
        p[0x2E] = m;
        p[0x2D] = m;
        p[0x2C] = m;
        p[0x2F] = f;
        p[0x30] = z;
        p[0x31] = z;
        p[0x43] = z;
        p[0x42] = z;
        p[0x41] = z;
        p[0x40] = z;
        p[0x46] = m;
        p[0x45] = m;
        p[0x44] = m;
        p[0x47] = f;
        p[0x48] = z;
        p[0x49] = z;
        p[0x5B] = z;
        p[0x5A] = z;
        p[0x59] = z;
        p[0x58] = z;
        p[0x5E] = m;
        p[0x5D] = m;
        p[0x5C] = m;
        p[0x5F] = f;
        p += 0x60;
    } while (--n != 0);
}

void fn_800C3364(s32 arg0, s32 arg1) {
    s32 r31 = arg0;
    s32 r30 = 0;
    
    do {
        Item_Read(r31, arg1);
        r30 += 1;
        r31 += 8;
    } while (r30 < 0xC8);
}

void fn_800C33C0(s32 arg0, s32 arg1) {
    s32 r31 = arg0;
    s32 r30 = 0;
    
    do {
        fn_8001C21C(r31, arg1);
        r30 += 1;
        r31 += 8;
    } while (r30 < 0xC8);
}

void fn_800C341C(s32 arg0) {
    s32 r31 = arg0;
    s32 r30 = 0;
    
    do {
        Item_Clear(r31);
        r30 += 1;
        r31 += 8;
    } while (r30 < 0xC8);
}

void fn_800C3468(void *arg0) {
    s32 i;
    void **ptr = (void**)arg0;
    
    for (i = 0; i < 0xC8; i++) {
        ptr++;
    }
}

void fn_800C3864(s32 arg0, s32 arg1) {
    M2C_UNK Item_Clear(s32);
    Item_Clear(arg0 + (arg1 * 8));
}

extern struct Unit;
s32 Convoy_FindByIid(s32 *arg0, s32 arg1) {
    s32 temp_r3;
    s32 i;
    s32 j;
    
    temp_r3 = Item_GetByIid(arg1);
    
    for (i = 0; i < 0x14; i++) {
      if (arg0[i * 0x14 + 0] == temp_r3) return i;
      if (arg0[i * 0x14 + 2] == temp_r3) return i + 1;
      if (arg0[i * 0x14 + 4] == temp_r3) return i + 2;
      if (arg0[i * 0x14 + 6] == temp_r3) return i + 3;
      if (arg0[i * 0x14 + 8] == temp_r3) return i + 4;
      if (arg0[i * 0x14 + 10] == temp_r3) return i + 5;
      if (arg0[i * 0x14 + 12] == temp_r3) return i + 6;
      if (arg0[i * 0x14 + 14] == temp_r3) return i + 7;
      if (arg0[i * 0x14 + 16] == temp_r3) return i + 8;
      if (arg0[i * 0x14 + 18] == temp_r3) return i + 9;
    }
    
    return -1;
}

s32 fn_800C39A4(s32 arg0, s32 arg1, s32 arg2)
{
    if (arg0 < 0) {
        return -1;
    }
    
    if (arg0 >= arg1) {
        return -1;
    }
    
    if ((arg2 & 0xF) != 0) {
        return -1;
    }
    
    // Simple lookup based on what we can tell from the structure
    return ((u16*)0x80317338)[arg0];
}

/* Return index of first empty convoy item slot, or -1 if full. */
s32 Convoy_FindEmpty(void *convoy) {
    s32 i;

    for (i = 0; i < 200; i++) {
        if (*(void **)((char *)convoy + i * 8) == NULL) {
            return i;
        }
    }

    return -1;
}

s32 fn_800C3E54(u32 *arg0) {
    s32 count = 0;
    s32 i;
    s32 j = 0;

    for (i = 0; i < 0x14; i++) {
        if (arg0[0] != 0) {
            count++;
        }
        if (arg0[2] != 0) {
            count++;
        }
        if (arg0[4] != 0) {
            count++;
        }
        if (arg0[6] != 0) {
            count++;
        }
        if (arg0[8] != 0) {
            count++;
        }
        if (arg0[10] != 0) {
            count++;
        }
        if (arg0[12] != 0) {
            count++;
        }
        if (arg0[14] != 0) {
            count++;
        }
        if (arg0[16] != 0) {
            count++;
        }
        if (arg0[18] != 0) {
            count++;
        }
        arg0 += 0x14;
        j += 9;
    }
    return j ? count : count;
}

#include "common.h"
extern u8 gFxChannels[];
extern void Fx_FadeOut(u32*, s16);
extern void fn_80146B00(void);
#include "global.h"
extern u16 gSoundSys[];

extern u16 gSoundSys[4976];

u16 fn_800AF704(s32 arg0) {
    return *(u16 *)(*(u8 **)((u8 *)gSoundSys + 0xF8) + arg0 * 0x13C);
}

void fn_800AF71C(s32 arg0, u16 arg1) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void fn_8024D3C4(void *, u16);
    u8 *sys;
    u8 *entry;
    u16 nest;

    sys = (u8 *)gSoundSys;
    entry = *(u8 **)(sys + 0xF8) + arg0 * 0x13C;
    if (*(u16 *)entry != 0) {
        *(u16 *)(entry + 0x1C) = arg1;
        if (*(u16 *)entry & 8) {
            if (*(u16 *)(sys + 0x124) == 0) {
                *(s32 *)((u8 *)gSoundSys + 0x128) = OSDisableInterrupts();
            }
            *(u16 *)(sys + 0x124) = *(u16 *)(sys + 0x124) + 1;
            fn_8024D3C4(*(void **)(entry + 0x50), *(u16 *)(entry + 0x1C));
            if (*(u16 *)(entry + 0x1E) == 2) {
                fn_8024D3C4(*(void **)(entry + 0xD8), *(u16 *)(entry + 0x1C));
            }
            nest = *(u16 *)(sys + 0x124);
            if (nest != 0) {
                nest -= 1;
                *(u16 *)(sys + 0x124) = nest;
                if ((u16)nest == 0) {
                    OSRestoreInterrupts(*(s32 *)((u8 *)gSoundSys + 0x128));
                }
            }
        }
    }
}

extern f64 lbl_80369CC0;
extern f32 lbl_80369CC8;
extern f32 lbl_80369CCC;
extern f32 lbl_80369CB0;
extern f32 lbl_80369CD0;
void fn_800AFC54(s32 arg0)
{
  u8 *sys;
  u16 rate;
  u16 *new_var;
  f32 var_f2;
  f32 *new_var2;
  f32 minimum;
  u8 *entry;
  sys = (u8 *) gSoundSys;
  entry = (*((u8 **) (sys + 0xF8))) + (arg0 * 0x13C);
  rate = *((u16 *) (sys + 0x120));
  if (((struct 
  {
    u16 flags;
  } *) entry)->flags != 0)
  {
    var_f2 = (f32) ((s32) rate);
    new_var2 = (f32 *) (entry + 0x18);
    var_f2 /= lbl_80369CC8;
    ;
    new_var = (u16 *) entry;
    if (lbl_80369CCC > var_f2)
    {
      var_f2 = minimum;
    }
    *new_var = (*new_var) & (~2);
    *new_var2 = ((*((f32 *) (entry + 0xC))) - (*((f32 *) (entry + 0x10)))) / var_f2;
    *((u16 *) entry) = (*new_var) | 0x10;
    *new_var = (*new_var) & (~0x20);
    *((u16 *) entry) = (*new_var) & (~0x40);
  }
}

void fn_800AFCFC(s32 arg0) {
    u16 *temp_r5;
    f32 var_f3;
    s32 var_r3;
    f32 temp_f4;
    
    temp_r5 = &gSoundSys[arg0 * 0x13C / 2];
    if ((u16) temp_r5[0] != 0) {
        var_f3 = (f32) temp_r5[0x122/2] / lbl_80369CC8;
        if (var_f3 < lbl_80369CCC) {
            var_f3 = lbl_80369CCC;
        }
        temp_f4 = temp_r5[0x10/2];
        var_r3 = (s32) ((temp_r5[0xC/2] * lbl_80369CB0) / lbl_80369CD0);
        if ((f32) var_r3 > temp_f4) {
            var_r3 = (s32) temp_f4;
        }
        temp_r5[0x14/2] = (f32) var_r3;
        temp_r5[0x18/2] = (f32) ((temp_r5[0x10/2] - temp_r5[0x14/2]) / var_f3);
        temp_r5[0] = (u16) (temp_r5[0] | 0x40);
        temp_r5[0] = (u16) (temp_r5[0] & 0xFFFFFFEF);
        temp_r5[0] = (u16) (temp_r5[0] & 0xFFFFFFDF);
    }
}

void fn_800AFE0C(s32 arg0) {
    u16* temp_r31;
    
    temp_r31 = &gSoundSys[arg0 * 0x13C];
    if (temp_r31[0] != 0) {
        if (!(temp_r31[0] & 8)) {
            temp_r31[0] = temp_r31[0] | 4;
            return;
        }
        if (temp_r31[0] & 0x400) {
            gSoundSys[(temp_r31[1] * 2) + 0x13E] = 0;
        }
        temp_r31[0] = 0;
        if (gSoundSys[0x124/2] == 0) {
            gSoundSys[0x128/2] = OSDisableInterrupts();
        }
        gSoundSys[0x124/2] = gSoundSys[0x124/2] + 1;
        fn_800B49D0((void *)(u32)temp_r31[0x2C/2]);
        fn_800B49D0((void *)(u32)temp_r31[0xB4/2]);
        fn_8024DA2C((void *)(u32)temp_r31[0x50/2]);
        if (temp_r31[0x1E/2] == 2) {
            fn_8024DA2C((void *)(u32)temp_r31[0xD8/2]);
        }
        if (gSoundSys[0x124/2] != 0) {
            u16 temp_r3_2 = gSoundSys[0x124/2] - 1;
            gSoundSys[0x124/2] = temp_r3_2;
            if (temp_r3_2 == 0) {
                OSRestoreInterrupts(gSoundSys[0x128/2]);
            }
        }
        gSoundSys[0xFC/2] = -1;
    }
}

#pragma use_lmw_stmw on
void fn_800AFF28(s32 arg0, u32 arg1) {
    void fn_800062EC(void *, void *, s32);
    void fn_800B1720(void *);
    void fn_800B16EC(void *);
    void fn_800B125C(void *);
    void fn_800B49E0(void *, s32, s32, s32, void *);
    void DCInvalidateRange(void *, u32);
    void ARQPostRequest(void *, void *, s32, s32, u32, void *, u32, void *);
    u32 fn_8024CE1C(s32, s32);
    void *fn_8024C97C(s32, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, void *, s32, void *);
    void fn_8024CE60(void *, s32, u8, u8, s32);
    u32 fn_800B49C8(void *);
    void fn_800B0AEC(void);
    extern f32 lbl_80369CB4;
    s32 idx;
    u8 *sys;
    u8 *e;
    u8 *src;
    u8 kind;
    u8 *stream;
    u32 size, aligned;
    u32 offset, limit;
    u32 base;
    u32 clear;
    u8 *p;
    u8 *p2;
    s32 r8;
    u8 *peer;
    u8 vol;
    f32 f, f31;
    u32 sz2;
    u32 ctr, rem;

    if (arg0 < 0) return;
    idx = 0;
    sys = (u8 *)gSoundSys;
    e = *(u8 **)(sys + 0xF8);
    if (*(u16 *)e == 0 || *(u32 *)(e + 0x2C) + 0x40 != arg1) {
        e += 0x13C;
        idx = 1;
        if (*(u16 *)e == 0 || *(u32 *)(e + 0x2C) + 0x40 != arg1) {
            e += 0x13C;
            idx = 2;
            if (*(u16 *)e == 0 || *(u32 *)(e + 0x2C) + 0x40 != arg1) {
                idx = 3;
            }
        }
    }
    src = *(u8 **)(e + 0x54);
    kind = src[0];
    *(u16 *)(e + 0x1C) = *(u16 *)(src + 2);
    *(u16 *)(e + 0x1E) = (u16)*(u32 *)(src + 4);
    *(u32 *)(e + 0x20) = *(u32 *)(src + 8);
    *(u32 *)(e + 0x24) = *(u32 *)(src + 0xC);
    *(u32 *)(e + 0x8C) = *(u32 *)(src + 0x10);
    *(u32 *)(e + 0x114) = *(u32 *)(src + 0x14);
    *(u32 *)(e + 0x90) = *(u32 *)(src + 0x18);
    *(u32 *)(e + 0x118) = *(u32 *)(src + 0x1C);
    if (*(u32 *)(e + 0x24) + 0x10000 != 0xFFFFFFFF) {
        *(u16 *)e = (u16)(*(u16 *)e | 0x200);
    } else {
        *(u32 *)(e + 0x24) = 0;
    }
    switch (kind) {
    case 0:
        *(u32 *)(e + 0x8C) = *(u32 *)(e + 0x20);
        *(u32 *)(e + 0x114) = *(u32 *)(e + 0x20);
        *(u32 *)(e + 0x90) = *(u32 *)(e + 0x24);
        *(u32 *)(e + 0x118) = *(u32 *)(e + 0x24);
        *(u16 *)(e + 4) = 0x40;
        break;
    case 2:
        *(u16 *)e = (u16)(*(u16 *)e | 0x100);
        fn_800062EC(e + 0x94, src + 0x5C, 0x20);
        if (*(u16 *)(e + 0x1E) == 2) {
            fn_800062EC(e + 0x11C, src + 0xBC, 0x20);
        }
        *(u16 *)(e + 4) = 0x100;
        break;
    }
    *(u16 *)(e + 0x78) = 0;
    *(u32 *)(e + 0x70) = 0;
    *(u32 *)(e + 0x60) = 0;
    *(u32 *)(e + 0x64) = 0;
    *(u16 *)(e + 0x80) = 0;
    *(u16 *)(e + 0x82) = 0;
    *(u16 *)(e + 0x84) = 0;
    *(u16 *)(e + 0x86) = 0;
    *(u16 *)(e + 0x88) = 0;
    *(u16 *)(e + 0x100) = 0;
    *(u32 *)(e + 0xF8) = 0;
    *(u32 *)(e + 0xE8) = 0;
    *(u32 *)(e + 0xEC) = 0;
    *(u16 *)(e + 0x108) = 0;
    *(u16 *)(e + 0x10A) = 0;
    *(u16 *)(e + 0x10C) = 0;
    *(u16 *)(e + 0x10E) = 0;
    *(u16 *)(e + 0x110) = 0;
    if (!(*(u16 *)e & 0x400)) {
        *(u16 *)(e + 0x78) = 1;
        stream = e + 0x2C;
        offset = *(u32 *)(e + 0x60);
        limit = *(u32 *)(e + 0x8C);
        size = SoundReadSizeB(offset, limit);
        aligned = (size + 0x1F) & ~0x1F;
        if (!(*(u16 *)e & 0x400)) {
            fn_800B49E0(*(void **)stream, *(s32 *)(stream + (1 - *(u16 *)(stream + 0x4C)) * 4 + 0x2C), aligned, *(u16 *)(e + 4) + offset, fn_800B1720);
        } else {
            base = *(u32 *)((u8 *)gSoundSys + *(u16 *)(e + 2) * 4 + 0x134) + offset + *(u16 *)(e + 4);
            DCInvalidateRange(*(void **)(stream + (1 - *(u16 *)(stream + 0x4C)) * 4 + 0x2C), 0x8000);
            ARQPostRequest(stream + 4, stream, 1, 0, base, *(void **)(stream + (1 - *(u16 *)(stream + 0x4C)) * 4 + 0x2C), aligned, fn_800B16EC);
        }
        *(u32 *)(stream + 0x48) = size;
        *(u16 *)e = (u16)(*(u16 *)e | 0x1000);
        if (*(u16 *)(e + 0x1E) == 2) {
            *(u16 *)(e + 0x100) = 1;
            stream = e + 0xB4;
            offset = *(u32 *)(e + 0xE8);
            limit = *(u32 *)(e + 0x114);
            base = limit + (32 - (limit & 31));
            size = SoundReadSizeB(offset, limit);
            aligned = (size + 0x1F) & ~0x1F;
            if (!(*(u16 *)e & 0x400)) {
                fn_800B49E0(*(void **)stream, *(s32 *)(stream + (1 - *(u16 *)(stream + 0x4C)) * 4 + 0x2C), aligned, *(u16 *)(e + 4) + (offset + base), fn_800B1720);
            } else {
                base = offset + base + *(u32 *)((u8 *)gSoundSys + *(u16 *)(e + 2) * 4 + 0x134) + *(u16 *)(e + 4);
                DCInvalidateRange(*(void **)(stream + (1 - *(u16 *)(stream + 0x4C)) * 4 + 0x2C), 0x8000);
                ARQPostRequest(stream + 4, stream, 1, 0, base, *(void **)(stream + (1 - *(u16 *)(stream + 0x4C)) * 4 + 0x2C), aligned, fn_800B16EC);
            }
            *(u32 *)(stream + 0x48) = size;
            *(u16 *)e = (u16)(*(u16 *)e | 0x2000);
        }
    }
    clear = fn_8024CE1C(0xE00, 0);
    p = *(u8 **)(e + 0x54);
    if (clear != 0) {
        ctr = clear >> 3;
        if (ctr != 0) {
            do {
                p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0;
                p[4] = 0; p[5] = 0; p[6] = 0; p[7] = 0;
                p += 8;
            } while (--ctr);
            rem = clear & 7;
            if (rem != 0) {
                do { *p = 0; p += 1; } while (--rem);
            }
        } else {
            rem = clear;
            do { *p = 0; p += 1; } while (--rem);
        }
    }
    if (*(u16 *)(e + 0x1E) == 2) {
        p2 = *(u8 **)(e + 0xDC);
        if (clear != 0) {
            ctr = clear >> 3;
            if (ctr != 0) {
                do {
                    p2[0] = 0; p2[1] = 0; p2[2] = 0; p2[3] = 0;
                    p2[4] = 0; p2[5] = 0; p2[6] = 0; p2[7] = 0;
                    p2 += 8;
                } while (--ctr);
                rem = clear & 7;
                if (rem != 0) {
                    do { *p2 = 0; p2 += 1; } while (--rem);
                }
            } else {
                rem = clear;
                do { *p2 = 0; p2 += 1; } while (--rem);
            }
        }
    }
    r8 = 0;
    if (*(u16 *)(e + 0x1E) == 1) r8 = 0x40;
    if (!(*(u16 *)e & 0x100)) {
        *(void **)(e + 0x50) = fn_8024C97C(0xFF, *(void **)(e + 0x54), 0xE00, *(u16 *)(e + 0x1C), 0, r8, 0, 0, 0, 0, 0x10000, (void *)fn_800B0AEC, idx, 0);
        if (*(u16 *)(e + 0x1E) == 2) {
            *(void **)(e + 0xD8) = fn_8024C97C(0xFF, *(void **)(e + 0xDC), 0xE00, *(u16 *)(e + 0x1C), 0, 0x7F, 0, 0, 0, 0, 0x10000, (void *)fn_800B0AEC, idx | 0x100, 0);
        }
        *(u16 *)e = (u16)(*(u16 *)e | 8);
    } else {
        *(void **)(e + 0x50) = fn_8024C97C(0xFF, *(void **)(e + 0x54), 0xE00, *(u16 *)(e + 0x1C), 0, r8, 0, 0, 0, 0, 0x10001, (void *)fn_800B0AEC, idx, e + 0x94);
        if (*(u16 *)(e + 0x1E) == 2) {
            *(void **)(e + 0xD8) = fn_8024C97C(0xFF, *(void **)(e + 0xDC), 0xE00, *(u16 *)(e + 0x1C), 0, 0x7F, 0, 0, 0, 0, 0x10001, (void *)fn_800B0AEC, idx | 0x100, e + 0x11C);
        }
    }
    vol = (u8)*(u16 *)(e + 6);
    peer = *(u8 **)(sys + 0xF8) + idx * 0x13C;
    if (*(u16 *)peer != 0) {
        *(u16 *)(peer + 6) = vol;
        if (*(u16 *)peer & 8) {
            if (*(u16 *)(peer + 0x1E) == 1) {
                fn_8024CE60(*(void **)(peer + 0x50), (s32)*(f32 *)(peer + 0x10), vol, (u8)*(u16 *)(peer + 8), 0);
            } else {
                f = *(f32 *)(peer + 0x10);
                f31 = f;
                if (vol < 0x40) {
                    f31 = ((f32)vol * f) / lbl_80369CB4;
                }
                if ((u32)(vol - 0x40) >> 31 == 0) {
                    f = ((f32)(s32)(0x7F - vol) * f) / lbl_80369CB4;
                }
                fn_8024CE60(*(void **)(peer + 0x50), (s32)f, 0, (u8)*(u16 *)(peer + 8), 0);
                fn_8024CE60(*(void **)(peer + 0xD8), (s32)f31, 0x7F, (u8)*(u16 *)(peer + 8), 0);
            }
        }
    }
    *(f32 *)(e + 0x18) = *(f32 *)(e + 0xC);
    *(u16 *)e = (u16)(*(u16 *)e | 0x10);
    if (*(u16 *)e & 0x400) {
        sz2 = fn_800B49C8(*(void **)(e + 0x2C));
        offset = *(u32 *)(e + 0x60);
        size = 0x8000;
        if (offset + 0x8000 >= sz2) size = sz2 - offset;
        fn_800B49E0(*(void **)(e + 0x2C), *(s32 *)(e + 0x58), (size + 0x1F) & ~0x1F, 0, fn_800B125C);
        *(u32 *)(e + 0x74) = size;
    }
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
void fn_800B080C(s32 arg0, s32 arg1, s32 arg2) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void fn_800B49D0(void *);
    void fn_800B49E0(void *, s32, s32, s32, void *);
    void *fn_800B4A84(void *, s32, s32);
    void sprintf(void *, void *, ...);
    void fn_8024DA2C(void *);
    extern f32 lbl_80369CB0;
    extern f32 lbl_80369CD4;
    extern u8 gSoundPathBuf[];
    extern u8 Sound_str[];
    void fn_800AFF28(s32, u32);

    u8 *buf;
    u16 flags;
    u32 nest;
    s32 i;
    u8 *p;
    s32 ctr;
    void *h;
    u16 *slot;
    f32 f0;
    f32 f1;
    u8 *entry;

    buf = (u8 *)gSoundSys;
    entry = *(u8 **)(buf + 0xF8) + arg0 * 0x13C;
    flags = *(u16 *)entry;
    if (flags != 0) {
        if (flags != 0) {
            if (!(flags & 8)) {
                *(u16 *)entry = (u16)(flags | 4);
            } else {
                if (flags & 0x400) {
                    slot = (u16 *)(buf + 0x13E);
                    slot[*(u16 *)(entry + 2)] = 0;
                }
                *(u16 *)entry = 0;
                buf = (u8 *)gSoundSys;
                if (*(u16 *)(buf + 0x124) == 0) {
                    *(s32 *)((u8 *)gSoundSys + 0x128) = OSDisableInterrupts();
                }
                *(u16 *)(buf + 0x124) = (u16)(*(u16 *)(buf + 0x124) + 1);
                fn_800B49D0(*(void **)(entry + 0x2C));
                fn_800B49D0(*(void **)(entry + 0xB4));
                fn_8024DA2C(*(void **)(entry + 0x50));
                if (*(u16 *)(entry + 0x1E) == 2) {
                    fn_8024DA2C(*(void **)(entry + 0xD8));
                }
                nest = *(u16 *)(buf + 0x124);
                if (nest != 0) {
                    nest -= 1;
                    *(u16 *)(buf + 0x124) = nest;
                    if ((u16)nest == 0) {
                        OSRestoreInterrupts(*(s32 *)((u8 *)gSoundSys + 0x128));
                    }
                }
                *(s32 *)((u8 *)gSoundSys + 0xFC) = -1;
            }
        }
    }

    if (arg2 != 0) {
        buf = (u8 *)gSoundSys;
        p = buf;
        ctr = *(u16 *)(buf + 0x13C);
        for (i = 0; i < ctr; i++) {
            if (*(u16 *)(p + 0x13E) == 0) {
                slot = (u16 *)((u8 *)gSoundSys + 0x13E);
                slot[i] = 1;
                *(u16 *)(entry + 2) = (u16)i;
                break;
            }
            p += 2;
        }
        if (i >= *(u16 *)(buf + 0x13C)) {
            return;
        }
    }

    {
        s32 zero;
        s32 forty;
        s32 one;

        buf = (u8 *)gSoundSys;
        zero = 0;
        forty = 0x40;
        one = 1;
        *(s32 *)(buf + 0xFC) = arg0;
        if (arg2 != 0) {
        }
        f1 = 0.0f;
        *(u16 *)(entry + 0x78) = zero;
        f0 = lbl_80369CD4;
        *(s32 *)(entry + 0x70) = zero;
        *(s32 *)(entry + 0x60) = zero;
        *(s32 *)(entry + 0x64) = zero;
        *(u16 *)(entry + 0x80) = zero;
        *(u16 *)(entry + 0x82) = zero;
        *(u16 *)(entry + 0x84) = zero;
        *(u16 *)(entry + 0x86) = zero;
        *(u16 *)(entry + 0x88) = zero;
        *(u16 *)(entry + 0x100) = zero;
        *(s32 *)(entry + 0xF8) = zero;
        *(s32 *)(entry + 0xE8) = zero;
        *(s32 *)(entry + 0xEC) = zero;
        *(u16 *)(entry + 0x108) = zero;
        *(u16 *)(entry + 0x10A) = zero;
        *(u16 *)(entry + 0x10C) = zero;
        *(u16 *)(entry + 0x10E) = zero;
        *(u16 *)(entry + 0x110) = zero;
        *(u16 *)(entry + 6) = forty;
        *(u16 *)(entry + 8) = zero;
        *(f32 *)(entry + 0xC) = f0;
        *(f32 *)(entry + 0x10) = f1;
        *(f32 *)(entry + 0x14) = f0;
        *(u16 *)entry = one;
        if (arg2 != 0) {
            *(u16 *)entry = (u16)(*(u16 *)entry | 0x400);
        }
    }
    sprintf(gSoundPathBuf, Sound_str + 0x1E, arg1, Sound_str + 0x23);
    buf = gSoundPathBuf;
    h = fn_800B4A84(buf, 0, 0);
    *(void **)(entry + 0x2C) = h;
    if (h == NULL) {
        *(u16 *)entry = 0;
        return;
    }
    h = fn_800B4A84(buf, 0, 0);
    *(void **)(entry + 0xB4) = h;
    if (h == NULL) {
        *(u16 *)entry = 0;
        return;
    }
    fn_800B49E0(*(void **)(entry + 0x2C), *(s32 *)(entry + 0x54), 0x100, 0, fn_800AFF28);
}
void fn_800B0AC8(void *arg0, void *arg1) {
    M2C_UNK fn_800B080C(void *, void *, M2C_UNK);
    fn_800B080C(arg0, arg1, 0);
}

s32 fn_800B0AEC(u16 *dstL, u32 nL, u16 *dstR, u32 nR, u8 ch) {
    extern u16 gSoundSys[4976];
    u8 *sys = (u8 *)gSoundSys;
    u8 *entry;
    u8 *side;
    u16 flags;
    u16 *p;
    u8 *bp;
    s16 *sp;
    u32 i, n;
    u32 *bufs;
    u32 lim;

    entry = *(u8 **)(sys + 0xF8) + ch * 0x13C;
    if (dstL == NULL && dstR == NULL && nL == 0 && nR == 0) {
        return 0;
    }
    *(s32 *)(entry + 0x28) = 0;
    flags = *(u16 *)entry;
    if ((flags & 0x8006) != 0 || *(u16 *)(sys + 0x12C) != 0) {
        if (flags & 0x100) {
            n = nL / 7;
            n = ((nL - n) >> 1) + n;
            n = ((n >> 31) + (n & ~7U)) >> 1;
            p = dstL;
            i = n >> 3;
            while (i--) {
                p[0] = p[1] = p[2] = p[3] = p[4] = p[5] = p[6] = p[7] = 0;
                p += 8;
            }
            n &= 7;
            while (n--) {
                *p++ = 0;
            }
            n = nR / 7;
            n = ((nR - n) >> 1) + n;
            n = ((n >> 31) + (n & ~7U)) >> 1;
            p = dstR;
            i = n >> 3;
            while (i--) {
                p[0] = p[1] = p[2] = p[3] = p[4] = p[5] = p[6] = p[7] = 0;
                p += 8;
            }
            n &= 7;
            while (n--) {
                *p++ = 0;
            }
            return (s32)(nL + nR);
        }
        p = dstL;
        for (i = 0; i < nL; i++) {
            *p++ = 0;
            *(s32 *)(entry + 0x28) += 1;
        }
        p = dstR;
        for (i = 0; i < nR; i++) {
            *p++ = 0;
            *(s32 *)(entry + 0x28) += 1;
        }
        return *(s32 *)(entry + 0x28);
    }
    if (ch & 0x100) {
        side = entry + 0xB4;
    } else {
        side = entry + 0x2C;
    }
    if (flags & 0x100) {
        n = ((nL + 0xD) / 7) & ~7;
        bufs = (u32 *)(side + 0x2C);
        bp = (u8 *)bufs[*(u16 *)(side + 0x4C)] + *(u32 *)(side + 0x44);
        while (n != 0) {
            *(u8 *)dstL = *bp;
            bp++;
            n--;
            dstL = (u16 *)((u8 *)dstL + 1);
            *(u32 *)(side + 0x44) += 1;
            *(u32 *)(side + 0x38) += 1;
            lim = *(u32 *)(side + (*(u16 *)(side + 0x4C) * 4) + 0x3C);
            if (*(u32 *)(side + 0x44) >= lim) {
                if (*(s16 *)(side + 0x54) == 0 && !(*(u16 *)entry & 0x4000)) {
                    *(u32 *)(side + 0x38) -= *(u32 *)(side + 0x44);
                    *(u32 *)(side + 0x44) = 0;
                    bp = (u8 *)bufs[*(u16 *)(side + 0x4C)];
                } else {
                    *(s16 *)(side + 0x54) = 0;
                    *(u32 *)(side + 0x44) = 0;
                    *(u16 *)(side + 0x4C) = 1 - *(u16 *)(side + 0x4C);
                    bp = (u8 *)bufs[*(u16 *)(side + 0x4C)];
                }
            }
            if (*(u32 *)(side + 0x38) >= *(u32 *)(entry + 0x20)) {
                *(u32 *)(side + 0x38) = *(u32 *)(entry + 0x24);
                flags = *(u16 *)entry;
                if (!(flags & 0x200)) {
                    *(u16 *)entry = flags | 4;
                    break;
                }
            }
        }
        n = ((nR + 0xD) / 7) & ~7;
        while (n != 0) {
            *(u8 *)dstR = *bp;
            bp++;
            n--;
            dstR = (u16 *)((u8 *)dstR + 1);
            *(u32 *)(side + 0x44) += 1;
            *(u32 *)(side + 0x38) += 1;
            lim = *(u32 *)(side + (*(u16 *)(side + 0x4C) * 4) + 0x3C);
            if (*(u32 *)(side + 0x44) >= lim) {
                if (*(s16 *)(side + 0x54) == 0 && !(*(u16 *)entry & 0x4000)) {
                    *(u32 *)(side + 0x38) -= *(u32 *)(side + 0x44);
                    *(u32 *)(side + 0x44) = 0;
                    bp = (u8 *)bufs[*(u16 *)(side + 0x4C)];
                } else {
                    *(s16 *)(side + 0x54) = 0;
                    *(u32 *)(side + 0x44) = 0;
                    *(u16 *)(side + 0x4C) = 1 - *(u16 *)(side + 0x4C);
                    bp = (u8 *)bufs[*(u16 *)(side + 0x4C)];
                }
            }
            if (*(u32 *)(side + 0x38) >= *(u32 *)(entry + 0x20)) {
                *(u32 *)(side + 0x38) = *(u32 *)(entry + 0x24);
                flags = *(u16 *)entry;
                if (!(flags & 0x200)) {
                    *(u16 *)entry = flags | 4;
                    break;
                }
            }
        }
        *(s32 *)(entry + 0x28) = (s32)(nL + nR);
    } else {
        bufs = (u32 *)(side + 0x2C);
        sp = (s16 *)((u8 *)bufs[*(u16 *)(side + 0x4C)] + (*(u32 *)(side + 0x44) & ~1U));
        while (nL != 0) {
            *dstL = *sp;
            sp++;
            nL--;
            dstL++;
            *(s32 *)(entry + 0x28) += 1;
            *(u32 *)(side + 0x44) += 2;
            *(u32 *)(side + 0x38) += 2;
            lim = *(u32 *)(side + (*(u16 *)(side + 0x4C) * 4) + 0x3C);
            if (*(u32 *)(side + 0x44) >= lim) {
                if (*(s16 *)(side + 0x54) == 0 && !(*(u16 *)entry & 0x4000)) {
                    *(u32 *)(side + 0x38) -= *(u32 *)(side + 0x44);
                    *(u32 *)(side + 0x44) = 0;
                    sp = (s16 *)bufs[*(u16 *)(side + 0x4C)];
                } else {
                    *(s16 *)(side + 0x54) = 0;
                    *(u32 *)(side + 0x44) = 0;
                    *(u16 *)(side + 0x4C) = 1 - *(u16 *)(side + 0x4C);
                    sp = (s16 *)bufs[*(u16 *)(side + 0x4C)];
                }
            }
            if (*(u32 *)(side + 0x38) >= *(u32 *)(entry + 0x20)) {
                *(u32 *)(side + 0x38) = *(u32 *)(entry + 0x24);
                flags = *(u16 *)entry;
                if (!(flags & 0x200)) {
                    *(u16 *)entry = flags | 4;
                    break;
                }
            }
        }
        while (nR != 0) {
            *dstR = *sp;
            sp++;
            nR--;
            dstR++;
            *(s32 *)(entry + 0x28) += 1;
            *(u32 *)(side + 0x44) += 2;
            *(u32 *)(side + 0x38) += 2;
            lim = *(u32 *)(side + (*(u16 *)(side + 0x4C) * 4) + 0x3C);
            if (*(u32 *)(side + 0x44) >= lim) {
                if (*(s16 *)(side + 0x54) == 0 && !(*(u16 *)entry & 0x4000)) {
                    *(u32 *)(side + 0x38) -= *(u32 *)(side + 0x44);
                    *(u32 *)(side + 0x44) = 0;
                    sp = (s16 *)bufs[*(u16 *)(side + 0x4C)];
                } else {
                    *(s16 *)(side + 0x54) = 0;
                    *(u32 *)(side + 0x44) = 0;
                    *(u16 *)(side + 0x4C) = 1 - *(u16 *)(side + 0x4C);
                    sp = (s16 *)bufs[*(u16 *)(side + 0x4C)];
                }
            }
            if (*(u32 *)(side + 0x38) >= *(u32 *)(entry + 0x20)) {
                *(u32 *)(side + 0x38) = *(u32 *)(entry + 0x24);
                flags = *(u16 *)entry;
                if (!(flags & 0x200)) {
                    *(u16 *)entry = flags | 4;
                    break;
                }
            }
        }
    }
    return *(s32 *)(entry + 0x28);
}

s32 fn_800B125C(s32 arg0, s32 arg1) {
    extern u16 gSoundSys[4976];
    void *entry;
    s32 result;
    
    entry = &gSoundSys[0xF0] + arg0 * 16;
    if (*(u32*)((char*)entry + 0xC) == 0xFFFFFFFF) {
        return -1;
    }
    
    result = *(s32*)((char*)entry + 0x8);
    if (result < 0) {
        return 0;
    }
    
    if ((arg1 & 0x80000000) != 0) {
        *(u32*)((char*)entry + 0x4) = arg1 & 0x7FFFFFFF;
        return result;
    }
    
    if (arg1 >= result) {
        return result;
    }
    
    return arg1;
}

#pragma opt_strength_reduction on
void fn_800B1368(void *arg0) {
    void fn_800B1720(void *);
    s32 fn_800B49C8(void *);
    void fn_800B49E0(void *, s32, s32, s32, void *);
    void DCInvalidateRange(void *, u32);
    void ARQPostRequest(void *, void *, s32, s32, u32, void *, u32, void *);


    u32 base, offset, limit, n, step;
    u32 size;
    u32 aligned;
    u8 *entry;
    u8 *stream;
    s32 i;
    entry = *(u8 **)((u8 *)gSoundSys + 0xF8) + (u8)*(u32 *)((u8 *)arg0 + 4) * 0x13C;
    if (*(u32 *)(entry + 0x64) >= (u32)fn_800B49C8(*(void **)(entry + 0x2C))) {
        *(u32 *)(entry + 0x60) = 0;
        *(u32 *)(entry + 0x64) = 0;
        *(u32 *)(entry + 0xE8) = 0;
        *(u32 *)(entry + 0xEC) = 0;
        *(u16 *)(entry + 0x78) = 1;
        stream = entry + 0x2C;
        step = 0x10000;
        size = step - 0x8000;
        offset = *(u32 *)(entry + 0x60);
        limit = *(u32 *)(entry + 0x8C);
        if (offset + 0x8000 > limit) size = limit - offset;
        else {
            for (n = 2; n < 6; n++) {
                if (offset + step > limit) {
                    size -= (0x8000 - (limit - (offset + ((n - 1) << 15)))) / n;
                    size += 0x20 - (size & 0x1F);
                    break;
                }
                step += 0x8000;
            }
        }
        aligned = (size + 0x1F) & ~0x1F;
        if (!(*(u16 *)entry & 0x400)) {
            fn_800B49E0(*(void **)stream, ((StreamB *)(stream + (1 - *(u16 *)(stream + 0x4C))*4))->buffers[0], aligned, *(u16 *)(entry + 4) + offset, fn_800B1720);
        } else {
            base = *(u32 *)((u8 *)gSoundSys + *(u16 *)(entry + 2)*4 + 0x134) + offset + *(u16 *)(entry + 4);
            DCInvalidateRange((void *)((StreamB *)(stream + (1 - *(u16 *)(stream + 0x4C))*4))->buffers[0], 0x8000);
            ARQPostRequest(stream + 4, stream, 1, 0, base, (void *)((StreamB *)(stream + (1 - *(u16 *)(stream + 0x4C))*4))->buffers[0], aligned, fn_800B16EC);
        }
        *(u32 *)(stream + 0x48) = size;
        if (*(u16 *)(entry + 0x1E) == 2) {
            *(u16 *)(entry + 0x100) = 1;
            stream = entry + 0xB4;
            step = 0x10000;
        size = step - 0x8000;
            offset = *(u32 *)(entry + 0xE8);
            limit = *(u32 *)(entry + 0x114);
            base = limit + (0x20 - (limit & 0x1F));
            if (offset + 0x8000 > limit) size = limit - offset;
            else {
                    for (n = 2; n < 6; n++) {
                    if (offset + step > limit) {
                        size -= (0x8000 - (limit - (offset + ((n - 1) << 15)))) / n;
                        size += 0x20 - (size & 0x1F);
                        break;
                    }
                    step += 0x8000;
                }
            }
            aligned = (size + 0x1F) & ~0x1F;
            if (!(*(u16 *)entry & 0x400)) {
                fn_800B49E0(*(void **)stream, ((StreamB *)(stream + (1 - *(u16 *)(stream + 0x4C))*4))->buffers[0], aligned, *(u16 *)(entry + 4) + (offset + base), fn_800B1720);
            } else {
                base = offset + base + *(u32 *)((u8 *)gSoundSys + *(u16 *)(entry + 2)*4 + 0x134) + *(u16 *)(entry + 4);
                DCInvalidateRange((void *)((StreamB *)(stream + (1 - *(u16 *)(stream + 0x4C))*4))->buffers[0], 0x8000);
                ARQPostRequest(stream + 4, stream, 1, 0, base, (void *)((StreamB *)(stream + (1 - *(u16 *)(stream + 0x4C))*4))->buffers[0], aligned, fn_800B16EC);
            }
            *(u32 *)(stream + 0x48) = size;
        }
    } else {
        limit = fn_800B49C8(*(void **)(entry + 0x2C));
        offset = *(u32 *)(entry + 0x60);
        step = 0x10000;
        size = step - 0x8000;
        if (offset + 0x8000 >= limit) size = limit - offset;
        fn_800B49E0(*(void **)(entry + 0x2C), *(s32 *)(entry + 0x58), (size + 0x1F) & ~0x1F, offset, fn_800B125C);
        *(u32 *)(entry + 0x74) = size;
    }
}
#pragma opt_strength_reduction reset
