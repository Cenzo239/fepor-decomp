/* Functions from 0x80006264 to 0x80011968, found by decomp-toolkit. */
#include "common.h"
#include "process.h"

static inline u8 *Process_FindCodeInPool(u32 value, u8 *p)
{
 s32 i;
 for(i=0;i<256;i++,p+=0x70) if(*(u32 *)p==value) return p;
 return 0;
}


static inline u32 Process_CompareName(const s8 *a, const s8 *b)
{
    while (*a | *b) {
        if (*a != *b) return *a - *b;
        a++;
        b++;
    }
    return 0;
}

static inline s32 GetKey_8000B39C(u32 *base)
{
    return (u8)(*base >> 16);
}

static inline s32 DecCounter_8000B39C(s32 counter)
{
    return counter - 1;
}

static inline u32 Process_CompareNameExt(const u8 *a, const u8 *b)
{
    s32 c2;
    s32 c1;
    u32 raw2;
    u32 raw1;
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

#pragma opt_unroll reset

#pragma global_optimizer off
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma global_optimizer reset
extern f64 lbl_80368C28;

#pragma global_optimizer off
#pragma scheduling off

#pragma scheduling reset
#pragma global_optimizer reset

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer on

#pragma use_lmw_stmw on

extern u16 gPrim2D;

/* Build XY(Z) translate and optional uniform scale into gPrim2D's matrix; store z and clear flag 0x800. */

#pragma peephole off

#pragma peephole on

#pragma optimization_level 3

#pragma optimization_level reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset
void *fn_800C4638(s32, void *, s32);

#pragma peephole on

#pragma peephole reset

s32 fn_8000AA60(void *arg0)
{
 void Process_Unlink(void *);
 void *entry = Process_FindName(*(s8 **)(*(u8 **)((u8 *)arg0 + 4) + 4));
 if(entry) Process_Unlink(entry);
 *(u32 *)((u8 *)arg0+4)+=8;
 return 1;
}

#pragma push
#pragma global_optimizer off
#pragma scheduling off
s32 fn_8000AB90(void *arg0) {
    extern u8 gProcesses[];
    u32 raw1;
    u32 raw2;
    s32 c1;
    s32 c2;
    u32 diff;
    u8 *a;
    u8 *b;
    s32 i;
    s32 n;
    u8 *entry;
    u8 *source;
    u8 *p;

    p = *(u8 **)((u8 *)arg0 + 4);
    source = *(u8 **)(p + 4);
    entry = gProcesses;
    n = 0;
    for (i = 0; i < 0x80; i++) {
        if (*(u32 *)entry != 0) {
            a = *(u8 **)(entry + 0x14);
            b = source;
            goto cmp1_ld;
        cmp1:
            if ((s8)raw1 != (s8)raw2) {
                diff = (u32)(c1 - c2);
                goto cmp1_done;
            }
            a += 1;
            b += 1;
        cmp1_ld:
            raw1 = *a;
            raw2 = *b;
            c1 = (s8)raw1;
            c2 = (s8)raw2;
            if ((c1 | c2) != 0) {
                goto cmp1;
            }
            diff = 0;
        cmp1_done:
            if (diff != 0) {
                goto skip1;
            }
            n = n + 0;
            goto found;
        skip1:
            ;
        }
        if (*(u32 *)(entry += 0x70) != 0) {
            b = source;
            a = *(u8 **)(entry + 0x14);
            goto cmp2_ld;
        cmp2:
            if ((s8)raw1 != (s8)raw2) {
                diff = (u32)(c1 - c2);
                goto cmp2_done;
            }
            a += 1;
            b += 1;
        cmp2_ld:
            raw1 = *a;
            raw2 = *b;
            c1 = (s8)raw1;
            c2 = (s8)raw2;
            if ((c1 | c2) != 0) {
                goto cmp2;
            }
            diff = 0;
        cmp2_done:
            if (diff != 0) {
                goto skip2;
            }
            n = n + 0;
            goto found;
        skip2:
            ;
        }
        n += 1;
        entry += 0x70;
    }
    entry = 0;
found:
    if (entry != 0) {
        return n - n;
    }
    {
        u8 **pp = (u8 **)((u8 *)arg0 + 4);
        *pp = *pp + 8;
    }
    return 1;
}
#pragma pop
s32 fn_8000ACA0(void *arg0) {
    u8 temp_r4;
    void *temp_r5;

    temp_r4 = M2C_FIELD(arg0, u8 *, 0x2C);
    if (temp_r4 & 2) {
        M2C_FIELD(arg0, u8 *, 0x2C) = (u8) (temp_r4 & 0xFFFFFFFD);
        temp_r5 = M2C_FIELD(arg0, void **, 0x18);
        M2C_FIELD(temp_r5, u8 *, 0x2D) = (u8) (M2C_FIELD(temp_r5, u8 *, 0x2D) - 1);
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_8000ACD8(void) {
    return 0;
}

#pragma global_optimizer off
#pragma opt_strength_reduction off
#pragma opt_common_subs off
s32 fn_8000ACE0(void *arg0)
{
  extern u8 gProcesses[];
  register u8 *p;
  register u32 value;
  u8 *new_var;
  register u32 zero;
  register s32 i;
  s32 j;
  value = *((u32 *) (((u8 *) (*((void **) (((u8 *) arg0) + 4)))) + 4));
  i = 0;
  p = gProcesses;
  zero = i;
  for (; i < 0x100; i++)
  {
    for (j = 0; j < 8; j++)
    {
      if ((*((u32 *) p)) == value)
      {
        new_var = p + 0x10;
        *((u32 *) new_var) = i;
      }
      p += 0x70;
    }

    i += 7;
  }

  *((u8 **) (((u8 *) arg0) + 4)) = (*((u8 **) (((u8 *) arg0) + 4))) + ((0, 8));
  return 1;
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
#pragma global_optimizer reset
s32 fn_8000ADA0(void *arg0) {
    s32 Process_UnlinkByKey(s32);
    Process_UnlinkByKey(((s32 **) arg0)[1][1]);
    ((s32 **) arg0)[1] = ((s32 **) arg0)[1] + 2;
    return 1;
}

#pragma global_optimizer off
s32 fn_8000ADE4(void *arg0)
{
 extern u8 gProcesses[];
 u8 *tmp = *(u8 **)((u8 *)arg0 + 4);
 if (Process_FindCodeInPool(*(u32 *)(tmp + 4), gProcesses) != 0) return 0;
 *(u8 **)((u8 *)arg0 + 4) += 8;
 return 1;
}
#pragma global_optimizer on
s32 fn_8000AEB4(void *arg0) {
    s32 Process_Create(s32, s16);
    s32 temp_r3 = ((s32 *) arg0)[1];
    Process_Create(((s32 *) temp_r3)[1], (s16) (((u32) ((s32 *) temp_r3)[0]) >> 16));
    ((s32 **) arg0)[1] = (s32 *) ((s32 *) arg0)[1] + 2;
    return 1;
}

s32 fn_8000AF04(void *arg0) {
    s32 Process_CreateChild(s32, void *);
    void **temp_r3 = (void **)((s32 *)arg0)[1];
    Process_CreateChild(((s32 *) temp_r3)[1], arg0);
    ((s32 **) arg0)[1] = (s32 *) ((s32 *) arg0)[1] + 2;
    return 0;
}

s32 fn_8000AF4C(void *arg0)
{
    extern void Process_Create(void *, void *);

    void *value;

    value = *(void **)(*(u8 **)((u8 *)arg0 + 4) + 4);

    Process_Create(value, arg0);

    *(u8 **)((u8 *)arg0 + 4) += 8;

    return 1;
}

s32 fn_8000AF94(void *arg0) {
    u32 *temp_r4;

    temp_r4 = M2C_FIELD(arg0, u32 **, 4);
    M2C_FIELD(arg0, u32 **, 4) = (u32 *) ((unsigned)temp_r4 + 4);
    M2C_FIELD(arg0, s16 *, 0x28) = (s16) ((u32) *temp_r4 >> 0x10U);
    return 1;
}

s32 fn_8000AFB4(void *arg0) {
    void **temp_r4;

    temp_r4 = (void **)M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(arg0, void **, 0x10) = (void *)temp_r4[1];
    temp_r4 = (void **)M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(arg0, void **, 4) = (void *)((u32)temp_r4 + 8);
    return 0;
}

void fn_8000AFD4(void *arg0) {
    u32 *entry;
    u32 value;
    s16 argument;
    u32 arg1;
    void (*callback)(void *, u32, s16);

    entry = *(u32 **)((u8 *)arg0 + 4);
    value = entry[0];
    callback = (void (*)(void *, u32, s16))entry[1];
    arg1 = entry[2];
    argument = (s16)(value >> 16);
    *(u32 **)((u8 *)arg0 + 4) = entry + 3;
    callback(arg0, arg1, argument);
}

void fn_8000B018(void *arg0) {
    s32 *node = ((s32 **)arg0)[1];
    void (*func)(void *, s32) = (void (*)(void *, s32))node[1];
    s32 arg1 = node[2];
    ((s32 **)arg0)[1] = node + 3;
    func(arg0, arg1);
}

void fn_8000B050(void *arg0)
{
  u32 new_var;
  s32 *node = ((s32 **) arg0)[1];
  u32 word = (u32) node[2];
  void (*func)(void *, s16, s16) = (void (*)(void *, s16, s16)) word;
  new_var = word;
  ((s32 **) arg0)[1] = node + 3;
  word = (s16) new_var;
  func(arg0, word, (s16) (new_var >> 16));
}

void fn_8000B090(void *arg0) {
    u32 *entry;
    u32 value;
    s16 argument;
    void (*callback)(void *, s16);

    entry = *(u32 **)((u8 *)arg0 + 4);
    value = entry[0];
    callback = (void (*)(void *, s16))entry[1];
    argument = (s16)(value >> 16);
    *(u32 **)((u8 *)arg0 + 4) = entry + 2;
    callback(arg0, argument);
}

s32 fn_8000B0D0(void *arg0)
{
    void *object;
    s32 (*callback)(void *);

    object = *(void **)((u8 *)arg0 + 4);
    callback = *(s32 (**)(void *))((u8 *)object + 4);

    if ((u8)callback(arg0) == 0) {
        return 0;
    }

    object = *(void **)((u8 *)arg0 + 4);
    *(void **)((u8 *)arg0 + 4) = (u8 *)object + 8;
    return 1;
}

s32 fn_8000B128(void *arg0)
{
    void *object;
    u8 (*callback)(void *);

    object = *(void **)((u8 *)arg0 + 4);
    callback = *(u8 (**)(void *))((u8 *)object + 4);

    if (callback(arg0) != 0) {
        return 0;
    }

    object = *(void **)((u8 *)arg0 + 4);
    *(void **)((u8 *)arg0 + 4) = (u8 *)object + 8;
    return 1;
}

int fn_8000B180(void *arg0) {
    void **p = (void **)((char *)arg0 + 4);
    void *obj = *p;
    int (*fn)(void *) = *(int (**)(void *))((char *)obj + 4);
    *p = (void *)((char *)obj + 8);
    return (u8)fn(arg0) == 0;
}

void fn_8000B1C0(void *arg0) {
    void **p = (void **)((char *)arg0 + 4);
    void *obj = *p;
    void (*fn)(void) = *(void (**)(void))((char *)obj + 4);
    *p = (void *)((char *)obj + 8);
    fn();
}

s32 fn_8000B1F4(void *arg0) {
    u32 *var_r4;
    u32 temp_r5;
    u32 key;

    if ((*(u8 (**)(void *))((u8 *)*(void **)((u8 *)arg0 + 4) + 4))(arg0) == 0) {
        key = (**(u32 **)((u8 *)arg0 + 4) >> 16) & 0xFF;
        var_r4 = *(u32 **)arg0;
        goto load;
        do {
            if ((temp_r5 & 0xFFF) == 1 && (s16)(temp_r5 >> 16) == (s32)key) {
                *(u32 **)((u8 *)arg0 + 4) = var_r4;
                *(s32 *)((u8 *)arg0 + 0x10) = 0;
                break;
            }
            var_r4 = (u32 *)((u8 *)var_r4 + ((temp_r5 >> 10) & 0x3C));
        load:
            temp_r5 = *var_r4;
        } while (temp_r5 != 0);
    } else {
        *(u8 **)((u8 *)arg0 + 4) = (u8 *)*(void **)((u8 *)arg0 + 4) + 8;
    }
    return 1;
}

s32 fn_8000B29C(void *arg0) {
    u32 *var_r4;
    u32 temp_r5;
    u32 key;

    if ((*(u8 (**)(void *))((u8 *)*(void **)((u8 *)arg0 + 4) + 4))(arg0) != 0) {
        key = (**(u32 **)((u8 *)arg0 + 4) >> 16) & 0xFF;
        var_r4 = *(u32 **)arg0;
        goto load;
        do {
            if ((temp_r5 & 0xFFF) == 1 && (s16)(temp_r5 >> 16) == (s32)key) {
                *(u32 **)((u8 *)arg0 + 4) = var_r4;
                *(s32 *)((u8 *)arg0 + 0x10) = 0;
                break;
            }
            var_r4 = (u32 *)((u8 *)var_r4 + ((temp_r5 >> 10) & 0x3C));
        load:
            temp_r5 = *var_r4;
        } while (temp_r5 != 0);
    } else {
        *(u8 **)((u8 *)arg0 + 4) = (u8 *)*(void **)((u8 *)arg0 + 4) + 8;
    }
    return 1;
}

s32 fn_8000B344(void *arg0) {
    s32 *node = ((s32 **)arg0)[1];
    void (*func)(void *) = (void (*)(void *))node[1];
    ((s32 **)arg0)[1] = node + 2;
    func(arg0);
    return 1;
}

s32 fn_8000B37C(void *arg0) {
    void *temp_r4;

    temp_r4 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 4);
    M2C_FIELD(arg0, void **, 0) = temp_r4;
    M2C_FIELD(arg0, void **, 4) = temp_r4;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    return 1;
}

#pragma global_optimizer off
s32 fn_8000B39C(void *arg0)
{
    u8 *ptr;
    u32 *base;
    s32 key;
    u32 node;

    base = *(u32 **)((u8 *)arg0 + 4);
    key = (u8)(*base >> 16);
    if (*(s16 *)((u8 *)arg0 + 0x28) >= 0) {
        (*(s16 *)((u8 *)arg0 + 0x28))--;
        if (*(s16 *)((u8 *)arg0 + 0x28) == 0) {
            ptr = *(u8 **)arg0;
            goto load;
        loop:
            if ((node & 0xFFF) == 1 && (s16)(node >> 16) == key) {
                *(u8 **)((u8 *)arg0 + 4) = ptr;
                *(s32 *)((u8 *)arg0 + 0x10) = 0;
                goto done;
            }
            ptr += (node >> 10) & 0x3C;
        load:
            node = *(u32 *)ptr;
            if (node != 0) {
                goto loop;
            }
        }
    }
done:
    return 1;
}
#pragma global_optimizer on
s32 fn_8000B418(void *arg0)
{
    u32 *ptr;
    u32 node;
    s32 key;
    u32 *base;

    base = *(u32 **)((u8 *)arg0 + 4);
    ptr = *(u32 **)arg0;
    key = (u8)(*base >> 16);
    goto load;
loop:
    if ((node & 0xFFF) == 1 && (s16)(node >> 16) == key) {
        *(u32 **)((u8 *)arg0 + 4) = ptr;
        *(s32 *)((u8 *)arg0 + 0x10) = 0;
        goto done;
    }
    ptr = (u32 *)((u8 *)ptr + ((node >> 10) & 0x3C));
load:
    node = *ptr;
    if (node != 0) {
        goto loop;
    }
done:
    return 1;
}

s32 fn_8000B474(void *arg0) {
    void fn_8000B4D0(void);
    void **temp_r4;

    M2C_FIELD(arg0, void **, 0x10) = (void *)fn_8000B4D0;
    temp_r4 = (void **)M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(arg0, void **, 4) = (void *)((u32)temp_r4 + 4);
    return 0;
}

s32 fn_8000B494(void *arg0) {
    void fn_8000B4D0(void);
    u32 *temp_r4;
    s16 val;

    temp_r4 = M2C_FIELD(arg0, u32 **, 4);
    M2C_FIELD(arg0, u32 **, 4) = (u32 *) ((unsigned)temp_r4 + 4);
    val = (s16) ((u32) *temp_r4 >> 0x10U);
    if (val == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s16 *, 0x28) = val;
    M2C_FIELD(arg0, void **, 0x10) = (void *)fn_8000B4D0;
    return 0;
}

void fn_8000B4D0(void) {

}

s32 fn_8000B4D4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_8000B4E8(void *arg0) {
    extern u8 gProcesses[];
    void Process_Unlink(void *);
    u8 *ptr = gProcesses;
    s32 i;

    for (i = 0; i < 256; i++, ptr += 0x70) {
        if (ptr != (u8 *)arg0 && *(u32 *)ptr == *(u32 *)arg0) {
            Process_Unlink(ptr);
            break;
        }
    }

    *(u32 *)((u8 *)arg0 + 4) += 4;
    return 1;
}

s32 fn_8000B660(void *arg0)
{
 extern u8 gProcesses[];
 s32 Process_Unlink(void *);
 u8 *ptr = gProcesses;
 s32 i = 0;
 s32 count = 0;
 for(;i<256;i++,ptr+=0x70) {
 if(*(u32*)ptr == *(u32*)arg0) count++;
 }
 if(count>1) { Process_Unlink(arg0); return 0; }
 *(u32*)((u8*)arg0+4)+=4;
 return 1;
}

s32 fn_8000B76C(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2C) = (u8) (M2C_FIELD(arg0, u8 *, 0x2C) | 4);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

s32 fn_8000B78C(void *arg0) {
    void **temp_r4;

    temp_r4 = (void **)M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(arg0, void **, 0xc) = (void *)temp_r4[1];
    temp_r4 = (void **)M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(arg0, void **, 4) = (void *)((u32)temp_r4 + 8);
    return 1;
}

s32 fn_8000B7AC(void *arg0) {
    void **temp_r4;
    
    temp_r4 = (void **)M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(arg0, void **, 8) = (void *)temp_r4[1];
    temp_r4 = (void **)M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(arg0, void **, 4) = (void *)((u32)temp_r4 + 8);
    return 1;
}

s32 fn_8000B7CC(void *arg0) {
    void **temp_r4;
    
    temp_r4 = (void **)M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(arg0, void **, 0x14) = (void *)temp_r4[1];
    temp_r4 = (void **)M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(arg0, void **, 4) = (void *)((u32)temp_r4 + 8);
    return 1;
}

s32 fn_8000B7EC(void *arg0) {
    u32 *temp_r4;

    temp_r4 = M2C_FIELD(arg0, u32 **, 4);
    M2C_FIELD(arg0, u32 **, 4) = (u32 *) ((s32)temp_r4 + 4);
    M2C_FIELD(arg0, s8 *, 0x2B) = (s8) ((u32) *temp_r4 >> 0x10U);
    return 1;
}

s32 fn_8000B80C(void *arg0) {
    u32 *temp_r4;

    temp_r4 = M2C_FIELD(arg0, u32 **, 4);
    M2C_FIELD(arg0, u32 **, 4) = (u32 *) ((u32)temp_r4 + 4);
    M2C_FIELD(arg0, s8 *, 0x2A) = (s8) ((u32) *temp_r4 >> 0x10U);
    return 1;
}

s32 fn_8000B82C(void) {
    M2C_UNK Process_Unlink();
    Process_Unlink();
    return 0;
}

extern void *(*lbl_80366DA0)(s32);
extern f32 gFloat1, lbl_80368BB8, lbl_80368B98;
extern u32 gProcessOpcodeTables[9];
void Process_RunScript(void *arg0) {
    extern u32 gProcessOpcodeTables[9];
    u8 *self;
    u32 *table;
    u32 x;
    u32 y;

    self = (u8 *)arg0;
    if (*(u32 *)self != 0 && self[0x2D] == 0 && self[0x2E] == 0 && *(void **)(self + 0x10) == NULL) {
        table = gProcessOpcodeTables;
        for (;;) {
            x = **(u32 **)(self + 4);
            y = table[(x >> 8) & 7];
            if (((u8 (*)(void *))(*(u32 *)(y + ((x & 0xFF) << 2))))(self)
                && *(u32 *)self != 0 && self[0x2D] == 0) {
                if (self[0x2E] == 0) {
                    continue;
                }
            }
            break;
        }
    }
}

void *GfxEnt_Get(u8 arg0) {
    extern u16 gProcesses[];
    return (u8 *)gProcesses + arg0 * 0x70;
}

u8 fn_8000B920(void *arg0) {
    extern u8 gProcesses[];

    s32 offset;

    offset = (s32)arg0 - (s32)gProcesses;
    return (u8)(offset / 0x70);
}

void fn_8000B950(void *arg0, void (*arg1)(void *)) {
    void fn_8000B9A4(void *, void (*)(void *));
    void *tmp;

    arg1(arg0);
    tmp = *(void **)((u8 *)arg0 + 0x1C);
    if (tmp != NULL) {
        fn_8000B9A4(tmp, arg1);
    }
}

#pragma inline_depth(3)
void fn_8000B9A4(void *arg0, void (*arg1)(void *)) {
    if (*(void **)((u8 *)arg0 + 0x24) != NULL) {
        fn_8000B9A4(*(void **)((u8 *)arg0 + 0x24), arg1);
    }
    arg1(arg0);
    if (*(void **)((u8 *)arg0 + 0x1C) != NULL) {
        fn_8000B9A4(*(void **)((u8 *)arg0 + 0x1C), arg1);
    }
}
#pragma inline_depth(0)
void *Process_FindByName(u8 *arg0) {
    extern u8 gProcesses[];
    s32 c2;
    s32 c1;
    u32 raw2;
    u32 raw1;
    u32 diff;
    s32 i;
    u8 *entry;
    s32 n;
    u8 *b;
    u8 *a;

    entry = gProcesses;
    n = 0;
    for (i = 0; i < 0x80; i++) {
        if (*(u32 *)entry != 0) {
            a = *(u8 **)(entry + 0x14);
            b = arg0;
            goto cmp1_ld;
        cmp1:
            if ((s8)raw1 != (s8)raw2) {
                diff = (u32)(c1 - c2);
                goto cmp1_done;
            }
            a += 1;
            b += 1;
        cmp1_ld:
            raw1 = *a;
            raw2 = *b;
            c1 = (s8)raw1;
            c2 = (s8)raw2;
            if ((c1 | c2) != 0) {
                goto cmp1;
            }
            diff = 0;
        cmp1_done:
            if (diff == 0) {
                n = n + 0;
                return entry;
            }
        }
        if (*(u32 *)(entry += 0x70) != 0) {
            b = arg0;
            a = *(u8 **)(entry + 0x14);
            goto cmp2_ld;
        cmp2:
            if ((s8)raw1 != (s8)raw2) {
                diff = (u32)(c1 - c2);
                goto cmp2_done;
            }
            a += 1;
            b += 1;
        cmp2_ld:
            raw1 = *a;
            raw2 = *b;
            c1 = (s8)raw1;
            c2 = (s8)raw2;
            if ((c1 | c2) != 0) {
                goto cmp2;
            }
            diff = 0;
        cmp2_done:
            if (diff == 0) {
                n = n + 0;
                return entry;
            }
        }
        n += 1;
        entry += 0x70;
    }
    return 0;
}

#pragma optimization_level 4
void GfxEnt_UnlinkByName(u8 *arg0) {
    void Process_Unlink(void *);
    extern u8 gProcesses[];
    u8 *var_r31;
    s32 var_r30;
    u8 *var_r29;
    u8 *a;
    u8 *b;

    var_r31 = gProcesses;
    var_r29 = arg0;
    for (var_r30 = 0; var_r30 < 0x100; var_r30++) {
        if (*(u32 *)var_r31 != 0) {
            s32 d;
            s32 c1;
            s32 c2;
            a = *(u8 **)(var_r31 + 0x14);
            b = var_r29;
            goto load;
        compare:
            if ((s8)c1 != (s8)c2) {
                d = (s8)c1 - (s8)c2;
                goto check;
            }
            a += 1;
            b += 1;
        load:
            c1 = *a;
            c2 = *b;
            if (((s8)c1 | (s8)c2) != 0) {
                goto compare;
            }
            d = 0;
        check:
            if ((u32)d == 0) {
                Process_Unlink(var_r31);
            }
        }
        var_r31 += 0x70;
    }
}

#pragma push
#pragma global_optimizer off
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void fn_8000BE54(u32 arg0) {
 extern u8 lbl_802A66D8[]; u8 *p=lbl_802A66D8; s32 i,j;
 for(i=0;i<32;i++){for(j=0;j<8;j++){if(*(u32*)p==arg0)*(u32*)(p+0x10)=0;p+=0x70;}}
}
#pragma pop
void Process_UnlinkByKey(u32 arg0) {
    extern u8 gProcesses[];
    void Process_Unlink(void *);
    u8 *var_r31;
    s32 var_r30;

    var_r31 = gProcesses;
    var_r30 = 0;
    do {
        if (*(u32 *)var_r31 == arg0) {
            Process_Unlink(var_r31);
        }
        var_r30 += 1;
        var_r31 += 0x70;
    } while (var_r30 < 0x100);
}

void fn_8000BF6C(u32 arg0, void (*arg1)(void *)) {
    extern u8 gProcesses[];
    u8 *var_r31;
    s32 var_r30;

    var_r31 = gProcesses;
    var_r30 = 0;
    do {
        if (*(u32 *)var_r31 == arg0) {
            arg1(var_r31);
        }
        var_r30 += 1;
        var_r31 += 0x70;
    } while (var_r30 < 0x100);
}

void fn_8000BFEC(void (*arg0)(void *)) {
    extern u8 gProcesses[];
    u8 *var_r31;
    s32 var_r30;

    var_r31 = gProcesses;
    var_r30 = 0;
    do {
        if (*(u32 *)var_r31 != 0) {
            arg0(var_r31);
        }
        var_r30 += 1;
        var_r31 += 0x70;
    } while (var_r30 < 0x100);
}

void fn_8000C060(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
}

void fn_8000C068(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 8) = arg1;
}

void Process_Goto(void *arg0, u32 arg1)
{
    u32 node;
    u32 *ptr;

    ptr = *(u32 **)arg0;
    goto load;
loop:
    if ((node & 0xFFF) == 1 && (s16)(node >> 16) == (s32)(u8)arg1) {
        *(u32 **)((u8 *)arg0 + 4) = ptr;
        *(s32 *)((u8 *)arg0 + 0x10) = 0;
        return;
    }
    ptr = (u32 *)((u8 *)ptr + ((node >> 10) & 0x3C));
load:
    node = *ptr;
    if (node != 0) {
        goto loop;
    }
}

/* Find the first process whose code pointer matches `code`. */
Process *Process_Find(u32 code) {
    extern u8 gProcesses[];
    u32 *p = (u32 *)gProcesses;
    s32 i;

    for (i = 0; i < PROCESS_POOL_COUNT; i++, p += 0x1C) {
        if (*p == code) {
            return (Process *)p;
        }
    }
    return NULL;
}

void Process_ClearFunc(void *arg0) {
    *(u32*)((char*)arg0 + 0x10) = 0;
}

void fn_8000C194(s32 arg0) {
    void Process_Update(u32);
    extern u32 lbl_802ADADC[];
    u32 v = lbl_802ADADC[arg0];
    if (v != 0) {
        Process_Update(v);
    }
}

void Process_RunScript(void *);
void Process_ClearFunc(void *);
/* Recursively tick a process subtree: run scripts/funcs with timers, then post callbacks and children. */
void Process_Update(void *arg0) {
    extern u32 gProcessOpcodeTables[9];
    u8 *self;
    u8 *node;
    u8 *child;
    void (*cb)(void *);
    s32 t;
    u32 x;
    u32 y;

    self = (u8 *)arg0;
    node = *(u8 **)(self + 0x24);
    if (node != NULL) {
        child = *(u8 **)(node + 0x24);
        if (child != NULL) {
            Process_Update(child);
        }
        if (*(u32 *)node != 0 && node[0x2E] == 0) {
            if (node[0x2D] == 0 && ((node[0x2C] & 4) == 0 || (*(u8 **)(node + 0x18))[0x2D] == 0)) {
                for (;;) {
                    if (*(void **)(node + 0x10) == NULL) {
                        Process_RunScript(node);
                    }
                    if (*(void **)(node + 0x10) != NULL) {
                        t = *(s16 *)(node + 0x28);
                        if (t >= 0) {
                            *(s16 *)(node + 0x28) = (s16)(t - 1);
                            if (*(s16 *)(node + 0x28) < 0) {
                                Process_ClearFunc(node);
                                continue;
                            }
                        }
                        (*(void (**)(void *))(node + 0x10))(node);
                    }
                    if (node[0x2C] & 1) {
                        goto done1;
                    }
                    break;
                }
            }
            cb = *(void (**)(void *))(node + 0xC);
            if (cb != NULL) {
                cb(node);
            }
            child = *(u8 **)(node + 0x1C);
            if (child != NULL) {
                Process_Update(child);
            }
        }
    }
done1:

    if (*(u32 *)self != 0 && self[0x2E] == 0) {
        if (self[0x2D] == 0 && ((self[0x2C] & 4) == 0 || (*(u8 **)(self + 0x18))[0x2D] == 0)) {
            for (;;) {
                if (*(void **)(self + 0x10) == NULL) {
                    if (*(u32 *)self != 0 && self[0x2D] == 0 && self[0x2E] == 0 && *(void **)(self + 0x10) == NULL) {
                        for (;;) {
                            x = **(u32 **)(self + 4);
                            y = gProcessOpcodeTables[(x >> 8) & 7];
                            if (((u8 (*)(void *))(*(u32 *)(y + ((x & 0xFF) << 2))))(self)
                                && *(u32 *)self != 0 && self[0x2D] == 0) {
                                if (self[0x2E] == 0) {
                                    continue;
                                }
                            }
                            break;
                        }
                    }
                }
                if (*(void **)(self + 0x10) != NULL) {
                    t = *(s16 *)(self + 0x28);
                    if (t >= 0) {
                        *(s16 *)(self + 0x28) = (s16)(t - 1);
                        if (*(s16 *)(self + 0x28) < 0) {
                            *(void **)(self + 0x10) = NULL;
                            continue;
                        }
                    }
                    (*(void (**)(void *))(self + 0x10))(self);
                }
                if (self[0x2C] & 1) {
                    goto done2;
                }
                break;
            }
        }
        cb = *(void (**)(void *))(self + 0xC);
        if (cb != NULL) {
            cb(self);
        }
        node = *(u8 **)(self + 0x1C);
        if (node != NULL) {
            child = *(u8 **)(node + 0x24);
            if (child != NULL) {
                Process_Update(child);
            }
            if (*(u32 *)node != 0 && node[0x2E] == 0) {
                if (node[0x2D] == 0 && ((node[0x2C] & 4) == 0 || (*(u8 **)(node + 0x18))[0x2D] == 0)) {
                    for (;;) {
                        if (*(void **)(node + 0x10) == NULL) {
                            Process_RunScript(node);
                        }
                        if (*(void **)(node + 0x10) != NULL) {
                            t = *(s16 *)(node + 0x28);
                            if (t >= 0) {
                                *(s16 *)(node + 0x28) = (s16)(t - 1);
                                if (*(s16 *)(node + 0x28) < 0) {
                                    Process_ClearFunc(node);
                                    continue;
                                }
                            }
                            (*(void (**)(void *))(node + 0x10))(node);
                        }
                        if (node[0x2C] & 1) {
                            goto done2;
                        }
                        break;
                    }
                }
                cb = *(void (**)(void *))(node + 0xC);
                if (cb != NULL) {
                    cb(node);
                }
                child = *(u8 **)(node + 0x1C);
                if (child != NULL) {
                    Process_Update(child);
                }
            }
        }
    }
done2:
    ;
}

s32 Process_CountFree(void) {
    extern void *gProcessFreeTop;
    extern u8 lbl_802AD6D8[];

    return ((s32)gProcessFreeTop - (s32)lbl_802AD6D8) / 4;
}

void Process_Free(s32 arg0) {
    extern s32 *gProcessFreeTop;
    s32 *temp_r4;

    temp_r4 = gProcessFreeTop - 1;
    gProcessFreeTop = temp_r4;
    *temp_r4 = arg0;
}

void *fn_8000C540(void) {
    void Process_Unlink(void *);
    extern void **gProcessFreeTop;
    extern u8 gProcesses[];
    void **p;
    void *result;
    u8 *entry;
    s32 i;

    p = gProcessFreeTop;
    result = *p;
    if (result != NULL) {
        gProcessFreeTop = p + 1;
        return result;
    }
    entry = gProcesses;
    for (i = 0x100; i != 0; i--) {
        if (*(void **)entry != NULL) {
            if ((entry[0x2C] & 0x10) != 0) {
                Process_Unlink(entry);
                return fn_8000C540();
            }
        }
        entry += 0x70;
    }
    return NULL;
}

void Process_DetachChild(void *arg0) {
    u8 temp_r4;
    void *temp_r4_2;

    temp_r4 = M2C_FIELD(arg0, u8 *, 0x2C);
    if (temp_r4 & 2) {
        M2C_FIELD(arg0, u8 *, 0x2C) = (u8) (temp_r4 & 0xFFFFFFFD);
        temp_r4_2 = M2C_FIELD(arg0, void **, 0x18);
        M2C_FIELD(temp_r4_2, u8 *, 0x2D) = (u8) (M2C_FIELD(temp_r4_2, u8 *, 0x2D) - 1);
    }
}

void Process_MarkActive(void *arg0) {
    void *temp_r4;

    if ((void *) M2C_FIELD(arg0, void **, 0x18) != NULL) {
        M2C_FIELD(arg0, u8 *, 0x2C) = (u8) (M2C_FIELD(arg0, u8 *, 0x2C) | 2);
        temp_r4 = M2C_FIELD(arg0, void **, 0x18);
        M2C_FIELD(temp_r4, u8 *, 0x2D) = (u8) (M2C_FIELD(temp_r4, u8 *, 0x2D) + 1);
    }
}

int Process_Unlink(void *arg0) {
    extern u32 lbl_802ADADC[8];
    int Process_Destroy(void);
    u32 *p = (u32 *)arg0;
    u32 *q;
    u32 idx;
    u32 head;

    if (arg0) {
        q = (u32 *)p[8];
        if (q) {
            q[9] = p[9];
        }
        q = (u32 *)p[9];
        if (q) {
            q[8] = p[8];
        }
        idx = p[6];
        if (idx > 8) {
            q = (u32 *)idx;
            if (q[7] == (u32)arg0) {
                q[7] = p[9];
            }
        } else {
            head = lbl_802ADADC[idx];
            if (head == (u32)arg0) {
                lbl_802ADADC[idx] = p[9];
            }
        }
        p[8] = 0;
        p[9] = 0;
        Process_Destroy();
    }
}

/* Recursively destroy a process tree (next and child), run destructors, and return nodes to the freelist. */
void Process_Destroy(Process *proc) {
    void Process_Free(void *);
    extern void **gProcessFreeTop;
    Process *node;
    Process *child;
    void **slot;

    node = proc->next;
    if (node != NULL) {
        child = node->next;
        if (child != NULL) {
            if (child->next != NULL) {
                Process_Destroy(child->next);
            }
            if (child->child != NULL) {
                Process_Destroy(child->child);
            }
            if ((child->flags & PROCESS_FLAG_ENDED) == 0) {
                if (child->destructor != NULL) {
                    child->destructor(child);
                }
                Process_Free(child);
                child->code = NULL;
                child->func = NULL;
                child->flags |= PROCESS_FLAG_ENDED;
                if (child->flags & PROCESS_FLAG_LOCKED) {
                    child->parent->lock_cnt -= 1;
                }
            }
        }
        child = node->child;
        if (child != NULL) {
            if (child->next != NULL) {
                Process_Destroy(child->next);
            }
            if (child->child != NULL) {
                Process_Destroy(child->child);
            }
            if ((child->flags & PROCESS_FLAG_ENDED) == 0) {
                if (child->destructor != NULL) {
                    child->destructor(child);
                }
                Process_Free(child);
                child->code = NULL;
                child->func = NULL;
                child->flags |= PROCESS_FLAG_ENDED;
                if (child->flags & PROCESS_FLAG_LOCKED) {
                    child->parent->lock_cnt -= 1;
                }
            }
        }
        if ((node->flags & PROCESS_FLAG_ENDED) == 0) {
            if (node->destructor != NULL) {
                node->destructor(node);
            }
            slot = (void **)((u8 *)gProcessFreeTop - 4);
            gProcessFreeTop = slot;
            *slot = node;
            node->code = NULL;
            node->func = NULL;
            node->flags |= PROCESS_FLAG_ENDED;
            if (node->flags & PROCESS_FLAG_LOCKED) {
                node->parent->lock_cnt -= 1;
            }
        }
    }
    node = proc->child;
    if (node != NULL) {
        child = node->next;
        if (child != NULL) {
            if (child->next != NULL) {
                Process_Destroy(child->next);
            }
            if (child->child != NULL) {
                Process_Destroy(child->child);
            }
            if ((child->flags & PROCESS_FLAG_ENDED) == 0) {
                if (child->destructor != NULL) {
                    child->destructor(child);
                }
                Process_Free(child);
                child->code = NULL;
                child->func = NULL;
                child->flags |= PROCESS_FLAG_ENDED;
                if (child->flags & PROCESS_FLAG_LOCKED) {
                    child->parent->lock_cnt -= 1;
                }
            }
        }
        child = node->child;
        if (child != NULL) {
            if (child->next != NULL) {
                Process_Destroy(child->next);
            }
            if (child->child != NULL) {
                Process_Destroy(child->child);
            }
            if ((child->flags & PROCESS_FLAG_ENDED) == 0) {
                if (child->destructor != NULL) {
                    child->destructor(child);
                }
                Process_Free(child);
                child->code = NULL;
                child->func = NULL;
                child->flags |= PROCESS_FLAG_ENDED;
                if (child->flags & PROCESS_FLAG_LOCKED) {
                    child->parent->lock_cnt -= 1;
                }
            }
        }
        if ((node->flags & PROCESS_FLAG_ENDED) == 0) {
            if (node->destructor != NULL) {
                node->destructor(node);
            }
            slot = (void **)((u8 *)gProcessFreeTop - 4);
            gProcessFreeTop = slot;
            *slot = node;
            node->code = NULL;
            node->func = NULL;
            node->flags |= PROCESS_FLAG_ENDED;
            if (node->flags & PROCESS_FLAG_LOCKED) {
                node->parent->lock_cnt -= 1;
            }
        }
    }
    if ((proc->flags & PROCESS_FLAG_ENDED) == 0) {
        if (proc->destructor != NULL) {
            proc->destructor(proc);
        }
        slot = (void **)((u8 *)gProcessFreeTop - 4);
        gProcessFreeTop = slot;
        *slot = proc;
        proc->code = NULL;
        proc->func = NULL;
        proc->flags |= PROCESS_FLAG_ENDED;
        if (proc->flags & PROCESS_FLAG_LOCKED) {
            proc->parent->lock_cnt -= 1;
        }
    }
}

void Process_CreateEx(u32 unused, u32 arg1) {
    void Process_CreateChild(void);
    void Process_Create(void);
    u32 var_r4;

    var_r4 = arg1;
    if (var_r4 == 0U) {
        var_r4 = 3U;
    }
    if ((s32)var_r4 < 0) {
        Process_CreateChild();
        return;
    }
    Process_Create();
}

void *Process_CreateChild(void *arg0, s32 arg1, void *arg2) {
    void *Process_Create();
    void *temp_r3;
    void *temp_r5;

    temp_r3 = Process_Create();
    if ((u32) M2C_FIELD(temp_r3, u32 *, 0) == 0U) {
        return NULL;
    }
    M2C_FIELD(temp_r3, u8 *, 0x2C) = (u8) (M2C_FIELD(temp_r3, u8 *, 0x2C) | 2);
    temp_r5 = M2C_FIELD(temp_r3, void **, 0x18);
    M2C_FIELD(temp_r5, u8 *, 0x2D) = (u8) (M2C_FIELD(temp_r5, u8 *, 0x2D) + 1);
    return temp_r3;
}

void *Process_Create(u32 *code, s32 parent) {
    Process *fn_8000C540(void);
    extern u8 lbl_80267CB0[];
    extern Process *lbl_802ADADC[];
    Process *p;
    p = fn_8000C540();
    p->code = code;
    p->script = (u32 **)code;
    p->destructor = 0;
    p->post = 0;
    p->func = 0;
    p->name = (char *)lbl_80267CB0 + 0x78;
    p->parent = 0;
    p->child = 0;
    p->prev = 0;
    p->next = 0;
    p->timer = -1;
    p->unk_2A = 255;
    p->flags = 8;
    p->lock_cnt = 0;
    p->pause = 0;
    if ((u32)parent < 8) {
        p->unk_2B = 0;
        if (lbl_802ADADC[parent]) {
            lbl_802ADADC[parent]->prev = p;
            p->next = lbl_802ADADC[parent];
        }
        p->parent = (Process *)parent;
        lbl_802ADADC[parent] = p;
    } else {
        p->unk_2B = ((Process *)parent)->unk_2B;
        if (((Process *)parent)->child) {
            ((Process *)parent)->child->prev = p;
            p->next = ((Process *)parent)->child;
        }
        ((Process *)parent)->child = p;
        p->parent = (Process *)parent;
    }
    if (p->code && p->lock_cnt == 0 && p->pause == 0 && p->func == 0) {
        u32 *table = gProcessOpcodeTables;
        for (;;) {
            u32 x = *(u32 *)p->script;
            u32 y = table[(x >> 8) & 7];
            if (((u8 (*)(void *))(*(u32 *)(y + ((x & 255) << 2))))(p)
                && p->code && p->lock_cnt == 0) {
                if (p->pause == 0) continue;
            }
            break;
        }
    }
    p->flags &= ~8;
    return p;
}

extern void *fn_8000A738(void *, s32);
extern void fn_8000B5F0(void *);
extern void fn_8000B70C(void *);
void fn_8000CC88(void) {
    extern u8 lbl_802A66D8[];
    extern u8 lbl_80283828[];
    extern void *lbl_80367148;
    u8 *base;
    u8 *p;
    u8 **q;
    s32 i;
    s16 neg1;
    u8 ff;
    u32 zero;

    base = lbl_802A66D8;
    p = base;
    q = (u8 **)(base + 0x7000);
    neg1 = -1;
    ff = 0xFF;
    zero = 0;
    for (i = 0; i < 0x100; i++) {
        *(u32 *)(p + 0x00) = zero;
        *(u32 *)(p + 0x04) = zero;
        *(u32 *)(p + 0x08) = zero;
        *(u32 *)(p + 0x0C) = zero;
        *(u32 *)(p + 0x10) = zero;
        *(u32 *)(p + 0x14) = zero;
        *(u32 *)(p + 0x18) = zero;
        *(u32 *)(p + 0x1C) = zero;
        *(u32 *)(p + 0x20) = zero;
        *(u32 *)(p + 0x24) = zero;
        *(s16 *)(p + 0x28) = neg1;
        p[0x2A] = ff;
        p[0x2B] = zero;
        p[0x2C] = zero;
        p[0x2D] = zero;
        *q = p;
        q++;
        p[0x2E] = zero;
        p += 0x70;
    }
    *(u32 *)(base + 0x7424) = zero;
    *(u32 *)(base + 0x7400) = zero;
    lbl_80367148 = base + 0x7000;
    *(u32 *)(base + 0x7428) = zero;
    *(u32 *)(base + 0x742C) = zero;
    *(u32 *)(base + 0x7430) = zero;
    *(u32 *)(base + 0x7434) = zero;
    *(u32 *)(base + 0x7438) = zero;
    *(u32 *)(base + 0x743C) = zero;
    *(u32 *)(base + 0x7440) = zero;
    *(void **)(base + 0x7424) = lbl_80283828;
    *(u32 *)(base + 0x7404) = zero;
    *(u32 *)(base + 0x7408) = zero;
    *(u32 *)(base + 0x740C) = zero;
    *(u32 *)(base + 0x7410) = zero;
    *(u32 *)(base + 0x7414) = zero;
    *(u32 *)(base + 0x7418) = zero;
    *(u32 *)(base + 0x741C) = zero;
    *(u32 *)(base + 0x7420) = zero;
}

u32 Rand_Next(void) {
    extern u32 lbl_80367158;
    u32 temp;
    u32 other;

    temp = (lbl_80367158 << 2) + 2;
    other = temp + 1;
    temp = temp * other;
    temp >>= 2;
    lbl_80367158 = temp;
    return temp;
}

void fn_8000CD80(s32 arg0) {
    extern s32 lbl_80367158;
    lbl_80367158 = arg0;
}

s32 Rand_TrueHit(s32 arg0)
{
  struct RandSt
  {
    u16 a;
    u16 b;
    u16 c;
  };
  extern struct RandSt lbl_80367150;
  s32 sum;
  s32 scaled;
  u16 t6;
  unsigned short t4;
  s32 s1;
  s32 s2;
  s32 s0;
  s32 s0h;
  u8 *st;
  st = (u8 *)&lbl_80367150;
  s0 = lbl_80367150.a;
  s2 = *(u16 *)(st + 4);
  s1 = *(u16 *)(st + 2);
  t4 = (s2 * 2) & 0xFFFE;
  s0h = s0 >> 5;
  t6 = (u16) ((s1 << 11) + s0h);
  *(u16 *)(st + 4) = t4;
  if (s1 & 0x8000)
  {
    *(u16 *)(st + 4) = t4 + 1;
  }
  t6 ^= *(u16 *)(st + 4);
  *(u16 *)(st + 4) = *(u16 *)(st + 2);
  scaled = ((u16) t6) * 100;
  *(u16 *)(st + 2) = lbl_80367150.a;
  lbl_80367150.a = t6;
  sum = scaled / 65536;
  s0 = lbl_80367150.a;
  s2 = *(u16 *)(st + 4);
  s1 = *(u16 *)(st + 2);
  t4 = (s2 * 2) & 0xFFFE;
  s0h = s0 >> 5;
  t6 = (u16) ((s1 << 11) + s0h);
  *(u16 *)(st + 4) = (((((((((t4 & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF;
  if (s1 & 0x8000)
  {
    *(u16 *)(st + 4) = t4 + 1;
  }
  t6 ^= *(u16 *)(st + 4);
  *(u16 *)(st + 4) = *(u16 *)(st + 2);
  scaled = ((u16) t6) * 100;
  *(u16 *)(st + 2) = lbl_80367150.a;
  lbl_80367150.a = t6;
  sum += scaled / 65536;
  return (sum / 2) < arg0;
}

#pragma global_optimizer off
s32 Rand_Chance(s32 arg0)
{
  struct RandSt
  {
    u16 a;
    u16 b;
    u16 c;
  };
  extern struct RandSt lbl_80367150;
  u16 t6;
  s32 t4;
  s32 sum;
  s32 s2;
  s32 s1;
  s32 s0;
  struct RandSt *st;
  st = &lbl_80367150;
  s0 = lbl_80367150.a;
  t4 = st->c;
  s1 = st->b;
  sum = s0 >> 5;
  s2 = (s1 << 11);
  t4 = (t4 << 1) & 0xFFFE;
  st->c = t4;
  sum = s2 + sum;
  t6 = (u16)sum;
  if (s1 & 0x8000) {
    st->c = 1 + t4;
  }
  t6 ^= st->c;
  st->c = st->b;
  st->b = lbl_80367150.a;
  lbl_80367150.a = t6;
  return (((u16)t6) * 100) / 65536 < arg0;
}
#pragma global_optimizer off
