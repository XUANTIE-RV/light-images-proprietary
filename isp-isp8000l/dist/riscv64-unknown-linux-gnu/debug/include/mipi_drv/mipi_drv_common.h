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
 * @file mipi_drv_common.h
 *
 * @brief   Definition of MIPI driver stuff common to API and internal implementation.
 *
 *****************************************************************************/

#ifndef __MIPI_DRV_COMMON_H__
#define __MIPI_DRV_COMMON_H__

#include <ebase/types.h>
#include <common/return_codes.h>
#include <common/mipi.h>

#include <hal/hal_api.h>

#ifdef MIPI_USE_CAMERIC
    #include <cameric_drv/cameric_drv_api.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/**
 * @brief   Max number of MIPI lanes supported by driver.
 *
 *****************************************************************************/
#define MAX_NUMBER_OF_MIPI_LANES     4


/******************************************************************************/
/**
 * @brief Handle to MIPI driver context.
 *
 ******************************************************************************/
typedef struct MipiDrvContext_s *MipiDrvHandle_t;


/******************************************************************************/
/**
 * @brief MIPI config data structure.
 *
 ******************************************************************************/
typedef struct MipiConfig_s
{
    uint32_t                        NumLanes;       //!< Number of MIPI lanes to use.
    MipiVirtualChannel_t            VirtChannel;    //!< Virtual channel to use.
    MipiDataType_t                  DataType;       //!< Type of data to be exchanged.
    MipiDataCompressionScheme_t     CompScheme;     //!< Compression scheme to use.
    MipiPredictorBlock_t            PredBlock;      //!< Predictor block to use.
} MipiConfig_t;

/******************************************************************************/
/**
 * @brief   MIPI driver configuration structure
 *
 ******************************************************************************/
typedef struct MipiDrvConfig_s
{
    int                 fd;
    uint32_t            InstanceNum;        //!< Zero based number of instance of MIPI module to use.

    HalHandle_t         HalHandle;          //!< HAL session to use for HW access.

    MipiDrvHandle_t     MipiDrvHandle;      //!< Handle to created MIPI driver context, set by @ref MipiDrvInit if successfull, undefined otherwise.

#ifdef MIPI_USE_CAMERIC
    CamerIcDrvHandle_t  CamerIcDrvHandle;   //!< Handle to existing CamerIc driver instance, only required if CamerIc MIPI module is in use, set to NULL otherwise; @note Must be valid for the whole lifetime of this driver instance!
#endif
} MipiDrvConfig_t;


#ifdef __cplusplus
}
#endif

#endif /* __MIPI_DRV_COMMON_H__ */
