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

//! Powered by Yong Yang

#pragma once

#include "common/interface.hpp"

#include <som_ctrl/som_ctrl_api.h>

struct Som : ItfBufferCb, Ctrl {
  Som(HalHandle_t hHal);
  ~Som();

  void bufferCb(MediaBuffer_t *) override;

  static void cbCompletion(somCtrlCmdID_t, int32_t, somCtrlCmdParams_t *,
                           somCtrlCompletionInfo_t *, void *);

  struct StartParam {
    char const *pFilenameBase;
    uint32_t frameCount;
    uint32_t skipCount;
    uint32_t averageFrameCount;
    bool_t isForceRgbOut;
    bool_t isExtendName;
  };

  int32_t start(void *) override;
  int32_t stop() override;

  somCtrlHandle_t hCtrl = NULL;

  osEvent eventDone;
};
