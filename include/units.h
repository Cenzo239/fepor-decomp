#ifndef INCLUDE_UNITS_H
#define INCLUDE_UNITS_H

#include "global.h"

struct Unit {
    /* 0x00 */ u16 mapAngle; /* degrees; idle-spins % 360 on active phase */
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 dispFlags; /* bit3 skip visual update; drawable when (flags&0x22)==2 */
    /* 0x04 */ u8 unk04[0x18];
    /* 0x1C */ u8 model[0xB]; /* gfx object (+0x1C); model updater / draw path */
    /* 0x27 */ u8 modelActive; /* nonzero required to update/draw model */
    /* 0x28 */ u8 unk28[0x88];
    /* 0xB0 */ u8 unkB0[0x40];
    /* 0xF0 */ u8 unkF0[0x10];
    /* 0x100 */ u8 unk100[0x40];
    /* 0x140 */ u8 unk140[0x44];
    /* 0x184 */ void* listNext; /* next unit in gUnitLists allegiance chain */
    /* 0x188 */ void* person; /* Person_GetByPid; +0x50 support table, +0x54 affinity */
    /* 0x18C */ void* job; /* Job_GetByJid */
    /* 0x190 */ void* faction; /* +0x8 = allegiance; compared for same-army checks */
    /* 0x194 */ void* rescuePartner; /* other unit while rescuing / being rescued */
    /* 0x198 */ u8 index; /* deployment/script unit id; UnitGetByPos return */
    /* 0x199 */ u8 disposId; /* Unit_SetDisposId; groups units in a dispos entry */
    /* 0x19A */ u8 level; /* UnitSet mid 0; display level */
    /* 0x19B */ u8 exp; /* UnitSet mid 6 via Unit_SetExp; 0..100 or 0xFF */
    /* 0x19C */ s8 transformGauge; /* UnitSet mid 7; 0..0x14 laguz meter */
    /* 0x19D */ u8 unk19D;
    /* 0x19E */ s8 mapX;
    /* 0x19F */ s8 mapY;
    /* 0x1A0 */ u32 stateFlags; /* bit0: skip idle spin; bit1: rescuer; bit2: rescuee; 0x4000: escaped; 0x010000FC: not drawable; bit 0x1C: gone/dead */
    /* 0x1A4 */ u8 unk1A4;
    /* 0x1A5 */ u8 statusNibbles; /* low3 / high3 ((v>>4)&7); high gates item flags 2/4 in Unit_CanEquipItem */
    /* 0x1A6 */ u8 unk1A6[2];
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
