#include "sieve.h"
#include <stdlib.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
  if (limit < 2)
    return 0;

  uint32_t size = limit - 1;
  uint32_t *arr = malloc(size * sizeof(uint32_t));
  for (uint32_t i = 0; i < size; i++) {
    arr[i] = i + 2;
  }

  for (uint32_t i = 0; i < size; i++) {
    uint32_t n = arr[i];

    if (n) {
      for (uint32_t j = n + n - 2; j < size; j += n) {
        arr[j] = 0;
      }
    }
  }

  uint32_t count = 0;
  uint32_t j = 0;
  for (uint32_t i = 0; i < size; i++) {
    if (arr[i] == 0)
      continue;

    primes[j] = arr[i];
    count++;
    j++;

    if (count == max_primes)
      break;
  }

  free(arr);

  return count;
}
