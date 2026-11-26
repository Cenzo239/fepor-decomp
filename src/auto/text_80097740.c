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

#pragma push
#pragma opt_strength_reduction off
s32 fn_80097740(void) {
    extern s16 gBattle[];
    extern u8 gEventSlots[];
    extern void *lbl_80367500;
    extern void *lbl_80367504;
    s16 *idx;
    s16 n;
    s32 result;
    s32 c;
    void *p;
    void *t;
    u32 v;

    idx = &gBattle[0x450];
    result = gBattle[0x450];
    if (result != 0) {
        *idx = result + 1;
    }
    for (;;) {
        n = *idx;
        c = ((u8 *)idx)[(n << 2) + 4];
        switch (c) {
        case 0x00:
        case 0x50:
        case 0x51:
        case 0x52:
            return result;
        case 0x54:
            result = n;
            break;
        case 0x20:
            p = (void *)gEventSlots;
            if (p != NULL) {
                t = *(void **)p;
                v = (t != NULL) ? M2C_FIELD(t, u32 *, 0x280) : 0;
                if (v != 0) {
                    lbl_80367500 = p;
                    goto h1;
                }
            }
            lbl_80367500 = NULL;
        h1:
            p = (void *)(gEventSlots + 0x14);
            if (p != NULL) {
                t = *(void **)p;
                v = (t != NULL) ? M2C_FIELD(t, u32 *, 0x280) : 0;
                if (v != 0) {
                    lbl_80367504 = p;
                    goto h2;
                }
            }
            lbl_80367504 = NULL;
        h2:
            result = *idx;
            break;
        case 0x21:
            p = (void *)(gEventSlots + 0x14);
            if (p != NULL) {
                t = *(void **)p;
                v = (t != NULL) ? M2C_FIELD(t, u32 *, 0x280) : 0;
                if (v != 0) {
                    lbl_80367500 = p;
                    goto h3;
                }
            }
            lbl_80367500 = NULL;
        h3:
            p = (void *)gEventSlots;
            if (p != NULL) {
                t = *(void **)p;
                v = (t != NULL) ? M2C_FIELD(t, u32 *, 0x280) : 0;
                if (v != 0) {
                    lbl_80367504 = p;
                    goto h4;
                }
            }
            lbl_80367504 = NULL;
        h4:
            result = *idx;
            break;
        case 0x22:
            p = (void *)(gEventSlots + 0x28);
            if (p != NULL) {
                t = *(void **)p;
                v = (t != NULL) ? M2C_FIELD(t, u32 *, 0x280) : 0;
                if (v != 0) {
                    lbl_80367500 = p;
                    goto h5;
                }
            }
            lbl_80367500 = NULL;
        h5:
            p = (void *)(gEventSlots + 0x14);
            if (p != NULL) {
                t = *(void **)p;
                v = (t != NULL) ? M2C_FIELD(t, u32 *, 0x280) : 0;
                if (v != 0) {
                    lbl_80367504 = p;
                    goto h6;
                }
            }
            lbl_80367504 = NULL;
        h6:
            result = *idx;
            break;
        case 0x24:
            result = n;
            break;
        }
        *idx = *idx + 1;
    }
}
#pragma pop
