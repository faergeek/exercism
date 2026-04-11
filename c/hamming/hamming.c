#include "hamming.h"
#include <stdio.h>

int compute(const char *lhs, const char *rhs) {
  printf("lhs: %s, rhs: %s\n", lhs, rhs);

  if (!lhs || !rhs) {
    return -1;
  }

  int distance = 0;
  for (; *lhs || *rhs; lhs++, rhs++) {
    if (!*lhs || !*rhs) {
      return -1;
    }

    if (*lhs != *rhs) {
      distance++;
    }
  }

  return distance;
}
