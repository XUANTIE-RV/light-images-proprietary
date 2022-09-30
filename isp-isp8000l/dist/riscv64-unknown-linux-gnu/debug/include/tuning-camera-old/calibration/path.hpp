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

namespace clb {

struct Path : Abstract {
  Path(XMLDocument &);

  void composeSubElements(XMLElement &) override;

  void parseSubElements(XMLElement &) override;

  void pathComposeSubElements(XMLElement &element,
                              CamEnginePathConfig_t &config);

  void pathParseSubElements(XMLElement &element, CamEnginePathConfig_t &config);

  struct Config {
    void reset();

    CamEnginePathConfig_t config[CAMERIC_MI_PATH_MAX];
  } config;
};

} // namespace clb
