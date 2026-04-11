#include "phone_number.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define EXPECTED_N_DIGITS 10

char *phone_number_clean(const char *input) {
  const size_t len = strlen(input);

  char *result = malloc(EXPECTED_N_DIGITS);
  memset(result, '0', EXPECTED_N_DIGITS);

  bool valid = true;
  size_t n_digits = 0;
  for (size_t i = 0; i < len; i++) {
    char c = input[i];

    if (c < '0' || c > '9' || (n_digits == 0 && c == '1')) {
      continue;
    }

    const bool is_N = (n_digits == 0 || n_digits == 3);

    if ((is_N && c < '2') || n_digits >= EXPECTED_N_DIGITS) {
      valid = false;
      break;
    }

    result[n_digits++] = c;
  }

  valid = valid && n_digits == EXPECTED_N_DIGITS;

  if (!valid) {
    memset(result, '0', EXPECTED_N_DIGITS);
  }

  return result;
}
