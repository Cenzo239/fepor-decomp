/* Functions from 0x800AD24C to 0x800C3F18, found by decomp-toolkit. */
#include "common.h"

typedef struct {
    u8 flag : 1;
    u8 unk : 7;
} ItemFlagBits;

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

#pragma peephole off
void fn_800AE444(void *arg0) {
    f32 fn_80059F64(f32, f32, f32, f32);
    f32 fn_8005A028(M2C_UNK, f32, f32, f32, f32);
    extern f32 lbl_80369C78;
    extern f32 lbl_80369C7C;
    extern f32 lbl_80369C80;
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) - 1);
    M2C_FIELD(arg0, f32 *, 0x38) = fn_8005A028(2, lbl_80369C78, lbl_80369C7C, (f32) M2C_FIELD(arg0, s32 *, 0x44), (f32) M2C_FIELD(arg0, s32 *, 0x30));
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) fn_80059F64(lbl_80369C7C, lbl_80369C80, (f32) M2C_FIELD(arg0, s32 *, 0x44), (f32) M2C_FIELD(arg0, s32 *, 0x30));
    if ((s32) M2C_FIELD(arg0, s32 *, 0x30) <= 0) {
        fn_8000C188(arg0);
    }
}
