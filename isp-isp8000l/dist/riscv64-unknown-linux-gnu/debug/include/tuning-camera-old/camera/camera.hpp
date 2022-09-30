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

#if defined(CTRL_DEWARP)
#include "control/dewarp.hpp"
#endif // CTRL_DEWARP

#if defined(CTRL_DOM)
#include "control/dom.hpp"
#endif // CTRL_DOM

#if defined(CTRL_DRM)
#include "drm/drm.hpp"
#endif // CTRL_DRM

#if defined(CTRL_EXA)
#include "control/exa.hpp"
#endif // CTRL_EXA

#include "control/som.hpp"

#if defined(CTRL_VOM)
#include "control/vom.hpp"
#endif // CTRL_VOM

namespace t_camera {

struct Camera : Abstract, t_common::Version {
  Camera(clb::Calibration *, AfpsResChangeCb_t * = nullptr, void * = nullptr);
  virtual ~Camera();

  static void bufferCb(CamEnginePathType_t path, MediaBuffer_t *pMediaBuffer,
                       void *pCtx);

  int32_t capture(std::string fileName, clb::Camera::SnapshotType snapshotType,
                  CamEngineLockType_t lockType = CAM_ENGINE_LOCK_ALL);

#if defined(CTRL_DEWARP)
  dwp::Dewarp &dewarp();
#endif

#if defined(CTRL_EXA)
  int32_t externalAlgorithmEnable(bool_t = BOOL_TRUE);
  int32_t externalAlgorithmRegister(exaCtrlSampleCb_t, void *, uint8_t);
#endif

  int32_t pipelineConnect(ItfBufferCb * = nullptr);
  int32_t pipelineDisconnect();

  int32_t previewStart();
  int32_t previewStop();

  int32_t reset();

  void versionGet(std::string &name, std::string &number,
                  std::string &time) override;

  // friend class PfidItf;

#if defined(CTRL_DEWARP)
  dwp::Dewarp *pDewarp = nullptr;
#endif

#if defined(CTRL_DOM)
  Dom *pDom = nullptr;
#endif // CTRL_DOM

#if defined(CTRL_DRM)
  Drm *pDrm = nullptr;
#endif // CTRL_DRM

#if defined(CTRL_EXA)
  Exa *pExa = nullptr;
  exaCtrlSampleCb_t exaCtrlSampleCb = nullptr;
#endif

  Som *pSom = nullptr;

#if defined(CTRL_VOM)
  Vom *pVom = nullptr;
#endif

  struct BufferCbContext {
    std::list<ItfBufferCb *> mainPath;
    std::list<ItfBufferCb *> selfPath;
  };

  BufferCbContext *pBufferCbContext = nullptr;

  void *pSampleCbContext = nullptr;
  uint8_t sampleSkip = 0;
};

} // namespace t_camera
