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

#define CLB_HDR_SENSOR_CURVE_POINT 64

namespace clb {

struct Hdr : Abstract {
  Hdr(XMLDocument &document);

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  enum Generation { V1, V1_2, VMax };

  union Config {
    struct V1 {
      void reset();

      float exposureRatio;
      int extensionBit;
    } v1;

    struct V1_2 {
      void reset();

      enum Mode {
        LongShort,
        LongShortVeryShort,

        Sum,
      } mode;

      struct Parampeter {
        int exposureRatio;
        int extensionBit;

        struct Range {
          double begin;
          double end;
        } trans;
      } parameters[Sum];
    } v1_2;
  };

  struct Sensor {
    float curve[CLB_HDR_SENSOR_CURVE_POINT * 2];
  } sensor;

  struct Holder {
    bool isEnable;

    Config config;
  };

  std::vector<Holder> holders;

  union Status {
    struct V1_2 {
      enum Mode { _2Dol, _3Dol } mode;
    } v1_2;
  };
};

} // namespace clb
