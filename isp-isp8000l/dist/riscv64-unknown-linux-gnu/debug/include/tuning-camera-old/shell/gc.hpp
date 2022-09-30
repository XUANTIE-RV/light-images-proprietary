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

struct Gc : Engine {
  enum {
    Begin = Engine::Gc * Engine::Step,

    ConfigGet,
    ConfigSet,
    EnableGet,
    EnableSet,

    End,
  };

  Gc(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Gc &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Gc &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Gc &configSet(Json::Value const &jQuery, Json::Value &jResponse);
  Gc &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Gc &enableSet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
