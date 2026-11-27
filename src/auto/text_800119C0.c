/* Functions from 0x800119C0 to 0x80016EE8, found by decomp-toolkit. */
#include "common.h"

static inline s32 Script_ReadSignedShort(void) {
    extern void *lbl_80367180;
    s32 value;
    value = *(*(s8 **)((u8 *)lbl_80367180 + 0xC))++;
    return (value << 8) + *(*(u8 **)((u8 *)lbl_80367180 + 0xC))++;
}
static inline void Script_PushWord(s32 value) {
    extern void *lbl_80367180;
    s32 *stack = (*(s32 **)((u8 *)lbl_80367180 + 0x18))++;
    *stack = value;
}

u16 *fn_800119C0(void) {
    extern u16 lbl_80267DC8[];
    return (u16 *)((u32)lbl_80267DC8 + 0x43);
}

s32 fn_800119D0(void) {
    return 0x18;
}

s32 fn_800119D8(void) {
    return 0x18;
}

void *fn_800119E0(void *arg0, s16 arg1) {
    void FileCache_ReleaseSlot(void *);
    void Heap_Free(void *);
    extern u16 lbl_80283EFC[];
    extern u16 lbl_80283948[];

    if (arg0 != NULL) {
        M2C_FIELD(arg0, void **, 0) = lbl_80283EFC;
        if (arg0 != NULL) {
            M2C_FIELD(arg0, void **, 0) = lbl_80283948;
            if (M2C_FIELD(arg0, u32 *, 4) != 0) {
                struct { void *vt; u32 unk4; } *p;
                p = arg0;
                FileCache_ReleaseSlot(&p->unk4);
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_80011A5C(void *arg0) {
extern s32 lbl_80367180;
u32 result; u32 *stack;
*(u32 **)((u8 *)lbl_80367180+0x18) -= *(s8 *)((u8 *)arg0+0xD);
switch (*(s8 *)((u8 *)arg0+0xD)) {
case 0:

result= ((u32 (*)(void))*(void **)((u8 *)arg0+4))();
stack=(*(u32 **)((u8 *)lbl_80367180+0x18))++;
*stack=result;
break;
case 1:
stack=*(u32 **)((u8 *)lbl_80367180+0x18);
result= ((u32 (*)(u32))*(void **)((u8 *)arg0+4))(stack[0]);
stack=(*(u32 **)((u8 *)lbl_80367180+0x18))++;
*stack=result;
break;
case 2:
stack=*(u32 **)((u8 *)lbl_80367180+0x18);
result= ((u32 (*)(u32,u32))*(void **)((u8 *)arg0+4))(stack[0],stack[1]);
stack=(*(u32 **)((u8 *)lbl_80367180+0x18))++;
*stack=result;
break;
case 3:
stack=*(u32 **)((u8 *)lbl_80367180+0x18);
result= ((u32 (*)(u32,u32,u32))*(void **)((u8 *)arg0+4))(stack[0],stack[1],stack[2]);
stack=(*(u32 **)((u8 *)lbl_80367180+0x18))++;
*stack=result;
break;
case 4:
stack=*(u32 **)((u8 *)lbl_80367180+0x18);
result= ((u32 (*)(u32,u32,u32,u32))*(void **)((u8 *)arg0+4))(stack[0],stack[1],stack[2],stack[3]);
stack=(*(u32 **)((u8 *)lbl_80367180+0x18))++;
*stack=result;
break;
case 5:
stack=*(u32 **)((u8 *)lbl_80367180+0x18);
result= ((u32 (*)(u32,u32,u32,u32,u32))*(void **)((u8 *)arg0+4))(stack[0],stack[1],stack[2],stack[3],stack[4]);
stack=(*(u32 **)((u8 *)lbl_80367180+0x18))++;
*stack=result;
break;
case 6:
stack=*(u32 **)((u8 *)lbl_80367180+0x18);
result= ((u32 (*)(u32,u32,u32,u32,u32,u32))*(void **)((u8 *)arg0+4))(stack[0],stack[1],stack[2],stack[3],stack[4],stack[5]);
stack=(*(u32 **)((u8 *)lbl_80367180+0x18))++;
*stack=result;
break;
case 7:
stack=*(u32 **)((u8 *)lbl_80367180+0x18);
result= ((u32 (*)(u32,u32,u32,u32,u32,u32,u32))*(void **)((u8 *)arg0+4))(stack[0],stack[1],stack[2],stack[3],stack[4],stack[5],stack[6]);
stack=(*(u32 **)((u8 *)lbl_80367180+0x18))++;
*stack=result;
break;
case 8:
stack=*(u32 **)((u8 *)lbl_80367180+0x18);
result= ((u32 (*)(u32,u32,u32,u32,u32,u32,u32,u32))*(void **)((u8 *)arg0+4))(stack[0],stack[1],stack[2],stack[3],stack[4],stack[5],stack[6],stack[7]);
stack=(*(u32 **)((u8 *)lbl_80367180+0x18))++;
*stack=result;
break;
case 9:
stack=*(u32 **)((u8 *)lbl_80367180+0x18);
result= ((u32 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32))*(void **)((u8 *)arg0+4))(stack[0],stack[1],stack[2],stack[3],stack[4],stack[5],stack[6],stack[7],stack[8]);
stack=(*(u32 **)((u8 *)lbl_80367180+0x18))++;
*stack=result;
break;
}
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_strength_reduction off
void fn_80011D20(void)
{
  extern void *lbl_80367180;
  extern void *lbl_803671A4;
  extern void *lbl_80367198;
  void *Res_GetByName(void *);
  void fn_80011A5C(void *);
  void fn_800142B0(s32);
  s32 index;
  void *ctx;
  void *script;
  void *inner;
  u8 *code;
  void *resource;
  s32 *stack;
  s32 base;
  s32 i;
  s32 *p;
  s32 zero;
  void *table;
  s32 val;
  s32 count;
  s32 size;
  s32 sp;
  s32 tidx;
  index = Script_ReadSignedShort();
  inner = *((void **) (((u8 *) lbl_80367180) + 8));
  resource = *((void **) (((u8 *) inner) + 8));
  resource = *((void **) (((u8 *) resource) + 0x24));
  script = Res_GetByName(((u8 *) resource) + index);
  code = (*((u8 **) (((u8 *) lbl_80367180) + 0xC)))++;
  count = (s8) (*code);
  if (script == NULL)
  {
    ctx = lbl_80367180;
    zero = 0;
    *((s32 *) (((u8 *) ctx) + 0x18)) = (*((s32 *) (((u8 *) ctx) + 0x18))) - (count << 2);
    Script_PushWord(0);
    fn_800142B0(0);
    return;
  }
  inner = *((void **) (((u8 *) script) + 8));
  if (inner == NULL)
  {
    fn_80011A5C(script);
    return;
  }
  ctx = lbl_80367180;
  if (ctx == NULL)
  {
    ctx = lbl_803671A4;
  }
  i = (s8) (*((u8 *) (((u8 *) script) + 0xD)));
  zero = 0;
  size = *((s16 *) (((u8 *) script) + 0x12));
  sp = *((s32 *) (((u8 *) ctx) + 0x18));
  i = i << 2;
  tidx = *((u16 *) (((u8 *) inner) + 0x20));
  base = sp - i;
  size = base + (size << 2);
  table = lbl_80367198;
  *((s32 *) (((u8 *) ctx) + 0x18)) = size;
  table = ((u8 *) table) + ((tidx << 1) << 1);
  i = (s8) (*((u8 *) (((u8 *) script) + 0xD)));
  p = (s32 *) (base + (i << 2));
  while (i < (*((s16 *) (((u8 *) script) + 0x12))))
  {
    *p = zero;
    p += 1;
    i += 1;
  }

  lbl_80367180 = ctx;
  Script_PushWord(*((s32 *) (((u8 *) ctx) + 0xC)));
  Script_PushWord(*((s32 *) (((u8 *) ctx) + 8)));
  Script_PushWord(*((s32 *) (((u8 *) ctx) + 0x10)));
  Script_PushWord(*((s32 *) (((u8 *) ctx) + 0x14)));
  *((s32 *) (((u8 *) ctx) + 0xC)) = *((s32 *) (((u8 *) script) + 4));
  *((void **) (((u8 *) ctx) + 0x8)) = script;
  *((void **) (((u8 *) ctx) + 0x10)) = table;
  *((s32 *) (((u8 *) ctx) + 0x14)) = base;
}
#pragma pop
void fn_80011EDC(void *arg0)
{
    void fn_800142B0(s32);
    void fn_80011D20(void);
    void DebugPrint(char *, ...);
    extern void *lbl_80367180;
    extern void *lbl_80367198;
    extern void *lbl_803671A4;
    extern char lbl_80267E20[];
    u8 *ctx;
    u8 *pc;
    u8 *scene;
    u8 *file;
    u8 *text1;
    u8 *text2;
    u32 *sp;
    u32 *base;
    u32 *array;
    u32 *frame;
    u32 *dst;
    u32 value;
    u32 left;
    u32 right;
    u32 result;
    u32 op;
    s32 index;
    s32 n;
    s32 count;
    s32 i;

    lbl_80367180 = arg0;
    *((u8 *)arg0 + 0x1C) = 0;
    fn_800142B0(0);

    for (;;) {
        ctx = (u8 *)lbl_80367180;
        if ((s8)ctx[0x1C] != 0) {
            break;
        }
        pc = *(u8 **)(ctx + 0xC);
        *(u8 **)(ctx + 0xC) = pc + 1;
        op = *pc;
        if (op > 0x41) {
            continue;
        }
        switch (op) {
        case 0x00: /* nop */
            break;
        case 0x01: { /* val.8 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            base = *(u32 **)(ctx + 0x14);
            result = base[index];
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x02: { /* val.16 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            base = *(u32 **)(ctx + 0x14);
            result = base[index];
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x03: { /* valx.8 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            base = *(u32 **)(ctx + 0x14);
            index += (s32)value;
            result = base[index];
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x04: { /* valx.16 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            base = *(u32 **)(ctx + 0x14);
            index += (s32)value;
            result = base[index];
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x05: { /* valy.8 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            base = *(u32 **)(ctx + 0x14);
            array = (u32 *)base[index];
            result = array[(s32)value];
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x06: { /* valy.16 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            base = *(u32 **)(ctx + 0x14);
            array = (u32 *)base[index];
            result = array[(s32)value];
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x07: { /* ref.8 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            base = *(u32 **)(ctx + 0x14);
            result = (u32)(base + index);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x08: { /* ref.16 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            base = *(u32 **)(ctx + 0x14);
            result = (u32)(base + index);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x09: { /* refx.8 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            base = *(u32 **)(ctx + 0x14);
            index += (s32)value;
            result = (u32)(base + index);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x0A: { /* refx.16 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            base = *(u32 **)(ctx + 0x14);
            index += (s32)value;
            result = (u32)(base + index);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x0B: { /* refy.8 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            base = *(u32 **)(ctx + 0x14);
            array = (u32 *)base[index];
            result = (u32)(array + (s32)value);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x0C: { /* refy.16 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            base = *(u32 **)(ctx + 0x14);
            array = (u32 *)base[index];
            result = (u32)(array + (s32)value);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x0D: { /* gval.8 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            base = (u32 *)lbl_80367198;
            result = base[index];
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x0E: { /* gval.16 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            base = (u32 *)lbl_80367198;
            result = base[index];
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x0F: { /* gvalx.8 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            base = (u32 *)lbl_80367198;
            index += (s32)value;
            result = base[index];
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x10: { /* gvalx.16 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            base = (u32 *)lbl_80367198;
            index += (s32)value;
            result = base[index];
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x11: { /* gvaly.8 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            base = (u32 *)lbl_80367198;
            array = (u32 *)base[index];
            result = array[(s32)value];
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x12: { /* gvaly.16 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            base = (u32 *)lbl_80367198;
            array = (u32 *)base[index];
            result = array[(s32)value];
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x13: { /* gref.8 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            base = (u32 *)lbl_80367198;
            result = (u32)(base + index);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x14: { /* gref.16 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            base = (u32 *)lbl_80367198;
            result = (u32)(base + index);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x15: { /* grefx.8 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            base = (u32 *)lbl_80367198;
            index += (s32)value;
            result = (u32)(base + index);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x16: { /* grefx.16 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            base = (u32 *)lbl_80367198;
            index += (s32)value;
            result = (u32)(base + index);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x17: { /* grefy.8 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            base = (u32 *)lbl_80367198;
            array = (u32 *)base[index];
            result = (u32)(array + (s32)value);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x18: { /* grefy.16 */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            base = (u32 *)lbl_80367198;
            array = (u32 *)base[index];
            result = (u32)(array + (s32)value);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x19: { /* number.8 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(index);
            break;
        }
        case 0x1A: { /* number.16 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(index);
            break;
        }
        case 0x1B: { /* number.32 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(index);
            break;
        }
        case 0x1C: { /* string.8 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            file = *(u8 **)(ctx + 8);
            file = *(u8 **)(file + 8);
            file = *(u8 **)(file + 0x24);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(file + index);
            break;
        }
        case 0x1D: { /* string.16 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            file = *(u8 **)(ctx + 8);
            file = *(u8 **)(file + 8);
            file = *(u8 **)(file + 0x24);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(file + index);
            break;
        }
        case 0x1E: { /* string.32 */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            file = *(u8 **)(ctx + 8);
            file = *(u8 **)(file + 8);
            file = *(u8 **)(file + 0x24);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(file + index);
            break;
        }
        case 0x1F: { /* deref */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            result = *(u32 *)sp[-1];
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = result;
            break;
        }
        case 0x20: { /* disc */
            ctx = (u8 *)lbl_80367180;
            *(u32 **)(ctx + 0x18) -= 1;
            break;
        }
        case 0x21: { /* store */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            *(u32 *)left = value;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(value);
            break;
        }
        case 0x22: { /* add */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = left + right;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x23: { /* sub */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = (s32)left - (s32)right;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x24: { /* mul */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = left * right;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x25: { /* div */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = (s32)left / (s32)right;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x26: { /* mod */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = (s32)left % (s32)right;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x27: { /* neg */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            result = (u32)-(s32)right;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x28: { /* mvn */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            result = ~right;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x29: { /* not */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            result = (right == 0);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x2A: { /* orr */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = left | right;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x2B: { /* and */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = left & right;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x2C: { /* xor */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = left ^ right;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x2D: { /* lsl */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = left << right;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x2E: { /* lsr */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = (s32)left >> right;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x2F: { /* eq */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = (left == right);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x30: { /* ne */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = (left != right);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x31: { /* lt */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = ((s32)left < (s32)right);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x32: { /* le */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = ((s32)left <= (s32)right);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x33: { /* gt */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = ((s32)left > (s32)right);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x34: { /* ge */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            result = ((s32)left >= (s32)right);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x35: { /* eqstr */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            text1 = (u8 *)left;
            text2 = (u8 *)right;
            while ((s8)*text1 == (s8)*text2 && (s8)*text1 != 0) {
                text1++;
                text2++;
            }
            result = ((s8)*text1 == (s8)*text2);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x36: { /* nestr */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            right = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            left = *sp;
            text1 = (u8 *)left;
            text2 = (u8 *)right;
            while ((s8)*text1 == (s8)*text2 && (s8)*text1 != 0) {
                text1++;
                text2++;
            }
            result = ((s8)*text1 != (s8)*text2);
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(result);
            break;
        }
        case 0x37: { /* call.loc */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            file = *(u8 **)((u8 *)arg0 + 8);
            file = *(u8 **)(file + 8);
            scene = ((u8 **)*(u8 **)(file + 0x28))[index];
            ctx = (u8 *)arg0;
            if (ctx == 0) {
                ctx = (u8 *)lbl_803671A4;
            }
            count = (s8)scene[0xD];
            n = *(s16 *)(scene + 0x12);
            sp = *(u32 **)(ctx + 0x18);
            base = sp - count;
            *(u32 **)(ctx + 0x18) = base + n;
            file = *(u8 **)(scene + 8);
            dst = (u32 *)lbl_80367198 + *(u16 *)(file + 0x20);
            sp = base + count;
            for (i = count; i < n; ++i) {
                *sp++ = 0;
            }
            lbl_80367180 = ctx;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = *(u32 *)(ctx + 0xC);
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = *(u32 *)(ctx + 8);
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = *(u32 *)(ctx + 0x10);
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = *(u32 *)(ctx + 0x14);
            *(u32 *)(ctx + 0xC) = *(u32 *)(scene + 4);
            *(u8 **)(ctx + 8) = scene;
            *(u32 **)(ctx + 0x10) = dst;
            *(u32 **)(ctx + 0x14) = base;
            break;
        }
        case 0x38: { /* call.ext */
            fn_80011D20();
            break;
        }
        case 0x39: { /* ret */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            ctx = (u8 *)lbl_80367180;
            scene = *(u8 **)(ctx + 8);
            n = *(s16 *)(scene + 0x12);
            sp = *(u32 **)(ctx + 0x14) + n + 4;
            *(u32 **)(ctx + 0x18) = sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            *(u32 *)(ctx + 0x14) = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            *(u32 *)(ctx + 0x10) = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            *(u32 *)(ctx + 0x8) = *sp;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            *(u32 *)(ctx + 0xC) = *sp;
            ctx = (u8 *)lbl_80367180;
            *(u32 **)(ctx + 0x18) -= n;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18);
            *(u32 **)(ctx + 0x18) = sp + 1;
            *sp = (u32)(value);
            if (*(u8 **)((u8 *)lbl_80367180 + 0xC) == 0) {
                return;
            }
            break;
        }
        case 0x3A: { /* b */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (index << 8) + *pc;
            ctx = (u8 *)lbl_80367180;
            *(u8 **)(ctx + 0xC) += index - 2;
            break;
        }
        case 0x3B: { /* by */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            if (value == 0) {
                *(u8 **)((u8 *)lbl_80367180 + 0xC) += 2;
            } else {
                pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
                *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
                index = (s8)*pc;
                pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
                *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
                index = (index << 8) + *pc;
                *(u8 **)((u8 *)lbl_80367180 + 0xC) += index - 2;
            }
            break;
        }
        case 0x3C: { /* bky */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            if (value == 0) {
                *(u8 **)((u8 *)lbl_80367180 + 0xC) += 2;
            } else {
                ctx = (u8 *)lbl_80367180;
                sp = *(u32 **)(ctx + 0x18);
                *(u32 **)(ctx + 0x18) = sp + 1;
                *sp = (u32)(1);
                pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
                *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
                index = (s8)*pc;
                pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
                *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
                index = (index << 8) + *pc;
                *(u8 **)((u8 *)lbl_80367180 + 0xC) += index - 2;
            }
            break;
        }
        case 0x3D: { /* bn */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            if (value != 0) {
                *(u8 **)((u8 *)lbl_80367180 + 0xC) += 2;
            } else {
                pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
                *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
                index = (s8)*pc;
                pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
                *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
                index = (index << 8) + *pc;
                *(u8 **)((u8 *)lbl_80367180 + 0xC) += index - 2;
            }
            break;
        }
        case 0x3E: { /* bkn */
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - 1;
            *(u32 **)(ctx + 0x18) = sp;
            value = *sp;
            if (value != 0) {
                *(u8 **)((u8 *)lbl_80367180 + 0xC) += 2;
            } else {
                ctx = (u8 *)lbl_80367180;
                sp = *(u32 **)(ctx + 0x18);
                *(u32 **)(ctx + 0x18) = sp + 1;
                *sp = (u32)(0);
                pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
                *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
                index = (s8)*pc;
                pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
                *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
                index = (index << 8) + *pc;
                *(u8 **)((u8 *)lbl_80367180 + 0xC) += index - 2;
            }
            break;
        }
        case 0x3F: { /* yield */
            ctx = (u8 *)lbl_80367180;
            ctx[0x1C] = 1;
            break;
        }
        case 0x40: { /* dummy */
            ctx = (u8 *)lbl_80367180;
            pc = *(u8 **)(ctx + 0xC);
            *(u8 **)(ctx + 0xC) = pc + 1;
            pc = *(u8 **)(ctx + 0xC);
            *(u8 **)(ctx + 0xC) = pc + 1;
            pc = *(u8 **)(ctx + 0xC);
            *(u8 **)(ctx + 0xC) = pc + 1;
            pc = *(u8 **)(ctx + 0xC);
            *(u8 **)(ctx + 0xC) = pc + 1;
            break;
        }
        case 0x41: { /* printf */
            pc = *(u8 **)((u8 *)lbl_80367180 + 0xC);
            *(u8 **)((u8 *)lbl_80367180 + 0xC) = pc + 1;
            index = (s8)*pc;
            ctx = (u8 *)lbl_80367180;
            sp = *(u32 **)(ctx + 0x18) - index;
            *(u32 **)(ctx + 0x18) = sp;
            if ((u32)index <= 9) {
                switch (index) {
                case 0:
                    DebugPrint((char *)sp[0]);
                    break;
                case 1:
                    DebugPrint((char *)sp[0]);
                    break;
                case 2:
                    DebugPrint((char *)sp[0], sp[1]);
                    break;
                case 3:
                    DebugPrint((char *)sp[0], sp[1], sp[2]);
                    break;
                case 4:
                    DebugPrint((char *)sp[0], sp[1], sp[2], sp[3]);
                    break;
                case 5:
                    DebugPrint((char *)sp[0], sp[1], sp[2], sp[3], sp[4]);
                    break;
                case 6:
                    DebugPrint((char *)sp[0], sp[1], sp[2], sp[3], sp[4], sp[5]);
                    break;
                case 7:
                    DebugPrint((char *)sp[0], sp[1], sp[2], sp[3], sp[4], sp[5], sp[6]);
                    break;
                case 8:
                    DebugPrint((char *)sp[0], sp[1], sp[2], sp[3], sp[4], sp[5], sp[6], sp[7]);
                    break;
                default:
                    DebugPrint((char *)sp[0], sp[1], sp[2], sp[3], sp[4], sp[5], sp[6], sp[7], sp[8]);
                    break;
                }
            }
            DebugPrint(lbl_80267E20);
            break;
        }
        default:
            break;
        }
    }

    ctx = (u8 *)lbl_80367180;
    if ((s8)ctx[0x1C] != 0) {
        sp = *(u32 **)(ctx + 0x18);
        *(u32 **)(ctx + 0x18) = sp + 1;
        *sp = 0;
        fn_800142B0(6);
    }
}

#pragma push
#pragma global_optimizer on
#pragma scheduling on
void fn_80013778(void *arg0, u8 *arg1) {
    extern void *lbl_803671A4;
    extern void *lbl_80367198;
    extern void *lbl_80367180;

    void *table;
    void *ctx;
    s32 *p;
    s32 *sp;
    s32 val;
    s32 base;
    s32 unk18;
    s32 i;
    s32 zero;
    s16 lim;
    s8 d;
    u8 b;

    if (arg0 != 0) {
    } else {
        arg0 = lbl_803671A4;
    }

    b = arg1[0xd];
    zero = 0;
    d = b;
    lim = *(s16 *)(arg1 + 0x12);
    unk18 = *(s32 *)((u8 *)arg0 + 0x18);
    base = unk18 - (d << 2);
    table = (void *)((u8 *)lbl_80367198 + (*(u16 *)(*(u8 **)(arg1 + 8) + 0x20) << 2));
    *(s32 *)((u8 *)arg0 + 0x18) = base + (lim << 2);

    i = (s8)arg1[0xd];
    p = (s32 *)(base + (i << 2));
    while (i < *(s16 *)(arg1 + 0x12)) {
        *p = zero;
        p += 1;
        i += 1;
    }

    lbl_80367180 = arg0;

    sp = *(s32 **)((u8 *)arg0 + 0x18);
    val = *(s32 *)((u8 *)arg0 + 0xc);
    *(s32 **)((u8 *)arg0 + 0x18) = (s32 *)((u8 *)sp + 4);
    *sp = val;

    ctx = lbl_80367180;
    val = *(s32 *)((u8 *)arg0 + 0x8);
    sp = *(s32 **)((u8 *)ctx + 0x18);
    *(s32 **)((u8 *)ctx + 0x18) = (s32 *)((u8 *)sp + 4);
    *sp = val;

    ctx = lbl_80367180;
    val = *(s32 *)((u8 *)arg0 + 0x10);
    sp = *(s32 **)((u8 *)ctx + 0x18);
    *(s32 **)((u8 *)ctx + 0x18) = (s32 *)((u8 *)sp + 4);
    *sp = val;

    ctx = lbl_80367180;
    val = *(s32 *)((u8 *)arg0 + 0x14);
    sp = *(s32 **)((u8 *)ctx + 0x18);
    *(s32 **)((u8 *)ctx + 0x18) = (s32 *)((u8 *)sp + 4);
    *sp = val;

    *(s32 *)((u8 *)arg0 + 0xc) = *(s32 *)(arg1 + 4);
    *(void **)((u8 *)arg0 + 0x8) = arg1;
    *(void **)((u8 *)arg0 + 0x10) = table;
    *(s32 *)((u8 *)arg0 + 0x14) = base;
}
#pragma pop
void fn_80013864(void) {
    extern void *lbl_803671A4;
    M2C_FIELD(lbl_803671A4, s8 *, 0x1C) = 1;
}

void fn_80013874(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x1C) = 1;
}

s32 fn_80013880(void) {
    extern s32 lbl_80367180;
    extern s32 lbl_803671A4;
    u8 *context;
    u32 *stack;
    s32 fn_80011EDC();
    lbl_80367180 = lbl_803671A4;
    fn_80011EDC(lbl_80367180);
    context = (u8 *)lbl_80367180;
    stack = *(u32 **)(context + 0x18) - 1;
    *(u32 **)(context + 0x18) = stack;
    return (s32)*stack;
}

s32 fn_800138BC(void *arg0) {
    extern s32 lbl_80367180;
    u8 *context;
    u32 *stack;
    s32 fn_80011EDC();

    lbl_80367180 = (s32)arg0;
    fn_80011EDC();
    context = (u8 *)lbl_80367180;
    stack = *(u32 **)(context + 0x18) - 1;
    *(u32 **)(context + 0x18) = stack;
    return (s32)*stack;
}

#pragma push
#pragma opt_propagation off
u32 ScriptCtx_Call(void) {
#pragma dont_inline on
    void fn_800142B0(s32);
    void fn_80011A5C(void *);
    void fn_80011EDC(void *);
    extern void *lbl_80367184;
    extern void *lbl_80367180;
    extern void *lbl_8036718C;
    extern void *lbl_803671A4;
    extern void *lbl_80367198;
    void *command;
    void *context;
    s32 *base;
    s32 i;
    void *table;

    fn_800142B0(0);
    command = lbl_80367184;
    if (command == NULL) {
        *(void **)((u8 *)lbl_80367180 + 0x18) = lbl_8036718C;
        fn_800142B0(5);
        return 0;
    }
    if (*(void **)((u8 *)command + 8) == NULL) {
        fn_80011A5C(command);
        return *--(*(u32 **)((u8 *)lbl_80367180 + 0x18));
    }
    if ((context = lbl_80367180) == NULL) {
        context = lbl_803671A4;
    }
    base = *(s32 **)((u8 *)context + 0x18) - *(s8 *)((u8 *)command + 0xD);
    table = (u32 *)lbl_80367198 + *(u16 *)(*(u8 **)((u8 *)command + 8) + 0x20);
    *(s32 **)((u8 *)context + 0x18) = base + *(s16 *)((u8 *)command + 0x12);
    for (i = *(s8 *)((u8 *)command + 0xD); i < *(s16 *)((u8 *)command + 0x12); i++) {
        base[i] = 0;
    }
    lbl_80367180 = context;
    *(*(s32 **)((u8 *)context + 0x18))++ = *(s32 *)((u8 *)context + 0xC);
    *(*(s32 **)((u8 *)lbl_80367180 + 0x18))++ = *(s32 *)((u8 *)context + 0x8);
    *(*(s32 **)((u8 *)lbl_80367180 + 0x18))++ = *(s32 *)((u8 *)context + 0x10);
    *(*(s32 **)((u8 *)lbl_80367180 + 0x18))++ = *(s32 *)((u8 *)context + 0x14);
    *(s32 *)((u8 *)context + 0xC) = *(s32 *)((u8 *)command + 4);
    *(void **)((u8 *)context + 0x8) = command;
    *(void **)((u8 *)context + 0x10) = table;
    *(s32 **)((u8 *)context + 0x14) = base;
    fn_80011EDC(lbl_80367180);
    return *--(*(u32 **)((u8 *)lbl_80367180 + 0x18));
}
#pragma pop
#pragma dont_inline on
void ScriptCtx_Push(s32 arg0) {
    extern u8 *lbl_80367180;
    extern s32 lbl_80367188;

    s32 **top;

    top = (s32 **)(lbl_80367180 + 0x18);
    *(*top)++ = arg0;

    lbl_80367188++;
}

#pragma scheduling reset
s32 ScriptCtx_Begin(void *arg0) {
    extern s32 lbl_803671A4;
    extern s32 lbl_80367180;
    extern s32 lbl_8036718C;
    extern s32 lbl_80367184;
    extern s32 lbl_80367188;
    u32 Res_GetByName(void *);
    void fn_800142B0(s32);

    u32 result;
    s32 context;
    s32 zero;

    context = lbl_803671A4;
    lbl_80367180 = context;
    lbl_8036718C = *(s32 *)((u8 *)context + 0x18);
    result = Res_GetByName(arg0);
    lbl_80367184 = result;
    if (result == 0U) {
        fn_800142B0(5);
        return 0;
    }
    zero = 0;
    lbl_80367188 = zero;
    return 1;
}

#pragma global_optimizer off
s32 Script_RegisterCommand(void *arg0, void *arg1, u8 arg2)
{
    extern s16 lbl_8036719E;
    extern s16 lbl_8036719C;
    extern u8 *lbl_803671A0;
    extern s32 gCmScriptStatus;
    void fn_8000D3EC(void *, void *);
    s32 index;
    s32 nextRaw;
    u8 *base;
    u8 *entry;

    index = lbl_8036719E;
    nextRaw = index + 1;
    base = lbl_803671A0;
    entry = base + (index << 4);
    lbl_8036719E = nextRaw;
    if ((s16)nextRaw > lbl_8036719C) {
        gCmScriptStatus = 9;
        return 0;
    }
    *(void **)(entry + 0) = arg0;
    *(void **)(entry + 4) = arg1;
    *(u32 *)(entry + 8) = 0;
    entry[0xD] = arg2;
    entry[0xC] = 0;
    fn_8000D3EC(arg0, entry);
    return 1;
}
#pragma global_optimizer on
u32 Event_NextEntry(void *arg0) {
    extern void *gCmScriptList;
    void *owner;
    void *p;
    u32 ret;

    if (arg0 == NULL) {
        return **(u32 **)((u8 *)gCmScriptList + 0x28);
    }
    owner = *(void **)((u8 *)arg0 + 8);
    ret = (*(u32 **)((u8 *)owner + 0x28))[*(s16 *)((u8 *)arg0 + 0x10) + 1];
    if (ret != 0) {
        return ret;
    }
    for (p = *(void **)((u8 *)owner + 0x1C); p != NULL; p = *(void **)((u8 *)p + 0x1C)) {
        if ((s32)*(u8 *)((u8 *)p + 3) != 0x53) {
            break;
        }
    }
    if (p == NULL) {
        return 0;
    }
    return **(u32 **)((u8 *)p + 0x28);
}

void ScriptCmd_CmWakeupScripts(void) {
    extern void *gCmScriptList;
    void fn_8000D3EC(void *, void *);

    void *name;
    s32 offset;
    void *entry;
    u8 *node;

    node = (u8 *)gCmScriptList;
    while (node != NULL) {
        if ((s32)node[0] == 'c' && (s32)node[1] == 'm' &&
            (s32)node[2] == 'b' && (s32)node[3] == 'S') {
            offset = 0;
            node[3] = ' ';

            for (;;) {
                entry = *(void **)(*(u8 **)(node + 0x28) + offset);
                if (entry == NULL) {
                    break;
                }

                name = *(void **)entry;
                if (name != NULL) {
                    fn_8000D3EC(name, entry);
                }
                offset += 4;
            }
        }
        node = *(u8 **)(node + 0x1C);
    }
}

s32 ScriptCmd_CmSleepScript(char *name) {
    /* Mark a CM script sleeping (by name, or the last one) and unregister its hashed command names. */
    void Hash_Remove(void *);
    extern void *gCmScriptList;
    void *node;
    void *last;
    s32 i;
    u32 **entries;

    if (name == NULL || *name == 0) {
        last = gCmScriptList;
        while (M2C_FIELD(last, void **, 0x1C) != NULL) {
            last = M2C_FIELD(last, void **, 0x1C);
        }
        node = last;
        if (node == NULL) {
            return 0;
        }
    } else {
        for (node = gCmScriptList; node != NULL; node = M2C_FIELD(node, void **, 0x1C)) {
            if (Str_Cmp((u8 *)node + 4, name) == 0) {
                goto found;
            }
        }
        return 0;
    }
found:
    M2C_FIELD(node, u8 *, 3) = 'S';
    for (i = 0; ; i++) {
        entries = M2C_FIELD(node, u32 ***, 0x28);
        if (entries[i] == NULL) {
            break;
        }
        if (*entries[i] != 0) {
            Hash_Remove((void *)*entries[i]);
        }
    }
    return 1;
}

s32 ScriptCmd_CmFreeScript(void)
{
    /* Free the last loaded CM script: unregister its names, unlink it, and release its file. */
    extern void *gCmScriptList;
    extern u16 gCmScriptUsed;
    extern s32 gCmScriptStatus;
    extern void Hash_Remove(void *);
    extern void fn_8005C7E8(void *);

    u8 *node;
    u8 *prev;
    u8 *next;
    u8 *head;
    void *entry;
    void *name;
    s32 offset;

    node = (u8 *)gCmScriptList;
    gCmScriptStatus = 0;

    while ((next = *(u8 **)(node + 0x1C)) != 0) {
        node = next;
    }

    if (node == 0) {
        gCmScriptStatus = 1;
        return 0;
    }

    gCmScriptUsed -= *(u16 *)(node + 0x22);

    offset = 0;

    while (1) {
        entry = *(void **)(*(u8 **)(node + 0x28) + offset);

        if (entry == 0) {
            break;
        }

        name = *(void **)entry;

        if (name != 0) {
            Hash_Remove(name);
        }

        offset += 4;
    }

    head = (u8 *)gCmScriptList;

    if (head != node) {
        prev = head;
        while ((next = *(u8 **)(prev + 0x1C)) != node) {
            prev = next;
        }

        *(u32 *)(prev + 0x1C) = 0;
    }

    fn_8005C7E8(node);

    return 1;
}

s32 ScriptCmd_CmLoadScript(s32 arg0) {
    void fn_800140B4(void *, u8);
    u32 FileCache_GetFlags(s32);
    void *FileCache_Load(s32);
    void FileCache_OrFlags(s32, u32);
    extern void *gCmScriptList;
    extern s32 gCmScriptStatus;
    u32 loaded;
    u8 *p;
    u8 *node;
    u8 *next;
    u8 a,b,c;
    loaded=(FileCache_GetFlags(arg0)>>14)&1;
    p=FileCache_Load(arg0);
    if (!loaded) { a=p[26]; b=p[25]; c=p[24]; p[24]=p[27]; p[25]=a; p[26]=b; p[27]=c;
a=p[30]; b=p[29]; c=p[28]; p[28]=p[31]; p[29]=a; p[30]=b; p[31]=c;
a=p[0x22]; p[0x22]=p[0x23]; p[0x23]=a;
a=p[38]; b=p[37]; c=p[36]; p[36]=p[39]; p[37]=a; p[38]=b; p[39]=c;
a=p[42]; b=p[41]; c=p[40]; p[40]=p[43]; p[41]=a; p[42]=b; p[43]=c; }
    node=gCmScriptList;
    gCmScriptStatus=0;
    if (node==0) gCmScriptList=p;
    else {
        while ((next=*(u8 **)(node+0x1c))!=0) node=next;
        *(u8 **)(node+0x1c)=p;
    }
    fn_800140B4(p, loaded);
    FileCache_OrFlags(arg0,0x4000);
    return 1;
}

void fn_80013F48(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s8 *, 0x1C) = 0;
}

s32 fn_80013F6C(void *arg0, s32 arg1) {
    extern u8 lbl_80267E28[];
    extern s32 gCmScriptStatus;
    extern void *fn_800C4638(s32, void *, s32);

    gCmScriptStatus = 0;

    M2C_FIELD(arg0, void **, 0) =
        fn_800C4638(arg1 << 2, lbl_80267E28, 0);

    if (M2C_FIELD(arg0, void **, 0) == NULL) {
        gCmScriptStatus = 4;
        return 0;
    }

    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, void **, 0x18) =
        M2C_FIELD(arg0, void **, 0);

    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x0C) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;

    return 1;
}

s32 fn_80014000(s32 arg0, s32 arg1) {
void *fn_800C4638(s32, void *, s32);
extern u8 lbl_80267E28[];
extern s16 lbl_80367194, gCmScriptUsed, lbl_8036719C, lbl_8036719E;
extern s32 gCmScriptStatus, gCmScriptList;
extern void *lbl_80367198, *lbl_803671A0;
void *temp;
s32 size=arg0<<2;
gCmScriptStatus=0;
gCmScriptList=0;
lbl_80367194=arg0;
gCmScriptUsed=0;
temp=fn_800C4638(size,lbl_80267E28,0);
lbl_80367198=temp;
if(!temp) {gCmScriptStatus=4;return 0;}
lbl_8036719C=arg1;
lbl_8036719E=0;
temp=fn_800C4638(arg1<<4,lbl_80267E28,0);
lbl_803671A0=temp;
if(!temp) {gCmScriptStatus=4;return 0;}
return 1;
}

void fn_800140B4(void *arg0, u8 arg1) {
    void fn_8000D3EC(void *, void *);
    extern u16 gCmScriptUsed;
    extern u16 lbl_80367194;
    extern s32 gCmScriptStatus;

    s32 i;
    u8 *self;
    u8 *entry;
    u8 *walk;
    s32 j;
    u8 pd, pa, pb, pc;
    u8 d, a, b, c;
    u8 *p;
    void *ptr;

    self = (u8 *)arg0;
    if (arg1 != 0) {
        for (i = 0;; i += 4) {
            ptr = *(void **)(*(u8 **)(self + 0x28) + i);
            if (ptr == 0) {
                break;
            }
            if (*(void **)ptr != 0) {
                fn_8000D3EC(*(void **)ptr, ptr);
            }
        }
        return;
    }

    if (*(u32 *)(self + 0x24) != 0) {
        *(u32 *)(self + 0x24) = *(u32 *)(self + 0x24) + (u32)self;
    }
    if (*(u32 *)(self + 0x28) != 0) {
        *(u32 *)(self + 0x28) = *(u32 *)(self + 0x28) + (u32)self;
    }
    *(u16 *)(self + 0x20) = gCmScriptUsed;
    gCmScriptUsed = gCmScriptUsed + *(u16 *)(self + 0x22);
    if (gCmScriptUsed > lbl_80367194) {
        gCmScriptStatus = 8;
        return;
    }

    for (i = 0;; i += 4) {
        p = *(u8 **)(self + 0x28) + i;
        if (*(u32 *)p == 0) {
            break;
        }
        pa = p[2];
        pb = p[1];
        pc = p[0];
        pd = p[3];
        p[0] = pd;
        p[1] = pa;
        p[2] = pb;
        p[3] = pc;

        *(u32 *)(*(u8 **)(self + 0x28) + i) += (u32)self;
        entry = *(u8 **)(*(u8 **)(self + 0x28) + i);

        a = entry[2];
        b = entry[1];
        c = entry[0];
        d = entry[3];
        entry[0] = d;
        entry[1] = a;
        entry[2] = b;
        entry[3] = c;

        pa = entry[6];
        pb = entry[5];
        pc = entry[4];
        pd = entry[7];
        entry[4] = pd;
        entry[5] = pa;
        entry[6] = pb;
        entry[7] = pc;

        pa = entry[0x12];
        pd = entry[0x13];
        entry[0x12] = pd;
        entry[0x13] = pa;

        a = entry[0x10];
        d = entry[0x11];
        entry[0x10] = d;
        entry[0x11] = a;

        if ((s8)entry[0xC] != 0) {
            walk = entry;
            for (j = 0; j < (s8)entry[0xE];) {
                a = walk[0x14];
                j += 1;
                d = walk[0x15];
                walk[0x14] = d;
                walk[0x15] = a;
                walk += 2;
            }
        }

        *(void **)(entry + 8) = self;
        if (*(u32 *)entry != 0) {
            *(u32 *)entry = *(u32 *)entry + (u32)self;
            fn_8000D3EC(*(void **)entry, entry);
        }
        if (*(u32 *)(entry + 4) != 0) {
            *(u32 *)(entry + 4) = *(u32 *)(entry + 4) + (u32)self;
        }
    }
}

void fn_800142B0(s32 arg0) {
    extern s32 gCmScriptStatus;
    gCmScriptStatus = arg0;
}

s32 fn_800142B8(void) {
    extern s32 gCmScriptStatus;
    return gCmScriptStatus;
}

void fn_800142C0(s32 *arg0, s16 *arg1) {
    extern s16 lbl_8036719E;
    extern s32 lbl_803671A0;
    *arg0 = lbl_803671A0;
    *arg1 = lbl_8036719E;
}

s32 EventWork_Set(s32 arg0) {
    extern s32 lbl_803671A4;

    s32 oldValue;

    oldValue = lbl_803671A4;
    lbl_803671A4 = arg0;

    return oldValue;
}

void fn_800142E4(void) {
    void fn_8000A440(s32, void *);
    extern u8 lbl_80284098[];

    fn_8000A440(1, lbl_80284098);
}

s32 fn_80014310(void *arg0) {
    void *Process_AttachFunc(void *, void *);
    void *temp;
    void *val;

    temp = *(void **)((u8 *)arg0 + 4);
    val = *(void **)((u8 *)temp + 4);
    *(void **)((u8 *)arg0 + 4) = (void *) ((u8 *)temp + 8);
    Process_AttachFunc(val, arg0);
    return 1;
}

s32 fn_8001434C(void *arg0) {
    u8 fn_8005BB2C();
    if (fn_8005BB2C() == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_80014398(void *arg0) {
    s32 temp_r31;
    void *temp_r3;

    temp_r3 = *(void **)((u8 *)arg0 + 4);
    temp_r31 = *(s32 *)((u8 *)temp_r3 + 4);
    *(void **)((u8 *)arg0 + 4) = (void *) ((u8 *)temp_r3 + 8);
    if (Res_GetByName(temp_r31) == 0U) {
        return 1;
    }
    Event_StartByName(temp_r31, arg0);
    return 0;
}

s32 fn_80014400(void *arg0) {
    u32 Res_GetByName(s32);
    void Process_Goto(void *, s32);
    void *ptr;
    s16 hi;
    s32 word1;

    ptr = *(void **)((u8 *)arg0 + 4);
    hi = (s16)(*(u32 *)ptr >> 16);
    word1 = *(s32 *)((u8 *)ptr + 4);
    *(void **)((u8 *)arg0 + 4) = (u8 *)ptr + 8;
    if (Res_GetByName(word1) == 0U) {
        Process_Goto(arg0, hi & 0xFF);
    }
    return 1;
}

s32 fn_80014468(void *arg0) {
    u32 Res_GetByName(s32);
    void Process_Goto(void *, s32);
    void *ptr;
    s16 hi;
    s32 word1;

    ptr = *(void **)((u8 *)arg0 + 4);
    hi = (s16)(*(u32 *)ptr >> 16);
    word1 = *(s32 *)((u8 *)ptr + 4);
    *(void **)((u8 *)arg0 + 4) = (u8 *)ptr + 8;
    if (Res_GetByName(word1) != 0U) {
        Process_Goto(arg0, hi & 0xFF);
    }
    return 1;
}

s32 fn_800144D0(void *arg0) {
    u8 fn_80089640();
    if (fn_80089640() != 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_8001451C(void *arg0) {
    M2C_UNK fn_800C4B8C();
    fn_800C4B8C();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_80014558(void *arg0) {
    s32 Heap_Create(void *, void *);
    void *temp;
    void *a;
    void *b;

    temp = *(void **)((u8 *)arg0 + 4);
    b = *(void **)((u8 *)temp + 8);
    a = *(void **)((u8 *)temp + 4);
    *(void **)((u8 *)arg0 + 4) = (void *) ((u8 *)temp + 0xC);
    Heap_Create(a, b);
    return 1;
}

s32 fn_80014594(void *arg0) {
    u8 fn_8008A59C();
    if (fn_8008A59C() != 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_800145E0(void *arg0) {
    fn_8008A290((u8)(*(u32 *)*(void **)((u8 *)arg0 + 4) >> 16),
                 *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 4));
    *(void **)((u8 *)arg0 + 4) = (void *)((u8 *)*(void **)((u8 *)arg0 + 4) + 8);
    return 1;
}

s32 fn_8001462C(void *arg0) {
    void fn_8008A290(s32, s32);
    void *ptr;
    s32 index;

    ptr = *(void **)((u8 *)arg0 + 4);
    index = (u8)(*(u32 *)ptr >> 16);
    fn_8008A290(index, *(s32 *)((u8 *)ptr + 4));
    *(void **)((u8 *)arg0 + 4) = (void *)((u8 *)*(void **)((u8 *)arg0 + 4) + 8);
    return index != 7;
}

s32 fn_80014690(void *arg0)
{
    void DebugPrint(char *, ...);
    extern char lbl_80267FE8[];

    DebugPrint(
        lbl_80267FE8,
        arg0,
        *(u32 *)((u8 *)arg0 + 0x14),
        ((s32 **)arg0)[1][1]
    );
    ((s32 **)arg0)[1] = ((s32 **)arg0)[1] + 2;
    return 1;
}

extern s32 fn_8006785C(s16, s32, void *);
s32 fn_800146E8(void *arg0)
{
    s32 *temp_r3 = (s32 *)arg0;
    s32 *temp_r3_2 = (s32 *)temp_r3[1];
    s16 temp_r4 = (s16)((u32)temp_r3_2[0] >> 16);
    fn_8006785C(temp_r4, temp_r3_2[1], arg0);
    temp_r3[1] = (s32)((s32 *)temp_r3[1] + 2);
    return 1;
}

s32 fn_8001473C(void *arg0)
{
    s32 *temp_r3 = (s32 *)arg0;
    s32 *temp_r3_2 = (s32 *)temp_r3[1];
    s16 temp_r4 = (s16)((u32)temp_r3_2[0] >> 16);
    fn_8006785C(temp_r4, temp_r3_2[1], (void *)temp_r3_2[2]);
    temp_r3[1] = (s32)((s32 *)temp_r3[1] + 3);
    return 1;
}

void fn_80014790(void) {
    s32 DVDGetDriveStatus(void);
    s32 DVDKeepAlive(void);
    void fn_80212CC0(s32, s32);
    void fn_800B28DC(void);
    void fn_800B27BC(void);
    void fn_8020AC68(s32);
    s32 fn_801FBC30(s32);
    s32 fn_801FBAD4(void);
    s32 fn_801FB9E0(s32);
    void DEMOBeforeRender(void);
    void fn_802240F0(s32, void *, f32, f32, f32, f32);
    void fn_8022462C(s32);
    void fn_80224658(s32);
    void GXSetZMode(s32, s32, s32);
    void fn_802246B8(s32);
    void fn_80223E5C(s32, s32, s32, s32, s32);
    void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
    void GXSetProjection(void *, s32);
    void fn_8022100C(s32);
    void PSMTXIdentity(void *);
    void GXLoadPosMtxImm(void *, s32);
    void fn_80224DCC(void *, s32);
    void GXSetCurrentMtx(s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxDesc(s32, s32);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetChanMatColor(s32, void *);
    void GXSetNumTevStages(s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void GXSetNumChans(s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void GXBegin(s32, s32, s32);
    u32 *Ui_GetColor(s32);
    void fn_801FB5D8(void *, s32, f32, f32, f32, f32);
    void fn_8006E660(void);
    void VIWaitForRetrace(void);
    void fn_80025970(void);
    void Game_PollSoftReset(void);
    extern u8 *gPadInput;
    extern u8 lbl_803671B0;
    extern u32 gUiInputFlags;
    extern s32 lbl_803671B4;
    extern f32 lbl_80368C4C;
    extern u32 lbl_8036C400;
    extern f32 lbl_80368C50;
    extern f32 lbl_80368C54;
    extern f32 lbl_80368C58;
    extern u32 lbl_80368C48;
    extern f64 lbl_80368C68;
    extern f32 lbl_80368C5C;
    extern f32 lbl_80368C60;
    extern f32 lbl_80368C64;

    f32 ortho[4][4];
    f32 mtx[3][4];
    u32 clearColor;
    u32 uiColor;
    u32 matColor;
    s32 code;
    s32 status;
    s32 tmp28;
    s32 tmp29;
    s32 tmp30;
    f32 fw;
    f32 fh;
    f32 scale;
    f32 a60;
    f32 a64;

    for (;;) {
        code = -1;
        status = DVDGetDriveStatus();
        switch (status + 1) {
        case 6: code = 0; break;
        case 5: code = 1; break;
        case 7: code = 2; break;
        case 12: code = 3; break;
        case 0: code = 4; break;
        }

        if (code >= 0) {
            if (DVDKeepAlive() == 0) {
                lbl_803671B0 = 1;
                fn_80212CC0(gPadInput[0x1C], 2);
                goto after_ka;
            }
        }
        if (code < 0) {
            if (DVDKeepAlive() != 0) {
                lbl_803671B0 = 0;
            }
        }
    after_ka:

        if (code >= 0) {
            fn_800B28DC();
        } else {
            fn_800B27BC();
        }

        if (gUiInputFlags & 0x100) {
            lbl_803671B0 = 0;
        }

        if (lbl_803671B0 != 0 && code >= 0) {
            if (status == -1) {
                fn_8020AC68(lbl_803671B4);
            }
            tmp28 = fn_801FBC30(code);
            tmp29 = fn_801FBAD4();
            tmp30 = fn_801FB9E0(tmp28);
            DEMOBeforeRender();
            {
                f32 z = lbl_80368C4C;
                clearColor = lbl_8036C400;
                fn_802240F0(0, &clearColor, z, z, z, z);
            }
            fn_8022462C(1);
            fn_80224658(1);
            GXSetZMode(1, 3, 1);
            fn_802246B8(1);
            fn_80223E5C(7, 0, 1, 7, 0);
            C_MTXOrtho(ortho, lbl_80368C4C, lbl_80368C50, lbl_80368C4C, lbl_80368C54, lbl_80368C4C, lbl_80368C58);
            GXSetProjection(ortho, 1);
            fn_8022100C(0);
            PSMTXIdentity(mtx);
            GXLoadPosMtxImm(mtx, 0);
            fn_80224DCC(mtx, 0);
            GXSetCurrentMtx(0);
            fn_802245D8(1, 4, 5, 0);
            GXClearVtxDesc();
            GXSetVtxDesc(9, 1);
            GXSetVtxAttrFmt(0, 9, 1, 3, 0);
            GXSetCullMode(1);
            GXSetBlendMode(4, 0, 0, 0, 0, 0, 2);
            matColor = lbl_80368C48;
            GXSetChanMatColor(4, &matColor);
            GXSetNumTevStages(1);
            GXSetTevOrder(0, 0, 0, 4);
            GXSetNumTexGens(0, 4);
            GXSetNumChans(1);
            fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
            GXBegin(0x80, 0, 4);
            {
                s16 *fifo = (s16 *)0xCC008000;
                s16 z = 0;
                s16 a = 0x5A;
                s16 b = 0x260;
                s16 c = 0x1C0;
                *fifo = z;
                *fifo = z;
                *fifo = a;
                *fifo = b;
                *fifo = z;
                *fifo = a;
                *fifo = b;
                *fifo = c;
                *fifo = a;
                *fifo = z;
                *fifo = c;
                *fifo = a;
            }
            uiColor = *Ui_GetColor(1);
            scale = lbl_80368C5C;
            a60 = lbl_80368C60;
            a64 = lbl_80368C64;
            fw = (f32)(s32)(0x260 - tmp29);
            fh = (f32)(s32)(0x1C0 - tmp30);
            fn_801FB5D8(&uiColor, tmp28, fw * scale, a60, fh * scale, a64);
            fn_8006E660();
            if (status == -1) {
                VIWaitForRetrace();
                fn_80025970();
            }
            Game_PollSoftReset();
        } else {
            if (lbl_803671B0 != 0) {
                Game_PollSoftReset();
            }
            VIWaitForRetrace();
        }
    }
}

#pragma push
#pragma global_optimizer off
#pragma opt_propagation off
