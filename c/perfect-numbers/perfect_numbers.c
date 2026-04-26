#include "perfect_numbers.h"
#include <stddef.h>

kind classify_number(int number) {
  if (number < 1) {
    return ERROR;
  }

  if (number == 1) {
    return DEFICIENT_NUMBER;
  }

  int aliquot_sum = number == 1 ? 0 : 1;

  size_t divisor = 2;
  size_t quotient = number / divisor;
  size_t remainder = number % divisor;

  while (quotient >= divisor) {
    if (remainder == 0) {
      aliquot_sum += divisor;

      if (quotient != divisor) {
        aliquot_sum += quotient;
      }

      if (aliquot_sum > number) {
        return ABUNDANT_NUMBER;
      }
    }

    divisor++;
    quotient = number / divisor;
    remainder = number % divisor;
  }

  if (aliquot_sum < number) {
    return DEFICIENT_NUMBER;
  }

  return PERFECT_NUMBER;
}
