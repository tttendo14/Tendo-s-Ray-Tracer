#pragma once

#include <string_view>

namespace tuple {

class Tuple {
public:
  Tuple(double x, double y, double z, double w);

  [[nodiscard]] double x() const;
  [[nodiscard]] double y() const;
  [[nodiscard]] double z() const;
  [[nodiscard]] double w() const;

  [[nodiscard]] bool isPoint() const;
  [[nodiscard]] bool isVector() const;

  [[nodiscard]] double magnitude() const;
  [[nodiscard]] Tuple normalize() const;

  void print(std::string_view name) const;

private:
  double x_, y_, z_, w_;
};

[[nodiscard]] Tuple point(double x, double y, double z);
[[nodiscard]] Tuple vector(double x, double y, double z);

[[nodiscard]] Tuple operator+(const Tuple &a, const Tuple &b);
[[nodiscard]] Tuple operator-(const Tuple &a, const Tuple &b);

[[nodiscard]] Tuple operator-(const Tuple &a);

[[nodiscard]] Tuple operator*(const Tuple &a, const double &scalar);
[[nodiscard]] Tuple operator*(const double &scalar, const Tuple &a);
[[nodiscard]] Tuple operator/(const Tuple &a, const double &scalar);

[[nodiscard]] double dot(const Tuple &a, const Tuple &b);
[[nodiscard]] Tuple cross(const Tuple &a, const Tuple &b);

} // namespace tuple
