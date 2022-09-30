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
#include <algorithm>

namespace clb {

#define AVS_DAMP_DATA_MAX 50

struct Avs : Abstract {
  Avs(XMLDocument &);

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  bool isEnable;

  struct Config {
    void reset();

    bool isUseParams;

    float acceleration;
    float baseGain;
    float fallOff;
    uint16_t numItpPoints;
    float theta;

    int32_t dampCount;
    double x[AVS_DAMP_DATA_MAX];
    double y[AVS_DAMP_DATA_MAX];
  } config;

  struct Status {
    std::pair<int16_t, int16_t> displacement;
    std::pair<int16_t, int16_t> offset;
  };
};

} // namespace clb
