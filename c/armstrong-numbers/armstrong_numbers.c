#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate) {
  int power = 1;
  while (pow(10, power) <= candidate) {
    power++;
  }

  int sum = 0;
  for (int n = candidate; n > 0; n /= 10) {
    sum += pow(n % 10, power);
  }

  return sum == candidate;
}
