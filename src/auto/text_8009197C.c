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
extern s32 gFaceDbgMouthEndStr;
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
extern f64 lbl_80369770;
extern u16 lbl_80289A60[];

extern u8 lbl_80289B00[16];

extern void* fn_800980D4(s32 arg0);
extern void fn_8017E394(void* arg0, void* arg1, void* arg2, s32 arg3);

extern u8 lbl_80289EB8[16];

extern f32 lbl_803697E0;
extern f32 lbl_803697E4;

#pragma scheduling reset

void fn_8009197C(void) {
    void Process_ClearFunc(u32);
    extern u32 gProcessQueue[];
    extern s32 gProcessQueueCount;

    while (gProcessQueueCount != 0) {
        if (gProcessQueueCount != 0) {
            gProcessQueueCount--;
            Process_ClearFunc(gProcessQueue[gProcessQueueCount]);
        }
    }
}

void fn_800919D8(void) {
    M2C_UNK Process_ClearFunc(s32, s32);
    extern u32 gProcessQueue[];
    extern s32 gProcessQueueCount;
    s32 temp_r4;

    if ((s32) gProcessQueueCount != 0) {
        temp_r4 = gProcessQueueCount - 1;
        gProcessQueueCount = temp_r4;
        Process_ClearFunc(gProcessQueue[temp_r4], temp_r4);
    }
}

#pragma optimization_level 3
void fn_80091A1C(void *arg0) {
    extern s32 gProcessQueueCount;
    extern u8 *gProcessQueue[];
    extern u8 E_CmdPlate_script[];
    extern f32 lbl_803697A4, gZeroF, lbl_803697A8, lbl_803697AC;
    u8 *Process_Create(void *, s32);
    s32 Str_Cmp(void *, void *);
    char *strcpy(char *, const char *);
    u8 *p;
    s32 index;
    f32 a, b, c;
    if (gProcessQueueCount > 0 && Str_Cmp(gProcessQueue[gProcessQueueCount - 1] + 0x58, arg0) == 0) return;
    p = Process_Create(E_CmdPlate_script, 4);
    gProcessQueue[gProcessQueueCount++] = p;
    index = gProcessQueueCount - 1;
    strcpy((char *)p + 0x58, arg0);
    *(f32 *)(p + 0x3C) = lbl_803697A4;
    a = gZeroF;
    b = lbl_803697A8;
    c = lbl_803697AC;
    *(f32 *)(p + 0x40) = index * 31 + 24;
    *(f32 *)(p + 0x44) = a;
    *(f32 *)(p + 0x48) = b;
    *(f32 *)(p + 0x4C) = index * 31 + 24;
    *(f32 *)(p + 0x50) = c;
    p[0x54] = 0;
    p[0x55] = 8;
    p[0x56] = 6;
    p[0x6F] = index;
}
#pragma optimization_level reset
void fn_80091B38(void *arg0)
{
  u8 *new_var;
  extern f32 gZeroF;
  extern f32 lbl_803697A4;
  s32 zero;
  s32 eight;
  s32 three;
  f32 w;
  f32 y2;
  f32 y;
  f32 z;
  f32 x;
  zero = 0;
  eight = 8;
  new_var = ((u8 *) arg0) + 0x3C;
  three = 3;
  x = *((f32 *) (((u8 *) arg0) + 0x38));
  y = *((f32 *) (((u8 *) arg0) + 0x34));
  z = *((f32 *) (((u8 *) arg0) + 0x30));
  w = lbl_803697A4;
  *((f32 *) new_var) = z;
  z = gZeroF;
  *((f32 *) (((u8 *) arg0) + 0x40)) = y;
  *((f32 *) (((u8 *) arg0) + 0x44)) = x;
  y2 = *((f32 *) (((u8 *) arg0) + 0x34));
  *((f32 *) (((u8 *) arg0) + 0x48)) = w;
  *((f32 *) (((u8 *) arg0) + 0x4C)) = y2;
  *((f32 *) (((u8 *) arg0) + 0x50)) = z;
  *((u8 *) (((u8 *) arg0) + 0x54)) = (u8) zero;
  *((u8 *) (((u8 *) arg0) + 0x55)) = (u8) eight;
  *((u8 *) (((u8 *) arg0) + 0x56)) = (u8) three;
}

f32 Math_Ease(s32, f32, f32, f32, f32);
s32 fn_800AA188(void);
void fn_8008B2B0(s32, s32, s32, s32, void *);
void Prim2D_ResetState(void);
void fn_80091B84(void *arg0) {
    if (((u8 *)arg0)[0x54] <= ((u8 *)arg0)[0x55]) {
        *(f32 *)((u8 *)arg0 + 0x30) = Math_Ease(
            ((u8 *)arg0)[0x56],
            *(f32 *)((u8 *)arg0 + 0x3C),
            *(f32 *)((u8 *)arg0 + 0x48),
            (f32)((u8 *)arg0)[0x54],
            (f32)((u8 *)arg0)[0x55]);
        *(f32 *)((u8 *)arg0 + 0x34) = Math_Ease(
            ((u8 *)arg0)[0x56],
            *(f32 *)((u8 *)arg0 + 0x40),
            *(f32 *)((u8 *)arg0 + 0x4C),
            (f32)((u8 *)arg0)[0x54],
            (f32)((u8 *)arg0)[0x55]);
        *(f32 *)((u8 *)arg0 + 0x38) = Math_Ease(
            0,
            *(f32 *)((u8 *)arg0 + 0x44),
            *(f32 *)((u8 *)arg0 + 0x50),
            (f32)((u8 *)arg0)[0x54],
            (f32)((u8 *)arg0)[0x55]);
        ((u8 *)arg0)[0x54]++;
    }
    if ((u8)fn_800AA188()) {
        fn_8008B2B0(
            (s32)*(f32 *)((u8 *)arg0 + 0x30),
            (s32)*(f32 *)((u8 *)arg0 + 0x34),
            (s32)*(f32 *)((u8 *)arg0 + 0x38),
            ((u8 *)arg0)[0x6F],
            (u8 *)arg0 + 0x58);
        Prim2D_ResetState();
    }
}

void fn_80091CD8(void *arg0)
{
  u64 *Item_GetFlagsPtr(void *);
  u8 *new_var;
  u32 *fn_80037C20(void);
  u32 *p;
  s32 new_var3[2];
  u8 *new_var2;
  p = fn_80037C20();
  if ((p == NULL) || ((*p) == 0))
  {
    new_var3[0] = 0;
  }
  else
  {
    new_var3[0] = ((*Item_GetFlagsPtr(p)) & 0x100000000ULL) != 0;
  }
  if (((u8) new_var3[0]) != 0)
  {
    new_var3[1] = *((u32 *) (((u8 *) arg0) + 0x1A0));
    new_var3[1] |= 0x800000;
    *((u32 *) (((u8 *) arg0) + 0x1A0)) = new_var3[1];
  }
  else
  {
    new_var = (u8 *) arg0;
    new_var3[1] = *((u32 *) (new_var + 0x1A0));
    new_var3[1] &= ~0x800000;
    new_var2 = ((u8 *) arg0) + 0x1A0;
    *((u32 *) new_var2) = new_var3[1];
  }
}

s32 fn_80091D74(void) {
    u64 *Item_GetFlagsPtr(void *);
    u32 *fn_80037C20(void);
    u32 *p;

    p = fn_80037C20();
    if (p == NULL || *p == 0) {
        return 0;
    }
    return (*Item_GetFlagsPtr(p) & 0x100000000ULL) != 0;
}

s8 Unit_FindItemSlot(void* arg0, void* arg1) {
    void **Unit_GetHeldItemSlot(void *, s32);
    s32 i;
    void *item;
    if (*(u64 *)((u8 *)arg1 + 0x38) & 5ULL) {
        for (i = 3; i >= 0; i--) {
            item = *Unit_GetHeldItemSlot(arg0, i);
            if (item != 0 && item == arg1) return (s8)i;
        }
    } else {
        item = *(void **)((u8 *)arg0 + 0x204);
        if (item != 0 && item == arg1) return 7;
        item = *(void **)((u8 *)arg0 + 0x1FC);
        if (item != 0 && item == arg1) return 6;
        item = *(void **)((u8 *)arg0 + 0x1F4);
        if (item != 0 && item == arg1) return 5;
        item = *(void **)((u8 *)arg0 + 0x1EC);
        if (item != 0 && item == arg1) return 4;
    }
    return -1;
}

#pragma global_optimizer off
static inline u8 CanUseItemImpl(s32 arg0, void *arg1, u8 def) {
    u8 fn_800940B0(s32, void *);
    u64 flags = *(u64 *)((u8 *)arg1 + 0x38);
    if (flags & 5ULL) return fn_800940B0(arg0, arg1) != 0;
    if (flags & 0x18ULL) return fn_800940B0(arg0, arg1);
    return def;
}
u8 Unit_CanUseItem(s32 arg0, void *arg1) {
    return CanUseItemImpl(arg0, arg1, 0);
}
#pragma global_optimizer reset
/* If the item's _UFX resource allows the current game state, invoke it. */
s32 Item_TryCallUfx(s32 unit, s32 item) {
    s32 Game_GetState();
    s32 Item_CallUfx(s32, s32);
    void *Item_GetUfx(s32);
    u8 ok;
    u8 okOther;
    void *ufx;
    void *ufxOther;

    if (Game_GetState() == 0x10) {
        ufx = Item_GetUfx(item);
        if (ufx == NULL) {
            ok = 0;
        } else if ((u32) M2C_FIELD(ufx, u32 *, 0) == 0U) {
            ok = 0;
        } else {
            ok = M2C_FIELD(ufx, u8 *, 4);
        }
        if (ok == 0) {
            return 0;
        }
        return Item_CallUfx(unit, item);
    }
    ufxOther = Item_GetUfx(item);
    if (ufxOther == NULL) {
        okOther = 0;
    } else if ((u32) M2C_FIELD(ufxOther, u32 *, 0) == 0U) {
        okOther = 0;
    } else {
        okOther = M2C_FIELD(ufxOther, u8 *, 5);
    }
    if (okOther == 0) {
        return 0;
    }
    return Item_CallUfx(unit, item);
}

#pragma opt_common_subs off
s32 fn_8009204C(void *arg0, void *arg1) {
    u8 Status_Test(void *, s32);
    u8 fn_800940B0(void *, void *);
    s32 Item_CallUfx(void *, void *);
    u8 ok;
    u64 flags = *(u64 *)((u8 *)arg1 + 0x38);
    if (!(flags & 4)) {
        ok = 0;
    } else {
        if (flags & 0x200) {
            if (Status_Test((u8 *)arg0 + 0x1BC, 9))
                ok = 1;
            else
                ok = 0;
        } else if (((*(u8 *)((u8 *)arg0 + 0x1A5) >> 4) & 7) == 0)
            ok = 1;
        else if (flags & 2)
            ok = 0;
        else if (flags & 4)
            ok = 0;
        else if (flags & 0x40)
            ok = 1;
        else
            ok = 1;
        if (!ok)
            ok = 0;
        else if (!fn_800940B0(arg0, arg1))
            ok = 0;
        else
            ok = 1;
    }
    if (ok)
        goto do_call;
    return 0;
do_call:
    return Item_CallUfx(arg0, arg1);
}
#pragma opt_common_subs reset
/* Find first 0x1EC item slot matching key mask; -2 if status-blocked, -1 if none. */
s32 Unit_FindKeyItemSlot(u8 *unit, s32 keyMask) {
    u8 Status_Test(u8 *, s32);
    void Item_GetKeyFlags(u8 *, s32);
    u8 flags;
    s32 result;
    u8 mask;
    u8 *p;
    s32 item;

    mask = keyMask;
    p = unit;
    if (Status_Test(p + 0x1BC, 0x5B)) {
        result = -2;
    } else if (Status_Test(p + 0x1BC, 0x50) && *(s32 *)(gBattleState + 0x18) >= 0x32) {
        result = -2;
    } else {
        for (result = 0; result < 4; result++, p += 8) {
            item = *(s32 *)(p + 0x1EC);
            if (!((u32)(-item | item) >> 31)) {
                break;
            }
            Item_GetKeyFlags(&flags, item);
            switch ((u8)(flags & mask)) {
            case 0:
                break;
            default:
                goto done;
            }
        }
        result = -1;
    }
done:
    return result;
}

s32 fn_8009226C(u8 *arg0, u8 *arg1) {
    u8 Status_Test(u8 *, s32);
    void Item_GetKeyFlags(u8 *, s32);
    u8 sp8;
    s32 i;
    u8 *p;

    if (Status_Test(arg0 + 0x1BC, 0x5B) != 0) {
        return -2;
    }
    if (Status_Test(arg0 + 0x1BC, 0x50) != 0 && *(s32 *)(gBattleState + 0x18) >= 0x32) {
        return -2;
    }
    p = arg0;
    for (i = 0; i < 4; i++) {
        if (*(u32 *)(p + 0x1EC) == 0) {
            break;
        }
        Item_GetKeyFlags(&sp8, *(s32 *)(p + 0x1EC));
        if ((u8)(sp8 & *arg1) != 0) {
            return i;
        }
        p += 8;
    }
    return -1;
}

#pragma global_optimizer off
void fn_8009233C(u8 *arg0, u8 *arg1) {
    u8 Status_Test(u8 *, s32);
    void Item_GetKeyFlags(u8 *, s32);
    s32 flags;
    u8 sp8;
    u8 *p;
    s32 i;

    p = arg1;
    flags = 0;
    if (Status_Test(p + 0x1BC, 0x5B) != 0) {
        *arg0 = 8;
        return;
    }
    if (Status_Test(p + 0x1BC, 0x50) != 0) {
        if (*(s32 *)(gBattleState + 0x18) < 0x32) {
            flags |= 0x20;
        } else {
            *arg0 = 0x10;
            return;
        }
    }
    for (i = 0; i < 4; ) {
        if (*(u32 *)(p + 0x1EC) == 0) {
            break;
        }
        Item_GetKeyFlags(&sp8, *(s32 *)(p + 0x1EC));
        i++;
        p += 8;
        flags |= sp8;
    }
    *arg0 = flags;
}
