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

#ifndef __CAMERIC_ISP_GREEN_EQUILIBRATION_DRV_API_H__
#define __CAMERIC_ISP_GREEN_EQUILIBRATION_DRV_API_H__

/**
 * @cond    cameric_isp_green_equilibration
 *
 * @file    cameric_isp_green_equilibration_drv_api.h
 *
 * @brief   This file contains the CamerIC ISP GREEN_EQUILIBRATION (video stabilization) Driver
 *          API definitions
 *
 *****************************************************************************/
/**
 * @defgroup cameric_isp_green_equilibration_drv_api CamerIC ISP GREEN_EQUILIBRATION Driver API definitions
 *
 *
 */
#include <ebase/types.h>
#include <common/return_codes.h>

#ifdef __cplusplus
extern "C"
{
#endif


typedef struct CamerIcIspGreenEqlr_s
{
    bool enable;
    uint16_t threshold;
    uint16_t dummyLine;
} CamerIcIspGreenEqlr_t;

/*****************************************************************************/
/**
 * @brief   This functions enables the CamerIC ISP green equilibration
 *           module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspGreenEqlrEnable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This functions disables the CamerIC ISP green equilibration
 *            module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspGreenEqlrDisable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   Get CamerIC ISP green equilibration module status.
 *
 * @param   handle          CamerIc driver handle.
 * @param   pIsEnabled
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
extern RESULT CamerIcIspGreenEqlrIsEnabled
(
    CamerIcDrvHandle_t      handle,
    bool_t                  *pIsEnabled
);

/*****************************************************************************/
/**
 * @brief
 *
 * @param   handle          CamerIc driver handle.
 * @param
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspGreenEqlrConfig
(
    CamerIcDrvHandle_t      handle,
    uint16_t threshold, uint16_t dummyLine
);

RESULT CamerIcIspGetGe
(
    CamerIcDrvHandle_t  handle,
    uint32_t            *enable,
    uint32_t            *pThreshold,
    uint32_t            *pHDummy
);

#ifdef __cplusplus
}
#endif

/* @} cameric_isp_green_equilibration_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_GREEN_EQUILIBRATION_DRV_API_H__ */


