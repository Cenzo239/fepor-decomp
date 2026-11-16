/* Functions from 0x8022C518 to 0x8022CCF8, found by decomp-toolkit. */
#include "common.h"

u32 __ptmf_scall(u32* arg0, u32 arg1) {
    u32 r0 = arg0[0];
    u32 r11 = arg0[1];
    u32 r12 = arg0[2];
    
    arg0 = (u32*)((u8*)arg0 + r0);
    if (r11 < 0) {
        return 0;
    }
    
    arg0 = (u32*)((u8*)arg0 + r12);
    return arg0[arg1];
}

u32* fn_8022C540(u32* param_1, u32 param_2) {
    u32 r0 = param_1[0]; 
    u32 r11 = param_1[1];
    u32 r12 = param_1[2];
    
    u32* r4_ptr = param_1 + param_2;
    u32 temp1 = r4_ptr[r12];
    u32* result = (u32*)temp1;
    
    if (r11 < 0) {
        return param_1;
    }
    
    // Actually, looking at the assembly more carefully it's an indexed lookup with a different approach
    return result;
}

s32 __cvt_fp2unsigned(f32 farg0) {
    extern M2C_UNK lbl_80282AD0;
    f32 var_f2;
    s32 temp_cr0_lt;
    s32 var_r3;

    var_r3 = 0;
    temp_cr0_lt = farg0 < (f32) M2C_FIELD(&lbl_80282AD0, f64 *, 0);
    M2C_ERROR(/* "fcmpu $cr6, $f1, $f3" is not supported, the first arg is not $cr0 */);
    if (temp_cr0_lt == 0) {
        var_r3 = -1;
        if (temp_cr0_lt != 0) {
            M2C_ERROR(/* "fcmpu $cr7, $f1, $f4" is not supported, the first arg is not $cr0 */);
            var_f2 = farg0;
            if (temp_cr0_lt == 0) {
                var_f2 = (f32) ((f64) farg0 - M2C_FIELD(&lbl_80282AD0, f64 *, 0x10));
            }
            var_r3 = (s32) var_f2;
            if (temp_cr0_lt == 0) {
                var_r3 += 0x80000000;
            }
        }
    }
    return var_r3;
}

unsigned long long __div2u(unsigned long long a, unsigned long long b) {
 unsigned long long q = 0, r = 0;
 int i;
 for (i = 64; i != 0; --i) { r = (r << 1) | (a >> 63); a <<= 1; q <<= 1; if (r >= b) { r -= b; q |= 1; } }
 return q;
}

s32 __div2i(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 dividend_high = arg0;
    s32 dividend_low = arg1;
    s32 divisor_high = arg2;
    s32 divisor_low = arg3;
    s32 temp_r9;
    s32 temp_r10;
    s32 temp_r0;
    s32 temp_r9_2;
    s32 temp_r9_3;
    s32 var_ctr;
    s32 var_r0;
    s32 var_r3;
    s32 var_r3_2;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;

    var_r3_2 = dividend_high;
    var_r4 = dividend_low;
    var_r5 = divisor_high;
    var_r6 = divisor_low;
    temp_r9 = var_r3_2 & 0x80000000;
    if (temp_r9 != 0) {
        var_r4 = 0 - var_r4;
        var_r3_2 = -var_r3_2;
        if (M2C_CARRY) {
            var_r4--;
        }
    }
    temp_r10 = var_r5 & 0x80000000;
    if (temp_r10 != 0) {
        var_r6 = 0 - var_r6;
        var_r5 = -var_r5;
        if (M2C_CARRY) {
            var_r6--;
        }
    }
    var_r0 = CLZ(var_r3_2);
    if (var_r3_2 == 0) {
        var_r0 = CLZ(var_r4) + 0x20;
    }
    temp_r9_2 = CLZ(var_r5);
    if (var_r5 == 0) {
        temp_r9_2 = CLZ(var_r6) + 0x20;
    }
    if (var_r0 <= temp_r9_2) {
        var_ctr = 0x40 - temp_r9_2;
        temp_r0 = var_r0 + var_ctr;
        var_ctr = 0x40 - temp_r0;
        if (temp_r0 >= 0x20) {
            var_r7 = 0;
        } else {
            var_r7 = (u32)var_r3_2 >> (temp_r0 - 0x20);
        }
        if (var_r0 <= 0x20) {
            var_r3 = (var_r3_2 << var_r0) | (var_r4 >> (0x20 - var_r0));
        } else {
            var_r3 = var_r4 << (var_r0 - 0x20);
        }
        temp_r9_3 = temp_r9_2;
        do {
            s32 r3_4 = var_r3 * 2 + M2C_CARRY;
            s32 r7_3 = var_r7 * 2 + M2C_CARRY;
            s32 diff = r7_3 - var_r5;
            if (diff >= 0) {
                var_r7 = diff;
                var_r3 = r3_4;
            } else {
                var_r7 = r7_3;
                var_r3 = r3_4 + 1;
            }
        } while (--temp_r9_3 != 0);
        if ((temp_r9 ^ temp_r10) != 0) {
            return -var_r3;
        }
        return var_r3;
    }
    return 0;
}

u64 __mod2u(u64 dividend, u64 divisor) { return dividend % divisor; }

s64 __mod2i(s64 a, s64 b) {
    return a % b;
}

typedef struct { u32 hi; u32 lo; } UL64;

s32 fn_8022CB08(s32 arg0, u32 arg1, s32 arg2) { u32 high = (u32)arg0 << arg2; high |= arg1 >> (32-arg2); high |= arg1 << (arg2-32); return high; }

u32 fn_8022CB2C(u32 hi, u32 lo, s32 s) {
    return (lo >> s) | (hi << (0x20 - s)) | (hi >> (s - 0x20));
}

u64 fn_8022CB50(s32 hi,u32 lo,s32 s) { s32 right; u32 low=lo>>s; low|=(u32)hi<<(32-s); right=s-32; { s32 extra=hi>>right; if(s>32) low|=extra; } return ((u64)(u32)(hi>>s)<<32)|low; }

f32 fn_8022CB78(s32 arg0, u32 arg1) {
    s32 r5;
    u32 r4_2;
    s32 r7_2;
    u32 r7_3;
    u32 r3_2;
    u32 r6_2;
    s32 temp_r7;
    s32 r7_4;
    s32 temp_r8;
    u32 r10;
    u32 r5_2;
    s32 r9;
    s32 temp_r11;
    s32 temp_r12;
    u32 r3_3;

    r5 = arg0 & 0x80000000;
    if (r5 != 0) {
        arg1 = -arg1;
        arg0 = ~arg0;
    }
    if ((arg0 | arg1) != 0) {
        temp_r7 = CLZ(arg0);
        r7_2 = temp_r7 + (((s32) ((temp_r7 << 0x1A) & 0xF8000000) >> 0x1F) & CLZ(arg1));
        r3_2 = (arg0 << r7_2) | (arg1 >> (0x20 - r7_2)) | (arg1 << (r7_2 - 0x20));
        r4_2 = arg1 << r7_2;
        r7_3 = r4_2 & 0x7FF;
        r6_2 = ((0 - r7_2) + 0x43E);
        if ((r7_3 >= 0x400) && ((r7_3 > 0x400) || (r4_2 & 0x800))) {
            r4_2 += 0x800;
            r3_2 += 1;
            r6_2 += 1;
        }
        r5_2 = (((r4_2 << 0x15) | (r4_2 >> 0xBU)) & ~0xFFE00000) | (r3_2 << 0x15);
        r7_4 = r5 | ((r6_2 << 0x14) | ((r3_2 >> 0xBU) & 0xFFFFF));
    } else {
        r5_2 = arg1;
        r7_4 = arg0;
    }
    return (f32) M2C_BITWISE(f64, r7_4);
}

s64 fn_8022CC2C(f64 value) { return (s64)value; }

typedef struct {
    u32* vtable;
    u32* data1;
    u32* data2;
} SomeStruct;

