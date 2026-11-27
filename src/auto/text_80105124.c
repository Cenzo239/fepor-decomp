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

#pragma push
#pragma cplusplus on
extern "C" s32 fn_801053E4(s32,s32,u16 *,void *);
extern "C" s32 fn_80105474(s32,s32,void *,void *);
extern "C" u32 fn_80104930(u16 *,u16);
extern "C" void *fn_80105124(u8 *arg0, s32 *arg1) {
    u16 sp8;
    u8 is_double;
    u16 code;
    void **ctx;
    u8 *next;
    void *base;
    void *end;
    void *start;
    void *entry;
    extern void *lbl_803679C0;
    ctx = (void **)lbl_803679C0;
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
        ctx[3]=(void *)fn_801053E4((s32)start,(s32)end,&sp8,(void *)fn_80104930);
        entry=ctx[3];
        if(end==entry || *(u16 *)entry!=sp8) {
            ctx[3]=(void *)fn_80105474((s32)start,(s32)end,&lbl_80366E80,(void *)fn_80104930);
            entry=ctx[3];
            if(end==entry || *(u16 *)entry!=0x8199U) ctx[3]=start;
        }
    }
    *arg1=*(s8 *)((u8 *)ctx[3]+12);
    return next;
}
#pragma pop
