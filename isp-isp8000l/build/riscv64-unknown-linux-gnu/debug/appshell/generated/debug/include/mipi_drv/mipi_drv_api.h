/******************************************************************************\
|* Copyright 2010, Dream Chip Technologies GmbH. used with permission by      *|
|* VeriSilicon.                                                               *|
|* Copyright (c) <2020> by VeriSilicon Holdings Co., Ltd. ("VeriSilicon")     *|
|* All Rights Reserved.                                                       *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of VeriSilicon.  This is proprietary information owned or licensed by      *|
|* VeriSilicon.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of VeriSilicon.                                         *|
|*                                                                            *|
\******************************************************************************/

/* VeriSilicon 2020 */

/**
 * @file mipi_drv_api.h
 *
 * @brief   Definition of MIPI driver API.
 *
 *****************************************************************************/

#ifndef __MIPI_DRV_API_H__
#define __MIPI_DRV_API_H__

#include <common/mipi.h>

#include <mipi_drv/mipi_drv_common.h>


#ifdef __cplusplus
extern "C"
{
#endif


/*****************************************************************************/
/**
 * @brief   This function creates and initializesthe MIPI driver context.
 *
 * @param   pConfig             Reference to configuration structure.
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_OUTOFMEM        not enough memory
 *
 * @note    On succes, this function fills in the DrvHandle from the configuration
 *          structure @ref MipiDrvConfig_s. This returned DrvHandle has to be
 *          used for later driver calls and should be store in application context.
 *
 *****************************************************************************/
extern RESULT MipiDrvInit
(
    MipiDrvConfig_t  *pConfig
);



/*****************************************************************************/
/**
 * @brief   This function releases the MIPI software driver context.
 *
 * @param   MipiDrvHandle       Handle to MIPI driver context as returned by @ref MipiDrvInit.
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to release its
 *                              context
 *
 * @note    Allocated memory by @ref MipiDrvInit is also released
 *
 *****************************************************************************/
extern RESULT MipiDrvRelease
(
    MipiDrvHandle_t MipiDrvHandle
);


/*****************************************************************************/
/**
 * @brief   This function configures the MIPI software driver.
 *
 * @param   MipiDrvHandle       Handle to MIPI driver context as returned by @ref MipiDrvInit.
 * @param   pMipiConfig         Refrence to MIPI configuration to use.
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to stop the driver
 *                              (maybe the driver is already running)
 *
 *****************************************************************************/
extern RESULT MipiDrvConfig
(
    MipiDrvHandle_t MipiDrvHandle,
    MipiConfig_t    *pMipiConfig
);


/*****************************************************************************/
/**
 * @brief   This function starts the MIPI software driver.
 *
 * @param   MipiDrvHandle       Handle to MIPI driver context as returned by @ref MipiDrvInit.
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to stop the driver
 *                              (maybe the driver is already running)
 *
 * @note    This function also starts the interrupt handling
 *
 *****************************************************************************/
extern RESULT MipiDrvStart
(
    MipiDrvHandle_t MipiDrvHandle
);


/*****************************************************************************/
/**
 * @brief   This function stops the MIPI software driver.
 *
 * @param   MipiDrvHandle       Handle to MIPI driver context as returned by @ref MipiDrvInit.
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to stop the driver
 *                              (maybe the driver is already stopped)
 *
 *****************************************************************************/
extern RESULT MipiDrvStop
(
    MipiDrvHandle_t MipiDrvHandle
);


extern int CsiOpen(const char* name);
extern void CsiClose(int fd);
extern int CsiSetFormat(int fd, int pad, int width, int height, int format);
extern int CsiSetHdr(int fd, int pad, bool enable);
extern int CsiSetPower(int fd, bool enable);
extern int CsiStreamon(int fd);
extern int CsiStreamoff(int fd);

#ifdef __cplusplus
}
#endif

#endif /* __MIPI_DRV_API_H__ */
