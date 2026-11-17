// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"
#include "global.h"
#include "ef.h"

extern u16 gSystemSave[];
void fn_801E4380(void) {
    extern u16 gSystemSave[];
    s32 fn_8021D614(s32, u32 *);
    s64 OSGetTime(void);
    s32 fn_80211690(void);
    u16 fn_802072A0(void);
    u8 fn_80209A0C(void);
    void *memset(void *, s32, u32);

    union {
        u64 value;
        u32 words[2];
    } timestamp;
    u8 *save;
    s32 language;

    save = (u8 *)gSystemSave;
    *(u32 *)(save + 0x00) = 0x53595346U;
    *(u32 *)(save + 0x04) = 0x20050201U;

    timestamp.words[1] = 0;
    timestamp.words[0] = 0;
    fn_8021D614(0, timestamp.words);
    timestamp.value += (u64)OSGetTime();
    timestamp.value += (u32)fn_80211690() * 0x7BU;

    *(u32 *)(save + 0x0C) = timestamp.words[1];
    *(u32 *)(save + 0x08) = timestamp.words[0];
    *(u16 *)(save + 0x10) = 0;
    save[0x40] = 0;
    save[0x41] = 0;
    save[0x42] = 0x40;
    save[0x43] = 0;

    language = 0;
    if (fn_802072A0() != 1) {
        switch ((s32)fn_80209A0C()) {
        case 0:
            language = 1;
            break;
        case 1:
            language = 2;
            break;
        case 2:
            language = 3;
            break;
        case 3:
            language = 4;
            break;
        case 4:
            language = 5;
            break;
        case 5:
            language = 1;
            break;
        }
    }

    ((volatile u8 *)save)[0x44] = (u8)language;
    save[0x47] = 0;
    memset(save + 0x12, 0, 0x1E);
    memset(save + 0x45, 0, 2);

    *(u32 *)(save + 0x3C) = 0;
    *(u32 *)(save + 0x38) = 0;
    *(u32 *)(save + 0x34) = 0;
    *(u32 *)(save + 0x30) = 0;
    *(u32 *)(save + 0x00) = 0xFFFFFFFFU;
    *(u32 *)(save + 0x04) = 0xFFFFFFFFU;
    ((volatile u8 *)save)[0x44] = 1;
}
