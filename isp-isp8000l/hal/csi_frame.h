/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: LuChongzhi <chongzhi.lcz@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_FRAME_H__
#define __CSI_FRAME_H__

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>

/*
 * CSI frame defination is below, including
 *
 *  @-- [frm_id] ----------------@
 *  |  __________   ___________  |
 *  | |          | |           | |
 *  | | img_info | | meta_info | |
 *  | |__________| |___________| |
 *  |                            |
 *  @------- csi_frame_s --------@
 */

#define CSI_IMAGE_MAX_PLANES	3
#define CSI_IMAGE_I420_PLANES	2

typedef enum csi_pixel_fmt {
	CSI_PIX_FMT_I420,	// YYYYYYYY UU VV, alias: YUV420P/YU12/IYUV
	CSI_PIX_FMT_NV12,	// YYYYYYYY UV UV, alias: YUV420SP
	CSI_PIX_FMT_BGR,
	CSI_PIX_FMT_RAW_8BIT,/*default no align*/
	CSI_PIX_FMT_RAW_10BIT,
	CSI_PIX_FMT_RAW_12BIT,
	CSI_PIX_FMT_RAW_14BIT,
	CSI_PIX_FMT_RAW_16BIT,
	CSI_PIX_FMT_RGB_PLANAR_888,
	CSI_PIX_FMT_RGB_INTEVLEAVED_888,
	CSI_PIX_FMT_YUV_PLANAR_422,
	CSI_PIX_FMT_YUV_PLANAR_420,
	CSI_PIX_FMT_YUV_PLANAR_444,
	CSI_PIX_FMT_YUV_SEMIPLANAR_422,
	CSI_PIX_FMT_YUV_SEMIPLANAR_420,
	CSI_PIX_FMT_YUV_SEMIPLANAR_444,
	CSI_PIX_FMT_YUV_TEVLEAVED_422,
	CSI_PIX_FMT_YUV_TEVLEAVED_420,
	CSI_PIX_FMT_YUV_TEVLEAVED_444,
} csi_pixel_fmt_e;

typedef enum csi_color_gamut {
	CSI_COLOR_GAMUT_DEFAULT = 0,
	CSI_COLOR_GAMUT_BT601,
	CSI_COLOR_GAMUT_BT709,
	CSI_COLOR_GAMUT_BT2020,
} csi_color_gamut_e;

typedef enum csi_meta_type {
	CSI_META_TYPE_SYSTEM,
	CSI_META_TYPE_CAMERA,
	CSI_META_TYPE_VDEC,
	CSI_META_TYPE_GPU,
	CSI_META_TYPE_G2D,
} csi_meta_type_e;

typedef enum csi_img_type {
	CSI_IMG_TYPE_DMA_BUF,		// memory allocated via dma-buf
	CSI_IMG_TYPE_SYSTEM_CONTIG,	// memory allocated via kmalloc
	CSI_IMG_TYPE_CARVEOUT,		// memory allocated from reserved memory
	CSI_IMG_TYPE_UMALLOC,		// memory allocated from user mode malloc
	CSI_IMG_TYPE_SHM,		// memory allocated from share memory(<sys/shm.h>)
} csi_img_type_e;

typedef enum csi_meta_value_type {
	CSI_META_VALUE_TYPE_BOOL,
	CSI_META_VALUE_TYPE_INT,
	CSI_META_VALUE_TYPE_UINT,
	CSI_META_VALUE_TYPE_STR,
	CSI_META_VALUE_TYPE_TIMEVAL,
} csi_meta_value_type_e;


/*
 * CSI frame config design
 *
 *     line_stride -->|
 *   img_width -->|   |
 *   _____________|___| __ start addr of frame/image, alignment (such as 4096)
 *  |             |   |
 *  | img_content |   |
 *  |_____________|___| __ end addr of image, No alignment requirement
 *  | extra_data      |
 *  |_________________| __ end addr of frame, No alignment requirement
 */

typedef struct csi_img_format {
	uint32_t	width;
	uint32_t	height;
	csi_pixel_fmt_e	pix_fmt;
} csi_img_format_t;


typedef struct {
    int32_t stride_alignment;	// should >= to the width of the image according to IP design
    int32_t addr_alignment;	// physical begin address alignment according to IP design
    int32_t extra_size;	    // storaging platform private data according to IP design (meta data storage is suggested)
    int32_t min_buffers_count;  // minimum number of buffers required
} csi_frame_config_s;       // New defined structure

typedef struct {
    int fds;  	// stores in dma_buf memory(s)
    unsigned long offset;
} cam_frame_dmabuf_t;

typedef struct csi_img {
	csi_img_type_e	type;
	size_t		size;
	uint32_t	width;
	uint32_t	height;
	csi_pixel_fmt_e	pix_format;
	csi_color_gamut_e color_gamut;
	uint32_t	num_planes;
	union {
        cam_frame_dmabuf_t dmabuf[CSI_IMAGE_MAX_PLANES];		// stores in dma_buf memory(s)
        int fds[CSI_IMAGE_MAX_PLANES];		// stores in dma_buf memory(s)
		void  *phy_addr[CSI_IMAGE_MAX_PLANES];	// stores in phy contigous memory(s)
		void  *usr_addr[CSI_IMAGE_MAX_PLANES];	// stores in usr contigous memory(s)
	};
	uint32_t strides[CSI_IMAGE_MAX_PLANES];
	uint32_t offsets[CSI_IMAGE_MAX_PLANES];
	uint64_t modifier;
    void *priv;
} csi_img_s;

typedef struct csi_meta {
	csi_meta_type_e  type;
	size_t           size;
	void            *data;
} csi_meta_s;

typedef struct csi_frame {
	csi_img_s  img;
	csi_meta_s meta;
} csi_frame_s;


int   csi_frame_reference(csi_frame_s *frame_dest, csi_frame_s *frame_src);
int   csi_frame_release(csi_frame_s *frame);
void *csi_frame_mmap(csi_frame_s *frame);
int   csi_frame_munmap(csi_frame_s *frame);

#endif /* __CSI_FRAME_H__ */
