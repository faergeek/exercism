#include "atbash_cipher.h"
#include <string>

namespace atbash_cipher {
std::string encode(const std::string &plain_text) {
  auto result = std::string();
  size_t n_groups = 0;

  const size_t len = plain_text.length();
  for (size_t i = 0; i < len; i++) {
    char c = plain_text[i];
    if ('a' <= c && c <= 'z') {
      c = 'z' - c + 'a';
    } else if ('A' <= c && c <= 'Z') {
      c = 'Z' - c + 'a';
    } else if ('0' <= c && c <= '9') {
      c = c;
    } else {
      c = '\0';
    }

    if (c != '\0') {
      if (result.length() != 0 && (result.length() - n_groups) % 5 == 0) {
        result.push_back(' ');
        n_groups++;
      }

      result.push_back(c);
    }
  }

  return result;
}

std::string decode(const std::string &cypher_text) {
  auto result = std::string();
  const size_t len = cypher_text.length();
  for (size_t i = 0; i < len; i++) {
    char c = cypher_text[i];

    if ('a' <= c && c <= 'z') {
      c = 'z' - c + 'a';
    } else if (c == ' ') {
      c = '\0';
    }

    if (c != '\0') {
      result.push_back(c);
    }
  }

  return result;
}
} // namespace atbash_cipher
