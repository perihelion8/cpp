#include "Contact.hpp"
#include <string>

const std::string& Contact::firstname() { return firstname_; }
const std::string& Contact::lastname() { return lastname_; }
const std::string& Contact::nickname() { return nickname_; }
const std::string& Contact::phonenumber() { return phonenumber_; }
const std::string& Contact::darksecret() { return darksecret_; }

void Contact::set_firstname(const std::string& firstname) { firstname_ = firstname; }
void Contact::set_lastname(const std::string& lastname) { lastname_ = lastname; }
void Contact::set_nickname(const std::string& nickname) { nickname_ = nickname; }
void Contact::set_phonenumber(const std::string& phonenumber) { phonenumber_ = phonenumber; }
void Contact::set_darksecret(const std::string& darksecret) { darksecret_ = darksecret; }
