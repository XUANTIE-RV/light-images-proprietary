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

#ifndef _CAM_ENGINE_BUFFER_CTRL_H_
#define _CAM_ENGINE_BUFFER_CTRL_H_

int BufferOpen(void *    HalHandle);

uint64_t BufferAllocate(uint32_t size);

int BufferFree(uint64_t addr);

void BufferClose(void);

#endif /* _CAM_ENGINE_BUFFER_CTRL_H_ */
