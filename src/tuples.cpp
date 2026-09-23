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

Tuple Tuple::operator+(const Tuple &other) const {
  return Tuple{x_ + other.x_, y_ + other.y_, z_ + other.z_, w_ + other.w_};
}
Tuple Tuple::operator-(const Tuple &other) const {
  return Tuple{x_ - other.x_, y_ - other.y_, z_ - other.z_, w_ - other.w_};
}

Tuple Tuple::operator-() const { return Tuple{-x_, -y_, -z_, -w_}; }

Tuple Tuple::operator*(double scalar) const {
  return Tuple{x_ * scalar, y_ * scalar, z_ * scalar, w_ * scalar};
}
Tuple operator*(const double &scalar, const Tuple &a) { return a * scalar; }
Tuple Tuple::operator/(double scalar) const {
  return Tuple{x_ / scalar, y_ / scalar, z_ / scalar, w_ / scalar};
}

Tuple Tuple::add(const Tuple &other) const { return *this + other; }

Tuple Tuple::subtract(const Tuple &other) const { return *this - other; }

Tuple Tuple::scale(double scalar) const { return *this * scalar; }

Tuple Tuple::divide(double scalar) const { return *this / scalar; }

double Tuple::dot(const Tuple &other) const {
  return x_ * other.x_ + y_ * other.y_ + z_ * other.z_ + w_ * other.w_;
}
Tuple Tuple::cross(const Tuple &other) const {
  return vector(y_ * other.z_ - z_ * other.y_,
                z_ * other.x_ - x_ * other.z_,
                x_ * other.y_ - y_ * other.x_);
}
} // namespace tuple
