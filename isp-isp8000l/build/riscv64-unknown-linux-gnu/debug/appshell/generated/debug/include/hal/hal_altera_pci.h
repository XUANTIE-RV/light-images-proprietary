/******************************************************************************\
|* Copyright 2010, Dream Chip Technologies GmbH. used with permission by      *|
|* VeriSilicon.                                                               *|
|* Copyright (c) <2020> by VeriSilicon Holdings Co., Ltd. ("VeriSilicon")     *|
|* All Rights Reserved.                                                       *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of VeriSilicon.  This is proprietary information owned or licensed by      *|
|* VeriSilicon.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of VeriSilicon.                                         *|
|*                                                                            *|
\******************************************************************************/

/* VeriSilicon 2020 */

/**
 * @file hal_altera_pci.h
 *
 * @brief   Altera PCI variant of Hardware Abstraction Layer
 *
 *          This header file exports the register IO interface realized as an Altera
 *          PCI-Express board access inline function. You should use it for your
 *          PC implementation in combination with the Altera FPGA board.
 * @note    Do not include directly! Include hal_api.h instead with HAL_ALTERA defined.
 *
 *****************************************************************************/

#ifndef __HAL_ALTERA_PCI_H__
#define __HAL_ALTERA_PCI_H__

#include <ebase/trace.h>
#include <fpga/altera_fpga.h>
#include <i2c_drv/i2c_drv.h>

#include <cam_device/cam_device_buf_defs.h>

#include "adapt.h"
//#include "hal_altera_irq_notifier.h"
/* Set this macro to 1 enable register dump. */
#define ENABLE_REGISTER_DUMP 0

/******************************************************************************
 * local macro definitions
 *****************************************************************************/
#define NUM_I2C 3

#define SYSCTRL_REVID_OFFS  0x00
#define SYSCTRL_SELECT_OFFS 0x10
#define SYSCTRL_RESET_OFFS  0x20

#define SYSCTRL_SELECT_CAM_1_NEGEDGE 0x00000100
#define SYSCTRL_SELECT_CAM_1_RESET   0x00000200
#define SYSCTRL_SELECT_CAM_1_POWERDN 0x00000400

#define SYSCTRL_SELECT_CAMPHY_1_RESET   0x00001000
#define SYSCTRL_SELECT_CAMPHY_1_POWERDN 0x00000000  //NOTE: not connected so far

#define EXT_MEM_ALIGN 0x1000 // 4k

#define DMA_STRIDE_BYTES 8 ////FPGA_DMA_SIZE_ALIGNMENT // currently 32
#define DMA_MEM_ALIGN    512

#define HAL_USE_RAW_DMA // comment out to use dma functions with byte reordering & stuff


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
typedef enum HalModule_s
{
    HAL_MODULE_VIDEO   = 0x01,//!<video in V4L2
    HAL_MODULE_ISP     = 0x02,//!<ISP
    HAL_MODULE_VIN     = 0x04,//!<VIN:mipi-csi2 dvp bt656 bt601
    HAL_MODULE_SENSOR  = 0x08,//!<Sensor
    HAL_MODULE_SOC     = 0x10,//!<SoC
}HalModule_e;

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
    void            *p_bufbase;     //!< Base of allocated buffer.
} HalMemMap_t;

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
    osMutex             modMutex;               //!< common short term mutex; e.g. for read-modify-write accesses
    uint32_t            refCount;               //!< internal ref count

    osMutex             iicMutex[NUM_I2C];      //!< transaction locks for I2C controller 1..NUM_I2C
    i2c_bus_t           iicConfig[NUM_I2C];     //!< configurations for I2C controller 1..NUM_I2C

    HalCamConfig_t      cam1Config;             //!< configuration for CAM1; set at runtime
    HalCamPhyConfig_t   camPhy1Config;          //!< configuration for CAMPHY1; set at runtime
    osDpcFunc           halIsrFunTable[eHalIsrMax];  //!< hal Isr source and function table

#if ENABLE_REGISTER_DUMP
    FILE*               regDumpFile;
#endif
    char*               regDynDumpName;         //!< register dump name.
    FILE*               regDynDumpFp;           //!< dynamic dump handle

    HalBuffPoolCtx      halBufPool;
    BUFF_MODE           buf_work_mode;
    uint32_t            isp_index;
    uint32_t            sensor_index;
    int32_t             isp_fd;
    int32_t             csi_fd;
    int32_t             sensor_fd;
    int32_t             soc_fd;
    int32_t             dec_fd;

    AdaptHandle_t       adaptHandle;
    void               *pIrqNotifier;

    bool_t              board_using;
    volatile int        irq_cancel_all;
    uint8_t*            extern_mem_virtual_base;
    unsigned long       reservedMemBase;
    unsigned long       reservedMemSize;

} HalContext_t;


/*****************************************************************************/
/**
 * @brief   handle to hal instance
 *****************************************************************************/
//typedef struct HalContext_s *HalHandle_t;
typedef void * HalHandle_t;

/******************************************************************************
 * common internal stuff; may be used externally as well
 *****************************************************************************/

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

#ifdef __cplusplus
extern "C"
{
#endif

USE_TRACER(HAL_ERROR);


RESULT HalKernelAddrMap(HalHandle_t HalHandle , BufIdentity * bufIdentify);
BufIdentity* HalGetPoolList(HalHandle_t HalHandle, ISPCORE_BUFIO_ID chain);
uint32_t* HalGetPoolNumHandle(HalHandle_t HalHandle, ISPCORE_BUFIO_ID chain);

int32_t HalGetFdHandle(HalHandle_t HalHandle, HalModule_e module);
RESULT HalIoctl(HalHandle_t HalHandle, HalModule_e module, unsigned int cmd, void *args);
RESULT HalGetSensorName(HalHandle_t HalHandle, char pSensorName[], uint16_t arraySize);
RESULT HalGetSensorDrvName(HalHandle_t HalHandle, char pSensorDrvName[], uint16_t arraySize);
RESULT HalGetSensorCalibXmlName(HalHandle_t HalHandle, char pSensorCalibXmlName[], uint16_t arraySize);
RESULT HalGetSensorDefaultMode(HalHandle_t HalHandle, uint32_t *pMode);
RESULT HalGetSensorCurrMode(HalHandle_t HalHandle, uint32_t *pMode);
RESULT HalSetSensorMode(HalHandle_t HalHandle, uint32_t mode);
RESULT HalSetSensorDefaultMode(HalHandle_t HalHandle, uint32_t mode);
RESULT HalSetSensorCalibXmlName(HalHandle_t HalHandle, const char* CalibXmlName);
RESULT HaSensorModeLock(HalHandle_t HalHandle);

int32_t HalSetSensorRegister(HalHandle_t HalHandle,uint32_t addr, uint32_t value);
int32_t HalGetSensorRegister(HalHandle_t HalHandle,uint32_t addr, uint32_t *value);
int32_t HalSetIspRegister(HalHandle_t HalHandle,uint32_t addr, uint32_t value);
int32_t HalGetIspRegister(HalHandle_t HalHandle,uint32_t addr, uint32_t *value);

int32_t HalSystemInit(uint32_t id,HalHandle_t HalHandle);
int32_t HalCsiInit(HalHandle_t HalHandle);
int32_t HalSensorInit(HalHandle_t HalHandle, const char *registerFileName);
int32_t HalIspInit(HalHandle_t HalHandle, const char *registerFileName);
int32_t HalDecInit(HalHandle_t HalHandle);


RESULT HalSetBuffMode(HalHandle_t HalHandle, BUFF_MODE buf_work_mode);
BUFF_MODE HalGetBuffMode(HalHandle_t HalHandle);

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

#define HAL_DEVID_HIGHACTIVE_RESET_DEVICES 0x00000000 //!< HAL internal use only; bitwise or of all device masks of devices with high active resets.
#define HAL_DEVID_HIGHACTIVE_POWER_DEVICES 0x00000000 //!< HAL internal use only; bitwise or of all device masks of devices with high active power on select.
#define HAL_DEVID_RISING_CLKEDGE_DEVICES   0x00000000 //!< HAL internal use only; bitwise or of all device masks of devices with rising edge active clocks.

/******************************************************************************
 * HAL device base addresses
 *****************************************************************************/
// HalRegs:
#define HAL_BASEADDR_MARVIN    0x00000000 //!< Base address of MARVIN module.
#define HAL_BASEADDR_MARVIN_2  0x00010000 //!< Base address of MARVIN module of 2nd channel.
#define HAL_BASEADDR_MIPI_1    0x00000000 //!< Base address of MIPI module.
#define HAL_BASEADDR_MIPI_2    0x00010000 //!< Base address of MIPI module of 2nd channel.
#define HAL_BASEADDR_VDU       0x00008000 //!< Base address of VDU module.
#define HAL_BASEADDR_MARVIN_DEC 0x00600000 //!< Base address of DEC module.

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
#define HAL_I2C_BUS_CAMPHY_2    1 //!< Num of I2C bus CAMPHY2 is connected to


/******************************************************************************
 * HAL CAM to PHY/REC mapping
 *****************************************************************************/
#define HAL_DEVID_CAM_1_PHY     HAL_DEVID_CAMPHY_1 //!< DEVID of CAMPHY CAM1 is connected to
#define HAL_DEVID_CAM_2_PHY     HAL_DEVID_CAMPHY_1 //!< DEVID of CAMPHY CAM2 is connected to
#define HAL_DEVID_CAM_1_REC     HAL_DEVID_CAMREC_1 //!< DEVID of CAMREC CAM1 is connected to
#define HAL_DEVID_CAM_2_REC     HAL_DEVID_CAMREC_1 //!< DEVID of CAMREC CAM2 is connected to


/******************************************************************************
 * HalReadReg()
 *****************************************************************************/
INLINE uint32_t HalReadReg( HalHandle_t HalHandle, uint32_t reg_address )
{
    uint32_t read;
    (void) HalHandle;
    struct HalContext_s * HalHandleCtx = (struct HalContext_s *)HalHandle;
    DCT_ASSERT(HalHandleCtx != NULL);

    read = AlteraFPGABoard_ReadReg(HalHandleCtx->isp_fd, reg_address);

#if ENABLE_REGISTER_DUMP
    if (HalHandleCtx->regDumpFile)
    {
        fprintf(HalHandleCtx->regDumpFile, "1 %08x %08x\n", reg_address, read);
    }
#endif

    if (HalHandleCtx->regDynDumpFp)
    {
        fprintf(HalHandleCtx->regDynDumpFp, "1 %08x %08x\n", (unsigned int)reg_address, (unsigned int)read);
    }

    //printf("HAL_READ: %08x %08x\n", reg_address, read);
    return read;
}


/******************************************************************************
 * HalWriteReg()
 *****************************************************************************/
INLINE void HalWriteReg( HalHandle_t HalHandle, uint32_t reg_address, uint32_t value )
{
    (void) HalHandle;
    DCT_ASSERT(HalHandle != NULL);
    struct HalContext_s * HalHandleCtx = (struct HalContext_s *)HalHandle;

#if ENABLE_REGISTER_DUMP
    if (HalHandleCtx->regDumpFile)
    {
        fprintf(HalHandleCtx->regDumpFile, "0 %08x %08x\n", reg_address, value);
    }
#endif
    if (HalHandleCtx->regDynDumpFp)
    {
        fprintf(HalHandleCtx->regDynDumpFp, "0 %08x %08x\n", (unsigned int)reg_address, (unsigned int)value);
    }

    //printf("HAL_WRITE: %08x %08x\n", reg_address, value);
    (void) AlteraFPGABoard_WriteReg(HalHandleCtx->isp_fd, reg_address, value );
}


/******************************************************************************
 * HalReadMaskedReg()
 *****************************************************************************/
INLINE uint32_t HalReadMaskedReg( HalHandle_t HalHandle, uint32_t reg_address, uint32_t reg_mask, uint32_t shift_mask )
{
    (void) HalHandle;
    DCT_ASSERT(HalHandle != NULL);

    uint32_t tmp_value = HalReadReg( HalHandle, reg_address );
    return HalGetMaskedValue( tmp_value, reg_mask, shift_mask );
}


/******************************************************************************
 * HalWriteMaskedReg()
 *****************************************************************************/
INLINE void HalWriteMaskedReg( HalHandle_t HalHandle, uint32_t reg_address, uint32_t reg_mask, uint32_t shift_mask, uint32_t value )
{
    (void) HalHandle;
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
    (void) HalHandle;
   // DCT_ASSERT(HalHandle != NULL);
    HalContext_t *pHalCtx = (HalContext_t *)HalHandle;

    return AlteraFPGABoard_ReadBAR( pHalCtx->isp_fd, FPGA_REG_ADDRESS_MOD(reg_address) );
}


/******************************************************************************
 * HalWriteSysReg()
 *****************************************************************************/
INLINE void HalWriteSysReg( HalHandle_t HalHandle, uint32_t reg_address, uint32_t value )
{
    (void) HalHandle;
    //DCT_ASSERT(HalHandle != NULL);
    HalContext_t *pHalCtx = (HalContext_t *)HalHandle;

    (void) AlteraFPGABoard_WriteBAR( pHalCtx->isp_fd, FPGA_REG_ADDRESS_MOD(reg_address), value );
}

/******************************************************************************
 * HalWriteSysReg()
 *****************************************************************************/
RESULT HalDynRegDumpOpen( HalHandle_t HalHandle, char* regDynDumpName );

/******************************************************************************
 * HalDynRegDumpClose()
 *****************************************************************************/
RESULT HalDynRegDumpClose( HalHandle_t HalHandle );


#ifdef __cplusplus
}
#endif

#endif /* __HAL_ALTERA_PCI_H__ */
