#include "triangle.h"
#include <cstddef>
#include <stdexcept>

namespace triangle {

flavor kind(double a, double b, double c) {
  double sides[] = {a, b, c};
  for (size_t i = 0; i < 3; i++) {
    if (sides[i] <= 0 || sides[(i + 1) % 3] + sides[(i + 2) % 3] < sides[i]) {
      throw std::domain_error("not a triangle");
    }
  }

  if (a == b && b == c) {
    return flavor::equilateral;
  }

  if (a == b || b == c || c == a) {
    return flavor::isosceles;
  }

  return flavor::scalene;
}

} // namespace triangle
