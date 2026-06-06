#include "validate.hpp"

namespace validate {

  bool IsNotEmpty(const std::string& str) {
    return !str.empty();
  }

  bool IsValidLength(const std::string& str, size_t max_len) {
    return str.length() <= max_len;
  }

  bool IsAlphaString(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
      if (!std::isalpha(static_cast<unsigned char>(str[i])))
        return false;
    }
    return true;
  }

  bool IsAllDigit(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
      if (!std::isdigit(static_cast<unsigned char>(str[i])))
        return false;
    }
    return true;
  }

  bool IsValidName(const std::string& str) {
    if (!IsNotEmpty(str)) return false;
    if (!IsValidLength(str, 20)) return false;
    if (!IsAlphaString(str)) return false;
    return true;
  }

  bool IsValidPhonenumber(const std::string& str) {
    if (!IsNotEmpty(str)) return false;
    if (str.length() != 8) return false;
    if (!IsAllDigit(str)) return false;
    return true;
  }

  bool IsValidDarkSecret(const std::string& str) {
    if (!IsNotEmpty(str)) return false;
    if (!IsValidLength(str, 100)) return false;
    return true;
  }

}
