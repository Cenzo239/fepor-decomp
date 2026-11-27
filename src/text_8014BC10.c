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

#pragma push
#pragma opt_lifetimes off
u8 fn_8014BC10(void *arg0) {
    void *fn_80019F04(u8);
    void Allegiance_FillMask(s32, void *);
    extern u8 gUnitLists[];
    extern u8 gUnits[];
    register s32 score asm("r31");
    register u32 self asm("r30");
    s32 n;
    void *tbl;
    void *p;
    void *unit;
    s32 g1;
    s32 g2;
    s32 g3;
    u32 i;
    u8 flags[4];
    s16 val;
    u8 id;

    score = 0;
    self = (u32)arg0;
    id = *(u8 *)(self + 0x10);
    if (id < 0x5A) {
        return 0x2D;
    }
    if (id < 0x5A) {
        g1 = 0x2D;
    } else {
        tbl = fn_80019F04(id);
        val = *(s16 *)(self + 0x12);
        g1 = 0x45;
        if (val <= *(u8 *)((u8 *)tbl + 0x57)) {
            g1 = 0x44;
            if (val <= *(u8 *)((u8 *)tbl + 0x56)) {
                g1 = 0x43;
                if (val <= *(u8 *)((u8 *)tbl + 0x55)) {
                    g1 = 0x42;
                    if (val <= *(u8 *)((u8 *)tbl + 0x54)) {
                        g1 = 0x41;
                    }
                }
            }
        }
    }
    score = 0x45 - (u8)g1;
    id = *(u8 *)(self + 0x10);
    if (id < 0x5A) {
        g2 = 0x2D;
    } else {
        n = 0;
        p = *(void **)(gUnitLists + 0x48);
        while (p != NULL) {
            u32 flags1a0 = *(u32 *)((u8 *)p + 0x1A0);
            p = *(void **)((u8 *)p + 0x184);
            if (flags1a0 & 0x8000) {
                n += 1;
            }
        }
        tbl = fn_80019F04(id);
        g2 = 0x45;
        if (n <= *(u8 *)((u8 *)tbl + 0x5B)) {
            g2 = 0x44;
            if (n <= *(u8 *)((u8 *)tbl + 0x5A)) {
                g2 = 0x43;
                if (n <= *(u8 *)((u8 *)tbl + 0x59)) {
                    g2 = 0x42;
                    if (n <= *(u8 *)((u8 *)tbl + 0x58)) {
                        g2 = 0x41;
                    }
                }
            }
        }
    }
    score += 0x45 - (u8)g2;
    id = *(u8 *)(self + 0x10);
    if (id < 0x5A) {
        g3 = 0x2D;
    } else {
        u8 *base;
        u8 *flagp;
        s32 ctr;
        n = 0;
        Allegiance_FillMask(4, flags);
        base = gUnits;
        flagp = flags;
        for (i=1;i<160;i++) {
            if ((u8)i != 0) {
                unit = base + ((u8)i - 1) * 0x280;
            } else {
                unit = NULL;
            }
            if (*(u32 *)((u8 *)unit + 0x188) != 0 &&
                flagp[*(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)] != 0) {
                n += *(u16 *)((u8 *)unit + 0x22C);
            }
        }
        tbl = fn_80019F04(*(u8 *)(self + 0x10));
        g3 = 0x45;
        if (n >= *(u8 *)((u8 *)tbl + 0x5F)) {
            g3 = 0x44;
            if (n >= *(u8 *)((u8 *)tbl + 0x5E)) {
                g3 = 0x43;
                if (n >= *(u8 *)((u8 *)tbl + 0x5D)) {
                    g3 = 0x42;
                    if (n >= *(u8 *)((u8 *)tbl + 0x5C)) {
                        g3 = 0x41;
                    }
                }
            }
        }
    }
    score += 0x45 - (u8)g3;
    return (u8)(0x45 - score / 3);
}
#pragma pop
s32 fn_8014BEE0(u8 *self) {
void Allegiance_FillMask(s32,u8*);
u8 mask[4];
s32 total,i,grade;
u8 *unit,*table;
if(self[0x10]<0x5a)return 0x2d;
total=0;
Allegiance_FillMask(4,mask);
for(i=1;i<160;i++){
u8 id=(u8)i;
unit=id?gUnits+(id-1)*0x280:0;
if(*(void**)(unit+0x188)&&mask[(*(u8**)(unit+0x190))[8]])total+=*(u16*)(unit+0x22c);
}
table=fn_80019F04(self[0x10]);
grade=0x45;
if(total>=table[0x5f]){grade=0x44;
if(total>=table[0x5e]){grade=0x43;
if(total>=table[0x5d]){grade=0x42;
if(total>=table[0x5c])grade=0x41;
}}}
return grade;
}

unsigned int fn_8014C078(void *arg0) {
    void *fn_80019F04(u8);
    extern u8 gUnitLists[];
    u8 id;
    s32 n;
    void *p;
    void *tbl;
    s32 grade;

    id = *(u8 *)((u8 *)arg0 + 0x10);
    if (id < 0x5A) {
        return 0x2D;
    }
    n = 0;
    p = *(void **)(gUnitLists + 0x48);
    while (p != NULL) {
        u32 flags1a0 = *(u32 *)((u8 *)p + 0x1A0);
        p = *(void **)((u8 *)p + 0x184);
        if (flags1a0 & 0x8000) {
            n += 1;
        }
    }
    tbl = fn_80019F04(id);
    grade = 0x45;
    if (n <= *(u8 *)((u8 *)tbl + 0x5B)) {
        grade = 0x44;
        if (n <= *(u8 *)((u8 *)tbl + 0x5A)) {
            grade = 0x43;
            if (n <= *(u8 *)((u8 *)tbl + 0x59)) {
                grade = 0x42;
                if (n <= *(u8 *)((u8 *)tbl + 0x58)) {
                    grade = 0x41;
                }
            }
        }
    }
    return grade;
}

unsigned int fn_8014C12C(void *arg0)
{
  void *fn_80019F04(u8);
  u8 id;
  u8 *table;
  s16 value;
  s32 grade;
  id = *((u8 *) (((u8 *) arg0) + 0x10));
  if (id < 0x5A)
  {
    return 0x2D;
  }
  table = (u8 *) fn_80019F04(id);
  value = *((s16 *) (((u8 *) arg0) + 0x12));
  grade = 0x45;
  if (value <= table[0x57])
  {
    grade = 0x44;
    if (value <= table[0x56])
    {
      grade = 0x43;
      if (value <= table[0x55])
      {
        grade = 0x42;
        if (value <= table[0x54])
        {
          grade = 0x41;
        }
      }
    }
  }
  return grade;
}

void fn_8014C1B8(void *state, void *stream) {
    void Stream_Read(void *, s32, void *);
    u8 Stream_ReadU8(void *);
    u16 Stream_ReadU16(void *);
    s32 fn_8017A950(void *);
    s64 fn_8017A860(void *);
    void fn_80105A04(void *, void *);
    void fn_80014F30(void *, void *);
    void fn_80199A60(void *, void *);
    void fn_800BDA9C(void *, void *);
    s32 i;

    Stream_Read(stream, 0x10, state);
    *(u8 *)((u8 *)state + 0x10) = Stream_ReadU8(stream);
    *(u8 *)((u8 *)state + 0x51E) = *(u8 *)((u8 *)state + 0x10);
    *(u8 *)((u8 *)state + 0x11) = Stream_ReadU8(stream);
    *(u16 *)((u8 *)state + 0x12) = Stream_ReadU16(stream);
    for (i = 0; i < 4; i++) {
        *(u8 *)((u8 *)state + 0x14 + i) = Stream_ReadU8(stream);
    }
    *(s32 *)((u8 *)state + 0x18) = fn_8017A950(stream);
    *(s32 *)((u8 *)state + 0x1C) = fn_8017A950(stream);
    Stream_Read(stream, 0x30, (u8 *)state + 0x20);
    *(u8 *)((u8 *)state + 0x50) = Stream_ReadU8(stream);
    *(u8 *)((u8 *)state + 0x51) = Stream_ReadU8(stream);
    *(u8 *)((u8 *)state + 0x52) = Stream_ReadU8(stream);
    *(u8 *)((u8 *)state + 0x53) = Stream_ReadU8(stream);
    *(u8 *)((u8 *)state + 0x54) = Stream_ReadU8(stream);
    *(u8 *)((u8 *)state + 0x55) = Stream_ReadU8(stream);
    *(u8 *)((u8 *)state + 0x56) = Stream_ReadU8(stream);
    *(u8 *)((u8 *)state + 0x57) = Stream_ReadU8(stream);
    *(s64 *)((u8 *)state + 0x58) = fn_8017A860(stream);
    *(s64 *)((u8 *)state + 0x60) = fn_8017A860(stream);
    *(s32 *)((u8 *)state + 0x68) = fn_8017A950(stream);
    *(s32 *)((u8 *)state + 0x6C) = fn_8017A950(stream);
    *(u16 *)((u8 *)state + 0x70) = Stream_ReadU16(stream);
    *(u16 *)((u8 *)state + 0x72) = Stream_ReadU16(stream);
    fn_80105A04((u8 *)state + 0x74, stream);
    fn_80105A04((u8 *)state + 0x84, stream);
    fn_80014F30((u8 *)state + 0x94, stream);
    fn_80014F30((u8 *)state + 0x98, stream);
    fn_80199A60((u8 *)state + 0x9C, stream);
    fn_800BDA9C((u8 *)state + 0xB4, stream);
    Stream_Read(stream, 0x140, (u8 *)state + 0x3C4);
    Stream_Read(stream, 0x18, (u8 *)state + 0x504);
    *(s32 *)((u8 *)stream + 4) = *(s32 *)((u8 *)stream + 4) + 8;
}

