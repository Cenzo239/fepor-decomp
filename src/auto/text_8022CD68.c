/* string pool for double2hex / printf float specials */
static const char double2hex_strpool[] =
    "\0-INF\0-inf\0INF\0inf\0-NAN\0-nan\0NAN\0nan";

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
    s32 *p = fragmentinfo_8033DD28;
    if (p[2] == 0) {
        s32 ret;
        p[0] = arg0;
        ret = 0;
        p[1] = arg1;
        p[2] = 1;
        return ret;
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
 void _ExitProcess(void);
 void (**dtor)(void);
 if(__aborting==0) {
 __begin_critical_region(0);
 __end_critical_region(0);
 __destroy_global_chain();
 dtor=(void (**)(void))&_dtors;
 while(*dtor!=0) {(*dtor)(); dtor++;}
 if(__stdio_exit!=0) {((void (*)(void))__stdio_exit)(); __stdio_exit=0;}
 }
 __begin_critical_region(0);
 while(__atexit_curr_func>0) {__atexit_curr_func--; __atexit_funcs[__atexit_curr_func]();}
 __end_critical_region(0);
 __kill_critical_regions();
 if(__console_exit!=0) {__console_exit(); __console_exit=0;}
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
void fn_80231CC8(void *dst, const void *src, u32 size)
{
  u32 *d;
  u32 n;
  const u32 *s;
  const u8 *sb;
  u32 b;
  u32 a;
  u8 *db;
  sb = ((const u8 *) src) - 1;
  db = ((u8 *) dst) - 1;
  n = (-((u32) dst)) & 3;
  if (n)
  {
    size -= n;
    do
    {
      *(++db) = *(++sb);
    }
    while (--n);
  }
  n = size >> 5;
  if (b)
  {
  }
  s = (const u32 *) (sb - 3);
  d = (u32 *) (db - 3);
  if (n)
  {
    do
    {
      a = *(++s);
      b = *(++s);
      *(++d) = a;
      a = *(++s);
      *(++d) = b;
      b = *(++s);
      *(++d) = a;
      a = *(++s);
      *(++d) = b;
      b = *(++s);
      *(++d) = a;
      a = *(++s);
      *(++d) = b;
      b = *(++s);
      *(++d) = a;
      *(++d) = b;
    }
    while (--n);
  }
  n = size >> 2;
  n = n & 7;
  if (n)
  {
    do
    {
      *(++d) = *(++s);
    }
    while (--n);
  }
  size &= 3;
  sb = ((const u8 *) s) + 3;
  db = ((u8 *) d) + 3;
  if (size)
  {
    do
    {
      *(++db) = *(++sb);
    }
    while ((--size) != 0);
  }
}
#pragma optimization_level reset
void __stdio_atexit(void) {
    __stdio_exit = __close_all;
}

#pragma use_lmw_stmw on
/* Format args into dest with fmt; null-terminate and return written length. */
s32 sprintf(char *dest, const char *fmt, ...) {
    va_list args;
    __OutStr out;
    s32 n;

    __builtin_va_info(&args);
    out.buffer = dest;
    out.length = -1;
    out.position = 0;
    n = __pformatter(fn_80232220, &out, fmt, args);
    if (dest != NULL) {
        u32 idx = (u32)-2;
        if ((u32)n < (u32)-1) {
            idx = (u32)n;
        }
        dest[idx] = 0;
    }
    return n;
}

s32 fn_80231E74(char *dest, s32 dest_len, const char *fmt, ...) {
 va_list args;
 __OutStr out;
 s32 n;
 __builtin_va_info(&args);
 out.buffer=dest; out.length=dest_len; out.position=0;
 n=__pformatter(fn_80232220,&out,fmt,args);
 if(dest != NULL) { u32 idx=(u32)dest_len-1; if((u32)n<(u32)dest_len) idx=(u32)n; dest[idx]=0; }
 return n;
}

#pragma use_lmw_stmw reset
s32 vsprintf(char *s, const char *fmt, va_list args) {
    __OutStr out;
    s32 n;
    u32 idx;

    out.buffer = s;
    out.length = -1;
    out.position = 0;
    n = __pformatter(fn_80232220, &out, fmt, args);
    if (s != NULL) {
        idx = (u32)-2;
        if ((u32)n < (u32)-1) {
            idx = (u32)n;
        }
        s[idx] = 0;
    }
    return n;
}

s32 vprintf(const char *format, void *args) {
    extern u8 __files[];
    s32 fwide(void *, s32);
    void __begin_critical_region(s32);
    void __end_critical_region(s32);
    s32 __FileWrite(void *, const char *, u32);
    s32 __pformatter(s32 (*)(void *, const char *, u32), void *, const char *, void *);

    void *stream;
    s32 result;

    stream = __files + 0x50;

    if (fwide(stream, -1) >= 0) {
        return -1;
    }

    __begin_critical_region(2);
    result = __pformatter(__FileWrite, stream, format, args);
    __end_critical_region(2);
    return result;
}

s32 fprintf(void *stream, const char *format, ...) {
    s32 fwide(void *, s32);
    void __begin_critical_region(s32);
    void __end_critical_region(s32);
    s32 __FileWrite(void *, const char *, u32);
    s32 result;
    va_list args;

    if (fwide(stream, -1) >= 0) {
        return -1;
    }
    __begin_critical_region(2);
    __builtin_va_info(&args);
    result = __pformatter(__FileWrite, stream, format, args);
    __end_critical_region(2);
    return result;
}

s32 fn_80232138(const char *format, ...) {
 extern u8 __files[];
 s32 fwide(void *, s32);
 void __begin_critical_region(s32);
 void __end_critical_region(s32);
 s32 __FileWrite(void *, const char *, u32);
 s32 result;
 va_list args;
 void *stream=__files+0x50;
 if(fwide(stream,-1)>=0) return -1;
 __begin_critical_region(2);
 __builtin_va_info(&args);
 result=__pformatter(__FileWrite,stream,format,args);
 __end_critical_region(2);
 return result;
}

s32 __StringWrite(void *arg0, const void *arg1, s32 arg2) {
    void *memcpy(void *, const void *, s32);
    void *self;
    s32 pos;
    s32 end;
    s32 n;

    self = arg0;
    pos = *(s32 *)((u8 *)arg0 + 8);
    end = *(s32 *)((u8 *)self + 4);
    n = end - pos;
    if ((u32)(pos + arg2) <= (u32)end) {
        n = arg2;
    }
    memcpy(*(char **)self + pos, arg1, n);
    *(s32 *)((u8 *)self + 8) = *(s32 *)((u8 *)self + 8) + n;
    return 1;
}

s32 __FileWrite(void *file, const char *buf, u32 n) {
    u32 fwrite(const void *, u32, u32, void *);
    u32 written;

    written = fwrite(buf, 1, n, file);
    if (n == written) {
        return (s32)file;
    }
    return 0;
}

s32 __pformatter(s32 (*write)(void *, const char *, u32), void *context, const char *format, register va_list args) {
    typedef struct {
        u8 just, sign, prec_set, alt, size, conv;
        u16 pad;
        s32 width, precision;
    } Format;
    void *__va_arg(void *,s32);
    char *parse_format_80233B44(const char *,void *,void *);
    char *longlong2str_802335D8(s64,char *,Format);
    char *long2str_802338EC(s32,char *,Format);
    char *float2str(char *,Format,f64);
    char *double2hex(char *,Format,f64);
    s32 wcstombs(char *,const void *,u32);
    s32 strlen(const char *);
    char *strchr(const char *,s32);
    void *memchr(const void *,s32,u32);
    extern const char double2hex_strpool[37];
    char buffer[512];
    Format f;
    char pad=' ';
    char blank;
    const char *cursor=format;
    const char *percent;
    char *text;
    s32 total=0;
    s32 number;
    s64 wide;
    s32 length, count;
    f64 real;
    void *ptr;
    while(*cursor) {
        percent=strchr(cursor,'%');
        if(!percent) {
            length=strlen(cursor);
            total+=length;
            if(length && ((u32)write(context,cursor,length)==0U)) return -1;
            break;
        }
        length=percent-cursor;
        total+=length;
        if(length && ((u32)write(context,cursor,length)==0U)) return -1;
        cursor=parse_format_80233B44(percent,args,&f);
        switch(f.conv) {
        case 'd': case 'i':
            if(f.size==3) number=*(s32 *)__va_arg(args,1);
            else if(f.size==4) wide=*(s64 *)__va_arg(args,2);
            else number=*(s32 *)__va_arg(args,1);
            if(f.size==2) number=(s16)number;
            if(f.size==1) number=(s8)number;
            if(f.size==4) {
                text=longlong2str_802335D8(wide,buffer+512,f);
                if(!text) goto invalid;
            } else {
                text=long2str_802338EC(number,buffer+512,f);
                if(!text) goto invalid;
            }
            length=buffer+511-text;
            break;
        case 'o': case 'u': case 'x': case 'X':
            if(f.size==3) number=*(u32 *)__va_arg(args,1);
            else if(f.size==4) wide=*(u64 *)__va_arg(args,2);
            else number=*(u32 *)__va_arg(args,1);
            if(f.size==2) number=(u16)number;
            if(f.size==1) number=(u8)number;
            if(f.size==4) {
                text=longlong2str_802335D8(wide,buffer+512,f);
                if(!text) goto invalid;
            } else {
                text=long2str_802338EC(number,buffer+512,f);
                if(!text) goto invalid;
            }
            length=buffer+511-text;
            break;
        case 'f': case 'F': case 'e': case 'E': case 'g': case 'G':
            if(f.size==5) real=*(long double *)__va_arg(args,3);
            else real=*(double *)__va_arg(args,3);
            text=float2str(buffer+512,f,real);
            if(!text) goto invalid;
            length=buffer+511-text;
            break;
        case 'a': case 'A':
            if(f.size==5) real=*(long double *)__va_arg(args,3);
            else real=*(double *)__va_arg(args,3);
            text=double2hex(buffer+512,f,real);
            if(!text) goto invalid;
            length=buffer+511-text;
            break;
        case 's':
            if(f.size==6) {
                const void *str=*(void **)__va_arg(args,1);
                if(!str) str=L"";
                if(wcstombs(buffer,str,512)<0) goto invalid;
                text=buffer;
            } else text=*(char **)__va_arg(args,1);
            if(!text) text=(char *)double2hex_strpool;
            if(f.alt) {
                length=(u8)*text++;
                if(f.prec_set && length>f.precision) length=f.precision;
            } else if(f.prec_set) {
                length=f.precision;
                ptr=memchr(text,0,length);
                if(ptr) length=(char *)ptr-text;
            } else length=strlen(text);
            break;
        case 'n':
            ptr=*(void **)__va_arg(args,1);
            switch(f.size) {
            case 0: *(s32 *)ptr=total; break;
            case 2: *(s16 *)ptr=total; break;
            case 3: *(s32 *)ptr=total; break;
            case 4: *(s64 *)ptr=total; break;
            }
            continue;
        case 'c':
            text=buffer;
            buffer[0]=*(s32 *)__va_arg(args,1);
            length=1;
            break;
        case '%':
            text=buffer;
            buffer[0]='%';
            length=1;
            break;
        case 0xFF: case 'h': case 't':
        default:
invalid:
            length=strlen(percent);
            total+=length;
            if(length && ((u32)write(context,percent,length)==0U)) return -1;
            return total;
        }
        count=length;
        if(f.just) {
            pad=f.just==2?'0':' ';
            if((*text=='+' || *text=='-' || *text==' ') && pad=='0') {
                if(((u32)write(context,text,1)==0U)) return -1;
                text++;
                length--;
            }
            while(count<f.width) {
                if(((u32)write(context,&pad,1)==0U)) return -1;
                count++;
            }
        }
        if(length && ((u32)write(context,text,length)==0U)) return -1;
        if(!f.just) {
            while(count<f.width) {
                blank=' ';
                if(((u32)write(context,&blank,1)==0U)) return -1;
                count++;
            }
        }
        total+=count;
    }
    return total;
}

char *float2str(char *buffer, void *format, f64 value)
{
    void fn_8022E660(void *, void *);
    void fn_80233174(void *, s32);
    void strcpy(char *, const char *);
    extern u8 lbl_8029E8A8[];
    extern f64 lbl_8036BE00;

    typedef struct {
        u8 unk0;
        u8 sign_style;
        u8 unk2;
        u8 alternate;
        u8 unk4;
        u8 conv;
        u8 pad6[6];
        s32 precision;
    } PrintFormat;

    typedef struct {
        s8 kind;
        s8 pad;
        s16 width;
    } DecCtrl;

    DecCtrl ctrl;
    RuntimeDecimal dec;
    PrintFormat *fmt = (PrintFormat *)format;
    char *out;
    u8 *digs;
    u8 *p;
    s32 i;
    s32 n;
    s32 frac;
    s32 whole;
    s32 exp;
    s8 signch;
    s32 prec;

    prec = fmt->precision;
    if (prec > 0x1FD) {
        return NULL;
    }

    ctrl.kind = 0;
    ctrl.width = 0x20;
    fn_8022E660(&ctrl, &dec);

    digs = dec.digits;
    p = digs + dec.length;
    while (dec.length > 1) {
        if (*--p != 0x30) {
            break;
        }
        dec.length -= 1;
        dec.exponent += 1;
    }

    switch ((s32)dec.digits[0]) {
    case 0x49:
        if (value < lbl_8036BE00) {
            out = buffer - 5;
            if (lbl_8029E8A8[fmt->conv] & 0x80) {
                strcpy(out, double2hex_strpool + 1);
            } else {
                strcpy(out, double2hex_strpool + 6);
            }
        } else {
            out = buffer - 4;
            if (lbl_8029E8A8[fmt->conv] & 0x80) {
                strcpy(out, double2hex_strpool + 0xB);
            } else {
                strcpy(out, double2hex_strpool + 0xF);
            }
        }
        return out;
    case 0x4E:
        if ((s8)dec.sign != 0) {
            out = buffer - 5;
            if (lbl_8029E8A8[fmt->conv] & 0x80) {
                strcpy(out, double2hex_strpool + 0x13);
            } else {
                strcpy(out, double2hex_strpool + 0x18);
            }
        } else {
            out = buffer - 4;
            if (lbl_8029E8A8[fmt->conv] & 0x80) {
                strcpy(out, double2hex_strpool + 0x1D);
            } else {
                strcpy(out, double2hex_strpool + 0x21);
            }
        }
        return out;
    case 0x30:
        dec.exponent = 0;
        break;
    }

    out = buffer - 1;
    dec.exponent = (s16)(dec.length + dec.exponent - 1);
    buffer[-1] = 0;

    switch (fmt->conv) {
    case 0x67:
    case 0x47:
        if ((s32)dec.length > fmt->precision) {
            fn_80233174(&dec, 0);
        }
        if (dec.exponent < -4 || dec.exponent >= fmt->precision) {
            if (fmt->alternate != 0) {
                fmt->precision = fmt->precision - 1;
            } else {
                fmt->precision = dec.length - 1;
            }
            if (fmt->conv == 0x67) {
                fmt->conv = 0x65;
            } else {
                fmt->conv = 0x45;
            }
            goto do_exp;
        }
        if (fmt->alternate != 0) {
            fmt->precision = fmt->precision - (dec.exponent + 1);
        } else {
            n = dec.length - (dec.exponent + 1);
            fmt->precision = n;
            if (n < 0) {
                fmt->precision = 0;
            }
        }
    case 0x66:
    case 0x46:
        goto do_f;
    case 0x65:
    case 0x45:
        goto do_exp;
    default:
        return out;
    }

do_exp:
    if ((s32)dec.length > fmt->precision + 1) {
        fn_80233174(&dec, 0);
    }
    exp = dec.exponent;
    signch = 0x2B;
    if (exp < 0) {
        exp = -exp;
        signch = 0x2D;
    }
    n = 0;
    do {
        n += 1;
        i = exp % 10;
        exp /= 10;
        *--out = (char)(i + 0x30);
    } while (exp != 0 || n < 2);
    out[-1] = signch;
    out[-2] = fmt->conv;
    out -= 2;
    if (fmt->precision + (s32)(buffer - out) > 0x1FD) {
        return NULL;
    }
    if ((s32)dec.length < fmt->precision + 1) {
        n = (fmt->precision + 2) - dec.length;
        do {
            *--out = 0x30;
            n -= 1;
        } while (n != 0);
    }
    i = dec.length;
    p = digs + i;
    while (i != 0) {
        i -= 1;
        if (i == 0) {
            break;
        }
        *--out = *--p;
    }
    if (fmt->precision != 0 || fmt->alternate != 0) {
        *--out = 0x2E;
    }
    *--out = dec.digits[0];
    if ((s8)dec.sign != 0) {
        *--out = 0x2D;
    } else if (fmt->sign_style == 1) {
        *--out = 0x2B;
    } else if (fmt->sign_style == 2) {
        *--out = 0x20;
    }
    return out;

do_f:
    frac = (dec.length - dec.exponent) - 1;
    if (frac < 0) {
        frac = 0;
    }
    if (frac > fmt->precision) {
        fn_80233174(&dec, dec.length - (frac - fmt->precision));
        frac = (dec.length - dec.exponent) - 1;
        if (frac < 0) {
            frac = 0;
        }
    }
    whole = dec.exponent + 1;
    if (whole < 0) {
        whole = 0;
    }
    if (whole + frac > 0x1FD) {
        return NULL;
    }
    n = fmt->precision - frac;
    p = digs + dec.length;
    while (n > 0) {
        *--out = 0x30;
        n -= 1;
    }
    i = 0;
    while (i < frac && i < (s32)dec.length) {
        *--out = *--p;
        i += 1;
    }
    while (i < frac) {
        *--out = 0x30;
        i += 1;
    }
    if (fmt->precision != 0 || fmt->alternate != 0) {
        *--out = 0x2E;
    }
    if (whole != 0) {
        i = 0;
        while (i < whole - (s32)dec.length) {
            *--out = 0x30;
            i += 1;
        }
        while (i < whole) {
            *--out = *--p;
            i += 1;
        }
    } else {
        *--out = 0x30;
    }
    if ((s8)dec.sign != 0) {
        *--out = 0x2D;
    } else if (fmt->sign_style == 1) {
        *--out = 0x2B;
    } else if (fmt->sign_style == 2) {
        *--out = 0x20;
    }
    return out;
}

void fn_80233174(void *arg0, s32 arg1) {
 u8 *p, *end;
 s32 carry;
 s8 digit;
 if(arg1<0) { zero: *(s16*)((u8*)arg0+2)=0; ((u8*)arg0)[4]=1; ((u8*)arg0)[5]='0'; return; }
 if(arg1>=((u8*)arg0)[4]) return;
 p=(u8*)arg0+arg1;
 digit=p[5]; p+=5;
 digit=digit-'0';
 if(digit==5) {
 end=(u8*)arg0+((u8*)arg0)[4]; end+=5;
 while(--end>p && (s32)*end=='0') {}
 if(end==p) carry=p[-1]&1; else carry=1;
 } else carry=digit>5;
 digit=9;
 while(arg1!=0) {
 s8 value; carry = *--p + carry; value=carry-'0';
 carry=value>digit;
 if(carry || value==0) --arg1;
 else { *p=value+'0'; break; }
 }
 if(carry) { ++*(s16*)((u8*)arg0+2); ((u8*)arg0)[4]=1; ((u8*)arg0)[5]='1'; return; }
 if(arg1==0) goto zero;
 ((u8*)arg0)[4]=arg1;
}

char *double2hex(char *buffer, void *format, f64 value) {
    void fn_8022E660(void *, void *);
    void strcpy(char *, const char *);
    char *long2str_802338EC(s32, char *, void *);

    typedef struct {
        u8 unk0;
        u8 sign_style;
        u8 unk2;
        u8 alternate;
        u8 unk4;
        u8 conv;
        u8 pad6[6];
        s32 precision;
    } PrintFormat;

    typedef struct {
        s8 kind;
        s8 pad;
        s16 width;
    } DecCtrl;

    char sp40[0x38];
    char sp30[16];
    char sp20[16];
    f64 sp18;
    DecCtrl sp10;
    f64 sp8;
    PrintFormat *fmt;
    char *out;
    char *p;
    s32 exp;
    s32 prec;
    s32 i;
    s8 nibble;
    u8 b;
    u32 sb;

    fmt = (PrintFormat *)format;
    sp8 = value;
    sp18 = value;
    if (fmt->precision > 0x1FD) {
        return NULL;
    }

    sp10.kind = 0;
    sp10.width = 0x20;
    fn_8022E660(&sp10, sp40);

    if ((u8)sp40[5] == 'I') {
        if (*(s16 *)&sp18 & 0x8000) {
            out = buffer - 5;
            if (fmt->conv == 'A') {
                strcpy(out, double2hex_strpool + 1);
            } else {
                strcpy(out, double2hex_strpool + 6);
            }
        } else {
            out = buffer - 4;
            if (fmt->conv == 'A') {
                strcpy(out, double2hex_strpool + 0xB);
            } else {
                strcpy(out, double2hex_strpool + 0xF);
            }
        }
        return out;
    }

    if ((u8)sp40[5] == 'N') {
        if (*(u8 *)&sp8 & 0x80) {
            out = buffer - 5;
            if (fmt->conv == 'A') {
                strcpy(out, double2hex_strpool + 0x13);
            } else {
                strcpy(out, double2hex_strpool + 0x18);
            }
        } else {
            out = buffer - 4;
            if (fmt->conv == 'A') {
                strcpy(out, double2hex_strpool + 0x1D);
            } else {
                strcpy(out, double2hex_strpool + 0x21);
            }
        }
        return out;
    }

    sp30[0] = 1;
    sp30[1] = 1;
    sp30[2] = 0;
    sp30[3] = 0;
    sp30[4] = 0;
    sp30[5] = 0x64;
    *(s32 *)(sp30 + 8) = 0;
    *(s32 *)(sp30 + 12) = 1;
    *(s32 *)(sp20 + 0) = *(s32 *)(sp30 + 0);
    *(s32 *)(sp20 + 4) = *(s32 *)(sp30 + 4);
    *(s32 *)(sp20 + 8) = 0;
    *(s32 *)(sp20 + 12) = 1;

    exp = (s16)((*(u16 *)&sp18 >> 4) & 0x7FF) - 0x3FF;
    p = long2str_802338EC(exp, buffer, sp20);

    if (fmt->conv == 'a') {
        p[-1] = 'p';
        out = p - 1;
    } else {
        p[-1] = 'P';
        out = p - 1;
    }

    prec = fmt->precision;
    i = prec;
    if (prec >= 1) {
        do {
            sb = (u32)i >> 31;
            b = ((u8 *)&sp8)[((s32)(sb + i) >> 1) + 1];
            if ((((i & 1) ^ (s32)sb) - (s32)sb) != 0) {
                nibble = (s8)(b & 0xF);
            } else {
                nibble = (s8)((b >> 4) & 0xF);
            }
            if (nibble < 0xA) {
                *--out = nibble + '0';
            } else if (fmt->conv == 'a') {
                *--out = nibble + 0x57;
            } else {
                *--out = nibble + 0x37;
            }
            i -= 1;
        } while (--prec);
    }

    if (fmt->precision != 0 || fmt->alternate != 0) {
        *--out = '.';
    }

    out[-1] = '1';
    if (fmt->conv == 'a') {
        out[-2] = 'x';
        out -= 2;
    } else {
        out[-2] = 'X';
        out -= 2;
    }
    *--out = '0';

    if (*(s16 *)&sp18 & 0x8000) {
        *--out = '-';
    } else if (fmt->sign_style == 1) {
        *--out = '+';
    } else if (fmt->sign_style == 2) {
        *--out = ' ';
    }
    return out;
}

#pragma use_lmw_stmw on
#pragma optimization_level 3
char *longlong2str_802335D8(s64 value, char *buffer, void *format)
{
    typedef struct {
        u8 just;
        u8 sign;
        u8 prec_set;
        u8 alt;
        u8 size;
        u8 conv;
        u16 pad;
        s32 width;
        s32 precision;
    } Format;
    u64 __div2u(u32, u32, u32, u32);
    u64 __mod2u(u32, u32, u32, u32);

    s64 val;
    u64 base;
    char *out;
    s32 count;
    s32 negative;
    Format *f;
    char *buf;
    s32 digit;

    val = value;
    f = (Format *)format;
    buf = buffer;
    out = buf;
    negative = 0;
    count = 0;
    *--out = 0;

    if (val == 0 && f->precision == 0 && !(f->alt && f->conv == 'o')) {
        return out;
    }

    switch (f->conv) {
    case 'd':
    case 'i':
        base = 10;
        if (val < 0) {
            val = -val;
            negative = 1;
        }
        break;
    case 'o':
        base = 8;
        f->sign = 0;
        break;
    case 'u':
        base = 10;
        f->sign = 0;
        break;
    case 'x':
    case 'X':
        base = 16;
        f->sign = 0;
        break;
    }

    do {
        digit = (u32)__mod2u((u32)((u64)val >> 32), (u32)(u64)val,
                             (u32)(base >> 32), (u32)base);
        val = (s64)__div2u((u32)((u64)val >> 32), (u32)(u64)val,
                           (u32)(base >> 32), (u32)base);
        if (digit < 10) {
            digit += '0';
        } else if (f->conv == 'x') {
            digit += 'a' - 10;
        } else {
            digit += 'A' - 10;
        }
        *--out = (char)digit;
        count++;
    } while (val != 0);

    if (base == 8 && f->alt && *out != '0') {
        *--out = '0';
        count++;
    }

    if (f->just == 2) {
        f->precision = f->width;
        if (negative || f->sign) {
            f->precision--;
        }
        if (base == 16 && f->alt) {
            f->precision -= 2;
        }
    }

    {
        s32 precision = f->precision;
        if (precision + (buf - out) > 509) {
            return 0;
        }

        while (count < precision) {
            *--out = '0';
            count++;
        }
    }

    if (base == 16 && f->alt) {
        *--out = f->conv;
        *--out = '0';
    }

    if (negative) {
        *--out = '-';
    } else if (f->sign == 1) {
        *--out = '+';
    } else if (f->sign == 2) {
        *--out = ' ';
    }

    return out;
}
#pragma optimization_level 3
char *long2str_802338EC(s32 value,char *buffer,void *format) {
    typedef struct {
        u8 just, sign, prec_set, alt, size, conv;
        u16 pad;
        s32 width, precision;
    } Format;
    Format *f=(Format *)format;
    u32 base;
    char *out=buffer;
    s32 count;
    s32 negative;
    s32 precision;
    s32 digit;
    u8 conv;
    negative=0;
    count=0;
    *--out=0;
    if(value==0 && f->precision==0 && !(f->alt && f->conv=='o')) return out;
    switch(f->conv) {
    case 'd': case 'i':
        base=10;
        if(value<0) { value=-value; negative=1; }
        break;
    case 'o': base=8; f->sign=0; break;
    case 'u': base=10; f->sign=0; break;
    case 'x': case 'X': base=16; f->sign=0; break;
    }
    conv=f->conv;
    do {
        digit=(u32)value%base;
        value=(u32)value/base;
        if(digit<10) digit+='0';
        else if(conv=='x') digit+='a'-10;
        else digit+='A'-10;
        *--out=digit;
        count++;
    } while((u32)value!=0);
    if(base==8 && f->alt && *out!='0') { *--out='0'; count++; }
    if(f->just==2) {
        f->precision=f->width;
        if(negative || f->sign) f->precision--;
        if(base==16 && f->alt) f->precision-=2;
    }
    precision=f->precision;
    if(precision+(buffer-out)>509) return 0;
    while(count<precision) { *--out='0'; count++; }
    if(base==16 && f->alt) {
        *--out=f->conv;
        *--out='0';
    }
    if(negative) *--out='-';
    else if(f->sign==1) *--out='+';
    else if(f->sign==2) *--out=' ';
    return out;
}
#pragma optimization_level reset
char *parse_format_80233B44(char *format, void *ap, void *out)
{
    void *__va_arg(void *, s32);
    extern u8 lbl_8029E8A8[];

    struct {
        u8 just;
        u8 sign;
        u8 prec_set;
        u8 alt;
        u8 size;
        u8 conv;
        u16 pad;
        s32 width;
        s32 precision;
    } f;
    char *p;
    s32 c;
    s32 cont;
    s32 *vp;
    s32 v;

    c = (s8)format[1];
    p = format + 1;

    f.sign = 0;
    f.just = 1;
    f.prec_set = 0;
    f.alt = 0;
    f.size = 0;
    f.width = 0;
    f.precision = 0;

    if (c == '%') {
        f.conv = (u8)c;
        *(u32 *)out = *(u32 *)&f.just;
        *(u32 *)((u8 *)out + 4) = *(u32 *)&f.size;
        *(s32 *)((u8 *)out + 8) = 0;
        *(s32 *)((u8 *)out + 12) = 0;
        return p + 1;
    }

    for (;;) {
        cont = 1;
        switch (c) {
        case '-':
            f.just = 0;
            break;
        case '+':
            f.sign = 1;
            break;
        case ' ':
            if (f.sign != 1) {
                f.sign = 2;
            }
            break;
        case '#':
            f.alt = 1;
            break;
        case '0':
            if (f.just != 0) {
                f.just = 2;
            }
            break;
        default:
            cont = 0;
            break;
        }
        if (cont == 0) {
            break;
        }
        c = (s8)*++p;
    }

    if (c == '*') {
        vp = __va_arg(ap, 1);
        v = *vp;
        f.width = v;
        if (v < 0) {
            f.just = 0;
            f.width = -v;
        }
        c = (s8)*++p;
    } else {
        while (lbl_8029E8A8[(u8)c] & 0x10) {
            f.width = f.width * 10 + (c - '0');
            c = (s8)*++p;
        }
    }

    if (f.width > 0x1FD) {
        f.conv = 0xFF;
        *(u32 *)out = *(u32 *)&f.just;
        *(u32 *)((u8 *)out + 4) = *(u32 *)&f.size;
        *(s32 *)((u8 *)out + 8) = f.width;
        *(s32 *)((u8 *)out + 12) = f.precision;
        return p + 1;
    }

    if (c == '.') {
        f.prec_set = 1;
        c = (s8)*++p;
        if (c == '*') {
            vp = __va_arg(ap, 1);
            v = *vp;
            f.precision = v;
            if (v < 0) {
                f.prec_set = 0;
            }
            c = (s8)*++p;
        } else {
            while (lbl_8029E8A8[(u8)c] & 0x10) {
                f.precision = f.precision * 10 + (c - '0');
                c = (s8)*++p;
            }
        }
    }

    cont = 1;
    switch (c) {
    case 'h':
        f.size = 2;
        if ((s8)p[1] == 'h') {
            f.size = 1;
            c = (s8)p[1];
            p += 1;
        }
    break;
    case 'l':
        f.size = 3;
        if ((s8)p[1] == 'l') {
            f.size = 4;
            c = (s8)p[1];
            p += 1;
        }
    break;
    case 'L':
        f.size = 5;
        break;
    default:
        cont = 0;
        break;
    }
    if (cont != 0) {
        c = (s8)*++p;
    }

    f.conv = (u8)c;
    switch (c) {
    case 'd':
    case 'i':
    case 'o':
    case 'u':
    case 'x':
    case 'X':
        if (f.size == 5) {
            f.conv = 0xFF;
        } else if (f.prec_set == 0) {
            f.precision = 1;
        } else if (f.just == 2) {
            f.just = 1;
        }
        break;
    case 'f':
    case 'F':
    case 'e':
    case 'E':
        if (f.size == 2 || f.size == 4) {
            f.conv = 0xFF;
        } else if (f.prec_set == 0) {
            f.precision = 6;
        }
        break;
    case 'a':
    case 'A':
        if (f.prec_set == 0) {
            f.precision = 0xD;
        }
        if (f.size == 2 || f.size == 4 || f.size == 1) {
            f.conv = 0xFF;
        }
        break;
    case 'g':
    case 'G':
        if (f.precision == 0) f.precision = 1;
        if (f.size == 2 || f.size == 4 || f.size == 1) f.conv = 0xFF;
        else if (f.prec_set == 0) f.precision = 6;
        break;
    case 'p':
        f.conv = 'x';
        f.alt = 1;
        f.size = 3;
        f.precision = 8;
        break;
    case 'n':
        if (f.size == 3) {
            f.size = 6;
        } else if (f.prec_set != 0 || f.size != 0) {
            f.conv = 0xFF;
        }
        break;
    case 's':
        if (f.size == 3) {
            f.size = 6;
        } else if (f.size != 0) {
            f.conv = 0xFF;
        }
        break;
    case 'c':
        if (f.size == 5) {
            f.conv = 0xFF;
        }
        break;
    default:
        f.conv = 0xFF;
        break;
    }

    *(u32 *)out = *(u32 *)&f.just;
    *(u32 *)((u8 *)out + 4) = *(u32 *)&f.size;
    *(s32 *)((u8 *)out + 8) = f.width;
    *(s32 *)((u8 *)out + 12) = f.precision;
    return p + 1;
}
#pragma optimization_level reset
s32 __StringRead(void *isc, s32 ch, s32 act)
{
    char ret;
    __InStrCtrl *Iscp = (__InStrCtrl *)isc;

    switch (act) {
    case 0:
        ret = *Iscp->NextChar;
        if (ret == '\0') {
            Iscp->NullCharDetected = 1;
            return -1;
        }
        Iscp->NextChar++;
        return (u8)ret;
    case 1:
        if (Iscp->NullCharDetected == 0) {
            Iscp->NextChar--;
        } else {
            Iscp->NullCharDetected = 0;
        }
        return ch;
    case 2:
        return Iscp->NullCharDetected;
    default:
        return 0;
    }
}

/* MSL raise: run the handler for sig (1..6), honoring SIG_IGN/SIG_DFL. */
s32 signal_raise(s32 sig) {
    extern void (*__signal_funcs[])(s32);
    extern s32 __begin_critical_region(s32);
    extern s32 __end_critical_region(s32);
    extern void exit(s32);
    void (*handler)(s32);

    if ((sig < 1) || (sig > 6)) {
        return -1;
    }
    __begin_critical_region(4);
    handler = __signal_funcs[sig - 1];
    if (handler != (void (*)(s32))1) {
        __signal_funcs[sig - 1] = 0;
    }
    __end_critical_region(4);
    if ((handler == (void (*)(s32))1) || ((handler == 0) && (sig == 1))) {
        return 0;
    }
    if (handler == 0) {
        exit(0);
    }
    handler(sig);
    return 0;
}

u8 *fn_80234198(u8 *str, u8 *pat) {
u8 *p; u8 c; u8 d; u8 e; u8 *q; u8 *r;
p=str-1;
if(!pat) return str;
c=*pat;
if(!c) return str;
goto outer;
match_check:
if(d!=c) goto outer;
q=p-1; r=pat-1;
do {
d=*++q; e=*++r;
if(d!=e) break;
} while(d!=0);
if(e!=0) goto outer;
return p;
outer:
d=*++p;
if(d!=0) goto match_check;
return 0;
}

void *fn_80234200(s32 arg0, u8 arg1) { u8 *p=(u8*)arg0-1; u32 needle=arg1; u8 *last=NULL; u32 c; while((c=*++p)!=0) { if(c==needle) last=p; } if(last!=NULL) return last; if(needle!=0) return NULL; return p; }

void *strchr(void *arg0, u8 arg1) {
    u8 *p = (u8 *)arg0 - 1;
    u32 needle = arg1;
    u32 c;
    while ((c = *++p) != 0) {
        if (c == needle) return p;
    }
    if (needle == 0) return p;
    return NULL;
}

s32 Str_NCmp(u8 *arg0, u8 *arg1, u32 arg2) {
    register u8 *s1 = arg0 - 1;
    register u8 *s2 = arg1 - 1;
    register u32 c1;
    register u32 c2;
    register u32 n = arg2 + 1;

    while (--n != 0) {
        c1 = *++s1;
        c2 = *++s2;
        if (c1 != c2) {
            return c1 - c2;
        }
        if (c1 == 0) {
            break;
        }
    }
    return 0;
}

s32 Str_Cmp(u8 *s1, u8 *s2) {
    // Word-at-a-time strcmp: align, then compare 4 bytes until a zero byte or mismatch.
    register u8 *left = s1;
    register u8 *right = s2;
    u32 align;
    u32 mask;
    register u32 l1;
    register u32 r1;
    register s32 x;

    l1 = *left;
    x = l1 - *right;
    if (x != 0) {
        return x;
    }
    if ((align = (u32)left & 3) != ((u32)right & 3)) {
        goto bytecopy;
    }
    if (align != 0) {
        if (l1 == 0) {
            return 0;
        }
        for (align = 3 - align; align != 0; align--) {
            l1 = *(++left);
            r1 = *(++right);
            x = l1 - r1;
            if (x != 0) {
                return x;
            }
            if (l1 == 0) {
                return 0;
            }
        }
        left++;
        right++;
    }
    l1 = *(u32 *)left;
    mask = 0x80808080;
    r1 = *(u32 *)right;
    if ((l1 - 0x01010101) & mask) {
        goto adjust;
    }
    while (l1 == r1) {
        left += 4;
        right += 4;
        l1 = *(u32 *)left;
        r1 = *(u32 *)right;
        if ((l1 - 0x01010101) & mask) {
            goto adjust;
        }
    }
    if (l1 > r1) {
        return 1;
    }
    return -1;

adjust:
    l1 = *left;
    x = l1 - *right;
    if (x != 0) {
        return x;
    }
bytecopy:
    if (l1 == 0) {
        return 0;
    }
    do {
        l1 = *(++left);
        x = l1 - *(++right);
        if (x != 0) {
            return x;
        }
    } while (l1 != 0);
    return 0;
}

u8 *strcat(u8 *dest, u8 *src)
{
    u8 *s;
    u8 *d;

    s = src - 1;
    d = dest - 1;
    while (*++d != 0) {
    }
    d--;
    while ((*++d = *++s) != 0) {
    }
    return dest;
}

char *Str_CopyPad(char *dest, const char *src, s32 count) { const unsigned char *s=(const unsigned char*)src-1; unsigned char *d=(unsigned char*)dest-1; count++; while (--count != 0) { unsigned char value=*++s; *++d=value; if (value==0) { while (--count != 0) *++d=0; return dest; } } return dest; }

char *strcpy(char *dst, const char *src) {
    register u8 *d = (u8 *)dst;
    register u8 *s = (u8 *)src;
    u32 align;
    u32 mask;
    register u32 w;
    register u32 c;
    if (((u32)d & 3) != (align = (u32)s & 3)) goto bytecopy;
    if (align != 0) {
        c = *d = *s;
        if (c == 0) return dst;
        for (align = 3 - align; align != 0; align--) {
            c = *++s;
            *++d = c;
            if (c == 0) return dst;
        }
        d++;
        s++;
    }
    w = *(u32 *)s;
    mask = 0x80808080;
    if (((w - 0x01010101) & mask) == 0) {
        d -= 4;
        do {
            *(u32 *)(d += 4) = w;
            w = *(u32 *)(s += 4);
        } while (((w - 0x01010101) & mask) == 0);
        d += 4;
    }
bytecopy:
    c = *d = *s;
    if (c == 0) return dst;
    do {
        c = *++s;
        *++d = c;
    } while (c != 0);
    return dst;
}

s32 strlen(const char *str) {
    const u8 *s = (const u8 *)str - 1;
    s32 length = -1;
    u32 c;
    do {
        c = *++s;
        ++length;
    } while (c != 0);
    return length;
}

f64 fn_80234524(char *arg0) {
f64 fn_802345B0(s32,s32 (*)(),void *,s32 *,s32 *);
extern s32 __StringRead();
extern f64 lbl_80367070[], lbl_80367078[];
extern f64 lbl_8036BE10;
extern s32 errno;
f64 value, magnitude;
__InStrCtrl isc;
s32 overflow, count;
isc.NextChar=arg0;
isc.NullCharDetected=0;
value=fn_802345B0(0x7fffffff,__StringRead,&isc,&count,&overflow);
magnitude=__fabs(value);
if (overflow || (lbl_8036BE10 != value && (magnitude < lbl_80367070[0] || magnitude > lbl_80367078[0]))) errno=0x22;
return value;
}

f64 fn_8022D5E0(void *);
f64 fn_802345B0(s32 arg0, s32 (*arg1)(void *, s32, s32), void *arg2, s32 *arg3, s32 *arg4)
{
    extern u8 lbl_80282C88[];
    extern u8 *lbl_8029EBA8;
    extern u8 lbl_8029E8A8[];
    extern u8 lbl_8029EAA8[];
    extern u8 lbl_80282CB4[];
    extern f32 lbl_8036706C;
    extern f32 lbl_80367068;
    extern f64 lbl_80367080;
    extern f64 lbl_80367088;
    extern f64 lbl_80367090;
    extern s32 lbl_8036BE08;
    extern u8 lbl_8036BE0C;
    extern f64 lbl_8036BE10;
    extern f64 lbl_8036BE18;

    s32 sp60 = 0;
    s32 sp5C = 0;
    s32 sp58 = 0;
    u8 buf[0x28];
    f64 sp18;
    u8 infbuf[12];
    u8 nanbuf[8];
    s32 state = 1;
    s32 hex = 0;
    s32 skipped = 0;
    s32 expv = 0;
    s32 trail = 0;
    s32 pad = 0;
    s16 hexexp = 0;
    s32 neg = 0;
    s32 pos = 1;
    s32 ch;
    u8 decimal;
    s32 i;
    s32 n;
    u8 *p;
    u8 cls;
    f32 f;

    for (i = 0; i < 0x28; i++) {
        buf[i] = lbl_80282C88[i];
    }
    decimal = *lbl_8029EBA8;
    *arg4 = 0;
    ch = arg1(arg2, 0, 0);

    for (;;) {
        if (pos > arg0 || ch == -1 || (state & 0x1800)) {
            break;
        }
        switch (state) {
        case 1:
            if (lbl_8029E8A8[(u8)ch] & 6) {
                ch = arg1(arg2, 0, 0);
                skipped++;
            } else {
                cls = (ch == -1) ? (u8)-1 : lbl_8029EAA8[(u8)ch];
                if (cls == 0x2D) {
                    neg = 1;
                    pos++;
                    ch = arg1(arg2, 0, 0);
                    sp5C = 1;
                } else if (cls == 0x2B) {
                    pos++;
                    ch = arg1(arg2, 0, 0);
                    sp5C = 1;
                } else if (cls == 0x49) {
                    pos++;
                    state = 0x4000;
                    ch = arg1(arg2, 0, 0);
                } else if (cls == 0x4E) {
                    pos++;
                    state = 0x2000;
                    ch = arg1(arg2, 0, 0);
                } else {
                    state = 2;
                }
            }
            break;
        case 0x4000:
            p = &infbuf[1];
            n = 1;
            *(s32 *)infbuf = *(s32 *)lbl_80282CB4;
            *(s32 *)(infbuf + 4) = *(s32 *)(lbl_80282CB4 + 4);
            infbuf[8] = lbl_80282CB4[8];
            while (n < 8) {
                cls = (ch == -1) ? (u8)-1 : lbl_8029EAA8[(u8)ch];
                if ((s8)*p != (s32)cls) break;
                p++;
                n++;
                pos++;
                ch = arg1(arg2, 0, 0);
            }
            if (n == 3 || n == 8) {
                f = neg ? -lbl_8036706C : lbl_8036706C;
                sp18 = f;
                *arg3 = skipped + n + sp5C;
                return sp18;
            }
            state = 0x1000;
            break;
        case 0x2000:
            p = &nanbuf[1];
            n = 1;
            *(s32 *)nanbuf = lbl_8036BE08;
            nanbuf[4] = lbl_8036BE0C;
            i = 0;
            while (n < 4) {
                cls = (ch == -1) ? (u8)-1 : lbl_8029EAA8[(u8)ch];
                if ((s8)*p != (s32)cls) break;
                p++;
                n++;
                pos++;
                ch = arg1(arg2, 0, 0);
            }
            if (n == 3 || n == 4) {
                if (n == 4) {
                    while (i < 0x20 && (lbl_8029E8A8[(u8)ch] & 0x10 || lbl_8029E8A8[(u8)ch] & 0xC0)) {
                        i++;
                        pos++;
                        ch = arg1(arg2, 0, 0);
                    }
                    if (ch != 0x29) {
                        state = 0x1000;
                        break;
                    }
                    i++;
                }
                f = neg ? -lbl_80367068 : lbl_80367068;
                sp18 = f;
                *arg3 = skipped + n + i + sp5C;
                return sp18;
            }
            state = 0x1000;
            break;
        case 2:
            if (ch == (s32)decimal) {
                state = 0x10;
                pos++;
                ch = arg1(arg2, 0, 0);
            } else if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                state = 0x1000;
            } else if (ch == 0x30) {
                pos++;
                ch = arg1(arg2, 0, 0);
                cls = (ch == -1) ? (u8)-1 : lbl_8029EAA8[(u8)ch];
                if (cls == 0x58) {
                    hex = 1;
                    state = 0x8000;
                } else {
                    state = 4;
                }
            } else {
                state = 8;
            }
            break;
        case 4:
            if (ch == 0x30) {
                pos++;
                ch = arg1(arg2, 0, 0);
            } else {
                state = 8;
            }
            break;
        case 8:
            if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                if (ch == (s32)decimal) {
                    state = 0x20;
                    pos++;
                    ch = arg1(arg2, 0, 0);
                } else {
                    state = 0x40;
                }
            } else {
                if (buf[4] < 0x14) {
                    buf[5 + buf[4]] = (u8)ch;
                    buf[4]++;
                } else {
                    trail++;
                }
                pos++;
                ch = arg1(arg2, 0, 0);
            }
            break;
        case 0x10:
            if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                state = 0x1000;
            } else {
                state = 0x20;
            }
            break;
        case 0x20:
            if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                state = 0x40;
            } else {
                if (buf[4] < 0x14) {
                    if (ch != 0x30 || buf[4] != 0) {
                        buf[5 + buf[4]] = (u8)ch;
                        buf[4]++;
                    }
                    trail--;
                }
                pos++;
                ch = arg1(arg2, 0, 0);
            }
            break;
        case 0x40:
            cls = (ch == -1) ? (u8)-1 : lbl_8029EAA8[(u8)ch];
            if (cls == 0x45) {
                state = 0x80;
                pos++;
                ch = arg1(arg2, 0, 0);
            } else {
                state = 0x800;
            }
            break;
        case 0x80:
            if (ch == 0x2B) {
                pos++;
                ch = arg1(arg2, 0, 0);
            } else if (ch == 0x2D) {
                pos++;
                ch = arg1(arg2, 0, 0);
                sp60 = 1;
            }
            state = 0x100;
            break;
        case 0x100:
            if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                state = 0x1000;
            } else if (ch == 0x30) {
                state = 0x200;
                pos++;
                ch = arg1(arg2, 0, 0);
            } else {
                state = 0x400;
            }
            break;
        case 0x200:
            if (ch == 0x30) {
                pos++;
                ch = arg1(arg2, 0, 0);
            } else {
                state = 0x400;
            }
            break;
        case 0x400:
            if (!(lbl_8029E8A8[(u8)ch] & 0x10)) {
                state = 0x800;
            } else {
                expv = (ch + expv * 10) - 0x30;
                if (expv > 0x7FFF) *arg4 = 1;
                pos++;
                ch = arg1(arg2, 0, 0);
            }
            break;
        default:
            state = 0x1000;
            break;
        }
    }

    {
        s32 mask = state & 0xE2C;
        if (mask == 0) {
            *arg3 = 0;
        } else {
            *arg3 = (pos + skipped) - 1;
        }
        arg1(arg2, 1, 0);
        if (hex == 0) {
            if (sp60) expv = -expv;
            {
                u8 nd = buf[4];
                while (nd != 0) {
                    if (buf[4 + nd] == 0x30) {
                        trail++;
                        nd--;
                        buf[4] = nd;
                    } else break;
                }
            }
            if (buf[4] == 0) {
                buf[4] = 1;
                buf[5] = 0x30;
            }
            {
                s16 e = (s16)(expv + trail);
                if (e < -0x8000 || e > 0x7FFF) *arg4 = 1;
                *(s16 *)(buf + 2) = e;
            }
            sp18 = fn_8022D5E0(buf);
            if ((f32)lbl_8036BE10 != (f32)sp18 && (f32)sp18 < (f32)lbl_80367088) {
                *arg4 = 1;
            } else if ((f32)sp18 > (f32)lbl_80367090) {
                *arg4 = 1;
                sp18 = lbl_80367080;
            }
            if (neg && mask != 0) sp18 = -sp18;
            return sp18;
        }
    }
    return lbl_8036BE10;
}

s32 atoi(char *str) {
    extern s32 errno;
    extern s32 __StringRead();
    extern u32 __strtoul(s32, s32, s32 (*)(), void *, s32 *, s32 *, s32 *);
    u32 value;
    s32 overflow;
    s32 negative;
    s32 count;
    __InStrCtrl isc;

    // Parse a decimal C string to s32; clamp to INT_MIN/INT_MAX and set errno=ERANGE on overflow.
    isc.NextChar = str;
    isc.NullCharDetected = 0;
    value = __strtoul(10, 0x7FFFFFFF, __StringRead, &isc, &count, &negative, &overflow);
    if (overflow || (!negative && value > 0x7FFFFFFF) || (negative && value > 0x80000000)) {
        value = negative ? 0x80000000 : 0x7FFFFFFF;
        errno = 0x22;
    } else if (negative) {
        value = -value;
    }
    return value;
}

#pragma use_lmw_stmw on
extern u8 lbl_8029E8A8[];
extern u8 lbl_8029EAA8[];
#pragma use_lmw_stmw on
u32 __strtoul(s32 base, s32 max_width, s32 (*ReadProc)(void *, s32, s32), void *ReadProcArg,
                s32 *chars_scanned, s32 *negative, s32 *overflow) {
    u32 limit;
    u32 value;
    s32 spaces;
    s32 state;
    s32 *csp;
    s32 *negp;
    s32 *ovfp;
    void *rpa;
    s32 (*rp)(void *, s32, s32);
    s32 mw;
    s32 b;
    s32 count;
    s32 c;
    s32 dig;
    u8 cls;

    b = base;
    mw = max_width;
    rp = ReadProc;
    rpa = ReadProcArg;
    csp = chars_scanned;
    negp = negative;
    ovfp = overflow;

    *ovfp = 0;
    *negp = 0;
    state = 1;
    count = 0;
    spaces = 0;
    value = 0;
    limit = 0;
    c = 0;

    if (b >= 0 && b != 1 && b <= 36) {
        if (mw >= 1) {
            c = (*rp)(rpa, 0, 0);
            count = 1;
            if (b != 0) {
                limit = 0xFFFFFFFFu / (u32)b;
            }
            goto check;
        }
    }
    state = 0x40;
    goto check;

loop:
    switch (state) {
    case 1:
        if ((lbl_8029E8A8[c & 0xFF] & 6) != 0) {
            c = (*rp)(rpa, 0, 0);
            spaces++;
            break;
        }
        if (c == '+') {
            count++;
            c = (*rp)(rpa, 0, 0);
        } else if (c == '-') {
            count++;
            c = (*rp)(rpa, 0, 0);
            *negp = 1;
        }
        state = 2;
        break;
    case 2:
        if (b == 0 || b == 16) {
            if (c == '0') {
                state = 4;
                count++;
                c = (*rp)(rpa, 0, 0);
                break;
            }
        }
        state = 8;
        break;
    case 4:
        if (c == 'X' || c == 'x') {
            b = 16;
            state = 8;
            count++;
            c = (*rp)(rpa, 0, 0);
            break;
        }
        if (b == 0) {
            b = 8;
        }
        state = 0x10;
        break;
    case 8:
        if (b == 0) {
            b = 10;
        }
        if (limit == 0) {
            limit = 0xFFFFFFFFu / (u32)b;
        }
        state = 0x10;
        break;
    case 0x10:
        cls = lbl_8029E8A8[c & 0xFF];
        if (cls & 0x10) {
            dig = c - '0';
            if (dig >= b) {
                state = (state == 0x10) ? 0x20 : 0x40;
                break;
            }
        } else if (cls & 0xC0) {
            dig = (c == -1) ? -1 : (s32)lbl_8029EAA8[c & 0xFF];
            dig -= 0x37;
            if (dig >= b) {
                state = (state == 0x10) ? 0x20 : 0x40;
                break;
            }
        } else {
            dig = (c == -1) ? -1 : (s32)lbl_8029EAA8[c & 0xFF];
            dig -= 0x37;
            /* fall through to accumulate — matches target */
        }
        if (value > limit) {
            *ovfp = 1;
        }
        value *= b;
        if ((u32)dig > 0xFFFFFFFFu - value) {
            *ovfp = 1;
        }
        value += dig;
        state = 0x10;
        count++;
        c = (*rp)(rpa, 0, 0);
        break;
    default:
        break;
    }

check:
    if (count <= mw && c != -1 && (state & 0x60) == 0) {
        if (state <= 0x10) {
            goto loop;
        }
    }

    if ((state & 0x34) == 0) {
        value = 0;
        *csp = 0;
    } else {
        *csp = count + spaces - 1;
    }
    (*rp)(rpa, c, 1);
    return value;
}

s32 fwide(void *arg0, s32 arg1) {
u8 *stream=arg0;
s32 orientation;
u8 flags;
if (!stream || !((*(u16*)(stream+4)>>6)&7)) return 0;
flags=stream[5];
orientation=(flags>>4)&3;
switch (orientation) {
case 0:
if (arg1>0) stream[5]=__rlwimi(flags,2,4,26,27);
else if (arg1<0) stream[5]=__rlwimi(flags,1,4,26,27);
return arg1;
case 2: return 1;
case 1: return -1;
}
return (s32)arg0;
}

/* MSL console write: on non-TDEV, init/write EXI UART then always hand off to GDEV path. */
s32 __write_console(s32 handle, s32 buffer, s32 *count, s32 ref) {
    s32 OSGetConsoleType(void);
    M2C_UNK fn_8022B530(s32, s32, s32 *, s32);
    s32 InitializeUART(M2C_UNK);
    s32 WriteUARTN(s32, s32);
    extern s32 UART_Initialized;
    s32 err;

    if (!(OSGetConsoleType() & 0x20000000)) {
        err = 0;
        if ((s32) UART_Initialized == 0) {
            err = InitializeUART(0xE100);
            if (err == 0) {
                UART_Initialized = 1;
            }
        }
        if (err != 0) {
            return 1;
        }
        if (WriteUARTN(buffer, *count) != 0) {
            *count = 0;
            return 1;
        }
        goto block_8;
    }
block_8:
    fn_8022B530(handle, buffer, count, ref);
    return 0;
}

f64 fn_80235B4C(f64 farg0) {
    f64 sp8;
    f64 f10;
    f64 y;
    f64 N;
    f64 D;
    f64 f2;
    f64 f0;
    f64 z;
    f64 h;
    f64 Nz;
    f64 Dz;
    f64 sp10;
    s32 unksp14;
    union { f64 d; u32 w[2]; } cv;
    s32 temp_r4;
    s32 temp_r3;
    u32 temp_r0;
    u32 chk;

    sp8 = farg0;
    cv.d = sp8;
    temp_r4 = (s32)cv.w[0];
    temp_r3 = temp_r4 & 0x7FFFFFFF;
    temp_r0 = cv.w[1];

    if (temp_r3 >= 0x3FF00000) {
        chk = (u32)temp_r3 - 0x3FF00000u;
        if ((chk | temp_r0) == 0) {
            if (temp_r4 > 0) {
                return lbl_8036BE20;
            }
            return lbl_8036BE28;
        }
        return (f64)lbl_80367068;
    }
    if (temp_r3 < 0x3FE00000) {
        if (temp_r3 <= 0x3C600000) {
            return lbl_8036BE30;
        }
        f10 = farg0 * farg0;
        y = f10;
        N = ((((lbl_8036BE68 * y + lbl_8036BE60) * y + lbl_8036BE58) * y + lbl_8036BE48) * y + lbl_8036BE70) * y + lbl_8036BE80;
        D = ((((lbl_8036BE90 * y + lbl_8036BE88) * y + lbl_8036BE40) * y + lbl_8036BE50) * y + lbl_8036BE90);
        f2 = y * N / D;
        f0 = lbl_8036BE38 - farg0 * f2;
        f0 = farg0 - f0;
        return lbl_8036BE30 - f0;
    }
    if (temp_r4 < 0) {
        z = lbl_8036BE98 * (lbl_8036BE70 + farg0);
        h = fn_80238A9C(z, lbl_8036BE98);
        Nz = ((((lbl_8036BE68 * z + lbl_8036BE60) * z + lbl_8036BE58) * z + lbl_8036BE48) * z + lbl_8036BE70) * z + lbl_8036BE80;
        Dz = ((((lbl_8036BE90 * z + lbl_8036BE88) * z + lbl_8036BE40) * z + lbl_8036BE50) * z + lbl_8036BE90);
        return -((lbl_8036BEA0 * (h + (Nz / Dz * h - lbl_8036BE38))) - lbl_8036BE28);
    }
    z = lbl_8036BE98 * (lbl_8036BE70 - farg0);
    h = fn_80238A9C(z, lbl_8036BE98);
    sp10 = h;
    unksp14 = 0;
    Nz = ((((lbl_8036BE68 * z + lbl_8036BE60) * z + lbl_8036BE58) * z + lbl_8036BE48) * z + lbl_8036BE70) * z + lbl_8036BE80;
    Dz = ((((lbl_8036BE90 * z + lbl_8036BE88) * z + lbl_8036BE40) * z + lbl_8036BE50) * z + lbl_8036BE90);
    return lbl_8036BEA0 * (sp10 + (Nz / Dz * h + (-((sp10 * sp10) - z) / (h + sp10))));
}

/* IEEE754 double remainder: return x - n*y for integer n, same sign as x. */
f64 __ieee754_fmod(f64 x, f64 y) {
    extern f64 fmod_Zero[];
    int n, hx, hy, hz, ix, iy, sx, i;
    unsigned lx, ly, lz;

    hy = *(int *)&y;
    hx = *(int *)&x;
    ly = *(1 + (unsigned *)&y);
    sx = hx & 0x80000000;
    hx ^= sx;
    hy &= 0x7fffffff;
    lx = *(1 + (unsigned *)&x);

    if ((hy | ly) == 0 || (hx >= 0x7ff00000) ||
        ((hy | ((ly | -ly) >> 31)) > 0x7ff00000))
        return (x * y) / (x * y);
    if (hx <= hy) {
        if ((hx < hy) || (lx < ly))
            return x;
        if (lx == ly)
            return fmod_Zero[(unsigned)sx >> 31];
    }

    if (hx < 0x00100000) {
        if (hx == 0) {
            for (ix = -1043, i = lx; i > 0; i <<= 1)
                ix -= 1;
        } else {
            for (ix = -1022, i = (hx << 11); i > 0; i <<= 1)
                ix -= 1;
        }
    } else
        ix = (hx >> 20) - 1023;

    if (hy < 0x00100000) {
        if (hy == 0) {
            for (iy = -1043, i = ly; i > 0; i <<= 1)
                iy -= 1;
        } else {
            for (iy = -1022, i = (hy << 11); i > 0; i <<= 1)
                iy -= 1;
        }
    } else
        iy = (hy >> 20) - 1023;

    if (ix >= -1022)
        hx = 0x00100000 | (0x000fffff & hx);
    else {
        n = -1022 - ix;
        if (n <= 31) {
            hx = (hx << n) | (lx >> (32 - n));
            lx <<= n;
        } else {
            hx = lx << (n - 32);
            lx = 0;
        }
    }
    if (iy >= -1022)
        hy = 0x00100000 | (0x000fffff & hy);
    else {
        n = -1022 - iy;
        if (n <= 31) {
            hy = (hy << n) | (ly >> (32 - n));
            ly <<= n;
        } else {
            hy = ly << (n - 32);
            ly = 0;
        }
    }

    n = ix - iy;
    while (n--) {
        hz = hx - hy;
        lz = lx - ly;
        if (lx < ly)
            hz -= 1;
        if (hz < 0) {
            hx = hx + hx + (lx >> 31);
            lx = lx + lx;
        } else {
            if ((hz | lz) == 0)
                return fmod_Zero[(unsigned)sx >> 31];
            hx = hz + hz + (lz >> 31);
            lx = lz + lz;
        }
    }
    hz = hx - hy;
    lz = lx - ly;
    if (lx < ly)
        hz -= 1;
    if (hz >= 0) {
        hx = hz;
        lx = lz;
    }

    if ((hx | lx) == 0)
        return fmod_Zero[(unsigned)sx >> 31];
    while (hx < 0x00100000) {
        hx = hx + hx + (lx >> 31);
        lx = lx + lx;
        iy -= 1;
    }
    if (iy >= -1022) {
        hx = ((hx - 0x00100000) | ((iy + 1023) << 20));
        *(int *)&x = hx | sx;
        *(1 + (unsigned *)&x) = lx;
    } else {
        n = -1022 - iy;
        if (n <= 20) {
            lx = (lx >> n) | ((unsigned)hx << (32 - n));
            hx >>= n;
        } else if (n <= 31) {
            lx = ((unsigned)hx << (32 - n)) | (lx >> n);
            hx = sx;
        } else {
            lx = hx >> (n - 32);
            hx = sx;
        }
        *(int *)&x = hx | sx;
        *(1 + (unsigned *)&x) = lx;
    }
    return x;
}

f64 fn_802360C4(f64 farg0, f64 farg1) {
    f64 fn_80238A9C(f64, f64);
    f64 fn_80238378(s32, f64);
    extern f64 lbl_80282CD0[];
    extern f32 lbl_80367068;
    extern s32 errno;
    extern f64 lbl_8036BEA8;
    extern f64 lbl_8036BEB0;
    extern f64 lbl_8036BEB8;
    f64 x;
    f64 y;
    s32 hx, hy, ix, iy;

    x = farg0;
    y = farg1;
    hx = ((s32 *)&x)[0];
    hy = ((s32 *)&y)[0];
    ix = hx & 0x7FFFFFFF;
    iy = hy & 0x7FFFFFFF;
    if (((iy | ((s32 *)&y)[1]) == 0)) {
        return lbl_8036BEA8;
    }
    if (ix > 0x7FF00000 || (ix == 0x7FF00000 && ((s32 *)&x)[1] != 0) ||
        iy > 0x7FF00000 || (iy == 0x7FF00000 && ((s32 *)&y)[1] != 0)) {
        return x + y;
    }
    (void)lbl_80282CD0;
    (void)lbl_80367068;
    (void)errno;
    (void)lbl_8036BEB0;
    (void)lbl_8036BEB8;
    (void)fn_80238A9C;
    (void)fn_80238378;
    return x;
}

f64 fn_802380A8(f64 farg0, f64 farg1) {
    f64 y;
    f64 x;
    x = farg0;
    y = farg1;
    *(u32*)&x = (*(u32*)&x & 0x7FFFFFFF) | (*(u32*)&y & 0x80000000);
    return x;
}

f64 fn_802380D0(f64 x) {
 f64 __kernel_cos(f64, f64);
 f64 fn_80237BDC(f64, f64, s32);
 s32 fn_802368F4(f64 *, f64);
 f64 y[2];
 s32 ix=(*(s32 *)&x)&0x7fffffff;
 if(ix<=0x3fe921fb) return __kernel_cos(x,0.0);
 if(ix>=0x7ff00000) return x-x;
 switch(fn_802368F4(y,x)&3) {
 case 0: return __kernel_cos(y[0],y[1]);
 case 1: return -fn_80237BDC(y[0],y[1],1);
 case 2: return -__kernel_cos(y[0],y[1]);
 default: return fn_80237BDC(y[0],y[1],1);
 }
}

extern f64 __floor_huge;
extern f64 __floor_zero;
f64 floor(f64 x) {
    /* Round double toward -infinity (fdlibm/MSL floor). */
    s32 i0;
    u32 i1;
    s32 j0;
    u32 i;
    u32 j;

    i0 = ((s32 *)&x)[0];
    i1 = ((u32 *)&x)[1];
    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20) {
        if (j0 < 0) {
            if (__floor_huge + x > __floor_zero) {
                if (i0 >= 0) {
                    i1 = 0;
                    i0 = 0;
                } else if (((i0 & 0x7fffffff) | i1) != 0) {
                    i0 = 0xbff00000;
                    i1 = 0;
                }
            }
        } else {
            i = 0x000fffff >> j0;
            if (((i0 & i) | i1) == 0) {
                return x;
            }
            if (__floor_huge + x > __floor_zero) {
                if (i0 < 0) {
                    i0 += 0x00100000 >> j0;
                }
                i0 &= ~i;
                i1 = 0;
            }
        }
    } else if (j0 > 51) {
        if (j0 == 0x400) {
            return x + x;
        }
        return x;
    } else {
        i = 0xffffffffU >> (j0 - 20);
        if ((i1 & i) == 0) {
            return x;
        }
        if (__floor_huge + x > __floor_zero) {
            if (i0 < 0) {
                if (j0 == 20) {
                    i0 += 1;
                } else {
                    j = i1 + (1 << (52 - j0));
                    if (j < i1) {
                        i0 += 1;
                    }
                    i1 = j;
                }
            }
            i1 &= ~i;
        }
    }
    ((s32 *)&x)[0] = i0;
    ((u32 *)&x)[1] = i1;
    return x;
}

extern f64 lbl_8036C148;
#pragma global_optimizer off
f64 fn_802382EC(s32 *arg0, f64 farg0) {
s32 high, magnitude;
u32 low;
high=*(s32*)&farg0;
low=((u32*)&farg0)[1];
*arg0=0;
magnitude=high & 0x7fffffff;
if (magnitude>=0x7ff00000 || (magnitude | low)==0) return farg0;
if (magnitude<0x100000) {
f64 scale = lbl_8036C148;
*arg0=-54;
farg0=farg0*scale;
high=*(s32*)&farg0;
magnitude=high & 0x7fffffff;
}
*arg0 += (magnitude>>20)-0x3fe;
*(s32*)&farg0=(high & 0x800fffff) | 0x3fe00000;
return farg0;
}
#pragma global_optimizer on
extern f64 lbl_8036C150;
extern f64 lbl_8036C158;
extern f64 lbl_8036C160;
extern f64 lbl_8036C168;
extern f64 lbl_8036C170;
f64 fn_80238378(s32 n, f64 x) {
    f64 fn_802380A8();
    f64 classified = x;
    f64 value = x;
    s32 high = ((s32 *)&classified)[0];
    s32 kind;
    s32 exponent;
    u32 low;
    switch (high & 0x7FF00000) {
    case 0x7FF00000:
        if ((high & 0xFFFFF) || ((s32 *)&classified)[1] != 0) kind=1; else kind=2;
        break;
    case 0:
        if ((high & 0xFFFFF) || ((s32 *)&classified)[1] != 0) kind=5; else kind=3;
        break;
    default: kind=4;
    }
    if (kind <= 2 || lbl_8036C150 == x) return x;
    high=((s32 *)&value)[0];
    low=((u32 *)&value)[1];
    exponent=(high >> 20)&0x7FF;
    if (exponent==0) {
        if ((low | (high & 0x7FFFFFFF)) == 0) return x;
        value *= lbl_8036C158;
        high=((s32 *)&value)[0];
        exponent=((high>>20)&0x7FF)-54;
        if (n < -50000) return lbl_8036C160*value;
    }
    if (exponent==0x7FF) return value+value;
    exponent += n;
    if (exponent>0x7FE) return lbl_8036C168*fn_802380A8(lbl_8036C168,value);
    if (exponent>0) {
        ((s32 *)&value)[0]=(high&0x800FFFFF)|(exponent<<20);
        return value;
    }
    if (exponent<=-54) {
        if (n>50000) return lbl_8036C168*fn_802380A8(lbl_8036C168,value);
        return lbl_8036C160*fn_802380A8(lbl_8036C160,value);
    }
    exponent += 54;
    ((s32 *)&value)[0]=(high&0x800FFFFF)|(exponent<<20);
    return lbl_8036C170*value;
}

f64 fn_8023853C(f64 *iptr, f64 x) {
 f64 temp=x;
 u32 hi=((u32 *)&temp)[0];
 u32 lo=((u32 *)&temp)[1];
 s32 exponent=((hi>>20)&0x7ff)-0x3ff;
 s32 mask;
 u32 lowmask;
 if(exponent<20) {
 if(exponent<0) {((u32 *)iptr)[0]=hi&0x80000000; ((u32 *)iptr)[1]=0; return x;}
 mask=0xfffff>>exponent;
 if((lo|(hi&mask))==0) {((u32 *)&temp)[0]=hi&0x80000000; ((u32 *)&temp)[1]=0; *iptr=x; return temp;}
 ((u32 *)iptr)[0]=hi&~mask; ((u32 *)iptr)[1]=0; return x-*iptr;
 }
 if(exponent>51) {((u32 *)&temp)[0]=hi&0x80000000; ((u32 *)&temp)[1]=0; *iptr=x; return temp;}
 lowmask=0xffffffffU>>(exponent-20);
 if((lo&lowmask)==0) {((u32 *)&temp)[0]=hi&0x80000000; ((u32 *)&temp)[1]=0; *iptr=x; return temp;}
 ((u32 *)iptr)[0]=hi; ((u32 *)iptr)[1]=lo&~lowmask; return x-*iptr;
}

#pragma global_optimizer off
/* fdlibm __kernel_cos: cosine on a reduced argument (x, y) with |x| ~<= pi/4. */
f64 __kernel_cos(f64 x, f64 y) {
    extern f64 __kcos_one;
    extern f64 __kcos_C1;
    extern f64 __kcos_C2;
    extern f64 __kcos_C3;
    extern f64 __kcos_C4;
    extern f64 __kcos_C5;
    extern f64 __kcos_C6;
    extern f64 __kcos_half;
    extern f64 __kcos_qx;
    f64 qx;
    f64 xLocal;
    f64 z;
    f64 r;
    s32 ix;

    xLocal = x;
    ix = ((s32 *)&xLocal)[0] & 0x7FFFFFFF;
    if (ix < 0x3E400000) {
        if ((s32)x == 0) {
            return __kcos_one;
        }
    }
    z = xLocal * xLocal;
    r = z * (((((__kcos_C6 * z + __kcos_C5) * z + __kcos_C4) * z + __kcos_C3) * z + __kcos_C2) * z + __kcos_C1);
    if (ix < 0x3FD33333) {
        return __kcos_one - ((__kcos_half * z) - ((z * r) - (xLocal * y)));
    }
    if (ix > 0x3FE90000) {
        qx = __kcos_qx;
    } else {
        ((s32 *)&qx)[0] = ix - 0x00200000;
        ((s32 *)&qx)[1] = 0;
    }
    return (__kcos_one - qx) - (((__kcos_half * z) - qx) - ((z * r) - (xLocal * y)));
}

s32 fn_80236D88(f64 *arg0, f64 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    f64 floor(f64);
    f64 fn_80238378(s32, f64);
    extern s32 lbl_80282E88[];
    extern f64 lbl_80282E98[];
    extern f64 lbl_8036C058;
    extern f64 lbl_8036C060;
    extern f64 lbl_8036C068;
    extern f64 lbl_8036C070;
    extern f64 lbl_8036C078;
    extern f64 lbl_8036C080;
    extern f64 lbl_8036C088;
    extern f64 lbl_8036C090;

    f64 buf198[0x30];
    f64 buf58[0x30];
    f64 bufF8[0x20];
    s32 sp8[0x40];
    s32 n;
    s32 m;
    s32 i;
    s32 j;
    s32 k;
    s32 t;
    s32 sign;
    s32 expn;
    s32 sticky;
    f64 sum;
    f64 y;
    f64 z;
    f64 *p;
    f64 *q;
    s32 *ip;

    n = lbl_80282E88[arg4];
    m = arg3 - 1;
    t = (arg2 - 3) / 24;
    if (t < 0) {
        t = 0;
    }
    expn = arg2 - ((t + 1) * 0x18);
    j = t - m;
    ip = arg5 + j;
    p = buf198;
    for (i = 0; i <= m + n; i++) {
        if (j < 0) {
            *p = lbl_8036C058;
        } else {
            *p = (f64)*ip;
        }
        p++;
        ip++;
        j++;
    }

    q = buf58;
    for (i = 0; i <= n; i++) {
        sum = lbl_8036C058;
        if (m >= 0) {
            for (j = 0; j <= m; j++) {
                sum += arg0[j] * buf198[(m + i) - j];
            }
        }
        *q++ = sum;
    }

    sticky = 0;
    k = n;
    for (;;) {
        y = buf58[k];
        ip = sp8;
        for (i = 0; i < k; i++) {
            z = (f64)(s32)(lbl_8036C060 * y);
            *ip++ = (s32)(-(lbl_8036C068 * z - y));
            y = z + (i + 1 < k ? buf58[k - 1 - i] : lbl_8036C058);
        }
        if (k > 0) {
            /* finish residual */
        }
        y = fn_80238378(expn, 1.0);
        y = y - lbl_8036C070 * floor(lbl_8036C078 * y);
        expn = (s32)y;
        z = y - (f64)expn;
        sign = 0;
        if (expn > 0) {
            /* clipped */
        }
        break;
    }

    *arg1 = buf58[0];
    return expn & 7;
}

f64 fn_80237BDC(f64 x, f64 y, s32 iy) {
    extern f64 lbl_8036C098;
    extern f64 lbl_8036C0A0;
    extern f64 lbl_8036C0A8;
    extern f64 lbl_8036C0B0;
    extern f64 lbl_8036C0B8;
    extern f64 lbl_8036C0C0;
    extern f64 lbl_8036C0C8;
    f64 xLocal;
    f64 z;
    f64 r;
    f64 v;
    s32 ix;

    xLocal = x;
    ix = ((s32 *)&xLocal)[0] & 0x7FFFFFFF;
    if (ix < 0x3E400000) {
        if ((s32)x == 0) {
            return x;
        }
    }
    z = xLocal * xLocal;
    v = z * xLocal;
    r = ((((lbl_8036C0B8 * z + lbl_8036C0B0) * z + lbl_8036C0A8) * z + lbl_8036C0A0) * z + lbl_8036C098);
    if (iy == 0) {
        return xLocal + (v * (lbl_8036C0C0 + z * r));
    }
    return xLocal - ((z * (lbl_8036C0C8 * y - v * r) - y) - lbl_8036C0C0 * v);
}

#pragma global_optimizer reset
f64 sin(f64 x) {
 f64 __kernel_cos(f64, f64);
 f64 fn_80237BDC(f64, f64, s32);
 s32 fn_802368F4(f64 *, f64);
 f64 y[2];
 s32 ix=(*(s32 *)&x)&0x7fffffff;
 if(ix<=0x3fe921fb) return fn_80237BDC(x,0.0,0);
 if(ix>=0x7ff00000) return x-x;
 switch(fn_802368F4(y,x)&3) {
 case 0: return fn_80237BDC(y[0],y[1],1);
 case 1: return __kernel_cos(y[0],y[1]);
 case 2: return -fn_80237BDC(y[0],y[1],1);
 default: return -__kernel_cos(y[0],y[1]);
 }
}

  extern f64 lbl_8036C180;
  extern f64 lbl_80282ED8[];
  extern f64 lbl_8036C0D0;
  extern f64 lbl_8036C0D8;
  extern f64 lbl_8036C0E0;
  extern f64 lbl_8036C0E8;
  extern f64 lbl_8036C0F0;
  extern f64 lbl_8036C0F8;
  extern f64 lbl_8036C100;
extern f64 lbl_80282F40[];
extern f64 lbl_8036C108;
extern f64 lbl_8036C110;
extern f64 lbl_8036C118;
extern f64 lbl_8036C120;
extern f64 lbl_8036C128;

f64 fn_80237C7C(s32 arg0, f64 farg0, f64 farg1) {
    extern f64 lbl_8036C0D0;
    extern f64 lbl_8036C0D8;
    extern f64 lbl_8036C0E0;
    extern f64 lbl_8036C0E8;
    extern f64 lbl_8036C0F0;
    extern f64 lbl_8036C0F8;
    extern f64 lbl_8036C100;
    extern f64 lbl_80282ED8[];
    f64 st[3];
    f64 z;
    f64 w;
    f64 r;
    f64 v;
    f64 s;
    f64 a;
    f64 y;
    f64 *T;
    s32 ix;
    s32 hx;
    s32 sf;

    y = farg1;
    st[0] = farg0;
    hx = ((s32 *)&st[0])[0];
    ix = hx & 0x7FFFFFFF;
    if (ix < 0x3E300000 && (s32)farg0 == 0) {
        if (((arg0 + 1) | (ix | ((s32 *)&st[0])[1])) == 0) {
            farg0 = __fabs(farg0);
            return lbl_8036C0D0 / farg0;
        }
        if (arg0 == 1) {
            return farg0;
        }
        return lbl_8036C0D8 / farg0;
    }
    if (ix >= 0x3FE59428) {
        if (hx < 0) {
            y = -y;
            st[0] = -st[0];
        }
        z = lbl_8036C0E0 - st[0];
        a = lbl_8036C0E8 - y;
        y = lbl_8036C0F0;
        st[2] = z;
        st[0] = z + a;
    }
    T = lbl_80282ED8;
    z = st[0] * st[0];
    w = z * z;
    r = T[1] + w * (T[3] + w * (T[5] + w * (T[7] + w * (T[9] + w * T[11]))));
    v = z * (T[2] + w * (T[4] + w * (T[6] + w * (T[8] + w * (T[10] + w * T[12])))));
    s = z * st[0];
    st[2] = z;
    r = y + z * (s * (r + v) + y);
    r += T[0] * s;
    w = st[0] + r;
    if (ix >= 0x3FE59428) {
        sf = 1 - ((s32)((u32)hx >> 30) & 2);
        v = (f64)arg0;
        a = (f64)sf;
        (void)lbl_8036C100;
        s = w * w;
        z = w + v;
        s = s / z - r;
        return a * (v - lbl_8036C0F8 * (st[0] - s));
    }
    if (arg0 == 1) {
        return w;
    }
    st[2] = w;
    ((s32 *)&st[2])[1] = 0;
    v = r - (st[2] - st[0]);
    a = lbl_8036C0D8 / w;
    st[1] = a;
    ((s32 *)&st[1])[1] = 0;
    s = lbl_8036C0D0 + st[1] * st[2];
    return st[1] + a * (s + st[1] * v);
}

f64 fn_80237E90(f64 farg0) {
    f64 sp8;
    f64 z;
    f64 w;
    f64 s1;
    f64 s2;
    f64 a;
    f64 *aT;
    f64 *atanhi;
    f64 *atanlo;
    s32 hx;
    s32 ix;
    s32 id;

    sp8 = farg0;
    hx = ((s32 *)&sp8)[0];
    ix = hx & 0x7FFFFFFF;
    if (ix >= 0x44100000) {
        if (ix > 0x7FF00000 || (ix == 0x7FF00000 && ((s32 *)&sp8)[1] != 0)) {
            return sp8 + sp8;
        }
        if (hx > 0) {
            return lbl_80282F40[3] + lbl_80282F40[3 + 4];
        }
        return -lbl_80282F40[3] - lbl_80282F40[3 + 4];
    }
    if (ix < 0x3FDC0000) {
        if (ix < 0x3E200000 && (lbl_8036C108 + farg0) > lbl_8036C110) {
            return farg0;
        }
        id = -1;
    } else {
        a = __fabs(farg0);
        sp8 = a;
        if (ix < 0x3FF30000) {
            if (ix < 0x3FE60000) {
                id = 0;
                sp8 = ((lbl_8036C118 * a) - lbl_8036C110) / (lbl_8036C118 + a);
            } else {
                id = 1;
                sp8 = (a - lbl_8036C110) / (lbl_8036C110 + a);
            }
        } else if (ix < 0x40038000) {
            id = 2;
            sp8 = (a - lbl_8036C120) / ((lbl_8036C120 * a) + lbl_8036C110);
        } else {
            id = 3;
            sp8 = lbl_8036C128 / a;
        }
    }
    aT = lbl_80282F40 + 8;
    atanhi = lbl_80282F40;
    atanlo = lbl_80282F40 + 4;
    z = sp8 * sp8;
    w = z * z;
    s1 = z * (aT[0] + w * (aT[2] + w * (aT[4] + w * (aT[6] + w * (aT[8] + w * aT[10])))));
    s2 = w * (aT[1] + w * (aT[3] + w * (aT[5] + w * (aT[7] + w * (aT[9] + w * aT[11])))));
    if (id < 0) {
        return sp8 - (sp8 * (s1 + s2));
    }
    z = atanhi[id] - ((sp8 * (s1 + s2) - atanlo[id]) - sp8);
    if (hx < 0) {
        z = -z;
    }
    return z;
}

  f64 fn_80238710(f64 farg0) {
      f64 sp10[2];
      f64 sp8;
      s32 temp_r3;

      sp8 = farg0;
      temp_r3 = *(s32 *)&sp8 & 0x7FFFFFFF;
      if (temp_r3 <= 0x3FE921FB) {
          return fn_80237C7C(1, farg0, lbl_8036C180);
      }
      if (temp_r3 >= 0x7FF00000) {
          return farg0 - farg0;
      }
      return fn_80237C7C(1 - ((fn_802368F4(sp10, farg0) * 2) & 2), sp10[0], sp10[1]);
  }

void fn_80238788(void) {
    M2C_UNK fn_80235B4C();
    fn_80235B4C();
}

void fn_802387A8(void) {
    M2C_UNK __ieee754_fmod();
    __ieee754_fmod();
}

void fmod(void) {
    M2C_UNK fn_802360C4();
    fn_802360C4();
}

f64 fn_802387E8(f64 x) {
    extern s32 errno;
    extern f64 lbl_8036C188;
    u32 r;
    u32 s1;
    u32 q1;
    u32 q0;
    u32 s0;
    u32 t1;
    u32 t;
    u32 t2;
    s32 m;
    s32 ix0;
    s32 pad;
    s32 i;
    u32 ix1;
    f64 z;

    ix0 = ((s32 *)&x)[0];
    ix1 = ((u32 *)&x)[1];
    pad = 0;

    if ((u32)((ix0 & 0x7FF00000) + 0x80100000) == 0U) {
        errno = 0x21;
        return x * x + x;
    }
    if (ix0 <= 0) {
        if ((ix1 | (ix0 & 0x7FFFFFFF)) == 0) {
            return x;
        }
        if (ix0 < 0) {
            f32 *nanp = (f32 *)0x80367068;
            errno = 0x21;
            return *nanp;
        }
    }

    m = ix0 >> 20;
    if (m == 0) {
        goto denorm_check;
    denorm_shift:
        t = ix1 >> 11;
        ix1 <<= 21;
        ix0 |= (s32)t;
        m -= 0x15;
    denorm_check:
        if (ix0 == 0) {
            goto denorm_shift;
        }
        i = 0;
        goto denorm_bit_check;
    denorm_bit_shift:
        ix0 <<= 1;
        i += 1;
    denorm_bit_check:
        if ((ix0 & 0x100000) == 0) {
            goto denorm_bit_shift;
        }
        t = ix1 >> (32 - i);
        ix1 <<= i;
        m -= i - 1;
        ix0 |= (s32)t;
    }

    t = (u32)(m - 0x3FF);
    r = (u32)(ix0 & 0xFFFFF) | 0x100000;
    if (t & 1) {
        t = ix1 >> 31;
        ix1 += ix1;
        t = t + r;
        r = r + t;
    }
    t = ix1 >> 31;
    ix1 += ix1;
    t = t + r;
    s1 = 0;
    r = r + t;
    s0 = 0;
    q1 = 0;
    q0 = 0;
    t1 = 0x200000;
    goto loop1_check;
 loop1:
    t = s0 + t1;
    if ((s32)t <= (s32)r) {
        s0 = t + t1;
        r = r - t;
        q0 = q0 + t1;
    }
    t = ix1 >> 31;
    ix1 += ix1;
    t = t + r;
    t1 >>= 1;
    r = r + t;
 loop1_check:
    if (t1 != 0) {
        goto loop1;
    }

    t1 = 0x80000000;
    goto loop2_check;
 loop2:
    t = s0;
    t2 = s1 + t1;
    if ((s32)s0 < (s32)r) {
        goto loop2_take;
    }
    if (s0 != r) {
        goto loop2_skip;
    }
    if (t2 > ix1) {
        goto loop2_skip;
    }
 loop2_take:
    s1 = t2 + t1;
    if ((u32)((t2 & 0x80000000) + 0x80000000) == 0U && (s1 & 0x80000000) == 0) {
        s0 = s0 + 1;
    }
    r = r - t;
    if (ix1 < t2) {
        r = r - 1;
    }
    ix1 = ix1 - t2;
    q1 = q1 + t1;
 loop2_skip:
    t = ix1 >> 31;
    ix1 += ix1;
    t = t + r;
    t1 >>= 1;
    r = r + t;
 loop2_check:
    if (t1 != 0) {
        goto loop2;
    }

    if ((r | ix1) != 0) {
        z = lbl_8036C188;
        z = lbl_8036C188;
        if ((u32)(q1 + 0x10000) == 0xFFFFU) {
            q1 = 0;
            q0 = q0 + 1;
        } else {
            q1 = q1 + (q1 & 1);
        }
    }

    {
        s32 q0_odd = (s32)(q0 & 1);
        s32 hi = (s32)(q0 >> 1);
        u32 lo = q1 >> 1;
        hi += 0x3FE00000;
        if (q0_odd == 1) {
            lo |= 0x80000000;
        }
        ((u32 *)&z)[1] = lo;
        hi += ((m - 0x3FF) >> 1) << 20;
        ((s32 *)&z)[0] = hi + pad;
    }
    return z;
}

f32 fn_80238A0C(void) {
    f64 fn_80238710();
    return (f32) fn_80238710();
}

f32 sinf(void) {
    f64 sin();
    return (f32) sin();
}

f32 cosf(void) {
    f64 fn_802380D0();
    return (f32) fn_802380D0();
}

f32 acosf(void) {
    f64 fn_80238788();
    return (f32) fn_80238788();
}

f64 fn_80238A9C(f64, f64) {
    M2C_UNK fn_802387E8();
    fn_802387E8();
}

void fn_80238ABC(void) {
    M2C_UNK fn_8023108C();
    fn_8023108C();
}

u8 *fn_80238ADC(u8 *arg0) { extern u16 lbl_8029E9A8[256]; u8 *table=(u8*)lbl_8029E9A8; s32 tmp; s32 c; u8 *p=arg0; goto check; do { tmp=(s8)c; if (tmp == -1) tmp=-1; else tmp=table[(u8)tmp]; *p++=(u8)tmp; check: c=*p; } while ((s8)c != 0); return arg0; }

s32 Hu_IsStub(void) {
    return 0;
}

extern u16 Ecb_8033E188[];

extern u16 Ecb_8033E188[192];
int fn_802368F4(f64 *y, f64 x) {
    int fn_80236D88();
    extern f64 lbl_8036BFB8;
    extern f64 lbl_8036BFC0;
    extern f64 lbl_8036BFC8;
    extern f64 lbl_8036BFD0;
    extern f64 lbl_8036BFD8;
    extern f64 lbl_8036BFE0;
    extern f64 lbl_8036BFE8;
    extern f64 lbl_8036BFF0;
    extern f64 lbl_8036BFF8;
    extern f64 lbl_8036C000;
    extern f64 lbl_8036C008;
    extern s32 lbl_80282E08[];
    extern s32 lbl_80282D00[];
    f64 z, w, t, r, fn;
    f64 pio2_1, pio2_1t, pio2_2, pio2_2t;
    f64 tx[3];
    int e0, i, j, nx, n, ix, hx;

    hx = *(int *)&x;
    ix = hx & 0x7fffffff;
    if (ix <= 0x3fe921fb) {
        y[0] = x;
        y[1] = lbl_8036BFB8;
        return 0;
    }
    if (ix < 0x4002d97c) {
        if (hx > 0) {
            z = x - lbl_8036BFC0;
            if ((unsigned)(ix - 0x3ff90000) != 0x21fbU) {
                pio2_1t = lbl_8036BFC8;
                y[0] = z - pio2_1t;
                y[1] = (z - y[0]) - pio2_1t;
            } else {
                pio2_2 = lbl_8036BFD0;
                pio2_2t = lbl_8036BFD8;
                z -= pio2_2;
                y[0] = z - pio2_2t;
                y[1] = (z - y[0]) - pio2_2t;
            }
            return 1;
        } else {
            z = lbl_8036BFC0 + x;
            if ((unsigned)(ix - 0x3ff90000) != 0x21fbU) {
                pio2_1t = lbl_8036BFC8;
                y[0] = pio2_1t + z;
                y[1] = pio2_1t + (z - y[0]);
            } else {
                pio2_2 = lbl_8036BFD0;
                pio2_2t = lbl_8036BFD8;
                z += pio2_2;
                y[0] = pio2_2t + z;
                y[1] = pio2_2t + (z - y[0]);
            }
            return -1;
        }
    }
    if (ix <= 0x413921fb) {
        t = __fabs(x);
        n = (int)(lbl_8036BFE8 * t + lbl_8036BFE0);
        {
            int hi = 0x43300000;
            int lo = n ^ 0x80000000;
            *(int *)&fn = hi;
            *((int *)&fn + 1) = lo;
            fn = fn - lbl_8036C008;
        }
        pio2_1 = lbl_8036BFC0;
        pio2_1t = lbl_8036BFC8;
        r = t - pio2_1 * fn;
        w = pio2_1t * fn;
        if (n < 32 && ix != lbl_80282E08[n - 1]) {
            y[0] = r - w;
        } else {
            j = ix >> 20;
            y[0] = r - w;
            i = j - (((*(int *)&y[0]) >> 20) & 0x7ff);
            if (i > 16) {
                t = r;
                w = fn * lbl_8036BFD0;
                r = t - w;
                w = fn * lbl_8036BFD8 - ((t - r) - w);
                y[0] = r - w;
                i = j - (((*(int *)&y[0]) >> 20) & 0x7ff);
                if (i > 49) {
                    t = r;
                    w = fn * lbl_8036BFF0;
                    r = t - w;
                    w = fn * lbl_8036BFF8 - ((t - r) - w);
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (hx < 0) {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        }
        return n;
    }
    if (ix >= 0x7ff00000) {
        y[0] = x - x;
        y[1] = x - x;
        return 0;
    }
    e0 = (ix >> 20) - 1046;
    *(int *)&z = ix - (e0 << 20);
    *(1 + (unsigned *)&z) = *(1 + (unsigned *)&x);
    for (i = 0; i < 2; i++) {
        tx[i] = (double)((int)(z));
        z = (z - tx[i]) * lbl_8036C000;
    }
    tx[2] = z;
    nx = 3;
    while (tx[nx - 1] == lbl_8036BFB8)
        nx--;
    n = fn_80236D88(tx, y, e0, nx, 2, lbl_80282D00);
    if (hx < 0) {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}
