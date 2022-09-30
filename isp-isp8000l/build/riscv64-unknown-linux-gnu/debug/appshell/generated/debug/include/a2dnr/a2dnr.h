/******************************************************************************
 *
 * Copyright 2020, Verisilicon. All rights reserved.
 *
 *****************************************************************************/

#ifndef __A2DNR_H__
#define __A2DNR_H__

/**
 * @file a2dnr.h
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
 * @defgroup A2DNR Auto 2D Noise Reduction module
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
typedef enum A2dnrRunMode_e
{
    A2DNR_MODE_INVALID                    = 0,        /**< initialization value */
    A2DNR_MODE_MANUAL                     = 1,        /**< run manual 2d noise reduction */
    A2DNR_MODE_AUTO                       = 2,        /**< run auto 2d noise reduction */
    A2DNR_MODE_MAX
} A2dnrMode_t;



/*****************************************************************************/
/**
 *          A2dnrHandle_t
 *
 * @brief   A2DNR Module instance handle
 *
 *****************************************************************************/
typedef struct A2dnrContext_s *A2dnrHandle_t;         /**< handle to A2DNR context */



/*****************************************************************************/
/**
 *          A2dnrInstanceConfig_t
 *
 * @brief   A2DNR Module instance configuration structure
 *
 *****************************************************************************/
typedef struct A2dnrInstanceConfig_s
{
    CamerIcDrvHandle_t      hCamerIc;           /**< handle to cameric driver */
    CamerIcDrvHandle_t      hSubCamerIc;        /**< handle to 2nd cameric drivder (3D) */

    A2dnrHandle_t           hA2dnr;            	/**< handle returned by A2dnrInit() */
} A2dnrInstanceConfig_t;



/*****************************************************************************/
/**
 *          A2dnrConfig_t
 *
 * @brief   A2DNR Module configuration structure
 *
 *****************************************************************************/
typedef struct A2dnrConfig_s
{
    float                 sigma;       	      /**< sigma */
    uint8_t               strength;  		  /**< strength */
    uint8_t               pregmaStrength;     /**< pregmaStrength */
} A2dnrConfig_t;



/*****************************************************************************/
/**
 *          A2dnrParamNode_t
 *
 * @brief   A2DNR parameters node structure
 *
 *****************************************************************************/
typedef struct A2dnrParamNode_s
{
	float					gain;				/**< gain */
	float					integrationTime;	/**< integrationTime */
    float                 	sigma;       	    /**< sigma */
    uint8_t               	strength;  		  	/**< strength */
    uint8_t               	pregmaStrength;     /**< pregmaStrength */
} A2dnrParamNode_t;



/*****************************************************************************/
/**
 *          A2dnrParamTable_t
 *
 * @brief   A2DNR Module parameters table structure
 *
 *****************************************************************************/
typedef struct A2dnrParamTable_s
{
    uint8_t               nodeNum;  			/**< nodeNum */
    A2dnrParamNode_t      *pNodeList;			/**< point of Node List  */
} A2dnrParamTable_t;



/*****************************************************************************/
/**
 *          A2dnrInit()
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
RESULT A2dnrInit
(
    A2dnrInstanceConfig_t *pInstConfig
);



/*****************************************************************************/
/**
 *          A2dnrRelease()
 *
 * @brief   The function releases/frees the Auto 2d noise reduction module
 *
 * @param   handle  Handle to A2DNRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A2dnrRelease
(
    A2dnrHandle_t handle
);



/*****************************************************************************/
/**
 *          A2dnrConfigure()
 *
 * @brief   This function configures the Auto 2d noise reduction module
 *
 * @param   handle  Handle to A2DNRM
 * @param   pConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT A2dnrConfigure
(
    A2dnrHandle_t handle,
    A2dnrConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          A2dnrReConfigure()
 *
 * @brief   This function re-configures the Auto 2d noise reduction Module
 *          after e.g. resolution change
 *
 * @param   handle  Handle to A2DNRM
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT A2dnrReConfigure
(
    A2dnrHandle_t handle,
    A2dnrConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          A2dnrSetAutoLevel()
 *
 * @brief   This function set auto mode level
 *
 * @param   handle  Handle to A2DNRM
 * @param   level
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT A2dnrSetAutoLevel
(
    A2dnrHandle_t handle,
    const uint8_t level
);



/*****************************************************************************/
/**
 *          A2dnrSetAutoParamTable()
 *
 * @brief   This function set auto mode parameters table
 *
 * @param   handle  Handle to A2DNRM
 * @param   pParamTable
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT A2dnrSetAutoParamTable
(
    A2dnrHandle_t handle,
    A2dnrParamTable_t *pParamTable
);



/*****************************************************************************/
/**
 *          A2dnrStart()
 *
 * @brief   The function starts the Auto 2d noise reduction module
 *
 * @param   handle  Handle to A2DNRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A2dnrStart
(
    A2dnrHandle_t 		handle,
    const A2dnrMode_t	mode
);



/*****************************************************************************/
/**
 *          A2dnrStop()
 *
 * @brief   The function stops the Auto 2d noise reduction module
 *
 * @param   handle  Handle to A2DNRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A2dnrStop
(
    A2dnrHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the current configuration.
 *
 * @param   handle      A2DNR instance handle
 * @param   pConfig     reference of configuration structure to be filled with
 *                      the current configuration
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT A2dnrGetCurrentConfig
(
    A2dnrHandle_t handle,
    A2dnrConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          A2dnrStatus()
 *
 * @brief   The function returns the status of the Auto 2d noise reduction
 *          module
 *
 * @param   handle  Handle to A2DNRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A2dnrStatus
(
    A2dnrHandle_t 		handle,
    bool_t       		*pRunning,
    A2dnrMode_t			*pMode,
    A2dnrParamNode_t 	*pCurrentParam
);



/*****************************************************************************/
/**
 *          A2dnrProcessFrame()
 *
 * @brief   The function calculates and adjusts a new 2DNR-setup regarding
 *          the current sensor-gain
 *
 * @param   handle  Handle to A2DNRM
 *          gain    current sensor-gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A2dnrProcessFrame
(
    A2dnrHandle_t	handle,
    const float		fGain,
    const float		fIntegrationTime
);



#ifdef __cplusplus
}
#endif


/* @} A2DNR */


#endif /* __A2DNR_H__*/
