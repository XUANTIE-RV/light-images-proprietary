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
 * @cond    cam_engine_drv
 *
 * @file    cam_engine_drv_api.h
 *
 * @brief
 *
 *   Interface function to the CamerIc Driver.
 *
 *****************************************************************************/
/**
 *
 * @defgroup cam_engine_drv_api CamEngine DRV API
 * @{
 *
 */

#ifndef __CAM_ENGINE_ISP_DRV_H__
#define __CAM_ENGINE_ISP_DRV_H__

#include <ebase/types.h>

#include <common/return_codes.h>

#ifdef __cplusplus
extern "C"
{
#endif


/*****************************************************************************/
/**
 * @brief   This function returns the CamerIc (Master) Revision ID.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   revision            reference to CamerIc Master Revision ID
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter (revision is a NULL pointer)
 *
 *****************************************************************************/
RESULT CamEngineCamerIcMasterId
(
    CamEngineHandle_t   hCamEngine,
    uint32_t            *revision
);


/*****************************************************************************/
/**
 * @brief   This function returns the CamerIc (Slave) Revision ID.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   revision            reference to CamerIc Slave Revision ID
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter (revision is a NULL pointer)
 *
 *****************************************************************************/
RESULT CamEngineCamerIcSlaveId
(
    CamEngineHandle_t   hCamEngine,
    uint32_t            *revision
);


#ifdef __cplusplus
}
#endif


/* @} cam_engine_isp_api */


#endif /* __CAM_ENGINE_ISP_DRV_H__ */

