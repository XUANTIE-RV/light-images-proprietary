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
#include "exception_ry.hpp"
#include "macros_ry.hpp"
#include <common/return_codes_ry.h>
#include <ebase/trace_ry.h>
#include "cam_device_api_ry.hpp"

namespace camdev {

class CitfEvent {
public:
    CitfEvent();
    ~CitfEvent();
    RESULT citfUsrEventCbRegister(CITFEventCallback eventCb, void* pContext);
    RESULT citfUsrEventCbDeregister(void);
    void * pCtifApi = nullptr;
 };

}  // namespace camdev
