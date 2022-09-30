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
#include "input.hpp"
#include <vector>

namespace clb {

struct Sensor : Abstract {
  Sensor(XMLDocument &document);

  void composeSubElements(XMLElement &) override;

  void parseSubElements(XMLElement &) override;

  struct Config {
    void reset();

    enum BayerPattern {
      Bggr,
      Gbrg,
      Grbg,
      Rggb,

      Sum,
    } bayerPattern;

    int framesPerSecond;

    bool isTestPattern;

    struct Exposure {
      float gain;
      float integrationTime;
    } _long, _short, veryShort;

    struct Resolution {
      uint32_t height;
      uint32_t width;
    } resolution;
  } config;

  struct Status {
    void reset();

    char driverName[30];

    bool isConnected;

    struct Range {
      float max;
      float min;
      float step;
    } gain, integrationTime;

    struct ResolutionCollection {
      int count;
      Config::Resolution resolutions[10];
    } resolutionCollection;
  } status;

  std::string driverFileName;
};

struct Sensors : Abstract {
  Sensors(XMLDocument &);

  void composeSubElements(XMLElement &) override;

  void parseSubElements(XMLElement &) override;

  std::vector<Sensor> sensors;
};

} // namespace clb
