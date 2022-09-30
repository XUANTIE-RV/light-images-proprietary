/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_COMMON_H__
#define __CSI_COMMON_H__

#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

typedef union csi_api_version {
	struct {
		uint16_t minor;
		uint16_t major;
	};
	uint32_t version;
} csi_api_version_u;

typedef struct csi_size {
	uint32_t	width;
	uint32_t	height;
} csi_size_s;

typedef struct csi_rect {
	uint32_t	pos_x;
	uint32_t	pos_y;
	uint32_t	width;
	uint32_t	height;
} csi_rect_s;


enum {
	CSI_IO_PATTERN_INTERNAL_MEMORY =  0x01, /* Internal preparation IO memory mode */
	CSI_IO_PATTERN_EXTERNAL_MEMORY =  0x02  /* External preparation IO memory mode */
};

typedef enum csi_common_err_code {
	CSI_SUCCESS,
	CSI_ERR_BAD_PARAM,
	CSI_ERR_NOT_SUPPORT,
	CSI_ERR_BUSY,
	CSI_ERR_OUT_OF_MEMORY,
	CSI_ERR_NEED_MORE_DATA,
	CSI_ERR_NEED_MORE_IO_FRAME,
	CSI_ERR_TIMEOUT,
	CSI_ERR_WAIT
} csi_common_err_code_e;


int32_t csi_hal_init();
int32_t csi_hal_deinit();


#ifdef  __cplusplus
}
#endif

#endif /* __CSI_COMMON_H__ */
