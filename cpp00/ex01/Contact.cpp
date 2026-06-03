#include "Contact.hpp"
#include <string>

const std::string Contact::kFieldNames[] = {
  "firstname",
  "lastname",
  "nickname",
  "phonenumber",
  "darksecret"
};

const std::string& Contact::field(Field field) const { return fields_[field]; }

void Contact::set_field(Field field, const std::string& value) {
  fields_[field] = value;
}
