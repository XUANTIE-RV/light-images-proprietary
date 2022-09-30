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

#ifndef __CAMERIC_ISP_DRV_RY_API_H__
#define __CAMERIC_ISP_DRV_RY_API_H__

/**
 * @file    cameric_isp_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC ISP driver API.
 *
 *****************************************************************************/
/**
 * @if CAMERIC_LITE
 *
 * @defgroup cameric_isp_drv_api CamerIC ISP lite driver API definitions
 * @{
 *
 * @image html isp_lite.png "Software ISP-lite driver" width=\textwidth
 * @image latex isp_lite.png "Software ISP-lite driver" width=\textwidth
 *
 * @endif
 *
 * @if CAMERIC_FULL
 *
 * @defgroup cameric_isp_drv_api CamerIC ISP driver API definitions
 * @{
 *
 * @image html isp.png "Software ISP driver" width=\textwidth
 * @image latex isp.png "Software ISP driver" width=\textwidth
 *
 * @endif
  *
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif



/******************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This macro defines the number of elements in a gamma-curve.
 *
 *****************************************************************************/
#define CAMERIC_ISP_GAMMA_CURVE_SIZE        17
#define CAMERIC_ISP_GAMMA_RGB_CURVE_SIZE    65

/* @endcond */




/******************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   Enumeration type to configure the ISP working mode.
 *
 *****************************************************************************/
typedef enum CamerIcIspMode_ry_e
{
    CAMERIC_ISP_MODE_INVALID                = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_MODE_RAW                    = 1,        /**< RAW picture with BT.601 sync (ISP bypass) */
    CAMERIC_ISP_MODE_656                    = 2,        /**< ITU-R BT.656 (YUV with embedded sync) */
    CAMERIC_ISP_MODE_601                    = 3,        /**< ITU-R BT.601 (YUV input with H and Vsync signals) */
    CAMERIC_ISP_MODE_BAYER_RGB              = 4,        /**< Bayer RGB processing with H and Vsync signals */
    CAMERIC_ISP_MODE_DATA                   = 5,        /**< data mode (ISP bypass, sync signals interpreted as data enable) */
    CAMERIC_ISP_MODE_RGB656                 = 6,        /**< Bayer RGB processing with BT.656 synchronization */
    CAMERIC_ISP_MODE_RAW656                 = 7,        /**< RAW picture with ITU-R BT.656 synchronization (ISP bypass) */
    CAMERIC_ISP_MODE_MAX                                /**< upper border (only for an internal evaluation) */
} CamerIcIspMode_ry_t;
/* @endcond */



/******************************************************************************/
/**
 * @brief   Enumeration type to configure the edge sampling in ISP
 *          input acquisition.
 *
 *****************************************************************************/
typedef enum CamerIcIspSampleEdge_ry_e
{
    CAMERIC_ISP_SAMPLE_EDGE_INVALID         = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_SAMPLE_EDGE_FALLING         = 1,        /**< sample falling edga */
    CAMERIC_ISP_SAMPLE_EDGE_RISING          = 2,        /**< sample rising edge */
    CAMERIC_ISP_SAMPLE_EDGE_MAX                         /**< upper border (only for an internal evaluation) */
} CamerIcIspSampleEdge_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure the vertical and horizontal
 *          polarity in ISP input acquisition.
 *
 *****************************************************************************/
typedef enum CamerIcIspPolarity_ry_e
{
    CAMERIC_ISP_POLARITY_INVALID            = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_POLARITY_HIGH               = 1,        /**< high active */
    CAMERIC_ISP_POLARITY_LOW                = 2,        /**< low active */
    CAMERIC_ISP_POLARITY_MAX                            /**< upper border (only for an internal evaluation) */
} CamerIcIspPolarity_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure the bayer pattern in the ISP
 *          input acquisition.
 *
 *****************************************************************************/
typedef enum CamerIcIspBayerPattern_ry_e
{
    CAMERIC_ISP_BAYER_PATTERN_INVALID       = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_BAYER_PATTERN_RGRGGBGB      = 1,        /**< 1st line: RGRG... , 2nd line GBGB... , etc. */
    CAMERIC_ISP_BAYER_PATTERN_GRGRBGBG      = 2,        /**< 1st line: GRGR... , 2nd line BGBG... , etc. */
    CAMERIC_ISP_BAYER_PATTERN_GBGBRGRG      = 3,        /**< 1st line: GBGB... , 2nd line RGRG... , etc. */
    CAMERIC_ISP_BAYER_PATTERN_BGBGGRGR      = 4,        /**< 2st line: BGBG... , 2nd line GRGR... , etc. */
    CAMERIC_ISP_BAYER_PATTERN_MAX                       /**< upper border (only for an internal evaluation) */
} CamerIcIspBayerPattern_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure the color subsampling mode in the
 *          ISP input acquisition.
 *
 *****************************************************************************/
typedef enum CamerIcIspColorSubsampling_ry_e
{
    CAMERIC_ISP_CONV422_INVALID             = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_CONV422_COSITED             = 1,        /**< co-sited color subsampling Y0Cb0Cr0 - Y1 */
    CAMERIC_ISP_CONV422_INTERLEAVED         = 2,        /**< interleaved color subsampling Y0Cb0 - Y1Cr1 (not recommended) */
    CAMERIC_ISP_CONV422_NONCOSITED          = 3,        /**< non-cosited color subsampling Y0Cb(0+1)/2 - Y1Cr(0+1)/2 */
    CAMERIC_ISP_CONV422_MAX                             /**< upper border (only for an internal evaluation) */
} CamerIcIspColorSubsampling_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure CCIR sequence in the ISP input
 *          acquisition.
 *
 *****************************************************************************/
typedef enum CamerIcIspCCIRSequence_ry_e
{
    CAMERIC_ISP_CCIR_SEQUENCE_INVALID       = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_CCIR_SEQUENCE_YCbYCr        = 1,        /**< YCbYCr */
    CAMERIC_ISP_CCIR_SEQUENCE_YCrYCb        = 2,        /**< YCrYCb */
    CAMERIC_ISP_CCIR_SEQUENCE_CbYCrY        = 3,        /**< CbYCrY */
    CAMERIC_ISP_CCIR_SEQUENCE_CrYCbY        = 4,        /**< CrYCbY */
    CAMERIC_ISP_CCIR_SEQUENCE_MAX                       /**< upper border (only for an internal evaluation) */
} CamerIcIspCCIRSequence_ry_t;


/******************************************************************************/
/**
 * @brief   Enumeration type to configure field sampling in the ISP input
 *          acquisition.
 *
 *****************************************************************************/
typedef enum CamerIcIspFieldSelection_ry_e
{
    CAMERIC_ISP_FIELD_SELECTION_INVALID     = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_FIELD_SELECTION_BOTH        = 1,        /**< sample all fields (don't care about fields) */
    CAMERIC_ISP_FIELD_SELECTION_EVEN        = 2,        /**< sample only even fields */
    CAMERIC_ISP_FIELD_SELECTION_ODD         = 3,        /**< sample only odd fields */
    CAMERIC_ISP_FIELD_SELECTION_MAX                     /**< upper border (only for an internal evaluation) */
} CamerIcIspFieldSelection_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure camera bus width in the CamerIC.
 *
 *****************************************************************************/
typedef enum CamerIcIspInputSelection_ry_e
{
    CAMERIC_ISP_INPUT_INVALID               = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_INPUT_12BIT                 = 1,        /**< 12 Bit input */
    CAMERIC_ISP_INPUT_10BIT_ZZ              = 2,        /**< 10 Bit input with 2 zereos as LSB's */
    CAMERIC_ISP_INPUT_10BIT_EX              = 3,        /**< 10 Bit input with 2 MSB's as LSB's */
    CAMERIC_ISP_INPUT_8BIT_ZZ               = 4,        /**< 8 Bit input with 4 zeroes as LSB's */
    CAMERIC_ISP_INPUT_8BIT_EX               = 5,        /**< 8 Bit input with 4 MSB's as LSB's */
    CAMERIC_ISP_INPUT_MAX                               /**< upper border (only for an internal evaluation) */
} CamerIcIspInputSelection_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to  configure the input interface selector on
 *          the CamerIC input (if_select).
 *
 *****************************************************************************/
typedef enum CamerIcIspLatencyFifo_ry_e
{
    CAMERIC_ISP_LATENCY_FIFO_INVALID            = 0,    /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_LATENCY_FIFO_INPUT_FORMATTER    = 1,    /**< use input formatter input for latency fifo */
    CAMERIC_ISP_LATENCY_FIFO_DMA_READ           = 2,    /**< use dma rgb read input for latency fifo */
    CAMERIC_ISP_LATENCY_FIFO_MAX                        /**< upper border (only for an internal evaluation) */
} CamerIcIspLatencyFifo_ry_t;

#ifdef ISP_DPF_RAW
/******************************************************************************/
/**
 *
 * @brief   Enumeration type to configure the ISP Nano DPF raw working mode.
 *
 *****************************************************************************/
typedef enum CamerIcIspDpfRaw_ry_e
{
    CAMERIC_ISP_DPF_RAW_DISABLE             = 0,        /**< NANO DPF raw diable */
    CAMERIC_ISP_DPF_RAW_ENABLE              = 1,        /**< NANO DPF raw enable */
    CAMERIC_ISP_DPF_RAW_MAX                             /**< upper border (only for an internal evaluation) */
} CamerIcIspDpfRaw_ry_t;


#endif

#ifdef ISP_DVP_PINMAPPING

/******************************************************************************/
/**
 * @brief   Enumeration type to  configure the DVP pin mapping input interface selector on
 *          the Nano version. (DVP_Pin_Mapping)
 *
 *****************************************************************************/
typedef enum CamerIcIspDvpPinMapping_ry_e
{
    CAMERIC_ISP_DVP_PIN_MAPPING_12TO12          = 0,  /* normal 12-bit external interface */
    CAMERIC_ISP_DVP_PIN_MAPPING_L10TOH10        = 1,  /* mapping Low 10 bit to high 10 bits, append 2 zeros as LSBs */
    CAMERIC_ISP_DVP_PIN_MAPPING_L8TOH8          = 2,  /* mapping Low 8 bits to high 8bits, append 4 zeros as LSBs */
    CAMERIC_ISP_DVP_PIN_MAPPING_M8TOH8          = 3,  /* mapping Middle 8 bits to high 8bits, append 4 zeros as LSBs */
    CAMERIC_ISP_DVP_PIN_MAPPING_MAX                   /**< upper border (only for an internal evaluation) */
}CamerIcIspDvpPinMappig_ry_t;
#endif

/******************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   Enumeration type to configure configure the demosaicing bypass.
 *
 *****************************************************************************/
typedef enum CamerIcIspDemosaicBypass_ry_e
{
    CAMERIC_ISP_DEMOSAIC_INVALID            = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_DEMOSAIC_NORMAL_OPERATION   = 1,        /**< normal operation for RGB Bayer pattern input */
    CAMERIC_ISP_DEMOSAIC_BYPASS             = 2,        /**< demosaicing bypass for Black&White input data */
    CAMERIC_ISP_DEMOSAIC_MAX                            /**< upper border (only for an internal evaluation) */
} CamerIcIspDemosaicBypass_ry_t;
/* @endcond */



/******************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   Enumeration type to configure configure the color conversion range.
 *
 * @note    The color conversion unit - also called color space matrix -
 *          performs a regular RGB to YCbCr 4:4:4 color space conversion. The
 *          nine coefficients take values between -2 and +1.992.
 *
 *          \arg YCbCr range limited output \n
 *          Y    = c0*R + c1*G + c2*B + 64  \n
 *          Cb   = c3*R + c4*G + c5*B + 512 \n
 *          Cr   = c6*R + c7*G + c8*B + 512 \n
 *
 *          \arg YCbCr full range output    \n
 *          Y    = c0*R + c1*G + c2*B       \n
 *          Cb   = c3*R + c4*G + c5*B + 512 \n
 *          Cr   = c6*R + c7*G + c8*B + 512 \n
 *
 *****************************************************************************/
typedef enum CamerIcColorConversionRange_ry_e
{
    CAMERIC_ISP_CCONV_RANGE_INVALID          = 0,       /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_CCONV_RANGE_LIMITED_RANGE    = 1,       /**< YCbCr range limited output according to ITU-R BT.601 standard */
    CAMERIC_ISP_CCONV_RANGE_FULL_RANGE       = 2,       /**< YCbCr full range output */
    CAMERIC_ISP_CCONV_RANGE_MAX                         /**< upper border (only for an internal evaluation) */
} CamerIcColorConversionRange_ry_t;
/* @endcond */



/******************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   A structure to represent a gamma-curve.
 *
 *****************************************************************************/
typedef struct CamerIcGammaCurve_ry_s
{
    uint16_t GammaY[CAMERIC_ISP_GAMMA_CURVE_SIZE];      /**< array of y coordinates */
} CamerIcIspGammaCurve_ry_t;
/* @endcond */



/******************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   Enumeration type to configure the gamma curve segementation.
 *
 *****************************************************************************/
typedef enum CamerIcIspGammaSegmentationMode_ry_e
{
    CAMERIC_ISP_SEGMENTATION_MODE_INVALID       = 0,    /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_SEGMENTATION_MODE_LOGARITHMIC   = 1,    /**< logarithmic segmentation from 0 to 4095
                                                             (64,64,64,64,128,128,128,128,256,256,256,512,512,512,512,512) */
    CAMERIC_ISP_SEGMENTATION_MODE_EQUIDISTANT   = 2,    /**< equidistant segmentation from 0 to 4095
                                                             (256, 256, ... ) */
    CAMERIC_ISP_SEGMENTATION_MODE_MAX                   /**< upper border (only for an internal evaluation) */
} CamerIcIspGammaSegmentationMode_ry_t;
/* @endcond */


/******************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   Enumeration of TPG picture type.
 *
 *****************************************************************************/
typedef enum CamerIcISPTpgImageType_ry_e
{
    CAMERIC_ISP_TPG_IMAGE_TYPE_3X3COLORBLOCK    = 0,    /**< 3 x 3 color block */
    CAMERIC_ISP_TPG_IMAGE_TYPE_COLORBAR         = 1,    /**< color bar */
    CAMERIC_ISP_TPG_IMAGE_TYPE_GRAYBAR          = 2,    /**< gray bar */
    CAMERIC_ISP_TPG_IMAGE_TYPE_GRID             = 3,    /**< highlighted grid */
    CAMERIC_ISP_TPG_IMAGE_TYPE_RANDOM           = 4,    /**< random data */

    CAMERIC_ISP_TPG_IMAGE_TYPE_MAX
} CamerIcISPTpgImageType_ry_t;
/* @endcond */


/******************************************************************************/
/**
 * @brief   Enumeration type to configure the bayer pattern in the TPG
 *
 *****************************************************************************/
typedef enum CamerIcIspTpgBayerPattern_ry_e
{
    CAMERIC_ISP_TPG_BAYER_PATTERN_RGGB      = 0,        /**< 1st line: RGRG... , 2nd line GBGB... , etc. */
    CAMERIC_ISP_TPG_BAYER_PATTERN_GRBG      = 1,        /**< 1st line: GRGR... , 2nd line BGBG... , etc. */
    CAMERIC_ISP_TPG_BAYER_PATTERN_GBRG      = 2,        /**< 1st line: GBGB... , 2nd line RGRG... , etc. */
    CAMERIC_ISP_TPG_BAYER_PATTERN_BGGR      = 3,        /**< 2st line: BGBG... , 2nd line GRGR... , etc. */

    CAMERIC_ISP_TPG_BAYER_PATTERN_MAX                   /**< upper border (only for an internal evaluation) */
} CamerIcIspTpgBayerPattern_ry_t;
/* @endcond */


/******************************************************************************/
/**
 * @brief   Enumeration of data width of TPG.
 *
 *****************************************************************************/
typedef enum CamerIcIspTpgColorDepth_ry_e
{
    CAMERIC_ISP_TPG_8BIT            = 0,        /**< 8  Bit output */
    CAMERIC_ISP_TPG_10BIT           = 1,        /**< 10 Bit output */
    CAMERIC_ISP_TPG_12BIT           = 2,        /**< 12 Bit output */

} CamerIcIspTpgColorDepth_ry_t;
/* @endcond */


/******************************************************************************/
/**
 * @brief   Enumeration of TPG resolution.
 *
 *****************************************************************************/
typedef enum CamerIcIspTpgResolution_ry_e
{
    CAMERIC_ISP_TPG_1080P           = 0,        /**< 1920 x 1080  */
    CAMERIC_ISP_TPG_720P            = 1,        /**< 1280 x 720   */
    CAMERIC_ISP_TPG_4K              = 2,        /**< 3840 x 2160  */
    CAMERIC_ISP_TPG_USER_DEFINED    = 3,        /**< user defined */

} CamerIcIspTpgResolution_ry_t;
/* @endcond */

typedef enum DumpTypeShift_ry_s {
    DUMP_HIST_SHIFT = 0,
    DUMP_EXPM_SHIFT = 1,
    DUMP_WBM_SHIFT = 2,
    DUMP_AFM_SHIFT = 3,
    DUMP_VSM_SHIFT = 4,
    DUMP_AEV2_SHIFT =5,
    DUMP_HIST64_SHIFT = 6,

    DUMP_TYPE_MAX,
} DumpTypeShift_ry_t;


/******************************************************************************/
/**
 * @brief   Stucture of TPG user defined mode.
 *
 *****************************************************************************/
typedef struct CamerIcIspTpgUserDefineMode_ry_s
{
    struct
    {
        uint16_t    total;
        uint16_t    fp;
        uint16_t    syncHeaderWidth;
        uint16_t    bp;
        uint16_t    act;
    }H,V;

} CamerIcIspTpgUserDefineMode_ry_t;
/* @endcond */


/******************************************************************************/
/**
 * @brief   Stucture of TPG configuration.
 *
 *****************************************************************************/
typedef struct CamerIcIspTpgConfig_ry_s
{
    CamerIcISPTpgImageType_ry_t        imageType;
    CamerIcIspTpgBayerPattern_ry_t     bayerPattern;
    CamerIcIspTpgColorDepth_ry_t       colorDepth;
    CamerIcIspTpgResolution_ry_t       resolution;

    uint16_t                        pixleGap;       // image 0 (3x3 block)
    uint16_t                        lineGap;        // image 0 (3x3 block)
    uint16_t                        gapStandard;    // image 1, 2, 3.
    uint32_t                        randomSeed;     // image 4
    uint32_t                        frame_num;

    CamerIcIspTpgUserDefineMode_ry_t   userMode;

} CamerIcIspTpgConfig_ry_t;


/******************************************************************************/
/**
 * @brief   Stucture of DigitalGain configuration.
 *
 *****************************************************************************/
typedef struct CamerIcIspDigitalGainConfig_ry_s {
    bool enable;
    uint16_t gainR;
    uint16_t gainB;
    uint16_t gainGr;
    uint32_t gainGb;

} CamerIcIspDigitalGainConfig_ry_t;

/* @endcond */

/******************************************************************************/
/**
 * @brief   Enumeration type to configure the format
 *
 *****************************************************************************/
typedef enum CamerIcIspDecFormat_ry_e
{
    CAMERIC_ISP_DEC_FORMAT_ARGB8         = 0 ,
    CAMERIC_ISP_DEC_FORMAT_XRGB8         = 1 ,
    CAMERIC_ISP_DEC_FORMAT_AYUV8         = 2 ,
    CAMERIC_ISP_DEC_FORMAT_UYVY          = 3 ,
    CAMERIC_ISP_DEC_FORMAT_YUY2          = 4 ,
    CAMERIC_ISP_DEC_FORMAT_SINGLE_Y_U_V  = 5 ,
    CAMERIC_ISP_DEC_FORMAT_UV_MIX        = 6 ,
    CAMERIC_ISP_DEC_FORMAT_ARGB4         = 7 ,
    CAMERIC_ISP_DEC_FORMAT_XRGB4         = 8 ,
    CAMERIC_ISP_DEC_FORMAT_ARGB1555      = 9 ,
    CAMERIC_ISP_DEC_FORMAT_XRGB1555      = 10,
    CAMERIC_ISP_DEC_FORMAT_RGB565        = 11,
    CAMERIC_ISP_DEC_FORMAT_Z24S8         = 12,
    CAMERIC_ISP_DEC_FORMAT_Z24           = 13,
    CAMERIC_ISP_DEC_FORMAT_Z16           = 14,
    CAMERIC_ISP_DEC_FORMAT_A2RGB10       = 15,   //Y410
    CAMERIC_ISP_DEC_FORMAT_BAYER         = 16,
    CAMERIC_ISP_DEC_FORMAT_FLOAT16       = 17,
    CAMERIC_ISP_DEC_FORMAT_COEFFICIENT   = 18,
    CAMERIC_ISP_DEC_FORMAT_ARGB16        = 19,   // Y416
    CAMERIC_ISP_DEC_FORMAT_Y216          = 20,
    CAMERIC_ISP_DEC_FORMAT_X2RGB10       = 21,
    CAMERIC_ISP_DEC_FORMAT_G2_Y          = 22,
    CAMERIC_ISP_DEC_FORMAT_G2_UV         = 23,
    CAMERIC_ISP_DEC_FORMAT_MAX
}CamerIcIspDecFormat_ry_t;

/******************************************************************************/
/**
 * @brief   Enumeration type to configure the Bit Depth
 *
 *****************************************************************************/
typedef enum CamerIcIspDecBitDepth_ry_e
{
    CAMERIC_ISP_DEC_BIT_DEPTH_8_BIT  = 0,
    CAMERIC_ISP_DEC_BIT_DEPTH_10_BIT = 1,
    CAMERIC_ISP_DEC_BIT_DEPTH_12_BIT = 2,
    CAMERIC_ISP_DEC_BIT_DEPTH_14_BIT = 3,
    CAMERIC_ISP_DEC_BIT_DEPTH_16_BIT = 4,
    CAMERIC_ISP_DEC_BIT_DEPTH_MAX
}CamerIcIspDecBitDepth_ry_t;

/******************************************************************************/
/**
 * @brief   Enumeration type to configure the Tile Mode
 *
 *****************************************************************************/
typedef enum CamerIcIspDecTileMode_ry_e
{
    CAMERIC_ISP_DEC_TILE_MODE_8x8_X_MAJOR  = 0,
    CAMERIC_ISP_DEC_TILE_MODE_8x8_Y_MAJOR  = 1,
    CAMERIC_ISP_DEC_TILE_MODE_16x4         = 2,
    CAMERIC_ISP_DEC_TILE_MODE_8x4          = 3,
    CAMERIC_ISP_DEC_TILE_MODE_4x8          = 4,
    CAMERIC_ISP_DEC_TILE_MODE_4x4          = 5,
    CAMERIC_ISP_DEC_TILE_MODE_16x4_RASTER  = 6,
    CAMERIC_ISP_DEC_TILE_MODE_64x4         = 7,
    CAMERIC_ISP_DEC_TILE_MODE_32x4         = 8,
    CAMERIC_ISP_DEC_TILE_MODE_256x1_RASTER = 9,
    CAMERIC_ISP_DEC_TILE_MODE_128x1_RASTER = 10,
    CAMERIC_ISP_DEC_TILE_MODE_64x4_RASTER  = 11,
    CAMERIC_ISP_DEC_TILE_MODE_256x2_RASTER = 12,
    CAMERIC_ISP_DEC_TILE_MODE_128x2_RASTER = 13,
    CAMERIC_ISP_DEC_TILE_MODE_128x4_RASTER = 14,
    CAMERIC_ISP_DEC_TILE_MODE_64x1_RASTER  = 15,
    CAMERIC_ISP_DEC_TILE_MODE_16x8           = 16,
    CAMERIC_ISP_DEC_TILE_MODE_8x16           = 17,
    CAMERIC_ISP_DEC_TILE_MODE_512x1_RASTER = 18,
    CAMERIC_ISP_DEC_TILE_MODE_32x4_RASTER  = 19,
    CAMERIC_ISP_DEC_TILE_MODE_64x2_RASTER  = 20,
    CAMERIC_ISP_DEC_TILE_MODE_32x2_RASTER  = 21,
    CAMERIC_ISP_DEC_TILE_MODE_32x1_RASTER  = 22,
    CAMERIC_ISP_DEC_TILE_MODE_16x1_RASTER  = 23,
    CAMERIC_ISP_DEC_TILE_MODE_128x4          = 24,
    CAMERIC_ISP_DEC_TILE_MODE_256x4          = 25,
    CAMERIC_ISP_DEC_TILE_MODE_512x4          = 26,
    CAMERIC_ISP_DEC_TILE_MODE_16x16          = 27,
    CAMERIC_ISP_DEC_TILE_MODE_32x16          = 28,
    CAMERIC_ISP_DEC_TILE_MODE_64x16          = 29,
    CAMERIC_ISP_DEC_TILE_MODE_128x8          = 30,
    CAMERIC_ISP_DEC_TILE_MODE_8x4S         = 31,
    CAMERIC_ISP_DEC_TILE_MODE_16x4S        = 32,
    CAMERIC_ISP_DEC_TILE_MODE_TILEYF_128B  = 33,
    CAMERIC_ISP_DEC_TILE_MODE_TILEYF_256B  = 34,
    CAMERIC_ISP_DEC_TILE_MODE_MAX,
    CAMERIC_ISP_DEC_TILE_MODE_UNDEFINED    = -1
}CamerIcIspDecTileMode_ry_t;

/******************************************************************************/
/**
 * @brief   Enumeration type to configure the Align Size
 *
 *****************************************************************************/
typedef enum CamerIcIspDecAlignMode_ry_e
{
    CAMERIC_ISP_DEC_ALIGN_SIZE_1_BYTE  = 0,
    CAMERIC_ISP_DEC_ALIGN_SIZE_16_BYTE = 1,
    CAMERIC_ISP_DEC_ALIGN_SIZE_32_BYTE = 2,
    CAMERIC_ISP_DEC_ALIGN_SIZE_64_BYTE = 3,
    CAMERIC_ISP_DEC_ALIGN_SIZE_256_BYTE = 4,
    CAMERIC_ISP_DEC_ALIGN_SIZE_512_BYTE = 5,
    CAMERIC_ISP_DEC_ALIGN_SIZE_MAX
}CamerIcIspDecAlignMode_ry_t;

/******************************************************************************/
/**
 * @brief   Stucture of DEC control.
 *
 *****************************************************************************/
typedef struct CamerIcIspDecControl_ry_s
{
    bool_t                         disableRamClockGating;
    bool_t                         disableModuleClockGating;
    bool_t                         disableCompression;
    bool_t                         disableDebugRegisters;
    bool_t                         disableCachePrefetch;
    bool_t                         disableDCache;

} CamerIcIspDecControl_ry_t;

/******************************************************************************/
/**
 * @brief   Stucture of DEC control_ex.
 *
 *****************************************************************************/
typedef struct CamerIcIspDecControl_ex_ry_s
{
    bool_t                         enableEndAddressRangeCheck;
    bool_t                         writeMissPolicy;
    bool_t                         readMissPolicy;

} CamerIcIspDecControl_ex_ry_t;

/******************************************************************************/
/**
 * @brief   Stucture of DEC control_ex2.
 *
 *****************************************************************************/
typedef struct CamerIcIspDecControl_ex2_ry_s
{
    uint8_t                         tileStatusReadId;
    uint8_t                         tileStatusWriteId;

} CamerIcIspDecControl_ex2_ry_t;

/******************************************************************************/
/**
 * @brief   Stucture of DEC write configuration.
 *
 *****************************************************************************/
typedef struct CamerIcIspDecWriteConfig_ry_s
{
    bool_t                          enable;
    CamerIcIspDecFormat_ry_t           format;
    CamerIcIspDecAlignMode_ry_t        alignMode;
    CamerIcIspDecTileMode_ry_t         tileMode;


} CamerIcIspDecWriteConfig_ry_t;

/******************************************************************************/
/**
 * @brief   Stucture of DEC write configuration ex.
 *
 *****************************************************************************/
typedef struct CamerIcIspDecWriteExConfig_ry_s
{
    CamerIcIspDecBitDepth_ry_t         bitDepth;

} CamerIcIspDecWriteExConfig_ry_t;

/******************************************************************************/
/**
 * @brief   Stucture of DEC read configuration.
 *
 *****************************************************************************/
typedef struct CamerIcIspDecReadConfig_ry_s
{
    bool_t                          enable;
    CamerIcIspDecFormat_ry_t           format;
    CamerIcIspDecAlignMode_ry_t        alignMode;
    CamerIcIspDecTileMode_ry_t         tileMode;


} CamerIcIspDecReadConfig_ry_t;

/******************************************************************************/
/**
 * @brief   Stucture of DEC read configuration ex.
 *
 *****************************************************************************/
typedef struct CamerIcIspDecReadExConfig_ry_s
{
    CamerIcIspDecBitDepth_ry_t         bitDepth;

} CamerIcIspDecReadExConfig_ry_t;
/* @endcond */


/*****************************************************************************/
/**
 * @brief   This function registers a Request-Callback at the CamerIC ISP
 *          Module. A request callback is called if the driver needs an
 *          interaction from the application layer (i.e. a new data buffer
 *          to fill, please also @ref CamerIcRequestId_ry_e).
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
 *                              request callback
 *
 *****************************************************************************/
extern RESULT CamerIcIspRegisterRequestCb_ry
(
    CamerIcDrvHandle_ry_t      handle,
    CamerIcRequestFunc_ry_t    func,
    void                    *pUserContext
);



/*****************************************************************************/
/**
 * @brief   This functions deregisters/releases a registered Request-Callback
 *          at CamerIc ISP Module.
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
extern RESULT CamerIcIspDeRegisterRequestCb_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 * @brief   This functions registers an Event-Callback at CamerIC ISP
 *          Module. An event callback is called if the driver needs to
 *          inform the application layer about an asynchronous event or
 *          an error situation (see @ref CamerIcEventId_ry_e).
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
 *                              event callback (maybe the driver is already running)
 *
 *****************************************************************************/
extern RESULT CamerIcIspRegisterEventCb_ry
(
    CamerIcDrvHandle_ry_t  handle,
    CamerIcEventFunc_ry_t  func,
    void                *pUserContext
);



/*****************************************************************************/
/**
 * @brief   This functions deregisters/releases a registered Event-Callback
 *          at CamerIC ISP Module.
 *
 * @param   handle              CamerIC driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to deregister the
 *                              event callback (maybe the driver is still running)
 *
 *****************************************************************************/
extern RESULT CamerIcIspDeRegisterEventCb_ry
(
    CamerIcDrvHandle_ry_t handle
);

/*****************************************************************************/
/**
 * @brief   This function will enable CamerIC ISP Module.
 *
 * @param   handle              CamerIC driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  true                operation succeded
 * @retval  false               operation failed
 *
 *****************************************************************************/
extern bool CamerIcIsIspEnable_ry
(
    CamerIcDrvHandle_ry_t handle
);

/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function configures the ISP working mode.
 *
 * @param   handle              CamerIC driver handle
 * @param   mode                new working mode
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to configure working
 *                              mode (maybe the driver is already running)
 * @retval  RET_NOTSUPP         selected working mode is not supported
 *
 *****************************************************************************/
extern RESULT CamerIcIspSetMode_ry
(
    CamerIcDrvHandle_ry_t      handle,
    const CamerIcIspMode_ry_t  mode
);
/* @endcond */

/*****************************************************************************/
/**
 * @brief   This function configures the CamerIC ISP input acquisition module.
 *
 * @param   handle              CamerIC driver handle
 * @param   tpg_enable          tpg enable flag
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 *
 *****************************************************************************/
RESULT CamerIcIspSetTpgBypass_ry
(
    CamerIcDrvHandle_ry_t                  handle,
    uint32_t                            tpg_enable
);

/*****************************************************************************/
/**
 * @brief   This function configures the CamerIC ISP Mcm write0 .
 *
 * @param   handle              CamerIC driver handle
 * @param   width               mcm write0 width
 * @param   height               mcm write0 height
 * @param   format               mcm write0 format
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 *
 *****************************************************************************/
RESULT CamerIcIspCfgMcmWr0_ry
(
    CamerIcDrvHandle_ry_t              handle,
    uint16_t width,
    uint16_t height,
    uint16_t  format
);

/*****************************************************************************/
/**
 * @brief   This function configures the CamerIC ISP Mcm write1 .
 *
 * @param   handle              CamerIC driver handle
 * @param   width                mcm write1 width
 * @param   height               mcm write1 height
 * @param   format               mcm write1 format
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 *
 *****************************************************************************/
RESULT CamerIcIspCfgMcmWr1_ry
(
    CamerIcDrvHandle_ry_t              handle,
    uint16_t width,
    uint16_t height,
    uint16_t  format
);

/*****************************************************************************/
/**
 * @brief   This function configures the CamerIC ISP Mcm g2 channel write0 .
 *
 * @param   handle              CamerIC driver handle
 * @param   width                mcm g2 channel write0 width
 * @param   height               mcm g2 channel write0 height
 * @param   format               mcm g2 channel write0 format
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 *
 *****************************************************************************/
RESULT CamerIcIspCfgMcmG2Wr0_ry
(
    CamerIcDrvHandle_ry_t              handle,
    uint16_t width,
    uint16_t height,
    uint16_t  format
);

/*****************************************************************************/
/**
 * @brief   This function configures the CamerIC ISP Mcm g2 channel write1 .
 *
 * @param   handle              CamerIC driver handle
 * @param   width                mcm g2 channel write1 width
 * @param   height               mcm g2 channel write1 height
 * @param   format               mcm g2 channel write1 format
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 *
 *****************************************************************************/
RESULT CamerIcIspCfgMcmG2Wr1_ry
(
    CamerIcDrvHandle_ry_t              handle,
    uint16_t width,
    uint16_t height,
    uint16_t  format
);

/*****************************************************************************/
/**
 * @brief   This function configures the CamerIC ISP Mcm rd format .
 *
 * @param   handle              CamerIC driver handle
 * @param   format               mcm rd format
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 *
 *****************************************************************************/
RESULT CamerIcIspSetMcmRdFmt_ry
(
    CamerIcDrvHandle_ry_t              handle,
    uint16_t  format
);

/*****************************************************************************/
/**
 * @brief   This function configures the CamerIC ISP Mcm bypass sensor switch .
 *
 * @param   handle              CamerIC driver handle
 * @param   bypassSwitch        Bypass switch
                                0000: sensor0 bypass
                                0001: sensor1 bypass
                                ��
                                1111: sensor15 bypass if any
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 *
 *****************************************************************************/
RESULT CamerIcIspSetMcmBypassSwitch_ry
(
    CamerIcDrvHandle_ry_t              handle,
    uint8_t  bypassSwitch
);

/*****************************************************************************/
/**
 * @brief   This function configures the CamerIC ISP input acquisition module.
 *
 * @param   handle              CamerIC driver handle
 * @param   enable          	mcm bypass enable
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 *
 *****************************************************************************/
RESULT CamerIcIspSetMcmBypass_ry
(
    CamerIcDrvHandle_ry_t              handle,
	uint32_t enable
);


/*****************************************************************************/
/**
 * @brief   This function configures the CamerIC ISP input acquisition module.
 *
 * @param   handle              CamerIC driver handle
 * @param   sampleEdge          sample edge (@ref CamerIcIspSampleEdge_ry_e)
 * @param   hSyncPol            horizontal sync polarity (@ref CamerIcIspPolarity_ry_e)
 * @param   vSyncPol            vertical sync polarity (@ref CamerIcIspPolarity_ry_e)
 * @param   bayerPattern        bayer pattern (@ref CamerIcIspBayerPattern_ry_e)
 * @param   subSampling         color subsampling mode (@ref CamerIcIspColorSubsampling_ry_e)
 * @param   seqCCIR             CCIR output sequence (@ref CamerIcIspCCIRSequence_ry_e)
 * @param   fieldSelection      field sampling (@ref CamerIcIspFieldSelection_ry_e)
 * @param   inputSelection      input format (@ref CamerIcIspInputSelection_ry_e)
 * @param   latencyFifo         latency fifo input (@ref CamerIcIspLatencyFifo_ry_e)
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to configure working
 *                              mode (maybe the driver is already running)
 * @retval  RET_NOTSUPP         a configuration is not supported
 *
 *****************************************************************************/
extern RESULT CamerIcIspSetAcqProperties_ry
(
    CamerIcDrvHandle_ry_t                  handle,
    const CamerIcIspSampleEdge_ry_t        sampleEdge,
    const CamerIcIspPolarity_ry_t          hSyncPol,
    const CamerIcIspPolarity_ry_t          vSyncPol,
    const CamerIcIspBayerPattern_ry_t      bayerPattern,
    const CamerIcIspColorSubsampling_ry_t  subSampling,
    const CamerIcIspCCIRSequence_ry_t      seqCCIR,
    const CamerIcIspFieldSelection_ry_t    fieldSelection,
    const CamerIcIspInputSelection_ry_t    inputSelection,
    const CamerIcIspLatencyFifo_ry_t       latencyFifo,
    const uint32_t stitchingMode
);

#ifdef ISP_DPF_RAW

/*****************************************************************************/
/**
 * @brief   This function configures the ISP DPF raw out mode.
 *
 * @param   handle              CamerIC driver handle
 * @param   mode                DPF raw out control
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to configure working
 *                              mode (maybe the driver is already running)
 * @retval  RET_NOTSUPP         selected working mode is not supported
 *
 *****************************************************************************/
extern RESULT CamerIcIspDpfRawCtrlNano_ry
(
    CamerIcDrvHandle_ry_t        handle,
    const CamerIcIspDpfRaw_ry_t  mode
);

#endif

#ifdef ISP_DVP_PINMAPPING
/*****************************************************************************/
/**
 * @brief   This function configures the CamerIC ISP input acquisition module for Nano specific controls
 *
 * @param   handle              CamerIC driver handle
 * @param   dvpPinMapping       Dvp pin mapping input (@ref CamerIcIspDvpPinMappig_ry_t)
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to configure working
 *                              mode (maybe the driver is already running)
 * @retval  RET_NOTSUPP         a configuration is not supported
 *
 *****************************************************************************/
extern RESULT CamerIcIspSetAcqPropertiesNano_ry
(
    CamerIcDrvHandle_ry_t                  handle,
    const CamerIcIspDvpPinMappig_ry_t      dvpPinMapping
);

/*****************************************************************************/
/**
 * @brief   Dump function for the CamerIC ISP input acquisition acq registers for Nano specific controls
 *
 * @param   handle              CamerIC driver handle
 * @param   const char *        dump_name
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to configure working
 *                              mode (maybe the driver is already running)
 * @retval  RET_NOTSUPP         a configuration is not supported
 *
 *****************************************************************************/
extern RESULT CamerIcIspDumpAcqPropNanoData_ry
(
    CamerIcDrvHandle_ry_t                      handle,
    const char *                            dump_name
);
#endif


/*****************************************************************************/
/**
 * @brief   This function configures the CamerIC ISP input resolution.
 *
 * @note    It's possible to crop the image by using a smaller resolution.
 *
 * @param   handle              CamerIC driver handle
 * @param   hOffset             horizontal offset
 * @param   vOffset             vertical offset
 * @param   height              height
 * @param   width               width
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to change the input
 *                              window (maybe the driver is already running)
 *
 *****************************************************************************/
extern RESULT CamerIcIspSetAcqResolution_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const uint16_t      hOffset,
    const uint16_t      vOffset,
    const uint16_t      width,
    const uint16_t      height
);



/*****************************************************************************/
/**
 * @brief   This function configures the CamerIC ISP output formatter window.
 *
 * @param   handle              CamerIC driver handle
 * @param   hOffset             horizontal offset
 * @param   vOffset             vertical offset
 * @param   height              height
 * @param   width               width
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to change the output
 *                              window (maybe the driver is already running)
 *
 *****************************************************************************/
extern RESULT CamerIcIspSetOutputFormatterResolution_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const uint16_t      hOffset,
    const uint16_t      vOffset,
    const uint16_t      width,
    const uint16_t      height
);



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function sets CamerIc ISP image stabilization output window.
 *
 * @param   handle              CamerIc driver handle
 * @param   hOffset             horizontal offset
 * @param   vOffset             vertical offset
 * @param   height              height
 * @param   width               width
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to change the image
 *                              stabilization outpu window (maybe the driver
 *                              is already running)
 *
 *****************************************************************************/
extern RESULT CamerIcIspSetImageStabilizationResolution_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const uint16_t      hOffset,
    const uint16_t      vOffset,
    const uint16_t      width,
    const uint16_t      height
);
/* @endcond */


/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function sets the demosaicing working mode and threshold.
 *
 * @param   handle              CamerIc driver handle
 * @param   pBypassMode         Bypass mode
 * @param   pThreshold          Demosaicing threshold
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to change the
 *                              demosaicing mode or demosaiing threshold
 *                              (maybe the driver is already running)
 * @retval  RET_NOTSUPP         demosaicing mode is not supported
 *
 *****************************************************************************/
extern RESULT CamerIcIspGetDemosaic_ry
(
    CamerIcDrvHandle_ry_t            handle,
    CamerIcIspDemosaicBypass_ry_t    *pBypassMode,
    uint8_t                       *pThreshold
);
/* @endcond */


/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function sets the demosaicing working mode and threshold.
 *
 * @param   handle              CamerIc driver handle
 * @param   BypassMode          bypass mode to set
 * @param   Threshold           Demosaicing threshold to set
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to change the
 *                              demosaicing mode or demosaiing threshold
 *                              (maybe the driver is already running)
 * @retval  RET_NOTSUPP         demosaicing mode is not supported
 *
 *****************************************************************************/
extern RESULT CamerIcIspSetDemosaic_ry
(
    CamerIcDrvHandle_ry_t                  handle,
    const CamerIcIspDemosaicBypass_ry_t    BypassMode,
    const uint8_t                       Threshold
);
/* @endcond */



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function sets the color conversion range.
 *
 * @note    The color conversion unit - also called color space matrix -
 *          performs a regular RGB to YCbCr 4:4:4 color space conversion. The
 *          nine coefficients take values between -2 and +1.992.
 *
 *          \arg YCbCr range limited output \n
 *          Y    = c0*R + c1*G + c2*B + 64  \n
 *          Cb   = c3*R + c4*G + c5*B + 512 \n
 *          Cr   = c6*R + c7*G + c8*B + 512 \n
 *
 *          \arg YCbCr full range output    \n
 *          Y    = c0*R + c1*G + c2*B       \n
 *          Cb   = c3*R + c4*G + c5*B + 512 \n
 *          Cr   = c6*R + c7*G + c8*B + 512 \n
 *
 *          \arg default matrix             \n
 *          ( 0x021 0x040 0x00D )       (   \n
 *          ( 0x1ED 0x1DB 0x038 )   =   (   \n
 *          ( 0x038 0x1D1 0x1F7 )       (   \n
 *
 * @param   handle              CamerIc driver handle
 * @param   YConvRange          luminance conversion range
 * @param   CrConvRange         chrominance conversion range
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to change the color
 *                              conversion matrix (maybe the driver is already
 *                              running)
 * @retval  RET_NOTSUPP         conversion range is not supported
 *
 *****************************************************************************/
extern RESULT CamerIcIspSetColorConversionRange_ry
(
    CamerIcDrvHandle_ry_t                  handle,
    const CamerIcColorConversionRange_ry_t YConvRange,
    const CamerIcColorConversionRange_ry_t CrConvRange
);
/* @endcond */



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function returns the currently configured color conversion
 *          coefficients.
 *
 * @param   handle              CamerIc driver handle
 * @param   pCConvCoefficients  storage class for color conversion coefficients
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to change the color
 *                              conversion matrix (maybe the driver is not
 *                              initialized)
 *
 *****************************************************************************/
extern RESULT CamerIcIspGetColorConversionCoefficients_ry
(
    CamerIcDrvHandle_ry_t      handle,
    CamerIc3x3FloatMatrix_ry_t *pCConvCoefficients
);
/* @endcond */



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function sets the color conversion coefficients.
 *
 * @param   handle      CamerIc driver handle
 * @param   pCConvCoefficients  Color conversion coefficients to set
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to change the color
 *                              conversion matrix (maybe the driver is already
 *                              running)
 *
 * @endif
 *
 *****************************************************************************/
extern RESULT CamerIcIspSetColorConversionCoefficients_ry
(
    CamerIcDrvHandle_ry_t              handle,
    const CamerIc3x3FloatMatrix_ry_t   *pCConvCoefficients
);
/* @endcond */



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function returns the currently configured cross-talk
 *          coefficients.
 *
 * @param   handle              CamerIc driver handle
 * @param   pCTalkCoefficients  Cross-talk coefficients
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to read the cross
 *                              talk matrix (maybe the driver is not initialized)
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 * @endif
 *
 *****************************************************************************/
extern RESULT CamerIcIspGetCrossTalkCoefficients_ry
(
    CamerIcDrvHandle_ry_t  handle,
    CamerIc3x3Matrix_ry_t  *pCTalkCoefficients
);
/* @endcond */



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This functions sets the cross-talk coefficients.
 *
 * @param   handle              CamerIc driver handle
 * @param   pCTalkCoefficients  Cross-talk coefficients
 *
 * @return                      Return the result of the function call.
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to read the cross
 *                              talk matrix (maybe the driver is not initialized)
 *
 *****************************************************************************/
extern RESULT CamerIcIspSetCrossTalkCoefficients_ry
(
    CamerIcDrvHandle_ry_t          handle,
    const CamerIc3x3Matrix_ry_t    *pCTalkCoefficients
);
/* @endcond */



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function returns the currently configured cross-talk
 *          offsets.
 *
 * @param   handle              CamerIc driver handle
 * @param   pCrossTalkOffset    Cross-talk offsets
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to read the cross
 *                              talk matrix (maybe the driver is not initialized)
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 * @endif
 *
 *****************************************************************************/
extern RESULT CamerIcIspGetCrossTalkOffset_ry
(
    CamerIcDrvHandle_ry_t          handle,
    CamerIcXTalkOffset_ry_t        *pCrossTalkOffset
);
/* @endcond */



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This functions sets the cross-talk offsets.
 *
 * @param   handle              CamerIc driver handle
 * @param   pCrossTalkOffset    Cross-talk offsets
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to set the cross
 *                              talk offsets (maybe the driver is already
 *                              running)
 *
 *****************************************************************************/
extern RESULT CamerIcIspSetCrossTalkOffset_ry
(
    CamerIcDrvHandle_ry_t          handle,
    const CamerIcXTalkOffset_ry_t  *pCrossTalkOffset
);
/* @endcond */



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This functions enables or disables the ISP AWB module.
 *
 * @param   handle              CamerIc driver handle
 * @param   enable              BOOL_TRUE enables ISP AWB module,
 *                              BOOL_FALSE bypass the ISP AWB module
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to enable or disable
 *                              AWB module
 *
 *****************************************************************************/
extern RESULT CamerIcIspActivateWB_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const bool_t        enable
);
/* @endcond */



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This functions returns wether the ISP AWB module is enable or not.
 *
 * @param   handle              CamerIc driver handle
 * @param   pIsEnabled          Pointer to value to store current ISP AWB state
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to read AWB state
 *                              (maybe driver not initialized)
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
extern RESULT CamerIcIspIsWBActivated_ry
(
    CamerIcDrvHandle_ry_t  handle,
    bool_t              *pIsEnabled
);
/* @endcond */


/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function eanbles the gamma-out correction.
 *
 * @param   handle              CamerIc driver handle
 * @param   enable              BOOL_TRUE to enable, BOOL_FALSE to disable
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to switch gamma-out
 *
 *****************************************************************************/
extern RESULT CamerIcIspGammaOutEnable
(
    CamerIcDrvHandle_ry_t  handle
);
/* @endcond */


/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function disables the gamma-out correction.
 *
 * @param   handle              CamerIc driver handle
 * @param   enable              BOOL_TRUE to enable, BOOL_FALSE to disable
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to switch gamma-out
 *
 *****************************************************************************/
extern RESULT CamerIcIspGammaOutDisable
(
    CamerIcDrvHandle_ry_t  handle
);
/* @endcond */

/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function eanbles/disables the gamma-out correction.
 *
 * @param   handle              CamerIc driver handle
 * @param   enable              BOOL_TRUE to enable, BOOL_FALSE to disable
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to switch gamma-out
 *
 *****************************************************************************/
extern RESULT CamerIcIspActivateGammaOut_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const bool_t        enable
);
/* @endcond */



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function returns the gamma-out status.
 *
 * @param   handle              CamerIc driver handle
 * @param   pIsEnabled          Pointer to value to store current gamma-out
 *                              state
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to read gamma-out
 *                              status
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
extern RESULT CamerIcIspIsGammaOutActivated_ry
(
    CamerIcDrvHandle_ry_t  handle,
    bool_t                  *pIsEnabled
);
/* @endcond */



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function sets a gamma out curve.
 *
 * @param   handle              CamerIc driver handle
 * @param   mode                segmentation of the x-axis
 *                              (@ref CamerIcIspGammaSegmentationMode_ry_e)
 * @param   pCurve              pointer to a gamma-out curve
 *                              (@ref CamerIcGammaCurve_ry_s)
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to read gamma-out
 *                              status
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
extern RESULT CamerIcIspSetGammOutCurve_ry
(
    CamerIcDrvHandle_ry_t                      handle,
    const CamerIcIspGammaSegmentationMode_ry_t mode,
    const CamerIcIspGammaCurve_ry_t            *pCurve
);
/* @endcond */



/*****************************************************************************/
/**
 * @cond    CAMERIC_FULL
 *
 * @brief   This function dumps measure to file.
 *
 * @param   handle              CamerIc driver handle
 * @param   dump_name           File name of dump
 * @param   dump_hism           hist measure data dump enable
 * @param   dump_expm           exp measure data dump enable
 * @param   dump_wbm            wb measure data dump enable

 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_FAILURE         common error occured
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_STATE     driver is in wrong state to read gamma-out
 *                              status
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/

/******************************************************************************
 * CamerIcIspDumpMeasureData_ry()
 *****************************************************************************/
extern RESULT CamerIcIspDumpMeasureData_ry
(
    CamerIcDrvHandle_ry_t                      handle,
    const char *                            dump_name,
    unsigned int                            dump_mask
);

extern RESULT CamerIcIspEnableDigitalGain_ry(
    CamerIcDrvHandle_ry_t handle,
    bool enbale
);

extern RESULT CamerIcIspDigitalGainIsActivated_ry
(
    CamerIcDrvHandle_ry_t      handle,
    bool_t                  *pIsEnabled
);

extern RESULT CamerIcIspSetDigitalGain_ry(
    CamerIcDrvHandle_ry_t handle,
    CamerIcIspDigitalGainConfig_ry_t *pDigiCfg
);

extern RESULT CamerIcIspGetDigitalGain_ry
(
	CamerIcDrvHandle_ry_t handle,
	CamerIcIspDigitalGainConfig_ry_t *pDigiCfg
);


#ifdef __cplusplus
}
#endif

/* @} cameric_isp_drv_api */

#endif /* __CAMERIC_ISP_DRV_RY_API_H__ */

