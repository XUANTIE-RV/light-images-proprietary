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
 * @file align.h
 *
 * @brief
 *
 *****************************************************************************/
#ifndef __ALIGN_H__
#define __ALIGN_H__

#ifndef ALIGN_UP
#define ALIGN_UP(addr, align)		( ((addr) + ((align)-1)) & ~(uintptr_t)((align)-1) ) //!< Aligns addr to next higher aligned addr; align must be a power of two.
#endif
#define ALIGN_DOWN(addr, align)		( ((addr)              ) & ~(uintptr_t)((align)-1) ) //!< Aligns addr to next lower aligned addr; align must be a power of two.

#define ALIGN_SIZE_1K               ( 0x400 )
#define ALIGN_UP_1K(addr)			( ALIGN_UP(addr, ALIGN_SIZE_1K) )

#define MAX_ALIGNED_SIZE(size, align) ( ALIGN_UP(size, align) + align ) //!< Calcs max size of memory required to be able to hold a block of size bytes with a start address aligned to align.

#endif /* __ALIGN_H__ */
