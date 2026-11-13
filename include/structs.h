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

/* 2D sprite sheet / atlas used by Sprite_DrawFrame and siblings */
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

#endif
