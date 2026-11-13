#ifndef INCLUDE_UNITS_H
#define INCLUDE_UNITS_H

#include "global.h"

struct Unit {
    /* 0x00 */ u8 unk00[0xB0];
    /* 0xB0 */ u8 unkB0[0x40];
    /* 0xF0 */ u8 unkF0[0x10];
    /* 0x100 */ u8 unk100[0x40];
    /* 0x140 */ u8 unk140[0x48];
    /* 0x188 */ void* person; /* Person_GetByPid; +0x50 support table, +0x54 affinity */
    /* 0x18C */ void* job; /* Job_GetByJid */
    /* 0x190 */ void* unk190; /* +0x8 = allegiance; compared for same-army checks */
    /* 0x194 */ void* unk194;
    /* 0x198 */ u8 unk198[6];
    /* 0x19E */ s8 mapX;
    /* 0x19F */ s8 mapY;
    /* 0x1A0 */ u8 unk1A0[8];
    /* 0x1A8 */ s8 hp;
    /* 0x1A9 */ u8 unk1A9[0x13];
    /* 0x1BC */ u32 statusBits[4]; /* Status_Test bitset */
    /* 0x1CC */ u8 unk1CC[0x40];
    /* 0x20C */ u8 wpnExp[8]; /* weapon-type exp; 0-3/7 also gated by status 0x24-0x28 */
    /* 0x214 */ u8 supportProgress[10]; /* per support-partner rank progress */
};

/* Affinity bonus totals (atk/def/hit/avo/crit/dodge); halved after summing both units. */
struct AffinityBonusInfo {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s8 bonuses[6];
};

#endif // INCLUDE_UNITS_H
