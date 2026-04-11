#pragma once

#include <cstdint>
#include <string>

namespace rotational_cipher {
std::string rotate(const std::string &plain_text, uint8_t key);
} // namespace rotational_cipher
