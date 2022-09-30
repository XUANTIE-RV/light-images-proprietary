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

#ifndef __CAMERIC_ISP_WDR3_DRV_RY_API_H__
#define __CAMERIC_ISP_WDR3_DRV_RY_API_H__

/**
 * @file    cameric_isp_wdr3_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC ISP WDR driver API definitions.
 *
 *****************************************************************************/
/**
 * @cond cameric_isp_wdr3
 *
 * @defgroup cameric_isp_wdr3_drv_api CamerIC ISP WDR3 Driver API definitions
 * @{
 *
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif


typedef struct CamerIcIspWdr3Config_ry_s {
    uint8_t               strength;			/**< strength */
    uint8_t               globalStrength;	/**< globalStrength */
    uint8_t               maxGain;			/**< maxGain */
} CamerIcIspWdr3Config_ry_t;


/*****************************************************************************/
/**
 *          CamerIcIspWdr3Enable_ry()
 *
 * @brief   Enable WDR3 Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspWdr3Enable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspWdr3Disable_ry()
 *
 * @brief   Disable WDR3 Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspWdr3Disable_ry
(
    CamerIcDrvHandle_ry_t handle
);


/*****************************************************************************/
/**
*          CamerIcIspWdr3Config_ry()
*
* @brief   Config WDR3 Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspWdr3Config_ry
(
	CamerIcDrvHandle_ry_t 		handle,
    CamerIcIspWdr3Config_ry_t  *pWdr3Cfg
);

RESULT CamerIcIspWdr3SetLowlightStrength_ry
(
	CamerIcDrvHandle_ry_t 		handle,
    float strength
);

RESULT CamerIcIspWdr3SetGammadownCurve_ry
(
	CamerIcDrvHandle_ry_t 		handle,
    unsigned short* pGammadownCurve
);

RESULT CamerIcIspWdr3SetLocalStrength_ry
(
	CamerIcDrvHandle_ry_t 		handle,
    int strength
);

RESULT CamerIcIspWdr3SetPixelSlope_ry
(
	CamerIcDrvHandle_ry_t handle,
    unsigned char merge_slope,
    unsigned char merge_base,
    unsigned char adjust_slope,
    unsigned char adjust_base
);

RESULT CamerIcIspWdr3SetEntropySlope_ry
(
	CamerIcDrvHandle_ry_t 		handle,
    unsigned short slope,
    unsigned short base
);

RESULT CamerIcIspWdr3GetHistogram_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);
RESULT CamerIcIspWdr3SetHistogram_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);

RESULT CamerIcIspWdr3GetGammaup_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);
RESULT CamerIcIspWdr3SetGammaup_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);

RESULT CamerIcIspWdr3GetEntropy_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);
RESULT CamerIcIspWdr3SetEntropy_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);

RESULT CamerIcIspWdr3GetDistanceWeight_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);
RESULT CamerIcIspWdr3SetDistanceWeight_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);

RESULT CamerIcIspWdr3GetDiffWeight_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);
RESULT CamerIcIspWdr3SetDiffWeight_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);

RESULT CamerIcIspWdr3GetInvertLinear_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);
RESULT CamerIcIspWdr3SetInvertLinear_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);

RESULT CamerIcIspWdr3GetInvertCurve_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);
RESULT CamerIcIspWdr3SetInvertCurve_ry(CamerIcDrvHandle_ry_t handle, unsigned int* bin);

RESULT CamerIcIspWdr3GetSigma_ry(CamerIcDrvHandle_ry_t handle, int* pSigmaWidth, int* pSigmaHeight, int* pSigmaValue);
RESULT CamerIcIspWdr3SetSigma_ry(CamerIcDrvHandle_ry_t handle, int w, int h, int val);

bool CamerIcIspWdr3IsEnable_ry(CamerIcDrvHandle_ry_t handle);

#ifdef __cplusplus
}
#endif



#endif /* __CAMERIC_ISP_WDR3_DRV_RY_API_H__ */

