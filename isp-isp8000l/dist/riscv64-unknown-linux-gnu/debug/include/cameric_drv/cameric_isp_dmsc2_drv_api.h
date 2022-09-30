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

#ifndef __CAMERIC_ISP_DMSC2_DRV_API_H__
#define __CAMERIC_ISP_DMSC2_DRV_API_H__

/**
 * @cond    cameric_isp_dmsc
 *
 * @file 	cameric_isp_dmsc_drv_api.h
 *
 * @brief	This file contains the CamerIc ISP DMSC driver API definitions
 *
 *****************************************************************************/
/**
 * @defgroup cameric_isp_dmsc_drv_api CamerIc ISP DMSC driver API definitions
 * @{
 *
 * A significant challenge for low profile lenses is to minimize lens shading
 * artifacts, also known as "vignetting". Lens shading artifacts are caused by
 * decreased light intensity in the peripheral regions of the sensor due to
 * the inability of the lens to focus the light in those areas in comparison
 * to the centre region. Lens shading artifacts are minimized by image data
 * processing with a lens shading correction algorithm.
 *
 * @image html dmsc.png "Overview of the CamerIC ISP DMSC driver" width=\textwidth
 * @image latex dmsc.png "Overview of the CamerIC ISP DMSC driver" width=\textwidth
 *
 * Lens shading is different for each of its color components, since sensor
 * produces no perfect response in all three color channels. Therefore the
 * lens shading correction is alternatively performed identically for the
 * four color components of the RGB Bayer input signal or calibrated
 * independently for the color components RGB.
 *
 * The aim of the lens shading correction algorithm is to achieve a constant
 * sensitivity across the entire frame after correction. Therefore each incoming
 * pixel value PIN(x,y) is multiplied by a correction factor F(x,y). The
 * correction factor depends on the coordinates of the pixel within the frame.
 *
 * The corrected pixel value PCOR(x,y) is calculated according:
 *
 * PCOR(x,y) = PIN(x,y) * F(x,y)                     (1)
 *
 * In order to increase the precision of the correction function, the frame
 * is divided into 16 sectors in x and y dimension. The coordinates of each
 * sector are programmable. Furthermore the lens shading correction parameters
 * are programmable independently for each sector and for each color component
 * within a sector. The sector coordinates apply for each color component.
 * This unit will be designed so that either the lens shading correction parameters
 * apply for all color components or each color component gets its own lens shading
 * correction parameters.
 *
 * @image html dmsc_sectors.png "Lens Shading Correction Sectors" width=\textwidth
 * @image latex dmsc_sectors.png "Lens Shading Correction Sectors" width=\textwidth
 *
 * To reduce hardware effort, position and size of mirrored sectors related to the
 * frame center are equivalent. This means for example that size and position of
 * sector X1 is equivalent to X16 related to frame center and Y3 to Y14. However
 * the correction factors are independent for each sector. To reduce the memory
 * for storing the coordinates of the sensor area, the size of each sector is
 * programmed. Furthermore only the sizes of one quarter of the frame is programmed,
 * because the sectors are symmetrical relative to the picture center. The coordinates
 * are calculated by hardware during processing.
 *
 * Within each sector, the correction function F(x,y) can be expressed as a Bilinear
 * Interpolation Function. These functions in different areas are correlated, because
 * of the requirement that the correction function must be continuous and smooth.
 *
 * The lens shading correction unit works on RGB Bayer pattern and is placed after
 * the sensor degamma and the black level correction units.
 *
 * @subsection Functional description
 *
 * The lens shading correction is based on one or more reference frames which have
 * to be captured under dedicated light conditions and a dedicated position of the
 * sensor. The pixels of the captured frame are then evaluated by software and the
 * calculated parameters for the lens shading correction are stored in different
 * tables. It is also possible to use different lens shading correction parameters
 * for different environment conditions, e.g. lightness, light direction or sensor
 * position. Therefore additional reference frames for the different conditions are
 * to be captured and evaluated. The calculated parameters including sector settings
 * can be stored in multiple tables at external memory or Flash device. Thus user
 * can select one of multiple lens shading correction algorithms so that software
 * can update the current required tables within the lens shading correction block.
 * The correction factors at the sector corners as well as the size of the sectors
 * are stored. The correction value for each pixel position is calculated using the
 * bilinear interpolation.
 *
 */

#include <ebase/types.h>
#include <common/return_codes.h>
#include "cameric_isp_drv_api.h"

#ifdef __cplusplus
extern "C"
{
#endif


/*****************************************************************************/
/**
 * @brief  demosaic configuration structure
 *
 *****************************************************************************/
typedef struct CamericIspDmscIntp_t {
     uint16_t intp_dir_thr_min;
     uint16_t intp_dir_thr_max;
} CamericIspDmscIntp_t;

typedef struct CamericIspDmscDemoire_t {
    bool enabled;
    uint8_t demoire_area_thr;
    uint8_t demoire_sat_shrink;
    uint16_t demoire_r2;
    uint16_t demoire_r1;
    uint8_t demoire_t2_shift;
    uint8_t demoire_t1;
    uint16_t demoire_edge_r2;
    uint16_t demoire_edge_r1;
    uint8_t demoire_edge_t2_shift;
    uint16_t demoire_edge_t1;
} CamericIspDmscDemoire_t;

typedef struct CamericIspDmscSharpen_t {
    bool enabled;
    uint16_t sharpen_factor_black;
    uint16_t sharpen_factor_white;
    uint16_t sharpen_clip_black;
    uint16_t sharpen_clip_white;
    uint16_t sharpen_t4_shift;
    uint16_t sharpen_t3;
    uint8_t sharpen_t2_shift;
    uint16_t sharpen_t1;
    uint16_t sharpen_r3;
    uint16_t sharpen_r2;
    uint16_t sharpen_r1;
} CamericIspDmscSharpen_t;

typedef struct CamericIspDmscSharpenLine_t {
	bool enabled;
	uint8_t sharpen_line_shift2;
    uint8_t sharpen_line_shift1;
    uint16_t sharpen_line_t1;
    uint16_t sharpen_line_strength;
    uint16_t sharpen_line_r2;
    uint16_t sharpen_line_r1;
} CamericIspDmscSharpenLine_t;

typedef struct CamericIspDmscGFilter_t {
    uint8_t sharpen_size;
    uint8_t hf_filt_00;
    uint8_t hf_filt_01;
    uint8_t hf_filt_02;
    uint8_t hf_filt_10;
    uint8_t hf_filt_11;
    uint8_t hf_filt_12;
    uint8_t hf_filt_20;
    uint8_t hf_filt_21;
    uint8_t hf_filt_22;
} CamericIspDmscGFilter_t;

typedef struct CamericIspDmscSkin_t {
    bool enabled;
    uint16_t cb_thr_max_2047;
    uint16_t cb_thr_min_2047;
    uint16_t cr_thr_max_2047;
    uint16_t cr_thr_min_2047;
    uint16_t y_thr_max_2047;
    uint16_t y_thr_min_2047;
} CamericIspDmscSkin_t;

typedef struct CamericIspDmscDepurple_t {
    bool enabled;
    bool red_sat, blue_sat;
    uint8_t depurple_sat_shrink;
    uint8_t depurple_thr;
} CamericIspDmscDepurple_t;

typedef struct CamericIspDmscCac_t {
    bool cac_enable;
    uint16_t v_count_start;
    uint16_t h_count_start;
    uint16_t a_red;
    uint16_t a_blue;
    uint16_t b_red;
    uint16_t b_blue;
    uint16_t c_red;
    uint16_t c_blue;
    uint8_t x_ns;
    uint8_t x_nf;
    uint8_t y_ns;
    uint8_t y_nf;
} CamericIspDmscCac_t;

typedef struct CamericIspDemosaicContext {
    bool enable;
    uint8_t demosaic_thr;
    uint8_t denoise_stren;
    CamericIspDmscIntp_t intp;
    CamericIspDmscDemoire_t demoire;
    CamericIspDmscSharpen_t sharpen;
    CamericIspDmscGFilter_t gFilter;
    CamericIspDmscSharpenLine_t sharpenLine;
    CamericIspDmscSkin_t skin;
    CamericIspDmscDepurple_t depurple;
} CamericIspDemosaicContext;

typedef struct CamericIspDmscSharpen2_t {
    CamericIspDmscSharpen_t sharpen;
    uint32_t gdenoise;
    uint32_t gsharpenSize;
} CamericIspDmscSharpen2_t;


extern RESULT CamerIcIspDmscEnable
(
    CamerIcDrvHandle_t handle
);

extern RESULT CamerIcIspDmscDisable
(
    CamerIcDrvHandle_t handle
);

extern RESULT CamerIcIspDmscEnableDemoire(CamerIcDrvHandle_t handle);
extern RESULT CamerIcIspDmscDisableDemoire(CamerIcDrvHandle_t handle);

extern RESULT CamerIcIspDmscGetDemoire
(
    CamerIcDrvHandle_t  handle,
    CamericIspDmscDemoire_t *pDemoircCfg
);

extern RESULT CamerIcIspDmscCfgDemoire
(
    CamerIcDrvHandle_t  handle,
    CamericIspDmscDemoire_t *pDemoircCfg
);

extern RESULT CamerIcIspDmscEnableSharpen(CamerIcDrvHandle_t handle);
extern RESULT CamerIcIspDmscDisableSharpen(CamerIcDrvHandle_t handle);

extern RESULT CamerIcIspDmscGetSharpen(CamerIcDrvHandle_t handle, CamericIspDmscSharpen_t *pSharpenCfg);

extern RESULT CamerIcIspDmscCfgSharpen(CamerIcDrvHandle_t handle, CamericIspDmscSharpen_t *pSharpenCfg);

extern RESULT CamerIcIspDmscCfgSkin
(
    CamerIcDrvHandle_t  handle,
    CamericIspDmscSkin_t *pSkinCfg
);

extern RESULT CamerIcIspDmscGetSkin
(
    CamerIcDrvHandle_t  handle,
    CamericIspDmscSkin_t *pSkinCfg
);

RESULT CamerIcIspDmscSet
(
    CamerIcDrvHandle_t  handle,
    CamericIspDemosaicContext *pDmsc
);

RESULT CamerIcIspGetDmsc
(
    CamerIcDrvHandle_t          handle,
    CamerIcIspDemosaicBypass_t  *pBypassMode,
    uint8_t                     *pDemosaicThreshold
);

RESULT CamerIcIspDmscUpdateAllSettings
(
    CamerIcDrvHandle_t  handle,
    CamericIspDemosaicContext *pDmsc
);

RESULT CamerIcIspDmscGetAllSettings
(
    CamerIcDrvHandle_t  handle,
    CamericIspDemosaicContext *pDmsc
);

RESULT CamericIspDmscSharpenEnable
(
    CamerIcDrvHandle_t  handle
);


RESULT CamericIspDmscSharpenDisable
(
    CamerIcDrvHandle_t  handle
);

RESULT CamericIspDmscSharpenConfig
(
    CamerIcDrvHandle_t  handle,
    CamericIspDmscSharpen2_t *pConfig
);

RESULT CamerIcIspDmscSetInterplation
(
    CamerIcDrvHandle_t                  handle,
    uint16_t max,
    uint16_t min
);

RESULT CamerIcIspDmscCfgGfilter
(
    CamerIcDrvHandle_t handle,
    CamericIspDmscGFilter_t *pGfilter
);

RESULT CamerIcIspDmscGetGfilter(
    CamerIcDrvHandle_t handle,
    CamericIspDmscGFilter_t *pGfilter
) ;

RESULT CamerIcIspDmscCfgSharpenLine
(
    CamerIcDrvHandle_t handle, 
    CamericIspDmscSharpenLine_t *pSharpenLine
);

RESULT CamerIcIspDmscGetSharpenLine
(
    CamerIcDrvHandle_t handle,
    CamericIspDmscSharpenLine_t *pSharpenLine
);

#ifdef __cplusplus
}
#endif

/* @} cameric_isp_dmsc_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_DMSC_DRV_API_H__ */


