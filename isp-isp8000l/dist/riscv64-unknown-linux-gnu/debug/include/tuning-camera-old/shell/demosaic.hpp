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

struct DeMosaic : Engine {
  enum {
    Begin = Engine::DeMosaic * Engine::Step,

    ConfigGet,
    ConfigSet,
    EnableGet,
    EnableSet,
    Reset,

    End,
  };

  DeMosaic(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  DeMosaic &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  DeMosaic &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  DeMosaic &configSet(Json::Value const &jQuery, Json::Value &jResponse);

  DeMosaic &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  DeMosaic &enableSet(Json::Value const &jQuery, Json::Value &jResponse);

  DeMosaic &reset(Json::Value const &jQuery, Json::Value &jResponse);

  void demosiacClbToRy(RydemosiacCfg_t* ryconfig, clb::DeMosaic::Config &config,  clb::DeMosaic::Generation generation);
  void demosiacRyToClb(RydemosiacCfg_t* ryconfig, clb::DeMosaic::Config &config);
};

} // namespace t_shell
