/* Functions from 0x80006264 to 0x80011968, found by decomp-toolkit. */
#include "common.h"
#include "process.h"

typedef struct {
    void *unk0;
    void *unk4;
    s32 unk8;
} Struct_8000B090;

extern s32 lbl_802AEE20[5]; // array of 5 pointers
extern f64 lbl_80368C28;    // global float constant
extern u16 jumptable_80283AE8[];

#pragma optimization_level 2
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma optimization_level reset

#pragma opt_unroll off

#pragma global_optimizer reset

#pragma global_optimizer on
#pragma opt_strength_reduction on

#pragma optimization_level 3
void fn_80006388(void) {
    s32 OSDisableInterrupts(void);
    void OSDisableScheduler(void);
    void OSEnableScheduler(void);
    void OSRestoreInterrupts(s32);
    void fn_8020ADD8(void *);
    void fn_8020AEC4(void *);
    extern u8 lbl_802A51C0[];
    extern u8 lbl_80367130;
    extern u8 lbl_80367131;
    extern s32 lbl_80367138;

    s32 temp_r30;
    s32 bitCount;
    s8 bitFlags;
    s32 copyLen;
    s32 copied;
    s32 left;
    u8 *src;
    u8 *dst;
    u8 *dstStart;
    u8 *back;
    u8 *slot;
    s32 t7;
    s32 t6;
    s32 t8;
    s32 uncompSize;
    u8 idxByte;
    void (*cb)(s32, void *, void *);
    u32 var_ctr;
    s32 var_ctr_2;

    goto loop_cond;
loop_body:
    bitCount = 0;
    slot = lbl_802A51C0 + ((s8)idxByte * 0x10);
    src = *(u8 **)slot;
    dst = *(u8 **)(slot + 4);
    dstStart = dst;
    if ((u8)*src == 0x10) {
        t7 = src[2];
        t6 = src[3];
        t8 = src[1];
        src += 4;
        uncompSize = t8 + ((t7 << 8) & 0xFF00) + ((t6 << 16) & 0xFF0000);
    loop_inner:
        if (uncompSize != (s32)(dst - dstStart)) {
            if ((s8)bitCount == 0) {
                bitFlags = (s8)*src;
                bitCount = 8;
                src += 1;
            }
            if (bitFlags >= 0) {
                *dst = *src;
                src += 1;
                dst += 1;
            } else {
                t8 = src[0];
                t6 = src[1];
                src += 2;
                copyLen = ((t8 >> 4) & 0xF) + 3;
                back = (dst - (((t8 << 8) & 0xF00) + t6)) - 1;
                copied = 0;
                if (copyLen > 0) {
                    left = copyLen - 8;
                    if (copyLen > 8) {
                        var_ctr = (u32)(left + 7) >> 3U;
                        if (left > 0) {
                            do {
                                copied += 8;
                                dst[0] = back[0];
                                dst[1] = back[1];
                                dst[2] = back[2];
                                dst[3] = back[3];
                                dst[4] = back[4];
                                dst[5] = back[5];
                                dst[6] = back[6];
                                dst[7] = back[7];
                                back += 8;
                                dst += 8;
                                var_ctr -= 1;
                            } while (var_ctr != 0);
                        }
                    }
                    var_ctr_2 = copyLen - copied;
                    if (copied < copyLen) {
                        do {
                            t6 = *back;
                            copied += 1;
                            back += 1;
                            *dst = t6;
                            dst += 1;
                            var_ctr_2 -= 1;
                        } while (var_ctr_2 != 0);
                    }
                }
            }
            bitCount -= 1;
            bitFlags = (s8)(bitFlags * 2);
            goto loop_inner;
        }
    }
    slot = lbl_802A51C0 + ((s8)lbl_80367130 * 0x10);
    if (*(u32 *)(slot + 8) != 0U) {
        temp_r30 = OSDisableInterrupts();
        OSDisableScheduler();
        slot = lbl_802A51C0 + ((s8)lbl_80367130 * 0x10);
        cb = *(void (**)(s32, void *, void *))(slot + 8);
        cb(*(s32 *)(slot + 0xC), *(void **)slot, *(void **)(slot + 4));
        OSEnableScheduler();
        OSRestoreInterrupts(temp_r30);
    }
    lbl_80367130 = (lbl_80367130 + 1) & 0x1F;
loop_cond:
    idxByte = lbl_80367130;
    if ((s8)idxByte != (s8)lbl_80367131) {
        goto loop_body;
    }
    fn_8020AEC4(&lbl_80367138);
    fn_8020ADD8(&lbl_80367138);
    goto loop_cond;
}
#pragma optimization_level reset
