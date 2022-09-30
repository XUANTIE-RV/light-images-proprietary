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

#ifndef _CAMERA_DEVICE_SENSOR_DEFS_H_
#define _CAMERA_DEVICE_SENSOR_DEFS_H_

#include "types.h"

typedef struct IsiResolution_s
{
    uint16_t width;
    uint16_t height;
}IsiResolution_t;

/*****************************************************************************/
/**
 * @brief   This structure defines the sensor capabilities.
 */
/*****************************************************************************/
typedef struct IsiSensorCaps_s {
    uint32_t BusWidth;                  /**< supported bus-width */
    uint32_t Mode;                      /**< supported operating modes */
    uint32_t FieldSelection;            /**< sample fields */
    uint32_t YCSequence;
    uint32_t Conv422;
    uint32_t BPat;                      /**< bayer pattern */
    uint32_t HPol;                      /**< horizontal polarity */
    uint32_t VPol;                      /**< vertical polarity */
    uint32_t Edge;                      /**< sample edge */
    IsiResolution_t Resolution;         /**< supported resolutions */
    uint32_t SmiaMode;
    uint32_t MipiMode;
    uint32_t MipiLanes;
    uint32_t enableHdr;
} IsiSensorCaps_t;

/*****************************************************************************/
/**
 *          IsiSensorConfig_t
 *
 * @brief   Sensor configuration struct
 */
/*****************************************************************************/
typedef IsiSensorCaps_t IsiSensorConfig_t;


#endif  // _CAMERA_DEVICE_SENSOR_DEFS_H_
