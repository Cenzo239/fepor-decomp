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

void Icon_WriteSlots(s32 arg0, s32 arg1) {
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
s32 off; u8 *p; u8 *q; u8 b3,b2,b1,b0; u8 flag;
off=arg1*0x18; b0=arg2[0]; b1=arg2[1]; flag=0; b2=arg2[2]; b3=arg2[3];
p=arg0+off; p[-4]=b0;p[-3]=b1;p[-2]=b2;p[-1]=b3;
if ((s8)p[-0x17]==0 && (s8)p[-8]==0 && (s8)p[-7]==0 && (s8)p[-6]==0 && (s8)p[-5]==0 && p[-4]==0x80 && p[-3]==0x80 && p[-2]==0x80 && p[-1]==0xFF) flag=1;
if(flag) {q=arg0+off; arg1=0; q[-0x18]=arg1;p[-0x17]=arg1;q[-5]=arg1;q[-6]=arg1;q[-7]=arg1;q[-8]=arg1;p[-2]=0x80;p[-3]=0x80;p[-4]=0x80;p[-1]=0xFF;}
return arg1;
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
    s32 off;
    u8 flag;
    s32 ret;
    Unk800C2ACC *p;
    u8 *q;

    off = idx * 0x18;
    flag = 0;
    ret = idx;
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
        ret = 0;
        q[-0x18] = (u8)ret;
        ((u8 *)p)[-0x17] = (u8)ret;
        q[-5] = (u8)ret;
        ((u8 *)p)[-6] = (u8)ret;
        q[-7] = (u8)ret;
        q[-8] = (u8)ret;
        q[-2] = 0x80;
        q[-3] = 0x80;
        q[-4] = 0x80;
        q[-1] = 0xFF;
    }
    return ret;
}

s8 fn_800C2C84(s32 arg0, s32 arg1) {
    u8 *ptr = (u8 *)arg0;
    return ptr[(arg1 * 0x18) - 7];
}

s32 fn_800C2C98(Unk800C2ACC *arr, s32 idx, u8 val) {
    struct { u8 flag; s32 off; } s;
    Unk800C2ACC *p = &arr[idx];
    s32 ret = idx;

    s.off = idx * 0x18;
    s.flag = 0;
    ((u8 *)p)[-7] = val;
    if ((s8)((u8 *)p)[-0x17] == 0 && (s8)((u8 *)p)[-8] == 0 && (s8)((u8 *)p)[-7] == 0 &&
        (s8)((u8 *)p)[-6] == 0 && (s8)((u8 *)p)[-5] == 0 && ((u8 *)p)[-4] == 0x80 &&
        ((u8 *)p)[-3] == 0x80 && ((u8 *)p)[-2] == 0x80 && ((u8 *)p)[-1] == 0xFF) {
        s.flag = 1;
    }
    if (s.flag) {
        u8 *q = (u8 *)arr + s.off;
        ret = 0;
        q[-0x18] = (u8)ret;
        ((u8 *)p)[-0x17] = (u8)ret;
        q[-5] = (u8)ret;
        q[-6] = (u8)ret;
        ((u8 *)p)[-7] = (u8)ret;
        q[-8] = (u8)ret;
        q[-2] = 0x80;
        q[-3] = 0x80;
        q[-4] = 0x80;
        q[-1] = 0xFF;
    }
    return ret;
}

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

#pragma opt_common_subs off
s32 fn_800C2EF8(u8 *slots, s32 index, u8 *str)
{
  s32 fn_80010710(u8 *);
  void *memset(void *, s32, u32);
  u8 *src;
  u8 *dst;
  u8 *new_var2;
  u32 count;
  u8 is_sjis;
  u8 flag;
  s32 off;
  u8 *end;
  int new_var;
  u8 *p;
  u32 b0;
  u32 b1;
  new_var2 = (slots + ((index - 1) * 0x18)) + 1;
  src = str;
  dst = new_var2;
  new_var = 0xF;
  memset(dst, 0, new_var);
  count = 0;
  goto check;
  body:
  src += fn_80010710(src);

  if (((s8) (*src)) == 0)
  {
    goto done;
  }
  b1 = *((volatile u8 *) src);
  b0 = b1 & 0xFF;
  if (!(((b0 >= 0x81U) && (b0 <= 0x9FU)) || ((b0 >= 0xE0U) && (b0 <= 0xFCU))))
  {
    goto not_sjis;
  }
  b1 = src[1];
  if (!(((b1 >= 0x40U) && (b1 <= 0x7EU)) || ((b1 >= 0x80U) && (b1 <= 0xFCU))))
  {
    goto not_sjis;
  }
  is_sjis = 1;
  goto after_sjis;
  not_sjis:
  is_sjis = 0;

  after_sjis:
  if (is_sjis != 0)
  {
    b0 = src[0];
    b1 = src[1];
    src += 2;
    dst[0] = (u8) b0;
    dst[1] = (u8) b1;
    dst += 2;
  }
  else
  {
    register u32 tmp = src[0];
    src += 1;
    dst[0] = (u8) tmp;
    dst += 1;
  }

  ++count;
  check:
  if (((s8) (*src)) == 0)
  {
    goto done;
  }

  if (count < 0xEU)
  {
    goto body;
  }
  done:
  off = index * 0x18;

  end = slots + off;
  flag = 0;
  if (((((((((((s8) end[-0x17]) == 0) && (((s8) end[-0x8]) == 0)) && (((s8) end[-0x7]) == 0)) && (((s8) end[-0x6]) == 0)) && (((s8) end[-0x5]) == 0)) && (end[-0x4] == 0x80)) && (end[-0x3] == 0x80)) && (end[-0x2] == 0x80)) && (end[-0x1] == 0xFF))
  {
    flag = 1;
  }
  if (flag != 0)
  {
    p = slots + off;
    {
      u8 z = 0;
      u8 a = 0x80;
      u8 b = 0xFF;
      p[-0x18] = z;
      end[-0x17] = z;
      p[-0x5] = z;
      p[-0x6] = z;
      p[-0x7] = z;
      p[-0x8] = z;
      p[-0x2] = a;
      p[-0x3] = a;
      p[-0x4] = a;
      p[-0x1] = b;
    }
    return 0;
  }
  return index;
}
#pragma opt_common_subs reset
s32 Icon_GetSlot(s32 arg0, s32 arg1) {
    return arg0 + ((arg1 - 1) * 0x18);
}
