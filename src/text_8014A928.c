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
#pragma opt_strength_reduction off

extern s32 lbl_80367B00;
extern u8 lbl_80367B0D;

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

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

#include "common.h"
extern f32 lbl_8036A7F0;
extern M2C_UNK gBattleMap;
extern s32 lbl_80367B00;
extern s32 lbl_80367B04;
extern u8 lbl_80367B0D;

void Ui_PlaySeCue(s32, s32); /* extern */
#include "global.h"

extern void* fn_80019F04();
#include "common.h"
extern u8 gUnitLists[];
extern u8 gUnits[];
#include "common.h"
#include "ef.h"
#include "global.h"

extern u8 gBattleState[];
extern u8 lbl_80277060[];
extern u8 gMapObjEventList[];
#include "global.h"
extern u8 gBattleState[];

s32 fn_8014A928(s32 unused0, s32 unused1, void *arg2) {
    if ((s8)lbl_80367B08 == 0) {
        lbl_80367B09 = lbl_80367B0D;
        lbl_80367B0B = *(u8 *)((u8 *)arg2 + 0x3A);
    } else {
        lbl_80367B0A = lbl_80367B0D;
        lbl_80367B0C = *(u8 *)((u8 *)arg2 + 0x3A);
    }
    return 9;
}

s32 fn_8014A960(void) {
    return 0;
}

s32 fn_8014A968(s32 unused, void *arg1) {
    s32 a = (s8)lbl_80367B0D;
    s32 b = *(u8 *)((u8 *)arg1 + 0x3A);
    return ((s32 *)lbl_80367B00)[a * 0x18 + b];
}

s32 fn_8014A98C(s32 arg0, s32 arg1, void *arg2)
{
    u8 *Hash_Lookup(s32);
    s8 fn_80146BE4(s32);
    void Ui_PlaySeCue(s32, s32);

    s32 index;
    s32 entry;

    index = *(u8 *)((u8 *)arg2 + 0x3A) + (s8)lbl_80367B0D * 0x18;

    if (index >= lbl_80367B04) {
        return 0;
    }

    entry = ((s32 *)lbl_80367B00)[index];

    if (!(Hash_Lookup(entry)[5] & 4) || (fn_80146BE4(entry) < 0)) {
        Ui_PlaySeCue(entry, 0x64);
    }

    return 0;
}

#pragma cplusplus on
extern "C" s32 fn_8014AA18(void *arg0, void *arg1, void *arg2) {
    void *Hash_Lookup(s32);
    void Ui_CreateMenu(void *, void *, s32);
    extern s32 lbl_80367B10;
    extern void *lbl_80367B14;
    extern u8 lbl_80367B34;
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9(void *, void *) = 0;
    };
    s32 index;
    s32 entry;

    index = *(u8 *)((u8 *)arg2 + 0x3A) + (s8)lbl_80367B0D * 0x18;
    lbl_80367B10 = index;
    if (index >= lbl_80367B04) {
        return 0;
    }
    entry = ((s32 *)lbl_80367B00)[index];
    lbl_80367B14 = Hash_Lookup(entry);
    ((Obj *)arg0)->v9(arg1, arg2);
    Ui_CreateMenu(&lbl_80367B34, arg1, 0);
    return 0;
}

extern "C" void fn_8014AAC8(void *unused,u8 *parent,u8 *item){
struct Model {u8 pad[4]; virtual void v0()=0;virtual void v1()=0;virtual void v2()=0;virtual void v3()=0;virtual void v4()=0;virtual void v5()=0;virtual void v6()=0;virtual void v7()=0;virtual void v8()=0;virtual void v9()=0;virtual void v10()=0;virtual void v11()=0;virtual void v12()=0;virtual void v13()=0;virtual void v14()=0;virtual void v15()=0;virtual void v16()=0;virtual void v17()=0;virtual void v18()=0;virtual void v19()=0;virtual void v20()=0;virtual void v21()=0;virtual void v22()=0;virtual void v23()=0;virtual void v24()=0; virtual f32 v25()=0;};
struct Drawer {virtual void v0()=0;virtual void v1()=0;virtual void v2()=0;virtual void v3()=0;virtual void *v4(void*)=0;};
u8 *Hash_Lookup(s32);
void Prim2D_Begin(void);
void Prim2D_SetTransform(f32,f32,f32,f32);
void Prim2D_SetTex(s32,s32);
void Prim2D_PrepareTex(void);
void Prim2D_AddPrim(s32);
void Prim2D_SetPos(f32,f32);
void Prim2D_SetText(void*);
void Prim2D_SetScale(f32);
void Prim2D_SetTint(s32,s32,s32,s32);
void Prim2D_EndPrim(void);
extern f32 gMenuItemZBias,gOneF,gMenuTextScale;
s32 index;
s32 page=(s8)lbl_80367B0D;
index=item[0x3a];
index+=page*24;
if(index<lbl_80367B04){
if(Hash_Lookup(((s32*)lbl_80367B00)[index])[5]&8)item[0x39]=2;else item[0x39]=0;
}
Prim2D_Begin();
Prim2D_SetTransform((f32)*(s16*)(parent+0x30),(f32)*(s16*)(parent+0x32),(*(Model**)(parent+0x3c))->v25()-gMenuItemZBias,gOneF);
Prim2D_SetTex(0,0x13);Prim2D_PrepareTex();Prim2D_AddPrim(5);
Prim2D_SetPos((f32)*(s16*)(item+0x30),(f32)*(s16*)(item+0x32));
Prim2D_SetText((*(Drawer**)(item+0x34))->v4(item));
Prim2D_SetScale(gMenuTextScale);
if(item[0x38])Prim2D_SetTint(255,255,0,255);
if(item[0x39]==2)Prim2D_SetTint(0,0,0,255);
Prim2D_EndPrim();
}

#pragma cplusplus reset
