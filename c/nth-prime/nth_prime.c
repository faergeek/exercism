#include "nth_prime.h"
#include <math.h>
#include <stdbool.h>

uint32_t nth(uint32_t n) {
  if (n < 1) {
    return 0;
  }

  uint32_t prime_index = 1;
  uint32_t i = 2;
  while (prime_index < n) {
    i++;

    bool is_prime = true;
    uint32_t end = sqrtf(i);
    for (uint32_t j = 2; j <= end; j++) {
      if (i % j == 0) {
        is_prime = false;
        break;
      }
    }

    if (is_prime) {
      prime_index++;
    }
  }

  return i;
}
