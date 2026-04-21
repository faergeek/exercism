#include "binary.h"

int convert(const char *input) {
  int result = 0;

  for (const char *it = input; *it != '\0'; it++) {
    int digit = (*it - '0');

    if (digit != 0 && digit != 1) {
      return INVALID;
    }

    result = result << 1 | digit;
  }

  return result;
}
