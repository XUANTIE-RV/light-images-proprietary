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

#include "abstract/abstract-client.hpp"

namespace t_transfer {

/**
 * @brief Client holder
 *
 */
class ClientHolder {
public:
  /**
   * @brief Client type
   *
   */
  enum Type {
    Http,
    Usb,
    Uart,

    Sum,
  };

  /**
   * @brief Construct a new Client Holder object
   *
   * @param type
   * @param fReport
   */
  ClientHolder(Type type, std::function<void(std::string const &text)> fReport);
  ~ClientHolder();

  /**
   * @brief Abstract reference
   *
   * @return t_transfer::abstract::Client&
   */
  t_transfer::abstract::Client &abstract() {
    if (!pAbstract) {
      throw "Abstract is never initialized";
    }

    return *pAbstract;
  }

  /**
   * @brief Get config
   *
   * @param jConfig
   * @return ClientHolder&
   */
  ClientHolder &configGet(Json::Value jConfig);

  /**
   * @brief Set config
   *
   * @param jConfig
   * @return ClientHolder&
   */
  ClientHolder &configSet(Json::Value const &jConfig);

  /**
   * @brief Download file
   *
   * @param jQuery
   * @return ClientHolder&
   */
  ClientHolder &fileDownload(Json::Value &jQuery);

  /**
   * @brief Upload file
   *
   * @param jQuery
   * @return ClientHolder&
   */
  ClientHolder &fileUpload(Json::Value const &jQuery);

  /**
   * @brief Info
   *
   * @return ClientHolder&
   */
  ClientHolder &info();

  /**
   * @brief Sync request with timeout
   *
   * @param jQuery
   * @param jResponse
   * @param timeout
   * @return ClientHolder&
   */
  ClientHolder &request(Json::Value const &jQuery, Json::Value &jResponse,
                        int32_t timeout);

  /**
   * @brief Async request
   *
   * @param jQuery
   * @param fComplete
   * @param timeout
   * @return ClientHolder&
   */
  ClientHolder &
  request(Json::Value const &jQuery,
          std::function<void(Json::Value jResponse)> const &fComplete,
          int32_t timeout);

  /**
   * @brief Read text
   *
   * @param text
   * @return ClientHolder&
   */
  ClientHolder &textRead(std::string &text);

  /**
   * @brief Write text
   *
   * @param text
   * @return ClientHolder&
   */
  ClientHolder &textWrite(std::string const &text);

private:
  t_transfer::abstract::Client *pAbstract = nullptr;
};

} // namespace t_transfer
