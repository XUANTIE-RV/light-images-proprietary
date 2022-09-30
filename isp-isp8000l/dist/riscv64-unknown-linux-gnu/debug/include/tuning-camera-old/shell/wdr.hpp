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

struct Wdr : Engine {
  enum {
    Begin = Engine::Wdr * Engine::Step,

    ConfigGet,
    ConfigSet,
    EnableGet,
    EnableSet,
    Reset,
    StatusGet,
    TableGet,
    TableSet,

    End,
  };

  Wdr(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Wdr &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Wdr &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Wdr &configSet(Json::Value const &jQuery, Json::Value &jResponse);

  Wdr &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Wdr &enableSet(Json::Value const &jQuery, Json::Value &jResponse);

  Wdr &reset(Json::Value const &jQuery, Json::Value &jResponse);

  Wdr &statusGet(Json::Value const &jQuery, Json::Value &jResponse);

  Wdr &tableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Wdr &tableSet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
