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
 * @cond    cam_engine_cproc
 *
 * @file    cam_engine_cproc_api.h
 *
 * @brief
 *
 *   Interface description of the CamEngine Color Processing.
 *
 *****************************************************************************/
/**
 *
 * @defgroup cam_engine_cproc_api CamEngine Color Processing API
 * @{
 *
 */

#ifndef __CAM_ENGINE_C_PROC_RY_API_H__
#define __CAM_ENGINE_C_PROC_RY_API_H__

#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif

//FIXME
#include <cameric_drv/cameric_cproc_drv_ry_api.h>
#include <cam_device/cam_device_ispcore_defs_ry.h>

/*****************************************************************************/
/**
 * @brief   This function enables the color processing.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   pConfig             configuration of color processing
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineEnableCproc_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    CamEngineCprocConfig_t  *pConfig
);


/*****************************************************************************/
/**
 * @brief   This function disables the color processing.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineDisableCproc_ry
(
    CamEngineHandle_ry_t   hCamEngine
);


/*****************************************************************************/
/**
 * @brief   This function returns thecolor processing status.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   pRunning            BOOL_TRUE: running, BOOL_FALSE: stopped
 * @param   pConfig             configuration of color processing
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineCprocStatus_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    bool_t                  *pRunning,
    CamEngineCprocConfig_t  *pConfig
);


RESULT CamEngineCprocSetContrast_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    const float         contrast
);



RESULT CamEngineCprocSetBrightness_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    const int8_t        brightness
);



RESULT CamEngineCprocSetSaturation_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    float               saturation
);



RESULT CamEngineCprocSetHue_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    float               hue
);


#ifdef __cplusplus
}
#endif

/* @} cam_engine_cproc_api */

#endif /* __CAM_ENGINE_C_PROC_RY_API_H__ */

