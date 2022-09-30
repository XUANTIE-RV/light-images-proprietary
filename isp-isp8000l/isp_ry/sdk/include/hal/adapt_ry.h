/******************************************************************************\
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

/*******************************************************************************
 * @file adapt.h
 *
 * @brief   adapter Layer for isp
 *
 *          This header file exports
 *
 *
 * @note
 *
 *****************************************************************************/

#ifndef __ADATPT_H__
#define __ADATPT_H__

#include <ebase/types_ry.h>
#include <ebase/dct_assert_ry.h>
//#include <ebase/trace_ry.h>
#include <common/return_codes_ry.h>

#include "oslayer/oslayer_ry.h"

/* Set this macro to 1 enable register dump. */
#define ENABLE_REGISTER_DUMP 0

/******************************************************************************
 * local macro definitions
 *****************************************************************************/
#define SEARCH_V4L2_DEV_NUM_MAX      20
#define SEARCH_V4L2_SUB_DEV_NUM_MAX  20
#define SENSOR_NAME_SIZE_MAX         16
#define SENSOR_DRV_NAME_SIZE_MAX     128
#define SENSOR_CALIB_NAME_SIZE_MAX   128

#define SENSOR_ADAPT_MODE_MAX        20

#define DW_NAME_SIZE_MAX        16

/******************************************************************************
 * local enum definitions
 *****************************************************************************/
typedef enum AdaptModule_s
{
    ADAPT_MODULE_VIDEO   = 0x01,//!<video in V4L2
    ADAPT_MODULE_ISP     = 0x02,//!<ISP
    ADAPT_MODULE_VIN     = 0x04,//!<VIN:mipi-csi2 dvp bt656 bt601
    ADAPT_MODULE_SENSOR  = 0x08,//!<Sensor
    ADAPT_MODULE_SOC     = 0x10,//!<SoC
}AdaptModule_e;

typedef enum AdaptChId_s
{
    ADAPT_CH_ID0 = 0, //!<isp channel id 0.
    ADAPT_CH_ID1 = 1, //!<isp channel id 1.
    ADAPT_CH_NUM      //!<isp channel numbers.
}AdaptChId_e;

typedef enum AdaptDrvMode_s
{
    ADAPT_DRV_MODE_AUTO   = 0,//!<Automatic detect mode(reserved)
    ADAPT_DRV_MODE_NATIVE = 1,//!<native driver mode
    ADAPT_DRV_MODE_V4L2   = 2,//!<v4l2 driver mode
}AdaptDrvMode_e;

typedef enum AdaptVinType_s
{
    ADAPT_VIN_TYPE_MIPI   = 0,//!<connect mipi with vin
    ADAPT_VIN_TYPE_DVP    = 1,//!<connect dvp with vin
    ADAPT_VIN_TYPE_BT656  = 2,//!<connect bt656 with vin
    ADAPT_VIN_TYPE_BT601  = 3,//!<connect bt601 with vin
}AdaptVinType_e;

/******************************************************************************
 * local type definitions
 *****************************************************************************/


/******************************************************************************
 * Contexts for modules in adepter layer
 *****************************************************************************/
typedef struct AdaptIspContext_s
{
    int32_t        ispFd;  //!< file descriptor of ISP deivce
    //AdaptChId_e    ispID;  //!< current id/channel index of ISP device
} AdaptIspContext_t;

typedef struct AdaptSensorInfo_s
{
    char  *pSensorName;
    char  *pSensorDrvName;
    char  *pSensorCalibXmlName;
    uint32_t sensorDefaultMode;
    uint32_t sensorCurrMode;
}AdaptSensorInfo_t;

typedef struct AdaptSensorModeConfig_s
{
    uint32_t      mode;
    char          sensorCalibXmlName[SENSOR_CALIB_NAME_SIZE_MAX];
}AdaptSensorModeConfig_t;

typedef struct AdaptSensorContext_s
{
    int32_t                 sensorFd;  //!< file descriptor of sensor deivce
    uint8_t                 i2cBusID;  //!< current i2c dev id which is shown as /dev/i2c-0  /dev/i2c-1...
    char                    sensorName[SENSOR_NAME_SIZE_MAX];
    char                    sensorDrvName[SENSOR_DRV_NAME_SIZE_MAX];
    uint8_t                 modeCount;
    AdaptSensorModeConfig_t sensorModeConfig[SENSOR_ADAPT_MODE_MAX];
    uint8_t                 ModeLock;
    uint32_t                sensorDefaultMode;
    uint32_t                sensorCurrMode;
} AdaptSensorContext_t;

typedef struct AdaptVinContext_s
{
    int32_t         vinFd;  //!< file descriptor of vin deivce
    AdaptChId_e     vinID;//!<current channel id of mipi csi which is connectted with isp
    AdaptVinType_e  vinType;//!< interface type of video input
} AdaptVinContext_t;

typedef struct AdaptContext_s
{
    AdaptDrvMode_e        drvMode; //!< driver mode: native or v4l2
    AdaptChId_e           currChID;//!< current channel id of adapter<==>isp

    AdaptIspContext_t     ispCtx;
    AdaptSensorContext_t  sensorCtx;
    AdaptVinContext_t     vinCtx;
    int32_t               socFd;
    int32_t               v4l2VideoFd; //!< only vaild in v4l2 mode(open /dev/videoX), others as -1

    osMutex               modMutex; //!< common short term mutex; e.g. for read-modify-write accesses

} AdaptContext_t;

/******************************************************************************
 * open parameters for adepter layer
 *****************************************************************************/
typedef struct AdaptOpenParam_s
{
    AdaptDrvMode_e        drvMode;  //!< isp driver mode: native or v4l2
    AdaptChId_e           openChID; //!< adapter channel ID
    AdaptVinType_e        vinType;  //!< interface type of video input
    char                 *pSensorCfgFile; //!<path of sensor cfg from isi layer
} AdaptOpenParam_t;
/*****************************************************************************/
/**
 * @brief   handle to adapt instance
 *****************************************************************************/
/*******AdaptContext_t *;   */
typedef void * AdaptHandle_t;


/******************************************************************************
 * common internal stuff; may be used externally as well
 *****************************************************************************/

/******************************************************************************
 * @brief
 * @return
 * @note
 *****************************************************************************/



#ifdef __cplusplus
extern "C"
{
#endif

AdaptHandle_t AdaptOpen_ry(AdaptOpenParam_t *pOpenParams);
RESULT AdaptClose(AdaptHandle_t adaptHandle);
int32_t AdaptGetFd(AdaptHandle_t adaptHandle, AdaptModule_e module);
RESULT AdaptGetDrvMode(AdaptHandle_t adaptHandle, AdaptDrvMode_e  *pDrvMode);
RESULT AdaptIoctl(AdaptHandle_t adaptHandle, AdaptModule_e module, unsigned int cmd, void *args);
RESULT AdaptGetSensorInfo(AdaptHandle_t adaptHandle, AdaptSensorInfo_t *pSensorInfo);
RESULT AdaptSetSensorMode(AdaptHandle_t adaptHandle, uint32_t currMode);
RESULT AdaptSetSensorCalibXmlName(AdaptHandle_t adaptHandle, const char * CalibXmlName);
RESULT AdaptSensorModeLock(AdaptHandle_t adaptHandle);

#ifdef __cplusplus
}
#endif

#endif /* __ADATPT_H__ */
