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

struct Dci : Engine {
  enum {
    Begin = Engine::Dci * Engine::Step,

    ConfigGet,
    ConfigSet,
    EnableGet,
    EnableSet,
    TableGet,
    TableSet,

    End,
  };

  Dci(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Dci &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Dci &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Dci &configSet(Json::Value const &jQuery, Json::Value &jResponse);

  Dci &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Dci &enableSet(Json::Value const &jQuery, Json::Value &jResponse);

  Dci &tableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Dci &tableSet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
