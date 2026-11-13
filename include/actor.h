#ifndef ACTOR_H
#define ACTOR_H

#include "common.h"

/* Battle/map actor (size 0x1D8). Layout used by Actor_LoadXml and neighbours. */
typedef struct BattleActor {
    u8 pad_00[0x124];
    f32 height;       /* 0x124 */
    f32 radius;       /* 0x128 */
    s32 unk_12C;
    s32 unk_130;
    s32 unk_134;
    s32 unk_138;
    s32 unk_13C;
    u8 pad_140[0x10];
    f32 unk_150;      /* 0x150 */
    u8 pad_154[0x34];
    s32 unk_188;      /* 0x188 timing */
    s32 unk_18C;
    s32 unk_190;
    u8 pad_194[4];
    s32 rate;         /* 0x198 */
    s32 heightFlag;   /* 0x19C */
    u8 pad_1A0;
    u8 flag_1A1;      /* 0x1A1 */
    u8 pad_1A2[0x14];
    u8 flag_1B6;      /* 0x1B6 */
    u8 pad_1B7[5];
    /* StringMap at 0x1BC */
} BattleActor;

#endif
