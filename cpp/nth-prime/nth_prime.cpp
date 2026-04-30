#include "nth_prime.h"
#include <cmath>
#include <exception>
#include <stdexcept>

namespace nth_prime {

int nth(int n) {
  if (n < 1) {
    throw std::domain_error("n must be greater than zero");
  }

  for (int i = 0, candidate = 2; i < n; candidate++) {
    int max_factor = sqrt(candidate);
    bool found = true;
    for (int i = 2; i <= max_factor; i++) {
      if (candidate % i == 0) {
        found = false;
        break;
      }
    }

    if (found) {
      i++;

      if (i == n) {
        return candidate;
      }
    }
  }

  throw std::exception();
}

} // namespace nth_prime
