// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

void fn_8001EE58(void)
{
    void Icon_FreeSlot(void *, s32);
    void Item_Destroy(void);

    typedef struct {
        u8 pad : 1;
        u8 flag : 1;
        u8 rest : 6;
    } Bit6;
    typedef struct {
        u32 word;
        u8 byte4;
        Bit6 byte5;
    } ItemGlobal;
    extern ItemGlobal lbl_80367218;
    extern u8 gIconSlots[];
    extern u8 lbl_802CA4B0[];

    s32 mask;

    lbl_80367218.byte5.rest = 0;
    lbl_80367218.word = 0;
    lbl_80367218.byte4 = 0;
    lbl_80367218.byte5.pad = 0;
    lbl_80367218.byte5.flag = 0;
    mask = lbl_80367218.byte5.rest;
    if (mask != 0) {
        Icon_FreeSlot(gIconSlots, mask);
        lbl_80367218.byte5.rest = 0;
    }
    __register_global_object(&lbl_80367218, Item_Destroy, lbl_802CA4B0);
}
