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

#include "abstract.hpp"

#include <cam_engine/cam_engine_api.h>

#include <cam_engine/cam_engine_isp_api.h>

namespace clb {

struct Wb : Abstract {
  Wb(XMLDocument &document);

  void composeSubElements(XMLElement &) override;

  void parseSubElements(XMLElement &) override;

  struct Config {
    void reset();

    CamEngineCcMatrix_t ccMatrix;
    CamEngineCcOffset_t ccOffset;
    CamEngineWbGains_t wbGains;
  } config;
};

} // namespace clb
