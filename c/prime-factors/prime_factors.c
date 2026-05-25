#include "prime_factors.h"
#include <math.h>

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]) {
  size_t len = 0;

  while (n % 2 == 0) {
    factors[len++] = 2;
    n /= 2;
  }

  for (size_t i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      factors[len++] = i;
      n /= i;
    }
  }

  if (n > 1) {
    factors[len++] = n;
  }

  return len;
}
