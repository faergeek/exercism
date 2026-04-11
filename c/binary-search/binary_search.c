#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {
  if (length != 0) {
    size_t l = 0;
    size_t h = length - 1;

    do {
      size_t m = (l + h) / 2;

      if (arr[m] == value) {
        return &arr[m];
      }

      if (m == 0)
        break;

      if (arr[m] < value) {
        l = m + 1;
      } else {
        h = m - 1;
      }
    } while (l <= h);
  }

  return NULL;
}
