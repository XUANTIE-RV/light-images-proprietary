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

#ifndef __CAMERIC_ISP_DPF_DRV_RY_API_H__
#define __CAMERIC_ISP_DPF_DRV_RY_API_H__

/**
 * @file    cameric_isp_dpf_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC ISP DPF driver API definitions.
 *
 *****************************************************************************/
/**
 * @cond cameric_isp_dpf
 *
 * @defgroup cameric_isp_dpf_drv_api CamerIC ISP DPF Driver API definitions
 * @{
 *
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>
#include <common/list_ry.h>
//#include <ic_dev.h>

#ifdef __cplusplus
extern "C"
{
#endif




#define CAMERIC_DPF_MAX_NLF_COEFFS      17
#define CAMERIC_DPF_MAX_SPATIAL_COEFFS  6



/*****************************************************************************/
/**
 * @brief   This type defines the supported filter kernel sizes for the red
 *          and blue channels.
 */
/*****************************************************************************/
typedef enum CamerIcDpfRedBlueFilterSize_ry_e
{
    CAMERIC_DPF_RB_FILTERSIZE_INVALID   = 0,    /**< lower border (only for an internal evaluation) */
    CAMERIC_DPF_RB_FILTERSIZE_9x9       = 1,    /**< red and blue filter kernel size 9x9 (means 5x5 active pixel) */
    CAMERIC_DPF_RB_FILTERSIZE_13x9      = 2,    /**< red and blue filter kernel size 13x9 (means 7x5 active pixel) */
    CAMERIC_DPF_RB_FILTERSIZE_MAX               /**< upper border (only for an internal evaluation) */
} CamerIcDpfRedBlueFilterSize_ry_t;



/*****************************************************************************/
/**
 * @brief   This type defines the supported gain usage modes in the DPF
 *          preprocessing stage.
 */
/*****************************************************************************/
typedef enum CamerIcDpfGainUsage_ry_e
{
    CAMERIC_DPF_GAIN_USAGE_INVALID       = 0,   /**< lower border (only for an internal evaluation) */
    CAMERIC_DPF_GAIN_USAGE_DISABLED      = 1,   /**< don't use any gains in preprocessing stage */
    CAMERIC_DPF_GAIN_USAGE_NF_GAINS      = 2,   /**< use only the noise function gains  from registers DPF_NF_GAIN_R, ... */
    CAMERIC_DPF_GAIN_USAGE_LSC_GAINS     = 3,   /**< use only the gains from LSC module */
    CAMERIC_DPF_GAIN_USAGE_NF_LSC_GAINS  = 4,   /**< use the moise function gains and the gains from LSC module */
    CAMERIC_DPF_GAIN_USAGE_AWB_GAINS     = 5,   /**< use only the gains from AWB module */
    CAMERIC_DPF_GAIN_USAGE_AWB_LSC_GAINS = 6,   /**< use the gains from AWB and LSC module */
    CAMERIC_DPF_GAIN_USAGE_MAX                  /**< upper border (only for an internal evaluation) */
} CamerIcDpfGainUsage_ry_t;



/*****************************************************************************/
/**
 * @brief   This type defines the supported scaling of x axis.
 */
/*****************************************************************************/
typedef enum CamerIcDpfNoiseLevelLookUpScale_ry_e
{
    CAMERIC_NLL_SCALE_INVALID       = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_NLL_SCALE_LINEAR        = 1,        /**< use a linear scaling */
    CAMERIC_NLL_SCALE_LOGARITHMIC   = 2,        /**< use a logarithmic scaling */
    CAMERIC_NLL_SCALE_MAX                       /**< upper border (only for an internal evaluation) */
} CamerIcDpfNoiseLevelLookUpScale_ry_t;



/*****************************************************************************/
/**
 * @brief   This type defines the
 */
/*****************************************************************************/
typedef struct CamerIcDpfInvStrength_ry_s
{
    uint8_t WeightR;
    uint8_t WeightG;
    uint8_t WeightB;
} CamerIcDpfInvStrength_ry_t;



/*****************************************************************************/
/**
 * @brief
 */
/*****************************************************************************/
typedef struct CamerIcDpfNoiseLevelLookUp_ry_s
{
    uint16_t                            NllCoeff[CAMERIC_DPF_MAX_NLF_COEFFS];   /**< Noise-Level-Lookup coefficients */
    CamerIcDpfNoiseLevelLookUpScale_ry_t   xScale;                                 /**< type of x-axis (logarithmic or linear type) */
} CamerIcDpfNoiseLevelLookUp_ry_t;



/*****************************************************************************/
/**
 * @brief   This type defines the supported filter kernel sizes for the red
 *          and blue channels.
 */
/*****************************************************************************/
typedef struct CamerIcDpfSpatial_ry_s
{
    uint8_t WeightCoeff[CAMERIC_DPF_MAX_SPATIAL_COEFFS];
} CamerIcDpfSpatial_ry_t;



/*****************************************************************************/
/**
 * @brief   This type defines the configuration structure of the CamerIc
 *          DPF module.
 */
/*****************************************************************************/
typedef struct CamerIcDpfConfig_ry_s
{
    CamerIcDpfGainUsage_ry_t           GainUsage;              /**< which gains shall be used in preprocessing stage of dpf module */

    CamerIcDpfRedBlueFilterSize_ry_t   RBFilterSize;           /**< size of filter kernel for red/blue pixel */

    bool_t                          ProcessRedPixel;        /**< enable filter processing for red pixel */
    bool_t                          ProcessGreenRPixel;     /**< enable filter processing for green pixel in red lines */
    bool_t                          ProcessGreenBPixel;     /**< enable filter processing for green pixel in blue lines */
    bool_t                          ProcessBluePixel;       /**< enable filter processing for blux pixel */

    CamerIcDpfSpatial_ry_t             SpatialG;               /**< spatial weights for green pixel */
    CamerIcDpfSpatial_ry_t             SpatialRB;              /**< spatial weights for red/blue pixel */
} CamerIcDpfConfig_ry_t;



/*****************************************************************************/
/**
 * @brief   This function enables the CamerIc ISP DPF module.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 *
 *****************************************************************************/
extern RESULT CamerIcIspDpfEnable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 * @brief   This function disables the CamerIc ISP DPF module.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 *
 *****************************************************************************/
extern RESULT CamerIcIspDpfDisable_ry
(
    CamerIcDrvHandle_ry_t handle
);


/*****************************************************************************/
/**
 * @brief   This functions returns the current status of the CamerIc ISP
 *          DPF module.
 *
 * @param   handle          CamerIc driver handle.
 * @param   pIsEnabled
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
extern RESULT CamerIcIspDpfIsEnabled_ry
(
    CamerIcDrvHandle_ry_t      handle,
    bool_t                  *pIsEnabled
);



/*****************************************************************************/
/**
 * @brief   This function configures the CamerIc ISP DPF module.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 *
 *****************************************************************************/
extern RESULT CamerIcIspDpfConfig_ry
(
    CamerIcDrvHandle_ry_t          handle,
    const CamerIcDpfConfig_ry_t    *pDpfCfg
);



/*****************************************************************************/
/**
 * @brief   This function sets the noise function gains to the CamerIc ISP
 *          DPF module.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_NULL_POINTER    NULL pointer detected
 *
 *****************************************************************************/
extern RESULT CamerIcIspDpfSetNoiseFunctionGain_ry
(
    CamerIcDrvHandle_ry_t      handle,
    const CamerIcGains_ry_t    *pNfGains
);



/*****************************************************************************/
/**
 * @brief   Programs the given inverse strength to the CamerIc ISP DPF module.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_NULL_POINTER    NULL pointer detected
 *
 *****************************************************************************/
extern RESULT CamerIcIspDpfSetStrength_ry
(
    CamerIcDrvHandle_ry_t              handle,
    const CamerIcDpfInvStrength_ry_t   *pDpfStrength
);



/*****************************************************************************/
/**
 * @brief   Programs the given Noise-Level-Lookup-Table to the CamerIc
 *          ISP DPF module
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_NULL_POINTER    NULL pointer detected
 *
 *****************************************************************************/
extern RESULT CamerIcIspDpfSetNoiseLevelLookUp_ry
(
    CamerIcDrvHandle_ry_t                  handle,
    const CamerIcDpfNoiseLevelLookUp_ry_t  *pDpfNll
);

extern RESULT CamerIcIspDpfSetFullConfig_ry (CamerIcDrvHandle_ry_t handle, struct isp_dpf_context *dpf);


#ifdef __cplusplus
}
#endif

/* @} cameric_isp_dpf_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_DPF_DRV_RY_API_H__ */

