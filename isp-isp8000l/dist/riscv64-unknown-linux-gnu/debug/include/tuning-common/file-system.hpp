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

#include <list>
#include <string>

namespace t_common {

/**
 * @brief File system utilities
 *
 */
struct FileSystem {
  /**
   * @brief Get file name from path
   *
   * @param path
   * @return std::string
   */
  static std::string filenameGetFromPath(std::string const &path);

  /**
   * @brief Check file exist
   *
   * @param name
   * @return true
   * @return false
   */
  static bool isExists(std::string const &name);

  /**
   * @brief List files
   *
   * @param list
   * @param extension
   * @param path
   * @return int
   */
  static int ls(std::list<std::string> &list, std::string const &extension = "",
                std::string const &path = ".");

  /**
   * @brief Get current path
   *
   * @return std::string
   */
  static std::string pwd();

  /**
   * @brief Create directory(and sub directory)
   *
   * @param dir
   */
  static void mkdirP(std::string const &dir);
};

} // namespace t_common
