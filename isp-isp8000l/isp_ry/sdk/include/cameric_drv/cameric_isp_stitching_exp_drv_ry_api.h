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

#ifndef __CAMERIC_ISP_STITCHING_EXP_DRV_RY_API_H__
#define __CAMERIC_ISP_STITCHING_EXP_DRV_RY_API_H__

/**
 * @cond    cameric_isp_stitching_exp
 *
 * @file    cameric_isp_stitching_exp_drv_api.h
 *
 * @brief   This file contains the CamerIC ISP AE Driver API definitions
 *
 *****************************************************************************/
/**
 * @defgroup cameric_isp_exp_drv_api CamerIC ISP AE Driver API definitions
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


extern RESULT CamerIcIspStitchingExpRegisterEventCb_ry
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
extern RESULT CamerIcIspStitchingExpDeRegisterEventCb_ry
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
extern RESULT CamerIcIspStitchingExpEnable_ry
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
extern RESULT CamerIcIspStitchingExpDisable_ry
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
extern RESULT CamerIcIspStitchingExpIsEnabled_ry
(
    CamerIcDrvHandle_ry_t      handle,
    bool_t                  *pIsEnabled
);



/*****************************************************************************/
/**
 * @brief   This functions configures the measurement mode of the CamerIC
 *          ISP exposure measurement module.
 *
 * @param   handle              CamerIc driver handle
 * @param   mode                measurement mode (@see CamerIcIspHistMode_e)
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
RESULT CamerIcIspStitchingExpSetMeasuringMode_ry
(
    CamerIcDrvHandle_ry_t                  handle,
    const CamerIcIspExpMeasuringMode_ry_t  mode
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
extern RESULT CamerIcIspStitchingExpSetMeasuringWindow_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const uint16_t      x,
    const uint16_t      y,
    const uint16_t      width,
    const uint16_t      height
);

RESULT CamerIcIspStitchingStart
(
    CamerIcDrvHandle_ry_t handle
);

RESULT CamerIcIspStitchingStop_ry
(
    CamerIcDrvHandle_ry_t handle
);

#ifdef __cplusplus
}
#endif

/* @} cameric_isp_exp_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_EXP_DRV_API_H__ */

