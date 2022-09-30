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

#pragma once

#include "calib_element_ry.hpp"
#include <algorithm>
#include <list>
#include <string>
#include <tinyxml2/tinyxml2_ry.h>

namespace camdev {

struct Calibration {
  Calibration();
  ~Calibration();

  void load(std::string fileName);
  void store(std::string fileName);

  template <typename T> T &module() {
    return dynamic_cast<T &>(
        **std::find_if(list.begin(), list.end(), [&](Element *pElement) {
          if (dynamic_cast<T *>(pElement)) {
            return true;
          } else {
            return false;
          }
        }));
  }

  std::list<camdev::Element *> list;

  tinyxml2::XMLDocument document;

  bool isReadOnly = false;
};

} // namespace camdev

extern camdev::Calibration *pCalibration;

