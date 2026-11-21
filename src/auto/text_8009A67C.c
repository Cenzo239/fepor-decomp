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
extern u16 lbl_80289A60[];

extern u8 lbl_80289B00[16];

extern void* fn_800980D4(s32 arg0);
extern void fn_8017E394(void* arg0, void* arg1, void* arg2, s32 arg3);

extern u8 lbl_80289EB8[16];

extern f32 lbl_803697E0;
extern const f32 lbl_803697E4;

#pragma scheduling reset

#pragma scheduling off
#pragma global_optimizer off

#pragma scheduling off
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma scheduling on

void fn_8009A67C(void *arg0) {
    f32 Math_Lerp(f32, f32, f32, f32);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern f32 lbl_803697E8;
    extern const f64 lbl_803697F0;
    u8 t;
    f32 start, end;

    (void)lbl_803697F0;
    t = *(u8 *)((u8 *)arg0 + 0x3e);
    if (t != 0) {
        *(u8 *)((u8 *)arg0 + 0x3e) = (u8)(t - 1);
    }
    *(s8 *)((u8 *)arg0 + 0x3d) = (s8)Math_Lerp(
        lbl_803697E4,
        (f32)(u32)*(u8 *)((u8 *)arg0 + 0x3f),
        (f32)(u32)*(u8 *)((u8 *)arg0 + 0x40),
        (f32)(u32)*(u8 *)((u8 *)arg0 + 0x3e));
    start = lbl_803697E8;
    end = lbl_803697E4;
    *(f32 *)((u8 *)arg0 + 0x30) = Math_EaseOutPow(
        2, start, end,
        (f32)(u32)*(u8 *)((u8 *)arg0 + 0x40),
        (f32)(u32)*(u8 *)((u8 *)arg0 + 0x3e));
    if (*(u8 *)((u8 *)arg0 + 0x3e) == 0) {
        Process_ClearFunc(arg0);
    }
}

#pragma global_optimizer off
