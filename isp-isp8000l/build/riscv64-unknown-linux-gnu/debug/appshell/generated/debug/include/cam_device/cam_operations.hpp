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
#include "cam_engine_interface.hpp"
#include "cam_sensor.hpp"
#include <vector>
#include "buf_io.hpp"
#include <cam_engine/cam_engine_api.h>
#include <string>

#include <deque>
#include <mutex>

namespace camdev {

typedef void(AfpsResChangeCb_t)(const void *);
const int CAM_METADATA_CHANNEL = 3;
const int CAM_METADATA_NUMBER = 1;

struct Operation : CamStatus {
    Operation(Operation_Handle * pOperationHandle_in);
    ~Operation();

  enum SnapshotType { RGB, RAW8, RAW12, JPEG, RAW10 };

    static int32_t afpsResChangeRequestCb(uint16_t, uint16_t, const void *);

    uint bitstreamId() const;

    int32_t bufferMap(const MediaBuffer_t *, PicBufMetaData_t *);
    int32_t bufferUnmap(PicBufMetaData_t *);

    uint camerIcId() const;

  int32_t dehazeEnableGet(bool &);
  int32_t dehazeEnableSet(bool);

    int32_t ecmSet(bool = false);

    Image &image() {
        return *images[pOperationHandle->pCalibration->module<camdev::CalibInputs>().config.index];
    }

    int32_t inputConnect();
    int32_t inputDisconnect();
    int32_t inputSwitch(int32_t);

    int32_t reset();

    int32_t resolutionGet(uint16_t &, uint16_t &);
    int32_t resolutionSet(uint16_t , uint16_t );

    SensorOps &sensor() {
        return *sensors[pOperationHandle->pCalibration->module<camdev::CalibInputs>().config.index];
    };

  std::string softwareVersion() const;

    int32_t streamingStart(uint frames = 0);
    int32_t streamingStop();

    std::vector<Image *> images;
    std::vector<SensorOps *> sensors;

    AfpsResChangeCb_t *pAfpsResChangeCb = nullptr;

    Engine *pEngine = nullptr;

    const void *pUserCbCtx = nullptr;

    // device operations
    static void bufferCb(CamEnginePathType_t path, MediaBuffer_t *pMediaBuffer, void *pCtx);

    typedef struct ConnectInfo {
        int width, height, format, fps, hdr;
        ConnectInfo& operator=(const ConnectInfo& ri) {
            width = ri.width;
            height = ri.height;
            format = ri.format;
            hdr = ri.hdr;
			fps    = ri.fps;
            return *this;
        }
    } ConnectInfo;

    int32_t cameraConnect(bool preview, ItfBufferCb * bufferCb, const ConnectInfo& connectInfo);
    int32_t cameraDisconnect();
    int32_t cameraReset();

    int32_t captureDma(std::string, CAMDEV_SnapshotType);
    int32_t captureSensor(std::string, CAMDEV_SnapshotType, uint32_t, CamEngineLockType_t = CAM_ENGINE_LOCK_ALL);

    int32_t previewStart();
    int32_t previewStop();

    int32_t streamingStandby(bool enable);

    // friend class PfidItf;

    struct BufferCbContext {
        std::list<ItfBufferCb *> mainPath;
        std::list<ItfBufferCb *> selfPath1;
        std::list<ItfBufferCb *> selfPath2;
        std::list<ItfBufferCb *> rdiPath;
        std::list<ItfBufferCb *> metaPath;
    };

    BufferCbContext *pBufferCbContext = nullptr;
    Operation_Handle * pOperationHandle = nullptr;

    void *pSampleCbContext = nullptr;
    uint8_t sampleSkip = 0;

    int miMode, miLayout, miAlign;
    ConnectInfo mConnectInfo;

    int updateMetadata(CamEnginePathType_t path);
    struct isp_metadata* getMetadata(int path);
    void freeMetadata(struct isp_metadata* meta, int path);
    std::list<isp_metadata *> mMetaList[CAM_METADATA_CHANNEL]; // main, self, self2
    std::mutex mMetaLock;
    bool bStandby = false;
};

}
