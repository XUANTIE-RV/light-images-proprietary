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

#include <json/json.h>

namespace t_common {

/**
 * @brief JSON API
 *
 */
struct JsonApp {
  /**
   * @brief Decode string to JSON object
   *
   * @param description
   * @return Json::Value
   */
  static Json::Value fromString(std::string const &description);

  /**
   * @brief Encode JSON object to string
   *
   * @param jValue
   * @param indentation
   * @return std::string
   */
  static std::string toString(Json::Value const &jValue,
                              std::string const &indentation = "  ");
};

} // namespace t_common
