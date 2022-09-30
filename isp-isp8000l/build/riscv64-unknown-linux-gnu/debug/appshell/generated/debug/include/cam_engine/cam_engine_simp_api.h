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
 * @cond    cam_engine_simp
 *
 * @file    cam_engine_simp_api.h
 *
 * @brief
 *
 *   Interface description of the CamEngine.
 *
 *****************************************************************************/
/**
 * @defgroup cam_engine_simp CamEngine Super Impose definitions
 * @{
 *
 */
#ifndef __CAM_ENGINE_SIMP_API_H__
#define __CAM_ENGINE_SIMP_API_H__

#include <ebase/types.h>
#include <common/return_codes.h>
#include <common/picture_buffer.h>

#ifdef __cplusplus
extern "C"
{
#endif

//FIXME
#include <cameric_drv/cameric_simp_drv_api.h>


/******************************************************************************/
/**
 * @brief   Enumeration type to configure the super impose working mode.
 *
 *****************************************************************************/
typedef enum CamEngineSimpMode_e
{
    CAM_ENGINE_SIMP_MODE_INVALID            = 0,        /**< lower border (only for an internal evaluation) */
    CAM_ENGINE_SIMP_MODE_OVERLAY            = 1,        /**< overlay mode */
    CAM_ENGINE_SIMP_MODE_KEYCOLORING        = 2,        /**< keycoloring mode */
    CAM_ENGINE_SIMP_MODE_MAX                            /**< upper border (only for an internal evaluation) */
} CamEngineSimpMode_t;



/******************************************************************************/
/**
 * @brief   Structure to configure the super impose module
 *
 * @note    This structure needs to be converted to driver structure
 *
 *****************************************************************************/
typedef struct CamEngineSimpConfig_s
{
    CamEngineSimpMode_t     Mode;

    union SimpModeConfig_u
    {
        struct Overlay_s
        {
            uint32_t OffsetX;
            uint32_t OffsetY;
        } Overlay;

        struct KeyColoring_s
        {
            uint8_t Y;
            uint8_t Cb;
            uint8_t Cr;
        } KeyColoring;
    } SimpModeConfig;

    PicBufMetaData_t      *pPicBuffer;

} CamEngineSimpConfig_t;



/*****************************************************************************/
/**
 * @brief   This function enables the super impose.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   pConfig             configuration off color processing
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineEnableSimp
(
    CamEngineHandle_t       hCamEngine,
    CamEngineSimpConfig_t   *pConfig
);



/*****************************************************************************/
/**
 * @brief   This function disables the super impose.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineDisableSimp
(
    CamEngineHandle_t   hCamEngine
);



#ifdef __cplusplus
}
#endif

/* @} cam_engine_simp */

#endif /* __CAM_ENGINE_SIMP_API_H__ */

