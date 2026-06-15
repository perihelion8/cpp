#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : raw_bits_(0) {}

Fixed::Fixed(const int n) : raw_bits_(n << kFractionalBits_) {}

Fixed::Fixed(const float f)
    : raw_bits_(static_cast<int>(roundf(f * (1 << kFractionalBits_)))) {}

Fixed::Fixed(const Fixed& other) : raw_bits_(other.raw_bits_) {}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) raw_bits_ = other.getRawBits();
  return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return raw_bits_; }

void Fixed::setRawBits(int const raw) { raw_bits_ = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(raw_bits_) / (1 << kFractionalBits_);
}

int Fixed::toInt(void) const {
  return raw_bits_ >> kFractionalBits_;
}

bool Fixed::operator>(const Fixed& other) const {
  return raw_bits_ > other.raw_bits_;
}

bool Fixed::operator<(const Fixed& other) const {
  return raw_bits_ < other.raw_bits_;
}

bool Fixed::operator>=(const Fixed& other) const {
  return raw_bits_ >= other.raw_bits_;
}

bool Fixed::operator<=(const Fixed& other) const {
  return raw_bits_ <= other.raw_bits_;
}

bool Fixed::operator==(const Fixed& other) const {
  return raw_bits_ == other.raw_bits_;
}

bool Fixed::operator!=(const Fixed& other) const {
  return raw_bits_ != other.raw_bits_;
}

Fixed Fixed::operator+(const Fixed& other) const {
  return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
  return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
  return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
  return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
  raw_bits_ += 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed copy(*this);
  raw_bits_ += 1;
  return copy;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
  return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
  return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
    return out << obj.toFloat();
}
