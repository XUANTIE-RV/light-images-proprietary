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

#include "camera/camera.hpp"

#define TRACE_CMD                                                              \
  std::cout << COLOR_BLUE << __COMPACT_PRETTY_FUNCTION__ << COLOR_POST_FIX     \
            << std::endl

#define RET_IRRELATIVE 0xFF

namespace t_shell {

struct Abstract : t_common::Version {
  enum {
    Begin,

    Camera,
    Cli,
    Dewarp,
    Engine,
    FileSystem,
    Image,
    Misc,
    Sensor,

    End,

    Step = 10000,
  };

  Abstract(t_camera::Camera *pCamera) : pCamera(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  virtual Abstract &process(Json::Value const &jQuery, Json::Value &jResponse);

  t_camera::Sensor &sensor();

  void versionGet(std::string &name, std::string &number,
                  std::string &date) override;

  int32_t idBegin;
  int32_t idEnd;

  t_camera::Camera *pCamera = nullptr;
};

} // namespace t_shell
