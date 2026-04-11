#include "darts.h"
#include <cmath>

namespace darts {
int score(float x, float y) {
  auto distance = std::hypot(x, y);

  return distance <= 1 ? 10 : distance <= 5 ? 5 : distance <= 10 ? 1 : 0;
}
} // namespace darts
