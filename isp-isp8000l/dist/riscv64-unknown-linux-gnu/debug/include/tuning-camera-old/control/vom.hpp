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

#include <vom_ctrl/vom_ctrl_api.h>

struct Vom : ItfBufferCb, Ctrl {
  Vom(HalHandle_t hHal);
  ~Vom();

  void bufferCb(MediaBuffer_t *) override;

  static void cbCompletion(vomCtrlCmdId_t, int32_t, void const *);

  int32_t start(void * = NULL) override;
  int32_t stop() override;

  vomCtrlHandle_t hCtrl = NULL;
};
