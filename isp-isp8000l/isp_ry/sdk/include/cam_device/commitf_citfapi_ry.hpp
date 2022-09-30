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

#include "cam_device_api_ry.hpp"
#include "commitf_citf_ry.hpp"
#include "calib_features_ry.hpp"
#include "commitf_features_ry.hpp"
#include "commitf_pipeline_ry.hpp"
#include "commitf_sensor_ry.hpp"
#include "commitf_event_ry.hpp"
#include "cam_operations_ry.hpp"
#include "buf_io_ry.hpp"

using namespace camdev;
#include <vector>

namespace camdev {


class CitfApi {
public:
    CitfApi(int ispID);
    ~CitfApi();

    Citf_Handle ctifHandle;

    static RESULT CitfGetHwResources(Json::Value &jRequest, Json::Value &jResponse);
    static RESULT CitfGetHwStatus(Json::Value &jRequest, Json::Value &jResponse);
    static RESULT CitfGetIspFeature(Json::Value &jRequest, Json::Value &jResponse);
    static RESULT CitfGetFeatureVersion(Json::Value &jRequest, Json::Value &jResponse);
    static RESULT CitfGetVersions(Json::Value &jRequest, Json::Value &jResponse);

    RESULT CitfGetSensorInfo(Json::Value &jRequest, Json::Value &jResopnse);
    RESULT CitfIoctl(int32_t ctrlId, Json::Value &jRequest, Json::Value &jResponse);

    Bitf &CitfCreateBuffItf();
    RESULT CitfDelBuffItf();
    CitfEvent &CitfCreateEvent();
    RESULT CitfDelEvent();

    /*output buffer controls*/
    RESULT CitfInitOutChain(ISPCORE_BUFIO_ID chain, uint8_t skip_interval);
    RESULT CitfDeinitOutChain(ISPCORE_BUFIO_ID chain);

    RESULT CitfStartOutChain(ISPCORE_BUFIO_ID chain);
    RESULT CitfStopOutChain(ISPCORE_BUFIO_ID chain);

    RESULT CitfAttachChain(ISPCORE_BUFIO_ID chain);
    RESULT CitfDetachChain(ISPCORE_BUFIO_ID chain);

    RESULT CitfWaitForBufferEvent(ISPCORE_BUFIO_ID chain, buffCtrlEvent_t * xomCtrlEvent, int timeout);

    RESULT CitfDQBUF(ISPCORE_BUFIO_ID chain, MediaBuffer_t ** pBuf);
    RESULT CitfQBUF(ISPCORE_BUFIO_ID chain, MediaBuffer_t * pBuf);

    RESULT CitfInitBufferPoolCtrl(ISPCORE_BUFIO_ID chain);
    RESULT CitfDeInitBufferPoolCtrl(ISPCORE_BUFIO_ID chain);

    RESULT CitfSetBufferParameters(BUFF_MODE buff_mode);
    RESULT CitfBufferPoolAddEntity(ISPCORE_BUFIO_ID chain, BufIdentity* buf);

    RESULT CitfBufferPoolClearBufList(ISPCORE_BUFIO_ID chain);
    RESULT CitfBufferPoolSetBufToEngine(ISPCORE_BUFIO_ID chain);

    RESULT CitfBufferPoolKernelAddrMap(ISPCORE_BUFIO_ID chain, uint32_t needRemap);
    RESULT CitfBufferPoolGetBufIdList(ISPCORE_BUFIO_ID chain, std::list<BufIdentity *> * poolList);

public:
    std::vector<Citf *> list;
    Bitf * pBitf = nullptr;
    CitfEvent * pEvent = nullptr;

};

} // namespace camdev
