#include "pangram.h"
#include <ctype.h>
#include <stdint.h>
#include <string.h>

bool is_pangram(const char *sentence) {
  if (sentence == NULL) {
    return false;
  }

  size_t len = strlen(sentence);
  int_fast32_t sentence_flags = 0;
  for (size_t i = 0; i < len; i++) {
    char ch = sentence[i];

    if (isalpha(ch)) {
      sentence_flags |= 1 << (tolower(ch) - 'a');
    }
  }

  return sentence_flags == (1 << 26) - 1;
}
