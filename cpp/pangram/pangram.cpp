#include "pangram.h"
#include <bitset>

namespace pangram {

bool is_pangram(const std::string &input) {
  std::bitset<'z' - 'a' + 1> letters;

  for (const auto c : input) {
    if (isalpha(c)) {
      letters.set(tolower(c) - 'a');
    }
  }

  return letters.all();
}

} // namespace pangram
