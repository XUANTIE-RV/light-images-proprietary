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

#ifndef __CAMERIC_ISP_CROP_DRV_API_H__
#define __CAMERIC_ISP_CROP_DRV_API_H__

/**
 * @cond    cameric_isp_crop
 *
 * @file    cameric_isp_crop_drv_api.h
 *
 * @brief   This file contains the CamerIC ISP crop Driver
 *          API definitions
 *
 *****************************************************************************/

#include <ebase/types.h>
#include <common/return_codes.h>

#include "cameric_drv_api.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct CamericIspCropContext_s
{
    /* data */
    CamerIcWindow_t  outWin;
    bool                enabled;
    uint32_t            inputWidth;
    uint32_t            inputHeight;
    uint8_t             pathId;
}CamericIspCropContext_t;


/*****************************************************************************/
/**
 * @brief   Initialize CamerIc ISP CROP driver context.
 *
 * @param   handle          CamerIc driver handle.
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspCropInit
(
    CamerIcDrvHandle_t handle
);

/*****************************************************************************/
/**
 * @brief   Release/Free CamerIc ISP CROP driver context.
 *
 * @param   handle          CamerIc driver handle.
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspCropRelease
(
    CamerIcDrvHandle_t handle
);

/*****************************************************************************/
/**
 * @brief   This functions enables the CamerIC ISP crop module.
 *
 *          Important note: This only enables the crop
 *          functionality of the CROP HW.
 *
 *
 * @param   handle              CamerIc driver handle
 * @param   pathId              path id
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspEnableCrop
(
    CamerIcDrvHandle_t handle,
    uint8_t pathId

);


/*****************************************************************************/
/**
 * @brief   This functions disables the CamerIC ISP crop module.
 *
 * @param   handle              CamerIc driver handle
 * @param   pathId              path id
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspDisableCrop
(
    CamerIcDrvHandle_t handle,
    uint8_t             pathId
);



/*****************************************************************************/
/**
 * @brief   Get CamerIC ISP crop status.
 *
 * @param   handle          CamerIc driver handle.
 * @param   pathId              path id
 * @param   pIsEnabled      Points to value indicating if crop is
 *                          enabled if function returns RET_SUCCESS
 *
 * @return                  Return the result of the function call.
 * @retval RET_SUCCESS      operation succeeded
 * @retval RET_WRONG_HANDLE handle is invalid
 * @retval RET_NULL_POINTER NULL pointer passed
 *
 *****************************************************************************/
extern RESULT CamerIcIspIsCropEnabled
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 pathId,
    bool_t                  *pIsEnabled
);



/*****************************************************************************/
/**
 * @brief   This functions config the crop context
 *
 * @param   handle              CamerIc driver handle
   * @param   pathId              path id
 * @param   pCrop             Pointer to crop context
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NULL_POINTER    NULL pointer passed
 * @retval  RET_WRONG_CONFIG    invalid window configuration
 *
 *****************************************************************************/
extern RESULT CamerIcIspConfigCrop
(
    CamerIcDrvHandle_t  handle,
    CamericIspCropContext_t    *pCrop
);



/*****************************************************************************/
/**
 * @brief   This functions gets the output window currently configured in the
 *          CamerIC ISP crop.
 *
 * @param   handle              CamerIc driver handle
  * @param   pathId              path id
 * @param   pOutWin             Points to current configured output window
 *                              if function returns RET_SUCCESS.
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NULL_POINTER    NULL pointer passed
 *
 *****************************************************************************/
extern RESULT CamerIcIspGetCropOutputWindow
(
    CamerIcDrvHandle_t  handle,
    uint8_t            pathId,
    CamerIcWindow_t    *pOutWin
);



#ifdef __cplusplus
}
#endif

/* @} cameric_isp_crop_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_CROP_DRV_API_H__ */

