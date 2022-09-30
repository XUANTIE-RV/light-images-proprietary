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

#include <algorithm>
#include <sstream>

namespace t_common {

/**
 * @brief Covert data type
 *
 */
struct Convert {
  /**
   * @brief Covert hex string to int
   *
   * @param hex
   * @return int
   */
  static int hex2Int(std::string hex);

  /**
   * @brief Convert int to hex string
   *
   * @param value
   * @return std::string
   */
  static std::string int2Hex(int32_t value);

  /**
   * @brief Convert unsigned int to hex string
   *
   * @param value
   * @return std::string
   */
  static std::string int2Hex(uint32_t value);
};

} // namespace t_common
