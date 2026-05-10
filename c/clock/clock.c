#include "clock.h"
#include <stdio.h>
#include <string.h>

clock_t clock_create(int hour, int minute) {
  clock_t result = {0};

  if (minute < 0) {
    hour += minute / 60 - 1;
    minute = minute % 60 + 60;
  }

  hour += minute / 60;
  if (hour < 0) {
    hour = hour % 24 + 24;
  }

  hour %= 24;
  minute %= 60;

  snprintf(result.text, MAX_STR_LEN, "%02hhi:%02hhi", (unsigned char)hour,
           (unsigned char)minute);

  return result;
}

static void clock_read(clock_t clock, unsigned char *hour,
                       unsigned char *minute) {
  sscanf(clock.text, "%02hhu:%02hhu", hour, minute);
}

clock_t clock_add(clock_t clock, int minute_add) {
  unsigned char hour;
  unsigned char minute;
  clock_read(clock, &hour, &minute);

  return clock_create(hour, minute + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
  unsigned char hour;
  unsigned char minute;
  clock_read(clock, &hour, &minute);

  return clock_create(hour, minute - minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b) {
  return strcmp(a.text, b.text) == 0;
}
