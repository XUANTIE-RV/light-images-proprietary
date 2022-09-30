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
#ifndef _CAM_DEVICE_META_BUILDER_HPP_
#define _CAM_DEVICE_META_BUILDER_HPP_
#include <string>
#include <cam_device_metadata.h>
#include <json/json.h>

bool buildMetadata(struct isp_metadata *meta, Json::Value& root);

#endif
