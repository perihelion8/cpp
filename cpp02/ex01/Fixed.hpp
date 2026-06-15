#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
 public:
  Fixed();
  Fixed(const int n);
  Fixed(const float f);
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);

  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

 private:
  int raw_bits_;
  static int const kFractionalBits_ = 8;

};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
