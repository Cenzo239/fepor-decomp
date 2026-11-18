/* Functions from 0x800AD24C to 0x800C3F18, found by decomp-toolkit. */
#include "common.h"

typedef struct {
    u8 flag : 1;
    u8 unk : 7;
} ItemFlagBits;

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
    M2C_UNK Item_Init(s32);
    Item_Init(arg0 + 4);
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
    void Event_BlessStartRoundSky(void *, void *);
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
    case 1: Event_BlessStartRoundSky(gUiContext, proc); break;
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
    void Battle_Apply(void *);
    extern u8 gBattle[];
    *(s32 *)(gBattle + 0xCAC) |= 1;
    Battle_Apply(gBattle);
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
