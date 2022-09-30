/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_VENC_H__
#define __CSI_VENC_H__

#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#include <csi_common.h>
#include <csi_allocator.h>
#include <csi_vcodec_common.h>
#include <csi_venc_h264.h>
#include <csi_venc_h265.h>
#include <csi_venc_mjpeg.h>
#include <csi_venc_property.h>
#include <csi_frame.h>
#include <csi_frame_ex.h>

#ifdef  __cplusplus
extern "C" {
#endif

#define CSI_VENC_VERSION_MAJOR 0
#define CSI_VENC_VERSION_MINOR 3

typedef void *csi_venc_dev_t;
typedef void *csi_venc_chn_t;
typedef void *csi_venc_event_handle_t;

#define CSI_VENC_NAME_MAX_LEN 32
typedef struct csi_venc_info {
	char module_name[CSI_VENC_NAME_MAX_LEN];
	char device_name[CSI_VENC_NAME_MAX_LEN];
	uint64_t capabilities;	 /* bitmask of 1<<(csi_vcodec_id_e) */
} csi_venc_info_s;

#define CSI_VENC_MAX_COUNT 2
typedef struct csi_venc_infos {
	uint32_t count;
	csi_venc_info_s info[CSI_VENC_MAX_COUNT];
} csi_venc_infos_s;

typedef struct csi_venc_chn_cfg {
	csi_venc_attr_s attr;
	csi_venc_gop_property_s gop;
	csi_venc_rc_property_s  rc;
} csi_venc_chn_cfg_s;

typedef enum csi_venc_event_type {
	CSI_VENC_EVENT_TYPE_DECODER,
	CSI_VENC_EVENT_TYPE_CHANNEL,
} csi_venc_event_type_e;

/* the attribute of the roi */
typedef struct csi_venc_chn_roi_prop {
	uint32_t   index;	/* Range:[0, 7]; Index of an ROI. The system supports indexes ranging from 0 to 7 */
	bool       enable;	/* Range:[0, 1]; Whether to enable this ROI */
	bool       abs_qp;	/* Range:[0, 1]; QP mode of an ROI.HI_FALSE: relative QP.HI_TURE: absolute QP.*/
	int32_t    qp;		/* Range:[-51, 51]; QP value,only relative mode can QP value less than 0. */
	csi_rect_s rect;	/* Region of an ROI*/
} csi_venc_chn_roi_prop_s;

typedef enum csi_venc_ext_property_id {
	CSI_VENC_EXT_PROPERTY_ROI,
} csi_venc_ext_property_id_e;

typedef struct csi_venc_chn_ext_property {
	csi_venc_ext_property_id_e prop_id;
	union {
		csi_venc_chn_roi_prop_s roi_prop;	// CSI_VENC_EXT_PROPERTY_ROI
	};
} csi_venc_chn_ext_property_s;

typedef enum csi_venc_event_id {
	CSI_VENC_EVENT_ID_ERROR	= 1 << 0,
} csi_venc_event_id_e;

typedef enum csi_venc_chn_event_id {
	CSI_VENC_CHANNEL_EVENT_ID_ERROR		= 1 << 0,
	CSI_VENC_CHANNEL_EVENT_ID_FRAME_READY	= 1 << 1,
} csi_venc_chn_event_id_e;

typedef struct csi_venc_event_subscription {
	csi_venc_event_type_e type;
	unsigned int id;	/* bitmasks */
} csi_venc_event_subscription_s;

typedef struct csi_venc_event {
	csi_venc_event_type_e	type;
	unsigned int		id;
	struct timespec		timestamp;
	union {
		char bin[128];
	};
} csi_venc_event_s;

typedef union csi_venc_data_type {
	csi_venc_h264_nalu_e h264_type;
	csi_venc_h265_nalu_e h265_type;
	csi_venc_jpeg_pack_e jpeg_type;
} csi_venc_data_type_u;

typedef struct csi_stream {
	size_t		size;
	union {
		int	buf_fd;		// stores in dma_buf memory
		void	*phy_addr;	// stores in phy contigous memory
		void	*usr_addr;	// stores in usr contigous memory
	};
	uint64_t	pts;
	bool		frame_end;
	csi_venc_data_type_u	data_type;
	uint32_t	data_num;
} csi_stream_s;

typedef enum csi_venc_prop_type {
	CSI_VENC_FRAME_PROP_NONE = 0,
	CSI_VENC_FRAME_PROP_FORCE_IDR,	// Instantaneous Decoding Refresh
	CSI_VENC_FRAME_PROP_FORCE_SKIP,
} csi_venc_prop_type_e;

typedef struct csi_venc_prop {
	csi_venc_prop_type_e type;
	union {
		bool force_idr;		// CSI_VENC_FRAME_PROP_FORCE_IDR
		bool force_skip;	// CSI_VENC_FRAME_PROP_FORCE_SKIP
	};
} csi_venc_frame_prop_s;

/* the status of the venc chnl*/
typedef struct csi_venc_chn_status {
	uint32_t left_pics;		/* R; left picture number */
	uint32_t left_stream_bytes;	/* R; left stream bytes*/
	uint32_t left_stream_frames;	/* R; left stream frames*/
	uint32_t cur_packs;		/* R; pack number of current frame*/
	uint32_t left_recv_pics;	/* R; Number of frames to be received. This member is valid after HI_MPI_VENC_StartRecvPicEx is called.*/
	uint32_t left_enc_pics;		/* R; Number of frames to be encoded. This member is valid after HI_MPI_VENC_StartRecvPicEx is called.*/
	bool     jpeg_snap_end;		/* R; the end of Snap.*/
} csi_venc_chn_status_s;

int csi_venc_get_version(csi_api_version_u *version);
int csi_venc_query_list(csi_venc_infos_s *infos);

int csi_venc_open(csi_venc_dev_t *enc, const char *device_name);
int csi_venc_close(csi_venc_dev_t enc);

int csi_venc_get_io_pattern(csi_venc_dev_t enc, int *pattern);
int csi_venc_get_frame_config(csi_venc_dev_t enc, csi_img_format_t *img_fmt, csi_frame_config_s *frm_cfg);
int csi_venc_set_frame_config(csi_venc_dev_t enc, csi_img_format_t *img_fmt, csi_frame_config_s *frm_cfg);



int csi_venc_create_channel(csi_venc_chn_t *chn, csi_venc_dev_t enc, csi_venc_chn_cfg_s *cfg);
int csi_venc_destory_channel(csi_venc_chn_t chn);

//int csi_venc_set_memory_allocator(csi_venc_chn_t chn, csi_allocator_s *allocator);

int csi_venc_set_ext_property(csi_venc_chn_t chn, csi_venc_chn_ext_property_s *prop);
int csi_venc_get_ext_property(csi_venc_chn_t chn, csi_venc_chn_ext_property_s *prop);

int csi_venc_start(csi_venc_chn_t chn);
int csi_venc_stop(csi_venc_chn_t chn);
int csi_venc_reset(csi_venc_chn_t chn);

int csi_venc_send_frame(csi_venc_chn_t chn, csi_frame_s *frame, int timeout);
int csi_venc_send_frame_ex(csi_venc_chn_t chn, csi_frame_s *frame, int timeout,
			   csi_venc_frame_prop_s *prop, int prop_count);


int csi_venc_enqueue_frame(csi_venc_chn_t chn, csi_frame_ex_s *frame);
int csi_venc_enqueue_frame_ex(csi_venc_chn_t chn, csi_frame_ex_s *frame,
			      csi_venc_frame_prop_s *prop, int prop_count);
int csi_venc_dequeue_frame(csi_venc_chn_t chn, csi_frame_ex_s **frame, int timeout);


int csi_venc_get_stream(csi_venc_chn_t chn, csi_stream_s *stream, int timeout);// Release by stream.release()

int csi_venc_query_status(csi_venc_chn_t chn, csi_venc_chn_status_s *status);

int csi_venc_create_event_handle(csi_venc_event_handle_t *chn, csi_venc_dev_t event_handle);
int csi_venc_destory_event(csi_venc_event_handle_t event_handle);

int csi_venc_subscribe_event(csi_venc_event_handle_t event_handle,
			     csi_venc_event_subscription_s *subscribe);
int csi_venc_unsubscribe_event(csi_venc_event_handle_t event_handle,
			       csi_venc_event_subscription_s *subscribe);
int csi_venc_get_event(csi_venc_event_handle_t event_handle,
		       csi_venc_event_s *event, int timeout);

#ifdef  __cplusplus
}
#endif

#endif /* __CSI_ENC_H__ */
