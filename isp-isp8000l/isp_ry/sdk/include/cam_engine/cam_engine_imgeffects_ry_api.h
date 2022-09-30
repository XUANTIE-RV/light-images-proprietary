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
 * @cond    cam_engine_ie
 *
 * @file    cam_engine_imgeffects_api.h
 *
 * @brief
 *
 *   Interface description of the CamEngine Image Effects.
 *
 *****************************************************************************/
/**
 *
 * @defgroup cam_engine_imgeffects_api CamEngine Image Effects API
 * @{
 *
 */

#ifndef __CAM_ENGINE_IMG_EFFECTS_RY_API_H__
#define __CAM_ENGINE_IMG_EFFECTS_RY_API_H__

#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif

//FIXME
#include <cameric_drv/cameric_ie_drv_ry_api.h>


/*****************************************************************************/
/**
 * @brief   This function enables the image effects.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineEnableImageEffect_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamerIcIeConfig_ry_t *pConfig
);


/*****************************************************************************/
/**
 * @brief   This function disables the image effects.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineDisableImageEffect_ry
(
    CamEngineHandle_ry_t hCamEngine
);


RESULT CamEngineImageEffectSetTintCb_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    const uint8_t       tint
);


RESULT CamEngineImageEffectSetTintCr_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    const uint8_t       tint
);


RESULT CamEngineImageEffectSetColorSelection_ry
(
    CamEngineHandle_ry_t               hCamEngine,
    const CamerIcIeColorSelection_t color,
    const uint8_t                   threshold
);


RESULT CamEngineImageEffectSetSharpen_ry
(
    CamEngineHandle_ry_t               hCamEngine,
    const uint8_t                   factor,
    const uint8_t                   threshold
);


#ifdef __cplusplus
}
#endif

/* @} cam_engine_imgeffects_api */

#endif /* __CAM_ENGINE_IMG_EFFECTS_RY_API_H__ */

