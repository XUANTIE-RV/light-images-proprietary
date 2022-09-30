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

#include <cam_calibdb/cam_calibdb_api.h>
#include <string>
#include <tinyxml2.h>

using namespace tinyxml2;

struct CalibDb {
  CalibDb(void *pParent = nullptr);
  ~CalibDb();

  CamCalibDbHandle_t GetCalibDbHandle(void) { return (hCalibDb); }

  int32_t install(std::string);
  int32_t install(XMLDocument &);
  int32_t uninstall();

  bool isValid() { return hCalibDb != 0; }

  typedef int32_t (CalibDb::*parseCellContent)(XMLElement const *, void *);

  // parse helper
  int32_t parseEntryCell(XMLElement const *, int32_t, parseCellContent,
                         void * = NULL);

  // parse Header
  int32_t parseEntryHeader(XMLElement const *, void * = NULL);
  int32_t parseEntryResolution(XMLElement const *, void * = NULL);

  // parse Sensor
  int32_t parseEntrySensor(XMLElement const *, void * = NULL);

  // parse Sensor-AWB
  int32_t parseEntryAwb(XMLElement const *, void * = NULL);
  int32_t parseEntryAwbGlobals(XMLElement const *, void * = NULL);
  int32_t parseEntryAwbIllumination(XMLElement const *, void * = NULL);
  int32_t parseEntryAwbIlluminationAlsc(XMLElement const *, void * = NULL);
  int32_t parseEntryAwbIlluminationAcc(XMLElement const *, void * = NULL);

  // parse Sensor-AEC
  int32_t parseEntryAec(XMLElement const *, void * = NULL);
  int32_t parseEntryAecEcm(XMLElement const *, void * = NULL);
  int32_t parseEntryAecEcmPriorityScheme(XMLElement const *, void * = NULL);

  // parse Sensor-LSC
  int32_t parseEntryLsc(XMLElement const *, void * = NULL);

  // parse Sensor-CC
  int32_t parseEntryCc(XMLElement const *, void * = NULL);

  // parse Sensor-BLS
  int32_t parseEntryBls(XMLElement const *, void * = NULL);

  // parse Sensor-CAC
  int32_t parseEntryCac(XMLElement const *, void * = NULL);

  // parse Sensor-DPF
  int32_t parseEntryDpf(XMLElement const *, void * = NULL);

  // parse Sensor-DPCC
  int32_t parseEntryDpcc(XMLElement const *, void * = NULL);
  int32_t parseEntryDpccRegisters(XMLElement const *, void * = NULL);

  int32_t parseEntryHdr(XMLElement const *, void * = NULL);

  // parse System
  int32_t parseEntrySystem(XMLElement const *, void * = NULL);

  CamCalibDbHandle_t hCalibDb = 0;

  void *pParent = nullptr;
};
