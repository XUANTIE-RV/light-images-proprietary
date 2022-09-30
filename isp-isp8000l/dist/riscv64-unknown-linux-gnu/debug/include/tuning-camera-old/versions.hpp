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

#include <string>
#include <vector>

struct Versions {
  Versions();
  ~Versions();

  struct Version {
    Version(std::string name, std::string number = "", std::string date = "")
        : date(date), name(name), number(number) {}

    std::string date;
    std::string name;
    std::string number;
  };

  std::vector<Version *> collection;
};
