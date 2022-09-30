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
 * @file vom_ctrl_api.h
 *
 * @brief
 *   Definition of vom ctrl API.
 *
 *****************************************************************************/
/**
 * @page vom_ctrl_page VOM Ctrl
 * The Video Output Module displays image buffers handed in via QuadMVDU_FX on
 * a connected HDMI display device.
 *
 * For a detailed list of functions and implementation detail refer to:
 * - @ref vom_ctrl_api
 * - @ref vom_ctrl_common
 * - @ref vom_ctrl
 * - @ref vom_ctrl_mvdu
 *
 * @defgroup vom_ctrl_api VOM Ctrl API
 * @{
 *
 */

#ifndef __VOM_CTRL_API_H__
#define __VOM_CTRL_API_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <ebase/types.h>
#include <common/return_codes.h>
#include <common/cea_861.h>
#include <common/hdmi_3d.h>

#include <bufferpool/media_buffer_queue_ex.h>

#include <hal/hal_api.h>

#include "vom_ctrl_common.h"

typedef struct vomCtrlConfig_s
{
    Cea861VideoFormat_t     VideoFormat;        //!< Reference to CEA style video format to be used for display
    bool_t                  Enable3D;           //!< Enable 3D display mode.
    Hdmi3DVideoFormat_t     VideoFormat3D;      //!< The HDMI 3D display mode to use; undefined if 3D not enabled.
    uint32_t                MaxPendingCommands; //!< Number of commands that can be queued and thus be pending at a time.
    uint32_t                MaxBuffers;
    MediaBufQueueEx_t       *pInputQueue;       //!< Reference to input queue to connect to.
    vomCtrlCompletionCb_t   vomCbCompletion;    //!< Callback function for command completion.
    void                    *pUserContext;      //!< User context passed on to completion callback.
    HalHandle_t             HalHandle;          //!< HAL session to use for HW access

    vomCtrlHandle_t         VomCtrlHandle;      //!< Handle to created vom control context, set by @ref vomCtrlInit if successfull, undefined otherwise.
} vomCtrlConfig_t;

extern RESULT vomCtrlInit
(
    vomCtrlConfig_t  *pConfig           //!< Reference to configuration structure.
);

extern RESULT vomCtrlShutDown
(
    vomCtrlHandle_t  VomCtrlHandle      //!< Handle to vom control context as returned by @ref vomCtrlInit.
);

extern RESULT vomCtrlStart
(
    vomCtrlHandle_t  VomCtrlHandle      //!< Handle to vom control context as returned by @ref vomCtrlInit.
);

extern RESULT vomCtrlStop
(
    vomCtrlHandle_t  VomCtrlHandle      //!< Handle to vom control context as returned by @ref vomCtrlInit.
);

extern RESULT  vomCtrlShowBuffer
(
	vomCtrlHandle_t  VomCtrlHandle,
    MediaBuffer_t    *pBuffer
);

/* @} vom_ctrl_api */

#ifdef __cplusplus
}
#endif

#endif /* __VOM_CTRL_API_H__ */
