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

#pragma once

#include "macros.hpp"
#include <exception>
#include <string>

namespace exc {

struct LogicError : std::exception {
    LogicError(int32_t error, std::string message)
            : error(error), message(message) {}

    const char *what() const throw() override { return message.c_str(); }

    int32_t error;
    std::string message;
};

} // namespace exc

