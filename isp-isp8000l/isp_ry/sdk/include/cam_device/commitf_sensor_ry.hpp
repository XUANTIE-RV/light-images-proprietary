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

class CitfSensor : public Citf {
public:
    CitfSensor(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input) {
        subId_Begin = ISPCORE_MODULE_SENSOR_BEGIN;
        subId_End = ISPCORE_MODULE_SENSOR_END;
    }

    RESULT process( int ctrlId, Json::Value &jRequest, Json::Value &jResponse) override;

    RESULT caps(Json::Value &jRequest, Json::Value &jResponse);
    RESULT configGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT configSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT nameGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT revisionGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT sensorOpen(Json::Value &jRequest, Json::Value &jResponse);
    RESULT isConnected(Json::Value &jRequest, Json::Value &jResponse);
    RESULT isTestPattern(Json::Value &jRequest, Json::Value &jResponse);
    RESULT driverChange(Json::Value &jRequest, Json::Value &jResponse);
    RESULT driverList(Json::Value &jRequest, Json::Value &jResponse);
    RESULT info(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resolutionListGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT isiGetResolutionName(Json::Value &jRequest, Json::Value &jResponse);
    RESULT registerDescription(Json::Value &jRequest, Json::Value &jResponse);
    RESULT registerDump2File(Json::Value &jRequest, Json::Value &jResponse);
    RESULT registerGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT registerSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT registerTable(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resolutionSetSensor(Json::Value &jRequest, Json::Value &jResponse);
    RESULT testPatternEnableSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resolutionSupportListGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT frameRateGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT frameRateSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT modeGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT modeSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resWGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resHGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT queryCaps(Json::Value &jRequest, Json::Value &jResponse);
    RESULT setCapsMode(Json::Value &jRequest, Json::Value &jResponse);
    RESULT setCapsModeLock(Json::Value &jRequest, Json::Value &jResponse);
};

} // namespace camdev
