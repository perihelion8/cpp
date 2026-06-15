#include "PhoneBook.hpp"
#include <iostream>
#include "display.hpp"

PhoneBook::PhoneBook()
    : index_(0),
      is_full_(false),
      contacts_size_(8),
      table_fields_(3) {}

void PhoneBook::AddContact() {
  contacts_[index_].set_firstname(display::ReadName("firstname"));
  contacts_[index_].set_lastname(display::ReadName("lastname"));
  contacts_[index_].set_nickname(display::ReadName("nickname"));
  contacts_[index_].set_phonenumber(display::ReadPhonenumber());
  contacts_[index_].set_darksecret(display::ReadDarkSecret());
  if (index_ == contacts_size_ - 1) is_full_ = true;
  index_ = (index_ + 1) % contacts_size_;
}

void PhoneBook::SearchContacts() {
  if (is_full_ == false && index_ == 0) {
    display::DisplayBox("Empty Contacts :(");
    return;
  }

  DisplayContacts();
  int i = display::ReadIndex();
  if (i < 0 || (!is_full_ && i >= index_) || i >= contacts_size_) {
    std::cout << "Invalid index!" << std::endl;
    return;
  }
  DisplayContact(i);
  return;
}

void PhoneBook::DisplayContacts() {
  std::string row[table_fields_ + 1];
  row[0] = "index"; 
  row[1] = "firstname";
  row[2] = "lastname";
  row[3] = "nickname";
  display::DisplayRow(row);
  int count = is_full_ ? contacts_size_ : index_;
  for (int i = 0; i < count; ++i) {
    row[0] = std::string(1, char('0' + i));
    row[1] = contacts_[i].firstname();
    row[2] = contacts_[i].lastname();
    row[3] = contacts_[i].nickname();
    display::DisplayRow(row);
  }
}

void PhoneBook::DisplayContact(int index) {
  std::cout << "firstname: " << contacts_[index].firstname() << std::endl;
  std::cout << "lastname: " << contacts_[index].lastname() << std::endl;
  std::cout << "nickname: " << contacts_[index].nickname() << std::endl;
  std::cout << "phonenumber: " << contacts_[index].phonenumber() << std::endl;
  std::cout << "dark secret: " << contacts_[index].darksecret() << std::endl;
}
