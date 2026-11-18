/* Functions from 0x80103748 to 0x80105504, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
#include "unit.h"

extern u32 gProcesses[];
extern f64 lbl_8036A100;
extern f32 lbl_8036A0F8;
extern u16 lbl_80366E80;

void Status_Clear(void *, u8);

/* Init unit-action menu configs if needed, then open the menu on the map UI process. */

#pragma global_optimizer on
#pragma opt_propagation on

#pragma opt_propagation reset
#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset

/* Return the packed weapon-rank nibble for kind (0-15); 0 if unused, -1 if out of range. */

extern u32 lbl_8028F210[];

/* Decrement packed skill-rank counters: mode 1 ticks all combat ranks, mode 0 ticks rank slot 5 only. */

extern void* lbl_803679C0;
extern u8 lbl_8032BB44[20];

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern void *lbl_803679C0;

extern u16 lbl_80366E80;

#pragma use_lmw_stmw on

#pragma scheduling on

void *fn_80105124(u8 *arg0, s32 *arg1) {
    u16 sp8;
    u8 is_double;
    u16 code;
    void **ctx;
    u8 *next;
    void *base;
    void *end;
    void *start;
    void *entry;
    s32 fn_801053E4(s32,s32,u16 *,void *);
    s32 fn_80105474(s32,s32,void *,void *);
    u32 fn_80104930(u16 *,u16);
    extern void *lbl_803679C0;
    ctx=lbl_803679C0;
    if (((arg0[0]>=0x81U && arg0[0]<=0x9FU)||(arg0[0]>=0xE0U && arg0[0]<=0xFCU)) &&
       ((arg0[1]>=0x40U && arg0[1]<=0x7EU)||(arg0[1]>=0x80U && arg0[1]<=0xFCU))) is_double=1;
    else is_double=0;
    if(is_double) {
        code=arg0[1];
        next=arg0+2;
        code=((s32)*(s8 *)arg0 << 8 & 0xFF00) | code;
    } else { code=*(s8 *)arg0 & 0xFF; next=arg0+1; }
    sp8=code;
    if(*(u16 *)ctx[3]!=code) {
        base=ctx[1];
        start=(u8 *)base+*(u16 *)((u8 *)base+0x22);
        end=(u8 *)start+((s32)ctx[2]<<4);
        ctx[3]=(void *)fn_801053E4((s32)start,(s32)end,&sp8,fn_80104930);
        entry=ctx[3];
        if(end==entry || *(u16 *)entry!=sp8) {
            ctx[3]=(void *)fn_80105474((s32)start,(s32)end,&lbl_80366E80,fn_80104930);
            entry=ctx[3];
            if(end==entry || *(u16 *)entry!=0x8199U) ctx[3]=start;
        }
    }
    *arg1=*(s8 *)((u8 *)ctx[3]+12);
    return next;
}
#pragma scheduling reset
void *fn_80105284(void *arg0, void *arg1) {
    void *FileCache_Load(void *);
    u8 *file;
    u16 sum;
    u16 off;
    u32 n;
    u16 *p;

    *(u8 **)((u8 *)arg0 + 4) = FileCache_Load(arg1);
    file = *(u8 **)((u8 *)arg0 + 4);
    sum = *(u16 *)(file + 0x8) + *(u16 *)(file + 0xA);
    *(u16 *)(file + 0x12) = sum;
    *(u16 *)(file + 0x10) = sum;
    off = *(u16 *)(file + 0x22);
    n = (*(u32 *)(file + 0x24) - off) >> 4;
    *(u32 *)((u8 *)arg0 + 8) = n;
    p = (u16 *)(*(u8 **)((u8 *)arg0 + 4) + *(u16 *)(file + 0x22) + ((*(u32 *)((u8 *)arg0 + 8) - 1) * 0x10));
    while (*p == 0) {
        p = (u16 *)((u8 *)p - 0x10);
        *(u32 *)((u8 *)arg0 + 8) -= 1;
    }
    *(u8 **)((u8 *)arg0 + 0xC) = *(u8 **)((u8 *)arg0 + 4) + *(u16 *)(file + 0x22);
    return *(void **)((u8 *)arg0 + 4);
}

void *fn_80105334(void *arg0, s16 arg1) {
    void fn_8005C7E8(void *);
    void Heap_Free(void *);
    void fn_800C4588(void *);
    void *p;

    if (arg0 != NULL) {
        if (M2C_FIELD(arg0, s32 *, 0) != 0) {
            p = M2C_FIELD(arg0, void **, 4);
            if (p != NULL) {
                fn_800C4588(p);
                M2C_FIELD(arg0, void **, 4) = NULL;
                goto clear;
            }
        }
        p = M2C_FIELD(arg0, void **, 4);
        if (p != NULL) {
            fn_8005C7E8(p);
        }
    clear:
        M2C_FIELD(arg0, void **, 4) = NULL;
        M2C_FIELD(arg0, s32 *, 0) = 0;
        M2C_FIELD(arg0, s32 *, 8) = 0;
        M2C_FIELD(arg0, s32 *, 0xC) = 0;
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_801053CC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
}

#pragma use_lmw_stmw on
s32 fn_801053E4(s32 arg0, s32 arg1, u16 *arg2, u8 (*arg3)(s32, u16)) {
 s32 count; s32 mid_ptr; s32 mid;
 count = (arg1-arg0)/16;
 while(count>0) { mid=count/2; mid_ptr=arg0+mid*16; if(arg3(mid_ptr,*arg2)!=0) {arg0=mid_ptr+16; count-=mid+1;} else {count=mid;} }
 return arg0;
}
#pragma use_lmw_stmw on
s32 fn_80105474(s32 arg0, s32 arg1, s32 *arg2, u8 (*arg3)(s32, u16)) {
s32 key;
s32 count;
s32 mid_ptr;
s32 mid;

key=*arg2;
count=(arg1-arg0)/16;

while(count>0) {
mid=count/2;
mid_ptr=arg0+(mid<<4);
if(arg3(mid_ptr,(u16)key)!=0) {
arg0=mid_ptr+0x10;
count-=mid+1;
} else count=mid;
}
return arg0;
}
#pragma use_lmw_stmw off
extern u16 lbl_802734D0;
extern u32 jumptable_8028F290[];
