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

#ifndef __CAMERIC_ISP_RGBIR_DRV_RY_API_H__
#define __CAMERIC_ISP_RGBIR_DRV_RY_API_H__

/**
 * @file    cameric_isp_rgbir_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC ISP WDR driver API definitions.
 *
 *****************************************************************************/
/**
 * @cond cameric_isp_rgbir
 *
 * @defgroup cameric_isp_rgbir_drv_api CamerIC ISP RGBIR Driver API definitions
 * @{
 *
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum CamerIcRgbirOutBpt_ry_e {
    CAMERA_IC_RGBIR_OUT_BPT_RGGB = 0,
    CAMERA_IC_RGBIR_OUT_BPT_GRBG,
    CAMERA_IC_RGBIR_OUT_BPT_GBRG,
    CAMERA_IC_RGBIR_OUT_BPT_BGGR,
} CamerIcRgbirOutBpt_ry_t;

typedef enum CamerIcRgbirBpt_ry_e{
    CAMERA_IC_RGBIR_BPT_BGGIR= 0,
    CAMERA_IC_RGBIR_BPT_GRIRG,
    CAMERA_IC_RGBIR_BPT_RGGIR,
    CAMERA_IC_RGBIR_BPT_GBIRG,
    CAMERA_IC_RGBIR_BPT_GIRRG,
    CAMERA_IC_RGBIR_BPT_IRGGB,
    CAMERA_IC_RGBIR_BPT_GIRBG,
    CAMERA_IC_RGBIR_BPT_IRGGR,
    CAMERA_IC_RGBIR_BPT_RGIRB,
    CAMERA_IC_RGBIR_BPT_GRBIR,
    CAMERA_IC_RGBIR_BPT_IRBRG,
    CAMERA_IC_RGBIR_BPT_BIRGR,
    CAMERA_IC_RGBIR_BPT_BGIRR,
    CAMERA_IC_RGBIR_BPT_GBRIR,
    CAMERA_IC_RGBIR_BPT_IRRBG,
    CAMERA_IC_RGBIR_BPT_RIRGB, 
} CamerIcRgbirBpt_ry_t;

typedef enum CamerIcRgbirFiltMode_ry_e{
    CAMERA_IC_RGBIR_GREEN_FILT_STATIC= 0,
    CAMERA_IC_RGBIR_GREEN_FILT_DYNAMIC,
} CamerIcRgbirFiltMode_ry_t;

typedef struct CamerIcIspRgbirConfig_ry_s {
    bool_t part1Enable;
    bool_t part2Enable;
    uint8_t dmscThreshold;
    uint8_t stageSelect;
    CamerIcRgbirOutBpt_ry_t outRgbBpt;
    CamerIcRgbirBpt_ry_t rgbirBpt;
    CamerIcRgbirFiltMode_ry_t filtMode;
    bool filtEnable;

    uint16_t ir_threshold, l_threshold;
    uint16_t bls_r, bls_g, bls_b, bls_ir;
    double gain_r, gain_g, gain_b;
    double cc_mtx[12];
    double ir_sigmas;
    uint16_t width, height;
} CamerIcIspRgbirConfig_ry_t;


/*****************************************************************************/
/**
 *          CamerIcIspRgbirEnable_ry()
 *
 * @brief   Enable RGBIR Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspRgbirEnable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspRgbirDisable_ry()
 *
 * @brief   Disable RGBIR Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspRgbirDisable_ry
(
    CamerIcDrvHandle_ry_t handle
);


/*****************************************************************************/
/**
*          CamerIcIspRgbirConfig_ry()
*
* @brief   Config RGBIR Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspRgbirConfig_ry
(
	CamerIcDrvHandle_ry_t 		handle,
    CamerIcIspRgbirConfig_ry_t  *pRgbirCfg
);

/*****************************************************************************/
/**
*          CamerIcIspRgbirSetIrRawOut_ry()
*
* @brief   set RGBIR Module ir raw output
*
* @param   handle          CamerIc driver handle
* @param   enable           rgbir ir raw output enable.
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspRgbirSetIrRawOut_ry
(
    CamerIcDrvHandle_ry_t handle,
    bool               enable
);

#ifdef __cplusplus
}
#endif



#endif /* __CAMERIC_ISP_RGBIR_DRV_RY_API_H__ */


