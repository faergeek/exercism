#include "rational_numbers.h"

#include <math.h>
#include <stdlib.h>

rational_t make_rational(int16_t, int16_t);
int16_t calculate_gcd(int16_t, int16_t);

int16_t calculate_gcd(int16_t numerator, int16_t denominator) {
  while (denominator) {
    int16_t prev_denominator = denominator;
    denominator = numerator % denominator;
    numerator = prev_denominator;
  }

  return abs(numerator);
}

rational_t make_rational(int16_t numerator, int16_t denominator) {
  int16_t gcd = calculate_gcd(numerator, denominator);

  rational_t result = {numerator, denominator};

  if (gcd != 1) {
    result.numerator /= gcd;
    result.denominator /= gcd;
  }

  if (result.denominator < 0) {
    result.numerator = -result.numerator;
    result.denominator = -result.denominator;
  }

  return result;
}

rational_t add(rational_t a, rational_t b) {
  return make_rational(a.numerator * b.denominator +
                           b.numerator * a.denominator,
                       a.denominator * b.denominator);
}

rational_t subtract(rational_t a, rational_t b) {
  return add(a, (rational_t){-b.numerator, b.denominator});
}

rational_t multiply(rational_t a, rational_t b) {
  return make_rational(a.numerator * b.numerator,
                       a.denominator * b.denominator);
}

rational_t divide(rational_t a, rational_t b) {
  return multiply(a, (rational_t){b.denominator, b.numerator});
}

rational_t absolute(rational_t a) {
  rational_t result = make_rational(a.numerator, a.denominator);

  if (result.numerator < 0) {
    result.numerator = -result.numerator;
  }

  return result;
}

rational_t exp_rational(rational_t r, int16_t p) {
  rational_t result = make_rational(1, 1);

  if (p > 0) {
    for (int16_t i = 0; i < p; i++) {
      result = multiply(result, r);
    }
  } else if (p < 0) {
    for (int16_t i = 0; i > p; i--) {
      result = divide(result, r);
    }
  }

  return result;
}

float exp_real(uint16_t x, rational_t r) {
  return pow(pow(x, r.numerator), 1.0 / r.denominator);
}

rational_t reduce(rational_t a) {
  return make_rational(a.numerator, a.denominator);
}
