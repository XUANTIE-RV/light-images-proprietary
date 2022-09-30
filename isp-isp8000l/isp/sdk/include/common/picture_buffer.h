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
 * @file    picture_buffer.h
 *
 * @brief   Defines picture buffer meta data structure including its components
 *          and helper functions around that structure.
 *
 *****************************************************************************/
/**
 * @page module_name_page Module Name
 * Describe here what this module does.
 *
 * For a detailed list of functions and implementation detail refer to:
 * - @ref module_name
 *
 * @defgroup picture_buffer Picture buffer descriptor
 * @{
 *
 */
#ifndef __PICTURE_BUFFER_H__
#define __PICTURE_BUFFER_H__

#include <ebase/types.h>
#include <scmi/scmi_types.h>
#include <common/return_codes.h>
#include <cam_device/cam_device_buf_defs.h>

#if defined (__cplusplus)
extern "C" {
#endif

/* input and output buffer macro define, default disable. */
#define ENABLE_BUFFER_DUMP 0



/*****************************************************************************/
/**
 *          PicBufIsConfigValid()
 *
 * @brief   Check the given picture buffer meta data structure for valid
 *          type & layout combination.
 *
 * @param   Reference to picture buffer meta data structure.
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS     type & layout combination is valid
 * @retval  RET_NOTSUPP     type & layout combination is invalid
 * @retval  RET_OUTOFRANGE  invalid type and/or layout
 *
 *****************************************************************************/
extern RESULT PicBufIsConfigValid
(
    PicBufMetaData_t *pPicBufMetaData
);

extern RESULT PicBufDump
(
    PicBufMetaData_t *pPicBuffer,
    const uint8_t *logical,
    bool_t inputSource
);

/* @} picture_buffer */

#if defined (__cplusplus)
}
#endif

#endif /* __PICTURE_BUFFER_H__ */
