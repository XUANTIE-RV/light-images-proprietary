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

#ifndef __CAMERIC_ISP_HIST64_DRV_API_H__
#define __CAMERIC_ISP_HIST64_DRV_API_H__

/**
 * @cond    cameric_isp_hist64
 *
 * @file    cameric_isp_hist64_drv_api.h
 *
 * @brief   This file contains the CamerIC ISP HIST driver API definitions.
 *
 *****************************************************************************/
/**
 * @defgroup cameric_isp_hist64_drv_api CamerIC ISP HIST driver API definitions
 * @{
 *
 * In general, a histogram is a graphical representation of the pattern of
 * variation  that exists in the intensity values of the color or luminance
 * planes. Usually it is displayed by vertical bars drawn to indicate frequency
 * levels of data collected within specific ranges.
 *
 * The following figure shows the position of the histogram measuring module in
 * the CamerIC ISP pipeline.
 *
 * @image html hist.png "Overview of the CamerIC ISP HIST driver" width=\textwidth
 * @image latex hist.png "Overview of the CamerIC ISP HIST driver" width=\textwidth
 *
 * The complete range of possible intensity values is divided into a number
 * (@ref CAMERIC_ISP_HIST64_NUM_BINS) of equally-sized ranges, so called @b bins .
 * Each incoming intensity value is associated to one of these bins and gets
 * counted for that bin only.
 *
 * The histogram measurement can be configured to work in one of five modes
 * (@ref CamerIcIspHist64Mode_e):
 *
 * @arg R separated histogram: only the red color component of incoming RGB
 *      triples is measured.
 * @arg G separated histogram: only the green color component of incoming RGB
 *      triples is measured.
 * @arg B separated histogram: only the blue color component of incoming RGB
 *      triples is measured.
 * @arg RGB combined histogram: The sum of red, green and blue component of
 *      the incoming RGB triples is measured. Note that it is not possible
 *      to calculate a luminance or grayscale histogram from an RGB histogram
 *      since the position information is lost during its generation.
 * @arg Y (luminance) histogram: the luminance values of incoming RGB triples
 *      are measured.
 *
 * Further, the histogram measurement block can be configured to measure
 * not the whole incoming image, but the pixels in a smaller window only.
 * Size and position of that measuring window can be set with @ref
 * CamerIcIspHist64SetMeasuringWindow.
 *
 * The histogram measurement window is also divided into a number (@ref
 * CAMERIC_ISP_HIST64_GRID_ITEMS) of sub-windows. Each sub-window may be
 * assigned a different weight factor, so that the contribution of the
 * sub-window to the histogram bins is weighted.
 *
 */
#include <ebase/types.h>
#include <common/return_codes.h>

#ifdef __cplusplus
extern "C"
{
#endif



/*****************************************************************************/
/**
 * @brief   This macro defines the number of used bins.
 *
 *****************************************************************************/

#define CAMERIC_ISP_HIST64_NUM_BINS           32  /**< number of bins */



/*****************************************************************************/
/**
 * @brief   This macro defines the number of used grid items ofr weightening
 *          measured pixels.
 *
 *****************************************************************************/
#define CAMERIC_ISP_HIST64_GRID_ITEMS         25  /**< number of grid sub windows */



/*****************************************************************************/
/**
 * @brief   This typedef specifies an array type to configure the grid weights
 *          of CamerIC ISP historgam module.
 *
 *****************************************************************************/
typedef uint8_t CamerIcHist64Weights_t[CAMERIC_ISP_HIST64_GRID_ITEMS];



/*****************************************************************************/
/**
 * @brief   This typedef represents the histogram which is measured by the
 *          CamerIC ISP histogram module.
 *
 *****************************************************************************/
typedef uint32_t CamerIcHist64Bins_t[ CAMERIC_ISP_HIST64_NUM_BINS];



/*****************************************************************************/
/**
 * @brief   Enumeration type to configure CamerIC ISP histogram measuring mode.
 *
 *****************************************************************************/
typedef enum CamerIcIspHist64Mode_e
{
    CAMERIC_ISP_HIST64_MODE_INVALID       = -1,    /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_HIST64_MODE_DISABLE  = 0,    /**< disable, no measurements  */
    CAMERIC_ISP_HIST64_MODE_ONE_FROM_YRGB             = 1,    /**< Y/R/G/B histogram controlled via coefficients coeff_r/g/b */
    CAMERIC_ISP_HIST64_MODE_R             = 2,    /**< r histogram */
    CAMERIC_ISP_HIST64_MODE_GR             = 3,    /**< Gr histogram */
    CAMERIC_ISP_HIST64_MODE_B             = 4,    /**< B histogram */
    CAMERIC_ISP_HIST64_MODE_GB             = 5,    /**< GB histogram */
    CAMERIC_ISP_HIST64_MODE_MAX,     				/**< upper border (only for an internal evaluation) */
} CamerIcIspHist64Mode_t;

typedef enum CamerIcIspHist64Channel_e
{
    CAMERIC_ISP_HIST64_CHANNEL_INVALID       = -1,    /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_HIST64_CHANNEL_0  = 0,    /**< disable, no measurements  */
    CAMERIC_ISP_HIST64_CHANNEL_1             = 1,
    CAMERIC_ISP_HIST64_CHANNEL_2             = 2,
    CAMERIC_ISP_HIST64_CHANNEL_3             = 3,
    CAMERIC_ISP_HIST64_CHANNEL_4             = 4,
    CAMERIC_ISP_HIST64_CHANNEL_5             = 5,
    CAMERIC_ISP_HIST64_CHANNEL_6             = 6,
    CAMERIC_ISP_HIST64_CHANNEL_7             = 7,
    CAMERIC_ISP_HIST64_CHANNEL_MAX,     				/**< upper border (only for an in*/
} CamerIcIspHist64Channel_t;

#define CAMERIC_ISP_HIST64_V_STEP_SIZE_MAX 127
#define CAMERIC_ISP_HIST64_V_STEP_SIZE_INVALID 0

#define CAMERIC_ISP_HIST64_H_STEP_INC_MAX 0x1ffff

#define  CAMERIC_ISP_HIST64_SAMPLE_SHIFT_MAX 7
#define CAMERIC_ISP_HIST64_SAMPLE_SHIFT_MIN  0

#define CAMERIC_ISP_HIST64_SAMPLE_OFFSET_MIN  0

#define CAMERIC_ISP_HIST64_SAMPLE_OFFSET_MAX 0xfff
typedef struct CamerIcIspHist64Window_s{
	unsigned int offsetX;
	unsigned int offsetY;
	unsigned int width;
	unsigned int height;
}CamerIcIspHist64Window_t;

#define CAMERIC_ISP_COEFFICIENT_MAX 1.992
/*****************************************************************************/
/**
 * @brief   This functions registers an Event-Callback at CamerIC ISP histogram
 *          measurement module. An event callback is called if the driver needs
 *          to inform the application layer about an asynchronous event or an
 *          error situation (i.e. please also @see CamerIcEventId_e).
 *
 * @param   handle              CamerIC driver handle
 * @param   func                Callback function
 * @param   pUserContext        User-Context
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_BUSY            already a callback registered
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_INVALID_PARM    a parameter is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to register a
 *                              event callback (maybe the driver is already
 *                              running)
 *
 *****************************************************************************/
extern RESULT CamerIcIspHist64RegisterEventCb
(
    CamerIcDrvHandle_t  handle,
    CamerIcEventFunc_t  func,
    void 			    *pUserContext
);



/*****************************************************************************/
/**
 * @brief   This functions deregisters/releases a registered Event-Callback
 *          at CamerIc ISP histogram64 measurement module.
 *
 * @param   handle              CamerIC driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to deregister the
 *                              request callback
 *
 *****************************************************************************/
extern RESULT CamerIcIspHist64DeRegisterEventCb
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This functions enables the CamerIC ISP histogram measurement
 *          module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspHist64Enable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   This functions disables the CamerIC ISP histogram measurement
 *          module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspHist64Disable
(
    CamerIcDrvHandle_t handle
);



/*****************************************************************************/
/**
 * @brief   Get CamerIC ISP histogram64 measurement module status.
 *
 * @param   handle          CamerIc driver handle.
 * @param   pIsEnabled
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
extern RESULT CamerIcIspHist64IsEnabled
(
    CamerIcDrvHandle_t      handle,
    bool_t                  *pIsEnabled
);



/*****************************************************************************/
/**
 * @brief   This functions configures the measurement mode of the CamerIC
 *          ISP histogram64 measurement module.
 *
 * @param   handle              CamerIc driver handle
 * @param   mode                measurement mode (see @ref CamerIcIspHist64Mode_e)
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspHist64SetMeasuringMode
(
    CamerIcDrvHandle_t  		handle,
    const CamerIcIspHist64Mode_t	mode
);

/*****************************************************************************/
/**
 * @brief   This function sets the position and size of a the measurement
 *          window in the CamerIC ISP histogram64 measurement module.
 *
 * @param   handle              CamerIc driver handle
 * @param   x                   start x position of measuring window
 * @param   y                   start y position of measuring window
 * @param   width               width of measuring window
 * @param   height              height of measuring window
 *
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_INVALID_PARM    invalid window identifier
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspHist64SetMeasuringWindow
(
    CamerIcDrvHandle_t  handle,
    const uint16_t      x,
    const uint16_t      y,
    const uint16_t      width,
    const uint16_t      height
);

/*****************************************************************************/
/**
 * @brief   This function configures the grid weights in the CamerIC ISP
 *          histogram64 measurement module.
 *
 * @param   handle              CamerIc driver handle
 * @param   weights             measurement mode (@see CamerIcHistWeights_t)
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspHist64SetGridWeights
(
    CamerIcDrvHandle_t          handle,
    const CamerIcHistWeights_t  weights
);

/*****************************************************************************/
/**
 * @brief   This function configures the subsample step in the CamerIC ISP
 *          histogram64 measurement module.
 *
 * @param   handle              CamerIc driver handle
 * @param   vStepSize           histogram veritcal predivider, process every
 *                              (stepsize)th line, all other lines are skipped
 * @param   hStepInc            horizontal subsampling step counter increment.
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
RESULT CamerIcIspHIST64SetSubSampleStep
(
    CamerIcDrvHandle_t          handle,
    const uint8_t               vStepSize,
    const uint32_t              hStepInc
);

/*****************************************************************************/
/**
 * @brief   This function configures the subsample range in the CamerIC ISP
 *          histogram64 measurement module.
 *
 * @param   handle              CamerIc driver handle
 * @param   shift               sample (left) shift will be executed after
 *                              offset subtraction and prior to histogram evaluation
 * @param   offset              sample offset will be subtracted from input
 *                              sample prior to shift and histogram evaluation
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
RESULT CamerIcIspHIST64SetSubSampleRange
(
    CamerIcDrvHandle_t          handle,
    const uint8_t               shift,
    const uint16_t              offset
);

/*****************************************************************************/
/**
 * @brief   This function force update the histogram register in the CamerIC ISP
 *          histogram64 measurement module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
RESULT CamerIcIspHIST64FourceUpdate
(
    CamerIcDrvHandle_t          handle
);

/*****************************************************************************/
/**
 * @brief   This function set the histogram conefficent in the CamerIC ISP
 *          histogram64 measurement module.
 *
 * @param   handle              CamerIc driver handle
 * @param   rCoeff              r coefficient
 * @param   gCoeff              g coefficient
 * @param   bCoeff              b coefficient
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
RESULT CamerIcIspHist64SetCoeff
(
    CamerIcDrvHandle_t          handle,
    const float               rCoeff,
    const float               gCoeff,
    const float               bCoeff
);

/*****************************************************************************/
/**
 * @brief   This function set the histogram channel in the CamerIC ISP
 *          histogram64 measurement module.
 *
 * @param   handle              CamerIc driver handle
 * @param   channel             channel  select
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_OUTOFRANGE      At least one perameter of out range
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
RESULT CamerIcIspHist64SetMeasuringChannel
(
    CamerIcDrvHandle_t          handle,
    const CamerIcIspHist64Channel_t    channel
);
#ifdef __cplusplus
}
#endif

/* @} cameric_isp_hist64_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_HIST64_DRV_API_H__ */

