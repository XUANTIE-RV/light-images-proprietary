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

#ifndef __CAMERIC_ISP_DEGAMMA_DRV_API_H__
#define __CAMERIC_ISP_DEGAMMA_DRV_API_H__

/**
 * @cond    cameric_isp_degamma
 *
 * @file    cameric_isp_degamma_drv_api.h
 *
 * @brief   This file contains the CamerIC ISP DEGAMMA driver API definitions.
 *
 *****************************************************************************/
/**
 * @defgroup cameric_isp_degamma_drv_api CamerIC ISP DEGAMMA driver API definitions
 * @{
 *
 */
#include <ebase/types.h>
#include <common/return_codes.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define CAMERIC_DEGAMMA_CURVE_SIZE      17U


/*******************************************************************************
 *
 * @brief
 *
 */
typedef struct CamerIcIspDegammaCurve_s
{
    uint8_t     segment[CAMERIC_DEGAMMA_CURVE_SIZE-1];      /**< x_i segment size */
    uint16_t    red[CAMERIC_DEGAMMA_CURVE_SIZE];            /**< red point */
    uint16_t    green[CAMERIC_DEGAMMA_CURVE_SIZE];          /**< green point */
    uint16_t    blue[CAMERIC_DEGAMMA_CURVE_SIZE];           /**< blue point */
} CamerIcIspDegammaCurve_t;



/*****************************************************************************/
/**
 * @brief   This function enables the CamerIC ISP Degamma Module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspDegammaEnable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function disables the CamerIc ISP Degamma module (bypass the
 *          degamma module)
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspDegammaDisable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the status of the CamerIC ISP Degamma module.
 *
 * @param   handle              CamerIc driver handle
 * @param   pIsEnabled          Pointer to value to store current state
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NULL_POINTER    pIsEnabled is a NULL pointer
 *
 *****************************************************************************/
extern RESULT CamerIcIspDegammaIsEnabled
(
    CamerIcDrvHandle_t  handle,
    bool_t              *pIsEnabled
);


/*****************************************************************************/
/**
 * @brief   This function returns the currently configured degamma curve
 *          from the CamerIc ISP Degamma module.
 *
 * @param   handle              CamerIc driver handle
 * @param   pCurve              reference to curve
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_INVALID_PARM    pCurve is a NULL pointer
 *
 *****************************************************************************/
extern RESULT CamerIcIspDegammaGetCurve
(
    CamerIcDrvHandle_t          handle,
    CamerIcIspDegammaCurve_t    *pCurve
);


/*****************************************************************************/
/**
 * @brief   This function set the degamma curve to use in the CamerIc ISP
 *          Degamma module.
 *
 * @param   handle              CamerIc driver handle
 * @param   pCurve              reference to curve
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_INVALID_PARM    pCurve is a NULL pointer
 * @retval  RET_WRONG_STATE     degamma module is running
 *
 *****************************************************************************/
extern RESULT CamerIcIspDegammaSetCurve
(
    CamerIcDrvHandle_t          handle,
    CamerIcIspDegammaCurve_t    *pCurve
);



#ifdef __cplusplus
}
#endif

/* @} cameric_isp_degamma_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_DEGAMMA_DRV_API_H__ */

