#ifndef __CSI_G2D_TYPES_H__
#define __CSI_G2D_TYPES_H__

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define swap(a, b) \
	do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)

#define __cmp(x, y, op)         ((x) op (y) ? (x) : (y))

#define __cmp_once(x, y, op) ({         \
        typeof(x) __x = (x);            \
        typeof(y) __y = (y);            \
        __cmp(__x, __y, op); })

#define min(x, y)               __cmp_once(x, y, <)
#define max(x, y)               __cmp_once(x, y, >)

#define csi_g2d_fourcc(a, b, c, d)				\
	((unsigned int )(a) | ((unsigned int)(b) << 8) |	\
	((unsigned int )(c) << 16) | ((unsigned int)(d) << 24))

/* 32 bpp RGB */
#define CSI_G2D_FMT_XRGB8888		csi_g2d_fourcc('X', 'R', '2', '4')
#define CSI_G2D_FMT_ARGB8888		csi_g2d_fourcc('A', 'R', '2', '4')
#define CSI_G2D_FMT_RGBX8888		csi_g2d_fourcc('R', 'A', '2', '4')
#define CSI_G2D_FMT_RGBA8888		csi_g2d_fourcc('R', 'X', '2', '4')
#define CSI_G2D_FMT_XBGR8888		csi_g2d_fourcc('X', 'B', '2', '4')
#define CSI_G2D_FMT_ABGR8888		csi_g2d_fourcc('A', 'B', '2', '4')
#define CSI_G2D_FMT_BGRX8888		csi_g2d_fourcc('B', 'X', '2', '4')
#define CSI_G2D_FMT_BGRA8888		csi_g2d_fourcc('B', 'G', '2', '4')

/* 24 bpp RGB */
#define CSI_G2D_FMT_RGB888		csi_g2d_fourcc('R', 'G', '2', '4')
#define CSI_G2D_FMT_BGR888		csi_g2d_fourcc('B', 'G', '2', '4')
#define CSI_G2D_FMT_BGR888_PLANAR	csi_g2d_fourcc('B', 'R', '8', 'P')
#define CSI_G2D_FMT_RGB888_PLANAR	csi_g2d_fourcc('R', 'B', '8', 'P')

/* 16 bpp RGB */
#define CSI_G2D_FMT_RGB565		csi_g2d_fourcc('R', 'G', '1', '6')
#define CSI_G2D_FMT_BGR565		csi_g2d_fourcc('B', 'G', '1', '6')
#define CSI_G2D_FMT_XRGB1555		csi_g2d_fourcc('X', 'R', '1', '5')
#define CSI_G2D_FMT_ARGB1555		csi_g2d_fourcc('A', 'R', '1', '5')
#define CSI_G2D_FMT_RGBX5551		csi_g2d_fourcc('R', 'X', '1', '5')
#define CSI_G2D_FMT_RGBA5551		csi_g2d_fourcc('R', 'A', '1', '5')
#define CSI_G2D_FMT_XBGR1555		csi_g2d_fourcc('X', 'B', '1', '5')
#define CSI_G2D_FMT_ABGR1555		csi_g2d_fourcc('A', 'B', '1', '5')
#define CSI_G2D_FMT_BGRX5551		csi_g2d_fourcc('B', 'X', '1', '5')
#define CSI_G2D_FMT_BGRA5551		csi_g2d_fourcc('B', 'A', '1', '5')
#define CSI_G2D_FMT_XRGB4444		csi_g2d_fourcc('X', 'R', '1', '2')
#define CSI_G2D_FMT_ARGB4444		csi_g2d_fourcc('A', 'R', '1', '2')
#define CSI_G2D_FMT_RGBX4444		csi_g2d_fourcc('R', 'X', '1', '2')
#define CSI_G2D_FMT_RGBA4444		csi_g2d_fourcc('R', 'A', '1', '2')
#define CSI_G2D_FMT_XBGR4444		csi_g2d_fourcc('X', 'B', '1', '2')
#define CSI_G2D_FMT_ABGR4444		csi_g2d_fourcc('A', 'B', '1', '2')
#define CSI_G2D_FMT_BGRX4444		csi_g2d_fourcc('B', 'X', '1', '2')
#define CSI_G2D_FMT_BGRA4444		csi_g2d_fourcc('B', 'A', '1', '2')

/* 10Bit RGB */
#define CSI_G2D_FMT_XRGB2101010		csi_g2d_fourcc('X', 'R', '3', '0')
#define CSI_G2D_FMT_ARGB2101010		csi_g2d_fourcc('A', 'R', '3', '0')
#define CSI_G2D_FMT_RGBX1010102		csi_g2d_fourcc('R', 'X', '3', '0')
#define CSI_G2D_FMT_RGBA1010102		csi_g2d_fourcc('R', 'A', '3', '0')
#define CSI_G2D_FMT_XBGR2101010		csi_g2d_fourcc('X', 'B', '3', '0')
#define CSI_G2D_FMT_ABGR2101010		csi_g2d_fourcc('A', 'B', '3', '0')
#define CSI_G2D_FMT_BGRX1010102		csi_g2d_fourcc('B', 'X', '3', '0')
#define CSI_G2D_FMT_BGRA1010102		csi_g2d_fourcc('B', 'A', '3', '0')

/* 8 bpp RGB */
#define CSI_G2D_FMT_A8			csi_g2d_fourcc('A', '8', ' ', ' ')
#define CSI_G2D_FMT_INDEX8		csi_g2d_fourcc('I', '8', ' ', ' ')

/* packed YUV formats */
#define CSI_G2D_FMT_YUY2		csi_g2d_fourcc('Y', 'U', 'Y', 'V')
#define CSI_G2D_FMT_YVYU		csi_g2d_fourcc('Y', 'V', 'Y', 'U')
#define CSI_G2D_FMT_UYVY		csi_g2d_fourcc('U', 'Y', 'V', 'Y')
#define CSI_G2D_FMT_VYUY		csi_g2d_fourcc('V', 'Y', 'U', 'Y')

/* planar YUV formats */
#define CSI_G2D_FMT_I420		csi_g2d_fourcc('Y', 'U', '1', '2')
#define CSI_G2D_FMT_YV12		csi_g2d_fourcc('Y', 'V', '1', '2')
#define CSI_G2D_FMT_YUV422		csi_g2d_fourcc('Y', 'U', '1', '6')
#define CSI_G2D_FMT_YVU422		csi_g2d_fourcc('Y', 'V', '1', '6')
#define CSI_G2D_FMT_YUV444		csi_g2d_fourcc('Y', 'U', '2', '4')
#define CSI_G2D_FMT_YVU444		csi_g2d_fourcc('Y', 'V', '2', '4')

/* semi-planar YUV formats */
#define CSI_G2D_FMT_NV16		csi_g2d_fourcc('N', 'V', '1', '6')
#define CSI_G2D_FMT_NV61		csi_g2d_fourcc('N', 'V', '6', '1')
#define CSI_G2D_FMT_NV12		csi_g2d_fourcc('N', 'V', '1', '2')
#define CSI_G2D_FMT_NV21		csi_g2d_fourcc('N', 'V', '2', '1')
#define CSI_G2D_FMT_P010		csi_g2d_fourcc('P', '0', '1', '0')

/* TODO: verify below formats supported or not:
   gcvSURF_P010_LSB gcvSURF_I010 gcvSURF_I010_LSB
 */
#define CSI_G2D_FMT_NV16_10BIT		csi_g2d_fourcc('N', '1', '6', 'X')
#define CSI_G2D_FMT_NV61_10BIT		csi_g2d_fourcc('N', '6', '1', 'X')
#define CSI_G2D_FMT_NV12_10BIT		csi_g2d_fourcc('N', '1', '2', 'X')
#define CSI_G2D_FMT_NV21_10BIT		csi_g2d_fourcc('N', '2', '1', 'X')

#ifdef __cplusplus
}
#endif

#endif
