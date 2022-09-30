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

#include "abstract/abstract-server.hpp"

namespace t_transfer {

/**
 * @brief Server holder
 *
 */
class ServerHolder {
public:
  /**
   * @brief Server type
   *
   */
  enum Type {
    Http,
    Usb,
    Uart,

    Sum,
  };

  /**
   * @brief Construct a new Server Holder object
   *
   * @param type
   * @param jsonHandler
   */
  ServerHolder(Type type, JsonHandler jsonHandler);
  ~ServerHolder();

  /**
   * @brief Abstract reference
   *
   * @return t_transfer::abstract::Server&
   */
  t_transfer::abstract::Server &abstract() {
    if (!pAbstract) {
      throw "Abstract is never initialized";
    }

    return *pAbstract;
  }

private:
  t_transfer::abstract::Server *pAbstract = nullptr;
};

} // namespace t_transfer
