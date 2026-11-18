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

s32 fn_8023C7F4(void) {
  extern u8 *lbl_80368950;
  s32 off;
  u8 i;
  u32 value;

  *(u8 **)(lbl_80368950 + 0x69C) += 2;
  if (*(*(u8 **)(lbl_80368950 + 0x69C))++ != 8)
    return 10;

  *(u16 *)(lbl_80368950 + 0x694) =
      ((*(u8 **)(lbl_80368950 + 0x69C))[0] << 8) |
      (*(u8 **)(lbl_80368950 + 0x69C))[1];
  *(u8 **)(lbl_80368950 + 0x69C) += 2;

  *(u16 *)(lbl_80368950 + 0x692) =
      ((*(u8 **)(lbl_80368950 + 0x69C))[0] << 8) |
      (*(u8 **)(lbl_80368950 + 0x69C))[1];
  *(u8 **)(lbl_80368950 + 0x69C) += 2;

  if (*(*(u8 **)(lbl_80368950 + 0x69C))++ != 3)
    return 12;

  for (i = 0, off = 0; i < 3; off += 6, i++) {
    *(u8 **)(lbl_80368950 + 0x69C) += 1;
    value = *(*(u8 **)(lbl_80368950 + 0x69C))++;
    if (i == 0) {
      if (value != 0x22)
        goto fail;
    }
    if (i == 0)
      goto success;
    if (value == 0x11)
      goto success;
  fail:
    return 0x13;
  success:
    lbl_80368950[off + 0x680] = *(*(u8 **)(lbl_80368950 + 0x69C))++;
  }
  return 0;
}

s32 fn_8023C930(void) {
extern u8 *lbl_80368950;
s32 off;
u8 i;
u32 value;
s32 hi;

*(u8 **)(lbl_80368950+0x69C)+=2;
if(*(*(u8 **)(lbl_80368950+0x69C))++!=3) return 12;
for(i=0,off=0;i<3;off+=6,i++) {
*(u8 **)(lbl_80368950+0x69C)+=1;
value=*(*(u8 **)(lbl_80368950+0x69C))++;
hi=(s32)value>>4;
lbl_80368950[off+0x681]=hi;
value &= 15;
lbl_80368950[off+0x682]=value;
if(!(lbl_80368950[0x6A8] & (1<<hi))) return 15;
if(!(lbl_80368950[0x6A8] & (1<<(value+1)))) return 15;
}
*(u8 **)(lbl_80368950+0x69C)+=3;
*(u16 *)(lbl_80368950+0x696)=(*(u16 *)(lbl_80368950+0x692)+15)/16;
*(u16 *)(lbl_80368950+0x684)=0;
*(u16 *)(lbl_80368950+0x68A)=0;
*(u16 *)(lbl_80368950+0x690)=0;
return 0;
}

#pragma opt_strength_reduction off
#pragma use_lmw_stmw on
s32 fn_8023CA4C(void) {
extern u8 lbl_80282FD8[];
extern ThpDecodeState *lbl_80368950;
u32 size; u32 id; u16 row; u16 i; f64 *scale; u8 *p; ThpDecodeState *state;
f32 table[64];
size=ThpReadWord()-2;
do {
id=ThpReadByte();
for(i=0;i<64;i++) table[lbl_80282FD8[i]]=(f32)(u32)ThpReadByte();
state=lbl_80368950;
scale=(f64 *)(lbl_80282FD8+0x50);
for(row=0,i=0;row<8;row++,scale++) {
state->tables[id][(u16)(i+0)]=((f64 *)(lbl_80282FD8+0x50))[0]*((f64)table[(u16)(i+0)]* *scale);
state->tables[id][(u16)(i+1)]=((f64 *)(lbl_80282FD8+0x50))[1]*((f64)table[(u16)(i+1)]* *scale);
state->tables[id][(u16)(i+2)]=((f64 *)(lbl_80282FD8+0x50))[2]*((f64)table[(u16)(i+2)]* *scale);
state->tables[id][(u16)(i+3)]=((f64 *)(lbl_80282FD8+0x50))[3]*((f64)table[(u16)(i+3)]* *scale);
state->tables[id][(u16)(i+4)]=((f64 *)(lbl_80282FD8+0x50))[4]*((f64)table[(u16)(i+4)]* *scale);
state->tables[id][(u16)(i+5)]=((f64 *)(lbl_80282FD8+0x50))[5]*((f64)table[(u16)(i+5)]* *scale);
state->tables[id][(u16)(i+6)]=((f64 *)(lbl_80282FD8+0x50))[6]*((f64)table[(u16)(i+6)]* *scale);
state->tables[id][(u16)(i+7)]=((f64 *)(lbl_80282FD8+0x50))[7]*((f64)table[(u16)(i+7)]* *scale);
i+=8;
}
size-=65;
} while((u16)size);
return 0;
}

u8 fn_8023CE08(void)
{
    extern s32 lbl_8036894C;
    extern u8 *lbl_80368950;
    extern u8 *lbl_803688E4;
    extern u8 *lbl_803688E8;
    extern u16 *lbl_803688EC;

    void fn_8023CFE8(void);
    void fn_8023D0D8(void);
    void fn_8023D140(u32);

    u8 *state;
    u8 *cursor;
    u8 value;
    u32 index;
    u32 i;
    u32 count;
    u32 total;
    u32 length;

    state = lbl_80368950;

    lbl_803688E8 = (u8 *)lbl_8036894C;
    lbl_803688EC = (u16 *)(lbl_8036894C + 0x101);

    cursor = *(u8 **)(state + 0x69C);

    length = ((u32)cursor[0] << 8) | cursor[1];
    *(u8 **)(state + 0x69C) = cursor + 2;

    length -= 2;

    do {
        state = lbl_80368950;
        cursor = *(u8 **)(state + 0x69C);

        value = *cursor;
        *(u8 **)(state + 0x69C) = cursor + 1;

        index = (value >> 4) + ((value & 0xF) << 1);

        lbl_803688E4 = *(u8 **)(state + 0x69C);

        total = 0;

        for (i = 0; i < 16; i += 8) {
            state = lbl_80368950;
            cursor = *(u8 **)(state + 0x69C);
            *(u8 **)(state + 0x69C) = cursor + 1;
            total += cursor[0];

            state = lbl_80368950;
            cursor = *(u8 **)(state + 0x69C);
            *(u8 **)(state + 0x69C) = cursor + 1;
            total += cursor[0];

            state = lbl_80368950;
            cursor = *(u8 **)(state + 0x69C);
            *(u8 **)(state + 0x69C) = cursor + 1;
            total += cursor[0];

            state = lbl_80368950;
            cursor = *(u8 **)(state + 0x69C);
            *(u8 **)(state + 0x69C) = cursor + 1;
            total += cursor[0];

            state = lbl_80368950;
            cursor = *(u8 **)(state + 0x69C);
            *(u8 **)(state + 0x69C) = cursor + 1;
            total += cursor[0];

            state = lbl_80368950;
            cursor = *(u8 **)(state + 0x69C);
            *(u8 **)(state + 0x69C) = cursor + 1;
            total += cursor[0];

            state = lbl_80368950;
            cursor = *(u8 **)(state + 0x69C);
            *(u8 **)(state + 0x69C) = cursor + 1;
            total += cursor[0];

            state = lbl_80368950;
            cursor = *(u8 **)(state + 0x69C);
            *(u8 **)(state + 0x69C) = cursor + 1;
            total += cursor[0];
        }

        state = lbl_80368950;

        *(u8 **)(state + 0x340 + index * 0xE0) =
            *(u8 **)(state + 0x69C);

        *(u8 **)(state + 0x69C) += (u16)total;

        fn_8023CFE8();
        fn_8023D0D8();
        fn_8023D140(index);

        state = lbl_80368950;

        length -= total + 0x11;

        state[0x6A8] |= 1 << index;

    } while ((u16)length != 0);

    return 0;
}

#pragma use_lmw_stmw off
#pragma opt_strength_reduction on
void fn_8023CFE8(void) {
    extern u8 *lbl_803688E4;
    extern u8 *volatile lbl_803688E8;
    s32 out;
    s32 val;
    s32 n;
    u8 v;
    s32 i;

    out = 0;
    val = 1;
    goto outer_test;
outer:
    n = lbl_803688E4[val - 1];
    v = val;
    if (n == 0) {
        goto next;
    }
    n = n;
    i = (u32)n >> 3;
    if (i == 0) {
        goto rem;
    }
    do {
        lbl_803688E8[out++] = v;
        lbl_803688E8[out++] = v;
        lbl_803688E8[out++] = v;
        lbl_803688E8[out++] = v;
        lbl_803688E8[out++] = v;
        lbl_803688E8[out++] = v;
        lbl_803688E8[out++] = v;
        lbl_803688E8[out++] = v;
    } while (--i);
rem:
    n &= 7;
    if (n == 0) {
        goto next;
    }
    do {
        lbl_803688E8[out++] = v;
    } while (--n);
next:
    val++;
outer_test:
    if (val <= 16) {
        goto outer;
    }
    lbl_803688E8[out] = 0;
}

#pragma global_optimizer off
#pragma scheduling off
void fn_8023D0D8(void) {
extern u8 *lbl_803688E8; extern u16 *lbl_803688EC;
s32 one; u32 cur_ext; u16 *dst; u8 *src; u8 current; u16 index; u16 count;
src=lbl_803688E8; index=0; dst=lbl_803688EC; count=0; current=src[0]; one=1;
while(src[index]!=0) {
cur_ext=current;
while(cur_ext==src[index]) { dst[index]=count; index++; count++; }
count=(u16)(count<<one); current++;
}
}
#pragma scheduling reset
#pragma global_optimizer reset
void fn_8023D140(u8 arg0) {
extern u8 *lbl_80368950;
extern u8 *lbl_803688E4;
extern u16 *lbl_803688EC;
u8 *base = lbl_80368950 + (arg0 * 0xE0 + 0x300);
s32 n = 0;
s32 i;
u8 *p = base + 4;
i = 1;
{ s32 count = 4;
do {
if (lbl_803688E4[i-1]) {
*(s32 *)(p + 0x8C) = n - lbl_803688EC[n];
n += lbl_803688E4[i-1];
*(s32 *)(p + 0x44) = lbl_803688EC[n-1];
} else {
*(s32 *)(p + 0x44) = -1;
*(s32 *)(p + 0x8C) = -1;
}
i++; p+=4;
if (lbl_803688E4[i-1]) {
*(s32 *)(p + 0x8C) = n - lbl_803688EC[n];
n += lbl_803688E4[i-1];
*(s32 *)(p + 0x44) = lbl_803688EC[n-1];
} else {
*(s32 *)(p + 0x44) = -1;
*(s32 *)(p + 0x8C) = -1;
}
i++; p+=4;
if (lbl_803688E4[i-1]) {
*(s32 *)(p + 0x8C) = n - lbl_803688EC[n];
n += lbl_803688E4[i-1];
*(s32 *)(p + 0x44) = lbl_803688EC[n-1];
} else {
*(s32 *)(p + 0x44) = -1;
*(s32 *)(p + 0x8C) = -1;
}
i++; p+=4;
if (lbl_803688E4[i-1]) {
*(s32 *)(p + 0x8C) = n - lbl_803688EC[n];
n += lbl_803688E4[i-1];
*(s32 *)(p + 0x44) = lbl_803688EC[n-1];
} else {
*(s32 *)(p + 0x44) = -1;
*(s32 *)(p + 0x8C) = -1;
}
i++; p+=4;
} while (--count);
}
*(s32 *)(base + 0x88) = 0xFFFFF;
}

void fn_8023D2FC(void)
{
    extern u8 *lbl_80368950;

    *(u8 *)(lbl_80368950 + 0x6a9) = 1;
    *(u32 *)(lbl_80368950 + 0x69c) += 2;
    *(u16 *)(lbl_80368950 + 0x6aa) = ((*(u8 **)(lbl_80368950 + 0x69c))[0] << 8) | (*(u8 **)(lbl_80368950 + 0x69c))[1];
    {
        u8 *p = *(u8 **)(lbl_80368950 + 0x69c);
        *(u8 **)(lbl_80368950 + 0x69c) = p + 2;
    }
    *(u16 *)(lbl_80368950 + 0x6ac) = *(u16 *)(lbl_80368950 + 0x6aa);
}

#pragma use_lmw_stmw on
void fn_8023D350(void)
{
    extern u8 *lbl_80368950;
    extern u8 *lbl_80368840;
    extern u8 *lbl_80368860;
    extern u8 *lbl_80368880;
    extern u8 *lbl_803688A0;
    extern u8 *lbl_803688C0;
    extern u8 *lbl_803688E0;

    u32 j;
    u8 *base;
    u8 *ptr;
    u32 *pBit;
    u32 bitpos;
    u32 low;
    u8 *aligned;
    u32 i;
    u32 off;
    u32 ctr;
    u32 idx;
    u32 slot;
    u8 *p;
    u8 *q;
    u8 *table;
    s32 code;
    u32 w340;
    u32 w390;
    u8 b682, b688, b68e, b687, b68d, b681;
    u32 t681, t687, t68d, t682, t688, t68e;

    base = lbl_80368950;
    ptr = *(u8 **)(base + 0x69c);
    pBit = (u32 *)(base + 0x6a4);
    bitpos = *pBit;
    aligned = (u8 *)((u32)ptr & ~3);
    low = (u32)ptr & 3;
    if (bitpos != 0x21) {
        *pBit = bitpos - ((3 - low) * 8);
    } else {
        *pBit = (low * 8) + 1;
    }

    i = 0;
    off = 0;
    *(u8 **)(lbl_80368950 + 0x69c) = aligned;
    *(u32 *)(lbl_80368950 + 0x6a0) = *(u32 *)aligned;

    do {
        if (lbl_80368950[0x6a8] & (1 << i)) {
            for (ctr = 0x10, slot = off, idx = 0; ctr != 0; ctr--) {
                lbl_80368950[off + idx + 0x300] = 0xFF;
                for (j = 0; j < 5; j++) {
                    p = (u8 *)(off + (u32)lbl_80368950);
                    q = p + (j * 4);
                    code = (s32)(idx >> (4 - j));
                    if (code <= *(s32 *)(q + 0x348)) {
                        w340 = *(u32 *)(p + 0x340);
                        w390 = *(u32 *)(q + 0x390);
                        table = (u8 *)w390 + w340;
                        lbl_80368950[slot + 0x300] = table[code];
                        lbl_80368950[slot + 0x320] = j + 1;
                        j = 0x63;
                    }
                }
                idx += 1;
                lbl_80368950[off + idx + 0x300] = 0xFF;
                j = 0;
                slot += 1;
                for (; j < 5; j++) {
                    p = (u8 *)(off + (u32)lbl_80368950);
                    q = p + (j * 4);
                    code = (s32)(idx >> (4 - j));
                    if (code <= *(s32 *)(q + 0x348)) {
                        w340 = *(u32 *)(p + 0x340);
                        w390 = *(u32 *)(q + 0x390);
                        table = (u8 *)w390 + w340;
                        lbl_80368950[slot + 0x300] = table[code];
                        lbl_80368950[slot + 0x320] = j + 1;
                        j = 0x63;
                    }
                }
                slot += 1;
                idx += 1;
            }
        }
        i += 1;
        off += 0xe0;
    } while (i < 4);

    base = lbl_80368950;
    b682 = base[0x682];
    b688 = base[0x688];
    b68e = base[0x68e];
    b687 = base[0x687];
    b68d = base[0x68d];
    b681 = base[0x681];

    t682 = (b682 << 1) + 1;
    t688 = (b688 << 1) + 1;
    t68e = (b68e << 1) + 1;
    t687 = b687 << 1;
    t68d = b68d << 1;
    t681 = b681 << 1;

    t681 *= 0xe0;
    t687 *= 0xe0;
    t68d *= 0xe0;
    t682 *= 0xe0;
    t688 *= 0xe0;
    t68e *= 0xe0;

    t681 += 0x300;
    t687 += 0x300;
    t68d += 0x300;
    t682 += 0x300;
    t688 += 0x300;
    t68e += 0x300;

    lbl_80368840 = base + t681;
    lbl_80368860 = base + t687;
    lbl_80368880 = base + t68d;
    lbl_803688A0 = base + t682;
    lbl_803688C0 = base + t688;
    lbl_803688E0 = base + t68e;
}
#pragma use_lmw_stmw reset

void fn_8023D59C(s32 arg0,s32 arg1,s32 arg2) {
extern void *lbl_80368950; extern s32 lbl_80368944,lbl_80368948;
void fn_8023D350(); void fn_8023D6A8(); void fn_8023F130(); void fn_80240BBC();
u16 row; u16 height;
*(s32 *)((u8 *)lbl_80368950+0x6B0)=arg0;
*(s32 *)((u8 *)lbl_80368950+0x6B4)=arg1;
*(s32 *)((u8 *)lbl_80368950+0x6B8)=arg2;
row=*(u16 *)((u8 *)lbl_80368950+0x698);
height=*(u16 *)((u8 *)lbl_80368950+0x694);
lbl_80368944=__builtin_mfspr(917); lbl_80368948=__builtin_mfspr(918);
__builtin_mtspr(917,0x70007); __builtin_mtspr(918,0x3D043D04);
fn_8023D350();
if(*(u16 *)((u8 *)lbl_80368950+0x692)==0x200 && height==0x1C0) {
for(;row<height;row+=16) fn_8023D6A8();
} else if(*(u16 *)((u8 *)lbl_80368950+0x692)==0x280 && height==0x1E0) {
for(;row<height;row+=16) fn_8023F130();
} else {for(;row<height;row+=16) fn_80240BBC();}
__builtin_mtspr(917,lbl_80368944); __builtin_mtspr(918,lbl_80368948);
}

void fn_8023D6A8(void) {
    extern u8 lbl_8033E460[];
    extern f32 lbl_8036C198;
    extern f32 lbl_8036C19C;
    extern f32 lbl_8036C1A0;
    extern f32 lbl_8036C1A4;
    extern f32 lbl_8036C1A8;
    extern void *lbl_80368950;
    extern void *lbl_80368900;
    extern u32 lbl_80368920;
    extern void *lbl_80368940;
    void fn_8020543C(s32);
    void fn_80242668(void *, void *);
    void fn_80242CE4(void *, void *);
    void fn_8024338C(void *, void *);
    u8 *buf;
    u8 i;
    f32 c0, c1, c2, c3, c4;
    void *src;

    buf = lbl_8033E460;
    fn_8020543C(3);
    c0 = lbl_8036C198;
    c1 = lbl_8036C19C;
    c2 = lbl_8036C1A0;
    c3 = lbl_8036C1A4;
    c4 = lbl_8036C1A8;
    i = 0;
    do {
        fn_80242668(lbl_80368950, *(void **)(buf + 0x118));
        fn_80242668(lbl_80368950, *(void **)(buf + 0x11C));
        fn_80242668(lbl_80368950, *(void **)(buf + 0x120));
        fn_80242668(lbl_80368950, *(void **)(buf + 0x124));
        fn_80242CE4(lbl_80368950, *(void **)(buf + 0x128));
        fn_8024338C(lbl_80368950, *(void **)(buf + 0x12C));
        lbl_80368900 = *(void **)(buf + 0x100);
        lbl_80368920 = 0x200;
        lbl_80368940 = (u8 *)lbl_80368950 + (*(u8 *)((u8 *)lbl_80368950 + 0x680) << 8);
        /* PS decode body omitted — needs paired-single/GQR */
        (void)c0; (void)c1; (void)c2; (void)c3; (void)c4;
        (void)src;
        i++;
    } while (i < 2);
}

void fn_8023F130(void) {
    extern u8 lbl_8033E460[];
    void fn_8020543C(s32);
    fn_8020543C(3);
    (void)lbl_8033E460;
}

void fn_80240BBC(void) {
    void fn_8020543C(s32);
    fn_8020543C(3);
}

void fn_80242668(void *arg0, s16 *arg1) {
    extern u8 *lbl_80368840;
    extern u8 *lbl_803688A0;
    extern u8 lbl_80282FD8[];
    u8 *ctx=arg0;
    u8 *tbl;
    u8 *lens;
    s32 bitpos;
    u32 bitbuf;
    s32 code;
    s32 val;
    s32 i;
    s32 run, bits, remaining, extra, shift;
    u32 x, oldbits;
    u32 *wp;
    __dcbz(arg1,0);
    tbl=lbl_80368840;
    bitpos=*(s32 *)(ctx+0x6a4);
    lens=tbl+0x20;
    bitbuf=*(u32 *)(ctx+0x6a0);
    {
        s32 *maxcode;
        s32 limit, length, step;
        u32 prefix;
        u32 *stream;
        code = __rlwnm(bitbuf, bitpos + 4, 27, 31);
        if (bitpos <= 28) {
            val=tbl[code];
            step=lens[code];
            if(val!=255) {
                bitpos+=step;
                *(s32 *)(ctx+0x6a4)=bitpos;
            } else {
                maxcode=(s32 *)(tbl+0x44);
                bitpos+=5;
                length=5;
                maxcode+=5;
                for(;;) {
                    code <<= 1;
                    if(bitpos!=33) {
                        step=__rlwnm(bitbuf,bitpos,31,31);
                        limit=*++maxcode;
                        code|=step;
                        bitpos++;
                    } else {
                        stream=*(u32 **)(ctx+0x69c);
                        bitpos=1;
                        bitbuf=*++stream;
                        limit=*++maxcode;
                        *(u32 **)(ctx+0x69c)=stream;
                        code|=bitbuf>>31;
                        *(u32 *)(ctx+0x6a0)=bitbuf;
                        for(;;) {
                            bitpos++;
                            length++;
                            if(code<=limit) break;
                            code <<= 1;
                            step=__rlwnm(bitbuf,bitpos,31,31);
                            limit=*++maxcode;
                            code|=step;
                        }
                        break;
                    }
                    length++;
                    if(code<=limit) break;
                }
                *(s32 *)(ctx+0x6a4)=bitpos;
                val=(*(u8 **)(tbl+0x40))[code+*(s32 *)(tbl+0x8c+length*4)];
            }
        } else {
            stream=*(u32 **)(ctx+0x69c);
            if(bitpos==33) {
                bitbuf=*++stream;
                code=bitbuf>>27;
                *(u32 **)(ctx+0x69c)=stream;
                val=tbl[code];
                step=lens[code];
                *(u32 *)(ctx+0x6a0)=bitbuf;
                if(val!=255) {
                    bitpos=step+1;
                    *(s32 *)(ctx+0x6a4)=bitpos;
                } else {
                    length=5;
                    do {
                        step=31-length;
                        length++;
                        code=bitbuf>>step;
                        limit=*(s32 *)(tbl+0x44+length*4);
                    } while(code>limit);
                    bitpos=length+1;
                    *(s32 *)(ctx+0x6a4)=bitpos;
                    val=(*(u8 **)(tbl+0x40))[code+*(s32 *)(tbl+0x8c+length*4)];
                }
            } else if(bitpos==32) {
                bitbuf=*++stream;
                *(u32 **)(ctx+0x69c)=stream;
                code=(code&16)|(bitbuf>>28);
                val=tbl[code];
                step=lens[code];
                *(u32 *)(ctx+0x6a0)=bitbuf;
                bitpos=step;
                *(s32 *)(ctx+0x6a4)=bitpos;
                if(val==255) {
                    maxcode=(s32 *)(tbl+0x44)+5;
                    prefix=((u32)code<<27)|(bitbuf>>1);
                    length=5;
                    do {
                        step=31-length;
                        limit=*++maxcode;
                        code=prefix>>step;
                        length++;
                    } while(code>limit);
                    bitpos=length;
                    *(s32 *)(ctx+0x6a4)=bitpos;
                    val=(*(u8 **)(tbl+0x40))[code+*(s32 *)(tbl+0x8c+length*4)];
                }
            } else {
                val=tbl[code];
                step=lens[code];
                length=bitpos+step;
                if(val!=255 && length<=33) {
                    bitpos=length;
                    *(s32 *)(ctx+0x6a4)=bitpos;
                } else {
                    step=33-bitpos;
                    code=bitbuf&~(~0U<<step);
                    maxcode=(s32 *)(tbl+0x44)+step;
                    length=step+1;
                    stream=*(u32 **)(ctx+0x69c);
                    bitbuf=*++stream;
                    *(u32 **)(ctx+0x69c)=stream;
                    code<<=1;
                    *(u32 *)(ctx+0x6a0)=bitbuf;
                    code|=bitbuf>>31;
                    limit=*++maxcode;
                    bitpos=2;
                    for(;;) {
                        step=__rlwnm(bitbuf,bitpos,31,31);
                        if(code<=limit) break;
                        code<<=1;
                        length++;
                        limit=*++maxcode;
                        code+=step;
                        bitpos++;
                    }
                    *(s32 *)(ctx+0x6a4)=bitpos;
                    val=(*(u8 **)(tbl+0x40))[code+*(s32 *)(tbl+0x8c+length*4)];
                }
            }
        }
    }
    __dcbz(arg1,0x20);
    x=0;
    __dcbz(arg1,0x40);
    if(val!=0) {
        bitpos=*(s32 *)(ctx+0x6a4);
        remaining=33-bitpos;
        bitbuf=*(u32 *)(ctx+0x6a0);
        extra=val-remaining;
        shift=bitpos-1;
        if(extra<=0) {
            *(s32 *)(ctx+0x6a4)=bitpos+val;
            x=(bitbuf<<shift)>>(32-val);
        } else {
            wp=*(u32 **)(ctx+0x69c);
            oldbits=bitbuf<<shift;
            bitbuf=*++wp;
            *(u32 *)(ctx+0x6a0)=bitbuf;
            *(u32 **)(ctx+0x69c)=wp;
            *(s32 *)(ctx+0x6a4)=extra+1;
            x=((bitbuf>>remaining)+oldbits)>>(32-val);
        }
        if((s32)__cntlzw((s16)x)>32-val) x=(~0U<<val)+x+1;
    }
    __dcbz(arg1,0x60);
    {
        s32 dc=*(s16 *)(ctx+0x684)+x;
        *(s16 *)(ctx+0x684)=dc;
        arg1[0]=dc;
    }
    tbl=lbl_803688A0;
    bitpos=*(s32 *)(ctx+0x6a4);
    lens=tbl+0x20;
    bitbuf=*(u32 *)(ctx+0x6a0);
    for(i=1;i<64;i++) {
        {
        s32 *maxcode;
        s32 limit, length, step;
        u32 prefix;
        u32 *stream;
        code = __rlwnm(bitbuf, bitpos + 4, 27, 31);
        if (bitpos <= 28) {
            val=tbl[code];
            step=lens[code];
            if(val!=255) {
                bitpos+=step;
                
            } else {
                maxcode=(s32 *)(tbl+0x44);
                bitpos+=5;
                length=5;
                maxcode+=5;
                for(;;) {
                    code <<= 1;
                    if(bitpos!=33) {
                        step=__rlwnm(bitbuf,bitpos,31,31);
                        limit=*++maxcode;
                        code|=step;
                        bitpos++;
                    } else {
                        stream=*(u32 **)(ctx+0x69c);
                        bitpos=1;
                        bitbuf=*++stream;
                        limit=*++maxcode;
                        *(u32 **)(ctx+0x69c)=stream;
                        code|=bitbuf>>31;
                        
                        for(;;) {
                            bitpos++;
                            length++;
                            if(code<=limit) break;
                            code <<= 1;
                            step=__rlwnm(bitbuf,bitpos,31,31);
                            limit=*++maxcode;
                            code|=step;
                        }
                        break;
                    }
                    length++;
                    if(code<=limit) break;
                }
                
                val=(*(u8 **)(tbl+0x40))[code+*(s32 *)(tbl+0x8c+length*4)];
            }
        } else {
            stream=*(u32 **)(ctx+0x69c);
            if(bitpos==33) {
                bitbuf=*++stream;
                code=bitbuf>>27;
                *(u32 **)(ctx+0x69c)=stream;
                val=tbl[code];
                step=lens[code];
                
                if(val!=255) {
                    bitpos=step+1;
                    
                } else {
                    length=5;
                    do {
                        step=31-length;
                        length++;
                        code=bitbuf>>step;
                        limit=*(s32 *)(tbl+0x44+length*4);
                    } while(code>limit);
                    bitpos=length+1;
                    
                    val=(*(u8 **)(tbl+0x40))[code+*(s32 *)(tbl+0x8c+length*4)];
                }
            } else if(bitpos==32) {
                bitbuf=*++stream;
                *(u32 **)(ctx+0x69c)=stream;
                code=(code&16)|(bitbuf>>28);
                val=tbl[code];
                step=lens[code];
                
                bitpos=step;
                
                if(val==255) {
                    maxcode=(s32 *)(tbl+0x44)+5;
                    prefix=((u32)code<<27)|(bitbuf>>1);
                    length=5;
                    do {
                        step=31-length;
                        limit=*++maxcode;
                        code=prefix>>step;
                        length++;
                    } while(code>limit);
                    bitpos=length;
                    
                    val=(*(u8 **)(tbl+0x40))[code+*(s32 *)(tbl+0x8c+length*4)];
                }
            } else {
                val=tbl[code];
                step=lens[code];
                length=bitpos+step;
                if(val!=255 && length<=33) {
                    bitpos=length;
                    
                } else {
                    step=33-bitpos;
                    code=bitbuf&~(~0U<<step);
                    maxcode=(s32 *)(tbl+0x44)+step;
                    length=step+1;
                    stream=*(u32 **)(ctx+0x69c);
                    bitbuf=*++stream;
                    *(u32 **)(ctx+0x69c)=stream;
                    code<<=1;
                    
                    code|=bitbuf>>31;
                    limit=*++maxcode;
                    bitpos=2;
                    for(;;) {
                        step=__rlwnm(bitbuf,bitpos,31,31);
                        if(code<=limit) break;
                        code<<=1;
                        length++;
                        limit=*++maxcode;
                        code+=step;
                        bitpos++;
                    }
                    
                    val=(*(u8 **)(tbl+0x40))[code+*(s32 *)(tbl+0x8c+length*4)];
                }
            }
        }
    }
        bits=val&15;
        run=val>>4;
        if(bits!=0) {
            i+=run;
            remaining=33-bitpos;
            extra=bits-remaining;
            shift=bitpos-1;
            if(extra<=0) {
                bitpos+=bits;
                x=(bitbuf<<shift)>>(32-bits);
            } else {
                wp=*(u32 **)(ctx+0x69c);
                oldbits=bitbuf<<shift;
                bitbuf=*++wp;
                bitpos=extra+1;
                *(u32 **)(ctx+0x69c)=wp;
                x=((bitbuf>>remaining)+oldbits)>>(32-bits);
            }
            if((s32)__cntlzw(x)>32-bits) x=(~0U<<bits)+x+1;
            arg1[lbl_80282FD8[i]]=(s16)x;
        } else {
            if(run!=15) break;
            i+=15;
        }
    }
    *(s32 *)(ctx+0x6a4)=bitpos;
    *(u32 *)(ctx+0x6a0)=bitbuf;
}

void fn_80242CE4(void *arg0, s16 *arg1) {
    extern u8 *lbl_80368860;
    extern u8 *lbl_803688C0;
    extern u8 lbl_80282FD8[];
    s32 bitpos;
    u32 bitbuf;
    s32 code;
    s32 n;
    u8 *tbl;
    u8 *lens;

    __dcbz(arg1, 0);
    tbl = lbl_80368860;
    lens = tbl + 0x20;
    bitpos = *(s32 *)((u8 *)arg0 + 0x6A4);
    bitbuf = *(u32 *)((u8 *)arg0 + 0x6A0);
    code = __rlwnm(bitbuf, bitpos + 4, 27, 31);
    if (bitpos <= 0x1C) {
        n = tbl[code];
        if (n != 0xFF) {
            *(s32 *)((u8 *)arg0 + 0x6A4) = bitpos + lens[code];
        }
    }
    __dcbz(arg1, 0x20);
    __dcbz(arg1, 0x40);
    __dcbz(arg1, 0x60);
    {
        s16 s = *(s16 *)((u8 *)arg0 + 0x68A);
        *arg1 = s;
    }
    (void)lbl_803688C0;
    (void)lbl_80282FD8;
}

void fn_8024338C(void *arg0, s16 *arg1) {
    extern u8 *lbl_80368880;
    extern u8 *lbl_803688E0;
    extern u8 lbl_80282FD8[];
    s32 bitpos;
    u32 bitbuf;
    s32 code;
    s32 n;
    u8 *tbl;
    u8 *lens;

    __dcbz(arg1, 0);
    tbl = lbl_80368880;
    lens = tbl + 0x20;
    bitpos = *(s32 *)((u8 *)arg0 + 0x6A4);
    bitbuf = *(u32 *)((u8 *)arg0 + 0x6A0);
    code = __rlwnm(bitbuf, bitpos + 4, 27, 31);
    if (bitpos <= 0x1C) {
        n = tbl[code];
        if (n != 0xFF) {
            *(s32 *)((u8 *)arg0 + 0x6A4) = bitpos + lens[code];
        }
    }
    __dcbz(arg1, 0x20);
    __dcbz(arg1, 0x40);
    __dcbz(arg1, 0x60);
    {
        s16 s = *(s16 *)((u8 *)arg0 + 0x690);
        *arg1 = s;
    }
    (void)lbl_803688E0;
    (void)lbl_80282FD8;
}

s32 fn_80243A34(void) {
    M2C_UNK OSRegisterVersion(s32, M2C_UNK *);
    extern M2C_UNK lbl_8033E460;
    extern s32 lbl_803670B0;
    extern s32 lbl_80368954;
    OSRegisterVersion(lbl_803670B0, &lbl_8033E460);
    M2C_FIELD(&lbl_8033E460, s32 *, 0x100) = 0xE0000000;
    M2C_FIELD(&lbl_8033E460, s32 *, 0x104) = 0xE0002000;
    M2C_FIELD(&lbl_8033E460, s32 *, 0x108) = 0xE0002800;
    M2C_FIELD(&lbl_8033E460, s32 *, 0x10C) = 0xE0000000;
    M2C_FIELD(&lbl_8033E460, s32 *, 0x110) = 0xE0002A00;
    M2C_FIELD(&lbl_8033E460, s32 *, 0x114) = 0xE0003480;
    M2C_ERROR(/* unknown instruction: mtspr GQR2, $r3 */);
    M2C_ERROR(/* unknown instruction: mtspr GQR3, $r3 */);
    M2C_ERROR(/* unknown instruction: mtspr GQR4, $r3 */);
    M2C_ERROR(/* unknown instruction: mtspr GQR5, $r3 */);
    lbl_80368954 = 1;
    return 1;
}

#pragma use_lmw_stmw on
u32 fn_80243AD4(s16 *out, void *src, s32 stereo) {
    s32 fn_80243E84(void *);
    void fn_80243F14(void *, u8 *);
    s64 fn_8022CB08(s32, u32, s32);
    s64 fn_8022CB50(s32, u32, s32);

    struct { u8 gap[0xC]; u8 st[0x10]; } sp;
    s16 *dstL;
    s16 *dstR;
    s16 yn1;
    s16 yn2;
    s32 stride;
    u32 i;
    u8 *hdr;
    u8 *base;

    if (out == 0 || src == 0) {
        return 0;
    }

    base = (u8 *)src + 0x50;
    hdr = (u8 *)src + *(s32 *)src;
    hdr += 0x50;

    if (stereo == 1) {
        dstL = out;
        stride = 1;
        dstR = out + *(s32 *)((u8 *)src + 4);
    } else {
        dstL = out;
        dstR = out + 1;
        stride = 2;
    }

    if (*(u32 *)src == 0) {
        fn_80243F14(sp.st, base);
        yn1 = *(s16 *)((u8 *)src + 0x48);
        yn2 = *(s16 *)((u8 *)src + 0x4A);
        stride *= 2;
        for (i = 0; i < *(u32 *)((u8 *)src + 4); i++) {
            s32 ni = fn_80243E84(sp.st);
            u8 *coef = (u8 *)src + (sp.st[8] << 2);
            s32 t1 = *(s16 *)(coef + 0xA) * yn2;
            s32 t0 = *(s16 *)(coef + 8) * yn1;
            s32 t2 = (ni << sp.st[9]) << 11;
            s64 acc = (s64)t1 + (s64)t0 + (s64)t2;
            s16 samp;
            acc = fn_8022CB08((s32)(acc >> 32), (u32)acc, 5);
            acc += 0x8000;
            if (acc > 0x7FFFFFFFLL) acc = 0x7FFFFFFFLL;
            if (acc < -0x80000000LL) acc = -0x80000000LL;
            samp = (s16)fn_8022CB50((s32)(acc >> 32), (u32)acc, 0x10);
            *dstR = samp;
            yn2 = yn1;
            yn1 = samp;
            *dstL = samp;
            dstR = (s16 *)((u8 *)dstR + stride);
            dstL = (s16 *)((u8 *)dstL + stride);
        }
    } else {
        fn_80243F14(sp.st, base);
        yn1 = *(s16 *)((u8 *)src + 0x48);
        yn2 = *(s16 *)((u8 *)src + 0x4A);
        stride *= 2;
        for (i = 0; i < *(u32 *)((u8 *)src + 4); i++) {
            s32 ni = fn_80243E84(sp.st);
            u8 *coef = (u8 *)src + (sp.st[8] << 2);
            s32 t1 = *(s16 *)(coef + 0xA) * yn2;
            s32 t0 = *(s16 *)(coef + 8) * yn1;
            s32 t2 = (ni << sp.st[9]) << 11;
            s64 acc = (s64)t1 + (s64)t0 + (s64)t2;
            s16 samp;
            acc = fn_8022CB08((s32)(acc >> 32), (u32)acc, 5);
            acc += 0x8000;
            if (acc > 0x7FFFFFFFLL) acc = 0x7FFFFFFFLL;
            if (acc < -0x80000000LL) acc = -0x80000000LL;
            samp = (s16)fn_8022CB50((s32)(acc >> 32), (u32)acc, 0x10);
            *dstR = samp;
            yn2 = yn1;
            yn1 = samp;
            dstR = (s16 *)((u8 *)dstR + stride);
        }
        fn_80243F14(sp.st, hdr);
        yn1 = *(s16 *)((u8 *)src + 0x4C);
        yn2 = *(s16 *)((u8 *)src + 0x4E);
        for (i = 0; i < *(u32 *)((u8 *)src + 4); i++) {
            s32 ni = fn_80243E84(sp.st);
            u8 *coef = (u8 *)src + (sp.st[8] << 2);
            s32 t1 = *(s16 *)(coef + 0x2A) * yn2;
            s32 t0 = *(s16 *)(coef + 0x28) * yn1;
            s32 t2 = (ni << sp.st[9]) << 11;
            s64 acc = (s64)t1 + (s64)t0 + (s64)t2;
            s16 samp;
            acc = fn_8022CB08((s32)(acc >> 32), (u32)acc, 5);
            acc += 0x8000;
            if (acc > 0x7FFFFFFFLL) acc = 0x7FFFFFFFLL;
            if (acc < -0x80000000LL) acc = -0x80000000LL;
            samp = (s16)fn_8022CB50((s32)(acc >> 32), (u32)acc, 0x10);
            *dstL = samp;
            yn2 = yn1;
            yn1 = samp;
            dstL = (s16 *)((u8 *)dstL + stride);
        }
    }
    return *(u32 *)((u8 *)src + 4);
}
#pragma use_lmw_stmw reset

#pragma optimization_level 3
s32 fn_80243E84(void *arg0) {
    register u8 *temp_r5;
    s32 var_r5;
    u32 tmp;

    if (!(M2C_FIELD(arg0, s32 *, 4) & 0xF)) {
        M2C_FIELD(arg0, s8 *, 8) = (s8) (((u8) *M2C_FIELD(arg0, u8 **, 0) >> 4U) & 7);
        M2C_FIELD(arg0, s8 *, 9) = (s8) (*M2C_FIELD(arg0, u8 **, 0) & 0xF);
        M2C_FIELD(arg0, u8 **, 0) = (u8 *) (M2C_FIELD(arg0, u8 **, 0) + 1);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 2);
    }
    if (M2C_FIELD(arg0, s32 *, 4) & 1) {
        temp_r5 = M2C_FIELD(arg0, u8 **, 0);
        tmp = (u32)*temp_r5 << 0x1C;
        M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_r5 + 1);
        var_r5 = (s32)tmp >> 0x1C;
    } else {
        var_r5 = (s32) ((*M2C_FIELD(arg0, u8 **, 0) << 0x18) & 0xF0000000) >> 0x1C;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 1);
    return var_r5;
}
#pragma optimization_level reset
void fn_80243F14(void *arg0, u8 *arg1) {
    M2C_FIELD(arg0, u8 **, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = 2;
    M2C_FIELD(arg0, s8 *, 8) = (s8) (((u8) *M2C_FIELD(arg0, u8 **, 0) >> 4U) & 7);
    M2C_FIELD(arg0, s8 *, 9) = (s8) (*M2C_FIELD(arg0, u8 **, 0) & 0xF);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (M2C_FIELD(arg0, u8 **, 0) + 1);
}

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

s32 fn_80243FB8(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, u8 arg5, s16 arg6) {
    void Sound_VoiceKeyOn(void *);
    void fn_80246D48(void);
    void fn_80247F1C(s32, u8, s32);
    void fn_8024A780(u8, u16, u8, u8, s32);
    void fn_8024AD04(u8, s32, u8);
    void Sound_WriteParamU8(s32, s32, u8, s32);
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

    SynthVoice *sv;
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

    sv = lbl_8036896C;
    if (sv == NULL) {
        return -1;
    }
    n = sv->next;
    lbl_8036896C = n;
    if (n != NULL) {
        n->prev = NULL;
    }
    sv->next = gKeyedVoices;
    if (gKeyedVoices != NULL) {
        gKeyedVoices->prev = sv;
    }
    z = 0;
    sv->prev = NULL;
    if (z < 0x10) {
        base = (u8 *)sv;
        *(s32 *)(base + 0x1524) = z;
        *(s32 *)(base + 0x155C) = z;
        *(s32 *)(base + 0x1594) = z;
        *(s32 *)(base + 0x15CC) = z;
        *(s32 *)(base + 0x1604) = z;
        *(s32 *)(base + 0x163C) = z;
        *(s32 *)(base + 0x1674) = z;
        *(s32 *)(base + 0x16AC) = z;
        *(s32 *)(base + 0x16E4) = z;
        *(s32 *)(base + 0x171C) = z;
        *(s32 *)(base + 0x1754) = z;
        *(s32 *)(base + 0x178C) = z;
        *(s32 *)(base + 0x17C4) = z;
        *(s32 *)(base + 0x17FC) = z;
        *(s32 *)(base + 0x1834) = z;
        *(s32 *)(base + 0x186C) = z;
    }
    gKeyedVoices = sv;
    sv->state = 1;

    base = (u8 *)sv;
    id = sv->id;
    base[0xF00] = 0;
    *(void **)(base + 0x10) = arg0;
    *(void **)(base + 0x94) = arg1;
    *(void **)(base + 0x118) = arg3;
    sv->unkA = arg6;

    i = 0;
    do {
        base[0x14 + i] = 0xFF;
        base[0x14 + (u8)(i + 1)] = 0xFF;
        base[0x14 + (u8)(i + 2)] = 0xFF;
        base[0x14 + (u8)(i + 3)] = 0xFF;
        base[0x14 + (u8)(i + 4)] = 0xFF;
        base[0x14 + (u8)(i + 5)] = 0xFF;
        base[0x14 + (u8)(i + 6)] = 0xFF;
        base[0x14 + (u8)(i + 7)] = 0xFF;
        i += 8;
    } while (i < 0x80);

    j = 0;
    p = *(u8 **)(base + 0x10);
    while (p[4] != 0xFF) {
        base[0x14 + p[4]] = j;
        p += 6;
        j++;
    }

    i = 0;
    do {
        base[0x98 + i] = 0xFF;
        base[0x98 + (u8)(i + 1)] = 0xFF;
        base[0x98 + (u8)(i + 2)] = 0xFF;
        base[0x98 + (u8)(i + 3)] = 0xFF;
        base[0x98 + (u8)(i + 4)] = 0xFF;
        base[0x98 + (u8)(i + 5)] = 0xFF;
        base[0x98 + (u8)(i + 6)] = 0xFF;
        base[0x98 + (u8)(i + 7)] = 0xFF;
        i += 8;
    } while (i < 0x80);

    j = 0;
    p = *(u8 **)(base + 0x94);
    while (p[4] != 0xFF) {
        base[0x98 + p[4]] = j;
        p += 6;
        j++;
    }

    base[0xED0] = (u8)(id + 0x17);
    off = 0;
    if (0 < 0x40) {
        for (ctr = 4; ctr != 0; ctr--) {
            q = base + off + 0x324;
            v = base[0xED0];
            q[0] = v; q[1] = v; q[2] = v; q[3] = v;
            q[4] = v; q[5] = v; q[6] = v; q[7] = v;
            q = base + off + 0x32C;
            off += 0x10;
            q[0] = v; q[1] = v; q[2] = v; q[3] = v;
            q[4] = v; q[5] = v; q[6] = v; q[7] = v;
        }
    }

    base[0xF01] = arg5;
    if (arg4 == NULL) {
        *(s32 *)(base + 0x11C) = -1;
        *(s32 *)(base + 0x120) = -1;
        z = 0;
        if (z < 0x10) {
            *(u16 *)(base + 0x153A) = 0x100;
            *(u16 *)(base + 0x1572) = 0x100;
            *(u16 *)(base + 0x15AA) = 0x100;
            *(u16 *)(base + 0x15E2) = 0x100;
            *(u16 *)(base + 0x161A) = 0x100;
            *(u16 *)(base + 0x1652) = 0x100;
            *(u16 *)(base + 0x168A) = 0x100;
            *(u16 *)(base + 0x16C2) = 0x100;
            *(u16 *)(base + 0x16FA) = 0x100;
            *(u16 *)(base + 0x1732) = 0x100;
            *(u16 *)(base + 0x176A) = 0x100;
            *(u16 *)(base + 0x17A2) = 0x100;
            *(u16 *)(base + 0x17DA) = 0x100;
            *(u16 *)(base + 0x1812) = 0x100;
            *(u16 *)(base + 0x184A) = 0x100;
            *(u16 *)(base + 0x1882) = 0x100;
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
            z = 0;
            if (z < 0x10) {
                val = *(u16 *)((u8 *)arg4 + 0xC);
                *(u16 *)(base + 0x153A) = val;
                *(u16 *)(base + 0x1572) = val;
                *(u16 *)(base + 0x15AA) = val;
                *(u16 *)(base + 0x15E2) = val;
                *(u16 *)(base + 0x161A) = val;
                *(u16 *)(base + 0x1652) = val;
                *(u16 *)(base + 0x168A) = val;
                *(u16 *)(base + 0x16C2) = val;
                *(u16 *)(base + 0x16FA) = val;
                *(u16 *)(base + 0x1732) = val;
                *(u16 *)(base + 0x176A) = val;
                *(u16 *)(base + 0x17A2) = val;
                *(u16 *)(base + 0x17DA) = val;
                *(u16 *)(base + 0x1812) = val;
                *(u16 *)(base + 0x184A) = val;
                *(u16 *)(base + 0x1882) = val;
            }
        } else {
            z = 0;
            if (z < 0x10) {
                *(u16 *)(base + 0x153A) = 0x100;
                *(u16 *)(base + 0x1572) = 0x100;
                *(u16 *)(base + 0x15AA) = 0x100;
                *(u16 *)(base + 0x15E2) = 0x100;
                *(u16 *)(base + 0x161A) = 0x100;
                *(u16 *)(base + 0x1652) = 0x100;
                *(u16 *)(base + 0x168A) = 0x100;
                *(u16 *)(base + 0x16C2) = 0x100;
                *(u16 *)(base + 0x16FA) = 0x100;
                *(u16 *)(base + 0x1732) = 0x100;
                *(u16 *)(base + 0x176A) = 0x100;
                *(u16 *)(base + 0x17A2) = 0x100;
                *(u16 *)(base + 0x17DA) = 0x100;
                *(u16 *)(base + 0x1812) = 0x100;
                *(u16 *)(base + 0x184A) = 0x100;
                *(u16 *)(base + 0x1882) = 0x100;
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
    for (i = 0; i < 0x10; i++) {
        *(u32 *)(row + 0x1510) = size;
        fn_80247F1C((s32)(size >> 10), id, i);
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
    src = *(u8 **)arg3 + (u32)arg3;
    dst = base;
    ep = base;
    for (ctr = 0x10; ctr != 0; ctr--) {
        *tab = 0x7F;
        *(s32 *)(dst + 0x36C) = 0;
        if (*(u32 *)src != 0) {
            p = (u8 *)arg3 + *(u32 *)src;
            *(u8 **)(ep + 0x124) = p;
            *(u8 **)(ep + 0x128) = p;
        } else {
            *(u8 **)(ep + 0x124) = NULL;
            *(u8 **)(ep + 0x128) = NULL;
        }
        tab[1] = 0x7F;
        *(s32 *)(dst + 0x398) = 0;
        if (*(u32 *)(src + 4) != 0) {
            p = (u8 *)arg3 + *(u32 *)(src + 4);
            *(u8 **)(ep + 0x12C) = p;
            *(u8 **)(ep + 0x130) = p;
        } else {
            *(u8 **)(ep + 0x12C) = NULL;
            *(u8 **)(ep + 0x130) = NULL;
        }
        tab[2] = 0x7F;
        *(s32 *)(dst + 0x3C4) = 0;
        if (*(u32 *)(src + 8) != 0) {
            p = (u8 *)arg3 + *(u32 *)(src + 8);
            *(u8 **)(ep + 0x134) = p;
            *(u8 **)(ep + 0x138) = p;
        } else {
            *(u8 **)(ep + 0x134) = NULL;
            *(u8 **)(ep + 0x138) = NULL;
        }
        tab[3] = 0x7F;
        *(s32 *)(dst + 0x3F0) = 0;
        if (*(u32 *)(src + 0xC) != 0) {
            p = (u8 *)arg3 + *(u32 *)(src + 0xC);
            *(u8 **)(ep + 0x13C) = p;
            *(u8 **)(ep + 0x140) = p;
        } else {
            *(u8 **)(ep + 0x13C) = NULL;
            *(u8 **)(ep + 0x140) = NULL;
        }
        tab += 4;
        dst += 0xB0;
        src += 0x10;
        ep += 0x20;
    }

    *(s32 *)(base + 0xE64) = 0;
    *(s32 *)(base + 0xE68) = 0;
    *(s32 *)(base + 0xE6C) = 0;
    for (i = 0; i < 0x10; i++) {
        fn_8025FB74(i, id, 1);
    }

    z = 0;
    if (z < 0x10) {
        *(u16 *)(base + 0xE70) = 0xFFFF;
        *(u16 *)(base + 0xE76) = 0xFFFF;
        *(u16 *)(base + 0xE7C) = 0xFFFF;
        *(u16 *)(base + 0xE82) = 0xFFFF;
        *(u16 *)(base + 0xE88) = 0xFFFF;
        *(u16 *)(base + 0xE8E) = 0xFFFF;
        *(u16 *)(base + 0xE94) = 0xFFFF;
        *(u16 *)(base + 0xE9A) = 0xFFFF;
        *(u16 *)(base + 0xEA0) = 0xFFFF;
        *(u16 *)(base + 0xEA6) = 0xFFFF;
        *(u16 *)(base + 0xEAC) = 0xFFFF;
        *(u16 *)(base + 0xEB2) = 0xFFFF;
        *(u16 *)(base + 0xEB8) = 0xFFFF;
        *(u16 *)(base + 0xEBE) = 0xFFFF;
        *(u16 *)(base + 0xEC4) = 0xFFFF;
        *(u16 *)(base + 0xECA) = 0xFFFF;
    }

    for (i = 0; i < 0x10; i++) {
        fn_8025FF6C(i, id);
    }

    if (arg2 != NULL) {
        ep = (u8 *)arg2;
        for (i = 0; i < 0x10; i++) {
            v = ep[4];
            *(u16 *)(lbl_8034BDD0 + (lbl_80368960 << 5) + (i * 2)) = 0xFFFF;
            if (i != 9) {
                j = base[0x14 + v];
                if (j != 0xFF) {
                    p = *(u8 **)(base + 0x10) + j * 6;
                    q = base + i * 6;
                    *(u16 *)(q + 0xE70) = *(u16 *)p;
                    q[0xE72] = p[2];
                    q[0xE73] = p[3];
                    q[0xE74] = j;
                }
            } else {
                j = base[0x98 + v];
                if (j != 0xFF) {
                    p = *(u8 **)(base + 0x94) + j * 6;
                    q = base + i * 6;
                    *(u16 *)(q + 0xE70) = *(u16 *)p;
                    q[0xE72] = p[2];
                    q[0xE73] = p[3];
                    q[0xE74] = j;
                }
            }
            Sound_WriteParamU8(7, i, id, ep[5]);
            Sound_WriteParamU8(0xA, i, id, ep[6]);
            Sound_WriteParamU8(0x5B, i, id, ep[7]);
            Sound_WriteParamU8(0x5D, i, id, ep[8]);
            ep += 5;
        }
    }

    z = 0;
    if (z < 0x10) {
        u16 *t = (u16 *)(lbl_8034BDD0 + (id << 5));
        t[0] = 0xFFFF; t[1] = 0xFFFF; t[2] = 0xFFFF; t[3] = 0xFFFF;
        t[4] = 0xFFFF; t[5] = 0xFFFF; t[6] = 0xFFFF; t[7] = 0xFFFF;
        t[8] = 0xFFFF; t[9] = 0xFFFF; t[10] = 0xFFFF; t[11] = 0xFFFF;
        t[12] = 0xFFFF; t[13] = 0xFFFF; t[14] = 0xFFFF; t[15] = 0xFFFF;
    }

    z = 0;
    if (z < 0x10) {
        p = base;
        for (ctr = 2; ctr != 0; ctr--) {
            *(s32 *)(p + 0x152C) = 0; *(s32 *)(p + 0x1528) = 0;
            *(s32 *)(p + 0x1534) = 0; *(s32 *)(p + 0x1530) = 0;
            *(s32 *)(p + 0x1538) = 0;
            *(s32 *)(p + 0x1564) = 0; *(s32 *)(p + 0x1560) = 0;
            *(s32 *)(p + 0x156C) = 0; *(s32 *)(p + 0x1568) = 0;
            *(s32 *)(p + 0x1570) = 0;
            *(s32 *)(p + 0x159C) = 0; *(s32 *)(p + 0x1598) = 0;
            *(s32 *)(p + 0x15A4) = 0; *(s32 *)(p + 0x15A0) = 0;
            *(s32 *)(p + 0x15A8) = 0;
            *(s32 *)(p + 0x15D4) = 0; *(s32 *)(p + 0x15D0) = 0;
            *(s32 *)(p + 0x15DC) = 0; *(s32 *)(p + 0x15D8) = 0;
            *(s32 *)(p + 0x15E0) = 0;
            *(s32 *)(p + 0x160C) = 0; *(s32 *)(p + 0x1608) = 0;
            *(s32 *)(p + 0x1614) = 0; *(s32 *)(p + 0x1610) = 0;
            *(s32 *)(p + 0x1618) = 0;
            *(s32 *)(p + 0x1644) = 0; *(s32 *)(p + 0x1640) = 0;
            *(s32 *)(p + 0x164C) = 0; *(s32 *)(p + 0x1648) = 0;
            *(s32 *)(p + 0x1650) = 0;
            *(s32 *)(p + 0x167C) = 0; *(s32 *)(p + 0x1678) = 0;
            *(s32 *)(p + 0x1684) = 0; *(s32 *)(p + 0x1680) = 0;
            *(s32 *)(p + 0x1688) = 0;
            *(s32 *)(p + 0x16B4) = 0; *(s32 *)(p + 0x16B0) = 0;
            *(s32 *)(p + 0x16BC) = 0; *(s32 *)(p + 0x16B8) = 0;
            *(s32 *)(p + 0x16C0) = 0;
            p += 0x1C0;
        }
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
        lbl_80368958 = (vid + 1) & 0x7FFFFFFF;
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
    } while ((u32)(vid + 0x10000) == 0xFFFFFFFF);

    gSynthVoicePool[id].vid = vid;
    return (s32)vid;
}

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
void fn_80244AE8(s32 arg0) {
 extern SynthVoice *gActiveVoices; extern SynthVoice *gKeyedVoices;
 extern SynthVoice gSynthVoicePool[]; extern VidList *lbl_80368964;
 void fn_80257224(s32);
 u32 id, vid; SynthVoice *p, *sv; VidList *tail; u32 i; VidList *node; SynthVoice *walk;
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
    walk=(SynthVoice *)sv->listE6C;
    while(walk!=NULL) {
     fn_80257224(((VidList *)walk)->vid);
     walk=(SynthVoice *)((VidList *)walk)->next;
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

void fn_80244D64(s32 arg0) {
    extern SynthVoice *gActiveVoices;
    extern SynthVoice *gKeyedVoices;
    extern SynthVoice *lbl_8036896C;
    extern SynthVoice gSynthVoicePool[];
    extern VidList *lbl_80368964;
    void fn_80257224(s32);
    s32 off;
    SynthVoice *sv;
    u32 i;
    SynthVoice *walk;
    VidList *node;
    VidList *tail;
    VidList **listpp;
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
                listpp = (VidList **)(off + 0xE6C);
                node = *listpp;
                goto loop_b_test;
            loop_b:
                fn_80257224(node->vid);
                node = node->next;
            loop_b_test:
                if (node != NULL) {
                    goto loop_b;
                }
                tail = sv->lists[0];
                if (tail != NULL) {
                    goto find_tail1_test;
                find_tail1:
                    tail = tail->next;
                find_tail1_test:
                    if (tail->next != NULL) {
                        goto find_tail1;
                    }
                    if (lbl_80368964 != NULL) {
                        tail->next = lbl_80368964;
                        lbl_80368964->prev = tail;
                    }
                    lbl_80368964 = sv->lists[0];
                    sv->lists[0] = NULL;
                }
                {
                    SynthVoice *sv4 = (SynthVoice *)((u8 *)sv + 4);
                    tail = sv4->lists[0];
                    if (tail != NULL) {
                        goto find_tail2_test;
                    find_tail2:
                        tail = tail->next;
                    find_tail2_test:
                        if (tail->next != NULL) {
                            goto find_tail2;
                        }
                        if (lbl_80368964 != NULL) {
                            tail->next = lbl_80368964;
                            lbl_80368964->prev = tail;
                        }
                        lbl_80368964 = sv4->lists[0];
                        sv4->lists[0] = NULL;
                    }
                }
                tail = *listpp;
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
                    lbl_80368964 = *listpp;
                    *listpp = NULL;
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

    keyed = gKeyedVoices;
    key = arg2 & 0x7FFFFFFF;
    while (keyed != NULL) {
        if (keyed->vid == (u32)key) {
            id = keyed->id | (arg2 & 0x80000000);
            goto found;
        }
        keyed = keyed->next;
    }
    active = gActiveVoices;
    while (active != NULL) {
        if (active->vid == (u32)key) {
            id = active->id | (arg2 & 0x80000000);
            goto found;
        }
        active = active->next;
    }
    id = -1;
found:
    if ((u32)(id + 0x10000) != 0xFFFFU) {
        if (!(id & 0x80000000)) {
            off = id * 0x1888;
            fn_8024A780(arg0, arg1, ((u8 *)gSynthVoicePool + off)[0xED0], arg3, arg2);
            i = 0;
            base = (u8 *)gSynthVoicePool + off;
            ed0 = base + 0xED0;
            while (i < 0x40U) {
                if (base[0x324] != *ed0) {
                    fn_8024A780(arg0, arg1, base[0x324], 0, -1);
                }
                i++;
                base++;
            }
        } else {
            switch (arg3 & 0xF) {
            case 0:
                ((u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888)[0xEEC] = arg0;
                break;
            case 1:
                *(s32 *)((u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888 + 0xEFC) = 0;
                break;
            case 2:
                base = (u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888;
                base[0xEFA] |= 8;
                base[0xEEC] = arg0;
                break;
            case 3:
                base = (u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888;
                base[0xEFA] |= 0x80;
                base[0xEEC] = arg0;
                break;
            }
        }
    }
}
#pragma opt_common_subs reset
#pragma dont_inline reset

void fn_80245518(void *arg0, s32 *arg1, u8 arg2) {
    void fn_8024A780(u8, u16, u8, u8, s32);
    void fn_8024B4B0(s32, s32, s32, s32);
    void fn_8024B3D8(s32, u16);
    void fn_8024B420(void);
    void fn_8024B458(s32, s32, s32);
    s32 fn_80259430(u16, u16, s32, s32 *, s32, u8);
    s32 fn_80259584(u16, u16, s32, s32 *, u8);
    typedef struct { s32 a; s32 b; } Pair;
    extern SynthVoice gSynthVoicePool[];
    extern SynthVoice *gActiveVoices;
    extern SynthVoice *gKeyedVoices;
    SynthVoice *sv;
    u8 *base;
    u8 *p;
    u32 vid;
    u32 id;
    u16 vol;
    u16 lim;
    u8 flags;
    u8 i;
    s32 off;
    s32 flags2;
    u16 pitch;
    u8 pan;
    u16 t;
    s32 k;
    s32 spC;
    s32 sp10;
    u16 sp14;
    u16 sp16;
    u8 sp18;
    s8 sp20;
    Pair *dst;
    Pair *src;
    s32 pad0, pad1, pad2, pad3;

    (void)pad0; (void)pad1; (void)pad2; (void)pad3;
    vid = *(u32 *)arg0;
    id = SynthFindVoice(vid);
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
    if (arg2 != 0) {
        lim = *(u16 *)((u8 *)arg0 + 4);
        vol = 5;
        if (lim >= 5) {
            vol = lim;
        }
        if (flags & 1) {
            id = SynthFindVoice(vid);
            if ((u32)(id + 0x10000) != 0xFFFF) {
                if (!(id & 0x80000000)) {
                    off = id * 0x1888;
                    base = (u8 *)gSynthVoicePool + off;
                    fn_8024A780(0, vol, base[0xED0], 2, 0);
                    p = base;
                    for (i = 0; i < 0x40; i++, p++) {
                        if (p[0x324] != base[0xED0]) {
                            fn_8024A780(0, vol, p[0x324], 0, -1);
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
                    base = (u8 *)gSynthVoicePool + off;
                    fn_8024A780(0, vol, base[0xED0], 3, 0);
                    p = base;
                    for (i = 0; i < 0x40; i++, p++) {
                        if (p[0x324] != base[0xED0]) {
                            fn_8024A780(0, vol, p[0x324], 0, -1);
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
                    base = (u8 *)gSynthVoicePool + off;
                    fn_8024A780(0, vol, base[0xED0], 1, 0);
                    p = base;
                    for (i = 0; i < 0x40; i++, p++) {
                        if (p[0x324] != base[0xED0]) {
                            fn_8024A780(0, vol, p[0x324], 0, -1);
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
        if ((u32)(id + 0x10000) == 0xFFFF) {
            *arg1 = -1;
            return;
        }
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
                    base = (u8 *)gSynthVoicePool + off;
                    fn_8024A780(pan, pitch, base[0xED0], 0, 0);
                    p = base;
                    for (i = 0; i < 0x40; i++, p++) {
                        if (p[0x324] != base[0xED0]) {
                            fn_8024A780(pan, pitch, p[0x324], 0, -1);
                        }
                    }
                } else {
                    base = (u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888;
                    base[0xEEC] = pan;
                }
            }
            if (*((u8 *)arg0 + 0x26) & 0x10) {
                id = SynthFindVoice(*(u32 *)((u8 *)arg0 + 8));
                if ((u32)(id + 0x10000) != 0xFFFF) {
                    if (!(id & 0x80000000)) {
                        sv = (SynthVoice *)((u8 *)gSynthVoicePool + id * 0x1888);
                        sv->unk11C = *(s32 *)((u8 *)arg0 + 0x1C);
                        sv->unk120 = *(s32 *)((u8 *)arg0 + 0x20);
                    } else {
                        base = (u8 *)gSynthVoicePool + (id & 0x7FFFFFFF) * 0x1888;
                        base[0xEFA] = (u8)(base[0xEFA] | 0x10);
                        *(s32 *)(base + 0xEF0) = *(s32 *)((u8 *)arg0 + 0x1C);
                        *(s32 *)(base + 0xEF4) = *(s32 *)((u8 *)arg0 + 0x20);
                    }
                }
            }
            if (*((u8 *)arg0 + 0x26) & 0x20) {
                id = SynthFindVoice(*(u32 *)((u8 *)arg0 + 8));
                t = *(u16 *)((u8 *)arg0 + 0x24);
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
        return;
    }
    flags2 = 4;
    if (flags & 8) {
        flags2 |= 0x10;
    }
    if (*((u8 *)arg0 + 0x26) & 0x20) {
        flags2 |= 2;
        sp14 = *(u16 *)((u8 *)arg0 + 0x24);
    }
    if (*((u8 *)arg0 + 0x26) & 0x10) {
        flags2 |= 1;
        spC = *(s32 *)((u8 *)arg0 + 0x1C);
        sp10 = *(s32 *)((u8 *)arg0 + 0x20);
    }
    sp16 = *(u16 *)((u8 *)arg0 + 0xC);
    sp18 = *((u8 *)arg0 + 0x18);
    sp20 = 0;
    if (arg2 != 0) {
        *arg1 = fn_80259430(*(u16 *)((u8 *)arg0 + 0x14), *(u16 *)((u8 *)arg0 + 0x16),
                            *(s32 *)((u8 *)arg0 + 0x10), &flags2, 1,
                            *((u8 *)arg0 + 0x19));
        if ((u32)(*arg1 + 0x10000) != 0xFFFF && (*((u8 *)arg0 + 0x26) & 0x80)) {
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
        *arg1 = fn_80259584(*(u16 *)((u8 *)arg0 + 0x14), *(u16 *)((u8 *)arg0 + 0x16),
                            *(s32 *)((u8 *)arg0 + 0x10), &flags2,
                            *((u8 *)arg0 + 0x19));
        if ((u32)(*arg1 + 0x10000) != 0xFFFF && (*((u8 *)arg0 + 0x26) & 0x80)) {
            fn_8024B458(*arg1, 0, 0);
        }
    }
}

void *fn_80246070(u8 arg0) {
    StreamSeqChan *chanSeq = &lbl_80368968->seqChans[arg0];
    StreamChannel *chan = &lbl_80368968->channels[arg0];
    u8 *voices;
    u8 *voiceState;
    StreamMsg *msg;
    u8 *q;
    u8 b;
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
            q = chan->unk8;
            b = q[2];
            if (b & 0x80) {
                chan->unk8 = q + 4;
            } else if ((b | q[3]) == 0) {
                chan->unk8 = q + 4;
                continue;
            } else {
                chan->unk8 = q + 6;
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

#pragma dont_inline on
StreamQueueNode *fn_80246288(StreamQueueNode *arg0, u8 arg1, u32 *arg2)
{
    return (StreamQueueNode *)(((u32)arg0 + 1) * (arg1 + 1));
}

void fn_80246D48(void) { u32 i; StreamQueueNode *node; StreamTempo *t;
if(!lbl_80368968->voices){for(i=0;i<64;i++){node=fn_80246070((u8)i);if(node){ StreamState *state=lbl_80368968; StreamQueueNode *prev=0,*cur=*(StreamQueueNode **)((u8*)state+0x1524); while(cur){if(cur->time>node->time){node->next=cur;node->prev=prev;if(prev)prev->next=node;else *(StreamQueueNode **)((u8*)state+0x1524)=node;cur->prev=node;goto next1;}prev=cur;cur=cur->next;}node->prev=prev;if(prev)prev->next=node;else *(StreamQueueNode **)((u8*)state+0x1524)=node;node->next=0; } next1:;}}
else {for(i=0;i<64;i++){node=fn_80246070((u8)i);if(node){{s32 offset=lbl_80368968->voices[i]*0x38+0x1508;t=(StreamTempo*)((u8*)lbl_80368968+offset);}{ StreamQueueNode *prev=0,*cur=t->head; while(cur){if(cur->time>node->time){node->next=cur;node->prev=prev;if(prev)prev->next=node;else t->head=node;cur->prev=node;goto next2;}prev=cur;cur=cur->next;}node->prev=prev;if(prev)prev->next=node;else t->head=node;node->next=0; }}next2:;}}}

#pragma dont_inline reset

#pragma opt_strength_reduction off
s32 fn_80246EBC(u8 arg0,u32 arg1){
StreamQueueNode *fn_80246288(StreamQueueNode*,u8,u32*);void fn_80247F1C(s32,u8,s32);
extern u32 lbl_80368960;extern f32 lbl_8036C1B0,lbl_8036C1B4,lbl_8036C1B8;extern f64 lbl_8036C1C0;
f64 fn_802387A8(f64,f64);f64 floor(f64);
u32 changed=0;s32 off=arg0*0x38;StreamTempo *tempo=(StreamTempo*)((u8*)lbl_80368968+off+0x1508);
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
t->timing[t->active*2]=__cvt_fp2unsigned((f32)fn_802387A8(lbl_8036C1B8*f,lbl_8036C1C0));
t->timing[t->active*2+1]=(s32)(f32)floor(f);
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

void fn_80247358(u32 arg0) {
    extern SynthVoice *gKeyedVoices;
    extern SynthVoice *lbl_8036896C;
    extern VidList *lbl_80368964;
    extern u8 lbl_8036895C;
    extern u32 lbl_80368960;
    extern f32 lbl_8036C1B0, lbl_8036C1B4, lbl_8036C1B8;
    extern f64 lbl_8036C1C0;
    s32 fn_80246EBC(u8, u32);
    void fn_80247F1C(s32, u8, s32);
    void fn_8024A6F8(u32);
    s32 fn_8024ACB0(u8);
    s32 fn_8024B7DC(s32);
    void fn_8025FA50(s32, u8, u8, s32);
    f64 fn_802387A8(f64, f64);
    f64 floor(f64);
    SynthVoice *sv;
    SynthVoice *svNext;
    StreamTempo *t;
    VidList *node;
    VidList *nnext;
    VidList *tail;
    u32 *event;
    u32 result;
    u32 hasLists;
    u32 i;
    u32 j;
    u32 off;
    u32 sum;
    s32 cmp;
    f32 f;
    f32 f28;
    f32 f30;
    f32 f31;
    f32 f27;
    u8 *base;
    u8 *p;
    u8 ch;
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
        t = (StreamTempo *)(base + 0x1508);
        if (t->start != NULL) {
            goto ev_check0;
        ev_body0:
            if (event[0] > t->buffers[t->active * 2 + 1]) {
                goto ev_done0;
            }
            if ((*(u32 *)(*(u8 **)((u8 *)lbl_80368968 + 0x118) + 0x10) & 0x40000000) != 0) {
                t->value = event[1];
                fn_80247F1C((s32)(event[1] >> 10), (u8)lbl_80368960, 0);
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
        f = lbl_8036C1B0 * ((f32)t->value * (f32)arg0) * (lbl_8036C1B4 * (f32)t->scale);
        t->timing[t->active * 2] = __cvt_fp2unsigned((f32)fn_802387A8(lbl_8036C1B8 * f, lbl_8036C1C0));
        t->timing[t->active * 2 + 1] = (s32)(f32)floor(f);
        result = (u32)fn_80246EBC(0, arg0);
        for (i = 0; i < 2; i++) {
            node = *(VidList **)((u8 *)lbl_80368968 + 0xE64 + i * 4);
            if (node == NULL) {
                goto list_next0;
            }
            goto list_cmp0;
        list_body0:
            fn_8024A6F8(node->vid);
            nnext = node->next;
            *(VidList **)((u8 *)lbl_80368968 + 0xE64 + i * 4) = nnext;
            if (nnext != NULL) {
                nnext->prev = NULL;
            }
            node->next = *(VidList **)((u8 *)lbl_80368968 + 0xE6C);
            if (*(VidList **)((u8 *)lbl_80368968 + 0xE6C) != NULL) {
                (*(VidList **)((u8 *)lbl_80368968 + 0xE6C))->prev = node;
            }
            *(VidList **)((u8 *)lbl_80368968 + 0xE6C) = node;
            node = *(VidList **)((u8 *)lbl_80368968 + 0xE64 + i * 4);
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
        f28 = lbl_8036C1B0;
        f30 = lbl_8036C1B4;
        f31 = lbl_8036C1B8;
        result = 0;
        for (ch = 0; ch < 0x10; ch++) {
            t = (StreamTempo *)((u8 *)lbl_80368968 + (u32)ch * 0x38 + 0x1508);
            if (t->start != NULL) {
                goto ev_check1;
            ev_body1:
                if (event[0] > t->buffers[t->active * 2 + 1]) {
                    goto ev_done1;
                }
                if ((*(u32 *)(*(u8 **)((u8 *)lbl_80368968 + 0x118) + 0x10) & 0x40000000) != 0) {
                    t->value = event[1];
                    fn_80247F1C((s32)(event[1] >> 10), (u8)lbl_80368960, (s32)ch);
                } else {
                    fn_80247F1C((s32)event[1], (u8)lbl_80368960, (s32)ch);
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
            t = (StreamTempo *)((u8 *)lbl_80368968 + (u32)ch * 0x38 + 0x1508);
            f27 = f28 * ((f32)t->value * (f32)arg0) * (f30 * (f32)t->scale);
            t->timing[t->active * 2] = __cvt_fp2unsigned((f32)fn_802387A8(f31 * f27, lbl_8036C1C0));
            t->timing[t->active * 2 + 1] = (s32)(f32)floor(f27);
            result |= (u32)fn_80246EBC(ch, arg0);
        }
        for (i = 0; i < 2; i++) {
            node = *(VidList **)((u8 *)lbl_80368968 + 0xE64 + i * 4);
            if (node == NULL) {
                goto list_next1;
            }
            goto list_cmp1;
        list_body1:
            fn_8024A6F8(node->vid);
            nnext = node->next;
            *(VidList **)((u8 *)lbl_80368968 + 0xE64 + i * 4) = nnext;
            if (nnext != NULL) {
                nnext->prev = NULL;
            }
            node->next = *(VidList **)((u8 *)lbl_80368968 + 0xE6C);
            if (*(VidList **)((u8 *)lbl_80368968 + 0xE6C) != NULL) {
                (*(VidList **)((u8 *)lbl_80368968 + 0xE6C))->prev = node;
            }
            *(VidList **)((u8 *)lbl_80368968 + 0xE6C) = node;
            node = *(VidList **)((u8 *)lbl_80368968 + 0xE64 + i * 4);
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
            fn_8025FA50(0x40, ch, (u8)lbl_80368960, 0);
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

    u8 *voice;
    u8 *node;
    u8 *previous;
    u16 *table;
    u32 i;
    u32 j;

    voice = (u8 *)gSynthVoicePool;
    table = lbl_8034BDD0;

    gKeyedVoices = NULL;
    gActiveVoices = NULL;

    i = 0;

    do {
        if (i == 0) {
            lbl_8036896C = (SynthVoice *)voice;
            *(void **)(voice + 4) = NULL;
        } else {
            *(void **)(voice - 0x1888) = voice;
            *(void **)(voice + 4) =
                (u8 *)gSynthVoicePool +
                (i - 1) * 0x1888;
        }

        table[0] = 0xFFFF;
        table[1] = 0xFFFF;
        table[2] = 0xFFFF;
        table[3] = 0xFFFF;
        table[4] = 0xFFFF;
        table[5] = 0xFFFF;
        table[6] = 0xFFFF;
        table[7] = 0xFFFF;
        table[8] = 0xFFFF;
        table[9] = 0xFFFF;
        table[10] = 0xFFFF;
        table[11] = 0xFFFF;
        table[12] = 0xFFFF;
        table[13] = 0xFFFF;

        voice[9] = i;
        i++;

        table[14] = 0xFFFF;
        voice[8] = 0;

        voice += 0x1888;

        table[15] = 0xFFFF;
        table += 16;

    } while (i < 8);

    *(void **)((u8 *)gSynthVoicePool +
               i * 0x1888 - 0x1888) = NULL;

    node = lbl_8033E590;
    previous = NULL;

    lbl_80368964 = (VidList *)node;
    *(void **)(node + 4) = NULL;

    for (j = 0; j < 0x100; j++) {
        if (previous != NULL) {
            *(void **)previous = node;
        }

        previous = node;
        *(void **)(node + 0x18) = previous;

        node += 0x14;
    }

    *(void **)previous = NULL;

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
s32 fn_8025094C(u16,u16 *);
s32 fn_802555A0(u16,u8,s32,s32,u8,u8,u8,u8,u8,u8,u16,u16,u32,u8,u8,s32);
s32 fn_8024866C(u16,s16,s32,s32,u8,u8,u8,u8,u8,u8,u16,u16,u32,u8,u8,s32);
s32 fn_80255E88(void *);
extern s32 gSynthVoices;
u32 low; s32 note; u32 high; s32 result; s32 last; u8 *entry; s32 first; s32 value; s32 balance; s32 flags; u8 vel; u32 savedPan; u32 valid; s32 status; u16 count;
first=-1;
entry=(u8 *)fn_8025094C(id,&count);
if(entry) {
low=key&127; high=key&128; savedPan=pan;
while(count) {
u16 sample=*(u16 *)entry;
if(sample!=65535 && entry[2]<=low && entry[3]>=low) {
value=low+(s8)entry[4];
if(value>127) note=127; else note=value & ~(value>>31);
if(!(sample&0xC000)) {
if(Sound_GetChanParam(0x41,channel,a8)>0x1F80U) {
result=Sound_RemapVoiceKey(note&127,channel,a8,0,&status);
valid=status==0;
} else { result=-1; valid=1; }
if(!valid) goto next;
if((u32)(result+0x10000)!=0xFFFF) goto link;
}
balance=entry[8];
if(!(balance&128)) {
balance=balance-64; balance+=savedPan;
if(balance<0) balance=0; else if(balance>127) balance=127;
} else balance=128;
volume+=*(s16 *)(entry+6);
vel=velocity*entry[5]/127;
if(volume>255) volume=255; else volume=volume & ~(volume>>31);
flags=*(u16 *)entry&0xC000;
switch(flags) {
case 0: result=fn_802555A0(*(u16 *)entry,(u8)volume,arg2,arg3,(u8)(note|high),vel,(u8)balance,channel,a8,a9,a10,a11,0,a13,a14,a15); break;
case 0x4000: result=fn_8024866C(*(u16 *)entry,volume,arg2,arg3,(u8)(note|high),vel,(u8)balance,channel,a8,a9,a10,a11,0,a13,a14,a15); break;
case 0x8000: result=fn_802482AC(*(u16 *)entry,volume,arg2,arg3,(u8)(note|high),vel,(u8)balance,channel,a8,a9,a10,a11,0,a13,a14,a15); break;
}
if((u32)(result+0x10000)!=0xFFFF) {
link:
if((u32)(first+0x10000)==0xFFFF) {
if(a12) first=fn_80255E88((u8 *)gSynthVoices+(u8)result*0x458);
else first=result;
} else {
*(s32 *)((u8 *)gSynthVoices+(u8)last*0x458+0xEC)=result;
*(s32 *)((u8 *)gSynthVoices+(u8)result*0x458+0xF0)=last;
}
last=result;
while((u32)(*(s32 *)((u8 *)gSynthVoices+(u8)last*0x458+0xEC)+0x10000)!=0xFFFF) {
*((u8 *)gSynthVoices+(u8)last*0x458+0x11C)=1;
last=*(s32 *)((u8 *)gSynthVoices+(u8)last*0x458+0xEC);
}
*((u8 *)gSynthVoices+(u8)last*0x458+0x11C)=1;
}
}
next: entry+=12; count--;
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
    u8 *table;
    u8 *entry;
    u8 *alt;
    u8 *row;
    u32 offset;
    u32 low;
    u8 original;
    s32 note;
    s32 flags;
    s32 value;
    s32 result;
    u32 valid;
    s32 status;
    u16 sample;
    s16 v;
    u16 save10;
    u16 save11;
    s32 save15;

    save10 = a10;
    save11 = a11;
    save15 = a15;
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
                v = volume;
                if (v > 255)
                    v = 255;
                else
                    v = v & ~(v >> 31);
                volume = v;
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
                    return fn_802555A0(*(u16 *)entry, (u8)volume, arg2, arg3, (u8)(key | (original & 128)), arg5, pan, arg7, a8, a9, save10, save11, (u8)a12, a13, a14, save15);
                }
                return fn_802482AC(sample, volume, arg2, arg3, (u8)(key | (original & 128)), arg5, pan, arg7, a8, a9, save10, save11, (u8)a12, a13, a14, save15);
            }
        }
    }
    return -1;
}

s32 fn_802488C8(u16 id, u8 volume, u8 arg2, s32 arg3, u8 key, s32 arg5, s32 panArg, u8 arg7, s32 a8Arg, s32 a9Arg, s32 a10Arg, s32 a11Arg, s32 a13Arg, s32 addVolumeArg, s32 a14Arg, s32 a15) {
    u8 a8 = a8Arg;
    u8 a9 = a9Arg;
    u16 a10 = a10Arg;
    u16 a11 = a11Arg;
    u8 a13 = a13Arg;
    s16 addVolume = addVolumeArg;
    u8 a14 = a14Arg;
    u8 pan = panArg;
    s32 fn_802508E0(u16);
    s32 fn_802482AC(u16,s16,s32,s32,u8,s32,u8,s32,u8,u8,u16,u16,u8,u8,u8,s32);
    s32 fn_802555A0(u16,u8,s32,s32,u8,s32,u8,s32,u8,u8,u16,u16,u8,u8,u8,s32);
    s32 status, status2;
    s32 result;
    u32 valid;
    u32 temp = (u8)(volume + addVolume);
    u8 vol = temp > 255U ? 255 : temp;
    switch (id & 0xC000) {
    case 0: {
        s32 result;
        if (Sound_GetChanParam(0x41,arg7,a8) > 0x1F80U) {
            result = Sound_RemapVoiceKey(key & 127,arg7,a8,1,&status);
            valid = status == 0;
        } else { result = -1; valid = 1; }
        if (!valid) return -1;
        if ((u32)(result + 0x10000) != 0xFFFF) return result;
        return fn_802555A0(id, vol, arg2, arg3, key, arg5, pan, arg7, a8, a9, a10, a11, 1, a13, a14, a15);
    }
    case 0x4000: {
        u8 *table = (u8 *)fn_802508E0(id);
        u8 original;
        SoundKeyEntry *entry;
        u16 sample;
        s32 flags;
        original = key;
        if (table && (entry = (SoundKeyEntry *)table + (key & 127), sample = *(u16 *)entry, sample != 0xFFFF) && (flags = sample & 0xC000, flags != 0x4000)) {
            s32 value;
            s32 note;
            s16 v;
            if (!(entry->pan & 128)) {
                value = table[(u8)key*8+3] - 64;
                value += pan;
                if (value < 0) pan=0;
                else if(value >127) pan=127;
                else pan=value;
            } else pan=128;
            note = (key & 127) + entry->key;
            if(note >127) key=127;
            else key=note & ~(note >>31);
            v = vol + entry->volume;
            if(v>255) v=255;
            else v=v & ~(v>>31);
            if(flags==0) {
                if(Sound_GetChanParam(0x41,arg7,a8)>0x1F80U) {
                    result=Sound_RemapVoiceKey((u8)key &127,arg7,a8,1,&status2);
                    valid=status2==0;
                } else {result=-1;valid=1;}
                if(!valid) result=-1;
                else if((u32)(result+0x10000)==0xFFFF)
                    result=fn_802555A0(*(u16 *)entry, (u8)v, arg2, arg3, (u8)(key | (original &128)), arg5, pan, arg7, a8, a9, a10, a11, 1, a13, a14, a15);
            } else result=fn_802482AC(sample, v, arg2, arg3, (u8)(key | (original &128)), arg5, pan, arg7, a8, a9, a10, a11, 1, a13, a14, a15);
        } else result=-1;
        if ((u32)(result + 0x10000) != 0xFFFF) {
        s32 voice = Sound_LookupVid(result);
        while ((u32)(voice + 0x10000) != 0xFFFF) {
            s32 offset = (u8)voice * 0x458;
            *((u8 *)gSynthVoices + offset + 0x11C) = 0;
            voice = *(s32 *)((u8 *)gSynthVoices + offset + 0xEC);
        }
    }
    return result;
    }
    case 0x8000:
        result=fn_802482AC(id, vol, arg2, arg3, key, arg5, pan, arg7, a8, a9, a10, a11, 1, a13, a14, a15);
        if ((u32)(result + 0x10000) != 0xFFFF) {
        s32 voice = Sound_LookupVid(result);
        while ((u32)(voice + 0x10000) != 0xFFFF) {
            s32 offset = (u8)voice * 0x458;
            *((u8 *)gSynthVoices + offset + 0x11C) = 0;
            voice = *(s32 *)((u8 *)gSynthVoices + offset + 0xEC);
        }
    }
    return result;
    default: return -1;
    }
}

void fn_80248D28(s32 arg0)
{
    extern s32 gSynthVoices;
    extern s32 lbl_803689B8;
    extern s32 lbl_803689BC;
    u32 Sound_IsHwVoiceActive(u32);
    s16 fn_80261214(s32);
    s32 fn_8025807C(s32, s32, s32);
    s32 fn_80260764(void *);
    s32 fn_802607F4(void *);
    u16 Sound_GetChanParam(s32, u8);
    s32 fn_8025785C(u8, s32);
    s32 fn_80257820(u16);
    u16 fn_802607AC(void *);
    void fn_80261BC8(s32, u16);
    void fn_80249C1C(void *, s32, s32);

    u8 spA;
    u8 sp8;
    u8 *voice;
    u8 *p;
    s32 delta;
    s32 i;
    s32 pitch;
    s32 t;
    s32 t2;
    u16 w;
    u64 flags;
    u64 now;

    voice = (u8 *)gSynthVoices + arg0 * 0x458;
    if (Sound_IsHwVoiceActive(arg0) != 0 || *(u32 *)(voice + 0x34) != 0) {
        p = voice;
        i = 0;
        now = ((u64)(u32)lbl_803689B8 << 32) | (u32)lbl_803689BC;
        delta = (s32)(now - ((((u64)*(u32 *)(voice + 0x24) << 32) | *(u32 *)(voice + 0x28))));
        *(s32 *)(voice + 0x28) = lbl_803689BC;
        *(s32 *)(voice + 0x24) = lbl_803689B8;
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
        i = 2;
        do {
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
                    } else if ((u32)t2 > 0x7F0000U) {
                        t = 0x7F0000;
                    } else {
                        t = t2;
                    }
                    *(s32 *)(p + 0x174) = t;
                }
                *(u32 *)(voice + 0x114) |= 0x2000;
            }
            p += 4;
            i -= 1;
        } while (i != 0);

        if ((*(u64 *)(voice + 0x114) & 0x20000000000ULL) != 0) {
            if (fn_8025807C((s32)(voice + 0x1E8), (s32)&spA, (s32)&sp8) != 0) {
                *(u32 *)(voice + 0x114) &= ~0x200;
            }
        }

        pitch = (*(u16 *)(voice + 0x12E) << 16) + (((s8)voice[0x130] << 16) / 100);
        if ((*(u64 *)(voice + 0x114) & 0x10030ULL) != 0) {
            if (voice[0x121] != 0xFF) {
                t = fn_80260764(voice);
                *(u16 *)(voice + 0x1DC) = (u16)t;
                t = (u16)t;
                if (t != 0x2000) {
                    t2 = t - 0x2000;
                    if (t2 < 0) {
                        pitch += voice[0x1DA] * t2 * 8;
                    } else {
                        pitch += voice[0x1DB] * t2 * 8;
                    }
                }
            }
        } else {
            t = *(u16 *)(voice + 0x1DC);
            if (t != 0x2000) {
                t2 = t - 0x2000;
                if (t2 < 0) {
                    pitch += voice[0x1DA] * t2 * 8;
                } else {
                    pitch += voice[0x1DB] * t2 * 8;
                }
            }
        }

        if ((*(u64 *)(voice + 0x114) & 0x2000ULL) != 0) {
            w = (u16)fn_802607F4(voice);
            t = (voice[0x144] << 8) + ((voice[0x145] << 8) / 100);
            if (*(s16 *)(voice + 0x154) != 0) {
                t += (*(s16 *)(voice + 0x154) * ((s32)w >> 7)) >> 7;
            }
            if ((*(u64 *)(voice + 0x114) & 0x4000ULL) != 0) {
                t2 = (*(s32 *)(voice + 0x150) * ((s32)w >> 7)) >> 7;
            } else {
                t2 = *(s32 *)(voice + 0x150);
            }
            pitch += (t * t2) >> 4;
        }

        if (voice[0x121] != 0xFF) {
            w = Sound_GetChanParam(0x41, voice[0x122]);
            if (w != *(u16 *)(voice + 0x134) ||
                (*(u64 *)(voice + 0x114) & 0x21000ULL) == 0x20000ULL) {
                if (w <= 0x1F80U) {
                    *(u32 *)(voice + 0x118) &= ~0x400;
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

        t = pitch;
        if ((*(u64 *)(voice + 0x114) & 0x400ULL) != 0) {
            t2 = (u32)(*(s32 *)(voice + 0x138) - *(s32 *)(voice + 0x140)) >> 8;
            if (t2 > 0) {
                i = *(u32 *)(voice + 0x13C);
                *(u32 *)(voice + 0x13C) =
                    i + ((delta * ((s32)(pitch - i) >> 8)) / t2);
                if ((i < (u32)pitch && *(u32 *)(voice + 0x13C) < (u32)pitch) ||
                    (i > (u32)pitch && *(u32 *)(voice + 0x13C) > (u32)pitch)) {
                    t = *(s32 *)(voice + 0x13C);
                    *(s32 *)(voice + 0x140) += delta;
                } else {
                    *(s32 *)(voice + 0x140) = *(s32 *)(voice + 0x138);
                }
            }
        }

        if ((*(u64 *)(voice + 0x114) & 0x20000000000ULL) != 0) {
            t += (*(s16 *)(voice + 0x210) * (*(s32 *)(voice + 0x1F0) >> 16)) >> 7;
        }

        pitch = fn_8025785C((u8)((u32)t >> 16), *(s32 *)(voice + 0x124)) << 16;
        if ((u16)t != 0) {
            t2 = (u32)pitch >> 16;
            pitch += (u16)t * (fn_80257820((u16)t2) - t2);
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

void fn_8024946C(s32 arg0) {
    u32 Sound_IsHwVoiceActive(s32);
    void fn_80249C1C(void *, s32, s32);
    u8 fn_802616EC(void);
    extern s32 gSynthVoices;
    extern s32 lbl_803689B8;
    extern s32 lbl_803689BC;
    extern s32 lbl_803689A4;
    extern f32 lbl_8034C324[];
    extern u8 lbl_8034C924[];
    extern f64 lbl_8036C1F8;
    extern f64 lbl_8036C200;
    extern f32 lbl_8036C1D0;
    extern f32 lbl_8036C1D4;
    extern f32 lbl_8036C1D8;
    extern f32 lbl_8036C1DC;
    extern f32 lbl_8036C1E0;
    extern f32 lbl_8036C1E4;
    extern f32 lbl_8036C1E8;
    extern f32 lbl_8036C1EC;
    extern f32 lbl_8036C1F0;

    u8 *ch;
    u32 dt;
    s32 dirty;
    f32 vol;
    f32 pitch;

    ch = (u8 *)gSynthVoices + arg0 * 0x458;
    if (Sound_IsHwVoiceActive(arg0) != 0) {
        goto fin;
    }
    if (*(u32 *)(ch + 0x34) == 0) {
        goto fin;
    }
    dt = lbl_803689BC - *(u32 *)(ch + 0x30);
    *(u32 *)(ch + 0x30) = lbl_803689BC;
    *(u32 *)(ch + 0x2C) = lbl_803689B8;
    dirty = 0;
    if (*(u32 *)(ch + 0x118) & 0x8000) {
        *(s32 *)(ch + 0x1A0) += *(s32 *)(ch + 0x198) * (s32)(dt >> 8);
        if (*(s32 *)(ch + 0x198) < 0) {
            if (*(s32 *)(ch + 0x19C) >= *(s32 *)(ch + 0x1A0)) {
                *(s32 *)(ch + 0x1A0) = *(s32 *)(ch + 0x19C);
                *(u32 *)(ch + 0x118) &= ~0x8000;
            }
        } else {
            if (*(s32 *)(ch + 0x19C) <= *(s32 *)(ch + 0x1A0)) {
                *(s32 *)(ch + 0x1A0) = *(s32 *)(ch + 0x19C);
                *(u32 *)(ch + 0x118) &= ~0x8000;
            }
        }
        dirty = 1;
        *(s32 *)(ch + 0x158) = *(s32 *)(ch + 0x1A0);
    } else {
        dirty = (*(u32 *)(ch + 0x114) & 0x1000) != 0;
    }
    *(u32 *)(ch + 0x114) &= ~0x1000;
    {
        s32 idx = ch[0x11E] * 0x30;
        f32 *tbl = lbl_8034C324;
        vol = tbl[idx / 4 + 5] * tbl[idx / 4] * tbl[((ch[0x11D] != 0) + 0x15) * 0x30 / 4];
        if (ch[0x120] != 0xFF) {
            vol = lbl_8036C1D0 * (vol * (f32)lbl_8034C924[ch[0x120]]);
        }
        if (vol != *(f32 *)(ch + 0x160)) {
            *(f32 *)(ch + 0x160) = vol;
            dirty = 1;
        }
        pitch = lbl_8036C1D4 * (f32)*(s32 *)(ch + 0x158);
    }
    (void)pitch;
    (void)dirty;
    (void)dt;
    fn_80249C1C(ch, 1, (5 - fn_802616EC()) << 8);
fin:
    if (ch[0xA8] != 0) {
        ch[0xA8] = 0;
        *(u32 *)(ch + 0x220) = 0x7FFF;
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
