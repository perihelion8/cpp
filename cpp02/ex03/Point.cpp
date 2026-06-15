#include "Point.hpp"

Point::Point() : x_(0), y_(0) {}

Point::Point(const float x, const float y) : x_(x), y_(y) {}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}

Point& Point::operator=(const Point& other) {
  if (this != &other) {}
}