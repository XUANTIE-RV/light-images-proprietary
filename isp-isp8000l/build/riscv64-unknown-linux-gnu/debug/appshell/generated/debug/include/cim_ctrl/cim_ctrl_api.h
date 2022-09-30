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
 * @file cim_ctrl_api.h
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
#ifndef __CIM_CTRL_API_H__
#define __CIM_CTRL_API_H__

#include <ebase/types.h>
#include <common/return_codes.h>
#include <hal/hal_api.h>

#include <isi/isi_iss.h>
#include <isi/isi.h>

#include "cim_ctrl_common.h"



/**
 * @brief   Configuration structure of the cim-ctrl
 *
 * @note
 *
 */
typedef struct CimCtrlConfig_s
{
    uint32_t                MaxPendingCommands;     /**< Number of commands that can be queued and thus be pending at a time. */
    uint32_t                MaxAvailableBuffers;    /**< Number of max available buffers in bufferpool */

    CimCtrlCompletionCb_t   cimCbCompletion;        /**< Callback function for command completion. */
    void                    *pUserContext;          /**< User context passed on to completion callback. */

    HalHandle_t             HalHandle;

    CimCtrlContextHandle_t  hCimContext;            /**< Handle to vom control context, set by @ref vomCtrlInit if successfull, undefined otherwise. */
} CimCtrlConfig_t;



/*****************************************************************************/
/**
 *          CimCtrlInit
 *
 * @brief   This function initializes the CIM-Control
 *
 * This functions initializes the AE, AWB and AF Module
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
RESULT CimCtrlInit
(
    CimCtrlConfig_t         *pConfig
);



/*****************************************************************************/
/**
 *          CimCtrlShutDown
 *
 * @brief   This function shutdowns the CIM-Control
 *
 * This functions releases and shutdowns the Memory-Output-Modul .
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
RESULT CimCtrlShutDown
(
    CimCtrlContextHandle_t handle
);



/*****************************************************************************/
/**
 *          CimCtrlStart
 *
 * @brief   This function starts the CIM-Control
 *
 * This functions starts the Memory-Output-Modul .
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
RESULT CimCtrlStart
(
    CimCtrlContextHandle_t handle
);



/*****************************************************************************/
/**
 *          CimCtrlStop
 *
 * @brief   Initialize the CIM-Control
 *
 * This functions initializes the Memory-Output-Modul .
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
RESULT CimCtrlStop
(
    CimCtrlContextHandle_t handle
);



/*****************************************************************************/
/**
 *          CimCtrlRegisterSensorDrv
 *
 * @brief   This function makes the sensor driver available for ussage.
 *
 * This functions initializes the Memory-Output-Modul .
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
RESULT CimCtrlRegisterSensorDrv
(
    CimCtrlContextHandle_t  handle,
    IsiCamDrvConfig_t       *pIsiCamDrvConfig,
    const uint32_t          HalDevID,
    const uint8_t           I2cBusNum
);



/* @} module_name*/

#endif /* __CIM_CTRL_API_H__ */

