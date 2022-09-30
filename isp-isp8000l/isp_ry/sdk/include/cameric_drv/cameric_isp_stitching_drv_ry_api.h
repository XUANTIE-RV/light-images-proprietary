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

#ifndef __CAMERIC_ISP_STITCHING_DRV_RY_API_H__
#define __CAMERIC_ISP_STITCHING_DRV_RY_API_H__

/**
* @file    cameric_isp_stitching_drv_ry_api.h
*
* @brief   This file contains the CamerIC ISP STITCHING driver API definitions.
*
*****************************************************************************/
/**
* @cond cameric_isp_stitching
*
* @defgroup cameric_isp_stitching_drv_api CamerIC ISP STITCHING Driver API definitions
* @{
*
*/
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>
#include "cameric_isp_exp_drv_ry_api.h"
#include "cameric_isp_hist_drv_ry_api.h"

#ifdef __cplusplus
extern "C"
{
#endif


/*****************************************************************************/
/**
 * @brief   This macro defines the size of stitching compress
 *			Look-Up Table
 *
 *****************************************************************************/
#define CAMERIC_ISP_STITCHING_LUT_SIZE      15U



/******************************************************************************/
/**
 * @brief   Enumeration type to configure the vertical and horizontal
 *          polarity type in stitching.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingPolarityType_ry_e
{
    CAMERIC_ISP_STITCHING_POLARITY_TYPE_INVALID_RY            = 0,			/**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_POLARITY_TYPE_LEVEL_RY              = 1,			/**< signal from sesnro is level */
    CAMERIC_ISP_STITCHING_POLARITY_TYPE_PULSE_RY              = 2,			/**< signal from sensor is pulse */
    CAMERIC_ISP_STITCHING_POLARITY_TYPE_MAX_RY								/**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingPolarityType_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure the bayer pattern in the
 *          stitching.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingBayerPattern_ry_e
{
    CAMERIC_ISP_STITCHING_BAYER_PATTERN_INVALID_RY       = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_BAYER_PATTERN_RGRGGBGB_RY      = 1,        /**< 1st line: RGRG... , 2nd line GBGB... , etc. */
    CAMERIC_ISP_STITCHING_BAYER_PATTERN_GRGRBGBG_RY      = 2,        /**< 1st line: GRGR... , 2nd line BGBG... , etc. */
    CAMERIC_ISP_STITCHING_BAYER_PATTERN_GBGBRGRG_RY      = 3,        /**< 1st line: GBGB... , 2nd line RGRG... , etc. */
    CAMERIC_ISP_STITCHING_BAYER_PATTERN_BGBGGRGR_RY      = 4,        /**< 2st line: BGBG... , 2nd line GRGR... , etc. */
    CAMERIC_ISP_STITCHING_BAYER_PATTERN_MAX_RY                       /**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingBayerPattern_ry_t;


/******************************************************************************/
/**
 * @brief   Enumeration type to configure bypass select mode.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingBypassSelectMode_ry_e
{
    CAMERIC_ISP_STITCHING_BYPASS_SELECT_MODE_INVALID_RY		= 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_BYPASS_SELECT_MODE_LONG_RY			= 1,        /**< select long frame */
    CAMERIC_ISP_STITCHING_BYPASS_SELECT_MODE_SHORT_RY			= 2,        /**< select short frame */
    CAMERIC_ISP_STITCHING_BYPASS_SELECT_MODE_VERY_SHORT_RY     = 3,        /**< select very short frame */
    CAMERIC_ISP_STITCHING_BYPASS_SELECT_MODE_MAX_RY						/**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingBypassSelectMode_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure combination mode.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingCombinationMode_ry_e
{
    CAMERIC_ISP_STITCHING_COMBINATION_MODE_INVALID_RY			= 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_COMBINATION_MODE_0_RY				= 1,        /**< linear L+S and LV+VS*/
    CAMERIC_ISP_STITCHING_COMBINATION_MODE_1_RY				= 2,        /**< nonlinear L+S */
    CAMERIC_ISP_STITCHING_COMBINATION_MODE_2_RY    		 	= 3,        /**< linear L+S and nonlinear LS+VS */
    CAMERIC_ISP_STITCHING_COMBINATION_MODE_MAX_RY							/**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingCombinationMode_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure base frame selection.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingBaseFrameSelection_ry_e
{
    CAMERIC_ISP_STITCHING_BASE_FRAME_SELECTION_INVALID_RY			= 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_BASE_FRAME_SELECTION_SHORT_RY			= 1,        /**< select short frame as base frame */
    CAMERIC_ISP_STITCHING_BASE_FRAME_SELECTION_LONG_RY				= 2,        /**< select long frame as base frame */
    CAMERIC_ISP_STITCHING_BASE_FRAME_SELECTION_MAX_RY							/**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingBaseFrameSelection_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure hdr mode.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingHdrMode_ry_e
{
    CAMERIC_ISP_STITCHING_HDR_MODE_INVALID_RY			= 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_HDR_MODE_DUAL_DCG_RY			= 1,        /**< dual DCG mode 3x12-bit */
    CAMERIC_ISP_STITCHING_HDR_MODE_3DOL_RY				= 2,        /**< dol3 frame 3x12-bit */
	CAMERIC_ISP_STITCHING_HDR_MODE_LINEBYLINE_RY		= 3,		/**< 3x12-bit line by line without waiting */
	CAMERIC_ISP_STITCHING_HDR_MODE_16BIT_COMPRESS_RY	= 4,		/**< 16-bit compressed data + 12-bit RAW */
	CAMERIC_ISP_STITCHING_HDR_MODE_DUAL_DCG_NOWAIT_RY	= 5,		/**< 2x12-bit dual DCG without waiting */
	CAMERIC_ISP_STITCHING_HDR_MODE_2DOL_RY				= 6,		/**< dol2 frame or 1 CG+VS sx12-bit RAW */
	CAMERIC_ISP_STITCHING_HDR_MODE_L_AND_S_RY			= 7,		/**< L+S 2x12-bit RAW */
	CAMERIC_ISP_STITCHING_HDR_MODE_MAX_RY							/**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingHdrMode_ry_t;

/******************************************************************************/
/**
 * @brief   Enumeration type to configure hdr RET STR.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingHdrRdStr_ry_e
{
    CAMERIC_ISP_STITCHING_HDR_RD_STR_INVALID_RY			= 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_HDR_RD_STR_L_RY		= 1,
    CAMERIC_ISP_STITCHING_HDR_RD_STR_L_S_RY				= 2,
	CAMERIC_ISP_STITCHING_HDR_RD_STR_L_S_VS_RY		= 3,
	CAMERIC_ISP_STITCHING_HDR_RD_STR_L_VS_RY	= 4,
	CAMERIC_ISP_STITCHING_HDR_RD_STR_MAX_RY							/**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingHdrRdStr_ry_t;


/*****************************************************************************/
/**
 * @brief   Stitching properties configuration structure
 *
 *****************************************************************************/
typedef struct CamerIcIspStitchingProperties_ry_s
{
    bool				        				regsInformEnable;
	bool										awbGainEnable;
	uint16_t									width;
	uint16_t									height;
	uint8_t										longBitDepth;
	uint8_t										shortBitDepth;
	uint8_t										vsBitDepth;
	uint8_t										lsBitDepth;
	uint16_t									longExposureTime;
	uint16_t									shortExposureTime;
	uint16_t									vsExposureTime;
	uint16_t									dummyShortHBlank;
	uint16_t									outHBlank;
	uint16_t									dummyVsHBlank;
	uint16_t									outVBlank;
    CamerIcIspStitchingPolarityType_ry_t     		hSyncPol;
    CamerIcIspStitchingPolarityType_ry_t     		vSyncPol;
    CamerIcIspStitchingBayerPattern_ry_t      		bayerPattern;
	CamerIcIspStitchingBypassSelectMode_ry_t		bypassSelectMode;
	CamerIcIspStitchingCombinationMode_ry_t		combinationMode;
	CamerIcIspStitchingBaseFrameSelection_ry_t		baseFrameSelection;
	CamerIcIspStitchingHdrMode_ry_t				hdrMode;
} CamerIcIspStitchingProperties_ry_t;



/*****************************************************************************/
/**
 * @brief   Stitching compress LUT configuration structure
 *
 *****************************************************************************/
typedef struct CamerIcIspStitchingCompressLookUpTable_ry_s
{
	uint8_t		lutFirstValidX;										/**< LUT first valid x */
    uint16_t    sampleVal[CAMERIC_ISP_STITCHING_LUT_SIZE];			/**< LUT sample value */
} CamerIcIspStitchingCompressLookUpTable_ry_t;



/*****************************************************************************/
/**
*          CamerIcIspStitchingEnable_ry()
*
* @brief   Enable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingEnable_ry
(
	CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingDisable_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingDisable_ry
(
	CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
*          CamerIcIspSetStitchingProperties_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspSetStitchingProperties_ry
(
	CamerIcDrvHandle_ry_t 						handle,
	const CamerIcIspStitchingProperties_ry_t 	*pProperties
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingGetBlackLevel_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingGetBlackLevel_ry
(
    CamerIcDrvHandle_ry_t  handle,
    uint16_t            *isp_bls_a_fixed,
    uint16_t            *isp_bls_b_fixed,
    uint16_t            *isp_bls_c_fixed,
    uint16_t            *isp_bls_d_fixed
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetBlackLevel_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingSetBlackLevel_ry
(
	CamerIcDrvHandle_ry_t	handle,
	const uint16_t		isp_bls_a_fixed,
	const uint16_t		isp_bls_b_fixed,
	const uint16_t		isp_bls_c_fixed,
	const uint16_t		isp_bls_d_fixed
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingGetAwbGain_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingGetAwbGain_ry
(
	CamerIcDrvHandle_ry_t handle,
	CamerIcGains_ry_t	  *pGains
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetAwbGain_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingSetAwbGain_ry
(
	CamerIcDrvHandle_ry_t		handle,
	const CamerIcGains_ry_t	*pGains
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetLinearTransRange_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingSetLinearTransRange_ry
(
	CamerIcDrvHandle_ry_t		handle,
	const uint16_t			startLinear,
	const uint16_t			factorMulLinear
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetNonlinearTransRange_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingSetNonlinearTransRange_ry
(
	CamerIcDrvHandle_ry_t		handle,
	const uint16_t			startNonLinear,
	const uint16_t			factorMulNonLinear
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetLSRatio_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingSetLSRatio_ry
(
	CamerIcDrvHandle_ry_t 		handle,
	const uint16_t			ratio_0,
	const uint16_t			ratio_1
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetVSRatio_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingSetVSRatio_ry
(
	CamerIcDrvHandle_ry_t		handle,
	const uint16_t			ratio_0,
	const uint16_t			ratio_1
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetCompressLUT_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingSetCompressLUT_ry
(
	CamerIcDrvHandle_ry_t 									handle,
	const CamerIcIspStitchingCompressLookUpTable_ry_t		*pCompessLut
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingGetExtBit_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingGetExtBit_ry
(
	CamerIcDrvHandle_ry_t		handle,
	uint8_t            		*pLsExtBit,
	uint8_t            		*pVsExtBit
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetExtBit_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingSetExtBit_ry
(
	CamerIcDrvHandle_ry_t 		handle,
	const uint8_t      		lsExtBit,
	const uint8_t      		vsExtBit
);
RESULT CamerIcIspStitchingDigitalGainSet_ry(CamerIcDrvHandle_ry_t handle,
                                       const uint16_t isp_digital_gain_r_fixed,
                                       const uint16_t isp_digital_gain_g_fixed,
                                       const uint16_t isp_digital_gain_gr_fixed,
                                       const uint16_t isp_digital_gain_gb_fixed);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetVSParams_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingSetVSParams_ry
(
	CamerIcDrvHandle_ry_t		handle,
	const uint16_t			vs_valid_thresh,
	const uint16_t			vs_valid_offset_val
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetLSParams_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingSetLSParams_ry
(
	CamerIcDrvHandle_ry_t 		handle,
	const uint16_t			long_sat_thresh,
	const uint16_t			long_combine_weight
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetColorWeight_ry()
*
* @brief   Disable STITCHING Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingSetColorWeight_ry
(
	CamerIcDrvHandle_ry_t		handle,
	const uint8_t 			weight0,
	const uint8_t 			weight1,
	const uint8_t 			weight2
);


RESULT CamerIcIspStitchingIsEnabled_ry
(
	CamerIcDrvHandle_ry_t handle,
	bool_t             *pIsEnabled
);

RESULT CamerIcIspStitchingHdrMode_ry
(
	CamerIcDrvHandle_ry_t handle,
	int               *pHdrMode
);

/*****************************************************************************/
/**
*          CamerIcIspStitchingSetRdWrStr()
*
* @brief   set stitching RdWr str.
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIspStitchingSetRdWrStr_ry
(
    CamerIcDrvHandle_ry_t handle,
    uint8_t            rdWrStr
);
#ifdef __cplusplus
}
#endif

/* @} cameric_isp_stitching_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_STITCHING_DRV_RY_API_H__ */

