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

#ifndef __CAMERIC_ISP_EXPV2_DRV_RY_API_H__
#define __CAMERIC_ISP_EXPV2_DRV_RY_API_H__

/**
 * @cond    cameric_isp_expv2
 *
 * @file    cameric_isp_expv2_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC ISP AE Driver API definitions
 *
 *****************************************************************************/
/**
 * @defgroup cameric_isp_expv2_drv_api CamerIC ISP AE Driver API definitions
 * @{
 *
 * @image html exp.png "Overview of the CamerIC ISP CAC driver" width=\textwidth
 * @image latex exp.png "Overview of the CamerIC ISP CAC driver" width=\textwidth
 *
 * @image html exp_grid.png "Luminance Measurement Grid" width=0.8\textwidth
 * @image latex exp_grid.png "Luminance Measurement Grid" width=0.8\textwidth
 *
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum CamerIcIspExpV2Sel_ry_e
{
    AEV2_INPUT_SEL_DEGAMMA       = 0,
    AEV2_INPUT_SEL_AWBGAIN       = 1,
    AEV2_INPUT_SEL_WDR3          = 2,
    AEV2_INPUT_SEL_LSC           = 3
} CamerIcIspExpV2Sel_ry_t;
/*****************************************************************************/
/**
 * @brief   This functions registers an Event-Callback at CamerIC ISP histogram
 *          measurement module. An event callback is called if the driver needs
 *          to inform the application layer about an asynchronous event or an
 *          error situation (i.e. please also @see CamerIcEventId_ry_e).
 *
 * @param   handle              CamerIc driver handle
 * @param   func                Callback function
 * @param   pUserContext        User-Context
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_BUSY            already a callback registered
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_INVALID_PARM    a parameter is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to register a
 *                              event callback (maybe the driver is already
 *                              running)
 *
 *****************************************************************************/
extern RESULT CamerIcIspExpV2RegisterEventCb_ry
(
    CamerIcDrvHandle_ry_t  handle,
    CamerIcEventFunc_ry_t  func,
    void 			    *pUserContext
);



/*****************************************************************************/
/**
 * @brief   This functions deregisters/releases a registered Event-Callback
 *          at CamerIc ISP histogram measurement module.
 *
 * @param   handle              CamerIC driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to deregister the
 *                              request callback
 *
 *****************************************************************************/
extern RESULT CamerIcIspExpV2DeRegisterEventCb_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 * @brief   This functions enables the CamerIC ISP exposure measurement
 *          module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspExpV2Enable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 * @brief   This functions disables the CamerIC ISP exposure measurement
 *          module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspExpV2Disable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 * @brief   Get CamerIC ISP exposure measurement module status.
 *
 * @param   handle          CamerIc driver handle.
 * @param   pIsEnabled
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
extern RESULT CamerIcIspExpV2IsEnabled_ry
(
    CamerIcDrvHandle_ry_t      handle,
    bool_t                  *pIsEnabled
);




/*****************************************************************************/
/**
 * @brief   This function sets the position and size of a the measurement
 *          window in the CamerIC ISP exposure measurement module.
 *
 * @note    This function calculates the grid-size by dividing the width and
 *          height by 5.
 *
 * @param   handle              CamerIc driver handle
 * @param   x                   start x position of measuring window
 * @param   y                   start y position of measuring window
 * @param   width               width of measuring window
 * @param   height              height of measuring window
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_INVALID_PARM    invalid window identifier
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspExpV2SetMeasuringWindow_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const uint16_t      x,
    const uint16_t      y,
    const uint16_t      width,
    const uint16_t      height
);

RESULT CamerIcIspExpV2SetWeight_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const uint8_t      rWeight,
    const uint8_t      grWeight,
    const uint8_t      gbWeight,
    const uint8_t      bWeight
);

RESULT CamerIcIspExpV2SetSizeRatio_ry
(
    CamerIcDrvHandle_ry_t handle,
    float ratio
);

RESULT CamerIcIspExpV2InputSel_ry
(
    CamerIcDrvHandle_ry_t  handle,
    CamerIcIspExpV2Sel_ry_t             input_select
);
#ifdef __cplusplus
}
#endif

/* @} cameric_isp_exp_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_EXPV2_DRV_RY_API_H__ */

