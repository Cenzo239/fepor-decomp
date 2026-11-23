/* Functions from 0x801101D0 to 0x80120CC0, found by decomp-toolkit. */
#include "common.h"
#include "actor.h"
extern u8 lbl_8032FE24[];
extern u16 gActorXmlStrs[];
extern u16 lbl_80296128[];
extern u8 lbl_80273DF8[];

typedef struct String {
    u32 size;
    u32 cap;
    char *data;
} String;

typedef struct Fn80116F84Args {
    s32 a;
    s32 b;
    s32 c;
} Fn80116F84Args;

extern f32 lbl_8036A1DC;
extern f32 fActorDefaultRadius;
extern f32 lbl_8036A1C8;
extern u16 lbl_8028F6C8[];
void String_Init(void *, char *, void *);
void String_Destroy(void *, s32);
void fn_800E6418(void *, s32, void *, s32, s32, void *);
void fn_800D6878(void *, void *, void *);
void String_AssignCStr(void *, char *, u32);
s32 String_Compare(void *, s32, void *, char *, s32);
s32 fn_800C9400(void *, u32, void *, char *, s32);
void fn_800C9ABC(void *, void *, void *);
void fn_800C96F8(void *, void *, u32);
void fn_800C9A60(void *, s32);
s32 String_Find(void *, char *, s32, s32);
u8 Actor_IsBusy(void *);
void Actor_LoadAnim(void *, void *, s32, s32, s32);
void fn_801134EC(void *, void *, void *);
void String_Assign(void *, void *, s32, s32);
void *String_CStr(void *);
extern u16 gUiPanelFlags;

extern s32 gUiInputFlags;

extern s32 gBattleState[];
extern f32 lbl_8036A184;
extern f32 lbl_8036A1BC;
extern f32 lbl_8036A1B0;
extern f64 lbl_8036A198;
extern f32 lbl_8036A1D8;
void fn_8005FEE8(void *, f32);
void fn_800608AC(void *);
void PSMTXRotRad(void *, s32, void *, f32, f32);
void fn_802029C4(void *, void *, void *);
#define VCALL(ptr, offset) (((void(**)(void *, void *))((u8*)(ptr) + (offset)))[0])

typedef struct {
    void *unk0;
    void *unk4;
    void *unk8;
    void *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
    void *unk28;
    void *unk2C;
    void *unk30;
    void *unk34;
    void *unk38;
    void *unk3C;
    void *unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    // ... (more fields if needed)
} UnitStruct;

extern u8 lbl_8028FDB0[];
extern u8 lbl_80292230[];
extern u8 lbl_802921E0[];

extern f32 lbl_8036A1E8;
extern f32 lbl_8036A1F8;

extern u8 lbl_80367A48;

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma use_lmw_stmw on
#pragma optimization_level 3
#pragma cplusplus on

#pragma use_lmw_stmw on

#pragma cplusplus reset
#pragma optimization_level reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset
#pragma use_lmw_stmw on
#pragma global_optimizer off
/* Parse actor XML at path into self: string-map entries, scalars, then apply defaults. */

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

#pragma cplusplus on
typedef struct Vec3f {
    f32 x, y, z;
    Vec3f() {}
    Vec3f(f32 _x, f32 _y, f32 _z) {
        x = _x;
        y = _y;
        z = _z;
    }
} Vec3f;
extern "C" f32 PSVECDistance(const Vec3f &, const Vec3f &);

#pragma cplusplus reset

#pragma global_optimizer off

#pragma global_optimizer off

#pragma global_optimizer on
/* Load an actor animation from a relative path under the actor base dir. */

#pragma global_optimizer off

#pragma global_optimizer on

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

typedef struct { f32 x, y, z; } PVector3;
#pragma cplusplus on
struct ActorMotionInterface {
    u8 pad[0x40];
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
    virtual PVector3 GetPos(s32) = 0;
    virtual void v13() = 0;
    virtual void Adjust(void *, f32, f32) = 0;
};
#pragma cplusplus on
#pragma push
#pragma dont_inline on
#pragma optimization_level 3
#pragma global_optimizer off

  #pragma pop
  #pragma cplusplus off

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer off
#pragma cplusplus on

#pragma cplusplus reset
#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma peephole off

#pragma peephole reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma global_optimizer off
#pragma cplusplus on

#pragma cplusplus reset
#pragma global_optimizer reset

#pragma optimization_level 1

#pragma optimization_level reset
#pragma cplusplus off
#pragma cplusplus on
#pragma cplusplus on
static inline s32 ActorUpdate_Compare(void *str, char *text) {
 s32 strlen(char *);
 return String_Compare(str,0,*(void **)str,text,strlen(text));
}
static inline void ActorUpdate_CopyVector(Vec3f *dst, const Vec3f *src) {
 const u32 *in=(const u32 *)src;
 u32 *out=(u32 *)dst;
 out[0]=in[0];out[1]=in[1];out[2]=in[2];
}
static inline void ActorUpdate_ReadPosition(Vec3f *out, void *actor) {
 typedef void (*Callback)(Vec3f *,void *,s32);
 Callback *vtable=*(Callback **)((u8 *)actor+0x40);
 Callback callback=vtable[14];
 callback(out,actor,0);
}
struct ActorUpdateSceneInterface {
 u8 pad[0x10];
 virtual void v0()=0;virtual void v1()=0;virtual void v2()=0;virtual void v3()=0;virtual void v4()=0;
 virtual void Add(void *)=0;
};
struct ActorUpdateInterface {
 u8 pad[0x40];
 virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
 virtual void v4()=0; virtual void v5()=0; virtual void v6()=0;
 virtual void SetScale(f32,f32,f32)=0;
 virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void v11()=0;
 virtual Vec3f GetPos(s32)=0;
 virtual void v13()=0; virtual void v14()=0; virtual void v15()=0;
 virtual u8 IsBusy()=0;
};
#pragma cplusplus off
#pragma cplusplus on
#pragma global_optimizer off
#pragma optimization_level reset
#pragma global_optimizer off

#pragma optimization_level reset
#pragma global_optimizer reset
#pragma cplusplus off

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer on

#pragma optimization_level 3

#pragma optimization_level reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset

#pragma global_optimizer off

void fn_8011AB38(void *arg0) {
    u8 FileCache_IsReady(void);
    s32 fn_80161FB8(void);
    void fn_80162054(void);
    void fn_801620AC(void *);
    s32 Archive_Load(void);
    void Process_ClearFunc(void *);

    fn_801620AC(arg0);
    if (FileCache_IsReady() == 0) {
        goto end;
    }
    if (fn_80161FB8() != 0) {
        goto work;
    }
    goto end;
work:
    fn_80162054();
    fn_801620AC(arg0);
    *(s32 *)((char *)arg0 + 0x40) = Archive_Load();
    Process_ClearFunc(arg0);
end:;
}
#pragma global_optimizer on
