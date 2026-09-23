#include "canvas.hpp"

#include <iostream>
#include <stdexcept>

namespace canvas {
namespace {

std::size_t validatedDimension(int dimension) {
  if (dimension < 0) {
    throw std::invalid_argument("Canvas dimensions cannot be negative");
  }
  return static_cast<std::size_t>(dimension);
}

} // namespace

Canvas::Canvas(int width, int height)
    : width(width), height(height),
      pixels(validatedDimension(width) * validatedDimension(height),
             color::Color{0, 0, 0}) {}

color::Color Canvas::getPixel(int w, int h) const {
  if (w < 0 || w >= width || h < 0 || h >= height) {
    std::cerr << "Pixel coordinates out of range\n";
    return {0, 0, 0};
  }
  return pixels[static_cast<std::size_t>(h) * static_cast<std::size_t>(width) +
                static_cast<std::size_t>(w)];
}

void Canvas::setPixel(int w, int h, color::Color c) {
  if (w < 0 || w >= width || h < 0 || h >= height) {
    std::cerr << "Pixel coordinates out of range\n";
    return;
  }
  pixels[static_cast<std::size_t>(h) * static_cast<std::size_t>(width) +
         static_cast<std::size_t>(w)] = c;
}

} // namespace canvas
