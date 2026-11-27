/* Functions from 0x8005A2A8 to 0x8005ADE4, found by decomp-toolkit. */
#include "common.h"

s32 fn_8005A2A8(void) {
    return 0;
}

s32 fn_8005A2B0(void) {
    return 1;
}

s32 fn_8005A2B8(void) {
    return 2;
}

s32 fn_8005A2C0(void) {
    return 6;
}

s32 fn_8005A2C8(void) {
    return 7;
}

s32 fn_8005A2D0(void) {
    return 8;
}

s32 fn_8005A2D8(void) {
    return 0;
}

s32 fn_8005A2E0(void) {
    return 0x300;
}

s32 fn_8005A2E8(void) {
    return 0xF0;
}

s32 fn_8005A2F0(void) {
    return 0x20;
}

s32 fn_8005A2F8(void) {
    return 0xA;
}

s32 fn_8005A300(void) {
    return 0x18;
}

s32 fn_8005A308(void) {
    return 0x18;
}

s32 fn_8005A310(void *arg0, u8 arg1, u8 arg2) {
    switch (arg1) {
    case 0:
    case 8:
        return 0x10;
    case 1:
        return 0x11;
    case 2:
        return 0x12;
    case 3:
        return 0x13;
    case 4:
        return 0x15;
    case 5:
        return 0x17;
    case 6:
        return 0x16;
    case 7:
        return arg2 ? 0x18 : 0x14;
    }
    return 0;
}

void fn_8005A388(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 x, f32 y, f32 z) {
void Prim2D_Begin(void);
void Prim2D_SetTex(void*,s32);
void Prim2D_PrepareTex(void);
void Prim2D_AddPrim(s32);
void Prim2D_SetRectUv(f32,f32,f32,f32,f32,f32);
void Prim2D_EndPrim(void);
extern f32 lbl_80369184,lbl_80369188;
void Prim2D_SetTransform(f32,f32,f32,f32);
void Prim2D_SetColor(s32,s32,s32,s32);
#pragma cplusplus on
struct Obj {
u8 pad[0x44];
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
virtual s32 v12()=0;
virtual void v13()=0;
virtual s32 v14()=0;
virtual s32 v15()=0;
};
s32 w, cols;
s32 offset;
f32 height,u,v;
if(arg3) {
Prim2D_Begin();
Prim2D_SetTransform(x,y,z,lbl_80369184);
Prim2D_SetTex((u8*)arg0+4,arg2);
Prim2D_PrepareTex();
w=((Obj*)arg0)->v14();
cols=((Obj*)arg0)->v12();
offset=(arg3-1)%cols;
u=(f32)(offset*w);
w=((Obj*)arg0)->v15();
cols=((Obj*)arg0)->v12();
offset=(arg3-1)/cols;
v=(f32)(offset*w);
Prim2D_AddPrim(1);
height=(f32)((Obj*)arg0)->v15();
w=((Obj*)arg0)->v14();
Prim2D_SetRectUv(lbl_80369188,lbl_80369188,u,v,(f32)w,height);
Prim2D_SetColor(255,255,255,arg1);
Prim2D_EndPrim();
}
#pragma cplusplus reset
}

void fn_8005A584(void *arg0,s32 arg1,s32 arg2,f32 x,f32 y) {
void Prim2D_SetAlpha(s32);
void Prim2D_Begin(void);
void Prim2D_SetTex(void *,s32);
void fn_8000A03C(void *,void *,s32,s32);
void Prim2D_PrepareTex(void);
void Prim2D_AddPrim(s32);
void Prim2D_SetRectUv(f32,f32,f32,f32,f32,f32);
void Prim2D_EndPrim(void);
#pragma cplusplus on
struct Obj {
u8 pad[0x44];
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
virtual s32 v12()=0;
virtual void v13()=0;
virtual s32 v14()=0;
virtual s32 v15()=0;
};
s32 w,cols;
s32 offset;
f32 height,u,v;
if(arg2) {
Prim2D_Begin();
if(((u8 *)arg0)[0x40]) fn_8000A03C((u8 *)arg0+4,(u8 *)arg0+0x24,0,0x11);
else Prim2D_SetTex((u8 *)arg0+4,0x11);
Prim2D_PrepareTex();
w=((Obj *)arg0)->v14();
cols=((Obj *)arg0)->v12();
offset=(arg2-1)%cols;
u=(f32)(offset*w);
w=((Obj *)arg0)->v15();
cols=((Obj *)arg0)->v12();
offset=(arg2-1)/cols;
v=(f32)(offset*w);
Prim2D_AddPrim(1);
height=(f32)((Obj *)arg0)->v15();
w=((Obj *)arg0)->v14();
Prim2D_SetRectUv(x,y,u,v,(f32)w,height);
Prim2D_SetAlpha(arg1);
Prim2D_EndPrim();
}
#pragma cplusplus reset
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma cplusplus on
extern "C" void DCFlushRange(void *, u32);
extern "C" void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
extern "C" void Prim2D_EndPrim(void);
extern "C" void Prim2D_AddPrim(s32);
extern "C" void fn_8000A03C(void *, void *, s32, s32);
extern "C" void Prim2D_SetTex(void *, s32);
extern "C" void Prim2D_PrepareTex(void);
extern "C" void Prim2D_Begin(void);
extern "C" s32 fn_80222CDC(void *);
extern "C" u32 fn_80222CE8(void *);
extern "C" void *memcpy(void *, const void *, u32);
#pragma push
#pragma cplusplus on
#pragma optimization_level 4
#pragma global_optimizer off
#pragma use_lmw_stmw on
extern "C" void fn_8005A79C(void *arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    struct Obj {
        u8 pad[0x44];
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
        virtual s32 v12() = 0;
        virtual void v13() = 0;
        virtual s32 v14() = 0;
        virtual s32 v15() = 0;
    };
    s32 nbytes;
    u8 *color;
    s32 a3;
    s32 a2;
    s32 a1;
    s32 count;
    u8 *pixels;
    u32 off;
    s32 src;
    s32 raw;
    u8 *srcPtr;
    u16 pix;
    u16 r, g, b;
    s32 w;
    s32 cols;
    s32 h;
    s32 offset;
    f32 fw, fx, fy;
    f32 width;

    a3 = arg3;
    a1 = arg1;
    a2 = arg2;
    color = arg4;
    if (a3 != 0) {
        Prim2D_Begin();
        if (((u8 *)arg0)[0x40] != 0) {
            if (color[0] == 0 && color[1] == 0 && color[2] == 0) {
                fn_8000A03C((u8 *)arg0 + 4, (u8 *)arg0 + 0x24, 0, 0x11);
            } else {
                nbytes = fn_80222CDC((u8 *)arg0 + 0x24);
                raw = fn_80222CE8((u8 *)arg0 + 0x24);
                srcPtr = (u8 *)((u32)nbytes + 0x80000000);
                nbytes = ((u16)raw) << 1;
                count = (u16)raw;
                memcpy(*(void **)((u8 *)arg0 + 0x3C), srcPtr, nbytes);
                for (off = 0; count > 0; off += 2) {
                    pixels = *(u8 **)((u8 *)arg0 + 0x3C);
                    pix = *(u16 *)(pixels + off);
                    if (pix & 0x8000) {
                        r = (pix & 0x7C00) >> 10;
                        g = (pix & 0x3E0) >> 5;
                        b = pix & 0x1F;
                        r = (u16)(r + (color[0] >> 3));
                        if (r > 0x1F) {
                            r = 0x1F;
                        }
                        g = (u16)(g + (color[1] >> 3));
                        if (g > 0x1F) {
                            g = 0x1F;
                        }
                        b = (u16)(b + (color[2] >> 3));
                        if (b > 0x1F) {
                            b = 0x1F;
                        }
                        *(u16 *)(pixels + off) = (u16)(0x8000 | (r << 10) | (g << 5) | b);
                    }
                    count--;
                }
                DCFlushRange(*(void **)((u8 *)arg0 + 0x3C), nbytes);
                fn_8000A03C((u8 *)arg0 + 4, (u8 *)arg0 + 0x30, 0, 0x11);
            }
        } else {
            Prim2D_SetTex((u8 *)arg0 + 4, 0x11);
        }
        Prim2D_PrepareTex();
        w = ((Obj *)arg0)->v14();
        cols = ((Obj *)arg0)->v12();
        fx = (f32)(w * ((a3 - 1) % cols));
        h = ((Obj *)arg0)->v15();
        cols = ((Obj *)arg0)->v12();
        offset = (a3 - 1) / cols;
        fy = (f32)(offset * h);
        Prim2D_AddPrim(1);
        fw = (f32)((Obj *)arg0)->v15();
        w = ((Obj *)arg0)->v14();
        width = (f32)w;
        Prim2D_SetRectUv((f32)a1, (f32)a2, fx, fy, width, fw);
        Prim2D_EndPrim();
    }
}
#pragma cplusplus reset
#pragma pop
extern "C" void fn_8005AABC(void *arg0,s32 arg1,s32 arg2,s32 arg3,u8 arg4) {
extern s32 lbl_80369180;
extern f32 lbl_80369188,lbl_80369198,lbl_8036919C;
long long OSGetTime(void);
f32 Math_Ease(s32,f32,f32,f32,f32);
struct Color { u32 bits; };
struct Obj {
u8 pad[0x44];
virtual void v0()=0;
virtual void v1()=0;
virtual void v2()=0;
virtual void v3(s32,s32,s32)=0;
virtual void v4()=0;
virtual void v5(s32,s32,s32,Color)=0;
};
Color color;
u32 time;
s32 level;
if(!arg4) {
((Obj *)arg0)->v3(arg1,arg2,arg3);
return;
}
time=(u32)(OSGetTime()/((*(u32 *)0x800000F8>>2)/1000))%600;
if(time<300) level=(s32)Math_Ease(0,lbl_80369188,lbl_80369198,(f32)time,lbl_8036919C);
else level=(s32)Math_Ease(0,lbl_80369198,lbl_80369188,(f32)(time-300),lbl_8036919C);
color=*(Color *)&lbl_80369180;
((u8 *)&color)[0]=level;
((u8 *)&color)[1]=level;
((u8 *)&color)[2]=level;
((Obj *)arg0)->v5(arg1,arg2,arg3,color);
}

#pragma cplusplus reset
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" void Ui_DrawIcon(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct color {
        u8 r, g, b, a;
    };
    struct Obj {
        u8 pad[0x44];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5(s32, s32, s32, color) = 0;
    };
    extern const color lbl_8036C438;
    ((Obj *)arg0)->v5(arg1, arg2, arg3, lbl_8036C438);
}
#pragma cplusplus reset
void fn_8005AC5C(u32 *arg0) {
    M2C_UNK FileCache_ReleaseSlot();
    if ((u32) *arg0 != 0U) {
        FileCache_ReleaseSlot();
    }
}

extern s32 D_800F1340;
extern s32 D_800F1344;
extern s32 D_800F1348;
extern s32 D_800F134C;
extern s32 D_800F1350;
extern s32 D_800F1354;
extern s32 D_800F1358;
extern s32 D_800F135C;
extern s32 D_803B9610;
#pragma cplusplus on
extern "C" void fn_8006EEFC(void *, s32);
extern "C" void *fn_8006EDD8(void *, s32);
extern "C" void fn_8006EBC4(void *, void *, void *, s32, s32);
extern "C" void *fn_800C4638(s32, char *, s32);
extern "C" void fn_80222CA4(u32 *, u32, u32, u16);
extern "C" void Ui_LoadAtlasTex(void *, void *, s32);
#pragma cplusplus on
#pragma global_optimizer off
extern "C" void Ui_InitIconDrawer(void *arg0) {
    struct Obj {
        u8 pad[0x44];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual s32 v8() = 0;
        virtual s32 v9() = 0;
    };
    extern char lbl_8026AE88[];
    extern void fn_80222CA4(u32 *, u32, u32, u32);
    u32 count;
    void *tmp;

    if (*(u32 *)arg0 == 0) {
        fn_8006EEFC(arg0, ((Obj *)arg0)->v8());
        tmp = fn_8006EDD8(*(void **)arg0, ((Obj *)arg0)->v9());
        if (*(u32 *)((u8 *)tmp + 4) != 0) {
            ((u8 *)arg0)[0x40] = 1;
            fn_8006EBC4(*(void **)arg0, (u8 *)arg0 + 4, (u8 *)arg0 + 0x24, 0, ((Obj *)arg0)->v9());
            fn_80222CDC((u8 *)arg0 + 0x24);
            count = fn_80222CE8((u8 *)arg0 + 0x24);
            *(void **)((u8 *)arg0 + 0x3C) = fn_800C4638(((u16)count) << 1, lbl_8026AE88 + 8, 0);
            fn_80222CA4((u32 *)((u8 *)arg0 + 0x30), (u32)*(void **)((u8 *)arg0 + 0x3C), 2, count);
        } else {
            ((u8 *)arg0)[0x40] = 0;
            Ui_LoadAtlasTex(*(void **)arg0, (u8 *)arg0 + 4, ((Obj *)arg0)->v9());
        }
    }
}
#pragma global_optimizer reset
extern "C" void fn_8005C8B4(s32);
extern "C" void fn_8005ADB4(void *arg0) {
    struct Obj {
        u8 pad[0x44];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual s32 v8() = 0;
    };
    fn_8005C8B4(((Obj *)arg0)->v8());
}
#pragma cplusplus reset
#include "global.h"

extern s32 lbl_80369180;
extern f32 lbl_80369188;
extern f32 lbl_80369198;
extern f32 lbl_8036919C;
extern f32 lbl_803691A0;
#include "global.h"

extern f32 lbl_80369184;
extern f64 lbl_80369190;
extern f32 lbl_80369188;
extern void* gPrim2D;
