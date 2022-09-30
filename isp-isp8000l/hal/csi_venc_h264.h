/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_VENC_H264_H__
#define __CSI_VENC_H264_H__

typedef enum {
	CSI_VENC_H264_PROFILE_BASELINE = 0,
	CSI_VENC_H264_PROFILE_EXTENDED = 1,
	CSI_VENC_H264_PROFILE_MAIN = 2,
	CSI_VENC_H264_PROFILE_HIGH = 3,
	CSI_VENC_H264_PROFILE_HIGH10 = 4,
	CSI_VENC_H264_PROFILE_HIGH422 = 5,
	CSI_VENC_H264_PROFILE_HIGH444 = 6,

	CSI_VENC_H264_PROFILE_SVC = 10,
} csi_venc_h264_profile_e;

typedef enum {
	CSI_VENC_H264_LEVEL_1   = 10,   /* QCIF  (176x144)   64k bps */
	CSI_VENC_H264_LEVEL_1_b = 99,
	CSI_VENC_H264_LEVEL_1_1 = 11,
	CSI_VENC_H264_LEVEL_1_2 = 12,
	CSI_VENC_H264_LEVEL_1_3 = 13,
	CSI_VENC_H264_LEVEL_2   = 20,   /* CIF   (352x288)   576k bps" */
	CSI_VENC_H264_LEVEL_2_1 = 21,
	CSI_VENC_H264_LEVEL_2_2 = 22,
	CSI_VENC_H264_LEVEL_3   = 30,   /* SD    (720x576)     2M bps */
	CSI_VENC_H264_LEVEL_3_1 = 31,
	CSI_VENC_H264_LEVEL_3_2 = 32,
	CSI_VENC_H264_LEVEL_4   = 40,   /* 1080p (1920x1080)  25M bps */
	CSI_VENC_H264_LEVEL_4_1 = 41,
	CSI_VENC_H264_LEVEL_4_2 = 42,
	CSI_VENC_H264_LEVEL_5   = 50,   /* 2k    (2560x1920) 168M bps */
	CSI_VENC_H264_LEVEL_5_1 = 51,
	CSI_VENC_H264_LEVEL_5_2 = 52,
} csi_venc_h264_level_e;

typedef struct csi_venc_h264_attr {
	csi_venc_h264_profile_e	profile;
	csi_venc_h264_level_e	level;
	uint32_t		frame_type; // bitmask of csi_vcodec_frame_type_e
	bool			frame_mode; // encode by frame or slice mode
	bool			share_buf;  //Whether to enable the Share Buf of Rcn and Ref
} csi_venc_h264_attr_s;

typedef struct csi_venc_h264_cbr {
	uint32_t stat_time;     /* Range:[1, 60]; the rate statistic time, the unit is senconds(s) */
	uint32_t framerate_numer;
	uint32_t framerate_denom;
	uint32_t bit_rate;	/* Range:[2, 409600]; average bitrate, units:kbps */
} csi_venc_h264_cbr_s;

typedef struct csi_venc_h264_vbr {
	uint32_t stat_time;     /* Range:[1, 60]; the rate statistic time, the unit is senconds(s) */
	uint32_t framerate_numer;
	uint32_t framerate_denom;
	uint32_t max_bit_rate;	/* Range:[2, 409600]; average bitrate, units:kbps */
} csi_venc_h264_vbr_s;

typedef struct csi_venc_h264_avbr {
	uint32_t stat_time;     /* Range:[1, 60]; the rate statistic time, the unit is senconds(s) */
	uint32_t framerate_numer;
	uint32_t framerate_denom;
	uint32_t max_bit_rate;	/* Range:[2, 409600]; average bitrate, units:kbps */
} csi_venc_h264_avbr_s;

typedef struct csi_venc_h264_fixqp {
	uint32_t framerate_numer;
	uint32_t framerate_denom;
	uint32_t i_qp;		/* Range:[0, 51]; qp of the I frame */
	uint32_t p_qp;		/* Range:[0, 51]; qp of the P frame */
	uint32_t b_qp;		/* Range:[0, 51]; qp of the B frame */
} csi_venc_h264_fixqp_s;

typedef struct csi_venc_h264_qpmap {
	uint32_t stat_time;     /* Range:[1, 60]; the rate statistic time, the unit is senconds(s) */
	uint32_t framerate_numer;
	uint32_t framerate_denom;
} csi_venc_h264_qpmap_s;

typedef enum csi_venc_h264_nalu {
	CSI_VENC_H264_NALU_BSLICE,	/*B SLICE types*/
	CSI_VENC_H264_NALU_PSLICE,	/*P SLICE types*/
	CSI_VENC_H264_NALU_ISLICE,	/*I SLICE types*/
	CSI_VENC_H264_NALU_IDRSLICE,	/*IDR SLICE types*/
	CSI_VENC_H264_NALU_SEI,		/*SEI types*/
	CSI_VENC_H264_NALU_SPS,		/*SPS types*/
	CSI_VENC_H264_NALU_PPS,		/*PPS types*/
} csi_venc_h264_nalu_e;

#endif /* __CSI_VENC_H264_H__ */
