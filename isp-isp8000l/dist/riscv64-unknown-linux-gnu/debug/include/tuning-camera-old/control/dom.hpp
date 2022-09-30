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

#include <dom_ctrl/dom_ctrl_api.h>

struct Dom : ItfBufferCb, Ctrl {
  Dom();
  ~Dom();
  Dom(HalHandle_t         HalHandle);
  void bufferCb(MediaBuffer_t *) override;

  static void cbCompletion(domCtrlCmdId_t, int32_t, void const *);

  int32_t start(void * = NULL) override;
  int32_t stop() override;

  domCtrlHandle_t hCtrl = NULL;
};
