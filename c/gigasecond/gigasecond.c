#include "gigasecond.h"
#include <time.h>

void gigasecond(time_t input, char *output, size_t size) {
  time_t result = input + 1e9;

  strftime(output, size, "%F %T", gmtime(&result));
}
