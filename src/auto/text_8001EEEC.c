/* Functions from 0x8001EEEC to 0x80028864, found by decomp-toolkit. */
#include "common.h"
#pragma cplusplus on
struct MenuSelection24768 { u8 pad[0x40]; u8 index; };
struct MenuController24768 { u32 pad;
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
virtual void v11(void *) = 0;
virtual void v12(void *) = 0;
virtual void v13(void *) = 0;
virtual u8 v14(void *) = 0;
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
virtual void * v27() = 0;
virtual void * v28() = 0;
};
struct MenuItem24768 {
virtual void v0() = 0;
virtual void v1() = 0;
virtual void * v2() = 0;
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
virtual void v15(void *,void *) = 0;
virtual void * v16(void *) = 0;
};
#pragma cplusplus off

typedef struct {
    s32 field_0x0;
    s32 field_0x4;
    s32 field_0x8;
    s32 field_0xC;
    s32 field_0x10;
    s32 field_0x14;
    s32 field_0x18;
    s32 field_0x1C;
    s32 field_0x20;
    s32 field_0x24;
    s32 field_0x28;
    s32 field_0x2C;
    s32 field_0x30;
    s32 field_0x34;
    s32 field_0x38;
} Actor;


#pragma push
#pragma opt_lifetimes off
void fn_8001EEEC(s8 *p)
{
start:
    switch (*p) {
    case 0:
        *p = 0x10;
        return;
    case 0x34:
        *p = 1;
        break;
    case 0x38:
        *p = 8;
        break;
    case 0x36:
        *p = 2;
        break;
    case 0x32:
        *p = 4;
        break;
    }
    p += 1;
    goto start;
}
#pragma pop
void fn_8001EF7C(void) {

}

#pragma use_lmw_stmw on
#pragma opt_common_subs off
#pragma push
#pragma opt_loop_invariants off
typedef struct {
    u8 pad0[0xC18E];
    s16 marks[0x1000];
    u8 padE18E[0x14190 - 0xE18E];
    s16 *costs;
} MapRangeBuffers;

static inline void Map_ClearRangeCell(MapRangeBuffers *map, s32 index, s32 offset)
{
    *(s16 *)((u8 *)map->costs + offset) = -1;
    map->marks[index] = 0;
}

void Map_ClipRangeByFacing(void *arg0, s8 x0, s8 y0, u8 facing)
{
    u8 Map_IsAiTerrainBlocked(s8, s8);
    extern u8 gBattleMap[];
    struct MapHi {
        u8 pad[0x4190];
        s16 *costs;
    };
    u8 *base;
    s32 yoff;
    u8 *row;
    struct MapHi *mapHi;
    u8 dir;
    s32 ox;
    s32 oy;
    s32 off;
    s32 idx;
    s32 y;
    s32 x;
    s32 xv;
    s16 *costs;

    dir = (u8)facing;
    base = gBattleMap;
    mapHi = (struct MapHi *)(base + 0x10000);
    ox = x0;
    oy = y0;
    y = ((s8 *)base)[9];
    goto outer_test;
outer:
    yoff = (s8)y << 6;
    x = ((s8 *)base)[8];
    row = base + yoff;
    goto inner_test;
inner:
    xv = (s8)x;
    costs = mapHi->costs;
    idx = xv + yoff;
    off = idx << 1;
    if (*(s16 *)((u8 *)costs + off) >= 0) {
        if ((s8)row[xv + 0xE18E] == 0) {
            if (Map_IsAiTerrainBlocked((s8)x, (s8)y) == 0) {
                switch (dir) {
                case 1:
                    if (ox < x) {
                        Map_ClearRangeCell((MapRangeBuffers *)arg0, idx, off);
                    }
                    break;
                case 2:
                    if (x < ox) {
                        Map_ClearRangeCell((MapRangeBuffers *)arg0, idx, off);
                    }
                    break;
                case 8:
                    if (oy < y) {
                        Map_ClearRangeCell((MapRangeBuffers *)arg0, idx, off);
                    }
                    break;
                case 4:
                    if (y < oy) {
                        Map_ClearRangeCell((MapRangeBuffers *)arg0, idx, off);
                    }
                    break;
                }
            }
        }
    }
    x += 1;
inner_test:
    if (x <= (s8)base[0xA] - 1) {
        goto inner;
    }
    y += 1;
outer_test:
    if (y <= (s8)base[0xB] - 1) {
        goto outer;
    }
}
#pragma pop
#pragma opt_common_subs reset
#pragma use_lmw_stmw reset
void fn_8001F140(void *arg0) {
    s32 OSGetTick(void);
    void fn_80022DAC(void *, s32, s32);
    void fn_800AACDC(void *);
    extern u8 lbl_802CA264[];
    extern u8 lbl_80367289;

    register u16 packed;
    void *next;
    u8 *bp;
    s8 row;
    register s32 i_up;
    register u8 *row_base;
    unsigned long t;
    register s32 idx;
    register void *node;
    register s32 idx2;
    u8 rt;
    s8 r;
    int ro;
    register s32 idx3_2;
    u8 var_r4;
    unsigned int i_cur_u;
    register s32 i_dn_u;
    s32 i_cur;
    register s32 row_off;
    s32 i_dn;
    u16 tflags;
    unsigned int bit;
    unsigned int masked;
    u8 up;
    u8 dn;
    u8 lf;
    u16 *p;
    s32 flags;
    unsigned long one;
    unsigned int temp;
    s8 col;
    s32 u;
    register s32 i_up_u;
    s8 row2;
    s32 ro2;
    u8 *base2;
    s32 idx3;
    u8 *bp2;
    s8 col2;
    s8 c;
    u32 zero;

    OSGetTick();
    fn_80022DAC(arg0, 9, 0);
    node = *(void **)(lbl_802CA264 + 0xC);
    while (node != NULL) {
        flags = *(s32 *)((u8 *)node + 0x1A0);
        next = *(void **)((u8 *)node + 0x184);
        if ((flags & (int)0x800) != 0 && (flags & (u32)0x010000DC) == 0) {
            fn_800AACDC(node);
            row = (s8)(*(s32 *)((u8 *)arg0 + 4) - 1);
            row_off = row << 6;
            row_base = (u8 *)arg0 + row_off;
            while (row >= 0) {
                col = (s8)(*(s32 *)arg0 - 1);
                idx = col + row_off;
                bp = row_base + col;
                idx2 = idx << 1;
                while (col >= 0) {
                    if ((s8)bp[0xE18E] == 0) {
                        p = (u16 *)((u8 *)arg0 + (idx << 1));
                        if (*(u16 *)((s32)p + 0xC18E) != 0) {
                            *(u16 *)((s32)p + 0x1218E) |= 0x2000;
                        }
                    }
                    bp -= 1;
                    idx--;
                    col -= 1;
                    idx2 -= 2;
                }
                row_base -= 0x40;
                row_off -= 0x40;
                row -= 1;
            }
        }
        node = next;
    }

    r = (s8)(*(s32 *)((u8 *)arg0 + 4) - 1);
    ro = r << 6;
    while (r >= 0) {
        c = (s8)(*(s32 *)arg0 - 1);
        i_cur_u = c + ro;
        i_up_u = c + ((s8)(r - 1) << 6);
        i_dn_u = c + ((s8)(r + 1) << 6);
        i_cur = i_cur_u << 1;
        i_dn = i_dn_u << 1;
        i_up = i_up_u << 1;
        while (c >= 0) {
            tflags = *(u16 *)((s32)arg0 + (i_cur_u << 1) + 0x1218E);
            if (tflags) {
                bit = (tflags >> 13) & 1;
                if (r == 0) {
                    up = 0;
                } else {
                    masked = *(u16 *)((s32)arg0 + (i_up_u << 1) + 0x1218E);
                    masked &= 0x2000;
                    up = (u32)__cntlzw(masked) >> 5;
                }
                if (r == *(s32 *)((u8 *)arg0 + 4) - 1) {
                    dn = 0;
                } else {
                    register masked = *(u16 *)((s32)arg0 + (i_dn_u << 1) + 0x1218E);
                    masked &= 0x2000;
                    dn = (u32)__cntlzw(masked) >> 5;
                }
                if (c == 0) {
                    lf = 0;
                } else {
                    masked = *(u16 *)((s32)arg0 + (((s8)(c - 1) + ro) << 1) + 0x1218E);
                    masked &= 0x2000;
                    lf = (u32)__cntlzw(masked) >> 5;
                }
                if (c == *(s32 *)arg0 - 1) {
                    rt = 0;
                } else {
                    masked = *(u16 *)((s32)arg0 + (((s8)(c + 1) + ro) << 1) + 0x1218E);
                    masked &= 0x2000;
                    rt = (u32)__cntlzw(masked) >> 5;
                }
                packed = 0;
                packed <<= 1;
                packed |= (u16)bit;
                if ((u32)bit != 0) {
                    packed <<= 6;
                    packed |= (u16)(u8)up;
                    packed <<= 1;
                    packed |= (u16)(u8)dn;
                    packed <<= 1;
                    packed |= (u16)(u8)rt;
                    packed <<= 1;
                    packed |= (u16)(u8)lf;
                } else {
                    packed <<= 9;
                }
                *(u16 *)((s32)arg0 + (i_cur_u << 1) + 0x1218E) = (packed << 4) & (u32)0xFFF0;
            }
            i_cur_u -= 1;
            i_cur -= 2;
            i_up_u -= 1;
            i_up -= 2;
            i_dn_u -= 1;
            i_dn -= 2;
            c -= 1;
        }
        ro -= 0x40;
        r -= 1;
    }

    one = 1;
    var_r4 = one;
    temp = (u8)(lbl_80367289 - 1);
    u = (u32)(one - temp) >> 1;
    t = one | ~temp;
    if (((u32)(t - u) >> 31) == 0) {
        var_r4 = 0;
    }
    if ((s32)var_r4 != 0) {
        register zero = 0;
        row2 = (s8)(*(s32 *)((u8 *)arg0 + 4) - 1);
        ro2 = row2 << 6;
        base2 = (u8 *)arg0 + ro2;
        while (0 <= row2) {
            col2 = (s8)(*(s32 *)arg0 - 1);
            idx3 = col2 + ro2;
            bp2 = base2 + col2;
            idx3_2 = idx3 << 1;
            while (0 <= col2) {
                if (bp2[0x200D] == 0) {
                    *(u16 *)((s32)arg0 + (idx3 << 1) + 0x1218E) = zero;
                }
                bp2 -= 1;
                idx3 -= 1;
                col2--;
                idx3_2 -= 2;
            }
            base2 -= 0x40;
            ro2 -= 0x40;
            row2--;
        }
    }
    OSGetTick();
}
s32 Map_IsInViewBounds(void *arg0, s8 arg1, s8 arg2) {
    if (arg1 < (s8) M2C_FIELD(arg0, u8 *, 8)) {
        return 0;
    }
    if (arg1 >= (s8) M2C_FIELD(arg0, u8 *, 0xA)) {
        return 0;
    }
    if (arg2 < (s8) M2C_FIELD(arg0, u8 *, 9)) {
        return 0;
    }
    return arg2 < (s8) M2C_FIELD(arg0, u8 *, 0xB);
}

#pragma fp_contract off
#pragma global_optimizer off
