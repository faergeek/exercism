#include "sum_of_multiples.h"
#include <stdbool.h>
#include <stdlib.h>

#define DEFAULT_CAPACITY 8

typedef struct {
  size_t cap;
  size_t len;
  unsigned int items[];
} uint_array;

static uint_array *array_new(void) {
  uint_array *result =
      malloc(sizeof(uint_array) + DEFAULT_CAPACITY * sizeof(unsigned int));
  result->cap = DEFAULT_CAPACITY;
  result->len = 0;
  return result;
}

static uint_array *array_push(uint_array *array, unsigned int item) {
  if (array->len == array->cap) {
    size_t new_cap = array->cap * 2;
    array = realloc(array, sizeof(*array) + new_cap * sizeof(unsigned int));
    array->cap = new_cap;
  }

  array->items[array->len++] = item;
  return array;
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit) {
  uint_array *multiples = array_new();

  for (size_t i = 0; i < number_of_factors; i++) {
    unsigned int factor = factors[i];

    if (factor == 0) {
      continue;
    }

    unsigned int multiple = factor;
    for (size_t j = 1; multiple < limit; j++, multiple = j * factor) {
      bool exists = false;

      for (size_t k = 0; k < multiples->len; k++) {
        if (multiples->items[k] == multiple) {
          exists = true;
          break;
        }
      }

      if (!exists) {
        multiples = array_push(multiples, multiple);
      }
    }
  }

  unsigned int sum = 0;
  for (size_t i = 0; i < multiples->len; i++) {
    sum += multiples->items[i];
  }

  free(multiples);
  return sum;
}
