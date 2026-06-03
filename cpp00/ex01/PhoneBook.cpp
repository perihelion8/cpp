#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include "display.hpp"

PhoneBook::PhoneBook() {
  index_ = 0;
  is_full_ = false;
}

void PhoneBook::AddContact() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::string value;
  for (int i = 0; i < Contact::kFieldCount; ++i) {
    std::cout << Contact::kFieldNames[i] << ": ";
    std::getline(std::cin, value);
    contacts_[index_].set_field(static_cast<Contact::Field>(i), value);
  }

  index_ = (index_ + 1) % kMaxContacts_;
  if (index_ == 0) is_full_ = true;
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
  for (int i = 0; i < kTableFields_; ++i)
    row[i + 1] = Contact::kFieldNames[i];
  display::DisplayRow(row);

  int count = is_full_ ? kMaxContacts_ : index_;
  for (int i = 0; i < count; ++i) {
    row[0] = std::string(1, char('0' + i));
    for (int j = 0; j < kTableFields_; ++j)
      row[j + 1] = contacts_[i].field(static_cast<Contact::Field>(j));
    display::DisplayRow(row);
  }
}

void PhoneBook::DisplayContact(int index) {
  std::string info;
  for (int j = 0; j < Contact::kFieldCount; ++j) {
    info += Contact::kFieldNames[j] + ": ";
    info += contacts_[index].field(static_cast<Contact::Field>(j)) + "\n";
  }

  display::DisplayBox(info);
}
