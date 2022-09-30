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

namespace clb {

struct Awb : Abstract {
  Awb(XMLDocument &);

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  bool isEnable;

  struct Config {
    void reset();

    int32_t illuminationProfileIndex;

    bool isAuto;
    bool isDamping;

    int32_t profilesCount;

#define AWB_PROFILE_COUNT 10
#define AWB_PROFILE_NAME_LENGTH 20
    char profilesName[AWB_PROFILE_COUNT][AWB_PROFILE_NAME_LENGTH];
  } config;

  struct Status {
    double indoorMin;
    double max;
    double maxSky;
    double outdoorMin;
  };
};

} // namespace clb
