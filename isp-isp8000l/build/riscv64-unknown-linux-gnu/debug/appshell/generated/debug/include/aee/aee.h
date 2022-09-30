/******************************************************************************
 *
 * Copyright 2020, Verisilicon. All rights reserved.
 *
 *****************************************************************************/

#ifndef __AEE_H__
#define __AEE_H__

/**
 * @file aee.h
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
 * @defgroup AEE Auto Edge Enhancement module
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
typedef enum AeeRunMode_e
{
    AEE_MODE_INVALID                    = 0,        /**< initialization value */
    AEE_MODE_MANUAL                     = 1,        /**< run manual edge enhancement */
    AEE_MODE_AUTO                       = 2,        /**< run auto edge enhancement */
    AEE_MODE_MAX
} AeeMode_t;



/*****************************************************************************/
/**
 *          AeeHandle_t
 *
 * @brief   AEE Module instance handle
 *
 *****************************************************************************/
typedef struct AeeContext_s *AeeHandle_t;         /**< handle to AEE context */



/*****************************************************************************/
/**
 *          AeeInstanceConfig_t
 *
 * @brief   AEE Module instance configuration structure
 *
 *****************************************************************************/
typedef struct AeeInstanceConfig_s
{
    CamerIcDrvHandle_t      hCamerIc;           /**< handle to cameric driver */
    CamerIcDrvHandle_t      hSubCamerIc;        /**< handle to 2nd cameric drivder (3D) */

    AeeHandle_t            	hAee;            /**< handle returned by AeeInit() */
} AeeInstanceConfig_t;



/*****************************************************************************/
/**
 *          AeeConfig_t
 *
 * @brief   AEE Module configuration structure
 *
 *****************************************************************************/
typedef struct AeeConfig_s
{
    uint8_t				strength;		/**< strength */
	uint16_t			yUpGain;		/**< yUpGain */
	uint16_t			yDownGain;		/**< yDownGain */
	uint16_t			uvGain;			/**< uvGain */
	uint16_t			edgeGain;		/**< edgeGain */
} AeeConfig_t;



/*****************************************************************************/
/**
 *          AeeParamNode_t
 *
 * @brief   AEE parameters node structure
 *
 *****************************************************************************/
typedef struct AeeParamNode_s
{
	float				gain;				/**< gain */
	float				integrationTime;	/**< integrationTime */
    uint8_t				strength;			/**< strength */
	uint16_t			yUpGain;			/**< yUpGain */
	uint16_t			yDownGain;			/**< yDownGain */
	uint16_t			uvGain;				/**< uvGain */
	uint16_t			edgeGain;			/**< edgeGain */
} AeeParamNode_t;



/*****************************************************************************/
/**
 *          AeeParamTable_t
 *
 * @brief   AEE Module parameters table structure
 *
 *****************************************************************************/
typedef struct AeeParamTable_s
{
    uint8_t				nodeNum;  			/**< nodeNum */
    AeeParamNode_t      *pNodeList;			/**< point of Node List  */
} AeeParamTable_t;



/*****************************************************************************/
/**
 *          AeeInit()
 *
 * @brief   This function initializes the Auto 3d noise reduction module
 *
 * @param   pInstConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_INVALID_PARM
 * @retval  RET_OUTOFMEM
 *
 *****************************************************************************/
RESULT AeeInit
(
    AeeInstanceConfig_t *pInstConfig
);



/*****************************************************************************/
/**
 *          AeeRelease()
 *
 * @brief   The function releases/frees the Auto 3d noise reduction module
 *
 * @param   handle  Handle to AEEM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AeeRelease
(
    AeeHandle_t handle
);



/*****************************************************************************/
/**
 *          AeeConfigure()
 *
 * @brief   This function configures the Auto 3d noise reduction module
 *
 * @param   handle  Handle to AEEM
 * @param   pConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AeeConfigure
(
    AeeHandle_t handle,
    AeeConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AeeReConfigure()
 *
 * @brief   This function re-configures the Auto 3d noise reduction Module
 *          after e.g. resolution change
 *
 * @param   handle  Handle to AEEM
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AeeReConfigure
(
    AeeHandle_t handle,
    AeeConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AeeSetAutoParamTable()
 *
 * @brief   This function set auto mode parameters table
 *
 * @param   handle  Handle to AEEM
 * @param   pParamTable
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AeeSetAutoParamTable
(
    AeeHandle_t handle,
    AeeParamTable_t *pParamTable
);



/*****************************************************************************/
/**
 *          AeeStart()
 *
 * @brief   The function starts the Auto 3d noise reduction module
 *
 * @param   handle  Handle to AEEM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AeeStart
(
    AeeHandle_t 		handle,
    const AeeMode_t		mode
);



/*****************************************************************************/
/**
 *          AeeStop()
 *
 * @brief   The function stops the Auto 3d noise reduction module
 *
 * @param   handle  Handle to AEEM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AeeStop
(
    AeeHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the current configuration.
 *
 * @param   handle      AEE instance handle
 * @param   pConfig     reference of configuration structure to be filled with
 *                      the current configuration
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT AeeGetCurrentConfig
(
    AeeHandle_t handle,
    AeeConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AeeStatus()
 *
 * @brief   The function returns the status of the Auto 3d noise reduction
 *          module
 *
 * @param   handle  Handle to AEEM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AeeStatus
(
    AeeHandle_t 	handle,
    bool_t       	*pRunning,
    AeeMode_t		*pMode,
    AeeParamNode_t 	*pCurrentParam
);



/*****************************************************************************/
/**
 *          AeeProcessFrame()
 *
 * @brief   The function calculates and adjusts a new EE-setup regarding
 *          the current sensor-gain
 *
 * @param   handle  Handle to AEEM
 *          gain    current sensor-gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AeeProcessFrame
(
    AeeHandle_t    		handle,
    const float			fGain,
    const float			fIntegrationTime
);



#ifdef __cplusplus
}
#endif


/* @} AEE */


#endif /* __AEE_H__*/
