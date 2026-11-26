/* Functions from 0x8007C5E4 to 0x8009F0BC, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
static inline void UnitInfo_DrawHp(s32 y, s32 current, s32 maximum, void *label) {
    extern char gBattleHelpStrings[];
    extern f32 lbl_80369754, gZeroF;
    void fn_8001003C(s32,s32,s32,s32,s32,f32,f32,const char *,...);
    fn_8001003C(0x10,y,1,1,0,lbl_80369754,gZeroF,gBattleHelpStrings+0xFA,label,(s8)current,(s8)maximum);
}
static inline void UnitInfo_DrawIcons(u8 *unit, s32 y, void *drawer) {
    s32 fn_8010418C(void *, s32);
    s32 fn_8010424C(void *);
    void Ui_DrawIcon(void *, s32, s32, s32);
    s32 x;
    s32 i;
    i = 0;
    x = 0x48;
    while (i < fn_8010424C(unit + 0x1A4)) {
        Ui_DrawIcon(drawer, x, y, fn_8010418C(unit + 0x1A4, i));
        x += 0x1A;
        i++;
    }
}
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

void fn_8008FE5C(u8 *arg0) {
 extern u8 gBattleHelpStrings[];
 void *fn_800C4638(s32,void *,s32);
 u8 *dst,*src;
 s32 i;
 *(void **)(arg0+0x30)=fn_800C4638(128,gBattleHelpStrings+0xF9,0);
 for(i=0;i<16;i++) {
 (*(u8 **)(arg0+0x30))[i*4]=255;
 (*(u8 **)(arg0+0x30))[i*4+1]=i*14;
 (*(u8 **)(arg0+0x30))[i*4+2]=i*8;
 (*(u8 **)(arg0+0x30))[i*4+3]=255;
 src=*(u8 **)(arg0+0x30)+i*4;
 dst=*(u8 **)(arg0+0x30)+(31-i)*4;
 dst[0]=src[0];dst[1]=src[1];dst[2]=src[2];dst[3]=src[3];
 }
}

#pragma use_lmw_stmw on
/* Draw up to three Msg_Expand strings centered in a message panel. */
void Ui_DrawCenteredMsgLines(s32 x, s32 y, u32 msg1, u32 msg2, u32 msg3) {
    void *Msg_Expand(u32);
    void Text_Draw(s16, s16, u8, void *, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    s32 Ui_DrawMsgPanelBg();
    extern f32 lbl_80369754;
    void *text;
    void *text2;
    s32 panelW;
    s32 pad;
    s32 pad2;
    s32 pad3;

    panelW = Ui_DrawMsgPanelBg();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    if (msg1 != 0U) {
        text = Msg_Expand(msg1);
        pad = panelW - Text_MeasureWidth(text, -1, lbl_80369754);
        Text_Draw((s16) (x + pad / 2), (s16) (y + 0x1E), 2, text);
    }
    if (msg2 != 0U) {
        text2 = Msg_Expand(msg2);
        pad2 = panelW - Text_MeasureWidth(text2, -1, lbl_80369754);
        Text_Draw((s16) (x + pad2 / 2), (s16) (y + 0x3C), 8, text2);
    }
    if (msg3 != 0U) {
        msg3 = (u32) Msg_Expand(msg3);
        pad3 = panelW - Text_MeasureWidth((void *) msg3, -1, lbl_80369754);
        Text_Draw((s16) (x + pad3 / 2), (s16) (y + 0x54), 8, (void *) msg3);
    }
}

#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw off
#pragma global_optimizer off
#pragma opt_strength_reduction off
void UnitInfo_DrawPair(u8 *arg0) {
#pragma scheduling on
    void fn_8008BA80(void *, s32, s32, s32);
    void fn_8007D044(s32, u8, f32, f32, f32, f32);
    void fn_8008CD64(f32);
    void fn_8008CD34(void);
    s8 Unit_GetMaxHp(void *);
    s8 fn_8003A1E0(void *);
    void *Msg_Expand(char *);
    void fn_8001003C(s32,s32,s32,s32,s32,f32,f32,const char *,...);
    s32 fn_8010418C(void *, s32);
    s32 fn_8010424C(void *);
    void Ui_DrawIcon(void *, s32, s32, s32);
    void UnitInfo_DrawPanel(s32, s32, u8);
    void *Msg_ResolveName(void *);
    s32 Text_MeasureWidth(void *, s32, f32);
    void Text_Draw(s16, s16, s32, void *, ...);
    extern const f32 gZeroF, lbl_80369780, lbl_80369784, lbl_80369788;
    extern f32 lbl_80369768, lbl_80369754;
    extern char gBattleHelpStrings[];
    extern u8 gUiIconDrawer[];
    u8 *self;
    s32 t;
    s32 b;
    s32 x;
    void *p;
    u8 *por;
    f32 f1, f2, f3, f4;

    self = arg0;
    fn_8008BA80(self, 0, 0, 0);
    por = *(u8 **)(self + 0x190);
    f1 = gZeroF;
    f2 = lbl_80369780;
    f3 = lbl_80369784;
    f4 = lbl_80369788;
    fn_8007D044(0xB3, por[8], f1, f2, f3, f4);
    fn_8008CD64(lbl_80369768);
    fn_8008CD34();
    b = self[0x1A8];
    t = Unit_GetMaxHp(self);
    p = Msg_Expand(gBattleHelpStrings + 0x111);
    fn_8001003C(0x10, 0x2C, 1, 1, 0, lbl_80369754, gZeroF, gBattleHelpStrings + 0xFA, p, (s8)b, (s8)t);
    t = fn_8003A1E0(self);
    p = Msg_Expand(gBattleHelpStrings + 0x126);
    fn_8001003C(0x86, 0x2C, 1, 1, 0, lbl_80369754, gZeroF, gBattleHelpStrings + 0x117, p, (s8)t);
    p = Msg_Expand(gBattleHelpStrings + 0x135);
    fn_8001003C(0x10, 0x48, 1, 1, 0, lbl_80369754, gZeroF, gBattleHelpStrings + 0x12D, p);
    UnitInfo_DrawIcons(self, 0x4A, gUiIconDrawer);
    self = *(u8 **)(self + 0x194);
    UnitInfo_DrawPanel(9, 0x68, ((u8 *)*(void **)(self + 0x190))[8]);
    fn_8008CD64(lbl_80369768);
    fn_8008CD34();
    b = (0xCF - Text_MeasureWidth(Msg_ResolveName(*(void **)(self + 0x188)), -1, lbl_80369754)) / 2;
    Text_Draw((s16)(b + 9), 0x6C, 1, Msg_ResolveName(*(void **)(self + 0x188)));
    Text_Draw((s16)(b - 0xF), 0x6C, 1, gBattleHelpStrings + 0x13D);
    b = self[0x1A8];
    t = Unit_GetMaxHp(self);
    p = Msg_Expand(gBattleHelpStrings + 0x111);
    fn_8001003C(0x10, 0x90, 1, 1, 0, lbl_80369754, gZeroF, gBattleHelpStrings + 0xFA, p, (s8)b, (s8)t);
    t = fn_8003A1E0(self);
    p = Msg_Expand(gBattleHelpStrings + 0x126);
    fn_8001003C(0x86, 0x90, 1, 1, 0, lbl_80369754, gZeroF, gBattleHelpStrings + 0x117, p, (s8)t);
    p = Msg_Expand(gBattleHelpStrings + 0x135);
    fn_8001003C(0x10, 0xAC, 1, 1, 0, lbl_80369754, gZeroF, gBattleHelpStrings + 0x12D, p);
    UnitInfo_DrawIcons(self, 0xAE, gUiIconDrawer);
}
#pragma pop
