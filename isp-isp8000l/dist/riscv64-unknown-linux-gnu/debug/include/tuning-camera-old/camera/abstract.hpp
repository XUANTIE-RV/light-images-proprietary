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
#include "halholder.hpp"
#include "image.hpp"
#include "sensor.hpp"
#include "dsp.hpp"
#include "engine_ry.h"

namespace t_camera {

typedef void(AfpsResChangeCb_t)(void const *);

struct Abstract : Object {
  Abstract(clb::Calibration *, AfpsResChangeCb_t *, void const *);
  ~Abstract();

  static int32_t afpsResChangeRequestCb(uint, void const *);

  int32_t deHazeEnableGet(bool &);
  int32_t deHazeEnableSet(bool);

  int32_t ecmSet(bool = false);

  Image &image() {
    return *images[pCalibration->module<clb::Inputs>().config.index];
  }

  int32_t inputConnect();
  int32_t inputDisconnect();
  int32_t inputSwitch(int32_t);

  int32_t pipelineEnableSet(bool);

  int32_t resolutionGet(uint32_t &width, uint32_t &height);
  int32_t resolutionSet(uint32_t width = 0, uint32_t height = 0);

  Sensor &sensor() {
#if defined(CTRL_SENSOR)
    return *sensors[pCalibration->module<clb::Inputs>().config.index];
#else
    throw t_common::LogicError(RET_NOTSUPP, "Sensor not support");
#endif
  };

  int32_t streamingStart(uint frames = 0);
  int32_t streamingStop();

  std::function<int32_t()> fEventSensorDriverChanged;
  std::function<int32_t()> fEventSensorDriverPrechange;

  AfpsResChangeCb_t *pAfpsResChangeCb = nullptr;

  Engine *pEngine = nullptr;
  Dsp *pDsp = nullptr;
  void *pEngineRy = nullptr;

  HalHolder halHolder;

  std::vector<Image *> images;
  std::vector<Sensor *> sensors;

  void const *pUserCbCtx = nullptr;
};

} // namespace t_camera
