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
 * @file mim_ctrl_api.h
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
#ifndef  __MIM_CTRL_API_H__
#define __MIM_CTRL_API_H__

#include <ebase/types.h>
#include <common/return_codes.h>

#include <bufferpool/media_buffer.h>
#include <bufferpool/media_buffer_queue_ex.h>

#include <cameric_drv/cameric_drv_api.h>

#include "mim_ctrl_common.h"

/**
 * @brief
 *
 * @note
 *
 */
typedef struct MimCtrlConfig_s
{
    uint32_t                MaxPendingCommands;     /**< Number of commands that can be queued and thus be pending at a time. */
    uint32_t                MaxAvailableBuffers;    /**< Number of max available buffers in bufferpool */

    MediaBufQueueEx_t       *pInputQueue;           /**< Reference to output queue to connect to. */
    MimCtrlCompletionCb_t   mimCbCompletion;        /**< Callback function for command completion. */
    void                    *pUserContext;          /**< User context passed on to completion callback. */

	CamerIcDrvHandle_t      hCamerIc;               /**< CamerIc Driver handle */

    MimCtrlContextHandle_t  hMimContext;            /**< Handle to vom control context, set by @ref vomCtrlInit if successfull, undefined otherwise. */
} MimCtrlConfig_t;



/*****************************************************************************/
/**
 * @brief   Initialize the MIM-Control
 *
 * This functions initializes the Memory-Input-Modul .
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
RESULT MimCtrlInit
(
    MimCtrlConfig_t *pConfig
);



/*****************************************************************************/
/**
 * @brief   Shutdown the MIM-Control
 *
 * This functions initializes the Memory-Input-Modul .
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
RESULT MimCtrlShutDown
(
	MimCtrlContextHandle_t hMimContext
);



/*****************************************************************************/
/**
 * @brief   Start the MIM-Control
 *
 * This functions initializes the Memory-Input-Modul .
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
RESULT MimCtrlStart
(
	MimCtrlContextHandle_t hMimContext
);



/*****************************************************************************/
/**
 * @brief   Stop MIM-Control
 *
 * This functions initializes the Memory-Input-Modul .
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
RESULT MimCtrlStop
(
	MimCtrlContextHandle_t hMimContext
);



RESULT MimCtrlLoadPicture
(
    MimCtrlContextHandle_t  hMimContext,
    PicBufMetaData_t        *pPicBuffer
);



/* @} module_name*/

#endif /* __MIM_CTRL_API_H__ */
