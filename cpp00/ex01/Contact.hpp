#pragma once

#include <string>

class Contact {
 public:
  enum Field {
    kFirstName,
    kLastName,
    kNickName,
    kPhoneNumber,
    kDarkSecret,
    kFieldCount
  };

  static const std::string  kFieldNames[kFieldCount];

  const std::string&        field(Field field) const;
  void                      set_field(Field field, const std::string& value);

 private:
  std::string fields_[kFieldCount];
};
