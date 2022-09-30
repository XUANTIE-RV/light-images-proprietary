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

struct Gc : Abstract {
  Gc(XMLDocument &);

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  enum Generation { V1, V2, VMax };

  union Config {
    Config() {}

    struct CurveAbstract {
      double gamma;

      enum XScale {
        Logarithmic,
        Equidistant,
      } xScale;
    };

    struct Curve : CurveAbstract {
         Curve() {}

#define GC_CURVE_POINT_COUNT 17
   Curve(double gamma, XScale xScale, uint32_t y[GC_CURVE_POINT_COUNT]) {
        this->gamma = gamma;
        this->xScale = xScale;
        REFCPY(this->y, y);
      }

      void reset();

      uint32_t y[GC_CURVE_POINT_COUNT];
    };

    struct Curve2 : CurveAbstract {
        Curve2() {}

#define GC2_CURVE_POINT_COUNT 64
    Curve2(double gamma, XScale xScale, uint32_t pX[GC2_CURVE_POINT_COUNT],
             uint32_t x[GC2_CURVE_POINT_COUNT],
             uint32_t y[GC2_CURVE_POINT_COUNT]) {
        this->gamma = gamma;
        this->xScale = xScale;

        REFCPY(this->pX, pX);
        REFCPY(this->x, x);
        REFCPY(this->y, y);
      }

      void reset();

      uint32_t pX[GC2_CURVE_POINT_COUNT];
      uint32_t x[GC2_CURVE_POINT_COUNT];
      uint32_t y[GC2_CURVE_POINT_COUNT];
    };

    struct V1 {
      void reset();

      Curve curve;
    } v1;

    struct V2 {
      enum Channel {
        ChannelBlue,
        ChannelGreen,
        ChannelRed,

        ChannelSum
      };

      Curve2 curves[ChannelSum];
    } v2;
  };

  struct Holder {
    Holder() {}

    bool isEnable;

    Config config;
  };

  std::vector<Holder> holders;
};

} // namespace clb
