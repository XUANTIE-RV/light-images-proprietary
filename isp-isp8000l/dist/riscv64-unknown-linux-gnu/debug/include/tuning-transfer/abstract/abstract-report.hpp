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

#include <functional>
#include <iostream>

namespace t_transfer {

namespace abstract {

/**
 * @brief Report
 *
 */
struct Report {
  /**
   * @brief Operator <<
   *
   * @param text
   * @return Report&
   */
  Report &operator<<(std::string const &text) {
    if (fReport) {
      fReport(text);
    } else {
      std::cout << text;
    }

    return *this;
  }

  /**
   * @brief Report function
   *
   */
  std::function<void(std::string const &text)> fReport;
};

} // namespace abstract

} // namespace t_transfer
