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

struct Ahdr : Engine {
  enum {
    Begin = Engine::Ahdr * Engine::Step,

    ConfigGet,
    ConfigSet,
    EnableGet,
    EnableSet,
    Reset,
    TableGet,
    TableSet,

    End,
  };

  Ahdr(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Ahdr &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Ahdr &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Ahdr &configSet(Json::Value const &jQuery, Json::Value &jResponse);

  Ahdr &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Ahdr &enableSet(Json::Value const &jQuery, Json::Value &jResponse);

  Ahdr &reset(Json::Value const &jQuery, Json::Value &jResponse);

  Ahdr &tableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Ahdr &tableSet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
