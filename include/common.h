/* Basic types for this decompilation (CodeWarrior conventions). Agents add structs and prototypes here or in
 * new headers next to it. */
#ifndef COMMON_H
#define COMMON_H

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
typedef unsigned long uintptr_t;
#define TRUE 1
#define FALSE 0
#ifndef NULL
#define NULL ((void*)0)
#endif

/* 0x18-byte record used by fn_800C29D0 / fn_800C2ACC / fn_800C30CC (1-based index) */
#ifndef UNK800C2ACC_TYPE
#define UNK800C2ACC_TYPE
typedef struct Unk800C2ACC {
    u8 unk0[0x13];
    u8 unk13;
    u8 unk14[4];
} Unk800C2ACC;
#endif

/* Memory-card linked-game IDs (FourCC) and system-save bonus flags at gSystemSave+0x10 */
#define GAME_ID_AFEJ 0x4146454A /* Animal Crossing (JP) */
#define GAME_ID_AE7J 0x4145374A /* Pokémon Box Ruby/Sapphire (JP) */
#define GAME_ID_AE7E 0x41453745 /* Pokémon Box (US) */
#define GAME_ID_AE7X 0x41453758 /* Pokémon Box (EU X) */
#define GAME_ID_AE7Y 0x41453759 /* Pokémon Box (EU Y) */
#define GAME_ID_BE8J 0x4245384A /* Fire Emblem: The Sacred Stones (JP) */
#define GAME_ID_BE8E 0x42453845 /* Fire Emblem: The Sacred Stones (US) */
#define GAME_ID_BE8P 0x42453850 /* Fire Emblem: The Sacred Stones (EU) */
#define LINK_BONUS_FLAG_AC      0x08
#define LINK_BONUS_FLAG_POKEMON 0x10
#define LINK_BONUS_FLAG_FE8     0x20

/* Dolphin CARD API result codes */
#define CARD_RESULT_UNLOCKED    1
#define CARD_RESULT_READY       0
#define CARD_RESULT_BUSY       -1
#define CARD_RESULT_WRONGDEVICE -2
#define CARD_RESULT_NOCARD     -3
#define CARD_RESULT_NOFILE     -4
#define CARD_RESULT_IOERROR    -5
#define CARD_RESULT_BROKEN     -6
#define CARD_RESULT_EXIST      -7
#define CARD_RESULT_NOENT      -8
#define CARD_RESULT_INSSPACE   -9
#define CARD_RESULT_NOPERM     -10
#define CARD_RESULT_LIMIT      -11
#define CARD_RESULT_NAMETOOLONG -12
#define CARD_RESULT_CANCELED   -13
#define CARD_RESULT_ENCODING   -14
#define CARD_RESULT_FATAL_ERROR -128

/* Save-file version stamps (YYYYMMDD as hex) */
#define SAVE_VER_20041216 0x20041216
#define SAVE_VER_20050201 0x20050201

/* Chapter/suspend save slot header (at slot+0x40) */
#define SAVE_SLOT_MAGIC        0x4645384AU /* "FE8J" */
#define SAVE_CHECKSUM_UNINIT   0x12345678U /* checksum not yet written */
#define SAVE_SLOT_PAYLOAD_OFF  0x70
#define SAVE_SLOT_BLOCK_SIZE   0x2000

/* Unit/class map-move SFX category flags (MSFX_*) */
#define MSFX_FLAG_MAGE   0x0001
#define MSFX_FLAG_FLY    0x0002
#define MSFX_FLAG_KNIGHT 0x0004
#define MSFX_FLAG_ARMOR  0x0008
#define MSFX_FLAG_ALIZE  0x0010
#define MSFX_FLAG_HUMAN  0x0020
#define MSFX_FLAG_BEAST  0x0040
#define MSFX_FLAG_DRAGON 0x0080
#define MSFX_FLAG_BIRD   0x0100
#define MSFX_FLAG_FINAL  0x0200
#define MSFX_FLAG_HERO   0x0400
#define MSFX_FLAG_BOSS   0x0800
#define MSFX_FLAG_DOORBREAK 0x1000

/* GX vertex attribute IDs (subset used by Gfx_SetupVtxFormat) */
#define GX_VA_PNMTXIDX 0
#define GX_VA_POS      9
#define GX_VA_NRM      10
#define GX_VA_CLR0     11
#define GX_VA_TEX0     13
#define GX_VA_TEX1     14
#define GX_VA_TEX2     15
#define GX_VA_TEX3     16
#define GX_VA_NBT      25
#define GX_VA_NULL     0xFF
#define GX_NONE        0
#define GX_DIRECT      1
#define GX_INDEX16     3

/* Global variables from the original game code */
extern u8 lbl_803671C0;
extern u8 lbl_80366DB0;
extern s32 gActiveCam;
extern u8 gActiveCamIndex;
extern f32 lbl_80368C8C;
extern f32 lbl_80368CAC;
extern char lbl_802704F8[];


/* What machine drafts (m2c) use for what they can't tell yet: autopilot tries them as they are. */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)

struct unit {
      u8 pad_0x0[0x8];
      s32 unk_0x8;
      s32 unk_0xC;
  };

struct efUnit {
    struct Unit* unit;
    s32 field_0x4;
    s32 field_0x8;
    s32 field_0xC;
    s32 field_0x10;
    s32 field_0x14;
    struct efUnit* field_0x18;
    struct efUnit* field_0x1C;
    struct efUnit* field_0x20;
    struct efUnit* field_0x24;
    s32 field_0x28;
    s32 field_0x2C;  
    s32 field_0x30;
    s32 field_0x34;
    s32 field_0x38;
    s32 field_0x3C;
    s32 field_0x40;
    s32 field_0x44;
    s32 field_0x48;
};

      struct UnitEntry {
        u8 unk0[4];
        u8 unk4;
        u8 unk5;
        u8 unk6;
        u8 unk7;
    };

    struct UnitTable {
        u8 unk0[8];
        struct UnitEntry entries[256];
    };

    #endif
    
    #endif
