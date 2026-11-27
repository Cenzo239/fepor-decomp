/* Functions from 0x80006264 to 0x80011968, found by decomp-toolkit. */
#include "common.h"
#include "process.h"

static inline u32 Process_CompareName(const s8 *a, const s8 *b)
{
    while (*a | *b) {
        if (*a != *b) return *a - *b;
        a++;
        b++;
    }
    return 0;
}

static inline u32 Process_CompareNameExt(const u8 *a, const u8 *b)
{
    u32 raw1;
    u32 raw2;
    s32 c1;
    s32 c2;
    goto ld;
cmp:
    if ((s8)raw1 != (s8)raw2)
        return (u32)(c1 - c2);
    a++;
    b++;
ld:
    raw1 = *a;
    raw2 = *b;
    c1 = (s8)raw1;
    c2 = (s8)raw2;
    if ((c1 | c2) != 0)
        goto cmp;
    return 0;
}

static inline void *Process_FindName(const s8 *source)
{
    extern u8 gProcesses[];
    u8 *entry = gProcesses;
    s32 i;
    for (i = 0; i < 256; i++, entry += 0x70) {
        if (*(u32 *)entry != 0 && Process_CompareName(*(s8 **)(entry + 0x14), source) == 0) return entry;
    }
    return 0;
}

typedef struct {
    void *unk0;
    void *unk4;
    s32 unk8;
} Struct_8000B090;

extern s32 lbl_802AEE20[5]; // array of 5 pointers
extern f64 lbl_80368C28;    // global float constant
extern u16 jumptable_80283AE8[];

#pragma optimization_level 2

#pragma optimization_level reset

#pragma opt_unroll off

#pragma global_optimizer reset

#pragma global_optimizer on
#pragma opt_strength_reduction on

#pragma optimization_level 4
#pragma scheduling on

#pragma scheduling reset
#pragma optimization_level reset

#pragma optimization_level 3

#pragma optimization_level reset

asm s32 fn_80006AF4(s32 *arg0) {
    nofralloc
    subi r3, r3, 4
    li r4, 0x1c
    li r11, 0
    mtctr r4
@loop:
    lwzu r12, 4(r3)
    add r11, r11, r12
    bdnz @loop
    addi r3, r11, 0
    blr
}
#pragma opt_unroll reset
void fn_80006B18(s32 arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4)
{
    extern void *gPrim2D;
    s32 Text_MeasureWidth(u8 *, s32, f32);
    extern f64 lbl_80368B88;

    u8 buffer[16];
    u8 *digits;
    u8 *write;
    u8 *read;
    u8 *prim;
    u8 *text;
    u8 *font;
    s32 sign;
    s32 count;
    s32 i;
    s32 width;
    s32 x;
    s32 size;
    u8 tmp;
    union {
        f64 value;
        struct { u32 hi; u32 lo; } bits;
    } fx, fy;

    sign = 0;
    count = 0;

    if (arg3 != 0) {
        if (arg4 < 0) {
            buffer[0] = '-';
            arg4 *= -1;
        } else {
            buffer[0] = '+';
        }
        sign = 1;
    } else if (arg4 < 0) {
        buffer[0] = '-';
        buffer[1] = '-';
        buffer[2] = 0;
        goto formatted;
    }

    digits = buffer + sign;
    write = digits;
    do {
        *write++ = (u8)('0' + arg4 % 10);
        arg4 /= 10;
        count++;
    } while (arg4 != 0);

    for (i = 0; i < count / 2; ++i) {
        tmp = digits[i];
        digits[i] = buffer[sign + count - 1 - i];
        buffer[sign + count - 1 - i] = tmp;
    }
    digits[count] = 0;

formatted:
    prim = (u8 *)gPrim2D;
    text = *(u8 **)(prim + 0xC);
    font = *(u8 **)(text + 4);
    width = Text_MeasureWidth(buffer, -1, *(f32 *)(font + 0x1C));

    x = arg0;
    if (arg2 == 0) {
        x -= width;
    } else if (arg2 == 2) {
        x -= (width + ((u32)width >> 31)) >> 1;
    }

    prim = (u8 *)gPrim2D;
    text = *(u8 **)(prim + 0xC);
    font = *(u8 **)(text + 4);
    fx.bits.hi = 0x43300000;
    fx.bits.lo = (u32)x ^ 0x80000000U;
    fy.bits.hi = 0x43300000;
    fy.bits.lo = (u32)arg1 ^ 0x80000000U;
    *(f32 *)(font + 0x10) = (f32)(fx.value - lbl_80368B88);
    *(f32 *)(font + 0x14) = (f32)(fy.value - lbl_80368B88);

    read = buffer;
    size = 1;
    while (*read++ != 0) {
        ++size;
    }
    size = (size + 3) & 0xFC;
    if (size > 0xD4) {
        size = 0xD4;
    }

    prim = (u8 *)gPrim2D;
    text = *(u8 **)(prim + 0xC);
    font = *(u8 **)(text + 4);
    write = *(u8 **)(prim + 8);
    *(u8 **)(prim + 8) = write + size;
    read = buffer;
    while (*read != 0) {
        *write++ = *read++;
    }
    *write = 0;

    font[5] += (u8)size;
    font[0x18] = font[0xC];
    font[0x19] = font[0xD];
    font[0x1A] = font[0xE];
    font[0x1B] = font[0xF];
}

#pragma global_optimizer off
#pragma use_lmw_stmw on
void fn_80006E8C(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
f32 y, yend, v, uend, vend, x, xend, u;
f32 a,c,b,z;
f32 d,f,e,delta,limit;
u8 red=arg1, green=arg2, blue=arg3, alpha=arg4;
a=*(f32*)((u8*)arg0+0x2C);
b=*(f32*)((u8*)arg0+0x1C);
c=*(f32*)((u8*)arg0+0x34);
vend=a;
y=*(f32*)((u8*)arg0+0x14);
v=b+c;
yend=(y+(a-b))-c;
for (;;) {
limit=*(f32*)((u8*)arg0+0x24);
if(yend>limit) {
delta=yend-limit;
yend=limit;
vend-=delta;
}
d=*(f32*)((u8*)arg0+0x28);
e=*(f32*)((u8*)arg0+0x18);
f=*(f32*)((u8*)arg0+0x30);
uend=d;
x=*(f32*)((u8*)arg0+0x10);
u=e+f;
xend=(x+(d-e))-f;
for (;;) {
c=*(f32*)((u8*)arg0+0x20);
if(xend>c) {
a=xend-c;
xend=c;
uend-=a;
}
GXBegin(0x98,0,4);
z=*(f32*)((u8*)arg0+8);
*(volatile f32*)0xCC008000=x;
*(volatile f32*)0xCC008000=y;
*(volatile f32*)0xCC008000=z;
*(volatile u8*)0xCC008000=red;
*(volatile u8*)0xCC008000=green;
*(volatile u8*)0xCC008000=blue;
*(volatile u8*)0xCC008000=alpha;
*(volatile f32*)0xCC008000=u;
*(volatile f32*)0xCC008000=v;
z=*(f32*)((u8*)arg0+8);
*(volatile f32*)0xCC008000=xend;
*(volatile f32*)0xCC008000=y;
*(volatile f32*)0xCC008000=z;
*(volatile u8*)0xCC008000=red;
*(volatile u8*)0xCC008000=green;
*(volatile u8*)0xCC008000=blue;
*(volatile u8*)0xCC008000=alpha;
*(volatile f32*)0xCC008000=uend;
*(volatile f32*)0xCC008000=v;
z=*(f32*)((u8*)arg0+8);
*(volatile f32*)0xCC008000=x;
*(volatile f32*)0xCC008000=yend;
*(volatile f32*)0xCC008000=z;
*(volatile u8*)0xCC008000=red;
*(volatile u8*)0xCC008000=green;
*(volatile u8*)0xCC008000=blue;
*(volatile u8*)0xCC008000=alpha;
*(volatile f32*)0xCC008000=u;
*(volatile f32*)0xCC008000=vend;
z=*(f32*)((u8*)arg0+8);
*(volatile f32*)0xCC008000=xend;
*(volatile f32*)0xCC008000=yend;
*(volatile f32*)0xCC008000=z;
*(volatile u8*)0xCC008000=red;
*(volatile u8*)0xCC008000=green;
*(volatile u8*)0xCC008000=blue;
*(volatile u8*)0xCC008000=alpha;
*(volatile f32*)0xCC008000=uend;
*(volatile f32*)0xCC008000=vend;
if(xend>=*(f32*)((u8*)arg0+0x20)) break;
c=*(f32*)((u8*)arg0+0x18);
x=xend;u=c;xend+=*(f32*)((u8*)arg0+0x28)-c;
}
if(yend>=*(f32*)((u8*)arg0+0x24)) break;
c=*(f32*)((u8*)arg0+0x1C);
y=yend;v=c;yend+=*(f32*)((u8*)arg0+0x2C)-c;
}
}
#pragma use_lmw_stmw reset
#pragma global_optimizer reset
extern f64 lbl_80368C28;
void fn_800070C8(s32 *arg0, s16 *arg1, s16 *arg2, s32 *arg3) {
    extern void *gPrim2D;

    if (arg0 != NULL) {
        *arg0 = *(s32 *)((u8 *)gPrim2D + 0xA4);
    }
    if (arg1 != NULL) {
        *arg1 = *(s16 *)((u8 *)gPrim2D + 0x92);
    }
    if (arg2 != NULL) {
        *arg2 = *(s16 *)((u8 *)gPrim2D + 0x90);
    }
    if (arg3 != NULL) {
        *arg3 = *(s32 *)((u8 *)gPrim2D + 8) - *(s32 *)gPrim2D;
    }
}

void Prim2D_SetText(u8 *arg0) {
    extern void *gPrim2D;
    extern u8 lbl_80366DA4;
    u8 *g;
    u32 n;
    u8 *out;
    u8 *dst;
    s8 *s;
    u32 len;
    u8 *mid;

    g = (u8 *)gPrim2D;
    n = 1;
    mid = *(u8 **)(g + 0xC);
    dst = *(u8 **)(mid + 4);
    s = (s8 *)arg0;
    if (s == NULL) {
        s = (s8 *)&lbl_80366DA4;
    }
    while (*s++) {
        n++;
    }
    s -= n;
    len = (n + 3) & 0xFC;
    if (len > 0xD4) {
        len = 0xD4;
    }
    out = *(u8 **)(g + 8);
    *(u8 **)(g + 8) = out + len;
    while (*s) {
        *out++ = (u8)*s++;
    }
    *out = 0;
    dst[5] += (u8)len;
    dst[0x18] = dst[0xC];
    dst[0x19] = dst[0xD];
    dst[0x1A] = dst[0xE];
    dst[0x1B] = dst[0xF];
}

void fn_800071D8(u32 arg0, f32 arg1)
{
    extern void *gPrim2D;
    s16 value = (s16)(256.0f * arg1);
    u8 disabled = (u8)arg0 == 0;
    u8 *object = *(u8 **)((u8 *)gPrim2D + 12);
    object = *(u8 **)(object + 4);
    *(s16 *)(object + 0x26) = disabled ? 0 : value;
}

void Prim2D_SetTextScale(u32 arg0, f32 arg1)
{
    extern void *gPrim2D;
    s16 value = (s16)(256.0f * arg1);
    u8 disabled = (u8)arg0 == 0;
    u8 *object = *(u8 **)((u8 *)gPrim2D + 12);
    object = *(u8 **)(object + 4);
    *(s16 *)(object + 0x24) = disabled ? 0 : value;
}

void fn_80007268(f32 arg0) {
    extern void *gPrim2D;

    u8 *ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);
    *(f32 *)(ptr + 0x20) = arg0;
}

void Prim2D_SetScale(f32 arg0) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);
    *(f32 *)(ptr + 0x1C) = arg0;
}

void Prim2D_SetTint(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
 extern void *gPrim2D;
 u8 *ptr = (u8 *)gPrim2D;
 ptr = *(u8 **)(ptr + 0xC);
 ptr = *(u8 **)(ptr + 4);
 ptr[0x18] = arg0;
 ptr[0x19] = arg1;
 ptr[0x1A] = arg2;
 ptr[0x1B] = arg3;
}

#pragma push
#pragma opt_common_subs off
void Prim2D_SetCornerColors(u8 *a, u8 *b, u8 *c, u8 *d) {
    extern void *gPrim2D;
    u8 *ptr;
    u8 t0, t2, t1, t3;

    t0 = a[0];
    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    t1 = a[1];
    ptr = *(u8 **)(ptr + 4);
    t2 = a[2];
    ptr[0xC] = t0;
    t3 = a[3];
    ptr[0xD] = t1;
    t0 = b[0];
    ptr[0xE] = t2;
    t1 = b[1];
    ptr[0xF] = t3;
    t2 = b[2];
    ptr[0x50] = t0;
    t3 = b[3];
    ptr[0x51] = t1;
    t0 = c[0];
    ptr[0x52] = t2;
    t1 = c[1];
    ptr[0x53] = t3;
    t2 = c[2];
    ptr[0x54] = t0;
    t3 = c[3];
    ptr[0x55] = t1;
    t0 = d[0];
    ptr[0x56] = t2;
    t1 = d[1];
    ptr[0x57] = t3;
    t2 = d[2];
    ptr[0x58] = t0;
    t3 = d[3];
    ptr[0x59] = t1;
    ptr[0x5A] = t2;
    ptr[0x5B] = t3;
}
#pragma pop
void fn_80007340(s32 arg0, s32 arg1) {
    extern void *gPrim2D;

    u8 *ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(s32 *)(ptr + 0x10) = arg0;
    *(s32 *)(ptr + 0x14) = arg1;
}

void fn_80007358(f32 arg0, f32 arg1) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x30) = arg0;
    *(f32 *)(ptr + 0x34) = arg1;
}

void fn_80007370(float arg0, float arg1, float arg2)
{
    extern void *gPrim2D;
    extern float lbl_80368B98;
    extern float lbl_80368B9C;

    float matrix1[12];
    float matrix2[12];
    float x, z;
    float scale;
    void *object;

    object = *(void **)((u8 *)gPrim2D + 0xC);
    object = *(void **)((u8 *)object + 4);

    PSMTXTrans(matrix1, -arg0, -arg1, lbl_80368B98);

    scale = lbl_80368B9C * arg2;
    PSMTXRotRad(matrix2, 0x5A, scale);

    PSMTXConcat(matrix2, matrix1, matrix2);

    PSMTXTrans(matrix1, arg0, arg1, lbl_80368B98);

    PSMTXConcat(matrix1, matrix2, matrix2);

    x = *(float *)((u8 *)object + 0x10);
    z = *(float *)((u8 *)object + 0x14);
    *(float *)((u8 *)object + 0x10) = matrix2[3] + (matrix2[0] * x + matrix2[1] * z);
    *(float *)((u8 *)object + 0x14) = matrix2[7] + (matrix2[4] * x + matrix2[5] * z);

    x = *(float *)((u8 *)object + 0x30);
    z = *(float *)((u8 *)object + 0x34);
    *(float *)((u8 *)object + 0x30) = matrix2[3] + (matrix2[0] * x + matrix2[1] * z);
    *(float *)((u8 *)object + 0x34) = matrix2[7] + (matrix2[4] * x + matrix2[5] * z);

    x = *(float *)((u8 *)object + 0x40);
    z = *(float *)((u8 *)object + 0x44);
    *(float *)((u8 *)object + 0x40) = matrix2[3] + (matrix2[0] * x + matrix2[1] * z);
    *(float *)((u8 *)object + 0x44) = matrix2[7] + (matrix2[4] * x + matrix2[5] * z);

    x = *(float *)((u8 *)object + 0x20);
    z = *(float *)((u8 *)object + 0x24);
    *(float *)((u8 *)object + 0x20) = matrix2[3] + (matrix2[0] * x + matrix2[1] * z);
    *(float *)((u8 *)object + 0x24) = matrix2[7] + (matrix2[4] * x + matrix2[5] * z);
}

void Prim2D_RotateUvCw(void)
{
    extern void *gPrim2D;

    void *object;
    f32 x;
    f32 y;

    object = *(void **)((u8 *)gPrim2D + 0xC);
    object = *(void **)((u8 *)object + 4);

    x = *(f32 *)((u8 *)object + 0x18);
    y = *(f32 *)((u8 *)object + 0x1C);

    *(f32 *)((u8 *)object + 0x18) = *(f32 *)((u8 *)object + 0x48);
    *(f32 *)((u8 *)object + 0x1C) = *(f32 *)((u8 *)object + 0x4C);

    *(f32 *)((u8 *)object + 0x48) = *(f32 *)((u8 *)object + 0x28);
    *(f32 *)((u8 *)object + 0x4C) = *(f32 *)((u8 *)object + 0x2C);

    *(f32 *)((u8 *)object + 0x28) = *(f32 *)((u8 *)object + 0x38);
    *(f32 *)((u8 *)object + 0x2C) = *(f32 *)((u8 *)object + 0x3C);

    *(f32 *)((u8 *)object + 0x38) = x;
    *(f32 *)((u8 *)object + 0x3C) = y;
}

void Prim2D_RotateUvCcw(void)
{
    extern void *gPrim2D;

    void *object;
    f32 x;
    f32 y;

    object = *(void **)((u8 *)gPrim2D + 0xC);
    object = *(void **)((u8 *)object + 4);

    x = *(f32 *)((u8 *)object + 0x18);
    y = *(f32 *)((u8 *)object + 0x1C);

    *(f32 *)((u8 *)object + 0x18) = *(f32 *)((u8 *)object + 0x38);
    *(f32 *)((u8 *)object + 0x1C) = *(f32 *)((u8 *)object + 0x3C);

    *(f32 *)((u8 *)object + 0x38) = *(f32 *)((u8 *)object + 0x28);
    *(f32 *)((u8 *)object + 0x3C) = *(f32 *)((u8 *)object + 0x2C);

    *(f32 *)((u8 *)object + 0x28) = *(f32 *)((u8 *)object + 0x48);
    *(f32 *)((u8 *)object + 0x2C) = *(f32 *)((u8 *)object + 0x4C);

    *(f32 *)((u8 *)object + 0x48) = x;
    *(f32 *)((u8 *)object + 0x4C) = y;
}

void Prim2D_EmitQuad(void) {
    extern void *gPrim2D;
    void *object;

    object = *(void **)((u8 *)gPrim2D + 0xC);
    object = *(void **)((u8 *)object + 4);

    *(f32 *)((u8 *)object + 0x30) = *(f32 *)((u8 *)object + 0x20);
    *(f32 *)((u8 *)object + 0x34) = *(f32 *)((u8 *)object + 0x14);
    *(f32 *)((u8 *)object + 0x40) = *(f32 *)((u8 *)object + 0x10);
    *(f32 *)((u8 *)object + 0x44) = *(f32 *)((u8 *)object + 0x24);
    *(f32 *)((u8 *)object + 0x38) = *(f32 *)((u8 *)object + 0x28);
    *(f32 *)((u8 *)object + 0x3C) = *(f32 *)((u8 *)object + 0x1C);
    *(f32 *)((u8 *)object + 0x48) = *(f32 *)((u8 *)object + 0x18);
    *(f32 *)((u8 *)object + 0x4C) = *(f32 *)((u8 *)object + 0x2C);
}

void fn_80007628(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
 extern void *gPrim2D;
 u8 *ptr = (u8 *)gPrim2D;
 ptr = *(u8 **)(ptr + 0xC);
 ptr = *(u8 **)(ptr + 4);
 *(f32 *)(ptr + 0x40) = arg0;
 *(f32 *)(ptr + 0x44) = arg1;
 *(f32 *)(ptr + 0x48) = arg2;
 *(f32 *)(ptr + 0x4C) = arg3;
}

void fn_80007648(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x30) = arg0;
    *(f32 *)(ptr + 0x34) = arg1;
    *(f32 *)(ptr + 0x38) = arg2;
    *(f32 *)(ptr + 0x3C) = arg3;
}

void Prim2D_SetColorPacked(u8 *src)
{
  extern void *gPrim2D;
  u8 *base;
  u8 a;
  u8 b;
  u8 *new_var;
  u8 c;
  u8 *new_var2;
  u8 *ptr;
  u8 d;
  base = (u8 *) gPrim2D;
  new_var = src;
  a = new_var[0];
  base = *((u8 **) (base + 0xC));
  new_var2 = new_var;
  b = new_var2[1];
  ptr = *((u8 **) (base + 0x4));
  if ((c && c) && c)
  {
  }
  c = new_var[2];
  ptr[0xC] = a;
  d = src[3];
  ptr[0xD] = b;
  ptr[0xE] = c;
  ptr[0xF] = d;
}

void Prim2D_SetAlpha(u8 arg0) {
    extern void *gPrim2D;

    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(u8 *)(ptr + 0xF) = arg0;
}

void Prim2D_SetColor(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    ptr[0xC] = arg0;
    ptr[0xD] = arg1;
    ptr[0xE] = arg2;
    ptr[0xF] = arg3;
}

void Prim2D_SwapUvV(void) {
 extern void *gPrim2D;
 u8 *ptr;
 f32 temp;
 ptr = (u8 *)gPrim2D;
 ptr = *(u8 **)(ptr + 0xC);
 ptr = *(u8 **)(ptr + 4);
 temp = *(f32 *)(ptr + 0x1C);
 *(f32 *)(ptr + 0x1C) = *(f32 *)(ptr + 0x2C);
 *(f32 *)(ptr + 0x2C) = temp;
}

void Prim2D_SwapUvU(void) {
    extern void *gPrim2D;

    u8 *ptr;
    f32 temp;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    temp = *(f32 *)(ptr + 0x18);
    *(f32 *)(ptr + 0x18) = *(f32 *)(ptr + 0x28);
    *(f32 *)(ptr + 0x28) = temp;
}

void Prim2D_SetRectUv(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f)
{
    extern void *gPrim2D;
    void *p;
    f32 t0, t1, t2, t3;
    p = *(void **)((u8 *)gPrim2D + 0xC);
    p = *(void **)((u8 *)p + 4);
    t0 = a + e;
    t1 = b + f;
    t2 = c + e;
    t3 = d + f;
    *(f32 *)((u8 *)p + 0x10) = a;
    *(f32 *)((u8 *)p + 0x20) = t0;
    *(f32 *)((u8 *)p + 0x14) = b;
    *(f32 *)((u8 *)p + 0x24) = t1;
    *(f32 *)((u8 *)p + 0x1C) = 0.0f;
    *(f32 *)((u8 *)p + 0x18) = 0.0f;
    *(f32 *)((u8 *)p + 0x2C) = 1.0f;
    *(f32 *)((u8 *)p + 0x28) = 1.0f;
    p = *(void **)((u8 *)gPrim2D + 0xC);
    p = *(void **)((u8 *)p + 4);
    *(f32 *)((u8 *)p + 0x18) = c;
    *(f32 *)((u8 *)p + 0x1C) = d;
    *(f32 *)((u8 *)p + 0x28) = t2;
    *(f32 *)((u8 *)p + 0x2C) = t3;
}

void Prim2D_SetUvCorners(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x18) = arg0;
    *(f32 *)(ptr + 0x1C) = arg1;
    *(f32 *)(ptr + 0x28) = arg2;
    *(f32 *)(ptr + 0x2C) = arg3;
}

void Prim2D_SetPosCorners(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x10) = arg0;
    *(f32 *)(ptr + 0x14) = arg1;
    *(f32 *)(ptr + 0x20) = arg2;
    *(f32 *)(ptr + 0x24) = arg3;
}

void Prim2D_SetUvRect(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x18) = arg0;
    *(f32 *)(ptr + 0x1C) = arg1;
    *(f32 *)(ptr + 0x28) = arg0 + arg2;
    *(f32 *)(ptr + 0x2C) = arg1 + arg3;
}

#pragma global_optimizer off
#pragma scheduling off
void Prim2D_SetRect(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    extern f32 lbl_80368B98;
    extern f32 gFloat1;
    u8 *ptr;
    f32 o;
    f32 z;
    f32 sum_x;

    ptr = (u8 *)gPrim2D;
    sum_x = arg0 + arg2;
    arg3 = arg1 + arg3;
    z = lbl_80368B98;
    ptr = *(u8 **)(ptr + 0xC);
    o = gFloat1;
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x10) = arg0;
    *(f32 *)(ptr + 0x20) = sum_x;
    *(f32 *)(ptr + 0x14) = arg1;
    *(f32 *)(ptr + 0x24) = arg3;
    *(f32 *)(ptr + 0x1C) = z;
    *(f32 *)(ptr + 0x18) = z;
    *(f32 *)(ptr + 0x2C) = o;
    *(f32 *)(ptr + 0x28) = o;
}
#pragma scheduling reset
#pragma global_optimizer reset
void Prim2D_SetQuadMax(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x20) = arg0;
    *(f32 *)(ptr + 0x24) = arg1;
    *(f32 *)(ptr + 0x28) = arg2;
    *(f32 *)(ptr + 0x2C) = arg3;
}

void Prim2D_SetQuadMin(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x10) = arg0;
    *(f32 *)(ptr + 0x14) = arg1;
    *(f32 *)(ptr + 0x18) = arg2;
    *(f32 *)(ptr + 0x1C) = arg3;
}

void Prim2D_SetPos(f32 arg0, f32 arg1) {
    extern void *gPrim2D;

    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x10) = arg0;
    *(f32 *)(ptr + 0x14) = arg1;
}

void Prim2D_SetPrimParam(f32 arg0) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);
    *(f32 *)(ptr + 0x8) = arg0;
}

void Prim2D_EndPrim(void) {
    extern u8 *gPrim2D;
    *(s16 *)(gPrim2D + 0x92) += 1;
}

static inline void *Prim2D_FindNode(void) {
    extern void *gPrim2D;
    s32 fn_80006264(void *, void *, s32);
    void *self;
    void *node;
    void *prev;
    prev = 0;
    self = gPrim2D;
    node = *(void **)((u8 *)self + 0xC);
    while (node != 0) {
        if (*(u32 *)((u8 *)node + 8) == *(u32 *)((u8 *)self + 0x18)) {
            if (fn_80006264((u8 *)node + 0x10, (u8 *)self + 0x20, 0x70) == 0) {
                if (*(void **)((u8 *)gPrim2D + 0xC) == node) {
                    return node;
                }
                if (prev != 0) {
                    *(void **)prev = *(void **)node;
                }
                *(void **)node = *(void **)((u8 *)gPrim2D + 0xC);
                *(void **)((u8 *)gPrim2D + 0xC) = node;
                return node;
            }
        }
        prev = node;
        node = *(void **)node;
    }
    return 0;
}

#pragma use_lmw_stmw on
#pragma global_optimizer on
void Prim2D_AddPrim(u8 arg0) {
    extern void *gPrim2D;
    extern const f32 lbl_80368B98;
    extern const f32 gFloat1;
    extern char lbl_80267C70[];
    s32 fn_80006AF4(void *);
    void fn_800062CC(void *, void *, s32);
    void OSPanic(char *, ...);
    u8 *Ui_GetColor(s32);

    s32 size;
    u32 type;
    void *node;

    if (*(u8 *)((u8 *)gPrim2D + 0xA8) == 2) {
        s32 tmp;
        tmp = fn_80006AF4((u8 *)gPrim2D + 0x20);
        *(s32 *)((u8 *)gPrim2D + 0x18) = tmp;
        node = Prim2D_FindNode();
        if (node == 0) {
            void *ctx;
            void *entry;
            ctx = gPrim2D;
            entry = *(void **)((u8 *)ctx + 8);
            *(void **)((u8 *)ctx + 8) = (u8 *)entry + 0x80;
            *(void **)entry = *(void **)((u8 *)gPrim2D + 0xC);
            *(void **)((u8 *)gPrim2D + 0xC) = entry;
            *(s32 *)((u8 *)entry + 4) = 0;
            *(s16 *)((u8 *)entry + 0xC) = -1;
            *(s32 *)((u8 *)entry + 8) = *(s32 *)((u8 *)gPrim2D + 0x18);
            fn_800062CC((u8 *)entry + 0x10, (u8 *)gPrim2D + 0x20, 0x70);
            *(s16 *)((u8 *)gPrim2D + 0x90) += 1;
        }
        *(u8 *)((u8 *)gPrim2D + 0xA8) = 3;
    }
    {
        void *entry;
        type = arg0;
        switch (type) {
        case 1:
        case 4:
            size = 0x30;
            break;
        case 2:
            size = 0x50;
            break;
        case 3:
            size = 0x5C;
            break;
        case 5:
        case 6:
        case 7:
        case 10:
            size = 0x28;
            break;
        case 9:
            size = 0x38;
            break;
        case 11:
            size = 0x18;
            break;
        default:
            OSPanic(lbl_80267C70 + 0x1A, 0x54B, lbl_80267C70 + 0x23);
        }
        entry = *(void **)((u8 *)gPrim2D + 8);
        *(void **)((u8 *)gPrim2D + 8) = (u8 *)entry + size;
        *(u8 *)((u8 *)entry + 4) = arg0;
        *(u8 *)((u8 *)entry + 5) = (u8)size;
        *(f32 *)((u8 *)entry + 8) = lbl_80368B98;
        *(s32 *)((u8 *)entry + 0xC) = -1;
        *(void **)entry = *(void **)((u8 *)*(void **)((u8 *)gPrim2D + 0xC) + 4);
        *(void **)((u8 *)*(void **)((u8 *)gPrim2D + 0xC) + 4) = entry;
        switch ((s32)type) {
        case 5:
        case 6:
        case 7:
        case 10:
            {
                u8 *p;
                node = *(void **)((u8 *)*(void **)((u8 *)gPrim2D + 0xC) + 4);
                *(f32 *)((u8 *)node + 0x1C) = gFloat1;
                *(f32 *)((u8 *)node + 0x20) = lbl_80368B98;
                *(s16 *)((u8 *)node + 0x24) = 0;
                *(s16 *)((u8 *)node + 0x26) = 0;
                p = Ui_GetColor(1);
                *(u8 *)((u8 *)node + 0x18) = p[0];
                *(u8 *)((u8 *)node + 0x19) = p[1];
                *(u8 *)((u8 *)node + 0x1A) = p[2];
                *(u8 *)((u8 *)node + 0x1B) = p[3];
            }
            break;
        }
    }
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_strength_reduction off
void fn_80007B04(void)
{
    extern u8 *gPrim2D;
    extern s16 lbl_802837B0[];
    extern const f32 lbl_80368B98, lbl_80368BA0, lbl_80368BA4;
    extern const f32 lbl_80368BA8, lbl_80368BAC, lbl_80368BB0, lbl_80368BB4;
    u32 OSGetTick(void);
    void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
    void GXSetProjection(void *, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxDesc(s32, s32);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    void GXSetZMode(s32, s32, s32);
    void GXSetScissor(u32, u32, u32, u32);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void fn_802246B8(s32);
    void fn_80223E5C(s32, s32, s32, s32, s32);
    void fn_802250D0(u32 *, u32 *, u32 *, u32 *);
    void fn_80009728(u32, void *, void *, u8);
    void fn_80009008(void *, u8, u8);

    f32 ortho[5][4][4];
    u32 oldX, oldY, oldW, oldH;
    u32 curX, curY, curW, curH;
    u8 *prim, *node, *other, *walker;
    s16 *matrixIds;
    u8 **items, **matrixCursor, **cursor;
    u32 flags, alpha, savedX;
    u8 changed;
    s32 count, j, k;

    *(u32 *)(gPrim2D + 0xA4) = OSGetTick();
    C_MTXOrtho(ortho[4], lbl_80368B98, lbl_80368BAC,
                lbl_80368B98, lbl_80368BB0,
                lbl_80368B98, lbl_80368BB4);
    GXSetProjection(ortho[4], 1);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(11, 1);
    GXSetVtxDesc(13, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 11, 1, 5, 0);
    GXSetVtxAttrFmt(0, 13, 1, 4, 0);
    GXSetCullMode(1);
    GXSetBlendMode(4, 0, 0, 1, 0, 0, 2);
    GXSetNumTevStages(1);

    prim = gPrim2D;
    items = *(u8 ***)(prim + 8);
    count = *(s16 *)(prim + 0x90);
    *(u8 ***)(prim + 8) = items + (count + 1);
    changed = 1;
    cursor = items;
    for (node = *(u8 **)(gPrim2D + 12); node != 0; node = *(u8 **)node) {
        *cursor++ = node;
        flags = *(u16 *)(node + 0x10);
        if ((flags & 0xF0) == 0) {
            if (flags & 0x800)
                *(f32 *)(node + 0x18) = lbl_80368BA0;
            else
                *(f32 *)(node + 0x18) = lbl_80368BA4;
        } else if (flags & 0x800) {
            *(f32 *)(node + 0x18) += lbl_80368BA8;
        }
    }

    while (changed) {
        changed = 0;
        cursor = items;
        for (k = 0; k < *(s16 *)(gPrim2D + 0x90) - 1; ++k, ++cursor) {
            node = cursor[0];
            other = cursor[1];
            if (*(f32 *)(node + 0x18) < *(f32 *)(other + 0x18)) {
                cursor[0] = other;
                cursor[1] = node;
                changed = 1;
            }
        }
    }

    items[*(s16 *)(gPrim2D + 0x90)] = 0;
    cursor = items;
    fn_802250D0(&oldX, &oldY, &oldW, &oldH);
    GXSetViewport(lbl_80368B98, lbl_80368B98,
                  lbl_80368BB0, lbl_80368BAC,
                  *(f32 *)(gPrim2D + 0x9C), *(f32 *)(gPrim2D + 0xA0));
    GXSetZMode(1, 3, 1);
    fn_802246B8(0);
    fn_80223E5C(6, 0x80, 1, 0, 0);
    while ((node = *cursor) != 0) {
        flags = *(u16 *)(node + 0x10);
        if (flags & 0xF0) goto pass3;
        if (flags & 0x800) goto pass2;
        fn_802250D0(&curX, &curY, &curW, &curH);
        savedX = oldX;
        if (savedX != curX || oldY != curY ||
            oldW != curW || oldH != curH) {
            GXSetScissor(savedX, oldY, oldW, oldH);
        }
        node = *cursor;
        flags = *(u16 *)(node + 0x10);
        if (flags & 0x1000) {
            ((void (*)(u32, void *, void *, void *, u8))*(void **)(node + 0x1C))
                (flags, *(void **)(node + 0x20), node + 0x24, node + 0x44, node[0x12]);
        } else {
            fn_80009728(flags, node + 0x24, node + 0x44, node[0x12]);
        }
        node = *cursor;
        if (*(s16 *)(node + 0xC) < 0) {
            matrixCursor = cursor;
            matrixIds = lbl_802837B0;
            j = 0;
            while ((walker = *matrixCursor) != 0 && j < 10) {
                if (*(u16 *)(walker + 0x10) & 0x400) {
                    *(s16 *)(walker + 0xC) = lbl_802837B0[j];
                    GXLoadPosMtxImm(*matrixCursor + 0x50, lbl_802837B0[j]);
                    break;
                }
                *(s16 *)(walker + 0xC) = *matrixIds;
                GXLoadPosMtxImm(*matrixCursor + 0x50, *matrixIds);
                ++matrixCursor;
                ++matrixIds;
                ++j;
            }
        }
        node = *cursor;
        GXSetCurrentMtx(*(s16 *)(node + 0xC));
        node = *cursor;
        flags = *(u16 *)(node + 0x10);
        if (flags & 0x2000) {
            ((void (*)(u32, void *, void *, void *, u8))*(void **)(node + 0x1C))
                (flags, *(void **)(node + 0x20), node + 0x24, node + 0x44, node[0x12]);
        }
        alpha = gPrim2D[0xA9];
        if (alpha == 255 || (*(u16 *)(*cursor + 0x10) & 0x400)) {
            node = *cursor;
            fn_80009008(*(void **)(node + 4), node[0x13], node[0x14]);
        } else if (alpha != 0) {
            node = *cursor;
            fn_80009008(*(void **)(node + 4), (u8)(((s32)alpha * node[0x13]) >> 8), node[0x14]);
        }
        node = *cursor;
        flags = *(u16 *)(node + 0x10);
        if (flags & 0x4000) {
            ((void (*)(u32, void *, void *, void *, u8))*(void **)(node + 0x1C))
                (flags, *(void **)(node + 0x20), node + 0x24, node + 0x44, node[0x12]);
        }
        flags = *(u16 *)(*cursor + 0x10);
        if (flags & 0x400) {
            if (!(flags & 0xF0)) {
                GXSetZMode(1, 3, 1);
                fn_802246B8(0);
                fn_80223E5C(6, 0x80, 1, 0, 0);
            } else {
                GXSetZMode(1, 3, 0);
                fn_802246B8(1);
                fn_80223E5C(7, 0, 1, 7, 0);
            }
            C_MTXOrtho(ortho[3], lbl_80368B98, lbl_80368BAC,
                       lbl_80368B98, lbl_80368BB0,
                       lbl_80368B98, lbl_80368BB4);
            GXSetProjection(ortho[3], 1);
            GXClearVtxDesc();
            GXSetVtxDesc(9, 1);
            GXSetVtxDesc(11, 1);
            GXSetVtxDesc(13, 1);
            GXSetVtxAttrFmt(0, 9, 1, 4, 0);
            GXSetVtxAttrFmt(0, 11, 1, 5, 0);
            GXSetVtxAttrFmt(0, 13, 1, 4, 0);
            GXSetCullMode(1);
            GXSetBlendMode(4, 0, 0, 1, 0, 0, 2);
            GXSetNumTevStages(1);
        }
        ++cursor;
    }
pass2:
    GXSetViewport(lbl_80368B98, lbl_80368B98, lbl_80368BB0, lbl_80368BAC,
                  *(f32 *)(gPrim2D + 0x94), *(f32 *)(gPrim2D + 0x98));
    while ((node = *cursor) != 0) {
        flags = *(u16 *)(node + 0x10);
        if (flags & 0xF0) goto pass3;
        fn_802250D0(&curX, &curY, &curW, &curH);
        savedX = oldX;
        if (savedX != curX || oldY != curY ||
            oldW != curW || oldH != curH) {
            GXSetScissor(savedX, oldY, oldW, oldH);
        }
        node = *cursor;
        flags = *(u16 *)(node + 0x10);
        if (flags & 0x1000) {
            ((void (*)(u32, void *, void *, void *, u8))*(void **)(node + 0x1C))
                (flags, *(void **)(node + 0x20), node + 0x24, node + 0x44, node[0x12]);
        } else {
            fn_80009728(flags, node + 0x24, node + 0x44, node[0x12]);
        }
        node = *cursor;
        if (*(s16 *)(node + 0xC) < 0) {
            matrixCursor = cursor;
            matrixIds = lbl_802837B0;
            j = 0;
            while ((walker = *matrixCursor) != 0 && j < 10) {
                if (*(u16 *)(walker + 0x10) & 0x400) {
                    *(s16 *)(walker + 0xC) = lbl_802837B0[j];
                    GXLoadPosMtxImm(*matrixCursor + 0x50, lbl_802837B0[j]);
                    break;
                }
                *(s16 *)(walker + 0xC) = *matrixIds;
                GXLoadPosMtxImm(*matrixCursor + 0x50, *matrixIds);
                ++matrixCursor;
                ++matrixIds;
                ++j;
            }
        }
        node = *cursor;
        GXSetCurrentMtx(*(s16 *)(node + 0xC));
        node = *cursor;
        flags = *(u16 *)(node + 0x10);
        if (flags & 0x2000) {
            ((void (*)(u32, void *, void *, void *, u8))*(void **)(node + 0x1C))
                (flags, *(void **)(node + 0x20), node + 0x24, node + 0x44, node[0x12]);
        }
        alpha = gPrim2D[0xA9];
        if (alpha == 255 || (*(u16 *)(*cursor + 0x10) & 0x400)) {
            node = *cursor;
            fn_80009008(*(void **)(node + 4), node[0x13], node[0x14]);
        } else if (alpha != 0) {
            node = *cursor;
            fn_80009008(*(void **)(node + 4), (u8)(((s32)alpha * node[0x13]) >> 8), node[0x14]);
        }
        node = *cursor;
        flags = *(u16 *)(node + 0x10);
        if (flags & 0x4000) {
            ((void (*)(u32, void *, void *, void *, u8))*(void **)(node + 0x1C))
                (flags, *(void **)(node + 0x20), node + 0x24, node + 0x44, node[0x12]);
        }
        flags = *(u16 *)(*cursor + 0x10);
        if (flags & 0x400) {
            if (!(flags & 0xF0)) {
                GXSetZMode(1, 3, 1);
                fn_802246B8(0);
                fn_80223E5C(6, 0x80, 1, 0, 0);
            } else {
                GXSetZMode(1, 3, 0);
                fn_802246B8(1);
                fn_80223E5C(7, 0, 1, 7, 0);
            }
            C_MTXOrtho(ortho[2], lbl_80368B98, lbl_80368BAC,
                       lbl_80368B98, lbl_80368BB0,
                       lbl_80368B98, lbl_80368BB4);
            GXSetProjection(ortho[2], 1);
            GXClearVtxDesc();
            GXSetVtxDesc(9, 1);
            GXSetVtxDesc(11, 1);
            GXSetVtxDesc(13, 1);
            GXSetVtxAttrFmt(0, 9, 1, 4, 0);
            GXSetVtxAttrFmt(0, 11, 1, 5, 0);
            GXSetVtxAttrFmt(0, 13, 1, 4, 0);
            GXSetCullMode(1);
            GXSetBlendMode(4, 0, 0, 1, 0, 0, 2);
            GXSetNumTevStages(1);
        }
        ++cursor;
    }
pass3:
    GXSetViewport(lbl_80368B98, lbl_80368B98, lbl_80368BB0, lbl_80368BAC,
                  *(f32 *)(gPrim2D + 0x94), *(f32 *)(gPrim2D + 0x98));
    GXSetZMode(1, 3, 0);
    fn_802246B8(1);
    fn_80223E5C(7, 0, 1, 7, 0);
    while ((node = *cursor) != 0) {
        flags = *(u16 *)(node + 0x10);
        if (!(flags & 0x800)) goto pass4;
        fn_802250D0(&curX, &curY, &curW, &curH);
        savedX = oldX;
        if (savedX != curX || oldY != curY ||
            oldW != curW || oldH != curH) {
            GXSetScissor(savedX, oldY, oldW, oldH);
        }
        node = *cursor;
        flags = *(u16 *)(node + 0x10);
        if (flags & 0x1000) {
            ((void (*)(u32, void *, void *, void *, u8))*(void **)(node + 0x1C))
                (flags, *(void **)(node + 0x20), node + 0x24, node + 0x44, node[0x12]);
        } else {
            fn_80009728(flags, node + 0x24, node + 0x44, node[0x12]);
        }
        node = *cursor;
        if (*(s16 *)(node + 0xC) < 0) {
            matrixCursor = cursor;
            matrixIds = lbl_802837B0;
            j = 0;
            while ((walker = *matrixCursor) != 0 && j < 10) {
                if (*(u16 *)(walker + 0x10) & 0x400) {
                    *(s16 *)(walker + 0xC) = lbl_802837B0[j];
                    GXLoadPosMtxImm(*matrixCursor + 0x50, lbl_802837B0[j]);
                    break;
                }
                *(s16 *)(walker + 0xC) = *matrixIds;
                GXLoadPosMtxImm(*matrixCursor + 0x50, *matrixIds);
                ++matrixCursor;
                ++matrixIds;
                ++j;
            }
        }
        node = *cursor;
        GXSetCurrentMtx(*(s16 *)(node + 0xC));
        node = *cursor;
        flags = *(u16 *)(node + 0x10);
        if (flags & 0x2000) {
            ((void (*)(u32, void *, void *, void *, u8))*(void **)(node + 0x1C))
                (flags, *(void **)(node + 0x20), node + 0x24, node + 0x44, node[0x12]);
        }
        alpha = gPrim2D[0xA9];
        if (alpha == 255 || (*(u16 *)(*cursor + 0x10) & 0x400)) {
            node = *cursor;
            fn_80009008(*(void **)(node + 4), node[0x13], node[0x14]);
        } else if (alpha != 0) {
            node = *cursor;
            fn_80009008(*(void **)(node + 4), (u8)(((s32)alpha * node[0x13]) >> 8), node[0x14]);
        }
        node = *cursor;
        flags = *(u16 *)(node + 0x10);
        if (flags & 0x4000) {
            ((void (*)(u32, void *, void *, void *, u8))*(void **)(node + 0x1C))
                (flags, *(void **)(node + 0x20), node + 0x24, node + 0x44, node[0x12]);
        }
        flags = *(u16 *)(*cursor + 0x10);
        if (flags & 0x400) {
            if (!(flags & 0xF0)) {
                GXSetZMode(1, 3, 1);
                fn_802246B8(0);
                fn_80223E5C(6, 0x80, 1, 0, 0);
            } else {
                GXSetZMode(1, 3, 0);
                fn_802246B8(1);
                fn_80223E5C(7, 0, 1, 7, 0);
            }
            C_MTXOrtho(ortho[1], lbl_80368B98, lbl_80368BAC,
                       lbl_80368B98, lbl_80368BB0,
                       lbl_80368B98, lbl_80368BB4);
            GXSetProjection(ortho[1], 1);
            GXClearVtxDesc();
            GXSetVtxDesc(9, 1);
            GXSetVtxDesc(11, 1);
            GXSetVtxDesc(13, 1);
            GXSetVtxAttrFmt(0, 9, 1, 4, 0);
            GXSetVtxAttrFmt(0, 11, 1, 5, 0);
            GXSetVtxAttrFmt(0, 13, 1, 4, 0);
            GXSetCullMode(1);
            GXSetBlendMode(4, 0, 0, 1, 0, 0, 2);
            GXSetNumTevStages(1);
        }
        ++cursor;
    }
pass4:
    GXSetViewport(lbl_80368B98, lbl_80368B98, lbl_80368BB0, lbl_80368BAC,
                  *(f32 *)(gPrim2D + 0x9C), *(f32 *)(gPrim2D + 0xA0));
    while ((node = *cursor) != 0) {
        fn_802250D0(&curX, &curY, &curW, &curH);
        savedX = oldX;
        if (savedX != curX || oldY != curY ||
            oldW != curW || oldH != curH) {
            GXSetScissor(savedX, oldY, oldW, oldH);
        }
        node = *cursor;
        flags = *(u16 *)(node + 0x10);
        if (flags & 0x1000) {
            ((void (*)(u32, void *, void *, void *, u8))*(void **)(node + 0x1C))
                (flags, *(void **)(node + 0x20), node + 0x24, node + 0x44, node[0x12]);
        } else {
            fn_80009728(flags, node + 0x24, node + 0x44, node[0x12]);
        }
        node = *cursor;
        if (*(s16 *)(node + 0xC) < 0) {
            matrixCursor = cursor;
            matrixIds = lbl_802837B0;
            j = 0;
            while ((walker = *matrixCursor) != 0 && j < 10) {
                if (*(u16 *)(walker + 0x10) & 0x400) {
                    *(s16 *)(walker + 0xC) = lbl_802837B0[j];
                    GXLoadPosMtxImm(*matrixCursor + 0x50, lbl_802837B0[j]);
                    break;
                }
                *(s16 *)(walker + 0xC) = *matrixIds;
                GXLoadPosMtxImm(*matrixCursor + 0x50, *matrixIds);
                ++matrixCursor;
                ++matrixIds;
                ++j;
            }
        }
        node = *cursor;
        GXSetCurrentMtx(*(s16 *)(node + 0xC));
        node = *cursor;
        flags = *(u16 *)(node + 0x10);
        if (flags & 0x2000) {
            ((void (*)(u32, void *, void *, void *, u8))*(void **)(node + 0x1C))
                (flags, *(void **)(node + 0x20), node + 0x24, node + 0x44, node[0x12]);
        }
        alpha = gPrim2D[0xA9];
        if (alpha == 255 || (*(u16 *)(*cursor + 0x10) & 0x400)) {
            node = *cursor;
            fn_80009008(*(void **)(node + 4), node[0x13], node[0x14]);
        } else if (alpha != 0) {
            node = *cursor;
            fn_80009008(*(void **)(node + 4), (u8)(((s32)alpha * node[0x13]) >> 8), node[0x14]);
        }
        node = *cursor;
        flags = *(u16 *)(node + 0x10);
        if (flags & 0x4000) {
            ((void (*)(u32, void *, void *, void *, u8))*(void **)(node + 0x1C))
                (flags, *(void **)(node + 0x20), node + 0x24, node + 0x44, node[0x12]);
        }
        flags = *(u16 *)(*cursor + 0x10);
        if (flags & 0x400) {
            if (!(flags & 0xF0)) {
                GXSetZMode(1, 3, 1);
                fn_802246B8(0);
                fn_80223E5C(6, 0x80, 1, 0, 0);
            } else {
                GXSetZMode(1, 3, 0);
                fn_802246B8(1);
                fn_80223E5C(7, 0, 1, 7, 0);
            }
            C_MTXOrtho(ortho[0], lbl_80368B98, lbl_80368BAC,
                       lbl_80368B98, lbl_80368BB0,
                       lbl_80368B98, lbl_80368BB4);
            GXSetProjection(ortho[0], 1);
            GXClearVtxDesc();
            GXSetVtxDesc(9, 1);
            GXSetVtxDesc(11, 1);
            GXSetVtxDesc(13, 1);
            GXSetVtxAttrFmt(0, 9, 1, 4, 0);
            GXSetVtxAttrFmt(0, 11, 1, 5, 0);
            GXSetVtxAttrFmt(0, 13, 1, 4, 0);
            GXSetCullMode(1);
            GXSetBlendMode(4, 0, 0, 1, 0, 0, 2);
            GXSetNumTevStages(1);
        }
        ++cursor;
    }
    prim = gPrim2D;
    *(u32 *)(prim + 0xA4) = OSGetTick() - *(u32 *)(prim + 0xA4);
    gPrim2D[0xA9] = 0xFF;
}
#pragma pop
#pragma global_optimizer on
void fn_80008B94(void)
{
    extern u8 *gPrim2D;
    extern void PSMTXIdentity(void *);

    *(s32 *)(gPrim2D + 8) = *(s32 *)gPrim2D + 0xAC;
    *(s32 *)(gPrim2D + 0xC) = 0;
    *(s16 *)(gPrim2D + 0x92) = 0;
    *(s16 *)(gPrim2D + 0x90) = 0;
    PSMTXIdentity(gPrim2D + 0x60);
    *(s32 *)(gPrim2D + 0x2C) = 0;
    *(s32 *)(gPrim2D + 0x30) = 0;
    gPrim2D[0x23] = 0xFF;
    gPrim2D[0x24] = 0x80;
    *(s16 *)(gPrim2D + 0x20) = 0;
    gPrim2D[0xA8] = 0;
}

void fn_80008C24(u8 *arg0, u8 *arg1, s8 *arg2, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    void *fn_80005C40(void);
    s32 fn_80011010(s32);
    u8 *fn_801047DC(s8 *);
    s8 *fn_801049E0(s8 *, s32 *, s32 *, s32 *, s32 *, s32 *);
    void PSMTXScale(f32 (*)[4], f32, f32, f32);
    void GXBegin(s32, s32, s32);
    void fn_80222644(void *, s32, u16, u16, u16, s32, s32, s32);
    void fn_80222C50(void *, s32);
    void fn_80224E50(f32 (*)[4], s32, s32);

    s32 saved;
    u8 *font;
    f32 mtx[3][4];
    u32 texObj[8];
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    u8 *glyph;
    f32 u;
    f32 v;
    f32 w0;
    f32 w1;
    f32 gw;
    f32 gh;
    f32 x;
    f32 y;
    f32 dx;
    f32 dy;
    f32 x2;
    f32 y2;
    f32 u2;
    f32 v2;
    u8 r0, g0, b0, a0;
    u8 r1, g1, b1, a1;

    saved = fn_80011010(-1);
    font = (u8 *)fn_80005C40();
    PSMTXScale(mtx, 1.0f / (f32)*(u16 *)(font + 0x1E), 1.0f / (f32)*(u16 *)(font + 0x20), 1.0f);
    fn_80224E50(mtx, 0x1E, 1);

    while (*arg2 != 0) {
        glyph = fn_801047DC(arg2);
        gw = (f32)glyph[8];
        gh = (f32)glyph[9];
        x = farg0 + (f32)(s8)glyph[0xA] * farg3;
        y = (farg1 + (f32)*(u16 *)(font + 8) * farg3) - (f32)(s8)glyph[0xB] * farg3;
        arg2 = fn_801049E0(arg2, &sp18, &sp14, &sp10, &spC, &sp8);
        u = (f32)sp14;
        v = (f32)sp10;
        w0 = (f32)spC;
        w1 = (f32)sp8;
        fn_80222644(texObj, sp18, *(u16 *)(font + 0x1E), *(u16 *)(font + 0x20), *(u16 *)(font + 0x18), 0, 0, 0);
        fn_80222C50(texObj, 0);
        x += farg3 * (0.5f * (w1 - w0));
        GXBegin(0x80, 0, 4);

        *(volatile f32 *)0xCC008000 = x;
        dx = gw * farg3;
        dy = gh * farg3;
        r0 = arg0[0];
        *(volatile f32 *)0xCC008000 = y;
        u2 = u + gw;
        g0 = arg0[1];
        *(volatile f32 *)0xCC008000 = farg2;
        b0 = arg0[2];
        x2 = x + dx;
        *(volatile u8 *)0xCC008000 = r0;
        y2 = y + dy;
        a0 = arg0[3];
        v2 = v + gh;
        *(volatile u8 *)0xCC008000 = g0;
        r1 = arg1[0];
        farg0 += w1 * farg3;
        *(volatile u8 *)0xCC008000 = b0;
        g1 = arg1[1];
        *(volatile u8 *)0xCC008000 = a0;
        b1 = arg1[2];
        *(volatile f32 *)0xCC008000 = u;
        a1 = arg1[3];
        *(volatile f32 *)0xCC008000 = v;

        *(volatile f32 *)0xCC008000 = x2;
        *(volatile f32 *)0xCC008000 = y;
        *(volatile f32 *)0xCC008000 = farg2;
        *(volatile u8 *)0xCC008000 = r0;
        *(volatile u8 *)0xCC008000 = g0;
        *(volatile u8 *)0xCC008000 = b0;
        *(volatile u8 *)0xCC008000 = a0;
        *(volatile f32 *)0xCC008000 = u2;
        *(volatile f32 *)0xCC008000 = v;

        *(volatile f32 *)0xCC008000 = x2;
        *(volatile f32 *)0xCC008000 = y2;
        *(volatile f32 *)0xCC008000 = farg2;
        *(volatile u8 *)0xCC008000 = r1;
        *(volatile u8 *)0xCC008000 = g1;
        *(volatile u8 *)0xCC008000 = b1;
        *(volatile u8 *)0xCC008000 = a1;
        *(volatile f32 *)0xCC008000 = u2;
        *(volatile f32 *)0xCC008000 = v2;

        *(volatile f32 *)0xCC008000 = x;
        *(volatile f32 *)0xCC008000 = y2;
        *(volatile f32 *)0xCC008000 = farg2;
        *(volatile u8 *)0xCC008000 = r1;
        *(volatile u8 *)0xCC008000 = g1;
        *(volatile u8 *)0xCC008000 = b1;
        *(volatile u8 *)0xCC008000 = a1;
        *(volatile f32 *)0xCC008000 = u;
        *(volatile f32 *)0xCC008000 = v2;
    }

    fn_80011010(saved);
}

#pragma use_lmw_stmw on
void fn_80009008(void *list, s32 a, s32 b) {
    void GXBegin(s32, s32, s32);
    void fn_80008C24(void *, void *, void *, f32, f32, f32, f32);
    void fn_8014B388(void *, void *, f32, f32, f32);
    void fn_8000E684(s16, s16, s32, void *, void *, void *, f32, f32, f32, f32, f32);
    void fn_8000E50C(s16, s16, s32, void *, void *, void *, f32, f32, f32, f32, f32);
    void fn_8000E394(s16, s16, s32, void *, void *, void *, f32, f32, f32, f32, f32);
    void fn_80006E8C(void *, u32, u32, u32, u32);

    u8 scale;
    s32 scale1;
    u8 cr, cg;
    u8 cb;
    u8 ca;
    u8 *node;
    s32 bsave;
    u8 type;
    u8 tmpCol[16], c0[4], c1[4];
    u32 col;
    f32 fx, fy, fz;
    u8 pr, pg, pb, pa;
    void (*vfn)(s32);

    bsave = b;
    node = list;
    scale = (u8)b;
    scale1 = (u8)a + 1;

    while (node != NULL) {
        cr = (u8)((node[0xC] * scale) >> 7);
        cg = (u8)((node[0xD] * scale) >> 7);
        cb = (u8)((node[0xE] * scale) >> 7);
        ca = (u8)((node[0xF] * scale1) >> 8);
        type = node[4];
        switch (type) {
            case 1:
                GXBegin(0x98, 0, 4);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x14); fx = *(f32 *)(node + 0x10);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                fx = *(f32 *)(node + 0x18); fy = *(f32 *)(node + 0x1C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x14); fx = *(f32 *)(node + 0x20);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                fx = *(f32 *)(node + 0x28); fy = *(f32 *)(node + 0x1C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x24); fx = *(f32 *)(node + 0x10);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                fx = *(f32 *)(node + 0x18); fy = *(f32 *)(node + 0x2C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x24); fx = *(f32 *)(node + 0x20);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                fx = *(f32 *)(node + 0x28); fy = *(f32 *)(node + 0x2C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                break;
            case 2:
                GXBegin(0x98, 0, 4);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x14); fx = *(f32 *)(node + 0x10);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                fx = *(f32 *)(node + 0x18); fy = *(f32 *)(node + 0x1C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x34); fx = *(f32 *)(node + 0x30);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                fx = *(f32 *)(node + 0x38); fy = *(f32 *)(node + 0x3C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x44); fx = *(f32 *)(node + 0x40);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                fx = *(f32 *)(node + 0x48); fy = *(f32 *)(node + 0x4C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x24); fx = *(f32 *)(node + 0x20);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                fx = *(f32 *)(node + 0x28); fy = *(f32 *)(node + 0x2C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                break;
            case 3:
                GXBegin(0x98, 0, 4);
                pr = (u8)((node[0xC] * scale) >> 7); pg = (u8)((node[0xD] * scale) >> 7);
                pb = (u8)((node[0xE] * scale) >> 7); pa = (u8)((node[0xF] * scale1) >> 8);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x14); fx = *(f32 *)(node + 0x10);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = pr; *(volatile u8 *)0xCC008000 = pg; *(volatile u8 *)0xCC008000 = pb; *(volatile u8 *)0xCC008000 = pa;
                fx = *(f32 *)(node + 0x18); fy = *(f32 *)(node + 0x1C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                pr = (u8)((node[0x50] * scale) >> 7); pg = (u8)((node[0x51] * scale) >> 7);
                pb = (u8)((node[0x52] * scale) >> 7); pa = (u8)((node[0x53] * scale1) >> 8);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x34); fx = *(f32 *)(node + 0x30);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = pr; *(volatile u8 *)0xCC008000 = pg; *(volatile u8 *)0xCC008000 = pb; *(volatile u8 *)0xCC008000 = pa;
                fx = *(f32 *)(node + 0x38); fy = *(f32 *)(node + 0x3C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                pr = (u8)((node[0x54] * scale) >> 7); pg = (u8)((node[0x55] * scale) >> 7);
                pb = (u8)((node[0x56] * scale) >> 7); pa = (u8)((node[0x57] * scale1) >> 8);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x44); fx = *(f32 *)(node + 0x40);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = pr; *(volatile u8 *)0xCC008000 = pg; *(volatile u8 *)0xCC008000 = pb; *(volatile u8 *)0xCC008000 = pa;
                fx = *(f32 *)(node + 0x48); fy = *(f32 *)(node + 0x4C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                pr = (u8)((node[0x58] * scale) >> 7); pg = (u8)((node[0x59] * scale) >> 7);
                pb = (u8)((node[0x5A] * scale) >> 7); pa = (u8)((node[0x5B] * scale1) >> 8);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x24); fx = *(f32 *)(node + 0x20);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = pr; *(volatile u8 *)0xCC008000 = pg; *(volatile u8 *)0xCC008000 = pb; *(volatile u8 *)0xCC008000 = pa;
                fx = *(f32 *)(node + 0x28); fy = *(f32 *)(node + 0x2C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                break;
            case 4:
                ca = (u8)((node[0xF] * scale1) >> 8);
                GXBegin(0xA8, 0, 2);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x14); fx = *(f32 *)(node + 0x10);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                fx = *(f32 *)(node + 0x18); fy = *(f32 *)(node + 0x1C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x24); fx = *(f32 *)(node + 0x20);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                fx = *(f32 *)(node + 0x28); fy = *(f32 *)(node + 0x2C);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy;
                break;
            case 5:
                col = (cr << 24) + (cg << 16) + (cb << 8) + ca;
                *(u32 *)c1 = col;
                c0[0] = (u8)((node[0x18] * scale) >> 7);
                c0[1] = (u8)((node[0x19] * scale) >> 7);
                c0[2] = (u8)((node[0x1A] * scale) >> 7);
                c0[3] = (u8)((node[0x1B] * scale1) >> 8);
                *(u32 *)tmpCol = *(u32 *)c0;
                fn_80008C24(c0, c1, node + 0x28, *(f32 *)(node + 0x10), *(f32 *)(node + 0x14), *(f32 *)(node + 0x8), *(f32 *)(node + 0x1C));
                break;
            case 10:
                col = (cr << 24) + (cg << 16) + (cb << 8) + ca;
                *(u32 *)c1 = col; *(u32 *)c0 = col;
                fn_8014B388(c0, node + 0x28, *(f32 *)(node + 0x10), *(f32 *)(node + 0x14), *(f32 *)(node + 0x8));
                break;
            case 6:
                col = (cr << 24) + (cg << 16) + (cb << 8) + ca;
                *(u32 *)c1 = col;
                c0[0] = node[0x18]; c0[1] = node[0x19]; c0[2] = node[0x1A];
                c0[3] = (u8)((node[0x1B] * scale1) >> 8);
                fn_8000E684(*(s16 *)(node + 0x24), *(s16 *)(node + 0x26), bsave, c0, c1, node + 0x28,
                    *(f32 *)(node + 0x10), *(f32 *)(node + 0x14), *(f32 *)(node + 0x8), *(f32 *)(node + 0x1C), *(f32 *)(node + 0x20));
                break;
            case 7:
                col = (cr << 24) + (cg << 16) + (cb << 8) + ca;
                *(u32 *)c1 = col;
                c0[0] = node[0x18]; c0[1] = node[0x19]; c0[2] = node[0x1A];
                c0[3] = (u8)((node[0x1B] * scale1) >> 8);
                fn_8000E50C(*(s16 *)(node + 0x24), *(s16 *)(node + 0x26), bsave, c0, c1, node + 0x28,
                    *(f32 *)(node + 0x10), *(f32 *)(node + 0x14), *(f32 *)(node + 0x8), *(f32 *)(node + 0x1C), *(f32 *)(node + 0x20));
                break;
            case 8:
                col = (cr << 24) + (cg << 16) + (cb << 8) + ca;
                *(u32 *)c1 = col;
                c0[0] = node[0x18]; c0[1] = node[0x19]; c0[2] = node[0x1A];
                c0[3] = (u8)((node[0x1B] * scale1) >> 8);
                fn_8000E394(*(s16 *)(node + 0x24), *(s16 *)(node + 0x26), bsave, c0, c1, node + 0x28,
                    *(f32 *)(node + 0x10), *(f32 *)(node + 0x14), *(f32 *)(node + 0x8), *(f32 *)(node + 0x1C), *(f32 *)(node + 0x20));
                break;
            case 9:
                fn_80006E8C(node, cr, cg, cb, ca);
                break;
            case 11:
                vfn = *(void (**)(s32))(node + 0x10);
                vfn(*(s32 *)(node + 0x14));
                break;
            default:
                break;
        }
        node = *(u8 **)node;
    }
}
#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
void fn_80009728(u32 arg0, void *arg1, s32 arg2, s32 arg3) {
    void PSMTXScale(void *, f32, f32, f32);
    void GXSetNumChans(s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void fn_80222CF0(s32, s32);
    void fn_80222C50(void *, s32);
    u32 GXGetTexObjWidth(void *);
    u32 GXGetTexObjHeight(void *);
    s32 fn_80222AA0(void *);
    void fn_80224E50(void *, s32, s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void GXSetTevColorIn(s32, s32, s32, s32, s32);
    void GXSetTevColorOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
    void GXSetTevAlphaOp(s32, s32, s32, s32, s32, s32);
    extern f32 gFloat1;
    u8 sp8[0x30];
    u16 temp_r31;
    u8 var_r30;
    f32 temp_f31;
    f32 temp_f1;
    s32 temp_r3;
    s32 a;
    s32 b;

    temp_r31 = (u16)arg0;
    var_r30 = 1;
    switch (arg0 & 3) {
    case 2:
        var_r30 = 0;
        GXSetNumChans(0);
        GXSetTevOrder(0, 0xFF, 0xFF, 4);
        break;
    case 0:
        if (temp_r31 & 0x8000) {
            fn_80222CF0(arg2, arg3);
        }
        fn_80222C50(arg1, 0);
        GXSetNumChans(1);
        fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
        GXSetTevOrder(0, 0, 0, 4);
        break;
    case 1:
        if (temp_r31 & 0x8000) {
            fn_80222CF0(arg2, arg3);
        }
        fn_80222C50(arg1, 0);
        temp_f31 = gFloat1 / (f32)(u16)GXGetTexObjHeight(arg1);
        temp_f1 = gFloat1 / (f32)(u16)GXGetTexObjWidth(arg1);
        PSMTXScale(sp8, temp_f1, temp_f31, gFloat1);
        fn_80224E50(sp8, 0x1E, 1);
        GXSetNumChans(1);
        fn_802201A8(0, 1, 4, 0x1E, 0, 0x7D);
        GXSetTevOrder(0, 0, 0, 4);
        break;
    case 3:
        GXSetNumChans(1);
        fn_802201A8(0, 1, 4, 0x1E, 0, 0x7D);
        GXSetTevOrder(0, 0, 0, 4);
        break;
    }

    switch (temp_r31 & 0xF0) {
    case 0x0:
        fn_802245D8(0, 0, 0, 0);
        a = 0;
        b = 4;
        if (var_r30 != 0) {
            b = 0;
        }
        GXSetNumTexGens(a, b);
        break;
    case 0x10:
        fn_802245D8(1, 4, 5, 0);
        if (var_r30 != 0) {
            temp_r3 = fn_80222AA0(arg1);
            switch (temp_r3) {
            case 0:
            case 1:
                GXSetTevColorIn(0, 0xF, 0xF, 0xF, 0xA);
                GXSetTevColorOp(0, 0, 0, 0, 1, 0);
                GXSetTevAlphaIn(0, 7, 4, 5, 7);
                GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
                break;
            default:
                GXSetNumTexGens(0, 0);
                break;
            }
        } else {
            GXSetNumTexGens(0, 4);
        }
        break;
    case 0x20:
        fn_802245D8(1, 4, 1, 0);
        a = 0;
        b = 4;
        if (var_r30 != 0) {
            b = 0;
        }
        GXSetNumTexGens(a, b);
        break;
    case 0x30:
        fn_802245D8(3, 4, 1, 0);
        a = 0;
        b = 4;
        if (var_r30 != 0) {
            b = 0;
        }
        GXSetNumTexGens(a, b);
        break;
    case 0x40:
        GXSetTevColorIn(0, 0xF, 0xF, 0xF, 0xA);
        GXSetTevColorOp(0, 0, 0, 0, 1, 0);
        GXSetTevAlphaIn(0, 7, 4, 5, 7);
        GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
        break;
    }
}
#pragma pop
void Prim2D_ResetState(void) {
    extern u16 gPrim2D;

    *(u8 *)(*(u8 **)&gPrim2D + 0xa8) = 1;
    *(u8 *)(*(u8 **)&gPrim2D + 0x23) = 0xff;
    *(u8 *)(*(u8 **)&gPrim2D + 0x24) = 0x80;
    *(u32 *)(*(u8 **)&gPrim2D + 0x2c) = 0;
    *(u32 *)(*(u8 **)&gPrim2D + 0x30) = 0;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) &= ~0x7000;
    *(u8 *)(*(u8 **)&gPrim2D + 0xa8) = 2;
}

void Prim2D_SetAlphaByte(s8 arg0) {
    extern void *gPrim2D;
    M2C_FIELD(gPrim2D, s8 *, 0x24) = arg0;
}

extern u16 gPrim2D;
void Prim2D_SetColorByte(s8 arg0) {
    *(u8 *)(*(u8 **)&gPrim2D + 0x23) = (u8)arg0;
}

void Prim2D_ClearCallbacks(void) {
    extern u16 gPrim2D;

    *(u32 *)(*(u8 **)&gPrim2D + 0x2c) = 0;
    *(u32 *)(*(u8 **)&gPrim2D + 0x30) = 0;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) &= ~0x7000;
}

void Prim2D_SetCallback(s32 arg0, s32 arg1) {
    extern u16 gPrim2D;

    *(u32 *)(*(u8 **)&gPrim2D + 0x2c) = arg0;
    *(u32 *)(*(u8 **)&gPrim2D + 0x30) = arg1;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) &= ~0x7000;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) |= 0x2000;
}

void fn_80009BF4(f32 farg0) {
    *(f32 *)(*(u8 **)&gPrim2D + 0x28) = farg0;
}

f32 fn_80009C00(void) {
    return *(f32 *)(*(u8 **)&gPrim2D + 0x28);
}

void Prim2D_AddZ(f32 farg0) {
    extern u16 gPrim2D;
    *(f32 *)(*(u8 **)&gPrim2D + 0x28) += farg0;
}

void fn_80009C20(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void PSMTXRotRad(void *, u32, f32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXCopy(void *, void *);
    extern f32 gFloat1;
    extern f32 lbl_80368B98;
    extern f32 lbl_80368B9C;
    extern u16 gPrim2D;
    f32 scale[12];
    f32 trans[12];
    f32 rot[12];
    f32 pos[12];
    f32 neg[12];
    f32 result[12];
    f32 scalar;

    scalar = arg2;
    PSMTXTrans(trans, arg0, arg1, arg2);
    PSMTXScale(scale, arg5, arg6, gFloat1);
    PSMTXRotRad(rot, 0x5A, lbl_80368B9C * arg7);
    PSMTXTrans(neg, -arg3, -arg4, lbl_80368B98);
    PSMTXTrans(pos, arg3, arg4, lbl_80368B98);
    PSMTXConcat(scale, neg, result);
    PSMTXConcat(rot, result, result);
    PSMTXConcat(pos, result, result);
    PSMTXConcat(trans, result, result);
    PSMTXCopy(result, (*(u8 **)&gPrim2D) + 0x60);
    *(f32 *)((*(u8 **)&gPrim2D) + 0x28) = scalar;
    *(u16 *)((*(u8 **)&gPrim2D) + 0x20) &= ~0x800;
}

/* Build XY(Z) translate and optional uniform scale into gPrim2D's matrix; store z and clear flag 0x800. */
void Prim2D_SetTransform(f32 x, f32 y, f32 z, f32 scale) {
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXCopy(void *, void *);
    extern f32 gFloat1;
    extern u16 gPrim2D;
    f32 tmp[12];
    f32 mtx[12];

    if (gFloat1 == scale) {
        PSMTXTrans(mtx, x, y, z);
    } else {
        PSMTXScale(tmp, scale, scale, gFloat1);
        PSMTXTrans(mtx, x, y, z);
        PSMTXConcat(mtx, tmp, mtx);
    }
    PSMTXCopy(mtx, (*(u8 **)&gPrim2D) + 0x60);
    *(f32 *)((*(u8 **)&gPrim2D) + 0x28) = z;
    *(u16 *)((*(u8 **)&gPrim2D) + 0x20) &= ~0x800;
}

#pragma peephole off
void *Prim2D_PushZ(f32 *arg0) {
    extern u16 gPrim2D;

    if (arg0 != NULL) {
        *arg0 = *(f32 *)(*(u8 *volatile *)&gPrim2D + 0x28);
    }

    return *(u8 *volatile *)&gPrim2D + 0x60;
}
#pragma peephole on
void Prim2D_PopZ(void *src, f32 farg0) {
    void PSMTXCopy(void *, void *);
    extern u16 gPrim2D;

    PSMTXCopy(src, *(u8 **)&gPrim2D + 0x60);
    *(f32 *)(*(u8 **)&gPrim2D + 0x28) = farg0;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) = (u16)(*(u16 *)(*(u8 **)&gPrim2D + 0x20) & ~0x800);
}

#pragma optimization_level 3
void fn_80009EB0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void fn_8006EBC4(void *, void *, void *, s32, s32);
    extern u16 gPrim2D;
    register u8 *p;
    register u16 flags;
    register s32 mask;
    unsigned long a;
    u32 b;
    u8 sp8[0xC];
    u8 sp14[0x20];

    fn_8006EBC4(arg0, sp14, sp8, arg2, arg1);
    p = *(u8 **)&gPrim2D;
    mask = 0xFFFF7B0C;
    a = *(u32 *)(sp14 + 0);
    flags = (u16)(arg3 | 0x8000);
    b = *(u32 *)(sp14 + 4);
    *(u32 *)(p + 0x34) = a;
    *(u32 *)(p + 0x38) = b;
    a = *(u32 *)(sp14 + 8);
    b = *(u32 *)(sp14 + 0xC);
    *(u32 *)(p + 0x3C) = a;
    *(u32 *)(p + 0x40) = b;
    a = *(u32 *)(sp14 + 0x10);
    b = *(u32 *)(sp14 + 0x14);
    *(u32 *)(p + 0x44) = a;
    *(u32 *)(p + 0x48) = b;
    a = *(u32 *)(sp14 + 0x18);
    b = *(u32 *)(sp14 + 0x1C);
    *(u32 *)(p + 0x4C) = a;
    *(u32 *)(p + 0x50) = b;
    p = *(u8 **)&gPrim2D;
    a = *(u32 *)(sp8 + 0);
    b = *(u32 *)(sp8 + 4);
    *(u32 *)(p + 0x58) = b;
    *(u32 *)(p + 0x54) = a;
    *(u32 *)(p + 0x5C) = *(u32 *)(sp8 + 8);
    (*(u8 **)&gPrim2D)[0x22] = arg2;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) =
        *(u16 *)(*(u8 **)&gPrim2D + 0x20) & mask;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) =
        *(u16 *)(*(u8 **)&gPrim2D + 0x20) | flags;
}
#pragma optimization_level reset
void Prim2D_BindTexture(void *arg0, s32 arg1, u16 flags) {
    typedef struct { u32 w[8]; } Blk;
    void Ui_LoadAtlasTex(void *, void *, s32);
    extern u16 gPrim2D;
    Blk sp;

    Ui_LoadAtlasTex(arg0, &sp, arg1);
    *(Blk *)(*(u8 **)&gPrim2D + 0x34) = sp;
    (*(u8 **)&gPrim2D)[0x22] = 0xFF;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) &= 0xFFFF7B0C;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) |= flags;
}

void fn_8000A03C(void *arg0, void *arg1, s8 arg2, u16 arg3) {
    void fn_80006298(void *, s32, u32);
    extern u16 gPrim2D;
    if (arg0) {
        typedef struct { u32 words[8]; } Tex;
        *(Tex *)(*(u8 **)&gPrim2D + 0x34) = *(Tex *)arg0;
    } else {
        fn_80006298(*(u8 **)&gPrim2D + 0x34, 0, 0x20);
        if ((arg3 & 3) == 0) {
            arg3 &= ~3;
            arg3 |= 2;
        }
    }
    if (arg1) {
        *(Struct_8000B090 *)(*(u8 **)&gPrim2D + 0x54) = *(Struct_8000B090 *)arg1;
        arg3 |= 0x8000;
        (*(u8 **)&gPrim2D)[0x22] = (short)arg2;
    } else {
        fn_80006298(*(u8 **)&gPrim2D + 0x54, 0, 0xC);
        (*(u8 **)&gPrim2D)[0x22] = 0xFF;
    }
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) &= 0xFFFF7B0C;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) |= arg3;
}

#pragma global_optimizer off
void Prim2D_SetTex(void *arg0, u32 arg1) {
    void fn_80006298(void *, s32, u32);
    extern u16 gPrim2D;
    u32 *src;
    u32 b;
    u32 a;
    u8 *g;
    u32 tmp;

    if (arg0) {
        g = *(u8 **)&gPrim2D;
        src = (u32 *)arg0;
        a = src[0];
        b = src[1];
        *(u32 *)(g + 0x34) = a;
        *(u32 *)(g + 0x38) = b;
        a = src[2];
        b = src[3];
        *(u32 *)(g + 0x3C) = a;
        *(u32 *)(g + 0x40) = b;
        a = src[4];
        b = src[5];
        *(u32 *)(g + 0x44) = a;
        *(u32 *)(g + 0x48) = b;
        a = src[6];
        b = src[7];
        *(u32 *)(g + 0x4C) = a;
        *(u32 *)(g + 0x50) = b;
    } else {
        fn_80006298(*(u8 **)&gPrim2D + 0x34, 0, 0x2C);
        if ((arg1 & 3) == 0) {
            arg1 &= 0xFFFC;
            tmp = arg1 | 2;
            arg1 = tmp & 0xFFFF;
        }
    }
    (*(u8 **)&gPrim2D)[0x22] = 0xFF;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) &= 0xFFFF7B0C;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) |= arg1;
}
#pragma global_optimizer reset
void Prim2D_PrepareTex(void) {
    extern u16 gPrim2D;
    *(u8 *)(*(u8 **)&gPrim2D + 0xa8) = 2;
}

void Prim2D_Begin(void) {
*(u8 *)(*(u8 **)&gPrim2D+0xA8)=1;
}

u8 fn_8000A268(void) {
    return *(u8 *)(*(u8 **)&gPrim2D + 0xA9);
}

void fn_8000A274(u8 arg0) {
    *(u8 *)(*(u8 **)&gPrim2D + 0xa9) = arg0;
}

void fn_8000A280(void) {

}

void fn_8000A284(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    *(f32 *)(*(u8 **)&gPrim2D + 0x98) = arg0;
    *(f32 *)(*(u8 **)&gPrim2D + 0x94) = arg1;
    *(f32 *)(*(u8 **)&gPrim2D + 0xa0) = arg2;
    *(f32 *)(*(u8 **)&gPrim2D + 0x9c) = arg3;
}

#pragma global_optimizer off
void *fn_8000A2A8(u32 arg0)
{
  extern void *(*lbl_80366DA0)(u32);
  extern u16 gPrim2D;
  extern f32 gFloat1;
  extern f32 lbl_80368B98;
  extern f32 lbl_80368BB8;
  u32 n;
  void *p;
  u8 *new_var;
  f32 f0;
  f32 f1;
  f32 f2;
  if (arg0 == 0)
  {
    arg0 = 0xFFE0;
  }
  n = arg0 & (~7);
  p = lbl_80366DA0(n);
  *((void **) (&gPrim2D)) = p;
  f2 = gFloat1;
  *((void **) p) = p;
  f1 = lbl_80368BB8;
  new_var = ((u8 *) (*((void **) (&gPrim2D)))) + 4;
  f0 = lbl_80368B98;
  *((u32 *) new_var) = n;
  *((f32 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0x98)) = f2;
  *((f32 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0x94)) = f1;
  *((f32 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0xa0)) = f1;
  *((f32 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0x9c)) = f0;
  *((u32 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0x10)) = 0;
  *((u32 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0x14)) = 0;
  *((u16 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0x20)) = 0;
  *(((u8 *) (*((void **) (&gPrim2D)))) + 0xa9) = 0xFF;
  return *((void **) (&gPrim2D));
}
#pragma global_optimizer reset
void *fn_800C4638(s32, void *, s32);
void fn_8000A358(s32 arg0) {
    extern u8 lbl_80267C70[];
    fn_800C4638(arg0, lbl_80267C70 + 0x3A, 0);
}

void GfxEnt_ForEachKey(u32 arg0, void (*arg1)(void *, s32), s32 arg2) {
    extern u8 gProcesses[];
    u8 *var_r31;
    s32 var_r30;

    var_r31 = gProcesses;
    var_r30 = 0;
    do {
        if (*(u32 *)var_r31 == arg0) {
            arg1(var_r31, arg2);
        }
        var_r30 += 1;
        var_r31 += 0x70;
    } while (var_r30 < 0x100);
}

void Process_DecRef(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2E) = (u8) (M2C_FIELD(arg0, u8 *, 0x2E) - 1);
}

void fn_8000A408(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2E) = (u8) (M2C_FIELD(arg0, u8 *, 0x2E) + 1);
}

u8 fn_8000A418(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x2E);
}

void Process_RetreatStep(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2D) = (u8) (M2C_FIELD(arg0, u8 *, 0x2D) - 1);
}

void Process_AdvanceStep(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2D) = (u8) (M2C_FIELD(arg0, u8 *, 0x2D) + 1);
}

void fn_8000A440(s32 arg0, s32 arg1) {
    extern s32 gProcessOpcodeTables[];
    gProcessOpcodeTables[arg0] = arg1;
}

void fn_8000A454(Process *node, s32 *arg1, s32 *arg2) {
    struct ColorA454 {
        u32 rgba;
    };
    void fn_8014BB58(s32, s32, struct ColorA454, void *);
    extern u8 lbl_80267CB0[];
    struct ColorA454 color;
    s32 depth;

    if (node->next != 0) {
        fn_8000A454(node->next, arg1, arg2);
    }

    depth = *arg1;
    *(u32 *)&color = 0xFFFFFFFF;
    *arg1 = depth + 1;
    if (node->flags & 2) {
        *(u32 *)&color = 0xFFC0C0FF;
    }
    if (node->lock_cnt != 0) {
        *(u32 *)&color = 0xA0A0A0FF;
    }
    if ((node->flags & 4) && node->parent->lock_cnt != 0) {
        *(u32 *)&color = 0xA0A0A0FF;
    }
    if (node->pause != 0) {
        *(u32 *)&color = 0x4040FFFF;
    }

    fn_8014BB58((*arg1) * 8, (*arg2) * 8, color, node->name);
    if (node->post != 0) {
        s8 *start = (s8 *)node->name;
        s8 *p = start;
        while (*p++ != 0) {
        }
        fn_8014BB58(((p - start) + 1 + (*arg1)) * 8, (*arg2) * 8, color, lbl_80267CB0 + 0x76);
    }
    (*arg2)++;

    if (node->child != 0) {
        fn_8000A454(node->child, arg1, arg2);
    }
    (*arg1)--;
}

void fn_8000A860(void) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    void fn_8014BB58(s32, s32, s32 *, s32);
    void fn_8000A454(u32, s32 *, s32 *, s32);
    extern f32 lbl_80368BCC;
    extern f32 lbl_80368BD0;
    extern f32 lbl_80368BD4;
    extern s32 lbl_80368BC8;
    extern u32 lbl_802ADADC[];
    extern s32 lbl_802838C8[];

    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 i;

    sp10 = 1;
    spC = 0;
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_80368BCC, lbl_80368BCC, lbl_80368BD0, lbl_80368BD4);
    Prim2D_PrepareTex();

    for (i = 0; i < 8; i++) {
        if (lbl_802ADADC[i] == 0) {
            continue;
        }
        sp8 = lbl_80368BC8;
        fn_8014BB58(0, spC * 8, &sp8, lbl_802838C8[i]);
        {
            s32 old = spC;
            spC = old + 1;
            fn_8000A454(lbl_802ADADC[i], &sp10, &spC, old);
        }
    }
}

s32 fn_8000A930(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2C) = (u8) (M2C_FIELD(arg0, u8 *, 0x2C) | 0x10);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

#pragma peephole on
