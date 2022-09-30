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

#include "cproc.hpp"
#include "wdr.hpp"

namespace clb {

struct DeHaze : Abstract {
  DeHaze(XMLDocument &);
  ~DeHaze();

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  struct Config {
    void reset();

    Cproc *pCproc = nullptr;
    Wdr *pWdr = nullptr;
  } config;

  struct Enable {
    void reset();

    bool isCproc;
    bool isGwdr;
    bool isWdr3;
  } enable;
};

} // namespace clb
