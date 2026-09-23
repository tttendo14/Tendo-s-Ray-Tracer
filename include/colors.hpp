#pragma once

#include <string_view>

namespace color {

class Color {
public:
  Color(double red, double green, double blue);

  [[nodiscard]] double red() const;
  [[nodiscard]] double green() const;
  [[nodiscard]] double blue() const;

  [[nodiscard]] Color operator+(const Color &other) const;
  [[nodiscard]] Color operator-(const Color &other) const;
  [[nodiscard]] Color operator-() const;
  [[nodiscard]] Color operator*(double scalar) const;
  [[nodiscard]] Color operator*(const Color &other) const;

  [[nodiscard]] Color blend(const Color &other) const;

  void print(std::string_view name) const;

private:
  double red_, green_, blue_;
};

[[nodiscard]] Color operator*(double scalar, const Color &color);

} // namespace color
