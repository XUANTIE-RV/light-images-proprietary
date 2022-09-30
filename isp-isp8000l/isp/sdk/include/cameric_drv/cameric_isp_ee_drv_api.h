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
#ifndef __CAMERIC_ISP_EE_DRV_API_H__
#define __CAMERIC_ISP_EE_DRV_API_H__

#include <ebase/types.h>
#include <common/return_codes.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief   Enumeration type to input data format select.
 *
 */
typedef enum CamerIcIspEeInputDataFormatSelect_e
{
    CAMERIC_ISP_EE_INPUT_DATA_FORMAT_SELECT_INVALID   = 0,
    CAMERIC_ISP_EE_INPUT_DATA_FORMAT_SELECT_RGB       = 1,
    CAMERIC_ISP_EE_INPUT_DATA_FORMAT_SELECT_YUV       = 2,
    CAMERIC_ISP_EE_INPUT_DATA_FORMAT_SELECT_MAX
} CamerIcIspEeInputDataFormatSelect_t;


/******************************************************************************/
/**
 * @brief   CamerIC EE configuration
 *
 *****************************************************************************/
typedef struct CamerIcIspEeConfig_s
{
	bool									enabled;
	uint8_t  								strength;

	uint16_t 								yUpGain;
	uint16_t 								yDownGain;

	uint16_t 								uvGain;
	uint16_t 								edgeGain;

	uint8_t  								srcStrength;
	CamerIcIspEeInputDataFormatSelect_t		inputDataFormatSelect;
} CamerIcIspEeConfig_t;


/*****************************************************************************/
/**
 * @brief   This function configures the EE module.
 *
 * @param   handle              CamerIc driver handle
 * @param   pConfig             Configuration of the EE module (@ref
 *                              CamerIcIspEeConfig_t)
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
RESULT CamerIcIspEeConfig
(
    CamerIcDrvHandle_t      handle,
    CamerIcIspEeConfig_t   *pConfig
);

/*****************************************************************************/
/**
 * @brief   This functions enables the CamerIC ISP EE module.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspEeEnable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspEeDisable()
 *
 * @brief   Disable EE Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspEeDisable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function
 *
 * @param   handle              CamerIc driver handle
 * @param   pIsEnabled          Pointer to value to store current state
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NULL_POINTER    pIsEnabled is NULL pointer
 *
 *****************************************************************************/
RESULT CamerIcIspEeIsEnabled
(
    CamerIcDrvHandle_t      handle,
    bool_t                  *pIsEnabled
);
RESULT CamerIcIspEeSetGain
(
    CamerIcDrvHandle_t    handle,
    const uint32_t        isp_y_gain,
    const uint16_t        isp_uv_gain,
    const uint16_t        isp_edge_gain
);
RESULT CamerIcIspEeGetGain
(
    CamerIcDrvHandle_t  handle,
    uint32_t            *isp_ee_y_gain,
    uint16_t            *isp_ee_uv_gain,
    uint16_t            *isp_ee_edge_gain
);
RESULT CamerIcIspEeGetConfig
(
    CamerIcDrvHandle_t      handle,
    CamerIcIspEeConfig_t   *pConfig
);


#ifdef __cplusplus
}
#endif

/* @} cameric_isp_ee_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_EE_DRV_API_H__ */


