#include "sieve.h"
#include <algorithm>

namespace sieve {
std::vector<int> primes(int max) {
  auto result = std::vector<int>();

  for (int i = 2; i <= max; i++) {
    result.emplace_back(i);
  }

  for (size_t i = 0; i < result.size(); i++)
    if (result[i] > 1)
      for (int n = result[i] + result[i]; n <= max; n += result[i])
        result[n - 2] = -1;

  result.erase(std::remove_if(result.begin(), result.end(),
                              [](int i) { return i == -1; }),
               result.end());

  return result;
}
} // namespace sieve
