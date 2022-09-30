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

struct Ee : Engine {
  enum {
    Begin = Engine::Ee * Engine::Step,

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

  Ee(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  struct Config {
    int32_t strength;
    int32_t sharpen;
    int32_t depurple;
  };

  Ee &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Ee &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Ee &configSet(Json::Value const &jQuery, Json::Value &jResponse);

  Ee &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Ee &enableSet(Json::Value const &jQuery, Json::Value &jResponse);

  Ee &reset(Json::Value const &jQuery, Json::Value &jResponse);

  Ee &statusGet(Json::Value const &jQuery, Json::Value &jResponse);

  Ee &tableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Ee &tableSet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
