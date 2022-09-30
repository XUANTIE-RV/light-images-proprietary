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

#include "abstract.hpp"

namespace t_shell {

struct Cli : Abstract {
  enum {
    Begin = Abstract::Cli * Abstract::Step,

    ControlListGet,
    VersionGet,

    End,
  };

  Cli(t_camera::Camera *pCamera) : Abstract(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Cli &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Cli &controlListGet(Json::Value const &jQuery, Json::Value &jResponse);
  Cli &versionGet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
