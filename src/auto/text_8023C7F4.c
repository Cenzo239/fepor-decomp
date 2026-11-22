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

s32 fn_8023C7F4(void)
{
  extern u8 *lbl_80368950;
  s32 off;
  u8 **new_var;
  u8 i;
  u32 value;
  *((u8 **) (lbl_80368950 + 0x69C)) += 2;
  if ((*((*((u8 **) (lbl_80368950 - -0x69C)))++)) != 8)
  {
    return 10;
  }
  *((u16 *) (lbl_80368950 + 0x694)) = ((*((u8 **) (lbl_80368950 + 0x69C)))[0] << 8) | (*((u8 **) (lbl_80368950 + 0x69C)))[1];
  *((u8 **) (lbl_80368950 + 0x69C)) += 2;
  *((u16 *) (lbl_80368950 + 0x692)) = ((*((u8 **) (lbl_80368950 + 0x69C)))[0] << (i = 8)) | (*(new_var = (u8 **) (lbl_80368950 + 0x69C)))[1];
  *((u8 **) (lbl_80368950 + 0x69C)) += 2;
  if ((*((*((u8 **) (lbl_80368950 + 0x69C)))++)) != 3)
  {
    return 12;
  }
  for (i = 0, off = 0; i < 3; off += 6, i++)
  {
    *((u8 **) (lbl_80368950 + 0x69C)) += 1;
    value = *((*((u8 **) (lbl_80368950 + 0x69C)))++);
    if (i == 0)
    {
      if (value != 0x22)
      {
        goto fail;
      }
    }
    if (i == 0)
    {
      goto success;
    }
    if (value == 0x11)
    {
      goto success;
    }
    fail:
    return 0x13;

    success:
    lbl_80368950[off + 0x680] = *((*new_var)++);

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
lbl_80368950[off+0x681]=(u8)hi;
value = value & 15;
lbl_80368950[off+0x682]=(u8)value;
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
    u8 **pp;
    s8 value;
    u8 index;
    u8 i;
    u16 length;
    u16 total;

    state = lbl_80368950;

    lbl_803688E8 = (u8 *)lbl_8036894C;
    lbl_803688EC = (u16 *)(lbl_8036894C + 0x101);

    pp = (u8 **)(state + 0x69C);
    cursor = *pp;

    length = ((u32)cursor[0] << 8) | cursor[1];
    *pp = cursor + 2;

    length -= 2;

    do {
        state = lbl_80368950;
        cursor = *(u8 **)(state + 0x69C);

        value = *cursor;
        *(u8 **)(state + 0x69C) = cursor + 1;

        index = (u8)((value >> 4) + ((value & 0xF) << 1));

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

        *(u8 **)(state + 0x69C) += total;

        fn_8023CFE8();
        fn_8023D0D8();
        fn_8023D140(index);

        state = lbl_80368950;

        length -= total + 0x11;

        state[0x6A8] |= 1 << index;

    } while (length != 0);

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
    u32 i;
    u32 off;
    u32 ctr;
    u32 idx;
    u32 slot;
    u8 *base;
    u8 *ptr;
    volatile u32 *pBit;
    u32 bitpos;
    u32 low;
    u32 aligned;
    u8 *p;
    u8 *q;
    u8 *table;
    s32 code;
    u8 b682, b688, b68e, b687, b68d, b681;
    u32 s682, s688, s68e, s687, s68d, s681;
    u32 m681, m687, m68d, m682, m688, m68e;
    u32 p681, p687, p68d, p682, p688, p68e;
    u32 pad0, pad1;

    base = lbl_80368950;
    ptr = *(u8 **)(base + 0x69c);
    pBit = (volatile u32 *)(base + 0x6a4);
    bitpos = *pBit;
    aligned = (u32)ptr & ~3;
    low = (u32)ptr & 3;
    if (bitpos != 0x21) {
        *pBit = bitpos - ((3 - low) * 8);
    } else {
        *pBit = (low * 8) + 1;
    }

    i = 0;
    off = 0;
    *(u8 **)(lbl_80368950 + 0x69c) = (u8 *)aligned;
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
                        table = (u8 *)(*(u32 *)(q + 0x390) + *(u32 *)(p + 0x340));
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
                        table = (u8 *)(*(u32 *)(q + 0x390) + *(u32 *)(p + 0x340));
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

    s682 = (b682 << 1) + 1;
    s688 = (b688 << 1) + 1;
    s68e = (b68e << 1) + 1;
    s687 = b687 << 1;
    s68d = b68d << 1;
    s681 = b681 << 1;

    m681 = s681 * 0xe0;
    m687 = s687 * 0xe0;
    m68d = s68d * 0xe0;
    m682 = s682 * 0xe0;
    m688 = s688 * 0xe0;
    m68e = s68e * 0xe0;

    p681 = m681 + 0x300;
    p687 = m687 + 0x300;
    p68d = m68d + 0x300;
    p682 = m682 + 0x300;
    p688 = m688 + 0x300;
    p68e = m68e + 0x300;

    lbl_80368840 = base + p681;
    lbl_80368860 = base + p687;
    lbl_80368880 = base + p68d;
    lbl_803688A0 = base + p682;
    lbl_803688C0 = base + p688;
    lbl_803688E0 = base + p68e;
}
#pragma use_lmw_stmw reset

void fn_8023D59C(s32 arg0, s32 arg1, s32 arg2)
{
  extern void *lbl_80368950;
  extern s32 lbl_80368944;
  extern s32 lbl_80368948;
  void fn_8023D350();
  void fn_8023D6A8();
  void fn_8023F130();
  void fn_80240BBC();
  u16 row;
  u16 height;
  *((s32 *) (((u8 *) lbl_80368950) + 0x6B0)) = arg0;
  *((s32 *) (((u8 *) lbl_80368950) + 0x6B4)) = arg1;
  *((s32 *) (((u8 *) lbl_80368950) + 0x6B8)) = arg2;
  row = *((u16 *) (((u8 *) lbl_80368950) + 0x698));
  height = *((u16 *) (((u8 *) lbl_80368950) + 0x694));
  lbl_80368944 = __mfspr(917);
  lbl_80368948 = __mfspr(918);
  __mtspr(917, (float) 0x70007);
  __mtspr(918, 0x3D043D04);
  fn_8023D350();
  if (((*((u16 *) (((u8 *) lbl_80368950) + 0x692))) == 0x200) && (height == 0x1C0))
  {
    for (; row < height; row += 16)
    {
      fn_8023D6A8();
    }

  }
  else
    if (((*((u16 *) (((u8 *) lbl_80368950) + 0x692))) == 0x280) && (height == 0x1E0))
  {
    for (; row < height; row += 16)
    {
      fn_8023F130();
    }

  }
  else
  {
    for (; row < height; row += 16)
    {
      fn_80240BBC();
    }

  }
  __mtspr(917, lbl_80368944);
  __mtspr(918, lbl_80368948);
}

void fn_8023D6A8(void)
{
  void fn_8020543C(s32);
  void fn_80242668(void *, void *);
  void fn_80242CE4(void *, void *);
  void fn_8024338C(void *, s16 *);
  void fn_80205390(void *, void *, s32);
  extern u8 lbl_8033E460[];
  extern u8 *lbl_80368950;
  extern u8 *lbl_80368900;
  extern u32 lbl_80368920;
  void *new_var2;
  extern f32 *lbl_80368940;
  extern f32 lbl_8036C198;
  extern f32 lbl_8036C19C;
  extern f32 lbl_8036C1A0;
  extern f32 lbl_8036C1A4;
  extern f32 lbl_8036C1A8;
  u8 *pixels;
  u8 *work;
  u8 *context;
  s16 *coefficients;
  f32 *quantization;
  f32 *scratch;
  unsigned int new_var;
  f32 *source;
  f32 *destination;
  f32 x0;
  f32 x1;
  f32 x2;
  f32 x3;
  f32 x4;
  f32 x5;
  f32 x6;
  f32 x7;
  f32 z10;
  f32 z11;
  f32 z12;
  f32 z13;
  f32 z5;
  f32 t0;
  f32 t1;
  f32 t2;
  f32 t3;
  f32 t4;
  f32 t5;
  f32 t6;
  f32 t7;
  f32 even0;
  f32 even1;
  f32 even2;
  f32 even3;
  f32 c1;
  f32 c2;
  f32 c3;
  f32 c4;
  f32 bias;
  u32 block;
  u32 macroblock;
  u32 row;
  u32 col;
  u32 pass;
  u32 index;
  u32 selector;
  u32 rowOffset;
  u32 halfOffset;
  u32 stride;
  u32 zero;
  s32 sample;
  u32 bitPosition;
  u16 counter;
  ;
  fn_8020543C(3);
  scratch = (f32 *) work;
  c1 = lbl_8036C198;
  c2 = lbl_8036C19C;
  c3 = lbl_8036C1A0;
  c4 = lbl_8036C1A4;
  *((u32 *) (context + 0x6A4)) = bitPosition;
  bias = lbl_8036C1A8;
  for (macroblock = 0; macroblock < (*((u16 *) (lbl_80368950 + 0x696))); ++macroblock)
  {
    new_var2 = *((void **) (work + 0x118));
    fn_80242668(lbl_80368950, new_var2);
    fn_80242668(lbl_80368950, *((void **) (lbl_8033E460 + 0x11C)));
    fn_80242668(lbl_80368950, *((void **) (lbl_8033E460 + 0x120)));
    fn_80242668(lbl_80368950, *((void **) (lbl_8033E460 + 0x124)));
    fn_80242CE4(lbl_80368950, *((void **) (lbl_8033E460 + 0x128)));
    fn_8024338C(lbl_80368950, *((s16 **) (lbl_8033E460 + 0x12C)));
    context = lbl_80368950;
    for (block = 0; block < 6; ++block)
    {
      coefficients = *((s16 **) ((work + 0x118) + (block * 4)));
      if (block < 4)
      {
        selector = context[0x680];
        lbl_80368900 = *((u8 **) (work + 0x100));
        lbl_80368920 = 0x200;
        pixels = ((lbl_80368900 + (macroblock << 6)) + ((block & 1) << 5)) + ((block & 2) << 11);
        halfOffset = 0x800;
      }
      else
        if (block == 4)
      {
        selector = context[0x686];
        lbl_80368900 = *((u8 **) (work + 0x104));
        lbl_80368920 = 0x100;
        pixels = lbl_80368900 + (macroblock << 5);
        halfOffset = 0x400;
      }
      else
      {
        selector = context[0x68C];
        lbl_80368900 = *((u8 **) (work + 0x108));
        lbl_80368920 = 0x100;
        pixels = lbl_80368900 + (macroblock << 5);
        halfOffset = 0x400;
      }
      t5 = 0.0f;
      quantization = (f32 *) (context + (selector << 8));
      lbl_80368940 = quantization;
      for (index = 0; index < 64; ++index)
      {
        scratch[index] = quantization[index];
        scratch[index] = ((f32) coefficients[index]) * scratch[index];
      }

      for (pass = 0; pass < 2; ++pass)
      {
        for (row = 0; row < 8; ++row)
        {
          source = (destination = scratch + ((pass == 0) ? (row * 8) : (row)));
          stride = (pass == ((((((((((((0 & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF)) ? (1) : (8);
          x0 = source[0];
          x1 = source[stride];
          x2 = source[stride * 2];
          x3 = source[stride * 3];
          x4 = source[stride * 4];
          x5 = source[stride * 5];
          x6 = (long) source[stride * 6];
          c2 = x6;
          x7 = source[stride * 7];
          zero = ((((((x1 == t5) && (x2 == 0.0f)) && (x3 == 0.0f)) && (x4 == t5)) && (x5 == 0.0f)) && (c2 == 0.0f)) && (x7 == 0.0f);
          if (zero)
          {
            for (col = 0; col < 8; ++col)
            {
              destination[col * stride] = x0;
            }

          }
          else
          {
            t0 = x0 + x4;
            t1 = x0 - x4;
            t3 = x2 + c2;
            t2 = ((x2 - c2) * c2) - t3;
            even0 = t0 + t3;
            even3 = t0 - t3;
            even1 = t1 + t2;
            even2 = t1 - t2;
            z13 = x5 + x3;
            z10 = x5 - x3;
            z11 = x1 + x7;
            z12 = x1 - x7;
            t7 = z11 + z13;
            t1 = (z11 - z13) * c2;
            z5 = (z10 + z12) * c3;
            t0 = z5 - (z12 * c4);
            t2 = z5 - (z10 * c1);
            t6 = t2 - t7;
            t5 = t1 - t6;
            t4 = t0 + t5;
            destination[0] = even0 + t7;
            destination[1 * stride] = even1 + t6;
            destination[2 * stride] = even2 + (t1 - t6);
            destination[3 * stride] = even3 + t4;
            destination[4 * stride] = even3 - t4;
            destination[5 * stride] = even2 - (t1 - t6);
            destination[6 * stride] = even1 - t6;
            destination[7 * stride] = even0 - t7;
          }
          c3 += 0;
        }

      }

      for (row = 0; row < 8; ++row)
      {
        for (col = 0; col < 8; ++col)
        {
          rowOffset = ((row & 3) << 3) + ((row >= 4) ? (halfOffset) : (0));
          sample = (s32) (scratch[(2 * (row * 4)) + col] + bias);
          if (sample < 0)
          {
            sample = 0;
          }
          if (sample > 255)
          {
            sample = 255;
          }
          pixels[rowOffset + col] = (u8) sample;
        }

      }

    }

    if (context[0x6A9] != 0)
    {
      counter = *((u16 *) (context + 0x6AC));
      counter--;
      *((u16 *) (context + 0x6AC)) = counter;
      if (counter == 0)
      {
        *((u16 *) (context + 0x6AC)) = *((u16 *) (context + 0x6AA));
        bitPosition = *((u32 *) (context + 0x6A4));
        bitPosition = ((bitPosition - (-6)) & (~(new_var = 7U))) + 1;
        if (bitPosition > 0x21)
        {
          bitPosition = 0x21;
        }
        *((u32 *) (context + 0x6A4)) = bitPosition;
        *((u16 *) (context + 0x690)) = (*((u16 *) (lbl_80368950 + 0x684)) = 0);
        *((u16 *) (lbl_80368950 + 0x68A)) = 0;
      }
    }
  }

  context = lbl_80368950;
  fn_80205390(*((void **) (context + 0x6B0)), *((void **) (lbl_8033E460 + 0x100)), 0x2000);
  fn_80205390(*((void **) (context + 0x6B4)), *((void **) (lbl_8033E460 + 0x104)), 0x800);
  fn_80205390(*((void **) (context + 0x6B8)), *((void **) (lbl_8033E460 + 0x108)), 0x800);
  *((u32 *) (context + 0x6B0)) += 0x2000;
  *((u32 *) (context + 0x6B4)) += 0x800;
  *((u32 *) (context + 0x6B8)) += 0x800;
}

void fn_8023F130(void)
{
  extern u8 lbl_8033E460[];
  const f32 (*new_var2)[8];
  extern u8 *lbl_80368950;
  extern void *lbl_80368900;
  extern u32 lbl_80368920;
  extern u8 *lbl_80368940;
  extern f32 lbl_8036C198;
  extern f32 lbl_8036C19C;
  extern f32 lbl_8036C1A0;
  extern f32 lbl_8036C1A4;
  extern f32 lbl_8036C1A8;
  void fn_8020543C(s32);
  void fn_80242668(void *, void *);
  void fn_80242CE4(void *, void *);
  u8 *new_var;
  void fn_8024338C(void *, void *);
  void fn_80205390(void *, const void *, u32);
  static const f32 basis[8][8] = {{0.707106781f, 0.980785280f, 0.923879533f, 0.831469612f, 0.707106781f, 0.555570233f, 0.382683432f, 0.195090322f}, {0.707106781f, 0.831469612f, 0.382683432f, -0.195090322f, -0.707106781f, -0.980785280f, -0.923879533f, -0.555570233f}, {0.707106781f, 0.555570233f, -0.382683432f, -0.980785280f, -0.707106781f, 0.195090322f, 0.923879533f, 0.831469612f}, {0.707106781f, 0.195090322f, -0.923879533f, -0.555570233f, 0.707106781f, 0.831469612f, -0.382683432f, -0.980785280f}, {0.707106781f, -0.195090322f, -0.923879533f, 0.555570233f, 0.707106781f, -0.831469612f, -0.382683432f, 0.980785280f}, {0.707106781f, -0.555570233f, -0.382683432f, 0.980785280f, -0.707106781f, -0.195090322f, 0.923879533f, -0.831469612f}, {0.707106781f, -0.831469612f, 0.382683432f, 0.195090322f, -0.707106781f, 0.980785280f, -0.923879533f, 0.555570233f}, {0.707106781f, -0.980785280f, 0.923879533f, -0.831469612f, 0.707106781f, -0.555570233f, 0.382683432f, -0.195090322f}};
  u8 *state;
  u8 *workbuf;
  s16 *coefficients;
  f32 *quant;
  f32 *intermediate;
  u8 *dst;
  u16 width;
  u16 halfWidth;
  u16 mcuCount;
  volatile long block;
  u32 componentWidth;
  u32 offset;
  u32 row;
  u32 col;
  u32 index;
  u32 mcuIndex;
  u32 term;
  u32 stride;
  u32 bitPos;
  f32 sum;
  f32 pixel;
  f32 bias;
  f32 c0;
  f32 c1;
  f32 c2;
  f32 c3;
  workbuf = lbl_8033E460;
  state = lbl_80368950;
  width = 0x280;
  fn_8020543C(3);
  c0 = lbl_8036C198;
  c1 = lbl_8036C19C;
  c2 = lbl_8036C1A0;
  c3 = lbl_8036C1A4;
  bias = lbl_8036C1A8;
  (void) c0;
  (void) c1;
  (void) c2;
  (void) c3;
  halfWidth = 0x140;
  mcuCount = *((u16 *) (state + 0x696));
  mcuIndex = 0;
  while (mcuIndex < mcuCount)
  {
    state = lbl_80368950;
    fn_80242668(state, *((void **) (workbuf + 0x118)));
    state = lbl_80368950;
    fn_80242668(state, *((void **) (workbuf + 0x11C)));
    state = lbl_80368950;
    fn_80242668(state, *((void **) (workbuf + 0x120)));
    state = lbl_80368950;
    fn_80242668(state, *((void **) (workbuf + 0x124)));
    state = lbl_80368950;
    fn_80242CE4(state, *((void **) (workbuf + 0x128)));
    state = lbl_80368950;
    new_var = workbuf + 0x110;
    fn_8024338C(state, *((void **) (workbuf + 0x12C)));
    for (block = 0; block < 6; block++)
    {
      if (block == 0)
      {
        lbl_80368900 = *((void **) (workbuf + 0x10C));
        lbl_80368920 = 0x280;
        state = lbl_80368950;
        lbl_80368940 = state + (((u32) state[0x680]) << 8);
      }
      else
        if (block == 4)
      {
        lbl_80368900 = *((void **) new_var);
        lbl_80368920 = 0x140;
        state = lbl_80368950;
        lbl_80368940 = state + (((u32) state[0x686]) << 8);
      }
      else
        if (block == 5)
      {
        lbl_80368900 = *((void **) (workbuf + 0x114));
        state = lbl_80368950;
        lbl_80368940 = state + (((u32) state[0x68C]) << 8);
      }
      componentWidth = (4 > block) ? (0x280) : (0x140);
      quant = (f32 *) lbl_80368940;
      coefficients = *((s16 **) ((workbuf + 0x118) + (block * 4)));
      intermediate = (f32 *) workbuf;
      dst = (u8 *) lbl_80368900;
      if (block < 4)
      {
        offset = mcuIndex << 6;
        if (block & 1)
        {
          offset += 32;
        }
        if (block & 2)
        {
          offset += 0x1400;
        }
      }
      else
      {
        offset = mcuIndex << 5;
      }
      for (row = 0; row < 8; row++)
      {
        s16 *r = coefficients + (row * 8);
        f32 *q = quant + (row * 8);
        new_var2 = basis;
        if (((((((r[1] == 0) && (r[2] == 0)) && (r[3] == 0)) && (r[4] == 0)) && (r[5] == 0)) && (r[6] == 0)) && (r[7] == 0))
        {
          f32 dc = (((f32) r[0]) * q[0]) * new_var2[0][0];
          for (col = 0; col < 8; col++)
          {
            intermediate[(row * 8) + col] = dc;
          }

        }
        else
        {
          for (col = 0; col < 8; col++)
          {
            sum = 0.0f;
            for (term = 0; term < 8; term++)
            {
              sum += (((f32) r[term]) * q[term]) * new_var2[col][term];
            }

            intermediate[(row * 8) + col] = sum;
          }

        }
      }

      for (row = 0; row < 8; row++)
      {
        for (col = 0; col < 8; col++)
        {
          sum = 0.0f;
          for (term = 0; term < 8; term++)
          {
            sum += intermediate[(term * 8) + col] * new_var2[row][term];
          }

          pixel = (sum * 0.25f) + bias;
          if (pixel < 0.0f)
          {
            register pixel = 0.0f;
          }
          else
            if (pixel > 255.0f)
          {
            pixel = 255.0f;
          }
          stride = ((((row >> 2) * componentWidth) * 4) + ((row & 3) << 3)) + col;
          dst[offset + stride] = (u8) pixel;
        }

      }

    }

    state = lbl_80368950;
    if (state[0x6A9] != 0)
    {
      *((u16 *) (state + 0x6AC)) -= 1;
      if ((*((u16 *) (state + 0x6AC))) == 0)
      {
        *((u16 *) (state + 0x6AC)) = *((u16 *) (state + 0x6AA));
        bitPos = *((u32 *) (state + 0x6A4));
        bitPos = ((bitPos + 6) & (~7U)) + 1;
        if (bitPos > 32)
        {
          bitPos = 33;
        }
        *((u32 *) (state + 0x6A4)) = bitPos;
        *((u16 *) (state + 0x684)) = 0;
        *((u16 *) (state + 0x68A)) = 0;
        *((u16 *) (state + 0x690)) = 0;
      }
    }
    mcuIndex++;
  }

  state = lbl_80368950;
  fn_80205390(*((void **) (state + 0x6B0)), *((void **) (workbuf + 0x10C)), 0x2800);
  fn_80205390(*((void **) (state + 0x6B4)), *((void **) (workbuf + 0x110)), 0xA00);
  fn_80205390(*((void **) (state + 0x6B8)), *((void **) (workbuf + 0x114)), 0xA00);
  state = lbl_80368950;
  *((u8 **) (state + 0x6B0)) += 0x2800;
  state = lbl_80368950;
  *((u8 **) (state + 0x6B4)) += 0xA00;
  state = lbl_80368950;
  *((u8 **) (state + 0x6B8)) += 0xA00;
}

void fn_80240BBC(void)
{
  f32 *new_var7;
  extern u8 lbl_8033E460[];
  extern u8 *lbl_80368950;
  extern void *lbl_80368900;
  extern u32 lbl_80368920;
  u16 *new_var3;
  extern u8 *lbl_80368940;
  extern f32 lbl_8036C198;
  extern f32 lbl_8036C19C;
  extern f32 lbl_8036C1A0;
  extern f32 lbl_8036C1A4;
  extern f32 lbl_8036C1A8;
  void fn_8020543C(s32);
  void fn_80242668(void *, void *);
  void fn_80242CE4(void *, void *);
  void fn_8024338C(void *, void *);
  u32 fn_80205390(s32, s32, s32);
  static const f32 basis[8][8] = {{0.707106781f, 0.980785280f, 0.923879533f, 0.831469612f, 0.707106781f, 0.555570233f, 0.382683432f, 0.195090322f}, {0.707106781f, 0.831469612f, 0.382683432f, -0.195090322f, -0.707106781f, -0.980785280f, -0.923879533f, -0.555570233f}, {0.707106781f, 0.555570233f, -0.382683432f, -0.980785280f, -0.707106781f, 0.195090322f, 0.923879533f, 0.831469612f}, {0.707106781f, 0.195090322f, -0.923879533f, -0.555570233f, 0.707106781f, 0.831469612f, -0.382683432f, -0.980785280f}, {0.707106781f, -0.195090322f, -0.923879533f, 0.555570233f, 0.707106781f, -0.831469612f, -0.382683432f, 0.980785280f}, {0.707106781f, -0.555570233f, -0.382683432f, 0.980785280f, -0.707106781f, -0.195090322f, 0.923879533f, -0.831469612f}, {0.707106781f, -0.831469612f, 0.382683432f, 0.195090322f, -0.707106781f, 0.980785280f, -0.923879533f, 0.555570233f}, {0.707106781f, -0.980785280f, 0.923879533f, -0.831469612f, 0.707106781f, -0.555570233f, 0.382683432f, -0.195090322f}};
  u8 *state;
  int new_var5;
  u8 *workbuf;
  s16 *coefficients;
  f32 *quant;
  f32 *intermediate;
  u8 *dst;
  u16 width;
  u16 halfWidth;
  u16 mcuCount;
  f32 new_var2;
  u32 block;
  u32 componentWidth;
  short offset;
  u32 row;
  u32 col;
  u32 index;
  u32 mcuIndex;
  u32 term;
  u32 stride;
  int new_var6;
  u32 bitPos;
  volatile unsigned char chromaCount;
  f32 sum;
  f32 pixel;
  u8 *new_var4;
  f32 bias;
  f32 c0;
  f32 c1;
  int new_var;
  f32 c2;
  f32 c3;
  workbuf = lbl_8033E460;
  state = lbl_80368950;
  fn_8020543C(3);
  c0 = lbl_8036C198;
  width = *((u16 *) (state + 0x692));
  c1 = lbl_8036C19C;
  c2 = lbl_8036C1A0;
  new_var2 = lbl_8036C1A4;
  chromaCount = 5;
  c3 = new_var2;
  bias = lbl_8036C1A8;
  (void) lbl_8036C198;
  (void) c1;
  (void) c2;
  (void) c3;
  new_var3 = (u16 *) (state + 0x696);
  halfWidth = width >> 1;
  mcuCount = *new_var3;
  mcuIndex = 0;
  while (mcuIndex < mcuCount)
  {
    state = lbl_80368950;
    fn_80242668(state, *((void **) (workbuf + 0x118)));
    state = lbl_80368950;
    fn_80242668(state, *((void **) (workbuf + 0x11C)));
    state = lbl_80368950;
    fn_80242668(state, *((void **) (workbuf + 0x120)));
    state = lbl_80368950;
    fn_80242668(state, *((void **) (workbuf + 0x124)));
    state = lbl_80368950;
    fn_80242CE4(state, *((void **) (workbuf + 0x128)));
    state = lbl_80368950;
    fn_8024338C(state, *((void **) (workbuf + 0x12C)));
    for (block = 0; block < 6; block++)
    {
      if (block == 0)
      {
        lbl_80368900 = *((void **) (workbuf + 0x10C));
        lbl_80368920 = width;
        state = lbl_80368950;
        lbl_80368940 = state + (((u32) state[0x680]) << 8);
      }
      else
      {
        pixel = (sum * 0.25f) + bias;
        if (block == 4)
        {
          lbl_80368900 = *((void **) (workbuf + 0x110));
          lbl_80368920 = halfWidth;
          state = lbl_80368950;
          lbl_80368940 = state + (((u32) state[0x686]) << 8);
        }
        else
          if (block == 5)
        {
          lbl_80368900 = *((void **) (workbuf + 0x114));
          state = lbl_80368950;
          lbl_80368940 = state + (((u32) state[0x68C]) << 8);
        }
      }
      componentWidth = (block < 4) ? (width) : (halfWidth);
      new_var4 = workbuf;
      new_var4 = new_var4 + 0x118;
      quant = (f32 *) lbl_80368940;
      lbl_80368940 = new_var4 + (block * 4);
      new_var = chromaCount;
      coefficients = *((s16 **) lbl_80368940);
      intermediate = (f32 *) workbuf;
      dst = (u8 *) lbl_80368900;
      if (block < 4)
      {
        offset = mcuIndex << 6;
        if (block & 1)
        {
          offset += (new_var5 = 32);
        }
        if (block & 2)
        {
          offset += ((u32) width) << 3;
        }
      }
      else
      {
        offset = mcuIndex << new_var;
      }
      for (row = 0; row < 8; row++)
      {
        for (col = 0; col < 8; col++)
        {
          sum = 0.0f;
          for (term = 0; term < 8; term++)
          {
            index = ((term * 8) & 0xFFFFFFFFFFFFFFFFu) + col;
            sum += (((f32) coefficients[index]) * quant[index]) * basis[row][term];
          }

          intermediate[(row * 8) + col] = sum;
        }

      }

      for (row = 0; row < 8; row++)
      {
        for (col = 0; (col - 1) < (8 - 1); col++)
        {
          new_var7 = intermediate;
          sum = 0.0f;
          for (term = 0; term < 8; term++)
          {
            sum += new_var7[(row * 8) + term] * basis[col][term];
          }

          new_var6 = (row >> 2) * componentWidth;
          if (pixel < 0.0f)
          {
            pixel = 0.0f;
          }
          else
            if (pixel > 255.0f)
          {
            pixel = 255.0f;
            stride = ((new_var6 * 4) + ((row & 3) << 3)) + col;
          }
          dst[offset + stride] = (u8) pixel;
        }

        coefficients += 0;
      }

    }

    state = lbl_80368950;
    if (state[0x6A9] != (row * 0))
    {
      *((u16 *) (state + 0x6AC)) -= 1;
      if ((*((u16 *) (state + 0x6AC))) == 0)
      {
        *((u16 *) (state + 0x6AC)) = *((u16 *) (state + 0x6AA));
        bitPos = *((u32 *) (state + 0x6A4));
        ;
        if ((((bitPos + 6) & (~7U)) + 1) > new_var5)
        {
          bitPos = 33;
        }
        *((u32 *) (state + 0x6A4)) = bitPos;
        *((u16 *) (state + 0x684)) = (*((u16 *) (state + 0x68A)) = 0);
        *((u16 *) (state + 0x690)) = 0;
      }
    }
    mcuIndex++;
  }

  state = lbl_80368950;
  ;
  fn_80205390((s32) (*((void **) (state + 0x6B0))), (s32) (*((void **) (workbuf + 0x10C))), width << 4);
  fn_80205390((s32) (*((void **) (state + 0x6B4))), (s32) (*((void **) (workbuf + 0x110))), (s32) ((width >> 4) << 6));
  fn_80205390((s32) (*((void **) (state + 0x6B8))), (s32) (*((void **) (workbuf + 0x114))), (s32) ((width >> 4) << 6));
  state = (state = lbl_80368950);
  *((u8 **) (state + 0x6B0)) += (width >> 4) << 8;
  state = lbl_80368950;
  *((u8 **) (state + 0x6B4)) += (width >> 4) << 6;
  state = lbl_80368950;
  *((u8 **) (state + 0x6B8)) += (width >> 4) << 6;
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

void fn_80242CE4(void *arg0, s16 *arg1)
{
    extern u8 *lbl_80368860;
    extern u8 *lbl_803688C0;
    extern u8 lbl_80282FD8[];

    u8 *ctx;
    u8 *table;
    u8 *lengths;
    u8 *symbols;
    u32 *stream;
    u32 bitbuf;
    s32 bitpos;
    s32 phase;
    s32 index;
    s32 code;
    s32 length;
    s32 symbol;
    s32 bits;
    s32 run;
    s32 value;
    s32 shift;
    s32 limit;
    s32 offset;
    s32 dc;
    u32 bit;
    u32 mask;

    ctx = (u8 *)arg0;

    __dcbz(arg1, 0);

    stream = *(u32 **)(ctx + 0x69C);
    bitbuf = *(u32 *)(ctx + 0x6A0);
    bitpos = *(s32 *)(ctx + 0x6A4);

    table = lbl_80368860;
    lengths = table + 0x20;

    code = 0;
    length = 0;

    for (;;) {
        if (bitpos == 33) {
            stream++;
            bitbuf = *stream;
            bitpos = 1;

            *(u32 **)(ctx + 0x69C) = stream;
            *(u32 *)(ctx + 0x6A0) = bitbuf;
        }

        bit = (bitbuf >> (32 - bitpos)) & 1;
        bitpos++;

        code = (code << 1) | bit;
        length++;

        if (length == 5) {
            symbol = table[code];

            if (symbol != 0xFF) {
                break;
            }
        }

        if (length > 5) {
            limit = *(s32 *)(table + 0x44 + length * 4);

            if (code <= limit) {
                symbols = *(u8 **)(table + 0x40);
                offset = *(s32 *)(table + 0x8C + length * 4);
                symbol = symbols[code + offset];
                break;
            }
        }
    }

    *(u32 **)(ctx + 0x69C) = stream;
    *(u32 *)(ctx + 0x6A0) = bitbuf;
    *(s32 *)(ctx + 0x6A4) = bitpos;

    bits = symbol;
    value = 0;

    if (bits != 0) {
        for (index = 0; index < bits; index++) {
            if (bitpos == 33) {
                stream++;
                bitbuf = *stream;
                bitpos = 1;
            }

            bit = (bitbuf >> (32 - bitpos)) & 1;
            bitpos++;

            value = (value << 1) | bit;
        }

        if ((value & (1 << (bits - 1))) == 0) {
            value += 1 - (1 << bits);
        }
    }

    *(u32 **)(ctx + 0x69C) = stream;
    *(u32 *)(ctx + 0x6A0) = bitbuf;
    *(s32 *)(ctx + 0x6A4) = bitpos;

    dc = *(s16 *)(ctx + 0x68A);
    dc += value;

    *(s16 *)(ctx + 0x68A) = dc;
    arg1[0] = (s16)dc;

    __dcbz(arg1, 0x20);
    __dcbz(arg1, 0x40);
    __dcbz(arg1, 0x60);

    table = lbl_803688C0;
    lengths = table + 0x20;

    index = 1;

    while (index < 64) {
        code = 0;
        length = 0;

        for (;;) {
            if (bitpos == 33) {
                stream++;
                bitbuf = *stream;
                bitpos = 1;

                *(u32 **)(ctx + 0x69C) = stream;
                *(u32 *)(ctx + 0x6A0) = bitbuf;
            }

            bit = (bitbuf >> (32 - bitpos)) & 1;
            bitpos++;

            code = (code << 1) | bit;
            length++;

            if (length == 5) {
                symbol = table[code];

                if (symbol != 0xFF) {
                    break;
                }
            }

            if (length > 5) {
                limit = *(s32 *)(table + 0x44 + length * 4);

                if (code <= limit) {
                    symbols = *(u8 **)(table + 0x40);
                    offset = *(s32 *)(table + 0x8C + length * 4);
                    symbol = symbols[code + offset];
                    break;
                }
            }
        }

        *(u32 **)(ctx + 0x69C) = stream;
        *(u32 *)(ctx + 0x6A0) = bitbuf;
        *(s32 *)(ctx + 0x6A4) = bitpos;

        if (symbol == 0) {
            break;
        }

        run = symbol >> 4;
        bits = symbol & 0xF;

        if (bits == 0) {
            if (run == 15) {
                index += 16;
                continue;
            }

            break;
        }

        index += run;

        if (index >= 64) {
            break;
        }

        value = 0;

        for (shift = 0; shift < bits; shift++) {
            if (bitpos == 33) {
                stream++;
                bitbuf = *stream;
                bitpos = 1;
            }

            bit = (bitbuf >> (32 - bitpos)) & 1;
            bitpos++;

            value = (value << 1) | bit;
        }

        if ((value & (1 << (bits - 1))) == 0) {
            value += 1 - (1 << bits);
        }

        arg1[lbl_80282FD8[index]] = (s16)value;

        index++;

        *(u32 **)(ctx + 0x69C) = stream;
        *(u32 *)(ctx + 0x6A0) = bitbuf;
        *(s32 *)(ctx + 0x6A4) = bitpos;
    }

    *(u32 **)(ctx + 0x69C) = stream;
    *(u32 *)(ctx + 0x6A0) = bitbuf;
    *(s32 *)(ctx + 0x6A4) = bitpos;
}

void fn_8024338C(void *arg0, s16 *arg1)
{
    extern u8 *lbl_80368880;
    extern u8 *lbl_803688E0;
    extern u8 lbl_80282FD8[];

    u8 *ctx;
    u8 *table;
    u8 *lens;
    u8 *zigzag;
    u32 *stream;
    u32 buffer;
    u32 code;
    u32 symbol;
    u32 length;
    u32 threshold;
    u32 index;
    u32 bits;
    u32 extra;
    u32 raw;
    u32 prefix;
    u32 off;
    s32 position;
    s32 category;
    s32 value;
    s32 dc;
    s32 run;
    s32 coefficient;

    ctx = (u8 *)arg0;
    /* First 32 bytes of the 8x8 coefficient block. */
    __dcbz(arg1, 0);

    table = lbl_80368880;
    lens = table + 0x20;
    position = *(s32 *)(ctx + 0x6A4);
    buffer = *(u32 *)(ctx + 0x6A0);
    code = __rlwnm(buffer, position + 4, 27, 31);

    if (position <= 28) {
        symbol = table[code];
        if (symbol != 0xFF) {
            position += lens[code];
            *(s32 *)(ctx + 0x6A4) = position;
            goto dc_decoded;
        }
        length = 5;
        position += 5;
        goto dc_long;
    }

    stream = *(u32 **)(ctx + 0x69C);
    if (position == 33) {
        stream++;
        buffer = *stream;
        *(u32 **)(ctx + 0x69C) = stream;
        *(u32 *)(ctx + 0x6A0) = buffer;
        code = (code & 0x10) | (buffer >> 28);
        symbol = table[code];
        position = lens[code];
        *(s32 *)(ctx + 0x6A4) = position;
        if (symbol != 0xFF) {
            goto dc_decoded;
        }
        length = 5;
        position = 6;
        goto dc_long;
    }

    if (position == 32) {
        stream++;
        buffer = *stream;
        *(u32 **)(ctx + 0x69C) = stream;
        *(u32 *)(ctx + 0x6A0) = buffer;
        code = buffer >> 27;
        symbol = table[code];
        position = lens[code] + 1;
        if (symbol != 0xFF) {
            *(s32 *)(ctx + 0x6A4) = position;
            goto dc_decoded;
        }
        length = 5;
        position = 6;
        goto dc_long;
    }

    symbol = table[code];
    position += lens[code];
    if (symbol != 0xFF && position <= 33) {
        *(s32 *)(ctx + 0x6A4) = position;
        goto dc_decoded;
    }

    stream++;
    buffer = *stream;
    *(u32 **)(ctx + 0x69C) = stream;
    *(u32 *)(ctx + 0x6A0) = buffer;
    code = (position & 0x10) | (buffer >> 28);
    symbol = table[code];
    position = lens[code];
    *(s32 *)(ctx + 0x6A4) = position;
    if (symbol != 0xFF) {
        goto dc_decoded;
    }
    length = 5;
    position = 6;

dc_long:
    /* Resolve a code not represented by the 5-bit fast table. */
    for (;;) {
        if (position == 33) {
            stream = *(u32 **)(ctx + 0x69C);
            stream++;
            buffer = *stream;
            *(u32 **)(ctx + 0x69C) = stream;
            *(u32 *)(ctx + 0x6A0) = buffer;
            position = 1;
        }
        code = (code << 1) | __rlwnm(buffer, position, 31, 31);
        position++;
        length++;
        threshold = *(u32 *)(table + 0x44 + length * 4);
        if (code <= threshold) {
            break;
        }
    }
    *(s32 *)(ctx + 0x6A4) = position;
    off = *(u32 *)(table + 0x40);
    off += *(u32 *)(table + 0x8C + length * 4);
    symbol = *(u8 *)(off + code);

dc_decoded:
    /* Clear the remaining three 32-byte cache lines. */
    __dcbz(arg1, 0x20);
    __dcbz(arg1, 0x40);

    value = 0;
    category = (s32)symbol;
    if (category != 0) {
        position = *(s32 *)(ctx + 0x6A4);
        buffer = *(u32 *)(ctx + 0x6A0);
        bits = (u32)category;
        extra = 33 - position;
        if (bits <= extra) {
            raw = (buffer << (position - 1)) >> (32 - bits);
            position += bits;
            *(s32 *)(ctx + 0x6A4) = position;
        } else {
            stream = *(u32 **)(ctx + 0x69C);
            prefix = buffer << (position - 1);
            stream++;
            buffer = *stream;
            *(u32 *)(ctx + 0x6A0) = buffer;
            *(u32 **)(ctx + 0x69C) = stream;
            position = (s32)bits - (s32)extra + 1;
            *(s32 *)(ctx + 0x6A4) = position;
            raw = (prefix + (buffer >> extra)) >> (32 - bits);
        }
        if (raw < (1U << (bits - 1))) {
            raw += 1U - (1U << bits);
        }
        value = (s16)raw;
    }

    __dcbz(arg1, 0x60);
    dc = (s16)(*(s16 *)(ctx + 0x690) + value);
    *(s16 *)(ctx + 0x690) = (s16)dc;
    arg1[0] = (s16)dc;
    zigzag = lbl_80282FD8;

    /* The remaining 63 coefficients are run-length/Huffman coded. */
    index = 1;
    while (index < 64) {
        table = lbl_803688E0;
        lens = table + 0x20;
        position = *(s32 *)(ctx + 0x6A4);
        buffer = *(u32 *)(ctx + 0x6A0);
        code = __rlwnm(buffer, position + 4, 27, 31);

        if (position <= 28) {
            symbol = table[code];
            if (symbol != 0xFF) {
                position += lens[code];
                *(s32 *)(ctx + 0x6A4) = position;
                goto ac_decoded;
            }
            length = 5;
            position += 5;
            goto ac_long;
        }

        stream = *(u32 **)(ctx + 0x69C);
        if (position == 33) {
            stream++;
            buffer = *stream;
            *(u32 **)(ctx + 0x69C) = stream;
            *(u32 *)(ctx + 0x6A0) = buffer;
            code = (code & 0x10) | (buffer >> 28);
            symbol = table[code];
            position = lens[code];
            *(s32 *)(ctx + 0x6A4) = position;
            if (symbol != 0xFF) {
                goto ac_decoded;
            }
            length = 5;
            position = 6;
            goto ac_long;
        }

        if (position == 32) {
            stream++;
            buffer = *stream;
            *(u32 **)(ctx + 0x69C) = stream;
            *(u32 *)(ctx + 0x6A0) = buffer;
            code = buffer >> 27;
            symbol = table[code];
            position = lens[code] + 1;
            if (symbol != 0xFF) {
                *(s32 *)(ctx + 0x6A4) = position;
                goto ac_decoded;
            }
            length = 5;
            position = 6;
            goto ac_long;
        }

        symbol = table[code];
        position += lens[code];
        if (symbol != 0xFF && position <= 33) {
            *(s32 *)(ctx + 0x6A4) = position;
            goto ac_decoded;
        }

        stream++;
        buffer = *stream;
        *(u32 **)(ctx + 0x69C) = stream;
        *(u32 *)(ctx + 0x6A0) = buffer;
        code = (position & 0x10) | (buffer >> 28);
        symbol = table[code];
        position = lens[code];
        *(s32 *)(ctx + 0x6A4) = position;
        if (symbol != 0xFF) {
            goto ac_decoded;
        }
        length = 5;
        position = 6;

ac_long:
        for (;;) {
            if (position == 33) {
                stream = *(u32 **)(ctx + 0x69C);
                stream++;
                buffer = *stream;
                *(u32 **)(ctx + 0x69C) = stream;
                *(u32 *)(ctx + 0x6A0) = buffer;
                position = 1;
            }
            code = (code << 1) | __rlwnm(buffer, position, 31, 31);
            position++;
            length++;
            threshold = *(u32 *)(table + 0x44 + length * 4);
            if (code <= threshold) {
                break;
            }
        }
        *(s32 *)(ctx + 0x6A4) = position;
        off = *(u32 *)(table + 0x40);
        off += *(u32 *)(table + 0x8C + length * 4);
        symbol = *(u8 *)(off + code);

ac_decoded:
        run = (s32)(symbol >> 4);
        category = (s32)(symbol & 15);
        if (category == 0) {
            if (run == 15) {
                index += 16;
                continue;
            }
            break;
        }

        index += run;
        position = *(s32 *)(ctx + 0x6A4);
        buffer = *(u32 *)(ctx + 0x6A0);
        bits = (u32)category;
        extra = 33 - position;
        if (bits <= extra) {
            raw = (buffer << (position - 1)) >> (32 - bits);
            position += bits;
            *(s32 *)(ctx + 0x6A4) = position;
        } else {
            stream = *(u32 **)(ctx + 0x69C);
            prefix = buffer << (position - 1);
            stream++;
            buffer = *stream;
            *(u32 *)(ctx + 0x6A0) = buffer;
            *(u32 **)(ctx + 0x69C) = stream;
            position = (s32)bits - (s32)extra + 1;
            *(s32 *)(ctx + 0x6A4) = position;
            raw = (prefix + (buffer >> extra)) >> (32 - bits);
        }
        if (raw < (1U << (bits - 1))) {
            raw += 1U - (1U << bits);
        }

        coefficient = (s16)raw;
        arg1[zigzag[index]] = (s16)coefficient;
        index++;
    }
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
