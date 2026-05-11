#include "rotational_cipher.h"
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key) {
  size_t len = strlen(text);
  char *result = calloc(len + 1, sizeof(*result));
  for (size_t i = 0; i < len; i++) {
    char start = 'a' <= text[i] && text[i] <= 'z' ? 'a'
                 : 'A' <= text[i] && text[i]      ? 'A'
                                                  : '\0';

    result[i] =
        start == '\0' ? text[i] : start + (text[i] - start + shift_key) % 26;
  }

  return result;
}
