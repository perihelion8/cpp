#ifndef VALIDATE_HPP
#define VALIDATE_HPP

#include <string>

namespace validate {

  bool IsNotEmpty(const std::string& str);
  bool IsValidLength(const std::string& str, size_t max_len);
  bool IsAlphaString(const std::string& str);
  bool IsAllDigit(const std::string& str);
  bool IsValidName(const std::string& str);
  bool IsValidPhonenumber(const std::string& str);
  bool IsValidDarkSecret(const std::string& str);

}

#endif // VALIDATE_HPP
