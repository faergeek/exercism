#include "pangram.h"

bool is_pangram(const char *sentence) {
  if (!sentence)
    return false;

  int sentence_flags = 0;
  for (; *sentence != '\0'; sentence++) {
    char ch = *sentence;

    if ('a' <= ch && ch <= 'z') {
      sentence_flags |= 1 << (ch - 'a');
    } else if ('A' <= ch && ch <= 'Z') {
      sentence_flags |= 1 << (ch - 'A');
    }
  }

  return sentence_flags == (1 << 26) - 1;
}
