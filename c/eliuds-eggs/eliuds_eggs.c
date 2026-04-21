#include "eliuds_eggs.h"

int egg_count(int input) {
  int result = 0;

  while (input > 0) {
    result += input & 1;
    input >>= 1;
  }

  return result;
}
