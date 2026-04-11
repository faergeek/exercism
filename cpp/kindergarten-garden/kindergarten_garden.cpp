#include "kindergarten_garden.h"
#include <array>

namespace kindergarten_garden {
static const std::array<std::string, 12> students = {
    "Alice", "Bob",     "Charlie", "David",  "Eve",     "Fred",
    "Ginny", "Harriet", "Ileana",  "Joseph", "Kincaid", "Larry",
};

std::array<kindergarten_garden::Plants, 4> plants(std::string diagram,
                                                  std::string student) {
  int student_index = -1;
  for (size_t i = 0; i < students.size(); i++) {
    if (students[i] == student) {
      student_index = i;
      break;
    }
  }

  int nl = diagram.find_first_of('\n');
  int start = student_index * 2;

  int chars[4] = {
      diagram[start],
      diagram[start + 1],
      diagram[start + 1 + nl],
      diagram[start + 1 + nl + 1],
  };

  std::array<kindergarten_garden::Plants, 4> result = {};

  for (int j = 0; j < 4; j++) {
    switch (chars[j]) {
    case 'C':
      result[j] = Plants::clover;
      break;
    case 'G':
      result[j] = Plants::grass;
      break;
    case 'V':
      result[j] = Plants::violets;
      break;
    case 'R':
      result[j] = Plants::radishes;
      break;
    }
  }

  return result;
}
} // namespace kindergarten_garden
