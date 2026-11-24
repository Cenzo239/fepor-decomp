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
    for (i = 64; i != 0; --i) {
        r = (r << 1) | (a >> 63);
        a <<= 1;
        q <<= 1;
        if (r >= b) {
            r -= b;
            q |= 1;
        }
    }
    return q;
}

s64 __div2i(s64 a, s64 b) {
    u32 sa=(u32)((u64)a>>32)&0x80000000;
    u32 sb=(u32)((u64)b>>32)&0x80000000;
    u64 n=(u64)a,d=(u64)b,r;
    s32 nl,dl,count,shift;
    u32 bit=0;
    if(sa) n=-n;
    if(sb) d=-d;
    nl=__cntlzw((u32)(n>>32)); if(!(u32)(n>>32)) nl=__cntlzw((u32)n)+32;
    dl=__cntlzw((u32)(d>>32)); if(!(u32)(d>>32)) dl=__cntlzw((u32)d)+32;
    if(nl>dl) return 0;
    shift=63-dl;
    count=(64-nl)-shift;
    if(count>=32) r=(u32)(n>>32)>>(count-32);
    else r=((u64)((u32)(n>>32)>>count)<<32)|((u32)n>>count)|((u32)(n>>32)<<(32-count));
    shift+=nl;
    if(shift>=32) n=(u64)((u32)n<<(shift-32))<<32;
    else n=((u64)(((u32)(n>>32)<<shift)|((u32)n>>(32-shift)))<<32)|((u32)n<<shift);
    do {
        u32 next=(u32)(n>>63);
        n=n+n+bit;
        r=r+r+next;
        bit=0;
        if((s64)(r-d)>=0) {r-=d;bit=1;}
    } while(--count);
    n=n+n+bit;
    if(sa^sb) n=-n;
    return n;
}

u64 __mod2u(u64 dividend, u64 divisor) { return dividend % divisor; }

s64 __mod2i(s64 a, s64 b) {
    return a % b;
}

typedef struct { u32 hi; u32 lo; } UL64;

#pragma push
asm s64 __shl2i(register s64 value, register int shift) {
    nofralloc
    subfic r8, r5, 0x20
    subic r9, r5, 0x20
    slw r3, r3, r5
    srw r10, r4, r8
    or r3, r3, r10
    slw r10, r4, r9
    or r3, r3, r10
    slw r4, r4, r5
    blr
}
#pragma pop

#pragma push
asm u64 __shr2u(register u64 value, register int shift) {
    nofralloc
    subfic r8, r5, 0x20
    subic r9, r5, 0x20
    srw r4, r4, r5
    slw r10, r3, r8
    or r4, r4, r10
    srw r10, r3, r9
    or r4, r4, r10
    srw r3, r3, r5
    blr
}
#pragma pop

#pragma push
asm s64 __shr2i(register s64 value, register int shift) {
    nofralloc
    subfic r8, r5, 0x20
    subic. r9, r5, 0x20
    srw r4, r4, r5
    slw r10, r3, r8
    or r4, r4, r10
    sraw r10, r3, r9
    ble L_8
    or r4, r4, r10
L_8:
    sraw r3, r3, r5
    blr
}
#pragma pop

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

s64 fn_8022CC2C(f64 value) {
    register s32 hi;
    register s32 lo;
    s32 exp;
    s32 sign;
    s32 sh;
    u32 r8;
    s32 r9;
    u32 r10;
    union { f64 d; s32 w[2]; } u;

    u.d = value;
    hi = u.w[0];
    lo = u.w[1];

    exp = (s32)(((u32)hi << 1) >> 21);
    if ((u32)exp < 0x3FFu) {
        return 0LL;
    }

    sign = hi;
    hi = (s32)((u32)hi & 0x000FFFFFu);
    hi = (s32)((u32)hi | 0x00100000u);
    sh = exp + (-0x433);

    if (sh < 0) {
        sh = -sh;
        r8 = 0x20 - sh;
        r9 = sh - 0x20;
        r10 = (u32)hi << r8;
        lo = (s32)(((u32)lo >> sh) | r10);
        r10 = (u32)hi >> r9;
        lo = (s32)((u32)lo | r10);
        hi = (s32)((u32)hi >> sh);
    } else if (sh > 10) {
        if ((u32)sign & 0x80000000u) {
            return (s64)0x8000000000000000ULL;
        }
        return (s64)0x7FFFFFFFFFFFFFFFLL;
    } else {
        r8 = 0x20 - sh;
        r9 = sh - 0x20;
        r10 = (u32)lo >> r8;
        hi = (s32)(((u32)hi << sh) | r10);
        r10 = (u32)lo << r9;
        hi = (s32)((u32)hi | r10);
        lo = (s32)((u32)lo << sh);
    }

    if ((u32)sign & 0x80000000u) {
        u64 v = ((u64)(u32)hi << 32) | (u32)lo;
        v = 0u - v;
        return (s64)v;
    }
    return ((s64)(u32)hi << 32) | (u32)lo;
}

typedef struct {
    u32* vtable;
    u32* data1;
    u32* data2;
} SomeStruct;

