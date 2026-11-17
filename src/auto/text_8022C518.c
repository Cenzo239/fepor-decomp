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

s64 __div2i(s64 a, s64 b) {
    u64 n = a < 0 ? -(u64)a : (u64)a;
    u64 d = b < 0 ? -(u64)b : (u64)b;
    u64 q = 0, r = 0;
    s32 i;
    for (i = 64; i != 0; --i) {
        r = (r << 1) | (n >> 63);
        n <<= 1;
        q <<= 1;
        if (r >= d) { r -= d; q |= 1; }
    }
    return (a < 0) != (b < 0) ? -q : q;
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

f32 fn_8022CB78(s32 hi, u32 lo) {
    u32 sign;
    u32 lz;
    u32 t;
    s32 exp;
    u32 bits_hi;
    u32 bits_lo;
    union { f64 d; u32 w[2]; } u;

    sign = (u32)hi & 0x80000000u;
    if (sign != 0) {
        u64 z = 0ULL - (((u64)(u32)hi << 32) | lo);
        hi = (s32)(z >> 32);
        lo = (u32)z;
    }

    exp = 0;
    if ((hi | lo) == 0) {
        bits_hi = sign;
        bits_lo = 0;
        goto done;
    }

    {
        u32 lzHi = __cntlzw((u32)hi);
        u32 lzLo = __cntlzw(lo);
        t = (lzHi << 26) & 0xF8000000u;
        lz = lzHi + (((s32)t >> 31) & lzLo);
    }

    {
        u32 r8 = 32 - lz;
        s32 r9 = (s32)lz - 32;
        u32 r10;
        hi = ((u32)hi << lz);
        r10 = lo >> r8;
        hi = hi | r10;
        r10 = lo << r9;
        hi = hi | r10;
        lo = lo << lz;
        exp = exp - (s32)lz;
    }

    exp += 0x43E;

    t = lo & 0x7FF;
    if (t >= 0x400) {
        if (t > 0x400 || (lo & 0x800) != 0) {
            lo += 0x800;
            if (lo < 0x800) {
                hi += 1;
                if (hi == 0)
                    exp += 1;
            }
        }
    }

    bits_lo = (lo >> 11) | ((u32)hi << 21);
    bits_hi = ((u32)exp << 20) | (((u32)hi >> 11) & 0xFFFFF);
    bits_hi |= sign;

done:
    u.w[0] = bits_hi;
    u.w[1] = bits_lo;
    return (f32)u.d;
}

s64 fn_8022CC2C(f64 value) { return (s64)value; }

typedef struct {
    u32* vtable;
    u32* data1;
    u32* data2;
} SomeStruct;

