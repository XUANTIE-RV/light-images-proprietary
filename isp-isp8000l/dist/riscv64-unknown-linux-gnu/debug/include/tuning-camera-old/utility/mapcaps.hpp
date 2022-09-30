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

#include <tuning-camera-old-config.hpp>

#include <cam_engine/cam_engine_api.h>

template <typename T> extern T isiCapValue(uint32_t);

template <typename T> extern bool isiCapValue(T &, uint32_t);

template <typename T> extern char const *isiCapDescription(uint32_t);

template <typename T> extern bool isiCapDescription(char const *, uint32_t);

extern bool operator==(CamEngineWindow_t const &, CamEngineWindow_t const &);

extern bool operator!=(CamEngineWindow_t const &, CamEngineWindow_t const &);

/* @} module_name_api*/
