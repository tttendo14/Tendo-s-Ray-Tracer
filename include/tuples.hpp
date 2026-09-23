#pragma once

#include <string_view>

namespace tuple {

class Tuple {
public:
  Tuple(double x, double y, double z, double w);
  Tuple(double x, double y, double z);

  [[nodiscard]] double x() const;
  [[nodiscard]] double y() const;
  [[nodiscard]] double z() const;
  [[nodiscard]] double w() const;

  [[nodiscard]] bool isPoint() const;
  [[nodiscard]] bool isVector() const;

  [[nodiscard]] double magnitude() const;
  [[nodiscard]] Tuple normalize() const;

  [[nodiscard]] Tuple operator+(const Tuple &other) const;
  [[nodiscard]] Tuple operator-(const Tuple &other) const;
  [[nodiscard]] Tuple operator-() const;
  [[nodiscard]] Tuple operator*(double scalar) const;
  [[nodiscard]] Tuple operator/(double scalar) const;

  [[nodiscard]] Tuple add(const Tuple &other) const;
  [[nodiscard]] Tuple subtract(const Tuple &other) const;
  [[nodiscard]] Tuple scale(double scalar) const;
  [[nodiscard]] Tuple divide(double scalar) const;

  [[nodiscard]] double dot(const Tuple &other) const;
  [[nodiscard]] Tuple cross(const Tuple &other) const;

  void print(std::string_view name) const;

private:
  double x_, y_, z_, w_;
};

[[nodiscard]] Tuple point(double x, double y, double z);
[[nodiscard]] Tuple vector(double x, double y, double z);

[[nodiscard]] Tuple operator*(const double &scalar, const Tuple &a);

} // namespace tuple
