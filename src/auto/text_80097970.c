/* Functions from 0x8007C5E4 to 0x8009F0BC, found by decomp-toolkit. */
#include "common.h"
typedef struct EventResourceRequest { s16 code; s16 active; u32 flags; } EventResourceRequest;
#include "global.h"
static inline u8 Event_ScanPositiveArg(u8 *s,s32 start) {
u8 found;
*(s16 *)s=start;
*(s16 *)s=(s16)start+1;
found=0;
for(;;){
switch(s[(*(s16 *)s*4)+4]){
case 0:case 0x20:case 0x21:case 0x22:case 0x24:
case 0x50:case 0x51:case 0x52:return found;
case 9:case 0x15:
if((s8)*(s16 *)(s+(*(s16 *)s*4)+6)>0)found=1;
break;
}
++*(s16*)s;
}
}

static inline u32 Event_ScanCommandFlagsInline(s16 *idx,s32 cur) {
extern u8 gBattle[];
void fn_800973F0(void *,s32);
s16 saved=(s16)cur;
s32 flagb,cursor,offset;
u8 ok;
*idx=cur;flagb=0;*idx=(s16)cur+1;
for(;;){
cursor=*idx;offset=cursor*4+4;
switch((s32)((u8*)idx)[offset]){
case 0:case 0x20:case 0x21:case 0x22:case 0x24:case 0x50:case 0x51:case 0x52:case 0x54:goto scan3done;
case 9:case 0x15:
if((s8)*(s16*)((u8*)idx+cursor*4+6)==0)flagb|=0x20000;break;
default:offset=cursor*4+4;fn_800973F0(&flagb,((u8*)idx)[offset]);break;
}
(*idx)++;
}
scan3done:
*idx=saved;
if(flagb&0x10000004){
*idx=cur;*idx=(s16)cur+1;ok=0;
for(;;){
cursor=*idx;offset=cursor*4+4;
switch((s32)((u8*)idx)[offset]){
case 0:case 0x20:case 0x21:case 0x22:case 0x24:case 0x50:case 0x51:case 0x52:goto scan4done;
case 9:case 0x15:
if((s8)*(s16*)((u8*)idx+cursor*4+6)>0)ok=1;break;
default:break;
}
(*idx)++;
}
scan4done:
*idx=cur;if(ok)flagb|=1;
}

return flagb;
}

static inline void *Event_SelectCommandResource(void **slot,u32 flags,s32 code,s32 kind) {
extern u8 gEventCmdStrings[];
void *fn_80055204(void *,s32);
void *str;
if(kind==1)return 0;
if(code==0x52)return 0;
if(flags&0x1000000)return gEventCmdStrings+0xDB;
if(flags&0x20000)return gEventCmdStrings+0xED;
if(flags&2)return gEventCmdStrings+0xFA;
if(slot){str=fn_80055204(*slot,1);if(str)return str;}
if(flags&0x40)return gEventCmdStrings+0x105;
if(code==0x51)return gEventCmdStrings+0x114;
if(code==0x50)return gEventCmdStrings+0xFA;
return 0;
}

extern void* lbl_803674E8;
extern f32 lbl_803696C8;

extern s32 gSaveDataBase;
extern void *lbl_8026CC58;
extern void *lbl_80289998;
extern f32 gScreenOrigin;
extern f32 lbl_803696A8;
extern f32 lbl_803696AC;

extern void* gActiveFace;
extern s32 gFaceDbgMouthStartStr;
extern s32 gFaceDbgMouthEndStr;
extern f64 lbl_803693C8;
extern f32 lbl_803693D4;
extern f32 lbl_803693D8;
extern f32 gFaceDbgTextScale;

extern u8 gBattleState[1400];

extern u16 *lbl_803674E0;

#pragma inline

extern f32 lbl_8036A118;
extern f32 lbl_8036A120;
extern f32 lbl_8036A130;
extern f32 gTextScale2;

extern f32 lbl_80369768;
extern u16 lbl_80289A60[];

extern u8 lbl_80289B00[16];

extern void* fn_800980D4(s32 arg0);
extern void fn_8017E394(void* arg0, void* arg1, void* arg2, s32 arg3);

extern u8 lbl_80289EB8[16];

extern f32 lbl_803697E0;
extern f32 lbl_803697E4;

#pragma scheduling reset

/* Return the debug name string for a single event command flag bit. */

/* Look up the resource pointer for a single event command flag bit. */

#pragma cplusplus on
#pragma global_optimizer off
#pragma use_lmw_stmw on

#pragma cplusplus reset
#pragma global_optimizer reset
/* Load model/gfx (mode 8) for the units stored in event slots 0-2. */

#pragma global_optimizer off
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma global_optimizer reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma opt_common_subs off

#pragma opt_common_subs reset
typedef struct {
    u8 pad[0x8A0];
    s16 value;
} lbl_80330EAC_t;

void fn_80097970(void) {
    extern u16 gBattle[];
    fn_800340E4(&gBattle[0x8A0 / sizeof(u16)]);
}

void fn_8009799C(void) {
    extern u8 gEventSlots[];
    u8 *p = gEventSlots;
    s32 i;
    for (i = 0; i < 3; i++, p += 0x14) {
        void *u = *(void **)p;
        if (u != NULL) {
            void *t = *(void **)((u8 *)u + 0x280);
            if (t != NULL) *(s8 *)((u8 *)t + 0x16C) = -1;
        }
    }
}

void fn_800979FC(void) {
 s8 fn_8004ABD4(void *,s32);
 extern u8 gBattle[]; extern u8 gEventSlots[];
 u8 *it; u8 *tbl; s32 i; void *p; void *q; s32 ca8;
 it=gEventSlots; tbl=gBattle;
 for(i=0;i<3;i++) {
 p=*(void **)it;
 if(p!=NULL && *(u32 *)((u8 *)p+0x280)!=0) {
 if(p==NULL) q=NULL;
 else if(*(u32 *)(q=(u8 *)p+0x28C)==0) q=NULL;
 ca8=*(s32 *)(tbl+0xCA8);
 *(u8 *)((u8 *)*(void **)((u8 *)*(void **)it+0x280)+0x16C)=fn_8004ABD4(q,ca8<=1);
 }
 it+=0x14;
 }
}

#pragma push
#pragma optimization_level 3
void fn_80097AB4(void) {
    extern u8 gEventSlots[], gBattle[];
    extern void *lbl_80367500, *lbl_80367504;
    extern const f32 lbl_803697BC;
    void fn_800340E4(void *);
    u8 *base = gEventSlots;
    u8 *script = gBattle + 0x8a0;
    u8 *second = base + 0x14;
    u8 *other;
    s16 saved;
    s32 value = 0;
    s32 i;

    for (i = 0; i < 3; i++) {
        u8 *slot = base + i * 0x14;
        M2C_FIELD(slot, void **, 0) = 0;
        M2C_FIELD(slot, f32 *, 4) = lbl_803697BC;
        M2C_FIELD(slot, f32 *, 8) = lbl_803697BC;
        M2C_FIELD(slot, f32 *, 12) = lbl_803697BC;
        M2C_FIELD(slot, f32 *, 16) = lbl_803697BC;
    }

    {
        saved = *(s16 *)script;
        M2C_FIELD(gEventSlots, void **, 0) = gBattle;
        fn_800340E4(script);
        other = gBattle + 0x2e0;
        for (;;) {
            s32 offset = *(s16 *)script * 4;
            switch ((s32)script[offset + 4]) {
                case 0:
                case 0x54:
                    goto done00;
                case 4:
                    if (gBattle == M2C_FIELD(gEventSlots, void **, 0))
                        value = (s8)((s16 *)script)[*(s16 *)script * 2 + 3];
                    break;
                case 16:
                    if (other == M2C_FIELD(gEventSlots, void **, 0))
                        value = (s8)((s16 *)script)[*(s16 *)script * 2 + 3];
                    break;
            }
            ++*(s16 *)script;
        }
    done00:
        *(s16 *)script = saved;
        M2C_FIELD(gEventSlots, f32 *, 4) = value;
    }
    {
        s32 value = 0;
        fn_800340E4(script);
        for (;;) {
            s32 offset = *(s16 *)script * 4;
            switch ((s32)script[offset + 4]) {
                case 0:
                case 0x54:
                    goto done01;
                case 3:
                    if (gBattle == M2C_FIELD(gEventSlots, void **, 0))
                        value = (s8)((s16 *)script)[*(s16 *)script * 2 + 3];
                    break;
                case 15:
                    if (other == M2C_FIELD(gEventSlots, void **, 0))
                        value = (s8)((s16 *)script)[*(s16 *)script * 2 + 3];
                    break;
            }
            ++*(s16 *)script;
        }
    done01:
        *(s16 *)script = saved;
        M2C_FIELD(gEventSlots, f32 *, 16) = M2C_FIELD(gEventSlots, f32 *, 4);
        M2C_FIELD(gEventSlots, f32 *, 8) = value;
        M2C_FIELD(gEventSlots, f32 *, 12) = lbl_803697BC;
    }

    {
        s16 saved1 = *(s16 *)script;
        s32 value = 0;
        M2C_FIELD(second, void **, 0) = other;
        fn_800340E4(script);
        for (;;) {
            s32 offset = *(s16 *)script * 4;
            switch ((s32)script[offset + 4]) {
                case 0:
                case 0x54:
                    goto done10;
                case 4:
                    if (gBattle == M2C_FIELD(second, void **, 0))
                        value = (s8)((s16 *)script)[*(s16 *)script * 2 + 3];
                    break;
                case 16:
                    if (other == M2C_FIELD(second, void **, 0))
                        value = (s8)((s16 *)script)[*(s16 *)script * 2 + 3];
                    break;
            }
            ++*(s16 *)script;
        }
    done10:
        *(s16 *)script = saved1;
        M2C_FIELD(base, f32 *, 24) = value;
        value = 0;
        fn_800340E4(script);
        for (;;) {
            s32 offset = *(s16 *)script * 4;
            switch ((s32)script[offset + 4]) {
                case 0:
                case 0x54:
                    goto done11;
                case 3:
                    if (gBattle == M2C_FIELD(second, void **, 0))
                        value = (s8)((s16 *)script)[*(s16 *)script * 2 + 3];
                    break;
                case 15:
                    if (other == M2C_FIELD(second, void **, 0))
                        value = (s8)((s16 *)script)[*(s16 *)script * 2 + 3];
                    break;
            }
            ++*(s16 *)script;
        }
    done11:
        *(s16 *)script = saved1;
        M2C_FIELD(base, f32 *, 36) = M2C_FIELD(base, f32 *, 24);
        M2C_FIELD(base, f32 *, 28) = value;
        M2C_FIELD(base, f32 *, 32) = lbl_803697BC;
    }

    {
        s16 saved2 = *(s16 *)script;
        s32 value = 0;
        M2C_FIELD(base, void **, 40) = gBattle + 0x5c0;
        fn_800340E4(script);
        for (;;) {
            s32 offset = *(s16 *)script * 4;
            switch ((s32)script[offset + 4]) {
                case 0:
                case 0x54:
                    goto done20;
                case 4:
                    if (gBattle == M2C_FIELD(base, void **, 40))
                        value = (s8)((s16 *)script)[*(s16 *)script * 2 + 3];
                    break;
                case 16:
                    if (other == M2C_FIELD(base, void **, 40))
                        value = (s8)((s16 *)script)[*(s16 *)script * 2 + 3];
                    break;
            }
            ++*(s16 *)script;
        }
    done20:
        *(s16 *)script = saved2;
        M2C_FIELD(base, f32 *, 44) = value;
        value = 0;
        fn_800340E4(script);
        for (;;) {
            s32 offset = *(s16 *)script * 4;
            switch ((s32)script[offset + 4]) {
                case 0:
                case 0x54:
                    goto done21;
                case 3:
                    if (gBattle == M2C_FIELD(base, void **, 40))
                        value = (s8)((s16 *)script)[*(s16 *)script * 2 + 3];
                    break;
                case 15:
                    if (other == M2C_FIELD(base, void **, 40))
                        value = (s8)((s16 *)script)[*(s16 *)script * 2 + 3];
                    break;
            }
            ++*(s16 *)script;
        }
    done21:
        *(s16 *)script = saved2;
        M2C_FIELD(base, f32 *, 56) = M2C_FIELD(base, f32 *, 44);
        M2C_FIELD(base, f32 *, 48) = value;
        M2C_FIELD(base, f32 *, 52) = lbl_803697BC;
    }

    {
        void *p = gEventSlots;
        if (p && (*(void **)p ? M2C_FIELD(*(void **)p, u32 *, 0x280) : 0)) {
            lbl_80367500 = p;
        } else {
            lbl_80367500 = 0;
        }
        p = second;
        if (p && (*(void **)p ? M2C_FIELD(*(void **)p, u32 *, 0x280) : 0)) {
            lbl_80367504 = p;
        } else {
            lbl_80367504 = 0;
        }
    }
    fn_800340E4(script);
}
#pragma pop
s32 fn_80098094(void) {
    extern s32 lbl_80367500;
    return lbl_80367500;
}

void *fn_8009809C(void) {
    extern u8 gBattle[];
    extern char gEventSlots[];
    extern void *lbl_80367500;
    extern void *lbl_80367504;

    if ((*(u32 *)(gBattle + 0xCAC) & 0x100) != 0) {
        return gEventSlots + 0x14;
    }
    if (lbl_80367504 == NULL) {
        return lbl_80367500;
    }
    return lbl_80367504;
}

void *fn_800980D4(s32 arg0) {
    extern u16 gEventSlots[];
    return (u8 *)gEventSlots + arg0 * 0x14;
}

s32 Event_GetSlotUnit(s32 arg0)
{
    extern u8 gEventSlots[];
    void *p = *(void **)(gEventSlots + arg0 * 0x14);
    if (p != NULL) {
        return M2C_FIELD(p, s32 *, 0x280);
    }
    return 0;
}

s32 fn_80098110(void) {
    extern void **lbl_80367504;
    void *temp_r3;

    if ((void **) lbl_80367504 == NULL) {
        return 0;
    }
    temp_r3 = *lbl_80367504;
    if (temp_r3 != NULL) {
        return M2C_FIELD(temp_r3, s32 *, 0x280);
    }
    return 0;
}

s32 fn_80098140(void) {
    extern void **lbl_80367500;
    void *temp_r3;

    if ((void **) lbl_80367500 == NULL) {
        return 0;
    }
    temp_r3 = *lbl_80367500;
    if (temp_r3 != NULL) {
        return M2C_FIELD(temp_r3, s32 *, 0x280);
    }
    return 0;
}
