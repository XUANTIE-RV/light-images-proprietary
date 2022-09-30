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

#ifndef __CAMERIC_ISP_COLOR_ADJUST_DRV_API_H__
#define __CAMERIC_ISP_COLOR_ADJUST_DRV_API_H__

/**
 * @cond    cameric_isp_color_adjust
 *
 * @file    cameric_isp_color_adjust_drv_api.h
 *
 * @brief   This file contains the CamerIC ISP COLOR_ADJUST  Driver
 *          API definitions
 *
 *****************************************************************************/
/**
 * @defgroup cameric_isp_color_adjust_drv_api CamerIC ISP COLOR_ADJUST Driver API definitions
 *
 *
 */
#include <ebase/types.h>
#include <common/return_codes.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define CA_CURVE_DATA_TABLE_LEN  65

typedef struct CamerIcIspCa_s
{
    bool enable;
    unsigned char caMode;
    unsigned short CaLutXTbl[ CA_CURVE_DATA_TABLE_LEN ];
    unsigned short CaLutLumaTbl[ CA_CURVE_DATA_TABLE_LEN ];
    unsigned short CaLutChromaTbl[ CA_CURVE_DATA_TABLE_LEN ];
    unsigned short CaLutShiftTbl[ CA_CURVE_DATA_TABLE_LEN ];

} CamerIcIspCa_t;

/*****************************************************************************/
/**
 * @brief   This functions enables the CamerIC color adjust
 *           module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspCaEnable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This functions disables the CamerIC color adjust
 *            module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspCaDisable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   Get CamerIC color adjust module status.
 *
 * @param   handle          CamerIc driver handle.
 * @param   pIsEnabled
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
extern RESULT CamerIcIspCaIsEnabled
(
    CamerIcDrvHandle_t      handle,
    bool_t                  *pIsEnabled
);

extern RESULT CamerIcIspCaConfig
(
    CamerIcDrvHandle_t      handle,
    CamerIcIspCa_t  *pCfg
);

extern RESULT CamerIcIspCaGetConfig
(
    CamerIcDrvHandle_t      handle,
    CamerIcIspCa_t *pCfg
);

extern RESULT CamerIcIspUpdateDciCurve
(
    CamerIcDrvHandle_t      handle,
    int *curve
);


#ifdef __cplusplus
}
#endif

/* @} cameric_isp_color_adjust_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_COLOR_ADJUST_DRV_API_H__ */



