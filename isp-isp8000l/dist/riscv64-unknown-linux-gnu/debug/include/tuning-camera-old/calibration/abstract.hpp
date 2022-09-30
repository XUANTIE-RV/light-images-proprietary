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

#include <tuning-camera-old-config.hpp>

#include <tuning-common/common.hpp>

#include "section-name.hpp"
#include <algorithm>
#include <tinyxml2.h>

#include <cam_engine/cam_engine_api.h>

#include <cam_engine/cam_engine_aaa_api.h>
#include <cam_engine/cam_engine_cproc_api.h>
#include <cam_engine/cam_engine_imgeffects_api.h>
#include <cam_engine/cam_engine_isp_api.h>
#include <cam_engine/cam_engine_jpe_api.h>
#include <cam_engine/cam_engine_mi_api.h>
#include <cam_engine/cam_engine_simp_api.h>

using namespace tinyxml2;

namespace clb {

struct Abstract {
  Abstract(XMLDocument &document, std::string name = std::string());
  virtual ~Abstract();

  virtual void compose(XMLElement &);

  virtual void composeAttributes(XMLElement &);
  virtual void composeSubElements(XMLElement &);

  virtual void parse(XMLElement &);

  virtual void parseAttributes(XMLElement &);
  virtual void parseSubElements(XMLElement &);

  XMLElement *subElementGet(XMLElement &element, char const *pKey,
                            std::string &value);

  XMLElement *subElementGet(XMLElement &element, char const *pKey,
                            int16_t &value);

  XMLElement *subElementGet(XMLElement &element, char const *pKey,
                            int32_t &value);

  XMLElement *subElementGet(XMLElement &element, char const *pKey,
                            uint8_t &value);

  XMLElement *subElementGet(XMLElement &element, char const *pKey,
                            uint16_t &value);

  XMLElement *subElementGet(XMLElement &element, char const *pKey,
                            uint32_t &value);

  XMLElement *subElementGet(XMLElement &element, char const *pKey,
                            double &value);

  XMLElement *subElementGet(XMLElement &element, char const *pKey,
                            float &value);

  XMLElement *subElementGet(XMLElement &element, char const *pKey, bool &value);

  XMLElement *subElementGet(XMLElement &element, char const *pKey,
                            Json::Value &value);

  template <typename Func>
  XMLElement *subElementProc(XMLElement &element, char const *pKey, Func f) {
    XMLElement *pSubElement = nullptr;

    if (!(pSubElement = element.FirstChildElement(pKey))) {
      element.InsertEndChild(pSubElement = document.NewElement(pKey));
    }

    f(*pSubElement);

    return pSubElement;
  }

  template <typename T>
  XMLElement *subElementSet(XMLElement &element, char const *pKey, T value) {
    XMLElement *pSubElement = nullptr;

    if (!(pSubElement = element.FirstChildElement(pKey))) {
      element.InsertEndChild(pSubElement = document.NewElement(pKey));
    }

    pSubElement->SetText(value);

    return pSubElement;
  }

  XMLElement *subElementSet(XMLElement &element, char const *pKey,
                            std::string value);

  XMLElement *subElementSet(XMLElement &element, char const *pKey,
                            Json::Value value);

  XMLDocument &document;
  std::string name;
  int32_t level = 0;
};

} // namespace clb
