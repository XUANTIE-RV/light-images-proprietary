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

#include "engine.hpp"

namespace t_shell {

struct Af : Engine {
  enum {
    Begin = Engine::Af * Engine::Step,

    AvailableGet,
    ConfigGet,
    ConfigSet,
    EnableGet,
    EnableSet,

    End,
  };

  Af(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Af &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Af &availableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Af &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Af &configSet(Json::Value const &jQuery, Json::Value &jResponse);
  Af &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Af &enableSet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
