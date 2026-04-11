#include "armstrong_numbers.h"
#include <cmath>
#include <cstdint>
#include <vector>

namespace armstrong_numbers {
bool is_armstrong_number(int n) {
  auto digits = std::vector<uint8_t>();

  for (int n2 = n; n2 > 0; n2 /= 10) {
    digits.push_back(n2 % 10);
  }

  int sum = 0;
  for (const auto &digit : digits) {
    sum += std::pow(digit, digits.size());
  }

  return sum == n;
}
} // namespace armstrong_numbers
