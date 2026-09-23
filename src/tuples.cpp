#include "tuples.hpp"
#include "float_compare.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace tuple {
Tuple::Tuple(double x, double y, double z, double w)
    : x_(x), y_(y), z_(z), w_(w) {}

double Tuple::x() const { return x_; }
double Tuple::y() const { return y_; }
double Tuple::z() const { return z_; }
double Tuple::w() const { return w_; }

bool Tuple::isPoint() const { return math::equal(w_, 1.0); }
bool Tuple::isVector() const { return math::equal(w_, 0.0); }

double Tuple::magnitude() const {
  return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_);
}

Tuple Tuple::normalize() const {
  const double length = magnitude();
  if (math::equal(length, 0.0)) {
    throw std::domain_error("Cannot normalize a zero-length tuple");
  }
  return *this / length;
}

void Tuple::print(std::string_view name) const {
  const char *type = isPoint() ? "point" : isVector() ? "vector" : "tuple";
  std::cout << name << " (" << type << "): x=" << x_ << ", y=" << y_
            << ", z=" << z_ << ", w=" << w_ << '\n';
}

Tuple point(double x, double y, double z) { return Tuple{x, y, z, 1.0}; }
Tuple vector(double x, double y, double z) { return Tuple{x, y, z, 0.0}; }

Tuple operator+(const Tuple &a, const Tuple &b) {
  return Tuple{a.x() + b.x(), a.y() + b.y(), a.z() + b.z(), a.w() + b.w()};
}
Tuple operator-(const Tuple &a, const Tuple &b) {
  return Tuple{a.x() - b.x(), a.y() - b.y(), a.z() - b.z(), a.w() - b.w()};
}

Tuple operator-(const Tuple &a) {
  return Tuple{-a.x(), -a.y(), -a.z(), -a.w()};
}

Tuple operator*(const Tuple &a, const double &scalar) {
  return Tuple{a.x() * scalar, a.y() * scalar, a.z() * scalar, a.w() * scalar};
}
Tuple operator*(const double &scalar, const Tuple &a) { return a * scalar; }
Tuple operator/(const Tuple &a, const double &scalar) {
  return Tuple{a.x() / scalar, a.y() / scalar, a.z() / scalar, a.w() / scalar};
}

double dot(const Tuple &a, const Tuple &b) {
  return a.x() * b.x() + a.y() * b.y() + a.z() * b.z() + a.w() * b.w();
}
Tuple cross(const Tuple &a, const Tuple &b) {
  return vector(a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(),
                a.x() * b.y() - a.y() * b.x());
}
} // namespace tuple
