/* Functions from 0x80120CCC to 0x80127D80, found by decomp-toolkit. */
#include "common.h"

typedef struct SkyVector { f32 x, y, z; } SkyVector;
typedef struct SkyProc {
 u8 pad[0x30];
 void *parent;
 s32 skyIndex;
 SkyVector position;
 f32 scale;
 f32 speed;
} SkyProc;

extern f64 lbl_8036A2C8;

typedef struct {
    s32 field_0x84;
} SomeStruct;

extern f32 lbl_8036A30C;
volatile f32 GXRegs_8036A30C[0x800] : 0xCC010000;

void UiPanel_ClearShowFlags(u16 *arg0) {
    *arg0 &= ~0x130;
}

void UiPanel_ClearFlags(void *arg0) {
    extern u32 gUiInputFlags;

    *(u16 *)((u8 *)arg0 + 0x0) = 0;
    *(u16 *)((u8 *)arg0 + 0x2) = 0;
    gUiInputFlags &= 0xFFFFFFFD;
}

void UiPanel_PollSkip(u16 *flags) {
    /* On B press, set skip bit if no blocking talk/tooltip and the hold counter is high enough. */
    u32 Process_FindByName(void *);
    void *Process_Find(void *);
    extern void *gPadInput;
    extern u8 gEventProcNames[];
    extern u32 gUiInputFlags;
    extern u8 gUiTooltipProc[];
    s32 held;
    void *tip;
    u8 blocked;
    u8 alpha;

    if (!(*flags & 8)) {
        held = *(s32 *)((u8 *)gPadInput + 4);
        if ((held & (*(s32 *)((u8 *)gPadInput + 8) ^ held) & 0x200) &&
            Process_FindByName(gEventProcNames + 0x34) == 0) {
            if (gUiInputFlags & 3) {
                blocked = 0;
            } else {
                tip = Process_Find(gUiTooltipProc);
                if (tip == NULL) {
                    blocked = 0;
                } else {
                    alpha = *(u8 *)((u8 *)tip + 0x50);
                    if (alpha == 0 || alpha == 0xFF) {
                        blocked = 0;
                    } else {
                        blocked = 1;
                    }
                }
            }
            if (blocked == 0 && flags[1] >= 3) {
                *flags |= 4;
            }
        }
    }
}

void Obj_StartTintEase(void *arg0, s32 arg1) {
    void *Process_Create(void *, s32);
    extern u8 lbl_8029023C[];
    u8 temp_r31;
    u8 *temp_r3;

    temp_r31 = ((u8 *)arg0)[0x41];
    if (temp_r31 != (u8)arg1) {
        temp_r3 = Process_Create(lbl_8029023C, (s32)arg0);
        *(void **)(temp_r3 + 0x30) = arg0;
        temp_r3[0x36] = 0;
        temp_r3[0x37] = 4;
        temp_r3[0x34] = temp_r31;
        temp_r3[0x35] = (u8)arg1;
    }
}

/* Ease the target object's tint (+0x41) toward the end value; clear when done. */
void Obj_EaseTintProc(void *proc) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);

    *(u8 *)((u8 *)proc + 0x36) = (u8)(*(u8 *)((u8 *)proc + 0x36) + 1);
    *(s8 *)(*(u8 **)((u8 *)proc + 0x30) + 0x41) = (s8)Math_Ease(
        0,
        (f32)*(u8 *)((u8 *)proc + 0x34),
        (f32)*(u8 *)((u8 *)proc + 0x35),
        (f32)*(u8 *)((u8 *)proc + 0x36),
        (f32)*(u8 *)((u8 *)proc + 0x37));
    if (*(u8 *)((u8 *)proc + 0x36) == *(u8 *)((u8 *)proc + 0x37)) {
        Process_ClearFunc(proc);
    }
}

#pragma global_optimizer off
#pragma peephole on
#pragma scheduling on
void fn_80120F0C(void) {
    struct Flags {
        u16 a;
        u16 b;
    };
    extern struct Flags gUiPanelFlags;
    extern u32 gUiInputFlags;
    extern u8 gUiTooltipProc[];
    void *Process_Find(void *);
    void Process_Unlink(void);
    void Process_ClearFunc(void);
    u16 b;
    u16 a;
    struct Flags *p = &gUiPanelFlags;
    a = gUiPanelFlags.a;
    b = p->b;
    gUiInputFlags |= 2;
    if (!(a & 0x40)) {
        if ((u32)Process_Find(gUiTooltipProc) != 0U) {
            if (gUiInputFlags & 3) {
                Process_Unlink();
            } else {
                Process_ClearFunc();
            }
        }
    }
    gUiPanelFlags.a = a;
    p->b = b;
}
#pragma scheduling on
#pragma peephole on
#pragma global_optimizer on

void fn_80120F94(void)
{
    void *Process_Find(void *);
    void Process_Unlink(void);
    void Process_ClearFunc(void);
    extern u16 gUiPanelFlags;
    extern u32 gUiInputFlags;
    extern u8 gUiTooltipProc[];
    void *p;

    if ((gUiPanelFlags & 0x0040) == 0) {
        p = Process_Find(gUiTooltipProc);
        if (p != NULL) {
            if ((gUiInputFlags & 3) != 0) {
                Process_Unlink();
            } else {
                Process_ClearFunc();
            }
        }
    }
}

#pragma global_optimizer off
void Ui_SetTooltip(void *arg0, s16 arg1, s16 arg2, s32 arg3) {
    void *Process_Find(void *);
    void Process_Unlink(void *);
    void *Process_Create(void *, s32);
    void *fn_8007C378(void *);
    void strcpy(char *, char *);
    u8 Text_MeasureWidth(void *, f32, s32);
    extern u8 gUiTooltipProc[];
    extern u16 gUiPanelFlags;
    extern f32 lbl_8036A268;
    void *obj;
    f32 scale;

    obj = Process_Find(gUiTooltipProc);
    if (obj) {
        if (*(void **)((u8 *)obj + 0x44) == arg0) {
            if (*(s16 *)((u8 *)obj + 0x48) == arg1) {
                if (*(s16 *)((u8 *)obj + 0x4A) == arg2) {
                    return;
                }
            }
        }
        Process_Unlink(obj);
    }
    if (gUiPanelFlags & 0x40) {
        return;
    }
    obj = Process_Create(gUiTooltipProc, arg3);
    *(void **)((u8 *)obj + 0x44) = arg0;
    strcpy((char *)((u8 *)obj + 0x30), (char *)fn_8007C378(arg0));
    *(s16 *)((u8 *)obj + 0x48) = arg1;
    scale = lbl_8036A268;
    *(s16 *)((u8 *)obj + 0x4A) = arg2;
    *(u8 *)((u8 *)obj + 0x51) = Text_MeasureWidth((u8 *)obj + 0x30, scale, -1);
}
#pragma global_optimizer on
/* Draw the tooltip balloon sprite and its text when UI input is idle. */
void Ui_DrawTooltip(void *tip) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Prim2D_SetText(void *);
    void Prim2D_SetColorPacked(void *);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(u8);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Ui_LoadAtlasTex(void *, void *, s32);
    u32 *Ui_GetColor(s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    extern u32 gUiInputFlags;
    extern void *gUiAtlas;
    extern f32 lbl_8036A258;
    extern f32 lbl_8036A268;
    extern f32 lbl_8036A26C;
    extern f32 lbl_8036A270;
    u32 color;
    u8 texBuf[0x24];
    s16 x;
    void *self;
    f32 scale;
    u16 texW;

    self = tip;
    if ((gUiInputFlags & 3) == 0) {
        x = M2C_FIELD(self, s16 *, 0x48);
        if (x >= 0x3E8) {
            x -= 0x3E8;
        }
        if (x > 0x1F8) {
            x = 0x1F8;
        }
        if (x < 0x68) {
            x = 0x68;
        }
        M2C_FIELD(self, u8 *, 0x50) = (u8)(s32)Math_Ease(
            0,
            (f32)M2C_FIELD(self, u8 *, 0x4C),
            (f32)M2C_FIELD(self, u8 *, 0x4D),
            (f32)M2C_FIELD(self, u8 *, 0x4E),
            (f32)M2C_FIELD(self, u8 *, 0x4F));
        Prim2D_Begin();
        scale = lbl_8036A258;
        Prim2D_SetTransform(scale, scale, lbl_8036A26C, lbl_8036A268);
        Prim2D_SetColorByte(M2C_FIELD(self, u8 *, 0x50));
        Prim2D_PrepareTex();
        Ui_LoadAtlasTex(gUiAtlas, texBuf, 0x1E);
        *(volatile u16 *)(texBuf + 0x20) = GXGetTexObjWidth(texBuf);
        *(volatile u16 *)(texBuf + 0x22) = GXGetTexObjHeight(texBuf);
        Prim2D_Begin();
        Prim2D_SetTex(texBuf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        texW = *(u16 *)(texBuf + 0x20);
        Prim2D_SetRect(
            (f32)(s32)(x - (s32)((texW >> 1) & 0x7FFF)),
            (f32)(s32)(M2C_FIELD(self, s16 *, 0x4A) - 0xC),
            (f32)texW,
            (f32)*(u16 *)(texBuf + 0x22));
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_SetTex((void *)0, 0x13);
        Prim2D_AddZ(lbl_8036A270);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(6);
        Prim2D_SetPos(
            (f32)(s32)(x - (s32)((u32)M2C_FIELD(self, u8 *, 0x51) >> 1)),
            (f32)(s32)(M2C_FIELD(self, s16 *, 0x4A) - 0xC));
        color = *Ui_GetColor(1);
        Prim2D_SetColorPacked(&color);
        Prim2D_SetText((u8 *)self + 0x30);
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}

void fn_80121328(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x4E) = (u8) (M2C_FIELD(arg0, u8 *, 0x4E) + 1);
}

void fn_80121338(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    s32 result;
    s32 zero;
    s32 eight;

    result = (s32)Math_Ease(
        0,
        (f32)*(u8 *)((u8 *)arg0 + 0x4C),
        (f32)*(u8 *)((u8 *)arg0 + 0x4D),
        (f32)*(u8 *)((u8 *)arg0 + 0x4E),
        (f32)*(u8 *)((u8 *)arg0 + 0x4F));
    zero = 0;
    eight = 8;
    *(u8 *)((u8 *)arg0 + 0x4C) = result;
    *(u8 *)((u8 *)arg0 + 0x4D) = zero;
    *(u8 *)((u8 *)arg0 + 0x4E) = zero;
    *(u8 *)((u8 *)arg0 + 0x4F) = eight;
    *(s16 *)((u8 *)arg0 + 0x28) = *(u8 *)((u8 *)arg0 + 0x4F);
}

void fn_801213EC(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x4C) = 0;
    *(u8 *)((u8 *)arg0 + 0x4D) = 0xFF;
    *(u8 *)((u8 *)arg0 + 0x4E) = 0;
    *(u8 *)((u8 *)arg0 + 0x4F) = 8;
    *(s16 *)((u8 *)arg0 + 0x28) = (u8)*(u8 *)((u8 *)arg0 + 0x4F);
}

#pragma opt_unroll off
#pragma opt_common_subs off
#pragma global_optimizer off
void fn_80121414(void) {
extern u8 lbl_8032BDE8[];
s32 i;
s32 ctr;
i=0;
*(u32 *)(lbl_8032BDE8+0x4000)=i;
*(u32 *)(lbl_8032BDE8+0x4004)=i;
lbl_8032BDE8[0x400C]=i;
for(ctr=32;ctr!=0;ctr--) {
lbl_8032BDE8[(u8)(i+0x100)<<6]=0;
lbl_8032BDE8[(u8)(i+0x101)<<6]=0;
lbl_8032BDE8[(u8)(i+0x102)<<6]=0;
lbl_8032BDE8[(u8)(i+0x103)<<6]=0;
lbl_8032BDE8[(u8)(i+0x104)<<6]=0;
lbl_8032BDE8[(u8)(i+0x105)<<6]=0;
lbl_8032BDE8[(u8)(i+0x106)<<6]=0;
lbl_8032BDE8[(u8)(i+0x107)<<6]=0;
i+=8;
}
}
#pragma global_optimizer on

void fn_801214A4(void) {
    struct Console {
        char lines[256][64];
        s32 line;
        s32 col;
        s32 unk;
        u8 flag;
    };
    extern u8 gBattleState[], lbl_80274D20[];
    extern struct Console lbl_8032BDE8;
    extern u32 gUiInputFlags;
    void fn_8014D8FC(void *);
    s32 fn_801662F0(void);
    int sprintf(char *, const char *, ...);
    char *p;
    u32 disabled;
    struct Console *b;
    char text[80];
    s32 col;

    fn_8014D8FC(gBattleState);
    sprintf(text, (char *)lbl_80274D20 + 0x1C, fn_801662F0());
    disabled = gUiInputFlags & 0x800;
    if (!disabled) {
        lbl_8032BDE8.flag = 0;
        col = lbl_8032BDE8.col;
        if (col <= 0x3E) {
            lbl_8032BDE8.lines[(u8)(lbl_8032BDE8.line + 0x100)][col] = ' ';
            ++lbl_8032BDE8.col;
            lbl_8032BDE8.lines[(u8)(lbl_8032BDE8.line + 0x100)][lbl_8032BDE8.col] = 0;
        }
    }
    b = &lbl_8032BDE8;
    if (b->flag == 0) {
        lbl_8032BDE8.lines[(u8)(b->line + 0x100)][b->col] = 0;
        b->col = 0;
        ++b->line;
        b->lines[(u8)(b->line + 0x100)][0] = 0;
        b->flag = 1;
    }
    p = text;
    if (disabled) {
        return;
    }
    while (*p) {
        u8 c = *p++;
        if (!disabled) {
            b->flag = 0;
            if (lbl_8032BDE8.col <= 0x3E) {
                lbl_8032BDE8.lines[(u8)(lbl_8032BDE8.line + 0x100)][lbl_8032BDE8.col] = c;
                ++lbl_8032BDE8.col;
                lbl_8032BDE8.lines[(u8)(lbl_8032BDE8.line + 0x100)][lbl_8032BDE8.col] = 0;
            }
        }
    }
}

#pragma opt_common_subs reset
#pragma opt_unroll reset
#pragma global_optimizer on
void fn_80121630(void *arg0)
{
    void *Process_CreateChild(void *, void *);
    void fn_80057880(void *, s32);
    void fn_80057898(void *, s32);
    void fn_800578A0(void *, f32);
    void fn_800578A8(void *, s32, s32, s32);
    void *fn_80057998(void *);
    void *Heap_Alloc(u32);

    extern u32 gUiInputFlags;
    extern u8 lbl_80290250[];
    extern u8 lbl_8032BDE8[];
    extern f32 lbl_8036A278;

    void *obj;
    s32 n;

    if ((gUiInputFlags & 0x800) == 0) {
        Process_CreateChild(lbl_80290250, arg0);

        *(s16 *)&lbl_8032BDE8[0x4014] = 0;
        *(s16 *)&lbl_8032BDE8[0x4016] = 0x20;
        *(s16 *)&lbl_8032BDE8[0x4010] =
            *(u8 *)&lbl_8032BDE8[0x4012] =
            *(u8 *)&lbl_8032BDE8[0x4013] = 0;

        n = 0x100;

        if (*(s32 *)&lbl_8032BDE8[0x4000] < 0x100) {
            n = *(s32 *)&lbl_8032BDE8[0x4000];
        }

        *(s16 *)&lbl_8032BDE8[0x400E] =
            (n - 0xF) * 0x19;

        if (*(s16 *)&lbl_8032BDE8[0x400E] < 0) {
            *(s16 *)&lbl_8032BDE8[0x400E] = 0;
        }

        if (*(s16 *)&lbl_8032BDE8[0x400E] != 0) {
            obj = Heap_Alloc(0x30);

            if (obj != NULL) {
                obj = fn_80057998(obj);
            }

            *(void **)&lbl_8032BDE8[0x4018] = obj;

            fn_800578A8(
                obj,
                0x240,
                0x36,
                0x174
            );

            fn_800578A0(
                *(void **)&lbl_8032BDE8[0x4018],
                lbl_8036A278
            );

            fn_80057898(
                *(void **)&lbl_8032BDE8[0x4018],
                *(s16 *)&lbl_8032BDE8[0x400E] + 0x177
            );

            fn_80057880(
                *(void **)&lbl_8032BDE8[0x4018],
                0x177
            );
        } else {
            *(void **)&lbl_8032BDE8[0x4018] = NULL;
        }
    }
}
#pragma global_optimizer on

#pragma cplusplus on
extern "C" void fn_80121754(void) {
    extern u8 lbl_8032BDE8[];
    struct Obj {
        u8 pad[0x2c];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6(s32) = 0;
    };
    Obj *obj;

    obj = *(Obj **)&lbl_8032BDE8[0x4018];
    if (obj != NULL) {
        if (obj != NULL) {
            obj->v6(1);
        }
    }
    *(Obj **)&lbl_8032BDE8[0x4018] = (Obj *)0;
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_801217AC(void) {
    void fn_80057880(void *, s32);
    void fn_80057898(void *, s32);
    void fn_800578A0(void *, f32);
    void fn_800578A8(void *, s32, s32, s32);
    void *fn_80057998(void *);
    void *Heap_Alloc(u32);
    extern u8 lbl_8032BDE8[];
    extern f32 lbl_8036A278;
    struct H {
        static inline s32 clamp(s32 x) {
            if (x >= 0x100) return 0x100;
            return x;
        }
    };
    void *obj;

    *(s16 *)&lbl_8032BDE8[0x4014] = 0;
    *(s16 *)&lbl_8032BDE8[0x4016] = 0x20;
    *(u8 *)&lbl_8032BDE8[0x4013] = 0;
    *(u8 *)&lbl_8032BDE8[0x4012] = 0;
    *(s16 *)&lbl_8032BDE8[0x4010] = 0;
    *(s16 *)&lbl_8032BDE8[0x400E] = (H::clamp(*(s32 *)&lbl_8032BDE8[0x4000]) - 0xF) * 0x19;
    if (*(s16 *)&lbl_8032BDE8[0x400E] < 0) {
        *(s16 *)&lbl_8032BDE8[0x400E] = 0;
    }
    if (*(s16 *)&lbl_8032BDE8[0x400E] != 0) {
        obj = Heap_Alloc(0x30);
        if (obj != NULL) {
            obj = fn_80057998(obj);
        }
        *(void **)&lbl_8032BDE8[0x4018] = obj;
        fn_800578A8(obj, 0x240, 0x36, 0x174);
        fn_800578A0(*(void **)&lbl_8032BDE8[0x4018], lbl_8036A278);
        fn_80057898(*(void **)&lbl_8032BDE8[0x4018], *(s16 *)&lbl_8032BDE8[0x400E] + 0x177);
        fn_80057880(*(void **)&lbl_8032BDE8[0x4018], 0x177);
    } else {
        *(void **)&lbl_8032BDE8[0x4018] = NULL;
    }
}
#pragma cplusplus off
#pragma push
#pragma optimization_level 4
void fn_801218B4(void *proc) {
    extern void *gPadInput;
    extern u32 gUiInputFlags;
    extern u8 lbl_8032BDE8[];
    void Process_ClearFunc(void *);
    void Process_Unlink(void *);
    u8 *pad = gPadInput;
    u32 active=0;
    s32 pos;
    s32 held;
    if ((*(u32 *)(pad+4)&0x08000008) &&
        ((s8)lbl_8032BDE8[0x4012]>0 || (s8)lbl_8032BDE8[0x4013]==0)) {
        active=1;
        *(s8 *)(lbl_8032BDE8+0x4012)=active;
        lbl_8032BDE8[0x4013]++;
    }
    if ((*(u32 *)(pad+4)&0x04000004) &&
        ((s8)lbl_8032BDE8[0x4012]<0 || (s8)lbl_8032BDE8[0x4013]==0)) {
        *(s8 *)(lbl_8032BDE8+0x4012)=-1;
        active=1;
        lbl_8032BDE8[0x4013]++;
    }
    if (!(u8)active) lbl_8032BDE8[0x4013]--;
    if ((s8)lbl_8032BDE8[0x4013]>12) lbl_8032BDE8[0x4013]=12;
    if ((s8)lbl_8032BDE8[0x4013]<0) lbl_8032BDE8[0x4013]=0;
    pos=*(s16 *)(lbl_8032BDE8+0x4010)+(s8)lbl_8032BDE8[0x4013]*(s8)lbl_8032BDE8[0x4012];
    *(s16 *)(lbl_8032BDE8+0x4010)=pos;
    if ((s16)pos>*(s16 *)(lbl_8032BDE8+0x400E)) {
        *(s16 *)(lbl_8032BDE8+0x4010)=*(s16 *)(lbl_8032BDE8+0x400E);
        lbl_8032BDE8[0x4013]=0;
    }
    if (*(s16 *)(lbl_8032BDE8+0x4010)<0) {
        *(s16 *)(lbl_8032BDE8+0x4010)=0;
        lbl_8032BDE8[0x4013]=0;
    }
    held=*(s32 *)(pad+4);
    if (held & (*(s32 *)(pad+8)^held) & 0x210) {
        *(s16 *)(lbl_8032BDE8+0x4016)=-32;
        *(s16 *)((u8 *)proc+0x28)=8;
        Process_ClearFunc(proc);
    } else if (gUiInputFlags & 3) Process_Unlink(proc);
}
#pragma pop
extern u8 lbl_8032BDE8[16];
void fn_80121A70(void) {
    fn_80121A98(&lbl_8032BDE8);
}

int fn_80121A98(void *arg0) {
extern u8 lbl_80274D20[];
extern f32 lbl_8036A278,lbl_8036A27C,lbl_8036A280,lbl_8036A284,lbl_8036A288,lbl_8036A28C,lbl_8036A290,lbl_8036A294,lbl_8036A298;
void Prim2D_Begin(void); void Prim2D_SetTransform(f32,f32,f32,f32); void Prim2D_SetTex(s32,s32); void Prim2D_SetColorByte(u8); void Prim2D_PrepareTex(void); void Prim2D_AddPrim(s32); void Prim2D_SetPosCorners(f32,f32,f32,f32); void Prim2D_SetColor(s32,s32,s32,s32); void Prim2D_EndPrim(void); void Prim2D_SetCallback(void *,s32); void fn_80121D30(void); void Prim2D_SetPos(f32,f32); s32 *Ui_GetColor(s32); void Prim2D_SetColorPacked(s32 *); void Prim2D_SetText(void *); void Prim2D_ClearCallbacks(void);
int sprintf(void *,void *,...); s32 fn_80234200(void *,s32); void fn_80057860(u32,s32); void fn_80057020(u32);

s32 color; char text[32];
s32 i, row; u8 *line; s32 adjust, y;
M2C_FIELD(arg0,s16 *,0x4014)+=M2C_FIELD(arg0,s16 *,0x4016);
if(M2C_FIELD(arg0,s16 *,0x4014)>255) M2C_FIELD(arg0,s16 *,0x4014)=255;
if(M2C_FIELD(arg0,s16 *,0x4014)<0) M2C_FIELD(arg0,s16 *,0x4014)=0;
Prim2D_Begin();
Prim2D_SetTransform(lbl_8036A27C,lbl_8036A27C,lbl_8036A280,lbl_8036A284);
Prim2D_SetTex(0,16);
Prim2D_SetColorByte((u8)M2C_FIELD(arg0,s16 *,0x4014));
Prim2D_PrepareTex(); Prim2D_AddPrim(1);
Prim2D_SetPosCorners(lbl_8036A278,lbl_8036A288,lbl_8036A28C,lbl_8036A290);
Prim2D_SetColor(0,0,0,200); Prim2D_EndPrim();
Prim2D_Begin();
Prim2D_SetTransform(lbl_8036A27C,lbl_8036A27C,lbl_8036A278,lbl_8036A284);
Prim2D_SetTex(0,19); Prim2D_SetCallback(fn_80121D30,0); Prim2D_PrepareTex();
for(i=0,row=0;i<16;i++,row+=25) {
s32 scroll=M2C_FIELD(arg0,s16 *,0x4010);
s32 index=M2C_FIELD(arg0,s32 *,0x4000)-i-scroll/25;
if(index<0) break;
line=(u8 *)arg0+((index+256)&255)*64;
y=(scroll-(scroll/25)*25)+(401-row);
if((s32)line[0]=='-') {
if((s32)line[1]=='F') {
Prim2D_AddPrim(6); Prim2D_SetPos(lbl_8036A294,(f32)y);
color=*Ui_GetColor(13); Prim2D_SetColorPacked(&color);
sprintf(text,lbl_80274D20+46,(u8 *)fn_80234200(line,42)+1);
Prim2D_SetText(text); Prim2D_EndPrim();
}
} else {
adjust=0;
if(*(u32 *)line==0x23463031) adjust=-4;
Prim2D_AddPrim(7); Prim2D_SetPos(lbl_8036A298,(f32)(y+adjust));
Prim2D_SetText(line); Prim2D_EndPrim();
}
}
Prim2D_Begin(); Prim2D_ClearCallbacks(); Prim2D_PrepareTex();
if(M2C_FIELD(arg0,u32 *,0x4018)) {
fn_80057860(M2C_FIELD(arg0,u32 *,0x4018),M2C_FIELD(arg0,s16 *,0x400E)-M2C_FIELD(arg0,s16 *,0x4010));
fn_80057020(M2C_FIELD(arg0,u32 *,0x4018));
}
Prim2D_Begin(); Prim2D_SetColorByte(255); Prim2D_PrepareTex();
}

void fn_80121D30(void) {
    M2C_UNK GXSetScissor(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    GXSetScissor(0, 0x33, 0x260, 0x177);
}

#pragma push
#pragma opt_common_subs off
void fn_80121D60(void *arg0, u8 *arg1) {
    u8 *fn_8007C378(u8 *);
    extern u8 lbl_80274D20[];
    extern u32 gUiInputFlags;
    u8 *s;
    u8 c;
    s32 pos;
    s32 off;
    u32 bit;

    if (arg1 == *(u8 **)((u8 *)arg0 + 0x4008)) {
        return;
    }
    *(u8 **)((u8 *)arg0 + 0x4008) = arg1;
    if (arg1 == NULL) {
        return;
    }
    if ((s32)*arg1 == 0x47) {
        s = lbl_80274D20 + 0x31;
        bit = gUiInputFlags & 0x800;
        switch (bit) {
        case 0:
            while ((s8)*s != 0) {
                c = *s;
                s += 1;
                if (!(gUiInputFlags & 0x800)) {
                    *(u8 *)((u8 *)arg0 + 0x400C) = 0;
                    pos = *(s32 *)((u8 *)arg0 + 0x4004);
                    if (pos <= 0x3E) {
                        off = (*(s32 *)((u8 *)arg0 + 0x4000) + 0x100) << 6;
                        off = (off & 0x3FC0) + pos;
                        M2C_FIELD(arg0, u8 *, off) = c;
                        pos = *(s32 *)((u8 *)arg0 + 0x4004);
                        *(s32 *)((u8 *)arg0 + 0x4004) = pos + 1;
                        off = (*(s32 *)((u8 *)arg0 + 0x4000) + 0x100) << 6;
                        off = (off & 0x3FC0) + *(s32 *)((u8 *)arg0 + 0x4004);
                        M2C_FIELD(arg0, u8 *, off) = 0;
                    }
                }
            }
            break;
        }
        if (*(u8 *)((u8 *)arg0 + 0x400C) == 0) {
            off = (*(s32 *)((u8 *)arg0 + 0x4000) + 0x100) << 6;
            off = (off & 0x3FC0) + *(s32 *)((u8 *)arg0 + 0x4004);
            M2C_FIELD(arg0, u8 *, off) = 0;
            *(s32 *)((u8 *)arg0 + 0x4004) = 0;
            *(s32 *)((u8 *)arg0 + 0x4000) = *(s32 *)((u8 *)arg0 + 0x4000) + 1;
            off = (*(s32 *)((u8 *)arg0 + 0x4000) + 0x100) << 6;
            off = (off & 0x3FC0) + *(s32 *)((u8 *)arg0 + 0x4004);
            M2C_FIELD(arg0, u8 *, off) = 0;
            *(u8 *)((u8 *)arg0 + 0x400C) = 1;
        }
    } else {
        s = lbl_80274D20 + 0x37;
        bit = gUiInputFlags & 0x800;
        switch (bit) {
        case 0:
            while ((s8)*s != 0) {
                c = *s;
                s += 1;
                if (!(gUiInputFlags & 0x800)) {
                    *(u8 *)((u8 *)arg0 + 0x400C) = 0;
                    pos = *(s32 *)((u8 *)arg0 + 0x4004);
                    if (pos <= 0x3E) {
                        off = (*(s32 *)((u8 *)arg0 + 0x4000) + 0x100) << 6;
                        off = (off & 0x3FC0) + pos;
                        M2C_FIELD(arg0, u8 *, off) = c;
                        pos = *(s32 *)((u8 *)arg0 + 0x4004);
                        *(s32 *)((u8 *)arg0 + 0x4004) = pos + 1;
                        off = (*(s32 *)((u8 *)arg0 + 0x4000) + 0x100) << 6;
                        off = (off & 0x3FC0) + *(s32 *)((u8 *)arg0 + 0x4004);
                        M2C_FIELD(arg0, u8 *, off) = 0;
                    }
                }
            }
            break;
        }
        s = fn_8007C378(arg1);
        bit = gUiInputFlags & 0x800;
        switch (bit) {
        case 0:
            while ((s8)*s != 0) {
                c = *s;
                s += 1;
                if (!(gUiInputFlags & 0x800)) {
                    *(u8 *)((u8 *)arg0 + 0x400C) = 0;
                    pos = *(s32 *)((u8 *)arg0 + 0x4004);
                    if (pos <= 0x3E) {
                        off = (*(s32 *)((u8 *)arg0 + 0x4000) + 0x100) << 6;
                        off = (off & 0x3FC0) + pos;
                        M2C_FIELD(arg0, u8 *, off) = c;
                        pos = *(s32 *)((u8 *)arg0 + 0x4004);
                        *(s32 *)((u8 *)arg0 + 0x4004) = pos + 1;
                        off = (*(s32 *)((u8 *)arg0 + 0x4000) + 0x100) << 6;
                        off = (off & 0x3FC0) + *(s32 *)((u8 *)arg0 + 0x4004);
                        M2C_FIELD(arg0, u8 *, off) = 0;
                    }
                }
            }
            break;
        }
        if (*(u8 *)((u8 *)arg0 + 0x400C) == 0) {
            off = (*(s32 *)((u8 *)arg0 + 0x4000) + 0x100) << 6;
            off = (off & 0x3FC0) + *(s32 *)((u8 *)arg0 + 0x4004);
            M2C_FIELD(arg0, u8 *, off) = 0;
            *(s32 *)((u8 *)arg0 + 0x4004) = 0;
            *(s32 *)((u8 *)arg0 + 0x4000) = *(s32 *)((u8 *)arg0 + 0x4000) + 1;
            off = (*(s32 *)((u8 *)arg0 + 0x4000) + 0x100) << 6;
            off = (off & 0x3FC0) + *(s32 *)((u8 *)arg0 + 0x4004);
            M2C_FIELD(arg0, u8 *, off) = 0;
            *(u8 *)((u8 *)arg0 + 0x400C) = 1;
        }
    }
}
#pragma pop
void fn_80122000(void *arg0)
{
    u8 *base;
    u32 index;
    u32 offset;

    base = (u8 *)arg0;

    if (base[0x400C] != 0) {
        return;
    }

    index = *(u32 *)(base + 0x4000);
    offset = *(u32 *)(base + 0x4004);

    base + (((u8)(index + 0x100) << 6) + offset);

    base[((u8)(index + 0x100) << 6) + offset] = 0;

    *(u32 *)(base + 0x4004) = 0;

    index = *(u32 *)(base + 0x4000);
    *(u32 *)(base + 0x4000) = index + 1;

    index = *(u32 *)(base + 0x4000);
    offset = *(u32 *)(base + 0x4004);

    base[((u8)(index + 0x100) << 6) + offset] = 0;

    base[0x400C] = 1;
}

void fn_8012205C(void *arg0)
{
    u8 *base;
    u32 index;
    u32 offset;

    base = (u8 *)arg0;

    if (base[0x400C] != 0) {
        return;
    }

    index = *(u32 *)(base + 0x4000);
    offset = *(u32 *)(base + 0x4004);

    base + (((u8)(index + 0x100) << 6) + offset);

    base[((u8)(index + 0x100) << 6) + offset] = 0;

    *(u32 *)(base + 0x4004) = 0;

    index = *(u32 *)(base + 0x4000);
    *(u32 *)(base + 0x4000) = index + 1;

    index = *(u32 *)(base + 0x4000);
    offset = *(u32 *)(base + 0x4004);

    base[((u8)(index + 0x100) << 6) + offset] = 0;

    base[0x400C] = 1;
}

void fn_801220B8(void *arg0)
{
    u8 *base;
    u32 index;
    u32 offset;

    base = (u8 *)arg0;

    if (base[0x400C] != 0) {
        return;
    }

    index = *(u32 *)(base + 0x4000);
    offset = *(u32 *)(base + 0x4004);

    base + (((u8)(index + 0x100) << 6) + offset);

    base[((u8)(index + 0x100) << 6) + offset] = 0;

    *(u32 *)(base + 0x4004) = 0;

    index = *(u32 *)(base + 0x4000);
    *(u32 *)(base + 0x4000) = index + 1;

    index = *(u32 *)(base + 0x4000);
    offset = *(u32 *)(base + 0x4004);

    base[((u8)(index + 0x100) << 6) + offset] = 0;

    base[0x400C] = 1;
}

void fn_80122114(void *arg0, u8 arg1)
{
    extern s32 gUiInputFlags;

    u8 *base;
    s32 offset;
    u32 index;

    if (gUiInputFlags & 0x800) {
        return;
    }

    base = (u8 *)arg0;
    base[0x400C] = 0;

    offset = *(s32 *)(base + 0x4004);

    if (offset > 0x3E) {
        return;
    }

    index = *(u32 *)(base + 0x4000);

    base[(((u8)(index + 0x100)) << 6) + offset] = arg1;

    offset = *(s32 *)(base + 0x4004);
    *(s32 *)(base + 0x4004) = offset + 1;

    index = *(u32 *)(base + 0x4000);
    offset = *(s32 *)(base + 0x4004);

    base[(((u8)(index + 0x100)) << 6) + offset] = 0;
}

void fn_80122170(void *arg0, void *arg1, u16 arg2) {
    extern u16 gUiPanelFlags;
    extern s32 gUiInputFlags;
    extern u8 gBattleState[];
    extern u8 lbl_802902D8[];
    void *Process_CreateChild(void *, void *);
    void *entry;
    s32 flags;
    u32 nib;
    u16 a2;

    a2 = arg2;
    if (!(gUiPanelFlags & 0x200)) {
        flags = gUiInputFlags;
        switch (flags & 3) {
        case 0:
            if ((flags & 0x2000) ||
                (nib = (((u8 *)gBattleState)[0x9c] >> 3) & 3, nib != 3U)) {
                entry = Process_CreateChild(lbl_802902D8, arg1);
                *(u16 *)((char *)entry + 0x28) = a2;
            }
            break;
        }
    }
}

void fn_801221E4(s32 arg0)
{
void UiPanel_PollSkip(u16 *);
void fn_80120C2C(void);
void Process_ClearFunc(s32);
extern u16 gUiPanelFlags;
extern u32 gUiInputFlags;
UiPanel_PollSkip(&gUiPanelFlags);
fn_80120C2C();
if ((gUiPanelFlags & 0x200) != 0 || (gUiInputFlags & 3) != 0) {
Process_ClearFunc(arg0);
}
}

void fn_80122238(void *arg0)
{
    extern s32 gUiInputFlags;
    extern u8 lbl_802902C4[];
    extern void *Process_CreateEx(void *);

    u8 *obj;
    u8 *entry;
    u32 value;

    obj = (u8 *)arg0;

    if (gUiInputFlags & 3) {
        obj[0x68] = 0;
    } else {
        entry = (u8 *)Process_CreateEx(lbl_802902C4);

        *(void **)(entry + 0x30) = obj;

        value = obj[0x68];

        *(u32 *)(entry + 0x3C) = value;
        *(u32 *)(entry + 0x40) = 0;
        *(u32 *)(entry + 0x34) = 0;
        *(u32 *)(entry + 0x38) = 8;
    }
}

void fn_801222A4(void *arg0)
{
    extern s32 gUiInputFlags;
    extern u8 lbl_802902C4[];
    extern void *Process_CreateEx(void *);

    u8 *obj;
    u8 *entry;
    u32 value;

    obj = (u8 *)arg0;

    if (gUiInputFlags & 3) {
        obj[0x68] = 0xFF;
    } else {
        entry = (u8 *)Process_CreateEx(lbl_802902C4);

        *(void **)(entry + 0x30) = obj;

        value = obj[0x68];

        *(u32 *)(entry + 0x3C) = value;
        *(u32 *)(entry + 0x40) = 0xFF;
        *(u32 *)(entry + 0x34) = 0;
        *(u32 *)(entry + 0x38) = 8;
    }
}

#pragma cplusplus on
extern "C" void fn_80122314(void *arg0) {
    extern u16 gUiPanelFlags;
    extern u32 gUiInputFlags;
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void UiPanel_PollSkip(void *);
    void Process_ClearFunc(void *);
    struct Item {
        u8 unk0;
        u8 pad1[0x3F];
        void *unk40;
        inline void reset() {
            unk0 = 0;
            unk40 = this;
        }
    };
    struct Panel {
        u8 pad0[0x30];
        Item *items[5];
        u8 unk44;
        s8 count;
        u8 unk46;
        u8 unk47;
        u8 unk48;
        inline void clear() {
            s32 i;
            for (i = 0; i < count; i++) {
                if (items[i] != NULL) {
                    items[i]->reset();
                }
            }
            unk46 = 0;
            unk47 = 0;
            unk48 = 0;
        }
    };
    s32 cur;
    s32 total;

    UiPanel_PollSkip(&gUiPanelFlags);
    M2C_FIELD(arg0, s32 *, 0x34)++;
    cur = M2C_FIELD(arg0, s32 *, 0x34);
    total = M2C_FIELD(arg0, s32 *, 0x38);
    if (cur > total || (gUiInputFlags & 3)) {
        Process_ClearFunc(arg0);
        if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
            ((Panel *)M2C_FIELD(arg0, void **, 0x30))->clear();
        }
    } else {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), u8 *, 0x68) = (u8) Math_Ease(0, (f32) M2C_FIELD(arg0, s32 *, 0x3C), (f32) M2C_FIELD(arg0, s32 *, 0x40), (f32) cur, (f32) total);
    }
}
#pragma cplusplus off
void TalkUi_SpawnKeyWait2(void *talk) {
    /* Spawn E_TalkKeyWait2 at the talk cursor and fade its sound in from silence. */
    void *Process_CreateChild(void *);
    void *Sound_Create(s32, u32);
    void Sound_FadeFromZero(void *, u8);
    extern u32 gUiInputFlags;
    extern u8 gProc_TalkKeyWait2[];
    void *proc;
    s16 x;
    s16 y;
    void *sound;

    if ((gUiInputFlags & 3) == 0) {
        proc = Process_CreateChild(gProc_TalkKeyWait2);
        y = *(s16 *)((u8 *)talk + 0x62);
        x = *(s16 *)((u8 *)talk + 0x60);
        *(u32 *)((u8 *)proc + 0x30) = *(u32 *)((u8 *)talk + 0x5C);
        *(s16 *)((u8 *)proc + 0x34) = x;
        *(s16 *)((u8 *)proc + 0x36) = y;
        if (*(u32 *)((u8 *)proc + 0x30) != 0) {
            *(void **)((u8 *)proc + 0x38) = Sound_Create(*(s32 *)((u8 *)proc + 0x30), 0);
            sound = *(void **)((u8 *)proc + 0x38);
            *(f32 *)((u8 *)sound + 0x40) = (f32)x;
            *(f32 *)((u8 *)sound + 0x44) = (f32)y;
            Sound_FadeFromZero(*(void **)((u8 *)proc + 0x38), 8);
        }
    }
}

void TalkUi_KeyWait2Proc(void *arg0) {
    void UiPanel_PollSkip(u16 *);
    u8 fn_80120C2C(void);
    void Ui_PlaySeCue(void *, s32);
    void fn_80109BB4(s32, s32);
    void Process_ClearFunc(void *);
    void fn_80121630(void *);
    extern u16 gUiPanelFlags;
    extern u8 lbl_80274D60[];
    extern u32 *gPadInput;
    u32 temp;

    UiPanel_PollSkip(&gUiPanelFlags);
    if (fn_80120C2C() != 0 || (gUiPanelFlags & 4)) {
        Ui_PlaySeCue(lbl_80274D60 + 0x3D, 0x64);
        if (*(u32 *)((u8 *)arg0 + 0x30) != 0) {
            fn_80109BB4(*(s32 *)((u8 *)arg0 + 0x38), 8);
        }
        Process_ClearFunc(arg0);
        gUiPanelFlags &= ~0x200;
    } else {
        temp = gPadInput[1];
        if (temp & (gPadInput[2] ^ temp) & 0x10) {
            fn_80121630(arg0);
        }
    }
}

void fn_801225D4(void *arg0) {
    extern s32 gUiInputFlags;
    extern u16 gUiPanelFlags;
    extern u8 lbl_80290298[];
    void *Process_CreateChild(void *);
    u8 *obj = arg0;
    s32 rem;

    gUiPanelFlags &= ~0x200;
    if (gUiInputFlags & 3) {
        s32 i;
        u8 *p;
        s32 zero;
        i = 0;
        p = obj;
        zero = i;
        for (; i < (s8)obj[0x45]; p += 4, i++) {
            void *ptr = *(void **)(p + 0x30);
            if (ptr) {
                *(u8 *)ptr = zero;
                *(void **)((u8 *)ptr + 0x40) = ptr;
            }
        }
        obj[0x46] = 0;
        obj[0x47] = 0;
        obj[0x48] = 0;
    } else {
        rem = (s8)obj[0x47] + 1 - (s8)obj[0x46];
        if (rem) {
            u8 *entry;
            if (rem > 4) {
                rem = 4;
            }
            entry = Process_CreateChild(lbl_80290298);
            *(s32 *)(entry + 0x38) = rem * obj[0x49];
            {
                s32 t = (s8)obj[0x44];
                t *= rem;
                *(s32 *)(entry + 0x34) = t;
            }
            *(void **)(entry + 0x30) = obj;
            *(s16 *)(entry + 0x28) = *(s32 *)(entry + 0x38);
            *(s32 *)(entry + 0x3c) = 1;
        }
    }
}

void fn_801226D0(void *arg0)
{
  extern s32 gUiInputFlags;
  u8 *new_var;
  extern u8 lbl_80290298[];
  void *Process_CreateChild(void *);
  u8 *obj;
  u8 *entry;
  s8 a;
  s8 b;
  s32 rem;
  void *ptr;
  obj = (u8 *) arg0;
  if (gUiInputFlags & 3)
  {
    a = (s8) obj[0x46];
    b = (s8) obj[0x45];
    rem = a % b;
    new_var = obj + 0x30;
    ptr = *((void **) (new_var + (rem * 4)));
    *((u8 *) ptr) = 0;
    *((void **) (((u8 *) ptr) + 0x40)) = ptr;
    obj[0x46] = (u8) (obj[0x46] + 1);
    obj[0x48] = 0;
  }
  else
  {
    entry = (u8 *) Process_CreateChild(lbl_80290298);
    *((s32 *) (entry + 0x38)) = obj[0x49];
    *((s32 *) (entry + 0x34)) = (s8) obj[0x44];
    *((void **) (entry + 0x30)) = obj;
    *((s16 *) (entry + 0x28)) = (s16) (*((s32 *) (entry + 0x38)));
    *((s32 *) (entry + 0x3C)) = 0;
  }
}

typedef struct { u8 x0; u8 pad[0x3f]; void *x40; } It_80122780;
typedef struct { u8 pad0[0x30]; It_80122780 *items[5]; u8 x44; s8 count; u8 x46, x47, x48; } P_80122780;
static inline void Set_80122780(It_80122780 *q, u8 v) { q->x0 = v; q->x40 = q; }
static inline void Clr_80122780(P_80122780 *p, u8 v) {
    s32 i;
    for (i = 0; i < p->count; i++) {
        if (p->items[i]) Set_80122780(p->items[i], v);
    }
    p->x46 = 0; p->x47 = 0; p->x48 = 0;
}
void fn_80122780(void *o_) {
    u8 *o = (u8 *)o_;
    if (*(s32 *)(o + 0x3c) != 0) {
        Clr_80122780(*(P_80122780 **)(o + 0x30), 0);
    } else {
        P_80122780 *p = *(P_80122780 **)(o + 0x30);
        It_80122780 *q = p->items[(s8)p->x46 % p->count];
        q->x0 = 0; q->x40 = q;
        p->x46++;
        p->x48 = 0;
    }
}

extern struct efUnit* gUiPanelFlags;
#pragma cplusplus on
extern "C" void fn_8012282C(struct efUnit* arg0) {
    #pragma dont_inline on
    void UiPanel_PollSkip(u16 *);
    #pragma dont_inline reset
    extern u32 gUiInputFlags;
    extern f32 lbl_8036A2B0;
    void Process_Unlink(void *);
    f32 Math_Ease(s32, f32, f32, f32, f32);
    struct Item {
        u8 unk0;
        u8 pad1[0x3F];
        void *unk40;
        inline void reset() {
            unk0 = 0;
            unk40 = this;
        }
    };
    struct Panel {
        u8 pad0[0x30];
        Item *items[5];
        u8 unk44;
        s8 count;
        s8 unk46;
        u8 unk47;
        u8 unk48;
        inline void clear() {
            s32 i;
            for (i = 0; i < count; i++) {
                if (items[i] != NULL) {
                    items[i]->reset();
                }
            }
            unk46 = 0;
            unk47 = 0;
            unk48 = 0;
        }
    };
    UiPanel_PollSkip((u16 *)&gUiPanelFlags);
    if ((gUiInputFlags & 3) || (*(u16 *)&gUiPanelFlags & 0x400)) {
        if (*(s32 *)((u8 *)arg0 + 0x3c)) {
            ((Panel *)*(void **)((u8 *)arg0 + 0x30))->clear();
        } else {
            Panel *p = (Panel *)*(void **)((u8 *)arg0 + 0x30);
            p->items[p->unk46 % p->count]->reset();
            p->unk46++;
            p->unk48 = 0;
        }
        Process_Unlink(arg0);
    } else {
        (*(u8 **)((u8 *)arg0 + 0x30))[0x48] = (s32)Math_Ease(0,
        (f32)*(s32 *)((u8 *)arg0 + 0x34), lbl_8036A2B0,
        (f32)*(s16 *)((u8 *)arg0 + 0x28), (f32)*(s32 *)((u8 *)arg0 + 0x38));
    }
}
#pragma cplusplus off
extern u8 lbl_80290288[16];
void fn_80122998(s32 arg0) {
    void Process_Create(void *, s32);
    extern u8 lbl_80290288[16];
    Process_Create(lbl_80290288, arg0);
}

u8 fn_801229C4(u8 *arg0) {
    s8 a = (s8)arg0[0x46];
    s8 b = (s8)arg0[0x47];
    s8 c = (s8)arg0[0x45];
    return (u8)((b - a) >= c);
}

void fn_801229F8(void *arg0) {
    u8 temp_r4;

    M2C_FIELD(arg0, u8 *, 0x47) = (u8) (M2C_FIELD(arg0, u8 *, 0x47) + 1);
    temp_r4 = M2C_FIELD(arg0, u8 *, 0x47);
    if ((s8) temp_r4 > 0x60) {
        M2C_FIELD(arg0, u8 *, 0x47) = (u8) (temp_r4 - 0x40);
        M2C_FIELD(arg0, u8 *, 0x46) = (u8) (M2C_FIELD(arg0, u8 *, 0x46) - 0x40);
    }
}

void fn_80122A2C(void *arg0, u8 arg1) {
    s32 index;
    s32 count;
    u8 **slot;
    index = (s8)*(u8 *)((u8 *)arg0 + 0x47);
    count = (s8)*(u8 *)((u8 *)arg0 + 0x45);
    index %= count;
    arg0 = (u8 *)arg0 + (index << 2);
    slot = *(u8 ***)((u8 *)arg0 + 0x30);
    *slot[16]++ = arg1;
    *slot[16] = 0;
}

void fn_80122A74(s32 unused, s16 *p) {
    extern void GXSetScissor(s16, s16, s16, s16);
    GXSetScissor(p[0], p[1], p[2], p[3]);
}

void fn_80122AA8(void *arg0) {
    void *fn_80079380(u8);
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32,f32,f32,f32);
    void Prim2D_SetTex(void *,s32);
    void Prim2D_SetColorByte(u8);
    void Prim2D_SetCallback(void (*)(s32,s16 *),void *);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32,f32);
    void Prim2D_SetTextScale(u8,f32);
    void fn_800071D8(u8,f32);
    void Prim2D_SetColor(s32,s32,s32,s32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    void Prim2D_ResetState(void);
    extern f32 lbl_8036A2B0,lbl_8036A2B4,lbl_8036A2B8,lbl_8036A2BC;
    u8 *self=arg0;
    u8 *p;
    s32 i;
    if ((s8)self[0x6A]>=0) {
        p=fn_80079380(self[0x6A]);
        if (p) self[0x69]=p[0x41];
    }
    p=*(u8 **)(self+0x64);
    if (p) {
        p[0x60]=self[0x68];
        (*(u8 **)(self+0x64))[0x61]=(u32)self[0x69]>>1;
    }
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036A2B0,lbl_8036A2B0,lbl_8036A2B4,lbl_8036A2B8);
    Prim2D_SetTex(0,0x13);
    Prim2D_SetColorByte(self[0x68]);
    if (self[0x48]) {
        Prim2D_SetCallback(fn_80122A74,self+0x54);
        {
            s16 y=*(s16 *)(self+0x4E);
            s32 bottom=y+*(s16 *)(self+0x52);
            s16 x=*(s16 *)(self+0x4C);
            s32 right=x+*(s16 *)(self+0x50);
            *(s16 *)(self+0x54)=x;
            *(s16 *)(self+0x56)=y;
            *(s16 *)(self+0x58)=right;
            *(s16 *)(self+0x5A)=bottom;
        }
    }
    Prim2D_PrepareTex();
    for (i=0;i<(s8)self[0x45];i++) {
        Prim2D_AddPrim(7);
        Prim2D_SetPos((f32)*(s16 *)(self+0x4C),(f32)(*(s16 *)(self+0x4E)+i*(s8)self[0x44]-self[0x48]));
        Prim2D_SetTextScale(self[0x4A],lbl_8036A2BC);
        fn_800071D8(self[0x4B],lbl_8036A2B8);
        Prim2D_SetColor(self[0x69],self[0x69],self[0x69],255);
        Prim2D_SetText(*(void **)(self+0x30+4*(((s8)self[0x46]+i)%(s8)self[0x45])));
        Prim2D_EndPrim();
    }
    Prim2D_ResetState();
}

void fn_80122C84(void *arg0) {
    void *p;
    s32 i;
    s32 zero = 0;

    p = arg0;
    i = 0;
    do {
        Heap_Free(*(s32 *)((u8 *)p + 0x30));
        *(s32 *)((u8 *)p + 0x30) = zero;
        i += 1;
        p = (u8 *)p + 4;
    } while (i < 5);
}

void *fn_80122CE0(void *arg0)
{
  void *fn_800C42D8(s32);
  u8 new_var;
  void *self;
  void *walk;
  s32 zero;
  s32 i;
  void *p;
  s32 t;
  s32 a;
  s32 b;
  self = arg0;
  walk = arg0;
  zero = 0;
  i = 0;
  *((u8 *) (((u8 *) arg0) + 0x44)) = 0x1C;
  *((u8 *) (((u8 *) arg0) + 0x45)) = 4;
  *((u8 *) (((u8 *) self) + 0x46)) = (u8) zero;
  *((u8 *) (((u8 *) self) + 0x47)) = (u8) zero;
  *((u8 *) (((u8 *) self) + 0x48)) = (u8) zero;
  t = (s8) (*((u8 *) (((u8 *) self) + 0x44)));
  t = t / 4;
  *((u8 *) (((u8 *) self) + 0x49)) = (u8) t;
  *((u8 *) (((u8 *) self) + 0x4A)) = (u8) zero;
  *((u8 *) (((u8 *) self) + 0x4B)) = 1;
  *((s16 *) (((u8 *) self) + 0x50)) = 0x190;
  a = (s8) (*((u8 *) (((u8 *) self) + 0x44)));
  new_var = (u8) zero;
  b = (s8) (*((u8 *) (((u8 *) self) + 0x45)));
  a = a * b;
  *((s16 *) (((u8 *) self) + 0x52)) = (s16) a;
  *((s16 *) (((u8 *) self) + 0x4C)) = 0x20;
  *((s16 *) (((u8 *) self) + 0x4E)) = 0x20;
  *((u8 *) (((u8 *) self) + 0x68)) = (u8) zero;
  *((u8 *) (((u8 *) self) + 0x69)) = 0xFF;
  do
  {
    p = fn_800C42D8(0x44);
 if (p != NULL) { *((u8 *)p) = new_var; *((void **)((u8 *)p + 0x40)) = p; }
    i += 1;
    *((void **) (((u8 *) walk) + 0x30)) = p;
    walk = ((u8 *) walk) + 4;
  }
  while (i < 5);
  return self;
}

void fn_80122DD0(void *arg0, s16 arg1, s16 arg2) {
    if (arg1 >= 0) {
        M2C_FIELD(arg0, s16 *, 0x60) = arg1;
    }
    if (arg2 >= 0) {
        M2C_FIELD(arg0, s16 *, 0x62) = arg2;
    }
}

void fn_80122DEC(void *arg0, s32 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x60) = arg2;
    M2C_FIELD(arg0, s16 *, 0x62) = arg3;
}

void fn_80122DFC(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x49) = arg1;
}

void fn_80122E04(void *arg0, s8 arg1, s8 arg2) {
    M2C_FIELD(arg0, s8 *, 0x4A) = arg1;
    M2C_FIELD(arg0, s8 *, 0x4B) = arg2;
}

void fn_80122E10(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x50) = arg1;
}

void fn_80122E18(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x45) = arg1;
}

void fn_80122E20(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x44) = arg1;
}

void fn_80122E28(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x4C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x4E) = arg2;
}

void fn_80122E34(void *arg0, u32 arg1) {
    s32 Sound_Create(u32, void *);
    if (arg1 != 0U) {
        M2C_FIELD(arg0, s32 *, 0x64) = Sound_Create(arg1, arg0);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
}

extern u16 lbl_8028E090[];
void *fn_80122E80(void *arg0, s16 arg1) {
    void String_Destroy(void *, s32);
    void fn_800DF724(void *, s32);
    void Heap_Free(void *);
    extern void *lbl_802902E8[];

    if (arg0 != NULL) {
        M2C_FIELD(arg0, void ***, 0x40) = lbl_802902E8;
        String_Destroy((s8 *)arg0 + 0x54, -1);
        if (arg0 != NULL) {
            *(void **)((char *)arg0 + 0x40) = (void *)lbl_8028E090;
            fn_800DF724(arg0, 0);
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma use_lmw_stmw on
void fn_80122F04(void *arg0, void *arg1) {
    void Effect_SetPos(void *, f32, f32, f32);
    void *fn_8005397C(void *, s32);
    void *String_CStr(void *);
    s32 i;
    s32 off;

    for (i = 0, off = 0; i < *(s32 *)((u8 *)arg1 + 4); i++, off += 0xC) {
        void *obj = fn_8005397C(String_CStr((u8 *)*(void **)((u8 *)arg1 + 8) + off), 4);
        Effect_SetPos(obj,
                      (f32)*(s32 *)((u8 *)arg0 + 0x48),
                      (f32)(*(s32 *)((u8 *)arg0 + 0x4C) + 0xC),
                      (f32)(*(s32 *)((u8 *)arg0 + 0x44) + 1));
        *(f32 *)((u8 *)*(void **)((u8 *)obj + 0x30) + 0x1C) =
            (f32)(s16)(*(s32 *)((u8 *)arg0 + 0x44) + 1);
        *(f32 *)((u8 *)*(void **)((u8 *)obj + 0x30) + 0x18) = 0.05f;
        *(f32 *)((u8 *)*(void **)((u8 *)obj + 0x30) + 0x20) = -90.0f;
    }
}
#pragma use_lmw_stmw on
#pragma opt_common_subs off
void fn_80123034(void *arg0, void *arg1, s32 arg2, f32 farg0, f32 farg1) {
    void fn_800536B0(void *, f32, f32, f32);
    void *fn_8005397C(void *, s32);
    void *fn_800C93EC(s32);
    extern f32 lbl_8036A2D0;
    extern f32 lbl_8036A2D4;
    extern f32 lbl_8036A2D8;
    extern f32 lbl_8036A2C0;
    extern f32 lbl_8036A2C4;
    extern f64 lbl_8036A2C8;
    extern u8 lbl_80274DB0[];
    void *obj;
    s32 i;
    u32 off;
    void *self;
    void *list;
    f32 t3;
    f32 f31;
    f32 f30;
    f32 t0;

    self = arg0;
    list = arg1;
    t3 = lbl_8036A2D0;
    t0 = lbl_8036A2D4;
    M2C_FIELD(self, f32 *, 0x78) = t3 * farg0;
    M2C_FIELD(self, f32 *, 0x80) = t0 * farg0;
    M2C_FIELD(self, f32 *, (unsigned)0x7C) = farg1;
    M2C_FIELD(self, s32 *, 0x90) = arg2;

    if (M2C_FIELD(list, u32 *, 4) == 0) {
        obj = fn_8005397C(lbl_80274DB0 + 8, 4);
        fn_800536B0(obj,
                    (f32)M2C_FIELD(self, s32 *, 0x48),
                    (f32)M2C_FIELD(self, s32 *, 0x4C),
                    (f32)(M2C_FIELD(self, s32 *, 0x44) + 1));
        M2C_FIELD(M2C_FIELD(obj, void **, 0x30), f32 *, 0x1C) =
            (f32)(s16)(M2C_FIELD(self, s32 *, 0x44) + 1);
        M2C_FIELD(M2C_FIELD(obj, void **, 0x30), f32 *, 0x18) = lbl_8036A2D8;
        return;
    }

    i = 0;
    f30 = lbl_8036A2C0;
    off = 0;
    f31 = lbl_8036A2C4;
    while (i < M2C_FIELD(list, s32 *, 4)) {
        obj = fn_8005397C(fn_800C93EC(M2C_FIELD(list, s32 *, 8) + off), 4);
        fn_800536B0(obj,
                    (f32)M2C_FIELD(self, s32 *, 0x48),
                    (f32)M2C_FIELD(self, s32 *, 0x4C),
                    (f32)(M2C_FIELD(self, s32 *, 0x44) + 1));
        ++i;
        off += 0xC;
        M2C_FIELD(M2C_FIELD(obj, void **, 0x30), f32 *, 0x1C) =
            (f32)(s16)(M2C_FIELD(self, s32 *, 0x44) + 1);
        M2C_FIELD(M2C_FIELD(obj, void **, 0x30), f32 *, 0x20) = f31;
        M2C_FIELD(M2C_FIELD(obj, void **, 0x30), f32 *, 0x18) = f30;
    }
}
#pragma opt_common_subs reset

#pragma optimization_level 3
void fn_8012323C(void *arg0) {
    extern f32 lbl_8036A2DC;
    f64 fn_80238638(f64);
    extern f64 lbl_8036A2E0;
    extern f32 lbl_8036A2E8;
    f32 halfpi;
    f32 cos_v;
    f32 clamp;
    f32 sin_v;

    if (M2C_FIELD(arg0, s32 *, 0x90) > 0) {
        cos_v = (f32)fn_80238638(M2C_FIELD(arg0, f32 *, 0x84));
        halfpi = lbl_8036A2DC;
        M2C_FIELD(arg0, f32 *, 0x88) = M2C_FIELD(arg0, f32 *, 0x78) * cos_v;
        sin_v = (f32)fn_80238638(halfpi + M2C_FIELD(arg0, f32 *, 0x84));
        clamp = lbl_8036A2E8;
        M2C_FIELD(arg0, f32 *, 0x8C) = (f32)(lbl_8036A2E0 * (f64)(M2C_FIELD(arg0, f32 *, 0x78) * sin_v));
        M2C_FIELD(arg0, f32 *, 0x84) = M2C_FIELD(arg0, f32 *, 0x84) + M2C_FIELD(arg0, f32 *, 0x7C);
        M2C_FIELD(arg0, f32 *, 0x78) = M2C_FIELD(arg0, f32 *, 0x78) + M2C_FIELD(arg0, f32 *, 0x80);
        if (M2C_FIELD(arg0, f32 *, 0x78) < clamp) {
            M2C_FIELD(arg0, f32 *, 0x78) = clamp;
        }
        M2C_FIELD(arg0, s32 *, 0x90)--;
    }
}
#pragma optimization_level reset
void fn_801232F4(void *arg0, f32 farg0, f32 farg1) {
    M2C_FIELD(arg0, f32 *, 0x70) = farg0;
    M2C_FIELD(arg0, f32 *, 0x74) = farg1;
}

void fn_80123300(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x68) = arg1;
}

#pragma use_lmw_stmw on
void fn_80123308(void *arg0, s32 arg1)
{
    char *fn_80238ABC(s32, char *, s32);
    void String_Init(void *, void *, void *);
    void String_Destroy(void *, s32);
    u8 *fn_80117CC0(void *, s32);
    s32 fn_800E2E68(void *);
    s32 fn_800E2E60(void *);
    void fn_800E3040(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    void SpriteSheet_DrawFrame(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern f64 lbl_8036A2C8;
    extern f64 lbl_8036A2F0;

    char buf0[36];
    char buf1[36];
    u32 str0[3];
    u32 str1[3];
    void *alloc0;
    void *alloc1;
    s32 spacing;
    s32 h;
    s32 w;
    s32 y;
    s32 x;
    s32 i;
    s32 digit;

    (void)lbl_8036A2C8;
    (void)lbl_8036A2F0;

    if (M2C_FIELD(arg0, s32 *, 0x64) == 0) {
        String_Init(str0, fn_80238ABC(M2C_FIELD(arg0, s32 *, 0x68), buf0, 10), &alloc0);
        x = (s32)(M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), f32 *, 0x68) + (f32)(M2C_FIELD(arg0, s32 *, 0x48) + M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), s32 *, 0x60)));
        y = M2C_FIELD(arg0, s32 *, 0x4C) + M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), s32 *, 0x64);
        w = (s32)(M2C_FIELD(arg0, f32 *, 0x6C) * (f32)fn_800E2E68(M2C_FIELD(arg0, void **, 0x60)));
        h = (s32)(M2C_FIELD(arg0, f32 *, 0x6C) * (f32)fn_800E2E60(M2C_FIELD(arg0, void **, 0x60)));
        x += (s32)M2C_FIELD(arg0, f32 *, 0x88);
        y += (s32)M2C_FIELD(arg0, f32 *, 0x8C);
        y = y - (h - fn_800E2E60(M2C_FIELD(arg0, void **, 0x60)));
        i = (s32)str0[0] - 1;
        spacing = (s32)(M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), f32 *, 0x6C) * (f32)M2C_FIELD(arg0, u8 *, 0x53));
        while (i >= 0) {
            digit = (s8)(*fn_80117CC0(str0, i)) - 0x30;
            fn_800E3040(
                M2C_FIELD(arg0, void **, 0x60),
                arg1,
                digit,
                x,
                y,
                M2C_FIELD(arg0, s32 *, 0x44),
                w,
                h,
                M2C_FIELD(arg0, u8 *, 0x50),
                M2C_FIELD(arg0, u8 *, 0x51),
                M2C_FIELD(arg0, u8 *, 0x52),
                spacing,
                0);
            i = i - 1;
            x = x - (w + M2C_FIELD(arg0, s32 *, 0x94));
        }
        String_Destroy(str0, -1);
    } else {
        void *panel;
        String_Init(str1, fn_80238ABC(M2C_FIELD(arg0, s32 *, 0x68), buf1, 10), &alloc1);
        panel = M2C_FIELD(arg0, void **, 0x38);
        i = 0;
        x = (s32)(M2C_FIELD(panel, f32 *, 0x68) + (f32)(M2C_FIELD(arg0, s32 *, 0x48) + M2C_FIELD(panel, s32 *, 0x60)));
        spacing = (s32)(M2C_FIELD(panel, f32 *, 0x6C) * (f32)M2C_FIELD(arg0, u8 *, 0x53));
        w = (s32)str1[0];
        y = M2C_FIELD(arg0, s32 *, 0x4C) + M2C_FIELD(panel, s32 *, 0x64);
        for (; i < w; i++) {
            digit = (s8)(*fn_80117CC0(str1, i)) - 0x30;
            SpriteSheet_DrawFrame(
                M2C_FIELD(arg0, void **, 0x60),
                arg1,
                digit,
                x,
                y,
                M2C_FIELD(arg0, s32 *, 0x44),
                M2C_FIELD(arg0, u8 *, 0x50),
                M2C_FIELD(arg0, u8 *, 0x51),
                M2C_FIELD(arg0, u8 *, 0x52),
                spacing,
                0);
            x = x + fn_800E2E68(M2C_FIELD(arg0, void **, 0x60));
            x = x + M2C_FIELD(arg0, s32 *, 0x94);
        }
        String_Destroy(str1, -1);
    }
}
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" void fn_80123634(void *arg0) {
    struct Obj {
        u8 pad[0x40];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        u8 pad2[0x28];
        f32 f6c;
        f32 f70;
        f32 f74;
    };
    Obj *self = (Obj *)arg0;

    self->v12();
    if (self->f6c < self->f70) {
        self->f6c = self->f6c + self->f74;
        if (self->f6c >= self->f70) {
            self->f6c = self->f70;
        }
    } else if (self->f6c > self->f70) {
        self->f6c = self->f6c - self->f74;
        if (self->f6c <= self->f70) {
            self->f6c = self->f70;
        }
    }
}
#pragma cplusplus reset
void *fn_801236CC(void *arg0, void *arg1, void *arg2) {
    void fn_800E2CF4(void *);
    void fn_800C9ABC(void *, void *, void *);
    void fn_800C8DCC(void *, void *, void *);
    void fn_800C96F8(void *, void *, u32);
    void fn_800C9A60(void *, s32);
    s32 fn_800C9400(void *, u32, u32, char *, u32);
    s32 fn_800E7FB4(void *, void *);
    u32 strlen(const char *);
    extern u8 lbl_802902E8[];
    extern u8 lbl_80274DB0[];
    extern const f32 lbl_8036A2F8;
    extern const f32 lbl_8036A2E8;

    typedef struct {
        u32 size;
        u32 cap;
        char *data;
    } String;

    typedef struct {
        void *unk00;
        u8 pad04[0x3C];
        void *vtable;
        u8 pad44[0x10];
        String str54;
        s32 unk60;
        s32 unk64;
        s32 unk68;
        f32 unk6C;
        f32 unk70;
        f32 unk74;
        f32 unk78;
        f32 unk7C;
        f32 unk80;
        f32 unk84;
        f32 unk88;
        f32 unk8C;
        s32 unk90;
        s32 unk94;
    } Obj;

    typedef struct {
        char pad[0x2B];
        char left[4];
    } LeftTbl;

    char spC0[0x20];
    char spA0[0x20];
    char sp80[0x20];
    char sp60[0x20];
    String sp54;
    String sp48;
    String sp3C;
    String sp30;
    String sp24;
    String sp18;
    u8 sp14[4];
    u8 sp10[4];
    u8 spC[4];
    u8 sp8[4];
    void *saved;
    Obj *path;
    Obj *self;
    Obj *buf;
    char *left;
    u32 len;
    f32 t0;
    f32 t1;

    path = (Obj *)arg2;
    self = (Obj *)arg0;
    fn_800E2CF4(arg0);
    self->vtable = lbl_802902E8;

    self->str54.size = 0;
    self->str54.cap = 0;
    self->str54.data = 0;
    self->str54.cap = 0;

    saved = self->unk00;

    sp54.cap = 0;
    sp48.cap = 0;
    sp54.size = 0;
    sp54.data = 0;
    sp54.cap = 0;
    sp48.size = 0;
    sp48.data = 0;
    sp48.cap = 0;

    fn_800C9ABC(&sp3C, lbl_80274DB0 + 0x12, &sp14);
    fn_800C8DCC(spC0, path, &sp3C);
    buf = (Obj *)spC0;
    fn_800C96F8(&self->str54, buf, strlen((char *)buf));
    fn_800C9A60(&sp3C, -1);

    fn_800C9ABC(&sp30, lbl_80274DB0 + 0x1A, &sp10);
    fn_800C8DCC(spA0, path, &sp30);
    buf = (Obj *)spA0;
    fn_800C96F8(&sp48, buf, strlen((char *)buf));
    fn_800C9A60(&sp30, -1);

    fn_800C9ABC(&sp24, lbl_80274DB0 + 0x1F, &spC);
    fn_800C8DCC(sp80, path, &sp24);
    self->unk68 = *(s32 *)sp80;
    fn_800C9A60(&sp24, -1);

    t1 = lbl_8036A2F8;
    self->unk6C = t1;
    self->unk70 = t1;
    t0 = lbl_8036A2E8;
    self->unk74 = t0;
    self->unk78 = t0;
    self->unk80 = t0;
    self->unk7C = t0;
    self->unk84 = t0;
    self->unk88 = t0;
    self->unk8C = t0;
    self->unk90 = 0;

    fn_800C9ABC(&sp18, lbl_80274DB0 + 0x23, &sp8);
    fn_800C8DCC(sp60, path, &sp18);
    self->unk94 = *(s32 *)sp60;
    fn_800C9A60(&sp18, -1);

    len = strlen(((LeftTbl *)lbl_80274DB0)->left);
    left = (char *)(lbl_80274DB0 + 0x2B);
    if (fn_800C9400(&sp48, 0, sp48.size, left, len) == 0) {
        self->unk64 = 1;
    } else {
        self->unk64 = 0;
    }
    self->unk60 = fn_800E7FB4(saved, &self->str54);
    fn_800C9A60(&sp48, -1);
    fn_800C9A60(&sp54, -1);
    return self;
}

void fn_8012391C(void *arg0) {
    void *Process_Find(void *);
    void Process_Unlink(void *);
    void fn_80123988(void *);
    extern u8 lbl_80290408[];
    extern u8 gBattleSkyIndex;
    void *temp_r3;
    void *ptr;

    temp_r3 = Process_Find(lbl_80290408);
    if (temp_r3 == NULL || *(s32 *)((u8 *)temp_r3 + 0x34) != gBattleSkyIndex) {
        ptr = *(void **)((u8 *)arg0 + 0x30);
        if (ptr != NULL) {
            Process_Unlink(ptr);
        }
        *(void **)((u8 *)arg0 + 0x30) = NULL;
        fn_80123988(arg0);
    }
}

#pragma global_optimizer on
#pragma scheduling on
void fn_80123988(SkyProc *self)
{
    void *Process_Create(void *, void *);
    void *Map_Get(void);

    extern s32 lbl_80274F68[3];
    extern u8 lbl_80290328[];
    extern u8 gBattleSkyIndex;
    extern f32 lbl_8036A308;
    extern f32 lbl_8036A30C;

    u8 *base;
    u8 *proc;
    u8 *map;
    SkyVector sp8;
    u32 skyIndex;

    self->skyIndex = -1;

    sp8 = *(SkyVector *)lbl_80274F68;
    self->position.x = sp8.x;
    self->position.y = sp8.y;
    self->position.z = sp8.z;
    self->scale = lbl_8036A308;
    self->speed = lbl_8036A30C;

    base = lbl_80290328;
    self->parent = Process_Create(base + 0xFC, self);
    self->skyIndex = gBattleSkyIndex;

    map = (u8 *)Map_Get();
    if (map[0x68] == 1) {
        skyIndex = self->skyIndex;
        switch ((s32)skyIndex) {
        case 2:
            proc = (u8 *)Process_Create(base + 0xB4, self->parent);
            proc[0x4F] = 0x3C;
            break;
        case 3:
            proc = (u8 *)Process_Create(base + 0xB4, self->parent);
            proc[0x4F] = 0x1E;
            break;
        case 4:
            proc = (u8 *)Process_Create(base + 0xB4, self->parent);
            proc[0x4F] = 0x64;
            break;
        case 5:
        case 6:
        case 7:
            proc = (u8 *)Process_Create(base + 0x8C, self->parent);
            proc[0x4C] = (u8)skyIndex;
            break;
        case 8:
            proc = (u8 *)Process_Create(base + 0x60, self->parent);
            proc[0x4C] = 0;
            break;
        }
    } else {
        skyIndex = self->skyIndex;
        switch (skyIndex) {
        case 0:
            Process_Create(base + 0, self->parent);
            break;
        case 1:
            Process_Create(base + 0, self->parent);
            break;
        case 2:
            proc = (u8 *)Process_Create(base + 0xB4, self->parent);
            proc[0x4F] = 0x3C;
            break;
        case 3:
            proc = (u8 *)Process_Create(base + 0xB4, self->parent);
            proc[0x4F] = 0x1E;
            break;
        case 4:
            proc = (u8 *)Process_Create(base + 0xB4, self->parent);
            proc[0x4F] = 0x64;
            break;
        case 5:
        case 6:
        case 7:
            proc = (u8 *)Process_Create(base + 0x8C, self->parent);
            proc[0x4C] = (u8)skyIndex;
            break;
        case 8:
            proc = (u8 *)Process_Create(base + 0x60, self->parent);
            proc[0x4C] = 0;
            break;
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            Process_Create(base + 0x3C, self->parent);
            break;
        }
    }
}
#pragma scheduling on
#pragma optimization_level reset
#pragma global_optimizer on

s32 fn_80123BA8(void) {
    s32 Process_Create(void *, s32);
    void fn_80123988(void);
    extern u8 lbl_80290408[];
    s32 result;

    result = Process_Create(lbl_80290408, 4);
    fn_80123988();
    return result;
}

void fn_80123BE8(void) {

}

void fn_80123BEC(void *arg0) {
    void Process_Unlink(void *);
    void *ptr;

    ptr = *(void **)((u8 *)arg0 + 0x30);
    if (ptr != NULL) {
        Process_Unlink(ptr);
    }
    *(void **)((u8 *)arg0 + 0x30) = NULL;
}

void fn_80123C2C(void *arg0) {
    void fn_8006785C(s32, void *, void *);
    void fn_80124424(void *);
    u8 fn_800AA188(void);
    void fn_80123D1C(void);

    if (*(u8 *)((u8 *)arg0 + 0x4D) != 0) {
        fn_8006785C(2, fn_80123D1C, arg0);
        goto block_4;
    }
    if (fn_800AA188() != 0) {
        fn_8006785C(2, fn_80123D1C, arg0);
    block_4:
        fn_80124424(arg0);
    }
}

void fn_80123CA0(void *arg0) {
    void fn_8006D8E8(s32);
    void Heap_FreeRaw(s32);
    void fn_801479C4(u8 *, s32);
    extern u8 lbl_80274F74[];

    Heap_FreeRaw(*(s32 *)((u8 *)arg0 + 0x64));
    Heap_FreeRaw(*(s32 *)((u8 *)arg0 + 0x60));
    Heap_FreeRaw(*(s32 *)((u8 *)arg0 + 0x5C));
    fn_8006D8E8(*(s32 *)((u8 *)arg0 + 0x58));
    fn_801479C4(lbl_80274F74 + 0x72, 0xFA);
}

void fn_80123CFC(void) {
    M2C_UNK fn_801246FC();
    fn_801246FC();
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma use_lmw_stmw on
#pragma opt_loop_invariants on
void fn_80123D1C(void *arg0) {
    void Ui_LoadAtlasTex(s32, void *, s32);
    s32 Game_GetFrameCount(void);
    void *Map_Get(void);
    void *Camera_GetViewMtx(void);
    void PSMTXScale(void *, f32, f32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXRotRad(void *, s32, f32);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void GXClearVtxDesc(void);
    void GXSetVtxDesc(s32, s32);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80222C50(void *, s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetZMode(s32, s32, s32);
    void fn_8022100C(s32);
    void GXBegin(s32, s32, s32);
    void fn_80220154(s32, s32, s32);
    void GXSetChanMatColor(s32, void *);
    void fn_80222164(s32, void *);
    void fn_80220F44(s32, s32);
    extern u32 lbl_8036A300;
    extern u32 lbl_8036A304;
    extern f32 lbl_8036A308;
    extern f32 lbl_8036A30C;
    extern f32 lbl_8036A310;
    extern f32 lbl_8036A314;
    extern f32 lbl_8036A318;
    extern f32 lbl_8036A31C;
    extern f64 lbl_8036A320;

    u8 sp18[0x20];
    f32 sp158[3][4];
    f32 sp128[3][4];
    f32 spF8[3][4];
    f32 spC8[3][4];
    f32 sp98[3][4];
    f32 sp68[3][4];
    f32 sp38[3][4];
    u32 sp14, sp10, spC, sp8;
    f32 zero;
    s32 ring;
    s32 count;
    s32 n;
    u8 limit;
    s32 fade;
    f32 *pts;
    s16 *verts;
    s32 k, j;
    s16 half;
    u8 alpha;
    s32 a2;
    s8 sx;
    s16 vx, vy, vz;
    s32 i;
    f32 *point;
    s32 last;
    s32 total;

    Ui_LoadAtlasTex(*(s32 *)((u8 *)arg0 + 0x58), sp18, 8);
    ring = Game_GetFrameCount();
    sx = *(s8 *)((u8 *)arg0 + 0x4E);
    fade = *(s8 *)((u8 *)arg0 + 0x4F);
    ring &= 7;
    count = *(u16 *)((u8 *)arg0 + 0x54);
    n = *(u16 *)((u8 *)arg0 + 0x56);
    limit = *(u8 *)((u8 *)arg0 + 0x52);
    PSMTXScale(sp158, (f32)sx, (f32)sx, (f32)sx);
    PSMTXConcat((u8 *)Map_Get() + 0x70, sp158, sp158);
    PSMTXConcat(Camera_GetViewMtx(), sp158, sp158);
    PSMTXScale(spF8, lbl_8036A310, lbl_8036A314, lbl_8036A310);
    PSMTXTrans(spC8, lbl_8036A30C, lbl_8036A318, lbl_8036A30C);
    PSMTXConcat(spF8, spC8, sp128);
    PSMTXConcat(sp158, sp128, sp128);
    GXLoadPosMtxImm(sp128, 0);
    GXSetCurrentMtx(0);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxDesc(0xD, 1);
    GXSetVtxAttrFmt(0, 9, 1, 3, 0);
    GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
    GXSetVtxAttrFmt(0, 0xD, 1, 0, 0);
    GXSetNumChans(1);
    fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
    fn_80222C50(sp18, 0);
    GXSetCullMode(1);
    GXSetBlendMode(4, 0, 1, 1, 0, 0, 2);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetNumTexGens(0, 0);
    fn_802245D8(1, 4, 5, 0);
    GXSetZMode(1, 3, 0);
    fn_8022100C(0);
    GXBegin(0x80, 0, (count & 0x7FF) << 5);

    j = 7;
    k = 0xD9;
    do {
        half = (s16)((j + 1) << 2);
        alpha = (u8)(((u8)(0xFF - k) * fade) / 100);
        verts = (s16 *)((u8 *)*(void **)((u8 *)arg0 + 0x5C) + count * ring * 6);
        for (i = count - 1; i >= 0; i--) {
            vx = verts[0] - half;
            vy = verts[1] - half;
            vz = verts[2];
            *(volatile s16 *)0xCC008000 = vx;
            *(volatile s16 *)0xCC008000 = vz;
            *(volatile s16 *)0xCC008000 = vy;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = alpha;
            *(volatile u8 *)0xCC008000 = 0;
            *(volatile u8 *)0xCC008000 = 0;
            vx = verts[0] + half;
            vy = verts[1] - half;
            vz = verts[2];
            *(volatile s16 *)0xCC008000 = vx;
            *(volatile s16 *)0xCC008000 = vz;
            *(volatile s16 *)0xCC008000 = vy;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = alpha;
            *(volatile u8 *)0xCC008000 = 1;
            *(volatile u8 *)0xCC008000 = 0;
            vx = verts[0] + half;
            vy = verts[1] + half;
            vz = verts[2];
            *(volatile s16 *)0xCC008000 = vx;
            *(volatile s16 *)0xCC008000 = vz;
            *(volatile s16 *)0xCC008000 = vy;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = alpha;
            *(volatile u8 *)0xCC008000 = 1;
            *(volatile u8 *)0xCC008000 = 1;
            vx = verts[0] - half;
            vy = verts[1] + half;
            vz = verts[2];
            *(volatile s16 *)0xCC008000 = vx;
            *(volatile s16 *)0xCC008000 = vz;
            *(volatile s16 *)0xCC008000 = vy;
            verts = (s16 *)((u8 *)verts + 6);
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = 0xFF;
            *(volatile u8 *)0xCC008000 = alpha;
            *(volatile u8 *)0xCC008000 = 0;
            *(volatile u8 *)0xCC008000 = 1;
        }
        j -= 1;
        ring = (ring + 1) & 7;
        k -= 0x1F;
    } while (j >= 0);

    GXClearVtxDesc();
    GXSetVtxDesc(9, 3);
    GXSetVtxAttrFmt(0, 9, 1, 3, 0);
    fn_80220154(9, *(s32 *)((u8 *)arg0 + 0x60), 6);
    GXSetCullMode(1);
    sp10 = lbl_8036A300;
    a2 = (fade << 5) / 100;
    ((u8 *)&sp10)[3] = a2;
    sp14 = sp10;
    GXSetChanMatColor(4, &sp14);
    sp8 = lbl_8036A304;
    ((u8 *)&sp8)[3] = a2;
    spC = sp8;
    fn_80222164(4, &spC);
    GXSetBlendMode(4, 0, 0, 0, 0, 0, 2);
    GXSetNumChans(0);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0xFF, 4);
    GXSetNumTexGens(0, 4);

    pts = *(f32 **)((u8 *)arg0 + 0x64);
    PSMTXTrans(sp68, (f32)(*(s8 *)((u8 *)arg0+0x50)/2), lbl_8036A30C, (f32)(*(s8 *)((u8 *)arg0+0x51)/2));
    PSMTXTrans(sp38, (f32)(-*(s8 *)((u8 *)arg0+0x50)/2), lbl_8036A30C, (f32)(-*(s8 *)((u8 *)arg0+0x51)/2));
    PSMTXScale(spF8, lbl_8036A310, lbl_8036A314, lbl_8036A310);
    fn_80220F44(6, 0);
    zero = lbl_8036A30C;
    total=n*2;
    last=total-1;
    point=pts;
    for (j = 0; j < (s32)limit; j++, point += 2) {
        if (!(point[1] < zero)) {
            s32 rem;
            s32 tot;
            PSMTXTrans(spC8, zero, point[1], zero);
            PSMTXRotRad(sp98, 0x59, lbl_8036A31C * point[0]);
            PSMTXConcat(spC8, spF8, sp128);
            PSMTXConcat(sp38, sp128, sp128);
            PSMTXConcat(sp98, sp128, sp128);
            PSMTXConcat(sp68, sp128, sp128);
            PSMTXConcat(sp158, sp128, sp128);
            GXLoadPosMtxImm(sp128, 0);
            GXSetCurrentMtx(0);
            GXBegin(0xA8, 0, (s32)(u16)total);
            for (rem=last;rem>=0;rem--) {
                *(volatile s16 *)0xCC008000=rem;
            }
            point[1] -= lbl_8036A308;
        }
    }
}
#pragma pop

#pragma push
#pragma use_lmw_stmw on
#pragma opt_unroll off
void fn_80124424(void *self) {
    s32 Game_GetFrameCount(void);
    u32 Rand_Next(void);
    f32 fn_800233D0(void *, s8, s8, u8);
    extern u8 gBattleMap[];
    extern f32 lbl_8036A328;
    extern f32 lbl_8036A30C;
    extern f32 lbl_8036A32C;
    u32 rangeX;
    u32 rangeY;
    s32 i;
    s16 *pts;
    f32 scale;
    f32 *pairs;

    rangeX = ((s8)*((u8 *)self + 0x50) + 0x10) << 8;
    rangeY = ((s8)*((u8 *)self + 0x51) + 0x10) << 8;
    {
        s32 t = Game_GetFrameCount();
        s32 offset;
        u8 flag = *((u8 *)self + 0x4D);
        offset = *(u16 *)((u8 *)self + 0x54) * (t & 7);
        pts = (s16 *)((u8 *)*(s16 **)((u8 *)self + 0x5C) + offset * 6);
        if (flag != 0) {
            i = 0;
            while (i < *(u16 *)((u8 *)self + 0x54)) {
                pts[0] = (s16)((Rand_Next() % rangeX) - 0x800);
                pts[1] = (s16)((Rand_Next() % rangeY) - 0x800);
                pts[2] = 0;
                pts = (s16 *)((u8 *)pts + 6);
                i++;
            }
        } else {
            scale = lbl_8036A328;
            i = 0;
            while (i < *(u16 *)((u8 *)self + 0x54)) {
                pts[0] = (s16)((Rand_Next() % rangeX) - 0x800);
                pts[1] = (s16)((Rand_Next() % rangeY) - 0x800);
                pts[2] = (s16)(scale * fn_800233D0(gBattleMap, (s8)(pts[0] >> 8), (s8)(pts[1] >> 8), 0));
                pts = (s16 *)((u8 *)pts + 6);
                i++;
            }
        }
    }

    if (*((u8 *)self + 0x4C) != 0) {
        i = 0;
        scale = lbl_8036A30C;
        rangeX = i;
        rangeY = rangeX;
        while (i < *((u8 *)self + 0x52)) {
            pairs = *(f32 **)((u8 *)self + 0x64);
            if (!(*(f32 *)((u8 *)pairs + rangeX + 4) >= scale)) {
                *(f32 *)((u8 *)pairs + rangeX + 4) = (f32)((s32)rangeY / (s32)*((u8 *)self + 0x52));
                {
                    u32 rnd = Rand_Next();
                    pairs = *(f32 **)((u8 *)self + 0x64);
                    *(f32 *)((u8 *)pairs + rangeX) = (f32)(u32)(rnd % 0x168U);
                }
            }
            rangeX += 8;
            rangeY += 0x28;
            i++;
        }
        *((u8 *)self + 0x4C) = 0;
        return;
    }

    if ((Game_GetFrameCount() & 3) == 0) {


        s32 ctr;
        f32 z;
        i = 0;
        rangeX = i;
        ctr = *((u8 *)self + 0x52);
        z = 0.0f;
        for (; ctr > 0; ctr--) {
            f32 v;
            pairs = *(f32 **)((u8 *)self + 0x64);
            v = *(f32 *)((u8 *)pairs + rangeX + 4);
            if (!(v >= z)) {
                pairs = (f32 *)((u8 *)pairs + (i << 3));
                pairs[1] = lbl_8036A32C;
                {
                    u32 rnd = Rand_Next();
                    pairs = *(f32 **)((u8 *)self + 0x64);
                    *(f32 *)((u8 *)pairs + (i << 3)) = (f32)(u32)(rnd % 0x168U);
                }
                return;
            }
            rangeX += 8;
            i += 1;
        }
    }
}
#pragma pop
void fn_801246FC(void *arg0) {
    void *Map_Get(void);
    void *fn_8006D948(void *);
    void *Heap_AllocRaw(s32);
    u32 Rand_Next(void);
    void DCFlushRange(void *,u32);
    void Fx_AllocSlot(void *,s32,s32);
    extern s32 gBattleMap[];
    extern u8 lbl_80274F74[];
    extern f32 lbl_8036A338;
    u8 *self=arg0;
    s16 *p;
    u32 rangeX;
    u32 rangeY;
    s32 i;
    s32 offset;
    s32 j;
    f32 initial;
    self[0x4C]=1;
    *(u16 *)(self+0x54)=*(u16 *)(self+0x56)=256;
    self[0x52]=16;
    if (((u8 *)Map_Get())[0x68]==1) {
        self[0x4D]=1;
        self[0x50]=32;
        self[0x51]=24;
        self[0x4E]=5;
    } else {
        self[0x4D]=0;
        self[0x50]=gBattleMap[0];
        self[0x51]=gBattleMap[1];
        self[0x4E]=1;
    }
    *(void **)(self+0x58)=fn_8006D948(lbl_80274F74+0x84);
    *(void **)(self+0x5C)=Heap_AllocRaw((*(u16 *)(self+0x54)<<3)*6);
    *(void **)(self+0x60)=Heap_AllocRaw((*(u16 *)(self+0x56)<<1)*6);
    p=*(s16 **)(self+0x60);
    rangeX=((s8)self[0x50]+16)<<8;
    rangeY=((s8)self[0x51]+16)<<8;
    for(i=0;i<*(u16 *)(self+0x56)*2;i+=2) {
        p[0]=p[3]=(Rand_Next()%rangeX)-0x800;
        p[2]=p[5]=(Rand_Next()%rangeY)-0x800;
        p[1]=Rand_Next()%768;
        p[4]=p[1]+256;
        p+=6;
    }
    DCFlushRange(*(void **)(self+0x60),*(u16 *)(self+0x56)*12);
    *(void **)(self+0x64)=Heap_AllocRaw(self[0x52]*8);
    initial=-1.0f;
    for(j=0;j<self[0x52];j++) (*(f32 **)(self+0x64))[j*2+1]=initial;
    Fx_AllocSlot(lbl_80274F74+0x72,50,1);
}

void fn_801248E4(void *arg0) {
    extern u8 lbl_80274F74[];

    void Heap_FreeRaw(void *);
    void Heap_Free(void *);
    void fn_801479C4(void *, s32);
    void fn_8006D8E8(void *);

    u8 *obj;
    u8 *data;
    void *ptr;

    obj = (u8 *)arg0;
    data = *(u8 **)(obj + 0x58);

    if (data != NULL) {
        ptr = *(void **)data;

        if (ptr != NULL) {
            if (ptr != NULL) {
                Heap_FreeRaw((u8 *)ptr - 0x10);
            }
            *(void **)data = NULL;
        }

        ptr = *(void **)(data + 4);

        if (ptr != NULL) {
            Heap_FreeRaw(ptr);
            *(void **)(data + 4) = NULL;
        }

        Heap_Free(data);
    }

    fn_801479C4(lbl_80274F74 + 0x94, 0xFA);
    fn_8006D8E8(*(void **)(obj + 0x54));
}

#pragma use_lmw_stmw on
#pragma peephole off
void fn_8012497C(void *arg0) {
    void *Map_Get(void);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_80067708(s32, s32, void (*)(void *), void *);
    u8 fn_800AA188(void);
    void fn_80124E58(void *, f32 *, f32 *);
    void Fx_DrawParticles(void *);
    f32 Vec_Length(void *);
    extern f32 lbl_8036A308;
    extern f32 lbl_8036A30C;
    extern f32 lbl_8036A32C;
    extern f32 lbl_8036A33C;
    extern f32 lbl_8036A340;
    extern f32 lbl_8036A344;
    extern f32 lbl_8036A348;
    extern f32 lbl_8036A34C;
    extern f32 lbl_8036A350;
    extern f32 lbl_8036A354;
    extern f32 lbl_8036A358;

    f32 sp58, sp54, sp50, sp4C, sp48, sp44;
    f32 sp40, sp3C, sp38, sp34, sp30, sp2C;
    f32 sp28, sp24, sp20, sp1C, sp18, sp14;
    f32 sp10, spC, sp8;
    u32 b20, b21, b22, b23, b24, b25, b29bits;
    void *self;
    s32 limit;
    void *cam;
    u32 gqrVal;
    s32 outer;
    s32 n;
    void *node;
    void *list;
    void *tmp;
    f32 t;
    f32 sc;
    u8 amax;
    s16 cur, mx;
    s32 fifth;
    u8 keep;

    self = arg0;
    limit = 1;

    if (*(u8 *)((u8 *)self + 0x4E) != 0) {
        limit = 0x3C;
        *(u8 *)((u8 *)self + 0x4E) = 0;
        t = Math_Lerp(lbl_8036A30C, lbl_8036A33C, lbl_8036A308,
                      Vec_Length((u8 *)self + 0x38) / *(f32 *)((u8 *)self + 0x50));
        t = lbl_8036A33C - t;
        if (t <= lbl_8036A340) {
            t = lbl_8036A340;
        }
        if (t >= lbl_8036A33C) {
            t = lbl_8036A33C;
        }
        *(u8 *)((u8 *)self + 0x4D) = (s32)t;
    }

    cam = Map_Get();
    gqrVal = 0x08070807;
    for (outer = 0; outer < limit; outer++) {
        switch (*(u8 *)((u8 *)cam + 0x68)) {
        case 0:
            if (fn_800AA188() == 0) {
                break;
            }
            sc = *(f32 *)((u8 *)self + 0x50);
            sp50 = lbl_8036A344;
            sp54 = lbl_8036A344;
            sp44 = (f32)(*(s16 *)cam + 8);
            sp48 = (f32)(*(s16 *)((u8 *)cam + 2) + 8);
            sp58 = lbl_8036A348 * sc;
            sp4C = lbl_8036A32C * sc;
            b23 = *(u32 *)&sp50;
            b22 = *(u32 *)&sp54;
            b20 = *(u32 *)&sp44;
            b25 = *(u32 *)&sp48;
            b21 = *(u32 *)&sp58;
            b24 = *(u32 *)&sp4C;
            for (n = 0; n < *(u8 *)((u8 *)self + 0x48); n++) {
                *(u32 *)&sp2C = b20;
                *(u32 *)&sp30 = b25;
                *(u32 *)&sp34 = b24;
                *(u32 *)&sp38 = b23;
                *(u32 *)&sp3C = b22;
                *(u32 *)&sp40 = b21;
                fn_80124E58(self, &sp38, &sp2C);
            }
        case 1:
            sc = *(f32 *)((u8 *)self + 0x50);
            sp50 = lbl_8036A34C * sc;
            sp54 = lbl_8036A350 * sc;
            sp44 = lbl_8036A354 * sc;
            sp48 = lbl_8036A358 * sc;
            sp58 = lbl_8036A340 * sc;
            sp4C = lbl_8036A32C * sc;
            b24 = *(u32 *)&sp50;
            b25 = *(u32 *)&sp54;
            b21 = *(u32 *)&sp44;
            b22 = *(u32 *)&sp48;
            b29bits = *(u32 *)&sp58;
            b23 = *(u32 *)&sp4C;
            for (b20 = 0; (s32)b20 < *(u8 *)((u8 *)self + 0x48); b20++) {
                *(u32 *)&sp14 = b21;
                *(u32 *)&sp18 = b22;
                *(u32 *)&sp1C = b23;
                *(u32 *)&sp20 = b24;
                *(u32 *)&sp24 = b25;
                *(u32 *)&sp28 = b29bits;
                fn_80124E58(self, &sp20, &sp14);
            }
            node = NULL;
            goto list_iter;
        default:
            node = NULL;
            goto list_iter;
        }

    list_body:
        amax = *(u8 *)((u8 *)self + 0x49);
        (void)gqrVal;
        sp8 = (f32)*(s16 *)((u8 *)node + 0xE);
        spC = (f32)*(s16 *)((u8 *)node + 0x10);
        sp10 = (f32)*(s16 *)((u8 *)node + 0x12);
        *(s16 *)((u8 *)node + 0x8) = (s16)(*(s16 *)((u8 *)node + 0x8) + 1);
        cur = *(s16 *)((u8 *)node + 0x8);
        mx = *(s16 *)((u8 *)node + 0xA);
        sp8 = sp8 + *(f32 *)((u8 *)self + 0x38);
        spC = spC + *(f32 *)((u8 *)self + 0x3C);
        sp10 = sp10 + *(f32 *)((u8 *)self + 0x40);
        if (cur >= mx) {
            keep = 0;
        } else {
            fifth = mx / 5;
            if (cur < fifth) {
                *(u8 *)((u8 *)node + 0xC) =
                    (s32)Math_Lerp(lbl_8036A30C, (f32)amax, (f32)fifth, (f32)cur);
            } else {
                *(u8 *)((u8 *)node + 0xC) = (s32)Math_Lerp(
                    (f32)amax, lbl_8036A30C, (f32)(mx - fifth), (f32)(cur - fifth));
            }
            keep = 1;
            *(f32 *)((u8 *)node + 0x14) = *(f32 *)((u8 *)node + 0x14) + sp8;
            *(f32 *)((u8 *)node + 0x18) = *(f32 *)((u8 *)node + 0x18) + spC;
            *(f32 *)((u8 *)node + 0x1C) = *(f32 *)((u8 *)node + 0x1C) + sp10;
        }
        if (keep == 0) {
            list = *(void **)((u8 *)self + 0x58);
            if (node != NULL) {
                tmp = *(void **)node;
                if (tmp != NULL) {
                    *(void **)((u8 *)tmp + 4) = *(void **)((u8 *)node + 4);
                }
                tmp = *(void **)((u8 *)node + 4);
                if (tmp != NULL) {
                    *(void **)tmp = *(void **)node;
                }
                if (node == *(void **)((u8 *)list + 0xC)) {
                    *(void **)((u8 *)list + 0xC) = *(void **)node;
                }
                if (node == *(void **)((u8 *)list + 0x10)) {
                    *(void **)((u8 *)list + 0x10) = *(void **)((u8 *)node + 4);
                }
                *(u8 **)((u8 *)list + 0x8) = *(u8 **)((u8 *)list + 0x8) - 4;
                *(s32 *)((u8 *)list + 0x14) = *(s32 *)((u8 *)list + 0x14) - 1;
                **(void ***)((u8 *)list + 0x8) = node;
            }
        }

    list_iter:
        list = *(void **)((u8 *)self + 0x58);
        if (node == NULL) {
            node = *(void **)((u8 *)list + 0xC);
        } else {
            node = *(void **)node;
        }
        if (node != NULL) {
            goto list_body;
        }
    }

    fn_80067708(2, 3, Fx_DrawParticles, self);
}
#pragma peephole reset
void fn_80124E58(void *arg0, f32 *arg1, f32 *arg2)
{
  u32 fn_8000CD60(void);
  f32 new_var2;
  extern f32 lbl_8036A35C;
  extern f32 lbl_8036A360;
  f32 new_var4[2];
  void *list;
  u8 **new_var;
  void *node;
  void *prev;
  u32 rnd;
  s16 scale;
  s16 spC;
  volatile unsigned int spA;
  s16 sp8;
  f32 dx;
  f32 dy;
  f32 dz;
  f32 px;
  f32 new_var3;
  f32 py;
  f32 pz;
  f32 ay;
  list = *((void **) (((u8 *) arg0) + 0x58));
  node = *(*((void ***) (((u8 *) list) + 0x8)));
  if (node == NULL)
  {
    node = NULL;
  }
  else
  {
    *((void **) (((u8 *) node) + 4)) = *((void **) (((u8 *) list) + 0x10));
    *((void **) node) = NULL;
    prev = *((void **) (((u8 *) list) + 0x10));
    new_var = (u8 **) (((u8 *) list) + 0x8);
    if (prev != NULL)
    {
      *((void **) prev) = node;
    }
    if ((*((void **) (((u8 *) list) + 0xC))) == NULL)
    {
      *((void **) (((u8 *) list) + 0xC)) = node;
    }
    *((void **) (((u8 *) list) + 0x10)) = node;
    *new_var = (*new_var) + 4;
    *((s32 *) (((u8 *) list) + 0x14)) = (*((s32 *) (((u8 *) list) + 0x14))) + 1;
  }
  if (node == NULL)
  {
    return;
  }
  rnd = fn_8000CD60();
  rnd = (rnd % 200) + 0xC8;
  scale = (s16) (((*((u8 *) (((u8 *) arg0) + 0x4D))) * rnd) / 100);
  __builtin_mtspr(917, 0x00070007);
  dx = arg2[0] - arg1[0];
  new_var3 = arg1[2];
  dy = arg2[1] - arg1[1];
  dz = arg2[2] - new_var3;
  new_var2 = lbl_8036A35C;
  spC = (s16) dx;
  spA = (s16) dy;
  sp8 = (s16) dz;
  spC = (s16) (fn_8000CD60() % ((u32) (spC * 10)));
  spA = (s16) (fn_8000CD60() % ((u32) (spA * 10)));
  sp8 = (s16) (fn_8000CD60() % ((u32) (sp8 * 10)));
  px = (new_var2 * ((f32) spC)) + arg1[0];
  pz = (new_var2 * ((f32) sp8)) + new_var3;
  py = (lbl_8036A35C * ((f32) spA)) + arg1[1];
  spC = (s16) (fn_8000CD60() % 100);
  sp8 = (s16) (fn_8000CD60() % 100);
  *((f32 *) (((u8 *) node) + 0x14)) = px;
  new_var4[0] = lbl_8036A360 * ((f32) spC);
  *((f32 *) (((u8 *) node) + 0x18)) = (new_var2 * ((f32) ((((sp8 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu))) + new_var3;
  ay = lbl_8036A360 * ((f32) sp8);
  *((s16 *) (((u8 *) node) + 0x8)) = 0;
  *((f32 *) (((u8 *) node) + 0x1C)) = py;
  __builtin_mtspr(917, 0x08070007);
  *((s16 *) (((u8 *) node) + 0xE)) = (s16) new_var4[0];
  *((s16 *) (((u8 *) node) + 0x10)) = (s16) new_var4[1];
  *((s16 *) (((u8 *) node) + 0x12)) = (s16) ay;
  *(((u8 *) node) + 0xA) = scale;
}

#pragma use_lmw_stmw reset

void fn_80125130(void *arg0) {
    void *Process_Create(void *, void *);
    void *Map_Get(void);
    void *fn_8006D948(void *);
    void *Heap_AllocRaw(s32);
    void *Heap_Alloc(s32);
    void Fx_AllocSlot(void *, s32, s32);
    void fn_8012600C(void *, s32);
    void fn_802031CC(void *, void *, f32);
    void *fn_8022C414(void *, void (*)(void *, s32), void *, s32, s32);
    void DCFlushRange(void *, u32);
    extern u8 lbl_80274F74[];
    extern u8 lbl_80290388[];
    extern f32 lbl_8036A308;
    extern f32 lbl_8036A30C;
    extern f32 lbl_8036A364;
    extern f32 lbl_8036A368;
    extern f32 lbl_8036A36C;
    extern f32 lbl_8036A370;
    extern f32 lbl_8036A374;
    extern f32 lbl_8036A378;
    void *arr;
    void *self;
    s32 bytes;
    s32 n;
    void *obj;
    void *tmp;
    s32 i;
    s32 off;
    s32 idx;
    f32 f0;
    f32 f1;
    u8 t;
    u8 *p;

    self = arg0;
    switch (M2C_FIELD(self, u8 *, 0x4C)) {
    case 6:
        t = 1;
        f1 = lbl_8036A364;
        M2C_FIELD(self, u8 *, 0x48) = t;
        f0 = lbl_8036A368;
        M2C_FIELD(self, f32 *, 0x38) = f1;
        M2C_FIELD(self, f32 *, 0x3C) = f0;
        M2C_FIELD(self, f32 *, 0x40) = f1;
        break;
    case 5:
        M2C_FIELD(self, u8 *, 0x48) = 2;
        p = lbl_80274F74;
        f1 = lbl_8036A36C;
        M2C_FIELD(self, f32 *, 0x38) = f1;
        p += 0x94;
        f0 = lbl_8036A370;
        M2C_FIELD(self, f32 *, 0x3C) = f0;
        M2C_FIELD(self, f32 *, 0x40) = f1;
        Fx_AllocSlot(p, 0x32, 1);
        break;
    case 7:
        M2C_FIELD(self, u8 *, 0x48) = 0x32;
        p = lbl_80290388;
        f0 = lbl_8036A308;
        f1 = lbl_8036A374;
        M2C_FIELD(self, f32 *, 0x38) = f0;
        f0 = lbl_8036A378;
        M2C_FIELD(self, f32 *, 0x3C) = f1;
        M2C_FIELD(self, f32 *, 0x40) = f0;
        tmp = Process_Create(p, self);
        M2C_FIELD(tmp, u8 *, 0x4C) = 1;
        Fx_AllocSlot(lbl_80274F74 + 0xA6, 0x32, 1);
        break;
    }

    tmp = Map_Get();
    M2C_FIELD(self, f32 *, 0x50) = M2C_FIELD(tmp, f32 *, 0x6C);
    fn_802031CC((u8 *)self + 0x38, (u8 *)self + 0x38, M2C_FIELD(self, f32 *, 0x50));
    M2C_FIELD(self, f32 *, 0x34) = lbl_8036A30C;
    M2C_FIELD(self, u8 *, 0x49) = 0xC0;
    M2C_FIELD(self, void **, 0x54) = fn_8006D948(lbl_80274F74 + 0x84);

    obj = Heap_Alloc(0x1C);
    if (obj != NULL) {
        M2C_FIELD(obj, s32 *, 0) = 0;
        M2C_FIELD(obj, s32 *, 4) = 0;
        M2C_FIELD(obj, s32 *, 8) = 0;
        M2C_FIELD(obj, s32 *, 0x14) = 0;
        M2C_FIELD(obj, s32 *, 0xC) = 0;
        M2C_FIELD(obj, s32 *, 0x10) = 0;
    }
    M2C_FIELD(self, void **, 0x58) = obj;

    arr = M2C_FIELD(self, void **, 0x58);
    M2C_FIELD(arr, s32 *, 0x18) = 0x7D0;
    n = M2C_FIELD(arr, s32 *, 0x18);
    bytes = n << 5;
    M2C_FIELD(arr, void **, 0) = fn_8022C414(Heap_AllocRaw(bytes + 0x10), fn_8012600C, NULL, 0x20, n);
    M2C_FIELD(arr, void **, 4) = Heap_AllocRaw((M2C_FIELD(arr, s32 *, 0x18) + 1) * 4);
    DCFlushRange(M2C_FIELD(arr, void **, 0), bytes);
    DCFlushRange(M2C_FIELD(arr, void **, 4), (M2C_FIELD(arr, s32 *, 0x18) + 1) * 4);

    {
        register s32 zero = 0;
        off = zero;
        M2C_FIELD(arr, s32 *, 0x14) = zero;
        i = zero;
        idx = zero;
    }
    while (i < M2C_FIELD(arr, s32 *, 0x18)) {
        *(void **)((u8 *)M2C_FIELD(arr, void **, 4) + idx) =
            (u8 *)M2C_FIELD(arr, void **, 0) + off;
        i += 1;
        off += 0x20;
        idx += 4;
    }
    *(s32 *)((u8 *)M2C_FIELD(arr, void **, 4) + (M2C_FIELD(arr, s32 *, 0x18) << 2)) = 0;
    M2C_FIELD(arr, void **, 8) = M2C_FIELD(arr, void **, 4);
    M2C_FIELD(arr, s32 *, 0xC) = 0;
    M2C_FIELD(arr, s32 *, 0x10) = 0;
    M2C_FIELD(self, u8 *, 0x4E) = 1;
    M2C_FIELD(self, u8 *, 0x4D) = 0x64;
}

/* Set up GX point sprites and draw each particle in the FX list (pos + alpha). */
void Fx_DrawParticles(void *arg0) {
    typedef struct Particle {
        struct Particle *next;   // 0x00
        u8 pad0[0x08];
        u8 alpha;                // 0x0C
        u8 pad1[0x07];
        f32 x;                   // 0x14
        f32 y;                   // 0x18
        f32 z;                   // 0x1C
    } Particle;
    typedef struct ParticleList {
        u8 pad[0x0C];
        Particle *head;          // 0x0C
    } ParticleList;
    typedef struct FxParticleSys {
        u8 pad0[0x54];
        s32 atlas;               // 0x54
        ParticleList *list;      // 0x58
    } FxParticleSys;
    extern f32 lbl_8036A30C;
    void Ui_LoadAtlasTex(s32, void *, s32);
    void fn_80222C50(void *, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxDesc(s32, s32);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetZMode(s32, s32, s32);
    void fn_8022100C(s32);
    s32 Map_Get(void);
    void *Camera_GetViewMtx(void);
    void PSMTXConcat(void *, void *, void *);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void fn_80220FC4(s32, s32, s32);
    void fn_80220F84(s32, s32);
    void GXBegin(s32, s32, s32);
    void fn_80066D00(s32);
    FxParticleSys *fx = (FxParticleSys *)arg0;
    u8 texBuf[0x20];
    u8 mtx[0x30];
    s32 map;
    f32 uv0;
    Particle *p;
    f32 vx;
    f32 vy;
    f32 vz;
    u8 alpha;
    ParticleList *list;

    Ui_LoadAtlasTex(fx->atlas, texBuf, 7);
    fn_80222C50(texBuf, 0);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxDesc(0xD, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
    GXSetVtxAttrFmt(0, 0xD, 1, 4, 0);
    GXSetNumChans(1);
    fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
    GXSetCullMode(1);
    GXSetBlendMode(4, 0, 1, 1, 0, 0, 2);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetNumTexGens(0, 0);
    fn_802245D8(1, 4, 5, 0);
    GXSetZMode(1, 3, 0);
    fn_8022100C(2);
    map = Map_Get();
    PSMTXConcat(Camera_GetViewMtx(), (void *)(u32)(map + 0x70), mtx);
    GXLoadPosMtxImm(mtx, 0);
    GXSetCurrentMtx(0);
    fn_80220FC4(0, 0, 1);
    fn_80220F84(0x30, 5);
    uv0 = lbl_8036A30C;
    p = NULL;
    goto loop_test;
loop_body:
    GXBegin(0xB8, 0, 1);
    vz = p->z;
    vy = p->y;
    vx = p->x;
    GXRegs_8036A30C[-0x2000] = vx;
    GXRegs_8036A30C[-0x2000] = vy;
    GXRegs_8036A30C[-0x2000] = vz;
    alpha = p->alpha;
    *(volatile u8 *)&GXRegs_8036A30C[-0x2000] = 0xFF;
    *(volatile u8 *)&GXRegs_8036A30C[-0x2000] = 0xFF;
    *(volatile u8 *)&GXRegs_8036A30C[-0x2000] = 0xFF;
    *(volatile u8 *)&GXRegs_8036A30C[-0x2000] = alpha;
    GXRegs_8036A30C[-0x2000] = uv0;
    GXRegs_8036A30C[-0x2000] = uv0;
    goto loop_test;
loop_test:
    list = fx->list;
    if (p == NULL) {
        p = list->head;
    } else {
        p = p->next;
    }
    if (p != NULL) {
        goto loop_body;
    }
    fn_80220FC4(0, 0, 0);
    fn_80066D00(-1);
}

void fn_801255D4(void *arg0) {
    void fn_8006D8E8(s32);
    void fn_801479C4(u8 *, s32);
    extern u8 lbl_80274F74[];

    if (*(u8 *)((u8 *)arg0 + 0x4C) == 0) {
        fn_801479C4(lbl_80274F74 + 0xBB, 0xFA);
    }
    fn_8006D8E8(*(s32 *)((u8 *)arg0 + 0x6C));
}

void fn_80125624(void *arg0) {
    typedef struct {
        f32 x, y, z;
    } Vec;
    typedef struct {
        u8 pad0[0xE0];
        Vec pos;
    } Cam;
    typedef struct {
        u8 pad0[0x38];
        f32 speedX;
        f32 speedY;
        u8 pad40[0xD];
        u8 unk4D;
        u8 pad4E[2];
        f32 scrollX[2];
        f32 scrollY[2];
        Vec pos;
        s32 unk6C;
    } Obj;
    u8 fn_800AA188(void);
    Cam *fn_80068548(void);
    void fn_8005A1E8(s32, Vec *, Vec *);
    void fn_80009D74(f32, f32, f32, f32);
    void fn_80009F90(s32, s32, s32);
    void fn_801258E4(void *);
    void fn_80007340(void (*)(void *), void *);
    void fn_80007884(void);
    void fn_80007898(s32);
    void fn_8000A248(void);
    void fn_8000A258(void);
    Obj *obj = arg0;
    Vec delta = {0.0f, 0.0f, 0.0f};
    Vec pos = {0.0f, 0.0f, 0.0f};
    Cam *cam;
    f32 scale;
    s32 i;

    if (obj->unk4D == 0) {
        if (fn_800AA188() == 0) {
            return;
        }
        cam = fn_80068548();
        fn_8005A1E8(0, &cam->pos, &delta);
        fn_8005A1E8(0, &obj->pos, &pos);
        delta.x -= pos.x;
        delta.y -= pos.y;
        obj->pos.x = cam->pos.x;
        obj->pos.y = cam->pos.y;
        obj->pos.z = cam->pos.z;
    }
    scale = 1.0f;
    for (i = 0; i < 2; i++) {
        f32 v;
        obj->scrollX[i] += obj->speedX * scale - delta.x;
        obj->scrollY[i] += obj->speedY * scale - delta.y;
        v = obj->scrollX[i];
        obj->scrollX[i] = v - (f32)((s32)(v / 128.0f) * 128);
        v = obj->scrollY[i];
        obj->scrollY[i] = v - (f32)((s32)(v / 128.0f) * 128);
        scale *= 1.5f;
    }
    fn_8000A258();
    fn_80009D74(0.0f, 0.0f, 800.0f, 1.0f);
    fn_80009F90(obj->unk6C, 6, 0x411);
    fn_8000A248();
    fn_80007898(0xB);
    fn_80007340(fn_801258E4, obj);
    fn_80007884();
}

void fn_80125818(void *arg0) {
    void *fn_80040844(void);
    void *fn_8006D948(void *);
    void fn_80147B9C(void *, s32, s32);
    extern u8 lbl_80274F74[];
    extern f32 lbl_8036A308;
    extern f32 lbl_8036A30C;
    extern f32 lbl_8036A378;
    extern f32 lbl_8036A388;
    extern f32 lbl_8036A38C;
    void *self;
    f32 f0;
    f32 f1;

    self = arg0;
    *(void **)((u8 *)self + 0x6C) = fn_8006D948(lbl_80274F74 + 0x84);
    f0 = lbl_8036A30C;
    *(u8 *)((u8 *)self + 0x49) = 0x40;
    *(f32 *)((u8 *)self + 0x60) = f0;
    *(f32 *)((u8 *)self + 0x64) = f0;
    *(f32 *)((u8 *)self + 0x68) = f0;
    *(f32 *)((u8 *)self + 0x50) = f0;
    *(f32 *)((u8 *)self + 0x58) = f0;
    *(f32 *)((u8 *)self + 0x54) = f0;
    *(f32 *)((u8 *)self + 0x5C) = f0;
    if (*(u8 *)((u8 *)self + 0x4C) == 0) {
        fn_80147B9C(lbl_80274F74 + 0xBB, 0x32, 1);
    }
    if (*(u8 *)((u8 *)fn_80040844() + 0x68) == 1) {
        f1 = lbl_8036A388;
        *(u8 *)((u8 *)self + 0x4D) = 1;
        f0 = lbl_8036A378;
        *(f32 *)((u8 *)self + 0x38) = f1;
        *(f32 *)((u8 *)self + 0x3C) = f0;
    } else {
        f1 = lbl_8036A38C;
        *(u8 *)((u8 *)self + 0x4D) = 0;
        f0 = lbl_8036A308;
        *(f32 *)((u8 *)self + 0x38) = f1;
        *(f32 *)((u8 *)self + 0x3C) = f0;
    }
}

void fn_801258E4(void *arg0) {
    typedef struct { f32 v[4][3]; } Quad;
    typedef struct { u8 v[4][4]; } Colors;
    extern Quad lbl_80274F10;
    extern Colors lbl_80274F40;
    extern f32 lbl_8036A390,lbl_8036A394;
    void GXBegin(s32,s32,s32);
    Quad positions=lbl_80274F10;
    Quad texcoords;
    Colors colors=lbl_80274F40;
    u8 *self=arg0;
    s32 layer;
    s32 i;
    f32 z=lbl_8036A30C;
    f32 height;
    f32 width;
    f32 *v;
    f32 *uv;
    u8 *color;
    width=lbl_8036A390;
    height=lbl_8036A394;
    for(layer=0;layer<2;layer++) {
        f32 bottom;
        f32 right;
        f32 x=-*(f32 *)(self+0x50+layer*4);
        f32 y=-*(f32 *)(self+0x58+layer*4);
        right=x+width;
        bottom=y+height;
        texcoords.v[0][0]=x;
        texcoords.v[0][1]=y;
        texcoords.v[1][0]=right;
        texcoords.v[1][1]=y;
        texcoords.v[2][0]=x;
        texcoords.v[2][1]=bottom;
        texcoords.v[3][0]=right;
        texcoords.v[3][1]=bottom;
        color=&colors.v[0][0];
        uv=&texcoords.v[0][0];
        v=&positions.v[0][0];
        GXBegin(0x98,0,4);
        for(i=0;i<4;i++,v+=3,uv+=3,color+=4) {
            {
                f32 x=v[0], y=v[1];
                GXRegs_8036A30C[-0x2000]=x;
                GXRegs_8036A30C[-0x2000]=y;
                GXRegs_8036A30C[-0x2000]=z;
            }
            {
                u8 r=color[0], g=color[1], b=color[2], a=color[3];
                *(volatile u8 *)&GXRegs_8036A30C[-0x2000]=r;
                *(volatile u8 *)&GXRegs_8036A30C[-0x2000]=g;
                *(volatile u8 *)&GXRegs_8036A30C[-0x2000]=b;
                *(volatile u8 *)&GXRegs_8036A30C[-0x2000]=a;
            }
            {
                f32 s=uv[0], t=uv[1];
                GXRegs_8036A30C[-0x2000]=s;
                GXRegs_8036A30C[-0x2000]=t;
            }
        }
    }
}

void fn_80125AE0(void *arg0)
{
  u8 fn_800AA188(void);
  void Math_Lerp(f32, f32, f32, f32);
  f64 sin(void);
  void *Map_Get(void);
  extern f32 lbl_8036A30C;
  extern f32 lbl_8036A398;
  extern f32 lbl_8036A39C;
  extern f64 lbl_8036A3A0;
  extern f64 lbl_8036A3A8;
  f32 b;
  f32 limit;
  f32 a;
  f32 x;
  f64 t;
  f32 temp_f31;
  double new_var;
  if (fn_800AA188() != 0)
  {
    a = *((f32 *) (((char *) arg0) + 0x4C));
    limit = lbl_8036A398;
    *((f32 *) (((char *) arg0) + 0x4C)) = a + *((f32 *) (((char *) arg0) + 0x34));
    a = *((f32 *) (((char *) arg0) + 0x4C));
    if (a >= limit)
    {
      *((f32 *) (((char *) arg0) + 0x4C)) = a - limit;
    }
    Math_Lerp(lbl_8036A30C, lbl_8036A39C, lbl_8036A398, *((f32 *) (((char *) arg0) + 0x4C)));
    x = (f32) sin();
    new_var = lbl_8036A3A0 + x;
    t = new_var;
    t = (*((f32 *) (((char *) arg0) + 0x30))) * t;
    temp_f31 = (f32) (t * lbl_8036A3A8);
    *((f32 *) (((char *) (*((void **) (((char *) Map_Get()) + 0x30)))) + 0x48)) = temp_f31;
  }
}

#pragma scheduling off
void fn_80125B94(void *arg0)
{
  extern f32 lbl_8036A30C;
  extern f32 lbl_8036A3B0;
  extern f32 lbl_8036A35C;
  f32 b;
  f32 a;
  f32 c;
  if ((lbl_8036A30C && lbl_8036A30C) && lbl_8036A30C)
  {
  }
  a = lbl_8036A30C;
  b = lbl_8036A3B0;
  *((f32 *) (((u8 *) arg0) + 0x4C)) = a;
  c = lbl_8036A35C;
  *((f32 *) (((u8 *) arg0) + 0x34)) = b;
  *((f32 *) (((u8 *) arg0) + 0x30)) = c;
}
#pragma scheduling on
s32 fn_80125BB0(void) {
    void *Process_Find(void *);
    s32 GMaterial_AllocMtx(void);
    s32 GMaterial_AllocTexCoord(void);
    s32 GMaterial_AllocTexMap(void);
    s32 GMaterial_AllocTevStage(void);
    void fn_8006A384(void *);
    s32 Ui_LoadAtlasTex(s32, void *, s32);
    void PSMTXConcat(void *, void *, void *);
    void fn_802026E4(void *, void *, void *, void *);
    void C_MTXLightOrtho(void *, f32, f32, f32, f32, f32, f32, f32, f32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80222C50(void *, s32);
    void GXSetTevColorIn(s32, s32, s32, s32, s32);
    void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
    void GXSetTevColorOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevAlphaOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void fn_80224E50(void *, s32, s32);
    extern u8 lbl_80274EE0[0x30];
    extern u8 lbl_80290328[0x60];
    extern f32 lbl_8036A378;
    extern f32 lbl_8036A3B4;
    f32 spF4[3][4];
    f32 spC4[3][4];
    f32 sp94[3][4];
    f32 sp64[3][4];
    u32 sp[15];
    f32 sp44[8];
    f32 temp_f1;
    f32 temp_f0;
    s32 tevStage;
    s32 texCoord;
    s32 texMap;
    s32 mtxId;
    void *proc;
    u8 *cfg;
    s32 z;

    cfg = lbl_80274EE0;
    proc = Process_Find(lbl_80290328);
    if (proc == NULL) {
        return 1;
    }
    fn_8006A384(sp64);
    texCoord = GMaterial_AllocTexCoord();
    tevStage = GMaterial_AllocTevStage();
    texMap = GMaterial_AllocTexMap();
    mtxId = GMaterial_AllocMtx();
    temp_f1 = lbl_8036A3B4 + *(f32 *)((u8 *)proc + 0x4C);
    temp_f0 = lbl_8036A3B4 + *(f32 *)((u8 *)proc + 0x50);
    sp[3] = *(u32 *)(cfg + 0xC);
    sp[4] = *(u32 *)(cfg + 0x10);
    sp[0] = *(u32 *)(cfg + 0x18);
    *(f32 *)&sp[4] = temp_f0;
    sp[1] = *(u32 *)(cfg + 0x1C);
    *(f32 *)&sp[0] = temp_f1;
    *(f32 *)&sp[3] = temp_f1;
    *(f32 *)&sp[1] = temp_f0;
    z = *(s32 *)(cfg + 0x14);
    sp[5] = z;
    sp[12] = sp[3];
    sp[13] = sp[4];
    sp[14] = z;
    sp[2] = *(u32 *)(cfg + 0x20);
    sp[9] = sp[0];
    sp[10] = sp[1];
    sp[11] = *(u32 *)(cfg + 0x20);
    sp[6] = *(u32 *)(cfg + 0x24);
    sp[7] = *(u32 *)(cfg + 0x28);
    sp[8] = *(u32 *)(cfg + 0x2C);
    fn_802026E4(sp94, &sp[9], &sp[6], &sp[12]);
    C_MTXLightOrtho(spC4, -lbl_8036A3B4, lbl_8036A3B4, -lbl_8036A3B4, lbl_8036A3B4, lbl_8036A378, lbl_8036A378, lbl_8036A378, lbl_8036A378);
    PSMTXConcat(sp94, sp64, sp94);
    PSMTXConcat(spC4, sp94, spF4);
    fn_80224E50(spF4, mtxId, 0);
    Ui_LoadAtlasTex(*(s32 *)((u8 *)proc + 0x54), sp44, 5);
    fn_80222C50(sp44, texMap);
    fn_802201A8(texCoord, 0, 0, mtxId, 0, 0x7D);
    GXSetTevOrder(tevStage, texCoord, texMap, 4);
    GXSetTevColorIn(tevStage, 0xF, 0, 8, 0xF);
    GXSetTevColorOp(tevStage, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(tevStage, 7, 7, 7, 0);
    GXSetTevAlphaOp(tevStage, 1, 0, 0, 1, 0);
    return 1;
}

void fn_80125DD8(void *arg0) {
    u8 fn_800AA188(void);
    void Process_ClearFunc(void *);

    if (fn_800AA188() != 0) {
        *(u8 *)((char *)arg0 + 0x49) = *(u8 *)((char *)arg0 + 0x49) - 1;
        if (*(u8 *)((char *)arg0 + 0x49) == 0) {
            *(u8 *)((char *)arg0 + 0x49) = 0;
            Process_ClearFunc(arg0);
        }
        *(f32 *)((char *)arg0 + 0x4C) =
            (*(f32 *)((char *)arg0 + 0x38) * *(f32 *)((char *)arg0 + 0x34))
            + *(f32 *)((char *)arg0 + 0x4C);
        *(f32 *)((char *)arg0 + 0x50) =
            (*(f32 *)((char *)arg0 + 0x3C) * *(f32 *)((char *)arg0 + 0x34))
            + *(f32 *)((char *)arg0 + 0x50);
    }
}

void fn_80125E5C(void *arg0) {
    u8 fn_800AA188();
    if (fn_800AA188() != 0) {
        M2C_FIELD(arg0, f32 *, 0x4C) = (f32) ((M2C_FIELD(arg0, f32 *, 0x38) * M2C_FIELD(arg0, f32 *, 0x34)) + M2C_FIELD(arg0, f32 *, 0x4C));
        M2C_FIELD(arg0, f32 *, 0x50) = (f32) ((M2C_FIELD(arg0, f32 *, 0x3C) * M2C_FIELD(arg0, f32 *, 0x34)) + M2C_FIELD(arg0, f32 *, 0x50));
    }
}

void fn_80125EB8(void *arg0) {
    u8 fn_800AA188(void);
    void Process_ClearFunc(void *);

    if (fn_800AA188() != 0) {
        *(u8 *)((char *)arg0 + 0x49) = *(u8 *)((char *)arg0 + 0x49) + 1;
        if (*(u8 *)((char *)arg0 + 0x49) >= 0x80U) {
            *(u8 *)((char *)arg0 + 0x49) = 0x80;
            Process_ClearFunc(arg0);
        }
        *(f32 *)((char *)arg0 + 0x4C) =
            (*(f32 *)((char *)arg0 + 0x38) * *(f32 *)((char *)arg0 + 0x34))
            + *(f32 *)((char *)arg0 + 0x4C);
        *(f32 *)((char *)arg0 + 0x50) =
            (*(f32 *)((char *)arg0 + 0x3C) * *(f32 *)((char *)arg0 + 0x34))
            + *(f32 *)((char *)arg0 + 0x50);
    }
}

#pragma global_optimizer off
void fn_80125F3C(void *arg0) {
void *Map_Get(void); void fn_80046360(void *,s32,void *,s32,s32,s32);
void *fn_8006D948(void *); s32 fn_80125BB0(void);
extern u8 lbl_80274F74[]; extern f32 lbl_8036A30C,lbl_8036A35C,lbl_8036A3B8;
f32 f0;
f32 f1;
f32 f2;
f2=0.0f;
*(f32 *)((u8 *)arg0+0x4c)=f2;
*(f32 *)((u8 *)arg0+0x50)=f2;
f1=0.1f;
*(f32 *)((u8 *)arg0+0x34)=f1;
*(f32 *)((u8 *)arg0+0x38)=f1;
f0=0.05f;
*(f32 *)((u8 *)arg0+0x3c)=f0;
*(f32 *)((u8 *)arg0+0x40)=f2;
*((u8 *)arg0+0x49)=0;
*(void **)((u8 *)arg0+0x54)=fn_8006D948(lbl_80274F74+0x84);
fn_80046360(Map_Get(),0,(void *)fn_80125BB0,0,0x80,0x8000);
}
#pragma global_optimizer reset
void fn_80125FC8(void *arg0) {
    s32 r = Map_Get();
    fn_800462FC(r, 0, fn_80125BB0);
    fn_8006D8E8(*(s32 *)((u8 *)arg0 + 0x54));
}

void fn_8012600C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
}

void fn_8012601C(void *arg0) {
    extern s32 gUiInputFlags;
    fn_80088F34();
    gUiInputFlags = ((s32*)arg0)[0x1B];
}

void fn_80126050(void *arg0) {
    M2C_UNK Process_Goto(void *, u8);
    extern u8 lbl_80367A6C;
    Process_Goto(arg0, lbl_80367A6C);
}

void fn_80126074(void *arg0) {
    extern s32 gUiInputFlags;
    extern u8 lbl_80367A6C;
    extern u8 lbl_8032FE48[];
    extern u8 lbl_802905F8[];
    
    ((s32*)arg0)[0x1B] = gUiInputFlags;
    fn_80088F34();
    lbl_80367A6C = 0x63;
    Ui_CreateMenu(lbl_8032FE48, arg0, 0);
    Process_Create(lbl_802905F8, arg0);
}

void fn_801260D4(void) {
    extern s32 gUiInputFlags;
    gUiInputFlags &= 0xFFFFFF7F;
}

void fn_801260E4(void *arg0) {
    void fn_80013F48(void *);
    void GfxEnt_UnlinkByName(void *);
    void *Res_GetByName(void *);
    void *Process_Create(void *, s32);
    void Str_CopyPad(void *, void *, s32);
    extern u8 lbl_80320060[];
    extern u8 gScriptCmdNames[];
    extern u8 lbl_80290480[];
    s32 self;
    s32 temp;

    self = (s32)arg0;
    fn_80013F48(lbl_80320060);
    GfxEnt_UnlinkByName(gScriptCmdNames + 0x15B);
    if (Res_GetByName((void *)(self + 0x30)) != 0) {
        temp = (s32)Process_Create(lbl_80290480, 2);
        Str_CopyPad((void *)(temp + 0x30), (void *)(self + 0x30), 0x20);
        *(void **)(temp + 0x50) = Res_GetByName((void *)(temp + 0x30));
        *(u8 *)(temp + 0x58) = 1;
        *(void **)(temp + 0x54) = lbl_80320060;
    }
}

extern u8 lbl_80290480[16];
void fn_80126184(void) {
    Process_UnlinkByKey(&lbl_80290480);
}

void fn_801261AC(s32 arg0) {
    s32 Process_Find(void *);
    M2C_UNK fn_8014C718(void *, s32);
    M2C_UNK fn_8019DB28();
    M2C_UNK strcpy(s32, s32);
    extern u8 lbl_80290480[16];
    extern u8 gBattleState[1400];

    fn_8019DB28();
    strcpy(arg0 + 0x30, Process_Find(lbl_80290480) + 0x30);
    fn_8014C718(gBattleState, arg0);
}

#pragma global_optimizer off
void fn_80126204(void) {
    void fn_80013F48(void *);
    void GfxEnt_UnlinkByName(void *);
    void *Res_GetByName(void *);
    void *Process_Create(void *, s32);
    void Str_CopyPad(void *, void *, s32);
    extern u8 lbl_80320060[];
    extern u8 gScriptCmdNames[];
    extern u8 lbl_80290480[16];
    s32 temp;

    fn_80013F48(lbl_80320060);
    GfxEnt_UnlinkByName(gScriptCmdNames + 0x15B);
    if (Res_GetByName(gScriptCmdNames + 0x16A) != 0) {
        temp = (s32)Process_Create(lbl_80290480, 2);
        Str_CopyPad((void *)(temp + 0x30), gScriptCmdNames + 0x16A, 0x20);
        *(void **)(temp + 0x50) = Res_GetByName((void *)(temp + 0x30));
        *(u8 *)(temp + 0x58) = 1;
        *(void **)(temp + 0x54) = lbl_80320060;
    }
}
#pragma global_optimizer on
void fn_801262A8(s32 arg0) {
    void Process_UnlinkByKey(void *);
    void fn_8014C718(void *, s32);
    void fn_8019DB28(void);
    extern u8 lbl_80290480[16];
    extern u8 gBattleState[1400];

    fn_8019DB28();
    Process_UnlinkByKey(lbl_80290480);
    fn_8014C718(gBattleState, arg0);
}

/* Register tutorial/script command names and their handlers. */
void Script_RegisterCommands(void) {
    void Script_RegisterCommand(void *, void *, s32);
    extern u8 gScriptCmdNames[];
    void ScriptCmd_GameBind(void);
    void ScriptCmd_GameUnbind(void);
    void ScriptCmd_TutorialCall(void);
    void ScriptCmd_QueryLesson(void);
    void ScriptCmd_BeginMapHoldCursor(void);
    void ScriptCmd_EndMapHoldCursor(void);
    void ScriptCmd_pa(void);
    void ScriptCmd_tt(void);
    void ScriptCmd_tr(void);
    void ScriptCmd_Config_Tutorial(void);
    void ScriptCmd_Config_TutSet_unitInfo(void);
    void ScriptCmd_Config_TutSet_terInfo(void);
    void ScriptCmd_Config_TutSet_otheridoshowing(void);
    void ScriptCmd_Config_TutSet_XinfoPage(void);
    void ScriptCmd_Config_TutGet_sfx_vol(void);
    void ScriptCmd_Config_TutSet_sfx_vol(void);
    void ScriptCmd_GetTutorial(void);
    void ScriptCmd_CmLoadScript(void);
    void ScriptCmd_CmFreeScript(void);
    void ScriptCmd_CmSleepScript(void);
    void ScriptCmd_CmWakeupScripts(void);
    void ScriptCmd_seqini(void);
    void ScriptCmd_bmsini(void);
    void ScriptCmd_ArcLoad(void);
    void ScriptCmd_ArcFree(void);
    void ScriptCmd_cmb_mess_load(void);
    void ScriptCmd_TutorialInitialize(void);
    void ScriptCmd_TutorialSallyCreate(void);
    void ScriptCmd_TutorialSallyDelete(void);
    void ScriptCmd_TutorialBasesCreate(void);
    void ScriptCmd_TutorialBasesDelete(void);
    void ScriptCmd_TutorialUnlock(void);
    void fn_80126DB0(void);
    void fn_80126D78(void);
    void fn_80126D40(void);
    void fn_80126E80(void);
    void fn_80126E50(void);
    void fn_80126E20(void);
    void fn_80127000(void);
    void fn_8008F400(void);
    void fn_8008D9B8(void);
    void fn_8008D988(void);
    void fn_8012835C(void);
    void fn_801282E8(void);
    void fn_80128268(void);
    void fn_801281E4(void);
    void fn_80128160(void);

    Script_RegisterCommand(gScriptCmdNames + 0x176, ScriptCmd_GameBind, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x17F, ScriptCmd_GameUnbind, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x18A, ScriptCmd_TutorialCall, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x197, ScriptCmd_QueryLesson, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x1A3, ScriptCmd_BeginMapHoldCursor, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x1B6, ScriptCmd_EndMapHoldCursor, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x1C7, ScriptCmd_pa, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x1CB, ScriptCmd_tt, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x1CF, ScriptCmd_tr, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x1D3, ScriptCmd_Config_Tutorial, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x1E3, ScriptCmd_Config_TutSet_unitInfo, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x1FA, ScriptCmd_Config_TutSet_terInfo, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x210, ScriptCmd_Config_TutSet_otheridoshowing, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x22E, ScriptCmd_Config_TutSet_XinfoPage, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x246, ScriptCmd_Config_TutGet_sfx_vol, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x25C, ScriptCmd_Config_TutSet_sfx_vol, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x272, ScriptCmd_GetTutorial, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x27E, ScriptCmd_CmLoadScript, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x28B, ScriptCmd_CmFreeScript, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x298, ScriptCmd_CmSleepScript, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x2A6, ScriptCmd_CmWakeupScripts, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x2B6, ScriptCmd_seqini, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x2BE, ScriptCmd_bmsini, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x2C6, ScriptCmd_ArcLoad, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x2CE, ScriptCmd_ArcFree, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x2D6, ScriptCmd_cmb_mess_load, 2);
    Script_RegisterCommand(gScriptCmdNames + 0x2E5, ScriptCmd_TutorialInitialize, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x2F8, ScriptCmd_TutorialSallyCreate, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x30C, ScriptCmd_TutorialSallyDelete, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x320, ScriptCmd_TutorialBasesCreate, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x334, ScriptCmd_TutorialBasesDelete, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x348, ScriptCmd_TutorialUnlock, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x357, fn_80126DB0, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x364, fn_80126D78, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x372, fn_80126D40, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x381, fn_80126E80, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x389, fn_80126E50, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x390, fn_80126E20, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x398, fn_80127000, 1);
    Script_RegisterCommand(gScriptCmdNames + 0x3A0, fn_8008F400, 4);
    Script_RegisterCommand(gScriptCmdNames + 0x3B2, fn_8008D9B8, 7);
    Script_RegisterCommand(gScriptCmdNames + 0x3C5, fn_8008D988, 0);
    Script_RegisterCommand(gScriptCmdNames + 0x3D7, fn_8012835C, 3);
    Script_RegisterCommand(gScriptCmdNames + 0x3E7, fn_801282E8, 3);
    Script_RegisterCommand(gScriptCmdNames + 0x3F7, fn_80128268, 3);
    Script_RegisterCommand(gScriptCmdNames + 0x408, fn_801281E4, 3);
    Script_RegisterCommand(gScriptCmdNames + 0x419, fn_80128160, 3);
}

u8 ScriptCmd_GetTutorial(void) {
    extern u8 gBattleState[];
    u8 temp = gBattleState[0x9D];
    temp = (temp >> 1) & 1;
    temp = (temp == 0);
    return temp;
}

void ScriptCmd_Config_TutSet_sfx_vol(s8 arg0) {
    extern u8 gBattleState[];
    gBattleState[0xA5] = arg0;
    fn_80199818(&gBattleState[0x9C], &gBattleState);
}

u8 ScriptCmd_Config_TutGet_sfx_vol(void) {
    extern u8 gBattleState[];
    return gBattleState[0xA5];
}

void ScriptCmd_Config_TutSet_XinfoPage(s8 arg0) {
    extern u8 gBattleState[];
    gBattleState[0xA8] = (u8)arg0;
}

void ScriptCmd_Config_TutSet_otheridoshowing(s32 arg0) {
    extern u8 gBattleState[];
    struct {
        u8 pad:1;
        u8 flag:1;
        u8 rest:6;
    } *p = (void *)(gBattleState + 0x9F);

    if (arg0 == 1) {
        p->flag = 1;
    } else {
        p->flag = 0;
    }
}

void ScriptCmd_Config_TutSet_terInfo(s32 arg0) {
    struct S {
        u8 pad[0x9C];
        u8 skip : 5;
        u8 flag : 1;
    };
    extern struct S gBattleState;
    struct S *p = &gBattleState;
    if (arg0 == 1) {
        p->flag = 1;
        return;
    }
    p->flag = 0;
}

void ScriptCmd_Config_TutSet_unitInfo(s32 arg0) {
    extern u8 gBattleState[];
    struct {
        u8 pad:6;
        u8 flag:1;
        u8 rest:1;
    } *p = (void *)(gBattleState + 0x9C);

    if (arg0 == 1) {
        p->flag = 1;
    } else {
        p->flag = 0;
    }
}

#pragma push
#pragma optimization_level 3
void ScriptCmd_Config_Tutorial(void) {
    struct Work {
        u8 pad0[0x9C];
        u8 a0 : 2;
        u8 a1 : 1;
        u8 a2 : 2;
        u8 a3 : 1;
        u8 a4 : 1;
        u8 a5 : 1;
        u8 b0 : 2;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 2;
        u8 b4 : 1;
        u8 b5 : 1;
        u8 c0 : 1;
        u8 c1 : 1;
        u8 c2 : 1;
        u8 c3 : 1;
        u8 c4 : 3;
        u8 c5 : 1;
        u8 pad9F;
        u8 unkA0;
        u8 padA1[5];
        u8 unkA6;
        u8 padA7;
        u8 unkA8;
        u8 unkA9;
        u8 unkAA;
        u8 padAB;
        s32 unkAC;
        s32 unkB0;
    };
    extern struct Work gBattleState;

    gBattleState.a0 = 1;
    gBattleState.a1 = 0;
    gBattleState.a2 = 1;
    gBattleState.a3 = 0;
    gBattleState.a4 = 0;
    gBattleState.a5 = 0;
    gBattleState.b0 = 0;
    gBattleState.b1 = 0;
    gBattleState.b2 = 0;
    gBattleState.b3 = 2;
    gBattleState.b4 = 0;
    gBattleState.b5 = 0;
    gBattleState.c0 = 0;
    gBattleState.c1 = 0;
    gBattleState.c2 = 1;
    gBattleState.c3 = 1;
    gBattleState.c5 = 0;
    gBattleState.unkA0 = 0x14;
    gBattleState.unkA8 = 0;
    gBattleState.unkAC = 0;
    gBattleState.unkA9 = 0;
    gBattleState.unkAA = 0;
    gBattleState.unkB0 = 0;
    gBattleState.unkA6 = 1;
}
#pragma pop
extern u16 lbl_80290564[];
s32 ScriptCmd_TutorialInitialize(void)
{
    s32 fn_800C0658(void);
    void Process_CreateChild(u16 *, s32);
    void fn_80013864(void);
    extern u16 lbl_80290564[];

    Process_CreateChild(lbl_80290564, fn_800C0658());
    fn_80013864();
    return 1;
}

void fn_80126A98(s32 arg0) {
    extern u8 gUiContext[];
    extern u8 gBattleState[];
    extern u8 gScriptCmdNames[];
    void TalkUi_ShowMsg(void *);
    void fn_8011D650(void *);
    void Process_ClearFunc(s32);
    struct {
        u8 hi : 6;
        u8 mid : 1;
        u8 lo : 1;
    } *bf;

    switch ((s32)gUiContext[8]) {
    case 0x81:
        bf = (void *)&gBattleState[0x9D];
        bf->mid = 0;
        TalkUi_ShowMsg(gScriptCmdNames + 0x42A);
        break;
    case 0x80:
        bf = (void *)&gBattleState[0x9D];
        bf->mid = 1;
        fn_8011D650(gBattleState);
        break;
    }
    Process_ClearFunc(arg0);
}

void fn_80126B34(s32 arg0) {
#pragma cplusplus on
    void *fn_8013BC10(void *,void *);
    void fn_80024398(void *,s32,s32);
    extern u8 lbl_80275048[];
    extern f32 lbl_8036A400;
    struct Item {
        virtual void v0()=0;
        virtual void v1()=0;
        virtual void v2()=0;
        virtual void v3()=0;
        virtual void v4()=0;
        virtual void v5()=0;
        virtual void v6()=0;
        virtual void v7()=0;
        virtual void v8()=0;
        virtual void v9()=0;
        virtual void v10()=0;
        virtual void v11()=0;
        virtual void v12()=0;
        virtual void v13()=0;
        virtual void v14()=0;
        virtual void v15()=0;
        virtual void v16()=0;
        virtual void v17()=0;
        virtual void v18(s32)=0;
        virtual void v19()=0;
        virtual void v20(s32)=0;
    };
    struct Menu {
        u8 pad[4];
        virtual void v0()=0;
        virtual void v1()=0;
        virtual void v2()=0;
        virtual void v3()=0;
        virtual void v4()=0;
        virtual void v5()=0;
        virtual void v6()=0;
        virtual void v7()=0;
        virtual void v8()=0;
        virtual void v9()=0;
        virtual void v10()=0;
        virtual void v11()=0;
        virtual void v12()=0;
        virtual void v13()=0;
        virtual void v14()=0;
        virtual Item * v15(s32)=0;
    };
    u8 *menu;
    s32 index;
    Item *item;
    f32 z;
    menu=(u8*)fn_8013BC10(lbl_80275048+0x43D,lbl_80275048+0x445);
    *(s16*)(menu+0xC)=0x160;
    *(s16*)(menu+0xE)=0x20;
    z=lbl_8036A400;
    *(s16*)(menu+0x1C)=0x20;
    *(s16*)(menu+8)=0x80;
    *(s16*)(menu+0xA)=0xF0;
    *(f32*)(menu+0x18)=10.0f;
    menu[0x24]=1;
    index=0;
    while (((Menu*)menu)->v15(index)!=0) {
        item=((Menu*)menu)->v15(index);
        item->v18(2);
        item->v20(3);
        index++;
    }
    fn_80024398(menu,arg0,0);
#pragma cplusplus reset
}

void fn_80126C44(void) {
    extern s32 gUiInputFlags;
    gUiInputFlags &= ~0x800;
}

void fn_80126C54(void *arg0) {
    void fn_8011D908(void *, void *);
    extern u8 gScriptCmdNames[];
    extern s32 gUiInputFlags;
    gUiInputFlags |= 0x800;
    fn_8011D908(gScriptCmdNames + 0x44e, arg0);
}

s32 ScriptCmd_TutorialBasesDelete(void) {
    M2C_UNK fn_8016969C();
    fn_8016969C();
    return 1;
}

s32 ScriptCmd_TutorialBasesCreate(void) {
    extern u16 gScriptCmdNames[103];
    Process_FindByName((u16*)((u8*)&gScriptCmdNames + 0x467));
    fn_80169804();
    return 1;
}

s32 ScriptCmd_TutorialSallyDelete(void) {
    M2C_UNK fn_8011AC44();
    fn_8011AC44();
    return 1;
}

s32 ScriptCmd_TutorialSallyCreate(void) {
    extern u16 gScriptCmdNames[103];
    Process_FindByName((u16*)((u8*)&gScriptCmdNames + 0x467));
    fn_8011AC78();
    return 1;
}

s32 fn_80126D40(u8 arg0) {
    extern u16 gBattleState[];
    u16* ptr = (u16*)((u32)gBattleState + 0x84);
    Status_Set(ptr, arg0);
    return 1;
}

s32 fn_80126D78(u8 arg0) {
    extern u16 gBattleState[];
    u16* ptr = (u16*)((u32)gBattleState + 0x84);
    Status_Clear(ptr, arg0);
    return 1;
}

s32 fn_80126DB0(u8 arg0) {
    extern u16 gBattleState[];
    u16* ptr = (u16*)((u32)gBattleState + 0x74);
    Status_Set(ptr, arg0);
    return 1;
}

s32 ScriptCmd_TutorialUnlock(u8 arg0) {
    extern u16 gBattleState[];
    u16* ptr = (u16*)((u32)gBattleState + 0x74);
    Status_Clear(ptr, arg0);
    return 1;
}

s32 fn_80126E20(void) {
    extern u16 lbl_80290550[];
    Process_Create(lbl_80290550, 3);
    return 1;
}

extern u16 lbl_8029053C[];
s32 fn_80126E50(void) {
    Process_Create(lbl_8029053C, 3);
    return 1;
}

extern u16 lbl_80290528[];
s32 fn_80126E80(void) {
    Process_Create(lbl_80290528, 3);
    return 1;
}

s32 ScriptCmd_cmb_mess_load(s32 arg0, s32 arg1) {
    void ScriptCmd_CmLoadScript(s32);
    s8 fn_8005BA00(void);
    void fn_8005BA08(s8);
    void FileCache_OrFlags(s32, s32);
    void Archive_Load(s32);
    s32 fn_800C4740(void);
    s8 temp_r31;

    temp_r31 = fn_8005BA00();
    fn_8005BA08((s8)fn_800C4740());
    ScriptCmd_CmLoadScript(arg0);
    FileCache_OrFlags(arg0, 4);
    Archive_Load(arg1);
    FileCache_OrFlags(arg1, 4);
    fn_8005BA08(temp_r31);
    return 1;
}

s32 ScriptCmd_ArcFree(void) {
    M2C_UNK fn_8005C7C8();
    fn_8005C7C8();
    return 1;
}

s32 ScriptCmd_ArcLoad(void) {
    M2C_UNK Archive_Load();
    Archive_Load();
    return 1;
}

s32 ScriptCmd_tr(void) {
    M2C_UNK fn_8011D5EC();
    fn_8011D5EC();
    return 1;
}

s32 ScriptCmd_tt(s32 arg0) {
    void *Process_FindByName(void *);
    void fn_8011D87C(s32);
    void fn_8011D908(s32, s32);
    extern u8 gScriptCmdNames[];

    if (Process_FindByName(gScriptCmdNames + 0x472) != NULL) {
        fn_8011D87C(arg0);
        return 1;
    }
    fn_8011D908(arg0, 0);
    return 1;
}

s32 fn_80127000(void *arg0) {
    void MsgTip_Create(void *, s32);
    MsgTip_Create(arg0, 0);
    return 1;
}

s32 ScriptCmd_EndMapHoldCursor(void) {
    void fn_8000BE54(void *);
    extern u8 lbl_80290510[];
    fn_8000BE54(lbl_80290510);
    return 0;
}

s32 ScriptCmd_BeginMapHoldCursor(void) {
    extern u16 lbl_80290510[];
    Process_Create(lbl_80290510, 4);
    return 0;
}

void fn_80127084(void) {
    M2C_UNK fn_800F1BFC();
    fn_800F1BFC();
}

void *fn_801270A4(void) {
    void *Process_FindByName(void *);
    void fn_8000B950(void *, void (*)(void *));
    void fn_80127150(void *);
    extern u8 gScriptCmdNames[];
    extern void *lbl_80367A68;
    void *var;

    lbl_80367A68 = 0;
    var = Process_FindByName(gScriptCmdNames + 0x467);
    if (var == NULL) {
        var = Process_FindByName(gScriptCmdNames + 0x15B);
        if (var == NULL) {
            var = Process_FindByName(gScriptCmdNames + 0x479);
            if (var == NULL) {
                var = Process_FindByName(gScriptCmdNames + 0x484);
            }
        }
    }
    fn_8000B950(var, fn_80127150);
    if (lbl_80367A68 != NULL) {
        return lbl_80367A68;
    }
    return var;
}

void fn_80127150(void *arg0) {
    extern void *lbl_80367A68;
    if (((u8) M2C_FIELD(arg0, u8 *, 0x2D) == 0) && (M2C_FIELD(arg0, u8 *, 0x2C) & 2)) {
        lbl_80367A68 = arg0;
    }
}

void fn_80127170(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    void Sound_Create(void *, void *);
    extern u8 lbl_80290504[];
    extern u8 gScriptCmdNames[];

    Sound_Create(gScriptCmdNames + 0x493, Process_CreateChild(lbl_80290504, arg0));
}

void fn_801271B0(s32 arg0) {
    void *Sound_FindByName(void *);
    void *Process_Create(void *, s32);
    void *Sound_Create(void *, void *);
    void Sound_FadeFromZero(void *, u8);
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Text_Draw(s32, s32, s32, void *, ...);
    void Process_ClearFunc(void *);
    extern u32 *gPadInput;
    extern u8 gScriptCmdNames[];
    extern u8 lbl_802904E0[];
    extern f32 lbl_8036A3D4;
    extern f32 lbl_8036A404;

    u32 held;
    u32 down;
    void *proc;
    void *proc9;

    held = gPadInput[1];
    down = held & (gPadInput[2] ^ held);

    if ((down & 0x08000008) && Sound_FindByName(gScriptCmdNames + 0x493) != NULL) {
        proc = Process_Create(lbl_802904E0, arg0);
        *(void **)((u8 *)proc + 0x30) = Sound_Create(gScriptCmdNames + 0x49B, proc);
        Sound_FadeFromZero(*(void **)((u8 *)proc + 0x30), 5);
    }
    if ((down & 0x04000004) && Sound_FindByName(gScriptCmdNames + 0x493) != NULL) {
        proc = Process_Create(lbl_802904E0, arg0);
        *(void **)((u8 *)proc + 0x30) = Sound_Create(gScriptCmdNames + 0x4A5, proc);
        Sound_FadeFromZero(*(void **)((u8 *)proc + 0x30), 5);
    }
    if ((down & 0x01000001) && Sound_FindByName(gScriptCmdNames + 0x493) != NULL) {
        proc = Process_Create(lbl_802904E0, arg0);
        *(void **)((u8 *)proc + 0x30) = Sound_Create(gScriptCmdNames + 0x4AF, proc);
        Sound_FadeFromZero(*(void **)((u8 *)proc + 0x30), 5);
    }
    if ((down & 0x02000002) && Sound_FindByName(gScriptCmdNames + 0x493) != NULL) {
        proc = Process_Create(lbl_802904E0, arg0);
        *(void **)((u8 *)proc + 0x30) = Sound_Create(gScriptCmdNames + 0x4B9, proc);
        Sound_FadeFromZero(*(void **)((u8 *)proc + 0x30), 5);
    }
    if ((down & 0x100) && Sound_FindByName(gScriptCmdNames + 0x493) != NULL) {
        proc = Process_Create(lbl_802904E0, arg0);
        *(void **)((u8 *)proc + 0x30) = Sound_Create(gScriptCmdNames + 0x4C3, proc);
        Sound_FadeFromZero(*(void **)((u8 *)proc + 0x30), 5);
    }
    if ((down & 0x200) && Sound_FindByName(gScriptCmdNames + 0x493) != NULL) {
        proc = Process_Create(lbl_802904E0, arg0);
        *(void **)((u8 *)proc + 0x30) = Sound_Create(gScriptCmdNames + 0x4CD, proc);
        Sound_FadeFromZero(*(void **)((u8 *)proc + 0x30), 5);
    }
    if ((down & 0x400) && Sound_FindByName(gScriptCmdNames + 0x493) != NULL) {
        proc = Process_Create(lbl_802904E0, arg0);
        *(void **)((u8 *)proc + 0x30) = Sound_Create(gScriptCmdNames + 0x4D7, proc);
        Sound_FadeFromZero(*(void **)((u8 *)proc + 0x30), 5);
    }
    if ((down & 0x800) && Sound_FindByName(gScriptCmdNames + 0x493) != NULL) {
        proc = Process_Create(lbl_802904E0, arg0);
        *(void **)((u8 *)proc + 0x30) = Sound_Create(gScriptCmdNames + 0x4E1, proc);
        Sound_FadeFromZero(*(void **)((u8 *)proc + 0x30), 5);
    }
    if ((down & 0x10) && Sound_FindByName(gScriptCmdNames + 0x493) != NULL) {
        proc9 = Process_Create(lbl_802904E0, arg0);
        *(void **)((u8 *)proc9 + 0x30) = Sound_Create(gScriptCmdNames + 0x4EB, proc9);
        Sound_FadeFromZero(*(void **)((u8 *)proc9 + 0x30), 5);
    }

    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036A3D4, lbl_8036A3D4, lbl_8036A3D4, lbl_8036A404);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    Text_Draw(0x32, 0x154, 1, gScriptCmdNames + 0x4F5);

    if (gPadInput[1] == 0x160) {
        Process_ClearFunc((void *)arg0);
    }
}

void fn_80127594(void *arg0) {
    M2C_UNK Sound_FadeToVol(s32, M2C_UNK);
    Sound_FadeToVol(M2C_FIELD(arg0, s32 *, 0x30), 5);
}

s32 ScriptCmd_pa(s32 arg0) {
    void *Process_Create(void *, s32);
    extern u8 lbl_802904C0[32];
    extern void *gPadInput;
    void *temp_r3;

    temp_r3 = Process_Create(lbl_802904C0, 2);
    *(s32 *)((u8 *)temp_r3 + 0x30) = arg0;
    *(u32 *)((u8 *)temp_r3 + 0x34) = 0;
    *(u8 *)((u8 *)temp_r3 + 0x38) = 0x10;
    *(u8 *)((u8 *)temp_r3 + 0x39) = 1;

    *(u32 *)((u8 *)gPadInput + 0x8) = 0;
    *(u32 *)((u8 *)gPadInput + 0x4) = 0;
    *(u32 *)((u8 *)gPadInput + 0xc) = 0;
    *(u32 *)((u8 *)gPadInput + 0x10) = 0;

    *(u8 *)(*(u8 **)gPadInput + 2) = 0;
    *(u8 *)(*(u8 **)gPadInput + 3) = 0;
    *(u8 *)(*(u8 **)gPadInput + 4) = 0;
    *(u8 *)(*(u8 **)gPadInput + 5) = 0;
    *(u8 *)(*(u8 **)gPadInput + 6) = 0;
    *(u8 *)(*(u8 **)gPadInput + 7) = 0;
    return 1;
}

void fn_8012767C(void)
{
    extern u32 gUiInputFlags;
    extern void *volatile gPadInput;

    gUiInputFlags &= ~0x20;
    gUiInputFlags |= 0x80;

    *(u32 *)((u8 *)gPadInput + 0x08) = 0;
    *(u32 *)((u8 *)gPadInput + 0x04) = 0;
    *(u32 *)((u8 *)gPadInput + 0x0C) = 0;
    *(u32 *)((u8 *)gPadInput + 0x10) = 0;

    *(u8 *)(*(u8 **)gPadInput + 0x02) = 0;
    *(u8 *)(*(u8 **)gPadInput + 0x03) = 0;
    *(u8 *)(*(u8 **)gPadInput + 0x04) = 0;
    *(u8 *)(*(u8 **)gPadInput + 0x05) = 0;
    *(u8 *)(*(u8 **)gPadInput + 0x06) = 0;
    *(u8 *)(*(u8 **)gPadInput + 0x07) = 0;
}

#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
void fn_80127700(void *self) {
    extern u32 gUiInputFlags;
    extern void *volatile gPadInput;
    void Process_ClearFunc(void *);
    u8 *script;
    s32 cmd;
    u32 mask;
    u32 zero;
    u8 t;

    mask = 0;
    gUiInputFlags |= 0x20;
    gUiInputFlags &= ~0x80;

    *(u8 *)((u8 *)self + 0x39) = *(u8 *)((u8 *)self + 0x39) - 1;

    *(u32 *)((u8 *)gPadInput + 0x8) = mask;
    *(u32 *)((u8 *)gPadInput + 0x4) = mask;
    *(u32 *)((u8 *)gPadInput + 0xC) = mask;
    *(u32 *)((u8 *)gPadInput + 0x10) = mask;
    *(u8 *)(*(u8 **)gPadInput + 2) = mask;
    *(u8 *)(*(u8 **)gPadInput + 3) = mask;
    *(u8 *)(*(u8 **)gPadInput + 4) = mask;
    *(u8 *)(*(u8 **)gPadInput + 5) = mask;
    *(u8 *)(*(u8 **)gPadInput + 6) = mask;
    *(u8 *)(*(u8 **)gPadInput + 7) = mask;

    if (*(u8 *)((u8 *)self + 0x39) != 0) {
        return;
    }

dispatch:
    script = *(u8 **)((u8 *)self + 0x30);
    *(u8 **)((u8 *)self + 0x30) = script + 1;
    cmd = (s8)*script;
    switch (cmd) {
    case 0:
        break;
    case '1':
        mask = 0x05000005;
        break;
    case '2':
        mask = 0x04000004;
        break;
    case '3':
        mask = 0x06000006;
        break;
    case '4':
        mask = 0x01000001;
        break;
    case '6':
        mask = 0x02000002;
        break;
    case '7':
        mask = 0x09000009;
        break;
    case '8':
        mask = 0x08000008;
        break;
    case '9':
        mask = 0x0A00000A;
        break;
    case 'A':
        mask = 0x100;
        break;
    case 'B':
        mask = 0x200;
        break;
    case 'X':
        mask = 0x400;
        break;
    case 'Y':
        mask = 0x800;
        break;
    case 'Z':
        mask = 0x10;
        break;
    case 'L':
        mask = 0x40;
        break;
    case 'R':
        mask = 0x20;
        break;
    case 'S':
        mask = 0x1000;
        break;
    case '<':
        *(u8 *)((u8 *)self + 0x38) = (u8)((*(u8 *)((u8 *)self + 0x38) * 2) & 0xFE);
        goto dispatch;
    case '>':
        *(u8 *)((u8 *)self + 0x38) >>= 1;
        goto dispatch;
    case '_':
        mask = 0xF;
        break;
    default:
        break;
    }
    t = *(u8 *)((u8 *)self + 0x38);
    zero = 0;
    *(u8 *)((u8 *)self + 0x39) = t;
    *(u32 *)((u8 *)gPadInput + 0x8) = zero;
    *(u32 *)((u8 *)gPadInput + 0x4) = mask;
    *(u32 *)((u8 *)gPadInput + 0xC) = mask;
    *(u32 *)((u8 *)gPadInput + 0x10) = mask;

    if ((s8)**(u8 **)((u8 *)self + 0x30) == 0) {
        Process_ClearFunc(self);
    }
}
#pragma pop
s32 ScriptCmd_GameUnbind(void) {
    void Process_UnlinkByKey(void *);
    extern u8 lbl_802904AC[];
    Process_UnlinkByKey(lbl_802904AC);
    return 1;
}

s32 ScriptCmd_GameBind(void) {
    void *Process_FindByName(void *);
    void fn_8000B950(void *, void (*)(void *));
    void *Process_CreateChild(void *, void *);
    void fn_80127150(void *);
    extern u8 gScriptCmdNames[];
    extern void *lbl_80367A68;
    extern u8 lbl_802904AC[];
    void *var;

    lbl_80367A68 = 0;
    var = Process_FindByName(gScriptCmdNames + 0x467);
    if (var == NULL) {
        var = Process_FindByName(gScriptCmdNames + 0x15B);
        if (var == NULL) {
            var = Process_FindByName(gScriptCmdNames + 0x479);
            if (var == NULL) {
                var = Process_FindByName(gScriptCmdNames + 0x484);
            }
        }
    }
    fn_8000B950(var, fn_80127150);
    Process_CreateChild(lbl_802904AC, lbl_80367A68 != NULL ? lbl_80367A68 : var);
    return 1;
}

s32 ScriptCmd_bmsini(void) {
    void fn_8014D55C(void *);
    extern u8 gBattleState[];
    fn_8014D55C(gBattleState);
    return 1;
}

s32 ScriptCmd_seqini(void) {
    /* Init sequence: set UI flags, jump map proc, unlink overlay gfx, clear move/queue/units. */
    void *Process_FindByName(void *);
    void Process_Goto(void *, s32);
    void GfxEnt_UnlinkByName(void *);
    void fn_8008D988(void);
    void Map_HideMoveLimitView(void);
    void ProcessQueue_Clear(void);
    void fn_800162B8(void);
    extern u16 gScriptCmdNames[];
    extern volatile u32 gUiInputFlags;
    void *proc;
    u32 flags;

    proc = (u8 *)gScriptCmdNames + 0x479;
    flags = gUiInputFlags | 0x890;
    gUiInputFlags = flags;
    flags &= ~0x20;
    gUiInputFlags = flags;
    proc = Process_FindByName(proc);
    if (proc != NULL) {
        Process_Goto(proc, 4);
    }
    GfxEnt_UnlinkByName((u8 *)gScriptCmdNames + 0x472);
    GfxEnt_UnlinkByName((u8 *)gScriptCmdNames + 0x50c);
    GfxEnt_UnlinkByName((u8 *)gScriptCmdNames + 0xe0);
    GfxEnt_UnlinkByName((u8 *)gScriptCmdNames + 0x467);
    GfxEnt_UnlinkByName((u8 *)gScriptCmdNames + 0x15b);
    GfxEnt_UnlinkByName((u8 *)gScriptCmdNames + 0x513);
    fn_8008D988();
    Map_HideMoveLimitView();
    ProcessQueue_Clear();
    fn_800162B8();
    return 1;
}

void MapUi_ClearOverlays(void) {
    extern u16 gScriptCmdNames[];

    GfxEnt_UnlinkByName((u8 *)gScriptCmdNames + 0x472);
    GfxEnt_UnlinkByName((u8 *)gScriptCmdNames + 0x50c);
    GfxEnt_UnlinkByName((u8 *)gScriptCmdNames + 0xe0);
    GfxEnt_UnlinkByName((u8 *)gScriptCmdNames + 0x467);
    GfxEnt_UnlinkByName((u8 *)gScriptCmdNames + 0x15b);
    GfxEnt_UnlinkByName((u8 *)gScriptCmdNames + 0x513);
    fn_8008D988();
    Map_HideMoveLimitView();
    ProcessQueue_Clear();
    fn_800162B8();
}

u8 ScriptCmd_QueryLesson(s32 arg0) {
    void *Process_Find(void *);
    s32 Str_Cmp(s32, s32);
    s32 temp_r3;

    temp_r3 = (s32)Process_Find(lbl_80290480);
    if (temp_r3 == 0) {
        return 0U;
    }
    return (u8)(Str_Cmp(arg0, temp_r3 + 0x30) == 0);
}

s32 ScriptCmd_TutorialCall(void *arg0) {
    extern u8 gScriptCmdNames[];
    extern u8 lbl_80290480[16];
    extern u8 lbl_80320060[];

    void GfxEnt_UnlinkByName(void *);
    void *Res_GetByName(void *);
    void *Process_Create(void *, s32);
    void Str_CopyPad(void *, void *, s32);

    void *result;
    u8 *obj;

    GfxEnt_UnlinkByName(gScriptCmdNames + 0x15B);
    result = Res_GetByName(arg0);
    if (result == NULL) {
        return 0;
    }
    obj = (u8 *)Process_Create(lbl_80290480, 2);
    Str_CopyPad(obj + 0x30, arg0, 0x20);
    *(void **)(obj + 0x50) = Res_GetByName(obj + 0x30);
    obj[0x58] = 1;
    *(void **)(obj + 0x54) = lbl_80320060;
    return 1;
}

void fn_80127C48(void) {
    Process_Find(&lbl_80290480);
}

void fn_80127C70(void) {

}

void fn_80127C74(void) {

}

void fn_80127C78(void *arg0) {
    if ((u8) M2C_FIELD(arg0, u8 *, 0x58) != 0) {
        M2C_FIELD(arg0, u8 *, 0x58) = 0U;
        fn_80013778(M2C_FIELD(arg0, s32 *, 0x54), M2C_FIELD(arg0, s32 *, 0x50));
    }
    fn_800138BC(M2C_FIELD(arg0, s32 *, 0x54));
    if (fn_800142B8() != 6) {
        Process_ClearFunc(arg0);
    }
}

void fn_80127CDC(void) {
    extern void *gPadInput;
    extern s32 gUiInputFlags;
    extern u8 gScriptCmdNames[];
    extern u8 lbl_80290608[];
    u32 Process_FindByName(void *);
    void *Process_Create(void *, s32);
    s32 fn_80089634(void);
    s32 fn_8008A56C(void);
    u16 val;
    s32 temp_r31;
    s32 temp_r3;
    void *obj;

    val = **(u16 **)gPadInput;
    if (val & (*(u32 *)((u8 *)gPadInput + 0x14) ^ val) & 0x1000) {
        temp_r31 = fn_80089634();
        temp_r3 = fn_8008A56C();
        if (!((u16)(temp_r3 | temp_r31) & 0xD) && (gUiInputFlags & 0x10) && !(gUiInputFlags & 4)
            && Process_FindByName(gScriptCmdNames + 0x156) == 0) {
            obj = Process_Create(lbl_80290608, 2);
            ((u8 *)obj)[0x2B] = 0x7B;
        }
    }
}

extern u32 gUiInputFlags;
#include "common.h"

extern f32 lbl_8036A278;
extern f32 lbl_8036A27C;
extern f32 lbl_8036A280;
extern f32 lbl_8036A284;
extern f32 lbl_8036A288;
extern f32 lbl_8036A28C;
extern f32 lbl_8036A290;
extern f32 lbl_8036A294;
extern f32 lbl_8036A298;
extern f64 lbl_8036A2A0;

extern s32 *Ui_GetColor(s32);
extern void Prim2D_SetText(void *);
extern void Prim2D_SetColorPacked(s32 *);
extern void Prim2D_SetColor(s32, s32, s32, s32);
extern void Prim2D_SetPosCorners(f32, f32, f32, f32);
extern void Prim2D_SetPos(f32, f32);
extern void Prim2D_EndPrim(void);
extern void Prim2D_AddPrim(s32);
extern void Prim2D_SetColorByte(u8);
extern void Prim2D_ClearCallbacks(void);
extern void Prim2D_SetCallback(void *, s32);
extern void Prim2D_SetTransform(f32, f32, f32, f32);
extern void Prim2D_SetTex(s32, s32);
extern void Prim2D_PrepareTex(void);
extern void Prim2D_Begin(void);
extern void fn_80057020(u32);
extern void fn_80057860(s32);
extern s32 sprintf(void *, void *, s32);
extern s32 fn_80234200(void *, s32);

void fn_80121D30(void);
#include "common.h"
extern f32 lbl_8036A30C;
extern f32 lbl_8036A35C;
extern f32 lbl_8036A3B8;
extern s32 lbl_80274F68[2];
extern u8 gBattleSkyIndex;
extern void* jumptable_80290434[];
extern f32 lbl_8036A308;
extern f32 lbl_8036A30C;
extern void *lbl_80274F74;
extern void *lbl_80367A68;
#include "global.h"
#include "unit.h"

extern u32* gUnitStructs; // gPadInput
extern u8* gSomeGlobal;
