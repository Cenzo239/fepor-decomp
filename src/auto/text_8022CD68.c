/* string pool for double2hex / printf float specials */
const char stringBase0_80282C60[] =
    "\0-INF\0-inf\0INF\0inf\0-NAN\0-nan\0NAN\0nan";
#define double2hex_strpool stringBase0_80282C60

/* Functions from 0x8022CD68 to 0x80267A7C, found by decomp-toolkit. */
#include "common.h"
typedef struct RuntimeDecimal { u8 sign; s16 exponent; u8 length; u8 digits[36]; } RuntimeDecimal;

extern f32 lbl_80367068;
extern f64 lbl_8036BE20;
extern f64 lbl_8036BE28;
extern f64 lbl_8036BE30;
extern f64 lbl_8036BE38;
extern f64 lbl_8036BE40;
extern f64 lbl_8036BE48;
extern f64 lbl_8036BE50;
extern f64 lbl_8036BE58;
extern f64 lbl_8036BE60;
extern f64 lbl_8036BE68;
extern f64 lbl_8036BE70;
extern f64 lbl_8036BE78;
extern f64 lbl_8036BE80;
extern f64 lbl_8036BE88;
extern f64 lbl_8036BE90;
extern f64 lbl_8036BE98;
extern f64 lbl_8036BEA0;

extern f64 fn_80238A9C(f64, f64);

extern s32 lbl_80366F28;
extern char lbl_80282AE8[];
extern char lbl_80282B20[];
extern void *__stdio_exit;
extern void __close_all(void);
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
extern void (*_dtors[])(void);
extern void _ExitProcess(void);
extern s16 lbl_802A1E90[];
extern u8 lbl_80368AAE;
extern u8 lbl_80368AAD;
extern u16 lbl_8035BF18[];
extern u32 lbl_8035C918[];

typedef struct __InStrCtrl {
    char *NextChar;
    s32 NullCharDetected;
} __InStrCtrl;

u32 fn_8026367C(void);
u16 Sound_GetChanParam(u8 arg0, u8 arg1, u8 arg2);
s32 __cvt_fp2unsigned(f32 arg0);
void Sound_SetVoiceEnvelope(u8 arg0, void *arg1, s32 arg2);
void fn_8026146C(s32 *);
void fn_8025FFC8(void *arg0, u8 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5);
s32 Sound_LookupVid(void);
extern void func_80013934(s32 arg0);
extern s32 gSynthVoices;
extern u16 lbl_803548B8;
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
    u8 pad124[0xEF0 - 0x124];
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


void __unregister_fragment(s32 arg0) {
    extern u8 fragmentinfo_8033DD28[];
    s32 *p;

    if (arg0 < 0) {
        return;
    }
    if (arg0 >= 1) {
        return;
    }
    p = (s32 *)((u8 *)fragmentinfo_8033DD28 + arg0 * 12);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}

s32 __register_fragment(s32 arg0, s32 arg1) {
extern s32 fragmentinfo_8033DD28[3];
s32 i;
for (i=0;i<1;i++) {
s32 *info=&fragmentinfo_8033DD28[i*3];
if (info[2]==0) {
info[0]=arg0;
info[1]=arg1;
info[2]=1;
return i;
}
}
return -1;
}

void fn_8022CDD0(void *arg0) {
u32 OSGetArenaLo(void);
u32 OSGetArenaHi(void);
void OSSetArenaLo(u32);
void OSReport(const char *,...);
u32 fn_80204CE4(u32,u32,s32);
s32 fn_80204D54(u32,u32);
void fn_80204CD4(s32);
void fn_80204C58(s32,void *);
u32 lo, hi;
if (lbl_80366F28 == -1) {
OSReport(lbl_80282AE8);
OSReport(lbl_80282B20);
lo=OSGetArenaLo();
hi=OSGetArenaHi();
lo=fn_80204CE4(lo,hi,1);
hi &= ~31;
OSSetArenaLo(lo);
lo=(lo+31)&~31;
fn_80204CD4(fn_80204D54(lo,hi));
OSSetArenaLo(hi);
}
fn_80204C58(lbl_80366F28,arg0);
}

void exit(void) {
    void __begin_critical_region(s32);
    void __end_critical_region(s32);
    void __destroy_global_chain(void);
    void __kill_critical_regions(void);
    void (**dtor)(void);

    if (__aborting == 0) {
        __begin_critical_region(0);
        __end_critical_region(0);
        __destroy_global_chain();
        dtor = _dtors;
        while (*dtor != 0) {
            (*dtor)();
            dtor++;
        }
        if (__stdio_exit != 0) {
            ((void (*)(void))__stdio_exit)();
            __stdio_exit = 0;
        }
    }
    __begin_critical_region(0);
    while (__atexit_curr_func > 0) {
        __atexit_curr_func--;
        __atexit_funcs[__atexit_curr_func]();
    }
    __end_critical_region(0);
    __kill_critical_regions();
    if (__console_exit != 0) {
        __console_exit();
        __console_exit = 0;
    }
    _ExitProcess();
}

void abort(void) {
    extern s32 __aborting;
    extern s32 __atexit_curr_func;
    extern void (*__atexit_funcs[])(void);
    extern void (*__console_exit)(void);

    void signal_raise(s32);
    void __begin_critical_region(s32);
    void __end_critical_region(s32);
    void __kill_critical_regions(void);
    void _ExitProcess(void);

    signal_raise(1);

    __aborting = 1;

    __begin_critical_region(0);

    while (__atexit_curr_func > 0) {
        __atexit_curr_func--;
        __atexit_funcs[__atexit_curr_func]();
    }

    __end_critical_region(0);
    __kill_critical_regions();

    if (__console_exit != 0) {
        __console_exit();
        __console_exit = 0;
    }

    _ExitProcess();
}

void fn_8022D014(void *arg0)
{
    extern u8 lbl_803687E8;
    extern u8 lbl_8033DE38[];

    extern void __begin_critical_region(s32);
    extern void __end_critical_region(s32);
    extern void *memset(void *, s32, u32);
    extern void fn_8022D084(void *, void *);

    __begin_critical_region(1);

    if (lbl_803687E8 == 0) {
        memset(lbl_8033DE38, 0, 0x34);
        lbl_803687E8 = 1;
    }

    fn_8022D084(lbl_8033DE38, arg0);

    __end_critical_region(1);
}

void fn_8022D084(void *heap, void *ptr) {
    void fn_8022D0DC(void *, void *, u32);
    void fn_8022D234(void *, void *);
    u32 header;
    u32 size;

    if (ptr != NULL) {
        header = *(u32 *)((u8 *)ptr - 4);
        if ((header & 1) == 0) {
            size = *(u32 *)(header + 8);
        } else {
            size = (*(u32 *)((u8 *)ptr - 8) & ~7u) - 8;
        }
        if (size <= 0x44u) {
            fn_8022D0DC(heap, ptr, size);
        } else {
            fn_8022D234(heap, ptr);
        }
    }
}

void fn_8022D0DC(void *heap, void *ptr, u32 size) {
    typedef struct PoolBlock {
        struct PoolBlock *prev;
        struct PoolBlock *next;
        u32 slotSize;
        void *freeSlots;
        u32 usedSlots;
    } PoolBlock;
    typedef struct {
        PoolBlock *head;
        PoolBlock *tail;
    } SizeClass;

    extern const u32 lbl_80282B60[];
    void fn_8022D234(void **, void *);

    const u32 *limit;
    u32 index;
    u8 *slot;
    SizeClass *sizeClass;
    PoolBlock *block;

    limit = lbl_80282B60;
    index = 0;
    while (size > *limit) {
        limit++;
        index++;
    }

    slot = (u8 *)ptr - 4;
    sizeClass = (SizeClass *)((u8 *)heap + (index * 8 + 4));
    block = *(PoolBlock **)slot;

    if (block->freeSlots == NULL && sizeClass->tail != block) {
        if (sizeClass->head == block) {
            sizeClass->tail = sizeClass->tail->prev;
            sizeClass->head = sizeClass->head->prev;
        } else {
            block->prev->next = block->next;
            block->next->prev = block->prev;
            block->next = sizeClass->tail;
            block->prev = block->next->prev;
            block->prev->next = block;
            block->next->prev = block;
            sizeClass->tail = block;
        }
    }

    *(void **)ptr = block->freeSlots;
    block->freeSlots = slot;

    if (--block->usedSlots == 0) {
        if (sizeClass->tail == block) {
            sizeClass->tail = block->next;
        }
        if (sizeClass->head == block) {
            sizeClass->head = block->prev;
        }

        block->prev->next = block->next;
        block->next->prev = block->prev;

        if (sizeClass->tail == block) {
            sizeClass->tail = NULL;
        }
        if (sizeClass->head == block) {
            sizeClass->head = NULL;
        }

        fn_8022D234((void **)heap, block);
    }
}

void fn_8022CDD0(void *);
#pragma global_optimizer off
#pragma opt_strength_reduction off
void fn_8022D234(void **arg0, void *arg1) {
    u32 *block;
    u32 sizeWord;
    u32 heapRaw;
    u32 size;
    u32 *nextHeader;
    u32 *heap;
    s32 off;
    u32 *listHead;
    u32 *p;
    u32 prevSize;
    u32 *prev;
    u32 *bck;
    u32 sz;
    u32 nextSize;
    u32 *nextBlk;
    u32 nextWord;
    u32 combined;
    u32 maxFree;
    u32 flagWord;
    s32 shouldReturn;
    void **link;

    block = (u32 *)((u8 *)arg1 - 8);
    sizeWord = *(u32 *)((u8 *)arg1 - 8);
    heapRaw = *(u32 *)((u8 *)block + 4);
    size = sizeWord & ~7u;
    *block = sizeWord & ~2u;
    nextHeader = (u32 *)((u8 *)block + size);
    heap = (u32 *)(heapRaw & ~1u);
    *nextHeader = *nextHeader & ~4u;
    *(u32 *)((u8 *)nextHeader - 4) = size;
    off = (heap[3] & ~7u) - 4;
    listHead = *(u32 **)((u8 *)heap + off);
    if (listHead != 0) {
        *(u32 *)((u8 *)block + 8) = *(u32 *)((u8 *)listHead + 8);
        *(u32 *)(*(u32 *)((u8 *)block + 8) + 0xC) = (u32)block;
        *(u32 *)((u8 *)block + 0xC) = *(u32 *)((u8 *)heap + off);
        *(u32 *)(*(u32 *)((u8 *)heap + off) + 8) = (u32)block;
        *(u32 *)((u8 *)heap + off) = (u32)block;
        p = *(u32 **)((u8 *)heap + off);
        if (!(*p & 4)) {
            prevSize = *(u32 *)((u8 *)p - 4);
            if (prevSize & 2) {
                prev = p;
            } else {
                prev = (u32 *)((u8 *)p - prevSize);
                *prev = *prev & 7;
                *prev = *prev | ((prevSize + (*p & ~7u)) & ~7u);
                if (!(*prev & 2)) {
                    combined = prevSize + (*p & ~7u);
                    *(u32 *)((u8 *)prev + combined - 4) = combined;
                }
                listHead = *(u32 **)((u8 *)heap + off);
                if (listHead == p) {
                    *(u32 *)((u8 *)heap + off) = *(u32 *)((u8 *)listHead + 0xC);
                }
                *(u32 *)(*(u32 *)((u8 *)p + 0xC) + 8) = *(u32 *)((u8 *)p + 8);
                bck = *(u32 **)((u8 *)p + 0xC);
                *(u32 *)(*(u32 *)((u8 *)bck + 8) + 0xC) = (u32)bck;
            }
        } else {
            prev = p;
        }
        *(u32 *)((u8 *)heap + off) = (u32)prev;
        p = *(u32 **)((u8 *)heap + off);
        sz = *p;
        nextSize = sz & ~7u;
        nextBlk = (u32 *)((u8 *)p + nextSize);
        nextWord = *nextBlk;
        if (!(nextWord & 2)) {
            *p = sz & 7;
            combined = nextSize + (nextWord & ~7u);
            *p = *p | (combined & ~7u);
            if (!(*p & 2)) {
                *(u32 *)((u8 *)p + combined - 4) = combined;
            }
            if (!(*p & 2)) {
                *(u32 *)((u8 *)p + combined) = *(u32 *)((u8 *)p + combined) & ~4u;
            } else {
                *(u32 *)((u8 *)p + combined) = *(u32 *)((u8 *)p + combined) | 4;
            }
            listHead = *(u32 **)((u8 *)heap + off);
            if (listHead == nextBlk) {
                *(u32 *)((u8 *)heap + off) = *(u32 *)((u8 *)listHead + 0xC);
            }
            if (*(u32 **)((u8 *)heap + off) == nextBlk) {
                *(u32 *)((u8 *)heap + off) = 0;
            }
            *(u32 *)(*(u32 *)((u8 *)nextBlk + 0xC) + 8) = *(u32 *)((u8 *)nextBlk + 8);
            *(u32 *)(*(u32 *)((u8 *)nextBlk + 8) + 0xC) = *(u32 *)((u8 *)nextBlk + 0xC);
        }
    } else {
        *(u32 *)((u8 *)heap + off) = (u32)block;
        *(u32 *)((u8 *)block + 8) = (u32)block;
        *(u32 *)((u8 *)block + 0xC) = (u32)block;
    }
    maxFree = **(u32 **)((u8 *)heap + off) & ~7u;
    if (*(u32 *)((u8 *)heap + 8) < maxFree) {
        *(u32 *)((u8 *)heap + 8) = maxFree;
    }
    flagWord = *(u32 *)((u8 *)heap + 0x10);
    shouldReturn = 0;
    if (!(flagWord & 2) && ((flagWord & ~7u) == ((*(u32 *)((u8 *)heap + 0xC) & ~7u) - 0x18))) {
        shouldReturn = 1;
    }
    if (shouldReturn != 0) {
        link = *(void ***)((u8 *)heap + 4);
        if ((u32 *)link == heap) {
            link = 0;
        }
        if (*arg0 == heap) {
            *arg0 = link;
        }
        if (link != 0) {
            *link = *(void **)heap;
            *(void **)((u8 *)*link + 4) = link;
        }
        *(u32 *)((u8 *)heap + 4) = 0;
        *(u32 *)heap = 0;
        fn_8022CDD0(heap);
    }
}
#pragma opt_strength_reduction reset
#pragma global_optimizer reset
s32 __flush_all(void) {
    s32 fflush(void *);
    extern char __files[];
    s32 ret;
    char *p;

    ret = 0;
    for (p = __files; p != NULL; p = *(char **)(p + 0x4c)) {
        if (((*(u16 *)(p + 4) >> 6) & 7) != 0 && fflush(p) != 0) {
            ret = -1;
        }
    }
    return ret;
}

void __close_all(void) {
    typedef struct Stream {
        u8 pad0[4];
        u16 modePrefix : 7;
        u16 mode : 3;
        u16 modeSuffix : 6;
        u8 pad6[6];
        u8 dynamicallyAllocated;
        u8 padD[0x4C - 0xD];
        struct Stream *next;
    } Stream;

    extern char __files[];
    void __begin_critical_region(s32);
    void __end_critical_region(s32);
    s32 fn_802312B0(void *);
    void fn_8022D014(void *);

    Stream *stream;
    Stream *closed;

    stream = (Stream *)__files;
    __begin_critical_region(2);

    while (stream != NULL) {
        if (stream->mode != 0) {
            fn_802312B0(stream);
        }

        closed = stream;
        stream = closed->next;

        if (closed->dynamicallyAllocated != 0) {
            fn_8022D014(closed);
        } else {
            closed->mode = 3;
            if (stream != NULL && stream->dynamicallyAllocated != 0) {
                closed->next = NULL;
            }
        }
    }

    __end_critical_region(2);
}

f64 fn_802380A8(f64, f64);
f64 fn_8022D5E0(void *arg0)
{
    extern f64 lbl_8036BDC8;
    extern f64 lbl_8036BDD0;
    extern f64 lbl_8036BDD8;
    extern f32 lbl_8036706C;
    extern f32 lbl_80367068;
    u8 *p = (u8 *)arg0;
    f64 sign;
    u8 kind;

    if (p[4] == 0) {
        if ((s8)p[0] == 0) {
            sign = lbl_8036BDD0;
        } else {
            sign = lbl_8036BDD8;
        }
        return fn_802380A8(lbl_8036BDC8, sign);
    }
    kind = p[5];
    if (kind == 0x49) {
        if ((s8)p[0] == 0) {
            sign = lbl_8036BDD0;
        } else {
            sign = lbl_8036BDD8;
        }
        return fn_802380A8((f64)lbl_8036706C, sign);
    }
    if (kind >= 0x4E) {
        if (kind == 0x4E) {
            if ((s8)p[0] == 0) {
                sign = lbl_8036BDD0;
            } else {
                sign = lbl_8036BDD8;
            }
            return fn_802380A8((f64)lbl_80367068, sign);
        }
    } else if (kind == 0x30) {
        /* digit path */
    }
    return 0.0;
}

void fn_8022E660(void *format, RuntimeDecimal *arg1, f64 x) {
    void fn_8022E804(void *, f64);
    RuntimeDecimal *d = arg1;
    s16 requested = *(s16 *)((u8 *)format + 2);
    s32 precision;
    s32 i;
    fn_8022E804(d, x);
    if (d->digits[0] <= 9) {
        if ((s16)requested > 36) requested = 36;
        precision = (s16)requested;
        if (precision > 0 && precision < d->length) {
            s32 round;
            u8 *p;
            if (d->digits[precision] > 5) round = 1;
            else if (d->digits[precision] < 5) round = -1;
            else {
                u8 *end = d->digits + d->length;
                p = d->digits + precision + 1;
                while (p < end) {
                    if (*p != 0) { round = 1; goto rounded; }
                    ++p;
                }
                if (d->digits[precision-1] & 1) round = 1;
                else round = -1;
            }
rounded:
            d->length = precision;
            if (round >= 0) {
                p = d->digits + (precision - 1);
                for (;;) {
                    if (*p < 9) { ++*p; break; }
                    if (p == d->digits) {
                        *p = 1;
                        ++d->exponent;
                        break;
                    }
                    *p-- = 0;
                }
            }
        }
        while (d->length < precision) d->digits[d->length++] = 0;
        d->exponent -= d->length - 1;
        for (i=0; i<d->length; i++) d->digits[i] += '0';
    }
}

#pragma use_lmw_stmw on
