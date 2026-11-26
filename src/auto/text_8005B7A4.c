/* Functions from 0x8005AE20 to 0x80072408, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
static inline u32 FileCache_AllocFromHeap(u32 size, s32 drive, char *name) {
    u32 fn_800C44F4(s32);
    u32 fn_800C4604(s32, s32, char *, s32);
    u32 strlen(char *);
    s32 off;
    if (fn_800C44F4(drive) < size) return 0;
    off = (s32)strlen(name) - 15;
    if (off < 0) off = 0;
    return fn_800C4604(drive, size, name + off, size);
}

static inline void FileCache_CopyName(u8 *arg0, char *arg1) {
    char *src; u8 c; s32 i; struct { u8 *p; } dst;
    src = arg1;
    if (*arg1 == '/') {
        src++;
    }
    *(s32 *)(arg0 + 0x2C) = 0;
    dst.p = arg0;
    for (i = 0x29; i > 0; i--) {
        c = *src;
        if ((s8)c >= 'A' && (s8)c <= 'Z') {
            *src = (char)(c + 0x20);
        }
        *dst.p = *src;
        c = *src;
        if ((s8)c == 0) {
            break;
        }
        dst.p++;
        src++;
        *(s32 *)(arg0 + 0x2C) = (s8)c + *(s32 *)(arg0 + 0x2C) * 0x25;
    }

}

static inline u8 FileCache_HasExtension(char *name, char *ext) {
    u8 c;
    char *p = name;
    while ((s8)(c = *p) != 0) {
        if ((s8)c == '.') break;
        ++p;
    }
    while ((s8)(c = *p) != 0) {
        if ((s8)c != (s8)*ext) break;
        ++ext;
        ++p;
        if ((s8)*ext == 0 && (s8)*p == 0) return 1;
    }
    return 0;
}
#pragma cplusplus on
struct UiSelectionHandler {
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
virtual void select(void *, void *) = 0;
virtual void deselect(void *, void *) = 0;
};
#pragma cplusplus reset

typedef struct MaterialColor { u8 r, g, b, a; } MaterialColor;
static inline void Terrain_HashAll(u32 *out, void *entries_void) {
    struct TerrainEntry {
        u8 *name;
        u32 unk4;
        u32 unk8;
    };
    struct TerrainEntry *entries = (struct TerrainEntry *)entries_void;
    u8 b;
    u32 *p = out;
    u8 *s;
    u32 acc;
    s32 i;

    for (i = 0; i < 0x4D; i++) {
        s = entries->name;
        acc = 0;
        while ((b = *s, (s8)b != 0)) {
            acc += b;
            s++;
            acc <<= 4;
        }
        *p++ = acc;
        entries++;
    }
}
static inline u8 *GActor_FindAnimation(u8 *p) {
    while (p) {
        u8 *anim = *(u8 **)(p + 0x44);
        if (anim) return anim;
        p = *(u8 **)(p + 4);
    }
    return 0;
}

typedef struct {
    s32 at0[16];
    s32 at40[8];
    s32 at60[8];
    s32 at80[16];
} StagePool;

// Structure definition for the argument passed to fn_80063A14
typedef struct {
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkC;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    s32 unk34;
} SomeStruct;

struct UnkStruct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

extern u16 gBattleState[1400];
extern f32 lbl_803692E0;
extern f32 lbl_80369300;
extern f32 lbl_8036930C;
extern f64 lbl_803692C0;
extern f32 lbl_803692B8;
extern u16 lbl_80285D18[];
extern char lbl_8026B590[];
extern f32 lbl_803691E0;
extern f32 lbl_803691E4;
extern f32 lbl_803691E8;
extern u8 lbl_8026B658[];

static inline u8 *FindEntryByName(char *name) {
    extern u8 gFileCache[];
    s32 Str_Cmp();
    u8 *e;
    char *start;
    u32 hash;
    s32 i;
    u8 c;

    if (*name == '/') {
        name++;
    }
    start = name;
    hash = 0;
    while ((s8)(c = *(u8 *)name) != 0) {
        if ((s8)c >= 'A' && (s8)c <= 'Z') {
            *(u8 *)name += 0x20;
        }
        hash = (s8)*(u8 *)name++ + hash * 37;
    }
    for (i = 0, e = gFileCache; i < 0x400; i++, e += 0x7C) {
        if (hash == *(u32 *)(e + 0x2C) && Str_Cmp(start, e) == 0) {
            return gFileCache + i * 0x7C;
        }
    }
    return NULL;
}

static inline u8 *FindEntryByNameFrom(char *name, char *path) {
    extern u8 gFileCache[];
    s32 Str_Cmp();
    u8 *e;
    char *start;
    u32 hash;
    s32 i;
    u8 c;

    if ((s32)*(u8 *)name == '/') {
        path++;
    }
    start = path;
    hash = 0;
    while ((s8)(c = *(u8 *)path) != 0) {
        if ((s8)c >= 'A' && (s8)c <= 'Z') {
            *(u8 *)path += 0x20;
        }
        hash = (s8)*(u8 *)path++ + hash * 37;
    }
    for (i = 0, e = gFileCache; i < 0x400; i++, e += 0x7C) {
        if (hash == *(u32 *)(e + 0x2C) && Str_Cmp(start, e) == 0) {
            return gFileCache + i * 0x7C;
        }
    }
    return NULL;
}

static inline u32 FindUnk48(void *arg0) {
    while (arg0 != NULL) {
        u32 temp = M2C_FIELD(arg0, u32 *, 0x48);
        if (temp != 0U) {
            return temp;
        }
        arg0 = M2C_FIELD(arg0, void **, 4);
    }
    return 0U;
}

static inline u32 CalcUnk48Size(u32 found) {
    s16 t = M2C_FIELD(M2C_FIELD(found, void **, 0x48), s16 *, 0xA);
    return (((t * 12) + 31) & ~31) / 2 * 2;
}

static inline u32 AddUnk48Size(u32 base, void *node) {
    void *current = node;

    while (current != NULL) {
        u32 temp = M2C_FIELD(current, u32 *, 0x48);
        if (temp != 0U) {
            return base + CalcUnk48Size(temp);
        }
        current = M2C_FIELD(current, void **, 4);
    }
    return base + CalcUnk48Size(0);
}

#pragma use_lmw_stmw on

#pragma use_lmw_stmw off

#pragma global_optimizer off

static inline u32 HashString(u8 *s) {
    u32 hash;
    u8 b;
    hash = 0;
    while ((b = *s, (s8)b != 0)) {
        hash += b;
        s++;
        hash <<= 4;
    }
    return hash;
}

static inline u32 ColFromHash(u32 hash) {
    extern u32 lbl_802F03A8[0x4D];
    u32 *p;
    s32 i;
    s32 ctr;
    p = lbl_802F03A8;
    i = 0;
    for (ctr = 0x4D; ctr != 0; ctr--) {
        if (hash == *p) {
            switch (i) {
            case 9:
            case 0x21:
                return 0x1C;
            default:
                return (u8)i;
            }
        }
        p++;
        i++;
    }
    return 0;
}

#pragma use_lmw_stmw on

#pragma optimization_level reset
#pragma use_lmw_stmw off

#pragma optimization_level 4

#pragma optimization_level reset

u8 fn_8005B7A4(u8 *s) {
extern u32 lbl_802F03A8[0x4D];
u32 hash; u8 b; u32 *p; s32 i; s32 ctr;
hash=0;
while((b=*s,(s8)b!=0)) { hash+=b; s++; hash<<=4;}
p=lbl_802F03A8; i=0;
for(ctr=0x4D;ctr!=0;ctr--) {
if(hash==*p) {
switch(i) { case 9: case 0x21: return 0x1C; default: return (u8)i; }
}
p++; i++;
}
return 0;
}

void fn_8005B820(void) {
    void *Terrain_GetEntry(u8);
    extern u32 lbl_802F03A8[];
    void *entries = Terrain_GetEntry(0);
    Terrain_HashAll(lbl_802F03A8, entries);
}

u8 fn_8005B888(s32 arg0) {
    extern void *lbl_803672F4;
    struct Entry { u8 pad[0x3f]; u8 f; };
    struct Entry *entries = lbl_803672F4;
    if (entries == NULL) return 0;
    return entries[arg0].f;
}

void *fn_8005B8AC(s32 arg0) {
    extern void *lbl_803672F4;
    if (lbl_803672F4 == NULL) {
        return NULL;
    }
    return (u8 *)lbl_803672F4 + (arg0 << 6);
}

s32 fn_8005B8CC(void) {
    extern void *lbl_803672F4;
    if ((void *) lbl_803672F4 == NULL) {
        return 0;
    }
    return M2C_FIELD(lbl_803672F4, s32 *, 0x4000);
}

extern void *lbl_803672F4;
s32 fn_8005B8E8(void) {
    void Heap_Free(void *);
    Heap_Free(lbl_803672F4);
    lbl_803672F4 = 0;
    return 1;
}

s32 fn_8005B918(s32 arg0) {
    void *fn_800C45B8(s32, void *, s32);
    s32 fn_8020CD64(s32, void *);
    s32 fn_8020CE24(void *, void *);
    void fn_8020CEC8(void *);
    void Str_CopyPad(void *, s32, s32);
    extern void *lbl_803672F4;
    extern u8 lbl_8026B330[];
    u8 iter[0xC];
    s32 out[3];
    void *p;
    s32 flag, name;
    if (lbl_803672F4 != NULL) return 0;
    if (fn_8020CD64(arg0, iter) == 0) return 0;
    p = fn_800C45B8(-0x4004, lbl_8026B330 + 5, 0);
    if (p != NULL) { *(u32 *)((u8 *)p + 0x4000) = 0; }
    lbl_803672F4 = p;
    while (fn_8020CE24(iter, out) != 0) {
        p = lbl_803672F4;
        name = out[2];
        flag = out[1] != 0;
        ((u8 *)p)[(*(u32 *)((u8 *)p + 0x4000) << 6) + 0x3f] = flag;
        Str_CopyPad((u8 *)p + (*(u32 *)((u8 *)p + 0x4000) << 6), name, 0x3e);
        *(u32 *)((u8 *)p + 0x4000) += 1;
    }
    fn_8020CEC8(iter);
    return 1;
}

u8 fn_8005BA00(void) {
    extern u8 lbl_803672E8;
    return lbl_803672E8;
}

void fn_8005BA08(s8 arg0) {
    extern s8 lbl_803672E8;
    lbl_803672E8 = arg0;
}

/* Return whether the named file is ready: load-done (0x2000) or absent (0x8000). */
s32 FileCache_IsReady(char *name) {
    u8 *entry = FindEntryByName(name);
    u16 flags;

    if (entry == NULL) {
        flags = 0x8000;
    } else {
        flags = *(u16 *)(entry + 0x30);
    }
    if (flags & 0x2000) {
        return 1;
    }
    return (flags >> 15) & 1;
}

#pragma push
#pragma opt_lifetimes off
typedef struct FileCacheEntry_8005BB2C {
    s8 name;
    u8 pad[0x2F];
    volatile u16 flags;
    u16 ref;
    u32 stamp;
    u8 rest[0x7C - 0x38];
} FileCacheEntry_8005BB2C;

static inline s32 FileCache_CheckAll_8005BB2C(u32 time, FileCacheEntry_8005BB2C *e) {
    s32 i;
    for (i = 0; i < 1024; i++, e++) {
        if (e->name != 0 && !(e->flags & 0x2000) && (e->flags & 0x200) && time <= e->stamp + 0xA) {
            return 0;
        }
    }
    return 1;
}

s32 fn_8005BB2C(void) {
    u8 fn_800B2FF4(s32);
    s64 OSGetTime(void);
    extern u8 gFileCache[];
    u32 time;

    if ((u8)fn_800B2FF4(0) == 0) {
        return 0;
    }
    time = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
    return FileCache_CheckAll_8005BB2C(time, (FileCacheEntry_8005BB2C *)gFileCache);
}
#pragma pop
void fn_8005C8D8();
void fn_8005BC8C() {
    void fn_8005C8D8();
    fn_8005C8D8();
}

void fn_8005BCAC(void) {
    fn_8005C8D8(-1);
}

void fn_8005BCD0(void) {
    M2C_UNK fn_8005CBC8();
    fn_8005CBC8();
}

void fn_8005BCF0(void) {
    extern u8 lbl_803672E9;
    extern s8 lbl_803672EA;
    extern s8 lbl_803672EB;
    extern u8 lbl_803672EC[8];
    extern u8 lbl_802F04E0[126976];
    extern u8 lbl_8030FAF8[8192];
    extern u8 lbl_8030F7E0[792];
    void OSInitThreadQueue(u8 *queue);
    s32 fn_8020A558(u8 *a, void *b, s32 c, u8 *d, s32 e, s32 f, s32 g);
    s32 fn_8020A9E0(u8 *a);
    extern void fn_8005BE48(void);
    s32 var_ctr;
    u8 *var_r5;

    var_r5 = lbl_802F04E0;
    for (var_ctr = 0; var_ctr < 0x80; var_ctr++, var_r5 += 0x3E0) {
        *(s8 *)(var_r5 + 0x0) = 0;
        *(s32 *)(var_r5 + 0x2C) = 0;
        *(s16 *)(var_r5 + 0x30) = 0;
        *(s16 *)(var_r5 + 0x32) = 0;
        *(s32 *)(var_r5 + 0x38) = 0;
        *(s32 *)(var_r5 + 0x3C) = 0;
        *(s8 *)(var_r5 + 0x7C) = 0;
        *(s32 *)(var_r5 + 0xA8) = 0;
        *(s16 *)(var_r5 + 0xAC) = 0;
        *(s16 *)(var_r5 + 0xAE) = 0;
        *(s32 *)(var_r5 + 0xB4) = 0;
        *(s32 *)(var_r5 + 0xB8) = 0;
        *(s8 *)(var_r5 + 0xF8) = 0;
        *(s32 *)(var_r5 + 0x124) = 0;
        *(s16 *)(var_r5 + 0x128) = 0;
        *(s16 *)(var_r5 + 0x12A) = 0;
        *(s32 *)(var_r5 + 0x130) = 0;
        *(s32 *)(var_r5 + 0x134) = 0;
        *(s8 *)(var_r5 + 0x174) = 0;
        *(s32 *)(var_r5 + 0x1A0) = 0;
        *(s16 *)(var_r5 + 0x1A4) = 0;
        *(s16 *)(var_r5 + 0x1A6) = 0;
        *(s32 *)(var_r5 + 0x1AC) = 0;
        *(s32 *)(var_r5 + 0x1B0) = 0;
        *(s8 *)(var_r5 + 0x1F0) = 0;
        *(s32 *)(var_r5 + 0x21C) = 0;
        *(s16 *)(var_r5 + 0x220) = 0;
        *(s16 *)(var_r5 + 0x222) = 0;
        *(s32 *)(var_r5 + 0x228) = 0;
        *(s32 *)(var_r5 + 0x22C) = 0;
        *(s8 *)(var_r5 + 0x26C) = 0;
        *(s32 *)(var_r5 + 0x298) = 0;
        *(s16 *)(var_r5 + 0x29C) = 0;
        *(s16 *)(var_r5 + 0x29E) = 0;
        *(s32 *)(var_r5 + 0x2A4) = 0;
        *(s32 *)(var_r5 + 0x2A8) = 0;
        *(s8 *)(var_r5 + 0x2E8) = 0;
        *(s32 *)(var_r5 + 0x314) = 0;
        *(s16 *)(var_r5 + 0x318) = 0;
        *(s16 *)(var_r5 + 0x31A) = 0;
        *(s32 *)(var_r5 + 0x320) = 0;
        *(s32 *)(var_r5 + 0x324) = 0;
        *(s8 *)(var_r5 + 0x364) = 0;
        *(s32 *)(var_r5 + 0x390) = 0;
        *(s16 *)(var_r5 + 0x394) = 0;
        *(s16 *)(var_r5 + 0x396) = 0;
        *(s32 *)(var_r5 + 0x39C) = 0;
        *(s32 *)(var_r5 + 0x3A0) = 0;
    }
    if ((u8) lbl_803672E9 == 0) {
        lbl_803672EB = 0;
        lbl_803672EA = 0;
        OSInitThreadQueue(lbl_803672EC);
        fn_8020A558(lbl_8030F7E0, &fn_8005BE48, 0, lbl_8030FAF8 + 0x2000, 0x2000, 0x10, 1);
        fn_8020A9E0(lbl_8030F7E0);
        lbl_803672E9 = 1;
    }
}

/* Forever drain the FileCache async work ring, sleeping when empty. */
void FileCache_WorkerThread(void) {
    void DCFlushRange(s32, s32);
    void FileCache_OnCancel(void *, s32);
    void FileCache_OnLoadDone(void *, s32);
    void FileCache_SpawnArchiveEntries(void *);
    void fn_800C4588(s32);
    void OSSleepThread(u8 *);
    extern u8 gFileCacheWorkQueue[];
    extern volatile u8 gFileCacheWorkRead;
    extern volatile u8 gFileCacheWorkWrite;
    extern u8 gFileCacheWorkThreadQueue[8];
    void *entry;
    s32 val;
    u8 type;

    goto check;
loop:
    entry = gFileCacheWorkQueue + gFileCacheWorkRead * 0xC;
    type = *(u8 *)entry;
    switch (type) {
    case 0:
        FileCache_OnLoadDone(*(void **)((u8 *)entry + 4), *(s32 *)((u8 *)entry + 8));
        break;
    case 1:
        FileCache_OnCancel(*(void **)((u8 *)entry + 4), *(s32 *)((u8 *)entry + 8));
        break;
    case 2:
        val = *(s32 *)((u8 *)entry + 8);
        entry = *(void **)((u8 *)entry + 4);
        if (*(volatile u16 *)((u8 *)entry + 0x30) & 0x400) {
            if (*(volatile u16 *)((u8 *)entry + 0x30) & 0x2000) {
                fn_800C4588(val);
            }
        } else {
            if (*(volatile u16 *)((u8 *)entry + 0x30) & 0x800) {
                FileCache_SpawnArchiveEntries(entry);
            }
            *(volatile u16 *)((u8 *)entry + 0x30) |= 0x2000;
        }
        *(volatile u16 *)((u8 *)entry + 0x30) &= ~0x80;
        break;
    case 3:
        val = *(s32 *)((u8 *)entry + 8);
        entry = *(void **)((u8 *)entry + 4);
        DCFlushRange(*(s32 *)((u8 *)entry + 0x38), *(s32 *)((u8 *)entry + 0x3C));
        if (!(*(u16 *)((u8 *)entry + 0x30) & 0x80)) {
            fn_800C4588(val);
        }
        if (*(u16 *)((u8 *)entry + 0x30) & 0x800) {
            FileCache_SpawnArchiveEntries(entry);
        }
        *(u16 *)((u8 *)entry + 0x30) |= 0x2000;
        break;
    }
    gFileCacheWorkRead = (gFileCacheWorkRead + 1) & 0x3F;
check:
    if (gFileCacheWorkRead != gFileCacheWorkWrite) {
        goto loop;
    }
    OSSleepThread(gFileCacheWorkThreadQueue);
    goto check;
}

void FileCache_OnCancel(void *arg0, s32 arg1) {
    void FileCache_SpawnArchiveEntries(void *);
    void FileCache_ExpandBuffer(void *);

    if (*(volatile u16 *)((u8 *)arg0 + 0x30) & 0x400) {
        FileCache_ExpandBuffer(arg0);
    } else {
        if (*(volatile u16 *)((u8 *)arg0 + 0x30) & 0x800) {
            FileCache_SpawnArchiveEntries(arg0);
        }
        *(volatile u16 *)((u8 *)arg0 + 0x30) |= 0x2004;
    }
}

/* After DVD load: optionally start ARAM DMA (flag 8), else expand buffer / spawn archive children and mark load-done. */
void FileCache_OnLoadDone(void *entry) {
    void FileCache_SpawnArchiveEntries(void *);
    void FileCache_ExpandBuffer(void *);
    u32 AramCache_Find(void);
    u8 AramCache_Request(void *, s32, s32, void *, void *);
    extern u8 FileCache_QueueAramDone[];
    volatile u16 *flags = (u16 *)((u8 *)entry + 0x30);

    if ((*flags & 8) && AramCache_Find() == 0 &&
        AramCache_Request(entry, *(s32 *)((u8 *)entry + 0x38), *(s32 *)((u8 *)entry + 0x3c),
                          FileCache_QueueAramDone, entry)) {
        *flags |= 0x80;
        *(s32 *)((u8 *)entry + 0x6c) = *(s32 *)((u8 *)entry + 0x38);
        if (*flags & 0x400) {
            FileCache_ExpandBuffer(entry);
        }
    } else {
        if (*flags & 0x400) {
            FileCache_ExpandBuffer(entry);
            return;
        }
        if (*flags & 0x800) {
            FileCache_SpawnArchiveEntries(entry);
        }
        *flags |= 0x2000;
    }
}

s32 fn_8005C0AC(void *arg0, u8 *arg1) {
    void *fn_80234200(void *, s32);
    void strcpy(void *, void *);
    void fn_80238ADC(void *);
    s32 Str_Cmp(void *, void *);
    char sp18[0x10];
    char sp8[0x10];
    void *temp_r3;
    u8 *var_r31;

    var_r31 = arg1;
    if ((s32)*arg1 == 0x2E) {
        var_r31 += 1;
    }
    temp_r3 = fn_80234200(arg0, 0x2E);
    if (temp_r3 == 0) {
        return (s8)*var_r31 == 0;
    }
    strcpy(sp18, (u8 *)temp_r3 + 1);
    fn_80238ADC(sp18);
    strcpy(sp8, var_r31);
    fn_80238ADC(sp8);
    return Str_Cmp(sp18, sp8) == 0;
}

#pragma use_lmw_stmw on
u16 FileCache_Probe(char *name) {
    s32 fn_8020C3E0(char *);
    u8 *entry = FindEntryByName(name);
    u16 flags;
    s32 r;

    if (entry == NULL) {
        flags = 0x8000;
    } else {
        flags = *(u16 *)(entry + 0x30);
    }
    if (!(flags & 0x8000)) {
        return flags;
    }
    r = fn_8020C3E0(name);
    if (r == -1) {
        flags = 0x8000;
    } else {
        flags = 0;
    }
    return flags;
}
#pragma use_lmw_stmw reset
/* Return the byte size of the named file-cache entry, or 0 if absent. */
s32 FileCache_GetSize(char *name) {
    u8 *entry = FindEntryByName(name);
    if (entry != NULL) {
        return *(s32 *)(entry + 0x3C);
    }
    return 0;
}

s32 fn_8005C368(u32 arg0)
{
    extern u8 gFileCache[];
    struct { u8 *e; unsigned long j; } s;
    u8 *found;
    s32 ctr;

    s.j = 0;
    s.e = gFileCache;
    for (ctr = 0x400; ctr > 0; ctr--) {
        if (*(u32 *)(s.e + 0x38) == arg0) {
            found = gFileCache + s.j * 0x7C;
            goto done;
        }
        s.e += 0x7C;
        s.j += 1;
    }
    found = 0;
done:
    if (found == 0) return -1;
    return *(u16 *)(found + 0x32);
}

/* Return 1 if a file-cache entry with this name exists, else 0. */
s32 FileCache_Exists(char *name) {
    if (FindEntryByName(name) == NULL) {
        return 0;
    }
    return 1;
}

#pragma no_register_save_helpers on
#pragma use_lmw_stmw on
void FileCache_OrFlags(char *name, s32 flags) {
    /* OR flags into the named file-cache entry's flag word at +0x30. */
    u8 *entry = FindEntryByName(name);
    s32 v = *(u16 *)(entry + 0x30);
    v |= flags;
    *(u16 *)(entry + 0x30) = v;
}
/* Mark the named file-cache entry as relocated (flags |= 0x4000). */
void FileCache_MarkRelocated(char *name) {
    u8 *e = FindEntryByName(name);
    u16 v = *(u16 *)(e + 0x30);
    v |= 0x4000;
    *(u16 *)(e + 0x30) = v;
}

u16 FileCache_GetFlags(char *name) {
    /* Return the named file-cache entry's flags, or 0x8000 if not cached. */
    u8 *entry = FindEntryByName(name);
    if (entry == NULL) {
        return 0x8000;
    }
    return *(u16 *)(entry + 0x30);
}

void fn_8005C7A4(s32 arg0) {
    arg0 = (s8)arg0;
    fn_8005CF6C(arg0);
}

void fn_8005C7C8(void) {
    M2C_UNK FileCache_ReleaseByName();
    FileCache_ReleaseByName();
}

void fn_8005C7E8(void) {
    M2C_UNK FileCache_ReleaseByKey();
    FileCache_ReleaseByKey();
}

void fn_8005C808(void *arg0) {
    M2C_UNK fn_8005D474(void *, M2C_UNK);
    fn_8005D474(arg0, 2);
}

M2C_UNK fn_8005C82C() {
    M2C_UNK fn_8005D474();
    return fn_8005D474();
}

void FileCache_Load(s32 arg0) {
    void fn_8005D474(s32, s32);
    fn_8005D474(arg0, 0);
}

void fn_8005C870(void) {
    M2C_UNK fn_8005D330();
    fn_8005D330();
}

void fn_8005C890(s32 arg0) {
    extern void fn_8005D330(s32, s32);
    fn_8005D330(arg0, 0xC);
}

void fn_8005C8B4(s32 arg0) {
    void fn_8005D330(s32, s32);
    fn_8005D330(arg0, 0);
}

#pragma push
#pragma optimization_level 3
#pragma global_optimizer off
#pragma opt_common_subs off
#pragma opt_lifetimes on
void fn_8005C8D8(arg0)
s8 arg0;
{
    void DebugPrint(char *, ...);
    s64 OSGetTime(void);
    void OS_YieldThread(void);
    void fn_8003FED8(void *);
    void fn_800C4588(void *);
    extern u8 gFileCache[];
    extern u8 lbl_8026B330[];
    u8 *list;
    u8 *entry;
    s32 index;
    u32 time;

    DebugPrint((char *)(lbl_8026B330 + 6), arg0);
    time = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));

    index = 0;
    entry = gFileCache;
    do {
        if (*(s8 *)entry != 0 && *(u16 *)(entry + 0x32) == 0 &&
            (arg0 < 0 || *(s8 *)(entry + 0x29) == arg0) &&
            *(u32 *)(entry + 0x38) != 0 &&
            (*(volatile u16 *)(entry + 0x30) & 0x2000) &&
            !(*(volatile u16 *)(entry + 0x30) & 0x1000)) {
            if ((*(volatile u16 *)(entry + 0x30) & 0x200) && time < *(u32 *)(entry + 0x34) + 0xA) {
                DebugPrint((char *)(lbl_8026B330 + 0x1C), entry);
            } else {
                DebugPrint((char *)(lbl_8026B330 + 0x4E), entry, *(u32 *)(entry + 0x3C));
                if (!(*(volatile u16 *)(entry + 0x30) & 0x1000)) goto check80;
                goto next;
                yield80: OS_YieldThread();
                check80: if (*(volatile u16 *)(entry + 0x30) & 0x80) goto yield80;
                if (*(volatile u16 *)(entry + 0x30) & 0x800) {
                    if (*(volatile u16 *)(entry + 0x30) & 0x2000) {
                        s32 i;
                        u8 *item;
                        list = *(u8 **)(entry + 0x38);
                        i = 0;
                        item = list + 8;
                        for (; i < *(u16 *)(list + 4); item += 0x10, i++) {
                            u8 *found;
                            u32 j;
                            u32 key;
                            u8 *e;
                            unsigned ctr;
                            e = gFileCache;
                            key = *(u32 *)(item + 8);
                            j = 0;
                            for (ctr = 0x400; ctr > 0; ctr--) {
                                if (*(u32 *)(e + 0x38) == key) {
                                    found = gFileCache + j * 0x7C;
                                    goto found1;
                                }
                                e += 0x7C;
                                j++;
                            }
                            found = 0;
                        found1:
                            if (found && (*(u16 *)(found + 0x30) & 1)) {
                                fn_8003FED8(*(void **)(found + 0x38));
                                *(u16 *)(found + 0x30) &= 0xFFFE;
                            }
                        }
                    }
                } else if (*(volatile u16 *)(entry + 0x30) & 1) {
                        fn_8003FED8(*(void **)(entry + 0x38));
                        *(volatile u16 *)(entry + 0x30) &= 0xFFFE;
                }
                if ((*(volatile u16 *)(entry + 0x30) & 0x800) && (*(volatile u16 *)(entry + 0x30) & 0x2000)) {
                    s32 i;
                    u8 *item;
                    list = *(u8 **)(entry + 0x38);
                    i = 0;
                    item = list + 8;
                    for (; i < *(u16 *)(list + 4); item += 0x10, i++) {
                        u8 *found;
                        u32 j;
                        u32 key;
                        u8 *e;
                        unsigned ctr;
                        e = gFileCache;
                        key = *(u32 *)(item + 8);
                        j = 0;
                        for (ctr = 0x400; ctr > 0; ctr--) {
                            if (*(u32 *)(e + 0x38) == key) {
                                found = gFileCache + j * 0x7C;
                                goto found2;
                            }
                            e += 0x7C;
                            j++;
                        }
                        found = 0;
                    found2:
                        if (found) {
                            *(found) = 0;
                            *(u32 *)(found + 0x2C) = 0;
                            *(u16 *)(found + 0x30) = 0;
                            *(u16 *)(found + 0x32) = 0;
                            *(u32 *)(found + 0x38) = 0;
                            *(u32 *)(found + 0x3C) = 0;
                        }
                    }
                }
                fn_800C4588(*(void **)(entry + 0x38));
                *(u8 *)entry = 0;
                *(u32 *)(entry + 0x2C) = 0;
                *(volatile u16 *)(entry + 0x30) = 0;
                *(u16 *)(entry + 0x32) = 0;
                *(u32 *)(entry + 0x38) = 0;
                *(u32 *)(entry + 0x3C) = 0;
            }
        }
    next:
        index++;
        entry += 0x7C;
    } while (index < 0x400);
}
#pragma push
#pragma optimization_level 3
#pragma global_optimizer off
#pragma opt_common_subs off
#pragma push
#pragma optimization_level 3
#pragma global_optimizer off
#pragma opt_common_subs off
#pragma peephole on
#pragma opt_propagation on
void fn_8005CBC8(void)
{
    extern char lbl_8026B330[];
    extern unsigned char gFileCache[];
    extern float lbl_803691A8;
    extern float lbl_803691AC;
    extern float lbl_803691B0;
    extern void DebugPrint(const char *, ...);
    extern long long OSGetTime(void);

    unsigned char *entry;
    unsigned short flags;
    int count;
    int total;
    int i;
    char buffer[16];
    char *p;
    float size1;
    float size2;

    DebugPrint(lbl_8026B330 + 0x69);

    entry = gFileCache;
    count = 0;
    total = 0;
    i = 0;

    do {
        if ((signed char)*entry != 0) {
            unsigned int ticks;

            ticks = (unsigned int)(
                OSGetTime() /
                (long long)(*(volatile unsigned int *)0x800000F8 >> 2)
            );

            DebugPrint(
                lbl_8026B330 + 0x8C,
                *(unsigned short *)(entry + 0x32),
                ticks - *(unsigned int *)(entry + 0x34),
                *(unsigned int *)(entry + 0x38),
                *(unsigned int *)(entry + 0x3C)
            );

            if (*(volatile unsigned short *)(entry + 0x30) & 0x5E07) {
                flags = *(volatile unsigned short *)(entry + 0x30);

                p = buffer;
                *p++ = '[';

                if (flags & 0x0001) *p++ = 'I';
                if (flags & 0x0002) *p++ = 'Z';
                if (flags & 0x0004) *p++ = 'V';
                if (flags & 0x0400) *p++ = 'c';
                if (flags & 0x0800) *p++ = 'P';
                if (flags & 0x1000) *p++ = 'C';
                if (flags & 0x4000) *p++ = 'U';
                if (flags & 0x0200) *p++ = 'R';

                *p++ = ']';
                *p = 0;

                DebugPrint(buffer);
            }

            DebugPrint(lbl_8026B330 + 0x9C, entry);

            count++;
            total += *(unsigned int *)(entry + 0x3C);
        }

        i++;
        entry += 0x7C;
    } while (i < 0x400);

    DebugPrint(lbl_8026B330 + 0xA0);
    DebugPrint(lbl_8026B330 + 0xCF);
    DebugPrint(lbl_8026B330 + 0xF9);
    DebugPrint(lbl_8026B330 + 0x121);
    DebugPrint(lbl_8026B330 + 0x145);
    DebugPrint(lbl_8026B330 + 0x165);
    DebugPrint(lbl_8026B330 + 0x185);
    DebugPrint(lbl_8026B330 + 0x1A9);
    DebugPrint(lbl_8026B330 + 0x1CD);
    DebugPrint(lbl_8026B330 + 0x1CF, count);

    DebugPrint(lbl_8026B330 + 0x1F1, (float)total / lbl_803691A8, lbl_803691AC * ((float)total / lbl_803691B0));
    DebugPrint(lbl_8026B330 + 0x21D);
}
#pragma pop
void *fn_8005CEC0(void) {
    void fn_8005C8D8(s32);
    extern u8 gFileCache[];
    u8 *e;
    u8 *base;
    s32 i;
    s32 j;
    unsigned ctr;

    i = 0;
    base = gFileCache;
    e = gFileCache;
    for (ctr = 0x400; ctr > 0; ctr--) {
        if ((s8)*e == 0) {
            return gFileCache + i * 0x7C;
        }
        e += 0x7C;
        i += 1;
    }
    fn_8005C8D8(-1);
    j = 0;
    for (ctr = 0x400; ctr > 0; ctr--) {
        if ((s8)*base == 0) {
            return gFileCache + j * 0x7C;
        }
        base += 0x7C;
        j += 1;
    }
    return NULL;
}
int fn_8005CF6C(int arg0) {
 void fn_8020F334(void *); void fn_800C4588(void *); void fn_8003FED8(void *); void OS_YieldThread(void); extern u8 gFileCache[];
 u8 *entry; s32 index;
 index=0;entry=gFileCache;
 do {
 if(*(s8 *)entry && *(s8 *)(entry+0x29)==(s8)arg0) {
 if((*(volatile u16 *)(entry+0x30)&0x200) && !(*(volatile u16 *)(entry+0x30)&0x2000)) {
 fn_8020F334(entry+0x40); fn_800C4588(*(void **)(entry+0x38)); *(entry)=0; *(u32 *)(entry+0x2c)=0; *(u16 *)(entry+0x30)=0; *(u16 *)(entry+0x32)=0; *(u32 *)(entry+0x38)=0; *(u32 *)(entry+0x3c)=0;
 } else {
 if(!(*(volatile u16 *)(entry+0x30)&0x1000)) {

 while (*(volatile u16 *)(entry+0x30)&0x80) OS_YieldThread();
 if(*(volatile u16 *)(entry+0x30)&0x800) { if(*(volatile u16 *)(entry+0x30)&0x2000)
 { s32 i; u8 *item; u8 *list; list=*(u8 **)(entry+0x38); i=0; item=list+8; for(;i<*(u16 *)(list+4);item+=0x10,i++) { u8 *found; unsigned long j; u32 key; u8 *e; unsigned ctr; e=gFileCache; key=*(u32 *)(item+8); j=0; for(ctr=0x400;ctr>0;ctr--) {if(*(u32 *)(e+0x38)==key){found=gFileCache+j*0x7c;goto found1;}e+=0x7c;j++;}found=0;found1: if(found) {if(*(u16 *)(found+0x30)&1){fn_8003FED8(*(void **)(found+0x38)); *(u16 *)(found+0x30)&=0xfffe;}} } }
 } else if(*(volatile u16 *)(entry+0x30)&1) {fn_8003FED8(*(void **)(entry+0x38));*(u16 *)(entry+0x30)&=0xfffe;}
 if((*(volatile u16 *)(entry+0x30)&0x800) && (*(volatile u16 *)(entry+0x30)&0x2000))
 { s32 i; u8 *item; u8 *list; list=*(u8 **)(entry+0x38); i=0; item=list+8; for(;i<*(u16 *)(list+4);item+=0x10,i++) { u8 *found; unsigned long j; u32 key; u8 *e; unsigned ctr; e=gFileCache; key=*(u32 *)(item+8); j=0; for(ctr=0x400;ctr>0;ctr--) {if(*(u32 *)(e+0x38)==key){found=gFileCache+j*0x7c;goto found2;}e+=0x7c;j++;}found=0;found2: if(found) {*(found)=0; *(u32 *)(found+0x2c)=0; *(u16 *)(found+0x30)=0; *(u16 *)(found+0x32)=0; *(u32 *)(found+0x38)=0; *(u32 *)(found+0x3c)=0;} } }
 *(entry)=0; *(u32 *)(entry+0x2c)=0; *(u16 *)(entry+0x30)=0; *(u16 *)(entry+0x32)=0; *(u32 *)(entry+0x38)=0; *(u32 *)(entry+0x3c)=0;
 }
 }
 }
 next: index++;entry+=0x7c;
 }while(index<0x400);
return;
}

#pragma global_optimizer on
void FileCache_Release(u8 *);
/* Look up a file-cache entry by path/name and release it. */
void FileCache_ReleaseByName(char *name) {
    FileCache_Release(FindEntryByName(name));
}

void FileCache_ReleaseByKey(u32 arg0) {
    void FileCache_Release(void *);
    extern u8 gFileCache[];
    struct { u8 *e; unsigned long j; } s;
    u8 *found;
    s32 ctr;

    s.j = 0;
    s.e = gFileCache;
    for (ctr = 0x400; ctr > 0; ctr--) {
        if (*(u32 *)(s.e + 0x38) == arg0) {
            found = gFileCache + s.j * 0x7C;
            goto done;
        }
        s.e += 0x7C;
        s.j += 1;
    }
    found = 0;
done:
    FileCache_Release(found);
}

#pragma global_optimizer off

#pragma use_lmw_stmw on
void fn_8005D330(char *name, u16 flags) {
    s64 OSGetTime(void);
    void *fn_8005CEC0(void);
    void fn_8005E12C(u8 *, char *, u16);
    void *AramCache_Find(char *);
    void fn_801ED7D0(void *);
    u8 *entry = FindEntryByNameFrom(name, name);
    u16 cur;
    u32 f;
    void *aram;

    if (entry) {
        *(u32 *)(entry + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
        return;
    }
    aram = AramCache_Find(name);
    if (aram) {
        fn_801ED7D0(aram);
        return;
    }
    entry = fn_8005CEC0();
    f = (u16)flags | 0x200U;
    cur = *(u16 *)(entry + 0x30);
    *(u16 *)(entry + 0x30) = cur | f;
    fn_8005E12C(entry, name, f);
}

void *fn_8005D474(char *name, u16 flags) {
    s64 OSGetTime(void);
    void OS_YieldThread(void);
    void *fn_8005CEC0(void);
    void fn_8005DB40(void *, char *, void *, u16);
    void fn_8005E12C(void *, char *, u16);
    void *AramCache_Find(char *);
    u8 *entry;
    void *aram;

    entry = FindEntryByNameFrom(name, name);
    if (entry) {
        *(u16 *)(entry + 0x30) |= flags;
        while (!(*(u16 *)(entry + 0x30) & 0x2000)) {
            OS_YieldThread();
        }
        *(u32 *)(entry + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
        (*(u16 *)(entry + 0x32))++;
        *(u16 *)(entry + 0x30) &= ~0x200;
        return *(void **)(entry + 0x38);
    }
    aram = AramCache_Find(name);
    if (aram) {
        entry = fn_8005CEC0();
        fn_8005DB40(entry, name, aram, flags);
        while (!(*(u16 *)(entry + 0x30) & 0x2000)) {
            OS_YieldThread();
        }
        *(u32 *)(entry + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
        (*(u16 *)(entry + 0x32))++;
        *(u16 *)(entry + 0x30) &= ~0x200;
        return *(void **)(entry + 0x38);
    }
    entry = fn_8005CEC0();
    fn_8005E12C(entry, name, flags);
    while (!(*(u16 *)(entry + 0x30) & 0x2000)) {
        OS_YieldThread();
    }
    *(u32 *)(entry + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
    (*(u16 *)(entry + 0x32))++;
    *(u16 *)(entry + 0x30) &= ~0x200;
    return *(void **)(entry + 0x38);
}

#pragma use_lmw_stmw reset

#pragma global_optimizer reset
/* Drop one ref on a file-cache entry; when the count hits zero, cancel loads, wait, and free it. */
void FileCache_Release(u8 *entry) {
    s64 OSGetTime(void);
    void fn_8003FED8(void *);
    void fn_800C4588(void *);
    void OS_YieldThread(void);
    extern u8 gFileCache[];

    *(u16 *)(entry + 0x32) = *(u16 *)(entry + 0x32) - 1;
    *(u32 *)(entry + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
    if (*(u16 *)(entry + 0x32) != 0) {
        return;
    }

    if (*(volatile u16 *)(entry + 0x30) & 0x800) {
        if (*(volatile u16 *)(entry + 0x30) & 0x2000) {
            s32 i;
            u8 *item;
            u8 *list;
            list = *(u8 **)(entry + 0x38);
            i = 0;
            item = list + 8;
            goto check1;
        body1:
            {
                u8 *found;
                unsigned long j;
                u32 key;
                u8 *e;
                unsigned ctr;
                e = gFileCache;
                key = *(u32 *)(item + 8);
                j = 0;
                for (ctr = 0x400; ctr > 0; ctr--) {
                    if (*(u32 *)(e + 0x38) == key) {
                        found = gFileCache + j * 0x7C;
                        goto found1;
                    }
                    e += 0x7C;
                    j += 1;
                }
                found = 0;
            found1:
                if (found) {
                    if (*(u16 *)(found + 0x30) & 1) {
                        fn_8003FED8(*(void **)(found + 0x38));
                        *(u16 *)(found + 0x30) &= 0xFFFE;
                    }
                }
            }
            item += 0x10;
            i += 1;
        check1:
            if (i < *(u16 *)(list + 4)) {
                goto body1;
            }
        }
    } else if (*(volatile u16 *)(entry + 0x30) & 1) {
        fn_8003FED8(*(void **)(entry + 0x38));
        *(u16 *)(entry + 0x30) &= 0xFFFE;
    }

    if (*(volatile u16 *)(entry + 0x30) & 4) {
        goto spin1_check;
    spin1_body:
        OS_YieldThread();
    spin1_check:
        if (*(volatile u16 *)(entry + 0x30) & 0x80) {
            goto spin1_body;
        }
        if (!(*(volatile u16 *)(entry + 0x30) & 0x1000)) goto spin2_check;
        else return;

        goto spin2_check;
    spin2_body:
        OS_YieldThread();
    spin2_check:
        if (*(volatile u16 *)(entry + 0x30) & 0x80) {
            goto spin2_body;
        }

        if (*(volatile u16 *)(entry + 0x30) & 0x800) {
            if (*(volatile u16 *)(entry + 0x30) & 0x2000) {
                s32 i;
            u8 *item;
            u8 *list;
            list = *(u8 **)(entry + 0x38);
                i = 0;
                item = list + 8;
                goto check2;
            body2:
                {
                    u8 *found;
                unsigned long j;
                u32 key;
                u8 *e;
                unsigned ctr;
                    key = *(u32 *)(item + 8);
                    e = gFileCache;
                    j = 0;
                    for (ctr = 0x400; ctr > 0; ctr--) {
                        if (*(u32 *)(e + 0x38) == key) {
                            found = gFileCache + j * 0x7C;
                            goto found2;
                        }
                        e += 0x7C;
                        ++j;
                    }
                    found = 0;
                found2:
                    if (found) {
                        if (*(u16 *)(found + 0x30) & 1) {
                            fn_8003FED8(*(void **)(found + 0x38));
                            *(u16 *)(found + 0x30) &= 0xFFFE;
                        }
                    }
                }
                item += 0x10;
                ++i;
            check2:
                if (i < *(u16 *)(list + 4)) {
                    goto body2;
                }
            }
        } else if (*(volatile u16 *)(entry + 0x30) & 1) {
            fn_8003FED8(*(void **)(entry + 0x38));
            *(u16 *)(entry + 0x30) &= 0xFFFE;
        }

        if (*(volatile u16 *)(entry + 0x30) & 0x800) {
            if (*(volatile u16 *)(entry + 0x30) & 0x2000) {
                s32 i;
            u8 *item;
            u8 *list;
            list = *(u8 **)(entry + 0x38);
                i = 0;
                item = list + 8;
                goto check3;
            body3:
                {
                    u8 *found;
                unsigned long j;
                u32 key;
                u8 *e;
                unsigned ctr;
                    e = gFileCache;
                    key = *(u32 *)(item + 8);
                    j = 0;
                    for (ctr = 0x400; ctr > 0; ctr--) {
                        if (*(u32 *)(e + 0x38) == key) {
                            found = gFileCache + j * 0x7C;
                            goto found3;
                        }
                        e += 0x7C;
                        j += 1;
                    }
                    found = 0;
                found3:
                    if (found) {
                        found[0] = 0;
                        *(u32 *)(found + (u32)0x2C) = 0;
                        *(u16 *)(found + 0x30) = 0;
                        *(u16 *)(found + 0x32) = 0;
                        *(u32 *)(found + 0x38) = 0;
                        *(u32 *)(found + 0x3C) = 0;
                    }
                }
                item += 0x10;
                i++;
            check3:
                if (i < *(u16 *)(list + 4)) {
                    goto body3;
                }
            }
        }

        fn_800C4588(*(void **)(entry + 0x38));
        entry[0] = 0;
        *(u32 *)(entry + 0x2C) = 0;
        *(u16 *)(entry + 0x30) = 0;
        *(u16 *)(entry + 0x32) = 0;
        *(u32 *)(entry + 0x38) = 0;
        *(u32 *)(entry + 0x3C) = 0;
    }
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void FileCache_SpawnArchiveEntries(u8 *arg0) {
    s64 OSGetTime(void);
    void *fn_8005CEC0(void);
    void strcpy(char *, char *);
    char path[0x30];
    u8 *entry;
    u8 *list;
    u8 *item;
    s32 i;
    char *var_r3;
    char *var_r6;
    char *var_r4;
    unsigned ctr;
    s32 var_r7;
    u8 temp_r5;

    if (*(u16 *)(arg0 + 0x30) & 0x800) {
        list = *(u8 **)(arg0 + 0x38);
        i = 0;
        item = list + 8;
        goto check;
    body:
        var_r3 = &path[0];
        var_r6 = (char *)arg0;
        var_r4 = var_r3;
        *(u32 *)(item + 4) = *(u32 *)(item + 4) + (u32)list;
        var_r7 = 0;
        *(u32 *)(item + 8) = *(u32 *)(item + 8) + (u32)list;
        for (ctr = 0x29; ctr > 0; ctr--) {
            temp_r5 = *(u8 *)var_r6;
            if ((s8)temp_r5 == 0) {
                break;
            }
            if ((s8)temp_r5 == '\\' || (s8)temp_r5 == '/') {
                var_r3 = &path[0] + 1;
                var_r3 = var_r3 + var_r7;
            }
            *var_r4 = temp_r5;
            var_r4 += 1;
            var_r7 += 1;
            var_r6 += 1;
        }
        strcpy(var_r3, *(char **)(item + 4));

        {
            entry = fn_8005CEC0();
            *(u16 *)(entry + 0x32) = 0;
            var_r6 = &path[0];
            *(u16 *)(entry + 0x30) = 0x3000;
            *(u32 *)(entry + 0x3C) = *(u32 *)(item + 0xC);
            *(u32 *)(entry + 0x38) = *(u32 *)(item + 8);
            entry[0x29] = arg0[0x29];
            if ((s8)path[0] == '/') {
                var_r6 += 1;
            }
            var_r7 = 0;
            *(u32 *)(entry + 0x2C) = 0;
            var_r3 = (char *)entry;
            for (ctr = 0x29; ctr > 0; ctr--) {
                temp_r5 = *(u8 *)var_r6;
                if ((s8)temp_r5 >= 'A' && (s8)temp_r5 <= 'Z') {
                    *var_r6 = temp_r5 + 0x20;
                }
                *var_r3 = *var_r6;
                temp_r5 = *(u8 *)var_r6;
                if ((s8)temp_r5 == 0) {
                    break;
                }
                var_r7 += 1;
                var_r3 += 1;
                *(u32 *)(entry + 0x2C) = (s8)temp_r5 + *(u32 *)(entry + 0x2C) * 0x25;
                var_r6 += 1;
            }
            *(u32 *)(entry + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
        }
        item += 0x10;
        i += 1;
    check:
        if (i < *(u16 *)(list + 4)) {
            goto body;
        }
    }
}
#pragma global_optimizer on

#pragma push
#pragma optimization_level 4
void fn_8005DB40(u8 *arg0, char *arg1, u8 *arg2, u16 arg3) {
    s64 OSGetTime(void);
    u32 fn_8005E594(s8, s32, char *);
    u32 fn_800C44F4(s8);
    u32 fn_800C45B8(s32, char *, s32);
    u32 fn_800C4604(s8, s32, char *, s32);
    void fn_801ED848(void *, u32, void *, u8 *);
    void fn_8005E014(void);
    extern char lbl_8026B330[];
    extern u8 lbl_803672E8;
    u32 strlen(char *);
    char *src;
    u8 *dst;
    s32 i;
    char *p;
    char *ext;
    s32 match;
    u8 c;
    u8 drive;
    s32 size;
    s32 off;
    u32 handle;

    FileCache_CopyName(arg0, arg1);
    arg0[0x29] = lbl_803672E8;
    *(u16 *)(arg0 + 0x32) = 0;
    *(u16 *)(arg0 + 0x30) = arg3;
    *(u32 *)(arg0 + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));

    if (FileCache_HasExtension(arg1, lbl_8026B330 + 0x221)) {
        *(u16 *)(arg0 + 0x30) = 0xC00;
    }

    if (FileCache_HasExtension(arg1, lbl_8026B330 + 0x226)) {
        *(u16 *)(arg0 + 0x30) = 0x800;
    }

    if (FileCache_HasExtension(arg1, lbl_8026B330 + 0x22B)) {
        *(u16 *)(arg0 + 0x30) = 0x400;
    }

    *(s32 *)(arg0 + 0x3C) = *(s32 *)(arg2 + 0x64);
    if (*(u16 *)(arg0 + 0x30) & 0x410) {
        *(u32 *)(arg0 + 0x38) = fn_800C45B8(-*(s32 *)(arg0 + 0x3C), lbl_8026B330 + 5, 0);
    } else {
        drive = arg0[0x29];
        size = *(s32 *)(arg0 + 0x3C);
        if (fn_800C44F4((s8)drive) < (u32)size) {
            handle = 0;
        } else {
            off = (s32)strlen(arg1) - 0xF;
            if (off < 0) {
                off = 0;
            }
            handle = fn_800C4604((s8)drive, size, arg1 + off, size);
        }
        *(u32 *)(arg0 + 0x38) = handle;
    }
    if (*(u32 *)(arg0 + 0x38) == 0) {
        *(u32 *)(arg0 + 0x38) = fn_8005E594((s8)arg0[0x29], *(s32 *)(arg0 + 0x3C), arg1);
    }
    fn_801ED848(arg2, *(u32 *)(arg0 + 0x38), fn_8005E014, arg0);
}
#pragma pop

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

void FileCache_ExpandBuffer(void *a)
{
    u32 fn_80006AC0(u32);
    u32 fn_800C44F4(s8);
    u32 fn_800C4604(s8, u32, void *, u32);
    u32 fn_8005E594(s8, u32, void *);
    void fn_800065B0(u32, u32, void *, void *);
    s32 strlen(void *);
    extern u8 fn_8005DF60[];
    u32 n;
    u32 ch;
    u32 ch2;
    u32 old;
    s32 len;
    u32 result;

    old = *(u32 *)((u8 *)a + 0x38);
    n = fn_80006AC0(old);
    *(u32 *)((u8 *)a + 0x3c) = n;
    ch = *(s8 *)((u8 *)a + 0x29);
    n = *(u32 *)((u8 *)a + 0x3c);
    if (fn_800C44F4((s8)ch) < n) {
        result = 0;
    } else {
        len = strlen(a) - 0xf;
        if (len < 0) {
            len = 0;
        }
        result = fn_800C4604((s8)ch, n, (u8 *)a + len, n);
    }
    *(u32 *)((u8 *)a + 0x38) = result;
    if (*(u32 *)((u8 *)a + 0x38) == 0) {
        ch2 = *(s8 *)((u8 *)a + 0x29);
        *(u32 *)((u8 *)a + 0x38) =
            fn_8005E594((s8)ch2, *(u32 *)((u8 *)a + 0x3c), a);
    }
    fn_800065B0(old, *(u32 *)((u8 *)a + 0x38), fn_8005DF60, a);
}

void fn_8005DF60(void *arg0, s32 arg1) {
    void fn_8020AEC4(u8 *);
    extern u8 gFileCacheWorkQueue[];
    extern volatile u8 gFileCacheWorkWrite;
    extern u8 gFileCacheWorkThreadQueue[8];
    u8 *entry;

    entry = gFileCacheWorkQueue + gFileCacheWorkWrite * 0xC;
    entry[0] = 3;
    *(void **)(entry + 4) = arg0;
    *(s32 *)(entry + 8) = arg1;
    gFileCacheWorkWrite = (gFileCacheWorkWrite + 1) & 0x3F;
    fn_8020AEC4(gFileCacheWorkThreadQueue);
}

void FileCache_QueueAramDone(void *arg0) {
    void fn_8020AEC4(u8 *);
    extern u8 gFileCacheWorkQueue[];
    extern volatile u8 gFileCacheWorkWrite;
    extern u8 gFileCacheWorkThreadQueue[8];
    u8 *entry;
    s32 val;

    entry = gFileCacheWorkQueue + gFileCacheWorkWrite * 0xC;
    val = *(s32 *)((u8 *)arg0 + 0x6c);
    entry[0] = 2;
    *(void **)(entry + 4) = arg0;
    *(s32 *)(entry + 8) = val;
    gFileCacheWorkWrite = (gFileCacheWorkWrite + 1) & 0x3F;
    fn_8020AEC4(gFileCacheWorkThreadQueue);
}

void fn_8005E014(void *arg0) {
    void fn_8020AEC4(u8 *);
    extern u8 gFileCacheWorkQueue[];
    extern volatile u8 gFileCacheWorkWrite;
    extern u8 gFileCacheWorkThreadQueue[8];
    u8 *entry;

    entry = gFileCacheWorkQueue + gFileCacheWorkWrite * 0xC;
    entry[0] = 1;
    *(void **)(entry + 4) = arg0;
    *(s32 *)(entry + 8) = 0;
    gFileCacheWorkWrite = (gFileCacheWorkWrite + 1) & 0x3F;
    fn_8020AEC4(gFileCacheWorkThreadQueue);
}

void fn_8005E070(s32 arg0, void *arg1) {
    void fn_8020C79C(void *);
    void fn_8020AEC4(u8 *);
    extern u8 gFileCacheWorkQueue[];
    extern volatile u8 gFileCacheWorkWrite;
    extern u8 gFileCacheWorkThreadQueue[8];
    u8 *entry;
    s32 val;

    val = *(s32 *)((u8 *)arg1 + 0x2C);
    fn_8020C79C(arg1);
    if (arg0 >= 0) {
        entry = gFileCacheWorkQueue + gFileCacheWorkWrite * 0xC;
        entry[0] = 0;
        *(s32 *)(entry + 4) = val;
        *(s32 *)(entry + 8) = 0;
        gFileCacheWorkWrite = (gFileCacheWorkWrite + 1) & 0x3F;
        fn_8020AEC4(gFileCacheWorkThreadQueue);
    }
}

void fn_8005E0F0(void) {
    void fn_8020A824(void *);
    extern u8 lbl_8030F7E0[];
    extern u8 lbl_803672E9;
    if (lbl_803672E9 != 0) {
        fn_8020A824(lbl_8030F7E0);
        lbl_803672E9 = 0;
    }
}

#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma use_lmw_stmw off
void fn_8005E12C(u8 *arg0, char *arg1, u16 arg2) {
    s64 OSGetTime(void);
    u32 fn_8005E594(s32, s32, char *);
    u32 fn_800C44F4(s8);
    u32 fn_800C45B8(s32, char *, s32);
    u32 fn_800C4604(s8, s32, char *, s32);
    void fn_8020C6D4(char *, u8 *);
    void fn_8020CB38(u8 *, u32, s32, s32, void *, s32);
    extern void fn_8005E070(void);
    extern char lbl_8026B330[];
    extern u8 lbl_803672E8;
    u32 strlen(char *);

    FileCache_CopyName(arg0, arg1);

    fn_8020C6D4(arg1, arg0 + 0x40);
    arg0[0x29] = lbl_803672E8;
    *(u16 *)(arg0 + 0x32) = 0;
    ((FileCacheEntry_8005BB2C *)arg0)->flags = arg2;
    *(u32 *)(arg0 + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
    *(u8 **)(arg0 + 0x6C) = arg0;

    if (FileCache_HasExtension(arg1, lbl_8026B330 + 0x221)) ((FileCacheEntry_8005BB2C *)arg0)->flags |= 0xC00;
    if (FileCache_HasExtension(arg1, lbl_8026B330 + 0x226)) ((FileCacheEntry_8005BB2C *)arg0)->flags |= 0x800;
    if (FileCache_HasExtension(arg1, lbl_8026B330 + 0x22B)) ((FileCacheEntry_8005BB2C *)arg0)->flags |= 0x400;
    *(s32 *)(arg0 + 0x3C) = (*(s32 *)(arg0 + 0x74) + 0x1F) & ~0x1F;

    if (((FileCacheEntry_8005BB2C *)arg0)->flags & 0x410) {
        *(u32 *)(arg0 + 0x38) = fn_800C45B8(-*(s32 *)(arg0 + 0x3C), lbl_8026B330 + 5, 0);
    } else {
        if (((FileCacheEntry_8005BB2C *)arg0)->flags & 2) {
            *(u32 *)(arg0 + 0x38) = FileCache_AllocFromHeap(*(u32 *)(arg0+0x3C)+1, *(s8 *)(arg0+0x29), arg1);
            *(u8 *)(*(u8 **)(arg0 + 0x3C) + *(u32 *)(arg0 + 0x38)) = 0;
        } else {
            s32 drive; u32 size; s32 off; u32 result;
            drive=*(s8 *)(arg0+0x29);
            size=*(u32 *)(arg0+0x3C);
            if(fn_800C44F4(drive)<size) result=0;
            else {
                off=(s32)strlen(arg1)-15;
                if(off<0)off=0;
                result=fn_800C4604(drive,size,arg1+off,size);
            }
            *(u32 *)(arg0+0x38)=result;
        }
        if (*(u32 *)(arg0 + 0x38) == 0) {
            *(u32 *)(arg0 + 0x38) = fn_8005E594(*(s8 *)(arg0+0x29), *(s32 *)(arg0 + 0x3C), arg1);
        }
    }

    if ((((FileCacheEntry_8005BB2C *)arg0)->flags & 0x300) == 0x300) {
        fn_8020CB38(arg0 + 0x40, *(u32 *)(arg0 + 0x38), *(s32 *)(arg0 + 0x3C), 0, (void *)fn_8005E070, 3);
    } else {
        fn_8020CB38(arg0 + 0x40, *(u32 *)(arg0 + 0x38), *(s32 *)(arg0 + 0x3C), 0, (void *)fn_8005E070, 2);
    }
}
#pragma pop
u32 fn_8005E55C(void) {
    s64 OSGetTime(void);
    return OSGetTime() / (*(u32 *)0x800000F8 >> 2);
}

#pragma dont_inline on
void *fn_8005E594(s32 arg0, u32 arg1, char *arg2) {
    void DebugPrint(char *, ...);
    void fn_8005BC8C();
    u32 fn_800C44F4(s32);
    void *fn_800C4604(s32, u32, char *, u32);
    void fn_800C4384(void);
    unsigned long strlen(const char *);
    extern u8 lbl_8026B330[];
    void *result;
    char *a2;
    u32 a1;
    s32 ofs;

    result = (void *)arg0;
    a2 = arg2;
    a1 = arg1;
    DebugPrint((char *)(lbl_8026B330 + 0x230));
    fn_8005BC8C((s8)arg0);
    if (fn_800C44F4((s32)result) < a1) {
        result = NULL;
    } else {
        ofs = strlen(a2) - 0xF;
        if (ofs < 0) {
            ofs = 0;
        }
        result = fn_800C4604((s32)result, a1, a2 + ofs, a1);
    }
    if (result == 0) {
        fn_800C4384();
    }
    return result;
}
#pragma dont_inline reset