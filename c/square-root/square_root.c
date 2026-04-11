#include "square_root.h"

uint16_t square_root(uint64_t radicand) {
  float x = (float)radicand / 16;

  while ((uint16_t)x * (uint16_t)x != radicand) {
    x = 0.5 * (x + radicand / x);
  }

  return x;
}
