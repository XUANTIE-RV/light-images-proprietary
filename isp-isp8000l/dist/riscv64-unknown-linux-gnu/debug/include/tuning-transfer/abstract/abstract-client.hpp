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

#include <tuning-common/common.hpp>

#include "abstract-object.hpp"
#include <fstream>
#include <string>

namespace t_transfer {

namespace abstract {

/**
 * @brief Client abstract
 *
 */
struct Client : Object {
  virtual ~Client();

  /**
   * @brief Get config
   *
   * @param jConfig
   * @return Client&
   */
  virtual Client &configGet(Json::Value &jConfig);

  /**
   * @brief Set config
   *
   * @param jConfig
   * @return Client&
   */
  virtual Client &configSet(Json::Value const &jConfig);

  /**
   * @brief Download file
   *
   * @param jQuery
   * @return Client&
   */
  virtual Client &fileDownload(Json::Value const &jQuery);

  /**
   * @brief Upload file
   *
   * @param jQuery
   * @return Client&
   */
  virtual Client &fileUpload(Json::Value const &jQuery);

  /**
   * @brief Info
   *
   * @return Client&
   */
  virtual Client &info();

  /**
   * @brief Sync request
   *
   * @param jQuery
   * @param jResponse
   * @param timeout
   * @return Client&
   */
  virtual Client &request(Json::Value const &jQuery, Json::Value &jResponse,
                          int32_t timeout);

  /**
   * @brief Async request
   *
   * @param jQuery
   * @param fComplete
   * @param timeout
   * @return Client&
   */
  virtual Client &
  request(Json::Value const &jQuery,
          std::function<void(Json::Value jResponse)> const &fComplete,
          int32_t timeout);

  /**
   * @brief Read text
   *
   * @param text
   * @return Client&
   */
  virtual Client &textRead(std::string &text);

  /**
   * @brief Write text
   *
   * @param text
   * @return Client&
   */
  virtual Client &textWrite(std::string const &text);
};

} // namespace abstract

} // namespace t_transfer
