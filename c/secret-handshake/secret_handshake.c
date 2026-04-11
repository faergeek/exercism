#include "secret_handshake.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const char *items[] = {"wink", "double blink", "close your eyes", "jump"};

const char **commands(size_t number) {
  const char **result = calloc(4, sizeof(char *));

  bool should_reverse = (number & (1 << 4)) != 0;

  int result_index = 0;
  for (int i = 0; i < 4; i++) {
    int index = should_reverse ? 3 - i : i;

    if ((number & (1 << index)) != 0) {
      const char *item = items[index];
      size_t size = sizeof(char) * strlen(item) + 1;

      result[result_index++] = memcpy(malloc(size), item, size);
    }
  }

  return result;
}
