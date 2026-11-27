/* Functions from 0x8022CD68 to 0x80267A7C, found by decomp-toolkit. */
#include "common.h"
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

u32 Sound_FindVoiceId(u32 arg0) {
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

#pragma push
#pragma optimization_level 4
s32 fn_80243FB8(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, u8 arg5, s16 arg6) {
    void Sound_VoiceKeyOn(void *);
    void fn_80246D48(void);
    void fn_80247F1C(s32, u8, u8);
    void fn_8024A780(u8, u16, u8, u8, s32);
    void fn_8024AD04(u8, s32, u8);
    void Sound_WriteParamU8(s32, u8, u8, s32);
    void fn_8025FB74(u8, u8, u8);
    void fn_8025FF6C(u8, u8);
    extern SynthVoice gSynthVoicePool[];
    extern u8 lbl_8034BDD0[];
    extern u8 lbl_8034C924[];
    extern u32 lbl_80368958;
    extern s32 lbl_80368960;
    extern StreamState *lbl_80368968;
    extern SynthVoice *lbl_8036896C;
    extern SynthVoice *gActiveVoices;
    extern SynthVoice *gKeyedVoices;

    SynthVoice *n;
    u8 *base;
    u8 *p;
    u8 *q;
    u8 *ep;
    u8 *row;
    u8 *src;
    u8 *dst;
    u8 *tab;
    StreamState *saved;
    u8 id;
    u8 i;
    u8 j;
    u8 v;
    s32 k;
    s32 off;
    u32 flags;
    u32 size;
    u32 vid;
    u16 val;
    s32 z;
    s32 ctr;
    s32 channel;
    register SynthVoice *sv;

    sv = lbl_8036896C;
    if (sv == NULL) {
        return -1;
    }
    n = sv->next;
    lbl_8036896C = n;
    if (n != NULL) {
        n->prev = NULL;
    }
    if ((sv->next = gKeyedVoices) != NULL) {
        gKeyedVoices->prev = sv;
    }
    sv->prev = NULL;
    gKeyedVoices = sv;
    sv->state = 1;
    base = (u8 *)sv;
    for (z = 0; z < 16; z++) {
        *(s32 *)(base + 0x1524 + z * 0x38) = 0;
    }
    base = (u8 *)sv;
    id = sv->id;
    base[0xF00] = 0;
    *(void **)(base + 0x10) = arg0;
    *(void **)(base + 0x94) = arg1;
    *(void **)(base + 0x118) = arg3;
    sv->unkA = arg6;

    p = *(u8 **)(base + 0x10);
    for (i = 0; i < 0x80; i++) {
        base[0x14 + i] = 0xFF;
    }

    j = 0;
    while (p[4] != 0xFF) {
        base[0x14 + p[4]] = j;
        p += 6;
        j++;
    }

    p = *(u8 **)(base + 0x94);
    for (i = 0; i < 0x80; i++) {
        base[0x98 + i] = 0xFF;
    }

    j = 0;
    while (p[4] != 0xFF) {
        base[0x98 + p[4]] = j;
        p += 6;
        j++;
    }

    base[0xED0] = (u8)(id + 0x17);
    for (z = 0; z < 64; z++) {
        base[0x324 + z] = base[0xED0];
    }

    base[0xF01] = arg5;
    if (arg4 == NULL) {
        *(s32 *)(base + 0x11C) = -1;
        *(s32 *)(base + 0x120) = -1;
        for (z = 0; z < 16; z++) {
            *(u16 *)(base + 0x153A + z * 0x38) = 0x100;
        }
        fn_8024A780(0x7F, 0, base[0xED0], 0, -1);
    } else {
        if (*(u32 *)arg4 & 1) {
            *(s32 *)(base + 0x11C) = *(s32 *)((u8 *)arg4 + 4);
            *(s32 *)(base + 0x120) = *(s32 *)((u8 *)arg4 + 8);
        } else {
            *(s32 *)(base + 0x11C) = -1;
            *(s32 *)(base + 0x120) = -1;
        }
        if (*(u32 *)arg4 & 2) {
            for (z = 0; z < 16; z++) {
                *(u16 *)(base + 0x153A + z * 0x38) = *(u16 *)((u8 *)arg4 + 0xC);
            }
        } else {
            for (z = 0; z < 16; z++) {
                *(u16 *)(base + 0x153A + z * 0x38) = 0x100;
            }
        }
        if (*(u32 *)arg4 & 8) {
            k = 0;
            off = 0;
            while (k < ((u8 *)arg4)[0x12]) {
                src = *(u8 **)((u8 *)arg4 + 0x14) + off;
                base[0x324 + src[0]] = src[1];
                fn_8024AD04((*(u8 **)((u8 *)arg4 + 0x14))[off + 1], 0, src[1]);
                off += 2;
                k++;
            }
        }
        if (*(u32 *)arg4 & 4) {
            fn_8024A780(((u8 *)arg4)[0x10], *(u16 *)((u8 *)arg4 + 0xE), base[0xED0], 0, -1);
            k = 0;
            while (k < ((u8 *)arg4)[0x18]) {
                fn_8024A780(((u8 *)arg4)[0x10], *(u16 *)((u8 *)arg4 + 0xE),
                            (*(u8 **)((u8 *)arg4 + 0x1C))[k], 0, -1);
                k++;
            }
        }
    }

    if (*(u32 *)((u8 *)arg3 + 0x10) & 0x80000000) {
        *(u8 **)(base + 0x1504) = (u8 *)arg3 + *(u32 *)((u8 *)arg3 + 0x54);
    } else {
        *(u8 **)(base + 0x1504) = NULL;
    }
    flags = *(u32 *)((u8 *)arg3 + 0x10);
    size = flags & 0x0FFFFFFF;
    if (!(flags & 0x40000000)) {
        size <<= 10;
    }
    row = base;
    for (channel = 0; channel < 0x10; channel++) {
        *(u32 *)(row + 0x1510) = size;
        fn_80247F1C((s32)(size >> 10), id, channel);
        if (*(u32 *)((u8 *)arg3 + 0xC) != 0) {
            *(u8 **)(row + 0x1508) = (u8 *)arg3 + *(u32 *)((u8 *)arg3 + 0xC);
            *(u8 **)(row + 0x150C) = *(u8 **)(row + 0x1508);
        } else {
            *(u8 **)(row + 0x1508) = NULL;
        }
        row[0x153E] = 0;
        *(u16 *)(row + 0x153C) = 0;
        row += 0x38;
    }

    tab = lbl_8034C924;
    src = (u8 *)arg3 + *(u32 *)arg3;
    for (z = 0; z < 64; z++) {
        tab[z] = 0x7F;
        *(s32 *)(base + 0x36C + z * 0x2C) = 0;
        if (((u32 *)src)[z] != 0) {
            p = (u8 *)arg3 + ((u32 *)src)[z];
            *(u8 **)(base + 0x124 + z * 8) = p;
            *(u8 **)(base + 0x128 + z * 8) = p;
        } else {
            *(u8 **)(base + 0x124 + z * 8) = *(u8 **)(base + 0x128 + z * 8) = NULL;
        }
    }

    *(s32 *)(base + 0xE64) = 0;
    *(s32 *)(base + 0xE68) = 0;
    *(s32 *)(base + 0xE6C) = 0;
    for (channel = 0; channel < 0x10; channel++) {
        fn_8025FB74(channel, id, 1);
    }

    for (z = 0; z < 16; z++) {
        *(u16 *)(base + 0xE70 + z * 6) = 0xFFFF;
    }

    for (channel = 0; channel < 0x10; channel++) {
        fn_8025FF6C(channel, id);
    }

    if (arg2 != NULL) {
        ep = (u8 *)arg2;
        for (channel = 0; channel < 0x10; channel++) {
            v = ep[4];
            *(u16 *)(lbl_8034BDD0 + (lbl_80368960 << 5) + ((u8)channel * 2)) = 0xFFFF;
            if ((u8)channel != 9) {
                j = base[0x14 + v];
                if (j != 0xFF) {
                    q = base + (u8)channel * 6;
                    *(u16 *)(q + 0xE70) = *(u16 *)(*(u8 **)(base + 0x10) + j * 6);
                    q[0xE72] = (*(u8 **)(base + 0x10))[j * 6 + 2];
                    q[0xE73] = (*(u8 **)(base + 0x10))[j * 6 + 3];
                    q[0xE74] = j;
                }
            } else {
                j = base[0x98 + v];
                if (j != 0xFF) {
                    p = *(u8 **)(base + 0x94) + j * 6;
                    q = base + channel * 6;
                    *(u16 *)(q + 0xE70) = *(u16 *)p;
                    q[0xE72] = p[2];
                    q[0xE73] = p[3];
                    q[0xE74] = j;
                }
            }
            Sound_WriteParamU8(7, channel, id, ep[5]);
            Sound_WriteParamU8(0xA, channel, id, ep[6]);
            Sound_WriteParamU8(0x5B, channel, id, ep[7]);
            Sound_WriteParamU8(0x5D, channel, id, ep[8]);
            ep += 5;
        }
    }

    for (z = 0; z < 16; z++) {
        ((u16 *)(lbl_8034BDD0 + (id << 5)))[z] = 0xFFFF;
    }

    for (z = 0; z < 16; z++) {
        p = base + z * 0x38;
        *(s32 *)(p + 0x152C) = 0; *(s32 *)(p + 0x1528) = 0;
        *(s32 *)(p + 0x1534) = 0; *(s32 *)(p + 0x1530) = 0;
        p[0x1538] = 0;
    }

    base[0xF02] = 0;
    if (arg4 != NULL && (*(u32 *)arg4 & 0x10)) {
        Sound_VoiceKeyOn(sv);
    }
    saved = lbl_80368968;
    lbl_80368968 = (StreamState *)sv;
    fn_80246D48();
    lbl_80368968 = saved;

    do {
        vid = lbl_80368958;
        lbl_80368958 = vid + 1;
        lbl_80368958 &= 0x7FFFFFFF;
        for (n = gKeyedVoices; n != NULL; n = n->next) {
            if (n->vid == vid) {
                vid = 0xFFFFFFFF;
                break;
            }
        }
        if (vid != 0xFFFFFFFF) {
            for (n = gActiveVoices; n != NULL; n = n->next) {
                if (n->vid == vid) {
                    vid = 0xFFFFFFFF;
                    break;
                }
            }
        }
    } while (vid == 0xFFFFFFFF);

    gSynthVoicePool[id].vid = vid;
    return (s32)vid;
}
#pragma pop
void Sound_VoiceKeyOn(SynthVoice *sv) {
    extern SynthVoice *gActiveVoices;
    extern SynthVoice *gKeyedVoices;

    if (sv->prev != NULL) {
        sv->prev->next = sv->next;
    } else {
        gKeyedVoices = sv->next;
    }
    if (sv->next != NULL) {
        sv->next->prev = sv->prev;
    }
    if ((sv->next = gActiveVoices) != NULL) {
        gActiveVoices->prev = sv;
    }
    sv->prev = NULL;
    gActiveVoices = sv;
    sv->state = 2;
}

#pragma global_optimizer on
#pragma optimization_level 3
void fn_80244AE8(s32 arg0) {
 extern SynthVoice *gActiveVoices; extern SynthVoice *gKeyedVoices;
 extern SynthVoice gSynthVoicePool[]; extern VidList *lbl_80368964;
 void fn_80257224(s32);
 u32 id, vid; SynthVoice *p, *sv; VidList *tail; u32 i; VidList *node; SynthVoice *walk; SynthVoice *walk2;
 vid=arg0&0x7FFFFFFF;
 for(p=gKeyedVoices;p!=NULL;p=p->next) {
  if(p->vid==vid) {id=p->id|(arg0&0x80000000);goto found;}
 }
 for(p=gActiveVoices;p!=NULL;p=p->next) {
  if(p->vid==vid) {id=p->id|(arg0&0x80000000);goto found;}
 }
 id=-1;
found:
 if((u32)(id+0x10000)!=0xFFFF) {
  if(!(id&0x80000000)) {
   sv=&gSynthVoicePool[id];
   if(sv->state==1) {
    if(sv->prev!=NULL) sv->prev->next=sv->next;
    else gKeyedVoices=sv->next;
    if(sv->next!=NULL) sv->next->prev=sv->prev;
    sv->next=gActiveVoices;
    if(gActiveVoices!=NULL) gActiveVoices->prev=sv;
    sv->prev=(SynthVoice *)(i=0);
    gActiveVoices=sv;
    sv->state=2;
    for(walk=sv;i<2;i++,walk=(SynthVoice*)((u8*)walk+4)) {
     for(node=walk->lists[0];node!=NULL;node=node->next) fn_80257224(node->vid);
    }
    walk2=(SynthVoice *)sv->listE6C;
    while(walk2!=NULL) {
     fn_80257224(((VidList *)walk2)->vid);
     walk2=(SynthVoice *)((VidList *)walk2)->next;
    }
    for(i=0,walk=sv;i<2;i++,walk=(SynthVoice*)((u8*)walk+4)) {
     tail=walk->lists[0];
     if(tail!=NULL) {
      while(tail->next!=NULL) tail=tail->next;
      if(lbl_80368964!=NULL) {tail->next=lbl_80368964;lbl_80368964->prev=tail;}
      lbl_80368964=walk->lists[0]; walk->lists[0]=NULL;
     }
    }
    tail=sv->listE6C;
    if(tail!=NULL) {
     while(tail->next!=NULL) tail=tail->next;
     if(lbl_80368964!=NULL) {tail->next=lbl_80368964;lbl_80368964->prev=tail;}
     lbl_80368964=sv->listE6C;sv->listE6C=NULL;
    }
   }
  } else {
   sv=&gSynthVoicePool[id&0x7FFFFFFF];
   if(sv->state!=0) sv->unkEFA|=8;
  }
 }
}
#pragma optimization_level reset
#pragma push
void fn_80244D64(s32 arg0) {
    extern SynthVoice *gActiveVoices;
    extern SynthVoice *gKeyedVoices;
    extern SynthVoice *lbl_8036896C;
    extern SynthVoice gSynthVoicePool[];
    extern VidList *lbl_80368964;
    void fn_80257224(s32);
    VidList *node;
    SynthVoice *sv;
    u32 i;
    SynthVoice *walk;
    s32 off;
    VidList *tail;

    u32 id;
    u32 vid;
    SynthVoice *p;

    vid = arg0 & 0x7FFFFFFF;
    p = gKeyedVoices;
    goto loop1_test;
loop1:
    if (p->vid == vid) {
        id = p->id | (arg0 & 0x80000000);
        goto found;
    }
    p = p->next;
loop1_test:
    if (p != NULL) {
        goto loop1;
    }
    p = gActiveVoices;
    goto loop2_test;
loop2:
    if (p->vid == vid) {
        id = p->id | (arg0 & 0x80000000);
        goto found;
    }
    p = p->next;
loop2_test:
    if (p != NULL) {
        goto loop2;
    }
    id = -1;
found:
    if ((u32)(id + 0x10000) != 0xFFFF) {
        if (!(id & 0x80000000)) {
            off = id * 0x1888;
            sv = (SynthVoice *)((u8 *)gSynthVoicePool + off);
            switch (sv->state) {
            case 1:
                if (sv->prev != NULL) {
                    sv->prev->next = sv->next;
                } else {
                    gKeyedVoices = sv->next;
                }
                i = 0;
                walk = sv;
            loop_a:
                node = walk->lists[0];
                goto loop_a_inner_test;
            loop_a_inner:
                fn_80257224(node->vid);
                node = node->next;
            loop_a_inner_test:
                if (node != NULL) {
                    goto loop_a_inner;
                }
                i += 1;
                walk = (SynthVoice *)((u8 *)walk + 4);
                if (i < 2) {
                    goto loop_a;
                }
                off = (s32)gSynthVoicePool + off;
                node = *(VidList **)(off + 0xE6C);
                goto loop_b_test;
            loop_b:
                fn_80257224(node->vid);
                node = node->next;
            loop_b_test:
                if (node != NULL) {
                    goto loop_b;
                }
                for (i = 0; i < 2; i++) {
                    tail = sv->lists[i];
                    if (tail != NULL) {
                        while (tail->next != NULL) tail = tail->next;
                        if (lbl_80368964 != NULL) {
                            tail->next = lbl_80368964;
                            lbl_80368964->prev = tail;
                        }
                        lbl_80368964 = sv->lists[i];
                        sv->lists[i] = NULL;
                    }
                }
                tail = *(VidList **)(off + 0xE6C);
                if (tail != NULL) {
                    goto find_tail3_test;
                find_tail3:
                    tail = tail->next;
                find_tail3_test:
                    if (tail->next != NULL) {
                        goto find_tail3;
                    }
                    if (lbl_80368964 != NULL) {
                        tail->next = lbl_80368964;
                        lbl_80368964->prev = tail;
                    }
                    lbl_80368964 = *(VidList **)(off + 0xE6C);
                    *(VidList **)(off + 0xE6C) = NULL;
                }
                break;
            case 2:
                if (sv->prev != NULL) {
                    sv->prev->next = sv->next;
                } else {
                    gActiveVoices = sv->next;
                }
                break;
            }
            if (sv->next != NULL) {
                sv->next->prev = sv->prev;
            }
            sv->state = 0;
            if (lbl_8036896C != NULL) {
                lbl_8036896C->prev = sv;
            }
            sv->next = lbl_8036896C;
            sv->prev = NULL;
            lbl_8036896C = sv;
        } else {
            sv = &gSynthVoicePool[id & 0x7FFFFFFF];
            if (sv->state != 0) {
                *(s32 *)((u8 *)sv + 0xEFC) = 0;
            }
        }
    }
}
#pragma pop
void fn_80245014(u16 arg0) {
    extern void *gActiveVoices;
    extern void *gKeyedVoices;
    void *var_r30;

    var_r30 = gKeyedVoices;
    while (var_r30 != NULL) {
        if ((u16) M2C_FIELD(var_r30, u16 *, 0xA) == arg0) {
            fn_80244D64(M2C_FIELD(var_r30, s32 *, 0xC));
        }
        var_r30 = M2C_FIELD(var_r30, void **, 0);
    }

    var_r30 = gActiveVoices;
    while (var_r30 != NULL) {
        if ((u16) M2C_FIELD(var_r30, u16 *, 0xA) == arg0) {
            fn_80244D64(M2C_FIELD(var_r30, s32 *, 0xC));
        }
        var_r30 = M2C_FIELD(var_r30, void **, 0);
    }
}

void Sound_SetVoicePortU16(u32 vid, u16 value) {
    /* Set the u16 at unk1508[].unk32 for all 16 ports, or queue it on the deferred voice. */
    extern SynthVoice gSynthVoicePool[];
    u32 id;
    u32 i;

    id = Sound_FindVoiceId(vid);
    if (!(id & 0x80000000)) {
        for (i = 0; i < 16; i++) {
            gSynthVoicePool[id].unk1508[i].unk32 = value;
        }
        return;
    }
    gSynthVoicePool[id & 0x7FFFFFFF].unkEFA |= 0x20;
    gSynthVoicePool[id & 0x7FFFFFFF].unkEF8 = value;
}

/* Key off a synth voice by vid: demote active to keyed list, or clear deferred key-off flag. */
void Sound_VoiceKeyOff(s32 vidArg) {
    extern SynthVoice *gActiveVoices;
    extern SynthVoice *gKeyedVoices;
    extern SynthVoice gSynthVoicePool[];
    u32 id;
    u32 vid;
    SynthVoice *p;
    SynthVoice *sv;

    vid = vidArg & 0x7FFFFFFF;
    for (p = gKeyedVoices; p != NULL; p = p->next) {
        if (p->vid == vid) {
            id = p->id | (vidArg & 0x80000000);
            goto found;
        }
    }
    for (p = gActiveVoices; p != NULL; p = p->next) {
        if (p->vid == vid) {
            id = p->id | (vidArg & 0x80000000);
            goto found;
        }
    }
    id = -1;
found:
    if (!(id & 0x80000000)) {
        sv = &gSynthVoicePool[id];
        if (sv->state == 2) {
            if (sv->prev != NULL) {
                sv->prev->next = sv->next;
            } else {
                gActiveVoices = sv->next;
            }
            if (sv->next != NULL) {
                sv->next->prev = sv->prev;
            }
            sv->next = gKeyedVoices;
            if (gKeyedVoices != NULL) {
                gKeyedVoices->prev = sv;
            }
            sv->prev = NULL;
            gKeyedVoices = sv;
            sv->state = 1;
        }
        return;
    }
    gSynthVoicePool[id & 0x7FFFFFFF].unkEFA &= ~8;
}

void fn_80245290(u32 arg0, s32 arg1, s32 arg2) {
    extern SynthVoice gSynthVoicePool[];
    u32 id;

    id = Sound_FindVoiceId(arg0);
    if (id != 0xFFFFFFFF) {
        if (!(id & 0x80000000)) {
            gSynthVoicePool[id].unk11C = arg1;
            gSynthVoicePool[id].unk120 = arg2;
        } else {
            gSynthVoicePool[id & 0x7FFFFFFF].unkEFA |= 0x10;
            gSynthVoicePool[id & 0x7FFFFFFF].unkEF0 = arg1;
            gSynthVoicePool[id & 0x7FFFFFFF].unkEF4 = arg2;
        }
    }
}

#pragma dont_inline on
#pragma opt_common_subs off
#pragma push
#pragma optimization_level 4
void fn_8024534C(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
  void fn_8024A780(s32, s32, s32, s32, s32);
  extern SynthVoice *gActiveVoices;
  extern SynthVoice *gKeyedVoices;
  extern SynthVoice gSynthVoicePool[];
  SynthVoice *keyed;
  SynthVoice *active;
  s32 key;
  s32 id;
  s32 off;
  u8 *ed0;
  u8 *base;
  u32 i;
  key = arg2 & 0x7FFFFFFF;
  while (keyed != NULL)
  {
    if (keyed->vid == ((u32) key))
    {
      id = keyed->id | (arg2 & 0x80000000);
      goto found;
    }
    keyed = keyed->next;
  }

  keyed = gKeyedVoices;
  active = gActiveVoices;
  while (active != NULL)
  {
    if (active->vid == ((u32) key))
    {
      id = active->id | (arg2 & 0x80000000);
      goto found;
    }
    active = active->next;
  }

  id = -1;
  found:
  if (((u32) (id + 0x10000)) != 0xFFFFU)
  {
    if (!(id & 0x80000000))
    {
      off = id * 0x1888;
      fn_8024A780(arg0, arg1, (((u8 *) gSynthVoicePool) + off)[0xED0], arg3, arg2);
      i = 0;
      base = ((u8 *) gSynthVoicePool) + off;
      ed0 = base + 0xED0;
      while (i < 0x40U)
      {
        if (base[0x324] != (*ed0))
        {
          fn_8024A780(arg0, arg1, base[0x324], 0, -1);
        }
        i++;
        base++;
      }

    }
    else
    {
      switch (arg3 & 0xF)
      {
        case 0:
          (((u8 *) gSynthVoicePool) + ((id & 0x7FFFFFFF) * 0x1888))[0xEEC] = arg0;
          break;

        case 1:
          *((s32 *) ((((u8 *) gSynthVoicePool) + ((id & 0x7FFFFFFF) * 0x1888)) + 0xEFC)) = 0;
          break;

        case 2:
          base = ((u8 *) gSynthVoicePool) + ((id & 0x7FFFFFFF) * 0x1888);
          base[0xEFA] |= 8;
          base[0xEEC] = arg0;
          break;

        case 3:
          base = ((u8 *) gSynthVoicePool) + ((id & 0x7FFFFFFF) * 0x1888);
          base[0xEFA] |= 0x80;
          base[0xEEC] = arg0;
          break;

      }

    }
  }

 }
#pragma pop
 #pragma opt_common_subs reset
 #pragma dont_inline reset

 #pragma push
#pragma optimization_level 4
#pragma opt_register_coloring off
void fn_80245518(void *arg0, s32 *arg1, u8 arg2) {
    void fn_8024A780(u8, u16, u8, u8, s32);
    void fn_8024B4B0(s32, s32, s32, s32);
    void fn_8024B3D8(s32, u16);
    void fn_8024B420(void);
    void fn_8024B458(s32, s32, s32);
    s32 fn_80259430(u16, u16, s32, s32 *, s32, u8);
    s32 fn_80259584(u16, u16, s32, s32 *, u8);
    typedef struct { s32 a; s32 b; } Pair;
    typedef struct {
        s32 flags;
        s32 fx;
        s32 voldown;
        u16 key;
        u16 vol;
        u8 pan;
        u8 pad19;
        u8 pad1A;
        u8 pad1B;
        s32 pad1C;
        s8 studio;
        u8 pad21[3];
        s32 pad24;
        s32 pad28;
        s32 pad2C;
    } PlayArgs;
    extern SynthVoice gSynthVoicePool[];
    extern SynthVoice *gActiveVoices;
    extern SynthVoice *gKeyedVoices;
    u32 vid;
    u32 id;
    SynthVoice *sv;
    u8 *base;
    u8 *p;
    u8 *ed0;
    u16 lim;
    u8 flags;
    u32 i;
    s32 off;
    u16 t;
    u32 k;
    s32 ret;
    PlayArgs play;
    Pair *dst;
    Pair *src;
    u8 pan;
    u32 pitch;
    u32 vol;

    id = SynthFindVoice(*(u32 *)arg0);
    flags = *((u8 *)arg0 + 0x26);
    if (flags & 4) {
        off = id * 0x1888;
        base = (u8 *)gSynthVoicePool + off;
        src = (Pair *)arg0;
        dst = (Pair *)(base + 0xED4);
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        dst[4] = src[4];
        base[0xF00] = 1;
        *(s32 **)(base + 0xEFC) = arg1;
        base[0xEFA] = (u8)(base[0xEFA] & ~4);
        *arg1 = *(u32 *)arg0 | 0x80000000;
        return;
    }
    vid = *(u32 *)arg0;
    if (arg2 != 0) {
        lim = *(u16 *)((u8 *)arg0 + 4);
        vol = 5;
        if (lim >= 5) {
            vol = lim;
        }
        vol = (u16)vol;
        if (flags & 1) {
            id = SynthFindVoice(vid);
            if ((u32)(id + 0x10000) != 0xFFFF) {
                if (!(id & 0x80000000)) {
                    off = id * 0x1888;
                    fn_8024A780(0, (u16)vol, ((u8 *)gSynthVoicePool + off)[0xED0], 2, vid);
                    p = (u8 *)gSynthVoicePool + off;
                    ed0 = p + 0xED0;
                    for (i = 0; i < 0x40; i++, p++) {
                        if (p[0x324] != *ed0) {
                            fn_8024A780(0, (u16)vol, p[0x324], 0, -1);
                        }
                    }
                } else {
                    base = (u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888;
                    base[0xEFA] = (u8)(base[0xEFA] | 8);
                    base[0xEEC] = 0;
                }
            }
        } else if (flags & 0x40) {
            id = SynthFindVoice(vid);
            if ((u32)(id + 0x10000) != 0xFFFF) {
                if (!(id & 0x80000000)) {
                    off = id * 0x1888;
                    fn_8024A780(0, (u16)vol, ((u8 *)gSynthVoicePool + off)[0xED0], 3, vid);
                    p = (u8 *)gSynthVoicePool + off;
                    ed0 = p + 0xED0;
                    for (i = 0; i < 0x40; i++, p++) {
                        if (p[0x324] != *ed0) {
                            fn_8024A780(0, (u16)vol, p[0x324], 0, -1);
                        }
                    }
                } else {
                    base = (u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888;
                    base[0xEFA] = (u8)(base[0xEFA] | 0x80);
                    base[0xEEC] = 0;
                }
            }
        } else {
            id = SynthFindVoice(vid);
            if ((u32)(id + 0x10000) != 0xFFFF) {
                if (!(id & 0x80000000)) {
                    off = id * 0x1888;
                    fn_8024A780(0, (u16)vol, ((u8 *)gSynthVoicePool + off)[0xED0], 1, vid);
                    p = (u8 *)gSynthVoicePool + off;
                    ed0 = p + 0xED0;
                    for (i = 0; i < 0x40; i++, p++) {
                        if (p[0x324] != *ed0) {
                            fn_8024A780(0, (u16)vol, p[0x324], 0, -1);
                        }
                    }
                } else {
                    base = (u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888;
                    *(s32 *)(base + 0xEFC) = 0;
                }
            }
        }
    } else if (flags & 1) {
        fn_8024B4B0(0, *(u16 *)((u8 *)arg0 + 4), (s32)vid, 2);
    } else if (flags & 0x40) {
        fn_8024B4B0(0, *(u16 *)((u8 *)arg0 + 4), (s32)vid, 3);
    } else {
        fn_8024B4B0(0, *(u16 *)((u8 *)arg0 + 4), (s32)vid, 1);
    }
    if (arg1 == NULL) {
        return;
    }
    flags = *((u8 *)arg0 + 0x26);
    if (flags & 2) {
        id = SynthFindVoice(*(u32 *)((u8 *)arg0 + 8));
        if ((u32)(id + 0x10000) != 0xFFFF) {
            if (arg2 != 0) {
                id = SynthFindVoice(*(u32 *)((u8 *)arg0 + 8));
                if (!(id & 0x80000000)) {
                    sv = (SynthVoice *)((u8 *)gSynthVoicePool + id * 0x1888);
                    if (sv->state == 2) {
                        if (sv->prev != NULL) {
                            sv->prev->next = sv->next;
                        } else {
                            gActiveVoices = sv->next;
                        }
                        if (sv->next != NULL) {
                            sv->next->prev = sv->prev;
                        }
                        sv->next = gKeyedVoices;
                        if (gKeyedVoices != NULL) {
                            gKeyedVoices->prev = sv;
                        }
                        sv->prev = NULL;
                        gKeyedVoices = sv;
                        sv->state = 1;
                    }
                } else {
                    base = (u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888;
                    base[0xEFA] = (u8)(base[0xEFA] & ~8);
                }
                pitch = *(u16 *)((u8 *)arg0 + 0xC);
                pan = *((u8 *)arg0 + 0x18);
                id = SynthFindVoice(*(u32 *)((u8 *)arg0 + 8));
                if ((u32)(id + 0x10000) != 0xFFFF) {
                    if (!(id & 0x80000000)) {
                        off = id * 0x1888;
                        fn_8024A780(pan, (u16)pitch, ((u8 *)gSynthVoicePool + off)[0xED0], 0,
                                    *(u32 *)((u8 *)arg0 + 8));
                        p = (u8 *)gSynthVoicePool + off;
                        ed0 = p + 0xED0;
                        for (i = 0; i < 0x40; i++, p++) {
                            if (p[0x324] != *ed0) {
                                fn_8024A780(pan, (u16)pitch, p[0x324], 0, -1);
                            }
                        }
                    } else {
                        base = (u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888;
                        base[0xEEC] = pan;
                    }
                }
                if (*((u8 *)arg0 + 0x26) & 0x10) {
                    s32 a, b;
                    b = *(s32 *)((u8 *)arg0 + 0x20);
                    a = *(s32 *)((u8 *)arg0 + 0x1C);
                    id = SynthFindVoice(*(u32 *)((u8 *)arg0 + 8));
                    if ((u32)(id + 0x10000) != 0xFFFF) {
                        if (!(id & 0x80000000)) {
                            sv = (SynthVoice *)((u8 *)gSynthVoicePool + id * 0x1888);
                            sv->unk11C = a;
                            sv->unk120 = b;
                        } else {
                            base = (u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888;
                            base[0xEFA] = (u8)(base[0xEFA] | 0x10);
                            *(s32 *)(base + 0xEF0) = a;
                            *(s32 *)(base + 0xEF4) = b;
                        }
                    }
                }
                if (*((u8 *)arg0 + 0x26) & 0x20) {
                    t = *(u16 *)((u8 *)arg0 + 0x24);
                    id = SynthFindVoice(*(u32 *)((u8 *)arg0 + 8));
                    if (!(id & 0x80000000)) {
                        base = (u8 *)gSynthVoicePool + id * 0x1888;
                        for (k = 0; k < 16; k++) {
                            *(u16 *)(base + 0x153A + k * 0x38) = t;
                        }
                    } else {
                        base = (u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888;
                        base[0xEFA] = (u8)(base[0xEFA] | 0x20);
                        *(u16 *)(base + 0xEF8) = t;
                    }
                }
            } else {
                fn_8024B420();
                fn_8024B4B0(*((u8 *)arg0 + 0x18), *(u16 *)((u8 *)arg0 + 0xC),
                             *(s32 *)((u8 *)arg0 + 8), 0);
                if (*((u8 *)arg0 + 0x26) & 0x10) {
                    fn_8024B458(*(s32 *)((u8 *)arg0 + 8),
                                *(s32 *)((u8 *)arg0 + 0x1C),
                                *(s32 *)((u8 *)arg0 + 0x20));
                }
                if (*((u8 *)arg0 + 0x26) & 0x20) {
                    fn_8024B3D8(*(s32 *)((u8 *)arg0 + 8), *(u16 *)((u8 *)arg0 + 0x24));
                }
            }
            *arg1 = *(s32 *)((u8 *)arg0 + 8);
        } else {
            *arg1 = -1;
        }
        return;
    }
    play.flags = 4;
    if (flags & 8) {
        play.flags |= 0x10;
    }
    if (*((u8 *)arg0 + 0x26) & 0x20) {
        play.flags |= 2;
        play.key = *(u16 *)((u8 *)arg0 + 0x24);
    }
    if (*((u8 *)arg0 + 0x26) & 0x10) {
        play.flags |= 1;
        play.fx = *(s32 *)((u8 *)arg0 + 0x1C);
        play.voldown = *(s32 *)((u8 *)arg0 + 0x20);
    }
    play.vol = *(u16 *)((u8 *)arg0 + 0xC);
    play.pan = *((u8 *)arg0 + 0x18);
    play.studio = 0;
    if (arg2 != 0) {
        ret = fn_80259430(*(u16 *)((u8 *)arg0 + 0x14), *(u16 *)((u8 *)arg0 + 0x16),
                          *(s32 *)((u8 *)arg0 + 0x10), &play.flags, 1,
                          *((u8 *)arg0 + 0x19));
        *arg1 = ret;
        if ((u32)(ret + 0x10000) != 0xFFFF && (*((u8 *)arg0 + 0x26) & 0x80)) {
            id = SynthFindVoice(*arg1);
            if ((u32)(id + 0x10000) != 0xFFFF) {
                if (!(id & 0x80000000)) {
                    sv = (SynthVoice *)((u8 *)gSynthVoicePool + id * 0x1888);
                    sv->unk11C = 0;
                    sv->unk120 = 0;
                } else {
                    base = (u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888;
                    base[0xEFA] = (u8)(base[0xEFA] | 0x10);
                    *(s32 *)(base + 0xEF0) = 0;
                    *(s32 *)(base + 0xEF4) = 0;
                }
            }
        }
    } else {
        ret = fn_80259584(*(u16 *)((u8 *)arg0 + 0x14), *(u16 *)((u8 *)arg0 + 0x16),
                          *(s32 *)((u8 *)arg0 + 0x10), &play.flags,
                          *((u8 *)arg0 + 0x19));
        *arg1 = ret;
        if ((u32)(ret + 0x10000) != 0xFFFF && (*((u8 *)arg0 + 0x26) & 0x80)) {
            fn_8024B458(*arg1, 0, 0);
        }
    }
}
#pragma pop
void *fn_80246070(u8 arg0) {
    StreamSeqChan *chanSeq = &lbl_80368968->seqChans[arg0];
    StreamChannel *chan = &lbl_80368968->channels[arg0];
    u8 *voices;
    u8 *voiceState;
    StreamMsg *msg;
    u8 *p;
    u32 temp_r9;
    u32 temp_r10;
    u32 temp_r11;
    u16 ev;

    if (chanSeq->unk4 != NULL) {
        msg = &lbl_80368968->msgs[arg0];
        msg->unk15 = arg0;
        msg->unk10 = chan;
        if (chan->unk8 != NULL) {
            goto stream;
        }
seq:
        ev = chanSeq->unk4->unk8;
        if (ev == 0xFFFF) {
            chanSeq->unk4 = NULL;
            return NULL;
        }
        if (ev == 0xFFFE) {
            voices = lbl_80368968->voices;
            if (voices == NULL) {
                if (lbl_80368968->unk153E != 0) {
                    chanSeq->unk4 = NULL;
                    return NULL;
                }
            } else {
                voiceState = (u8 *) lbl_80368968;
                voiceState += voices[arg0] * 0x38;
                if (*(u8 *) (voiceState + 0x153E) != 0) {
                    chanSeq->unk4 = NULL;
                    return NULL;
                }
            }
            msg->unk14 = 3;
            msg->unk8 = chanSeq->unk4->unk0;
            chanSeq->unk4 = (StreamSeqEvent *) (chanSeq->unk0 + chanSeq->unk4->unkA * 0xC);
            return msg;
        }
        msg->unk14 = 4;
        msg->unk8 = chanSeq->unk4->unk0;
        msg->unkC = chanSeq->unk4;
        chanSeq->unk4 = (StreamSeqEvent *) ((u8 *) chanSeq->unk4 + 0xC);
        return msg;
stream:
        temp_r10 = chan->unk18;
        temp_r11 = chan->unk24;
        for (;;) {
            p = chan->unk8;
            temp_r9 = *(u16 *) p + chan->unk0;
            if (temp_r9 >= temp_r10) {
                goto tail;
            }
            if (temp_r9 >= temp_r11) {
                goto state1;
            }
            if ((p[2] == 0xFF) && (p[3] == 0xFF)) {
                chan->unk8 = NULL;
                goto seq;
            }
            msg->unkC = p;
            chan->unk0 = temp_r9;
            if (chan->unk8[2] & 0x80) {
                chan->unk8 += 4;
            } else if ((chan->unk8[2] | chan->unk8[3]) == 0) {
                chan->unk8 += 4;
                continue;
            } else {
                chan->unk8 += 6;
            }
            msg->unk14 = 0;
            msg->unk8 = temp_r9 + chan->unk4;
            goto done;
        }
tail:
        if (temp_r10 < temp_r11) {
            msg->unk8 = temp_r10 + chan->unk4;
            msg->unk14 = 2;
            goto done;
        }
state1:
        msg->unk8 = temp_r11 + chan->unk4;
        msg->unk14 = 1;
done:
        return msg;
    }
    return NULL;
}

#pragma opt_strength_reduction off
StreamQueueNode *fn_80246288(StreamQueueNode *arg0, u8 arg1, u32 *arg2)
{
    void fn_80245518(void *, s32 *, u8);
    void fn_8024A6F8(u32);
    void fn_8025FA50(s32, u8, u8, s32);
    void fn_8025FB74(u8, u8, u8);
    void Sound_WriteParamU8(s32, s32, u8, s32);
    void *fn_80246070(u8);
    u32 fn_802488C8(u16, u8, u8, s32, u8, s32, s32, u8,
                    s32, u8, s32, s32, s32, s32, s32, s32);

    extern StreamState *lbl_80368968;
    extern u32 lbl_80368960;
    extern u32 lbl_80368964;
    extern u8 lbl_8036895C;
    extern u8 lbl_8034BDD0[];
    extern u8 lbl_8034CB64[];

    struct LocalInst {
        u16 progId;
        u8 vol;
        u8 prio;
        u8 idx;
        u8 pad;
    };
    struct LocalState {
        u8 pad0[0xA];
        u16 unkA;
        u8 padC[4];
        struct LocalInst *instTable;
        u8 instMap[0x80];
        struct LocalInst *drumTable;
        u8 drumMap[0x80];
        u8 *bank;
        u32 trackMask[2];
        u8 pad124[0x200];
        u8 trackPrio[0x40];
        u8 channels[0xB00];
        u8 *activeList[2];
        u8 *freeList;
        struct LocalInst chanInst[16];
        u8 padED0[4];
        u8 unkED4[0x28];
        s32 *unkEFC;
        u8 unkF00;
        u8 unkF01;
    };

    u8 *msg;
    u8 *data;
    u8 *channel;
    u8 *sequence;
    u8 *cursor;
    u8 *bank;
    u8 *seqOff;
    u8 *bankTbl;
    struct LocalState *state;
    u32 i;
    u8 *next;
    u8 *prev;
    u8 *cur;
    u32 offset;
    u16 value;
    u32 command;
    u8 first;
    u8 second;
    u32 index;
    u8 bankIndex;
    u32 instrument;
    s32 temp;
    s32 key;
    s32 vel;
    u8 *node;
    u32 off;
    u8 *walk;

    msg = (u8 *)arg0;

    switch (msg[0x14]) {
    case 4:
        data = *(u8 **)(msg + 0xC);
        cursor = 0;
        index = *(u16 *)(data + 8);
        state = (struct LocalState *)lbl_80368968;
        channel = (u8 *)state + 0x364 + msg[0x15] * 0x2C;
        bank = state->bank;
        seqOff = (u8 *)(u32)*(u32 *)(bank + 4);
        sequence = bank + *(u32 *)(seqOff + (u32)bank + (index << 2));

        *(u32 *)(channel + 8) = (u32)(sequence + 0xC);
        *(u32 *)(channel + 0) = (u32)cursor;
        *(u32 *)(channel + 4) = *(u32 *)data;
        *(u32 *)(channel + 0xC) = (u32)data;

        offset = *(u32 *)(sequence + 4);
        if (offset != 0) {
            walk = ((struct LocalState *)lbl_80368968)->bank + offset;
            first = walk[0];
            second = walk[1];
            if (first == 0x80 && second == 0) {
                /* empty-run marker: cursor stays NULL */
            } else {
                if (first & 0x80) {
                    value = ((first & 0x7F) << 8) | second;
                    walk += 2;
                } else {
                    value = first;
                    walk += 1;
                }
                first = walk[0];
                second = walk[1];
                if (first & 0x80) {
                    temp = (s16)(((first & 0x7F) << 8) | second);
                    walk += 2;
                    temp |= (temp << 1) & 0x8000;
                    *(s16 *)(channel + 0x16) = temp;
                } else {
                    temp = (s8)(u8)(first | ((first << 1) & 0x80));
                    walk += 1;
                    *(s16 *)(channel + 0x16) = temp;
                }
                cursor = walk;
            }
            *(u32 *)(channel + 0x10) = (u32)cursor;
            if (cursor != 0) {
                *(u32 *)(channel + 0x18) = value;
            } else {
                *(u32 *)(channel + 0x18) = 0x7FFFFFFF;
            }
        } else {
            *(u32 *)(channel + 0x18) = 0x7FFFFFFF;
        }
        *(u16 *)(channel + 0x14) = 0x2000;

        offset = *(u32 *)(sequence + 8);
        if (offset != 0) {
            cursor = ((struct LocalState *)lbl_80368968)->bank + offset;
            first = cursor[0];
            second = cursor[1];
            if (first == 0x80 && second == 0) {
                cursor = 0;
            } else {
                if (first & 0x80) {
                    value = ((first & 0x7F) << 8) | second;
                    cursor += 2;
                } else {
                    value = first;
                    cursor++;
                }
                first = cursor[0];
                second = cursor[1];
                if (first & 0x80) {
                    temp = (s16)(((first & 0x7F) << 8) | second);
                    cursor += 2;
                    temp |= (temp << 1) & 0x8000;
                    *(s16 *)(channel + 0x22) = temp;
                } else {
                    temp = (s8)(u8)(first | ((first << 1) & 0x80));
                    cursor++;
                    *(s16 *)(channel + 0x22) = temp;
                }
            }
            *(u32 *)(channel + 0x1C) = (u32)cursor;
            if (cursor != 0) {
                *(u32 *)(channel + 0x24) = value;
            } else {
                *(u32 *)(channel + 0x24) = 0x7FFFFFFF;
            }
        } else {
            *(u32 *)(channel + 0x24) = 0x7FFFFFFF;
        }
        *(u16 *)(channel + 0x20) = 0;

        bank = ((struct LocalState *)lbl_80368968)->bank;
        bankTbl = (u8 *)(u32)*(u32 *)(bank + 8);
        channel[0x28] = *(u8 *)(bankTbl + (u32)bank + msg[0x15]);

        instrument = data[4];
        if (instrument != 0xFF) {
            bankIndex = channel[0x28];
            *(u16 *)(lbl_8034BDD0 + (lbl_80368960 << 5) + bankIndex * 2) = 0xFFFF;
            state = (struct LocalState *)lbl_80368968;
            if (bankIndex != 9) {
                instrument = state->instMap[instrument];
                if (instrument != 0xFF) {
                    state->chanInst[bankIndex].progId = state->instTable[instrument].progId;
                    state->chanInst[bankIndex].vol = state->instTable[instrument].vol;
                    state->chanInst[bankIndex].prio = state->instTable[instrument].prio;
                    state->chanInst[bankIndex].idx = instrument;
                }
            } else {
                instrument = state->drumMap[instrument];
                if (instrument != 0xFF) {
                    state->chanInst[bankIndex].progId = state->drumTable[instrument].progId;
                    state->chanInst[bankIndex].vol = state->drumTable[instrument].vol;
                    state->chanInst[bankIndex].prio = state->drumTable[instrument].prio;
                    state->chanInst[bankIndex].idx = instrument;
                }
            }
        }

        if (data[5] != 0xFF) {
            Sound_WriteParamU8(7, channel[0x28], (u8)lbl_80368960, data[5]);
        }
        break;

    case 0:
        data = *(u8 **)(msg + 0xC);
        channel = *(u8 **)(msg + 0x10);
        value = data[2];
        command = data[3];
        bankIndex = channel[0x28];

        if (value & 0x80) {
            switch (command) {
            case 0:
                *(u16 *)(lbl_8034BDD0 + (lbl_80368960 << 5) + bankIndex * 2) = 0xFFFF;
                instrument = value & 0x7F;
                state = (struct LocalState *)lbl_80368968;
                if (bankIndex != 9) {
                    instrument = state->instMap[instrument];
                    if (instrument != 0xFF) {
                        state->chanInst[bankIndex].progId = state->instTable[instrument].progId;
                        state->chanInst[bankIndex].vol = state->instTable[instrument].vol;
                        state->chanInst[bankIndex].prio = state->instTable[instrument].prio;
                        state->chanInst[bankIndex].idx = instrument;
                    }
                } else {
                    instrument = state->drumMap[instrument];
                    if (instrument != 0xFF) {
                        state->chanInst[bankIndex].progId = state->drumTable[instrument].progId;
                        state->chanInst[bankIndex].vol = state->drumTable[instrument].vol;
                        state->chanInst[bankIndex].prio = state->drumTable[instrument].prio;
                        state->chanInst[bankIndex].idx = instrument;
                    }
                }
                break;

            case 1:
                Sound_WriteParamU8(0x82, bankIndex, (u8)lbl_80368960, value & 0x7F);
                break;

            default:
                if ((s32)(command & 0x80) == 0x80) {
                    u32 cc = command & 0x7F;
                    switch (cc) {
                    case 0x68:
                        if (((struct LocalState *)lbl_80368968)->unkF00 != 0) {
                            fn_80245518(((struct LocalState *)lbl_80368968)->unkED4, ((struct LocalState *)lbl_80368968)->unkEFC, 1);
                            ((struct LocalState *)lbl_80368968)->unkF00 = 0;
                        }
                        break;

                    case 0x69:
                        *(u16 *)(lbl_8034BDD0 + (lbl_80368960 << 5) + bankIndex * 2) = value & 0x7F;
                        break;

                    case 0x6A:
                        *(u16 *)(lbl_8034BDD0 + (lbl_80368960 << 5) + bankIndex * 2) = (value & 0x7F) + 0x80;
                        break;

                    case 0x79:
                        fn_8025FB74(bankIndex, (u8)lbl_80368960, 0);
                        break;

                    case 0x7B:
                        for (i = 0; i < 2; i++) {
                            node = ((struct LocalState *)lbl_80368968)->activeList[i];
                            while (node != 0) {
                                u8 *n;
                                next = *(u8 **)(node + 0);
                                fn_8024A6F8(*(u32 *)(node + 8));
                                n = *(u8 **)(node + 0);
                                ((struct LocalState *)lbl_80368968)->activeList[i] = n;
                                if (n != 0) {
                                    *(u32 *)(((struct LocalState *)lbl_80368968)->activeList[i] + 4) = 0;
                                }
                                n = ((struct LocalState *)lbl_80368968)->freeList;
                                *(u8 **)(node + 0) = n;
                                if (n != 0) {
                                    *(u8 **)(((struct LocalState *)lbl_80368968)->freeList + 4) = node;
                                }
                                ((struct LocalState *)lbl_80368968)->freeList = node;
                                node = next;
                            }
                        }
                        break;

                    default:
                        Sound_WriteParamU8(cc, bankIndex, (u8)lbl_80368960, value & 0x7F);
                        break;
                    }
                }
                break;
            }
        } else {
            state = (struct LocalState *)lbl_80368968;
            if ((state->trackMask[(u32)msg[0x15] >> 5] & (1 << (msg[0x15] & 0x1F))) != 0) {
                u16 progId = state->chanInst[bankIndex].progId;
                if (progId != 0xFFFF) {
                    u8 *chanData = *(u8 **)(channel + 0xC);
                    u32 endTime;
                    key = (s32)value + (s8)chanData[0xA];
                    if (key > 0x7F) {
                        key = 0x7F;
                    } else {
                        key = key < 0 ? 0 : key;
                    }
                    vel = (s32)command + (s8)chanData[0xB];
                    if (vel > 0x7F) {
                        vel = 0x7F;
                    } else {
                        vel = vel < 0 ? 0 : vel;
                    }
                    node = (u8 *)lbl_80368964;
                    endTime = *(u32 *)(msg + 8) + *(u16 *)(data + 4);
                    if (node != 0) {
                        lbl_80368964 = *(u32 *)(node + 0);
                        if (lbl_80368964 != 0) {
                            *(u32 *)((u8 *)lbl_80368964 + 4) = 0;
                        }
                        *(u32 *)(node + 0xC) = endTime;
                        node[0x10] = arg1;
                        off = (u32)arg1 * 0x38;
                        node[0x11] = *((u8 *)lbl_80368968 + off + 0x1538);
                        prev = 0;
                        cur = *(u8 **)((u8 *)lbl_80368968 + (node[0x11] * 4 + 0xE64));
                        while (cur != 0) {
                            if (*(s32 *)(cur + 0xC) > *(s32 *)(node + 0xC)) {
                                *(u8 **)(node + 0) = cur;
                                *(u8 **)(node + 4) = prev;
                                if (prev != 0) {
                                    *(u8 **)(prev + 0) = node;
                                } else {
                                    *(u8 **)((u8 *)lbl_80368968 + (node[0x11] * 4 + 0xE64)) = node;
                                }
                                *(u8 **)(cur + 4) = node;
                                goto inserted;
                            }
                            prev = cur;
                            cur = *(u8 **)(cur + 0);
                        }
                        *(u8 **)(node + 4) = prev;
                        if (prev != 0) {
                            *(u8 **)(prev + 0) = node;
                        } else {
                            *(u8 **)((u8 *)lbl_80368968 + (node[0x11] * 4 + 0xE64)) = node;
                        }
                        *(u32 *)(node + 0) = 0;
                    }
                inserted:
                    if (node != 0) {
                        struct LocalState *st = (struct LocalState *)lbl_80368968;
                        u8 track = msg[0x15];
                        u8 unkF01 = st->unkF01;
                        u32 handle = fn_802488C8(
                            progId,
                            st->chanInst[bankIndex].vol,
                            st->chanInst[bankIndex].prio,
                            st->unkA | ((u32)st->chanInst[bankIndex].idx << 16) | ((u32)(bankIndex == 9) << 24),
                            (u8)key,
                            (u8)vel,
                            0x40,
                            bankIndex,
                            (u8)lbl_80368960,
                            arg1,
                            0,
                            track,
                            st->trackPrio[track],
                            (s16)(lbl_8036895C != 0 ? -1 : 0),
                            unkF01,
                            lbl_8034CB64[unkF01 * 2]);
                        *(u32 *)(node + 8) = handle;
                        if (handle == 0xFFFFFFFF) {
                            if (*(u8 **)(node + 0) != 0) {
                                *(u8 **)(*(u8 **)(node + 0) + 4) = *(u8 **)(node + 4);
                            }
                            if (*(u8 **)(node + 4) != 0) {
                                *(u8 **)(*(u8 **)(node + 4) + 0) = *(u8 **)(node + 0);
                            } else {
                                *(u8 **)((u8 *)lbl_80368968 + (node[0x11] * 4 + 0xE64)) = *(u8 **)(node + 0);
                            }
                            next = (u8 *)lbl_80368964;
                            *(u32 *)(node + 0) = (u32)next;
                            if (next != 0) {
                                *(u8 **)((u8 *)lbl_80368964 + 4) = node;
                            }
                            *(u32 *)(node + 4) = 0;
                            lbl_80368964 = (u32)node;
                        }
                    }
                }
            }
        }
        break;

    case 2:
        channel = *(u8 **)(msg + 0x10);
        *(u16 *)(channel + 0x14) += *(s16 *)(channel + 0x16);
        cursor = *(u8 **)(channel + 0x10);
        if (cursor != 0) {
            first = cursor[0];
            second = cursor[1];
            if (first == 0x80 && second == 0) {
                cursor = 0;
            } else {
                if (first & 0x80) {
                    value = ((first & 0x7F) << 8) | second;
                    cursor += 2;
                } else {
                    value = first;
                    cursor++;
                }
                first = cursor[0];
                second = cursor[1];
                if (first & 0x80) {
                    temp = (s16)(((first & 0x7F) << 8) | second);
                    cursor += 2;
                    temp |= (temp << 1) & 0x8000;
                    *(s16 *)(channel + 0x16) = temp;
                } else {
                    temp = (s8)(u8)(first | ((first << 1) & 0x80));
                    cursor++;
                    *(s16 *)(channel + 0x16) = temp;
                }
            }
            *(u32 *)(channel + 0x10) = (u32)cursor;
            if (cursor != 0) {
                *(u32 *)(channel + 0x18) += value;
            } else {
                *(u32 *)(channel + 0x18) = 0x7FFFFFFF;
            }
        } else {
            *(u32 *)(channel + 0x18) = 0x7FFFFFFF;
        }
        fn_8025FA50(0x80, channel[0x28], (u8)lbl_80368960, *(u16 *)(channel + 0x14));
        break;

    case 1:
        channel = *(u8 **)(msg + 0x10);
        *(u16 *)(channel + 0x20) += *(s16 *)(channel + 0x22);
        cursor = *(u8 **)(channel + 0x1C);
        if (cursor != 0) {
            first = cursor[0];
            second = cursor[1];
            if (first == 0x80 && second == 0) {
                cursor = 0;
            } else {
                if (first & 0x80) {
                    value = ((first & 0x7F) << 8) | second;
                    cursor += 2;
                } else {
                    value = first;
                    cursor++;
                }
                first = cursor[0];
                second = cursor[1];
                if (first & 0x80) {
                    temp = (s16)(((first & 0x7F) << 8) | second);
                    cursor += 2;
                    temp |= (temp << 1) & 0x8000;
                    *(s16 *)(channel + 0x22) = temp;
                } else {
                    temp = (s8)(u8)(first | ((first << 1) & 0x80));
                    cursor++;
                    *(s16 *)(channel + 0x22) = temp;
                }
            }
            *(u32 *)(channel + 0x1C) = (u32)cursor;
            if (cursor != 0) {
                *(u32 *)(channel + 0x24) += value;
            } else {
                *(u32 *)(channel + 0x24) = 0x7FFFFFFF;
            }
        } else {
            *(u32 *)(channel + 0x24) = 0x7FFFFFFF;
        }
        fn_8025FA50(1, channel[0x28], (u8)lbl_80368960, *(u16 *)(channel + 0x20));
        break;

    case 3:
        *arg2 |= 1;
        return 0;
    }

    return (StreamQueueNode *)fn_80246070(msg[0x15]);
}
void fn_80246D48(void) {
    u32 i;
    StreamQueueNode *node;
    struct TempoTable { u8 pad[0x1508]; StreamTempo tempo[16]; };
    if (!lbl_80368968->voices) {
        for (i = 0; i < 64; i++) {
            node = fn_80246070((u8)i);
            if (node) {
                StreamState *state = lbl_80368968;
                StreamQueueNode *prev = 0;
                StreamQueueNode *cur = *(StreamQueueNode **)((u8 *)state + 0x1524);
                while (cur) {
                    if (cur->time > node->time) {
                        node->next = cur; node->prev = prev;
                        if (prev) prev->next = node; else *(StreamQueueNode **)((u8 *)state + 0x1524) = node;
                        cur->prev = node; goto next1;
                    }
                    prev = cur; cur = cur->next;
                }
                node->prev = prev;
                if (prev) prev->next = node; else *(StreamQueueNode **)((u8 *)state + 0x1524) = node;
                node->next = 0;
            }
            next1:;
        }
    } else {
        for (i = 0; i < 64; i++) {
            node = fn_80246070((u8)i);
            if (node) {
                StreamQueueNode *prev = 0;
                StreamState *state = lbl_80368968;
                StreamTempo *t = &((struct TempoTable *)state)->tempo[state->voices[i]];
                StreamQueueNode *cur = t->head;
                while (cur) {
                    if (cur->time > node->time) {
                        node->next = cur; node->prev = prev;
                        if (prev) prev->next = node; else t->head = node;
                        cur->prev = node; goto next2;
                    }
                    prev = cur; cur = cur->next;
                }
                node->prev = prev;
                if (prev) prev->next = node; else t->head = node;
                node->next = 0;
            }
            next2:;
        }
    }
}

#pragma dont_inline reset

#pragma opt_strength_reduction off
s32 fn_80246EBC(u8 arg0,u32 arg1){
StreamQueueNode *fn_80246288(StreamQueueNode*,u8,u32*);void fn_80247F1C(s32,u8,s32);
extern u32 lbl_80368960;extern f32 lbl_8036C1B0,lbl_8036C1B4,lbl_8036C1B8;extern f64 lbl_8036C1C0;
f64 fn_802387A8(f64,f64);f64 fn_802381A4(f64);
u32 changed=0;u32 off=arg0*0x38;StreamTempo *tempo=(StreamTempo*)((u8*)lbl_80368968+off+0x1508);
StreamTempo *t;StreamQueueNode *node;u32 time;s32 i,j;u32 *event;f32 f;
goto check;
for(;;){
if(node){StreamQueueNode *next=node->next;tempo->head=next;if(next)tempo->head->prev=0;}
if(!node){
if(!changed)return 0;
changed=0;tempo->active^=1;
tempo->buffers[tempo->active*2+1]=*(u32*)(*(u8**)((u8*)lbl_80368968+0x118)+0x14+arg0*4);
tempo->buffers[tempo->active*2]=tempo->buffers[(tempo->active^1)*2];
t=(StreamTempo*)((u8*)lbl_80368968+off+0x1508);
if(t->start){
t->cursor=t->start;
t=(StreamTempo*)((u8*)lbl_80368968+off+0x1508);
if(t->start){
while((event=t->cursor)[0]!=0xffffffffU){
if(event[0]>t->buffers[t->active*2+1])break;
if(*(u32*)(*(u8**)((u8*)lbl_80368968+0x118)+0x10)&0x40000000){
t->value=event[1];fn_80247F1C(event[1]>>10,(u8)lbl_80368960,arg0);
}else{fn_80247F1C(event[1],(u8)lbl_80368960,arg0);t->value=t->cursor[1]<<10;}
t->cursor+=2;
}
}
t=(StreamTempo*)((u8*)lbl_80368968+off+0x1508);
f=lbl_8036C1B0*((f32)t->value*(f32)arg1)*(lbl_8036C1B4*(f32)t->scale);
t->timing[t->active*2]=fn_8022C568((f32)fn_802387A8(lbl_8036C1B8*f,lbl_8036C1C0));
t->timing[t->active*2+1]=(s32)(f32)fn_802381A4(f);
}
tempo->count++;
if(!lbl_80368968->voices){
for(i=0;i<64;i++){node=fn_80246070((u8)i);if(node)StreamQueueInsert((StreamQueueNode**)((u8*)lbl_80368968+0x1524),node);}
}else{
for(j=0;j<64;j++){if(arg0==lbl_80368968->voices[j]){
node=fn_80246070((u8)j);if(node){t=(StreamTempo*)((u8*)lbl_80368968+off+0x1508);StreamQueueInsert(&t->head,node);}
}}
}
}else{
node=fn_80246288(node,arg0,&changed);
if(node)StreamQueueInsert(&tempo->head,node);
}
check:
node=tempo->head;time=node?node->time:0;
if(time>tempo->buffers[tempo->active*2+1])return 1;
}
}

#pragma push
#pragma optimization_level 4
#pragma opt_strength_reduction off
void fn_80247358(u32 arg0) {
    extern SynthVoice *gKeyedVoices;
    extern SynthVoice *lbl_8036896C;
    extern VidList *lbl_80368964;
    extern u8 lbl_8036895C;
    extern u32 lbl_80368960;
    extern f32 lbl_8036C1B0, lbl_8036C1B4, lbl_8036C1B8;
    extern f64 lbl_8036C1C0, lbl_8036C1C8;
    s32 fn_80246EBC(u8, u32);
    void fn_80247F1C(s32, u8, s32);
    void fn_8024A6F8(u32);
    s32 fn_8024ACB0(u8);
    s32 fn_8024B7DC(s32);
    void fn_8025FA50(s32, u8, u8, s32);
    f64 fn_802387A8(f64, f64);
    f64 floor(f64);
    u32 result;
    SynthVoice *sv;
    SynthVoice *svNext;
    VidList *node;
    VidList *nnext;
    VidList *tail;
    u32 *event;
    u32 val;
    u32 hasLists;
    u32 i;
    u32 j;
    u32 off;
    u32 sum;
    s32 cmp;
    f32 f31;
    f32 f30;
    f32 f28;
    f32 f27;
    u8 *base;
    u8 *p;
    u32 ch;
    u8 v;

    if (arg0 == 0) {
        return;
    }
    sv = gKeyedVoices;
    goto outer_test;
outer:
    svNext = sv->next;
    lbl_80368968 = (StreamState *)sv;
    lbl_80368960 = sv->id;
    lbl_8036895C = (u8)fn_8024ACB0(*(u8 *)((u8 *)sv + 0xED0));
    base = (u8 *)lbl_80368968;
    if (*(u32 *)(base + 0x1504) == 0) {
        StreamTempo *t = (StreamTempo *)(base + 0x1508);
        if (t->start != NULL) {
            goto ev_check0;
        ev_body0:
            if (event[0] > t->buffers[t->active * 2 + 1]) {
                goto ev_done0;
            }
            if ((*(u32 *)(*(u8 **)((u8 *)lbl_80368968 + 0x118) + 0x10) & 0x40000000) != 0) {
                val = event[1];
                t->value = val;
                fn_80247F1C((s32)(val >> 10), (u8)lbl_80368960, 0);
            } else {
                fn_80247F1C((s32)event[1], (u8)lbl_80368960, 0);
                t->value = t->cursor[1] << 10;
            }
            t->cursor += 2;
        ev_check0:
            event = t->cursor;
            if (event[0] != 0xFFFFFFFFU) {
                goto ev_body0;
            }
        }
    ev_done0:
        t = (StreamTempo *)((u8 *)lbl_80368968 + 0x1508);
        f28 = lbl_8036C1B0 * ((f32)t->value * (f32)arg0);
        f28 = f28 * (lbl_8036C1B4 * (f32)t->scale);
        t->timing[t->active * 2] = __cvt_fp2unsigned((f32)fn_802387A8(lbl_8036C1B8 * f28, lbl_8036C1C0));
        t->timing[t->active * 2 + 1] = (s32)(f32)floor(f28);
        result = (u32)fn_80246EBC(0, arg0);
        for (i = 0; i < 2; i++) {
            node = *(VidList **)((u8 *)lbl_80368968 + (0xE64 + i * 4));
            if (node == NULL) {
                goto list_next0;
            }
            goto list_cmp0;
        list_body0:
            fn_8024A6F8(node->vid);
            nnext = node->next;
            *(VidList **)((u8 *)lbl_80368968 + (0xE64 + i * 4)) = nnext;
            if (nnext != NULL) {
                (*(VidList **)((u8 *)lbl_80368968 + (0xE64 + i * 4)))->prev = NULL;
            }
            node->next = *(VidList **)((u8 *)lbl_80368968 + 0xE6C);
            if (*(VidList **)((u8 *)lbl_80368968 + 0xE6C) != NULL) {
                (*(VidList **)((u8 *)lbl_80368968 + 0xE6C))->prev = node;
            }
            *(VidList **)((u8 *)lbl_80368968 + 0xE6C) = node;
            node = *(VidList **)((u8 *)lbl_80368968 + (0xE64 + i * 4));
            if (node == NULL) {
                goto list_next0;
            }
        list_cmp0:
            cmp = *(s32 *)((u8 *)lbl_80368968 + *(u8 *)((u8 *)node + 0x10) * 0x38 + 0x152C + i * 8);
            if ((s32)node->root <= cmp) {
                goto list_body0;
            }
        list_next0:
            ;
        }
        hasLists = 0;
        if (*(u32 *)((u8 *)lbl_80368968 + 0xE64) != 0 || *(u32 *)((u8 *)lbl_80368968 + 0xE68) != 0) {
            hasLists = 1;
        }
        if (*(u8 *)((u8 *)lbl_80368968 + 0xF02) == 0) {
            node = *(VidList **)((u8 *)lbl_80368968 + 0xE6C);
            goto free_test0;
        free_body0:
            nnext = node->next;
            if ((u32)(node->vid + 0x10000) != 0xFFFF &&
                (u32)(fn_8024B7DC((s32)node->vid) + 0x10000) == 0xFFFF) {
                if (node->next != NULL) {
                    node->next->prev = node->prev;
                }
                if (node->prev != NULL) {
                    node->prev->next = node->next;
                } else {
                    *(VidList **)((u8 *)lbl_80368968 + 0xE6C) = node->next;
                }
                node->next = lbl_80368964;
                if (lbl_80368964 != NULL) {
                    lbl_80368964->prev = node;
                }
                node->prev = NULL;
                lbl_80368964 = node;
            }
            node = nnext;
        free_test0:
            if (node != NULL) {
                goto free_body0;
            }
        }
        v = *(u8 *)((u8 *)lbl_80368968 + 0xF02);
        *(u8 *)((u8 *)lbl_80368968 + 0xF02) = (u8)((v + 1) % 5);
        sum = *(u32 *)((u8 *)lbl_80368968 + 0x1528) + *(u32 *)((u8 *)lbl_80368968 + 0x1514);
        *(u32 *)((u8 *)lbl_80368968 + 0x1528) = sum & 0xFFFF;
        *(u32 *)((u8 *)lbl_80368968 + 0x152C) =
            (sum >> 16) + (*(u32 *)((u8 *)lbl_80368968 + 0x1518) + *(u32 *)((u8 *)lbl_80368968 + 0x152C));
        sum = *(u32 *)((u8 *)lbl_80368968 + 0x1530) + *(u32 *)((u8 *)lbl_80368968 + 0x151C);
        *(u32 *)((u8 *)lbl_80368968 + 0x1530) = sum & 0xFFFF;
        *(u32 *)((u8 *)lbl_80368968 + 0x1534) =
            (sum >> 16) + (*(u32 *)((u8 *)lbl_80368968 + 0x1520) + *(u32 *)((u8 *)lbl_80368968 + 0x1534));
    } else {
        StreamTempo *t;
        f28 = lbl_8036C1B0;
        f30 = lbl_8036C1B4;
        f31 = lbl_8036C1B8;
        result = 0;
        for (ch = 0; ch < 0x10; ch++) {
            t = (StreamTempo *)((u8 *)lbl_80368968 + ch * 0x38 + 0x1508);
            if (t->start != NULL) {
                goto ev_check1;
            ev_body1:
                if (event[0] > t->buffers[t->active * 2 + 1]) {
                    goto ev_done1;
                }
                if ((*(u32 *)(*(u8 **)((u8 *)lbl_80368968 + 0x118) + 0x10) & 0x40000000) != 0) {
                    val = event[1];
                    t->value = val;
                    fn_80247F1C((s32)(val >> 10), (u8)lbl_80368960, (u8)ch);
                } else {
                    fn_80247F1C((s32)event[1], (u8)lbl_80368960, (u8)ch);
                    t->value = t->cursor[1] << 10;
                }
                t->cursor += 2;
            ev_check1:
                event = t->cursor;
                if (event[0] != 0xFFFFFFFFU) {
                    goto ev_body1;
                }
            }
        ev_done1:
            t = (StreamTempo *)((u8 *)lbl_80368968 + ch * 0x38 + 0x1508);
            f27 = f28 * ((f32)t->value * (f32)arg0);
            f27 = f27 * (f30 * (f32)t->scale);
            t->timing[t->active * 2] = __cvt_fp2unsigned((f32)fn_802387A8(f31 * f27, lbl_8036C1C0));
            t->timing[t->active * 2 + 1] = (s32)(f32)floor(f27);
            result |= (u32)fn_80246EBC((u8)ch, arg0);
        }
        for (i = 0; i < 2; i++) {
            node = *(VidList **)((u8 *)lbl_80368968 + (0xE64 + i * 4));
            if (node == NULL) {
                goto list_next1;
            }
            goto list_cmp1;
        list_body1:
            fn_8024A6F8(node->vid);
            nnext = node->next;
            *(VidList **)((u8 *)lbl_80368968 + (0xE64 + i * 4)) = nnext;
            if (nnext != NULL) {
                (*(VidList **)((u8 *)lbl_80368968 + (0xE64 + i * 4)))->prev = NULL;
            }
            node->next = *(VidList **)((u8 *)lbl_80368968 + 0xE6C);
            if (*(VidList **)((u8 *)lbl_80368968 + 0xE6C) != NULL) {
                (*(VidList **)((u8 *)lbl_80368968 + 0xE6C))->prev = node;
            }
            *(VidList **)((u8 *)lbl_80368968 + 0xE6C) = node;
            node = *(VidList **)((u8 *)lbl_80368968 + (0xE64 + i * 4));
            if (node == NULL) {
                goto list_next1;
            }
        list_cmp1:
            cmp = *(s32 *)((u8 *)lbl_80368968 + *(u8 *)((u8 *)node + 0x10) * 0x38 + 0x152C + i * 8);
            if ((s32)node->root <= cmp) {
                goto list_body1;
            }
        list_next1:
            ;
        }
        hasLists = 0;
        if (*(u32 *)((u8 *)lbl_80368968 + 0xE64) != 0 || *(u32 *)((u8 *)lbl_80368968 + 0xE68) != 0) {
            hasLists = 1;
        }
        if (*(u8 *)((u8 *)lbl_80368968 + 0xF02) == 0) {
            node = *(VidList **)((u8 *)lbl_80368968 + 0xE6C);
            goto free_test1;
        free_body1:
            nnext = node->next;
            if ((u32)(node->vid + 0x10000) != 0xFFFF &&
                (u32)(fn_8024B7DC((s32)node->vid) + 0x10000) == 0xFFFF) {
                if (node->next != NULL) {
                    node->next->prev = node->prev;
                }
                if (node->prev != NULL) {
                    node->prev->next = node->next;
                } else {
                    *(VidList **)((u8 *)lbl_80368968 + 0xE6C) = node->next;
                }
                node->next = lbl_80368964;
                if (lbl_80368964 != NULL) {
                    lbl_80368964->prev = node;
                }
                node->prev = NULL;
                lbl_80368964 = node;
            }
            node = nnext;
        free_test1:
            if (node != NULL) {
                goto free_body1;
            }
        }
        v = *(u8 *)((u8 *)lbl_80368968 + 0xF02);
        *(u8 *)((u8 *)lbl_80368968 + 0xF02) = (u8)((v + 1) % 5);
        for (j = 0, off = 0; j < 8; j++, off += 0x70) {
            p = (u8 *)lbl_80368968 + off;
            sum = *(u32 *)(p + 0x1528) + *(u32 *)(p + 0x1514);
            *(u32 *)(p + 0x1528) = sum & 0xFFFF;
            *(u32 *)(p + 0x152C) = (sum >> 16) + (*(u32 *)(p + 0x1518) + *(u32 *)(p + 0x152C));
            sum = *(u32 *)(p + 0x1530) + *(u32 *)(p + 0x151C);
            *(u32 *)(p + 0x1530) = sum & 0xFFFF;
            *(u32 *)(p + 0x1534) = (sum >> 16) + (*(u32 *)(p + 0x1520) + *(u32 *)(p + 0x1534));
            p = (u8 *)lbl_80368968 + off + 0x38;
            sum = *(u32 *)(p + 0x1528) + *(u32 *)(p + 0x1514);
            *(u32 *)(p + 0x1528) = sum & 0xFFFF;
            *(u32 *)(p + 0x152C) = (sum >> 16) + (*(u32 *)(p + 0x1518) + *(u32 *)(p + 0x152C));
            sum = *(u32 *)(p + 0x1530) + *(u32 *)(p + 0x151C);
            *(u32 *)(p + 0x1530) = sum & 0xFFFF;
            *(u32 *)(p + 0x1534) = (sum >> 16) + (*(u32 *)(p + 0x1520) + *(u32 *)(p + 0x1534));
        }
    }
    if (result == 0 && hasLists == 0) {
        for (ch = 0; ch < 0x10; ch++) {
            fn_8025FA50(0x40, (u8)ch, (u8)lbl_80368960, 0);
        }
        if (sv->prev != NULL) {
            sv->prev->next = svNext;
        } else {
            gKeyedVoices = svNext;
        }
        if (svNext != NULL) {
            svNext->prev = sv->prev;
        }
        for (i = 0; i < 2; i++) {
            tail = *(VidList **)((u8 *)sv + 0xE64 + i * 4);
            if (tail != NULL) {
                while (tail->next != NULL) {
                    tail = tail->next;
                }
                if (lbl_80368964 != NULL) {
                    tail->next = lbl_80368964;
                    lbl_80368964->prev = tail;
                }
                lbl_80368964 = *(VidList **)((u8 *)sv + 0xE64 + i * 4);
                *(VidList **)((u8 *)sv + 0xE64 + i * 4) = NULL;
            }
        }
        tail = sv->listE6C;
        if (tail != NULL) {
            while (tail->next != NULL) {
                tail = tail->next;
            }
            if (lbl_80368964 != NULL) {
                tail->next = lbl_80368964;
                lbl_80368964->prev = tail;
            }
            lbl_80368964 = sv->listE6C;
            sv->listE6C = NULL;
        }
        sv->state = 0;
        sv->prev = NULL;
        sv->next = lbl_8036896C;
        if (lbl_8036896C != NULL) {
            lbl_8036896C->prev = sv;
        }
        lbl_8036896C = sv;
    }
    sv = svNext;
outer_test:
    if (sv != NULL) {
        goto outer;
    }
}
#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
#pragma opt_strength_reduction reset
#pragma pop
