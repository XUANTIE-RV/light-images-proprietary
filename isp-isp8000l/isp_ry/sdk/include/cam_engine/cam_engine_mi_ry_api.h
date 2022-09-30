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

/**
 * @cond    cam_engine_mi
 *
 * @file    cam_engine_mi_api.h
 *
 * @brief
 *
 *   Interface description of the CamEngine MI.
 *
 *****************************************************************************/
/**
 *
 * @defgroup cam_engine_mi_api CamEngine MI Api
 * @{
 *
 */

#ifndef __CAM_ENGINE_MI_RY_API_H__
#define __CAM_ENGINE_MI_RY_API_H__

#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif


#include <cameric_drv/cameric_mi_drv_ry_api.h>



/*****************************************************************************/
/**
 * @brief   This function enables/disables horizontal flip.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineOriginal_ry
(
    CamEngineHandle_ry_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function enables/disables horizontal flip.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineHorizontalFlip_ry
(
    CamEngineHandle_ry_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function enables/disables vertical flip.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineVerticalFlip_ry
(
    CamEngineHandle_ry_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function enables/disables rotation.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineRotateLeft_ry
(
    CamEngineHandle_ry_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function enables/disables rotation.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineRotateRight_ry
(
    CamEngineHandle_ry_t hCamEngine
);


#ifdef ISP_MI_HANDSHAKE_NANO
/*****************************************************************************/
/**
 * @brief   This function works for handshake buffer allocation.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   pHandshake          handle to the handshake struct pointer
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineMiHandshakeBufferAlloc_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamerIcMiMpHandshake_ry_t *pHandshake
);


/*****************************************************************************/
/**
 * @brief   Dump function for handshake ring buffer.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   pHandshake          handle to the handshake struct pointer
 * @param   dump_name           File name of dump file
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineMiHandshakeDumpBufToFile_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    CamerIcMiMpHandshake_ry_t *pHandshake,
    const char *            dump_name
);

/*****************************************************************************/
/**
 * @brief   This function works for handshake buffer free.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   pHandshake          handle to the handshake struct pointer
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineMiHandshakeBufferFreev
(
    CamEngineHandle_ry_t hCamEngine,
    CamerIcMiMpHandshake_ry_t *pHandshake
);


/*****************************************************************************/
/**
 * @brief   Dump function works for Fifo depth register value dump.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   dump_name           dump file name
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineMiFifoDepthDumpBufToFile_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    const char *            dump_name
);

#endif

/*****************************************************************************/
/**
 * @brief   Dump configure function works for MI MP media buffer dump.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   dump_name           dump file name
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NULL_POINTER    handle is NULL
 * @retval  RET_FAILURE         module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineMiMpDumpBufCfg_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    const char *            mp_dump_name
);

/*****************************************************************************/
/**
 * @brief   Dump configure function works for MI SP media buffer dump.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   dump_name           dump file name
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NULL_POINTER    handle is NULL
 * @retval  RET_FAILURE         module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineMiSpDumpBufCfg_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    const char *            sp_dump_name
);

/*****************************************************************************/
/**
 * @brief   Dump function works for MI MP media buffer dump to file.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   dump_name           dump file name
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NULL_POINTER    handle is NULL
 * @retval  RET_FAILURE         module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineMiMpDumpToFile_ry
(
    CamEngineHandle_ry_t       hCamEngine
);

/*****************************************************************************/
/**
 * @brief   Dump function works for MI SP media buffer dump to file.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   dump_name           dump file name
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NULL_POINTER    handle is NULL
 * @retval  RET_FAILURE         module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineMiSpDumpToFile_ry
(
    CamEngineHandle_ry_t       hCamEngine
);

RESULT CamEngineSetMiPpwLineNum_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    uint16_t            num
);

RESULT CamEngineGetMiPpwLineCnt_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    uint16_t            *pCnt
);

RESULT CamEngineGetMiPpwBufInfo_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    pp_write_line_entry_ry_t       *pp_wr_line_entry
);

RESULT CamEngineCfgMiPpDamLineEntry_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    uint16_t            bufNumber,
    uint16_t            lineNumber,
    uint64_t            bufAddr
);
#ifdef ISP_DEC
//#ifdef HAL_CMODEL
RESULT CamEngineMiMpCmpDumpToFile_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    char* 					dstFileName
);

//#endif
#endif


#ifdef __cplusplus
}
#endif

/* @} cam_engine_mi_api */

#endif /* __CAM_ENGINE_MI_RY_API_H__ */


