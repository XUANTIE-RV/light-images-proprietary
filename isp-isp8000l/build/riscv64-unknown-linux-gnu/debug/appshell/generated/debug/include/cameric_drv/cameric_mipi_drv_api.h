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

#ifndef __CAMERIC_MIPI_DRV_API_H__
#define __CAMERIC_MIPI_DRV_API_H__

/**
 * @cond    cameric_mipi
 *
 * @file    cameric_mipi_drv_api.h
 *
 * @brief   This file contains the CamerIC ISP MIPI driver API definitions.
 *
 *****************************************************************************/
/**
 * @defgroup cameric_mipi_drv_api CamerIC MIPI driver API definitions
 * @{
 *
 */
#include <ebase/types.h>

#include <common/mipi.h>
#include <common/return_codes.h>



#ifdef __cplusplus
extern "C"
{
#endif



/*****************************************************************************/
/**
 * @brief   This function enables CamerIC MIPI module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcMipiEnable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function disables CamerIC MIPI module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcMipiDisable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the status of the mipi module.
 *
 * @param   handle              CamerIc driver handle.
 * @param   pIsEnabled          Pointer to value to store current state
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NULL_POINTER    pIsEnabled is a NULL pointer.
 *
 *****************************************************************************/
extern RESULT CamerIcMipiIsEnabled
(
    CamerIcDrvHandle_t      handle,
    bool_t                  *pIsEnabled
);



/*****************************************************************************/
/**
 * @brief   This function returns the number of currently used MIPI lanes.
 *
 * @param   handle              CamerIc driver handle.
 * @param   no_lanes            number of MIPI lanes to use (1..4)
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_INVALID_PARM    no_lanes is a NULL pointer.
 *
 *****************************************************************************/
extern RESULT CamerIcMipiGetNumberOfLanes
(
    CamerIcDrvHandle_t  handle,
    uint32_t            *no_lanes
);



/*****************************************************************************/
/**
 * @brief   This function sets the number of MIPI lanes to use.
 *
 * @param   handle              CamerIC driver handle.
 * @param   no_lanes            Number of MIPI lanes to use (1..4)
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_OUTOFRANGE      number of lanes is out of range.
 *
 *****************************************************************************/
extern RESULT CamerIcMipiSetNumberOfLanes
(
    CamerIcDrvHandle_t  handle,
    const uint32_t      no_lanes
);



/*****************************************************************************/
/**
 * @brief   This function sets the MIPI virtual channel and data type of the
 *          packages to process.
 *
 * @param   handle              CamerIC driver handle.
 * @param   vc                  virtul channel number
 * @param   dt                  data type of image data
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_BUSY            module is currently in use.
 * @retval  RET_OUTOFRANGE      at least one config parameter is invalid
 * @retval  RET_NOTSUPP         at least one config parameter is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcMipiSetVirtualChannelAndDataType
(
    CamerIcDrvHandle_t          handle,
    const MipiVirtualChannel_t  vc,
    const MipiDataType_t        dt
);


/*****************************************************************************/
/**
 * @brief   This function sets the MIPI compression scheme and predictor block.
 *
 * @param   handle              CamerIC driver handle.
 * @param   cs                  compression scheme
 * @param   pred                predictor block
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_BUSY            module is currently in use.
 * @retval  RET_OUTOFRANGE      at least one config parameter is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcMipiSetCompressionSchemeAndPredictorBlock
(
    CamerIcDrvHandle_t                  handle,
    const MipiDataCompressionScheme_t   cs,
    const MipiPredictorBlock_t          pred
);


/*****************************************************************************/
/**
 * @brief   This function enables compressed data processing.
 *
 * @param   handle              CamerIC driver handle.
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_BUSY            module is currently in use
 * @retval  RET_WRONG_CONFIG    at least one config parameter set before is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcMipiEnableCompressedMode
(
    CamerIcDrvHandle_t  handle
);


/*****************************************************************************/
/**
 * @brief   This function disables compressed data processing.
 *
 * @param   handle              CamerIC driver handle.
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_BUSY            module is currently in use
 *
 *****************************************************************************/
extern RESULT CamerIcMipiDisableCompressedMode
(
    CamerIcDrvHandle_t  handle
);


/*****************************************************************************/
/**
 * @brief   This function returns the status of the compressed data processing mode.
 *
 * @param   handle              CamerIc driver handle.
 * @param   pIsEnabled          Pointer to value to store current state
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NULL_POINTER    pIsEnabled is a NULL pointer
 *
 *****************************************************************************/
extern RESULT CamerIcMipiIsEnabledCompressedMode
(
    CamerIcDrvHandle_t  handle,
    bool_t              *pIsEnabled
);


#ifdef __cplusplus
}
#endif

/* @} cameric_mipi_drv_api */

/* @endcond */

#endif /* __CAMERIC_MIPI_DRV_API_H__ */

