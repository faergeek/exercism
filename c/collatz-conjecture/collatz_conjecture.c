#include "collatz_conjecture.h"

int steps(int n) {
  if (n < 1)
    return ERROR_VALUE;

  int result = 0;

  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }

    result++;
  }

  return result;
}
