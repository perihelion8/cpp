#include "PhoneBook.hpp"
#include <iostream>
#include "display.hpp"

int main() {
    PhoneBook   phonebook;
    std::string command;

    while (true) {
      std::cout << "> ";
      if (!(std::cin >> command)) {

        break;
      } 
      if (command == "ADD") {
          phonebook.AddContact(); 
      } else if (command == "SEARCH") {
          phonebook.SearchContacts();
      } else if (command == "EXIT") {
          display::DisplayBox("Goodbye!");
        break ;
      }
      else {
        std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
      }
    }
	return (0);
}
