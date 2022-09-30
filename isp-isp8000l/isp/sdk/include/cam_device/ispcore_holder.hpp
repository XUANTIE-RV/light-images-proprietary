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
#include "cam_common.hpp"

#include "cam_device_api.hpp"
#include "commitf_citfapi.hpp"


namespace camdev {

class Ispcore_Holder {
    struct IspCoreCtx {
        CitfApi * ctx;
        CAM_DEVICE * handle;
    };

public:
    static Ispcore_Holder * getInstance() {
        static Ispcore_Holder instance;
        return &instance;
    }

    IspCoreCtx ispcore[CAM_ISPCORE_ID_MAX];

protected:
    struct Inst_Creator {
        Inst_Creator() {
            Ispcore_Holder::getInstance();
        }
    };

    static Inst_Creator inst_creator;

    Ispcore_Holder();
    ~Ispcore_Holder();
};

}  // namespace camdev



