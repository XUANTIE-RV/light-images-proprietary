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

/**
 * @file xmltags.h
 *
 *****************************************************************************/
#pragma once

#include <string>
#include <tinyxml2/tinyxml2_ry.h>

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

  XmlTag(const XMLElement *);

  int32_t size();
  const char *value();
  const char *valueToUpper();
  uint32_t valueToUInt();

  TagType_e type();
  bool isType(const TagType_e);

protected:
  const XMLElement *_pElement;
};

class XmlCellTag : public XmlTag {
public:
  XmlCellTag(const XMLElement *);

  int32_t Index();
};
