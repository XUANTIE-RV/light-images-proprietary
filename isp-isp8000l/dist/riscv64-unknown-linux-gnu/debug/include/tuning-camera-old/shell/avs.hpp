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

struct Avs : Engine {
  enum {
    Begin = Engine::Avs * Engine::Step,

    ConfigGet,
    ConfigSet,
    EnableGet,
    EnableSet,
    StatusGet,

    End,
  };

  Avs(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Avs &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Avs &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Avs &configSet(Json::Value const &jQuery, Json::Value &jResponse);
  Avs &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Avs &enableSet(Json::Value const &jQuery, Json::Value &jResponse);
  Avs &statusGet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
