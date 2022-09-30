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

struct Cac : Abstract {
  Cac(XMLDocument &);

  void composeAttributes(XMLElement &) override;

  void parseAttributes(XMLElement &) override;

  bool isEnable;

  struct Status {
    void reset();

    int32_t hCenterOffset;
    int32_t vCenterOffset;

    enum {
      Blue,
      Red,

      Sum,
    };

    struct Coeff {
      double linear;
      double square;
      double cubical;
    } coeff[Sum];
  };
};

} // namespace clb
