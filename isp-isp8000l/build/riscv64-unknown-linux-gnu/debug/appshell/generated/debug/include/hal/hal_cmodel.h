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
/**
 * @file hal_cmodel.h
 *
 * @brief   MockedUp variant of Hardware Abstraction Layer
 *
 *          Exports the cmodel version of the HAL API's inline functions. You could
 *          use it for your PC implementation to check general interaction of your
 *          code with the HAL.
 * @note    Do not include directly! Include hal_api.h instead with HAL_CMODEL defined.
 *
 *****************************************************************************/

#ifndef __HAL_CMODEL_H__
#define __HAL_CMODEL_H__
#include <ebase/trace.h>
#include <cmodel_wrapper/cmodel_wrapper.h>
#include <common/picture_buffer.h>


/******************************************************************************
 * local macro definitions
 *****************************************************************************/
#define NUM_I2C 3

/*****************************************************************************/
/**
 * @brief   different ways of how mapping of data from the memory into local memory is done
 *****************************************************************************/
typedef enum HalMapMemType_s
{
    HAL_MAPMEM_READWRITE = 0,   //!< Maps memory for read/write access.
    HAL_MAPMEM_READONLY,        //!< Maps memory for read access only, system action on write access is undefined
    HAL_MAPMEM_WRITEONLY        //!< Maps memory for write access only, system action on read access is undefined
} HalMapMemType_t;

/******************************************************************************
 * local type definitions
 *****************************************************************************/
typedef struct HalCamConfig_s
{
    bool_t configured;      //!< Mark whether this config was set.
    bool_t power_lowact;    //!< Power on is low-active.
    bool_t reset_lowact;    //!< Reset is low-active.
    //bool_t negedge;         //!< Capture data on negedge.
} HalCamConfig_t;

typedef struct HalCamPhyConfig_s
{
    bool_t configured;      //!< Mark whether this config was set.
    bool_t power_lowact;    //!< Power on is low-active.
    bool_t reset_lowact;    //!< Reset is low-active.
} HalCamPhyConfig_t;

typedef struct HalMemMap_s
{
    uint32_t        mem_address;    //!< Hardware memory address.
    uint32_t        byte_size;      //!< Size of mapped buffer.
    HalMapMemType_t mapping_type;   //!< How the buffer is mapped.
} HalMemMap_t;

#if 0
/******************************************************************************
 * HalCmodelBufType_t
 *****************************************************************************/
typedef enum HalCmodelBufType_e
{
    eHalCmodelBufTypeRAW8     = 0x0000,
    eHalCmodelBufTypeRAW16,
    eHalCmodelBufTypeYCbCr444,
    eHalCmodelBufTypeYCbCr422,
    eHalCmodelBufTypeYCbCr420,
    eHalCmodelBufTypeYCbCr400,
    eHalCmodelBufTypeJPEG,
    eHalCmodelBufTypeRGB565,
    eHalCmodelBufTypeRGB666,
    eHalCmodelBufTypeRGB888,
    eHalCmodelBufTypeMax,
}HalCmodelBufType_t;

/******************************************************************************
 * HalCmodelBufLayout_t
 *****************************************************************************/
typedef enum HalCmodelBufLayout_e
{
    eHalCmodelBufLayoutBayerRGRGGBGB     = 0x0000,
    eHalCmodelBufLayoutBayerGRGRBGBG,
    eHalCmodelBufLayoutBayerGBGBRGRG,
    eHalCmodelBufLayoutBayerBGBGGRGR,
    eHalCmodelBufLayoutPlanar,
    eHalCmodelBufLayoutSemiPlanar,
    eHalCmodelBufLayoutCombined,
    eHalCmodelBufLayoutMax,
}HalCmodelBufLayout_t;
#endif

#define HAL_CMODEL_BUF_TRANS_DMA   0x0001
#define HAL_CMODEL_BUF_TRANS_MP    0x0002
#define HAL_CMODEL_BUF_TRANS_SP    0x0004
#define HAL_CMODEL_BUF_TRANS_SP2_BP    0x0008
#define HAL_CMODEL_BUF_TRANS_PP    0x00010

#define HAL_CMODEL_BUF_TRANS_HDR_RET    0x00020
#define HAL_CMODEL_BUF_TRANS_MASK  0x0003F


/******************************************************************************
 * HalCmodelBufConfig_t
 *****************************************************************************/
typedef struct HalCmodelBufConfig_s{
    //DMA input buffer configurations
    PicBufType_t cmDmaBufType;
    PicBufLayout_t cmDmaBufLayout;
    uint32_t cmDmaBaseY;
    uint32_t cmDmaWidthY;
    uint32_t cmDmaHeightY;
    uint32_t cmDmaBaseCb;
    uint32_t cmDmaBaseCr;
    uint32_t cmDmaIntEnabled;
    //tobe expand later for y_burstlength, c_burstlength

    //Main Path buffer configurations
    PicBufType_t cmMpBufType;
    PicBufLayout_t cmMpBufLayout;
    uint32_t cmMpBaseY;
    uint32_t cmMpSizeY;
    uint32_t cmMpOffsY;
    uint32_t cmMpPicWidthPixelY;
    uint32_t cmMpPicHeightPixelY;

    uint32_t cmMpBaseCb;
    uint32_t cmMpSizeCb;
    uint32_t cmMpOffsCb;
    uint32_t cmMpPicWidthPixelCb;
    uint32_t cmMpPicHeightPixelCb;

    uint32_t cmMpBaseCr;
    uint32_t cmMpSizeCr;
    uint32_t cmMpOffsCr;
    uint32_t cmMpPicWidthPixelCr;
    uint32_t cmMpPicHeightPixelCr;
    uint32_t cmMpIntEnabled;

    //shd register
    uint32_t cmMpBaseYShd;
    uint32_t cmMpSizeYShd;
    uint32_t cmMpOffsYShd;
    uint32_t cmMpPicWidthPixelYShd;
    uint32_t cmMpPicHeightPixelYShd;

    uint32_t cmMpBaseCbShd;
    uint32_t cmMpSizeCbShd;
    uint32_t cmMpOffsCbShd;
    uint32_t cmMpPicWidthPixelCbShd;
    uint32_t cmMpPicHeightPixelCbShd;

    uint32_t cmMpBaseCrShd;
    uint32_t cmMpSizeCrShd;
    uint32_t cmMpOffsCrShd;
    uint32_t cmMpPicWidthPixelCrShd;
    uint32_t cmMpPicHeightPixelCrShd;

    //Self Path buffer configurations
    PicBufType_t cmSpBufType;
    PicBufLayout_t cmSpBufLayout;
    uint32_t cmSpBaseY;
    uint32_t cmSpSizeY;
    uint32_t cmSpOffsY;
    uint32_t cmSpPicWidthPixelY;
    uint32_t cmSpPicHeightPixelY;

    uint32_t cmSpBaseCb;
    uint32_t cmSpSizeCb;
    uint32_t cmSpOffsCb;
    uint32_t cmSpPicWidthPixelCb;
    uint32_t cmSpPicHeightPixelCb;

    uint32_t cmSpBaseCr;
    uint32_t cmSpSizeCr;
    uint32_t cmSpOffsCr;
    uint32_t cmSpPicWidthPixelCr;
    uint32_t cmSpPicHeightPixelCr;

    uint32_t cmSpRotEn;
    uint32_t cmSpVFlip;
    uint32_t cmSpHFlip;

    uint32_t cmSpIntEnabled;

    //Shd register
    uint32_t cmSpBaseYShd;
    uint32_t cmSpSizeYShd;
    uint32_t cmSpOffsYShd;
    uint32_t cmSpPicWidthPixelYShd;
    uint32_t cmSpPicHeightPixelYShd;

    uint32_t cmSpBaseCbShd;
    uint32_t cmSpSizeCbShd;
    uint32_t cmSpOffsCbShd;
    uint32_t cmSpPicWidthPixelCbShd;
    uint32_t cmSpPicHeightPixelCbShd;

    uint32_t cmSpBaseCrShd;
    uint32_t cmSpSizeCrShd;
    uint32_t cmSpOffsCrShd;
    uint32_t cmSpPicWidthPixelCrShd;
    uint32_t cmSpPicHeightPixelCrShd;


	//Self Path2 buffer configurations
    PicBufType_t cmSp2BufType;
    PicBufLayout_t cmSp2BufLayout;
    uint32_t cmSp2BaseY;
    uint32_t cmSp2SizeY;
    uint32_t cmSp2OffsY;
    uint32_t cmSp2PicWidthPixelY;
    uint32_t cmSp2PicHeightPixelY;

    uint32_t cmSp2BaseCb;
    uint32_t cmSp2SizeCb;
    uint32_t cmSp2OffsCb;
    uint32_t cmSp2PicWidthPixelCb;
    uint32_t cmSp2PicHeightPixelCb;

    uint32_t cmSp2BaseCr;
    uint32_t cmSp2SizeCr;
    uint32_t cmSp2OffsCr;
    uint32_t cmSp2PicWidthPixelCr;
    uint32_t cmSp2PicHeightPixelCr;

    uint32_t cmSp2RotEn;
    uint32_t cmSp2VFlip;
    uint32_t cmSp2HFlip;

    uint32_t cmSp2BpIntEnabled;

    //Shd register
    uint32_t cmSp2BaseYShd;
    uint32_t cmSp2SizeYShd;
    uint32_t cmSp2OffsYShd;
    uint32_t cmSp2PicWidthPixelYShd;
    uint32_t cmSp2PicHeightPixelYShd;

    uint32_t cmSp2BaseCbShd;
    uint32_t cmSp2SizeCbShd;
    uint32_t cmSp2OffsCbShd;
    uint32_t cmSp2PicWidthPixelCbShd;
    uint32_t cmSp2PicHeightPixelCbShd;

    uint32_t cmSp2BaseCrShd;
    uint32_t cmSp2SizeCrShd;
    uint32_t cmSp2OffsCrShd;
    uint32_t cmSp2PicWidthPixelCrShd;
    uint32_t cmSp2PicHeightPixelCrShd;

	//cameric post process buffer configurations
    PicBufType_t cmPpBufType;
    PicBufLayout_t cmPpBufLayout;
    uint32_t cmPpBaseY;
    uint32_t cmPpSizeY;
    uint32_t cmPpOffsY;
    uint32_t cmPpPicWidthPixelY;
    uint32_t cmPpPicHeightPixelY;

    uint32_t cmPpBaseCb;
    uint32_t cmPpSizeCb;
    uint32_t cmPpOffsCb;
    uint32_t cmPpPicWidthPixelCb;
    uint32_t cmPpPicHeightPixelCb;

    uint32_t cmPpBaseCr;
    uint32_t cmPpSizeCr;
    uint32_t cmPpOffsCr;
    uint32_t cmPpPicWidthPixelCr;
    uint32_t cmPpPicHeightPixelCr;

    uint32_t cmPpRotEn;
    uint32_t cmPpVFlip;
    uint32_t cmPpHFlip;

    uint32_t cmPpIntEnabled;

    //Shd register
    uint32_t cmPpBaseYShd;
    uint32_t cmPpSizeYShd;
    uint32_t cmPpOffsYShd;
    uint32_t cmPpPicWidthPixelYShd;
    uint32_t cmPpPicHeightPixelYShd;

    uint32_t cmPpBaseCbShd;
    uint32_t cmPpSizeCbShd;
    uint32_t cmPpOffsCbShd;
    uint32_t cmPpPicWidthPixelCbShd;
    uint32_t cmPpPicHeightPixelCbShd;

    uint32_t cmPpBaseCrShd;
    uint32_t cmPpSizeCrShd;
    uint32_t cmPpOffsCrShd;
    uint32_t cmPpPicWidthPixelCrShd;
    uint32_t cmPpPicHeightPixelCrShd;

#ifdef ISP_MI_BP
//bayper Pattern buffer configurations
    PicBufType_t cmBpBufType;
    PicBufLayout_t cmBpBufLayout;
    uint32_t cmBpBaseR;
    uint32_t cmBpSizeR;
    uint32_t cmBpOffsR;

    uint32_t cmBpBaseGr;
    uint32_t cmBpSizeGr;
    uint32_t cmBpOffsGr;

    uint32_t cmBpBaseGb;
    uint32_t cmBpSizeGb;
    uint32_t cmBpOffsGb;


    uint32_t cmBpBaseB;
    uint32_t cmBpSizeB;
    uint32_t cmBpOffsB;

    uint32_t cmBpPicWrOffsCntInit;
    uint32_t cmBpPicWrIrqOffsInit;
    uint32_t cmBpPicWrSizeInit;

    uint32_t cmBpPicWrLlength;
    uint32_t cmBpPicWrWidth;
    uint32_t cmBpPicWrHeight;
    uint32_t cmBpPicSize;
    uint32_t cmBpIntEnabled;
//Shd register
    uint32_t cmBpBaseRShd;
    uint32_t cmBpSizeRShd;
    uint32_t cmBpOffsRShd;

    uint32_t cmBpBaseGrShd;
    uint32_t cmBpSizeGrShd;
    uint32_t cmBpOffsGrShd;

    uint32_t cmBpBaseGbShd;
    uint32_t cmBpSizeGbShd;
    uint32_t cmBpOffsGbShd;

    uint32_t cmBpBaseBShd;
    uint32_t cmBpSizeBShd;
    uint32_t cmBpOffsBShd;

#endif

    int frame_cnt;

#ifdef ISP_MI_HANDSHAKE_NANO
    uint32_t cmMiMpHandshkSwitch;
    uint32_t cmMiMpHandshkStrFmt;
    uint32_t cmMiMpHandshkDataFmt;

    uint32_t cmMiMpHandshkLinePerSliceMinus1;
    uint32_t cmMiMpHandshkSlicePerBufferMinus1;
    uint32_t cmMiMpHandshkAckCount;

    uint32_t cmMiMpHandshkYbaseAdInit;
    uint32_t cmMiMpHandshkCbbaseAdInit;
    uint32_t cmMiMpHandshkCrbaseAdInit;

    uint32_t cmMiMpHandshkYLlengthPixel;
    uint32_t cmMiMpHandshkYSliceOffsetBytes;
    uint32_t cmMiMpHandshkCSliceOffsetBytes;

    uint32_t cmMiMpHandshkYPicWidthPixel;
    uint32_t cmMiMpHandshkYPicHeightPixel;
    uint32_t cmMiMpHandshkYPicSizePixel;    //auto calculation, no need to fill

    uint32_t cmMpYBufSize;          //Y buffer size
    uint32_t cmMpCBufSize;          //Cb buffer size
#endif
}HalCmodelBufConfig_t;


typedef enum HalInterruptType_e{
    eHAL_INT_MI_DMA_READY    =0x0000,
    eHAL_INT_MI_FRAME_END_MP,
    eHAL_INT_MI_FRAME_END_SP,
	eHAL_INT_MI_FRAME_END_SP2_BP,
    eHAL_INT_MI_RAW_FRAME_END_SP2_BP,
    eHAL_INT_MI2_FRAME_END_PPW,
    eHAL_INT_ISP_OFF,
    eHal_INT_ISP_HistM,
    eHal_INT_ISP_ExpM,
    eHal_INT_ISP_WbM,
    eHal_INT_ISP_AfmM,
    eHal_INT_ISP_VsmM,

    eHAL_INTMax,
}HalInterruptType_t;

typedef enum HalModule_s
{
    HAL_MODULE_VIDEO   = 0x01,//!<video in V4L2
    HAL_MODULE_ISP     = 0x02,//!<ISP
    HAL_MODULE_VIN     = 0x04,//!<VIN:mipi-csi2 dvp bt656 bt601
    HAL_MODULE_SENSOR  = 0x08,//!<Sensor
    HAL_MODULE_SOC     = 0x10,//!<SoC
}HalModule_e;

typedef struct __HalBuffPoolCtx__
{
    BufIdentity bufPoolMp[BUFF_POOL_MAX_OUTPUT_BUF_NUMBER];
    BufIdentity bufPoolSP1[BUFF_POOL_MAX_OUTPUT_BUF_NUMBER];
    BufIdentity bufPoolSP2[BUFF_POOL_MAX_OUTPUT_BUF_NUMBER];
    BufIdentity bufPoolRdi[BUFF_POOL_MAX_OUTPUT_BUF_NUMBER];
    BufIdentity bufPoolMeta[BUFF_POOL_MAX_OUTPUT_BUF_NUMBER];
    BufIdentity bufPoolRead[BUFF_POOL_MAX_INPUT_BUF_NUMBER];
    uint32_t    bufPoolMpNum;
    uint32_t    bufPoolSP1Num;
    uint32_t    bufPoolSP2Num;
    uint32_t    bufPoolRdiNum;
    uint32_t    bufPoolMetaNum;
    uint32_t    bufPoolReadNum;
}HalBuffPoolCtx;

/******************************************************************************
 * HalContext_t
 *****************************************************************************/
typedef struct HalContext_s
{
    osMutex               modMutex;               //!< common short term mutex; e.g. for read-modify-write accesses
    uint32_t              refCount;               //!< internal ref count

    osMutex               iicMutex[NUM_I2C];      //!< transaction locks for I2C controller 1..NUM_I2C

    HalCamConfig_t        cam1Config;             //!< configuration for CAM1; set at runtime
    HalCamPhyConfig_t     camPhy1Config;          //!< configuration for CAMPHY1; set at runtime
    HalCmodelBufConfig_t  halCmodelbufCfg;        //!< configuration for HalCmodel buffer configurations
    osDpcFunc             halIsrFunTable[eHalIsrMax];  //!< hal Cmodel Isr source and function table

    char*                 regDynDumpName;         //!< register dump name.
    FILE*                 regDynDumpFp;           //!< dynamic dump handle

    HalBuffPoolCtx      halBufPool;
    BUFF_MODE           buf_work_mode;
    uint32_t            isp_index;
    uint32_t            sensor_index;
    int32_t             isp_fd;
    int32_t             csi_fd;
    int32_t             sensor_fd;
    int32_t             soc_fd;

} HalContext_t;

/*****************************************************************************/
/**
 * @brief   handle to hal instance
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

USE_TRACER(HAL_ERROR);

/******************************************************************************
 * HAL device IDs
 *****************************************************************************/
#define HAL_DEVID_OCP       0x00000001  //!< HAL internal use only
#define HAL_DEVID_MARVIN    0x00000002  //!< MARVIN.*
#define HAL_DEVID_VDU       0x00000004  //!< VDU.clk + VDU.ocpclk
#define HAL_DEVID_PCLK      0x00000008  //!< VDU.pclk
#define HAL_DEVID_I2C_0     0x00000010  //!< HAL internal use only
#define HAL_DEVID_I2C_1     0x00000020  //!< HAL internal use only
#define HAL_DEVID_I2C_2     0x00000040  //!< HAL internal use only
#define HAL_DEVID_CAMREC_1  0x00000080  //!< CAMREC1, not neccessarily the REC that CAM1 is hooked up to; see @ref HAL_DEVID_CAM_1_REC instead
#define HAL_DEVID_INTERNAL  0x000000ff  //!< just internal devices included

#define HAL_DEVID_CAM_1     0x10000000  //!< CAM1
#define HAL_DEVID_CAMPHY_1  0x20000000  //!< CAMPHY1, not neccessarily the PHY that CAM1 is hooked up to; see @ref HAL_DEVID_CAM_1_PHY instead
#define HAL_DEVID_EXTERNAL  0x30000000  //!< just external devices included

#define HAL_DEVID_ALL       (HAL_DEVID_INTERNAL | HAL_DEVID_EXTERNAL) //!< all devices included


/******************************************************************************
 * HAL device base addresses
 *****************************************************************************/
// HalRegs:
#define HAL_BASEADDR_MARVIN    0x00000000 //!< Base address of MARVIN module.
#define HAL_BASEADDR_MARVIN_2  0x00010000 //!< Base address of MARVIN module of 2nd channel.
#define HAL_BASEADDR_MIPI_1    0x00000000 //!< Base address of MIPI module.
#define HAL_BASEADDR_MIPI_2    0x00010000 //!< Base address of MIPI module of 2nd channel.
#define HAL_BASEADDR_VDU       0x00008000 //!< Base address of VDU module.

// HalSysRegs:
#define HAL_BASEADDR_SYSCTRL   0x00000000 //!< HAL internal use only
#define HAL_BASEADDR_I2C_0     0x00001000 //!< HAL internal use only
#define HAL_BASEADDR_I2C_1     0x00001800 //!< HAL internal use only
#define HAL_BASEADDR_I2C_2     0x00000800 //!< HAL internal use only


/******************************************************************************
 * HAL device base region
 *****************************************************************************/
// HalRegs:
#define HAL_BASEREGION_MARVIN    0 //!< Base region of MARVIN module(s).
#define HAL_BASEREGION_MIPI      0 //!< Base region of MIPI module(s).
#define HAL_BASEREGION_VDU       0 //!< Base region of VDU module.

// HalSysRegs:
#define HAL_BASEREGION_SYSCTRL   2 //!< HAL internal use only
#define HAL_BASEREGION_I2C       2 //!< HAL internal use only


/******************************************************************************
 * HAL I2C bus location
 *****************************************************************************/
#define HAL_I2C_BUS_CAM_1       0 //!< Num of I2C bus CAM1 is connected to
#define HAL_I2C_BUS_CAM_2       1 //!< Num of I2C bus CAM2 is connected to
#define HAL_I2C_BUS_HDMI_TX     2 //!< Num of I2C bus HDMI TX is connected to
#define HAL_I2C_BUS_CAMPHY_1    0 //!< Num of I2C bus CAMPHY1 is connected to
#define HAL_I2C_BUS_CAMPHY_2    1 //!< Num of I2C bus CAMPHY1 is connected to


/******************************************************************************
 * HAL CAM to PHY/REC mapping
 *****************************************************************************/
#define HAL_DEVID_CAM_1_PHY     HAL_DEVID_CAMPHY_1 //!< DEVID of CAMPHY CAM1 is connected to
#define HAL_DEVID_CAM_2_PHY     HAL_DEVID_CAMPHY_1 //!< DEVID of CAMPHY CAM2 is connected to
#define HAL_DEVID_CAM_1_REC     HAL_DEVID_CAMREC_1 //!< DEVID of CAMREC CAM1 is connected to
#define HAL_DEVID_CAM_2_REC     HAL_DEVID_CAMREC_1 //!< DEVID of CAMREC CAM2 is connected to


/******************************************************************************
 * @brief   writes a value to specific part of the given variable
 * @return  new value of variable
 *
 * @note    It is required to pass a variable (not a register!)
 *          and the masks (reg_mask and shift_mask) by using constant defines.
 *          This function is used internally by HalWriteMaskedReg() but can also
 *          be used directly to write values into a (temporary) variable.
 *****************************************************************************/
INLINE uint32_t HalSetMaskedValue( uint32_t reg_value, uint32_t reg_mask, uint32_t shift_mask, uint32_t value )
{
    return (reg_value & ~(reg_mask)) | ((value << shift_mask) & reg_mask);
}

/******************************************************************************
 * @brief   reads a value from a specific part of the given variable
 * @return  masked and shifted data of specific variable part
 *
 * @note    It is required to pass a variable (not a register!)
 *          and the masks (reg_mask and shift_mask) by using constant defines.
 *          This function is used internally by HalReadMaskedReg() but can also
 *          be used directly to read values from a (temporary) variable.
 *****************************************************************************/
INLINE uint32_t HalGetMaskedValue( uint32_t reg_value, uint32_t reg_mask, uint32_t shift_mask )
{
    return ((reg_value & reg_mask) >> shift_mask);
}

/******************************************************************************
 * HalReadReg()
 *****************************************************************************/
INLINE uint32_t HalReadReg( HalHandle_t HalHandle, uint32_t reg_address )
{
    unsigned int data;
    struct HalContext_s * HalHandleCtx = (struct HalContext_s *)HalHandle;

    DCT_ASSERT(HalHandle != NULL);

    readRegister(reg_address, &data);

    if (HalHandleCtx->regDynDumpFp)
    {
        fprintf(HalHandleCtx->regDynDumpFp, "1 %08x %08x\n", (unsigned int)reg_address, (unsigned int)data);
    }

    return data;
}

/******************************************************************************
 * HalWriteReg()
 *****************************************************************************/
INLINE void HalWriteReg( HalHandle_t HalHandle, uint32_t reg_address, uint32_t value )
{
    struct HalContext_s * HalHandleCtx = (struct HalContext_s *)HalHandle;
    DCT_ASSERT(HalHandle != NULL);

    if (HalHandleCtx->regDynDumpFp)
    {
        fprintf(HalHandleCtx->regDynDumpFp, "0 %08x %08x\n", (unsigned int)reg_address, (unsigned int)value);
    }

    writeRegister(reg_address, value);

}

/******************************************************************************
 * HalReadMaskedReg()
 *****************************************************************************/
INLINE uint32_t HalReadMaskedReg( HalHandle_t HalHandle, uint32_t reg_address, uint32_t reg_mask, uint32_t shift_mask )
{
    DCT_ASSERT(HalHandle != NULL);

    uint32_t tmp_value = HalReadReg( HalHandle, reg_address );
    return HalGetMaskedValue( tmp_value, reg_mask, shift_mask );
}

/******************************************************************************
 * HalWriteMaskedReg()
 *****************************************************************************/
INLINE void HalWriteMaskedReg( HalHandle_t HalHandle, uint32_t reg_address, uint32_t reg_mask, uint32_t shift_mask, uint32_t value )
{
    DCT_ASSERT(HalHandle != NULL);

    uint32_t tmp_value = HalReadReg( HalHandle, reg_address );
    tmp_value = HalSetMaskedValue( tmp_value, reg_mask, shift_mask, value );
    HalWriteReg( HalHandle, reg_address, tmp_value );
}

/******************************************************************************
 * HalReadSysReg()
 *****************************************************************************/
INLINE uint32_t HalReadSysReg( HalHandle_t HalHandle, uint32_t reg_address )
{
    return HalReadReg(HalHandle, reg_address);
}

/******************************************************************************
 * HalWriteSysReg()
 *****************************************************************************/
INLINE void HalWriteSysReg( HalHandle_t HalHandle, uint32_t reg_address, uint32_t value )
{
    HalWriteReg(HalHandle, reg_address, value);
}

/******************************************************************************
 * HalWriteSysReg()
 *****************************************************************************/
RESULT HalDynRegDumpOpen( HalHandle_t HalHandle, char* regDynDumpName );

/******************************************************************************
 * HalDynRegDumpClose()
 *****************************************************************************/
RESULT HalDynRegDumpClose( HalHandle_t HalHandle );

INLINE RESULT HalKernelAddrMap(HalHandle_t HalHandle , BufIdentity * bufIdentify) {
	return 0;
}

INLINE BufIdentity* HalGetPoolList(HalHandle_t HalHandle, ISPCORE_BUFIO_ID chain) {
	return NULL;
}

INLINE uint32_t* HalGetPoolNumHandle(HalHandle_t HalHandle, ISPCORE_BUFIO_ID chain) {
	return NULL;
}

INLINE RESULT HalSetBuffMode(HalHandle_t HalHandle, BUFF_MODE buf_work_mode) {
	return 0;
}

INLINE BUFF_MODE HalGetBuffMode(HalHandle_t HalHandle) {
	return BUFF_MODE_PHYLINEAR;
}

int32_t HalGetFdHandle(HalHandle_t HalHandle, HalModule_e module);
RESULT HalGetSensorName(HalHandle_t HalHandle, char pSensorName[], uint16_t arraySize);
RESULT HalGetSensorDrvName(HalHandle_t HalHandle, char pSensorDrvName[], uint16_t arraySize);
RESULT HalGetSensorCalibXmlName(HalHandle_t HalHandle, char pSensorCalibXmlName[], uint16_t arraySize);
RESULT HalGetSensorDefaultMode(HalHandle_t HalHandle, uint32_t *pMode);
RESULT HalGetSensorCurrMode(HalHandle_t HalHandle, uint32_t *pMode);
RESULT HalSetSensorMode(HalHandle_t HalHandle, uint32_t mode);
RESULT HalSetSensorCalibXmlName(HalHandle_t HalHandle, const char* CalibXmlName);
RESULT HaSensorModeLock(HalHandle_t HalHandle);

#ifdef __cplusplus
}
#endif

#endif /* __HAL_CMODEL_H__ */
