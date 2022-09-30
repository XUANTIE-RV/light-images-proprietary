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

#include "misc.hpp"

namespace t_shell {

struct DeHaze : Misc {
  enum {
    Begin = Misc::DeHaze * Misc::Step,

    EnableGet,
    EnableSet,

    End,
  };

  DeHaze(t_camera::Camera *pCamera) : Misc(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  DeHaze &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  DeHaze &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  DeHaze &enableSet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
