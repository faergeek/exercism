#include "secret_handshake.h"
#include <stdlib.h>

static const char *items[] = {"wink", "double blink", "close your eyes",
                              "jump"};

const char **commands(size_t number) {
  const char **result = calloc(4, sizeof(char *));
  const char should_reverse = (number & (1 << 4));

  int result_index = 0;
  for (int i = 0; i < 4; i++) {
    int index = should_reverse ? 3 - i : i;

    if ((number & (1 << index)) != 0)
      result[result_index++] = items[index];
  }

  return result;
}
