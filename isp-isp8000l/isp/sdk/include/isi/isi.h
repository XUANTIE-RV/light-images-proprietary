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
 * @defgroup isi Independent Sensor Interface
 * @{
 *
 */
#ifndef __ISI_H__
#define __ISI_H__

#include <ebase/types.h>
#include <hal/hal_api.h>

#include <isi/isi_common.h>
#include <cameric_drv/cameric_drv_common.h>
#include <cam_device/cam_device_sensor_defs.h>
#include <vvsensor.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/**
 *          IsiSensorHandle_t
 *
 * @brief   Handle to a sensor instance
 *
 */
/*****************************************************************************/
typedef void *IsiSensorHandle_t; // should be of type 'struct IsiSensorContext_s *'



/*****************************************************************************/
/**
 * @brief
 */
/*****************************************************************************/
typedef struct IsiSensor_s IsiSensor_t;


/*****************************************************************************/
/**
 *          IsiSensorInstanceConfig_t
 *
 * @brief   Config structure to create a new sensor instance
 *
 */
/*****************************************************************************/
typedef struct IsiSensorInstanceConfig_s
{
    HalHandle_t           HalHandle;          /**< Handle of HAL session to use. */
    uint32_t              HalDevID;           /**< HAL device ID of this sensor. */
    uint8_t               I2cBusNum;          /**< The I2C bus the sensor is connected to. */
    uint16_t              SlaveAddr;          /**< The I2C slave addr the sensor is configured to. */
    uint8_t               I2cAfBusNum;        /**< The I2C bus the ad module is connected to. */
    uint16_t              SlaveAfAddr;        /**< The I2C slave addr of the af module is configured to */

    uint32_t              SensorModeIndex;


    IsiSensor_t         *pSensor;           /**< Sensor driver interface */

    IsiSensorHandle_t   hSensor;            /**< Sensor handle returned by IsiCreateSensorIss */
    char szSensorNodeName[32];
} IsiSensorInstanceConfig_t;



/*****************************************************************************/
/**
 * @brief   This structure defines a single Afps resolution's data.
 */
/*****************************************************************************/
typedef struct IsiAfpsResInfo_s
{
    uint32_t Resolution;                /**< the corresponding resolution ID */
    float    MaxIntTime;                /**< the maximum supported integration time */
} IsiAfpsResInfo_t;



/*****************************************************************************/
/**
 *          IsiSetCsiConfig
 *
 * @brief   mipi config.
 *
 * @param   handle      Sensor instance handle
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_NULL_POINTER
 * @retval  RET_OUTOFMEM
 *
 *****************************************************************************/
RESULT IsiSetCsiConfig
(
    IsiSensorHandle_t   handle,
    uint32_t            clk
);

/*****************************************************************************/
/**
 *          IsiCreateSensorIss
 *
 * @brief   This function creates a new sensor instance.
 *
 * @param   pConfig     configuration of the new sensor
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_NULL_POINTER
 * @retval  RET_OUTOFMEM
 *
 *****************************************************************************/
RESULT IsiCreateSensorIss
(
    IsiSensorInstanceConfig_t   *pConfig
);

/******************************************************************************
 *  *          IsiInitSensorIss
 *^M
 * @brief   The function Init a sensor register.
 *^M
 * @param   handle      sensor Init handle
 *^M
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_NOTSUPP
******************************************************************************/


RESULT IsiInitSensorIss
(
   IsiSensorHandle_t   handle
);



/*****************************************************************************/
/**
 *          IsiGetSensorModeIss
 *
 * @brief   get cuurent sensor mode info.
 *
 * @param   handle      Sensor instance handle
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 *
 *****************************************************************************/
RESULT IsiGetSensorModeIss
(
    IsiSensorHandle_t   handle,
    void *pmode
);



/*****************************************************************************/
/**
 *          IsiReleaseSensorIss
 *
 * @brief   The function destroys/releases a sensor instance.
 *
 * @param   handle      sensor instance handle
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_NOTSUPP
 *
 *****************************************************************************/
RESULT IsiReleaseSensorIss
(
    IsiSensorHandle_t   handle
);



/*****************************************************************************/
/**
 *          IsiGetCapsIss
 *
 * @brief   fills in the correct pointers for the sensor description struct
 *
 * @param   handle      Sensor instance handle
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiGetCapsIss
(
    IsiSensorHandle_t   handle,
    IsiSensorCaps_t     *pIsiSensorCaps
);



/*****************************************************************************/
/**
 *          IsiSetupSensorIss
 *
 * @brief   Setup of the image sensor considering the given configuration.
 *
 * @param   handle      Sensor instance handle
 * @param   pConfig     pointer to sensor configuration structure
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiSetupSensorIss
(
    IsiSensorHandle_t   handle,
    IsiSensorConfig_t   *pConfig
);



/*****************************************************************************/
/**
 *          IsiChangeSensorResolutionIss
 *
 * @brief   Change image sensor resolution while keeping all other static settings.
 *          Dynamic settings like current gain & integration time are kept as
 *          close as possible.
 *
 * @note    Re-read current & min/max values as they will probably have changed!
 *
 * @param   handle                  Sensor instance handle
 * @param   width             
 * @param   height   
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_WRONG_STATE
 * @retval  RET_OUTOFRANGE
 *
 *****************************************************************************/
RESULT IsiChangeSensorResolutionIss
(
    IsiSensorHandle_t   handle,
    uint16_t            width,
    uint16_t            height
);



/*****************************************************************************/
/**
 *          IsiSensorSetStreamingIss
 *
 * @brief   Enables/disables streaming of sensor data, if possible.
 *
 * @param   handle      Sensor instance handle
 * @param   on          new streaming state (BOOL_TRUE=on, BOOL_FALSE=off)
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT IsiSensorSetStreamingIss
(
    IsiSensorHandle_t   handle,
    bool_t              on
);



/*****************************************************************************/
/**
 *          IsiSensorSetPowerIss
 *
 * @brief   Performs the power-up/power-down sequence of the camera, if possible.
 *
 * @param   handle      Sensor instance handle
 * @param   on          new power state (BOOL_TRUE=on, BOOL_FALSE=off)
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiSensorSetPowerIss
(
    IsiSensorHandle_t   handle,
    bool_t              on
);



/*****************************************************************************/
/**
 *          IsiCheckSensorConnectionIss
 *
 * @brief   Checks the connection to the camera sensor, if possible.
 *
 * @param   handle      Sensor instance handle
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiCheckSensorConnectionIss
(
    IsiSensorHandle_t   handle
);



/*****************************************************************************/
/**
 *          IsiGetSensorRevisionIss
 *
 * @brief   This function reads the sensor revision register and returns it.
 *
 * @param   handle      sensor instance handle
 * @param   p_value     pointer to value
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 * @retval  RET_NOTSUPP
 *
 *****************************************************************************/
RESULT IsiGetSensorRevisionIss
(
    IsiSensorHandle_t   handle,
    uint32_t            *p_value
);



/*****************************************************************************/
/**
 *          IsiGetGainLimitsIss
 *
 * @brief   Returns the gain minimal and maximal values of a sensor
 *          instance
 *
 * @param   handle      sensor instance handle
 * @param   pMinGain    Pointer to a variable receiving minimal exposure value
 * @param   pMaxGain    Pointer to a variable receiving maximal exposure value
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiGetGainLimitsIss
(
    IsiSensorHandle_t   handle,
    float               *pMinGain,
    float               *pMaxGain
);



/*****************************************************************************/
/**
 *          IsiGetIntegrationTimeLimitsIss
 *
 * @brief   Returns the integration time minimal and maximal values of a sensor
 *          instance
 *
 * @param   handle                  sensor instance handle
 * @param   pMinIntegrationTime     Pointer to a variable receiving minimal exposure value
 * @param   pMaxIntegrationTime     Pointer to a variable receiving maximal exposure value
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiGetIntegrationTimeLimitsIss
(
    IsiSensorHandle_t   handle,
    float               *pMinIntegrationTime,
    float               *pMaxIntegrationTime
);


/*****************************************************************************/
/**
 *          IsiExposureControlIss
 *
 * @brief   Sets the exposure values (gain & integration time) of a sensor
 *          instance
 *
 * @param   handle                  sensor instance handle
 * @param   NewGain                 newly calculated gain to be set
 * @param   NewIntegrationTime      newly calculated integration time to be set
 * @param   pNumberOfFramesToSkip   number of frames to skip until AE is
 *                                  executed again
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiExposureControlIss
(
    IsiSensorHandle_t   handle,
    float               NewGain,
    float               NewIntegrationTime,
    uint8_t             *pNumberOfFramesToSkip,
    float               *pSetGain,
    float               *pSetIntegrationTime,
    float               *hdr_ratio
);



/*****************************************************************************/
/**
 *          IsiGetCurrentExposureIss
 *
 * @brief   Returns the currently adjusted AE values
 *
 * @param   handle       sensor instance handle
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiGetCurrentExposureIss
(
    IsiSensorHandle_t   handle,
    float               *pCurGain,
    float               *pCurIntegrationTime,
    float               *pCurHdrRatio
);



/*****************************************************************************/
/**
 *          IsiGetGainIss
 *
 * @brief   Reads gain values from the image sensor module.
 *
 * @param   handle                  sensor instance handle
 * @param   pSetGain                set gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiGetGainIss
(
    IsiSensorHandle_t   handle,
    float               *pGain
);

RESULT IsiGetVSGainIss
(
    IsiSensorHandle_t   handle,
    float               *pGain
);

RESULT IsiGetLongGainIss
(
    IsiSensorHandle_t   handle,
    float               *pGain
);


/*****************************************************************************/
/**
 *          IsiGetGainIncrementIss
 *
 * @brief   Get smalles possible gain increment.
 *
 * @param   handle                  sensor instance handle
 * @param   pIncr                   increment
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiGetGainIncrementIss
(
    IsiSensorHandle_t   handle,
    float               *pIncr
);


/*****************************************************************************/
/**
 *          IsiSetGainIss
 *
 * @brief   Writes gain values to the image sensor module.
 *
 * @param   handle                  sensor instance handle
 * @param   NewGain                 gain to be set
 * @param   pSetGain                set gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiSetGainIss
(
    IsiSensorHandle_t   handle,
    float               NewGain,
    float               *pSetGain,
    float               *hdr_ratio
);



/*****************************************************************************/
/**
 *          IsiGetIntegrationTimeIss
 *
 * @brief   Reads integration time values from the image sensor module.
 *
 * @param   handle                  sensor instance handle
 * @param   pSetIntegrationTime     set integration time
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiGetIntegrationTimeIss
(
    IsiSensorHandle_t   handle,
    float               *pIntegrationTime
);

RESULT IsiGetVSIntegrationTimeIss
(
    IsiSensorHandle_t   handle,
    float               *pIntegrationTime
);

RESULT IsiGetLongIntegrationTimeIss
(
    IsiSensorHandle_t   handle,
    float               *pIntegrationTime
);


/*****************************************************************************/
/**
 *          IsiGetIntegrationTimeIncrementIss
 *
 * @brief   Get smalles possible integration time increment.
 *
 * @param   handle                  sensor instance handle
 * @param   pIncr                   increment
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiGetIntegrationTimeIncrementIss
(
    IsiSensorHandle_t   handle,
    float               *pIncr
);



/*****************************************************************************/
/**
 *          IsiSetIntegrationTimeIss
 *
 * @brief   Writes integration time values to the image sensor module.
 *
 * @param   handle                  sensor instance handle
 * @param   NewIntegrationTime      integration time to be set
 * @param   pSetIntegrationTime     set integration time
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiSetIntegrationTimeIss
(
    IsiSensorHandle_t   handle,
    float               NewIntegrationTime,
    float               *pSetIntegrationTime,
    float               *hdr_ratio
);



/*****************************************************************************/
/**
 *          IsiQuerySensorIss
 *
 * @brief   query sensor info arry.
 *
 * @param   handle                  sensor instance handle
 * @param   pSensorInfo             sensor query arry
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiQuerySensorIss
(
    IsiSensorHandle_t   handle,
    vvcam_mode_info_array_t *pSensorInfo
);



/*****************************************************************************/
/**
 *          IsiGetSensorFpsIss
 *
 * @brief   Get Sensor Fps Config.
 *
 * @param   handle                  sensor instance handle
 * @param   pFps                    current fps
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiGetSensorFpsIss
(
    IsiSensorHandle_t   handle,
    uint32_t            *pFps
);



/*****************************************************************************/
/**
 *          IsiSetSensorFpsIss
 *
 * @brief   set Sensor Fps Config.
 *
 * @param   handle                  sensor instance handle
 * @param   Fps                     Setfps
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiSetSensorFpsIss
(
    IsiSensorHandle_t   handle,
    uint32_t            Fps
);



/*****************************************************************************/
/**
 *          IsiGetResolutionIss
 *
 * @brief   Reads integration time values from the image sensor module.
 *
 * @param   handle                  sensor instance handle
 * @param   pwidth    
 * @param   pheight      
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiGetResolutionIss
(
    IsiSensorHandle_t   handle,
    uint16_t *pwidth,
    uint16_t *pheight
);



/*****************************************************************************/
/**
 *          IsiWriteRegister
 *
 * @brief   writes a given number of bytes to the image sensor device by
 *          calling the corresponding sensor-function
 *
 * @param   handle              Handle to image sensor device
 * @param   RegAddress          register address
 * @param   RegValue            value to write
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NOTSUPP
 *
 *****************************************************************************/
RESULT IsiWriteRegister
(
    IsiSensorHandle_t   handle,
    const uint32_t      RegAddress,
    const uint32_t      RegValue
);



/*****************************************************************************/
/**
 *          IsiReadRegister
 *
 * @brief   reads a given number of bytes from the image sensor device
 *
 * @param   handle              Handle to image sensor device
 * @param   RegAddress          register address
 * @param   RegValue            value to write
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 * @retval  RET_NOTSUPP
 *
 *****************************************************************************/
RESULT IsiReadRegister
(
    IsiSensorHandle_t   handle,
    const uint32_t      RegAddress,
    uint32_t            *pRegValue
);







/*****************************************************************************/
/**
 *          IsiMdiInitMotoDrive
 *
 * @brief   General initialisation tasks like I/O initialisation.
 *
 * @param   handle          sensor instance handle
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiMdiInitMotoDrive
(
    IsiSensorHandle_t   handle
);



/*****************************************************************************/
/**
 *          IsiMdiSetupMotoDrive
 *
 * @brief   Setup of the MotoDrive and return possible max step.
 *
 * @param   handle          sensor instance handle
 *          pMaxStep        pointer to variable to receive the maximum
 *                          possible focus step
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiMdiSetupMotoDrive
(
    IsiSensorHandle_t   handle,
    uint32_t            *pMaxStep
);



/*****************************************************************************/
/**
 *          IsiMdiFocusSet
 *
 * @brief   Drives the lens system to a certain focus point.
 *
 * @param   handle          sensor instance handle
 *          AbsStep         absolute focus point to apply
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiMdiFocusSet
(
    IsiSensorHandle_t   handle,
    const uint32_t      AbsStep
);



/*****************************************************************************/
/**
 *          IsiMdiFocusGet
 *
 * @brief   Retrieves the currently applied focus point.
 *
 * @param   handle          sensor instance handle
 *          pAbsStep        pointer to a variable to receive the current
 *                          focus point
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiMdiFocusGet
(
    IsiSensorHandle_t   handle,
    uint32_t            *pAbsStep
);



/*****************************************************************************/
/**
 *          IsiMdiFocusCalibrate
 *
 * @brief   Triggers a forced calibration of the focus hardware.
 *
 * @param   handle          sensor instance handle
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiMdiFocusCalibrate
(
    IsiSensorHandle_t   handle
);



/*****************************************************************************/
/**
 *          IsiActivateTestPattern
 *
 * @brief   Activates or deactivates sensor's test-pattern (normally a defined
 *          colorbar )
 *
 * @param   handle          sensor instance handle
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiActivateTestPattern
(
    IsiSensorHandle_t   handle,
    const bool_t        enable
);

RESULT IsiEnableHdr
(
    IsiSensorHandle_t   handle,
    const bool_t        enable
);

RESULT IsiSetBayerPattern
(
    IsiSensorHandle_t handle,
    uint8_t pattern
);

/*****************************************************************************/
/**
 *          IsiDumpAllRegisters
 *
 * @brief   Activates or deactivates sensor's test-pattern (normally a defined
 *          colorbar )
 *
 * @param   handle          sensor instance handle
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiDumpAllRegisters
(
    IsiSensorHandle_t   handle,
    const uint8_t       *filename
);



/*****************************************************************************/
/**
 *          IsiTryToSetConfigFromPreferredCaps
 *
 * @brief   Tries to set the referenced sensor config parameter to the first of the
 *          given preferred capabilities that is included in the given capability
 *          mask. If none of the preferred capabilities is supported, the config
 *          parameter value remains unchanged.
 *
 * @note    Use this function for example to modify the retrieved default sensor
 *          config parameter for parameter according to some external preferences
 *          while taking the retrieved sensor capabilities for that config parameter
 *          into account.
 *
 * @param   pConfigParam    reference to parameter of sensor config structure
 * @param   prefList        reference to 0 (zero) terminated array of preferred
 *                          capability values in descending order
 * @param   capsmask        bitmask of supported capabilites for that parameter
 *
 * @return  Return the result of the function call.
 * @retval  BOOL_TRUE       preferred capability set in referenced config parameter
 * @retval  BOOL_FALSE      preferred capability not supported
 *
 *****************************************************************************/
bool_t IsiTryToSetConfigFromPreferredCaps
(
    uint32_t    *pConfigParam,
    uint32_t    *prefList,
    uint32_t    capsmask
);



/*****************************************************************************/
/**
 *          IsiTryToSetConfigFromPreferredCap
 *
 * @brief   Tries to set referenced sensor config parameter to the given preferred
 *          capability while checking that capability against the given capability
 *          mask. If that capability isn't supported, the config parameter value
 *          remains unchanged.
 *
 * @note    Use this function for example to modify the retrieved default sensor
 *          config parameter for parameter according to some external preferences
 *          while taking the retrieved sensor capabilities for that config parameter
 *          into account.
 *
 * @param   pConfigParam    reference to parameter of sensor config structure
 * @param   prefcap         preferred capability value
 * @param   capsmask        bitmask of supported capabilites for that parameter
 *
 * @return  Return the result of the function call.
 * @retval  BOOL_TRUE       preferred capability set in referenced config parameter
 * @retval  BOOL_FALSE      preferred capability not supported
 *
 *****************************************************************************/
bool_t IsiTryToSetConfigFromPreferredCap
(
    uint32_t        *pConfigParam,
    const uint32_t  prefcap,
    const uint32_t  capsmask
);



/*****************************************************************************/
/**
 *          IsiGetSensorAWBMode
 *
 * @brief   get sensor awb mode ( workaround )
 *
 * Used to modify the AWB control loop handling in case of sensors that require
 * on-sensor whitebalance gain
 *
 * @param        handle          sensor instance handle
 * @param[out]   pawb_mode       awb mode the sensor is operating in currently
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT IsiGetSensorAWBMode(IsiSensorHandle_t handle, IsiSensorAwbMode_t *pawb_mode);



/*****************************************************************************/
/**
 *          IsiSensorSetBlc
 *
 * @brief   set sensor linear mode black level 
 *          
 *
 * @param   handle          sensor instance handle
 * @param   pblc            blc params point
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT IsiSensorSetBlc(IsiSensorHandle_t handle, sensor_blc_t * pblc);




/*****************************************************************************/
/**
 *          IsiSensorSetWB
 *
 * @brief   set sensor linear mode white balance 
 *          or hdr mode normal exp frame white balance
 *
 * @param   handle          sensor instance handle
 * @param   pwb             wb params point
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT IsiSensorSetWB(IsiSensorHandle_t handle, sensor_white_balance_t *pwb);



/*****************************************************************************/
/**
 *          IsiSensorGetExpandCure
 *
 * @brief   get sensor expand curve 
 *
 * @param   handle          sensor instance handle
 * @param   pexpand_curve   expand cure point
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT IsiSensorGetExpandCurve(IsiSensorHandle_t handle, sensor_expand_curve_t * pexpand_curve);


#ifdef __cplusplus
}
#endif


/* @} isi */


#endif /* __ISI_H__ */
