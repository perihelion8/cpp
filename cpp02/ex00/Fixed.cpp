#include "Fixed.hpp"

Fixed::Fixed() : raw_bits_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed(const Fixed& other) {
  
}

int getRawBits() { return raw_bits_; }

