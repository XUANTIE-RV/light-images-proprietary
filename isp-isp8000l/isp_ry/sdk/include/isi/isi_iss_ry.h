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
 * @file isi_iss.h
 *
 * @brief Interface description for image sensor specific implementation (iss).
 *
 *****************************************************************************/
/**
 * @page module_name_page Module Name
 * Describe here what this module does.
 *
 * For a detailed list of functions and implementation detail refer to:
 * - @ref module_name
 *
 * @defgroup isi_iss CamerIc Driver API
 * @{
 *
 */
#ifndef __ISI_ISS_H__
#define __ISI_ISS_H__

#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>
#include <hal/hal_api_ry.h>

#include "isi_ry.h"

#ifdef __cplusplus
extern "C"
{
#endif



/*****************************************************************************/
/**
 *          IsiRegisterFlags_t
 *
 * @brief   Register permission enumeration type
 */
/*****************************************************************************/
typedef enum IsiRegisterFlags_e
{
    // basic features
    eTableEnd           = 0x00,                                                 /**< special flag for end of register table */
    eReadable           = 0x01,
    eWritable           = 0x02,
    eVolatile           = 0x04,                                                 /**< register can change even if not written by I2C */
    eDelay              = 0x08,                                                 /**< wait n ms */
    eReserved           = 0x10,
    eNoDefault          = 0x20,                                                 /**< no default value specified */
    eTwoBytes           = 0x40,                                                 /**< SMIA sensors use 8-, 16- and 32-bit registers */
    eFourBytes          = 0x80,                                                 /**< SMIA sensors use 8-, 16- and 32-bit registers */

    // combined features
    eReadOnly           = eReadable,
    eWriteOnly          = eWritable,
    eReadWrite          = eReadable | eWritable,
    eReadWriteDel       = eReadable | eWritable | eDelay,
    eReadWriteVolatile  = eReadable | eWritable | eVolatile,
    eReadWriteNoDef     = eReadable | eWritable | eNoDefault,
    eReadWriteVolNoDef  = eReadable | eWritable | eVolatile | eNoDefault,
    eReadVolNoDef       = eReadable | eVolatile | eNoDefault,
    eReadOnlyVolNoDef   = eReadOnly | eVolatile | eNoDefault,

    // additional SMIA features
    eReadOnly_16            = eReadOnly          | eTwoBytes,
    eReadWrite_16           = eReadWrite         | eTwoBytes,
    eReadWriteDel_16        = eReadWriteDel      | eTwoBytes,
    eReadWriteVolatile_16   = eReadWriteVolatile | eTwoBytes,
    eReadWriteNoDef_16      = eReadWriteNoDef    | eTwoBytes,
    eReadWriteVolNoDef_16   = eReadWriteVolNoDef | eTwoBytes,
    eReadOnlyVolNoDef_16    = eReadOnly_16 | eVolatile | eNoDefault,
    eReadOnly_32            = eReadOnly          | eFourBytes,
    eReadWrite_32           = eReadWrite         | eFourBytes,
    eReadWriteVolatile_32   = eReadWriteVolatile | eFourBytes,
    eReadWriteNoDef_32      = eReadWriteNoDef    | eFourBytes,
    eReadWriteVolNoDef_32   = eReadWriteVolNoDef | eFourBytes
} IsiRegisterFlags_t;



/*****************************************************************************/
/**
 *          IsiRegDescription_t
 *
 * @brief   Sensor register description struct
 */
/*****************************************************************************/
typedef struct IsiRegisterFlags_s
{
    uint32_t    Addr;
    uint32_t    DefaultValue;
    const char* pName;
    uint32_t    Flags;
} IsiRegDescription_t;


typedef RESULT (*IsiCreateSensorIss_t)               (IsiSensorInstanceConfig_t *pConfig);
typedef RESULT (*IsiInitSensorIss_t)                 (IsiSensorHandle_t handle);
typedef RESULT (*IsiGetSensorModeIss_t)              (IsiSensorHandle_t handle, void *mode);
typedef RESULT (*IsiReleaseSensorIss_t)              (IsiSensorHandle_t handle);
typedef RESULT (*IsiGetCapsIss_t)                    (IsiSensorHandle_t handle, IsiSensorCaps_t *pIsiSensorCaps);
typedef RESULT (*IsiSetupSensorIss_t)                (IsiSensorHandle_t handle, const IsiSensorCaps_t *pIsiSensorCaps);
typedef RESULT (*IsiChangeSensorResolutionIss_t)     (IsiSensorHandle_t handle, uint16_t width, uint16_t height);
typedef RESULT (*IsiSensorSetStreamingIss_t)         (IsiSensorHandle_t handle, bool_t on);
typedef RESULT (*IsiSensorSetPowerIss_t)             (IsiSensorHandle_t handle, bool_t on);
typedef RESULT (*IsiCheckSensorConnectionIss_t)      (IsiSensorHandle_t handle);
typedef RESULT (*IsiGetSensorRevisionIss_t)          (IsiSensorHandle_t handle, uint32_t *p_value);
typedef RESULT (*IsiRegisterReadIss_t)               (IsiSensorHandle_t handle, const uint32_t address, uint32_t *p_value);
typedef RESULT (*IsiRegisterWriteIss_t)              (IsiSensorHandle_t handle, const uint32_t address, const uint32_t value);

/* AEC */
typedef RESULT (*IsiExposureControlIss_t)            (IsiSensorHandle_t handle, const float NewGain, const float NewIntegrationTime, uint8_t *pNumberOfFramesToSkip, float *pSetGain, float *pSetIntegrationTime, float* hdr_ratio);
typedef RESULT (*IsiGetGainLimitsIss_t)              (IsiSensorHandle_t handle, float *pMinGain, float *pMaxGain);
typedef RESULT (*IsiGetIntegrationTimeLimitsIss_t)   (IsiSensorHandle_t handle, float *pMinIntegrationTime, float *pMaxIntegrationTime);
typedef RESULT (*IsiGetCurrentExposureIss_t)         (IsiSensorHandle_t handle, float *pSetGain, float *pSetIntegrationTime, float *pCurHdrRatio);
typedef RESULT (*IsiGetGainIss_t)                    (IsiSensorHandle_t handle, float *pSetGain);
typedef RESULT (*IsiGetVSGainIss_t)                  (IsiSensorHandle_t handle, float *pSetGain);
typedef RESULT (*IsiGetLongGainIss_t)                (IsiSensorHandle_t handle, float *pSetGain);
typedef RESULT (*IsiGetGainIncrementIss_t)           (IsiSensorHandle_t handle, float *pIncr);
typedef RESULT (*IsiSetGainIss_t)                    (IsiSensorHandle_t handle, float NewGain, float *pSetGain, float *hdr_ratio);
typedef RESULT (*IsiGetIntegrationTimeIss_t)         (IsiSensorHandle_t handle, float *pSetIntegrationTime);
typedef RESULT (*IsiGetVSIntegrationTimeIss_t)       (IsiSensorHandle_t handle, float *pSetIntegrationTime);
typedef RESULT (*IsiGetLongIntegrationTimeIss_t)     (IsiSensorHandle_t handle, float *pIntegrationTime);
typedef RESULT (*IsiGetIntegrationTimeIncrementIss_t)(IsiSensorHandle_t handle, float *pIncr);
typedef RESULT (*IsiSetIntegrationTimeIss_t)         (IsiSensorHandle_t handle, float NewIntegrationTime, float *pSetIntegrationTime, uint8_t *pNumberOfFramesToSkip, float *hdr_ratio);
typedef RESULT (*IsiGetResolutionIss_t)              (IsiSensorHandle_t handle, uint16_t *pwidth, uint16_t *pheight);

/* AF */
typedef RESULT (*IsiMdiInitMotoDriveMds_t)           (IsiSensorHandle_t handle);
typedef RESULT (*IsiMdiSetupMotoDrive_t)             (IsiSensorHandle_t handle, uint32_t *pMaxStep);
typedef RESULT (*IsiMdiFocusSet_t)                   (IsiSensorHandle_t handle, const uint32_t AbsStep);
typedef RESULT (*IsiMdiFocusGet_t)                   (IsiSensorHandle_t handle, uint32_t *pAbsStep);
typedef RESULT (*IsiMdiFocusCalibrate_t)             (IsiSensorHandle_t handle);

/*MIPI*/
typedef RESULT (*IsiGetSensorMipiInfoIss_t)          (IsiSensorHandle_t handle, IsiSensorMipiInfo *ptIsiSensorMipiInfo);
typedef RESULT (*IsiResetSensor_t)                   (IsiSensorHandle_t handle);
/* Testpattern */
typedef RESULT (*IsiActivateTestPattern_t)           (IsiSensorHandle_t handle, const bool_t enable);

/* BayerPattern */
typedef RESULT (*IsiSetBayerPattern_t)               (IsiSensorHandle_t handle, uint8_t pattern);

/* get fps */
typedef RESULT (*IsiGetSensorFpsIss_t)               (IsiSensorHandle_t handle, uint32_t *pfps);

/* set fps */
typedef RESULT (*IsiSetSensorFpsIss_t)               (IsiSensorHandle_t handle, uint32_t fps);

typedef RESULT (*IsiQuerySensorIss_t)                (IsiSensorHandle_t handle, vvcam_mode_info_array_t *pSensorInfo);

typedef RESULT (*IsiSensorSetBlcIss_t)               (IsiSensorHandle_t handle, sensor_blc_t *pblc);

typedef RESULT (*IsiSensorSetWBIss_t)                (IsiSensorHandle_t handle, sensor_white_balance_t *pwb);

typedef RESULT (*IsiGetSensorAWBModeIss_t)           (IsiSensorHandle_t handle, IsiSensorAwbMode_t *pawbmode);

typedef RESULT (*IsiSensorGetExpandCurveIss_t)       (IsiSensorHandle_t handle, sensor_expand_curve_t *pexpand_curve);

/* query sensor support mode */
typedef RESULT (*IsiQuerySensorSupportIss_t)         (HalHandle_t HalHandle, vvcam_mode_info_array_t *pSensorSupportInfo);

/*****************************************************************************/
/**
 *          IsiSensor_t
 *
 * @brief
 *
 */
/*****************************************************************************/
struct IsiSensor_s
{
    const char                          *pszName;                      /**< name of the camera-sensor */
    const IsiRegDescription_t           *pRegisterTable;               /**< pointer to register table */

    IsiCreateSensorIss_t                pIsiCreateSensorIss;           /**< create a sensor handle */
    IsiInitSensorIss_t                  pIsiInitSensorIss;             /** init sensor register  */
    IsiGetSensorModeIss_t               pIsiGetSensorModeIss;
    IsiReleaseSensorIss_t               pIsiReleaseSensorIss;          /**< release a sensor handle */
    IsiGetCapsIss_t                     pIsiGetCapsIss;                /**< get sensor capabilities */
    IsiSetupSensorIss_t                 pIsiSetupSensorIss;            /**< setup sensor capabilities */
    IsiChangeSensorResolutionIss_t      pIsiChangeSensorResolutionIss; /**< change sensor resolution */
    IsiSensorSetStreamingIss_t          pIsiSensorSetStreamingIss;     /**< enable/disable streaming of data once sensor is configured */
    IsiSensorSetPowerIss_t              pIsiSensorSetPowerIss;         /**< turn sensor power on/off */
    IsiCheckSensorConnectionIss_t       pIsiCheckSensorConnectionIss;

    IsiGetSensorRevisionIss_t           pIsiGetSensorRevisionIss;      /**< read sensor revision register (if available) */
    IsiRegisterReadIss_t                pIsiRegisterReadIss;           /**< read sensor register */
    IsiRegisterWriteIss_t               pIsiRegisterWriteIss;          /**< write sensor register */

    /* AEC functions */
    IsiExposureControlIss_t             pIsiExposureControlIss;
    IsiGetGainLimitsIss_t               pIsiGetGainLimitsIss;
    IsiGetIntegrationTimeLimitsIss_t    pIsiGetIntegrationTimeLimitsIss;
    IsiGetCurrentExposureIss_t          pIsiGetCurrentExposureIss;     /**< get the currenntly adjusted ae values (gain and integration time) */
    IsiGetGainIss_t                     pIsiGetGainIss;
    IsiGetVSGainIss_t                   pIsiGetVSGainIss;
    IsiGetLongGainIss_t                 pIsiGetLongGainIss;
    IsiGetGainIncrementIss_t            pIsiGetGainIncrementIss;
    IsiSetGainIss_t                     pIsiSetGainIss;
    IsiGetIntegrationTimeIss_t          pIsiGetIntegrationTimeIss;
    IsiGetVSIntegrationTimeIss_t        pIsiGetVSIntegrationTimeIss;
    IsiGetLongIntegrationTimeIss_t      pIsiGetLongIntegrationTimeIss;
    IsiGetIntegrationTimeIncrementIss_t pIsiGetIntegrationTimeIncrementIss;
    IsiSetIntegrationTimeIss_t          pIsiSetIntegrationTimeIss;
    IsiQuerySensorIss_t                 pIsiQuerySensorIss;
    IsiGetResolutionIss_t               pIsiGetResolutionIss;
    IsiGetSensorFpsIss_t                pIsiGetSensorFpsIss;
    IsiSetSensorFpsIss_t                pIsiSetSensorFpsIss;
    IsiSensorGetExpandCurveIss_t        pIsiSensorGetExpandCurveIss;
    /* AF functions */
    IsiMdiInitMotoDriveMds_t            pIsiMdiInitMotoDriveMds;
    IsiMdiSetupMotoDrive_t              pIsiMdiSetupMotoDrive;
    IsiMdiFocusSet_t                    pIsiMdiFocusSet;
    IsiMdiFocusGet_t                    pIsiMdiFocusGet;
    IsiMdiFocusCalibrate_t              pIsiMdiFocusCalibrate;

    /*MIPI*/
    IsiGetSensorMipiInfoIss_t           pIsiGetSensorMipiInfoIss;
    IsiResetSensor_t                    pIsiResetSensorIss;

    /* Testpattern */
    IsiActivateTestPattern_t            pIsiActivateTestPattern;       /**< enable/disable test-pattern */
    IsiSetBayerPattern_t                pIsiSetBayerPattern;

    IsiSensorSetBlcIss_t                pIsiSensorSetBlcIss;
    IsiSensorSetWBIss_t                 pIsiSensorSetWBIss;
    IsiGetSensorAWBModeIss_t            pIsiGetSensorAWBModeIss;
};



/*****************************************************************************/
/**
 *          IsiGetSensorIss_t
 *
 * @brief   Only exported function of sensor specific code: fills in
 *          sensor decription struct
 *
 */
/*****************************************************************************/
typedef RESULT (*IsiGetSensorIss_t) (IsiSensor_t *pIsiSensor);



/*****************************************************************************/
/**
 *          IsiCamDrvConfig_t
 *
 * @brief   Camera sensor driver specific data
 *
 */
/*****************************************************************************/
typedef struct IsiCamDrvConfig_s
{
    uint32_t                     CameraDriverID;
    IsiQuerySensorSupportIss_t   pIsiQuerySensorSupportIss;
    IsiGetSensorIss_t            pfIsiGetSensorIss;
    IsiSensor_t                  IsiSensor;
} IsiCamDrvConfig_t;

typedef struct IsiSccbInfo_s
{
    uint8_t slave_addr;
    uint8_t addr_byte;
    uint8_t data_byte;
} IsiSccbInfo_t;


#ifdef __cplusplus
}
#endif

#endif /* __ISI_ISS_H__ */

