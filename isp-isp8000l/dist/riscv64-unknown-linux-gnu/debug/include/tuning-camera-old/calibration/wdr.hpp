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
#include <cam_engine/cam_engine_api.h>

#include <cam_engine/cam_engine_isp_api.h>

namespace clb {

#define CURVE_ARRAY_SIZE 33

struct Wdr : Abstract {
  Wdr(XMLDocument &);

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  enum Generation { V1, V2, V3, V4, VMax };

  union Config {
    struct V1 {
      void reset();

      CamEngineWdrCurve_t curve;
    } v1;

    struct V2 {
      void reset();

      float strength;
    } v2;

    struct V3 {
      void reset();

      bool isAuto;
      int autoLevel;

      int gainMax;
      int strength;
      int strengthGlobal;
    } v3;

    struct V4 {
      void reset();

      bool isAuto;
      int autoLevel;

      int contrast;
      int flatStrength;
      int flatThreshold;
      int strength;
      int strengthHigh;
      int strengthLow;
      int strengthGlobal;
    } v4;
  };

  struct Status {
    double gain;
    double integrationTime;
  };

  struct Table {
    void reset(Generation generation);

    enum ColumnV3 {
      Hdr,
      Gain,
      IntegrationTime,
      Strength,
      MaxGain,
      GlobalCurve,
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
