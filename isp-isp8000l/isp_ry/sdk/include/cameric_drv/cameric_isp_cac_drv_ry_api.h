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

#ifndef __CAMERIC_ISP_CAC_DRV_RY_API_H__
#define __CAMERIC_ISP_CAC_DRV_RY_API_H__

/**
 * @cond    cameric_isp_cac
 *
 * @file    cameric_isp_cac_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC ISP CAC driver API definitions.
 *
 *****************************************************************************/
/**
 * @defgroup cameric_isp_cac_drv_api CamerIC ISP CAC Driver API definitions
 * @{
 *
 * This hardware module corrects the chromatic aberration of the lens system by
 * shifting the pixels of the incoming image. The direction and the width of the
 * shift is derived from a polynomial model. The polynomial coefficients of the
 * model, appropriate for the used lens system, can be programmed, as well as
 * the optical center of the lens system.
 *
 * The following figure shows the position of the chromatic aberration
 * correction module in the CamerIC ISP pipeline.
 *
 * @image html cac.png "Overview of the CamerIC ISP CAC driver" width=\textwidth
 * @image latex cac.png "Overview of the CamerIC ISP CAC driver" width=\textwidth
 *
 * The initialization is static, thus parameters usually do not change afterwards
 * during runtime. In this case, however, nearly all parameters do change if the
 * resolution is changed. Thus the potential use case is a call to set all parameters
 * during initialization or resolution change and a call to enable/disable the CAC.
 *
 * The polynomial coefficients in registers ISP_CAC_A, ISP_CAC_B and ISP_CAC_C
 * need to be set according to the chromatic aberration which is observed for
 * the used lens system. The observed aberration in an image is normally stronger
 * at the corners of an image as in the middle. In general the strength of the
 * aberration is dependent on the distance from the optical image center.
 *
 * Therefore the polynomial is defined as a function  of the radius from optical image center:
 *
 * B_s (r) = A_blue * r + B_blue * r^2 + C_blue * r^3 \n
 * R_s (r) = A_red * r  + B_red * r^2  + C_red * r^3  \n
 *
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif



/******************************************************************************/
/**
 * @brief   Enumeration type to configure the horizontal clip mode
 *
 * @note    Defines the maximum red/blue pixel shift in horizontal direction
 *          At pixel positions, that require a larger displacement, the maximum
 *          shift value is used instead (vector clipping)
 *
 *****************************************************************************/
typedef enum CamerIcIspCacHorizontalClipMode_ry_e
{
    CAMERIC_CAC_H_CLIPMODE_INVALID  = 0,    /**< lower border (only for an internal evaluation) */
    CAMERIC_CAC_H_CLIPMODE_FIX4     = 1,    /**< horizontal vector clipping +/-4 pixel displacement (default) */
    CAMERIC_CAC_H_CLIPMODE_DYN5     = 2,    /**< horizontal vector clipping to +/-4 or +/-5 pixel displacement
                                                 depending on pixel position inside the bayer raster (dynamic
                                                 switching between +/-4 and +/-5) */
    CAMERIC_CAC_H_CLIPMODE_MAX              /**< upper border (only for an internal evaluation) */
} CamerIcIspCacHorizontalClipMode_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure the vertical clip mode
 *
 * @note    Defines the maximum red/blue pixel shift in vertical direction
 *
 *****************************************************************************/
typedef enum CamerIcIspCacVerticalClipMode_ry_e
{
    CAMERIC_CAC_V_CLIPMODE_INVALID  = 0,    /**< lower border (only for an internal evaluation) */
    CAMERIC_CAC_V_CLIPMODE_FIX2     = 1,    /**< vertical vector clipping to +/-2 pixel */
    CAMERIC_CAC_V_CLIPMODE_FIX3     = 2,    /**< vertical vector clipping to +/-3 pixel */
    CAMERIC_CAC_V_CLIBMODE_DYN4     = 3,    /**< vertical vector clipping +/-3 or +/-4 pixel displacement
                                                 depending on pixel position inside the bayer raster (dynamic
                                                 switching between +/-3 and +/-4) */
    CAMERIC_CAC_V_CLIPMODE_MAX              /**< upper border (only for an internal evaluation) */
} CamerIcIspCacVerticalClipMode_ry_t;



/******************************************************************************/
/**
 * @brief   CamerIC CAC configuration
 *
 *****************************************************************************/
typedef struct CamerIcIspCacConfig_ry_s
{
    uint16_t                            width;          /**< width of the input image in pixel */
    uint16_t                            height;         /**< height of the input image in pixel */

    int16_t                             hCenterOffset;  /**< horizontal offset between image center and optical center of the input image in pixels */
    int16_t                             vCenterOffset;  /**< vertical offset between image center and optical center of the input image in pixels */

    CamerIcIspCacHorizontalClipMode_ry_t   hClipMode;      /**< maximum red/blue pixel shift in horizontal direction */
    CamerIcIspCacVerticalClipMode_ry_t     vClipMode;      /**< maximum red/blue pixel shift in vertical direction */

    uint16_t                            aBlue;          /**< parameters for radial shift calculation 9 bit twos complement with 4 fractional digits, valid range -16..15.9375 */
    uint16_t                            aRed;           /**< parameters for radial shift calculation 9 bit twos complement with 4 fractional digits, valid range -16..15.9375 */

    uint16_t                            bBlue;          /**< parameters for radial shift calculation 9 bit twos complement with 4 fractional digits, valid range -16..15.9375 */
    uint16_t                            bRed;           /**< parameters for radial shift calculation 9 bit twos complement with 4 fractional digits, valid range -16..15.9375 */

    uint16_t                            cBlue;          /**< parameters for radial shift calculation 9 bit twos complement with 4 fractional digits, valid range -16..15.9375 */
    uint16_t                            cRed;           /**< parameters for radial shift calculation 9 bit twos complement with 4 fractional digits, valid range -16..15.9375 */

    uint8_t                             Xns;            /**< horizontal normal shift parameter */
    uint8_t                             Xnf;            /**< horizontal scaling factor */

    uint8_t                             Yns;            /**< vertical normal shift parameter */
    uint8_t                             Ynf;            /**< vertical scaling factor */
    float                              fAspectRatio;
} CamerIcIspCacConfig_ry_t;



/*****************************************************************************/
/**
 * @brief   This function configures the CAC module.
 *
 * @param   handle              CamerIc driver handle
 * @param   pConfig             Configuration of the CAC module (@ref
 *                              CamerIcIspCacConfig_ry_t)
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
RESULT CamerIcIspCacConfig_ry
(
    CamerIcDrvHandle_ry_t      handle,
    CamerIcIspCacConfig_ry_t   *pConfig
);


/*****************************************************************************/
/**
 * @brief   This function reads out the current configred chromatic aberration
 *          correction configuration.
 *
 * @param   handle              CamerIc driver handle
 * @param   pConfig             Pointer to store the current configuration
 *                              (@ref  CamerIcIspCacConfig_ry_t)
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NULL_POINTER    pLscConfig is a NULL pointer
 *
 *****************************************************************************/
RESULT CamerIcIspCacGetConfig_ry
(
    CamerIcDrvHandle_ry_t              handle,
    CamerIcIspCacConfig_ry_t           *pConfig
);


/*****************************************************************************/
/**
 * @brief   This functions enables the CamerIC ISP CAC module.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspCacEnable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspCacDisable_ry()
 *
 * @brief   Disable CAC Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspCacDisable_ry
(
    CamerIcDrvHandle_ry_t handle
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
RESULT CamerIcIspCacIsEnabled_ry
(
    CamerIcDrvHandle_ry_t      handle,
    bool_t                  *pIsEnabled
);

RESULT CamerIcIspCacGetConfig_ry
(
    CamerIcDrvHandle_ry_t      handle,
    CamerIcIspCacConfig_ry_t   *pConfig
);

/*****************************************************************************/
/**
 * @brief   calculations for square, non-suare pixel mode and normalization 
 * values (non-square pixel sensor)
 *
 * @param   handle              CamerIc driver handle
 * @param   pConfig             Pointer to value to config context
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NULL_POINTER    pIsEnabled is NULL pointer
 *
 *****************************************************************************/
RESULT CamerIcIspCacComputeNsNf_ry(
    CamerIcDrvHandle_ry_t handle,
    CamerIcIspCacConfig_ry_t * pConfig
);
#ifdef __cplusplus
}
#endif

/* @} cameric_isp_cac_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_CAC_DRV_RY_API_H__ */

