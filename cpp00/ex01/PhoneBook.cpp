#include "PhoneBook.hpp"
#include <iostream>
#include "display.hpp"

PhoneBook::PhoneBook() {
  index_ = 0;
  is_full_ = false;
}

void PhoneBook::AddContact() {
  contacts_[index_].set_first_name(display::DisplayForAdd("first name"));
  contacts_[index_].set_last_name(display::DisplayForAdd("last name"));
  contacts_[index_].set_nick_name(display::DisplayForAdd("nick name"));
  contacts_[index_].set_phone_number(display::DisplayForAdd("phone number"));
  contacts_[index_].set_dark_secret(display::DisplayForAdd("dark secret"));
  index_ = (index_ + 1) % kContactsSize_;
  if (is_full_ == false && index_ == 0) is_full_ = true;
}

void PhoneBook::SearchContacts() {
  if (is_full_ == false && index_ == 0) {
    display::DisplayBox("Empty Contacts :(");
    return;
  }
  DisplayContacts();
  std::cout << "Enter index: ";
  std::string input;
  if (!(std::cin >> input) || input.size() != 1 ||
      input[0] < '0' || input[0] >= '0' + index_) {
    std::cout << "Invalid index." << std::endl;
    return;
  }
  DisplayContact(input[0] - '0');
}

void PhoneBook::DisplayContacts() {
  std::string row[kTableFields_ + 1];
  row[0] = "index"; 
  row[1] = "first name";
  row[2] = "last name";
  row[3] = "nick name";
  display::DisplayRow(row);
  int count = is_full_ ? kContactsSize_ : index_;
  for (int i = 0; i < count; ++i) {
    row[0] = std::string(1, char('0' + i));
    row[1] = contacts_[i].first_name();
    row[2] = contacts_[i].last_name();
    row[3] = contacts_[i].nick_name();
    display::DisplayRow(row);
  }
}

void PhoneBook::DisplayContact(int index) {
  std::cout << "first name: " << contacts_[index].first_name() << std::endl;
  std::cout << "last name: " << contacts_[index].last_name() << std::endl;
  std::cout << "nick name: " << contacts_[index].nick_name() << std::endl;
  std::cout << "phone number: " << contacts_[index].phone_number() << std::endl;
  std::cout << "dark secret: " << contacts_[index].dark_secret() << std::endl;
}
