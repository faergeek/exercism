#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
  std::vector<int> result{};

  size_t size = student_scores.size();
  for (size_t i = 0; i < size; i++) {
    result.push_back(static_cast<int>(student_scores.at(i)));
  }

  return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
  int count = 0;

  auto size = student_scores.size();
  for (int i = 0; i < size; i++) {
    if (student_scores.at(i) <= 40) {
      count++;
    }
  }

  return count;
}

// Determine how many of the provided student scores were 'the best' based on
// the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores,
                                 int threshold) {
  std::vector<int> result{};

  size_t size = student_scores.size();
  for (size_t i = 0; i < size; i++) {
    auto score = student_scores.at(i);

    if (score >= threshold) {
      result.push_back(score);
    }
  }

  return result;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
  std::array<int, 4> result{};

  auto score_step = (highest_score - 40) / 4;
  auto score = 41;
  for (auto i = 0; i < 4; i++) {
    result.at(i) = score;
    score += score_step;
  }

  return result;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string>
student_ranking(std::vector<int> student_scores,
                std::vector<std::string> student_names) {
  std::vector<std::string> result{};

  size_t size = student_scores.size();
  for (size_t i = 0; i < size; i++) {
    auto name = student_names.at(i);
    auto score = student_scores.at(i);

    result.push_back(std::to_string(i + 1) + ". " + name + ": " +
                     std::to_string(score));
  }

  return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
  std::string result = "";

  size_t size = student_scores.size();
  for (size_t i = 0; i < size; i++) {
    auto name = student_names.at(i);
    auto score = student_scores.at(i);

    if (score == 100) {
      return name;
    }
  }

  return result;
}
