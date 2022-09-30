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

namespace t_shell {

struct Camera : Abstract {
  enum {
    Begin = Abstract::Camera * Abstract::Step,

    CalibrationGet,
    CalibrationSet,
    Capture,
    InputInfo,
    InputSwitch,
    Preview,

    End,
  };

  Camera(t_camera::Camera *pCamera) : Abstract(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Camera &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Camera &calibrationGet(Json::Value const &jQuery, Json::Value &jResponse);
  Camera &calibrationSet(Json::Value const &jQuery, Json::Value &jResponse);

  Camera &capture(Json::Value const &jQuery, Json::Value &jResponse);

  Camera &inputInfo(Json::Value const &jQuery, Json::Value &jResponse);
  Camera &inputSwitch(Json::Value const &jQuery, Json::Value &jResponse);

  Camera &preview(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
