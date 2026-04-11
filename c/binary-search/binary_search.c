#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {
  if (arr != NULL) {
    size_t l = 0;
    size_t h = length;

    while (l < h) {
      size_t m = (l + h) / 2;
      int cur = arr[m];

      if (cur < value)
        l = m + 1;
      else if (cur > value)
        h = m;
      else
        return &arr[m];
    }
  }

  return NULL;
}
