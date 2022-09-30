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

struct Dnr2 : Engine {
  enum {
    Begin = Engine::Dnr2 * Engine::Step,

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

  Dnr2(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Dnr2 &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Dnr2 &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Dnr2 &configSet(Json::Value const &jQuery, Json::Value &jResponse);

  Dnr2 &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Dnr2 &enableSet(Json::Value const &jQuery, Json::Value &jResponse);

  Dnr2 &reset(Json::Value const &jQuery, Json::Value &jResponse);

  Dnr2 &statusGet(Json::Value const &jQuery, Json::Value &jResponse);

  Dnr2 &tableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Dnr2 &tableSet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
