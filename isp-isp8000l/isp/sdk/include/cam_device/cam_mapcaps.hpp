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

/**
 * @file mapcaps.h
 *
 * @brief
 *   Mapping of ISI capabilities / configuration to CamerIC modes.
 *
 *****************************************************************************/
/**
 *
 * @mainpage Module Documentation
 *
 *
 * Doc-Id: xx-xxx-xxx-xxx (NAME Implementation Specification)\n
 * Author: NAME
 *
 * DESCRIBE_HERE
 *
 *
 * The manual is divided into the following sections:
 *
 * -@subpage module_name_api_page \n
 * -@subpage module_name_page \n
 *
 * @page module_name_api_page Module Name API
 * This module is the API for the NAME. DESCRIBE IN DETAIL / ADD USECASES...
 *
 * for a detailed list of api functions refer to:
 * - @ref module_name_api
 *
 * @defgroup module_name_api Module Name API
 * @{
 */

#pragma once

#include <string>
#include <cam_engine/cam_engine_api.h>
#include <common/mipi.h>
#include <ebase/trace.h>
#include <isi/isi.h>

template <typename T> extern T isiCapValue(uint32_t);

template <typename T> extern bool isiCapValue(T &, uint32_t);

template <typename T> extern const char *isiCapDescription(uint32_t);

template <typename T> extern bool isiCapDescription(const char *, uint32_t);

extern bool operator==(const CamEngineWindow_t &, const CamEngineWindow_t &);

extern bool operator!=(const CamEngineWindow_t &, const CamEngineWindow_t &);

/* @} module_name_api*/
