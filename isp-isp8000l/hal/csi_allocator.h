/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_ALLOCATOR_H__
#define __CSI_ALLOCATOR_H__

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>

typedef enum csi_allocator_type {
	CSI_ALLOCATOR_TYPE_SYSTEM,
	CSI_ALLOCATOR_TYPE_SYSTEM_CONTIG,
	CSI_ALLOCATOR_TYPE_CARVEOUT,
	CSI_ALLOCATOR_TYPE_DMA,
	CSI_ALLOCATOR_TYPE_CUSTOM,
} csi_allocator_type_e;	// refer from ion_heap_type

typedef struct csi_mem {
	void *usr_addr;
	union {
		int64_t phy_addr; /* 0 means invalid */
		int fd; /* -1 means invalid */
	};

	size_t size;
	void *opaque; /* not for user, DO NOT use or modify it */
} csi_mem_s;


typedef struct csi_allocator {
	//int (*init)(char *args);
	csi_mem_s *(*alloc)(csi_allocator_type_e type, size_t size, uint32_t align);
	void (*free)(csi_mem_s *mem);
	void *(*map)(csi_mem_s *mem);
	void (*unmap)(csi_mem_s *mem);
} csi_allocator_s;

//csi_allocator_s *csi_allocator_get(csi_allocator_type_e type);
int32_t csi_hal_set_allocator(csi_allocator_s allocator);
int32_t csi_hal_get_allocator(csi_allocator_s *allocator);

#endif /* __CSI_ALLOCATOR_H__ */
