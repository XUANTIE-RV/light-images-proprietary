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

#if defined(CTRL_DEWARP)
#include "DW200Driver.h"
#endif

#define DEWARP_CORE_MAX 2

namespace clb {

struct Dewarp : Abstract {
  Dewarp(XMLDocument &);
  ~Dewarp();

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  bool isEnable;

  struct Config {
#if defined(CTRL_DEWARP)
    ~Config() { freeUserMap(); }

    void reset();

    Config &operator=(Config const &);

    void freeUserMap();

    dw200_parameters params;
    dewarp_distortion_map distortionMap[DEWARP_CORE_MAX];
#endif
  } config;
};

} // namespace clb
