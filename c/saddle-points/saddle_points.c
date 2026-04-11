#include "saddle_points.h"
#include <stdlib.h>

saddle_points_t *saddle_points(size_t rows, size_t columns,
                               uint8_t matrix[rows][columns]) {
  saddle_points_t *result =
      malloc(sizeof(saddle_points_t) + sizeof(saddle_point_t) * rows * columns);
  result->count = 0;

  uint8_t *max_per_row = malloc(sizeof(uint8_t) * rows);
  for (size_t row = 0; row < rows; row++) {
    uint8_t max = 0;

    for (size_t column = 0; column < columns; column++) {
      if (matrix[row][column] > max) {
        max = matrix[row][column];
      }
    }

    max_per_row[row] = max;
  }

  uint8_t *min_per_column = malloc(sizeof(uint8_t) * columns);
  for (size_t column = 0; column < columns; column++) {
    uint8_t min = ~0;

    for (size_t row = 0; row < rows; row++) {
      if (matrix[row][column] < min) {
        min = matrix[row][column];
      }
    }

    min_per_column[column] = min;
  }

  for (size_t row = 0; row < rows; row++) {
    for (size_t column = 0; column < columns; column++) {
      uint8_t value = matrix[row][column];

      if (value == max_per_row[row] && value == min_per_column[column]) {
        result->points[result->count] = (saddle_point_t){
            .row = row + 1,
            .column = column + 1,
        };
        result->count++;
      }
    }
  }

  free(max_per_row);
  free(min_per_column);

  return result;
}

void free_saddle_points(saddle_points_t *p) { free(p); }
