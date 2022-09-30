/******************************************************************************\
|* Copyright (c) 2020 by VeriSilicon Holdings Co., Ltd. ("VeriSilicon")       *|
|* All Rights Reserved.                                                       *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of VeriSilicon.  This is proprietary information owned or licensed by      *|
|* VeriSilicon.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of VeriSilicon.                                         *|
|*                                                                            *|
\******************************************************************************/

#ifndef _CAMERA_DEVICE_BUF_DEFS_H_
#define _CAMERA_DEVICE_BUF_DEFS_H_

#include "types.h"
#include "cam_dct_assert.h"
#include "cam_device_buf_defs_common.h"

#define BUFF_POOL_MAX_INPUT_BUF_NUMBER 8
#define BUFF_POOL_MAX_OUTPUT_BUF_NUMBER 16

#define PIC_BUFFER_ALIGN            (0x400)
#define PIC_BUFFER_ALIGN_META       (0x0)
#define PIC_BUFFER_MEM_SIZE_MAX     (256 * 1024 * 1024)

#define PIC_BUFFER_NUM_INPUT        (1)
#define PIC_BUFFER_SIZE_INPUT       (8 * 1024 * 1024)    // 21MPixel@12bit => 42MByte
#define PIC_BUFFER_NUM_LARGE_IMAGE   (3)
#define PIC_BUFFER_SIZE_LARGE_IMAGE  (8 * 1024 * 1024)    // modify by wuyi to fix alloc memory fail TBD 21MPixel@12bit => 42MByte
#define PIC_BUFFER_NUM_SMALL_IMAGE   (4)
#define PIC_BUFFER_SIZE_SMALL_IMAGE  (8 * 1024 * 1024)     // 2MPixel@4:4:4 10bit  => 8MByte


#ifdef ISP_DEC
#define DEC_TILE_BUFFER_SIZE       (172032)    // (pictureSize/(tile size))*tile status bits)/8  tilesize=> 128byte tile status bits=> 4
#endif
DCT_ASSERT_STATIC(((PIC_BUFFER_NUM_INPUT*PIC_BUFFER_SIZE_INPUT) + (PIC_BUFFER_NUM_LARGE_IMAGE*PIC_BUFFER_SIZE_LARGE_IMAGE) + (PIC_BUFFER_NUM_SMALL_IMAGE*PIC_BUFFER_SIZE_SMALL_IMAGE)) < PIC_BUFFER_MEM_SIZE_MAX);

#ifdef ISP_SINGLE_DOM_OVER_MP
#define PIC_BUFFER_NUM_MAIN_SENSOR  (10)
#define PIC_BUFFER_SIZE_MAIN_SENSOR (16 * 1024 * 1024)    //  2MPixel@4:4:4  => 6MByte
#define PIC_BUFFER_NUM_SELF1_SENSOR  (0)
#define PIC_BUFFER_SIZE_SELF1_SENSOR (6 * 1024 * 1024)     // 2MPixel@4:4:4  => 6MByte, no buffer for sp
#define PIC_BUFFER_NUM_SELF2_SENSOR  (0)
#define PIC_BUFFER_SIZE_SELF2_SENSOR (6 * 1024 * 1024)     // 2MPixel@4:4:4  => 6MByte, no buffer for sp
#define PIC_BUFFER_NUM_PP_PATH_RAW_SENSOR  (0)
#define PIC_BUFFER_SIZE_PP_PATH_RAW_SENSOR (6 * 1024 * 1024)     // 2MPixel@4:4:4  => 6MByte, no buffer for sp

#define PIC_BUFFER_NUM_RDI_SENSOR    (0)
#define PIC_BUFFER_SIZE_RDI_SENSOR   (6 * 1024 * 1024)     // 2MPixel@4:4:4  => 6MByte
#define PIC_BUFFER_NUM_META_SENSOR    (6)
#define PIC_BUFFER_SIZE_META_SENSOR   (1 * 1024 * 1024)     // Meta max size  => 1MByte
#define PIC_BUFFER_NUM_MAIN_SENSOR_IMGSTAB  ( 10 )
#define PIC_BUFFER_SIZE_MAIN_SENSOR_IMGSTAB ( 6 * 1024 * 1024 )    // ISI_RES_4416_3312 => 14MPixel@12bit => 28MByte
#define PIC_BUFFER_NUM_SELF_SENSOR_IMGSTAB  ( 10 )
#define PIC_BUFFER_SIZE_SELF_SENSOR_IMGSTAB ( 6 * 1024 * 1024 )    // ISI_RES_4416_3312 => 14MPixel@12bit => 28MByte

DCT_ASSERT_STATIC(((PIC_BUFFER_NUM_MAIN_SENSOR*PIC_BUFFER_SIZE_MAIN_SENSOR) + (PIC_BUFFER_NUM_SELF1_SENSOR*PIC_BUFFER_SIZE_SELF1_SENSOR) + (PIC_BUFFER_NUM_RDI_SENSOR*PIC_BUFFER_SIZE_RDI_SENSOR) + (PIC_BUFFER_NUM_META_SENSOR*PIC_BUFFER_SIZE_META_SENSOR)) < PIC_BUFFER_MEM_SIZE_MAX);
#else
#define PIC_BUFFER_NUM_MAIN_SENSOR  (10)
#define PIC_BUFFER_SIZE_MAIN_SENSOR (16 * 1024 * 1024)    // ISI_RES_4416_3312 => 14MPixel@12bit => 28MByte
#define PIC_BUFFER_NUM_SELF1_SENSOR  (8)
#define PIC_BUFFER_SIZE_SELF1_SENSOR (6 * 1024 * 1024)     // 2MPixel@4:4:4  => 6MByte
#define PIC_BUFFER_NUM_SELF2_SENSOR  (2)
#define PIC_BUFFER_SIZE_SELF2_SENSOR (6 * 1024 * 1024)     // 2MPixel@4:4:4  => 6MByte
#define PIC_BUFFER_NUM_PP_PATH_RAW_SENSOR  (2)
#define PIC_BUFFER_SIZE_PP_PATH_RAW_SENSOR (6 * 1024 * 1024)     // 2MPixel@4:4:4  => 6MByte

#define PIC_BUFFER_NUM_RDI_SENSOR    (2)
#define PIC_BUFFER_SIZE_RDI_SENSOR   (6 * 1024 * 1024)     // 2MPixel@4:4:4  => 6MByte
#define PIC_BUFFER_NUM_META_SENSOR    (6)
#define PIC_BUFFER_SIZE_META_SENSOR   (1 * 1024 * 1024)     // Meta max size  => 1MByte
#define PIC_BUFFER_NUM_MAIN_SENSOR_IMGSTAB  ( 10 )
#define PIC_BUFFER_SIZE_MAIN_SENSOR_IMGSTAB ( 6 * 1024 * 1024 )    // ISI_RES_4416_3312 => 14MPixel@12bit => 28MByte
#define PIC_BUFFER_NUM_SELF_SENSOR_IMGSTAB  ( 10 )
#define PIC_BUFFER_SIZE_SELF_SENSOR_IMGSTAB ( 6 * 1024 * 1024 )    // ISI_RES_4416_3312 => 14MPixel@12bit => 28MByte

DCT_ASSERT_STATIC(((PIC_BUFFER_NUM_MAIN_SENSOR*PIC_BUFFER_SIZE_MAIN_SENSOR) + (PIC_BUFFER_NUM_SELF1_SENSOR*PIC_BUFFER_SIZE_SELF1_SENSOR) + (PIC_BUFFER_NUM_RDI_SENSOR*PIC_BUFFER_SIZE_RDI_SENSOR) + (PIC_BUFFER_NUM_META_SENSOR*PIC_BUFFER_SIZE_META_SENSOR)) < PIC_BUFFER_MEM_SIZE_MAX);
#endif


#define PIC_BUFFER_NUM_LARGE_BUF_SENSOR_3D   (10)
#define PIC_BUFFER_SIZE_LARGE_BUF_SENSOR_3D  (6 * 1024 * 1024)  // allocated twice!
#define PIC_BUFFER_NUM_SMALL_BUF_SENSOR_3D   (5)
#define PIC_BUFFER_SIZE_SMALL_BUF_SENSOR_3D  (6 * 1024 * 1024)  // allocated twice!

DCT_ASSERT_STATIC(((PIC_BUFFER_NUM_LARGE_BUF_SENSOR_3D*2*PIC_BUFFER_SIZE_LARGE_BUF_SENSOR_3D) + (PIC_BUFFER_NUM_SMALL_BUF_SENSOR_3D*2*PIC_BUFFER_SIZE_SMALL_BUF_SENSOR_3D)) < PIC_BUFFER_MEM_SIZE_MAX);

#ifdef ISP_MI_HANDSHAKE_NANO
#define PIC_BUFFER_NUM_MAIN_MP_HANDSHK   (4)                   // virtual sram buffer number
#endif


typedef enum _CAM_DEVICE_ID_ {
    CAM_ISPCORE_ID_0 = 0,
    CAM_ISPCORE_ID_1 = 1,
    CAM_ISPCORE_ID_MAX = 2
} CAM_DEVICE_ID;

typedef enum __BUFF_MODE__ {
    BUFF_MODE_PHYLINEAR     = 0,
    BUFF_MODE_USRPTR        = 1,  // V4l2 mode
    BUFF_MODE_KERNEL        = 2,
    BUFF_MODE_DMAHANDSHAKE  = 3,
    BUFF_MODE_DIRECTLINK    = 4,
    BUFF_MODE_NAX           = 5,
    BUFF_MODE_INVALID       = 6,
} BUFF_MODE;

#define MEDIA_BUF_ALIGN(buf, align) (((buf)+((align)-1U)) & ~((align)-1U))


/*Typedef HAL handle*/
typedef void *HalHandle_t;

/*******************************************************************************
 * @brief Common SCMI buffer type
 *
 * This structure defines a SCMI buffer. In addition to an address pointer to
 * the actual buffer, this structure also contains the size of the buffer and
 * an optional (may be null) pointer to some buffer meta data. This meta data
 * is defined seperately for each specific buffer type. The buffer_flags
 * variable contains more information about the buffer in the form of
 * (up to 32) bit flags.
 * The bit flags and their meaning are defined by each SCMI system separately.
 * For a list of buffer bit flags, see the respective system's documentation.
 */

/*Be careful of machine int width bits(32/64)*/
typedef struct _ScmiBuffer {
    void        *p_next;        /**< Pointer used by module to chain SCMI-buffers */
    void        *p_address;     /**< Address of the actual buffer */
    uint32_t    base_address;   /**< HW address of the actual buffer */
    BufIdentity buf_id;
#ifdef ISP_MI_HANDSHAKE_NANO
    uint32_t    base_addr_sram_cb; /**< HW address of the Nano handshake Sram Cb address */
    uint32_t    base_addr_sram_cr; /**< HW address of the Nano handshake Sram Cr address */
#endif

    uint32_t    size;           /**< Size of the buffer in bytes */
    uint32_t    buffer_flags;   /**< Generic buffer flags */
    int64_t     time_stamp;     /**< Time stamp of the buffer in ticks with 27 MHz resolution */
    void        *p_meta_data;   /**< Optional pointer to buffer meta data */
} ScmiBuffer;


/**
 *
 * @brief The MediaBufferPool holds elements from type MediaBuffer_t.
 */
typedef struct MediaBuffer_s {
    uint8_t       *pBufAddress;  /**< Base address of system memory buffer(can differ from
                                     actual buffer start address, set in ScmiBuffer). */
    uint32_t      baseAddress;  /**< HW address of system memory buffer. */

#ifdef ISP_MI_HANDSHAKE_NANO
    uint32_t      baseAddrCbSram; /**< HW address of sram Cb memory buffer for Nano Handshake. */
    uint32_t      baseAddrCrSram; /**< HW address of sram Cr memory buffer for Nano Handshake. */
#endif

    uint32_t      baseSize;     /**< Base size of buffer(can differ from actual buffer
                                     size, set in ScmiBuffer). */
    uint32_t      lockCount;    /**< Counting how many times buffer is used. 0 means
                                     buffer belongs to pool and is free. */
    void          *pOwner;
    uint32_t      duration;     /**< Used to calculate duration */
    bool_t        syncPoint;    /**< Indicates if buffer contains a reference frame. */
    bool_t        last;         /**< Media source module signals delivery of last buffer. */
    bool_t        isFull;       /**< Flag set to TRUE when buffer is put in queue as a full buffer */
    ScmiBuffer    buf;          /**< Common SCMI buffer type */
    void          *pNext;        /**< Common next pointer that can be used to create linked lists of media buffers. */
    void          *pMetaData;    /**< Pointer to optional meta data structure. */
} MediaBuffer_t;



// Pic buffers

/*****************************************************************************/
/**
 *          PicBufType_t
 *
 * @brief   The type of image data a picture buffer holds.
 *
 * @note    MVDU_FXQuad requires PIC_BUF_TYPE_YCbCr422 in PIC_BUF_LAYOUT_SEMIPLANAR mode.
 *
 *****************************************************************************/
typedef enum PicBufType_e {
    PIC_BUF_TYPE_INVALID  = 0x00,
    PIC_BUF_TYPE_DATA     = 0x08,   // just some sequential data
    PIC_BUF_TYPE_RAW8     = 0x10,
    PIC_BUF_TYPE_RAW16    = 0x11,   // includes: 9..16bits, MSBit aligned, LSByte first!
    PIC_BUF_TYPE_RAW10    = 0x12,   // includes: 10bits, MSBit aligned, LSByte first!
    PIC_BUF_TYPE_RAW12    = 0x13,   // includes: 12bits, MSBit aligned, LSByte first!
    PIC_BUF_TYPE_RAW14    = 0x14,   // includes: 14bits, MSBit aligned, LSByte first!
    PIC_BUF_TYPE_JPEG     = 0x20,
    PIC_BUF_TYPE_YCbCr444 = 0x30,
    PIC_BUF_TYPE_YCbCr422 = 0x31,
    PIC_BUF_TYPE_YCbCr420 = 0x32,
    PIC_BUF_TYPE_YCbCr400 = 0x33,
    PIC_BUF_TYPE_YCbCr32  = 0x3f,
    // PIC_BUF_TYPE_YCbCr400 = 0x33, // "Black&White"
    PIC_BUF_TYPE_RGB888   = 0x40,
    PIC_BUF_TYPE_RGB666   = 0x41,  // R, G & B are LSBit aligned!
    PIC_BUF_TYPE_RGB565   = 0x42,  // TODO: don't know the memory layout right now, investigate!
    PIC_BUF_TYPE_RGB32    = 0x4f,
    PIC_BUF_TYPE_META     = 0x50,
    _PIC_BUF_TYPE_DUMMY_
} PicBufType_t;


/*****************************************************************************/
/**
 *          PicBufLayout_t
 *
 * @brief   The layout of the image data a picture buffer holds.
 *
 * @note    MVDU_FXQuad requires PIC_BUF_TYPE_YCbCr422 in PIC_BUF_LAYOUT_SEMIPLANAR mode.
 *
 *****************************************************************************/
typedef enum PicBufLayout_e {
    PIC_BUF_LAYOUT_INVALID         = 0,

    PIC_BUF_LAYOUT_COMBINED        = 0x10,  // PIC_BUF_TYPE_DATA:      Data: D0 D1 D2...
                                            // PIC_BUF_TYPE_RAW8:      Data: D0 D1 D2...
                                            // PIC_BUF_TYPE_RAW16/10:  Data: D0L D0H D1L D1H...
                                            // PIC_BUF_TYPE_JPEG:      Data: J0 J1 J2...
                                            // PIC_BUF_TYPE_YCbCr444:  Data: Y0 Cb0 Cr0 Y1 Cb1Cr1...
                                            // PIC_BUF_TYPE_YCbCr422:  Data: Y0 Cb0 Y1 Cr0 Y2 Cb1 Y3 Cr1...
                                            // PIC_BUF_TYPE_YCbCr32:   Data: Cr0 Cb0 Y0 A0 Cr1 Cb1 Y1 A1...
                                            // PIC_BUF_TYPE_RGB888:    Data: R0 G0 B0 R1 B2 G1...
                                            // PIC_BUF_TYPE_RGB666:    Data: {00,R0[5:0]} {00,G0[5:0]} {00,B0[5:0]} {00,R1[5:0]} {00,G2[5:0]} {00,B3[5:0]}...
                                            // PIC_BUF_TYPE_RGB565:    Data: {R0[4:0],G0[5:3]} {G0[2:0],B0[4:0]} {R1[4:0],G1[5:3]} {G1[2:0],B1[4:0]}... (is this correct?)
                                            // PIC_BUF_TYPE_RGB32:     Data: B0 G0 R0 A0 B1 G1 R1 A1...
    PIC_BUF_LAYOUT_BAYER_RGRGGBGB  = 0x11,  // 1st line: RGRG... , 2nd line GBGB... , etc.
    PIC_BUF_LAYOUT_BAYER_GRGRBGBG  = 0x12,  // 1st line: GRGR... , 2nd line BGBG... , etc.
    PIC_BUF_LAYOUT_BAYER_GBGBRGRG  = 0x13,  // 1st line: GBGB... , 2nd line RGRG... , etc.
    PIC_BUF_LAYOUT_BAYER_BGBGGRGR  = 0x14,  // 1st line: BGBG... , 2nd line GRGR... , etc.

    PIC_BUF_LAYOUT_SEMIPLANAR      = 0x20,  // PIC_BUF_TYPE_YCbCr422:  Luma:  Y0 Y1 Y2 Y3... ; Chroma: Cb0 Cr0 Cb1 Cr1...
                                            // PIC_BUF_TYPE_YCbCr420:  Luma:  Y0 Y1 Y2 Y3... ; Chroma: Cb0 Cr0 Cb1 Cr1...
                                            // PIC_BUF_TYPE_YCbCr400:  Luma:  Y0 Y1 Y2 Y3... ; Chroma: not used

    PIC_BUF_LAYOUT_PLANAR          = 0x30,  // PIC_BUF_TYPE_YCbCr444:  Y: Y0 Y1 Y2 Y3...;  Cb: Cb0 Cb1 Cb2 Cb3...; Cr: Cr0 Cr1 Cr2 Cr3...
                                            // PIC_BUF_TYPE_YCbCr422:  Y: Y0 Y1 Y2 Y3...;  Cb: Cb0 Cb1 Cb2 Cb3...; Cr: Cr0 Cr1 Cr2 Cr3...
                                            // PIC_BUF_TYPE_YCbCr420:  Y: Y0 Y1 Y2 Y3...;  Cb: Cb0 Cb1 Cb2 Cb3...; Cr: Cr0 Cr1 Cr2 Cr3...
                                            // PIC_BUF_TYPE_YCbCr400:  Y: Y0 Y1 Y2 Y3...;  Cb: not used;           Cr: not used...
                                            // PIC_BUF_TYPE_RGB888:    R: R0 R1 R2 R3...;  G:  G0 G1 G2 G3...;     B:  B0 B1 B2 B3...
                                            // PIC_BUF_TYPE_RGB666:    R: {00,R0[5:0]}...; G:  {00,G0[5:0]}...;    B:  {00,B0[5:0]}...
    PIC_BUF_LAYOUT_META_DATA      = 0x40,
    _PIC_BUF_LAYOUT_DUMMY_
} PicBufLayout_t;

/*****************************************************************************/
/**
 *          PixelDataAlignMode_t
 *
 * @brief   The align mode of the image data a picture buffer holds.
 *
 *
 *****************************************************************************/

enum {
    PIC_BUF_DATA_ALIGN_MODE_INVALID          = -1,
    PIC_BUF_DATA_UNALIGN_MODE                = 0,  // pixel data not aligned.
    PIC_BUF_DATA_ALIGN_128BIT_MODE           = 1,  // pixel data  aligned with 128 bit.
    PIC_BUF_DATA_ALIGN_16BIT_MODE            = 2,  // pixel data  aligned with 16 bit.
    PIC_BUF_DATA_ALIGN_MODE_MAX
};

/*****************************************************************************/
/**
 *          PicBufPlane_t
 *
 * @brief   Common information about a color component plane within an image buffer.
 *
 *****************************************************************************/
typedef struct PicBufPlane_s {
    uint8_t    *pData;
    uint32_t    BaseAddress;
    uint32_t    PicWidthPixel;
    uint32_t    PicWidthBytes;
    uint32_t    PicHeightPixel;
    uint8_t     PixelDataAlignMode;
} PicBufPlane_t;

/*****************************************************************************/
/**
 *          PicBufMetaData_t
 *
 * @brief   All the meta data one needs to know about an image buffer.
 *
 *****************************************************************************/
typedef struct PicBufMetaData_s {
    PicBufType_t            Type;       // type of picture data
    PicBufLayout_t          Layout;     // kind of data layout
    uint32_t                Align;      // min. alignment required for color component planes or sub buffer base adresses for this picture buffer
    int64_t                 TimeStampUs;  // timestamp in us
    struct PicBufMetaData_s *pNext3D;   // Reference to PicBufMetaData of the subsequent buffer in a 3D descriptor chain, valid only in 3D mode; set to NULL if last in chain or for 2D mode.
                                        // Note: depending on the 3D format in use, the primary buffer holds left image data while the secondary buffer holds right or depth information.
                                        //       Certain 3D formats require further buffers, in which case the 3D chain consists of more than two descriptors.
    BufIdentity             buf_id;
    union Data_u {                      // the type and layout dependent meta data
        struct data_s {      // DATA
            uint8_t    *pData;
            uint32_t    BaseAddress;
            uint32_t    DataSize;
        } data;

        struct data_meta {   // meta
            uint8_t    *pData;
            uint32_t    BaseAddress;
            uint32_t    DataSize;
        } meta;

        PicBufPlane_t raw;   // RAW8, RAW16

        struct jpeg_s {      // JPEG
            uint8_t    *pHeader;
            uint32_t    HeaderSize;
            uint8_t    *pData;
            uint32_t    BaseAddress;
            uint32_t    DataSize;
        } jpeg;

        union YCbCr_u {     // YCbCr444, YCbCr422, YCbCr420, YCbCr32
            PicBufPlane_t combined;
            struct semiplanar_s {
                PicBufPlane_t Y;
                PicBufPlane_t CbCr;
            } semiplanar;
            struct planar_YUV_s {
                PicBufPlane_t Y;
                PicBufPlane_t Cb;
                PicBufPlane_t Cr;
            } planar;
        } YCbCr;

        union RGB_u {        // RGB888, RGB32
            PicBufPlane_t combined;
            struct planar_RGB_s {
                PicBufPlane_t R;
                PicBufPlane_t G;
                PicBufPlane_t B;
            } planar;
        } RGB;
#ifdef ISP_MI_BP
        union BAYER_u {         // rggb bggr
            struct planar_BAYER_s {
                PicBufPlane_t R;
                PicBufPlane_t Gr;
                PicBufPlane_t Gb;
                PicBufPlane_t B;
            } planar;
        } BAYER;
#endif
    } Data;
} PicBufMetaData_t;

#endif  // _CAMERA_DEVICE_BUF_DEFS_H_
