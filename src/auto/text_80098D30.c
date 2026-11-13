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

typedef struct {
    s32 x, y, z;
} Word3;

static void *get_280(void **handle) {
    void *t;

    t = *handle;
    if (t != NULL) {
        return *(void **)((u8 *)t + 0x280);
    }
    return NULL;
}

void fn_80098D30(void *arg0) {
    s32 temp_r31;
    s32 temp_r30;

    fn_80055204(**((s32 ***)arg0 + 0xE), 0);
    Res_GetByName();
    temp_r31 = fn_80098140();
    temp_r30 = fn_80098110();
    fn_8018CAD8(0x32, 0x1E, arg0);
    fn_8018CA68(temp_r31);
    fn_8018CA68(temp_r30);
}

void fn_80098DA4(void) {
    void fn_8009799C(void);
    void fn_800980D4(s32);
    s32 Event_GetSlotUnit(s32);
    u8 fn_80098568(void);
    void Mu_StartBlend(s32, s32, s32, s32);
    s32 i;
    s32 temp;

    fn_8009799C();
    for (i = 0; i < 3; i++) {
        temp = Event_GetSlotUnit(i);
        if (temp != 0) {
            fn_800980D4(i);
            if (fn_80098568() == 0) {
                Mu_StartBlend(temp, 0, 0x18, 0);
            }
        }
    }
}

void fn_80098E1C(s32 arg0) {
    s32 Event_GetSlotUnit(s32);
    void fn_80050BF4(s32, s32);
    void fn_800980D4(s32);
    u8 fn_80098568(void);
    void fn_80183B24(s32, s32);

    s32 var_r31;
    s32 temp_r3;

    var_r31 = 0;
    do {
        temp_r3 = Event_GetSlotUnit(var_r31);
        if (temp_r3 != 0) {
            fn_80050BF4(temp_r3, 0);
            fn_800980D4(var_r31);
            if (fn_80098568() != 0) {
                fn_80183B24(temp_r3, arg0);
            }
        }
        var_r31 += 1;
    } while (var_r31 < 3);
}

void fn_80099094(void *arg0)
{
  void Event_AdvanceCmd(s16);
  s32 Event_GetCmdKind(s16);
  s32 Event_GetCmdFlags(s16);
  void *fn_80095934(void *, s32, s32);
  void *Effect_Create(void *, void *);
  void fn_800536CC(void *, void *);
  void fn_800536D8(void *, void *);
  s32 new_var;
  void fn_8005306C(void *);
  void fn_80184688(void *, s32, s32, void *);
  void fn_800983E0(void *, void *);
  void SeCue_PlayAtPos(void *, void *, s32);
  void fn_80025624(s32, s32);
  void fn_8017F70C(void *, void *);
  void FloatAnim_Start(void *, s32, void *);
  void fn_8017F040(void *, s32, void *);
  void Mu_StartBlend(void *, s32, s32, s32);
  void fn_80184BE8(void *, s32, s32, s32);
  void fn_8018CFA4(s32, s32, s32, s32, void *);
  void Effect_SetPos(void *, f32, f32, f32);
  extern u8 gEventUiSeCues[];
  extern s32 gPadInput;
  s32 sp38[3];
  s32 sp2C[3];
  s32 sp20[3];
  s32 sp14[3];
  s32 sp8[3];
  void *self;
  s16 temp_r29;
  void *temp_r29_2;
  void *temp_r3;
  void *var_r0;
  s32 temp_r30;
  self = arg0;
  temp_r29 = *((s16 *) (((u8 *) self) + 0x46));
  Event_AdvanceCmd(temp_r29);
  temp_r30 = (s32) (*((f32 *) (((u8 *) (*((void **) (((u8 *) self) + 0x38)))) + 0xC)));
  if (temp_r30 == 0)
  {
    temp_r30 = Event_GetCmdKind(temp_r29);
    new_var = temp_r30;
    temp_r3 = fn_80095934(*((void **) (((u8 *) self) + 0x38)), new_var, Event_GetCmdFlags(temp_r29));
    if (temp_r3 != NULL)
    {
      temp_r29_2 = Effect_Create(temp_r3, self);
      fn_800536CC(temp_r29_2, *((void **) (*((void **) (((u8 *) self) + 0x38)))));
      fn_800536D8(temp_r29_2, *((void **) (*((void **) (((u8 *) self) + 0x3C)))));
      fn_8005306C(temp_r29_2);
    }
    fn_80184688(get_280((void **) (*((void **) (((u8 *) self) + 0x3C)))), 1, 2, self);
    fn_800983E0(sp14, *((void **) (((u8 *) self) + 0x3C)));
    sp8[0] = sp14[0];
    sp8[1] = sp14[1];
    sp8[2] = sp14[2];
    SeCue_PlayAtPos(gEventUiSeCues + 0xE3, sp8, 0x64);
    fn_80025624(gPadInput, 4);
    if ((*((u8 *) (((u8 *) self) + 0x34))) != 2)
    {
      fn_8017F70C(*((void **) (((u8 *) self) + 0x38)), self);
    }
  }
  else
  {
    fn_800983E0(sp2C, *((void **) (((u8 *) self) + 0x38)));
    *((Word3 *) sp20) = *((Word3 *) sp2C);
    *((Word3 *) sp38) = *((Word3 *) sp2C);
    SeCue_PlayAtPos(gEventUiSeCues + 0x104, sp38, 0x64);
    var_r0 = get_280((void **) (*((void **) (((u8 *) self) + 0x38))));
    if (var_r0 != NULL)
    {
      Mu_StartBlend(get_280((void **) (*((void **) (((u8 *) self) + 0x38)))), 9, 2, 0);
      fn_80184BE8(get_280((void **) (*((void **) (((u8 *) self) + 0x38)))), 8, 8, 0);
      fn_80184688(get_280((void **) (*((void **) (((u8 *) self) + 0x38)))), 1, 2, self);
    }
    fn_8018CFA4(0xF, 6, 2, 0, self);
    temp_r3 = Effect_Create(gEventUiSeCues + 0x119, self);
    Effect_SetPos(temp_r3, *((f32 *) (&sp20[0])), *((f32 *) (&sp20[1])), *((f32 *) (&sp20[2])));
    FloatAnim_Start(*((void **) (((u8 *) self) + 0x38)), new_var, self);
    if ((*((u8 *) (((u8 *) self) + 0x34))) != 2)
    {
      fn_8017F040(*((void **) (((u8 *) self) + 0x38)), new_var, self);
    }
    fn_80025624(gPadInput, 8);
  }
}

void fn_8009933C(void *arg0) {
s32 fn_80098140(void); u8 Pad_IsActive(void *); u8 Pad_IsButton(void *,s32);
s32 Event_GetCmdKind(s16); s32 Event_GetCmdFlags(s16); void Event_AdvanceCmd(s16);
void fn_8009A0A4(void *,s16); void *fn_800958C4(s32);
void fn_8017DF54(void *,void *,void *);
void *fn_80095934(void *,s32,s32); void *Effect_Create(void *,void *);
void fn_800536CC(void *,void *); void fn_800536D8(void *,void *); void fn_8005306C(void *);
void fn_80184688(void *,s32,s32,void *); void fn_800983E0(void *,void *);
void SeCue_PlayAtPos(void *,void *,s32); void fn_80025624(void *,s32);
void fn_8017F70C(void *,void *); void FloatAnim_Start(void *,s32,void *); void fn_8017F040(void *,s32,void *);
void Mu_StartBlend(void *,s32,s32,s32); void fn_80184BE8(void *,s32,s32,s32); void fn_8017F474(void *,void *);
s16 fn_80097740(void); void *fn_80098094(void); void *fn_8009809C(void);
u8 fn_8004BF80(void *); void Process_ClearFunc(void *);
extern u8 gEventUiSeCues[]; extern void *gPadInput;
Word3 posC, tmpC, posA, tmpA, posB, tmpB;
void *self=arg0;
u8 *input;
void *unit;
unit=(void *)fn_80098140();
input=(u8 *)unit+0x1c;
if(Pad_IsActive(input)) {
s32 command=Event_GetCmdKind(M2C_FIELD(self,s16 *,0x46));
s32 flags=Event_GetCmdFlags(M2C_FIELD(self,s16 *,0x46));
switch(command) {
case 0x50: case 0x51:
if(Pad_IsButton(input,0)) {
if(M2C_FIELD(self,s8 *,0x41)<=0) fn_8009A0A4(self,M2C_FIELD(self,s16 *,0x46));
else { if(flags&1) {

s32 value;
void *p; s32 amount;
s16 index=M2C_FIELD(self,s16 *,0x46);
value=Event_GetCmdFlags(index);
Event_AdvanceCmd(index);
p=fn_800958C4(value);
if(p) fn_8017DF54(M2C_FIELD(self,void **,0x3c),p,self);
amount=(s32)M2C_FIELD(M2C_FIELD(self,void **,0x3c),f32 *,12);
if(amount==0) {
s32 kind=Event_GetCmdKind(index);
p=fn_80095934(M2C_FIELD(self,void **,0x38),kind,Event_GetCmdFlags(index));
if(p) {
p=Effect_Create(p,self);
fn_800536CC(p,*M2C_FIELD(self,void ***,0x38));
fn_800536D8(p,*M2C_FIELD(self,void ***,0x3c));
fn_8005306C(p);
}
fn_80184688(get_280(M2C_FIELD(self,void ***,0x3c)),1,2,self);
fn_800983E0(&tmpA,M2C_FIELD(self,void **,0x3c));
posA=tmpA;
SeCue_PlayAtPos(gEventUiSeCues+0xe3,&posA,100);
fn_80025624(gPadInput,4);
if(M2C_FIELD(self,u8 *,0x34)!=2) fn_8017F70C(M2C_FIELD(self,void **,0x3c),self);
} else {
fn_8009A0A4(self,index);
FloatAnim_Start(M2C_FIELD(self,void **,0x3c),amount,self);
if(M2C_FIELD(self,u8 *,0x34)!=2) fn_8017F040(M2C_FIELD(self,void **,0x3c),amount,self);
}
amount=(s32)M2C_FIELD(M2C_FIELD(self,void **,0x38),f32 *,12);
if(amount) {
FloatAnim_Start(M2C_FIELD(self,void **,0x38),amount,self);
if(M2C_FIELD(self,u8 *,0x34)!=2) fn_8017F040(M2C_FIELD(self,void **,0x38),amount,self);
fn_80184688(get_280(M2C_FIELD(self,void ***,0x38)),1,32,self);
}
} else {
s32 value;
void *p; s32 amount;
s16 index=M2C_FIELD(self,s16 *,0x46);
value=Event_GetCmdFlags(index);
Event_AdvanceCmd(index);
p=fn_800958C4(value);
if(p) fn_8017DF54(M2C_FIELD(self,void **,0x3c),p,self);
amount=(s32)M2C_FIELD(M2C_FIELD(self,void **,0x3c),f32 *,12);
if(amount==0) {
s32 kind=Event_GetCmdKind(index);
p=fn_80095934(M2C_FIELD(self,void **,0x38),kind,Event_GetCmdFlags(index));
if(p) {
p=Effect_Create(p,self);
fn_800536CC(p,*M2C_FIELD(self,void ***,0x38));
fn_800536D8(p,*M2C_FIELD(self,void ***,0x3c));
fn_8005306C(p);
}
fn_80184688(get_280(M2C_FIELD(self,void ***,0x3c)),1,2,self);
fn_800983E0(&tmpB,M2C_FIELD(self,void **,0x3c));
posB=tmpB;
SeCue_PlayAtPos(gEventUiSeCues+0xe3,&posB,100);
fn_80025624(gPadInput,4);
if(M2C_FIELD(self,u8 *,0x34)!=2) fn_8017F70C(M2C_FIELD(self,void **,0x3c),self);
} else {
fn_8009A0A4(self,index);
FloatAnim_Start(M2C_FIELD(self,void **,0x3c),amount,self);
if(M2C_FIELD(self,u8 *,0x34)!=2) fn_8017F040(M2C_FIELD(self,void **,0x3c),amount,self);
}}
M2C_FIELD(self,u8 *,0x41)--;
}
}
break;
case 0x52:
if(Pad_IsButton(input,1)) {
Event_AdvanceCmd(M2C_FIELD(self,s16 *,0x46));
if(M2C_FIELD(self,u8 *,0x34)!=1) {
Mu_StartBlend(get_280(M2C_FIELD(self,void ***,0x3c)),7,2,0);
fn_80184BE8(get_280(M2C_FIELD(self,void ***,0x3c)),8,8,0);
}
if(M2C_FIELD(self,u8 *,0x34)!=2) fn_8017F474(M2C_FIELD(self,void **,0x3c),self);
fn_800983E0(&tmpC,M2C_FIELD(self,void **,0x3c));
posC=tmpC; SeCue_PlayAtPos(gEventUiSeCues+0xf6,&posC,100);
M2C_FIELD(self,u8 *,0x41)--;
} break;
}
{u8 advance;
if(input) {
s8 old=M2C_FIELD(self,s8 *,0x43);
if(Pad_IsButton(input,1)) M2C_FIELD(self,u8 *,0x43)--;
if(Pad_IsButton(input,0)) M2C_FIELD(self,u8 *,0x43)++;
if(old!=M2C_FIELD(self,s8 *,0x43) && M2C_FIELD(self,s8 *,0x43)==0 && M2C_FIELD(self,s8 *,0x41)>0) advance=1; else goto noAdvance;
} else if(M2C_FIELD(self,s8 *,0x41)>0) advance=1; else {noAdvance: advance=0;}
if(advance) {
M2C_FIELD(self,s16 *,0x46)=fn_80097740();
M2C_FIELD(self,void **,0x38)=fn_80098094();
M2C_FIELD(self,void **,0x3c)=fn_8009809C();
M2C_FIELD(self,u8 *,0x43)=0;
}
}
}
if(fn_8004BF80(unit)) {Mu_StartBlend(unit,8,4,0); Process_ClearFunc(self);}
}

void fn_8009991C(void *arg0) {
    s32 fn_80098140(void);
    void *fn_800984FC(void **);
    s32 fn_8001B9F4(void);
    void fn_80184578(s32, s32 *, void *);
    void Mu_StartBlend(s32, s32, s32, s32);

    s32 unit;
    s32 sp8;

    unit = fn_80098140();
    if (fn_800984FC(*(void ***)((u8 *)arg0 + 0x38)) != NULL) {
        sp8 = fn_8001B9F4();
        fn_80184578(unit, &sp8, arg0);
    }
    Mu_StartBlend(unit, *(s16 *)((u8 *)arg0 + 0x44), 8, 0);
}

void fn_80099994(void *arg0) {
    void fn_8004FC70(s32);
    u8 fn_800504FC(s32, s32);
    u8 fn_80096C78(s16);
    s32 Event_GetCmdFlags(s16);
    s32 fn_80098140(void);
    s32 fn_80096D64(void);
    void fn_800056A0(s32);
    void Process_Goto(void *, s32);
    s32 temp_r29;
    s32 temp_r30;
    s32 temp_r3_2;
    u8 temp_r3;
    s32 temp_r4;

    temp_r29 = fn_80098140();
    temp_r30 = Event_GetCmdFlags(M2C_FIELD(arg0, s16 *, 0x46));
    temp_r3 = fn_80096C78(M2C_FIELD(arg0, s16 *, 0x46));
    M2C_FIELD(arg0, s16 *, 0x44) = -1;
    if ((temp_r30 & 0xFFC00000) && (fn_800504FC(temp_r29, 4) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x44) = 4;
    } else {
        temp_r3_2 = fn_80096D64();
        switch (temp_r3_2) {
        case 0:
        case 3:
            if ((temp_r3 != 0) && (fn_800504FC(temp_r29, 3) != 0)) {
                M2C_FIELD(arg0, s16 *, 0x44) = 3;
            } else {
                M2C_FIELD(arg0, s16 *, 0x44) = 2;
            }
            break;
        case 1:
        case 2:
            if ((temp_r3 != 0) && (fn_800504FC(temp_r29, 0xD) != 0)) {
                M2C_FIELD(arg0, s16 *, 0x44) = 0xD;
            } else {
                M2C_FIELD(arg0, s16 *, 0x44) = 0xC;
            }
            break;
        }
    }
    temp_r4 = M2C_FIELD(arg0, s16 *, 0x44);
    if ((s16)temp_r4 < 0) {
        fn_800056A0(0);
        Process_Goto(arg0, 7);
        return;
    }
    fn_8004FC70(temp_r29);
}

void fn_80099AD0(void *arg0) {
    s32 Event_GetCmdFlags(s16);
    void *Event_GetSlotUnit(s32);
    void *fn_800958A4(s32);
    void *Event_GetCmdFlagRes(s32);
    void *fn_80053AE8(void *, void *);
    void fn_80052FB0(void *, f32 *, f32 *);
    void Unit_FaceToward(void *, void *, s32, void *);

    void *ptrs[3];
    f32 dst[3];
    f32 src[3];
    void **var_r31;
    s32 var_r30;
    void *temp_r29;
    void *temp_r3;
    void *temp_r4;

    if (Event_GetCmdFlags(*(s16 *)((u8 *)arg0 + 0x46)) & 0x40000) {
        ptrs[0] = Event_GetSlotUnit(0);
        ptrs[1] = fn_800958A4(0);
        ptrs[2] = fn_800958A4(1);
        var_r31 = ptrs;
        if (ptrs[0] != NULL && ptrs[1] != NULL && ptrs[2] != NULL) {
            temp_r3 = Event_GetSlotUnit(1);
            src[0] = *(f32 *)((u8 *)temp_r3 + 4);
            temp_r29 = temp_r3;
            var_r30 = 0;
            src[1] = *(f32 *)((u8 *)temp_r3 + 8);
            src[2] = *(f32 *)((u8 *)temp_r3 + 0xC);
            do {
                Unit_FaceToward(*var_r31, temp_r29, 0x18, arg0);
                temp_r4 = *var_r31;
                dst[0] = *(f32 *)((u8 *)temp_r4 + 4);
                dst[1] = *(f32 *)((u8 *)temp_r4 + 8);
                dst[2] = *(f32 *)((u8 *)temp_r4 + 0xC);
                temp_r3 = Event_GetCmdFlagRes(0x40000);
                if (temp_r3 != NULL) {
                    fn_80052FB0(fn_80053AE8(temp_r3, arg0), dst, src);
                }
                var_r30 += 1;
                var_r31 += 1;
            } while (var_r30 < 3);
        }
    }
}

#pragma use_lmw_stmw on
void fn_80099BF8(void *arg0) {
    s32 Event_GetCmdFlags(s16);
    s32 fn_80096EEC(s32 *, s32);
    void *Process_CreateChild(void *, void *);
    void Process_Goto(void *, s32);
    extern u8 lbl_80289C38[];
    s32 buf[19];
    s32 flags;
    s32 count;
    void *chain;
    s32 i;
    s32 val;
    void *obj;

    flags = Event_GetCmdFlags(*(s16 *)((u8 *)arg0 + 0x46));
    count = fn_80096EEC(buf, flags);
    chain = arg0;
    for (i = 0; i < count; i++) {
        val = buf[count - (i + 1)];
        if (val != 0x40000) {
            obj = Process_CreateChild(lbl_80289C38, chain);
            *(s32 *)((u8 *)obj + 0x60) = val;
            chain = obj;
        }
    }
    if (flags & 2) {
        Process_Goto(arg0, 6);
    }
}
#pragma use_lmw_stmw off
void fn_80099CA4(void *arg0) {
    void *fn_80095BB0(s32);
    void *Event_GetCmdFlagRes(s32);
    void Event_GetCmdFlagName(s32);
    void *fn_80053AE8(void *, void *);
    void fn_800536CC(void *, s32);
    void fn_8005306C(void *);

    void *temp_r29;
    void *temp_r30;
    void *temp_r31;
    void *temp_r30_2;

    temp_r29 = arg0;
    temp_r31 = fn_80095BB0(*(s32 *)((u8 *)arg0 + 0x60));
    if (temp_r31 != NULL) {
        temp_r30 = Event_GetCmdFlagRes(*(s32 *)((u8 *)temp_r29 + 0x60));
        Event_GetCmdFlagName(*(s32 *)((u8 *)temp_r29 + 0x60));
        if (temp_r30 != NULL) {
            temp_r30_2 = fn_80053AE8(temp_r30, temp_r29);
            fn_800536CC(temp_r30_2, *(s32 *)temp_r31);
            fn_8005306C(temp_r30_2);
        }
    }
}

void fn_80099D2C(void *arg0) {
    M2C_UNK fn_800056A0(M2C_UNK);
    *(u8 *)((char *)arg0 + 0x42) = (u8)(*(u8 *)((char *)arg0 + 0x42) + 1);
    if ((s8)*(u8 *)((char *)arg0 + 0x42) >= 0xA) {
        fn_800056A0(0);
        Process_Goto(arg0, 7);
        return;
    }
    if ((s8)*(u8 *)((char *)arg0 + 0x43) != 0) {
        fn_800056A0(0);
    }
    if ((s8)*(u8 *)((char *)arg0 + 0x41) > 0) {
        Process_Goto(arg0, 1);
        return;
    }
    Process_Goto(arg0, 0);
}

void fn_80099DC4(s32 arg0) {
    M2C_UNK Process_Goto(s32, M2C_UNK);
    s32 fn_80096D64();
    s32 temp_r3;

    temp_r3 = fn_80096D64();
    switch (temp_r3) {
    case 0:
        Process_Goto(arg0, 3);
        return;
    case 1:
        Process_Goto(arg0, 2);
        return;
    case 2:
        Process_Goto(arg0, 4);
        return;
    case 3:
        Process_Goto(arg0, 5);
        return;
    }
}

void fn_80099E54(void *arg0) {
    M2C_UNK Process_Goto(void *, M2C_UNK);
    s32 Event_GetCmdKind(s16);
    s8 fn_80097168(s16);
    s16 fn_80097740();
    s32 fn_8009809C();
    M2C_FIELD(arg0, s16 *, 0x46) = fn_80097740();
    M2C_FIELD(arg0, s32 *, 0x38) = fn_80098094();
    M2C_FIELD(arg0, s32 *, 0x3C) = fn_8009809C();
    M2C_FIELD(arg0, s8 *, 0x43) = 0;
    if (Event_GetCmdKind(M2C_FIELD(arg0, s16 *, 0x46)) == 0) {
        Process_Goto(arg0, 7);
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x41) = fn_80097168(M2C_FIELD(arg0, s16 *, 0x46));
    M2C_FIELD(arg0, s8 *, 0x42) = 0;
}

void fn_80099ED0(void *arg0) {
    M2C_UNK fn_80096418(s16);
    fn_80096418(*(s16 *)((char *)arg0 + 0x46));
}

void fn_80099EF4(void *arg0) {
    void fn_8017E35C(void);
    if (*(u8 *)((char *)arg0 + 0x34) != 2) {
        fn_8017E35C();
    }
}

void fn_80099F20(void *arg0) {
    void *fn_800980D4(s32);
    void fn_8017E394(void *, void *, void *, s32);
    void *a;
    void *b;
    s32 flag;

    if (*(u8 *)((u8 *)arg0 + 0x34) != 2) {
        a = fn_800980D4(0);
        b = fn_800980D4(1);
        flag = *(u8 *)((u8 *)arg0 + 0x34);
        switch (flag) {
        case 1:
            fn_8017E394(b, 0, arg0, 0);
            break;
        default:
            fn_8017E394(a, b, arg0, 0);
            break;
        }
    }
}

/* Face event-slot units toward each other and play their talk MU blend anims. */
void Event_FaceTalkUnits(s32 parent) {
    u32 Event_GetSlotUnit(s32);
    void Unit_FaceToward(u32, u32, s32, s32);
    void Mu_StartBlend(u32, s32, s32, s32);
    s32 proc;
    u32 unit0;
    u32 unit1;
    u32 unit2;

    proc = parent;
    unit0 = Event_GetSlotUnit(0);
    unit1 = Event_GetSlotUnit(1);
    unit2 = Event_GetSlotUnit(2);
    Mu_StartBlend(unit0, 8, 0x10, proc);
    if (unit1 != 0U) {
        Unit_FaceToward(unit0, unit1, 0x18, proc);
        Unit_FaceToward(unit1, unit0, 0x18, proc);
        Mu_StartBlend(unit1, 8, 0x10, proc);
        if (unit2 != 0U) {
            Unit_FaceToward(unit2, unit1, 0x18, proc);
            Mu_StartBlend(unit2, 8, 0x10, proc);
        }
    }
}

#pragma use_lmw_stmw on
void fn_8009A0A4(void *arg0, s16 arg1) {
    s32 Event_GetCmdKind(s16);
    s32 Event_GetCmdFlags(s16);
    void fn_800983E0(void *, void *);
    u8 fn_80096C18(void);
    void SeCue_PlayAtPos(void *, void *, s32);
    void fn_80048E08(void *, void *, void *, s32);
    void **fn_800984FC(void **);
    void Mu_StartBlend(void *, s32, s32, s32);
    void fn_80184BE8(void *, s32, s32, s32);
    void fn_80184688(void *, s32, s32, void *);
    void fn_8018CFA4(s32, s32, s32, s32, void *);
    void fn_80025624(s32, s32);
    void fn_8017E2BC(void);
    void *fn_80095934(void *, s32, s32);
    void *Effect_Create(void *, void *);
    void Effect_SetPos(void *, f32, f32, f32);
    void fn_800536CC(void *, void *);
    void fn_800536D8(void *, void *);
    void fn_8005306C(void *);
    extern u8 gEventUiSeCues[];
    extern s32 gPadInput;
    extern s32 lbl_803697D8;
    Word3 pos;
    Word3 sp78;
    Word3 sp6C;
    Word3 sp60;
    Word3 sp54;
    Word3 sp48;
    Word3 sp3C;
    Word3 sp30;
    Word3 sp24;
    Word3 sp18;
    Word3 spC;
    s32 sp8;
    s32 kind;
    s32 flags;
    void *tmp;
    void *created;
    void **temp_r4;
    void *temp_r3_2;
    void *var_r0_2;
    void *temp_r3_3;
    s32 mode;
    u8 item;

    kind = Event_GetCmdKind(arg1);
    flags = Event_GetCmdFlags(arg1);
    fn_800983E0(&sp78, M2C_FIELD(arg0, void **, 0x3C));
    mode = M2C_FIELD(arg0, u8 *, 0x34);
    pos = sp78;
    switch (mode) {
    case 1:
        if (fn_80096C18() != 0) {
            sp6C = pos;
            SeCue_PlayAtPos(gEventUiSeCues + 0x124, &sp6C, 0x64);
        } else {
            sp60 = pos;
            SeCue_PlayAtPos(gEventUiSeCues + 0x140, &sp60, 0x64);
        }
        if (M2C_FIELD(arg0, void **, 0x30) != NULL) {
            sp8 = lbl_803697D8;
            fn_80048E08(M2C_FIELD(arg0, void **, 0x30), arg0, &sp8, 2);
        }
        break;
    default:
        if (fn_80096C18() != 0) {
            sp54 = pos;
            SeCue_PlayAtPos(gEventUiSeCues + 0x155, &sp54, 0x64);
        } else {
            tmp = *fn_800984FC(M2C_FIELD(arg0, void **, 0x38));
            if (tmp != NULL) {
                item = M2C_FIELD(tmp, u8 *, 0x12);
            } else {
                item = 0xC;
            }
            switch (item) {
            case 1:
            case 3:
                sp48 = pos;
                SeCue_PlayAtPos(gEventUiSeCues + 0x16C, &sp48, 0x64);
                break;
            case 0:
            case 2:
            case 8:
                if (M2C_FIELD(arg0, u8 *, 0x41) & 1) {
                    sp3C = pos;
                    SeCue_PlayAtPos(gEventUiSeCues + 0x183, &sp3C, 0x64);
                } else {
                    sp30 = pos;
                    SeCue_PlayAtPos(gEventUiSeCues + 0x104, &sp30, 0x64);
                }
                break;
            default:
                sp24 = pos;
                SeCue_PlayAtPos(gEventUiSeCues + 0x104, &sp24, 0x64);
                break;
            }
        }
        temp_r4 = M2C_FIELD(arg0, void ***, 0x3C);
        temp_r3_2 = *temp_r4;
        if (temp_r3_2 != NULL) {
            var_r0_2 = *(void **)((u8 *)temp_r3_2 + 0x280);
        } else {
            var_r0_2 = NULL;
        }
        if (var_r0_2 != NULL) {
            temp_r3_2 = NULL;
            temp_r3_3 = *temp_r4;
            if (temp_r3_3 != NULL) {
                temp_r3_3 = *(void **)((u8 *)temp_r3_3 + 0x280);
            } else {
                temp_r3_3 = NULL;
            }
            Mu_StartBlend(temp_r3_3, 9, 2, 0);
            fn_80184BE8(get_280(M2C_FIELD(arg0, void ***, 0x3C)), 8, 8, 0);
            fn_80184688(get_280(M2C_FIELD(arg0, void ***, 0x3C)), 1, 2, arg0);
        }
        break;
    }
    if (flags & 0xFFC00000) {
        sp18 = pos;
        SeCue_PlayAtPos(gEventUiSeCues + 0x196, &sp18, 0x64);
    } else if (kind == 0x51) {
        spC = pos;
        SeCue_PlayAtPos(gEventUiSeCues + 0x1AE, &spC, 0x64);
    }
    if (kind == 0x51) {
        fn_8018CFA4(0x3C, 6, 2, 0, arg0);
        fn_80025624(gPadInput, 0x10);
        fn_8017E2BC();
    } else {
        fn_8018CFA4(0xF, 6, 2, 0, arg0);
        fn_80025624(gPadInput, 8);
    }
    tmp = fn_80095934(M2C_FIELD(arg0, void **, 0x38), kind, flags);
    if (tmp != NULL) {
        created = Effect_Create(tmp, arg0);
        mode = M2C_FIELD(arg0, u8 *, 0x34);
        switch (mode) {
        case 1:
            Effect_SetPos(created, *(f32 *)&pos.x, *(f32 *)&pos.y, *(f32 *)&pos.z);
            break;
        default:
            fn_800536CC(created, *M2C_FIELD(arg0, void ***, 0x38));
            fn_800536D8(created, *M2C_FIELD(arg0, void ***, 0x3C));
            fn_8005306C(created);
            break;
        }
    }
}
void fn_8009A514(void) {
    u32 temp_r3 = Process_Find(lbl_80289EB8);
    if (temp_r3 != 0) {
        Process_Goto(temp_r3, 4);
    }
}

void fn_8009A54C(void) {
    extern u8 lbl_80289EB8[16];
    extern void *Process_Find(void *);
    extern void Process_Goto(void *, int);

    void *result;

    result = Process_Find(lbl_80289EB8);

    if (result != 0) {
        Process_Goto(result, 3);
    }
}

void fn_8009A584(void) {
    extern u8 lbl_80289EB8[16];
    extern void *Process_Find(void *);
    extern void Process_Goto(void *, int);

    void *result;

    result = Process_Find(lbl_80289EB8);

    if (result != 0) {
        Process_Goto(result, 2);
    }
}

void fn_8009A5BC(void) {
    extern u8 lbl_80289EB8[16];
    extern void *Process_Find(void *);
    extern void Process_Goto(void *, int);

    void *result;

    result = Process_Find(lbl_80289EB8);

    if (result != 0) {
        Process_Goto(result, 1);
    }
}

