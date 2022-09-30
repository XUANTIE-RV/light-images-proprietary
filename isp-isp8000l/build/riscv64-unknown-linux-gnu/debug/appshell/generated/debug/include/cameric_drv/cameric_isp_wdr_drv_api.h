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

#ifndef __CAMERIC_ISP_WDR_DRV_API_H__
#define __CAMERIC_ISP_WDR_DRV_API_H__

/**
 * @file    cameric_isp_wdr_drv_api.h
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
#include <ebase/types.h>
#include <common/return_codes.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define CAMERIC_WDR_MAX_COEFFS      33
#define CAMERIC_WDR_MAX_SEGMENTS    ( CAMERIC_WDR_MAX_COEFFS - 1 )



/*******************************************************************************
 *
 *          CamerIcIspWdrToneCurve_t
 *
 * @brief
 *
 */
typedef struct CamerIcIspWdrToneCurve_s
{
    uint16_t    Segment[CAMERIC_WDR_MAX_SEGMENTS];
    uint16_t    Ym[CAMERIC_WDR_MAX_COEFFS];
} CamerIcIspWdrToneCurve_t;



/*****************************************************************************/
/**
 *          CamerIcIspWdrEnable()
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
RESULT CamerIcIspWdrEnable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspWdrDisable()
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
RESULT CamerIcIspWdrDisable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspWdrSetRgbOffset()
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
RESULT CamerIcIspWdrSetRgbOffset
(
    CamerIcDrvHandle_t  handle,
    const uint32_t      RgbOffset
);



/*****************************************************************************/
/**
 *          CamerIcIspWdrSetLumOffset()
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
RESULT CamerIcIspWdrSetLumOffset
(
    CamerIcDrvHandle_t  handle,
    const uint32_t      LumOffset
);



/*****************************************************************************/
/**
 *          CamerIcIspWdrSetStaticDemoConfig()
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
RESULT CamerIcIspWdrSetStaticDemoConfig
(
    CamerIcDrvHandle_t  handle
);

/***********************************************************************
****************************************************************
*Modify by Fei for demo Only Start!!!
****************************************************************
************************************************************************/
RESULT CamerIcIspWdrSetStaticDemoConfigCurve0
(
    CamerIcDrvHandle_t  handle
);


RESULT CamerIcIspWdrSetStaticDemoConfigCurve1
(
    CamerIcDrvHandle_t  handle
);

RESULT CamerIcIspWdrSetStaticDemoConfigCurve2
(
    CamerIcDrvHandle_t  handle
);

RESULT CamerIcIspWdrSetStaticDemoConfigCurve3
(
    CamerIcDrvHandle_t  handle
);

/***********************************************************************
****************************************************************
*Modify by Fei for demo Only End!!!
****************************************************************
************************************************************************/
RESULT CamerIcIspWdrSetCurve
(
    CamerIcDrvHandle_t  handle,
    uint16_t            *Ym,
    uint8_t             *dY
);

#ifdef __cplusplus
}
#endif

/* @} cameric_isp_wdr_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_DPF_DRV_API_H__ */

