#include "alphametics.h"
#include <cstddef>
#include <cstdint>
#include <set>
#include <stdexcept>
#include <vector>

namespace alphametics {

void skip_whitespace(std::string::const_iterator &it) {
  while (std::isspace(*it)) {
    it++;
  }
}

std::string parse_literal(std::string::const_iterator &it) {
  std::string literal;

  while (std::isalpha(*it)) {
    auto c = *it;
    literal.push_back(c);
    it++;
  }

  return literal;
}

int get_literal_value(solution &solution, std::string &literal) {
  int result = 0;

  for (const auto c : literal) {
    result *= 10;
    auto digit = solution.find(c);

    if (digit == solution.end()) {
      throw std::out_of_range(std::string("No value set for ") + c);
    }

    result += digit->second;
  }

  return result;
}

std::optional<solution> solve(const std::string &input) {
  std::vector<std::string> terms;
  std::string result;

  for (auto it = input.cbegin(); it < input.cend();) {
    skip_whitespace(it);

    auto c = *it;
    if (std::isalpha(c)) {
      terms.push_back(parse_literal(it));
    } else if (c == '+') {
      it++;
    } else if (c == '=') {
      it++;
      c = *it;

      if (c != '=') {
        throw std::invalid_argument("Expected a second '=' after '='");
      }

      it++;
      skip_whitespace(it);
      result = parse_literal(it);
    } else {
      throw std::invalid_argument(std::string("Unexpected character: ") + c);
    }
  }

  std::set<char> letters_set;
  std::set<char> leading_letters;
  for (auto term : terms) {
    leading_letters.insert(term[0]);

    for (auto c : term) {
      letters_set.insert(c);
    }
  }

  leading_letters.insert(result[0]);
  for (auto c : result) {
    letters_set.insert(c);
  }

  solution solution;
  for (const auto c : letters_set) {
    solution.emplace(c, 0);
  }

  size_t n = 10;
  size_t k = letters_set.size();

  size_t n_permutations = n;
  for (size_t i = n - k + 1; i < n; i++) {
    n_permutations *= i;
  }

  std::vector<uint8_t> values(letters_set.size());
  for (size_t i = 0; i < n_permutations; i++) {
    std::vector<uint8_t> digits{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    bool invalid = false;
    size_t remainder = i;
    for (const auto c : letters_set) {
      size_t index = remainder % digits.size();
      uint8_t digit = digits[index];

      if (digit == 0 && leading_letters.find(c) != leading_letters.end()) {
        invalid = true;
        break;
      }

      remainder /= digits.size();
      digits.erase(digits.begin() + index);
      solution.at(c) = digit;
    }

    if (invalid) {
      continue;
    }

    int sum = 0;

    for (auto term : terms) {
      sum += get_literal_value(solution, term);
    }

    if (sum == get_literal_value(solution, result)) {
      return std::optional(solution);
    }
  }

  return std::nullopt;
}

} // namespace alphametics
