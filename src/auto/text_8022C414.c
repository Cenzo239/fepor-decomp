// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

#pragma use_lmw_stmw on
void *fn_8022C414(void *arg0, void (*ctor)(void *, int), void (*dtor)(void *, int), s32 size, u32 count) {
    volatile struct {
        void *base;
        s32 size;
        u32 count;
        void (*dtor)(void *, int);
        u32 constructed;
    } guard;
    void *p;
    u32 n;

    if (arg0 != NULL) {
        ((s32 *)arg0)[0] = size;
        ((u32 *)arg0)[1] = count;
        arg0 = (u8 *)arg0 + 16;
        if (ctor != NULL) {
            p = arg0;
            guard.constructed = count;
            guard.base = arg0;
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
    }
    return arg0;
}
