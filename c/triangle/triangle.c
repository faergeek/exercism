#include "triangle.h"
#include <stddef.h>

static bool is_a_triangle(triangle_t sides) {
  double lengths[] = {sides.a, sides.b, sides.c};

  for (size_t i = 0; i < 3; i++) {
    if (lengths[i] <= 0) {
      return false;
    }

    double sum = 0;
    for (size_t j = 1; j < 3; j++) {
      sum += lengths[(i + j) % 3];
    }

    if (lengths[i] > sum) {
      return false;
    }
  }

  return true;
}

bool is_equilateral(triangle_t sides) {
  return is_a_triangle(sides) && sides.a == sides.b && sides.b == sides.c;
}

bool is_isosceles(triangle_t sides) {
  return is_a_triangle(sides) &&
         (sides.a == sides.b || sides.b == sides.c || sides.c == sides.a);
}

bool is_scalene(triangle_t sides) {
  return is_a_triangle(sides) && sides.a != sides.b && sides.b != sides.c &&
         sides.c != sides.a;
}
