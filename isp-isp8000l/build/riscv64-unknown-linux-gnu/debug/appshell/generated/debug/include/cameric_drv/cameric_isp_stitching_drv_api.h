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

#ifndef __CAMERIC_ISP_STITCHING_DRV_API_H__
#define __CAMERIC_ISP_STITCHING_DRV_API_H__

/**
* @file    cameric_isp_stitching_drv_api.h
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
#include <ebase/types.h>
#include <common/return_codes.h>
#include "cameric_isp_exp_drv_api.h"
#include "cameric_isp_hist_drv_api.h"

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
typedef enum CamerIcIspStitchingPolarityType_e
{
    CAMERIC_ISP_STITCHING_POLARITY_TYPE_INVALID            = 0,			/**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_POLARITY_TYPE_LEVEL              = 1,			/**< signal from sesnro is level */
    CAMERIC_ISP_STITCHING_POLARITY_TYPE_PULSE              = 2,			/**< signal from sensor is pulse */
    CAMERIC_ISP_STITCHING_POLARITY_TYPE_MAX								/**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingPolarityType_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure the bayer pattern in the
 *          stitching.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingBayerPattern_e
{
    CAMERIC_ISP_STITCHING_BAYER_PATTERN_INVALID       = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_BAYER_PATTERN_RGRGGBGB      = 1,        /**< 1st line: RGRG... , 2nd line GBGB... , etc. */
    CAMERIC_ISP_STITCHING_BAYER_PATTERN_GRGRBGBG      = 2,        /**< 1st line: GRGR... , 2nd line BGBG... , etc. */
    CAMERIC_ISP_STITCHING_BAYER_PATTERN_GBGBRGRG      = 3,        /**< 1st line: GBGB... , 2nd line RGRG... , etc. */
    CAMERIC_ISP_STITCHING_BAYER_PATTERN_BGBGGRGR      = 4,        /**< 2st line: BGBG... , 2nd line GRGR... , etc. */
    CAMERIC_ISP_STITCHING_BAYER_PATTERN_MAX                       /**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingBayerPattern_t;


/******************************************************************************/
/**
 * @brief   Enumeration type to configure bypass select mode.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingBypassSelectMode_e
{
    CAMERIC_ISP_STITCHING_BYPASS_SELECT_MODE_INVALID		= 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_BYPASS_SELECT_MODE_LONG			= 1,        /**< select long frame */
    CAMERIC_ISP_STITCHING_BYPASS_SELECT_MODE_SHORT			= 2,        /**< select short frame */
    CAMERIC_ISP_STITCHING_BYPASS_SELECT_MODE_VERY_SHORT     = 3,        /**< select very short frame */
    CAMERIC_ISP_STITCHING_BYPASS_SELECT_MODE_MAX						/**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingBypassSelectMode_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure combination mode.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingCombinationMode_e
{
    CAMERIC_ISP_STITCHING_COMBINATION_MODE_INVALID			= 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_COMBINATION_MODE_0				= 1,        /**< linear L+S and LV+VS*/
    CAMERIC_ISP_STITCHING_COMBINATION_MODE_1				= 2,        /**< nonlinear L+S */
    CAMERIC_ISP_STITCHING_COMBINATION_MODE_2    		 	= 3,        /**< linear L+S and nonlinear LS+VS */
    CAMERIC_ISP_STITCHING_COMBINATION_MODE_MAX							/**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingCombinationMode_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure base frame selection.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingBaseFrameSelection_e
{
    CAMERIC_ISP_STITCHING_BASE_FRAME_SELECTION_INVALID			= 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_BASE_FRAME_SELECTION_SHORT			= 1,        /**< select short frame as base frame */
    CAMERIC_ISP_STITCHING_BASE_FRAME_SELECTION_LONG				= 2,        /**< select long frame as base frame */
    CAMERIC_ISP_STITCHING_BASE_FRAME_SELECTION_MAX							/**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingBaseFrameSelection_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure hdr mode.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingHdrMode_e
{
    CAMERIC_ISP_STITCHING_HDR_MODE_INVALID			= 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_HDR_MODE_DUAL_DCG			= 1,        /**< dual DCG mode 3x12-bit */
    CAMERIC_ISP_STITCHING_HDR_MODE_3DOL				= 2,        /**< dol3 frame 3x12-bit */
	CAMERIC_ISP_STITCHING_HDR_MODE_LINEBYLINE		= 3,		/**< 3x12-bit line by line without waiting */
	CAMERIC_ISP_STITCHING_HDR_MODE_16BIT_COMPRESS	= 4,		/**< 16-bit compressed data + 12-bit RAW */
	CAMERIC_ISP_STITCHING_HDR_MODE_DUAL_DCG_NOWAIT	= 5,		/**< 2x12-bit dual DCG without waiting */
	CAMERIC_ISP_STITCHING_HDR_MODE_2DOL				= 6,		/**< dol2 frame or 1 CG+VS sx12-bit RAW */
	CAMERIC_ISP_STITCHING_HDR_MODE_L_AND_S			= 7,		/**< L+S 2x12-bit RAW */
	CAMERIC_ISP_STITCHING_HDR_MODE_MAX							/**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingHdrMode_t;

/******************************************************************************/
/**
 * @brief   Enumeration type to configure hdr RET STR.
 *
 *****************************************************************************/
typedef enum CamerIcIspStitchingHdrRdStr_e
{
    CAMERIC_ISP_STITCHING_HDR_RD_STR_INVALID			= 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_STITCHING_HDR_RD_STR_L		= 1,
    CAMERIC_ISP_STITCHING_HDR_RD_STR_L_S				= 2,
	CAMERIC_ISP_STITCHING_HDR_RD_STR_L_S_VS		= 3,
	CAMERIC_ISP_STITCHING_HDR_RD_STR_L_VS	= 4,
	CAMERIC_ISP_STITCHING_HDR_RD_STR_MAX							/**< upper border (only for an internal evaluation) */
} CamerIcIspStitchingHdrRdStr_t;


/*****************************************************************************/
/**
 * @brief   Stitching properties configuration structure
 *
 *****************************************************************************/
typedef struct CamerIcIspStitchingProperties_s
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
    CamerIcIspStitchingPolarityType_t     		hSyncPol;
    CamerIcIspStitchingPolarityType_t     		vSyncPol;
    CamerIcIspStitchingBayerPattern_t      		bayerPattern;
	CamerIcIspStitchingBypassSelectMode_t		bypassSelectMode;
	CamerIcIspStitchingCombinationMode_t		combinationMode;
	CamerIcIspStitchingBaseFrameSelection_t		baseFrameSelection;
	CamerIcIspStitchingHdrMode_t				hdrMode;
} CamerIcIspStitchingProperties_t;



/*****************************************************************************/
/**
 * @brief   Stitching compress LUT configuration structure
 *
 *****************************************************************************/
typedef struct CamerIcIspStitchingCompressLookUpTable_s
{
	uint8_t		lutFirstValidX;										/**< LUT first valid x */
    uint16_t    sampleVal[CAMERIC_ISP_STITCHING_LUT_SIZE];			/**< LUT sample value */
} CamerIcIspStitchingCompressLookUpTable_t;



/*****************************************************************************/
/**
*          CamerIcIspStitchingEnable()
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
RESULT CamerIcIspStitchingEnable
(
	CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingDisable()
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
RESULT CamerIcIspStitchingDisable
(
	CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
*          CamerIcIspSetStitchingProperties()
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
RESULT CamerIcIspSetStitchingProperties
(
	CamerIcDrvHandle_t 						handle,
	const CamerIcIspStitchingProperties_t 	*pProperties
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingGetBlackLevel()
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
RESULT CamerIcIspStitchingGetBlackLevel
(
    CamerIcDrvHandle_t  handle,
    uint16_t            *isp_bls_a_fixed,
    uint16_t            *isp_bls_b_fixed,
    uint16_t            *isp_bls_c_fixed,
    uint16_t            *isp_bls_d_fixed
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetBlackLevel()
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
RESULT CamerIcIspStitchingSetBlackLevel
(
	CamerIcDrvHandle_t	handle,
	const uint16_t		isp_bls_a_fixed,
	const uint16_t		isp_bls_b_fixed,
	const uint16_t		isp_bls_c_fixed,
	const uint16_t		isp_bls_d_fixed
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingGetAwbGain()
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
RESULT CamerIcIspStitchingGetAwbGain
(
	CamerIcDrvHandle_t handle,
	CamerIcGains_t	  *pGains
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetAwbGain()
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
RESULT CamerIcIspStitchingSetAwbGain
(
	CamerIcDrvHandle_t		handle,
	const CamerIcGains_t	*pGains
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetLinearTransRange()
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
RESULT CamerIcIspStitchingSetLinearTransRange
(
	CamerIcDrvHandle_t		handle,
	const uint16_t			startLinear,
	const uint16_t			factorMulLinear
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetNonlinearTransRange()
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
RESULT CamerIcIspStitchingSetNonlinearTransRange
(
	CamerIcDrvHandle_t		handle,
	const uint16_t			startNonLinear,
	const uint16_t			factorMulNonLinear
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetLSRatio()
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
RESULT CamerIcIspStitchingSetLSRatio
(
	CamerIcDrvHandle_t 		handle,
	const uint16_t			ratio_0,
	const uint16_t			ratio_1
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetVSRatio()
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
RESULT CamerIcIspStitchingSetVSRatio
(
	CamerIcDrvHandle_t		handle,
	const uint16_t			ratio_0,
	const uint16_t			ratio_1
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetCompressLUT()
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
RESULT CamerIcIspStitchingSetCompressLUT
(
	CamerIcDrvHandle_t 									handle,
	const CamerIcIspStitchingCompressLookUpTable_t		*pCompessLut
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingGetExtBit()
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
RESULT CamerIcIspStitchingGetExtBit
(
	CamerIcDrvHandle_t		handle,
	uint8_t            		*pLsExtBit,
	uint8_t            		*pVsExtBit
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetExtBit()
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
RESULT CamerIcIspStitchingSetExtBit
(
	CamerIcDrvHandle_t 		handle,
	const uint8_t      		lsExtBit,
	const uint8_t      		vsExtBit
);
RESULT CamerIcIspStitchingDigitalGainSet(CamerIcDrvHandle_t handle,
                                       const uint16_t isp_digital_gain_r_fixed,
                                       const uint16_t isp_digital_gain_g_fixed,
                                       const uint16_t isp_digital_gain_gr_fixed,
                                       const uint16_t isp_digital_gain_gb_fixed);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetVSParams()
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
RESULT CamerIcIspStitchingSetVSParams
(
	CamerIcDrvHandle_t		handle,
	const uint16_t			vs_valid_thresh,
	const uint16_t			vs_valid_offset_val
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetLSParams()
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
RESULT CamerIcIspStitchingSetLSParams
(
	CamerIcDrvHandle_t 		handle,
	const uint16_t			long_sat_thresh,
	const uint16_t			long_combine_weight
);



/*****************************************************************************/
/**
*          CamerIcIspStitchingSetColorWeight()
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
RESULT CamerIcIspStitchingSetColorWeight
(
	CamerIcDrvHandle_t		handle,
	const uint8_t 			weight0,
	const uint8_t 			weight1,
	const uint8_t 			weight2
);


RESULT CamerIcIspStitchingIsEnabled
(
	CamerIcDrvHandle_t handle,
	bool_t             *pIsEnabled
);

RESULT CamerIcIspStitchingHdrMode
(
	CamerIcDrvHandle_t handle,
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
RESULT CamerIcIspStitchingSetRdWrStr
(
    CamerIcDrvHandle_t handle,
    uint8_t            rdWrStr
);
#ifdef __cplusplus
}
#endif

/* @} cameric_isp_stitching_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_STITCHING_DRV_API_H__ */

