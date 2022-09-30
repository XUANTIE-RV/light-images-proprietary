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

struct Filter : Abstract {
  Filter(XMLDocument &);

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  bool isEnable;

  struct Config {
    void reset();

    bool isAuto;

    int32_t denoise;
    int32_t sharpen;
  } config;

  struct Status {
    void reset();

    double gain;
    double integrationTime;
  };

  struct Table {
    void reset();

    enum Column {
      Hdr,
      Gain,
      IntegrationTime,
      Denoising,
      Sharpening,
    };

    Json::Value jTable;
  } table;
};

} // namespace clb
