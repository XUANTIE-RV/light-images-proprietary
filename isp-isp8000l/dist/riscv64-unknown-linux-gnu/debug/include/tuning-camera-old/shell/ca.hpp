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

struct Ca : Engine {
  enum {
    Begin = Engine::Ca * Engine::Step,

    ConfigGet,
    ConfigSet,
    EnableGet,
    EnableSet,
    TableGet,
    TableSet,

    End,
  };

  Ca(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Ca &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Ca &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Ca &configSet(Json::Value const &jQuery, Json::Value &jResponse);

  Ca &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Ca &enableSet(Json::Value const &jQuery, Json::Value &jResponse);

  Ca &tableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Ca &tableSet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
