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
#include <iostream>

namespace t_transfer {

/**
 * @brief JSON handler
 *
 */
typedef std::function<void(Json::Value const &jQuery, Json::Value &jResponse)>
    JsonHandler;

namespace abstract {

/**
 * @brief Server abstract
 *
 */
struct Server : Object {
  /**
   * @brief Construct a new Server object
   *
   * @param jsonHandler
   */
  Server(JsonHandler jsonHandler);
  virtual ~Server();

  /**
   * @brief JSON handler holder
   *
   */
  JsonHandler jsonHandler;
};

} // namespace abstract

} // namespace t_transfer
