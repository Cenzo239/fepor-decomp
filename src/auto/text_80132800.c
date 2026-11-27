/* Functions from 0x80132800 to 0x80149F38, found by decomp-toolkit. */
#include "common.h"
#pragma cplusplus on
    struct PortraitPanelObject {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3(s32) = 0;
        u8 pad4[6];
        s16 unkA;
        s16 unkC;
        s16 unkE;
        s16 unk10;
        s16 unk12;
        s16 unk14;
        s16 unk16;
        s16 unk18;
        u8 pad1A[0x22 - 0x1A];
        s16 unk22;
        u8 pad24[0x34 - 0x24];
        u32 unk34;
        u8 pad38[4];
        void *unk3C;
        u32 unk40;
        s16 unk44;
        s16 unk46;
        s16 unk48;
        s16 unk4A;
        s32 unk4C;
        u8 *unk50;
    };
struct MenuCenteredLabel {
virtual void v0()=0;
virtual void *getText()=0;
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
virtual void v18()=0;
virtual void v19()=0;
virtual void v20()=0;
virtual u8 test(s32)=0;
};
struct MenuCenteredPanel { u32 pad;
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
virtual void v18()=0;
virtual void v19()=0;
virtual void v20()=0;
virtual void v21()=0;
virtual void v22()=0;
virtual void v23()=0;
virtual void v24()=0;
virtual void v25()=0;
virtual void v26()=0;
virtual void v27()=0;
virtual void v28()=0;
virtual void v29()=0;
virtual void v30()=0;
virtual void v31()=0;
virtual void v32()=0;
virtual void v33()=0;
virtual void v34()=0;
virtual void v35()=0;
virtual void v36()=0;
virtual void v37()=0;
virtual s32 height()=0;
};
#pragma cplusplus reset
#pragma cplusplus on
struct MenuDDEntry { u8 pad[0x40]; u8 id; };
struct MenuDD { u8 pad[4];
virtual s32 v0()=0;
virtual s32 v1()=0;
virtual s32 v2()=0;
virtual s32 v3()=0;
virtual s32 v4()=0;
virtual s32 v5()=0;
virtual s32 v6()=0;
virtual s32 v7()=0;
virtual s32 v8()=0;
virtual s32 v9()=0;
virtual s32 v10()=0;
virtual s32 v11()=0;
virtual s32 v12()=0;
virtual s32 v13()=0;
virtual s32 v14()=0;
virtual s32 v15()=0;
virtual s32 v16()=0;
virtual s32 v17()=0;
virtual s32 v18()=0;
virtual s32 v19()=0;
virtual s32 v20()=0;
virtual s32 v21()=0;
virtual s32 v22()=0;
virtual s32 v23()=0;
virtual s32 v24()=0;
virtual s32 v25()=0;
virtual s32 v26()=0;
virtual s32 v27()=0;
virtual s32 v28()=0;
virtual s32 v29()=0;
virtual s32 v30()=0;
virtual s32 v31()=0;
virtual s32 v32()=0;
virtual s32 v33()=0;
virtual s32 v34()=0;
virtual s32 v35()=0;
};
struct Menu349 {
virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void prepare()=0;
virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0; virtual void v8()=0; virtual void v9()=0; virtual void v10()=0;
virtual void draw(s16,s16,s16,s16,u8)=0;
};
struct Menu42 {
virtual void v0()=0; virtual void v1()=0; virtual void v2()=0;
virtual void draw(s32)=0;
virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0;
virtual void v8()=0; virtual void v9()=0; virtual s32 page()=0;
virtual void v11()=0; virtual void v12()=0; virtual void v13()=0;
virtual s32 item(void *)=0; virtual void row(s16,s16,s32,void *,s32)=0;
virtual void v16()=0; virtual void prepare()=0;
};
struct Menu42Callback { void (Menu42::*method)(s32); s32 arg; };
static inline void Menu42Visit(void *first, void *last, Menu42Callback cb) {
while(first!=last) {
Menu42 *obj=*(Menu42 **)((u8*)first+8);
(obj->*cb.method)(cb.arg);
first=*(void **)((u8*)first+4);
}
}
#pragma cplusplus reset
#include "common.h"
#include "dolphin/os.h"

extern u16 gSystemSave[36]; // 72 bytes 
extern f32 lbl_8036A6D0;
extern f32 gUiMenuSlotPlainTextScale;
extern f64 lbl_8036A720;

extern u16 gSystemSave[36]; // 72 bytes = 36 * 2-byte entries
extern f32 lbl_8036A5A8;
extern const f32 lbl_8036A5AC;
extern f32 lbl_8036A5B8;

extern u8 gSeCueSlots[1344];

static inline s32 mul_ss(s32 a, s32 b) {
    return a * b;
}

static inline f32 mul_ss_f(s32 a, s32 b) {
    return (f32)(a * b);
}

typedef struct Vec2s {
    s16 x;
    s16 y;
} Vec2s;

typedef struct MenuGridLayout {
    u8 pad00[0x12];
    s16 left;
    s16 top;
    s16 right;
    u8 pad18[0x26];
    s16 index;
    u8 pad40[4];
    s16 columns;
    s16 rowHeight;
    s16 xOffset;
    s16 yOffset;
} MenuGridLayout;
static inline s16 MenuGridColumn(s32 index, s32 columns) { return index % columns; }
static inline s32 MenuGridQuotient(s16 index, s16 columns) { return index / columns; }

static inline s16 MenuGridColumnWidth(const void *self, s32 columns) {
    s16 width = *(s16 *)((u8 *)self + 0x16) - *(s16 *)((u8 *)self + 0x12);
    return width / columns;
}



typedef struct {
    u8 unk0;
} Unk1;


typedef struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    void *val;
} ListNode;

typedef struct ListIter {
    ListNode *node;
} ListIter;

typedef struct List {
    s32 size;
} List;

typedef struct Anim Anim;
typedef void (*AnimFn)(Anim *);

struct Anim {
    u8 pad0[8];
    AnimFn *funcs;      /* +0x08 */
    u8 flags;           /* +0x0C */
    u8 unk_d;           /* +0x0D */
    u8 unk_e;           /* +0x0E */
    u8 pad_f;           /* +0x0F */
    u8 unk_10;          /* +0x10 */
    u8 delay;           /* +0x11 */
    s16 unk_12;         /* +0x12 */
    u8 pad14[2];
    u8 cur;             /* +0x16 */
    u8 prev;            /* +0x17 */
    AnimFn *draw;       /* +0x18 */
    u8 pad1C[0xC];
    u8 start;           /* +0x28 */
    u8 end;             /* +0x29 */
    u8 pad2A[2];
    u16 frame;          /* +0x2C */
    u16 frames;         /* +0x2E */
};

void *fn_80132800(void) {
    extern u16 lbl_80276008[];
    return &lbl_80276008[0x50 / 2];
}

void *fn_80132810(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0x59;
}

s32 fn_80132820(s32 arg0, s32 arg1) {
    void Ui_CreateMenu(void *, s32, s32);
    extern u8 lbl_80367AC4;
    Ui_CreateMenu(&lbl_80367AC4, arg1, 0);
    return 4;
}

void *fn_8013284C(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0x92;
}

void *fn_8013285C(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0x97;
}

s32 fn_8013286C(void) {
    return 2;
}

s32 fn_80132874(void) {
    return 0x10;
}

void *fn_8013287C(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0xb4;
}

void *fn_8013288C(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0xC2;
}

s32 fn_8013289C(void) {
    return 0;
}

s32 fn_801328A4(void) {
    extern u16 lbl_80276008[];
    void fn_801C1C64(s32, s32, void *, s32, s32, s32, s32);

    fn_801C1C64(0x17C, 0x50, (u8 *)lbl_80276008 + 0xE5, 0xFA, 0x7D0, 0xFA, 3);
    return 5;
}

void *fn_801328EC(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0xee;
}

void *fn_801328FC(void) {
    extern u16 lbl_80276008[];
    return &lbl_80276008[0x7E];
}

s32 fn_8013290C(void) {
    return 0;
}

s32 fn_80132914(void) {
    extern u16 lbl_80276008[];
    fn_8006F09C((u8 *)lbl_80276008 + 0x117, (u8 *)lbl_80276008 + 0x120, (u8 *)lbl_80276008 + 0x129);
    return 5;
}

void *fn_8013294C(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0x132;
}

void *fn_8013295C(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0x140;
}

s32 fn_8013296C(void) {
    return 0;
}

s32 fn_80132974(void) {
    extern u16 lbl_80276008[];
    fn_8006F10C((u8 *)lbl_80276008 + 0x117, (u8 *)lbl_80276008 + 0x120);
    return 5;
}

void *fn_801329A8(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0x15b;
}

void *fn_801329B8(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0x16b;
}

s32 fn_801329C8(void) {
    return 0;
}

s32 fn_801329D0(void) {
    extern u16 lbl_80276008[];
    void fn_8006F6A4(s32, void *, s32, s32);
    s32 fn_800C0658(void);

    fn_8006F6A4(fn_800C0658(), (u8 *)lbl_80276008 + 0x186, 0, 0);
    return 5;
}

void *fn_80132A0C(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0x1b2;
}

void *fn_80132A1C(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0x1bb;
}

s32 fn_80132A2C(void) {
    return 2;
}

s32 fn_80132A34(void) {
    return 0x10;
}

void *fn_80132A3C(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0x1e2;
}

void *fn_80132A4C(void) {
    extern u16 lbl_80276008[];
    return (u8 *)lbl_80276008 + 0x1fa;
}

s32 fn_80132A5C(void) {
    return 0;
}

s32 fn_80132A64(void) {
    extern u16 gSystemSave[36]; // 72 bytes = 36 * 2-byte entries
    
    s32 i;
    
    i = 0;
    gSystemSave[0x8] |= 1;
    gSystemSave[0x8] |= 2;
    gSystemSave[0x8] |= 4;
    gSystemSave[0x8] |= 8;
    gSystemSave[0x8] |= 0x10;
    gSystemSave[0x8] |= 0x20;
    
    do {
        fn_801E35BC(gSystemSave, i);
        i += 1;
    } while (i < 0x80);
    
    return 6;
}

void *fn_80132B00(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    M2C_UNK fn_8016A6A4(void *);
    extern u8 lbl_80276270[];
    void *temp_r3;

    temp_r3 = Process_CreateChild(lbl_80276270, arg0);
    if (temp_r3 != NULL) {
        fn_8016A6A4(temp_r3);
    }
    M2C_FIELD(temp_r3, s32 *, 0x44) = arg1;
    return temp_r3;
}

void fn_80132B58(void *arg0) {
    M2C_UNK fn_8003F670(s32);
    M2C_UNK fn_80161F7C();
    M2C_UNK fn_8016A650(void *, M2C_UNK);
    fn_80161F7C();
    fn_8003F670(M2C_FIELD(arg0, s32 *, 0x48));
    if (arg0 != NULL) {
        fn_8016A650(arg0, 0);
    }
}

void fn_80132BA0(void *arg0) {
    s32 Archive_Load();
    M2C_UNK fn_80162018();
    M2C_UNK fn_801620AC();
    fn_80162018();
    fn_801620AC();
    M2C_FIELD(arg0, s32 *, 0x48) = Archive_Load();
}

void fn_80132BD8(s32 arg0) {
    M2C_UNK Process_ClearFunc(s32);
    s32 fn_80161FB8();
    if (fn_80161FB8() != 0) {
        Process_ClearFunc(arg0);
    }
}

void fn_80132C14(s32 arg0) {
    void *fn_8014D8FC(void *);
    M2C_UNK fn_80162054(void);
    M2C_UNK fn_8016A5DC(s32, s32, f32);
    extern u8 gBattleState[];
    fn_80162054();
    fn_8016A5DC(arg0, M2C_FIELD(fn_8014D8FC(gBattleState), s32 *, 0x44), 90.0f);
}

#pragma global_optimizer off
void fn_80132C5C(void *arg0) {
    void fn_8016E9DC(void *);
    void strcpy(void *, void *);
    void fn_801CE070(void *, void *, void *);
    extern u8 lbl_8032FE80[];
    extern u8 lbl_802762DC[];

    switch (*(s32 *)((u8 *)arg0 + 0x44)) {
    case 0:
        fn_8016E9DC(arg0);
        break;
    case 1:
        strcpy(lbl_8032FE80, lbl_802762DC + 0x2C);
        fn_801CE070(lbl_8032FE80, lbl_802762DC + 0x2C, arg0);
        break;
    }
}
#pragma global_optimizer on
void fn_80132CDC(void) {
    M2C_UNK Process_ClearFunc();
    Process_ClearFunc();
}

#pragma push
#pragma cplusplus on
#pragma optimization_level 4
#pragma opt_common_subs off
extern "C" void fn_80132CFC(void *arg0) {
    void fn_801475FC(void *, s32);
    extern u8 lbl_802764BC[];
    extern s32 lbl_80367110;
    extern void *lbl_80367240;
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
    };
    s32 state;
    u8 blocked;
    s32 flags;
    s16 dir;
    s32 pad;
    u8 *p;
    u8 lt;
    u8 v;
    u8 lim;
    u8 other;
    u8 canDec;

    state = *(s32 *)((u8 *)arg0 + 0x4C);
    if (state == 0) {
        ((Obj *)arg0)->v6();
        return;
    }
    if (state != 1) {
        return;
    }
    flags = lbl_80367110;
    blocked = 0;
    if ((flags & 0x10) != 0 && (flags & 0x20) == 0) {
        blocked = 1;
    }
    if (blocked != 0) {
        return;
    }
    dir = *(s16 *)((u8 *)arg0 + 0x3E);
    p = (u8 *)0;
    pad = *(s32 *)((u8 *)lbl_80367240 + 0xC);
    switch (dir) {
    case 0:
        p = (u8 *)arg0 + 0x51;
        lim = p[8];
        v = p[0];
        canDec = 0;
        other = p[4];
        if ((s8)lim < (s8)v && (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x60) + 0x19) + (s8)v) > 1) {
            canDec = 1;
        }
        lt = (s8)v < (s8)other;
        break;
    case 1:
        p = (u8 *)arg0 + 0x52;
        lim = p[8];
        v = p[0];
        canDec = 0;
        other = p[4];
        if ((s8)lim < (s8)v && (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x60) + 0x1A) + (s8)(v * 5)) > 1) {
            canDec = 1;
        }
        lt = (s8)v < (s8)other;
        break;
    case 2:
        p = (u8 *)arg0 + 0x53;
        lim = p[8];
        v = p[0];
        canDec = 0;
        other = p[4];
        if ((s8)lim < (s8)v && (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x60) + 0x1C) + (s8)(v * 3)) > 0) {
            canDec = 1;
        }
        lt = (s8)v < (s8)other;
        break;
    case 3:
        p = (u8 *)arg0 + 0x54;
        lim = p[4];
        v = p[0];
        canDec = 0;
        other = p[8];
        if ((s8)v < (s8)lim && (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x60) + 0x1B) - (s8)v) > 1) {
            canDec = 1;
        }
        lt = (s8)other < (s8)v;
        break;
    }
    if (lt) {
        if (pad & 0x08000008) {
            if (dir != 3) {
                *p = *p + 1;
            } else {
                *p = *p - 1;
            }
            fn_801475FC(lbl_802764BC + 0x1C3, 0x64);
            return;
        }
    }
    if (canDec) {
        if (pad & 0x04000004) {
            if (dir != 3) {
                *p = *p - 1;
            } else {
                *p = *p + 1;
            }
            fn_801475FC(lbl_802764BC + 0x1C3, 0x64);
        }
    }
}
#pragma cplusplus on
#pragma global_optimizer on
extern "C" void fn_80132FD0(void *arg0) {
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
        virtual void v9() = 0;
        virtual s32 getCount() = 0;
    };
    void Ui_PlaySeCue(void *, s32);
    extern u8 lbl_802764BC[];
    extern s32 gUiInputFlags;
    extern void *gPadInput;
    s16 temp_r0;
    s16 temp_r31;
    s32 temp_r3_2;
    s32 temp_r4;
    s16 temp_r5;
    s16 temp_r6;
    s16 temp_r8;
    s16 temp_r8_2;
    s32 var_r12;
    s32 temp_r0_2;
    s32 temp_r10;
    s32 temp_r10_2;
    s32 temp_r3;
    u8 var_r3;
    void *var_r9;
    s16 var_r7;

    temp_r31 = M2C_FIELD(arg0, s16 *, 0x44);
    temp_r5 = ((Obj *)arg0)->getCount();
    temp_r8 = M2C_FIELD(arg0, s16 *, 0x3E);
    var_r3 = 0;
    var_r7 = (s16)(temp_r8 / temp_r31);
    temp_r6 = temp_r31 + temp_r5;
    temp_r6 = (s16)((temp_r6 - 1) / temp_r31);
    temp_r0 = M2C_FIELD(arg0, s16 *, 0x3E) % temp_r31;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        var_r3 = 1;
    }
    if (var_r3 == 0) {
        var_r9 = gPadInput;
        temp_r8_2 = M2C_FIELD(arg0, s16 *, 0x3E);
        temp_r10 = M2C_FIELD(var_r9, s32 *, 4);
        temp_r0_2 = M2C_FIELD(var_r9, s32 *, 0xC);
        temp_r3 = temp_r10 & (M2C_FIELD(var_r9, s32 *, 8) ^ temp_r10);
        if (temp_r8 == 4) {
            if (temp_r3 & 0x08000008) {
                M2C_FIELD(arg0, s16 *, 0x3E) = (s16)(temp_r8_2 - 1);
            } else if (temp_r3 & 0x01000001) {
                M2C_FIELD(arg0, s16 *, 0x3E) = 2;
            }
        } else {
            if (temp_r31 > 1) {
                var_r12 = temp_r5 - (var_r7 * temp_r31);
                if (var_r12 > temp_r31) {
                    var_r12 = temp_r31;
                }
                if (temp_r0_2 & 0x01000001) {
                    if (temp_r0 > 0) {
                        M2C_FIELD(arg0, s16 *, 0x3E) = (s16)(M2C_FIELD(arg0, s16 *, 0x3E) - 1);
                    } else if (temp_r0_2 == temp_r3) {
                        M2C_FIELD(arg0, s16 *, 0x3E) = (s16)((var_r12 + M2C_FIELD(arg0, s16 *, 0x3E)) - 1);
                    }
                } else if (temp_r0_2 & 0x02000002) {
                    temp_r10_2 = var_r12 - 1;
                    if (temp_r0 < temp_r10_2) {
                        M2C_FIELD(arg0, s16 *, 0x3E) = (s16)(M2C_FIELD(arg0, s16 *, 0x3E) + 1);
                    } else if (temp_r0_2 == temp_r3) {
                        M2C_FIELD(arg0, s16 *, 0x3E) = (s16)(M2C_FIELD(arg0, s16 *, 0x3E) - temp_r10_2);
                    }
                }
            }
            if (temp_r0_2 & 0x08000008) {
                if (var_r7 == 0) {
                    if (temp_r0_2 == temp_r3) {
                        temp_r4 = temp_r5 - 1;
                        M2C_FIELD(arg0, s16 *, 0x3E) = (s16)(M2C_FIELD(arg0, s16 *, 0x3E) + ((temp_r6 - 1) * temp_r31));
                        if ((s16)M2C_FIELD(arg0, s16 *, 0x3E) > temp_r4) {
                            M2C_FIELD(arg0, s16 *, 0x3E) = temp_r4;
                        }
                    }
                } else {
                    M2C_FIELD(arg0, s16 *, 0x3E) = (s16)(M2C_FIELD(arg0, s16 *, 0x3E) - temp_r31);
                }
            } else if (temp_r0_2 & 0x04000004) {
                if (var_r7 == (s32)(temp_r6 - 1)) {
                    M2C_FIELD(arg0, s16 *, 0x3E) = 4;
                } else {
                    temp_r3_2 = temp_r5 - 1;
                    M2C_FIELD(arg0, s16 *, 0x3E) = (s16)(M2C_FIELD(arg0, s16 *, 0x3E) + temp_r31);
                    if ((s16)M2C_FIELD(arg0, s16 *, 0x3E) > temp_r3_2) {
                        M2C_FIELD(arg0, s16 *, 0x3E) = temp_r3_2;
                    }
                }
            }
        }
        if (temp_r8_2 != (s16)M2C_FIELD(arg0, s16 *, 0x3E)) {
            Ui_PlaySeCue(lbl_802764BC + 0x1DF, 0x64);
        }
    }
}
extern "C" void fn_80133230(void *self, void *other) {
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    s32 Text_MeasureHeight(s32, f32);
    void Ui_DrawRouteIconEx(s16, s32, u8);
    void fn_801552D4(s16, s32, s32, s32);
    f64 fn_802380D0(f64);
    u32 OSGetTick(void);
    extern f32 lbl_8036A5A8;
    extern const f32 lbl_8036A5AC;
    extern f64 lbl_8036A5C0;
    extern f32 lbl_8036A5B0;
    extern f32 lbl_8036A5B4;
    extern f32 lbl_8036A5B8;
    extern f32 lbl_8036A5BC;
    extern f64 lbl_8036A5C8;
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void draw(s32) = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11(s16, s16, s32, s16, u8) = 0;
    };
    u8 r29;
    u8 r26;
    u8 r25;
    s16 r28;
    s16 r27;
    s16 t46;
    s16 divv;
    f32 f31;

    ((Obj *)self)->draw((s32)other);
    {
        s16 t3e = *(s16 *)((u8 *)self + 0x3E);
        s16 t44 = *(s16 *)((u8 *)self + 0x44);
        s16 w = (s16)(*(s16 *)((u8 *)self + 0x16) - *(s16 *)((u8 *)self + 0x12));
        s16 q = (s16)(t3e / t44);
        s16 t48 = *(s16 *)((u8 *)self + 0x48);
        s16 t4a;
        t46 = *(s16 *)((u8 *)self + 0x46);
        t4a = *(s16 *)((u8 *)self + 0x4A);
        divv = (s16)(w / t44);
        r28 = (s16)(divv * (s16)(t3e % t44) + t48);
        r27 = (s16)(t46 * (s16)q + t4a);
        if (t3e == 4) {
            r28 = (s16)(w - 0x50);
            r27 = (s16)((s16)(*(s16 *)((u8 *)self + 0x18) - *(s16 *)((u8 *)self + 0x14)) - 0x10);
        }
    }
    {
        s16 t40 = *(s16 *)((u8 *)self + 0x40);
        if ((s16)t40 < 0 || *(s16 *)((u8 *)self + 0x42) < 0) {
            *(s16 *)((u8 *)self + 0x40) = r28;
            *(s16 *)((u8 *)self + 0x42) = r27;
        } else {
            *(s16 *)((u8 *)self + 0x40) = (s16)((s32)(t40 + r28 + 1) >> 1);
            *(s16 *)((u8 *)self + 0x42) = (s16)((s32)(*(s16 *)((u8 *)self + 0x42) + r27 + 1) >> 1);
        }
    }
    if (*(u8 *)((u8 *)self + 0x3C) != 0) {
        u8 flag;
        void *ptr;
        s32 mode;
        r29 = 0;
        flag = r29;
        if (*(u8 *)((u8 *)other + 0x2D) == 0) {
            if (*(u8 *)((u8 *)other + 0x2E) == 0) {
                flag = 1;
            }
        }
        if (flag) {
            if (*(u32 *)((u8 *)other + 0x34) != 0) {
                ptr = (*(void ***)((u8 *)other + 0x38))[2];
            } else {
                ptr = 0;
            }
            if (ptr == self) {
                r29 = 1;
            }
        }
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A5A8);
        Prim2D_PrepareTex();
        mode = *(s32 *)((u8 *)self + 0x4C);
        if (mode == 0) {
            s32 t = (u16)*(s16 *)((u8 *)self + 0x46);
            Ui_DrawRouteIconEx(*(s16 *)((u8 *)self + 0x40),
                *(s16 *)((u8 *)self + 0x42) + (s16)(((s16)t - Text_MeasureHeight(-1, lbl_8036A5AC)) >> 1),
                r29);
        } else if (mode == 1) {
            u32 tick = OSGetTick();
            u32 bus = *(u32 *)0x800000F8 >> 2;
            u32 tpm = ((u32)(((u64)0x10624DD3 * bus) >> 32)) >> 6;
            u32 ms = tick / tpm;
            ms = ms % 1000;
            {
                f32 f1 = (f32)ms / lbl_8036A5B0;
                if (r29) {
                    f64 sv = fn_802380D0((f64)(lbl_8036A5B4 * f1));
                    f31 = (f32)__fabs((f64)(lbl_8036A5B8 * (f32)sv));
                } else {
                    f31 = lbl_8036A5BC;
                }
            }
            {
                s32 t = (u16)*(s16 *)((u8 *)self + 0x46);
                s16 kind = *(s16 *)((u8 *)self + 0x3E);
                s16 half = (s16)(((s16)t - Text_MeasureHeight(-1, lbl_8036A5AC)) >> 1);
                s16 x; s32 y;
                u8 b, c, d, allowed;
                u8 *unit;
                switch (kind) {
                case 0:
                    b = ((u8 *)self)[0x51];
                    allowed = 0;
                    c = ((u8 *)self)[0x59];
                    d = ((u8 *)self)[0x55];
                    if ((s8)c < (s8)b) {
                        unit = *(u8 **)((u8 *)self + 0x60);
                        if ((s32)(unit[0x19] + (s8)b) > 1) {
                            allowed = 1;
                        }
                    }
                    r25 = allowed;
                    r26 = (s8)b < (s8)d;
                    break;
                case 1:
                    b = ((u8 *)self)[0x52];
                    allowed = 0;
                    c = ((u8 *)self)[0x5A];
                    d = ((u8 *)self)[0x56];
                    if ((s8)c < (s8)b) {
                        unit = *(u8 **)((u8 *)self + 0x60);
                        if ((s32)(unit[0x1A] + (s8)(b * 5)) > 1) {
                            allowed = 1;
                        }
                    }
                    r25 = allowed;
                    r26 = (s8)b < (s8)d;
                    break;
                case 2:
                    b = ((u8 *)self)[0x53];
                    allowed = 0;
                    c = ((u8 *)self)[0x5B];
                    d = ((u8 *)self)[0x57];
                    if ((s8)c < (s8)b) {
                        unit = *(u8 **)((u8 *)self + 0x60);
                        if ((unit[0x1C] + (s8)(b * 3)) > 0) {
                            allowed = 1;
                        }
                    }
                    r25 = allowed;
                    r26 = (s8)b < (s8)d;
                    break;
                case 3:
                    b = ((u8 *)self)[0x54];
                    allowed = 0;
                    c = ((u8 *)self)[0x58];
                    d = ((u8 *)self)[0x5C];
                    if ((s8)b < (s8)c) {
                        unit = *(u8 **)((u8 *)self + 0x60);
                        if ((s32)(unit[0x1B] - (s8)b) > 1) {
                            allowed = 1;
                        }
                    }
                    r25 = allowed;
                    r26 = (s8)d < (s8)b;
                    break;
                }
                y = r27 + half;
                x = (s16)(r28 + ((divv - 0xF) - (*(s16 *)((u8 *)self + 0x48) << 1)));
                if (r26) {
                    fn_801552D4(x, (s32)((f32)(s16)(y - 0x17) - f31), 1, 0x10);
                }
                {
                    s16 t2 = (s16)(y + Text_MeasureHeight(-1, lbl_8036A5AC));
                    if (r25) {
                        fn_801552D4(x, (s32)((f32)t2 + f31), 0, 0x10);
                    }
                }
            }
        }
        if (*(s16 *)((u8 *)self + 0x3E) != 4) {
            Prim2D_Begin();
            Prim2D_AddZ(lbl_8036A5B8);
            Prim2D_PrepareTex();
            ((Obj *)self)->v11((s16)(r28 - *(s16 *)((u8 *)self + 0x48)), r27, divv, t46, r29);
        }
    }
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus on
#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
#pragma global_optimizer off
extern "C" void fn_80133760(void *arg0, s32 arg1) {
    void fn_80006B18(s32, s32, s32, s32, s32);
    void Prim2D_SetText(void *);
    void Prim2D_SetColorPacked(void *);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void *Msg_Expand(void *);
    s32 Text_MeasureHeight(s32, f32);
    s8 fn_8001BFB8(void *);
    s8 fn_8001BFFC(void *);
    s8 fn_8001C040(void *);
    s8 fn_8001C084(void *);
    u8 Item_GetWt(void *);
    u8 fn_8001D3FC(void *);
    u8 fn_8001D47C(void *);
    u8 fn_8001D500(void *);
    u32 *Ui_GetColor(s32);
    extern u8 lbl_802764BC[];
    extern const f32 lbl_8036A5AC;
    extern f64 lbl_8036A5C8;
    extern f32 lbl_8036A5D0;
    struct Obj {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void draw(s32) = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
        virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
        virtual void v12() = 0;
    };
    u32 sp24, sp20, sp1C, sp18, sp14, sp10, spC, sp8;
    register s32 t48;
    register s32 t46;
    register s32 divv;
    register s16 x0;
    s32 y0;
    s32 bar;
    s32 t4a;
    Obj *self;
    s32 arg;

    self = (Obj *)arg0;
    arg = arg1;
    self->v12();
    self->draw(arg);
    t46 = (s16)*(s16 *)((u8 *)self + 0x46);
    t48 = (s16)*(s16 *)((u8 *)self + 0x48);
    t4a = (s16)*(s16 *)((u8 *)self + 0x4A);
    divv = (s16)((s16)(*(s16 *)((u8 *)self + 0x16) - *(s16 *)((u8 *)self + 0x12)) / *(s16 *)((u8 *)self + 0x44));
    {
        s32 d = Text_MeasureHeight(-1, lbl_8036A5AC);
        x0 = (s16)(t4a + (((s32)(s16)t46 - d) >> 1));
        t4a = (s16)(*(s16 *)((u8 *)self + 0x48) << 1);
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A5D0);
    Prim2D_SetTex(0, (u16)(*(u32 *)((u8 *)self + 0x34) | 0x13));
    Prim2D_PrepareTex();
    Prim2D_AddPrim(6);
    Prim2D_SetPos((f32)(s16)t48, (f32)x0);
    Prim2D_SetColor(0xFF, 0x80, 0, 0xFF);
    Prim2D_SetText(Msg_Expand(lbl_802764BC + 0x1FB));
    Prim2D_EndPrim();
    Prim2D_AddPrim(6);
    bar = (u8)fn_8001D500((u8 *)self + 0x60) + (s8)((u8 *)self)[0x51];
    if (bar < 1) {
        bar = 1;
    }
    if ((s8)((u8 *)self)[0x51] != 0 || (s8)fn_8001C084((u8 *)self + 0x60) != 0) {
        sp24 = *Ui_GetColor(6);
        Prim2D_SetColorPacked(&sp24);
    } else {
        sp20 = *Ui_GetColor(1);
        Prim2D_SetColorPacked(&sp20);
    }
    y0 = ((s32)(s16)t48 + divv) - t4a;
    fn_80006B18(y0, x0, 0, 0, bar);
    Prim2D_EndPrim();
    bar = t48 + divv;
    Prim2D_AddPrim(6);
    Prim2D_SetPos((f32)(s16)bar, (f32)x0);
    Prim2D_SetColor(0xFF, 0x80, 0, 0xFF);
    Prim2D_SetText(Msg_Expand(lbl_802764BC + 0x202));
    Prim2D_EndPrim();
    Prim2D_AddPrim(6);
    arg = (u8)fn_8001D47C((u8 *)self + 0x60) + (s8)(((u8 *)self)[0x52] * 5);
    if (arg < 1) {
        arg = 1;
    }
    if ((s8)((u8 *)self)[0x52] != 0 || (s8)fn_8001C040((u8 *)self + 0x60) != 0) {
        sp1C = *Ui_GetColor(6);
        Prim2D_SetColorPacked(&sp1C);
    } else {
        sp18 = *Ui_GetColor(1);
        Prim2D_SetColorPacked(&sp18);
    }
    fn_80006B18(((s32)(s16)bar + divv) - t4a, x0, 0, 0, arg);
    Prim2D_EndPrim();
    bar = x0 + t46;
    Prim2D_AddPrim(6);
    Prim2D_SetPos((f32)(s16)t48, (f32)(s16)bar);
    Prim2D_SetColor(0xFF, 0x80, 0, 0xFF);
    Prim2D_SetText(Msg_Expand(lbl_802764BC + 0x209));
    Prim2D_EndPrim();
    Prim2D_AddPrim(6);
    arg = (u8)fn_8001D3FC((u8 *)self + 0x60) + (s8)(((u8 *)self)[0x53] * 3);
    if (arg < 0) {
        arg = 0;
    }
    if ((s8)((u8 *)self)[0x53] != 0 || (s8)fn_8001BFFC((u8 *)self + 0x60) != 0) {
        sp14 = *Ui_GetColor(6);
        Prim2D_SetColorPacked(&sp14);
    } else {
        sp10 = *Ui_GetColor(1);
        Prim2D_SetColorPacked(&sp10);
    }
    x0 = (s16)bar;
    fn_80006B18(y0, x0, 0, 0, arg);
    Prim2D_EndPrim();
    y0 = t48 + divv;
    Prim2D_AddPrim(6);
    Prim2D_SetPos((f32)(s16)y0, (f32)x0);
    Prim2D_SetColor(0xFF, 0x80, 0, 0xFF);
    Prim2D_SetText(Msg_Expand(lbl_802764BC + 0x211));
    Prim2D_EndPrim();
    Prim2D_AddPrim(6);
    arg = (u8)Item_GetWt((u8 *)self + 0x60) - (s8)((u8 *)self)[0x54];
    if (arg < 1) {
        arg = 1;
    }
    if ((s8)((u8 *)self)[0x54] != 0 || (s8)fn_8001BFB8((u8 *)self + 0x60) != 0) {
        spC = *Ui_GetColor(6);
        Prim2D_SetColorPacked(&spC);
    } else {
        sp8 = *Ui_GetColor(1);
        Prim2D_SetColorPacked(&sp8);
    }
    fn_80006B18(((s32)(s16)y0 + divv) - t4a, x0, 0, 0, arg);
    Prim2D_EndPrim();
}
#pragma use_lmw_stmw on
#pragma opt_lifetimes off
extern "C" void fn_80133C74(void *arg0)
{
    extern const f32 lbl_8036A5AC;
    extern const f32 lbl_8036A5D4;

    void fn_80159898(s32, s32, s32, s32, s32, s32);
    s32 Text_MeasureHeight(s32, f32);
    void Ui_DrawLine(s16, s16, s16, s16, s32, u8 *);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void fn_80152CAC(s16, s16, s32);

    struct Base {
        virtual void v0();
        virtual void v1();
        virtual void v2();
    };

    s16 columnWidth, rowHeight, width, height;
    s32 xOffset, yOffset;
    s16 row, column, x, y;
    u8 *self;
    s32 textHeight, halfHeight;
    s16 w, dy;
    u8 color[4];

    self = (u8 *)arg0;

    ((Base *)self)->v2();

    width = *(s16 *)(self + 0xE) - *(s16 *)(self + 0xA);
    height = *(s16 *)(self + 0x10) - *(s16 *)(self + 0xC);

    if (self[0x3D] != 0) {
        fn_80159898(0, 0, width, height, 0xB3, 0x10);
    }

    columnWidth = (s16)(*(s16 *)(self + 0x16) - *(s16 *)(self + 0x12)) / *(s16 *)(self + 0x44);
    rowHeight = *(s16 *)(self + 0x46);

    for (row = 0, yOffset = 0; row < (s16)(((s16)(*(s16 *)(self + 0x18) - *(s16 *)(self + 0x14)) - (*(s16 *)(self + 0x4A) << 1)) / *(s16 *)(self + 0x46)); row++, yOffset += rowHeight) {
        for (column = 0, xOffset = 0; column < *(s16 *)(self + 0x44); column++, xOffset += columnWidth) {
            s32 tx = *(s16 *)(self + 0x48) + *(s16 *)(self + 0x12);
            x = xOffset + tx;
            s32 ty = *(s16 *)(self + 0x4A) + *(s16 *)(self + 0x14);
            y = yOffset + ty;

            textHeight = Text_MeasureHeight(-1, lbl_8036A5AC);
            halfHeight = (rowHeight - textHeight) >> 1;
            textHeight = Text_MeasureHeight(-1, lbl_8036A5AC);

            dy = textHeight + halfHeight;
            w = columnWidth - (*(s16 *)(self + 0x48) << 1);

            color[0] = 0xFF;
            color[1] = 0xFF;
            color[2] = 0xFF;
            color[3] = 0x4C;

            Ui_DrawLine(x, y + dy, x + w, y + dy, 0x10, color);
        }
    }

    if (self[0x50] != 0) {
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A5D4);
        Prim2D_PrepareTex();

        fn_80152CAC((s16)(width - 0x5C), (s16)(height - 0x10), 0x10);
    }
}
#pragma opt_lifetimes reset
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus reset

void fn_80133E50(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5) {
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    fn_8008AB7C(arg1 + (arg3 >> 1), arg2 + (arg4 >> 1), arg3, 0x18, 0x19, 0x4C, arg5);
}

#pragma use_lmw_stmw on
#pragma scheduling on
#pragma opt_lifetimes off
void fn_80133EA4(s32 *arg0, void *arg1) {
    Vec2s *fn_8013F748(void *, Vec2s *, Vec2s *);
    s32 Text_MeasureHeight(s32, f32);
    Vec2s out;
    Vec2s in;
    u32 rowH;
    s32 kind;
    s32 colW;
    s32 quot;
    s32 rem;
    s32 hdiv;
    s32 t;
    s16 x;
    s16 y;
    s16 half;
    s16 off48;
    s16 off4a;
    colW = *(s16 *)((u8 *)arg1 + 0x44);
    kind = *(s16 *)((u8 *)arg1 + 0x3e);
    quot = MenuGridQuotient(kind, colW);
    t = *(s16 *)((u8 *)arg1 + 0x12);
    rem = *(s16 *)((u8 *)arg1 + 0x16);
    rem -= t;
    rowH = *(u16 *)((u8 *)arg1 + 0x46);
    off48 = *(s16 *)((u8 *)arg1 + 0x48);
    off4a = *(s16 *)((u8 *)arg1 + 0x4a);
    t = (s16)rem;
    hdiv = t / colW;
    t = (s16)hdiv;
    rem = kind - quot * colW;
    rem = (s16)rem;
    rem = t * rem;
    x = (s16)(rem + off48);
    y = (s16)(rowH * quot + off4a);
    t = Text_MeasureHeight(-1, lbl_8036A5AC);
    half = (s16)(((s32)(s16)rowH - t) >> 1);
    if (*(s16 *)((u8 *)arg1 + 0x3E) == 4) {
        x = (s16)(*(s16 *)((u8 *)arg1 + 0x16) - *(s16 *)((u8 *)arg1 + 0x12)) - 0x50;
        y = (s16)(*(s16 *)((u8 *)arg1 + 0x18) - *(s16 *)((u8 *)arg1 + 0x14)) - 0x10;
    }
    in.x = x;
    in.y = (s32)y + half;
    *arg0 = *(s32 *)fn_8013F748(arg1, &out, &in);
}
#pragma opt_lifetimes reset
#pragma scheduling reset
#pragma use_lmw_stmw reset
s32 fn_80133FA4(void *arg0) {
    extern s32 lbl_80291744[];
    return lbl_80291744[M2C_FIELD(arg0, s16 *, 0x3E)];
}

void Item_Copy(void *);
void Ui_ConfirmChild_BindItem(void *arg0, void *arg1) {
    s8 fn_8001BFB8(void *);
    s8 fn_8001BFFC(void *);
    s8 fn_8001C040(void *);
    s8 fn_8001C084(void *);
    void Item_Copy(void *);
 s32 positive=5; s32 negative=-5;
 u8 *self=(u8*)arg0;
 Item_Copy((u8 *)arg0+0x60);
 M2C_FIELD(self,s8 *,84)=0;
 M2C_FIELD(self,s8 *,83)=0;
 M2C_FIELD(self,s8 *,82)=0;
 M2C_FIELD(self,s8 *,81)=0;
 M2C_FIELD(self,s8 *,81)=fn_8001C084(arg1);
 M2C_FIELD(self,s8 *,82)=fn_8001C040(arg1);
 M2C_FIELD(self,s8 *,83)=fn_8001BFFC(arg1);
 M2C_FIELD(self,s8 *,84)=fn_8001BFB8(arg1);
 M2C_FIELD(self,s8 *,85)=positive;
 M2C_FIELD(self,s8 *,89)=negative;
 M2C_FIELD(self,s8 *,86)=positive;
 M2C_FIELD(self,s8 *,90)=negative;
 M2C_FIELD(self,s8 *,87)=3;
 M2C_FIELD(self,s8 *,91)=-3;
 M2C_FIELD(self,s8 *,88)=positive;
 M2C_FIELD(self,s8 *,92)=negative;
}

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
#pragma opt_strength_reduction off
extern "C" void fn_8013406C(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3(s32) = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual s32 v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        u8 pad4[0xE];
        s16 unk12;
        u8 pad14[2];
        s16 unk16;
        u8 pad18[0x1C];
        u32 unk34;
        u8 pad38[0xC];
        s16 unk44;
        s16 unk46;
        s16 unk48;
        s16 unk4A;
        u32 unk4C;
        u8 *unk50;
    };
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_SetAlphaByte(s32);
    s32 Text_MeasureHeight(s32, f32);
    void *Item_GetByIid(void *);
    void Ui_DrawIcon(void *, s16, s16, s32);
    s32 Msg_Expand(void *);
    void fn_8001003C(s16, s16, s32, s32, s32, s32, ...);
    extern const f32 lbl_8036A5AC;
    extern f32 lbl_8036A5D0;
    extern f32 lbl_8036A5BC;
    Obj *self;
    extern u8 gUiIconDrawer[];
    s32 startX;

    self = (Obj *)arg0;
    startX = arg1;
    self->v12();
    self->v3(startX);
    {
        s32 cols;
        s16 rows;
        s32 rowH;
        s16 startY0;
        s16 colW;
        s16 yOff;
        s32 x;
        s32 y;
        s32 row;
        s32 col;
        s32 idx;
        s32 curY;
        u8 *rowBase;
        u8 *cell;
        s32 vret;
        s16 rowHs;
        s16 colsExt;
        s16 x16;
        s16 curY16;
        void *p;
        s32 str;
        s32 sum;

        cols = self->unk44;
        vret = self->v10();
        sum = cols + (s16)vret;
        sum = sum - 1;
        rows = (s16)(sum / cols);
        colW = (s16)((s16)(self->unk16 - self->unk12) / self->unk44);
        startX = self->unk48;
        rowH = self->unk46;
        startY0 = self->unk4A;
        rowHs = (s16)rowH;
        startY0 = (s16)(startY0 + ((rowHs - Text_MeasureHeight(-1, lbl_8036A5AC)) >> 1));
        yOff = (s16)((0x18 - Text_MeasureHeight(-1, lbl_8036A5AC)) >> 1);
        curY = startY0;
        self->v10();
        idx = 0;
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A5D0);
        Prim2D_PrepareTex();
        row = 0;
        y = startY0 + yOff;
        rowBase = self->unk50 + self->unk4C * 0x48;
        colsExt = cols;
        while ((s16)row < rows) {
            x = startX;
            cell = rowBase;
            curY16 = (s16)curY;
            col = 0;
            while ((s16)col < colsExt) {
                if ((s16)idx >= 9) {
                    goto done;
                }
                if (*(u32 *)cell != 0) {
                    p = Item_GetByIid(*(void **)cell);
                    x16 = (s16)x;
                    Ui_DrawIcon(gUiIconDrawer, x16, curY16, ((u8 *)p)[0x15] + 0x61);
                    Prim2D_Begin();
                    Prim2D_SetTex(0, (u16)(self->unk34 | 0x13));
                    Prim2D_PrepareTex();
                    str = Msg_Expand(*(void **)(cell + 4));
                    fn_8001003C((s16)(x16 + 0x18), (s16)y, 0xE, 1, 0, str, lbl_8036A5AC, lbl_8036A5BC);
                    x = x + colW;
                    col = col + 1;
                }
                cell = cell + 8;
                rowBase = rowBase + 8;
                idx = idx + 1;
            }
            y = y + rowHs;
            curY = curY + rowH;
            row = row + 1;
        }
    }
done:
    Prim2D_Begin();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}
#pragma pop
#pragma push
#pragma global_optimizer on
#pragma scheduling on
extern "C" void fn_80134280(void *arg0) {
s32 Item_GetByIid(u32);
s32 off = *(s32 *)((u8*)arg0+0x4C)*0x48;
s16 count=0;
s16 lim=*(s16*)((u8*)arg0+0x3E);
u32 *p=(u32*)(*(u8**)((u8*)arg0+0x50)+off);
for(s32 i=0;i<9;i++,p+=2) {
if(*p && count++==(s16)lim) break;
}
Item_GetByIid(*p);
}
#pragma pop
#pragma cplusplus reset
#pragma use_lmw_stmw reset

s16 Ui_CountPageItems(void *panel) {
    /* Count nonempty item cells (9 slots) on the list panel's current page. */
    s16 count;
    u8 *page;

    count = 0;
    page = *(u8 **)((u8 *)panel + 0x50) + *(u32 *)((u8 *)panel + 0x4c) * 0x48;
    if (*(u32 *)(page + 0) != 0) {
        count = 1;
    }
    if (*(u32 *)(page + 8) != 0) {
        count += 1;
    }
    if (*(u32 *)(page + 0x10) != 0) {
        count += 1;
    }
    if (*(u32 *)(page + 0x18) != 0) {
        count += 1;
    }
    if (*(u32 *)(page + 0x20) != 0) {
        count += 1;
    }
    if (*(u32 *)(page + 0x28) != 0) {
        count += 1;
    }
    if (*(u32 *)(page + 0x30) != 0) {
        count += 1;
    }
    if (*(u32 *)(page + 0x38) != 0) {
        count += 1;
    }
    if (*(u32 *)(page + 0x40) != 0) {
        count += 1;
    }
    return count;
}

void *fn_801343F8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    extern u8 lbl_80276354[360];
    extern u8 lbl_802764BC[];
    extern u8 lbl_80291794[];
    extern u8 gBattleState[];
    void *Res_GetByName(void *);
    void fn_80134E48(void *, s32, s32, s32, s32, s32);
    void sprintf(void *, void *, u8, ...);

    fn_80134E48(arg0, arg2, arg3, arg4, arg5, arg6);
    *(void **)arg0 = lbl_80291794;
    *(s32 *)((char *)arg0 + 0x4c) = arg1;
    sprintf(lbl_802764BC + 0x218, lbl_802764BC + 0x228, *(u8 *)((char *)gBattleState + 0x10));
    *(void **)((char *)arg0 + 0x50) = Res_GetByName(lbl_802764BC + 0x218);
    if (*(void **)((char *)arg0 + 0x50) == NULL) {
        *(void **)((char *)arg0 + 0x50) = lbl_80276354;
    }
    return arg0;
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void fn_801344AC(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3(s32) = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        u8 pad4[0xE];
        s16 unk12;
        u8 pad14[2];
        s16 unk16;
        u8 pad18[0x1C];
        u32 unk34;
        u8 pad38[0xC];
        s16 unk44;
        s16 unk46;
        s16 unk48;
        s16 unk4A;
    };
    typedef struct {
        s16 x;
        s16 y;
        s16 unk4;
        u16 pad6;
        void *str;
    } Cell;
    typedef struct {
        Cell c[5];
    } Cells;
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    s32 Text_MeasureHeight(s32, f32);
    void *Msg_Expand(void *);
    void Ui_DrawIcon(void *, s16, s16, s16);
    void Prim2D_SetTex(s32, u16);
    void fn_8001003C(s16, s16, s32, s32, s32, void *, ...);
    void Prim2D_SetAlphaByte(s32);
    extern const f32 lbl_8036A5AC;
    extern f32 lbl_8036A5D0;
    extern f32 lbl_8036A5BC;
    extern Cells lbl_80276318;
    extern u8 lbl_802764BC[];
    extern u8 gUiIconDrawer[];
    Cells cells;
    s16 temp_r31;
    s16 temp_r30;
    s16 temp_r29;
    s16 temp_r28;
    s16 temp_r27;
    register Obj *self;
    s32 x1;
    Cell *p;
    s32 i;
    s16 cx;
    s16 cy;

    self = (Obj *)arg0;
    self->v12();
    self->v3(arg1);
    temp_r31 = self->unk46;
    temp_r29 = (s16)((s16)(self->unk16 - self->unk12) / self->unk44);
    temp_r30 = self->unk48;
    temp_r28 = (s16)(self->unk4A + ((temp_r31 - 0x18) >> 1));
    temp_r27 = (s16)((0x18 - Text_MeasureHeight(-1, lbl_8036A5AC)) >> 1);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A5D0);
    Prim2D_PrepareTex();
    cells = lbl_80276318;
    cells.c[0].x = temp_r30;
    cells.c[0].y = temp_r28;
    cells.c[0].str = Msg_Expand(lbl_802764BC + 0x23A);
    x1 = cells.c[0].x + temp_r29;
    cells.c[1].x = x1;
    cells.c[1].y = temp_r28;
    cells.c[1].str = Msg_Expand(lbl_802764BC + 0x241);
    cells.c[2].x = temp_r30;
    cells.c[2].y = temp_r28 + temp_r31;
    cells.c[2].str = Msg_Expand(lbl_802764BC + 0x248);
    cells.c[3].y = temp_r28 + temp_r31;
    cells.c[3].x = x1;
    cells.c[3].str = Msg_Expand(lbl_802764BC + 0x24F);
    cells.c[4].x = temp_r30;
    cells.c[4].y = temp_r28 + temp_r31 + temp_r31;
    cells.c[4].str = Msg_Expand(lbl_802764BC + 0x256);
    p = cells.c;
    for (i = 0; i < 5; i++) {
        cx = p->x;
        cy = p->y;
        Ui_DrawIcon(gUiIconDrawer, cx, cy, p->unk4);
        Prim2D_Begin();
        Prim2D_SetTex(0, (u16)(self->unk34 | 0x13));
        fn_8001003C((s16)(cx + 0x18), (s16)(cy + temp_r27), 1, 1, 0, p->str, lbl_8036A5AC, lbl_8036A5BC);
        Prim2D_PrepareTex();
        p++;
    }
    Prim2D_Begin();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}
#pragma cplusplus reset
#pragma use_lmw_stmw reset

s32 fn_80134718(void *arg0) {
    extern s32 lbl_80291730[];
    return lbl_80291730[M2C_FIELD(arg0, s16 *, 0x3E)];
}

#pragma cplusplus on
extern "C" void fn_80134730(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
    };
    ((Obj *)arg0)->v6();
}

#pragma global_optimizer off
extern "C" void fn_8013475C(void *arg0) {
    void Ui_PlaySeCue(void *, s32);
    extern u8 lbl_802764BC[];
    extern s32 gUiInputFlags;
    extern void *gPadInput;
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
        virtual void v9() = 0;
        virtual s16 v10() = 0;
        u8 pad4[0x3A];
        s16 unk3E;
        u8 pad40[4];
        s16 unk44;
    };
    s16 cols;
    s16 count;
    s16 cursor;
    s16 row;
    s16 rows;
    s16 rem;
    s32 cols32;
    s32 count32;
    s32 width;
    s32 held;
    s32 trig;
    s32 repeat;
    s32 edge;
    s32 lastRow;
    s32 tmp;
    s32 cols_cmp;
    u8 skip;
    s16 prev;

    cols = ((Obj *)arg0)->unk44;
    count = ((Obj *)arg0)->v10();
    skip = 0;
    cursor = ((Obj *)arg0)->unk3E;
    cols32 = cols;
    count32 = count;
    row = (s16)(cursor / cols32);
    rows = (s16)((cols32 + count32 + -1) / cols32);
    rem = (s16)(cursor - row * cols32);
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        skip = 1;
    }
    if (skip == 0) {
        prev = ((Obj *)arg0)->unk3E;
        held = *(s32 *)((u8 *)gPadInput + 4);
        repeat = *(s32 *)((u8 *)gPadInput + 0xC);
        trig = held & (*(s32 *)((u8 *)gPadInput + 8) ^ held);
        cols_cmp = cols;
        if (cols_cmp > 1) {
            width = count32 - (row * cols32);
            if (width > cols32) {
                width = cols_cmp;
            }
            if (repeat & 0x01000001) {
                if (rem > 0) {
                    ((Obj *)arg0)->unk3E = (s16)(((Obj *)arg0)->unk3E - 1);
                } else if (repeat == trig) {
                    tmp = width + ((Obj *)arg0)->unk3E;
                    ((Obj *)arg0)->unk3E = (s16)(tmp - 1);
                }
            } else if (repeat & 0x02000002) {
                edge = width - 1;
                if (rem < edge) {
                    ((Obj *)arg0)->unk3E = (s16)(((Obj *)arg0)->unk3E + 1);
                } else if (repeat == trig) {
                    ((Obj *)arg0)->unk3E = (s16)(((Obj *)arg0)->unk3E - edge);
                }
            }
        }
        if (repeat & 0x08000008) {
            if (row == 0) {
                if (repeat == trig) {
                    tmp = count32 - 1;
                    ((Obj *)arg0)->unk3E = (s16)(((Obj *)arg0)->unk3E + ((rows - 1) * cols32));
                    if (((Obj *)arg0)->unk3E > tmp) {
                        ((Obj *)arg0)->unk3E = (s16)tmp;
                    }
                }
            } else {
                ((Obj *)arg0)->unk3E = (s16)(((Obj *)arg0)->unk3E - cols);
            }
        } else if (repeat & 0x04000004) {
            lastRow = rows - 1;
            if (row == lastRow) {
                if (repeat == trig) {
                    ((Obj *)arg0)->unk3E = (s16)(((Obj *)arg0)->unk3E - (lastRow * cols32));
                }
            } else {
                tmp = count32 - 1;
                ((Obj *)arg0)->unk3E = (s16)(((Obj *)arg0)->unk3E + cols);
                if (((Obj *)arg0)->unk3E > tmp) {
                    ((Obj *)arg0)->unk3E = (s16)tmp;
                }
            }
        }
        if (prev != ((Obj *)arg0)->unk3E) {
            Ui_PlaySeCue(lbl_802764BC + 0x1DF, 0x64);
        }
    }
}

#pragma global_optimizer reset
#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma global_optimizer off
extern "C" volatile unsigned char fn_80134988(void *arg0, void *arg1)
{
  void Prim2D_Begin();
  u8 *new_var;
  void Prim2D_AddZ(f32);
  void Prim2D_PrepareTex();
  void Prim2D_SetAlphaByte(u8);
  s32 Text_MeasureHeight(s32, f32);
  void Ui_DrawRouteIconEx(s16, s32, u8);
  s16 w;
  s16 h;
  s32 x;
  s32 y;
  u8 active;
  s32 n;
  s32 d;
  s32 q;
  s16 r;
  s16 row;
  u8 *ctx = (u8 *) arg1;
  u8 *self = (u8 *) arg0;
  ((Menu349 *) ((u8 *) arg0))->prepare();
  d = *((s16 *) (self + 0x44));
  n = *((s16 *) (self + 0x3e));
  q = (row = n / d);
  w = ((s16) ((*((s16 *) (self + 0x16))) - (*((s16 *) (self + 0x12))))) / d;
  h = *((s16 *) (self + 0x46));
  r = n - (q * d);
  x = (s16) ((w * r) + (*((s16 *) (self + 0x48))));
  y = (s16) ((h * row) + (*((s16 *) (self + 0x4a))));
  s32 oldX = *((s16 *) (((u8 *) arg0) + 0x40));
  new_var = ctx;
  if ((((s16) oldX) < 0) || ((*((s16 *) (((u8 *) arg0) + 0x42))) < 0))
  {
    *((s16 *) (((u8 *) arg0) + 0x40)) = x;
    *((s16 *) (((u8 *) arg0) + 0x42)) = y;
  }
  else
  {
    u32 nx = x + 1;
    u32 ny = y + 1;
    *((s16 *) (((u8 *) arg0) + 0x40)) = ((s32) (oldX + nx)) >> 1;
    *((s16 *) (((u8 *) arg0) + 0x42)) = ((s32) ((*((s16 *) (((u8 *) arg0) + 0x42))) + ny)) >> 1;
  }
  if (((u8 *) arg0)[0x3c])
  {
    active = 0;
    u8 idle = active;
    if ((ctx[0x2d] == 0) && (ctx[0x2e] == 0))
    {
      idle = 1;
    }
    if (idle)
    {
      void *cur = (*((u32 *) (ctx + 0x34))) ? ((*((ListNode **) (new_var + 0x38)))->val) : (0);
      if (cur == ((u8 *) arg0))
      {
        active = 1;
      }
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A5A8);
    Prim2D_PrepareTex();
    s16 t = *((s16 *) (((u8 *) arg0) + 0x46));
    Ui_DrawRouteIconEx(*((s16 *) (((u8 *) arg0) + 0x40)), (*((s16 *) (((u8 *) arg0) + 0x42))) + ((s16) ((t - Text_MeasureHeight(-1, lbl_8036A5AC)) >> 1)), active);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A5B8);
    Prim2D_PrepareTex();
    ((Menu349 *) ((u8 *) arg0))->draw((s16) (x - (*((s16 *) (((u8 *) arg0) + 0x48)))), y, w, h, active);
    Prim2D_Begin();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
  }
}
#pragma optimization_level reset
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma cplusplus reset
extern "C" void fn_80134B58(void *arg0) {
    void fn_801569C4(s32, s32, s16, s16, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    if (*(u8 *)((u8 *)arg0 + 0x3D) != 0) {
        fn_801569C4(0, 0,
            (s16)(*(s16 *)((u8 *)arg0 + 0xE) - *(s16 *)((u8 *)arg0 + 0xA)),
            (s16)(*(s16 *)((u8 *)arg0 + 0x10) - *(s16 *)((u8 *)arg0 + 0xC)),
            0xE6, 0x10);
    }
}
#pragma cplusplus reset
void fn_80134BD0(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5) {
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    fn_8008AB7C(arg1 + (arg3 >> 1), arg2 + (arg4 >> 1), arg3, 0x17, 0x19, 0x4C, arg5);
}

#pragma use_lmw_stmw on
#pragma scheduling on
#pragma opt_lifetimes off



void fn_80134C24(s32 *arg0, const s16 *arg1)
{
  volatile unsigned long pad;
  int new_var;
  Vec2s *fn_8013F748(void *, Vec2s *, Vec2s *);
  s32 Text_MeasureHeight(s32, f32);
  Vec2s out;
  Vec2s in;
  s16 rowH;
  s16 kind;
  s16 colW;
  s16 quot;
  s32 rem;
  s32 hdiv;
  s32 t;
  s16 x;
  s16 y;
  s16 half;
  s16 off48;
  s16 off4a;
  colW = arg1[34];
  kind = arg1[31];
  quot = kind / colW;
  rowH = arg1[35];
  off48 = arg1[36];
  off4a = arg1[37];
  t = MenuGridColumnWidth(arg1, colW);
  rem = kind % colW;
  rem = (s16) rem;
  rem = t * rem;
  x = (s16) (rem + off48);
  new_var = ((s16) rowH) * ((s16) quot);
  y = (s16) (new_var + off4a);
  t = Text_MeasureHeight(-1, lbl_8036A5AC);
  in.x = x;
  half = (s16) ((((s32) ((s16) rowH)) - t) >> 1);
  in.y = ((s32) y) + half;
  *arg0 = *((s32 *) fn_8013F748((void *) arg1, &out, &in));
}
#pragma peephole reset
#pragma optimization_level reset
#pragma global_optimizer reset
#pragma scheduling reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
#pragma opt_strength_reduction off
extern "C" void Ui_LayoutListPanel(void *arg0) {
struct Obj {
virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0; virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0; virtual void v8()=0; virtual void v9()=0; virtual s16 v10()=0;
u8 pad4[6]; s16 unkA,unkC,unkE,unk10,unk12,unk14,unk16,unk18; u8 pad1A[0x2A]; s16 unk44,unk46; u8 pad48[2]; s16 unk4A;
};
Obj *self=(Obj*)arg0;
s16 h=self->unk44;
s16 v=self->v10();
s32 sum=h+v;
s16 t=(sum-1)/h;
s32 tmp=t*self->unk46+self->unk4A*2;
tmp+=0x10;
self->unk10=self->unkC+(s16)tmp;
s16 w,h2,w8,h22;
w=(s16)(self->unk10-self->unkC);
h2=(s16)(self->unkE-self->unkA);
w8=(s16)(w-8);
h22=(s16)(h2-2);
self->unk12=2;
self->unk14=8;
self->unk16=h22;
self->unk18=w8;
}
#pragma opt_strength_reduction reset
#pragma cplusplus reset
void *fn_80134DA8(void *arg0, s16 arg1) {
    extern u8 lbl_80291758[];
    extern u8 lbl_8029180C[];
    extern u8 lbl_80292230[];
    extern u8 lbl_8028FDB0[];

    void Item_Destroy(void *, s32);
    void Heap_Free(void *);

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80291758;
        Item_Destroy((u8 *)arg0 + 0x60, -1);
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_8029180C;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_80292230;
                if (arg0 != NULL) {
                    *(void **)arg0 = lbl_8028FDB0;
                }
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

s32 fn_80134E40(void) {
    return 4;
}

#pragma use_lmw_stmw on
void fn_80134E48(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_8029180C[];
    extern u8 lbl_80292230[];
    extern const f32 lbl_8036A5AC;
    void *new_var;
    s16 w;
    s16 h;
    s16 *new_var2;
    u8 *new_var3;
    s32 zero;
    s16 neg1;
    s16 right;
    s16 bottom;
    u8 ff;
    f32 f;

    zero = 0;
    neg1 = -1;
    ff = 0xFF;
    f = lbl_8036A5AC;
    right = (s16)arg1 + (s16)arg3;
    bottom = (s16)arg2 + (s16)arg4;

    *(void **)arg0 = lbl_8028FDB0;
    new_var2 = (s16 *)((u8 *)arg0 + 0xC);
    *(s32 *)((u8 *)arg0 + 4) = zero;
    *(void **)arg0 = lbl_80292230;
    *(s16 *)((u8 *)arg0 + 8) = neg1;
    *(s16 *)((u8 *)arg0 + 0xA) = (s16)arg1;
    *new_var2 = (s16)arg2;
    *(s16 *)((u8 *)arg0 + 0xE) = right;
    *(s16 *)((u8 *)arg0 + 0x10) = bottom;
    *(s16 *)((u8 *)arg0 + 0x12) = (s16)zero;
    *(s16 *)((u8 *)arg0 + 0x14) = (s16)zero;
    *(s16 *)((u8 *)arg0 + 0x16) = (s16)arg3;
    *(s16 *)((u8 *)arg0 + 0x18) = (s16)arg4;
    *(s16 *)((u8 *)arg0 + 0x1A) = (s16)zero;
    *(s16 *)((u8 *)arg0 + 0x1C) = (s16)zero;
    ((u8 *)arg0)[0x1E] = ff;
    ((u8 *)arg0)[0x1F] = ff;
    ((u8 *)arg0)[0x20] = ff;
    ((u8 *)arg0)[0x21] = ff;
    *(s16 *)((u8 *)arg0 + 0x22) = (s16)arg5;
    *(s16 *)((u8 *)arg0 + 0x24) = (s16)zero;
    *(f32 *)((u8 *)arg0 + 0x28) = f;
    *(f32 *)((u8 *)arg0 + 0x2C) = f;
    *(f32 *)((u8 *)arg0 + 0x30) = f;
    *(s32 *)((u8 *)arg0 + 0x34) = zero;
    *(s32 *)((u8 *)arg0 + 0x38) = zero;
    *(void **)arg0 = lbl_8029180C;
    ((u8 *)arg0)[0x3C] = 1;
    ((u8 *)arg0)[0x3D] = 1;
    *(s16 *)((u8 *)arg0 + 0x3E) = (s16)zero;
    *(s16 *)((u8 *)arg0 + 0x40) = neg1;
    *(s16 *)((u8 *)arg0 + 0x42) = neg1;
    *(s16 *)((u8 *)arg0 + 0x44) = 2;
    *(s16 *)((u8 *)arg0 + 0x46) = 0x30;
    *(s16 *)((u8 *)arg0 + 0x48) = 0x10;
    *(s16 *)((u8 *)arg0 + 0x4A) = (s16)zero;
    new_var = arg0;
    h = (s16)(*(s16 *)((u8 *)new_var + 0x10) - *(s16 *)((u8 *)new_var + 0xC));
    w = (s16)(*(s16 *)((u8 *)new_var + 0xE) - *(s16 *)((u8 *)new_var + 0xA));
    *(s16 *)((u8 *)arg0 + 0x12) = 2;
    new_var3 = (u8 *)arg0 + 0x14;
    *(s16 *)new_var3 = 8;
    *(s16 *)((u8 *)arg0 + 0x18) = (s16)(h - 8);
    *(s16 *)((u8 *)arg0 + 0x16) = (s16)(w - 2);
}
#pragma use_lmw_stmw reset
void *fn_80134F74(void *arg0, s16 arg1) {
    M2C_UNK Heap_Free(void *);
    extern u16 lbl_8028FDB0[];
    extern u16 lbl_80292230[];
    extern u8 lbl_80291794[];
    extern u8 lbl_8029180C[];

    if (arg0 != NULL) {
        M2C_FIELD(arg0, void **, 0) = lbl_80291794;
        if (arg0 != NULL) {
            M2C_FIELD(arg0, void **, 0) = lbl_8029180C;
            if (arg0 != NULL) {
                M2C_FIELD(arg0, void **, 0) = lbl_80292230;
                if (arg0 != NULL) {
                    M2C_FIELD(arg0, void **, 0) = lbl_8028FDB0;
                }
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

s32 fn_80134FF0(void) {
    return 0;
}

void *fn_80134FF8(void *arg0, s16 arg1) {
    M2C_UNK Heap_Free(void *);
    extern u16 lbl_8028FDB0[];
    extern u16 lbl_80292230[];
    extern u8 gUiMainListPanelVtbl[];
    extern u8 lbl_8029180C[];

    if (arg0 != NULL) {
        M2C_FIELD(arg0, void **, 0) = gUiMainListPanelVtbl;
        if (arg0 != NULL) {
            M2C_FIELD(arg0, void **, 0) = lbl_8029180C;
            if (arg0 != NULL) {
                M2C_FIELD(arg0, void **, 0) = lbl_80292230;
                if (arg0 != NULL) {
                    M2C_FIELD(arg0, void **, 0) = lbl_8028FDB0;
                }
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

s32 fn_80135074(void) {
    return 5;
}

s32 fn_8013507C(void) {
    return 0;
}

#pragma push
#pragma optimization_level 4
#pragma opt_strength_reduction off
#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void fn_80135084(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3(s32) = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9(s16, s16, s32) = 0;
        virtual void v10() = 0;
        u8 pad4[0xE];
        s16 unk12;
        s16 unk14;
        s16 unk16;
        s16 unk18;
        u8 pad1A[0x1A];
        u32 unk34;
        u8 pad38[4];
        s32 unk3C;
        s16 unk40;
        s16 unk42;
        s16 unk44;
        s16 unk46;
        s16 unk48;
        s16 unk4A;
    };
    void fn_8013F748(void *, s16 *, s16 *);
    void Prim2D_Begin(void);
    void Prim2D_SetCallback(void (*)(void *), s16 *);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_PrepareTex(void);
    s32 Text_MeasureHeight(s32, f32);
    u8 *fn_801057BC(s32);
    u8 *fn_80104970(u8 *);
    void fn_800C9874(s32 *, s32, s8);
    s32 String_CStr(s32 *);
    void Text_Draw(s16, s16, s32, void *, s32, ...);
    void String_Destroy(s32 *, s32);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_ScissorFromRect(void *);
    extern f32 lbl_8036A5D8;
    extern f32 lbl_8036A5DC;
    extern u8 lbl_80276720[];
    s32 saved;
    s16 ax;
    s16 ay;
    Obj *self;
    s16 pad;
    u8 *end;
    u8 *p;
    s32 arg;
    s16 w;
    s16 h;
    u8 *str;
    u8 done;
    s32 buf[3];
    s32 ch;
    s16 *rect;
    s32 tmp;
    void (*draw)(Obj *, s16, s16, s32);

    self = (Obj *)arg0;
    arg = arg1;
    saved = self->unk3C;
    self->v10();
    self->v3(arg);
    rect = &self->unk44;
    h = (s16)(self->unk18 - self->unk14);
    w = (s16)(self->unk16 - self->unk12);
    self->unk44 = 0;
    self->unk46 = 0;
    self->unk48 = w;
    self->unk4A = h;
    fn_8013F748(self, rect, rect);
    rect = &self->unk48;
    fn_8013F748(self, rect, rect);
    Prim2D_Begin();
    Prim2D_SetCallback(Prim2D_ScissorFromRect, &self->unk44);
    Prim2D_AddZ(lbl_8036A5D8);
    Prim2D_SetTex(0, (u16)(self->unk34 | 3));
    Prim2D_PrepareTex();
    draw = (void (*)(Obj *, s16, s16, s32))(*(void ***)self)[11];
    ax = self->unk40;
    ay = self->unk42;
    draw(self, ax, ay, saved);
    Prim2D_Begin();
    Prim2D_SetTex(0, (u16)(self->unk34 | 3));
    Prim2D_PrepareTex();
    pad = (s16)((0x1A - Text_MeasureHeight(-1, lbl_8036A5DC)) >> 1);
    tmp = Text_MeasureHeight(-1, lbl_8036A5DC);
    tmp = tmp * 2;
    tmp += ay;
    ay = (s16)(pad + tmp);
    p = fn_801057BC(saved);
    str = lbl_80276720;
    for (;;) {
        done = 0;
        buf[1] = 0;
        buf[0] = 0;
        buf[2] = 0;
        buf[1] = 0;
        while (done == 0) {
            switch ((s8)*p) {
            case 0:
            case 10:
                fn_800C9874(buf, 1, 0);
                done = 1;
                break;
            default:
            end = fn_80104970(p);
            while (p != end) {
                fn_800C9874(buf, 1, (s8)*p);
                p += 1;
            }
            }
        }
        Text_Draw(ax, ay, 1, str + 0x1D, String_CStr(buf));
        if ((s32)(u8)*p == 0xA) {
            ay += 0x1A;
            String_Destroy(buf, -1);
        } else if ((s8)*p == 0) {
            String_Destroy(buf, -1);
            break;
        } else {
            String_Destroy(buf, -1);
        }
        p += 1;
    }
    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
}
#pragma pop
#pragma cplusplus on
extern "C" void fn_801352F0(void *arg0) {
    void fn_80154A74(s32, s32, s16, s16, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_80154A74(0, 0,
        (s16)(*(s16 *)((u8 *)arg0 + 0xE) - *(s16 *)((u8 *)arg0 + 0xA)),
        (s16)(*(s16 *)((u8 *)arg0 + 0x10) - *(s16 *)((u8 *)arg0 + 0xC)),
        0xB3, 0x10);
}

extern "C" void fn_8013535C(void *self, s32 argX, s32 argY, void *argItem) {
#pragma cplusplus reset
#pragma use_lmw_stmw on
void Prim2D_Begin(void); void Prim2D_SetTex(s32,u16); void Prim2D_PrepareTex(void);
s32 Text_MeasureHeight(s32,f32);
s32 fn_8010586C(void *);
void Text_Draw(s16,s16,s32,void *,...);
void Prim2D_AddPrim(s32);
u32 *Ui_GetColor(s32);
void Prim2D_SetColorPacked(void *);
void Prim2D_SetTextScale(s32,f32);
void fn_80006B18(s32,s32,s32,s32,u8);
void Prim2D_EndPrim(void);
void Ui_DrawIcon(void *,s32,s32,u8);
extern u8 lbl_80276720[],gItemIconDrawer[];
extern f32 lbl_8036A5DC,lbl_8036A5E0;
s16 x;
s16 y;
void *item=argItem;
s32 textY;
u32 color;
s32 name;
Prim2D_Begin();
Prim2D_SetTex(0,(u16)(*(u32 *)((u8 *)self+0x34)|3));
Prim2D_PrepareTex();
textY=(s16)((26-Text_MeasureHeight(-1,lbl_8036A5DC))>>1);
name=fn_8010586C(item);
x=argX; y=argY;
textY=y+textY;
Text_Draw((s16)(x+32),(s16)textY,1,lbl_80276720+0x1D,name);
Prim2D_AddPrim(6);
color=*Ui_GetColor(1);
Prim2D_SetColorPacked(&color);
Prim2D_SetTextScale(1,lbl_8036A5E0);
fn_80006B18(x+(s16)(*(s16 *)((u8 *)self+0x16)-*(s16 *)((u8 *)self+0x12))-2* *(s16 *)((u8 *)self+0x40),textY,0,0,*((u8 *)item+0x1A));
Prim2D_EndPrim();
Ui_DrawIcon(gItemIconDrawer,x,y,*((u8 *)item+0x19));
#pragma cplusplus on
}

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" void fn_8013547C(void *arg0) {
    void fn_80154BE4(s32, s32, s16, s16, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_80154BE4(0, 0,
        (s16)(*(s16 *)((u8 *)arg0 + 0xE) - *(s16 *)((u8 *)arg0 + 0xA)),
        (s16)(*(s16 *)((u8 *)arg0 + 0x10) - *(s16 *)((u8 *)arg0 + 0xC)),
        0xB3, 0x10);
}

extern "C" void fn_801354E8(void *arg0, s32 arg1, s32 arg2, s32 unused, void *arg4, u8 arg5) {
void Prim2D_Begin(void); void Prim2D_SetTex(s32,u16); void Prim2D_PrepareTex(void);
void Text_Draw(s16,s16,s32,void *,...);
s32 Text_MeasureHeight(s32,f32);
void Prim2D_AddPrim(s32); void Prim2D_SetColorPacked(void *);
void Prim2D_SetTextScale(s32,f32); void fn_80006B18(s32,s32,s32,s32,u8);
void Prim2D_EndPrim(void); void Ui_DrawIcon(void *,s16,s16,u8);
s32 fn_8010586C(void *); s32 *Ui_GetColor(s32);
u16 Unit_GetSkillCapacityUsed(void *);
extern u8 lbl_80276720[],gItemIconDrawer[];
extern f32 lbl_8036A5DC,lbl_8036A5E0;
s32 color;
s32 textY;
s16 x,y;
s16 offset;
s32 name;
void *unit;
u8 capacity,cost;
s32 drawFlag;
s32 flag = (arg5 != 0);
Prim2D_Begin();
Prim2D_SetTex(0,(u16)(M2C_FIELD(arg0,u32 *,0x34)|3));
Prim2D_PrepareTex();
offset=(32-Text_MeasureHeight(-1,lbl_8036A5DC))>>1;
name=fn_8010586C(arg4);
x=arg1; y=arg2;
textY=y+offset;
Text_Draw((s16)(x+32),(s16)textY,flag,lbl_80276720+0x1D,name);
unit=M2C_FIELD(arg0,void **,0xCC);
drawFlag=flag;
if(arg5) {
void *data=M2C_FIELD(unit,void **,0x18C);
cost=M2C_FIELD(arg4,u8 *,0x1A);
capacity=M2C_FIELD(data,u8 *,0x40);
if(cost>capacity-Unit_GetSkillCapacityUsed(unit)) drawFlag=0;
}
Prim2D_AddPrim(6);
color=*Ui_GetColor(drawFlag);
Prim2D_SetColorPacked(&color);
Prim2D_SetTextScale(1,lbl_8036A5E0);
fn_80006B18(x+(s16)((s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))/M2C_FIELD(arg0,s16 *,0x56))-2*M2C_FIELD(arg0,s16 *,0x5C)-24,textY,0,0,M2C_FIELD(arg4,u8 *,0x1A));
Prim2D_EndPrim();
Ui_DrawIcon(gItemIconDrawer,x,y,M2C_FIELD(arg4,u8 *,0x19));
}
#pragma cplusplus reset
s32 fn_80135664(void *arg0, void *arg1) {
    u8 Status_Test(s32, u8);
    u8 (*temp_r12)(void *, s32);

    temp_r12 = M2C_FIELD(arg0, u8 (**)(void *, s32), 0x74);
    if (temp_r12 != NULL) {
        return temp_r12(arg1, M2C_FIELD(arg0, s32 *, 0x78)) != 0;
    }
    return Status_Test(M2C_FIELD(arg0, s32 *, 0xCC) + 0x1BC, M2C_FIELD(arg1, u8 *, 0x18)) == 0;
}

#pragma cplusplus on
extern "C" void fn_801356D0(void *arg0, s32 arg1) {
extern u8 lbl_80291860[];
struct Obj { virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0; virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; };
struct Node { Node *prev; Node *next; Obj *obj; };
typedef void (Obj::*PTMF)(s32);
struct Pair { PTMF ptmf; s32 arg; };
Pair p[2];
Node *it;
Node *sent;
((Obj*)arg0)->v6();
sent=(Node*)((u8*)arg0+0x40);
p[0].ptmf=*(PTMF*)lbl_80291860;
p[0].arg=arg1;
((u32*)&p[1].ptmf)[0]=((u32*)&p[0].ptmf)[0];
it=sent->next;
((u32*)&p[1].ptmf)[1]=((u32*)&p[0].ptmf)[1];
((u32*)&p[1].ptmf)[2]=((u32*)&p[0].ptmf)[2];
p[1].arg=arg1;
while(it!=sent) { (it->obj->*p[0].ptmf)(p[0].arg); it=it->next; }
}
#pragma cplusplus reset

#pragma push
#pragma optimization_level 4
#pragma cplusplus on
#pragma global_optimizer on
#pragma opt_common_subs off
extern "C" void fn_8013577C(void *arg0) {
    void Ui_PlaySeCue(void *, s32);
    extern u8 lbl_80276720[];
    void fn_8013ED84(void *, s16);
    extern u32 gUiInputFlags;
    extern u32 *gPadInput;
    extern const f32 lbl_8036A5F0;
    extern const f32 lbl_8036A5EC;
    struct Obj {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
        virtual void v9() = 0; virtual s32 v10() = 0;
    };

    s32 vret;
    s32 rows;
    s32 raw;
    s32 total;
    register s32 rows2;
    s16 pages;
    s16 col;
    u8 skip;
    s32 trig;
    s16 page;
    register s16 saved;
    s32 edge;
    s32 held;
    long rows_m1;

    vret = ((Obj *)arg0)->v10();
    rows = *(s16 *)((u8 *)arg0 + 0x56);
    raw = *(s32 *)((u8 *)arg0 + 0x68);
    rows_m1 = rows - 1;
    total = (s16)raw;
    pages = (s16)((total + rows_m1) / rows);
    if ((s16)vret > pages) {
        vret = pages;
    }
    skip = 0;
    {
        register s16 t = *(s16 *)((u8 *)arg0 + 0x4E);
        page = (s16)(t / rows);
        col = (s16)(t % rows);
    }
    if ((gUiInputFlags & 0x10) != 0) {
        if ((gUiInputFlags & 0x20) == 0) {
            skip = 1;
        }
    }
    if (!skip) {
        rows2 = (s16)rows;
        saved = *(s16 *)((u8 *)arg0 + 0x4E);
        held = (s32)gPadInput[1];
        trig = gPadInput[3];
        edge = held & (gPadInput[2] ^ held);
        if (1 < rows2) {
            held = total - page * rows;
            if (held > rows) {
                held = rows2;
            }
            if ((trig & 0x01000001) != 0) {
                if (col > 0) {
                    *(s16 *)((u8 *)arg0 + (s32)0x4E) = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) - 1);
                } else if (trig == edge) {
                    register s32 idx = *(s16 *)((u8 *)arg0 + 0x4E);
                    idx = held + idx;
                    idx = idx - 1;
                    *(s16 *)((u8 *)arg0 + 0x4E) = idx;
                }
            } else if ((trig & 0x02000002) != 0) {
                int lim = held - 1;
                if (col < lim) {
                    *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) + 1);
                } else if (trig == edge) {
                    *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) - lim);
                }
            }
        }
        if ((s16)(s32)*(f32 *)((u8 *)arg0 + 0x58) == 0) {
            if ((trig & 0x08000008) != 0) {
                if (!page) {
                    if (trig == edge) {
                        s32 pm1 = pages - 1;
                        register s16 vr = (s16)vret;
                        register s32 add = pm1 * rows;
                        s16 cur = *(s16 *)((u8 *)arg0 + 0x4E);
                        unsigned int d = pages - vr;
                        s32 tmax = total - 1;
                        long tmp = (-d) & ~d;
                        *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(cur + add);
                        *(s16 *)((u8 *)arg0 + 0x54) = (s16)(d & (tmp >> 31));
                        if (*(s16 *)((u8 *)arg0 + 0x4E) > tmax) {
                            *(s16 *)((u8 *)arg0 + 0x4E) = (s16)tmax;
                        }
                    }
                } else {
                    *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) - rows);
                    if (*(s16 *)((u8 *)arg0 + 0x4E) > rows_m1) {
                        if (((s16)(*(s16 *)((u8 *)arg0 + 0x4E) / rows) - *(s16 *)((u8 *)arg0 + 0x54)) == 0) {
                            s16 ns = (s16)(*(s16 *)((u8 *)arg0 + 0x54) - 1);
                            f32 fv = lbl_8036A5EC;
                            *(s16 *)((u8 *)arg0 + 0x54) = ns;
                            *(f32 *)((u8 *)arg0 + 0x58) = fv;
                        }
                    }
                }
                if (saved != *(s16 *)((u8 *)arg0 + 0x4E)) {
                    *(s16 *)((u8 *)arg0 + 0x92) = 1;
                    *(u8 *)((u8 *)arg0 + 0x89) = 1;
                }
            } else if ((trig & 0x04000004) != 0) {
                s32 pm1 = pages - 1;
                if (page == pm1) {
                    if (trig == edge) {
                        *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) - pm1 * rows);
                        *(s16 *)((u8 *)arg0 + 0x54) = 0;
                    }
                } else {
                    s32 tmax = total - 1;
                    *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) + rows);
                    if (*(s16 *)((u8 *)arg0 + 0x4E) > tmax) {
                        *(s16 *)((u8 *)arg0 + 0x4E) = (s16)tmax;
                    }
                    {
                        register s16 np = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) / rows);
                        if (np < pm1) {
                            s16 sc = *(s16 *)((u8 *)arg0 + 0x54);
                            if ((s32)((s16)vret - 1) == (s32)(np - sc)) {
                                s16 ns = (s16)(sc + 1);
                                f32 fv = lbl_8036A5F0;
                                *(s16 *)((u8 *)arg0 + 0x54) = ns;
                                *(f32 *)((u8 *)arg0 + 0x58) = fv;
                            }
                        }
                    }
                }
                if (saved != *(s16 *)((u8 *)arg0 + 0x4E)) {
                    *(s16 *)((u8 *)arg0 + 0xBA) = 1;
                    *(u8 *)((u8 *)arg0 + 0xB1) = 1;
                }
            }
        }
        if (saved != *(s16 *)((u8 *)arg0 + 0x4E)) {
            Ui_PlaySeCue(lbl_80276720 + 0x22, 0x64);
        }
    }
    fn_8013ED84(*(void **)((u8 *)arg0 + 0x48),
                (s16)((*(s16 *)((u8 *)arg0 + 0x54) << 5) - (s32)*(f32 *)((u8 *)arg0 + 0x58)));
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma cplusplus on
extern "C" void fn_80135AC0(void *self, void *other) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
    };
    struct Sub {
        virtual void v0() = 0;
    };
    struct Node {
        Node *prev;
        Node *next;
        Sub *obj;
    };
    typedef void (Sub::*PTMF)(void *);
    struct Pair {
        PTMF ptmf;
        void *arg;
    };
    void fn_8000A258(void);
    void fn_80009C0C(f32);
    void fn_8000A248(void);
    s32 fn_800102BC(s32, f32);
    void fn_8008BF68(s16, s32, u8);
    void fn_8008AB7C(s32, s32, s16, s32, s32, s32, u8);
    extern u8 lbl_80291854[];
    extern f32 lbl_8036A5F4;
    extern f32 lbl_8036A5DC;
    extern f32 lbl_8036A5F8;
    Node *it;
    u8 r31;
    s16 r30;
    s16 r29;
    s16 r28;
    Pair p[2];
    Node *sent;
    u8 flag;
    void *ptr;

    ((Obj *)self)->v3();
    {
        s16 t56;
        s16 t4e;
        s16 t50;
        s32 quot;
        s16 t12;
        s16 t16;
        s16 t54;
        s16 t5c;
        s16 t5e;
        s16 q;

        t56 = *(s16 *)((u8 *)self + 0x56);
        t4e = *(s16 *)((u8 *)self + 0x4E);
        t50 = *(s16 *)((u8 *)self + 0x50);
        quot = t4e / t56;
        t12 = *(s16 *)((u8 *)self + 0x12);
        t16 = *(s16 *)((u8 *)self + 0x16);
        t54 = *(s16 *)((u8 *)self + 0x54);
        q = (s16)quot;
        r30 = (s16)((s16)(t16 - t12) / t56);
        t5c = *(s16 *)((u8 *)self + 0x5C);
        t5e = *(s16 *)((u8 *)self + 0x5E);
        r28 = (s16)(((s16)(q - t54) << 5) + t5e);
        r29 = (s16)(r30 * (s16)(t4e % t56) + t5c);
        if (t50 < 0 || *(s16 *)((u8 *)self + 0x52) < 0) {
            *(s16 *)((u8 *)self + 0x50) = r29;
            *(s16 *)((u8 *)self + 0x52) = r28;
        } else {
            *(s16 *)((u8 *)self + 0x50) = (t50 + r29 + 1) >> 1;
            *(s16 *)((u8 *)self + 0x52) = (*(s16 *)((u8 *)self + 0x52) + r28 + 1) >> 1;
        }
    }
    if (*(u8 *)((u8 *)self + 0x4C) != 0 && *(u32 *)((u8 *)self + 0x68) != 0) {
        r31 = 0;
        flag = r31;
        if (*(u8 *)((u8 *)other + 0x2D) == 0) {
            if (*(u8 *)((u8 *)other + 0x2E) == 0) {
                flag = 1;
            }
        }
        if (flag) {
            if (*(u32 *)((u8 *)other + 0x34) != 0) {
                ptr = (*(void ***)((u8 *)other + 0x38))[2];
            } else {
                ptr = 0;
            }
            if (ptr == self) {
                r31 = 1;
            }
        }
        fn_8000A258();
        fn_80009C0C(lbl_8036A5F4);
        fn_8000A248();
        fn_8008BF68(*(s16 *)((u8 *)self + 0x50),
                    *(s16 *)((u8 *)self + 0x52) + (s16)((0x20 - fn_800102BC(-1, lbl_8036A5DC)) >> 1),
                    r31);
        fn_8000A258();
        fn_80009C0C(lbl_8036A5F8);
        fn_8000A248();
        fn_8008AB7C((r30 >> 1) + (r29 - *(s16 *)((u8 *)self + 0x5C)),
                    r28 + 0x10, r30, 0x18, 0x19, 0x4C, r31);
    }
    p[0].arg = other;
    sent = (Node *)((u8 *)self + 0x40);
    p[0].ptmf = *(PTMF *)lbl_80291854;
    p[1].ptmf = *(PTMF *)lbl_80291854;
    it = *(Node **)((u8 *)self + 0x44);
    p[1].arg = other;
    while (it != sent) {
        (it->obj->*p[0].ptmf)(p[0].arg);
        it = it->next;
    }
}
#pragma pop
#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void fn_80135CE8(u8 *self, s32 arg1) {
    struct Obj {
        virtual void v0()=0; virtual void v1()=0; virtual void v2()=0;
        virtual void v3(s32)=0; virtual void v4()=0; virtual void v5()=0;
        virtual void v6()=0; virtual void v7()=0; virtual void v8()=0;
        virtual void v9()=0; virtual s32 v10()=0;
        virtual s32 v11(void *)=0;
        virtual void v12(s16,s16,s32,void *,s32)=0;
        virtual void v13()=0;
        u8 pad4[14]; s16 a12,a14,a16,a18; u8 pad1a[0x3a]; s16 a54,a56; f32 a58; s16 a5c,a5e; s16 rect[4]; u32 a68;
    };
    struct Sub {
        virtual void v0()=0; virtual void v1()=0; virtual void v2()=0;
        virtual void v3()=0; virtual void v4()=0; virtual void v5()=0;
        virtual void v6()=0; virtual void v7()=0; virtual void v8()=0;
        virtual void v9(s32)=0;
    };
    struct Node { Node *prev; Node *next; Sub *obj; };
    typedef void (Sub::*PTMF)(s32);
    struct Pair { PTMF ptmf; s32 arg; };
    void fn_8013F748(void *,s16 *,s16 *);
    void Prim2D_Begin(void); void Prim2D_PrepareTex(void); void Prim2D_ClearCallbacks(void);
    void Prim2D_AddZ(f32); void Prim2D_ScissorFromRect(void *);
    void Prim2D_SetCallback(void (*)(void *),s16 *);
    extern f32 lbl_8036A5D8,lbl_8036A5E4,lbl_8036A5E8,lbl_8036A5F4;
    extern f32 lbl_80367098[];
    extern u8 lbl_80291848[];
    s32 visible;
    s16 rows;
    s16 width;
    Node *node;
    s32 xpos;
    s32 ypos;
    s16 scroll;
    s16 index;
    s16 row;
    s16 endrow;
    s16 y;
    s16 col;
    Node *it,*sent;
    s16 x;
    s16 sign;
    Pair p[2];
    s16 *rect;
    ((Obj *)self)->v13();
    ((Obj *)self)->v3(arg1);
    rect=(s16 *)(self+0x60);
    s16 h=((Obj *)self)->a18-((Obj *)self)->a14;
    s16 w=((Obj *)self)->a16-((Obj *)self)->a12;
    rect[0]=0; rect[1]=0; rect[2]=w; rect[3]=h;
    fn_8013F748(self,rect,rect);
    rect=(s16 *)(self+0x64); fn_8013F748(self,rect,rect);
    Prim2D_Begin(); Prim2D_AddZ(lbl_8036A5D8);
    Prim2D_SetCallback(Prim2D_ScissorFromRect,(s16 *)(self+0x60)); Prim2D_PrepareTex();
    rows=((Obj *)self)->a56;
    visible=((Obj *)self)->v10();
    width=(s16)((s16)(((Obj *)self)->a16-((Obj *)self)->a12)/ ((Obj *)self)->a56);
    scroll=(s16)((Obj *)self)->a58;
    index=((Obj *)self)->a56* ((Obj *)self)->a54;
    f32 zero=lbl_8036A5E4;
    if (((Obj *)self)->a58<zero) {
        f32 value=*(volatile f32 *)&((Obj *)self)->a58+lbl_8036A5E8;
        ((Obj *)self)->a58=value;
        if (value>=-lbl_80367098[0]) ((Obj *)self)->a58=zero;
    } else if (((Obj *)self)->a58>zero) {
        f32 value=*(volatile f32 *)&((Obj *)self)->a58-lbl_8036A5E8;
        ((Obj *)self)->a58=value;
        if (value<=lbl_80367098[0]) ((Obj *)self)->a58=zero;
    }
    sign=scroll<0 ? -1 : (scroll>0 ? 1 : 0);
    if(sign>0 && index-rows>=0) index-=rows;
    node=*(Node **)(self+0x70);
    s16 n=index;
    if(index>=0) { while(n>0) {node=node->next; --n;} }
    else {while(n<0) {node=node->prev; ++n;} }
    row=(-sign & ~sign)>>31;
    s32 er=(s16)visible;
    if(sign<0) ++er;
    endrow=er;
    ypos=scroll+(row<<5);
    for(;row<endrow;ypos+=32,++row) {
        col=0; xpos=0;
        y=ypos+((Obj *)self)->a5e;
        while(col<rows) {
            if((u32)index>=((Obj *)self)->a68) goto done;
            x=xpos+((Obj *)self)->a5c;
            ((Obj *)self)->v12(x,y,-1,node->obj,((Obj *)self)->v11(node->obj));
            node=node->next; xpos+=width; ++col; ++index;
        }
    }
done:
    Prim2D_Begin(); Prim2D_ClearCallbacks(); Prim2D_PrepareTex();
    Prim2D_Begin(); Prim2D_AddZ(lbl_8036A5F4); Prim2D_PrepareTex();
    s32 rm1=rows-1;
    s16 pages=(rm1+((Obj *)self)->a68)/(u32)rows;
    *(u8 *)(self+0x88)=((Obj *)self)->a54>0;
    s16 page=((Obj *)self)->a54;
    s32 available=pages-(s16)((Obj *)self)->v10();
    *(u8 *)(self+0xb0)=page<available;
    ((Sub *)(self+0x7c))->v9(16); ((Sub *)(self+0xa4))->v9(16);
    s16 bw=((rm1+((Obj *)self)->a68)/(u32)rows)<<5;
    s16 bh=(s16)visible<<5;
    s16 by=(((Obj *)self)->a54<<5)-scroll;
    u8 *bar=*(u8 **)(self+0x48);
    *(s16 *)(bar+0x3c)=bw;
    *(s16 *)(bar+0x3e)=bh;
    *(s16 *)(bar+0x40)=by;
    p[1].arg=arg1;
    p[0].ptmf=*(PTMF *)lbl_80291848; p[0].arg=arg1; p[1].ptmf=*(PTMF *)lbl_80291848;
    it=*(Node **)(self+0x44); sent=(Node *)(self+0x40);
    while(it!=sent) { (it->obj->*p[0].ptmf)(p[0].arg); it=it->next; }
}
#pragma cplusplus reset
#pragma global_optimizer reset

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_801360FC(void *arg0) {
    void fn_8015BA88(s32, s32, s16, s16, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_8015BA88(0, 0,
        (s16)(*(s16 *)((u8 *)arg0 + 0xE) - *(s16 *)((u8 *)arg0 + 0xA)),
        (s16)(*(s16 *)((u8 *)arg0 + 0x10) - *(s16 *)((u8 *)arg0 + 0xC)),
        0xB3, 0x10);
}
#pragma cplusplus reset

void fn_80136168(void *arg0, s16 arg1, s16 arg2, s32 unused, void *arg4, u8 arg5) {
void Prim2D_Begin(void); void Prim2D_SetTex(s32,u16); void Prim2D_PrepareTex(void);
void Text_Draw(s16,s16,s32,void *,s32,...);
void Prim2D_AddPrim(s32); void Prim2D_SetColorPacked(void *);
void Prim2D_SetTextScale(s32,f32); void fn_80006B18(s32,s32,s32,s32,u8);
void Prim2D_EndPrim(void); void Ui_DrawIcon(void *,s16,s16,u8);
s32 fn_8010586C(void *); s32 *Ui_GetColor(s32);
extern u8 lbl_80276720[],lbl_802F0350[]; extern f32 lbl_8036A5E0;
s32 sp8; s32 y,tx,x,name; s32 flag;
flag=arg5!=0;
Prim2D_Begin(); Prim2D_SetTex(0,(u16)(*(u32 *)((u8 *)arg0+0x34)|0x13)); Prim2D_PrepareTex();
name=fn_8010586C(arg4);
y=arg1; x=arg2; tx=x+0x20;
Text_Draw(tx,y+4,flag,lbl_80276720+0x1d,name);
Prim2D_AddPrim(6); sp8=*Ui_GetColor(flag); Prim2D_SetColorPacked(&sp8);
Prim2D_SetTextScale(1,lbl_8036A5E0);
fn_80006B18(tx,y+8,0,0,((u8 *)arg4)[0x1a]);
Prim2D_EndPrim(); Ui_DrawIcon(lbl_802F0350,x,y,((u8 *)arg4)[0x19]);
}

s32 fn_80136268(void *arg0, void *arg1) {
    u8 (*temp_r12)(void *, s32);

    temp_r12 = M2C_FIELD(arg0, u8 (**)(void *, s32), 0x74);
    if (temp_r12 != NULL) {
        return temp_r12(arg1, M2C_FIELD(arg0, s32 *, 0x78)) != 0;
    }
    return M2C_FIELD(arg1, u8 *, 0x19) != 0;
}

s32 fn_801362C8(void *arg0) {
    struct Node {
        struct Node *prev;
        struct Node *next;
        s32 unk8;
    };
    s32 tmp;
    s16 n;
    struct Node *node;

    if (*(u32 *)((u8 *)arg0 + 0x68) == 0) {
        return 0;
    }
    tmp = *(s16 *)((u8 *)arg0 + 0x4E);
    node = *(struct Node **)((u8 *)arg0 + 0x70);
    n = (s16)tmp;
    if (n >= 0) {
        goto loop_pos;
        do {
            node = node->next;
            n -= 1;
        loop_pos:
            ;
        } while (n > 0);
    } else {
        goto loop_neg;
        do {
            node = node->prev;
            n += 1;
        loop_neg:
            ;
        } while (n < 0);
    }
    return node->unk8;
}

#pragma scheduling on
void fn_80136320(s32 *arg0, s16 *arg1) {
    s32 *fn_8013F748(s16 *, s32 *, s16 *);
    s16 in[2];
    s32 out;
    s16 v56 = arg1[0x56 / 2];
    s16 *self = arg1;
    s16 v4e = arg1[0x4E / 2];
    s32 quot = v4e / v56;
    s16 v12 = self[0x12 / 2];
    s16 v16 = self[0x16 / 2];
    s32 diff = v16 - v12;
    s16 v54 = self[0x54 / 2];
    s16 v5e = self[0x5E / 2];
    s16 v5c = self[0x5C / 2];
    s32 t = (s16)diff;
    s32 rem = (s16)((s16)quot - v54);
    rem = (s16)rem << 5;
    in[1] = rem + v5e;
    {
        s32 hdiv = t / v56;
        rem = v4e - quot * v56;
        rem = (s16)hdiv * (s16)rem;
        in[0] = rem + v5c;
    }
    *arg0 = *fn_8013F748(self, &out, in);
}
#pragma scheduling reset
void *fn_801363C4(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_8029186C[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_8029186C;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma global_optimizer off
void fn_80136430(void *arg0) {
    s16 height, width;
    s32 bottom, right;
    s16 *p = (s16 *)arg0;
    height = p[0x10 / 2] - p[0xC / 2];
    width = p[0xE / 2] - p[0xA / 2];
    bottom = height - 0xC;
    right = width - 5;
    p[0x12 / 2] = 5;
    p[0x14 / 2] = 0xC;
    p[0x16 / 2] = right;
    p[0x18 / 2] = bottom;
}
#pragma global_optimizer reset
s16 fn_80136474(void *arg0) {
    return (s16) ((s32) ((s16) (M2C_FIELD(arg0, s16 *, 0x18) - M2C_FIELD(arg0, s16 *, 0x14)) - (M2C_FIELD(arg0, s16 *, 0x5E) * 2)) / 32);
}

#pragma cplusplus on
/* C++ destructor for a unit-panel widget (gUiUnitPanelVtbl): destroy embeds, clear list, base dtor, optional free. */
extern "C" void *Ui_DtorUnitPanel(void *self, s16 doFree) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    typedef struct {
        u32 unk0;
        ListNode node;
    } DtorList;
    typedef struct Owner {
        void *vtbl;
        u8 pad4[0x64];
        DtorList list;
        u8 pad78[4];
        void *sub7C;
        u8 pad80[0x24];
        void *subA4;
    } Owner;
    void List_EraseRange(void *, void *, void *, void *);
    void fn_8013F2A4(void *, s32);
    void Heap_Free(void *);
    extern u8 gUiUnitPanelVtbl[];
    extern u8 gUiUnitPanelMidVtbl[];
    extern u8 gEmptyVtbl[];

    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    Owner *owner;

    owner = (Owner *)self;
    if (self != NULL) {
        owner->vtbl = gUiUnitPanelVtbl;
        if (self != NULL) {
            owner->vtbl = gUiUnitPanelMidVtbl;
            if (&owner->subA4 != NULL) {
                owner->subA4 = gEmptyVtbl;
                ((Obj *)&owner->subA4)->v2();
            }
            if (&owner->sub7C != NULL) {
                owner->sub7C = gEmptyVtbl;
                ((Obj *)&owner->sub7C)->v2();
            }
            if (&owner->list != NULL) {
                if (&owner->list != NULL) {
                    if (&owner->list != NULL) {
                        end = &owner->list.node;
                        sp10 = end;
                        spC = end->next;
                        List_EraseRange(sp8, &owner->list, &spC, &sp10);
                    }
                }
            }
            fn_8013F2A4(self, 0);
        }
        if (doFree > 0) {
            Heap_Free(self);
        }
    }
    return self;
}

extern "C" void fn_801365A0(void *arg0) {
#pragma cplusplus reset
void *Heap_Alloc(s32);
void *fn_8013692C(void *,s32,s32,s32,s32,s32);
void fn_8013F0F0(void *,void *);
void fn_8013F1A0(void *,void *);
#pragma cplusplus on
struct Rect {
s16 left,top,right,bottom;
s16 width() { return right-left; }
s16 height() { return bottom-top; }
void set(s16 l,s16 t,s16 r,s16 b) { left=l; top=t; right=r; bottom=b; }
};
void *child;
s16 mid,height;
Rect *outer=(Rect *)((u8 *)arg0+0xA);
Rect *inner=(Rect *)((u8 *)arg0+0x12);
inner->set(3,12,outer->width()-3,outer->height()-12);
M2C_FIELD(arg0,s16 *,0x8A)=(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))>>1;
M2C_FIELD(arg0,s16 *,0x8C)=0;
M2C_FIELD(arg0,s16 *,0x8E)=0;
mid=(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))>>1;
height=M2C_FIELD(arg0,s16 *,0x18)-M2C_FIELD(arg0,s16 *,0x14);
M2C_FIELD(arg0,s16 *,0xB2)=mid;
M2C_FIELD(arg0,s16 *,0xB4)=height;
M2C_FIELD(arg0,s16 *,0xB6)=0;
if(M2C_FIELD(arg0,void **,0x48)) fn_8013F0F0(arg0,M2C_FIELD(arg0,void **,0x48));
child=Heap_Alloc(0x9C);
if(child) child=fn_8013692C(child,(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))-16,0,9,(s16)(M2C_FIELD(arg0,s16 *,0x18)-M2C_FIELD(arg0,s16 *,0x14))-16,M2C_FIELD(arg0,s16 *,0x22)-5);
M2C_FIELD(arg0,void **,0x48)=child;
M2C_FIELD(M2C_FIELD(arg0,void **,0x48),s32 *,0x48)=2;
fn_8013F1A0(arg0,M2C_FIELD(arg0,void **,0x48));
M2C_FIELD(arg0,s16 *,0x5C)=24;
M2C_FIELD(arg0,s16 *,0x5E)=8;
#pragma cplusplus reset
}

#pragma cplusplus reset
s16 fn_801366E4(void *arg0) {
    return (s16) ((s32) ((s16) (M2C_FIELD(arg0, s16 *, 0x18) - M2C_FIELD(arg0, s16 *, 0x14)) - M2C_FIELD(arg0, s16 *, 0x5E)) / 32);
}

#pragma cplusplus on
/* C++ destructor for a mid unit-panel widget (gUiUnitPanelMidVtbl): destroy embeds, clear list, base dtor, optional free. */
extern "C" void *Ui_DtorUnitPanelMid(void *self, s16 doFree) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    typedef struct {
        u32 unk0;
        ListNode node;
    } DtorList;
    typedef struct Owner {
        void *vtbl;
        u8 pad4[0x64];
        DtorList list;
        u8 pad78[4];
        void *sub7C;
        u8 pad80[0x24];
        void *subA4;
    } Owner;
    void List_EraseRange(void *, void *, void *, void *);
    void fn_8013F2A4(void *, s32);
    void Heap_Free(void *);
    extern u8 gUiUnitPanelMidVtbl[];
    extern u8 gEmptyVtbl[];

    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    Owner *owner;

    owner = (Owner *)self;
    if (self != NULL) {
        owner->vtbl = gUiUnitPanelMidVtbl;
        if (&owner->subA4 != NULL) {
            owner->subA4 = gEmptyVtbl;
            ((Obj *)&owner->subA4)->v2();
        }
        if (&owner->sub7C != NULL) {
            owner->sub7C = gEmptyVtbl;
            ((Obj *)&owner->sub7C)->v2();
        }
        if (&owner->list != NULL) {
            if (&owner->list != NULL) {
                if (&owner->list != NULL) {
                    end = &owner->list.node;
                    sp10 = end;
                    spC = end->next;
                    List_EraseRange(sp8, &owner->list, &spC, &sp10);
                }
            }
        }
        fn_8013F2A4(self, 0);
        if (doFree > 0) {
            Heap_Free(self);
        }
    }
    return self;
}

struct Rect367FC {
s16 left,top,right,bottom;
s16 width() { return right-left; }
s16 height() { return bottom-top; }
void set(s16 l,s16 t,s16 r,s16 b) { left=l; top=t; right=r; bottom=b; }
};
extern "C" void fn_801367FC(void *arg0) {
#pragma cplusplus reset
void *Heap_Alloc(s32);
void *fn_8013692C(void *,s32,s32,s32,s32,s32);
void fn_8013F0F0(void *,void *);
void fn_8013F1A0(void *,void *);
#pragma cplusplus on
void *child;
s16 mid,height;
Rect367FC *outer=(Rect367FC *)((u8 *)arg0+0xA);
Rect367FC *inner=(Rect367FC *)((u8 *)arg0+0x12);
inner->set(2,12,outer->width()-2,outer->height()-12);
M2C_FIELD(arg0,s16 *,0x8A)=(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))>>1;
M2C_FIELD(arg0,s16 *,0x8C)=0;
M2C_FIELD(arg0,s16 *,0x8E)=0;
mid=(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))>>1;
height=M2C_FIELD(arg0,s16 *,0x18)-M2C_FIELD(arg0,s16 *,0x14);
M2C_FIELD(arg0,s16 *,0xB2)=mid;
M2C_FIELD(arg0,s16 *,0xB4)=height;
M2C_FIELD(arg0,s16 *,0xB6)=0;
if(M2C_FIELD(arg0,void **,0x48)) fn_8013F0F0(arg0,M2C_FIELD(arg0,void **,0x48));
child=Heap_Alloc(0x9C);
if(child) child=fn_8013692C(child,(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))-11,0,9,(s16)(M2C_FIELD(arg0,s16 *,0x18)-M2C_FIELD(arg0,s16 *,0x14)),M2C_FIELD(arg0,s16 *,0x22)-5);
M2C_FIELD(arg0,void **,0x48)=child;
M2C_FIELD(M2C_FIELD(arg0,void **,0x48),s32 *,0x48)=1;
fn_8013F1A0(arg0,M2C_FIELD(arg0,void **,0x48));
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
extern "C" void *fn_8013692C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
struct Sub { virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0; virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual s16 height()=0; };
extern u8 lbl_802921B0[];
extern f32 lbl_8036A5FC;
void *fn_80136AC4(void *, s32, s32, s32, s32, s32, s32);
u8 *self = (u8 *)arg0;
s32 bottom;
s16 halfWidth, halfHeight;
fn_80136AC4(self,1,arg1,arg2,arg3,arg4,arg5);
*(void **)self=lbl_802921B0;
arg4=(s32)((f32)arg4-lbl_8036A5FC*(f32)((Sub *)(self+0x74))->height());
{ s32 top=(s32)(lbl_8036A5FC * (f32)((Sub *)(self+0x4c))->height());
*(s16 *)(self+0x12)=0;
*(s16 *)(self+0x14)=top; }
*(s16 *)(self+0x16)=arg3;
*(s16 *)(self+0x18)=arg4;
halfWidth=((s16)(*(s16 *)(self+0x16)-*(s16 *)(self+0x12))+1)>>1;
halfHeight=((Sub *)(self+0x74))->height()>>1;
*(s16 *)(self+0x5a)=halfWidth;
*(s16 *)(self+0x5c)=-halfHeight;
*(s16 *)(self+0x5e)=0;
{ s16 span=*(s16 *)(self+0x18)-*(s16 *)(self+0x14);
*(s16 *)(self+0x82)=halfWidth;
*(s16 *)(self+0x84)=halfHeight+span; }
*(s16 *)(self+0x86)=0;
return self;
}
#pragma pop
#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void *fn_80136AC4(void *arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    struct Sub {
        virtual void v0() = 0;
        virtual void v1(s32, s32, f32) = 0;
    };
    extern u8 lbl_8028FDB0[]; extern u8 lbl_80292230[]; extern u8 lbl_80291914[];
    extern u8 gEmptyVtbl[]; extern u8 lbl_802918E0[];
    extern const f32 lbl_8036A5DC; extern const f32 lbl_8036A5E4;
    void *temp_r27; s32 temp_r28; void *temp_r29; void *temp_r30; s32 temp_r31;
    s32 flag; s32 a; s32 b; f32 f0; f32 f;
    temp_r30 = arg0; temp_r27 = temp_r30; temp_r31 = arg1; temp_r28 = 0;
    temp_r29 = (u8 *)temp_r30 + 0x4C; f0 = lbl_8036A5DC;
    *(void **)temp_r30 = lbl_8028FDB0;
    *(s32 *)((u8 *)temp_r27 + 4) = temp_r28;
    *(void **)temp_r27 = lbl_80292230;
    *(s16 *)((u8 *)temp_r27 + 8) = -1;
    *(s16 *)((u8 *)temp_r27 + 0xA) = arg2;
    *(s16 *)((u8 *)temp_r27 + 0xC) = arg3;
    *(s16 *)((u8 *)temp_r27 + 0xE) = (s16)((s16)arg2 + (s16)arg4);
    *(s16 *)((u8 *)temp_r27 + 0x10) = (s16)((s16)arg3 + (s16)arg5);
    flag = 2;
    *(s16 *)((u8 *)temp_r27 + 0x12) = (s16)temp_r28;
    *(s16 *)((u8 *)temp_r27 + 0x14) = (s16)temp_r28;
    *(s16 *)((u8 *)temp_r27 + 0x16) = arg4;
    *(s16 *)((u8 *)temp_r27 + 0x18) = arg5;
    *(s16 *)((u8 *)temp_r27 + 0x1A) = (s16)temp_r28;
    *(s16 *)((u8 *)temp_r27 + 0x1C) = (s16)temp_r28;
    *(u8 *)((u8 *)temp_r27 + 0x1E) = 0xFF;
    *(u8 *)((u8 *)temp_r27 + 0x1F) = 0xFF;
    *(u8 *)((u8 *)temp_r27 + 0x20) = 0xFF;
    *(u8 *)((u8 *)temp_r27 + 0x21) = 0xFF;
    *(s16 *)((u8 *)temp_r27 + 0x22) = arg6;
    *(s16 *)((u8 *)temp_r27 + 0x24) = (s16)temp_r28;
    *(f32 *)((u8 *)temp_r27 + 0x28) = f0;
    *(f32 *)((u8 *)temp_r27 + 0x2C) = f0;
    *(f32 *)((u8 *)temp_r27 + 0x30) = f0;
    *(s32 *)((u8 *)temp_r27 + 0x34) = temp_r28;
    *(s32 *)((u8 *)temp_r27 + 0x38) = temp_r28;
    *(void **)temp_r30 = lbl_80291914;
    *(s16 *)((u8 *)temp_r30 + 0x3C) = (s16)temp_r28;
    *(s16 *)((u8 *)temp_r30 + 0x3E) = (s16)temp_r28;
    *(s16 *)((u8 *)temp_r30 + 0x40) = (s16)temp_r28;
    *(s32 *)((u8 *)temp_r30 + 0x44) = temp_r31;
    *(s32 *)((u8 *)temp_r30 + 0x48) = temp_r28;
    *(void **)temp_r29 = gEmptyVtbl;
    *(s32 *)((u8 *)temp_r30 + 0x50) = temp_r28;
    if (temp_r31 == 0) flag = temp_r28;
    *(s32 *)((u8 *)temp_r29 + 8) = flag;
    b = 1; a = 0; f = lbl_8036A5DC;
    *(u8 *)((u8 *)temp_r29 + 0xC) = (u8)b;
    *(u8 *)((u8 *)temp_r29 + 0xD) = (u8)b;
    *(s16 *)((u8 *)temp_r29 + 0x14) = (s16)a;
    *(s16 *)((u8 *)temp_r29 + 0x16) = (s16)a;
    *(f32 *)((u8 *)temp_r29 + 0x18) = f;
    *(f32 *)((u8 *)temp_r29 + 0x1C) = f;
    *(u8 *)((u8 *)temp_r29 + 0x20) = 0xFF;
    *(u8 *)((u8 *)temp_r29 + 0x21) = 0xFF;
    *(u8 *)((u8 *)temp_r29 + 0x22) = 0xFF;
    *(u8 *)((u8 *)temp_r29 + 0x23) = 0xFF;
    *(f32 *)((u8 *)temp_r29 + 0x24) = lbl_8036A5E4;
    ((Sub *)temp_r29)->v1(a, b, f);
    *(void **)temp_r29 = lbl_802918E0;
    temp_r27 = (u8 *)temp_r30 + 0x74;
    *(u8 *)((u8 *)temp_r29 + 0xD) = 0;
    flag = 3;
    *(void **)temp_r27 = gEmptyVtbl;
    *(s32 *)((u8 *)temp_r30 + 0x78) = 0;
    if (temp_r31 == 0) flag = 1;
    *(s32 *)((u8 *)temp_r27 + 8) = flag;
    b = 1; a = 0; f = lbl_8036A5DC;
    *(u8 *)((u8 *)temp_r27 + 0xC) = (u8)b;
    *(u8 *)((u8 *)temp_r27 + 0xD) = (u8)b;
    *(s16 *)((u8 *)temp_r27 + 0x14) = (s16)a;
    *(s16 *)((u8 *)temp_r27 + 0x16) = (s16)a;
    *(f32 *)((u8 *)temp_r27 + 0x18) = f;
    *(f32 *)((u8 *)temp_r27 + 0x1C) = f;
    *(u8 *)((u8 *)temp_r27 + 0x20) = 0xFF;
    *(u8 *)((u8 *)temp_r27 + 0x21) = 0xFF;
    *(u8 *)((u8 *)temp_r27 + 0x22) = 0xFF;
    *(u8 *)((u8 *)temp_r27 + 0x23) = 0xFF;
    *(f32 *)((u8 *)temp_r27 + 0x24) = lbl_8036A5E4;
    ((Sub *)temp_r27)->v1(a, b, f);
    *(void **)temp_r27 = lbl_802918E0;
    *(u8 *)((u8 *)temp_r27 + 0xD) = 0;
    return temp_r30;
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" s32 fn_80136CD4(void *arg0) {
 s32 kind = *(s32 *)((u8 *)arg0 + 8);
 struct Obj {
 virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
 virtual s16 v4()=0; virtual s16 v5()=0;
 u8 pad[4]; s32 kind; u8 pad2[0xC]; f32 scale;
 };
 Obj *self=(Obj *)arg0;
 s16 v;
 switch(kind) {
 case 0: case 1: v=self->v5(); break;
 case 2: case 3: v=self->v4(); break;
 }
 return (s32)(self->scale * (f32)v);
}
#pragma cplusplus reset
s32 fn_80136D78(void) {
    return 0x10;
}

s32 fn_80136D80(void) {
    return 0x20;
}

#pragma cplusplus on
extern "C" void *fn_80136D88(void *arg0, s16 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    extern u8 lbl_802918E0[];
    extern u8 gEmptyVtbl[];
    extern void Heap_Free(void *);
    if (arg0 != NULL) {
        *(void **)arg0 = lbl_802918E0;
        if (arg0 != NULL) {
            *(void **)arg0 = gEmptyVtbl;
            ((Obj *)arg0)->v2();
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void *fn_80136E00(void *arg0, s16 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    extern u8 gEmptyVtbl[];
    extern void Heap_Free(void *);
    if (arg0 != NULL) {
        *(void **)arg0 = gEmptyVtbl;
        ((Obj *)arg0)->v2();
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}
#pragma cplusplus reset

s32 fn_80136E68(void) {
    return 1;
}

s32 fn_80136E70(void) {
    return 8;
}

s32 fn_80136E78(void) {
    return 0x10;
}

#pragma cplusplus on
extern "C" s32 fn_80136E80(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        u8 pad[4];
        s32 kind;
        u8 pad2[0xC];
        f32 scale;
    };
    s32 kind;
    s32 result;

    kind = *(s32 *)((u8 *)arg0 + 8);

    switch (kind) {
    case 0:
    case 1:
        result = ((Obj *)arg0)->v4();
        break;
    case 2:
    case 3:
        result = ((Obj *)arg0)->v5();
        break;
    default:
        break;
    }
    return (s32)(((Obj *)arg0)->scale * (f32)(s16)result);
}
#pragma cplusplus reset

s32 fn_80136F24(void) {
    return 6;
}

#pragma opt_strength_reduction off
void List_EraseRange(ListIter *ret, List *list, ListIter *start, ListIter *end)
{
  ListNode *first; ListNode *last; ListNode *a; ListNode *node;
  first = start->node;
  if (first == last) { ret->node = last; return; }
  a = last->prev; first->prev->next = a->next;
  last = end->node; a->next->prev = first->prev;
  while (start->node != end->node) {
    node = start->node; start->node = node->next; Heap_Free(node); list->size--;
  }
  ret->node = end->node;
}
#pragma opt_strength_reduction on
#pragma cplusplus on
extern "C" void fn_80136FDC(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    void fn_8008B464(s32, s32, s32);
    ((Obj *)arg0)->v2();
    fn_8008B464(*(s32 *)((char *)arg0 + 0x3C), 0, 0);
}
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_strength_reduction off
extern "C" void fn_80137024(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3(s32) = 0;
        u8 pad4[6];
        s16 unkA;
        s16 unkC;
        s16 unkE;
        s16 unk10;
        u8 pad12[0x22];
        u32 unk34;
        u8 pad38[4];
        s32 unk3C;
    };
    void fn_801546B0(s32, s32, s16, s16, s32, s16);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Unit_GetWpnExp(s32, u8);
    u8 *WpnRank_GetLetter(void);
    u8 Status_Test(void *, s32);
    void *Msg_Expand(void *);
    u8 fn_8005A310(void *, u8, s32);
    void fn_8001E5D0(u8, s32);
    s32 Text_MeasureHeight(s32, f32);
    void Ui_DrawIcon(void *, s16, s32, u8);
    void Prim2D_SetTex(s32, u16);
    void Text_Draw(s16, s16, s32, void *, ...);
    s8 Unit_GetMov(s32);
    s8 fn_8003A1E0(s32);
    s8 Unit_GetCon(s32);
    extern f32 lbl_8036A61C;
    extern f32 lbl_8036A620;
    extern s32 lbl_8036A608;
    extern s32 lbl_8036A60C;
    extern s32 lbl_8036A610;
    extern s32 lbl_8036A614;
    extern u8 lbl_802767E0[];
    extern u8 gUiIconDrawer[];
    s32 coords[4];
    s32 idx;
    u8 idx_u8;
    s32 unit;
    u32 flags;
    s32 slot;
    u8 *str;
    s32 slot_ext;
    s16 x;

    ((Obj *)arg0)->v2();
    fn_801546B0(0, 0, (s16)(((Obj *)arg0)->unkE - ((Obj *)arg0)->unkA), (s16)(((Obj *)arg0)->unk10 - ((Obj *)arg0)->unkC), 0x10, ((Obj *)arg0)->unkA);
    ((Obj *)arg0)->v3(arg1);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A61C);
    Prim2D_PrepareTex();
    slot = 0;
    idx = 0;
    do {
        coords[0] = lbl_8036A608;
        idx_u8 = (u8)idx;
        coords[1] = lbl_8036A60C;
        unit = ((Obj *)arg0)->unk3C;
        coords[2] = lbl_8036A610;
        coords[3] = lbl_8036A614;
        flags = ((Obj *)arg0)->unk34;
        Unit_GetWpnExp(unit, idx_u8);
        str = WpnRank_GetLetter();
        if ((s32)*str != 0x2D) {
            s16 *row;
            slot_ext = (s8)slot;
            row = (s16 *)coords;
            slot = ((s16 *)(coords + 2))[slot_ext];
            x = row[slot_ext];
            if ((s8)idx == 7) {
                if (Status_Test((u8 *)unit + 0x1BC, 0x23) != 0) {
                    unit = 0x53;
                    Msg_Expand(&lbl_802767E0[0x3B]);
                    goto after_icon;
                }
            }
            unit = (u8)fn_8005A310(gUiIconDrawer, idx_u8, 0);
            fn_8001E5D0(idx_u8, 0);
        after_icon:
            Ui_DrawIcon(gUiIconDrawer, x, ((s16)slot + ((Text_MeasureHeight(-1, lbl_8036A620) - 0x18) >> 1)), (u8)unit);
            Prim2D_Begin();
            Prim2D_SetTex(0, (u16)(flags | 3));
            Prim2D_PrepareTex();
            Text_Draw((s16)(x + 0x20), (s16)slot, 2, str);
            slot = (s8)(slot_ext + 1);
        }
        idx += 1;
    } while (idx < 8);
    Prim2D_Begin();
    Prim2D_SetTex(0, (u16)(((Obj *)arg0)->unk34 | 3));
    Prim2D_PrepareTex();
    Text_Draw(0xE0, 0x12, 2, lbl_802767E0 + 0x44, Unit_GetMov(((Obj *)arg0)->unk3C));
    Text_Draw(0xE0, 0x34, 2, lbl_802767E0 + 0x44, fn_8003A1E0(((Obj *)arg0)->unk3C));
    Text_Draw(0xE0, 0x54, 2, lbl_802767E0 + 0x44, Unit_GetCon(((Obj *)arg0)->unk3C));
}
#pragma pop
#pragma push
#pragma opt_lifetimes off
extern "C" void fn_8013729C(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3(s32) = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9(s16, s16, u8 *, s32, s32, s32) = 0;
        u8 pad4[6];
        s16 unkA;
        s16 unkC;
        s16 unkE;
        s16 unk10;
        s16 unk12;
        s16 unk14;
        s16 unk16;
        s16 unk18;
        u8 pad1A[0x34 - 0x1A];
        unsigned unk34;
        u8 pad38[4];
        s16 unk3C;
        s16 unk3E;
        s16 unk40;
        s16 unk42;
        void *unk44;
        u8 unk48;
    };
    void fn_80154370(s32, s32, s16, s16, s32, s32);
    void fn_8013F748(void *, s16 *, s16 *);
    void fn_8000A258(void);
    void fn_80009BC0(void (*)(void *), s16 *);
    void fn_80009C0C(f32);
    void fn_8000A174(s32, u16);
    void fn_8000A248(void);
    void fn_8013F920(void *);
    s32 fn_8003B658(void *);
    s32 fn_8003B2D0(void *);
    s32 fn_8003B258(void *);
    s32 fn_8003B614(void *);
    s32 fn_8003AFA0(void *);
    s32 fn_8003B5D0(void *);
    s32 fn_8003AF28(void *);
    s32 fn_8003B58C(void *);
    s32 fn_8003A398(void *);
    s32 fn_80038748(void *);
    s32 fn_8003AEB0(void *);
    s32 fn_8003B548(void *);
    s32 fn_8003ACF8(void *);
    s32 fn_8003B518(void *);
    s32 fn_8003AA40(void *);
    s32 fn_8003B4D4(void *);
    s32 fn_8003A778(void *);
    s32 fn_8003B490(void *);
    s32 fn_8003A5B4(void *);
    s32 fn_800388C8(void *);
    void *fn_8003A114(void *);
    void *fn_8007BA4C(void *, s32);
    void fn_8007B4D8(s16, s16, s32, void *);
    void fn_8007B990(void *);
    void fn_80009B98(void);
    extern f32 lbl_8036A61C;
    extern f32 lbl_8036A624;
    extern u8 lbl_802767E0[192];
    s16 h;
    s16 w;
    s16 *rect;
    Obj *self;
    unsigned long idx;
    void *unit;
    void *obj;
    s16 dw;
    s16 dh;
    register s32 lim;

    self = (Obj *)arg0;
    idx = arg1;
    self->v2();
    fn_80154370(0, 0, (s16)(self->unkE - self->unkA), (s16)(self->unk10 - self->unkC), 0xFF, 0x10);
    self->v3(idx);

    h = (s16)(self->unk18 - self->unk14);
    rect = &self->unk3C;
    w = (s16)(self->unk16 - self->unk12);
    self->unk3C = 0;
    self->unk3E = 0;
    self->unk40 = w;
    self->unk42 = h;
    fn_8013F748(self, rect, rect);
    rect = &self->unk40;
    fn_8013F748(self, rect, rect);

    fn_8000A258();
    fn_80009BC0(fn_8013F920, &self->unk3C);
    fn_80009C0C(lbl_8036A61C);
    fn_8000A174(0, (u16)(self->unk34 | 3));
    fn_8000A248();

    unit = self->unk44;
    self->v9(0xC, 0x22, lbl_802767E0 + 0x48, fn_8003B658(unit), fn_8003B2D0(unit),
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x4C]);
    self->v9(0xC, 0x42, lbl_802767E0 + 0x4E, fn_8003B614(unit), fn_8003B258(unit),
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x4D]);
    self->v9(0xC, 0x62, lbl_802767E0 + 0x55, fn_8003B5D0(unit), fn_8003AFA0(unit),
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x4E]);
    self->v9(0xC, 0x82, lbl_802767E0 + 0x5D, fn_8003B58C(unit), fn_8003AF28(unit),
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x4F]);
    self->v9(0xC, 0xA2, lbl_802767E0 + 0x65, (s8)(fn_8003A398(unit) - fn_80038748(unit)), fn_8003A398(unit), 0x14);
    self->v9(0x8C, 0x22, lbl_802767E0 + 0x6C, fn_8003B548(unit), fn_8003AEB0(unit),
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x50]);
    self->v9(0x8C, 0x42, lbl_802767E0 + 0x75, fn_8003B518(unit), fn_8003ACF8(unit), 0x28);
    self->v9(0x8C, 0x62, lbl_802767E0 + 0x7D, fn_8003B4D4(unit), fn_8003AA40(unit),
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x52]);
    self->v9(0x8C, 0x82, lbl_802767E0 + 0x84, fn_8003B490(unit), fn_8003A778(unit),
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x53]);
    self->v9(0x8C, 0xA2, lbl_802767E0 + 0x8C, (s8)(fn_8003A5B4(unit) - fn_800388C8(unit)), fn_8003A5B4(unit), 0x63);

    if (self->unk48 != 0) {
        fn_8000A258();
        fn_80009C0C(lbl_8036A624);
        fn_8000A248();
        obj = fn_8007BA4C(fn_8003A114(unit), 0x100);
        lim = 0x130;
        register int mid = (s16)(self->unkA + ((s16)(self->unkE - self->unkA) >> 1));
        *(u16 *)((u8 *)obj + 0x46) &= (u16)~1;
        *(u16 *)((u8 *)obj + 0x46) |= (u16)(lim > mid);
        dw = (s16)(self->unk16 - self->unk12);
        dh = (s16)(self->unk18 - self->unk14);
        fn_8007B4D8((s16)(dw >> 1), (s16)(dh + *(s16 *)((u8 *)*(void **)((u8 *)obj + 0x34) + 0x1E)), 0x7F, obj);
        fn_8007B990(obj);
    }

    fn_8000A258();
    fn_80009B98();
    fn_8000A248();
}
#pragma pop

#pragma cplusplus reset
#pragma use_lmw_stmw reset

extern f32 lbl_8036A620;
extern f32 lbl_8036A628;
extern f64 lbl_8036A630;
extern u8 lbl_802767E0[192];
extern void Prim2D_Begin(void);
extern s32 Prim2D_SetTex(s32, u16);
extern void Prim2D_PrepareTex(void);
extern void *Msg_Expand(s32);
extern s32 fn_8001003C(s16, s16, u8, u8, u8, void*, f32, f32, f32);
extern s32 fn_8007CCE8(s32, f32, f32);
void fn_801377BC(void *self,s16 x,s16 y,s32 message,s8 current,s8 maximum,s8 threshold) {
extern f32 lbl_8036A620,lbl_8036A628;
extern u8 lbl_802767E0[192];
void Prim2D_Begin(void);
s32 Prim2D_SetTex(s32,u16);
void Prim2D_PrepareTex(void);
void *Msg_Expand(s32);
s32 fn_8001003C(s16,s16,u8,u8,u8,void *,...);
s32 fn_8007CCE8(f32,f32,s32);
s32 color;
s32 sx;
s32 value;
Prim2D_Begin();
Prim2D_SetTex(0,*(u32*)((u8*)self+0x34)|3);
Prim2D_PrepareTex();
fn_8001003C(x,y,6,1,0,Msg_Expand(message),lbl_8036A620,lbl_8036A628);
color=0x22;
if(current<threshold)color=1;
sx=(s16)x;
fn_8001003C((s16)(sx+47),y,color,1,0,lbl_802767E0+0x44,lbl_8036A620,lbl_8036A628,(value=(s8)current));
fn_8007CCE8((f32)(sx+70),(f32)((s16)y+4),(s8)maximum-value);
}

void fn_801378E8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x44) = arg1;
}

void *fn_801378F0(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_802919DC[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_802919DC;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void fn_8013795C(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3(s32) = 0;
        virtual void v4() = 0;
        virtual void v6() = 0;
        virtual void v5() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9(s16, s16, u8 *, s32, s32, s32) = 0;
        u8 pad4[6];
        s16 unkA;
        s16 unkC;
        s16 unkE;
        s16 unk10;
        s16 unk12;
        s16 unk14;
        s16 unk16;
        s16 unk18;
        u8 pad1A[0x34 - 0x1A];
        unsigned int unk34;
        u8 pad38[4];
        s16 unk3C;
        s16 unk3E;
        s16 unk40;
        s16 unk42;
        void *unk44;
        u8 unk48;
    };
    void fn_80154370(s32, s32, s16, s16, s32, s32);
    void fn_8013F748(void *, s16 *, s16 *);
    void Prim2D_SetCallback(void (*)(void *), s16 *);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_ScissorFromRect(void *);
    s32 Unit_GetCarryWtLimit(void *);
    s32 Unit_GetStr(void *);
    s32 Unit_GetMagAtk(void *);
    s32 Unit_GetMag(void *);
    s32 fn_8003AF28(void *);
    s32 Unit_GetSkl(void *);
    s32 fn_8003AEB0(void *);
    s32 Unit_GetSpd(void *);
    s32 fn_8003ACF8(void *);
    s32 Unit_GetLck(void *);
    s32 fn_8003AA40(void *);
    s32 Unit_GetDef(void *);
    s32 fn_8003A778(void *);
    s32 Unit_GetRes(void *);
    void *fn_8003A114(void *);
    void fn_8007B4D8(s16, s16, s32, void *);
    void *Face_Create(void *, s32);
    void Face_ClearSlot(void *);
    void Prim2D_ClearCallbacks(void);
    extern f32 lbl_8036A61C;
    extern f32 lbl_8036A624;
    s16 h;
    extern u8 lbl_802767E0[192];
    s16 w;
    s16 *rect;
    Obj *self;
    int idx;
    register void *unit;
    void *obj;
    s16 mid;
    s16 dw;
    s16 dh;
    void *info;
    register s32 lim;

    self = (Obj *)arg0;
    idx = arg1;
    self->v2();
    fn_80154370(0, 0, (s16)(self->unkE - self->unkA), (s16)(self->unk10 - self->unkC), 0xFF, 0x10);
    self->v3(idx);

    h = (s16)(self->unk18 - self->unk14);
    rect = &self->unk3C;
    w = (s16)(self->unk16 - self->unk12);
    self->unk3C = 0;
    self->unk3E = 0;
    self->unk40 = w;
    self->unk42 = h;
    fn_8013F748(self, rect, rect);
    rect = &self->unk40;
    fn_8013F748(self, rect, rect);

    Prim2D_Begin();
    Prim2D_SetCallback(Prim2D_ScissorFromRect, &self->unk3C);
    Prim2D_AddZ(lbl_8036A61C);
    Prim2D_SetTex(0, (u16)(self->unk34 | 3));
    Prim2D_PrepareTex();

    unit = self->unk44;
    idx = Unit_GetCarryWtLimit(unit);
    self->v9(0xC, 0x29, lbl_802767E0 + 0x4E, Unit_GetStr(unit), idx,
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x4D]);
    idx = Unit_GetMagAtk(unit);
    self->v9(0xC, 0x48, lbl_802767E0 + 0x55, Unit_GetMag(unit), idx,
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x4E]);
    idx = fn_8003AF28(unit);
    self->v9(0xC, 0x67, lbl_802767E0 + 0x5D, Unit_GetSkl(unit), idx,
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x4F]);
    idx = fn_8003AEB0(unit);
    self->v9(0x8C, 0xA, lbl_802767E0 + 0x6C, Unit_GetSpd(unit), idx,
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x50]);
    idx = fn_8003ACF8(unit);
    self->v9(0x8C, 0x29, lbl_802767E0 + 0x75, Unit_GetLck(unit), idx, 0x28);
    idx = fn_8003AA40(unit);
    self->v9(0x8C, 0x48, lbl_802767E0 + 0x7D, Unit_GetDef(unit), idx,
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x52]);
    idx = fn_8003A778(unit);
    self->v9(0x8C, 0x67, lbl_802767E0 + 0x84, Unit_GetRes(unit), idx,
             (s8)(*(u8 **)((u8 *)unit + 0x18C))[0x53]);

    if (self->unk48 != 0) {
        s16 x0, x1, y0, y1, t;
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A624);
        Prim2D_PrepareTex();
        obj = Face_Create(fn_8003A114(unit), 0x100);
        lim = 0x130;
        register int mid = (s16)(self->unkA + ((s16)(self->unkE - self->unkA) >> 1));
        *(u16 *)((u8 *)obj + 0x46) &= (u16)~1;
        *(u16 *)((u8 *)obj + 0x46) = (u16)(lim > mid) | *(u16 *)((u8 *)obj + 0x46);
        x0 = self->unk12;
        x1 = self->unk16;
        info = *(void **)((u8 *)obj + 0x34);
        dw = (s16)(x1 - x0);
        y0 = self->unk14;
        y1 = self->unk18;
        t = *(s16 *)((u8 *)info + 0x1E);
        dh = (s16)(y1 - y0);
        fn_8007B4D8((s16)(dw >> 1), (s16)(dh + t), 0x7F, obj);
        Face_ClearSlot(obj);
    }

    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
}

#pragma cplusplus reset
#pragma peephole off
void fn_80137D74(void *self,s16 x,s16 y,s32 message,s8 current,s8 maximum,s8 threshold) {
extern f32 lbl_8036A620,lbl_8036A628;
extern u8 lbl_802767E0[192];
void Prim2D_Begin(void);
s32 Prim2D_SetTex(s32,u16);
void Prim2D_PrepareTex(void);
void *Msg_Expand(s32);
s32 fn_8001003C(s16,s16,u8,u8,u8,void *,...);
s32 fn_8007CCE8(f32,f32,s32);
s32 color;
s32 sx;
s32 value;
Prim2D_Begin();
Prim2D_SetTex(0,*(u32*)((u8*)self+0x34)|3);
Prim2D_PrepareTex();
fn_8001003C(x,y,6,1,0,Msg_Expand(message),lbl_8036A620,lbl_8036A628);
color=0x22;
if(current<threshold)color=1;
sx=(s16)x;
fn_8001003C((s16)(sx+47),y,color,1,0,lbl_802767E0+0x44,lbl_8036A620,lbl_8036A628,(value=(s8)current));
fn_8007CCE8((f32)(sx+70),(f32)((s16)y+4),(s8)maximum-value);
}
#pragma peephole on
void fn_80137EA0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x44) = arg1;
}

void *fn_80137EA8(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_80291A0C[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80291A0C;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma use_lmw_stmw on
#pragma push
#pragma cplusplus on
#pragma optimization_level 2
#pragma opt_common_subs off
extern "C" void fn_80137F14(PortraitPanelObject *self, s32 arg1) {
    void fn_80160F00(s32, s32, s32, s32);
    void fn_8013F748(void *, s16 *, s16 *);
    void Prim2D_Begin(void);
    void Prim2D_SetCallback(void (*)(void *), s16 *);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_ScissorFromRect(void *);
    void Text_Draw(s32, s32, s32, void *, ...);
    s32 fn_8001059C(void *, s32, f32);
    void *Msg_Expand(void *);
    s32 Text_MeasureWidth(void *, s32, f32);
    void *Msg_ResolveName(void *);
    void *fn_800A8978(void *);
    u8 fn_800386B0(void *);
    s8 Unit_GetMaxHp(void *);
    u16 Unit_GetSkillCapacityUsed(void *);
    void fn_8004BD1C(void *, f32 *, f32);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXConcat(void *, void *, void *);
    void fn_802025E8(void *, void *, f32, f32, f32);
    void fn_80202574(void *, void *, f32, f32, f32);
    f32 fn_80138AC0(void *);
    s32 fn_80138908(void *);
    void Model_SetColor(void *, u8, u8, u8);
    void Model_SetAlpha(void *, s32);
    void fn_8005F780(void *, s32);
    void fn_80060060(void *);
    void fn_800609DC(void *);
    void fn_8004DDB8(s32);
    void Prim2D_SetColorByte(void);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_AddPrim(s32);
    void fn_80007340(void *, void *);
    void Prim2D_EndPrim(void);
    extern void fn_80069F04;
    extern void fn_801388D4;
    extern f32 lbl_8036A61C;
    extern f32 lbl_8036A620;
    extern f32 lbl_8036A628;
    extern f32 lbl_8036A638;
    extern f32 lbl_8036A63C;
    extern f32 lbl_8036A640;
    extern f32 lbl_8036A644;
    extern f32 lbl_8036A648;
    extern f32 lbl_8036A64C;
    extern f32 lbl_8036A650;
    extern f32 lbl_8036A654;
    extern f32 lbl_8036A658;
    extern f32 lbl_8036A65C;
    extern f32 lbl_8036A660;
    extern u8 lbl_802767E0[192];

    s32 idx;
    void *unit;
    s16 *rect;
    s16 w, h;
    f32 fy, fx, fgap;
    void *str;
    s32 tw;
    s32 flags;
    f32 sp2C[3];
    u8 sp68[0x30];
    u8 sp38[0x30];

    idx = arg1;
    self->v2();
    fn_80160F00(0, 0, self->unk4C == 0 ? 1 : 0, 0x10);
    self->v3(idx);

    unit = self->unk3C;
    h = (s16)(self->unk18 - self->unk14);
    w = (s16)(self->unk16 - self->unk12);
    self->unk44 = 0;
    self->unk46 = 0;
    self->unk48 = w;
    self->unk4A = h;
    fn_8013F748(self, &self->unk44, &self->unk44);
    rect = &self->unk48;
    fn_8013F748(self, rect, rect);

    Prim2D_Begin();
    Prim2D_SetCallback(Prim2D_ScissorFromRect, &self->unk44);
    Prim2D_AddZ(lbl_8036A61C);
    Prim2D_SetTex(0, (u16)(self->unk34 | 3));
    Prim2D_PrepareTex();

    fy = (self->unk4C == 0) ? lbl_8036A638 : lbl_8036A63C;
    fx = lbl_8036A628;
    fgap = (f32)fn_8001059C(lbl_802767E0 + 0x95, -1, lbl_8036A620);

    if (self->unk40 & 2) {
        Text_Draw((s32)fy, (s32)lbl_8036A628, 2, Msg_ResolveName(*(void **)((u8 *)unit + 0x188)));
        fx += lbl_8036A640;
    }
    if (self->unk40 & 4) {
        Text_Draw((s32)fy, (s32)fx, 2, fn_800A8978(*(void **)((u8 *)unit + 0x18C)));
        fx += lbl_8036A640;
    }
    if (self->unk40 & 8) {
        str = Msg_Expand(lbl_802767E0 + 0x97);
        tw = Text_MeasureWidth(str, -1, lbl_8036A620);
        Text_Draw((s32)fy, (s32)fx, 0xF, str);
        fy = fy + ((f32)tw + fgap);
        Text_Draw((s32)fy, (s32)fx, 2, lbl_802767E0 + 0x44, *(s8 *)((u8 *)unit + 0x19A));
        fy += lbl_8036A644;
    }
    if (self->unk40 & 0x10) {
        str = Msg_Expand(lbl_802767E0 + 0x9E);
        tw = Text_MeasureWidth(str, -1, lbl_8036A620);
        Text_Draw((s32)fy, (s32)fx, 0xF, str);
        fy = fy + ((f32)tw + fgap);
        if (fn_800386B0(unit) != 0xFF) {
            Text_Draw((s32)fy, (s32)fx, 2, lbl_802767E0 + 0x44, (u8)fn_800386B0(unit));
        } else {
            Text_Draw((s32)fy, (s32)fx, 2, lbl_802767E0 + 0xA5);
        }
        fy += lbl_8036A644;
    }

    flags = (s32)self->unk40;
    if (flags & 0x18) {
        fy = (self->unk4C == 0) ? lbl_8036A638 : lbl_8036A63C;
        fx += lbl_8036A640;
    }
    if (flags & 0x20) {
        str = Msg_Expand(lbl_802767E0 + 0xAA);
        tw = Text_MeasureWidth(str, -1, lbl_8036A620);
        Text_Draw((s32)fy, (s32)fx, 0xF, str);
        fy = fy + ((f32)tw + fgap);
        Text_Draw((s32)fy, (s32)fx, 2, lbl_802767E0 + 0x44, *(s8 *)((u8 *)unit + 0x1A8));
        Text_Draw((s32)(lbl_8036A640 + fy), (s32)fx, 0xC, lbl_802767E0 + 0xB1, Unit_GetMaxHp(unit));
        fy += lbl_8036A648;
    }
    if (self->unk40 & 0x40) {
        str = Msg_Expand(lbl_802767E0 + 0xB6);
        tw = Text_MeasureWidth(str, -1, lbl_8036A620);
        Text_Draw((s32)fy, (s32)fx, 0xF, str);
        fy = fy + ((f32)tw + fgap);
        Text_Draw((s32)fy, (s32)fx, 2, lbl_802767E0 + 0x44, (u16)Unit_GetSkillCapacityUsed(unit));
        Text_Draw((s32)(lbl_8036A64C + fy), (s32)fx, 0xC, lbl_802767E0 + 0xB1,
                    (*(u8 **)((u8 *)unit + 0x18C))[0x40]);
    }

    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();

    if (self->unk40 & 0x10000) {
        s32 xoff;
        s32 c8, c4, c0;
        s32 *pr, *pg, *pb;
        f32 a;

        if (self->unk4C == 0) {
            xoff = (s16)(self->unk16 - self->unk12) - 0x38;
        } else {
            xoff = 0x38;
        }
        fgap = (f32)xoff;
        fx = (f32)(s16)(self->unk18 - self->unk14);
        fgap += (f32)self->unkA;
        fx += (f32)self->unkC;
        fn_8004BD1C(unit, sp2C, lbl_8036A650);
        fx += sp2C[1];
        fgap += sp2C[0];
        fx += lbl_8036A654;
        PSMTXRotRad(sp38, 0x79, lbl_8036A658);
        PSMTXRotRad(sp68, 0x78, lbl_8036A65C);
        PSMTXConcat(sp68, sp38, sp68);
        fn_802025E8(sp68, sp68, lbl_8036A650, lbl_8036A650, lbl_8036A650);
        fn_80202574(sp68, self->unk50 + 0x10, fgap, fx, (f32)self->unk22);
        a = fn_80138AC0(self);
        c0 = (s32)(lbl_8036A660 * a);
        u8 red, green, blue;
        {
            s32 value, low, high;
            high = 255; low = 0; value = c0;
            s32 *p = value > low ? &value : &low;
            red = *(*p < high ? p : &high);
        }
        {
            s32 value, low, high;
            high = 255; low = 0; value = c0;
            s32 *p = value > low ? &value : &low;
            green = *(*p < high ? p : &high);
        }
        {
            s32 value, low, high;
            high = 255; low = 0; value = c0;
            s32 *p = value > low ? &value : &low;
            blue = *(*p < high ? p : &high);
        }
        Model_SetColor(self->unk50, red, green, blue);
        Model_SetAlpha(self->unk50, fn_80138908(self));
        fn_8005F780(self->unk50, 0xFF);
        fn_80060060(self->unk50);
        fn_800609DC(self->unk50);
        fn_8004DDB8(self->unk22 - 2);
        Prim2D_Begin();
        Prim2D_SetTex(0, (u16)(self->unk34 | 0x400));
        Prim2D_AddZ(lbl_8036A620);
        fn_80138908(self);
        Prim2D_SetColorByte();
        Prim2D_PrepareTex();
        Prim2D_AddPrim(0xB);
        fn_80007340(&fn_80069F04, self->unk50);
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A620);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(0xB);
        fn_80007340(&fn_801388D4, (void *)0);
        Prim2D_EndPrim();
    }
}
#pragma pop
#pragma cplusplus reset

void Ui_SetPortraitUnit(void *arg0, s32 arg1) {
    void fn_800506E0(void *, s32, void *);
    void GActor_Finalize(void *);
    void fn_800616A0(void *);
    void *GActor_Create(void);
    s32 fn_800639B4(void);

    void *tmp;
    s32 saved;

    *(s32 *)((u8 *)arg0 + 0x3C) = arg1;
    saved = *(s32 *)((u8 *)arg0 + 0x3C);
    tmp = *(void **)((u8 *)arg0 + 0x50);
    if (tmp != NULL) {
        fn_800616A0(tmp);
    }
    *(void **)((u8 *)arg0 + 0x50) = GActor_Create();
    tmp = *(void **)((u8 *)arg0 + 0x50);
    *(s32 *)((u8 *)tmp + 4) = saved + 0x1C;
    tmp = *(void **)((u8 *)arg0 + 0x50);
    *(u32 *)tmp = *(u32 *)tmp | 0x50028400;
    fn_800506E0((void *)saved, 0, tmp);
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 0x44) = fn_800639B4();
    GActor_Finalize(*(void **)((u8 *)arg0 + 0x50));
}

void fn_80138898(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) (M2C_FIELD(arg0, s16 *, 0xA) + 0x108);
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) (M2C_FIELD(arg0, s16 *, 0xC) + 0x55);
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 7;
    M2C_FIELD(arg0, s16 *, 0x16) = 0x108;
    M2C_FIELD(arg0, s16 *, 0x18) = 0x4F;
}

void fn_801388D4(void) {
    M2C_UNK fn_80059C2C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    fn_80059C2C(0, 0, 0x260, 0x1C0, 0);
}

s32 fn_80138908(void) {
    f32 Ui_GetWorldScale();
    extern f32 lbl_8036A618;
    return (s32) (lbl_8036A618 * Ui_GetWorldScale());
}

extern s32 fn_80138AB8(void *);
f32 Ui_GetWorldScale(void *arg0) {
#pragma cplusplus on
 struct Node { u8 pad[0x2C]; f32 scale; u8 pad30[8]; Node *parent; Node *getParent() { return parent; } };
 Node *node = (Node *)arg0;
 f32 scale = node->scale;
 if (node->getParent() != NULL) scale *= Ui_GetWorldScale(node->getParent());
 return scale;
#pragma cplusplus reset
}

#pragma dont_inline on
s32 fn_80138AB8(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x38);
}
#pragma dont_inline reset

f32 fn_80138AC0(void *arg0) {
#pragma cplusplus on
 struct Node { u8 pad[0x30]; f32 scale; u8 pad34[4]; Node *parent; Node *getParent() { return parent; } };
 Node *node = (Node *)arg0;
 f32 scale = node->scale;
 if (node->getParent() != NULL) scale *= fn_80138AC0(node->getParent());
 return scale;
#pragma cplusplus reset
}

void *fn_80138C3C(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_80291988[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80291988;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void *fn_80138CA8(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_802919B0[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_802919B0;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_80138D14(void *arg0) {
    s16 h = M2C_FIELD(arg0, s16 *, 0x10) - M2C_FIELD(arg0, s16 *, 0xc);
    s16 w = M2C_FIELD(arg0, s16 *, 0xe) - M2C_FIELD(arg0, s16 *, 0xa);

    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    M2C_FIELD(arg0, s16 *, 0x16) = w;
    M2C_FIELD(arg0, s16 *, 0x18) = h;
}

void fn_80138D44(void *arg0) {
    s16 height, width;
    s32 bottom, right;
    s16 *p = (s16 *)arg0;
    height = p[0x10 / 2] - p[0xC / 2];
    width = p[0xE / 2] - p[0xA / 2];
    bottom = height - 5;
    right = width - 3;
    p[0x12 / 2] = 3;
    p[0x14 / 2] = 5;
    p[0x16 / 2] = right;
    p[0x18 / 2] = bottom;
}

void fn_80138D88(void *arg0) {
    s16 height, width;
    s32 bottom, right;
    s16 *p = (s16 *)arg0;
    height = p[0x10 / 2] - p[0xC / 2];
    width = p[0xE / 2] - p[0xA / 2];
    bottom = height - 5;
    right = width - 3;
    p[0x12 / 2] = 3;
    p[0x14 / 2] = 5;
    p[0x16 / 2] = right;
    p[0x18 / 2] = bottom;
}

void *fn_80138DCC(void *arg0, s16 arg1) {
    void fn_800616A0(void *);
    M2C_UNK Heap_Free(void *);
    extern u16 lbl_8028FDB0[];
    extern u8 lbl_80291A3C[];
    extern u16 lbl_80292230[];

    if (arg0 != NULL) {
        M2C_FIELD(arg0, void **, 0) = lbl_80291A3C;
        if (M2C_FIELD(arg0, void **, 0x50) != NULL) {
            fn_800616A0(M2C_FIELD(arg0, void **, 0x50));
        }
        if (arg0 != NULL) {
            M2C_FIELD(arg0, void **, 0) = lbl_80292230;
            if (arg0 != NULL) {
                M2C_FIELD(arg0, void **, 0) = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
#pragma opt_strength_reduction off
extern "C" void fn_80138E58(void *self, void *other) {
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
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual s32 v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16(s16, s16, s32, s16, u8) = 0;
        virtual void v17() = 0;
        virtual void v18(void *) = 0;
    };
    void *fn_80009E44(void *);
    void fn_80202574(void *, void *, f32, f32, f32);
    void fn_8000A258(void);
    void fn_80009C0C(f32);
    void fn_8000A248(void);
    s32 fn_800102BC(s32, f32);
    void fn_8008BF68(s16, s32, u8);
    void fn_80009B98(void);
    void fn_80009B80(s32);
    extern f32 lbl_8036A668;
    extern f32 lbl_8036A66C;
    extern f32 lbl_8036A670;
    extern f32 lbl_8036A674;
    extern f32 lbl_8036A678;
    s16 t5a;
    u8 r30;
    s32 r29;
    s16 r28;
    s16 r27;
    s16 t24;
    u8 flag;
    void *ptr;
    u8 sp8[8];
    void *tmp;

    ((Obj *)self)->v3();
    tmp = fn_80009E44(sp8);
    fn_80202574(tmp, tmp, lbl_8036A668, lbl_8036A668, lbl_8036A66C);
    r29 = ((Obj *)self)->v11();
    {
        s16 t4e = *(s16 *)((u8 *)self + 0x4E);
        s16 t58 = *(s16 *)((u8 *)self + 0x58);
        s16 t62 = *(s16 *)((u8 *)self + 0x62);
        s32 quot = t4e / t58;
        s16 t52 = *(s16 *)((u8 *)self + 0x52);
        s32 t62m = t62 - 0x20;
        s16 t56 = *(s16 *)((u8 *)self + 0x56);
        t5a = *(s16 *)((u8 *)self + 0x5A);
        s16 t64 = *(s16 *)((u8 *)self + 0x64);
        r28 = (s16)((r29 * (s16)(t4e - quot * t58)) + t62m);
        r27 = (s16)((t5a * (s16)((s16)quot - t56)) + t64);
        if (t52 < 0 || *(s16 *)((u8 *)self + 0x54) < 0) {
            *(s16 *)((u8 *)self + 0x52) = r28;
            *(s16 *)((u8 *)self + 0x54) = r27;
        } else {
            *(s16 *)((u8 *)self + 0x52) = (t52 + r28 + 1) >> 1;
            *(s16 *)((u8 *)self + 0x54) = (*(s16 *)((u8 *)self + 0x54) + r27 + 1) >> 1;
        }
    }
    if (*(u8 *)((u8 *)self + 0x4C) != 0 && *(u32 *)((u8 *)self + 0x70) != 0) {
        u8 b1 = *(u8 *)((u8 *)other + 0x2D);
        r30 = 0;
        flag = r30;
        if (b1 == 0) {
            if (*(u8 *)((u8 *)other + 0x2E) == 0) {
                flag = 1;
            }
        }
        if (flag) {
            if (*(u32 *)((u8 *)other + 0x34) != 0) {
                ptr = (*(void ***)((u8 *)other + 0x38))[2];
            } else {
                ptr = 0;
            }
            if (ptr == self) {
                r30 = 1;
            }
        }
        fn_8000A258();
        fn_80009C0C(lbl_8036A670);
        fn_8000A248();
        t24 = *(s16 *)((u8 *)self + 0x5A);
        {
            s32 h = fn_800102BC(-1, lbl_8036A674);
            s16 xpos = *(s16 *)((u8 *)self + 0x52);
            h = ((s32)(s16)t24 - h) >> 1;
            s16 ypos = *(s16 *)((u8 *)self + 0x54);
            fn_8008BF68((s16)(xpos + 0x20), ypos + h, r30);
        }
        fn_8000A258();
        fn_80009C0C(lbl_8036A678);
        fn_8000A248();
        ((Obj *)self)->v16((s16)((r28 - *(s16 *)((u8 *)self + 0x62)) + 0x20), r27, r29, t5a, r30);
    }
    ((Obj *)self)->v18(other);
    fn_8000A258();
    fn_80009B98();
    fn_80009B80(0x80);
    fn_8000A248();
}
#pragma pop
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma opt_lifetimes off
extern "C" void fn_80139084(void *arg0, s32 arg1) {
    struct Node;
    struct Obj {
        virtual void v0()=0; virtual void v1()=0; virtual void v2()=0;
        virtual void v3(s32)=0; virtual void v4()=0; virtual void v5()=0;
        virtual void v6()=0; virtual void v7()=0; virtual void v8()=0;
        virtual void v9()=0; virtual void v10()=0;
        virtual s32 v11()=0;
        virtual void v12()=0;
        virtual s32 v13()=0;
        virtual u8 v14(void *)=0;
        virtual void v15()=0; virtual void v16()=0; virtual void v17()=0;
        u8 pad4[6];
        s16 unkA, unkC;
        u8 padE[0x12-0xE];
        s16 a12, a14, a16, a18;
        u8 pad1a[0x22-0x1A];
        s16 a22;
        u8 pad24[0x56-0x24];
        s16 a56, a58, a5a;
        f32 a5c;
        s16 a60, a62, a64;
        s16 rect[4];
        u32 a70;
        u8 pad74[4];
        Node *list;
    };
    struct Node { Node *prev; Node *next; void *obj; void *spr; };
    void fn_8013A5A0(void *, s32);
    void fn_8013F748(void *, s16 *, s16 *);
    void fn_80202300(void *, s32, f32);
    void fn_80202024(void *, void *, void *);
    void fn_802025E8(void *, void *, f32, f32, f32);
    void fn_80202574(void *, void *, f32, f32, f32);
    void fn_8000A258(void);
    void fn_8000A248(void);
    void fn_80009D74(f32, f32, f32, f32);
    void fn_8000A174(s32, s32);
    void fn_80009B8C(s32);
    void fn_80009BC0(void (*)(void *), s16 *);
    void fn_8013F920(void *);
    void fn_80007898(s32);
    void fn_80007340(void *, s32);
    void fn_80007884(void);
    void fn_80009C0C(f32);
    void fn_8004BD1C(void *, f32 *, f32);
    void fn_8005F7E0(void *, s32, s32, s32);
    void fn_8005F7B0(void *, s32);
    void fn_8005F780(void *, s32);
    void fn_80060060(void *);
    void fn_800609DC(void *);
    void fn_8004DDB8(s32);
    void fn_80009B98(void);
    extern const f32 lbl_8036A67C, lbl_8036A680, lbl_8036A684;
    extern const f32 lbl_8036A668, lbl_8036A688, lbl_8036A674, lbl_8036A68C;
    extern void fn_80069F04;
    extern void fn_8013B120;
    u8 sp4C[0x30];
    u8 sp1C[0x30];
    f32 sp10[3];
    s32 spC;
    s32 sp8;
    s16 s14, s16v, s18;
    s32 index, width, scroll, n, row, col;
    s16 rows, row_h, endrow;
    s32 sign;
    s16 y, x, t;
    s16 *rect;
    s16 w, h;
    s32 visible, ypos, xpos, arg;
    Node *node;
    void *spr;
    f32 fx, fy, baseX, baseY;
    Obj *self;

    self = (Obj *)arg0;
    arg = arg1;
    sp8 = *(s32 *)((u8 *)self + 0x12);
    spC = *(s32 *)((u8 *)self + 0x16);
    s14 = *((s16 *)&sp8 + 1);
    s16v = *(s16 *)&spC;
    s18 = *((s16 *)&spC + 1);
    self->a12 = (s16)(*(s16 *)&sp8 + 0x20);
    self->a14 = s14;
    self->a16 = s16v;
    self->a18 = s18;
    fn_8013A5A0(self, arg);
    self->a12 = *(s16 *)&sp8;
    self->a14 = s14;
    self->a16 = s16v;
    self->a18 = s18;
    self->v3(arg);

    h = (s16)(self->a18 - self->a14);
    rect = self->rect;
    w = (s16)(self->a16 - self->a12);
    rect[0] = 0; rect[1] = 0; rect[2] = w; rect[3] = h;
    fn_8013F748(self, rect, rect);
    rect = self->rect + 2;
    fn_8013F748(self, rect, rect);

    rows = self->a58;
    visible = self->v13();
    {
        s16 page0 = self->a56;
        index = (s16)(page0 * self->a58);
    }
    width = self->v11();
    scroll = (s32)self->a5c;
    row_h = self->a5a;
    if ((s16)scroll < 0) {
        sign = -1;
    } else {
        t = scroll;
        sign = (s16)((-(u32)(s32)t & ~(u32)(s32)t) >> 31);
    }
    if ((s16)sign > 0 && index - (s16)rows >= 0) {
        index = index - rows;
    }
    node = self->list;
    n = index;
    if ((s16)index >= 0) {
        while ((s16)n > 0) { node = node->next; n--; }
    } else {
        while ((s16)n < 0) { node = node->prev; n++; }
    }

    fn_80202300(sp1C, 0x79, lbl_8036A67C);
    fn_80202300(sp4C, 0x78, lbl_8036A680);
    fn_80202024(sp4C, sp1C, sp4C);
    fn_802025E8(sp4C, sp4C, lbl_8036A684, lbl_8036A684, lbl_8036A684);
    fn_8000A258();
    fn_80009D74(lbl_8036A668, lbl_8036A668, lbl_8036A688 + (f32)self->a22, lbl_8036A674);
    fn_8000A174(0, 0x410);
    fn_80009B8C(0xFF);
    if ((s16)self->a5c != 0) {
        fn_80009BC0(fn_8013F920, self->rect);
    }
    fn_8000A248();
    fn_80007898(0xB);
    fn_80007340(&fn_8013B120, 0);
    fn_80007884();
    fn_8000A258();
    fn_80009C0C(lbl_8036A68C);
    fn_8000A248();

    endrow = (s16)visible;
    row = (-(s32)sign & ~(s32)sign) >> 31;
    row = (s16)row;
    if (sign < 0) {
        endrow = (s16)(endrow + 1);
    }
    ypos = (s32)(s16)row * (s32)row_h;
    for (; (s16)row < (s16)endrow; ypos += row_h, row++) {
        col = 0;
        xpos = 0;
        y = (s16)((s16)scroll + ypos + self->a64 + self->a5a);
        while ((s16)col < (s16)rows) {
            if ((u32)(s16)index >= self->a70) goto done;
            x = (s16)(xpos + (self->a62 + 0x10));
            baseX = (f32)(x + self->unkA);
            baseY = (f32)(y + self->unkC);
            spr = node->spr;
            fn_8004BD1C(node->obj, sp10, lbl_8036A684);
            baseX += sp10[0];
            baseY += sp10[1];
            fn_80202574(sp4C, (u8 *)spr + 0x10, baseX, baseY, (f32)self->a22);
            if (self->v14(node->obj) != 0) {
                fn_8005F7E0(spr, 0x80, 0x80, 0x80);
            } else {
                fn_8005F7E0(spr, 0x40, 0x40, 0x40);
            }
            fn_8005F7B0(spr, 0xFF);
            fn_8005F780(spr, 0xFF);
            fn_80060060(spr);
            fn_800609DC(spr);
            fn_80007898(0xB);
            fn_80007340(&fn_80069F04, (s32)spr);
            fn_80007884();
            node = node->next;
            xpos += (s16)width;
            col++;
            index++;
        }
    }
done:
    fn_8004DDB8(self->a22 - 1);
    fn_8000A258();
    fn_80009B98();
    fn_8000A248();
}
#pragma pop
#pragma push
#pragma optimization_level 4
#pragma opt_lifetimes off
extern "C" void fn_80139538(void *arg0, s32 arg1) {
 void fn_80139E88(void *,s32);
 void Ui_PlaySeCue(void *,s32);
 extern u32 gUiInputFlags;
 extern u32 *gPadInput;
 extern u8 lbl_802768A0[];
 s32 visible, row; s16 page, old, total; s32 pages;
 struct Menu { virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0; virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0; virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void v11()=0; virtual void v12()=0; virtual s32 count()=0; };
 s32 size, held, edge, repeat;
 u8 blocked;
 visible=((Menu *)arg0)->count();
 size=M2C_FIELD(arg0,s16 *,0x58);
 total=M2C_FIELD(arg0,s32 *,0x70);
 pages=size+total; pages=(s16)((pages-1)/size);
 if((s16)visible>pages) visible=pages;
 row=M2C_FIELD(arg0,s16 *,0x4E);
 blocked=0;
 page=row/size;
 if((gUiInputFlags&0x10)&&!(gUiInputFlags&0x20)) blocked=1;
 if(!blocked) {
 held=gPadInput[1]; edge=(s32)gPadInput[2]^held; repeat=gPadInput[3]; edge=held&edge;
 struct State { u8 pad[0x4E]; s16 selection; }; old=((State *)arg0)->selection;
 if((s16)row==0x7FFF) {
 s32 last=(pages-1)*size;
 if(edge&0x08000008) M2C_FIELD(arg0,s16 *,0x4E)=last;
 else if(edge&0x04000004) {M2C_FIELD(arg0,s16 *,0x4E)=0;M2C_FIELD(arg0,s16 *,0x56)=0;}
 goto changed;
 }
 if(page==pages-1&&(repeat&0x04000004)) {M2C_FIELD(arg0,s16 *,0x4E)=0x7FFF;goto changed;}
 if(page==0&&(edge&0x08000008)) {M2C_FIELD(arg0,s16 *,0x56)=pages-visible;M2C_FIELD(arg0,s16 *,0x4E)=0x7FFF;goto changed;}
 }
 fn_80139E88(arg0,arg1); return;
changed:
 if(old!=M2C_FIELD(arg0,s16 *,0x4E)) Ui_PlaySeCue(lbl_802768A0+0x1D,100);
}
#pragma optimization_level 2
#pragma opt_propagation off
extern "C" void fn_801396C4(void *self, void *other) {
    struct Obj {
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
        virtual s32 v11()=0;
        virtual void v12()=0;
        virtual void v13()=0;
        virtual void v14()=0;
        virtual void v15()=0;
        virtual void v16(s16,s32,s32,s16,u8)=0;
    };
    void fn_8013A39C(void *,void *);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetAlphaByte(s32);
    s32 Text_MeasureHeight(s32,f32);
    void Ui_DrawRouteIconEx(s16,s32,u8);
    extern f32 lbl_8036A670,lbl_8036A674,lbl_8036A678;
    s16 x;
    s16 height;
    s32 y;
    u8 active;
    s32 width;
    s32 old;
    if(M2C_FIELD(self,s16 *,0x4E)!=0x7FFF) {fn_8013A39C(self,other);return;}
    ((Obj *)self)->v3();
    width=((Obj *)self)->v11();
    old=M2C_FIELD(self,s16 *,0x52);
    height=M2C_FIELD(self,s16 *,0x5A);
    x=M2C_FIELD(self,s16 *,0x62);
    y=(s16)(M2C_FIELD(self,s16 *,0x18)-M2C_FIELD(self,s16 *,0x14));
    if((s16)old<0 || M2C_FIELD(self,s16 *,0x54)<0) {
        M2C_FIELD(self,s16 *,0x52)=x;
        M2C_FIELD(self,s16 *,0x54)=y;
    } else {
        s32 x1 = x + 1;
        s32 y1 = y + 1;
        M2C_FIELD(self,s16 *,0x52)=(old+x1)>>1;
        M2C_FIELD(self,s16 *,0x54)=(M2C_FIELD(self,s16 *,0x54)+y1)>>1;
    }
    if(M2C_FIELD(self,u8 *,0x4C)) {
        u8 flag;
        void *ptr;
        s16 h;
        active=0;
        flag=active;
        if(!M2C_FIELD(other,u8 *,0x2D)&&!M2C_FIELD(other,u8 *,0x2E))flag=1;
        if(flag) {
            ptr=M2C_FIELD(other,u32 *,0x34)?M2C_FIELD(M2C_FIELD(other,void **,0x38),void **,8):0;
            if(ptr==self)active=1;
        }
        Prim2D_Begin();Prim2D_AddZ(lbl_8036A670);Prim2D_PrepareTex();
        h=M2C_FIELD(self,s16 *,0x5A);
        Ui_DrawRouteIconEx(M2C_FIELD(self,s16 *,0x52),M2C_FIELD(self,s16 *,0x54)+(s16)((h-Text_MeasureHeight(-1,lbl_8036A674))>>1),active);
        Prim2D_Begin();Prim2D_AddZ(lbl_8036A678);Prim2D_PrepareTex();
        ((Obj *)self)->v16((s16)(x-M2C_FIELD(self,s16 *,0x62)),y,width,height,active);
    }
    Prim2D_Begin();Prim2D_SetAlphaByte(0x80);Prim2D_PrepareTex();
}
#pragma opt_propagation reset
#pragma optimization_level reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" void Prim2D_AddZ(f32);
extern "C" void Text_Draw(s16, s16, u8, char *, ...);
extern "C" s32 Text_MeasureHeight(s32, f32);
extern "C" s32 Convoy_FindEmpty(void *);
extern "C" u8 fn_8014D8DC(void *);
extern "C" void fn_80155F20(s32, s32, s16, s16, s32, s32);
extern "C" void Ui_DrawLine(s16, s16, s16, s16, s32, u8 *);
extern "C" void fn_80139884(void *arg0, s32 arg1)
{
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3(s32) = 0;
        s16 GetLineHeight() {
            return M2C_FIELD(this, s16 *, 0x5A);
        }
    };

    extern u8 lbl_802768A0[];
    extern u8 gConvoy[];
    extern u8 gBattleState[];
    extern f32 lbl_8036A674;
    extern f32 lbl_8036A6A0;

    u8 color[4];
    s16 width;
    s16 margin;
    s16 height;
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;
    s32 lineHeight;
    s32 measured;
    s32 difference;
    u8 flag;
    s16 y;
    s16 drawY;
    s32 shadow;
    char *expanded;

    ((Obj *)arg0)->v2();

    fn_80155F20(
        0,
        0,
        (s16)(M2C_FIELD(arg0, s16 *, 0xE) -
              M2C_FIELD(arg0, s16 *, 0xA)),
        (s16)(M2C_FIELD(arg0, s16 *, 0x10) -
              M2C_FIELD(arg0, s16 *, 0xC)),
        0xFF,
        0x10
    );

    ((Obj *)arg0)->v3(arg1);

    left = M2C_FIELD(arg0, s16 *, 0x12);
    right = M2C_FIELD(arg0, s16 *, 0x16);
    width = (s16)(right - left);

    margin = M2C_FIELD(arg0, s16 *, 0x62);

    top = M2C_FIELD(arg0, s16 *, 0x14);
    bottom = M2C_FIELD(arg0, s16 *, 0x18);
    height = (s16)(bottom - top);

    color[0] = 0xFF;
    color[1] = 0xFF;
    color[2] = 0xFF;
    color[3] = 0x33;

    Ui_DrawLine(
        margin,
        height,
        (s16)(margin + (s16)((s16)(right - left) - (margin << 1))),
        height,
        0x10,
        color
    );

    Prim2D_Begin();
    Prim2D_SetTex(
        0,
        M2C_FIELD(arg0, s32 *, 0x34) | 0x13
    );
    Prim2D_PrepareTex();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A6A0);
    Prim2D_PrepareTex();

    lineHeight = ((Obj *)arg0)->GetLineHeight();

    measured = Text_MeasureHeight(-1, lbl_8036A674);
    difference = (s16)lineHeight - measured;

    flag = 0;
    y = (s16)(difference >> 1);

    if (!fn_8014D8DC(gBattleState) ||
        Convoy_FindEmpty(gConvoy) < 0) {
        flag = 1;
    }

    shadow = 6;

    if (flag) {
        shadow = 0;
    }

    expanded = (char *)Msg_Expand(
        (s32)lbl_802768A0 + 0x3E
    );

    drawY = (s16)(height + y);

    Text_Draw(
        margin,
        drawY,
        shadow,
        (char *)lbl_802768A0 + 0x39,
        expanded
    );
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_80139A50(s32 *arg0, void *arg1) {
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
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual s32 v11() = 0;
    };
    struct Point {
        s16 x;
        s16 y;
    };
    struct Point *fn_8013F748(void *, struct Point *, struct Point *);
    struct Point out2;
    struct Point in2;
    struct Point in;
    struct Point out;
    unsigned vret;
    s16 v4e;
    s16 v58;
    s16 v56;
    s16 v5a;
    s16 v62;
    s16 v64;
    u32 quot;
    s16 rem;
    s16 adj;
    s16 x;
    s16 y;

    if (*(s16 *)((u8 *)arg1 + 0x4E) != 0x7FFF) {
        vret = ((Obj *)arg1)->v11();
        v4e = *(s16 *)((u8 *)arg1 + 0x4E);
        v58 = *(s16 *)((u8 *)arg1 + 0x58);
        v56 = *(s16 *)((u8 *)arg1 + 0x56);
        quot = v4e / v58;
        v5a = *(s16 *)((u8 *)arg1 + 0x5A);
        v62 = *(s16 *)((u8 *)arg1 + 0x62);
        v64 = *(s16 *)((u8 *)arg1 + 0x64);
        rem = (s16)(v4e - quot * v58);
        adj = (s16)((s16)quot - v56);
        x = (s16)(vret * rem + v62);
        y = (s16)(v5a * adj + v64);
        in.x = x;
        in.y = y;
        *arg0 = *(s32 *)fn_8013F748(arg1, &out, &in);
    } else {
        s16 diff = *(s16 *)((u8 *)arg1 + 0x18) - *(s16 *)((u8 *)arg1 + 0x14);
        in2.x = *(s16 *)((u8 *)arg1 + 0x62);
        in2.y = diff;
        *arg0 = *(s32 *)fn_8013F748(arg1, &out2, &in2);
    }
}
#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma global_optimizer off
extern "C" void fn_80139B3C(void *self, void *other) {
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
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual s32 v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16(s16, s16, s32, s16, u8) = 0;
        virtual void v17() = 0;
        virtual void v18(void *) = 0;
    };
    extern void Prim2D_Begin(void);
    extern void Prim2D_AddZ(f32);
    extern void Prim2D_PrepareTex(void);
    extern s32 Text_MeasureHeight(s32, f32);
    extern void Ui_DrawRouteIconEx(s16, s32, u8);
    extern void Prim2D_ClearCallbacks(void);
    extern void Prim2D_SetAlphaByte(s32);
    extern f32 lbl_8036A670;
    extern f32 lbl_8036A674;
    extern f32 lbl_8036A678;
    extern f32 lbl_8036A6A4;
    extern f32 lbl_8036A6A8;
    s16 t5a;
    u8 r30;
    s32 r29;
    s16 r28;
    s16 r27;
    s16 t24;
    u8 flag;
    void *ptr;
    f32 f;
    s16 x;
    s16 y;

    ((Obj *)self)->v3();
    r29 = ((Obj *)self)->v11();
    {
        s16 t56;
        s16 t62;
        s16 t58;
        s16 t4e;
        s16 t52;
        s32 quot;
        s16 t64;
        t4e = *(s16 *)((u8 *)self + 0x4E);
        t58 = *(s16 *)((u8 *)self + 0x58);
        t52 = *(s16 *)((u8 *)self + 0x52);
        quot = t4e / t58;
        t56 = *(s16 *)((u8 *)self + 0x56);
        t5a = *(s16 *)((u8 *)self + 0x5A);
        t62 = *(s16 *)((u8 *)self + 0x62);
        t64 = *(s16 *)((u8 *)self + 0x64);
        r27 = (s16)(t5a * (s16)((s16)quot - t56) + t64);
        r28 = (s16)(r29 * (s16)(t4e - quot * t58) + t62);
        if (t52 < 0 || *(s16 *)((u8 *)self + 0x54) < 0) {
            *(s16 *)((u8 *)self + 0x52) = r28;
            *(s16 *)((u8 *)self + 0x54) = r27;
        } else {
            *(s16 *)((u8 *)self + 0x52) = (t52 + r28 + 1) >> 1;
            *(s16 *)((u8 *)self + 0x54) = (*(s16 *)((u8 *)self + 0x54) + r27 + 1) >> 1;
        }
    }
    if (*(u8 *)((u8 *)self + 0x4C) != 0 && *(u32 *)((u8 *)self + 0x70) != 0) {
        r30 = 0;
        flag = r30;
        if (*(u8 *)((u8 *)other + 0x2D) == 0) {
            if (*(u8 *)((u8 *)other + 0x2E) == 0) {
                flag = 1;
            }
        }
        if (flag) {
            if (*(u32 *)((u8 *)other + 0x34) != 0) {
                ptr = (*(void ***)((u8 *)other + 0x38))[2];
            } else {
                ptr = 0;
            }
            if (ptr == self) {
                r30 = 1;
            }
        }
        Prim2D_Begin();
        if (r30 != 0) {
            f = lbl_8036A6A4;
        } else {
            f = lbl_8036A670;
        }
        Prim2D_AddZ(f);
        Prim2D_PrepareTex();
        t24 = *(s16 *)((u8 *)self + 0x5A);
        x = (s16)Text_MeasureHeight(-1, lbl_8036A674);
        y = (s16)((t24 - x) >> 1);
        Ui_DrawRouteIconEx(*(s16 *)((u8 *)self + 0x52), *(s16 *)((u8 *)self + 0x54) + y, r30);
        Prim2D_Begin();
        if (r30 != 0) {
            f = lbl_8036A6A8;
        } else {
            f = lbl_8036A678;
        }
        Prim2D_AddZ(f);
        Prim2D_PrepareTex();
        ((Obj *)self)->v16((s16)(r28 - *(s16 *)((u8 *)self + 0x62)), r27, r29, t5a, r30);
    }
    ((Obj *)self)->v18(other);
    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}
#pragma global_optimizer on
#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" void fn_80139D60(void *arg0, void *arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    void fn_8015547C(s16, s16, s32, s32, u8, s32);
    extern f32 lbl_8036A66C;
    extern f32 lbl_8036A668;
    void *other = arg1;
    void *self = arg0;
    u8 flag;
    u8 sel;
    void *p;
    f32 f;

    ((Obj *)self)->v2();
    fn_8015547C(0, 0,
                (s16)(*(s16 *)((u8 *)self + 0xE) - *(s16 *)((u8 *)self + 0xA)),
                (s16)(*(s16 *)((u8 *)self + 0x10) - *(s16 *)((u8 *)self + 0xC)),
                0xFF, 0x10);

    sel = 0;
    flag = sel;
    if (*(u8 *)((u8 *)other + 0x2D) == 0 && *(u8 *)((u8 *)other + 0x2E) == 0) {
        flag = 1;
    }
    if (flag) {
        if (*(void **)((u8 *)other + 0x34) != NULL) {
            p = *(void **)((u8 *)*(void **)((u8 *)other + 0x38) + 8);
        } else {
            p = NULL;
        }
        if (p == self) {
            sel = 1;
        }
    }
    f = sel ? lbl_8036A66C : lbl_8036A668;
    *(f32 *)((u8 *)self + 0xA8) = f;
    f = sel ? lbl_8036A66C : lbl_8036A668;
    *(f32 *)((u8 *)self + 0xD0) = f;
}
extern "C" void fn_80139E5C(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
    };
    ((Obj *)arg0)->v6();
}

#pragma push
#pragma optimization_level 4
#pragma global_optimizer off
extern "C" void fn_80139E88(void *arg0) {
    void Ui_PlaySeCue(void *, s32);
    void fn_8013ED84(void *, s16);
    extern char lbl_802768A0[];
    extern u32 gUiInputFlags;
    extern u32 *gPadInput;
    struct Obj {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
        virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
        virtual void v12() = 0; virtual s32 v13() = 0;
    };
    s32 vret;
    s32 rows;
    s32 raw;
    s32 total;
    s16 pages;
    s16 page;
    s16 col;
    u8 skip;
    s32 trig;
    s32 edge;
    s16 saved;
    s16 rows2;
    s32 held;
    s32 rows_m1;
    s32 pages_tmp;

    vret = ((Obj *)arg0)->v13();
    rows = *(s16 *)((u8 *)arg0 + 0x58);
    raw = *(s32 *)((u8 *)arg0 + 0x70);
    rows_m1 = rows - 1;
    total = (s16)raw;
    pages_tmp = (total + rows_m1) / rows;
    pages = (s16)pages_tmp;
    if ((s16)vret > pages) {
        vret = pages;
    }
    skip = 0;
    {
        s16 t = *(s16 *)((u8 *)arg0 + 0x4E);
        page = (s16)(t / rows);
        col = (s16)(t % rows);
    }
    if ((gUiInputFlags & 0x10) != 0) {
        if ((gUiInputFlags & 0x20) == 0) {
            skip = 1;
        }
    }
    if (skip == 0) {
        rows2 = (s16)rows;
        saved = *(s16 *)((u8 *)arg0 + 0x4E);
        held = (s32)gPadInput[1];
        trig = (s32)gPadInput[3];
        edge = held & ((s32)gPadInput[2] ^ held);
        if (rows2 > 1) {
            held = total - page * rows2;
            if (held > rows2) {
                held = rows2;
            }
            if ((trig & 0x01000001) != 0) {
                if (col > 0) {
                    *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) - 1);
                } else if (trig == edge) {
                    s32 idx = held + *(s16 *)((u8 *)arg0 + 0x4E);
                    *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(idx - 1);
                }
            } else if ((trig & 0x02000002) != 0) {
                s32 lim = held - 1;
                if (col < lim) {
                    *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) + 1);
                } else if (trig == edge) {
                    *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) - lim);
                }
            }
        }
        if ((s16)(s32)*(f32 *)((u8 *)arg0 + 0x5C) == 0) {
            if ((trig & 0x08000008) != 0) {
                if (page == 0) {
                    if (trig == edge) {
                        s32 pm1 = pages - 1;
                        s16 vr = (s16)vret;
                        s32 add = pm1 * rows;
                        s16 cur = *(s16 *)((u8 *)arg0 + 0x4E);
                        s32 d = pages - vr;
                        s32 tmax = total - 1;
                        s32 tmp = (-d) & ~d;
                        *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(cur + add);
                        *(s16 *)((u8 *)arg0 + 0x56) = (s16)(d & (tmp >> 31));
                        if (*(s16 *)((u8 *)arg0 + 0x4E) > tmax) {
                            *(s16 *)((u8 *)arg0 + 0x4E) = (s16)tmax;
                        }
                    }
                } else {
                    *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) - rows);
                    if (*(s16 *)((u8 *)arg0 + 0x4E) > rows_m1) {
                        if (((s16)(*(s16 *)((u8 *)arg0 + 0x4E) / rows) - *(s16 *)((u8 *)arg0 + 0x56)) == 0) {
                            *(s16 *)((u8 *)arg0 + 0x56) -= 1;
                            *(f32 *)((u8 *)arg0 + 0x5C) = (f32)(-(*(s16 *)((u8 *)arg0 + 0x5A)));
                        }
                    }
                }
                if (saved != *(s16 *)((u8 *)arg0 + 0x4E)) {
                    *(s16 *)((u8 *)arg0 + 0x9A) = 1;
                    *(u8 *)((u8 *)arg0 + 0x91) = 1;
                }
            } else if ((trig & 0x04000004) != 0) {
                s32 pm1 = pages - 1;
                if (page == pm1) {
                    if (trig == edge) {
                        *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) - pm1 * rows);
                        *(s16 *)((u8 *)arg0 + 0x56) = 0;
                    }
                } else {
                    s32 tmax = total - 1;
                    *(s16 *)((u8 *)arg0 + 0x4E) = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) + rows);
                    if (*(s16 *)((u8 *)arg0 + 0x4E) > tmax) {
                        *(s16 *)((u8 *)arg0 + 0x4E) = (s16)tmax;
                    }
                    {
                        s16 np = (s16)(*(s16 *)((u8 *)arg0 + 0x4E) / rows);
                        if (np < pm1) {
                            s16 sc = *(s16 *)((u8 *)arg0 + 0x56);
                            if ((s32)((s16)vret - 1) == (s32)(np - sc)) {
                                *(s16 *)((u8 *)arg0 + 0x56) = (s16)(sc + 1);
                                *(f32 *)((u8 *)arg0 + 0x5C) = (f32)(*(s16 *)((u8 *)arg0 + 0x5A));
                            }
                        }
                    }
                }
                if (saved != *(s16 *)((u8 *)arg0 + 0x4E)) {
                    *(s16 *)((u8 *)arg0 + 0xC2) = 1;
                    *(u8 *)((u8 *)arg0 + 0xB9) = 1;
                }
            }
        }
        if (saved != *(s16 *)((u8 *)arg0 + 0x4E)) {
            Ui_PlaySeCue(lbl_802768A0 + 0x1D, 0x64);
        }
    }
    fn_8013ED84(*(void **)((u8 *)arg0 + 0x48),
                (s16)((*(s16 *)((u8 *)arg0 + 0x56) * *(s16 *)((u8 *)arg0 + 0x5A)) - (s32)*(f32 *)((u8 *)arg0 + 0x5C)));
}
#pragma pop
extern "C" void fn_8013A20C(void *arg0) {
    void Prim2D_Begin(void); void Prim2D_AddZ(f32); void Prim2D_PrepareTex(void);
    void Prim2D_SetAlphaByte(s32); void Prim2D_ClearCallbacks(void);
    s32 Text_MeasureHeight(s32,f32); void Ui_DrawRouteIconEx(s16,s32,u8);
    extern f32 lbl_8036A674, lbl_8036A698, lbl_8036A69C;
    struct Obj {
virtual void v1()=0; virtual void v2()=0;
virtual void v3()=0; virtual void setup()=0; virtual void v5()=0;
virtual void v6()=0; virtual void v7()=0; virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void v11()=0;
virtual s32 width()=0; virtual void v13()=0; virtual void v14()=0; virtual void v15()=0; virtual void v16()=0;
virtual void draw(s16,s16,s32,s16,s32)=0;
};

    s32 height, drawY, width, y;
    s16 x, half, rowHeight;
    s16 index, columns, row;
    u8 *self=(u8 *)arg0;
    if(self[0x4D]) {
        ((Obj *)self)->setup();
        Prim2D_Begin(); Prim2D_AddZ(lbl_8036A698); Prim2D_PrepareTex();
        width=((Obj *)self)->width();
        height=*(s16 *)(self+0x5A); rowHeight=(s16)height;
        index=*(s16 *)(self+0x50); columns=*(s16 *)(self+0x58);
        row=(s16)(index/columns);
        x=(s16)(width*(s16)(index%columns)+*(s16 *)(self+0x62));
        y=(s16)(rowHeight*(s16)(row-*(s16 *)(self+0x56))+*(s16 *)(self+0x64));
        half=(s16)((rowHeight-Text_MeasureHeight(-1,lbl_8036A674))>>1);
        drawY=half+*(s16 *)(self+0x60);
        drawY=y+drawY;
        if(drawY>=*(s16 *)(self+0x64)) {
            y+=*(s16 *)(self+0x60);
            if((s16)(*(s16 *)(self+0x18)-*(s16 *)(self+0x14))-*(s16 *)(self+0x64)>=(rowHeight+y)-half) {
                Prim2D_Begin(); Prim2D_SetAlphaByte(0x40); Prim2D_PrepareTex();
                Ui_DrawRouteIconEx(x,drawY,0);
                Prim2D_Begin(); Prim2D_AddZ(lbl_8036A69C); Prim2D_PrepareTex();
                ((Obj *)self)->draw((s16)(x-*(s16 *)(self+0x62)),(s16)y,width,height,0);
            }
        }
    }
    Prim2D_Begin(); Prim2D_ClearCallbacks(); Prim2D_SetAlphaByte(0x80); Prim2D_PrepareTex();
}

#pragma cplusplus reset
#pragma global_optimizer reset

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma global_optimizer off
extern "C" void fn_8013A39C(void *self, void *other) {
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
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual s32 v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16(s16, s16, s32, s16, u8) = 0;
        virtual void v17() = 0;
        virtual void v18(void *) = 0;
    };
    extern void Prim2D_Begin(void);
    extern void Prim2D_AddZ(f32);
    extern void Prim2D_PrepareTex(void);
    extern s32 Text_MeasureHeight(s32, f32);
    extern void Ui_DrawRouteIconEx(s16, s32, u8);
    extern void Prim2D_ClearCallbacks(void);
    extern void Prim2D_SetAlphaByte(s32);
    extern f32 lbl_8036A670;
    extern f32 lbl_8036A674;
    extern f32 lbl_8036A678;
    s16 t5a;
    u8 r30 = 0;
    s32 r29;
    s16 r28;
    s16 r27;
    s16 t24;
    u8 flag;
    void *ptr;
    s16 x;
    s16 y;

    ((Obj *)self)->v3();
    r29 = ((Obj *)self)->v11();
    {
        s16 t56;
        s16 t62;
        s16 t58;
        s16 t4e;
        s16 t52;
        s32 quot;
        s16 t64;
        t4e = *(s16 *)((u8 *)self + 0x4E);
        t58 = *(s16 *)((u8 *)self + 0x58);
        t52 = *(s16 *)((u8 *)self + 0x52);
        quot = t4e / t58;
        t56 = *(s16 *)((u8 *)self + 0x56);
        t5a = *(s16 *)((u8 *)self + 0x5A);
        t62 = *(s16 *)((u8 *)self + 0x62);
        t64 = *(s16 *)((u8 *)self + 0x64);
        r27 = (s16)(t5a * (s16)((s16)quot - t56) + t64);
        r28 = (s16)(r29 * (s16)(t4e - quot * t58) + t62);
        if (t52 < 0 || *(s16 *)((u8 *)self + 0x54) < 0) {
            *(s16 *)((u8 *)self + 0x52) = r28;
            *(s16 *)((u8 *)self + 0x54) = r27;
        } else {
            *(s16 *)((u8 *)self + 0x52) = (t52 + r28 + 1) >> 1;
            *(s16 *)((u8 *)self + 0x54) = (*(s16 *)((u8 *)self + 0x54) + r27 + 1) >> 1;
        }
    }
    if (*(u8 *)((u8 *)self + 0x4C) != 0 && *(u32 *)((u8 *)self + 0x70) != 0) {
        flag = r30;
        if (*(u8 *)((u8 *)other + 0x2D) == 0) {
            if (*(u8 *)((u8 *)other + 0x2E) == 0) {
                flag = 1;
            }
        }
        if (flag) {
            if (*(u32 *)((u8 *)other + 0x34) != 0) {
                ptr = (*(void ***)((u8 *)other + 0x38))[2];
            } else {
                ptr = 0;
            }
            if (ptr == self) {
                r30 = 1;
            }
        }
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A670);
        Prim2D_PrepareTex();
        t24 = *(s16 *)((u8 *)self + 0x5A);
        x = (s16)Text_MeasureHeight(-1, lbl_8036A674);
        y = (s16)((t24 - x) >> 1);
        Ui_DrawRouteIconEx(*(s16 *)((u8 *)self + 0x52), *(s16 *)((u8 *)self + 0x54) + y, r30);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A678);
        Prim2D_PrepareTex();
        ((Obj *)self)->v16((s16)(r28 - *(s16 *)((u8 *)self + 0x62)), r27, r29, t5a, r30);
    }
    ((Obj *)self)->v18(other);
    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void fn_8013A5A0(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0()=0; virtual void v1()=0; virtual void v2()=0;
        virtual void v3(s32)=0; virtual void v4()=0; virtual void v5()=0;
        virtual void v6()=0; virtual void v7()=0; virtual void v8()=0;
        virtual void v9()=0; virtual void v10()=0;
        virtual s32 v11()=0;
        virtual void v12()=0;
        virtual s32 v13()=0;
        virtual s32 v14(void *)=0;
        virtual void v15(s16,s16,s32,void *,s32)=0;
        virtual void v16()=0;
        virtual void v17()=0;
        u8 pad4[14]; s16 a12,a14,a16,a18; u8 pad1a[0x56-0x1A];
        s16 a56,a58,a5a; f32 a5c; s16 a60,a62,a64; s16 rect[4]; u32 a70;
    };
    struct Sub {
        virtual void v0()=0; virtual void v1()=0; virtual void v2()=0;
        virtual void v3()=0; virtual void v4()=0; virtual void v5()=0;
        virtual void v6()=0; virtual void v7()=0; virtual void v8()=0;
        virtual void v9(s32)=0;
    };
    struct Node { Node *prev; Node *next; Sub *obj; };
    typedef void (Sub::*PTMF)(s32);
    struct Pair { PTMF ptmf; s32 arg; };
    void fn_8013F748(void *,s16 *,s16 *);
    void Prim2D_Begin(void); void Prim2D_PrepareTex(void); void Prim2D_ClearCallbacks(void);
    void Prim2D_AddZ(f32); void Prim2D_ScissorFromRect(void *);
    void Prim2D_SetCallback(void (*)(void *),s16 *);
    extern f32 lbl_8036A668,lbl_8036A6AC,lbl_8036A670;
    extern f32 lbl_80367098[];
    extern PTMF lbl_80291A68;
    s16 index;
    s16 row;
    s16 endrow;
    s16 y;
    s16 col;
    s16 x;
    u8 *self;
    s16 width;
    s16 rows;
    Node *node;
    s32 xpos;
    s32 ypos;
    s16 scroll;
    s16 rowHeight;
    Node *it,*sent;
    s32 arg;
    s32 visible;
    s16 sign;
    self=(u8 *)arg0;
    arg=arg1;
    Pair p[2];
    s16 *rect;
    ((Obj *)self)->v17();
    ((Obj *)self)->v3(arg);
    rect=(s16 *)(self+0x66);
    s16 h=((Obj *)self)->a18-((Obj *)self)->a14;
    s16 w=((Obj *)self)->a16-((Obj *)self)->a12;
    rect[0]=0; rect[1]=0; rect[2]=w; rect[3]=h;
    fn_8013F748(self,rect,rect);
    rect=(s16 *)(self+0x6a); fn_8013F748(self,rect,rect);
    Prim2D_Begin();
    Prim2D_SetCallback(Prim2D_ScissorFromRect,(s16 *)(self+0x66)); Prim2D_PrepareTex();
    rows=((Obj *)self)->a58;
    visible=((Obj *)self)->v13();
    s16 page0=((Obj *)self)->a56;
    index=(s16)(((Obj *)self)->a58 * page0);
    width=(s16)((Obj *)self)->v11();
    s16 conv=(s16)((Obj *)self)->a5c;
    rowHeight=((Obj *)self)->a5a;
    ((Obj *)self)->a60=conv;
    f32 zero=lbl_8036A668;
    f32 fval=((Obj *)self)->a5c;
    if (fval<zero) {
        f32 value=(f32)((Obj *)self)->a5a*lbl_8036A6AC+fval;
        ((Obj *)self)->a5c=value;
        if (value>=-lbl_80367098[0]) ((Obj *)self)->a5c=zero;
    } else if (fval>zero) {
        f32 value=fval-(f32)((Obj *)self)->a5a*lbl_8036A6AC;
        ((Obj *)self)->a5c=value;
        if (value<=lbl_80367098[0]) ((Obj *)self)->a5c=zero;
    }
    scroll=conv;
    sign=(s16)scroll<0 ? -1 : ((s16)scroll>0 ? 1 : 0);
    if((s16)sign>0 && (s16)index-(s16)rows>=0) index-=rows;
    node=*(Node **)(self+0x78);
    s16 n=index;
    if((s16)index>=0) { while(n>0) {node=node->next; --n;} }
    else {while(n<0) {node=node->prev; ++n;} }
    endrow=(s16)visible;
    row=(-((s16)sign) & ~(s16)sign)>>31;
    if((s16)sign<0) ++endrow;
    ypos=row*rowHeight;
    for(;row<endrow;ypos+=rowHeight,++row) {
        col=0; xpos=0;
        y=ypos+((Obj *)self)->a64+scroll;
        while(col<(s16)rows) {
            if((u32)(s16)index>=((Obj *)self)->a70) goto done;
            x=xpos+((Obj *)self)->a62;
            s32 value=((Obj *)self)->v14(node->obj);
            ((Obj *)self)->v15(x,y,-1,node->obj,value);
            node=node->next; xpos+=width; ++col; ++index;
        }
    }
done:
    Prim2D_Begin(); Prim2D_ClearCallbacks(); Prim2D_PrepareTex();
    Prim2D_Begin(); Prim2D_AddZ(lbl_8036A670); Prim2D_PrepareTex();
    s32 rm1=(s16)rows-1;
    s16 pages=(rm1+((Obj *)self)->a70)/(u32)(s16)rows;
    *(u8 *)(self+0x90)=((Obj *)self)->a56>0;
    s16 page=((Obj *)self)->a56;
    s32 available=pages-(s16)((Obj *)self)->v13();
    *(u8 *)(self+0xb8)=((s16)page)<available;
    ((Sub *)(self+0x84))->v9(16); ((Sub *)(self+0xac))->v9(16);
    s16 bw=(s16)(((rm1+((Obj *)self)->a70)/(u32)(s16)rows)*rowHeight);
    s16 bh=(s16)((s16)visible*rowHeight);
    s16 by=(s16)(page*rowHeight-(s16)scroll);
    u8 *bar=*(u8 **)(self+0x48);
    *(s16 *)(bar+0x3c)=bw;
    *(s16 *)(bar+0x3e)=bh;
    *(s16 *)(bar+0x40)=by;
    p[1].arg=arg;
    p[0].ptmf=lbl_80291A68; p[0].arg=arg; p[1].ptmf=lbl_80291A68;
    it=*(Node **)(self+0x44); sent=(Node *)(self+0x40);
    while(it!=sent) { (it->obj->*p[0].ptmf)(p[0].arg); it=it->next; }
}
#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma global_optimizer on
#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_8013A9F4(void *arg0) {
    void fn_80155F20(s32, s32, s16, s16, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_80155F20(0, 0,
        (s16)(*(s16 *)((u8 *)arg0 + 0xE) - *(s16 *)((u8 *)arg0 + 0xA)),
        (s16)(*(s16 *)((u8 *)arg0 + 0x10) - *(s16 *)((u8 *)arg0 + 0xC)),
        0xFF, 0x10);
}
#pragma cplusplus reset
void fn_8013AA60(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5) {
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    fn_8008AB7C(arg1 + (arg3 >> 1), arg2 + (arg4 >> 1), arg3, 0x18, 0x19, 0x4C, arg5);
}

#pragma push
#pragma optimization_level 3
void fn_8013AAB4(void *arg0, s32 arg1, s16 arg2, s32 arg3, void *arg4, u8 arg5) {
    M2C_UNK Prim2D_AddZ(f32);
    void Text_Draw(s32, s16, s32, void *, ...);
    s32 Text_MeasureHeight(M2C_UNK, f32);
    s32 Msg_ResolveName(s32);
    M2C_UNK fn_80152010(s16, s16, s16, M2C_UNK, M2C_UNK);
    extern u8 lbl_802768A0[];
    extern f32 lbl_8036A674;
    extern f32 lbl_8036A6B0;
    extern f32 lbl_8036A6B4;
#pragma cplusplus on
#pragma optimization_level 3
    struct Panel {
        virtual void v0()=0; virtual void v1()=0; virtual void v2()=0;
        virtual void v3()=0; virtual void v4()=0; virtual void v5()=0;
        virtual void v6()=0; virtual void v7()=0; virtual void v8()=0;
        virtual void v9()=0; virtual void v10()=0; virtual s32 width()=0;
        s16 height() { return *(s16 *)((u8 *)this+0x5A); }
    };
    s16 h;
    s16 y;
    s32 flag;
    s32 name;
    s32 meas;
    s32 diff;

    flag = arg5 != 0;
    if ((u32) ((M2C_FIELD(arg4, s32 *, 0x1A0) & 0x010000DC) + 0xFF000000) == 0xDCU) {
        flag = 0;
    }
    Prim2D_Begin();
    Prim2D_SetTex(0, (u16) (M2C_FIELD(arg0, s32 *, 0x34) | 0x13));
    Prim2D_PrepareTex();
    name = Msg_ResolveName(M2C_FIELD(arg4, s32 *, 0x188));
    h = ((Panel *)arg0)->height();
    meas = Text_MeasureHeight(-1, lbl_8036A674);
    diff = (s16)h;
    diff = diff - meas;
    y = (s16)arg2;
    Text_Draw(arg1, (s16)(y + (s16)(diff >> 1)), flag, lbl_802768A0 + 0x39, name);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A6B0);
    Prim2D_PrepareTex();
    h = ((Panel *)arg0)->height();
    {
        s32 w = ((Panel *)arg0)->width();
        s16 pad = M2C_FIELD(arg0, s16 *, 0x62);
        diff = (s16)h;
        fn_80152010((s16)(arg1 - 6), (s16)(y + (diff >> 1)), (s16)((w - (pad * 2)) + 6), 0xFF, 0x10);
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A6B4);
    Prim2D_PrepareTex();
#pragma optimization_level reset
#pragma cplusplus reset
}
#pragma pop
s32 fn_8013AC00(void *arg0, s32 arg1) {
    u8 (*temp_r12)(s32, s32);

    temp_r12 = M2C_FIELD(arg0, u8 (**)(s32, s32), 0x7C);
    if (temp_r12 != NULL) {
        return temp_r12(arg1, M2C_FIELD(arg0, s32 *, 0x80)) != 0;
    }
    return 1;
}

void *Ui_ListGetSelected(void *arg0) {
    struct Node {
        struct Node *prev;
        struct Node *next;
        void *unk8;
    };
    struct Node *node;
    s32 tmp;
    s16 n;
    u32 count;

    count = *(u32 *)((u8 *)arg0 + 0x70);
    if (count == 0) {
        return NULL;
    }
    tmp = *(s16 *)((u8 *)arg0 + 0x4E);
    n = (s16)tmp;
    if (n < 0 || count <= (u32)n) {
        return NULL;
    }
    node = *(struct Node **)((u8 *)arg0 + 0x78);
    if (n >= 0) {
        goto loop_pos;
        do {
            node = node->next;
            n -= 1;
        loop_pos:
            ;
        } while (n > 0);
    } else {
        goto loop_neg;
        do {
            node = node->prev;
            n += 1;
        loop_neg:
            ;
        } while (n < 0);
    }
    return node->unk8;
}

#pragma cplusplus on
extern "C" void fn_8013ACC4(s32 *arg0, void *arg1) {
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
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual s32 v11() = 0;
    };
    struct Point {
        s16 x;
        s16 y;
    };
    struct Point *fn_8013F748(void *, struct Point *, struct Point *);
    struct Point out;
    struct Point in;
    unsigned vret;
    s16 v4e;
    s16 v58;
    s16 v56;
    s16 v5a;
    s16 v62;
    s16 v64;
    u32 quot;
    s16 rem;
    s16 adj;

    vret = ((Obj *)arg1)->v11();
    v4e = *(s16 *)((u8 *)arg1 + 0x4E);
    v58 = *(s16 *)((u8 *)arg1 + 0x58);
    v56 = *(s16 *)((u8 *)arg1 + 0x56);
    v5a = *(s16 *)((u8 *)arg1 + 0x5A);
    v62 = *(s16 *)((u8 *)arg1 + 0x62);
    v64 = *(s16 *)((u8 *)arg1 + 0x64);
    quot = v4e / v58;
    rem = (s16)(v4e - quot * v58);
    adj = (s16)((s16)quot - v56);
    in.y = (s16)(v5a * adj + v64);
    in.x = (s16)(vret * rem + v62);
    *arg0 = *(s32 *)fn_8013F748(arg1, &out, &in);
}

extern "C" void fn_8013AD70(void *arg0, void *arg1) {
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
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual s16 v13() = 0;
    };
    struct Node {
        struct Node *prev;
        struct Node *next;
        void *obj;
    };
    typedef struct {
        u8 pad0[0x4E];
        s16 unk4E;
        s16 unk50;
        s16 unk52;
        s16 unk54;
        s16 unk56;
        s16 unk58;
        u8 pad5A[0x16];
        s32 unk70;
        struct Node sentinel;
    } Unk;

    s32 index;
    s16 target;
    s16 var_r3;
    s32 temp_r4;
    s32 temp_r7;
    s32 temp_r6;
    s32 temp_r8;
    s32 t;
    struct Node *node;
    struct Node *head;
    struct Node *end;
    Unk *self;

    self = (Unk *)arg0;
    end = &self->sentinel;
    head = end->next;
    node = head;

    goto lbl_check;
    do {
        node = node->next;
    lbl_check:
        if (node == end) {
            break;
        }
    } while (node->obj != arg1);

    if (node == end) {
        return;
    }

    index = 0;
    goto lbl_count;
    do {
        head = head->next;
        index++;
    lbl_count:
        ;
    } while (head != node);

    target = (s16)index;

    if (target != self->unk4E) {
        var_r3 = ((Obj *)self)->v13();
        temp_r7 = (s16)self->unk70;
        temp_r4 = self->unk58;
        temp_r6 = temp_r4 - 1;
        temp_r8 = (s16)((temp_r7 + temp_r6) / temp_r4);
        if (target < 0) {
            return;
        }
        if (temp_r7 <= target) {
            return;
        }
        if (var_r3 > temp_r8) {
            var_r3 = temp_r8;
        }
        if (target < self->unk4E) {
            do {
                self->unk4E = (s16)(self->unk4E - 1);
                if (self->unk4E > temp_r6) {
                    if ((s16)(self->unk4E / temp_r4) - self->unk56 == 0) {
                        self->unk56 = (s16)(self->unk56 - 1);
                    }
                }
            } while (target < self->unk4E);
        } else {
            temp_r6 = temp_r7 - 1;
            temp_r7 = temp_r8 - 1;
            temp_r8 = var_r3 - 1;
            do {
                self->unk4E = (s16)(self->unk4E + 1);
                if (self->unk4E > temp_r6) {
                    self->unk4E = (s16)temp_r6;
                }
                t = (s16)(self->unk4E / temp_r4);
                if (t < temp_r7) {
                    if (temp_r8 == t - (s16)self->unk56) {
                        self->unk56 = (s16)(self->unk56 + 1);
                    }
                }
            } while (self->unk4E < target);
        }
        self->unk52 = -1;
        self->unk54 = -1;
    }
}

extern "C" void Ui_ListSetCursor(void *arg0, s16 arg1) {
    struct Obj {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
        virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
        virtual void v8() = 0; virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
        virtual void v12() = 0; virtual s16 v13() = 0;
    };
    s16 var_r3;
    s32 temp_r4;
    s32 temp_r6;
    s16 temp_r7;
    s16 temp_r8;
    s32 maxIdx;
    s32 maxRow;
    s32 maxOff;
    s32 t;

    if (arg1 != (s16)M2C_FIELD(arg0, s16 *, 0x4E)) {
        var_r3 = ((Obj *)arg0)->v13();
        temp_r7 = (s16)M2C_FIELD(arg0, s32 *, 0x70);
        temp_r4 = M2C_FIELD(arg0, s16 *, 0x58);
        temp_r6 = temp_r4 - 1;
        temp_r8 = (s16)((temp_r7 + temp_r6) / temp_r4);
        if ((arg1 < 0) || (temp_r7 <= arg1)) return;
        if (var_r3 > temp_r8) var_r3 = temp_r8;
        if (arg1 < (s16)M2C_FIELD(arg0, s16 *, 0x4E)) {
            do {
                M2C_FIELD(arg0, s16 *, 0x4E) = (s16)(M2C_FIELD(arg0, s16 *, 0x4E) - 1);
                if ((s16)M2C_FIELD(arg0, s16 *, 0x4E) > temp_r6) {
                    if ((s16)(M2C_FIELD(arg0, s16 *, 0x4E) / temp_r4) - M2C_FIELD(arg0, s16 *, 0x56) == 0) {
                        M2C_FIELD(arg0, s16 *, 0x56) = (s16)(M2C_FIELD(arg0, s16 *, 0x56) - 1);
                    }
                }
            } while (arg1 < (s16)M2C_FIELD(arg0, s16 *, 0x4E));
        } else {
            maxIdx = temp_r7 - 1;
            maxRow = temp_r8 - 1;
            maxOff = var_r3 - 1;
            do {
                M2C_FIELD(arg0, s16 *, 0x4E) = (s16)(M2C_FIELD(arg0, s16 *, 0x4E) + 1);
                if ((s16)M2C_FIELD(arg0, s16 *, 0x4E) > maxIdx) {
                    M2C_FIELD(arg0, s16 *, 0x4E) = (s16)maxIdx;
                }
                t = (s16)(M2C_FIELD(arg0, s16 *, 0x4E) / temp_r4);
                if (t < maxRow) {
                    if (maxOff == t - (s16)M2C_FIELD(arg0, s16 *, 0x56)) {
                        M2C_FIELD(arg0, s16 *, 0x56) = (s16)(M2C_FIELD(arg0, s16 *, 0x56) + 1);
                    }
                }
            } while ((s16)M2C_FIELD(arg0, s16 *, 0x4E) < arg1);
        }
        M2C_FIELD(arg0, s16 *, 0x52) = -1;
        M2C_FIELD(arg0, s16 *, 0x54) = -1;
    }
}
#pragma cplusplus reset

void fn_8013B064(void *arg0, void *arg1) {
    void fn_800506E0(void *, s32, void *);
    void GActor_Finalize(void *);
    void fn_800616A0(void *);
    void *GActor_Create(void);
    s32 fn_800639B4(void);
    void fn_8013BAD4(void *, void *, void *, void *);
    struct Entry {
        void *unit;
        void *actor;
        
    };
    struct Entry entry;
    void *end;
    void *result;
    entry.unit = arg1;
    entry.actor = 0;
    if (entry.actor) fn_800616A0(entry.actor);
    entry.actor = GActor_Create();
    *(void **)((u8 *)entry.actor + 4) = (u8 *)arg1 + 0x1C;
    {
        void *actor = entry.actor;
        *(u32 *)actor |= 0x50028400;
        fn_800506E0(arg1, 0, actor);
    }
    *(s32 *)((u8 *)entry.actor + 0x44) = fn_800639B4();
    GActor_Finalize(entry.actor);
    end = (u8 *)arg0 + 0x74;
    fn_8013BAD4(&result, (u8 *)arg0 + 0x70, &end, &entry);
    if (entry.actor) fn_800616A0(entry.actor);
}

void fn_8013B120(void) {
    M2C_UNK fn_80059C2C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    fn_80059C2C(0, 0, 0x260, 0x1C0, 0);
}

#pragma cplusplus on
extern "C" void *Ui_DtorPanelB(void *self, s16 doFree) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    typedef struct {
        u32 unk0;
        ListNode node;
    } DtorList;
    typedef struct Owner {
        void *vtbl;
        u8 pad4[0x6C];
        DtorList list;
        u8 pad80[4];
        void *sub84;
        u8 pad88[0x24];
        void *subAC;
    } Owner;
    void fn_8013BA08(void *, void *, void *, void *);
    void fn_8013F2A4(void *, s32);
    void Heap_Free(void *);
    extern u8 gUiPanelBVtbl[];
    extern u8 gUiPanelMidVtbl[];
    extern u8 gEmptyVtbl[];

    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    Owner *owner;

    /* C++ destructor for a UI panel (gUiPanelBVtbl): destroy embeds, clear list, run base dtor, optional free. */
    owner = (Owner *)self;
    if (self != NULL) {
        owner->vtbl = gUiPanelBVtbl;
        if (self != NULL) {
            owner->vtbl = gUiPanelMidVtbl;
            if (&owner->subAC != NULL) {
                owner->subAC = gEmptyVtbl;
                ((Obj *)&owner->subAC)->v2();
            }
            if (&owner->sub84 != NULL) {
                owner->sub84 = gEmptyVtbl;
                ((Obj *)&owner->sub84)->v2();
            }
            if (&owner->list != NULL) {
                if (&owner->list != NULL) {
                    if (&owner->list != NULL) {
                        end = &owner->list.node;
                        sp10 = end;
                        spC = end->next;
                        fn_8013BA08(sp8, &owner->list, &spC, &sp10);
                    }
                }
            }
            fn_8013F2A4(self, 0);
        }
        if (doFree > 0) {
            Heap_Free(self);
        }
    }
    return self;
}
#pragma cplusplus reset

void fn_8013B254(void *arg0)
{
  s16 new_var;
  s16 zero;
  s16 x0;
  s16 x1;
  s16 y0;
  void *new_var3;
  s16 y1;
  s32 dx;
  s16 *new_var2;
  s16 new_var4;
  s16 dy;
  s16 a;
  s16 c;
  s16 e;
  s16 new_a;
  void *q;
  void *p;
  zero = 0;
  new_var = *((s16 *) (((s8 *) arg0) + 0x64));
  new_var += 8;
  *((s16 *) (((s8 *) arg0) + 0x64)) = new_var;
  new_var4 = *((s16 *) (((s8 *) arg0) + 0x12));
  x0 = new_var4;
  x1 = *((s16 *) (((s8 *) arg0) + 0x16));
  *((s16 *) (((s8 *) arg0) + 0x92)) = (s16) ((((s16) (x1 - x0)) >> 1) - 0x20);
  *((s16 *) (((s8 *) arg0) + 0x94)) = zero;
  new_var2 = &(*((s16 *) (((s8 *) arg0) + 0x12)));
  *((s16 *) (((s8 *) arg0) + 0x96)) = zero;
  x0 = *new_var2;
  x1 = *((s16 *) (((s8 *) arg0) + 0x16));
  y0 = *((s16 *) (((s8 *) arg0) + 0x14));
  dx = (s16) (x1 - x0);
  y1 = *((s16 *) (((s8 *) arg0) + 0x18));
  dy = y1 - y0;
  *((s16 *) (((s8 *) arg0) + 0xBA)) = (s16) ((dx >> 1) - 0x20);
  *((s16 *) (((s8 *) arg0) + 0xBC)) = dy;
  *((s16 *) (((s8 *) arg0) + 0xBE)) = zero;
  q = *((void **) (((s8 *) arg0) + 0x48));
  *((s32 *) (((s8 *) q) + 0x48)) = zero;
  p = *((void **) (((s8 *) arg0) + 0x48));
  a = *((s16 *) (((s8 *) p) + 0xA));
  e = *((s16 *) (((s8 *) p) + 0xE));
  new_var = *((s16 *) (((s8 *) p) + 0xC));
  new_a = (s16) (a - 0x20);
  c = new_var;
  *((s16 *) (((s8 *) p) + 0xE)) = (s16) (new_a + ((s16) (e - a)));
  *((s16 *) (((s8 *) p) + 0xA)) = new_a;
  x0 = *((s16 *) (((s8 *) p) + 0xC));
  new_var3 = p;
  x1 = *((s16 *) (((s8 *) new_var3) + 0x10));
  *((s16 *) (((s8 *) new_var3) + 0x10)) = (s16) (c + ((s16) (x1 - x0)));
}

void fn_8013B308(void) {

}

s16 fn_8013B30C(void *arg0) {
    return (s16) ((s16) (M2C_FIELD(arg0, s16 *, 0x16) - M2C_FIELD(arg0, s16 *, 0x12)) / (s16) M2C_FIELD(arg0, s16 *, 0x58));
}

void fn_8013B32C(void) {

}

s16 fn_8013B330(void *arg0) {
    return (s16) ((s32) ((s16) (M2C_FIELD(arg0, s16 *, 0x18) - M2C_FIELD(arg0, s16 *, 0x14)) - (M2C_FIELD(arg0, s16 *, 0x64) * 2)) / (s16) M2C_FIELD(arg0, s16 *, 0x5A));
}

s16 fn_8013B35C(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0xD4);
}

#pragma cplusplus on
/* C++ destructor for a UI panel (gUiPanelVtbl): destroy embeds, clear list, run base dtor, optional free. */
extern "C" void *Ui_DtorPanel(void *self, s16 doFree) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    typedef struct {
        u32 unk0;
        ListNode node;
    } DtorList;
    typedef struct Owner {
        void *vtbl;
        u8 pad4[0x6C];
        DtorList list;
        u8 pad80[4];
        void *sub84;
        u8 pad88[0x24];
        void *subAC;
    } Owner;
    void fn_8013BA08(void *, void *, void *, void *);
    void fn_8013F2A4(void *, s32);
    void Heap_Free(void *);
    extern u8 gUiPanelVtbl[];
    extern u8 gUiPanelMidVtbl[];
    extern u8 gEmptyVtbl[];

    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    Owner *owner;

    owner = (Owner *)self;
    if (self != NULL) {
        owner->vtbl = gUiPanelVtbl;
        if (self != NULL) {
            owner->vtbl = gUiPanelMidVtbl;
            if (&owner->subAC != NULL) {
                owner->subAC = gEmptyVtbl;
                ((Obj *)&owner->subAC)->v2();
            }
            if (&owner->sub84 != NULL) {
                owner->sub84 = gEmptyVtbl;
                ((Obj *)&owner->sub84)->v2();
            }
            if (&owner->list != NULL) {
                if (&owner->list != NULL) {
                    if (&owner->list != NULL) {
                        end = &owner->list.node;
                        sp10 = end;
                        spC = end->next;
                        fn_8013BA08(sp8, &owner->list, &spC, &sp10);
                    }
                }
            }
            fn_8013F2A4(self, 0);
        }
        if (doFree > 0) {
            Heap_Free(self);
        }
    }
    return self;
}

extern "C" void fn_8013B464(void *arg0) {
#pragma cplusplus reset
void *Heap_Alloc(s32);
void *fn_8013692C(void *,s32,s32,s32,s32,s32);
void fn_8013F0F0(void *,void *);
void fn_8013F1A0(void *,void *);
#pragma cplusplus on
struct Rect {
s16 left,top,right,bottom;
s16 width() { return right-left; }
s16 height() { return bottom-top; }
void set(s16 l,s16 t,s16 r,s16 b) { left=l; top=t; right=r; bottom=b; }
};
void *child;
s16 mid,height;
Rect *outer=(Rect *)((u8 *)arg0+0xA);
Rect *inner=(Rect *)((u8 *)arg0+0x12);
inner->set(2,8,outer->width()-2,outer->height()-38);
M2C_FIELD(arg0,s16 *,0x92)=(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))>>1;
M2C_FIELD(arg0,s16 *,0x94)=0;
M2C_FIELD(arg0,s16 *,0x96)=0;
mid=(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))>>1;
height=M2C_FIELD(arg0,s16 *,0x18)-M2C_FIELD(arg0,s16 *,0x14);
M2C_FIELD(arg0,s16 *,0xBA)=mid;
M2C_FIELD(arg0,s16 *,0xBC)=height;
M2C_FIELD(arg0,s16 *,0xBE)=0;
if(M2C_FIELD(arg0,void **,0x48)) fn_8013F0F0(arg0,M2C_FIELD(arg0,void **,0x48));
child=Heap_Alloc(0x9C);
if(child) child=fn_8013692C(child,(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))-11,0,9,(s16)(M2C_FIELD(arg0,s16 *,0x18)-M2C_FIELD(arg0,s16 *,0x14)),M2C_FIELD(arg0,s16 *,0x22)-5);
M2C_FIELD(arg0,void **,0x48)=child;
M2C_FIELD(M2C_FIELD(arg0,void **,0x48),s32 *,0x48)=1;
fn_8013F1A0(arg0,M2C_FIELD(arg0,void **,0x48));
#pragma cplusplus reset
}

#pragma cplusplus reset

void fn_8013B594(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xD4) = arg1;
}

#pragma cplusplus on
/* C++ destructor for a UI panel (gUiPanelExVtbl): destroy embeds, clear list, run base dtor, optional free. */
extern "C" void *Ui_DtorPanelEx(void *self, s16 doFree) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    typedef struct {
        u32 unk0;
        ListNode node;
    } DtorList;
    typedef struct Owner {
        void *vtbl;
        u8 pad4[0x6C];
        DtorList list;
        u8 pad80[4];
        void *sub84;
        u8 pad88[0x24];
        void *subAC;
    } Owner;
    void fn_8013BA08(void *, void *, void *, void *);
    void fn_8013F2A4(void *, s32);
    void Heap_Free(void *);
    extern u8 gUiPanelExVtbl[];
    extern u8 gUiPanelMidVtbl[];
    extern u8 gEmptyVtbl[];
    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    Owner *owner;
    owner = (Owner *)self;
    if (self != NULL) {
        owner->vtbl = gUiPanelExVtbl;
        if (self != NULL) {
            owner->vtbl = gUiPanelMidVtbl;
            if (&owner->subAC != NULL) {
                owner->subAC = gEmptyVtbl;
                ((Obj *)&owner->subAC)->v2();
            }
            if (&owner->sub84 != NULL) {
                owner->sub84 = gEmptyVtbl;
                ((Obj *)&owner->sub84)->v2();
            }
            if (&owner->list != NULL) {
                if (&owner->list != NULL) {
                    if (&owner->list != NULL) {
                        end = &owner->list.node;
                        sp10 = end;
                        spC = end->next;
                        fn_8013BA08(sp8, &owner->list, &spC, &sp10);
                    }
                }
            }
            fn_8013F2A4(self, 0);
        }
        if (doFree > 0) Heap_Free(self);
    }
    return self;
}
#pragma cplusplus reset

void fn_8013B69C(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xD4) = arg1;
}

s16 fn_8013B6A4(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0xD4);
}

void fn_8013B6AC(void *arg0) {
#pragma cplusplus reset
void *Heap_Alloc(s32);
void *fn_8013692C(void *,s32,s32,s32,s32,s32);
void fn_8013F0F0(void *,void *);
void fn_8013F1A0(void *,void *);
#pragma cplusplus on
struct Rect {
s16 left,top,right,bottom;
s16 width() { return right-left; }
s16 height() { return bottom-top; }
void set(s16 l,s16 t,s16 r,s16 b) { left=l; top=t; right=r; bottom=b; }
};
void *child;
s16 mid,height;
Rect *outer=(Rect *)((u8 *)arg0+0xA);
Rect *inner=(Rect *)((u8 *)arg0+0x12);
inner->set(32,8,outer->width()-32,outer->height()-8);
M2C_FIELD(arg0,s16 *,0x62)=8;
M2C_FIELD(arg0,s16 *,0x64)=12;
if(M2C_FIELD(arg0,void **,0x48)) fn_8013F0F0(arg0,M2C_FIELD(arg0,void **,0x48));
child=Heap_Alloc(0x9C);
if(child) child=fn_8013692C(child,(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))+16,0,9,(s16)(M2C_FIELD(arg0,s16 *,0x18)-M2C_FIELD(arg0,s16 *,0x14)),M2C_FIELD(arg0,s16 *,0x22)-5);
M2C_FIELD(arg0,void **,0x48)=child;
M2C_FIELD(M2C_FIELD(arg0,void **,0x48),s32 *,0x48)=0;
fn_8013F1A0(arg0,M2C_FIELD(arg0,void **,0x48));
M2C_FIELD(arg0,s16 *,0x92)=(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))>>1;
M2C_FIELD(arg0,s16 *,0x94)=0;
M2C_FIELD(arg0,s16 *,0x96)=0;
mid=(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))>>1;
height=M2C_FIELD(arg0,s16 *,0x18)-M2C_FIELD(arg0,s16 *,0x14);
M2C_FIELD(arg0,s16 *,0xBA)=mid;
M2C_FIELD(arg0,s16 *,0xBC)=height;
M2C_FIELD(arg0,s16 *,0xBE)=0;
#pragma cplusplus reset
}

#pragma cplusplus on
extern "C" void *Ui_DtorPanelMid(void *self, s16 doFree) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    typedef struct {
        u32 unk0;
        ListNode node;
    } DtorList;
    typedef struct Owner {
        void *vtbl;
        u8 pad4[0x6C];
        DtorList list;
        u8 pad80[4];
        void *sub84;
        u8 pad88[0x24];
        void *subAC;
    } Owner;
    void fn_8013BA08(void *, void *, void *, void *);
    void fn_8013F2A4(void *, s32);
    void Heap_Free(void *);
    extern u8 gUiPanelMidVtbl[];
    extern u8 gEmptyVtbl[];

    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    Owner *owner;

    /* C++ destructor for UI panel mid base (gUiPanelMidVtbl): destroy embeds, clear list, run base dtor, optional free. */
    owner = (Owner *)self;
    if (self != NULL) {
        owner->vtbl = gUiPanelMidVtbl;
        if (&owner->subAC != NULL) {
            owner->subAC = gEmptyVtbl;
            ((Obj *)&owner->subAC)->v2();
        }
        if (&owner->sub84 != NULL) {
            owner->sub84 = gEmptyVtbl;
            ((Obj *)&owner->sub84)->v2();
        }
        if (&owner->list != NULL) {
            if (&owner->list != NULL) {
                if (&owner->list != NULL) {
                    end = &owner->list.node;
                    sp10 = end;
                    spC = end->next;
                    fn_8013BA08(sp8, &owner->list, &spC, &sp10);
                }
            }
        }
        fn_8013F2A4(self, 0);
        if (doFree > 0) {
            Heap_Free(self);
        }
    }
    return self;
}

extern "C" void fn_8013B8D8(void *arg0) {
#pragma cplusplus reset
void *Heap_Alloc(s32);
void *fn_8013692C(void *,s32,s32,s32,s32,s32);
void fn_8013F0F0(void *,void *);
void fn_8013F1A0(void *,void *);
#pragma cplusplus on
struct Rect {
s16 left,top,right,bottom;
s16 width() { return right-left; }
s16 height() { return bottom-top; }
void set(s16 l,s16 t,s16 r,s16 b) { left=l; top=t; right=r; bottom=b; }
};
void *child;
s16 mid,height;
Rect *outer=(Rect *)((u8 *)arg0+0xA);
Rect *inner=(Rect *)((u8 *)arg0+0x12);
inner->set(2,8,outer->width()-2,outer->height()-8);
M2C_FIELD(arg0,s16 *,0x92)=(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))>>1;
M2C_FIELD(arg0,s16 *,0x94)=0;
M2C_FIELD(arg0,s16 *,0x96)=0;
mid=(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))>>1;
height=M2C_FIELD(arg0,s16 *,0x18)-M2C_FIELD(arg0,s16 *,0x14);
M2C_FIELD(arg0,s16 *,0xBA)=mid;
M2C_FIELD(arg0,s16 *,0xBC)=height;
M2C_FIELD(arg0,s16 *,0xBE)=0;
if(M2C_FIELD(arg0,void **,0x48)) fn_8013F0F0(arg0,M2C_FIELD(arg0,void **,0x48));
child=Heap_Alloc(0x9C);
if(child) child=fn_8013692C(child,(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))-11,0,9,(s16)(M2C_FIELD(arg0,s16 *,0x18)-M2C_FIELD(arg0,s16 *,0x14)),M2C_FIELD(arg0,s16 *,0x22)-5);
M2C_FIELD(arg0,void **,0x48)=child;
M2C_FIELD(M2C_FIELD(arg0,void **,0x48),s32 *,0x48)=1;
fn_8013F1A0(arg0,M2C_FIELD(arg0,void **,0x48));
#pragma cplusplus reset
}

#pragma cplusplus reset

#pragma global_optimizer on
void fn_8013BA08(void **ret, s32 *list, void **start, void **end) {
    struct Node {
        struct Node *prev;
        struct Node *next;
        s32 owner;
        void *obj;
    };
    void fn_800616A0(void *);
    void Heap_Free(void *);
    void **end_p = end;
    void **start_p = start;
    s32 *list_p = list;
    void **ret_p = ret;
    struct Node *first = (struct Node *)*start;
    struct Node *last = (struct Node *)*end;
    struct Node *a;
    struct Node *node;
    void *value;

    if (first == last) {
        *ret_p = last;
        return;
    }
    a = last->prev;
    first->prev->next = a->next;
    a->next->prev = first->prev;
    while ((node = (struct Node *)*start_p) != (struct Node *)*end_p) {
        value = (u8 *)node + 8;
        if (value != NULL && *(void **)((u8 *)value + 4) != NULL) {
            fn_800616A0(*(void **)((u8 *)value + 4));
        }
        node = (struct Node *)*start_p;
        *start_p = node->next;
        Heap_Free(node);
        (*list_p)--;
    }
    *ret_p = *end_p;
}
#pragma global_optimizer reset
void fn_8013BAD4(void **outNode, s32 *listHead, void ***insertBefore, s32 *unitPtr) {
    void *Heap_Alloc(s32);
    void Heap_Free(void *);
    void fprintf(void *, void *, ...);
    void abort(void);
    void fn_800616A0(void *);
    void *GActor_Create(void);
    void fn_800506E0(s32, s32, void *);
    s32 fn_800639B4(void);
    void GActor_Finalize(void *);
    extern char __files[];
    extern char lbl_802768A0[];
    struct Obj {
        u32 flags;
        s32 unk4;
        u8 pad8[0x3C];
        s32 anim;
    };
    struct Value {
        s32 unit;
        struct Obj *actor;
    };
    struct Node {
        struct Node *prev;
        struct Node *next;
        struct Value value;
    };
    struct Holder {
        void *list;
        struct Node *node;
    };
    struct Value *value;
    struct Node *node;
    s32 unit;
    void *list;
    struct Obj *actor;
    struct Node *pos;
    struct Node *n;
    struct Holder h;
    struct Holder *hp;

    list = listHead + 1;
    node = (struct Node *)Heap_Alloc(0x10);
    if (node == 0) {
        fprintf(__files + 0xA0, lbl_802768A0 + 0x47);
        abort();
    }
    hp = &h;
    hp->list = list;
    hp->node = node;
    value = &node->value;
    if (value != 0) {
        unit = *unitPtr;
        value->unit = unit;
        value->actor = 0;
        if (value->actor != 0) {
            fn_800616A0(value->actor);
        }
        value->actor = (struct Obj *)GActor_Create();
        value->actor->unk4 = unit + 0x1C;
        actor = value->actor;
        actor->flags |= 0x50028400;
        fn_800506E0(unit, 0, actor);
        value->actor->anim = fn_800639B4();
        GActor_Finalize(value->actor);
    }
    pos = (struct Node *)*insertBefore;
    n = hp->node;
    hp->node = 0;
    pos->prev->next = n;
    n->prev = pos->prev;
    pos->prev = n;
    n->next = pos;
    (*listHead)++;
    *outNode = n;
    if (hp->node != 0) {
        Heap_Free(hp->node);
    }
}
#pragma use_lmw_stmw reset
int fn_8013BBF8(void *arg0) {
    u32 *ptr;

    ptr = (u32 *)((u8 *)arg0 + 0x4);
    *(u32 *)arg0 = 0;
    ptr[1] = (u32)ptr;
    ptr[0] = (u32)ptr;
}

#pragma push
#pragma optimization_level 2
void *fn_8013BC10(void *arg0, void *arg1)
{
  void *Heap_Alloc(s32);
  extern u8 lbl_80276908[];
  extern u8 lbl_8028459C[];
  extern u8 gUiMenuDrawVtbl[];
  extern u8 lbl_80291BE0[];
  extern u8 lbl_80291BEC[];
  extern u8 lbl_80291CF8[];
  extern u8 lbl_80291DA0[];
  extern u8 lbl_80291E48[];
  extern u8 lbl_80291EAC[];
  f32 new_var;
  extern u8 lbl_80292090[];
  extern u8 lbl_802920E0[];
  extern u8 lbl_8032FEF0[];
  extern u8 lbl_8032FEFC[];
  extern u8 lbl_80367AD4;
  extern u8 lbl_80367AD5;
  extern f32 lbl_8036A6B8;
  extern f32 lbl_8036A6BC;
  void *obj;
  if (((s8) lbl_80367AD4) == 0)
  {
    *((void **) lbl_8032FEF0) = lbl_8028459C;
    *((void **) lbl_8032FEF0) = lbl_80292090;
    *((void **) lbl_8032FEF0) = lbl_80291BEC;
    *((void **) (lbl_8032FEF0 + 4)) = lbl_80276908 + 0x46;
    lbl_8032FEF0[8] = 2;
    lbl_8032FEF0[9] = 0;
    *((void **) lbl_8032FEF0) = lbl_80291EAC;
    lbl_80367AD4 = 1;
  }
  if (((s8) lbl_80367AD5) == 0)
  {
    *((void **) lbl_8032FEFC) = lbl_8028459C;
    *((void **) lbl_8032FEFC) = lbl_80292090;
    *((void **) lbl_8032FEFC) = lbl_80291BEC;
    *((void **) (lbl_8032FEFC + 4)) = lbl_80276908 + 0x4E;
    lbl_8032FEFC[8] = 2;
    lbl_8032FEFC[9] = 0;
    *((void **) lbl_8032FEFC) = lbl_80291E48;
    lbl_80367AD5 = 1;
  }
  *((void **) (lbl_8032FEF0 + 4)) = (arg0) ? (arg0) : (lbl_80276908 + 0x46);
  *((void **) (lbl_8032FEFC + 4)) = (arg1) ? (arg1) : (lbl_80276908 + 0x4E);
  lbl_8032FEF0[8] = 1;
  lbl_8032FEFC[8] = 1;
  lbl_8032FEF0[9] |= 1;
  lbl_8032FEFC[9] |= 1;
  obj = Heap_Alloc(0x28);
  if (obj != NULL)
  {
    *((void **) (((u8 *) obj) + 4)) = gUiMenuDrawVtbl;
    *((void **) obj) = lbl_80291BE0;
    *((void **) (((u8 *) obj) + 4)) = lbl_802920E0;
    *((s16 *) (((u8 *) obj) + 8)) = 0x80;
    *((s16 *) (((u8 *) obj) + 0xA)) = 0x9C;
    *((s16 *) (((u8 *) obj) + 0xC)) = 0x160;
    *((s16 *) (((u8 *) obj) + 0xE)) = 0x88;
    *((s16 *) (((u8 *) obj) + 0x10)) = 0;
    *((s16 *) (((u8 *) obj) + 0x12)) = 0;
    *((s16 *) (((u8 *) obj) + 0x14)) = 0;
    *((s16 *) (((u8 *) obj) + 0x16)) = 0;
    *((f32 *) (((u8 *) obj) + 0x18)) = lbl_8036A6B8;
    *((s16 *) (((u8 *) obj) + 0x1C)) = 0x20;
    *((s16 *) (((u8 *) obj) + 0x1E)) = 4;
    *((void **) (((u8 *) obj) + 4)) = lbl_80291DA0;
    *((s32 *) (((u8 *) obj) + 0x20)) = 0;
    *((s8 *) (((u8 *) obj) + 0x24)) = 0;
    *((void **) (((u8 *) obj) + 4)) = lbl_80291CF8;
    *((s16 *) (((u8 *) obj) + 0xE)) = 0x1C;
    new_var = lbl_8036A6BC;
    *((s16 *) (((u8 *) obj) + 0xC)) = 0xC8;
    *((f32 *) (((u8 *) obj) + 0x18)) = new_var;
    *((s16 *) (((u8 *) obj) + 0x10)) = 0;
    *((s16 *) (((u8 *) obj) + 0x12)) = 0;
  }
  return obj;
}
#pragma pop
void fn_8013BE3C(s32 arg0) {
void *Heap_Alloc(s32);
extern u8 lbl_80276908[],lbl_8028459C[],lbl_80291BD4[],lbl_80291BEC[],lbl_80291DA0[],lbl_80291E48[],lbl_80291EAC[],lbl_80292090[],lbl_802920E0[],gUiMenuDrawVtbl[],lbl_80291C50[];
extern u8 lbl_8032FED8[],lbl_8032FEE4[];
extern s8 lbl_80367AD2,lbl_80367AD3;
extern f32 lbl_8036A6B8;
void *p;
if(!lbl_80367AD2) {
M2C_FIELD(lbl_8032FED8,void **,0)=lbl_8028459C;
M2C_FIELD(lbl_8032FED8,void **,0)=lbl_80292090;
M2C_FIELD(lbl_8032FED8,void **,0)=lbl_80291BEC;
M2C_FIELD(lbl_8032FED8,void **,4)=lbl_80276908+70;
M2C_FIELD(lbl_8032FED8,u8 *,8)=2;
M2C_FIELD(lbl_8032FED8,u8 *,9)=0;
M2C_FIELD(lbl_8032FED8,void **,0)=lbl_80291EAC;
lbl_80367AD2=1;
}
if(!lbl_80367AD3) {
M2C_FIELD(lbl_8032FEE4,void **,0)=lbl_8028459C;
M2C_FIELD(lbl_8032FEE4,void **,0)=lbl_80292090;
M2C_FIELD(lbl_8032FEE4,void **,0)=lbl_80291BEC;
M2C_FIELD(lbl_8032FEE4,void **,4)=lbl_80276908+78;
M2C_FIELD(lbl_8032FEE4,u8 *,8)=2;
M2C_FIELD(lbl_8032FEE4,u8 *,9)=0;
M2C_FIELD(lbl_8032FEE4,void **,0)=lbl_80291E48;
lbl_80367AD3=1;
}
p=Heap_Alloc(0x28);
if(p){
M2C_FIELD(p,void **,4)=gUiMenuDrawVtbl;
M2C_FIELD(p,void **,0)=lbl_80291BD4;
M2C_FIELD(p,void **,4)=lbl_802920E0;
M2C_FIELD(p,s16 *,8)=128;
M2C_FIELD(p,s16 *,10)=156;
M2C_FIELD(p,s16 *,12)=352;
M2C_FIELD(p,s16 *,14)=136;
M2C_FIELD(p,s16 *,16)=0;
M2C_FIELD(p,s16 *,18)=0;
M2C_FIELD(p,s16 *,20)=0;
M2C_FIELD(p,s16 *,22)=0;
M2C_FIELD(p,f32 *,24)=10.0f;
M2C_FIELD(p,s16 *,28)=32;
M2C_FIELD(p,s16 *,30)=4;
M2C_FIELD(p,void **,4)=lbl_80291DA0;
M2C_FIELD(p,s32 *,32)=0;
M2C_FIELD(p,u8 *,36)=0;
M2C_FIELD(p,void **,4)=lbl_80291C50;
M2C_FIELD(p,s16 *,12)=272;
M2C_FIELD(p,s16 *,14)=128;
M2C_FIELD(p,s16 *,8)=168;
M2C_FIELD(p,s16 *,10)=160;
}
M2C_FIELD(p,s32 *,32)=arg0;
}

void fn_8013BFFC(s32 arg0) {
void *Heap_Alloc(s32);
extern u8 lbl_80276908[],lbl_8028459C[],lbl_80291BC8[],lbl_80291BEC[],lbl_80291DA0[],lbl_80291E48[],lbl_80291EAC[],lbl_80292090[],lbl_802920E0[],gUiMenuDrawVtbl[];
extern u8 lbl_8032FEC0[],lbl_8032FECC[];
extern s8 lbl_80367AD0,lbl_80367AD1;
extern f32 lbl_8036A6B8;
void *p;
if(!lbl_80367AD0) {
M2C_FIELD(lbl_8032FEC0,void **,0)=lbl_8028459C;
M2C_FIELD(lbl_8032FEC0,void **,0)=lbl_80292090;
M2C_FIELD(lbl_8032FEC0,void **,0)=lbl_80291BEC;
M2C_FIELD(lbl_8032FEC0,void **,4)=lbl_80276908+70;
M2C_FIELD(lbl_8032FEC0,u8 *,8)=2;
M2C_FIELD(lbl_8032FEC0,u8 *,9)=0;
M2C_FIELD(lbl_8032FEC0,void **,0)=lbl_80291EAC;
lbl_80367AD0=1;
}
if(!lbl_80367AD1) {
M2C_FIELD(lbl_8032FECC,void **,0)=lbl_8028459C;
M2C_FIELD(lbl_8032FECC,void **,0)=lbl_80292090;
M2C_FIELD(lbl_8032FECC,void **,0)=lbl_80291BEC;
M2C_FIELD(lbl_8032FECC,void **,4)=lbl_80276908+78;
M2C_FIELD(lbl_8032FECC,u8 *,8)=2;
M2C_FIELD(lbl_8032FECC,u8 *,9)=0;
M2C_FIELD(lbl_8032FECC,void **,0)=lbl_80291E48;
lbl_80367AD1=1;
}
p=Heap_Alloc(0x28);
if(p){
M2C_FIELD(p,void **,4)=gUiMenuDrawVtbl;
M2C_FIELD(p,void **,0)=lbl_80291BC8;
M2C_FIELD(p,void **,4)=lbl_802920E0;
M2C_FIELD(p,s16 *,8)=128;
M2C_FIELD(p,s16 *,10)=156;
M2C_FIELD(p,s16 *,12)=352;
M2C_FIELD(p,s16 *,14)=136;
M2C_FIELD(p,s16 *,16)=0;
M2C_FIELD(p,s16 *,18)=0;
M2C_FIELD(p,s16 *,20)=0;
M2C_FIELD(p,s16 *,22)=0;
M2C_FIELD(p,f32 *,24)=10.0f;
M2C_FIELD(p,s16 *,28)=32;
M2C_FIELD(p,s16 *,30)=4;
M2C_FIELD(p,void **,4)=lbl_80291DA0;
M2C_FIELD(p,s32 *,32)=0;
M2C_FIELD(p,u8 *,36)=0;
}
M2C_FIELD(p,s32 *,32)=arg0;
}

#pragma cplusplus on
extern "C" void fn_8013C194(void *self, void *arg1, void *slot) {
void Prim2D_Begin(void); void Prim2D_SetTex(s32,s32); void Prim2D_PrepareTex(void); void Prim2D_AddPrim(s32); void Prim2D_SetPos(f32,f32); void Prim2D_SetColorPacked(s32*); void Prim2D_SetTextScale(s32,f32); void fn_800071D8(s32,f32); void Prim2D_SetText(void*); void Prim2D_EndPrim(void);
s32 Text_MeasureWidth(void*,s32,f32); s32 fn_80010770(void*,s32,f32); s32 *Ui_GetColor(s32);
extern f32 lbl_8036A6C0;
s32 color;
f32 x = (f32)M2C_FIELD(slot,s16*,0x30);
f32 y = (f32)M2C_FIELD(slot,s16*,0x32);
void *obj = M2C_FIELD(arg1,void**,0x3c);
s32 h;
x -= (f32)(Text_MeasureWidth(((MenuCenteredLabel*)self)->getText(),-1,lbl_8036A6C0)/2);
h = (s16)((MenuCenteredPanel*)obj)->height();
y += (f32)((h-fn_80010770(((MenuCenteredLabel*)self)->getText(),-1,lbl_8036A6C0))/2);
Prim2D_Begin(); Prim2D_SetTex(0,0x13); Prim2D_PrepareTex(); Prim2D_AddPrim(6); Prim2D_SetPos(x,y);
color=*Ui_GetColor(M2C_FIELD(self,u8*,8)); Prim2D_SetColorPacked(&color);
if(((MenuCenteredLabel*)self)->test(1)) Prim2D_SetTextScale(1,gUiMenuSlotPlainTextScale);
else if(((MenuCenteredLabel*)self)->test(2)) fn_800071D8(1,lbl_8036A6C0);
Prim2D_SetText(((MenuCenteredLabel*)self)->getText()); Prim2D_EndPrim();
}
#pragma cplusplus reset
void fn_8013C388(void *arg0) {
    M2C_UNK Msg_Expand(s32);
    Msg_Expand(M2C_FIELD(arg0, s32 *, 4));
}

s32 fn_8013C3AC(void) {
    return 0;
}

#pragma cplusplus on
extern "C" void fn_8013C3B4(void *unused, void *arg1) {
    void *GfxEnt_Get(u8);
    s32 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoText(void *, void *, f32, f32);
    void Ui_PlaySeCue(void *, s32);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 gUnitInfoPopup[];
    extern u8 lbl_80276908[];
    extern f64 lbl_8036A6C8;
    struct Inner {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void *v2() = 0;
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
        virtual void v13() = 0;
        virtual void v14(void *, void *) = 0;
        virtual void v15(void *, void *) = 0;
    };
    s32 gate;
    s32 flags;
    s32 btn;
    s32 cur;
    void *pad;
    f32 f31;
    f32 f30;
    void *tmp;
    void *res;
    u8 *p;

    flags = gUiInputFlags;
    gate = 0;
    if ((flags & 0x10) && !(flags & 0x20)) {
        gate = 1;
    }
    if ((u8)gate == 0) {
        u8 prevCursor;
        s32 prevButtons;
        pad = gPadInput;
        prevCursor = *(u8 *)((u8 *)arg1 + 0x62);
        cur = *(s32 *)((u8 *)pad + 4);
        prevButtons = *(s32 *)((u8 *)pad + 8);
        *(u8 *)((u8 *)arg1 + 0x63) = prevCursor;
        btn = cur & (prevButtons ^ cur);
        if ((s8)*(u8 *)((u8 *)arg1 + 0x62) != 0) {
            if ((btn & 0x01000001) != 0) {
                *(u8 *)((u8 *)arg1 + 0x62) = *(u8 *)((u8 *)arg1 + 0x62) - 1;
            }
        }
        if ((s8)*(u8 *)((u8 *)arg1 + 0x62) != ((s8)*(u8 *)((u8 *)arg1 + 0x60) - 1)) {
            if ((btn & 0x02000002) != 0) {
                *(u8 *)((u8 *)arg1 + 0x62) = *(u8 *)((u8 *)arg1 + 0x62) + 1;
            }
        }
        if ((s8)*(u8 *)((u8 *)arg1 + 0x62) != (s8)*(u8 *)((u8 *)arg1 + 0x63)) {
            if ((u8)Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
                p = (u8 *)arg1;
                p += (s8)*(u8 *)((u8 *)arg1 + 0x62);
                tmp = GfxEnt_Get(p[0x40]);
                f31 = (f32)(*(s16 *)((u8 *)arg1 + 0x30) + *(s16 *)((u8 *)tmp + 0x30));
                p = (u8 *)arg1;
                p += (s8)*(u8 *)((u8 *)arg1 + 0x62);
                tmp = GfxEnt_Get(p[0x40]);
                f30 = (f32)(*(s16 *)((u8 *)arg1 + 0x32) + *(s16 *)((u8 *)tmp + 0x32));
                p = (u8 *)arg1;
                p += (s8)*(u8 *)((u8 *)arg1 + 0x62);
                tmp = GfxEnt_Get(p[0x40]);
                res = (*(Inner **)((u8 *)tmp + 0x34))->v2();
                if (res != NULL) {
                    Ui_ShowUnitInfoText(gUnitInfoPopup, res, f31, f30);
                }
            }
        }
        if (*(s8 *)((u8 *)arg1 + 0x62) != *(s8 *)((u8 *)arg1 + 0x63)) {
            p = (u8 *)arg1;
            p += *(s8 *)((u8 *)arg1 + 0x63);
            tmp = GfxEnt_Get(p[0x40]);
            (*(Inner **)((u8 *)tmp + 0x34))->v15(arg1, tmp);
            p = (u8 *)arg1;
            p += *(s8 *)((u8 *)arg1 + 0x62);
            tmp = GfxEnt_Get(p[0x40]);
            (*(Inner **)((u8 *)tmp + 0x34))->v14(arg1, tmp);
            Ui_PlaySeCue(lbl_80276908 + 0x56, 0x64);
        }
    }
}
#pragma cplusplus reset

#pragma push
#pragma optimization_level 4
#pragma opt_lifetimes off
#pragma cplusplus on
extern "C" void fn_8013C600(void *arg0, void *arg1) {
    struct Inner {
        virtual void v0() = 0;
        virtual s32 v1() = 0;
    };
    struct Outer {
        u8 pad[4];
        virtual s32 v0() = 0;
        virtual s32 v1() = 0;
        virtual s32 v2() = 0;
        virtual s32 v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        virtual s32 v6() = 0;
        virtual s32 v7() = 0;
        virtual s32 v8() = 0;
        virtual s32 v9() = 0;
        virtual s32 v10() = 0;
        virtual s32 v11() = 0;
        virtual s32 v12() = 0;
        virtual s32 v13() = 0;
        virtual s32 v14() = 0;
        virtual s32 v15() = 0;
        virtual s32 v16() = 0;
        virtual s32 v17() = 0;
        virtual s32 v18() = 0;
        virtual s32 v19() = 0;
        virtual s32 v20() = 0;
        virtual s32 v21() = 0;
        virtual s32 v22() = 0;
        virtual s32 v23() = 0;
        virtual s32 v24() = 0;
        virtual s32 v25() = 0;
        virtual s32 v26() = 0;
        virtual s32 v27() = 0;
        virtual s32 v28() = 0;
        virtual s32 v29() = 0;
        virtual s32 v30() = 0;
        virtual s32 v31() = 0;
        virtual s32 v32() = 0;
        virtual s32 v33() = 0;
        virtual s32 v34() = 0;
        virtual s32 v35() = 0;
        virtual s32 v36() = 0;
        virtual s32 v37() = 0;
        virtual s32 v38() = 0;
        virtual s32 v39() = 0;
        virtual s32 v40() = 0;
        virtual s32 v41() = 0;
        virtual s32 v42() = 0;
    };
    void *GfxEnt_Get(u8);
    s32 Text_MeasureHeight(s32, f32);
    s32 Text_MeasureWidth(s32, s32, f32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Ui_DrawRouteIconEx(s16, s32, s32);
    void fn_8008AB7C(s32, s32, s16, s32, s32, s32, s32);
    extern f32 lbl_8036A6C0;
    extern f32 lbl_8036A6D0;
    extern f64 lbl_8036A6C8;
    extern const f32 lbl_8036A6D4;
    extern f32 lbl_8036A6D8;
    extern f32 lbl_8036A6DC;
    s32 iconH;
    s32 iconW;
    s32 flag;
    s32 v;
    s16 t3a;
    s16 t38;
    s32 halfW;
    s16 w;
    s16 x;
    void *item;
    void *self;
    u8 *a1;
    f32 scaled;
    f32 sum;
    s16 y;
    s16 v38;
    s16 y3a;

    self = arg0;
    a1 = (u8 *)arg1;
    item = GfxEnt_Get(a1[0x40 + (s8)a1[0x62]]);
    x = *(s16 *)((u8 *)item + 0x30);
    y = *(s16 *)((u8 *)item + 0x32);
    w = (s16)Text_MeasureHeight(-1, lbl_8036A6C0);
    v = ((Inner *)*(void **)((u8 *)item + 0x34))->v1();
    halfW = (s16)Text_MeasureWidth(v, -1, lbl_8036A6C0);
    x = (s16)(x - (halfW / 2));
    t38 = *(s16 *)(a1 + 0x38);
    if (t38 < 0 || *(s16 *)(a1 + 0x3a) < 0) {
        *(s16 *)(a1 + 0x38) = x;
        *(s16 *)(a1 + 0x3a) = y;
    } else {
        *(s16 *)(a1 + 0x38) = (s16)((t38 + x) / 2);
        t3a = *(s16 *)(a1 + 0x3a);
        *(s16 *)(a1 + 0x3a) = (s16)((t3a + y) / 2);
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A6D0);
    Prim2D_PrepareTex();
    v38 = (s16)((Outer *)self)->v38();
    scaled = (f32)(v38 - w) * lbl_8036A6D4;
    y3a = *(s16 *)(a1 + 0x3a);
    sum = scaled + (f32)y3a;
    Ui_DrawRouteIconEx(*(s16 *)(a1 + 0x38), (s32)sum, 1);
    if (*(u8 *)((u8 *)self + 0x24) != 0) {
        iconW = ((Outer *)self)->v35();
        iconH = ((Outer *)self)->v20();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A6D8);
        Prim2D_PrepareTex();
        flag = 0;
        if (a1[0x2d] == 0 && a1[0x2e] == 0) {
            flag = 1;
        }
        fn_8008AB7C(*(s16 *)(a1 + 0x38) + (halfW >> 1),
            *(s16 *)(a1 + 0x3a) + ((s16)iconH >> 1),
            iconW, 0x18, 0x19, 0x4c, flag);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036A6DC);
        Prim2D_PrepareTex();
    }
}
#pragma pop
#pragma cplusplus on
#pragma push
#pragma optimization_level 3
extern "C" void fn_8013C814(void *arg0) {
    struct Outer {
        u8 pad[4];
        virtual s32 v0() = 0;
        virtual s32 v1() = 0;
        virtual s32 v2() = 0;
        virtual s32 v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        virtual s32 v6() = 0;
        virtual s32 v7() = 0;
        virtual s32 v8() = 0;
        virtual s32 v9() = 0;
        virtual s32 v10() = 0;
        virtual s32 v11() = 0;
        virtual s32 v12() = 0;
        virtual s32 v13() = 0;
        virtual s32 v14() = 0;
        virtual s32 v15() = 0;
        virtual s32 v16() = 0;
        virtual s32 v17() = 0;
        virtual s32 v18() = 0;
        virtual s32 v19() = 0;
        virtual s32 v20() = 0;
        virtual s32 v21() = 0;
        virtual s32 v22() = 0;
        virtual s32 v23() = 0;
        virtual s32 v24() = 0;
        virtual s32 v25() = 0;
        virtual s32 v26() = 0;
        virtual s32 v27() = 0;
        virtual s32 v28() = 0;
        virtual s32 v29() = 0;
        virtual s32 v30() = 0;
        virtual s32 v31() = 0;
        virtual s32 v32() = 0;
        virtual s32 v33() = 0;
        virtual s32 v34() = 0;
        virtual s32 v35() = 0;
        virtual s32 v36() = 0;
        virtual s32 v37() = 0;
        virtual s32 v38() = 0;
        virtual s32 v39() = 0;
    };
    void *fn_8000E0E4(void *);
    void fn_8000A258(void);
    void fn_80009C0C(f32);
    void fn_8000A174(s32, s32);
    void fn_8000A248(void);
    s32 fn_80010B78(void *, s32, f32);
    s32 fn_800102BC(s32, f32);
    void fn_80007898(s32);
    void fn_80007858(f32, f32);
    void fn_800076AC(s32, s32, s32, s32);
    void fn_80007124(void *);
    void fn_80007884(void);
    void fn_80009B80(s32);
    extern u8 lbl_80276908[];
    extern f32 lbl_8036A6C0;
    extern f32 lbl_8036A6D0;
    extern f32 lbl_8036A6C8;
    f32 f31;
    f32 f30;
    void *v36v;
    void *ptr;
    Outer *self;
    s32 half;

    self = (Outer *)arg0;
    v36v = 0;
    self->v39();
    if (*(u32 *)((u8 *)self + 0x20) != 0) {
        ptr = fn_8000E0E4(*(void **)((u8 *)self + 0x20));
    } else {
        ptr = &lbl_80276908[0x72];
    }
    if (ptr != 0) {
        fn_8000A258();
        fn_80009C0C(lbl_8036A6D0);
        fn_8000A174(0, 0x13);
        fn_8000A248();
        if (*(u32 *)((u8 *)self + 0x20) != 0) {
            ptr = fn_8000E0E4(*(void **)((u8 *)self + 0x20));
        } else {
            ptr = &lbl_80276908[0x72];
        }
        half = (s16)self->v18() / 2;
        f31 = (f32)(half - (fn_80010B78(ptr, -1, lbl_8036A6C0) / 2));
        half = ((s16)self->v38() - fn_800102BC(-1, lbl_8036A6C0)) / 2;
        v36v = (void *)(s32)(s16)self->v36();
        f30 = (f32)(half + ((s16)(s32)v36v - (s16)self->v38()));
        fn_80007898(6);
        fn_80007858(f31, f30);
        fn_800076AC(0, 0, 0, 0xff);
        if (*(u32 *)((u8 *)self + 0x20) != 0) {
            ptr = fn_8000E0E4(*(void **)((u8 *)self + 0x20));
        } else {
            ptr = &lbl_80276908[0x72];
        }
        fn_80007124(ptr);
        fn_80007884();
    }
    fn_8000A258();
    fn_80009B80(0x80);
    fn_8000A248();
}
#pragma pop

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
struct RefObj {
    virtual ~RefObj();
    s32 refCount;
};
extern "C" void Ui_DrawAtlasRect75(s32, s32, s32);

extern "C" void fn_8013CA2C(void *arg0) {
    struct Obj {
        u8 pad[4];
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
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual void v18() = 0;
        virtual void v19() = 0;
        virtual void v20() = 0;
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual void v25() = 0;
        virtual void v26() = 0;
        virtual void v27() = 0;
        virtual void v28() = 0;
        virtual void v29() = 0;
        virtual void v30() = 0;
    };
    ((Obj *)arg0)->v30();
    Ui_DrawAtlasRect75(0, 0, 0x10);
}

extern "C" void fn_8013CA68(void *arg0, void *arg1) {
    struct Obj {
        u8 pad[4];
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
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual s16 getW() = 0;
        virtual s16 getH() = 0;
        virtual void v20() = 0;
        virtual s16 getX() = 0;
        virtual s16 getY() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual f32 getZ() = 0;
    };
    f32 UiWin_GetFade(void *);
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void fn_80009C20(f32, f32, f32, f32, f32, f32, f32, f32);
    void Prim2D_Begin(void);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetAlphaByte(s32);
    void Prim2D_PrepareTex(void);

    f32 fade, scale;
    u8 focused, alpha;
    void *o;

    fade = UiWin_GetFade(arg1);
    scale = Math_Ease(5, 0.0f, 1.0f, fade, 1.0f);
    Prim2D_Begin();
    o = arg0;
    fn_80009C20(
        ((Obj *)o)->getX(),
        ((Obj *)o)->getY(),
        ((Obj *)o)->getZ(),
        ((Obj *)o)->getW() / 2,
        ((Obj *)o)->getH() / 2,
        scale,
        scale,
        0.0f
    );
    Prim2D_SetColorByte((s32)(255.99f * fade));
    focused = 0;
    if (*((u8 *)arg1 + 0x2D) == 0 && *((u8 *)arg1 + 0x2E) == 0) {
        focused = 1;
    }
    alpha = 0x40;
    if (focused) {
        alpha = 0x80;
    }
    Prim2D_SetAlphaByte(alpha);
    Prim2D_PrepareTex();
}

#pragma cplusplus on
/* Space each child gfx ent evenly across parent width (v18); y = panel v37-v38. */
extern "C" void Ui_LayoutChildGfxEnts(void *panel, void *group) {
    struct Obj {
        u8 pad[4];
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
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual s32 v16() = 0;
        virtual void v17() = 0;
        virtual s16 v18() = 0;
        virtual void v19() = 0;
        virtual void v20() = 0;
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual void v25() = 0;
        virtual void v26() = 0;
        virtual void v27() = 0;
        virtual void v28() = 0;
        virtual void v29() = 0;
        virtual void v30() = 0;
        virtual void v31() = 0;
        virtual void v32() = 0;
        virtual void v33() = 0;
        virtual void v34() = 0;
        virtual void v35() = 0;
        virtual void v36() = 0;
        virtual s32 v37() = 0;
        virtual s32 v38() = 0;
    };
    void *GfxEnt_Get(u8);
    s32 i;
    void *ent;
    s16 step;
    s16 width;
    u8 *g = (u8 *)group;

    for (i = 0; i < (s8)g[0x60]; i++) {
        ent = GfxEnt_Get(g[0x40 + i]);
        width = (*(Obj **)(g + 0x3C))->v18();
        step = (s16)(width / ((s8)g[0x60] + 1));
        *(s16 *)((u32)ent + 0x30) = (i + 1) * step + (*(Obj **)(g + 0x3C))->v16();
        *(s16 *)((u32)ent + 0x32) = ((Obj *)panel)->v37() - ((Obj *)panel)->v38();
    }
}
#pragma cplusplus reset

#pragma cplusplus reset
void fn_8013CD7C(void)
{
    extern u8 gUiContext[24];
    gUiContext[8] = 0x80;
}

#pragma optimization_level 2
#pragma scheduling on

