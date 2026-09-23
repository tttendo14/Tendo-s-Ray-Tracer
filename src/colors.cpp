#include "colors.hpp"

#include <iostream>

namespace color {

Color::Color(double red, double green, double blue)
    : red_(red), green_(green), blue_(blue) {}

double Color::red() const { return red_; }
double Color::green() const { return green_; }
double Color::blue() const { return blue_; }

Color Color::operator+(const Color &other) const {
  return {red_ + other.red_, green_ + other.green_, blue_ + other.blue_};
}

Color Color::operator-(const Color &other) const {
  return {red_ - other.red_, green_ - other.green_, blue_ - other.blue_};
}

Color Color::operator-() const { return {-red_, -green_, -blue_}; }

Color Color::operator*(double scalar) const {
  return {red_ * scalar, green_ * scalar, blue_ * scalar};
}

Color Color::operator*(const Color &other) const {
  return {red_ * other.red_, green_ * other.green_, blue_ * other.blue_};
}
Color Color::blend(const Color &other) const {
  return {red_ * other.red_, green_ * other.green_, blue_ * other.blue_};
}

void Color::print(std::string_view name) const {
  std::cout << name << ": red=" << red_ << ", green=" << green_
            << ", blue=" << blue_ << '\n';
}

Color operator*(double scalar, const Color &color) { return color * scalar; }

} // namespace color
