/* Functions from 0x800725C8 to 0x800732BC, found by decomp-toolkit. */
#include "common.h"
extern u16 lbl_801D3B14[];
extern void *lbl_801D8A28;
extern void *lbl_801D8A30;

void fn_800725C8(void **arg0)
{
  extern u8 lbl_8028459C[];
  u8 *new_var;
  extern u8 lbl_80285FE8[];
  new_var = lbl_80285FE8;
  if ((lbl_80285FE8 && lbl_80285FE8) && lbl_80285FE8)
  {
  }
  *arg0 = lbl_8028459C;
  *arg0 = lbl_80285FE8 - -0x628;
  *arg0 = lbl_80285FE8 + 0x2FC;
  *arg0 = new_var + 0xC;
}

extern u8 lbl_80286860[16];
void fn_800725F8(s32 arg0) {
    void fn_8000CAA0(void *, s32);
    extern u8 lbl_80286860[16];
    fn_8000CAA0(lbl_80286860, arg0);
}

#pragma global_optimizer off
void fn_80072624(void) {
    void fn_8003BE50(void *);
    u8 fn_80091D74(void);
    extern u8 gUiContext[24];
    void *p;
    u8 *base;

    p = *(void **)gUiContext;
    if ((*(s32 *)((u8 *)p + 0x1A0) & 0x800000) && fn_80091D74() == 0) {
        fn_8003BE50(*(void **)gUiContext);
    }
    base = gUiContext;
    p = *(void **)(base + 4);
    if ((*(s32 *)((u8 *)p + 0x1A0) & 0x800000) && fn_80091D74() == 0) {
        fn_8003BE50(*(void **)(base + 4));
    }
}
#pragma global_optimizer on
void fn_800726A8(s32 arg0) {
    u8 fn_80091D74(void);
    void fn_80183BE4(void *, s32);
    extern u8 gUiContext[24];
    void *p;
    u8 *base;

    p = *(void **)gUiContext;
    if ((*(s32 *)((u8 *)p + 0x1A0) & 0x800000) && fn_80091D74() == 0) {
        fn_80183BE4(*(void **)gUiContext, arg0);
    }
    base = gUiContext;
    p = *(void **)(base + 4);
    if ((*(s32 *)((u8 *)p + 0x1A0) & 0x800000) && fn_80091D74() == 0) {
        fn_80183BE4(*(void **)(base + 4), arg0);
    }
}

void fn_80072740(s32 arg0) {
    s32 *fn_800285C0(void *);
    void fn_8001C878(s32, s32, s32);
    extern struct {
        s32 unk0;
        s32 unk4;
        u8 unk8;
        u8 unk9;
        s8 unkA;
    } gUiContext;
    s32 *temp;

    temp = fn_800285C0(&gUiContext);
    fn_8001C878(gUiContext.unk0, *temp, arg0);
}

void fn_8007278C(void) {
    extern u8 lbl_8026BC88[];
    extern u8 gUiContext[];
    if ((void *) M2C_FIELD(&gUiContext, void **, 4) != NULL) {
        fn_800A8A88(M2C_FIELD(M2C_FIELD(&gUiContext, void **, 4), s32 *, 0x188));
        fn_80091A1C();
        return;
    }
    Msg_Expand(lbl_8026BC88 + 0x1A5);
    fn_80091A1C();
}

void fn_800727E0(void) {
    extern u16 gUiContext[12];
    fn_800285C0(gUiContext);
    UnitRef_GetName();
    fn_80091A1C();
}

#pragma global_optimizer off
void fn_80072810(void) {
    void fn_8010FF24(void *, u8, u8, s32);
    void fn_8010FA2C(void);
    void UnitRef_GetName(void);
    void fn_80091A1C(void);
    extern u8 gUiContext[];
    extern u8 lbl_8032BB58[];
    u8 *base;
    void *ptr;
    u8 a;
    u8 b;

    base = gUiContext;
    ptr = *(void **)base;
    a = *((u8 *)ptr + 0x19F);
    b = *((u8 *)ptr + 0x19E);
    fn_8010FF24(lbl_8032BB58, b, a, 7);
    fn_8010FA2C();
    UnitRef_GetName();
    fn_80091A1C();
}
#pragma global_optimizer on
void fn_8007285C(void) {
    void UnitRef_GetName(void);
    void fn_80037D54(void *);
    void fn_80091A1C(void);
    extern u8 gUiContext[];
    fn_80037D54(*(void **)gUiContext);
    UnitRef_GetName();
    fn_80091A1C();
}

void fn_80072890(void) {
    void fn_80184C7C(s32, s32, s32, s32);
    extern u8 gUiContext[24];
    fn_80184C7C(*(s32 *)(gUiContext + 4), 0, 4, 0);
}

void fn_800728C8(void) {
    void fn_80184C7C(s32, s32, s32, s32);
    extern u8 gUiContext[24];
    fn_80184C7C(*(s32 *)gUiContext, 0, 4, 0);
}

void fn_80072900(s32 arg0) {
    void fn_80024398(void *, s32, s32);
    extern u8 gUiContext[24];
    extern u8 lbl_8036737C;
    u8 *p;

    p = gUiContext;
    p[8] = 0;
    fn_80024398(&lbl_8036737C, arg0, 0);
}

void fn_8007293C(void) {
    extern u8 gBattleState[];
    gBattleState[0x54] = (u8)(gBattleState[0x54] & 0x7F);
}

void fn_80072954(void *arg0) {
    void fn_801D3B14(void *);
    extern u8 gBattleState[];
    gBattleState[0x54] |= 0x80;
    fn_801D3B14(arg0);
}

void fn_80072988(void) {
s32 fn_8000BCA4(void *); void fn_8000CAA0(void *,s32); void fn_80023DE8(void);
extern u8 gUiContext[]; extern u8 lbl_8036723A; extern u8 lbl_8026BE40[]; extern u8 lbl_80286DA8[];
s32 temp;
if(gUiContext[8]==1) {
switch(lbl_8036723A & 8) {
case 0:
temp=fn_8000BCA4(lbl_8026BE40+0x101);
if(temp) {fn_80023DE8(); fn_8000CAA0(lbl_80286DA8,temp);}
break;
default: break;
}
}
}

void fn_800729FC(void *arg0) {
    extern u8 gUiContext[];
    void fn_80073C44(void *);
    u8 *p = gUiContext;
    p[8] = 1;
    fn_80073C44(arg0);
}

void fn_80072A2C(void *arg0) {
    extern u8 lbl_80311D50[];
    *(u16 *)(lbl_80311D50 + 2) = 0xC8;
    *(s16 *)((u8 *)arg0 + 0x3A) = -0x20;
}

void fn_80072A48(void) {
    M2C_UNK fn_80006220(M2C_UNK);
    M2C_UNK fn_8000BD98(void *);
    M2C_UNK fn_8002D780(M2C_UNK);
    extern u8 lbl_8026BE40[];
    extern u8 lbl_80311D50[];
    fn_80006220(3);
    fn_8002D780(6);
    fn_8000BD98(lbl_8026BE40 + 0x101);
    *(u16 *)(lbl_80311D50 + 2) = 0xC8;
}

void fn_80072A94(void) {
    M2C_UNK fn_8000BD98(void *);
    M2C_UNK fn_8008A290(M2C_UNK, M2C_UNK);
    M2C_UNK fn_801480D8(M2C_UNK);
    extern u8 lbl_8026BE40[];
    fn_801480D8(0xBB8);
    fn_8008A290(3, 0x7D0);
    fn_8000BD98(lbl_8026BE40 + 0x10C);
}

void fn_80072AD4(void *arg0) {
    void Process_ClearFunc(void *);
    extern void *gPadInput;
    if (*(s32 *)((char *)gPadInput + 4) & 0x300) {
        Process_ClearFunc(arg0);
    }
}

void fn_80072B04(void *arg0) {
    void MsgBox_Init(void *, u8 *, s32, s32, s32);
    s32 Msg_Expand(u8 *);
    extern u8 lbl_8026BE40[];
    extern u16 lbl_80311D50[];
    MsgBox_Init(lbl_80311D50, lbl_8026BE40 + 0x11A, 0, 0, 0);
    M2C_FIELD(arg0, s16 *, 0x28) = 0x258;
    M2C_FIELD(arg0, s32 *, 0x34) = Msg_Expand(lbl_8026BE40 + 0x127);
}

void fn_80072B6C(void *arg0)
{
    void fn_801E2594(void *);
    s32 fn_800EB774(void);
    void MsgBox_Init(void *, u8 *, s32, s32, s32);
    s32 Msg_Expand(u8 *);
    void Process_Goto(void *, s32);
    extern u8 gSaveDataBase;
    extern u8 lbl_8026BE40[];
    extern u16 lbl_80311D50[];
    s32 r;

    fn_801E2594(&gSaveDataBase);
    r = fn_800EB774();
    switch (r) {
    case -3:
        MsgBox_Init(lbl_80311D50, lbl_8026BE40 + 0x12D, 0, 1, 0);
        *(s32 *)((u8 *)arg0 + 0x34) = Msg_Expand(lbl_8026BE40 + 0x13B);
        Process_Goto(arg0, 0xA);
        return;
    default:
        MsgBox_Init(lbl_80311D50, lbl_8026BE40 + 0x141, 0, 1, 0);
        *(s32 *)((u8 *)arg0 + 0x34) = Msg_Expand(lbl_8026BE40 + 0x13B);
        Process_Goto(arg0, 0xA);
        return;
    case 0:
    case -66:
        lbl_80311D50[1] = 0xC8;
        return;
    }
}

void fn_80072C64(void *arg0)
{
    void fn_801E047C(void *, void *);
    void MsgBox_Init(void *, u8 *, s32, s32, s32);
    extern u8 gSaveDataBase;
    extern u8 lbl_8026BE40[];
    extern u16 lbl_80311D50[];

    fn_801E047C(&gSaveDataBase, arg0);
    MsgBox_Init(lbl_80311D50, lbl_8026BE40 + 0x14D, 0, 0, 0);
}

void fn_80072CB0(s32 arg0) {
    M2C_UNK fn_801E3118(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK gSaveDataBase;
    fn_801E3118(&gSaveDataBase, arg0, 1);
}

void fn_80072CDC(void *arg0) {
    void MsgBox_Init(void *, u8 *, s32, s32, s32);
    extern u8 lbl_8026BE40[];
    extern u16 lbl_80311D50[];
    MsgBox_Init(lbl_80311D50, lbl_8026BE40 + 0x155, 0, 1, 0);
    M2C_FIELD(arg0, s32 *, 0x30) = -0x80;
}

void fn_80072D30(void *arg0) {
    void MsgBox_Init(void *, u8 *, s32, s32, s32);
    extern u8 lbl_8026BE40[];
    extern u16 lbl_80311D50[];
    MsgBox_Init(lbl_80311D50, lbl_8026BE40 + 0x162, 0, 1, 0);
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
}

void fn_80072D84(void *arg0) {
    void MsgBox_Init(void *, u8 *, s32, s32, s32);
    extern u8 lbl_8026BE40[];
    extern u16 lbl_80311D50[];
    MsgBox_Init(lbl_80311D50, lbl_8026BE40 + 0x16F, 0, 1, 0);
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
}

void fn_80072DD8(void *arg0) {
    void MsgBox_Init(void *, u8 *, s32, s32, s32);
    extern u8 lbl_8026BE40[];
    extern u16 lbl_80311D50[];
    MsgBox_Init(lbl_80311D50, lbl_8026BE40 + 0x179, 0, 1, 0);
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
}

void fn_80072E2C(void *arg0) {
    void MsgBox_Init(void *, u8 *, s32, s32, s32);
    extern u8 lbl_8026BE40[];
    extern u16 lbl_80311D50[];
    MsgBox_Init(lbl_80311D50, lbl_8026BE40 + 0x188, 0, 1, 0);
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
}

void fn_80072E80(void *arg0) {
    void MsgBox_Init(void *, u8 *, s32, s32, s32);
    extern u8 lbl_8026BE40[];
    extern u16 lbl_80311D50[];
    MsgBox_Init(lbl_80311D50, lbl_8026BE40 + 0x199, 0, 1, 0);
    M2C_FIELD(arg0, s32 *, 0x30) = -2;
}

void fn_80072ED4(void *arg0) {
    void MsgBox_Init(void *, u8 *, s32, s32, s32);
    extern u8 lbl_8026BE40[];
    extern u16 lbl_80311D50[];
    MsgBox_Init(lbl_80311D50, lbl_8026BE40 + 0x12D, 0, 1, 0);
    M2C_FIELD(arg0, s32 *, 0x30) = -3;
}

void fn_80072F28(void *arg0) {
    void Process_Goto(void *, s32);
    s32 Msg_Expand(u8 *);
    s32 fn_800EB74C(void);
    s32 fn_8021A8C8(s32, s32, s32);
    extern u8 lbl_8026BE40[];
    extern u16 lbl_80311D50[];
    extern void *gPadInput;
    s32 buttons;
    s32 prev;
    s32 var_r3;

    *(s32 *)((u8 *)arg0 + 0x34) = Msg_Expand(lbl_8026BE40 + 0x13B);
    buttons = *(s32 *)((u8 *)gPadInput + 4);
    prev = *(s32 *)((u8 *)gPadInput + 8);
    if (buttons & (prev ^ buttons) & 0x200) {
        lbl_80311D50[1] = 0xC8;
        Process_Goto(arg0, 9);
        return;
    }
    var_r3 = fn_8021A8C8(fn_800EB74C(), 0, 0);
    if (var_r3 != -1) {
        if (var_r3 == -0xD) {
            var_r3 = -6;
        }
        if (var_r3 != *(s32 *)((u8 *)arg0 + 0x30)) {
            lbl_80311D50[1] = 0xC8;
            switch (var_r3) {
            case 0:
            case -66:
                Process_Goto(arg0, 0);
                return;
            case -3:
                Process_Goto(arg0, 2);
                return;
            case -2:
                Process_Goto(arg0, 3);
                break;
            }
        }
    }
}

void fn_8007303C(s32 arg0) {
    M2C_UNK Process_Goto(s32, M2C_UNK);
    s32 fn_800EB774();
    s32 temp_r3;

    temp_r3 = fn_800EB774();
    switch (temp_r3) {                              /* irregular */
    case 0:
    case -66:
        Process_Goto(arg0, 1);
        return;
    case -3:
        Process_Goto(arg0, 2);
        return;
    case -2:
        Process_Goto(arg0, 3);
        return;
    case -6:
    case -13:
        Process_Goto(arg0, 4);
        return;
    case -5:
        Process_Goto(arg0, 5);
        return;
    case -65:
        Process_Goto(arg0, 6);
        return;
    case -128:
        Process_Goto(arg0, 7);
        return;
    case -4:
    case -64:
        Process_Goto(arg0, 8);
        return;
    default:
        Process_Goto(arg0, 7);
        return;
    }
}

void fn_80073164(void) {
    M2C_UNK fn_801E2594(M2C_UNK *);
    extern M2C_UNK gSaveDataBase;
    fn_801E2594(&gSaveDataBase);
}

void fn_80073188(void *arg0) {
    void *memset(void *, s32, u32);
    void fn_801E3118(void *, void *, s32);
    extern u8 lbl_8026BE40[];
    extern u16 lbl_80311D50[];
    extern M2C_UNK gSaveDataBase;
    memset(lbl_80311D50, 0, 0x1EA);
    lbl_80311D50[1] = 0;
    lbl_80311D50[0] = 0;
    lbl_80311D50[0xF] = 0;
    M2C_FIELD(arg0, u8 **, 0x34) = lbl_8026BE40 + 0x1A6;
    M2C_FIELD(arg0, u16 *, 0x38) = 0;
    M2C_FIELD(arg0, u16 *, 0x3A) = 0x20;
    fn_801E3118(&gSaveDataBase, arg0, 1);
}

void fn_80073208(void *arg0) {
    M2C_UNK Prim2D_SetColorByte(u8);
    M2C_UNK Prim2D_SetTransform(f32, f32, f32, f32);
    M2C_UNK Prim2D_PrepareTex();
    M2C_UNK Prim2D_Begin();
    M2C_UNK Ui_DrawCaptionBar(s32, M2C_UNK);
    M2C_UNK fn_801DCD3C(u16 *);
    M2C_UNK fn_801DDAC8(u16 *);
    extern u16 lbl_80311D50[];
    extern f32 lbl_80369368;
    extern f32 lbl_8036936C;
    extern f32 lbl_80369370;
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_80369368, lbl_80369368, lbl_8036936C, lbl_80369370);
    Prim2D_PrepareTex();
    fn_801DDAC8(lbl_80311D50);
    fn_801DCD3C(lbl_80311D50);
    M2C_FIELD(arg0, s16 *, 0x38) = (s16) (M2C_FIELD(arg0, s16 *, 0x38) + M2C_FIELD(arg0, s16 *, 0x3A));
    if (M2C_FIELD(arg0, s16 *, 0x38) > 0xFF) {
        M2C_FIELD(arg0, s16 *, 0x38) = 0xFF;
    }
    if (M2C_FIELD(arg0, s16 *, 0x38) < 0) {
        M2C_FIELD(arg0, s16 *, 0x38) = 0;
    }
    Prim2D_Begin();
    Prim2D_SetColorByte((u8) M2C_FIELD(arg0, s16 *, 0x38));
    Prim2D_PrepareTex();
    Ui_DrawCaptionBar(M2C_FIELD(arg0, s32 *, 0x34), 0);
}

extern u16 gUiContext[12];
extern u8 lbl_8036723A;
extern u8 lbl_8026BE40[];
extern u8 lbl_80286DA8[];
extern u16 lbl_80311D50[124];
extern void fn_80006220(s32);
extern void fn_8002D780(s32);
extern void fn_8000BD98(void *);
extern s32 fn_8000BCA4(void *);
extern void fn_8000CAA0(void *, s32);
extern void fn_80023DE8(void);
