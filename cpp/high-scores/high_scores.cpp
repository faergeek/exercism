#include "high_scores.h"

#include <algorithm>

namespace arcade {
std::vector<int> HighScores::list_scores() { return scores; }

int HighScores::latest_score() { return scores.back(); }

int HighScores::personal_best() {
  return *std::max_element(scores.begin(), scores.end()).base();
}

std::vector<int> HighScores::top_three() {
  auto result = std::vector<int>(scores);
  std::sort(result.begin(), result.end());
  std::reverse(result.begin(), result.end());

  while (result.size() > 3)
    result.pop_back();

  return result;
}
} // namespace arcade
