/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"

#include <dolphin/os.h>
#include "global.h"
#include "ef.h"



typedef struct CardDirEntry {
    u8 unk0[4];
    u8 unk4[2];
    u8 pad6[1];
    u8 unk7;
    u8 unk8[0x20];
    s32 unk28;
    s32 unk2C;
    u16 unk30;
    u16 unk32;
    u8 unk34;
    u8 unk35;
    u8 pad36[6];
    s32 unk3C;
} CardDirEntry;
extern s32 gSaveDataBase;
extern s32 fn_80013E50(s32);
extern s32 fn_80013E60(s32, s32);
extern s32 fn_80013E74(void*, s32);

extern u8 lbl_8033A420[];
extern u8 lbl_80366FF2;
extern s32 lbl_80368614;
extern void (*lbl_803685E8)(void);
extern void* lbl_80368618;
extern void* lbl_8036861C;
extern void* lbl_80368620;
extern void* lbl_80368624;
extern void* lbl_80368628;
extern void* lbl_8036862C;
extern void* lbl_80368630;
extern void* lbl_80368634;
extern void* lbl_80368638;
extern void* lbl_8036863C;
extern void* lbl_80368640;
extern void* lbl_80368644;
extern void* lbl_80368648;
extern void* lbl_8036864C;
extern void* lbl_80368650;
extern void* lbl_80368654;

u8 ErrorCode2Num(s32);

extern u8 lbl_802820B8[];
extern u32 lbl_80368448;

static u32 sFaceResAddrs[8];
static u32 sFaceResIds[8];
static s16 lbl_80339328[8];
static s16 lbl_80339338[8];

extern s32 lbl_803679F0;

extern u16 lbl_8029B634[10];

#pragma opt_common_subs off

#pragma opt_common_subs reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern u16 lbl_8029B7FC[10];

#pragma opt_common_subs off

#pragma opt_common_subs reset

extern u16 lbl_8029B7A4[10];

#pragma opt_common_subs off

#pragma opt_common_subs reset

extern void *IDShouldBe_8036859C;
extern void *fn_8020DAE0;
extern void fn_8020C1A4(u8, u32, void *);

extern u8 lbl_80289EB8[16];

typedef struct CardCtrl {
    u8 unk0[0xC];
    u32 sectorSize;
    u8 unk10[0xAC];
    u16 fileNo;
    u8 unkBE[2];
    void *apiFd;
    u8 unkC4[0xC];
    void *apiCb;
    u8 unkD4[0x38];
    void *diskID;
} CardCtrl;

/* Lock/select the memory card EXI channel and arm the command timeout alarm. */

#pragma optimization_level 3

#pragma optimization_level reset

extern u16 __CARDBlock[];

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma optimization_level 3

#pragma optimization_level 4

#pragma optimization_level 3

#pragma optimization_level reset

s32 fn_802198C0(u16 *arg0, s32 arg1, u16 *arg2, u16 *arg3);
s32 fn_80205110(void *, s32);
void fn_80219734(s32, s32);
#pragma optimization_level 3

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma global_optimizer reset
#pragma opt_strength_reduction off
#pragma opt_common_subs reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma opt_strength_reduction on

#pragma opt_strength_reduction off

#pragma global_optimizer off

#pragma global_optimizer on

#pragma dont_inline on

#pragma use_lmw_stmw on

#pragma dont_inline reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

s64 OSGetTime(void);
s32 __CARDGetDirBlock(void *arg0);
s32 __CARDGetFatBlock(void *arg0);
s32 __CARDUpdateDir(s32 arg0, s32 arg1);
s32 __CARDPutControlBlock(void *arg0, s32 arg1);
int __CARDEraseSector(s32 chan, u32 addr, void *callback);
void __CARDEraseCallback(s32 chan, s32 result);
#pragma dont_inline on
/* Continue a CARD file write: on success update dir time or erase/write next FAT block. */

#pragma dont_inline reset

#pragma optimization_level 3

#pragma optimization_level reset

#pragma inline_depth(0)

#pragma inline_depth(8)

#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

#pragma push
#pragma optimization_level 4
typedef s64 OSTime;
typedef struct OSContext {
    u32 gpr[32];
    u32 cr;
    u32 lr;
    u32 ctr;
    u32 xer;
    f64 fpr[32];
    u32 fpscr_pad;
    u32 fpscr;
    u32 srr0;
    u32 srr1;
    u16 mode;
    u16 state;
    u32 gqr[8];
    u32 psf_pad;
    f64 psf[32];
} OSContext;
typedef s32 OSPriority;
typedef struct OSThread OSThread;
typedef struct OSMutex OSMutex;
typedef struct OSThreadQueue OSThreadQueue;
typedef struct OSMutexQueue OSMutexQueue;
typedef struct OSThreadLink OSThreadLink;
typedef struct OSMutexLink OSMutexLink;
struct OSThreadQueue {
    OSThread *head;
    OSThread *tail;
};
struct OSThreadLink {
    OSThread *next;
    OSThread *prev;
};
struct OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
};
struct OSMutexLink {
    OSMutex *next;
    OSMutex *prev;
};
struct OSThread {
    OSContext context;
    u16 state;
    u16 attr;
    s32 suspend;
    OSPriority priority;
    OSPriority base;
    void *val;
    OSThreadQueue *queue;
    OSThreadLink link;
    OSThreadQueue queueJoin;
    OSMutex *mutex;
    OSMutexQueue queueMutex;
    OSThreadLink linkActive;
    u8 *stackBase;
    u32 *stackEnd;
    s32 error;
    void *specific[2];
};
struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;
    OSMutexLink link;
};
typedef struct OSAlarm OSAlarm;
typedef void (*OSAlarmHandler)(OSAlarm *alarm, OSContext *context);
struct OSAlarm {
    OSAlarmHandler handler;
    u32 tag;
    OSTime fire;
    OSAlarm *prev;
    OSAlarm *next;
    OSTime period;
    OSTime start;
};
typedef struct DVDDiskID {
    char gameName[4];
    char company[2];
    u8 diskNumber;
    u8 gameVersion;
    u8 streaming;
    u8 streamingBufSize;
    u8 padding[22];
} DVDDiskID;
typedef void (*DSPCallback)(void *task);
typedef struct STRUCT_DSP_TASK DSPTaskInfo;
typedef struct STRUCT_DSP_TASK {
    volatile u32 state;
    volatile u32 priority;
    volatile u32 flags;
    u16 *iram_mmem_addr;
    u32 iram_length;
    u32 iram_addr;
    u16 *dram_mmem_addr;
    u32 dram_length;
    u32 dram_addr;
    u16 dsp_init_vector;
    u16 dsp_resume_vector;
    DSPCallback init_cb;
    DSPCallback res_cb;
    DSPCallback done_cb;
    DSPCallback req_cb;
    DSPTaskInfo *next;
    DSPTaskInfo *prev;
    OSTime t_context;
    OSTime t_task;
} DSPTaskInfo;
typedef void (*CARDCallback)(s32 chan, s32 result);
typedef struct CARDFileInfo {
    s32 chan;
    s32 fileNo;
    s32 offset;
    s32 length;
    u16 iBlock;
} CARDFileInfo;
typedef struct CARDDir {
    u8 gameName[4];
    u8 company[2];
    u8 _padding0;
    u8 bannerFormat;
    u8 fileName[32];
    u32 time;
    u32 iconAddr;
    u16 iconFormat;
    u16 iconSpeed;
    u8 permission;
    u8 copyTimes;
    u16 startBlock;
    u16 length;
    u8 _padding1[2];
    u32 commentAddr;
} CARDDir;
typedef struct CARDControl {
    BOOL attached;
    s32 result;
    u16 size;
    u16 pageSize;
    s32 sectorSize;
    u16 cBlock;
    u16 vendorID;
    s32 latency;
    u8 id[12];
    int mountStep;
    int formatStep;
    u32 scramble;
    DSPTaskInfo task;
    void *workArea;
    CARDDir *currentDir;
    u16 *currentFat;
    OSThreadQueue threadQueue;
    u8 cmd[9];
    s32 cmdlen;
    volatile u32 mode;
    int retry;
    int repeat;
    u32 addr;
    void *buffer;
    s32 xferred;
    u16 freeNo;
    u16 startBlock;
    CARDFileInfo *fileInfo;
    CARDCallback extCallback;
    CARDCallback txCallback;
    CARDCallback exiCallback;
    CARDCallback apiCallback;
    CARDCallback xferCallback;
    CARDCallback eraseCallback;
    CARDCallback unlockCallback;
    OSAlarm alarm;
    u32 cid;
    const DVDDiskID *diskID;
} CARDControl;
typedef struct CARDID {
    u8 serial[32];
    u16 deviceID;
    u16 size;
    u16 encode;
    u8 padding[470];
    u16 checkSum;
    u16 checkSumInv;
} CARDID;
s32 fn_8021D614(s32 chan, u32 *serialNo_) {
    u64 *serialNo = (u64 *)serialNo_;
    s32 fn_80217B18(s32 chan, CARDControl **pcard);
    s32 __CARDPutControlBlock(CARDControl *card, s32 result);
    CARDControl *card;
    s32 result;
    CARDID *id;
    u64 code;
    int i;
    if (!(0 <= chan && chan < 2)) {
        return -128;
    }
    result = fn_80217B18(chan, &card);
    if (result < 0) {
        return result;
    }
    id = (CARDID *)card->workArea;
    for (code = 0, i = 0; i < sizeof(id->serial) / sizeof(u64); ++i) {
        code ^= *(u64 *)&id->serial[sizeof(u64) * i];
    }
    *serialNo = code;
    return __CARDPutControlBlock(card, 0);
}
#pragma pop
