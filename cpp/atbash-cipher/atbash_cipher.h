#pragma once

#include <string>

namespace atbash_cipher {
std::string encode(const std::string &plain_text);
std::string decode(const std::string &cypher_text);
} // namespace atbash_cipher
