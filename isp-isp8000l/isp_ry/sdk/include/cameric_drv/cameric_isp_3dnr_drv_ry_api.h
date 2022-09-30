#ifndef __CAMERIC_ISP_3DNR_DRV_RY_API_H__
#define __CAMERIC_ISP_3DNR_DRV_RY_API_H__

/**
* @file    cameric_isp_3dnr_drv_ry_api.h
*
* @brief   This file contains the CamerIC ISP 3DNR driver API definitions.
*
*****************************************************************************/
/**
* @cond cameric_isp_3dnr
*
* @defgroup cameric_isp_3dnr_drv_api CamerIC ISP 3DNR Driver API definitions
* @{
*
*/
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif


typedef struct CamerIcIsp3DnrConfig_ry_s {
    uint8_t               strength;		 /**< strength */
    uint16_t              motionFactor;	 /**< motionFactor */
    uint16_t              deltaFactor; 	 /**< deltaFactor */
} CamerIcIsp3DnrConfig_ry_t;

typedef struct CamericIsp3DNRCompress_ry_s {
    uint8_t weightUpY[2];
    uint8_t weightDown[4];
    uint8_t weightUpX[8];

} CamericIsp3DNRCompress_ry_t;
/*****************************************************************************/
/**
*          CamerIcIsp3DnrEnable_ry()
*
* @brief   Enable 3DNR Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIsp3DnrEnable_ry
(
	CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
*          CamerIcIsp3DnrDisable_ry()
*
* @brief   Disable 3DNR Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIsp3DnrDisable_ry
(
	CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
*          CamerIcIsp3DnrConfig_ry()
*
* @brief   Config 3DNR Module
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIsp3DnrConfig_ry
(
	CamerIcDrvHandle_ry_t  handle,
    CamerIcIsp3DnrConfig_ry_t  *p3DnrCfg
);



/*****************************************************************************/
/**
*          CamerIcIsp3DnrCompute_ry()
*
* @brief   Compute 3DNR Module register use last average, last last average and gain
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIsp3DnrCompute_ry
(
	CamerIcDrvHandle_ry_t  handle
);



/*****************************************************************************/
/**
*          CamerIcIsp3DnrSetSensorExpGain_ry()
*
* @brief   Update 3DNR Module's last average and last average
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIsp3DnrSetSensorExpGain_ry
(
	CamerIcDrvHandle_ry_t  handle,
	float 				expGain
);

/*****************************************************************************/
/**
*          CamerIcIsp3DNRSetCompress_ry()
*
* @brief   config CamerIc ISP 3DNR driver compress parm for 3dnr ddr less 
context
*
* @return  Return the result of the function call.
* @retval  RET_SUCCESS
* @retval  RET_FAILURE
*
*****************************************************************************/
		
RESULT CamerIcIsp3DNRSetCompress_ry(
	CamerIcDrvHandle_ry_t handle, 
	CamericIsp3DNRCompress_ry_t *cmp
);

/*****************************************************************************/
/**
*          CamerIcIsp3DnrSetStrength_ry()
*
* @brief   set 3DNR Module's denoiseStrength
*
* @param   handle          CamerIc driver handle
*
* @return                  Return the result of the function call.
* @retval                  RET_SUCCESS
* @retval                  RET_FAILURE
*
*****************************************************************************/
RESULT CamerIcIsp3DnrSetStrength_ry( 
	CamerIcDrvHandle_ry_t  handle,
	unsigned int denoiseStrength
);

RESULT CamerIcIsp3DnrSetMotionFactor_ry( 
    CamerIcDrvHandle_ry_t  handle,
    unsigned int motionFactor
);

RESULT CamerIcIsp3DnrSetDeltaFactor_ry(
    CamerIcDrvHandle_ry_t  handle,
    unsigned int deltaFactor
);


#ifdef __cplusplus
}
#endif

/* @} cameric_isp_3dnr_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_3DNR_DRV_RY_API_H__ */

