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

#pragma opt_common_subs off
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
    s8 c;
    u8 b;
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
            while ((c = *(s8 *)p) != 0) {
                if (c == 0x40) {
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
                    b = *p;
                    if ((((b >= 0x81U) && (b <= 0x9FU)) || ((b >= 0xE0U) && (b <= 0xFCU))) &&
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
            while ((c = *(s8 *)src) != 0) {
                if (c == 0x40) {
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
                    b = *src;
                    if ((((b >= 0x81U) && (b <= 0x9FU)) || ((b >= 0xE0U) && (b <= 0xFCU))) &&
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
            *dst++ = 0;
            lbl_80366DA8 = dst;
            resolved = out;
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
            while ((c = *(s8 *)p) != 0) {
                if (c == 0x40) {
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
                    b = *p;
                    if ((((b >= 0x81U) && (b <= 0x9FU)) || ((b >= 0xE0U) && (b <= 0xFCU))) &&
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
            while ((c = *(s8 *)src) != 0) {
                if (c == 0x40) {
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
                    b = *src;
                    if ((((b >= 0x81U) && (b <= 0x9FU)) || ((b >= 0xE0U) && (b <= 0xFCU))) &&
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
            *dst++ = 0;
            lbl_80366DA8 = dst;
            resolved = out;
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
        while ((c = *(s8 *)p) != 0) {
            if (c == 0x40) {
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
                b = *p;
                if ((((b >= 0x81U) && (b <= 0x9FU)) || ((b >= 0xE0U) && (b <= 0xFCU))) &&
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
        while ((c = *(s8 *)src) != 0) {
            if (c == 0x40) {
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
                b = *src;
                if ((((b >= 0x81U) && (b <= 0x9FU)) || ((b >= 0xE0U) && (b <= 0xFCU))) &&
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
        *dst++ = 0;
        lbl_80366DA8 = dst;
        resolved = out;
    }
    return resolved;
}
#pragma optimization_level reset
u8 *Msg_Expand(u8 *arg0) {
    u8 *Res_GetByName(u8 *);
    void strcpy(u8 *, void *);
    extern u8 lbl_802AEB10[];
    extern u8 lbl_802AED10[];
    extern u8 *lbl_80366DA8;

    u8 *dst;
    u8 *out;
    u8 *src;
    u8 *entry;
    u32 need;
    u8 *p;
    u8 *resolved;
    u8 c;
    u8 c1;
    u8 sjis;

    resolved = Res_GetByName(arg0);
    if (resolved == 0) {
        return arg0;
    }
    if ((s32) *resolved == 0x40) {
        src = resolved + 1;
        need = 0;
        p = src;
        while ((c = *p), (s8) c != 0) {
            if ((s8) c == 0x40) {
                c1 = p[1];
                p += 1;
                switch ((s8) c1) {
                case 0x40:
                    p += 1;
                    need += 1;
                    break;
                case 0x7B:
                    c1 = p[1];
                    p += 3;
                    need += *(s32 *) (lbl_802AED10 + (((s8) c1 - 0x30) * 0x44));
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
        if ((u32) (0x200 - (lbl_80366DA8 - lbl_802AEB10)) <= need) {
            lbl_80366DA8 = lbl_802AEB10;
        }
        dst = lbl_80366DA8;
        out = dst;
        while ((c = *src), (s8) c != 0) {
            if ((s8) c == 0x40) {
                c1 = src[1];
                src += 1;
                switch ((s8) c1) {
                case 0x40:
                    src += 1;
                    *dst = 0x40;
                    dst += 1;
                    break;
                case 0x7B:
                    c1 = src[1];
                    src += 3;
                    entry = lbl_802AED10 + (((s8) c1 - 0x30) * 0x44);
                    strcpy(dst, entry + 4);
                    dst += *(s32 *) entry;
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
#pragma global_optimizer on
int fn_8000E7FC(int a0, int a1, int a2, int a3, int a4, int a5, float f0, float f1, float f2, float f3, float f4);
#pragma push
#pragma use_lmw_stmw on
void fn_8000E394(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    s32 index;
    u32 *table;
    u32 result;

    index = 3;
    if (index == -1) {
        index = 0;
    }
    result = (u32)fn_8010494C(lbl_802AEE20[index]);
    table = (u32 *)lbl_802AEE20;
    index = Text_FindFontIndex(table, result);

    fn_8000E7FC(arg0, arg1, arg2, arg3, arg4, arg5,
                farg0, farg1, farg2, farg3, farg4);

    if (index == -1) {
        index = 0;
    }
    result = (u32)fn_8010494C(lbl_802AEE20[index]);
    Text_FindFontIndex(table, result);
}
#pragma pop

#pragma push
#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8000E50C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    s32 fontId;
    s32 index;
    u32 *table;
    u32 result;

    fontId = 2;
    if (fontId == -1) {
        fontId = 0;
    }
    result = (u32)fn_8010494C(lbl_802AEE20[fontId]);
    table = (u32 *)lbl_802AEE20;
    index = Text_FindFontIndex(table, result);

    fn_8000E7FC(arg0, arg1, arg2, arg3, arg4, arg5,
                farg0, farg1, farg2, farg3, farg4);

    if (index == -1) {
        index = 0;
    }
    result = (u32)fn_8010494C(lbl_802AEE20[index]);
    Text_FindFontIndex(table, result);
}
#pragma push
#pragma use_lmw_stmw on
void fn_8000E684(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    s32 fontId;
    s32 index;
    u32 *table;
    u32 result;

    fontId = 0;
    if (fontId == -1) {
        fontId = 0;
    }
    result = (u32)fn_8010494C(lbl_802AEE20[fontId]);
    table = (u32 *)lbl_802AEE20;
    index = Text_FindFontIndex(table, result);

    fn_8000E7FC(arg0, arg1, arg2, arg3, arg4, arg5,
                farg0, farg1, farg2, farg3, farg4);

    if (index == -1) {
        index = 0;
    }
    result = (u32)fn_8010494C(lbl_802AEE20[index]);
    Text_FindFontIndex(table, result);
}
#pragma pop
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
    s16 dimensions[2];
    u8 flg_w, flg_h;
    u8 *str;
    u8 *c0;
    u8 *c1;
    s32 ch;
    s32 code;
    f32 xpos, ypos, zpos;
    f32 scale, scale2;
    f32 fpad0, fpad1, fpad2, fpad3, fpad4, fpad5, fpad6, fpad7;
    u8 color[4];
    u8 saved[3],saveAlpha;
    s16 digi, shift;
    s32 val;
    s32 sp18, sp14, sp10, spC, sp8;
    u32 sp1C[8];
    void *glyph;
    f32 gw, gh;
    s32 glyphHeight;
    f32 fx, fy, fxa, fw, fh, fadv;
    f32 t0, t1, t2, t3;
    u8 cr, cg, cb, ca;
    u8 cr2, cg2, cb2, ca2;
    s32 alpha;
    u8 opacity;
    s32 alpha_scaled;
    f32 f18;
    s32 ctr;
    s32 unk;
    void *mtxbase;
    void *unkptr;

    u8 *fn_80104BF4(u8 *,s32 *,s32 *,s32 *,s32 *);
    s32 fn_80222AC0(void *);
    void fn_80222A3C(void *,s32,s32);
    extern f32 lbl_80368BEC,lbl_80368BF0,lbl_80368BF8;
    u8 upper[4],lower[4],modulated[4];
    u32 lastTexture;
    u8 textureDirty;
    f32 vh,uw,bottom,right,top,left,shearBottom,shearTop,sy,sx;
    f32 shear,originX,originY;

    dimensions[0] = (s16)a0;
    dimensions[1] = (s16)a1;
    xpos = f0;
    ypos = f1;
    zpos = f2;
    fpad0 = f3;
    fpad1 = f4;
    alpha = a2;
    c0 = (u8 *)a3;
    c1 = (u8 *)a4;
    str = (u8 *)a5;
    font = fn_801047D0();
    scale = lbl_80368BDC;
    scale2 = scale;
    flg_w = ((u32)(-(s32)dimensions[0]) | (u32)(s32)dimensions[0]) >> 31;
    flg_h = ((u32)(-(s32)dimensions[1]) | (u32)(s32)dimensions[1]) >> 31;
    *(u32 *)color = lbl_80368BD8;
    lastTexture=0;
    unk = 0;
    if (flg_w == 0) {
        dimensions[0] = 0x200;
    }
    if (flg_h == 0) {
        dimensions[1] = 0x100;
    }
    obj = lbl_80367168;
    if (obj != 0) {
        (*(void (**)(void *))(*(u32 *)obj + 0x14))(obj);
        (*(void (**)(void *))(*(u32 *)obj + 0x18))(obj);
    }
    PSMTXScale(matrix, lbl_80368BDC / (f32)*(u16 *)(font + 0x1e),
        lbl_80368BDC / (f32)*(u16 *)(font + 0x20), lbl_80368BDC);
    fn_80224E50(matrix, 0x1e, 1);
    opacity=(u8)alpha;
    alpha_scaled = (opacity * 0xff) >> 7;
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
    while ((ch = *str) != 0) {
        ctr = -1;
        if ((s8)ch == '#') {
            ch = (s8)str[1];
            str += 2;
            code = ch - '#';
            if ((u32)code <= 0x56U) {
                switch (code) {
                case 32: { u8 *digits; s16 shift,digi; s32 val; u8 n;

                    saved[0] = color[0];
                    saved[1] = color[1];
                    saved[2] = color[2];
                    saveAlpha = color[3];
                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') {
                            digits[n] = (u8)(ch - '0');
                        } else if (ch >= 'a' && ch <= 'f') {
                            digits[n] = (u8)(ch - 0x57);
                        } else if (ch >= 'A' && ch <= 'F') {
                            digits[n] = (u8)(ch - 0x37);
                        }
                        n += 1;
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
                    continue;
}
case 47: { u8 *digits; s16 shift,digi; s32 val; u8 n;

                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[n] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[n] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[n] = (u8)(ch - 0x37);
                        n += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
color[0]=(u8)val;continue;
}
case 36: { u8 *digits; s16 shift,digi; s32 val; u8 n;

                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[n] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[n] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[n] = (u8)(ch - 0x37);
                        n += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
color[1]=(u8)val;continue;
}
case 31: { u8 *digits; s16 shift,digi; s32 val; u8 n;

                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[n] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[n] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[n] = (u8)(ch - 0x37);
                        n += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
color[2]=(u8)val;continue;
}
case 30: { u8 *digits; s16 shift,digi; s32 val; u8 n;

                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[n] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[n] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[n] = (u8)(ch - 0x37);
                        n += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
color[3]=(u8)val;continue;
}
case 64:color[0]=saved[0];color[1]=saved[1];color[2]=saved[2];color[3]=saveAlpha;continue;
case 48: { u8 *digits; s16 shift,digi; s32 val; u8 n;

                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[n] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[n] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[n] = (u8)(ch - 0x37);
                        n += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
scale=(f32)(u32)val*lbl_80368BE0;scale2=scale;continue;
}
case 80:scale=lbl_80368BDC;scale2=scale;continue;
case 53: { u8 *digits; s16 shift,digi; s32 val; u8 n;

                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[n] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[n] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[n] = (u8)(ch - 0x37);
                        n += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
scale2=(f32)(u32)val*lbl_80368BE0;continue;
}
case 85:scale2=lbl_80368BDC;continue;
case 54: { u8 *digits; s16 shift,digi; s32 val; u8 n;

                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[n] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[n] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[n] = (u8)(ch - 0x37);
                        n += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
scale=(f32)(u32)val*lbl_80368BE0;continue;
}
case 86:scale=lbl_80368BDC;continue;
case 38: { u8 *digits; s16 shift,digi; s32 val; u8 n;

                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[n] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[n] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[n] = (u8)(ch - 0x37);
                        n += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
fpad1=(f32)(u32)val*lbl_80368BE4;continue;
}
case 70:fpad1=lbl_80368BE8;continue;
case 45: { u8 *digits; s16 shift,digi; s32 val; u8 n;

                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 3) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[n] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[n] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[n] = (u8)(ch - 0x37);
                        n += 1;
                    }
                    val = 0; digi = 2; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
ctr=val;break;
}
case 35: { u8 *digits; s16 shift,digi; s32 val; u8 n;

                    digits = (u8 *)__alloca(8);
                    n = 0;
                    while (n < 2) {
                        ch = (s8)*str++;
                        if (ch >= '0' && ch <= '9') digits[n] = (u8)(ch - '0');
                        else if (ch >= 'a' && ch <= 'f') digits[n] = (u8)(ch - 0x57);
                        else if (ch >= 'A' && ch <= 'F') digits[n] = (u8)(ch - 0x37);
                        n += 1;
                    }
                    val = 0; digi = 1; shift = 0;
                    while (digi >= 0) { val += digits[digi] << shift; digi -= 1; shift += 4; }
if(val==-1)val=0;{
u32 found=(u32)fn_8010494C(lbl_802AEE20[val]);
u32 *q=(u32 *)lbl_802AEE20;
s32 j;
for(j=0;j<5;j++,q++) {if(*q==found)break;}
}
font=fn_801047D0();
PSMTXScale(matrix,lbl_80368BDC/(f32)*(u16 *)(font+0x1e),lbl_80368BDC/(f32)*(u16 *)(font+0x20),lbl_80368BDC);
fn_80224E50(matrix,0x1e,1);
continue;
}
case 0: str--; break;
default:break;
}
}
}
        modulated[0]=(u8)((color[0]*opacity)>>7);
        modulated[1]=(u8)((color[1]*opacity)>>7);
        modulated[2]=(u8)((color[2]*opacity)>>7);
        modulated[3]=color[3];
        ((u8 *)unkptr)[0]=(u8)(s32)((f32)(modulated[0]*c0[0])*lbl_80368BEC);
        ((u8 *)unkptr)[1]=(u8)(s32)((f32)(modulated[1]*c0[1])*lbl_80368BEC);
        ((u8 *)unkptr)[2]=(u8)(s32)((f32)(modulated[2]*c0[2])*lbl_80368BEC);
        ((u8 *)unkptr)[3]=(u8)(s32)((f32)(modulated[3]*c0[3])*lbl_80368BEC);
        *(u32 *)upper=*(u32 *)unkptr;
        ((u8 *)unkptr)[0]=(u8)(s32)((f32)(modulated[0]*c1[0])*lbl_80368BEC);
        ((u8 *)unkptr)[1]=(u8)(s32)((f32)(modulated[1]*c1[1])*lbl_80368BEC);
        ((u8 *)unkptr)[2]=(u8)(s32)((f32)(modulated[2]*c1[2])*lbl_80368BEC);
        ((u8 *)unkptr)[3]=(u8)(s32)((f32)(modulated[3]*c1[3])*lbl_80368BEC);
        *(u32 *)lower=*(u32 *)unkptr;
        sx=scale*f3;
        sy=scale2*f3;
        if(ctr>=0) {
            s32 fn_80104E40(void);
            extern f32 lbl_80368BF4;
            f32 iconY;
            (*(void (**)(void *))(*(u32 *)obj+0xc))(obj);
            {
                f32 glyphAdvance = (f32)fn_80104E40();
                f32 offset = lbl_80368BF4;
                f32 multiplier = lbl_80368BF0;
                f32 delta = (glyphAdvance * sy) - offset;
                iconY = ypos + multiplier * delta;
            }
            modulated[0]=modulated[1]=modulated[2]=(u8)alpha_scaled;
            modulated[3]=(u8)((upper[3]+lower[3]+1)>>1);
            (*(void (**)(void *,s32,void *,f32,f32,f32))(*(u32 *)obj+0x1c))(obj,ctr,modulated,xpos,iconY,zpos);
            (*(void (**)(void *))(*(u32 *)obj+0x10))(obj);
            fadv=(f32)(*(s32 (**)(void *))(*(u32 *)obj+0x3c))(obj);
        } else {
        glyph=fn_801047DC(str);
        textureDirty=0;
        gw=(f32)*((u8 *)glyph+8); glyphHeight=*((u8 *)glyph+9); gh=(f32)glyphHeight;
        shear=fpad1*sx;
        shearTop=shear*((f32)*(s8 *)((u8 *)glyph+11)/(f32)*(u16 *)(font+8));
        shearBottom=shear*((f32)(*(s8 *)((u8 *)glyph+11)-glyphHeight)/(f32)*(u16 *)(font+8));
        originX=(f32)*(s8 *)((u8 *)glyph+10);
        originY=(f32)*(s8 *)((u8 *)glyph+11);
        left=xpos+originX*sx;
        top=ypos+(f32)*(u16 *)(font+8)*sy-originY*sy;
        fw=(f32)gw*sx; fh=(f32)gh*sy;
        str=fn_80104BF4(str,&sp18,&sp14,&sp10,&spC);
        t0=(f32)sp14; t1=(f32)sp10;
        uw=t0+(f32)gw; vh=t1+(f32)gh;
        fadv=(f32)spC*sx;
        if(lastTexture!=(u32)sp18) {
            fn_80222644(sp1C,sp18,*(u16 *)(font+0x1e),*(u16 *)(font+0x20),*(u16 *)(font+0x18),0,0,0);
            lastTexture=(u32)sp18;
            textureDirty=1;
        }
        if(lbl_80368BDC==sx && lbl_80368BDC==sy) {
            if(fn_80222AC0(sp1C)!=0) {
                fn_80222A3C(sp1C,0,0);
                textureDirty=1;
            }
        } else if(fn_80222AC0(sp1C)!=1) {
            fn_80222A3C(sp1C,1,1);
            textureDirty=1;
        }
        if(textureDirty)fn_80222C50(sp1C,0);
        if(flg_w) {
            f32 shadowX=sx*((f32)dimensions[0]*lbl_80368BF8);
            f32 shadowY=sy*((f32)dimensions[0]*lbl_80368BF8);
            GXBegin(0x80,0,4);
        *(volatile f32 *)0xCC008000=shadowX+left+shearTop;
        *(volatile f32 *)0xCC008000=top+shadowY;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=(u8)(s32)(lbl_80368BF0*(f32)upper[3]);
        *(volatile f32 *)0xCC008000=t0;
        *(volatile f32 *)0xCC008000=t1;
        *(volatile f32 *)0xCC008000=shadowX+left+shearTop+fw;
        *(volatile f32 *)0xCC008000=top+shadowY;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=(u8)(s32)(lbl_80368BF0*(f32)upper[3]);
        *(volatile f32 *)0xCC008000=uw;
        *(volatile f32 *)0xCC008000=t1;
        *(volatile f32 *)0xCC008000=shadowX+left+shearBottom+fw;
        *(volatile f32 *)0xCC008000=top+shadowY+fh;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=(u8)(s32)(lbl_80368BF0*(f32)lower[3]);
        *(volatile f32 *)0xCC008000=uw;
        *(volatile f32 *)0xCC008000=vh;
        *(volatile f32 *)0xCC008000=shadowX+left+shearBottom;
        *(volatile f32 *)0xCC008000=top+shadowY+fh;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=(u8)(s32)(lbl_80368BF0*(f32)lower[3]);
        *(volatile f32 *)0xCC008000=t0;
        *(volatile f32 *)0xCC008000=vh;
        GXBegin(0x80,0,4);
        *(volatile f32 *)0xCC008000=left+shearTop;
        *(volatile f32 *)0xCC008000=top;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=upper[0];
        *(volatile u8 *)0xCC008000=upper[1];
        *(volatile u8 *)0xCC008000=upper[2];
        *(volatile u8 *)0xCC008000=upper[3];
        *(volatile f32 *)0xCC008000=t0;
        *(volatile f32 *)0xCC008000=t1;
        *(volatile f32 *)0xCC008000=left+shearTop+fw;
        *(volatile f32 *)0xCC008000=top;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=upper[0];
        *(volatile u8 *)0xCC008000=upper[1];
        *(volatile u8 *)0xCC008000=upper[2];
        *(volatile u8 *)0xCC008000=upper[3];
        *(volatile f32 *)0xCC008000=uw;
        *(volatile f32 *)0xCC008000=t1;
        *(volatile f32 *)0xCC008000=left+shearBottom+fw;
        *(volatile f32 *)0xCC008000=top+fh;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=lower[0];
        *(volatile u8 *)0xCC008000=lower[1];
        *(volatile u8 *)0xCC008000=lower[2];
        *(volatile u8 *)0xCC008000=lower[3];
        *(volatile f32 *)0xCC008000=uw;
        *(volatile f32 *)0xCC008000=vh;
        *(volatile f32 *)0xCC008000=left+shearBottom;
        *(volatile f32 *)0xCC008000=top+fh;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=lower[0];
        *(volatile u8 *)0xCC008000=lower[1];
        *(volatile u8 *)0xCC008000=lower[2];
        *(volatile u8 *)0xCC008000=lower[3];
        *(volatile f32 *)0xCC008000=t0;
        *(volatile f32 *)0xCC008000=vh;
        } else if(flg_h) {
          s32 n;
          f32 *offsets;
          f32 radius,ox,oy;
          extern s8 lbl_80367178;
          extern f64 lbl_80368C00,lbl_80368C08,lbl_80368C10,lbl_80368C18;
          f64 fn_802380D0(f64);
          f64 sin(f64);
          if(!lbl_80367178) {
((f32 *)((u8 *)mtxbase+0x30))[0]=(f32)fn_802380D0(lbl_80368C00);
((f32 *)((u8 *)mtxbase+0x30))[1]=(f32)sin(lbl_80368C00);
((f32 *)((u8 *)mtxbase+0x30))[3]=(f32)fn_802380D0(lbl_80368C08);
((f32 *)((u8 *)mtxbase+0x30))[4]=(f32)sin(lbl_80368C08);
((f32 *)((u8 *)mtxbase+0x30))[6]=(f32)fn_802380D0(lbl_80368C10);
((f32 *)((u8 *)mtxbase+0x30))[7]=(f32)sin(lbl_80368C10);
((f32 *)((u8 *)mtxbase+0x30))[9]=(f32)fn_802380D0(lbl_80368C18);
((f32 *)((u8 *)mtxbase+0x30))[10]=(f32)sin(lbl_80368C18);
lbl_80367178=1;
}
radius=(f32)dimensions[1]*lbl_80368BF8;
GXBegin(0x80,0,0x20);
for(n=0,offsets=(f32 *)mtxbase;n<8;n++,offsets+=3) {
ox=radius*offsets[0];oy=radius*offsets[1];
        *(volatile f32 *)0xCC008000=left+shearTop+ox;
        *(volatile f32 *)0xCC008000=top+oy;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=upper[3];
        *(volatile f32 *)0xCC008000=t0;
        *(volatile f32 *)0xCC008000=t1;
        *(volatile f32 *)0xCC008000=left+shearTop+fw+ox;
        *(volatile f32 *)0xCC008000=top+oy;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=upper[3];
        *(volatile f32 *)0xCC008000=uw;
        *(volatile f32 *)0xCC008000=t1;
        *(volatile f32 *)0xCC008000=left+shearBottom+fw+ox;
        *(volatile f32 *)0xCC008000=top+fh+oy;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=lower[3];
        *(volatile f32 *)0xCC008000=uw;
        *(volatile f32 *)0xCC008000=vh;
        *(volatile f32 *)0xCC008000=left+shearBottom+ox;
        *(volatile f32 *)0xCC008000=top+fh+oy;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=0;
        *(volatile u8 *)0xCC008000=lower[3];
        *(volatile f32 *)0xCC008000=t0;
        *(volatile f32 *)0xCC008000=vh;
}
        GXBegin(0x80,0,4);
        *(volatile f32 *)0xCC008000=left+shearTop;
        *(volatile f32 *)0xCC008000=top;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=upper[0];
        *(volatile u8 *)0xCC008000=upper[1];
        *(volatile u8 *)0xCC008000=upper[2];
        *(volatile u8 *)0xCC008000=upper[3];
        *(volatile f32 *)0xCC008000=t0;
        *(volatile f32 *)0xCC008000=t1;
        *(volatile f32 *)0xCC008000=left+shearTop+fw;
        *(volatile f32 *)0xCC008000=top;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=upper[0];
        *(volatile u8 *)0xCC008000=upper[1];
        *(volatile u8 *)0xCC008000=upper[2];
        *(volatile u8 *)0xCC008000=upper[3];
        *(volatile f32 *)0xCC008000=uw;
        *(volatile f32 *)0xCC008000=t1;
        *(volatile f32 *)0xCC008000=left+shearBottom+fw;
        *(volatile f32 *)0xCC008000=top+fh;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=lower[0];
        *(volatile u8 *)0xCC008000=lower[1];
        *(volatile u8 *)0xCC008000=lower[2];
        *(volatile u8 *)0xCC008000=lower[3];
        *(volatile f32 *)0xCC008000=uw;
        *(volatile f32 *)0xCC008000=vh;
        *(volatile f32 *)0xCC008000=left+shearBottom;
        *(volatile f32 *)0xCC008000=top+fh;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=lower[0];
        *(volatile u8 *)0xCC008000=lower[1];
        *(volatile u8 *)0xCC008000=lower[2];
        *(volatile u8 *)0xCC008000=lower[3];
        *(volatile f32 *)0xCC008000=t0;
        *(volatile f32 *)0xCC008000=vh;
} else {
        GXBegin(0x80,0,4);
        *(volatile f32 *)0xCC008000=left+shearTop;
        *(volatile f32 *)0xCC008000=top;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=upper[0];
        *(volatile u8 *)0xCC008000=upper[1];
        *(volatile u8 *)0xCC008000=upper[2];
        *(volatile u8 *)0xCC008000=upper[3];
        *(volatile f32 *)0xCC008000=t0;
        *(volatile f32 *)0xCC008000=t1;
        *(volatile f32 *)0xCC008000=left+shearTop+fw;
        *(volatile f32 *)0xCC008000=top;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=upper[0];
        *(volatile u8 *)0xCC008000=upper[1];
        *(volatile u8 *)0xCC008000=upper[2];
        *(volatile u8 *)0xCC008000=upper[3];
        *(volatile f32 *)0xCC008000=uw;
        *(volatile f32 *)0xCC008000=t1;
        *(volatile f32 *)0xCC008000=left+shearBottom+fw;
        *(volatile f32 *)0xCC008000=top+fh;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=lower[0];
        *(volatile u8 *)0xCC008000=lower[1];
        *(volatile u8 *)0xCC008000=lower[2];
        *(volatile u8 *)0xCC008000=lower[3];
        *(volatile f32 *)0xCC008000=uw;
        *(volatile f32 *)0xCC008000=vh;
        *(volatile f32 *)0xCC008000=left+shearBottom;
        *(volatile f32 *)0xCC008000=top+fh;
        *(volatile f32 *)0xCC008000=zpos;
        *(volatile u8 *)0xCC008000=lower[0];
        *(volatile u8 *)0xCC008000=lower[1];
        *(volatile u8 *)0xCC008000=lower[2];
        *(volatile u8 *)0xCC008000=lower[3];
        *(volatile f32 *)0xCC008000=t0;
        *(volatile f32 *)0xCC008000=vh;
}
        }
        xpos+=fadv;
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

s32 Text_MeasureHeight(s32 arg0, f32 arg1) {
    s32 fn_8010494C(s32);
    s32 fn_80104E40(void);
    s32 index, value;
    u32 *table;
    u32 result;
    if (arg0 == -1) arg0 = 0;
    result = (u32)fn_8010494C(lbl_802AEE20[arg0]);
    table = (u32 *)lbl_802AEE20;
    index = Text_FindFontIndex(table, result);
    value = (s32)(arg1 * (f32)fn_80104E40());
    if (index == -1) index = 0;
    result = (u32)fn_8010494C(lbl_802AEE20[index]);
    Text_FindFontIndex(table, result);
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
