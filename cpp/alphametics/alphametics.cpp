#include "alphametics.h"
#include <cassert>
#include <cstring>
#include <stdexcept>
#include <unordered_set>

namespace alphametics {

constexpr size_t ALPHABET_SIZE = 'Z' - 'A' + 1;

struct puzzle {
  size_t max_term_len = 0;
  size_t term_count = 0;
  size_t *term_lengths;

  size_t matrix_size;
  int *matrix;

  size_t letter_count;
  int *letters;

  puzzle(const std::string_view &input) {
    // first pass through input to figure out the size of the matrix we need
    {
      size_t cur_term_len = 0;
      for (auto it = input.crbegin(); it != input.crend(); it++) {
        const char c = *it;

        if (isalpha(c)) {
          if (cur_term_len == 0) {
            term_count++;
          }

          cur_term_len++;
        } else {
          max_term_len =
              cur_term_len > max_term_len ? cur_term_len : max_term_len;
          cur_term_len = 0;
        }
      }

      max_term_len = cur_term_len > max_term_len ? cur_term_len : max_term_len;
      matrix_size = term_count * max_term_len;
      matrix = new int[matrix_size]{0};
      term_lengths = new size_t[term_count]{0};
    }

    // actually fill in the matrix
    std::unordered_set<int> letter_indices_set;
    size_t term_index = 0;
    for (auto it = input.crbegin(); it != input.crend();) {
      char c = *it;

      while (isspace(c)) {
        it++;
        c = *it;
      }

      if (isupper(c)) {
        size_t cur_term_len = 0;
        for (size_t i = 0; isupper(c); i++, it++, c = *it) {
          int letter_index = c - 'A';
          matrix[i * term_count + term_index] = letter_index;
          letter_indices_set.insert(letter_index);
          cur_term_len++;
        }

        term_lengths[term_index] = cur_term_len;
        term_index++;
      } else if (c == '=') {
        it++;
        c = *it;

        if (c != '=') {
          throw std::invalid_argument(
              std::string("Expected a second '=' after '=', got ") + c);
        }

        it++;
      } else if (c == '+') {
        it++;
      } else {
        throw std::invalid_argument(std::string("Unexpected character ") + c);
      }
    }

    letter_count = letter_indices_set.size();
    letters = new int[letter_count];

    size_t i = 0;
    for (auto letter : letter_indices_set) {
      letters[i++] = letter;
    }
  }

  ~puzzle() {
    delete[] letters;
    delete[] matrix;
  }

  bool is_valid(const int permutation[ALPHABET_SIZE]) {
    int sum = 0;
    size_t cell_index = 0;
    for (size_t column = 0; column < max_term_len; column++) {
      for (size_t term_index = 0; term_index < term_count; term_index++) {
        const size_t term_len = term_lengths[term_index];
        if (column > term_len - 1) {
          cell_index++;
          continue;
        }

        const int index = matrix[cell_index];
        const int digit = permutation[index];

        if (digit == 0 && column == term_len - 1) {
          return false;
        }

        if (term_index == 0) {
          sum -= digit;
        } else {
          sum += digit;
        }

        cell_index++;
      }

      if (sum % 10 != 0) {
        break;
      }

      sum /= 10;
    }

    return sum == 0;
  }

  // Steinhaus–Johnson–Trotter algorithm with Even's speedup
  // https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm#Even's_speedup
  bool permute(int permutation[ALPHABET_SIZE], int *directions, int *indices) {
    int max_i = -1;
    int max_n = -1;
    for (size_t i = 0; i < letter_count; i++) {
      if (directions[i] != 0 && indices[i] > max_n) {
        max_i = i;
        max_n = indices[i];
      }
    }

    if (max_i == -1) {
      return false;
    }

    size_t src_i = max_i;

    int direction = directions[src_i];
    size_t dst_i = src_i + direction;

    int temp = permutation[indices[src_i]];
    permutation[indices[src_i]] = permutation[indices[dst_i]];
    permutation[indices[dst_i]] = temp;

    temp = indices[src_i];
    indices[src_i] = indices[dst_i];
    indices[dst_i] = temp;

    temp = directions[src_i];
    directions[src_i] = directions[dst_i];
    directions[dst_i] = temp;

    if (dst_i == 0 || dst_i == letter_count - 1 ||
        indices[dst_i + direction] > indices[dst_i]) {
      directions[dst_i] = 0;
    }

    for (size_t i = 0; i < letter_count; i++) {
      if (indices[i] > max_n) {
        directions[i] = i > dst_i ? -1 : 1;
      }
    }

    return true;
  }

  bool search(int solution[ALPHABET_SIZE], const int next_digit_base,
              const size_t letter_index) {
    if (letter_index < letter_count) {
      for (size_t next_digit = next_digit_base; next_digit < 10; next_digit++) {
        solution[letters[letter_index]] = next_digit;

        if (search(solution, next_digit + 1, letter_index + 1)) {
          return true;
        }
      }

      return false;
    }

    int permutation[ALPHABET_SIZE];
    memcpy(permutation, solution, ALPHABET_SIZE * sizeof(solution[0]));

    int *indices = new int[letter_count];
    for (size_t i = 0, j = 0; i < ALPHABET_SIZE; i++) {
      if (permutation[i] >= 0) {
        indices[j++] = i;
      }
    }

    int *directions = new int[letter_count]{0};
    for (size_t i = 1; i < letter_count; i++) {
      directions[i] = -1;
    }

    bool found = false;
    while (!found) {
      found = is_valid(permutation);

      if (!found && !permute(permutation, directions, indices)) {
        break;
      }
    }

    if (found) {
      memcpy(solution, permutation, ALPHABET_SIZE * sizeof(permutation[0]));
    }

    delete[] indices;
    delete[] directions;

    return found;
  }

  std::optional<std::unordered_map<char, int>> solve() {
    int solution[ALPHABET_SIZE];
    for (size_t i = 0; i < ALPHABET_SIZE; i++) {
      solution[i] = -255;
    }

    if (!search(solution, 0, 0)) {
      return std::nullopt;
    }

    std::unordered_map<char, int> result;
    for (size_t i = 0; i < letter_count; i++) {
      const auto letter = letters[i];
      result.emplace('A' + letter, solution[letter]);
    }

    return std::optional(result);
  }
};

std::optional<std::unordered_map<char, int>> solve(const std::string &input) {
  puzzle puzzle(input);

  return puzzle.solve();
}

} // namespace alphametics
