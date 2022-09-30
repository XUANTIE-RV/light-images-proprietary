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

#ifndef __CAMERIC_ISP_DEC_DRV_RY_API_H__
#define __CAMERIC_ISP_DEC_DRV_RY_API_H__

/**
 * @file    cameric_isp_dec_drv_ry_api.h
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
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>
#include "cameric_isp_drv_ry_api.h"
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 *
 *          CamerIcIspDecStreamCfg_ry_t
 *
 * @brief
 *
 */
 typedef struct CamerIcIspDecStreamCfg_ry_s
{

    CamerIcIspDecWriteConfig_ry_t decWriteConfig;
    CamerIcIspDecWriteExConfig_ry_t decWriteExConfig;
    CamerIcIspDecReadConfig_ry_t decReadConfig;
    CamerIcIspDecReadExConfig_ry_t decReadExConfig;
    uint32_t baseAddr;
    uint32_t endAddr;

    uint32_t cacheBaseAddr;
    uint32_t flushAddr;


} CamerIcIspDecStreamCfg_ry_t;

#define MAX_STREAM 32

/*******************************************************************************
 *
 *          CamerIcIspDecContext_ry_t
 *
 * @brief
 *
 */
typedef struct CamerIcIspDecContext_ry_s
{
    bool_t                          enabled;
    bool_t                          cfgUpdate;

    CamerIcIspDecWriteConfig_ry_t           writeConfig;
    CamerIcIspDecWriteExConfig_ry_t         writeExConfig;
    CamerIcIspDecReadConfig_ry_t            readConfig;
    CamerIcIspDecReadExConfig_ry_t          readExConfig;
	CamerIcIspDecStreamCfg_ry_t         decStreamCfg[MAX_STREAM];
    uint16_t                       streamIdMask;


} CamerIcIspDecContext_ry_t;
/*****************************************************************************/
/**
 * @brief   This function enable the ISP DEC module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspDecEnable_ry
(
    CamerIcDrvHandle_ry_t handle
);

/*****************************************************************************/
/**
 * @brief   This function enable the ISP DEC module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspDecDisable_ry
(
    CamerIcDrvHandle_ry_t handle
);


/*****************************************************************************/
/**
 *          CamerIcIspDecControl_ry()
 *
 * @brief   Config DEC global control
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspDecControl_ry
(
    CamerIcDrvHandle_ry_t      handle,
    CamerIcIspDecControl_ry_t *pDecControl,
    CamerIcIspDecControl_ex_ry_t *pDecControlEx,
    CamerIcIspDecControl_ex2_ry_t *pDecControlEx2

);

/*****************************************************************************/
/**
 *          CamerIcIspDecIntrEnbl_ry()
 *
 * @brief   Enable DEC interrupt
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspDecIntrEnbl_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint32_t  intrEnblVec,
    uint32_t  intrEnblExVec,
    uint32_t  intrEnblEx2Vec

);

/*****************************************************************************/
/**
 *          CamerIcIspDecWriteConfig_ry()
 *
 * @brief   Config DEC format, bitDepth, tileMode, alignSize, etc.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspDecWriteConfig_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    CamerIcIspDecWriteConfig_ry_t  *pDecWriteConfig,
    CamerIcIspDecWriteExConfig_ry_t  *pDecWriteExConfig

);

/*****************************************************************************/
/**
 *          CamerIcIspDecReadConfig_ry()
 *
 * @brief   Config DEC format, bitDepth, tileMode, alignSize, etc.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspDecReadConfig_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    CamerIcIspDecReadConfig_ry_t  *pDecReadConfig,
    CamerIcIspDecReadExConfig_ry_t  *pDecReadExConfig

);

/*****************************************************************************/
/**
 *          CamerIcIspDecWriteBufferBase_ry()
 *
 * @brief   Config DEC write buffer base address.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspDecWriteBufferBase_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    uint32_t                baseAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecWriteBufferEnd_ry()
 *
 * @brief   Config DEC write buffer end address.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspDecWriteBufferEnd_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    uint32_t                endAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecReadBufferBase_ry()
 *
 * @brief   Config DEC read buffer base address.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspDecReadBufferBase_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    uint32_t                baseAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecReadBufferEnd_ry()
 *
 * @brief   Config DEC read buffer end address.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspDecReadBufferEnd_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    uint32_t                endAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecWriteCacheBase_ry()
 *
 * @brief   Config DEC write cache base address.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspDecWriteCacheBase_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    uint32_t                baseAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecReadCacheBase_ry()
 *
 * @brief   Config DEC read cache base address.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspDecReadCacheBase_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    uint32_t                baseAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecWriteFlushCache_ry()
 *
 * @brief   Config DEC write flush cache address.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspDecWriteFlushCache_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    uint32_t                cacheAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecReadFlushCache_ry()
 *
 * @brief   Config DEC read flush cache address.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT CamerIcIspDecReadFlushCache_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    uint32_t                cacheAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecCfg_ry()
 *
 * @brief   Config DEC stream.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/

RESULT CamerIcIspDecCfg_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    CamerIcIspDecStreamCfg_ry_t*   pDecStreamCfg
);

/*****************************************************************************/
/**
 *          CamerIcIspDecWriteAddrCfg_ry()
 *
 * @brief   enable DEC compress.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/

RESULT CamerIcIspDecWriteAddrCfg_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    CamerIcIspDecStreamCfg_ry_t*   pDecStreamCfg

);

/*****************************************************************************/
/**
 *          CamerIcIspDecIsEnabled_ry()
 *
 * @brief   Is  DEC enabled compress?
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/

bool CamerIcIspDecIsEnabled_ry
(
    CamerIcDrvHandle_ry_t      handle
);

/*****************************************************************************/
/**
 *          CamerIcIspDecReadAddrCfg_ry()
 *
 * @brief   enable DEC compress.
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_WRONG_HANDLE
 *
 *****************************************************************************/

RESULT CamerIcIspDecReadAddrCfg_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId,
    CamerIcIspDecStreamCfg_ry_t*   pDecStreamCfg

);

RESULT CamerIcIspDecReadUpdateAddr_ry
(
    CamerIcDrvHandle_ry_t      handle,
    uint8_t                 streamId
);


#ifdef __cplusplus
}
#endif

/* @} cameric_isp_dec_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_DEC_DRV_RY_API_H__ */


