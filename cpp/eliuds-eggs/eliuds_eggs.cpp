#include "eliuds_eggs.h"

namespace chicken_coop {
int positions_to_quantity(int n) {
  int count = 0;
  while (n > 0) {
    count += n & 1;
    n >>= 1;
  }

  return count;
}
} // namespace chicken_coop
