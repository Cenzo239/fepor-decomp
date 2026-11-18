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
    register s32 dy;
    register s32 dx;
    u16 flags;
    u8 dir;
    u8 r;

    sy2 = (s8)y2;
    sy1 = (s8)y1;
    dy = sy1 - sy2;
    if (0 > dy) {
        dy = -dy;
    }
    sx2 = (s8)x2;
    sx1 = (s8)x1;
    dx = sx1 - sx2;
    if (0 > dx) {
        dx = -dx;
    }
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
 s32 dy;
 s8 xmin;
 s8 y;
 s8 x;
 s32 offset;
 s8 ymax;
 s8 xmax;
 s32 ady;
 s32 dx;
 s8 ymin;
 s32 row,index;
 s32 radius=arg3;
 s32 centerX=arg1;
 s32 centerY;
 s32 delta;
 s32 negdy;
 u8 *rowptr,*cell;
 s16 *values;
 xmin=centerX-radius; if(xmin<0) xmin=0;
 centerY=arg2;
 ymin=centerY-radius; if(ymin<0) ymin=0;
 xmax=centerX+radius; if(xmax>*(s32*)arg0-1) xmax=*(s32*)arg0-1;
 ymax=centerY+radius; if(ymax>*(s32*)((u8*)arg0+4)-1) ymax=*(s32*)((u8*)arg0+4)-1;
 delta=arg4;
 row=ymin<<6;
 rowptr=(u8*)arg0+row;
 for(y=ymin;y<=ymax;y++) {
 dy=y-centerY; negdy=-dy;
 index=xmin+row;
 cell=rowptr+xmin;
 offset=index*2;
 for(x=xmin;x<=xmax;x++) {
 ady=dy; if(dy<0) ady=negdy;
 dx=x-centerX; if(dx<0) dx=-dx;
 if(dx+ady<=radius && *(s8*)(cell+0xe18e)==0) {
 values=*(s16**)((u8*)arg0+0x14190);
 values[index]=delta+values[index];
 }
 cell++; index++; offset+=2;
 }
 rowptr+=0x40; row+=0x40;
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
    u8 cand[4];
    u16 dist[4];
    u8 buf[0x88];
    u8 *start;
    u8 *src;
    u8 *dst;
    u8 *out;
    s32 i;
    u16 min;
    u8 n;
    u8 dir;

    start = arg1;
    while (M2C_FIELD(arg0, s16 **, 0x14190)[arg2 + (arg3 << 6)] != 0) {
        if (M2C_FIELD(arg0, u8 *, 0x24EEA) != 0) {
            if (((u16 *)((u8 *)arg0 + 0x408E))[(s8)(arg2 + 1) + (arg3 << 6)] & 0x10) {
                dist[0] = 0xFFFF;
            } else {
                dist[0] = M2C_FIELD(arg0, s16 **, 0x14190)[(s8)(arg2 + 1) + (arg3 << 6)];
            }
            if (((u16 *)((u8 *)arg0 + 0x408E))[(s8)(arg2 - 1) + (arg3 << 6)] & 0x20) {
                dist[1] = 0xFFFF;
            } else {
                dist[1] = M2C_FIELD(arg0, s16 **, 0x14190)[(s8)(arg2 - 1) + (arg3 << 6)];
            }
            if (((u16 *)((u8 *)arg0 + 0x408E))[arg2 + ((s8)(arg3 + 1) << 6)] & 0x80) {
                dist[3] = 0xFFFF;
            } else {
                dist[3] = M2C_FIELD(arg0, s16 **, 0x14190)[arg2 + ((s8)(arg3 + 1) << 6)];
            }
            if (((u16 *)((u8 *)arg0 + 0x408E))[arg2 + ((s8)(arg3 - 1) << 6)] & 0x40) {
                dist[2] = 0xFFFF;
            } else {
                dist[2] = M2C_FIELD(arg0, s16 **, 0x14190)[arg2 + ((s8)(arg3 - 1) << 6)];
            }
        } else {
            if (((u16 *)((u8 *)arg0 + 0x408E))[(s8)(arg2 + 1) + (arg3 << 6)] & 0x1) {
                dist[0] = M2C_FIELD(arg0, s16 **, 0x14190)[(s8)(arg2 + 1) + (arg3 << 6)];
            } else {
                dist[0] = 0xFFFF;
            }
            if (((u16 *)((u8 *)arg0 + 0x408E))[(s8)(arg2 - 1) + (arg3 << 6)] & 0x2) {
                dist[1] = M2C_FIELD(arg0, s16 **, 0x14190)[(s8)(arg2 - 1) + (arg3 << 6)];
            } else {
                dist[1] = 0xFFFF;
            }
            if (((u16 *)((u8 *)arg0 + 0x408E))[arg2 + ((s8)(arg3 + 1) << 6)] & 0x8) {
                dist[3] = M2C_FIELD(arg0, s16 **, 0x14190)[arg2 + ((s8)(arg3 + 1) << 6)];
            } else {
                dist[3] = 0xFFFF;
            }
            if (((u16 *)((u8 *)arg0 + 0x408E))[arg2 + ((s8)(arg3 - 1) << 6)] & 0x4) {
                dist[2] = M2C_FIELD(arg0, s16 **, 0x14190)[arg2 + ((s8)(arg3 - 1) << 6)];
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
        *arg1++ = dir;
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
        *dst++ = *--src;
    }
    *dst = 0x10;
    src = buf;
    while (*src != 0x10) {
        *out++ = *src++;
    }
    *out = 0x10;
    return start;
}

void Map_FillAttackRange(void *arg0, s8 arg1, s8 arg2, u8 arg3, u8 arg4)
{
    void Map_FillLayer(void *, s32, s32);
    s8 x;
    void *self;
    s8 y;

    x = arg1;
    self = arg0;
    y = arg2;

    ((u8 *)self + 0x20000)[0x4EE0] = 0;
    *(u16 *)((u8 *)self + 0x24EE2) = arg4;
    *(void **)((u8 *)self + 0x24ED8) = (u8 *)self + 0x242D8;
    *(void **)((u8 *)self + 0x24EDC) = (u8 *)self + 0x248D8;
    ((u8 *)self + 0x20000)[0x4EE9] = arg3;

    (*(u8 **)((u8 *)self + 0x24EDC))[0] = (u8)x;
    (*(u8 **)((u8 *)self + 0x24EDC))[1] = (u8)y;
    (*(u8 **)((u8 *)self + 0x24EDC))[2] = 0x20;
    *(u16 *)(*(u8 **)((u8 *)self + 0x24EDC) + 4) = 0;
    *(u8 **)((u8 *)self + 0x24EDC) = *(u8 **)((u8 *)self + 0x24EDC) + 6;
    (*(u8 **)((u8 *)self + 0x24EDC))[2] = 0x10;

    Map_FillLayer(self, 0xB, -1);

    (*(s16 **)((u8 *)self + 0x14190))[(s8)x + ((s8)y << 6)] = 0;

    for (;;) {
        u8 slot;
        u8 *ed8;
        u8 *edc;

        slot = ((u8 *)self + 0x20000)[0x4EE0];
        *(void **)((u8 *)self + 0x24EDC) = (u8 *)self + slot * 0x600 + 0x242D8;
        ((u8 *)self + 0x20000)[0x4EE0] = (u8)(slot ^ 1);
        slot = ((u8 *)self + 0x20000)[0x4EE0];
        *(void **)((u8 *)self + 0x24ED8) = (u8 *)self + slot * 0x600 + 0x242D8;
        ((u8 *)self + 0x20000)[0x4EE1] = 0;

        ed8 = *(u8 **)((u8 *)self + 0x24ED8);
        if (ed8[2] == 0x10) {
            break;
        }

        do {
            switch (ed8[2]) {
            case 0x20:
            case 0x8:
            case 0x4:
            case 0x1:
            case 0x2:
                break;
            }
            edc = *(u8 **)((u8 *)self + 0x24EDC);
            edc[2] = 0x10;
            ed8 += 6;
            *(u8 **)((u8 *)self + 0x24ED8) = ed8;
        } while (ed8[2] != 0x10);
    }
}

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
    u8 *ed8;
    u8 *edc;
    u8 slot;
    s16 *costs;
    u8 nx;
    u8 ny;
    u8 kind;
    u16 flags;
    u16 neu;
    u16 oldc;
    u16 have;
    u8 *cell;
    u8 tid;
    u8 uid;
    u8 *unit;
    u8 *cls;

    ((u8 *)map + 0x20000)[0x4EE0] = 0;
    *(u16 *)((u8 *)map + 0x24EE2) = range;
    *(void **)((u8 *)map + 0x24ED8) = (u8 *)map + 0x242D8;
    *(void **)((u8 *)map + 0x24EDC) = (u8 *)map + 0x248D8;

    edc = *(u8 **)((u8 *)map + 0x24EDC);
    edc[0] = x;
    edc = *(u8 **)((u8 *)map + 0x24EDC);
    edc[1] = y;
    edc = *(u8 **)((u8 *)map + 0x24EDC);
    edc[2] = 0x20;
    edc = *(u8 **)((u8 *)map + 0x24EDC);
    *(u16 *)(edc + 4) = 0;
    edc = *(u8 **)((u8 *)map + 0x24EDC);
    *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
    edc = *(u8 **)((u8 *)map + 0x24EDC);
    edc[2] = 0x10;

    Map_FillLayer(map, 0xB, -1);

    ((u8 *)map)[0xC] = 0;
    costs = *(s16 **)((u8 *)map + 0x14190);
    costs[(s8)x + ((s8)y << 6)] = 0;

    if ((u8)flagB == 0 || (u8)flagA == 0) {
        ((u8 *)map + 0x20000)[0x4EE8] = 0;
        if ((u8)flagB != 0) {
            ((u8 *)map + 0x20000)[0x4EE8] |= 1;
        }
        if ((u8)flagA != 0) {
            ((u8 *)map + 0x20000)[0x4EE8] |= 2;
        }
    }

    for (;;) {
        slot = ((u8 *)map + 0x20000)[0x4EE0];
        *(void **)((u8 *)map + 0x24EDC) = (u8 *)map + slot * 0x600 + 0x242D8;
        ((u8 *)map + 0x20000)[0x4EE0] = (u8)(slot ^ 1);
        slot = ((u8 *)map + 0x20000)[0x4EE0];
        *(void **)((u8 *)map + 0x24ED8) = (u8 *)map + slot * 0x600 + 0x242D8;
        ((u8 *)map + 0x20000)[0x4EE1] = 0;

        ed8 = *(u8 **)((u8 *)map + 0x24ED8);
        if (ed8[2] == 0x10) {
            break;
        }

        do {
            ny = ed8[1];
            nx = ed8[0];
            kind = ed8[2];
            flags = *(u16 *)((u8 *)map + 0x1408E + (((s8)nx + ((s8)ny << 6)) << 1));
            if (((u8 *)map + 0x20000)[0x4EEA] != 0) {
                flags = (u16)(((flags ^ 0xF0) >> 4) & 0xFFF);
            }

            costs = *(s16 **)((u8 *)map + 0x14190);
            oldc = (u16)costs[(s8)nx + ((s8)ny << 6)];

            switch (kind) {
            case 0x20:
                if (flags & 0x8) {
                    cell = (u8 *)map + (s8)nx + (((s8)ny - 1) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c20_s;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)ny - 1) << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = nx;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = (u8)(ny - 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x8;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[(s8)nx + (((s8)ny - 1) << 6)] = (s16)neu;
                    }
                }
            c20_s:
                if (flags & 0x4) {
                    ny = (*(u8 **)((u8 *)map + 0x24ED8))[1];
                    nx = (*(u8 **)((u8 *)map + 0x24ED8))[0];
                    costs = *(s16 **)((u8 *)map + 0x14190);
                    oldc = (u16)costs[(s8)nx + ((s8)ny << 6)];
                    cell = (u8 *)map + (s8)nx + (((s8)ny + 1) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c20_w;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)ny + 1) << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = nx;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = (u8)(ny + 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x4;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[(s8)nx + (((s8)ny + 1) << 6)] = (s16)neu;
                    }
                }
            c20_w:
                if (flags & 0x1) {
                    ny = (*(u8 **)((u8 *)map + 0x24ED8))[1];
                    nx = (*(u8 **)((u8 *)map + 0x24ED8))[0];
                    costs = *(s16 **)((u8 *)map + 0x14190);
                    oldc = (u16)costs[(s8)nx + ((s8)ny << 6)];
                    cell = (u8 *)map + ((s8)nx - 1) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c20_e;
                        }
                    }
                    have = (u16)costs[((s8)nx - 1) + ((s8)ny << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = (u8)(nx - 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = ny;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x1;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[((s8)nx - 1) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
            c20_e:
                if (flags & 0x2) {
                    ny = (*(u8 **)((u8 *)map + 0x24ED8))[1];
                    nx = (*(u8 **)((u8 *)map + 0x24ED8))[0];
                    costs = *(s16 **)((u8 *)map + 0x14190);
                    oldc = (u16)costs[(s8)nx + ((s8)ny << 6)];
                    cell = (u8 *)map + ((s8)nx + 1) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            break;
                        }
                    }
                    have = (u16)costs[((s8)nx + 1) + ((s8)ny << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = (u8)(nx + 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = ny;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x2;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[((s8)nx + 1) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
                break;
            case 0x8:
                if (flags & 0x8) {
                    cell = (u8 *)map + (s8)nx + (((s8)ny - 1) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c8_w;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)ny - 1) << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = nx;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = (u8)(ny - 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x8;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[(s8)nx + (((s8)ny - 1) << 6)] = (s16)neu;
                    }
                }
            c8_w:
                if (flags & 0x1) {
                    ny = (*(u8 **)((u8 *)map + 0x24ED8))[1];
                    nx = (*(u8 **)((u8 *)map + 0x24ED8))[0];
                    costs = *(s16 **)((u8 *)map + 0x14190);
                    oldc = (u16)costs[(s8)nx + ((s8)ny << 6)];
                    cell = (u8 *)map + ((s8)nx - 1) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c8_e;
                        }
                    }
                    have = (u16)costs[((s8)nx - 1) + ((s8)ny << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = (u8)(nx - 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = ny;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x1;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[((s8)nx - 1) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
            c8_e:
                if (flags & 0x2) {
                    ny = (*(u8 **)((u8 *)map + 0x24ED8))[1];
                    nx = (*(u8 **)((u8 *)map + 0x24ED8))[0];
                    costs = *(s16 **)((u8 *)map + 0x14190);
                    oldc = (u16)costs[(s8)nx + ((s8)ny << 6)];
                    cell = (u8 *)map + ((s8)nx + 1) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            break;
                        }
                    }
                    have = (u16)costs[((s8)nx + 1) + ((s8)ny << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = (u8)(nx + 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = ny;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x2;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[((s8)nx + 1) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
                break;
            case 0x4:
                if (flags & 0x4) {
                    cell = (u8 *)map + (s8)nx + (((s8)ny + 1) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c4_w;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)ny + 1) << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = nx;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = (u8)(ny + 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x4;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[(s8)nx + (((s8)ny + 1) << 6)] = (s16)neu;
                    }
                }
            c4_w:
                if (flags & 0x1) {
                    ny = (*(u8 **)((u8 *)map + 0x24ED8))[1];
                    nx = (*(u8 **)((u8 *)map + 0x24ED8))[0];
                    costs = *(s16 **)((u8 *)map + 0x14190);
                    oldc = (u16)costs[(s8)nx + ((s8)ny << 6)];
                    cell = (u8 *)map + ((s8)nx - 1) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c4_e;
                        }
                    }
                    have = (u16)costs[((s8)nx - 1) + ((s8)ny << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = (u8)(nx - 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = ny;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x1;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[((s8)nx - 1) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
            c4_e:
                if (flags & 0x2) {
                    ny = (*(u8 **)((u8 *)map + 0x24ED8))[1];
                    nx = (*(u8 **)((u8 *)map + 0x24ED8))[0];
                    costs = *(s16 **)((u8 *)map + 0x14190);
                    oldc = (u16)costs[(s8)nx + ((s8)ny << 6)];
                    cell = (u8 *)map + ((s8)nx + 1) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            break;
                        }
                    }
                    have = (u16)costs[((s8)nx + 1) + ((s8)ny << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = (u8)(nx + 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = ny;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x2;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[((s8)nx + 1) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
                break;
            case 0x1:
                if (flags & 0x8) {
                    cell = (u8 *)map + (s8)nx + (((s8)ny - 1) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c1_s;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)ny - 1) << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = nx;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = (u8)(ny - 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x8;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[(s8)nx + (((s8)ny - 1) << 6)] = (s16)neu;
                    }
                }
            c1_s:
                if (flags & 0x4) {
                    ny = (*(u8 **)((u8 *)map + 0x24ED8))[1];
                    nx = (*(u8 **)((u8 *)map + 0x24ED8))[0];
                    costs = *(s16 **)((u8 *)map + 0x14190);
                    oldc = (u16)costs[(s8)nx + ((s8)ny << 6)];
                    cell = (u8 *)map + (s8)nx + (((s8)ny + 1) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c1_w;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)ny + 1) << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = nx;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = (u8)(ny + 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x4;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[(s8)nx + (((s8)ny + 1) << 6)] = (s16)neu;
                    }
                }
            c1_w:
                if (flags & 0x1) {
                    ny = (*(u8 **)((u8 *)map + 0x24ED8))[1];
                    nx = (*(u8 **)((u8 *)map + 0x24ED8))[0];
                    costs = *(s16 **)((u8 *)map + 0x14190);
                    oldc = (u16)costs[(s8)nx + ((s8)ny << 6)];
                    cell = (u8 *)map + ((s8)nx - 1) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            break;
                        }
                    }
                    have = (u16)costs[((s8)nx - 1) + ((s8)ny << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = (u8)(nx - 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = ny;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x1;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[((s8)nx - 1) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
                break;
            case 0x2:
                if (flags & 0x8) {
                    cell = (u8 *)map + (s8)nx + (((s8)ny - 1) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c2_s;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)ny - 1) << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = nx;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = (u8)(ny - 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x8;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[(s8)nx + (((s8)ny - 1) << 6)] = (s16)neu;
                    }
                }
            c2_s:
                if (flags & 0x4) {
                    ny = (*(u8 **)((u8 *)map + 0x24ED8))[1];
                    nx = (*(u8 **)((u8 *)map + 0x24ED8))[0];
                    costs = *(s16 **)((u8 *)map + 0x14190);
                    oldc = (u16)costs[(s8)nx + ((s8)ny << 6)];
                    cell = (u8 *)map + (s8)nx + (((s8)ny + 1) << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            goto c2_e;
                        }
                    }
                    have = (u16)costs[(s8)nx + (((s8)ny + 1) << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = nx;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = (u8)(ny + 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x4;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[(s8)nx + (((s8)ny + 1) << 6)] = (s16)neu;
                    }
                }
            c2_e:
                if (flags & 0x2) {
                    ny = (*(u8 **)((u8 *)map + 0x24ED8))[1];
                    nx = (*(u8 **)((u8 *)map + 0x24ED8))[0];
                    costs = *(s16 **)((u8 *)map + 0x14190);
                    oldc = (u16)costs[(s8)nx + ((s8)ny << 6)];
                    cell = (u8 *)map + ((s8)nx + 1) + ((s8)ny << 6);
                    tid = cell[0x100D];
                    uid = cell[0xD];
                    neu = (u16)(oldc + *(u16 *)((u8 *)map + 0x14214 + (tid << 1)));
                    if (uid != 0) {
                        unit = (uid != 0) ? gUnits + (uid - 1) * 0x280 : NULL;
                        cls = *(u8 **)(unit + 0x190);
                        if (((u8 *)map + 0x20000)[0x4EE4 + cls[8]] != 0) {
                            break;
                        }
                    }
                    have = (u16)costs[((s8)nx + 1) + ((s8)ny << 6)];
                    if (neu < have && neu <= *(u16 *)((u8 *)map + 0x24EE2)) {
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[0] = (u8)(nx + 1);
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[1] = ny;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        edc[2] = 0x2;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u16 *)(edc + 4) = neu;
                        edc = *(u8 **)((u8 *)map + 0x24EDC);
                        *(u8 **)((u8 *)map + 0x24EDC) = edc + 6;
                        ((u8 *)map + 0x20000)[0x4EE1]++;
                        costs = *(s16 **)((u8 *)map + 0x14190);
                        costs[((s8)nx + 1) + ((s8)ny << 6)] = (s16)neu;
                    }
                }
                break;
            }

            edc = *(u8 **)((u8 *)map + 0x24EDC);
            edc[2] = 0x10;
            ed8 += 6;
            *(u8 **)((u8 *)map + 0x24ED8) = ed8;
        } while (ed8[2] != 0x10);
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
void fn_800227F8(void *arg0,void *arg1) {
struct Map { u8 pad[0x14214]; s16 costs[77]; };
struct Terrain { u32 unk0,unk4; s8 *data; };
struct Terrain *Terrain_GetEntry(s32);
u8 Status_Test(void *,s32);
struct Map *map=arg0;
u8 *unit=arg1;
struct Terrain *terrain;
s32 i;
terrain=Terrain_GetEntry(0);
if(unit==0){
for(i=1;i<77;i++) map->costs[i]=1;
map->costs[0]=0x7FFF;
((u8 *)map)[0x24EEA]=1;
} else {
for(i=0;i<77;i++,terrain++){
s32 cost=0x7FFF;
if(terrain->data[unit[0x42]+8]>=0) cost=terrain->data[unit[0x42]+8];
map->costs[i]=cost;
}
((u8 *)map)[0x24EEA]=Status_Test(unit+0x1C,4)!=0;
}
}

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
    s32 nadx;
    s32 ax;
    s32 ady;
    u8 *row;
    u8 *cursor;
    u8 f;
    s32 saved;
    u8 t;

#pragma optimization_level 1
    f = 1;
    self = arg0;
    t = (u8)(gMapBlendMode - 1);
    if (((u32)((f | ~t) - ((u32)(f - t) >> 1)) >> 31) == 0) {
        f = 0;
    }
    saved = (f != 0);
#pragma optimization_level reset
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
                nadx = -adx;
                for (x = 0; x < *(s32 *)self; x++) {
                    ax = adx;
                    if (adx < 0) {
                        ax = nadx;
                    }
                    ady = x - ux;
                    if (ady < 0) {
                        ady = -ady;
                    }
                    if (ax + ady <= rad) {
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
            s32 idx;
            if ((u8)i != 0) {
                unit = gUnits + ((u8)i - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (*(u32 *)(unit + 0x188) != 0
                && buf2[*(u8 *)(*(u8 **)(unit + 0x190) + 8)] != 0
                && (*(u32 *)(unit + 0x1A0) & 0x0100009C) == 0) {
                idx = (*(s8 *)(unit + 0x19E)) + ((*(s8 *)(unit + 0x19F)) << 6);
                if (*((u8 *)self + (idx + 0x200D)) != 0) {
                    *((u8 *)self + (idx + 0xD)) = unit[0x198];
                    {
                        u32 fr = *(u32 *)(unit + 0x1A0);
                        if (fr & 0x40) {
                            *(u32 *)(unit + 0x1A0) = fr & ~0x40;
                            *(u32 *)(unit + 0x1A0) = *(u32 *)(unit + 0x1A0) | 0x200;
                        }
                    }
                } else {
                    *((u8 *)self + (idx + 0x300D)) |= 1;
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
            s32 idx;
            if ((u8)i != 0) {
                unit = gUnits + ((u8)i - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (*(u32 *)(unit + 0x188) != 0
                && buf3[*(u8 *)(*(u8 **)(unit + 0x190) + 8)] != 0
                && (*(u32 *)(unit + 0x1A0) & 4) == 0) {
                idx = (*(s8 *)(unit + 0x19E)) + ((*(s8 *)(unit + 0x19F)) << 6);
                if (*((u8 *)self + (idx + 0x200D)) != 0) {
                    *(u32 *)(unit + 0x1A0) &= ~0x40;
                } else {
                    *(u32 *)(unit + 0x1A0) |= 0x40;
                }
                *((u8 *)self + ((*(s8 *)(unit + 0x19E)) + ((*(s8 *)(unit + 0x19F)) << 6) + 0xD)) =
                    unit[0x198];
            }
        }
    }
    fn_8010FAA8();
    fn_8001F140(self);
}

extern u16 jumptable_80284514[12];

static u32 Map_SplatByte(u32 arg0)
{
    u32 t;
    u32 value;
    u32 lo;
    u32 hi;

    t = (arg0 & 0xFF) << 8;
    value = (arg0 & 0xFF) << 16;
    value = value + t;
    lo = arg0 & 0xFF;
    hi = arg0 << 24;
    lo = value + lo;
    return hi + lo;
}

void Map_FillLayer(void *arg0, u32 arg1, u32 arg2)
{
    void fn_800062B0(u32 *, u32, u32);
    u32 fn_80022FB0(u32);

    u8 *map = (u8 *)arg0;
    u32 t;
    u32 value;
    u32 *buffer;

    switch (arg1) {
    case 0:
        t = (arg2 & 0xFF) << 8;
        value = (arg2 & 0xFF) << 16;
        value = value + t;
        value = value + (arg2 & 0xFF);
        value = (arg2 << 24) + value;
        fn_800062B0((u32 *)(map + 0xD), value, 0x1000);
        break;
    case 1:
        t = (arg2 & 0xFF) << 8;
        value = (arg2 & 0xFF) << 16;
        value = value + t;
        value = value + (arg2 & 0xFF);
        value = (arg2 << 24) + value;
        fn_800062B0((u32 *)(map + 0x100D), value, 0x1000);
        break;
    case 2:
        t = (arg2 & 0xFF) << 8;
        value = (arg2 & 0xFF) << 16;
        value = value + t;
        value = value + (arg2 & 0xFF);
        value = (arg2 << 24) + value;
        fn_800062B0((u32 *)(map + 0x200D), value, 0x1000);
        break;
    case 3:
        t = (arg2 & 0xFF) << 8;
        value = (arg2 & 0xFF) << 16;
        value = value + t;
        value = value + (arg2 & 0xFF);
        value = (arg2 << 24) + value;
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
