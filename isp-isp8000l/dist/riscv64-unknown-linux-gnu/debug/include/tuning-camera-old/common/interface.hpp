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

#include <tuning-camera-old-config.hpp>

#include <tuning-common/common.hpp>

#include "calibration/calibration.hpp"
#include "common/tracer.hpp"
#include <algorithm>
#include <bufferpool/media_buffer.h>
#include <common/return_codes.h>
#include <ebase/dct_assert.h>
#include <iostream>
#include <list>
#include <oslayer/oslayer.h>
#include <string>
#include <vector>
#include <csi_frame.h>
#include <csi_camera.h>

struct Object {
  std::string stateDescription();

  enum State { Invalid, Init, Idle, Running };

  State state = Invalid;

  clb::Calibration *pCalibration = nullptr;
};

struct Ctrl : Object {
  Ctrl();
  virtual ~Ctrl();

  virtual int32_t start(void *) = 0;
  virtual int32_t stop() = 0;

  osEvent eventStarted;
  osEvent eventStopped;
};

struct ItfBufferCb {
  virtual void bufferCb(MediaBuffer_t *) = 0;
};

typedef enum {
	CAM_I420,	    //same as csi_pixel_fmt_e
	CAM_NV12,
	CAM_BGR,
    CAM_RAW8 = 10,  //camera hal private
    CAM_RAW10,      //16bit 瀵归綈
    CAM_RAW12,      //16bit 瀵归綈
} cam_fmt_e;

typedef struct {
    int h_pixel;
    int v_pixel;
    int bayer_mode;
    cam_fmt_e fmt;
    csi_pixel_fmt_e pix_fmt;
} cam_img_param_t;