/******************************************************************************
*
* Copyright 2010, Dream Chip Technologies GmbH. All rights reserved.
* No part of this work may be reproduced, modified, distributed, transmitted,
* transcribed, or translated into any language or computer format, in any form
* or by any means without written permission of:
* Dream Chip Technologies GmbH, Steinriede 10, 30827 Garbsen / Berenbostel,
* Germany
*
*****************************************************************************/
#ifndef __CAMERIC_ISP_2DNR_DRV_RY_API_H__
#define __CAMERIC_ISP_2DNR_DRV_RY_API_H__

/**
* @file    cameric_isp_2dnr_drv_ry_api.h
*
* @brief   This file contains the CamerIC ISP 2DNR driver API definitions.
*
*****************************************************************************/
/**
* @cond cameric_isp_2dnr
*
* @defgroup cameric_isp_2dnr_drv_api CamerIC ISP 2DNR Driver API definitions
* @{
*
*/
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define ISP_2DNR_SIGMA_BIN 60
typedef struct CamerIcIsp2DnrConfig_ry_s {
    bool        enable;
    float 		sigma;       	  /**< sigma */
    uint8_t		strength;  		  /**< strength */
    uint8_t		pregmaStrength;   /**< pregmaStrength */
	uint16_t    coeff[ISP_2DNR_SIGMA_BIN];          /**< denoise sigma Y */
//#ifdef ISP_2DNR_V4

   uint16_t strengthOffset, strengthMax;
   uint8_t  strengthSlope;
//#endif
} CamerIcIsp2DnrConfig_ry_t;

/*****************************************************************************/
/**
*          CamerIcIsp2DnrEnable_ry()
*
* @brief   Enable 2DNR Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIsp2DnrEnable_ry
(
	CamerIcDrvHandle_ry_t handle
);

/*****************************************************************************/
/**
*          CamerIcIsp2DnrDisable_ry()
*
* @brief   Disable 2DNR Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIsp2DnrDisable_ry
(
	CamerIcDrvHandle_ry_t handle
);


/*****************************************************************************/
/**
*          CamerIcIsp2DnrConfig_ry()
*
* @brief   Config 2DNR Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIsp2DnrConfig_ry
(
	CamerIcDrvHandle_ry_t 		handle,
    CamerIcIsp2DnrConfig_ry_t  *p2DnrCfg
);



#ifdef __cplusplus
}
#endif

/* @} cameric_isp_2dnr_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_2DNR_DRV_RY_API_H__ */


