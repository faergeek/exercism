#include "rna_transcription.h"
#include <algorithm>

namespace rna_transcription {

char to_rna(const char input) {
  switch (input) {
  case 'G':
    return 'C';
  case 'C':
    return 'G';
  case 'T':
    return 'A';
  case 'A':
    return 'U';
  }

  return '\0';
}

std::string to_rna(const std::string &input) {
  std::string result(input);
  std::transform(result.cbegin(), result.cend(), result.begin(),
                 [](const char c) { return to_rna(c); });

  return result;
}

} // namespace rna_transcription
