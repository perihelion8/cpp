#ifndef VALIDATE_HPP
#define VALIDATE_HPP

namespace validate {

  bool validate::IsNotEmpty(const std::string& str);
  bool validate::IsValidLength(const std::string& str, size_t max_len);
  bool validate::IsAlphaString(const std::string& str);
  bool validate::IsAllDigit(const std::string& str);
  bool validate::IsValidName(const std::string& str);
  bool validate::IsValidPhoneNumber(const std::string& str);
  bool validate::IsValidDarkSecret(const std::string& str);

}

#endif // VALIDATE_HPP
