#ifndef __CSI_G2D_H__
#define __CSI_G2D_H__

#include <csi_g2d_types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct _g2d_surface;
typedef struct _g2d_surface g2d_surface;

struct _g2d_context;
typedef struct _g2d_context g2d_context;

typedef enum _csi_g2d_tiling {
    CSI_G2D_LINEAR,
} csi_g2d_tiling;

typedef enum _csi_g2d_rotation {
    CSI_G2D_ROTATION_0_DEGREE,
    CSI_G2D_ROTATION_90_DEGREE,
    CSI_G2D_ROTATION_180_DEGREE,
    CSI_G2D_ROTATION_270_DEGREE,
    CSI_G2D_ROTATION_FLIP_X = 0x10000000,
    CSI_G2D_ROTATION_FLIP_Y = 0x20000000,
} csi_g2d_rotation;

/* TODO: maximum 16 different modes */
typedef enum _csi_g2d_blend_mode {
    CSI_G2D_BLEND_MODE_CLEAR,
    CSI_G2D_BLEND_MODE_SRC,
    CSI_G2D_BLEND_MODE_DST,
    CSI_G2D_BLEND_MODE_SRC_OVER,
    CSI_G2D_BLEND_MODE_DST_OVER,
    CSI_G2D_BLEND_MODE_SRC_IN,
    CSI_G2D_BLEND_MODE_DST_IN,
    CSI_G2D_BLEND_MODE_SRC_OUT,
    CSI_G2D_BLEND_MODE_DST_OUT,
    CSI_G2D_BLEND_MODE_SRC_ATOP,
    CSI_G2D_BLEND_MODE_DST_ATOP,
    CSI_G2D_BLEND_MODE_ADD,
    CSI_G2D_BLEND_MODE_XOR,
} csi_g2d_blend_mode;

typedef enum _csi_g2d_alpha_mode {
    CSI_G2D_ALPHA_MODE_STRAIGHT,
    CSI_G2D_ALPHA_MODE_INVERSED
} csi_g2d_alpha_mode;

typedef enum _csi_g2d_global_alpha_mode {
    CSI_G2D_GLOBAL_ALPHA_MODE_OFF,
    CSI_G2D_GLOBAL_ALPHA_MODE_ON,
    CSI_G2D_GLOBAL_ALPHA_MODE_SCALE
} csi_g2d_global_alpha_mode;

typedef enum _csi_g2d_global_multiply_mode {
    CSI_G2D_GLOBAL_COLOR_MULTIPLY_DISABLE,
    CSI_G2D_GLOBAL_COLOR_MULTIPLY_ALPHA,
    CSI_G2D_GLOBAL_COLOR_MULTIPLY_COLOR
} csi_g2d_global_multiply_mode;

typedef enum _csi_g2d_yuv_mode {
    CSI_G2D_YUV_MODE_BT601,
    CSI_G2D_YUV_MODE_BT709,
    CSI_G2D_YUV_MODE_BT2020,
    CSI_G2D_YUV_MODE_USER_DEFINED,
    CSI_G2D_YUV_MODE_USER_DEFINED_CLAMP,
    CSI_G2D_YUV_MODE_NUM,
} csi_g2d_yuv_mode;

typedef enum _csi_g2d_filter_tap {
    CSI_G2D_FILTER_TAP_1,
    CSI_G2D_FILTER_TAP_3,
    CSI_G2D_FILTER_TAP_5
} csi_g2d_filter_tap;

typedef struct _csi_g2d_point {
    int x;
    int y;
} csi_g2d_point;

typedef struct _csi_g2d_line {
    csi_g2d_point start;
    csi_g2d_point end;
} csi_g2d_line;

typedef struct _csi_g2d_triangle {
    csi_g2d_line line[3];
} csi_g2d_triangle;

typedef struct _csi_g2d_rectangle {
    csi_g2d_line line[4];
} csi_g2d_rectangle;

typedef struct _csi_g2d_region {
    unsigned int left;
    unsigned int top;
    unsigned int right;
    unsigned int bottom;
} csi_g2d_region;

typedef struct _csi_g2d_surface {
    g2d_surface *priv;	/* point to g2d_surface */
    int width;		/* in pixels */
    int height;		/* in pixels */
    int cpp[3];		/* bytes per pixel (per plane) */
    int stride[3];	/* in bytes  */
    int nplanes;	/* planes number */
    int alignment;	/* in pixels */
    unsigned int format; /* in fourcc */
    csi_g2d_tiling tiling;
    void *lgcaddr[3];
    unsigned int flags;
} csi_g2d_surface;

int csi_g2d_open(void);
int csi_g2d_close(void);
int csi_g2d_flush(void);

/* csi_g2d_surface APIs */
int csi_g2d_surface_create(csi_g2d_surface *csi_surface);
int csi_g2d_surface_destroy(csi_g2d_surface *csi_surface);
int csi_g2d_surface_select_source(unsigned int id);
int csi_g2d_surface_set_source(csi_g2d_surface *surface);
int csi_g2d_surface_set_target(csi_g2d_surface *surface);
int csi_g2d_surface_set_source_clipping(csi_g2d_region *region);
int csi_g2d_surface_set_target_clipping(csi_g2d_region *region);
int csi_g2d_surface_set_source_yuv_mode(csi_g2d_yuv_mode yuv_mode);
int csi_g2d_surface_set_target_yuv_mode(csi_g2d_yuv_mode yuv_mode);

int csi_g2d_surface_set_source_alpha_mode(
	csi_g2d_alpha_mode alpha_mode,
	csi_g2d_blend_mode blend_mode
);
int csi_g2d_surface_set_source_global_alpha_mode(
	csi_g2d_global_alpha_mode global_mode,
	unsigned int global_color
);
int csi_g2d_surface_set_source_multiply_mode(
	bool multiply,
	csi_g2d_global_multiply_mode global_mode
);

int csi_g2d_surface_set_target_alpha_mode(
	csi_g2d_alpha_mode alpha_mode,
	csi_g2d_blend_mode blend_mode
);
int csi_g2d_surface_set_target_global_alpha_mode(
	csi_g2d_global_alpha_mode global_mode,
	unsigned int global_color
);
int csi_g2d_surface_set_target_multiply_mode(
	bool multiply,
	bool demultiply
);

int csi_g2d_surface_enable_disable_alpha_blend(bool enable);

/* csi_g2d_brush APIs */
int csi_g2d_brush_create(unsigned int argb_color, bool convert);
int csi_g2d_brush_destroy(void);

int csi_g2d_palette_load(unsigned int *table,
			 unsigned int count,
			 bool convert);

/* csi_g2d_line APIs: draw line(s) in target */
int csi_g2d_line_draw_line(csi_g2d_line *lines, int nlines);
int csi_g2d_line_draw_triangle(csi_g2d_triangle *triangles,
			       int ntriangles);
int csi_g2d_line_draw_rectangle(csi_g2d_rectangle *rectangles,
				int nrectangles);

/* blit properties config APIs */
int csi_g2d_blit_set_rotation(csi_g2d_rotation rotation);
int csi_g2d_blit_set_mirror(bool hmirror, bool vmirror);
int csi_g2d_blit_set_filter_tap(csi_g2d_filter_tap htap,
				csi_g2d_filter_tap vtap);

/* clear target: clear color should be ARGB8888 */
int csi_g2d_fill(csi_g2d_region *regions,
		 int nregions,
		 unsigned int argb_color);

/* blit without resize, support alpha blending */
int csi_g2d_blit_bitblit(csi_g2d_region *target_regions, int nregions);

/* scaling up or down APIs */
int csi_g2d_blit_stretchblit(csi_g2d_region *target_regions, int nregions);
int csi_g2d_blit_filterblit(csi_g2d_region *target_regions, int nregions);

/* multisrc blit API */
int csi_g2d_blit_multisrc_blit(
	unsigned int src_mask,
	csi_g2d_region *target_regions,
	int nregions
);

#ifdef __cplusplus
}
#endif

#endif