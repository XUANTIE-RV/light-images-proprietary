/******************************************************************************\
|* Copyright (c) 2020 by VeriSilicon Holdings Co., Ltd. ("VeriSilicon")       *|
|* All Rights Reserved.                                                       *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of VeriSilicon.  This is proprietary information owned or licensed by      *|
|* VeriSilicon.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of VeriSilicon.                                         *|
|*                                                                            *|
\******************************************************************************/

#ifndef __CAMERIC_ISP_TPG_DRV_API_H__
#define __CAMERIC_ISP_TPG_DRV_API_H__

/**
 * @file    cameric_isp_tpg_drv_api.h
 *
 * @brief   This file contains the CamerIC ISP compand driver API definitions.
 *
 *****************************************************************************/
/**
 * @cond cameric_isp_compand
 *
 * @defgroup cameric_isp_compand_drv_api CamerIC ISP compand Driver API definitions
 * @{
 *
 */
#include <ebase/types.h>
#include <common/return_codes.h>

#ifdef __cplusplus
extern "C"
{
#endif



/*****************************************************************************/
/**
 *          CamerIcIspTpgEnable()
 *
 * @brief   Enable TPG Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspTpgEnable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspTpgDisable()
 *
 * @brief   Disable TPG Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspTpgDisable
(
    CamerIcDrvHandle_t handle
);

/*****************************************************************************/
/**
 *          CamerIcIspTpgConfigMode()
 *
 * @brief   Config TPG mode
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspTpgConfig
(
    CamerIcDrvHandle_t      handle,
    CamerIcIspTpgConfig_t  *pTpgConfig

);


#ifdef __cplusplus
}
#endif



#endif /* __CAMERIC_ISP_TPG_DRV_API_H__ */

