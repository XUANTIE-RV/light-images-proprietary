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

#ifndef __CAMERIC_IE_DRV_API_H__
#define __CAMERIC_IE_DRV_API_H__

/**
 * @cond    cameric_ie
 *
 * @file    cameric_ie_drv_api.h
 *
 * @brief   This file contains the CamerIC IE driver API definitions.
 *
 *****************************************************************************/
/**
 * @defgroup cameric_ie_drv_api CamerIC IE Driver API definitions
 * @{
 *
 * The Image Effects block modifies an image by pixel modifications. A set of
 * different modifications can be applied:
 *
 * @arg grayscale-effect: In this mode only the luminance component of the image
 * is processed. The chrominance part is set to 128.
 *
 * @arg negative-effect: This effect inverts the luminance and chrominance part of a
 * picture. The values are inverted according to the BT.601 pixel value range
 * (16...235 for luminance and 16...240 for chrominance).
 *
 * @arg sepia-effect: In sepia mode the two chrominance components are processed.
 * The chrominance should be modified in the appropriate brown hue to create a
 * historical like image color. The new chrominance parts of resulting pixels
 * are calculated according to the programmed tint color value (IMG_EFF_TINT)
 * and the luminance part of the original pixel. The Y component is passed through.
 *
 * @arg color selection-effect: Converting picture to grayscale while maintaining
 * one color component above a configurable threshold value (0...255).
 *
 * The following effects are realized with a programmable 3x3 Laplace filter
 * which uses a two line buffers. The kernel for filtering (see Table 2) is
 * programmable and for the following two effects (emboss and sketch) the
 * configuration registers are separately available with their default
 * values (IMG_EFF_MAT_1 to IMG_EFF_MAT_5).
 *
 * Programmable Laplace Filter Kernel:
 *
 * 1.1 | 1.2 | 1.3 \n
 * ----+-----+---- \n
 * 2.1 | 2.2 | 2.3 \n
 * ----+-----+---- \n
 * 3.1 | 3.2 | 3.3 \n
 *
 * @arg emboss-effect: The emboss effect is created by the result of a 3x3
 * Laplace Filter with the luminance components. For emboss picture appearing
 * an offset 128 is added to the result. The chrominance components are not
 * processed and are set to 128.
 *
 * @arg sketch effect: The sketch mode is also a result of the 3x3 Laplace
 * Filter with an extracting of the edges in whitely background. A fixed
 * threshold value of 31 is defined. All luminance values smaller 31 are
 * set to 235 to visualize the whitely background. Other luminance values
 * are subtracted from 235 to visualize the edges in picture. The chrominance
 * components are not processed and are set to 128.
 *
 * @arg The sharpen effect is applied to the Y component only. The Cb and Cr
 * components are not modified by this effect. The sharpen function shall be
 * realized as a coring filter which consists of a highpass filter and a
 * threshold function for the highpass signal. The output signal is the sum
 * of highpass and original signal as shown in Figure 2. The coefficients
 * for the highpass filter are shown in Table 3. The factor (sharp_factor)
 * for the highpass signal shall be programmable through a register in the
 * range 0.1 to 1.5. The threshold (coring_thr) for the coring function shall
 * have a range between 0 and 255. The registers for the convolution mask of
 * the highpass filter shall be shared between sketch and sharpening effect.
 *
 * In addition a sharpening function shall be implemented, which enhances the
 * perceived sharpness of images by applying a kind of coring function to the
 * Y component of the image.
 *
 * The Image Effects module gets YCbCr 4:2:2 data via a 16 bit ([15:8]: Y,
 * [7:0]: Cb/Cr) data interface from the Color Processing Module. An image
 * can be modified in eight different effect modes (see chapter 1.1).
 *
 * The YCbCr 4:2:2 output picture is sent to the Superimpose Module via a 16
 * bit data interface.
 *
 * @if CAMERIC_LITE
 *
 * @image html ie_lite.png "Overview of the CamerIC IE driver" width=\textwidth
 * @image latex ie_lite.png "Overview of the CamerIC IE driver" width=\textwidth
 *
 * @endif
 *
 * @if CAMERIC_FULL
 *
 * @image html ie.png "Overview of the CamerIC IE driver" width=\textwidth
 * @image latex ie.png "Overview of the CamerIC IE driver" width=\textwidth
 *
 * @endif
 *
 */
#include <ebase/types.h>
#include <common/return_codes.h>
#include <cam_device/cam_device_ispcore_defs.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/**
 * @brief   This function enables the IE Module.
 *
 * @param   handle          	CamerIc driver handle
 *
 * @return                  	Return the result of the function call.
 * @retval	RET_SUCCESS			operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIeEnable
(
    CamerIcDrvHandle_t handle
);

/*****************************************************************************/
/**
 * @brief   This function disables the IE module (bypass the image effects
 * 			module).
 *
 * @param   handle          	CamerIc driver handle
 *
 * @return                  	Return the result of the function call.
 * @retval	RET_SUCCESS			operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIeDisable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the status of the IE module.
 *
 * @param   handle              CamerIc driver handle
 * @param   pIsEnabled          Pointer to value to store current state
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NULL_POINTER    pIsEnabled is a NULL pointer
 *
 *****************************************************************************/
extern RESULT CamerIcIeIsEnabled
(
    CamerIcDrvHandle_t      handle,
    bool_t                  *pIsEnabled
);



/*****************************************************************************/
/**
 * @brief   This function configures the IE module
 *
 * @param   handle              CamerIC driver handle
 * @param   pConfig             pointer to image effects configuration structure
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NOTSUPP         selected working mode is not supported
 * @retval  RET_NULL_POINTER    null pointer
 * @retval  RET_BUSY            image effects already enabled
 *
 *****************************************************************************/
extern RESULT CamerIcIeConfigure
(
    CamerIcDrvHandle_t      handle,
    CamerIcIeConfig_t       *pConfig
);


/*****************************************************************************/
/**
 * @brief   This function sets the Cb tint value in CamerIC IE module.
 *
 * @param   handle              CamerIc driver handle
 * @param   tint                tint value to set
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_OUTOFRANGE      given brightness value is out of range
 *
 *****************************************************************************/
extern RESULT CamerIcIeSetTintCb
(
    CamerIcDrvHandle_t      handle,
    const uint8_t           tint
);


/*****************************************************************************/
/**
 * @brief   This function sets the Cr tint value in CamerIC IE module.
 *
 * @param   handle              CamerIc driver handle
 * @param   tint                tint value to set
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_OUTOFRANGE      given brightness value is out of range
 *
 *****************************************************************************/
extern RESULT CamerIcIeSetTintCr
(
    CamerIcDrvHandle_t      handle,
    const uint8_t           tint
);


/*****************************************************************************/
/**
 * @brief   This function sets color selection in CamerIC IE module.
 *
 * @param   handle              CamerIc driver handle
 * @param   color               selected color
 * @param   threshold           threshold
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_OUTOFRANGE      given brightness value is out of range
 *
 *****************************************************************************/
extern RESULT CamerIcIeSetColorSelection
(
    CamerIcDrvHandle_t              handle,
    const CamerIcIeColorSelection_t color,
    const uint8_t                   threshold
);


/*****************************************************************************/
/**
 * @brief   This function sets sharpening in CamerIC IE module.
 *
 * @param   handle              CamerIc driver handle
 * @param   factor              sharpening factor color
 * @param   threshold           threshold
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_OUTOFRANGE      given brightness value is out of range
 *
 *****************************************************************************/
extern RESULT CamerIcIeSetSharpen
(
    CamerIcDrvHandle_t              handle,
    const uint8_t                   factor,
    const uint8_t                   threshold
);


#ifdef __cplusplus
}
#endif

/* @} cameric_ie_drv_api */

/* @endcond */

#endif /* __CAMERIC_IE_DRV_API_H__ */

