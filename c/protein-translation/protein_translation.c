#include "protein_translation.h"
#include <string.h>

protein_t protein(const char *const rna) {
  protein_t result = {.valid = true};
  size_t len = strlen(rna);
  for (size_t i = 0; i < len; i += 3) {
    const char *const it = rna + i;
    if (strncmp(it, "AUG", 3) == 0) {
      result.amino_acids[result.count++] = Methionine;
    } else if (strncmp(it, "UUU", 3) == 0 || strncmp(it, "UUC", 3) == 0) {
      result.amino_acids[result.count++] = Phenylalanine;
    } else if (strncmp(it, "UUA", 3) == 0 || strncmp(it, "UUG", 3) == 0) {
      result.amino_acids[result.count++] = Leucine;
    } else if (strncmp(it, "UCU", 3) == 0 || strncmp(it, "UCC", 3) == 0 ||
               strncmp(it, "UCA", 3) == 0 || strncmp(it, "UCG", 3) == 0) {
      result.amino_acids[result.count++] = Serine;
    } else if (strncmp(it, "UAU", 3) == 0 || strncmp(it, "UAC", 3) == 0) {
      result.amino_acids[result.count++] = Tyrosine;
    } else if (strncmp(it, "UGU", 3) == 0 || strncmp(it, "UGC", 3) == 0) {
      result.amino_acids[result.count++] = Cysteine;
    } else if (strncmp(it, "UGG", 3) == 0) {
      result.amino_acids[result.count++] = Tryptophan;
    } else if (strncmp(it, "UAA", 3) == 0 || strncmp(it, "UAG", 3) == 0 ||
               strncmp(it, "UGA", 3) == 0) {
      break;
    } else {
      result.valid = false;
      break;
    }
  }

  return result;
}
