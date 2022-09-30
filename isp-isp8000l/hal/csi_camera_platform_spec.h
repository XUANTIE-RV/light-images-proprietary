/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_CAMERA_PLATFORM_SPEC_H__
#define __CSI_CAMERA_PLATFORM_SPEC_H__
#include <stdio.h>
#include <csi_camera.h>

/******************************************************************************/
/*********** Platform Spec in Enum ********************************************/
/******************************************************************************/

#define CAMERA_PROPERTY_MAX_ENUM_COUNT 16

typedef struct camera_support_enums {
	int count;
	int enums[CAMERA_PROPERTY_MAX_ENUM_COUNT];
} camera_spec_enums_s;

typedef enum camera_sepc_enums {
	CAMERA_SPEC_ENUM_CHANNEL_PIX_FMT,
	CAMERA_SPEC_ENUM_CHANNEL_IMG_TYPE,
	CAMERA_SPEC_ENUM_CAMERA_EVENT_TYPES,
	CAMERA_SPEC_ENUM_CHANNEL_EVENT_TYPES,

	/* Camera Properties below */
	CAMERA_SPEC_ENUM_CAMERA_EXPOSURE_MODES = CSI_CAMERA_PID_EXPOSURE_MODE,
} camera_sepc_enums_e;

const camera_spec_enums_s *camera_spec_get_enum_array(int property_id);


/******************************************************************************/
/*********** Platform Spec in Bitmask *****************************************/
/******************************************************************************/

#define CAMERA_PROPERTY_MAX_BITMASK_COUNT 32

typedef struct camera_support_bitmasks {
	int count;
	int bitmask[CAMERA_PROPERTY_MAX_BITMASK_COUNT];
} camera_spec_bitmasks_t;


typedef enum camera_sepc_bitmasks {
	CAMERA_SPEC_BITMAKS_CHANNEL_CAPTURE_TYPE,
	CAMERA_SPEC_BITMAKS_CHANNEL_META_TYPE,

	/* Camera Properties below */
	CAMERA_SPEC_BITMAKS_CAMERA_3A_LOCK = CSI_CAMERA_PID_3A_LOCK,
} camera_sepc_bitmasks_e;

const camera_spec_bitmasks_t *camera_spec_get_bitmask_array(int property_id);

#endif /* __CSI_CAMERA_PLATFORM_SPEC_H__ */

