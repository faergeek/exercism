#include "pythagorean_triplet.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

const uint16_t CAPACITY_CHUNK = 5;

static void ensure_capacity(triplets_t *triplets[static 1],
                            uint16_t desired_capacity) {
  uint16_t capacity;
  uint16_t count;

  if (*triplets) {
    capacity = (*triplets)->capacity;
    count = (*triplets)->count;
  } else {
    capacity = 0;
    count = 0;
  }

  if (!(*triplets) || capacity < desired_capacity) {
    capacity = desired_capacity % CAPACITY_CHUNK == 0
                   ? desired_capacity
                   : ((desired_capacity / CAPACITY_CHUNK) + 1) * CAPACITY_CHUNK;

    triplets_t *new_triplets =
        malloc(sizeof(triplets_t) + capacity * sizeof(triplet_t));

    *new_triplets = (triplets_t){
        .capacity = capacity,
        .count = count,
    };

    if (*triplets) {
      memcpy(new_triplets->triplets, (*triplets)->triplets,
             count * sizeof(triplet_t));
    }

    free(*triplets);

    *triplets = new_triplets;
  }
}

triplets_t *triplets_with_sum(uint16_t sum) {
  triplets_t *triplets = NULL;
  ensure_capacity(&triplets, 0);

  for (uint16_t a = 1; a + (a + 1) + (a + 2) <= sum; a++) {
    uint32_t a_squared = a * a;

    for (uint16_t b = a + 1; a + b + (b + 1) <= sum; b++) {
      double c = sqrt(a_squared + b * b);

      if (c == (uint16_t)c && a + b + (uint16_t)c == sum) {
        ensure_capacity(&triplets, triplets->count + 1);
        triplets->triplets[triplets->count] = (triplet_t){
            .a = a,
            .b = b,
            .c = c,
        };
        triplets->count++;
      }
    }
  }

  return triplets;
}

void free_triplets(triplets_t *triplets) { free(triplets); }
