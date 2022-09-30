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
#ifndef __CAMERIC_ISP_RGBGAMMA_DRV_API_H__
#define __CAMERIC_ISP_RGBGAMMA_DRV_API_H__
//#ifdef ISP_RGBGC

#include <ebase/types.h>
#include <common/return_codes.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define CAMERIC_ISP_RGBGAMMA_PX_NUM 64    /* 64 items */
#define CAMERIC_ISP_RGBGAMMA_DATA_X_NUM 63    /* 63 items */
#define CAMERIC_ISP_RGBGAMMA_DATA_Y_NUM 64    /* 64 items */


/*******************************************************************************
 *
 *          CamerIcIsprgb gammaContext_t
 *
 * @brief
 *
 */
typedef struct CamerIcIspRgbGammaContext_s
{
    bool		           enabled;                            /**< rgb gamma enabled */
    uint32_t               rgbgammaRPx[CAMERIC_ISP_RGBGAMMA_PX_NUM];                          /**< rgb gamma px table */
    uint32_t               rgbgammaRDataX[CAMERIC_ISP_RGBGAMMA_DATA_X_NUM];                          /**< rgb gamma data x table */
    uint32_t              rgbgammaRDataY[CAMERIC_ISP_RGBGAMMA_DATA_Y_NUM];                          /**< rgb gamma data y table */

    uint32_t               rgbgammaGPx[CAMERIC_ISP_RGBGAMMA_PX_NUM];                          /**< rgb gamma px table */
    uint32_t               rgbgammaGDataX[CAMERIC_ISP_RGBGAMMA_DATA_X_NUM];                          /**< rgb gamma data x table */
    uint32_t              rgbgammaGDataY[CAMERIC_ISP_RGBGAMMA_DATA_Y_NUM];                          /**< rgb gamma data y table */

    uint32_t               rgbgammaBPx[CAMERIC_ISP_RGBGAMMA_PX_NUM];                          /**< rgb gamma px table */
    uint32_t               rgbgammaBDataX[CAMERIC_ISP_RGBGAMMA_DATA_X_NUM];                          /**< rgb gamma data x table */
    uint32_t              rgbgammaBDataY[CAMERIC_ISP_RGBGAMMA_DATA_Y_NUM];                          /**< rgb gamma data y table */
} CamerIcIspRgbGammaContext_t;

/*****************************************************************************/
/**
 * @brief   This functions enables the CamerIC ISP rgbgamma
 *          module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspRgbGammaEnable
(
    CamerIcDrvHandle_t handle
);


/*****************************************************************************/
/**
 * @brief   This functions disables the CamerIC ISP rgbgamma
 *          module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspRgbGammaDisable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   Get CamerIC ISP rgb gamma module status.
 *
 * @param   handle          CamerIc driver handle.
 * @param   pIsEnabled
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
extern RESULT CamerIcIspRgbGammaIsEnabled
(
    CamerIcDrvHandle_t          handle,
    bool    *pIsEnabled
);

/******************************************************************************
 * CamerIcIspRgbGammaConfig()
 * @brief   config CamerIC ISP rgb gamma module.
 *
 * @param   handle          CamerIc driver handle.
 * @param   pRgbGammaCtx      rgbgamma Context pointer
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/

extern RESULT CamerIcIspRgbGammaConfig
(
    CamerIcDrvHandle_t              handle,
    CamerIcIspRgbGammaContext_t       *pRgbGammaCtx
);

/******************************************************************************
 * CamerIcIspRgbGammaGetConfig()
 * @brief   get ISP rgb gamma module config..
 *
 * @param   handle          CamerIc driver handle.
 * @param   *pRgbGammaCtx     rgb gamma Context pointer
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspRgbGammaGetConfig
(
    CamerIcDrvHandle_t handle,
    CamerIcIspRgbGammaContext_t *pRgbGammaCtx
);


#ifdef __cplusplus
}
#endif

/* @} cameric_isp_rgbgamma_drv_api */

/* @endcond */
//#endif /* ISP_RGBGAMMA */
#endif /* __CAMERIC_ISP_RGBGAMMA_DRV_API_H__ */


