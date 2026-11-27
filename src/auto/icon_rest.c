/* Functions from 0x800AD24C to 0x800C3F18, found by decomp-toolkit. */
#include "common.h"

typedef struct {
    u8 flag : 1;
    u8 unk : 7;
} ItemFlagBits;

static inline s32 Convoy_FindEmpty_inline(void *convoy) {
    u8 *p = (u8 *)convoy;
    s32 i;
    for (i = 0; i < 200; p += 8, i++) {
        if (*(void **)p == NULL) {
            return i;
        }
    }
    return -1;
}

static inline u8 Convoy_TryAddItem_inline(void *convoy, void *item) {
    void Item_Copy(void *, void *);
    s32 slot;
    ((ItemFlagBits *)((u8 *)item + 5))->flag = 0;
    slot = Convoy_FindEmpty_inline(convoy);
    if (slot < 0) {
        return 0;
    }
    Item_Copy((u8 *)convoy + slot * 8, item);
    return 1;
}

static inline s32 Convoy_Count_inline(void *convoy) {
    u8 *p;
    s32 count = 0;
    s32 i;
    for (i = 0, p = (u8 *)convoy; i < 200; p += 8, i++) {
        if (*(void **)p != NULL) {
            count++;
        }
    }
    return count;
}

typedef struct {
    u8 unk0[8];
    u8 param;
    u8 pad9[3];
    u32 handle;
    u8 pad10[4];
} SoundChan_800B1BFC;

extern f64 lbl_80369CF8;

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
  extern s32 E_EventCaller_script[];
  extern s32 lbl_80319A68[];
  void Battle_ClearPhaseBannerChild(void *);
  void Battle_DrawPhaseBanner(void *);

#pragma optimization_level 2
/* Collect same-allegiance units with Live/Rest statuses into an E_Bless process; return 0 if none. */

/* Advance the E_Bless queue: begin move-select for the next unit, or finish at label 0x63. */

extern u8 lbl_8028D064[16];

#pragma optimization_level reset

/* Apply prior battle, bump win/battle stats if needed, then setup and calc vs current target. */

/* Setup gBattle for healing the current target from proc HP, then open MapSelect. */

void fn_800ADD04(void);

extern u8 gTargetList[];
extern void fn_8002F61C(void *);
extern void *TargetList_GetCurrent(void *);
extern u8 *UnitRef_GetUnit(void);
extern void Unit_OnZeroHp(void);

/* Init gBattle from the current target entry's unit, apply optional HP delta, and open MapSelect. */

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern void Unit_ApplyTransform(void);

/* Set up the phase-change banner: ambient FX for this army, banner widget, and draw callback. */

/* Draw the player/enemy phase banner as two full-width gradient bars. */

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on
/* Play a sound effect: find an SE slot, duck pan/vol if the same id is already playing, start the voice. */

extern void *vidListRoot;

#pragma dont_inline on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma dont_inline reset

#pragma global_optimizer off
#pragma use_lmw_stmw on
/* Load .stm/.slib/.stbl sound banks for pack id into the next gSoundSys slot. */

#pragma global_optimizer reset

/* Return 1 if sound id is present in gSoundIdSlots (stored as id+1). */

extern u16 lbl_80319A18[];
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma use_lmw_stmw on

#pragma global_optimizer off

/* DVD callback: copy size bytes from gSoundLoadBuf+offset into the sound work buffer. */

#pragma global_optimizer on

void *fn_800C4638(s32, void *, s32);

extern u16 lbl_8028D0FC[];

#pragma global_optimizer off
#pragma use_lmw_stmw on

#pragma global_optimizer reset
extern u8 *lbl_80367820;

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern s32 lbl_8036B3A4;
extern s32 lbl_8036B3A4;

extern u8 Proc_CpPhaseMain[];

/* Serialize all units and icon slots into a new gUnitSaveBuf. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

extern u8 gMapObjEventList[];

/* Script command: set up and run a battle between two units by deployment id. */

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

/* Open a message window for msgPtr; multi-line if expanded text has a newline. */

extern void fn_8006F6A4(u32 arg0, u32 arg1, u32 arg2);

extern void MsgWin_OpenSingle(u32 arg0, u32 arg1, u32 arg2);

extern void MsgWin_OpenSingle(u32 arg0, u32 arg1, u32 arg2);

/* Script command: play a colored, scaled effect on a named script object at (x,y). */

#pragma optimization_level 1

#pragma optimization_level 4

s32 fn_800B9CD4(u32, s32, s32, s32, u32, f32);

/* Script command: look up a sound by name and tween/set a typed parameter (percent-scaled for types 5-7). */

extern void *Battle_GetActiveCombatant(u32 *);
extern s32 Res_GetByName();
extern s32 fn_800A87D4(s32);

#pragma optimization_level 3

#pragma optimization_level reset

/* Mark the given inventory slot as droppable if the unit has none already. */

#pragma optimization_level 3

#pragma optimization_level reset

extern u16 gBattleState[700];

extern u16 gBattleState[];

#pragma peephole off

#pragma peephole reset

extern u8 gUiContext[24];

extern u16 gUnits[];

/* Script: have rescuerId carry rescueeId (place beside, link, refresh map). */

extern u16 gUnitLists[50];

/* Script UnitSet: write member mid on unit id (level/exp/gauge/HP/dispos); unsupported mids return 0. */

#pragma use_lmw_stmw on

#pragma dont_inline on
#pragma use_lmw_stmw on
#pragma optimization_level 3

#pragma optimization_level reset

#pragma push
#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma scheduling on

#pragma pop

#pragma optimization_level 1

#pragma optimization_level reset

#pragma global_optimizer off

#pragma optimization_level 3

#pragma optimization_level reset
/* True if this talk entry's mode and persons match gTalkState (either order). */

#pragma global_optimizer on
/* Find the index-th kind-0xE (talk) event, spawn E_Event_script on it, clear run-flag and UI input. */

#pragma scheduling on

extern u8 lbl_80317334[];
extern s32 lbl_80368320;

#pragma optimization_level 3

#pragma optimization_level 3

#pragma optimization_level 3

#pragma optimization_level reset

#pragma optimization_level reset

#pragma optimization_level reset

#pragma optimization_level 3

#pragma optimization_level reset

/* True if this talk entry's persons match the UI unit pair (order or swapped). */

#pragma optimization_level 3

#pragma optimization_level reset

#pragma dont_inline on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma dont_inline reset

extern u16* const lbl_8036A0D0;

/* If any kind-2 event entry has its flag set, start E_EventCaller under parent and return 1. */

extern s32 lbl_80367FCC;

/* Restore battle-map UI after BMapSuspend: reset UI, restore saved BMap procs, restart the event. */

/* Save BMapMain/BMapPlph state, ensure BMap exists, and switch context for an event. */

extern u8 lbl_8028D4D0[16];

/* Copy the EFB into the capture buffer, then draw it as a Z-rotated textured strip. */

s32 GXGetTexBufferSize(s32, s32, s32, s32, s32);
void *fn_800C45B8(s32, void *, s32);
void fn_80222644(void *, void *, s32, s32, s32, s32, s32, s32);
void GXInitTexObjLOD(void *, s32, s32, s32, s32, s32, f32, f32, f32);

#pragma optimization_level 3

#pragma optimization_level reset

#pragma optimization_level 2
/* Set up map blend-mode TEV (ortho UV, texture, blend ops). Returns 0 if blend off. */

#pragma optimization_level 4

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma global_optimizer off

#pragma global_optimizer reset
extern u8 lbl_8028D768[16];

#pragma scheduling on

#pragma scheduling reset

#pragma optimization_level 2

#pragma optimization_level reset

#pragma use_lmw_stmw on
#pragma opt_common_subs off
#pragma global_optimizer off
#pragma scheduling on

#pragma scheduling reset
#pragma global_optimizer on
#pragma opt_common_subs reset
#pragma use_lmw_stmw reset

extern struct Unit;

#pragma optimization_level 3

#pragma optimization_level reset

/* Return index of first empty convoy item slot, or -1 if full. */

#include "common.h"
extern u8 gFxChannels[];
extern void Fx_FadeOut(u32*, s16);
extern void fn_80146B00(void);
#include "global.h"
extern u16 gSoundSys[];

extern u16 gSoundSys[4976];

extern f64 lbl_80369CC0;
extern f32 lbl_80369CC8;
extern f32 lbl_80369CCC;
extern f32 lbl_80369CB0;
extern f32 lbl_80369CD0;

#pragma optimization_level 3
#pragma global_optimizer off

#pragma opt_common_subs off

#pragma opt_common_subs reset

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off

#pragma optimization_level 3

#pragma optimization_level reset

#pragma opt_strength_reduction reset

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
