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

using namespace std;

namespace clb {

struct Dnr2 : Abstract {
  Dnr2(XMLDocument &);

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  enum Generation { V1, V5, VMax };

  union Config {
    struct Abstract {
      bool isAuto;
      int32_t autoLevel;
    };

    struct V1 : Abstract {
      void reset();

      int32_t denoisePregamaStrength;
      int32_t denoiseStrength;
      double sigma;
    } v1;

    struct V5 : Abstract {
      void reset();

      struct BlendOpacity {
        int32_t _static;
        int32_t moving;
      } blendOpacity;

      double denoiseStrength;
      double sigma;
    } v5;
  };

  struct Status {
    double gain;
    double integrationTime;
  };

  struct Table {
    enum ColumnV1 {
      V1Hdr,
      V1Gain,
      V1IntegrationTime,
      V1PregammaStrength,
      V1DenoiseStrength,
      V1Sigma,
    };

    enum ColumnV5 {
      V5Hdr,
      V5Gain,
      V5IntegrationTime,
      V5DenoiseStrength,
      V5Sigma,
      V5BlendingOpacityStaticArea,
      V5BlendingOpacityMovingArea,
    };

    void reset(Generation generation);

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
