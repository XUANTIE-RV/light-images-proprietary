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

#include "commitf_citf_ry.hpp"

namespace camdev {

class CitfPipeline : public Citf {
public:
    CitfPipeline(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input) {
        subId_Begin = ISPCORE_MODULE_PIPELINE_BEGIN;
        subId_End = ISPCORE_MODULE_PIPELINE_END;
    }

    RESULT process( int ctrlId, Json::Value &jRequest, Json::Value &jResponse) override;

    RESULT warmUp(Json::Value &jRequest, Json::Value &jResponse);
};

} // namespace camdev
