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

#ifndef _CAMERA_DEVICE_API_HPP_
#define _CAMERA_DEVICE_API_HPP_

#include <json/json.h>
#include "cam_device_buf_defs.h"
#include "cam_device_sensor_defs.h"
#include "cam_device_ispcore_defs.h"
#include "cam_device_metadata.h"
#include "cam_device_module_ids.h"
#include "base64.hpp"
#include <list>

#include "json_helper.h"


// Interface class definitions
#define RET_OK 0


enum CAMDEV_SnapshotType { CAMDEV_RGB=0, CAMDEV_RAW8, CAMDEV_RAW12, CAMDEV_JPEG, CAMDEV_RAW10 };

// Event related operations
struct EventContext {
    int FrameID = 0;
};

enum CITF_EVENT {
    CITF_EVENT_FRAME_DONE,
};

typedef int (* CITFEventCallback)
(
    CITF_EVENT   citf_event_id,
    void         *pContext,   //!< Opaque sample data pointer that was passed in on xom control creation.
    EventContext event_ctx
);


typedef enum buffCtrl_event_e {
    BUFF_CTRL_CMD_START          = 0,
    BUFF_CTRL_CMD_STOP           = 1,
    // Output chain Event
    BUFF_CTRL_CMD_BUFFER_BYPASS  = 2,
    BUFF_CTRL_CMD_BUFFER_READY   = 3,
    BUFF_CTRL_CMD_MAX            = 4,
} BuffCtrlEventID_t;

typedef struct buffCtrlEvent_s {
      BuffCtrlEventID_t eventID;   //!< The command to execute.
      unsigned int buffer_id;
      unsigned int buffer_skip_cnt;
} buffCtrlEvent_t;

struct CamStatus {
    enum State { Invalid, Init, Idle, Running };
    State state = Invalid;
};

static inline void readValueFromBase64(const Json::Value& node, const char* section, void* ret) {
    Json::Value base64bin = node[section];
    std::string cfg_parms = base64bin[BASE64_BIN].asString();
    std::string decodedString = base64_decode(cfg_parms);
    std::copy(decodedString.begin(), decodedString.end(), (unsigned char *)ret);
}

class CAM_DEVICE {
public:
    static int getHwResources(Json::Value &jRequest, Json::Value &jResponse);
    static int getHwStatus(Json::Value &jRequest, Json::Value &jResponse);
    static int getIspFeature(Json::Value &jRequest, Json::Value &jResponse);
    static int getFeatureVersion(Json::Value &jRequest, Json::Value &jResponse);
    static int getVersions(Json::Value &jRequest, Json::Value &jResponse);

    /*
     * ISP control cmds operatiuon guide:
     * query getHwResources
     * check getHwStatus
     * initHardware(CAM_DEVICE_ID ..)
     * prepare buffer, bitfSetBufferPoolCtrl for path.

     * ioctl(ISPCORE_MODULE_DEVICE_CALIBRATIONLOAD..)
     * ioctl(ISPCORE_MODULE_DEVICE_INITENGINEOPERATION..)
     * ioctl(ISPCORE_MODULE_SENSOR_CAPS..)
     * ioctl(ISPCORE_MODULE_SENSOR_RESOLUTION_LIST_GET..)
     *
     * releaseHardware
     */
    CAM_DEVICE();
    ~CAM_DEVICE();
    int initHardware(CAM_DEVICE_ID id, void ** handle);
    int releaseHardware();
    int getSensorInfo(Json::Value &jRequest, Json::Value &jResopnse);
    int ioctl(int32_t ctrlId, Json::Value &jRequest, Json::Value &jResponse);

    template<typename T>
    int post(int32_t ctrlId, const char* section, T value) {
        Json::Value jRequest, jResponse;
        if (section != NULL) {
            jRequest[section] = value;
        }
        return ioctl(ctrlId, jRequest, jResponse);
    }

    template<typename inType, typename outType>
    int post(int32_t ctrlId, const char* section, inType value, const char* retSection, outType& retVal) {
        Json::Value jRequest, jResponse;
        if (section != NULL) {
            jRequest[section] = value;
        }
        int ret = ioctl(ctrlId, jRequest, jResponse);
        readValueFromNode<outType>(jResponse[retSection], retVal);
        return ret;
    }
    /*
     * output buffer controls operation guide:
     * initOutChain
     * startOutChain
     * attachChain
     * waitForBufferEvent
     * DQBUF
     * ..Processing..
     * QBUF
     * loop to waitForBufferEvent
     * detachChain
     * stopOutChain
     * deInitOutChain
     */
    int initOutChain(ISPCORE_BUFIO_ID chain, uint8_t skip_interval);
    int deInitOutChain(ISPCORE_BUFIO_ID chain);

    int startOutChain(ISPCORE_BUFIO_ID chain);
    int stopOutChain(ISPCORE_BUFIO_ID chain);

    int attachChain(ISPCORE_BUFIO_ID chain);
    int detachChain(ISPCORE_BUFIO_ID chain);

    int waitForBufferEvent(ISPCORE_BUFIO_ID chain, buffCtrlEvent_t * xomCtrlEvent, int timeout);

    int DQBUF(ISPCORE_BUFIO_ID chain, MediaBuffer_t ** pBuf);
    int QBUF(ISPCORE_BUFIO_ID chain, MediaBuffer_t * pBuf);

    /*
     * input chain operations need to add
     */

    /*
     * Buffer Pool init control guide:
     * initBufferPoolCtrl
     * bitfSetBufferParameters
     * Loop begin
     *   buffPoolAddEntity
     * Loop end
     * bufferPoolKernelAddrMap
     * bufferPoolSetBufToEngine
     * deInitBufferPoolCtrl
    */

    int initBufferPoolCtrl(ISPCORE_BUFIO_ID chain);
    int deInitBufferPoolCtrl(ISPCORE_BUFIO_ID chain);

    int setBufferParameters(BUFF_MODE buff_mode);
    int bufferPoolAddEntity(ISPCORE_BUFIO_ID chain, BufIdentity* buf);

    int bufferPoolClearBufList(ISPCORE_BUFIO_ID chain);
    int bufferPoolSetBufToEngine(ISPCORE_BUFIO_ID chain);

    int bufferPoolKernelAddrMap(ISPCORE_BUFIO_ID chain, uint32_t needRemap);
    int bufferPoolGetBufIdList(ISPCORE_BUFIO_ID chain, std::list<BufIdentity *> * poolList);


    void * camdev_ctx = nullptr;
    CAM_DEVICE_ID isp_idx;
};

bool PGM_ReadRaw(std::string, PicBufMetaData_t *);

#endif  // _CAMERA_DEVICE_API_HPP_
