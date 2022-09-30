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

struct Dnr3 : Abstract {
  Dnr3(XMLDocument &);

  void composeSubElements(XMLElement &) override;

  void parseSubElements(XMLElement &) override;

  enum Generation { V1, V3, VMax };

  union Config {
    struct Abstract {
      bool isAuto;
      double autoLevel;
    };

    struct V1 : Abstract {
      void reset();

      int32_t deltaFactor;
      int32_t motionFactor;
      int32_t strength;
    } v1;

    struct V3 {
      void reset();

      bool isEnableNoiseCurve;

      struct Tnr : Abstract {
        bool isEnable;

        uint16_t filterLength;
        uint8_t filterLength2;
        uint8_t motionSlope;
        uint16_t noiseLevel;
        uint8_t sadWeight;
      } tnr;
    } v3;
  };

  struct Status {
    double gain;
    double integrationTime;
  };

  struct Table {
    void reset(Generation Generation);

    enum ColumnV1 {
      V1Hdr,
      V1Gain,
      V1IntegrationTime,
      V1Strength,
      V1MotionFactor,
      V1DeltaFactor,
    };

    enum ColumnV3 {
      V3Hdr,
      V3Gain,
      V3IntegrationTime,
      V3FilterLength,
      V3FilterLength2,
      V3MotionSlope,
      V3NoiseLevel,
      V3SadWeight,
    };

    Json::Value jTable;
  };

  struct Holder {
    bool isEnable;

    Config config;
    Table table;
  };

  std::vector<Holder> holders;
};

} // namespace clb
