/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_VENC_PROPERTY_H__
#define __CSI_VENC_PROPERTY_H__

#include <csi_frame.h>

typedef struct csi_venc_attr {
	csi_vcodec_id_e enc_vcodec_id;	/* RW; the type of payload*/
	csi_pixel_fmt_e input_format;
	uint32_t max_pic_width;		/* RW; maximum width of a picture to be encoded, in pixel*/
	uint32_t max_pic_height;	/* RW; maximum height of a picture to be encoded, in pixel*/
	uint32_t buf_size;		/* RW; stream buffer size*/
	uint32_t pic_width;		/* RW; maximum width of a picture to be encoded, in pixel*/
	uint32_t pic_height;		/* RW; maximum height of a picture to be encoded, in pixel*/
	union {
		csi_venc_h264_attr_s  h264_attr;
		csi_venc_h265_attr_s  h265_attr;
		csi_venc_jpeg_attr_s  jpeg_attr;
		csi_venc_mjpeg_attr_s mjpeg_attr;
	};
} csi_venc_attr_s;

/* VENC GOP Property */
typedef enum csi_venc_gop_mode {
	CSI_VENC_GOPMODE_NORMALP	= 0,
	CSI_VENC_GOPMODE_DUALP		= 1,
	CSI_VENC_GOPMODE_SMARTP		= 2,
	CSI_VENC_GOPMODE_ADVSMARTP	= 3,
	CSI_VENC_GOPMODE_BIPREDB	= 4,
	CSI_VENC_GOPMODE_LOWDELAYB	= 5,
} csi_venc_gop_mode_e;

typedef struct csi_venc_gop_normalp {
	int32_t ip_qp_delta;	/* Range:[-10,30]; QP variance between P frame and I frame */
} csi_venc_gop_normalp_s;

typedef struct csi_venc_gop_dualp {
	uint32_t sp_interval;	/* Range:[0, 1)U(1, Gop -1]; Interval of the special P frames */
	int32_t  sp_qp_delta;	/* Range:[-10,30]; QP variance between P frame and special P frame */
	int32_t  ip_qp_delta;	/* Range:[-10,30]; QP variance between P frame and I frame */
} csi_venc_gop_dualp_s;

typedef struct csi_venc_gop_smartp {
	uint32_t bg_interval;	/* Range:[0, 1)U(1, Gop -1]; Interval of the special P frames */
	int32_t  sp_qp_delta;	/* Range:[-10,30]; QP variance between P frame and special P frame */
	int32_t  ip_qp_delta;	/* Range:[-10,30]; QP variance between P frame and I frame */
} csi_venc_gop_smartp_s;

typedef struct csi_venc_gop_advsmartp {
	uint32_t bg_interval;	/* Range:[Gop,4294967295] ;Interval of the long-term reference frame */
	int32_t  bg_qp_delta;	/* Range:[-10,30]; QP variance between P frame and Bg frame */
	int32_t  vi_qp_delta;	/* Range:[-10,30]; QP variance between P frame and virtual I frame */
} csi_venc_gop_advsmartp_s;

typedef struct csi_venc_gop_bipredb {
	uint32_t b_frm_num;	/* Range:[1,3]; Number of B frames */
	int32_t  b_qp_delta;	/* Range:[-10,30]; QP variance between P frame and B frame */
	int32_t  ip_qp_delta;	/* Range:[-10,30]; QP variance between P frame and I frame */
} csi_venc_gop_bipredb_s;

typedef struct csi_venc_gop_property {
	uint32_t gop_num;
	csi_venc_gop_mode_e gop_mode;
	union {
		csi_venc_gop_normalp_s   normalp;	/* attributes of normal P */
		csi_venc_gop_dualp_s     dualp;		/* attributes of dual P */
		csi_venc_gop_smartp_s    smartp;	/* attributes of Smart P */
		csi_venc_gop_advsmartp_s advsmartp;	/* attributes of AdvSmart P */
		csi_venc_gop_bipredb_s   bipredb;	/* attributes of B */
	};
} csi_venc_gop_property_s;

/* VENC Rate Control Property */
typedef enum csi_venc_rc_mode {
	CSI_VENC_RC_MODE_NONE = 0,	/* JPEG use it */

	CSI_VENC_RC_MODE_H264CBR = 1,
	CSI_VENC_RC_MODE_H264VBR,
	CSI_VENC_RC_MODE_H264AVBR,
	CSI_VENC_RC_MODE_H264FIXQP,
	CSI_VENC_RC_MODE_H264QPMAP,

	CSI_VENC_RC_MODE_H265CBR,
	CSI_VENC_RC_MODE_H265VBR,
	CSI_VENC_RC_MODE_H265AVBR,
	CSI_VENC_RC_MODE_H265FIXQP,
	CSI_VENC_RC_MODE_H265QPMAP,

	CSI_VENC_RC_MODE_MJPEGCBR,
	CSI_VENC_RC_MODE_MJPEGVBR,
	CSI_VENC_RC_MODE_MJPEGFIXQP,
} csi_venc_rc_mode_e;

typedef struct csi_venc_rc_property {
	csi_venc_rc_mode_e rc_mode;
	union {
		csi_venc_h264_cbr_s    h264_cbr;
		csi_venc_h264_vbr_s    h264_vbr;
		csi_venc_h264_avbr_s   h264_avbr;
		csi_venc_h264_fixqp_s  h264_fixqp;

		csi_venc_h265_cbr_s    h265_cbr;
		csi_venc_h265_vbr_s    h265_vbr;
		csi_venc_h265_avbr_s   h265_avbr;
		csi_venc_h265_fixqp_s  h265_fixqp;

		csi_venc_mjpeg_cbr_s   mjpeg_cbr;
		csi_venc_mjpeg_vbr_s   mjpeg_vbr;
		csi_venc_mjpeg_fixqp_s mjpeg_fixqp;
	};
} csi_venc_rc_property_s;

#endif /* __CSI_VENC_PROPERTY_H__ */
