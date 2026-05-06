#include "luhn.h"
#include <stddef.h>
#include <string.h>

bool luhn(const char *num) {
  const char *it = num + (strlen(num) - 1);
  size_t sum = 0;
  size_t digit_index;
  for (digit_index = 0; it >= num; it--) {
    const char ch = *it;

    if ('0' <= ch && ch <= '9') {
      size_t digit = ch - '0';
      if (digit_index % 2 == 1) {
        digit *= 2;
        digit = digit > 9 ? digit - 9 : digit;
      }

      sum += digit;
      digit_index++;
    } else if (ch == ' ') {
      // skip
    } else {
      return false;
    }
  }

  return digit_index > 1 && sum % 10 == 0;
}
