/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_VENC_MJPEG_H__
#define __CSI_VENC_MJPEG_H__

typedef struct csi_venc_mpf_cfg
{
	uint8_t    large_thumbnail_count;   /* Range:[0,2]; the large thumbnail pic num of the MPF */
	csi_size_s large_thumbnail_size[2]; /* The resolution of large ThumbNail*/
} csi_venc_mpf_cfg_s;

/*the attribute of jpeg */
typedef struct csi_venc_jpeg_attr {
	bool			support_dcf;       /* Range:[0,1]; support dcf */
	csi_venc_mpf_cfg_s	mpf_cfg;           /* Range:[0,1]; config of Mpf*/
} csi_venc_jpeg_attr_s;

/*the attribute of mjpeg */
typedef struct csi_venc_mjpeg_attr {
	// reserve
} csi_venc_mjpeg_attr_s;

typedef struct csi_venc_mjpeg_cbr {
	uint32_t stat_time;	/* Range:[1, 60]; the rate statistic time, the unit is senconds(s) */
	uint32_t framerate_numer;
	uint32_t framerate_denom;
	uint32_t bit_rate;	/* Range:[2, 409600]; average bitrate, units:kbps */
} csi_venc_mjpeg_cbr_s;

typedef struct csi_venc_mjpeg_vbr {
	uint32_t stat_time;	/* Range:[1, 60]; the rate statistic time, the unit is senconds(s) */
	uint32_t framerate_numer;
	uint32_t framerate_denom;
	uint32_t max_bit_rate;	/* Range:[2, 409600]; average bitrate, units:kbps */
} csi_venc_mjpeg_vbr_s;

typedef struct csi_venc_mjpeg_fixqp {
	uint32_t framerate_numer;
	uint32_t framerate_denom;
	uint32_t q_factor;	/* Range:[1,99];image quality. */
} csi_venc_mjpeg_fixqp_s;

typedef enum csi_venc_jpeg_pack {
	CSI_VENC_JPEG_PACK_ECS,	/*ECS types*/
	CSI_VENC_JPEG_PACK_APP,	/*APP types*/
	CSI_VENC_JPEG_PACK_VDO,	/*VDO types*/
	CSI_VENC_JPEG_PACK_PIC,	/*PIC types*/
} csi_venc_jpeg_pack_e;

#endif /* __CSI_VENC_MJPEG_H__ */
