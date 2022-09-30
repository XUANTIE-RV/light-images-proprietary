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

#ifndef __CAMERIC_ISP_DEC_DRV_API_H__
#define __CAMERIC_ISP_DEC_DRV_API_H__

/**
 * @file    cameric_isp_dec_drv_api.h
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
#include "cameric_isp_drv_api.h"
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 *
 *          CamerIcIspDecStreamCfg_t
 *
 * @brief
 *
 */
 typedef struct CamerIcIspDecStreamCfg_s
{

    CamerIcIspDecWriteConfig_t decWriteConfig;
    CamerIcIspDecWriteExConfig_t decWriteExConfig;
    CamerIcIspDecReadConfig_t decReadConfig;
    CamerIcIspDecReadExConfig_t decReadExConfig;
    uint32_t baseAddr;
    uint32_t endAddr;

    uint32_t cacheBaseAddr;
    uint32_t flushAddr;


} CamerIcIspDecStreamCfg_t;

#define MAX_STREAM 32

/*******************************************************************************
 *
 *          CamerIcIspDecContext_t
 *
 * @brief
 *
 */
typedef struct CamerIcIspDecContext_s
{
    bool_t                          enabled;
    bool_t                          cfgUpdate;

    CamerIcIspDecWriteConfig_t           writeConfig;
    CamerIcIspDecWriteExConfig_t         writeExConfig;
    CamerIcIspDecReadConfig_t            readConfig;
    CamerIcIspDecReadExConfig_t          readExConfig;
	CamerIcIspDecStreamCfg_t         decStreamCfg[MAX_STREAM];
    uint16_t                       streamIdMask;


} CamerIcIspDecContext_t;
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
extern RESULT CamerIcIspDecEnable
(
    CamerIcDrvHandle_t handle
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
extern RESULT CamerIcIspDecDisable
(
    CamerIcDrvHandle_t handle
);


/*****************************************************************************/
/**
 *          CamerIcIspDecControl()
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
RESULT CamerIcIspDecControl
(
    CamerIcDrvHandle_t      handle,
    CamerIcIspDecControl_t *pDecControl,
    CamerIcIspDecControl_ex_t *pDecControlEx,
    CamerIcIspDecControl_ex2_t *pDecControlEx2

);

/*****************************************************************************/
/**
 *          CamerIcIspDecIntrEnbl()
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
RESULT CamerIcIspDecIntrEnbl
(
    CamerIcDrvHandle_t      handle,
    uint32_t  intrEnblVec,
    uint32_t  intrEnblExVec,
    uint32_t  intrEnblEx2Vec

);

/*****************************************************************************/
/**
 *          CamerIcIspDecWriteConfig()
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
RESULT CamerIcIspDecWriteConfig
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    CamerIcIspDecWriteConfig_t  *pDecWriteConfig,
    CamerIcIspDecWriteExConfig_t  *pDecWriteExConfig

);

/*****************************************************************************/
/**
 *          CamerIcIspDecReadConfig()
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
RESULT CamerIcIspDecReadConfig
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    CamerIcIspDecReadConfig_t  *pDecReadConfig,
    CamerIcIspDecReadExConfig_t  *pDecReadExConfig

);

/*****************************************************************************/
/**
 *          CamerIcIspDecWriteBufferBase()
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
RESULT CamerIcIspDecWriteBufferBase
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    uint32_t                baseAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecWriteBufferEnd()
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
RESULT CamerIcIspDecWriteBufferEnd
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    uint32_t                endAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecReadBufferBase()
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
RESULT CamerIcIspDecReadBufferBase
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    uint32_t                baseAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecReadBufferEnd()
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
RESULT CamerIcIspDecReadBufferEnd
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    uint32_t                endAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecWriteCacheBase()
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
RESULT CamerIcIspDecWriteCacheBase
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    uint32_t                baseAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecReadCacheBase()
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
RESULT CamerIcIspDecReadCacheBase
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    uint32_t                baseAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecWriteFlushCache()
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
RESULT CamerIcIspDecWriteFlushCache
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    uint32_t                cacheAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecReadFlushCache()
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
RESULT CamerIcIspDecReadFlushCache
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    uint32_t                cacheAddress

);

/*****************************************************************************/
/**
 *          CamerIcIspDecCfg()
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

RESULT CamerIcIspDecCfg
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    CamerIcIspDecStreamCfg_t*   pDecStreamCfg
);

/*****************************************************************************/
/**
 *          CamerIcIspDecWriteAddrCfg()
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

RESULT CamerIcIspDecWriteAddrCfg
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    CamerIcIspDecStreamCfg_t*   pDecStreamCfg

);

/*****************************************************************************/
/**
 *          CamerIcIspDecIsEnabled()
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

bool CamerIcIspDecIsEnabled
(
    CamerIcDrvHandle_t      handle
);

/*****************************************************************************/
/**
 *          CamerIcIspDecReadAddrCfg()
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

RESULT CamerIcIspDecReadAddrCfg
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId,
    CamerIcIspDecStreamCfg_t*   pDecStreamCfg

);

RESULT CamerIcIspDecReadUpdateAddr
(
    CamerIcDrvHandle_t      handle,
    uint8_t                 streamId
);


#ifdef __cplusplus
}
#endif

/* @} cameric_isp_dec_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_DEC_DRV_API_H__ */


