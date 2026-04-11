#include "resistor_color.h"
#include <stddef.h>
#include <stdio.h>

uint16_t color_code(resistor_band_t band) { return band; }

const resistor_band_t all_colors[] = {
    BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE,
};

const resistor_band_t *colors() { return all_colors; }
