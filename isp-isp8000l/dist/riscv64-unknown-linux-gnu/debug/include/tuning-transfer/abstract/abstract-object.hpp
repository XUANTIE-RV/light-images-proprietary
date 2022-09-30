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

#include <tuning-transfer-config.hpp>

#include <tuning-common/common.hpp>

#include "abstract-report.hpp"

namespace t_transfer {

namespace abstract {

/**
 * @brief Abstract object
 *
 */
struct Object {
  /**
   * @brief Set report
   *
   * @param fReport
   * @return Object&
   */
  Object &reportSet(std::function<void(std::string text)> fReport) {
    report.fReport = fReport;

    return *this;
  }

  /**
   * @brief Report holder
   *
   */
  Report report;
};

} // namespace abstract

} // namespace t_transfer
