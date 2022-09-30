/**
* Copyright (C) 2021 Alibaba Group Holding Limited
**/
#ifndef _CSI_FRAME_EX_H
#define _CSI_FRAME_EX_H

#include <csi_common.h>

#define MAX_PLANE_COUNT  3

typedef enum {
	CSI_PIXEL_FORMAT_RGB_444 = 0,
	CSI_PIXEL_FORMAT_RGB_555,
	CSI_PIXEL_FORMAT_RGB_565,
	CSI_PIXEL_FORMAT_RGB_888,

	CSI_PIXEL_FORMAT_BGR_444,
	CSI_PIXEL_FORMAT_BGR_555,
	CSI_PIXEL_FORMAT_BGR_565,
	CSI_PIXEL_FORMAT_BGR_888,

	CSI_PIXEL_FORMAT_ARGB_1555,
	CSI_PIXEL_FORMAT_ARGB_4444,
	CSI_PIXEL_FORMAT_ARGB_8565,
	CSI_PIXEL_FORMAT_ARGB_8888,
	CSI_PIXEL_FORMAT_ARGB_2BPP,

	CSI_PIXEL_FORMAT_ABGR_1555,
	CSI_PIXEL_FORMAT_ABGR_4444,
	CSI_PIXEL_FORMAT_ABGR_8565,
	CSI_PIXEL_FORMAT_ABGR_8888,

	CSI_PIXEL_FORMAT_RGB_BAYER_8BPP,
	CSI_PIXEL_FORMAT_RGB_BAYER_10BPP,
	CSI_PIXEL_FORMAT_RGB_BAYER_12BPP,
	CSI_PIXEL_FORMAT_RGB_BAYER_14BPP,
	CSI_PIXEL_FORMAT_RGB_BAYER_16BPP,

	CSI_PIXEL_FORMAT_YVU_PLANAR_422,
	CSI_PIXEL_FORMAT_YVU_PLANAR_420,
	CSI_PIXEL_FORMAT_YVU_PLANAR_444,

	CSI_PIXEL_FORMAT_YVU_SEMIPLANAR_422,
	CSI_PIXEL_FORMAT_YVU_SEMIPLANAR_420,
	CSI_PIXEL_FORMAT_YVU_SEMIPLANAR_444,

	CSI_PIXEL_FORMAT_YUV_SEMIPLANAR_422,
	CSI_PIXEL_FORMAT_YUV_SEMIPLANAR_420,
	CSI_PIXEL_FORMAT_YUV_SEMIPLANAR_444,

	CSI_PIXEL_FORMAT_YUYV_PACKAGE_422,
	CSI_PIXEL_FORMAT_YVYU_PACKAGE_422,
	CSI_PIXEL_FORMAT_UYVY_PACKAGE_422,
	CSI_PIXEL_FORMAT_VYUY_PACKAGE_422,
	CSI_PIXEL_FORMAT_YYUV_PACKAGE_422,
	CSI_PIXEL_FORMAT_YYVU_PACKAGE_422,
	CSI_PIXEL_FORMAT_UVYY_PACKAGE_422,
	CSI_PIXEL_FORMAT_VUYY_PACKAGE_422,
	CSI_PIXEL_FORMAT_VY1UY0_PACKAGE_422,

	CSI_PIXEL_FORMAT_YUV_400,
	CSI_PIXEL_FORMAT_UV_420,

	CSI_PIXEL_FORMAT_MAX
} csi_pixel_format_e;

#if 0
typedef enum {
	CSI_PICTURE_TYPE_NONE = 0, /* undefined */
	CSI_PICTURE_TYPE_I,        /* intra */
	CSI_PICTURE_TYPE_P,        /* predicted */
	CSI_PICTURE_TYPE_B,        /* BI-dir predictd */
	CSI_PICTURE_TYPE_S,        /* S(GMC)-VOP MPEG-4 */
	CSI_PICTURE_TYPE_SI,       /* Switching intra */
	CSI_PICTURE_TYPE_SP,       /* Switching Predicted */
	CSI_PICTURE_TYPE_BI,       /* BI Type */
} csi_picture_type_e;
#endif


typedef enum {
	CSI_CHROMA_LOCATION_LEFT,
	CSI_CHROMA_LOCATION_CENTER,
	CSI_CHROMA_LOCATION_TOPLEFT,
	CSI_CHROMA_LOCATION_TOP,
	CSI_CHROMA_LOCATION_BOTTOMLEFT,
	CSI_CHROMA_LOCATION_BOTTOM,
	CSI_CHROMA_LOCATION_DV420
} csi_chroma_location_e;

#if 0
typedef enum {
	CSI_FRAME_COMPRESS_MODE_NONE = 0, /* no compress */
	CSI_FRAME_COMPRESS_MODE_SEQ,      /* compress unit is 256x1 bytes as a segment. */
	CSI_FRAME_COMPRESS_MODE_TILE,     /* compress unit is a tile. */
	CSI_FRAME_COMPRESS_MODE_LINE,     /* compress unit is the whole line.  raw for VI */
	CSI_FRAME_COMPRESS_MODE_FRAME,    /* compress unit is the whole frame. YUV for VI(3DNR), RGB for TDE(write)/VO(read) */
	CSI_FRAME_COMPRESS_MAX
} csi_frame_compress_mode;
#endif

typedef enum {
	CSI_COLORSPACE_ACES,   /* RGB color space ACES standardized as SMPTE ST 2065-1:2012. */
	CSI_COLORSPACE_ACESCG, /* RGB color space ACEScg standardized as Academy S-2014-004. */
	CSI_COLORSPACE_RGB,    /* RGB color space Adobe RGB (1998). */
	CSI_COLORSPACE_BT2020, /* RGB color space BT.2020 standardized as Rec. */
	CSI_COLORSPACE_BT709,   /* RGB color space BT.709 standardized as Rec. */
	CSI_COLORSPACE_CIE_LAB, /* Lab color space CIE L*a*b*. */
	CSI_COLORSPACE_CIE_XYZ, /* XYZ color space CIE XYZ.  */
	CSI_COLORSPACE_DCI_P3,  /* RGB color space DCI-P3 standardized as SMPTE RP 431-2-2007. */
	CSI_COLORSPACE_DISPLAY_p3, /* RGB color space Display P3 based on SMPTE RP 431-2-2007 and IEC 61966-2.1:1999.  */
	CSI_COLORSPACE_EXTENDED_SRGB, /* RGB color space scRGB-nl standardized as IEC 61966-2-2:2003. */
	CSI_COLORSPACE_LINEAR_EXTENDED_SRGB, /* RGB color space scRGB standardized as IEC 61966-2-2:2003.  */
	CSI_COLORSPACE_LINEAR_SRGB, /* RGB color space sRGB standardized as IEC 61966-2.1:1999.  */
	CSI_COLORSPACE_NTSC_1953, /* RGB color space NTSC, 1953 standard.  */
	CSI_COLORSPACE_PRO_PHOTO_RGB, /* RGB color space NTSC, 1953 standard. */
	CSI_COLORSPACE_SMPTE_C, /* RGB color space SMPTE C.  */
	CSI_COLORSPACE_SRGB  /* RGB color space sRGB standardized as IEC 61966-2.1:1999.  */
} csi_color_space_e;

typedef enum {
	CSI_VIDEO_FORMAT_UNDEFINED,
	CSI_VIDEO_FORMAT_COMPONENT,
	CSI_VIDEO_FORMAT_PAL,
	CSI_VIDEO_FORMAT_NTSC,
	CSI_VIDEO_FORMAT_SECAM,
	CSI_VIDEO_FORMAT_MAC
} csi_video_format_e;


typedef struct csi_frame_info {
	int32_t width;
	int32_t height;
	/* the region of interest of the frame */
	//csi_rect_s roi;
	csi_pixel_format_e pixel_format;
	//csi_frame_compress_mode compress_mode;
	csi_color_space_e  color_space;
	csi_chroma_location_e chroma_location;
} csi_frame_info_s;

typedef struct csi_frame_data {
	int64_t pts;
	int64_t dts;
	int64_t frame_num;
	int8_t is_key_frame;
	int8_t is_eos; /* last frame */

	int32_t offset[MAX_PLANE_COUNT];
	int32_t stride[MAX_PLANE_COUNT];
	int32_t num_plane;

	void *vir_addr[MAX_PLANE_COUNT];
	union {
		int fd[MAX_PLANE_COUNT];  /* -1 means invalid */
		int64_t phy_addr[MAX_PLANE_COUNT]; /* 0 means invalid */
	};
} csi_frame_data_s;


typedef struct csi_frame_ex {
	csi_frame_info_s frame_info;
	csi_frame_data_s frame_data;
	void *opaque; /* not for user, DO NOT use or modify it */
} csi_frame_ex_s;

#if 0
typedef struct csi_bitstream {
	void *buf;
	uint32_t len;
	uint8_t is_eos;   //is the end of stream
	uint8_t is_frame; //is whole compress frame data
} csi_bitstream_s;
#endif

#endif