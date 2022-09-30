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
#include <IDisplay.h>

struct Drm : ItfBufferCb, Ctrl {
  Drm();
  ~Drm();

  void bufferCb(MediaBuffer_t *) override;

  static void cbCompletion(int, int32_t, const void *);

  int32_t start(void * = NULL) override;
  int32_t stop() override;

  void *hCtrl = NULL;
  IDisplay *pDisplay = NULL;
};
