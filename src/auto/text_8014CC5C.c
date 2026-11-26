/* Functions from 0x8014A370 to 0x8014E350, found by decomp-toolkit. */
#include "common.h"

extern s32 lbl_80367B00;
extern s32 lbl_80367B04;
extern u8 lbl_80367B0E;
extern u8 lbl_80367B44;

typedef struct { u8 a; u8 b; } Entry;
typedef struct { u8 pad[0x544]; s8 count; Entry entries[256]; } Obj;
extern u8 lbl_80367B08;
extern u8 lbl_80367B09;
extern u8 lbl_80367B0A;
extern u8 lbl_80367B0B;
extern u16 lbl_80292F60[];
extern f32 lbl_8036A7D0;
extern f32 lbl_8036A7D4;
extern f32 lbl_8036A7D8;
extern f32 lbl_8036A7DC;
extern f32 lbl_8036A7E0;
extern f64 lbl_8036A7E8;
extern u8 lbl_80367B0C;
extern u8 lbl_80367B0D;

void Heap_FreeRaw(s32);
s32 Heap_AllocRaw(s32);
void *Archive_Load(void *);
void Ui_CreateMenu(void *, s32, s32);

extern s32 lbl_80367B00;
extern u8 lbl_80367B0D;

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma cplusplus on

#pragma cplusplus off

extern u16 *g_AccessoryArray;

void Stream_Write(void *, s32, void *);
void Stream_WriteU8(void *, u8);
void Stream_WriteS32(void *, s32);
void Stream_WriteU16(void *, u16);
void Stream_WriteS64(void *, s32, s32);
void fn_80105A30(void *, void *);
void fn_80014F94(void *, void *);
void fn_80199B88(void *, void *);
void fn_800BDAF8(void *, void *);
void Stream_WriteStr(void *, s32, void *);
void Stream_WritePad(void *, s32, u8);
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
extern u16 lbl_80367B68;

void strcpy(s32, u32);

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern u16 lbl_80367B14;
extern u16 lbl_80367B14;
#include "common.h"
extern f32 lbl_8036A7F0;
extern u8 gBattleMap[];
extern s32 lbl_80367B00;
extern s32 lbl_80367B04;
extern u8 lbl_80367B0D;

void Ui_PlaySeCue(s32, s32); /* extern */
#include "global.h"

extern void* fn_80019F04();
#include "common.h"
extern u16 gUnitLists[50];
extern u16 gUnits[];
#include "common.h"
#include "ef.h"
#include "global.h"

extern u8 gBattleState[];
extern u8 lbl_80277060[];
extern u8 gMapObjEventList[];
#include "global.h"
extern u8 gBattleState[];

#pragma push
#pragma optimization_level 3
s8 fn_8014CC5C(Obj *arg0, s32 arg1) {
s32 fn_80106DC8(s32,void*);
u8 buffer[128];
s32 count,i;
count=fn_80106DC8(arg1,buffer);
for(i=0;i<count;i++){
u8 b=buffer[2*i+1];
u8 a=buffer[2*i];
arg0->entries[(s8)((u8*)arg0)[0x544]].a=a;
arg0->entries[(s8)((u8*)arg0)[0x544]].b=b;
((u8*)arg0)[0x544]++;
}
return count;
}
#pragma pop
