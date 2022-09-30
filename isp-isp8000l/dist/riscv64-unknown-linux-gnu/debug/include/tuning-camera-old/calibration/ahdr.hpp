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

#include "abstract.hpp"

namespace clb {

struct Ahdr : Abstract {
  Ahdr(XMLDocument &);

  void composeAttributes(XMLElement &) override;
  void composeSubElements(XMLElement &) override;

  void parseAttributes(XMLElement &) override;
  void parseSubElements(XMLElement &) override;

  enum Generation { V1, VMax };

  union Config {
    struct V1 {
      void reset();

      bool isAuto;
      bool isAutoSetPoint;
      bool isAutoSetPoint2;

      double c, c2, ceil, objectFector, setPoint2;

      uint8_t tolerance;

      struct {
        double max, min;
      } ratio;
    } v1;
  };

  struct Table {
    enum Column {
      V1Gain,
      V1IntegrationTime,
      V1SetPointScale,
      V1SetPoint2Scale,
      V1C,
      V1C2,
      V1Ceil,
    };

    void reset(Generation generation);

    Json::Value jTable;
  };

  struct Holder {
    bool isEnable;

    Config config;
    Table table;
  };

  std::vector<Holder> holders;
};

} // namespace clb
