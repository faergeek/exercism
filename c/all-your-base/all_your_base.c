#include "all_your_base.h"
#include <stdlib.h>

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base,
              int16_t output_base, size_t input_length) {
  if (input_length < 1 || input_base <= 1 || output_base <= 1) {
    return 0;
  }

  for (size_t i = 0; i < input_length; i++) {
    if (digits[i] < 0 || digits[i] >= input_base) {
      return 0;
    }
  }

  int32_t n = 0;
  for (int32_t i = input_length - 1, m = 1; i >= 0; i--, m *= input_base) {
    n += digits[i] * m;
  }

  size_t output_length = 1;
  for (int32_t m = output_base; m <= n; m *= output_base) {
    output_length++;
  }

  for (int32_t i = output_length - 1; i >= 0; i--) {
    div_t x = div(n, output_base);
    digits[i] = x.rem;
    n = x.quot;
  }

  return output_length;
}
