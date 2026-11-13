#ifndef PROCESS_H
#define PROCESS_H

#include "common.h"

/* Cooperative process node (pool entry size 0x70). Tree via child/next; sibling list via prev/next. */
typedef struct Process {
    void *code;                          /* +0x00 */
    void *unk_04;                        /* +0x04 */
    void (*destructor)(struct Process *); /* +0x08 */
    void (*unk_0C)(struct Process *);    /* +0x0C */
    void (*func)(struct Process *);      /* +0x10 */
    void *unk_14;                        /* +0x14 */
    struct Process *parent;              /* +0x18 */
    struct Process *child;               /* +0x1C */
    struct Process *prev;                /* +0x20 */
    struct Process *next;                /* +0x24 */
    s16 timer;                           /* +0x28 */
    u8 unk_2A;
    u8 unk_2B;
    u8 flags;                            /* +0x2C: bit0 ended, bit1 counted in parent->lock_cnt */
    u8 lock_cnt;                         /* +0x2D */
    u8 pause;                            /* +0x2E */
    u8 pad_2F;
    u8 pad_30[0x40];                     /* remainder to 0x70 */
} Process;

#define PROCESS_FLAG_ENDED  0x01
#define PROCESS_FLAG_LOCKED 0x02

#endif
