/* Functions from 0x801EAA2C to 0x801F18D4, found by decomp-toolkit. */
#include "common.h"


static inline void Map_UpdateCursorMoveLimit(void) {
    extern s8 lbl_80368374;
    extern void *lbl_80368370, *gPadInput;
    extern s32 gUiInputFlags;
    void *Map_GetCursorUnit(void);
    void Map_HideMoveLimitView(void);
    void Map_ShowMoveLimitView(void);
    void Map_SetupUnitMoveLimit(void *);
    void *unit2;
    u8 skip;
    u32 gflags;
    if (lbl_80368374 == 0) {
        lbl_80368370 = NULL;
        lbl_80368374 = 1;
    }
    unit2 = Map_GetCursorUnit();
    if (unit2 == NULL && (gUiInputFlags & 0x400)) {
        Map_HideMoveLimitView();
    }
    skip = 0;
    gflags = gUiInputFlags;
    if ((gflags & 0x10) && !(gflags & 0x20)) {
        skip = 1;
    }
    if ((skip != 0) ||
        ((!( *(u32 *)((u8 *)gPadInput + 4) & 0xF)) &&
         ((s8)(*(u8 **)gPadInput)[2] == 0) &&
         ((s8)(*(u8 **)gPadInput)[3] == 0))) {
        if ((lbl_80368370 != unit2) || !(gflags & 0x400)) {
            lbl_80368370 = unit2;
            if ((unit2 == NULL) || (*(u8 *)(*(u8 **)((u8 *)unit2 + 0x190) + 8) == 0)) {
                if (gflags & 0x400) {
                    Map_HideMoveLimitView();
                }
            } else {
                Map_SetupUnitMoveLimit(unit2);
                Map_ShowMoveLimitView();
            }
        }
    }

}
typedef struct AramSlot {
    u8 unk_00[0x20];
    void *cbArg;              /* 0x20 */
    void *cbData;             /* 0x24 */
    char name[0x2B];          /* 0x28 */
    u8 flags;                 /* 0x53 */
    u32 nameHash;             /* 0x54 */
    s32 tick;                 /* 0x58 */
    struct AramSlot *prev;    /* 0x5C */
    struct AramSlot *next;    /* 0x60 */
    s32 size;                 /* 0x64 */
    u32 addr;                 /* 0x68 */
} AramSlot;
typedef AramSlot AramAllocSlot;
static inline void *AramCache_InsertUsed(void *best, void *alloc_list) {
    void *insert_prev;
    void *iter;
    insert_prev = 0;
    iter = alloc_list;
    while (iter != 0) {
    if (insert_prev != 0) {
        if (((AramAllocSlot *)best)->addr <= ((AramAllocSlot *)insert_prev)->addr) {
            goto ins_a;
        }
    }
    if (iter == 0) {
        break;
    }
    if (((AramAllocSlot *)iter)->addr > ((AramAllocSlot *)best)->addr) {
        goto ins_d;
    }
ins_a:
    insert_prev = iter;
    iter = ((AramAllocSlot *)iter)->next;
    }
ins_d:
    ((AramAllocSlot *)best)->next = iter;
    ((AramAllocSlot *)best)->prev = insert_prev;
    if (iter != 0) {
        ((AramAllocSlot *)iter)->prev = best;
    }
    if (insert_prev != 0) {
        ((AramAllocSlot *)insert_prev)->next = best;
    }
    if (insert_prev != 0) return alloc_list;
    return best;
}
static inline void AramCache_ReplaceSlot(AramAllocSlot *cell, AramAllocSlot *best, u32 rem, s32 size) {
    extern void *gAramFreeList;
    cell->size = rem;
    cell->addr = best->addr + size;
    cell->prev = best->prev;
    cell->next = best->next;
    if (cell->next) cell->next->prev = cell;
    if (cell->prev) cell->prev->next = cell;
    else gAramFreeList = cell;
}
static inline void *AramCache_UnlinkSlot(void *head, AramAllocSlot *node) {
    AramAllocSlot *prev;
    AramAllocSlot *next = node->next;
    if (next) next->prev = node->prev;
    prev = node->prev;
    if (prev) {
        prev->next = node->next;
        return head;
    }
    return node->next;
}
static inline void *AramCache_FindUnusedSlot(void *pool) {
    u8 *p = pool;
    s32 i;
    for (i = 255; i >= 0; i--, p += 0x6C) {
        if (*(s32 *)(p + 0x64) == 0) return p;
    }
    return 0;
}
static inline void Fx_801EDFCC_Body(void *p) {
    void fn_80146AF0(void);
    void Fx_FadeIn(void *, s32);
    void fn_8014876C(void *, s32, s32);
    s32 i;
    for (i = 0; i < 1; i++) {
        fn_80146AF0();
        Fx_FadeIn(p, 0x3E8);
        fn_8014876C(p, 0x64, 0x3E8);
    }
}

typedef struct CameraAnimVec { f32 x, y, z; } CameraAnimVec;
typedef struct CameraAnimState { CameraAnimVec eye, target; f32 zoom; } CameraAnimState;
typedef struct CameraAnimProc {
    u8 pad[0x34]; void *anim;
    CameraAnimState *prev, *current, *next, *future;
    u16 index, count, duration, elapsed;
} CameraAnimProc;

typedef struct String {
    u32 size;
    u32 cap;
    char *data;
} String;

typedef struct Unk5C {
    void *unk0;
    void *unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
    u8 unk21;
    s16 unk22;
    s16 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    u8 unk4C;
    s16 unk4E;
    s16 unk50;
    s16 unk52;
    s16 unk54;
    s32 unk58;
} Unk5C;

/* 0x6C-byte ARAM file-cache slot. */


static inline void AramCache_ClearUnusedSlots(void *pool) {
    s32 empty;
    u32 flags;
    AramSlot *scan;
    s32 j;
    scan = (AramSlot *)pool;
    empty = 0;
    for (j = 0; j < 256; scan++, j++) {
        flags = scan->flags;
        if (flags & 1) scan->flags = flags & ~1;
        else { scan->size = empty; scan->flags = empty; }
    }
}
static inline void AramCache_ClearAllSlots(void *pool) {
    AramSlot *scan;
    s32 j;
    scan = (AramSlot *)pool;
    for (j = 0; j < 256; scan++, j++) {
        scan->size = 0;
        scan->flags = 0;
    }
}
static inline void *AramFindFreeSlot(void) {
    extern u8 gAramSlotPool[];
    u8 *slot = gAramSlotPool;
    s32 i;
    for (i=255; i>=0; i--, slot+=0x6C) {
        if (*(s32 *)(slot+0x64) == 0) return slot;
    }
    return 0;
}

void fn_801EAA2C(s8 *arg0) {
    *arg0 = -1;
}

void fn_801EAA38(s32 arg0) {
    void Msg_Expand(void *);
    void Ui_CreateMenu(void *, s32, s32);
    void *fn_8013BFFC(void);
    extern char lbl_8027EE08[];
    void *tmp;

    Msg_Expand(lbl_8027EE08 + 0x12b);
    tmp = fn_8013BFFC();
    *((u8 *)tmp + 0x24) = 1;
    Ui_CreateMenu(tmp, arg0, 0);
}

extern u16 Proc_BMapAuxiliary[10];
s32 fn_801EAA88(void) {
    return Process_Find(&Proc_BMapAuxiliary) != 0;
}

/* Create BMapAuxiliaryProc with name; child of parent if non-NULL. Requires units on list 5. */
void *BMapAuxiliary_Create(char *name, void *parent) {
    extern u8 gUnitLists[];
    extern char lbl_8027EE08[];
    s32 fn_80015680(void *);
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, void *);
    void fn_801403F0(void *);
    void String_Init(void *, char *, void *);
    void String_AssignCStr(void *, char *, s32);
    s32 strlen(char *);
    void *obj;
    s32 len;
    s32 sp8;

    if (fn_80015680(gUnitLists + 0x3C) == 0) {
        return NULL;
    }

    if (parent != NULL) {
        obj = Process_CreateChild(Proc_BMapAuxiliary, parent);
    } else {
        obj = Process_Create(Proc_BMapAuxiliary, parent);
    }

    if (obj != NULL) {
        fn_801403F0(obj);
        String_Init((u8 *)obj + 0x40, lbl_8027EE08 + 0x147, &sp8);
        *(s32 *)((u8 *)obj + 0x4C) = 0;
    }

    len = strlen(name);
    String_AssignCStr((u8 *)obj + 0x40, name, len);
    return obj;
}

#pragma global_optimizer off
s32 fn_801EAB90(s32 unused, void *obj) {
    extern u8 gUnitLists[];
    extern s32 gTargetList[];
    u32 flags;
    u32 node;
    s32 count;
    u32 nf;
    s32 ret;

    ret = 0;
    flags = *(u32 *)((u8 *)obj + 0x1A0);
    if (flags & 0x400000) {
        *(u32 *)((u8 *)obj + 0x1A0) = flags & ~0x400000;
        return 1;
    }
    if (flags & 0x200000) {
        return 0;
    }
    count = 0;
    node = *(u32 *)(gUnitLists + 0x3C);
    while (node != 0) {
        nf = *(u32 *)(node + 0x1A0);
        node = *(u32 *)(node + 0x184);
        if (nf & 0x400000) {
            count += 1;
        }
    }
    if (count < gTargetList[0]) {
        *(u32 *)((u8 *)obj + 0x1A0) |= 0x400000;
        ret = 1;
    }
    return ret;
}
#pragma global_optimizer on
void fn_801EAC14(void *arg0) {
    M2C_UNK Process_Goto(void *, u8);
    Ui_DecBusy();
    Process_Goto(arg0, M2C_FIELD(arg0, u8 *, 0x54));
}

void fn_801EAC4C(s32 arg0) {
    extern s32 gUiContext[];
    
    void fn_8013FED0(void);
    void fn_8007D064(s32, s32, s32);

    fn_8013FED0();
    fn_8007D064(gUiContext[0], arg0, 0);
}

void fn_801EAC90(void *arg0) {
extern u8 lbl_8028FDB0[],lbl_80292230[],lbl_80293C84[],lbl_80293C58[],lbl_8027EE08[];
extern f32 lbl_8036B780;
void *Heap_Alloc(s32); void String_AssignCStr(void*,void*,s32); s32 strlen(const char*);
void Ui_AddChild(void*,void*); void *Ui_FindChild(void*,s32,s32);
void Process_RetreatStep(void*); void Process_ClearFunc(void*);
Unk5C *temp_r3;
Unk5C *child;
s32 len;
extern u8 gUiContext[];
void Process_Goto(void*,s32); void fn_801EBE88(void);
switch(gUiContext[8]) {
case 0x81: Process_Goto(arg0,11); break;
default:
Process_RetreatStep(*(void**)((u8*)arg0+0x50));
temp_r3=Heap_Alloc(0x5c);
if(temp_r3) {
        temp_r3->unk0 = lbl_8028FDB0;
        temp_r3->unk4 = NULL;
        temp_r3->unk0 = lbl_80292230;
        temp_r3->unk8 = -1;
        temp_r3->unkA = 0;
        temp_r3->unkC = 0x190;
        temp_r3->unkE = 0x260;
        temp_r3->unk10 = 0x1c0;
        temp_r3->unk12 = 0;
        temp_r3->unk14 = 0;
        temp_r3->unk16 = 0x260;
        temp_r3->unk18 = 0x30;
        temp_r3->unk1A = 0;
        temp_r3->unk1C = 0;
        temp_r3->unk1E = 0xff;
        temp_r3->unk1F = 0xff;
        temp_r3->unk20 = 0xff;
        temp_r3->unk21 = 0xff;
        temp_r3->unk22 = 0x316;
        temp_r3->unk24 = 0;
        temp_r3->unk28 = 0.0f;
        temp_r3->unk2C = 0.0f;
        temp_r3->unk30 = 0.0f;
        temp_r3->unk34 = 0;
        temp_r3->unk38 = 0;
        temp_r3->unk0 = lbl_80293C84;
        temp_r3->unk3C = 0;
        temp_r3->unk40 = 0;
        temp_r3->unk44 = 0;
        temp_r3->unk40 = 0;
        temp_r3->unk48 = 0;
        temp_r3->unk4C = 1;
        temp_r3->unk4E = 0;
        temp_r3->unk50 = 0;
        temp_r3->unk52 = 0;
        temp_r3->unk54 = 0;
        temp_r3->unk0 = lbl_80293C58;
        temp_r3->unk58 = 1;
        temp_r3->unk4E = 0x30;
        temp_r3->unk52 = 0x30;

}
temp_r3->unk8=-0x1000;
temp_r3->unk48=1;
len=strlen((const char*)lbl_8027EE08+0x147);
String_AssignCStr(&temp_r3->unk3C,lbl_8027EE08+0x147,len);
temp_r3->unk34|=0x10;
temp_r3->unk58=1;
Ui_AddChild(arg0,temp_r3);
child=Ui_FindChild(arg0,-0x1000,0);
if(child) child->unk58=0;
fn_801EBE88();
Process_ClearFunc(arg0);
}
}

void fn_801EAE68(void *arg0) {
    void fn_8012C788(void *, void *);
    void Process_AdvanceStep(s32);
    s32 Ui_FindChild(void *, s32, s32);
    void Ui_RemoveChild(void *, s32);
    void fn_801EAB90(void);
    s32 tmp;

    fn_8012C788((void *)fn_801EAB90, arg0);
    Process_AdvanceStep(*(s32 *)((u8 *)arg0 + 0x50));
    tmp = Ui_FindChild(arg0, -0x1000, 0);
    if (tmp != 0) {
        Ui_RemoveChild(arg0, tmp);
    }
}

void fn_801EAEC8(void *arg0) {
    void EventLock_Dec(void);
    void Process_Goto(void *, s32);
    extern u8 gUiContext[];

    EventLock_Dec();
    switch ((s32)gUiContext[8]) {
    case 0x81:
        Process_Goto(arg0, 0xB);
        return;
    case 0x80:
        Process_Goto(arg0, *(u8 *)((u8 *)arg0 + 0x54));
        return;
    }
}

void fn_801EAF34(s32 arg0) {
    void Msg_Expand(void *);
    void EventLock_Inc(void);
    void Ui_CreateMenu(void *, s32, s32);
    void *fn_8013BFFC(void);
    u32 Ui_FindChild(s32, s32, s32);
    void Ui_SetWidgetText(u32, void *);
    void fn_801EB98C(void);
    extern char lbl_8027EE08[];
    void *tmp;
    u32 result;

    fn_801EB98C();
    EventLock_Inc();
    Msg_Expand(lbl_8027EE08 + 0x12B);
    tmp = fn_8013BFFC();
    *((u8 *)tmp + 0x24) = 1;
    Ui_CreateMenu(tmp, arg0, 0);
    result = Ui_FindChild(arg0, -0x1000, 0);
    if (result != 0) {
        Ui_SetWidgetText(result, lbl_8027EE08 + 0x148);
    }
}

void fn_801EAFB4(s32 arg0) {
    M2C_UNK Process_ClearFunc(s32);
    M2C_UNK fn_800A8400();
    Ui_DecBusy();
    fn_800A8400();
    Process_ClearFunc(arg0);
}

void fn_801EAFEC(s32 arg0) {
    M2C_UNK fn_8013FED0();
    M2C_UNK fn_801AA120(s32);
    fn_8013FED0();
    fn_801AA120(arg0);
}

void fn_801EB020(s32 arg0) {
    M2C_UNK Process_ClearFunc(s32);
    M2C_UNK fn_800A8400();
    Ui_DecBusy();
    fn_800A8400();
    Process_ClearFunc(arg0);
}

void fn_801EB058(s32 arg0) {
    M2C_UNK fn_8013FED0();
    M2C_UNK fn_8016B730(s32);
    fn_8013FED0();
    fn_8016B730(arg0);
}

void fn_801EB08C(void *arg0) {
extern u8 lbl_8028FDB0[],lbl_80292230[],lbl_80293C84[],lbl_80293C58[],lbl_8027EE08[];
extern f32 lbl_8036B780;
void *Heap_Alloc(s32); void String_AssignCStr(void*,void*,s32); s32 strlen(const char*);
void Ui_AddChild(void*,void*); void *Ui_FindChild(void*,s32,s32);
void Process_RetreatStep(void*); void Process_ClearFunc(void*);
Unk5C *temp_r3;
Unk5C *child;
s32 len;
temp_r3=Heap_Alloc(0x5c);
if(temp_r3) {
        temp_r3->unk0 = lbl_8028FDB0;
        temp_r3->unk4 = NULL;
        temp_r3->unk0 = lbl_80292230;
        temp_r3->unk8 = -1;
        temp_r3->unkA = 0;
        temp_r3->unkC = 0x190;
        temp_r3->unkE = 0x260;
        temp_r3->unk10 = 0x1c0;
        temp_r3->unk12 = 0;
        temp_r3->unk14 = 0;
        temp_r3->unk16 = 0x260;
        temp_r3->unk18 = 0x30;
        temp_r3->unk1A = 0;
        temp_r3->unk1C = 0;
        temp_r3->unk1E = 0xff;
        temp_r3->unk1F = 0xff;
        temp_r3->unk20 = 0xff;
        temp_r3->unk21 = 0xff;
        temp_r3->unk22 = 0x316;
        temp_r3->unk24 = 0;
        temp_r3->unk28 = 0.0f;
        temp_r3->unk2C = 0.0f;
        temp_r3->unk30 = 0.0f;
        temp_r3->unk34 = 0;
        temp_r3->unk38 = 0;
        temp_r3->unk0 = lbl_80293C84;
        temp_r3->unk3C = 0;
        temp_r3->unk40 = 0;
        temp_r3->unk44 = 0;
        temp_r3->unk40 = 0;
        temp_r3->unk48 = 0;
        temp_r3->unk4C = 1;
        temp_r3->unk4E = 0;
        temp_r3->unk50 = 0;
        temp_r3->unk52 = 0;
        temp_r3->unk54 = 0;
        temp_r3->unk0 = lbl_80293C58;
        temp_r3->unk58 = 1;
        temp_r3->unk4E = 0x30;
        temp_r3->unk52 = 0x30;

}
temp_r3->unk8=-0x1000;
temp_r3->unk48=1;
len=strlen((const char*)lbl_8027EE08+0x147);
String_AssignCStr(&temp_r3->unk3C,lbl_8027EE08+0x147,len);
temp_r3->unk34|=0x10;
temp_r3->unk58=1;
Ui_AddChild(arg0,temp_r3);
child=Ui_FindChild(arg0,-0x1000,0);
if(child) child->unk58=0;
Process_RetreatStep(*(void**)((u8*)arg0+0x50));
Process_ClearFunc(arg0);
}

void fn_801EB23C(void *arg0) {
    M2C_UNK Process_AdvanceStep(s32);
    s32 Ui_FindChild(void *, M2C_UNK, M2C_UNK);
    M2C_UNK Ui_RemoveChild(void *, s32);
    M2C_UNK fn_8016E9DC(void *);
    s32 tmp;

    Process_AdvanceStep(M2C_FIELD(arg0, s32 *, 0x50));
    tmp = Ui_FindChild(arg0, -0x1000, 0);
    if (tmp != 0) {
        Ui_RemoveChild(arg0, tmp);
    }
    fn_8016E9DC(arg0);
}

#pragma push
#pragma optimization_level 3
void fn_801EB294(void *arg0)
{
    void Process_Goto(void *, s32);
    u8 Allegiance_CompareIds(s32, u8);
    void Map_RefreshUnitMap(u8 *);
    void UiCtx_BindUnit(u8 *, void *);
    void Map_HideMoveLimitView(void);
    void Map_ShowMoveLimitView(void);
    void fn_800A8400(void);
    void *Map_GetCursorUnit(void);
    void Map_SetupUnitMoveLimit(void *);
    u32 Ui_FindChild(void *, s32, s32);
    void Ui_PlaySeCue(u8 *, s32);
    void Ui_SetWidgetText(u32, u8 *);
    extern u8 lbl_8027EE08[];
    extern u8 gUnitLists[];
    extern u8 gBattleMap[];
    extern u8 gUiContext[];
    extern s32 gUiInputFlags;
    extern void *gPadInput;
    extern void *lbl_80368370;
    extern s8 lbl_80368374;
    void *unit;
    void *unit2;
    void *next;
    u8 flag;
    u8 skip;
    u32 buttons;
    void *iter;
    u32 flags;
    u32 gflags;
    u32 ret;
    void *self;

    self = arg0;
    unit = Map_GetCursorUnit();
    if (unit != NULL) {
        if (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1) {
            if (!(*(u32 *)((u8 *)unit + 0x1A0) & 0x800)) {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != 0) {
                    Ui_SetWidgetText(ret, lbl_8027EE08 + 0x15b);
                }
            } else {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != 0) {
                    Ui_SetWidgetText(ret, lbl_8027EE08 + 0x171);
                }
            }
        } else {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != 0) {
                Ui_SetWidgetText(ret, lbl_8027EE08 + 0x187);
            }
        }
    } else {
        flag = 0;
        iter = *(void **)(gUnitLists + 0xC);
        while (iter != NULL) {
            flags = *(u32 *)((u8 *)iter + 0x1A0);
            iter = *(void **)((u8 *)iter + 0x184);
            if (flags & 0x800) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != 0) {
                Ui_SetWidgetText(ret, lbl_8027EE08 + 0x19d);
            }
        } else {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != 0) {
                Ui_SetWidgetText(ret, lbl_8027EE08 + 0x1b3);
            }
        }
    }
    if (lbl_80368374 == 0) {
        lbl_80368370 = NULL;
        lbl_80368374 = 1;
    }
    unit2 = Map_GetCursorUnit();
    if (unit2 == NULL && (gUiInputFlags & 0x400)) {
        Map_HideMoveLimitView();
    }
    skip = 0;
    gflags = gUiInputFlags;
    if ((gflags & 0x10) && !(gflags & 0x20)) {
        skip = 1;
    }
    if ((skip != 0) ||
        ((!( *(u32 *)((u8 *)gPadInput + 4) & 0xF)) &&
         ((s8)(*(u8 **)gPadInput)[2] == 0) &&
         ((s8)(*(u8 **)gPadInput)[3] == 0))) {
        if ((lbl_80368370 != unit2) || !(gflags & 0x400)) {
            lbl_80368370 = unit2;
            if ((unit2 == NULL) || (*(u8 *)(*(u8 **)((u8 *)unit2 + 0x190) + 8) == 0)) {
                if (gflags & 0x400) {
                    Map_HideMoveLimitView();
                }
            } else {
                Map_SetupUnitMoveLimit(unit2);
                Map_ShowMoveLimitView();
            }
        }
    }
    skip = 0;
    gflags = gUiInputFlags;
    if ((gflags & 0x10) && !(gflags & 0x20)) {
        skip = 1;
    }
    if (skip == 0) {
        buttons = (u32)gPadInput;
        {
            u32 a = *(u32 *)((u8 *)buttons + 4);
            buttons = a & (*(u32 *)((u8 *)buttons + 8) ^ a);
        }
        if ((unit != NULL) && (buttons & 0x800)) {
            fn_800A8400();
            if (gUiInputFlags & 0x400) {
                Map_HideMoveLimitView();
            }
            UiCtx_BindUnit(gUiContext, unit);
            Ui_PlaySeCue(lbl_8027EE08 + 0x1c9, 0x64);
            *((u8 *)self + 0x54) = 2;
            Process_Goto(self, 0xA);
            return;
        }
        if (buttons & 0x100) {
            if ((unit != NULL) && (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1)) {
                flags = *(u32 *)((u8 *)unit + 0x1A0);
                if (!(flags & 0x800)) {
                    *(u32 *)((u8 *)unit + 0x1A0) = flags | 0x800;
                    Map_RefreshUnitMap(gBattleMap);
                    Map_SetupUnitMoveLimit(unit);
                    Ui_PlaySeCue(lbl_8027EE08 + 0x1d9, 0x64);
                }
            } else {
                goto block_65;
            }
        } else if (buttons & 0x200) {
            if ((unit != NULL) && (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1)) {
                flags = *(u32 *)((u8 *)unit + 0x1A0);
                if (flags & 0x800) {
                    *(u32 *)((u8 *)unit + 0x1A0) = flags & ~0x800;
                    Map_RefreshUnitMap(gBattleMap);
                    Map_SetupUnitMoveLimit(unit);
                    Ui_PlaySeCue(lbl_8027EE08 + 0x1f4, 0x64);
                }
            } else if (unit == NULL) {
                flag = 0;
                iter = *(void **)(gUnitLists + 0xC);
                while (iter != NULL) {
                    flags = *(u32 *)((u8 *)iter + 0x1A0);
                    next = *(void **)((u8 *)iter + 0x184);
                    if (flags & 0x800) {
                        flag = 1;
                        *(u32 *)((u8 *)iter + 0x1A0) = flags & ~0x800;
                    }
                    iter = next;
                }
                if (flag != 0) {
                    Ui_PlaySeCue(lbl_8027EE08 + 0x1f4, 0x64);
                    Map_RefreshUnitMap(gBattleMap);
                }
            }
        } else {
            if (buttons & 0x10) {
            block_65:
                if (gUiInputFlags & 0x400) {
                    Map_HideMoveLimitView();
                }
                Ui_PlaySeCue(lbl_8027EE08 + 0x20f, 0x64);
                Process_Goto(self, 1);
                return;
            }
            if (buttons & 0x1000) {
                if (gflags & 0x400) {
                    Map_HideMoveLimitView();
                }
                *((u8 *)self + 0x54) = 2;
                Process_Goto(self, 5);
            }
        }
    }
}
#pragma pop
void fn_801EB72C(void *arg0) {
    void EventLock_Dec(void);
    void fn_800A8478(void);
    void fn_8018DB4C(void);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_CloseChildAnim(void *, void *, s32);
    extern u8 gEventLockDepth;

    while (gEventLockDepth != 0) {
        EventLock_Dec();
    }
    fn_800A8478();
    fn_8018DB4C();
    if (Ui_FindChild(arg0, 0x40, 0) != NULL) {
        Ui_CloseChildAnim(arg0, Ui_FindChild(arg0, 0x40, 0), 1);
    }
}

void fn_801EB7A8(s32 arg0) {
    void EventLock_Inc(void);
    void fn_800A8450(void);
    void fn_801EB81C(s32);
    void fn_801EB98C(s32);
    u32 Ui_FindChild(s32, s32, s32);
    void Ui_SetWidgetText(u32, u8 *);
    extern u8 gEventLockDepth;
    extern u16 lbl_8027EE08[];
    u32 temp;

    if (gEventLockDepth == 0) {
        EventLock_Inc();
    }
    fn_800A8450();
    fn_801EB81C(arg0);
    fn_801EB98C(arg0);
    temp = Ui_FindChild(arg0, -0x1000, 0);
    if (temp != 0) {
        Ui_SetWidgetText(temp, (u8 *)lbl_8027EE08 + 0x21F);
    }
}

void fn_801EB81C(s32 arg0) {
    void Ui_CreateMenu(void *,s32,s32);
    extern u8 gUiContext[];
    extern u8 gUiMenuDrawVtbl[], lbl_80286664[], lbl_80286590[], lbl_8029A144[], lbl_8029A2D4[];
    extern u8 lbl_803683AC;
    extern void *lbl_803683B0[2];
    extern u8 lbl_80368375, lbl_8029A54C[];
    extern void *lbl_80368378;
    extern u8 lbl_8036837C, lbl_8029A4F8[];
    extern void *lbl_80368380;
    extern u8 lbl_80368384, lbl_8029A4A4[];
    extern void *lbl_80368388;
    extern u8 lbl_8036838C, lbl_8029A450[];
    extern void *lbl_80368390;
    extern u8 lbl_80368394, lbl_8029A3FC[];
    extern void *lbl_80368398;
    extern u8 lbl_8036839C, lbl_8029A3A8[];
    extern void *lbl_803683A0;
    extern u8 lbl_803683A4, lbl_8029A354[];
    extern void *lbl_803683A8;
    u8 *entry;
    if ((s8)lbl_80368375 == 0) {
        entry=lbl_8029A54C;
        lbl_80368378=entry;
        lbl_80368375=1;
    }
    if ((s8)lbl_8036837C == 0) {
        entry=lbl_8029A4F8;
        lbl_80368380=entry;
        lbl_8036837C=1;
    }
    if ((s8)lbl_80368384 == 0) {
        entry=lbl_8029A4A4;
        lbl_80368388=entry;
        lbl_80368384=1;
    }
    if ((s8)lbl_8036838C == 0) {
        entry=lbl_8029A450;
        lbl_80368390=entry;
        lbl_8036838C=1;
    }
    if ((s8)lbl_80368394 == 0) {
        entry=lbl_8029A3FC;
        lbl_80368398=entry;
        lbl_80368394=1;
    }
    if ((s8)lbl_8036839C == 0) {
        entry=lbl_8029A3A8;
        lbl_803683A0=entry;
        lbl_8036839C=1;
    }
    if ((s8)lbl_803683A4 == 0) {
        entry=lbl_8029A354;
        lbl_803683A8=entry;
        lbl_803683A4=1;
    }
    if ((s8)lbl_803683AC == 0) {
        lbl_803683B0[1]=gUiMenuDrawVtbl;
        lbl_803683B0[1]=lbl_80286664;
        lbl_803683B0[1]=lbl_80286590;
        lbl_803683B0[0]=lbl_8029A144;
        lbl_803683B0[1]=lbl_8029A2D4;
        lbl_803683AC=1;
    }
    gUiContext[8]=0;
    Ui_CreateMenu(lbl_803683B0,arg0,0);
}

#pragma global_optimizer off
#pragma opt_common_subs off
void fn_801EB98C(void *arg0) {
extern u8 lbl_8028FDB0[],lbl_80292230[],lbl_802921E0[];
extern f32 lbl_8036B784;
void *Ui_FindChild(void *, s32, s32); void *Heap_Alloc(s32);
void Ui_AddChild(void *, void *); void Ui_OpenChildAnim(void *, void *, s32);
Unk5C *widget;
u8 color[4];
if (Ui_FindChild(arg0,0x40,0)==0) {
widget=Heap_Alloc(0x3C);
if(widget) {
widget->unk0=lbl_8028FDB0; widget->unk4=NULL; widget->unk0=lbl_80292230;
widget->unk8=-1; widget->unkA=0; widget->unkC=0;
widget->unkE=0x260; widget->unk10=0x1C0; widget->unk12=0; widget->unk14=0;
widget->unk16=0x260; widget->unk18=0x1C0; widget->unk1A=0; widget->unk1C=0;
widget->unk1E=0xFF; widget->unk1F=0xFF; widget->unk20=0xFF; widget->unk21=0xFF;
widget->unk22=0x316; widget->unk24=0;
widget->unk28=0.0f; widget->unk2C=0.0f; widget->unk30=0.0f;
widget->unk34=0; widget->unk38=0; widget->unk0=lbl_802921E0;
}
widget->unk8=0x40;
color[0]=0; color[1]=0; color[2]=0; color[3]=0x80;
if (&widget->unk1E != &color[0]) {
widget->unk1E=color[0]; widget->unk1F=color[1]; widget->unk20=color[2]; widget->unk21=color[3];
}
widget->unk34|=0x10; widget->unk24=8; widget->unk2C=0.0f;
Ui_AddChild(arg0,widget); Ui_OpenChildAnim(arg0,widget,1);
}
}
#pragma opt_common_subs reset
#pragma global_optimizer reset
void fn_801EBB00(void *arg0) {
void fn_801EBE88(void); void String_CStr(void *); void fn_80106BCC(void); void fn_800A8400(void); void Map_RefreshUnitMap(void *); void fn_80161F7C(void); void fn_8003F670(void *); void EventLock_Dec(void); void fn_80018B04(void); void String_Destroy(void *, s32); void Ui_DtorPanelBase(void *, s32);
extern u8 gUnitLists[], gBattleMap[], gEventLockDepth;
void *next; void *iter; u32 flags;
iter = *(void **)(gUnitLists + 12);
while(iter) { flags=*(u32*)((u8*)iter+0x1A0); next=*(void**)((u8*)iter+0x184); *(u32*)((u8*)iter+0x1A0)=flags&~0x800; iter=next; }
fn_801EBE88(); String_CStr((u8*)arg0+0x40); fn_80106BCC(); fn_800A8400(); Map_RefreshUnitMap(gBattleMap); fn_80161F7C(); fn_8003F670(*(void**)((u8*)arg0+0x4c));
while(gEventLockDepth != 0) EventLock_Dec();
if(arg0) { String_Destroy((void*)((u32)arg0+0x40),-1); Ui_DtorPanelBase(arg0,0); }
fn_80018B04();
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_801EBBB8(void *arg0) {
    extern s32 gUiInputFlags;
    extern s8 lbl_803683B8;
    extern f32 lbl_8036B780;
    extern u8 lbl_8027EE08[];
    extern u8 lbl_8029A128[];
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_80292230[];
    extern u8 lbl_80293C84[];
    extern u8 lbl_80293C58[];
    extern u8 gTargetList[];
    extern u8 gBattleState[];
    void *String_CStr(void *);
    s32 fn_80106DC8(void *, u8 *);
    void fn_8002F728(void *);
    void fn_8002F6E8(void *, u8, u8, s32, s32);
    void *Process_Create(void *, void *);
    void *Heap_Alloc(s32);
    void String_AssignCStr(void *, void *, s32);
    void Ui_AddChild(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void fn_80018B18(void *);
    s32 strlen(const char *);

    s32 count;
    u8 *p;
    s32 i;
    Unk5C *temp_r3;
    s32 len;
    u8 sp8[128];

    lbl_803683B8 = 0;
    gUiInputFlags &= ~1;
    count = fn_80106DC8(String_CStr((u8 *)arg0 + 0x40), sp8);
    fn_8002F728(gTargetList);
    p = sp8;
    for (i = 0; i < count; i++) {
        fn_8002F6E8(gTargetList, p[0], p[1], 0, 0);
        p += 2;
    }

    *(void **)((u8 *)arg0 + 0x50) = Process_Create(lbl_8029A128, arg0);
    *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 0x2c) |= 4;
    temp_r3 = (Unk5C *)Heap_Alloc(0x5c);
    if (temp_r3) {
        temp_r3->unk0 = lbl_8028FDB0;
        temp_r3->unk4 = NULL;
        temp_r3->unk0 = lbl_80292230;
        temp_r3->unk8 = -1;
        temp_r3->unkA = 0;
        temp_r3->unkC = 0x190;
        temp_r3->unkE = 0x260;
        temp_r3->unk10 = 0x1c0;
        temp_r3->unk12 = 0;
        temp_r3->unk14 = 0;
        temp_r3->unk16 = 0x260;
        temp_r3->unk18 = 0x30;
        temp_r3->unk1A = 0;
        temp_r3->unk1C = 0;
        temp_r3->unk1E = 0xff;
        temp_r3->unk1F = 0xff;
        temp_r3->unk20 = 0xff;
        temp_r3->unk21 = 0xff;
        temp_r3->unk22 = 0x316;
        temp_r3->unk24 = 0;
        temp_r3->unk28 = 0.0f;
        temp_r3->unk2C = 0.0f;
        temp_r3->unk30 = 0.0f;
        temp_r3->unk34 = 0;
        temp_r3->unk38 = 0;
        temp_r3->unk0 = lbl_80293C84;
        temp_r3->unk3C = 0;
        temp_r3->unk40 = 0;
        temp_r3->unk44 = 0;
        temp_r3->unk40 = 0;
        temp_r3->unk48 = 0;
        temp_r3->unk4C = 1;
        temp_r3->unk4E = 0;
        temp_r3->unk50 = 0;
        temp_r3->unk52 = 0;
        temp_r3->unk54 = 0;
        temp_r3->unk0 = lbl_80293C58;
        temp_r3->unk58 = 1;
        temp_r3->unk4E = 0x30;
        temp_r3->unk52 = 0x30;
        temp_r3->unk8 = -0x1000;
        temp_r3->unk48 = 1;
        len = strlen((const char *)lbl_8027EE08 + 0x147);
        String_AssignCStr(&temp_r3->unk3C, lbl_8027EE08 + 0x147, len);
        temp_r3->unk34 |= 0x10;
        temp_r3->unk58 = 1;
        Ui_AddChild(arg0, temp_r3);
    }
    {
        Unk5C *child = (Unk5C *)Ui_FindChild(arg0, -0x1000, 0);
        if (child) child->unk58 = 0;
    }
    gBattleState[0xa9] = 0;
    gBattleState[0xaa] = 0;
    *(u32 *)((u8 *)gBattleState + 0xb0) = 0;
    fn_80018B18(gBattleState);
}
#pragma global_optimizer on
void fn_801EBE00(void *arg0) {
    u8 FileCache_IsReady(void);
    s32 fn_80161FB8(void);
    void fn_80162054(void);
    s32 fn_801620AC(void);
    s32 Archive_Load(void);
    void Process_ClearFunc(void *);

    fn_801620AC();
    if (FileCache_IsReady() == 0 || fn_80161FB8() == 0) {
        return;
    } else {
        fn_80162054();
        fn_801620AC();
        *(s32 *)((char *)arg0 + 0x4C) = Archive_Load();
        Process_ClearFunc(arg0);
    }
}

void fn_801EBE60(void) {
    M2C_UNK fn_801620AC();
    M2C_UNK fn_8005C8B4();
    M2C_UNK fn_80162018();
    fn_801620AC();
    fn_8005C8B4();
    fn_80162018();
}

#pragma optimization_level 3
void fn_801EBE88(void)
{
    extern u8 gUnitLists[];
    void fn_8001594C(void *, s32);
    void fn_800156A0(void *, void *);
    void fn_80015718(void *, void *);
    void *sp8[5];
    void *node;
    void *next;

    fn_8001594C(sp8, 5);
    node = *(void **)(gUnitLists + 0x3c);
    while (node != NULL) {
        next = *(void **)((u8 *)node + 0x184);
        if (*(u32 *)((u8 *)node + 0x1A0) & 0x400000) {
            fn_800156A0(*(void **)((u8 *)node + 0x190), node);
            fn_80015718(sp8, node);
        }
        node = next;
    }
    node = *(void **)(gUnitLists + 0x3c);
    while (node != NULL) {
        next = *(void **)((u8 *)node + 0x184);
        if (!(*(u32 *)((u8 *)node + 0x1A0) & 0x400000)) {
            fn_800156A0(*(void **)((u8 *)node + 0x190), node);
            fn_80015718(sp8, node);
            node = next;
        } else {
            break;
        }
    }
    node = sp8[0];
    while (node != NULL) {
        next = *(void **)((u8 *)node + 0x184);
        fn_800156A0(*(void **)((u8 *)node + 0x190), node);
        fn_80015718(gUnitLists + 0x3c, node);
        node = next;
    }
}
#pragma optimization_level reset
void fn_801EBF7C(void) {
    M2C_UNK fn_800F20E0();
    M2C_UNK fn_800F214C();
    fn_800F214C();
    fn_800F20E0();
}

void fn_801EBFA0(void) {

}

void fn_801EBFA4(void) {

}

s32 fn_801EBFA8(void) {
    return 0xB0;
}

#pragma cplusplus on
extern "C" void fn_801EBFB0(void *arg0, void *arg1) {
void fn_8008C1D8(s32,s32,s32,s32,s32);
struct Obj { u8 pad[4]; virtual void v0()=0;
virtual void v1()=0;
virtual void v2()=0;
virtual void v3()=0;
virtual void v4()=0;
virtual void v5()=0;
virtual void v6()=0;
virtual void v7()=0;
virtual void v8()=0;
virtual void v9()=0;
virtual void v10()=0;
virtual void v11()=0;
virtual void v12()=0;
virtual void v13()=0;
virtual void v14()=0;
virtual void v15()=0;
virtual void v16()=0;
virtual void v17()=0;
virtual void v18()=0;
virtual void v19()=0;
virtual s16 v20()=0;
virtual void v21()=0;
virtual void v22()=0;
virtual void v23()=0;
virtual void v24()=0;
virtual void v25()=0;
virtual void v26()=0;
virtual void v27()=0;
virtual void v28()=0;
virtual void v29()=0; };
s32 value=*(s8 *)((u8 *)arg1+0x60);
s32 count=value;
((Obj *)arg0)->v29();
fn_8008C1D8(0,0,0,count*((Obj *)*(void **)((u8 *)arg1+0x3C))->v20()+0x20,2);
}

extern "C" void fn_801EC02C(void *self, void *ctx)
{
    void Ui_DrawObjRouteIcon(void *, void *);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    s32 Text_MeasureHeight(s32, f32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    extern f32 lbl_8036B788;
    extern f32 lbl_8036B78C;
    extern f32 lbl_8036B780;
    extern f32 lbl_8036B790;

    struct DrawObj {
        u8 pad04[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual s32 v20() = 0;
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual void v25() = 0;
        virtual void v26() = 0;
        virtual void v27() = 0;
        virtual void v28() = 0;
        virtual void v29() = 0;
        virtual void v30() = 0;
        virtual void v31(void *ctx) = 0;
    };

    s16 top;
    register unsigned int heightOffset;
    s32 width;
    s32 scaled;

    Ui_DrawObjRouteIcon(self, ctx);
    ((DrawObj *)self)->v31(ctx);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B788);
    Prim2D_PrepareTex();

    scaled = (s32)((f32)(s16)((DrawObj *)self)->v20() * lbl_8036B78C);

    heightOffset = Text_MeasureHeight(-1, lbl_8036B780) >> 1;

    top = *(s16 *)((u8 *)ctx + 0x3A);
    width = (s16)((DrawObj *)self)->v20();

    fn_8008AB7C(width >> 1, top + heightOffset, scaled, 0x17, 0xA, 0x28, 1);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B790);
    Prim2D_PrepareTex();
}

#pragma cplusplus on
extern "C" s16 fn_801EC140(void *arg0) {
    struct Obj {
        u8 pad[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual s16 v18() = 0;
    };
    s16 temp = ((Obj *)arg0)->v18();
    return (s16)((0x260 - temp) >> 1);
}
#pragma cplusplus reset

#pragma cplusplus reset

s32 fn_801EC17C(void) {
    return 0x60;
}

s32 fn_801EC184(void *unused, u8 *obj) {
#pragma cplusplus on
 extern u32 gUiInputFlags; extern u8 *gPadInput; extern u8 lbl_803683B8; extern u8 gUnitInfoPopup[]; extern u8 gUiContext[];
 void *GfxEnt_Get(u8); u8 Ui_IsUnitInfoPopupOpen(void *);
class Handler { public:
virtual s32 v0(void*,void*)=0;
virtual s32 v1(void*,void*)=0;
virtual s32 v2(void*,void*)=0;
virtual s32 v3(void*,void*)=0;
virtual s32 v4(void*,void*)=0;
virtual s32 v5(void*,void*)=0;
virtual s32 v6(void*,void*)=0;
virtual s32 v7(void*,void*)=0;
virtual s32 v8(void*,void*)=0;
virtual s32 v9(void*,void*)=0;
virtual s32 v10(void*,void*)=0;
virtual s32 v11(void*,void*)=0;
virtual s32 v12(void*,void*)=0;
virtual s32 v13(void*,void*)=0;
virtual s32 v14(void*,void*)=0;
virtual s32 v15(void*,void*)=0;
};
class Base {public: int word;}; class Handler2: public Base { public:
virtual s32 v0(void*,void*)=0;
virtual s32 v1(void*,void*)=0;
virtual s32 v2(void*,void*)=0;
virtual s32 v3(void*,void*)=0;
virtual s32 v4(void*,void*)=0;
virtual s32 v5(void*,void*)=0;
virtual s32 v6(void*,void*)=0;
virtual s32 v7(void*,void*)=0;
virtual s32 v8(void*,void*)=0;
virtual s32 v9(void*,void*)=0;
};
 u8 *ent; u32 pressed, held, previous; u8 flag; void *handler;
 ent = (u8*)GfxEnt_Get(obj[0x40 + (s8)obj[0x62]]);
 flag=0; if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) flag=1;
 if(flag) { handler=*(void**)(ent+0x34); return ((Handler*)handler)->v13(obj,ent); }
 held=*(u32*)(gPadInput+4); previous=*(u32*)(gPadInput+8); pressed=held & (previous^held); lbl_803683B8=ent[0x3A]+0x80;
 if((pressed&0x100)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) { handler=*(void**)(ent+0x34); return ((Handler*)handler)->v9(obj,ent); }
 if(pressed&0x200) { handler=*(void**)(obj+0x3C); return ((Handler2*)handler)->v6(obj,ent); }
 if(pressed&0x400) { handler=*(void**)(ent+0x34); return ((Handler*)handler)->v10(obj,ent); }
 if(pressed&0x800) { handler=*(void**)(obj+0x3C); return ((Handler2*)handler)->v7(obj,ent); }
 if(pressed&0x10) { handler=*(void**)(ent+0x34); return ((Handler*)handler)->v11(obj,ent); }
 if((pressed&0x1000)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) { (*(u8**)(obj+0x18))[0x54]=1; gUiContext[8]=0x86; return 5; }
 handler=*(void**)(ent+0x34); return ((Handler*)handler)->v13(obj,ent);
#pragma cplusplus reset
}

void fn_801EC370(void) {
    extern u16 lbl_8027EE08[];
    Msg_Expand((u8 *)lbl_8027EE08 + 0x26c);
}

void **fn_801EC39C(void) {
    extern u32 lbl_8027EE08[];
    return (void **)((u8 *)lbl_8027EE08 + 0x279);
}

u8 fn_801EC3AC(void) {
    extern u8 lbl_803683B8;
    return (u8) (lbl_803683B8 == 0x86);
}

s32 fn_801EC3C0(s32 unused, u8 *arg1) {
    extern u8 gUiContext[24];
    u8 *p;
    u8 *obj;
    obj = *(u8 **)(arg1 + 0x18);
    obj[0x54] = 1;
    p = gUiContext;
    p[8] = 0x86;
    return 5;
}

#pragma use_lmw_stmw on
void fn_801EC3E4(void *self, void *panel, void *entry) {
    s32 Text_MeasureWidth(void *, s32, f32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    extern f32 lbl_8036B780;
#pragma cplusplus on
    struct Obj {
        u8 pad[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual s16 v18() = 0;
    };
    struct TextSrc {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void *v4(void *) = 0;
    };
    struct Host {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17(void *) = 0;
        virtual void v18(void *) = 0;
    };

    s16 w;
    s32 tw;
    void *text;

    w = ((Obj *)*(void **)((u8 *)panel + 0x3C))->v18();
    text = ((TextSrc *)*(void **)((u8 *)entry + 0x34))->v4(entry);
    tw = Text_MeasureWidth(text, -1, lbl_8036B780);
    ((Host *)self)->v17(panel);
    Prim2D_AddPrim(6);
    Prim2D_SetPos((f32)((w - tw) >> 1), (f32)*(s16 *)((u8 *)entry + 0x32));
    ((Host *)self)->v18(entry);
    text = ((TextSrc *)*(void **)((u8 *)entry + 0x34))->v4(entry);
    Prim2D_SetText(text);
    Prim2D_EndPrim();
#pragma cplusplus reset
}
void fn_801EC4F0(void) {
    extern u16 lbl_8027EE08[];
    Msg_Expand((u8 *)lbl_8027EE08 + 0x29a);
}

void *fn_801EC51C(void) {
    extern u16 lbl_8027EE08[];
    return (u8 *)lbl_8027EE08 + 0x2a2;
}

u8 fn_801EC52C(void) {
    extern u8 lbl_803683B8;
    u32 temp;

    temp = __cntlzw(0x85 - lbl_803683B8);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_801EC540(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x85;
    return 5;
}

void fn_801EC558(void) {
    void Msg_Expand(void *);
    extern u8 lbl_8027EE08[257];

    Msg_Expand(lbl_8027EE08 + 0x2AB);
}

void *fn_801EC584(void) {
    extern u16 lbl_8027EE08[];
    return (u8 *)lbl_8027EE08 + 0x2b4;
}

u8 fn_801EC594(void) {
    extern u8 lbl_803683B8;
    u32 temp;

    temp = __cntlzw(0x84 - lbl_803683B8);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_801EC5A8(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x84;
    return 5;
}

void fn_801EC5C0(void) {
    extern u16 lbl_8027EE08[];
    Msg_Expand((u8 *)lbl_8027EE08 + 0x2BD);
}

void *fn_801EC5EC(void) {
    extern u16 lbl_8027EE08[];
    return (u8 *)lbl_8027EE08 + 0x2cd;
}

u8 fn_801EC5FC(void) {
    extern u8 lbl_803683B8;
    u32 temp;

    temp = __cntlzw(0x83 - lbl_803683B8);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_801EC610(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x83;
    return 5;
}

void fn_801EC628(void) {
    extern u16 lbl_8027EE08[];
    Msg_Expand(&lbl_8027EE08[0x2D8 / sizeof(u16)]);
}

void *fn_801EC654(void) {
    extern u16 lbl_8027EE08[];
    return (u8 *)lbl_8027EE08 + 0x2e4;
}

u8 fn_801EC664(void) {
    extern u8 lbl_803683B8;
    u32 temp;

    temp = __cntlzw(0x82 - lbl_803683B8);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_801EC678(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x82;
    return 5;
}

void fn_801EC690(void) {
    extern u16 lbl_8027EE08[];
    Msg_Expand(&lbl_8027EE08[0x2F0 / sizeof(u16)]);
}

void *fn_801EC6BC(void) {
    extern u16 lbl_8027EE08[];
    return (u8 *)lbl_8027EE08 + 0x2fd;
}

s32 fn_801EC6CC(void) {
    return 2;
}

#pragma global_optimizer off
s32 fn_801EC6D4(s32 unused, void *a, void *b)
{
    extern const char lbl_8027EE08[];
    void Ui_CreateMsgPopup(const char *, void *, f32, f32);
    f32 x = (f32)(*(s16 *)((u8 *)a + 0x30) + *(s16 *)((u8 *)b + 0x30));
    f32 y = (f32)(*(s16 *)((u8 *)a + 0x32) + *(s16 *)((u8 *)b + 0x32));
    Ui_CreateMsgPopup(lbl_8027EE08 + 0x30A, a, x, y);
    return 0x10;
}
#pragma global_optimizer reset
void fn_801EC74C(void) {
    extern u16 lbl_8027EE08[];
    Msg_Expand((u8 *)lbl_8027EE08 + 0x31D);
}

void *fn_801EC778(void) {
    extern u16 lbl_8027EE08[];
    return (u8 *)lbl_8027EE08 + 0x32e;
}

u8 fn_801EC788(void) {
    extern u8 lbl_803683B8;
    u32 temp;

    temp = __cntlzw(0x80 - lbl_803683B8);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_801EC79C(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x80;
    return 5;
}

void fn_801EC7B4(void) {

}

#pragma push
#pragma use_lmw_stmw on
#pragma opt_propagation off
#pragma push
#pragma optimization_level 3
#pragma use_lmw_stmw on
#pragma opt_propagation off
void fn_801EC7B8(void) {
    void DebugPrint(void *, ...);
    s32 OSGetTick(void);
    s8 fn_8005BA00(void);
    u32 fn_800C44F4(s32);
    void *fn_800C45B8(s32, void *, s32);
    void fn_800C4588(void *);
    void DCInvalidateRange(void *, u32);
    void ARQPostRequest(void *, s32, s32, s32, s32, s32, s32, void *);
    void fn_801ED838(void);
    extern u8 lbl_8027F1D0[];
    extern u8 gAramSlotPool[];
    extern void *lbl_80338E70[];
    extern void *gAramUsedList;
    extern void *gAramFreeList;
    extern s32 gAramBase;
    extern s32 gAramHeapSize;
    extern s32 gAramRequestCount;

    s32 tick;
    void **slot;
    void **arr;
    s32 half;
    void *buf;
    void *buf0;
    s32 used;
    s32 i;
    void *entry;
    void *node;
    void *best;
    u32 bestPri;
    u8 *p;
    s32 zero;
    s32 ctr;
    s32 j;
    u8 flg;
    u32 bus;
    u32 dt;

    DebugPrint(lbl_8027F1D0);
    tick = OSGetTick();
    while (*(volatile s32 *)&gAramRequestCount != 0) {}
    half = gAramHeapSize >> 1;
    if (fn_800C44F4(fn_8005BA00()) >= (u32)half) {
        buf = fn_800C45B8(-half, lbl_8027F1D0 + 0x18, 0);
    } else {
    p = gAramSlotPool;
    for (j=0;j<256;j++,p+=0x6C) {
       *(s32 *)(p+0x64)=0;
       p[0x53]=0;
    }
    gAramUsedList = 0;
    gAramFreeList = AramFindFreeSlot();
    *(s32 *)((u8 *)gAramFreeList + 0x60) = 0;
    *(s32 *)((u8 *)gAramFreeList + 0x5C) = 0;
    *(s32 *)((u8 *)gAramFreeList + 0x64) = gAramHeapSize;
    *(s32 *)((u8 *)gAramFreeList + 0x68) = gAramBase;
        return;
    }
        buf0 = buf;
        used = 0;
        for (node = gAramUsedList; node != 0; node = *(void **)((u8 *)node + 0x60)) {
            *(u8 *)((u8 *)node + 0x53) = (u8)(*(u8 *)((u8 *)node + 0x53) & 0xFE);
        }
        arr = lbl_80338E70;
        slot = arr;
        i = 0;
        for (;;) {
            node = gAramUsedList;
            bestPri = (u32)-1;
            best = 0;
            while (node != 0) {
                if ((*(u8 *)((u8 *)node + 0x53) & 1) == 0) {
                    if (bestPri > *(u32 *)((u8 *)node + 0x58)) {
                        bestPri = *(u32 *)((u8 *)node + 0x58);
                        best = node;
                    }
                }
                node = *(void **)((u8 *)node + 0x60);
            }
            if (best != 0) {
                *(u8 *)((u8 *)best + 0x53) = (u8)(*(u8 *)((u8 *)best + 0x53) | 1);
            }
            *slot = best;
            entry = *slot;
            if (entry == 0) {
                break;
            }
            if ((u32)half < (u32)(used + *(s32 *)((u8 *)entry + 0x64))) {
                lbl_80338E70[i] = 0;
                break;
            }
            DCInvalidateRange(buf, *(u32 *)((u8 *)entry + 0x64));
            gAramRequestCount += 1;
            ARQPostRequest(entry, 0, 1, 1, *(s32 *)((u8 *)entry + 0x68), (s32)buf,
                        *(s32 *)((u8 *)entry + 0x64), fn_801ED838);
            i += 1;
            *(s32 *)((u8 *)*slot + 0x68) = gAramBase + used;
            {
                s32 sz = *(s32 *)((u8 *)*slot + 0x64);
                slot += 1;
                used += sz;
                buf = (u8 *)buf + sz;
            }
            if (i >= 0x100) {
                break;
            }
        }
        {
        void *nullNode;
        void **sp;
        s32 j;
        sp = arr;
        j=0;
        nullNode = 0;
        for(;j<256;sp++,j++) {
            node=*sp;
            if(node==0) break;
            if(j==0) *(void **)((u8 *)node+0x5C)=nullNode;
            else *(void **)((u8 *)node+0x5C)=sp[-1];
            if(j<255) *(void **)((u8 *)*sp+0x60)=sp[1];
            else *(void **)((u8 *)*sp+0x60)=nullNode;
        }
        }
        gAramUsedList = lbl_80338E70[0];
        AramCache_ClearUnusedSlots((AramSlot *)gAramSlotPool);
        gAramFreeList = AramFindFreeSlot();
    *(s32 *)((u8 *)gAramFreeList + 0x5C) = 0;
        *(s32 *)((u8 *)gAramFreeList + 0x60) = 0;
        *(s32 *)((u8 *)gAramFreeList + 0x68) = gAramBase;
        *(s32 *)((u8 *)gAramFreeList + 0x64) = gAramHeapSize - used;
        {
        s32 j;
        for(j=0;j<256;arr++,j++) {
            node=*arr;
            if(node==0) break;
            *(s32 *)((u8 *)node+0x68)+=*(s32 *)((u8 *)gAramFreeList+0x64);
        }
        }
        gAramRequestCount += 1;
        ARQPostRequest(gAramFreeList, 0, 0, 1, (s32)buf0,
                    gAramBase + *(s32 *)((u8 *)gAramFreeList + 0x64), used, fn_801ED838);
        while (*(volatile s32 *)&gAramRequestCount != 0) {}
        fn_800C4588(buf0);
        dt = (u32)(OSGetTick() - tick);
        bus = *(u32 *)0x800000F8;
        DebugPrint(lbl_8027F1D0 + 0x19, dt / ((bus >> 2) / 1000));
}
#pragma pop
extern void *gAramUsedList;
void *AramCache_Find(s32 arg0) {
    extern void *gAramUsedList;
    void *node;
    u32 id;

    id = fn_8000D598();
    for (node = gAramUsedList; node != NULL; node = *(void **)((u8 *)node + 0x60)) {
        if (*(s32 *)((u8 *)node + 0x64) != 0 &&
            *(u32 *)((u8 *)node + 0x54) == id &&
            Str_Cmp((u8 *)node + 0x28, arg0) == 0) {
            return node;
        }
    }
    return NULL;
}

#pragma use_lmw_stmw on
s32 AramCache_Request(s32 path, s32 buf, s32 size, s32 a3, s32 a4) {
    void *fn_801ED12C(s32);
    void *AramCache_InsertFree(void *, void *);
    s32 fn_8000D598(s32);
    s32 fn_8005E55C(void);
    void DCFlushRange(s32, s32);
    void ARQPostRequest(void *, s32, s32, s32, s32, s32, s32, void *);
    void *fn_80234200(s32, s32);
    s32 Str_Cmp(void *, void *);
    void strcpy(void *, s32, s32);
    extern void fn_801ED800;
    extern u8 lbl_8027F1D0[];
    extern u8 gAramSlotPool[];
    extern void *gAramUsedList;
    extern void *gAramFreeList;
    extern s32 gAramHeapSize;
    extern s32 gAramRequestCount;
    u8 *flag;
    s32 i;
    void *temp;
    void *next;
    void *prev;
    void *cell;
    void *name;

    if (gAramHeapSize < size) {
        return 0;
    }
    if (AramFindFreeSlot() == NULL) {
        return 0;
    }
    flag = 0;
    name = fn_80234200(path, 0x2F);
    if (name != 0 && Str_Cmp(name, lbl_8027F1D0 + 0x35) == 0) {
        i = 0;
        flag = gAramSlotPool;
        do {
            if ((flag[0x53] & 2) && *(s32 *)(flag + 0x64) != 0) {
                next = *(void **)(flag + 0x60);
                temp = gAramUsedList;
                if (next != 0) {
                    *(void **)((u8 *)next + 0x5C) = *(void **)(flag + 0x5C);
                }
                prev = *(void **)(flag + 0x5C);
                if (prev != 0) {
                    *(void **)((u8 *)prev + 0x60) = *(void **)(flag + 0x60);
                } else {
                    temp = *(void **)(flag + 0x60);
                }
                gAramUsedList = temp;
                gAramFreeList = AramCache_InsertFree(gAramFreeList, flag);
            }
            i += 1;
            flag += 0x6C;
        } while (i < 0x100);
        flag = (u8 *)2;
        size = 0x180000;
    }
    cell = fn_801ED12C(size);
    if (cell == 0) {
        return 0;
    }
    *(u8 *)((u8 *)cell + 0x53) = *(u8 *)((u8 *)cell + 0x53) | (s32)flag;
    {
        s32 id = gAramRequestCount;
        gAramRequestCount = id + 1;
        strcpy((u8 *)cell + 0x28, path, id);
    }
    *(s32 *)((u8 *)cell + 0x24) = a4;
    *(s32 *)((u8 *)cell + 0x20) = a3;
    *(s32 *)((u8 *)cell + 0x54) = fn_8000D598(path);
    *(s32 *)((u8 *)cell + 0x58) = fn_8005E55C();
    DCFlushRange(buf, *(s32 *)((u8 *)cell + 0x64));
    ARQPostRequest(cell, 0, 0, 0, buf, *(s32 *)((u8 *)cell + 0x68), *(s32 *)((u8 *)cell + 0x64), &fn_801ED800);
    return 1;
}
#pragma push
#pragma opt_common_subs off
void fn_801ED12C(s32 arg0) {
    void fn_801EC7B8(void);
    void *AramCache_InsertFree(void *, void *);
    extern void *gAramUsedList;
    extern void *gAramFreeList;
    extern u8 gAramSlotPool[];
    u32 best_size;
    void *best;
    void *cell;
    void *next;
    void *prev;
    void *node;
    void *alloc_list;
    void *iter;
    void *insert_prev;
    s32 size;
    u32 rem;
    s32 var_ctr;
    s32 temp_r0;

    best = 0;
    best_size = 0x80000000u - 1u;
    cell = gAramFreeList;
    goto test1;
body1:
    size = ((AramAllocSlot *)cell)->size;
    if (size >= arg0 && (u32)size <= best_size) {
        best_size = (u32)size;
        best = cell;
    }
    cell = ((AramAllocSlot *)cell)->next;
test1:
    if (cell != 0) {
        goto body1;
    }

    if (best != 0) {
        goto have;
    }
    fn_801EC7B8();
reclaim:
    best = gAramFreeList;
    if (((AramAllocSlot *)best)->size >= (u32)arg0) {
        goto have;
    }
    node = gAramUsedList;
    gAramUsedList = AramCache_UnlinkSlot(node, node);
    gAramFreeList = AramCache_InsertFree(gAramFreeList, node);
    goto reclaim;

have:
    rem = ((AramAllocSlot *)best)->size - (u32)arg0;
    if (rem >= 0x20U) {
        goto split;
    }
    next = ((AramAllocSlot *)best)->next;
    cell = gAramFreeList;
    if (next != 0) {
        ((AramAllocSlot *)next)->prev = ((AramAllocSlot *)best)->prev;
    }
    prev = ((AramAllocSlot *)best)->prev;
    if (prev != 0) {
        ((AramAllocSlot *)prev)->next = ((AramAllocSlot *)best)->next;
    } else {
        cell = ((AramAllocSlot *)best)->next;
    }
    gAramFreeList = cell;
    goto insert;

split:
    cell = gAramSlotPool;
    ((AramAllocSlot *)best)->size = arg0;
    cell = AramCache_FindUnusedSlot(cell);
    AramCache_ReplaceSlot(cell, best, rem, arg0);

insert:
    gAramUsedList = AramCache_InsertUsed(best, gAramUsedList);
}
#pragma pop
void fn_801ED3D4(void) {
    extern u8 gAramSlotPool[];
    extern void *gAramUsedList;
    extern AramSlot *gAramFreeList;
    extern s32 gAramBase;
    extern s32 gAramHeapSize;
    AramSlot *p;
    s32 i;

    p = (AramSlot *)gAramSlotPool;
    for (i = 0; i < 256; i++, p++) {
        p->size = 0;
        p->flags = 0;
    }

    gAramUsedList = 0;
    gAramFreeList = (AramSlot *)AramFindFreeSlot();
    gAramFreeList->next = 0;
    gAramFreeList->prev = 0;
    gAramFreeList->size = gAramHeapSize;
    gAramFreeList->addr = gAramBase;
}

void fn_801ED52C(s32 arg0) {
    s32 fn_80214184(s32);
    void fn_80215D2C(void);
    s32 fn_80215F38(void);
    extern u8 gAramSlotPool[];
    extern void *gAramUsedList;
    extern void *gAramFreeList;
    extern s32 gAramBase;
    extern s32 gAramHeapSize;
    u8 *var_r4;
    s32 ctr1;
    s32 ctr2;
    s32 temp_r0;
    s32 var_r3;
    void *zero_ptr;

    if (fn_80215F38() == 0) {
        fn_80215D2C();
    }
    var_r4 = gAramSlotPool;
    ctr1 = 0x20;
    for (;;) {
        *(s32 *)(var_r4 + 0x64) = 0;
        *(u8 *)(var_r4 + 0x53) = 0;
        *(s32 *)(var_r4 + 0xD0) = 0;
        *(u8 *)(var_r4 + 0xBF) = 0;
        *(s32 *)(var_r4 + 0x13C) = 0;
        *(u8 *)(var_r4 + 0x12B) = 0;
        *(s32 *)(var_r4 + 0x1A8) = 0;
        *(u8 *)(var_r4 + 0x197) = 0;
        *(s32 *)(var_r4 + 0x214) = 0;
        *(u8 *)(var_r4 + 0x203) = 0;
        *(s32 *)(var_r4 + 0x280) = 0;
        *(u8 *)(var_r4 + 0x26F) = 0;
        *(s32 *)(var_r4 + 0x2EC) = 0;
        *(u8 *)(var_r4 + 0x2DB) = 0;
        *(s32 *)(var_r4 + 0x358) = 0;
        *(u8 *)(var_r4 + 0x347) = 0;
        var_r4 += 0x360;
        if (--ctr1 == 0) {
            break;
        }
    }
    if (arg0 == 0) {
        arg0 = 0x400000;
    }
    gAramBase = fn_80214184(arg0);
    zero_ptr = 0;
    var_r3 = 0xFF;
    gAramHeapSize = arg0;
    gAramUsedList = zero_ptr;
    var_r4 = gAramSlotPool;
    ctr2 = 0x20;
loop_7:
    if (*(s32 *)(var_r4 + 0x64) == 0) {
        goto found;
    }
    temp_r0 = *(s32 *)(var_r4 + 0xD0);
    var_r4 += 0x6C;
    if (temp_r0 == 0) {
        goto found;
    }
    temp_r0 = *(s32 *)(var_r4 + 0xD0);
    var_r4 += 0x6C;
    if (temp_r0 == 0) {
        goto found;
    }
    temp_r0 = *(s32 *)(var_r4 + 0xD0);
    var_r4 += 0x6C;
    if (temp_r0 == 0) {
        goto found;
    }
    temp_r0 = *(s32 *)(var_r4 + 0xD0);
    var_r4 += 0x6C;
    if (temp_r0 == 0) {
        goto found;
    }
    temp_r0 = *(s32 *)(var_r4 + 0xD0);
    var_r4 += 0x6C;
    if (temp_r0 == 0) {
        goto found;
    }
    temp_r0 = *(s32 *)(var_r4 + 0xD0);
    var_r4 += 0x6C;
    if (temp_r0 == 0) {
        goto found;
    }
    temp_r0 = *(s32 *)(var_r4 + 0xD0);
    var_r4 += 0x6C;
    if (temp_r0 == 0) {
        goto found;
    }
    var_r3 -= 7;
    var_r4 += 0x6C;
    if (--ctr2 != 0) {
        goto loop_7;
    }
    var_r4 = 0;
found:
    gAramFreeList = var_r4;
    *(s32 *)((u8 *)var_r4 + 0x60) = 0;
    *(s32 *)((u8 *)gAramFreeList + 0x5C) = 0;
    *(s32 *)((u8 *)gAramFreeList + 0x64) = gAramHeapSize;
    *(s32 *)((u8 *)gAramFreeList + 0x68) = gAramBase;
}

AramSlot *AramCache_InsertFree(AramSlot *list, AramSlot *cell)
{
  /* Insert cell into the ARAM free list by addr, coalescing adjacent free blocks. */
  AramSlot *prev;
  AramSlot *next;
  s32 *new_var;
  prev = NULL;
  next = list;
  goto loop_t;
  loop_b:
  if (prev != NULL)
  {
    if (cell->addr <= prev->addr)
    {
      goto loop_a;
    }
  }

  if (next == NULL)
  {
    goto loop_d;
  }
  if (next->addr > cell->addr)
  {
    goto loop_d;
  }
  loop_a:
  prev = next;

  next = next->next;
  loop_t:
  if (next != NULL)
  {
    goto loop_b;
  }

  loop_d:
  cell->next = next;

  cell->prev = prev;
  if (next != NULL)
  {
    next->prev = cell;
    if (next->addr == (cell->addr + cell->size))
    {
      cell->size = cell->size + next->size;
      next->size = 0;
      next->flags = 0;
      next = next->next;
      cell->next = next;
      if (next != NULL)
      {
        next->prev = cell;
      }
    }
  }
  if (prev != NULL)
  {
    prev->next = cell;
    new_var = &prev->size;
    if (cell->addr == (prev->addr + prev->size))
    {
      prev->size = (*new_var) + cell->size;
      *new_var = 0;
      prev->flags = 0;
      prev->next = next;
      if (next != NULL)
      {
        next->prev = prev;
      }
    }
    return list;
  }
  return cell;
}

void fn_801ED7D0(void *arg0) {
    s32 fn_8005E55C();
    M2C_FIELD(arg0, s32 *, 0x58) = fn_8005E55C();
}

void fn_801ED800(void *arg0) {
    void (*callback)(void *);
    extern s32 gAramRequestCount;

    callback = *(void (**)(void *))((u8 *)arg0 + 0x20);
    callback(*(void **)((u8 *)arg0 + 0x24));

    gAramRequestCount -= 1;
}

void fn_801ED838(void) {
    extern s32 gAramRequestCount;
    gAramRequestCount -= 1;
}

void fn_801ED848(void *arg0, void *arg1, void *arg2, void *arg3) {
    void DCInvalidateRange(void *, u32);
    s32 fn_8005E55C(void);
    void ARQPostRequest(void *, s32, s32, s32, s32, void *, s32, void *);
    void fn_801ED800(void *);
    extern s32 gAramRequestCount;

    gAramRequestCount++;
    *(void **)((char *)arg0 + 0x24) = arg3;
    *(void **)((char *)arg0 + 0x20) = arg2;
    *(s32 *)((char *)arg0 + 0x58) = fn_8005E55C();
    DCInvalidateRange(arg1, *(u32 *)((char *)arg0 + 0x64));
    ARQPostRequest(arg0, 0, 1, 0, *(s32 *)((char *)arg0 + 0x68), arg1, *(s32 *)((char *)arg0 + 0x64), fn_801ED800);
}

void fn_801ED8CC(void *arg0)
{
    extern u8 gUiContext[];
    extern void *lbl_8029A734[];
    extern u8 gGActorPathExt[];
    void *Msg_Expand(void *);
    void fn_8000D864(s32, void *);
    void Ui_OpenHelpPopup(void *, s32, void *, s32);

    fn_8000D864(0, Msg_Expand(lbl_8029A734[gUiContext[0x14]]));
    Ui_OpenHelpPopup(Msg_Expand(gGActorPathExt + 0x17E), 0, arg0, 0);
}

void fn_801ED940(s32 arg0) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    extern u8 lbl_803392B8[];

    Ui_CreateMenu((M2C_UNK *)lbl_803392B8, arg0, 0);
}

void fn_801ED970(void *arg0, void *arg1)
{
    extern u8 gGActorPathExt[];
    extern u8 lbl_8029A5FC[];
    extern u8 lbl_80366F00;

    extern void *Process_FindByName(void *);
    extern void *Process_CreateChild(void *, void *);

    u8 *entry;
    void *value;

    value = Process_FindByName(gGActorPathExt + 0x186);

    entry = (u8 *)Process_CreateChild(lbl_8029A5FC, value);

    *(void **)(entry + 0x30) = arg0;
    entry[0x38] = 2;

    Process_CreateChild(&lbl_80366F00, arg1);
}

void fn_801ED9DC(void *arg0, void *arg1)
{
    extern u8 gGActorPathExt[];
    extern u8 lbl_8029A5FC[];
    extern u8 lbl_80366F00;

    extern void *Process_FindByName(void *);
    extern void *Process_CreateChild(void *, void *);

    u8 *entry;
    void *value;

    value = Process_FindByName(gGActorPathExt + 0x186);

    entry = (u8 *)Process_CreateChild(lbl_8029A5FC, value);

    *(void **)(entry + 0x30) = arg0;
    entry[0x38] = 3;

    Process_CreateChild(&lbl_80366F00, arg1);
}

void fn_801EDA48(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    extern u8 lbl_8029A5FC[];
    void *temp_r3;

    temp_r3 = Process_CreateChild(lbl_8029A5FC, arg1);
    *(s32 *)((u8 *)temp_r3 + 0x30) = arg0;
    *(u8 *)((u8 *)temp_r3 + 0x38) = 1;
}

void fn_801EDA88(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    extern u8 lbl_8029A5FC[];
    void *temp_r3;

    temp_r3 = Process_CreateChild(lbl_8029A5FC, arg1);
    *(s32 *)((u8 *)temp_r3 + 0x30) = arg0;
    *(u8 *)((u8 *)temp_r3 + 0x38) = 0;
}

void fn_801EDAC8(void *arg0) {
    M2C_UNK fn_80169714(s32);
    M2C_UNK fn_8016978C(s32);
    u8 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x38);
    switch ((s32) temp_r0) {                        /* irregular */
    case 2:
        fn_80169714(M2C_FIELD(arg0, s32 *, 0x18));
        Process_Goto(arg0, 0x63);
        return;
    case 3:
        fn_8016978C(M2C_FIELD(arg0, s32 *, 0x18));
        Process_Goto(arg0, 0x63);
        return;
    }
}

void fn_801EDB38(void *arg0) {
    void fn_8016969C(void);
    switch ((s32)*(u8 *)((char *)arg0 + 0x38)) {
    case 2:
    case 3:
        fn_8016969C();
        break;
    }
}

void fn_801EDB70(void *arg0) {
    u8 temp_r0;

    M2C_FIELD(arg0, s16 *, 0x3A) = -1;
    M2C_FIELD(arg0, s8 *, 0x39) = 1;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    temp_r0 = *(u8 *)((char *)arg0 + 0x38);
    switch ((s32)temp_r0) {
    case 1:
        Process_Goto(arg0, 0xA);
        break;
    }
}

extern u32 jumptable_8029A7AC[9];
void fn_801EDBC0(void *arg0)
{
    extern u32 gUiInputFlags;
    extern u8 gBattle[];
    extern u8 gUiContext[];

    void BattleUnit_Copy(void *, void *);
    void BattleUnit_Reset(void *);
    void Item_Destroy(void *, s32);
    void Array_Destroy(void *, void (*)(void *, s32), s32, s32);
    void Heap_Free(void *);
    void Status_Clear(void *, u8);
    void Unit_ApplyStatusWpnExp(void *);

    u8 *self;
    u8 *saved;
    u8 status;

    self = (u8 *)arg0;

    if (*(u32 *)(self + 0x34) == 0) {
        gUiInputFlags &= ~4U;
    }

    saved = *(u8 **)(self + 0x4C);

    if (saved != 0) {
        u8 *unit;
        BattleUnit_Copy(gBattle, saved);

        unit = *(u8 **)(self + 0x4C);

        if (unit != 0) {
            BattleUnit_Reset(unit);

            Item_Destroy(unit + 0x28C, -1);
            Item_Destroy(unit + 0x284, -1);

            if (unit != 0 &&
                unit != 0 &&
                unit != 0 &&
                unit != 0 &&
                unit != 0 &&
                unit != 0 &&
                unit != 0) {
                Array_Destroy(unit + 0x1EC, Item_Destroy, 8, 4);
                Array_Destroy(unit + 0x1CC, Item_Destroy, 8, 4);
            }

            Heap_Free(unit);
        }

        *(void **)(self + 0x4C) = 0;
    }

    saved = *(u8 **)(self + 0x50);

    if (saved != 0) {
        u8 *unit;
        BattleUnit_Copy(gBattle + 0x2E0, saved);

        unit = *(u8 **)(self + 0x50);

        if (unit != 0) {
            BattleUnit_Reset(unit);

            Item_Destroy(unit + 0x28C, -1);
            Item_Destroy(unit + 0x284, -1);

            if (unit != 0 &&
                unit != 0 &&
                unit != 0 &&
                unit != 0 &&
                unit != 0 &&
                unit != 0 &&
                unit != 0) {
                Array_Destroy(unit + 0x1EC, Item_Destroy, 8, 4);
                Array_Destroy(unit + 0x1CC, Item_Destroy, 8, 4);
            }

            Heap_Free(unit);
        }

        *(void **)(self + 0x50) = 0;
    }

    status = gUiContext[0x14];

    if (status != 0xFF) {
        u8 *unit;
        unit = *(u8 **)(self + 0x30);

        switch (status) {
        case 0:
            Status_Clear(unit + 0x1BC, 0x24);
            break;
        case 1:
            Status_Clear(unit + 0x1BC, 0x25);
            break;
        case 2:
            Status_Clear(unit + 0x1BC, 0x26);
            break;
        case 3:
            Status_Clear(unit + 0x1BC, 0x27);
            break;
        case 4:
        case 5:
        case 6:
            break;
        case 7:
            Status_Clear(unit + 0x1BC, 0x28);
            break;
        case 8:
            Status_Clear(unit + 0x1BC, 0x22);
            break;
        default:
            break;
        }

        Unit_ApplyStatusWpnExp(unit);
    }
}

void fn_801EDDF0(void *arg0) {
    void *Heap_Alloc(s32);
    void *fn_801A7FA4(void *);
    void BattleUnit_Copy(void *, void *);
    void Battle_QueuePromotionGains(void *, void *);
    void Unit_Promote(void *);
    extern u8 gBattle[];
    extern u8 gUiContext[];
    void *temp;
    u8 *base_2e0;

    if (*(u32 *)(gBattle + 0x188) != 0) {
        temp = Heap_Alloc(0x2E0);
        if (temp != NULL) {
            temp = fn_801A7FA4(temp);
        }
        *(void **)((u8 *)arg0 + 0x4C) = temp;
        BattleUnit_Copy(*(void **)((u8 *)arg0 + 0x4C), gBattle);
    }
    base_2e0 = gBattle + 0x2E0;
    if (*(u32 *)(base_2e0 + 0x188) != 0) {
        temp = Heap_Alloc(0x2E0);
        if (temp != NULL) {
            temp = fn_801A7FA4(temp);
        }
        *(void **)((u8 *)arg0 + 0x50) = temp;
        BattleUnit_Copy(*(void **)((u8 *)arg0 + 0x50), base_2e0);
    }
    gUiContext[0x14] = 0xFF;
    Battle_QueuePromotionGains(gBattle, *(void **)((u8 *)arg0 + 0x30));
    Unit_Promote(*(void **)((u8 *)arg0 + 0x30));
}

void fn_801EDEC8(void *arg0) {
    extern s32 gUiInputFlags;
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (gUiInputFlags & 4);
    gUiInputFlags |= 4;
}

void fn_801EDEE4(void *arg0) {
    void *Process_Find(void *);
    void fn_80015D54(void);
    void fn_80016180(void);
    void fn_80016358(void);
    void fn_800163F8(void);
    void fn_8014C798(void *);
    void BattleState_LoadMap(void *, u8 *);
    extern u8 lbl_8029A5FC[];
    extern u8 gBattleState[];
    void *temp_r3;
    u8 var_r0;
    s32 temp_r0;

    if (*(u8 *)((u8 *)arg0 + 0x39) != 0) {
        BattleState_LoadMap(gBattleState, gBattleState + 0x504);
        fn_8014C798(gBattleState);
    }
    temp_r3 = Process_Find(lbl_8029A5FC);
    if (temp_r3 != NULL) {
        temp_r0 = *(u8 *)((u8 *)temp_r3 + 0x38);
        switch (temp_r0) {
        case 2:
        case 3:
            var_r0 = 1;
            break;
        default:
            goto block_7;
        }
    } else {
    block_7:
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        fn_80016358();
    } else {
        fn_800163F8();
    }
    fn_80016180();
    fn_80015D54();
}

void fn_801EDF7C(void *arg0) {
    M2C_UNK fn_800162B8();
    u8 fn_80040824();
    M2C_UNK fn_8014C718(void *, void *);
    extern u8 gBattleState[];
    M2C_FIELD(arg0, u8 *, 0x39) = fn_80040824();
    if ((u8) M2C_FIELD(arg0, u8 *, 0x39) != 0) {
        fn_8014C718(gBattleState, arg0);
    }
    fn_800162B8();
}

#pragma push
#pragma optimization_level 4
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_801EDFCC(void) {
    extern u8 gFxChannels[];
    Fx_801EDFCC_Body(gFxChannels);
}
#pragma pop
void fn_801EE018(void *arg0) {
    extern u8 gFxChannels[];
    void fn_80148980(void *, s32, s32);
    s16 temp_r5;

    temp_r5 = *(s16 *)((char *)arg0 + 0x3A);
    fn_80148980(gFxChannels + ((u8)temp_r5 * 0x30), 0x3E8, temp_r5);
}

void fn_801EE054(void *arg0) {
    s8 fn_80148618(void *, s32);
    extern u16 gGActorPathExt[];

    *(s16 *)((char *)arg0 + 0x3A) = fn_80148618((u8 *)gGActorPathExt + 0x195, 1);
}

void fn_801EE098(void) {
    M2C_UNK fn_80146B00();
    M2C_UNK fn_801478D0(M2C_UNK);
    M2C_UNK fn_80147FA8(M2C_UNK);
    fn_80147FA8(0x3E8);
    fn_801478D0(0x3E8);
    fn_80146B00();
}

void fn_801EE0C8(u8 *selfArg) {
    void *Effect_Create(char *, u8 *);
    void Effect_SetPos(void *, f32, f32, f32);
    void fn_801C6CBC(void *, s32, u8 *, s32);
    void fn_801C6E60(void *);
    void *Process_Create(void *, void *);
    void Process_UnlinkByKey(void *);
    void Process_CreateChild(void *, void *);
    void Process_ClearFunc(void);
    void Model_SetColor(void *, u8, u8, u8);
    void Model_SetAlpha(void *, u8);
    void fn_800C4384(void);
    void fn_800616A0(void *);
    void fn_8005C7E8(void *);
    void fn_8005C8B4(void *);
    u8 fn_800537E8(void);
    void fn_80056580(void);
    void fn_801B3258(void *, u8 *);
    void fn_80162018(void);
    u8 fn_800A8504(void *, u8);
    s32 GActor_LoadResources(void *, s32);
    void fn_801C6DB8(void *);
    void fn_801C4440(void);
    void fn_801EF39C(void *, u8 *, s32);
    void String_Copy(void *, void *);
    void String_Destroy(void *, s32);
    void String_JoinCStr(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void String_Concat(void *, void *, void *);
    void String_Assign(void *, void *, s32, s32);
    void *String_CStr(void *);
    extern char gGActorPathExt[];
    extern u8 gBattle[];
    extern f32 lbl_8036B7B8;
    extern f32 lbl_8036B7BC;
    extern u32 lbl_8036B7A0;
    extern u32 lbl_8036B7A4;
    extern u32 lbl_8036B7A8;
    extern u32 lbl_8036B7AC;
    extern u32 lbl_8036B7B0;
    extern u32 lbl_8036B7B4;
    extern u32 lbl_803683D8;
    extern u8 lbl_8029A5A0[];
    extern u8 lbl_8029A780[];
    u8 *self;
    void *eff;
    void *model;
    u8 b8[8];
    u8 b10[8];
    u8 b18[8];
    u8 b20[8];
    u32 w28;
    u32 w2C;
    u32 w30;
    u32 w34;
    u32 w38;
    u32 w3C;
    String sAC, sA0, s94, s88, s7C, s70, s64, s58, s4C, s40;
    u8 alpha;
    s32 i;
    s32 sum;

    self = selfArg;
    if (*(u16 *)(self + 0x3E) != 0) {
        *(u16 *)(self + 0x3E) = *(u16 *)(self + 0x3E) - 1;
        return;
    }
    switch (*(u16 *)(self + 0x3C)) {
    case 0:
        *(u16 *)(self + 0x3E) = 0x3C;
        *(u16 *)(self + 0x3C) = 1;
        break;
    case 1:
        eff = Effect_Create(gGActorPathExt + 0x1AB, self);
        Effect_SetPos(eff, lbl_8036B7B8, lbl_8036B7B8, lbl_8036B7B8);
        *(f32 *)((u8 *)*(void **)((u8 *)eff + 0x30) + 0x1C) = lbl_8036B7BC;
        *(u16 *)(self + 0x3E) = 0x1F4;
        *(u16 *)(self + 0x3C) = 2;
        w3C = lbl_8036B7A0;
        fn_801C6CBC(&w3C, 0x78, self, 0);
        fn_801C6E60(*(void **)((u8 *)*(void **)(self + 0x48) + 0xB8));
        fn_801C6E60(*(void **)((u8 *)*(void **)(self + 0x48) + 0xC4));
        w38 = lbl_8036B7A4;
        w34 = lbl_8036B7A8;
        model = *(void **)((u8 *)*(void **)(self + 0x48) + 0xB8);
        if (model != NULL) {
            void *p = Process_Create(lbl_8029A5A0, self);
            *(void **)((u8 *)p + 0x30) = model;
            *(s32 *)((u8 *)p + 0x38) = 0x12C;
            *(u32 *)&b20[0] = w38;
            *(u32 *)&b20[4] = w34;
            alpha = b20[3];
            ((u8 *)p)[0x44] = b20[0];
            ((u8 *)p)[0x45] = b20[1];
            ((u8 *)p)[0x46] = b20[2];
            ((u8 *)p)[0x47] = alpha;
            ((u8 *)p)[0x48] = b20[4];
            ((u8 *)p)[0x49] = b20[5];
            ((u8 *)p)[0x4A] = b20[6];
            ((u8 *)p)[0x4B] = b20[7];
            *(s32 *)((u8 *)p + 0x3C) = 0xF0;
            *(s32 *)((u8 *)p + 0x40) = 0;
            Model_SetColor(model, b20[0], b20[1], b20[2]);
            Model_SetAlpha(model, alpha);
        }
        model = *(void **)((u8 *)*(void **)(self + 0x48) + 0xC4);
        if (model != NULL) {
            void *p = Process_Create(lbl_8029A5A0, self);
            *(void **)((u8 *)p + 0x30) = model;
            *(s32 *)((u8 *)p + 0x38) = 0x12C;
            *(u32 *)&b18[0] = w38;
            *(u32 *)&b18[4] = w34;
            alpha = b18[3];
            ((u8 *)p)[0x44] = b18[0];
            ((u8 *)p)[0x45] = b18[1];
            ((u8 *)p)[0x46] = b18[2];
            ((u8 *)p)[0x47] = alpha;
            ((u8 *)p)[0x48] = b18[4];
            ((u8 *)p)[0x49] = b18[5];
            ((u8 *)p)[0x4A] = b18[6];
            ((u8 *)p)[0x4B] = b18[7];
            *(s32 *)((u8 *)p + 0x3C) = 0xF0;
            *(s32 *)((u8 *)p + 0x40) = 0;
            Model_SetColor(model, b18[0], b18[1], b18[2]);
            Model_SetAlpha(model, alpha);
        }
        break;
    case 8:
        fn_800C4384();
        *(u16 *)(self + 0x3E) = 0x869F;
        break;
    case 2:
        if (*(u32 *)((u8 *)*(void **)(self + 0x48) + 0xB4) != 0) {
            void *actor = *(void **)(self + 0x48);
            fn_801C6DB8(*(void **)((u8 *)actor + 0xB8));
            fn_801C4440();
            Process_UnlinkByKey(lbl_8029A5A0);
            fn_800616A0(*(void **)((u8 *)actor + 0xBC));
            *(u32 *)((u8 *)actor + 0xBC) = 0;
            fn_800616A0(*(void **)((u8 *)actor + 0xB8));
            *(u32 *)((u8 *)actor + 0xB8) = 0;
            fn_8005C7E8(*(void **)((u8 *)actor + 0xB4));
            *(u32 *)((u8 *)actor + 0xB4) = 0;
            actor = *(void **)(self + 0x48);
            s40.cap = 0;
            s40.size = 0;
            s40.data = 0;
            s40.cap = 0;
            fn_801EF39C(&s64, actor, 1);
            String_Copy(&s4C, &s64);
            String_Destroy(&s64, -1);
            String_JoinCStr(&s70, gGActorPathExt + 0x1BB, &s4C);
            String_ConcatCStr(&s7C, &s70, gGActorPathExt + 0x1BF);
            String_Copy(&s58, &s7C);
            String_Destroy(&s7C, -1);
            String_Destroy(&s70, -1);
            String_Concat(&s88, &s58, &s4C);
            String_ConcatCStr(&s94, &s88, gGActorPathExt + 0x1C1);
            String_Assign(&s40, &s94, 0, -1);
            String_Destroy(&s94, -1);
            String_Destroy(&s88, -1);
            fn_8005C8B4(String_CStr(&s40));
            String_Concat(&sA0, &s58, (String *)((u8 *)actor + 0x20));
            String_ConcatCStr(&sAC, &sA0, gGActorPathExt + 0x1C9);
            String_Assign(&s40, &sAC, 0, -1);
            String_Destroy(&sAC, -1);
            String_Destroy(&sA0, -1);
            fn_8005C8B4(String_CStr(&s40));
            String_Destroy(&s58, -1);
            String_Destroy(&s4C, -1);
            String_Destroy(&s40, -1);
        }
        *(u16 *)(self + 0x3C) = 3;
        *(u16 *)(self + 0x3E) = 0xB4;
        break;
    case 3:
        GActor_LoadResources(*(void **)(self + 0x48), 1);
        w30 = lbl_8036B7AC;
        fn_801C6CBC(&w30, 0xB4, self, 0);
        w2C = lbl_8036B7B0;
        w28 = lbl_8036B7B4;
        model = *(void **)((u8 *)*(void **)(self + 0x48) + 0xB8);
        if (model != NULL) {
            void *p = Process_Create(lbl_8029A5A0, self);
            *(void **)((u8 *)p + 0x30) = model;
            *(s32 *)((u8 *)p + 0x38) = 0x12C;
            *(u32 *)&b10[0] = w2C;
            *(u32 *)&b10[4] = w28;
            alpha = b10[3];
            ((u8 *)p)[0x44] = b10[0];
            ((u8 *)p)[0x45] = b10[1];
            ((u8 *)p)[0x46] = b10[2];
            ((u8 *)p)[0x47] = alpha;
            ((u8 *)p)[0x48] = b10[4];
            ((u8 *)p)[0x49] = b10[5];
            ((u8 *)p)[0x4A] = b10[6];
            ((u8 *)p)[0x4B] = b10[7];
            *(s32 *)((u8 *)p + 0x3C) = 0x3C;
            *(s32 *)((u8 *)p + 0x40) = 0;
            Model_SetColor(model, b10[0], b10[1], b10[2]);
            Model_SetAlpha(model, alpha);
        }
        model = *(void **)((u8 *)*(void **)(self + 0x48) + 0xC4);
        if (model != NULL) {
            void *p = Process_Create(lbl_8029A5A0, self);
            *(void **)((u8 *)p + 0x30) = model;
            *(s32 *)((u8 *)p + 0x38) = 0x12C;
            *(u32 *)&b8[0] = w2C;
            *(u32 *)&b8[4] = w28;
            alpha = b8[3];
            ((u8 *)p)[0x44] = b8[0];
            ((u8 *)p)[0x45] = b8[1];
            ((u8 *)p)[0x46] = b8[2];
            ((u8 *)p)[0x47] = alpha;
            ((u8 *)p)[0x48] = b8[4];
            ((u8 *)p)[0x49] = b8[5];
            ((u8 *)p)[0x4A] = b8[6];
            ((u8 *)p)[0x4B] = b8[7];
            *(s32 *)((u8 *)p + 0x3C) = 0x3C;
            *(s32 *)((u8 *)p + 0x40) = 0;
            Model_SetColor(model, b8[0], b8[1], b8[2]);
            Model_SetAlpha(model, alpha);
        }
        *(u16 *)(self + 0x3C) = 4;
        break;
    case 4:
        if (fn_800537E8() != 0) break;
        fn_80056580();
        *(u16 *)(self + 0x3C) = 5;
        *(u16 *)(self + 0x3E) = 0x1E;
        break;
    case 5:
        fn_801B3258(gBattle, self);
        fn_80162018();
        *(u16 *)(self + 0x3C) = 6;
        *(u16 *)(self + 0x3E) = 1;
        break;
    case 6:
        sum = 0;
        for (i = 0; i <= 8; i++) {
            sum += (u8)fn_800A8504(*(void **)(gBattle + 0x46C), (u8)i);
        }
        if (sum == 0) break;
        lbl_803683D8 = *(u32 *)(gBattle + 0x560);
        Process_CreateChild(lbl_8029A780, self);
        *(u16 *)(self + 0x3C) = 7;
        *(u16 *)(self + 0x3E) = 0x1E;
        break;
    case 7:
        Process_ClearFunc();
        break;
    }
}

#pragma use_lmw_stmw on
void fn_801EE76C(void *arg0) {
    void *fn_800C42D8(s32);
    void fn_800D6878(void *, void *, void *);
    void fn_8022C260(void *, void *, void *, s32, s32);
    void *fn_80068548(void);
    void fn_801C77A4(f32, f32, f32);
    void fn_801EFDC8(void *);
    s32 fn_800C9400(void *, s32, void *, char *, s32);
    void *fn_8000C0C0(void *);
    void *fn_8014D8FC(void *);
    void fn_800C9ABC(void *, char *, void *);
    void fn_800C992C(void *, char *, s32);
    void fn_800408A8(s32);
    void fn_8004084C(void);
    void *fn_80040844(void);
    void *fn_800C93EC(void *);
    void fn_80041514(void *, void *);
    void fn_800CB90C(void *, void *, char *);
    void *fn_800C91EC(void *, void *, void *);
    void fn_800C9A60(void *, s32);
    void fn_800C8DCC(void *, void *, void *);
    void fn_800C9120(void *, s32);
    void fn_801EFB2C(void *, char *);
    void fn_801EF6BC(void *);
    void fn_801EEF74(void *, s32);
    void fn_800558D8(char *);
    void *fn_8000CAF0(void *, void *);
    void *fn_80059208(void *, void *);
    void fn_8000C070(void *, s32);
    void fn_800E99CC(void *);
    void fn_801EEDB4(void);
    s32 strlen(char *);
    extern char lbl_8027F26C[];
    extern u8 lbl_8029A5FC[];
    extern u8 lbl_80330708[];
    extern u8 lbl_80330EAC[];
    extern u8 lbl_8029A5BC[];
    extern f32 lbl_8036B7B8;
    extern f32 lbl_8036B7C0;
    extern f32 lbl_8036B7C4;
    extern f32 lbl_8036B7C8;

    char bufAC[0x20];
    char buf8C[0x20];
    char buf6C[0x20];
    String sp60;
    String sp54;
    String sp48;
    String sp3C;
    String sp30;
    String sp24;
    void *sp20;
    void *sp1C;
    void *sp18;
    void *sp14;
    void *sp10;
    void *spC;
    void *sp8;
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    s32 n;
    s32 ok;
    s32 st;
    char *str;
    void *cam;
    s8 flag27;
    s8 flag26;
    char *path;
    void *r29;
    void *obj;
    void *self;

    self = arg0;
    obj = fn_800C42D8(0xD8);
    r29 = obj;
    path = (char *)obj;
    if (obj != NULL) {
        fn_800D6878((char *)obj + 4, &sp8, &spC);
        fn_8022C260(path + 0x14, (void *)fn_800E99CC, (void *)fn_800C9A60, 0xC, 2);
        fn_8022C260(path + 0x2C, (void *)fn_800E99CC, (void *)fn_800C9A60, 0xC, 2);
        fn_8022C260(path + 0x44, (void *)fn_800E99CC, (void *)fn_800C9A60, 0xC, 2);
        fn_8022C260(path + 0x5C, (void *)fn_800E99CC, (void *)fn_800C9A60, 0xC, 2);
        fn_8022C260(path + 0x74, (void *)fn_800E99CC, (void *)fn_800C9A60, 0xC, 2);
        fn_8022C260(path + 0x8C, (void *)fn_800E99CC, (void *)fn_800C9A60, 0xC, 2);
    }
    *(void **)((char *)self + 0x48) = obj;

    cam = fn_80068548();
    f3 = lbl_8036B7B8;
    f2 = lbl_8036B7C0;
    *(f32 *)((char *)cam + 0xE0) = f3;
    f1 = lbl_8036B7C4;
    *(f32 *)((char *)cam + 0xE4) = f3;
    f0 = lbl_8036B7C8;
    *(f32 *)((char *)cam + 0xE8) = f3;
    *(f32 *)((char *)cam + 0xD4) = f3;
    *(f32 *)((char *)cam + 0xD8) = f2;
    *(f32 *)((char *)cam + 0xDC) = f1;
    *(f32 *)((char *)cam + 0xEC) = f3;
    *(f32 *)((char *)cam + 0xF0) = f0;
    *(f32 *)((char *)cam + 0xF4) = f3;
    fn_801C77A4(f1, f2, f3);

    fn_801EFDC8(*(void **)((char *)self + 0x48));

    path = (char *)*(void **)((char *)self + 0x48) + 0x5C;
    str = lbl_8027F26C;
    str += 0x1CE;
    n = strlen(str);
    str = lbl_8027F26C;
    if (fn_800C9400(path, 0, *(void **)path, str + 0x1CE, n) != 0) {
        r29 = fn_8000C0C0(lbl_8029A5FC);
        if (r29 == NULL) {
            goto set0;
        }
        st = *(u8 *)((char *)r29 + 0x38);
        if (st >= 4) {
            goto set0;
        }
        if (st < 2) {
            ok = 0;
        } else {
            ok = 1;
        }
        goto setdone;
set0:
        ok = 0;
setdone:
        if ((u8)ok == 0) {
            r29 = *(void **)(lbl_80330EAC + 0xCB0);
            path = *(char **)(lbl_80330EAC + 0xCB4);
        } else {
            goto use30708;
        }
    } else {
use30708:
        r29 = fn_8014D8FC(lbl_80330708);
        path = *(char **)((char *)r29 + 0x4C);
        r29 = *(void **)((char *)r29 + 0x48);
    }

    obj = *(void **)((char *)self + 0x48);
    fn_800C9ABC(&sp24, lbl_8027F26C + 0x1D6, &sp10);
    n = strlen((char *)r29);
    fn_800C992C(&sp24, (char *)r29, n);
    str = lbl_8027F26C;
    str += 0x1BF;
    n = strlen(str);
    str = lbl_8027F26C;
    fn_800C992C(&sp24, str + 0x1BF, n);
    fn_800408A8(1);
    fn_8004084C();
    r29 = fn_80040844();
    fn_80041514(r29, fn_800C93EC(&sp24));

    flag27 = 0;
    flag26 = 0;
    r29 = fn_800C42D8(0x60);
    if (r29 != NULL) {
        fn_800C9ABC(&sp30, lbl_8027F26C + 0x1DB, &sp14);
        flag27 = 1;
        fn_800CB90C(&sp3C, &sp24, lbl_8027F26C + 0x1E0);
        flag26 = 1;
        r29 = fn_800C91EC(r29, &sp3C, &sp30);
    }
    if (flag26 != 0) {
        fn_800C9A60(&sp3C, -1);
    }
    if (flag27 != 0) {
        fn_800C9A60(&sp30, -1);
    }

    fn_800C9ABC(&sp48, lbl_8027F26C + 0x1EA, &sp18);
    fn_800C8DCC(buf6C, r29, &sp48);
    *(s32 *)((char *)obj + 0xA8) = *(s32 *)buf6C;
    fn_800C9A60(&sp48, -1);

    fn_800C9ABC(&sp54, lbl_8027F26C + 0x1F3, &sp1C);
    fn_800C8DCC(buf8C, r29, &sp54);
    *(s32 *)((char *)obj + 0xAC) = *(s32 *)buf8C;
    fn_800C9A60(&sp54, -1);

    fn_800C9ABC(&sp60, lbl_8027F26C + 0x1FE, &sp20);
    fn_800C8DCC(bufAC, r29, &sp60);
    *(s32 *)((char *)obj + 0xB0) = *(s32 *)bufAC;
    fn_800C9A60(&sp60, -1);

    fn_800C9120(r29, 1);
    fn_800C9A60(&sp24, -1);

    fn_801EFB2C(*(void **)((char *)self + 0x48), path);
    fn_801EF6BC(*(void **)((char *)self + 0x48));
    fn_801EEF74(*(void **)((char *)self + 0x48), 0);
    fn_800558D8(lbl_8027F26C + 0x1AB);
    *(void **)((char *)self + 0x44) = fn_8000CAF0(lbl_8029A5BC, self);
    *(void **)((char *)self + 0x40) = fn_80059208((void *)fn_801EEDB4, self);
    *(s16 *)((char *)self + 0x3E) = 0;
    *(s16 *)((char *)self + 0x3C) = 0;
    r29 = *(void **)((char *)self + 0x44);
    fn_8000C070(r29, 0xA);
    *(s16 *)((char *)r29 + 0x48) = 0;
}
void fn_801EEBC0(void *arg0) {
void Process_Unlink(void*); void fn_801C777C(void); void fn_801C6DB8(void*);
void fn_801C4440(void); void Process_UnlinkByKey(void*); void fn_800616A0(void*);
void fn_8005C7E8(void*); void *Map_Get(void); void fn_80041254(void*);
void fn_800408A8(s32); void fn_8004084C(void); void fn_801F1888(void*);
void fn_800D5894(void*); void Array_Destroy(void*,void*,s32,s32);
void String_Destroy(void*,s32); void BinTree_Destroy(void*,void*);
void Heap_Free(void*); void fn_8005376C(void);
extern u8 lbl_8029A5A0[];
u8 *obj;
Process_Unlink(*(void**)((u8*)arg0+0x44));
Process_Unlink(*(void**)((u8*)arg0+0x40));
fn_801C777C();
obj=*(u8**)((u8*)arg0+0x48);
if(*(void**)(obj+0xB4)) {
fn_801C6DB8(*(void**)(obj+0xB8));
fn_801C4440();
Process_UnlinkByKey(lbl_8029A5A0);
fn_800616A0(*(void**)(obj+0xBC)); *(void**)(obj+0xBC)=0;
fn_800616A0(*(void**)(obj+0xB8)); *(void**)(obj+0xB8)=0;
fn_8005C7E8(*(void**)(obj+0xB4)); *(void**)(obj+0xB4)=0;
}
obj=*(u8**)((u8*)arg0+0x48);
if(*(void**)(obj+0xD0)) {
fn_800616A0(*(void**)(obj+0xD0)); *(void**)(obj+0xD0)=0;
fn_8005C7E8(*(void**)(obj+0xCC));
}
fn_80041254(Map_Get());
fn_800408A8(0); fn_8004084C();
obj=*(u8**)((u8*)arg0+0x48);
fn_801F1888(obj+4); fn_800D5894(obj);
obj=*(u8**)((u8*)arg0+0x48);
if(obj) {
Array_Destroy(obj+140,String_Destroy,12,2);
Array_Destroy(obj+116,String_Destroy,12,2);
Array_Destroy(obj+92,String_Destroy,12,2);
Array_Destroy(obj+68,String_Destroy,12,2);
Array_Destroy(obj+44,String_Destroy,12,2);
Array_Destroy(obj+20,String_Destroy,12,2);
if(obj+4) {if(obj+4) {if(*(void**)(obj+8)) BinTree_Destroy(obj+4,*(void**)(obj+8));}}
Heap_Free(obj);
}
fn_8005376C();
}

void fn_801EED74(void) {
    M2C_UNK fn_801EE0C8();
    fn_801EE0C8();
}

void fn_801EED94(void) {
    M2C_UNK fn_801EE76C();
    fn_801EE76C();
}

void fn_801EEDB4(void *arg0) {
void *Map_Get(void); void Map_UpdateTransforms(void*);
void PSMTXScale(void*,f32,f32,f32); void PSMTXRotRad(void*,s32,f32);
void PSMTXConcat(void*,void*,void*); void PSMTXCopy(void*,void*);
s32 fn_800E49D0(void); void fn_800E4A78(void*,void*); void Model_SetAlpha(void*,s32);
void *fn_8006049C(void*); void *GActor_GetNodeTable(void*); void MTXRotDegOrder(void*,void*);
void fn_800606BC(void*); void fn_80060060(void*); void fn_8006CAD4(void*); void LightFade_Start(void);
extern f32 lbl_8036B7C8,lbl_8036B7B8,lbl_8036B7CC;
f32 node[3][4],combined[3][4],rotation[3][4],scale[3][4];
u32 alpha;
u8 *matrices;
u8 *obj=*(u8**)((u8*)arg0+0x48);
void *map=Map_Get();
++*(s32*)(obj+0xD4);
if(map) Map_UpdateTransforms(map);
if(*(void**)(obj+0xB8)) {
PSMTXScale(scale,lbl_8036B7C8,lbl_8036B7C8,lbl_8036B7C8);
PSMTXRotRad(rotation,0x59,lbl_8036B7B8);
PSMTXConcat(rotation,scale,combined);
PSMTXCopy(combined,*(u8**)(obj+0xB8)+0x10);
alpha=fn_800E49D0() & 255;
fn_800E4A78(*(void**)(obj+0xBC),*(void**)(obj+0xB8));
Model_SetAlpha(*(void**)(obj+0xBC),alpha);
if(*(void**)(obj+0xC4)) {
matrices=fn_8006049C(*(void**)(obj+0xB8));
MTXRotDegOrder(*(u8**)((u8*)GActor_GetNodeTable(*(void**)(obj+0xB8))+12)+*(s32*)(obj+0xA4)*0xF4,node);
PSMTXConcat(matrices+*(s32*)(obj+0xA4)*0x30,node,node);
PSMTXConcat(*(u8**)(obj+0xB8)+0x10,node,*(u8**)(obj+0xC4)+0x10);
fn_800E4A78(*(void**)(obj+0xC8),*(void**)(obj+0xC4));
Model_SetAlpha(*(void**)(obj+0xC8),alpha);
}
}
if(*(void**)(obj+0xD0)) {
PSMTXScale(combined,lbl_8036B7CC,lbl_8036B7CC,lbl_8036B7CC);
PSMTXCopy(combined,*(u8**)(obj+0xD0)+0x10);
}
if(*(void**)(obj+0xD0)) fn_800606BC(*(void**)(obj+0xD0));
if(*(void**)(obj+0xB8)) {
fn_80060060(*(void**)(obj+0xB8));
fn_800606BC(*(void**)(obj+0xB8));
fn_8006CAD4(*(void**)(obj+0xBC));
if(*(void**)(obj+0xC4)) {
fn_800606BC(*(void**)(obj+0xC4)); fn_800606BC(*(void**)(obj+0xC8));
}
}
LightFade_Start();
}

/* Build asset paths for entry arg1 and load model/tex/anim into a new GActor hierarchy. */
void GActor_LoadResources(void *arg0, s32 arg1)
{
    s32 FileCache_Load(void);
    void Model_SetAlpha(void *, s32);
    void Model_SetColor(void *, s32, s32, s32);
    void *GActor_FindNode(void *, char *);
    void GActor_Finalize(void *);
    void *GActor_Create(void);
    s32 fn_800639B4(void);
    s32 fn_80065EE8(void);
    s32 fn_8006CE14(void);
    s32 fn_8006D948(void);
    void *String_CStr(void *);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_Copy(void *, void *);
    void String_Concat(void *, void *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void String_JoinCStr(void *, char *, void *);
    s32 fn_800E49D0(void);
    void fn_801C4468(void *);
    void fn_801C6E60(void *);
    void fn_801EF39C(void *, void *, s32);
    extern char gGActorPathExt[];
    extern u8 gBattle[];

    String path;
    String baseName;
    String dir;
    String sp98;
    String sp8C;
    String sp80;
    String sp74;
    String sp68;
    String sp5C;
    String sp50;
    String sp44;
    String sp38;
    String sp2C;
    String sp20;
    String sp14;
    String sp8;
    void *self;
    void *nameField;
    u8 *row;
    void *actor;
    void *tmp;
    void **slot;
    void *p;
    u8 val;

    self = arg0;

    path.cap = 0;
    path.size = 0;
    path.data = 0;
    path.cap = 0;
    fn_801EF39C(&sp98, self, arg1);
    String_Copy(&baseName, &sp98);
    String_Destroy(&sp98, -1);
    String_JoinCStr(&sp8C, gGActorPathExt + 0x1BB, &baseName);
    String_ConcatCStr(&sp80, &sp8C, gGActorPathExt + 0x1BF);
    String_Copy(&dir, &sp80);
    String_Destroy(&sp80, -1);
    String_Destroy(&sp8C, -1);
    String_Concat(&sp74, &dir, &baseName);
    String_ConcatCStr(&sp68, &sp74, gGActorPathExt + 0x1C1);
    String_Assign(&path, &sp68, 0, -1);
    String_Destroy(&sp68, -1);
    String_Destroy(&sp74, -1);
    String_CStr(&path);
    *(s32 *)((u8 *)self + 0xB4) = FileCache_Load();
    *(void **)((u8 *)self + 0xB8) = GActor_Create();
    row = (u8 *)self + arg1 * 0xC;
    nameField = row + 0x44;
    String_Concat(&sp5C, &dir, nameField);
    String_ConcatCStr(&sp50, &sp5C, gGActorPathExt + 0x208);
    String_Assign(&path, &sp50, 0, -1);
    String_Destroy(&sp50, -1);
    String_Destroy(&sp5C, -1);
    String_CStr(&path);
    tmp = (void *)fn_8006CE14();
    actor = *(void **)((u8 *)self + 0xB8);
    *(s32 *)((u8 *)actor + 0x48) = (s32)tmp;
    String_Concat(&sp44, &dir, nameField);
    String_ConcatCStr(&sp38, &sp44, gGActorPathExt + 0x20C);
    String_Assign(&path, &sp38, 0, -1);
    String_Destroy(&sp38, -1);
    String_Destroy(&sp44, -1);
    String_CStr(&path);
    tmp = (void *)fn_80065EE8();
    actor = *(void **)((u8 *)self + 0xB8);
    *(s32 *)((u8 *)actor + 0x40) = (s32)tmp;
    String_Concat(&sp2C, &dir, row + 0x14);
    String_ConcatCStr(&sp20, &sp2C, gGActorPathExt + 0x1C9);
    String_Assign(&path, &sp20, 0, -1);
    String_Destroy(&sp20, -1);
    String_Destroy(&sp2C, -1);
    String_CStr(&path);
    tmp = (void *)fn_8006D948();
    actor = *(void **)((u8 *)self + 0xB8);
    *(s32 *)((u8 *)actor + 0x4C) = (s32)tmp;
    String_Concat(&sp14, &dir, row + 0x2C);
    String_ConcatCStr(&sp8, &sp14, gGActorPathExt + 0x20F);
    String_Assign(&path, &sp8, 0, -1);
    String_Destroy(&sp8, -1);
    String_Destroy(&sp14, -1);
    String_CStr(&path);
    tmp = (void *)fn_800639B4();
    actor = *(void **)((u8 *)self + 0xB8);
    *(s32 *)((u8 *)actor + 0x44) = (s32)tmp;
    GActor_Finalize(*(void **)((u8 *)self + 0xB8));
    actor = *(void **)((u8 *)self + 0xB8);
    *(u32 *)actor |= 0x8000;
    actor = *(void **)((u8 *)self + 0xB8);
    *(u8 *)((u8 *)actor + 0x85) |= 0xF0;
    *(u8 *)((u8 *)*(void **)((u8 *)self + 0xB8) + 0x84) = 0xFF;
    *(u8 *)((u8 *)*(void **)((u8 *)self + 0xB8) + 0x87) = 4;
    nameField = *(void **)((u8 *)self + 0xB8);
    *(void **)((u8 *)self + 0xBC) = GActor_Create();
    actor = *(void **)((u8 *)self + 0xBC);
    *(void **)((u8 *)actor + 4) = nameField;
    Model_SetColor(*(void **)((u8 *)self + 0xBC), 0, 0, 0);
    Model_SetAlpha(*(void **)((u8 *)self + 0xBC), fn_800E49D0());
    actor = *(void **)((u8 *)self + 0xBC);
    *(u8 *)((u8 *)actor + 0x87) = 0;
    actor = *(void **)((u8 *)self + 0xBC);
    *(u32 *)actor |= 0x4001E400;
    slot = (void **)(gBattle + 0x28C);
    if (slot != NULL && (p = *slot, p != NULL)) {
        val = (p != NULL) ? *(u8 *)((u8 *)p + 0x12) : 0xC;
        if ((u8)val == 3) {
            *(void **)((u8 *)self + 0xA4) = GActor_FindNode(*(void **)((u8 *)self + 0xB8), gGActorPathExt + 0x213);
        } else {
            goto block_else;
        }
    } else {
block_else:
        *(void **)((u8 *)self + 0xA4) = GActor_FindNode(*(void **)((u8 *)self + 0xB8), gGActorPathExt + 0x21A);
    }
    if (*(s32 *)((u8 *)self + 0xAC) == 2) {
        fn_801C4468(*(void **)((u8 *)self + 0xB8));
        fn_801C6E60(*(void **)((u8 *)self + 0xB8));
    }
    String_Destroy(&dir, -1);
    String_Destroy(&baseName, -1);
    String_Destroy(&path, -1);
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
void fn_801EF39C(String *arg0, u8 *arg1, s32 arg2)
{
  s32 String_Compare(String *, s32, s32, char *, s32);
  void String_Assign(String *, void *, s32, s32);
  void String_Destroy(String *, s32);
  void String_Init(String *, char *, void *);
  void String_Copy(String *, void *);
  void String_Concat(String *, String *, String *);
  u8 *entry;
  void String_ConcatCStr(String *, String *, char *);
  void *StringMap_FindOrInsert(void *, String *);
  s32 strlen(char *);
  extern char gGActorPathExt[];
  String sp54;
  String sp48;
  String sp3C;
  String sp30;
  String sp24;
  String sp18;
  String spC;
  u8 sp8[4];
  s32 n;
  char *str;
  u8 *row;
  String *out;
  u8 *base;
  sp54.cap = 0;
  sp48.cap = 0;
  sp54.size = 0;
  sp54.data = 0;
  sp54.cap = 0;
  sp48.size = 0;
  sp48.data = 0;
  sp48.cap = 0;
  out = arg0;
  base = arg1;
  row = base + (arg2 * 0xC);
  String_Copy(&sp3C, row + 0x74);
  String_Copy(&sp30, row + 0x5C);
  String_Copy(&sp24, row + 0x8C);
  entry = ((u8 *) StringMap_FindOrInsert(base + 4, &sp24)) + 0xC;
  String_Assign(&sp48, entry, 0, -1);
  str = gGActorPathExt;
  str += 0x221;
  n = strlen(str);
  str = gGActorPathExt;
  if (String_Compare(&sp48, 0, (s32) sp48.size, str + 0x221, n) != 0)
  {
    String_Copy(out, &sp48);
    String_Destroy(&sp24, -1);
    String_Destroy(&sp30, -1);
    String_Destroy(&sp3C, -1);
    String_Destroy(&sp48, -1);
    String_Destroy(&sp54, -1);
    return;
  }
  String_ConcatCStr(&sp18, &sp3C, (char *) (((u8 *) gGActorPathExt) + 0x222));
  String_Concat(&spC, &sp18, &sp30);
  String_Assign(&sp54, &spC, 0, -1);
  String_Destroy(&spC, -1);
  String_Destroy(&sp18, -1);
  entry = ((u8 *) StringMap_FindOrInsert(base + 4, &sp54)) + 0xC;
  String_Assign(&sp48, entry, 0, -1);
  str = gGActorPathExt;
  str += 0x221;
  n = strlen(str);
  str = gGActorPathExt;
  if (String_Compare(&sp48, 0, (s32) sp48.size, str + 0x221, n) != 0)
  {
    String_Copy(out, &sp48);
    String_Destroy(&sp24, -1);
    String_Destroy(&sp30, -1);
    String_Destroy(&sp3C, -1);
    String_Destroy(&sp48, -1);
    String_Destroy(&sp54, -1);
    return;
  }
  entry = ((u8 *) StringMap_FindOrInsert(base + 4, &sp3C)) + 0xC;
  String_Assign(&sp48, entry, 0, -1);
  str = gGActorPathExt;
  str += 0x221;
  n = strlen(str);
  str = gGActorPathExt;
  if (String_Compare(&sp48, 0, (s32) sp48.size, str + 0x221, n) != 0)
  {
    String_Copy(out, &sp48);
    String_Destroy(&sp24, -1);
    String_Destroy(&sp30, -1);
    String_Destroy(&sp3C, -1);
    String_Destroy(&sp48, -1);
    String_Destroy(&sp54, -1);
    return;
  }
  String_Init(out, (char *) (((u8 *) gGActorPathExt) + 0x221), sp8);
  String_Destroy(&sp24, -1);
  String_Destroy(&sp30, -1);
  String_Destroy(&sp3C, -1);
  String_Destroy(&sp48, -1);
  String_Destroy(&sp54, -1);
}
#pragma pop
void fn_801EF6BC(void *arg0) {
    typedef struct { u32 unk0; char name[4]; } Named;
    u16 FileCache_Probe(void);
    s32 FileCache_Load(void);
    void Model_SetAlpha(void *, s32);
    void Model_SetColor(void *, s32, s32, s32);
    void GActor_Finalize(void *);
    void *GActor_Create(void);
    s32 fn_80065EE8(void);
    s32 fn_8006CE14(void);
    s32 fn_8006D948(void);
    void fn_8008CDE0(void *, void *);
    void *String_CStr(void *);
    void String_AssignCStr(void *, char *, s32);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_Init(void *, char *, void *);
    void String_Concat(void *, void *, void *);
    void String_ConcatCStr(void *, void *, char *);
    s32 fn_800E49D0(void);
    void fn_801C6E60(void *);
    s32 strlen(char *);
    extern char gGActorPathExt[];
    extern u8 gBattle[];

    String spE4;
    String spD8;
    String spCC;
    String spC0;
    String spB4;
    String spA8;
    String sp9C;
    String sp90;
    String sp84;
    String sp78;
    String sp6C;
    String sp60;
    String sp54;
    String sp48;
    String sp3C;
    String sp30;
    String sp24;
    String sp18;
    String spC;
    void *sp8;
    void *slot;
    void *self;
    Named *p;
    void *obj;
    void *tmp;

    self = arg0;

    spE4.cap = 0;
    spD8.cap = 0;
    spE4.size = 0;
    spE4.data = 0;
    spE4.cap = 0;
    spD8.size = 0;
    spD8.data = 0;
    spD8.cap = 0;
    String_Init(&spCC, gGActorPathExt + 0x224, &sp8);
    p = 0;
    *(void **)((u8 *)self + 0xC0) = p;
    slot = gBattle + 0x28C;
    *(void **)((u8 *)self + 0xC4) = p;
    if (slot == NULL || *(void **)slot == NULL) {
        String_Destroy(&spCC, -1);
        String_Destroy(&spD8, -1);
        String_Destroy(&spE4, -1);
        return;
    }
    if (*(void **)slot != NULL) {
        p = *(Named **)*(void **)slot;
    }
    String_AssignCStr(&spD8, p->name, strlen(p->name));
    String_Concat(&spC0, &spCC, &spD8);
    String_ConcatCStr(&spB4, &spC0, gGActorPathExt + 0x1BF);
    String_Concat(&spA8, &spB4, &spD8);
    String_ConcatCStr(&sp9C, &spA8, gGActorPathExt + 0x229);
    String_Assign(&spE4, &sp9C, 0, -1);
    String_Destroy(&sp9C, -1);
    String_Destroy(&spA8, -1);
    String_Destroy(&spB4, -1);
    String_Destroy(&spC0, -1);
    String_CStr(&spE4);
    if ((u16)FileCache_Probe() != 0x8000) {
        String_CStr(&spE4);
        *(s32 *)((u8 *)self + 0xC0) = FileCache_Load();
        *(void **)((u8 *)self + 0xC4) = GActor_Create();
        String_Concat(&sp90, &spCC, &spD8);
        String_ConcatCStr(&sp84, &sp90, (char *)((u32)gGActorPathExt + 0x1BF));
        String_Concat(&sp78, &sp84, &spD8);
        String_ConcatCStr(&sp6C, &sp78, gGActorPathExt + 0x208);
        String_Assign(&spE4, &sp6C, 0, -1);
        String_Destroy(&sp6C, -1);
        String_Destroy(&sp78, -1);
        String_Destroy(&sp84, -1);
        String_Destroy(&sp90, -1);
        String_CStr(&spE4);
        tmp = (void *)fn_8006CE14();
        obj = *(void **)((u8 *)self + 0xC4);
        *(s32 *)((u8 *)obj + 0x48) = (s32)tmp;
        String_Concat(&sp60, &spCC, &spD8);
        String_ConcatCStr(&sp54, &sp60, (char *)((u8 *)gGActorPathExt + 0x1BF));
        String_Concat(&sp48, &sp54, &spD8);
        String_ConcatCStr(&sp3C, &sp48, gGActorPathExt + 0x20C);
        String_Assign(&spE4, &sp3C, 0, -1);
        String_Destroy(&sp3C, -1);
        String_Destroy(&sp48, -1);
        String_Destroy(&sp54, -1);
        String_Destroy(&sp60, -1);
        String_CStr(&spE4);
        tmp = (void *)fn_80065EE8();
        obj = *(void **)((u8 *)self + 0xC4);
        *(s32 *)((u8 *)obj + 0x40) = (s32)tmp;
        String_Concat(&sp30, &spCC, &spD8);
        String_ConcatCStr(&sp24, &sp30, (char *)((s32)gGActorPathExt + 0x1BF));
        String_Concat(&sp18, &sp24, &spD8);
        String_ConcatCStr(&spC, &sp18, gGActorPathExt + 0x1C9);
        String_Assign(&spE4, &spC, 0, -1);
        String_Destroy(&spC, -1);
        String_Destroy(&sp18, -1);
        String_Destroy(&sp24, -1);
        String_Destroy(&sp30, -1);
        String_CStr(&spE4);
        tmp = (void *)fn_8006D948();
        obj = *(void **)((u8 *)self + 0xC4);
        *(s32 *)((u8 *)obj + 0x4C) = (s32)tmp;
        GActor_Finalize(*(void **)((u8 *)self + 0xC4));
        obj = *(void **)((u8 *)self + 0xC4);
        *(u32 *)obj |= 0x8000;
        obj = *(void **)((u8 *)self + 0xC4);
        *(u8 *)((u8 *)obj + 0x85) |= 0xF0;
        *(u8 *)((u8 *)*(void **)((u8 *)self + 0xC4) + 0x84) = 0xFF;
        *(u8 *)((u8 *)*(void **)((u8 *)self + 0xC4) + 0x87) = 4;
        fn_8008CDE0(*(void **)((u8 *)self + 0xC4), slot);
        slot = *(void **)((u8 *)self + 0xC4);
        *(void **)((u8 *)self + 0xC8) = GActor_Create();
        obj = *(void **)((u8 *)self + 0xC8);
        *(void **)((u8 *)obj + 4) = slot;
        Model_SetColor(*(void **)((u8 *)self + 0xC8), 0, 0, 0);
        Model_SetAlpha(*(void **)((u8 *)self + 0xC8), fn_800E49D0());
        obj = *(void **)((u8 *)self + 0xC8);
        *(u8 *)((u8 *)obj + 0x87) = 0;
        obj = *(void **)((u8 *)self + 0xC8);
        *(u32 *)obj |= 0x4001E400;
        fn_801C6E60(*(void **)((u8 *)self + 0xC4));
        (void)p;
    } else {
        (void)p;
    }
    String_Destroy(&spCC, -1);
    String_Destroy(&spD8, -1);
    String_Destroy(&spE4, -1);
}
void GActor_LoadByName(void *arg0, char *name) {
    /* Build asset paths from name and load model/tex/anim into a new GActor at +0xD0. */
    void *Map_Get(void *);
    s32 FileCache_Load(void);
    void GActor_Finalize(void *);
    void *GActor_Create(void);
    s32 fn_800639B4(void);
    s32 fn_80065EE8(void);
    s32 fn_8006CE14(void);
    s32 fn_8006D948(void);
    void *String_CStr(void *);
    void String_Assign(void *, void *, s32, s32);
    void fn_800C992C(void *, char *, s32);
    void String_Destroy(void *, s32);
    void String_Init(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    s32 strlen(char *);
    extern char gGActorPathExt[];
    extern f32 gGActorDefaultScale;

    String path;
    String dir;
    String sp3C;
    String sp30;
    String sp24;
    String sp18;
    String spC;
    void *sp8;
    void *self;
    void *actor;
    void *tmp;
    s32 n;
    f32 scale;

    self = arg0;
    if (name == NULL || *(s32 *)((u8 *)self + 0xA8) != 0) {
        *(void **)((u8 *)self + 0xD0) = NULL;
        return;
    }

    path.cap = 0;
    path.size = 0;
    path.data = 0;
    path.cap = 0;
    String_Init(&dir, gGActorPathExt + 0x1D6, &sp8);
    n = strlen(name);
    fn_800C992C(&dir, name, n);
    n = strlen((char *)((u32)gGActorPathExt + 0x1BF));
    fn_800C992C(&dir, (char *)((u8 *)gGActorPathExt + 0x1BF), n);
    n = strlen(name);
    fn_800C992C(&dir, name, n);
    String_ConcatCStr(&sp3C, &dir, gGActorPathExt + 0x229);
    String_Assign(&path, &sp3C, 0, -1);
    String_Destroy(&sp3C, -1);
    String_CStr(&path);
    *(s32 *)((u8 *)self + 0xCC) = FileCache_Load();
    *(void **)((u8 *)self + 0xD0) = GActor_Create();
    String_ConcatCStr(&sp30, &dir, gGActorPathExt + 0x208);
    String_Assign(&path, &sp30, 0, -1);
    String_Destroy(&sp30, -1);
    String_CStr(&path);
    tmp = (void *)fn_8006CE14();
    actor = *(void **)((u8 *)self + 0xD0);
    *(s32 *)((u8 *)actor + 0x48) = (s32)tmp;
    String_ConcatCStr(&sp24, &dir, gGActorPathExt + 0x20C);
    String_Assign(&path, &sp24, 0, -1);
    String_Destroy(&sp24, -1);
    String_CStr(&path);
    tmp = (void *)fn_80065EE8();
    actor = *(void **)((u8 *)self + 0xD0);
    *(s32 *)((u8 *)actor + 0x40) = (s32)tmp;
    String_ConcatCStr(&sp18, &dir, gGActorPathExt + 0x1C9);
    String_Assign(&path, &sp18, 0, -1);
    String_Destroy(&sp18, -1);
    String_CStr(&path);
    tmp = (void *)fn_8006D948();
    actor = *(void **)((u8 *)self + 0xD0);
    *(s32 *)((u8 *)actor + 0x4C) = (s32)tmp;
    String_ConcatCStr(&spC, &dir, gGActorPathExt + 0x20F);
    String_Assign(&path, &spC, 0, -1);
    String_Destroy(&spC, -1);
    String_CStr(&path);
    tmp = (void *)fn_800639B4();
    actor = *(void **)((u8 *)self + 0xD0);
    *(s32 *)((u8 *)actor + 0x44) = (s32)tmp;
    GActor_Finalize(*(void **)((u8 *)self + 0xD0));
    actor = *(void **)((u8 *)self + 0xD0);
    scale = gGActorDefaultScale;
    *(u32 *)actor |= 0x01040000;
    actor = *(void **)((u8 *)self + 0xD0);
    *(f32 *)((u8 *)actor + 0x5C) = scale;
    tmp = Map_Get(actor);
    *(void **)((u8 *)tmp + 0x34) = *(void **)((u8 *)self + 0xD0);
    String_Destroy(&dir, -1);
    String_Destroy(&path, -1);
}

#pragma global_optimizer off
#pragma use_lmw_stmw on
void fn_801EFDC8(void *arg0) {
    void fn_800D58C0(void);
    void String_Init(String *, char *, void *);
    void fn_800C992C(String *, char *, s32);
    void *Heap_Alloc(s32);
    void *Xml_ParseFile(void *, String *, String *);
    void String_Destroy(String *, s32);
    void Str_CopyPad(void *, char *, s32);
    void fn_800C908C(void *, String *, void *);
    u8 Xml_AdvanceChild(void *);
    void Xml_GetChildName(String *, void *);
    void String_Assign(String *, String *, s32, s32);
    void Xml_GetChildValue(char *, void *);
    void String_AssignCStr(String *, char *, s32);
    s32 String_Find(String *, char *, s32, s32);
    void String_Substr(String *, String *, s32, s32);
    void String_JoinCStr(String *, char *, String *);
    void fn_800C99A0(String *, String *, s32, s32);
    void *StringMap_FindOrInsert(void *, String *);
    void Xml_Destroy(void *, s32);
    char *Unit_GetMapModelName(void *);
    void fn_801EF39C(String *, void *, s32);
    void String_Concat(String *, String *, String *);
    void String_ConcatCStr(String *, String *, char *);
    s32 String_Compare(String *, s32, void *, char *, s32);
    void fn_800D6878(void *, void *, void *);
    void Xml_GetNamedValue(char *, void *, String *);
    void fn_801F1888(void *);
    s32 strlen(char *);
    extern char gGActorPathExt[];
    extern char lbl_8027F25C[];
    extern u8 gBattle[];

    char buf260[0x20];
    char buf224[0x20];
    char buf204[0x20];
    char buf1E4[0x20];
    char buf1C4[0x20];
    char buf1A4[0x20];
    char buf184[0x20];
    String path;
    String str16c;
    String str160;
    String str154;
    String str148;
    String str13c;
    String str130;
    String str124;
    u32 classNames[4];
    void *tree[4];
    String spF8;
    String spEC;
    String spE0;
    String spD4;
    String spC8;
    String spBC;
    String spB0;
    String spA4;
    String sp98;
    String sp8C;
    String sp80;
    String sp74;
    String sp68;
    String sp5C;
    String sp50;
    String sp44;
    String sp38;
    void *mgrs[2];
    void *sp2C, *sp28, *sp24, *sp20, *sp1C, *sp18, *sp14, *sp10, *spC, *sp8;
    void **slot;
    char *s;
    char *strBase;
    void *self;
    void *base;
    void *file;
    void *file2;
    char *p204;
    s32 i, j, pos, count, kind;
    s8 flag0, flag1, flag2;

    self = arg0;
    fn_800D58C0();
    String_Init(&path, gGActorPathExt + 0x22E, &sp2C);
    fn_800C992C(&path, gGActorPathExt + 0x234, strlen(gGActorPathExt + 0x234));
    flag0 = 0;
    file = Heap_Alloc(0x60);
    if (file) {
        String_Init(&spF8, gGActorPathExt + 0x1DB, &sp28);
        flag0 = 1;
        file = Xml_ParseFile(file, &path, &spF8);
    }
    if (flag0) {
        String_Destroy(&spF8, -1);
    }

    str16c.cap = 0;
    str160.cap = 0;
    str16c.size = 0;
    str16c.data = NULL;
    str16c.cap = 0;
    str160.size = 0;
    str160.data = NULL;
    str160.cap = 0;
    String_Init(&spEC, gGActorPathExt + 0x240, &sp24);
    Str_CopyPad(buf224, gGActorPathExt + 0x246, 0x20);
    {
        u32 *d = (u32 *)buf260;
        u32 *s2 = (u32 *)buf224;
        d[0] = s2[0]; d[1] = s2[1]; d[2] = s2[2]; d[3] = s2[3];
        d[4] = s2[4]; d[5] = s2[5]; d[6] = s2[6]; d[7] = s2[7];
    }
    fn_800C908C(file, &spEC, buf260);
    String_Destroy(&spEC, -1);

    p204 = buf204;
    strBase = gGActorPathExt;
    while (Xml_AdvanceChild(file) != 0) {
        Xml_GetChildName(&spE0, file);
        String_Assign(&str16c, &spE0, 0, -1);
        String_Destroy(&spE0, -1);
        Xml_GetChildValue(p204, file);
        String_AssignCStr(&str160, p204, strlen(p204));
        pos = String_Find(&str160, strBase + 0x24E, 0, strlen(strBase + 0x24E));
        if ((u32)(pos + 0x10000) != 0xFFFFFFFFU) {
            String_Substr(&spD4, &str160, 0, pos);
            String_JoinCStr(&spC8, strBase + 0x222, &spD4);
            fn_800C99A0(&str16c, &spC8, 0, -1);
            String_Destroy(&spC8, -1);
            String_Destroy(&spD4, -1);
            String_Substr(&spBC, &str160, pos + 1, 4);
            String_Assign(&str160, &spBC, 0, -1);
            String_Destroy(&spBC, -1);
        }
        String_Assign((String *)((u8 *)StringMap_FindOrInsert((u8 *)self + 4, &str16c) + 0xC), &str160, 0, -1);
    }
    Xml_Destroy(file, 1);

    str154.cap = 0;
    str148.cap = 0;
    str154.size = 0;
    str154.data = NULL;
    str154.cap = 0;
    str148.size = 0;
    str148.data = NULL;
    str148.cap = 0;
    String_Init(&str13c, gGActorPathExt + 0x1BB, &sp20);

    str130.cap = 0;
    str124.cap = 0;
    str130.size = 0;
    str130.data = NULL;
    str130.cap = 0;
    str124.size = 0;
    str124.data = NULL;
    str124.cap = 0;
    {
        u32 *src = (u32 *)lbl_8027F25C;
        classNames[0] = src[0];
        classNames[1] = src[1];
        classNames[2] = src[2];
        classNames[3] = src[3];
    }
    mgrs[0] = gBattle;
    mgrs[1] = gBattle + 0x2E0;
    slot = mgrs;
    base = self;
    strBase = gGActorPathExt;
    for (i = 0; i < 2; i++) {
        s = *(char **)(*(void **)((u8 *)*slot + 0x188));
        String_AssignCStr((String *)((u8 *)base + 0x5C), s, strlen(s));
        s = *(char **)(*(void **)((u8 *)*slot + 0x18C));
        String_AssignCStr((String *)((u8 *)base + 0x74), s, strlen(s));
        s = Unit_GetMapModelName(*slot);
        String_AssignCStr((String *)((u8 *)base + 0x8C), s, strlen(s));
        kind = *(u8 *)(*(u8 **)((u8 *)*slot + 0x190) + 8);
        if (kind == 5) {
            kind = 0;
        }
        fn_801EF39C(&spB0, self, i);
        String_Assign(&str148, &spB0, 0, -1);
        String_Destroy(&spB0, -1);
        String_AssignCStr((String *)((u8 *)base + 0x2C), strBase + 0x221, strlen(strBase + 0x221));
        String_AssignCStr((String *)((u8 *)base + 0x44), strBase + 0x221, strlen(strBase + 0x221));

        flag0 = 0;
        flag1 = 0;
        flag2 = 0;
        file2 = Heap_Alloc(0x60);
        if (file2) {
            String_Init(&spA4, gGActorPathExt + 0x1DB, &sp1C);
            flag0 = 1;
            String_Concat(&sp98, &str13c, &str148);
            flag1 = 1;
            String_ConcatCStr(&sp8C, &sp98, strBase + 0x250);
            flag2 = 1;
            file2 = Xml_ParseFile(file2, &sp8C, &spA4);
        }
        if (flag2 != 0) String_Destroy(&sp8C, -1);
        if (flag1 != 0) String_Destroy(&sp98, -1);
        if (flag0 != 0) String_Destroy(&spA4, -1);

        {
            String *field44 = (String *)((u8 *)base + 0x44);
            while (Xml_AdvanceChild(file2) != 0) {
                Xml_GetChildName(&sp80, file2);
                String_Assign(&str154, &sp80, 0, -1);
                String_Destroy(&sp80, -1);
                if (String_Compare(&str154, 0, str154.data, strBase + 0x255, strlen(strBase + 0x255)) == 0) {
                    Xml_GetChildValue(buf1E4, file2);
                    String_AssignCStr(field44, buf1E4, strlen(buf1E4));
                }
                if (String_Compare(&str154, 0, str154.data, strBase + 0x25B, strlen(strBase + 0x25B)) == 0) {
                    Xml_GetChildValue(buf1C4, file2);
                    String_AssignCStr((String *)((u8 *)base + 0x2C), buf1C4, strlen(buf1C4));
                    break;
                }
            }
        }
        Xml_Destroy(file2, 1);

        fn_800D6878(tree, &sp8, &spC);
        flag0 = 0;
        flag1 = 0;
        flag2 = 0;
        file2 = Heap_Alloc(0x60);
        if (file2) {
            String_Init(&sp74, gGActorPathExt + 0x1DB, &sp18);
            flag0 = 1;
            String_Concat(&sp68, &str13c, &str148);
            flag1 = 1;
            String_ConcatCStr(&sp5C, &sp68, strBase + 0x263);
            flag2 = 1;
            file2 = Xml_ParseFile(file2, &sp5C, &sp74);
        }
        if (flag2 != 0) String_Destroy(&sp5C, -1);
        if (flag1 != 0) String_Destroy(&sp68, -1);
        if (flag0 != 0) String_Destroy(&sp74, -1);

        String_Init(&sp50, strBase + 0x26C, &sp14);
        Xml_GetNamedValue(buf1A4, file2, &sp50);
        count = *(s32 *)buf1A4;
        String_Destroy(&sp50, -1);

        for (j = 0; j < count; j++) {
            Xml_AdvanceChild(file2);
            Xml_GetChildName(&sp44, file2);
            String_Assign(&str130, &sp44, 0, -1);
            String_Destroy(&sp44, -1);
            Xml_GetChildValue(buf184, file2);
            String_AssignCStr(&str124, buf184, strlen(buf184));
            String_Assign((String *)((u8 *)StringMap_FindOrInsert(tree, &str130) + 0xC), &str124, 0, -1);
        }
        Xml_Destroy(file2, 1);

        String_Assign(&str124, (String *)((u8 *)StringMap_FindOrInsert(tree, (String *)((u8 *)base + 0x8C)) + 0xC), 0, -1);
        if (String_Compare(&str124, 0, str124.data, strBase + 0x221, strlen(strBase + 0x221)) == 0) {
            String_Assign(&str124, (String *)((u8 *)StringMap_FindOrInsert(tree, (String *)((u8 *)base + 0x5C)) + 0xC), 0, -1);
        }
        if (String_Compare(&str124, 0, str124.data, strBase + 0x221, strlen(strBase + 0x221)) == 0) {
            String_Init(&sp38, (char *)classNames[kind & 3], &sp10);
            String_Assign(&str124, (String *)((u8 *)StringMap_FindOrInsert(tree, &sp38) + 0xC), 0, -1);
            String_Destroy(&sp38, -1);
        }
        if (String_Compare(&str124, 0, str124.data, strBase + 0x221, strlen(strBase + 0x221)) == 0) {
            String_Assign((String *)((u8 *)base + 0x14), &str148, 0, -1);
        } else {
            String_Assign((String *)((u8 *)base + 0x14), &str124, 0, -1);
        }
        fn_801F1888(tree);
        base = (u8 *)base + 0xC;
        slot++;
    }

    String_Destroy(&str124, -1);
    String_Destroy(&str130, -1);
    String_Destroy(&str13c, -1);
    String_Destroy(&str148, -1);
    String_Destroy(&str154, -1);
    String_Destroy(&str160, -1);
    String_Destroy(&str16c, -1);
    String_Destroy(&path, -1);
}
#pragma global_optimizer reset
void fn_801F0718(void *arg0) {
    f32 fn_80059500(f32, f32, f32, f32, f32);
    void *fn_80068548(void);
    void fn_80202300(void *, s32, f32);
    void fn_802029C4(void *, void *, void *);
    void fn_80203184(void *, void *, void *);
    void fn_80067FE8(void *, void *, void *);
    void fn_8000C188(void *);
    extern f32 lbl_8036B7C8;
    extern f32 lbl_8036B7D4;
    extern f64 lbl_8036B7D8;
    extern u8 lbl_8027F250[];

    struct Cam {
        u8 pad[0xD4];
        f32 at[3];
        f32 eye[3];
        f32 unkEC;
    };

    f32 vec[3];
    u8 mtx44[0x30];
    u8 mtx14[0x30];
    struct Cam *cam;
    f32 t;
    f32 f27, f28, f29, f30, f31, ftmp;
    f32 angle;
    u32 *src;
    u16 n;

    cam = (struct Cam *)fn_80068548();
    t = lbl_8036B7C8;
    n = *(u16 *)((u8 *)arg0 + 0x4C);
    if (n != 0) {
        t = (f32)*(u16 *)((u8 *)arg0 + 0x4E) / (f32)n;
    }
    f27 = fn_80059500(
        (*(f32 **)((u8 *)arg0 + 0x38))[0],
        (*(f32 **)((u8 *)arg0 + 0x3C))[0],
        (*(f32 **)((u8 *)arg0 + 0x40))[0],
        (*(f32 **)((u8 *)arg0 + 0x44))[0], t);
    f28 = fn_80059500(
        (*(f32 **)((u8 *)arg0 + 0x38))[1],
        (*(f32 **)((u8 *)arg0 + 0x3C))[1],
        (*(f32 **)((u8 *)arg0 + 0x40))[1],
        (*(f32 **)((u8 *)arg0 + 0x44))[1], t);
    f29 = fn_80059500(
        (*(f32 **)((u8 *)arg0 + 0x38))[2],
        (*(f32 **)((u8 *)arg0 + 0x3C))[2],
        (*(f32 **)((u8 *)arg0 + 0x40))[2],
        (*(f32 **)((u8 *)arg0 + 0x44))[2], t);
    f30 = fn_80059500(
        (*(f32 **)((u8 *)arg0 + 0x38))[3],
        (*(f32 **)((u8 *)arg0 + 0x3C))[3],
        (*(f32 **)((u8 *)arg0 + 0x40))[3],
        (*(f32 **)((u8 *)arg0 + 0x44))[3], t);
    f31 = fn_80059500(
        (*(f32 **)((u8 *)arg0 + 0x38))[4],
        (*(f32 **)((u8 *)arg0 + 0x3C))[4],
        (*(f32 **)((u8 *)arg0 + 0x40))[4],
        (*(f32 **)((u8 *)arg0 + 0x44))[4], t);
    fn_80059500(
        (*(f32 **)((u8 *)arg0 + 0x38))[5],
        (*(f32 **)((u8 *)arg0 + 0x3C))[5],
        (*(f32 **)((u8 *)arg0 + 0x40))[5],
        (*(f32 **)((u8 *)arg0 + 0x44))[5], t);
    ftmp = fn_80059500(
        (*(f32 **)((u8 *)arg0 + 0x38))[6],
        (*(f32 **)((u8 *)arg0 + 0x3C))[6],
        (*(f32 **)((u8 *)arg0 + 0x40))[6],
        (*(f32 **)((u8 *)arg0 + 0x44))[6], t);
    cam->eye[0] = f27;
    src = (u32 *)lbl_8027F250;
    ftmp = -ftmp;
    cam->eye[1] = f28;
    angle = lbl_8036B7D4 * f30;
    cam->eye[2] = f29;
    ((u32 *)vec)[2] = src[2];
    ((u32 *)vec)[0] = src[0];
    ((u32 *)vec)[1] = src[1];
    vec[2] = ftmp;
    fn_80202300(mtx14, 0x58, angle);
    fn_80202300(mtx44, 0x59, lbl_8036B7D4 * f31);
    fn_802029C4(mtx14, vec, vec);
    fn_802029C4(mtx44, vec, vec);
    fn_80203184(cam->eye, vec, cam->at);
    fn_80067FE8(cam->at, &cam->unkEC, cam->eye);
    (*(u16 *)((u8 *)arg0 + 0x4E))++;
    if (*(u16 *)((u8 *)arg0 + 0x4E) >= *(u16 *)((u8 *)arg0 + 0x4C)) {
        (*(u16 *)((u8 *)arg0 + 0x48))++;
        fn_8000C188(arg0);
    }
}

void fn_801F09E8(void) {
    M2C_UNK fn_801F0BC4();
    fn_801F0BC4();
}

#pragma cplusplus on
extern "C" void fn_801F0A08(void *arg0) {
    void fn_8005376C(void);
    void Heap_Free(void *);
    struct Obj {
        u8 pad[0x10];
        virtual void v0() = 0;
        virtual void v1(s32) = 0;
    };
    void *temp;

    Heap_Free(*(void **)((char *)arg0 + 0x38));
    Heap_Free(*(void **)((char *)arg0 + 0x3C));
    Heap_Free(*(void **)((char *)arg0 + 0x40));
    Heap_Free(*(void **)((char *)arg0 + 0x44));
    temp = *(void **)((char *)arg0 + 0x30);
    if (temp != NULL) {
        ((Obj *)temp)->v1(1);
    }
    fn_8005376C();
}

extern "C" void fn_801F0A74(void *arg0) {
    void *Heap_Alloc(u32);
    void String_Init(void *, void *, void *);
    void String_Destroy(void *, s32);
    void fn_800C992C(void *, void *, s32);
    void fn_800E8154(void *, void *);
    void *fn_800E8504(void *, s32, void *);
    s16 fn_801CAF50(s32);
    u32 strlen(const char *);
    extern char gGActorPathExt[];

    struct Obj { u8 pad[0x10]; virtual void v0() = 0; virtual void v1() = 0; virtual s32 v2(void *, void *) = 0; };
    struct Str {
        String s;
        Str(void *p) {
            u32 alloc;
            String_Init(&s, p, &alloc);
        }
        ~Str() {
            String_Destroy(&s, -1);
        }
    };
    struct Actor {
        u8 pad[0x48];
        void *operator new(u32 sz) { return Heap_Alloc(sz); }
        Actor(s32 a, const Str &s) {
            fn_800E8504(this, a, (void *)&s.s);
        }
    };

    *(Actor **)((u8 *)arg0 + 0x30) = new Actor(0, Str(gGActorPathExt + 0x221));
    String path;
    u32 allocator1;
    String_Init(&path, gGActorPathExt + 0x273, &allocator1);
    fn_800C992C(&path, gGActorPathExt + 0x279, strlen(gGActorPathExt + 0x279));
    fn_800E8154(*(void **)((u8 *)arg0 + 0x30), &path);
    void *object = *(void **)((u8 *)arg0 + 0x30);
    *(s32 *)((u8 *)arg0 + 0x34) = ((Obj *)object)->v2(gGActorPathExt + 0x287, gGActorPathExt + 0x293);
    *(s16 *)((u8 *)arg0 + 0x4A) = fn_801CAF50(*(s32 *)((u8 *)arg0 + 0x34));
    *(void **)((u8 *)arg0 + 0x38) = Heap_Alloc(0x1C);
    *(void **)((u8 *)arg0 + 0x3C) = Heap_Alloc(0x1C);
    *(void **)((u8 *)arg0 + 0x40) = Heap_Alloc(0x1C);
    *(void **)((u8 *)arg0 + 0x44) = Heap_Alloc(0x1C);
    String_Destroy(&path, -1);
}

extern "C" void fn_801F0BC4(CameraAnimProc *p) {
void *CameraAnim_GetKeyframe(void *, s32);
void Process_Goto(void *, s32);
f32 *key;
if(p->index >= p->count) { Process_Goto(p,0); return; }
key = (f32 *)CameraAnim_GetKeyframe(p->anim,p->index);
if(p->index == 0) { p->current->eye.x = key[0];
p->current->eye.y = key[1];
p->current->eye.z = key[2];
p->current->target.x = key[3];
p->current->target.y = key[4];
p->current->target.z = key[5];
p->current->zoom = key[6]; { CameraAnimState *dst; CameraAnimState *src; src=p->current; dst=p->prev; dst->eye=src->eye; dst->target=src->target; dst->zoom=src->zoom; } }
else { { CameraAnimState *dst; CameraAnimState *src; src=p->current; dst=p->prev; dst->eye=src->eye; dst->target=src->target; dst->zoom=src->zoom; } { CameraAnimState *dst; CameraAnimState *src; src=p->next; dst=p->current; dst->eye=src->eye; dst->target=src->target; dst->zoom=src->zoom; } }
p->next->eye.x = key[0];
p->next->eye.y = key[1];
p->next->eye.z = key[2];
p->next->target.x = key[3];
p->next->target.y = key[4];
p->next->target.z = key[5];
p->next->zoom = key[6];
p->duration = *(s32 *)(key+7);
if(p->index + 1 < p->count) {
key = (f32 *)CameraAnim_GetKeyframe(p->anim,p->index+1);
p->future->eye.x = key[0];
p->future->eye.y = key[1];
p->future->eye.z = key[2];
p->future->target.x = key[3];
p->future->target.y = key[4];
p->future->target.z = key[5];
p->future->zoom = key[6];
} else { { CameraAnimState *dst; CameraAnimState *src; src=p->next; dst=p->future; dst->eye=src->eye; dst->target=src->target; dst->zoom=src->zoom; } }
p->elapsed=0;
}

#pragma cplusplus reset
#pragma use_lmw_stmw off
void fn_801F0E4C(void *arg0) {
f32 Math_Lerp(f32,f32,f32,f32);
void Model_SetColor(s32,u8,u8,u8);
void Model_SetAlpha(s32,u8);
void Process_ClearFunc(void *);
s32 a,b,g,r;
u8 *p=arg0;
*(s32 *)(p+0x40)+=1;
if(*(s32 *)(p+0x40)>=*(s32 *)(p+0x38)) Process_ClearFunc(arg0);
r=(s32)Math_Lerp((f32)p[68],(f32)p[72],(f32)*(s32 *)(p+0x38),(f32)*(s32 *)(p+0x40));
g=(s32)Math_Lerp((f32)p[69],(f32)p[73],(f32)*(s32 *)(p+0x38),(f32)*(s32 *)(p+0x40));
b=(s32)Math_Lerp((f32)p[70],(f32)p[74],(f32)*(s32 *)(p+0x38),(f32)*(s32 *)(p+0x40));
a=(s32)Math_Lerp((f32)p[71],(f32)p[75],(f32)*(s32 *)(p+0x38),(f32)*(s32 *)(p+0x40));
Model_SetColor(*(s32 *)(p+0x30),r,g,b);
Model_SetAlpha(*(s32 *)(p+0x30),a);
}

#pragma use_lmw_stmw on
void fn_801F109C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3C) - 1);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x3C) < 0) {
        Process_ClearFunc();
    }
}

void fn_801F10D4(void) {
    extern u16 gGActorPathExt[];
    Msg_Expand((u8 *)gGActorPathExt + 0x422);
}

s32 fn_801F1100(void) {
    return 0;
}

s32 fn_801F1108(void) {
    return 0;
}

#pragma cplusplus on
extern "C" void fn_801F1110(void *arg0, void *arg1) {
    struct Obj {
        u8 pad[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual void v18() = 0;
        virtual void v19() = 0;
        virtual s16 v20() = 0;
    };
    void *GfxEnt_Get(u8);
    void fn_8006F9F4(void *, void *);
    s32 i;
    void *p;
    u8 *a1 = (u8 *)arg1;

    fn_8006F9F4(arg0, arg1);
    for (i = 0; i < (s8)a1[0x60]; i++) {
        p = GfxEnt_Get(a1[0x40 + i]);
        *(s16 *)((u32)p + 0x32) -= ((Obj *)arg0)->v20();
    }
}
extern "C" void fn_801F11A4(void *arg0, void *arg1) {
    void Prim2D_SetAlpha(s32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void *GfxEnt_Get(u8);
    void fn_8000D864(s32, void *);
    void *Msg_Expand(void *);
    void Text_Draw(s32, s32, s32, void *, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    void fn_8015A2D8(s32, s32, s32, s32, s32, s32);
    void strcpy(void *, void *);
    extern f32 lbl_8036B7B8;
    extern f32 lbl_8036B7C8;
    extern f32 lbl_8036B7E8;
    extern f32 lbl_8036B7EC;
    extern f32 lbl_8036B7F0;
    extern f32 lbl_8036B7F4;
    extern f32 lbl_8036B7F8;
    extern f32 lbl_8036B7FC;
    extern f32 lbl_8036B800;
    extern void *lbl_8029A734[];
    extern u8 gGActorPathExt[];
    struct Obj {
        u8 pad[4];
        virtual void *v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual s32 v17() = 0;
        virtual s32 v18() = 0;
        virtual s32 v19() = 0;
        virtual void v20() = 0;
        virtual s32 v21() = 0;
        virtual s32 v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual f32 v25() = 0;
    };
    struct Row {
        u8 pad[0x40];
        u8 id;
    };
    u8 sp8[0x40];
    f32 f30;
    f32 f31;
    f32 tmp;
    s16 r29;
    void *str;
    void *item;
    struct Row *row;
    s32 t;

    Prim2D_Begin();
    f30 = ((Obj *)arg0)->v25();
    f31 = (f32)(s16)((Obj *)arg0)->v22();
    Prim2D_SetTransform((f32)(s16)((Obj *)arg0)->v21(), f31, f30, lbl_8036B7C8);
    Prim2D_PrepareTex();
    r29 = (s16)((Obj *)arg0)->v19();
    fn_8015A2D8(0, 8, ((Obj *)arg0)->v18(), r29, 0xB3, 0x10);
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x10);
    Prim2D_PrepareTex();
    tmp = (f32)(s16)((Obj *)arg0)->v18() - lbl_8036B7E8;
    f31 = tmp * lbl_8036B7EC;
    f30 = (f32)((s16)((Obj *)arg0)->v17() + 0x13);
    Prim2D_AddPrim(1);
    Prim2D_SetRect(f31, f30, lbl_8036B7E8, lbl_8036B7F0);
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B7F4);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(4);
    Prim2D_SetRect(f31, f30, lbl_8036B7F8, lbl_8036B7B8);
    Prim2D_SetAlpha(0x4D);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetRect(f31, lbl_8036B7C8 + (f30 + lbl_8036B7F0), lbl_8036B7F8, lbl_8036B7B8);
    Prim2D_SetAlpha(0x4D);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetRect(f31, f30 - lbl_8036B7C8, lbl_8036B7B8, lbl_8036B7FC);
    Prim2D_SetAlpha(0x4D);
    Prim2D_EndPrim();
    Prim2D_AddPrim(4);
    Prim2D_SetRect(lbl_8036B7C8 + (f31 + lbl_8036B7E8), f30, lbl_8036B7B8, lbl_8036B7F0);
    Prim2D_SetAlpha(0x4D);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_AddZ(lbl_8036B800);
    Prim2D_PrepareTex();
    str = ((Obj *)arg0)->v0();
    tmp = (f32)Text_MeasureWidth(str, -1, lbl_8036B7C8);
    f31 = ((f32)(s16)((Obj *)arg0)->v18() - tmp) * lbl_8036B7EC;
    str = ((Obj *)arg0)->v0();
    Text_Draw((s32)f31, 0x18, 1, str);
    row = (struct Row *)arg1;
    row = (struct Row *)((u8 *)row + *(s8 *)((u8 *)arg1 + 0x62));
    item = GfxEnt_Get(row->id);
    fn_8000D864(0, Msg_Expand(lbl_8029A734[*(u8 *)((u8 *)item + 0x3A)]));
    strcpy(sp8, Msg_Expand(gGActorPathExt + 0x42D));
    arg1 = (void *)(s32)(s16)((Obj *)arg0)->v18();
    f31 = (f32)((s32)(((u32)(t = (s16)(s32)arg1 - Text_MeasureWidth(sp8, -1, lbl_8036B7C8)) >> 31) + t) >> 1);
    Text_Draw((s32)f31, (s32)(f32)((s16)((Obj *)arg0)->v17() + 0x14), 7, sp8);
    if (f30) {
        /* keep y in f31-phys so text/half prefer f30 */
    }
}
#pragma cplusplus reset
#pragma peephole reset

s32 fn_801F1644(void *arg0, s32 unused, s8 arg2) {
    u8 fn_800A8504(s32, s8);
    extern void *lbl_803683D8;

    if (fn_800A8504(M2C_FIELD(lbl_803683D8, s32 *, 0x18C), arg2) == 0) {
        return 3;
    }
    M2C_FIELD(arg0, s8 *, 4) = arg2;
    return 0;
}

void fn_801F16A0(void *arg0) {
    extern void *lbl_8029A710[];
    void Msg_Expand(void *);

    Msg_Expand(lbl_8029A710[*(u8 *)((u8 *)arg0 + 4)]);
}

s32 fn_801F16D4(s32 arg0, s32 arg1, void *arg2) {
    extern u8 gUiContext[];
    gUiContext[0x14] = *(u8 *)((u8 *)arg2 + 0x3A);
    return 5;
}

void fn_801F16EC(void *arg0, void *arg1, void *arg2) {
    s32 Text_MeasureWidth(void *, s32, f32);
    s32 Text_MeasureHeight(s32, f32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32,f32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    extern f32 lbl_8036B7C8;
#pragma cplusplus on
    struct Model {
        u8 pad[4];
        virtual void v0()=0;
        virtual void v1()=0;
        virtual void v2()=0;
        virtual void v3()=0;
        virtual void v4()=0;
        virtual void v5()=0;
        virtual void v6()=0;
        virtual void v7()=0;
        virtual void v8()=0;
        virtual void v9()=0;
        virtual void v10()=0;
        virtual void v11()=0;
        virtual void v12()=0;
        virtual void v13()=0;
        virtual void v14()=0;
        virtual void v15()=0;
        virtual void v16()=0;
        virtual void v17()=0;
        virtual void v18()=0;
        virtual void v19()=0;
        virtual s32 height()=0;
    };
    struct Item {
        virtual void v0()=0;
        virtual void *text()=0;
        virtual void v2()=0;
        virtual void v3()=0;
        virtual void v4()=0;
        virtual void v5()=0;
        virtual void v6()=0;
        virtual void v7()=0;
        virtual void v8()=0;
        virtual void v9()=0;
        virtual void v10()=0;
        virtual void v11()=0;
        virtual void v12()=0;
        virtual void v13()=0;
        virtual void v14()=0;
        virtual void v15()=0;
        virtual void v16()=0;
        virtual void setup(void *)=0;
        virtual void v18(void *)=0;
    };
    f32 x;
    s16 y;
    s16 height;
    s32 width;
    Model *model;
    void *text;
    text = ((Item *)arg0)->text();
    width=Text_MeasureWidth(text,-1,lbl_8036B7C8);
    x=(f32)(M2C_FIELD(arg2,s16 *,0x30)-(width>>1));
    model=M2C_FIELD(arg1,Model **,0x3C);
    height=model->height();
    y=((height-Text_MeasureHeight(-1,lbl_8036B7C8))>>1)+M2C_FIELD(arg2,s16 *,0x32);
    ((Item *)arg0)->setup(arg1);
    Prim2D_AddPrim(6);
    Prim2D_SetPos(x,(f32)y);
    ((Item *)arg0)->v18(arg2);
    text=((Item *)arg0)->text();
    Prim2D_SetText(text);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B7C8);
    Prim2D_PrepareTex();
#pragma cplusplus reset
}

void fn_801F1848(void *arg0, void *arg1) {
    void Prim2D_SetColorPacked(s32 *);
    s32 *Ui_GetColor(s32);
    s32 sp8;

    if (*(u8 *)((u8 *)arg1 + 0x38) != 0) {
        sp8 = *Ui_GetColor(7);
        Prim2D_SetColorPacked(&sp8);
    }
}

void fn_801F1888(void *arg0) {
    struct Tree {
        s32 count;
        void *root;
        void *unk8;
        void **first;
    };
    void BinTree_Destroy(struct Tree *, void *);
    struct Tree *tree = arg0;

    if (tree->root != NULL) {
        BinTree_Destroy(tree, tree->root);
        tree->count = 0;
        tree->root = NULL;
        tree->first = &tree->root;
    }
}

#include "common.h"
extern u16 lbl_8029A5FC;
extern u16 gUiContext;
#include "common.h"

extern f32 lbl_8036B780; 
extern void* lbl_8028FDB0;
extern void* lbl_80292230;
extern void* lbl_80293C84;
extern void* lbl_80293C58;
extern void* lbl_8027EE08;
/* Functions from 0x801EAA2C to 0x801F18D4, found by decomp-toolkit. */
#include "common.h"

s32 gUiInputFlags;

