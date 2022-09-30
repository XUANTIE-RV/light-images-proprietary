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

#include "shell.hpp"

namespace t_shell {

struct Sensor : Abstract {
  enum {
    Begin = Abstract::Sensor * Abstract::Step,

    ConfigGet,
    ConfigSet,
    DriverChange,
    RegisterDumpToFile,
    RegisterGet,
    RegisterSet,
    StatusGet,

    End,
  };

  Sensor(t_camera::Camera *pCamera) : Abstract(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Sensor &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Sensor &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Sensor &configSet(Json::Value const &jQuery, Json::Value &jResponse);

  Sensor &driverChange(Json::Value const &jQuery, Json::Value &jResponse);

  Sensor &registerDump2File(Json::Value const &jQuery, Json::Value &jResponse);
  Sensor &registerGet(Json::Value const &jQuery, Json::Value &jResponse);
  Sensor &registerSet(Json::Value const &jQuery, Json::Value &jResponse);

  Sensor &statusGet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
