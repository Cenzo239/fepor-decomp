/* Functions from 0x800119C0 to 0x80016EE8, found by decomp-toolkit. */
#include "common.h"

static inline s32 Script_ReadSignedShort(void) {
    extern void *lbl_80367180;
    s32 value;
    value = *(*(s8 **)((u8 *)lbl_80367180 + 0xC))++;
    return (value << 8) + *(*(u8 **)((u8 *)lbl_80367180 + 0xC))++;
}
static inline void Script_PushWord(s32 value) {
    extern void *lbl_80367180;
    s32 *stack = (*(s32 **)((u8 *)lbl_80367180 + 0x18))++;
    *stack = value;
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_strength_reduction off

#pragma pop

#pragma push
#pragma global_optimizer on
#pragma scheduling on

#pragma pop

#pragma push
#pragma opt_propagation off

#pragma pop
#pragma dont_inline on

#pragma scheduling reset

#pragma global_optimizer off

#pragma global_optimizer on

extern s32 fn_8006785C(s16, s32, void *);

#pragma push
#pragma global_optimizer off
#pragma opt_propagation off

void main(void) {
    void *OSGetTick(void);
    void OS_YieldThread(void);
    void fn_800056CC(char *, ...);
    void fn_800059B4(void);
    void fn_800059FC(s32, s32, s32, s32, s32);
    void fn_80005A84(s32, s32);
    void fn_80005C18(void);
    void fn_80005C60(void);
    void fn_80006314(void);
    void fn_80006754(void);
    void fn_80007B04(void);
    void fn_80008B94(void);
    void fn_8000A280(void);
    void fn_8000A284(f32, f32, f32, f32);
    void fn_8000A2A8(s32);
    void fn_8000A860(s32, s32, s32);
    void fn_8000C194(s32);
    void fn_8000CC88(void);
    void fn_8000CD80(void);
    void fn_8000CF4C(void);
    void fn_8000D5C8(void);
    void fn_80010FF0(void);
    void fn_800142E4(void);
    void fn_80014790(void);
    void fn_80014EA8(void);
    void fn_80025970(void);
    void fn_80025BA0(void);
    void fn_8005AE78(void);
    void fn_8005BCF0(void);
    void fn_80066124(s32);
    void fn_800675E8(s32);
    void fn_80067DA4(s32);
    void fn_80067EDC(s32);
    void fn_8006E568(s32);
    void fn_8006E660(void);
    void fn_8006E748(void);
    void fn_80078DF8(void);
    void fn_800895B8(void);
    void fn_8009B738(s32, s32);
    void fn_8009B900(s32, s32);
    void fn_8009CF28(void);
    void fn_8009D0E8(s32, s32);
    void fn_8009D95C(s32, s32);
    void fn_8009E588(void);
    void fn_8009E5B4(void);
    void fn_8009E5F8(void);
    void fn_8009E6B4(void);
    void fn_8009E6F0(void);
    void fn_8009E71C(void);
    void fn_8009E774(void);
    void fn_8009E7A0(void);
    void fn_8009E7DC(void);
    void fn_8009E808(void);
    void fn_8009E844(void);
    void fn_8009E9A0(void);
    void fn_8009E9D0(void);
    void fn_8014702C(s32);
    void fn_801C9460(void);
    void fn_801ED52C(s32);
    void fn_801FBC48(void);
    void fn_802052E8(void);
    s32 fn_80209FD4(void);
    void fn_8020A558(void *, void *, s32, void *, s32, s32, s32);
    void fn_8020A9E0(void *);
    void fn_80224658(s32);
    void fn_80234450(void *, void *);
    void fn_8023A504(s32, s32, void *);
    extern u8 lbl_802AEE40[];
    extern char lbl_80268000[];
    extern s32 lbl_803671B4;
    extern u8 lbl_803671B8;
    extern u8 lbl_803671B0;
    extern s32 lbl_803682A4;
    extern u8 lbl_80367700;
    extern u8 lbl_80367701;
    extern u8 lbl_80367702;
    extern u8 lbl_80367704;
    extern u8 lbl_80367705;
    extern u8 lbl_80367706;
    extern f32 lbl_80368C4C;
    extern f32 lbl_80368C64;
    extern f32 lbl_80368C70;
    extern f32 lbl_80368C74;

    s32 sp8;
    s32 tmp;
    u8 *stack;
    u8 *base = lbl_802AEE40;

    lbl_803671B4 = fn_80209FD4();
    fn_802052E8();
    fn_80025BA0();
    fn_801C9460();
    fn_8006E568(5);
    fn_801FBC48();
    stack = base + 0x1698;
    fn_8020A558(base + 0x1380, fn_80014790, 0, (u8 *)((u32)stack + 0x1000), 0x1000, 0x10, 1);
    fn_8020A9E0(base + 0x1380);
    fn_8000D5C8();
    fn_8005BCF0();
    fn_80006314();
    fn_80005A84(0, 0x800);
    fn_800059FC(0x10, 0x20, 0x240, 0x1A0, 0x10);
    fn_800059B4();
    base[0x1320] = 0;
    fn_80234450(base + 0x1360, lbl_80268000);
    fn_800056CC(lbl_80268000 + 7,
                *(s8 *)0x80000000, *(s8 *)0x80000001, *(s8 *)0x80000002,
                *(s8 *)0x80000003, *(s8 *)0x80000004, *(s8 *)0x80000005);
    fn_8023A504(0, 2, &sp8);
    OSGetTick();
    fn_8000CF4C();
    OSGetTick();
    fn_8000CD80();
    fn_8000CC88();
    fn_800142E4();
    fn_80078DF8();
    fn_800895B8();
    fn_80005C18();
    fn_8000A2A8(0);
    fn_8000A284(lbl_80368C64, lbl_80368C70, lbl_80368C74, lbl_80368C4C);
    fn_80010FF0();
    fn_8000A280();
    lbl_803671B8 = 0;
    fn_8014702C(0);
    stack = base + 0x318;
    fn_8020A558(base + 0, fn_80014EA8, 0, (u8 *)((u32)stack + 0x1000), 0x1000, 0x10, 1);
    fn_8020A9E0(base + 0);
    OS_YieldThread();
    fn_801ED52C(0);
    fn_80005C60();
    fn_80008B94();
    for (;;) {
        while (lbl_803671B0) {
            OS_YieldThread();
        }
        tmp = lbl_803682A4;
        if (tmp & 2) {
            lbl_803682A4 = tmp & ~2;
            fn_80066124(0);
        } else {
            fn_8009E9D0();
            fn_8006E748();
            fn_8000C194(5);
            fn_80224658(0);
            fn_8009E7DC();
            fn_800675E8(0);
            fn_8009E7A0();
            if (lbl_80367701) {
                fn_8009D95C(0x10, 0x188);
            }
            if (lbl_80367702) {
                fn_8009D0E8(0x160, 0x10);
            }
            if (lbl_80367704) {
                fn_8009CF28();
            }
            if (lbl_80367705) {
                fn_8009B900(0x100, 0x10);
            }
            if (lbl_80367700) {
                fn_8000A860(0x10, 0x10, 0xC);
            }
            if (lbl_80367706) {
                fn_8009B738(0xB8, 0x188);
            }
            fn_8009E5F8();
            fn_80067EDC(0);
            fn_8009E774();
            fn_80007B04();
            fn_8009E71C();
            fn_80067DA4(0);
            fn_8000C194(6);
            fn_8000C194(7);
            fn_8009E6F0();
            fn_8009E6B4();
            tmp = lbl_803682A4;
            if (tmp & 4) {
                lbl_803682A4 = tmp & ~4;
                lbl_803682A4 = lbl_803682A4 | 2;
            }
        }
        fn_8009E5B4();
        fn_80025970();
        fn_80008B94();
        fn_8009E844();
        fn_8000C194(2);
        fn_8000C194(3);
        fn_8000C194(4);
        fn_8009E808();
        fn_8009E9A0();
        fn_8009E588();
        fn_80224658(1);
        if (!(lbl_803682A4 & 2)) {
            fn_8006E660();
        }
        fn_80006754();
        fn_8005AE78();
    }
}
#pragma pop
