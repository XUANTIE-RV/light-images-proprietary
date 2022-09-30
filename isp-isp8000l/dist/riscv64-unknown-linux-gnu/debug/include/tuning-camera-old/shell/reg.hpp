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

struct Reg : Engine {
  enum {
    Begin = Engine::Reg * Engine::Step,

    ConfigGet,
    ConfigSet,
    StatusGet,

    End,
  };

  Reg(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Reg &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Reg &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Reg &configSet(Json::Value const &jQuery, Json::Value &jResponse);

  Reg &statusGet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
