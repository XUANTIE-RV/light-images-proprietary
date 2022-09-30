/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_CAMERA_FRAME_H__
#define __CSI_CAMERA_FRAME_H__

#include <stddef.h>
#include <stdbool.h>
#include <sys/time.h>

#include <csi_frame.h>

#define CSI_CAMERA_META_MAX_LEN 1024

typedef enum csi_camera_meta_id {
	CSI_CAMERA_META_ID_CAMERA_NAME = (1<<0), /* str_value */
	CSI_CAMERA_META_ID_CHANNEL_ID  = (1<<1), /* uint_value */
	CSI_CAMERA_META_ID_FRAME_ID    = (1<<2), /* uint_value: Re-Count from zero when start() */
	CSI_CAMERA_META_ID_TIMESTAMP   = (1<<3), /* time_value: Get from gettimeofday()  */
	CSI_CAMERA_META_ID_HDR         = (1<<4), /* bool_value */
} csi_camera_meta_id_e;

#define CSI_CAMERA_META_NO_FIELD 0
#define CSI_CAMERA_META_DEFAULT_FIELDS (CSI_CAMERA_META_ID_CAMERA_NAME       | \
					CSI_CAMERA_META_ID_CHANNEL_ID        | \
					CSI_CAMERA_META_ID_FRAME_ID          | \
					CSI_CAMERA_META_ID_TIMESTAMP)

typedef struct csi_camrea_meta_unit {
	csi_camera_meta_id_e  id;
	csi_meta_value_type_e type;
	union {
		bool		bool_value;
		int		int_value;
		unsigned int	uint_value;
		char		str_value[32];
		struct timeval  time_value;
	};
} csi_camrea_meta_unit_s;

typedef struct csi_camera_meta {
	unsigned int            count;
	size_t                  size;
	csi_camrea_meta_unit_s *units;	// Is meta_unit array head
} csi_camera_meta_s;

int csi_camera_frame_alloc_meta(csi_camera_meta_s **meta, int meta_count, size_t *meta_data_size);
int csi_camera_frame_free_meta(csi_camera_meta_s *meta);

int csi_camera_frame_get_meta_unit(csi_camrea_meta_unit_s *meta_unit,
				   csi_camera_meta_s      *meta_data,
				   csi_camera_meta_id_e    meta_field);


#endif /* __CSI_CAMERA_FRAME_H__ */

