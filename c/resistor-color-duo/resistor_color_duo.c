#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t bands[2]) {
  return bands[0] * 10 + bands[1];
}
