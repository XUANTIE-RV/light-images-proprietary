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

struct FileSystem : Abstract {
  enum {
    Begin = Abstract::FileSystem * Abstract::Step,

    List,
    Remove,

    End,
  };

  FileSystem(t_camera::Camera *pCamera) : Abstract(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  FileSystem &process(Json::Value const &jQuery,
                      Json::Value &jResponse) override;

  FileSystem &list(Json::Value const &jQuery, Json::Value &jResponse);
  FileSystem &remove(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
