#pragma once

#include <string>

class Contact {
 public:
   const std::string& firstname();
   const std::string& lastname();
   const std::string& nickname();
   const std::string& phonenumber();
   const std::string& darksecret();

   void set_firstname(const std::string& firstname);
   void set_lastname(const std::string& lastname);
   void set_nickname(const std::string& nickname);
   void set_phonenumber(const std::string& phonenumber);
   void set_darksecret(const std::string& darksecret);

 private:
  std::string firstname_;
  std::string lastname_;
  std::string nickname_;
  std::string phonenumber_;
  std::string darksecret_;
};
