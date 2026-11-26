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

void Ui_DrawTerrainInfoDecor(s32 tex, s32 mode, f32 x, f32 y) {
    void Prim2D_EmitQuad(void);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_BindTexture(s32, s32, s32);
    extern f32 lbl_803697E4;
    extern f32 lbl_803697F8;
    extern f32 lbl_803697FC;
    extern f32 lbl_80369808;
    extern f32 lbl_8036980C;
    extern f32 lbl_8036981C;
    extern f32 lbl_80369830;
    extern f32 lbl_80369844;
    extern f32 lbl_80369860;
    extern f32 lbl_80369868;
    extern f32 lbl_8036987C;
    extern f32 lbl_80369880;
    extern f32 lbl_80369884;
    extern f32 lbl_80369888;
    extern f32 lbl_8036988C;

    // Draw terrain-info popup frame pieces for mode 0/1/2 (tex slots 8/9/A).
    switch (mode) {
    case 0:
        Prim2D_Begin();
        Prim2D_SetTransform(x, y, lbl_80369808, lbl_8036980C);
        Prim2D_BindTexture(tex, 8, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_8036987C, lbl_803697FC, lbl_803697E4, lbl_803697E4, lbl_80369860, lbl_8036981C);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_80369880, lbl_803697FC, lbl_80369830, lbl_803697E4, lbl_80369884, lbl_8036981C);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_80369888, lbl_803697FC, lbl_80369868, lbl_803697E4, lbl_803697FC, lbl_8036981C);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        break;
    case 1:
        Prim2D_Begin();
        Prim2D_SetTransform(x, y, lbl_80369808, lbl_8036980C);
        Prim2D_BindTexture(tex, 9, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_803697F8, lbl_803697FC, 0.0f, 0.0f, lbl_803697F8, lbl_8036981C);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        break;
    case 2:
        Prim2D_Begin();
        Prim2D_SetTransform(x, y, lbl_80369808, lbl_8036980C);
        Prim2D_BindTexture(tex, 0xA, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv(lbl_80369844, lbl_803697FC, 0.0f, 0.0f, lbl_8036988C, lbl_803697FC);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        break;
    }
}

void fn_8009B738(s32 arg0, s32 arg1) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void fn_8014BB58(s32, s32, void *, char *);
    void sprintf(char *, char *, ...);
    extern f32 lbl_803698FC;
    extern f32 lbl_80369900;
    extern f32 lbl_80369904;
    extern u32 lbl_803698E8;
    extern u32 lbl_803698EC;
    extern u32 lbl_803698F0;
    extern u32 lbl_803698F4;
    extern u8 lbl_80312100[];
    extern u8 gDebugHudStrs[];
    char buf[0x10];
    u32 c0;
    u32 c1;
    u32 c2;
    u32 c3;
    u32 bus;
    u32 rate;
    u32 ticks;

    Prim2D_Begin();
    Prim2D_SetTransform((f32)arg0, (f32)arg1, lbl_803698FC, lbl_80369900);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 1000u;
    ticks = *(u32 *)(lbl_80312100 + 0xB8) << 3;
    sprintf(buf, (char *)gDebugHudStrs + 8, (f32)(ticks / rate) / lbl_80369904);
    c0 = lbl_803698E8;
    fn_8014BB58(0, 0, &c0, buf);

    sprintf(buf, (char *)gDebugHudStrs + 0x13, (s32)*(s16 *)(lbl_80312100 + 0xBC));
    c1 = lbl_803698EC;
    fn_8014BB58(0, 8, &c1, buf);

    sprintf(buf, (char *)gDebugHudStrs + 0x1D, (s32)*(s16 *)(lbl_80312100 + 0xBE));
    c2 = lbl_803698F0;
    fn_8014BB58(0, 0x10, &c2, buf);

    sprintf(buf, (char *)gDebugHudStrs + 0x28, *(s32 *)(lbl_80312100 + 0xC0));
    c3 = lbl_803698F4;
    fn_8014BB58(0, 0x18, &c3, buf);
}

void fn_8009B900(s32 arg0, s32 arg1) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_EndPrim(void);
    void Prim2D_SetRect(f32, f32, f32, f32);
    u32 Game_GetFrameCount(void);
    u32 strlen(const char *);
    void fn_8014BB58(s32, s32, u32 *, char *);
    extern u8 gDebugHudStrs[];
    extern u8 gFxChannels[];
    extern u8 gSeCueSlots[];
    extern u8 gFxSlots[];
    extern f32 lbl_803698FC;
    extern f32 lbl_80369900;
    extern f32 lbl_80369918;
    extern f32 lbl_8036991C;
    extern f32 lbl_80369920;
    extern f32 lbl_80369924;
    extern f32 lbl_80369928;
    extern f32 lbl_8036992C;
    extern u32 lbl_803698B8;
    extern u32 lbl_803698BC;
    extern u32 lbl_803698C0;
    extern u32 lbl_803698C4;
    extern u32 lbl_803698C8;
    extern u32 lbl_803698CC;
    extern u32 lbl_803698D0;
    extern u32 lbl_803698D4;
    extern u32 lbl_803698D8;
    extern u32 lbl_803698DC;
    extern u32 lbl_803698E0;
    extern u32 lbl_803698E4;
    u32 headerColor0, headerColor1, headerColor2, headerColor3, headerColor4, headerColor5;
    u32 textColor0, textColor1, textColor2, textColor3, textColor4, textColor5;
    u8 groupA[3];
    u8 groupB[8];
    u8 groupC[40];
    u8 *groupAPtr, *groupBPtr;
    u8 * volatile groupCPtr;
    u8 * volatile fxChannelsBase;
    s32 i, j, groupY, barY, targetY, span, cumulative, baseId, kind, channelId;
    s32 brightness, phase, active;
    u32 len;
    u8 *channel, *record;
    char *label;
    void *virtualTable;
    u32 (*check)(void *);
    f32 xLeft, xRight, yLeft, yRight;

    Prim2D_Begin();
    Prim2D_SetTransform((f32)arg0, (f32)arg1, lbl_803698FC, lbl_80369900);
    Prim2D_PrepareTex();
    headerColor0 = lbl_803698B8;
    fn_8014BB58(0x13A, 0x20, &headerColor0, (char *)(gDebugHudStrs + 0x2F));
    headerColor1 = lbl_803698BC;
    fn_8014BB58(0x13A, 0x38, &headerColor1, (char *)(gDebugHudStrs + 0x32));
    headerColor2 = lbl_803698C0;
    fn_8014BB58(0x13A, 0x78, &headerColor2, (char *)(gDebugHudStrs + 0x37));
    headerColor3 = lbl_803698C4;
    fn_8014BB58(0x10A, 0x20, &headerColor3, (char *)(gDebugHudStrs + 0x3B));
    headerColor4 = lbl_803698C8;
    fn_8014BB58(0x10A, 0x90, &headerColor4, (char *)(gDebugHudStrs + 0x3F));
    headerColor5 = lbl_803698CC;
    fn_8014BB58(0x10A, 0x40, &headerColor5, (char *)(gDebugHudStrs + 0x43));

    groupA[0] = 0;
    groupA[1] = 0;
    groupA[2] = 0;
    groupB[0] = 0;
    groupB[1] = 0;
    groupB[2] = 0;
    groupB[3] = 0;
    groupB[4] = 0;
    groupB[5] = 0;
    groupB[6] = 0;
    groupB[7] = 0;
    groupC[0] = 0;
    groupC[1] = 0;
    groupC[2] = 0;
    groupC[3] = 0;
    groupC[4] = 0;
    groupC[5] = 0;
    groupC[6] = 0;
    groupC[7] = 0;
    groupC[8] = 0;
    groupC[9] = 0;
    groupC[10] = 0;
    groupC[11] = 0;
    groupC[12] = 0;
    groupC[13] = 0;
    groupC[14] = 0;
    groupC[15] = 0;
    groupC[16] = 0;
    groupC[17] = 0;
    groupC[18] = 0;
    groupC[19] = 0;
    groupC[20] = 0;
    groupC[21] = 0;
    groupC[22] = 0;
    groupC[23] = 0;
    groupC[24] = 0;
    groupC[25] = 0;
    groupC[26] = 0;
    groupC[27] = 0;
    groupC[28] = 0;
    groupC[29] = 0;
    groupC[30] = 0;
    groupC[31] = 0;
    groupC[32] = 0;
    groupC[33] = 0;
    groupC[34] = 0;
    groupC[35] = 0;
    groupC[36] = 0;
    groupC[37] = 0;
    groupC[38] = 0;
    groupC[39] = 0;
    groupAPtr = groupA;
    groupBPtr = groupB;
    groupCPtr = groupC;
    Prim2D_Begin();
    Prim2D_SetTex(0, 0);
    Prim2D_PrepareTex();

    fxChannelsBase = gFxChannels;
    /* Channel group 1: gFxChannels, 4 slots. */
    for (i = 0; i < 4; i++) {
        channel = fxChannelsBase + (u8)i * 0x30;
        active = 0;
        if ((channel[0x0C] & 1) != 0) {
            virtualTable = *(void **)(channel + 8);
            check = *(u32 (**)(void *))((u8 *)virtualTable + 8);
            if ((u8)check(channel) != 0) {
                active = 1;
            }
        }
        if (active != 0) {
            record = *(u8 **)channel;
            channelId = channel[4];
            kind = record[5] & 3;
            switch (kind) {
                case 0: baseId = 0xB; break;
                case 1: baseId = 3; break;
                case 2: baseId = 0; break;
                default: baseId = 0; break;
            }
            groupY = (i + 0) << 3;
            barY = groupY + 0x23;
            targetY = ((baseId + (u8)channelId) << 3) + 0x20;
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            phase = 7 - (Game_GetFrameCount() & 7);
            span = (targetY + 3 - barY) / 8;
            cumulative = 0;
            for (j = 0; j < 8; j++) {
                xLeft = (f32)((j * 6) + 0x103);
                yLeft = (f32)(barY + cumulative);
                xRight = (f32)(((j + 1) * 6) + 0x103);
                yRight = (f32)(barY + ((j + 1) * span));
                brightness = (u8)(((phase + j) & 7) << 5);
                Prim2D_AddPrim(4);
                Prim2D_SetPosCorners(xLeft, yLeft, xRight, yRight);
                Prim2D_SetColor(0xFF, brightness, brightness, 0xFF);
                Prim2D_EndPrim();
                Prim2D_AddPrim(4);
                Prim2D_SetPosCorners(xLeft, lbl_80369900 + yLeft, xRight, lbl_80369900 + yRight);
                Prim2D_SetColor(0xFF, brightness, brightness, 0xFF);
                Prim2D_EndPrim();
                cumulative += span;
            }
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369918, (f32)(groupY + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369920, (f32)(groupY + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
            label = *(char **)record;
            len = strlen(label);
            textColor0 = lbl_803698D0;
            fn_8014BB58(0x100 - (len << 3), groupY + 0x20, &textColor0, label);
            switch (kind) {
                case 0:
                    groupC[channelId] = 1;
                    break;
                case 1:
                    groupB[channelId] = 1;
                    break;
                case 2:
                    groupA[channelId] = 1;
                    break;
            }
        } else if ((channel[0xC] & 1) != 0) {
            record = *(u8 **)channel;
            label = *(char **)record;
            len = strlen(label);
            groupY = (i + 0) << 3;
            textColor1 = lbl_803698D4;
            fn_8014BB58(0x100 - (len << 3), groupY + 0x20, &textColor1, label);
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369918, (f32)(groupY + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369920, (f32)(groupY + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
        } else {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369918, (f32)(((i + 0) << 3) + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0xC0, 0xA0, 0x40, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369920, (f32)(((i + 0) << 3) + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
        }
    }

    /* Channel group 2: gSeCueSlots, 28 slots. */
    for (i = 0; i < 28; i++) {
        channel = gSeCueSlots + (u8)i * 0x30;
        active = 0;
        if ((channel[0x0C] & 1) != 0) {
            virtualTable = *(void **)(channel + 8);
            check = *(u32 (**)(void *))((u8 *)virtualTable + 8);
            if ((u8)check(channel) != 0) {
                active = 1;
            }
        }
        if (active != 0) {
            record = *(u8 **)channel;
            channelId = channel[4];
            kind = record[5] & 3;
            switch (kind) {
                case 0: baseId = 0xB; break;
                case 1: baseId = 3; break;
                case 2: baseId = 0; break;
                default: baseId = 0; break;
            }
            groupY = (i + 14) << 3;
            barY = groupY + 0x23;
            targetY = ((baseId + (u8)channelId) << 3) + 0x20;
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            phase = 7 - (Game_GetFrameCount() & 7);
            span = (targetY + 3 - barY) / 8;
            cumulative = 0;
            for (j = 0; j < 8; j++) {
                xLeft = (f32)((j * 6) + 0x103);
                yLeft = (f32)(barY + cumulative);
                xRight = (f32)(((j + 1) * 6) + 0x103);
                yRight = (f32)(barY + ((j + 1) * span));
                brightness = (u8)(((phase + j) & 7) << 5);
                Prim2D_AddPrim(4);
                Prim2D_SetPosCorners(xLeft, yLeft, xRight, yRight);
                Prim2D_SetColor(0xFF, brightness, brightness, 0xFF);
                Prim2D_EndPrim();
                Prim2D_AddPrim(4);
                Prim2D_SetPosCorners(xLeft, lbl_80369900 + yLeft, xRight, lbl_80369900 + yRight);
                Prim2D_SetColor(0xFF, brightness, brightness, 0xFF);
                Prim2D_EndPrim();
                cumulative += span;
            }
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369918, (f32)(groupY + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369920, (f32)(groupY + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
            label = *(char **)record;
            len = strlen(label);
            textColor2 = lbl_803698D8;
            fn_8014BB58(0x100 - (len << 3), groupY + 0x20, &textColor2, label);
            switch (kind) {
                case 0:
                    groupC[channelId] = 1;
                    break;
                case 1:
                    groupB[channelId] = 1;
                    break;
                case 2:
                    groupA[channelId] = 1;
                    break;
            }
        } else if ((channel[0xC] & 1) != 0) {
            record = *(u8 **)channel;
            label = *(char **)record;
            len = strlen(label);
            groupY = (i + 14) << 3;
            textColor3 = lbl_803698DC;
            fn_8014BB58(0x100 - (len << 3), groupY + 0x20, &textColor3, label);
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369918, (f32)(groupY + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369920, (f32)(groupY + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
        } else {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369918, (f32)(((i + 14) << 3) + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0x40, 0x80, 0xC0, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369920, (f32)(((i + 14) << 3) + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
        }
    }

    /* Channel group 3: gFxSlots, 10 slots. */
    for (i = 0; i < 10; i++) {
        channel = gFxSlots + (u8)i * 0x30;
        active = 0;
        if ((channel[0x0C] & 1) != 0) {
            virtualTable = *(void **)(channel + 8);
            check = *(u32 (**)(void *))((u8 *)virtualTable + 8);
            if ((u8)check(channel) != 0) {
                active = 1;
            }
        }
        if (active != 0) {
            record = *(u8 **)channel;
            channelId = channel[4];
            kind = record[5] & 3;
            switch (kind) {
                case 0: baseId = 0xB; break;
                case 1: baseId = 3; break;
                case 2: baseId = 0; break;
                default: baseId = 0; break;
            }
            groupY = (i + 4) << 3;
            barY = groupY + 0x23;
            targetY = ((baseId + (u8)channelId) << 3) + 0x20;
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            phase = 7 - (Game_GetFrameCount() & 7);
            span = (targetY + 3 - barY) / 8;
            cumulative = 0;
            for (j = 0; j < 8; j++) {
                xLeft = (f32)((j * 6) + 0x103);
                yLeft = (f32)(barY + cumulative);
                xRight = (f32)(((j + 1) * 6) + 0x103);
                yRight = (f32)(barY + ((j + 1) * span));
                brightness = (u8)(((phase + j) & 7) << 5);
                Prim2D_AddPrim(4);
                Prim2D_SetPosCorners(xLeft, yLeft, xRight, yRight);
                Prim2D_SetColor(0xFF, brightness, brightness, 0xFF);
                Prim2D_EndPrim();
                Prim2D_AddPrim(4);
                Prim2D_SetPosCorners(xLeft, lbl_80369900 + yLeft, xRight, lbl_80369900 + yRight);
                Prim2D_SetColor(0xFF, brightness, brightness, 0xFF);
                Prim2D_EndPrim();
                cumulative += span;
            }
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369918, (f32)(groupY + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369920, (f32)(groupY + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
            label = *(char **)record;
            len = strlen(label);
            textColor4 = lbl_803698E0;
            fn_8014BB58(0x100 - (len << 3), groupY + 0x20, &textColor4, label);
            switch (kind) {
                case 0:
                    groupC[channelId] = 1;
                    break;
                case 1:
                    groupB[channelId] = 1;
                    break;
                case 2:
                    groupA[channelId] = 1;
                    break;
            }
        } else if ((channel[0xC] & 1) != 0) {
            record = *(u8 **)channel;
            label = *(char **)record;
            len = strlen(label);
            groupY = (i + 4) << 3;
            textColor5 = lbl_803698E4;
            fn_8014BB58(0x100 - (len << 3), groupY + 0x20, &textColor5, label);
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369918, (f32)(groupY + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369920, (f32)(groupY + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
        } else {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369918, (f32)(((i + 4) << 3) + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0xC8, 0x0A, 0x0A, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369920, (f32)(((i + 4) << 3) + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
        }
    }

    /* Three final status tables. */
    for (i = 0; i < 3; i++) {
        if (*groupAPtr) {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369928, (f32)((i << 3) + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_8036992C, (f32)((i << 3) + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
        } else {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369928, (f32)((i << 3) + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0xC8, 0x80, 0x80, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_8036992C, (f32)((i << 3) + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
        }
        groupAPtr++;
    }
    for (i = 0; i < 8; i++) {
        if (*groupBPtr) {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369928, (f32)(((i + 3) << 3) + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_8036992C, (f32)(((i + 3) << 3) + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
        } else {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369928, (f32)(((i + 3) << 3) + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0x80, 0xC0, 0x80, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_8036992C, (f32)(((i + 3) << 3) + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
        }
        groupBPtr++;
    }
    for (i = 0; i < 40; i++) {
        if (*groupCPtr) {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369928, (f32)(((i + 0xB) << 3) + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_8036992C, (f32)(((i + 0xB) << 3) + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
        } else {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_80369928, (f32)(((i + 0xB) << 3) + 0x21), lbl_8036991C, lbl_8036991C);
            Prim2D_SetColor(0x80, 0x80, 0xFF, 0xFF);
            Prim2D_EndPrim();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_8036992C, (f32)(((i + 0xB) << 3) + 0x20), lbl_80369924, lbl_80369924);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_EndPrim();
        }
        groupCPtr++;
    }
}

/* Draw the debug guide rectangle and optional T/E markers from gUiInputFlags. */
void Debug_DrawGuideFrame(void) {
    void Prim2D_SetText(u8 *);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Prim2D_EndPrim(void);
    extern u8 gDebugHudStrs[];
    extern s32 gUiInputFlags;
    extern f32 lbl_803698FC;
    extern f32 lbl_80369900;
    extern f32 lbl_8036992C;
    extern f32 lbl_80369930;
    extern f32 lbl_80369934;
    extern f32 lbl_80369938;
    extern f32 lbl_8036993C;
    extern f32 lbl_80369940;
    extern f32 lbl_80369944;
    extern f32 lbl_80369948;
    extern f32 lbl_8036994C;
    extern f32 lbl_80369950;
    extern f32 lbl_80369954;
    extern f32 lbl_80369958;
    extern f32 lbl_8036995C;
    extern f32 lbl_80369960;
    extern f32 lbl_80369964;
    extern f32 lbl_80369968;

    Prim2D_Begin();
    Prim2D_SetTransform(lbl_803698FC, lbl_803698FC, lbl_803698FC, lbl_80369900);
    Prim2D_SetTex(0, 0);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_80369930, lbl_80369934, lbl_80369938, lbl_80369934);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_80369938, lbl_80369934, lbl_80369938, lbl_8036993C);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_80369938, lbl_8036993C, lbl_80369930, lbl_8036993C);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_80369930, lbl_80369934, lbl_80369930, lbl_8036993C);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_80369940, lbl_80369944, lbl_80369948, lbl_80369944);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_8036992C, lbl_8036994C, lbl_8036992C, lbl_80369950);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_80369954, lbl_80369944, lbl_80369958, lbl_80369944);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_8036995C, lbl_80369960, lbl_8036995C, lbl_80369964);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTex(0, 3);
    Prim2D_PrepareTex();
    if (gUiInputFlags & 2) {
        Prim2D_AddPrim(7);
        Prim2D_SetPos(lbl_80369930, lbl_80369934);
        Prim2D_SetText(gDebugHudStrs + 0x47);
        Prim2D_EndPrim();
    }
    if (gUiInputFlags & 1) {
        Prim2D_AddPrim(7);
        Prim2D_SetPos(lbl_80369968, lbl_80369934);
        Prim2D_SetText(gDebugHudStrs + 0x49);
        Prim2D_EndPrim();
    }
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
void fn_8009D0E8(s32 arg0, s32 arg1) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    s32 sprintf(char *, char *, ...);
    extern u8 gDebugHudStrs[];
    extern u8 lbl_803121C8[];
    extern f64 lbl_80369908;
    extern f32 lbl_803698FC, lbl_80369900;
    extern f32 lbl_8036996C, lbl_80369930, lbl_80369970, lbl_80369968;
    extern f32 lbl_80369974, lbl_80369978, lbl_8036997C, lbl_80369980;
    extern f32 lbl_80369984, lbl_80369988, lbl_8036998C, lbl_80369990;
    extern f32 lbl_80369994, lbl_80369998, lbl_8036999C, lbl_803699A0;
    extern f32 lbl_803699A4, lbl_803699A8, lbl_803699AC, lbl_803699B0;
    extern f32 lbl_803699B4, lbl_803699B8, lbl_803699BC, lbl_803699C0;
    extern f32 lbl_803699C4, lbl_803699C8, lbl_803699CC;

    char sp368[0x20]; char sp348[0x20]; char sp328[0x20]; char sp308[0x20];
    char sp2E8[0x20]; char sp2C8[0x20]; char sp2A8[0x20]; char sp288[0x20];
    char sp268[0x20]; char sp248[0x20]; char sp228[0x20]; char sp208[0x20];
    char sp1E8[0x20]; char sp1C8[0x20]; char sp1A8[0x20]; char sp188[0x20];
    char sp168[0x20]; char sp148[0x20]; char sp128[0x20]; char sp108[0x20];
    char spE8[0x20]; char spC8[0x20]; char spA8[0x20]; char sp88[0x20];
    char sp68[0x20]; char sp48[0x20]; char sp28[0x20]; char sp8[0x20];

    Prim2D_Begin();
    Prim2D_SetTransform((f32)arg0, (f32)arg1, lbl_803698FC, lbl_80369900);
    Prim2D_SetTex(0, 0x23);
    Prim2D_PrepareTex();

    sprintf(sp368, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x54, *(s32 *)(lbl_803121C8 + 0x00));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803698FC); Prim2D_SetText(sp368); Prim2D_EndPrim();
    sprintf(sp348, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x5D, *(s32 *)(lbl_803121C8 + 0x04));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_8036996C); Prim2D_SetText(sp348); Prim2D_EndPrim();
    sprintf(sp328, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x67, *(s32 *)(lbl_803121C8 + 0x08));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_80369930); Prim2D_SetText(sp328); Prim2D_EndPrim();
    sprintf(sp308, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x72, *(s32 *)(lbl_803121C8 + 0x0C));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_80369970); Prim2D_SetText(sp308); Prim2D_EndPrim();
    sprintf(sp2E8, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x7E, *(s32 *)(lbl_803121C8 + 0x10));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_80369968); Prim2D_SetText(sp2E8); Prim2D_EndPrim();
    sprintf(sp2C8, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x8B, *(s32 *)(lbl_803121C8 + 0x14));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_80369974); Prim2D_SetText(sp2C8); Prim2D_EndPrim();
    sprintf(sp2A8, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x97, *(s32 *)(lbl_803121C8 + 0x18));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_80369978); Prim2D_SetText(sp2A8); Prim2D_EndPrim();
    sprintf(sp288, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0xA3, *(s32 *)(lbl_803121C8 + 0x1C));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_8036997C); Prim2D_SetText(sp288); Prim2D_EndPrim();
    sprintf(sp268, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0xB1, *(s32 *)(lbl_803121C8 + 0x20));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_80369980); Prim2D_SetText(sp268); Prim2D_EndPrim();
    sprintf(sp248, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0xBF, *(s32 *)(lbl_803121C8 + 0x24));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_80369984); Prim2D_SetText(sp248); Prim2D_EndPrim();
    sprintf(sp228, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0xC9, *(s32 *)(lbl_803121C8 + 0x28));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_80369988); Prim2D_SetText(sp228); Prim2D_EndPrim();
    sprintf(sp208, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0xDA, *(s32 *)(lbl_803121C8 + 0x2C));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_8036998C); Prim2D_SetText(sp208); Prim2D_EndPrim();
    sprintf(sp1E8, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0xEE, *(s32 *)(lbl_803121C8 + 0x40));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_80369990); Prim2D_SetText(sp1E8); Prim2D_EndPrim();
    sprintf(sp1C8, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0xF5, *(s32 *)(lbl_803121C8 + 0x44));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_80369994); Prim2D_SetText(sp1C8); Prim2D_EndPrim();
    sprintf(sp1A8, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0xFD, *(s32 *)(lbl_803121C8 + 0x48));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_80369998); Prim2D_SetText(sp1A8); Prim2D_EndPrim();
    sprintf(sp188, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x105, *(s32 *)(lbl_803121C8 + 0x4C));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_8036999C); Prim2D_SetText(sp188); Prim2D_EndPrim();
    sprintf(sp168, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x111, *(s32 *)(lbl_803121C8 + 0x50));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803699A0); Prim2D_SetText(sp168); Prim2D_EndPrim();
    sprintf(sp148, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x119, *(s32 *)(lbl_803121C8 + 0x54));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803699A4); Prim2D_SetText(sp148); Prim2D_EndPrim();
    sprintf(sp128, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x122, *(s32 *)(lbl_803121C8 + 0x58));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803699A8); Prim2D_SetText(sp128); Prim2D_EndPrim();
    sprintf(sp108, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x12B, *(s32 *)(lbl_803121C8 + 0x5C));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803699AC); Prim2D_SetText(sp108); Prim2D_EndPrim();
    sprintf(spE8, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x134, *(s32 *)(lbl_803121C8 + 0x60));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803699B0); Prim2D_SetText(spE8); Prim2D_EndPrim();
    sprintf(spC8, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x140, *(s32 *)(lbl_803121C8 + 0x64));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803699B4); Prim2D_SetText(spC8); Prim2D_EndPrim();
    sprintf(spA8, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x147, *(s32 *)(lbl_803121C8 + 0x84));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803699B8); Prim2D_SetText(spA8); Prim2D_EndPrim();
    sprintf(sp88, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x155, *(s32 *)(lbl_803121C8 + 0x88));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803699BC); Prim2D_SetText(sp88); Prim2D_EndPrim();
    sprintf(sp68, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x164, *(s32 *)(lbl_803121C8 + 0x8C));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803699C0); Prim2D_SetText(sp68); Prim2D_EndPrim();
    sprintf(sp48, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x172, *(s32 *)(lbl_803121C8 + 0x90));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803699C4); Prim2D_SetText(sp48); Prim2D_EndPrim();
    sprintf(sp28, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x181, *(s32 *)(lbl_803121C8 + 0x94));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803699C8); Prim2D_SetText(sp28); Prim2D_EndPrim();
    sprintf(sp8, (char *)gDebugHudStrs + 0x4B, (char *)gDebugHudStrs + 0x18F, *(s32 *)(lbl_803121C8 + 0x98));
    Prim2D_AddPrim(0xA); Prim2D_SetPos(lbl_803698FC, lbl_803699CC); Prim2D_SetText(sp8); Prim2D_EndPrim();

    *(s32 *)(lbl_803121C8 + 0xA0) = *(s32 *)(lbl_803121C8 + 0x9C);
}
#pragma pop
void fn_8009D95C(s32 arg0, s32 arg1) {
    void Prim2D_SetText(void *);
    void Prim2D_SetCornerColors(u32 *, u32 *, u32 *, u32 *);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void sprintf(void *, void *, s32, ...);
    extern u32 lbl_80312100[];
    extern u32 lbl_80369890, lbl_80369894, lbl_80369898, lbl_8036989C;
    extern u32 lbl_803698A0, lbl_803698A4, lbl_803698A8, lbl_803698AC;
    extern u32 lbl_803698B0, lbl_803698B4;
    extern f32 lbl_803698F8, lbl_803698FC, lbl_80369900;
    extern f32 lbl_80369904, lbl_8036996C, lbl_803699D0, lbl_803699D4, lbl_803699D8;
    extern f32 lbl_803699DC, lbl_803699E0, lbl_803699E4;
    extern f32 lbl_80369930, lbl_80369968, lbl_80369970;
    extern u8 gDebugHudStrs[];
    s32 x;
    s32 y;
    u32 *tbl;
    f32 f31;
    f32 f30;
    f32 f29;
    u32 c01, c11, c02, c12, c03, c13, c04, c14, c05, c15;
    u32 a, b, c, d;
    u32 bus, rate, ticks;
    char buf[0x80];
    s32 i;

    x = arg0;
    y = arg1;
    Prim2D_Begin();
    Prim2D_SetTransform((f32)x, (f32)(y + 0x28), lbl_803698FC, lbl_80369900);
    Prim2D_SetTex(0, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_803698FC, lbl_8036996C, lbl_803699D0, lbl_8036996C);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetPosCorners(lbl_803698FC, lbl_803698FC, lbl_803698FC, lbl_803699D4);
    Prim2D_EndPrim();

    tbl = lbl_80312100;
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 125000u;
    ticks = tbl[2] << 3;
    c01 = lbl_80369894;
    c11 = lbl_80369890;
    f31 = lbl_803699D0 * ((f32)(ticks / rate) / lbl_803699D8);
    Prim2D_AddPrim(3);
    Prim2D_SetRect(lbl_803698FC, lbl_803698FC, f31, lbl_8036996C);
    Prim2D_EmitQuad();
    a = c11; b = c11; c = c01; d = c01;
    Prim2D_SetCornerColors(&a, &b, &c, &d);
    Prim2D_EndPrim();

    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 125000u;
    ticks = tbl[3] << 3;
    f30 = lbl_803698FC + f31;
    c02 = lbl_8036989C;
    c12 = lbl_80369898;
    f31 = lbl_803699D0 * ((f32)(ticks / rate) / lbl_803699D8);
    Prim2D_AddPrim(3);
    Prim2D_SetRect(f30, lbl_803698FC, f31, lbl_8036996C);
    Prim2D_EmitQuad();
    a = c12; b = c12; c = c02; d = c02;
    Prim2D_SetCornerColors(&a, &b, &c, &d);
    Prim2D_EndPrim();

    f30 = f30 + f31;
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 125000u;
    ticks = tbl[4] << 3;
    c03 = lbl_803698A4;
    c13 = lbl_803698A0;
    f31 = lbl_803699D0 * ((f32)(ticks / rate) / lbl_803699D8);
    Prim2D_AddPrim(3);
    Prim2D_SetRect(f30, lbl_803698FC, f31, lbl_8036996C);
    Prim2D_EmitQuad();
    a = c13; b = c13; c = c03; d = c03;
    Prim2D_SetCornerColors(&a, &b, &c, &d);
    Prim2D_EndPrim();

    f29 = f30 + f31;
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 125000u;
    ticks = tbl[7] << 3;
    c04 = lbl_803698AC;
    c14 = lbl_803698A8;
    f31 = lbl_803699D0 * ((f32)(ticks / rate) / lbl_803699D8);
    Prim2D_AddPrim(3);
    Prim2D_SetRect(f29, lbl_803698FC, f31, lbl_8036996C);
    Prim2D_EmitQuad();
    a = c14; b = c14; c = c04; d = c04;
    Prim2D_SetCornerColors(&a, &b, &c, &d);
    Prim2D_EndPrim();

    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 125000u;
    ticks = tbl[1] << 3;
    c05 = lbl_803698B4;
    c15 = lbl_803698B0;
    f30 = lbl_803699D0 * ((f32)(ticks / rate) / lbl_803699D8);
    Prim2D_AddPrim(3);
    Prim2D_SetRect(f29 + f31, lbl_803698FC, f30, lbl_8036996C);
    Prim2D_EmitQuad();
    a = c15; b = c15; c = c05; d = c05;
    Prim2D_SetCornerColors(&a, &b, &c, &d);
    Prim2D_EndPrim();

    Prim2D_AddPrim(1);
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 125000u;
    ticks = tbl[6] << 3;
    Prim2D_SetRect(lbl_803698FC, lbl_8036996C,
                lbl_803699D0 * ((f32)(ticks / rate) / lbl_803699D8),
                lbl_803699DC);
    Prim2D_SetColor(0xFF, 0xA0, 0xFF, 0xFF);
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_SetTransform((f32)x, (f32)y, lbl_803698FC, lbl_80369900);
    Prim2D_SetTex(0, 0x23);
    Prim2D_PrepareTex();

    Prim2D_AddPrim(0xA);
    Prim2D_SetPos(lbl_803698FC, lbl_803698FC);
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 125000u;
    ticks = tbl[2] << 3;
    {
        u32 qq = ticks / rate;
        sprintf(buf, gDebugHudStrs + 0x199,
                    (s32)(lbl_803698F8 * ((f32)qq / lbl_803699D8)),
                    (f32)qq / lbl_80369904);
    }
    Prim2D_SetColor(0x80, 0xC8, 0xFF, 0xFF);
    Prim2D_SetText(buf);
    Prim2D_EndPrim();

    Prim2D_AddPrim(0xA);
    Prim2D_SetPos(lbl_803698FC, lbl_8036996C);
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 125000u;
    ticks = tbl[3] << 3;
    {
        u32 qq = ticks / rate;
        sprintf(buf, gDebugHudStrs + 0x1AF,
                    (s32)(lbl_803698F8 * ((f32)qq / lbl_803699D8)),
                    (f32)qq / lbl_80369904);
    }
    Prim2D_SetColor(0xA0, 0xFF, 0xA0, 0xFF);
    Prim2D_SetText(buf);
    Prim2D_EndPrim();

    if ((f32)tbl[7] > lbl_803699E0) {
        Prim2D_AddPrim(0xA);
        Prim2D_SetPos(lbl_803698FC, lbl_803699E4);
        bus = *(u32 *)0x800000F8 >> 2;
        rate = bus / 125000u;
        ticks = tbl[7] << 3;
        {
            u32 qq = ticks / rate;
            sprintf(buf, gDebugHudStrs + 0x1C5,
                        (s32)(lbl_803698F8 * ((f32)qq / lbl_803699D8)),
                        (f32)qq / lbl_80369904);
        }
        Prim2D_SetColor(0xFF, 0xA0, 0xA0, 0xFF);
        Prim2D_SetText(buf);
        Prim2D_EndPrim();
    }

    Prim2D_AddPrim(0xA);
    Prim2D_SetPos(lbl_803698FC, lbl_80369930);
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 125000u;
    ticks = tbl[1] << 3;
    {
        u32 qq = ticks / rate;
        sprintf(buf, gDebugHudStrs + 0x1DB,
                    (s32)(lbl_803698F8 * ((f32)qq / lbl_803699D8)),
                    (f32)qq / lbl_80369904);
    }
    Prim2D_SetColor(0xFF, 0xFF, 0x80, 0xFF);
    Prim2D_SetText(buf);
    Prim2D_EndPrim();

    Prim2D_AddPrim(0xA);
    Prim2D_SetPos(lbl_803698FC, lbl_80369970);
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 125000u;
    ticks = tbl[5] << 3;
    {
        u32 qq = ticks / rate;
        sprintf(buf, gDebugHudStrs + 0x1F1,
                    (s32)(lbl_803698F8 * ((f32)qq / lbl_803699D8)),
                    (f32)qq / lbl_80369904);
    }
    Prim2D_SetText(buf);
    Prim2D_EndPrim();

    Prim2D_AddPrim(0xA);
    Prim2D_SetPos(lbl_803698FC, lbl_80369968);
    bus = *(u32 *)0x800000F8 >> 2;
    rate = bus / 125000u;
    ticks = tbl[6] << 3;
    {
        u32 qq = ticks / rate;
        sprintf(buf, gDebugHudStrs + 0x207,
                    (s32)(lbl_803698F8 * ((f32)qq / lbl_803699D8)),
                    (f32)qq / lbl_80369904);
    }
    Prim2D_SetColor(0xFF, 0xB4, 0xFF, 0xFF);
    Prim2D_SetText(buf);
    Prim2D_EndPrim();

    for (i = 0; i < 8; i++) {
        if (*(u32 *)((u8 *)tbl + 0x24 + i * 4) != 0) {
            Prim2D_Begin();
            Prim2D_SetTransform((f32)x, (f32)y, lbl_803698FC, lbl_80369900);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(0xA);
            Prim2D_SetPos(lbl_803698FC, (f32)(-0xC - i * 8));
            sprintf(buf, gDebugHudStrs + 0x21D, i);
            Prim2D_SetText(buf);
            Prim2D_EndPrim();
        }
    }
    for (i = 0; i < 4; i++) {
        if (*(u32 *)((u8 *)tbl + 0x64 + i * 4) != 0) {
            Prim2D_Begin();
            Prim2D_SetTransform((f32)x, (f32)y, lbl_803698FC, lbl_80369900);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(0xA);
            Prim2D_SetPos(lbl_803698FC, (f32)(-0xC - i * 8));
            sprintf(buf, gDebugHudStrs + 0x234, i,
                        *(u32 *)((u8 *)tbl + 0x64 + i * 4));
            Prim2D_SetText(buf);
            Prim2D_EndPrim();
        }
    }
}
#pragma use_lmw_stmw reset
void fn_8009E574(void) {
    extern u8 lbl_80312100[];
    lbl_80312100[0xc4] = 1;
}

void fn_8009E588(void) {
    s32 fn_8006EB9C(void);
    void fn_8021F1B8(s32, void *, void *);
    s32 spC;
    s32 sp8;

    fn_8021F1B8(fn_8006EB9C(), &sp8, &spC);
}

void fn_8009E5B4(void) {
    s32 fn_8006EB9C(void *);
    void fn_8021F1B8(s32, void *, void *);
    extern u8 lbl_80312100[];
    s32 sp8;

    lbl_80312100[0xC4] = 0;
    fn_8021F1B8(fn_8006EB9C(lbl_80312100), &sp8, lbl_80312100 + 0xB4);
}

void fn_8009E5F8(void) {
    extern u8 lbl_80312100[];
    *(s32 *)(lbl_80312100 + 0x24) = 0;
    *(s32 *)(lbl_80312100 + 0x28) = 0;
    *(s32 *)(lbl_80312100 + 0x2C) = 0;
    *(s32 *)(lbl_80312100 + 0x30) = 0;
    *(s32 *)(lbl_80312100 + 0x34) = 0;
    *(s32 *)(lbl_80312100 + 0x38) = 0;
    *(s32 *)(lbl_80312100 + 0x3C) = 0;
    *(s32 *)(lbl_80312100 + 0x40) = 0;
    *(s32 *)(lbl_80312100 + 0x64) = 0;
    *(s32 *)(lbl_80312100 + 0x68) = 0;
    *(s32 *)(lbl_80312100 + 0x6C) = 0;
    *(s32 *)(lbl_80312100 + 0x70) = 0;
}

void fn_8009E638(void) {
    extern u8 lbl_80312100[];
    *(s32 *)(lbl_80312100 + 0x1c) = 0;
}

void fn_8009E64C(void) {
    u32 OSGetTick(void);
    extern u8 lbl_80312100[];
    u8 *p = lbl_80312100;

    *(u32 *)(p + 0x1c) = OSGetTick() - *(u32 *)(p + 0x1c);
}

void fn_8009E688(void) {
    extern u16 lbl_80312100[];
    *(u32 *)((u8 *)lbl_80312100 + 0x1c) = OSGetTick();
}

void fn_8009E6B4(void) {
    u32 OSGetTick(void);
    extern u8 lbl_80312100[];
    u8 *p = lbl_80312100;

    *(u32 *)(p + 0x10) = OSGetTick() - *(u32 *)(p + 0x10);
}

void fn_8009E6F0(void) {
    extern u16 lbl_80312100[];
    *(u32 *)((u8 *)lbl_80312100 + 0x10) = OSGetTick();
}

void fn_8009E71C(void) {
    u32 OSGetTick(void);
    void fn_800070C8(void *, void *, void *, void *);
    extern u8 lbl_80312100[];
    u8 *p = lbl_80312100;

    *(u32 *)(p + 0xC) = OSGetTick() - *(u32 *)(p + 0xC);
    fn_800070C8(p + 0xB8, p + 0xBC, p + 0xBE, p + 0xC0);
}

void fn_8009E774(void) {
    extern u16 lbl_80312100[];
    *(u32 *)((u8 *)lbl_80312100 + 0xc) = OSGetTick();
}

void fn_8009E7A0(void) {
    u32 OSGetTick(void);
    extern u8 lbl_80312100[];
    u8 *p = lbl_80312100;

    *(u32 *)(p + 8) = OSGetTick() - *(u32 *)(p + 8);
}

void fn_8009E7DC(void) {
    extern u16 lbl_80312100[];
    *(u32 *)((u8 *)lbl_80312100 + 0x8) = OSGetTick();
}

void fn_8009E808(void) {
    u32 OSGetTick(void);
    extern u8 lbl_80312100[];
    u8 *p = lbl_80312100;

    *(u32 *)(p + 4) = OSGetTick() - *(u32 *)(p + 4);
}

void fn_8009E844(void) {
    extern u16 lbl_80312100[];
    *(u32 *)((u8 *)lbl_80312100 + 0x4) = OSGetTick();
}

void fn_8009E870(void) {
s32 OSGetTick(void);
s32 fn_8006EB9C(void);
void fn_8021F1B8(s32,void *,void *);
void fn_80225A4C(void *,void *);
void fn_80225204(s32,s32);
void fn_80225C04(void *,void *,void *,void *,void *,void *);
void fn_80225D3C(void);
extern u8 lbl_80312100[];
extern u8 lbl_803121C8[];
extern s32 lbl_80289F28[];
extern s32 lbl_80289F5C[];
s32 sp8;
u8 *p;
s32 tick=OSGetTick();
*(s32 *)(lbl_80312100+0x18)=tick-*(s32 *)lbl_80312100;
p=lbl_803121C8;
fn_80225A4C(p+*(s16 *)(p+0x80)*4,p+*(s16 *)(p+0x82)*4+0x40);
++*(s16 *)(p+0x80);
if(lbl_80289F28[*(s16 *)(p+0x80)]<0) *(s16 *)(p+0x80)=0;
++*(s16 *)(p+0x82);
if(lbl_80289F5C[*(s16 *)(p+0x82)]<0) *(s16 *)(p+0x82)=0;
fn_80225204(lbl_80289F28[*(s16 *)(p+0x80)],lbl_80289F5C[*(s16 *)(p+0x82)]);
fn_80225C04(lbl_803121C8+0x84,lbl_803121C8+0x88,lbl_803121C8+0x8C,lbl_803121C8+0x90,lbl_803121C8+0x94,lbl_803121C8+0x98);
fn_8021F1B8(fn_8006EB9C(),&sp8,lbl_803121C8+0xA4);
fn_80225D3C();
}

void fn_8009E9A0(void) {
    s32 OSGetTick();
    extern s32 lbl_80312100[];
    lbl_80312100[5] = OSGetTick() - lbl_80312100[0];
}

void fn_8009E9D0(void) {
    s32 OSGetTick(void);
    s32 fn_80225BF4(s32);
    s32 fn_8006EB9C(void);
    void fn_8021F1B8(s32, void *, void *);
    extern u8 lbl_80312100[];
    extern u8 lbl_803121C8[];
    s32 sp8;
    s32 tick;

    tick = OSGetTick();
    *(s32 *)lbl_80312100 = tick;
    fn_80225BF4(tick);
    fn_8021F1B8(fn_8006EB9C(), &sp8, lbl_803121C8 + 0x9C);
}

