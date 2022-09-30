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
 * @note    Do not include directly! Include hal_api_ry.h instead with HAL_ALTERA defined.
 *
 *****************************************************************************/

#ifndef __HAL_ALTERA_IRQ_NOTIFIER_H__
#define __HAL_ALTERA_IRQ_NOTIFIER_H__

#include <stdio.h>
#include <ebase/trace_ry.h>
#include <common/align_ry.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include "hal_api_ry.h"  // this includes 'hal_altera_pci.h' as well

//#include "hal_altera_pci_mem_ry.h"
/******************************************************************************
 * local type definitions
 *****************************************************************************/


typedef enum HalIrqNotifierCmdId_e
{
    HAL_IRQ_NORIFIER_CMD_INVALID                   = 0,    /**< invalid command (only for initialization) */
    HAL_IRQ_NORIFIER_CMD_REGISTER_ISP_IRQ          = 1,    /**< register isp irq command */
    HAL_IRQ_NORIFIER_CMD_REGISTER_JPE_STATUS_IRQ   = 2,    /**< register jpe status irq command  */
    HAL_IRQ_NORIFIER_CMD_REGISTER_JPE_ERROR_IRQ    = 3,    /**< register jpe error  irq command  */
    HAL_IRQ_NORIFIER_CMD_REGISTER_MI_IRQ      = 4,    /**< register mi irq command  */
    HAL_IRQ_NORIFIER_CMD_REGISTER_MI2_IRQ           = 5,    /**< register mi2 irq command  */

    HAL_IRQ_NORIFIER_CMD_UNREGISTER_ISP_IRQ          ,
    HAL_IRQ_NORIFIER_CMD_UNREGISTER_JPE_STATUS_IRQ,
    HAL_IRQ_NORIFIER_CMD_UNREGISTER_JPE_ERROR_IRQ,

    HAL_IRQ_NORIFIER_CMD_UNREGISTER_MI_IRQ ,    /**< unregister mi irq command  */
    HAL_IRQ_NORIFIER_CMD_UNREGISTER_MI2_IRQ,
    HAL_IRQ_NORIFIER_CMD_MAX

}HalIrqNotifierCmdId_t;


/**
 * @brief Generic command type.
 *
 */
typedef struct HalIrqNotifierCmd_s
{
    HalIrqNotifierCmdId_t    cmdId;
    void                *pCmdCtx;
} HalIrqNotifierCmd_t;



typedef struct IrqContext_s
{
    uint32_t misRegAddress;
    uint32_t mis;
    osEvent      *pIsr_irq_event;        //notify observer interrupt event
    osQueue      *pIsr_mis_queue;        // mis value queue
}IrqContext_t;

typedef struct IrqNotifierContext_s
{

//    IrqContentQueue_t   head;
    osThread    isr_thread;
    osEvent      isr_exit_event;
	osMutex     access_lock;

    osQueue      commandQueue;
    osEvent      process_cmd_done_event;
    int          device_file;
    IrqContext_t  irqSrcCtx[eHalIsrMax];

} IrqNotifierContext_t;

typedef void* IrqNotifierHandle_t;

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
 * createHalIrqNotifierThd()
 *****************************************************************************/
RESULT createHalIrqNotifierThd
(
    IrqNotifierContext_t * pIrqNotifier
);

/******************************************************************************
 * destroyHalIrqNotifierThd()
 *****************************************************************************/
RESULT destroyHalIrqNotifierThd
(
    IrqNotifierContext_t * pIrqNotifier
);

/******************************************************************************
 * HalIrqNotifierSendCommand
 *****************************************************************************/
RESULT HalIrqNotifierSendCommand
(
    IrqNotifierContext_t     *pIrqNotifier,
    HalIrqNotifierCmd_t    *pCommand
);

#ifdef __cplusplus
}
#endif

#endif /* __HAL_ALTERA_IRQ_NOTIFIER_H__ */