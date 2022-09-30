/******************************************************************************
 *
 * Copyright 2020, Verisilicon. All rights reserved.
 *
 *****************************************************************************/

#ifndef __AWDR4_H__
#define __AWDR4_H__

/**
 * @file awdr4.h
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
 * @defgroup AWDR4 Auto Wide Dynamic Range v4 module
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
typedef enum Awdr4RunMode_e
{
    AWDR4_MODE_INVALID                    = 0,        /**< initialization value */
    AWDR4_MODE_MANUAL                     = 1,        /**< run manual wide dynamic range(V3) */
    AWDR4_MODE_AUTO                       = 2,        /**< run auto wide dynamic range(V3) */
    AWDR4_MODE_MAX
} Awdr4Mode_t;



/*****************************************************************************/
/**
 *          Awdr4Handle_t
 *
 * @brief   AWDR4 Module instance handle
 *
 *****************************************************************************/
typedef struct Awdr4Context_s *Awdr4Handle_t;         /**< handle to AWDR4 context */



/*****************************************************************************/
/**
 *          Awdr4InstanceConfig_t
 *
 * @brief   AWDR4 Module instance configuration structure
 *
 *****************************************************************************/
typedef struct Awdr4InstanceConfig_s
{
    CamerIcDrvHandle_t      hCamerIc;           /**< handle to cameric driver */
    CamerIcDrvHandle_t      hSubCamerIc;        /**< handle to 2nd cameric drivder (3D) */

    Awdr4Handle_t            hAwdr4;            /**< handle returned by Awdr4Init() */
} Awdr4InstanceConfig_t;



/*****************************************************************************/
/**
 *          Awdr4Config_t
 *
 * @brief   AWDR4 Module configuration structure
 *
 *****************************************************************************/
typedef struct Awdr4Config_s
{
    uint8_t				strength;			/**< strength */
    uint8_t				globalStrength;		/**< globalStrength */
    uint8_t				maxGain;			/**< maxGain */
} Awdr4Config_t;



/*****************************************************************************/
/**
 *          Awdr4ParamNode_t
 *
 * @brief   AWDR4 parameters node structure
 *
 *****************************************************************************/
typedef struct Awdr4ParamNode_s
{
	float					gain;				/**< gain */
	float					integrationTime;	/**< integrationTime */
    uint8_t					strength;			/**< strength */
    uint8_t					globalStrength;		/**< globalStrength */
    uint8_t					maxGain;			/**< maxGain */
} Awdr4ParamNode_t;



/*****************************************************************************/
/**
 *          Awdr4ParamTable_t
 *
 * @brief   AWDR4 Module parameters table structure
 *
 *****************************************************************************/
typedef struct Awdr4ParamTable_s
{
    uint8_t					nodeNum;  			/**< nodeNum */
    Awdr4ParamNode_t		*pNodeList;			/**< point of Node List  */
} Awdr4ParamTable_t;



/*****************************************************************************/
/**
 *          Awdr4Init()
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
RESULT Awdr4Init
(
    Awdr4InstanceConfig_t *pInstConfig
);



/*****************************************************************************/
/**
 *          Awdr4Release()
 *
 * @brief   The function releases/frees the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to AWDR4M
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT Awdr4Release
(
    Awdr4Handle_t handle
);



/*****************************************************************************/
/**
 *          Awdr4Configure()
 *
 * @brief   This function configures the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to AWDR4M
 * @param   pConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT Awdr4Configure
(
    Awdr4Handle_t handle,
    Awdr4Config_t *pConfig
);



/*****************************************************************************/
/**
 *          Awdr4ReConfigure()
 *
 * @brief   This function re-configures the Auto wide dynamic range v3 Module
 *          after e.g. resolution change
 *
 * @param   handle  Handle to AWDR4M
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT Awdr4ReConfigure
(
    Awdr4Handle_t handle,
    Awdr4Config_t *pConfig
);



/*****************************************************************************/
/**
 *          Awdr4SetAutoParamTable()
 *
 * @brief   This function set auto mode parameters table
 *
 * @param   handle  Handle to AWDR4M
 * @param   pParamTable
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT Awdr4SetAutoParamTable
(
    Awdr4Handle_t handle,
    Awdr4ParamTable_t *pParamTable
);



/*****************************************************************************/
/**
 *          Awdr4Start()
 *
 * @brief   The function starts the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to AWDR4M
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT Awdr4Start
(
    Awdr4Handle_t 		handle,
    const Awdr4Mode_t	mode
);



/*****************************************************************************/
/**
 *          Awdr4Stop()
 *
 * @brief   The function stops the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to AWDR4M
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT Awdr4Stop
(
    Awdr4Handle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the current configuration.
 *
 * @param   handle      AWDR4 instance handle
 * @param   pConfig     reference of configuration structure to be filled with
 *                      the current configuration
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT Awdr4GetCurrentConfig
(
    Awdr4Handle_t handle,
    Awdr4Config_t *pConfig
);



/*****************************************************************************/
/**
 *          Awdr4Status()
 *
 * @brief   The function returns the status of the Auto wide dynamic range v3
 *          module
 *
 * @param   handle  Handle to AWDR4M
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT Awdr4Status
(
    Awdr4Handle_t 		handle,
    bool_t       		*pRunning,
    Awdr4Mode_t			*pMode,
    Awdr4ParamNode_t 	*pCurrentParam
);



/*****************************************************************************/
/**
 *          Awdr4ProcessFrame()
 *
 * @brief   The function calculates and adjusts a new WDR4-setup regarding
 *          the current sensor-gain
 *
 * @param   handle  Handle to AWDR4M
 *          gain    current sensor-gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT Awdr4ProcessFrame
(
    Awdr4Handle_t    	handle,
    const float			fGain,
    const float			fIntegrationTime
);



#ifdef __cplusplus
}
#endif


/* @} AWDR4 */


#endif /* __AWDR4_H__*/
