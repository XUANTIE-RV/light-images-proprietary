/******************************************************************************
 *
 * Copyright 2020, Verisilicon. All rights reserved.
 *
 *****************************************************************************/

#ifndef __A3DNR_H__
#define __A3DNR_H__

/**
 * @file a3dnr.h
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
 * @defgroup A3DNR Auto 3D Noise Reduction module
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
typedef enum A3dnrRunMode_e
{
    A3DNR_MODE_INVALID                    = 0,        /**< initialization value */
    A3DNR_MODE_MANUAL                     = 1,        /**< run manual 3d noise reduction */
    A3DNR_MODE_AUTO                       = 2,        /**< run auto 3d noise reduction */
    A3DNR_MODE_MAX
} A3dnrMode_t;



/*****************************************************************************/
/**
 *          A3dnrHandle_t
 *
 * @brief   A3DNR Module instance handle
 *
 *****************************************************************************/
typedef struct A3dnrContext_s *A3dnrHandle_t;         /**< handle to A3DNR context */



/*****************************************************************************/
/**
 *          A3dnrInstanceConfig_t
 *
 * @brief   A3DNR Module instance configuration structure
 *
 *****************************************************************************/
typedef struct A3dnrInstanceConfig_s
{
    CamerIcDrvHandle_ry_t      hCamerIc;           /**< handle to cameric driver */
    CamerIcDrvHandle_ry_t      hSubCamerIc;        /**< handle to 2nd cameric drivder (3D) */

    A3dnrHandle_t            hA3dnr;            /**< handle returned by A3dnrInit() */
} A3dnrInstanceConfig_t;



/*****************************************************************************/
/**
 *          A3dnrConfig_t
 *
 * @brief   A3DNR Module configuration structure
 *
 *****************************************************************************/
typedef struct A3dnrConfig_s
{
    uint8_t               strength;			/**< strength */
    uint16_t              motionFactor;		/**< motionFactor */
    uint16_t              deltaFactor;		/**< deltaFactor */
} A3dnrConfig_t;



/*****************************************************************************/
/**
 *          A3dnrParamNode_t
 *
 * @brief   A3DNR parameters node structure
 *
 *****************************************************************************/
typedef struct A3dnrParamNode_s
{
	float					gain;				/**< gain */
	float					integrationTime;	/**< integrationTime */
    uint8_t               	strength;			/**< strength */
    uint16_t             	motionFactor;		/**< motionFactor */
    uint16_t              	deltaFactor;		/**< deltaFactor */
} A3dnrParamNode_t;



/*****************************************************************************/
/**
 *          A3dnrParamTable_t
 *
 * @brief   A3DNR Module parameters table structure
 *
 *****************************************************************************/
typedef struct A3dnrParamTable_s
{
    uint8_t               nodeNum;  			/**< nodeNum */
    A3dnrParamNode_t      *pNodeList;			/**< point of Node List  */
} A3dnrParamTable_t;



/*****************************************************************************/
/**
 *          A3dnrInit()
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
RESULT A3dnrInit
(
    A3dnrInstanceConfig_t *pInstConfig
);



/*****************************************************************************/
/**
 *          A3dnrRelease()
 *
 * @brief   The function releases/frees the Auto 3d noise reduction module
 *
 * @param   handle  Handle to A3DNRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A3dnrRelease
(
    A3dnrHandle_t handle
);



/*****************************************************************************/
/**
 *          A3dnrConfigure()
 *
 * @brief   This function configures the Auto 3d noise reduction module
 *
 * @param   handle  Handle to A3DNRM
 * @param   pConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT A3dnrConfigure
(
    A3dnrHandle_t handle,
    A3dnrConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          A3dnrReConfigure()
 *
 * @brief   This function re-configures the Auto 3d noise reduction Module
 *          after e.g. resolution change
 *
 * @param   handle  Handle to A3DNRM
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT A3dnrReConfigure
(
    A3dnrHandle_t handle,
    A3dnrConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          A3dnrSetAutoLevel()
 *
 * @brief   This function set auto mode level
 *
 * @param   handle  Handle to A3DNRM
 * @param   level
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT A3dnrSetAutoLevel
(
    A3dnrHandle_t handle,
    const uint8_t level
);



/*****************************************************************************/
/**
 *          A3dnrSetAutoParamTable()
 *
 * @brief   This function set auto mode parameters table
 *
 * @param   handle  Handle to A3DNRM
 * @param   pParamTable
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT A3dnrSetAutoParamTable
(
    A3dnrHandle_t handle,
    A3dnrParamTable_t *pParamTable
);



/*****************************************************************************/
/**
 *          A3dnrStart()
 *
 * @brief   The function starts the Auto 3d noise reduction module
 *
 * @param   handle  Handle to A3DNRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A3dnrStart
(
    A3dnrHandle_t 		handle,
    const A3dnrMode_t	mode
);



/*****************************************************************************/
/**
 *          A3dnrStop()
 *
 * @brief   The function stops the Auto 3d noise reduction module
 *
 * @param   handle  Handle to A3DNRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A3dnrStop
(
    A3dnrHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the current configuration.
 *
 * @param   handle      A3DNR instance handle
 * @param   pConfig     reference of configuration structure to be filled with
 *                      the current configuration
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT A3dnrGetCurrentConfig
(
    A3dnrHandle_t handle,
    A3dnrConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          A3dnrStatus()
 *
 * @brief   The function returns the status of the Auto 3d noise reduction
 *          module
 *
 * @param   handle  Handle to A3DNRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A3dnrStatus
(
    A3dnrHandle_t 		handle,
    bool_t       		*pRunning,
    A3dnrMode_t			*pMode,
    A3dnrParamNode_t 	*pCurrentParam
);



/*****************************************************************************/
/**
 *          A3dnrProcessFrame()
 *
 * @brief   The function calculates and adjusts a new 3DNR-setup regarding
 *          the current sensor-gain
 *
 * @param   handle  Handle to A3DNRM
 *          gain    current sensor-gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT A3dnrProcessFrame
(
    A3dnrHandle_t		handle,
    const float			fGain,
    const float			fIntegrationTime
);



#ifdef __cplusplus
}
#endif


/* @} A3DNR */


#endif /* __A3DNR_H__*/
