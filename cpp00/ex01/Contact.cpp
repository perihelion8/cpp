#include "Contact.hpp"
#include <string>

const std::string& Contact::first_name() { return first_name_; }
const std::string& Contact::last_name() { return last_name_; }
const std::string& Contact::nick_name() { return nick_name_; }
const std::string& Contact::phone_number() { return phone_number_; }
const std::string& Contact::dark_secret() { return dark_secret_; }

void Contact::set_first_name(const std::string& first_name) { first_name_ = first_name; }
void Contact::set_last_name(const std::string& last_name) { last_name_ = last_name; }
void Contact::set_nick_name(const std::string& nick_name) { nick_name_ = nick_name; }
void Contact::set_phone_number(const std::string& phone_number) { phone_number_ = phone_number; }
void Contact::set_dark_secret(const std::string& dark_secret) { dark_secret_ = dark_secret; }
