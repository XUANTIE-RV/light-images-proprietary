/******************************************************************************
 *
 * Copyright 2020, Verisilicon. All rights reserved.
 *
 *****************************************************************************/

#ifndef __ATDNR_H__
#define __ATDNR_H__

/**
 * @file atdnr.h
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
 * @defgroup ATDNR Auto Tempor Noise Reduction module
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
typedef enum AtdnrRunMode_e
{
    ATDNR_MODE_INVALID                    = 0,        /**< initialization value */
    ATDNR_MODE_MANUAL                     = 1,        /**< run manual 3d noise reduction */
    ATDNR_MODE_AUTO                       = 2,        /**< run auto 3d noise reduction */
    ATDNR_MODE_MAX
} AtdnrMode_t;



/*****************************************************************************/
/**
 *          AtdnrHandle_t
 *
 * @brief   ATDNR Module instance handle
 *
 *****************************************************************************/
typedef struct AtdnrContext_s *AtdnrHandle_t;         /**< handle to ATDNR context */



/*****************************************************************************/
/**
 *          AtdnrInstanceConfig_t
 *
 * @brief   ATDNR Module instance configuration structure
 *
 *****************************************************************************/
typedef struct AtdnrInstanceConfig_s
{
    CamerIcDrvHandle_ry_t      hCamerIc;           /**< handle to cameric driver */
    CamerIcDrvHandle_ry_t      hSubCamerIc;        /**< handle to 2nd cameric drivder (3D) */

    AtdnrHandle_t            hAtdnr;            /**< handle returned by AtdnrInit() */
} AtdnrInstanceConfig_t;



/*****************************************************************************/
/**
 *          AtdnrConfig_t
 *
 * @brief   ATDNR Module configuration structure
 *
 *****************************************************************************/
typedef struct AtdnrConfig_s
{
    uint16_t	noiseLevel;
    uint8_t		motionSlope;
    uint8_t		sadWeight;
    uint16_t	filterLength1;
	uint8_t		filterLength2;
} AtdnrConfig_t;



/*****************************************************************************/
/**
 *          AtdnrParamNode_t
 *
 * @brief   ATDNR parameters node structure
 *
 *****************************************************************************/
typedef struct AtdnrParamNode_s
{
	float					gain;				/**< gain */
	float					integrationTime;	/**< integrationTime */
    AtdnrConfig_t           config;				/**< config */
} AtdnrParamNode_t;



/*****************************************************************************/
/**
 *          AtdnrParamTable_t
 *
 * @brief   ATDNR Module parameters table structure
 *
 *****************************************************************************/
typedef struct AtdnrParamTable_s
{
    uint8_t               nodeNum;  			/**< nodeNum */
    AtdnrParamNode_t      *pNodeList;			/**< point of Node List  */
} AtdnrParamTable_t;



/*****************************************************************************/
/**
 *          AtdnrInit()
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
RESULT AtdnrInit
(
    AtdnrInstanceConfig_t *pInstConfig
);



/*****************************************************************************/
/**
 *          AtdnrRelease()
 *
 * @brief   The function releases/frees the Auto 3d noise reduction module
 *
 * @param   handle  Handle to ATDNRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AtdnrRelease
(
    AtdnrHandle_t handle
);



/*****************************************************************************/
/**
 *          AtdnrConfigure()
 *
 * @brief   This function configures the Auto 3d noise reduction module
 *
 * @param   handle  Handle to ATDNRM
 * @param   pConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AtdnrConfigure
(
    AtdnrHandle_t handle,
    AtdnrConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AtdnrReConfigure()
 *
 * @brief   This function re-configures the Auto 3d noise reduction Module
 *          after e.g. resolution change
 *
 * @param   handle  Handle to ATDNRM
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AtdnrReConfigure
(
    AtdnrHandle_t handle,
    AtdnrConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AtdnrSetAutoStrength()
 *
 * @brief   This function set auto mode strength
 *
 * @param   handle  Handle to ATDNRM
 * @param   level
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AtdnrSetAutoStrength
(
    AtdnrHandle_t handle,
    const float   autoStrength
);



/*****************************************************************************/
/**
 *          AtdnrSetAutoParamTable()
 *
 * @brief   This function set auto mode parameters table
 *
 * @param   handle  Handle to ATDNRM
 * @param   pParamTable
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AtdnrSetAutoParamTable
(
    AtdnrHandle_t handle,
    AtdnrParamTable_t *pParamTable
);



/*****************************************************************************/
/**
 *          AtdnrStart()
 *
 * @brief   The function starts the Auto 3d noise reduction module
 *
 * @param   handle  Handle to ATDNRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AtdnrStart
(
    AtdnrHandle_t 		handle,
    const AtdnrMode_t	mode
);



/*****************************************************************************/
/**
 *          AtdnrStop()
 *
 * @brief   The function stops the Auto 3d noise reduction module
 *
 * @param   handle  Handle to ATDNRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AtdnrStop
(
    AtdnrHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the current configuration.
 *
 * @param   handle      ATDNR instance handle
 * @param   pConfig     reference of configuration structure to be filled with
 *                      the current configuration
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT AtdnrGetCurrentConfig
(
    AtdnrHandle_t handle,
    AtdnrConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AtdnrStatus()
 *
 * @brief   The function returns the status of the Auto 3d noise reduction
 *          module
 *
 * @param   handle  Handle to ATDNRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AtdnrStatus
(
    AtdnrHandle_t 		handle,
    bool_t       		*pRunning,
    AtdnrMode_t			*pMode,
    AtdnrParamNode_t 	*pCurrentParam
);



/*****************************************************************************/
/**
 *          AtdnrProcessFrame()
 *
 * @brief   The function calculates and adjusts a new TDNR-setup regarding
 *          the current sensor-gain
 *
 * @param   handle  Handle to ATDNRM
 *          gain    current sensor-gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AtdnrProcessFrame
(
    AtdnrHandle_t		handle,
    const float			fGain,
    const float			fIntegrationTime
);



#ifdef __cplusplus
}
#endif


/* @} ATDNR */


#endif /* __ATDNR_H__*/
