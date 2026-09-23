#pragma once

#include <cmath>

namespace math {
inline constexpr double EPS = 1e-5;

[[nodiscard]] inline bool equal(double a, double b) {
  return std::abs(a - b) < EPS;
}

} // namespace math
