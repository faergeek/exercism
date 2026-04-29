#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

int steps(int n) {
  if (n < 1) {
    throw std::domain_error("Input number must be positive");
  }

  int result = 0;

  for (result = 0; n != 1; result++) {
    n = n % 2 == 0 ? n / 2 : n * 3 + 1;
  }

  return result;
}

} // namespace collatz_conjecture
