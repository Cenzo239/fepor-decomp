#ifndef CAMERA_H
#define CAMERA_H

#include "common.h"

/* Active render camera (gCamera). Projection at +0x24, clip at +0x64, view at +0xA4. */
typedef struct Camera {
    u16 flags;       /* +0x00: bit0 = custom projection installed */
    u16 unk_02;
    f32 vpX;         /* +0x04 */
    f32 vpY;         /* +0x08 */
    f32 vpW;         /* +0x0C */
    f32 vpH;         /* +0x10 */
    f32 vpNear;      /* +0x14 */
    f32 vpFar;       /* +0x18 */
    u16 scissorX;    /* +0x1C */
    u16 scissorY;    /* +0x1E */
    u16 scissorW;    /* +0x20 */
    u16 scissorH;    /* +0x22 */
    f32 proj[16];    /* +0x24 Mtx44 */
    f32 clip[16];    /* +0x64 proj*view */
    f32 view[12];    /* +0xA4 Mtx */
    u8 pad_D4[0xAC];
    f32 unk_180;     /* +0x180 */
    f32 unk_184;     /* +0x184 */
} Camera;

extern Camera *gCamera;
extern u8 gCameraProjMode; /* 1 if flags bit0 was set, else 2 */
extern f32 gScreenWidthF;  /* 640.0f */
extern f32 gScreenHeightF; /* 480.0f */
extern f32 gOrthoFarZ;     /* -1000.0f */

void Camera_ApplyOrtho(Camera *cam);
s32 Camera_Get(void);
s32 Camera_GetViewMtx(void);

#endif
