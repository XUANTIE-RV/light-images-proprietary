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
 * @file impexinfo.h
 *
 * @brief
 *   Image info for import/export C++ API.
 *
 *****************************************************************************/
/**
 *
 * @mainpage Module Documentation
 *
 *
 * Doc-Id: xx-xxx-xxx-xxx (NAME Implementation Specification)\n
 * Author: NAME
 *
 * DESCRIBE_HERE
 *
 *
 * The manual is divided into the following sections:
 *
 * -@subpage module_name_api_page \n
 * -@subpage module_name_page \n
 *
 * @page module_name_api_page Module Name API
 * This module is the API for the NAME. DESCRIBE IN DETAIL / ADD USECASES...
 *
 * for a detailed list of api functions refer to:
 * - @ref module_name_api
 *
 * @defgroup module_name_api Module Name API
 * @{
 */

#pragma once

#include <list>
#include <map>
#include <string>

class Tag {
public:
  enum Type {
    TYPE_INVALID = 0,
    TYPE_BOOL = 1,
    TYPE_INT = 2,
    TYPE_UINT32 = 3,
    TYPE_FLOAT = 4,
    TYPE_STRING = 5
  };

protected:
  Tag(Type type, const std::string &id) : type(type), id(id) {}
  virtual ~Tag() {}

public:
  Type getType() const { return type; };
  std::string getId() const { return id; };

  template <class T> bool getValue(T &) const;
  template <class T> bool setValue(const T &);

  virtual std::string toString() const = 0;
  virtual void fromString(const std::string &) = 0;

private:
  friend class TagMap;

  Type type;
  std::string id;
};

class TagMap {
public:
  typedef std::list<Tag *>::const_iterator const_tag_iterator;
  typedef std::map<std::string, std::list<Tag *>>::const_iterator
      const_category_iterator;

public:
  TagMap();
  ~TagMap();

private:
  TagMap(const TagMap &);
  TagMap &operator=(const TagMap &);

public:
  void clear();
  bool containes(const std::string &,
                 const std::string & = std::string()) const;
  template <class T>
  void insert(const T &, const std::string &,
              const std::string & = std::string());
  void remove(const std::string &, const std::string & = std::string());

  Tag *tag(const std::string &, const std::string & = std::string()) const;

  const_category_iterator begin() const;
  const_category_iterator end() const;

  const_tag_iterator begin(const_category_iterator) const;
  const_tag_iterator end(const_category_iterator) const;

private:
  typedef std::list<Tag *>::iterator tagIterator;
  typedef std::map<std::string, std::list<Tag *>>::iterator categoryIterator;

  std::map<std::string, std::list<Tag *>> data;
};

/**
 * @brief ImageExportInfo class declaration.
 */
class ImageExportInfo : public TagMap {
public:
  ImageExportInfo(std::string);
  ~ImageExportInfo();

public:
  void write() const;

private:
  std::string filename;
};

/* @} module_name_api*/
