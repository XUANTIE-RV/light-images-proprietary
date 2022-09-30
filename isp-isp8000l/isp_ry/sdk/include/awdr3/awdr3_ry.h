/******************************************************************************
 *
 * Copyright 2020, Verisilicon. All rights reserved.
 *
 *****************************************************************************/

#ifndef __AWDR3_H__
#define __AWDR3_H__

/**
 * @file awdr3.h
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
 * @defgroup AWDR3 Auto Wide Dynamic Range v3 module
 * @{
 *
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#include <isi/isi_iss_ry.h>
#include <isi/isi_ry.h>



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
typedef enum Awdr3RunMode_e
{
    AWDR3_MODE_INVALID                    = 0,        /**< initialization value */
    AWDR3_MODE_MANUAL                     = 1,        /**< run manual wide dynamic range(V3) */
    AWDR3_MODE_AUTO                       = 2,        /**< run auto wide dynamic range(V3) */
    AWDR3_MODE_MAX
} Awdr3Mode_t;



/*****************************************************************************/
/**
 *          Awdr3Handle_t
 *
 * @brief   AWDR3 Module instance handle
 *
 *****************************************************************************/
typedef struct Awdr3Context_s *Awdr3Handle_t;         /**< handle to AWDR3 context */



/*****************************************************************************/
/**
 *          Awdr3InstanceConfig_t
 *
 * @brief   AWDR3 Module instance configuration structure
 *
 *****************************************************************************/
typedef struct Awdr3InstanceConfig_s
{
    CamerIcDrvHandle_ry_t      hCamerIc;           /**< handle to cameric driver */
    CamerIcDrvHandle_ry_t      hSubCamerIc;        /**< handle to 2nd cameric drivder (3D) */

    Awdr3Handle_t            hAwdr3;            /**< handle returned by Awdr3Init() */
} Awdr3InstanceConfig_t;



/*****************************************************************************/
/**
 *          Awdr3Config_t
 *
 * @brief   AWDR3 Module configuration structure
 *
 *****************************************************************************/
typedef struct Awdr3Config_s
{
    uint8_t				strength;			/**< strength */
    uint8_t				globalStrength;		/**< globalStrength */
    uint8_t				maxGain;			/**< maxGain */
} Awdr3Config_t;



/*****************************************************************************/
/**
 *          Awdr3ParamNode_t
 *
 * @brief   AWDR3 parameters node structure
 *
 *****************************************************************************/
typedef struct Awdr3ParamNode_s
{
	float					gain;				/**< gain */
	float					integrationTime;	/**< integrationTime */
    uint8_t					strength;			/**< strength */
    uint8_t					globalStrength;		/**< globalStrength */
    uint8_t					maxGain;			/**< maxGain */
} Awdr3ParamNode_t;



/*****************************************************************************/
/**
 *          Awdr3ParamTable_t
 *
 * @brief   AWDR3 Module parameters table structure
 *
 *****************************************************************************/
typedef struct Awdr3ParamTable_s
{
    uint8_t					nodeNum;  			/**< nodeNum */
    Awdr3ParamNode_t		*pNodeList;			/**< point of Node List  */
} Awdr3ParamTable_t;



/*****************************************************************************/
/**
 *          Awdr3Init()
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
RESULT Awdr3Init
(
    Awdr3InstanceConfig_t *pInstConfig
);



/*****************************************************************************/
/**
 *          Awdr3Release()
 *
 * @brief   The function releases/frees the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to AWDR3M
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT Awdr3Release
(
    Awdr3Handle_t handle
);



/*****************************************************************************/
/**
 *          Awdr3Configure()
 *
 * @brief   This function configures the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to AWDR3M
 * @param   pConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT Awdr3Configure
(
    Awdr3Handle_t handle,
    Awdr3Config_t *pConfig
);



/*****************************************************************************/
/**
 *          Awdr3ReConfigure()
 *
 * @brief   This function re-configures the Auto wide dynamic range v3 Module
 *          after e.g. resolution change
 *
 * @param   handle  Handle to AWDR3M
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT Awdr3ReConfigure
(
    Awdr3Handle_t handle,
    Awdr3Config_t *pConfig
);



/*****************************************************************************/
/**
 *          Awdr3SetAutoLevel()
 *
 * @brief   This function set auto mode level
 *
 * @param   handle  Handle to AWDR3M
 * @param   level
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT Awdr3SetAutoLevel
(
    Awdr3Handle_t handle,
    const uint8_t level
);



/*****************************************************************************/
/**
 *          Awdr3SetAutoParamTable()
 *
 * @brief   This function set auto mode parameters table
 *
 * @param   handle  Handle to AWDR3M
 * @param   pParamTable
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT Awdr3SetAutoParamTable
(
    Awdr3Handle_t handle,
    Awdr3ParamTable_t *pParamTable
);



/*****************************************************************************/
/**
 *          Awdr3Start()
 *
 * @brief   The function starts the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to AWDR3M
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT Awdr3Start
(
    Awdr3Handle_t 		handle,
    const Awdr3Mode_t	mode
);



/*****************************************************************************/
/**
 *          Awdr3Stop()
 *
 * @brief   The function stops the Auto wide dynamic range v3 module
 *
 * @param   handle  Handle to AWDR3M
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT Awdr3Stop
(
    Awdr3Handle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the current configuration.
 *
 * @param   handle      AWDR3 instance handle
 * @param   pConfig     reference of configuration structure to be filled with
 *                      the current configuration
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT Awdr3GetCurrentConfig
(
    Awdr3Handle_t handle,
    Awdr3Config_t *pConfig
);



/*****************************************************************************/
/**
 *          Awdr3Status()
 *
 * @brief   The function returns the status of the Auto wide dynamic range v3
 *          module
 *
 * @param   handle  Handle to AWDR3M
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT Awdr3Status
(
    Awdr3Handle_t 		handle,
    bool_t       		*pRunning,
    Awdr3Mode_t			*pMode,
    Awdr3ParamNode_t 	*pCurrentParam
);



/*****************************************************************************/
/**
 *          Awdr3ProcessFrame()
 *
 * @brief   The function calculates and adjusts a new WDR3-setup regarding
 *          the current sensor-gain
 *
 * @param   handle  Handle to AWDR3M
 *          gain    current sensor-gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT Awdr3ProcessFrame
(
    Awdr3Handle_t    	handle,
    const float			fGain,
    const float			fIntegrationTime
);



#ifdef __cplusplus
}
#endif


/* @} AWDR3 */


#endif /* __AWDR3_H__*/
