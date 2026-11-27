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

s32 Unit_FindEmptyHeldSlot(s32 arg0) {
    u32 *Unit_GetHeldItemSlot(s32, s32);
    s32 i;

    for (i = 0; i < 4; i++) {
        if (*Unit_GetHeldItemSlot(arg0, i) == 0) {
            return i;
        }
    }
    return -1;
}

void fn_80095678(void) {
    void Process_UnlinkByKey(void *);
    extern u8 lbl_80289B00[16];
    Process_UnlinkByKey(lbl_80289B00);
}

void fn_800956A0(s32 arg0) {
    void Process_Create(void *, s32);
    extern u8 lbl_8036728B;
    extern u8 lbl_80289B00[16];
    if (!(lbl_8036728B & 2)) {
        Process_Create(lbl_80289B00, arg0);
    }
}

#pragma optimization_level 3
void fn_800956D8(u8 *arg0) {
 void *Camera_GetActive(void);
 void fn_80019384(void *,s32);
 void BattleState_SetCamPos(void *,f32,f32);
 void EventLock_Inc(void);
 extern u8 gBattle[],gEventSlots[];
 extern f32 lbl_803697B8,lbl_803697BC,lbl_803697C0;
 u8 *cam; s32 i; f32 x,y; f32 minimum;
 cam=Camera_GetActive(); minimum=40.0f;
 *(f32 *)(arg0+0x30)=*(f32 *)(cam+8);
 *(u32 *)(arg0+0x60)=*(u32 *)(cam+0x20);
 if(*(f32 *)(cam+8)<minimum) *(f32 *)(cam+8)=minimum;
 if(*(s32 *)(gBattle+0xCA8)>=5 && *(s32 *)(cam+0x20)==0) fn_80019384(cam,1);
 if(*(s32 *)(gBattle+0xCA8)>=5) {
 u8 *slot; u8 *unit; s32 count;
 x=0.0f; count=0; y=0.0f;
 for(i=0;i<3;i++) {
 u8 *event=*(u8 **)(gEventSlots+i*20);
 if(event) unit=*(u8 **)(event+0x280); else unit=0;
 if(unit) {count++;x+=(f32)(s8)unit[0x19E];y+=(f32)(s8)unit[0x19F];}
 }
 if(count>0) {x/=(f32)count;y/=(f32)count;BattleState_SetCamPos(gBattleState,x,y);}
 }
 *(f32 *)(cam+0x70)=lbl_803697C0;
 EventLock_Inc();
}
#pragma optimization_level reset
