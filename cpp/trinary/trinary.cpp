#include "trinary.h"
#include <cmath>
#include <cstdio>

namespace trinary {
int to_decimal(std::string input) {
  int result = 0;

  const size_t len = input.length();
  for (size_t i = 0; i < len; i++) {
    const auto c = input[i];

    if (c < '0' || c > '2') {
      return 0;
    }

    result += (c - '0') * std::pow(3, len - 1 - i);
  }

  return result;
}
} // namespace trinary
