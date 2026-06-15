#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : raw_bits_(0) {
  std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const int n) : raw_bits_(n << kFractionalBits_) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
    : raw_bits_(static_cast<int>(roundf(f * (1 << kFractionalBits_)))) {
  std::cout << "Float constructor called" << std::endl;
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

float Fixed::toFloat(void) const {
  return static_cast<float>(raw_bits_) / (1 << kFractionalBits_);
}

int Fixed::toInt(void) const {
  return raw_bits_ >> kFractionalBits_;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
    out << obj.toFloat();
    return out;
}
