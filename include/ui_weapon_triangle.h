#ifndef UI_WEAPON_TRIANGLE_H
#define UI_WEAPON_TRIANGLE_H

#include "common.h"

/* Partial window interface: vtable at +4, depth getter at vtable +0x6C. */
struct UiWindowDepthView {
    u8 pad[4];
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
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual f32 getDepth() = 0;
};

enum {
    UI_TRIANGLE_ITEM_OFFSET = 0x28C,
    UI_TRIANGLE_ITEM_TYPE_OFFSET = 0x13,
    UI_TRIANGLE_NO_ITEM_TYPE = 12,
    UI_TRIANGLE_ICON_TABLE_OFFSET = 0x1C,
    UI_TRIANGLE_ARROW_X_OFFSET = 0x34,
    UI_TRIANGLE_ARROW_Y_OFFSET = 0x58,
    UI_TRIANGLE_ANIMATION_TICKS = 24,
    UI_TRIANGLE_TICKS_PER_FRAME = 8
};

#endif
