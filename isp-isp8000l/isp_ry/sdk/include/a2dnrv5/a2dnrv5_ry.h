/******************************************************************************
 *
 * Copyright 2020, Verisilicon. All rights reserved.
 *
 *****************************************************************************/

#ifndef __A2DNRV5_H__
#define __A2DNRV5_H__

/**
 * @file a2dnrv5.h
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
 * @defgroup A2DNRV5 Auto 2D Version5 Noise Reduction module
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
typedef enum A2dnrV5RunMode_e
{
    A2DNRV5_MODE_INVALID                    = 0,        /**< initialization value */
    A2DNRV5_MODE_MANUAL                     = 1,        /**< run manual 2d noise reduction */
    A2DNRV5_MODE_AUTO                       = 2,        /**< run auto 2d noise reduction */
    A2DNRV5_MODE_MAX
} A2dnrV5Mode_t;



/*****************************************************************************/
/**
 *          A2dnrV5Handle_t
 *
 * @brief   A2DNRV5 Module instance handle
 *
 *****************************************************************************/
typedef struct A2dnrV5Context_s *A2dnrV5Handle_t;         /**< handle to A2DNRV5 context */



/*****************************************************************************/
/**
 *          A2dnrV5InstanceConfig_t
 *
 * @brief   A2DNRV5 Module instance configuration structure
 *
 *****************************************************************************/
typedef struct A2dnrV5InstanceConfig_s
{
    CamerIcDrvHandle_ry_t      hCamerIc;           /**< handle to cameric driver */
    CamerIcDrvHandle_ry_t      hSubCamerIc;        /**< handle to 2nd cameric drivder (3D) */

    A2dnrV5Handle_t         hA2dnrV5;            /**< handle returned by A2dnrV5Init() */
} A2dnrV5InstanceConfig_t;



/*****************************************************************************/
/**
 *          A2dnrV5Config_t
 *
 * @brief   A2DNRV5 Module configuration structure
 *
 *****************************************************************************/
typedef struct A2dnrV5Config_s
{
	float 				strength;
	float 				sigma;
	uint8_t				blendingOpacityStaticArea;
	uint8_t				blendingOpacityMovingArea;
} A2dnrV5Config_t;



/*****************************************************************************/
/**
 *          A2dnrV5ParamNode_t
 *
 * @brief   A2DNRV5 parameters node structure
 *
 *****************************************************************************/
typedef struct A2dnrV5ParamNode_s
{
	float					gain;				/**< gain */
	float					integrationTime;	/**< integrationTime */
	float 					strength;
	float 					sigma;
	uint8_t					blendingOpacityStaticArea;
	uint8_t					blendingOpacityMovingArea;
} A2dnrV5ParamNode_t;



/*****************************************************************************/
/**
 *          A2dnrV5ParamTable_t
 *
 * @brief   A2DNRV5 Module parameters table structure
 *
 *****************************************************************************/
typedef struct A2dnrV5ParamTable_s
{
    uint8_t               nodeNum;  			/**< nodeNum */
    A2dnrV5ParamNode_t    *pNodeList;			/**< point of Node List  */
} A2dnrV5ParamTable_t;



/*****************************************************************************/
/**
 *          A2dnrV5Init()
 *
 * @brief   This function initializes the Auto 2d noise reduction module
 *
 * @param   pInstConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_INVALID_PARM
 * @retval  RET_OUTOFMEM
 *
 *****************************************************************************/
RESULT A2dnrV5Init
(
    A2dnrV5InstanceConfig_t *pInstConfig
);



/*****************************************************************************/
/**
 *          A2dnrV5Release()
 *
 * @brief   The function releases/frees the Auto 2d noise reduction module
 *
 * @param   handle  Handle to A2DNRV5M
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A2dnrV5Release
(
    A2dnrV5Handle_t handle
);



/*****************************************************************************/
/**
 *          A2dnrV5Configure()
 *
 * @brief   This function configures the Auto 2d noise reduction module
 *
 * @param   handle  Handle to A2DNRV5M
 * @param   pConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT A2dnrV5Configure
(
    A2dnrV5Handle_t handle,
    A2dnrV5Config_t *pConfig
);



/*****************************************************************************/
/**
 *          A2dnrV5ReConfigure()
 *
 * @brief   This function re-configures the Auto 2d noise reduction Module
 *          after e.g. resolution change
 *
 * @param   handle  Handle to A2DNRV5M
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT A2dnrV5ReConfigure
(
    A2dnrV5Handle_t handle,
    A2dnrV5Config_t *pConfig
);



/*****************************************************************************/
/**
 *          A2dnrV5SetAutoParamTable()
 *
 * @brief   This function set auto mode parameters table
 *
 * @param   handle  Handle to A2DNRV5M
 * @param   pParamTable
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT A2dnrV5SetAutoParamTable
(
    A2dnrV5Handle_t handle,
    A2dnrV5ParamTable_t *pParamTable
);



/*****************************************************************************/
/**
 *          A2dnrV5Start()
 *
 * @brief   The function starts the Auto 2d noise reduction module
 *
 * @param   handle  Handle to A2DNRV5M
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A2dnrV5Start
(
    A2dnrV5Handle_t 		handle,
    const A2dnrV5Mode_t		mode
);



/*****************************************************************************/
/**
 *          A2dnrV5Stop()
 *
 * @brief   The function stops the Auto 2d noise reduction module
 *
 * @param   handle  Handle to A2DNRV5M
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A2dnrV5Stop
(
    A2dnrV5Handle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the current configuration.
 *
 * @param   handle      A2DNRV5 instance handle
 * @param   pConfig     reference of configuration structure to be filled with
 *                      the current configuration
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT A2dnrV5GetCurrentConfig
(
    A2dnrV5Handle_t handle,
    A2dnrV5Config_t *pConfig
);



/*****************************************************************************/
/**
 *          A2dnrV5Status()
 *
 * @brief   The function returns the status of the Auto 2d noise reduction
 *          module
 *
 * @param   handle  Handle to A2DNRV5M
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A2dnrV5Status
(
    A2dnrV5Handle_t 	handle,
    bool_t       		*pRunning,
    A2dnrV5Mode_t		*pMode,
    A2dnrV5ParamNode_t 	*pCurrentParam
);



/*****************************************************************************/
/**
 *          A2dnrV5ProcessFrame()
 *
 * @brief   The function calculates and adjusts a new 2DNRV5-setup regarding
 *          the current sensor-gain
 *
 * @param   handle  Handle to A2DNRV5M
 *          gain    current sensor-gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A2dnrV5ProcessFrame
(
    A2dnrV5Handle_t	handle,
    const float		fGain,
    const float		fIntegrationTime
);



#ifdef __cplusplus
}
#endif


/* @} A2DNRV5 */


#endif /* __A2DNRV5_H__*/
