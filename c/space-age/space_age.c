#include "space_age.h"

#define YEAR_IN_SECONDS 365.25f * 24.0f * 60.0f * 60.0f

static const float multipliers[] = {
    YEAR_IN_SECONDS * 0.2408467f, YEAR_IN_SECONDS * 0.61519726f,
    YEAR_IN_SECONDS * 1.0,        YEAR_IN_SECONDS * 1.8808158,
    YEAR_IN_SECONDS * 11.862615,  YEAR_IN_SECONDS * 29.447498,
    YEAR_IN_SECONDS * 84.016846,  YEAR_IN_SECONDS * 164.79132,
};

float age(planet_t planet, int64_t seconds) {
  return 0 <= planet && planet <= NEPTUNE ? seconds / multipliers[planet]
                                          : -1.0f;
}
