#include "two_fer.h"
#include <stdio.h>
#include <string.h>

void two_fer(char *buffer, const char *name) {
  snprintf(buffer, 50, "One for %s, one for me.", name == NULL ? "you" : name);
}
