/* fe448_448.h
 *
 * Copyright (C) 2006-2020 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLF_CRYPT_FE_448_H
#define WOLF_CRYPT_FE_448_H

#include <wolfssl/wolfcrypt/settings.h>

#if defined(HAVE_CURVE448) || defined(HAVE_ED448)

#ifndef WOLFSSL_LINUXKM
#include <stdint.h>
#endif

#include <wolfssl/wolfcrypt/types.h>

#if defined(HAVE___UINT128_T) && !defined(NO_CURVED448_128BIT)
    #define CURVED448_128BIT
#endif

#ifdef __cplusplus
    extern "C" {
#endif

/* default to be faster but take more memory */
#if !defined(CURVE448_SMALL) && !defined(ED448_SMALL)

#if defined(CURVED448_128BIT)
    typedef int64_t fe448;
    #ifndef WOLFSSL_UINT128_T_DEFINED
        #ifdef __SIZEOF_INT128__
            typedef __uint128_t uint128_t;
            typedef __int128_t int128_t;
        #else
            typedef unsigned long uint128_t __attribute__ ((mode(TI)));
            typedef long int128_t __attribute__ ((mode(TI)));
        #endif
        #define WOLFSSL_UINT128_T_DEFINED
    #endif
#else
    typedef int32_t fe448;
#endif

WOLFSSL_LOCAL void fe448_init(void);
WOLFSSL_LOCAL int  curve448(byte* r, const byte* n, const byte* a);

#if !defined(CURVED448_128BIT)
WOLFSSL_LOCAL void fe448_reduce(fe448*);
#else
#define fe448_reduce(a)
#endif
WOLFSSL_LOCAL void fe448_neg(fe448*,const fe448*);
WOLFSSL_LOCAL void fe448_add(fe448*, const fe448*, const fe448*);
WOLFSSL_LOCAL void fe448_sub(fe448*, const fe448*, const fe448*);
WOLFSSL_LOCAL void fe448_mul(fe448*,const fe448*,const fe448*);
WOLFSSL_LOCAL void fe448_sqr(fe448*, const fe448*);
WOLFSSL_LOCAL void fe448_mul39081(fe448*, const fe448*);
WOLFSSL_LOCAL void fe448_invert(fe448*, const fe448*);

WOLFSSL_LOCAL void fe448_0(fe448*);
WOLFSSL_LOCAL void fe448_1(fe448*);
WOLFSSL_LOCAL void fe448_copy(fe448*, const fe448*);
WOLFSSL_LOCAL int  fe448_isnonzero(const fe448*);
WOLFSSL_LOCAL int  fe448_isnegative(const fe448*);

WOLFSSL_LOCAL void fe448_from_bytes(fe448*,const unsigned char *);
WOLFSSL_LOCAL void fe448_to_bytes(unsigned char *, const fe448*);

WOLFSSL_LOCAL void fe448_cmov(fe448*,const fe448*, int);
WOLFSSL_LOCAL void fe448_pow_2_446_222_1(fe448*,const fe448*);

#else

WOLFSSL_LOCAL void fe448_init(void);
WOLFSSL_LOCAL int  curve448(byte* r, const byte* n, const byte* a);

#define fe448_reduce(a)
WOLFSSL_LOCAL void fe448_neg(uint8_t*,const uint8_t*);
WOLFSSL_LOCAL void fe448_add(uint8_t*, const uint8_t*, const uint8_t*);
WOLFSSL_LOCAL void fe448_sub(uint8_t*, const uint8_t*, const uint8_t*);
WOLFSSL_LOCAL void fe448_mul(uint8_t*,const uint8_t*,const uint8_t*);
WOLFSSL_LOCAL void fe448_sqr(uint8_t*, const uint8_t*);
WOLFSSL_LOCAL void fe448_mul39081(uint8_t*, const uint8_t*);
WOLFSSL_LOCAL void fe448_invert(uint8_t*, const uint8_t*);

WOLFSSL_LOCAL void fe448_copy(uint8_t*, const uint8_t*);
WOLFSSL_LOCAL int  fe448_isnonzero(const uint8_t*);

WOLFSSL_LOCAL void fe448_norm(byte *a);

WOLFSSL_LOCAL void fe448_cmov(uint8_t*,const uint8_t*, int);
WOLFSSL_LOCAL void fe448_pow_2_446_222_1(uint8_t*,const uint8_t*);

#endif /* !CURVE448_SMALL || !ED448_SMALL */

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* HAVE_CURVE448 || HAVE_ED448 */

#endif /* WOLF_CRYPT_FE_448_H */
