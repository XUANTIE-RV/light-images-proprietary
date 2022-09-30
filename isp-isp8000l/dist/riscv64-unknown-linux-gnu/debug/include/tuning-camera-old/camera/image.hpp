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

#include "common/interface.hpp"
#include <cam_engine/cam_engine_api.h>

namespace t_camera {

struct Image : Object {
  Image(clb::Calibration * = nullptr, int32_t = -1);
  ~Image();

  Image &checkValid();

  void clean();

  void load(std::string fileName);

  int32_t index = 0;

  struct Config {
    Config() { REFSET(picBufMetaData, 0); }

    PicBufMetaData_t picBufMetaData;

    bool isLsb = false;
  } config;
};

} // namespace t_camera
