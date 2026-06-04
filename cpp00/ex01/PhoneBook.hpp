// Copyright 2026 by abazzoun

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
 public:
  PhoneBook();

  void AddContact();
  void SearchContacts();

 private:
  static const int kContactsSize_ = 8;
  static const int kTableFields_ = 3;

  Contact   contacts_[kContactsSize_];
  int       index_;
  bool      is_full_;

  void  DisplayContacts();
  void  DisplayContact(int index);
};

#endif // PHONEBOOK_HPP
