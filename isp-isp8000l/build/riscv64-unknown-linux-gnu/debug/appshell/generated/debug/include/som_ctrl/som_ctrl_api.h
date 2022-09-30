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
 * @file som_ctrl_api.h
 *
 * @brief
 *   Definition of som ctrl API.
 *
 *****************************************************************************/
/**
 * @page som_ctrl_page SOM Ctrl
 * The Snapshot Output Module captures image buffers handed in on disk.
 *
 * For a detailed list of functions and implementation detail refer to:
 * - @ref som_ctrl_api
 * - @ref som_ctrl_common
 * - @ref som_ctrl
 *
 * @defgroup som_ctrl_api SOM Ctrl API
 * @{
 *
 */

#ifndef __SOM_CTRL_API_H__
#define __SOM_CTRL_API_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <ebase/types.h>
#include <common/return_codes.h>
#include <common/cea_861.h>

#include <bufferpool/media_buffer_queue_ex.h>

#include <hal/hal_api.h>

#include "som_ctrl_common.h"

typedef struct somCtrlConfig_s
{
    uint32_t                MaxPendingCommands; //!< Number of commands that can be queued and thus be pending at a time.
    uint32_t                MaxBuffers;
    MediaBufQueueEx_t       *pInputQueue;       //!< Reference to input queue to connect to.
    somCtrlCompletionCb_t   somCbCompletion;    //!< Callback function for command completion.
    void                    *pUserContext;      //!< User context passed on to completion callback.
    HalHandle_t             HalHandle;          //!< HAL session to use for HW access

    somCtrlHandle_t         somCtrlHandle;      //!< Handle to created som control context, set by @ref somCtrlInit if successfull, undefined otherwise.
} somCtrlConfig_t;

extern RESULT somCtrlInit
(
    somCtrlConfig_t *pConfig            //!< Reference to configuration structure.
);

extern RESULT somCtrlShutDown
(
    somCtrlHandle_t somCtrlHandle       //!< Handle to som control context as returned by @ref somCtrlInit.
);

extern RESULT somCtrlStart
(
    somCtrlHandle_t     somCtrlHandle,  //!< Handle to som control context as returned by @ref somCtrlInit.
    somCtrlCmdParams_t  *pParams        //!< Reference to the params structure for this command. @note: The referenced data is expected to be valid until the command is completed!
);

extern RESULT somCtrlStop
(
    somCtrlHandle_t somCtrlHandle       //!< Handle to som control context as returned by @ref somCtrlInit.
);

extern RESULT  somCtrlStoreBuffer
(
    somCtrlHandle_t         somCtrlHandle,
    MediaBuffer_t           *pBuffer
);

/* @} som_ctrl_api */

#ifdef __cplusplus
}
#endif

#endif /* __SOM_CTRL_API_H__ */
