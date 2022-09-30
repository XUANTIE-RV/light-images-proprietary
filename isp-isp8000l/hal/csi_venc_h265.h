/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_VENC_H265_H__
#define __CSI_VENC_H265_H__

#include <csi_venc_h265.h>

typedef enum {
	CSI_VENC_H265_PROFILE_MAIN = 0,
	CSI_VENC_H265_PROFILE_MAIN10,
	CSI_VENC_H265_PROFILE_MAINSTILL,
} csi_venc_h265_profile_e;

typedef enum {
	CSI_VENC_H265_LEVEL_1   = 10,   /* QCIF  (176x144)   64k bps */
	CSI_VENC_H265_LEVEL_2   = 20,   /* CIF   (352x288)  122k bps" */
	CSI_VENC_H265_LEVEL_2_1 = 21,
	CSI_VENC_H265_LEVEL_3   = 30,   /* SD    (720x576)    6M bps */
	CSI_VENC_H265_LEVEL_3_1 = 31,
	CSI_VENC_H265_LEVEL_4   = 40,   /* 1080p (1920x1080) 12M bps */
	CSI_VENC_H265_LEVEL_4_1 = 41,
	CSI_VENC_H265_LEVEL_5   = 50,   /* 4k (3840x2160)    25M bps */
	CSI_VENC_H265_LEVEL_5_1 = 51,
	CSI_VENC_H265_LEVEL_5_2 = 52,
	CSI_VENC_H265_LEVEL_6   = 60,   /* 8k (7680x4320)    60M bps */
	CSI_VENC_H265_LEVEL_6_1 = 61,
	CSI_VENC_H265_LEVEL_6_2 = 62,
} csi_venc_h265_level_e;

typedef struct csi_venc_h265_attr {
	csi_venc_h265_profile_e	profile;
	csi_venc_h265_level_e	level;

	uint32_t		frame_type; // bitmask of csi_vcodec_frame_type_e
	bool			frame_mode; // encode by frame or slice mode
	bool			share_buf;  //Whether to enable the Share Buf of Rcn and Ref
} csi_venc_h265_attr_s;

typedef enum csi_venc_h265_nalu {
	CSI_VENC_H265_NALU_BSLICE,	/*B SLICE types*/
	CSI_VENC_H265_NALU_PSLICE,	/*P SLICE types*/
	CSI_VENC_H265_NALU_ISLICE,	/*I SLICE types*/
	CSI_VENC_H265_NALU_IDRSLICE,	/*IDR SLICE types*/
	CSI_VENC_H265_NALU_VPS,		/*VPS types*/
	CSI_VENC_H265_NALU_SEI,		/*SEI types*/
	CSI_VENC_H265_NALU_SPS,		/*SPS types*/
	CSI_VENC_H265_NALU_PPS,		/*PPS types*/
} csi_venc_h265_nalu_e;

typedef csi_venc_h264_cbr_s   csi_venc_h265_cbr_s;
typedef csi_venc_h264_vbr_s   csi_venc_h265_vbr_s;
typedef csi_venc_h264_avbr_s  csi_venc_h265_avbr_s;
typedef csi_venc_h264_fixqp_s csi_venc_h265_fixqp_s;

#endif /* __CSI_VENC_H265_H__ */
