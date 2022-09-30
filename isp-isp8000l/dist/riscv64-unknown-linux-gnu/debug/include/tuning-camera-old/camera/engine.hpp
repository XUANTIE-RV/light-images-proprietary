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

#include "image.hpp"
#include "sensor.hpp"

#include <cam_engine/cam_engine_api.h>

#include <cam_engine/cam_engine_aaa_api.h>
#include <cam_engine/cam_engine_cproc_api.h>
#include <cam_engine/cam_engine_imgeffects_api.h>
#include <cam_engine/cam_engine_isp_api.h>
#include <cam_engine/cam_engine_jpe_api.h>
#include <cam_engine/cam_engine_mi_api.h>
#include <cam_engine/cam_engine_simp_api.h>
#include <cameric_reg_drv/cameric_reg_description.h>

namespace t_camera {

struct Engine : Object {
  Engine(clb::Calibration *pCalibration, HalHandle_t hHal);
  ~Engine();

  int32_t aeConfigGet(clb::Ae::Config &, clb::Ae::Generation);
  int32_t aeConfigSet(clb::Ae::Config const &, clb::Ae::Generation);
  int32_t aeEnableGet(bool &, clb::Ae::Generation);
  int32_t aeEnableSet(bool, clb::Ae::Generation);
  int32_t aeReset(clb::Ae::Generation);
  int32_t aeStatusGet(clb::Ae::Status &, clb::Ae::Generation);

  int32_t afAvailableGet(bool &);
  int32_t afConfigGet(clb::Af::Config &);
  int32_t afConfigSet(clb::Af::Config const &);
  int32_t afEnableGet(bool &);
  int32_t afEnableSet(bool);

  int32_t ahdrConfigGet(clb::Ahdr::Config &, clb::Ahdr::Generation);
  int32_t ahdrConfigSet(clb::Ahdr::Config const &, clb::Ahdr::Generation);
  int32_t ahdrEnableGet(bool &, clb::Ahdr::Generation);
  int32_t ahdrEnableSet(bool, clb::Ahdr::Generation);
  int32_t ahdrReset(clb::Ahdr::Generation);
  int32_t ahdrTableGet(Json::Value &, clb::Ahdr::Generation);
  int32_t ahdrTableSet(Json::Value const &, clb::Ahdr::Generation);

  static void afpsResChangeCb(uint32_t, void const *);
  static int32_t entryAfpsResChange(void *);
  typedef int32_t(AfpsResChangeRequestCb_t)(uint32_t, void const *);

  int32_t avsConfigGet(clb::Avs::Config &);
  int32_t avsConfigSet(clb::Avs::Config const &);
  int32_t avsEnableGet(bool &);
  int32_t avsEnableSet(bool);
  int32_t avsStatusGet(clb::Avs::Status &);

  int32_t awbConfigGet(clb::Awb::Config &);
  int32_t awbConfigSet(clb::Awb::Config const &);
  int32_t awbEnableGet(bool &);
  int32_t awbEnableSet(bool);
  int32_t awbReset();
  int32_t awbStatusGet(clb::Awb::Status &);

  int32_t blsConfigGet(clb::Bls::Config &);
  int32_t blsConfigSet(clb::Bls::Config const &);

  int32_t bufferCbRegister(CamEngineBufferCb_t, void *);
  int32_t bufferCbUnregister();
  int32_t bufferCbGet(CamEngineBufferCb_t *, void **);

  int32_t caConfigGet(clb::Ca::Config &);
  int32_t caConfigSet(clb::Ca::Config const &);
  int32_t caEnableGet(bool &);
  int32_t caEnableSet(bool);
  int32_t caTableGet(Json::Value &);
  int32_t caTableSet(Json::Value const &);

  int32_t cacEnableGet(bool &);
  int32_t cacEnableSet(bool);
  int32_t cacStatusGet(clb::Cac::Status &);

  static void cbCompletion(CamEngineCmdId_t, int32_t, void const *);

  int32_t cnrConfigGet(clb::Cnr::Config &);
  int32_t cnrConfigSet(clb::Cnr::Config const &);
  int32_t cnrEnableGet(bool &);
  int32_t cnrEnableSet(bool);

  int32_t cprocConfigGet(clb::Cproc::Config &);
  int32_t cprocConfigSet(clb::Cproc::Config const &);
  int32_t cprocEnableGet(bool &);
  int32_t cprocEnableSet(bool);

  int32_t dciConfigGet(clb::Dci::Config &);
  int32_t dciConfigSet(clb::Dci::Config const &);
  int32_t dciEnableGet(bool &);
  int32_t dciEnableSet(bool);
  int32_t dciTableGet(Json::Value &);
  int32_t dciTableSet(Json::Value const &);

  int32_t deMosaicConfigGet(clb::DeMosaic::Config &, clb::DeMosaic::Generation);
  int32_t deMosaicConfigSet(clb::DeMosaic::Config const &,
                            clb::DeMosaic::Generation);
  int32_t deMosaicEnableGet(bool &, clb::DeMosaic::Generation);
  int32_t deMosaicEnableSet(bool, clb::DeMosaic::Generation);
  int32_t deMosaicReset(clb::DeMosaic::Generation);
  int32_t deMosaicEnableUpdate(bool isEnable, clb::DeMosaic::Generation generation);

  int32_t dgConfigGet(clb::Dg::Config &);
  int32_t dgConfigSet(clb::Dg::Config const &);
  int32_t dgEnableGet(bool &);
  int32_t dgEnableSet(bool);

  int32_t dnr2ConfigGet(clb::Dnr2::Config &, clb::Dnr2::Generation);
  int32_t dnr2ConfigSet(clb::Dnr2::Config const &, clb::Dnr2::Generation);
  int32_t dnr2EnableGet(bool &, clb::Dnr2::Generation);
  int32_t dnr2EnableSet(bool, clb::Dnr2::Generation);
  int32_t dnr2Reset(clb::Dnr2::Generation);
  int32_t dnr2StatusGet(clb::Dnr2::Status &, clb::Dnr2::Generation);
  int32_t dnr2TableGet(Json::Value &, clb::Dnr2::Generation);
  int32_t dnr2TableSet(Json::Value const &, clb::Dnr2::Generation);

  int32_t dnr3ConfigGet(clb::Dnr3::Config &, clb::Dnr3::Generation);
  int32_t dnr3ConfigSet(clb::Dnr3::Config const &, clb::Dnr3::Generation);
  int32_t dnr3EnableGet(bool &, clb::Dnr3::Generation);
  int32_t dnr3EnableSet(bool, clb::Dnr3::Generation);
  int32_t dnr3Reset(clb::Dnr3::Generation);
  int32_t dnr3StatusGet(clb::Dnr3::Status &, clb::Dnr3::Generation);
  int32_t dnr3TableGet(Json::Value &, clb::Dnr3::Generation);
  int32_t dnr3TableSet(Json::Value const &, clb::Dnr3::Generation);

  int32_t dpccEnableGet(bool &);
  int32_t dpccEnableSet(bool);

  int32_t dpfConfigGet(clb::Dpf::Config &);
  int32_t dpfConfigSet(clb::Dpf::Config const &);
  int32_t dpfEnableGet(bool &);
  int32_t dpfEnableSet(bool);

  int32_t eeConfigGet(clb::Ee::Config &);
  int32_t eeConfigSet(clb::Ee::Config const &);
  int32_t eeEnableGet(bool &);
  int32_t eeEnableSet(bool);
  int32_t eeReset();
  int32_t eeStatusGet(clb::Ee::Status &);
  int32_t eeTableGet(Json::Value &);
  int32_t eeTableSet(Json::Value const &);

  int32_t filterConfigGet(clb::Filter::Config &);
  int32_t filterConfigSet(clb::Filter::Config const &);
  int32_t filterEnableGet(bool &);
  int32_t filterEnableSet(bool);
  int32_t filterStatusGet(clb::Filter::Status &);
  int32_t filterTableGet(Json::Value &);
  int32_t filterTableSet(Json::Value const &);

  int32_t gcConfigGet(clb::Gc::Config &, clb::Gc::Generation);
  int32_t gcConfigSet(clb::Gc::Config const &, clb::Gc::Generation);
  int32_t gcEnableGet(bool &, clb::Gc::Generation);
  int32_t gcEnableSet(bool, clb::Gc::Generation);

  int32_t geConfigGet(clb::Ge::Config &);
  int32_t geConfigSet(clb::Ge::Config const &);
  int32_t geEnableGet(bool &);
  int32_t geEnableSet(bool);

  int32_t hdrConfigGet(clb::Hdr::Config &, clb::Hdr::Generation);
  int32_t hdrConfigSet(clb::Hdr::Config const &, clb::Hdr::Generation);
  int32_t hdrEnableGet(bool &, clb::Hdr::Generation);
  int32_t hdrEnableSet(bool, clb::Hdr::Generation);
  int32_t hdrReset(clb::Hdr::Generation);
  int32_t hdrStatusGet(clb::Hdr::Status &, clb::Hdr::Generation);

  int32_t ieConfigGet(clb::Ie::Config &);
  int32_t ieConfigSet(clb::Ie::Config const &);
  int32_t ieEnableGet(bool &);
  int32_t ieEnableSet(bool);

  int32_t lscConfigGet(clb::Lsc::Config &);
  int32_t lscConfigSet(clb::Lsc::Config const &);
  int32_t lscEnableGet(bool &);
  int32_t lscEnableSet(bool);
  int32_t lscStatusGet(clb::Lsc::Status &);

  int32_t pathConfigGet(clb::Path::Config &);
  int32_t pathConfigSet(clb::Path::Config const &);

  int32_t pictureOrientationSet(CamerIcMiOrientation_t);

  int32_t resolutionSet(CamEngineWindow_t, CamEngineWindow_t, CamEngineWindow_t,
                        uint32_t = 0);

  int32_t searchAndLock(CamEngineLockType_t);

  int32_t simpConfigGet(clb::Simp::Config &);
  int32_t simpConfigSet(clb::Simp::Config const &);
  int32_t simpEnableGet(bool &);
  int32_t simpEnableSet(bool);

  int32_t start(CamEngineConfig_t::CamEngineConfigData_u const &configData);
  int32_t stop();

  int32_t streamingStart(uint32_t = 0);
  int32_t streamingStop();

  int32_t unlock(CamEngineLockType_t);

  int32_t wbConfigGet(clb::Wb::Config &);
  int32_t wbConfigSet(clb::Wb::Config const &);

  int32_t wdrConfigGet(clb::Wdr::Config &, clb::Wdr::Generation);
  int32_t wdrConfigSet(clb::Wdr::Config const &, clb::Wdr::Generation);
  int32_t wdrEnableGet(bool &, clb::Wdr::Generation);
  int32_t wdrEnableSet(bool, clb::Wdr::Generation);
  int32_t wdrReset(clb::Wdr::Generation);
  int32_t wdrStatusGet(clb::Wdr::Status &, clb::Wdr::Generation);
  int32_t wdrTableGet(Json::Value &, clb::Wdr::Generation);
  int32_t wdrTableSet(Json::Value const &, clb::Wdr::Generation);

  CamEngineBlackLevel_t blackLevel;

  CamEngineCcMatrix_t ccMatrix;
  CamEngineCcOffset_t ccOffset;

  osEvent eventStart;
  osEvent eventStop;
  osEvent eventStartStreaming;
  osEvent eventStopStreaming;
  osEvent eventAcquireLock;
  osEvent eventReleaseLock;

  CamerIcDrvContext_t hCamerIcReg;

  CamEngineHandle_t hCamEngine;

  AfpsResChangeRequestCb_t *pAfpsResChangeRequestCb = NULL;

  void const *pUserCbCtx = NULL;
  osQueue queueAfpsResChange;

  CamEngineWbGains_t wbGains;

  Image *pSimpImage = NULL;

  osThread threadAfpsResChange;

  pp_write_line_entry_t pp_write_line_entry;
};
} // namespace t_camera
