#include <stdint.h>
#include "idiv.h"

#define _IDIV_UU(_INT_WIDTH_)                                   \
    uint ## _INT_WIDTH_ ## _t idiv ## _INT_WIDTH_ ## _uu(       \
        uint ## _INT_WIDTH_ ## _t n,                            \
        uint ## _INT_WIDTH_ ## _t d,                            \
        uint ## _INT_WIDTH_ ## _t *rp)                          \
    {                                                           \
        uint ## _INT_WIDTH_ ## _t q = 0, r = 0;                 \
        int i;                                                  \
        if (d == 0) {                                           \
            if (rp) *rp = 0;                                    \
            return 0;                                           \
        }                                                       \
        for (i = _INT_WIDTH_-1; i >= 0; i --) {                 \
            r <<= 1;                                            \
            q <<= 1;                                            \
            r |= (n & (1ull << (_INT_WIDTH_-1))) ? 1 : 0;       \
            if (r >= d) {                                       \
                r -= d;                                         \
                q |= 1;                                         \
            }                                                   \
            n <<= 1;                                            \
        }                                                       \
        if (rp) *rp = r;                                        \
        return q;                                               \
    }


#define _IDIV_II(_INT_WIDTH_)                                   \
    int ## _INT_WIDTH_ ## _t idiv ## _INT_WIDTH_ ## _ii(        \
        int ## _INT_WIDTH_ ## _t n,                             \
        int ## _INT_WIDTH_ ## _t d,                             \
        int ## _INT_WIDTH_ ## _t *rp)                           \
    {                                                           \
        uint ## _INT_WIDTH_ ## _t qu = 0, ru = 0, nu, du;       \
        int qneg = (n >= 0 && d < 0) | (n < 0 && d >= 0);       \
        int rneg = (n < 0);                                     \
        nu = (n < 0) ? -n : n;                                  \
        du = (d < 0) ? -d : d;                                  \
        qu = idiv ## _INT_WIDTH_ ## _uu(nu, du, &ru);           \
        if (rp) *rp = rneg ? -ru : ru;                          \
        return qneg ? -qu : qu;                                 \
    }

#define _IDIV_UI(_INT_WIDTH_)                                   \
    int ## _INT_WIDTH_ ## _t idiv ## _INT_WIDTH_ ## _ui(        \
        uint ## _INT_WIDTH_ ## _t n,                            \
        int ## _INT_WIDTH_ ## _t d,                             \
        uint ## _INT_WIDTH_ ## _t *rp)                          \
    {                                                           \
        uint ## _INT_WIDTH_ ## _t qu = 0, ru = 0, du;           \
        int qneg = (d < 0);                                     \
        du = (d < 0) ? -d : d;                                  \
        qu = idiv ## _INT_WIDTH_ ## _uu(n, du, &ru);            \
        if (rp) *rp = ru;                                       \
        return qneg ? -qu : qu;                                 \
    }

#define _IDIV_IU(_INT_WIDTH_)                                   \
    int ## _INT_WIDTH_ ## _t idiv ## _INT_WIDTH_ ## _iu(        \
        int ## _INT_WIDTH_ ## _t n,                             \
        uint ## _INT_WIDTH_ ## _t d,                            \
        int  ## _INT_WIDTH_ ## _t *rp)                          \
    {                                                           \
        uint ## _INT_WIDTH_ ## _t qu = 0, ru = 0, nu;           \
        int neg = (n < 0);                                      \
        nu = (n < 0) ? -n : n;                                  \
        qu = idiv ## _INT_WIDTH_ ## _uu(nu, d, &ru);            \
        if (rp) *rp = neg ? -ru : ru;                           \
        return neg ? -qu : qu;                                  \
    }

_IDIV_UU(32)
_IDIV_II(32)
_IDIV_UI(32)
_IDIV_IU(32)

_IDIV_UU(64)
_IDIV_II(64)
_IDIV_UI(64)
_IDIV_IU(64)
