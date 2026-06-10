#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
 public:
   Fixed();
   ~Fixed();

   int getRawBits() const;
   void setRawBits(int const raw);

 private:
   static const int kNumberOfFractionalBits_ = 8;

   int integer_;

};

#endif
