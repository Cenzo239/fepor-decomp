#ifndef CAMPATH_H
#define CAMPATH_H

#include "common.h"

/* Overlay on Process for camera-path animation (CamPath_Update / CamPath_Apply).
 * Common Process fields occupy +0x00..+0x2F; path state starts at +0x30. */
typedef struct CamPathProc {
    u8 pad_00[0x30];
    s32 ease_mode;       /* +0x30: 0=linear, 1=ease-in, 2=ease-out, 3=ease-in-out */
    s32 frame;           /* +0x34: current frame */
    s32 duration;        /* +0x38: total frames */
    u8 done;             /* +0x3C: set when path finishes */
    u8 pad_3D[3];
    void *keyframes;     /* +0x40 */
    u8 keyframe_count;   /* +0x44 */
    u8 look_count;       /* +0x45: look-at key count */
    u8 pos_count;        /* +0x46: position key count */
    u8 pad_47;
    void *look_keys;     /* +0x48 */
    void *pos_keys;      /* +0x4C */
} CamPathProc;

void CamPath_Update(void *proc);
void CamPath_Apply(void *proc, f32 t);

#endif
