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

struct Dci : Abstract {
  Dci(XMLDocument &);

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  struct Config {
    void reset();

    enum Mode {
      Mode2Sections,
      Mode3Sections,
      ModeHistogram,

      ModeSum,
    } mode;

    struct Exponent {
      double high;
      double low;
      double middle;
    } exponent;

    struct Histogram {
      double scale;
      double step;
      double base;
      double strength;
      double damp;
    } histogram;

    bool isAuto;

    struct Point {
      double x;
      double y;
    } start, inflection, inflection2, end;
  } config;

  bool isEnable;

  struct Table {
    enum Column {
      Hdr,
      Gain,
      IntegrationTime,
      SectionLowExponent,
      SectionMiddleExponent,
      SectionHighExponent,
      SectionPointStartX,
      SectionPointStartY,
      SectionPointInflectionX,
      SectionPointInflectionY,
      SectionPointEndX,
      SectionPointEndY,
      SectionPointInflection2X,
      SectionPointInflection2Y,
      HistogramScale,
      HistogramStepSize,
      HistogramBase,
      HistogramStrength,
      HistogramDamp,
    };

    void reset();

    Json::Value jTable;
  } table;
};

} // namespace clb
