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

#include "exception.hpp"
#include <iostream>
#include <string>

std::string computeMethodName(const std::string &function,
                              const std::string &prettyFunction);

#define __COMPACT_PRETTY_FUNCTION__                                            \
  computeMethodName(__FUNCTION__, __PRETTY_FUNCTION__)                         \
      .c_str() // c_str() is optional

#define REPORT(_X_)                                                            \
  do {                                                                         \
    if (_X_ != RET_SUCCESS && _X_ != RET_PENDING && _X_ != RET_CANCELED) {     \
      printf("%s:%d: %s() = %s(0x%02X) \n", __FILE__, __LINE__, __FUNCTION__,  \
             t_common::Error::text(_X_), _X_);                                 \
      return _X_;                                                              \
    }                                                                          \
  } while (0);

#define REPORT2(_X_)                                                           \
  do {                                                                         \
    if (_X_ != RET_SUCCESS && _X_ != RET_PENDING && _X_ != RET_CANCELED) {     \
      printf("%s:%d: %s() = %s(0x%02X) \n", __FILE__, __LINE__, __FUNCTION__,  \
             t_common::Error::text(_X_), _X_);                                 \
      return;                                                                  \
    }                                                                          \
  } while (0);

#define THROW(_X_)                                                             \
  do {                                                                         \
    if (_X_ != RET_SUCCESS && _X_ != RET_PENDING && _X_ != RET_CANCELED) {     \
      std::cout << __FILE__ << ":" << __LINE__ << ": " << __FUNCTION__         \
                << "() = " << t_common::Error::text(_X_) << "(" << _X_         \
                << ")\n";                                                      \
      throw t_common::LogicError(_X_, t_common::Error::text(_X_));             \
    }                                                                          \
  } while (0);

#if !defined(MEMCPY)
#define MEMCPY memcpy
#endif // MEMCPY

#if !defined(MEMSET)
#define MEMSET memset
#endif // MEMSET

#define REFCPY(_DST_REF_, _SRC_) memcpy(&_DST_REF_, _SRC_, sizeof(_DST_REF_))
#define REFSET(_DST_REF_, _VAL_) memset(&_DST_REF_, _VAL_, sizeof(_DST_REF_))
