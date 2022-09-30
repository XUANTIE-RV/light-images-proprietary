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
#ifndef __CAM_ENGINE_COMMON_H__
#define __CAM_ENGINE_COMMON_H__
#include <cam_device/cam_device_ispcore_defs.h>


#ifdef __cplusplus
extern "C"
{
#endif


/*****************************************************************************/
/**
 * @brief   Handle to a CamEngine instance.
 *
 *****************************************************************************/
typedef struct CamEngineContext_s *CamEngineHandle_t;


/*****************************************************************************/
/**
 * @brief   Commands for the CamEngine
 *
 *****************************************************************************/
typedef enum CamEngineCmdId_e
{
    CAM_ENGINE_CMD_INVALID                  = 0,    /**< invalid command (only for initialization) */
    CAM_ENGINE_CMD_START                    = 1,    /**< start a cam-engine instance */
    CAM_ENGINE_CMD_STOP                     = 2,    /**< stop a cam-engine instance */
    CAM_ENGINE_CMD_SHUTDOWN                 = 3,    /**< shutdown a stopped cam-engine instance */

    CAM_ENGINE_CMD_START_STREAMING          = 4,    /**< start streaming */
    CAM_ENGINE_CMD_STOP_STREAMING           = 5,    /**< stop streaming */

    CAM_ENGINE_CMD_ACQUIRE_LOCK             = 6,    /**< locks the auto algorithms */
    CAM_ENGINE_CMD_RELEASE_LOCK             = 7,    /**< releases locks of the auto algorithms */

    CAM_ENGINE_CMD_INTERNAL_BASE            = 1000,                                 /**< base for internal commands */
    CAM_ENGINE_CMD_AAA_LOCKED               = (CAM_ENGINE_CMD_INTERNAL_BASE + 0),   /**< selected auto-algorithms are locked now */
    CAM_ENGINE_CMD_HW_STREAMING_FINISHED    = (CAM_ENGINE_CMD_INTERNAL_BASE + 20),  /**< send by CamerIc hw, if ISP disabled (streaming finished) */
    CAM_ENGINE_CMD_HW_DMA_FINISHED          = (CAM_ENGINE_CMD_INTERNAL_BASE + 21),  /**< send by CamerIc hw, if DMA transfer completed */
    CAM_ENGINE_CMD_HW_JPE_DATA_ENCODED      = (CAM_ENGINE_CMD_INTERNAL_BASE + 22),  /**< send by CamerIc hw, if JPE data encoded */
    CAM_ENGINE_CMD_HW_DMA_TRANSFER          = (CAM_ENGINE_CMD_INTERNAL_BASE + 23),  /**<DMA TRANSFER load picture again while state is streaming */
    CAM_ENGINE_CMD_MAX
} CamEngineCmdId_t;


/*****************************************************************************/
/**
 * @brief States of the CamEngine.
 *
 *****************************************************************************/
typedef enum CamEngineState_e
{
    eCamEngineStateInvalid    = 0x0000,   /**< FSM state is invalid since CamEngine instance does not exist. */
    eCamEngineStateInitialize = 0x0001,   /**< FSM is in state initialized. */
    eCamEngineStateRunning    = 0x0002,   /**< FSM is in state running. */
    eCamEngineStateStreaming  = 0x0003,   /**< FSM is in state streaming. */
    CAM_ENGINE_STATE_MAX
} CamEngineState_t;


/*****************************************************************************/
/**
 * @brief Processing paths of the CamEngine.
 *
 *****************************************************************************/
typedef enum CamEnginePathType_e
{
    CAM_ENGINE_PATH_INVALID = -1,
    CAM_ENGINE_PATH_MAIN    = 0,
    CAM_ENGINE_PATH_SELF    = 1,
    CAM_ENGINE_PATH_SELF2_BP   = 2,
#ifdef ISP_MI_MCM_WR
    CAM_ENGINE_PATH_MCM_WR0   ,
    CAM_ENGINE_PATH_MCM_WR1   ,
#endif
#ifdef ISP_MI_PP_WRITE
    CAM_ENGINE_PATH_POST_PROCESS   ,
#endif
#ifdef ISP_MI_HDR
    CAM_ENGINE_PATH_HDR_L,
    CAM_ENGINE_PATH_HDR_S,
    CAM_ENGINE_PATH_HDR_VS,
#endif
    CAM_ENGINE_PATH_RDI ,
    CAM_ENGINE_PATH_META,
    CAM_ENGINE_PATH_MAX
} CamEnginePathType_t;


/*****************************************************************************/
/**
 * @brief Input config types of the CamEngine.
 *
 *****************************************************************************/
#define TEST_ENG_TYPE_IMAGE 1
#define TEST_ENG_TYPE_SENSOR 2
#define TEST_ENG_TYPE_TPG 3

typedef enum CamEngineConfigType_e
{
    CAM_ENGINE_CONFIG_INVALID = 0,
    CAM_ENGINE_CONFIG_SENSOR  = 1,
    CAM_ENGINE_CONFIG_IMAGE   = 2,
    CAM_ENGINE_CONFIG_TPG     = 3,
    CAM_ENGINE_CONFIG_MAX     = 4
} CamEngineConfigType_t;


/*****************************************************************************/
/**
 * @brief Flicker period types for the AEC algorithm.
 *
 *****************************************************************************/
typedef enum CamEngineFlickerPeriod_e
{
    CAM_ENGINE_FLICKER_OFF   = 0x00,
    CAM_ENGINE_FLICKER_100HZ = 0x01,
    CAM_ENGINE_FLICKER_120HZ = 0x02
} CamEngineFlickerPeriod_t;


/*****************************************************************************/
/**
 *  @brief Command completion signaling callback
 *
 *  Callback for signaling command completion which could require application
 *  interaction. The cmdId (see @ref CamEngineCmdId_t) identifies the completed
 *  command.
 *
 *****************************************************************************/
typedef void (* CamEngineCompletionCb_t)
(
    CamEngineCmdId_t    cmdId,          /**< command Id of the notifying event */
    RESULT              result,         /**< result of the executed command */
    const void          *pUserCbCtx     /**< user data pointer that was passed on creation (see @ref CamEngineInstanceConfig_t) */
);


/*****************************************************************************/
/**
 *  @brief AFPS resolution change request signaling callback
 *
 *  Callback for signaling an AFPS resolution (better: frame rate) change
 *  request to the application.
 *
 *****************************************************************************/
typedef void (*CamEngineAfpsResChangeCb_t)
(
    uint32_t            NewResolution,  /**< new resolution to switch to */
    const void          *pUserCbCtx     /**< user data pointer that was passed on creation (see @ref CamEngineInstanceConfig_t) */
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
typedef void (*CamEngineBufferCb_t)
(
    CamEnginePathType_t path,           /**< output path of the media buffer */
    MediaBuffer_t       *pMediaBuffer,  /**< full media buffer */
    void                *pBufferCbCtx   /**< user data pointer that was passed on registering the callback (see @ref CamEngineRegisterBufferCb) */
);


/*****************************************************************************/
/**
 * @brief   Configuration structure of the output path.
 *
 *****************************************************************************/
typedef struct CamEnginePathConfig_s
{
    uint16_t                width;
    uint16_t                height;
    CamerIcMiDataMode_t     mode;
    CamerIcMiDataLayout_t   layout;
    CamerIcMiDataAlignMode_t   alignMode;
    bool_t                  yuv_bit;
} CamEnginePathConfig_t;


/*****************************************************************************/
/**
 * @brief   Generic structure to define a window.
 *
 *****************************************************************************/
typedef struct CamEngineWindow_s
{
    uint16_t    hOffset;
    uint16_t    vOffset;
    uint16_t    width;
    uint16_t    height;
} CamEngineWindow_t;


/*****************************************************************************/
/**
 * @brief   Generic structure to define a vector.
 *
 *****************************************************************************/
typedef struct CamEngineVector_s
{
    int16_t   x;
    int16_t   y;
} CamEngineVector_t;


/*****************************************************************************/
/**
 * @brief   Generic structure for the white balance gains of the four color
 *          components.
 *
 *****************************************************************************/
typedef struct CamEngineWbGains_s
{
    float Red;
    float GreenR;
    float GreenB;
    float Blue;
} CamEngineWbGains_t;


/*****************************************************************************/
/**
 * @brief   Generic structure for the cross talk matrix of the four color
 *          components.
 *
 *****************************************************************************/
typedef struct CamEngineCcMatrix_s
{
    float Coeff[9U];
} CamEngineCcMatrix_t;


/*****************************************************************************/
/**
 * @brief   Generic structure for the cross talk offset of the four color
 *          components.
 *
 *****************************************************************************/
typedef struct CamEngineCcOffset_s
{
    int16_t Red;
    int16_t Green;
    int16_t Blue;
} CamEngineCcOffset_t;


/*****************************************************************************/
/**
 * @brief   Generic structure for the black level of the four color components.
 *
 *****************************************************************************/
typedef struct CamEngineBlackLevel_s
{
    uint16_t Red;
    uint16_t GreenR;
    uint16_t GreenB;
    uint16_t Blue;
} CamEngineBlackLevel_t;

typedef enum CamEngineExpV2Sel_e
{
    CAM_ENGINE_AEV2_INPUT_SEL_DEGAMMA       = 0,
    CAM_ENGINE_AEV2_INPUT_SEL_AWBGAIN       = 1,
    CAM_ENGINE_AEV2_INPUT_SEL_WDR3          = 2
} CamEngineExpV2Sel_t;

typedef struct CamEngineAev2Cfg_s
{
    unsigned int vOffset;
    unsigned int hOffset;
    unsigned int width;
    unsigned int height;

    uint8_t rWeight;
    uint8_t grWeight;
    uint8_t gbWeight;
    uint8_t bWeight;
    CamEngineExpV2Sel_t input_sel;
} CamEngineAev2Cfg_t;





typedef enum CamEngineAtdnrMode_e
{
    CAM_ENGINE_ATDNR_MODE_INVALID = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_ATDNR_MODE_MANUAL  = 1,    /**< manual mode */
    CAM_ENGINE_ATDNR_MODE_AUTO    = 2,    /**< run auto mode */
    CAM_ENGINE_ATDNR_MODE_MAX
} CamEngineAtdnrMode_t;

typedef struct CamEngineTdnrConfig_s
{
    uint16_t    noiseLevel;
    uint8_t     motionSlope;
    uint8_t     sadWeight;
    uint16_t    filterLength1;
    uint8_t     filterLength2;
} CamEngineTdnrConfig_t;

typedef struct CamEngineAtdnrParamNode_s
{
    float                    gain;
    float                    integrationTime;
    CamEngineTdnrConfig_t    config;
} CamEngineAtdnrParamNode_t;

#if 0
typedef enum CamEngineA2dnrV5Mode_e
{
    CAM_ENGINE_A2DNRv5_MODE_INVALID = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_A2DNRv5_MODE_MANUAL  = 1,    /**< manual mode */
    CAM_ENGINE_A2DNRv5_MODE_AUTO    = 2,    /**< run auto mode */
    CAM_ENGINE_A2DNRv5_MODE_MAX
} CamEngineA2dnrV5Mode_t;
#endif

typedef struct CamEngine2dnrV5Config_s
{
    float       strength;                     /**< strength */
    float       sigma;                        /**< sigma */
    uint8_t     blendingOpacityStaticArea;    /**< blendingOpacityStaticArea */
    uint8_t     blendingOpacityMovingArea;    /**< blendingOpacityMovingArea, should big then blendingOpacityStaticArea */
} CamEngine2dnrV5Config_t;

typedef struct CamEngineA2dnrV5ParamNode_s
{
    float                        gain;
    float                        integrationTime;
    CamEngine2dnrV5Config_t      config;
} CamEngineA2dnrV5ParamNode_t;

typedef enum CamEngineAhdrMode_e
{
    CAM_ENGINE_AHDR_MODE_INVALID    = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_AHDR_MODE_MANUAL     = 1,    /**< manual mode */
    CAM_ENGINE_AHDR_MODE_AUTO       = 2,    /**< run auto mode with fix exposure setpoint */
    CAM_ENGINE_AHDR_MODE_MAX
} CamEngineAhdrMode_t;

typedef enum CamEngineHdrBaseFrameType_e
{
    CAM_ENGINE_HDR_BASE_FRAME_INVALID = 0,
    CAM_ENGINE_HDR_BASE_FRAM_SHORT    = 1,
    CAM_ENGINE_HDR_BASE_FRAM_LONG     = 2,
    CAM_ENGINE_HDR_BASE_FRAM_MAX
} CamEngineHdrBaseFrameType_t;

typedef enum CamEngineHdrDolType_e
{
    CAM_ENGINE_HDR_TYPE_INVALID = 0,
    CAM_ENGINE_HDR_TYPE_2DOL    = 1,
    CAM_ENGINE_HDR_TYPE_3DOL    = 2,
    CAM_ENGINE_HDR_TYPE_MAX
} CamEngineHdrDolType_t;


typedef struct CamEngineHdrConfig_s {
    float c1;
    float c2;
    float ceil;
    float setPoint2;
    float tolerance;
    float objectFactor;
    float maxRatio;
    float minRatio;
} CamEngineHdrConfig_t;

//only used for CAM_ENGINE_AHDR_MODE_AUTO_EXP_ADPTIVE
typedef struct CamEngineHdrParamNode_s {
    float gain;
    float integrationTime;
    float setPointScale;
    float setPoint2Scale;
    float c1;
    float c2;
    float ceil;
} CamEngineAhdrParamNode_t;

typedef struct CamEngineHdrStatus_s {
    bool_t running;
    CamEngineAhdrMode_t mode;
} CamEngineHdrStatus_t;


typedef struct CamEngineWdr4Config_s {
    uint8_t     strength;
    uint8_t     highStrength;
    uint8_t     lowStrength;
    uint8_t     globalStrength;
    uint16_t    contrast;
    uint8_t     flatStrength;
    uint8_t     flatThreshold;
} CamEngineWdr4Config_t;

typedef struct CamEngineAwdr4ParamNode_s
{
    float gain;
    float integrationTime;
    CamEngineWdr4Config_t config;
} CamEngineAwdr4ParamNode_t;

#define CA_CURVE_DATA_TABLE_LEN  65
typedef enum CamEngineAcaMode_e
{
    CAM_ENGINE_ACA_MODE_INVALID = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_ACA_MODE_MANUAL  = 1,    /**< manual mode */
    CAM_ENGINE_ACA_MODE_AUTO    = 2,    /**< run auto mode */
    CAM_ENGINE_ACA_MODE_MAX
} CamEngineAcaMode_t;

typedef enum CamEngineColorAdjustMode_e
{
    CAM_ENGINE_COLOR_ADJUST_MODE_INVALID     = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_COLOR_ADJUST_MODE_BRIGHTNESS = 1,
    CAM_ENGINE_COLOR_ADJUST_MODE_SATURATION = 2,
    CAM_ENGINE_COLOR_ADJUST_MODE_BOTH        = 3,
    CAM_ENGINE_COLOR_ADJUST_MODE_MAX
} CamEngineColorAdjustMode_t;

typedef enum CamEngineColorAdjustCurve_e
{
    CAM_ENGINE_COLOR_ADJUST_CURVE_INVALID     = 0,    /**< invalid curve (only for initialization) */
    CAM_ENGINE_COLOR_ADJUST_CURVE_S            = 1,
    CAM_ENGINE_COLOR_ADJUST_CURVE_PARABOLIC = 2,
    CAM_ENGINE_COLOR_ADJUST_CURVE_MAX
} CamEngineColorAdjustCurve_t;

typedef struct CamEngineCaCurvePoint_s
{
    uint8_t xValue;
    uint16_t yValue;
} CamEngineCaCurvePoint_t;

typedef struct CamEngineCaConfig_s
{
    CamEngineColorAdjustMode_t mode;
    CamEngineColorAdjustCurve_t curveType;
    uint8_t sCurveInflection;
    uint8_t sCurveExponent;
    float parabolicFactor;
} CamEngineCaConfig_t;

typedef struct CamEngineAcaParamNode_s
{
    float gain;
    float integrationTime;
    uint8_t sCurveInflection;
    uint8_t sCurveExponent;
    float parabolicFactor;
} CamEngineAcaParamNode_t;

typedef struct CamEngineAcaStatus_s
{
    CamEngineAcaParamNode_t params;
    uint16_t chroma[CA_CURVE_DATA_TABLE_LEN];
} CamEngineAcaStatus_t;

typedef enum CamEngineAdciMode_e
{
    CAM_ENGINE_ADCI_MODE_INVALID = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_ADCI_MODE_MANUAL  = 1,    /**< manual mode */
    CAM_ENGINE_ADCI_MODE_AUTO    = 2,    /**< run auto mode */
    CAM_ENGINE_ADCI_MODE_HIST    = 3,
    CAM_ENGINE_ADCI_MODE_MAX
} CamEngineAdciMode_t;

typedef enum CamEngineDciCurveMode_e
{
    CAM_ENGINE_DCI_CURVE_MODE_INVALID   = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_DCI_CURVE_MODE_SECTION2  = 1,
    CAM_ENGINE_DCI_CURVE_MODE_SECTION3  = 2,
    CAM_ENGINE_DCI_CURVE_MODE_HISTOGRAM = 3,
    CAM_ENGINE_DCI_CURVE_MODE_MAX
} CamEngineDciCurveMode_t;

typedef struct CamEngineDciSectionContext_s
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
} CamEngineDciSectionContext_t;

typedef struct CamEngineHistogramContext_s
{
    float scale;
    float stepSize;
    float base;
    float strength;
    float damp;
} CamEngineDciHistogramContext_t;

typedef struct CamEngineDciConfig_s
{
    CamEngineDciCurveMode_t mode;
    CamEngineDciSectionContext_t sectionContext;
    CamEngineDciHistogramContext_t histogramContext;
} CamEngineDciConfig_t;

typedef struct CamEngineAdciParamNode_s
{
    float gain;
    float integrationTime;
    CamEngineDciSectionContext_t sectionContext;
    CamEngineDciHistogramContext_t histogramContext;
} CamEngineAdciParamNode_t;

typedef struct CamEngineAdciStatus_s
{
    CamEngineDciCurveMode_t mode;
    CamEngineAdciParamNode_t params;
    uint16_t luma[CA_CURVE_DATA_TABLE_LEN];
} CamEngineAdciStatus_t;



enum {
    CAM_ENGINE_MODULE_INIT = 0,
    CAM_ENGINE_MODULE_EE,
    CAM_ENGINE_MODULE_AHDR,
    CAM_ENGINE_MODULE_TDNR,
    CAM_ENGINE_MODULE_2DNRV5,
    CAM_ENGINE_MODULE_WDR4,
    CAM_ENGINE_MODULE_CA,
    CAM_ENGINE_MODULE_DCI,
    CAM_ENGINE_MODULE_CPROC,
    CAM_ENGINE_MODULE_GAMMA64,
    CAM_ENGINE_MODULE_DPF,
    CAM_ENGINE_MODULE_DGAIN,
    CAM_ENGINE_MODULE_DMSC2,
};

enum {
    CAM_ENGINE_MODE_OFF= 0,
    CAM_ENGINE_MODE_MANUAL,
    CAM_ENGINE_MODE_AUTO,
};
#ifdef __cplusplus
}
#endif


/* @} cam_engine_common */


#endif /* __CAM_ENGINE_COMMON_H__ */

