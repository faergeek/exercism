#include "protein_translation.h"
#include <cstdio>

namespace protein_translation {
std::vector<std::string> proteins(std::string_view input) {
  auto result = std::vector<std::string>();
  const size_t len = input.length();

  for (size_t i = 0; i < len; i += 3) {
    const auto codon = input.substr(i, 3);

    std::string acid;
    if (codon == "AUG") {
      acid = "Methionine";
    } else if (codon == "UUU" || codon == "UUC") {
      acid = "Phenylalanine";
    } else if (codon == "UUA" || codon == "UUG") {
      acid = "Leucine";
    } else if (codon == "UCU" || codon == "UCC" || codon == "UCA" ||
               codon == "UCG") {
      acid = "Serine";
    } else if (codon == "UAU" || codon == "UAC") {
      acid = "Tyrosine";
    } else if (codon == "UGU" || codon == "UGC") {
      acid = "Cysteine";
    } else if (codon == "UGG") {
      acid = "Tryptophan";
    } else if (codon == "UAA" || codon == "UAG" || codon == "UGA") {
      break;
    }

    result.push_back(acid);
  }

  return result;
}
} // namespace protein_translation
