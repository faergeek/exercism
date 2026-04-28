#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t input[]) {
  int value = input[0] * 10 + input[1];
  int exponent = input[2];

  resistor_unit_t unit = OHMS;
  while (exponent > 3 && unit < RESISTOR_LENGTH) {
    exponent -= 3;
    unit++;
  }

  while (exponent > 0) {
    value *= 10;
    exponent--;
  }

  while (value / 1000 != 0 && value % 1000 == 0 && unit < RESISTOR_LENGTH) {
    unit++;
    value /= 1000;
  }

  return (resistor_value_t){
      .value = value,
      .unit = unit,
  };
}
