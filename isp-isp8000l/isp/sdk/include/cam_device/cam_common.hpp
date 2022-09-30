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

#pragma once

#include "cam_device_api.hpp"
#include <common/return_codes.h>
#include <oslayer/oslayer.h>
#include <string>


#include <sys/stat.h>
#include <ebase/trace.h>
#include <hal/hal_api.h>

namespace fs {

inline bool isExists(const std::string &name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

}

USE_TRACER(CITF_INF);
USE_TRACER(CITF_WAN);
USE_TRACER(CITF_ERR);
#define TRACE_IN TRACE(CITF_INF, "%s (enter)\n", __PRETTY_FUNCTION__)
#define TRACE_OUT TRACE(CITF_INF, "%s (exit)\n", __PRETTY_FUNCTION__)


#define ISP_MAX 2
#define ISP_INPUT_MAX 4

#define CTRL_2DNR
#define CTRL_3DNR1
#define CTRL_AVS
#define CTRL_CAC
#define CTRL_CNR
#define CTRL_DEMOSAIC
#define CTRL_EE
#define CTRL_GC
#define CTRL_HDR
#define CTRL_LSC
#define CTRL_SI
#define CTRL_WDR2
#define CTRL_WDR3
#define CTRL_WDR4

/* BufferCallback functions */
struct ItfBufferCb {
    virtual void bufferCb(MediaBuffer_t *) = 0;
};


struct Ctrl : CamStatus {
    Ctrl();
    virtual ~Ctrl();

    virtual int32_t start(void *) = 0;
    virtual int32_t stop() = 0;

    osEvent eventStarted;
    osEvent eventStopped;
};


class HalHolder {
public:
    HalHolder(int ispID);
    ~HalHolder();

public:
    HalHandle_t hHal = NULL;
#ifdef USE_3AV2
    int index;
#endif
};

