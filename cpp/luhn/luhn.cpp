#include "luhn.h"

namespace luhn {
bool valid(std::string input) {
  int sum = 0;
  int n_digits = 0;
  for (int i = input.length() - 1; i > -1; i--) {
    const auto c = input[i];

    if (c == ' ') {
      continue;
    }

    if (c < '0' || c > '9') {
      return false;
    }

    int n = c - '0';

    if (n_digits % 2 == 1) {
      n += n;

      if (n > 9) {
        n -= 9;
      }
    }

    sum += n;
    n_digits++;
  }

  return n_digits > 1 && sum % 10 == 0;
}
} // namespace luhn
