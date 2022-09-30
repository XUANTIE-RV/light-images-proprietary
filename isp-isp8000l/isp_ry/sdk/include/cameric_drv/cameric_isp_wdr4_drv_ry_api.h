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

#ifndef __CAMERIC_ISP_WDR4_DRV_RY_API_H__
#define __CAMERIC_ISP_WDR4_DRV_RY_API_H__

/**
 * @file    cameric_isp_wdr4_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC ISP WDR driver API definitions.
 *
 *****************************************************************************/
/**
 * @cond cameric_isp_wdr4
 *
 * @defgroup cameric_isp_wdr4_drv_api CamerIC ISP WDR4 Driver API definitions
 * @{
 *
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif


typedef struct CamerIcIspWdr4Config_ry_s {
    uint8_t               strength;			/**< strength */
    uint8_t               highStrength;		/**< highStrength */
    uint8_t               lowStrength;		/**< lowStrength */
    uint8_t               globalStrength;	/**< globalStrength */
    int                   contrast;         /**< contrast */
    uint8_t               flatStrength;     /**< flatStrength */
    uint8_t               flatThreshold;    /**< flatThreshold */
} CamerIcIspWdr4Config_ry_t;

RESULT CamerIcIspWdr4Init_ry
(
    CamerIcDrvHandle_ry_t handle
);

RESULT CamerIcIspWdr4Release_ry
(
    CamerIcDrvHandle_ry_t handle
);
/*****************************************************************************/
/**
 *          CamerIcIspWdr4Enable_ry()
 *
 * @brief   Enable WDR4 Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspWdr4Enable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspWdr4Disable_ry()
 *
 * @brief   Disable WDR4 Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspWdr4Disable_ry
(
    CamerIcDrvHandle_ry_t handle
);


/*****************************************************************************/
/**
*          CamerIcIspWdr4Config_ry()
*
* @brief   Config WDR4 Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspWdr4Config_ry
(
	CamerIcDrvHandle_ry_t 		handle,
    CamerIcIspWdr4Config_ry_t  *pWdr4Cfg
);

RESULT CamerIcIspWdr4SetFlat_ry
(
	CamerIcDrvHandle_ry_t handle,
    uint8_t strength,
    uint8_t threshold
);

/*****************************************************************************/
/**
*          CamerIcIspWdr4StoreHdrRatio_ry()
*
* @brief   Config WDR4 Module
*
* @param   handle          CamerIc driver handle
* @param   ratioLSVS,      hdr long exposure and very short exposure 
* @param   ratioLS         hdr long exposure and short exposure
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspWdr4StoreHdrRatio_ry
(
	CamerIcDrvHandle_ry_t  handle,
	uint8_t  ratioLSVS,
    uint8_t   ratioLS
);

RESULT CamerIcIspWdr4GetEnable_ry
(
	CamerIcDrvHandle_ry_t handle,
    bool *pEnabled
);

RESULT CamerIcIspWdr4GetLowStrength_ry
(
	CamerIcDrvHandle_ry_t handle,
    uint32_t *low_strength
);

RESULT CamerIcIspWdr4SetEntropy_ry
(
	CamerIcDrvHandle_ry_t handle,
    uint32_t *entropy
);

RESULT CamerIcIspWdr4SetGammaPre_ry
(
	CamerIcDrvHandle_ry_t handle,
    uint32_t *gammapre
);

RESULT CamerIcIspWdr4SetGammaUp_ry
(
	CamerIcDrvHandle_ry_t handle,
    uint32_t *gammaup
);

RESULT CamerIcIspWdr4SetGammaDown_ry
(
	CamerIcDrvHandle_ry_t handle,
    uint32_t *gammadown
);

RESULT CamerIcIspWdr4SetEntropySlope_ry
(
	CamerIcDrvHandle_ry_t handle,
    uint32_t slope,
    uint32_t base
);

#ifdef __cplusplus
}
#endif



#endif /* __CAMERIC_ISP_WDR4_DRV_RY_API_H__ */


