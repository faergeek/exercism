#include <string>
#include <vector>

namespace election {

struct ElectionResult {
  std::string name{};
  int votes{};
};

int vote_count(ElectionResult &result) { return result.votes; }

void increment_vote_count(ElectionResult &result, int incrementBy) {
  result.votes += incrementBy;
}

// TODO: Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.
struct ElectionResult &
determine_result(std::vector<ElectionResult> &final_count) {
  size_t size = final_count.size();
  int winner_votes = 0;
  size_t winner_index = 0;

  for (size_t i = 0; i < size; i++) {
    ElectionResult &candidate{final_count[i]};

    if (candidate.votes > winner_votes) {
      winner_votes = candidate.votes;
      winner_index = i;
    }
  }

  ElectionResult &winner{final_count[winner_index]};

  winner.name = "President " + winner.name;

  return winner;
}

} // namespace election
