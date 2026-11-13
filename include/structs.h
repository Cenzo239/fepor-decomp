#ifndef STRUCTS_H
#define STRUCTS_H

#include "common.h"

typedef struct {
    u8 unk0;
    u8 pad1[3];
    u32 unk4;
    u8 pad8[4];
    s32 unkC;
} Struct_8014589C;

/* 2D sprite sheet / atlas for Prim2D cell draws */
typedef struct SpriteSheet {
    u8 pad00[0x48];
    u32 texture;   /* +0x48 */
    u8 pad4C[0x54 - 0x4C];
    s32 cellW;     /* +0x54 */
    s32 cellH;     /* +0x58 */
    s32 cols;      /* +0x5C */
    s32 frameCount;/* +0x60 */
    s32 uBase;     /* +0x64 */
    s32 vBase;     /* +0x68 */
    s32 texAttr;   /* +0x6C */
} SpriteSheet;

/* UI text label (-1=left, 0=center, 1=right align) */
typedef struct UiTextLabel {
    u8 pad00[2];
    s8 primParam;    /* +0x02 */
    u8 pad03[5];
    void *msg;       /* +0x08 */
    s16 x;           /* +0x0C */
    s16 y;           /* +0x0E */
    u8 scale;        /* +0x10 */
    u8 spacing;      /* +0x11 */
    u8 colorId;      /* +0x12 */
    u8 pad13;
    s8 align;        /* +0x14 */
} UiTextLabel;

/* Inventory/equipment slot reference (item ptr + uses + flags) */
typedef struct UnitRef {
    void *item; /* +0x00 */
    u8 uses;    /* +0x04 */
    u8 flags;   /* +0x05: low6 name-id, bit6 tint, bit7 badge */
} UnitRef;

#endif
