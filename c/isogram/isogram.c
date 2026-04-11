#include "isogram.h"
#include <stdint.h>
#include <string.h>

bool is_isogram(const char phrase[]) {
  if (phrase == NULL) {
    return false;
  }

  uint32_t char_flags = 0;

  for (const char *cp = phrase; *cp != '\0'; cp++) {
    const char c = *cp;
    char n;

    if (c >= 'A' && c <= 'Z') {
      n = c - 'A';
    } else if (c >= 'a' && c <= 'z') {
      n = c - 'a';
    } else {
      continue;
    }

    uint32_t bit = (1 << n);

    if (char_flags & bit) {
      return false;
    }

    char_flags |= bit;
  }

  return true;
}
