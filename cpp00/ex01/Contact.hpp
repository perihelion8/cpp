#pragma once

#include <string>

class Contact {
 public:
   const std::string& first_name();
   const std::string& last_name();
   const std::string& nick_name();
   const std::string& phone_number();
   const std::string& dark_secret();

   void set_first_name(const std::string& first_name);
   void set_last_name(const std::string& last_name);
   void set_nick_name(const std::string& nick_name);
   void set_phone_number(const std::string& phone_number);
   void set_dark_secret(const std::string& dark_secret);

 private:
  std::string first_name_;
  std::string last_name_;
  std::string nick_name_;
  std::string phone_number_;
  std::string dark_secret_;
};
