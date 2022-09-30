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
 * @file cam_engine_api.h
 *
 * @brief
 *   Interface description of the CamEngine.
 *
 *****************************************************************************/
/**
 *
 * @mainpage General Concept
 *
 * The CamEengine provides the application programming interface (API) to control
 * the camerIC ISP hardware and its sub modules from C/C++ applications. It abstracts
 * a common camera interface and contains functions to control the usage modes of
 * a typical image capturing device.
 *
 * The camerIC ISP offers two data output path. The @e self @e path is intended for preview;
 * the @e main @e path offers an additional JPEG encoding block and is intended for capturing
 * video streams and high resolution still images. The CamEngine controls the output
 * modality for the chosen usage mode (see @ref CamEngineSetPathConfig). A callback to receive
 * full buffers of either the @e self @e or @e main @e path can be registered using the
 * @ref CamEngineRegisterBufferCb function. The @e self @e path can either be rendered in
 * an X11 application window or forward to the video display unit for rendering on a connected
 * HDMI display. The stream from the @e main @e path can be captured to disk.
 *
 * The CamEngine follows the object model of the camerIC evaluation software. Before usage, the
 * CamEngine needs to be statically configured by the @ref CamEngineInit function. Then, an instance
 * of the CamEngine can be started using the @ref CamEngineStart function. From now on commands
 * can be send to the CamEngine. The instance can be stopped using the @ref CamEngineStop
 * function and all resources are released with the @ref CamEngineShutDown function.
 *
 * @defgroup cam_engine_api CamEngine API
 * @{
 */

#ifndef __CAM_ENGINE_RY_API_H__
#define __CAM_ENGINE_RY_API_H__

#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>
#include <common/picture_buffer_ry.h>
#include <bufferpool/media_buffer_ry.h>

//FIXME
#include <common/mipi_ry.h>
#include <isi/isi_ry.h>

#include <cameric_drv/cameric_drv_ry_api.h>
#include <cameric_drv/cameric_isp_drv_ry_api.h>
#include <cameric_drv/cameric_mi_drv_ry_api.h>

#ifdef ISP_GCMONO
#include <cameric_drv/cameric_isp_gcmono_drv_ry_api.h>
#endif

#ifdef ISP_RGBGC_RY
#include <cameric_drv/cameric_isp_rgbgamma_drv_ry_api.h>
#endif

#include <cam_calibdb/cam_calibdb_api_ry.h>

#include "cam_engine_common_ry.h"
#include "cam_device/cam_device_metadata_ry.h"

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * @brief   Configuration structure of the cam-engine instance.
 *
 */
typedef struct CamEngineInstanceConfig_ry_s
{
    uint32_t                    maxPendingCommands; /**< Number of commands that can be queued and thus be pending at a time. */
    bool_t                   isSystem3D;            /**< System capable for 3D */

    CamEngineCompletionCb_ry_t     cbCompletion;       /**< Callback function for command completion. */
    CamEngineAfpsResChangeCb_ry_t  cbAfpsResChange;    /**< Afps resolution chnage request callback */
    void                        *pUserCbCtx;        /**< User context passed on to completion & Afps callbacks. */

    HalHandle_t                 hHal;               /**< HAL handle (hardware abstraction layer). */

    CamEngineHandle_ry_t           hCamEngine;         /**< Handle to cam-engine context, set by @ref CamEngineInit if successful, undefined otherwise. */
#ifdef SUBDEV_V4L2
    char szIspNodeNameLeft[32];
    char szIspNodeNameRight[32];
#endif
    bool hdr;
#ifdef USE_3AV2
    int iEngineIndex;
#endif
} CamEngineInstanceConfig_ry_t;


/**
 * @brief   Configuration structure of the cam-engine.
 *
 */
typedef struct CamEngineConfig_ry_s
{
    CamEngineConfigType_ry_t type;
    CamEnginePathConfig_ry_t pathConfig[CAM_ENGINE_PATH_MAX_RY];

    union CamEngineConfigData_ry_u
    {
        struct CamEngineConfigSensor_ry_s
        {
            /* sensor interface */
            IsiSensorHandle_t               hSensor;                /**< main sensor handle (measuring running on this sensor pipe */
            IsiSensorHandle_t               hSubSensor;             /**< sub sensor handle */

            CamCalibDbHandle_t              hCamCalibDb;            /**< handle to calibration data base */

            /* input interface */
            CamerIcInterfaceSelect_ry_t        ifSelect;

            /* input acquisition */
            CamerIcIspSampleEdge_ry_t          sampleEdge;
            CamerIcIspPolarity_ry_t            hSyncPol;
            CamerIcIspPolarity_ry_t            vSyncPol;
            CamerIcIspBayerPattern_ry_t        bayerPattern;
            CamerIcIspColorSubsampling_ry_t    subSampling;
            CamerIcIspCCIRSequence_ry_t        seqCCIR;
            CamerIcIspFieldSelection_ry_t      fieldSelection;
            CamerIcIspInputSelection_ry_t      inputSelection;

#ifdef ISP_DVP_PINMAPPING
            CamerIcIspDvpPinMappig_ry_t        dvpPinMapping;
#endif
#ifdef ISP_DPF_RAW
            CamerIcIspDpfRaw_ry_t              dpf_mode;
#endif
#ifdef ISP_MI_FIFO_DEPTH_NANO
            CamerIcMiMpOutputFifoDepth_ry_t    mi_mp_fifo_depth;
#endif
#ifdef ISP_MI_ALIGN_NANO
            CamerIcMiMpOutputLsbAlign_ry_t     mi_mp_lsb_align;
#endif
#ifdef ISP_MI_BYTESWAP
            CamerIcMiMpOutputByteSwap_ry_t     mi_mp_byte_swap;
#endif
#ifdef ISP_MI_HANDSHAKE_NANO
            CamerIcMiMpHandshake_ry_t          mi_mp_handshake;
#endif
#ifdef ISP_GCMONO
            CamerIcIspGcMonoContext_ry_t       gcmono_ctx;
#endif
            /* isp configuration */
            CamerIcIspMode_ry_t                mode;
            CamEngineWindow_ry_t               acqWindow;
            CamEngineWindow_ry_t               outWindow;
            CamEngineWindow_ry_t               isWindow;

            MipiDataType_t                  mipiMode;

            bool_t                          enable3D;
            bool_t                          enableTestpattern;

            CamEngineFlickerPeriod_ry_t        flickerPeriod;
            bool_t                          enableAfps;
            char szSensorName[256];
            char szCsiName[256];
            int64_t csiFormat;
            int csiPad;
            uint32_t stitchingMode;
            CamerIcISPCompandCurveConfig_ry_t compress_curve;
            CamerIcISPCompandCurveConfig_ry_t expand_curve;
        } sensor;

        struct CamEngineConfigImage_ry_s
        {
            /* image information */
            PicBufType_t                    type;
            PicBufLayout_t                  layout;

            uint8_t                         *pBuffer;
            uint16_t                        width;
            uint16_t                        height;
            uint32_t                        is_lsb_align;

            CamEngineWbGains_ry_t              *pWbGains;
            CamEngineCcMatrix_ry_t             *pCcMatrix;
            CamEngineCcOffset_ry_t             *pCcOffset;
            CamEngineBlackLevel_ry_t           *pBlvl;

#ifdef ISP_DVP_PINMAPPING
            CamerIcIspDvpPinMappig_ry_t        dvpPinMapping; //for test bench enabling
#endif
#ifdef ISP_DPF_RAW
            CamerIcIspDpfRaw_ry_t              dpf_mode;
#endif
#ifdef ISP_MI_FIFO_DEPTH_NANO
            CamerIcMiMpOutputFifoDepth_ry_t    mi_mp_fifo_depth;
#endif
#ifdef ISP_MI_ALIGN_NANO
            CamerIcMiMpOutputLsbAlign_ry_t     mi_mp_lsb_align;
#endif
#ifdef ISP_MI_BYTESWAP
            CamerIcMiMpOutputByteSwap_ry_t     mi_mp_byte_swap;
#endif
#ifdef ISP_MI_HANDSHAKE_NANO
            CamerIcMiMpHandshake_ry_t          mi_mp_handshake;
#endif
#ifdef ISP_GCMONO
            CamerIcIspGcMonoContext_ry_t       gcmono_ctx;
#endif
            uint32_t                        tpg_enabled;

            /* add raw image support */
            CamerIcIspFieldSelection_ry_t      fieldSelection;
            CamerIcIspInputSelection_ry_t      inputSelection;
            CamerIcISPCompandCurveConfig_ry_t compress_curve;
            CamerIcISPCompandCurveConfig_ry_t expand_curve;
            char                            align;  // raw data align mode

            /* input interface */
            CamerIcInterfaceSelect_ry_t        ifSelect;
            uint32_t stitchingMode;
        } image;
    } data;

} CamEngineConfig_ry_t;


/*****************************************************************************/
/**
 * @brief   The function creates and initializes a CamEngine instance.
 *
 * @param   pConfig     Instance configuration structure.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_INVALID_PARM    invalid configuration
 * @retval  RET_OUTOFRANGE      a configuration parameter is out of range
 * @retval  RET_WRONG_HANDLE    invalid HAL handle
 * @retval  RET_OUTOFMEM        not enough memory available
 *
 *****************************************************************************/
RESULT CamEngineInit_ry
(
    CamEngineInstanceConfig_ry_t *pConfig
);


/*****************************************************************************/
/**
 * @brief   This function shutdowns and destroys a CamEngine instance.
 *
 * @param   hCamEngine Handle to the CamEngine instance.
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamEngineShutDown_ry
(
    CamEngineHandle_ry_t   hCamEngine
);


/*****************************************************************************/
/**
 * @brief   The function starts a CamEngine instance. This puts the CamEngine
 *          into the running state. The CamEngine is configured and ready for
            streaming but streaming not yet started. Configuration settings
            of the auto and image processing algorithms may be accessed and
            altered.
 *
 * @param   hCamEngine  Handle to the CamEngine instance.
 * @param   pConfig     Configuration structure.
 *
 * @return  Return the result of the function call.
 * @return  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamEngineStart_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    CamEngineConfig_ry_t   *pConfig
);


/*****************************************************************************/
/**
 * @brief   The function stops a CamEngine instance.
 *
 * @param   hCamEngine  Handle to the CamEngine instance.
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state
 *
 *****************************************************************************/
RESULT CamEngineStop_ry
(
    CamEngineHandle_ry_t   hCamEngine
);


/*****************************************************************************/
/**
 * @brief   This function starts streaming. This puts the CamEngine
 *          into the streaming state.
 *
 * @param   hCamEngine      Handle to the CamEngine instance.
 * @param   frames          Number of frames to capture, frames = 0, means continuously.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state
 *
 *****************************************************************************/
RESULT CamEngineStartStreaming_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    uint32_t            frames
);


/*****************************************************************************/
/**
 * @brief   This function stops streaming.
 *
 * @param   hCamEngine      Handle to the CamEngine instance.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state
 *
 *****************************************************************************/
RESULT CamEngineStopStreaming_ry
(
    CamEngineHandle_ry_t   hCamEngine
);


/*****************************************************************************/
/**
 * @brief   This function registers a buffer callback. Only one buffer callback
 *          may be registered at a time.
 *
 * @param   hCamEngine      Handle to the CamEngine instance.
 * @param   fpCallback      Buffer callback to register.
 * @param   pUserContext    User context to pass on to callback.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NULL_POINTER    callback is null pointer
 * @retval  RET_WRONG_STATE     instance is in wrong state
 *
 *****************************************************************************/
RESULT CamEngineRegisterBufferCb_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    CamEngineBufferCb_ry_t fpCallback,
    void*               pBufferCbCtx
);


/*****************************************************************************/
/**
 * @brief   This function unregisters the buffer callback.
 *
 * @param   hCamEngine      Handle to the CamEngine instance.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state
 *
 *****************************************************************************/
RESULT CamEngineDeRegisterBufferCb_ry
(
    CamEngineHandle_ry_t   hCamEngine
);


/*****************************************************************************/
/**
 * @brief   This function returns the current buffer callback.
 *
 * @param   hCamEngine      Handle to the CamEngine instance.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state
 *
 *****************************************************************************/
RESULT CamEngineGetBufferCb_ry
(
    CamEngineHandle_ry_t    hCamEngine,
    CamEngineBufferCb_ry_t* fpCallback,
    void**               ppBufferCbCtx
);


/*****************************************************************************/
/**
 * @brief   This function returns the state of the CamEngine.
 *
 * @param   hCamEngine      Handle to the CamEngine instance.
 *
 * @return  Return the the state of the CamEngine.
 *
 *****************************************************************************/
CamEngineState_ry_t CamEngineGetState_ry
(
    CamEngineHandle_ry_t   hCamEngine
);


/*****************************************************************************/
/**
 * @brief   This function sets the configuration of main and self path.
 *
 * @param   hCamEngine      Handle to the CamEngine instance.
 * @param   pConfigMain     Configuration structure for main path.
 * @param   pConfigSelf     Configuration structure for self path.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state
 *
 *****************************************************************************/
RESULT CamEngineSetPathConfig_ry
(
    CamEngineHandle_ry_t               hCamEngine,
    const CamEnginePathConfig_ry_t     pConfig[CAM_ENGINE_PATH_MAX_RY]
);


/*****************************************************************************/
/**
 * @brief   This function sets the configuration of main and self path.
 *
 * @param   hCamEngine      Handle to the CamEngine instance.
 * @param   pConfigMain     Configuration structure for main path.
 * @param   pConfigSelf     Configuration structure for self path.
 * @param   numFramesToSkip Number of frames to skip.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state
 *
 *****************************************************************************/
RESULT CamEngineSetAcqResolution_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    CamEngineWindow_ry_t   acqWindow,
    CamEngineWindow_ry_t   outWindow,
    CamEngineWindow_ry_t   isWindow,
    uint32_t            numFramesToSkip
);


/*****************************************************************************/
/**
 * @brief   This function sets the configuration of the ECM.
 *
 * @param   hCamEngine          Handle to the CamEngine instance.
 * @param   flickerPeriod       Flicker period ID.
 * @param   enableAfps          Enable AFPS mode.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
RESULT CamEngineSetEcm_ry
(
    CamEngineHandle_ry_t           hCamEngine,
    CamEngineFlickerPeriod_ry_t    flickerPeriod,
    bool_t                      enableAfps
);


/*****************************************************************************/
/**
 * @brief   This function sets the configuration of main and self path.
 *
 * @param   hCamEngine      Handle to the CamEngine instance.
 * @param   pConfigMain     Configuration structure for main path.
 * @param   pConfigSelf     Configuration structure for self path.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state
 *
 *****************************************************************************/
RESULT CamEngineSetCalibDb_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    CamCalibDbHandle_t  hCamCalibDb

);


/*****************************************************************************/
/**
 * @brief   This function runs the auto algorithms and locks the settings
            of the requested locks, e.g. autofocus, auto exposure control
            and auto white balance.
 *
 * @param   hCamEngine      Handle to the CamEngine instance.
 * @param   locks              Requested locks, locks = 0xFF, means all.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state
 *
 *****************************************************************************/
RESULT CamEngineSearchAndLock_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    CamEngineLockType_t locks
);


/*****************************************************************************/
/**
 * @brief   This function cancels the requested locks if locked.
 *
 * @param   hCamEngine      Handle to the CamEngine instance.
 * @param   locks           Requested locks, locks = 0xFF, means all.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state
 *
 *****************************************************************************/
RESULT CamEngineUnlock_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    CamEngineLockType_t locks
);


/*****************************************************************************/
/**
 * @brief   The function update the dma input resolution and config mi data.
 *          This is avaliable when CamEngine in the running state. T
 *
 * @param   hCamEngine  Handle to the CamEngine instance.
 * @param   pConfig     Configuration structure.
 *
 * @return  Return the result of the function call.
 * @return  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/

uint32_t CamEngineUpdateIspResolution_ry(
    CamEngineHandle_ry_t   hCamEngine,
    CamEngineConfig_ry_t   *pConfig
);

int CamEngineGetHwResources_ry();

uint32_t CamEngineGetIspStatus_ry();

uint32_t CamEngineGetIspFeatrue_ry();

uint32_t CamEngineGetFeatureVersion_ry();

RESULT CamEngineGetFullMetadata_ry(CamEngineHandle_ry_t hCamEngine, int path, struct isp_metadata *meta);

RESULT CamEngineInitHdrMode_ry(CamEngineHandle_ry_t hCamEngine, bool_t enableHDR);
#ifdef __cplusplus
}
#endif


/* @} cam_engine_api */


#endif /* __CAM_ENGINE_RY_API_H__ */

