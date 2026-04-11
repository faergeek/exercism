#include "darts.h"
#include <math.h>

int score(coordinate_t landing_position) {
  float distance = hypotf(landing_position.x, landing_position.y);

  return distance <= 1.0f    ? 10
         : distance <= 5.0f  ? 5
         : distance <= 10.0f ? 1
                             : 0;
}
