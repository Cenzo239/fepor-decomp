/* Functions from 0x8022CD68 to 0x80267A7C, found by decomp-toolkit. */
#include "common.h"
static inline s32 Synth_CalculatePortamento(s32 pitch, u8 *voice, s32 delta) {
 s32 finalPitch,t2,i;
        finalPitch = pitch;
        if ((*(u64 *)(voice + 0x114) & 0x400ULL) != 0) {
            t2 = (u32)(*(s32 *)(voice + 0x138) - *(s32 *)(voice + 0x140)) >> 8;
            if (t2 > 0) {
                i = *(u32 *)(voice + 0x13C);
                *(u32 *)(voice + 0x13C) =
                    i + ((delta * ((s32)(pitch - i) >> 8)) / t2);
                if ((i < (u32)pitch && *(u32 *)(voice + 0x13C) < (u32)pitch) ||
                    (i > (u32)pitch && *(u32 *)(voice + 0x13C) > (u32)pitch)) {
                    finalPitch = *(s32 *)(voice + 0x13C);
                    *(s32 *)(voice + 0x140) += delta;
                } else {
                    *(s32 *)(voice + 0x140) = *(s32 *)(voice + 0x138);
                }
            }
        }

        if ((*(u64 *)(voice + 0x114) & 0x20000000000ULL) != 0) {
            finalPitch += (*(s16 *)(voice + 0x210) * (*(s32 *)(voice + 0x1F0) >> 16)) >> 7;
        }

 return finalPitch;
}

typedef struct SoundBucketNode { struct SoundBucketNode *next, *prev; u8 flags, index; u16 pad; } SoundBucketNode;
static inline void SoundBucket_Unlink(SoundBucketNode *node, s32 offset) {
extern u8 lbl_8034C964[];
SoundBucketNode *next = node->next;
SoundBucketNode *prev;
if(next) next->prev=node->prev;
prev=node->prev;
if(prev) prev->next=node->next;
else *(SoundBucketNode **)(lbl_8034C964+node->index*12+offset)=node->next;
}
extern u64 lbl_8029F3D0[4];
extern u32 lbl_8029F3F0[4];
extern u8 lbl_8034D034[];
extern f32 lbl_802A4590[512];
extern u32 lbl_803596F0[8];
extern u32 lbl_8029F400[8];
extern u32 lbl_8029F420[4];
extern u8 lbl_8034CBB4[];

typedef struct AudioGroupSlot { void *node; s32 id; void *data; } AudioGroupSlot;
typedef struct AudioGroupState { u8 pad[8]; s16 count; u16 padA; AudioGroupSlot slots[128]; } AudioGroupState;
typedef struct SynthMessageSlots { u8 pad[0xAC]; u32 slots[32]; } SynthMessageSlots;
typedef struct SynthMessageQueue { u8 pad[0x444]; u32 slots[4]; } SynthMessageQueue;
typedef struct SynthMsgSlot { u8 pad[0x444]; u32 value; } SynthMsgSlot;
typedef struct SampleKey { s32 data; u16 id; u16 type; u16 ref; u16 pad; } SampleKey;
typedef struct SoundKeyEntry { u16 id; s8 key; u8 pan; s16 volume; u16 pad; } SoundKeyEntry;
/* 10-byte bank table entry looked up by Sound_FindEntry / used by Sound_Start. */
typedef struct SoundEntry {
    u16 id;
    u16 progId;
    u8 group;
    u8 channel;
    u8 volume;
    u8 pan;
    u8 key;
    u8 flags;
} SoundEntry;
typedef struct AudioTableRange { u16 count; u16 start; } AudioTableRange;
typedef struct AudioTableEntry { s32 data; u16 id; u16 ref; } AudioTableEntry;
typedef struct SynthVmState { u8 pad[0xAC]; s32 regs[16]; } SynthVmState;
typedef struct SynthInsn {
    u32 flagA : 8;
    u32 storeReg : 8;
    u32 storeMode : 8;
    u32 pad0 : 8;
    union {
        struct { u32 pad1 : 8; s32 imm : 16; u32 regA : 8; } f;
        struct { u32 pad1 : 8; u32 regB : 8; u32 modeB : 8; u32 regA : 8; } b;
    } u;
} SynthInsn;
static inline u8 *FindAudioResource(void *data, u16 id, u32 offset) {
    u8 *node;
    if (data == NULL) return NULL;
    node = (u8 *)data + *(u32 *)((u8 *)data + offset);
    while (*(u32 *)node != 0xFFFFFFFF) {
        if (*(u16 *)(node + 4) == id) return node;
        node += *(u32 *)node;
    }
    return NULL;
}
typedef struct SynthStateLink { u8 pad[0xEC]; s32 next; u8 padF0[0x458 - 0xF0]; } SynthStateLink;
typedef s32 Fn80256FF0Arg;
typedef struct ThpDecodeState { f32 tables[3][64]; u8 pad[0x398]; u16 count; u16 pad69A; u8 *cursor; u32 pad6A0; u32 bits; } ThpDecodeState;
static inline u32 ThpReadByte(void) {
extern ThpDecodeState *lbl_80368950;
u8 *p=lbl_80368950->cursor;
lbl_80368950->cursor=p+1;
return *p;
}
static inline u16 ThpReadWord(void) {
extern ThpDecodeState *lbl_80368950;
u8 **cursor=&lbl_80368950->cursor;
u8 *p=*cursor;
u16 value=(p[0]<<8)|p[1];
*cursor=p+2;
return value;
}
static inline u8 SynthAllocateStream(void) {
extern u8 gSoundStreamCtrl[];
u8 i;
for(i=0;i<gSoundStreamCtrl[0];i++){
if(gSoundStreamCtrl[i*0x2c+8]==0){
u8 *p=gSoundStreamCtrl+i*0x2c;
p[8]=1;*(u32*)(p+12)=0;return i;
}
}
return 255;
}
typedef struct SynthFreeNode { u8 prev, next; u16 active; } SynthFreeNode;

/* Sound ARAM DMA slot: ARQRequest plus user completion (MusyX owner 0x2A). */
typedef struct SoundAramDmaSlot {
    s32 next;
    s32 owner;
    s32 type;
    s32 priority;
    s32 mramAddr;
    s32 aramAddr;
    s32 length;
    void *callback;
    s32 userCb;
    s32 userArg;
} SoundAramDmaSlot;
typedef struct SoundAramDmaQueue {
    SoundAramDmaSlot slots[16];
    volatile u8 next;
    volatile u8 count;
} SoundAramDmaQueue;

extern u16 lbl_80366F28;
extern char lbl_80282AE8[];
extern u8 gSoundReady;
extern u8 lbl_803689B0;
extern u8 gSoundData[]; char lbl_80282B20[];
extern u8 gSoundData[];
extern f64 lbl_8036C368;
extern u16 Ecb_8033E188[192];u16 *D_80256B30;
extern s32 UART_Initialized;
extern f32 lbl_8036C374;
extern s32 gSynthTimeHi;
extern s32 gSynthTimeLo;
extern s32 gSynthSchedList;
extern s32 gSynthIdleList;
extern u32* lbl_80368A38;
extern void (*lbl_80368B34)(s16);
extern f32 lbl_8034C324[];
extern s32 D_80368AD0;
extern s32 lbl_80368B0C;
extern void (*__atexit_funcs[])(void);
extern s32 __atexit_curr_func;
extern void (*__console_exit)(void);
extern s32 __aborting;
extern void (*__stdio_exit)(void);
extern void (**_dtors)(void);
extern void _ExitProcess(void);
extern s16 lbl_802A1E90[];
extern u8 lbl_80368AAE;
extern u8 lbl_80368AAD;
extern u16 lbl_8035BF18[];
extern u32 lbl_8035C918[];

u32 fn_8026367C(void);
u16 Sound_GetChanParam(u8 arg0, u8 arg1, u8 arg2);
s32 __cvt_fp2unsigned(f32 arg0);
void Sound_SetVoiceEnvelope(u8 arg0, void *arg1, s32 arg2);
void fn_8026146C(s32 *);
void fn_8025FFC8(void *arg0, u8 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5);
s32 Sound_LookupVid();
extern void func_80013934(s32 arg0);
extern s32 gSynthVoices;
extern u8 lbl_803548B8[1536];
extern u16 lbl_80368A08;
extern u16 lbl_8035A510[];
extern u16 lbl_8035D118[256];
extern u16 gSoundChanParamsDefault[4288];
extern f32 lbl_802831BC[];
extern f64 lbl_8036C348;
extern u16 lbl_803670C0;
extern u32 lbl_803670C8;
extern u32 lbl_800000F8;

#include "musyx/select_source.h"

typedef struct StreamQueueNode StreamQueueNode;
struct StreamQueueNode { StreamQueueNode *next, *prev; u32 time; };
typedef struct StreamTempo { u32 *start, *cursor; u32 value; u32 timing[4]; StreamQueueNode *head; u32 buffers[4]; u8 active, pad31; u16 scale, count; } StreamTempo;
static inline void StreamQueueInsert(StreamQueueNode **head, StreamQueueNode *node) {
StreamQueueNode *prev=0,*cur=*head;
while(cur){if(cur->time>node->time){node->next=cur;node->prev=prev;if(prev)prev->next=node;else *head=node;cur->prev=node;return;}prev=cur;cur=cur->next;}
node->prev=prev;if(prev)prev->next=node;else *head=node;node->next=0;
}
typedef struct StreamMsg {
    u32 unk0;   /* 0x0 */
    u32 unk4;   /* 0x4 */
    u32 unk8;   /* 0x8 */
    void *unkC; /* 0xC */
    void *unk10; /* 0x10 */
    u8 unk14;   /* 0x14 */
    u8 unk15;   /* 0x15 */
    u8 pad16[2];
} StreamMsg; /* 0x18 */

typedef struct StreamSeqEvent {
    u32 unk0; /* 0x0 */
    u8 pad4[4];
    u16 unk8; /* 0x8 */
    u16 unkA; /* 0xA */
} StreamSeqEvent; /* 0xC */

typedef struct StreamSeqChan {
    u32 unk0; /* 0x0 */
    StreamSeqEvent *unk4; /* 0x4 */
} StreamSeqChan; /* 0x8 */

typedef struct StreamChannel {
    u32 unk0; /* 0x0 */
    u32 unk4; /* 0x4 */
    u8 *unk8; /* 0x8 */
    u8 padC[0xC];
    u32 unk18; /* 0x18 */
    u8 pad1C[8];
    u32 unk24; /* 0x24 */
    u8 pad28[4];
} StreamChannel; /* 0x2C */

typedef struct StreamVoice {
    u8 unk0;
    u8 pad1[0x37];
} StreamVoice;

typedef struct StreamState {
    u8 pad0[0x124];
    StreamSeqChan seqChans[72]; /* 0x124 */
    StreamChannel channels[67]; /* 0x364 */
    u8 padEE8[0x1C];
    StreamMsg msgs[64]; /* 0xF04 */
    u8 *voices; /* 0x1504 */
    u8 pad1508[0x36];
    u8 unk153E; /* 0x153E */
    StreamVoice voiceFlags[1];
} StreamState;

extern StreamState *lbl_80368968;

typedef struct Voice {
    u8 pad0[0x110];
    u64 flags;
    u8 pad118[0x5C];
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    s32 unk188;
    u32 unk18C;
    u32 unk190;
} Voice;

typedef struct VidList {
    struct VidList *next; /* 0x0 */
    struct VidList *prev; /* 0x4 */
    u32 vid;              /* 0x8 */
    u32 root;             /* 0xC */
} VidList;

extern u32 vidGenerator;

static u32 GetNewVid(void) {
    u32 vid;

    do {
        vid = vidGenerator++;
    } while (vid == 0xFFFFFFFF);
    return vid;
}

typedef struct GroupData {
    u8 pad0[4];
    u16 id;     /* 0x04 */
    u16 type;   /* 0x06 */
    u8 pad8[0x1C - 0x8];
    u32 unk1C;  /* 0x1C */
    u32 unk20;  /* 0x20 */
    u32 unk24;  /* 0x24 */
} GroupData;

typedef struct GroupEntry {
    GroupData *data; /* 0x0 */
    u32 unk4;        /* 0x4 */
    u32 base;        /* 0x8 */
} GroupEntry;

typedef struct GroupNode {
    struct GroupNode *next; /* 0x0 */
    u32 unk4;               /* 0x4 */
    s16 count;              /* 0x8 */
    GroupEntry entries[1];  /* 0xC */
} GroupNode;

typedef struct GroupItem {
    u16 id;
    u8 pad2[0x52];
} GroupItem;

typedef struct SynthVoice {
    struct SynthVoice *next; /* 0x000 */
    struct SynthVoice *prev; /* 0x004 */
    u8 state;                /* 0x008 */
    u8 id;                   /* 0x009 */
    u16 unkA;                /* 0x00A */
    u32 vid;                 /* 0x00C */
    u8 pad10[0xF4 - 0x10];
    u32 unkF4;               /* 0x0F4 */
    struct VidList *unkF8;   /* 0x0F8 */
    struct VidList *unkFC;   /* 0x0FC */
    u8 pad100[0x11C - 0x100];
    s32 unk11C;              /* 0x11C */
    s32 unk120;              /* 0x120 */
    u8 pad124[0xE64 - 0x124];
    VidList *lists[2];
    VidList *listE6C;
    u8 padE70[0xEF0 - 0xE70];
    s32 unkEF0;              /* 0xEF0 */
    s32 unkEF4;              /* 0xEF4 */
    u16 unkEF8;              /* 0xEF8 */
    u8 unkEFA;               /* 0xEFA */
    u8 padEFB[0x1508 - 0xEFB];
    struct {
        u8 pad0[0x32];
        u16 unk32;
        u8 pad34[4];
    } unk1508[16];           /* 0x1508 */
} SynthVoice;

typedef struct {
    char gpr;
    char fpr;
    char reserved[2];
    char *input_arg_area;
    char *reg_save_area;
} __va_list;
typedef __va_list va_list[1];

typedef struct {
    char *buffer;
    s32 length;
    s32 position;
} __OutStr;

s32 __pformatter(s32 (*)(void *, const char *, u32), void *, const char *, va_list);
s32 fn_80232220(void *, const char *, u32);

// The structure being used in functions in this file - assumed based on offset 0xF4
typedef struct {
    u8 unkF4;  // This is likely the member accessed in function with 0xF4 offset 
} SStructType;

extern s32 fn_802314D8(s32, s32, s32);

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern f64 lbl_8036C148;

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma inline_depth(0)

#pragma inline_depth(8)
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma push
#pragma global_optimizer on

#pragma pop

#pragma opt_strength_reduction off
#pragma use_lmw_stmw on

#pragma use_lmw_stmw off
#pragma opt_strength_reduction on

#pragma global_optimizer off
#pragma scheduling off

#pragma scheduling reset
#pragma global_optimizer reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma optimization_level 3

#pragma optimization_level reset

static inline u32 SynthFindVoice(u32 arg0) {
    extern SynthVoice *gActiveVoices;
    extern SynthVoice *gKeyedVoices;
    SynthVoice *p;
    for (p = gKeyedVoices; p != NULL; p = p->next) {
        if (p->vid == (arg0 & 0x7FFFFFFF)) {
            return p->id | (arg0 & 0x80000000);
        }
    }
    for (p = gActiveVoices; p != NULL; p = p->next) {
        if (p->vid == (arg0 & 0x7FFFFFFF)) {
            return p->id | (arg0 & 0x80000000);
        }
    }
    return -1;
}

#pragma global_optimizer on

/* Key off a synth voice by vid: demote active to keyed list, or clear deferred key-off flag. */

#pragma dont_inline on
#pragma opt_common_subs off

#pragma opt_common_subs reset
#pragma dont_inline reset

#pragma dont_inline on

#pragma dont_inline reset

#pragma opt_strength_reduction off

#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
#pragma opt_strength_reduction reset

void fn_80247D74(void)
{
    extern SynthVoice gSynthVoicePool[];
    extern SynthVoice *gKeyedVoices;
    extern SynthVoice *gActiveVoices;
    extern SynthVoice *lbl_8036896C;
    extern VidList *lbl_80368964;
    extern u16 lbl_8034BDD0[];
    extern u8 lbl_8033E590[];
    extern u32 lbl_80368958;

    struct { VidList *node; VidList *prev; SynthVoice *sv; u16 *table; void *z; } s;
    u32 i = 0;
    u32 j;

    s.z = 0;
    gKeyedVoices = s.z;
    gActiveVoices = s.z;
    s.sv = gSynthVoicePool;
    s.table = lbl_8034BDD0;

    for (; i < 8; i++, s.sv++) {
        if (i == 0) {
            lbl_8036896C = s.sv;
            s.sv->prev = s.z;
        } else {
            s.sv[-1].next = s.sv;
            s.sv->prev = &gSynthVoicePool[i - 1];
        }

        s.table[0] = 0xFFFF;
        s.table[1] = 0xFFFF;
        s.table[2] = 0xFFFF;
        s.table[3] = 0xFFFF;
        s.table[4] = 0xFFFF;
        s.table[5] = 0xFFFF;
        s.table[6] = 0xFFFF;
        s.table[7] = 0xFFFF;
        s.table[8] = 0xFFFF;
        s.table[9] = 0xFFFF;
        s.table[10] = 0xFFFF;
        s.table[11] = 0xFFFF;
        s.table[12] = 0xFFFF;
        s.table[13] = 0xFFFF;

        s.sv->id = i;

        s.table[14] = 0xFFFF;
        s.sv->state = 0;

        s.table[15] = 0xFFFF;
        s.table += 16;
    }

    s.prev = NULL;
    j = (u32)s.prev;

    gSynthVoicePool[i - 1].next = s.z;
    lbl_80368964 = (VidList *)lbl_8033E590;
    s.sv = (SynthVoice *)lbl_8033E590;
    *(void **)((u8 *)s.sv + 4) = s.prev;

    for (; j < 0x100; j++) {
        if (s.prev != NULL) {
            *(void **)s.prev = (void *)s.sv;
        }
        s.prev = (VidList *)s.sv;
        *(void **)((u8 *)s.sv + 0x18) = s.prev;
        s.sv = (SynthVoice *)((u8 *)s.sv + 0x14);
    }

    *(void **)s.prev = NULL;

    lbl_80368958 = 0;
}

void fn_80247F1C(u32 arg0, u8 arg1, u8 arg2) {
extern u8 lbl_8034BED0[];
if (arg1 == 0xFF) arg1=8;
*(u32 *)(lbl_8034BED0 + (arg1 << 6) + (arg2 << 2)) = ((arg0 << 3)*0x600u)/240u;
}

s32 fn_80247F60(void *arg0) {
    extern u8 lbl_8034BED0[];
    u8 temp_r0;
    u32 var_r4;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x122);
    var_r4 = 8;
    if (temp_r0 != 0xFF) {
        var_r4 = temp_r0;
    }
    return *(s32 *)((u8 *) lbl_8034BED0 + (var_r4 << 6) + (M2C_FIELD(arg0, u8 *, 0x123) << 2));
}

#pragma opt_strength_reduction off
#pragma global_optimizer off
void fn_80247F94(void *arg0) {
u64 flags = *(u64 *)((u8 *)arg0 + 0x114);
if ((flags & 0x20000ULL) != 0) return;
if (*(u8 *)((u8 *)arg0 + 0x133) == 1) {
if ((flags & 0x1000ULL) == 0)
*(u32 *)((u8 *)arg0 + 0x140) = 0;
else
*(u32 *)((u8 *)arg0 + 0x140) = *(u32 *)((u8 *)arg0 + 0x138);
} else {
*(u32 *)((u8 *)arg0 + 0x140) = *(u32 *)((u8 *)arg0 + 0x138);
}
*(u32 *)((u8 *)arg0 + 0x13C) = (u32)*(u8 *)((u8 *)arg0 + 0x132) << 16;
}
#pragma global_optimizer reset
#pragma opt_strength_reduction reset
s32 Sound_RemapVoiceKey(u8 key, u8 group, u8 channel, s32 isMaster, s32 *status) {
    void fn_80255B20(void *);
    s32 Sound_AddVid(void *, s32);
    void fn_80257614(void *);
    void fn_80260174(u8, u8, u8);
    u32 Sound_IsHwVoiceActive(u32);
    s32 offset;
    u32 keyValue;
    u32 i;
    u32 result;
    s32 previous;
    u8 *voice;
    u8 *last;
    s32 found;
    u64 flags;

    keyValue = key;
    voice = (u8 *)gSynthVoices;
    found = 0;
    result = -1;
    i = 0;
    offset = 0;
    for (; i < gSoundData[0x210]; offset += 0x458, i++, voice += 0x458) {
        if (voice[0x11C] == 0 && (u32)(*(s32 *)(voice + 0xF4) + 0x10000) != 0xFFFF && voice[0x121] == group &&
            voice[0x122] == channel) {
            flags = *(u64 *)(voice + 0x114);
            if ((flags & 2ULL) != 0) {
                found = 1;
            }
            if ((flags & 0x10ULL) != 0 && (flags & 0x10000000008ULL) != 8ULL && Sound_IsHwVoiceActive(i) != 0) {
                if (result == 0xFFFFFFFF && 0x20002ULL == (0x20002ULL & *(u64 *)(voice + 0x114))) {
                    *status = 1;
                    return -1;
                }
                *(s32 *)(voice + 0x13C) = (*(u16 *)(voice + 0x12E) << 16) + (((s8)voice[0x130] << 16) / 100);
                last = voice;
                voice[0x132] = *(u16 *)(voice + 0x12E);
                *(u16 *)(voice + 0x12E) = keyValue + ((u8)*(u16 *)(voice + 0x12E) - voice[0x131]);
                voice[0x131] = key;
                voice[0x130] = 0;
                *(s32 *)(voice + 0x140) = 0;
                *(u64 *)(voice + 0x114) |= 0x20000ULL;
                fn_80255B20((u8 *)gSynthVoices + offset);
                if (result == 0xFFFFFFFF) {
                    *(s32 *)(voice + 0xEC) = -1;
                    *(s32 *)(voice + 0xF0) = -1;
                    result = Sound_AddVid((u8 *)gSynthVoices + offset, isMaster);
                    previous = *(s32 *)(voice + 0xF4);
                } else {
                    ((SynthStateLink *)gSynthVoices)[(u8)previous].next = *(s32 *)(voice + 0xF4);
                    *(s32 *)(voice + 0xF0) = previous;
                    previous = *(s32 *)(voice + 0xF4);
                    Sound_AddVid((u8 *)gSynthVoices + offset, 0);
                }
            }
        }
    }
    if (result != 0xFFFFFFFF) {
        fn_80257614(last);
        fn_80260174(last[0x121], last[0x122], (u8)*(u16 *)(last + 0x12E));
        *status = 0;
    } else {
        *status = found;
    }
    return result;
}

s32 fn_802482AC(u16 id, s16 volume, s32 arg2, s32 arg3, u8 key, u8 velocity, u8 pan, u8 channel, u8 a8, u8 a9, u16 a10, u16 a11, u32 a12, u8 a13, u8 a14, s32 a15) {
    s32 fn_8025094C(u16, u16 *);
    s32 fn_802555A0(u16, u8, s32, s32, u8, u8, u8, u8, u8, u8, u16, u16, u32, u8, u8, s32);
    s32 fn_8024866C(u16, s16, s32, s32, u8, u8, u8, u8, u8, u8, u16, u16, u32, u8, u8, s32);
    s32 fn_80255E88(void *);
    extern s32 gSynthVoices;
    u32 low;
    s32 note;
    u32 high;
    s32 result;
    s32 last;
    u8 *entry;
    s32 first;
    u16 sample;
    s32 balance;
    s32 flags;
    u8 vel;
    u32 savedPan;
    u32 savedVel;
    u32 valid;
    s32 status;
    u16 count;
    u8 savedVelocity;

    savedVelocity = velocity;
    first = -1;
    entry = (u8 *)fn_8025094C(id, &count);
    if (entry) {
        savedPan = pan;
        low = key & 127;
        high = key & 128;
        savedVel = savedVelocity;
        while (count) {
            sample = *(u16 *)entry;
            if (sample != 65535 && entry[2] <= low && entry[3] >= low) {
                s32 value = low + (s8)entry[4];
                if (value > 127) note = 127;
                else note = value < 0 ? 0 : value;
                if (!(sample & 0xC000)) {
                    if (Sound_GetChanParam(0x41, channel, a8) > 0x1F80U) {
                        result = Sound_RemapVoiceKey(note & 127, channel, a8, 0, &status);
                        valid = status == 0;
                    } else {
                        result = -1;
                        valid = 1;
                    }
                    if (!valid) goto next;
                    if ((u32)(result + 0x10000) != 0xFFFF) goto link;
                }
                if (!(entry[8] & 128)) {
                    s32 tmp = entry[8] - 64;
                    tmp += savedPan;
                    if (tmp < 0) balance = 0;
                    else balance = (tmp > 127) ? 127 : tmp;
                } else {
                    balance = 128;
                }
                vel = (u8)((s32)(savedVel * entry[5]) / 127);
                volume += *(s16 *)(entry + 6);
                volume = (s16)(volume > 255 ? 255 : (volume < 0 ? 0 : volume));
                flags = *(u16 *)entry & 0xC000;
                switch (flags) {
                case 0:
                    result = fn_802555A0(*(u16 *)entry, (u8)volume, arg2, arg3, (u8)(note | high), vel, (u8)balance, channel, a8, a9, a10, a11, 0, a13, a14, a15);
                    break;
                case 0x4000:
                    result = fn_8024866C(*(u16 *)entry, volume, arg2, arg3, (u8)(note | high), vel, (u8)balance, channel, a8, a9, a10, a11, 0, a13, a14, a15);
                    break;
                case 0x8000:
                    result = fn_802482AC(*(u16 *)entry, volume, arg2, arg3, (u8)(note | high), vel, (u8)balance, channel, a8, a9, a10, a11, 0, a13, a14, a15);
                    break;
                }
                if ((u32)(result + 0x10000) != 0xFFFF) {
                link:
                    if ((u32)(first + 0x10000) == 0xFFFF) {
                        if (a12) first = fn_80255E88((u8 *)gSynthVoices + (u8)result * 0x458);
                        else first = result;
                    } else {
                        *(s32 *)((u8 *)gSynthVoices + (u8)last * 0x458 + 0xEC) = result;
                        *(s32 *)((u8 *)gSynthVoices + (u8)result * 0x458 + 0xF0) = last;
                    }
                    last = result;
                    while ((u32)(*(s32 *)((u8 *)gSynthVoices + (u8)last * 0x458 + 0xEC) + 0x10000) != 0xFFFF) {
                        *((u8 *)gSynthVoices + (u8)last * 0x458 + 0x11C) = 1;
                        last = *(s32 *)((u8 *)gSynthVoices + (u8)last * 0x458 + 0xEC);
                    }
                    *((u8 *)gSynthVoices + (u8)last * 0x458 + 0x11C) = 1;
                }
            }
        next:
            entry += 12;
            count--;
        }
    }
    return first;
}

#pragma global_optimizer off
s32 fn_8024866C(u16 id, s16 volume, s32 arg2, s32 arg3, s32 key, s32 arg5, u8 pan, s32 arg7, u8 a8, u8 a9, u16 a10, u16 a11, s32 a12, u8 a13, u8 a14, s32 a15) {
    s32 fn_802508E0(u16);
    u16 Sound_GetChanParam(u8, s32, u8);
    s32 Sound_RemapVoiceKey(s32, s32, u8, s32, s32 *);
    s32 fn_802482AC(u16, s16, s32, s32, u8, s32, u8, s32, u8, u8, u16, u16, u8, u8, u8, s32);
    s32 fn_802555A0(u16, u8, s32, s32, u8, s32, u8, s32, u8, u8, u16, u16, u8, u8, u8, s32);
    u16 sample;
    s32 status;
    u32 valid;
    s32 result;
    s32 value;
    s32 flags;
    s32 note;
    u8 original;
    u8 *row;
    u8 *alt;
    u8 *entry;
    u8 *table;
    u32 low;
    u32 offset;

    table = (u8 *)fn_802508E0(id);
    if (table != 0) {
        original = key;
        offset = (key & 0x7F) * 8;
        low = key & 127;
        entry = table + offset;
        sample = *(u16 *)entry;
        if (sample != 0xFFFF) {
            flags = sample & 0xC000;
            if (flags != 0x4000) {
                if (!(entry[3] & 0x80)) {
                    alt = table + ((u8)key << 3);
                    value = alt[3] - 0x40;
                    value += pan;
                    if (value < 0)
                        pan = 0;
                    else if (value > 127)
                        pan = 127;
                    else
                        pan = (u8)value;
                } else
                    pan = 128;
                row = table + offset;
                note = low + *(s8 *)(row + 2);
                if (note > 127)
                    key = 127;
                else
                    key = note & ~(note >> 31);
                volume += *(s16 *)(row + 4);
                volume = (s16)(volume > 255 ? 255 : (volume < 0 ? 0 : volume));
                if (flags == 0) {
                    if (Sound_GetChanParam(0x41, arg7, a8) > 0x1F80U) {
                        result = Sound_RemapVoiceKey(key & 127, arg7, a8, a12, &status);
                        valid = status == 0;
                    } else {
                        result = -1;
                        valid = 1;
                    }
                    if (valid == 0)
                        return -1;
                    if ((u32)(result + 0x10000) != 0xFFFF)
                        return result;
                    return fn_802555A0(*(u16 *)entry, (u8)volume, arg2, arg3, (u8)(key | (original & 128)), arg5, pan, arg7, a8, a9, a10, a11, (u8)a12, a13, a14, a15);
                }
                return fn_802482AC(sample, volume, arg2, arg3, (u8)(key | (original & 128)), arg5, pan, arg7, a8, a9, a10, a11, (u8)a12, a13, a14, a15);
            }
        }
    }
    return -1;
}

#pragma opt_strength_reduction off
s32 fn_802488C8(u16 id, u8 volume, u8 arg2, s32 arg3, u8 key, s32 arg5, u8 pan, u8 arg7, u8 a8, u8 a9, u16 a10, u16 a11, u8 a13, s16 addVolume, u8 a14, s32 a15)
{
  u8 *fn_802508E0(u16);
  u8 new_var2;
  s32 fn_802482AC(u16, s16, u8, s32, u8, s32, u8, u8, u8, u8, u16, u16, u8, u8, u8, s32);
  s32 fn_802555A0(u16, u8, u8, s32, u8, s32, u8, u8, u8, u8, u16, u16, u8, u8, u8, s32);
  s32 status; s32 status2; s32 new_var; u32 valid;
  volume = volume + addVolume;
  new_var2 = pan;
  volume = (volume > 255U) ? (255) : (volume);
  switch (id & 0xC000)
  {
    case 0:
    {
      s32 r;
      if (Sound_GetChanParam(0x41, arg7, a8) > 0x1F80U)
      {
        r = Sound_RemapVoiceKey(key & 127, arg7, a8, 1, &status);
        valid = status == 0;
      }
      else { r = -1; valid = 1; }
      if (!valid) return -1;
      if (((u32) (r + 0x10000)) != 0xFFFF) return r;
      return fn_802555A0(id, volume, arg2, arg3, key, arg5, new_var2, arg7, a8, a9, a10, a11, 1, a13, a14, a15);
    }
    case 0x4000:
    {
      s32 result;
      u8 *table = (u8 *) fn_802508E0(id);
      if (table != 0)
      {
        u8 original = key & 0xFF;
        u32 offset = (key & 0x7F) * 8;
        u32 low = key & 127;
        u8 *entry = table + offset;
        u16 sample = *((u16 *) entry);
        if (sample != 0xFFFF)
        {
          s32 flags = sample & 0xC000;
          if (flags != 0x4000)
          {
            s32 value; s32 note; s16 v; u8 *alt; u8 *row; u8 newPan;
            if (!(entry[3] & 0x80))
            {
              alt = table + (((u8) key) << 3);
              value = alt[3] - ((0, 0x40));
              value += new_var2;
              if (value < 0) newPan = 0;
              else if (value > 127) newPan = 127;
              else newPan = (u8) value;
            }
            else newPan = 128;
            row = table + offset;
            note = low + (*((s8 *) (row + 2)));
            if (note > 127) key = 127;
            else key = note & (~(note >> 31));
            v = volume + (*((s16 *) (row + 4)));
            if (v > 255) v = 255;
            else v = v & (~(v >> 31));
            if (flags == 0)
            {
              s32 r;
              u8 k;
              k = key;
              if (Sound_GetChanParam(0x41, arg7, a8) > 0x1F80U)
              {
                r = Sound_RemapVoiceKey(k & 127, arg7, a8, 1, &status2);
                valid = status2 == 0;
              }
              else { r = -1; valid = 1; }
              if (!valid) result = -1;
              else if (((u32) (r + 0x10000)) != 0xFFFF) result = r;
              else result = fn_802555A0(*((u16 *) entry), (u8) v, arg2, arg3, (u8) (key | (original & 128)), arg5, newPan, arg7, a8, a9, a10, a11, 1, a13, a14, a15);
            }
            else result = fn_802482AC(sample, v, arg2, arg3, (u8) (key | (original & 128)), arg5, newPan, arg7, a8, a9, a10, a11, 1, a13, a14, a15);
            goto done4000;
          }
        }
      }
      result = -1;
      done4000:
      if (((u32) (result + 0x10000)) != 0xFFFF)
      {
        s32 voice = Sound_LookupVid(result);
        while (((u32) (voice + 0x10000)) != 0xFFFF)
        {
          s32 offset = ((u8) voice) * 0x458;
          *((((u8 *) gSynthVoices) + offset) + 0x11C) = 0;
          voice = *((s32 *) ((((u8 *) gSynthVoices) + offset) + 0xEC));
        }
      }
      return result;
    }
    case 0x8000:
      new_var = fn_802482AC(id, volume, arg2, arg3, key, arg5, new_var2, arg7, a8, a9, a10, a11, 1, a13, a14, a15);
    {
      s32 result = new_var;
      if (((u32) (result + 0x10000)) != 0xFFFF)
      {
        s32 voice = Sound_LookupVid(result);
        while (((u32) (voice + 0x10000)) != 0xFFFF)
        {
          s32 offset = ((u8) voice) * 0x458;
          *((((u8 *) gSynthVoices) + offset) + 0x11C) = 0;
          voice = *((s32 *) ((((u8 *) gSynthVoices) + offset) + 0xEC));
        }
      }
      return result;
    }
    default: return -1;
  }
}
#pragma push
#pragma cplusplus on
#pragma optimization_level 3
extern "C" void fn_80248D28(s32 arg0)
{
    extern s32 gSynthVoices;
    extern s32 lbl_803689B8;
    extern s32 lbl_803689BC;
    u32 Sound_IsHwVoiceActive(u32);
    s16 fn_80261214(u16);
    u32 fn_8025807C(s32, s32, s32);
    s32 fn_80260764(void *);
    s32 fn_802607F4(void *);
    u16 Sound_GetChanParam(s32, u8, u8);
    s32 fn_8025785C(u8, s32);
    u16 fn_80257820(u16);
    u16 fn_802607AC(void *);
    void fn_80261BC8(s32, u16);
    void fn_80249C1C(void *, s32, s32);

    u16 spA;
    u16 sp8;
    u8 *p;
    s32 i;
    s32 delta;
    s32 pitch;
    u8 *voice;
    s32 t;
    s32 t2;
    u16 w;
    u32 modulation;
    s32 finalPitch;
    u64 flags;
    u64 now;

    voice = (u8 *)gSynthVoices + arg0 * 0x458;
    if (Sound_IsHwVoiceActive(arg0) != 0 || *(u32 *)(voice + 0x34) != 0) {
        p = voice;
        i = 0;
        now = *(u64 *)&lbl_803689B8;
        delta = (s32)(now - *(u64 *)(voice + 0x24));
        *(u64 *)(voice + 0x24) = now;
        do {
            if (*(u32 *)(p + 0x1C4) != 0) {
                *(u32 *)(p + 0x1C0) += delta;
                {
                    u32 per = *(u32 *)(p + 0x1C4);
                    u32 pos = *(u32 *)(p + 0x1C0);
                    w = (u16)(((pos % per) * 0x10) / (per >> 8));
                    *(s16 *)(p + 0x1C8) = fn_80261214(w);
                }
                if (*(s16 *)(p + 0x1C8) != *(s16 *)(p + 0x1CA)) {
                    *(s16 *)(p + 0x1CA) = *(s16 *)(p + 0x1C8);
                    t = i + 0x1D8;
                    if (voice[t] != 0) {
                        voice[t] = 0;
                        *(u32 *)(voice + 0x220) |= 0x7FFF;
                    }
                }
            }
            i += 1;
            p += 0xC;
        } while ((u32)i < 2U);

        if ((*(u64 *)(voice + 0x114) & 0x2000ULL) != 0) {
            *(u32 *)(voice + 0x14C) += delta;
            {
                u32 per = *(u32 *)(voice + 0x148);
                u32 pos = *(u32 *)(voice + 0x14C);
                *(s32 *)(voice + 0x150) =
                    (s16)fn_80261214((u16)(((pos % per) * 0x10) / (per >> 8)));
            }
        }

        if ((voice[0x1BC] | voice[0x1BD]) != 0) {
            t = (delta << 4) & 0x0FFFFFF0;
            t2 = delta & 0x0FFFFFFF;
            if (voice[0x1BC] != 0) {
                *(s32 *)(voice + 0x1B4) -= t;
                if (*(s32 *)(voice + 0x1B4) <= 0) {
                    *(s32 *)(voice + 0x1B4) = voice[0x1BC] << 16;
                    *(s32 *)(voice + 0x1A4) = 0;
                } else {
                    *(s32 *)(voice + 0x1A4) += (*(s32 *)(voice + 0x1AC) >> 12) * t2;
                }
            }
            if (voice[0x1BD] != 0) {
                *(s32 *)(voice + 0x1B8) -= t;
                if (*(s32 *)(voice + 0x1B8) <= 0) {
                    *(s32 *)(voice + 0x1B8) = voice[0x1BD] << 16;
                    *(s32 *)(voice + 0x1A8) = 0;
                } else {
                    *(s32 *)(voice + 0x1A8) += (*(s32 *)(voice + 0x1B0) >> 12) * t2;
                }
            }
        }

        p = voice;
        for (i=0;i<2;i++) {
            if (*(u32 *)(p + 0x174) != *(u32 *)(p + 0x184)) {
                *(s32 *)(p + 0x18C) -= delta;
                t = *(s32 *)(p + 0x18C);
                if (t <= 0) {
                    *(u32 *)(p + 0x174) = *(u32 *)(p + 0x184);
                    *(s32 *)(p + 0x18C) = 0;
                } else {
                    *(u32 *)(p + 0x174) =
                        *(u32 *)(p + 0x184) - (((u32)t >> 8) * *(u32 *)(p + 0x17C));
                    t2 = *(s32 *)(p + 0x174);
                    if (t2 < 0) {
                        t = 0;
                    } else {
 t=0x7F0000;
 if((u32)t2 <= 0x7F0000U)t=t2;
 }
                    *(s32 *)(p + 0x174) = t;
                }
                *(u32 *)(voice + 0x114) |= 0x2000;
            }
            p += 4;
        }

        if ((*(u64 *)(voice + 0x114) & 0x20000000000ULL) != 0) {
            if (fn_8025807C((s32)(voice + 0x1E8), (s32)&spA, (s32)&sp8) != 0) {
                *(u64 *)(voice + 0x114) &= ~0x20000000000ULL;
            }
        }

        pitch = (*(u16 *)(voice + 0x12E) << 16) + (((s8)voice[0x130] << 16) / 100);
        if ((*(u64 *)(voice + 0x114) & 0x10030ULL) != 0) {
 if(voice[0x121]==0xFF) goto pitchDone;
 t=fn_80260764(voice);
 *(u16*)(voice+0x1DC)=t;
 t=(u16)t;
 } else t=*(u16*)(voice+0x1DC);
 if(t!=0x2000) {
 t-=0x2000;
 if(t<0)pitch+=voice[0x1DA]*t*8;
 else pitch+=voice[0x1DB]*t*8;
 }
pitchDone:

        if ((*(u64 *)(voice + 0x114) & 0x2000ULL) != 0) {
            modulation = fn_802607F4(voice);
            t = (voice[0x144] << 8) + ((voice[0x145] << 8) / 100);
            if (*(s16 *)(voice + 0x154) != 0) {
                t += (*(s16 *)(voice + 0x154) * ((s32)(u16)modulation >> 7)) >> 7;
            }
            if ((*(u64 *)(voice + 0x114) & 0x4000ULL) != 0) {
                t2 = (*(s32 *)(voice + 0x150) * ((s32)(u16)modulation >> 7)) >> 7;
            } else {
                t2 = *(s32 *)(voice + 0x150);
            }
            pitch += (t * t2) >> 4;
        }

        if (voice[0x121] != 0xFF) {
            w = Sound_GetChanParam(0x41, voice[0x121], voice[0x122]);
            if (w != *(u16 *)(voice + 0x134) ||
                (*(u64 *)(voice + 0x114) & 0x21000ULL) == 0x20000ULL) {
                if (w <= 0x1F80U) {
                    *(u64 *)(voice + 0x114) &= ~0x400ULL;
                } else {
                    flags = *(u64 *)(voice + 0x114);
                    if ((flags & 0x400ULL) == 0 && (flags & 0x20000ULL) == 0) {
                        if (voice[0x133] == 1) {
                            if ((flags & 0x1000ULL) == 0) {
                                *(s32 *)(voice + 0x140) = 0;
                            } else {
                                *(s32 *)(voice + 0x140) = *(s32 *)(voice + 0x138);
                            }
                        } else {
                            *(s32 *)(voice + 0x140) = *(s32 *)(voice + 0x138);
                        }
                        *(u32 *)(voice + 0x13C) = voice[0x132] << 16;
                    }
                    *(u32 *)(voice + 0x118) |= 0x400;
                }
                *(u32 *)(voice + 0x118) |= 0x1000;
                *(u16 *)(voice + 0x134) = w;
            }
        }

        finalPitch = pitch;
        if ((*(u64 *)(voice + 0x114) & 0x400ULL) != 0) {
            t2 = (u32)(*(s32 *)(voice + 0x138) - *(s32 *)(voice + 0x140)) >> 8;
            if (t2 > 0) {
                i = *(u32 *)(voice + 0x13C);
                *(u32 *)(voice + 0x13C) =
                    i + ((delta * ((s32)(pitch - i) >> 8)) / t2);
                if ((i < (u32)pitch && *(u32 *)(voice + 0x13C) < (u32)pitch) ||
                    (i > (u32)pitch && *(u32 *)(voice + 0x13C) > (u32)pitch)) {
                    finalPitch = *(s32 *)(voice + 0x13C);
                    *(s32 *)(voice + 0x140) += delta;
                } else {
                    *(s32 *)(voice + 0x140) = *(s32 *)(voice + 0x138);
                }
            }
        }

        if ((*(u64 *)(voice + 0x114) & 0x20000000000ULL) != 0) {
            finalPitch += (*(s16 *)(voice + 0x210) * (*(s32 *)(voice + 0x1F0) >> 16)) >> 7;
        }

        pitch = fn_8025785C((u8)((u32)finalPitch >> 16), *(s32 *)(voice + 0x124)) << 16;
        finalPitch = (u16)finalPitch;
        if (finalPitch != 0) {
            t2 = (u32)pitch >> 16;
            pitch += finalPitch * (fn_80257820((u16)t2) - t2);
        }
        pitch = *(s32 *)(voice + 0x1A8) + pitch;
        pitch = *(s32 *)(voice + 0x1A4) + pitch;
        w = (u16)((((u32)pitch >> 16) * fn_802607AC(voice)) >> 13);
        *(u16 *)(voice + 0x212) = w;
        fn_80261BC8(arg0, w);
        fn_80249C1C(voice, 0, 0xF00);
    }

    if (voice[0xA8] != 0) {
        voice[0xA8] = 0;
        *(u32 *)(voice + 0x220) = 0x7FFF;
    }
}
#pragma pop
#pragma cplusplus off
void fn_8024946C(s32 arg0)
{
    u32 Sound_IsHwVoiceActive(s32);
    u16 fn_8026068C(void *);
    u16 fn_802606D4(void *);
    u16 fn_8026071C(void *);
    u16 fn_802607F4(void *);
    u16 fn_80260884(void *);
    u16 fn_802608CC(void *);
    u16 fn_80260914(void *);
    u16 fn_8026095C(void *);
    s16 fn_802609A4(void *);
    u16 fn_802609EC(void *);
    u16 fn_80260A34(void *);
    void fn_80261E6C(s32, u32, u32, u32, f32, f32, f32);
    void fn_80261C98(u32, u16 *, u16 *);
    void fn_80261D90(s32, s32, u16, u16);
    void fn_8026171C(s32, u32);
    u8 fn_802616EC(void);
    void fn_80249C1C(void *, s32, s32);

    extern s32 gSynthVoices;
    extern s32 lbl_803689B8;
    extern s32 lbl_803689BC;
    extern s32 lbl_803689A4;
    extern f32 lbl_8034C324[];
    extern u8 lbl_8034C924[];
    extern f32 lbl_8036C1D0;
    extern f32 lbl_8036C1D4;
    extern f32 lbl_8036C1D8;
    extern f32 lbl_8036C1DC;
    extern f32 lbl_8036C1E0;
    extern f32 lbl_8036C1E4;
    extern f32 lbl_8036C1E8;
    extern f32 lbl_8036C1EC;
    extern f32 lbl_8036C1F0;

    u8 *voice;
    u64 timestamp;
    u64 previousTimestamp;
    u64 flags64;
    u32 delta;
    u32 globalFlags;
    u32 flags;
    u32 value;
    u32 end;
    u32 start;
    u32 packed;
    u32 capacity;
    u32 position;
    s32 step;
    s32 target;
    s32 result;
    s32 dirty;
    s32 index;
    s32 group;
    u16 phaseA;
    u16 phaseB;
    u16 resultA;
    u16 resultB;
    f32 volume;
    f32 pitch;
    f32 gain;
    f32 outputA;
    f32 outputB;
    f32 current;
    f32 wanted;
    f32 adjustment;

    voice = (u8 *)gSynthVoices + arg0 * 0x458;

    if (Sound_IsHwVoiceActive(arg0) != 0) {
        goto finish;
    }
    if (*(u32 *)(voice + 0x34) == 0) {
        goto finish;
    }

    timestamp = ((u64)(u32)lbl_803689B8 << 32) | (u32)lbl_803689BC;
    previousTimestamp = *(u64 *)(voice + 0x2C);
    delta = (u32)(timestamp - previousTimestamp);
    *(u64 *)(voice + 0x2C) = timestamp;

    flags64 = *(u64 *)(voice + 0x114);
    dirty = 0;
    if ((flags64 & 0x8000ULL) != 0) {
        step = *(s32 *)(voice + 0x198);
        value = *(u32 *)(voice + 0x1A0);
        value += step * (delta >> 8);
        *(u32 *)(voice + 0x1A0) = value;

        target = *(s32 *)(voice + 0x19C);
        if (step < 0) {
            if (target >= (s32)value) {
                *(s32 *)(voice + 0x1A0) = target;
                *(u64 *)(voice + 0x114) &= ~0x8000ULL;
            }
        } else {
            if (target <= (s32)value) {
                *(s32 *)(voice + 0x1A0) = target;
                *(u64 *)(voice + 0x114) &= ~0x8000ULL;
            }
        }
        *(u32 *)(voice + 0x158) = *(u32 *)(voice + 0x1A0);
        dirty = 1;
    } else {
        dirty = (flags64 & ((u64)0x1000 << 32)) != 0;
    }
    *(u64 *)(voice + 0x114) &= ~((u64)0x1000 << 32);

    index = (s32)voice[0x11E];
    group = (voice[0x11D] != 0) + 0x15;
    volume = lbl_8034C324[index * 12];
    volume = lbl_8034C324[index * 12 + 5] * volume;
    volume = volume * lbl_8034C324[group * 12];
    if (voice[0x120] != 0xFF) {
        volume = lbl_8036C1D0 * (volume * (f32)lbl_8034C924[voice[0x120]]);
    }
    if (volume != *(f32 *)(voice + 0x160)) {
        *(f32 *)(voice + 0x160) = volume;
        dirty = 1;
    }

    pitch = lbl_8036C1D4 * (f32)*(u32 *)(voice + 0x158);

    phaseA = *(u16 *)(voice + 0x170);
    phaseB = *(u16 *)(voice + 0x172);
    if ((phaseA | phaseB) != 0) {
        u32 parameter = fn_802607F4(voice);
        s32 angle = (s16)fn_802609A4(voice);
        s32 shift = 0x2000 - ((0x4000 - angle) >> 1);

        adjustment = lbl_8036C1D8 * (f32)shift;
        wanted = lbl_8036C1DC *
            ((f32)phaseA * (lbl_8036C1E0 -
            lbl_8036C1E4 * ((f32)parameter * (f32)(0x1000 - phaseB))));
        current = *(f32 *)(voice + 0x16C);
        if (current < wanted) {
            current += lbl_8036C1E8;
            *(f32 *)(voice + 0x16C) = current;
            if (current > wanted) {
                *(f32 *)(voice + 0x16C) = wanted;
            }
        } else if (current > wanted) {
            current -= lbl_8036C1E8;
            *(f32 *)(voice + 0x16C) = current;
            if (current < wanted) {
                *(f32 *)(voice + 0x16C) = wanted;
            }
        }
        dirty = 1;
        pitch *= lbl_8036C1E0 - adjustment *
                 (lbl_8036C1E0 - *(f32 *)(voice + 0x16C));
    }

    globalFlags = (u32)lbl_803689A4;
    if ((globalFlags & 1) == 0) {
        flags = *(u32 *)(voice + 0x114);
        if ((flags & 0x2000) != 0 || (*(u32 *)(voice + 0x220) & 6) != 0) {
            *(u64 *)(voice + 0x114) &= ~((u64)0x2000 << 32);

            result = (s32)((u16)fn_802606D4(voice)) - 0x2000;
            result = *(s32 *)(voice + 0x174) + (s32)((u32)result << 9);
            if (result < 0) {
                result = 0;
            } else if (result > 0x7F0000) {
                result = 0x7F0000;
            }
            *(u32 *)(voice + 0x164) = (u32)result;

            if ((globalFlags & 2) != 0) {
                value = *(u32 *)(voice + 0x178) + ((u32)(u16)fn_8026071C(voice) << 9);
                *(u32 *)(voice + 0x168) = value;
                if (value > 0x7F0000U) {
                    *(u32 *)(voice + 0x168) = 0x7F0000U;
                }
            } else {
                *(u32 *)(voice + 0x168) = 0;
            }
            dirty = 1;
        } else if ((globalFlags & 2) == 0) {
            *(u32 *)(voice + 0x168) = 0;
        }
    } else {
        *(u32 *)(voice + 0x164) = 0x400000;
        *(u32 *)(voice + 0x168) = 0;
        flags64 = *(u64 *)(voice + 0x114);
        dirty |= (flags64 & ((u64)0x2000 << 32)) != 0;
        *(u64 *)(voice + 0x114) = flags64 & ~((u64)0x2000 << 32);
    }

    if (dirty != 0) {
        if ((*(u32 *)(voice + 0x220) & 0xF01) != 0) {
            value = fn_8026068C(voice);
            gain = lbl_8036C1EC * ((pitch * volume) * (f32)value);

            value = fn_802608CC(voice);
            outputA = lbl_8036C1D0 *
                ((f32)voice[0x194] *
                 (lbl_8036C1EC * (gain * (f32)value)));

            value = fn_80260884(voice);
            outputB = (lbl_8036C1EC * (pitch * (f32)value)) +
                      outputA + lbl_8036C1D0 * (f32)voice[0x195];

            value = fn_8026095C(voice);
            outputA = lbl_8036C1EC * (gain * (f32)value);

            value = fn_80260914(voice);
            outputA += lbl_8036C1EC * (pitch * (f32)value);

            *(s16 *)(voice + 0x454) = (s16)(lbl_8036C1F0 * gain);
            fn_80261E6C(arg0, voice[0x196],
                         *(u32 *)(voice + 0x164),
                         *(u32 *)(voice + 0x168),
                         gain, outputB, outputA);
        }
    }

    if ((*(u32 *)(voice + 0x220) & 0x6000) != 0) {
        value = fn_802609EC(voice);
        if ((u16)value > 0x1FFF) {
            value = fn_80260A34(voice);
            start = *(u32 *)(voice + 0x1E0);
            end = *(u32 *)(voice + 0x1E4);
            position = (u32)((lbl_8036C1E0 -
                       lbl_8036C1EC * (f32)(u16)value) *
                       (f32)(end - start));
            fn_80261C98(start + position, &resultA, &resultB);
            fn_80261D90(arg0, 1, resultA, resultB);
        } else {
            fn_80261D90(arg0, 0, 0, 0);
        }
    }

    capacity = *(u32 *)(voice + 0x110);
    if (capacity != 0) {
        result = (s32)capacity - (s32)((u32)*(u16 *)(voice + 0x10E) * delta);
        *(s32 *)(voice + 0x110) = result;
        if (result < 0) {
            *(u32 *)(voice + 0x110) = 0;
        }
        packed = (*(u32 *)(voice + 0x110) >> 15) |
                 ((u32)voice[0x10C] << 24);
        fn_8026171C(arg0, packed);
    }

    fn_80249C1C(voice, 1, (5 - (u8)fn_802616EC()) << 8);

finish:
    if (voice[0xA8] != 0) {
        voice[0xA8] = 0;
        *(u32 *)(voice + 0x220) = 0x7FFF;
    }
}

void fn_80249C1C(SoundBucketNode *arg0, s32 kind, u32 time) {
extern u8 lbl_80368979;
extern u8 lbl_8034C964[];
SoundBucketNode *prev;
SoundBucketNode *next;
SoundBucketNode **head;
SoundBucketNode *node;
u32 index;
SoundBucketNode **bucket;
u32 oldIndex;
index=((time>>8)+lbl_80368979)&31;
bucket=(SoundBucketNode **)(lbl_8034C964+index*12);
switch(kind) {
case 0:
oldIndex=arg0->index; node=arg0;
if(oldIndex!=255) {
if(oldIndex==index)return;
SoundBucket_Unlink(arg0,0);
}
head=bucket; break;
case 1:
node=arg0+1; oldIndex=node->index;
if(oldIndex!=255) {
if(oldIndex==index)return;
SoundBucket_Unlink(node,8);
}
head=bucket+2;break;
case 2:
node=arg0+2;
if(node->index!=255)return;
head=bucket+1;break;
default:break;
}
node->index=index;
next=*head;
node->next=next;
if(next)(*head)->prev=node;
node->prev=0;
*head=node;
}

#pragma scheduling on
void fn_80249D6C(void *arg0) {
    void fn_80249C1C(void *, s32, s32);
    extern s32 lbl_803689BC;
    extern s32 lbl_803689B8;
    s32 v0;
    unsigned long v1;

    v0 = lbl_803689B8;
    v1 = lbl_803689BC;
    *(s32 *)((u8 *)arg0 + 0x28) = v1;
    *(s32 *)((u8 *)arg0 + 0x24) = v0;
    v0 = lbl_803689B8;
    v1 = lbl_803689BC;
    *(s32 *)((u8 *)arg0 + 0x30) = v1;
    *(s32 *)((u8 *)arg0 + 0x2C) = v0;
    fn_80249C1C(arg0, 0, 0);
    fn_80249C1C(arg0, 1, 0);
}
