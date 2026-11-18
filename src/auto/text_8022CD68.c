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
void fn_8022E804(void *dst, f64 x) {
    u64 __div2u(u32, u32, u32, u32);
    u64 __mod2u(u32, u32, u32, u32);
    u64 fn_8022CC2C(f64);
    void fn_8022F1C0(void *, s32);
    void fn_80230944(void *, void *, void *);
    f64 fn_802382EC(s32 *, f64);
    f64 fn_80238378(s32, f64);
    void fn_8023853C(f64 *);
    extern f64 lbl_8036BDC8;
    u8 dig[0x2C];
    u8 sp38[0x2C];
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    s8 sign;
    u8 *digp;
    s32 zero;
    u32 hi;
    u32 ul;
    f64 f31;
    s32 hx;
    s32 clas;
    s32 clas2;
    s32 m;
    u32 xbits;
    s32 n;
    s32 j;
    s32 k;
    u32 xb;
    u32 lo;
    u64 uq;
    u8 *p;
    u8 *q;
    u8 t;
    u8 idx;
    s32 expadj;
    s8 ch;

    sp8 = x;
    sign = (s8)((*(u32 *)&sp8) >> 31);
    if (lbl_8036BDC8 == x) {
        *(s8 *)dst = sign;
        *(s16 *)((u8 *)dst + 2) = 0;
        ((u8 *)dst)[4] = 1;
        ((u8 *)dst)[5] = 0;
        return;
    }
    sp28 = x;
    hx = *(s32 *)&sp28;
    switch (hx & 0x7FF00000) {
    case 0x7FF00000:
        if ((hx & 0xFFFFF) || *((s32 *)&sp28 + 1) != 0) {
            clas = 1;
        } else {
            clas = 2;
        }
        break;
    case 0:
        if ((hx & 0xFFFFF) || *((s32 *)&sp28 + 1) != 0) {
            clas = 5;
        } else {
            clas = 3;
        }
        break;
    default:
        clas = 4;
        break;
    }
    if (clas <= 2) {
        *(s8 *)dst = sign;
        *(s16 *)((u8 *)dst + 2) = 0;
        ((u8 *)dst)[4] = 1;
        sp20 = sp8;
        hx = *(s32 *)&sp20;
        switch (hx & 0x7FF00000) {
        case 0x7FF00000:
            if ((hx & 0xFFFFF) || *((s32 *)&sp20 + 1) != 0) {
                clas2 = 1;
            } else {
                clas2 = 2;
            }
            break;
        case 0:
            if ((hx & 0xFFFFF) || *((s32 *)&sp20 + 1) != 0) {
                clas2 = 5;
            } else {
                clas2 = 3;
            }
            break;
        default:
            clas2 = 4;
            break;
        }
        ch = 0x49;
        if (clas2 == 1) {
            ch = 0x4E;
        }
        ((u8 *)dst)[5] = ch;
        return;
    }
    if ((s8)sign != 0) {
        sp8 = -x;
    }
    f31 = fn_802382EC((s32 *)&sp10, sp8);
    sp18 = f31;
    lo = *((u32 *)&sp18 + 1);
    if (lo != 0) {
        m = 0x10;
        xbits = 0xFFFFU;
        n = 0;
        j = 0x20;
        k = m;
        while (j != 0) {
            if ((lo & xbits) == 0) {
                n += k;
                lo >>= k;
                j -= k;
            } else if (xbits == 1) {
                break;
            }
            if (m > 1) {
                m = (s32)(((u32)m >> 31) + m) >> 1;
            }
            if (xbits > 1) {
                xbits >>= m;
                k -= m;
            }
        }
    } else {
        m = 0x10;
        n = 0;
        k = m;
        xbits = (*(u32 *)&sp18) | 0x100000;
        xb = 0xFFFFU;
        j = 0x20;
        while (j != 0) {
            if ((xbits & xb) == 0) {
                n += k;
                xbits >>= k;
                j -= k;
            } else if (xb == 1) {
                break;
            }
            if (m > 1) {
                m = (s32)(((u32)m >> 31) + m) >> 1;
            }
            if (xb > 1) {
                xb >>= m;
                k -= m;
            }
        }
        n += 0x20;
    }
    expadj = 0x35 - n;
    ul = (u32)expadj;
    fn_8022F1C0(sp38, *(s32 *)&sp10 - (s32)ul);
    fn_80238378((s32)ul, f31);
    fn_8023853C(&sp30);
    uq = fn_8022CC2C(sp30);
    zero = *(s32 *)&lbl_8036BDC8;
    hi = (u32)(uq >> 32);
    ul = (u32)uq;
    dig[0] = (u8)zero;
    if (((ul ^ (u32)zero) | (hi ^ (u32)zero)) == 0) {
        *(s16 *)(dig + 2) = (s16)zero;
        dig[4] = 1;
        dig[5] = (u8)zero;
    } else {
        dig[4] = (u8)zero;
        digp = dig;
        while (((ul ^ (u32)zero) | (hi ^ (u32)zero)) != 0) {
            uq = __mod2u(hi, ul, 0, 10);
            idx = dig[4];
            dig[4] = idx + 1;
            digp[idx + 5] = (u8)(u32)uq;
            uq = __div2u(hi, ul, 0, 10);
            ul = (u32)uq;
            hi = (u32)(uq >> 32);
        }
        p = dig + 5;
        q = dig + dig[4] + 5;
        while (p < q) {
            t = *p;
            *p = *q;
            p++;
            *q = t;
            q--;
        }
        *(s16 *)(dig + 2) = dig[4] - 1;
    }
    fn_80230944(dst, dig, sp38);
    *(s8 *)dst = sign;
}

void fn_8022EBB8(RuntimeDecimal *out,RuntimeDecimal *left,RuntimeDecimal *right){
s32 offset,n,len,index,round;u8 *base,*p,*rbase,*tail,*q,*borrow,*end;u8 removed;
{u32 *dst=(u32*)out,*src=(u32*)left;dst[0]=src[0];dst[1]=src[1];dst[2]=src[2];dst[3]=src[3];dst[4]=src[4];dst[5]=src[5];dst[6]=src[6];dst[7]=src[7];dst[8]=src[8];dst[9]=src[9];*(u16*)(dst+10)=*(u16*)(src+10);}
if(!right->digits[0])return;
n=out->length;if(n<right->length)n=right->length;
offset=out->exponent-right->exponent;n+=offset;if(n>36)n=36;
while(out->length<n){out->digits[out->length++]=0;}
base=out->digits;p=base+n;len=right->length+offset;if(len<n)p=base+len;
rbase=right->digits;q=rbase+(p-base-offset);tail=q;
while(p>base&&q>rbase){
--p;--q;
if(*p<*q){
borrow=p-1;while(*borrow==0)--borrow;
for(;borrow!=p;borrow++){--*borrow;borrow[1]+=10;}
}
*p-=*q;
}
index=tail-rbase;
if(index<right->length){
round=0;
if(*tail<5)round=1;
else if(*tail==5){
q=tail+1;end=right->digits+right->length;
for(;q<end;q++){if(*q)goto trim;}
p=base+index+offset-1;
if(*p&1)round=1;
}
if(round){
if(*p<1){borrow=p-1;while(*borrow==0)--borrow;for(;borrow!=p;borrow++){--*borrow;borrow[1]+=10;}}
--*p;
}
}
trim:
p=base;while(*p==0)++p;
if(p>base){removed=p-base;out->exponent-=removed;end=base+out->length;
for(;p<end;p++,base++)*base=*p;
out->length-=removed;
}
base=out->digits;p=base+out->length;
while(p>base){if(*--p)break;}
out->length=p-base+1;
}

extern s32 D_8022EF64;
s32 fn_8022F0B4(RuntimeDecimal *a, RuntimeDecimal *b) {
    s32 blen,alen,i,n;
    if(a->digits[0]==0) return b->digits[0]==0;
    if(b->digits[0]==0) return a->digits[0]==0;
    if(a->exponent==b->exponent) {
        alen=a->length;
        blen=b->length;
        n=alen;
        if(alen>blen) n=blen;
        for(i=0;i<n;i++) {
            if(a->digits[i]!=b->digits[i]) return 0;
        }
        if(n==alen) {
            for(;i<blen;i++) if(b->digits[i]!=0) return 0;
        } else {
            for(;i<alen;i++) if(a->digits[i]!=0) return 0;
        }
        return 1;
    }
    return 0;
}

void fn_8022F1C0(RuntimeDecimal *d,s32 code) { extern char lbl_80282B78[]; void fn_80230944(void *,void *,void *); RuntimeDecimal half, temp; s32 i; char *s; u8 *p; switch(code){
case -64: d->exponent=-20; d->sign=0; s=lbl_80282B78+37; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round0; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round0: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -53: d->exponent=-16; d->sign=0; s=lbl_80282B78+83; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round1; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round1: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -32: d->exponent=-10; d->sign=0; s=lbl_80282B78+122; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round2; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round2: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -16: d->exponent=-5; d->sign=0; s=lbl_80282B78+146; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round3; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round3: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -8: d->exponent=-3; d->sign=0; s=lbl_80282B78+159; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round4; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round4: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -7: d->exponent=-3; d->sign=0; s=lbl_80282B78+166; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round5; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round5: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -6: d->exponent=-2; d->sign=0; s=lbl_80282B78+172; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round6; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round6: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -5: d->exponent=-2; d->sign=0; s=lbl_80282B78+178; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round7; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round7: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -4: d->exponent=-2; d->sign=0; s=lbl_80282B78+183; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round8; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round8: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -3: d->exponent=-1; d->sign=0; s=lbl_80282B78+187; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round9; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round9: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -2: d->exponent=-1; d->sign=0; s=lbl_80282B78+191; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round10; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round10: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case -1: d->exponent=-1; d->sign=0; s=lbl_80282B78+194; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round11; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round11: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 0: d->exponent=0; d->sign=0; s=lbl_80282B78+196; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round12; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round12: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 1: d->exponent=0; d->sign=0; s=lbl_80282B78+198; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round13; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round13: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 2: d->exponent=0; d->sign=0; s=lbl_80282B78+200; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round14; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round14: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 3: d->exponent=0; d->sign=0; s=lbl_80282B78+202; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round15; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round15: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 4: d->exponent=1; d->sign=0; s=lbl_80282B78+204; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round16; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round16: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 5: d->exponent=1; d->sign=0; s=lbl_80282B78+207; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round17; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round17: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 6: d->exponent=1; d->sign=0; s=lbl_80282B78+210; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round18; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round18: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 7: d->exponent=2; d->sign=0; s=lbl_80282B78+213; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round19; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round19: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;
case 8: d->exponent=2; d->sign=0; s=lbl_80282B78+217; for(i=0;i<36 && *s;i++) d->digits[i]=*s++-'0';
d->length=i;
if(!*s) goto done;
if(*s<5) goto done;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round20; ++t; } if(!(d->digits[i-1]&1)) goto done; }
round20: {u8 *base=d->digits; p=base+(d->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++d->exponent;break;} *p=0; }}
 break;default: fn_8022F1C0(&half,code/2); fn_80230944(d,&half,&half); if(code&1){temp=*d; if(code>0){half.exponent=0;half.sign=0;s=lbl_80282B78+198;for(i=0;i<36 && *s;i++) (&half)->digits[i]=*s++-'0';
(&half)->length=i;
if(!*s) goto multiply;
if(*s<5) goto multiply;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round21; ++t; } if(!((&half)->digits[i-1]&1)) goto multiply; }
round21: {u8 *base=(&half)->digits; p=base+((&half)->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++(&half)->exponent;break;} *p=0; }}
}else{half.sign=0;half.exponent=-1;s=lbl_80282B78+194;for(i=0;i<36 && *s;i++) (&half)->digits[i]=*s++-'0';
(&half)->length=i;
if(!*s) goto multiply;
if(*s<5) goto multiply;
if(*s<=5) { char *t=s+1; while(*t) { if(*t!='0') goto round22; ++t; } if(!((&half)->digits[i-1]&1)) goto multiply; }
round22: {u8 *base=(&half)->digits; p=base+((&half)->length-1);
for(;;--p) { if(*p<9){++*p;break;} if(p==base){*p=1;++(&half)->exponent;break;} *p=0; }}
} multiply: fn_80230944(d,&temp,&half);}break;} done:; }

#pragma use_lmw_stmw on
void fn_80230944(u8 *dest, u8 *a, u8 *b) {
    u8 sp8[0x54];
    u8 *out;
    u8 *end;
    u8 dig_b = b[4];
    u8 dig_a = a[4];
    s32 pos = dig_a + (dig_b - 1);
    u32 acc = 0;
    s32 i, j, n, n8;
    u8 *pa, *pb;
    u32 prod;
    u8 t0, t1;
    s32 c;
    u8 *p, *base;
    u8 d;

    out = sp8 + (pos + 1);
    dest[0] = 0;
    end = out;

    while (pos > 0) {
        j = dig_b - 1;
        i = (pos - j) - 1;
        if (i < 0) {
            i = 0;
            j = pos - 1;
        }
        n = j + 1;
        {
            s32 lim = dig_a - i;
            pa = a + i + 5;
            pb = b + j + 5;
            if (n > lim) {
                n = lim;
            }
        }
        if (n > 0) {
            n8 = (u32)n >> 3;
            if (n8 != 0) {
                do {
                    t0 = pa[0]; t1 = pb[0]; prod = t0 * t1; acc += prod;
                    t0 = pa[1]; t1 = pb[-1]; prod = t0 * t1; acc += prod;
                    t0 = pa[2]; t1 = pb[-2]; prod = t0 * t1; acc += prod;
                    t0 = pa[3]; t1 = pb[-3]; prod = t0 * t1; acc += prod;
                    t0 = pa[4]; t1 = pb[-4]; prod = t0 * t1; acc += prod;
                    t0 = pa[5]; t1 = pb[-5]; prod = t0 * t1; acc += prod;
                    t0 = pa[6]; t1 = pb[-6]; prod = t0 * t1; acc += prod;
                    t0 = pa[7]; t1 = pb[-7];
                    pa += 8; pb -= 8;
                    prod = t0 * t1; acc += prod;
                } while (--n8);
            }
            n &= 7;
            if (n != 0) {
                do {
                    t0 = *pa; pa++;
                    t1 = *pb; pb--;
                    acc += t0 * t1;
                } while (--n);
            }
        }
        {
            u32 magic = acc * 0xCCCCCCCDU;
            pos--;
            d = (u8)(acc - ((magic >> 3) * 10));
            acc = magic >> 3;
            *--out = d;
        }
    }

    *(s16 *)(dest + 2) = *(s16 *)(a + 2) + *(s16 *)(b + 2);
    if (acc != 0) {
        *--out = (u8)acc;
        (*(s16 *)(dest + 2))++;
    }

    for (c = 0; c < 0x24 && out < end; c++, out++) {
        dest[c + 5] = *out;
    }
    dest[4] = (u8)c;

    if (out < end) {
        d = *out;
        if (d >= 5) {
            if (d != 5) {
                goto round_up;
            }
            p = out + 1;
            n = (s32)(end - p);
            if (p < end) {
                do {
                    if (*p != 0) {
                        goto round_up;
                    }
                    p++;
                } while (--n);
            }
            if ((out[-1] & 1) == 0) {
                goto done;
            }
        round_up:
            base = dest + 5;
            p = base + dest[4] - 1;
            for (;;) {
                if (*p < 9) {
                    (*p)++;
                    break;
                }
                if (p == base) {
                    *p = 1;
                    (*(s16 *)(dest + 2))++;
                    break;
                }
                *p = 0;
                p--;
            }
        }
    }
done:
    ;
}
#pragma use_lmw_stmw reset

s32 fn_80230BBC(s32 arg0) {
    s32 temp_r4;

    temp_r4 = arg0 >> 0x1F;
    return (temp_r4 ^ arg0) - temp_r4;
}

s32 Abs(s32 arg0) {
    s32 temp_r4;

    temp_r4 = arg0 >> 0x1F;
    return (temp_r4 ^ arg0) - temp_r4;
}

/* Write any pending FILE buffer bytes via write_proc, then reset buffer pointers. */
s32 __flush_buffer(void *stream, s32 *nbytes) {
    typedef struct {
        void *handle;       /* 0x00 */
        u8 pad0[0x14];
        u32 position;       /* 0x18 file offset */
        u32 buffer;         /* 0x1C */
        u32 buffer_end;     /* 0x20 */
        u32 buffer_ptr;     /* 0x24 */
        u32 buffer_length;  /* 0x28 */
        u32 buffer_alignment; /* 0x2C */
        u8 pad1[4];
        u32 saved_position; /* 0x34 */
        u8 pad2[8];
        s32 (*write_proc)(void *, u32, u32 *, u32);  /* 0x40 */
        u8 pad3[4];
        u32 ref_con;        /* 0x48 */
    } FILE;
    FILE *file = (FILE *)stream;
    u32 n = file->buffer_ptr - file->buffer;
    s32 result;

    if (n != 0) {
        file->buffer_length = n;
        result = file->write_proc(file->handle, file->buffer, &file->buffer_length, file->ref_con);
        if (nbytes != NULL) {
            *nbytes = file->buffer_length;
        }
        if (result != 0) {
            return result;
        }
        file->position += file->buffer_length;
    }
    file->buffer_ptr = file->buffer;
    file->buffer_length = file->buffer_end;
    file->buffer_length = file->buffer_length - (file->position & file->buffer_alignment);
    file->saved_position = file->position;
    return 0;
}

void __prep_buffer(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x20);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) - (M2C_FIELD(arg0, s32 *, 0x18) & M2C_FIELD(arg0, s32 *, 0x2C)));
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
}

void __end_critical_region(void) {

}

void __begin_critical_region(void) {

}

void __kill_critical_regions(void) {

}

s32 fn_80230CE0(s32 arg0) {
 extern u16 lbl_8029E9A8[256];
 if (arg0 == -1) return -1;
 return ((u8 *)lbl_8029E9A8)[(u8)arg0];
}

u32 fwrite(const void *ptr, u32 size, u32 count, void *stream)
{
    extern void __begin_critical_region(s32);
    extern void __end_critical_region(s32);
    extern u32 __fwrite(const void *, u32, u32, void *);

    u32 result;

    __begin_critical_region(2);

    result = __fwrite(ptr, size, count, stream);

    __end_critical_region(2);

    return result;
}

char *fn_8023108C(s32 value, char *p, u32 base) {
 s32 strlen(const char *);
 s8 negative;
 s32 length;
 s32 digit;
 s32 i;
 char temp;
 s32 j;
 char *buffer=p;
 negative=0; length=0;
 if(value<0) {value=-value; negative=1; if(p!=buffer) p=buffer;}
 do {digit=(u32)value%base; if(digit>9) {length++; *p++=digit+0x37;} else {length++; *p++=digit+0x30;} value=(u32)value/base;} while(value!=0);
 if(negative) {buffer[length]='-'; length++;}
 buffer[length]=(i=0);
 j=strlen(buffer)-1;
 while(i<j) {temp=buffer[i]; buffer[i]=buffer[j]; buffer[j]=temp; i++; j--;}
 return buffer;
}

int fflush(void *file) {
    /* Flush a FILE's buffer to the device, or flush every open file when file is NULL. */
    s32 __flush_buffer(void *, s32 *);
    s32 __flush_all();
    s32 fn_80231748(void *);
    typedef struct {
        u8 pad[4];
        u16 pre:7;
        u16 ioMode:3;
        u16 rest:6;
    } FileWord4;
    typedef struct {
        u8 pad[4];
        u8 pre:2;
        u8 state:3;
        u8 rest:3;
    } FileByte4;
    typedef struct {
        u8 pad[8];
        u8 bufMode:3;
        u8 rest:4;
        u8 flag:1;
    } FileByte8;
    FileWord4 *w4 = (FileWord4 *)file;
    FileByte4 *b4 = (FileByte4 *)file;
    FileByte8 *b8 = (FileByte8 *)file;
    s32 pos;

    if (file == NULL) {
        return __flush_all();
    }
    if (((u8) M2C_FIELD(file, u8 *, 0xA) != 0) || (w4->ioMode == 0)) {
        return -1;
    }
    if (b4->state == 1) {
        return 0;
    }
    if (b8->bufMode >= 3U) {
        b8->bufMode = 2;
    }
    if (b8->bufMode == 2) {
        M2C_FIELD(file, s32 *, 0x28) = 0;
    }
    if (b8->bufMode != 1) {
        b8->bufMode = 0;
        return 0;
    }
    if (w4->ioMode != 1) {
        pos = 0;
    } else {
        pos = fn_80231748(file);
    }
    if (__flush_buffer(file, 0) != 0) {
        M2C_FIELD(file, u8 *, 0xA) = 1U;
        M2C_FIELD(file, s32 *, 0x28) = 0;
        return -1;
    }
    b8->bufMode = 0;
    M2C_FIELD(file, s32 *, 0x18) = pos;
    M2C_FIELD(file, s32 *, 0x28) = 0;
    return 0;
}

s32 fn_802312B0(void *arg0) {
    s32 __flush_buffer(void *, s32 *);
    M2C_UNK fn_8022D014(s32);
    s32 __flush_all();
    s32 fn_80231748(void *);
    typedef struct {
        u8 pad[4];
        u16 pre:7;
        u16 mode:3;
        u16 rest:6;
    } S4;
    typedef struct {
        u8 pad[4];
        u8 pre:2;
        u8 modeB:3;
        u8 rest:3;
    } B4;
    typedef struct {
        u8 pad[8];
        u8 mode:3;
        u8 flag:1;
        u8 rest:4;
    } B8;
    S4 *s4 = (S4 *)arg0;
    B4 *b4 = (B4 *)arg0;
    B8 *b8 = (B8 *)arg0;
    s32 temp_r30;
    register s32 var_r29;
    s32 var_r30;
    s32 var_r3;

    if (arg0 == NULL) {
        return -1;
    }
    if (s4->mode == 0) {
        return 0;
    }
    if (arg0 == NULL) {
        var_r29 = __flush_all();
    } else if (((u8) M2C_FIELD(arg0, u8 *, 0xA) != 0) || (s4->mode == 0)) {
        var_r29 = -1;
    } else if (b4->modeB == 1) {
        var_r29 = 0;
    } else {
        if (b8->mode >= 3U) {
            b8->mode = 2;
        }
        if (b8->mode == 2) {
            M2C_FIELD(arg0, s32 *, 0x28) = 0;
        }
        if (b8->mode != 1) {
            var_r29 = 0;
            b8->mode = var_r29;
        } else {
            if (s4->mode != 1) {
                var_r30 = 0;
            } else {
                var_r30 = fn_80231748(arg0);
            }
            if (__flush_buffer(arg0, 0) != 0) {
                M2C_FIELD(arg0, u8 *, 0xA) = 1U;
                var_r29 = -1;
                M2C_FIELD(arg0, s32 *, 0x28) = 0;
            } else {
                var_r29 = 0;
                b8->mode = var_r29;
                M2C_FIELD(arg0, s32 *, 0x18) = var_r30;
                M2C_FIELD(arg0, s32 *, 0x28) = var_r29;
            }
        }
    }
    temp_r30 = M2C_FIELD(arg0, s32 (**)(s32), 0x44)(M2C_FIELD(arg0, s32 *, 0));
    s4->mode = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    if (b8->flag) {
        fn_8022D014(M2C_FIELD(arg0, s32 *, 0x1C));
    }
    var_r3 = 0;
    if ((var_r29 != 0) || (temp_r30 != 0)) {
        var_r3 = 1;
    }
    return (s32) (-var_r3 | var_r3) >> 0x1F;
}

extern s32 fn_802314D8(s32, s32, s32);
s32 fseek(s32 arg0, s32 arg1, s32 arg2) {
extern void __begin_critical_region(s32);
extern void __end_critical_region(s32);
s32 result;
__begin_critical_region(2);
result = fn_802314D8(arg0, arg1, arg2);
__end_critical_region(2);
return result;
}

s32 fn_802314D8(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 errno;
    s32 __flush_buffer(void *, s32 *);
    typedef struct {
        u8 pad[4];
        u16 pre:7;
        u16 mode:3;
        u16 rest:6;
    } S4;
    typedef struct {
        u8 pad[4];
        u8 pre:2;
        u8 modeB:3;
        u8 rest:3;
    } B4;
    typedef struct {
        u8 pad[8];
        u8 mode:3;
        u8 rest:5;
    } B8;
    S4 *s4;
    B4 *b4;
    B8 *b8;
    s32 offset;
    s32 whence;
    s32 i;
    s32 result;
    u8 *p;
    s32 n;
    s32 adj;
    s32 (*seek_proc)(s32, s32 *, s32, s32);

    s4 = (S4 *)arg0;
    b4 = (B4 *)arg0;
    b8 = (B8 *)arg0;
    whence = arg2;
    offset = arg1;

    if (s4->mode != 1 || M2C_FIELD(arg0, u8 *, 0xA) != 0) {
        errno = 0x28;
        return -1;
    }

    if (b8->mode == 1) {
        if (__flush_buffer((void *)arg0, 0) != 0) {
            M2C_FIELD(arg0, u8 *, 0xA) = 1;
            M2C_FIELD(arg0, s32 *, 0x28) = 0;
            errno = 0x28;
            return -1;
        }
    }

    if (whence == 1) {
        p = 0;
        whence = 0;
        adj = 0;
        if ((s4->mode != 1 && s4->mode != 2) || M2C_FIELD(arg0, u8 *, 0xA) != 0) {
            result = -1;
            errno = 0x28;
        } else if (b8->mode == 0) {
            result = M2C_FIELD(arg0, s32 *, 0x18);
        } else {
            p = (u8 *)M2C_FIELD(arg0, void **, 0x1C);
            n = (u8 *)M2C_FIELD(arg0, void **, 0x24) - p;
            result = M2C_FIELD(arg0, s32 *, 0x34) + n;
            if (b8->mode >= 3U) {
                adj = (s32)b8->mode - 2;
                result -= adj;
            }
            if (((*((u8 *)arg0 + 5) >> 3) & 1) == 0) {
                for (i = n - adj; i != 0; i--) {
                    if (*p++ == '\n') {
                        result++;
                    }
                }
            }
        }
        offset += result;
    }

    if (whence != 2 && b4->modeB != 3 && (b8->mode == 2 || b8->mode == 3)) {
        if ((u32)offset >= (u32)M2C_FIELD(arg0, s32 *, 0x18) ||
            (u32)offset < (u32)M2C_FIELD(arg0, s32 *, 0x34)) {
            b8->mode = 0;
        } else {
            M2C_FIELD(arg0, void **, 0x24) =
                (u8 *)M2C_FIELD(arg0, void **, 0x1C) + (offset - M2C_FIELD(arg0, s32 *, 0x34));
            M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s32 *, 0x18) - offset;
            b8->mode = 2;
        }
    } else {
        b8->mode = 0;
    }

    if (b8->mode == 0) {
        seek_proc = (s32 (*)(s32, s32 *, s32, s32))M2C_FIELD(arg0, s32 *, 0x38);
        if (seek_proc != NULL) {
            if (seek_proc(M2C_FIELD(arg0, s32 *, 0), &offset, whence, M2C_FIELD(arg0, s32 *, 0x48)) != 0) {
                M2C_FIELD(arg0, u8 *, 0xA) = 1;
                M2C_FIELD(arg0, s32 *, 0x28) = 0;
                errno = 0x28;
                return -1;
            }
        }
        M2C_FIELD(arg0, u8 *, 0x9) = 0;
        M2C_FIELD(arg0, s32 *, 0x18) = offset;
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
    }
    return 0;
}

s32 fn_80231748(void *arg0) {
 void __begin_critical_region(s32);
 void __end_critical_region(s32);
 extern s32 errno;
 u8 *file=arg0;
 s32 result;
 u8 *p;
 s32 n;
 u32 mode;
 u32 state;
 s32 count;
 s32 adj;
 __begin_critical_region(2);
 adj=0;
 mode=(*(u16 *)(file+4)>>6)&7;
 if((mode!=1 && mode!=2)||file[10]!=0) { errno=40; result=-1; }
 else {
 state=(file[8]>>5)&7;
 if(state==0) result=*(s32 *)(file+0x18);
 else {
 p=*(u8 **)(file+0x1c);
 n=*(u8 **)(file+0x24)-p;
 result=n+*(s32 *)(file+0x34);
 if(state>=3) {adj=state-2; result-=adj;}
 if(!((file[5]>>3)&1)) { count=n-adj; while(count!=0) {if(*p++==10) result++; count--;}}
 }
 }
 __end_critical_region(2);
 return result;
}

u32 wcstombs(char *arg0, const u16 *src, u32 arg2) {
    char *Str_CopyPad(char *,const char *,s32);
    extern u32 lbl_8036BDF8;
    char buffer[3];
    u32 prefixes;
    s32 count;
    char *dest;
    u32 limit;
    const u16 *p;
    u32 total;
    u32 result;

    register u32 ch;
    char *out;
    dest=arg0;
    limit=arg2;
    total=0;
    if(dest==0 || src==0) return 0;
    p=src;
    while((result=total)<=limit) {
        ch=*p;
        if(ch==0) {
            dest[total]=0;
            break;
        }
        p++;
        prefixes=lbl_8036BDF8;
        if(ch<0x80) count=1;
        else if(ch<0x800) count=2;
        else count=3;
        out=buffer+count;
        switch(count) {
        case 3:
            *--out=(ch&0x3F)|0x80;
            ch=(u16)ch>>6;
        case 2:
            *--out=(ch&0x3F)|0x80;
            ch=(u16)ch>>6;
        case 1:
            *--out=ch|((u8*)&prefixes)[count];
        }
        if(total+count>limit) break;
        Str_CopyPad(dest+total,buffer,count);
        total+=count;
    }
    return result;
}

int fn_80231944(const char *str1, const char *str2, int count) {
 const u8 *s1=(const u8*)str1-1;
 const u8 *s2=(const u8*)str2-1;
 int n=count+1;
 while (--n != 0) {
 if (*++s1 != *++s2) return *s1 < *s2 ? -1 : 1;
 }
 return 0;
}

void *__memrchr(void *arg0, int arg1, u32 arg2) {
    u32 value = (u8)arg1;
    u8 *ptr = (u8 *)arg0 + arg2;
    ++arg2;
    while (--arg2 != 0) {
        if (*--ptr == value) return ptr;
    }
    return NULL;
}

void *memchr(const void *ptr, int value, unsigned long count) {
    u32 c = (u8)value;
    const u8 *p = (const u8 *)ptr - 1;
    ++count;
    while (--count != 0) {
        if (*++p == c) return (void *)p;
    }
    return NULL;
}

void *memmove(void *dst, const void *src, u32 n) {
    void fn_80231B60(void *, const void *, u32);
    void fn_80231AB4(void *, const void *, u32);
    void fn_80231CC8(void *, const void *, u32);
    void fn_80231C20(void *, const void *, u32);
    const u8 *s;
    u8 *d;
    s32 rev;

    rev = (u32)src < (u32)dst;
    if (n >= 0x20U) {
        if (((u32)dst ^ (u32)src) & 3) {
            if (rev == 0) {
                fn_80231B60(dst, src, n);
            } else {
                fn_80231AB4(dst, src, n);
            }
        } else if (rev == 0) {
            fn_80231CC8(dst, src, n);
        } else {
            fn_80231C20(dst, src, n);
        }
        return dst;
    }
    if (rev == 0) {
        s = (const u8 *)src - 1;
        d = (u8 *)dst - 1;
        n += 1;
        while (--n != 0) {
            *++d = *++s;
        }
    } else {
        s = (const u8 *)src + n;
        d = (u8 *)dst + n;
        n += 1;
        while (--n != 0) {
            *--d = *--s;
        }
    }
    return dst;
}

void fn_80231B60(void *dst, const void *src, u32 size) {
u32 *d;
u32 n, blocks;
const u8 *tail;
const u8 *sb;
u32 offset, shift, back;
u32 a,b;
u8 *db;
sb=(const u8*)src-1;
db=(u8*)dst-1;
n=(-(u32)dst)&3;
if(n) {
size-=n;
do { *++db=*++sb; } while(--n);
}
offset=(u32)(sb+1)&3;
d=(u32*)(db-3);
blocks=size>>3;
sb-=offset;
shift=offset*8;
back=32-shift;
a=*(const u32*)(sb+=1);
do {
b=*(const u32*)(sb+=4);
*++d=(a<<shift)|(b>>back);
a=*(const u32*)(sb+=4);
*++d=(b<<shift)|(a>>back);
} while(--blocks);
if(size&4) { b=*(const u32*)(sb+=4); *++d=(a<<shift)|(b>>back); }
size &=3;
tail=sb+3;
db=(u8*)d+3;
if(size) {
tail-=4-offset;
do { *++db=*++tail; } while(--size);
}
}

void fn_80231C20(u8 *dst, u8 *src, u32 n)
{
  u8 *s;
  u32 new_var2;
  u8 *d;
  unsigned int i;
  u8 *new_var;
  s = src + n;
  d = dst + n;
  i = ((u32) d) & 3;
  if (i != 0)
  {
    n -= i;
    do
    {
      *(--d) = *(--s);
    }
    while (--i);
  }
  i = n >> 5;
  if (i != 0)
  {
    do
    {
      u32 b;
      u32 a;
      new_var = d - 4;
      a = *((u32 *) (s - 4));
      --i;
      ;
      new_var2 = *((u32 *) (s - 12));
      *((u32 *) new_var) = a;
      a = new_var2;
      if ((s && s) && s)
      {
      }
      *((u32 *) (d - 8)) = *((u32 *) (s - 8));
      b = *((u32 *) (s - 16));
      *((u32 *) (d - 12)) = a;
      a = *((u32 *) (s - 20));
      *((u32 *) (d - 16)) = b;
      b = *((u32 *) (s - 24));
      *((u32 *) (d - 20)) = a;
      a = *((u32 *) (s - 28));
      *((u32 *) (d - 24)) = b;
      b = *((u32 *) (s - 32));
      s -= 32;
      *((u32 *) (d - 28)) = a;
      d -= 32;
      *((u32 *) d) = b;
    }
    while (i != 0);
  }
  i = (n >> 2) & 7;
  if (i != 0)
  {
    do
    {
      s -= 4;
      --i;
      d -= 4;
      *((u32 *) d) = *((u32 *) s);
    }
    while (i != 0);
  }
  n &= 3;
  if (n != 0)
  {
    do
    {
      *(--d) = *(--s);
    }
    while (--n);
  }
}

#pragma optimization_level 3
