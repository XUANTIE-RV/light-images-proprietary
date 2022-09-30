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

#ifndef __CAMERIC_ISP_WDR_DRV_RY_API_H__
#define __CAMERIC_ISP_WDR_DRV_RY_API_H__

/**
 * @file    cameric_isp_wdr_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC ISP WDR driver API definitions.
 *
 *****************************************************************************/
/**
 * @cond cameric_isp_wdr
 *
 * @defgroup cameric_isp_wdr_drv_api CamerIC ISP WDR Driver API definitions
 * @{
 *
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define CAMERIC_WDR_MAX_COEFFS      33
#define CAMERIC_WDR_MAX_SEGMENTS    ( CAMERIC_WDR_MAX_COEFFS - 1 )



/*******************************************************************************
 *
 *          CamerIcIspWdrToneCurve_ry_t
 *
 * @brief
 *
 */
typedef struct CamerIcIspWdrToneCurve_ry_s
{
    uint16_t    Segment[CAMERIC_WDR_MAX_SEGMENTS];
    uint16_t    Ym[CAMERIC_WDR_MAX_COEFFS];
} CamerIcIspWdrToneCurve_ry_t;



/*****************************************************************************/
/**
 *          CamerIcIspWdrEnable_ry()
 *
 * @brief   Enable WDR Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspWdrEnable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspWdrDisable_ry()
 *
 * @brief   Disable WDR Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspWdrDisable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspWdrSetRgbOffset_ry()
 *
 * @brief   Set RGB Offset
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspWdrSetRgbOffset_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const uint32_t      RgbOffset
);



/*****************************************************************************/
/**
 *          CamerIcIspWdrSetLumOffset_ry()
 *
 * @brief   Set Luminance Offset
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspWdrSetLumOffset_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const uint32_t      LumOffset
);



/*****************************************************************************/
/**
 *          CamerIcIspWdrSetStaticDemoConfig_ry()
 *
 * @brief   Set static WDR configuration; quick hack for demo purposes only!
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspWdrSetStaticDemoConfig_ry
(
    CamerIcDrvHandle_ry_t  handle
);

/***********************************************************************
****************************************************************
*Modify by Fei for demo Only Start!!!
****************************************************************
************************************************************************/
RESULT CamerIcIspWdrSetStaticDemoConfigCurve0_ry
(
    CamerIcDrvHandle_ry_t  handle
);


RESULT CamerIcIspWdrSetStaticDemoConfigCurve1_ry
(
    CamerIcDrvHandle_ry_t  handle
);

RESULT CamerIcIspWdrSetStaticDemoConfigCurve2_ry
(
    CamerIcDrvHandle_ry_t  handle
);

RESULT CamerIcIspWdrSetStaticDemoConfigCurve3_ry
(
    CamerIcDrvHandle_ry_t  handle
);

/***********************************************************************
****************************************************************
*Modify by Fei for demo Only End!!!
****************************************************************
************************************************************************/
RESULT CamerIcIspWdrSetCurve_ry
(
    CamerIcDrvHandle_ry_t  handle,
    uint16_t            *Ym,
    uint8_t             *dY
);

#ifdef __cplusplus
}
#endif

/* @} cameric_isp_wdr_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_WDR_DRV_RY_API_H__ */

