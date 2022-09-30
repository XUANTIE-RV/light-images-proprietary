/******************************************************************************\
|* Copyright 2010, Dream Chip Technologies GmbH. used with permission by      *|
|* VeriSilicon.                                                               *|
|* Copyright (c) <2020> by VeriSilicon Holdings Co., Ltd. ("VeriSilicon")     *|
|* All Rights Reserved.                                                       *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of VeriSilicon.  This is proprietary information owned or licensed by      *|
|* VeriSilicon.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of VeriSilicon.                                         *|
|*                                                                            *|
\******************************************************************************/

/* VeriSilicon 2020 */

/**
 *   @file dct_assert.h
 *
 *  This file defines the API for the assertion facility of the embedded lib.
 *
 *****************************************************************************/
/*****************************************************************************/
/**
 * @defgroup module_assert Assert macros
 *
 * @brief The assertion system used by Dream Chip.
 *
 * Example use of the assert system:
 *
 *
 * - In your source file just use the macro
 *
 * @code
 * void foo( uint8_t* pData, size_t size)
 * {
 *     DCT_ASSERT(pData != NULL);
 *     DCT_ASSERT(size > 0);
 * }
 * @endcode
 *
 * @{
 *
 *****************************************************************************/
#ifndef ASSERT_H_
#define ASSERT_H_
#include <cam_device/cam_dct_assert.h>

/**
 * @brief   The type of the assert handler. @see assert_handler
 *
 *****************************************************************************/
typedef void (*ASSERT_HANDLER)(void) __attribute__((noreturn));


/**
 *          The assert handler is a function that is called in case an
 *          assertion failed. If no handler is registered, which is the
 *          default, exit() is called.
 *
 *****************************************************************************/
extern ASSERT_HANDLER   assert_handler;

#if defined(ENABLE_ASSERT) || !defined(NDEBUG)
    /**
     *              Dump information on stderr and exit.
     *
     *  @param      file  Filename where assertion occured.
     *  @param      line  Linenumber where assertion occured.
     *
     *****************************************************************************/
#ifdef __cplusplus
     extern "C"
#endif
    void exit_(const char *file, int line) __attribute__((noreturn));

    /**
     *              The assert macro.
     *
     *  @param      exp Expression which assumed to be true.
     *
     *****************************************************************************/
    #define DCT_ASSERT(exp) do { if (!(exp)){ static CHAR filename[] = __FILE__; exit_(&filename[0], __LINE__);}}while(0)
#else
    #define DCT_ASSERT(exp)\
    do {\
        if ((exp)) {\
        }\
    } while(0)
#endif

/* @} module_tracer*/

#endif /*ASSERT_H_*/
