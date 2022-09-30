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
 * @cond    cam_engine_isp
 *
 * @file    cam_engine_isp_api.h
 *
 * @brief
 *
 *   Interface description of the CamEngine ISP.
 *
 *****************************************************************************/
/**
 *
 * @defgroup cam_engine_isp_api CamEngine ISP API
 * @{
 *
 */

#ifndef __CAM_ENGINE_ISP_API_H__
#define __CAM_ENGINE_ISP_API_H__

#include <ebase/types.h>
#include <common/return_codes.h>

#ifdef __cplusplus
extern "C"
{
#endif

//FIXME
#include <cameric_drv/cameric_isp_drv_api.h>
#include <cameric_drv/cameric_isp_bls_drv_api.h>
#include <cameric_drv/cameric_isp_wdr_drv_api.h>
#include <cameric_drv/cameric_isp_wdr2_drv_api.h>
#include <cameric_drv/cameric_isp_wdr3_drv_api.h>
#include <cameric_drv/cameric_isp_wdr4_drv_api.h>

#include <cameric_drv/cameric_isp_compand_drv_api.h>
#include <cameric_drv/cameric_isp_tpg_drv_api.h>
#include <cameric_drv/cameric_isp_stitching_drv_api.h>

#include <cameric_drv/cameric_isp_ee_drv_api.h>
#include <cameric_drv/cameric_isp_2dnr_drv_api.h>
#include <cameric_drv/cameric_isp_3dnr_drv_api.h>

#include <cameric_drv/cameric_isp_lsc_drv_api.h>
#include <cameric_drv/cameric_isp_dmsc2_drv_api.h>
#include <cameric_drv/cameric_isp_rgbgamma_drv_api.h>
#include <cameric_drv/cameric_isp_tdnr3_drv_api.h>
#include <cameric_drv/cameric_isp_color_adjust_drv_api.h>
#include <cameric_drv/cameric_isp_stitching_exp_drv_api.h>
#include <cameric_drv/cameric_isp_stitching_hist_drv_api.h>

/******************************************************************************/
/**
 * @brief   Structure to configure the lense shade correction
 *
 * @note    This structure needs to be converted to driver structure
 *
 *****************************************************************************/
typedef struct CamEngineLscConfig_s
{
    struct
    {
        uint16_t LscXGradTbl[CAEMRIC_GRAD_TBL_SIZE];    /**< multiplication factors of x direction  */
        uint16_t LscYGradTbl[CAEMRIC_GRAD_TBL_SIZE];    /**< multiplication factors of y direction  */
        uint16_t LscXSizeTbl[CAEMRIC_GRAD_TBL_SIZE];    /**< sector sizes of x direction            */
        uint16_t LscYSizeTbl[CAEMRIC_GRAD_TBL_SIZE];    /**< sector sizes of y direction            */
    } grid;

    struct
    {
        uint16_t LscRDataTbl[CAMERIC_DATA_TBL_SIZE];    /**< correction values of R color part */
        uint16_t LscGRDataTbl[CAMERIC_DATA_TBL_SIZE];   /**< correction values of G (red lines) color part */
        uint16_t LscGBDataTbl[CAMERIC_DATA_TBL_SIZE];   /**< correction values of G (blue lines) color part  */
        uint16_t LscBDataTbl[CAMERIC_DATA_TBL_SIZE];    /**< correction values of B color part  */
    } gain;

} CamEngineLscConfig_t;


/******************************************************************************/
/**
 * @brief   Enumeration type to configure the horizontal clip mode
 *
 * @note    Defines the maximum red/blue pixel shift in horizontal direction
 *          At pixel positions, that require a larger displacement, the maximum
 *          shift value is used instead (vector clipping)
 *
 *****************************************************************************/
typedef enum CamEngineCacHorizontalClipMode_e
{
    CAM_ENGINE_CAC_H_CLIPMODE_INVALID  = 0,    /**< lower border (only for an internal evaluation) */
    CAM_ENGINE_CAC_H_CLIPMODE_FIX4     = 1,    /**< horizontal vector clipping +/-4 pixel displacement (default) */
    CAM_ENGINE_CAC_H_CLIPMODE_DYN5     = 2,    /**< horizontal vector clipping to +/-4 or +/-5 pixel displacement
                                                 depending on pixel position inside the bayer raster (dynamic
                                                 switching between +/-4 and +/-5) */
    CAM_ENGINE_CAC_H_CLIPMODE_MAX              /**< upper border (only for an internal evaluation) */
} CamEngineCacHorizontalClipMode_t;


/******************************************************************************/
/**
 * @brief   Enumeration type to configure the vertical clip mode
 *
 * @note    Defines the maximum red/blue pixel shift in vertical direction
 *
 *****************************************************************************/
typedef enum CamEngineCacVerticalClipMode_e
{
    CAM_ENGINE_CAC_V_CLIPMODE_INVALID  = 0,    /**< lower border (only for an internal evaluation) */
    CAM_ENGINE_CAC_V_CLIPMODE_FIX2     = 1,    /**< vertical vector clipping to +/-2 pixel */
    CAM_ENGINE_CAC_V_CLIPMODE_FIX3     = 2,    /**< vertical vector clipping to +/-3 pixel */
    CAM_ENGINE_CAC_V_CLIBMODE_DYN4     = 3,    /**< vertical vector clipping +/-3 or +/-4 pixel displacement
                                                 depending on pixel position inside the bayer raster (dynamic
                                                 switching between +/-3 and +/-4) */
    CAM_ENGINE_CAC_V_CLIPMODE_MAX              /**< upper border (only for an internal evaluation) */
} CamEngineCacVerticalClipMode_t;



/******************************************************************************/
/**
 * @brief   Structure to configure the chromatic aberration correction
 *
 * @note    This structure needs to be converted to driver structure
 *
 *****************************************************************************/
typedef struct CamEngineCacConfig_s
{
    uint16_t                            width;          /**< width of the input image in pixel */
    uint16_t                            height;         /**< height of the input image in pixel */

    int16_t                             hCenterOffset;  /**< horizontal offset between image center and optical center of the input image in pixels */
    int16_t                             vCenterOffset;  /**< vertical offset between image center and optical center of the input image in pixels */

    CamEngineCacHorizontalClipMode_t    hClipMode;      /**< maximum red/blue pixel shift in horizontal direction */
    CamEngineCacVerticalClipMode_t      vClipMode;      /**< maximum red/blue pixel shift in vertical direction */

    float                            aBlue;          /**< parameters for radial shift calculation 9 bit twos complement with 4 fractional digits, valid range -16..15.9375 */
    float                            aRed;           /**< parameters for radial shift calculation 9 bit twos complement with 4 fractional digits, valid range -16..15.9375 */

    float                           bBlue;          /**< parameters for radial shift calculation 9 bit twos complement with 4 fractional digits, valid range -16..15.9375 */
    float                           bRed;           /**< parameters for radial shift calculation 9 bit twos complement with 4 fractional digits, valid range -16..15.9375 */

    float                           cBlue;          /**< parameters for radial shift calculation 9 bit twos complement with 4 fractional digits, valid range -16..15.9375 */
    float                          cRed;           /**< parameters for radial shift calculation 9 bit twos complement with 4 fractional digits, valid range -16..15.9375 */

    uint8_t                             Xns;            /**< horizontal normal shift parameter */
    uint8_t                             Xnf;            /**< horizontal scaling factor */

    uint8_t                             Yns;            /**< vertical normal shift parameter */
    uint8_t                             Ynf;            /**< vertical scaling factor */
} CamEngineCacConfig_t;

typedef enum CamEngineWdrMode_e
{
    CAM_ENGINE_WDR_MODE_INVALID  = 0,
    CAM_ENGINE_WDR_MODE_FIX      = 1,
    CAM_ENGINE_WDR_MODE_ADAPTIVE = 2,
    CAM_ENGINE_WDR_MODE_MAX
} CamEngineWdrMode_t;



typedef struct CamEngineWdrConfig
{
    CamEngineWdrMode_t  mode;
    uint16_t            RgbFactor;
    uint16_t            RgbOffset;
    uint16_t            LumOffset;
    uint16_t            DminStrength;
    uint16_t            DminThresh;
} CamEngineWdrConfig_t;



typedef struct CamEngineWdrCurve_s
{
    uint16_t            Ym[33];
    uint8_t             dY[33];
} CamEngineWdrCurve_t;


/******************************************************************************/
/**
 * @brief   Structure to configure the gamma curve.
 *
 * @note    This structure needs to be converted to driver structure
 *
 *****************************************************************************/
typedef enum CamEngineGammaOutXScale_e
{
    CAM_ENGINE_GAMMAOUT_XSCALE_INVALID  = 0,    /**< lower border (only for an internal evaluation) */
    CAM_ENGINE_GAMMAOUT_XSCALE_LOG      = 1,    /**< logarithmic segmentation from 0 to 4095
                                                     (64,64,64,64,128,128,128,128,256,256,256,512,512,512,512,512) */
    CAM_ENGINE_GAMMAOUT_XSCALE_EQU      = 2,    /**< equidistant segmentation from 0 to 4095
                                                     (256, 256, ... ) */
    CAM_ENGINE_GAMMAOUT_XSCALE_MAX              /**< upper border (only for an internal evaluation) */
} CamEngineGammaOutXScale_t;


typedef struct CamEngineGammaOutCurve_s
{
#ifndef ISP_RGBGC

    CamEngineGammaOutXScale_t   xScale;
    uint16_t                    GammaY[CAMERIC_ISP_GAMMA_CURVE_SIZE];
#else
    uint32_t gammaRPx[CAMERIC_ISP_RGBGAMMA_PX_NUM];                         /**< rgb gamma px table */
    uint32_t gammaRDataX[CAMERIC_ISP_RGBGAMMA_DATA_X_NUM];                         /**< rgb gamma data x table */
    uint32_t gammaRDataY[CAMERIC_ISP_RGBGAMMA_DATA_Y_NUM];                         /**< rgb gamma data y table */
    uint32_t gammaGPx[CAMERIC_ISP_RGBGAMMA_PX_NUM];                         /**< rgb gamma px table */
    uint32_t gammaGDataX[CAMERIC_ISP_RGBGAMMA_DATA_X_NUM];                         /**< rgb gamma data x table */
    uint32_t gammaGDataY[CAMERIC_ISP_RGBGAMMA_DATA_Y_NUM];                         /**< rgb gamma data y table */
    uint32_t gammaBPx[CAMERIC_ISP_RGBGAMMA_PX_NUM];                         /**< rgb gamma px table */
    uint32_t gammaBDataX[CAMERIC_ISP_RGBGAMMA_DATA_X_NUM];                         /**< rgb gamma data x table */
    uint32_t gammaBDataY[CAMERIC_ISP_RGBGAMMA_DATA_Y_NUM];
#endif
} CamEngineGammaOutCurve_t;



typedef struct CamEngineGammaOutRGBCurve_s
{
    uint16_t GammaRX[CAMERIC_ISP_GAMMA_RGB_CURVE_SIZE];
    uint16_t GammaRY[CAMERIC_ISP_GAMMA_RGB_CURVE_SIZE];
    uint16_t GammaGX[CAMERIC_ISP_GAMMA_RGB_CURVE_SIZE];
    uint16_t GammaGY[CAMERIC_ISP_GAMMA_RGB_CURVE_SIZE];
	uint16_t GammaBX[CAMERIC_ISP_GAMMA_RGB_CURVE_SIZE];
    uint16_t GammaBY[CAMERIC_ISP_GAMMA_RGB_CURVE_SIZE];
} CamEngineGammaOutRGBCurve_t;



/******************************************************************************/
/**
 * @brief   Structure to configure the edge enhancement
 *
 * @note    This structure needs to be converted to driver structure
 *
 *****************************************************************************/
typedef struct CamEngineEeConfig_s
{
    bool                                    enabled;
    uint8_t                                 strength;

    uint16_t                                yUpGain;
    uint16_t                                yDownGain;

    uint16_t                                uvGain;
    uint16_t                                edgeGain;

    uint8_t                                 srcStrength;
    CamerIcIspEeInputDataFormatSelect_t     inputDataFormatSelect;

}CamEngineEeConfig_t;

typedef enum CamEngineRgbirOutBpt_e {
    CAM_ENGINE_RGBIR_OUT_BPT_RGGB = 0,
    CAM_ENGINE_RGBIR_OUT_BPT_GRBG,
    CAM_ENGINE_RGBIR_OUT_BPT_GBRG,
    CAM_ENGINE_RGBIR_OUT_BPT_BGGR,
} CamEngineRgbirOutBpt_t;

typedef enum CamEngineRgbirBpt_e{
    CAM_ENGINE_RGBIR_BPT_BGGIR= 0,
    CAM_ENGINE_RGBIR_BPT_GRIRG,
    CAM_ENGINE_RGBIR_BPT_RGGIR,
    CAM_ENGINE_RGBIR_BPT_GBIRG,
    CAM_ENGINE_RGBIR_BPT_GIRRG,
    CAM_ENGINE_RGBIR_BPT_IRGGB,
    CAM_ENGINE_RGBIR_BPT_GIRBG,
    CAM_ENGINE_RGBIR_BPT_IRGGR,
    CAM_ENGINE_RGBIR_BPT_RGIRB,
    CAM_ENGINE_RGBIR_BPT_GRBIR,
    CAM_ENGINE_RGBIR_BPT_IRBRG,
    CAM_ENGINE_RGBIR_BPT_BIRGR,
    CAM_ENGINE_RGBIR_BPT_BGIRR,
    CAM_ENGINE_RGBIR_BPT_GBRIR,
    CAM_ENGINE_RGBIR_BPT_IRRBG,
    CAM_ENGINE_RGBIR_BPT_RIRGB,
} CamEngineRgbirBpt_t;

typedef enum CamEngineRgbirFiltMode_e{
    CAM_ENGINE_RGBIR_GREEN_FILT_STATIC= 0,
    CAM_ENGINE_RGBIR_GREEN_FILT_DYNAMIC,
} CamEngineRgbirFiltMode_t;
/******************************************************************************/
/**
 * @brief   Structure to configure the  rgbir
 *
 * @note    This structure needs to be converted to driver structure
 *
 *****************************************************************************/
typedef struct CamEngineRgbirConfig_s
{
    bool_t enable;
    bool_t enable_ir_raw_out;
    bool_t part1Enable;
    bool_t part2Enable;
    uint8_t dmscThreshold;
    uint8_t stageSelect;
    CamEngineRgbirOutBpt_t outRgbBpt;
    CamEngineRgbirBpt_t rgbirBpt;
    CamEngineRgbirFiltMode_t filtMode;
    bool_t filtEnable;
    double irSigmas;
    uint16_t ir_threshold, l_threshold;
    uint16_t bls_r, bls_g, bls_b, bls_ir;
    double gain_r, gain_g, gain_b, gain_ir;
    double cc_mtx[12];
    uint16_t width, height;
}CamEngineRgbirConfig_t;

/******************************************************************************/
/**
 * @brief   Structure to configure the  tdnr3 module
 *
 * @note    This structure needs to be converted to driver structure
 *
 *****************************************************************************/
typedef struct CamEngineTdnr3Config_s
{
    bool_t enableInvGamma;
    bool_t enablePreGamma;
    bool_t enableMotionErosion;
    bool_t enableMotionCoverage;
    bool_t enableMotionDilation;
    bool_t enableTdnr;

    unsigned char strength;         //[0, 128]
    unsigned short noiseLvl;        //[0, 100] -> [0, 1024]
    unsigned short motionSlope;     //[0, 100] -> [0, 1024]
    unsigned short sadWeight;       //[0, 16]
    unsigned short updateFactor;    //[0, 1024]
    unsigned short motionUpdateFactor; //[0, 1024]
    double  modelA, modelB;

}CamEngineTdnr3Config_t;

/*****************************************************************************/
/**
 * @brief   This function sets the black-level.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   Red                 red cells
 * @param   GreenR              green (red neighbors) cells
 * @param   GreenB              green (blue neighbors) cells
 * @param   Blue                blue cells
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineBlsSet
(
    CamEngineHandle_t   hCamEngine,
    const uint16_t      Red,
    const uint16_t      GreenR,
    const uint16_t      GreenB,
    const uint16_t      Blue
);



/*****************************************************************************/
/**
 * @brief   This function returns the black-level.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   Red                 red cells
 * @param   GreenR              green (red neighbors) cells
 * @param   GreenB              green (blue neighbors) cells
 * @param   Blue                blue cells
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineBlsGet
(
    CamEngineHandle_t   hCamEngine,
    uint16_t            *Red,
    uint16_t            *GreenR,
    uint16_t            *GreenB,
    uint16_t            *Blue
);



/*****************************************************************************/
/**
 * @brief   This function sets the white balance gains.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   Gains               white balance gains
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineWbSetGains
(
    CamEngineHandle_t           hCamEngine,
    const CamEngineWbGains_t    *Gains
);



/*****************************************************************************/
/**
 * @brief   This function returns the white balance gains.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   Gains               white balance gains
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineWbGetGains
(
    CamEngineHandle_t   hCamEngine,
    CamEngineWbGains_t  *Gains
);



/*****************************************************************************/
/**
 * @brief   This function sets the cross talk matrix.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   CcMatrix            cross talk matrix
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineWbSetCcMatrix
(
    CamEngineHandle_t           hCamEngine,
    const CamEngineCcMatrix_t   *CcMatrix
);



/*****************************************************************************/
/**
 * @brief   This function returns the cross talk matrix.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   CcMatrix            cross talk matrix
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineWbGetCcMatrix
(
    CamEngineHandle_t   hCamEngine,
    CamEngineCcMatrix_t *CcMatrix
);



/*****************************************************************************/
/**
 * @brief   This function sets the cross talk offset.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   CcOffset            cross talk offset
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineWbSetCcOffset
(
    CamEngineHandle_t           hCamEngine,
    const CamEngineCcOffset_t   *CcOffset
);



/*****************************************************************************/
/**
 * @brief   This function returns the cross talk offset.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   CcOffset            cross talk offset
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineWbGetCcOffset
(
    CamEngineHandle_t   hCamEngine,
    CamEngineCcOffset_t *CcOffset
);

/*****************************************************************************/
/**
 * @brief   This function sets the measuring window for AWB.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   win                 pointer to a measuring window
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineAwbSetMeasuringWindow
(
    CamEngineHandle_t           hCamEngine,
    CamEngineWindow_t           *win
);

#ifndef ISP_DEMOSAIC2
/*****************************************************************************/
/**
 * @brief   This function sets the demosaicing.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   Bypass              bypass mode
 * @param   Threshold           threshold
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineDemosaicSet
(
    CamEngineHandle_t   hCamEngine,
    const bool_t        Bypass,
    const uint8_t       Threshold
);

/*****************************************************************************/
/**
 * @brief   This function returns the demosaicing.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   pBypass             bypass mode
 * @param   pThreshold          threshold
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineDemosaicGet
(
    CamEngineHandle_t   hCamEngine,
    bool_t              *pBypass,
    uint8_t             *pThreshold
);
#else
/*****************************************************************************/
/**
 * @brief   This function sets the demosaic2.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   Bypass              bypass mode
 * @param   Threshold           threshold
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineDemosaic2Set
(
    CamEngineHandle_t   hCamEngine,
    const bool_t        Bypass,
    const uint8_t       Threshold
);
/*****************************************************************************/
/**
 * @brief   This function returns the demosaic2.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   pBypass             bypass mode
 * @param   pThreshold          threshold
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineDemosaic2Get
(
    CamEngineHandle_t   hCamEngine,
    bool_t              *pBypass,
    uint8_t             *pThreshold
);

#endif


/*****************************************************************************/
/**
 * @brief   This function returns the status of the LSC module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineLscStatus
(
    CamEngineHandle_t       hCamEngine,
    bool_t                  *pRunning,
    CamEngineLscConfig_t    *pConfig
);



/*****************************************************************************/
/**
 * @brief   This function enables the LSC module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineLscEnable
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function disables the LSC module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineLscDisable
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function initializes the wide dynamic range module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineInitWdr
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function enables the wide dynamic range module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineEnableWdr
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function disables the wide dynamic range module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineDisableWdr
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function loads a WDR curve.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   WdrCurve            WDR curve to load
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineWdrSetCurve
(
    CamEngineHandle_t hCamEngine,
    CamEngineWdrCurve_t WdrCurve
);



/*****************************************************************************/
/**
 * @brief   This function returns the status of the gamma correction module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineGammaStatus
(
    CamEngineHandle_t   hCamEngine,
    bool_t              *pRunning
);



/*****************************************************************************/
/**
 * @brief   This function enables the gamma correction module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineGammaEnable
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function disables the gamma correction module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineGammaDisable
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function loads a correction curve into gamma correction
 *          module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   WdrCurve            WDR curve to load
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineGammaSetCurve
(
    CamEngineHandle_t           hCamEngine,
    CamEngineGammaOutCurve_t    GammaCurve
);



/*****************************************************************************/
/**
 * @brief   This function returns the status of the Cac module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineCacStatus
(
    CamEngineHandle_t       hCamEngine,
    bool_t                  *pRunning,
    CamEngineCacConfig_t    *pConfig
);



/*****************************************************************************/
/**
 * @brief   This function enables the CAC module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineCacEnable
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function enables the CAC module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineCacDisable
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function returns the status of the filter module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineFilterStatus
(
    CamEngineHandle_t   hCamEngine,
    bool_t              *pRunning,
    uint8_t             *pDenoiseLevel,
    uint8_t             *pSharpenLevel
);



/*****************************************************************************/
/**
 * @brief   This function enables the filter module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineFilterEnable
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function disables the filter module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineFilterDisable
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function sets the levels of the filter module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineFilterSetLevel
(
    CamEngineHandle_t           hCamEngine,
    const uint8_t               DenoiseLevel,
    const uint8_t               SharpenLevel
);



/*****************************************************************************/
/**
 * @brief   This function enables the color noise reduction module.
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
RESULT CamEngineCnrEnable
(
    CamEngineHandle_t   hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function disables the color noise reduction module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineCnrDisable
(
    CamEngineHandle_t   hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function returns the color noise reduction status.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   pRunning            BOOL_TRUE: running, BOOL_FALSE: stopped
 * @param   pThreshold1         Threshold Color Channel 1
 * @param   pThreshold2         Threshold Color Channel 2
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineCnrStatus
(
    CamEngineHandle_t       hCamEngine,
    bool_t                  *pRunning,
    uint32_t                *pThreshold1,
    uint32_t                *pThreshold2
);



/*****************************************************************************/
/**
 * @brief   This function sets the thresholds of the color noise reduction
 *          module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   Threshold1          Threshold Color Channel 1
 * @param   Threshold2          Threshold Color Channel 2
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineCnrSetThresholds
(
    CamEngineHandle_t   hCamEngine,
    const uint32_t      Threshold1,
    const uint32_t      Threshold2
);

/*****************************************************************************/
/**
 * @brief   This function initializes the compand module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineInitCmpd
(
    CamEngineHandle_t hCamEngine
);

/*****************************************************************************/
/**
 * @brief   This function set the compand module expand curve.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   xData          pointer to the xdata
 * @param   yData          pointer to the ydata
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineSetCmpdExpandCurve
(
    CamEngineHandle_t hCamEngine,
    uint32_t           *xData,
    uint32_t            *yData
);

/*****************************************************************************/
/**
 * @brief   This function enables the compand module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineEnableCmpd
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineEnableCmpdBls
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineEnableCmpdExpand
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineEnableCmpdCompress
(
    CamEngineHandle_t hCamEngine
);


/*****************************************************************************/
/**
 * @brief   This function disables the compand module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineDisableCmpd
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableCmpdBls
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableCmpdExpand
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableCmpdCompress
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function disables the compand module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineCmpdConfig
(
    CamEngineHandle_t   hCamEngine,
    bool_t              blsEnable,
    bool_t              compressEnable,
    bool_t              expandEnable,
    int                *pBlsPara
);



/*****************************************************************************/
/**
 * @brief   This function returns the status of the Ee module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineEeStatus
(
    CamEngineHandle_t       hCamEngine,
    bool_t                  *pRunning,
    CamEngineEeConfig_t     *pConfig
);



/*****************************************************************************/
/**
 * @brief   This function enables the edge enhance module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineEeEnable
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function disables the edge enhance module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineEeDisable
(
    CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function set strength and Gain of the edge enhance module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineEeSetConfig
(
    CamEngineHandle_t       hCamEngine,
    CamEngineEeConfig_t     *pConfig
);



//===========================================================================
// Temporary API, not used for tuning tool
//===========================================================================

RESULT CamEngineEnableTpg
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableTpg
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineTpgConfig
(
    CamEngineHandle_t       hCamEngine,
    CamerIcIspTpgConfig_t  *pTpgConfig

);

RESULT CamEngineInitWdr2
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineEnableWdr2
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableWdr2
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineWdr2SetStrength
(
    CamEngineHandle_t hCamEngine,
    float             WdrStrength
);

RESULT CamEngineEnableWdr3
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableWdr3
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineWdr3SetStrength
(
    CamEngineHandle_t   hCamEngine,
    uint8_t             Wdr3Strength,
    uint8_t             Wdr3MaxGain,
    uint8_t             Wdr3GlobalStrength
);

RESULT CamEngineEnableWdr4
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableWdr4
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineWdr4Config
(
    CamEngineHandle_t   hCamEngine,
    CamerIcIspWdr4Config_t *wdr4Cfg
);

RESULT CamEngineIspWdr4StoreHdrRatio
(
    CamEngineHandle_t hCamEngine,
	uint8_t  ratioLSVS,
    uint8_t   ratioLS
);

RESULT CamEngineInitCmpd
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineEnableCmpd
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableCmpd
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineCmpdSetTbl
(
    CamEngineHandle_t   hCamEngine,
    const int          *pExpandTbl,
    const int          *pCompressTbl
);

RESULT CamEngineCmpdConfig
(
    CamEngineHandle_t   hCamEngine,
    bool_t              blsEnable,
    bool_t              compressEnable,
    bool_t              expandEnable,
    int                *pBlsPara
);

RESULT CamEngineEnableTpg
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableTpg
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineTpgConfig
(
    CamEngineHandle_t       hCamEngine,
    CamerIcIspTpgConfig_t  *pTpgConfig

);

RESULT CamEngineInitStitching
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineEnableStitching
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableStitching
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineStitchingConfig
(
    CamEngineHandle_t       hCamEngine,
    int                     StitchingPara

);

RESULT CamEngineSetStitchingRdWrStr
(
    CamEngineHandle_t hCamEngine,
    int               rdStr
);

RESULT CamEngineBypassMcm
(
    CamEngineHandle_t hCamEngine,
    bool               enable
);

/******************************************************************************
 * CamEngineSetStitchingColorWeight()
 *****************************************************************************/
RESULT CamEngineSetStitchingColorWeight
(
    CamEngineHandle_t hCamEngine,
    const uint8_t                weight0,
    const uint8_t                weight1,
    const uint8_t                weight2
);

RESULT CamEngineSetStitchingProperties
(
    CamEngineHandle_t hCamEngine,
    const CamerIcIspStitchingProperties_t     *pProperties
);

RESULT CamEngineStitchingExpConfig
(
    CamEngineHandle_t       hCamEngine,
    int                     StitchingPara,
    float                   SensorGain[3],
    float                   ExposureTime[3],
    float* hdr_ratio
);

RESULT CamEngineStitchingShortExpSet
(
    CamEngineHandle_t hCamEngine,
    bool_t           ShortExpSet
);

RESULT CamEngineStitchingExtBitGet
(
    CamEngineHandle_t hCamEngine,
    uint8_t           *ext_bit
);
RESULT CamEngineInitEe
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineEnableEe
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableEe
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineEeConfig
(
    CamEngineHandle_t hCamEngine,
    CamEngineEeConfig_t *EePara
);

RESULT CamEngineInit2Dnr
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineEnable2Dnr
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisable2Dnr
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngine2DnrConfig
(
    CamEngineHandle_t hCamEngine,
    CamerIcIsp2DnrConfig_t * cfgPara
);

RESULT CamEngineEnable3Dnr
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisable3Dnr
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngine3DnrUpdate
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngine3DnrCompute
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngine3DnrSetStrength
(
       CamEngineHandle_t hCamEngine,
       uint32_t denoiseStrength
);

RESULT CamEngine3DnrSetCompress
(
    CamEngineHandle_t hCamEngine,
    CamericIsp3DNRCompress_t *compress
);

RESULT CamEngineEnableAfm
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableAfm
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineAfmConfig
(
    CamEngineHandle_t hCamEngine,
    uint32_t AfmWinId,
    uint32_t AfmThresHold
);

RESULT CamEngineDemosaicConfig
(
    CamEngineHandle_t hCamEngine,
    uint32_t DemosaicMode,
    uint32_t DemosaicThreshold
);


RESULT CamEngineDmsc2Configure
(
    CamEngineHandle_t hCamEngine,
    CamericIspDemosaicContext *pConfig
);

RESULT CamEngineDmsc2GetConfig
(
    CamEngineHandle_t hCamEngine,
    CamericIspDemosaicContext *pConfig
);

RESULT CamEngineDmsc2Enable
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDmsc2Disable
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineRgbGammaConfigure
(
    CamEngineHandle_t hCamEngine,
    CamerIcIspRgbGammaContext_t *pConfig
);

RESULT CamEngineRgbGammaGetConfig
(
    CamEngineHandle_t hCamEngine,
    CamerIcIspRgbGammaContext_t *pConfig
);

RESULT CamEngineRgbGammaEnable
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineRgbGammaDisable
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineColorAdjustConfigure
(
    CamEngineHandle_t hCamEngine,
    CamerIcIspCa_t *pConfig
);

RESULT CamEngineColorAdjustGetConfig
(
    CamEngineHandle_t hCamEngine,
    CamerIcIspCa_t *pConfig
);

RESULT CamEngineColorAdjustEnable
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineColorAdjustDisable
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineEnableRgbir
(
    CamEngineHandle_t hCamEngine,
    bool bEnable
) ;

RESULT CamEngineEnableRgbirIrRawOut(
    CamEngineHandle_t hCamEngine,
    bool bEnable
) ;

RESULT CamEngineConfigRgbir
(
    CamEngineHandle_t hCamEngine,
    CamEngineRgbirConfig_t* pRgbirCfg
);

/*****************************************************************************/
/**
 * @brief   This function enable the tdnr3
 * stats.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   enableDnr2          enable the 2dnr of tdnr3
 *  @param  enableDnr3          enable the 3dnr of tdnr3
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineEnableTdnr3
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineDisableTdnr3
(
    CamEngineHandle_t hCamEngine
);

RESULT CamEngineTdnr3GetConfig
(
    CamEngineHandle_t hCamEngine,
    CamerIcIspTdnr3Config_t *pConfig
);

RESULT CamEngineTdnr3SetConfig
(
    CamEngineHandle_t hCamEngine,
    const CamerIcIspTdnr3Config_t *pConfig
);

/*****************************************************************************/
/**
 * @brief   This function config the tdnr3 invgamma pregamma curve
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   modelA              noise model parameters, calibrated according to gain
 * @param   modelB              noise model parameters, calibrated according to gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineUpdateTdnr3Curve
(
    CamEngineHandle_t hCamEngine,
     double modelA,
     double modelB
);

/*****************************************************************************/
/**
 * @brief   This function config the tdnr3 strength
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   strength            strength parameter
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineSetTdnr3Strength
(
    CamEngineHandle_t hCamEngine,
    unsigned int strength
);

/*****************************************************************************/
/**
 * @brief   This function config the  2dnr of tdnr3 coeff curve
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   pCoeff              pinter to the coneff curve
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineCfgTdnr3Nlm
(
    CamEngineHandle_t hCamEngine,
    unsigned int *pCoeff
);

RESULT CamEngineEnableDigitalGain(CamEngineHandle_t hCamEngine);

RESULT CamEngineDisableDigitalGain(CamEngineHandle_t hCamEngine);

RESULT CamEngineSetupDigitalGain(CamEngineHandle_t hCamEngine,
                                    const uint16_t rGain,
                                    const uint16_t grGain,
                                    const uint16_t gbGain,
                                    const uint16_t bGain);

RESULT CamEngineEnableGreenEquilibration(CamEngineHandle_t hCamEngine);

RESULT CamEngineDisableGreenEquilibration(CamEngineHandle_t hCamEngine);

RESULT CamEngineSetupGreenEquilibration(CamEngineHandle_t hCamEngine, uint16_t threshold, uint16_t dummyLine);



/*****************************************************************************/
/**
 * @brief	This function enables the 3DNRv3 module.
 *
 * @param	hCamEngine			handle to the CamEngine instance
 * @param	pCoeff				pinter to the coneff curve
 *
 * @return	Return the result of the function call.
 * @retval	RET_SUCCESS 		function succeed
 * @retval	RET_WRONG_HANDLE	invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngine3DNRv3Enable
(
	CamEngineHandle_t hCamEngine,
	const bool_t	  noiseCurveEnable

);



/*****************************************************************************/
/**
 * @brief	This function disables the 3DNRv3 module.
 *
 * @param	hCamEngine			handle to the CamEngine instance
 *
 * @return	Return the result of the function call.
 * @retval	RET_SUCCESS 		function succeed
 * @retval	RET_WRONG_HANDLE	invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngine3DNRv3Disable
(
	CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief	This function enables the green equilibrate module.
 *
 * @param	hCamEngine			handle to the CamEngine instance
 *
 * @return	Return the result of the function call.
 * @retval	RET_SUCCESS 		function succeed
 * @retval	RET_WRONG_HANDLE	invalid instance handle
 * @retval	RET_WRONG_CONFIG	image effects isn't configured
 * @retval	RET_NOTAVAILABLE	module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineGeEnable
(
	CamEngineHandle_t	hCamEngine
);



/*****************************************************************************/
/**
 * @brief	This function disables the green equilibrate module.
 *
 * @param	hCamEngine			handle to the CamEngine instance
 *
 * @return	Return the result of the function call.
 * @retval	RET_SUCCESS 		function succeed
 * @retval	RET_WRONG_HANDLE	invalid instance handle
 * @retval	RET_NOTAVAILABLE	module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineGeDisable
(
	CamEngineHandle_t	hCamEngine
);



/*****************************************************************************/
/**
 * @brief	This function sets the threshold of the green equilibrate
 *			module.
 *
 * @param	hCamEngine			handle to the CamEngine instance
 * @param	threshold			threshold
 * @return	Return the result of the function call.
 * @retval	RET_SUCCESS 		function succeed
 * @retval	RET_WRONG_HANDLE	invalid instance handle
 * @retval	RET_NOTAVAILABLE	module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineGeSetThreshold
(
	CamEngineHandle_t	hCamEngine,
	const uint16_t		threshold
);



/*****************************************************************************/
/**
 * @brief	This function returns the green equilibrate status.
 *
 * @param	hCamEngine			handle to the CamEngine instance
 * @param	pRunning			BOOL_TRUE: running, BOOL_FALSE: stopped
 * @param	pThreshold			Threshold
 *
 * @return	Return the result of the function call.
 * @retval	RET_SUCCESS 		function succeed
 * @retval	RET_WRONG_HANDLE	invalid instance handle
 * @retval	RET_NOTAVAILABLE	module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineGeStatus
(
	CamEngineHandle_t		hCamEngine,
	bool_t					*pRunning,
	uint16_t				*pThreshold
);



/*****************************************************************************/
/**
 * @brief	This function enables the RGB gamma correction module.
 *
 * @param	hCamEngine			handle to the CamEngine instance
 *
 * @return	Return the result of the function call.
 * @retval	RET_SUCCESS 		function succeed
 * @retval	RET_WRONG_HANDLE	invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineGammaRGBEnable
(
	CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief	This function disables the RGB gamma correction module.
 *
 * @param	hCamEngine			handle to the CamEngine instance
 *
 * @return	Return the result of the function call.
 * @retval	RET_SUCCESS 		function succeed
 * @retval	RET_WRONG_HANDLE	invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineGammaRGBDisable
(
	CamEngineHandle_t hCamEngine
);



/*****************************************************************************/
/**
 * @brief	This function loads a correction curve into RGB gamma correction
 *			module.
 *
 * @param	hCamEngine			handle to the CamEngine instance
 * @param	GammaCurve			Gamma curve to load
 *
 * @return	Return the result of the function call.
 * @retval	RET_SUCCESS 		function succeed
 * @retval	RET_WRONG_HANDLE	invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineGammaRGBSetCurve
(
	CamEngineHandle_t				hCamEngine,
	CamEngineGammaOutRGBCurve_t 	gammaCurve
);



/*****************************************************************************/
/**
 * @brief	This function returns the status of the RGB gamma correction module.
 *
 * @param	hCamEngine			handle to the CamEngine instance
 *
 * @return	Return the result of the function call.
 * @retval	RET_SUCCESS 		function succeed
 * @retval	RET_WRONG_HANDLE	invalid instance handle
 *
 *****************************************************************************/
RESULT CamEngineGammaRGBStatus
(
	CamEngineHandle_t	hCamEngine,
	bool_t				*pRunning
);



/*****************************************************************************/
/**
 * @brief   This function enables the digital gain module.
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
RESULT CamEngineDgEnable
(
    CamEngineHandle_t   hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function disables the digital gain module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineDgDisable
(
    CamEngineHandle_t   hCamEngine
);



/*****************************************************************************/
/**
 * @brief   This function returns the digital gain status.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   pRunning            BOOL_TRUE: running, BOOL_FALSE: stopped
 * @param   pGain         		digital gain value
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineDgStatus
(
    CamEngineHandle_t       hCamEngine,
    bool_t                  *pRunning,
    float                	*pGain
);



/*****************************************************************************/
/**
 * @brief   This function sets the gain value of the digital gain module.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   gain          		digital gain value

 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineDgSetGain
(
    CamEngineHandle_t   hCamEngine,
    const float      	gain
);



#ifdef __cplusplus
}
#endif


/* @} cam_engine_isp_api */


#endif /* __CAM_ENGINE_ISP_API_H__ */

