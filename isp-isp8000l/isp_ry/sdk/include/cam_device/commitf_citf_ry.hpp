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

#include "cam_operations_ry.hpp"
#include "exception_ry.hpp"
#include "macros_ry.hpp"
#include <base64/base64_ry.hpp>
#include <json/json.h>


#define CITF_CID "cmdId"
#define CITF_MID "moduleId"
#define CITF_RET "result"
#define CITF_MSG "message"
#define ERR_CTRLID "errctrlId"
#define JSON_STR_BUF_LENGTH 64

#ifdef TRACE_CMD
#undef TRACE_CMD
#endif

#define TRACE_CMD TRACE(CITF_INF, " %s\n", __PRETTY_FUNCTION__)
USE_TRACER(CITF_INF);
USE_TRACER(CITF_ERR);
namespace camdev {

struct Citf_Handle{
    HalHolder *pHalHolder = nullptr;
    Calibration *pCalibration = nullptr;
    Operation *pOperation = nullptr;
};


class Citf {
public:
    Citf(Citf_Handle * pCitfHandle_in);
    virtual ~Citf();

public:
    Citf_Handle * pCitfHandle = nullptr;

    template <typename T> RESULT binDecode(Json::Value &jValue, T &object) {
        uint32_t sizeT = sizeof(T);
        uint32_t size = jValue["base64.size"].asUInt();

        if (sizeT != size) {
            std::string message("T size(%d) != size(%d)", sizeT, size);
            throw exc::LogicError(RET_INVALID_PARM, message.c_str());
            return RET_INVALID_PARM;
        }

        std::string decodedString = base64_decode(jValue["base64.bin"].asString());
        std::copy(decodedString.begin(), decodedString.end(), (char *)&object);

        return RET_SUCCESS;
    }

    template <typename T> RESULT binEncode(T &object, Json::Value &jValue) {
        uint32_t size = sizeof(T);

        jValue["base64.size"] = size;
        jValue["base64.bin"] = base64_encode((u_char *)&object, size);

        return RET_SUCCESS;
    }

    virtual RESULT process( int ctrlId, Json::Value &jRequest, Json::Value &jResponse);
    virtual RESULT getModuleVersion(Json::Value &jRequest, Json::Value &jResponse);

    RESULT setSubId(int32_t inputId_Begin, int32_t inputId_End);
    RESULT checkIsSubId(int32_t inputId);

    camdev::SensorOps &sensor();

public:
    int32_t subId_Begin;
    int32_t subId_End;

    int32_t idBegin;
    int32_t idEnd;
};

} // namespace camdev
