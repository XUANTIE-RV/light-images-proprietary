/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_CAMERA_H__
#define __CSI_CAMERA_H__

#include <time.h>

#include <csi_common.h>
#include <csi_camera_property.h>
#include <csi_camera_frame.h>
#include <csi_frame_ex.h>

#ifdef  __cplusplus
extern "C" {
#endif

/*
 * Camera logical parts are below, including: input sensor and output channel
 *  @------------------------------@
 *  |    Camera Settings      _____|______   Channel Settings
 *  |  ===================   |            | =====================
 *  |      Exposure          | channel[0] | configuration: width/height, pix_fmt
 *  |      R/G/B Gain        |_____ ______| ---> Channel Events
 *  |      HDR mode           _____|______
 *  |        ......          |            |
 *  |                        | channel[1] | configuration: width/height, pix_fmt
 *  |                        |_____ ______| ---> Channel Events
 *  |                         _____|______
 *  |                        |            |
 *  |                        | channel[n] | configuration: width/height, pix_fmt
 *  |                        |_____ ______| ---> Channel Events
 *  |        CAMERA                |
 *  @------------------------------@        ===> Camera Events (sensor, error, warning...)
 */

#define CSI_CAMERA_VERSION_MAJOR	0
#define CSI_CAMERA_VERSION_MINOR	2

#define CSI_CAMERA_NAME_MAX_LEN 32
typedef void *csi_cam_handle_t;
typedef void *csi_cam_event_handle_t;
typedef struct csi_cam_handle_info {
	int idx;
} csi_cam_handle_info_t;

#define MAX_FRAME_COUNT 1024
typedef enum csi_frame_status_type {
	CSI_FRAME_IDLE = 1,
	CSI_FRAME_WORKING = 2,
	CSI_FRAME_READY = 3,
	CSI_FRAME_DISPATCHED = 4,
} csi_frame_status_type_e;

typedef struct frame_channel_info {

	unsigned char *frame_bufs[MAX_FRAME_COUNT];
	int frame_status[MAX_FRAME_COUNT];
	int refcount[MAX_FRAME_COUNT];

	int frame_cnt;
	csi_frame_s frame[MAX_FRAME_COUNT];
} frame_channel_info_s;

typedef struct camera_frame_info {
	unsigned char *frame_bufs;
	int frame_status;
} camera_frame_info_s;

#define CSI_CAMERA_CAP_VIDEO_CAPTURE	0x00000001  /* Is a video capture device */
#define CSI_CAMERA_CAP_META_CAPTURE	0x00800000  /* Is a metadata capture device */

typedef struct csi_camera_info {
	char camera_name[CSI_CAMERA_NAME_MAX_LEN];
	char device_name[CSI_CAMERA_NAME_MAX_LEN];
	char		bus_info[32];	 /* e.g. "MIPI-CSI" */
	unsigned int	capabilities;	 /* bit mask of CSI_CAMERA_CAP_xx */
} csi_camera_info_s;

#define CSI_CAMERA_MAX_COUNT 16
typedef struct csi_camera_infos {
	unsigned int count;
	csi_camera_info_s info[CSI_CAMERA_MAX_COUNT];
} csi_camera_infos_s;

#define CSI_CAMERA_MODE_MAX_COUNT 16
typedef struct csi_camera_modes {
	int count;
	struct {
		int mode_id;
		char description[128];
	} modes[CSI_CAMERA_MODE_MAX_COUNT];
} csi_camera_modes_s;

typedef struct csi_camera_mode_cfg {
	int mode_id;
	char *calibriation;	/* set NULL to use default in system  */
	char *lib3a;		/* set NULL to use default in system  */
} csi_camera_mode_cfg_s;

typedef enum csi_camera_property_type {
	CSI_CAMERA_PROPERTY_TYPE_INTEGER	= 1,
	CSI_CAMERA_PROPERTY_TYPE_BOOLEAN	= 2,
	CSI_CAMERA_PROPERTY_TYPE_ENUM		= 3,
	CSI_CAMERA_PROPERTY_TYPE_STRING		= 7,
	CSI_CAMERA_PROPERTY_TYPE_BITMASK	= 8,
} csi_camera_property_type_e;

typedef union csi_camera_property_data {
	bool     bool_value;
	int      int_value;
	int      enum_value;
	uint32_t bitmask_value;
	char     str_value[32];
} csi_camera_property_data_u;

typedef struct csi_camera_property_description {
	unsigned int 			id;		/* CSI_CAMERA_PID_xx */
	csi_camera_property_type_e	type;		/* data type */
	char				name[32];	/* Whatever */
	int				minimum;	/* Note signedness */
	int				maximum;
	int				step;
	csi_camera_property_data_u default_value;
	csi_camera_property_data_u value; /*current value*/
	unsigned int			flags;
	unsigned int			reserved[2];
} csi_camera_property_description_s;

typedef struct csi_camera_property {
	unsigned int	id;
	csi_camera_property_type_e	type;		/* data type */
	csi_camera_property_data_u value;
} csi_camera_property_s;

typedef struct csi_camera_properties {
	unsigned int count;
	csi_camera_property_s *property;
} csi_camera_properties_s;

typedef enum csi_camera_channel_id {
	CSI_CAMERA_CHANNEL_0 = 0,
	CSI_CAMERA_CHANNEL_1,
	CSI_CAMERA_CHANNEL_2,
	CSI_CAMERA_CHANNEL_3,
	CSI_CAMERA_CHANNEL_4,
	CSI_CAMERA_CHANNEL_5,
	CSI_CAMERA_CHANNEL_6,
	CSI_CAMERA_CHANNEL_7,
	CSI_CAMERA_CHANNEL_MAX_COUNT
} csi_camera_channel_id_e;

typedef enum csi_camera_channel_status {
	CSI_CAMERA_CHANNEL_INVALID = -1,	/* channel can't be openned */
    CSI_CAMERA_CHANNEL_CLOSED,
    CSI_CAMERA_CHANNEL_OPENED,
	CSI_CAMERA_CHANNEL_RUNNING,
    CSI_CAMERA_CHANNEL_EXCEPTION,
} csi_camera_channel_status_e;

typedef enum csi_camera_channel_capture_type {
	CSI_CAMERA_CHANNEL_CAPTURE_VIDEO = (1 << 0),
	CSI_CAMERA_CHANNEL_CAPTURE_META  = (1 << 1),
} csi_camera_channel_capture_type_e;

typedef struct csi_camera_channel_cfg {
	csi_camera_channel_id_e 	chn_id;
	unsigned int			capture_type;	/* bitmask of: csi_camera_channel_capture_type_e */
	unsigned int			frm_cnt;
	csi_img_format_t		img_fmt;
	csi_img_type_e			img_type;
	unsigned int			meta_fields;	/* bitmask of: csi_camera_meta_id_e */
	csi_camera_channel_status_e	status;
} csi_camera_channel_cfg_s;

typedef enum csi_camera_event_type {
	CSI_CAMERA_EVENT_TYPE_INVALID = -1,
	CSI_CAMERA_EVENT_TYPE_CAMERA,
	CSI_CAMERA_EVENT_TYPE_CHANNEL0,
	CSI_CAMERA_EVENT_TYPE_CHANNEL1,
	CSI_CAMERA_EVENT_TYPE_CHANNEL2,
	CSI_CAMERA_EVENT_TYPE_CHANNEL3,
	CSI_CAMERA_EVENT_TYPE_CHANNEL4,
	CSI_CAMERA_EVENT_TYPE_CHANNEL5,
	CSI_CAMERA_EVENT_TYPE_CHANNEL6,
	CSI_CAMERA_EVENT_TYPE_CHANNEL7,
} csi_camera_event_type_e;

typedef enum csi_camera_event_id {
	CSI_CAMERA_EVENT_WARNING                   = 1 << 0,
	CSI_CAMERA_EVENT_ERROR                     = 1 << 1,
	CSI_CAMERA_EVENT_SENSOR_FIRST_IMAGE_ARRIVE = 1 << 2,
	CSI_CAMERA_EVENT_ISP_3A_ADJUST_READY       = 1 << 3,

	CSI_CAMERA_EVENT_MAX_COUNT = 32
} csi_camera_event_id_e;

typedef enum csi_camera_channel_event_id {
	CSI_CAMERA_CHANNEL_EVENT_FRAME_READY = 1 << 0,
	CSI_CAMERA_CHANNEL_EVENT_FRAME_PUT   = 1 << 1,
	CSI_CAMERA_CHANNEL_EVENT_OVERFLOW    = 1 << 2,

	CSI_CAMERA_CHANNEL_EVENT_MAX_COUNT = 32
} csi_camera_channel_event_id_e;

typedef struct csi_camera_event_subscription {
	csi_camera_event_type_e type;
	unsigned int id;	/* bitmasks */
} csi_camera_event_subscription_s;

typedef struct csi_camera_event {
	csi_camera_event_type_e	type;
	unsigned int		id;
	struct timespec		timestamp;
	union {
		char bin[128];
	};
} csi_camera_event_s;

int csi_camera_get_version(csi_api_version_u *version);

int csi_camera_query_list(csi_camera_infos_s *infos);
int csi_camera_open(csi_cam_handle_t *cam_handle, const char *device_name);
int csi_camera_close(csi_cam_handle_t cam_handle);

int csi_camera_get_modes(csi_cam_handle_t cam_handle,
			 csi_camera_modes_s *modes);

int csi_camera_set_mode(csi_cam_handle_t cam_handle,
			csi_camera_mode_cfg_s *cfg);

int csi_camera_get_io_pattern(csi_cam_handle_t cam_handle, int *pattern);
int csi_camera_get_frame_config(csi_cam_handle_t cam_handle, csi_img_format_t *img_fmt, csi_frame_config_s *frm_cfg);
int csi_camera_set_frame_config(csi_cam_handle_t cam_handle, csi_img_format_t *img_fmt, csi_frame_config_s *frm_cfg);

int csi_sensor_enable_colobar(csi_cam_handle_t cam_handle, int en);
int csi_camera_query_property(csi_cam_handle_t cam_handle,
			      csi_camera_property_description_s *desc);
int csi_camera_get_property(csi_cam_handle_t cam_handle,
			    csi_camera_properties_s *properties);
int csi_camera_set_property(csi_cam_handle_t cam_handle,
			    csi_camera_properties_s *properties);

int csi_camera_channel_open(csi_cam_handle_t cam_handle,
			    csi_camera_channel_cfg_s *cfg);
int csi_camera_channel_close(csi_cam_handle_t cam_handle,
			     csi_camera_channel_id_e chn_id);
int csi_camera_channel_query(csi_cam_handle_t cam_handle,
			     csi_camera_channel_cfg_s *cfg);

int csi_camera_get_frame_count(csi_cam_handle_t cam_handle,
			       csi_camera_channel_id_e chn_id);
int csi_camera_get_frame(csi_cam_handle_t cam_handle,
			 csi_camera_channel_id_e chn_id,
			 csi_frame_s *frame, int timeout);

int csi_camera_put_frame(csi_frame_s *frame);


int csi_camera_dequeue_frame(csi_cam_handle_t cam_handle,
			     csi_camera_channel_id_e chn_id,
			     csi_frame_ex_s **frame,
			     int timeout);

int csi_camera_enqueue_frame(csi_cam_handle_t cam_handle,
			     csi_camera_channel_id_e chn_id,
			     csi_frame_ex_s *frame);


int csi_camera_create_event(csi_cam_event_handle_t *event_handle,
			    csi_cam_handle_t cam_handle);
int csi_camera_destory_event(csi_cam_event_handle_t event_handle);

int csi_camera_subscribe_event(csi_cam_event_handle_t event_handle,
			       csi_camera_event_subscription_s *subscribe);
int csi_camera_unsubscribe_event(csi_cam_event_handle_t event_handle,
				 csi_camera_event_subscription_s *subscribe);
int csi_camera_get_event(csi_cam_event_handle_t event_handle,
			 csi_camera_event_s *event,
			 int timeout);

int csi_camera_channel_start(csi_cam_handle_t cam_handle,
			     csi_camera_channel_id_e chn_id);
int csi_camera_channel_stop(csi_cam_handle_t cam_handle,
			    csi_camera_channel_id_e chn_id);

#ifdef  __cplusplus
}
#endif

#endif /* __CSI_CAMERA_H__ */
