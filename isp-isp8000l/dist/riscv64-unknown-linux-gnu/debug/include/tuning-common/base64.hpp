//
//  base64 encoding and decoding with C++.
//  Version: 1.01.00
//

#pragma once

#include "error.hpp"
#include "exception.hpp"
#include <string>

namespace t_common {

/**
 * @brief Base64
 *
 */
struct Base64 {
  /**
   * @brief Decode from base64
   *
   * @param value
   * @return std::string
   */
  static std::string decode(std::string const &value);

  /**
   * @brief Decode from base64 base on type name
   *
   * @tparam T
   * @param value
   * @param object
   */
  template <typename T> static void decode(std::string const &value, T &object) {
    std::string decodedString = t_common::Base64::decode(value);

    if (decodedString.length() != sizeof(T)) {
      throw LogicError(RET_OUTOFRANGE,
                       "Base64 decode failed: object size not match");
    }

    std::copy(decodedString.begin(), decodedString.end(),
              reinterpret_cast<unsigned char *>(&object));
  }

  /**
   * @brief Decode base64 to text buffer
   *
   * @param value
   * @param ppBuffer
   * @param len
   */
  static void decode(std::string const &value, unsigned char **ppBuffer,
                     unsigned int &len);

  /**
   * @brief Decode base64 to bin buffer
   *
   * @param value
   * @param ppBuffer
   * @param len
   */
  static void decode(std::string const &value, void **ppBuffer,
                     unsigned int &len);

  /**
   * @brief Decode base64 base on type name
   *
   * @tparam T
   * @param value
   * @return T
   */
  template <typename T> static T decode(std::string const &value) {
    T object;

    decode(value, object);

    return object;
  }

  /**
   * @brief Encode text buffer to base64
   *
   * @param pBuffer
   * @param len
   * @return std::string
   */
  static std::string encode(unsigned char const *pBuffer, unsigned int len);

  /**
   * @brief Encode bin buffer to base64
   *
   * @param pBuffer
   * @param len
   * @return std::string
   */
  static std::string encode(void const *pBuffer, unsigned int len);

  /**
   * @brief Encode object to base64
   *
   * @tparam T
   * @param object
   * @param value
   */
  template <typename T> static void encode(T object, std::string &value) {
    value =
        Base64::encode(reinterpret_cast<unsigned char *>(&object), sizeof(T));
  }

  /**
   * @brief Encode object to base64
   *
   * @tparam T
   * @param object
   * @return std::string
   */
  template <typename T> static std::string encode(T object) {
    return Base64::encode(reinterpret_cast<unsigned char *>(&object),
                          sizeof(T));
  }
};

} // namespace t_common
