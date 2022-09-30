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

#define RET_SUCCESS 0      //!< this has to be 0, if clauses rely on it
#define RET_FAILURE 1      //!< general failure
#define RET_NOTSUPP 2      //!< feature not supported
#define RET_BUSY 3         //!< there's already something going on...
#define RET_CANCELED 4     //!< operation canceled
#define RET_OUTOFMEM 5     //!< out of memory
#define RET_OUTOFRANGE 6   //!< parameter/value out of range
#define RET_IDLE 7         //!< feature/subsystem is in idle state
#define RET_WRONG_HANDLE 8 //!< handle is wrong
#define RET_NULL_POINTER                                                       \
  9 //!< the/one/all parameter(s) is a(are) NULL pointer(s)
#define RET_NOTAVAILABLE 10     //!< profile not available
#define RET_DIVISION_BY_ZERO 11 //!< a divisor equals ZERO
#define RET_WRONG_STATE 12      //!< state machine in wrong state
#define RET_INVALID_PARM 13     //!< invalid parameter
#define RET_PENDING 14          //!< command pending
#define RET_WRONG_CONFIG 15     //!< given configuration is invalid

#define ERROR_DESCRIPTION(_ERROR_, _VALUE_)                                    \
  do {                                                                         \
    if (_ERROR_ == _VALUE_)                                                    \
      return #_VALUE_;                                                         \
  } while (0)

namespace t_common {

/**
 * @brief Error description
 *
 */
struct Error {
  /**
   * @brief Convert error code to text
   *
   * @param error
   * @return char const*
   */
  static char const *text(int error) {
    ERROR_DESCRIPTION(error, RET_SUCCESS);
    ERROR_DESCRIPTION(error, RET_FAILURE);
    ERROR_DESCRIPTION(error, RET_NOTSUPP);
    ERROR_DESCRIPTION(error, RET_BUSY);
    ERROR_DESCRIPTION(error, RET_CANCELED);
    ERROR_DESCRIPTION(error, RET_OUTOFMEM);
    ERROR_DESCRIPTION(error, RET_OUTOFRANGE);
    ERROR_DESCRIPTION(error, RET_IDLE);
    ERROR_DESCRIPTION(error, RET_WRONG_HANDLE);
    ERROR_DESCRIPTION(error, RET_NULL_POINTER);
    ERROR_DESCRIPTION(error, RET_NOTAVAILABLE);
    ERROR_DESCRIPTION(error, RET_DIVISION_BY_ZERO);
    ERROR_DESCRIPTION(error, RET_WRONG_STATE);
    ERROR_DESCRIPTION(error, RET_INVALID_PARM);
    ERROR_DESCRIPTION(error, RET_PENDING);
    ERROR_DESCRIPTION(error, RET_WRONG_CONFIG);
    return "UNKNOWN ERROR";
  }
};

} // namespace t_common
