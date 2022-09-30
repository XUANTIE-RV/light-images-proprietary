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

struct Ae : Abstract {
  Ae(XMLDocument &);

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  enum Generation { V1, V2, VMax };

  union Config {
    struct V1 {
      void reset();

      bool isBypass;

      enum Mode {
        ModeDisable,
        ModeFix,
        ModeAdaptive,

        ModeSum,
      } mode;

      double dampingOver;
      double dampingUnder;
      double setPoint;
      double tolerance;

      struct Ecm {
        void reset();

        enum FlickerPeriod {
          FlickerPeriodOff,
          FlickerPeriod100Hz,
          FlickerPeriod120Hz,
        } flickerPeriod;

        double flickerPeriodValue() {
          switch (flickerPeriod) {
          case CAM_ENGINE_FLICKER_OFF:
          default:
            return 0.0000001;

          case CAM_ENGINE_FLICKER_100HZ:
            return 1.0 / 100.0;

          case CAM_ENGINE_FLICKER_120HZ:
            return 1.0 / 120.0;
          }
        }

        bool isAfps;
      } ecm;
    } v1;

    struct V2 : V1 {
      int dummy;
    } v2;
  };

  struct Holder {
    bool isEnable;

    Config config;
  };

  std::vector<Holder> holders;

  struct Status {
    void reset();

    union histogram {
      struct V1 {
        unsigned int _16[16];
      } v1;

      struct V2 {
        unsigned int _16[16];
        unsigned int _64[32];
        unsigned int _256[256];

        struct Hdr {
          unsigned char aeData[75];

          unsigned int green[16];
          unsigned int blue[16];
          unsigned int red[16];
        } hdr;
      } v2;
    } histogram;

    unsigned char luminance[25];
    unsigned char objectRegion[25];
  };
};

} // namespace clb
