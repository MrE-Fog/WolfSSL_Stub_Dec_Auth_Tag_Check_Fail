/* user_setting.h
 *
 * Copyright (C) 2006-2020 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef MICRIUM_USER_SETTINGS_H_
#define MICRIUM_USER_SETTINGS_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define MICRIUM

/* You can select one or all of the following tests */
#define WOLFSSL_WOLFCRYPT_TEST
#define WOLFSSL_BENCHMARK_TEST
#define WOLFSSL_CLIENT_TEST
#define WOLFSSL_SERVER_TEST

/* adjust CURRENT_UNIX_TS to seconds since Jan 01 1970. (UTC)
You can get the current time from https://www.unixtimestamp.com/
*/
#define CURRENT_UNIX_TS 1542605837

/* When using Windows simulator, you must define USE_WINDOWS_API for test.h to build */
#ifdef _WIN32
#define USE_WINDOWS_API
#endif

#define NO_FILESYSTEM
#define SIZEOF_LONG_LONG 8

/* prevents from including multiple definition of main() */
#define NO_MAIN_DRIVER
#define NO_TESTSUITE_MAIN_DRIVER

/* includes certificate test buffers via header files */
#define USE_CERT_BUFFERS_2048
/*use kB instead of mB for embedded benchmarking*/
#define BENCH_EMBEDDED

#define NO_WRITE_TEMP_FILES

#define XSNPRINTF snprintf

#define HAVE_AESGCM
#define WOLFSSL_SHA512
#define HAVE_ECC
#define HAVE_CURVE25519
#define CURVE25519_SMALL
#define HAVE_ED25519
#define ED25519_SMALL

#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif
