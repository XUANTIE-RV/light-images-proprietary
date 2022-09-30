/******************************************************************************\
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
 * @file hal_common.h
 *
 * @brief
 *
 *
 * @note
 *
 *****************************************************************************/

#ifndef __HAL_COMMON_H__
#define __HAL_COMMON_H__

#include <ebase/trace_ry.h>
#include <ebase/dct_assert_ry.h>
#include <oslayer/oslayer_ry.h>


/** Interrupt handling mode switch.
  * If set to zero (0), the interrupt facilities built into the kernel driver
  * will not be used. Instead, the user-space application will poll for
  * interrupts by reading the masked interrupt status register repeatedly.
  * If set to one (1), the kernel driver will handle the interrupt requests by
  * the hardware. This is much more efficient, but requires the IRQ logic in the
  * hardware to work correctly. */
#define FPGA_USE_KERNEL_IRQ_HANDLING 0

/******************************************************************************
 * local macro definitions
 *****************************************************************************/
typedef enum HalIsrSrc_e
{
    eHalIsrSrcIspIrq         = 0x0000,
    eHalIsrSrcJpeStatusIrq,
    eHalIsrSrcJpeErrorIrq,
    eHalIsrSrcCamIcMiIrq,
    eHalIsrSrcCamIcMi1Irq,
    eHalIsrSrcCamIcMi2Irq,
    eHalIsrSrcCamIcMipiIrq,
    eHalIsrSrcCamIcIspStitchingIrq,
    eHalIsrMax,
} HalIsrSrc_t;


typedef enum HalChId_s
{
    HAL_CH_ID0 = 0, //!<isp channel id 0.
    HAL_CH_ID1 = 1, //!<isp channel id 1.
    HAL_CH_NUM      //!<isp channel numbers.
}HalChId_e;



/******************************************************************************
 * local type definitions
 *****************************************************************************/
 #if defined ( HAL_ALTERA ) || defined ( HAL_LIGHT_FPGA )

/* IRQ handle type. */
typedef struct _fpga_irq_handle {
#if FPGA_USE_KERNEL_IRQ_HANDLING
        int __dummy;
#else
        uint32_t mis_addr;
        uint32_t cis_addr;
        uint32_t timeout;
        volatile int cancel;
        osMutex poll_mutex;
#endif
} fpga_irq_handle_t;


#endif

/*****************************************************************************/
/**
 * @brief   handle to hal instance
 *****************************************************************************/
typedef void * HalHandle_t;

/*****************************************************************************/
/**
 * @brief   hal irq context
 *****************************************************************************/
struct HalIrqCtx_s                                  // note: a forward declaration was given in this file before!
{
    HalHandle_t         HalHandle;                  /**< hal handle this context belongs to; must be set by callee prior connection of irq! */
    uint32_t            misRegAddress;              /**< address of the masked interrupt status register (MIS); must be set by callee prior connection of irq! */
    uint32_t            icrRegAddress;              /**< address of the interrupt clear register (ICR); must be set by callee prior connection of irq! */

    osInterrupt         OsIrq;                      /**< os layer abstraction for the interrupt */
    uint32_t            misValue;                   /**< value of the MIS-Register */

#if defined ( HAL_ALTERA )
    fpga_irq_handle_t   AlteraIrqHandle;            /**< handle for multiple interrupt handler */
#elif defined ( HAL_LIGHT_FPGA )
    fpga_irq_handle_t   IrqHandle;                  /**< handle for multiple interrupt handler */
#endif

    HalIsrSrc_t   irq_src;
};

/*****************************************************************************/
/**
 * @brief   hal irq context
 *****************************************************************************/
typedef struct HalIrqCtx_s HalIrqCtx_t; // implicit forward declaration of struct HalIrqCtx_s

#if defined ( HAL_ALTERA )
#define FPGA_ReadReg AlteraFPGABoard_ReadReg
#define FPGA_WriteReg AlteraFPGABoard_WriteReg
#elif defined ( HAL_LIGHT_FPGA )
#define FPGA_ReadReg LightFPGA_ReadReg
#define FPGA_WriteReg LightFPGA_WriteReg
#endif

#endif /* __HAL_COMMON_H__ */
