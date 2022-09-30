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
#ifndef _VSI_3AV2_C_H_
#define _VSI_3AV2_C_H_
#include <stdint.h>
#include <stdlib.h>
#include <vsi3a/vsi3a_types.h>

#ifndef VVEXPORTS
# define VVEXPORTS
#endif

typedef void* Vsi3AHandle_t;

#ifdef __cplusplus
extern "C"{
#endif

/** @brief create new Vsi3A instance
 *  @param ispId, specific isp id to support dual isp
 *      we need create instance for each isp.
 */
VVEXPORTS Vsi3AHandle_t Vsi3ACreateInstance(int ispId);  // support dual isp


/** @brief get Vsi3A instance by isp id.
 */
VVEXPORTS Vsi3AHandle_t Vsi3AGetInstance(int ispId);


/** @brief destroy Vsi3A instance
 */
VVEXPORTS void Vsi3ADestroyInstance(Vsi3AHandle_t handle);


/** @brief post HW STATS to 3a
 *  @param type, HW supported stats types: AEV1, AEV2, AWB, AFM, HIST, VSM...
 *  @param params, user can post any types by params pointer, defined in vsi3a_types.h
 *      Aev1EventData, Aev2EventData, HistEventData...
 */
VVEXPORTS int Vsi3APostEvent(Vsi3AHandle_t handle, enum e3aStatistic_t type, void *params);


/** @brief init/reset settings of 3A sub algo modules
 *  @param type, AE, AWB, AF, AVS, AHDR...
 *  @param params, user can post any types by params pointer, defined in vsi3a_types.h
 *      AecSettings, AwbSettings, HdrSettings...
 */
VVEXPORTS int Vsi3ASetConfig(Vsi3AHandle_t handle, enum e3aConfig_t type, void *params);
VVEXPORTS int Vsi3AGetConfig(Vsi3AHandle_t handle, enum e3aConfig_t type, void *params);



/** @brief set 3A sub algo modules working mode.
 *  @param type, in vsi3a_types.h, VSI_AE_MODE, VSI_AF_MODE, VSI_AWB_MODE
 *  @param params,  in vsi3a_types.h
 *     VSI_AE_ANTIBANDING_MODE_OFF, VSI_AE_ANTIBANDING_MODE_50HZ...
 */
VVEXPORTS int Vsi3ASetMode(Vsi3AHandle_t handle, enum e3aMode_t type, int mode);


/** @brief get 3A sub algo modules current working mode.
 */
VVEXPORTS int Vsi3AGetMode(Vsi3AHandle_t handle, enum e3aMode_t type, int *mode);


/** @brief get 3A region
 *  @param Vsi3AROI, in vsi3a_types.h rect{x, y, w, h} {0, 0, 1920, 1080}
 */
VVEXPORTS int Vsi3AGetROI(Vsi3AHandle_t handle, enum e3aMode_t type, int* num, struct Vsi3AROI *roi);

/** @brief set 3A region
 *  @param type, in vsi3a_types.h, VSI_AE_MODE, VSI_AF_MODE, VSI_AWB_MODE
 *  @param Vsi3AROI, in vsi3a_types.h rect{x, y, w, h} {0, 0, 1920, 1080}
 */
VVEXPORTS int Vsi3ASetROI(Vsi3AHandle_t handle, enum e3aMode_t type, int num, struct Vsi3AROI *roi);


/** @brief get 3A sub algo modules current status
 *  @param type, AE, AWB, AF, AVS, AHDR...in vsi3a_types.h 
 *  @param status, in vsi3a_types.h 
 *      VSI_AWB_STATUS_INIT, VSI_AWB_STATUS_RUNNING, VSI_AWB_LOCKED...
 */
VVEXPORTS int Vsi3AGetStatus(Vsi3AHandle_t handle, enum e3aStatus_t type, int *status);

/** @brief get runtime data of 3a module
 *  @param type, AE, AWB, AF, AVS, AHDR...in vsi3a_types.h 
 *  @param data, pointer to aev1/aev2/aehdr exp stats, 
 *               pointer to hist16/hist256/histhdr stats
 *               pointer to awbv1 stats
 *               pointer to asem object data.
 *       Allocated by user, free by user.
 */
VVEXPORTS int Vsi3AGetData(Vsi3AHandle_t handle, enum e3aRuntimeData_t type, void *data);

/** @brief et runtime data to 3a modules

 */
VVEXPORTS int Vsi3ASetData(Vsi3AHandle_t handle, enum e3aRuntimeSetData_t type, void *data);

/** @brief set isp handle
 *  @param ispHandle, pointer of CamerIcDrvHandle_t
 *         1. control isp awb gain.
 *         2. control lsc maxtrix/sector
 *         3. control ccm matrix offset
 *         4. control wdr, stitching, exp window.
 *         5. ...
 */
VVEXPORTS int Vsi3ASetIspHandle(Vsi3AHandle_t handle, void *ispHandle);


/** @brief set sensor handle and calib data handle
 *  @param sensorHandle, pointer of IsiSensorHandle_t, 
 *          1. set integration time/gain
 *          2  get integration time/gain
 *          3. set/get sensor awb gain
 *          4. query max/min integration time/gain
 *  @param calibHandle pointer of sensor calibhandle.
 *          1. query default AE setpoint
 *          2. query default tolerance
 *          3. query default dampOver/dampUnder.
 */
VVEXPORTS int Vsi3ASetSensorHandle(Vsi3AHandle_t handle, void *sensorHandle, void *calibHandle);


VVEXPORTS void* Vsi3AGetGlobalData(Vsi3AHandle_t handle);


#ifdef __cplusplus
}
#endif

#endif
