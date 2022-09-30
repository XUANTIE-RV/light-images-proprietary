/****************************************************************************
* Copyright 2021-2022 Alibaba Group Holding Limited
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*****************************************************************************/

#ifndef OMX_CsiExt_h
#define OMX_CsiExt_h

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <OMX_Video.h>

typedef enum OMX_CSI_INDEXTYPE {
    OMX_CSI_IndexStartUnused = OMX_IndexVendorStartUnused + 0x00110000,
    OMX_CSI_IndexConfigVideoIntraArea,
    OMX_CSI_IndexConfigVideoRoiArea,
    OMX_CSI_IndexConfigVideoRoiDeltaQp,
    OMX_CSI_IndexConfigVideoRoiQp,
    OMX_CSI_IndexConfigVideoOsd,
    OMX_CSI_IndexParamVideoHevc,
    OMX_CSI_IndexParamVideoVp9,
    OMX_CSI_IndexParamVideoConfig,
    OMX_CSI_IndexParamVideoAvcExt,
    OMX_CSI_IndexParamBufferMode,
    OMX_CSI_IndexParamCompressionMode,
} OMX_CSI_INDEXTYPE;

typedef enum OMX_CSI_VIDEO_CODINGTYPE {
    OMX_CSI_VIDEO_CodingStartUnused = OMX_VIDEO_CodingVendorStartUnused + 0x00110000,
    OMX_CSI_VIDEO_CodingVP6,
    OMX_CSI_VIDEO_CodingAVS,
    OMX_CSI_VIDEO_CodingHEVC,
    OMX_CSI_VIDEO_CodingVP9,
    OMX_CSI_VIDEO_CodingAVS2,
} OMX_CSI_VIDEO_CODINGTYPE;

typedef enum OMX_CSI_COLOR_FORMATTYPE {
    OMX_CSI_COLOR_FormatStartUnused = OMX_COLOR_FormatVendorStartUnused + 0x00110000,
    OMX_CSI_COLOR_FormatYUV420SemiPlanarP010        /* P010 format */
} OMX_CSI_COLOR_FORMATTYPE;

/** Structure for configuring Intra area for 8290/H1/H2 encoder */
typedef struct OMX_CSI_VIDEO_CONFIG_INTRAAREATYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_BOOL bEnable;
    OMX_U32 nTop;       /* Top mb row inside area [0..heightMbs-1]      */
    OMX_U32 nLeft;      /* Left mb row inside area [0..widthMbs-1]      */
    OMX_U32 nBottom;    /* Bottom mb row inside area [top..heightMbs-1] */
    OMX_U32 nRight;     /* Right mb row inside area [left..widthMbs-1]  */
} OMX_CSI_VIDEO_CONFIG_INTRAAREATYPE;

/** Structure for configuring ROI area for 8290/H1/H2 encoder */
typedef struct OMX_CSI_VIDEO_CONFIG_ROIAREATYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_BOOL bEnable;
    OMX_U32 nArea;      /* ROI area number [1..2]                       */
    OMX_U32 nTop;       /* Top mb row inside area [0..heightMbs-1]      */
    OMX_U32 nLeft;      /* Left mb row inside area [0..widthMbs-1]      */
    OMX_U32 nBottom;    /* Bottom mb row inside area [top..heightMbs-1] */
    OMX_U32 nRight;     /* Right mb row inside area [left..widthMbs-1]  */
} OMX_CSI_VIDEO_CONFIG_ROIAREATYPE;

/** Structure for configuring ROI Delta QP for 8290/H1/H2 encoder */
typedef struct OMX_CSI_VIDEO_CONFIG_ROIDELTAQPTYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_U32 nArea;      /* ROI area number [1..2]               */
    OMX_S32 nDeltaQP;   /* QP delta value [-127..0] for VP8     */
                        /*                [-15..0]  for H264    */
} OMX_CSI_VIDEO_CONFIG_ROIDELTAQPTYPE;

/** Structure for configuring ROI Absolute QP for 8290/H1/H2 encoder */
typedef struct OMX_CSI_VIDEO_CONFIG_ROIQPTYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_U32 nArea;      /* ROI area number [1..2]               */
    OMX_S32 nQP;        /* absolute QP value     */
} OMX_CSI_VIDEO_CONFIG_ROIQPTYPE;

typedef struct OMX_CSI_VIDEO_CONFIG_OSDTYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    /** Global alpha value for this osd area, not used for ARGB8888*/
    OMX_U32 nAlpha;
    /** Top left column offset of this osd area */
    OMX_U32 nOffsetX;
    /** Top left row offset of this osd area */
    OMX_U32 nOffsetY;
    /** Global luma Y value for bitmap format */
    OMX_U32 nBitmapY;
    /** Global chroma cb value for bitmap format */
    OMX_U32 nBitmapU;
    /** Global chroma cr value for bitmap format */
    OMX_U32 nBitmapV;
} OMX_CSI_VIDEO_CONFIG_OSDTYPE;

typedef enum OMX_CSI_VIDEO_AVCLEVELTYPEEXT {
    OMX_CSI_VIDEO_AVCLevelUnused = OMX_VIDEO_AVCLevelVendorStartUnused + 0x00110000,
    OMX_CSI_VIDEO_AVCLevel52,   
    OMX_CSI_VIDEO_AVCLevel60,
    OMX_CSI_VIDEO_AVCLevel61,
    OMX_CSI_VIDEO_AVCLevel62
} OMX_CSI_VIDEO_AVCLEVELTYPEEXT;


typedef enum OMX_CSI_VIDEO_HEVCPROFILETYPE {
    OMX_CSI_VIDEO_HEVCProfileMain     = 0x01,   /**< Main profile */
    OMX_CSI_VIDEO_HEVCProfileMain10   = 0x02,   /**< Main10 profile */
    OMX_CSI_VIDEO_HEVCProfileMainStillPicture  = 0x04,   /**< Main still picture profile */
} OMX_CSI_VIDEO_HEVCPROFILETYPE;

typedef enum OMX_CSI_VIDEO_HEVCLEVELTYPE {
    OMX_CSI_VIDEO_HEVCLevel1   = 0x01,     /**< Level 1   */
    OMX_CSI_VIDEO_HEVCLevel2   = 0x02,     /**< Level 2   */
    OMX_CSI_VIDEO_HEVCLevel21  = 0x04,     /**< Level 2.1 */
    OMX_CSI_VIDEO_HEVCLevel3   = 0x08,     /**< Level 3   */
    OMX_CSI_VIDEO_HEVCLevel31  = 0x10,     /**< Level 3.1 */
    OMX_CSI_VIDEO_HEVCLevel4   = 0x20,     /**< Level 4   */
    OMX_CSI_VIDEO_HEVCLevel41  = 0x40,     /**< Level 4.1 */
    OMX_CSI_VIDEO_HEVCLevel5   = 0x80,     /**< Level 5   */
    OMX_CSI_VIDEO_HEVCLevel51  = 0x100,    /**< Level 5.1 */
    OMX_CSI_VIDEO_HEVCLevel52  = 0x200,    /**< Level 5.2 */
    OMX_CSI_VIDEO_HEVCLevel6   = 0x400,    /**< Level 6   */
    OMX_CSI_VIDEO_HEVCLevel61  = 0x800,    /**< Level 6.1 */
    OMX_CSI_VIDEO_HEVCLevel62  = 0x1000,   /**< Level 6.2 */
} OMX_CSI_VIDEO_HEVCLEVELTYPE;

/**
 * AVC Encoder VSI Extension params
 *
 * STRUCT MEMBERS:
 *  nSize                     : Size of the structure in bytes
 *  nVersion                  : OMX specification version information
 *  nPortIndex                : Port that this structure applies to
 *  nBitDepthLuma             : Luma component valid bit depth.
 *  nBitDepthChroma           : Chroma component valid bit depth.
 *  gopSize                   : GOP Size, [0..8], 0 for adaptive GOP size; 1~7 for fixed GOP size
 *  hrdCpbSize                : HRD Coded Picture Buffer size in bits. Buffer size used by the HRD model.
 *  firstPic                  : First picture of input file to encode.
 *  lastPic                   : Last picture of input file to encode.
 * coded chroma_format_idc
 *  codedChromaIdc            : Specify coded chroma format idc.[1]. 0 -400, 1- 420, 2- 422
 
 *  rdoLevel                  : Programable hardware RDO Level [1..3].
 *  crf                       : Specify constant rate factor mode, working with look-ahead turned on.
                              :     [-1..51], -1=disable.
                              :     CRF mode is to keep a certain level of quality based on crf value, working as constant QP with complexity rate control.
                              :     CRF adjusts frame level QP within range of crf constant +-3 based on frame complexity. 
                              :     CRF will disable VBR mode if both enabled.
 * preset                     : Specify preset parameter to trade off performance and compression efficiency. 0...4 for HEVC. 0..1 for H264.
 */
typedef struct OMX_CSI_VIDEO_PARAM_AVCTYPEEXT {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;

    OMX_U32 nPreset;         /* 1 for AVC. Trade off performance and compression efficiency */

    OMX_U32 nBitDepthLuma;
    OMX_U32 nBitDepthChroma;

    OMX_BOOL bEnableConstrainedVBR;
    OMX_S32 nQpMinI;
    OMX_S32 nQpMaxI;
    OMX_S32 nQpMinPB;
    OMX_S32 nQpMaxPB;
    OMX_U32 nHrdCpbSize;
    OMX_S32 nIntraQpDelta;

    OMX_S32 nCTBRC;
    OMX_S32 nCTBRCBlockSize;
    OMX_S32 nCTBRCTolInter;
    OMX_S32 nCTBRCTolIntra;

    OMX_BOOL bEnableMBS; // Memory bandwidth saving mode
    OMX_BOOL bLowLatencyEncoding;
} OMX_CSI_VIDEO_PARAM_AVCTYPEEXT;

typedef struct OMX_CSI_VIDEO_PARAM_HEVCTYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_CSI_VIDEO_HEVCPROFILETYPE eProfile;
    OMX_CSI_VIDEO_HEVCLEVELTYPE eLevel;
    OMX_U32 nPFrames;
    OMX_U32 nRefFrames;

    OMX_U32 nPreset;         /* 1...3 for HEVC. Trade off performance and compression efficiency */

    OMX_U32 nBitDepthLuma;
    OMX_U32 nBitDepthChroma;
    OMX_S32 nVideoRange;
    OMX_S32 nSliceSize;
    OMX_U32 nTileColumns;
    OMX_U32 nTileRows;

    OMX_BOOL bEnableSAO;
    OMX_S32 nTcOffset;
    OMX_S32 nBetaOffset;
    OMX_BOOL bEnableDeblockOverride;
    OMX_BOOL bDeblockOverride;
    OMX_BOOL bEnableCrossTileLF; /* Set to 1 to enable loop filter accross tiles */

    OMX_BOOL bEnableConstrainedVBR;
    OMX_S32 nQpMinI;
    OMX_S32 nQpMaxI;
    OMX_S32 nQpMinPB;
    OMX_S32 nQpMaxPB;
    OMX_S32 nTolMovingBitRate; /* 0...2000%% percent tolerance over target bitrate of moving bit rate */
    OMX_S32 nMonitorFrames;
    OMX_S32 nBitVarRangeI;
    OMX_S32 nBitVarRangeP;
    OMX_S32 nStaticSceneIbitPercent;
    OMX_S32 nCTBRC;
    OMX_S32 nCTBRCBlockSize; /* Block size in CTB QP adjustment for Subjective Quality */
    OMX_S32 nCTBRCTolInter;
    OMX_S32 nCTBRCTolIntra;
    OMX_S32 nRcQpDeltaRange;
    OMX_S32 nRcBaseMBComplexity;
    OMX_S32 nCTBRowQpStep;
    OMX_S32 nPicQpDeltaMin;
    OMX_S32 nPicQpDeltaMax;
	OMX_U32 nHrdCpbSize;
    OMX_S32 nBitrateWindow;
    OMX_S32 nIntraQpDelta;
    OMX_S32 nFixedIntraQp;
    OMX_U32 nChromaQpOffset;
    OMX_BOOL bEnableVuiTimingInfo;

    OMX_U32 nGdrDuration;
    OMX_U32 nCirStart;
    OMX_U32 nCirInterval;
    OMX_U32 nRoiMapDeltaQpBlockUnit;
    OMX_U32 nEnableRoiMapDeltaQp;
    OMX_U32 nRoiQpDeltaVersion;

    OMX_BOOL bStrongIntraSmoothing;
    OMX_BOOL bDisablePcmLF; /* Set to 1 to disable PCM loop filter */

    OMX_BOOL bEnableMBS; // Memory bandwidth saving mode
    OMX_BOOL bLowLatencyEncoding;
} OMX_CSI_VIDEO_PARAM_HEVCTYPE;

/** VP9 profiles */
typedef enum OMX_CSI_VIDEO_VP9PROFILETYPE {
    OMX_CSI_VIDEO_VP9Profile0 = 0x01, /* 8-bit 4:2:0 */
    OMX_CSI_VIDEO_VP9Profile1 = 0x02, /* 8-bit 4:2:2, 4:4:4, alpha channel */
    OMX_CSI_VIDEO_VP9Profile2 = 0x04, /* 10-bit/12-bit 4:2:0, YouTube Premium Content Profile */
    OMX_CSI_VIDEO_VP9Profile3 = 0x08, /* 10-bit/12-bit 4:2:2, 4:4:4, alpha channel */
} OMX_CSI_VIDEO_VP9PROFILETYPE;

/** VP9 Param */
typedef struct OMX_CSI_VIDEO_PARAM_VP9TYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_CSI_VIDEO_VP9PROFILETYPE eProfile;
    OMX_U32 nBitDepthLuma;
    OMX_U32 nBitDepthChroma;
} OMX_CSI_VIDEO_PARAM_VP9TYPE;

/** AVS2 profiles */
typedef enum OMX_CSI_VIDEO_AVS2PROFILETYPE {
    OMX_CSI_VIDEO_AVS2ProfileMain = 0x01, /* Main profile */
    OMX_CSI_VIDEO_AVS2ProfileMain10 = 0x02, /* Main10 profile */
} OMX_CSI_VIDEO_AVS2PROFILETYPE;

/** Structure for configuring decoder */
typedef struct OMX_CSI_VIDEO_PARAM_CONFIGTYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_BOOL bEnableAdaptiveBuffers;
    OMX_BOOL bEnableRFC;
    OMX_BOOL bDisableReordering;
} OMX_CSI_VIDEO_PARAM_CONFIGTYPE;

typedef enum OMX_CSI_BUFFER_MODE {
  OMX_CSI_BUFFER_MODE_NORMAL = 0,
  OMX_CSI_BUFFER_MODE_DMA = 1,
} OMX_CSI_BUFFER_MODE;

/** Structure for configuring port buffer mode */
typedef struct OMX_CSI_BUFFER_MODE_CONFIGTYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_CSI_BUFFER_MODE eMode;
} OMX_CSI_BUFFER_MODE_CONFIGTYPE;

typedef enum OMX_CSI_COMPRESSION_MODE {
  OMX_CSI_COMPRESSION_MODE_DISABLED = 0,
  OMX_CSI_COMPRESSION_MODE_LOSSLESS = 1,
} OMX_CSI_COMPRESSION_MODE;

/** Structure for configuring port compression mode */
typedef struct OMX_CSI_COMPRESSION_MODE_CONFIGTYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_CSI_COMPRESSION_MODE eMode;
} OMX_CSI_COMPRESSION_MODE_CONFIGTYPE;
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OMX_CsiExt_h */
