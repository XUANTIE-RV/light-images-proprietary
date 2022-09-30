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

struct Cproc : Engine {
  enum {
    Begin = Engine::Cproc * Engine::Step,

    ConfigGet,
    ConfigSet,
    EnableGet,
    EnableSet,

    End,
  };

  Cproc(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Cproc &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Cproc &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Cproc &configSet(Json::Value const &jQuery, Json::Value &jResponse);
  Cproc &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Cproc &enableSet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
