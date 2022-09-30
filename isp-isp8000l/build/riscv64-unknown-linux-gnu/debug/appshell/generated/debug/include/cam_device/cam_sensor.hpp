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

#include "calibdb.hpp"
#include "calib_calibration.hpp"
#include "calib_features.hpp"
#include "cam_common.hpp"
#include <algorithm>
#include <iostream>
#include <isi/isi_iss.h>
#include <list>
#include <string>
#include <vector>


USE_TRACER(CITF_INF);
USE_TRACER(CITF_WAN);
USE_TRACER(CITF_ERR);
#define TRACE_IN TRACE(CITF_INF, "%s (enter)\n", __PRETTY_FUNCTION__)
#define TRACE_OUT TRACE(CITF_INF, "%s (exit)\n", __PRETTY_FUNCTION__)

namespace camdev {

struct SensorOps : CamStatus {
    SensorOps (camdev::CalibSensor &, HalHolder *pHalHolder_input);
    ~SensorOps ();

    struct Resolution {
        uint value;
        std::string description;
    };

    struct cam_compand_curve{
        bool     enable;
        uint8_t  in_bit;
        uint8_t  out_bit;
        uint8_t  px[64];
        uint32_t x_data[65];
        uint32_t y_data[65];
    };

    int32_t capsGet(IsiSensorCaps_t &);
    int32_t configGet(IsiSensorConfig_t &);
    int32_t configSet(IsiSensorConfig_t &);

    SensorOps &checkValid();

    int32_t close();

    int32_t driverChange(std::string driverFileName, std::string calibFileName = "");

    int32_t ecConfigGet(camdev::CalibEc::Config &);
    int32_t ecConfigSet(camdev::CalibEc::Config);
    int32_t ecStatusGet(camdev::CalibEc::Status &);

    int32_t focusGet(uint &);
    int32_t focusSet(uint);

    int32_t illuminationProfilesGet(std::vector<CamIlluProfile_t *> &);

    bool isConnected();
    bool isTestPattern();

    int32_t nameGet(std::string &);

    int32_t open();

    int32_t registerDescriptionGet(uint, IsiRegDescription_t &);
    int32_t registerDump2File(std::string &);
    int32_t registerRead(uint, uint &);
    int32_t registerTableGet(IsiRegDescription_t *pRegisterTable) { return 0; }
    int32_t registerWrite(uint, uint);

    int32_t reset();

    int32_t resolutionDescriptionListGet(std::list<Resolution> &);
    int32_t resolutionSet(uint16_t, uint16_t);
    int32_t resolutionGet(uint16_t*, uint16_t*);
    int32_t resolutionSupportListGet(std::list<Resolution> &);

    int32_t frameRateGet(uint32_t &);
    int32_t frameRateSet(uint32_t);

    int32_t modeSet(uint32_t);
    int32_t modeGet(uint32_t &);

    int32_t revisionGet(uint &);

    int32_t setup();

    int32_t streamEnableSet(bool);

    int32_t testPatternEnableSet(bool);
	int32_t bayerPatternSet(uint8_t);

    static int32_t queryCaps(HalHolder *, vvcam_mode_info_array_t *,
            uint32_t *, uint32_t *);
    static int32_t setCapsMode(HalHolder *, uint32_t , const char*);
    static int32_t setCapsModeLock(HalHolder *);

    HalHolder *pHalHolder;

    CalibDb calibDb;

    IsiSensorConfig_t config;

    IsiSensorHandle_t hSensor = 0;

    IsiCamDrvConfig_t *pCamDrvConfig = nullptr;
    void *pLib = nullptr;
    const IsiRegDescription_t *pRegisterTable = nullptr;
    const IsiSensor_t *pSensor = nullptr;

    camdev::CalibSensor &calibrationSensor;

    char szDriverName[256];
    char szCalibFile[256];
    int64_t csiFormat;
    uint32_t SensorHdrMode;
    uint32_t SensorHdrStichMode;
    uint32_t SensorFps;

    struct cam_compand_curve expand_curve;
};

} // namespace camdev
