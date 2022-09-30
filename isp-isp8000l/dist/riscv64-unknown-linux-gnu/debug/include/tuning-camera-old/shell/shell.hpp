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
#include "ae.hpp"
#include "af.hpp"
#include "ahdr.hpp"
#include "avs.hpp"
#include "awb.hpp"
#include "bls.hpp"
#include "ca.hpp"
#include "cac.hpp"
#include "camera.hpp"
#include "cli.hpp"
#include "cnr.hpp"
#include "cproc.hpp"
#include "dci.hpp"
#include "dehaze.hpp"
#include "demosaic.hpp"
#include "dewarp.hpp"
#include "dg.hpp"
#include "dnr2.hpp"
#include "dnr3.hpp"
#include "dpcc.hpp"
#include "dpf.hpp"
#include "ee.hpp"
#include "engine.hpp"
#include "filter.hpp"
#include "fs.hpp"
#include "gc.hpp"
#include "ge.hpp"
#include "hdr.hpp"
#include "ie.hpp"
#include "image.hpp"
#include "lsc.hpp"
#include "misc.hpp"
#include "reg.hpp"
#include "sensor.hpp"
#include "simp.hpp"
#include "wb.hpp"
#include "wdr.hpp"

namespace t_shell {

struct Shell {
  Shell(t_camera::Camera *pCamera);

  Shell &process(Json::Value const &jQuery, Json::Value &jResponse);

  std::list<Abstract *> list;
};

} // namespace t_shell
