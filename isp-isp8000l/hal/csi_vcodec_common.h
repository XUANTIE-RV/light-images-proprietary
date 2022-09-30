/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_VIDEO_COMMON__
#define __CSI_VIDEO_COMMON__

#ifdef  __cplusplus
extern "C" {
#endif

/* Refer ffmpeg: libavcodec/codec_id.h */
typedef enum csi_vcodec_id {
	CSI_VCODEC_ID_UNKNOWN = 0,		/* unknown decoder */

	CSI_VCODEC_ID_JPEG  = (1 << 0),
	CSI_VCODEC_ID_MJPEG = (1 << 1),

	CSI_VCODEC_ID_MPEG1 = (1 << 2),
	CSI_VCODEC_ID_MPEG2 = (1 << 3),		/* MPEG-2 decoder */
	CSI_VCODEC_ID_MPEG4 = (1 << 4),		/* MPEG-4 decoder */

	CSI_VCODEC_ID_H263P = (1 << 5),		/* H.263 progressive  */
	CSI_VCODEC_ID_H263I = (1 << 6),		/* H.263 interleave  */
	CSI_VCODEC_ID_H264  = (1 << 7),		/* H.264 AVC/SVC */
	CSI_VCODEC_ID_H265  = (1 << 8),		/* H.265  */
	CSI_VCODEC_ID_H266  = (1 << 9),		/* H.266  */

	CSI_VCODEC_ID_RV30  = (1 << 10),	/* RealVideo 8  */
	CSI_VCODEC_ID_RV40  = (1 << 11),	/* RealVideo 9/10  */

	CSI_VCODEC_ID_WMV1  = (1 << 12),
	CSI_VCODEC_ID_WMV2  = (1 << 13),
	CSI_VCODEC_ID_WMV3  = (1 << 14),

	CSI_VCODEC_ID_MSMPEG4V1 = (1 << 15),
	CSI_VCODEC_ID_MSMPEG4V2 = (1 << 16),
	CSI_VCODEC_ID_MSMPEG4V3 = (1 << 17),

	// Alias names
	CSI_VCODEC_ID_HEVC = CSI_VCODEC_ID_H265,
	CSI_VCODEC_ID_DIVX = CSI_VCODEC_ID_MSMPEG4V2,
} csi_vcodec_id_e;

typedef enum csi_vcodec_frame_type {
	CSI_VCODEC_I_FRAME = 1 << 0,
	CSI_VCODEC_P_FRAME = 1 << 1,
	CSI_VCODEC_B_FRAME = 1 << 2,
} csi_vcodec_frame_type_e;

#ifdef  __cplusplus
}
#endif

#endif /* __CSI_VIDEO_COMMON__ */
