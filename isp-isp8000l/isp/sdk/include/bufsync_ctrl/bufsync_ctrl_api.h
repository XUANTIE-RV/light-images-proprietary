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
 * @file bufsync_ctrl_api.h
 *
 * @brief
 *   ADD_DESCRIPTION_HERE
 *
 *****************************************************************************/
/**
 * @page module_name_page Module Name
 * Describe here what this module does.
 *
 * For a detailed list of functions and implementation detail refer to:
 * - @ref module_name
 *
 * @defgroup module_name Module Name
 * @{
 *
 */
#ifndef __BUFSYNC_CTRL_API_H__
#define __BUFSYNC_CTRL_API_H__

#include <ebase/types.h>
#include <oslayer/oslayer.h>
#include <common/return_codes.h>

#include <bufferpool/media_buffer.h>
#include <bufferpool/media_buffer_queue_ex.h>

#include "bufsync_ctrl_common.h"

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * @brief   Configuration structure of the bufsync-ctrl
 *
 * @note
 *
 */
typedef struct BufSyncCtrlConfig_s
{
    uint32_t                    MaxPendingCommands;     /**< Number of commands that can be queued and thus be pending at a time. */

    osQueue                     *pPicBufQueue1;         /**< Reference to output queue to connect to. */
    osQueue                     *pPicBufQueue2;         /**< Reference to output queue to connect to. */

    BufSyncCtrlCompletionCb_t   bufsyncCbCompletion;    /**< Callback function for command completion. */
    void                        *pUserContext;          /**< User context passed on to completion callback. */

    BufSyncCtrlHandle_t         hBufSyncCtrl;           /**< Handle to bufsync control context, set by @ref BufSyncCtrlInit if successfull, undefined otherwise. */
} BufSyncCtrlConfig_t;



/*****************************************************************************/
/**
 * @brief   Initialize the BufSync-Control
 *
 * This functions initializes the Buffer Synchronisation Module .
 *
 * Some detailed description goes here ...
 *
 * @param   param1      Describe the parameter 1.
 * @param   param2      Describe the parameter 2
 *
 * @return              Return the result of the function call.
 * @retval              RET_VAL1
 * @retval              RET_VAL2
 *
 *****************************************************************************/
RESULT BufSyncCtrlInit
(
    BufSyncCtrlConfig_t *pConfig
);



/*****************************************************************************/
/**
 * @brief   Shutdown the BufSync-Control
 *
 * This functions releases and shutdowns the Buffer Synchronisation Module.
 *
 * Some detailed description goes here ...
 *
 * @param   param1      Describe the parameter 1.
 * @param   param2      Describe the parameter 2
 *
 * @return              Return the result of the function call.
 * @retval              RET_VAL1
 * @retval              RET_VAL2
 *
 *****************************************************************************/
RESULT BufSyncCtrlShutDown
(
    BufSyncCtrlHandle_t hBufSyncCtrl
);



/*****************************************************************************/
/**
 * @brief   Start the BufSync-Control
 *
 * This functions starts the Buffer Synchronisation Module.
 *
 * Some detailed description goes here ...
 *
 * @param   param1      Describe the parameter 1.
 * @param   param2      Describe the parameter 2
 *
 * @return              Return the result of the function call.
 * @retval              RET_VAL1
 * @retval              RET_VAL2
 *
 *****************************************************************************/
RESULT BufSyncCtrlStart
(
    BufSyncCtrlHandle_t hBufSyncCtrl
);



/*****************************************************************************/
/**
 * @brief   Stop the BufSync-Control
 *
 * This functions stops the Buffer Synchronisation Module.
 *
 * Some detailed description goes here ...
 *
 * @param   param1      Describe the parameter 1.
 * @param   param2      Describe the parameter 2
 *
 * @return              Return the result of the function call.
 * @retval              RET_VAL1
 * @retval              RET_VAL2
 *
 *****************************************************************************/
RESULT BufSyncCtrlStop
(
    BufSyncCtrlHandle_t hBufSyncCtrl
);



/*****************************************************************************/
/**
 * @brief   TODO
 *
 *****************************************************************************/
RESULT  BufSyncCtrlRegisterBufferCb
(
    BufSyncCtrlHandle_t     hBufSyncCtrl,
    BufSyncCtrlBufferCb_t   fpCallback,
    void                    *pBufferCbCtx
);



/*****************************************************************************/
/**
 * @brief   TODO
 *
 *****************************************************************************/
RESULT  BufSyncCtrlDeRegisterBufferCb
(
    BufSyncCtrlHandle_t  hBufSyncCtrl
);



#ifdef __cplusplus
}
#endif


/* @} module_name*/

#endif /* __BUFSYNC_CTRL_API_H__ */

