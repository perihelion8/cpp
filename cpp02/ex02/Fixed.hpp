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

	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed& operator++();
	Fixed operator++(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

 private:
  int raw_bits_;
  static int const kFractionalBits_ = 8;

};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
