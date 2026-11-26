// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"
#include "common.h"
extern u8 lbl_80285050[];
extern u8 lbl_802EFCB8[];
extern u8 lbl_80285424[];
extern u8 lbl_80285458[];
extern u8 lbl_80367278;
void Item_Destroy(void);

struct Record {
    void *data;
    void *volatile table;
};

#pragma global_optimizer off

#pragma opt_propagation off
void fn_80033080(void) {
#pragma opt_propagation off
    typedef struct {
        u8 pad[4];
        void *volatile table;
    } Record;

    void *Item_Init(void *);
    void Item_Destroy(void);
    void __register_global_object(void *, void (*)(void), void *);

    extern u8 lbl_80285050[];
    extern u8 lbl_802EFCB8[];
    extern u8 lbl_80285424[];
    extern u8 lbl_80285458[];
    extern u8 lbl_80367278;

    u8 *base;
    register Record *slot0;
    register Record *slot1;
    void *table;
    void *lastTable;

    table = lbl_80285050;
    base = lbl_802EFCB8;
    lastTable = lbl_80285424;

    slot1 = (Record *)(base + 0xC);
    slot1->table = table;
    slot0 = (Record *)base;
    slot0->table = table;

    table = lbl_80285458;
    slot1->table = table;
    slot0->table = table;
    slot1->table = lastTable;

    __register_global_object(Item_Init(&lbl_80367278), Item_Destroy,
                             base + 0xDC);
#pragma opt_propagation reset
}
#pragma opt_propagation reset
#pragma global_optimizer reset
