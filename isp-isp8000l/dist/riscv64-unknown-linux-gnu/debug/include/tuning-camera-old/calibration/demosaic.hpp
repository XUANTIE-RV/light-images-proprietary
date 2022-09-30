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

struct DeMosaic : Abstract {
  DeMosaic(XMLDocument &);

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  enum Generation { V1, V2, VMax };

  union Config {
    struct V1 {
      void reset();

      uint8_t threshold;
    } v1;

    struct V2 : V1 {
      void reset();

      struct InterplationDirectionThreshold {
        uint16_t min;
        uint16_t max;
      } interplationDirectionThreshold;

      struct Demoire {
        bool isEnable;

        uint8_t areaThreshold;
        uint8_t saturationShrink;

        struct {
          uint16_t r2;
          uint16_t r1;
          uint8_t t2Shift;
          uint8_t t1;
        } threshold;

        struct {
          uint16_t r2;
          uint16_t r1;
          uint8_t t2Shift;
          uint16_t t1;
        } edge;
      } deMoire;

      struct Sharpen {
        bool isEnable;

        struct {
          uint16_t black;
          uint16_t white;
        } factor, clip;

        struct Threshold {
          uint16_t t4Shift;
          uint16_t t3;
          uint8_t t2Shift;
          uint16_t t1;
        } threshold;

        struct Ratio {
          uint16_t r3;
          uint16_t r2;
          uint16_t r1;
        } ratio;
      } sharpen;

      struct SharpenLine {
        bool isEnable;

        uint8_t shift1;
        uint8_t shift2;
        uint16_t t1;
        uint16_t strength;

        struct Ratio {
          uint16_t r2;
          uint16_t r1;
        } ratio;
      } sharpenLine;

      struct SharpenFilter {
        uint8_t _00;
        uint8_t _01;
        uint8_t _02;
        uint8_t _10;
        uint8_t _11;
        uint8_t _12;

        uint8_t _20;
        uint8_t _21;
        uint8_t _22;
      } sharpenFilter;

      struct DePurple {
        bool isEnable;

        enum CbCrMode {
          Off,
          Red,
          Blue,
          RedBlue,
        } cbCrMode;

        uint8_t saturationShrink;
        uint8_t threshold;
      } dePurple;

      struct Skin {
        bool isEnable;

        struct {
          uint16_t max2047;
          uint16_t min2047;
        } cbThreshold, crThreshold, yThreshold;
      } skin;

      struct Cac {
        bool isEnable;

        struct Count {
          uint16_t v;
          uint16_t h;
        } count;

        struct {
          uint16_t red;
          uint16_t blue;
        } a, b, c;

        struct Normal {
          uint8_t s;
          uint8_t f;
        } x, y;
      } cac;

      uint8_t denoiseStrength;
      uint8_t sharpenSize;
    } v2;
  };

  struct Holder {
    bool isEnable;

    Config config;
  };

  std::vector<Holder> holders;
};

} // namespace clb
