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

#include "common/interface.hpp"

#include <isi/isi_iss.h>
#include <hal/hal_api.h>

namespace t_camera {

struct Sensor : Object {
  Sensor(clb::Calibration *pCalibration, HalHandle_t hHal, int32_t = 0);
  ~Sensor();

  struct cam_compand_curve{
        bool     enable;
        uint8_t  in_bit;
        uint8_t  out_bit;
        uint8_t  px[64];
        uint32_t x_data[65];
        uint32_t y_data[65];
    };
  int32_t configGet(clb::Sensor::Config &);
  int32_t configSet(clb::Sensor::Config const &);

  Sensor &checkValid();

  int32_t close();

  int32_t driverChange(std::string const &driverFileName,
                       bool isBlockSignal = false);

  int32_t open();

  int32_t renewHalHandle(std::string const &sensorName);

  int32_t registerDump2File(std::string &);

  int32_t registerRead(uint32_t, uint32_t &);
  int32_t registerWrite(uint32_t, uint32_t);

  int32_t statusGet(clb::Sensor::Status &);

  int32_t streamEnableSet(bool);

  std::function<int32_t(std::string const &)> fEventDriverChanged;
  std::function<int32_t(std::string const &)> fEventDriverPrechange;

  IsiSensorConfig_t isiSensorConfig;

  HalHandle_t hHal = 0;

  IsiSensorHandle_t hIsiSensor = 0;

  int32_t index = 0;

  IsiCamDrvConfig_t *pIsiCamDrvConfig = nullptr;
  void *pLib = nullptr;
  const IsiRegDescription_t *pIsiRegisterTable = nullptr;
  const IsiSensor_t *pIsiSensor = nullptr;
  const IsiSensorCaps_t *pIsiSensorCaps = nullptr;

  uint32_t hdrMode = 0;
  uint32_t hdrStitchMode = 0;
  struct cam_compand_curve expand_curve;
};

} // namespace t_camera
