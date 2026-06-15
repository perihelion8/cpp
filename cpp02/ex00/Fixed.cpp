#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : raw_bits_(0) {
  std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const Fixed& other) : raw_bits_(other.raw_bits_) {
  std::cout << "Copy constructor called" << std::endl; 
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl; 
  if (this != &other) raw_bits_ = other.getRawBits();
  return (*this);
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return raw_bits_;
}

void Fixed::setRawBits(int const raw) {
  raw_bits_ = raw;
}
