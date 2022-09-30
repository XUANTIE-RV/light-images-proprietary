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

struct Ca : Abstract {
  Ca(XMLDocument &);

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  bool isEnable;

  struct Config {
    void reset();

    enum Curve {
      S,
      Parabolic,
    } curve;

    enum Mode {
      Brightness,
      Saturation,
      BrightnessSaturation,
    } mode;

    int32_t curveSInflection;
    int32_t curveSExponent;
    double curveParabolicFactor;

    bool isAuto;
  } config;

  struct Table {
    enum Column {
      Hdr,
      Gain,
      IntegrationTime,
      SCurveInflection,
      SCurveExponent,
      ParabolicFactor,
    };

    void reset();

    Json::Value jTable;
  } table;
};

} // namespace clb
