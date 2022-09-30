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

#include "calib_features_ry.hpp"
#include "cam_common_ry.hpp"

#include <cam_engine/cam_engine_ry_api.h>

#include <cam_engine/cam_engine_aaa_ry_api.h>
#include <cam_engine/cam_engine_cproc_ry_api.h>
#include <cam_engine/cam_engine_imgeffects_ry_api.h>
#include <cam_engine/cam_engine_isp_ry_api.h>
#include <cam_engine/cam_engine_jpe_ry_api.h>
#include <cam_engine/cam_engine_mi_ry_api.h>
#include <cam_engine/cam_engine_simp_ry_api.h>
#include "calib_calibration_ry.hpp"
#include <cameric_reg_drv/cameric_reg_description_ry.h>

namespace camdev {

struct Operation_Handle{
    HalHolder *pHalHolder = nullptr;
    Calibration *pCalibration = nullptr;
};



struct Image {
    Image();
    ~Image();

    void clean();

    void load(std::string fileName);

    PicBufMetaData_t picBufMetaData;
};


class Engine : public CamStatus {
public:
#ifdef USE_3AV2
    Engine(Operation_Handle *pOperationHandle_in, bool hdr, int index);
#else
    Engine(Operation_Handle *pOperationHandle_in, bool hdr);
#endif
    ~Engine();

public:
    int32_t aeConfigGet(camdev::CalibAe::Config &);
    int32_t aeConfigSet(camdev::CalibAe::Config);
    int32_t aeEcmGet(camdev::CalibAe::Ecm &);
    int32_t aeEcmSet(camdev::CalibAe::Ecm);
    int32_t aeEnableGet(bool &);
    int32_t aeEnableSet(bool);
    int32_t aeFlickerPeriodGet(float &) const;
    int32_t aeFlickerPeriodSet(float &) const;
    int32_t aeStatus(camdev::CalibAe::Status &);
    int32_t aeReset();

    int32_t afAvailableGet(bool &);
    int32_t afConfigGet(camdev::CalibAf::Config &);
    int32_t afConfigSet(camdev::CalibAf::Config);
    int32_t afEnableGet(bool &);
    int32_t afEnableSet(bool);

    static void afpsResChangeCb(uint32_t, const void *);
    static int32_t entryAfpsResChange(void *);
    typedef int32_t(AfpsResChangeRequestCb_t)(uint16_t, uint16_t, const void *);

    int32_t avsConfigGet(camdev::CalibAvs::Config &);
    int32_t avsConfigSet(camdev::CalibAvs::Config);
    int32_t avsEnableGet(bool &);
    int32_t avsEnableSet(bool);
    int32_t avsStatusGet(camdev::CalibAvs::Status &);

    int32_t awbConfigGet(camdev::CalibAwb::Config &);
    int32_t awbConfigSet(camdev::CalibAwb::Config);
    int32_t awbEnableGet(bool &);
    int32_t awbEnableSet(bool);
    int32_t awbGainSet(float* gain);
    int32_t awbReset();
    int32_t awbStatusGet(camdev::CalibAwb::Status &);
    int32_t awbMeasWinSet(CamEngineWindow_ry_t &);

    int32_t blsConfigGet(camdev::CalibBls::Config &);
    int32_t blsConfigSet(camdev::CalibBls::Config);

    int32_t bufferCbRegister(CamEngineBufferCb_ry_t, void *);
    int32_t bufferCbUnregister();
    int32_t bufferCbGet(CamEngineBufferCb_ry_t *, void **);

    int32_t cacConfigGet(camdev::CalibCac::Config &);
    int32_t cacConfigSet(camdev::CalibCac::Config);
    int32_t cacEnableGet(bool &);
    int32_t cacEnableSet(bool);
    int32_t cacStatusGet(camdev::CalibCac::Config &);

    static void cbCompletion(CamEngineCmdId_ry_t, int32_t, const void *);

    int32_t cnrConfigGet(camdev::CalibCnr::Config &);
    int32_t cnrConfigSet(camdev::CalibCnr::Config);
    int32_t cnrEnableGet(bool &);
    int32_t cnrEnableSet(bool);

    int32_t cprocConfigGet(camdev::CalibCproc::Config &);
    int32_t cprocConfigSet(camdev::CalibCproc::Config);
    int32_t cprocEnableGet(bool &);
    int32_t cprocEnableSet(bool);

    int32_t demosaicConfigGet(camdev::CalibDemosaic::Config &);
    int32_t demosaicConfigSet(camdev::CalibDemosaic::Config);
    int32_t demosaicEnableGet(bool &);
    int32_t demosaicEnableSet(bool);

    int32_t nr2dConfigGet(camdev::CalibNr2d::Config &, camdev::CalibNr2d::Generation);
    int32_t nr2dConfigSet(camdev::CalibNr2d::Config, camdev::CalibNr2d::Generation);
    int32_t nr2dEnableGet(bool &, camdev::CalibNr2d::Generation);
    int32_t nr2dEnableSet(bool, camdev::CalibNr2d::Generation);
    int32_t nr2dReset(camdev::CalibNr2d::Generation);
    int32_t nr2dStatusGet(camdev::CalibNr2d::Status &, camdev::CalibNr2d::Generation);
    int32_t nr2dTableGet(Json::Value &, camdev::CalibNr2d::Generation);
    int32_t nr2dTableSet(Json::Value, camdev::CalibNr2d::Generation);

    int32_t nr3dConfigGet(camdev::CalibNr3d::Config &, camdev::CalibNr3d::Generation);
    int32_t nr3dConfigSet(camdev::CalibNr3d::Config, camdev::CalibNr3d::Generation);
    int32_t nr3dEnableGet(bool &, camdev::CalibNr3d::Generation);
    int32_t nr3dEnableSet(bool, camdev::CalibNr3d::Generation);
    int32_t nr3dReset(camdev::CalibNr3d::Generation);
    int32_t nr3dStatusGet(camdev::CalibNr3d::Status &, camdev::CalibNr3d::Generation);
    int32_t nr3dTableGet(Json::Value &, camdev::CalibNr3d::Generation);
    int32_t nr3dTableSet(Json::Value, camdev::CalibNr3d::Generation);

    int32_t dpccEnableGet(bool &);
    int32_t dpccEnableSet(bool);

    int32_t dpfConfigGet(camdev::CalibDpf::Config &);
    int32_t dpfConfigSet(camdev::CalibDpf::Config);
    int32_t dpfEnableGet(bool &);
    int32_t dpfEnableSet(bool);

    int32_t eeConfigGet(camdev::CalibEe::Config &);
    int32_t eeConfigSet(camdev::CalibEe::Config);
    int32_t eeEnableGet(bool &);
    int32_t eeEnableSet(bool);
    int32_t eeReset();
    int32_t eeStatusGet(camdev::CalibEe::Status &status);
    int32_t eeTableGet(Json::Value &jTable);
    int32_t eeTableSet(Json::Value jTable);

    int32_t filterConfigGet(camdev::CalibFilter::Config &);
    int32_t filterConfigSet(camdev::CalibFilter::Config &);
    int32_t filterEnableGet(bool &);
    int32_t filterEnableSet(bool);
    int32_t filterStatusGet(camdev::CalibFilter::Status &);
    int32_t filterTableGet(Json::Value &);
    int32_t filterTableSet(Json::Value);

    int32_t gcConfigGet(camdev::CalibGc::Config &);
    int32_t gcConfigSet(camdev::CalibGc::Config);
    int32_t gcEnableGet(bool &);
    int32_t gcEnableSet(bool);

    int32_t hdrConfigGet(camdev::CalibHdr::Config &);
    int32_t hdrConfigSet(camdev::CalibHdr::Config);
    int32_t hdrEnableGet(bool &);
    int32_t hdrEnableSet(bool);
    int32_t hdrReset();

    int32_t ieConfigGet(camdev::CalibIe::Config &);
    int32_t ieConfigSet(camdev::CalibIe::Config);
    int32_t ieEnableGet(bool &);
    int32_t ieEnableSet(bool);

    // int32_t getDemosaicMode(CamerIcIspDemosaicMode_t &, uint8_t &) const;
    // int32_t setDemosaicMode(const CamerIcIspDemosaicMode_t &, uint8_t);

    // bool isGammaInActivated() const;
    // int32_t activateGammaIn(bool = BOOL_TRUE);
    // bool isGammaOutActivated() const;
    // int32_t activateGammaOut(bool = BOOL_TRUE);
    // bool isWBActivated() const;
    // int32_t activateGammaWB(bool = BOOL_TRUE);

    int32_t lscConfigGet(camdev::CalibLsc::Config &);
    int32_t lscConfigSet(camdev::CalibLsc::Config &);
    int32_t lscEnableGet(bool &);
    int32_t lscEnableSet(bool);
    int32_t lscStatusGet(camdev::CalibLsc::Status &);

    int32_t jpeConfigGet(camdev::CalibJpe::Config &);
    int32_t jpeConfigSet(camdev::CalibJpe::Config);
    int32_t jpeEnableGet(bool &);
    int32_t jpeEnableSet(bool);

    int32_t pathConfigGet(camdev::CalibPaths::Config &);
    int32_t pathConfigSet(const camdev::CalibPaths::Config&);

    int32_t pictureOrientationSet(CamerIcMiOrientation_ry_t);

    int32_t reset();

    int32_t resolutionSet(CamEngineWindow_ry_t, CamEngineWindow_ry_t, CamEngineWindow_ry_t, uint32_t = 0);

    int32_t searchAndLock(CamEngineLockType_t);

    int32_t simpConfigGet(camdev::CalibSimp::Config &);
    int32_t simpConfigSet(camdev::CalibSimp::Config);
    int32_t simpEnableGet(bool &);
    int32_t simpEnableSet(bool);

    int32_t start();
    int32_t stop();

    int32_t streamingStart(uint32_t = 0);
    int32_t streamingStop();

    int32_t unlock(CamEngineLockType_t);

    int32_t wbConfigGet(camdev::CalibWb::Config &);
    int32_t wbConfigSet(camdev::CalibWb::Config);

    int32_t wdrConfigGet(camdev::CalibWdr::Config &, camdev::CalibWdr::Generation);
    int32_t wdrConfigSet(camdev::CalibWdr::Config, camdev::CalibWdr::Generation);
    int32_t wdrEnableGet(bool &, camdev::CalibWdr::Generation);
    int32_t wdrEnableSet(bool, camdev::CalibWdr::Generation);
    int32_t wdrReset(camdev::CalibWdr::Generation);
    int32_t wdrStatusGet(camdev::CalibWdr::Status &, camdev::CalibWdr::Generation);
    int32_t wdrTableGet(Json::Value &, camdev::CalibWdr::Generation);
    int32_t wdrTableSet(Json::Value, camdev::CalibWdr::Generation);
    int32_t getMetadata(CamEnginePathType_ry_t path, struct isp_metadata *meta);

    int32_t dmsc2ConfigGet(camdev::CalibDmsc2::Config&);
    int32_t dmsc2ConfigSet(const camdev::CalibDmsc2::Config&);
    int32_t dmsc2EnableSet(bool);
    int32_t dmsc2EnableGet(bool&);

    int32_t geConfigGet(camdev::CalibGe::Config&);
    int32_t geConfigSet(const camdev::CalibGe::Config&);
    int32_t geEnableSet(bool);
    int32_t geEnableGet(bool&);

    int32_t rgbGammaConfigGet(camdev::CalibRgbGamma::Config&);
    int32_t rgbGammaConfigSet(const camdev::CalibRgbGamma::Config&);
    int32_t rgbGammaEnableSet(bool);
    int32_t rgbGammaEnableGet(bool&);

    int32_t colorAdjustConfigGet(camdev::CalibColorAdjust::Config&);
    int32_t colorAdjustConfigSet(const camdev::CalibColorAdjust::Config&);
    int32_t colorAdjustEnableSet(bool);
    int32_t colorAdjustEnableGet(bool&);

    int32_t tdnrConfigGet(camdev::CalibTdnr::Config&);
    int32_t tdnrConfigSet(const camdev::CalibTdnr::Config&);
    int32_t tdnrEnableGet(bool&);
    int32_t tdnrEnableSet(bool);
    int32_t tdnrCurveSet(double mode_a, double mode_b);

    int32_t dgainConfigGet(camdev::CalibDigitalGain::Config&);
    int32_t dgainConfigSet(const camdev::CalibDigitalGain::Config&);
    int32_t dgainEnableSet(bool);
    int32_t dgainEnableGet(bool&);

    int32_t dciHistConfigGet(camdev::CalibDciHist::Config&);
    int32_t dciHistConfigSet(const camdev::CalibDciHist::Config&);
    int32_t dciHistEnableSet(bool);
    int32_t dciHistEnableGet(bool&);
    int32_t dciHistStatusGet(uint16_t* pCurve);

    int32_t aehdrAutoRatioConfigGet(camdev::CalibAehdrAutoRatio::Config&);
    int32_t aehdrAutoRatioConfigSet(const camdev::CalibAehdrAutoRatio::Config&);
    int32_t aehdrAutoRatioEnableSet(bool);
    int32_t aehdrAutoRatioEnableGet(bool&);

public:
    CamEngineBlackLevel_ry_t blackLevel;

    CamEngineConfig_ry_t camEngineConfig;

    CamEngineCcMatrix_ry_t ccMatrix;
    CamEngineCcOffset_ry_t ccOffset;

    osEvent eventStart;
    osEvent eventStop;
    osEvent eventStartStreaming;
    osEvent eventStopStreaming;
    osEvent eventAcquireLock;
    osEvent eventReleaseLock;

    CamerIcRegDescriptionDrvConfig_t regDescriptionConfig;
    CamerIcDrvContext_ry_t hCamerIcRegCtx;

    CamEngineInstanceConfig_ry_t instanceConfig;

    CamEngineHandle_ry_t hCamEngine;
    Operation_Handle *pOperationHandle;

    AfpsResChangeRequestCb_t *pAfpsResChangeRequestCb = NULL;

    void *pUserCbCtx = NULL;

    osQueue queueAfpsResChange;

    CamEngineWbGains_ry_t wbGains;

    Image *pSimpImage = NULL;

private:
    osThread threadAfpsResChange;
};
} // namespace camdev
