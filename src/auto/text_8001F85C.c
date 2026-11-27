/* Functions from 0x8001EEEC to 0x80028864, found by decomp-toolkit. */
#define STEPY(SIGN, DIR, M1, M2) { \
    u8 y, x; \
    s32 nextY; \
    s32 nextIndex, index; \
    u16 terrain, cost, oldCost; \
    u8 *q; \
    entry = *(u8 **)(self + 0x24ED8); \
    y = entry[1]; \
    x = entry[0]; \
    nextY = y SIGN 1; \
    index = (s8)x + ((s8)y * 64); \
    terrain = *(u16 *)(self + 0x408E + index * 2); \
    if ((terrain & (M1)) == 0) { \
        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1); \
        if ((terrain & (M2)) == 0) { \
            cost++; \
        } else if (self[index + 0x100D] == 0x1C) { \
            cost += 2; \
        } \
        nextIndex = (s8)x + ((s8)nextY * 64); \
        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex]; \
        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) { \
            q = *(u8 **)(self + 0x24EDC); \
            q[0] = x; \
            q = *(u8 **)(self + 0x24EDC); \
            q[1] = nextY; \
            q = *(u8 **)(self + 0x24EDC); \
            q[2] = (DIR); \
            q = *(u8 **)(self + 0x24EDC); \
            *(u16 *)(q + 4) = cost; \
            q = *(u8 **)(self + 0x24EDC); \
            *(u8 **)(self + 0x24EDC) = q + 6; \
            self[0x24EE1]++; \
            (*(s16 **)(self + 0x14190))[nextIndex] = cost; \
            if ((u16)cost >= self[0x24EE9]) { \
                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1; \
            } \
        } \
    } \
}
#define STEPX(SIGN, DIR, M1, M2) { \
    u8 y, x; \
    s32 nextX; \
    s32 nextIndex, index; \
    u16 terrain, cost, oldCost; \
    u8 *q; \
    entry = *(u8 **)(self + 0x24ED8); \
    y = entry[1]; \
    x = entry[0]; \
    nextX = x SIGN 1; \
    index = (s8)x + ((s8)y * 64); \
    terrain = *(u16 *)(self + 0x408E + index * 2); \
    if ((terrain & (M1)) == 0) { \
        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1); \
        if ((terrain & (M2)) == 0) { \
            cost++; \
        } else if (self[index + 0x100D] == 0x1C) { \
            cost += 2; \
        } \
        nextIndex = (s8)nextX + ((s8)y * 64); \
        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex]; \
        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) { \
            q = *(u8 **)(self + 0x24EDC); \
            q[0] = nextX; \
            q = *(u8 **)(self + 0x24EDC); \
            q[1] = y; \
            q = *(u8 **)(self + 0x24EDC); \
            q[2] = (DIR); \
            q = *(u8 **)(self + 0x24EDC); \
            *(u16 *)(q + 4) = cost; \
            q = *(u8 **)(self + 0x24EDC); \
            *(u8 **)(self + 0x24EDC) = q + 6; \
            self[0x24EE1]++; \
            (*(s16 **)(self + 0x14190))[nextIndex] = cost; \
            if ((u16)cost >= self[0x24EE9]) { \
                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1; \
            } \
        } \
    } \
}
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

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma fp_contract off
#pragma global_optimizer off

#pragma global_optimizer off

s32 fn_8001F85C(u8 *map, s32 x1, s32 y1, s32 x2, s32 y2) {
    s32 sy1;
    s32 sy2;
    s32 sx1;
    s32 sx2;
    u16 flags;
    u8 dir;
    u8 r;
    register s32 dx;
    register s32 dy;

    sy2 = (s8)y2;
    sy1 = (s8)y1;
    dy = Map_AbsDiff(sy1, sy2);
    sx2 = (s8)x2;
    sx1 = (s8)x1;
    dx = Map_AbsDiff(sx1, sx2);
    if (dx + dy != 1) {
        return 0;
    }
    map += (sx1 + (sy1 << 6)) << 1;
    flags = *(u16 *)(map + 0x408E);
    if ((s8)x1 < (s8)x2) {
        dir = 2;
    } else if ((s8)x1 > (s8)x2) {
        dir = 1;
    } else if ((s8)y1 < (s8)y2) {
        dir = 4;
    } else if ((s8)y1 > (s8)y2) {
        dir = 8;
    } else {
        dir = 0x10;
    }
    r = (flags & dir) != 0;
    return r != 0;
}
#pragma global_optimizer reset
void fn_8001F91C(void *map, s8 cx, s8 cy, s8 rad) {
    s32 cy_s = cy;
    u8 *row = (u8 *)map;
    s32 cx_s = cx;
    s32 rad_s = rad;
    s32 x;
    s32 y;
    s32 yext;
    s32 xext;

    y = 0;
    goto y_check;
    do {
        s32 dy;
        u8 *cell;
        s32 one;
        s32 ndy;

        dy = yext - cy_s;
        cell = row;
        x = 0;
        one = 1;
        ndy = -dy;
        goto x_check;
        do {
            s32 ady;
            s32 dx;

            ady = dy;
            if (dy < 0) {
                ady = ndy;
            }
            dx = xext - cx_s;
            if (dx < 0) {
                dx = -dx;
            }
            if (ady + dx <= rad_s) {
                cell[0x200D] = one;
            }
            cell++;
            x++;
        x_check:
            xext = (s8)x;
        } while (xext < *(s32 *)map);

        row += 0x40;
        y++;
    y_check:
        yext = (s8)y;
    } while (yext < *(s32 *)((u8 *)map + 4));
}

void fn_8001F9C4(void *arg0, s8 arg1, s8 arg2, s8 arg3, s16 arg4) {
    s16 *values;
    u8 *cell;
    u8 *rowptr;
    s32 centerY;
    s32 centerX;
    s32 radius;
    s32 index;
    s32 row;
    s8 ymin;
    s32 dx;
    s32 ady;
    s8 xmax;
    s8 ymax;
    s32 negdy;
    s8 x;
    s8 y;
    s32 dy;
    s8 xmin;

    radius = arg3;
    centerX = arg1;
    xmin = (s8)(centerX - radius);
    if (xmin < 0) {
        xmin = 0;
    }
    centerY = arg2;
    ymin = (s8)(centerY - radius);
    if (ymin < 0) {
        ymin = 0;
    }
    xmax = (s8)(centerX + radius);
    if (xmax > *(s32 *)arg0 - 1) {
        xmax = (s8)(*(s32 *)arg0 - 1);
    }
    ymax = (s8)(centerY + radius);
    if (ymax > *(s32 *)((u8 *)arg0 + 4) - 1) {
        ymax = (s8)(*(s32 *)((u8 *)arg0 + 4) - 1);
    }
    row = ymin << 6;
    rowptr = (u8 *)arg0 + row;
    for (y = ymin; y <= ymax; y++) {
        dy = y - centerY;
        negdy = -dy;
        index = xmin + row;
        cell = rowptr + xmin;
        for (x = xmin; x <= xmax; x++) {
            ady = dy;
            if (dy < 0) {
                ady = negdy;
            }
            dx = x - centerX;
            if (dx < 0) {
                dx = -dx;
            }
            if (dx + ady <= radius && *(s8 *)(cell + 0xe18e) == 0) {
                values = *(s16 **)((u8 *)arg0 + 0x14190);
                values[index] = arg4 + values[index];
            }
            cell++;
            index++;
        }
        rowptr += 0x40;
        row += 0x40;
    }
}

s32 fn_8001FB04(void *arg0, s8 *x, s8 *y, u8 arg3, u8 *path) {
 s8 oldx,oldy;
 u8 *last;
 if(path==0) path=(u8*)arg0+0x14194;
 oldx=*x; oldy=*y; last=path;
 for(;;) {
 u8 *cell;
 s32 index;
 s8 cx,cy;
 switch(*path++) {
 case 1: --*x; break;
 case 2: ++*x; break;
 case 4: ++*y; break;
 case 8: --*y; break;
 case 16: goto done;
 }
 cy=*y; cx=*x;
 index=cx+(cy<<6); index=(s32)arg0+index; cell=(u8*)index;
 if(cell[0x300d]&1) goto blocked;
 if((cell[0x300d]&2) && !arg3) goto stop;
 if(*(s8*)(cell+0xe18e)==0) { oldx=cx; oldy=cy; last=path; }
 }
 done: return 0;
 blocked: *x=oldx; *y=oldy; *last=16; return 1;
 stop: last[1]=16; return 2;
}

#pragma global_optimizer reset
u8 *fn_8001FC24(u8 *arg0) {
arg0+=0x14194;
*arg0=0x10;
return arg0;
}

s32 BattleMap_GetPath(s32 arg0) {
    return arg0 + 0x14194;
}

u8 *fn_8001FC7C(void *arg0, u8 *arg1, s8 arg2, s8 arg3);
u8 *fn_8001FC40(void *arg0, s8 arg1, s8 arg2) {
    M2C_FIELD(arg0, u8 *, 0xC) = 1;
    return fn_8001FC7C(arg0, (u8 *)arg0 + 0x14194, arg1, arg2);
}

extern u8 lbl_80366DB8[8];
s32 Rand_Range(s32);
u8 *fn_8001FC7C(void *arg0, u8 *arg1, s8 arg2, s8 arg3) {
    s32 Rand_Range(s32);
    typedef struct {
        u8 pad0[0x408E];
        u16 flags[0x8000];
        u8 pad1408E[0x102];
        s16 *distMap;
        u8 pad14194[0x10D56];
        u8 mode;
    } MapState;

    u16 dist[4];
    u8 buf[0x80];
    u8 cand[4];
    MapState *map = (MapState *)arg0;
    u8 *start;
    u8 *dst;
    u8 *out;
    u8 *src;
    s32 i;
    u16 min;
    u8 n;
    u8 dir;

    start = arg1;
    while (map->distMap[arg2 + (arg3 << 6)] != 0) {
        if (map->mode != 0) {
            if (map->flags[(s8)(arg2 + 1) + (arg3 << 6)] & 0x10) {
                dist[0] = 0xFFFF;
            } else {
                dist[0] = map->distMap[(s8)(arg2 + 1) + (arg3 << 6)];
            }
            if (map->flags[(s8)(arg2 - 1) + (arg3 << 6)] & 0x20) {
                dist[1] = 0xFFFF;
            } else {
                dist[1] = map->distMap[(s8)(arg2 - 1) + (arg3 << 6)];
            }
            if (map->flags[arg2 + ((s8)(arg3 + 1) << 6)] & 0x80) {
                dist[3] = 0xFFFF;
            } else {
                dist[3] = map->distMap[arg2 + ((s8)(arg3 + 1) << 6)];
            }
            if (map->flags[arg2 + ((s8)(arg3 - 1) << 6)] & 0x40) {
                dist[2] = 0xFFFF;
            } else {
                dist[2] = map->distMap[arg2 + ((s8)(arg3 - 1) << 6)];
            }
        } else {
            if (map->flags[(s8)(arg2 + 1) + (arg3 << 6)] & 0x1) {
                dist[0] = map->distMap[(s8)(arg2 + 1) + (arg3 << 6)];
            } else {
                dist[0] = 0xFFFF;
            }
            if (map->flags[(s8)(arg2 - 1) + (arg3 << 6)] & 0x2) {
                dist[1] = map->distMap[(s8)(arg2 - 1) + (arg3 << 6)];
            } else {
                dist[1] = 0xFFFF;
            }
            if (map->flags[arg2 + ((s8)(arg3 + 1) << 6)] & 0x8) {
                dist[3] = map->distMap[arg2 + ((s8)(arg3 + 1) << 6)];
            } else {
                dist[3] = 0xFFFF;
            }
            if (map->flags[arg2 + ((s8)(arg3 - 1) << 6)] & 0x4) {
                dist[2] = map->distMap[arg2 + ((s8)(arg3 - 1) << 6)];
            } else {
                dist[2] = 0xFFFF;
            }
        }

        min = 0xFFFF;
        n = 0;
        for (i = 0; i < 4; i++) {
            if (min > dist[i]) {
                min = dist[i];
            }
        }

        for (i = 0; i < 4; i++) {
            if (min == dist[i]) {
                cand[n++] = lbl_80366DB8[i];
            }
        }

        switch (n) {
            case 1:
                dir = cand[0];
                break;
            case 2:
            case 3:
            case 4:
                dir = cand[Rand_Range(n)];
                break;
        }

        *(arg1++) = dir;
        switch (dir) {
            case 1:
                arg2++;
                break;
            case 2:
                arg2--;
                break;
            case 8:
                arg3++;
                break;
            case 4:
                arg3--;
                break;
        }
    }

    src = arg1;
    out = start;
    dst = buf;
    while (src > start) {
        *(dst++) = *(--src);
    }

    *dst = 0x10;
    src = buf;
    while (*src != 0x10) {
        *(out++) = *(src++);
    }

    *out = 0x10;
    return start;
}

#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
volatile char Map_FillAttackRange(void *arg0, s8 arg1, s8 arg2, u8 arg3, u8 arg4)
{
    void Map_FillLayer(void *, s32, s32);
    register s8 startX = arg1;
    register u8 *self = (u8 *)arg0;
    register s8 startY = arg2;
    u8 *entry;
    u8 *write;
    u8 *read;
    u8 direction;
    u8 slot;

    self[0x24EE0] = 0;
    *(u16 *)(self + 0x24EE2) = arg4;
    *(u8 **)(self + 0x24ED8) = self + 0x242D8;
    *(u8 **)(self + 0x24EDC) = self + 0x248D8;
    self[0x24EE9] = arg3;

    write = *(u8 **)(self + 0x24EDC);
    write[0] = startX;
    write = *(u8 **)(self + 0x24EDC);
    write[1] = startY;
    write = *(u8 **)(self + 0x24EDC);
    write[2] = 0x20;
    write = *(u8 **)(self + 0x24EDC);
    *(u16 *)(write + 4) = 0;
    write = *(u8 **)(self + 0x24EDC);
    *(u8 **)(self + 0x24EDC) = write + 6;
    write = *(u8 **)(self + 0x24EDC);
    write[2] = 0x10;

    Map_FillLayer(self, 0xB, -1);
    (*(s16 **)(self + 0x14190))[(s8)startX + ((s8)startY * 64)] = 0;

    for (;;) {
        slot = self[0x24EE0];
        *(u8 **)(self + 0x24EDC) = self + (slot * 0x600 + 0x242D8);
        self[0x24EE0] ^= 1;
        slot = self[0x24EE0];
        *(u8 **)(self + 0x24ED8) = self + (slot * 0x600 + 0x242D8);
        self[0x24EE1] = 0;

        entry = *(u8 **)(self + 0x24ED8);
        if (entry[2] == 0x10) {
            break;
        }

        while ((direction = (entry = *(u8 **)(self + 0x24ED8))[2]) != 0x10) {
            switch (direction) {
            case 0x20:
                {
                    u8 x, y;
                    s32 nextY;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    y = entry[1];
                    x = entry[0];
                    nextY = y - 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x8080) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0808) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)x + ((s8)nextY * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = x;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = nextY;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x08;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                {
                    u8 x, y;
                    s32 nextY;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    entry = *(u8 **)(self + 0x24ED8);
                    y = entry[1];
                    x = entry[0];
                    nextY = y + 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x4040) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0404) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)x + ((s8)nextY * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = x;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = nextY;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x04;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                {
                    u8 x, y;
                    s32 nextX;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    entry = *(u8 **)(self + 0x24ED8);
                    y = entry[1];
                    x = entry[0];
                    nextX = x - 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x1010) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0101) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)nextX + ((s8)y * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = nextX;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = y;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x01;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                {
                    u8 x, y;
                    s32 nextX;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    entry = *(u8 **)(self + 0x24ED8);
                    y = entry[1];
                    x = entry[0];
                    nextX = x + 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x2020) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0202) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)nextX + ((s8)y * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = nextX;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = y;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x02;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                break;
            case 0x08:
                {
                    u8 x, y;
                    s32 nextY;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    y = entry[1];
                    x = entry[0];
                    nextY = y - 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x8080) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0808) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)x + ((s8)nextY * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = x;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = nextY;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x08;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                {
                    u8 x, y;
                    s32 nextX;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    entry = *(u8 **)(self + 0x24ED8);
                    y = entry[1];
                    x = entry[0];
                    nextX = x - 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x1010) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0101) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)nextX + ((s8)y * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = nextX;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = y;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x01;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                {
                    u8 x, y;
                    s32 nextX;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    entry = *(u8 **)(self + 0x24ED8);
                    y = entry[1];
                    x = entry[0];
                    nextX = x + 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x2020) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0202) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)nextX + ((s8)y * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = nextX;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = y;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x02;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                break;
            case 0x04:
                {
                    u8 x, y;
                    s32 nextY;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    y = entry[1];
                    x = entry[0];
                    nextY = y + 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x4040) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0404) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)x + ((s8)nextY * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = x;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = nextY;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x04;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                {
                    u8 x, y;
                    s32 nextX;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    entry = *(u8 **)(self + 0x24ED8);
                    y = entry[1];
                    x = entry[0];
                    nextX = x - 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x1010) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0101) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)nextX + ((s8)y * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = nextX;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = y;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x01;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                {
                    u8 x, y;
                    s32 nextX;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    entry = *(u8 **)(self + 0x24ED8);
                    y = entry[1];
                    x = entry[0];
                    nextX = x + 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x2020) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0202) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)nextX + ((s8)y * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = nextX;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = y;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x02;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                break;
            case 0x01:
                {
                    u8 x, y;
                    s32 nextY;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    y = entry[1];
                    x = entry[0];
                    nextY = y - 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x8080) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0808) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)x + ((s8)nextY * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = x;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = nextY;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x08;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                {
                    u8 x, y;
                    s32 nextY;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    entry = *(u8 **)(self + 0x24ED8);
                    y = entry[1];
                    x = entry[0];
                    nextY = y + 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x4040) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0404) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)x + ((s8)nextY * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = x;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = nextY;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x04;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                {
                    u8 x, y;
                    s32 nextX;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    entry = *(u8 **)(self + 0x24ED8);
                    y = entry[1];
                    x = entry[0];
                    nextX = x - 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x1010) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0101) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)nextX + ((s8)y * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = nextX;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = y;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x01;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                break;
            case 0x02:
                {
                    u8 x, y;
                    s32 nextY;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    y = entry[1];
                    x = entry[0];
                    nextY = y - 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x8080) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0808) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)x + ((s8)nextY * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = x;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = nextY;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x08;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                {
                    u8 x, y;
                    s32 nextY;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    entry = *(u8 **)(self + 0x24ED8);
                    y = entry[1];
                    x = entry[0];
                    nextY = y + 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x4040) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0404) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)x + ((s8)nextY * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = x;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = nextY;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x04;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                {
                    u8 x, y;
                    s32 nextX;
                    s32 index, nextIndex;
                    u16 terrain;
                    u16 cost;
                    u16 oldCost;
                    u8 *q;
                    entry = *(u8 **)(self + 0x24ED8);
                    y = entry[1];
                    x = entry[0];
                    nextX = x + 1;
                    index = (s8)x + ((s8)y * 64);
                    terrain = *(u16 *)(self + 0x408E + index * 2);
                    if ((terrain & 0x2020) == 0) {
                        cost = (u16)((*(s16 **)(self + 0x14190))[index] + 1);
                        if ((terrain & 0x0202) == 0) {
                            cost++;
                        } else if (self[index + 0x100D] == 0x1C) {
                            cost += 2;
                        }
                        nextIndex = (s8)nextX + ((s8)y * 64);
                        oldCost = (u16)(*(s16 **)(self + 0x14190))[nextIndex];
                        if ((u16)cost < oldCost && (u16)cost <= *(u16 *)(self + 0x24EE2)) {
                            q = *(u8 **)(self + 0x24EDC);
                            q[0] = nextX;
                            q = *(u8 **)(self + 0x24EDC);
                            q[1] = y;
                            q = *(u8 **)(self + 0x24EDC);
                            q[2] = 0x02;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u16 *)(q + 4) = cost;
                            q = *(u8 **)(self + 0x24EDC);
                            *(u8 **)(self + 0x24EDC) = q + 6;
                            self[0x24EE1]++;
                            (*(s16 **)(self + 0x14190))[nextIndex] = cost;
                            if ((u16)cost >= self[0x24EE9]) {
                                *(u16 *)(self + 0xC18E + nextIndex * 2) = 1;
                            }
                        }
                    }
                }
                break;
            }
            write = *(u8 **)(self + 0x24EDC);
            write[2] = 0x10;
            read = *(u8 **)(self + 0x24ED8);
            *(u8 **)(self + 0x24ED8) = read + 6;
        }
    }
}
#pragma pop
s16 fn_8002134C(u8 *map, s8 x, s8 y)
{
  extern u8 gUnits[];
  u8 *cell;
  u8 *hi;
  u8 *entry;
  u8 tid;
  u8 uid;
  s16 val;
  int new_var;
  u8 *unit;
  u8 *cls;
  cell = map + x;
  hi = map + 0x10000;
  cell += y << 6;
  if ((map && map) && map)
  {
  }
  tid = cell[0x100D];
  uid = cell[0xD];
  entry = hi;
  entry += tid << 1;
  val = (s16) (*((u16 *) (entry + 0x4214)));
  if (uid != 0)
  {
    new_var = 1;
    unit = (uid != 0) ? (gUnits + ((uid - new_var) * 0x280)) : (NULL);
    cls = *((u8 **) (unit + 0x190));
    map += 0x20000;
    map += cls[8];
    if (map[0x4EE4] != 0)
    {
      return 0x7FFE;
    }
  }
  return val;
}

void Map_FloodMoveRange(void *map, u8 x, u8 y, u16 range, s32 flagA, s32 flagB)
{
    void Map_FillLayer(void *, s32, s32);
    extern u8 gUnits[];
    typedef struct {
        u8 pad0[0x408E];
        u16 terrainFlags[0x1000];
        u8 pad1[0x14190 - 0x608E];
        s16 *costs;
        u8 pad2[0x14214 - 0x14194];
        u16 terrainCost[0x100];
        u8 pad3[0x242D8 - 0x14414];
        u8 queue[2][0x600];
        u8 *read;
        u8 *write;
        u8 slot;
        u8 count;
        u16 limit;
        u8 blocked[4];
        u8 mask;
        u8 unused;
        u8 flip;
    } FloodMapLayout;
    FloodMapLayout *self = (FloodMapLayout *)map;
    u8 *ed8;
    u8 *edc;
    u8 slot;
    s16 *costs;
    u8 nx;
    u8 ny;
    u8 kind;
    s8 nextCoord;
    u16 flags;
    u16 rawFlags;
    u16 neu;
    s16 oldc;
    u16 have;
    u8 *cell;
    u8 tid;
    u8 uid;
    u8 *unit;
    u8 *cls;

    self->slot = 0;
    self->limit = range;
    self->read = self->queue[0];
    self->write = self->queue[1];

    edc = self->write;
    edc[0] = x;
    edc = self->write;
    edc[1] = y;
    edc = self->write;
    edc[2] = 0x20;
    edc = self->write;
    *(u16 *)(edc + 4) = 0;
    edc = self->write;
    self->write = edc + 6;
    edc = self->write;
    edc[2] = 0x10;

    Map_FillLayer(map, 0xB, -1);

    ((u8 *)map)[0xC] = 0;
    costs = self->costs;
    costs[(s8)x + ((s8)y << 6)] = 0;

    if ((u8)flagB == 0 || (u8)flagA == 0) {
        self->mask = 0;
        if ((u8)flagB != 0) {
            self->mask |= 1;
        }
        if ((u8)flagA != 0) {
            self->mask |= 2;
        }
    }

    for (;;) {
        slot = self->slot;
        self->write = self->queue[slot];
        self->slot ^= 1;
        slot = self->slot;
        self->read = self->queue[slot];
        self->count = 0;

        ed8 = self->read;
        if (ed8[2] == 0x10) {
            break;
        }

        while ((ed8 = self->read), (kind = ed8[2]) != 0x10) {
            ny = ed8[1];
            nx = ed8[0];
            rawFlags = self->terrainFlags[(s8)nx + ((s8)ny << 6)];
            flags = rawFlags;
            if (self->flip != 0) {
                flags = (u16)(((rawFlags ^ 0xF0) >> 4) & 0xFFF);
            }

            switch (kind) {
            case 0x20:
                if (flags & 0x8) {
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(ny - 1);
                    cell = (u8 *)map + (s8)nx + (((s8)nextCoord) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c20_s;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)nextCoord) << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = nx;
                        edc = self->write;
                        edc[1] = (u8)nextCoord;
                        edc = self->write;
                        edc[2] = 0x8;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[(s8)nx + (((s8)nextCoord) << 6)] = (s16)neu;
                    }
                }
            c20_s:
                if (flags & 0x4) {
                    ny = (self->read)[1];
                    nx = (self->read)[0];
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(ny + 1);
                    cell = (u8 *)map + (s8)nx + (((s8)nextCoord) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c20_w;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)nextCoord) << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = nx;
                        edc = self->write;
                        edc[1] = (u8)nextCoord;
                        edc = self->write;
                        edc[2] = 0x4;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[(s8)nx + (((s8)nextCoord) << 6)] = (s16)neu;
                    }
                }
            c20_w:
                if (flags & 0x1) {
                    ny = (self->read)[1];
                    nx = (self->read)[0];
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(nx - 1);
                    cell = (u8 *)map + ((s8)nextCoord) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c20_e;
                        }
                    }
                    have = (u16)costs[((s8)nextCoord) + ((s8)ny << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = (u8)nextCoord;
                        edc = self->write;
                        edc[1] = ny;
                        edc = self->write;
                        edc[2] = 0x1;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[((s8)nextCoord) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
            c20_e:
                if (flags & 0x2) {
                    ny = (self->read)[1];
                    nx = (self->read)[0];
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(nx + 1);
                    cell = (u8 *)map + ((s8)nextCoord) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            break;
                        }
                    }
                    have = (u16)costs[((s8)nextCoord) + ((s8)ny << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = (u8)nextCoord;
                        edc = self->write;
                        edc[1] = ny;
                        edc = self->write;
                        edc[2] = 0x2;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[((s8)nextCoord) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
                break;
            case 0x8:
                if (flags & 0x8) {
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(ny - 1);
                    cell = (u8 *)map + (s8)nx + (((s8)nextCoord) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c8_w;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)nextCoord) << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = nx;
                        edc = self->write;
                        edc[1] = (u8)nextCoord;
                        edc = self->write;
                        edc[2] = 0x8;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[(s8)nx + (((s8)nextCoord) << 6)] = (s16)neu;
                    }
                }
            c8_w:
                if (flags & 0x1) {
                    ny = (self->read)[1];
                    nx = (self->read)[0];
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(nx - 1);
                    cell = (u8 *)map + ((s8)nextCoord) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c8_e;
                        }
                    }
                    have = (u16)costs[((s8)nextCoord) + ((s8)ny << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = (u8)nextCoord;
                        edc = self->write;
                        edc[1] = ny;
                        edc = self->write;
                        edc[2] = 0x1;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[((s8)nextCoord) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
            c8_e:
                if (flags & 0x2) {
                    ny = (self->read)[1];
                    nx = (self->read)[0];
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(nx + 1);
                    cell = (u8 *)map + ((s8)nextCoord) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            break;
                        }
                    }
                    have = (u16)costs[((s8)nextCoord) + ((s8)ny << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = (u8)nextCoord;
                        edc = self->write;
                        edc[1] = ny;
                        edc = self->write;
                        edc[2] = 0x2;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[((s8)nextCoord) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
                break;
            case 0x4:
                if (flags & 0x4) {
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(ny + 1);
                    cell = (u8 *)map + (s8)nx + (((s8)nextCoord) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c4_w;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)nextCoord) << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = nx;
                        edc = self->write;
                        edc[1] = (u8)nextCoord;
                        edc = self->write;
                        edc[2] = 0x4;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[(s8)nx + (((s8)nextCoord) << 6)] = (s16)neu;
                    }
                }
            c4_w:
                if (flags & 0x1) {
                    ny = (self->read)[1];
                    nx = (self->read)[0];
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(nx - 1);
                    cell = (u8 *)map + ((s8)nextCoord) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c4_e;
                        }
                    }
                    have = (u16)costs[((s8)nextCoord) + ((s8)ny << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = (u8)nextCoord;
                        edc = self->write;
                        edc[1] = ny;
                        edc = self->write;
                        edc[2] = 0x1;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[((s8)nextCoord) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
            c4_e:
                if (flags & 0x2) {
                    ny = (self->read)[1];
                    nx = (self->read)[0];
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(nx + 1);
                    cell = (u8 *)map + ((s8)nextCoord) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            break;
                        }
                    }
                    have = (u16)costs[((s8)nextCoord) + ((s8)ny << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = (u8)nextCoord;
                        edc = self->write;
                        edc[1] = ny;
                        edc = self->write;
                        edc[2] = 0x2;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[((s8)nextCoord) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
                break;
            case 0x1:
                if (flags & 0x8) {
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(ny - 1);
                    cell = (u8 *)map + (s8)nx + (((s8)nextCoord) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c1_s;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)nextCoord) << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = nx;
                        edc = self->write;
                        edc[1] = (u8)nextCoord;
                        edc = self->write;
                        edc[2] = 0x8;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[(s8)nx + (((s8)nextCoord) << 6)] = (s16)neu;
                    }
                }
            c1_s:
                if (flags & 0x4) {
                    ny = (self->read)[1];
                    nx = (self->read)[0];
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(ny + 1);
                    cell = (u8 *)map + (s8)nx + (((s8)nextCoord) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c1_w;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)nextCoord) << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = nx;
                        edc = self->write;
                        edc[1] = (u8)nextCoord;
                        edc = self->write;
                        edc[2] = 0x4;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[(s8)nx + (((s8)nextCoord) << 6)] = (s16)neu;
                    }
                }
            c1_w:
                if (flags & 0x1) {
                    ny = (self->read)[1];
                    nx = (self->read)[0];
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(nx - 1);
                    cell = (u8 *)map + ((s8)nextCoord) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            break;
                        }
                    }
                    have = (u16)costs[((s8)nextCoord) + ((s8)ny << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = (u8)nextCoord;
                        edc = self->write;
                        edc[1] = ny;
                        edc = self->write;
                        edc[2] = 0x1;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[((s8)nextCoord) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
                break;
            case 0x2:
                if (flags & 0x8) {
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(ny - 1);
                    cell = (u8 *)map + (s8)nx + (((s8)nextCoord) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c2_s;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)nextCoord) << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = nx;
                        edc = self->write;
                        edc[1] = (u8)nextCoord;
                        edc = self->write;
                        edc[2] = 0x8;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[(s8)nx + (((s8)nextCoord) << 6)] = (s16)neu;
                    }
                }
            c2_s:
                if (flags & 0x4) {
                    ny = (self->read)[1];
                    nx = (self->read)[0];
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(ny + 1);
                    cell = (u8 *)map + (s8)nx + (((s8)nextCoord) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c2_e;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)nextCoord) << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = nx;
                        edc = self->write;
                        edc[1] = (u8)nextCoord;
                        edc = self->write;
                        edc[2] = 0x4;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[(s8)nx + (((s8)nextCoord) << 6)] = (s16)neu;
                    }
                }
            c2_e:
                if (flags & 0x2) {
                    ny = (self->read)[1];
                    nx = (self->read)[0];
                    costs = self->costs;
                    oldc = costs[(s8)nx + ((s8)ny << 6)];
                    nextCoord = (s8)(nx + 1);
                    cell = (u8 *)map + ((s8)nextCoord) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + self->terrainCost[tid]);
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            break;
                        }
                    }
                    have = (u16)costs[((s8)nextCoord) + ((s8)ny << 6)];
                    if (neu < have && neu <= self->limit) {
                        edc = self->write;
                        edc[0] = (u8)nextCoord;
                        edc = self->write;
                        edc[1] = ny;
                        edc = self->write;
                        edc[2] = 0x2;
                        edc = self->write;
                        *(u16 *)(edc + 4) = neu;
                        edc = self->write;
                        self->write = edc + 6;
                        self->count++;
                        costs = self->costs;
                        costs[((s8)nextCoord) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
                break;
            }

            edc = self->write;
            edc[2] = 0x10;
            ed8 = self->read;
            self->read = ed8 + 6;
            ed8 = self->read;
        }
    }
}

void fn_80022748(u8 *map, u8 *arg1) {
    u8 v;

    if (arg1 == NULL) {
        map += 0x20000;
        map[0x4EE4] = 0;
        map[0x4EE5] = 0;
        map[0x4EE6] = 0;
        map[0x4EE7] = 0;
        return;
    }
    v = arg1[8];
    switch (v) {
    case 0:
    case 2:
    case 3:
        map += 0x20000;
        map[0x4EE4] = 0;
        map[0x4EE5] = 1;
        map[0x4EE6] = 0;
        map[0x4EE7] = 0;
        break;
    case 1:
        map += 0x20000;
        map[0x4EE4] = 1;
        map[0x4EE5] = 0;
        map[0x4EE6] = 1;
        map[0x4EE7] = 1;
        break;
    }
}

#pragma optimization_level 2
#pragma scheduling on
void fn_800227D0(s32 arg0, s32 arg1, s8 arg2) { s32 base; s16 value; s32 offset; base=arg0+0x10000; offset=arg1<<1; value=arg2; arg0=base+offset; *(s16 *)(arg0+0x4214)=value; if(arg2<0) *(s16 *)(arg0+0x4214)=0x7FFE; }
#pragma scheduling reset
#pragma optimization_level reset
void fn_800227F8(void *arg0, void *arg1) {
    struct Map { u8 pad[0x14214]; s16 costs[77]; };
    struct Terrain { u32 unk0, unk4; s8 *data; };
    struct Terrain *Terrain_GetEntry(s32);
    u8 Status_Test(void *, s32);
    struct Map *map = arg0;
    u8 *unit = arg1;
    struct Terrain *terrain;
    terrain = Terrain_GetEntry(0);
    if (unit == 0) {
        int i;
        for (i = 1; i < 77; i++) {
            map->costs[i] = 1;
        }
        map->costs[0] = 0x7FFF;
        ((u8 *)map)[0x24EEA] = 1;
    } else {
        int i;
        for (i = 0; i < 77; i++, terrain++) {
            map->costs[i] = (terrain->data[unit[0x42] + 8] >= 0) ? terrain->data[unit[0x42] + 8] : 0x7FFF;
        }
        ((u8 *)map)[0x24EEA] = Status_Test(unit + 0x1C, 4) != 0;
    }
}

#pragma push
#pragma optimization_level 3
void Map_RefreshUnitMap(void *arg0)
{
    void Allegiance_SetMask(s32, s32, s32, s32, s32, s32, s32, s32, void *);
    void fn_8001F140(void *);
    void Map_FillLayer(void *, s32, u8);
    s8 fn_8003A1C4(void *);
    void fn_8010FAA8(void);
    extern u8 gUnits[];
    extern u8 gBattleState[];
    extern u8 gMapBlendMode;

    u8 buf1[8];
    u8 buf2[8];
    u8 buf3[8];
    void *self;
    u8 *unit;
    s32 i;
    s8 x, y;
    s8 rad;
    s8 ux, uy;
    s32 adx;
    s32 ax;
    s32 ady;
    u8 *row;
    u8 *cursor;
    u8 f;
    s32 saved;

    f = 1;
    self = arg0;
    if (!((u8)(gMapBlendMode - 1) <= 1)) {
        f = 0;
    }
    saved = (f != 0);
    Map_FillLayer(self, 0, 0);
    Map_FillLayer(self, 2, (u8)(saved == 0));
    Map_FillLayer(self, 3, 0);
    Allegiance_SetMask(1, 0, 1, 1, 0, 0, 0, 0, buf1);

    unit = 0;
    for (i = 0x9F; i >= 1; i--) {
        if ((u8)i != 0) {
            unit = gUnits + ((u8)i - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (*(u32 *)(unit + 0x188) != 0
            && buf1[*(u8 *)(*(u8 **)(unit + 0x190) + 8)] != 0
            && (*(u32 *)(unit + 0x1A0) & 0x010000DC) == 0) {
            ((u8 *)self)[*(s8 *)(unit + 0x19E) + (*(s8 *)(unit + 0x19F) << 6) + 0xD] =
                unit[0x198];
            rad = fn_8003A1C4(unit);
            uy = *(s8 *)(unit + 0x19F);
            row = (u8 *)self;
            ux = *(s8 *)(unit + 0x19E);
            for (y = 0; y < *(s32 *)((u8 *)self + 4); y++) {
                adx = y - uy;
                cursor = row;
                for (x = 0; x < *(s32 *)self; x++) {
                    ax = (adx < 0) ? -adx : adx;
                    ady = (x - ux < 0) ? -(x - ux) : (x - ux);
                    if (ady + ax <= rad) {
                        cursor[0x200D] = 1;
                    }
                    cursor += 1;
                }
                row += 0x40;
            }
        }
    }

    if (gBattleState[0x11] != 1) {
        Allegiance_SetMask(0, 1, 0, 0, 0, 0, 0, 0, buf2);
        for (i = 0x9F; i > 0; i--) {
            if ((u8)i != 0) {
                unit = gUnits + ((u8)i - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (*(u32 *)(unit + 0x188) != 0
                && buf2[*(u8 *)(*(u8 **)(unit + 0x190) + 8)] != 0
                && (*(u32 *)(unit + 0x1A0) & 0x0100009C) == 0) {
                if (((u8 *)self)[*(s8 *)(unit + 0x19E) + (*(s8 *)(unit + 0x19F) << 6) + 0x200D] != 0) {
                    ((u8 *)self)[*(s8 *)(unit + 0x19E) + (*(s8 *)(unit + 0x19F) << 6) + 0xD] = unit[0x198];
                    {
                        u32 fr = *(u32 *)(unit + 0x1A0);
                        if (fr & 0x40) {
                            *(u32 *)(unit + 0x1A0) = fr & ~0x40;
                            *(u32 *)(unit + 0x1A0) = *(u32 *)(unit + 0x1A0) | 0x200;
                        }
                    }
                } else {
                    ((u8 *)self)[*(s8 *)(unit + 0x19E) + (*(s8 *)(unit + 0x19F) << 6) + 0x300D] |= 1;
                    {
                        u32 fr = *(u32 *)(unit + 0x1A0);
                        if (!(fr & 0x40)) {
                            *(u32 *)(unit + 0x1A0) = fr | 0x240;
                        }
                    }
                }
            }
        }
    } else {
        Allegiance_SetMask(0, 1, 0, 0, 0, 0, 0, 0, buf3);
        for (i = 0x9F; i > 0; i--) {
            if ((u8)i != 0) {
                unit = gUnits + ((u8)i - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (*(u32 *)(unit + 0x188) != 0
                && buf3[*(u8 *)(*(u8 **)(unit + 0x190) + 8)] != 0
                && (*(u32 *)(unit + 0x1A0) & 4) == 0) {
                if (((u8 *)self)[*(s8 *)(unit + 0x19E) + (*(s8 *)(unit + 0x19F) << 6) + 0x200D] != 0) {
                    *(u32 *)(unit + 0x1A0) &= ~0x40;
                } else {
                    *(u32 *)(unit + 0x1A0) |= 0x40;
                }
                ((u8 *)self)[*(s8 *)(unit + 0x19E) + (*(s8 *)(unit + 0x19F) << 6) + 0xD] =
                    unit[0x198];
            }
        }
    }
    fn_8010FAA8();
    fn_8001F140(self);
}
#pragma pop
extern u16 jumptable_80284514[12];
#pragma push
#pragma optimization_level 4
#pragma global_optimizer on
void Map_FillLayer(void *arg0, u32 arg1, u32 arg2)
{
    void fn_800062B0(u32 *, u32, u32);
    u32 fn_80022FB0(u32);

    u8 *map = (u8 *)arg0;
    u32 value;
    u32 *buffer;

    switch (arg1) {
    case 0:
        value = (arg2 & 0xFF) + (((arg2 << 24) + ((arg2 & 0xFF) << 16)) + ((arg2 & 0xFF) << 8));
        fn_800062B0((u32 *)(map + 0xD), value, 0x1000);
        break;
    case 1:
        value = (arg2 & 0xFF) + (((arg2 << 24) + ((arg2 & 0xFF) << 16)) + ((arg2 & 0xFF) << 8));
        fn_800062B0((u32 *)(map + 0x100D), value, 0x1000);
        break;
    case 2:
        value = (arg2 & 0xFF) + (((arg2 << 24) + ((arg2 & 0xFF) << 16)) + ((arg2 & 0xFF) << 8));
        fn_800062B0((u32 *)(map + 0x200D), value, 0x1000);
        break;
    case 3:
        value = (arg2 & 0xFF) + (((arg2 << 24) + ((arg2 & 0xFF) << 16)) + ((arg2 & 0xFF) << 8));
        fn_800062B0((u32 *)(map + 0x300D), value, 0x1000);
        break;
    case 4:
        value = arg2 & 0xFFFF;
        value += arg2 << 16;
        fn_800062B0((u32 *)(map + 0x608E), value, 0x2080);
        break;
    case 5:
        value = arg2 & 0xFFFF;
        value += arg2 << 16;
        fn_800062B0((u32 *)(map + 0x810E), value, 0x2080);
        break;
    case 10:
    case 11:
        buffer = *(u32 **)(map + 0x14190);
        if (buffer == (u32 *)(map + 0x610E)) {
            value = fn_80022FB0(arg2);
            fn_800062B0((u32 *)(map + 0x608E), value, 0x2080);
        } else if (buffer == (u32 *)(map + 0x818E)) {
            value = fn_80022FB0(arg2);
            fn_800062B0((u32 *)(map + 0x810E), value, 0x2080);
        } else {
            value = arg2 & 0xFFFF;
            value += arg2 << 16;
            fn_800062B0(buffer, value, 0x2000);
        }
        break;
    case 6:
    case 7:
        value = arg2 & 0xFFFF;
        value += arg2 << 16;
        fn_800062B0((u32 *)(map + 0xA18E), value, 0x2000);
        break;
    case 8:
        value = arg2 & 0xFFFF;
        value += arg2 << 16;
        fn_800062B0((u32 *)(map + 0xC18E), value, 0x2000);
        break;
    case 9:
        value = arg2 & 0xFFFF;
        value += arg2 << 16;
        fn_800062B0((u32 *)(map + 0x1218E), value, 0x2000);
        break;
    }
}
#pragma pop
s32 fn_80022FB0(u32 arg0) {
    u32 lo;
    u32 hi;
    lo = arg0 & 0xFFFF;
    hi = arg0 << 16;
    lo = lo + hi;
    return lo;
}

s32 fn_80022FC4(void) {
    return 0x2000;
}

void fn_80022FCC(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x14190) = arg1;
}

void Map_SelectRangeBuffer(void *arg0, s32 arg1) {
    if (arg1 != 6) {
        if (arg1 >= 6) {
            return;
        }
        if (arg1 < 5) {
            return;
        }
        *(s32 *)((char *)arg0 + 0x14190) = (s32)arg0 + 0x610E;
        return;
    }
    *(s32 *)((char *)arg0 + 0x14190) = (s32)arg0 + 0x818E;
}

#pragma opt_strength_reduction off
f32 Map_GetTileCornerHeight(void *arg0, s8 arg1, s8 arg2, u8 arg3)
{
    u8 *base = (u8 *)arg0 + 0x20000;
    s32 index = arg1 + (arg2 << 6);
    f32 scale = *(f32 *)(base - 0x3D2C);
    f32 height = ((s16 *)(base - 0x3D28))[(u8)arg3 + (index << 2)];
    return height * scale;
}
#pragma opt_strength_reduction reset
#pragma fp_contract on
