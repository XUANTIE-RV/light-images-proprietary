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

#include <string>

namespace t_common {

/**
 * @brief Version common API
 *
 */
struct Version {
  virtual ~Version() {}

  /**
   * @brief Get version info
   *
   * @param name
   * @param number
   * @param date
   */
  virtual void versionGet(std::string &name, std::string &number,
                          std::string &date) = 0;
};

} // namespace t_common
