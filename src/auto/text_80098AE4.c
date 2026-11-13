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
extern f32 lbl_803697E4;

#pragma scheduling reset

void fn_80098AE4(void *arg0) {
    void fn_8004B1B4(s32);
    void fn_8009799C(void);
    void fn_8004FE98(s32, s32);
    void fn_8005376C(void);
    void fn_800980D4(s32);
    s32 fn_800980E8(s32);
    u8 fn_80098568(void);
    s32 i;
    s32 temp;

    fn_8005376C();
    if (*(u8 *)((char *)arg0 + 0x40) == 0) {
        fn_8009799C();
        for (i = 0; i < 3; i++) {
            temp = fn_800980E8(i);
            if (temp != 0) {
                fn_800980D4(i);
                if (fn_80098568() != 0) {
                    fn_8004B1B4(temp);
                } else {
                    fn_8004FE98(temp, 0);
                }
            }
        }
    }
}

