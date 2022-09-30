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

#ifdef USE_STANDARD_ASSERT
#include "assert.hpp"
#undef DCT_ASSERT
#define DCT_ASSERT(_X_) assert(_X_)
#else
#include <ebase/dct_assert.h>
#endif

#define REPORT(_X_)                                                            \
  do {                                                                         \
    if (_X_ != RET_SUCCESS && _X_ != RET_PENDING) {                            \
      printf("[ERR] %s:%d: %s() = %d(%s) \n", __FILE__, __LINE__,              \
             __FUNCTION__, _X_, #_X_);                                         \
      return _X_;                                                              \
    }                                                                          \
  } while (0);

#define REPORT_WORET(_X_)                                                      \
  do {                                                                         \
    if (_X_ != RET_SUCCESS && _X_ != RET_PENDING) {                            \
      printf("[ERR] %s:%d: %s() = %d(%s) \n", __FILE__, __LINE__,              \
             __FUNCTION__, _X_, #_X_);                                         \
    }                                                                          \
  } while (0);


#include <ebase/builtins.h>

#define REFCPY(_DST_REF_, _SRC_) MEMCPY(&_DST_REF_, _SRC_, sizeof(_DST_REF_))
#define REFSET(_DST_REF_, _VAL_) MEMSET(&_DST_REF_, _VAL_, sizeof(_DST_REF_))
