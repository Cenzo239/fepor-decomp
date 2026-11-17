// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

void *dtor_8022C35C(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    u32 count;
    u32 capacity;
    u32 elemSize;
    void *base;
    void *ptr;

    if (arg0 != NULL) {
        count = *(u32 *)((char *)arg0 + 0x10);
        capacity = *(u32 *)((char *)arg0 + 0x8);
        if (count < capacity) {
            if (*(u32 *)((char *)arg0 + 0xC) != 0) {
                elemSize = *(u32 *)((char *)arg0 + 0x4);
                base = *(void **)arg0;
                ptr = (char *)base + elemSize * count;
                goto check;
            loop:
                elemSize = *(u32 *)((char *)arg0 + 0x4);
                ptr = (char *)ptr - elemSize;
                ((void (*)(void *, s32))(*(u32 *)((char *)arg0 + 0xC)))(ptr, -1);
                *(u32 *)((char *)arg0 + 0x10) = *(u32 *)((char *)arg0 + 0x10) - 1;
            check:
                if (*(u32 *)((char *)arg0 + 0x10) != 0) {
                    goto loop;
                }
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}
