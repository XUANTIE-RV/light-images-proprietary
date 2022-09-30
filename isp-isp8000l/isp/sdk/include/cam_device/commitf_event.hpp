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
#include "exception.hpp"
#include "macros.hpp"
#include <common/return_codes.h>
#include <ebase/trace.h>
#include "cam_device_api.hpp"

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
