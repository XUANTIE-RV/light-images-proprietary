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
 * @file cam_engine_common.h
 *
 * @brief
 *   Common definitions of the CamEngine.
 *
 *****************************************************************************/
/**
 *
 * @defgroup cam_engine_common CamEngine Common Definitions
 * @{
 *
 */
#ifndef __CAM_ENGINE_COMMON_RY_H__
#define __CAM_ENGINE_COMMON_RY_H__
#include <cam_device/cam_device_ispcore_defs_ry.h>


#ifdef __cplusplus
extern "C"
{
#endif


/*****************************************************************************/
/**
 * @brief   Handle to a CamEngine instance.
 *
 *****************************************************************************/
typedef struct CamEngineContext_ry_s *CamEngineHandle_ry_t;


/*****************************************************************************/
/**
 * @brief   Commands for the CamEngine
 *
 *****************************************************************************/
typedef enum CamEngineCmdId_ry_e
{
    CAM_ENGINE_CMD_INVALID_RY                  = 0,    /**< invalid command (only for initialization) */
    CAM_ENGINE_CMD_START_RY                    = 1,    /**< start a cam-engine instance */
    CAM_ENGINE_CMD_STOP_RY                     = 2,    /**< stop a cam-engine instance */
    CAM_ENGINE_CMD_SHUTDOWN_RY                 = 3,    /**< shutdown a stopped cam-engine instance */

    CAM_ENGINE_CMD_START_STREAMING_RY          = 4,    /**< start streaming */
    CAM_ENGINE_CMD_STOP_STREAMING_RY           = 5,    /**< stop streaming */

    CAM_ENGINE_CMD_ACQUIRE_LOCK_RY             = 6,    /**< locks the auto algorithms */
    CAM_ENGINE_CMD_RELEASE_LOCK_RY             = 7,    /**< releases locks of the auto algorithms */

    CAM_ENGINE_CMD_INTERNAL_BASE_RY            = 1000,                                 /**< base for internal commands */
    CAM_ENGINE_CMD_AAA_LOCKED_RY               = (CAM_ENGINE_CMD_INTERNAL_BASE_RY + 0),   /**< selected auto-algorithms are locked now */
    CAM_ENGINE_CMD_HW_STREAMING_FINISHED_RY    = (CAM_ENGINE_CMD_INTERNAL_BASE_RY + 20),  /**< send by CamerIc hw, if ISP disabled (streaming finished) */
    CAM_ENGINE_CMD_HW_DMA_FINISHED_RY          = (CAM_ENGINE_CMD_INTERNAL_BASE_RY + 21),  /**< send by CamerIc hw, if DMA transfer completed */
    CAM_ENGINE_CMD_HW_JPE_DATA_ENCODED_RY      = (CAM_ENGINE_CMD_INTERNAL_BASE_RY + 22),  /**< send by CamerIc hw, if JPE data encoded */
    CAM_ENGINE_CMD_HW_DMA_TRANSFER_RY          = (CAM_ENGINE_CMD_INTERNAL_BASE_RY + 23),  /**<DMA TRANSFER load picture again while state is streaming */
    CAM_ENGINE_CMD_MAX_RY
} CamEngineCmdId_ry_t;


/*****************************************************************************/
/**
 * @brief States of the CamEngine.
 *
 *****************************************************************************/
typedef enum CamEngineState_ry_e
{
    eCamEngineStateInvalid_ry    = 0x0000,   /**< FSM state is invalid since CamEngine instance does not exist. */
    eCamEngineStateInitialize_ry = 0x0001,   /**< FSM is in state initialized. */
    eCamEngineStateRunning_ry    = 0x0002,   /**< FSM is in state running. */
    eCamEngineStateStreaming_ry  = 0x0003,   /**< FSM is in state streaming. */
    CAM_ENGINE_STATE_MAX_ry
} CamEngineState_ry_t;


/*****************************************************************************/
/**
 * @brief Processing paths of the CamEngine.
 *
 *****************************************************************************/
typedef enum CamEnginePathType_ry_e
{
    CAM_ENGINE_PATH_INVALID_RY = -1,
    CAM_ENGINE_PATH_MAIN_RY    = 0,
    CAM_ENGINE_PATH_SELF_RY    = 1,
    CAM_ENGINE_PATH_SELF2_BP_RY   = 2,
#ifdef ISP_MI_MCM_WR_RY
    CAM_ENGINE_PATH_MCM_WR0_RY   ,
    CAM_ENGINE_PATH_MCM_WR1_RY   ,
#endif
#ifdef ISP_MI_PP_WRITE_RY
    CAM_ENGINE_PATH_POST_PROCESS_RY   ,
#endif
#ifdef ISP_MI_HDR_RY
    CAM_ENGINE_PATH_HDR_L_RY,
    CAM_ENGINE_PATH_HDR_S_RY,
    CAM_ENGINE_PATH_HDR_VS_RY,
#endif
    CAM_ENGINE_PATH_RDI_RY ,
    CAM_ENGINE_PATH_META_RY,
    CAM_ENGINE_PATH_MAX_RY
} CamEnginePathType_ry_t;


/*****************************************************************************/
/**
 * @brief Input config types of the CamEngine.
 *
 *****************************************************************************/
#define TEST_ENG_TYPE_IMAGE_RY 1
#define TEST_ENG_TYPE_SENSOR_RY 2
#define TEST_ENG_TYPE_TPG_RY 3

typedef enum CamEngineConfigType_ry_e
{
    CAM_ENGINE_CONFIG_INVALID_RY = 0,
    CAM_ENGINE_CONFIG_SENSOR_RY  = 1,
    CAM_ENGINE_CONFIG_IMAGE_RY   = 2,
    CAM_ENGINE_CONFIG_TPG_RY     = 3,
    CAM_ENGINE_CONFIG_MAX_RY     = 4
} CamEngineConfigType_ry_t;


/*****************************************************************************/
/**
 * @brief Flicker period types for the AEC algorithm.
 *
 *****************************************************************************/
typedef enum CamEngineFlickerPeriod_ry_e
{
    CAM_ENGINE_FLICKER_OFF_RY   = 0x00,
    CAM_ENGINE_FLICKER_100HZ_RY = 0x01,
    CAM_ENGINE_FLICKER_120HZ_RY = 0x02
} CamEngineFlickerPeriod_ry_t;


/*****************************************************************************/
/**
 *  @brief Command completion signaling callback
 *
 *  Callback for signaling command completion which could require application
 *  interaction. The cmdId (see @ref CamEngineCmdId_ry_t) identifies the completed
 *  command.
 *
 *****************************************************************************/
typedef void (* CamEngineCompletionCb_ry_t)
(
    CamEngineCmdId_ry_t    cmdId,          /**< command Id of the notifying event */
    RESULT              result,         /**< result of the executed command */
    const void          *pUserCbCtx     /**< user data pointer that was passed on creation (see @ref CamEngineInstanceConfig_ry_t) */
);


/*****************************************************************************/
/**
 *  @brief AFPS resolution change request signaling callback
 *
 *  Callback for signaling an AFPS resolution (better: frame rate) change
 *  request to the application.
 *
 *****************************************************************************/
typedef void (*CamEngineAfpsResChangeCb_ry_t)
(
    uint32_t            NewResolution,  /**< new resolution to switch to */
    const void          *pUserCbCtx     /**< user data pointer that was passed on creation (see @ref CamEngineInstanceConfig_ry_t) */
);


/*****************************************************************************/
/**
 *  @brief Full buffer signaling callback
 *
 *  Callback for signaling a full buffer which should be handled by the
 *  application. The path (see @ref CamEnginePath_t) identifies the output
 *  path.
 *
 *****************************************************************************/
typedef void (*CamEngineBufferCb_ry_t)
(
    CamEnginePathType_ry_t path,           /**< output path of the media buffer */
    MediaBuffer_t       *pMediaBuffer,  /**< full media buffer */
    void                *pBufferCbCtx   /**< user data pointer that was passed on registering the callback (see @ref CamEngineRegisterBufferCb) */
);


/*****************************************************************************/
/**
 * @brief   Configuration structure of the output path.
 *
 *****************************************************************************/
typedef struct CamEnginePathConfig_ry_s
{
    uint16_t                width;
    uint16_t                height;
    CamerIcMiDataMode_ry_t     mode;
    CamerIcMiDataLayout_ry_t   layout;
    CamerIcMiDataAlignMode_ry_t   alignMode;
    bool_t                  yuv_bit;
} CamEnginePathConfig_ry_t;


/*****************************************************************************/
/**
 * @brief   Generic structure to define a window.
 *
 *****************************************************************************/
typedef struct CamEngineWindow_ry_s
{
    uint16_t    hOffset;
    uint16_t    vOffset;
    uint16_t    width;
    uint16_t    height;
} CamEngineWindow_ry_t;


/*****************************************************************************/
/**
 * @brief   Generic structure to define a vector.
 *
 *****************************************************************************/
typedef struct CamEngineVector_ry_s
{
    int16_t   x;
    int16_t   y;
} CamEngineVector_ry_t;


/*****************************************************************************/
/**
 * @brief   Generic structure for the white balance gains of the four color
 *          components.
 *
 *****************************************************************************/
typedef struct CamEngineWbGains_ry_s
{
    float Red;
    float GreenR;
    float GreenB;
    float Blue;
} CamEngineWbGains_ry_t;


/*****************************************************************************/
/**
 * @brief   Generic structure for the cross talk matrix of the four color
 *          components.
 *
 *****************************************************************************/
typedef struct CamEngineCcMatrix_ry_s
{
    float Coeff[9U];
} CamEngineCcMatrix_ry_t;


/*****************************************************************************/
/**
 * @brief   Generic structure for the cross talk offset of the four color
 *          components.
 *
 *****************************************************************************/
typedef struct CamEngineCcOffset_ry_s
{
    int16_t Red;
    int16_t Green;
    int16_t Blue;
} CamEngineCcOffset_ry_t;


/*****************************************************************************/
/**
 * @brief   Generic structure for the black level of the four color components.
 *
 *****************************************************************************/
typedef struct CamEngineBlackLevel_ry_s
{
    uint16_t Red;
    uint16_t GreenR;
    uint16_t GreenB;
    uint16_t Blue;
} CamEngineBlackLevel_ry_t;

typedef enum CamEngineExpV2Sel_ry_e
{
    CAM_ENGINE_AEV2_INPUT_SEL_DEGAMMA_RY       = 0,
    CAM_ENGINE_AEV2_INPUT_SEL_AWBGAIN_RY       = 1,
    CAM_ENGINE_AEV2_INPUT_SEL_WDR3_RY          = 2
} CamEngineExpV2Sel_ry_t;

typedef struct CamEngineAev2Cfg_ry_s
{
    unsigned int vOffset;
    unsigned int hOffset;
    unsigned int width;
    unsigned int height;

    uint8_t rWeight;
    uint8_t grWeight;
    uint8_t gbWeight;
    uint8_t bWeight;
    CamEngineExpV2Sel_ry_t input_sel;
} CamEngineAev2Cfg_ry_t;





typedef enum CamEngineAtdnrMode_ry_e
{
    CAM_ENGINE_ATDNR_MODE_INVALID_RY = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_ATDNR_MODE_MANUAL_RY  = 1,    /**< manual mode */
    CAM_ENGINE_ATDNR_MODE_AUTO_RY    = 2,    /**< run auto mode */
    CAM_ENGINE_ATDNR_MODE_MAX_RY
} CamEngineAtdnrMode_ry_t;

typedef struct CamEngineTdnrConfig_ry_s
{
    uint16_t    noiseLevel;
    uint8_t     motionSlope;
    uint8_t     sadWeight;
    uint16_t    filterLength1;
    uint8_t     filterLength2;
} CamEngineTdnrConfig_ry_t;

typedef struct CamEngineAtdnrParamNode_ry_s
{
    float                    gain;
    float                    integrationTime;
    CamEngineTdnrConfig_ry_t    config;
} CamEngineAtdnrParamNode_ry_t;

#if 0
typedef enum CamEngineA2dnrV5Mode_ry_e
{
    CAM_ENGINE_A2DNRv5_MODE_INVALID_RY = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_A2DNRv5_MODE_MANUAL_RY  = 1,    /**< manual mode */
    CAM_ENGINE_A2DNRv5_MODE_AUTO_RY    = 2,    /**< run auto mode */
    CAM_ENGINE_A2DNRv5_MODE_MAX_RY
} CamEngineA2dnrV5Mode_ry_t;
#endif

typedef struct CamEngine2dnrV5Config_ry_s
{
    float       strength;                     /**< strength */
    float       sigma;                        /**< sigma */
    uint8_t     blendingOpacityStaticArea;    /**< blendingOpacityStaticArea */
    uint8_t     blendingOpacityMovingArea;    /**< blendingOpacityMovingArea, should big then blendingOpacityStaticArea */
} CamEngine2dnrV5Config_ry_t;

typedef struct CamEngineA2dnrV5ParamNode_ry_s
{
    float                        gain;
    float                        integrationTime;
    CamEngine2dnrV5Config_ry_t      config;
} CamEngineA2dnrV5ParamNode_ry_t;

typedef enum CamEngineAhdrMode_ry_e
{
    CAM_ENGINE_AHDR_MODE_INVALID_RY    = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_AHDR_MODE_MANUAL_RY     = 1,    /**< manual mode */
    CAM_ENGINE_AHDR_MODE_AUTO_RY       = 2,    /**< run auto mode with fix exposure setpoint */
    CAM_ENGINE_AHDR_MODE_MAX_RY
} CamEngineAhdrMode_ry_t;

typedef enum CamEngineHdrBaseFrameType_ry_e
{
    CAM_ENGINE_HDR_BASE_FRAME_INVALID_RY = 0,
    CAM_ENGINE_HDR_BASE_FRAM_SHORT_RY    = 1,
    CAM_ENGINE_HDR_BASE_FRAM_LONG_RY     = 2,
    CAM_ENGINE_HDR_BASE_FRAM_MAX_RY
} CamEngineHdrBaseFrameType_ry_t;

typedef enum CamEngineHdrDolType_ry_e
{
    CAM_ENGINE_HDR_TYPE_INVALID_RY = 0,
    CAM_ENGINE_HDR_TYPE_2DOL_RY    = 1,
    CAM_ENGINE_HDR_TYPE_3DOL_RY    = 2,
    CAM_ENGINE_HDR_TYPE_MAX_RY
} CamEngineHdrDolType_ry_t;


typedef struct CamEngineHdrConfig_ry_s {
    float c1;
    float c2;
    float ceil;
    float setPoint2;
    float tolerance;
    float objectFactor;
    float maxRatio;
    float minRatio;
} CamEngineHdrConfig_ry_t;

//only used for CAM_ENGINE_AHDR_MODE_AUTO_EXP_ADPTIVE
typedef struct CamEngineHdrParamNode_ry_s {
    float gain;
    float integrationTime;
    float setPointScale;
    float setPoint2Scale;
    float c1;
    float c2;
    float ceil;
} CamEngineAhdrParamNode_ry_t;

typedef struct CamEngineHdrStatus_ry_s {
    bool_t running;
    CamEngineAhdrMode_ry_t mode;
} CamEngineHdrStatus_ry_t;


typedef struct CamEngineWdr4Config_ry_s {
    uint8_t     strength;
    uint8_t     highStrength;
    uint8_t     lowStrength;
    uint8_t     globalStrength;
    uint16_t    contrast;
    uint8_t     flatStrength;
    uint8_t     flatThreshold;
} CamEngineWdr4Config_ry_t;

typedef struct CamEngineAwdr4ParamNode_ry_s
{
    float gain;
    float integrationTime;
    CamEngineWdr4Config_ry_t config;
} CamEngineAwdr4ParamNode_ry_t;

#define CA_CURVE_DATA_TABLE_LEN  65
typedef enum CamEngineAcaMode_ry_e
{
    CAM_ENGINE_ACA_MODE_INVALID_RY = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_ACA_MODE_MANUAL_RY  = 1,    /**< manual mode */
    CAM_ENGINE_ACA_MODE_AUTO_RY   = 2,    /**< run auto mode */
    CAM_ENGINE_ACA_MODE_MAX_RY
} CamEngineAcaMode_ry_t;

typedef enum CamEngineColorAdjustMode_ry_e
{
    CAM_ENGINE_COLOR_ADJUST_MODE_INVALID_RY     = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_COLOR_ADJUST_MODE_BRIGHTNESS_RY = 1,
    CAM_ENGINE_COLOR_ADJUST_MODE_SATURATION_RY = 2,
    CAM_ENGINE_COLOR_ADJUST_MODE_BOTH_RY        = 3,
    CAM_ENGINE_COLOR_ADJUST_MODE_MAX_RY
} CamEngineColorAdjustMode_ry_t;

typedef enum CamEngineColorAdjustCurve_ry_e
{
    CAM_ENGINE_COLOR_ADJUST_CURVE_INVALID_RY     = 0,    /**< invalid curve (only for initialization) */
    CAM_ENGINE_COLOR_ADJUST_CURVE_S_RY            = 1,
    CAM_ENGINE_COLOR_ADJUST_CURVE_PARABOLIC_RY = 2,
    CAM_ENGINE_COLOR_ADJUST_CURVE_MAX_RY
} CamEngineColorAdjustCurve_ry_t;

typedef struct CamEngineCaCurvePoint_ry_s
{
    uint8_t xValue;
    uint16_t yValue;
} CamEngineCaCurvePoint_ry_t;

typedef struct CamEngineCaConfig_ry_s
{
    CamEngineColorAdjustMode_ry_t mode;
    CamEngineColorAdjustCurve_ry_t curveType;
    uint8_t sCurveInflection;
    uint8_t sCurveExponent;
    float parabolicFactor;
} CamEngineCaConfig_ry_t;

typedef struct CamEngineAcaParamNode_ry_s
{
    float gain;
    float integrationTime;
    uint8_t sCurveInflection;
    uint8_t sCurveExponent;
    float parabolicFactor;
} CamEngineAcaParamNode_ry_t;

typedef struct CamEngineAcaStatus_ry_s
{
    CamEngineAcaParamNode_ry_t params;
    uint16_t chroma[CA_CURVE_DATA_TABLE_LEN];
} CamEngineAcaStatus_ry_t;

typedef enum CamEngineAdciMode_ry_e
{
    CAM_ENGINE_ADCI_MODE_INVALID_RY = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_ADCI_MODE_MANUAL_RY  = 1,    /**< manual mode */
    CAM_ENGINE_ADCI_MODE_AUTO_RY    = 2,    /**< run auto mode */
    CAM_ENGINE_ADCI_MODE_HIST_RY    = 3,
    CAM_ENGINE_ADCI_MODE_MAX_RY
} CamEngineAdciMode_ry_t;

typedef enum CamEngineDciCurveMode_ry_e
{
    CAM_ENGINE_DCI_CURVE_MODE_INVALID_RY   = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_DCI_CURVE_MODE_SECTION2_RY  = 1,
    CAM_ENGINE_DCI_CURVE_MODE_SECTION3_RY  = 2,
    CAM_ENGINE_DCI_CURVE_MODE_HISTOGRAM_RY = 3,
    CAM_ENGINE_DCI_CURVE_MODE_MAX_RY
} CamEngineDciCurveMode_ry_t;

typedef struct CamEngineDciSectionContext_ry_s
{
    float lowExponent;
    float middleExponent;
    float highExponent;
    uint16_t pStartX;
    uint16_t pStartY;
    uint16_t pInflectionX;
    uint16_t pInflectionY;
    uint16_t pEndX;
    uint16_t pEndY;
    uint16_t pInflection2X;    /* only for 3 section mode */
    uint16_t pInflection2Y;    /* only for 3 section mode */
} CamEngineDciSectionContext_ry_t;

typedef struct CamEngineHistogramContext_ry_s
{
    float scale;
    float stepSize;
    float base;
    float strength;
    float damp;
} CamEngineDciHistogramContext_ry_t;

typedef struct CamEngineDciConfig_ry_s
{
    CamEngineDciCurveMode_ry_t mode;
    CamEngineDciSectionContext_ry_t sectionContext;
    CamEngineDciHistogramContext_ry_t histogramContext;
} CamEngineDciConfig_ry_t;

typedef struct CamEngineAdciParamNode_ry_s
{
    float gain;
    float integrationTime;
    CamEngineDciSectionContext_ry_t sectionContext;
    CamEngineDciHistogramContext_ry_t histogramContext;
} CamEngineAdciParamNode_ry_t;

typedef struct CamEngineAdciStatus_ry_s
{
    CamEngineDciCurveMode_ry_t mode;
    CamEngineAdciParamNode_ry_t params;
    uint16_t luma[CA_CURVE_DATA_TABLE_LEN];
} CamEngineAdciStatus_ry_t;



enum {
    CAM_ENGINE_MODULE_INIT_RY = 0,
    CAM_ENGINE_MODULE_EE_RY,
    CAM_ENGINE_MODULE_AHDR_RY,
    CAM_ENGINE_MODULE_TDNR_RY,
    CAM_ENGINE_MODULE_2DNRV5_RY,
    CAM_ENGINE_MODULE_WDR4_RY,
    CAM_ENGINE_MODULE_CA_RY,
    CAM_ENGINE_MODULE_DCI_RY,
    CAM_ENGINE_MODULE_CPROC_RY,
    CAM_ENGINE_MODULE_GAMMA64_RY,
    CAM_ENGINE_MODULE_DPF_RY,
    CAM_ENGINE_MODULE_DGAIN_RY,
    CAM_ENGINE_MODULE_DMSC2_RY,
};

enum {
    CAM_ENGINE_MODE_OFF_RY = 0,
    CAM_ENGINE_MODE_MANUAL_RY,
    CAM_ENGINE_MODE_AUTO_RY,
};
#ifdef __cplusplus
}
#endif


/* @} cam_engine_common */


#endif /* __CAM_ENGINE_COMMON_RY_H__ */

