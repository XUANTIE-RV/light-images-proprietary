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
#include "filter.hpp"
#include "gc.hpp"
#include "ge.hpp"
#include "hdr.hpp"
#include "ie.hpp"
#include "image.hpp"
#include "input.hpp"
#include "lsc.hpp"
#include "path.hpp"
#include "reg.hpp"
#include "sensor.hpp"
#include "simp.hpp"
#include "wb.hpp"
#include "wdr.hpp"

#include "calibdb/calibdb.hpp"

#include <functional>

namespace clb {

struct Calibration {
  Calibration();
  ~Calibration();

  bool isConnectable();

  int32_t load(std::string const &fileName, bool isBlockSignal = false);
  int32_t save(std::string const &fileName, bool isBlockSignal = false);

  template <typename T> T &module() {
    return dynamic_cast<T &>(
        **std::find_if(list.begin(), list.end(), [&](Abstract *pAbstract) {
          if (dynamic_cast<T *>(pAbstract)) {
            return true;
          } else {
            return false;
          }
        }));
  }

  std::function<int32_t(std::string const &fileName)> fEventPreload;
  std::function<int32_t(std::string const &fileName)> fEventLoaded;
  std::function<int32_t(std::string const &fileName)> fEventSaved;

  CalibDb dbLegacy;

  std::list<clb::Abstract *> list;

  tinyxml2::XMLDocument &document =
      *new tinyxml2::XMLDocument(true, COLLAPSE_WHITESPACE);

  bool isReadOnly = false;
};

} // namespace clb
