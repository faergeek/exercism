#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake {

static const char *all_commands[4]{"wink", "double blink", "close your eyes",
                                   "jump"};

std::vector<std::string> commands(int number) {
  std::vector<std::string> result;
  for (size_t i = 0; i < 4; i++) {
    if (number & (1 << i)) {
      result.push_back(all_commands[i]);
    }
  }

  if (number & (1 << 4)) {
    std::reverse(result.begin(), result.end());
  }

  return result;
}

} // namespace secret_handshake
