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

#include "abstract.hpp"
#include "input.hpp"
#include <vector>

namespace clb {

struct Reg : Abstract {
  Reg(XMLDocument &document);

  struct Config {
    void reset();

    uint32_t address;

    enum {
      ReadOnly,
      ReadWrite,
      WriteOnly,
    } permission;

    char name[30];
    char description[100];
    uint32_t value;
    uint32_t valueDefault;
    uint32_t bitMaskUsed;
    uint32_t bitMaskWriteable;
  } config;
};

} // namespace clb
