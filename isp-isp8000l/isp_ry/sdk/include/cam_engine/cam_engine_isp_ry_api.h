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

#ifndef __CAM_ENGINE_ISP_RY_API_H__
#define __CAM_ENGINE_ISP_RY_API_H__

#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif

//FIXME
#include <cameric_drv/cameric_isp_drv_ry_api.h>
#include <cameric_drv/cameric_isp_bls_drv_ry_api.h>
#include <cameric_drv/cameric_isp_wdr_drv_ry_api.h>
#include <cameric_drv/cameric_isp_wdr2_drv_ry_api.h>
#include <cameric_drv/cameric_isp_wdr3_drv_ry_api.h>
#include <cameric_drv/cameric_isp_wdr4_drv_ry_api.h>

#include <cameric_drv/cameric_isp_compand_drv_ry_api.h>
#include <cameric_drv/cameric_isp_tpg_drv_ry_api.h>
#include <cameric_drv/cameric_isp_stitching_drv_ry_api.h>

#include <cameric_drv/cameric_isp_ee_drv_ry_api.h>
#include <cameric_drv/cameric_isp_2dnr_drv_ry_api.h>
#include <cameric_drv/cameric_isp_3dnr_drv_ry_api.h>

#include <cameric_drv/cameric_isp_lsc_drv_ry_api.h>
#include <cameric_drv/cameric_isp_dmsc2_drv_ry_api.h>
#include <cameric_drv/cameric_isp_rgbgamma_drv_ry_api.h>
#include <cameric_drv/cameric_isp_tdnr3_drv_ry_api.h>
#include <cameric_drv/cameric_isp_color_adjust_drv_ry_api.h>
#include <cameric_drv/cameric_isp_stitching_exp_drv_ry_api.h>
#include <cameric_drv/cameric_isp_stitching_hist_drv_ry_api.h>

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
#ifndef ISP_RGBGC_RY

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
} CamEngineGammaOutRGBCurve_ry_t;



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
    CamerIcIspEeInputDataFormatSelect_ry_t     inputDataFormatSelect;

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
RESULT CamEngineBlsSet_ry
(
    CamEngineHandle_ry_t   hCamEngine,
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
RESULT CamEngineBlsGet_ry
(
    CamEngineHandle_ry_t   hCamEngine,
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
RESULT CamEngineWbSetGains_ry
(
    CamEngineHandle_ry_t           hCamEngine,
    const CamEngineWbGains_ry_t    *Gains
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
RESULT CamEngineWbGetGains_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    CamEngineWbGains_ry_t  *Gains
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
RESULT CamEngineWbSetCcMatrix_ry
(
    CamEngineHandle_ry_t           hCamEngine,
    const CamEngineCcMatrix_ry_t   *CcMatrix
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
RESULT CamEngineWbGetCcMatrix_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    CamEngineCcMatrix_ry_t *CcMatrix
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
RESULT CamEngineWbSetCcOffset_ry
(
    CamEngineHandle_ry_t           hCamEngine,
    const CamEngineCcOffset_ry_t   *CcOffset
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
RESULT CamEngineWbGetCcOffset_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    CamEngineCcOffset_ry_t *CcOffset
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
RESULT CamEngineAwbSetMeasuringWindow_ry
(
    CamEngineHandle_ry_t           hCamEngine,
    CamEngineWindow_ry_t           *win
);

#ifndef ISP_DEMOSAIC2_RY
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
RESULT CamEngineDemosaicSet_ry
(
    CamEngineHandle_ry_t   hCamEngine,
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
RESULT CamEngineDemosaicGet_ry
(
    CamEngineHandle_ry_t   hCamEngine,
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
RESULT CamEngineDemosaic2Set_ry
(
    CamEngineHandle_ry_t   hCamEngine,
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
RESULT CamEngineDemosaic2Get_ry
(
    CamEngineHandle_ry_t   hCamEngine,
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
RESULT CamEngineLscStatus_ry
(
    CamEngineHandle_ry_t       hCamEngine,
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
RESULT CamEngineLscEnable_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineLscDisable_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineInitWdr_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineEnableWdr_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineDisableWdr_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineWdrSetCurve_ry
(
    CamEngineHandle_ry_t hCamEngine,
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
RESULT CamEngineGammaStatus_ry
(
    CamEngineHandle_ry_t   hCamEngine,
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
RESULT CamEngineGammaEnable_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineGammaDisable_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineGammaSetCurve_ry
(
    CamEngineHandle_ry_t           hCamEngine,
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
RESULT CamEngineCacStatus_ry
(
    CamEngineHandle_ry_t       hCamEngine,
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
RESULT CamEngineCacEnable_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineCacDisable_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineFilterStatus_ry
(
    CamEngineHandle_ry_t   hCamEngine,
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
RESULT CamEngineFilterEnable_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineFilterDisable_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineFilterSetLevel_ry
(
    CamEngineHandle_ry_t           hCamEngine,
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
RESULT CamEngineCnrEnable_ry
(
    CamEngineHandle_ry_t   hCamEngine
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
RESULT CamEngineCnrDisable_ry
(
    CamEngineHandle_ry_t   hCamEngine
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
RESULT CamEngineCnrStatus_ry
(
    CamEngineHandle_ry_t       hCamEngine,
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
RESULT CamEngineCnrSetThresholds_ry
(
    CamEngineHandle_ry_t   hCamEngine,
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
RESULT CamEngineInitCmpd_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineSetCmpdExpandCurve_ry
(
    CamEngineHandle_ry_t hCamEngine,
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
RESULT CamEngineEnableCmpd_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineEnableCmpdBls_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineEnableCmpdExpand_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineEnableCmpdCompress_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineDisableCmpd_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableCmpdBls_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableCmpdExpand_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableCmpdCompress_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineCmpdConfig_ry
(
    CamEngineHandle_ry_t   hCamEngine,
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
RESULT CamEngineEeStatus_ry
(
    CamEngineHandle_ry_t       hCamEngine,
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
RESULT CamEngineEeEnable_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineEeDisable_ry
(
    CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineEeSetConfig_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    CamEngineEeConfig_t     *pConfig
);



//===========================================================================
// Temporary API, not used for tuning tool
//===========================================================================

RESULT CamEngineEnableTpg_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableTpg_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineTpgConfig_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    CamerIcIspTpgConfig_ry_t  *pTpgConfig

);

RESULT CamEngineInitWdr2_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineEnableWdr2_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableWdr2_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineWdr2SetStrength_ry
(
    CamEngineHandle_ry_t hCamEngine,
    float             WdrStrength
);

RESULT CamEngineEnableWdr3_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableWdr3_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineWdr3SetStrength_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    uint8_t             Wdr3Strength,
    uint8_t             Wdr3MaxGain,
    uint8_t             Wdr3GlobalStrength
);

RESULT CamEngineEnableWdr4_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableWdr4_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineWdr4Config_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    CamerIcIspWdr4Config_ry_t *wdr4Cfg
);

RESULT CamEngineIspWdr4StoreHdrRatio_ry
(
    CamEngineHandle_ry_t hCamEngine,
	uint8_t  ratioLSVS,
    uint8_t   ratioLS
);

RESULT CamEngineInitCmpd_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineEnableCmpd_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableCmpd_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineCmpdSetTbl_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    const int          *pExpandTbl,
    const int          *pCompressTbl
);

RESULT CamEngineCmpdConfig_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    bool_t              blsEnable,
    bool_t              compressEnable,
    bool_t              expandEnable,
    int                *pBlsPara
);

RESULT CamEngineEnableTpg_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableTpg_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineTpgConfig_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    CamerIcIspTpgConfig_ry_t  *pTpgConfig

);

RESULT CamEngineInitStitching_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineEnableStitching_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableStitching_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineStitchingConfig_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    int                     StitchingPara

);

RESULT CamEngineSetStitchingRdWrStr_ry
(
    CamEngineHandle_ry_t hCamEngine,
    int               rdStr
);

RESULT CamEngineBypassMcm_ry
(
    CamEngineHandle_ry_t hCamEngine,
    bool               enable
);

/******************************************************************************
 * CamEngineSetStitchingColorWeight()
 *****************************************************************************/
RESULT CamEngineSetStitchingColorWeight_ry
(
    CamEngineHandle_ry_t hCamEngine,
    const uint8_t                weight0,
    const uint8_t                weight1,
    const uint8_t                weight2
);

RESULT CamEngineSetStitchingProperties
(
    CamEngineHandle_ry_t hCamEngine,
    const CamerIcIspStitchingProperties_ry_t     *pProperties
);

RESULT CamEngineStitchingExpConfig_ry
(
    CamEngineHandle_ry_t       hCamEngine,
    int                     StitchingPara,
    float                   SensorGain[3],
    float                   ExposureTime[3],
    float* hdr_ratio
);

RESULT CamEngineStitchingShortExpSet_ry
(
    CamEngineHandle_ry_t hCamEngine,
    bool_t           ShortExpSet
);

RESULT CamEngineStitchingExtBitGet_ry
(
    CamEngineHandle_ry_t hCamEngine,
    uint8_t           *ext_bit
);
RESULT CamEngineInitEe_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineEnableEe_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableEe_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineEeConfig_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamEngineEeConfig_t *EePara
);

RESULT CamEngineInit2Dnr_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineEnable2Dnr_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisable2Dnr_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngine2DnrConfig_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamerIcIsp2DnrConfig_ry_t * cfgPara
);

RESULT CamEngineEnable3Dnr_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisable3Dnr_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngine3DnrUpdate_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngine3DnrCompute_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngine3DnrSetStrength_ry
(
       CamEngineHandle_ry_t hCamEngine,
       uint32_t denoiseStrength
);

RESULT CamEngine3DnrSetCompress_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamericIsp3DNRCompress_ry_t *compress
);

RESULT CamEngineEnableAfm_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableAfm_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineAfmConfig_ry
(
    CamEngineHandle_ry_t hCamEngine,
    uint32_t AfmWinId,
    uint32_t AfmThresHold
);

RESULT CamEngineDemosaicConfig_ry
(
    CamEngineHandle_ry_t hCamEngine,
    uint32_t DemosaicMode,
    uint32_t DemosaicThreshold
);


RESULT CamEngineDmsc2Configure_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamericIspDemosaicContext_ry_t *pConfig
);

RESULT CamEngineDmsc2GetConfig_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamericIspDemosaicContext_ry_t *pConfig
);

RESULT CamEngineDmsc2Enable_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDmsc2Disable_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineRgbGammaConfigure_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamerIcIspRgbGammaContext_ry_t *pConfig
);

RESULT CamEngineRgbGammaGetConfig_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamerIcIspRgbGammaContext_ry_t *pConfig
);

RESULT CamEngineRgbGammaEnable_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineRgbGammaDisable_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineColorAdjustConfigure_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamerIcIspCa_ry_t *pConfig
);

RESULT CamEngineColorAdjustGetConfig_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamerIcIspCa_ry_t *pConfig
);

RESULT CamEngineColorAdjustEnable_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineColorAdjustDisable_ry
(
    CamEngineHandle_ry_t hCamEngine
);


RESULT CamEngineEnableRgbir_ry
(
    CamEngineHandle_ry_t hCamEngine, 
    bool bEnable
);

RESULT CamEngineEnableRgbirIrRawOut_ry(
    CamEngineHandle_ry_t hCamEngine,
    bool bEnable
) ;

RESULT CamEngineConfigRgbir_ry
(
    CamEngineHandle_ry_t hCamEngine,
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
RESULT CamEngineEnableTdnr3_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineDisableTdnr3_ry
(
    CamEngineHandle_ry_t hCamEngine
);

RESULT CamEngineTdnr3GetConfig_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamerIcIspTdnr3Config_ry_t *pConfig
);

RESULT CamEngineTdnr3SetConfig_ry
(
    CamEngineHandle_ry_t hCamEngine,
    const CamerIcIspTdnr3Config_ry_t *pConfig
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
RESULT CamEngineUpdateTdnr3Curve_ry
(
    CamEngineHandle_ry_t hCamEngine,
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
RESULT CamEngineSetTdnr3Strength_ry
(
    CamEngineHandle_ry_t hCamEngine,
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
RESULT CamEngineEnableDigitalGain_ry(CamEngineHandle_ry_t hCamEngine);

RESULT CamEngineDisableDigitalGain_ry(CamEngineHandle_ry_t hCamEngine);

RESULT CamEngineSetupDigitalGain_ry(CamEngineHandle_ry_t hCamEngine,
                                    const uint16_t rGain,
                                    const uint16_t grGain,
                                    const uint16_t gbGain,
                                    const uint16_t bGain);

RESULT CamEngineEnableGreenEquilibration_ry(CamEngineHandle_ry_t hCamEngine);

RESULT CamEngineDisableGreenEquilibration_ry(CamEngineHandle_ry_t hCamEngine);

RESULT CamEngineSetupGreenEquilibration_ry(CamEngineHandle_ry_t hCamEngine, uint16_t threshold, uint16_t dummyLine);



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
RESULT CamEngine3DNRv3Enable_ry
(
	CamEngineHandle_ry_t hCamEngine,
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
RESULT CamEngine3DNRv3Disable_ry
(
	CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineGeEnable_ry
(
	CamEngineHandle_ry_t	hCamEngine
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
RESULT CamEngineGeDisable_ry
(
	CamEngineHandle_ry_t	hCamEngine
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
RESULT CamEngineGeSetThreshold_ry
(
	CamEngineHandle_ry_t	hCamEngine,
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
RESULT CamEngineGeStatus_ry
(
	CamEngineHandle_ry_t		hCamEngine,
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
RESULT CamEngineGammaRGBEnable_ry
(
	CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineGammaRGBDisable_ry
(
	CamEngineHandle_ry_t hCamEngine
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
RESULT CamEngineGammaRGBSetCurve_ry
(
	CamEngineHandle_ry_t				hCamEngine,
	CamEngineGammaOutRGBCurve_ry_t 	gammaCurve
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
RESULT CamEngineGammaRGBStatus_ry
(
	CamEngineHandle_ry_t	hCamEngine,
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
RESULT CamEngineDgEnable_ry
(
    CamEngineHandle_ry_t   hCamEngine
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
RESULT CamEngineDgDisable_ry
(
    CamEngineHandle_ry_t   hCamEngine
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
RESULT CamEngineDgStatus_ry
(
    CamEngineHandle_ry_t       hCamEngine,
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
RESULT CamEngineDgSetGain_ry
(
    CamEngineHandle_ry_t   hCamEngine,
    const float      	gain
);



#ifdef __cplusplus
}
#endif


/* @} cam_engine_isp_api */


#endif /* __CAM_ENGINE_ISP_RY_API_H__ */

