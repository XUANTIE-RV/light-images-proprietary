/******************************************************************************
 *
 * Copyright 2020, Verisilicon. All rights reserved.
 *
 *****************************************************************************/

#ifndef __AFLT_H__
#define __AFLT_H__

/**
 * @file aflt.h
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
 * @defgroup AFLT Auto Filter module
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
typedef enum AfltRunMode_e
{
    AFLT_MODE_INVALID                    = 0,        /**< initialization value */
    AFLT_MODE_MANUAL                     = 1,        /**< run manual filter */
    AFLT_MODE_AUTO                       = 2,        /**< run auto filter */
    AFLT_MODE_MAX
} AfltMode_t;



/*****************************************************************************/
/**
 *          AfltHandle_t
 *
 * @brief   AFLT Module instance handle
 *
 *****************************************************************************/
typedef struct AfltContext_s *AfltHandle_t;         /**< handle to AFLT context */



/*****************************************************************************/
/**
 *          AfltInstanceConfig_t
 *
 * @brief   AFLT Module instance configuration structure
 *
 *****************************************************************************/
typedef struct AfltInstanceConfig_s
{
    CamerIcDrvHandle_t      hCamerIc;           /**< handle to cameric driver */
    CamerIcDrvHandle_t      hSubCamerIc;        /**< handle to 2nd cameric drivder (3D) */

    AfltHandle_t            hAflt;            	/**< handle returned by AfltInit() */
} AfltInstanceConfig_t;



/*****************************************************************************/
/**
 *          AfltConfig_t
 *
 * @brief   AFLT Module configuration structure
 *
 *****************************************************************************/
typedef struct AfltConfig_s
{
    uint8_t			denoiseLevel;	/**< denoiseLevel */
    uint8_t			sharpenLevel;	/**< sharpenLevel */
} AfltConfig_t;



/*****************************************************************************/
/**
 *          AfltParamNode_t
 *
 * @brief   AFLT parameters node structure
 *
 *****************************************************************************/
typedef struct AfltParamNode_s
{
	float				gain;				/**< gain */
	float				integrationTime;	/**< integrationTime */
    uint8_t				denoiseLevel;		/**< denoiseLevel */
    uint8_t				sharpenLevel;		/**< sharpenLevel */
} AfltParamNode_t;



/*****************************************************************************/
/**
 *          AfltParamTable_t
 *
 * @brief   AFLT Module parameters table structure
 *
 *****************************************************************************/
typedef struct AfltParamTable_s
{
    uint8_t					nodeNum;  			/**< nodeNum */
    AfltParamNode_t			*pNodeList;			/**< point of Node List  */
} AfltParamTable_t;



/*****************************************************************************/
/**
 *          AfltInit()
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
RESULT AfltInit
(
    AfltInstanceConfig_t *pInstConfig
);



/*****************************************************************************/
/**
 *          AfltRelease()
 *
 * @brief   The function releases/frflts the Auto 3d noise reduction module
 *
 * @param   handle  Handle to AFLTM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AfltRelease
(
    AfltHandle_t handle
);



/*****************************************************************************/
/**
 *          AfltConfigure()
 *
 * @brief   This function configures the Auto 3d noise reduction module
 *
 * @param   handle  Handle to AFLTM
 * @param   pConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AfltConfigure
(
    AfltHandle_t handle,
    AfltConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AfltReConfigure()
 *
 * @brief   This function re-configures the Auto 3d noise reduction Module
 *          after e.g. resolution change
 *
 * @param   handle  Handle to AFLTM
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AfltReConfigure
(
    AfltHandle_t handle,
    AfltConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AfltSetAutoParamTable()
 *
 * @brief   This function set auto mode parameters table
 *
 * @param   handle  Handle to AFLTM
 * @param   pParamTable
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AfltSetAutoParamTable
(
    AfltHandle_t handle,
    AfltParamTable_t *pParamTable
);



/*****************************************************************************/
/**
 *          AfltStart()
 *
 * @brief   The function starts the Auto 3d noise reduction module
 *
 * @param   handle  Handle to AFLTM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AfltStart
(
    AfltHandle_t 		handle,
    const AfltMode_t	mode
);



/*****************************************************************************/
/**
 *          AfltStop()
 *
 * @brief   The function stops the Auto 3d noise reduction module
 *
 * @param   handle  Handle to AFLTM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AfltStop
(
    AfltHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the current configuration.
 *
 * @param   handle      AFLT instance handle
 * @param   pConfig     reference of configuration structure to be filled with
 *                      the current configuration
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT AfltGetCurrentConfig
(
    AfltHandle_t handle,
    AfltConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AfltStatus()
 *
 * @brief   The function returns the status of the Auto 3d noise reduction
 *          module
 *
 * @param   handle  Handle to AFLTM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AfltStatus
(
    AfltHandle_t 		handle,
    bool_t       		*pRunning,
    AfltMode_t			*pMode,
    AfltParamNode_t 	*pCurrentParam
);



/*****************************************************************************/
/**
 *          AfltProcessFrame()
 *
 * @brief   The function calculates and adjusts a new FLT-setup regarding
 *          the current sensor-gain
 *
 * @param   handle  Handle to AFLTM
 *          gain    current sensor-gain
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AfltProcessFrame
(
    AfltHandle_t    	handle,
    const float			fGain,
    const float			fIntegrationTime
);



#ifdef __cplusplus
}
#endif


/* @} AFLT */


#endif /* __AFLT_H__*/
