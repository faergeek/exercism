#include "pangram.h"
#include <set>

namespace pangram {

bool is_pangram(const std::string &input) {
  std::set<char> letters;

  for (const auto c : input) {
    if (isalpha(c)) {
      letters.insert(tolower(c));
    }
  }

  return letters.size() == ('z' - 'a' + 1);
}

} // namespace pangram
