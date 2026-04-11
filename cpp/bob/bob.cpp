#include "bob.h"

namespace bob {
std::string hey(std::string input) {
  bool is_silence = true;

  for (const auto &c : input) {
    if (!std::isspace(c)) {
      is_silence = false;
      break;
    }
  }

  if (is_silence) {
    return "Fine. Be that way!";
  }

  bool has_letters = false;
  for (const auto &c : input) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
      has_letters = true;
    }
  }

  bool is_yelling = false;
  if (has_letters) {
    is_yelling = true;
    for (const auto &c : input) {
      if ('a' <= c && c <= 'z') {
        is_yelling = false;
      }
    }
  }

  bool is_question = false;
  for (int i = input.length() - 1; i > -1; i--) {
    const auto c = input[i];

    if (c == '?') {
      is_question = true;
      break;
    }

    if (!std::isspace(c)) {
      break;
    }
  }

  if (is_question) {
    return is_yelling ? "Calm down, I know what I'm doing!" : "Sure.";
  }

  return is_yelling ? "Whoa, chill out!" : "Whatever.";
}
} // namespace bob
