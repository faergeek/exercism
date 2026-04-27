#include "high_scores.h"
#include <stdbool.h>

int32_t latest(const int32_t *scores, size_t scores_len) {
  return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
  int32_t result = 0;

  for (size_t i = 0; i < scores_len; i++) {
    if (scores[i] > result) {
      result = scores[i];
    }
  }

  return result;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
  size_t len = scores_len < 3 ? scores_len : 3;
  size_t max_indices[3] = {scores_len, scores_len, scores_len};
  for (size_t i = 0; i < len; i++) {
    for (size_t j = 0; j < scores_len; j++) {
      bool already_used = false;
      for (size_t k = 0; k < i + 1; k++) {
        if (max_indices[k] == j) {
          already_used = true;
          break;
        }
      }

      if (already_used) {
        continue;
      }

      if (max_indices[i] > scores_len - 1 ||
          scores[j] > scores[max_indices[i]]) {
        max_indices[i] = j;
      }
    }
  }

  for (size_t i = 0; i < len; i++) {
    output[i] = scores[max_indices[i]];
  }

  return len;
}
