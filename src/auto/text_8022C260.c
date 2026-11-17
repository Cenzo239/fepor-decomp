// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

void fn_8022C260(void *base, void (*ctor)(void *, int), void (*dtor)(void *, int), u32 size, u32 count) {
    volatile struct {
        void *base;
        u32 size;
        u32 count;
        void (*dtor)(void *, int);
        u32 constructed;
    } guard;
    void *p;
    u32 n;

    p = base;
    guard.constructed = count;
    guard.base = base;
    guard.size = size;
    guard.count = count;
    guard.dtor = dtor;
    guard.constructed = 0;
    goto loop_test;
loop_body:
    ctor(p, 1);
    p = (char *)p + size;
    guard.constructed = guard.constructed + 1;
loop_test:
    n = guard.constructed;
    if (n < count) {
        goto loop_body;
    }
    if (n < guard.count) {
        if (guard.dtor != 0) {
            u32 s = guard.size;
            p = (char *)guard.base + s * n;
            goto destroy_test;
        destroy_body:
            p = (char *)p - guard.size;
            ((void (*)(void *, int))guard.dtor)(p, -1);
            guard.constructed = guard.constructed - 1;
        destroy_test:
            if (guard.constructed != 0) {
                goto destroy_body;
            }
        }
    }
}
