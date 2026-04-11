#include "reverse_string.h"
#include <string>

namespace reverse_string {
std::string reverse_string(std::string input) {
  const size_t len = input.length();

  auto result = std::string();
  result.resize(len);
  for (size_t i = 0; i < len; i++) {
    result[i] = input[len - 1 - i];
  }

  return result;
}
} // namespace reverse_string
