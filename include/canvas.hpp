#pragma once

#include "colors.hpp"
#include <vector>

namespace canvas {

class Canvas {
public:
  Canvas(int width, int height);

  [[nodiscard]] color::Color getPixel(int w, int h) const;
  void setPixel(int w, int h, color::Color c);

private:
  int width, height;
  std::vector<color::Color> pixels;
};

} // namespace canvas
