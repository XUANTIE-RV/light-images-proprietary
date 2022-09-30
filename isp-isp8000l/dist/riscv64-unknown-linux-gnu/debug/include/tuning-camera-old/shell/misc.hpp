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

struct Misc : Abstract {
  enum {
    Begin = Abstract::Misc * Abstract::Step,

    DeHaze,

    End,

    Step = 100,
  };

  Misc(t_camera::Camera *pCamera) : Abstract(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }
};

} // namespace t_shell
