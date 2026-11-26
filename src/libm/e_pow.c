#include "common.h"

#pragma push
#pragma optimization_level 4
double fn_802360C4(double x, double y)
{

    extern double fn_80238A9C(double);
    extern double fn_80238378(double, int);
    extern int errno;
    extern float lbl_80367068[];

    static const double bp[2] = {
        1.0, 1.5
    };
    static const double dp_h[2] = {
        0.0, 5.84962487220764160156e-01
    };
    static const double dp_l[2] = {
        0.0, 1.35003920212974897128e-08
    };

    const double zero = 0.0;
    const double one = 1.0;
    const double two = 2.0;
    const double two53 = 9007199254740992.0;
    const double huge = 1.0e300;
    const double tiny = 1.0e-300;

    const double L1 = 5.99999999999994648725e-01;
    const double L2 = 4.28571428578550184252e-01;
    const double L3 = 3.33333329818377432918e-01;
    const double L4 = 2.72728123808534006489e-01;
    const double L5 = 2.30660745775561754067e-01;
    const double L6 = 2.06975017800338417784e-01;

    const double P1 = 1.66666666666666019037e-01;
    const double P2 = -2.77777777770155933842e-03;
    const double P3 = 6.61375632143793436117e-05;
    const double P4 = -1.65339022054652515390e-06;
    const double P5 = 4.13813679705723846039e-08;

    const double lg2 = 6.93147180559945286227e-01;
    const double lg2_h = 6.93147182464599609375e-01;
    const double lg2_l = -1.90465429995776804525e-09;
    const double ovt = 8.0085662595372944372e-17;

    const double cp = 9.61796693925975554329e-01;
    const double cp_h = 9.61796700954437255859e-01;
    const double cp_l = -7.02846165095275826516e-09;

    const double ivln2 = 1.44269504088896338700e+00;
    const double ivln2_h = 1.44269502162933349609e+00;
    const double ivln2_l = 1.92596299112661746887e-08;

    double z, ax, z_h, z_l, p_h, p_l;
    double y1, t1, t2, r, s, t, u, v, w;
    double ss, s2, s_h, s_l, t_h, t_l;

    int i, j, k, yisint, n;
    int sign;
    int hx, hy, ix, iy;
    unsigned int lx, ly;

    hy = ((int *)&y)[0];
    ly = ((unsigned int *)&y)[1];
    hx = ((int *)&x)[0];
    lx = ((unsigned int *)&x)[1];

    ix = hx & 0x7fffffff;
    iy = hy & 0x7fffffff;

    if ((iy | ly) == 0)
        return one;

    if (ix > 0x7ff00000 ||
        (ix == 0x7ff00000 && lx != 0) ||
        iy > 0x7ff00000 ||
        (iy == 0x7ff00000 && ly != 0))
        return x + y;

    yisint = 0;

    if (hx < 0) {
        if (iy >= 0x43400000) {
            yisint = 2;
        } else if (iy >= 0x3ff00000) {
            k = (iy >> 20) - 0x3ff;

            if (k > 20) {
                j = ly >> (52 - k);
                if ((unsigned int)(j << (52 - k)) == ly)
                    yisint = 2 - (j & 1);
            } else if (ly == 0) {
                j = iy >> (20 - k);
                if ((j << (20 - k)) == iy)
                    yisint = 2 - (j & 1);
            }
        }
    }

    if (ly == 0) {
        if (iy == 0x7ff00000) {
            if (((ix - 0x3ff00000) | lx) == 0)
                return y - y;
            else if (ix >= 0x3ff00000)
                return hy >= 0 ? y : zero;
            else
                return hy < 0 ? -y : zero;
        }

        if (iy == 0x3ff00000) {
            if (hy < 0)
                return one / x;
            return x;
        }

        if (hy == 0x40000000)
            return x * x;

        if (hy == 0x3fe00000 && hx >= 0)
            return fn_80238A9C(x);
    }

    ax = __fabs(x);

    if (lx == 0) {
        if (ix == 0x7ff00000 ||
            ix == 0 ||
            ix == 0x3ff00000) {
            z = ax;

            if (hy < 0)
                z = one / z;

            if (hx < 0) {
                if (((ix - 0x3ff00000) | yisint) == 0) {
                    z = (z - z) / (z - z);
                } else if (yisint == 1) {
                    z = -z;
                }
            }
            return z;
        }
    }

    sign = (hx >> 31) + 1;

    if ((sign | yisint) == 0) {
        errno = 33;
        return lbl_80367068[0];
    }


    if (iy > 0x41e00000) {
        if (iy > 0x43f00000) {
            if (ix <= 0x3fefffff)
                return hy < 0 ? huge * huge : tiny * tiny;

            if (ix >= 0x3ff00000)
                return hy > 0 ? huge * huge : tiny * tiny;
        }

        if (ix < 0x3fefffff)
            return hy < 0 ? huge * huge : tiny * tiny;

        if (ix > 0x3ff00000)
            return hy > 0 ? huge * huge : tiny * tiny;

        t = x - one;
        w = (t * t) *
            (0.5 - t * (0.3333333333333333333333 - t * 0.25));

        u = ivln2_h * t;
        v = t * ivln2_l - w * ivln2;

        t1 = u + v;
        ((unsigned int *)&t1)[1] = 0;

        t2 = v - (t1 - u);
    } else {
        n = 0;

        if (ix < 0x00100000) {
            ax *= two53;
            n -= 53;
            ix = ((int *)&ax)[0];
        }

        n += (ix >> 20) - 0x3ff;
        j = ix & 0x000fffff;
        ix = j | 0x3ff00000;

        if (j <= 0x3988E) {
            k = 0;
        } else if (j < 0xBB67A) {
            k = 1;
        } else {
            k = 0;
            n++;
            ix -= 0x00100000;
        }

        ((unsigned int *)&ax)[0] = ix;

        u = ax - bp[k];
        v = one / (ax + bp[k]);
        ss = u * v;

        s_h = ss;
        ((unsigned int *)&s_h)[1] = 0;

        t_h = zero;
        ((unsigned int *)&t_h)[0] = ((ix >> 1) | 0x20000000) +
                    0x00080000 + (k << 18);

        t_l = ax - (t_h - bp[k]);
        s_l = v * ((u - s_h * t_h) - s_h * t_l);

        s2 = ss * ss;

        r = s2 * s2 *
            (L1 + s2 *
            (L2 + s2 *
            (L3 + s2 *
            (L4 + s2 *
            (L5 + s2 * L6)))));

        r += s_l * (s_h + ss);

        s2 = s_h * s_h;
        t_h = 3.0 + s2 + r;

        ((unsigned int *)&t_h)[1] = 0;

        t_l = r - ((t_h - 3.0) - s2);

        u = s_h * t_h;
        v = s_l * t_h + t_l * ss;

        p_h = u + v;
        ((unsigned int *)&p_h)[1] = 0;

        p_l = v - (p_h - u);

        z_h = cp_h * p_h;
        z_l = cp_l * p_h + p_l * cp + dp_l[k];

        t = (double)n;
        t1 = ((z_h + z_l) + dp_h[k]) + t;

        ((unsigned int *)&t1)[1] = 0;

        t2 = z_l - (((t1 - t) - dp_h[k]) - z_h);
    }

    s = one;

    if ((sign | (yisint - 1)) == 0)
        s = -one;

    y1 = y;
    ((unsigned int *)&y1)[1] = 0;

    p_l = (y - y1) * t1 + y * t2;
    p_h = y1 * t1;

    z = p_l + p_h;
    j = ((int *)&z)[0];
    i = ((int *)&z)[1];

    if (j >= 0x40900000) {
        if (((j - 0x40900000) | i) != 0)
            return s * huge * huge;

        if (p_l + ovt > z - p_h)
            return s * huge * huge;
    } else if ((j & 0x7fffffff) >= 0x4090cc00) {
        if (((unsigned int)j - 0xc090cc00U) | (unsigned int)i)
            return s * tiny * tiny;

        if (p_l <= z - p_h)
            return s * tiny * tiny;
    }

    i = j & 0x7fffffff;
    k = (i >> 20) - 0x3ff;
    n = 0;

    if (i > 0x3fe00000) {
        n = j + (0x00100000 >> (k + 1));
        k = ((n & 0x7fffffff) >> 20) - 0x3ff;

        t = zero;
        ((unsigned int *)&t)[0] = n & ~(0x000fffff >> k);

        n = ((n & 0x000fffff) | 0x00100000) >> (20 - k);

        if (j < 0)
            n = -n;

        p_h -= t;
    }

    t = p_l + p_h;
    ((unsigned int *)&t)[1] = 0;

    u = t * lg2_h;
    v = (p_l - (t - p_h)) * lg2 + t * lg2_l;

    z = u + v;
    w = v - (z - u);

    t = z * z;

    t1 = z - t *
        (P1 + t *
        (P2 + t *
        (P3 + t *
        (P4 + t * P5))));

    r = (z * t1) / (t1 - two) - (w + z * w);
    z = one - (r - z);

    j = ((int *)&z)[0];
    j += n << 20;

    if ((j >> 20) <= 0) {
        z = fn_80238378(z, n);
    } else {
        ((int *)&z)[0] += n << 20;
    }

    return s * z;
}
#pragma pop
