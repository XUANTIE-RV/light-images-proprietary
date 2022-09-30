/******************************************************************************
 *
 * Copyright 2020, Verisilicon. All rights reserved.
 *
 *****************************************************************************/

#ifndef __ADCI_H__
#define __ADCI_H__

/**
 * @file adci.h
 *
 * @brief
 *
 *****************************************************************************/
/**
 * @page module_name_page Module Name
 * Describe here what this module does.
 *
 * For a detailed list of functions and implementation detail refer to:
 * - @ref module_name
 *
 * @defgroup ADCI Auto Dynamic Contrast Improvement module
 * @{
 *
 */
#include <ebase/types.h>
#include <common/return_codes.h>

#include <isi/isi_iss.h>
#include <isi/isi.h>
#include <cameric_drv/cameric_isp_color_adjust_drv_api.h>



#ifdef __cplusplus
extern "C"
{
#endif



/*****************************************************************************/
/**
 * @brief
 *
 */
/*****************************************************************************/
typedef enum AdciRunMode_e
{
    ADCI_MODE_INVALID                    = 0,        /**< initialization value */
    ADCI_MODE_MANUAL                     = 1,        /**< run manual wide dynamic range(V3) */
    ADCI_MODE_AUTO                       = 2,        /**< run auto wide dynamic range(V3) */
    ADCI_MODE_MAX
} AdciMode_t;



/*****************************************************************************/
/**
 *          AdciHandle_t
 *
 * @brief   ADCI Module instance handle
 *
 *****************************************************************************/
typedef struct AdciContext_s *AdciHandle_t;         /**< handle to ADCI context */



/*****************************************************************************/
/**
 *          AdciInstanceConfig_t
 *
 * @brief   ADCI Module instance configuration structure
 *
 *****************************************************************************/
typedef struct AdciInstanceConfig_s
{
    CamerIcDrvHandle_t      hCamerIc;           /**< handle to cameric driver */
    CamerIcDrvHandle_t      hSubCamerIc;        /**< handle to 2nd cameric drivder (3D) */

    AdciHandle_t            hAdci;            /**< handle returned by AdciInit() */
} AdciInstanceConfig_t;


typedef enum AdciCurveMode_e
{
    ADCI_CURVE_MODE_INVALID 	= 0,    /**< invalid mode (only for initialization) */
    ADCI_CURVE_MODE_SECTION2  	= 1,
    ADCI_CURVE_MODE_SECTION3  	= 2,
    ADCI_CURVE_MODE_HISTOGRAM	= 3,
    ADCI_CURVE_MODE_MAX
} AdciCurveMode_t;


typedef struct AdciSection_s
{
	float							lowExponent;
	float							middleExponent;
	float							highExponent;
	uint16_t						pStartX;
	uint16_t						pStartY;
	uint16_t						pInflectionX;
	uint16_t						pInflectionY;
	uint16_t						pEndX;
	uint16_t						pEndY;
	uint16_t						pInflection2X;	/* only for 3 section mode */
	uint16_t						pInflection2Y;	/* only for 3 section mode */
} AdciSection_t;


typedef struct AdciHistogram_s
{
	float							scale;
	float							stepSize;
	float							base;
	float							strength;
	float							damp;
} AdciHistogram_t;



/*****************************************************************************/
/**
 *          AdciConfig_t
 *
 * @brief   ADCI Module configuration structure
 *
 *****************************************************************************/
typedef struct AdciConfig_s
{
	AdciCurveMode_t						mode;
    AdciSection_t						section;
    AdciHistogram_t						histogram;
} AdciConfig_t;



/*****************************************************************************/
/**
 *          AdciParamNode_t
 *
 * @brief   ADCI parameters node structure
 *
 *****************************************************************************/
typedef struct AdciParamNode_s
{
	float					gain;				/**< gain */
	float					integrationTime;	/**< integrationTime */
    AdciSection_t			section;
    AdciHistogram_t			histogram;
} AdciParamNode_t;



/*****************************************************************************/
/**
 *          AdciStatus_t
 *
 * @brief   ADCI parameters node structure
 *
 *****************************************************************************/
typedef struct AdciStatus_s
{
	AdciCurveMode_t		mode;
	AdciParamNode_t 	params;
	uint16_t			luma[CA_CURVE_DATA_TABLE_LEN];
} AdciStatus_t;



/*****************************************************************************/
/**
 *          AdciParamTable_t
 *
 * @brief   ADCI Module parameters table structure
 *
 *****************************************************************************/
typedef struct AdciParamTable_s
{
    uint8_t					nodeNum;  			/**< nodeNum */
    AdciParamNode_t			*pNodeList;			/**< point of Node List  */
} AdciParamTable_t;



/*****************************************************************************/
/**
 *          AdciInit()
 *
 * @brief   This function initializes the Auto wide dynamic range v3 module
 *
 * @param   pInstConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_INVALID_PARM
 * @retval  RET_OUTOFMEM
 *
 *****************************************************************************/
RESULT AdciInit
(
    AdciInstanceConfig_t *pInstConfig
);



/*****************************************************************************/
/**
 *          AdciRelease()
 *
 * @brief   The function releases/frees the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to ADCIM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AdciRelease
(
    AdciHandle_t handle
);



/*****************************************************************************/
/**
 *          AdciConfigure()
 *
 * @brief   This function configures the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to ADCIM
 * @param   pConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AdciConfigure
(
    AdciHandle_t handle,
    AdciConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AdciReConfigure()
 *
 * @brief   This function re-configures the Auto wide dynamic range v3 Module
 *          after e.g. resolution change
 *
 * @param   handle  Handle to ADCIM
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AdciReConfigure
(
    AdciHandle_t handle,
    AdciConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AdciSetAutoParamTable()
 *
 * @brief   This function set auto mode parameters table
 *
 * @param   handle  Handle to ADCIM
 * @param   pParamTable
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AdciSetAutoParamTable
(
    AdciHandle_t handle,
    AdciParamTable_t *pParamTable
);



/*****************************************************************************/
/**
 *          AdciStart()
 *
 * @brief   The function starts the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to ADCIM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AdciStart
(
    AdciHandle_t 		handle,
    const AdciMode_t	mode
);



/*****************************************************************************/
/**
 *          AdciStop()
 *
 * @brief   The function stops the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to ADCIM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AdciStop
(
    AdciHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the current configuration.
 *
 * @param   handle      ADCI instance handle
 * @param   pConfig     reference of configuration structure to be filled with
 *                      the current configuration
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT AdciGetCurrentConfig
(
    AdciHandle_t handle,
    AdciConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AdciStatus()
 *
 * @brief   The function returns the status of the Auto wide dynamic range v3
 *          module
 *
 * @param   handle  Handle to ADCIM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AdciStatus
(
    AdciHandle_t 		handle,
    bool_t       		*pRunning,
    AdciMode_t			*pMode,
    AdciParamNode_t 	*pCurrentParam
);



/*****************************************************************************/
/**
 *          AdciProcessFrame()
 *
 * @brief   The function calculates and adjusts a new WDR4-setup regarding
 *          the current sensor-gain
 *
 * @param   handle  Handle to ADCIM
 *          gain    current sensor-gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AdciProcessFrame
(
    AdciHandle_t    	handle,
    const float			fGain,
    const float			fIntegrationTime
);



#ifdef __cplusplus
}
#endif


/* @} ADCI */


#endif /* __ADCI_H__*/
