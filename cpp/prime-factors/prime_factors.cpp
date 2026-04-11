#include "prime_factors.h"
#include <vector>

namespace prime_factors {
const std::vector<long long> of(long long n) {
  auto result = std::vector<long long>();

  int i = 2;
  while (n > 1) {
    if (n % i == 0) {
      n /= i;
      result.push_back(i);
    } else {
      i++;
    }
  }

  return result;
}
} // namespace prime_factors
