/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_VDEC_H__
#define __CSI_VDEC_H__

#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#include <csi_common.h>
#include <csi_vcodec_common.h>
#include <csi_allocator.h>
#include <csi_frame.h>
#include <csi_frame_ex.h>

#ifdef  __cplusplus
extern "C" {
#endif

#define CSI_VDEC_VERSION_MAJOR	0
#define CSI_VDEC_VERSION_MINOR	2

typedef void *csi_vdec_dev_t;
typedef void *csi_vdec_chn_t;
typedef void *csi_vdec_event_handle_t;

typedef enum csi_vdec_status {
	CSI_VDEC_STATUS_OK = 0,
	CSI_VDEC_STATUS_MORE_FRAME_BUFFER = 1,
	CSI_VDEC_STATUS_MORE_BITSTREAM = 2,
	CSI_VDEC_STATUS_HAS_INFO = 3,
	CSI_VDEC_STATUS_PIC_DECODED = 4,
	CSI_VDEC_STATUS_NO_FRAME_BUFFER = 5,
	CSI_VDEC_STATUS_EOS = 6,
	CSI_VDEC_STATUS_TIMEOUT = 7,
	CSI_VDEC_STATUS_SKIPPED = 8,
	CSI_VDEC_STATUS_PIC_OUTPUT = 9,
	CSI_VDEC_STATUS_FLUSHED = 10,

	/* error codes < 0 */
	CSI_VDEC_ERR_UNKOWN = -1,
	CSI_VDEC_ERR_UNSUPPORTED = -2,
	CSI_VDEC_ERR_INSUFFICIENT_RESOURCES = -3,
	CSI_VDEC_ERR_WRONG_PARAM = -4,
	CSI_VDEC_ERR_BAD_STREAM = -5,
	CSI_VDEC_ERR_NOT_INTIALIZED = -6,
	CSI_VDEC_ERR_MEMORY = -7,
	/* add more ... */

	/* warnings > 0 */
	CSI_VDEC_WRN_DEVICE_BUSY = 256,
	CSI_VDEC_WRN_INCOMPATIBLE_PARAM = 257,
	CSI_VDEC_WRN_NOT_IMPLEMENTED = 258,
	/* add more ... */
} csi_vdec_status_e;

typedef enum csi_vdec_event_type {
	CSI_VDEC_EVENT_TYPE_DECODER,
	CSI_VDEC_EVENT_TYPE_CHANNEL,
} csi_vdec_event_type_e;

typedef enum csi_vdec_event_id {
	CSI_VDEC_EVENT_ID_ERROR	= 1 << 0,
} csi_vdec_event_id_e;

typedef enum csi_vdec_channel_event_id {
	CSI_VDEC_CHANNEL_EVENT_ID_ERROR		= 1 << 0,
	CSI_VDEC_CHANNEL_EVENT_ID_FRAME_READY	= 1 << 1,
} csi_vdec_channel_event_id_e;

typedef enum csi_framebuf_source {
	CSI_FB_SOURCE_DMABUF,
	CSI_FB_SOURCE_CARVEOUT,
} csi_framebuf_source_e;

typedef enum csi_vdec_input_mode {
	CSI_VDEC_INPUT_MODE_STREAM,
	CSI_VDEC_INPUT_MODE_FRAME,
} csi_vdec_input_mode_e;

typedef enum csi_vdec_img_type {
	CSI_VDEC_MODE_I = CSI_VCODEC_I_FRAME,
	CSI_VDEC_MODE_IP = (CSI_VCODEC_I_FRAME | CSI_VCODEC_P_FRAME),
	CSI_VDEC_MODE_IPB = (CSI_VCODEC_I_FRAME | CSI_VCODEC_P_FRAME | CSI_VCODEC_B_FRAME),
} csi_vdec_img_type_e;

typedef enum csi_vdec_output_order {
	CSI_VDEC_OUTPUT_ORDER_DISP = 0,
	CSI_VDEC_OUTPUT_ORDER_DEC,
} csi_vdec_output_order_e;

typedef enum csi_vdec_pp_rotate {
	CSI_VDEC_PP_ROTATE_0,
	CSI_VDEC_PP_ROTATE_90,
	CSI_VDEC_PP_ROTATE_180,
	CSI_VDEC_PP_ROTATE_270
} csi_vdec_pp_rotate_t;

#define CSI_VDEC_NAME_MAX_LEN 32
typedef struct csi_vdec_info {
	char module_name[CSI_VDEC_NAME_MAX_LEN];
	char device_name[CSI_VDEC_NAME_MAX_LEN];
	uint64_t capabilities;	 /* bitmask of 1<<(csi_vcodec_id_e) */
} csi_vdec_info_t;

#define CSI_VDEC_MAX_COUNT 2
typedef struct csi_vdec_infos {
	uint32_t count;
	csi_vdec_info_t info[CSI_VDEC_MAX_COUNT];
} csi_vdec_infos_s;

typedef struct csi_vdec_stream {
	uint32_t  length;
	uint64_t  pts;
	bool      eos;
	char     *data;
} csi_vdec_stream_s;

typedef struct csi_vdec_mode {
	csi_framebuf_source_e fb_source;
	bool low_latency_mode;
	bool mini_buf_mode;
} csi_vdec_mode_s;


typedef struct csi_vdec_video_264 {
} csi_vdec_video_264_s;

typedef struct csi_vdec_video_265 {
} csi_vdec_video_265_s;

typedef struct csi_vdec_picture_jpeg {
} csi_vdec_picture_jpeg_s;

typedef struct csi_vdec_config {
	csi_vcodec_id_e		dec_vcodec_id;
	uint32_t		dec_frame_buf_cnt;
	uint32_t		dec_frame_buf_size;
	union {
		csi_vdec_video_264_s    video_264_param;
		csi_vdec_video_265_s    video_265_param;
		csi_vdec_picture_jpeg_s picture_jpeg_param;
	};

	csi_vdec_input_mode_e	input_mode;
	uint32_t		input_stream_buf_size;

	csi_vdec_img_type_e	output_img_type;
	csi_pixel_fmt_e		output_format;
	uint32_t		output_width;
	uint32_t		output_height;
	csi_vdec_output_order_e output_order;
} csi_vdec_config_s;

typedef struct csi_vdec_pp_config {
	csi_vdec_pp_rotate_t rotate;
	bool h_flip;
	bool v_flip;
	csi_rect_s crop;	/* width or height to be zero means no crop */
} csi_vdec_pp_config_s;

typedef struct csi_vdec_error_stats {
	int32_t format_err;		/* R; format error. eg: do not support filed */
	int32_t pic_size_err_set;	/* R; picture width or height is larger than chnnel width or height*/
	int32_t stream_unsupprt;	/* R; unsupport the stream specification */
	int32_t pack_err;		/* R; stream package error */
	int32_t prtcl_num_err_set;	/* R; protocol num is not enough. eg: slice, pps, sps */
	int32_t ref_err_set;		/* R; refrence num is not enough */
	int32_t pic_buf_size_err_set;	/* R; the buffer size of picture is not enough */
	int32_t stream_size_over;	/* R; the stream size is too big and and force discard stream */
	int32_t vdec_stream_not_release;/* R; the stream not released for too long time */
} csi_vdec_error_stats_s;

typedef struct csi_vdec_chn_status {
	csi_vcodec_id_e dec_vcodec_id;		/* R; video type to be decoded */
	uint32_t	left_stream_bytes;	/* R; left stream bytes waiting for decode */
	uint32_t	left_stream_frames;	/* R; left frames waiting for decode,only valid for VIDEO_MODE_FRAME*/
	uint32_t	left_pics;		/* R; pics waiting for output */
	bool		recv_stream_started;	/* R; had started recv stream? */
	uint32_t	recv_stream_frames;	/* R; how many frames of stream has been received. valid when send by frame. */
	uint32_t	decode_stream_frames;	/* R; how many frames of stream has been decoded. valid when send by frame. */
	csi_vdec_error_stats_s stVdecDecErr;	/* R; information about decode error */
} csi_vdec_chn_status_s;

typedef struct csi_vdec_event_subscription {
	csi_vdec_event_type_e type;
	unsigned int id;	/* bitmasks */
} csi_vdec_event_subscription_t;

typedef struct csi_vdec_event {
	csi_vdec_event_type_e	type;
	unsigned int		id;
	struct timespec		timestamp;
	union {
		char bin[128];
	};
} csi_vdec_event_s;

int csi_vdec_get_version(csi_api_version_u *version);
int csi_vdec_query_list(csi_vdec_infos_s *infos);

int csi_vdec_open(csi_vdec_dev_t *dec, const char *device_name);
int csi_vdec_close(csi_vdec_dev_t dec);

int csi_vdec_get_io_pattern(csi_vdec_dev_t dec, int *pattern);

int csi_vdec_create_channel(csi_vdec_chn_t *chn, csi_vdec_dev_t dec, csi_vdec_config_s *cfg);
int csi_vdec_destory_channel(csi_vdec_chn_t chn);

int csi_vdec_get_frame_config(csi_vdec_chn_t chn, csi_img_format_t *img_fmt, csi_frame_config_s *frm_cfg);
int csi_vdec_set_frame_config(csi_vdec_chn_t chn, csi_img_format_t *img_fmt, csi_frame_config_s *frm_cfg);

//int csi_vdec_set_memory_allocator(csi_vdec_chn_t chn, csi_allocator_s *allocator);

int csi_vdec_set_mode(csi_vdec_chn_t chn, csi_vdec_mode_s *mode);
int csi_vdec_get_mode(csi_vdec_chn_t chn, csi_vdec_mode_s *mode);

int csi_vdec_set_chn_config(csi_vdec_chn_t chn, csi_vdec_config_s *cfg);
int csi_vdec_get_chn_config(csi_vdec_chn_t chn, csi_vdec_config_s *cfg);

int csi_vdec_set_pp_config(csi_vdec_chn_t chn, csi_vdec_pp_config_s *cfg);
int csi_vdec_get_pp_config(csi_vdec_chn_t chn, csi_vdec_pp_config_s *cfg);

int csi_vdec_start(csi_vdec_chn_t chn);
int csi_vdec_stop(csi_vdec_chn_t chn);
int csi_vdec_reset(csi_vdec_chn_t chn);

//int csi_vdec_get_frame_info(csi_vdec_chn_t chn, csi_vdec_frame_info *stream_info, csi_vdec_stream_s *stream);
int csi_vdec_send_stream_buf(csi_vdec_chn_t chn, csi_vdec_stream_s *stream, int32_t timeout);

int csi_vdec_register_frames(csi_vdec_chn_t chn, csi_frame_s *frame[], int count);
int csi_vdec_put_frame(csi_vdec_chn_t chn, csi_frame_s *frame);
int csi_vdec_get_frame(csi_vdec_chn_t chn, csi_frame_s **frame, int32_t timeout);// Release by frame.release()


int csi_vdec_enqueue_frame(csi_vdec_chn_t chn, csi_frame_ex_s *frame);
int csi_vdec_dequeue_frame(csi_vdec_chn_t chn, csi_frame_ex_s **frame, int32_t timeout);


int csi_vdec_query_status(csi_vdec_chn_t chn, csi_vdec_chn_status_s *pstStatus);

int csi_vdec_create_event_handle(csi_vdec_event_handle_t *chn, csi_vdec_dev_t event_handle);
int csi_vdec_destory_event(csi_vdec_event_handle_t event_handle);

int csi_vdec_subscribe_event(csi_vdec_event_handle_t event_handle,
			     csi_vdec_event_subscription_t *subscribe);
int csi_vdec_unsubscribe_event(csi_vdec_event_handle_t event_handle,
			       csi_vdec_event_subscription_t *subscribe);
int csi_vdec_get_event(csi_vdec_event_handle_t event_handle,
		       csi_vdec_event_s *event, int timeout);

#ifdef  __cplusplus
}
#endif

#endif /* __CSI_VDEC_H__ */
