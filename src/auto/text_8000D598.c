/* Functions from 0x80006264 to 0x80011968, found by decomp-toolkit. */
#include "common.h"
#pragma cplusplus on
struct TextWidthFontInterface {
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
};
#pragma cplusplus reset

typedef struct {
    void *unk0;
    void *unk4;
    s32 unk8;
} Struct_8000B090;

extern s32 lbl_802AEE20[5]; // array of 5 pointers
static inline s32 Text_FindFontIndex(u32 *p, u32 result) {
    s32 i;
    for(i=0;i<5;i++,p++) {
        if(*p==result) return i;
    }
    return -1;
}
extern f64 lbl_80368C28;    // global float constant
extern u16 jumptable_80283AE8[];

extern f64 lbl_80368C28;

extern u16 gPrim2D;

extern void *(*lbl_80366DA0)(s32);
extern f32 gFloat1, lbl_80368BB8, lbl_80368B98;
extern u32 gProcessOpcodeTables[9];

extern void *fn_8000A738(void *, s32);
extern void fn_8000B5F0(void *);
extern void fn_8000B70C(void *);

typedef struct HashKey {
    u32 h1;
    u32 h2;
} HashKey;

extern struct UnkStruct_802AEE80 gUnk_802AEE80;

extern s32 gUnknown_0x80369C84;
extern s32 gUnknown_0x80369C88;

s32 fn_8000D598(s8 *arg0) {
    s32 h = 0;
    while (*arg0 != 0) {
        h = *arg0++ + h * 0x25;
    }
    return h;
}

#pragma push
#pragma use_lmw_stmw on
#pragma peephole on
void fn_8000D5C8(void) {
 void *fn_800C4638(s32, void *, s32);
 extern u8 lbl_802ADB20[];
 extern u8 lbl_80267D40[];
 u32 i;
 for(i=0;(s32)i<0x1FD;i++) {
 *(s32 *)(lbl_802ADB20+8+i*4)=0;
 *(s32 *)(lbl_802ADB20+0x7FC+i*4)=0;
 }
 *(s32 *)lbl_802ADB20=0;
 *(void **)(lbl_802ADB20+4)=fn_800C4638(0x28000,lbl_80267D40+0x78,0);
 for(i=0;i<0x2800;i++) {
 (*(s32 **)(lbl_802ADB20+4))[i*4]=0;
 (*(s32 **)(lbl_802ADB20+4))[i*4+1]=0;
 (*(s32 **)(lbl_802ADB20+4))[i*4+2]=0;
 (*(s32 **)(lbl_802ADB20+4))[i*4+3]=0;
 }
}
#pragma pop
void fn_8000D864(s32 arg0, char *arg1) {
    void strcpy(char *, char *);
    s32 strlen(char *);
    extern u8 lbl_802AED10[];
    u8 *temp_r31;
    char *temp_r30;

    temp_r31 = lbl_802AED10 + (arg0 * 0x44);
    temp_r30 = arg1;
    *(s32 *)temp_r31 = strlen(temp_r30);
    strcpy((char *)(temp_r31 + 4), temp_r30);
}

void *fn_8000D8BC(s32 arg0, char *arg1) {
    void fn_80238ABC(char *, char *, s32);
    s32 strlen(char *);
    extern u8 lbl_802AED10[];
    u8 *temp_r31;

    temp_r31 = lbl_802AED10 + (arg0 * 0x44);
    fn_80238ABC(arg1, (char *)(temp_r31 + 4), 0xA);
    *(s32 *)temp_r31 = strlen((char *)(temp_r31 + 4));
    return temp_r31 + 4;
}

u8 *fn_8000D910(u8 *arg0, u8 arg1) {
    u8 *Res_GetByName(u8 *);
    void fn_80231E74(u8 *, s32, void *, u8 *, ...);
    void strcpy(u8 *, void *);
    extern u8 lbl_80267DC0[];
    extern u8 lbl_802AEB10[];
    extern u8 lbl_802AED10[];
    extern u8 *lbl_80366DA8;

    u8 sp8[0x80];
    u8 *entry;
    u32 need;
    u8 *src;
    u8 *dst;
    u8 *out;
    u8 *p;
    u8 *resolved;
    u8 c;
    u8 c1;
    u8 sjis;

    if (arg1 == 0) {
        resolved = Res_GetByName(arg0);
        if (resolved == NULL) {
            return arg0;
        }
        if ((s32)*resolved == 0x40) {
            src = resolved + 1;
            need = 0;
            p = src;
            while ((c = *p), (s8)c != 0) {
                if ((s8)c == 0x40) {
                    c1 = p[1];
                    p += 1;
                    switch ((s8)c1) {
                    case 0x40:
                        p += 1;
                        need += 1;
                        break;
                    case 0x7B:
                        c1 = p[1];
                        p += 3;
                        need += *(s32 *)(lbl_802AED10 + (((s8)c1 - 0x30) * 0x44));
                        break;
                    default:
                        need += 1;
                        goto count_body;
                    }
                } else {
count_body:
                    c = *p;
                    if ((((c >= 0x81U) && (c <= 0x9FU)) || ((c >= 0xE0U) && (c <= 0xFCU))) &&
                        (((c1 = p[1], c1 >= 0x40U) && (c1 <= 0x7EU)) || ((c1 >= 0x80U) && (c1 <= 0xFCU)))) {
                        sjis = 1;
                    } else {
                        sjis = 0;
                    }
                    if (sjis != 0) {
                        need += 2;
                        p += 2;
                    } else {
                        need += 1;
                        p += 1;
                    }
                }
            }
            if ((u32)(0x200 - (lbl_80366DA8 - lbl_802AEB10)) <= need) {
                lbl_80366DA8 = lbl_802AEB10;
            }
            dst = lbl_80366DA8;
            out = dst;
            while ((c = *src), (s8)c != 0) {
                if ((s8)c == 0x40) {
                    c1 = src[1];
                    src += 1;
                    switch ((s8)c1) {
                    case 0x40:
                        src += 1;
                        *dst = 0x40;
                        dst += 1;
                        break;
                    case 0x7B:
                        c1 = src[1];
                        src += 3;
                        entry = lbl_802AED10 + (((s8)c1 - 0x30) * 0x44);
                        strcpy(dst, entry + 4);
                        dst += *(s32 *)entry;
                        break;
                    default:
                        *dst = 0x40;
                        dst += 1;
                        goto copy_body;
                    }
                } else {
copy_body:
                    c = *src;
                    if ((((c >= 0x81U) && (c <= 0x9FU)) || ((c >= 0xE0U) && (c <= 0xFCU))) &&
                        (((c1 = src[1], c1 >= 0x40U) && (c1 <= 0x7EU)) || ((c1 >= 0x80U) && (c1 <= 0xFCU)))) {
                        sjis = 1;
                    } else {
                        sjis = 0;
                    }
                    if (sjis != 0) {
                        dst[0] = src[0];
                        c1 = src[1];
                        src += 2;
                        dst[1] = c1;
                        dst += 2;
                    } else {
                        c1 = *src;
                        src += 1;
                        *dst = c1;
                        dst += 1;
                    }
                }
            }
            *dst = 0;
            lbl_80366DA8 = dst + 1;
            return out;
        }
        return resolved;
    }

    fn_80231E74(sp8, 0x80, lbl_80267DC0, arg0);
    if (Res_GetByName(sp8) == NULL) {
        resolved = Res_GetByName(arg0);
        if (resolved == NULL) {
            return arg0;
        }
        if ((s32)*resolved == 0x40) {
            src = resolved + 1;
            need = 0;
            p = src;
            while ((c = *p), (s8)c != 0) {
                if ((s8)c == 0x40) {
                    c1 = p[1];
                    p += 1;
                    switch ((s8)c1) {
                    case 0x40:
                        p += 1;
                        need += 1;
                        break;
                    case 0x7B:
                        c1 = p[1];
                        p += 3;
                        need += *(s32 *)(lbl_802AED10 + (((s8)c1 - 0x30) * 0x44));
                        break;
                    default:
                        need += 1;
                        goto count_body2;
                    }
                } else {
count_body2:
                    c = *p;
                    if ((((c >= 0x81U) && (c <= 0x9FU)) || ((c >= 0xE0U) && (c <= 0xFCU))) &&
                        (((c1 = p[1], c1 >= 0x40U) && (c1 <= 0x7EU)) || ((c1 >= 0x80U) && (c1 <= 0xFCU)))) {
                        sjis = 1;
                    } else {
                        sjis = 0;
                    }
                    if (sjis != 0) {
                        need += 2;
                        p += 2;
                    } else {
                        need += 1;
                        p += 1;
                    }
                }
            }
            if ((u32)(0x200 - (lbl_80366DA8 - lbl_802AEB10)) <= need) {
                lbl_80366DA8 = lbl_802AEB10;
            }
            dst = lbl_80366DA8;
            out = dst;
            while ((c = *src), (s8)c != 0) {
                if ((s8)c == 0x40) {
                    c1 = src[1];
                    src += 1;
                    switch ((s8)c1) {
                    case 0x40:
                        src += 1;
                        *dst = 0x40;
                        dst += 1;
                        break;
                    case 0x7B:
                        c1 = src[1];
                        src += 3;
                        entry = lbl_802AED10 + (((s8)c1 - 0x30) * 0x44);
                        strcpy(dst, entry + 4);
                        dst += *(s32 *)entry;
                        break;
                    default:
                        *dst = 0x40;
                        dst += 1;
                        goto copy_body2;
                    }
                } else {
copy_body2:
                    c = *src;
                    if ((((c >= 0x81U) && (c <= 0x9FU)) || ((c >= 0xE0U) && (c <= 0xFCU))) &&
                        (((c1 = src[1], c1 >= 0x40U) && (c1 <= 0x7EU)) || ((c1 >= 0x80U) && (c1 <= 0xFCU)))) {
                        sjis = 1;
                    } else {
                        sjis = 0;
                    }
                    if (sjis != 0) {
                        dst[0] = src[0];
                        c1 = src[1];
                        src += 2;
                        dst[1] = c1;
                        dst += 2;
                    } else {
                        c1 = *src;
                        src += 1;
                        *dst = c1;
                        dst += 1;
                    }
                }
            }
            *dst = 0;
            lbl_80366DA8 = dst + 1;
            return out;
        }
        return resolved;
    }

    resolved = Res_GetByName(sp8);
    if (resolved == NULL) {
        return sp8;
    }
    if ((s32)*resolved == 0x40) {
        src = resolved + 1;
        need = 0;
        p = src;
        while ((c = *p), (s8)c != 0) {
            if ((s8)c == 0x40) {
                c1 = p[1];
                p += 1;
                switch ((s8)c1) {
                case 0x40:
                    p += 1;
                    need += 1;
                    break;
                case 0x7B:
                    c1 = p[1];
                    p += 3;
                    need += *(s32 *)(lbl_802AED10 + (((s8)c1 - 0x30) * 0x44));
                    break;
                default:
                    need += 1;
                    goto count_body3;
                }
            } else {
count_body3:
                c = *p;
                if ((((c >= 0x81U) && (c <= 0x9FU)) || ((c >= 0xE0U) && (c <= 0xFCU))) &&
                    (((c1 = p[1], c1 >= 0x40U) && (c1 <= 0x7EU)) || ((c1 >= 0x80U) && (c1 <= 0xFCU)))) {
                    sjis = 1;
                } else {
                    sjis = 0;
                }
                if (sjis != 0) {
                    need += 2;
                    p += 2;
                } else {
                    need += 1;
                    p += 1;
                }
            }
        }
        if ((u32)(0x200 - (lbl_80366DA8 - lbl_802AEB10)) <= need) {
            lbl_80366DA8 = lbl_802AEB10;
        }
        dst = lbl_80366DA8;
        out = dst;
        while ((c = *src), (s8)c != 0) {
            if ((s8)c == 0x40) {
                c1 = src[1];
                src += 1;
                switch ((s8)c1) {
                case 0x40:
                    src += 1;
                    *dst = 0x40;
                    dst += 1;
                    break;
                case 0x7B:
                    c1 = src[1];
                    src += 3;
                    entry = lbl_802AED10 + (((s8)c1 - 0x30) * 0x44);
                    strcpy(dst, entry + 4);
                    dst += *(s32 *)entry;
                    break;
                default:
                    *dst = 0x40;
                    dst += 1;
                    goto copy_body3;
                }
            } else {
copy_body3:
                c = *src;
                if ((((c >= 0x81U) && (c <= 0x9FU)) || ((c >= 0xE0U) && (c <= 0xFCU))) &&
                    (((c1 = src[1], c1 >= 0x40U) && (c1 <= 0x7EU)) || ((c1 >= 0x80U) && (c1 <= 0xFCU)))) {
                    sjis = 1;
                } else {
                    sjis = 0;
                }
                if (sjis != 0) {
                    dst[0] = src[0];
                    c1 = src[1];
                    src += 2;
                    dst[1] = c1;
                    dst += 2;
                } else {
                    c1 = *src;
                    src += 1;
                    *dst = c1;
                    dst += 1;
                }
            }
        }
        *dst = 0;
        lbl_80366DA8 = dst + 1;
        return out;
    }
    return resolved;
}

u8 *Msg_Expand(u8 *arg0) {
    u8 *Res_GetByName();
    M2C_UNK strcpy(u8 *, void *);
    extern u8 lbl_802AEB10;
    extern M2C_UNK lbl_802AED10;
    extern u8 *lbl_80366DA8;
    s32 *temp_r28;
    u32 var_r5;
    u8 *temp_r31;
    u8 *var_r29;
    u8 *var_r30;
    u8 *var_r3;
    u8 *var_r6;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r0_3;
    u8 temp_r0_4;
    u8 temp_r0_5;
    u8 temp_r0_6;
    u8 temp_r0_7;
    u8 temp_r0_8;
    u8 temp_r0_9;
    u8 temp_r3;
    u8 temp_r3_2;
    u8 temp_r4;
    u8 var_r0;
    u8 var_r0_2;

    var_r3 = Res_GetByName();
    if (var_r3 == NULL) {
        return arg0;
    }
    if ((s32) *var_r3 == 0x40) {
        var_r29 = var_r3 + 1;
        var_r5 = 0U;
        var_r6 = var_r29;
loop_25:
        temp_r3 = M2C_FIELD(var_r6, u8 *, 0);
        if ((s8) temp_r3 != 0) {
            if ((s8) temp_r3 == 0x40) {
                temp_r0 = M2C_FIELD(var_r6, u8 *, 1);
                var_r6 += 1;
                switch ((s8) temp_r0) {             /* switch 1; irregular */
                case 0x40:                          /* switch 1 */
                    var_r6 += 1;
                    var_r5 += 1;
                    break;
                case 0x7B:                          /* switch 1 */
                    temp_r0_2 = M2C_FIELD(var_r6, u8 *, 1);
                    var_r6 += 3;
                    var_r5 += *(&lbl_802AED10 + (((s8) temp_r0_2 - 0x30) * 0x44));
                    break;
                default:                            /* switch 1 */
                    var_r5 += 1;
                    goto block_12;
                }
            } else {
block_12:
                temp_r0_3 = M2C_FIELD(var_r6, u8 *, 0);
                if ((((temp_r0_3 >= 0x81U) && (temp_r0_3 <= 0x9FU)) || ((temp_r0_3 >= 0xE0U) && (temp_r0_3 <= 0xFCU))) && (((temp_r0_4 = M2C_FIELD(var_r6, u8 *, 1), ((temp_r0_4 < 0x40U) == 0)) && (temp_r0_4 <= 0x7EU)) || ((temp_r0_4 >= 0x80U) && (temp_r0_4 <= 0xFCU)))) {
                    var_r0 = 1;
                } else {
                    var_r0 = 0;
                }
                if (var_r0 != 0) {
                    var_r5 += 2;
                    var_r6 += 2;
                } else {
                    var_r5 += 1;
                    var_r6 += 1;
                }
            }
            goto loop_25;
        }
        if ((u32) (0x200 - (lbl_80366DA8 - &lbl_802AEB10)) <= var_r5) {
            lbl_80366DA8 = &lbl_802AEB10;
        }
        var_r30 = lbl_80366DA8;
        temp_r31 = var_r30;
loop_50:
        temp_r3_2 = M2C_FIELD(var_r29, u8 *, 0);
        if ((s8) temp_r3_2 != 0) {
            if ((s8) temp_r3_2 == 0x40) {
                temp_r0_5 = M2C_FIELD(var_r29, u8 *, 1);
                var_r29 += 1;
                switch ((s8) temp_r0_5) {           /* switch 2; irregular */
                case 0x40:                          /* switch 2 */
                    var_r29 += 1;
                    *var_r30 = 0x40;
                    var_r30 += 1;
                    break;
                case 0x7B:                          /* switch 2 */
                    temp_r4 = M2C_FIELD(var_r29, u8 *, 1);
                    var_r29 += 3;
                    temp_r28 = &lbl_802AED10 + (((s8) temp_r4 - 0x30) * 0x44);
                    strcpy(var_r30, temp_r28 + 4);
                    var_r30 = &var_r30[*temp_r28];
                    break;
                default:                            /* switch 2 */
                    *var_r30 = 0x40;
                    var_r30 += 1;
                    goto block_37;
                }
            } else {
block_37:
                temp_r0_6 = M2C_FIELD(var_r29, u8 *, 0);
                if ((((temp_r0_6 >= 0x81U) && (temp_r0_6 <= 0x9FU)) || ((temp_r0_6 >= 0xE0U) && (temp_r0_6 <= 0xFCU))) && (((temp_r0_7 = M2C_FIELD(var_r29, u8 *, 1), ((temp_r0_7 < 0x40U) == 0)) && (temp_r0_7 <= 0x7EU)) || ((temp_r0_7 >= 0x80U) && (temp_r0_7 <= 0xFCU)))) {
                    var_r0_2 = 1;
                } else {
                    var_r0_2 = 0;
                }
                if (var_r0_2 != 0) {
                    M2C_FIELD(var_r30, u8 *, 0) = M2C_FIELD(var_r29, u8 *, 0);
                    temp_r0_8 = M2C_FIELD(var_r29, u8 *, 1);
                    var_r29 += 2;
                    M2C_FIELD(var_r30, u8 *, 1) = temp_r0_8;
                    var_r30 += 2;
                } else {
                    temp_r0_9 = M2C_FIELD(var_r29, u8 *, 0);
                    var_r29 += 1;
                    M2C_FIELD(var_r30, u8 *, 0) = temp_r0_9;
                    var_r30 += 1;
                }
            }
            goto loop_50;
        }
        var_r3 = temp_r31;
        *var_r30 = 0;
        lbl_80366DA8 = var_r30 + 1;
    }
    return var_r3;
}

int fn_8000E7FC(int a0, int a1, int a2, int a3, int a4, int a5, float f0, float f1, float f2, float f3, float f4);
void fn_8000E394(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
 u32 *table;
 u32 result;
 s32 index;
 u32 *p;
 index = 3;
 result = (u32)fn_8010494C(lbl_802AEE20[index]);
 table = (u32 *)lbl_802AEE20;
 if (table[0] == result) index = 0;
 else {
 p = table + 1;
 if (table[1] == result) index = 1;
 else if (*++p == result) index = 2;
 else if (*++p == result) index = 3;
 else if (p[1] == result) index = 4;
 else index = -1;
 }
 fn_8000E7FC(arg0,arg1,arg2,arg3,arg4,arg5,farg0,farg1,farg2,farg3,farg4);
 if (index == -1) index = 0;
 result = (u32)fn_8010494C(lbl_802AEE20[index]);
 for (index = 0, p = table; index < 5; ++index, ++p) {
 if (*p == result) break;
 }
}

#pragma push
#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8000E50C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    u32 *table;
    u32 result;
    s32 index;
    u32 *p;

    index = 2;
    result = (u32)fn_8010494C(lbl_802AEE20[index]);
    table = (u32 *)lbl_802AEE20;
    if (table[0] == result) {
        index = 0;
    } else {
        p = table + 1;
        if (table[1] == result) {
            index = 1;
        } else if (*++p == result) {
            index = 2;
        } else if (*++p == result) {
            index = 3;
        } else if (p[1] == result) {
            index = 4;
        } else {
            index = -1;
        }
    }
    fn_8000E7FC(arg0, arg1, arg2, arg3, arg4, arg5, farg0, farg1, farg2, farg3, farg4);
    if (index == -1) {
        index = 0;
    }
    result = (u32)fn_8010494C(lbl_802AEE20[index]);
    if (table[0] != result) {
        p = table + 1;
        if (table[1] != result) {
            if (*++p != result) {
                if (*++p != result) {
                    if (p[1] != result) {
                    }
                }
            }
        }
    }
}
#pragma pop
void fn_8000E684(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
u32 *table;
u32 result;
s32 index;
u32 *p;
index=0;
result=(u32)fn_8010494C(lbl_802AEE20[index]);
table=(u32*)lbl_802AEE20;
index=-1;
{ s32 i; for(i=0,p=table;i<5;++i,++p) { if(*p==result) { index=i; break; } } }
fn_8000E7FC(arg0,arg1,arg2,arg3,arg4,arg5,farg0,farg1,farg2,farg3,farg4);
if(index==-1) index=0;
result=(u32)fn_8010494C(lbl_802AEE20[index]);
for(index=0,p=table;index<5;++index,++p) { if(*p==result) break; }
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
int fn_8000E7FC(int a0, int a1, int a2, int a3, int a4, int a5, float f0, float f1, float f2, float f3, float f4)
{
    void *fn_801047D0(void);
    void *fn_801047DC(u8 *);
    u8 *fn_801049E0(u8 *, s32 *, s32 *, s32 *, s32 *, s32 *, u8, u8, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void fn_80224E50(void *, s32, s32);
    void fn_80222644(void *, s32, u16, u16, u16, u32, u32, u32);
    void fn_80222C50(void *, u32);
    void GXBegin(u32, u32, u32);
    u8 *Ui_GetColor(s32);
    extern void *lbl_80367168;
    extern f32 lbl_80368BDC;
    extern u32 lbl_80368BD8;
    extern f32 lbl_80368BE0;
    extern f32 lbl_80368BE4;
    extern f32 lbl_80368BE8;
    extern f32 lbl_80368BB8;
    extern u8 lbl_802838E8[];
    extern void *lbl_80367174;
    register u8 *digits;
    u8 *font;
    void *obj;
    f32 matrix[3][4];
    s16 w, h;
    u32 flg_w, flg_h;
    u8 *str;
    u8 *c0;
    u8 *c1;
    s32 ch;
    s32 code;
    f32 xpos, ypos, zpos;
    f32 scale, scale2;
    f32 fpad0, fpad1, fpad2, fpad3, fpad4, fpad5, fpad6, fpad7;
    u8 color[4];
    u8 save_r, save_g, save_b, save_a;
    s16 digi, shift;
    s32 val;
    s32 sp18, sp14, sp10, spC, sp8;
    u32 sp1C[8];
    void *glyph;
    u8 gw, gh;
    f32 fx, fy, fxa, fw, fh, fadv;
    f32 t0, t1, t2, t3;
    u8 cr, cg, cb, ca;
    u8 cr2, cg2, cb2, ca2;
    s32 alpha;
    s32 alpha_scaled;
    f32 f18;
    s32 ctr;
    s32 unk;
    void *mtxbase;
    void *unkptr;

    w = (s16)a0;
    h = (s16)a1;
    xpos = f0;
    zpos = f1;
    ypos = f2;
    fpad0 = f3;
    fpad1 = f4;
    alpha = a2;
    c0 = (u8 *)a3;
    c1 = (u8 *)a4;
    str = (u8 *)a5;
    *(u32 *)color = lbl_80368BD8;
    font = fn_801047D0();
    scale = lbl_80368BDC;
    scale2 = scale;
    flg_w = ((u32)(-(s32)w) | (u32)(s32)w) >> 31;
    flg_h = ((u32)(-(s32)h) | (u32)(s32)h) >> 31;
    unk = 0;
    if (flg_w == 0) {
        w = 0x200;
    }
    if (flg_h == 0) {
        h = 0x100;
    }
    obj = lbl_80367168;
    if (obj != 0) {
        (*(void (**)(void *))(*(u32 *)obj + 0x14))(obj);
        (*(void (**)(void *))(*(u32 *)obj + 0x18))(obj);
    }
    PSMTXScale(matrix, lbl_80368BDC / (f32)*(u16 *)(font + 0x1e),
        lbl_80368BDC / (f32)*(u16 *)(font + 0x20), lbl_80368BDC);
    fn_80224E50(matrix, 0x1e, 1);
    alpha_scaled = ((u8)alpha * 0xff) >> 7;
    mtxbase = lbl_802838E8;
    unkptr = &lbl_80367174;
    f18 = lbl_80368BB8;
    fpad2 = fpad0;
    fpad3 = fpad1;
    fpad4 = xpos;
    fpad5 = ypos;
    fpad6 = zpos;
    fpad7 = scale;
    ctr = -1;
    while ((ch = *(s8 *)str) != 0) {
        ctr = -1;
        if (ch == '#') {
            ch = (s8)str[1];
            str += 2;
            code = ch - '#';
            if ((u32)code <= 0x56U) {
                switch (code) {
                case 0:
                    save_r = color[0];
                    save_g = color[1];
                    save_b = color[2];
                    save_a = color[3];
                    digits = (u8 *)__alloca(8);
                    digi = 0;
                    while ((u8)digi < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') {
                            digits[(u8)digi] = (u8)(ch - '0');
                        } else if (ch >= 'a' && ch <= 'f') {
                            digits[(u8)digi] = (u8)(ch - 0x57);
                        } else if (ch >= 'A' && ch <= 'F') {
                            digits[(u8)digi] = (u8)(ch - 0x37);
                        }
                        digi += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) {
                        val += digits[digi] << shift;
                        digi -= 1; shift += 4;
                    }
                    {
                        u8 *cp = Ui_GetColor((u8)val);
                        color[0] = cp[0]; color[1] = cp[1];
                        color[2] = cp[2]; color[3] = cp[3];
                    }
                    break;
                case 30:
                    digits = (u8 *)__alloca(8);
                    digi = 0;
                    while ((u8)digi < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[(u8)digi] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[(u8)digi] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[(u8)digi] = (u8)(ch - 0x37);
                        digi += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
                    color[0] = (u8)val;
                    break;
                case 31:
                    digits = (u8 *)__alloca(8);
                    digi = 0;
                    while ((u8)digi < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[(u8)digi] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[(u8)digi] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[(u8)digi] = (u8)(ch - 0x37);
                        digi += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
                    color[1] = (u8)val;
                    break;
                case 32:
                    digits = (u8 *)__alloca(8);
                    digi = 0;
                    while ((u8)digi < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[(u8)digi] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[(u8)digi] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[(u8)digi] = (u8)(ch - 0x37);
                        digi += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
                    color[2] = (u8)val;
                    break;
                case 36:
                    digits = (u8 *)__alloca(8);
                    digi = 0;
                    while ((u8)digi < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[(u8)digi] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[(u8)digi] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[(u8)digi] = (u8)(ch - 0x37);
                        digi += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
                    color[3] = (u8)val;
                    break;
                case 48:
                case 54:
                    digits = (u8 *)__alloca(8);
                    digi = 0;
                    while ((u8)digi < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[(u8)digi] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[(u8)digi] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[(u8)digi] = (u8)(ch - 0x37);
                        digi += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
                    scale = (f32)(u32)val * lbl_80368BE0;
                    scale2 = scale;
                    break;
                case 33:
                case 64:
                case 66:
                case 70:
                case 76:
                case 80:
                case 85:
                case 86:
                    scale = lbl_80368BDC;
                    scale2 = scale;
                    break;
                case 35:
                    digits = (u8 *)__alloca(8);
                    digi = 0;
                    while ((u8)digi < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[(u8)digi] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[(u8)digi] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[(u8)digi] = (u8)(ch - 0x37);
                        digi += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
                    (void)val;
                    break;
                case 45:
                    str += 3;
                    break;
                case 38:
                case 47:
                case 53:
                    str += 2;
                    break;
                default:
                    break;
                }
            }
            continue;
        }
        glyph = fn_801047DC(str);
        gw = *(u8 *)((char *)glyph + 8);
        gh = *(u8 *)((char *)glyph + 9);
        fx = ((f32)(s8)*(u8 *)((char *)glyph + 0xA) * scale2) + xpos;
        fy = -(((f32)(s8)*(u8 *)((char *)glyph + 0xB) * scale2) - (((f32)*(u16 *)((char *)font + 8) * scale2) + ypos));
        fw = (f32)gw;
        fh = (f32)gh;
        {
            f32 tmpb = (f32)(s8)*(u8 *)((char *)glyph + 0xB);
            str = fn_801049E0(str, &sp18, &sp14, &sp10, &spC, &sp8, gh, gw, tmpb);
        }
        t0 = (f32)sp14;
        t1 = (f32)sp10;
        fadv = (f32)sp8;
        fn_80222644(sp1C, sp18, *(u16 *)((char *)font + 0x1E), *(u16 *)((char *)font + 0x20), *(u16 *)((char *)font + 0x18), 0, 0, 0);
        fn_80222C50(sp1C, 0);
        fxa = (scale2 * (f18 * (fadv - (f32)spC))) + fx;
        GXBegin(0x80, 0, 4);
        cr = (u8)((color[0] * alpha_scaled) >> 7);
        cg = (u8)((color[1] * alpha_scaled) >> 7);
        cb = (u8)((color[2] * alpha_scaled) >> 7);
        ca = color[3];
        cr2 = c0[0]; cg2 = c0[1]; cb2 = c0[2]; ca2 = c0[3];
        *(volatile f32 *)0xCC008000 = fxa;
        *(volatile f32 *)0xCC008000 = fy;
        *(volatile f32 *)0xCC008000 = zpos;
        *(volatile u8 *)0xCC008000 = cr;
        *(volatile u8 *)0xCC008000 = cg;
        *(volatile u8 *)0xCC008000 = cb;
        *(volatile u8 *)0xCC008000 = ca;
        *(volatile f32 *)0xCC008000 = t0;
        *(volatile f32 *)0xCC008000 = t1;
        t2 = fxa + (fw * scale2);
        t3 = fy + (fh * scale2);
        *(volatile f32 *)0xCC008000 = t2;
        *(volatile f32 *)0xCC008000 = fy;
        *(volatile f32 *)0xCC008000 = zpos;
        *(volatile u8 *)0xCC008000 = cr;
        *(volatile u8 *)0xCC008000 = cg;
        *(volatile u8 *)0xCC008000 = cb;
        *(volatile u8 *)0xCC008000 = ca;
        *(volatile f32 *)0xCC008000 = t0 + fw;
        *(volatile f32 *)0xCC008000 = t1;
        *(volatile f32 *)0xCC008000 = t2;
        *(volatile f32 *)0xCC008000 = t3;
        *(volatile f32 *)0xCC008000 = zpos;
        *(volatile u8 *)0xCC008000 = c1[0];
        *(volatile u8 *)0xCC008000 = c1[1];
        *(volatile u8 *)0xCC008000 = c1[2];
        *(volatile u8 *)0xCC008000 = c1[3];
        *(volatile f32 *)0xCC008000 = t0 + fw;
        *(volatile f32 *)0xCC008000 = t1 + fh;
        *(volatile f32 *)0xCC008000 = fxa;
        *(volatile f32 *)0xCC008000 = t3;
        *(volatile f32 *)0xCC008000 = zpos;
        *(volatile u8 *)0xCC008000 = c1[0];
        *(volatile u8 *)0xCC008000 = c1[1];
        *(volatile u8 *)0xCC008000 = c1[2];
        *(volatile u8 *)0xCC008000 = c1[3];
        *(volatile f32 *)0xCC008000 = t0;
        *(volatile f32 *)0xCC008000 = t1 + fh;
        xpos += fadv * scale2;
        (void)unk; (void)mtxbase; (void)unkptr;
        (void)cr2; (void)cg2; (void)cb2; (void)ca2;
        (void)lbl_80368BE4; (void)lbl_80368BE8;
        (void)w; (void)h; (void)save_r; (void)save_g; (void)save_b; (void)save_a;
        (void)fpad2; (void)fpad3; (void)fpad4; (void)fpad5; (void)fpad6; (void)fpad7;
        (void)ctr;
    }
    return 0;
}
#pragma global_optimizer reset
void fn_8001003C(s32 x, s32 y, s32 color, s32 mode, s32 flags, f32 scale, f32 angle, const char *fmt, ...) {
#pragma push
#pragma use_lmw_stmw on
 void Prim2D_SetPos(f32, f32);
 u32 *Ui_GetColor(s32);
 void Prim2D_SetScale(f32);
 void fn_80007268(f32);
 void Prim2D_SetTextScale(s32,f32);
 void fn_800071D8(s32,f32);
 extern f32 lbl_80368C30, lbl_80368BDC;
 char text[256];
 struct { unsigned char gpr, fpr; unsigned char reserved[2]; void *input_arg_area; void *reg_save_area; } args[1];
 u32 packed;
 __builtin_va_info(args);
 vsprintf(text, fmt, args);
 Prim2D_AddPrim(6);
 Prim2D_SetPos((f32)(s16)x, (f32)(s16)y);
 packed = *Ui_GetColor(color);
 Prim2D_SetColorPacked(&packed);
 Prim2D_SetScale(scale);
 fn_80007268(angle);
 Prim2D_SetTextScale(mode,lbl_80368C30);
 fn_800071D8(flags,lbl_80368BDC);
 Prim2D_SetText(text);
 Prim2D_EndPrim();
#pragma pop
}

void Text_Draw(s32 x, s32 y, s32 color, const char *fmt, ...) {
 void Prim2D_SetPos(f32, f32);
 u32 *Ui_GetColor(s32);
 char text[256];
 struct { unsigned char gpr, fpr; unsigned char reserved[2]; void *input_arg_area; void *reg_save_area; } args[1];
 u32 packed;
 __builtin_va_info(args);
 vsprintf(text, fmt, args);
 Prim2D_AddPrim(6);
 Prim2D_SetPos((f32)(s16)x, (f32)(s16)y);
 packed = *Ui_GetColor(color);
 Prim2D_SetColorPacked(&packed);
 Prim2D_SetText(text);
 Prim2D_EndPrim();
}

s32 Text_MeasureHeight(s32 arg0, f32 arg1)
{
    extern s32 lbl_802AEE20[5];
    extern f64 lbl_80368C28;

    void *fn_8010494C(void *);
    s32 fn_80104E40(void);

    s32 *table;
    void *result;
    s32 index;
    s32 value;
    s32 i;

    table = lbl_802AEE20;
    index = arg0;

    if (index == -1) {
        result = fn_8010494C((void *)table[0]);

        if (table[0] == (s32)result) {
            index = 0;
        } else if (table[1] == (s32)result) {
            index = 1;
        } else if (table[2] == (s32)result) {
            index = 2;
        } else if (table[3] == (s32)result) {
            index = 3;
        } else if (table[4] == (s32)result) {
            index = 4;
        } else {
            index = -1;
        }
    }

    value = (s32)(arg1 * (f32)fn_80104E40());

    if (index == -1) {
        index = 0;
        result = fn_8010494C((void *)table[index]);

        for (i = 0; i < 5; i++) {
            if (table[i] == (s32)result) {
                break;
            }
        }
    }

    return value;
}

s32 fn_80010428(s32 arg0,s32 arg1,f32 arg2) {
    s32 fn_8010494C(s32);
    s32 fn_80104FC4(s32);
    s32 index, value;
    u32 *table;
    u32 result;
    if(arg1==-1) arg1=0;
    result=(u32)fn_8010494C(lbl_802AEE20[arg1]);
    table=(u32 *)lbl_802AEE20;
    index=Text_FindFontIndex(table,result);
    value=(s32)(arg2*(f32)fn_80104FC4(arg0));
    if(index==-1) index=0;
    result=(u32)fn_8010494C(lbl_802AEE20[index]);
    Text_FindFontIndex(table,result);
    return value;
}

#pragma global_optimizer off
s32 fn_8001059C(s32 arg0,s32 arg1,f32 arg2) {
    s32 fn_8010494C(s32);
    s32 fn_80104E68(s32);
    s32 index, value;
    u32 *table;
    u32 result;
    if(arg1==-1) arg1=0;
    result=(u32)fn_8010494C(lbl_802AEE20[arg1]);
    table=(u32 *)lbl_802AEE20;
    index=Text_FindFontIndex(table,result);
    value=(s32)(arg2*(f32)fn_80104E68(arg0));
    if(index==-1) index=0;
    result=(u32)fn_8010494C(lbl_802AEE20[index]);
    Text_FindFontIndex(table,result);
    return value;
}
#pragma global_optimizer reset
s32 fn_80010710(const char *arg0)
{
  s32 value;
  if (arg0[0] != '#')
  {
    return 0;
  }
  value = (s8) arg0[1];
  switch (value)
  {
    case 'A':

    case 'B':

    case 'C':

    case 'F':

    case 'G':

    case 'I':

    case 'R':

    case 'S':

    case 'X':

    case 'Y':
      return 4;

    case 'P':
      return 5;

    case '#':

    case 'D':

    case 'c':

    case 'e':

    case 'i':

    case 'o':

    case 's':

    case 'x':

    case 'y':
      return 2;

    default:
      return -1;

  }

}

extern f32 lbl_80368BDC;
extern f32 lbl_80368BE0;
extern f64 lbl_80368C20;
s32 fn_80010770(u8 *str, s32 idx, f32 scale) {
    register u8 *digits;
    u32 *tbl;
    u32 found;
    s32 i;
    s32 result;
    f32 fmax;
    u8 *p;
    s32 c;
    s32 code;
    s16 digi;
    s16 shift;
    s32 val;
    f32 ftmp;
    s32 rnd;

    p = str;
    if (idx == -1) {
        idx = 0;
    }
    found = (u32)fn_8010494C((void *)lbl_802AEE20[idx]);
    tbl = (u32 *)lbl_802AEE20;
    if (tbl[0] == found) {
        i = 0;
    } else if (tbl[1] == found) {
        i = 1;
    } else if (tbl[2] == found) {
        i = 2;
    } else if (tbl[3] == found) {
        i = 3;
    } else if (tbl[4] == found) {
        i = 4;
    } else {
        i = -1;
    }

    fmax = lbl_80368BDC;
    result = 0;

    while ((s8)*p != 0) {
        if (*p++ == '#') {
            c = (s8)*p++;
            code = c - '#';
            if ((u32)code <= 0x56U) {
                switch (code) {
                case 30:
                case 31:
                case 32:
                case 36:
                case 38:
                case 47:
                case 53:
                case 85:
                    p += 2;
                    break;
                case 45:
                    p += 3;
                    break;
                case 35:
                    digits = (u8 *)__alloca(8);
                    digi = 0;
                    while ((u8)digi < 2) {
                        c = (s8)*p++;
                        if (c >= '0' && c <= '9') {
                            digits[(u8)digi] = (u8)(c - '0');
                        } else if (c >= 'a' && c <= 'f') {
                            digits[(u8)digi] = (u8)(c - 0x57);
                        } else if (c >= 'A' && c <= 'F') {
                            digits[(u8)digi] = (u8)(c - 0x37);
                        }
                        digi += 1;
                    }
                    val = 0;
                    digi = 1;
                    shift = 0;
                    while (digi >= 0) {
                        val += digits[digi] << shift;
                        digi -= 1;
                        shift += 4;
                    }
                    if (val == -1) {
                        val = 0;
                    }
                    found = (u32)fn_8010494C((void *)lbl_802AEE20[val]);
                    if (tbl[0] == found) {
                    } else if (tbl[1] == found) {
                    } else if (tbl[2] == found) {
                    } else if (tbl[3] == found) {
                    } else if (tbl[4] == found) {
                    }
                    break;
                case 48:
                case 54:
                    digits = (u8 *)__alloca(8);
                    digi = 0;
                    while ((u8)digi < 2) {
                        c = (s8)*p++;
                        if (c >= '0' && c <= '9') {
                            digits[(u8)digi] = (u8)(c - '0');
                        } else if (c >= 'a' && c <= 'f') {
                            digits[(u8)digi] = (u8)(c - 0x57);
                        } else if (c >= 'A' && c <= 'F') {
                            digits[(u8)digi] = (u8)(c - 0x37);
                        }
                        digi += 1;
                    }
                    val = 0;
                    digi = 1;
                    shift = 0;
                    while (digi >= 0) {
                        val += digits[digi] << shift;
                        digi -= 1;
                        shift += 4;
                    }
                    ftmp = (f32)(u32)val * lbl_80368BE0;
                    if (ftmp > fmax) {
                        fmax = ftmp;
                    }
                    break;
                default:
                    break;
                }
            }
        } else {
            rnd = fn_80104E40();
            ftmp = fmax * (f32)rnd * scale;
            rnd = (s32)ftmp;
            if (result < rnd) {
                result = rnd;
            }
        }
    }

    if (i == -1) {
        i = 0;
    }
    found = (u32)fn_8010494C((void *)lbl_802AEE20[i]);
    if (tbl[0] == found) {
    } else if (tbl[1] == found) {
    } else if (tbl[2] == found) {
    } else if (tbl[3] == found) {
    } else if (tbl[4] == found) {
    }
    return result;
}

#pragma push
#pragma cplusplus on
extern "C" s32 Text_MeasureWidth(u8 *str, s32 idx, f32 scale)
{
  extern f32 lbl_80368BE8;
  extern f32 lbl_80368BDC;
  extern f32 lbl_80368BE0;
  extern void *lbl_80367168;
  extern u8 *fn_80105124(u8 *, s32 *);
  u32 *tbl;
  u32 found;
  s32 index;
  f32 result;
  f32 fmax;
  u8 *p;
  s32 c;
  s32 code;
  s16 digi;
  s16 shift;
  s32 val;
  u8 *digits;
  s32 width;
  f32 advance;
  u8 flag;
  void *obj;
  u32 raw;
  p = str;
  if (idx == (-1))
  {
    idx = 0;
  }
  found = (u32) fn_8010494C(lbl_802AEE20[idx]);
  tbl = (u32 *) lbl_802AEE20;
  {
    u32 *q = tbl;
    s32 j;
    for (j = 0; j < 5; j++, q++)
    {
      if ((*q) == found)
      {
        index = j;
        goto font_found;
      }
    }

    index = -1;
    font_found:
    ;

    ;
    ;
  }
  result = lbl_80368BE8;
  fmax = lbl_80368BDC;
  while (((s8) (raw = *p)) != 0)
  {
    flag = 0;
    if (((s8) raw) == '#')
    {
      c = (s8) p[1];
      p += 2;
      code = c - 0x23;
      if ((((u32) code) + 1) <= (0x56U + 1))
      {
        switch (code)
        {
          case 30:

          case 31:

          case 32:

          case 36:

          case 38:

          case 47:

          case 53:

          case 85:
            p += 2;
            goto next;

          case 48:

          case 54:
          {
            s16 shift;
            s16 digi;
            u8 n;
            s32 val;
            u8 *digits;
            digits = (u8 *) __alloca(8);
            n = 0;
            while (n < 2)
            {
              c = (s8) (*(p++));
              if ((c >= '0') && (c <= '9'))
              {
                digits[n] = (u8) (c - '0');
              }
              else
                if ((c >= 'a') && (c <= 'f'))
              {
                digits[n] = (u8) (c - 0x57);
              }
              else
                if ((c >= 'A') && (c <= 'F'))
              {
                digits[n] = (u8) (c - 0x37);
              }
              n += 1;
            }

            val = 0;
            digi = 1;
            shift = 0;
            while (digi >= 0)
            {
              val += digits[digi] << shift;
              digi -= 1;
              shift += 4;
            }

            fmax = ((f32) ((u32) val)) * lbl_80368BE0;
            goto next;
          }

          case 86:
            fmax = lbl_80368BDC;
            goto next;

          case 45:
            flag = 1;
            index = -1;
            p += 3;
            break;

          case 35:
          {
            s16 shift;
            s16 digi;
            u8 n;
            s32 val;
            u8 *digits;
            digits = (u8 *) __alloca(8);
            n = 0;
            while (n < 2)
            {
              c = (s8) (*(p++));
              if ((c >= '0') && (c <= '9'))
              {
                digits[n] = (u8) (c - '0');
              }
              else
                if ((c >= 'a') && (c <= 'f'))
              {
                digits[n] = (u8) (c - 0x57);
              }
              else
                if ((c >= 'A') && (c <= 'F'))
              {
                digits[n] = (u8) (c - 0x37);
              }
              n += 1;
            }

            val = 0;
            digi = 1;
            shift = 0;
            while (digi >= 0)
            {
              val += digits[digi] << shift;
              digi -= 1;
              shift += 4;
            }

            if (val == (-1))
            {
              val = 0;
            }
            found = (u32) fn_8010494C(lbl_802AEE20[val]);
            Text_FindFontIndex(tbl, found);
            goto next;
          }

          default:
            p -= 1;
            break;

        }

      }
    }
    if (((u8) flag) == 0)
    {
      p = fn_80105124(p, &width);
      advance = scale * (((f32) width) * fmax);
    }
    else
    {
      obj = lbl_80367168;
      advance = (f32) ((TextWidthFontInterface *) obj)->v13();
    }
    result += advance;
    next:
    ;

    ;
    ;
  }

  if (index == (-1))
  {
    index = 0;
  }
  found = (u32) fn_8010494C(lbl_802AEE20[index]);
  Text_FindFontIndex(tbl, found);
  return (s32) result;
}
#pragma pop
void fn_80010FF0(void) {
    M2C_UNK fn_801047D0();
    fn_801047D0();
}

#pragma global_optimizer off
s32 fn_80011010(s32 arg0) {
    u32 result;
    u32 *p;
    s32 fn_8010494C(s32);
    s32 i;

    if (arg0 == -1) {
        i = 0;
        result = (u32)fn_8010494C(lbl_802AEE20[i]);
        p = (u32 *)lbl_802AEE20;
        if (*p == result) {
            return 0;
        }
        p = p + 1;
        if (*p == result) {
            return 1;
        }
        p = p + 1;
        if (*p == result) {
            return 2;
        }
        p = p + 1;
        if (*p == result) {
            return 3;
        }
        if (p[1] == result) {
            return 4;
        }
    }
    return -1;
}
#pragma global_optimizer on
void fn_800110B8(void) {
 extern char lbl_80267DC8[];
 extern u32 lbl_80367160[2];
 extern void *lbl_80367168;
 s32 Heap_Alloc(u32);
 s32 fn_801053CC(s32);
 void fn_80105284(s32, const char *, s32);
 struct Object { struct VTable { s32 (*method[9])(); } *vtable; u32 value; } *self;
 s32 object;
 object = Heap_Alloc(0x10);
 if (object) object = fn_801053CC(object);
 lbl_802AEE20[1] = object;
 fn_80105284(object,lbl_80267DC8,0);
 object = Heap_Alloc(0x10);
 if (object) object = fn_801053CC(object);
 lbl_802AEE20[2] = object;
 fn_80105284(object,lbl_80267DC8+0x12,0);
 object = Heap_Alloc(0x10);
 if (object) object = fn_801053CC(object);
 lbl_802AEE20[3] = object;
 fn_80105284(object,lbl_80267DC8+0x21,0);
 object = Heap_Alloc(0x10);
 if (object) object = fn_801053CC(object);
 lbl_802AEE20[4] = object;
 fn_80105284(object,lbl_80267DC8+0x33,0);
 self = (struct Object *)lbl_80367160;
 lbl_80367168 = self;
 if (!self->value) fn_8006EEFC(&self->value,self->vtable->method[8](self));
}

void fn_800111FC(void) {
    extern s32 lbl_802AEE20[5];
    extern s32 lbl_8036716C;
    extern s8 lbl_80367170;
    s32 ret;

    if (lbl_80367170 == 0) {
        lbl_8036716C = 0;
        lbl_80367170 = 1;
    }
    if (lbl_8036716C == 0) {
        fn_80104D90(0);
        fn_8010494C(0);
        ret = fn_80104944();
        lbl_8036716C = 1;
        lbl_802AEE20[0] = ret;
    }
}

#pragma cplusplus on
extern "C" s32 fn_80011264(void **arg0) {
    struct Obj {
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
    };
    return ((Obj *)arg0)->v10() / ((Obj *)arg0)->v14();
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" s32 fn_800112C0(void **arg0) {
    struct Obj {
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
    };
    return ((Obj *)arg0)->v9() / ((Obj *)arg0)->v13();
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" u16 fn_8001131C(void *arg0) {
    struct Obj {
        virtual s32 v0() = 0;
        virtual s32 v1() = 0;
        virtual s32 v2() = 0;
        virtual s32 v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        virtual s32 v6() = 0;
        virtual s32 v7() = 0;
        s32 unk04;
    };
    u16 **fn_8006EDD8(s32, s32);
    Obj *obj = (Obj *)arg0;
    return **fn_8006EDD8(obj->unk04, obj->v7());
}
extern "C" u16 fn_80011368(void *arg0) {
    struct Obj {
        virtual s32 v0() = 0;
        virtual s32 v1() = 0;
        virtual s32 v2() = 0;
        virtual s32 v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        virtual s32 v6() = 0;
        virtual s32 v7() = 0;
        s32 unk04;
    };
    void **fn_8006EDD8(s32, s32);
    Obj *obj = (Obj *)arg0;
    return *(u16 *)((u8 *)*fn_8006EDD8(obj->unk04, obj->v7()) + 2);
}
#pragma cplusplus reset
s32 fn_800113B4(void) {
    return 0;
}

s32 fn_800113BC(void) {
    return 0;
}

#pragma cplusplus on
extern "C" void fn_800113C4(void *obj, s32 arg1, u8 *color, f32 x, f32 y, f32 z) {
    f64 fmod(f64, f64);
    void GXBegin(s32, s32, s32);
    extern f64 lbl_80368C38;
    extern f64 lbl_80368C40;
    extern f32 lbl_80368BF0;
    extern f64 lbl_80368C28;
    struct Obj {
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
    };
    f32 f30;
    f32 f29;
    f32 f28;
    f32 f27;
    f32 f26;
    f32 f25;
    s32 t;
    s32 idx;
    s32 w;
    s32 rem;
    u8 r, g, b, a;
    f32 f0, f1, f2, f3;
    u8 *wg;

    idx = arg1;
    if (idx < 0) {
        return;
    }
    {
        f32 f = (f32)fmod(lbl_80368C38, lbl_80368C40);
        f30 = (f32)(s32)(f * (x + (lbl_80368BF0 / f))) / f;
    }
    {
        f32 f = (f32)fmod(lbl_80368C38, lbl_80368C40);
        f29 = (f32)(s32)(f * (y + (lbl_80368BF0 / f))) / f;
    }
    t = ((Obj *)obj)->v13();
    w = ((Obj *)obj)->v11();
    rem = idx % w;
    f28 = (f32)(rem * t);
    t = ((Obj *)obj)->v14();
    w = ((Obj *)obj)->v11();
    rem = idx / w;
    f27 = (f32)(rem * t);
    f26 = (f32)((Obj *)obj)->v13();
    f25 = (f32)((Obj *)obj)->v14();
    GXBegin(0x80, 0, 4);
    wg = (u8 *)0xCC010000;
    r = color[wg - (u8 *)0xCC010000];
    *(volatile f32 *)(wg - 0x8000) = f30;
    f0 = f30 + f26;
    g = color[1];
    f1 = f28 + f26;
    *(volatile f32 *)(wg - 0x8000) = f29;
    f2 = f29 + f25;
    b = color[2];
    *(volatile f32 *)(wg - 0x8000) = z;
    f3 = f27 + f25;
    a = color[3];
    *(wg - 0x8000) = r;
    *(wg - 0x8000) = g;
    *(wg - 0x8000) = b;
    *(wg - 0x8000) = a;
    *(volatile f32 *)(wg - 0x8000) = f28;
    *(volatile f32 *)(wg - 0x8000) = f27;
    *(volatile f32 *)(wg - 0x8000) = f0;
    *(volatile f32 *)(wg - 0x8000) = f29;
    *(volatile f32 *)(wg - 0x8000) = z;
    *(wg - 0x8000) = r;
    *(wg - 0x8000) = g;
    *(wg - 0x8000) = b;
    *(wg - 0x8000) = a;
    *(volatile f32 *)(wg - 0x8000) = f1;
    *(volatile f32 *)(wg - 0x8000) = f27;
    *(volatile f32 *)(wg - 0x8000) = f0;
    *(volatile f32 *)(wg - 0x8000) = f2;
    *(volatile f32 *)(wg - 0x8000) = z;
    *(wg - 0x8000) = r;
    *(wg - 0x8000) = g;
    *(wg - 0x8000) = b;
    *(wg - 0x8000) = a;
    *(volatile f32 *)(wg - 0x8000) = f1;
    *(volatile f32 *)(wg - 0x8000) = f3;
    *(volatile f32 *)(wg - 0x8000) = f30;
    *(volatile f32 *)(wg - 0x8000) = f2;
    *(volatile f32 *)(wg - 0x8000) = z;
    *(wg - 0x8000) = r;
    *(wg - 0x8000) = g;
    *(wg - 0x8000) = b;
    *(wg - 0x8000) = a;
    *(volatile f32 *)(wg - 0x8000) = f28;
    *(volatile f32 *)(wg - 0x8000) = f3;
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_800116F0(void *arg0) {
#pragma scheduling off
    void PSMTXScale(void *, f32, f32, f32);
    void fn_80224E50(void *, s32, s32);
    extern f32 lbl_80368BDC;
    extern f64 lbl_80368C28;
    struct Obj {
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
    };
    u8 sp8[0x30];
    f32 inv_h;
    s32 t;
    Obj *obj = (Obj *)arg0;

    t = obj->v10();
    inv_h = lbl_80368BDC / (f32)t;
    t = obj->v9();
    PSMTXScale(sp8, lbl_80368BDC / (f32)t, inv_h, lbl_80368BDC);
    fn_80224E50(sp8, 0x21, 1);
#pragma scheduling reset
}
#pragma cplusplus reset
void fn_800117B0(void *arg0) {
    void fn_8006EBC4(s32, void *, void *, s32, s32);
    void fn_80222A3C(void *, s32, s32);
    void fn_80222C50(void *, s32);
    void fn_80222CF0(void *, s32);
    u8 sp8[0xC];
    u8 sp14[0x20];
    void *obj;
    s32 temp;

    obj = arg0;
    temp = (*(s32 (**)(void *))((u8 *)*(void **)obj + 0x24))(obj);
    fn_8006EBC4(*(s32 *)((u8 *)obj + 4), sp14, sp8,
        (*(s32 (**)(void *))((u8 *)*(void **)obj + 0x28))(obj), temp);
    fn_80222A3C(sp14, 0, 0);
    fn_80222C50(sp14, 1);
    fn_80222CF0(sp8, (*(s32 (**)(void *))((u8 *)*(void **)obj + 0x28))(obj));
}
#pragma cplusplus reset
void fn_8001185C(void) {
    M2C_UNK GXSetTevColorIn(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevAlphaIn(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevColorOp(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevAlphaOp(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    fn_802201A8(0, 1, 4, 0x1E, 0, 0x7D);
    GXSetTevColorIn(0, 0xF, 0xF, 0xF, 0xA);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 4, 5, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevOrder(0, 0, 0, 4);
}

void fn_80011910(void) {
    M2C_UNK fn_802201A8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetNumTexGens(M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevOrder(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    fn_802201A8(0, 1, 4, 0x21, 0, 0x7D);
    GXSetNumTexGens(0, 0);
    GXSetTevOrder(0, 0, 1, 4);
}

