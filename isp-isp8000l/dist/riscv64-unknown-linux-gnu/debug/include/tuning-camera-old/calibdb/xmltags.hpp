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

#include <string>
#include <tinyxml2.h>

using namespace tinyxml2;

class XmlTag {
public:
  enum TagType_e {
    TAG_TYPE_INVALID = 0,
    TAG_TYPE_CHAR,
    TAG_TYPE_DOUBLE,
    TAG_TYPE_STRUCT,
    TAG_TYPE_CELL,
    TAG_TYPE_MAX
  };

  XmlTag(XMLElement const *);

  int32_t size();
  char const *value();
  char const *valueToUpper();
  uint32_t valueToUInt();

  TagType_e type();
  bool isType(const TagType_e);

protected:
  XMLElement const *_pElement;
};

struct XmlCellTag : XmlTag {
  XmlCellTag(XMLElement const *);

  int32_t Index();
};
