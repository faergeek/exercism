#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna) {
  const size_t len = strlen(dna);
  char *rna = calloc(len + 1, sizeof(rna[0]));

  for (size_t i = 0; i < len; i++) {
    switch (dna[i]) {
    case 'G':
      rna[i] = 'C';
      break;
    case 'C':
      rna[i] = 'G';
      break;
    case 'T':
      rna[i] = 'A';
      break;
    case 'A':
      rna[i] = 'U';
      break;
    }
  }

  return rna;
}
