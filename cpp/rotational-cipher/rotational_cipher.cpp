#include "rotational_cipher.h"
#include <cctype>

namespace rotational_cipher {
std::string rotate(const std::string &plain_text, uint8_t key) {
  auto result = std::string();
  constexpr auto base = ('z' - 'a' + 1);
  for (const char &c : plain_text) {
    if (std::islower(c)) {
      result += ((c - 'a') + key) % base + 'a';
    } else if (std::isupper(c)) {
      result += ((c - 'A') + key) % base + 'A';
    } else {
      result += c;
    }
  }

  return result;
}
} // namespace rotational_cipher
