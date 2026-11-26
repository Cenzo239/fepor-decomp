/* Functions from 0x800A39F8 to 0x800A9384, found by decomp-toolkit. */
#include "common.h"

static inline s32 Movie_FrameDataOffset(u32 count) {
    return count * 4 + 8;
}

static inline s32 Movie_FrameData(void *base, s32 offset) {
    return (s32)base + offset;
}

static inline s32 Movie_DecodeFrame(s32 data, u8 *state) {
    s32 fn_8023C56C(s32, s32, s32, s32, s32);
    extern u8 lbl_803123A0[];
    if (fn_8023C56C(data, *(s32 *)(state + 0x14C), *(s32 *)(state + 0x150), *(s32 *)(state + 0x154), *(s32 *)(state + 0x9C)) == 0) {
        *(s32 *)(state + 0x158) = *(s32 *)(lbl_803123A0 + *(s32 *)(state + 0xB4) * 12 + 0xD8);
        return 1;
    }
    return 0;
}
extern u8 lbl_8028C750[16];
extern u16 lbl_8026E408[];
extern void strcat(void *, s32);
extern void strcpy(void *, void *, void *);
extern u8 lbl_80312A80[0x30];


extern s32 lbl_803677A4;
void *fn_800A39F8(void) {
    extern u8 lbl_8026E168[];
    return lbl_8026E168;
}

s32 fn_800A3A04(s32 arg0, s32 arg1) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    Ui_CreateMenu(&lbl_803677A4, arg1, 0);
    return 0;
}

void *fn_800A3A30(void) {
    extern u8 lbl_8026E168[];
    return &lbl_8026E168[0x2E];
}

s32 fn_800A3A40(s32 arg0, s32 arg1) {
    M2C_UNK fn_8007982C(s32);
    fn_8007982C(arg1);
    return 0;
}

s32 fn_800A3A68(s32 arg0, s32 arg1) {
    struct G {
        u8 pad[0xA0];
        s32 f_A0;
        u8 f_A4, f_A5, f_A6, f_A7;
        u8 pad3[0x1C];
        f32 f_C4, f_C8, f_CC;
        s32 f_D0;
    };
    extern struct G lbl_803123A0;
    extern f64 lbl_80369A18;
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    u32 fn_802139F4(void);
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;
    s32 intr;
    f32 temp_f1;
    s32 temp_r4;
    u32 tmp;

    var_r30 = arg1;
    var_r29 = arg0;
    if (lbl_803123A0.f_A0 != 0 && lbl_803123A0.f_A7 != 0) {
        tmp = fn_802139F4();
        var_r31 = 0x30;
        if (tmp == 0) {
            var_r31 = 0x20;
        }
        if (var_r29 > 0x7F) {
            var_r29 = 0x7F;
        }
        if (var_r29 < 0) {
            var_r29 = 0;
        }
        if (var_r30 > 0xEA60) {
            var_r30 = 0xEA60;
        }
        if (var_r30 < 0) {
            var_r30 = 0;
        }
        intr = OSDisableInterrupts();
        temp_f1 = (f32)var_r29;
        lbl_803123A0.f_C8 = temp_f1;
        if (var_r30 != 0) {
            temp_r4 = var_r31 * var_r30;
            lbl_803123A0.f_D0 = temp_r4;
            temp_f1 = (temp_f1 - lbl_803123A0.f_C4) / (f32)temp_r4;
            lbl_803123A0.f_CC = temp_f1;
        } else {
            lbl_803123A0.f_C4 = temp_f1;
            lbl_803123A0.f_D0 = 0;
        }
        OSRestoreInterrupts(intr);
        return 1;
    }
    return 0;
}

void fn_800A3B90(void) {
extern s32 lbl_803677C4,lbl_803677B4;
extern u32 lbl_803677BC,lbl_803677C0,lbl_803677B8;
extern u8 lbl_80312580[];
void fn_80213760(void *,u32);
u32 fn_80213800(void);
void fn_800A3DBC(void *,u32,s32);
s32 OSEnableInterrupts(void);
void OSRestoreInterrupts(s32);
void DCFlushRange(void *,u32);
void DCInvalidateRange(u32,u32);
s32 interrupts;
if(lbl_803677C4==0){
lbl_803677B4^=1;
fn_80213760(lbl_80312580+lbl_803677B4*0x280,0x280);
interrupts=OSEnableInterrupts();
fn_800A3DBC(lbl_80312580+lbl_803677B4*0x280,0,0xA0);
DCFlushRange(lbl_80312580+lbl_803677B4*0x280,0x280);
OSRestoreInterrupts(interrupts);
return;
}
if(lbl_803677C4==1){
if(lbl_803677BC!=0) lbl_803677C0=lbl_803677BC;
((void (*)(void))lbl_803677B8)();
lbl_803677BC=fn_80213800()+0x80000000;
}else{
((void (*)(void))lbl_803677B8)();
lbl_803677C0=fn_80213800()+0x80000000;
}
lbl_803677B4^=1;
fn_80213760(lbl_80312580+lbl_803677B4*0x280,0x280);
interrupts=OSEnableInterrupts();
if(lbl_803677C0!=0) DCInvalidateRange(lbl_803677C0,0x280);
fn_800A3DBC(lbl_80312580+lbl_803677B4*0x280,lbl_803677C0,0xA0);
DCFlushRange(lbl_80312580+lbl_803677B4*0x280,0x280);
OSRestoreInterrupts(interrupts);
}

s32 fn_800A3D08(void) {
    extern u8 lbl_803123A0[];
    if (*(s32 *)(lbl_803123A0 + 0xA0) != 0) {
        return *(s32 *)(lbl_803123A0 + 0x50);
    }
    return 0;
}

s32 fn_800A3D2C(void *dst) {
    extern u8 lbl_803123A0[];
    u8 *p;

    p = lbl_803123A0;
    if (*(s32 *)(p + 0xA0) != 0) {
        memcpy(dst, p + 0x8C, 0x10);
        return 1;
    }
    return 0;
}

s32 fn_800A3D74(void *dst) {
    extern u8 lbl_803123A0[];
    u8 *p;

    p = lbl_803123A0;
    if (*(s32 *)(p + 0xA0) != 0) {
        memcpy(dst, p + 0x80, 0xC);
        return 1;
    }
    return 0;
}

void fn_800A3DBC(s16 *arg0, s16 *arg1, u32 arg2) {
    u32 fn_802097D4(void);
    void memcpy(void *, void *, u32);
    void memset(void *, s32, u32);
    extern u16 lbl_8028C578[];

    struct State {
        u8 pad0[0xA0];
        s32 flagA0;
        u8 padA4;
        u8 a5;
        u8 padA6;
        u8 a7;
        u8 padA8[0xC4 - 0xA8];
        f32 c4;
        f32 c8;
        f32 cc;
        s32 d0;
        u8 padD4[0x160 - 0xD4];
        struct {
            s16 *ptr;
            u32 remain;
            u32 pad;
        } slots[3];
        s32 slotIdx;
    };
    extern struct State lbl_803123A0;

    s16 *var_r31;
    u8 var_r30;
    u32 var_r29;
    s16 *var_r28;
    s16 *out;
    s16 *in;
    u32 left;
    u32 n;
    s16 *ring;
    s32 vol;
    s32 samp;
    s32 i;
    u32 var_ctr;
    u16 *table;
    struct State *p;

    var_r31 = arg0;
    var_r30 = 0;
    var_r29 = arg2;
    var_r28 = arg1;

    if (fn_802097D4() == 0) {
        var_r30 = 1;
    }

    if (var_r28 != NULL) {
        p = &lbl_803123A0;
        if (p->flagA0 != 0 && p->a5 == 1 && p->a7 != 0) {
            table = lbl_8028C578;
            left = var_r29;
            out = var_r31;
            in = var_r28;
            while (1) {
                n = p->slots[p->slotIdx].remain;
                if (n != 0) {
                    if (n >= left) {
                        n = left;
                    }
                    ring = p->slots[p->slotIdx].ptr;
                    for (var_ctr = n; var_ctr != 0; var_ctr--) {
                        if (p->d0 != 0) {
                            p->d0 = p->d0 - 1;
                            p->c4 = p->c4 + p->cc;
                        } else {
                            p->c4 = p->c8;
                        }
                        vol = table[(s32)p->c4];
                        samp = in[0] + ((s32)(vol * ring[0]) >> 15);
                        if (samp < -0x8000) {
                            samp = -0x8000;
                        }
                        if (samp > 0x7FFF) {
                            samp = 0x7FFF;
                        }
                        out[0] = (s16)samp;
                        samp = in[1] + ((s32)(vol * ring[1]) >> 15);
                        if (samp < -0x8000) {
                            samp = -0x8000;
                        }
                        if (samp > 0x7FFF) {
                            samp = 0x7FFF;
                        }
                        out[1] = (s16)samp;
                        out += 2;
                        in += 2;
                        ring += 2;
                        if (var_r30) {
                            samp = (s32)(table[0x64] * (out[-1] + out[-2])) >> 15;
                            if (samp < -0x8000) {
                                samp = -0x8000;
                            }
                            if (samp > 0x7FFF) {
                                samp = 0x7FFF;
                            }
                            out[-2] = (s16)samp;
                            out[-1] = (s16)samp;
                        }
                    }
                    left -= n;
                    p->slots[p->slotIdx].remain -= n;
                    p->slots[p->slotIdx].ptr = ring;
                    if (p->slots[p->slotIdx].remain == 0) {
                        i = p->slotIdx + 1;
                        p->slotIdx = i;
                        if (i >= 3) {
                            p->slotIdx = 0;
                        }
                    }
                    if (left == 0) {
                        break;
                    }
                } else {
                    memcpy(out, in, left * 4);
                    break;
                }
            }
        } else {
            memcpy(var_r31, var_r28, var_r29 * 4);
        }
    } else {
        p = &lbl_803123A0;
        if (p->flagA0 != 0 && p->a5 == 1 && p->a7 != 0) {
            table = lbl_8028C578;
            left = var_r29;
            out = var_r31;
            while (1) {
                n = p->slots[p->slotIdx].remain;
                if (n != 0) {
                    if (n >= left) {
                        n = left;
                    }
                    ring = p->slots[p->slotIdx].ptr;
                    for (var_ctr = n; var_ctr != 0; var_ctr--) {
                        if (p->d0 != 0) {
                            p->d0 = p->d0 - 1;
                            p->c4 = p->c4 + p->cc;
                        } else {
                            p->c4 = p->c8;
                        }
                        vol = table[(s32)p->c4];
                        samp = (s32)(vol * ring[0]) >> 15;
                        if (samp < -0x8000) {
                            samp = -0x8000;
                        }
                        if (samp > 0x7FFF) {
                            samp = 0x7FFF;
                        }
                        out[0] = (s16)samp;
                        samp = (s32)(vol * ring[1]) >> 15;
                        if (samp < -0x8000) {
                            samp = -0x8000;
                        }
                        if (samp > 0x7FFF) {
                            samp = 0x7FFF;
                        }
                        out[1] = (s16)samp;
                        out += 2;
                        ring += 2;
                    }
                    left -= n;
                    p->slots[p->slotIdx].remain -= n;
                    p->slots[p->slotIdx].ptr = ring;
                    if (p->slots[p->slotIdx].remain == 0) {
                        i = p->slotIdx + 1;
                        p->slotIdx = i;
                        if (i >= 3) {
                            p->slotIdx = 0;
                        }
                    }
                    if (left == 0) {
                        break;
                    }
                } else {
                    memset(out, 0, left * 4);
                    break;
                }
            }
        } else {
            memset(var_r31, 0, var_r29 * 4);
        }
    }
}

#pragma use_lmw_stmw on
s32 fn_800A41B4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    extern u8 lbl_803123A0[];
    void Gx_Setup2DState(void *);
    void fn_800A5158(s32, s32, s32, s16, s16, s16, s16, s16, s16);
    void Gx_SetupSimpleTev(void);
    s32 a1;
    s32 a2;
    s32 a3;
    s32 a4;
    u8 *base;

    a1 = arg1;
    a2 = arg2;
    a3 = arg3;
    a4 = arg4;
    base = lbl_803123A0;
    if (*(s32 *)(base + 0x158) >= 0) {
        Gx_Setup2DState(arg0);
        fn_800A5158(
            *(s32 *)(lbl_803123A0 + 0x14C),
            *(s32 *)(lbl_803123A0 + 0x150),
            *(s32 *)(lbl_803123A0 + 0x154),
            (s16)a1,
            (s16)a2,
            (s16)*(s32 *)(lbl_803123A0 + 0x80),
            (s16)*(s32 *)(lbl_803123A0 + 0x84),
            (s16)a3,
            (s16)a4);
        Gx_SetupSimpleTev();
        return *(s32 *)(base + 0x158);
    }
    return -1;
}
#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
s32 fn_800A424C(s32 arg0) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s32 fn_8023C56C(s32, s32, s32, s32, s32);
    s32 fn_80243AD4(s32, s32, s32);
    s32 fn_8020CB38(void *, s32, s32, s32, void *, s32);
    extern void fn_800A4878(void);
    struct SlotA {
        void *ptr;
        s32 unk4;
        s32 flag;
    };
    struct SlotB {
        s32 f15c;
        s32 f160;
        u32 f164;
    };
    struct Obj {
        u8 pad0[0x50];
        s32 f50;
        s32 f54;
        u8 pad58[0x0c];
        s32 f64;
        s32 f68;
        u32 f6c;
        u8 f70[0x28];
        s32 f98;
        s32 f9c;
        u8 pa0[4];
        u8 fa4;
        u8 fa5;
        u8 fa6;
        u8 fa7;
        s32 fa8;
        s32 fac;
        u32 fb0;
        s32 fb4;
        s32 fb8;
        s32 fbc;
        s32 fc0;
        u8 padc4[0x10];
        struct SlotA slotA[10];
        s32 f14c;
        s32 f150;
        s32 f154;
        s32 f158;
        struct SlotB slotB[3];
        s32 f180;
    };
    extern struct Obj lbl_803123A0;
    struct Obj *p;
    struct Obj *r30;
    u8 *ready;
    u8 *buffers;
    s32 r27;
    u32 r26;
    s32 *r25;
    struct Obj *r23;
    s32 r24;
    s32 intr;
    s32 v;

    p = &lbl_803123A0;
    ready = (u8 *)&p->slotA[0].flag;
    if (*(s32 *)(ready + p->fb4 * 12) != 0) {
    buffers = (u8 *)&p->slotA[0].ptr;
    r25 = (s32 *)((u8 *)*(void **)(buffers + p->fb4 * 12) + 8);
    r26 = p->f6c * 4 + 8;
    r26 = (s32)*(void **)(buffers + p->fb4 * 12) + r26;
    if (p->fa7 != 0) {
        if (arg0 < 0 || (u32)arg0 >= (u32)p->f98) {
            return 4;
        }
        if (lbl_803123A0.slotB[p->f180].f164 == 0) {
            r30 = p;
            r27 = 0;
            while (r27 < p->f6c) {
                switch (*(r30->f70)) {
                    case 0:
                        if (!Movie_DecodeFrame(r26, (u8 *)p)) return 1;
                        break;
                    case 1:
                        v = fn_80243AD4(lbl_803123A0.slotB[p->f180].f15c, r26 + (*r25 * arg0), 0);
                        intr = OSDisableInterrupts();
                        lbl_803123A0.slotB[p->f180].f164 = v;
                        lbl_803123A0.slotB[p->f180].f160 = lbl_803123A0.slotB[p->f180].f15c;
                        OSRestoreInterrupts(intr);
                        p->f180 = p->f180 + 1;
                        if (p->f180 >= 3) {
                            p->f180 = 0;
                        }
                        break;
                    default:
                        break;
                }
                v = *r25;
                r25++;
                r30 = (struct Obj *)((u8 *)r30 + 1);
                r27++;
                r26 += v;
            }
        } else {
            return 3;
        }
    } else {
        r23 = p;
        r24 = 0;
        while (r24 < p->f6c) {
            switch (*(r23->f70)) { case 0:
                if (!Movie_DecodeFrame(r26, (u8 *)p)) return 1;
                break;
            }
            v = *r25;
            r25++;
            r23 = (struct Obj *)((u8 *)r23 + 1);
            r24++;
            r26 += v;
        }
    }

    *(s32 *)(ready + p->fb4 * 12) = 0;
    v = p->fb4 + 1;
    p->fb4 = v >= 10 ? 0 : v;
    intr = OSDisableInterrupts();
    p = &lbl_803123A0;
    if (*(s32 *)(ready + p->fb8 * 12) == 0 && p->fb0 == 0 && p->fac == 0 && p->fa4 == 1) {
        if ((u32)p->fc0 > (u32)(p->f50 - 1)) {
            if (p->fa6 == 1) {
                p->fc0 = 0;
                p->fa8 = p->f64;
                p->fbc = p->f54;
                goto block_39;
            }
        } else {
        block_39:
            p->fb0 = 1;
            if (fn_8020CB38(&lbl_803123A0, (s32)*(void **)(buffers + p->fb8 * 12), lbl_803123A0.fbc, lbl_803123A0.fa8, fn_800A4878, 2) != 1) {
                p->fb0 = 0;
                p->fac = 1;
            }
        }
    }
    OSRestoreInterrupts(intr);
    return 0;
    }
    return 2;
}
#pragma pop
#pragma use_lmw_stmw reset
s32 fn_800A45C4(void) {
    void fn_8020F334(void *);
    extern u8 lbl_803123A0[];
    register u8 *p;
    register u8 *q;
    s32 i;
    s32 zero;
    u32 flag;

    p = lbl_803123A0;
    if (*(s32 *)(p + 0xA0) != 0 && p[0xA5] == 0) {
        p[0xA4] = 0;
        flag = *(u32 *)(p + 0xB0);
        if (flag) {
            fn_8020F334(p);
            *(u32 *)(p + 0xB0) = 0;
        }
        i = 0;
        if (i < 10) {
            q = lbl_803123A0;
            zero = 0;
            *(s32 *)(q + 0xDC) = zero;
            *(s32 *)(q + 0xE8) = zero;
            *(s32 *)(q + 0xF4) = zero;
            *(s32 *)(q + 0x100) = zero;
            *(s32 *)(q + 0x10C) = zero;
            *(s32 *)(q + 0x118) = zero;
            *(s32 *)(q + 0x124) = zero;
            *(s32 *)(q + 0x130) = zero;
            *(s32 *)(q + 0x13C) = zero;
            *(s32 *)(q + 0x148) = zero;
        }
        q = lbl_803123A0;
        zero = 0;
        *(s32 *)(q + 0x164) = zero;
        *(s32 *)(q + 0x170) = zero;
        *(s32 *)(q + 0x17C) = zero;
        *(s32 *)(q + 0x158) = -1;
        *(s32 *)(q + 0xA8) = *(s32 *)(q + 0x64);
        *(s32 *)(q + 0xBC) = *(s32 *)(q + 0x54);
        *(s32 *)(q + 0xB8) = zero;
        *(s32 *)(q + 0xC0) = zero;
        *(s32 *)(q + 0xAC) = zero;
        *(s32 *)(q + 0xB4) = zero;
        *(s32 *)(q + 0x180) = zero;
        *(s32 *)(q + 0x184) = zero;
        *(f32 *)(q + 0xC4) = *(f32 *)(q + 0xC8);
        *(s32 *)(q + 0xD0) = zero;
        return 1;
    }
    return 0;
}
#pragma optimization_level reset
void fn_800A46CC(void) {
    extern u8 lbl_803123A0[];
    lbl_803123A0[0xA5] = 0;
}

void fn_800A46E0(void) {
    extern u8 lbl_803123A0[];
    lbl_803123A0[0xA5] = 1;
}

#pragma use_lmw_stmw on
s32 fn_800A46F4(s32 arg0) {
    s32 fn_8020CC28(void *, s32, s32, s32, s32);
    extern u8 lbl_803123A0[];
    u32 temp_r4;
    s32 temp_r6_2;
    u32 var_r29;
    u32 var_r28;
    void *temp_r6;

    if (((s32) M2C_FIELD(lbl_803123A0, s32 *, 0xA0) != 0) && ((u8) M2C_FIELD(lbl_803123A0, u8 *, 0xA4) == 0)) {
        var_r28 = 0xAU;
        if ((arg0 == 0) && ((u32) M2C_FIELD(lbl_803123A0, u32 *, 0x50) < 0xAU)) {
            var_r28 = M2C_FIELD(lbl_803123A0, u32 *, 0x50);
        }
        for(var_r29 = 0; var_r29 < var_r28; var_r29++) {
        if (fn_8020CC28(lbl_803123A0, M2C_FIELD((lbl_803123A0 + (M2C_FIELD(lbl_803123A0, s32 *, 0xB8) * 0xC)), s32 *, 0xD4), M2C_FIELD(lbl_803123A0, s32 *, 0xBC), M2C_FIELD(lbl_803123A0, s32 *, 0xA8), 2) < 0) {
            M2C_FIELD(lbl_803123A0, s32 *, 0xAC) = 1;
            return 0;
        }
        M2C_FIELD(lbl_803123A0, s32 *, 0xA8) = (s32) (M2C_FIELD(lbl_803123A0, s32 *, 0xA8) + M2C_FIELD(lbl_803123A0, s32 *, 0xBC));
        temp_r6 = lbl_803123A0 + (M2C_FIELD(lbl_803123A0, s32 *, 0xB8) * 0xC);
        M2C_FIELD(lbl_803123A0, s32 *, 0xBC) = (s32) *M2C_FIELD(temp_r6, s32 **, 0xD4);
        M2C_FIELD(temp_r6, s32 *, 0xDC) = 1;
        M2C_FIELD((lbl_803123A0 + (M2C_FIELD(lbl_803123A0, s32 *, 0xB8) * 0xC)), u32 *, 0xD8) = (u32) M2C_FIELD(lbl_803123A0, u32 *, 0xC0);
        temp_r6_2 = M2C_FIELD(lbl_803123A0, s32 *, 0xB8) + 1;
        temp_r4 = M2C_FIELD(lbl_803123A0, u32 *, 0xC0) + 1;
        M2C_FIELD(lbl_803123A0, u32 *, 0xC0) = temp_r4;
        M2C_FIELD(lbl_803123A0, s32 *, 0xB8) = (temp_r6_2 >= 10 ? 0 : temp_r6_2);
        if ((temp_r4 > (u32) (M2C_FIELD(lbl_803123A0, u32 *, 0x50) - 1)) && ((u8) M2C_FIELD(lbl_803123A0, u8 *, 0xA6) == 1)) {
            M2C_FIELD(lbl_803123A0, u32 *, 0xC0) = 0U;
            M2C_FIELD(lbl_803123A0, s32 *, 0xA8) = (s32) M2C_FIELD(lbl_803123A0, s32 *, 0x64);
            M2C_FIELD(lbl_803123A0, s32 *, 0xBC) = (s32) M2C_FIELD(lbl_803123A0, s32 *, 0x54);
        }
        }
        M2C_FIELD(lbl_803123A0, u8 *, 0xA6) = (u8)arg0;
        M2C_FIELD(lbl_803123A0, u8 *, 0xA4) = 1;
        return 1;
    }
    return 0;
}
#pragma use_lmw_stmw reset
void fn_800A4878(s32 result) {
extern u8 lbl_803123A0[];
s32 fn_8020CB38(void *,void *,s32,s32,void (*)(s32),s32);
s32 next;
u8 *p;
u8 *buffers;
u8 *ready;
if(result==-1){*(s32 *)(lbl_803123A0+0xAC)=1;return;}
if(result==-3)return;
p=lbl_803123A0;
buffers=p+0xD4;
ready=p+0xDC;
*(s32 *)(p+0xB0)=0;
*(u32 *)(p+*(s32 *)(p+0xB8)*12+0xD8)=*(u32 *)(p+0xC0);
++*(u32 *)(p+0xC0);
*(s32 *)(ready+*(s32 *)(p+0xB8)*12)=1;
*(s32 *)(p+0xA8)+=*(s32 *)(p+0xBC);
next=*(s32 *)(p+0xB8)+1;
next=next>=10?0:next;
*(s32 *)(p+0xBC)=**(s32 **)(buffers+*(s32 *)(p+0xB8)*12);
*(s32 *)(p+0xB8)=next;
if(*(s32 *)(ready+next*12)==0 && *(s32 *)(p+0xAC)==0 && p[0xA4]==1) {
if(*(u32 *)(p+0xC0)>(u32)(*(s32 *)(p+0x50)-1)) {
if(p[0xA6]!=1)return;
*(u32 *)(p+0xC0)=0;
*(s32 *)(p+0xA8)=*(s32 *)(p+0x64);
*(s32 *)(p+0xBC)=*(s32 *)(p+0x54);
}
*(s32 *)(p+0xB0)=1;
if(fn_8020CB38(lbl_803123A0,*(void **)(buffers+*(s32 *)(p+0xB8)*12),*(s32 *)(p+0xBC),*(s32 *)(p+0xA8),fn_800A4878,2)!=1) {
*(s32 *)(p+0xB0)=0;
*(s32 *)(p+0xAC)=1;
}
}
}
#pragma optimization_level reset
s32 fn_800A49F4(u8 *arg0) {
    void DCInvalidateRange(void *, u32);
    extern u8 lbl_803123A0[];
    u8 *ptr;
    u8 *cursor;
    u32 size;
    u32 sizeFull;
    u32 sizeQuarter;
    u32 step;
    s32 i;
    s32 zero;

    if (*(s32 *)(lbl_803123A0 + 0xA0) != 0 && lbl_803123A0[0xA4] == 0) {
        if (lbl_803123A0[0xA5] == 1) {
            return 0;
        }
        *(u8 **)(lbl_803123A0 + 0x14C) = arg0;
        size = *(s32 *)(lbl_803123A0 + 0x80) * *(s32 *)(lbl_803123A0 + 0x84);
        sizeFull = (size + 0x1F) & ~0x1FU;
        sizeQuarter = ((size >> 2) + 0x1F) & ~0x1FU;
        DCInvalidateRange(arg0, sizeFull);
        ptr = arg0 + sizeFull;
        *(u8 **)(lbl_803123A0 + 0x150) = ptr;
        DCInvalidateRange(ptr, sizeQuarter);
        ptr += sizeQuarter;
        *(u8 **)(lbl_803123A0 + 0x154) = ptr;
        DCInvalidateRange(ptr, sizeQuarter);
        ptr += sizeQuarter;
        cursor = lbl_803123A0;
        zero = 0;
        for (i = 0; i < 2; i++) {
            *(u8 **)(cursor + 0xD4) = ptr;
            step = (*(s32 *)(lbl_803123A0 + 0x44) + 0x1F) & ~0x1FU;
            *(s32 *)(cursor + 0xDC) = zero;
            ptr += step;
            *(u8 **)(cursor + 0xE0) = ptr;
            step = (*(s32 *)(lbl_803123A0 + 0x44) + 0x1F) & ~0x1FU;
            *(s32 *)(cursor + 0xE8) = zero;
            ptr += step;
            *(u8 **)(cursor + 0xEC) = ptr;
            step = (*(s32 *)(lbl_803123A0 + 0x44) + 0x1F) & ~0x1FU;
            *(s32 *)(cursor + 0xF4) = zero;
            ptr += step;
            *(u8 **)(cursor + 0xF8) = ptr;
            step = (*(s32 *)(lbl_803123A0 + 0x44) + 0x1F) & ~0x1FU;
            *(s32 *)(cursor + 0x100) = zero;
            ptr += step;
            *(u8 **)(cursor + 0x104) = ptr;
            step = (*(s32 *)(lbl_803123A0 + 0x44) + 0x1F) & ~0x1FU;
            *(s32 *)(cursor + 0x10C) = zero;
            cursor += 0x3C;
            ptr += step;
        }
        if (lbl_803123A0[0xA7] != 0) {
            step = ((*(s32 *)(lbl_803123A0 + 0x48) << 2) + 0x1F) & ~0x1FU;
            *(u8 **)(lbl_803123A0 + 0x15C) = ptr;
            *(u8 **)(lbl_803123A0 + 0x160) = ptr;
            ptr += step;
            *(s32 *)(lbl_803123A0 + 0x164) = zero;
            *(u8 **)(lbl_803123A0 + 0x168) = ptr;
            *(u8 **)(lbl_803123A0 + 0x16C) = ptr;
            ptr += step;
            *(s32 *)(lbl_803123A0 + 0x170) = zero;
            *(u8 **)(lbl_803123A0 + 0x174) = ptr;
            *(u8 **)(lbl_803123A0 + 0x178) = ptr;
            ptr += step;
            *(s32 *)(lbl_803123A0 + 0x17C) = zero;
        }
        *(u8 **)(lbl_803123A0 + 0x9C) = ptr;
    }
    return 1;
}

s32 fn_800A4BC4(void) {
    extern struct {
        u8 pad0[0x44];
        u32 v44;
        u32 v48;
        u8 pad4C[0x34];
        u32 v80;
        u32 v84;
        u8 pad88[0x18];
        s32 vA0;
        u8 padA4[3];
        u8 vA7;
    } lbl_803123A0;

    if (lbl_803123A0.vA0) {
        u32 size = ((lbl_803123A0.v44 + 0x1F) & ~0x1F) * 10;
        u32 prod = lbl_803123A0.v80 * lbl_803123A0.v84;
        u32 uvsize;
        size += (prod + 0x1F) & ~0x1F;
        uvsize = ((prod >> 2) + 0x1F) & ~0x1F;
        size += uvsize;
        size += uvsize;
        if (lbl_803123A0.vA7) {
            size += (((lbl_803123A0.v48 << 2) + 0x1F) & ~0x1F) * 3;
        }
        return size + 0x1000;
    }
    return 0;
}

s32 fn_800A4C48(void) {
 void fn_8020C79C(void);
 extern u8 lbl_803123A0[];
 u8 *p=lbl_803123A0;
 if (*(s32 *)(p+0xA0)==0) goto ret0;
 if(p[0xA4]!=0) goto ret0;
 if(p[0xA7]==0) goto clear_a5;
 if(p[0xA5]!=1) goto check_b0;
 return 0;
clear_a5:
 p[0xA5]=0;
check_b0:
 if(*(u32 *)(lbl_803123A0+0xB0)!=0) goto ret0;
 *(s32 *)(p+0xA0)=0;
 fn_8020C79C();
 return 1;
ret0:
 return 0;
}

#pragma push
#pragma optimization_level 2
#pragma use_lmw_stmw on
s32 fn_800A4CD8(s32 arg0) {
    s32 fn_8020C6D4(s32, void *);
    void fn_8020C79C(void *);
    s32 fn_8020CC28(void *, void *, s32, s32, s32);
    s32 Str_Cmp(void *, void *);
    void *memset(void *, s32, s32);
    void *memcpy(void *, void *, s32);
    extern s32 lbl_803677B0;
    extern u8 lbl_80312540[];
    extern u8 lbl_803123A0[];
    extern u8 lbl_8026E1A8[];
    extern f32 lbl_80369A20;

    u8 *types;
    u8 *p6c;
    s32 off;
    u8 *p8c;
    u8 *base;
    u8 *p80;
    u8 *loopBase;

    if (!lbl_803677B0) {
        return 0;
    }
    base = lbl_803123A0;
    if (*(s32 *)(base + 0xA0) != 0) {
        return 0;
    }
    p80 = base + 0x80;
    memset(p80, 0, 0xC);
    p8c = lbl_803123A0 + 0x8C;
    memset(p8c, 0, 0x10);
    if (fn_8020C6D4(arg0, lbl_803123A0) == 0) {
        return 0;
    }
    if (fn_8020CC28(lbl_803123A0, lbl_80312540, 0x40, 0, 2) < 0) {
        fn_8020C79C(lbl_803123A0);
        return 0;
    }
    arg0 = (s32)(lbl_803123A0 + 0x3C);
    memcpy((void *)arg0, lbl_80312540, 0x30);
    if (Str_Cmp((void *)arg0, lbl_8026E1A8) != 0) {
        fn_8020C79C(lbl_803123A0);
        return 0;
    }
    {
        u8 *tmp = lbl_803123A0;
        if ((u32)(*(u32 *)(tmp + 0x40) - 0x10000) != 0x1000U) {
            fn_8020C79C(tmp);
            return 0;
        }
        arg0 = *(s32 *)(tmp + 0x5C);
        if (fn_8020CC28(tmp, lbl_80312540, 0x20, arg0, 2) < 0) {
            fn_8020C79C(lbl_803123A0);
            return 0;
        }
    }
    p6c = lbl_803123A0 + 0x6C;
    memcpy(p6c, lbl_80312540, 0x14);
    off = arg0 + 0x14;
    loopBase = lbl_803123A0;
    {
        u8 zero = 0;
        loopBase[0xA7] = zero;
    }
    types = loopBase;
    arg0 = 0;
    goto loop_cond;
loop_body:
    switch (types[0x70]) {
    case 0:
        if (fn_8020CC28(lbl_803123A0, lbl_80312540, 0x20, off, 2) < 0) {
            fn_8020C79C(lbl_803123A0);
            return 0;
        }
        memcpy(p80, lbl_80312540, 0xC);
        off += 0xC;
        break;
    case 1:
        if (fn_8020CC28(lbl_803123A0, lbl_80312540, 0x20, off, 2) < 0) {
            fn_8020C79C(lbl_803123A0);
            return 0;
        }
        memcpy(p8c, lbl_80312540, 0x10);
        loopBase[0xA7] = 1;
        off += 0x10;
        break;
    default:
        return 0;
    }
    arg0 += 1;
    types += 1;
loop_cond:
    if ((u32)arg0 < *(u32 *)p6c) {
        goto loop_body;
    }
    loopBase = lbl_803123A0;
    *(s32 *)(loopBase + 0xA8) = *(s32 *)(loopBase + 0x64);
    *(s32 *)(loopBase + 0xBC) = *(s32 *)(loopBase + 0x54);
    *(s32 *)(loopBase + 0xB8) = 0;
    *(s32 *)(loopBase + 0xC0) = 0;
    *(s32 *)(loopBase + 0xAC) = 0;
    *(s32 *)(loopBase + 0x158) = -1;
    *(s32 *)(loopBase + 0xB4) = 0;
    *(s32 *)(loopBase + 0x180) = 0;
    *(s32 *)(loopBase + 0x184) = 0;
    loopBase[0xA4] = 0;
    loopBase[0xA5] = 0;
    loopBase[0xA6] = 0;
    *(s32 *)(base + 0xA0) = 1;
    *(f32 *)(loopBase + 0xC4) = lbl_80369A20;
    *(f32 *)(loopBase + 0xC8) = lbl_80369A20;
    *(s32 *)(loopBase + 0xD0) = 0;
    return 1;
}
#pragma pop
#pragma use_lmw_stmw on
void fn_800A4FF8(void) {
    s32 OSDisableInterrupts();
    M2C_UNK OSRestoreInterrupts(s32);
    M2C_UNK fn_8021371C(u32);
    extern s32 lbl_803677B0;
    extern u32 lbl_803677B8;
    s32 temp_r31;

    temp_r31 = OSDisableInterrupts();
    if ((u32) lbl_803677B8 != 0U) {
        fn_8021371C(lbl_803677B8);
    }
    OSRestoreInterrupts(temp_r31);
    lbl_803677B0 = 0;
}

s32 fn_800A5048(s32 arg0) {
extern u8 lbl_803123A0[],lbl_80312580[];
extern s32 lbl_803677C4,lbl_803677B4,lbl_803677BC,lbl_803677C0,lbl_803677B0;
extern u32 lbl_803677B8;
void fn_800A3B90(void);
u32 fn_8021371C(void (*)(void));
void fn_80213760(void *,u32);
void fn_802137E8(void);
s32 fn_80243A34(void);
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
void DCFlushRange(void *,u32);
void *memset(void *,s32,u32);
s32 interrupts;
memset(lbl_803123A0,0,0x188);
if(fn_80243A34()==0) return 0;
interrupts=OSDisableInterrupts();
lbl_803677C4=arg0;
lbl_803677B4=0;lbl_803677BC=0;lbl_803677C0=0;
lbl_803677B8=fn_8021371C(fn_800A3B90);
if(lbl_803677B8==0 && lbl_803677C4!=0) {
fn_8021371C(0);OSRestoreInterrupts(interrupts);return 0;
}
OSRestoreInterrupts(interrupts);
if(lbl_803677C4==0){
memset(lbl_80312580,0,0x500);
DCFlushRange(lbl_80312580,0x500);
fn_80213760(lbl_80312580+lbl_803677B4*0x280,0x280);
fn_802137E8();
}
lbl_803677B0=1;
return 1;
}

void fn_800A5158(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s16 arg_sp8) {
    M2C_UNK GXBegin(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK fn_80222644(M2C_UNK *, s32, u16, u16, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXInitTexObjLOD(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32, f32, f32);
    M2C_UNK fn_80222C50(M2C_UNK *, M2C_UNK);
    extern f32 lbl_80369A3C;
    M2C_UNK sp48[8];
    M2C_UNK sp28[8];
    M2C_UNK sp8[8];
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r29;
    s32 temp_r28;

    fn_80222644(sp48, arg0, (u16)arg5, (u16)arg6, 1, 0, 0, 0);
    GXInitTexObjLOD(sp48, 0, 0, 0, 0, 0, lbl_80369A3C, lbl_80369A3C, lbl_80369A3C);
    fn_80222C50(sp48, 0);
    temp_r28 = (s16)arg5 >> 1;
    temp_r29 = (s16)arg6 >> 1;
    fn_80222644(sp28, arg1, (u16)temp_r28, (u16)temp_r29, 1, 0, 0, 0);
    GXInitTexObjLOD(sp28, 0, 0, 0, 0, 0, lbl_80369A3C, lbl_80369A3C, lbl_80369A3C);
    fn_80222C50(sp28, 1);
    fn_80222644(sp8, arg2, (u16)temp_r28, (u16)temp_r29, 1, 0, 0, 0);
    GXInitTexObjLOD(sp8, 0, 0, 0, 0, 0, lbl_80369A3C, lbl_80369A3C, lbl_80369A3C);
    fn_80222C50(sp8, 2);
    GXBegin(0x80, 7, 4);
    *(s16 *)0xCC008000 = (s16)arg3;
    temp_r6 = (s16)arg4 + arg_sp8;
    *(s16 *)0xCC008000 = (s16)arg4;
    temp_r5 = (s16)arg3 + (s16)arg7;
    *(s16 *)0xCC008000 = 0;
    *(s16 *)0xCC008000 = 0;
    *(s16 *)0xCC008000 = 0;
    *(s16 *)0xCC008000 = temp_r5;
    *(s16 *)0xCC008000 = (s16)arg4;
    *(s16 *)0xCC008000 = 0;
    *(s16 *)0xCC008000 = 1;
    *(s16 *)0xCC008000 = 0;
    *(s16 *)0xCC008000 = temp_r5;
    *(s16 *)0xCC008000 = temp_r6;
    *(s16 *)0xCC008000 = 0;
    *(s16 *)0xCC008000 = 1;
    *(s16 *)0xCC008000 = 1;
    *(s16 *)0xCC008000 = (s16)arg3;
    *(s16 *)0xCC008000 = temp_r6;
    *(s16 *)0xCC008000 = 0;
    *(s16 *)0xCC008000 = 0;
    *(s16 *)0xCC008000 = 1;
}

/* Configure GX for orthographic 2D drawing to the screen size in arg0. */
void Gx_Setup2DState(void *arg0) {
    void PSMTXIdentity(void *);
    void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
    void GXSetVtxDesc(s32, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80221A2C(s32);
    void GXSetCullMode(s32);
    void GXSetNumChans(s32);
    void fn_80222EB4(void);
    void GXSetTevColorIn(s32, s32, s32, s32, s32);
    void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
    void GXSetTevColorOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevAlphaOp(s32, s32, s32, s32, s32, s32);
    void fn_80223C14(s32, s32 *, s32);
    void fn_80223C78(s32, s32 *);
    void fn_80223CDC(s32, s32);
    void fn_80223D38(s32, s32);
    void GXSetTevSwapMode(s32, s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetZMode(s32, s32, s32);
    void GXSetProjection(void *, s32);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    void GXSetScissor(s32, s32, s32, s32);
    void GXSetTevSwapModeTable(s32, s32, s32, s32, s32);
    extern s32 lbl_80369A28;
    extern s32 lbl_80369A2C;
    extern s32 lbl_80369A30;
    extern s32 lbl_80369A34;
    extern s32 lbl_80369A38;
    u8 ortho[0x44];
    u8 identity[0x30];
    s32 sp14[2];
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 width;
    s32 height;
    width = M2C_FIELD(arg0, u16 *, 4);
    height = M2C_FIELD(arg0, u16 *, 6);
    C_MTXOrtho(ortho, 0.0f, (f32)height, 0.0f, (f32)width, 0.0f, -1.0f);
    GXSetProjection(ortho, 1);
    GXSetViewport(0.0f, 0.0f, (f32)width, (f32)height, 0.9f, 0.9f);
    GXSetScissor(0, 0, width, height);
    PSMTXIdentity(identity);
    GXLoadPosMtxImm(identity, 0);
    GXSetCurrentMtx(0);
    GXSetZMode(1, 3, 1);
    fn_802245D8(0, 1, 0, 0);
    fn_80221A2C(0);
    GXSetCullMode(0);
    GXSetNumChans(2);
    fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
    fn_802201A8(1, 1, 4, 0x3C, 0, 0x7D);
    fn_80222EB4();
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xD, 1);
    GXSetVtxAttrFmt(7, 9, 1, 3, 0);
    GXSetVtxAttrFmt(7, 0xD, 1, 2, 0);
    GXSetNumTevStages(4);
    GXSetTevOrder(0, 1, 1, 0xFF);
    GXSetTevColorIn(0, 0xF, 8, 0xE, 2);
    GXSetTevColorOp(0, 0, 0, 0, 0, 0);
    GXSetTevAlphaIn(0, 7, 4, 6, 1);
    GXSetTevAlphaOp(0, 1, 0, 0, 0, 0);
    fn_80223CDC(0, 0xC);
    fn_80223D38(0, 0x1C);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevOrder(1, 1, 2, 0xFF);
    GXSetTevColorIn(1, 0xF, 8, 0xE, 0);
    GXSetTevColorOp(1, 0, 0, 1, 0, 0);
    GXSetTevAlphaIn(1, 7, 4, 6, 0);
    GXSetTevAlphaOp(1, 1, 0, 0, 0, 0);
    fn_80223CDC(1, 0xD);
    fn_80223D38(1, 0x1D);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevOrder(2, 0, 0, 0xFF);
    GXSetTevColorIn(2, 0xF, 8, 0xC, 0);
    GXSetTevColorOp(2, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(2, 4, 7, 7, 0);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    GXSetTevSwapMode(2, 0, 0);
    GXSetTevOrder(3, 0xFF, 0xFF, 0xFF);
    GXSetTevColorIn(3, 1, 0, 0xE, 0xF);
    GXSetTevColorOp(3, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(3, 7, 7, 7, 7);
    GXSetTevAlphaOp(3, 0, 0, 0, 1, 0);
    GXSetTevSwapMode(3, 0, 0);
    fn_80223CDC(3, 0xE);
    sp14[0] = lbl_80369A28;
    sp14[1] = lbl_80369A2C;
    fn_80223C14(1, sp14, lbl_80369A28);
    sp10 = lbl_80369A30;
    fn_80223C78(0, &sp10);
    spC = lbl_80369A34;
    fn_80223C78(1, &spC);
    sp8 = lbl_80369A38;
    fn_80223C78(2, &sp8);
    GXSetTevSwapModeTable(0, 0, 1, 2, 3);
}

/* Configure a simple 1-stage TEV with default RGBA swap tables. */
void Gx_SetupSimpleTev(void) {
    void GXSetNumChans(s32);
    void GXSetCullMode(s32);
    void GXSetNumTexGens(s32, s32);
    void GXSetTevSwapMode(s32, s32, s32);
    void GXSetTevSwapModeTable(s32, s32, s32, s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetZMode(s32, s32, s32);
    GXSetZMode(1, 7, 1);
    fn_802245D8(0, 1, 0, 0xF);
    GXSetNumChans(1);
    GXSetCullMode(0);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 0xFF);
    GXSetNumTexGens(0, 3);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevSwapMode(2, 0, 0);
    GXSetTevSwapMode(3, 0, 0);
    GXSetTevSwapModeTable(0, 0, 1, 2, 3);
    GXSetTevSwapModeTable(1, 0, 0, 0, 3);
    GXSetTevSwapModeTable(2, 1, 1, 1, 3);
    GXSetTevSwapModeTable(3, 2, 2, 2, 3);
}

void fn_800A58F0(s32 arg0) {
    void *Process_FindByName(void *);
    void *Process_Create(void *, void *);
    extern u8 lbl_8026E1B0[];
    extern u8 lbl_8028C6A8[];
    void *temp;

    temp = Process_FindByName(lbl_8026E1B0 + 0x15);
    if (temp != NULL) {
        temp = Process_Create(lbl_8028C6A8, temp);
        *(s32 *)((u8 *)temp + 0x30) = arg0;
    }
}

void fn_800A5944(s32 arg0) {
    M2C_UNK FileCache_ReleaseSlot(s32);
    FileCache_ReleaseSlot(arg0 + 0x34);
}

#pragma optimization_level reset
void fn_800A5968(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Process_ClearFunc(void *);
    extern const f32 lbl_80369A70;
    extern const f32 lbl_80369A6C;
    extern const f32 lbl_80369A68;
    extern const f32 lbl_80369A64;
    extern const f32 lbl_80369A60;
    extern const f32 lbl_80369A5C;
    extern const f32 lbl_80369A58;
    extern const f32 lbl_80369A54;
    extern const f32 lbl_80369A50;
    s32 temp_r0;
    s32 temp_r3;

    M2C_FIELD(arg0, s32 *, 0x38) = M2C_FIELD(arg0, s32 *, 0x38) + 1;
    M2C_FIELD(arg0, s16 *, 0x40) = 0x40;
    if (M2C_FIELD(arg0, s32 *, 0x38) < 0x46) {
        M2C_FIELD(arg0, u8 *, 0x60) = 0;
    }
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x38);
    if (temp_r0 >= 0x46 && temp_r0 <= 0x64) {
        M2C_FIELD(arg0, u8 *, 0x61) = 8;
        M2C_FIELD(arg0, s16 *, 0x42) = (s16)Math_Ease(4, lbl_80369A50, lbl_80369A54, (f32)(M2C_FIELD(arg0, s32 *, 0x38) - 0x46), lbl_80369A58);
        M2C_FIELD(arg0, u8 *, 0x60) = (u8)Math_Ease(0, lbl_80369A5C, lbl_80369A60, (f32)(M2C_FIELD(arg0, s32 *, 0x38) - 0x46), lbl_80369A58);
    }
    temp_r3 = M2C_FIELD(arg0, s32 *, 0x38);
    if (temp_r3 >= 0xC8 && temp_r3 <= 0xDC) {
        M2C_FIELD(arg0, u8 *, 0x60) = (u8)Math_Ease(0, lbl_80369A60, lbl_80369A5C, (f32)(temp_r3 - 0xC8), lbl_80369A64);
    }
    if (M2C_FIELD(arg0, s32 *, 0x38) > 0xDC) {
        Process_ClearFunc(arg0);
    }
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_80369A5C, lbl_80369A5C, lbl_80369A5C, lbl_80369A68);
    Prim2D_SetColorByte(0xFF);
    Prim2D_BindTexture(M2C_FIELD(arg0, s32 *, 0x34), 0, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin((f32)M2C_FIELD(arg0, s16 *, 0x40), (f32)M2C_FIELD(arg0, s16 *, 0x42), lbl_80369A5C, lbl_80369A5C);
    Prim2D_SetQuadMax((f32)(M2C_FIELD(arg0, s16 *, 0x40) + 0x1E0), (f32)(M2C_FIELD(arg0, s16 *, 0x42) + 0xA0), lbl_80369A6C, lbl_80369A70);
    Prim2D_SetColor(0xFF, 0xFF, 0xFF, M2C_FIELD(arg0, u8 *, 0x60));
    Prim2D_EndPrim();
}
void fn_800A5BB4(s32 arg0) {
    M2C_UNK Process_ClearFunc(s32);
    s32 FileCache_GetFlags(s32);
    M2C_UNK fn_8006EEFC(s32, s32);
    if (FileCache_GetFlags(arg0 + 0x44) & 0x2000) {
        fn_8006EEFC(arg0 + 0x34, arg0 + 0x44);
        Process_ClearFunc(arg0);
    }
}

void fn_800A5C00(void *arg0)
{
    extern u8 lbl_8026E1B0[];

    extern void strcpy(void *, const char *);
    extern s32 sprintf(char *, const char *, ...);
    extern void strcat(void *, const char *);
    extern void fn_8005C8B4(void *);

    u8 *obj;
    char buffer[0x10];

    obj = (u8 *)arg0;

    *(u32 *)(obj + 0x38) = 0;

    strcpy(
        obj + 0x44,
        (const char *)lbl_8026E1B0 + 0x2E
    );

    sprintf(
        buffer,
        (const char *)lbl_8026E1B0 + 0x42,
        *(u32 *)(obj + 0x30)
    );

    strcat(obj + 0x44, buffer);

    strcat(
        obj + 0x44,
        (const char *)lbl_8026E1B0 + 0x45
    );

    fn_8005C8B4(obj + 0x44);
}

extern u16 lbl_802B9E80;
s32 fn_800A5C88(void) {
    extern u16 lbl_8028C678[];
    s32 v = Process_Find(lbl_8028C678);
    return v != 0;
}

void fn_800A5CBC(void) {
    extern u16 lbl_8028C678[];
    u32 temp_r3 = Process_Find(&lbl_8028C678[0]);
    if (temp_r3 != 0) {
        Process_Goto(temp_r3, 0x63);
    }
}

void fn_800A5CF4(void) {
    M2C_UNK fn_800A3A68(M2C_UNK, M2C_UNK);
    fn_800A3A68(0, 0x64);
}

void fn_800A5D1C(void *arg0, s32 arg1, s32 arg2) {
    void *Process_Create(void *, M2C_UNK);
    u16 FileCache_Probe();
    s32 Heap_AllocRaw(M2C_UNK);
    M2C_UNK fn_80147188(M2C_UNK);
    M2C_UNK fn_801C9724();
    M2C_UNK Str_CopyPad(s32, void *, M2C_UNK);
    extern u8 lbl_8026E1B0[];
    extern u8 lbl_8028C678[];
    void *temp_r31;

    if ((u16) FileCache_Probe() == 0x8000) {
        arg0 = lbl_8026E1B0 + 0x4A;
    }
    temp_r31 = Process_Create(lbl_8028C678, 5);
    M2C_FIELD(temp_r31, s32 *, 0x5C) = Heap_AllocRaw(0x100);
    Str_CopyPad(M2C_FIELD(temp_r31, s32 *, 0x5C), arg0, 0xFE);
    M2C_FIELD(temp_r31, s8 *, 0x54) = arg1;
    M2C_FIELD(temp_r31, s32 *, 0x58) = arg2;
    fn_801C9724();
    fn_80147188(1);
}

void fn_800A5DC4(void *arg0)
{
    void fn_800A46CC(void);
    void fn_800A45C4(void);
    void fn_800A4C48(void);
    void fn_800C4588(void *);
    void fn_800A4FF8(void);
    void fn_8009E638(void);
    void fn_801C9714(void);
    void fn_800C426C(void *);
    void *fn_8006E658(void);
    void fn_80221824(u8, void *, s32, void *);
    extern u8 lbl_80330708[];
    extern s32 lbl_803682A4;
    extern f32 lbl_80369A68;
    extern f32 lbl_80369A80;
    extern f32 lbl_80369A84;
    extern s32 lbl_8036C478;
    extern u16 lbl_8036C47C;
    extern u8 lbl_8036C47E;
    struct {
        s32 unk0;
        u16 unk4;
        u8 unk6;
    } sp10;
    u32 spC;
    u32 sp8;
    s32 temp_r0;
    u16 temp_r8;
    u8 *var_r9;
    s32 var_r7;
    s32 count;
    s32 temp_r7;
    s32 var_ctr;
    u8 *var_r8;
    void *temp_r3;

    fn_800A46CC();
    fn_800A45C4();
    fn_800A4C48();
    fn_800C4588(*(void **)((u8 *)arg0 + 0x4C));
    *(s32 *)((u8 *)arg0 + 0x4C) = 0;
    fn_800A4FF8();
    fn_8009E638();
    fn_801C9714();
    fn_800C426C(*(void **)((u8 *)arg0 + 0x5C));
    if (lbl_803682A4 & 0x40) {
        temp_r3 = fn_8006E658();
        var_r9 = (u8 *)&spC;
        var_r7 = 0;
        temp_r0 = (s32)((f32)(s8)lbl_80330708[0xA1] * lbl_80369A68);
        temp_r8 = (s8)lbl_80330708[0xA1] - (u16)temp_r0;
        count = temp_r8 % 4;
        for (var_ctr = 2; var_ctr != 0; var_ctr--) {
            if (var_r7 < count) {
                *var_r9 = (u8)(s32)((f32)temp_r8 * lbl_80369A80 + lbl_80369A68);
            } else {
                *var_r9 = (u8)(s32)((f32)temp_r8 * lbl_80369A80);
            }
            temp_r7 = var_r7 + 1;
            if (temp_r7 < count) {
                var_r9[1] = (u8)(s32)((f32)temp_r8 * lbl_80369A80 + lbl_80369A68);
            } else {
                var_r9[1] = (u8)(s32)((f32)temp_r8 * lbl_80369A80);
            }
            var_r9 += 2;
            var_r7 = temp_r7 + 1;
        }
        var_r8 = (u8 *)&sp8;
        var_r7 = 0;
        for (var_ctr = 3; var_ctr != 0; var_ctr--) {
            if (var_r7 < (s32)((u16)temp_r0 % 3)) {
                *var_r8 = (u8)(s32)(lbl_80369A68 + (f32)(u16)temp_r0 / lbl_80369A84);
            } else {
                *var_r8 = (u8)(s32)((f32)(u16)temp_r0 / lbl_80369A84);
            }
            var_r8 += 1;
            var_r7 += 1;
        }
        sp10.unk0 = lbl_8036C478;
        sp10.unk4 = lbl_8036C47C;
        sp10.unk6 = lbl_8036C47E;
        *(u8 *)&sp10.unk0 = *((u8 *)&spC + 2);
        *((u8 *)&sp10.unk0 + 1) = *(u8 *)&spC;
        *((u8 *)&sp10.unk0 + 2) = *((u8 *)&sp8 + 1);
        *((u8 *)&sp10.unk0 + 3) = *(u8 *)&sp8;
        *(u8 *)&sp10.unk4 = *((u8 *)&sp8 + 2);
        *((u8 *)&sp10.unk4 + 1) = *((u8 *)&spC + 1);
        *((u8 *)&sp10.unk0 + 6) = *((u8 *)&spC + 3);
        fn_80221824(*(u8 *)((u8 *)temp_r3 + 0x19), (u8 *)temp_r3 + 0x1A, 1, &sp10);
    }
}

void fn_800A60A4(void *arg0) {
    void *fn_8006E658(void);
    void fn_8009E64C(void);
    void fn_8009E688(void);
    void fn_800A41B4(void *, u32, u32, s32, s32);
    void fn_800A424C(s32);
    void fn_800A46E0(void);
    s32 x;
    s32 y;
    void *ret;

    fn_8009E688();
    fn_800A424C(*(s32 *)((u8 *)arg0 + 0x50));
    ret = fn_8006E658();
    x = *(s32 *)((u8 *)arg0 + 0x30);
    y = *(s32 *)((u8 *)arg0 + 0x34);
    fn_800A41B4(ret, (u32)(0x260 - x) >> 1, (u32)(0x1C0 - y) >> 1, x, y);
    fn_8009E64C();
    if (*(u8 *)((u8 *)arg0 + 0x55) != 0) {
        fn_800A46E0();
        *(u8 *)((u8 *)arg0 + 0x55) = 0;
    }
}

#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
void fn_800A6114(void *arg0)
{
    void *fn_8006E658(void);
    s16 fn_800A3D08(void);
    void fn_800A3D2C(void *);
    void fn_800A3D74(void *);
    void fn_800A46F4(s32);
    void fn_800A49F4(s32);
    s32 fn_800A4BC4(void);
    void fn_800A4CD8(s32);
    void fn_800A5048(s32);
    s32 fn_800C45B8(s32, void *, s32);
    void fn_80221824(u8, void *, s32, void *);
    u32 OSGetTick(void);
    extern u8 lbl_8026E1B0[];
    extern u8 lbl_80330708[];
    extern s32 lbl_803682A4;
    extern f32 lbl_80369A68;
    extern f32 lbl_80369A80;
    extern f32 lbl_80369A84;
    extern f32 lbl_80369A90;
    extern s32 lbl_8036C478;
    extern u16 lbl_8036C47C;
    extern u8 lbl_8036C47E;
    struct {
        s32 unk0;
        u16 unk4;
        u8 unk6;
    } sp10;
    u8 spC[4];
    u8 sp8[4];
    s32 temp_r0;
    u16 temp_r8;
    s32 var_r7;
    u8 *var_r9;
    s32 count;
    s32 temp_r7;
    unsigned int var_ctr;
    u8 *var_r8;
    void *temp_r3;
    void *self;

    self = arg0;
    if (lbl_803682A4 & 0x40) {
        temp_r3 = fn_8006E658();
        var_r9 = (u8 *)&spC;
        var_r7 = 0;
        temp_r0 = (s32)((f32)(s8)lbl_80330708[0xA1] * lbl_80369A90);
        temp_r8 = (s8)lbl_80330708[0xA1] - (u16)temp_r0;
        count = temp_r8 % 4;
        for (var_r7 = 0; var_r7 < 4; var_r7++) {
            if (var_r7 < count) {
                ((u8 *)&spC)[var_r7] = (u8)(s32)((f32)temp_r8 * lbl_80369A80 + lbl_80369A68);
            } else {
                ((u8 *)&spC)[var_r7] = (u8)(s32)((f32)temp_r8 * lbl_80369A80);
            }
        }
        var_r8 = (u8 *)&sp8;
        var_r7 = 0;
        for (var_ctr = 3; var_ctr != 0; var_ctr--) {
            if (var_r7 < (s32)((u16)temp_r0 % 3)) {
                *var_r8 = (u8)(s32)(lbl_80369A68 + (f32)(u16)temp_r0 / lbl_80369A84);
            } else {
                *var_r8 = (u8)(s32)((f32)(u16)temp_r0 / lbl_80369A84);
            }
            var_r8 += 1;
            var_r7 += 1;
        }
        sp10.unk0 = lbl_8036C478;
        sp10.unk4 = lbl_8036C47C;
        sp10.unk6 = lbl_8036C47E;
        *(u8 *)&sp10.unk0 = *((u8 *)&spC + 2);
        *((u8 *)&sp10.unk0 + 1) = *(u8 *)&spC;
        *((u8 *)&sp10.unk0 + 2) = *((u8 *)&sp8 + 1);
        *((u8 *)&sp10.unk0 + 3) = *(u8 *)&sp8;
        *(u8 *)&sp10.unk4 = *((u8 *)&sp8 + 2);
        *((u8 *)&sp10.unk4 + 1) = *((u8 *)&spC + 1);
        *((u8 *)&sp10.unk0 + 6) = *((u8 *)&spC + 3);
        fn_80221824(*(u8 *)((u8 *)temp_r3 + 0x19), (u8 *)temp_r3 + 0x1A, 1, &sp10);
    }
    if (*(u8 *)((u8 *)self + 0x54) == 0) {
        *(u8 *)((u8 *)self + 0x54) = 1;
    }
    fn_800A5048(2);
    fn_800A4CD8(*(s32 *)((u8 *)self + 0x5C));
    fn_800A3D74((u8 *)self + 0x30);
    fn_800A3D2C((u8 *)self + 0x3C);
    *(s32 *)((u8 *)self + 0x4C) = fn_800C45B8(-fn_800A4BC4(), lbl_8026E1B0 + 0x56, 0);
    fn_800A49F4(*(s32 *)((u8 *)self + 0x4C));
    fn_800A46F4(1);
    {
        u32 tick = OSGetTick();
        u32 period = *(u32 *)((u8 *)self + 0x48);
        *(u32 *)((u8 *)self + 0x50) = tick % period;
    }
    *(s16 *)((u8 *)self + 0x28) = fn_800A3D08();
    *(u8 *)((u8 *)self + 0x55) = 1;
}
#pragma pop
#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_800A6450(void) {
    void fn_8000D3EC(void *, void *);
    void fn_8010554C(void);
    void fn_80196078(void);
    extern u8 lbl_8026E208[];
    extern u8 lbl_8028C6D8[];
    u8 *dst;

    dst = lbl_8028C6D8;
    fn_8000D3EC(lbl_8026E208 + 0xCE, dst + 0x18);
    fn_8000D3EC(lbl_8026E208 + 0xE0, dst + 0x28);
    fn_8000D3EC(lbl_8026E208 + 0xEF, dst + 0x38);
    fn_8000D3EC(lbl_8026E208 + 0x101, dst + 0x48);
    fn_8000D3EC(lbl_8026E208 + 0x113, dst + 0x58);
    fn_8000D3EC(lbl_8026E208 + 0x125, dst + 0x68);
    fn_8000D3EC(lbl_8026E208 + 0x139, dst + 0x68);
    fn_8010554C();
    fn_80196078();
}
#pragma global_optimizer on
s32 fn_800A6510(s32 arg0) {
    void fn_80094A08(s32, s32);
    void Process_CreateChild(void *, s32, void *);
    extern struct {
        s32 unk0;
        s32 unk4;
        u8 unk8;
        u8 unk9;
        s8 unkA;
        u8 pad[0x18 - 0xB];
    } gUiContext;
    extern u8 gBattle[];
    extern u8 lbl_8028C6D8[];

    fn_80094A08(gUiContext.unk0, gUiContext.unkA);
    *(u32 *)(gBattle + 0xCAC) |= 0x2000;
    Process_CreateChild(lbl_8028C6D8, arg0, gBattle);
    return 1;
}

void fn_800A6578(void) {
    void Unit_ApplyTransform(void *);
    extern u8 gUiContext[24];
    Unit_ApplyTransform(*(void **)gUiContext);
}

void fn_800A65A4(s32 arg0) {
    void fn_80183BE4(void *, s32);
    extern u8 gUiContext[];
    fn_80183BE4(*(void **)gUiContext, arg0);
}

s32 fn_800A65D4(s32 arg0) {
    u8 Status_Test(s32, M2C_UNK);
    if (Status_Test(arg0 + 0x1BC, 8) == 0) {
        return 0;
    }
    return Status_Test(arg0 + 0x1BC, 9) == 0;
}

s32 fn_800A6630(s32 arg0) {
    void Battle_SetupUnit(void *, s32, s32);
    void fn_801A4714(void *, u8);
    void fn_8019C8A4(s32, s32);
    extern u16 gUiContext[];
    extern u16 gBattle[];
    u8 *base;

    Battle_SetupUnit(gBattle, *(s32 *)gUiContext, -1);
    fn_801A4714(gBattle, *(u8 *)((u8 *)gUiContext + 0xA));
    base = (u8 *)gBattle;
    ((struct { u8 pad : 3; u8 mid : 3; u8 lo : 2; } *)(base + 0x1A6))->mid = 4;
    fn_8019C8A4(arg0, 0);
    return 1;
}

#pragma global_optimizer off
s32 fn_800A66B4(void) {
    s32 fn_801044E0(s32);
    extern u8 gUiContext[], gMapBlendMode;
    s32 flag;
    u32 t;

    flag = 1;
    t = ((u8)(gMapBlendMode - 1) <= (u32)flag);
    if (!t) {
        flag = 0;
    }
    if ((u8)flag == 0) {
        return 0;
    }
    return fn_801044E0(*(s32 *)gUiContext + 0x1A4);
}
#pragma global_optimizer reset
s32 fn_800A6720(s32 arg0) {
void Battle_SetupUnit(void *, s32, s32);
void fn_801A4714(void *, u8);
void fn_8019CA24(s32, s32);
extern u16 gUiContext[];
extern u16 gBattle[];
u8 *base;
Battle_SetupUnit(gBattle, *(s32 *)gUiContext, -1);
fn_801A4714(gBattle, *(u8 *)((u8 *)gUiContext + 0xA));
base = (u8 *)gBattle;
((struct { u8 hi:3; u8 lo:5; } *)(base + 0x1A6))->hi = 7;
fn_8019CA24(arg0, 0);
return 1;
}

void fn_800A67A4(void) {
    void fn_801044C4(s32);
    extern u8 gUiContext[];
    fn_801044C4(*(s32 *)gUiContext + 0x1A4);
}

s32 fn_800A67D4(s32 arg0) {
    void Battle_SetupUnit(void *, s32, s32);
    void fn_801A4714(void *, u8);
    void fn_8010446C(void *);
    void fn_8019CA6C(s32, s32);
    extern u16 gUiContext[];
    extern u16 gBattle[];

    Battle_SetupUnit(gBattle, *(s32 *)gUiContext, -1);
    fn_801A4714(gBattle, *(u8 *)((u8 *)gUiContext + 0xA));
    fn_8010446C((u8 *)gBattle + 0x1A4);
    fn_8019CA6C(arg0, 0);
    return 1;
}

s32 fn_800A6850(void *arg0) {
    return (((u8) M2C_FIELD(arg0, u8 *, 0x1A4) >> 5U) & 7) != 0;
}

s32 fn_800A6868(s32 arg0) {
    void Battle_SetupUnit(void *, s32, s32);
    void fn_801A47B0(void *, u8, s32);
    void fn_8019C994(s32, s32);
    extern u16 gUiContext[];
    extern u16 gBattle[];

    Battle_SetupUnit(gBattle, *(s32 *)gUiContext, -1);
    fn_801A47B0(gBattle, *(u8 *)((u8 *)gUiContext + 0xA), 0x7F);
    fn_8019C994(arg0, 0);
    return 1;
}

s32 fn_800A68D8(void *arg0) {
    s8 Unit_GetMaxHp();
    u8 temp_r31;

    temp_r31 = M2C_FIELD(arg0, u8 *, 0x1A8);
    return (s8) temp_r31 < Unit_GetMaxHp();
}

s32 fn_800A6920(s32 arg0) {
    void Battle_SetupUnit(void *, s32, s32);
    void fn_801A47B0(void *, u8, s32);
    void fn_8019C9DC(s32, s32);
    extern u16 gUiContext[];
    extern u16 gBattle[];

    Battle_SetupUnit(gBattle, *(s32 *)gUiContext, -1);
    fn_801A47B0(gBattle, *(u8 *)((u8 *)gUiContext + 0xA), 0xA);
    fn_8019C9DC(arg0, 0);
    return 1;
}

s32 fn_800A6990(void *arg0) {
    s8 Unit_GetMaxHp();
    u8 temp_r31;

    temp_r31 = M2C_FIELD(arg0, u8 *, 0x1A8);
    return (s8) temp_r31 < Unit_GetMaxHp();
}

s32 fn_800A69D8(s32 *arg0, s32 *arg1) {
    void *Process_Find(void *);
    void *temp_r3;

    temp_r3 = Process_Find(lbl_8028C750);
    if (temp_r3 != NULL) {
        *arg0 = *(s16 *)((u8 *)temp_r3 + 0x44);
        *arg1 = *(s16 *)((u8 *)temp_r3 + 0x46);
        return 1;
    }
    return 0;
}

void fn_800A6A3C(void) {
    u32 temp_r3 = Process_Find(lbl_8028C750);
    if (temp_r3 != 0) {
        Process_Goto(temp_r3, 7);
    }
}

void fn_800A6A74(void) {
    u32 temp_r3 = Process_Find(lbl_8028C750);
    if (temp_r3 != 0) {
        Process_Goto(temp_r3, 6);
    }
}

void fn_800A6AAC(void) {
    u32 temp_r3 = Process_Find(lbl_8028C750);
    if (temp_r3 != 0) {
        Process_Goto(temp_r3, 5);
    }
}

void fn_800A6AE4(void) {
    u32 temp_r3 = Process_Find(lbl_8028C750);
    if (temp_r3 != 0) {
        Process_Goto(temp_r3, 4);
    }
}

extern u8 lbl_8028C750[16];
void fn_800A6B1C(void) {
    Process_UnlinkByKey(&lbl_8028C750);
}

void fn_800A6B44(s32 arg0) {
    void Process_Create(void *, s32);
    extern u8 lbl_8028C750[16];
    Process_Create(lbl_8028C750, arg0);
}

void fn_800A6B70(void *arg0) {
    f32 Math_Lerp(f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern f32 lbl_80369AA4;
    extern f64 lbl_80369AA8;
    u8 t;

    (void)lbl_80369AA8;
    t = *(u8 *)((u8 *)arg0 + 0x39);
    if (t != 0) {
        *(u8 *)((u8 *)arg0 + 0x39) = (u8)(t - 1);
    }
    *(s8 *)((u8 *)arg0 + 0x38) = (s8)Math_Lerp(
        lbl_80369AA4,
        (f32)(u32)*(u8 *)((u8 *)arg0 + 0x3A),
        (f32)(u32)*(u8 *)((u8 *)arg0 + 0x3B),
        (f32)(u32)*(u8 *)((u8 *)arg0 + 0x39));
    if (*(u8 *)((u8 *)arg0 + 0x39) == 0) {
        Process_ClearFunc(arg0);
        *(u32 *)((u8 *)arg0 + 0x30) = 0;
    }
}

void fn_800A6C24(void *arg0) {
    extern u8 gBattleState[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    void Process_Goto(void *, s32);
    s8 sx;
    s8 sy;
    u8 id;
    void *unit;

    sx = (s8)*(f32 *)(gBattleState + 0x524);
    sy = (s8)*(f32 *)(gBattleState + 0x528);
    id = gBattleMap[sx + (sy << 6) + 0xD];
    if (id != 0) {
        unit = gUnits + (id - 1) * 0x280;
    } else {
        unit = NULL;
    }

    *(void **)((u8 *)arg0 + 0x30) = unit;

    if (*(void **)((u8 *)arg0 + 0x30) == NULL) {
        Process_Goto(arg0, 7);
    }
}

void fn_800A6CC4(void *arg0) {
 f32 Math_Lerp(f32,f32,f32,f32); void Process_ClearFunc(void *);
 extern f32 lbl_80369AA4;
 u8 *p=arg0;
 if(p[0x39]<p[0x3B]) ++p[0x39];
 p[0x38]=(s8)Math_Lerp(lbl_80369AA4,(f32)(u32)p[0x3A],(f32)(u32)p[0x3B],(f32)(u32)p[0x39]);
 if(p[0x39]==p[0x3B]) Process_ClearFunc(arg0);
}

void fn_800A6D78(void *arg0) {
    extern u8 gBattleState[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    void Process_Goto(void *, s32);
    s8 sx;
    s8 sy;
    u8 id;
    void *unit;

    sx = (s8)*(f32 *)(gBattleState + 0x524);
    sy = (s8)*(f32 *)(gBattleState + 0x528);
    id = gBattleMap[sx + (sy << 6) + 0xD];
    if (id != 0) {
        unit = &gUnits[(id - 1) * 0x280];
    } else {
        unit = NULL;
    }

    *(void **)((u8 *)arg0 + 0x30) = unit;
    *(s16 *)((u8 *)arg0 + 0x36) = -1;

    if (*(void **)((u8 *)arg0 + 0x30) == NULL) {
        Process_Goto(arg0, 6);
    }
}

/* Track the unit under the map cursor: goto 2 on appear, 3 on leave; invalidate +0x36 if it changes. */
void MapUi_TrackCursorUnit(void *proc) {
    extern u8 gBattleState[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    void Process_Goto(void *, s32);
    s8 sx;
    s8 sy;
    u8 id;
    void *unit;

    sx = (s8)*(f32 *)(gBattleState + 0x524);
    sy = (s8)*(f32 *)(gBattleState + 0x528);
    id = gBattleMap[sx + (sy << 6) + 0xD];
    if (id != 0) {
        unit = &gUnits[(id - 1) * 0x280];
    } else {
        unit = NULL;
    }

    if (unit != NULL) {
        if (*(void **)((u8 *)proc + 0x30) == NULL) {
            Process_Goto(proc, 2);
        }
        if (*(void **)((u8 *)proc + 0x30) != unit) {
            *(s16 *)((u8 *)proc + 0x36) = -1;
        }
        *(void **)((u8 *)proc + 0x30) = unit;
    } else if (*(void **)((u8 *)proc + 0x30) != NULL) {
        Process_Goto(proc, 3);
    }
}

void fn_800A6F10(void *arg0) {
    extern u8 gBattleState[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    s8 sx;
    s8 sy;
    u8 id;
    void *var;

    sx = (s8)*(f32 *)(gBattleState + 0x524);
    sy = (s8)*(f32 *)(gBattleState + 0x528);
    id = gBattleMap[sx + (sy << 6) + 0xD];
    if (id != 0) {
        var = &gUnits[(id - 1) * 0x280];
    } else {
        var = NULL;
    }
    if (var != NULL) {
        ((u8 *)arg0)[0x39] = ((u8 *)arg0)[0x3B];
        ((u8 *)arg0)[0x38] = ((u8 *)arg0)[0x3A];
        *(void **)((u8 *)arg0 + 0x30) = var;
    } else {
        ((u8 *)arg0)[0x39] = 0;
        ((u8 *)arg0)[0x38] = 0;
        *(void **)((u8 *)arg0 + 0x30) = NULL;
    }
}

void fn_800A6FB8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x39) = 0;
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = -1;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
}

void fn_800A6FD4(void *arg0) {
    void fn_8006D8E8(void *);
    void *ptr;

    ptr = *(void **)((u8 *)arg0 + 0x40);
    if (ptr != NULL) {
        fn_8006D8E8(ptr);
    }
    *(void **)((u8 *)arg0 + 0x40) = NULL;
}

void fn_800A7014(void *arg0) {
    void fn_80055C8C(void *, void *, void *);
    void Process_AttachFunc(void *, void *);
    extern u8 lbl_8026E378[];
    void fn_800A70A0(void);
    void fn_800A70DC(void);

    *(s16 *)((u8 *)arg0 + 0x36) = -1;
    *(u8 *)((u8 *)arg0 + 0x38) = 0;
    *(u8 *)((u8 *)arg0 + 0x39) = 0;
    *(u8 *)((u8 *)arg0 + 0x3A) = 0xE0;
    *(u8 *)((u8 *)arg0 + 0x3B) = 4;
    *(s16 *)((u8 *)arg0 + 0x34) = 0;
    *(s32 *)((u8 *)arg0 + 0x30) = 0;
    *(s16 *)((u8 *)arg0 + 0x44) = -1;
    *(s16 *)((u8 *)arg0 + 0x46) = -1;
    *(s32 *)((u8 *)arg0 + 0x40) = 0;
    fn_80055C8C(lbl_8026E378 + 0x28, fn_800A70A0, arg0);
    Process_AttachFunc(fn_800A70DC, arg0);
}

void fn_800A70A0(void *arg0) {
    s32 fn_8006D948(void *);
    extern u8 lbl_8026E378[];
    *(s32 *)((char *)arg0 + 0x40) = fn_8006D948(lbl_8026E378 + 0x28);
}

void fn_800A70DC(void *self)
{
    typedef struct {
        f32 x, y, z;
    } Position;
    typedef union {
        u32 word;
        struct {
            u8 r, g, b, a;
        } rgba;
    } Color;
    typedef struct {
        Color v[4];
    } ColorTable;

    void fn_8004E670(f32 *, void *, s32);
    void *fn_8003A114(void *);
    void *fn_8007C3BC(void *);
    u8 fn_8007C484(void *);
    void fn_8007C4D4(void *, s32);
    void fn_800793EC(void *, s32);
    s32 fn_8010424C(void *);
    s32 fn_8010418C(void *, s32);
    void Ui_DrawIcon(void *, s32, s32, s32);
    u8 Status_Test(s32, s32);
    void *Unit_GetActiveItemPtr(void *);
    void fn_8008CFB4(void **, s32, s32);
    s32 Msg_ResolveName(void *);
    s8 Unit_GetMaxHp(void *);
    s32 UnitRef_GetName(void *);
    void fn_80006B18(s32, s32, s32, s32, s32);
    void fn_8001003C(s16, s32, s32, s32, s32, void *, ...);
    void fn_800A7938(s32, s32, void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetColorByte(u8);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    void Prim2D_SetScale(f32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetText(void *);
    void Prim2D_SetTint(s32, s32, s32, s32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_SetCornerColors(u32 *, u32 *, u32 *, u32 *);
    void Prim2D_ResetState(void);

    extern u8 gBattleState[];
    extern u8 gUiIconDrawer[];
    extern u8 lbl_8026E378[];
    extern ColorTable lbl_8026E358;
    extern ColorTable lbl_8026E368;
    extern f32 lbl_80369AA4;
    extern f32 lbl_80369AB0;
    extern f32 lbl_80369AB4;
    extern f32 lbl_80369AB8;
    extern f32 lbl_80369ABC;
    extern f32 lbl_80369AC0;
    extern f32 lbl_80369AC4;
    extern f32 lbl_80369AC8;
    extern f32 lbl_80369ACC;
    extern f32 lbl_80369AD0;
    extern f32 lbl_80369AD4;
    extern f32 lbl_80369AD8;
    extern f32 lbl_80369ADC;
    extern f32 lbl_80369AE0;
    extern f32 lbl_80369AE4;
    extern f32 lbl_80369AE8;
    extern f32 lbl_80369AEC;
    extern f32 lbl_80369AF0;
    extern f32 lbl_80369AF4;

    Position position;
    Position screen;
    ColorTable corners;
    ColorTable tints;
    ColorTable colors;
    Color c3, c2, c1, c0;
    register s32 iconX;
    register u8 *p = (u8 *)self;
    register s32 n;
    register u8 *status;
    register s32 count;
    register u8 *drawer;
    register s32 i;
    register f32 x;
    register f32 y;
    s32 ix, iy;
    s32 left, top;
    u8 *unit;
    u8 *resource;

    unit = *(u8 **)(p + 0x30);
    if (unit == 0) {
        return;
    }

    fn_8004E670(&screen.x, unit, 1);
    position = screen;
    ix = (s32)(lbl_80369AB0 + position.x);
    iy = (s32)(lbl_80369AB0 + position.y);
    x = (f32)ix;
    y = (f32)iy;
    left = (s32)(x - lbl_80369AB4);
    top = (s32)(y - lbl_80369AB8);
    *(s16 *)(p + 0x44) = (s16)left;
    *(s16 *)(p + 0x46) = (s16)top;

    if (p[0x38] == 0) {
        return;
    }
    unit = *(u8 **)(p + 0x30);
    if (*(u32 *)(unit + 0x1A0) & 0x18) {
        return;
    }
    if (((gBattleState[0x9C] >> 1) & 1U) == 1U) {
        return;
    }
    if (*(void **)(p + 0x40) == 0) {
        return;
    }

    if (*(s16 *)(p + 0x36) < 0) {
        resource = (u8 *)fn_8007C3BC(fn_8003A114(unit));
        if (resource == 0) {
            return;
        }
        if (fn_8007C484(resource) == 0) {
            fn_8007C4D4(resource, 0);
            return;
        }
        *(s16 *)(p + 0x36) = *(u16 *)(resource + 0x1A);
    }

    Prim2D_Begin();
    Prim2D_SetTransform(x, y, lbl_80369ABC, lbl_80369AC0);
    Prim2D_SetColorByte(p[0x38]);
    Prim2D_PrepareTex();

    iconX = 0x6E;
    status = *(u8 **)(p + 0x30) + 0x1A4;
    count = fn_8010424C(status);
    drawer = gUiIconDrawer;
    i = 0;
    goto icon_test;
icon_body:
    {
        n = count - i - 1;
        Ui_DrawIcon(drawer, iconX, -0x8C, fn_8010418C(status, n));
        switch (fn_8010418C(status, n)) {
        case 0x1B:
            n = (status[0] >> 5) & 7;
            break;
        case 0x1C:
            n = (*(u16 *)status >> 7) & 7;
            break;
        case 0x1D:
            n = (status[1] >> 4) & 7;
            break;
        case 0x1E:
            n = (status[0] >> 2) & 7;
            break;
        case 0x1F:
            n = status[1] & 7;
            break;
        default:
            n = 0;
            break;
        }
        if (n >= 1) {
            Prim2D_Begin();
            Prim2D_AddZ(lbl_80369AC4);
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            fn_8001003C((s16)(iconX + 0x10), -0x8C, 3, 0, 1,
                        lbl_8026E378 + 0x3F, n, lbl_80369AC0, lbl_80369AA4);
            Prim2D_Begin();
            Prim2D_AddZ(lbl_80369AC0);
            Prim2D_PrepareTex();
        }
        iconX -= 0x18;
        ++i;
    }
icon_test:
    if (i < count) {
        goto icon_body;
    }

    if (!Status_Test((s32)(*(u8 **)(p + 0x30) + 0x1BC), 8)) {
        if (Unit_GetActiveItemPtr(*(void **)(p + 0x30)) != 0) {
            fn_8008CFB4((void **)Unit_GetActiveItemPtr(*(void **)(p + 0x30)), -0x14, -0x48);
        }
    }

    Prim2D_Begin();
    Prim2D_SetTransform(x, y, lbl_80369ABC, lbl_80369AC0);
    fn_800793EC(fn_8003A114(*(void **)(p + 0x30)), 0x11);
    Prim2D_SetColorByte(p[0x38]);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    {
        f32 uvZero;
        f32 uvSize;
        uvZero = *(volatile f32 *)&lbl_80369AA4;
        uvSize = *(volatile f32 *)&lbl_80369AD0;
        Prim2D_SetRectUv(lbl_80369AC8, lbl_80369ACC, uvZero,
                         uvZero, uvSize, uvSize);
    }
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_SetTransform(x, y, lbl_80369ABC, lbl_80369AC0);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    Prim2D_AddPrim(6);
    Prim2D_SetScale(lbl_80369AC0);
    Prim2D_SetPos(lbl_80369AD4, lbl_80369AD8);
    Prim2D_SetText((void *)Msg_ResolveName(*(void **)(*(u8 **)(p + 0x30) + 0x188)));
    Prim2D_SetTint(0, 0, 0, 0xFF);
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_EndPrim();

    Prim2D_AddPrim(6);
    Prim2D_SetScale(lbl_80369AC0);
    fn_80006B18(0x19, -0x5E, 0, 0, *(s8 *)(*(u8 **)(p + 0x30) + 0x19A));
    Prim2D_SetTint(0, 0, 0, 0xFF);
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_EndPrim();

    Prim2D_AddPrim(6);
    Prim2D_SetScale(lbl_80369AC0);
    Prim2D_SetPos(lbl_80369ADC, lbl_80369AE0);
    Prim2D_SetText(lbl_8026E378 + 0x42);
    Prim2D_SetTint(0, 0x80, 0, 0xFF);
    Prim2D_SetColor(0, 0x80, 0, 0xFF);
    Prim2D_EndPrim();

    Prim2D_AddPrim(6);
    Prim2D_SetScale(lbl_80369AC0);
    fn_80006B18(0x55, -0x5E, 0, 0, *(s8 *)(*(u8 **)(p + 0x30) + 0x1A8));
    Prim2D_SetTint(0, 0, 0, 0xFF);
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_EndPrim();

    Prim2D_AddPrim(6);
    Prim2D_SetScale(lbl_80369AC0);
    fn_80006B18(0x7D, -0x5E, 0, 0, (s8)Unit_GetMaxHp(*(void **)(p + 0x30)));
    Prim2D_SetTint(0, 0x80, 0, 0xFF);
    Prim2D_SetColor(0, 0x80, 0, 0xFF);
    Prim2D_EndPrim();

    if (Status_Test((s32)(*(u8 **)(p + 0x30) + 0x1BC), 8)) {
        fn_800A7938((s32)(lbl_80369AE4 + x), (s32)(y - lbl_80369AB8), p);
    } else if (Unit_GetActiveItemPtr(*(void **)(p + 0x30)) != 0) {
        Prim2D_AddPrim(6);
        Prim2D_SetScale(lbl_80369AC0);
        Prim2D_SetPos(lbl_80369AE8, lbl_80369AEC);
        Prim2D_SetText((void *)UnitRef_GetName(Unit_GetActiveItemPtr(*(void **)(p + 0x30))));
        Prim2D_SetTint(0, 0, 0, 0xFF);
        Prim2D_SetColor(0, 0, 0, 0xFF);
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_SetTransform((f32)*(s16 *)(p + 0x44), (f32)*(s16 *)(p + 0x46),
                        lbl_80369ABC, lbl_80369AC0);
    Prim2D_SetColorByte(p[0x38]);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_BindTexture(*(s32 *)(p + 0x40), 0, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(3);
    Prim2D_SetRectUv(lbl_80369AA4, lbl_80369AA4, lbl_80369AA4, lbl_80369AA4,
                     lbl_80369AF0, lbl_80369AF4);
    Prim2D_EmitQuad();

    {
        Color *base;
        Color *out;
        Color *tint;
        s32 j;
        s32 faction;

        faction = (*(u8 **)(*(u8 **)(p + 0x30) + 0x190))[8];
        colors = lbl_8026E358;
        tints = lbl_8026E368;
        tint = &tints.v[faction];
        base = colors.v;
        out = corners.v;
        for (j = 0; j < 2; ++j) {
            out[0].rgba.r = (u8)((tint->rgba.r * base[0].rgba.r) / 255);
            out[0].rgba.g = (u8)((tint->rgba.g * base[0].rgba.g) / 255);
            out[0].rgba.b = (u8)((tint->rgba.b * base[0].rgba.b) / 255);
            out[0].rgba.a = tint->rgba.a;
            out[1].rgba.r = (u8)((tint->rgba.r * base[1].rgba.r) / 255);
            out[1].rgba.g = (u8)((tint->rgba.g * base[1].rgba.g) / 255);
            out[1].rgba.b = (u8)((tint->rgba.b * base[1].rgba.b) / 255);
            out[1].rgba.a = tint->rgba.a;
            base += 2;
            out += 2;
        }
    }
    c3 = corners.v[3];
    c2 = corners.v[2];
    c1 = corners.v[1];
    c0 = corners.v[0];
    Prim2D_SetCornerColors(&c0.word, &c1.word, &c2.word, &c3.word);
    Prim2D_EndPrim();
    Prim2D_ResetState();
}

#pragma push
#pragma optimization_level 4
#pragma use_lmw_stmw on
#pragma opt_common_subs off
void fn_800A7938(s32 arg0, s32 arg1, void *arg2) {
    s8 fn_8003C114(void *);
    void fn_80006B18(s32, s32, s32, s32, s32);
    void fn_8000727C(f32);
    void fn_80007290(s32, s32, s32, s32);
    void fn_800075D8(void);
    void fn_80007668(u32 *);
    void fn_800076AC(s32, s32, s32, s32);
    void fn_8000770C(f32, f32, f32, f32, f32, f32);
    void fn_80007884(void);
    void fn_80007898(s32);
    void fn_80009B28(void);
    void fn_80009B8C(u8);
    void fn_80009D74(f32, f32, f32, f32);
    void fn_80009F90(s32, s32, s32);
    void fn_8000A248(void);
    void fn_8000A174(s32, s32);
    void fn_8000A258(void);
    void *fn_8000D354(void *);
    u8 fn_80105BC0(void *, s32);
    extern u32 lbl_80369A98;
    extern u32 lbl_80369A9C;
    extern u32 lbl_80369AA0;
    extern const f32 lbl_80369AA4;
    extern const f32 lbl_80369ABC;
    extern const f32 lbl_80369AC0;
    extern const f32 lbl_80369B00;
    extern const f32 lbl_80369B04;
    extern const f32 lbl_80369B08;
    extern const f32 lbl_80369B0C;
    extern const f32 lbl_80369B14;
    extern const f32 lbl_80369B10;
    extern const f32 lbl_80369B18;
    extern const f32 lbl_80369B1C;
    extern const f32 lbl_80369B20;
    u32 sp10;
    unsigned long spC;
    register s32 r28;
    u16 flags;
    s32 t;
    u32 sp8;
    void *temp_r3;
    unsigned long var_r26;
    s32 r27;
    void *r29;
    s8 temp_r31;
    void *var_r30;
    s32 icon;

    r27 = arg0;
    r29 = arg2;
    r28 = arg1;
    temp_r31 = (s8)fn_8003C114(*(void **)((u8 *)arg2 + 0x30));
    var_r30 = *(void **)((u8 *)*(void **)((u8 *)r29 + 0x30) + 0x18C);
    fn_8000A258();
    fn_80009D74((f32)r27, (f32)r28, lbl_80369ABC, lbl_80369AC0);
    fn_8000A174(0, 0x13);
    fn_8000A248();
    fn_80007898(6);
    fn_8000727C(lbl_80369AC0);
    fn_80006B18(0xDE, 0x30, 0, 0, temp_r31);
    fn_80007290(0x80, 0x40, 0x40, 0xFF);
    fn_800076AC(0x80, 0x40, 0x40, 0xFF);
    fn_80007884();
    var_r26 = 3;
    if (fn_80105BC0((u8 *)*(void **)((u8 *)r29 + 0x30) + 0x1BC, 9) != 0) {
        var_r26 = 4;
    } else {
        if (*(void **)((u8 *)var_r30 + 0xC) != NULL) {
            temp_r3 = fn_8000D354(*(void **)((u8 *)var_r30 + 0xC));
        } else {
            temp_r3 = NULL;
        }
        var_r30 = temp_r3;
    }
    fn_8000A258();
    fn_80009D74((f32)r27, (f32)r28, lbl_80369ABC, lbl_80369AC0);
    fn_80009F90(*(s32 *)((u8 *)r29 + 0x40), var_r26, 0x11);
    fn_80009B8C(*(u8 *)((u8 *)r29 + 0x38));
    fn_8000A248();
    fn_80007898(2);
    t = temp_r31 * 0x50;
    fn_8000770C(lbl_80369B00, lbl_80369B04, lbl_80369AA4, lbl_80369AA4, (f32)(t / 20), lbl_80369B08);
    fn_800075D8();
    sp10 = lbl_80369A98;
    fn_80007668(&sp10);
    fn_80007884();
    flags = *(u16 *)((u8 *)var_r30 + 0x3A);
    icon = 0;
    if (flags & 0x40) {
        icon = 5;
    } else if (flags & 0x100) {
        icon = 6;
    } else if (flags & 0x80) {
        icon = 9;
    }
    fn_8000A258();
    fn_80009D74((f32)r27, (f32)r28, lbl_80369ABC, lbl_80369AC0);
    fn_80009F90(*(s32 *)((u8 *)r29 + 0x40), icon, 0x11);
    fn_80009B8C(*(u8 *)((u8 *)r29 + 0x38));
    fn_8000A248();
    fn_80007898(2);
    fn_8000770C(lbl_80369B0C, lbl_80369B10, lbl_80369AA4, lbl_80369AA4, lbl_80369B14, lbl_80369B14);
    fn_800075D8();
    spC = lbl_80369A9C;
    fn_80007668(&spC);
    fn_80007884();
    fn_8000A258();
    fn_80009D74((f32)r27, (f32)r28, lbl_80369ABC, lbl_80369AC0);
    fn_80009F90(*(s32 *)((u8 *)r29 + 0x40), 1, 0x11);
    fn_80009B8C(*(u8 *)((u8 *)r29 + 0x38));
    fn_8000A248();
    fn_80007898(2);
    fn_8000770C(lbl_80369B18, lbl_80369B1C, lbl_80369AA4, lbl_80369AA4, lbl_80369B20, lbl_80369B14);
    fn_800075D8();
    sp8 = lbl_80369AA0;
    fn_80007668(&sp8);
    fn_80007884();
    fn_80009B28();
}
#pragma pop
#pragma use_lmw_stmw on
void fn_800A7C94(void *arg0) {
    void *Process_Create(void *, void *);
    void fn_8006EEFC(void **, s32);
    void *Heap_AllocRaw(s32);
    void *fn_8022C414(void *, void *, void *, s32, s32);
    s32 Rand_Range(s32);
    void Ui_LoadAtlasTex(void *, void *, u16);
    u16 GXGetTexObjWidth(void *);
    s16 GXGetTexObjHeight(void *);
    u8 fn_80006650(void *, void *);
    void fn_80006608(void *);
    void Heap_FreeRaw(void *);
    extern u8 lbl_8028C7F8[];
    extern u8 lbl_8028C814[];
    extern s32 lbl_80369B2C;
    extern s32 lbl_80369B28;
    extern f32 lbl_80369B30;
    extern f32 lbl_80369B34;
    extern f64 lbl_80369B38;
    extern void fn_800A7EC0();

    struct {
        s32 sp8;
        s32 spC;
        u8 sp10[0x20];
        u16 sp30;
        s16 sp32;
    } st;
    s32 r31;
    s32 r30;
    s32 r29;
    void *r28;
    s32 r27;
    void *r26;
    void *r25;
    s16 r24;
    void *r23;
    s16 *r22;

    r25 = Process_Create(lbl_8028C7F8, arg0);
    st.spC = lbl_80369B2C;
    st.sp8 = lbl_80369B28;
    fn_8006EEFC((void **)((u8 *)r25 + 0x30), st.spC);
    r26 = *(void **)((u8 *)r25 + 0x30);
    r27 = 0x64;
    r28 = fn_8022C414(Heap_AllocRaw(0x110), (void *)fn_800A7EC0, NULL, 8, 0x20);
    r29 = 0;
    r22 = (s16 *)r28;
    do {
        s16 adj;
        s16 tmp16;
        u16 t;
        u16 texIdx;
        r30 = Rand_Range(8) + 2;
        texIdx = (u16)r30;
        Ui_LoadAtlasTex(r26, st.sp10, texIdx);
        st.sp30 = GXGetTexObjWidth(st.sp10);
        tmp16 = GXGetTexObjHeight(st.sp10);
        t = st.sp30;
        st.sp32 = tmp16;
        r22[0] = 0;
        r22[1] = 0;
        r22[2] = t;
        r22[3] = tmp16;
        for (;;) {
            r24 = Rand_Range(0x200);
            adj = (s16)(Rand_Range(st.sp30 + 0x260) - ((u32)st.sp30 >> 1));
            r22[0] += adj;
            r22[1] += r24;
            r22[2] += adj;
            r22[3] += r24;
            for (r31 = 0, r23 = r28; r31 < r29; r23 = (u8 *)r23 + 8, r31++) {
                if (fn_80006650(r22, r23)) {
                    fn_80006608(r22);
                    if (--r27 < 0)
                        goto cleanup;
                    goto next_try;
                }
            }
            break;
        next_try:
            ;
        }
        r23 = Process_Create(lbl_8028C814, r25);
        *(f32 *)((u8 *)r23 + 0x34) = (f32)r22[0];
        *(f32 *)((u8 *)r23 + 0x38) = (f32)r22[1];
        *(s32 *)((u8 *)r23 + 0x44) = r30;
        *(void **)((u8 *)r23 + 0x30) = r25;
        *(f32 *)((u8 *)r23 + 0x3C) = lbl_80369B30;
        *(f32 *)((u8 *)r23 + 0x40) = (*(f32 *)((u8 *)r23 + 0x3C) / lbl_80369B34) * (f32)Rand_Range(0x8000);
        r29 += 1;
        r22 += 4;
    } while (r29 < 0x20);
cleanup:
    if (r28 != NULL)
        Heap_FreeRaw((u8 *)r28 - 0x10);
}
#pragma optimization_level reset
#pragma opt_common_subs reset
#pragma use_lmw_stmw reset
void fn_800A7EC0(void) {

}

#pragma use_lmw_stmw on
void fn_800A7EC4(void *arg0) {
    void *Process_Create(void *, void *);
    void fn_8006EEFC(void *, s32);
    s32 Rand_Range(s32);
    void Heap_AllocRaw(s32);
    void *fn_8022C414(void (*)(void), s32, s32, s32);
    void Ui_LoadAtlasTex(s32, void *, u16);
    u16 GXGetTexObjWidth(void *);
    s16 GXGetTexObjHeight(void *);
    u8 fn_80006650(void *, void *);
    void fn_80006608(void *);
    void Heap_FreeRaw(void *);
    void fn_800A7EC0(void);
    extern u8 lbl_8028C7F8[];
    extern u8 lbl_8028C814[];
    extern s32 lbl_80369B28;
    extern s32 lbl_80369B2C;
    extern f32 lbl_80369B30;
    extern f32 lbl_80369B34;
    extern f64 lbl_80369B38;
    void *res;
    s32 sp8;
    s32 spC;
    u8 sp10[0x20];
    u16 sp30;
    s16 sp32;
    s32 unk30;
    s32 retry;
    void *arr;
    s32 count;
    u8 *cur;
    u16 span;
    u16 a;
    s16 b;
    s16 dy;
    s16 dx;
    u8 *scan;
    s32 idx;
    void *obj;

    res = Process_Create(lbl_8028C7F8, arg0);
    sp8 = lbl_80369B28;
    spC = lbl_80369B2C;
    fn_8006EEFC((u8 *)res + 0x30, lbl_80369B28);
    unk30 = M2C_FIELD(res, s32 *, 0x30);
    retry = 0x64;
    Heap_AllocRaw(0x110);
    arr = fn_8022C414(fn_800A7EC0, 0, 8, 0x20);
    count = 0;
    cur = (u8 *)arr;
    while (count < 0x20) {
        span = Rand_Range(8) + 2;
        Ui_LoadAtlasTex(unk30, sp10, span);
        a = GXGetTexObjWidth(sp10);
        b = GXGetTexObjHeight(sp10);
        sp30 = a;
        sp32 = b;
        M2C_FIELD(cur, u16 *, 0) = 0;
        M2C_FIELD(cur, u16 *, 2) = 0;
        M2C_FIELD(cur, u16 *, 4) = sp30;
        M2C_FIELD(cur, u16 *, 6) = sp32;
recompute:
        dy = Rand_Range(0x200);
        scan = (u8 *)arr;
        idx = 0;
        dx = Rand_Range(span + 0x260) - (span >> 1);
        M2C_FIELD(cur, s16 *, 0) += dx;
        M2C_FIELD(cur, s16 *, 2) += dy;
        M2C_FIELD(cur, s16 *, 4) += dx;
        M2C_FIELD(cur, s16 *, 6) += dy;
        while (idx < count) {
            if (fn_80006650(cur, scan) != 0) {
                fn_80006608(cur);
                if (--retry < 0) {
                    goto cleanup;
                }
                goto recompute;
            }
            scan += 8;
            idx++;
        }
        obj = Process_Create(lbl_8028C814, res);
        M2C_FIELD(obj, f32 *, 0x34) = (f32) M2C_FIELD(cur, s16 *, 0);
        M2C_FIELD(obj, f32 *, 0x38) = (f32) M2C_FIELD(cur, s16 *, 2);
        M2C_FIELD(obj, u32 *, 0x44) = span;
        M2C_FIELD(obj, void **, 0x30) = res;
        M2C_FIELD(obj, f32 *, 0x3C) = lbl_80369B30;
        M2C_FIELD(obj, f32 *, 0x40) = (M2C_FIELD(obj, f32 *, 0x3C) / lbl_80369B34) * (f32) Rand_Range(0x8000);
        count++;
        cur += 8;
    }
cleanup:
    if (arr != NULL) {
        Heap_FreeRaw((u8 *)arr - 0x10);
    }
}
#pragma use_lmw_stmw reset

void fn_800A80F0(void *arg0) {
    M2C_UNK Prim2D_SetTex(void *, M2C_UNK);
    M2C_UNK Ui_LoadAtlasTex(s32, void *, u16);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    f64 fn_802380D0(f32);
    void Prim2D_SetRect(f32,f32,f32,f32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_SetColor(s32,s32,s32,s32);
    extern f32 lbl_80369B40;
    extern f32 lbl_80369B44;
    extern f32 lbl_80369B48;
    extern f32 lbl_80369B4C;
    extern f32 lbl_80369B50;
    extern f32 lbl_80369B54;
    struct { u32 tex[8]; u16 width,height; } st;
    f32 rate;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f31;
    s32 temp_r3;
    u32 temp_r6;

    rate = lbl_80369B40 / M2C_FIELD(arg0, f32 *, 0x3C);
    temp_f31 = (f32) fn_802380D0(rate * M2C_FIELD(arg0, f32 *, 0x40));
    temp_f31 = lbl_80369B44 * temp_f31 + lbl_80369B44;
    M2C_FIELD(arg0, f32 *, 0x40) = (f32) (M2C_FIELD(arg0, f32 *, 0x40) + lbl_80369B48);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x40);
    temp_f1 = M2C_FIELD(arg0, f32 *, 0x3C);
    if (temp_f0 > temp_f1) {
        M2C_FIELD(arg0, f32 *, 0x40) = (f32) (temp_f0 - temp_f1);
    }
    Ui_LoadAtlasTex(M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x30), st.tex, (u16) M2C_FIELD(arg0, s32 *, 0x44));
    st.width = GXGetTexObjWidth(st.tex);
    st.height = GXGetTexObjHeight(st.tex);
    Prim2D_Begin();
    Prim2D_SetTex(st.tex, 0x20);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    temp_r6 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), u32 *, 0x34);
    temp_r3 = (s32) ((lbl_80369B4C + M2C_FIELD(arg0, f32 *, 0x38)) - (f32)((s32)temp_r6 / 2)) & 0x1FF;
    Prim2D_SetRect( M2C_FIELD(arg0, f32 *, 0x34), (f32) (temp_r3 - 0x20), (f32) st.width, (f32) st.height);
    Prim2D_SetColor(0xC0, 0xC0, 0xFF, (s32) (lbl_80369B50 * temp_f31));
    Prim2D_SetPrimParam(lbl_80369B54);
    Prim2D_EndPrim();
}

void fn_800A828C(s32 arg0) {
    FileCache_ReleaseSlot(arg0 + 0x30);
}

/* Draw a frame-scrolled background layer, then a gray tint overlay. */
void Bg_DrawScrollLayers(void *self) {
    s32 Game_GetFrameCount(void);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetUvCorners(s32, f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    extern f32 gScrollBgZero;
    extern f32 gScrollBgDepth;
    extern f32 gScrollBgOne;
    extern f32 gScrollBgWidth;
    extern f32 gScrollBgHeight;
    extern f32 gScrollBgUvScale;
    extern f32 gScrollBgUvH;
    extern f32 gScrollBgPrimParam;
    extern f32 gScrollBgOverlayParam;
    f32 uvOff;
    s32 scroll;

    *(s32 *)((u8 *)self + 0x34) = (s32)(Game_GetFrameCount() & 0x3FF);
    Prim2D_Begin();
    Prim2D_SetTransform(gScrollBgZero, gScrollBgZero, gScrollBgDepth, gScrollBgOne);
    Prim2D_BindTexture(*(s32 *)((u8 *)self + 0x30), 0, 0);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect(gScrollBgZero, gScrollBgZero, gScrollBgWidth, gScrollBgHeight);
    scroll = *(s32 *)((u8 *)self + 0x34);
    uvOff = gScrollBgUvScale * (f32)scroll;
    Prim2D_SetUvCorners(scroll, gScrollBgZero, uvOff, gScrollBgOne, gScrollBgUvH + uvOff);
    Prim2D_SetPrimParam(gScrollBgPrimParam);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_BindTexture(*(s32 *)((u8 *)self + 0x30), 1, 0x30);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect(gScrollBgZero, gScrollBgZero, gScrollBgWidth, gScrollBgHeight);
    Prim2D_SetColor(0x32, 0x32, 0x32, 0);
    Prim2D_SetPrimParam(gScrollBgOverlayParam);
    Prim2D_EndPrim();
}

s32 fn_800A83C8(void) {
    extern u16 lbl_8026E3C0[8];
    s32 Process_FindByName(void *);
    return Process_FindByName((u8 *)lbl_8026E3C0 + 0x39) != 0;
}

void fn_800A8400(void) {
    M2C_UNK fn_8009A514();
    M2C_UNK fn_800A6A3C();
    M2C_UNK fn_8018DB4C();
    fn_8009A514();
    fn_800A6A3C();
    fn_8018DB4C();
}

void fn_800A8428(void) {
    M2C_UNK fn_8009A54C();
    M2C_UNK fn_800A6A74();
    M2C_UNK fn_8018DB90();
    fn_8009A54C();
    fn_800A6A74();
    fn_8018DB90();
}

void fn_800A8450(void) {
    M2C_UNK fn_8009A584();
    M2C_UNK fn_800A6AAC();
    M2C_UNK fn_8018DC18();
    fn_8009A584();
    fn_800A6AAC();
    fn_8018DC18();
}

void fn_800A8478(void) {
    M2C_UNK fn_8009A5BC();
    M2C_UNK fn_800A6AE4();
    M2C_UNK fn_8018DC58();
    fn_8009A5BC();
    fn_800A6AE4();
    fn_8018DC58();
}

void fn_800A84A0(void) {
    M2C_UNK fn_8009A5F4();
    M2C_UNK fn_800A6B1C();
    M2C_UNK fn_8018DC98();
    fn_8009A5F4();
    fn_800A6B1C();
    fn_8018DC98();
}

void fn_800A84C8(s32 arg0) {
    M2C_UNK fn_8018DCC0(s32);
    M2C_UNK fn_800A6B44(s32);
    M2C_UNK fn_8009A61C();
    fn_8009A61C();
    fn_800A6B44(arg0);
    fn_8018DCC0(arg0);
}

u32 fn_800A8504(void *arg0, u32 arg1) {
    u8 *ptr;
    u32 temp;

    ptr = *(u8 **)((u8 *)arg0 + 0x34);
    temp = __cntlzw(0x2A - (s32)*(s8 *)(ptr + (arg1 & 0xFF)));

    return temp >> 5;
}

u8 *fn_800A8524(void *arg0, void *arg1, u8 arg2) {
void strcpy(void *,void *);
void strcat(void *,void *);
char *strchr(const char *,s32);
u8 *a;
u8 *b;
u32 ka,kb;
strcpy(lbl_80312A80,(u8 *)lbl_8026E408+8);
a=(u8 *)strchr(*(char **)arg0,'_')+1;
b=(u8 *)strchr(*(char **)arg1,'_')+1;
ka=((s8)a[2]<<8)+((s8)a[1]<<16)+(s8)a[3]+(a[0]<<24);
kb=((s8)b[2]<<8)+((s8)b[1]<<16)+(s8)b[3]+(b[0]<<24);
if(ka<kb) {
strcat(lbl_80312A80,a);
strcat(lbl_80312A80,(u8 *)lbl_8026E408+15);
strcat(lbl_80312A80,b);
} else {
strcat(lbl_80312A80,b);
strcat(lbl_80312A80,(u8 *)lbl_8026E408+15);
strcat(lbl_80312A80,a);
}
switch(arg2) {
case 1: strcat(lbl_80312A80,(u8 *)lbl_8026E408+17); break;
case 2: strcat(lbl_80312A80,(u8 *)lbl_8026E408+20); break;
case 3: strcat(lbl_80312A80,(u8 *)lbl_8026E408+23); break;
}
return lbl_80312A80;
}

u8 *fn_800A8704(void *arg0) {
    void strcpy(void *, void *);
    void strcat(void *, char *);
    char *strchr(const char *, int);
    char *temp;

    strcpy(lbl_80312A80, (u8 *)lbl_8026E408 + 0x26);
    temp = strchr(*(char **)arg0, 0x5F);
    strcat(lbl_80312A80, temp + 1);
    return lbl_80312A80;
}

u8 *fn_800A876C(void *arg0) {
    void strcpy(void *, void *);
    void strcat(void *, char *);
    char *strchr(const char *, int);
    char *temp;

    strcpy(lbl_80312A80, (u8 *)lbl_8026E408 + 0x2C);
    temp = strchr(*(char **)arg0, 0x5F);
    strcat(lbl_80312A80, temp + 1);
    return lbl_80312A80;
}

u8 *fn_800A87D4(void *arg0) {
    void strcpy(void *, void *);
    void strcat(void *, char *);
    char *strchr(const char *, int);
    char *temp;

    strcpy(lbl_80312A80, (u8 *)lbl_8026E408 + 0x32);
    temp = strchr(*(char **)arg0, 0x5F);
    strcat(lbl_80312A80, temp + 1);
    return lbl_80312A80;
}

s32 fn_800A883C(void *arg0, s32 arg1) { u8 val; u8 *p = &val; u32 n; if (arg1 == 0) n = (*(u8 *)((u8 *)arg0 + 0x43) >> 4) & 15; else n = *(u8 *)((u8 *)arg0 + 0x43) & 15; *p = n; return *p << 24; }

s32 fn_800A886C(u8 *arg0) {
    switch (*arg0) {
    case 0:
        return 0;
    case 1:
        return 0x4E;
    case 2:
        return 0x47;
    case 3:
        return 0x48;
    case 4:
        return 0x49;
    case 5:
        return 0x4A;
    case 6:
        return 0x4B;
    case 7:
        return 0x4C;
    case 8:
        return 0x4D;
    default:
        return 0;
    }
}

u8 *fn_800A88E0(void *arg0) {
    void strcpy(void *, void *);
    void strcat(void *, s32);

    strcpy(lbl_80312A80, (u8 *)lbl_8026E408 + 0x58);
    strcat(lbl_80312A80, *(s32 *)((char *)arg0 + 0xC) + 4);
    return lbl_80312A80;
}

void *fn_800A893C(void *arg0) {
    void *Msg_Expand(void *);
    u32 field = *(u32 *)((u8 *)arg0 + 0x8);

    if (field == 0) {
        return (void *)((u8 *)lbl_8026E408 + 0x5f);
    }
    return Msg_Expand((void *)field);
}

s32 fn_800A8978(void *arg0) {
    s32 Msg_Expand(s32);
    if (Res_GetByName(M2C_FIELD(arg0, s32 *, 4)) != 0U) {
        return Msg_Expand(M2C_FIELD(arg0, s32 *, 4));
    }
    return M2C_FIELD(arg0, s32 *, 0);
}

void *fn_800A89C0(void *arg0) {
    void *memset(void *, int, unsigned int);
    *(short *)((char *)arg0 + 0x3A) = 0;
    memset(arg0, 0, 0x64);
    return arg0;
}

s32 fn_800A8A00(s32 *arg0) {
    s32 strchr(s32, M2C_UNK);
    return strchr(*arg0, 0x5F) + 1;
}

s32 fn_800A8A2C(s32 arg0) {
    memset((void*)arg0, 0, 0x64);
    return arg0;
}

void fn_800A8A64(void *arg0) {
    M2C_UNK Msg_Expand(s32);
    Msg_Expand(M2C_FIELD(arg0, s32 *, 8));
}

s32 Msg_ResolveName(void *arg0) {
    s32 Msg_Expand(s32);
    s32 Res_GetByName(s32);
    s32 fn_8007C378(s32);
    if (*(u32 *)((u8 *)arg0 + 4) != 0U) {
        return Msg_Expand(*(s32 *)((u8 *)arg0 + 4));
    }
    if (Res_GetByName(*(s32 *)((u8 *)arg0 + 0xC)) != 0U) {
        return fn_8007C378(*(s32 *)((u8 *)arg0 + 0xC));
    }
    return *(s32 *)arg0;
}

void fn_800A8AE4(s32 arg0) {
    extern u16 gOptionsStr[];
    FileCache_ReleaseSlot(arg0 + 0x30);
    fn_8005C7C8(&gOptionsStr[0x58 / sizeof(u16)]);
}

void fn_800A8B18(void *arg0) {
 void FileCache_Load(void *); void fn_8006EEFC(void *, void *); s32 fn_80005E2C(s32); void Process_Goto(void *, s32);
 extern u8 gOptionsStr[]; extern u8 lbl_803677FC;
 FileCache_Load(gOptionsStr + 0x58);
 fn_8006EEFC((u8 *)arg0 + 0x30, gOptionsStr + 0x62);
 *(s32 *)((u8 *)arg0 + 0x34) = 0;
 ((u8 *)arg0)[0x38] = 0;
 if (lbl_803677FC == 0 && fn_80005E2C(0) == 0) Process_Goto(arg0, 1);
 lbl_803677FC = 1;
}

void fn_800A8BA0(void) {
    extern u8 gOptionsStr[];
    void fn_80109020(s32);
    void fn_801481CC(void *, s32);

    fn_80109020(0);
    fn_801481CC(gOptionsStr + 0x73, 0x1F4);
}

void fn_800A8BD8(void *arg0) {
    void Ui_PlaySeCue(void *, s32);
    void fn_801481CC(void *, s32);
    void Process_Goto(void *, s32);
    extern u8 *gPadInput;
    extern u8 gOptionsStr[];

    if (*(u32 *)(gPadInput + 4) & 0x1100) {
        Ui_PlaySeCue((u8 *)&gOptionsStr + 0x82, 0x64);
        fn_801481CC((u8 *)&gOptionsStr + 0x73, 0x1F4);
        ((u8 *)arg0)[0x38] = 1;
        Process_Goto(arg0, 2);
    }
}

#pragma optimization_level 2
#pragma opt_common_subs off
/* Advance the frame counter and draw the prompt base sprite plus two pulsing overlays. */
void Ui_DrawPromptSprites(void *proc) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Prim2D_SetAlpha(s32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Ui_LoadAtlasTex(void *, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    extern f32 lbl_80369BA8;
    extern f32 lbl_80369BAC;
    extern f32 gOptionsIdentityScale;
    extern f32 lbl_80369BB4;
    extern f32 lbl_80369BB8;
    extern f32 lbl_80369BBC;
    extern f32 lbl_80369BC0;
    extern f32 lbl_80369BC4;
    extern f32 lbl_80369BC8;
    extern f32 lbl_80369BCC;
    extern f32 lbl_80369BD0;
    extern f32 lbl_80369BD4;
    extern f32 lbl_80369BD8;
    extern f32 lbl_80369BDC;
    extern f32 lbl_80369BE0;
    extern f32 lbl_80369BE4;
    extern f32 lbl_80369BE8;
    extern f32 lbl_80369BEC;
    extern f32 lbl_80369BF0;
    struct {
        u8 buf[0x20];
        u16 x;
        u16 y;
    } st;
    f32 pulse;
    s32 frame;
    s32 shade;
    void *self;

    self = proc;
    *(s32 *)((u8 *)self + 0x34) = *(s32 *)((u8 *)proc + 0x34) + 1;
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_80369BA8, lbl_80369BA8, lbl_80369BAC, gOptionsIdentityScale);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(*(void **)((u8 *)self + 0x30), st.buf, 0);
    st.x = GXGetTexObjWidth(st.buf);
    st.y = GXGetTexObjHeight(st.buf);
    Prim2D_Begin();
    Prim2D_SetTex(st.buf, 0);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect(lbl_80369BB4, lbl_80369BB8, (f32)(u32)st.x, (f32)(u32)st.y);
    Prim2D_EndPrim();
    if (*(u8 *)((u8 *)self + 0x38) == 0 || !(*(s32 *)((u8 *)self + 0x34) & 4)) {
        frame = *(s32 *)((u8 *)self + 0x34);
        pulse = Math_Ease(0, lbl_80369BBC, lbl_80369BC0, (f32)(frame % 60), lbl_80369BC4);
        if (pulse > lbl_80369BCC) {
            pulse = lbl_80369BC8 - pulse;
        }
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_80369BA8, lbl_80369BA8, lbl_80369BD0, gOptionsIdentityScale);
        Prim2D_PrepareTex();
        Ui_LoadAtlasTex(*(void **)((u8 *)self + 0x30), st.buf, 1);
        st.x = GXGetTexObjWidth(st.buf);
        st.y = GXGetTexObjHeight(st.buf);
        Prim2D_Begin();
        Prim2D_SetTex(st.buf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect(lbl_80369BD4, lbl_80369BD8, (f32)(u32)st.x, (f32)(u32)st.y);
        Prim2D_SetAlpha((s32)pulse);
        Prim2D_EndPrim();
        frame = *(s32 *)((u8 *)self + 0x34);
        pulse = Math_Ease(0, lbl_80369BDC, lbl_80369BE0, (f32)(frame % 180), lbl_80369BE4);
        if (pulse > lbl_80369BCC) {
            pulse = lbl_80369BC8 - pulse;
        }
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_80369BA8, lbl_80369BA8, lbl_80369BE8, gOptionsIdentityScale);
        Prim2D_PrepareTex();
        Ui_LoadAtlasTex(*(void **)((u8 *)self + 0x30), st.buf, 2);
        st.x = GXGetTexObjWidth(st.buf);
        st.y = GXGetTexObjHeight(st.buf);
        Prim2D_Begin();
        Prim2D_SetTex(st.buf, 0x10);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect(lbl_80369BEC, lbl_80369BF0, (f32)(u32)st.x, (f32)(u32)st.y);
        shade = (s32)pulse;
        Prim2D_SetColor(shade, shade, shade, 0xFF);
        Prim2D_EndPrim();
    }
}
void fn_800A8F94(s32 arg0) {
    void *Sound_Create(void *, s32);
    void fn_80148618(void *, s32);
    extern u8 gOptionsStr[];
    extern f32 lbl_80369C08;
    extern const f32 lbl_80369BA8;
    f32 b;
    f32 a;
    f32 *p = (f32 *)((u8 *)Sound_Create(gOptionsStr + 0x96, arg0) + 0x40);
    a = lbl_80369C08;
    b = lbl_80369BA8;
    p[0] = a;
    p[1] = b;
    fn_80148618(gOptionsStr + 0x73, 500);
}

#pragma optimization_level reset
#pragma opt_common_subs reset
void fn_800A8FE8(void *arg0) {
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    u8 fn_800A5C88(void);
    extern void *gPadInput;
    s32 temp_r5;

    temp_r5 = *(s32 *)((u8 *)gPadInput + 4);
    if (temp_r5 & (*(s32 *)((u8 *)gPadInput + 8) ^ temp_r5) & 0x1100) {
        Process_ClearFunc(arg0);
        return;
    }
    if (fn_800A5C88() == 0) {
        Process_Goto(arg0, 0);
    }
}

void fn_800A904C(s32 arg0)
{
    void fn_800A5D1C(void *, u8, s32);
    extern u8 gOptionsStr[];
    s32 cond;

    cond = arg0 != 0;
    fn_800A5D1C((void *)((u32)gOptionsStr + 0xA3), cond, 0);
}

extern u8 lbl_8028C870[16];
void fn_800A9088(s32 arg0) {
    void Process_CreateChild(void *, s32);
    extern u8 lbl_8028C870[16];
    Process_CreateChild(lbl_8028C870, arg0);
}

void fn_800A90B4(void) {
    void fn_80148618(void *, s32);
    extern u8 gOptionsStr[];
    fn_80148618(gOptionsStr + 0x73, 0x1F4);
}

void fn_800A90E4(s32 arg0) {
    void Ui_PlaySeCue(void *, s32);
    void Process_ClearFunc(s32);
    extern void *gPadInput;
    extern u8 gOptionsStr[];
    s32 temp_r3;

    temp_r3 = *(s32 *)((u8 *)gPadInput + 4);
    if (temp_r3 & (*(s32 *)((u8 *)gPadInput + 8) ^ temp_r3) & 0x1F70) {
        Ui_PlaySeCue(gOptionsStr + 0x82, 0x64);
        Process_ClearFunc(arg0);
    }
}

void fn_800A9144(void) {
    void fn_801481CC(void *, s32);
    extern u8 gOptionsStr[];
    fn_801481CC(gOptionsStr + 0x73, 0x1F4);
}

extern void *D_800E53FC;
void fn_800A9174(void) {
    void *fn_8017A764(void *, void *, s32);
    s32 fn_8017A950(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    void fn_800C4588(void *);
    extern u8 gOptionsStr[];
    extern f32 lbl_80369BA8;
    extern f32 lbl_80369C0C;
    extern f32 gOptionsIdentityScale;
    extern u8 lbl_802842B8[];
    extern u8 gStreamBaseVtbl[];
    struct {
        void *ptr;
        u8 *cur;
        s32 unk8;
        u8 flag;
        u8 pad[3];
        void *vt;
    } tmp;
    struct { s32 a; s32 b; } res;

    fn_8017A764(&tmp, gOptionsStr + 0xb5, 0);
    tmp.cur += 4;
    res.a = fn_8017A950(&tmp);
    res.b = fn_8017A950(&tmp);
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_80369BA8, lbl_80369BA8, lbl_80369C0C, gOptionsIdentityScale);
    Prim2D_SetTex(0, 3);
    Prim2D_PrepareTex();
    fn_8001003C(0xb8, 0x190, 1, 0, 1, gOptionsStr + 0xc2, res.a, res.b, gOptionsIdentityScale, lbl_80369BA8);
    tmp.vt = lbl_802842B8;
    tmp.vt = gStreamBaseVtbl;
    if (tmp.flag != 0) {
        fn_800C4588(tmp.ptr);
        tmp.ptr = 0;
        tmp.flag = 0;
    }
}

void fn_800A9274(s32 arg0) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK lbl_803677EC;
    Ui_CreateMenu(&lbl_803677EC, arg0, 0);
}

void fn_800A92A0(void) {
    M2C_UNK SaveData_Release(M2C_UNK *);
    extern M2C_UNK gSaveDataBase;
    SaveData_Release(&gSaveDataBase);
}

void fn_800A92C4(s32 arg0) {
    M2C_UNK fn_801E3118(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK gSaveDataBase;
    fn_801E3118(&gSaveDataBase, arg0, 0);
}

void fn_800A92F0(void) {
    extern u16 gOptionsStr[];
    fn_8005C7C8(&gOptionsStr[0x58 / sizeof(u16)]);
}

void fn_800A931C(s32 arg0) {
    void fn_8005BCD0(void);
    void FileCache_Load(void *);
    void *Sound_Create(void *, s32);
    extern u8 gOptionsStr[];
    void *temp_r3;
    f32 f0;
    f32 f1;

    FileCache_Load(gOptionsStr + 0x58);
    fn_8005BCD0();
    temp_r3 = Sound_Create(gOptionsStr + 0x96, arg0);
    f0 = 64.0f;
    f1 = 0.0f;
    *(f32 *)((u8 *)temp_r3 + 0x40) = f0;
    f0 = -10.0f;
    *(f32 *)((u8 *)temp_r3 + 0x44) = f1;
    *(f32 *)((u8 *)temp_r3 + 0x48) = f0;
}

#include "common.h"
extern u16 lbl_8026E168[];
extern void *D_800E53FC;
extern void *gOptionsStr;
extern f32 lbl_80369BA8;
extern f32 lbl_80369C0C;
extern f32 gOptionsIdentityScale;
extern u8 lbl_802842B8[];
extern u8 gStreamBaseVtbl[];
