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

struct Image : Abstract {
  Image(XMLDocument &document);

  void composeSubElements(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  struct Config {
    void reset();

    std::string fileName;
  } config;
};

struct Images : Abstract {
  Images(XMLDocument &);

  void composeSubElements(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  std::vector<Image> images;
};

} // namespace clb
