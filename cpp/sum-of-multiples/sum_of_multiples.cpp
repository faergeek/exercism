#include "sum_of_multiples.h"

namespace sum_of_multiples {

int to(std::vector<int> input, int limit) {
  int sum = 0;
  for (int i = 1; i < limit; i++) {
    for (const auto base_value : input) {
      if (i % base_value == 0) {
        sum += i;
        break;
      }
    }
  }

  return sum;
}

} // namespace sum_of_multiples
