#include "nucleotide_count.h"
#include <stdio.h>
#include <stdlib.h>

char *count(const char *dna_strand) {
  int a_count = 0;
  int c_count = 0;
  int g_count = 0;
  int t_count = 0;

  for (const char *it = dna_strand; *it != '\0'; it++) {
    switch (*it) {
    case 'A':
      a_count++;
      break;
    case 'C':
      c_count++;
      break;
    case 'G':
      g_count++;
      break;
    case 'T':
      t_count++;
      break;
    default: {
      char *result = calloc(1, sizeof(*result));
      return result;
    }
    }
  }

  char *result = NULL;
  int max_len = 0;
  for (;;) {
    int printed_len = snprintf(result, max_len, "A:%d C:%d G:%d T:%d", a_count,
                               c_count, g_count, t_count);

    if (printed_len < max_len) {
      break;
    }

    max_len = printed_len + 1;
    result = malloc(max_len);
  }

  return result;
}
