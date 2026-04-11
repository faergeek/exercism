#include "grains.h"
#include <stdio.h>

uint64_t square(uint8_t index) {
  return index < 1 || index > 64 ? 0 : 1ull << (index - 1);
}

uint64_t total(void) { return -1; }
