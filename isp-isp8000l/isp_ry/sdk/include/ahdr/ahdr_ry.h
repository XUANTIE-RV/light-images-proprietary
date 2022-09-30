/******************************************************************************
 *
 * Copyright 2020, Verisilicon. All rights reserved.
 *
 *****************************************************************************/

#ifndef __AHDR_H__
#define __AHDR_H__

/**
 * @file ahdr.h
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
 * @defgroup AHDR Auto High Dynamic Range module
 * @{
 *
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#include <isi/isi_iss_ry.h>
#include <isi/isi_ry.h>
#include "isp_version.h" //need remove later


#ifdef __cplusplus
extern "C"
{
#endif



/*****************************************************************************/
/**
 *          AhdrHandle_t
 *
 * @brief   AHDR Module instance handle
 *
 *****************************************************************************/
typedef struct AhdrContext_s *AhdrHandle_t;         /**< handle to AHDR context */


/*****************************************************************************/
/**
 *          AhdrInstanceConfig_t
 *
 * @brief   AHDR Module instance configuration structure
 *
 *****************************************************************************/
typedef struct AhdrInstanceConfig_s
{
    CamerIcDrvHandle_ry_t      hCamerIc;           /**< handle to cameric driver */
    CamerIcDrvHandle_ry_t      hSubCamerIc;        /**< handle to 2nd cameric drivder (3D) */

    AhdrHandle_t            hAhdr;            /**< handle returned by AhdrInit() */
} AhdrInstanceConfig_t;




/*****************************************************************************/
/**
 *          AhdrConfig_t
 *
 * @brief   AHDR Module configuration structure
 *
 *****************************************************************************/
typedef struct AhdrConfig_s
{
	uint8_t				extBit;					/**< extBit */
    float				hdrRatio;				/**< hdrRatio */
    int                 mode;                   /**< stitchingMode [0, 6], ingnore at ReConfigure*/
    float               transrangeStart;
    float               transrangeEnd;
} AhdrConfig_t;



/*****************************************************************************/
/**
 *          AhdrInit()
 *
 * @brief   This function initializes the Auto high dynamic range module
 *
 * @param   pInstConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_INVALID_PARM
 * @retval  RET_OUTOFMEM
 *
 *****************************************************************************/
RESULT AhdrInit
(
    AhdrInstanceConfig_t *pInstConfig
);



/*****************************************************************************/
/**
 *          AhdrRelease()
 *
 * @brief   The function releases/frees the Auto high dynamic range module
 *
 * @param   handle  Handle to AHDRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AhdrRelease
(
    AhdrHandle_t handle
);



/*****************************************************************************/
/**
 *          AhdrConfigure()
 *
 * @brief   This function configures the Auto high dynamic range module
 *
 * @param   handle  Handle to AHDRM
 * @param   pConfig
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_INVALID_PARM
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AhdrConfigure
(
    AhdrHandle_t handle,
    AhdrConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AhdrReConfigure()
 *
 * @brief   This function re-configures the Auto high dynamic range Module
 *          after e.g. resolution change
 *
 * @param   handle  Handle to AHDRM
 *
 * @return  Returns the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_WRONG_STATE
 *
 *****************************************************************************/
RESULT AhdrReConfigure
(
    AhdrHandle_t handle,
    AhdrConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AhdrStart()
 *
 * @brief   The function starts the Auto high dynamic range module
 *
 * @param   handle  Handle to AHDRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AhdrStart
(
    AhdrHandle_t handle
);



/*****************************************************************************/
/**
 *          AhdrStop()
 *
 * @brief   The function stops the Auto high dynamic range module
 *
 * @param   handle  Handle to AHDRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AhdrStop
(
    AhdrHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the current configuration.
 *
 * @param   handle      AHDR instance handle
 * @param   pConfig     reference of configuration structure to be filled with
 *                      the current configuration
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT AhdrGetCurrentConfig
(
    AhdrHandle_t handle,
    AhdrConfig_t *pConfig
);



/*****************************************************************************/
/**
 *          AhdrStatus()
 *
 * @brief   The function returns the status of the Auto high dynamic range
 *          module
 *
 * @param   handle  Handle to AHDRM
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AhdrStatus
(
    AhdrHandle_t handle,
    bool_t       *pRunning
);



/*****************************************************************************/
/**
 *          AhdrProcessFrame()
 *
 * @brief   The function calculates and adjusts a new HDR-setup regarding
 *          the current sensor-gain
 *
 * @param   handle  		Handle to AHDRM
 *          sensorGain		current sensor-gain
 *			exposureTime	current sensor-exposure-time
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AhdrProcessFrame
(
	AhdrHandle_t	handle,
	const float 	sensorGain[3],
	const float 	exposureTime[3]
);



/*****************************************************************************/
/**
 *          AhdrGetHdrRatio()
 *
 * @brief   The function calculates and adjusts a new HDR-setup regarding
 *          the current sensor-gain
 *
 * @param   handle  		Handle to AHDRM
 *          pHdrRatio		current hdr_ratio setting
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_FAILURE
 *
 *****************************************************************************/
RESULT AhdrGetHdrRatio
(
	AhdrHandle_t	handle,
	float			*pHdrRatio
);



/*****************************************************************************/
/**
 *			AhdrGetExtBit()
 *
 * @brief	The function calculates and adjusts a new HDR-setup regarding
 *			the current sensor-gain
 *
 * @param	handle			Handle to AHDRM
 *			pExtBit			current ext_bit setting
 *
 * @return	Return the result of the function call.
 * @retval	RET_SUCCESS
 * @retval	RET_FAILURE
 *
 *****************************************************************************/
RESULT AhdrGetExtBit
(
    AhdrHandle_t    handle,
    uint8_t     	*pExtBit
);


#ifdef __cplusplus
}
#endif


/* @} AHDR */


#endif /* __AHDR_H__*/
