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

#ifndef __CAMERIC_ISP_COMPAND_DRV_API_H__
#define __CAMERIC_ISP_COMPAND_DRV_API_H__

/**
 * @file    cameric_isp_compand_drv_api.h
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

struct CamericIspBlsContext {
	uint8_t  bit_width;
	bool     enable;
	uint32_t a;
	uint32_t b;
	uint32_t c;
	uint32_t d;
};
/*****************************************************************************/
/**
 *          CamerIcIspCmpdSetCurve()
 *
 * @brief   init compand Module
 *
 * @param   handle          CamerIc driver handle
 * @param   xData           pointer to xData
 * @param   yData           pointer to yData
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspCmpdSetCurve
(
    CamerIcDrvHandle_t handle,
    uint32_t*          xData,
    uint32_t*          yData
);

/*****************************************************************************/
/**
 *          CamerIcIspCmpdEnable()
 *
 * @brief   Enable compand Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspCmpdEnable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspCmpdDisable()
 *
 * @brief   Disable compand Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspCmpdDisable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspCmpdSetTbl()
 *
 * @brief   set compand expand table and compress table.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspCmpdSetTbl
(
    CamerIcDrvHandle_t  handle,
    const int          *pExpandTbl,
    const int          *pCompressTbl
);



/*****************************************************************************/
/**
 *          CamerIcIspCmpdConfig()
 *
 * @brief   Config compand module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspCmpdConfig
(
    CamerIcDrvHandle_t  handle,
    void * pExpandParam,
    void * pCompressParam,
    void * pBlsParam
);


/*****************************************************************************/
/**
 *          CamerIcIspCompandConfig()
 *
 * @brief   Config compand module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspCompandConfig
(
    CamerIcDrvHandle_t  handle,
    bool_t              compressEnable,
    bool_t              expandEnable,
    struct CamericIspBlsContext  *pBlsPara
);



/*****************************************************************************/
/**
 * @brief   This function sets the fixed black level substraction values
 *          for the color channels.
 *
 * @note    The assignment of the values for A, B, C and D to R, G, G and B
 *          pattern depends on the position and offset of the input acquisition
 *          window.
 *
 *          The position [0,0] is always assigned to A, correlatively [0,1]
 *          is assigned to B, [1,0] to C and [1,1] to D.
 *
 * @param   handle              CamerIc driver handle
 * @param   A                   black-level substraction value A
 * @param   B                   black-level substraction value B
 * @param   C                   black-level substraction value C
 * @param   D                   black-level substraction value D
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_CONFIG    a bayer-pattern was not configured
 * @retval  RET_OUTOFRANGE      substraction value is to large
 *
 *****************************************************************************/
extern RESULT CamerIcIspCompandBlsSetBlackLevel
(
    CamerIcDrvHandle_t  handle,
    const uint16_t      isp_bls_a_fixed,
    const uint16_t      isp_bls_b_fixed,
    const uint16_t      isp_bls_c_fixed,
    const uint16_t      isp_bls_d_fixed
);



/*****************************************************************************/
/**
 * @brief   This function reads out the current configured fixed black level
 *          substraction values.
 *
 * @note    The assignment of the values for A, B, C and D to R, G, G and B
 *          pattern depends on the position and offset of the input acquisition
 *          window.
 *
 *          The position [0,0] is always assigned to A, correlatively [0,1]
 *          is assigned to B, [1,0] to C and [1,1] to D.
 *
 * @param   handle              CamerIc driver handle
 * @param   A                   pointer to store the black-level substraction value A
 * @param   B                   pointer to store the black-level substraction value B
 * @param   C                   pointer to store the black-level substraction value C
 * @param   D                   pointer to store the black-level substraction value D
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
extern RESULT CamerIcIspCompandBlsGetBlackLevel
(
    CamerIcDrvHandle_t  handle,
    uint16_t            *isp_bls_a_fixed,
    uint16_t            *isp_bls_b_fixed,
    uint16_t            *isp_bls_c_fixed,
    uint16_t            *isp_bls_d_fixd
);

/******************************************************************************
 * CamerIcIspCompandBlsEnable()
 *****************************************************************************/
extern RESULT CamerIcIspCompandBlsEnable
(
    CamerIcDrvHandle_t  handle
);

/******************************************************************************
 * CamerIcIspCompandBlsDisable()
 *****************************************************************************/
RESULT CamerIcIspCompandBlsDisable
(
    CamerIcDrvHandle_t  handle
);

/******************************************************************************
 * CamerIcIspCompandExpandEnable()
 *****************************************************************************/
extern RESULT CamerIcIspCompandExpandEnable
(
    CamerIcDrvHandle_t  handle
);

/******************************************************************************
 * CamerIcIspCompandExpandDisable()
 *****************************************************************************/
extern RESULT CamerIcIspCompandExpandDisable
(
    CamerIcDrvHandle_t  handle
);

/******************************************************************************
 * CamerIcIspCompandCompressEnable()
 *****************************************************************************/
extern RESULT CamerIcIspCompandCompressEnable
(
    CamerIcDrvHandle_t  handle
);

/******************************************************************************
 * CamerIcIspCompandCompressDisable()
 *****************************************************************************/
extern RESULT CamerIcIspCompandCompressDisable
(
    CamerIcDrvHandle_t  handle
);

#ifdef __cplusplus
}
#endif



#endif /* __CAMERIC_ISP_COMPAND_DRV_API_H__ */

