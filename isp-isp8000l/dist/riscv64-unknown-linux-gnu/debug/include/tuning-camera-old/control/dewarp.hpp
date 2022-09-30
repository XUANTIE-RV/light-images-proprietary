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

#include "DW200Driver.h"

namespace dwp {

struct Dewarp : ItfBufferCb, Ctrl {
  Dewarp(HalHandle_t hHal);
  ~Dewarp();

  void bufferCb(MediaBuffer_t *) override;

  void bufferCbBufferConst(MediaBuffer_t *);
  void bufferCbBufferDynamic(MediaBuffer_t *);

  int32_t configGet(clb::Dewarp::Config &);
  int32_t configSet(clb::Dewarp::Config const &);

  int32_t enableGet(bool &);
  int32_t enableSet(bool);

  void onFrameAvailable(uint64_t src0, uint64_t src1);

  int32_t start(void * = NULL) override;
  int32_t stop() override;

#if defined(CTRL_DEWARP)
  DW200Driver *pDriver = nullptr;
#endif

  std::vector<ItfBufferCb *> bufferCbCollection;

  osEvent eventProcessed;

  HalHandle_t hHal;
};

} // namespace dwp
