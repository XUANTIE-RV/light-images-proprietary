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

struct Hdr : Engine {
  enum {
    Begin = Engine::Hdr * Engine::Step,

    ConfigGet,
    ConfigSet,
    EnableGet,
    EnableSet,
    Reset,
    StatusGet,

    End,
  };

  Hdr(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Hdr &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Hdr &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Hdr &configSet(Json::Value const &jQuery, Json::Value &jResponse);

  Hdr &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Hdr &enableSet(Json::Value const &jQuery, Json::Value &jResponse);

  Hdr &reset(Json::Value const &jQuery, Json::Value &jResponse);

  Hdr &statusGet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
