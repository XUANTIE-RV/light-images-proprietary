/*******************************************************************************/
/*! This is an unpublished work, the copyright in which vests in sci-worx GmbH.
*   The information contained herein is the property of sci-worx GmbH and is
*   supplied without liability for errors or omissions. No part may be repro-
*   duced or used except as authorized by contract or other written permission.
*   Copyright(c) sci-worx GmbH, 2007. All rights reserved.
*/
/******************************************************************************/
/*! Module    : Altera driver
*
* Hierarchy :
*
* Purpose   : User-level driver for the Altera FPGA board
*
* Creator   : Martin Fiedler
*/
/******************************************************************************/
/**
 *  @file altera_fpga.h
 *  @brief User-level driver for the Altera FPGA board
 */

#ifndef _ALTERA_FPGA_H
#define _ALTERA_FPGA_H

#include <hal/hal_common.h>


#ifdef __cplusplus
extern "C" {
#endif

/** Register access mode switch.
  * If set to zero (0), each register access will be done with a "DoMem" ioctl()
  * call to the driver.
  * If set to one (1), all registers will be memory-mapped and accessed directly. */
#define FPGA_USE_MMAP  0

#define FPGA_BOARD_NUM           0           /**< board (DMA engine) number */

#define FPGA_REG_BAR_NUM         1           /**< PCI BAR for register access */

#define FPGA_REGISTER_SPACE_SIZE (512*1024)  /**< size of register BAR */

// these mainly influence byte reordering stuff in AlteraFPGABoard_DMARead/Write functions
// use AlteraFPGABoard_RawDMARead/Write functions to avoid byte reordering & stuff
#define FPGA_DATA_ITEM_SIZE     8
#define FPGA_DATA_BLOCK_SIZE    8
#define FPGA_DATA_BLOCK_STRIDE  8

#define FPGA_DMA_ALIGNMENT       (4*1024)    /**< DMA helper buffer alignment (*must* be a power of two!); used by AlteraFPGABoard_DMARead/Write functions only */
#define FPGA_DMA_SIZE_ALIGNMENT  32          /**< DMA transfer size alignment (*must* be a power of two!); used by AlteraFPGABoard_DMARead/Write functions only */

#define FPGA_DMA_BLOCK_SIZE      (1024*1024) /**< DMA max block size */

#define FPGA_IRQ_POLL_INTERVAL   1000 //20 //50 //20          /**< interrupt poll interval in microseconds */
//#define FPGA_IRQ_POLL_INTERVAL   30000 //50 //20          /**< interrupt poll interval in microseconds */

/** Address adjustment macro.
  * Internally, the driver operates with DWORD (32-bit aligned) adresses. On the
  * FPGA, however, adresses are 128-bit aligned, creating a gap of 3 unused DWORDs
  * between each consecutive pair of registers. To compensate for that, register
  * addresses need to be shifted two bits to the left before using them as FPGA
  * (PCI BAR) addresses. */
#if 0
#define FPGA_REG_ADDRESS_MOD(x) ((x) << 2)
#else
#define FPGA_REG_ADDRESS_MOD(x) (x)
#endif


/* PLL config type. */
typedef struct _AlteraFPGAPLLConfig {
    uint32_t Fin;
    uint16_t M;
    uint16_t N;
    uint16_t C[10];
} AlteraFPGAPLLConfig_t;

/* PLL type. */
typedef struct _AlteraFPGAPLL {
    uint32_t reg_offset;
    uint32_t config_pll_reset_mask;
    uint32_t config_reset_mask;
} AlteraFPGAPLL_t;

/* Predefined PLL descriptions */
extern const AlteraFPGAPLL_t AlteraFPGAPLL_1; //vdu
extern const AlteraFPGAPLL_t AlteraFPGAPLL_2; //msvd, cam1 etc

#if FPGA_USE_MMAP
    extern volatile uint32_t* fpga_regs_mmap;  /**< memory-mapped registers */
#endif

/** error codes */
#define FPGA_RES_OK       0  /**< no error */
#define FPGA_RES_NODEV    1  /**< device file not open / could not open device */
#define FPGA_RES_FAIL     2  /**< general HW failure / wrong or missing device */
#define FPGA_RES_NODMA    3  /**< no DMA engines available */
#define FPGA_RES_INVAL    4  /**< operation not allowed */

#define FPGA_READ_ERROR 0xDEADBEEF  /**< returned from ReadReg in case of failure */

/** AlteraFPGABoard_Open()
  * @brief  Open and initialize the FPGA board.
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_INVAL  board already opened
  * @retval FPGA_RES_NODEV  cannot open device (driver not loaded or wrong permissions)
  * @retval FPGA_RES_FAIL   hardware failure or unexpected hardware behavior
  * @retval FPGA_RES_NODMA  operation successful, but no DMA engines found
  *                         (register access is possible, but DMA access is not) */
uint32_t AlteraFPGABoard_Open(HalHandle_t HalHandle);


void AlteraFPGABoard_Reset(HalHandle_t HalHandle);

/** AlteraFPGABoard_Close()
  * @brief  Uninitialize and close the FPGA board.
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_NODEV  FPGA board not initialized (need to call AlteraFPGABoard_Open() first) */
uint32_t AlteraFPGABoard_Close(HalHandle_t HalHandle);


/** AlteraFPGABoard_ReadBAR()
  * @brief  Read a 32-bit DWORD from one of the PCI BARs on the FPGA.
  * @param  bar             the number of the PCI BAR to access
  * @param  address         the address (128-bit aligned) to read from
  * @return the value read from the register, or FPGA_READ_ERROR if any error occured */
uint32_t AlteraFPGABoard_ReadBAR(int32_t isp_fd, uint32_t address);


/** AlteraFPGABoard_WriteBAR()
  * @brief  Write a 32-bit DWORD to one of the PCI BARs on the FPGA.
  * @param  bar             the number of the PCI BAR to access
  * @param  address         the address (128-bit aligned) to write to
  * @param  data            the data word to write
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_NODEV  FPGA board not initialized (need to call AlteraFPGABoard_Open() first)
  * @retval FPGA_RES_FAIL   could not write value */
uint32_t AlteraFPGABoard_WriteBAR(int32_t isp_fd, uint32_t address, uint32_t data);


/** AlteraFPGABoard_ReadReg()
  * @brief  Read a 32-bit DWORD from one of the registers on the predefined PCI BAR.
  * @param  address         the address (32-bit aligned) to read from
  * @return the value read from the register, or FPGA_READ_ERROR if any error occured */
INLINE uint32_t AlteraFPGABoard_ReadReg(int32_t isp_fd, uint32_t address) {
#if FPGA_USE_MMAP
    return fpga_regs_mmap[FPGA_REG_ADDRESS_MOD(address) >> 2];
#else
    return AlteraFPGABoard_ReadBAR(isp_fd, FPGA_REG_ADDRESS_MOD(address));
#endif
}


/** AlteraFPGABoard_WriteReg()
  * @brief  Write a 32-bit DWORD to one of the registers on the predefined PCI BAR.
  * @param  address         the address (32-bit aligned) to write to
  * @param  data            the data word to write
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_NODEV  FPGA board not initialized (need to call AlteraFPGABoard_Open() first)
  * @retval FPGA_RES_FAIL   could not write value */
INLINE uint32_t AlteraFPGABoard_WriteReg(int32_t isp_fd, uint32_t address, uint32_t data) {
#if FPGA_USE_MMAP
    fpga_regs_mmap[FPGA_REG_ADDRESS_MOD(address) >> 2] = data;
    return FPGA_RES_OK;
#else
    return AlteraFPGABoard_WriteBAR(isp_fd, FPGA_REG_ADDRESS_MOD(address), data);
#endif
}

/** AlteraFPGABoard_ReadMis()
  * @brief  Read a 32-bit DWORD from one of the mis array store in kernel.
  * @param  pAry         pointer to the irq mis src and val array.
  * @return the value read from the mis, or RET_FAILURE if any error occured */
uint32_t AlteraFPGABoard_ReadMis(int32_t isp_fd, uint32_t* pAry);

/** AlteraFPGABoard_RawDMARead()
  * @brief  Transfer a block of memory from the FPGA board's memory into host memory,
  *         bypassing the 256-to-64-bit memory translation.
  * @param  data            host memory pointer to write data to
  * @param  address         board memory address (256-bit aligned) to read data from
  * @param  size            transfer size in bytes (must be a multiple of 32 bytes)
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_NODEV  FPGA board not initialized (need to call AlteraFPGABoard_Open() first)
  * @retval FPGA_RES_FAIL   transfer failed
  * @retval FPGA_RES_NODMA  DMA not available on this board */
uint32_t AlteraFPGABoard_RawDMARead(HalHandle_t HalHandle, void* data, uint32_t address, uint32_t size);



/** AlteraFPGABoard_RawDMAWrite()
  * @brief  Transfer a block of memory from host memory into the FPGA board's memory,
  *         bypassing the 256-to-64-bit memory translation.
  * @param  data            host memory pointer to read data from
  * @param  address         board memory address (256-bit aligned) to write data to
  * @param  size            transfer size in bytes (must be a multiple of 32 bytes)
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_NODEV  FPGA board not initialized (need to call AlteraFPGABoard_Open() first)
  * @retval FPGA_RES_FAIL   transfer failed
  * @retval FPGA_RES_NODMA  DMA not available on this board */
uint32_t AlteraFPGABoard_RawDMAWrite(HalHandle_t HalHandle, void* data, uint32_t address, uint32_t size);


/** AlteraFPGABoard_DMARead()
  * @brief  Transfer a block of memory from the FPGA board's memory into host memory
  *         with 256-to-64-bit memory translation.
  * @param  data            host memory pointer to write data to
  * @param  address         board memory address (64-bit aligned, MSVD address space) to read data from
  * @param  size            transfer size in bytes (must be a multiple of 8 bytes)
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_NODEV  FPGA board not initialized (need to call AlteraFPGABoard_Open() first)
  * @retval FPGA_RES_FAIL   transfer failed
  * @retval FPGA_RES_NODMA  DMA not available on this board */
uint32_t AlteraFPGABoard_DMARead(HalHandle_t HalHandle, uint8_t* data, uint32_t address, uint32_t size);


/** AlteraFPGABoard_DMAWrite()
  * @brief  Transfer a block of memory from host memory into the FPGA board's memory
  *         with 256-to-64-bit memory translation.
  * @param  data            host memory pointer to read data from
  * @param  address         board memory address (64-bit aligned, MSVD address space) to write data to
  * @param  size            transfer size in bytes (must be a multiple of 8 bytes)
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_NODEV  FPGA board not initialized (need to call AlteraFPGABoard_Open() first)
  * @retval FPGA_RES_FAIL   transfer failed
  * @retval FPGA_RES_NODMA  DMA not available on this board */
uint32_t AlteraFPGABoard_DMAWrite(HalHandle_t HalHandle, uint8_t* data, uint32_t address, uint32_t size);


/** AlteraFPGABoard_SetupIRQ()
  * @brief  Set up user interrupt and service routine.
  * @param  irq             pointer to fpga_irq_handle_t structure to be initialized
  * @param  mis_addr        address (32-bit aligned) of the interrupt status register in the user design
  * @param  cis_addr        address (32-bit aligned) of the interrupt clear register in the user design
  * @param  timeout         timeout, in milliseconds, after which a WaitForIRQ() call shall return
  *                         if no interrupt occured. If this is zero (0), no timeout will occur.
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_NODEV  FPGA board not initialized (need to call AlteraFPGABoard_Open() first)
  * @retval FPGA_RES_FAIL   interrupt setup failed */
uint32_t AlteraFPGABoard_SetupIRQ(fpga_irq_handle_t *irq, uint32_t mis_addr, uint32_t cis_addr, uint32_t timeout);


/** AlteraFPGABoard_StopIRQ()
  * @brief  Deregister interrupt service routine.
  * @param  irq             pointer to fpga_irq_handle_t structure to be used
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_NODEV  FPGA board not initialized (need to call AlteraFPGABoard_Open() first)
  * @retval FPGA_RES_FAIL   interrupt setup failed */
uint32_t AlteraFPGABoard_StopIRQ(fpga_irq_handle_t *irq);


/** AlteraFPGABoard_WaitForIRQ()
  * @brief  Wait for an interrupt.
  * @param  irq             pointer to fpga_irq_handle_t structure to be used
  * @param  irq_status      pointer to a variable that receives the contents of the interrupt status register
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_NODEV  FPGA board not initialized (need to call AlteraFPGABoard_Open() first)
  * @retval FPGA_RES_FAIL   wait for interrupt failed or timed out */
uint32_t AlteraFPGABoard_WaitForIRQ(HalIrqCtx_t *pIrqCtx, uint32_t irq_src, uint32_t *irq_status);


/** AlteraFPGABoard_CancelIRQ()
  * @brief  Cancel all pending interrupts.
  * @param  irq             pointer to fpga_irq_handle_t structure to be used
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_NODEV  FPGA board not initialized (need to call AlteraFPGABoard_Open() first)
  * @retval FPGA_RES_FAIL   cancelling of interrupts failed */
uint32_t AlteraFPGABoard_CancelIRQ(fpga_irq_handle_t *irq);


/** AlteraFPGABoard_SetPLLConfig()
  * @brief  Update PLL configuration.
  * @param  pll             one of the predefined PLL object structures
  * @retval cfg             pointer to the new configuration
  * @retval FPGA_RES_OK     operation successful
  * @retval FPGA_RES_NODEV  FPGA board not initialized (need to call AlteraFPGABoard_Open() first)
  * @retval FPGA_RES_FAIL   reconfiguration failed */
uint32_t AlteraFPGABoard_SetPLLConfig(const AlteraFPGAPLL_t* pll, const AlteraFPGAPLLConfig_t* cfg);


#if FPGA_USE_KERNEL_IRQ_HANDLING

#define AlteraFPGABoard_ForbidIRQPolling(x) do { } while (0)
#define AlteraFPGABoard_AllowIRQPolling(x)  do { } while (0)

#else

/** AlteraFPGABoard_ForbidIRQPolling()
  * @brief  Temporally forbid IRQ polling */
void AlteraFPGABoard_ForbidIRQPolling(fpga_irq_handle_t *irq);

/** AlteraFPGABoard_AllowIRQPolling()
  * @brief  Re-allow IRQ polling */
void AlteraFPGABoard_AllowIRQPolling(fpga_irq_handle_t *irq);

#endif


#ifdef __cplusplus
}
#endif

#endif /* _ALTERA_FPGA_H */
