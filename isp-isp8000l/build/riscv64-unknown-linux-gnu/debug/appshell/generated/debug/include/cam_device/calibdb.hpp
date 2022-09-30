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

/**
 * @file    calibtreewidget.h
 *
 *
 *****************************************************************************/
#pragma once

#include <cam_calibdb/cam_calibdb_api.h>
#include <string>
#include <tinyxml2/tinyxml2.h>

using namespace tinyxml2;

class CalibDb {
public:
  ~CalibDb();

  CamCalibDbHandle_t GetCalibDbHandle(void) { return (hCalibDb); }

  int32_t install(std::string &);
  int32_t uninstall();

private:
  typedef int32_t (CalibDb::*parseCellContent)(const XMLElement *, void *);

  // parse helper
  int32_t parseEntryCell(const XMLElement *, int32_t, parseCellContent,
                         void * = NULL);

  // parse Header
  int32_t parseEntryHeader(const XMLElement *, void * = NULL);
  int32_t parseEntryResolution(const XMLElement *, void * = NULL);

  // parse Sensor
  int32_t parseEntrySensor(const XMLElement *, void * = NULL);

  // parse Sensor-AWB
  int32_t parseEntryAwb(const XMLElement *, void * = NULL);
  int32_t parseEntryAwbGlobals(const XMLElement *, void * = NULL);
  int32_t parseEntryAwbIllumination(const XMLElement *, void * = NULL);
  int32_t parseEntryAwbIlluminationAlsc(const XMLElement *, void * = NULL);
  int32_t parseEntryAwbIlluminationAcc(const XMLElement *, void * = NULL);

  // parse Sensor-AEC
  int32_t parseEntryAec(const XMLElement *, void * = NULL);
  int32_t parseEntryAecEcm(const XMLElement *, void * = NULL);
  int32_t parseEntryAecEcmPriorityScheme(const XMLElement *, void * = NULL);

  // parse Sensor-LSC
  int32_t parseEntryLsc(const XMLElement *, void * = NULL);

  // parse Sensor-CC
  int32_t parseEntryCc(const XMLElement *, void * = NULL);

  // parse Sensor-BLS
  int32_t parseEntryBls(const XMLElement *, void * = NULL);

  // parse Sensor-CAC
  int32_t parseEntryCac(const XMLElement *, void * = NULL);

  // parse Sensor-DPF
  int32_t parseEntryDpf(const XMLElement *, void * = NULL);

  // parse Sensor-DPCC
  int32_t parseEntryDpcc(const XMLElement *, void * = NULL);
  int32_t parseEntryDpccRegisters(const XMLElement *, void * = NULL);

  int32_t parseEntryHdr(const XMLElement *, void * = NULL);

  // parse System
  int32_t parseEntrySystem(const XMLElement *, void * = NULL);

private:
  CamCalibDbHandle_t hCalibDb = 0;
};
