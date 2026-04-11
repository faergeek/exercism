#include "matching_brackets.h"
#include <vector>

namespace matching_brackets {
bool check(std::string input) {
  auto open = std::vector<char>();

  for (auto &c : input) {
    if (c == '[' || c == '{' || c == '(') {
      open.emplace_back(c);
    } else if (c == ']' || c == '}' || c == ')') {
      if ((open.size() == 0) || (c == ']' && open.back() != '[') ||
          (c == '}' && open.back() != '{') ||
          (c == ')' && open.back() != '(')) {
        return false;
      }

      open.pop_back();
    }
  }

  return open.size() == 0;
}
} // namespace matching_brackets
