#include "hamming.h"
#include <stdexcept>

namespace hamming {

int compute(const std::string &a, const std::string &b) {
  if (a.size() != b.size()) {
    throw std::domain_error("Strings must be of equal lengths");
  }

  size_t distance = 0;
  for (size_t i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) {
      distance++;
    }
  }

  return distance;
}

} // namespace hamming
