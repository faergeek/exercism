#include "hexadecimal.h"
#include <cctype>
#include <cmath>

namespace hexadecimal {
uint32_t convert(std::string input) {
  int result = 0;

  int last_i = input.length() - 1;
  for (int i = last_i; i > -1; i--) {
    const auto c = std::tolower(input[i]);

    uint8_t n;
    if ('0' <= c && c <= '9') {
      n = c - '0';
    } else if ('a' <= c && c <= 'f') {
      n = c - 'a' + 10;
    } else {
      return 0;
    }

    result += n * std::pow(16, last_i - i);
  }

  return result;
}
} // namespace hexadecimal
