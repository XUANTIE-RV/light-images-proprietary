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

//! Powered by Yong Yang

#pragma once

#include <ebase/trace.h>

USE_TRACER(ITF_INF);
USE_TRACER(ITF_WAN);
USE_TRACER(ITF_ERR);

#define TRACE_IN TRACE(ITF_INF, "%s (enter)\n", __PRETTY_FUNCTION__)
#define TRACE_OUT TRACE(ITF_INF, "%s (exit)\n", __PRETTY_FUNCTION__)
