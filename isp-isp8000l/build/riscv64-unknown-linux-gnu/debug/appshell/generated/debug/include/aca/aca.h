/******************************************************************************
 *
 * Copyright 2020, Verisilicon. All rights reserved.
 *
 *****************************************************************************/

#ifndef __ACA_H__
#define __ACA_H__

/**
 * @file aca.h
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
 * @defgroup ACA Auto Color Adjust module
 * @{
 *
 */
#include <ebase/types.h>
#include <common/return_codes.h>

#include <isi/isi_iss.h>
#include <isi/isi.h>



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
typedef enum AcaRunMode_e
{
    ACA_MODE_INVALID                    = 0,        /**< initialization value */
    ACA_MODE_MANUAL                     = 1,        /**< run manual wide dynamic range(V3) */
    ACA_MODE_AUTO                       = 2,        /**< run auto wide dynamic range(V3) */
    ACA_MODE_MAX
} AcaMode_t;



/*****************************************************************************/
/**
 *          AcaHandle_t
 *
 * @brief   ACA Module instance handle
 *
 *****************************************************************************/
typedef struct AcaContext_s *AcaHandle_t;         /**< handle to ACA context */



/*****************************************************************************/
/**
 *          AcaInstanceConfig_t
 *
 * @brief   ACA Module instance configuration structure
 *
 *****************************************************************************/
typedef struct AcaInstanceConfig_s
{
    CamerIcDrvHandle_t      hCamerIc;           /**< handle to cameric driver */
    CamerIcDrvHandle_t      hSubCamerIc;        /**< handle to 2nd cameric drivder (3D) */

    AcaHandle_t            hAca;            /**< handle returned by AcaInit() */
} AcaInstanceConfig_t;



/*****************************************************************************/
/**
 *          AcaConfig_t
 *
 * @brief   ACA Module configuration structure
 *
 *****************************************************************************/
typedef struct AcaConfig_s
{
    uint8_t				strength;			/**< strength */
    uint8_t				globalStrength;		/**< globalStrength */
    uint8_t				maxGain;			/**< maxGain */
    int mode;
	int curveType;
	uint8_t sCurveInflection;
	uint8_t sCurveExponent;
	float parabolicFactor;
} AcaConfig_t;



/*****************************************************************************/
/**
 *          AcaParamNode_t
 *
 * @brief   ACA parameters node structure
 *
 *****************************************************************************/
typedef struct AcaParamNode_s
{
	float					gain;				/**< gain */
	float					integrationTime;	/**< integrationTime */
    uint8_t					strength;			/**< strength */
    uint8_t					globalStrength;		/**< globalStrength */
    uint8_t					maxGain;			/**< maxGain */
    uint8_t sCurveInflection;
	uint8_t sCurveExponent;
	float parabolicFactor;
} AcaParamNode_t;



/*****************************************************************************/
/**
 *          AcaParamTable_t
 *
 * @brief   ACA Module parameters table structure
 *
 *****************************************************************************/
typedef struct AcaParamTable_s
{
    uint8_t					nodeNum;  			/**< nodeNum */
    AcaParamNode_t		*pNodeList;			/**< point of Node List  */
} AcaParamTable_t;



/*****************************************************************************/
/**
 *          AcaInit()
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
RESULT AcaInit
(
    AcaInstanceConfig_t *pInstConfig
);



/*****************************************************************************/
/**
 *          AcaRelease()
 *
 * @brief   The function releases/frees the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to ACAM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AcaRelease
(
    AcaHandle_t handle
);



/*****************************************************************************/
/**
 *          AcaConfigure()
 *
 * @brief   This function configures the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to ACAM
 * @param   pConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AcaConfigure
(
    AcaHandle_t handle,
    AcaConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AcaReConfigure()
 *
 * @brief   This function re-configures the Auto wide dynamic range v3 Module
 *          after e.g. resolution change
 *
 * @param   handle  Handle to ACAM
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AcaReConfigure
(
    AcaHandle_t handle,
    AcaConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AcaSetAutoParamTable()
 *
 * @brief   This function set auto mode parameters table
 *
 * @param   handle  Handle to ACAM
 * @param   pParamTable
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AcaSetAutoParamTable
(
    AcaHandle_t handle,
    AcaParamTable_t *pParamTable
);



/*****************************************************************************/
/**
 *          AcaStart()
 *
 * @brief   The function starts the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to ACAM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AcaStart
(
    AcaHandle_t 		handle,
    const AcaMode_t	mode
);



/*****************************************************************************/
/**
 *          AcaStop()
 *
 * @brief   The function stops the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to ACAM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AcaStop
(
    AcaHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the current configuration.
 *
 * @param   handle      ACA instance handle
 * @param   pConfig     reference of configuration structure to be filled with
 *                      the current configuration
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT AcaGetCurrentConfig
(
    AcaHandle_t handle,
    AcaConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AcaStatus()
 *
 * @brief   The function returns the status of the Auto wide dynamic range v3
 *          module
 *
 * @param   handle  Handle to ACAM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AcaStatus
(
    AcaHandle_t 		handle,
    bool_t       		*pRunning,
    AcaMode_t			*pMode,
    AcaParamNode_t 	*pCurrentParam
);



/*****************************************************************************/
/**
 *          AcaProcessFrame()
 *
 * @brief   The function calculates and adjusts a new WDR4-setup regarding
 *          the current sensor-gain
 *
 * @param   handle  Handle to ACAM
 *          gain    current sensor-gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AcaProcessFrame
(
    AcaHandle_t    	handle,
    const float			fGain,
    const float			fIntegrationTime
);



#ifdef __cplusplus
}
#endif


/* @} ACA */


#endif /* __ACA_H__*/
